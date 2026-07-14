---
name: port-wmp-viz
description: Port Windows Media Player visualization plugins (.exe/.dll) to ProjectM/MilkDrop .milk presets via Ghidra reverse engineering. Triggers on keywords: WMP visualization, port visualization, wmpvis, milkdrop preset, disassemble viz.
---

# Port WMP Visualizations to ProjectM MilkDrop Presets

Step-by-step workflow for extracting, reverse engineering, and porting Windows Media Player visualization DLLs to ProjectM `.milk` presets.

## Prerequisites

| Tool | Install | Notes |
|------|---------|-------|
| **Ghidra** | `brew install --cask ghidra` or [download](https://github.com/NationalSecurityAgency/ghidra/releases) | 12.x+ recommended |
| **Java 21+** | `brew install openjdk@21` | Required by Ghidra — verify with `java -version` |
| **cabextract** | `brew install cabextract` | Extracts MS CAB archives |
| **ProjectM** | [Build from source](https://github.com/projectm-visualizer/projectm) | For testing presets |
| **Python 3** | System default | For the syntax validator |
| **C++ compiler** | Xcode/clang or gcc | For the C++ validation tools |
| **(Optional) gh** | `brew install gh` | For publishing presets to GitHub |

### macOS Notes
- `cabextract` is available via Homebrew: `brew install cabextract`
- On Apple Silicon, build ProjectM arm64 core + x86_64 SDL2 test UI (for Rosetta compatibility with x86_64 Homebrew SDL2)
- No `sudo` needed — use `~/.projectM/` for config and presets

## Step 1: Set Up Project Directory

```bash
WORKDIR=~/devel/wmp-viz-port
mkdir -p "$WORKDIR"/{extracted,ghidra-project,output}
```

## Step 2: Extract the DLL from the Installer

WMP viz `.exe` files are typically **MS CAB self-extracting archives**:

```bash
# Check file type
file /path/to/vizname.exe
# Expected: PE32 executable ... MS CAB self-extracting archive

# Extract
cd "$WORKDIR/extracted"
cabextract ../vizname.exe
```

This yields:
- `VizName.dll` — the visualization COM DLL
- `VizName.inf` — install config (viz name, description, COM registration)
- Installer infrastructure DLLs — ignore

### Embedded CAB (non-standard offsets)

Some `.exe` files have a CAB embedded at a non-zero offset (not at byte 0). Find and extract it:

```python
# Find the CAB offset
with open("vizname.exe", "rb") as f:
    data = f.read()
    offset = data.find(b'MSCF')
    print(f"CAB found at offset: {offset}")

# Extract the CAB slice
with open("vizname.exe", "rb") as f:
    f.seek(offset)
    cab_data = f.read()
    with open("embedded.cab", "wb") as out:
        out.write(cab_data)

# Then extract
cabextract embedded.cab
```

### Read the .inf for metadata

```bash
cat VizName.inf
# Look for: description, COM class ID, viz names
# Example: val description = s 'Trilogy III - Lava'
```

## Step 3: DLL Recon

```bash
# File type
file extracted/VizName.dll

# Key strings — viz names, APIs, COM interfaces
strings extracted/VizName.dll | grep -iE "render|direct|d3d|ddraw|audio|fft|color|blend|CLSID|IID"

# COM class ID
strings extracted/VizName.dll | grep -i "CLSID\|classid"

# Rendering API
strings extracted/VizName.dll | grep -i "DDRAW\|D3D\|BitBlt\|StretchDIBits"
```

## Step 4: Ghidra Headless Analysis

### First Pass — Import and Auto-Analyze

```bash
GHIDRA_PATH=/path/to/ghidra_XXXX_PUBLIC/support

"$GHIDRA_PATH/analyzeHeadless" "$WORKDIR/ghidra-project" VizName \
  -import "$WORKDIR/extracted/VizName.dll" \
  -processor x86:LE:32:default \
  -analysisTimeoutPerFile 300
```

### Decompile All Functions

Use the `DumpDecompiled.java` script (see Appendix A):

```bash
# Copy script to Ghidra scripts dir (required — Ghidra caches scripts)
cp DumpDecompiled.java /path/to/ghidra/Ghidra/Features/Base/ghidra_scripts/

# Run decompilation
"$GHIDRA_PATH/analyzeHeadless" "$WORKDIR/ghidra-project" VizName \
  -process VizName.dll \
  -noanalysis \
  -scriptPath "$WORKDIR" \
  -postScript DumpDecompiled.java "$WORKDIR/output"
```

Output: `$WORKDIR/output/decompiled_VizName.txt`

**Important**: Ghidra caches scripts internally. Always `cp` updated scripts to the Ghidra scripts directory, even when using `-scriptPath`.

## Step 5: Identify the Renderers

```bash
# Named functions (skip internal FUN_xxxxxxxx)
grep "Function:" decompiled_output.txt | grep -v "FUN_"

# Largest functions (likely renderers) — sort by line count
awk '/^\/\/ Function:/{name=$0; start=NR} /^====/{if(start && NR-start > 100) print start, NR-start, name}' \
  decompiled_output.txt | sort -k2 -rn | head -20

# Rendering API calls
grep -n "DirectDraw\|CreateSurface\|BitBlt\|StretchDIBits\|SetPalette" decompiled_output.txt

# Math operations (identifies coordinate transforms)
grep -n "sin\|cos\|sqrt\|pow\|atan\|__ftol" decompiled_output.txt

# Audio data flow
grep -n "peak\|level\|frequency\|spectrum\|waveform\|audioData" decompiled_output.txt
```

### Key Architecture Patterns

- **COM-based**: All WMP viz are COM objects implementing vtable-based interfaces
- **Shared pipeline**: Multiple visualizations share the same render infrastructure — different vis = different parameter set
- **State struct**: ~50KB struct with sin LUT, audio peaks, framebuffer pointers, per-vis params at fixed offsets
- **Sin LUT**: 360-entry float table at a fixed offset — used to identify angle parameters
- **Audio peaks**: Normalized to [0,1] by dividing by 255.0, stored at fixed stride (e.g. `0xE0` bytes)
- **DirectDraw**: Most use DirectDraw + GDI for final compositing

## Step 6: Analyze the Algorithms

For each visualization renderer, identify:

1. **Coordinate system** — cartesian, polar, screen-space
2. **Color math** — interpolation, channel rotation, HSV, easing functions
3. **Audio reactivity** — which audio bands drive which parameters
4. **Effects** — blur, edge detection, distance fields, noise
5. **Warp/distortion** — how the coordinate space is distorted
6. **Shapes/geometry** — what shapes are drawn and how

Document each in a `PORT_PLAN.md` file.

## Step 7: Map to .milk Preset Format

### EEL vs HLSL — Know the Limits

| Feature | Per-frame/per-pixel EEL | Per-point EEL | HLSL (composite/warp shaders) |
|---------|------------------------|---------------|-------------------------------|
| `sin()`, `cos()`, `atan2()`, `sqrt()`, `abs()` | ✅ | ✅ | ✅ |
| `max()`, `min()`, `pow()` | ✅ | ✅ | ✅ |
| `mod()` | ✅ | ✅ | ✅ (`fmod` also works) |
| `if(cond, a, b)` ternary | ✅ (3 args only) | ✅ (3 args only) | N/A |
| `rand()` | ❌ | ✅ | N/A |
| `step()`, `smoothstep()`, `saturate()`, `lerp()` | ❌ | ❌ | ✅ |
| `select()` | ❌ | ❌ | ❌ |
| `if/else` blocks | ❌ | ❌ | ✅ |
| `floor()`, `ceil()`, `round()` | ❌ | ❌ | ✅ |
| `fmod()` | ❌ | ❌ | ✅ |
| `tex2D()` | ❌ | ❌ | ✅ |
| `for` loops | ❌ | ❌ | ✅ |

### EEL Workarounds

```
select(c, a, b)       →  c*a + (1-c)*b
if (c) x = a          →  x = c*a + (1-c)*x
step(thresh, val)     →  (val > thresh)
smoothstep(a, b, x)   →  t = min(max((x-a)/(b-a), 0), 1); t*t*(3-2*t)
clamp(x, lo, hi)      →  min(max(x, lo), hi)
fmod(a, b)            →  avoid entirely in per-pixel (no floor available)
```

### Audio Variables

| Variable | Description |
|----------|-------------|
| `bass`, `mid`, `treb` | Raw peak levels (0-1) |
| `bass_att`, `mid_att`, `treble_att` | Attenuated/averaged (smooth) |
| `time` | Seconds since start |

### .milk File Structure

```ini
[preset00]
// Header: fRating, fGammaAdj, fVideoEchoZoom, etc.
// Wave/shape definitions
// Per-frame equations
// Per-pixel equations
// Warp shader (HLSL with backtick line continuation)
// Composite shader (HLSL)
```

**Critical formatting rules**:
- **MUST set version headers BEFORE `[preset00]`** or composite shaders are completely ignored:
  ```
  MILKDROP_PRESET_VERSION=201
  PSVERSION=2
  PSVERSION_WARP=2
  PSVERSION_COMP=2
  [preset00]
  ```
- Without these, ProjectM defaults to MilkDrop 1.x (presetVersion=100) which has no shader support — presets render as black
- Per-pixel/per-frame lines must be sequentially numbered: `per_pixel_1=`, `per_pixel_2=`, etc.
- **Same rule applies to `comp_` and `warp_` lines**: gaps in numbering terminate the parser — `comp_28` followed by `comp_35` means lines 29-34 are lost and the shader will have syntax errors (missing closing `}`, etc.)
- Comment-only lines (`per_pixel_5=// comment`) occupy a line number
- **NEVER use `//` or `/* */` comments inside backtick-continued shader lines** (`comp_N=\``, `warp_N=\``). The `.milk` parser strips `//` comments at the line level before the HLSL compiler sees them, corrupting the code. The shader falls back to the default passthrough silently with a single WARN log line.
  - ✅ `comp_1=\`  ret = tex2D(sampler_main, uv).xyz;`
  - ❌ `comp_1=\`  // read texture\n  ret = tex2D(sampler_main, uv).xyz;`

### HLSL → GLSL Transpiler Limitations

The ProjectM HLSL transpiler (M4::HLSLParser) has quirks that can cause silent compilation failures:

- **No variables inside `sin()`/`cos()` arguments**: Using previously-defined local variables in trig functions will fail. `sin(t*speed)` = ❌, `sin(time*0.6*(0.8 + 0.6*bass))` = ✅. Decompose to `sin(time*CONSTANT + bass*time*CONSTANT)` pattern.
- **Avoid `sqrt()` and `pow()` with non-integer exponents**: Prefer literal multiplication: `lava*lava*lava` instead of `pow(lava, 3.0)`. `sqrt()` can cause NaN propagation issues.
- **`atan2` creates visible seam**: Using `atan2(y, x)` for polar coordinates creates a visible discontinuity at the left edge (angle wraps from π to -π). Use cartesian coordinates (`uv2.x`, `uv2.y`) instead.
- **`treb_att` is the correct name**: NOT `treble_att`. The attenuated treble uniform is `treb_att`.

Safe trig pattern:
```hlsl
float p1 = 0.5 + 0.5*sin(uv2.x*12.0 + uv2.y*10.0 - time*0.5 + bass*time*0.3);
float p2 = 0.5 + 0.5*sin(uv2.x*8.0 - uv2.y*14.0 + time*0.6 + mid*time*0.2);
```

## Step 8: Write the Preset

### Approach

1. **Start with composite shader** — get the visual effect right in HLSL first (full language support)
2. **Extract to per-frame/per-pixel** — move what can be expressed in EEL for performance
3. **Add audio reactivity** — use `bass_att`/`mid_att`/`treb_att` for smooth response (attenuated/averaged). These are available as built-in uniforms in composite/warp shaders — no per_frame q-variables needed.
   - Raw peaks: `bass`, `mid`, `treb` (instantaneous, can strobe)
   - Smoothed: `bass_att`, `mid_att`, `treb_att` (smooth, use for color modulation)
4. **Test iteratively** — validate syntax, then test visually

### Minimum Viable Preset

```ini
[preset00]
fRating=3.000000
fGammaAdj=1.000000
fVideoEchoZoom=1.000000
fVideoEchoAngle=0.000000
fWaveMode=0
bWaveThick=false
bAdditiveWaves=false
bWaveDarken=false
bSmooth=true
bModWaveAlphaByVolume=false
bModWaveAlphaReverse=false
bInterlace=false
bBrighten=false
bDarken=false
bSolarize=false
fWaveAlpha=0.700000
fWaveScale=1.000000
fWaveSmoothing=0.500000
fWaveAspect=1.000000
fWarpAnimSpeed=1.000000
fWarpScale=1.500000
fZoomExponent=1.000000
fZoom=1.000000
fSpin=0.000000
fZoomCamera=0.000000
dx=0.000000
dy=0.000000
cx=0.500000
cy=0.500000
sx=1.000000
sy=1.000000
ob_size=0.000000
ob_r=0.000000
ob_g=0.000000
ob_b=0.000000
ob_a=0.000000
ib_size=0.000000
ib_r=0.000000
ib_g=0.000000
ib_b=0.000000
ib_a=0.000000
wave_r=1.000000
wave_g=1.000000
wave_b=1.000000
wave_a=0.500000
wave_mode=0
wave_scale=1.000000
wave_smoothing=0.500000
wave_mystery=0.000000
wave_aspect=1.000000
fDecay=0.970000

per_frame_1=t = time;

comp_1=`shader_body
comp_2=`{
comp_3=`  ret = float3(0, 0, 0);
comp_4=`}
```

## Step 9: Validate and Test

### Python Syntax Validator

```bash
python3 validate_milk.py preset.milk
```

Checks: sequential numbering, valid EEL syntax, header completeness, shader structure.

### C++ PresetFileParser (Semantic)

```bash
g++ -std=c++17 \
  -I./projectm/src/libprojectM \
  -I./projectm/vendor/hlslparser/src \
  -I./projectm/src/api/include \
  -I./projectm/build/src/api/include \
  test_parser.cpp \
  ./projectm/build/src/libprojectM/MilkdropPreset/CMakeFiles/MilkdropPreset.dir/PresetFileParser.cpp.o \
  -o test_parser
./test_parser preset1.milk preset2.milk
```

This actually compiles the EEL and HLSL — catches runtime errors the Python validator misses.

### Visual Test with ProjectM

```bash
# Copy presets
mkdir -p ~/.projectM/presets
cp *.milk ~/.projectM/presets/

# Run from config dir
cd ~/.projectM
/path/to/projectm/build/src/sdl-test-ui/projectM-Test-UI
```

- Arrow keys cycle presets
- `F` toggles fullscreen
- No audio required — renders with synthetic audio
- Look for `ERROR` lines in output — those are EEL/HLSL compilation failures

## Step 10: Visual Approximation (When Decompilation Fails)

If decompilation yields complex DirectDraw/GDI code that's hard to reverse-engineer, use **visual approximation** from screenshots:

### Analyze Original Screenshots

```python
from PIL import Image
import numpy as np

img = Image.open('original_screenshot.jpg')
arr = np.array(img)

# Color palette
print(f'Mean RGB: {arr.mean(axis=(0,1))}')

# Spatial distribution
h, w = arr.shape[:2]
cy, cx = h//2, w//2
for r_frac in [0.1, 0.2, 0.3, 0.4, 0.5]:
    r = int(min(h,w) * r_frac)
    mask = ((X - cx)**2 + (Y - cy)**2) <= r**2
    region = arr[mask]
    print(f'r={r_frac}: mean={region.mean(axis=0)}')

# Symmetry check
left = arr[:, :w//2]
right = arr[:, w//2:][:, ::-1]
diff = np.abs(left.astype(float) - right.astype(float)).mean()
print(f'Left-right symmetry diff: {diff:.2f}')
```

### Create Composite Shader Preset

Use math-simulated effects instead of audio-reactive FFT:

```ini
MILKDROP_PRESET_VERSION=201
PSVERSION=2
PSVERSION_COMP=2
[preset00]
fDecay=0.950000

per_frame_1=warp = 0;
per_frame_2=wave_a = 0;

comp_1=`shader_body
comp_2=`{
comp_3=`  float2 uv_c = uv - 0.5;
comp_4=`  float r = length(uv_c);
comp_5=`  float angle = atan2(uv_c.y, uv_c.x);
comp_6=`  float t = time * 0.5;
comp_7=`
comp_8=`  // Create pattern based on screenshot analysis
comp_9=`  float pattern = sin(angle * 3.0 + r * 12.0 - t * 2.0);
comp_10=`  float brightness = max(0.0, 1.0 - r * 2.0);
comp_11=`  brightness = brightness * brightness;
comp_12=`  float glow = pattern * brightness;
comp_13=`
comp_14=`  // Match color palette from screenshot
comp_15=`  ret = float3(glow * 1.0, glow * 0.55, glow * 0.18);
comp_16=`}
```

### Key Patterns

- **Spiral**: `sin(angle * N + r * M - t * S)` — N=arms, M=tightness, S=speed
- **Radial gradient**: `max(0, 1 - r * falloff)` — controls brightness distribution
- **Wing-like**: `sin(angle * 2) * sin(angle * 2) * max(0, offset - uv_c.y)`
- **Color matching**: Adjust RGB ratios to match screenshot mean colors

### Validate

```bash
# Test compilation
venv/bin/python3 validate_milk.py preset.milk

# Take screenshot and compare
projectM-Test-UI --preset preset.milk --screenshot out.bmp --frames 60
venv/bin/python3 compare_screenshots.py out.bmp original.jpg
```

## Step 11: Iterate

1. Start with the simplest visualization
2. Create a minimal preset
3. Test, observe, adjust
4. Add audio reactivity
5. Move to the next visualization
6. Tune transitions between presets

## Critical Learnings

### Rendering Pipeline (Must Understand)

```
Frame N:
1. WARP: reads previous frame, applies zoom/dx/dy/rot + per-pixel equations
   → fDecay multiplies previous frame (0=discard, 0.95=trails, 1.0=infinite)
2. CUSTOM SHAPES (0-15)
3. CUSTOM WAVEFORMS (0-3) — per_point code runs here
4. BUILT-IN WAVEFORM
5. DARKEN CENTER
6. BORDER
7. COMPOSITE: reads current frame, writes to previous frame buffer
8. SWAP: current ↔ previous
```

**Key insight**: Composite output feeds back through warp next frame. With `fDecay=1.0`, this causes infinite accumulation ("lava" effect). With `fDecay=0.0`, nothing persists (black screen).

**Critical pipeline nuance**: The user sees the WARP output (currentFrameBuffer), NOT the composite output directly. The composite writes to the previous frame buffer, which becomes the warp's input next frame. So the visual is always one frame delayed through warp + fDecay:
- Composite generates fresh content → stored as "previous frame"
- Next frame: warp reads it, applies fDecay + mesh distortion → displayed
- So the user sees a faded+distorted version of what the composite produced last frame
  
If per_pixel equations push vertices outward (dx = ux*...), the warp displaces content outward each frame. Combined with fDecay < 1.0, content fades while drifting outward → eventual black screen after ~30 frames.

### Spectrum Analyzer Pattern

ProjectM's FFT equalization suppresses low frequencies heavily (DC=0, bass≈0.00004, treble≈0.125). The `value1` variable in custom waveforms is **not** raw FFT magnitude — it's equalized and scaled.

**Working pattern for spectrum displays**:
```ini
per_frame_1=warp = 0;            # MUST disable warp for static displays
per_frame_2=wave_a = 0;          # Hide built-in wave

wavecode_0_enabled=1
wavecode_0_bSpectrum=1           # value1 = FFT magnitude
wavecode_0_samples=512           # Max frequency resolution
wavecode_0_scaling=0.5           # Amplify spectrum
wavecode_0_smoothing=0.5         # Temporal smoothing
wavecode_0_bUseDots=0            # Connected polyline
wavecode_0_bAdditive=0           # Opaque (not additive)

# CRITICAL: Multiply value1 by 10x+ to compensate for FFT equalization
wave_0_per_point1=x = sample;
wave_0_per_point2=y = 0.5 - value1 * 10.0;
```

### Common Pitfalls

1. **NOT setting `warp=0`** → causes lava/flow distortion
2. **`fDecay=1.0`** → causes accumulation/lava effect
3. **`fDecay=0.0`** → causes black screen (no persistence)
4. **Using composite shader for basic rendering** → most presets don't need it
5. **Using `if/else` blocks in per-point EEL** → fails silently
6. **Using `floor()`, `fract()`, `step()` in per-point EEL** → undefined behavior
7. **Setting `wave_a=0` but forgetting `warp=0`** → warp still distorts everything
8. **`//` comments in backtick shader lines** → the `.milk` parser strips `//` at the line level, corrupting the HLSL code. The shader falls back silently to passthrough (`tex2D(sampler_main, uv)`). Remove ALL comments from backtick-continued lines.
9. **Numbering gaps in `comp_` lines** → parser stops at the gap, shader gets missing lines (closing `}`, trailing code). Keep sequential numbering for ALL prefixed lines.
10. **per_pixel outward push (`dx = ux*...`, `dy = uy*...`) + fDecay < 1.0** → mesh drifts outward each frame, content fades — screen goes black after ~30 frames. Use angular/circular displacement instead (`dx = 0.003*sin(...)`, `dy = 0.003*cos(...)`).
11. **smoothstep/radius clipping** — `smoothstep(r-0.05, r, dist2)` with `r=0.4` clips everything beyond 0.4 (most of the screen). Ensure radius covers the visible range.
12. **`mid` is a built-in audio uniform in HLSL shaders** — declaring a local variable named `mid` in composite/warp shaders causes a compilation conflict with the pre-defined `mid` uniform (mid-range audio level). Rename to `mid_c` or similar.
13. **`PSVERSION_WARP=2` without any warp shader lines** (`warp_N=\``...) causes "Error compiling composite warp shader code" — the parser expects a warp shader section but finds none. Remove `PSVERSION_WARP` if no custom warp shader is needed.

## Common WMP → MilkDrop Mapping

| WMP Type | MilkDrop Approach |
|----------|-------------------|
| Perlin noise | Warp shader with noise + blur |
| Particles | Shape objects with `t`-based animation |
| Waveforms | Wave objects with `wave_mode` |
| Geometric rotation | Composite shader with rotation matrix |
| Distance fields | Warp shader with `atan2`/`sqrt` |
| Color cycling | Composite shader with `sin(time + phase)` |
| Pixel manipulation | Warp shader texture reads |

## Appendix A: DumpDecompiled.java

```java
// @category Analysis
// Usage: analyzeHeadless ... -postScript DumpDecompiled.java [output_dir]
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.List;

public class DumpDecompiled extends GhidraScript {
    @Override
    public void run() throws Exception {
        List<String> args = getScriptArgs();
        String progName = currentProgram.getName();
        String stem = progName.replace(".dll", "").replace(".DLL", "");
        String outputDir;
        if (args.size() >= 1) {
            outputDir = args.get(0);
        } else {
            File exePath = new File(currentProgram.getExecutablePath());
            outputDir = exePath.getParent();
        }
        File outDir = new File(outputDir);
        if (!outDir.exists()) outDir.mkdirs();
        String outputPath = outputDir + File.separator + "decompiled_" + stem + ".txt";

        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        PrintWriter pw = new PrintWriter(new FileWriter(outputPath));
        pw.println("=== DECOMPILED FUNCTIONS: " + progName + " ===\n");
        int count = 0;
        FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
        while (funcs.hasNext()) {
            Function func = funcs.next();
            DecompileResults result = decomp.decompileFunction(func, 30, monitor);
            pw.println("======================================================================");
            pw.println("// Function: " + func.getName() + " @ " + func.getEntryPoint());
            pw.println("======================================================================");
            if (result != null && result.decompileCompleted()) {
                String c = result.getDecompiledFunction().getC();
                pw.println(c != null ? c : "// <no decompilation>");
            } else {
                pw.println("// <decompilation failed>");
            }
            pw.println("\n");
            count++;
        }
        pw.println("\n=== TOTAL: " + count + " functions ===");
        pw.flush(); pw.close();
        println("Dumped " + count + " functions to " + outputPath);
        decomp.dispose();
    }
}
```

## Appendix B: Python Syntax Validator

```python
#!/usr/bin/env python3
"""Validate a .milk preset file for common issues."""
import sys, re

def validate(path):
    errors = []
    with open(path) as f:
        lines = f.readlines()

    if not lines or not lines[0].strip().startswith("[preset"):
        errors.append("Missing [preset00] header")

    sections = {"per_frame": [], "per_pixel": [], "comp": [], "warp": []}
    for i, line in enumerate(lines, 1):
        line = line.strip()
        for prefix in sections:
            m = re.match(rf"{prefix}_(\d+)=(.*)", line)
            if m:
                num = int(m.group(1))
                sections[prefix].append((i, num, m.group(2)))

    for name, items in sections.items():
        if not items:
            continue
        nums = [n for _, n, _ in items]
        expected = list(range(1, max(nums) + 1))
        missing = set(expected) - set(nums)
        if missing:
            errors.append(f"{name}: missing lines {sorted(missing)}")
        dupes = [n for n in nums if nums.count(n) > 1]
        if dupes:
            errors.append(f"{name}: duplicate line numbers {sorted(set(dupes))}")

    if errors:
        print(f"FAIL {path}:")
        for e in errors:
            print(f"  {e}")
        return 1
    print(f"OK {path}")
    return 0

if __name__ == "__main__":
    sys.exit(sum(validate(p) for p in sys.argv[1:]))
```

## Appendix C: C++ Validation Build

```bash
# Build the test_parser (requires ProjectM source and build)
g++ -std=c++17 \
  -I./projectm/src/libprojectM \
  -I./projectm/vendor/hlslparser/src \
  -I./projectm/src/api/include \
  -I./projectm/build/src/api/include \
  test_parser.cpp \
  ./projectm/build/src/libprojectM/MilkdropPreset/CMakeFiles/MilkdropPreset.dir/PresetFileParser.cpp.o \
  -o test_parser

# Usage
./test_parser preset1.milk preset2.milk preset3.milk
# Exit code 0 = all pass, 1 = any fail
```
