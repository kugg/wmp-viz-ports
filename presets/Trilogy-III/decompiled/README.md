# Trilogy III - Undulation

## Overview
Trilogy III is the "Undulation" visualization from the WMP visualization pack. It implements a wave-like effect with undulating patterns and radial symmetry.

## Decompiled Files

- `TrilogyIII_decompiled.c` - Full decompiled code with renamed functions
- `trilogy_state.h` - State structure definitions

## Key Functions

### Render Pipeline
- `Render_MainLoop` - Main render orchestrator (0x10001000)
- `Present_ToScreen` - GDI BitBlt to HDC (0x10001290)
- `IWMPEffects_Render` - IWMPEffects::Render method (0x10001E50)

### Audio Processing
- `Audio_GetBass` - Get bass level (0x1000E6E0)
- `Audio_GetMid` - Get mid level (0x1000E760)
- `Audio_GetTreble` - Get treble level (0x1000E7F0)
- `UpdateSpectrumData` - Compute FFT-like spectrum (0x10015540)

### Coordinate Transforms
- `PerPixelTransformSetup` - Per-pixel transform setup (0x100081D0)
- `RenderPixels_Radial` - Radial pixel rendering (0x10009660)
- `EdgeDetectionScan` - Edge detection/contour extraction (0x10004B00)

### Effects
- `Effect_GaussianBlur` - Gaussian blur (0x10003120)
- `Effect_ColorCycle` - Color cycling (0x10003350)
- `PerPixelAlphaBlend` - Per-pixel alpha blend (0x10006FE0)
- `ScrollingPixelBuffer` - Pixel buffer scrolling/panning (0x1000C370)

## Unique Features

Trilogy III includes specialized rendering:
- `EdgeDetectionScan` - 4-directional edge detection
- `RenderPixels_Radial` - Radial distance-based rendering
- `BufferStretch` - Bilinear/pixel-doubled scaling

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
