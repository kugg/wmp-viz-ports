/**
 * Trilogy WMP Visualizer State Structure Definitions
 * 
 * This header defines the state structure used by all three Trilogy visualization
 * DLLs (I, II, III). The structure is approximately 53KB and contains:
 * - COM interface vtables
 * - Rendering state (framebuffers, dimensions, etc.)
 * - Audio processing buffers
 * - Per-preset configuration
 * - Sin/cos lookup tables
 */

#ifndef TRILOGY_STATE_H
#define TRILOGY_STATE_H

#include <windows.h>

// Forward declarations
typedef struct _TRILOGY_STATE TRILOGY_STATE;
typedef struct _TRILOGY_PRESET TRILOGY_PRESET;
typedef struct _TRILOGY_AUDIO TRILOGY_AUDIO;

// Constants
#define TRILOGY_MAX_PRESETS     54
#define TRILOGY_SIN_LUT_SIZE    360
#define TRILOGY_SPECTRUM_SIZE   520
#define TRILOGY_DEFAULT_WIDTH   640
#define TRILOGY_DEFAULT_HEIGHT  480

// Per-preset state structure (stride 0x1EC)
#pragma pack(push, 1)
struct _TRILOGY_PRESET {
    /* +0x00 */ int     preset_id;          // -1 = inactive
    /* +0x04 */ int     reserved1[8];
    /* +0x24 */ void*   texture_data;       // Texture/image data pointer
    /* +0x28 */ int     reserved2[23];
    /* +0x84 */ int     blend_mode;         // 0=none, 1=alpha, 2=additive
    /* +0x88 */ void*   alpha_texture;      // Alpha texture pointer
    /* +0x8C */ void*   mask_texture;       // Mask texture pointer
    /* +0x90 */ int     reserved3[12];
    /* +0xC4 */ float   rotation;           // Rotation angle (degrees)
    /* +0xC8 */ int     reserved4;
    /* +0xCC */ float   speed_x;            // Movement speed X
    /* +0xD0 */ float   offset_x;           // X offset
    /* +0xD4 */ float   offset_y;           // Y offset
    /* +0xD8 */ int     reserved5[41];
    /* +0x180 */ int    complexity;         // Complexity parameter
    /* +0x184 */ float  audio_reactivity;   // Audio reactivity amount
    /* +0x188 */ int    reserved6[26];
};
#pragma pack(pop)

// Main state structure (~53KB)
#pragma pack(push, 1)
struct _TRILOGY_STATE {
    /* +0x00 */ void*   vtable;             // Primary vtable pointer
    /* +0x04 */ void*   vtable2;            // Secondary vtable pointer
    /* +0x08 */ int     ref_count;          // Reference count
    /* +0x0C */ CRITICAL_SECTION cs;        // Critical section (24 bytes on x86)
    /* +0x24 */ int     reserved1[4];
    /* +0x34 */ HWND    hWnd;               // Window handle
    /* +0x38 */ int     reserved2[1];
    /* +0x3C */ HMODULE hModule;            // Library module handle
    /* +0x40 */ int     reserved3[14];
    /* +0x78 */ int     width;              // Viewport width (default 640)
    /* +0x7C */ int     height;             // Viewport height (default 480)
    /* +0x80 */ int     frame_count;        // Frame counter
    /* +0x84 */ int     reserved4;
    /* +0x88 */ DWORD   last_fps_time;      // timeGetTime() for FPS
    /* +0x8C */ float   fps;                // Calculated FPS
    /* +0x90 */ int     reserved5;
    /* +0x94 */ void*   vtable_wmpeffects;  // IWMPEffects vtable
    /* +0x98 */ int     reserved6[2];
    /* +0xA0 */ int     reserved7[42];
    
    // Per-effect state array (0x7B = 123 words each)
    /* +0x1A0 */ int     effect_state[TRILOGY_MAX_PRESETS * 0x7B];
    
    // Sin lookup table (360 floats)
    /* +0xBC28 */ float  sin_lut[TRILOGY_SIN_LUT_SIZE];
    
