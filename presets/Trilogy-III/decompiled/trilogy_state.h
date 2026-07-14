/**
 * Trilogy WMP Visualizer State Structure Definitions
 *
 * Reverse-engineered from Ghidra decompilation of TrilogyI.dll, TrilogyII.dll,
 * TrilogyIII.dll. This is the CTrilogyVisualizer COM object (~53KB).
 *
 * Two allocation paths exist:
 *   - Create_VisObject2: operator_new(0xD0AC), state starts at +0x08
 *   - ClassFactory2_CreateInstance: operator_new(0xD0A4), state starts at +0x00
 *
 * All offsets below are from the state base pointer (param_1 in most functions).
 */

#ifndef TRILOGY_STATE_H
#define TRILOGY_STATE_H

#include <windows.h>

typedef struct _TRILOGY_STATE TRILOGY_STATE;

#define TRILOGY_MAX_PRESETS         54
#define TRILOGY_PRESET_STRIDE       0x7B
#define TRILOGY_PRESET_BASE_IDX     0xC39
#define TRILOGY_SIN_LUT_SIZE        360
#define TRILOGY_SPECTRUM_SIZE       520
#define TRILOGY_DEFAULT_WIDTH       640
#define TRILOGY_DEFAULT_HEIGHT      480
#define TRILOGY_RENDER_WIDTH_INIT   0x15E
#define TRILOGY_RENDER_HEIGHT_INIT  0x140
#define TRILOGY_TEXTURE_SIZE        0x100
#define TRILOGY_RENDER_PASS_COUNT   9
#define TRILOGY_OBJECT_SIZE         0xD0AC
#define TRILOGY_STATE_BASE_OFFSET   0x08

/* ── Helper macros ─────────────────────────────────────────────────────── */

#define STATE_FIELD(state, offset, type) (*(type*)((char*)(state) + (offset)))
#define STATE_IDX(state, index)          ((int*)(state))[(index)]
#define PRESET_FIELD(state, idx, foff) \
    STATE_FIELD(state, ((idx) * TRILOGY_PRESET_STRIDE + TRILOGY_PRESET_BASE_IDX) * 4 + (foff), int)
#define STATE_FRAMEBUFFER(state)         STATE_FIELD(state, 0xC7F0, void*)
#define STATE_VTABLE(state)              STATE_FIELD(state, 0x00, void**)

/* ── Main state structure (~53KB) ──────────────────────────────────────── */

#pragma pack(push, 4)
struct _TRILOGY_STATE {

    /* ═══ Object header (0x00..0xA4) ═══ */

    /* +0x00 */ void**   vtable_render;         /* Primary render vtable */
    /* +0x04 */ void**   vtable_secondary;      /* Secondary interface vtable */
    /* +0x08 */ void**   vtable_tertiary;       /* Tertiary vtable */
    /* +0x0C */ void*    window_state_base;     /* -> +0x10 (window sub-struct) */

    /* Window sub-region: InitWindowState(state+4) zeroes most, sets DefWindowProcA */
    /* +0x10 */ void*    window_reserved[3];
    /* +0x1C */ HWND     hWnd;
    /* +0x20 */ HMODULE  hModule;
    /* +0x24 */ void*    window_reserved2[6];

    /* +0x3C */ void*    def_wndproc;           /* DefWindowProcA */
    /* +0x40 */ void*    window_self_ptr;       /* Self-pointer */
    /* +0x44 */ int      window_created;        /* 1 after window creation */
    /* +0x48 */ int      window_reserved3;
    /* +0x4C */ void*    saved_wndproc;         /* Previous window proc */

    /* WMP interface pointers */
    /* +0x50 */ int      wmp_output_iface;      /* param_1[0x14]: WMP output interface */
    /* +0x54 */ int      wmp_secondary_iface;   /* param_1[0x13]: WMP secondary */

    /* +0x58..0x7C */ void* window_reserved4[10];

    /* Viewport defaults */
    /* +0x80 */ int      default_width;         /* = 640 */
    /* +0x84 */ int      default_height;        /* = 480 */

    /* FPS */
    /* +0x88 */ int      frame_count;
    /* +0x8C */ DWORD    last_fps_time;         /* timeGetTime() */
    /* +0x90 */ float    fps;

    /* +0x94 */ int      unknown_0x94;
    /* +0x98 */ void**   vtable_wmpeffects;     /* IWMPEffects vtable */
    /* +0x9C */ int      unknown_0x9c;          /* Set to 0xFF */
    /* +0xA0 */ void*    stored_param;          /* Constructor arg */
    /* +0xA4 */ int      ref_count;

