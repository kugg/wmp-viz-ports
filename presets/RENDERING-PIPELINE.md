# Trilogy Visualizer Rendering Pipeline

Reverse-engineered from Ghidra decompilation of the WMP Trilogy visualization plugin DLL.
All code references use `function_name @ address` with line numbers from `TrilogyII_decompiled.c`.

---

## 1. COM Interface & Object Layout

### IWMPEffects/IWMPEffects2 vtable

The DLL exports a COM object implementing IWMPEffects (v1) and IWMPEffects2 (v2).
The vtable is stored at `PTR_FUN_100217f0` in the .rdata section.

| Slot | Offset | Function | Role |
|------|--------|----------|------|
| 0 | 0x000 | `QueryInterface_Main @ 100116a0` | COM QI |
| 1 | 0x004 | `IUnknown_AddRef @ 100115f0` | AddRef |
| 2 | 0x008 | `IUnknown_Release2 @ 10011600` | Release |
| 3 | 0x00C | thunk → 0x10011818 | **IWMPEffects::Render** |
| 4 | 0x010 | thunk → 0x100117D8 | MediaInfo |
| 5 | 0x014 | thunk → 0x100117F8 | GetCapabilities |
| 6 | 0x018 | `Texture_InitRender @ 1000FAE0` | Init + per-frame setup |
| 13 | 0x034 | `0x100106B0` | RenderFullScreen |
| 14 | 0x038 | `0x10011160` | SetCore |
| 15 | 0x03C | `FUN_100103A0` | Create |
| 16 | 0x040 | `Init_GDIContext @ 100103F0` | Destroy |
| 17 | 0x044 | `0x10011080` | NotifyNewMedia |
| 18 | 0x048 | `0x10011A00` | OnWindowMessage |
| 19 | 0x04C | `0x10011150` | RenderWindowed |

All `IWMPEffects::X` entries are thunks: `sub dword ptr [esp+4], 0x94; jmp <internal>`.
The -0x94 adjustment converts from the COM vtable base to the state struct pointer
(state starts at offset +0x08, COM vtable at offset -0x94 relative to state).

### IWMPEffects::Render Thunk Chain

```
IWMPEffects::Render @ 10011A30:
  81 6C 24 04 94 00 00 00    sub dword ptr [esp+4], 0x94
  E9 E3 FD FF FF             jmp 10011818
```

The actual Render body is at 0x10011818 (after 8 NOP alignment padding).

### Internal vtable (extended dispatch)

Beyond the COM interface, the object uses an internal vtable with 150+ function pointers.
Key internal slots used by the rendering pipeline:

| Slot | Offset | Function | Role |
|------|--------|----------|------|
| 24 | 0x060 | `0x10011800` | Alloc framebuffer |
| 26 | 0x068 | `0x10011180` | (init helper) |
| 60 | 0x0F0 | `Transform_PolarCoords @ 10009670` | Per-pixel polar transform |
| 61 | 0x0F4 | `State_SetDefaults @ 10014E80` | Load preset defaults |
| 62 | 0x0F8 | `Transform_PresetCoords @ 100081E0` | Per-pixel coord setup |
| 63 | 0x0FC | `Effect_GenerateTexture @ 10002F60` | Texture double-buffer |
| 64 | 0x100 | `Motion_ComplexPhysics @ 10005F50` | Beat-reactive color |
| 65 | 0x104 | `Effect_Fade2 @ 1000BE50` | Fade/transition |
| 88 | 0x160 | `FUN_10015C30` | Resource/preset data loader |
| 89 | 0x164 | `0x10011A00` | Load preset params |
| 90 | 0x168 | `Geom_RotateZoom @ 10004220` | Rotation/zoom transform |
| 91 | 0x16C | `PerPixelColorBlend @ 10006FF0` | Distance-based alpha |
| 95 | 0x17C | `FUN_10017BC0` | (geom helper) |
| 99 | 0x18C | `0x10014B40` | Allocate temp buffer |
| 103 | 0x19C | `0x10014890` | (motion dispatch) |
| 107 | 0x1AC | `Render_SwapFrameBuffers @ 10016D20` | Swap front/back |
| 118 | 0x1D8 | `Transform_Wrap @ 10004930` | RLE decompress motion |
| 119 | 0x1DC | `Transform_Motion @ 100047E0` | Motion vector apply |
| 122 | 0x1E8 | `FUN_1000F6C0` | **Per-frame render dispatch** |
| 123 | 0x1EC | `FUN_100147D0` | (per-frame helper) |
| 124 | 0x1F0 | `FUN_10017AB0` | (render helper) |
| 126 | 0x1F8 | `FUN_10017FD0` | (blit helper) |
| 127 | 0x1FC | `0x10003CC0` | (blit helper 2) |
| 128 | 0x200 | `Transform_Configure @ 100040D0` | Pipeline: setup offsets |
| 129 | 0x204 | `0x10003870` | Pipeline: palette/color reset |
| 131 | 0x20C | `Render_MipmapChain @ 1000DF50` | Pipeline: mipmap + final blit |
| 132 | 0x210 | `Effect_Brightness @ 1000D500` | Pipeline: sub-pixel copy |
| 133 | 0x214 | `FUN_1000E5F0` | Pipeline: alloc 180×120 buf |
| 134 | 0x218 | `FUN_1000E570` | Pipeline: alloc 350×320 buf |
| 135 | 0x21C | `FUN_1000E670` | Pipeline: alloc 352×320 buf |
| 136 | 0x220 | `FUN_1000E6F0` | Pipeline: alloc 400×300 buf |
| 137-142 | 0x224-0x238 | blend intensity tiers | Pipeline: blend at 3 scales |

