# Trilogy I - Lava

## Overview
Trilogy I is the "Lava" visualization from the WMP visualization pack. It implements a lava lamp-like effect with organic flowing shapes.

## Decompilation Status

- **Named Functions:** 213 / 342 (62%)
- **Remaining FUN_ References:** 758 (mostly CRT/runtime and internal helpers)

## Decompiled Files

- `TrilogyI_decompiled.c` - Full decompiled code with renamed functions
- `trilogy_state.h` - State structure definitions
- `windows_api_reference.md` - Windows API function signatures
- `function_signatures.md` - Function signature analysis

## Key Functions

### DLL Entry Points
- `DllMain` - DLL entry point (0x10010890)
- `DllCanUnloadNow` - Check if DLL can be unloaded (0x10010A90)
- `DllGetClassObject` - Get class factory (0x10010AA0)
- `DllRegisterServer` - Register COM server (0x10010B90)
- `DllUnregisterServer` - Unregister COM server (0x10010C20)

### COM Class Factory
- `ClassFactory_CreateInstance` - Create visualizer instance (0x10010CB0)
- `IUnknown_QueryInterface` - Query for interface (0x10010E90)
- `IUnknown_AddRef` - Increment reference count (0x10010DC0)
- `IUnknown_Release` - Decrement reference count (0x10010E00)

### Render Pipeline
- `Render_MainLoop` - Main render orchestrator (0x10001000)
- `Present_ToScreen` - GDI BitBlt to HDC (0x10001290)
- `Update_FPSCounter` - FPS calculation (0x10001590)
- `Render_AllPresets` - Iterate all presets (0x10001600)
- `Render_PresetLoop` - Per-preset render loop (0x10016BB0)
- `Render_PresetSetup` - Per-preset render setup (0x10016C80)
- `Render_SwapFrameBuffers` - Swap frame buffers (0x10016D10)
- `Render_ComplexScene` - Complex scene rendering (0x1000DB00)
- `Render_Particles` - Particle rendering (0x1000DC90)
- `Render_MipmapChain` - Mipmap chain rendering (0x1000DF40)

### Audio Processing
- `Audio_GetBass` - Get bass level (0x1000E6E0)
- `Audio_GetMid` - Get mid level (0x1000E760)
- `Audio_GetTreble` - Get treble level (0x1000E7F0)
- `Audio_Smooth` - Smooth audio data (0x1000E8C0)
- `Audio_Decay` - Decay audio levels (0x1000E960)
- `Audio_CopyTimedLevel` - Copy timed level data (0x1000EA60)
- `Audio_Decimate` - Decimate audio data (0x1000EBF0)
- `Audio_InitStream` - Initialize audio stream (0x1000ED00)
- `Audio_RotateSpectrumBuffers` - Rotate spectrum buffers (0x100151D0)
- `Audio_RandomSelect` - Random audio selection (0x10017D40)

### Texture Generation
- `Effect_GenerateTexture` - Generate texture (0x10002F60)

### Effects
- `Effect_Convolution` - Convolution filter (0x100030B0)
- `Effect_GaussianBlur` - Gaussian blur (0x10003120)
- `Effect_ColorCycle` - Color cycling (0x10003350)
- `Effect_Rotate` - Rotation effect (0x100034B0)
- `Effect_Zoom` - Zoom effect (0x100036D0)
- `Effect_Swirl` - Swirl effect (0x10003790)
- `Effect_Water` - Water effect (0x10003800)
- `Effect_Ripple` - Ripple effect (0x100038E0)
- `Effect_Fade` - Fade effect (0x10003970)
- `Effect_Blur` - Blur effect (0x1000B680)
- `Effect_Shadow` - Shadow effect (0x1000B8F0)
- `Effect_MotionBlur` - Motion blur (0x1000BDF0)
- `Effect_Invert` - Invert colors (0x1000D3E0)
- `Effect_Grayscale` - Grayscale effect (0x1000D460)
- `Effect_Brightness` - Brightness adjustment (0x1000D4F0)
- `Effect_Contrast` - Contrast adjustment (0x1000D760)
- `Effect_Saturation` - Saturation adjustment (0x1000D7A0)
- `Effect_Hue` - Hue adjustment (0x1000D7E0)
- `Effect_Gamma` - Gamma correction (0x1000D830)
- `Effect_ColorBalance` - Color balance (0x1000D8C0)
- `Effect_ColorLookup` - Color lookup table (0x1000D960)
- `Effect_ChannelMix` - Channel mixing (0x1000DA20)
- `Effect_RunPipeline` - Run effect pipeline (0x10014F80)