    /* +0xA8..0x9BA7 */ char gap1[0x9B00];

    /* ═══ Per-element visualization value arrays (0x9BA8..0xC7F0) ═══ */
    /* Indexed by resetIndex; State_ResetAll iterates 0x208 elements */

    /* +0x9BA8 */ float    vis_values_a[0x208]; /* 520 floats */
    /* +0xA3C8 */ float    vis_values_b[0x208];
    /* +0xABE8 */ float    vis_values_c[0x208];
    /* +0xB408 */ float    vis_backup[0x208];

    /* Sine LUT */
    /* +0xBC28 */ float    sin_lut[TRILOGY_SIN_LUT_SIZE];

    /* +0xC218..C7EF */ char gap2[0x5D8];

    /* ═══ Core rendering state (0xC7F0..0xD0AC) ═══ */

    /* Framebuffer management */
    /* +0xC7E4 */ int      row_padding;          /* Row alignment bytes */
    /* +0xC7E8 */ int      unknown_0xc7e8;
    /* +0xC7EC */ void*    framebuffer;          /* Main pixel data (BGRA) */
    /* +0xC7F0 */ void*    framebuffer_copy;     /* Framebuffer copy */

    /* +0xC7F4 */ void*    unknown_ptr_0xc7f4;
    /* +0xC7F8 */ int      unknown_0xc7f8;

    /* Audio pointers */
    /* +0xC7FC */ void*    timed_level_freq;     /* TimedLevel frequency data */
    /* +0xC800 */ void*    timed_level_wave;     /* TimedLevel waveform data */
    /* +0xC804 */ int      unknown_0xc804;
    /* +0xC808 */ void*    dst_pixel_ptr;        /* Write cursor into output buffer */
    /* +0xC80C */ int      unknown_0xc80c;

    /* Audio state */
    /* +0xC810 */ void*    audio_data_ptr;
    /* +0xC814 */ void*    waveform_data_ptr;
    /* +0xC818 */ int      audio_ready;
    /* +0xC81C */ void*    bitmap_info_alloc;    /* BITMAPINFO alloc (HeapFree'd) */
    /* +0xC820 */ BITMAPINFO* bmp_info;          /* BITMAPINFO pointer */
    /* +0xC824 */ void*    bmp_pixel_data;       /* Pixel data after BITMAPINFO */
    /* +0xC828 */ int      audio_format;
    /* +0xC82C */ int      unknown_0xc82c;
    /* +0xC830 */ int      unknown_0xc830;

    /* Rendering center */
    /* +0xC834 */ float    half_width;

    /* +0xC838 */ int      unknown_0xc838;

    /* Change detection */
    /* +0xC83C */ int      change_hash;

    /* +0xC840 */ int      spectrum_idx;
    /* +0xC844 */ int      unknown_0xc844;

    /* Framebuffer geometry */
    /* +0xC848 */ int      fb_row_count;
    /* +0xC84C */ int      fb_col_count;
    /* +0xC850 */ int      fb_stride;

    /* +0xC854 */ int      unknown_0xc854;

    /* BPP conversion */
    /* +0xC858 */ int      target_bpp;

    /* +0xC85C */ int      unknown_0xc85c;
    /* +0xC860 */ int      unknown_0xc860;

    /* Spectrum / vis index */
    /* +0xC864 */ int      spectrum_write_idx;

    /* +0xC868 */ int      unknown_0xc868;

    /* Preset iteration */
    /* +0xC86C */ int      active_vis_idx;       /* Currently processing vis index */

    /* +0xC870 */ int      unknown_0xc870;
    /* +0xC874 */ int      unknown_0xc874;
    /* +0xC878 */ int      unknown_0xc878;
    /* +0xC87C */ int      unknown_0xc87c;
    /* +0xC880 */ int      unknown_0xc880;

    /* Max preset index for iteration */
    /* +0xC884 */ int      max_preset_idx;
    /* +0xC888 */ int      current_preset_loop;

    /* Reset range */
    /* +0xC88C */ int      reset_range_start;
    /* +0xC890 */ int      reset_range_end;

    /* +0xC894 */ int      unknown_0xc894;

    /* Buffer fill color */
    /* +0xC898 */ int      clear_color;

    /* +0xC89C */ int      unknown_0xc89c;
    /* +0xC8A0 */ int      unknown_0xc8a0;

    /* Multi-pass render control */
    /* +0xC8A4 */ int      render_pass_count;
    /* +0xC8A8 */ int      termination_flag;

    /* +0xC8AC */ int      unknown_0xc8ac[4];

    /* Render center (from Render_MainLoop) */
    /* +0xC8BC */ int      center_x;
    /* +0xC8C0 */ int      center_y;

