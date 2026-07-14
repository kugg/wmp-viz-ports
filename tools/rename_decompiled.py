#!/usr/bin/env python3
"""Rename decompiled WMP visualization functions using the deep-decompilation naming schema."""

import re
import sys
from pathlib import Path

# =============================================================================
# FUNCTION NAME MAPPINGS
# =============================================================================
# Addresses are lowercase hex without "0x" prefix.
# When the same code exists at different addresses in different DLL builds,
# both addresses map to the same name.
#
# TrilogyI and TrilogyIII share identical code (same addresses).
# TrilogyII is a separate build with addresses shifted by +0x10 in many cases.
# =============================================================================

# --- Helper: base addresses for TrilogyI/III (no offset) ---
_I_BASE = {
    # DLL Entry Points
    "10010890": "DllMain",
    "10010a90": "DllCanUnloadNow",
    "10010aa0": "DllGetClassObject",
    "10010b90": "DllRegisterServer",
    "10010c20": "DllUnregisterServer",

    # COM Class Factory
    "10010cb0": "ClassFactory_CreateInstance",
    "10010dc0": "IUnknown_AddRef",
    "10010e00": "IUnknown_Release",
    "10010e60": "IUnknown_Destructor",
    "10010e90": "IUnknown_QueryInterface",
    "10010f90": "ClassFactory2_CreateInstance",
    "10010fa0": "CreateEffectObject",

    # Render Pipeline
    "10001000": "Render_MainLoop",
    "10001290": "Present_ToScreen",
    "10001590": "Update_FPSCounter",
    "10001600": "Render_AllPresets",

    # Preset Management
    "10001970": "Convert_BufferFormat",
    "100019f0": "Preset_LoadConfig",
    "10001ce0": "Calc_RowPadding",
    "10001e40": "Release_PresetData",
    "10001e50": "IWMPEffects_Render",
    "10001ee0": "IWMPEffects_MediaInfo",
    "10001f40": "IWMPEffects_SetUserPreset",
    "10001fa0": "IterateSubVisualizations",
    "100020c0": "Blend_PresetFrames",
    "100021d0": "Blend_AudioFrames",

    # Audio Processing
    "1000e350": "Audio_AllocBuffer",
    "1000e450": "Audio_ProcessData",
    "1000e560": "Audio_GetLevel",
    "1000e5e0": "Audio_GetPeak",
    "1000e660": "Audio_GetAverage",
    "1000e6e0": "Audio_GetBass",
    "1000e760": "Audio_GetMid",
    "1000e7f0": "Audio_GetTreble",
    "1000e8c0": "Audio_Smooth",
    "1000e960": "Audio_Decay",
    "1000ea60": "Audio_CopyTimedLevel",
    "1000ebf0": "Audio_Decimate",
    "1000ed00": "Audio_InitStream",
    "1000ee00": "Audio_WndProc",

    # Texture Generation
    "10002f60": "Effect_GenerateTexture",

    # Effects
    "100030b0": "Effect_Convolution",
    "10003120": "Effect_GaussianBlur",
    "10003350": "Effect_ColorCycle",
    "100034b0": "Effect_Rotate",
    "100036d0": "Effect_Zoom",
    "10003790": "Effect_Swirl",
    "10003800": "Effect_Water",
    "100038e0": "Effect_Ripple",
    "10003970": "Effect_Fade",

    # Coordinate Transforms
    "10003b20": "Transform_PixelOffset",
    "100040d0": "Transform_Configure",
    "10004220": "Geom_RotateZoom",
    "100047d0": "Transform_Motion",
    "10004920": "Transform_Wrap",
    "10004b00": "Transform_WithAudio",

    # Pixel Operations
    "10005040": "PixelBlit_SimpleCopy",
    "10005300": "PixelBlit_AlphaBlend",

    # Geometric Transforms
    "100058b0": "Transform_Scale",
    "100059a0": "Transform_RotatePolar",
    "10005aa0": "Transform_RotateFast",
    "10005e70": "Convolution_Apply",

    # Motion Physics
    "10005f40": "Motion_ComplexPhysics",
    "10006fe0": "PerPixelColorBlend",
    "100081d0": "Transform_PresetCoords",
    "10009660": "Transform_PolarCoords",
    "1000a480": "Blend_AlphaComposite",
    "1000abf0": "Blend_LayerMerge",
    "1000b010": "Blend_Additive",
    "1000b680": "Effect_Blur",
    "1000b8f0": "Effect_Shadow",
    "1000bdf0": "Effect_MotionBlur",
    "1000be40": "Effect_Fade",
    "1000c370": "Render_PresetImage",
    "1000c930": "Blend_WithOverlay",
    "1000cb50": "Blend_WithTransform",
    "1000ce30": "Blend_CopySecondary",
    "1000cf50": "Blend_CopyBack",
    "1000d010": "Blend_Screen",
    "1000d1f0": "Blend_Multiply",
    "1000d2b0": "Blend_Overlay",
    "1000d370": "Blend_SoftLight",
    "1000d3e0": "Effect_Invert",
    "1000d460": "Effect_Grayscale",
    "1000d4f0": "Effect_Brightness",
    "1000d760": "Effect_Contrast",
    "1000d7a0": "Effect_Saturation",
    "1000d7e0": "Effect_Hue",
    "1000d830": "Effect_Gamma",
    "1000d8c0": "Effect_ColorBalance",
    "1000d960": "Effect_ColorLookup",
    "1000da20": "Effect_ChannelMix",
    "1000db00": "Render_ComplexScene",
    "1000dc90": "Render_Particles",
    "1000df40": "Render_MipmapChain",

    # Window Management
    "1000ee60": "InitWindowState",
    "1000eec0": "Cleanup_WindowState",
    "1000eed0": "Command_Exit",
    "1000eee0": "Wnd_Destroy",
    "1000f3d0": "Misc_HideCursor",
    "1000f3e0": "WndProc_Viz",
    "1000f460": "PostCloseMessage",
    "1000f480": "DestroyVizWindow",
    "1000f4f0": "CleanupVizInstance",

    # State Management
    "1000f500": "State_Cleanup",
    "1000f730": "FreeVisTextures",
    "1000f880": "FreeAllBuffers",
    "1000f890": "State_FullReset",
    "1000f9e0": "InitStateDefaults",
    "1000fa50": "Destructor_VisObject",
    "1000fab0": "Init_Stub",
    "1000fac0": "Shutdown_Stub",
    "1000fad0": "Init_RenderContext",
    "1000fae0": "Texture_InitRender",
    "100103e0": "Init_GDIContext",
    "10010470": "Load_DisplayName",

    # String/Registry Utilities
    "10010700": "ParseHexDWord",
    "100107f0": "FormatHexDWord",
    "10011a80": "BuildRegScript",
    "10011d50": "StringBuffer_Append",
    "10011f20": "ExecuteRegScript",
    "10012240": "IsEscape",
    "100122a0": "IsDelimiter",
    "100122f0": "SkipWhitespace",
    "10012340": "ParseToken",
    "100124a0": "ExpandVariables",
    "10012850": "RegFileParser",
    "10013540": "RegWriteValue",

    # COM Object Creation
    "10011170": "Get_SingletonObject",
    "10011340": "Create_VisObject2",
    "10011470": "Init_CriticalSection",
    "100114e0": "QueryInterface_Table2",
    "10011570": "IUnknown_AddRef2",
    "100115f0": "IUnknown_Release2",
    "10011620": "Destructor_VisObject2",
    "10011690": "QueryInterface_Main",
    "10011930": "ScalarDeletingDestructor_Main",
    "10011960": "Destructor_Main",
    "100119f0": "ScalarDeletingDestructor_Main2",

    # Initialization
    "10015630": "InitAllVisParams",
    "10015550": "UpdateSpectrumData",

    # Registry/File Utilities
    "100139a0": "Reg_QueryKeyInfo",
    "10013a50": "Reg_ParseConfigValue",
    "10013bd0": "Reg_RegisterTypeLib",
    "10013d00": "Reg_UnregisterServer",
    "10013f70": "Reg_RegisterServer",
    "10014170": "Str_FindFileNameW",

    # Motion Physics
    "10014680": "Motion_UpdateAll",
    "10014860": "IterateActivePresets",
    "10014f80": "Effect_RunPipeline",
    "100151d0": "Audio_RotateSpectrumBuffers",
    "10015b10": "Resource_LoadPresetData",
    "10015cc0": "State_InitParams",

    # Per-Preset Motion
    "100162d0": "Motion_CalcPresetXY",
    "100165b0": "Motion_CalcPresetX",
    "100166a0": "Motion_CalcPresetXY2",
    "100169f0": "Motion_CalcPresetXYZ",

    # Preset Rendering
    "10016bb0": "Render_PresetLoop",
    "10016c80": "Render_PresetSetup",
    "10016d10": "Render_SwapFrameBuffers",

    # Waveform Data Copy
    "100171a0": "Waveform_CopyMultiBPP",
    "10017300": "Waveform_Copy4BPP",
    "10017400": "Waveform_CopyWithScroll",
    "10017510": "Waveform_CopyAndFill",
    "10017610": "Waveform_CopyWithMirror",
    "10017730": "Waveform_CopyWithWrap",
    "10017840": "Waveform_MirrorCopy",
    "10017a10": "Preset_FillBuffer",
    "10017d40": "Audio_RandomSelect",
    "10017f40": "Waveform_CopyToDisplay",
    "10014e70": "State_SetDefaults",
    "10015350": "State_ResetAudio",
    "10015540": "State_ResetAll",

    # Memory Management (TrilogyI addresses)
    "10019b16": "Mem_Free",
    "10019b5e": "_malloc",
    "10019b70": "__nh_malloc",
    "10019bea": "Mem_FreeObj",
    "10019d3c": "__ftol",
    "10019d96": "HeapFree_Wrapper",
    "10019dde": "malloc_wrap",
    "10019df0": "__nh_malloc",
    "10019e1c": "HeapAlloc_Wrapper",
    "10019e6a": "free_wrap",
    "10019fbc": "ftol",
    "1001a288": "operator_new",
    "1001a420": "Mem_Alloc",
    "1001a508": "operator_new",
}

