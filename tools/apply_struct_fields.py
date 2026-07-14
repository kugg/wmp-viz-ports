#!/usr/bin/env python3
"""Apply struct field names to decompiled Trilogy code.

Replaces param_1[0xNNNN] array indexing with named struct field access.
The state struct (CTrilogyVisualizer) is ~53KB with fields at known offsets.

Two access patterns exist in the decompiled code:
  Pattern A: param_1[0xNNNN]           (param_1 is int*, index is hex)
  Pattern B: *(int*)(param_1 + 0xNNNN) (param_1 is byte*, direct byte offset)

All fields are 4-byte (int-sized) for Pattern A.
"""

import re
import sys
from pathlib import Path

# =============================================================================
# STRUCT FIELD MAPPINGS
# =============================================================================
# Maps byte offset (hex) -> field_name
# All offsets are byte offsets from the state base pointer.

STRUCT_FIELDS = {
    # Object header
    0x00: "vtable_render",
    0x04: "vtable_secondary",
    0x08: "vtable_tertiary",
    0x0C: "window_state_base",

    # Window sub-region
    0x1C: "hWnd",
    0x20: "hModule",
    0x3C: "def_wndproc",
    0x40: "window_self_ptr",
    0x44: "window_created",
    0x4C: "saved_wndproc",
    0x50: "wmp_output_iface",
    0x54: "wmp_secondary_iface",

    # Viewport defaults
    0x80: "default_width",
    0x84: "default_height",

    # FPS
    0x88: "frame_count",
    0x8C: "last_fps_time",
    0x90: "fps",

    # Object identity
    0x94: "unknown_0x94",
    0x98: "vtable_wmpeffects",
    0x9C: "unknown_0x9c",
    0xA0: "stored_param",
    0xA4: "ref_count",

    # Per-element vis values (byte offsets for Pattern B)
    # These are at 0x9BA8..0xC7F0
    0x9BA8: "vis_values_a",
    0xA3C8: "vis_values_b",
    0xABE8: "vis_values_c",
    0xB408: "vis_backup",

    # Sin LUT
    0xBC28: "sin_lut",

    # Framebuffer management
    0xC7E4: "row_padding",
    0xC7EC: "framebuffer",
    0xC7F0: "framebuffer_copy",

    # Audio pointers
    0xC7FC: "timed_level_freq",
    0xC800: "timed_level_wave",

    # Audio state
    0xC810: "audio_data_ptr",
    0xC814: "waveform_data_ptr",
    0xC818: "audio_ready",
    0xC81C: "bitmap_info_alloc",
    0xC820: "bmp_info",
    0xC824: "bmp_pixel_data",
    0xC828: "audio_format",

    # Rendering center
    0xC834: "half_width",

    # Change detection
    0xC83C: "change_hash",

    # Current preset index (heavily used in per-pixel loop)
    0xC900: "current_preset",

    # Spectrum / vis index
    0xC840: "spectrum_idx",
    0xC848: "fb_row_count",
    0xC84C: "fb_col_count",
    0xC850: "fb_stride",
    0xC858: "target_bpp",

    # Preset iteration
    0xC864: "spectrum_write_idx",
    0xC86C: "active_vis_idx",
    0xC884: "max_preset_idx",
    0xC888: "current_preset_loop",
    0xC88C: "reset_range_start",
    0xC890: "reset_range_end",

    # Buffer fill color
    0xC898: "clear_color",

    # Multi-pass render control
    0xC8A4: "render_pass_count",
    0xC8A8: "termination_flag",

    # Render center (from Render_MainLoop)
    0xC8BC: "center_x",
    0xC8C0: "center_y",

    # Active preset list (from IWMPEffects_Render)
    0xC8D0: "active_preset_list",

    # Frame dimensions (from Render_MainLoop: used for malloc)
    0xC8E8: "frame_width",
    0xC8EC: "frame_height",
    0xC8F0: "single_preset_mode",

    # Error / init
    0xC904: "error_flag",
    0xC908: "init_render_guard",
    0xC90C: "first_init_flag",
    0xC910: "default_bg_color",
    0xC918: "render_init_phase",

    # Render defaults
    0xC91C: "render_width_init",
    0xC920: "render_height_init",

    # Viewport dimensions
    0xC928: "viewport_width",
    0xC92C: "viewport_height",

    # Texture dimensions
    0xC930: "texture_width",
    0xC934: "texture_height",

    # Render pass count
    0xC938: "render_passes",

    # Foreground window
    0xC93C: "foreground_hwnd",

    # Frame skip
    0xC944: "frame_skip_counter",

    # Rect from input
    0xC948: "rect_left",
    0xC94C: "rect_top",

    # Previous viewport
    0xC950: "prev_viewport_width",
    0xC954: "prev_viewport_height",

    # Resize detection
    0xC958: "resize_flag",
    0xC95C: "frame_stability",

    # Buffer management
    0xC980: "buffers_allocated",
    0xC984: "staging_buffer",
    0xC988: "work_buffer",
    0xC98C: "alloc_buf_a",
    0xC990: "alloc_buf_b",
    0xC998: "alloc_buf_c",
    0xC99C: "alloc_buf_d",
    0xC9A0: "alloc_buf_e",

    # Screen DC
    0xC9AC: "screen_dc_storage",

    # Last presented
    0xC9B4: "last_present_width",
    0xC9B8: "last_present_height",
    0xC9BC: "last_buffer_ptr",

    # Primary pixel buffer
    0xC9C4: "primary_buffer",

    # Resource/data
    0xC9CC: "resource_data",
    0xC9D0: "palette_buffer",
    0xC9D4: "palette_buffer_2",

    # Stretch
    0xC9D8: "stretch_width",
    0xC9DC: "stretch_height",

    # Blit destination
    0xC9F8: "blit_dest_x",
    0xC9FC: "blit_dest_y",

    # Preset iteration counter
    0xCA08: "preset_iter_counter",

    # Max vis count
    0xCA20: "max_vis_count",

    # Alloc buffer F
    0xCA44: "alloc_buf_f",

    # Pixel iteration core (hot loop working variables)
    0xC808: "dst_pixel_ptr",         # Write cursor into output buffer
    0xC8CC: "src_center_x",          # Source image center X
    0xC8D4: "src_center_y",          # Source image center Y
    0xC994: "src_height",            # Source sub-image height
    0xCBC4: "pixel_col",             # Current pixel column index
    0xCBC8: "pixel_row",             # Current pixel row index
    0xCBCC: "pixel_dx",              # X offset from center
    0xCBD0: "pixel_dy",              # Y offset from center
    0xCBE0: "direction_ratio",       # Angle/direction ratio for polar
    0xCBEC: "sample_count",          # Valid neighbor sample count
    0xCA18: "pixel_index",           # Flat pixel iteration counter

    # ARGB color pipeline (per-pixel color working variables)
    0xCD9C: "blue_channel",          # Blue component (byte 0)
    0xCDAC: "current_pixel",         # Packed ARGB value being processed
    0xCEAC: "green_channel",         # Green component (byte 1)
    0xCF40: "src_width",             # Source buffer width (stride)
    0xCF44: "red_channel",           # Red component (byte 2)
    0xCF48: "red_accum",             # Red channel neighbor accumulator
    0xCF70: "transparent_color",     # Background/transparent color value

    # Shadow / neighborhood sampling
    0xCDA4: "shadow_radius",         # Shadow sampling radius

    # Blit / compositing working variables
    0xCDDC: "dst_y",                 # Destination Y for blit
    0xD018: "blend_pass_count",      # Sub-visualization blend pass counter
    0xD040: "total_pixels",          # Width * height
    0xD058: "row_copy_counter",      # Row iteration / init counter

    # Active framebuffer
    0xCB00: "active_framebuffer",
    0xCB04: "buf_width",
    0xCB08: "buf_height",
    0xCB0C: "color_depth",

    # Render dimensions
    0xCB30: "render_width",
    0xCB34: "render_height",

    # Blit coordinates
    0xCB48: "blit_x",
    0xCB4C: "blit_y",

    # Preset iteration counter (IWMPEffects_Render)
    0xCB60: "preset_iter",

    # Screen HDC
    0xCBD4: "screen_hdc",

    # ── Pattern A (array index) specific mappings ──
    # These are int-array indices, byte_offset = index * 4

    # Window sub-region (via param_1[0xNN])
    # param_1[0x14] = byte 0x50 = wmp_output_iface
    # param_1[0x13] = byte 0x4C = wmp_secondary_iface

    # Render dimensions (Pattern A: index * 4 = byte offset)
    # param_1[0x3234] = byte 0xC8D0 = center_x
    # param_1[0x3236] = byte 0xC8D8 = center_y
    # param_1[0x32a4] = byte 0xCA90 = main_width
    # param_1[0x32a5] = byte 0xCA94 = main_height
    # param_1[0x32a9] = byte 0xCAA4 = staging_buffer
    # param_1[0x32aa] = byte 0xCAA8 = work_buffer
    # param_1[0x322a] = byte 0xC8A8 = clear_color
    # param_1[0x3309] = byte 0xCC24 = single_preset_mode
    # param_1[0x31fc] = byte 0xC7F0 = active_framebuffer
    # param_1[0x3420] = byte 0xD080 = blit_x
    # param_1[0x3425] = byte 0xD094 = blit_y
    # param_1[0x3225] = byte 0xC894 = buf_width
    # param_1[0x3224] = byte 0xC890 = buf_height
    # param_1[0x3270] = byte 0xC9C0 = render_flag
    # param_1[0x3274] = byte 0xC9D0 = alloc_error
    # param_1[0x3279] = byte 0xC9E4 = initialized
    # param_1[0x328e] = byte 0xCA38 = completion_flag
    # param_1[0x326b] = byte 0xC9AC = render_pass_count
    # param_1[0x326a] = byte 0xC9A8 = termination_flag
    # param_1[0x326d] = byte 0xC9B4 = buffers_allocated
    # param_1[0x3271] = byte 0xC9C4 = secondary_buf_flag
    # param_1[0x32a3] = byte 0xCA8C = max_vis_count
    # param_1[0x3298] = byte 0xCA60 = preset_loop_idx
    # param_1[0x31ea] = byte 0xC3A8 = preset_texture_base
    # param_1[0x320b] = byte 0xC82C = unknown field
    # param_1[0x3207] = byte 0xC81C = bitmap_info_alloc
    # param_1[0x3208] = byte 0xC820 = bmp_info
    # param_1[0x3209] = byte 0xC824 = bmp_pixel_data
    # param_1[0x3284] = byte 0xCA10 = bmp_offset
    # param_1[0x3229] = byte 0xC8A4 = color_depth
    # param_1[0x32af] = byte 0xCABC = stretch_width
    # param_1[0x32b0] = byte 0xCAC0 = stretch_height
    # param_1[0x3290] = byte 0xCA40 = last_buf_width
    # param_1[0x3291] = byte 0xCA44 = last_buf_height
    # param_1[0x3292] = byte 0xCA48 = last_buf_ptr
    # param_1[0x329a] = byte 0xCA68 = screen_dc_field
    # param_1[0x3318] = byte 0xCC60 = offset_x
    # param_1[0x3319] = byte 0xCC64 = offset_y
    # param_1[0x3240] = byte 0xC900 = current_preset
    # param_1[0x32a1] = byte 0xCA84 = max_preset_slots
    # param_1[0x269e] = byte 0x9A78 = active_preset_start
    # param_1[0x3306] = byte 0xCC18 = frame_width
    # param_1[0x3307] = byte 0xCC1C = frame_stride
    # param_1[0x3308] = byte 0xCC20 = frame_height
    # param_1[0x3428] = byte 0xD0A0 = preset_iter
    # param_1[0x3274] = byte 0xC9D0 = alloc_error
}