### Coordinate Transforms
- `Transform_PresetCoords` - Per-pixel coordinate calc (0x100081D0)
- `Transform_PolarCoords` - Polar coordinate transform (0x10009660)
- `Transform_Scale` - Zoom scale (0x100058B0)
- `Transform_RotatePolar` - Polar rotation (0x100059A0)
- `Transform_RotateFast` - Fast rotation (0x10005AA0)
- `Transform_Motion` - Motion transform (0x100047D0)
- `Transform_Wrap` - Wrap coordinates (0x10004920)
- `Transform_WithAudio` - Audio-driven transform (0x10004B00)
- `Transform_PixelOffset` - Pixel offset (0x10003B20)
- `Transform_Configure` - Configure transform (0x100040D0)

### Motion Physics
- `Motion_ComplexPhysics` - Complex physics (0x10005F40)
- `Motion_UpdateAll` - Update all motion (0x10014680)
- `Motion_CalcPresetXY` - Calculate preset XY motion (0x100162D0)
- `Motion_CalcPresetX` - Calculate preset X motion (0x100165B0)
- `Motion_CalcPresetXY2` - Calculate preset XY motion variant (0x100166A0)
- `Motion_CalcPresetXYZ` - Calculate preset XYZ motion (0x100169F0)

### Pixel Operations
- `PixelBlit_SimpleCopy` - Simple pixel copy (0x10005040)
- `PixelBlit_AlphaBlend` - Alpha blending (0x10005300)
- `PerPixelColorBlend` - Per-pixel color blend (0x10006FE0)

### Blending Modes
- `Blend_AlphaComposite` - Alpha compositing (0x1000A480)
- `Blend_LayerMerge` - Layer merging (0x1000ABF0)
- `Blend_Additive` - Additive blending (0x1000B010)
- `Blend_WithOverlay` - Overlay blending (0x1000C930)
- `Blend_WithTransform` - Transform blending (0x1000CB50)
- `Blend_CopySecondary` - Copy secondary buffer (0x1000CE30)
- `Blend_CopyBack` - Copy back buffer (0x1000CF50)
- `Blend_Screen` - Screen blend mode (0x1000D010)
- `Blend_Multiply` - Multiply blend mode (0x1000D1F0)
- `Blend_Overlay` - Overlay blend mode (0x1000D2B0)
- `Blend_SoftLight` - Soft light blend mode (0x1000D370)

### Preset Management
- `Convert_BufferFormat` - Convert buffer format (0x10001970)
- `Preset_LoadConfig` - Load preset configuration (0x100019F0)
- `Calc_RowPadding` - Calculate row padding (0x10001CE0)
- `Release_PresetData` - Release preset data (0x10001E40)
- `IWMPEffects_Render` - WMP render callback (0x10001E50)
- `IWMPEffects_MediaInfo` - WMP media info callback (0x10001EE0)
- `IWMPEffects_SetUserPreset` - Set user preset (0x10001F40)
- `IterateSubVisualizations` - Iterate sub-visualizations (0x10001FA0)
- `Blend_PresetFrames` - Blend preset frames (0x100020C0)
- `Blend_AudioFrames` - Blend audio frames (0x100021D0)
- `IterateActivePresets` - Iterate active presets (0x10014860)
- `Preset_FillBuffer` - Fill preset buffer (0x10017A10)

### Waveform Data Copy
- `Waveform_CopyMultiBPP` - Copy waveform multi-BPP (0x100171A0)
- `Waveform_Copy4BPP` - Copy waveform 4BPP (0x10017300)
- `Waveform_CopyWithScroll` - Copy with scroll (0x10017400)
- `Waveform_CopyAndFill` - Copy and fill (0x10017510)
- `Waveform_CopyWithMirror` - Copy with mirror (0x10017610)
- `Waveform_CopyWithWrap` - Copy with wrap (0x10017730)
- `Waveform_MirrorCopy` - Mirror copy (0x10017840)
- `Waveform_CopyToDisplay` - Copy to display (0x10017F40)