    // Spectrum buffers (520 floats each)
    /* +0x9BA8 */ float  spectrum_a[TRILOGY_SPECTRUM_SIZE];
    /* +0xA3C8 */ float  spectrum_b[TRILOGY_SPECTRUM_SIZE];
    /* +0xABE8 */ float  spectrum_c[TRILOGY_SPECTRUM_SIZE];
    
    // Audio state
    /* +0xB408 */ int    reserved8[342];
    /* +0xBC28 */ int    reserved9[1240];  // Overlap with sin_lut in actual struct
    /* +0xC7E8 */ int    row_padding;      // Row alignment padding
    /* +0xC7EC */ int    reserved10;
    /* +0xC7F0 */ void*  framebuffer_a;    // Framebuffer A
    /* +0xC7F4 */ int    reserved11[6];
    /* +0xC810 */ void*  audio_buffer;     // Audio data pointer
    /* +0xC814 */ void*  waveform_buffer;  // Waveform data pointer
    /* +0xC818 */ int    reserved12[2];
    /* +0xC820 */ int    audio_ready;      // Audio ready flag
    /* +0xC824 */ int    reserved13[2];
    /* +0xC82C */ int    audio_format;     // Audio format code
    /* +0xC830 */ int    reserved14;
    /* +0xC834 */ float  half_width;       // Half-width for centering
    /* +0xC838 */ int    reserved15[16];
    /* +0xC878 */ int    hash_value;       // Change detection hash
    /* +0xC87C */ int    reserved16[2];
    /* +0xC884 */ int    spectrum_idx;     // Spectrum history index
    /* +0xC888 */ int    reserved17;
    /* +0xC88C */ int    default_bg;       // Default background color
    /* +0xC890 */ int    fb_rows;          // Framebuffer row count
    /* +0xC894 */ int    fb_cols;          // Framebuffer column count
    /* +0xC898 */ int    fb_stride;        // Framebuffer stride
    /* +0xC89C */ int    reserved18[2];
    /* +0xC8A4 */ int    target_bpp;       // Target BPP for conversion
    /* +0xC8A8 */ int    reserved19[22];
    /* +0xC900 */ int    active_vis_idx;   // Currently processing vis index
    /* +0xC904 */ int    reserved20[8];
    /* +0xC924 */ int    wave_blend;       // Wave blend value
    /* +0xC928 */ int    audio_level;      // Master audio level (0-100)
    /* +0xC92C */ int    reserved21[3];
    /* +0xC938 */ float  motion_speed;     // Motion speed
    /* +0xC93C */ float  motion_phase;     // Motion phase
    /* +0xC940 */ int    reserved22[4];
    /* +0xC950 */ float  motion_delta;     // Motion delta per step
    /* +0xC954 */ int    reserved23;
    /* +0xC958 */ float  scroll_offset_y;  // Scroll offset Y
    /* +0xC95C */ int    reserved24[34];
    /* +0xC9E4 */ int    initialized;      // System initialized flag
    /* +0xC9E8 */ float  freq_low;         // Low frequency component
    /* +0xC9EC */ float  freq_high;        // High frequency component
    /* +0xC9F0 */ int    reserved25[32];
    /* +0xCA74 */ float  motion_magnitude; // Motion magnitude
    /* +0xCA78 */ int    resize_flag;      // Resize detected flag
    /* +0xCA7C */ int    reserved26[2];
    /* +0xCA84 */ int    max_vis;          // Max vis slots (0x37 = 55)
    /* +0xCA88 */ int    reserved27[28];
    /* +0xCF70 */ int    transparent_color;// Transparent/background color
    
    // Framebuffer management
    /* +0xCF74 */ int    reserved28[33];
    /* +0xD038 */ int    vis_count;        // Number of active visualizations
    /* +0xD03C */ int    reserved29;
    /* +0xD040 */ int    pixel_count;      // Width × height
    
    // Per-preset configuration (stride 0x1EC)
    /* +0xD044 */ TRILOGY_PRESET presets[TRILOGY_MAX_PRESETS];
    