# Build reverse mapping: byte_offset -> field_name (for Pattern B)
# and index -> field_name (for Pattern A: byte_offset / 4)
PATTERN_B_FIELDS = STRUCT_FIELDS  # byte offset -> name

# Auto-generate Pattern A (int-array index) mappings from STRUCT_FIELDS
PATTERN_A_AUTO = {}  # array index -> name
for byte_offset, name in STRUCT_FIELDS.items():
    if byte_offset % 4 == 0:
        PATTERN_A_AUTO[byte_offset // 4] = name

# =============================================================================
# MANUAL INDEX-BASED FIELDS FOR PATTERN A
# =============================================================================
# These supplement PATTERN_A_AUTO for cases where the auto-mapping doesn't
# exist in STRUCT_FIELDS (e.g., fields only known by their int-array index).

INDEX_FIELDS_MANUAL = {
    # Window sub-region
    0x13: "wmp_secondary_iface",      # byte 0x4C
    0x14: "wmp_output_iface",         # byte 0x50

    # Render pipeline (byte offset = index * 4)
    0x31FC: "active_framebuffer",     # byte 0xC7F0
    0x3207: "bitmap_info_alloc",      # byte 0xC81C
    0x3208: "bmp_info",               # byte 0xC820
    0x3209: "bmp_pixel_data",         # byte 0xC824
    0x320B: "bmp_pixel_data2",        # byte 0xC82C
    0x3224: "buf_height",             # byte 0xC890
    0x3225: "buf_width",              # byte 0xC894
    0x3229: "color_depth",            # byte 0xC8A4
    0x322A: "clear_color",            # byte 0xC8A8
    0x3234: "center_x",              # byte 0xC8D0
    0x3236: "center_y",              # byte 0xC8D8
    0x3240: "current_preset",        # byte 0xC900
    0x326A: "termination_flag",      # byte 0xC9A8
    0x326B: "render_pass_count",     # byte 0xC9AC
    0x326D: "buffers_allocated",     # byte 0xC9B4
    0x3270: "render_flag",           # byte 0xC9C0
    0x3271: "secondary_buf_flag",    # byte 0xC9C4
    0x3274: "alloc_error",           # byte 0xC9D0
    0x3279: "initialized",           # byte 0xC9E4
    0x3284: "bmp_offset",            # byte 0xCA10
    0x328E: "completion_flag",       # byte 0xCA38
    0x3290: "last_buf_width",        # byte 0xCA40
    0x3291: "last_buf_height",       # byte 0xCA44
    0x3292: "last_buf_ptr",          # byte 0xCA48
    0x3298: "preset_loop_idx",       # byte 0xCA60
    0x329A: "screen_dc_field",       # byte 0xCA68
    0x32A1: "max_preset_slots",      # byte 0xCA84
    0x32A3: "max_vis_count",         # byte 0xCA8C
    0x32A4: "main_width",            # byte 0xCA90
    0x32A5: "main_height",           # byte 0xCA94
    0x32A9: "staging_buffer",        # byte 0xCA A4
    0x32AA: "work_buffer",           # byte 0xCAA8
    0x32AB: "alloc_buf_b",           # byte 0xCAAC
    0x32AC: "alloc_buf_c",           # byte 0xCAB0
    0x32AD: "alloc_buf_d",           # byte 0xCAB4
    0x32AE: "alloc_buf_e",           # byte 0xCAB8
    0x32AF: "stretch_width",         # byte 0xCABC
    0x32B0: "stretch_height",        # byte 0xCAC0
    0x32B9: "screen_dc_ptr",         # byte 0xCAE4
    0x3306: "frame_width",           # byte 0xCC18
    0x3307: "frame_stride",          # byte 0xCC1C
    0x3308: "frame_height",          # byte 0xCC20
    0x3309: "single_preset_mode",    # byte 0xCC24
    0x3318: "offset_x",              # byte 0xCC60
    0x3319: "offset_y",              # byte 0xCC64
    0x333D: "alloc_buf_g",           # byte 0xCCF4
    0x334E: "alloc_buf_h",           # byte 0xCD38
    0x3354: "alloc_buf_i",           # byte 0xCD50
    0x3395: "alloc_buf_f",           # byte 0xCDE4
    0x3420: "blit_x",               # byte 0xD080
    0x3425: "blit_y",               # byte 0xD094
    0x3428: "preset_iter",           # byte 0xD0A0

    # Per-element vis values (byte / 4 for pattern A)
    0x269E: "active_preset_start",   # byte 0x9A78

    # Preset data (base index 0xC39, stride 0x7B)
    0x31EA: "preset_texture_base",   # byte 0xC3A8 (loop base)
}

# Merge: auto-generated from STRUCT_FIELDS + manual supplements
# Manual entries take precedence for fields not in STRUCT_FIELDS
PATTERN_A_FIELDS = {}
PATTERN_A_FIELDS.update(PATTERN_A_AUTO)
PATTERN_A_FIELDS.update(INDEX_FIELDS_MANUAL)


def apply_struct_fields(input_path, output_path):
    """Read decompiled output, apply struct field names, write to output."""
    with open(input_path, 'r') as f:
        lines = f.readlines()

    rename_count = 0
    output_lines = []

    # Patterns to match:
    # Pattern A: param_1[0xNNNN] or similar variable[0xNNNN]
    # Pattern B: *(type*)(param_1 + 0xNNNN) or similar

    # Pattern A: array indexing with hex index
    # Matches: varname[0x3234] or varname[iVar1] (skip these - only hex)
    pattern_a = re.compile(r'(\w+)\[(0x[0-9a-fA-F]+)\]')

    # Pattern B: pointer cast with byte offset
    # Matches: *(int*)(param_1 + 0xc8d0) or *(undefined4*)(param_1 + 0xc8d0)
    pattern_b = re.compile(r'\*\((?:int|undefined4|void\s*\*|LPVOID|short|char)\s*\*\)\s*\(\s*(\w+)\s*\+\s*(0x[0-9a-fA-F]+)\s*\)')

    for line in lines:
        original = line

        # Apply Pattern A replacements (right to left to preserve positions)
        def replace_pattern_a(match):
            var_name = match.group(1)
            hex_index = match.group(2)
            index = int(hex_index, 16)

            if index in PATTERN_A_FIELDS:
                field = PATTERN_A_FIELDS[index]
                rename = f"{var_name}->{field}"
                return rename
            return match.group(0)

        line = pattern_a.sub(replace_pattern_a, line)

        # Apply Pattern B replacements
        def replace_pattern_b(match):
            var_name = match.group(1)
            hex_offset = match.group(2)
            offset = int(hex_offset, 16)

            if offset in PATTERN_B_FIELDS:
                field = PATTERN_B_FIELDS[offset]
                rename = f"{var_name}->{field}"
                return rename
            return match.group(0)

        line = pattern_b.sub(replace_pattern_b, line)

        if line != original:
            rename_count += 1

        output_lines.append(line)

    with open(output_path, 'w') as f:
        f.writelines(output_lines)

    return rename_count


def main():
    if len(sys.argv) < 3:
        print("Usage: apply_struct_fields.py <input.c> <output.c>")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    count = apply_struct_fields(input_path, output_path)
    print(f"Applied {count} struct field renames")


if __name__ == "__main__":
    main()