---

## 2. Object Allocation & Initialization

### `Create_Visposable2 @ 10011350`

```c
puVar1 = operator_new(0xD0AC);         // 53,420 byte state struct
puVar1[1] = 0;                          // ref count
InitStateDefaults(puVar1 + 2);          // zero-init + load defaults
puVar1[2] = &PTR_LAB_10021848;         // internal vtable 1
puVar1[3] = &PTR_LAB_10021834;         // internal vtable 2
puVar1->unknown_0x9c = &PTR_LAB_100217FC;
*puVar1 = &PTR_FUN_100217F0;           // main vtable
```

Memory layout:
- `+0x00`: vtable pointer (to `PTR_FUN_100217F0`)
- `+0x04`: reference count
- `+0x08`: start of 0xD0A4-byte state block (accessed as `param_1[2]` in functions taking int*)

The state struct fields use two access patterns:
- **Pattern A** (int array): `param_1[field_index]` → byte offset = field_index × 4
- **Pattern B** (byte offset): `*(int*)(param_1 + byte_offset)` → direct byte offset from param_1

---

## 3. Per-Frame Rendering Flow

When WMP calls `IWMPEffects::Render`, the flow is:

### 3.1 Texture_InitRender (entry point)

`Texture_InitRender @ 1000FAE0` — called via vtable slot 6.

**First call initialization** (when `render_height_init == 0`):
```c
*(param_1 + 0xCB84) = 0x15E;    // 350 pixels wide
*(param_1 + 0xCB8C) = 0x140;    // 320 pixels tall
*(param_1 + 0xCA28) = 0x15E;    // stored width
*(param_1 + 0xCA2C) = 0x140;    // stored height
param_1->pixel_col = 0x100;      // 256 (zoom factor?)
param_1->pixel_row = 0x100;      // 256
```
Then calls vtable+0x164, 0x168, 0x178, 0x16C for preset initialization.

**Each frame**: stores viewport rect from `param_4` (RECT*), detects size changes, calls vtable+0x288 for the actual render.

### 3.2 Per-Frame Render Loop (vtable+0x1E8)

`FUN_1000F6C0 @ 1000F6C0` — called 11 times per frame, the main render dispatch.

The per-frame sequence (reconstructed from vtable call patterns):

```
1. vtable+0xF4  → State_SetDefaults:     Load current preset params, copy texture data
2. vtable+0xFC  → Effect_GenerateTexture: Ping-pong between two texture buffers
3. vtable+0xF8  → Transform_PresetCoords: Clear framebuffer, set up coordinate system
4. vtable+0x100 → Motion_ComplexPhysics:  Beat-reactive hue/color processing
5. vtable+0xF0  → Transform_PolarCoords:  Per-pixel polar coordinate transform (main visual)
6. vtable+0x104 → Effect_Fade2:           Fade/transition between frames
7. vtable+0x224-0x238 → Blend (3 intensity tiers): Screen/Multiply/Overlay compositing
8. vtable+0x1AC → Render_SwapFrameBuffers: Swap front/back buffers
```

---

## 4. Per-Pixel Transform Pipeline (Core Visual Behavior)

### 4.1 State_SetDefaults @ 10014E80

Loads the current preset's base parameters into working state:
```c
waveform_data_ptr = *(preset + 0x30EC);        // texture source pointer
transparent_color = *(preset + 0x313C);         // transparent pixel color (ARGB)
total_pixels = preset_width * preset_height;     // total pixel count
```
Then copies texture data with a color offset applied (byte-swap + addition), skipping transparent pixels.

### 4.2 Effect_GenerateTexture @ 10002F60

Manages **double-buffered texture swapping** (ping-pong):

State values at `preset + 0xC5F`: 0 = buffer A→B, 1 = buffer B→A, 2 = buffer A→B.