# =============================================================================
# TrilogyII auto-generated shifted addresses (+0x10 from TrilogyI base)
# Only addresses that are UNIQUE to TrilogyII (not in _I_BASE)
# =============================================================================
def _gen_shiftedAddresses(base_dict, offset=0x10):
    """Generate shifted addresses for TrilogyII from TrilogyI base."""
    shifted = {}
    for addr, name in base_dict.items():
        new_addr = hex(int(addr, 16) + offset).replace("0x", "")
        shifted[new_addr] = name
    return shifted

# These are the TrilogyI addresses that get shifted +0x10 in TrilogyII
_SHIFTABLE_ADDRS = {
    # Effects
    "100030b0": "Effect_Convolution",
    "10003120": "Effect_GaussianBlur",
    "10003350": "Effect_ColorCycle",
    "100034b0": "Effect_Rotate",
    "100036d0": "Effect_Zoom",
    "10003790": "Effect_Swirl",
    "10003800": "Effect_Water",
    "100038e0": "Effect_Ripple",
    "10003970": "Effect_Fade",
    "10003b20": "Transform_PixelOffset",
    "100040d0": "Transform_Configure",
    "10004220": "Geom_RotateZoom",
    "100047d0": "Transform_Motion",
    "10004920": "Transform_Wrap",
    "10004b00": "Transform_WithAudio",
    "10005040": "PixelBlit_SimpleCopy",
    "10005300": "PixelBlit_AlphaBlend",
    "100058b0": "Transform_Scale",
    "100059a0": "Transform_RotatePolar",
    "10005aa0": "Transform_RotateFast",
    "10005e70": "Convolution_Apply",
    "10005f40": "Motion_ComplexPhysics",
    "10006fe0": "PerPixelColorBlend",
    "100081d0": "Transform_PresetCoords",
    "10009660": "Transform_PolarCoords",
    "1000a480": "Blend_AlphaComposite",
    "1000abf0": "Blend_LayerMerge",
    "1000b010": "Blend_Additive",
    "1000b680": "Effect_Blur",
    "1000b8f0": "Effect_Shadow",
    "1000bdf0": "Effect_MotionBlur",
    "1000be40": "Effect_Fade2",
    "1000c370": "Render_PresetImage",
    "1000c930": "Blend_WithOverlay",
    "1000cb50": "Blend_WithTransform",
    "1000ce30": "Blend_CopySecondary",
    "1000cf50": "Blend_CopyBack",
    "1000d010": "Blend_Screen",
    "1000d1f0": "Blend_Multiply",
    "1000d2b0": "Blend_Overlay",
    "1000d370": "Blend_SoftLight",
    "1000d3e0": "Effect_Invert",
    "1000d460": "Effect_Grayscale",
    "1000d4f0": "Effect_Brightness",
    "1000d760": "Effect_Contrast",
    "1000d7a0": "Effect_Saturation",
    "1000d7e0": "Effect_Hue",
    "1000d830": "Effect_Gamma",
    "1000d8c0": "Effect_ColorBalance",
    "1000d960": "Effect_ColorLookup",
    "1000da20": "Effect_ChannelMix",
    "1000db00": "Render_ComplexScene",
    "1000dc90": "Render_Particles",
    "1000df40": "Render_MipmapChain",
    # Window/State Management
    "1000ee60": "InitWindowState",
    "1000eec0": "Cleanup_WindowState",
    "1000eee0": "Wnd_Destroy",
    "1000f3d0": "Misc_HideCursor",
    "1000f3e0": "WndProc_Viz",
    "1000f460": "PostCloseMessage",
    "1000f480": "DestroyVizWindow",
    "1000f4f0": "CleanupVizInstance",
    "1000f500": "State_Cleanup",
    "1000f730": "FreeVisTextures",
    "1000f880": "FreeAllBuffers",
    "1000f890": "State_FullReset",
    "1000f9e0": "InitStateDefaults",
    "1000fa50": "Destructor_VisObject",
    # String/Registry
    "10010700": "ParseHexDWord",
    "100107f0": "FormatHexDWord",
    "10011a80": "BuildRegScript",
    "10011d50": "StringBuffer_Append",
    "10011f20": "ExecuteRegScript",
    "10012240": "IsEscape",
    "100122a0": "IsDelimiter",
    "100122f0": "SkipWhitespace",
    "10012340": "ParseToken",
    "100124a0": "ExpandVariables",
    "10012850": "RegFileParser",
    "10013540": "RegWriteValue",
    # COM Object Creation
    "10011170": "Get_SingletonObject",
    "10011340": "Create_VisObject2",
    "10011470": "Init_CriticalSection",
    "100114e0": "QueryInterface_Table2",
    "10011570": "IUnknown_AddRef2",
    "100115f0": "IUnknown_Release2",
    "10011620": "Destructor_VisObject2",
    "10011690": "QueryInterface_Main",
    "10011930": "ScalarDeletingDestructor_Main",
    "10011960": "Destructor_Main",
    "100119f0": "ScalarDeletingDestructor_Main2",
    # Initialization
    "10015630": "InitAllVisParams",
    "10015550": "UpdateSpectrumData",
    "100103e0": "Init_GDIContext",
    "10010470": "Load_DisplayName",
    # Registry/File Utilities
    "100139a0": "Reg_QueryKeyInfo",
    "10013a50": "Reg_ParseConfigValue",
    "10013bd0": "Reg_RegisterTypeLib",
    "10013d00": "Reg_UnregisterServer",
    "10013f70": "Reg_RegisterServer",
    "10014170": "Str_FindFileNameW",
    # Motion Physics
    "10014680": "Motion_UpdateAll",
    "10014860": "IterateActivePresets",
    "10014f80": "Effect_RunPipeline",
    "100151d0": "Audio_RotateSpectrumBuffers",
    "10015b10": "Resource_LoadPresetData",
    "10015cc0": "State_InitParams",
    # Per-Preset Motion
    "100162d0": "Motion_CalcPresetXY",
    "100165b0": "Motion_CalcPresetX",
    "100166a0": "Motion_CalcPresetXY2",
    "100169f0": "Motion_CalcPresetXYZ",
    # Preset Rendering
    "10016bb0": "Render_PresetLoop",
    "10016c80": "Render_PresetSetup",
    "10016d10": "Render_SwapFrameBuffers",
    # Waveform Data Copy
    "100171a0": "Waveform_CopyMultiBPP",
    "10017300": "Waveform_Copy4BPP",
    "10017400": "Waveform_CopyWithScroll",
    "10017510": "Waveform_CopyAndFill",
    "10017610": "Waveform_CopyWithMirror",
    "10017730": "Waveform_CopyWithWrap",
    "10017840": "Waveform_MirrorCopy",
    "10017a10": "Preset_FillBuffer",
    "10017d40": "Audio_RandomSelect",
    "10017f40": "Waveform_CopyToDisplay",
    "10014e70": "State_SetDefaults",
    "10015350": "State_ResetAudio",
    "10015540": "State_ResetAll",
}

