#!/usr/bin/env python3
"""Rename decompiled variables using Windows SDK type inference.

Scans decompiled C code and renames variables based on:
1. Windows API function calls (SDK signatures)
2. WMP SDK interface types (IWMPEffects, IWMPEffects2, TimedLevel)
3. Variable usage patterns (cast context, function arguments)
4. Global variable names based on their usage
"""

import re
import sys
from pathlib import Path

# =============================================================================
# WMP SDK INTERFACE TYPES
# =============================================================================
# IWMPEffects vtable layout (4 bytes per entry on x86):
#   [0]  QueryInterface(REFIID riid, void **ppvObject) -> HRESULT
#   [1]  AddRef() -> ULONG
#   [2]  Release() -> ULONG
#   [3]  Render(TimedLevel *pLevels, HDC hdc, RECT *prc) -> HRESULT
#   [4]  MediaInfo(LONG lChannelCount, LONG lSampleRate, BSTR bstrTitle) -> HRESULT
#   [5]  GetCapabilities(DWORD *pdwCapabilities) -> HRESULT
#   [6]  GetTitle(BSTR *bstrTitle) -> HRESULT
#   [7]  GetPresetTitle(LONG nPreset, BSTR *bstrPresetTitle) -> HRESULT
#   [8]  GetPresetCount(LONG *pnPresetCount) -> HRESULT
#   [9]  SetCurrentPreset(LONG nPreset) -> HRESULT
#   [10] GetCurrentPreset(LONG *pnPreset) -> HRESULT
#   [11] DisplayPropertyPage(HWND hwndOwner) -> HRESULT
#   [12] GoFullscreen(BOOL fFullScreen) -> HRESULT
#   [13] RenderFullScreen(TimedLevel *pLevels) -> HRESULT
#
# IWMPEffects2 vtable (extends IWMPEffects):
#   [14] SetCore(IWMPCore *pPlayer) -> HRESULT
#   [15] Create(HWND hwndParent) -> HRESULT
#   [16] Destroy() -> HRESULT
#   [17] NotifyNewMedia(IWMPMedia *pMedia) -> HRESULT
#   [18] OnWindowMessage(UINT msg, WPARAM WParam, LPARAM LParam, LRESULT *plResultParam) -> HRESULT
#   [19] RenderWindowed(TimedLevel *pData, BOOL fRequiredRender) -> HRESULT
# =============================================================================

