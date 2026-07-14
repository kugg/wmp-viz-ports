# Transform_PolarCoords: Complete Algorithm Analysis

Source: `TrilogyII_decompiled.c:3302` (Transform_PolarCoords @ 10009670)

## Per-Pixel Loop: Step-by-Step

For each pixel in the source texture (waveform_data_ptr):

### 1. Skip transparent pixels
```
if (src_pixel == transparent_color):
    dst_pixel = src_pixel   // copy as-is, no transform
    continue
```

### 2. Compute row/col from linear index
```
row = pixel_index / src_width
col = pixel_index % src_width
```

### 3. Vertical scroll/zoom factor
```
if (float_param[0x3a] <= 0):
    scroll = -(height - row) * float_param[0x3a]   // scrolls up
else:
    scroll = row * float_param[0x3a]                // scrolls down
```

### 4. Center-relative coordinates
```
col = col - src_center_x    // src_center_x = width/2 + offset_x
row = row - src_center_y    // src_center_y = height/2 + offset_y
```

### 5. Apply stretch factors
```
pixel_dx = col * (1.0 + float_param[0x33]) + col
pixel_dy = row * (1.0 + float_param[0x32]) + row
```
Equivalent to: `pixel_dx = col * (2.0 + stretch_x)`, `pixel_dy = row * (2.0 + stretch_y)`

### 6. Direction filtering (if float_param[0x39] != 0)
```
abs_dx = abs(pixel_dx)
abs_dy = abs(pixel_dy)

if (float_param[0x39] > 0):
    // Ring filter: ratio of min/max
    ratio = min(abs_dx, abs_dy) / max(abs_dx, abs_dy)
    if (ratio <= float_param[0x39]):
        goto SKIP_PIXEL    // pixel is inside the ring
else:
    // Wedge filter: fractional part of ratio
    ratio = min(abs_dx, abs_dy) / max(abs_dx, abs_dy)
    frac = ratio - floor(ratio)
    if (frac <= |float_param[0x39]| OR (1.0 - frac) <= |float_param[0x39]|):
        goto SKIP_PIXEL    // pixel is inside the wedge
```

### 7. Radial distance check
```
pixel_dx = pixel_dx * pixel_dx    // now pixel_dx is dx²
pixel_dy = pixel_dy * pixel_dy    // now pixel_dy is dy²
radius_sq = pixel_dx + pixel_dy   // total squared distance

if (float_param[0x30] <= 0):
    if (radius_threshold < radius_sq): goto SKIP_PIXEL
else:
    if (radius_threshold >= radius_sq): goto SKIP_PIXEL
```
`radius_threshold = float_param[0x30]² * 2` (precomputed at init)

### 8. Vertical scroll gate
```
if (float_param[0x3a] != 0 AND scroll < radius_sq):
    goto SKIP_PIXEL
```

### 9. Compute angular position
```
angular_pos = radius_sq * float_param[0x34] / angular_divisor + angular_offset
angular_pos += angular_accumulator    // accumulated per-frame

if (float_param[0x3c] > 0):
    angular_pos = radius_sq * angular_accumulator    // radial-dependent angle
else:
    angular_pos = pixel_dx * pixel_dy * angular_accumulator  // product-dependent angle
```

### 10. Look up sin/cos LUT
```
angle_index = preset_angular_offset + angular_pos
angle_index = abs(angle_index)
if (angle_index > 360): angle_index %= 360

intensity = (float_param[0x35] + sin_lut[angle_index]) * radial_scale
if (intensity <= 0): goto SKIP_PIXEL
```
**sin_lut** = 360-entry float table at state offset 0xBC28 = sin(i * pi/180) for i=0..359

### 11. Extract source pixel channels
```
alpha = src_pixel >> 24
red   = (src_pixel >> 16) & 0xFF
green = (src_pixel >> 8) & 0xFF
blue  = src_pixel & 0xFF
```

### 12. Mix RGB toward target colors
```
if (target_r != 0): red   = lerp(red, target_r_value, intensity)
if (target_g != 0): green = lerp(green, target_g_value, intensity)
if (target_b != 0): blue  = lerp(blue, target_b_value, intensity)
```
Where `lerp(a, b, t) = (b - a) * t + a`

### 13. Alpha modulation
```
alpha = alpha + alpha_offset - (int)(intensity * alpha_offset)
```

