---
name: plan-milk-preset
description: Use when creating a plan for porting a WMP visualization to a MilkDrop .milk preset. Analyzes decompiled rendering pipeline code and produces a structured preset plan document. Triggers on keywords like milk preset plan, preset plan, port to milk, milkdrop mapping, rendering-to-milk, visualization plan.
---

# Plan a MilkDrop Preset from Decompiled WMP Code

Takes a mapped rendering pipeline (from `deep-decompilation` skill + `RENDERING-PIPELINE.md`) and produces a structured preset plan: a document that maps every WMP visual behavior to a MilkDrop equivalent, organized by MilkDrop's file structure. The plan is then used by a coder to write the actual `.milk` file.

## Prerequisites

| Input | Description |
|-------|-------------|
| `RENDERING-PIPELINE.md` | Comprehensive mapping of decompiled code to visual behavior |
| `*_decompiled.c` | Renamed + struct-substituted decompiled code |
| `trilogy_state.h` | State struct definition |
| `vtable_mapping.md` | vtable slot → function mapping (if available) |

The `disassemble-wmp-viz` and `deep-decompilation` skills must already be complete.

## Step 1: Identify Per-Pixel Transform Behavior

The core visual of any WMP preset lives in the per-pixel rendering loop(s). Find these in the decompiled code by searching for the innermost loops containing pixel-level coordinate math.

### 1a. Per-Pixel Loop Structure

Every per-pixel loop follows this skeleton:

```c
pixel_index = 0;
while (pixel_index < total_pixels) {
    row = pixel_index / src_width;
    col = pixel_index % src_width;
    dx = col - center_x;
    dy = row - center_y;
    // ... visual transform ...
    pixel_index++;
}
```

**Extract for the plan:**
- `src_width`, `src_height` — working resolution
- `center_x`, `center_y` — coordinate origin
- What `dx`, `dy` are used for — linear motion? polar? both?

### 1b. Polar Coordinate Transforms

If the code computes `sqrt(dx² + dy²)` or uses sin/cos with angle calculations, it's doing polar transforms. This maps to MilkDrop's per-pixel `rad` and `ang` built-in variables.

```c
// WMP code pattern — recognize and extract parameters:
radius = sqrt(dx*dx + dy*dy);
angle = atan2(dy, dx);
sin_val = sin(angle * n + offset);  // from sin LUT
```

**Extract for the plan:**
- What function of `rad` and `ang` controls the visual?
- Are there multiple frequency/multiplier values?
- Is the sin/cos LUT used (360 entries, fixed phase)?

### 1c. Direction Filtering

Some presets filter pixels by direction (wedge/ring):

```c
if (direction == 2) {
    if (col > center_x) continue;   // wedge: left half only
}
```

**Extract for the plan:**
- Direction filter type: none / wedge / ring
- Which quadrants/regions are active?
- Is the filter frame-dependent (animated)?

### 1d. RGB Channel Mixing

Per-pixel color manipulation — the code mixes source RGB toward target RGB based on some factor:

```c
r = (src_r * (1 - factor) + target_r * factor) & 0xFF;
g = (src_g * (1 - factor) + target_g * factor) & 0xFF;
b = (src_b * (1 - factor) + target_b * factor) & 0xFF;
```

**Extract for the plan:**
- What `factor` controls the mix (radial falloff? angular? fixed?)
- What are the target colors? (often from per-preset data offsets `0x3198/0x319C/0x31A0`)
- Is the factor computed from polar coordinates?

## Step 2: Identify Blend & Transition Behavior

### 2a. Fade/Transition

If `Effect_Fade2` is called, the preset supports blend transitions:

```c
if (state->fade_active != 0) {
    fade_factor = state->fade_progress;  // 0.0–1.0
    blend_alpha = (1.0 - fade_factor) * fade_speed;
    output = src * (1-blend_alpha) + prev_frame * blend_alpha;
}
```

**Extract for the plan:**
- Is the preset single-frame (no blend) or has blend/transition support?
- What blend modes are used (Screen, Multiply, Overlay, SoftLight)?
- What blend intensity is applied at each tier?

### 2b. Blend Modes

The DLL supports 4 blend modes, selected by per-preset data:

| Blend | Formula | MilkDrop Equivalent |
|-------|---------|---------------------|
| Screen | `1 - (1-a)*(1-b)` | Custom shader or `screenblend` |
| Multiply | `a * b` | Per-pixel `blend` equation |
| Overlay | `a < 0.5 ? 2*a*b : 1-2*(1-a)*(1-b)` | Custom shader |
| SoftLight | Custom formula | Custom shader |

**Extract for the plan:**
- Which blend mode the current preset uses
- Blend intensity: low / medium / high (3 tiers from vtable dispatch)

### 2c. Alpha Composite Spiral

`Blend_AlphaComposite` creates a spiral alpha pattern emanating from center:

```c
// Walk: right → up → left → down from center
// Alpha decreases along the spiral path
```

