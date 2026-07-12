# WMP Visualizations → ProjectM MilkDrop Ports

Ports of classic Windows Media Player visualizations to [ProjectM](https://github.com/projectM-visualizer/projectm) MilkDrop `.milk` presets, reverse-engineered from the original WMP visualization DLLs using Ghidra.

## Visualizations

| Pack | Presets | Source |
|------|---------|--------|
| **Trilogy III** | `lava.milk`, `mystic_cloud.milk`, `undulation.milk` | `TrilogyIII.dll` |
| **Trilogy II** | `musical_sine.milk`, `fourth_dimension.milk`, `mathical_music.milk`, `random_selection.milk` | `TrilogyII.dll` |
| **PulsingColors** | `bars.milk`, `wave.milk` | `Pulsing.dll` |
| **MusicalColors** | `musical_colors.milk` | `wmpvis.dll` |

**10 presets total** — all validated and rendering with 0 errors on ProjectM (macOS/Apple Silicon, tested with OpenGL 4.1 core profile).

## Installation

1. **Install ProjectM** — see [ProjectM GitHub](https://github.com/projectM-visualizer/projectm) for your platform.

2. **Copy the presets** to your ProjectM presets directory:
   ```bash
   # Linux
   cp -r presets/* ~/.projectM/presets/
   
   # macOS
   cp -r presets/* ~/Library/Application\ Support/projectM/presets/
   
   # Or use any path and point ProjectM to it
   ```

3. **Run ProjectM** — any ProjectM client (SDL test UI, QProjectM, Android app, etc.) will pick up the presets from the presets directory.

### Quick Test (SDL2)

If you have the ProjectM source:
```bash
cd projectm
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(sysctl -n hw.ncpu)
cd src/sdl-test-ui
./projectM-Test-UI
# Press Space to cycle presets, Q to quit
```

## Porting Flow

These presets were ported from the original WMP visualization DLLs using a semi-automated reverse engineering pipeline:

### 1. Extract the DLLs
```
WMP Viz Installer (.exe)
    ↓ cabextract (MS CAB format)
Visualization DLL (.dll)
```

Some installers (e.g. MusicalColors) embed a CAB at a non-standard offset inside a PE executable. Use a hex search for `MSCF` to find it, extract the slice, then `cabextract` on that.

### 2. Decompile with Ghidra
```
DLL (.dll)
    ↓ Ghidra headless + DumpDecompiled.java
Decompiled C source (.c)
```

A custom Ghidra headless script (`DumpDecompiled.java`) decompiles all functions and writes the output to a text file. Run via:
```bash
ghidra_XXXX_PUBLIC/support/analyzeHeadless \
    /tmp/ghidra_project projectName \
    -import target.dll \
    -postScript DumpDecompiled.java outputPath
```

### 3. Reverse Engineer the Algorithms
```
Decompiled C source
    ↓ Analysis (state struct, sin LUTs, render pipeline)
Algorithm description (PORT_PLAN.md)
```

Key things to identify:
- **State struct**: large (~50KB) struct containing sin LUTs, audio peaks, framebuffer pointers, per-vis parameters at fixed offsets
- **Sin LUT**: 360-entry float table for fast sine lookups — used to identify which parameters are angles
- **Audio pipeline**: peaks divided by 255.0 → normalized to [0,1], stored at fixed stride (e.g. `0xE0` bytes)
- **Render functions**: the largest decompiled functions (100+ lines) are almost always the renderers

### 4. Write the MilkDrop Preset
```
Algorithm description
    ↓ Manual translation
.milk preset
```

Each preset has three layers:

| Section | Language | Capabilities |
|---------|----------|--------------|
| **Per-frame** | MilkDrop EEL | Audio reactivity, timing, parameter modulation |
| **Per-pixel** | MilkDrop EEL | Coordinate transforms, per-pixel effects |
| **Composite shader** | HLSL | Full HLSL (loops, conditionals, texture reads, `smoothstep`, `fmod`, etc.) |

**EEL is the bottleneck** — per-frame/per-pixel EEL is a minimal expression language. The following functions are **NOT available** in EEL:
- `smoothstep()`, `step()`, `lerp()`, `saturate()`, `clamp()` — use arithmetic: `min(max(x, 0.0), 1.0)`
- `select()`, `if/else` blocks — use ternary: `if(cond, a, b)` (3 args only)
- `floor()`, `ceil()`, `round()`, `fmod()`, `mod()` (in per-pixel) — use arithmetic equivalents
- Texture reads — use composite shader instead

Available in EEL: `sin()`, `cos()`, `atan2()`, `sqrt()`, `abs()`, `max()`, `min()`, `pow()`, `if()` (ternary only).

**HLSL composite shaders** support everything — loops, `if/else`, `fmod()`, `smoothstep()`, `tex2D()`, `lerp()`, `saturate()`, etc. Put complex logic there.

### 5. Validate and Test
```
.milk preset
    ↓ Python validator (syntax)
    ↓ C++ PresetFileParser (semantic — validates EEL compilation)
    ↓ ProjectM SDL test UI (visual — renders with real audio)
Confirmed working preset
```

### 6. Known Quirks
- `.milk` parser terminates at numbering gaps — always use sequential numbering (`per_frame_1`, `per_frame_2`, ...)
- Composite shader lines use backtick (`` ` ``) line continuation: `` comp_1=`shader_body ``
- Comment lines (`per_pixel_5=// comment`) are valid but occupy a line number — avoid duplicate numbering
- Per-pixel EEL runs on every pixel — keep it simple for performance

## Prerequisites for Porting

| Tool | Purpose |
|------|---------|
| [Ghidra](https://ghidra-sre.org/) | Reverse engineering / decompilation |
| [ProjectM](https://github.com/projectM-visualizer/projectm) | Testing the `.milk` presets |
| [cabextract](https://www.cabextract.org.uk/) | Extracting DLLs from WMP installer archives |
| Python 3 | Running the `.milk` syntax validator |
| C++ compiler | Building the C++ validation tools |

## Credits

**RootNotez** — Huge shoutout to [RootNotez](https://sites.google.com/view/wmpgoodies/visualizations) for preserving and archiving the original WMP visualization installers. Without this collection, these ports wouldn't exist. Check out the full WMP Goodies archive at [wmpgoodies.visualizations](https://sites.google.com/view/wmpgoodies/visualizations).

These ports were created by reverse-engineering the original WMP visualization DLLs with Ghidra, analyzing the algorithms, and translating them to MilkDrop/EEL/HLSL presets for use with ProjectM.

## Lessons Learned

### Rendering Pipeline (Critical)

Understanding the frame rendering order is essential:

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

## Project Structure

```
visualization/
├── README.md
├── presets/
│   ├── Trilogy-III/
│   │   ├── lava.milk
│   │   ├── mystic_cloud.milk
│   │   └── undulation.milk
│   ├── Trilogy-II/
│   │   ├── musical_sine.milk
│   │   ├── fourth_dimension.milk
│   │   ├── mathical_music.milk
│   │   └── random_selection.milk
│   ├── PulsingColors/
│   │   ├── bars.milk
│   │   └── wave.milk
│   └── MusicalColors/
│       └── musical_colors.milk
└── skills/
    └── port-wmp-viz/
        └── SKILL.md    # Reusable workflow for porting more viz
```

## License

These are ports of proprietary Windows Media Player visualizations for personal/educational use. The original visualizations are Microsoft property. The ported `.milk` presets are derivative works — use at your own discretion.