# Vtable offset -> parameter name mappings for IWMPEffects
# Format: vtable_offset -> {param_index -> name}
IWMPEFFECTS_PARAMS = {
    # Render(This, pLevels, hdc, prc) - vtable offset 0x0C (index 3)
    0x0C: {
        "this": "pEffects",
        1: "pLevels",      # TimedLevel*
        2: "hdc",          # HDC
        3: "prc",          # RECT*
    },
    # MediaInfo(This, lChannelCount, lSampleRate, bstrTitle) - vtable offset 0x10 (index 4)
    0x10: {
        "this": "pEffects",
        1: "lChannelCount", # LONG
        2: "lSampleRate",   # LONG
        3: "bstrTitle",     # BSTR
    },
    # GetCapabilities(This, pdwCapabilities) - vtable offset 0x14 (index 5)
    0x14: {
        "this": "pEffects",
        1: "pdwCapabilities", # DWORD*
    },
    # GetTitle(This, bstrTitle) - vtable offset 0x18 (index 6)
    0x18: {
        "this": "pEffects",
        1: "bstrTitle",     # BSTR*
    },
    # GetPresetTitle(This, nPreset, bstrPresetTitle) - vtable offset 0x1C (index 7)
    0x1C: {
        "this": "pEffects",
        1: "nPreset",       # LONG
        2: "bstrPresetTitle", # BSTR*
    },
    # GetPresetCount(This, pnpResetCount) - vtable offset 0x20 (index 8)
    0x20: {
        "this": "pEffects",
        1: "pnPresetCount", # LONG*
    },
    # SetCurrentPreset(This, nPreset) - vtable offset 0x24 (index 9)
    0x24: {
        "this": "pEffects",
        1: "nPreset",       # LONG
    },
    # GetCurrentPreset(This, pnPreset) - vtable offset 0x28 (index 10)
    0x28: {
        "this": "pEffects",
        1: "pnPreset",      # LONG*
    },
    # DisplayPropertyPage(This, hwndOwner) - vtable offset 0x2C (index 11)
    0x2C: {
        "this": "pEffects",
        1: "hwndOwner",    # HWND
    },
    # GoFullscreen(This, fFullScreen) - vtable offset 0x30 (index 12)
    0x30: {
        "this": "pEffects",
        1: "fFullScreen",   # BOOL
    },
    # RenderFullScreen(This, pLevels) - vtable offset 0x34 (index 13)
    0x34: {
        "this": "pEffects",
        1: "pLevels",      # TimedLevel*
    },
    # IWMPEffects2::SetCore(This, pPlayer) - vtable offset 0x38 (index 14)
    0x38: {
        "this": "pEffects",
        1: "pPlayer",      # IWMPCore*
    },
    # IWMPEffects2::Create(This, hwndParent) - vtable offset 0x3C (index 15)
    0x3C: {
        "this": "pEffects",
        1: "hwndParent",   # HWND
    },
    # IWMPEffects2::Destroy(This) - vtable offset 0x40 (index 16)
    0x40: {
        "this": "pEffects",
    },
    # IWMPEffects2::NotifyNewMedia(This, pMedia) - vtable offset 0x44 (index 17)
    0x44: {
        "this": "pEffects",
        1: "pMedia",       # IWMPMedia*
    },
    # IWMPEffects2::OnWindowMessage(This, msg, WParam, LParam, plResultParam) - vtable offset 0x48 (index 18)
    0x48: {
        "this": "pEffects",
        1: "msg",          # UINT
        2: "WParam",       # WPARAM
        3: "LParam",       # LPARAM
        4: "plResultParam", # LRESULT*
    },
    # IWMPEffects2::RenderWindowed(This, pData, fRequiredRender) - vtable offset 0x4C (index 19)
    0x4C: {
        "this": "pEffects",
        1: "pData",        # TimedLevel*
        2: "fRequiredRender", # BOOL
    },
}

# =============================================================================
# VARIABLE RENAMES BY FUNCTION
# =============================================================================
# Maps function address -> {old_name -> new_name}
# Applied only within the function body.