**Extract for the plan:**
- Is spiral alpha used? (rare — mostly for special effects)
- Spiral radius and decay rate

## Step 3: Identify Audio-Reactive Behavior

### 3a. Audio Data Sources

The preset reads audio from multiple sources:
- **Spectrum data**: 4 × 520 float arrays at `0x9BA8–0xC7F0` (per-band amplitudes)
- **Beat detection**: beat flag from WMP → drives hue rotation timing
- **Bass/mid/treb**: derived from spectrum bands → controls animation speed, color saturation

**Extract for the plan:**
- Which spectrum bands drive which visual parameters?
- Is beat detection used? (check for `beat_detected` flag in state)
- How does audio amplitude modulate visual parameters?

### 3b. Hue Rotation / Color Cycling

`Motion_ComplexPhysics` drives beat-reactive hue rotation:

```c
hue_rotation = (hue_rotation + hue_step) % 90;
target_r = (int)(255.0 * cos(hue_rotation * PI/45.0));
target_g = (int)(255.0 * cos((hue_rotation + 120) * PI/45.0));
target_b = (int)(255.0 * cos((hue_rotation + 240) * PI/45.0));
```

**Extract for the plan:**
- Hue rotation speed (radians/second or degrees/beat)
- Beat reactivity: does hue step on beat or continuously?
- Target color derivation: pure hue rotation? or mixed with preset target RGB?

## Step 4: Identify Texture Generation

### 4a. Texture Ping-Pong

`Effect_GenerateTexture` implements a double-buffered texture that evolves each frame:

```c
if (texture_state == 0) {
    // Write to texture A, read from texture B
    write_ptr = texture_A;
    read_ptr = texture_B;
    texture_state = 1;
} else {
    // Write to texture B, read from texture A
    write_ptr = texture_B;
    read_ptr = texture_A;
    texture_state = 0;
}
```

**Extract for the plan:**
- Is a generated texture used? (most Trilogy presets use it)
- What drives the texture content — per-pixel copy with offset? noise? mathematical pattern?
- Texture dimensions — typically same as working buffer (180×120 or 350×320)

### 4b. Texture as Visual Source

The texture often becomes the main visual element — a "living" background that evolves per-frame.

**Extract for the plan:**
- Is the texture the primary visual, or an overlay/modulation?
- How is the texture blended with the per-pixel output?

## Step 5: Map to MilkDrop Components

Translate every extracted behavior into MilkDrop's file structure.

### MilkDrop Preset File Structure

```ini
[preset]
fRating=3.0
fEvolution=0.5
fGammaAdj=1.0
fVideoEchoZoom=1.0
fVideoEchoAlpha=0.0
nVideoEchoOrientation=3
nWaveMode=0
bAdditiveWaves=0
bWaveThick=0
bBrighten=0
bDarken=0
bMirror=0
bSwap=0
bWaveDots=0
iWaveMode=0
iWaveRotation=0
iWaveAlpha=0
fWaveR=1.0
fWaveG=1.0
fWaveB=1.0
fWaveX=0.5
fWaveY=0.5
bModulateAlphaByVolume=0
bRedBlueStereo=0
bBrightenCenter=0
bRippledBase=0
fWrap=0.0

[per-pixel]
// Per-pixel equations — runs for every pixel every frame
// MilkDrop built-in: q1–q32, rad, ang, tex, width, height, time, frame, bass, mid, treb, vol
// Custom: dx, dy (from center), etc.
// Output: red, green, blue, alpha

[per-frame]
// Per-frame equations — runs once per frame
// Updates q1–q32 values used by per-pixel code
// Drives audio-reactive animation

[shape N]
// Shape definitions — geometric overlays
// Drawn on top of the per-pixel output

[wave N]
// Wave definitions — waveform lines
// Drawn on top of per-pixel output

[sampler N]
// Texture samplers — generated textures
// bound to sampler slots, readable in per-pixel via texN
```

### WMP → MilkDrop Mapping Table

| WMP Component | MilkDrop Equivalent |
|--------------|---------------------|
| Per-pixel loop body | `[per-pixel]` equations |
| `rad = sqrt(dx²+dy²)` | MilkDrop built-in `rad` |
| `ang = atan2(dy,dx)` | MilkDrop built-in `ang` |
| `sin(angle)` from LUT | `sin(ang * multiplier + time * speed)` |
| `cos(angle)` from LUT | `cos(ang * multiplier + time * speed)` |
| `dx = col - center_x` | MilkDrop built-in (normalized) `dx` |
| `dy = row - center_y` | MilkDrop built-in (normalized) `dy` |
| Per-pixel RGB mix | `[per-pixel]` red/green/blue equations |
| Per-frame animation | `[per-frame]` equations |
| `Effect_Fade2` blend | `fDecay` or per-pixel `blend` equation |
| `Blend_Screen` | `screenblend` param or custom |
| Hue rotation | `[per-frame]` q variable update |
| Beat flag | `beat` built-in variable |
| Bass amplitude | `bass` / `vol` built-in variables |
| Spectrum bands | `q1`–`q8` mapped from band data |
| Generated texture | `[sampler0]` + tex0 in per-pixel |
| Per-preset parameters | `[preset]` section + q variable ranges |
| Color target RGB | q variable range mapping |
| Motion vector (2D) | Per-pixel `dx`/`dy` offset |
| Polar coordinate | `rad`, `ang` in per-pixel |
| Frame buffer ping-pong | MilkDrop handles automatically |
| Working buffer (180×120) | MilkDrop internal (512×512) |
| Working buffer (350×320) | MilkDrop internal (512×512) |
| Texture copy with offset | `sampler0` + offset in per-pixel |
| Spiral alpha pattern | Per-pixel alpha equation |
| Window resize | `width`, `height` built-in |
| iQuality level | Map to MilkDrop quality params |

