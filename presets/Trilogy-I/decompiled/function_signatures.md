# Trilogy Function Signature Analysis

This document provides a detailed analysis of the function signatures in the Trilogy decompiled code, based on the Windows API calls they make and the parameters they use.

## Main State Structure

Based on the analysis of the decompiled code, the main state structure (`CTrilogyVisualizer`) is approximately 53KB and contains the following key fields:

```c
typedef struct {
    // COM Interface (offset 0x00)
    void** vtable;              // +0x00: Primary vtable pointer
    void** vtable2;             // +0x04: Secondary vtable pointer
    int ref_count;              // +0x08: Reference count
    
    // Thread Safety (offset 0x0C)
    CRITICAL_SECTION cs;        // +0x0C: Critical section (24 bytes on x86)
    
    // Window & Module (offset 0x24)
    int reserved1[4];           // +0x24: Reserved
    HWND hWnd;                  // +0x34: Window handle
    int reserved2;              // +0x38: Reserved
    HMODULE hModule;            // +0x3C: Library module handle
    
    // Viewport (offset 0x40)
    int reserved3[14];          // +0x40: Reserved
    int width;                  // +0x78: Viewport width (640)
    int height;                 // +0x7C: Viewport height (480)
    
    // Frame Counter (offset 0x80)
    int frame_count;            // +0x80: Frame counter
    int reserved4;              // +0x84: Reserved
    DWORD last_fps_time;        // +0x88: timeGetTime() for FPS
    float fps;                  // +0x8C: Calculated FPS
    
    // Audio State (offset 0x90)
    int reserved5;              // +0x90: Reserved
    void* vtable_wmpeffects;    // +0x94: IWMPEffects vtable
    int reserved6[2];           // +0x98: Reserved
    int reserved7[42];          // +0xA0: Reserved
    
    // Per-Effect State (offset 0x1A0)
    int effect_state[54 * 0x7B]; // +0x1A0: Per-effect state array
    
    // Sin Lookup Table (offset 0xBC28)
    float sin_lut[360];         // +0xBC28: Sin lookup table (360 entries)
    
    // Spectrum Buffers (offset 0x9BA8)
    float spectrum_a[520];      // +0x9BA8: Spectrum buffer A
    float spectrum_b[520];      // +0xA3C8: Spectrum buffer B
    float spectrum_c[520];      // +0xABE8: Spectrum buffer C
    
    // Audio Processing (offset 0xB408)
    int reserved8[342];         // +0xB408: Reserved
    int reserved9[1240];        // +0xBC28: Reserved (overlap with sin_lut)
    int row_padding;            // +0xC7E8: Row alignment padding
    int reserved10;             // +0xC7EC: Reserved
    void* framebuffer_a;        // +0xC7F0: Framebuffer A
    int reserved11[6];          // +0xC7F4: Reserved
    void* audio_buffer;         // +0xC810: Audio data pointer
    void* waveform_buffer;      // +0xC814: Waveform data pointer
    int reserved12[2];          // +0xC818: Reserved
    int audio_ready;            // +0xC820: Audio ready flag
    int reserved13[2];          // +0xC824: Reserved
    int audio_format;           // +0xC82C: Audio format code
    int reserved14;             // +0xC830: Reserved
    float half_width;           // +0xC834: Half-width for centering
    int reserved15[16];         // +0xC838: Reserved
    int hash_value;             // +0xC878: Change detection hash
    int reserved16[2];          // +0xC87C: Reserved
    int spectrum_idx;           // +0xC884: Spectrum history index
    int reserved17;             // +0xC888: Reserved
    int default_bg;             // +0xC88C: Default background color
    int fb_rows;                // +0xC890: Framebuffer row count
    int fb_cols;                // +0xC894: Framebuffer column count
    int fb_stride;              // +0xC898: Framebuffer stride
    int reserved18[2];          // +0xC89C: Reserved
    int target_bpp;             // +0xC8A4: Target BPP for conversion
    int reserved19[22];         // +0xC8A8: Reserved
    int active_vis_idx;         // +0xC900: Currently processing vis index
    int reserved20[8];          // +0xC904: Reserved
    int wave_blend;             // +0xC924: Wave blend value
    int audio_level;            // +0xC928: Master audio level (0-100)
    int reserved21[3];          // +0xC92C: Reserved
    float motion_speed;         // +0xC938: Motion speed
    float motion_phase;         // +0xC93C: Motion phase
    int reserved22[4];          // +0xC940: Reserved
    float motion_delta;         // +0xC950: Motion delta per step
    int reserved23;             // +0xC954: Reserved
    float scroll_offset_y;      // +0xC958: Scroll offset Y
    int reserved24[34];         // +0xC95C: Reserved
    int initialized;            // +0xC9E4: System initialized flag
    float freq_low;             // +0xC9E8: Low frequency component
    float freq_high;            // +0xC9EC: High frequency component
    int reserved25[32];         // +0xC9F0: Reserved
    float motion_magnitude;     // +0xCA74: Motion magnitude
    int resize_flag;            // +0xCA78: Resize detected flag
    int reserved26[2];          // +0xCA7C: Reserved
    int max_vis;                // +0xCA84: Max vis slots (0x37 = 55)
    int reserved27[28];         // +0xCA88: Reserved
    int transparent_color;      // +0xCF70: Transparent/background color
    
    // Framebuffer Management (offset 0xCF74)
    int reserved28[33];         // +0xCF74: Reserved
    int vis_count;              // +0xD038: Number of active visualizations
    int reserved29;             // +0xD03C: Reserved
    int pixel_count;            // +0xD040: Width × height
    
    // Per-Preset Configuration (offset 0xD044)
    // Each preset is 0x1EC bytes
    PresetConfig presets[54];   // +0xD044: Per-preset configuration
    
    // Framebuffer Pointers (offset 0x31FC)
    void* frame_buffer;         // +0x31FC: Active pixel buffer (BGRA)
    int reserved30;             // +0x3200: Reserved
    void* dest_buffer;          // +0x3204: Destination buffer pointer
    BITMAPINFO* bmp_info;       // +0x3208: BITMAPINFO pointer
    int reserved31;             // +0x320C: Reserved
    void* pixel_data;           // +0x3210: Pixel data start
    int reserved32[4];          // +0x3214: Reserved
    short buf_height;           // +0x3224: Current buffer height
    short buf_width;            // +0x3226: Current buffer width
    int row_stride;             // +0x3228: Row stride in bytes
    char color_depth;           // +0x322C: Bits per pixel (8/16/24/32)
    char clear_color;           // +0x322D: Background clear color
    short reserved32b;          // +0x322E: Reserved
    int reserved33;             // +0x3230: Reserved
    int center_x;               // +0x3234: Center X (width/2)
    int center_y;               // +0x3238: Center Y (height/2)
    int reserved34;             // +0x323C: Reserved
    int current_preset;         // +0x3240: Current preset index
    int reserved35[18];         // +0x3244: Reserved
    int reserved36[2];          // +0x328C: Reserved
    int last_width;             // +0x3294: Last presented width
    int last_height;            // +0x3298: Last presented height
    void* last_buffer;          // +0x329C: Last presented buffer ptr
    int reserved37;             // +0x32A0: Reserved
    int main_buffer;            // +0x32A4: Primary pixel buffer
    void* work_buffer;          // +0x32A8: Working/temp pixel buffer
    void* alloc_buffer;         // +0x32AC: Allocated buffer (staging)
    void* resource_data;        // +0x32B0: Resource/data pointer
    void* palette_buf;          // +0x32B4: Palette buffer
    void* palette_buf2;         // +0x32B8: Secondary palette buffer
    int stretch_w;              // +0x32BC: Stretch target width
    int stretch_h;              // +0x32C0: Stretch target height
    int reserved38[22];         // +0x32C4: Reserved
    int blit_x;                 // +0x331C: Blit destination X
    int blit_y;                 // +0x3320: Blit destination Y
    int reserved39[53];         // +0x3324: Reserved
    int bg_color;               // +0x33DC: Background fill color
    int reserved40[8];          // +0x33E0: Reserved
    int target_width;           // +0x3400: Target output width
} CTrilogyVisualizer;
```

