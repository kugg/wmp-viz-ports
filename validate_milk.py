#!/usr/bin/env python3
"""Validate .milk preset syntax for projectM compatibility."""
import sys
import re
import os

def validate_milk(filepath):
    errors = []
    warnings = []
    
    with open(filepath, 'r') as f:
        content = f.read()
    
    lines = content.split('\n')
    
    # Check for [preset00] header
    if not any('[preset00]' in line for line in lines):
        errors.append("Missing [preset00] section header")
    
    # Check for BOM or null bytes
    if '\x00' in content:
        errors.append("File contains null bytes")
    
    # Track parsed keys
    keys_seen = {}
    in_code_block = False
    code_block_name = None
    code_block_lines = []
    
    for i, line in enumerate(lines, 1):
        stripped = line.strip()
        
        # Skip empty lines and comments
        if not stripped or stripped.startswith('//'):
            continue
        
        # Check for code blocks (backtick continuation)
        if '`' in stripped:
            parts = stripped.split('=', 1)
            if len(parts) == 2:
                key = parts[0].strip()
                value = parts[1]
                
                if value.startswith('`'):
                    # Start of a code block
                    in_code_block = True
                    code_block_name = key.rsplit('_', 1)[0] if '_' in key else key
                    code_block_lines = [value[1:]]  # Skip the opening backtick
                elif in_code_block:
                    code_block_lines.append(stripped)
                
                # Track key numbering gaps
                if '_' in key:
                    prefix = key.rsplit('_', 1)[0]
                    try:
                        num = int(key.rsplit('_', 1)[1])
                        full_prefix = prefix
                        if full_prefix not in keys_seen:
                            keys_seen[full_prefix] = []
                        keys_seen[full_prefix].append(num)
                    except ValueError:
                        pass
            continue
        
        # Regular key=value line
        if '=' in stripped:
            key, _, value = stripped.partition('=')
            key = key.strip()
            
            # Track numbering
            if '_' in key:
                prefix = key.rsplit('_', 1)[0]
                try:
                    num = int(key.rsplit('_', 1)[1])
                    if prefix not in keys_seen:
                        keys_seen[prefix] = []
                    keys_seen[prefix].append(num)
                except ValueError:
                    pass
    
    # Check for numbering gaps (terminate parsing in projectM)
    for prefix, nums in keys_seen.items():
        if len(nums) < 2:
            continue
        nums_sorted = sorted(set(nums))
        for j in range(len(nums_sorted) - 1):
            if nums_sorted[j+1] - nums_sorted[j] > 1:
                warnings.append(
                    f"Gap in numbering for '{prefix}': {nums_sorted[j]} -> {nums_sorted[j+1]} "
                    f"(projectM terminates parsing at gaps)"
                )
    
    # Check for known preset parameters
    known_params = {
        'fRating', 'fGammaAdj', 'fVideoEchoZoom', 'fVideoEchoAngle',
        'fWaveMode', 'bWaveThick', 'bAdditiveWaves', 'bWaveDarken',
        'bSmooth', 'bModWaveAlphaByVolume', 'bModWaveAlphaReverse',
        'bInterlace', 'bBrighten', 'bDarken', 'bSolarize',
        'fWaveAlpha', 'fWaveScale', 'fWaveSmoothing', 'fWaveAspect',
        'fWarpAnimSpeed', 'fWarpScale', 'fZoomExponent', 'fZoom',
        'fSpin', 'fZoomCamera', 'dx', 'dy', 'cx', 'cy', 'sx', 'sy',
        'ob_size', 'ob_r', 'ob_g', 'ob_b', 'ob_a',
        'ib_size', 'ib_r', 'ib_g', 'ib_b', 'ib_a',
        'nWaveDots', 'nWaveThick', 'nWaveAlphaMode',
        'wave_r', 'wave_g', 'wave_b', 'wave_a', 'wave_mode',
        'wave_scale', 'wave_smoothing', 'wave_mystery', 'wave_aspect',
        'fDecay',
    }
    
    # Validate known parameters have valid values
    for i, line in enumerate(lines, 1):
        stripped = line.strip()
        if stripped.startswith('//') or not stripped or '`' in stripped:
            continue
        if '=' in stripped:
            key, _, value = stripped.partition('=')
            key = key.strip()
            if key in known_params and value.strip():
                try:
                    float(value.strip())
                except ValueError:
                    if not any(c in value for c in '();+-*/sin cos tan pow sqrt abs min max if above below'):
                        warnings.append(f"Line {i}: '{key}' has non-numeric value: {value.strip()}")
    
    return errors, warnings


def main():
    if len(sys.argv) < 2:
        print("Usage: validate_milk.py <preset.milk> [preset2.milk ...]")
        sys.exit(1)
    
    total_errors = 0
    total_warnings = 0
    
    for filepath in sys.argv[1:]:
        print(f"\n{'='*60}")
        print(f"Validating: {filepath}")
        print(f"{'='*60}")
        
        if not os.path.exists(filepath):
            print(f"  ERROR: File not found")
            total_errors += 1
            continue
        
        errors, warnings = validate_milk(filepath)
        
        if errors:
            for e in errors:
                print(f"  ERROR: {e}")
            total_errors += len(errors)
        
        if warnings:
            for w in warnings:
                print(f"  WARNING: {w}")
            total_warnings += len(warnings)
        
        if not errors and not warnings:
            print(f"  OK - No issues found")
        
        # Show file stats
        with open(filepath, 'r') as f:
            lines = f.readlines()
        print(f"  Stats: {len(lines)} lines, {os.path.getsize(filepath)} bytes")
    
    print(f"\n{'='*60}")
    print(f"Summary: {total_errors} errors, {total_warnings} warnings")
    print(f"{'='*60}")
    
    sys.exit(1 if total_errors else 0)


if __name__ == '__main__':
    main()