```c
switch (texHeight) {
  case 0:  // Initialize: use buffer at offset 0xC3B
    framebuffer = preset[0xC60];
    preset[0xC5F] = 1;
    return 1;
  case 1:  // Call Transform_PresetCoords (vtable+0xF8)
    if (preset[0xC99] == 0) { vtable+0xF8(this); }
    framebuffer = preset[0xC99];
    preset[0xC5F] = 2;
    return 1;
  case 2:  // Call alloc (vtable+0xFC)
    if (preset[0xC60] == 0) { vtable+0xFC(this); }
    framebuffer = preset[0xC60];
    preset[0xC5F] = 1;
    return 1;
}
```

### 4.3 Transform_PresetCoords @ 100081E0

**Per-pixel coordinate setup** — runs before the main visual transform.

Key operations:
1. **Clear framebuffer** to `transparent_color`:
```c
total_pixels = preset_width * preset_height;
framebuffer_ptr = framebuffer;
do { *framebuffer_ptr++ = transparent_color; } while (--total_pixels);
```

2. **Compute center offset**:
```c
src_center_x = preset_width / 2 + offset_x;
src_center_y = preset_height / 2 + offset_y;
src_width = preset_width;
```

3. **Load per-preset transform params** from offsets 0xC76-C8F into working registers:
   - Zoom factor, rotation speed, motion vectors
   - Color modulation parameters
   - Animation speed multipliers

4. **Apply audio modulation** when anim_flags == 1 or 2:
```c
if (anim_flags == 1 || anim_flags == 2) {
    zoom *= sin_lut[audio_index];  // modulate by audio spectrum
}
```

### 4.4 Motion_ComplexPhysics @ 10005F50

**Beat-reactive color processing** — the heart of the audio-reactive behavior.

#### Hue Rotation
```c
if (hue_rotation_speed != 0) {
    hue_angle += hue_rotation_speed;
    while (hue_angle > 90) hue_angle -= 90;  // mod 90°
}
```

#### Target Color Blending
```c
if (target_r != 0 || target_g != 0 || target_b != 0) {
    // Load target RGB from per-preset data
    target_r = *(preset + 0x3198);  // red target
    target_g = *(preset + 0x319C);  // green target
    target_b = *(preset + 0x31A0);  // blue target
    
    // Convert to float for interpolation
    target_r_f = (float)target_r;
    target_g_f = (float)target_g;
    target_b_f = (float)target_b;
    
    // Compute blend speed from beat decay
    blend_speed = *(preset + 0x31B8);  // beat decay rate
    if (blend_speed < 0) blend_speed = -blend_speed;
    else blend_speed = 0xFF - blend_speed;
    
    // Apply audio modulation to blend speed
    speed_f = (float)(preset + 0x3194) / 360.0f;
    speed_f *= sin_lut[audio_waveform_index];
}
```

#### Per-Pixel Screen Blend
The pixel loop reads each pixel, decomposes ARGB, applies hue rotation via sin/cos LUT:
```c
pixel = *src++;
if (pixel != transparent_color) {
    alpha = pixel >> 24;
    red   = (pixel >> 16) & 0xFF;
    green = (pixel >> 8) & 0xFF;
    blue  = pixel & 0xFF;
    
    // Apply hue rotation to RGB
    if (hue_angle != 0) {
        red   = rotate_color(red, hue_angle);
        green = rotate_color(green, hue_angle);
        blue  = rotate_color(blue, hue_angle);
    }
    
    // Blend toward target color
    blend_factor = distance_from_center * audio_level;
    red   = lerp(red, target_r, blend_factor);
    green = lerp(green, target_g, blend_factor);
    blue  = lerp(blue, target_b, blend_factor);
    
    // Clamp and write
    *dst++ = (alpha << 24) | (red << 16) | (green << 8) | blue;
}
```

### 4.5 Transform_PolarCoords @ 10009670

**The main visual generator** — the per-pixel loop that creates the actual visual patterns.

This is the most complex function. Per-pixel loop processing:

```c
total_pixels = preset_width * preset_height;
dst_ptr = framebuffer;
src_ptr = waveform_data_ptr;  // source texture
pixel_index = 0;

do {
    current_pixel = *src_ptr;
    
    // Skip transparent pixels (copy as-is)
    if (current_pixel == transparent_color) {
        *dst_ptr = current_pixel;
    } else {
        // Convert to polar coordinates
        pixel_row = pixel_index / src_width;
        pixel_col = pixel_index % src_width;
        
        // Apply vertical scroll/zoom
        if (scroll_factor <= 0) {
            vertical_offset = -(preset_height - pixel_row) * scroll_factor;
        } else {
            vertical_offset = pixel_row * scroll_factor;
        }
        
        // Center-relative coordinates
        pixel_col -= src_center_x;
        pixel_row -= src_center_y;
        
        // Apply stretch factors
        pixel_dx = pixel_col * (1.0f + stretch_x) + pixel_col;
        pixel_dy = pixel_row * (1.0f + stretch_y) + pixel_row;
        
        // Direction filtering (ring/wedge patterns)
        if (direction_filter != 0) {
            abs_dx = abs(pixel_dx);
            abs_dy = abs(pixel_dy);
            if (direction_filter > 0) {
                ratio = (abs_dx > abs_dy) ? abs_dy / abs_dx : abs_dx / abs_dy;
            } else {
                ratio = (abs_dx > abs_dy) ? abs_dy / abs_dx : abs_dx / abs_dy;
                ratio -= floor(ratio);
            }
            // Skip pixels outside the filter band
            if (ratio < -direction_filter || ratio > direction_filter)
                goto write_pixel;
        }
        
        // Radial distance check
        radial_dist = pixel_dx * pixel_dx + pixel_dy * pixel_dy;
        if (ring_radius != 0) {
            if (radial_dist > ring_radius_threshold)
                goto write_pixel;
        }
        
        // Angular position via sin/cos LUT
        angular_pos = radial_dist * angular_scale / angular_divisor + angular_offset;
        angular_pos += angular_speed;
        if (angular_speed > 0) {
            angular_pos = radial_dist * angular_speed;
        } else {
            angular_pos = pixel_dx * pixel_dy * angular_speed;
        }
        
        // Look up color from sin/cos table (base at 0x2F0A)
        angle_index = preset_angle_offset + (int)angular_pos;
        angle_index = abs(angle_index);
        if (angle_index > 360) angle_index %= 360;
        
        // Compute intensity from sin/cos LUT
        intensity = (preset_color_scale + sin_lut[angle_index]) * radial_scale;
        if (intensity <= 0) goto write_pixel;
        
        // Extract current pixel channels
        alpha = current_pixel >> 24;
        red   = (current_pixel >> 16) & 0xFF;
        green = (current_pixel >> 8) & 0xFF;
        blue  = current_pixel & 0xFF;
        
        // Mix RGB toward target colors
        if (target_r != 0)
            red   = lerp(red, target_r_value, intensity);
        if (target_g != 0)
            green = lerp(green, target_g_value, intensity);
        if (target_b != 0)
            blue  = lerp(blue, target_b_value, intensity);
        
        // Alpha modulation
        alpha = alpha + alpha_offset - (int)(intensity * alpha_offset);
        
        // Clamp all channels
        red   = clamp(red, 0, 255);
        green = clamp(green, 0, 255);
        blue  = clamp(blue, 0, 255);
        alpha = clamp(alpha, 0, 255);
        
        // Reconstruct pixel and write
        *dst_ptr = (alpha << 24) | (red << 16) | (green << 8) | blue;
    }
    
    src_ptr++;
    dst_ptr++;
    pixel_index++;
} while (pixel_index < total_pixels);
```

### 4.6 PerPixelColorBlend @ 10006FF0

**Distance-based alpha fading** — fades pixels based on distance from a reference point.

```c
// Early exit if color params haven't changed (change hash check)
change_hash = sum_of_preset_params + 1;
if (waveform_data_ptr[-1] == change_hash) return 0;
waveform_data_ptr[-1] = change_hash;

// Setup
blend_count = alloc_width * alloc_height;
blend_speed = *(preset + 0x31A8);  // pixels per step
fade_ref = *(preset + 0x31A4);     // reference value

if (blend_speed != 0) {
    // Distance-based alpha from center
    ref_distance = abs(fade_ref);
    ref_float = (float)ref_distance;
    step_size = ref_float / (float)blend_speed;
    
    // Adjust for initial position
    if (current_position < blend_speed / 3) {
        ref_float = (blend_speed / 3 - current_position) * step_size + ref_float;
    }
}

// Per-pixel loop: modify alpha based on distance
// Alpha = ref_value - (distance * ref_value / blend_speed)
// Clamped to [0, 255], written to pixel alpha channel
```

### 4.7 Blend_LayerMerge @ 1000AC00

**Multi-layer composition** with 13 motion modes (0-12):

| Mode | X Motion | Y Motion |
|------|----------|----------|
| 0 | dx (linear) | dy (linear) |
| 1 | dx × constant | dy (linear) |
| 2 | dx (linear) | dy × constant |
| 3 | dx × constant | dy × constant |
| 4 | dx² | dy (linear) |
| 5 | dx (linear) | dy² |
| 6 | dx² | dy² |
| 7 | dx × dy | dy (linear) |
| 8 | dx (linear) | dx × dy |
| 9 | dx × dy | dx × dy |
| 10 | dx | dy²/dx |
| 11 | dx²/dy | dy |
| 12 | dx²/dy | dy²/dx |

After mode selection, applies sin/cos modulation from per-preset angle data.