## Per-Preset Configuration Structure

Each preset configuration is 0x1EC bytes:

```c
typedef struct {
    int preset_id;              // +0x00: Preset ID (-1 = inactive)
    int reserved1[8];           // +0x04: Reserved
    void* texture_data;         // +0x24: Texture/image data pointer
    int reserved2[23];          // +0x28: Reserved
    int blend_mode;             // +0x84: Blend mode (0=none, 1=alpha, 2=additive)
    void* alpha_texture;        // +0x88: Alpha texture pointer
    void* mask_texture;         // +0x8C: Mask texture pointer
    int reserved3[12];          // +0x90: Reserved
    float rotation;             // +0xC4: Rotation angle (degrees)
    int reserved4;              // +0xC8: Reserved
    float speed_x;              // +0xCC: Movement speed X
    float offset_x;             // +0xD0: X offset
    float offset_y;             // +0xD4: Y offset
    int reserved5[41];          // +0xD8: Reserved
    int complexity;             // +0x180: Complexity parameter
    float audio_reactivity;     // +0x184: Audio reactivity amount
    int reserved6[26];          // +0x188: Reserved
} PresetConfig;
```

## Function Signatures by Category

### DllMain / Entry Points

```c
// DllMain - DLL entry point
// Parameters:
//   param_1: HMODULE - Module handle
//   param_2: int - Reason for call (1=DLL_PROCESS_ATTACH, 0=DLL_PROCESS_DETACH)
// Returns: int (1=success, 0=failure)
int DllMain(HMODULE param_1, int param_2);

// ClassFactory_CreateInstance - Creates a new instance of the visualizer
// Parameters:
//   param_1: undefined4 - IUnknown pointer
//   param_2: undefined4 - REFIID
//   param_3: undefined4 - PPV (pointer to pointer)
// Returns: HRESULT (0=success, negative=error)
int ClassFactory_CreateInstance(undefined4 param_1, undefined4 param_2, undefined4 param_3);

// IUnknown_QueryInterface - Queries for an interface
// Parameters:
//   param_1: int* - this pointer
//   param_2: int* - REFIID
//   param_3: undefined4* - PPV (pointer to pointer)
// Returns: HRESULT (0=success, negative=error)
int IUnknown_QueryInterface(int* param_1, int* param_2, undefined4* param_3);
```