_II_SHIFTED = _gen_shiftedAddresses(_SHIFTABLE_ADDRS, offset=0x10)

# --- TrilogyII-only utility functions (config file parsing) ---
_II_ONLY = {
    "10010720": "Util_HexStringToColor",
    "10010810": "Util_ColorToHexString",
    "10012260": "Util_IsSpace",
    "100122c0": "Util_IsDelimiter",
    "10012310": "Util_InitParser",
    "10012360": "Util_ParseConfig",
    "100124c0": "Util_ReadConfig",
    "10012760": "Util_ConfigSection",
    "10012870": "Util_RegistryParse",
    "10013be0": "Util_RegisterClass",
    "10013bf0": "Register_TypeLib",
    "10013d10": "Unregister_Server",
    "10013d20": "Util_UnregisterClass",
    "10013f80": "Register_Server",
    "10013f90": "Util_WriteRegKey",
    "10011190": "GetOrCreateSingleton",
    "10011360": "CreateEffectObject_V2",
    "10015650": "State_InitAllDefaults",
    "10015570": "Texture_MotionCalc",
}

# Merge all mappings - _I_BASE first, then shifted, then II-only
FUNCTION_NAMES = {}
FUNCTION_NAMES.update(_I_BASE)
FUNCTION_NAMES.update(_II_SHIFTED)
FUNCTION_NAMES.update(_II_ONLY)