    /* +0xC8C4 */ int      unknown_0xc8c4;

    /* ═══ Pixel iteration core (0xC8C8..0xCBE0) ═══ */
    /* Per-pixel loop working variables, hot path */

    /* Preset state region (per-preset config starts here) */
    /* +0xC8C8 */ int      unknown_0xc8c8[2];

    /* Source image center (computed from preset params) */
    /* +0xC8CC */ int      src_center_x;         /* width/2 + offset_x */
    /* +0xC8D0 */ int      active_preset_idx;    /* Active preset for rendering */
    /* +0xC8D4 */ int      src_center_y;         /* height/2 + offset_y */

    /* Active preset list (from IWMPEffects_Render: -1 terminated) */
    /* +0xC8D8 */ int      active_preset_list[5];

    /* Frame dimensions (from Render_MainLoop: used for malloc) */
    /* +0xC8E8 */ int      frame_width;
    /* +0xC8EC */ int      frame_height;
    /* +0xC8F0 */ int      single_preset_mode;   /* 0=multi, nonzero=single */

    /* +0xC8F4 */ int      unknown_0xc8f4[4];

    /* Error / init */
    /* +0xC904 */ int      error_flag;           /* 1 = allocation failure */
    /* +0xC908 */ int      init_render_guard;    /* Must != 0x1E */
    /* +0xC90C */ int      first_init_flag;      /* 0=first time */

    /* Default background color */
    /* +0xC910 */ int      default_bg_color;

    /* +0xC914 */ int      unknown_0xc914;

    /* Render init */
    /* +0xC918 */ int      render_init_phase;

    /* Render defaults */
    /* +0xC91C */ int      render_width_init;    /* = 0x15E */
    /* +0xC920 */ int      render_height_init;   /* = 0x140 */

    /* +0xC924 */ int      unknown_0xc924;

    /* Viewport dimensions */
    /* +0xC928 */ int      viewport_width;
    /* +0xC92C */ int      viewport_height;

    /* Texture dimensions */
    /* +0xC930 */ int      texture_width;        /* = 0x100 */
    /* +0xC934 */ int      texture_height;       /* = 0x100 */

    /* Render pass count */
    /* +0xC938 */ int      render_passes;        /* = 9 */

    /* Foreground window */
    /* +0xC93C */ HWND     foreground_hwnd;

    /* +0xC940 */ int      unknown_0xc940;

    /* Frame skip */
    /* +0xC944 */ int      frame_skip_counter;

    /* Rect from input */
    /* +0xC948 */ int      rect_left;
    /* +0xC94C */ int      rect_top;

    /* Previous viewport (for resize detection) */
    /* +0xC950 */ int      prev_viewport_width;
    /* +0xC954 */ int      prev_viewport_height;

    /* Resize detection */
    /* +0xC958 */ int      resize_flag;
    /* +0xC95C */ int      frame_stability;     /* Counts up to 0x10 */

    /* +0xC960 */ int      unknown_0xc960[8];

    /* ═══ Buffer management (0xC980..0xCA00) ═══ */

    /* Buffer allocated flag */
    /* +0xC980 */ int      buffers_allocated;

    /* Buffer pointers (all HeapFree'd in FreeAllBuffers) */
    /* +0xC984 */ void*    staging_buffer;       /* Main pixel buffer */
    /* +0xC988 */ void*    work_buffer;          /* Working/temp buffer */
    /* +0xC98C */ void*    alloc_buf_a;
    /* +0xC990 */ void*    alloc_buf_b;
    /* +0xC994 */ int      src_height;           /* Source sub-image height */
    /* +0xC998 */ void*    alloc_buf_c;
    /* +0xC99C */ void*    alloc_buf_d;
    /* +0xC9A0 */ void*    alloc_buf_e;

    /* +0xC9A4 */ int      unknown_0xc9a4[2];

    /* Screen DC region */
    /* +0xC9AC */ int      screen_dc_storage;

    /* +0xC9B0 */ int      unknown_0xc9b0;

    /* Last presented */
    /* +0xC9B4 */ int      last_present_width;
    /* +0xC9B8 */ int      last_present_height;
    /* +0xC9BC */ void*    last_buffer_ptr;

    /* +0xC9C0 */ int      unknown_0xc9c0;

    /* Primary pixel buffer */
    /* +0xC9C4 */ void*    primary_buffer;

    /* +0xC9C8 */ int      unknown_0xc9c8;

    /* Resource/data */
    /* +0xC9CC */ void*    resource_data;
    /* +0xC9D0 */ void*    palette_buffer;
    /* +0xC9D4 */ void*    palette_buffer_2;