### Render Pipeline

```c
// Render_MainLoop - Main render orchestrator
// Parameters:
//   param_1: int* - this pointer (CTrilogyVisualizer)
// Returns: undefined4 (always 0)
undefined4 Render_MainLoop(int* param_1);

// Present_ToScreen - GDI BitBlt to HDC
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Present_ToScreen(int* param_1);

// Update_FPSCounter - FPS calculation
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Update_FPSCounter(int* param_1);

// Render_AllPresets - Iterate all presets
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Render_AllPresets(int* param_1);
```

### Audio Processing

```c
// Audio_GetBass - Get bass level (initializes audio buffer)
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Audio_GetBass(int param_1);

// Audio_GetMid - Get mid level (initializes audio buffer)
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Audio_GetMid(int param_1);

// Audio_GetTreble - Get treble level (processes audio data)
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (0=success, 1=failure)
undefined4 Audio_GetTreble(int* param_1);

// Audio_Smooth - Smooth audio data
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Audio_Smooth(int* param_1);

// Audio_Decay - Decay audio levels
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Audio_Decay(int* param_1);

// Audio_CopyTimedLevel - Copy timed level data
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Audio_CopyTimedLevel(int* param_1);
```

### Effects

```c
// Effect_GaussianBlur - Gaussian blur effect
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_GaussianBlur(int param_1);

// Effect_ColorCycle - Color cycling effect
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_ColorCycle(int* param_1);

// Effect_Rotate - Rotation effect
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Rotate(int param_1);

// Effect_Zoom - Zoom effect
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Zoom(int param_1);

// Effect_Invert - Invert colors effect
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Invert(int param_1);

// Effect_Grayscale - Grayscale effect
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Grayscale(int param_1);

// Effect_Brightness - Brightness adjustment
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Brightness(int param_1);

// Effect_Contrast - Contrast adjustment
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Contrast(int param_1);

// Effect_Saturation - Saturation adjustment
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Saturation(int param_1);

// Effect_Hue - Hue adjustment
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Hue(int param_1);

// Effect_Gamma - Gamma correction
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Effect_Gamma(int param_1);
```

### Coordinate Transforms

```c
// Transform_Motion - Motion transform
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Transform_Motion(int* param_1);

// Transform_Scale - Zoom scale transform
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Transform_Scale(int param_1);

// Transform_RotatePolar - Polar rotation transform
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Transform_RotatePolar(int param_1);

// Transform_PresetCoords - Per-pixel coordinate calculation
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Transform_PresetCoords(int* param_1);

// Transform_PolarCoords - Polar coordinate transform
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Transform_PolarCoords(int* param_1);
```

### Pixel Operations