    // Additional state...
    /* +0x31FC */ void*  frame_buffer;     // Active pixel buffer (BGRA)
    /* +0x3200 */ int    reserved30;
    /* +0x3204 */ void*  dest_buffer;      // Destination buffer pointer
    /* +0x3208 */ BITMAPINFO* bmp_info;    // BITMAPINFO pointer
    /* +0x320C */ int    reserved31;
    /* +0x3210 */ void*  pixel_data;       // Pixel data start
    /* +0x3214 */ int    reserved32[4];
    /* +0x3224 */ short  buf_height;       // Current buffer height
    /* +0x3226 */ short  buf_width;        // Current buffer width
    /* +0x3228 */ int    row_stride;       // Row stride in bytes
    /* +0x322C */ char   color_depth;      // Bits per pixel (8/16/24/32)
    /* +0x322D */ char   clear_color;      // Background clear color
    /* +0x322E */ short  reserved32b;
    /* +0x3230 */ int    reserved33;
    /* +0x3234 */ int    center_x;         // Center X (width/2)
    /* +0x3238 */ int    center_y;         // Center Y (height/2)
    /* +0x323C */ int    reserved34;
    /* +0x3240 */ int    current_preset;   // Current preset index
    /* +0x3244 */ int    reserved35[18];
    /* +0x328C */ int    reserved36[2];
    /* +0x3294 */ int    last_width;       // Last presented width
    /* +0x3298 */ int    last_height;      // Last presented height
    /* +0x329C */ void*  last_buffer;      // Last presented buffer ptr
    /* +0x32A0 */ int    reserved37;
    /* +0x32A4 */ int    main_buffer;      // Primary pixel buffer
    /* +0x32A8 */ void*  work_buffer;      // Working/temp pixel buffer
    /* +0x32AC */ void*  alloc_buffer;     // Allocated buffer (staging)
    /* +0x32B0 */ void*  resource_data;    // Resource/data pointer
    /* +0x32B4 */ void*  palette_buf;      // Palette buffer
    /* +0x32B8 */ void*  palette_buf2;     // Secondary palette buffer
    /* +0x32BC */ int    stretch_w;        // Stretch target width
    /* +0x32C0 */ int    stretch_h;        // Stretch target height
    /* +0x32C4 */ int    reserved38[22];
    /* +0x331C */ int    blit_x;           // Blit destination X
    /* +0x3320 */ int    blit_y;           // Blit destination Y
    /* +0x3324 */ int    reserved39[53];
    /* +0x33DC */ int    bg_color;         // Background fill color
    /* +0x33E0 */ int    reserved40[8];
    /* +0x3400 */ int    target_width;     // Target output width
};
#pragma pack(pop)

// Function pointer types for vtable methods
typedef int (*PFN_RENDER)(TRILOGY_STATE* state);
typedef int (*PFN_PRESENT)(TRILOGY_STATE* state);
typedef int (*PFN_EFFECT)(TRILOGY_STATE* state, int param);

// Vtable offsets (from base vtable)
#define VTBL_QUERYINTERFACE     0x00
#define VTBL_ADDREF             0x04
#define VTBL_RELEASE            0x08
#define VTBL_DESTROY            0x10
#define VTBL_RENDER_SETUP       0x1B0
#define VTBL_RENDER_PASS        0x54
#define VTBL_RENDER_FINAL       0x3C
#define VTBL_PRESENT            0x220
#define VTBL_WNDPROC            0x10

// Audio helper macros
#define AUDIO_GET_BASS(state)   (*(float*)((char*)state + 0x15C))
#define AUDIO_GET_MID(state)    (*(float*)((char*)state + 0x15C + 0xE0))
#define AUDIO_GET_TREBLE(state) (*(float*)((char*)state + 0x15C + 0x1C0))

// Sin LUT access macro
#define SIN_LUT(state, angle)   (state->sin_lut[(angle) % 360])
#define COS_LUT(state, angle)   (state->sin_lut[((angle) + 90) % 360])

#endif // TRILOGY_STATE_H
