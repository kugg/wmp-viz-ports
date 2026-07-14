---
name: deep-decompilation
description: Use when performing deep decompilation of WMP visualization DLLs with COM vtable reconstruction and systematic method/structure naming. Triggers on keywords like deep decompile, COM vtable, IWMPEffects, method naming, structure recovery.
---

# Deep Decompilation of WMP Visualization DLLs

Systematic approach to reconstruct COM structures and name decompiled functions for Windows Media Player (WMP) custom visualizers (Trilogy I, II, III).

## Prerequisites

| Tool | Install | Notes |
|------|---------|-------|
| **Ghidra** | `brew install --cask ghidra` or [download](https://github.com/NationalSecurityAgency/ghidra/releases) | 12.x+ recommended |
| **Java 21+** | `brew install openjdk@21` | Required by Ghidra |
| **cabextract** | `brew install cabextract` | Extracts MS CAB archives |
| **Python 3** | System default | For automation scripts |

## Step 1: Extract the DLLs

WMP viz `.exe` files are MS CAB self-extracting archives:

```bash
# Check file type
file /path/to/vizname.exe
# Expected: PE32 executable ... MS CAB-Installer self-extracting archive

# Extract
mkdir -p extracted
cabextract -d extracted /path/to/vizname.exe
```

This yields:
- `VizName.dll` — the visualization COM DLL
- `VizName.inf` — install config (viz name, description, COM registration)
- `ADVPACK.DLL`, `W95INF*.DLL` — installer infrastructure (ignore)

## Step 2: Identify COM Interface

Read the `.inf` file for metadata:
```bash
cat extracted/VizName.inf
# Look for: description, vizname, COM class registration
```

Extract COM interface information from the DLL:
```bash
# Find COM class IDs
strings extracted/VizName.dll | grep -i "CLSID\|classid"

# Find interface names
strings extracted/VizName.dll | grep -i "ITrilogy\|IWMPEffects\|IUnknown"

# Find GUID arrays in .rdata section
strings -t x extracted/VizName.dll | grep -E "^\{[0-9A-Fa-f-]{36}\}$"
```

## Step 3: Ghidra Headless Analysis

### First Pass — Import and Auto-Analyze

```bash
GHIDRA="/Users/user/devel/milky/ghidra/ghidra_12.1.2_PUBLIC/support"

"$GHIDRA/analyzeHeadless" /Users/user/devel/milky/ghidra-project VizName \
  -import /Users/user/devel/milky/extracted/VizName.dll \
  -processor x86:LE:32:default \
  -analysisTimeoutPerFile 300
```

### Decompile All Functions

Use the `DumpDecompiled.java` script:

```bash
# Copy script to Ghidra scripts dir (required — Ghidra caches scripts)
cp /Users/user/devel/milky/visualization/DumpDecompiled.java \
   /Users/user/devel/milky/ghidra/ghidra_12.1.2_PUBLIC/Ghidra/Features/Base/ghidra_scripts/

# Run decompilation
"$GHIDRA/analyzeHeadless" /Users/user/devel/milky/ghidra-project VizName \
  -process VizName.dll \
  -noanalysis \
  -scriptPath /Users/user/devel/milky \
  -postScript DumpDecompiled.java /Users/user/devel/milky/output
```

Output: `/Users/user/devel/milky/output/decompiled_VizName.txt`

## Step 4: COM Vtable Reconstruction

### Locate the CLSIDs and IIDs

Look for 16-byte GUID arrays in the `.rdata` section. In WMP visualizers, look specifically for the interface IDs (IIDs) of `IWMPEffects` or `IWMPEffects2`.

### Import the SDK Headers

Parse the legacy headers containing the interface definitions into Ghidra's **Data Type Manager** (using **File -> Parse C Source**). If you cannot parse the full headers, manually create a C structure representing the interface vtable in Ghidra.

### Apply to the `this` Pointer

In Ghidra's decompiler:

1. Re-type the first parameter (`param_1`) of any suspected method to a pointer to your defined interface structure (e.g., `IWMPEffects*`).
2. This resolves indirect calls (like `*(code *)(*param_1 + 0x1c)`) into named calls (like `param_1->lpVtbl->Render`).

## Step 5: Standardized Naming Schema

Use a strict, hierarchical schema. This simplifies searching and allows agentic scripts to regex-match against the symbols.

### COM Interface Implementations

Name functions implementing virtual methods using the pattern:
`[ClassName]_[InterfaceName]_[MethodName]`

Examples:
- `CTrilogyVisualizer_IWMPEffects_Render`
- `CTrilogyVisualizer_IWMPEffects_MediaInfo`
- `CTrilogyVisualizer_IUnknown_QueryInterface`

### Internal Helper Functions

Group non-COM helper functions by their functional subsystem:

| Prefix | Category | Examples |
|--------|----------|----------|
| `Dx_` | Direct3D graphics | `Dx_CreateDevice`, `Dx_DrawSphere` |
| `Gdi_` | GDI graphics | `Gdi_DrawLine`, `Gdi_FillRect` |
| `Cfg_` | Configuration | `Cfg_LoadPresetSettings`, `Cfg_ReadRegistry` |
| `Math_` | Math/DSP | `Math_CalculateFFT`, `Math_SinLUT` |
| `Mem_` | Memory | `Mem_AllocateBuffer`, `Mem_AlignPointer` |

### State Structure Naming

Name the reconstructed `this` pointer structure:
`CTrilogyVisualizer` (or `CTrilogyI`, `CTrilogyII`, `CTrilogyIII` for specific versions)

Populate with offsets observed in constructor and `Initialize` methods:
- `*(float *)(this + 0x24) = 1.0;` → `this->zoom_scale = 1.0;`
- `*(int *)(this + 0x30) = 0;` → `this->active_mode = 0;`

## Step 6: Automated Renaming with Ghidra Scripts

### Extract Structures to JSON

Export the binary's vtables and decompiled entry points to JSON using Ghidra's Python API:

```python
# extract_vtables.py
from ghidra.program.model.symbol import SymbolType
from ghidra.app.decompiler import DecompInterface
import json

def extract_vtables():
    vtables = {}
    listing = currentProgram.getListing()
    symbols = currentProgram.getSymbolTable()
    
    for symbol in symbols.getAllSymbols(True):
        if symbol.getSymbolType() == SymbolType.DATA:
            name = symbol.getName()
            if 'vtable' in name.lower() or 'vtbl' in name.lower():
                vtables[name] = {
                    'address': str(symbol.getAddress()),
                    'name': name
                }
    
    return vtables

vtables = extract_vtables()
with open('/tmp/vtables.json', 'w') as f:
    json.dump(vtables, f, indent=2)
```

### Agentic Mapping

Use an LLM agent to match known `IWMPEffects` method offsets sequentially. Since `IUnknown` methods (`QueryInterface`, `AddRef`, `Release`) always occupy the first three offsets, the agent can orient itself and map subsequent custom visualizer methods sequentially.

### Write-Back Script

Generate a Python script utilizing Ghidra's `FlatProgramAPI` (using functions like `createLabel` or `setPlateComment`) to automatically apply types and rename functions in the `.gpr` database:

```python
# rename_methods.py
from ghidra.program.model.symbol import SourceType

def rename_function(address, new_name):
    func = getFunctionAt(address)
    if func:
        func.setName(new_name, SourceType.USER_DEFINED)
        print(f"Renamed {address} to {new_name}")

# Example: Map IWMPEffects vtable offsets
# IUnknown: QueryInterface(0x0), AddRef(0x4), Release(0x8)
# IWMPEffects: Render(0xc), MediaInfo(0x10), etc.
```

## Step 7: Identify the Main Render Loop

The core of the visualizer is the `IWMPEffects::Render` method.

**Signature:**
```cpp
HRESULT Render(TimedLevel *pLevels, HDC hdc, RECT *prc);
```

**Why it matters:** This function is called by Windows Media Player for every frame. Every audio-reactive callback, coordinate transformation, and rendering call originates here or is dispatched from here.

## Step 8: Trace the Audio Data

Windows Media Player performs the FFT on the audio stream and passes the pre-calculated frequency data directly to the visualizer inside the `TimedLevel` structure:

```cpp
typedef struct tagTimedLevel {
    unsigned char frequency[2][1024]; // FFT spectrum data (Left/Right channels, 1024 bands)
    unsigned char waveform[2][1024];  // Raw wave amplitude data (Oscilloscope)
    int state;                         // Playback state
    hyper timeStamp;                   // Time stamp
} TimedLevel;
```

### Identification Strategy

1. In Ghidra, locate the `Render` method.
2. Find the first argument (`param_2` or `pLevels`), and define its type as `TimedLevel *`.
3. Search for memory reads from this pointer:
   - Reads from `pLevels->frequency` (offset `0x0` to `0x7FF`) → **frequency-based rendering**
   - Reads from `pLevels->waveform` (offset `0x800` to `0xFFF`) → **waveform-based rendering**

4. Label any helper functions that accept these buffer slices as audio-reactive processors.

## Step 9: Reconstruct the Preset State Structure

Trilogy visualizers maintain their state (preset variables, parameters, current rotation angles, color lookup tables) inside the class instance memory.

### Identification Strategy

1. Create a custom structure in Ghidra's Data Type Manager named `CTrilogyVisualizer`.
2. Go to the COM object's constructor or its `IWMPEffects::Initialize` method.
3. Observe the offsets assigned default values.
4. Slowly populate the `CTrilogyVisualizer` structure in Ghidra with these offsets.
5. In `Render`, observe which offsets of `this` are mutated frame-over-frame.

## Step 10: Identify DSP, Symmetry, and Coloring Components

### Coordinate Transforms and Mirrors

- **Trigonometry:** Look for calls to `sin` and `cos` inside nested loops.
- **Polar Conversion:** Look for calls to `atan2` and `sqrt`.
- **Symmetry/Mirrors:** Look for loops that copy pixel buffers with reversed indices.

### Color Functions

- **HSV/HSL to RGB:** Look for a function that takes a cycling float (Hue, 0.0 to 360.0 or 0.0 to 1.0) and outputs three values (Red, Green, Blue).
- **Palette Interpolation:** Look for arrays containing 256 colors.

## Step 11: Map to .milk Preset Format

### WMP → MilkDrop Mapping

| WMP Concept | .milk Equivalent |
|-------------|-----------------|
| Per-pixel shader loop | Warp shader (HLSL) |
| Final color output | Composite shader (HLSL) |
| Per-frame parameters | Per-frame equations + q-variables |
| Sin/Cos LUT | `sin(qN)`, `cos(qN)` built-ins |
| Audio levels | `bass`, `mid`, `treble`, `bass_att`, `mid_att`, `treble_att` |
| Time | `time` (seconds since start) |
| Pixel buffer operations | Warp shader texture sampling |
| Color channel mixing | Composite shader math |
| Waveforms/lines | Wave objects (up to 16) |
| Geometric shapes | Shape objects (up to 16) |
| Alpha blending | Composite shader with alpha |
| Edge detection | Warp shader neighbor sampling |
| Distance fields | `q1 = sqrt(dx*dx + dy*dy)` in per-frame |

## Critical Learnings

### What Works

1. **CAB extraction**: `cabextract` reliably extracts all WMP viz DLLs from their self-extracting installers.
2. **Ghidra headless analysis**: 300s timeout is sufficient for small DLLs (<200KB). Larger DLLs may need 600s+.
3. **COM vtable identification**: The `DllGetClassObject` entry point always references the CLSID, which can be traced back to the vtable.
4. **Sin LUT identification**: Almost always at a fixed offset (e.g., `0xBC28`), 360 entries × 4 bytes. Used to identify angle parameters.
5. **Audio peak normalization**: WMP normalizes audio levels to [0,1] by dividing by 255.0. Stored per-vis at a fixed stride.
6. **Identical DLLs**: TrilogyI.dll and TrilogyIII.dll are functionally identical (same code, different embedded resources). Only TrilogyII.dll is a genuinely different build.

### What Doesn't Work (Caveats)

1. **DirectDraw rendering is hard to port**: Most WMP viz use DirectDraw + GDI, not Direct3D. The rendering code is deeply tied to Windows APIs and cannot be directly ported to HLSL/GLSL.
2. **State struct offsets are fragile**: The offsets in the `CTrilogyVisualizer` structure are specific to each version. Changing one offset can cascade through the entire decompilation.
3. **COM interface boundaries are opaque**: Without the original SDK headers, reconstructing the exact vtable layout requires significant guesswork.
4. **Audio data flow is complex**: The `TimedLevel` structure is passed by pointer, and the visualizer may store references to it in multiple places. Tracing the full data flow requires manual analysis.
5. **Color functions are often inline**: HSV/HSL conversion and palette interpolation are frequently inlined by the compiler, making them hard to identify as distinct functions.

### Common Patterns in Trilogy DLLs

1. **Shared pipeline**: Multiple visualizations share the same render infrastructure. Different vis = different parameter set fed into the same subroutines.
2. **Sin LUT**: 360-entry float table at a fixed offset — used for all trig operations.
3. **Audio peaks**: Stored per-vis at a fixed stride (e.g., `0xE0` bytes), normalized to [0,1].
4. **Background/clear color**: Stored at a fixed offset (e.g., `0x33DC`).
5. **Coordinate transform chain**: Many WMP viz use a chain of transforms (oscillation → shear → translate) dispatched via vtable.

## Trilogy DLL Analysis Results

### DLL Comparison

| DLL | File Size | MD5 | Code Identity |
|-----|-----------|-----|---------------|
| TrilogyI.dll | 167,936 bytes | `ae3b109f197c8a6a62c545ad87bd0214` | Baseline |
| TrilogyIII.dll | 167,936 bytes | `fb841a54309221bb533279e91495ae2f` | **Identical to I** |
| TrilogyII.dll | 172,032 bytes | `14d72ee449e125fcfcfef18c9775bbe8` | Different build |

**Key finding**: TrilogyI and TrilogyIII share identical code (same function addresses, same logic). The 1,843 diff lines between them are only global data address offsets (0x10 byte shift in .data section) due to different embedded resources (textures, config data).

### Address Shift Pattern (TrilogyII)

TrilogyII is a separate build where most code addresses are shifted by **+0x10** from TrilogyI:

| TrilogyI Address | TrilogyII Address | Function Name |
|------------------|-------------------|---------------|
| `0x10001000` | `0x10001000` | `Render_MainLoop` (same) |
| `0x100047d0` | `0x100047e0` | `Transform_Motion` |
| `0x10005040` | `0x10005050` | `PixelBlit_SimpleCopy` |
| `0x1000e6e0` | `0x1000e6f0` | `Audio_GetBass` |

**Exceptions**: CRT/memory functions (0x10019xxx+) have completely different addresses between builds.

### State Structure Offsets (All DLLs)

```c
// Main state structure (~53KB)
typedef struct {
    void*   vtable;              // +0x00: Primary vtable
    void*   vtable2;             // +0x04: Secondary vtable
    int     ref_count;           // +0x08: Reference count
    HWND    hWnd;                // +0x34: Window handle
    HMODULE hModule;             // +0x3C: Library module
    int     width;               // +0x78: Viewport width (640)
    int     height;              // +0x7C: Viewport height (480)
    int     frame_count;         // +0x80: Frame counter
    float   fps;                 // +0x8C: Calculated FPS
    float   sin_lut[360];        // +0xBC28: Sin lookup table
    float   spectrum_a[520];     // +0x9BA8: Spectrum buffer A
    float   spectrum_b[520];     // +0xA3C8: Spectrum buffer B
    float   spectrum_c[520];     // +0xABE8: Spectrum buffer C
    void*   audio_buffer;        // +0xC810: Audio data pointer
    void*   waveform_buffer;     // +0xC814: Waveform data pointer
    int     current_preset;      // +0x3240: Current preset index
    int     bg_color;            // +0x33DC: Background color
} CTrilogyVisualizer;
```

### Named Functions (423 of 866 mapped)

| Category | Count | Example Names |
|----------|-------|---------------|
| Render Pipeline | 5 | `Render_MainLoop`, `Present_ToScreen`, `Render_AllPresets` |
| Audio Processing | 14 | `Audio_GetBass`, `Audio_GetMid`, `Audio_GetTreble`, `Audio_Smooth` |
| Effects | 40+ | `Effect_GaussianBlur`, `Effect_ColorCycle`, `Effect_Rotate` |
| Coordinate Transforms | 10 | `Transform_Motion`, `Transform_PolarCoords`, `Transform_Scale` |
| Pixel Operations | 5 | `PixelBlit_SimpleCopy`, `PixelBlit_AlphaBlend` |
| Blending | 15 | `Blend_AlphaComposite`, `Blend_Screen`, `Blend_Overlay` |
| COM Interface | 20+ | `IUnknown_QueryInterface`, `ClassFactory_CreateInstance` |
| Window Management | 10 | `InitWindowState`, `WndProc_Viz`, `Wnd_Destroy` |
| State Management | 15 | `State_Cleanup`, `State_FullReset`, `InitStateDefaults` |
| String/Registry | 15 | `RegFileParser`, `ExpandVariables`, `BuildRegScript` |

### TrilogyII-Specific Functions

TrilogyII adds 7 utility functions for config file parsing:

| Function | Purpose |
|----------|---------|
| `Util_HexStringToColor` | Parse `#RRGGBB` hex string to color integer |
| `Util_ColorToHexString` | Convert color integer to hex string |
| `Util_IsSpace` | Check for whitespace characters |
| `Util_InitParser` | Skip whitespace in config string |
| `Util_ParseConfig` | Parse config tokens (quoted/unquoted) |
| `Util_ConfigSection` | Look up config section by name |
| `Util_RegistryParse` | Full config file parser with `%variable%` substitution |

## Project Structure

```
milky/
├── ghidra/                          # Ghidra installation
├── ghidra-project/                  # Ghidra project files
│   ├── TrilogyI.gpr
│   ├── TrilogyII.gpr
│   └── TrilogyIII.gpr
├── wmp-sdk/                         # Extracted WMPlayerSDK contents
├── winsdk-include/                  # Windows SDK headers (from PLATSDK.ISO)
├── trilogy-i-extracted/             # Extracted Trilogy I DLL
│   ├── TrilogyI.dll
│   └── output/decompiled_TrilogyI.txt
├── trilogy-ii-extracted/            # Extracted Trilogy II DLL
│   ├── TrilogyII.dll
│   └── output/decompiled_TrilogyII.txt
├── trilogy-iii-extracted/           # Extracted Trilogy III DLL
│   ├── TrilogyIII.dll
│   └── output/decompiled_TrilogyIII.txt
├── DumpDecompiled.java              # Ghidra decompilation script
├── rename_decompiled.py             # Automated function renaming script
├── function_mapping.md              # Cross-DLL function mapping
├── trilogy_state.h                  # State structure header
├── visualization/
│   ├── presets/
│   │   ├── Trilogy-I/decompiled/    # Renamed decompiled output
│   │   ├── Trilogy-II/decompiled/   # Renamed decompiled output
│   │   └── Trilogy-III/decompiled/  # Renamed decompiled output
│   ├── skills/
│   │   ├── disassemble-wmp-viz/     # Basic extraction & analysis
│   │   ├── port-wmp-viz/            # Porting to .milk presets
│   │   └── deep-decompilation/      # This skill
│   └── ...
└── .opencode/skills/
    ├── disassemble-wmp-viz/
    └── deep-decompilation/          # This skill
```

## Reverse Engineering Techniques: Variables, Types, and Parameters

### Technique 1: API Call Site Type Inference

The most powerful technique for identifying field types. Every Windows API call constrains the types of its arguments:

```c
// If code calls: HeapFree(g_hProcessHeap, 0, param_1[0x32a9])
// Then param_1[0x32a9] MUST be void* (LPVOID)

// If code calls: StretchDIBits(hdc, ..., (void*)param_1[0x31fc], (BITMAPINFO*)param_1[0x3207], ...)
// Then param_1[0x31fc] is void* (pixel data), param_1[0x3207] is BITMAPINFO*

// If code calls: CreateDIBitmap(hdc, (BITMAPINFOHEADER*)param_1[0x3208], ...)
// Then param_1[0x3208] is BITMAPINFO*

// If code calls: GetForegroundWindow() and stores result in param_1[0xc980]
// Then param_1[0xc980] is HWND
```

**Process:**
1. Find Windows API call in decompiled code
2. Look up the API signature (use `winsdk-include/` headers)
3. Map each argument to the struct field it reads from
4. The SDK parameter type constrains the field type

### Technique 2: Vtable Dispatch Pattern Recognition

Every `(**(code **)(*param_1 + 0xNN))(param_1, ...)` is a virtual method call:

```c
// Pattern: (*vtable_offset)(this_ptr, args...)
(**(code **)(*param_1 + 0x260))(param_1);    // this->vtable[0x260/4](this)
(**(code **)(*param_1 + 0x50))(param_1);     // this->vtable[0x50/4](this)
(**(code **)(*param_1 + 0x148))(param_1);    // this->vtable[0x148/4](this)
```

**Process:**
1. Collect ALL vtable offsets used across all functions
2. Sort numerically — these are sequential vtable entries
3. Identify known offsets from SDK (IUnknown: 0x00=QI, 0x04=AddRef, 0x08=Release)
4. Map unknown offsets by their calling context (render loop = render methods, cleanup = destructor)

### Technique 3: Allocation Size → Struct Size

```c
puVar1 = operator_new(0xd0ac);   // Total object size = 53,420 bytes
InitStateDefaults((int)(puVar1 + 2));  // State starts at +8 bytes (2 ints)
// Therefore: state struct = 0xD0AC - 0x08 = 0xD0A4 bytes
```

```c
_malloc(param_1[0x3308] * param_1[0x3306] * 4);
// param_1[0x3306] * 4 = stride in bytes → param_1[0x3306] is width (pixels)
// param_1[0x3308] is height
// param_1[0x3307] = param_1[0x3306] * 4 → stride = width * 4 (BGRA)
```

### Technique 4: Cross-Reference Init Patterns

Functions that initialize fields reveal default values and intended semantics:

```c
// InitStateDefaults sets these to 0:
*(undefined4 *)(param_1 + 0xc864) = 0;   // → zeroed flag/counter
*(undefined4 *)(param_1 + 0xc9b4) = 0;   // → buffers_allocated (checked before use)
*(undefined4 *)(param_1 + 0xca6c) = 0;   // → unknown flag
*(undefined4 *)(param_1 + 0xcaa0) = 0;   // → work buffer pointer

// InitStateDefaults sets this to 0xFF:
*(undefined4 *)(param_1 + 0x9c) = 0xff;  // → sentinel value (invalid index?)

// InitStateDefaults sets this to 1:
*(undefined4 *)(param_1 + 0xc9e4) = 1;   // → initialized flag
```

### Technique 5: Conditional Access Patterns

How a field is tested reveals its semantics:

```c
if (param_1[0x326d] != 0) {              // "if buffers allocated"
    HeapFree_Wrapper(param_1[0x32a9]);    // "free staging buffer"
    param_1[0x326d] = 0;                 // "mark as freed"
}
// → param_1[0x326d] is a boolean flag: buffers_allocated

if (param_1[0x3229] == 0x18 || param_1[0x3229] == 0x10) {
    // 0x18 = 24bpp, 0x10 = 16bpp
}
// → param_1[0x3229] is color_depth (bits per pixel)

if (param_1[0x3309] != 0) {
    // Single preset mode
}
// → param_1[0x3309] is single_preset_mode flag
```

### Technique 6: Arithmetic Expression → Field Semantics

```c
param_1[0x3307] = param_1[0x3306] * 4;
// stride = width * 4 bytes (BGRA pixel format)
// → 0x3306 = frame_width, 0x3307 = frame_stride

param_1[0x3234] = param_1[0x32a4] / 2;
param_1[0x3236] = param_1[0x32a5] / 2;
// center = dimension / 2
// → 0x32a4 = main_width, 0x3234 = center_x
// → 0x32a5 = main_height, 0x3236 = center_y

malloc(param_1[0x3225] * param_1[0x3224] * 4);
// allocation = width * height * 4 bytes
// → 0x3225 = buf_width, 0x3224 = buf_height
```

### Technique 7: Two-Function Access Pattern (Cast Chain)

When `InitStateDefaults` receives `param_1 + 4`, all its internal offsets are shifted:

```c
// In InitStateDefaults(param_1 + 4):
*(int*)(param_1 + 0x98) = 0;    // → state byte offset 0x98 + 4 = 0x9C
*(int*)(param_1 + 0xa0) = 0;    // → state byte offset 0xA0 + 4 = 0xA4
```

**Rule:** If `func(state + N)` uses `*(type*)(param_1 + M)`, the actual state offset is `M + N`.

### Technique 8: Preset Array Formula Decomposition

```c
param_1[param_1[0x3240] * 0x7b + 0xc3f]
// = state[current_preset * 0x7B + 0xC3F]
// Byte offset = (current_preset * 0x7B + 0xC3F) * 4
//             = current_preset * 0x1EC + 0x30FC
// Stride = 0x1EC (492 bytes per preset)
// Base = 0x30E4 (byte offset of first preset)
```

### Technique 9: Cross-DLL Comparison

TrilogyII has shifted addresses (+0x10 for most functions). Comparing identical functions at different addresses reveals:
- Which offsets are compile-time constants (same values)
- Which are relocated data pointers (shifted)
- Which are unique to a build (TrilogyII-only functions)

### Technique 10: Iteration Pattern → Array Bounds

```c
// In FreeAllBuffers:
param_1[0x3298] = 0;                              // loop index = 0
pBuffer = param_1[param_1[0x3298] + 0x31ea];       // base at 0x31EA
param_1[param_1[0x3298] + 0x31ea] = 0;             // zero the entry
iVar2 = param_1[0x3298];
param_1[0x3298] = iVar2 + 1U;                      // increment
} while (iVar2 + 1U <= (uint)param_1[0x32a3]);     // compare against max

// → 0x3298 = loop index, 0x32a3 = max count
// → preset_texture_ptrs base at state[(0x31EA * 4)] = byte 0xC3A8
```

## Automation Scripts

### rename_decompiled.py

Automated function renaming script that:
1. Reads raw Ghidra decompiled output
2. Applies naming schema from `FUNCTION_NAMES` dictionary
3. Handles both TrilogyI/III (same addresses) and TrilogyII (shifted +0x10)
4. Writes renamed C code to output files

**Usage:**
```bash
python3 rename_decompiled.py <input.txt> <output.c> <dll_name>

# Example:
python3 rename_decompiled.py \
  trilogy-i-extracted/output/decompiled_TrilogyI.txt \
  visualization/presets/Trilogy-I/decompiled/TrilogyI_decompiled.c \
  TrilogyI
```

**Current stats:**
- TrilogyI: 423/866 functions renamed (830 FUN_ refs remain)
- TrilogyII: 393/866 functions renamed (861 FUN_ refs remain)
- TrilogyIII: 423/866 functions renamed (830 FUN_ refs remain)

### Extract VTables (Ghidra Python)

```python
# Save as extract_vtables.py, run in Ghidra's Python console
from ghidra.program.model.symbol import SymbolType
import json

def extract_vtables():
    vtables = {}
    symbols = currentProgram.getSymbolTable()
    
    for symbol in symbols.getAllSymbols(True):
        if symbol.getSymbolType() == SymbolType.DATA:
            name = symbol.getName()
            if 'vtable' in name.lower() or 'vtbl' in name.lower():
                vtables[name] = str(symbol.getAddress())
    
    return vtables

vtables = extract_vtables()
print(json.dumps(vtables, indent=2))
```

### Rename Functions (Ghidra Python)

```python
# Save as rename_methods.py, run in Ghidra's Python console
from ghidra.program.model.symbol import SourceType

def rename_function(address_str, new_name):
    addr = toAddr(address_str)
    func = getFunctionAt(addr)
    if func:
        func.setName(new_name, SourceType.USER_DEFINED)
        print(f"Renamed {addr} to {new_name}")
    else:
        print(f"No function at {addr}")

# Example usage:
# rename_function("0x10001234", "CTrilogyVisualizer_IWMPEffects_Render")
```

### Batch Rename from JSON

```python
# Save as batch_rename.py
import json
from ghidra.program.model.symbol import SourceType

def batch_rename(mapping_file):
    with open(mapping_file) as f:
        mappings = json.load(f)
    
    for addr, name in mappings.items():
        rename_function(addr, name)

# Usage: batch_rename("/tmp/function_mapping.json")
```

## Automation Scripts

### Extract VTables (Ghidra Python)

```python
# Save as extract_vtables.py, run in Ghidra's Python console
from ghidra.program.model.symbol import SymbolType
import json

def extract_vtables():
    vtables = {}
    symbols = currentProgram.getSymbolTable()
    
    for symbol in symbols.getAllSymbols(True):
        if symbol.getSymbolType() == SymbolType.DATA:
            name = symbol.getName()
            if 'vtable' in name.lower() or 'vtbl' in name.lower():
                vtables[name] = str(symbol.getAddress())
    
    return vtables

vtables = extract_vtables()
print(json.dumps(vtables, indent=2))
```

### Rename Functions (Ghidra Python)

```python
# Save as rename_methods.py, run in Ghidra's Python console
from ghidra.program.model.symbol import SourceType

def rename_function(address_str, new_name):
    addr = toAddr(address_str)
    func = getFunctionAt(addr)
    if func:
        func.setName(new_name, SourceType.USER_DEFINED)
        print(f"Renamed {addr} to {new_name}")
    else:
        print(f"No function at {addr}")

# Example usage:
# rename_function("0x10001234", "CTrilogyVisualizer_IWMPEffects_Render")
```

### Batch Rename from JSON

```python
# Save as batch_rename.py
import json
from ghidra.program.model.symbol import SourceType

def batch_rename(mapping_file):
    with open(mapping_file) as f:
        mappings = json.load(f)
    
    for addr, name in mappings.items():
        rename_function(addr, name)

# Usage: batch_rename("/tmp/function_mapping.json")
```