    /* Stretch */
    /* +0xC9D8 */ int      stretch_width;
    /* +0xC9DC */ int      stretch_height;

    /* +0xC9E0 */ int      unknown_0xc9e0[6];

    /* Blit destination */
    /* +0xC9F8 */ int      blit_dest_x;
    /* +0xC9FC */ int      blit_dest_y;

    /* +0xCA00 */ int      unknown_0xca00;
    /* +0xCA04 */ int      unknown_0xCA04;

    /* Preset iteration counter */
    /* +0xCA08 */ int      preset_iter_counter;

    /* +0xCA0C */ int      unknown_0xca0c;

    /* +0xCA10 */ int      unknown_0xca10[2];

    /* Pixel iteration counter (hot loop) */
    /* +0xCA18 */ int      pixel_index;          /* Flat pixel iteration counter */

    /* +0xCA1C */ int      unknown_0xca1c;

    /* Max vis count */
    /* +0xCA20 */ int      max_vis_count;        /* = 0x37 */

    /* +0xCA24 */ int      unknown_0xca24;

    /* +0xCA28 */ int      unknown_0xca28[6];

    /* +0xCA40 */ int      unknown_0xca40;

    /* Alloc buffer F */
    /* +0xCA44 */ void*    alloc_buf_f;

    /* +0xCA48 */ int      unknown_0xca48;

    /* +0xCA4C */ int      unknown_0xca4c[8];

    /* +0xCA6C */ int      unknown_0xca6c[2];

    /* +0xCA74 */ int      unknown_0xca74;

    /* +0xCA78 */ int      unknown_0xca78[3];

    /* Preset texture pointers (freed in loop) */
    /* +0xCA84 */ void*    preset_texture_ptrs[TRILOGY_MAX_PRESETS];

    /* +0xCAF0 */ int      unknown_0xcaf0[4];

    /* ═══ Active framebuffer and presentation ═══ */

    /* +0xCB00 */ void*    active_framebuffer;   /* Active pixel buffer (BGRA) */
    /* +0xCB04 */ int      buf_width;
    /* +0xCB08 */ int      buf_height;
    /* +0xCB0C */ int      color_depth;          /* 8/16/24/32 bpp */

    /* +0xCB10 */ int      unknown_0xcb10[8];

    /* Render dimensions */
    /* +0xCB30 */ int      render_width;
    /* +0CB34 */  int      render_height;

    /* +0xCB38 */ int      unknown_0xcb38[2];

    /* ═══ Final region (0xCB40..0xD0AC) ═══ */

    /* +0xCB40 */ int      unknown_0xcb40[2];

    /* +0xCB48 */ int      blit_x;               /* Blit dest X */
    /* +0xCB4C */ int      blit_y;               /* Blit dest Y */

    /* +0xCB50 */ int      unknown_0xcb50[4];

    /* Preset iteration counter */
    /* +0xCB60 */ int      preset_iter;          /* IWMPEffects_Render loop counter */

    /* +0xCB64 */ int      unknown_0xcb64[24];

    /* ═══ Pixel iteration core (hot path working variables) ═══ */
    /* +0xCBC4 */ int      pixel_col;            /* Current pixel column index */
    /* +0xCBC8 */ int      pixel_row;            /* Current pixel row index */
    /* +0xCBCC */ int      pixel_dx;             /* X offset from center */
    /* +0xCBD0 */ int      pixel_dy;             /* Y offset from center */

    /* Screen HDC */
    /* +0xCBD4 */ HDC      screen_hdc;

    /* +0xCBD8 */ int      unknown_0xcbd8;

    /* Direction / polar ratio */
    /* +0xCBE0 */ int      direction_ratio;      /* Angle ratio for polar effects */

    /* +0xCBE4 */ int      unknown_0xcbe4;

    /* Shadow / neighborhood sampling */
    /* +0xCBE8 */ int      unknown_0xcbe8;
    /* +0xCBEC */ int      sample_count;         /* Valid neighbor sample count */

    /* +0xCBF0 */ int      unknown_0xcbf0[28];

    /* ═══ ARGB color pipeline (0xCD00..0xCF80) ═══ */
    /* Per-pixel color decomposition and processing */

    /* +0xCD9C */ int      blue_channel;         /* Blue component (byte 0) */
    /* +0xCDA0 */ int      unknown_0xcda0;
    /* +0xCDA4 */ int      shadow_radius;        /* Shadow sampling radius */
    /* +0xCDA8 */ int      unknown_0xcda8;
    /* +0xCDAC */ int      current_pixel;        /* Packed ARGB value being processed */