### Window Management
- `InitWindowState` - Initialize window state (0x1000EE60)
- `Cleanup_WindowState` - Cleanup window state (0x1000EEC0)
- `Command_Exit` - Exit command (0x1000EED0)
- `Wnd_Destroy` - Destroy window (0x1000EEE0)
- `Misc_HideCursor` - Hide cursor (0x1000F3D0)
- `WndProc_Viz` - Window procedure (0x1000F3E0)
- `PostCloseMessage` - Post close message (0x1000F460)
- `DestroyVizWindow` - Destroy viz window (0x1000F480)
- `CleanupVizInstance` - Cleanup viz instance (0x1000F4F0)

### State Management
- `State_Cleanup` - Cleanup state (0x1000F500)
- `FreeVisTextures` - Free visualization textures (0x1000F730)
- `FreeAllBuffers` - Free all buffers (0x1000F880)
- `State_FullReset` - Full state reset (0x1000F890)
- `InitStateDefaults` - Initialize state defaults (0x1000F9E0)
- `State_SetDefaults` - Set state defaults (0x10014E70)
- `State_ResetAudio` - Reset audio state (0x10015350)
- `State_ResetAll` - Reset all state (0x10015540)
- `State_InitParams` - Initialize state parameters (0x10015CC0)

### Initialization
- `InitAllVisParams` - Initialize all visualization parameters (0x10015630)
- `UpdateSpectrumData` - Update spectrum data (0x10015550)
- `Init_GDIContext` - Initialize GDI context (0x100103E0)
- `Load_DisplayName` - Load display name (0x10010470)
- `Init_RenderContext` - Initialize render context (0x1000FAD0)
- `Texture_InitRender` - Initialize texture rendering (0x1000FAE0)

### Registry/File Utilities
- `ParseHexDWord` - Parse hex DWORD (0x10010700)
- `FormatHexDWord` - Format hex DWORD (0x100107F0)
- `BuildRegScript` - Build registry script (0x10011A80)
- `StringBuffer_Append` - Append to string buffer (0x10011D50)
- `ExecuteRegScript` - Execute registry script (0x10011F20)
- `IsEscape` - Check if escape character (0x10012240)
- `IsDelimiter` - Check if delimiter (0x100122A0)
- `SkipWhitespace` - Skip whitespace (0x100122F0)
- `ParseToken` - Parse token (0x10012340)
- `ExpandVariables` - Expand variables (0x100124A0)
- `RegFileParser` - Registry file parser (0x10012850)
- `RegWriteValue` - Write registry value (0x10013540)
- `Reg_QueryKeyInfo` - Query registry key info (0x100139A0)
- `Reg_ParseConfigValue` - Parse config value (0x10013A50)
- `Reg_RegisterTypeLib` - Register type library (0x10013BD0)
- `Reg_UnregisterServer` - Unregister server (0x10013D00)
- `Reg_RegisterServer` - Register server (0x10013F70)
- `Str_FindFileNameW` - Find file name in wide string (0x10014170)

### COM Object Creation
- `Get_SingletonObject` - Get singleton object (0x10011170)
- `Create_VisObject2` - Create visualization object (0x10011340)
- `Init_CriticalSection` - Initialize critical section (0x10011470)
- `QueryInterface_Table2` - Query interface table 2 (0x100114E0)
- `IUnknown_AddRef2` - AddRef table 2 (0x10011570)
- `IUnknown_Release2` - Release table 2 (0x100115F0)
- `Destructor_VisObject2` - Destructor table 2 (0x10011620)
- `QueryInterface_Main` - Main QueryInterface (0x10011690)
- `ScalarDeletingDestructor_Main` - Scalar deleting destructor (0x10011930)
- `Destructor_Main` - Main destructor (0x10011960)
- `ScalarDeletingDestructor_Main2` - Scalar deleting destructor 2 (0x100119F0)

### Memory Management
- `Mem_Free` - Free memory (0x10019B16)
- `_malloc` - Allocate memory (0x10019B5E)
- `__nh_malloc` - No-throw malloc (0x10019B70)
- `Mem_FreeObj` - Free object memory (0x10019BEA)
- `__ftol` - Float to long conversion (0x10019D3C)
- `HeapFree_Wrapper` - HeapFree wrapper (0x10019D96)
- `malloc_wrap` - Malloc wrapper (0x10019DDE)
- `HeapAlloc_Wrapper` - HeapAlloc wrapper (0x10019E1C)
- `free_wrap` - Free wrapper (0x10019E6A)
- `ftol` - Float to long (0x10019FBC)
- `operator_new` - Operator new (0x1001A288)
- `Mem_Alloc` - Allocate memory (0x1001A420)

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
