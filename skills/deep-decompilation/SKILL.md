---
name: deep-decompilation
description: Use when performing deep decompilation of WMP visualization DLLs with COM vtable reconstruction, systematic method/structure naming, and automated struct field substitution. Triggers on keywords like deep decompile, COM vtable, IWMPEffects, method naming, structure recovery, struct fields.
---

# Deep Decompilation of WMP Visualization DLLs

End-to-end pipeline: extract → decompile → rename functions → rename variables → substitute struct fields → identify remaining unknowns.

## Prerequisites

| Tool | Install | Notes |
|------|---------|-------|
| **Ghidra** | `brew install --cask ghidra` | 12.x+ |
| **Java 21+** | `brew install openjdk@22` | Required by Ghidra |
| **cabextract** | `brew install cabextract` | MS CAB archives |
| **Python 3** | System default | Automation scripts |

SDK headers needed:
- Windows SDK: `winsdk-include/` (for API signatures)
- WMP SDK: `wmp-sdk-extracted/effects.h` (IWMPEffects, IWMPEffects2, TimedLevel)

## Step 1: Extract DLLs

WMP viz `.exe` files are MS CAB self-extracting archives:

```bash
file /path/to/vizname.exe   # Expected: PE32 executable ... MS CAB-Installer
mkdir -p extracted
cabextract -d extracted /path/to/vizname.exe
# Yields: VizName.dll, VizName.inf, installer DLLs (ignore)
```

## Step 2: Ghidra Headless Analysis

```bash
GHIDRA="/path/to/ghidra/support"

# Import + auto-analyze
"$GHIDRA/analyzeHeadless" /path/to/ghidra-project VizName \
  -import /path/to/extracted/VizName.dll \
  -processor x86:LE:32:default \
  -analysisTimeoutPerFile 300

# Decompile all functions
cp DumpDecompiled.java "$GHIDRA/../../../Ghidra/Features/Base/ghidra_scripts/"
"$GHIDRA/analyzeHeadless" /path/to/ghidra-project VizName \
  -process VizName.dll -noanalysis \
  -scriptPath /path/to/milky \
  -postScript DumpDecompiled.java /path/to/output
```

Output: `output/decompiled_VizName.txt` (~21K lines, ~620KB per DLL)

## Step 3: Automated Renaming Pipeline

Three scripts in `tools/` process decompiled output in sequence:

### 3a. Function Renaming (`rename_decompiled.py`)

Renames `FUN_XXXXXXXX` to semantic names using a dictionary of known addresses.

```bash
python3 tools/rename_decompiled.py <input.txt> <output.c> <dll_name>
# TrilogyI/III: 495/1204 functions renamed
# TrilogyII: 453/1204 (shifted +0x10 addresses)
```

TrilogyI and TrilogyIII share identical code (same addresses). TrilogyII is a separate build with most addresses shifted +0x10. The script auto-generates shifted mappings.

### 3b. Variable Renaming (`rename_variables.py`)

Applies WMP SDK parameter names and Windows SDK type inference:

```bash
python3 tools/rename_variables.py <input.c> <output.c>
```

**Key mappings:**
- `param_1` → `pEffects` in IWMPEffects methods (Render, MediaInfo, SetUserPreset)
- Local variables named by API call context (e.g., `HeapFree_Wrapper(hHeap, ...)` → hHeap)
- Global variables: `DAT_10025010` → `g_pTrilogyState`, `DAT_10025018` → `g_hModule`

### 3c. Struct Field Substitution (`apply_struct_fields.py`)

Replaces raw `param_1[0xNNNN]` array indexing and `*(type*)(param_1 + 0xNNNN)` pointer casts with named struct field access:

```bash
python3 tools/apply_struct_fields.py <input.c> <output.c>
# Current: 1,671 field renames applied per file
```

**Two access patterns in decompiled code:**
- **Pattern A**: `param_1[0x3234]` — int array indexing, byte offset = index × 4
- **Pattern B**: `*(int*)(param_1 + 0xc8d0)` — pointer cast, direct byte offset

The script maintains `STRUCT_FIELDS` (byte offset → name) and `INDEX_FIELDS_MANUAL` (int index → name). Both are merged into `PATTERN_A_FIELDS` for Pattern A lookups.

### Full Pipeline

```bash
for DLL in TrilogyI TrilogyII TrilogyIII; do
  python3 tools/rename_decompiled.py \
    ${DLL,,}-extracted/output/decompiled_${DLL}.txt \
    /tmp/${DLL}_s1.c ${DLL}
  python3 tools/rename_variables.py /tmp/${DLL}_s1.c /tmp/${DLL}_s2.c
  python3 tools/apply_struct_fields.py /tmp/${DLL}_s2.c \
    presets/${DLL%-I*}-${DLL#*Trilogy}/decompiled/${DLL}_decompiled.c
done
```

