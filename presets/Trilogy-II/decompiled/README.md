# Trilogy II - Mystic Cloud

## Overview
Trilogy II is the "Mystic Cloud" visualization from the WMP visualization pack. It implements a cloud-like effect with flowing patterns and color gradients.

## Decompiled Files

- `TrilogyII_decompiled.c` - Full decompiled code with renamed functions
- `trilogy_state.h` - State structure definitions

## Key Functions

### Render Pipeline
- `Render_MainLoop` - Main render orchestrator (0x10001000)
- `Present_ToScreen` - GDI BitBlt to HDC (0x10001290)
- `Render_AllPresets` - Iterate all presets (0x10001600)

### Audio Processing
- `Audio_GetBass` - Get bass level (0x1000E6E0)
- `Audio_GetMid` - Get mid level (0x1000E760)
- `Audio_GetTreble` - Get treble level (0x1000E7F0)
- `Audio_Smooth` - Smooth audio data (0x1000E8C0)

### Coordinate Transforms
- `Motion_TexturedRender` - Textured rendering (0x100081E0)
- `Motion_Dissolve` - Dissolve/morph effect (0x10009670)
- `Geom_SphereWarp` - Spherical warp (0x100058C0)
- `Geom_CylinderWarp` - Cylindrical warp (0x100059B0)

### Effects
- `Effect_GaussianBlur` - Gaussian blur (0x10003120)
- `Effect_ColorCycle` - Color cycling (0x10003350)
- `Motion_ComplexPhysics` - Complex physics (0x10005F50)
- `Motion_MainUpdate` - Main motion update (0x10006FF0)

## Unique Features

Trilogy II includes additional geometry functions:
- `Geom_DrawLine3D` - 3D line drawing with perspective
- `Geom_DrawShape` - Shape drawing with fill
- `Geom_PolarTransform` - Polar coordinate transform

## State Structure

The main state structure is ~53KB and contains:
- COM interface vtables
- Rendering state (framebuffers, dimensions)
- Audio processing buffers
- Per-preset configuration (54 slots)
- Sin/cos lookup table (360 floats at offset 0xBC28)

## Audio Data Flow

```
WMP Audio Stream
  └─ TimedLevel structure
       ├─ frequency[2][1024] → offset 0xC810
       └─ waveform[2][1024] → offset 0xC814
            └─ Normalized to [0,1] via /255.0
                 └─ Stored per-vis at +0x15C + vis*0xE0
```
