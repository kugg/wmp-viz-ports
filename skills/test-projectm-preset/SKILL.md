---
name: test-projectm-preset
description: Test and validate ProjectM .milk presets using the screenshot capture tools. Triggers on: test preset, validate milk, compare screenshot, run projectm.
---

# Test ProjectM Presets

Workflow for validating, rendering, and comparing .milk presets against original WMP screenshots.

## Prerequisites

| Tool | Location | Notes |
|------|----------|-------|
| **ProjectM build** | `~/devel/milky/projectm/build/` | Arm64 core + x86_64 SDL2 test UI |
| **Test UI binary** | `~/devel/milky/projectm/build/src/sdl-test-ui/projectM-Test-UI` | Takes screenshots via CLI |
| **Python venv** | `~/devel/milky/venv/` | For compare_screenshots.py |
| **Screenshot patch** | `~/devel/milky/visualization/tools/projectm-screenshot.patch` | Must be applied to ProjectM source |

## Quick Reference

### Validate Syntax

```bash
cd ~/devel/milky
venv/bin/python3 validate_milk.py path/to/preset.milk
```

Output: `0 errors, 0 warnings` = good.

### Render Screenshot (Headless)

```bash
cd ~/devel/milky
projectm/build/src/sdl-test-ui/projectM-Test-UI \
  --preset path/to/preset.milk \
  --screenshot projectm_out.bmp \
  --frames 60
```

- `--frames 60` = render 60 frames then capture (gives time for animation to settle)
- Output is a BMP file at the path specified
- Window opens briefly then closes automatically

### Render with Audio (Interactive)

```bash
cd ~/devel/milky
projectm/build/src/sdl-test-ui/projectM-Test-UI \
  --preset path/to/preset.milk
```

- Window stays open, captures live audio from system default input
- Press **F12** to take a screenshot (saved as BMP in current directory)
- Press **number keys** (0-9) to cycle through presets in the presets directory
- Press **F** to toggle fullscreen
- Press **Q** or **Esc** to quit

### Compare Screenshots

```bash
cd ~/devel/milky
venv/bin/python3 visualization/tools/compare_screenshots.py \
  projectm_out.bmp \
  path/to/original_screenshot.jpg
```

Metrics:
- **SSIM**: Structural similarity (1.0 = identical, 0.0 = completely different)
- **MSE**: Mean squared error (0.0 = identical, higher = worse)
- **Hist**: Histogram correlation (1.0 = identical color distribution)

Typical scores for good visual approximation: SSIM > 0.4

### Batch Compare

```bash
cd ~/devel/milky
venv/bin/python3 visualization/tools/compare_screenshots.py \
  --dir projectm_outputs/ original_screenshots/ \
  --out-dir diffs/
```

## Full Workflow

### 1. Create Preset

Write the `.milk` file in `visualization/presets/<VizName>/`.

### 2. Validate Syntax

```bash
venv/bin/python3 validate_milk.py visualization/presets/<VizName>/preset.milk
```

Fix any errors before proceeding.

### 3. Copy to ProjectM Presets Directory

```bash
cp visualization/presets/<VizName>/preset.milk ~/.projectM/presets/
```

### 4. Render Test Screenshot

```bash
projectm/build/src/sdl-test-ui/projectM-Test-UI \
  --preset ~/.projectM/presets/preset.milk \
  --screenshot projectm_out.bmp \
  --frames 60
```

### 5. Compare with Original

```bash
venv/bin/python3 visualization/tools/compare_screenshots.py \
  projectm_out.bmp \
  research/<VizName>/screenshots/Original.jpg
```

### 6. Iterate

Adjust preset, re-render, re-compare until satisfied.

### 7. Commit

```bash
cd ~/devel/milky/visualization
git add presets/<VizName>/preset.milk
git commit -m "Add preset name"
git push origin main
```

## Interactive Testing (With Audio)

When you want to hear/see the preset react to real audio:

```bash
# Kill any existing instances first
pkill -f projectM-Test-UI

# Launch with your presets directory
cd ~/devel/milky
projectm/build/src/sdl-test-ui/projectM-Test-UI
```

The test UI reads presets from `~/.projectM/presets/` based on the config at `~/.projectM/config.inp`.

Key bindings:
- **1-9**: Switch to preset by number
- **F12**: Take screenshot
- **F**: Toggle fullscreen
- **Q/Esc**: Quit

## Troubleshooting

### Black screen

- Check `MILKDROP_PRESET_VERSION=201` header is present
- Check `PSVERSION=2` and `PSVERSION_COMP=2` for composite shaders
- Check `fDecay` is not 0.0 (causes instant black)
- Check `per_frame_1=warp = 0;` if using custom waveforms

### Preset not found

- Verify file is in `~/.projectM/presets/`
- Check `~/.projectM/config.inp` has `Preset Path = presets`

### Screenshot is all black

- Increase `--frames` to give animation time to render
- Check audio capture is working (look for "Opened audio capture device" in output)
- For spectrum presets, audio input is required for visible output

### Comparison scores low

- Check image dimensions match (tool auto-resizes but large differences affect SSIM)
- Verify you're comparing the right preset against the right original
- SSIM < 0.3 usually means the visual pattern is fundamentally different

## File Locations

```
~/devel/milky/
├── projectm/                          # ProjectM source + build
│   └── build/src/sdl-test-ui/
│       └── projectM-Test-UI          # Test UI binary
├── visualization/
│   ├── presets/<VizName>/*.milk      # Your presets
│   ├── tools/
│   │   ├── compare_screenshots.py    # Screenshot comparison
│   │   ├── projectm-screenshot.patch # Adds screenshot API
│   │   └── requirements.txt         # Python deps
│   └── skills/
│       └── port-wmp-viz/SKILL.md    # Porting workflow
├── research/<VizName>/screenshots/  # Original WMP screenshots
├── venv/                            # Python virtualenv
└── validate_milk.py                 # Syntax validator
```