---

## 5. Post-Processing Pipeline (`Effect_RunPipeline`)

`Effect_RunPipeline @ 10014F90` — 6-stage post-processing after per-pixel transforms.

```c
undefined4 Effect_RunPipeline(int *param_1) {
    (**(code **)(*param_1 + 0x200))(param_1);  // Transform_Configure
    (**(code **)(*param_1 + 0x214))(param_1);  // Alloc 180×120 buffer
    (**(code **)(*param_1 + 0x210))(param_1);  // Effect_Brightness
    (**(code **)(*param_1 + 0x204))(param_1);  // Palette/color reset
    (**(code **)(*param_1 + 0x218))(param_1);  // Alloc 350×320 buffer
    (**(code **)(*param_1 + 0x20c))(param_1);  // Render_MipmapChain
    return 0;
}
```

### Stage 1: Transform_Configure @ 100040D0
Computes final output center, motion blur, and zoom for the post-process stage:
```c
center_offset = preset_width / 2 + preset_center_x;
output_center_x = viewport_center + frame_stability;
output_center_y = viewport_y + frame_stability_y;
motion_blur_level = max(blur_a, blur_b);
```

### Stage 2: Allocate 180×120 Intermediate Buffer
`FUN_1000E5F0 @ 1000E5F0`
```c
if (buffer_width != 0xB4 || buffer_height != 0x78) {
    free(current_buffer);
    buffer_width = 0xB4;   // 180
    buffer_height = 0x78;  // 120
    buffer = malloc(0x15180);  // 180 × 120 × 4 = 86,400 bytes
    current_buffer = buffer;
}
```

### Stage 3: Effect_Brightness @ 1000D500
Pixel copy with **sub-pixel precision scaling** from source to intermediate buffer.
Three modes based on source width:
- **Width < 257**: 1:1 copy with carry-based sub-pixel stepping
- **Width 257-512**: 2:1 horizontal scaling (doubles each pixel, skip on carry)
- **Width 513-768**: 3:1 scaling with line doubling

```c
// Sub-pixel Bresenham-style stepping
step_x = (target_width - source_width) << 8;  // 8-bit fixed point
carry = 0;
do {
    *dst++ = *src++;
    carry += step_x;
    if (carry >= 0x100) {
        // Skip or duplicate pixel for scaling
        carry -= 0x100;
    }
} while (--pixel_count);
```

### Stage 4: Palette/Color Reset
`0x10003870` — Small helper that compares two state fields and zeros a third if equal:
```c
if (field_a == field_b) {
    field_c = 0;
}
return 0;
```

### Stage 5: Allocate 350×320 Output Buffer
`FUN_1000E570 @ 1000E570`
```c
if (buffer_width != 0x15E || buffer_height != 0x140) {
    free(current_buffer);
    buffer_width = 0x15E;   // 350
    buffer_height = 0x140;  // 320
    buffer = malloc(0x6D600);  // 350 × 320 × 4 = 448,000 bytes
    current_buffer = buffer;
}
```

### Stage 6: Render_MipmapChain @ 1000DF50
The final rendering stage — generates **mipmap chain** then blits to output.

```c
// Phase 1: Mipmap generation (downsample loop)
while (width >= 0x301 || height >= 0x301) {
    vtable+0xC4(this);  // downsample 2:1
    width <<= 1;
    height <<= 1;
}

// Phase 2: Horizontal stretch
vtable+0x64(this);  // stretch horizontally
vtable+0x64(this);  // stretch vertically

// Phase 3: Final blit with extra border pixels
extra_width = *(preset + 0x31FA);  // border/gutter pixels
final_width = output_width + extra_width;
buffer = malloc(final_width * output_height * 4);
```

---

## 6. Blend Modes

Available blend operations between current and previous frame:

### Blend_Screen @ 1000D020
Screen blend with decay factor:
```c
decay = blend_amount;  // 0x001-0x2FF range
if (decay != 0xFE && decay != 0xFF && decay != 0x100 && decay != 0x101 && decay != 0x102) {
    // Decay old frame position values
    old_x = (old_x << 8) / decay;
    old_y = (old_y << 8) / decay;
}
```

### Blend_Multiply @ 1000D200
Three intensity tiers based on blend amount:
```c
if (blend_amount < 0x100)      vtable+0x224(this);  // tier 1
else if (blend_amount < 0x201) vtable+0x228(this);  // tier 2
else                           vtable+0x22C(this);  // tier 3
// Then swap buffers
vtable+0x1AC(this);  // Render_SwapFrameBuffers
```

### Blend_Overlay @ 1000D2C0
Same 3-tier structure as Multiply, different compositing math.

### Blend_SoftLight @ 1000D380
Soft light blend with same tier pattern.