```c
// PixelBlit_SimpleCopy - Simple pixel copy with transparency
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 PixelBlit_SimpleCopy(int* param_1);

// PixelBlit_AlphaBlend - Per-pixel alpha blending
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 PixelBlit_AlphaBlend(int* param_1);
```

### Blending

```c
// Blend_AlphaComposite - Alpha compositing
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_AlphaComposite(int param_1);

// Blend_Screen - Screen blend mode
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_Screen(int param_1);

// Blend_Overlay - Overlay blend mode
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_Overlay(int* param_1);

// Blend_Multiply - Multiply blend mode
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_Multiply(int* param_1);

// Blend_SoftLight - Soft light blend mode
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_SoftLight(int param_1);

// Blend_WithOverlay - Blend with overlay texture
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_WithOverlay(int param_1);

// Blend_WithTransform - Blend with transform
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_WithTransform(int param_1);

// Blend_CopySecondary - Copy secondary buffer
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_CopySecondary(int param_1);

// Blend_CopyBack - Copy back buffer
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Blend_CopyBack(int param_1);
```

### Window Management

```c
// InitWindowState - Initialize window state
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 InitWindowState(int param_1);

// Cleanup_WindowState - Cleanup window state
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Cleanup_WindowState(int param_1);

// Wnd_Destroy - Destroy window
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Wnd_Destroy(int param_1);

// WndProc_Viz - Window procedure
// Parameters:
//   param_1: HWND - Window handle
//   param_2: UINT - Message
//   param_3: WPARAM - Message parameter
//   param_4: LPARAM - Message parameter
// Returns: LRESULT
LRESULT WndProc_Viz(HWND param_1, UINT param_2, WPARAM param_3, LPARAM param_4);
```

### State Management

```c
// State_Cleanup - Cleanup state
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 State_Cleanup(int param_1);

// State_FullReset - Full state reset
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 State_FullReset(int param_1);

// InitStateDefaults - Initialize state defaults
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 InitStateDefaults(int param_1);

// Init_RenderContext - Initialize render context
// Parameters:
//   param_1: int - this pointer
// Returns: undefined4 (always 0)
undefined4 Init_RenderContext(int param_1);
```

### Memory Management

```c
// _malloc - Allocate memory
// Parameters:
//   param_1: int - Size in bytes
// Returns: void* - Pointer to allocated memory
void* _malloc(int param_1);

// HeapFree_Wrapper - Free memory
// Parameters:
//   param_1: void* - Pointer to memory to free
// Returns: undefined4 (always 0)
undefined4 HeapFree_Wrapper(void* param_1);

// Mem_Alloc - Allocate memory (alternative)
// Parameters:
//   param_1: int - Size in bytes
// Returns: void* - Pointer to allocated memory
void* Mem_Alloc(int param_1);

// Mem_Free - Free memory (alternative)
// Parameters:
//   param_1: void* - Pointer to memory to free
// Returns: undefined4 (always 0)
undefined4 Mem_Free(void* param_1);
```

### String/Registry Utilities

```c
// Util_HexStringToColor - Parse #RRGGBB hex string to color integer
// Parameters:
//   param_1: LPCSTR - Hex string
// Returns: int - Color value (0x00RRGGBB)
int Util_HexStringToColor(LPCSTR param_1);

// Util_ColorToHexString - Convert color integer to hex string
// Parameters:
//   param_1: int - Color value
//   param_2: LPSTR - Output buffer
//   param_3: int - Buffer size
// Returns: int - 0 on success
int Util_ColorToHexString(int param_1, LPSTR param_2, int param_3);

// Util_ParseConfig - Parse config tokens
// Parameters:
//   param_1: int* - Parser state
//   param_2: LPSTR - Output token
//   param_3: int - Max token size
// Returns: int - 1=more tokens, 0=done, -1=error
int Util_ParseConfig(int* param_1, LPSTR param_2, int param_3);

// Util_ConfigSection - Look up config section by name
// Parameters:
//   param_1: LPCSTR - Section name
//   param_2: int* - Config data
// Returns: int - 1=found, 0=not found
int Util_ConfigSection(LPCSTR param_1, int* param_2);

// Util_RegistryParse - Full config file parser
// Parameters:
//   param_1: LPCSTR - Config file path
//   param_2: int* - Output data
// Returns: int - 0 on success
int Util_RegistryParse(LPCSTR param_1, int* param_2);

// RegFileParser - Registry file parser
// Parameters:
//   param_1: LPCSTR - Registry file path
//   param_2: int* - Output data
// Returns: int - 0 on success
int RegFileParser(LPCSTR param_1, int* param_2);

// ExpandVariables - Expand %variable% in strings
// Parameters:
//   param_1: LPCSTR - Input string with variables
//   param_2: LPSTR - Output buffer
//   param_3: int - Buffer size
// Returns: int - Length of expanded string
int ExpandVariables(LPCSTR param_1, LPSTR param_2, int param_3);
```