## Step 6: Write the Preset Plan Document

Produce a structured `.milk-plan.md` document. Use this template:

---

### Template: `{preset-name}.milk-plan.md`

```markdown
# {Preset Name} — MilkDrop Preset Plan

Source: `{source_dll}` decompiled rendering pipeline
Resolution: {working_width}×{working_height} → {output_width}×{output_height}

## Per-Pixel Equations

### Coordinate System
- Origin: center ({center_x}, {center_y})
- Normalized: yes/no
- Polar: yes/no
- Direction filter: none / wedge (left/right) / ring

### Visual Core
{description of what the per-pixel loop does, step by step}
```
// MilkDrop per-pixel equations
// TODO: implement from plan
```

### Color Pipeline
- Source: {texture / solid color / computed}
- RGB mix: {factor computation description}
- Target RGB: {from q variables / computed from angle}

## Per-Frame Equations

### Audio Reactivity
- Bass → {what parameter}
- Beat → {what parameter}
- Mid/Treb → {what parameter}

### Animation
- Hue rotation: {speed, beat-reactive: yes/no}
- Other animation: {description}
```
// MilkDrop per-frame equations
// TODO: implement from plan
```

## Blend / Transition
- Mode: {Screen / Multiply / Overlay / SoftLight / None}
- Intensity: {low / medium / high}
- Decay: {description}

## Textures
- sampler0: {what the texture contains, how it evolves}
- sampler1: {if applicable}

## Shapes
- Shape 1: {what it draws, when}
- Shape 2: {if applicable}

## Waves
- Wave 1: {what it draws, when}
- Wave 2: {if applicable}

## Parameters
- q1–q8: {what each q variable maps to, range}
- q9–q16: {if applicable}
- q17–q32: {if applicable}

## Quality Notes
- Per-pixel complexity: {low / medium / high}
- Texture reads per pixel: {count}
- Trig calls per pixel: {count}
- Recommended quality: {low/medium/high}
```

---

## Step 7: Validate the Plan

Before finalizing, check:

### Completeness Checklist

- [ ] Every pipeline function from RENDERING-PIPELINE.md has a MilkDrop mapping
- [ ] Per-pixel equations cover the full visual transform
- [ ] Per-frame equations cover all animation
- [ ] All audio-reactive behaviors are mapped
- [ ] Blend modes are specified
- [ ] Texture generation (if any) is specified
- [ ] Q variable ranges don't conflict
- [ ] Quality is appropriate for target hardware

### Consistency Checks

- [ ] Per-pixel equations produce a finite value for all possible `rad`/`ang` inputs
- [ ] No division by zero possible in per-pixel code
- [ ] Q variable updates in per-frame are self-consistent
- [ ] Texture coordinates are within [0,1] range
- [ ] Alpha output is clamped to [0,1]

## Example: Trilogy Visualizer Preset Mapping

This shows how the Trilogy DLL's 3-stage pipeline maps to MilkDrop:

| Pipeline Stage | WMP Function | MilkDrop Component |
|---------------|--------------|-------------------|
| Texture gen | `Effect_GenerateTexture` | `[sampler0]` + per-frame update |
| Per-pixel | `Transform_PolarCoords` | `[per-pixel]` rad/ang equations |
| Beat color | `Motion_ComplexPhysics` | `[per-frame]` q variable hue update |
| Fade | `Effect_Fade2` | `fDecay` or per-pixel blend |
| Mipmap blit | `Render_MipmapChain` | MilkDrop handles internally |
| Output | `Render_SwapFrameBuffers` | MilkDrop handles internally |

The `Transform_PolarCoords` per-pixel loop is the heart of the preset:
- Computes polar coords from pixel position
- Applies sin/cos modulation with LUT angles
- Direction filtering (wedge/ring)
- RGB mixing toward target colors based on radial distance
- All of this goes directly into `[per-pixel]` equations

The `Motion_ComplexPhysics` per-frame loop drives animation:
- Beat-reactive hue rotation
- Target RGB from per-preset data
- Audio amplitude modulation of blend speed
- All of this goes into `[per-frame]` equations that update q variables