## Step 4: State Structure Reconstruction

The `CTrilogyVisualizer` COM object is ~53KB (`operator_new(0xD0AC)`). State starts at +0x08 (8-byte COM prefix).

### Structure Definition

See `trilogy_state.h` for the full struct. Key sections:

| Region | Byte Range | Contents |
|--------|-----------|----------|
| Object header | 0x00–0xA4 | vtables, window, WMP interfaces, FPS |
| Vis value arrays | 0x9BA8–0xC7F0 | 4×520 floats (spectrum, motion, etc.) |
| Sin LUT | 0xBC28 | 360-entry float table |
| Core rendering | 0xC7F0–0xD0AC | Framebuffers, audio, pixel iteration |
| Preset data | 0x30E4+ | 54 presets × 492 bytes each |

### Field Identification Techniques

These are the systematic techniques for identifying UNKNOWN fields. Apply them iteratively until all `param_1[0xNNNN]` and `*(type*)(param_1 + 0xNNNN)` references are resolved.

#### Technique 1: API Call Site Type Inference

The most powerful technique. Every Windows API call constrains its argument types:

```c
HeapFree(g_hProcessHeap, 0, param_1[0x32a9]);
// → param_1[0x32a9] MUST be void* (LPVOID) — freed heap pointer

StretchDIBits(hdc, ..., (void*)param_1[0x31fc], (BITMAPINFO*)param_1[0x3207], ...);
// → param_1[0x31fc] = pixel data (void*), param_1[0x3207] = BITMAPINFO*

CreateDIBitmap(hdc, (BITMAPINFOHEADER*)param_1[0x3208], ...);
// → param_1[0x3208] = BITMAPINFO*

GetForegroundWindow() stored in param_1[0xc980];
// → param_1[0xc980] = HWND
```

**Process:** For each unresolved field, find ALL function calls that read or write it. Look up the API signature in `winsdk-include/`. The SDK parameter type constrains the field type.

#### Technique 2: Two-Function Access Pattern (Cast Chain)

When a function receives `state + N`, all its internal offsets are shifted:

```c
// In InitStateDefaults(state + 4):
*(int*)(param_1 + 0x98) = 0;    // actual state offset = 0x98 + 4 = 0x9C
*(int*)(param_1 + 0xa0) = 0;    // actual state offset = 0xA0 + 4 = 0xA4
```

**Rule:** If `func(state + N)` uses `*(type*)(param_1 + M)`, the actual state offset is `M + N`.

#### Technique 3: Allocation Size → Struct Size

```c
puVar1 = operator_new(0xd0ac);   // Total object = 53,420 bytes
InitStateDefaults((int)(puVar1 + 2));  // State starts at +8 bytes (2 ints)
// → state struct = 0xD0AC - 0x08 = 0xD0A4 bytes
```

#### Technique 4: Arithmetic Expression → Field Semantics

```c
param_1[0x3307] = param_1[0x3306] * 4;
// stride = width * 4 bytes (BGRA) → 0x3306 = frame_width, 0x3307 = frame_stride

param_1[0x3234] = param_1[0x32a4] / 2;
param_1[0x3236] = param_1[0x32a5] / 2;
// center = dimension / 2 → 0x32a4 = main_width, 0x3234 = center_x

malloc(param_1[0x3225] * param_1[0x3224] * 4);
// allocation = width * height * 4 → 0x3225 = buf_width, 0x3224 = buf_height
```

#### Technique 5: Conditional Access Patterns

How a field is tested reveals its semantics:

```c
if (param_1[0x326d] != 0) {
    HeapFree_Wrapper(param_1[0x32a9]);
    param_1[0x326d] = 0;
}
// → param_1[0x326d] is boolean: buffers_allocated

if (param_1[0x3229] == 0x18 || param_1[0x3229] == 0x10) {
    // 0x18 = 24bpp, 0x10 = 16bpp
}
// → param_1[0x3229] is color_depth (bits per pixel)
```

#### Technique 6: Cross-Reference Init Patterns

Functions that initialize fields reveal default values:

```c
// InitStateDefaults zeros these → flags/counters
*(undefined4 *)(param_1 + 0xc864) = 0;   // → spectrum_write_idx
*(undefined4 *)(param_1 + 0xc9b4) = 0;   // → buffers_allocated

// Sets to 0xFF → sentinel/invalid
*(undefined4 *)(param_1 + 0x9c) = 0xff;  // → unknown_0x9c sentinel

// Sets to 1 → initialized flag
*(undefined4 *)(param_1 + 0xc9e4) = 1;   // → initialized
```