FUNCTION_VARIABLE_RENAMES = {
    "10001000": {
        # This is the main render loop - key parameters from WMP SDK
        # param_1 = IWMPEffects2* (this pointer)
        # Local variables used in render pipeline
    },
    "10001290": {
        # Local variable declarations
        "h": "hBitmap",
        "hdc": "hScreenDC",
        "h_00": "hOldBitmap",
        "piVar1": "pScreenDC",
    },
    "10001590": {
        "DVar1": "dwCurrentTime",
    },
    "10001600": {
        "iVar1": "visIndex",
    },
    "10001970": {
        "iVar1": "srcFormat",
        "iVar2": "dstFormat",
    },
    "100019f0": {
        "iVar1": "configParam",
    },
    "10001ce0": {
        "iVar1": "rowBytes",
        "iVar2": "padding",
    },
    "10001e40": {
        "iVar1": "presetIndex",
    },
    "10001e50": {
        "iVar1": "renderResult",
        "param_1": "pEffects",
    },
    "10001ee0": {
        "iVar1": "mediaInfoResult",
        "param_1": "pEffects",
    },
    "10001f40": {
        "iVar1": "presetIndex",
        "param_1": "pEffects",
    },
    "10001fa0": {
        # Iterates sub-visualizations
        "iVar1": "visIndex",
    },
    "100020c0": {
        "fVar1": "blendAlpha",
    },
    "100021d0": {
        "fVar1": "audioBlend",
    },
    "10002f60": {
        "iVar1": "texWidth",
        "iVar2": "texHeight",
    },
    "100030b0": {
        "iVar1": "kernelSize",
        "fVar2": "kernelSum",
    },
    "10003120": {
        "fVar1": "sigma",
    },
    "10003350": {
        "fVar1": "cycleSpeed",
    },
    "100034b0": {
        "fVar1": "angle",
    },
    "100036d0": {
        "fVar1": "zoomFactor",
    },
    "10003790": {
        "fVar1": "swirlAmount",
    },
    "10003800": {
        "fVar1": "waveAmplitude",
    },
    "100038e0": {
        "fVar1": "ripplePhase",
    },
    "10003970": {
        "fVar1": "fadeAlpha",
    },
    "10003b20": {
        "fVar1": "offsetX",
        "fVar2": "offsetY",
    },
    "100040d0": {
        "iVar1": "configParam",
    },
    "10004220": {
        "fVar1": "rotation",
        "fVar2": "zoom",
    },
    "100047d0": {
        "fVar1": "motionX",
        "fVar2": "motionY",
    },
    "10004920": {
        "fVar1": "wrapX",
        "fVar2": "wrapY",
    },
    "10004b00": {
        "fVar1": "audioLevel",
    },
    "10005040": {
        "iVar1": "srcIndex",
        "iVar2": "dstIndex",
    },
    "10005300": {
        "fVar1": "alpha",
    },
    "100058b0": {
        "fVar1": "scaleX",
        "fVar2": "scaleY",
    },
    "100059a0": {
        "fVar1": "angle",
    },
    "10005aa0": {
        "fVar1": "angle",
    },
    "10005e70": {
        "iVar1": "kernelSize",
    },
    "10005f40": {
        "fVar1": "velocityX",
        "fVar2": "velocityY",
        "fVar3": "acceleration",
    },
    "10006fe0": {
        "fVar1": "blendFactor",
    },
    "100081d0": {
        "fVar1": "coordX",
        "fVar2": "coordY",
    },
    "10009660": {
        "fVar1": "radius",
        "fVar2": "theta",
    },
    "1000a480": {
        "fVar1": "alpha",
    },
    "1000abf0": {
        "fVar1": "mergeFactor",
    },
    "1000b010": {
        "fVar1": "additiveStrength",
    },
    "1000b680": {
        "fVar1": "blurRadius",
    },
    "1000b8f0": {
        "fVar1": "shadowOffsetX",
        "fVar2": "shadowOffsetY",
    },
    "1000bdf0": {
        "fVar1": "blurDirection",
    },
    "1000c370": {
        "iVar1": "imgWidth",
        "iVar2": "imgHeight",
    },
    "1000c930": {
        "fVar1": "overlayAlpha",
    },
    "1000cb50": {
        "fVar1": "transformAlpha",
    },
    "1000ce30": {
        "iVar1": "srcOffset",
        "iVar2": "dstOffset",
    },
    "1000cf50": {
        "iVar1": "srcOffset",
        "iVar2": "dstOffset",
    },
    "1000d010": {
        "fVar1": "screenBlend",
    },
    "1000d1f0": {
        "fVar1": "multiplyFactor",
    },
    "1000d2b0": {
        "fVar1": "overlayFactor",
    },
    "1000d370": {
        "fVar1": "softLightFactor",
    },
    "1000d3e0": {
        "iVar1": "pixelIndex",
    },
    "1000d460": {
        "fVar1": "luminance",
    },
    "1000d4f0": {
        "fVar1": "brightness",
    },
    "1000d760": {
        "fVar1": "contrast",
    },
    "1000d7a0": {
        "fVar1": "saturation",
    },
    "1000d7e0": {
        "fVar1": "hueShift",
    },
    "1000d830": {
        "fVar1": "gamma",
    },
    "1000d8c0": {
        "fVar1": "redBalance",
        "fVar2": "greenBalance",
        "fVar3": "blueBalance",
    },
    "1000d960": {
        "iVar1": "paletteIndex",
    },
    "1000da20": {
        "fVar1": "channelMix",
    },
    "1000db00": {
        "iVar1": "sceneIndex",
    },
    "1000dc90": {
        "iVar1": "particleIndex",
    },
    "1000df40": {
        "iVar1": "mipLevel",
    },
    "1000e6e0": {
        "iVar1": "bufferSize",
    },
    "1000e760": {
        "iVar1": "bufferSize",
    },
    "1000e7f0": {
        "iVar1": "bufferSize",
    },
    "1000e8c0": {
        "fVar1": "smoothFactor",
    },
    "1000e960": {
        "fVar1": "decayRate",
    },
    "1000ea60": {
        "iVar1": "srcOffset",
        "iVar2": "dstOffset",
    },
    "1000ebf0": {
        "iVar1": "srcIndex",
        "iVar2": "dstIndex",
    },
    "1000ed00": {
        "iVar1": "bufferSize",
    },
    "1000ee60": {
        "iVar1": "windowStyle",
    },
    "1000eec0": {
        "iVar1": "cleanupResult",
    },
    "1000f3e0": {
        "DVar1": "dwTimestamp",
    },
    "1000f460": {
        "iVar1": "msgResult",
    },
    "1000f480": {
        "iVar1": "destroyResult",
    },
    "1000f4f0": {
        "pvVar1": "pVizModule",
    },
    "1000f500": {
        "iVar1": "cleanupPhase",
    },
    "1000f730": {
        "pvVar1": "pTexture",
    },
    "1000f880": {
        "pvVar1": "pBuffer",
    },
    "1000f890": {
        "iVar1": "resetPhase",
    },
    "1000f9e0": {
        "iVar1": "paramIndex",
    },
    "1000fa50": {
        "iVar1": "refCount",
    },
    "1000fad0": {
        "iVar1": "initResult",
    },
    "1000fae0": {
        "iVar1": "texInitResult",
    },
    "100103e0": {
        "iVar1": "bitsPerPixel",
    },
    "10010470": {
        "local_204": "szDisplayName",
        "iVar1": "strLen",
    },
    "10010700": {
        "iVar2": "hexStrLen",
    },
    "10011470": {
        "lpCriticalSection": "pCritSect",
    },
    "10011960": {
        "lpCriticalSection": "pCritSect",
    },
    "10011a80": {
        "DVar6": "dwPathLen",
        "local_228": "szShortPath",
        "local_124": "szModulePath",
    },
    "10011d50": {
        "pvVar3": "pAllocatedBuffer",
        "iVar2": "strLen",
    },
    "10011f20": {
        "hModule": "hResModule",
        "DVar3": "dwError",
    },
    "100124a0": {
        "local_24": "cbWideSize",
        "local_20": "cbMBCSSize",
        "local_1c": "pCoTaskBuffer",
        "iVar4": "strLen",
    },
    "100139a0": {
        "LVar1": "regStatus",
    },
    "10013a50": {
        "iVar3": "isDelim",
        "pCVar4": "pCurrent",
        "pCVar5": "currentChar",
        "pCVar6": "pTokenStart",
    },
    "10013d00": {
        "hModule": "hOleaut32Module",
        "pFVar4": "pfnUnRegisterTypeLib",
        "lpString2": "szNameSuffix",
        "local_128": "szModulePath",
    },
    "10013f70": {
        "local_128": "szModulePath",
    },
    "10014170": {
        "sVar1": "currentChar",
        "psVar2": "pFileNameStart",
        "psVar3": "pCurrent",
    },
    "10014680": {
        "iVar1": "motionResult",
        "lVar2": "deltaTime",
    },
    "10014860": {
        "iVar1": "presetIndex",
    },
    "10014e70": {
        "iVar1": "defaultIndex",
    },
    "10014f80": {
        # No local vars to rename, only vtable calls
    },
    "100151d0": {
        "iVar1": "srcIndex",
        "iVar4": "bufferIndex",
        "iVar5": "rotationAmount",
        "uVar6": "stepSize",
        "uVar7": "accumulator",
    },
    "10015350": {
        "iVar1": "audioIndex",
    },
    "10015540": {
        "iVar1": "resetIndex",
    },
    "10015b10": {
        "hResData": "hResData",
        "pvVar2": "pResourceData",
        "hResInfo": "hResInfo",
    },
    "10015cc0": {
        "iVar1": "paramIndex",
    },
    "100162d0": {
        "iVar1": "presetOffset",
        "iVar2": "velocityX",
        "lVar3": "deltaTime",
    },
    "100165b0": {
        "iVar2": "presetOffset",
        "fVar1": "velocityX",
        "lVar3": "deltaTime",
    },
    "100166a0": {
        "iVar1": "presetOffset",
        "iVar2": "velocityX",
        "lVar3": "deltaTime",
    },
    "100169f0": {
        "iVar1": "presetOffset",
        "iVar2": "velocityX",
        "lVar3": "deltaTime",
    },
    "10016bb0": {
        "iVar1": "renderMode",
    },
    "10016c80": {
        "iVar1": "setupResult",
    },
    "10016d10": {
        "iVar1": "srcIndex",
        "iVar2": "dstIndex",
        "piVar3": "pSrcBuffer",
        "piVar4": "pDstBuffer",
        "lVar5": "copySize",
    },
    "100171a0": {
        "piVar1": "pDstRow",
        "iVar2": "bytesPerPixel",
        "puVar3": "pSrc",
        "puVar4": "pDst",
    },
    "10017300": {
        "iVar1": "srcOffset",
        "iVar2": "dstOffset",
        "puVar3": "pSrc",
        "puVar4": "pDst",
    },
    "10017400": {
        "lVar1": "copySize",
        "uVar2": "scrollOffset",
        "iVar3": "rowSize",
        "puVar4": "pSrc",
        "puVar5": "pDst",
    },
    "10017510": {
        "uVar1": "fillValue",
        "iVar2": "fillCount",
        "puVar3": "pSrc",
        "puVar4": "pDst",
    },
    "10017610": {
        "iVar1": "srcOffset",
        "iVar3": "mirrorCount",
        "piVar4": "pSrc",
        "piVar5": "pDst",
        "piVar6": "pMirrorEnd",
    },
    "10017730": {
        "uVar1": "wrapMask",
        "uVar4": "srcIndex",
        "uVar5": "dstIndex",
        "puVar6": "pSrc",
        "puVar7": "pDst",
    },
    "10017840": {
        "iVar1": "srcOffset",
        "uVar2": "halfSize",
        "uVar3": "srcIndex",
        "uVar4": "dstIndex",
        "uVar5": "totalPixels",
        "puVar6": "pSrc",
        "puVar7": "pDst",
    },
    "10017a10": {
        "uVar1": "fillValue",
        "iVar2": "fillCount",
        "puVar4": "pDst",
    },
    "10017d40": {
        "iVar1": "audioLevel",
        "lVar3": "randomSeed",
        "lVar4": "threshold",
        "uVar2": "randomIndex",
    },
    "10017f40": {
        "iVar1": "copyCount",
        "iVar2": "srcOffset",
        "puVar3": "pSrc",
        "puVar4": "pDst",
    },
}


