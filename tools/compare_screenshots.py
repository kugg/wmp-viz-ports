#!/usr/bin/env python3
"""
projectM -- Milkdrop-esque visualisation SDK
Copyright (C)2003-2025 projectM Team

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

Compare a ProjectM screenshot against an original WMP screenshot.
Computes SSIM, MSE, and histogram correlation. Generates a diff overlay.

Usage:
    python3 compare_screenshots.py projectm_screenshot.bmp original_screenshot.jpg
    python3 compare_screenshots.py --dir screenshots/ originals/
    python3 compare_screenshots.py --threshold 0.7 a.bmp b.jpg
"""

import argparse
import os
import sys
import warnings

import numpy as np
from PIL import Image

warnings.filterwarnings("ignore", category=UserWarning)

try:
    from skimage.metrics import structural_similarity as ssim
    HAS_SSIM = True
except ImportError:
    HAS_SSIM = False


def load_image(path: str, max_size: tuple = (800, 800)) -> np.ndarray:
    img = Image.open(path).convert("RGB")
    if img.width > max_size[0] or img.height > max_size[1]:
        img.thumbnail(max_size, Image.LANCZOS)
    return np.array(img, dtype=np.float32) / 255.0


def compute_mse(a: np.ndarray, b: np.ndarray) -> float:
    return float(np.mean((a - b) ** 2))


def compute_histogram_correlation(a: np.ndarray, b: np.ndarray) -> float:
    scores = []
    for c in range(3):
        ha, _ = np.histogram(a[:, :, c], bins=64, range=(0, 1))
        hb, _ = np.histogram(b[:, :, c], bins=64, range=(0, 1))
        ha = ha.astype(np.float64)
        hb = hb.astype(np.float64)
        ha -= ha.mean()
        hb -= hb.mean()
        num = np.dot(ha, hb)
        den = np.sqrt(np.dot(ha, ha) * np.dot(hb, hb))
        scores.append(abs(num / den) if den > 0 else 0.0)
    return float(np.mean(scores))


def generate_diff(a: np.ndarray, b: np.ndarray, out_path: str):
    diff = np.abs(a - b)
    mask = np.max(diff, axis=2) > 0.05
    overlay = np.stack([
        np.clip(b[:, :, 0] + mask.astype(np.float32) * 0.6, 0, 1),
        b[:, :, 1] * (1.0 - mask.astype(np.float32) * 0.5),
        b[:, :, 2] * (1.0 - mask.astype(np.float32) * 0.5),
    ], axis=2)
    img = Image.fromarray((overlay * 255).astype(np.uint8))
    img.save(out_path)
    return out_path


def compare(a_path: str, b_path: str, threshold: float = None, out_dir: str = None):
    img_a = load_image(a_path)
    img_b = load_image(b_path)

    h = min(img_a.shape[0], img_b.shape[0])
    w = min(img_a.shape[1], img_b.shape[1])
    img_a = img_a[:h, :w, :]
    img_b = img_b[:h, :w, :]

    mse = compute_mse(img_a, img_b)

    if HAS_SSIM:
        ssim_score = ssim(img_a, img_b, channel_axis=-1, data_range=1.0)
    else:
        ssim_score = None

    hist_corr = compute_histogram_correlation(img_a, img_b)

    print(f"Comparison: {os.path.basename(a_path)} vs {os.path.basename(b_path)}")
    print(f"  Size: {w}x{h}")
    print(f"  MSE:  {mse:.6f}  (0 = identical, higher = worse)")
    if ssim_score is not None:
        print(f"  SSIM: {ssim_score:.4f}  (1 = identical, 0 = completely different)")
    else:
        print(f"  SSIM: (skimage not available, install scikit-image)")
    print(f"  Hist: {hist_corr:.4f}  (1 = identical color distribution)")

    if ssim_score is not None:
        overall = ssim_score
    else:
        overall = 1.0 - mse

    if overall >= 0.9:
        verdict = "VERY SIMILAR"
    elif overall >= 0.75:
        verdict = "SIMILAR"
    elif overall >= 0.5:
        verdict = "PARTIALLY SIMILAR"
    else:
        verdict = "DIFFERENT"

    print(f"  Verdict: {verdict}")

    if threshold is not None and overall < threshold:
        print(f"  FAIL: similarity {overall:.4f} < threshold {threshold}")
        if out_dir:
            diff_path = os.path.join(out_dir, f"diff_{os.path.basename(a_path)}")
            generate_diff(img_a, img_b, diff_path)
            print(f"  Diff overlay saved: {diff_path}")
        sys.exit(1)
    elif threshold is not None:
        print(f"  PASS: similarity {overall:.4f} >= threshold {threshold}")

    if out_dir:
        diff_path = os.path.join(out_dir, f"diff_{os.path.basename(a_path)}")
        generate_diff(img_a, img_b, diff_path)
        print(f"  Diff overlay saved: {diff_path}")

    return overall


def batch_compare(src_dir: str, ref_dir: str, threshold: float = None, out_dir: str = None):
    results = []
    for fname in os.listdir(src_dir):
        src_path = os.path.join(src_dir, fname)
        if not os.path.isfile(src_path):
            continue
        ref_path = os.path.join(ref_dir, fname)
        if not os.path.exists(ref_path):
            base, _ = os.path.splitext(fname)
            for ext in ['.jpg', '.png', '.bmp', '.webp']:
                candidate = os.path.join(ref_dir, base + ext)
                if os.path.exists(candidate):
                    ref_path = candidate
                    break
        if not os.path.exists(ref_path):
            print(f"Skipping {fname}: no match in {ref_dir}")
            continue
        score = compare(src_path, ref_path, threshold=threshold, out_dir=out_dir)
        results.append((fname, score))

    if results:
        avg = np.mean([r[1] for r in results])
        print(f"\n=== Batch Summary ===")
        print(f"  Average similarity: {avg:.4f}")
        print(f"  Best:  {max(results, key=lambda r: r[1])[0]} ({max(r[1] for r in results):.4f})")
        print(f"  Worst: {min(results, key=lambda r: r[1])[0]} ({min(r[1] for r in results):.4f})")


def main():
    parser = argparse.ArgumentParser(description="Compare ProjectM screenshot vs original WMP screenshot")
    parser.add_argument("image_a", nargs="?", help="ProjectM screenshot (BMP/PNG/JPG)")
    parser.add_argument("image_b", nargs="?", help="Original WMP screenshot")
    parser.add_argument("--dir", nargs=2, metavar=("SRC_DIR", "REF_DIR"),
                        help="Batch compare all images in SRC_DIR against REF_DIR by filename")
    parser.add_argument("--threshold", type=float, default=None,
                        help="Exit with code 1 if SSIM/MSE-derived similarity < threshold")
    parser.add_argument("--out-dir", default=None,
                        help="Directory to save diff overlay images")
    args = parser.parse_args()

    if args.dir:
        src_dir, ref_dir = args.dir
        batch_compare(src_dir, ref_dir, threshold=args.threshold, out_dir=args.out_dir)
    elif args.image_a and args.image_b:
        compare(args.image_a, args.image_b, threshold=args.threshold, out_dir=args.out_dir)
    else:
        parser.print_help()
        sys.exit(1)


if __name__ == "__main__":
    main()
