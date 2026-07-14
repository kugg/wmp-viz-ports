# Trilogy DLL Function Address Mapping

This document maps equivalent functions across the three Trilogy DLL builds.
Functions at different addresses may be the same code with different offsets.

## Common Functions (Same Address)

| Address | Function Name | Purpose |
|---------|---------------|---------|
| `10001000` | `Render_MainLoop` | Main render orchestrator |
| `10001290` | `Present_ToScreen` | GDI BitBlt to HDC |
| `10001590` | `Update_FPSCounter` | FPS calculation |
| `10001600` | `Render_AllPresets` | Iterate all presets |
| `10001970` | `Convert_BufferFormat` | Format conversion |
| `10003120` | `Effect_GaussianBlur` | Gaussian blur |
| `10003350` | `Effect_ColorCycle` | Color cycling |
| `10005040` | `PixelBlit_SimpleCopy` | Simple pixel copy |
| `10005300` | `PixelBlit_AlphaBlend` | Alpha blending |
| `1000ee60` | `InitWindowState` | Window init |
| `1000f3e0` | `WndProc_Viz` | Window procedure |
| `10010890` | `DllMain` | Library entry |
| `10010a90` | `DllCanUnloadNow` | COM ref check |
| `10010aa0` | `DllGetClassObject` | COM class factory |
| `10010b90` | `DllRegisterServer` | COM registration |
| `10010c20` | `DllUnregisterServer` | COM unregistration |
| `10010cb0` | `ClassFactory_CreateInstance` | Create COM object |
| `10010dc0` | `IUnknown_AddRef` | Increment ref count |
| `10010e00` | `IUnknown_Release` | Decrement ref count |
| `10010e60` | `IUnknown_Destructor` | Destructor |
| `10010e90` | `IUnknown_QueryInterface` | Interface lookup |

## TrilogyI-Specific Functions

| Address | Function Name | Purpose |
|---------|---------------|---------|
| `100047d0` | `Transform_Motion` | Motion transform |
| `10004b00` | `Transform_WithAudio` | Audio-reactive transform |
| `100058b0` | `Transform_Scale` | Zoom scale |
| `100059a0` | `Transform_RotatePolar` | Polar rotation |
| `10005aa0` | `Transform_RotateFast` | Fast rotation |
| `10005e70` | `Convolution_Apply` | Convolution filter |
| `10005f40` | `Motion_ComplexPhysics` | Complex physics |
| `10006fe0` | `PerPixelColorBlend` | Per-pixel alpha blend |
| `100081d0` | `Transform_PresetCoords` | Per-pixel coord calc |
| `1000a480` | `Blend_AlphaComposite` | Alpha compositing |

## TrilogyII-Specific Functions

| Address | Function Name | Purpose |
|---------|---------------|---------|
| `100047e0` | `Transform_Motion` | Motion transform |
| `10004930` | `Draw_FillRect` | Rectangle fill |
| `10004b10` | `Geom_DrawLine3D` | 3D line drawing |
| `100058c0` | `Geom_SphereWarp` | Spherical warp |
| `100059b0` | `Geom_CylinderWarp` | Cylindrical warp |
| `10005ab0` | `Transform_RotateFast` | Fast rotation |
| `10005e80` | `Convolution_Apply` | Convolution filter |
| `10005f50` | `Motion_ComplexPhysics` | Complex physics |
| `10006ff0` | `Motion_MainUpdate` | Main motion update |
| `100081e0` | `Motion_TexturedRender` | Textured rendering |

## TrilogyIII-Specific Functions

| Address | Function Name | Purpose |
|---------|---------------|---------|
| `10004b00` | `EdgeDetectionScan` | Edge detection |
| `10005f40` | `SetupMovementParams` | Movement setup |
| `10006fe0` | `PerPixelAlphaBlend` | Per-pixel alpha blend |
| `100081d0` | `PerPixelTransformSetup` | Per-pixel transform |
| `10009660` | `RenderPixels_Radial` | Radial pixel render |

## State Structure Offsets (Common)

| Offset | Size | Purpose |
|--------|------|---------|
| `0x00` | 4 | Primary vtable |
| `0x04` | 4 | Secondary vtable / ref count |
| `0x14` | 4 | HWND |
| `0x40` | 4 | HMODULE |
| `0x78` | 4 | Width (default 640) |
| `0x7C` | 4 | Height (default 480) |
| `0x80` | 4 | Frame counter |
| `0x8C` | 4 | FPS |
| `0x94` | 4 | IWMPEffects vtable |
| `0xBC28` | 1440 | Sin LUT (360 × 4 bytes) |
| `0x9BA8` | 2080 | Spectrum buffer A |
| `0xA3C8` | 2080 | Spectrum buffer B |
| `0xABE8` | 2080 | Spectrum buffer C |
| `0xC810` | 4 | Audio data pointer |
| `0xC814` | 4 | Waveform data pointer |
| `0xC900` | 4 | Active audio channel |
| `0xD038` | 4 | Max preset index |
| `0x31FC` | 4 | Frame buffer pointer |
| `0x3224` | 2 | Buffer height |
| `0x3225` | 2 | Buffer width |
| `0x3226` | 4 | Row stride |
| `0x3229` | 1 | Color depth |
| `0x3234` | 4 | Center X |
| `0x3236` | 4 | Center Y |
| `0x3240` | 4 | Current preset index |
| `0x33DC` | 4 | Transparent color |
