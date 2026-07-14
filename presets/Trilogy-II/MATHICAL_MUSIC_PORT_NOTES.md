# Mathical Music — WMP→MilkDrop Port: Findings & Assumptions

Status: **Draft** — needs validation via rendering comparison

---

## 1. What the Decompiler Reveals

### 1.1 Rendering Pipeline (per frame)

```
IWMPEffects_Render (10001E50)
  └─ for each active preset in list at state[0x269F]:
       └─ vtable+0x188 → per-preset render entry

Render_MainLoop (10001000)
  ├─ Clear staging buffer with clear_color
  ├─ vtable+0x260 → Allocate/Setup textures
  ├─ vtable+0x50  → Init render pass
  ├─ if single_preset_mode:
  │    ├─ vtable+0x148 → Render preset (includes Transform_PolarCoords)
  │    └─ vtable+0xC8  → Present to screen
  └─ else (multi-pass):
       └─ while render_pass_count != 1:
            ├─ malloc work buffer
            ├─ vtable+0x128 → Blur (Effect_GaussianBlur)
            ├─ vtable+0x15C → Post-process (Effect_RunPipeline)
            ├─ vtable+0xC8  → Present
            └─ free work buffer
```

### 1.2 Effect_GenerateTexture (10002F60) — Double-Buffer Ping-Pong

**Finding**: This function does NOT generate content. It only swaps buffer pointers.

```
state_flag == 0: waveform_data_ptr = buffer_A, framebuffer = buffer_B, flag → 1
state_flag == 1: waveform_data_ptr = buffer_B, framebuffer = buffer_C, flag → 2
state_flag == 2: waveform_data_ptr = buffer_C, framebuffer = buffer_B, flag → 1
```

Buffers are at per-preset offsets: `0xc3b` (A), `0xc60` (B), `0xc99` (C).

**Assumption**: The initial buffer content comes from `State_SetDefaults` which copies
resource data with a color shift applied per-pixel.

### 1.3 Transform_PolarCoords (10009670) — Per-Pixel Loop

**Finding**: This is the core visual algorithm. For each pixel in the source texture:

1. **Transparent pass-through**: If `src_pixel == transparent_color`, copy unchanged
2. **Polar coords**: Compute row/col, center-relative, apply stretch
3. **Direction filter**: Ring (ratio check) or wedge (frac check) based on `float_param[0x39]`
4. **Radial gate**: Skip if dist outside `radius_threshold = float_param[0x30]² * 2`
5. **Angular position**: `angle = dist² * ang_scale / div + ang_offset + accumulated_angle`
6. **Sin/cos LUT**: `intensity = (color_scale + sin_lut[angle]) * radial_scale`
7. **RGB lerp**: `channel = lerp(src_channel, target_channel, intensity)`
8. **Alpha modulation**, clamp, write

**Critical**: The source pixel's RGB is USED in the output. The transform does NOT
generate colors from scratch — it MODULATES existing colors based on position.

### 1.4 State_InitParams (10015CD0) — Hardcoded Per-Preset Values

**Finding**: 6 presets (0–5) initialized with hardcoded parameters. Key values for
preset 2 (Mathical Music): `init_flag=2, stretch_y=2, stretch_x=9, ang_scale=4,
dir_filter=-1, center_x=1314, center_y=-401, dimension=1420`.

After hardcoding, calls `vtable+0x160` per preset (likely loads resource data).

### 1.5 State_SetDefaults (10014E80) — Color-Shifted Copy

**Finding**: NOT just defaults — performs a per-pixel color transformation:
- Reads source texture from resource data
- For each pixel: if not transparent, add `bg_add` (byte-swapped color)
- Overflow clamps to transparent color
- Writes to working buffer

**Assumption**: This provides the initial texture content that the feedback loop
then evolves.

---

## 2. Key Insight: Feedback System

The WMP visualizer is a **feedback system**, not a pattern generator.

```
Frame N:   Read buffer A → Transform_PolarCoords → Write buffer B
Frame N+1: Read buffer B → Transform_PolarCoords → Write buffer A
Frame N+2: Read buffer A → Transform_PolarCoords → Write buffer B
...
```

The "concentric rings" visual emerges from the feedback loop:
1. Initial texture has some base pattern (from resource data)
2. Transform_PolarCoords modulates each pixel's color based on position
3. Over many frames, position-dependent modulation accumulates
4. The ring pattern becomes dominant through constructive interference

**This is NOT**: Generating rings from mathematical formulas
**This IS**: Position-dependent color modulation + feedback accumulation

---

## 3. MilkDrop Mapping

### 3.1 Feedback → fDecay

WMP's double-buffer ping-pong maps directly to MilkDrop's `fDecay`:
- `fDecay = 0.96` provides 4% frame retention
- Each frame builds on the previous frame's output
- The ring pattern accumulates over time

### 3.2 Transform_PolarCoords → Warp Shader

The per-pixel transform maps to MilkDrop's warp shader:
- Compute distance from center
- Apply stretch factors
- Direction filter (ring/wedge)
- Radial gate
- Angular modulation via sin/cos
- Color modulation

### 3.3 Effect_RunPipeline → Composite Shader

The post-processing pipeline maps to MilkDrop's composite shader:
- Brightness adjustment
- Palette lookup
- Screen blend mode

### 3.4 Current .milk Implementation

The current implementation uses:
- **Warp shader**: Position-dependent modulation (distance, angle, stretch)
- **Composite shader**: Simple passthrough (`ret = tex2D(sampler, uv)`)
- **fDecay**: 0.96 for feedback accumulation

**Assumption**: The warp shader's position-dependent modulation, combined with
fDecay feedback, will build up the ring pattern over time.

---

## 4. Unknowns & Risks

### 4.1 Initial Texture Content
- **Unknown**: What exactly is in the resource data loaded by `State_SetDefaults`
- **Risk**: Without the correct initial pattern, the feedback loop may not produce rings
- **Mitigation**: MilkDrop starts with a black screen, which may be sufficient

### 4.2 Per-Preset Parameter Values
- **Unknown**: Exact float values for all parameters (only integer部分 visible in decompiled code)
- **Risk**: Wrong parameter values may produce different visual
- **Mitigation**: Parameters can be tuned empirically

### 4.3 Vtable+0x160 Function
- **Unknown**: What this function does (called after each preset init)
- **Risk**: May load critical texture data or apply transformations
- **Mitigation**: Visual comparison will reveal if missing

### 4.4 Multi-Pass Rendering
- **Unknown**: Exact blur/post-processing parameters
- **Risk**: May affect visual appearance
- **Mitigation**: MilkDrop has its own blur/post-processing

### 4.5 Sin/Cos LUT Values
- **Finding**: LUT is at state offset 0xBC28, 360 entries
- **Assumption**: Standard sin(i * pi/180) for i = 0..359
- **Risk**: May have non-standard values (e.g., scaled, offset)
- **Mitigation**: Standard sin/cos should be close enough

---

## 5. Validation Plan

1. **Render** the .milk file with ProjectM
2. **Compare** with original WMP screenshot using SSIM/MSE
3. **Iterate** if score is low:
   - Check if feedback is working (rings should build up over time)
   - Tune fDecay if rings don't accumulate
   - Tune warp shader parameters if rings are wrong shape
   - Check composite shader if colors are wrong

---

## 6. Files

- `mathical_music.milk` — Current MilkDrop preset
- `TRANSFORM_POLARCOORDS_ANALYSIS.md` — Detailed algorithm analysis
- `decompiled/TrilogyII_decompiled.c` — Renamed decompiled code
- `decompiled/trilogy_state.h` — State struct definition