### Blend_AlphaComposite @ 1000A490
**Spiral alpha pattern** from center of buffer — generates a spiral mask:
```c
// Allocate spiral buffer
buffer = malloc((max_dim + 1) * other_dim * 4);
center = buffer + (total/2 + other_dim/2) * 4;

// Spiral walk: right, up, left, down (repeating)
direction = 0;
do {
    switch (direction) {
        case 0: ptr += 4; break;           // right
        case 1: ptr -= width * 4; break;   // up
        case 2: ptr -= 4; break;           // left
        case 3: ptr += width * 4; break;   // down
    }
    *ptr = pixel_index++;
    
    step_count--;
    if (step_count < 1) {
        direction = (direction + 1) % 4;
        // Increase step length every other cycle
    }
} while (pixel_index < total_pixels);
```

---

## 7. Audio-Rotate Spectrum Buffers

`Audio_RotateSpectrumBuffers @ 100151E0` — called when `hue_rotation_speed != 0xFF`.

Handles triple-buffered spectrum data with Bresenham-style downsampling:
```c
// Rotate between three spectrum buffers
if (buffer_state == 0) {
    src = spectrum_buffer_a;
    buffer_state = 1;
} else if (buffer_state == 1) {
    src = spectrum_buffer_b;
    buffer_state = 2;
} else {
    src = spectrum_buffer_c;
}

// Bresenham downsample from 0x200 (512) to fit
step = (0x200 - target_size) << 8;
carry = 0;
do {
    *dst++ = *src++;
    carry += step;
    if (carry >= 0x100) {
        // Average adjacent samples
        *dst = (src[-1] + src[0]) >> 1;
        dst++;
    }
} while (carry < 0x10000);
```

---

## 8. Preset Data Model

### Per-Preset Data Structure

54 presets max, stride 0x1EC bytes per preset.
Base index in state struct: 0xC39 (Pattern A indexing).

**Access formula** (Pattern A):
```c
preset_field = param_1[preset_idx * 0x7B + field_offset];
// field_offset ranges: 0xC39..0xC9F (within each preset's 0x1EC block)
```

**Access formula** (Pattern B, byte offset):
```c
preset_field = *(int*)(param_1 + 0x30E0 + preset_idx * 0x1EC + field_byte_offset);
```

### Key Per-Preset Fields

| Offset (Pattern A) | Byte Offset | Type | Role |
|---------------------|-------------|------|------|
| 0xC39 | — | int | preset_flags |
| 0xC3B | — | int* | texture_source_a |
| 0xC3D | — | int | buffer_width_a |
| 0xC3E | — | int | buffer_height_a |
| 0xC40 | — | int | blit_x |
| 0xC41 | — | int | blit_y |
| 0xC45 | — | int | buf_width |
| 0xC46 | — | int | buf_height |
| 0xC53 | — | int | preset_width |
| 0xC54 | — | int | preset_height |
| 0xC58 | — | int | rotation_mode |
| 0xC5D | — | int | output_width |
| 0xC5E | — | int | output_height |
| 0xC5F | — | int | texture_state (0/1/2) |
| 0xC60 | — | int* | texture_buffer_b |
| 0xC66 | — | int | target_r_value |
| 0xC67 | — | int | target_g_value |
| 0xC68 | — | int | target_b_value |
| 0xC76 | — | int | center_offset_x |
| 0xC77 | — | int | center_offset_y |
| 0xC79 | — | int | motion_param_a |
| 0xC7A | — | int | motion_param_b |
| 0xC7B | — | int | motion_param_c |
| 0xC7F | — | int | polar_center_x |
| 0xC80 | — | int | polar_center_y |
| 0xC81 | — | int | audio_mod_speed |
| 0xC82 | — | int | angular_base_offset |
| 0xC85 | — | int | polar_rotation_speed |
| 0xC86 | — | int | alpha_offset |
| 0xC88 | — | int | anim_flags_x (0=off, 1=sin, 2=cos) |
| 0xC89 | — | int | anim_flags_y |
| 0xC8B | — | int | anim_flags_z_a |
| 0xC8C | — | int | anim_flags_z_b |
| 0xC8F | — | int | audio_decay_rate |
| 0xC91 | — | int | zoom_audio_mod_a |
| 0xC92 | — | int | zoom_audio_mod_b |
| 0xC94 | — | int | motion_audio_mod |
| 0xC95 | — | int | color_audio_mod |
| 0xC99 | — | int* | texture_buffer_a |

### Per-Preset Extended Fields (Pattern B, 0x1EC stride)

