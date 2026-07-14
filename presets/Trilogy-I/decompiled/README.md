# Trilogy I - Lava

## Overview
Trilogy I is the "Lava" visualization from the WMP visualization pack. It implements a lava lamp-like effect with organic flowing shapes.

## Decompiled Files

- `TrilogyI_decompiled.c` - Full decompiled code with renamed functions
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
- `Transform_PresetCoords` - Per-pixel coordinate calc (0x100081D0)
- `Transform_PolarCoords` - Polar coordinate transform (0x10009660)
- `Transform_Scale` - Zoom scale (0x100058B0)

### Effects
- `Effect_GaussianBlur` - Gaussian blur (0x10003120)
- `Effect_ColorCycle` - Color cycling (0x10003350)
- `PerPixelColorBlend` - Per-pixel alpha blend (0x10006FE0)

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

## Rendering Pipeline

```
Frame N:
1. Render_MainLoop (0x10001000)
   ├─ Allocate frame buffer if needed
   ├─ Calculate center (width/2, height/2)
   ├─ Call vtable+0x260 (setup)
   ├─ Call vtable+0x50 (audio copy)
   ├─ If single preset mode:
   │   └─ Call vtable+0x148 (render single)
   └─ If multi-preset mode:
       ├─ For each preset:
       │   ├─ Call vtable+0x128 (prepare)
       │   ├─ Call vtable+0x15c (render)
       │   └─ Call vtable+0xC8 (composite)
       └─ Call vtable+0x3C (final composite)
2. Present_ToScreen (0x10001290)
   ├─ CreateDIBitmap from frame buffer
   ├─ BitBlt or StretchDIBits to HDC
   └─ Call vtable+0x220 (post-present)
```