#### Technique 7: Preset Array Formula Decomposition

```c
param_1[param_1[0x3240] * 0x7b + 0xc3f]
// = state[current_preset * 0x7B + 0xC3F]
// Stride = 0x1EC (492 bytes), Base = 0x30E4
```

#### Technique 8: Iteration Pattern → Array Bounds

```c
param_1[0x3298] = 0;                           // loop index
pBuffer = param_1[param_1[0x3298] + 0x31ea];   // base at 0x31EA
param_1[0x3298] = iVar2 + 1U;                  // increment
} while (iVar2 + 1U <= (uint)param_1[0x32a3]);// compare against max
// → 0x3298 = loop index, 0x32a3 = max count
// → preset_texture_ptrs base at byte 0xC3A8
```

#### Technique 9: Per-Pixel Loop Decomposition

The hottest code path is the per-pixel iteration loop. Once you identify the loop structure, the working variables reveal themselves:

```c
// The loop:
param_1[0x3286] = 0;                              // pixel_index = 0
while (param_1[0x3286] < param_1[0x3410]) {       // while pixel_index < total_pixels
    param_1[0x32f2] = param_1[0x3286] / param_1[0x33d0];  // pixel_row = index / src_width
    param_1[0x32f1] = param_1[0x3286] % param_1[0x33d0];  // pixel_col = index % src_width
    param_1[0x32f3] = param_1[0x32f1] - param_1[0x3233];  // pixel_dx = col - src_center_x
    param_1[0x32f4] = param_1[0x32f2] - param_1[0x3235];  // pixel_dy = row - src_center_y
    // ... polar transforms, effects, color manipulation ...
    param_1[0x3286]++;                                     // pixel_index++
}
```

#### Technique 10: ARGB Color Pipeline Decomposition

Per-pixel color processing follows a fixed pattern:

```c
uVar4 = *(uint*)(param_1[0x320f]);           // load packed ARGB from source
param_1[0x336b] = uVar4;                      // current_pixel = packed ARGB
param_1[0x335a] = uVar4 >> 0x18;             // alpha = bits 31-24
param_1[0x33ab] = (uVar4 >> 8) & 0xff;       // green = bits 15-8
param_1[0x3367] = uVar4 & 0xff;              // blue = bits 7-0
param_1[0x33d1] = (uVar4 >> 0x10) & 0xff;    // red = bits 23-16
// ... processing on individual channels ...
// Reassemble:
param_1[0x336b] = ((alpha << 8 | red) << 8 | green) << 8 | blue;
*(int*)(param_1[0x3202]) = param_1[0x336b];  // write to dst_pixel_ptr
param_1[0x3202] += 4;                         // advance dst_pixel_ptr
```

#### Technique 11: Vtable Dispatch Recognition

Every `(**(code **)(*param_1 + 0xNN))(param_1, ...)` is a virtual method call. Collect ALL offsets, sort numerically, and map from known IUnknown entries:

| Offset | Method |
|--------|--------|
| 0x00 | QueryInterface |
| 0x04 | AddRef |
| 0x08 | Release |
| 0x0C | Render |
| 0x10 | MediaInfo |
| 0x38 | SetCore (IWMPEffects2) |
| 0x3C | Create (IWMPEffects2) |

## Step 5: Identify Remaining Unknowns

After running the pipeline, some `param_1[0xNNNN]` accesses remain unresolved. To identify them:

### 5a. Count Remaining Accesses

```bash
# Pattern A: int array indexing
rg -c 'param_1\[0x[0-9a-fA-F]+\]' output.c

# Pattern B: pointer cast
rg -c '\*\((?:int|undefined4|void\s*\*)\s*\*\)\s*\(\s*param_1\s*\+' output.c
```

### 5b. Extract Unique Offsets

```python
import re, collections
with open('output.c') as f: content = f.read()
matches = re.findall(r'param_1\[(0x[0-9a-fA-F]+)\]', content)
counts = collections.Counter(matches)
for idx_hex, count in sorted(counts.items(), key=lambda x: -x[1]):
    print(f'{idx_hex} (byte 0x{int(idx_hex,16)*4:04X}): {count}')
```

### 5c. Analyze High-Frequency Offsets

For each unknown offset with ≥5 occurrences:
1. Find ALL occurrences in the decompiled code
2. Read the surrounding function context (10+ lines before/after)
3. Apply Techniques 1–11 above
4. Cross-reference with other functions that use the same offset
5. Suggest a name and rationale
6. Add to `STRUCT_FIELDS` and/or `INDEX_FIELDS_MANUAL` in `apply_struct_fields.py`
7. Add to `trilogy_state.h`
8. Re-run the pipeline