| Byte Offset | Role |
|-------------|------|
| 0x30EC | texture_data_ptr |
| 0x313C | transparent_color |
| 0x3140 | center_x_init |
| 0x3148 | center_y_init |
| 0x314C | alloc_width |
| 0x3150 | alloc_height |
| 0x317C | texture_load_mode (0/1/2) |
| 0x3180 | texture_load_param |
| 0x318C | hue_rotation_speed |
| 0x3190 | audio_level_scale |
| 0x3194 | blend_speed_x |
| 0x3198 | target_r |
| 0x319C | target_g |
| 0x31A0 | target_b |
| 0x31A4 | fade_ref_value |
| 0x31A8 | blend_speed |
| 0x31B4 | beat_decay_a |
| 0x31B8 | beat_decay_b |
| 0x31BC | color_blend_rate |
| 0x31C0 | motion_scale |
| 0x31D4 | sin_lut_index |
| 0x31F0 | layer_merge_type |
| 0x31F4 | layer_offset |
| 0x3234 | motion_mode (0-12) |
| 0x3238 | motion_offset |
| 0x324C | color_mix_rate |
| 0x3274 | audio_source_index |
| 0x32A8 | blend_state_flag |
| 0x32AC | blend_position |

### Preset 2 (Mathical Music) Hard-Coded Values

From `State_InitParams`:
```c
preset[0xD2F] = 9;        // resource type
preset[0xD30] = 4;        // config mode
preset[0xD45] = -1;       // blend_ref = -1 (none)
preset[0xD46] = 0x453;    // width_hint = 1107
preset[0xD47] = -0x1DB;   // height_offset = -475
preset[0xD4B] = 0x58C;    // dimension_param = 1420
preset[0xD2B] = 2;        // type code
preset[0xCF]  = 0x40000000; // 2.0f (float)
preset[0xBA]  = 0x43960000; // 300.0f (float)
preset[0xC3]  = 0x3F800000; // 1.0f (float)
preset[0xC4]  = 0x3F000000; // 0.5f (float)
preset[0xD9D] = 2;        // init_flag
preset[0xD9F] = 1;        // init_flag_2
```

---

## 9. Key Constants & Buffers

| Value | Hex | Meaning |
|-------|-----|---------|
| 350 | 0x15E | Base output width |
| 320 | 0x140 | Base output height |
| 180 | 0xB4 | Intermediate buffer width |
| 120 | 0x78 | Intermediate buffer height |
| 352 | 0x160 | Alternative buffer width |
| 400 | 0x190 | Alternative buffer width |
| 300 | 0x12C | Alternative buffer height |
| 54 | — | Max presets |
| 0x1EC | — | Per-preset struct stride (bytes) |
| 0xD0AC | — | Total state struct size (bytes) |
| 0x2F0A | — | Sin/cos LUT base address (Pattern A index) |
| 0x200 | — | Spectrum width (samples) |
| 0x100 | 256 | Sub-pixel fixed-point scale factor |
| 0x5A | 90 | Hue rotation mod value (degrees) |
| 0x168 | 360 | Full rotation (degrees) |

### Buffer Size Calculations

```
180 × 120 × 4 = 0x15180  (intermediate buffer)
350 × 320 × 4 = 0x6D600  (output buffer)
352 × 320 × 4 = 0x6E000  (alt output buffer)
400 × 300 × 4 = 480000   (alt output buffer)
```

---

## 10. Sin/Cos LUT Usage

The sin/cos lookup table is stored at state offset 0x2F0A (Pattern A index).
Each entry is a 4-byte integer representing a precomputed trigonometric value.

**Index formula**:
```c
index = preset_base_angle + computed_angle;
index = abs(index);
if (index > 360) index %= 360;
value = sin_lut[index];  // state[0x2F0A + index]
```

Used in:
- `Transform_PolarCoords`: Angular position → color lookup
- `Motion_ComplexPhysics`: Hue rotation, audio-reactive modulation
- `Blend_LayerMerge`: Motion mode angle computation

---

## 11. State Field Reference (Identified Fields)

### ARGB Pipeline Fields

| Byte Offset | Pattern A Index | Name | Role |
|-------------|-----------------|------|------|
| 0xCD9C | 0x3367 | blue_channel | Current pixel blue |
| 0xCEAC | 0x33AB | green_channel | Current pixel green |
| 0xCD68 | — | alpha_channel | Current pixel alpha |
| 0xCF44 | — | red_channel | Current pixel red |
| 0xCF48 | — | red_accum | Red accumulator |
| 0xCF70 | — | transparent_color | Transparent pixel value |

### Pixel Iteration Fields

| Byte Offset | Pattern A Index | Name | Role |
|-------------|-----------------|------|------|
| 0xCBC4 | — | pixel_col | Current column |
| 0xCBC8 | — | pixel_row | Current row |
| 0xCBCC | — | pixel_dx | Delta X from center |
| 0xCBD0 | — | pixel_dy | Delta Y from center |
| 0xCBE0 | — | direction_ratio | Direction filter ratio |
| 0xCA18 | — | pixel_index | Current pixel index |
| 0xD040 | — | total_pixels | Total pixel count |