### 14. Clamp and write
```
red   = clamp(red, 0, 255)
green = clamp(green, 0, 255)
blue  = clamp(blue, 0, 255)
alpha = clamp(alpha, 0, 255)
dst_pixel = (alpha << 24) | (red << 16) | (green << 8) | blue
```

---

## Parameter Summary Table

| Float Param | Index | Role | MilkDrop Equivalent |
|-------------|-------|------|---------------------|
| float_param[0x30] | 0 | **Radius threshold** — max distance from center | `dist` comparison |
| float_param[0x32] | 2 | **Stretch Y** — vertical axis scale | `y * (1+stretch)` |
| float_param[0x33] | 3 | **Stretch X** — horizontal axis scale | `x * (1+stretch)` |
| float_param[0x34] | 4 | **Angular scale** — multiplier for angle computation | `ang * scale` |
| float_param[0x35] | 5 | **Color scale** — base intensity offset | `intensity_base` |
| float_param[0x39] | 9 | **Direction filter** — ring/wedge threshold | `step/ratio` check |
| float_param[0x3a] | 10 | **Scroll factor** — vertical motion | `dy` or time-based |
| float_param[0x3b] | 11 | **Texture sample flag** — if nonzero, samples from texture | `tex2D()` |
| float_param[0x3c] | 12 | **Angular speed** — animation rate | `time * speed` |

---

## Key Insight: The Source Texture IS the Visual

The `do { ... } while` loop in Transform_PolarCoords:

1. Reads each pixel from `waveform_data_ptr` (the source texture)
2. **Skips transparent pixels** — they pass through unchanged
3. **Transforms non-transparent pixels** — applies polar transform, direction filter, RGB mix

**This means the visual pattern comes from the SOURCE TEXTURE, not from the per-pixel math alone.**

The per-pixel math:
- Filters which pixels are visible (radial gate, direction filter)
- Modulates their color (RGB lerp toward target)
- Does NOT generate the pattern from scratch

The source texture is generated by `Effect_GenerateTexture` which:
- Double-buffers between two framebuffers
- Reads from one, writes to the other
- The "read" content comes from the PREVIOUS FRAME's output

**This is a FEEDBACK LOOP:**
1. Frame N: Read texture A → Transform_PolarCoords → Write to buffer B
2. Frame N+1: Read texture B → Transform_PolarCoords → Write to buffer A
3. The pattern EVOLVES each frame through the feedback

---

## What This Means for MilkDrop Porting

The WMP visualizer is NOT:
- Generating concentric rings from mathematical formulas
- Using per-pixel equations to create patterns

The WMP visualizer IS:
- Taking a source texture (which may be a simple gradient, noise, or initial pattern)
- Applying polar coordinate transforms with feedback
- The feedback loop creates the evolving visual over time

For MilkDrop, this maps to:
- **Per-pixel equations**: Apply the polar transform to the texture
- **Feedback**: MilkDrop's `fDecay` provides natural feedback
- **Source texture**: Use a sampler or generate procedurally

The "concentric rings" visual emerges from the FEEDBACK LOOP, not from explicit ring equations.

---

## Effect_GenerateTexture @ 10002F60: Double-Buffer Ping-Pong

```c
Effect_GenerateTexture(param_1):
    texWidth = param_1->current_preset
    state_flag = param_1[texWidth * 0x7b + 0xc5f]
    
    if (state_flag == 0):  // First call or reset
        waveform_data_ptr = param_1[texWidth * 0x7b + 0xc3b]  // buffer A
        if (param_1[texWidth * 0x7b + 0xc60] != 0):  // buffer B exists
            framebuffer = param_1[texWidth * 0x7b + 0xc60]
            state_flag = 1
            return 1
        // Allocate buffer B via vtable+0xFC
        vtable[0xFC](param_1)
        if (framebuffer != 0):
            framebuffer = param_1[texWidth * 0x7b + 0xc60]
            state_flag = 1
            return 1
    
    elif (state_flag == 1):  // Read from B, write to C
        waveform_data_ptr = param_1[texWidth * 0x7b + 0xc60]
        // Allocate buffer C via vtable+0xF8 if needed
        framebuffer = param_1[texWidth * 0x7b + 0xc99]
        state_flag = 2
        return 1
    
    elif (state_flag == 2):  // Read from C, write to B
        waveform_data_ptr = param_1[texWidth * 0x7b + 0xc99]
        // Allocate buffer B via vtable+0xFC if needed
        framebuffer = param_1[texWidth * 0x7b + 0xc60]
        state_flag = 1
        return 1
```