# =============================================================================
# GLOBAL VARIABLE RENAMES
# =============================================================================
# Maps DAT_XXXX -> new_name for global variables used across functions

GLOBAL_RENAMES = {
    "DAT_10025010": "g_pTrilogyState",
    "DAT_10025018": "g_hModule",
    "DAT_1002502c": "g_csInit",
    "DAT_10025154": "g_dwOSVersion",
    "DAT_10025160": "g_dwOSMinor",
    "DAT_1002515c": "g_dwOSMajor",
    "DAT_10025158": "g_dwOSBuild",
    "DAT_100257ac": "g_hProcessHeap",
    "DAT_100257a8": "g_pMemTracker",
    "DAT_100257b0": "g_pCommandLine",
    "DAT_100250d4": "g_pEnvironment",
    "DAT_100250d0": "g_dwRefCount",
    "DAT_10025368": "g_pfnMessageBoxA",
    "DAT_1002536c": "g_pfnGetActiveWindow",
    "DAT_10025370": "g_pfnGetLastActivePopup",
    "_DAT_10025160": "g_dwOSMinor",
    "_DAT_1002515c": "g_dwOSMajor",
    "_DAT_10025158": "g_dwOSBuild",
    # TrilogyII-specific globals (shifted +0x10)
    "DAT_10025028": "g_hVizWindow",
    "DAT_10025024": "g_hMsgHook",
    "DAT_10025020": "g_hInstance",
    "_DAT_100250b0": "g_pClassFactory",
}


