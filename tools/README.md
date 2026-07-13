# Tools for WMP Viz Porting

## projectm-screenshot.patch

Adds screenshot capture to ProjectM 4.x. Two new API functions:

- `projectm_take_screenshot(handle, filename)` — captures the currently bound
  framebuffer (call after `projectm_opengl_render_frame()`). Writes BMP.
- `projectm_write_debug_image_on_next_frame(handle, filename)` — implemented the
  previously-stubbed API, captures the next rendered frame.

The SDL test UI adds:
- `F12` keybinding for interactive screenshot
- `--preset`, `--screenshot`, `--frames` CLI args for automated testing

**Apply**: `cd /path/to/projectm && git apply tools/projectm-screenshot.patch`

**License**: LGPL 2.1 (same as projectM) — see LICENSE.txt

## compare_screenshots.py

Compares a ProjectM screenshot against an original WMP screenshot.
Computes SSIM, MSE, histogram correlation. Generates diff overlays.

```
python3 compare_screenshots.py projectm_output.bmp original.jpg
python3 compare_screenshots.py --dir screenshots/ originals/ --threshold 0.7
```

**Requirements**: See `requirements.txt`. Install: `pip install -r requirements.txt`

**License**: LGPL 2.1 (same as projectM)

## validate_milk.py

Python syntax validator for `.milk` preset files.

## validate_preset.cpp / test_parser.cpp

C++ validators for `.milk` presets (require projectM build).