### Buffer/Blit Fields

| Byte Offset | Pattern A Index | Name | Role |
|-------------|-----------------|------|------|
| 0xC808 | — | dst_pixel_ptr | Destination pixel pointer |
| 0xC810 | — | src_read_ptr | Source read pointer |
| 0xC814 | — | src_pixel_ptr | Source pixel pointer |
| 0xC818 | — | audio_spectrum_ptr | Audio spectrum data |
| 0xC858 | — | spectrum_read_ptr | Spectrum read pointer |
| 0xCF40 | — | src_width | Source width |
| 0xC994 | — | src_height | Source height |
| 0xCDA4 | — | shadow_radius | Shadow/glow radius |
| 0xCDDC | — | dst_y | Destination Y offset |
| 0xD018 | — | blend_pass_count | Blend pass count |
| 0xD058 | — | row_copy_counter | Row copy counter |

### Center/Transform Fields

| Byte Offset | Pattern A Index | Name | Role |
|-------------|-----------------|------|------|
| 0xC8CC | — | src_center_x | Source center X |
| 0xC8D4 | — | src_center_y | Source center Y |
| 0xCD88 | — | output_center_x | Output center X |
| 0xCD90 | — | output_center_y | Output center Y |

### Motion/Physics Fields

| Byte Offset | Pattern A Index | Name | Role |
|-------------|-----------------|------|------|
| 0xCFC4 | — | target_b_f | Target blue (float) |
| 0xCFCC | — | target_g_f | Target green (float) |
| 0xCFD0 | — | target_r_f | Target red (float) |
| 0xCBB0 | — | blend_speed_val | Blend speed value |
| 0xCBA8 | — | pixel_blend_count | Pixels to blend |
| 0xCB90 | — | motion_scale_f | Motion scale (float) |
| 0xCB98 | — | motion_scale_y | Motion scale Y |
| 0xCE48 | — | blend_amount | Blend amount (0x001-0x2FF) |
| 0xCE50 | — | alloc_width | Allocation width |
| 0xCE5C | — | alloc_height | Allocation height |
| 0xCE70 | — | audio_level_f | Audio level (float) |
| 0xCEC0 | — | hue_angle | Current hue angle |
| 0xD098 | — | max_blur_level | Max blur level |
| 0xCDE4 | — | frame_stability_y | Frame stability Y |

### Frame Buffer Fields

| Byte Offset | Pattern A Index | Name | Role |
|-------------|-----------------|------|------|
| 0xC814 | — | active_framebuffer | Active framebuffer pointer |
| 0xC858 | — | spectrum_buffer | Spectrum data buffer |
| 0xCAAC | — | framebuffer_copy | Framebuffer copy pointer |
| 0xCAAB | — | work_buffer | Working buffer |
| 0xCAB8 | — | alpha_composite_buf | Alpha composite buffer |
| 0xCA90 | — | blur_level_a | Blur level A |
| 0xCA94 | — | blur_level_b | Blur level B |
| 0xCC18 | — | output_width | Output buffer width |
| 0xCC20 | — | output_height | Output buffer height |
| 0xCC58 | — | display_width | Display width |
| 0xCC5C | — | display_height | Display height |
| 0xCC88 | — | border_color | Border/gutter color |
| 0xCCD0 | — | sub_pixel_accum | Sub-pixel accumulator |
| 0xCCB8 | — | sub_pixel_step | Sub-pixel step |

---

## 12. File References

| File | Path |
|------|------|
| TrilogyII decompiled | `visualization/presets/Trilogy-II/decompiled/TrilogyII_decompiled.c` |
| TrilogyI decompiled | `visualization/presets/Trilogy-I/decompiled/TrilogyI_decompiled.c` |
| TrilogyIII decompiled | `visualization/presets/Trilogy-III/decompiled/TrilogyIII_decompiled.c` |
| Raw Ghidra output | `trilogy-ii-extracted/output/decompiled_TrilogyII.txt` |
| State struct header | `visualization/presets/Trilogy-I/decompiled/trilogy_state.h` |
| Rename functions | `visualization/tools/rename_decompiled.py` |
| Rename variables | `visualization/tools/rename_variables.py` |
| Struct field substitution | `visualization/tools/apply_struct_fields.py` |
| WMP SDK effects.h | `wmp-sdk-extracted/effects.h` |
| Windows SDK headers | `winsdk-include/` |

### Note on TrilogyI vs TrilogyIII

TrilogyI and TrilogyIII are **functionally identical** — same code, same addresses, same file size (167,936 bytes). Only difference is a 0x10 byte shift in .data section globals. TrilogyII is a genuinely different build (172,032 bytes, +4KB) with 6 extra utility functions and shifted addresses.