def find_function_body(lines, func_start_idx):
    """Find the end of a function body by tracking brace depth."""
    depth = 0
    in_function = False
    for i in range(func_start_idx, len(lines)):
        line = lines[i]
        for ch in line:
            if ch == '{':
                depth += 1
                in_function = True
            elif ch == '}':
                depth -= 1
                if in_function and depth == 0:
                    return i
    return len(lines) - 1


def extract_function_address(header_line):
    """Extract function address from comment header like '// Function: FUNC_NAME @ 10001234'"""
    m = re.search(r'@ ([0-9a-fA-F]+)', header_line)
    if m:
        return m.group(1).lower()
    return None


def apply_variable_renames(input_path, output_path):
    """Read decompiled output, apply variable renames, write to output."""
    with open(input_path, 'r') as f:
        lines = f.readlines()
    
    rename_count = 0
    output_lines = []
    
    current_func_addr = None
    current_func_renames = {}
    in_function = False
    in_sig_line = False
    brace_depth = 0
    
    for i, line in enumerate(lines):
        stripped = line.rstrip('\n')
        
        # Detect function comment headers
        if '// Function:' in stripped and '@' in stripped:
            addr = extract_function_address(stripped)
            if addr:
                current_func_addr = addr
                current_func_renames = FUNCTION_VARIABLE_RENAMES.get(addr, {})
                in_function = False
                brace_depth = 0
                # Also rename parameters in function signature (skip separator line)
                in_sig_line = True
                output_lines.append(stripped)
                continue
        
        # Pass through separator and empty lines when looking for signature
        if in_sig_line and (stripped.startswith('====') or not stripped):
            output_lines.append(stripped)
            continue
        
        # Apply renames to function signature line
        if current_func_renames and in_sig_line:
            for old_name, new_name in current_func_renames.items():
                if old_name in stripped:
                    stripped = re.sub(
                        r'\b' + re.escape(old_name) + r'\b',
                        new_name,
                        stripped
                    )
                    rename_count += 1
            # Only mark as done if this looks like a function signature
            if '(' in stripped:
                in_sig_line = False
        
        # Track brace depth for function body
        if current_func_addr and current_func_renames:
            for ch in stripped:
                if ch == '{':
                    brace_depth += 1
                    in_function = True
                elif ch == '}':
                    brace_depth -= 1
                    if brace_depth == 0 and in_function:
                        in_function = False
                        current_func_renames = {}
        
        # Apply renames within function body
        if current_func_renames and in_function:
            for old_name, new_name in current_func_renames.items():
                if old_name in stripped:
                    # Only rename exact word matches (not substrings)
                    # Use word boundary matching
                    stripped = re.sub(
                        r'\b' + re.escape(old_name) + r'\b',
                        new_name,
                        stripped
                    )
                    rename_count += 1
        
        # Apply global renames everywhere
        for old_name, new_name in GLOBAL_RENAMES.items():
            if old_name in stripped:
                stripped = stripped.replace(old_name, new_name)
                rename_count += 1
        
        output_lines.append(stripped)
    
    with open(output_path, 'w') as f:
        f.write('\n'.join(output_lines) + '\n')
    
    return rename_count


def main():
    if len(sys.argv) < 3:
        print("Usage: rename_variables.py <input.c> <output.c>")
        sys.exit(1)
    
    input_path = sys.argv[1]
    output_path = sys.argv[2]
    
    count = apply_variable_renames(input_path, output_path)
    print(f"Applied {count} variable renames")


if __name__ == "__main__":
    main()