**Key**: This is purely a pointer swap. No content is generated. The pattern comes from Transform_PolarCoords modifying the pixels.

---

## State_InitParams @ 10015CD0: Hardcoded Per-Preset Values

Initializes 6 presets (0-5) with hardcoded parameters:

| Preset | init_flag | stretch_y | stretch_x | ang_scale | dir_filter | center_x | center_y | dimension |
|--------|-----------|-----------|-----------|-----------|------------|----------|----------|-----------|
| 0 | 2 | 2 | 9 | 4 | -1 | 1314 | -401 | 1420 |
| 1 | 2 | 9 | 4 | -1 | 1420 | -401 | 1420 | - |
| 2 | 2 | 9 | 4 | -1 | 1420 | -401 | 1420 | - |
| 3 | 2 | 9 | 4 | 0 | 1420 | -401 | 1420 | - |
| 4 | 2 | 9 | 4 | 0 | 1420 | -401 | 1420 | - |
| 5 | 2 | 9 | 4 | -1 | 1420 | -31 | 1420 | - |

After hardcoding, calls vtable+0x160 for each preset (likely loads additional resource data).

---

## State_SetDefaults @ 10014E80: Per-Pixel Color Transformation

Does NOT just set defaults — performs a per-pixel color shift on the texture data:

```c
State_SetDefaults(param_1):
    // Read per-preset params (stride 0x1EC, NOT 0x7b!)
    waveform_data_ptr = *(param_1 + 0x30ec + current_preset * 0x1ec)
    transparent_color = *(iVar4 + 0x313c)
    total_pixels = *(iVar4 + 0x3150) * *(iVar4 + 0x314c)  // height * width
    
    // Read texture data pointer
    cd5c = *(iVar4 + 0x30ec)
    
    // Check texture source type
    if (*(iVar4 + 0x317c) == 1):  // type 1: use first pointer
        iVar4 = *(iVar4 + 0x3180)
    elif (*(iVar4 + 0x317c) == 2):  // type 2: use second pointer
        iVar4 = *(iVar4 + 0x3264)
    
    // Copy texture data to working buffer with color shift
    src = *(cd5c)  // source texture data
    dst = *(c814)  // working buffer
    count = total_pixels
    bg_add = cdb4  // background color addition (byte-swapped)
    
    for each pixel:
        pixel = *src
        if (pixel != transparent_color):
            pixel = pixel + bg_add  // color shift
            if (carry): pixel = transparent_color  // overflow: clamp
        *dst = pixel
        src++; dst++; count--
    
    // Clear texture source type
    *(0x317c + current_preset * 0x1ec) = 0
```

This initializes the working buffer with shifted colors from the resource data.

---

## Render_MainLoop @ 10001000: Multi-Pass Rendering

```c
Render_MainLoop(param_1):
    // Clear staging buffer with clear_color
    frame_stride = frame_width * 4
    center_x = main_width / 2
    center_y = main_height / 2
    for each pixel: *dst++ = clear_color
    
    // Allocate textures (vtable+0x260)
    vtable[0x260](param_1)
    // Setup (vtable+0x50)
    vtable[0x50](param_1)
    
    if (single_preset_mode):
        active_framebuffer = staging_buffer
        vtable[0x148](param_1)  // Render single preset
        if (render_flag): vtable[0xC8](param_1)  // Present
        return
    
    // Multi-pass rendering loop
    while (render_pass_count != 1):
        work_buffer = malloc(buf_width * buf_height * 4)
        active_framebuffer = work_buffer
        vtable[0x128](param_1)  // Blur
        vtable[0x15c](param_1)  // Post-process
        vtable[0xC8](param_1)   // Present
        free(work_buffer)
        vtable[0x44](param_1)  // Next pass
    
    // Final pass
    vtable[0x3c](param_1)
    while (termination_flag != 1):
        work_buffer = malloc(buf_width * buf_height * 4)
        active_framebuffer = work_buffer
        vtable[0x128](param_1)  // Blur
        vtable[0x15c](param_1)  // Post-process
        vtable[0xC8](param_1)   // Present
        free(work_buffer)
        vtable[0x3c](param_1)   // Next pass
```

**Key**: Multi-pass rendering with blur and post-processing creates the evolving visual over time.