    /* +0xCDB0 */ int      unknown_0xcdb0[40];

    /* +0xCDDC */ int      dst_y;                /* Destination Y for blit */

    /* +0xCDE0 */ int      unknown_0xcde0[104];

    /* +0xCEAC */ int      green_channel;        /* Green component (byte 1) */

    /* +0xCEB0 */ int      unknown_0xceb0[20];

    /* +0xCF40 */ int      src_width;            /* Source buffer width (stride) */
    /* +0xCF44 */ int      red_channel;          /* Red component (byte 2) */
    /* +0xCF48 */ int      red_accum;            /* Red channel neighbor accumulator */

    /* +0xCF4C */ int      unknown_0xcf4c[8];

    /* +0xCF70 */ int      transparent_color;    /* Background/transparent color */

    /* +0xCF74 */ int      unknown_0xcf74[25];

    /* ═══ Blit / compositing working variables (0xD010..0xD060) ═══ */

    /* +0xD018 */ int      blend_pass_count;     /* Sub-vis blend pass counter */

    /* +0xD01C */ int      unknown_0xd01c[8];

    /* +0xD040 */ int      total_pixels;         /* Width * height */

    /* +0xD044 */ int      unknown_0xd044[5];

    /* +0xD058 */ int      row_copy_counter;     /* Row iteration / init counter */

    /* +0xD05C */ int      unknown_0xd05c[9];

    /* ═══ Preset data array ═══ */
    /* Access: state[(preset_idx * 0x7B + 0xC39)]
     * Stride: 0x7B ints = 492 bytes per preset, base index 0xC39
     * Byte offset: preset_idx * 0x1EC + 0x30E4
     *
     * Per-preset layout (stride 492 bytes):
     *   +0x00 : preset_id / active flag
     *   +0x04 : texture_id
     *   +0x08 : type_code
     *   +0x0C : parameter_a (float)
     *   +0x10 : parameter_b (float)
     *   +0x14 : state_flag (0=idle, 1=active, 2=rendering)
     *   +0x30 : data_field
     *   +0x4C : blend_texture
     *   +0x50 : mask_texture
     *   +0x80 : buffer_a (zeroed on mismatch)
     *   +0x84 : buffer_b (HeapFree'd)
     *   +0x88 : buffer_c (HeapFree'd)
     *   +0x7A8: texture_alloc (HeapFree'd in FreeAllBuffers loop)
     */

    /* +0x30E4 */ int      preset_data[TRILOGY_MAX_PRESETS * TRILOGY_PRESET_STRIDE];
};
#pragma pack(pop)

/* ── Vtable offsets (from state vtable at +0x00) ──────────────────────── */

#define VTBL_QUERYINTERFACE        0x00
#define VTBL_ADDREF                0x04
#define VTBL_RELEASE               0x08
#define VTBL_DESTROY               0x0C
#define VTBL_DESTROY2              0x10
#define VTBL_RENDER_ALLOC          0x3C
#define VTBL_RENDER_INIT           0x44
#define VTBL_RENDER_SETUP          0x50
#define VTBL_RENDER_PASS           0x84
#define VTBL_RENDER_FINAL          0xC8
#define VTBL_RENDER_FREE           0xF4
#define VTBL_RENDER_BLUR           0x128
#define VTBL_RENDER_EFFECT         0x148
#define VTBL_RENDER_POST           0x15C
#define VTBL_RENDER_PRESENT        0x1B4
#define VTBL_PRESENT_TO_SCREEN     0x220
#define VTBL_ALLOC_TEXTURE         0x260
#define VTBL_RESIZE                0x288

/* Secondary vtable (at +0x04) */
#define VTBL2_SET_SCREEN_DC        0x44
#define VTBL2_BLIT_TO_SCREEN       0x68

/* WMP output interface (at state +0x50) */
#define VTBL_WMP_FLIP              0x2C
#define VTBL_WMP_RELEASE           0x6C

/* Audio helpers */
#define AUDIO_GET_BASS(state)      (*(float*)((char*)(state) + 0x15C))
#define AUDIO_GET_MID(state)       (*(float*)((char*)(state) + 0x15C + 0xE0))
#define AUDIO_GET_TREBLE(state)    (*(float*)((char*)(state) + 0x15C + 0x1C0))

/* Sin LUT (at byte offset 0xBC28 = float index 0x2F0A) */
#define SIN_LUT(state, angle)      (((float*)(state) + 0x2F0A)[(angle) % 360])
#define COS_LUT(state, angle)      (((float*)(state) + 0x2F0A)[((angle) + 90) % 360])

#endif /* TRILOGY_STATE_H */