### 5d. Expected Field Categories

Fields typically fall into these categories:

| Category | Pattern | Examples |
|----------|---------|---------|
| Buffer pointer | `HeapFree(ptr)`, `malloc()` | `staging_buffer`, `work_buffer` |
| Dimension | `width * height * 4` | `buf_width`, `src_height` |
| Loop counter | `i = 0; i < max; i++` | `pixel_index`, `blend_pass_count` |
| Boolean flag | `if (field != 0) { ... = 0 }` | `buffers_allocated`, `audio_ready` |
| Color value | Compared against 0xFF, packed ARGB | `transparent_color`, `clear_color` |
| Coordinate | `pixel - center` | `pixel_dx`, `pixel_dy` |
| Channel | `>> 8 & 0xff` | `red_channel`, `green_channel` |
| Preset parameter | `preset[idx * 0x7B + 0xNNN]` | `shadow_radius`, `src_center_x` |

## Step 6: Iterate

The field identification process is iterative:

1. Run pipeline → count remaining unknowns
2. Pick top 10–20 highest-frequency unknowns
3. Analyze with Techniques 1–11
4. Add fields to `STRUCT_FIELDS`, `INDEX_FIELDS_MANUAL`, `trilogy_state.h`
5. Re-run pipeline
6. Repeat until remaining count stabilizes or drops below threshold

## DLL Comparison

| DLL | Size | Code Identity | Notes |
|-----|------|---------------|-------|
| TrilogyI.dll | 167,936 | Baseline | `ae3b109f197c8a6a62c545ad87bd0214` |
| TrilogyIII.dll | 167,936 | **Identical to I** | `fb841a54309221bb533279e91495ae2f` |
| TrilogyII.dll | 172,032 | Different build | `14d72ee449e125fcfcfef18c9775bbe8` |

TrilogyII addresses are shifted +0x10 for most functions. CRT/memory functions have completely different addresses.

## Project Structure

```
visualization/
├── presets/
│   ├── Trilogy-I/decompiled/
│   │   ├── TrilogyI_decompiled.c    # Renamed + struct-substituted
│   │   └── trilogy_state.h          # State struct definition
│   ├── Trilogy-II/decompiled/
│   │   ├── TrilogyII_decompiled.c
│   │   └── trilogy_state.h
│   └── Trilogy-III/decompiled/
│       ├── TrilogyIII_decompiled.c
│       └── trilogy_state.h
├── tools/
│   ├── rename_decompiled.py         # Step 3a: function renaming
│   ├── rename_variables.py          # Step 3b: variable renaming
│   └── apply_struct_fields.py       # Step 3c: struct field substitution
├── skills/
│   ├── deep-decompilation/          # This skill
│   └── port-wmp-viz/               # Porting to .milk presets
└── function_mapping.md              # Cross-DLL function mapping
```

## Key Learnings

### What Works

1. **CAB extraction** reliably extracts all WMP viz DLLs
2. **Ghidra headless** with 300s timeout handles DLLs <200KB
3. **Sin LUT** at fixed offset (0xBC28), 360 entries × 4 bytes — anchors angle parameters
4. **Per-pixel loop** is the key to identifying most working variables (Technique 9)
5. **ARGB decomposition** pattern identifies all channel variables (Technique 10)
6. **Cross-DLL comparison** reveals which offsets are compile-time constants vs relocated data

### What Doesn't Work

1. **DirectDraw rendering** is deeply tied to Windows APIs — cannot be directly ported to HLSL/GLSL
2. **State struct offsets are fragile** — changing one offset cascades through the entire decompilation
3. **COM interface boundaries** are opaque without original SDK headers
4. **Color functions are often inlined** — HSV/HSL conversion and palette interpolation rarely appear as distinct functions
5. **Audio data flow** is complex — TimedLevel is passed by pointer and stored in multiple places

### Trilogy-Specific Patterns

1. **Shared pipeline**: Multiple visualizations share the same render infrastructure. Different vis = different parameter set
2. **Per-preset data**: 54 presets × 492 bytes (stride 0x1EC), base at byte 0x30E4
3. **Spectrum buffers**: 4 × 520 floats at 0x9BA8–0xC7F0
4. **Two access patterns**: Pattern A (int array index) and Pattern B (byte offset pointer cast) refer to the same fields
5. **Memory reuse**: Some offsets serve different purposes in different pipeline phases (e.g., 0xC8D4 is both `active_preset_list[1]` and `src_center_y`)