### COM Object Creation

```c
// Get_SingletonObject - Get or create singleton object
// Parameters:
//   param_1: int* - Object type
// Returns: int* - Object pointer
int* Get_SingletonObject(int* param_1);

// Create_VisObject2 - Create visualization object
// Parameters:
//   param_1: int* - Object parameters
// Returns: int* - Object pointer
int* Create_VisObject2(int* param_1);

// Init_CriticalSection - Initialize critical section in object
// Parameters:
//   param_1: int* - this pointer
// Returns: undefined4 (always 0)
undefined4 Init_CriticalSection(int* param_1);

// QueryInterface_Table2 - Query interface using second vtable
// Parameters:
//   param_1: int* - this pointer
//   param_2: int* - REFIID
//   param_3: undefined4* - PPV
// Returns: HRESULT
int QueryInterface_Table2(int* param_1, int* param_2, undefined4* param_3);
```

## Common Parameter Patterns

### this Pointer (param_1)

Almost all functions take `param_1` as the first parameter, which is a pointer to the `CTrilogyVisualizer` state structure. This is typically declared as:
- `int* param_1` when the function accesses fields via array indexing
- `int param_1` when the function accesses fields via pointer arithmetic

### Return Values

Most functions return `undefined4` (which is `int` or `DWORD`), and the return value is almost always 0. The only exceptions are:
- `ClassFactory_CreateInstance` - Returns HRESULT (0=success, negative=error)
- `IUnknown_QueryInterface` - Returns HRESULT
- `Audio_GetTreble` - Returns 0 on success, 1 on failure
- Memory allocation functions - Return pointer or NULL

### Vtable Calls

Functions are called via vtable using patterns like:
```c
(**(code **)(*param_1 + 0x148))(param_1);  // Call function at vtable offset 0x148
(**(code **)(*param_1 + 0x104))(param_1);  // Call function at vtable offset 0x104
```

Common vtable offsets:
- `0x00`: QueryInterface
- `0x04`: AddRef
- `0x08`: Release
- `0x10`: Destroy
- `0x44`: Some render function
- `0x50`: Audio copy function
- `0xC8`: Some render function
- `0x104`: Some render function
- `0x138`: Transform function
- `0x140`: Rotation function
- `0x148`: Main render function
- `0x220`: Present function
- `0x230`: Blend function 1
- `0x234`: Blend function 2
- `0x254`: Alpha blend function
- `0x260`: Setup function

## Audio Data Flow

```c
// WMP passes TimedLevel structure to Render():
typedef struct {
    unsigned char frequency[2][1024]; // FFT spectrum data (L/R channels)
    unsigned char waveform[2][1024];  // Raw wave amplitude data
    int state;                        // Playback state
    hyper timeStamp;                  // Time stamp
} TimedLevel;

// Audio data is stored in the state structure:
// param_1 + 0xC810: pointer to frequency data
// param_1 + 0xC814: pointer to waveform data

// Audio levels are normalized to [0,1] by dividing by 255.0
// Bass/Mid/Treble are computed from spectrum buffers
```

## Render Pipeline Flow

```c
// 1. Render_MainLoop is called by WMP
// 2. Allocates frame buffer if needed (width * height * 4 bytes)
// 3. Calculates center coordinates (width/2, height/2)
// 4. Calls vtable+0x260 (setup function)
// 5. Calls vtable+0x50 (audio copy function)
// 6. If single preset mode (param_1[0x3309] != 0):
//    - Sets frame buffer pointer
//    - Calls vtable+0x148 (render single preset)
//    - Calls vtable+0xC8 (final composite)
// 7. If multi-preset mode:
//    - For each preset:
//      * Calls vtable+0x128 (prepare preset)
//      * Calls vtable+0x15C (render preset)
//      * Calls vtable+0xC8 (composite preset)
// 8. Present_ToScreen copies frame buffer to HDC via GDI
```