def rename_functions(input_path, output_path, dll_name):
    """Read decompiled output, apply naming schema, write to output."""
    with open(input_path, 'r') as f:
        content = f.read()
    
    # Track stats
    renamed_count = 0
    total_functions = 0
    
    # Replace function names in the content
    lines = content.split('\n')
    output_lines = []
    
    for line in lines:
        # Pattern 1: Function comment headers
        # "// Function: FUN_XXXXXXXX @ 1000XXXX"
        comment_match = re.match(r'^(// Function: )(FUN_[0-9a-fA-F]+)( @ [0-9a-fA-F]+.*$)', line)
        if comment_match:
            prefix = comment_match.group(1)
            func_name = comment_match.group(2)
            suffix = comment_match.group(3)
            addr = func_name[4:]
            if addr.lower() in FUNCTION_NAMES:
                new_name = FUNCTION_NAMES[addr.lower()]
                output_lines.append(f"{prefix}{new_name}{suffix}")
                renamed_count += 1
            else:
                output_lines.append(line)
            total_functions += 1
            continue
        
        # Pattern 2: Function declarations
        # "undefined4 FUN_XXXXXXXX(int *param_1)" or "void FUN_XXXXXXXX(...)"
        func_match = re.match(r'^(.*?\s+)(FUN_[0-9a-fA-F]+)(\(.*$)', line)
        if func_match:
            prefix = func_match.group(1)
            func_name = func_match.group(2)
            suffix = func_match.group(3)
            addr = func_name[4:]
            if addr.lower() in FUNCTION_NAMES:
                new_name = FUNCTION_NAMES[addr.lower()]
                output_lines.append(f"{prefix}{new_name}{suffix}")
                renamed_count += 1
            else:
                output_lines.append(line)
            total_functions += 1
            continue
        
        # Pattern 3: Function calls in code - "FUN_XXXXXXXX(...)"
        # Only replace known addresses to avoid false positives
        for old_addr, new_name in FUNCTION_NAMES.items():
            line = line.replace(f"FUN_{old_addr.upper()}", new_name)
        output_lines.append(line)
    
    # Write output
    with open(output_path, 'w') as f:
        f.write('\n'.join(output_lines))
    
    return renamed_count, total_functions

def main():
    if len(sys.argv) < 4:
        print("Usage: rename_decompiled.py <input.txt> <output.txt> <dll_name>")
        sys.exit(1)
    
    input_path = sys.argv[1]
    output_path = sys.argv[2]
    dll_name = sys.argv[3]
    
    renamed, total = rename_functions(input_path, output_path, dll_name)
    print(f"Renamed {renamed}/{total} functions in {dll_name}")

if __name__ == "__main__":
    main()
