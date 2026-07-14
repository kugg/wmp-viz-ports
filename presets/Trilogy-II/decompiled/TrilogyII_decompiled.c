=== DECOMPILED FUNCTIONS: TrilogyII.dll ===

======================================================================
// Function: Render_MainLoop @ 10001000
======================================================================

undefined4 Render_MainLoop(int *param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  
  param_1[0x3307] = param_1[0x3306] * 4;
  param_1[0x3234] = param_1[0x32a4] / 2;
  param_1[0x3236] = param_1[0x32a5] / 2;
  if (param_1[0x32a9] == 0) {
    pvVar2 = _malloc(param_1[0x3308] * param_1[0x3306] * 4);
    param_1[0x32a9] = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      param_1[0x3274] = 1;
      return 0;
    }
  }
  iVar3 = param_1[0x3308] * param_1[0x3306];
  piVar4 = (int *)param_1[0x32a9];
  iVar1 = param_1[0x322a];
  do {
    *piVar4 = iVar1;
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  (**(code **)(*param_1 + 0x260))(param_1);
  (**(code **)(*param_1 + 0x50))(param_1);
  if (param_1[0x3309] != 0) {
    param_1[0x31fc] = param_1[0x32a9];
    param_1[0x3420] = 0;
    param_1[0x3425] = 0;
    param_1[0x3225] = param_1[0x3306];
    param_1[0x3224] = param_1[0x3308];
    (**(code **)(*param_1 + 0x148))(param_1);
    if (param_1[0x3270] != 0) {
      (**(code **)(*param_1 + 200))(param_1);
    }
    param_1[0x328e] = 0;
    return 0;
  }
  param_1[0x328e] = 1;
  if ((LPVOID)param_1[0x32aa] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x32aa]);
    param_1[0x32aa] = 0;
  }
  (**(code **)(*param_1 + 0x44))(param_1);
  iVar1 = param_1[0x326b];
  while (iVar1 != 1) {
    pvVar2 = _malloc(param_1[0x3225] * param_1[0x3224] * 4);
    param_1[0x32aa] = (int)pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_1000123b;
    param_1[0x31fc] = (int)pvVar2;
    (**(code **)(*param_1 + 0x128))(param_1);
    (**(code **)(*param_1 + 0x15c))(param_1);
    (**(code **)(*param_1 + 200))(param_1);
    if ((LPVOID)param_1[0x32aa] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x32aa]);
      param_1[0x32aa] = 0;
    }
    (**(code **)(*param_1 + 0x44))(param_1);
    iVar1 = param_1[0x326b];
  }
  (**(code **)(*param_1 + 0x3c))(param_1);
  if (param_1[0x326a] != 1) {
    while( true ) {
      pvVar2 = _malloc(param_1[0x3225] * param_1[0x3224] * 4);
      param_1[0x32aa] = (int)pvVar2;
      if (pvVar2 == (void *)0x0) break;
      param_1[0x31fc] = (int)pvVar2;
      (**(code **)(*param_1 + 0x128))(param_1);
      (**(code **)(*param_1 + 0x15c))(param_1);
      (**(code **)(*param_1 + 200))(param_1);
      if ((LPVOID)param_1[0x32aa] != (LPVOID)0x0) {
        Mem_Free((LPVOID)param_1[0x32aa]);
        param_1[0x32aa] = 0;
      }
      (**(code **)(*param_1 + 0x3c))(param_1);
      if (param_1[0x326a] == 1) {
        return 0;
      }
    }
LAB_1000123b:
    param_1[0x3274] = 1;
  }
  return 0;
}




======================================================================
// Function: Present_ToScreen @ 10001290
======================================================================

undefined4 Present_ToScreen(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  HBITMAP h;
  HDC hdc;
  HGDIOBJ h_00;
  int iVar4;
  
  if (param_1[0x3279] == 1) {
    (**(code **)(*param_1 + 0x1b4))(param_1);
  }
  if (param_1[0x3274] != 1) {
    piVar2 = (int *)param_1[0x14];
    piVar1 = param_1 + 0x33ae;
    if (piVar2 == (int *)0x0) {
      *piVar1 = param_1[0x329a];
    }
    else {
      (**(code **)(*piVar2 + 0x44))(piVar2,piVar1);
      param_1[0x3229] = param_1[2];
    }
    if (param_1[0x3229] == 0x18 || param_1[0x3229] == 0x10) {
      (**(code **)(*param_1 + 0x84))(param_1);
    }
    if (param_1[0x3279] == 1) {
      param_1[0x3420] = param_1[0x3318];
      param_1[0x3425] = param_1[0x3319];
    }
    if (param_1[0x14] != 0) {
      param_1[0x3420] = 0;
      param_1[0x3425] = 0;
    }
    if (param_1[0x3207] == 0) {
      puVar3 = _malloc(0x34);
      param_1[0x3207] = (int)puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        param_1[0x3274] = 1;
        return 0;
      }
      param_1[0x3208] = (int)puVar3;
      param_1[0x3284] = 0x28;
      param_1[0x3209] = (int)(puVar3 + 0x28);
      *puVar3 = 0x28;
      *(undefined4 *)(param_1[0x3208] + 4) = 0;
      *(undefined4 *)(param_1[0x3208] + 8) = 0;
      *(undefined2 *)(param_1[0x3208] + 0xc) = 1;
      *(short *)(param_1[0x3208] + 0xe) = (short)param_1[0x3229];
      *(undefined4 *)(param_1[0x3208] + 0x10) = 0;
      *(undefined4 *)(param_1[0x3208] + 0x18) = 0;
      *(undefined4 *)(param_1[0x3208] + 0x1c) = 0;
      *(undefined4 *)(param_1[0x3208] + 0x20) = 0;
      *(undefined4 *)(param_1[0x3208] + 0x24) = 0;
    }
    *(short *)(param_1[0x3208] + 0xe) = (short)param_1[0x3229];
    *(int *)(param_1[0x3208] + 0x14) = param_1[0x3224] * param_1[0x3225];
    *(int *)(param_1[0x3208] + 4) = param_1[0x3225];
    *(int *)(param_1[0x3208] + 8) = -param_1[0x3224];
    h = CreateDIBitmap((HDC)*piVar1,(BITMAPINFOHEADER *)param_1[0x3208],4,(void *)param_1[0x31fc],
                       (BITMAPINFO *)param_1[0x3207],0);
    hdc = CreateCompatibleDC((HDC)0x0);
    h_00 = SelectObject(hdc,h);
    if (param_1[0x3229] == 8) {
      *(undefined2 *)(param_1[0x3208] + 0xe) = 0x20;
      StretchDIBits((HDC)*piVar1,param_1[0x3420],param_1[0x3425],param_1[0x32af],param_1[0x32b0],0,0
                    ,param_1[0x3225],param_1[0x3224],(void *)param_1[0x31fc],
                    (BITMAPINFO *)param_1[0x3207],0,0xcc0020);
    }
    else {
      BitBlt((HDC)*piVar1,param_1[0x3420],param_1[0x3425],param_1[0x3225],param_1[0x3224],hdc,0,0,
             0xcc0020);
    }
    piVar2 = (int *)param_1[0x14];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x68))(piVar2,*piVar1);
    }
    param_1[0x3290] = param_1[0x3225];
    param_1[0x3291] = param_1[0x3224];
    param_1[0x3292] = param_1[0x31fc];
    SelectObject(hdc,h_00);
    DeleteDC(hdc);
    DeleteObject(h);
    (**(code **)(*param_1 + 0x220))(param_1);
    if (param_1[0x14] != 0) {
      iVar4 = (**(code **)(*(int *)param_1[0x13] + 0x2c))((int *)param_1[0x13],0,1);
      if (iVar4 == -0x7789fe3e) {
        (**(code **)(*(int *)param_1[0x13] + 0x6c))((int *)param_1[0x13]);
        (**(code **)(*(int *)param_1[0x13] + 0x2c))((int *)param_1[0x13],0,1);
      }
    }
  }
  return 0;
}




======================================================================
// Function: Update_FPSCounter @ 10001590
======================================================================

undefined4 Update_FPSCounter(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  
  DVar1 = timeGetTime();
  uVar2 = DVar1 - *(int *)(param_1 + 0x88);
  if (1000 < uVar2) {
    *(uint *)(param_1 + 0x8c) = (uint)(*(int *)(param_1 + 0x84) * 1000) / uVar2;
    DVar1 = timeGetTime();
    *(DWORD *)(param_1 + 0x88) = DVar1;
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
  return 0;
}




======================================================================
// Function: Render_AllPresets @ 10001600
======================================================================

undefined4 Render_AllPresets(int *param_1)

{
  int iVar1;
  
  param_1[0x3240] = 0;
  do {
    (**(code **)(*param_1 + 0x54))(param_1);
    iVar1 = param_1[0x3240];
    param_1[0x3240] = iVar1 + 1U;
  } while (iVar1 + 1U <= (uint)param_1[0x32a1]);
  return 0;
}




======================================================================
// Function: Convert_BufferFormat @ 10001970
======================================================================

longlong Convert_BufferFormat(int param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  lVar2 = (ulonglong)*(uint *)(param_1 + 0xc894) * (ulonglong)*(uint *)(param_1 + 0xc890);
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  iVar3 = (int)lVar2;
  puVar5 = *(uint **)(param_1 + 0xc7f0);
  puVar6 = *(uint **)(param_1 + 0xc7f0);
  if (*(int *)(param_1 + 0xc8a4) == 0x18) {
    do {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = (uint *)((int)puVar6 + 3);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  else {
    do {
      uVar1 = *puVar5;
      uVar4 = uVar1 >> 6 & 0x3e0;
      *(ushort *)puVar6 =
           (ushort)(uVar1 >> 9) & 0x7c00 | (ushort)(uVar1 >> 3) & 0x1f | (ushort)uVar4;
      puVar5 = puVar5 + 1;
      puVar6 = (uint *)((int)puVar6 + 2);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return (ulonglong)uVar4 << 0x20;
}




======================================================================
// Function: Preset_LoadConfig @ 100019f0
======================================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Preset_LoadConfig(int *param_1)

{
  int *piVar1;
  
  param_1[0x3298] = param_1[param_1[0x3240] * 0x7b + 0xc39];
  (**(code **)(*param_1 + 0x164))(param_1);
  if ((param_1[0x320b] != 0) &&
     (param_1[0x3297] = param_1[param_1[0x3240] * 0x7b + 0xc3a], param_1[0x3297] != 0)) {
    if ((uint)param_1[0x3297] <= *(uint *)(param_1[0x320b] + 4)) {
      piVar1 = (int *)(((uint *)(param_1[0x320b] + 4))[param_1[0x3297]] + param_1[0x320b]);
      param_1[0x3393] = (int)(piVar1 + 4);
      param_1[0x336a] = *piVar1;
      param_1[0x3374] = piVar1[1];
      param_1[0x336f] = piVar1[2];
      if ((param_1[param_1[0x3240] * 0x7b + 0xc53] != param_1[0x3374]) ||
         (param_1[param_1[0x3240] * 0x7b + 0xc54] != param_1[0x336f])) {
        if (param_1[param_1[0x3240] * 0x7b + 0xc61] != 0) {
          Mem_Free((LPVOID)param_1[param_1[0x3240] * 0x7b + 0xc61]);
          param_1[param_1[0x3240] * 0x7b + 0xc61] = 0;
        }
        if (param_1[param_1[0x3240] * 0x7b + 0xc60] != 0) {
          Mem_Free((LPVOID)param_1[param_1[0x3240] * 0x7b + 0xc60]);
          param_1[param_1[0x3240] * 0x7b + 0xc60] = 0;
        }
        param_1[param_1[0x3240] * 0x7b + 0xc5f] = 0;
      }
      param_1[param_1[0x3240] * 0x7b + 0xc53] = param_1[0x3374];
      param_1[param_1[0x3240] * 0x7b + 0xc54] = param_1[0x336f];
      param_1[param_1[0x3240] * 0x7b + 0xc3d] = param_1[0x3374];
      param_1[param_1[0x3240] * 0x7b + 0xc3e] = param_1[0x336f];
      param_1[param_1[0x3240] * 0x7b + 0xc3b] = param_1[0x3393];
      return 1;
    }
  }
  param_1[param_1[0x3240] * 0x7b + 0xc31] = -1;
  param_1[param_1[0x3240] * 0x7b + 0xc3b] = 0;
  return 0;
}




======================================================================
// Function: Calc_RowPadding @ 10001ce0
======================================================================

undefined4 Calc_RowPadding(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0xc7e8) = 0;
  if (*(int *)(param_1 + 0x50) == 0) {
    if (*(int *)(param_1 + 0xc8a4) == 8) {
      uVar1 = *(uint *)(param_1 + 0xc894) & 3;
      if (uVar1 != 0) {
        *(uint *)(param_1 + 0xc7e8) = 4 - uVar1;
      }
    }
    else if (*(int *)(param_1 + 0xc8a4) == 0x10) {
      if ((*(uint *)(param_1 + 0xc894) & 1) != 0) {
        *(undefined4 *)(param_1 + 0xc7e8) = 1;
      }
    }
    else if ((*(int *)(param_1 + 0xc8a4) == 0x18) &&
            (uVar1 = *(uint *)(param_1 + 0xc894) & 3, uVar1 != 0)) {
      *(uint *)(param_1 + 0xc7e8) = 4 - uVar1;
    }
  }
  else if (*(int *)(param_1 + 8) == 8) {
    uVar1 = *(uint *)(param_1 + 0xc894) & 3;
    if (uVar1 != 0) {
      *(uint *)(param_1 + 0xc7e8) = 4 - uVar1;
    }
  }
  else if (*(int *)(param_1 + 8) == 0x10) {
    uVar1 = *(uint *)(param_1 + 0xc894) & 3;
    if (uVar1 != 0) {
      *(uint *)(param_1 + 0xc7e8) = 4 - uVar1;
    }
  }
  else {
    if (*(int *)(param_1 + 8) == 0x18) {
      uVar1 = *(uint *)(param_1 + 0xc894) & 3;
      if (uVar1 == 0) {
        return 0;
      }
      *(uint *)(param_1 + 0xc7e8) = 4 - uVar1;
    }
    if ((*(int *)(param_1 + 8) == 0x20) && (uVar1 = *(uint *)(param_1 + 0xc894) & 3, uVar1 != 0)) {
      *(uint *)(param_1 + 0xc7e8) = 4 - uVar1;
    }
  }
  return 0;
}




======================================================================
// Function: Release_PresetData @ 10001e40
======================================================================

void __fastcall Release_PresetData(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}




======================================================================
// Function: IWMPEffects_Render @ 10001e50
======================================================================

undefined4 IWMPEffects_Render(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x280))(param_1);
  param_1[0x3428] = 0;
  iVar1 = param_1[0x269e];
  param_1[0x3240] = iVar1;
  while (iVar1 != -1) {
    if (param_1[param_1[0x3240] * 0x7b + 0xc3f] == 2) {
      param_1[param_1[0x3240] * 0x7b + 0xc3f] = 1;
    }
    (**(code **)(*param_1 + 0x188))(param_1);
    iVar1 = param_1[0x3428];
    param_1[0x3428] = iVar1 + 1;
    iVar1 = param_1[iVar1 + 0x269f];
    param_1[0x3240] = iVar1;
  }
  return 0;
}




======================================================================
// Function: IWMPEffects_MediaInfo @ 10001ee0
======================================================================

undefined4 IWMPEffects_MediaInfo(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x284))(param_1);
  param_1[0x3428] = 0;
  iVar1 = param_1[0x269e];
  param_1[0x3240] = iVar1;
  while (iVar1 != -1) {
    (**(code **)(*param_1 + 0x188))(param_1);
    iVar1 = param_1[0x3428];
    param_1[0x3428] = iVar1 + 1;
    iVar1 = param_1[iVar1 + 0x269f];
    param_1[0x3240] = iVar1;
  }
  return 0;
}




======================================================================
// Function: IWMPEffects_SetUserPreset @ 10001f40
======================================================================

undefined4 IWMPEffects_SetUserPreset(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x27c))(param_1);
  param_1[0x3428] = 0;
  iVar1 = param_1[0x269e];
  param_1[0x3240] = iVar1;
  while (iVar1 != -1) {
    (**(code **)(*param_1 + 0x188))(param_1);
    iVar1 = param_1[0x3428];
    param_1[0x3428] = iVar1 + 1;
    iVar1 = param_1[iVar1 + 0x269f];
    param_1[0x3240] = iVar1;
  }
  return 0;
}




======================================================================
// Function: IterateSubVisualizations @ 10001fa0
======================================================================

undefined4 IterateSubVisualizations(int *param_1)

{
  param_1[0x3428] = 0;
  param_1[0x330a] = 0;
  param_1[0x330b] = 0;
  param_1[0x3406] = 0;
  param_1[0x3254] = param_1[0x3223];
  (**(code **)(*param_1 + 0x1e8))(param_1);
  if (param_1[0x3254] != param_1[0x3223]) {
    do {
      (**(code **)(*param_1 + 0x17c))(param_1);
      param_1[0x3406] = param_1[0x3406] + 1;
      param_1[0x3254] = param_1[0x3223];
      (**(code **)(*param_1 + 0x1e8))(param_1);
    } while (param_1[0x3254] != param_1[0x3223]);
  }
  param_1[0x330a] = 1;
  param_1[0x330b] = 2;
  param_1[0x3406] = 0;
  param_1[0x3254] = param_1[0x3223];
  (**(code **)(*param_1 + 0x1e8))(param_1);
  if (param_1[0x3254] != param_1[0x3223]) {
    do {
      (**(code **)(*param_1 + 0x17c))(param_1);
      param_1[0x3406] = param_1[0x3406] + 1;
      param_1[0x3254] = param_1[0x3223];
      (**(code **)(*param_1 + 0x1e8))(param_1);
    } while (param_1[0x3254] != param_1[0x3223]);
  }
  param_1[param_1[0x3428] + 0x269e] = -1;
  return 0;
}




======================================================================
// Function: Blend_PresetFrames @ 100020c0
======================================================================

undefined4 Blend_PresetFrames(int *param_1)

{
  param_1[0x3428] = 0;
  param_1[0x330a] = 0;
  param_1[0x330b] = 0;
  param_1[0x3406] = 0;
  param_1[0x3254] = param_1[0x3223];
  (**(code **)(*param_1 + 0x1e8))(param_1);
  if (param_1[0x3254] != param_1[0x3223]) {
    do {
      (**(code **)(*param_1 + 0x17c))(param_1);
      param_1[0x3406] = param_1[0x3406] + 1;
      param_1[0x3254] = param_1[0x3223];
      (**(code **)(*param_1 + 0x1e8))(param_1);
    } while (param_1[0x3254] != param_1[0x3223]);
  }
  param_1[0x330a] = 1;
  param_1[0x330b] = 1;
  param_1[0x3406] = 0;
  param_1[0x3254] = param_1[0x3223];
  (**(code **)(*param_1 + 0x1e8))(param_1);
  if (param_1[0x3254] != param_1[0x3223]) {
    do {
      (**(code **)(*param_1 + 0x17c))(param_1);
      param_1[0x3406] = param_1[0x3406] + 1;
      param_1[0x3254] = param_1[0x3223];
      (**(code **)(*param_1 + 0x1e8))(param_1);
    } while (param_1[0x3254] != param_1[0x3223]);
  }
  param_1[param_1[0x3428] + 0x269e] = -1;
  return 0;
}




======================================================================
// Function: Blend_AudioFrames @ 100021d0
======================================================================

undefined4 Blend_AudioFrames(int *param_1)

{
  param_1[0x3428] = 0;
  param_1[0x3406] = 0;
  param_1[0x330a] = 2;
  param_1[0x330b] = 2;
  param_1[0x3254] = param_1[0x3223];
  (**(code **)(*param_1 + 0x1e8))(param_1);
  if (param_1[0x3254] != param_1[0x3223]) {
    param_1[0x330a] = 1;
    param_1[0x330b] = 2;
    param_1[0x3254] = param_1[0x3223];
    (**(code **)(*param_1 + 0x1e8))(param_1);
    if (param_1[0x3254] != param_1[0x3223]) {
      do {
        (**(code **)(*param_1 + 0x17c))(param_1);
        param_1[0x3406] = param_1[0x3406] + 1;
        param_1[0x3254] = param_1[0x3223];
        (**(code **)(*param_1 + 0x1e8))(param_1);
      } while (param_1[0x3254] != param_1[0x3223]);
    }
  }
  param_1[param_1[0x3428] + 0x269e] = -1;
  return 0;
}




======================================================================
// Function: Effect_GenerateTexture @ 10002f60
======================================================================

undefined4 Effect_GenerateTexture(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x3240];
  iVar2 = param_1[iVar1 * 0x7b + 0xc5f];
  if (iVar2 == 0) {
    param_1[0x3205] = param_1[iVar1 * 0x7b + 0xc3b];
    if (param_1[iVar1 * 0x7b + 0xc60] != 0) {
LAB_10003077:
      param_1[0x31fb] = param_1[param_1[0x3240] * 0x7b + 0xc60];
      param_1[param_1[0x3240] * 0x7b + 0xc5f] = 1;
      return 1;
    }
    (**(code **)(*param_1 + 0xfc))(param_1);
    if (param_1[0x31fb] != 0) {
      param_1[0x31fb] = param_1[param_1[0x3240] * 0x7b + 0xc60];
      param_1[param_1[0x3240] * 0x7b + 0xc5f] = 1;
      return 1;
    }
  }
  else {
    if (iVar2 == 1) {
      param_1[0x3205] = param_1[iVar1 * 0x7b + 0xc60];
      if ((param_1[iVar1 * 0x7b + 0xc99] == 0) &&
         ((**(code **)(*param_1 + 0xf8))(param_1), param_1[0x31fb] == 0)) {
        return 0;
      }
      param_1[0x31fb] = param_1[param_1[0x3240] * 0x7b + 0xc99];
      param_1[param_1[0x3240] * 0x7b + 0xc5f] = 2;
      return 1;
    }
    if (iVar2 == 2) {
      param_1[0x3205] = param_1[iVar1 * 0x7b + 0xc99];
      if ((param_1[iVar1 * 0x7b + 0xc60] == 0) &&
         ((**(code **)(*param_1 + 0xfc))(param_1), param_1[0x31fb] == 0)) {
        return 0;
      }
      goto LAB_10003077;
    }
  }
  return 0;
}




======================================================================
// Function: Effect_Convolution @ 100030b0
======================================================================

longlong Effect_Convolution(int param_1)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  int *piVar6;
  short *psVar7;
  
  psVar5 = *(short **)(param_1 + 0xc814);
  psVar7 = *(short **)(param_1 + 0xc804);
  lVar2 = (ulonglong)*(uint *)(param_1 + 0xcb48) * (ulonglong)*(uint *)(param_1 + 0xcb44);
  do {
    while( true ) {
      uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
      if (*psVar5 != -1) break;
      sVar1 = psVar5[1];
      *psVar7 = sVar1;
      psVar7 = psVar7 + 1;
      piVar6 = (int *)(psVar5 + 2);
      psVar5 = psVar5 + 4;
      uVar4 = *piVar6 - 1;
      iVar3 = (int)lVar2 + -1;
      if (iVar3 == 0) goto LAB_1000310b;
      do {
        *psVar7 = sVar1;
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) goto LAB_1000310b;
        psVar7 = psVar7 + 1;
        uVar4 = uVar4 - 1;
        lVar2 = CONCAT44(uVar4,iVar3);
      } while (uVar4 != 0);
    }
    *psVar7 = *psVar5;
    psVar5 = psVar5 + 1;
    psVar7 = psVar7 + 1;
    iVar3 = (int)lVar2 + -1;
    lVar2 = CONCAT44(uVar4,iVar3);
  } while (iVar3 != 0);
LAB_1000310b:
  *(undefined4 *)(param_1 + 0xc814) = *(undefined4 *)(param_1 + 0xc804);
  return (ulonglong)uVar4 << 0x20;
}




======================================================================
// Function: Effect_GaussianBlur @ 10003120
======================================================================

undefined4 Effect_GaussianBlur(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  *(undefined4 *)(param_1 + 0xca20) = 0;
  *(undefined4 *)(param_1 + 0xc978) = 0;
  *(undefined4 *)(param_1 + 0xcb38) = 0;
  *(undefined4 *)(param_1 + 0xcb3c) = 0;
  *(undefined4 *)(param_1 + 0xcb40) = 0;
  *(undefined4 *)(param_1 + 0xcb34) = 0;
  *(undefined4 *)(param_1 + 0xc958) = 0;
  *(undefined4 *)(param_1 + 0xc930) = 0;
  *(undefined4 *)(param_1 + 0xc94c) = 0;
  *(undefined4 *)(param_1 + 0xc940) = 0;
  *(undefined4 *)(param_1 + 0xcdd0) = *(undefined4 *)(param_1 + 0xc998);
  *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(param_1 + 0xc994);
  uVar1 = *(uint *)(param_1 + 0xcdd4);
  if (0x7fffffff < uVar1) {
    *(undefined4 *)(param_1 + 0xcdd4) = 0;
    *(uint *)(param_1 + 0xcdd0) = uVar1 + *(int *)(param_1 + 0xc998);
    *(uint *)(param_1 + 0xc940) = -uVar1;
    *(undefined4 *)(param_1 + 0xcb38) = 1;
    if (*(int *)(param_1 + 0xd080) == 0) {
      *(undefined4 *)(param_1 + 0xc978) = 1;
    }
  }
  uVar1 = *(uint *)(param_1 + 0xcddc);
  if (0x7fffffff < uVar1) {
    *(undefined4 *)(param_1 + 0xcddc) = 0;
    *(uint *)(param_1 + 0xcdbc) = uVar1 + *(int *)(param_1 + 0xc994);
    *(uint *)(param_1 + 0xc958) = -uVar1;
    *(undefined4 *)(param_1 + 0xcb40) = 1;
    if (*(int *)(param_1 + 0xd094) == 0) {
      *(undefined4 *)(param_1 + 0xc978) = 1;
    }
  }
  if ((*(uint *)(param_1 + 0xcdd4) < *(uint *)(param_1 + 0xd080) + *(int *)(param_1 + 0xc894)) &&
     (*(uint *)(param_1 + 0xd080) < *(uint *)(param_1 + 0xcdd4) + *(int *)(param_1 + 0xcdd0))) {
    if ((*(uint *)(param_1 + 0xcddc) < *(uint *)(param_1 + 0xd094) + *(int *)(param_1 + 0xc890)) &&
       (*(uint *)(param_1 + 0xd094) < *(uint *)(param_1 + 0xcddc) + *(int *)(param_1 + 0xcdbc))) {
      *(undefined4 *)(param_1 + 0xca20) = 1;
      uVar1 = *(uint *)(param_1 + 0xd080);
      uVar2 = uVar1 + *(int *)(param_1 + 0xc894);
      uVar3 = *(uint *)(param_1 + 0xcdd4);
      uVar4 = uVar3 + *(int *)(param_1 + 0xcdd0);
      if (uVar2 < uVar4) {
        *(uint *)(param_1 + 0xc94c) = uVar4 - uVar2;
        *(undefined4 *)(param_1 + 0xcb3c) = 1;
        *(undefined4 *)(param_1 + 0xc978) = 1;
      }
      if (uVar3 < uVar1) {
        *(undefined4 *)(param_1 + 0xcdd4) = *(undefined4 *)(param_1 + 0xd080);
        *(int *)(param_1 + 0xc940) = *(int *)(param_1 + 0xc940) + (uVar1 - uVar3);
        *(undefined4 *)(param_1 + 0xcb38) = 1;
        *(undefined4 *)(param_1 + 0xc978) = 1;
      }
      uVar1 = *(uint *)(param_1 + 0xd094);
      uVar3 = uVar1 + *(int *)(param_1 + 0xc890);
      uVar2 = *(int *)(param_1 + 0xcddc) + *(int *)(param_1 + 0xcdbc);
      if (uVar3 < uVar2) {
        *(uint *)(param_1 + 0xc930) = uVar2 - uVar3;
        *(undefined4 *)(param_1 + 0xcb34) = 1;
        *(undefined4 *)(param_1 + 0xc978) = 1;
      }
      if (*(uint *)(param_1 + 0xcddc) < uVar1) {
        *(int *)(param_1 + 0xc958) =
             *(int *)(param_1 + 0xc958) + (uVar1 - *(uint *)(param_1 + 0xcddc));
        *(undefined4 *)(param_1 + 0xcb40) = 1;
        *(undefined4 *)(param_1 + 0xc978) = 1;
      }
    }
  }
  return 0;
}




======================================================================
// Function: Effect_ColorCycle @ 10003350
======================================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Effect_ColorCycle(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_1[0x32d0] == 1) {
    param_1[0x3377] = param_1[0x3425];
    param_1[0x3265] = param_1[0x3265] - param_1[0x3256];
  }
  if (param_1[0x32cd] == 1) {
    iVar2 = param_1[0x3265] - param_1[0x324c];
    param_1[0x3265] = iVar2;
    param_1[0x3377] = (param_1[0x3425] + param_1[0x3224]) - iVar2;
    param_1[0x3205] = param_1[0x3205] + param_1[0x3266] * param_1[0x324c] * 4;
  }
  if (param_1[0x32cf] == 1 || param_1[0x32ce] == 1) {
    param_1[0x32cc] = param_1[0x3266];
    param_1[0x3266] = (param_1[0x3266] - param_1[0x3253]) - param_1[0x3250];
    (**(code **)(*param_1 + 0x104))(param_1);
    if (param_1[0x3274] != 1) {
      param_1[0x3251] = param_1[0x3250] << 2;
      iVar2 = param_1[0x3265];
      iVar1 = param_1[0x3253];
      puVar4 = (undefined4 *)param_1[0x3205];
      puVar5 = (undefined4 *)param_1[0x32c2];
      do {
        puVar4 = (undefined4 *)((int)puVar4 + param_1[0x3251]);
        iVar3 = param_1[0x3266];
        do {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        puVar4 = puVar4 + iVar1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      param_1[0x32cb] = param_1[0x3205];
      param_1[0x3205] = param_1[0x32c2];
      (**(code **)(*param_1 + 0x1ac))(param_1);
    }
  }
  return 0;
}




======================================================================
// Function: Effect_Rotate @ 100034b0
======================================================================

undefined4 Effect_Rotate(int param_1)

{
  size_t sVar1;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0xce58) == 0) {
    if (*(int *)(param_1 + 0xccf0) < *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4) {
      if (*(LPVOID *)(param_1 + 0xce54) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)(param_1 + 0xce54));
      }
      sVar1 = *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4;
      *(size_t *)(param_1 + 0xccf0) = sVar1;
      pvVar2 = _malloc(sVar1);
      *(void **)(param_1 + 0xce54) = pvVar2;
    }
    if (*(int *)(param_1 + 0xce54) != 0) {
      *(int *)(param_1 + 0xcb08) = *(int *)(param_1 + 0xce54);
      *(undefined4 *)(param_1 + 0xce58) = 1;
      return 0;
    }
  }
  else if (*(int *)(param_1 + 0xccf8) == 0) {
    if (*(int *)(param_1 + 0xccfc) < *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4) {
      if (*(LPVOID *)(param_1 + 0xccf4) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)(param_1 + 0xccf4));
      }
      sVar1 = *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4;
      *(size_t *)(param_1 + 0xccfc) = sVar1;
      pvVar2 = _malloc(sVar1);
      *(void **)(param_1 + 0xccf4) = pvVar2;
    }
    if (*(int *)(param_1 + 0xccf4) != 0) {
      *(int *)(param_1 + 0xcb08) = *(int *)(param_1 + 0xccf4);
      *(undefined4 *)(param_1 + 0xccf8) = 1;
      return 0;
    }
  }
  else {
    if (*(int *)(param_1 + 0xcd3c) != 0) {
      if (*(int *)(param_1 + 0xcd54) == 0) {
        if (*(int *)(param_1 + 0xcd58) < *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4
           ) {
          if (*(LPVOID *)(param_1 + 0xcd50) != (LPVOID)0x0) {
            Mem_Free(*(LPVOID *)(param_1 + 0xcd50));
          }
          sVar1 = *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4;
          *(size_t *)(param_1 + 0xcd58) = sVar1;
          pvVar2 = _malloc(sVar1);
          *(void **)(param_1 + 0xcd50) = pvVar2;
        }
        if (*(int *)(param_1 + 0xcd50) == 0) goto LAB_10003699;
        *(int *)(param_1 + 0xcb08) = *(int *)(param_1 + 0xcd50);
        *(undefined4 *)(param_1 + 0xcd54) = 1;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0xcd40) < *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4) {
      if (*(LPVOID *)(param_1 + 0xcd38) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)(param_1 + 0xcd38));
      }
      sVar1 = *(int *)(param_1 + 0xc994) * *(int *)(param_1 + 0xc998) * 4;
      *(size_t *)(param_1 + 0xcd40) = sVar1;
      pvVar2 = _malloc(sVar1);
      *(void **)(param_1 + 0xcd38) = pvVar2;
    }
    if (*(int *)(param_1 + 0xcd38) != 0) {
      *(int *)(param_1 + 0xcb08) = *(int *)(param_1 + 0xcd38);
      *(undefined4 *)(param_1 + 0xcd3c) = 1;
      return 0;
    }
  }
LAB_10003699:
  *(undefined4 *)(param_1 + 0xcb08) = 0;
  *(undefined4 *)(param_1 + 0xc9d0) = 1;
  return 0;
}




======================================================================
// Function: Effect_Zoom @ 100036d0
======================================================================

undefined4 Effect_Zoom(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  pvVar1 = _malloc(*(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
                   *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c) * 4 + 8);
  *(void **)(param_1 + 0xc810) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0xc9d0) = 1;
    return 0;
  }
  *(void **)(param_1 + 0x3184 + *(int *)(param_1 + 0xc900) * 0x1ec) = pvVar1;
  *(int *)(param_1 + 0xd040) =
       *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
       *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c);
  iVar2 = *(int *)(param_1 + 0xd040);
  puVar3 = *(undefined4 **)(param_1 + 0xc810);
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}




======================================================================
// Function: Effect_Swirl @ 10003790
======================================================================

undefined4 Effect_Swirl(int param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc(*(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
                   *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c) * 4 + 8);
  *(void **)(param_1 + 0xc7ec) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0xc9d0) = 1;
    return 0;
  }
  *(void **)(param_1 + 0x3180 + *(int *)(param_1 + 0xc900) * 0x1ec) = pvVar1;
  return 0;
}




======================================================================
// Function: Effect_Water @ 10003800
======================================================================

undefined4 Effect_Water(int param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc(*(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
                   *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c) * 4 + 8);
  *(void **)(param_1 + 0xc7ec) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0xc9d0) = 1;
    return 0;
  }
  *(void **)(param_1 + 0x3264 + *(int *)(param_1 + 0xc900) * 0x1ec) = pvVar1;
  return 0;
}




======================================================================
// Function: Effect_Ripple @ 100038e0
======================================================================

undefined4 Effect_Ripple(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0xce5c) =
       *(undefined4 *)(param_1 + 0x314c + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(undefined4 *)(param_1 + 0xce50) =
       *(undefined4 *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x3150);
  puVar3 = *(undefined4 **)(param_1 + 0xc814);
  iVar2 = *(int *)(param_1 + 0xce50);
  iVar1 = *(int *)(param_1 + 0xce5c);
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc7ec) + iVar1 + iVar1 * 3 + -4);
  do {
    do {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + -1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar1 = *(int *)(param_1 + 0xce5c);
    puVar4 = puVar4 + iVar1 * 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}




======================================================================
// Function: Effect_Fade @ 10003970
======================================================================

undefined4 Effect_Fade(int param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x317c + *(int *)(param_1 + 0xc900) * 0x1ec) = 0;
  pvVar1 = *(LPVOID *)(param_1 + 0x3184 + *(int *)(param_1 + 0xc900) * 0x1ec);
  if (pvVar1 != (LPVOID)0x0) {
    Mem_Free(pvVar1);
    *(undefined4 *)(param_1 + 0x3184 + *(int *)(param_1 + 0xc900) * 0x1ec) = 0;
  }
  pvVar1 = *(LPVOID *)(param_1 + 0x3180 + *(int *)(param_1 + 0xc900) * 0x1ec);
  if (pvVar1 != (LPVOID)0x0) {
    Mem_Free(pvVar1);
    *(undefined4 *)(param_1 + 0x3180 + *(int *)(param_1 + 0xc900) * 0x1ec) = 0;
  }
  pvVar1 = *(LPVOID *)(param_1 + 0x3264 + *(int *)(param_1 + 0xc900) * 0x1ec);
  if (pvVar1 != (LPVOID)0x0) {
    Mem_Free(pvVar1);
    *(undefined4 *)(param_1 + 0x3264 + *(int *)(param_1 + 0xc900) * 0x1ec) = 0;
  }
  iVar2 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  *(undefined4 *)(param_1 + 0xc810) =
       *(undefined4 *)(param_1 + 0x3180 + *(int *)(param_1 + 0xc900) * 0x1ec);
  if (*(int *)(iVar2 + 0x3150) * *(int *)(iVar2 + 0x314c) != 0) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(iVar2 + 0x30ec);
    *(undefined1 *)(*(int *)(param_1 + 0xc83c) + -4) = 0;
    *(undefined4 *)(param_1 + 0xca18) = 0;
    if (-1 < *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
             *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c)) {
      do {
        **(uint **)(param_1 + 0xc83c) = **(uint **)(param_1 + 0xc83c) & 0xffffff;
        *(int *)(param_1 + 0xc83c) = *(int *)(param_1 + 0xc83c) + 4;
        iVar2 = *(int *)(param_1 + 0xca18) + 1;
        *(int *)(param_1 + 0xca18) = iVar2;
      } while (iVar2 <= *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
                        *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c));
    }
  }
  return 0;
}




======================================================================
// Function: Transform_PixelOffset @ 10003b20
======================================================================

undefined4 Transform_PixelOffset(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  if (*(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) * *(int *)(iVar1 + 0x314c) !=
      0) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(iVar1 + 0x30ec);
    *(undefined1 *)(*(int *)(param_1 + 0xc83c) + -4) = 0;
    *(undefined4 *)(param_1 + 0xca18) = 0;
    if (-1 < *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
             *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c)) {
      do {
        **(uint **)(param_1 + 0xc83c) = **(uint **)(param_1 + 0xc83c) & 0xffffff;
        *(int *)(param_1 + 0xc83c) = *(int *)(param_1 + 0xc83c) + 4;
        iVar1 = *(int *)(param_1 + 0xca18) + 1;
        *(int *)(param_1 + 0xca18) = iVar1;
      } while (iVar1 <= *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
                        *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c));
      return 0;
    }
  }
  return 0;
}




======================================================================
// Function: Transform_Configure @ 100040d0
======================================================================

undefined4 Transform_Configure(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 extraout_ST0;
  longlong lVar4;
  
  iVar2 = *(int *)(param_1 + 0xc8d0);
  iVar1 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  iVar3 = *(int *)(param_1 + 0x314c + *(int *)(param_1 + 0xc900) * 0x1ec) / 2 +
          *(int *)(iVar1 + 0x3140);
  *(int *)(param_1 + 0xcd88) = iVar3;
  *(int *)(param_1 + 0xcbc4) = iVar3 - iVar2;
  *(int *)(param_1 + 0xcbc8) = *(int *)(param_1 + 0xc89c) - *(int *)(param_1 + 0xc8d8);
  lVar4 = __ftol();
  *(int *)(param_1 + 0xc95c) = (int)lVar4;
  lVar4 = __ftol();
  *(int *)(param_1 + 0xc964) = (int)lVar4;
  iVar3 = *(int *)(param_1 + 0xc8d8) + (int)lVar4;
  *(int *)(param_1 + 0xcd88) = iVar2 + *(int *)(param_1 + 0xc95c);
  *(int *)(param_1 + 0xcd90) = iVar3;
  *(int *)(iVar1 + 0x3148) = iVar3;
  *(int *)(param_1 + 0xd098) = *(int *)(param_1 + 0xca90);
  if (*(int *)(param_1 + 0xca90) < *(int *)(param_1 + 0xca94)) {
    *(int *)(param_1 + 0xd098) = *(int *)(param_1 + 0xca94);
  }
  iVar1 = *(int *)(param_1 + 0xd068);
  *(int *)(param_1 + 0xcbc8) = *(int *)(param_1 + 0xd098) - *(int *)(param_1 + 0xcd90);
  lVar4 = __ftol();
  *(int *)(param_1 + 0xcde4) = (int)lVar4;
  *(float *)(param_1 + 0xc968) =
       (float)(extraout_ST0 * (float10)*(float *)(param_1 + 0xbc28 + iVar1 * 4));
  *(undefined4 *)(param_1 + 0x30e0 + *(int *)(param_1 + 0xc900) * 0x1ec) =
       *(undefined4 *)(param_1 + 0xcde4);
  return 0;
}




======================================================================
// Function: Geom_RotateZoom @ 10004220
======================================================================

undefined4 Geom_RotateZoom(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x3240];
  param_1[0x3266] = param_1[iVar1 * 0x7b + 0xc53];
  param_1[0x3265] = param_1[iVar1 * 0x7b + 0xc54];
  iVar1 = param_1[iVar1 * 0x7b + 0xc58];
  param_1[0x33b9] = iVar1;
  if (-1 < iVar1) {
    (**(code **)(*param_1 + 0x60))(param_1);
    param_1[param_1[0x3240] * 0x7b + 0xc5d] = param_1[0x3266];
    param_1[param_1[0x3240] * 0x7b + 0xc5e] = param_1[0x3265];
    param_1[param_1[0x3240] * 0x7b + 0xc3d] = param_1[0x3266];
    param_1[param_1[0x3240] * 0x7b + 0xc3e] = param_1[0x3265];
    param_1[param_1[0x3240] * 0x7b + 0xc59] = param_1[0x33b9];
    return 0;
  }
  param_1[0x33b9] = -iVar1;
  (**(code **)(*param_1 + 0x60))(param_1);
  param_1[param_1[0x3240] * 0x7b + 0xc5d] = param_1[0x3266];
  param_1[param_1[0x3240] * 0x7b + 0xc5e] = param_1[0x3265];
  param_1[param_1[0x3240] * 0x7b + 0xc3d] = param_1[0x3266];
  param_1[param_1[0x3240] * 0x7b + 0xc3e] = param_1[0x3265];
  param_1[param_1[0x3240] * 0x7b + 0xc59] = -param_1[0x33b9];
  return 0;
}




======================================================================
// Function: Transform_Motion @ 100047e0
======================================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Transform_Motion(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  size_t _Size;
  
  param_1[0x3315] = *(int *)param_1[0x32ac];
  param_1[0x32a2] = ((int *)param_1[0x32ac])[1];
  _Size = param_1[0x3315] + param_1[0x32a2] * 4;
  param_1[0x3315] = _Size;
  pvVar5 = _malloc(_Size);
  param_1[0x32a8] = (int)pvVar5;
  if (pvVar5 != (void *)0x0) {
    puVar1 = (undefined4 *)param_1[0x32ac];
    puVar2 = (undefined4 *)param_1[0x32a8];
    *puVar2 = *puVar1;
    iVar3 = puVar1[1];
    puVar2[1] = iVar3;
    param_1[0x32a2] = iVar3;
    param_1[0x323c] = 1;
    do {
      iVar3 = param_1[0x32ac];
      iVar4 = param_1[0x323c];
      if (iVar4 == 1) {
        param_1[0x31fd] = *(int *)(iVar3 + 4) * 4 + 8 + param_1[0x32a8];
      }
      *(int *)(param_1[0x32a8] + 4 + iVar4 * 4) = param_1[0x31fd] - param_1[0x32a8];
      piVar6 = (int *)(((int *)(iVar3 + 4))[iVar4] + param_1[0x32ac]);
      param_1[0x31fe] = (int)piVar6;
      param_1[0x336a] = *piVar6;
      (**(code **)(*param_1 + 0x180))(param_1);
      iVar3 = param_1[0x323c];
      param_1[0x323c] = iVar3 + 1;
    } while (iVar3 + 1 <= param_1[0x32a2]);
    param_1[0x32ac] = param_1[0x32a8];
    param_1[0x32a8] = 0;
    return 0;
  }
  param_1[0x3274] = 1;
  param_1[0x32ac] = 0;
  return 0;
}




======================================================================
// Function: Transform_Wrap @ 10004930
======================================================================

longlong Transform_Wrap(int param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  uint *puVar13;
  
  if ((*(int *)(param_1 + 0xcda8) == 0x16) || (*(int *)(param_1 + 0xcda8) == 0xc16)) {
    iVar5 = *(int *)(param_1 + 0xc7f8);
    puVar2 = *(undefined4 **)(param_1 + 0xc7f4);
    *puVar2 = 0x16;
    iVar3 = *(int *)(iVar5 + 4);
    puVar2[1] = iVar3;
    *(int *)(param_1 + 0xc998) = iVar3;
    iVar7 = *(int *)(iVar5 + 8);
    puVar2[2] = iVar7;
    *(int *)(param_1 + 0xc994) = iVar7;
    puVar11 = (ushort *)(iVar5 + 0xc);
    *(undefined1 *)(puVar2 + 3) = 0;
    puVar9 = puVar2 + 4;
    iVar7 = iVar7 * iVar3;
    do {
      while (uVar1 = *puVar11, uVar1 == 0xffff) {
        uVar8 = (uint)puVar11[1] << 6;
        uVar8 = (uVar8 & 0x1f0000) << 3 | (puVar11[1] & 0x1f) << 3 | uVar8 & 0xf800;
        *puVar9 = uVar8;
        puVar12 = puVar11 + 2;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 4;
        uVar6 = *(int *)puVar12 - 1;
        iVar7 = iVar7 + -1;
        if (iVar7 == 0) goto LAB_10004aff;
        do {
          *puVar9 = uVar8;
          iVar7 = iVar7 + -1;
          if (iVar7 == 0) {
            puVar9 = puVar9 + 1;
            goto LAB_10004aff;
          }
          puVar9 = puVar9 + 1;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      uVar8 = (uint)uVar1 << 6;
      uVar6 = uVar8 & 0xf800;
      *puVar9 = (uVar8 & 0x1f0000) << 3 | (uVar1 & 0x1f) << 3 | uVar6;
      puVar11 = puVar11 + 1;
      puVar9 = puVar9 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
LAB_10004aff:
    *(uint **)(param_1 + 0xc7f4) = puVar9;
    return (ulonglong)uVar6 << 0x20;
  }
  iVar5 = *(int *)(param_1 + 0xc7f8);
  puVar2 = *(undefined4 **)(param_1 + 0xc7f4);
  *puVar2 = 0x24;
  uVar8 = *(uint *)(iVar5 + 4);
  puVar2[1] = uVar8;
  *(uint *)(param_1 + 0xc998) = uVar8;
  uVar6 = *(uint *)(iVar5 + 8);
  puVar2[2] = uVar6;
  *(uint *)(param_1 + 0xc994) = uVar6;
  puVar9 = (uint *)(iVar5 + 0xc);
  *(undefined1 *)(puVar2 + 3) = 0;
  puVar13 = puVar2 + 4;
  lVar4 = (ulonglong)uVar6 * (ulonglong)uVar8;
  uVar8 = (uint)((ulonglong)lVar4 >> 0x20);
  iVar5 = (int)lVar4;
  if (*(int *)(param_1 + 0xcda8) == 0x24) {
    do {
      *puVar13 = *puVar9 & 0xffffff;
      puVar9 = (uint *)((int)puVar9 + 3);
      puVar13 = puVar13 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  else {
    do {
      while( true ) {
        uVar8 = (uint)((ulonglong)lVar4 >> 0x20);
        if (((*puVar9 & 0xffffff) != 0xffffff) ||
           ((*(uint *)((int)puVar9 + 3) & 0xffffff) != 0xffffff)) break;
        uVar6 = *(uint *)((int)puVar9 + 6) & 0xffffff;
        *puVar13 = uVar6;
        puVar10 = (uint *)((int)puVar9 + 9);
        puVar13 = puVar13 + 1;
        puVar9 = puVar9 + 3;
        uVar8 = (*puVar10 & 0xffffff) - 1;
        iVar5 = (int)lVar4 + -1;
        if (iVar5 == 0) goto LAB_10004a15;
        do {
          *puVar13 = uVar6;
          iVar5 = iVar5 + -1;
          if (iVar5 == 0) {
            puVar13 = puVar13 + 1;
            goto LAB_10004a15;
          }
          puVar13 = puVar13 + 1;
          uVar8 = uVar8 - 1;
          lVar4 = CONCAT44(uVar8,iVar5);
        } while (uVar8 != 0);
      }
      *puVar13 = *puVar9 & 0xffffff;
      puVar9 = (uint *)((int)puVar9 + 3);
      puVar13 = puVar13 + 1;
      iVar5 = (int)lVar4 + -1;
      lVar4 = CONCAT44(uVar8,iVar5);
    } while (iVar5 != 0);
  }
LAB_10004a15:
  *(uint **)(param_1 + 0xc7f4) = puVar13;
  return (ulonglong)uVar8 << 0x20;
}




======================================================================
// Function: Transform_WithAudio @ 10004b10
======================================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Transform_WithAudio(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint *puVar8;
  
  *(undefined4 *)(param_1 + 0xccb4) =
       *(undefined4 *)(param_1 + 0x31c8 + *(int *)(param_1 + 0xc900) * 0x1ec);
  uVar3 = *(uint *)(param_1 + 0xccb4) & 0xf;
  if (uVar3 == 0) {
    uVar3 = 0xf;
  }
  *(uint *)(param_1 + 0xccb4) = uVar3;
  *(undefined4 *)(param_1 + 0xcf70) =
       *(undefined4 *)(param_1 + 0x313c + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(int *)(param_1 + 0xd040) =
       *(int *)(param_1 + 0x314c + *(int *)(param_1 + 0xc900) * 0x1ec) *
       *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(int *)(param_1 + 0xd03c) = *(int *)(param_1 + 0xd040) << 2;
  *(undefined4 *)(param_1 + 0xc98c) =
       *(undefined4 *)(param_1 + 0x314c + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(undefined4 *)(param_1 + 0xce40) = *(undefined4 *)(param_1 + 0xc98c);
  *(int *)(param_1 + 0xc984) = *(int *)(param_1 + 0xc814) + -4 + *(int *)(param_1 + 0xd03c);
  *(int *)(param_1 + 0xc980) = *(int *)(param_1 + 0xc810) + -4 + *(int *)(param_1 + 0xd03c);
  *(undefined4 *)(param_1 + 0xca64) = 0;
  if ((*(uint *)(param_1 + 0xccb4) & 8) == 0) {
    puVar7 = *(undefined4 **)(param_1 + 0xc810);
    iVar4 = *(int *)(param_1 + 0xd040);
    iVar2 = *(int *)(param_1 + 0xcf70);
    piVar6 = *(int **)(param_1 + 0xc814);
    do {
      if (*piVar6 != iVar2) {
        *puVar7 = 0xfffe;
      }
      puVar7 = puVar7 + 1;
      piVar6 = piVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    puVar8 = *(uint **)(param_1 + 0xc810);
    piVar6 = *(int **)(param_1 + 0xc814);
    iVar4 = *(int *)(param_1 + 0xd040);
    iVar2 = *(int *)(param_1 + 0xcf70);
    uVar3 = 0;
    do {
      if (*piVar6 == iVar2) {
        uVar5 = 0;
        if (uVar3 != 0) {
          uVar5 = 0xffff;
        }
        *puVar8 = *puVar8 | uVar5;
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 + 1;
        if (0xff < uVar3) {
          uVar3 = 0xff;
        }
        *puVar8 = *puVar8 & 0xffff0000 | uVar3;
        if (*(uint *)(param_1 + 0xca64) < uVar3) {
          *(uint *)(param_1 + 0xca64) = uVar3;
        }
      }
      piVar1 = (int *)(param_1 + 0xce40);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0xce40) = *(undefined4 *)(param_1 + 0xc98c);
      }
      piVar6 = piVar6 + 1;
      puVar8 = puVar8 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(undefined4 *)(param_1 + 0xce40) = *(undefined4 *)(param_1 + 0xc98c);
  if ((*(uint *)(param_1 + 0xccb4) & 4) != 0) {
    piVar6 = *(int **)(param_1 + 0xc984);
    puVar8 = *(uint **)(param_1 + 0xc980);
    iVar4 = *(int *)(param_1 + 0xd040);
    iVar2 = *(int *)(param_1 + 0xcf70);
    uVar3 = 0;
    do {
      if (*piVar6 == iVar2) {
        uVar5 = 0;
        if (uVar3 != 0) {
          uVar5 = 0xffff;
        }
        *puVar8 = *puVar8 | uVar5;
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 + 1;
        if (0xff < uVar3) {
          uVar3 = 0xff;
        }
        if ((uVar3 < (*puVar8 & 0xffff)) && (*puVar8 = uVar3, *(uint *)(param_1 + 0xca64) < uVar3))
        {
          *(uint *)(param_1 + 0xca64) = uVar3;
        }
      }
      piVar1 = (int *)(param_1 + 0xce40);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0xce40) = *(undefined4 *)(param_1 + 0xc98c);
      }
      piVar6 = piVar6 + -1;
      puVar8 = puVar8 + -1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(undefined4 *)(param_1 + 0xc988) =
       *(undefined4 *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(undefined4 *)(param_1 + 0xce3c) = *(undefined4 *)(param_1 + 0xc988);
  *(int *)(param_1 + 0xce40) = *(int *)(param_1 + 0xc98c) << 2;
  if ((*(uint *)(param_1 + 0xccb4) & 2) != 0) {
    puVar8 = *(uint **)(param_1 + 0xc810);
    piVar6 = *(int **)(param_1 + 0xc814);
    *(uint **)(param_1 + 0xce30) = puVar8;
    *(int **)(param_1 + 0xce4c) = piVar6;
    iVar4 = *(int *)(param_1 + 0xcf70);
    uVar3 = 0;
    do {
      do {
        if (*piVar6 == iVar4) {
          uVar5 = 0;
          if (uVar3 != 0) {
            uVar5 = 0xffff;
          }
          *puVar8 = *puVar8 | uVar5;
          uVar3 = 0;
        }
        else {
          uVar3 = uVar3 + 1;
          if (0xff < uVar3) {
            uVar3 = 0xff;
          }
          if ((uVar3 < (*puVar8 & 0xffff)) && (*puVar8 = uVar3, *(uint *)(param_1 + 0xca64) < uVar3)
             ) {
            *(uint *)(param_1 + 0xca64) = uVar3;
          }
        }
        piVar6 = (int *)((int)piVar6 + *(int *)(param_1 + 0xce40));
        puVar8 = (uint *)((int)puVar8 + *(int *)(param_1 + 0xce40));
        piVar1 = (int *)(param_1 + 0xc988);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      *(undefined4 *)(param_1 + 0xc988) = *(undefined4 *)(param_1 + 0xce3c);
      uVar3 = 0;
      *(int *)(param_1 + 0xce30) = *(int *)(param_1 + 0xce30) + 1;
      *(int *)(param_1 + 0xce30) = *(int *)(param_1 + 0xce30) + 1;
      *(int *)(param_1 + 0xce30) = *(int *)(param_1 + 0xce30) + 1;
      *(int *)(param_1 + 0xce30) = *(int *)(param_1 + 0xce30) + 1;
      *(int *)(param_1 + 0xce4c) = *(int *)(param_1 + 0xce4c) + 1;
      *(int *)(param_1 + 0xce4c) = *(int *)(param_1 + 0xce4c) + 1;
      *(int *)(param_1 + 0xce4c) = *(int *)(param_1 + 0xce4c) + 1;
      *(int *)(param_1 + 0xce4c) = *(int *)(param_1 + 0xce4c) + 1;
      puVar8 = *(uint **)(param_1 + 0xce30);
      piVar6 = *(int **)(param_1 + 0xce4c);
      piVar1 = (int *)(param_1 + 0xc98c);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  *(undefined4 *)(param_1 + 0xc98c) =
       *(undefined4 *)(param_1 + 0x314c + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(undefined4 *)(param_1 + 0xc988) =
       *(undefined4 *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(undefined4 *)(param_1 + 0xce3c) = *(undefined4 *)(param_1 + 0xc988);
  *(int *)(param_1 + 0xce40) = *(int *)(param_1 + 0xc98c) << 2;
  if ((*(uint *)(param_1 + 0xccb4) & 1) != 0) {
    piVar6 = *(int **)(param_1 + 0xc984);
    puVar8 = *(uint **)(param_1 + 0xc980);
    iVar4 = *(int *)(param_1 + 0xcf70);
    uVar3 = 0;
    do {
      do {
        if (*piVar6 == iVar4) {
          uVar5 = 0;
          if (uVar3 != 0) {
            uVar5 = 0xffff;
          }
          *puVar8 = *puVar8 | uVar5;
          uVar3 = 0;
        }
        else {
          uVar3 = uVar3 + 1;
          if (0xff < uVar3) {
            uVar3 = 0xff;
          }
          if ((uVar3 < (*puVar8 & 0xffff)) && (*puVar8 = uVar3, *(uint *)(param_1 + 0xca64) < uVar3)
             ) {
            *(uint *)(param_1 + 0xca64) = uVar3;
          }
        }
        piVar6 = (int *)((int)piVar6 - *(int *)(param_1 + 0xce40));
        puVar8 = (uint *)((int)puVar8 - *(int *)(param_1 + 0xce40));
        piVar1 = (int *)(param_1 + 0xc988);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      *(undefined4 *)(param_1 + 0xc988) = *(undefined4 *)(param_1 + 0xce3c);
      uVar3 = 0;
      *(int *)(param_1 + 0xc980) = *(int *)(param_1 + 0xc980) + -1;
      *(int *)(param_1 + 0xc980) = *(int *)(param_1 + 0xc980) + -1;
      *(int *)(param_1 + 0xc980) = *(int *)(param_1 + 0xc980) + -1;
      *(int *)(param_1 + 0xc980) = *(int *)(param_1 + 0xc980) + -1;
      *(int *)(param_1 + 0xc984) = *(int *)(param_1 + 0xc984) + -1;
      *(int *)(param_1 + 0xc984) = *(int *)(param_1 + 0xc984) + -1;
      *(int *)(param_1 + 0xc984) = *(int *)(param_1 + 0xc984) + -1;
      *(int *)(param_1 + 0xc984) = *(int *)(param_1 + 0xc984) + -1;
      puVar8 = *(uint **)(param_1 + 0xc980);
      piVar6 = *(int **)(param_1 + 0xc984);
      piVar1 = (int *)(param_1 + 0xc98c);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  *(undefined4 *)(param_1 + 0x32ac + *(int *)(param_1 + 0xc900) * 0x1ec) =
       *(undefined4 *)(param_1 + 0xca64);
  return 0;
}




======================================================================
// Function: PixelBlit_SimpleCopy @ 10005050
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PixelBlit_SimpleCopy(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  longlong lVar12;
  
  if ((param_1[0x3266] != 0 && param_1[0x3205] != 0) && param_1[0x3265] != 0) {
    param_1[0x3267] = param_1[0x3266] << 2;
    param_1[0x3226] = param_1[0x3225] << 2;
    if (param_1[param_1[0x3240] * 0x7b + 0xc62] == 1) {
      (**(code **)(*param_1 + 0x138))(param_1);
      iVar9 = param_1[0x3240];
      if ((((param_1[iVar9 * 0x7b + 0xc63] != 0) || (param_1[iVar9 * 0x7b + 0xc64] != 0)) ||
          (param_1[iVar9 * 0x7b + 0xc65] != 0)) ||
         ((param_1[iVar9 * 0x7b + 0xc6d] != 0 || (param_1[iVar9 * 0x7b + 0xc70] != 0)))) {
        param_1[0x3397] = param_1[0x3266];
        param_1[0x3394] = param_1[0x3265];
        param_1[0x31fb] = param_1[0x3205];
        (**(code **)(*param_1 + 0xa8))(param_1);
      }
    }
    iVar9 = param_1[0x3240];
    param_1[0x341e] = 0;
    iVar10 = param_1[iVar9 * 0x7b + 0xc86];
    iVar1 = param_1[iVar9 * 0x7b + 0xc84];
    iVar2 = param_1[iVar9 * 0x7b + 0xc93];
    iVar3 = param_1[iVar9 * 0x7b + 0xc6c];
    iVar4 = param_1[iVar9 * 0x7b + 0xc6f];
    iVar5 = param_1[iVar9 * 0x7b + 0xc6e];
    iVar6 = param_1[iVar9 * 0x7b + 0xc6a];
    iVar7 = param_1[iVar9 * 0x7b + 0xc69];
    lVar12 = __ftol();
    if ((((((iVar10 != 0 && iVar1 == 1 || iVar2 != 0 && iVar3 != 0) || iVar4 != 0 && iVar5 != 0) ||
          iVar6 != 0 && iVar7 != 0) || (int)lVar12 != 0) || param_1[iVar9 * 0x7b + 0xca9] != 0) ||
        1 < param_1[iVar9 * 0x7b + 0xc7c]) {
      (**(code **)(*param_1 + 0x144))(param_1);
      return 0;
    }
    if ((float)param_1[iVar9 * 0x38 + 0x57] != _DAT_10021260) {
      (**(code **)(*param_1 + 0x140))(param_1);
      return 0;
    }
    piVar8 = (int *)((((param_1[0x3377] + param_1[0x3265]) - param_1[0x3425]) + -1) *
                     param_1[0x3225] * 4 + (param_1[0x3375] - param_1[0x3420]) * 4 + param_1[0x31fc]
                    );
    piVar11 = (int *)param_1[0x3205];
    iVar9 = param_1[0x3266];
    iVar10 = param_1[0x3265];
    iVar1 = param_1[0x33dc];
    if (iVar1 == -1) {
      do {
        do {
          *piVar8 = *piVar11;
          piVar11 = piVar11 + 1;
          piVar8 = piVar8 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        iVar9 = param_1[0x3266];
        piVar8 = (int *)((int)piVar8 + (-param_1[0x3226] - param_1[0x3267]));
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    else {
      do {
        do {
          if (*piVar11 != iVar1) {
            *piVar8 = *piVar11;
          }
          piVar11 = piVar11 + 1;
          piVar8 = piVar8 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        iVar9 = param_1[0x3266];
        piVar8 = (int *)((int)piVar8 + (-param_1[0x3226] - param_1[0x3267]));
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  return 0;
}




======================================================================
// Function: PixelBlit_AlphaBlend @ 10005310
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 PixelBlit_AlphaBlend(int *param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  longlong lVar7;
  
  if (param_1[param_1[0x3240] * 0x7b + 0xca9] == 1) {
    (**(code **)(*param_1 + 0x254))(param_1);
  }
  else if (param_1[param_1[0x3240] * 0x7b + 0xca9] == 2) {
    (**(code **)(*param_1 + 600))(param_1);
  }
  else {
    param_1[0x3226] = param_1[0x3225] << 2;
    param_1[0x3397] = param_1[0x3266];
    param_1[0x3394] = param_1[0x3265];
    param_1[0x338d] = (int)((float)param_1[param_1[0x3240] * 0x7b + 0xc73] / _DAT_100212d8);
    param_1[0x338e] = (int)((float)param_1[param_1[0x3240] * 0x7b + 0xc74] / _DAT_100212d8);
    param_1[0x3391] = (int)((float)param_1[param_1[0x3240] * 0x7b + 0xc9b] / _DAT_100212d8);
    param_1[0x33f4] = param_1[param_1[0x3240] * 0x7b + 0xc66];
    param_1[0x33f3] = param_1[param_1[0x3240] * 0x7b + 0xc67];
    param_1[0x33f1] = param_1[param_1[0x3240] * 0x7b + 0xc68];
    puVar2 = (uint *)((((param_1[0x3377] + param_1[0x3265]) - param_1[0x3425]) + -1) *
                      param_1[0x3225] * 4 + (param_1[0x3375] - param_1[0x3420]) * 4 +
                     param_1[0x31fc]);
    puVar6 = (uint *)param_1[0x3205];
    do {
      do {
        param_1[0x3301] = (int)puVar2;
        param_1[0x3302] = (int)puVar6;
        uVar5 = *puVar6;
        if (uVar5 != param_1[0x33dc]) {
          if ((uVar5 & 0xff000000) != 0) {
            if ((uVar5 & 0xff000000) == 0xff000000) goto LAB_1000586d;
            param_1[0x33f6] = uVar5 >> 0x18;
            param_1[0x33f7] = (uVar5 >> 0x18) << 0x18;
            param_1[0x3367] = uVar5 & 0xff;
            param_1[0x33ab] = uVar5 >> 8 & 0xff;
            param_1[0x33d1] = uVar5 >> 0x10 & 0xff;
            uVar5 = *puVar2;
            param_1[0x3339] = uVar5 & 0xff;
            param_1[0x3346] = uVar5 >> 8 & 0xff;
            param_1[0x3348] = uVar5 >> 0x10 & 0xff;
            param_1[0x32df] = (int)((float)param_1[0x33f6] / _DAT_100212d8);
            param_1[0x32e0] = (int)(_DAT_1002129c - (float)param_1[0x32df]);
            param_1[0x32df] = (int)((float)param_1[0x32df] + (float)param_1[0x338d]);
            param_1[0x32e0] = (int)((float)param_1[0x32e0] + (float)param_1[0x338e]);
            lVar7 = __ftol();
            param_1[0x33d1] = (int)lVar7;
            lVar7 = __ftol();
            param_1[0x3367] = (int)lVar7;
            lVar7 = __ftol();
            param_1[0x33ab] = (int)lVar7;
            if (param_1[param_1[0x3240] * 0x7b + 0xc9b] != 0) {
              if (param_1[0x33f4] != 0) {
                lVar7 = __ftol();
                param_1[0x33d1] = param_1[0x33d1] + (int)lVar7;
              }
              if (param_1[0x33f1] != 0) {
                lVar7 = __ftol();
                param_1[0x3367] = param_1[0x3367] + (int)lVar7;
              }
              if (param_1[0x33f3] != 0) {
                lVar7 = __ftol();
                param_1[0x33ab] = param_1[0x33ab] + (int)lVar7;
              }
              if (0xff < param_1[0x33d1]) {
                param_1[0x33d1] = 0xff;
              }
              if (0xff < param_1[0x3367]) {
                param_1[0x3367] = 0xff;
              }
              if (0xff < param_1[0x33ab]) {
                param_1[0x33ab] = 0xff;
              }
            }
            if (param_1[0x33d1] < 0) {
              param_1[0x33d1] = 0;
            }
            if (param_1[0x3367] < 0) {
              param_1[0x3367] = 0;
            }
            if (param_1[0x33ab] < 0) {
              param_1[0x33ab] = 0;
            }
            uVar5 = param_1[0x3367];
            uVar4 = param_1[0x33ab];
            uVar3 = param_1[0x33d1];
            if (0xff < uVar3) {
              uVar3 = 0xff;
            }
            if (0xff < uVar5) {
              uVar5 = 0xff;
            }
            if (0xff < uVar4) {
              uVar4 = 0xff;
            }
            uVar5 = CONCAT22((short)uVar3,CONCAT11((char)uVar4,(char)uVar5)) & 0xffffff |
                    param_1[0x33f7];
            puVar2 = (uint *)param_1[0x3301];
            puVar6 = (uint *)param_1[0x3302];
          }
          *puVar2 = uVar5;
        }
LAB_1000586d:
        puVar6 = puVar6 + 1;
        puVar2 = puVar2 + 1;
        piVar1 = param_1 + 0x3397;
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      param_1[0x3397] = param_1[0x3266];
      puVar2 = (uint *)((int)puVar2 + (param_1[0x3266] * -4 - param_1[0x3226]));
      puVar6 = (uint *)((int)puVar6 + param_1[0x341e]);
      piVar1 = param_1 + 0x3394;
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  return 0;
}




======================================================================
// Function: Transform_Scale @ 100058c0
======================================================================

undefined4 Transform_Scale(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  
  *(int *)(param_1 + 0xce5c) = *(int *)(param_1 + 0xc998);
  *(int *)(param_1 + 0xc898) = (*(int *)(param_1 + 0xc894) + *(int *)(param_1 + 0xc998)) * 4;
  *(undefined4 *)(param_1 + 0xce50) = *(undefined4 *)(param_1 + 0xc994);
  puVar2 = (uint *)((((*(int *)(param_1 + 0xcddc) + *(int *)(param_1 + 0xc994)) -
                     *(int *)(param_1 + 0xd094)) + -1) * *(int *)(param_1 + 0xc894) * 4 +
                    (*(int *)(param_1 + 0xcdd4) - *(int *)(param_1 + 0xd080)) * 4 +
                   *(int *)(param_1 + 0xc7f0));
  puVar8 = *(uint **)(param_1 + 0xc814);
  iVar5 = *(int *)(param_1 + 0xc998);
  uVar6 = 0xff000000;
  do {
    uVar3 = *puVar8;
    if (uVar3 != *(uint *)(param_1 + 0xcf70)) {
      uVar7 = uVar3 & uVar6;
      if (uVar7 != 0) {
        if (uVar7 == uVar6) goto LAB_1000597e;
        uVar6 = 0xffffffff - uVar6;
        uVar3 = (uVar3 & uVar6) << 8 | (uVar3 & uVar6) >> 0x18;
        uVar4 = uVar3 - uVar7;
        if (uVar3 < uVar7) {
          uVar4 = uVar4 & uVar6;
        }
        uVar3 = uVar4 << 8 | uVar4 >> 0x18;
        uVar4 = uVar3 - uVar7;
        if (uVar3 < uVar7) {
          uVar4 = uVar4 & uVar6;
        }
        uVar3 = uVar4 << 8 | uVar4 >> 0x18;
        uVar4 = uVar3 - uVar7;
        if (uVar3 < uVar7) {
          uVar4 = uVar4 & uVar6;
        }
        uVar6 = 0xffffffff - uVar6;
        uVar3 = uVar4 << 8 | uVar4 >> 0x18 | uVar7;
      }
      *puVar2 = uVar3;
    }
LAB_1000597e:
    puVar8 = puVar8 + 1;
    puVar2 = puVar2 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 0xc998);
      puVar2 = (uint *)((int)puVar2 - *(int *)(param_1 + 0xc898));
      piVar1 = (int *)(param_1 + 0xce50);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        return 0;
      }
    }
  } while( true );
}




======================================================================
// Function: Transform_RotatePolar @ 100059b0
======================================================================

undefined4 Transform_RotatePolar(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  
  *(int *)(param_1 + 0xce5c) = *(int *)(param_1 + 0xc998);
  *(int *)(param_1 + 0xc898) = (*(int *)(param_1 + 0xc894) + *(int *)(param_1 + 0xc998)) * 4;
  *(undefined4 *)(param_1 + 0xce50) = *(undefined4 *)(param_1 + 0xc994);
  puVar2 = (uint *)((((*(int *)(param_1 + 0xcddc) + *(int *)(param_1 + 0xc994)) -
                     *(int *)(param_1 + 0xd094)) + -1) * *(int *)(param_1 + 0xc894) * 4 +
                    (*(int *)(param_1 + 0xcdd4) - *(int *)(param_1 + 0xd080)) * 4 +
                   *(int *)(param_1 + 0xc7f0));
  puVar8 = *(uint **)(param_1 + 0xc814);
  iVar5 = *(int *)(param_1 + 0xc998);
  uVar6 = 0xff000000;
  do {
    do {
      uVar3 = *puVar8;
      if (uVar3 != *(uint *)(param_1 + 0xcf70)) {
        uVar7 = uVar3 & uVar6;
        if (uVar7 != 0) {
          if (uVar7 == uVar6) {
            uVar3 = 0xffffffff;
          }
          else {
            uVar3 = uVar3 & 0xffffffff - uVar6;
            uVar3 = uVar3 << 8 | uVar3 >> 0x18;
            uVar4 = uVar3 + uVar7;
            if (CARRY4(uVar3,uVar7)) {
              uVar4 = uVar4 | 0xff000000;
            }
            uVar3 = uVar4 << 8 | uVar4 >> 0x18;
            uVar4 = uVar3 + uVar7;
            if (CARRY4(uVar3,uVar7)) {
              uVar4 = uVar4 | 0xff000000;
            }
            uVar3 = uVar4 << 8 | uVar4 >> 0x18;
            uVar4 = uVar3 + uVar7;
            if (CARRY4(uVar3,uVar7)) {
              uVar4 = uVar4 | 0xff000000;
            }
            uVar6 = 0xffffffff - (0xffffffff - uVar6);
            uVar3 = uVar4 << 8 | uVar4 >> 0x18 | uVar7;
          }
        }
        *puVar2 = uVar3;
      }
      puVar8 = puVar8 + 1;
      puVar2 = puVar2 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = *(int *)(param_1 + 0xc998);
    puVar2 = (uint *)((int)puVar2 - *(int *)(param_1 + 0xc898));
    piVar1 = (int *)(param_1 + 0xce50);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  return 0;
}




======================================================================
// Function: Transform_RotateFast @ 10005ab0
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

longlong Transform_RotateFast(uint param_1)

{
  int *piVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  longlong lVar9;
  
  if (*(float *)(param_1 + 0x15c + *(int *)(param_1 + 0xc900) * 0xe0) < _DAT_10021260) {
    *(undefined4 *)(param_1 + 0x15c + *(int *)(param_1 + 0xc900) * 0xe0) = 0;
  }
  if (*(float *)(param_1 + 0x15c + *(int *)(param_1 + 0xc900) * 0xe0) < _DAT_100212d8) {
    *(int *)(param_1 + 0xc898) = *(int *)(param_1 + 0xc894) << 2;
    lVar9 = __ftol();
    *(int *)(param_1 + 0xcfd8) = (int)lVar9;
    *(undefined4 *)(param_1 + 0xce5c) = *(undefined4 *)(param_1 + 0xc998);
    *(undefined4 *)(param_1 + 0xce50) = *(undefined4 *)(param_1 + 0xc994);
    *(float *)(param_1 + 0xce34) =
         (float)*(int *)(param_1 + 0x31cc + *(int *)(param_1 + 0xc900) * 0x1ec) / _DAT_100212d8;
    *(float *)(param_1 + 0xce38) =
         (float)*(int *)(param_1 + 0x31d0 + *(int *)(param_1 + 0xc900) * 0x1ec) / _DAT_100212d8;
    *(float *)(param_1 + 0xcb7c) = (float)*(int *)(param_1 + 0xcfd8) / _DAT_100212d8;
    *(float *)(param_1 + 0xcb80) = _DAT_1002129c - *(float *)(param_1 + 0xcb7c);
    *(float *)(param_1 + 0xcb7c) = *(float *)(param_1 + 0xcb7c) + *(float *)(param_1 + 0xce34);
    *(float *)(param_1 + 0xcb80) = *(float *)(param_1 + 0xcb80) + *(float *)(param_1 + 0xce38);
    lVar9 = (ulonglong)
            (((*(int *)(param_1 + 0xcddc) + *(int *)(param_1 + 0xc994)) - *(int *)(param_1 + 0xd094)
             ) - 1) * (ulonglong)(uint)(*(int *)(param_1 + 0xc894) << 2);
    uVar6 = (uint)((ulonglong)lVar9 >> 0x20);
    puVar3 = (uint *)((int)lVar9 + (*(int *)(param_1 + 0xcdd4) - *(int *)(param_1 + 0xd080)) * 4 +
                     *(int *)(param_1 + 0xc7f0));
    puVar8 = *(uint **)(param_1 + 0xc814);
    do {
      do {
        *(uint **)(param_1 + 0xcc04) = puVar3;
        *(uint **)(param_1 + 0xcc08) = puVar8;
        uVar7 = *puVar8;
        if (uVar7 != *(uint *)(param_1 + 0xcf70)) {
          *(uint *)(param_1 + 0xcd9c) = uVar7 & 0xff;
          *(uint *)(param_1 + 0xceac) = uVar7 >> 8 & 0xff;
          *(uint *)(param_1 + 0xcf44) = uVar7 >> 0x10 & 0xff;
          uVar6 = *puVar3;
          *(uint *)(param_1 + 0xcce4) = uVar6 & 0xff;
          *(uint *)(param_1 + 0xcd18) = uVar6 >> 8 & 0xff;
          *(uint *)(param_1 + 0xcd20) = uVar6 >> 0x10 & 0xff;
          lVar9 = __ftol();
          *(int *)(param_1 + 0xcf44) = (int)lVar9;
          lVar9 = __ftol();
          *(int *)(param_1 + 0xcd9c) = (int)lVar9;
          lVar9 = __ftol();
          *(int *)(param_1 + 0xceac) = (int)lVar9;
          if (*(int *)(param_1 + 0xcf44) < 0) {
            *(undefined4 *)(param_1 + 0xce90) = 0;
          }
          if (*(int *)(param_1 + 0xcd9c) < 0) {
            *(undefined4 *)(param_1 + 0xce6c) = 0;
          }
          if (*(int *)(param_1 + 0xceac) < 0) {
            *(undefined4 *)(param_1 + 0xce80) = 0;
          }
          uVar7 = *(uint *)(param_1 + 0xcd9c);
          uVar5 = *(uint *)(param_1 + 0xceac);
          uVar4 = *(uint *)(param_1 + 0xcf44);
          uVar6 = 0xff;
          if (0xff < uVar4) {
            uVar4 = 0xff;
          }
          if (0xff < uVar7) {
            uVar7 = 0xff;
          }
          if (0xff < uVar5) {
            uVar5 = 0xff;
          }
          bVar2 = (byte)uVar4;
          puVar3 = *(uint **)(param_1 + 0xcc04);
          puVar8 = *(uint **)(param_1 + 0xcc08);
          *puVar3 = CONCAT22((ushort)bVar2 | (ushort)(((uint)CONCAT11(bVar2,bVar2) << 0x18) >> 0x10)
                             ,CONCAT11((char)uVar5,(char)uVar7));
        }
        puVar8 = puVar8 + 1;
        puVar3 = puVar3 + 1;
        piVar1 = (int *)(param_1 + 0xce5c);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      *(int *)(param_1 + 0xce5c) = *(int *)(param_1 + 0xc998);
      puVar3 = (uint *)((int)puVar3 + (*(int *)(param_1 + 0xc998) * -4 - *(int *)(param_1 + 0xc898))
                       );
      piVar1 = (int *)(param_1 + 0xce50);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  else {
    *(undefined4 *)(param_1 + 0x15c + *(int *)(param_1 + 0xc900) * 0xe0) = 0x437f0000;
    uVar6 = param_1;
  }
  return (ulonglong)uVar6 << 0x20;
}




======================================================================
// Function: Convolution_Apply @ 10005e80
======================================================================

undefined4 Convolution_Apply(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  *(int *)(param_1 + 0xc898) = *(int *)(param_1 + 0xc894) << 2;
  piVar2 = (int *)((((*(int *)(param_1 + 0xcddc) + *(int *)(param_1 + 0xc994)) -
                    *(int *)(param_1 + 0xd094)) + -1) * *(int *)(param_1 + 0xc894) * 4 +
                   (*(int *)(param_1 + 0xcdd4) - *(int *)(param_1 + 0xd080)) * 4 +
                  *(int *)(param_1 + 0xc7f0));
  piVar5 = *(int **)(param_1 + 0xc814);
  iVar3 = *(int *)(param_1 + 0xc998);
  iVar4 = *(int *)(param_1 + 0xc994);
  iVar1 = *(int *)(param_1 + 0xcf70);
  if (iVar1 == -1) {
    do {
      do {
        *piVar5 = *piVar2;
        piVar5 = piVar5 + 1;
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = *(int *)(param_1 + 0xc998);
      piVar2 = (int *)((int)piVar2 + (iVar3 * -4 - *(int *)(param_1 + 0xc898)));
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    do {
      do {
        if (*piVar5 != iVar1) {
          *piVar5 = *piVar2;
        }
        piVar5 = piVar5 + 1;
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = *(int *)(param_1 + 0xc998);
      piVar2 = (int *)((int)piVar2 + (iVar3 * -4 - *(int *)(param_1 + 0xc898)));
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return 0;
}




======================================================================
// Function: Motion_ComplexPhysics @ 10005f50
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

longlong Motion_ComplexPhysics(uint param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  
  if (*(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
    *(undefined4 *)(param_1 + 0xcec0) =
         *(undefined4 *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec);
    if (*(int *)(param_1 + 0x3274 + *(int *)(param_1 + 0xc900) * 0x1ec) == 1) {
      __ftol();
      lVar5 = __ftol();
      *(int *)(param_1 + 0xcec0) = (int)lVar5;
    }
    if (*(int *)(param_1 + 0x3274 + *(int *)(param_1 + 0xc900) * 0x1ec) == 2) {
      __ftol();
      lVar5 = __ftol();
      *(int *)(param_1 + 0xcec0) = (int)lVar5;
    }
    if (*(int *)(param_1 + 0xcec0) < 0) {
      *(int *)(param_1 + 0xcec0) = -*(int *)(param_1 + 0xcec0);
    }
    while (0x5a < *(int *)(param_1 + 0xcec0)) {
      *(int *)(param_1 + 0xcec0) = *(int *)(param_1 + 0xcec0) + -0x5a;
    }
  }
  if ((*(int *)(param_1 + 0x3194 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0 ||
      *(int *)(param_1 + 0x31b4 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) ||
      *(int *)(param_1 + 0x31c0 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
    *(undefined4 *)(param_1 + 0xcfd0) =
         *(undefined4 *)(param_1 + 0x3198 + *(int *)(param_1 + 0xc900) * 0x1ec);
    *(undefined4 *)(param_1 + 0xcfcc) =
         *(undefined4 *)(param_1 + 0x319c + *(int *)(param_1 + 0xc900) * 0x1ec);
    *(undefined4 *)(param_1 + 0xcfc4) =
         *(undefined4 *)(param_1 + 0x31a0 + *(int *)(param_1 + 0xc900) * 0x1ec);
    *(float *)(param_1 + 0xcea0) = (float)*(int *)(param_1 + 0xcfd0);
    *(float *)(param_1 + 0xce9c) = (float)*(int *)(param_1 + 0xcfcc);
    *(float *)(param_1 + 0xce94) = (float)*(int *)(param_1 + 0xcfc4);
    if (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) < 1) {
      *(float *)(param_1 + 0xcea4) =
           (float)-*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec);
    }
    else {
      *(float *)(param_1 + 0xcea4) =
           (float)(0xff - *(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec));
    }
    *(float *)(param_1 + 0xcb90) =
         (float)*(int *)(param_1 + 0x3194 + *(int *)(param_1 + 0xc900) * 0x1ec) / _DAT_100212dc;
    *(float *)(param_1 + 0xcb98) =
         (float)*(int *)(param_1 + 0x31c0 + *(int *)(param_1 + 0xc900) * 0x1ec) / _DAT_100212dc;
    *(float *)(param_1 + 0xcb90) =
         *(float *)(param_1 + 0xcb90) *
         *(float *)(param_1 + 0xbc28 +
                   *(int *)(param_1 + 0x31d4 + *(int *)(param_1 + 0xc900) * 0x1ec) * 4);
    *(float *)(param_1 + 0xcb98) =
         *(float *)(param_1 + 0xcb98) *
         *(float *)(param_1 + 0xbc28 +
                   *(int *)(param_1 + 0x31d4 + *(int *)(param_1 + 0xc900) * 0x1ec) * 4);
  }
  *(undefined4 *)(param_1 + 0xcbb0) =
       *(undefined4 *)(param_1 + 0x31a8 + *(int *)(param_1 + 0xc900) * 0x1ec);
  if (*(int *)(param_1 + 0x31a8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
    *(int *)(param_1 + 0xc97c) =
         *(int *)(param_1 + 0xc810) +
         *(int *)(param_1 + 0xc998) * 4 * *(int *)(param_1 + 0xc994) * 4;
    *(float *)(param_1 + 0xca74) =
         (float)*(int *)(param_1 + 0x31b4 + *(int *)(param_1 + 0xc900) * 0x1ec);
    if (*(float *)(param_1 + 0xca74) < _DAT_10021260) {
      *(float *)(param_1 + 0xca74) = -*(float *)(param_1 + 0xca74);
    }
    *(float *)(param_1 + 0xc954) = *(float *)(param_1 + 0xca74) / (float)*(int *)(param_1 + 0xcbb0);
    *(float *)(param_1 + 0xca74) = *(float *)(param_1 + 0xca74) + *(float *)(param_1 + 0xc954);
  }
  *(undefined4 *)(param_1 + 0xc7fc) = *(undefined4 *)(param_1 + 0xc814);
  *(undefined4 *)(param_1 + 0xc800) = *(undefined4 *)(param_1 + 0xc7ec);
  *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
  *(float *)(param_1 + 0xce70) =
       (float)*(int *)(param_1 + 0x3190 + *(int *)(param_1 + 0xc900) * 0x1ec);
  uVar2 = param_1;
  if (*(int *)(param_1 + 0x3190 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
    if (*(int *)(param_1 + 0x3274 + *(int *)(param_1 + 0xc900) * 0x1ec) == 1) {
      lVar5 = __ftol();
      *(float *)(param_1 + 0xce70) =
           *(float *)(param_1 + 0xce70) * *(float *)(param_1 + 0xbc28 + (int)lVar5 * 4);
    }
    if (*(int *)(param_1 + 0x3274 + *(int *)(param_1 + 0xc900) * 0x1ec) == 2) {
      lVar5 = __ftol();
      *(float *)(param_1 + 0xce70) =
           *(float *)(param_1 + 0xce70) * *(float *)(param_1 + 0xbc28 + (int)lVar5 * 4);
    }
  }
  do {
    uVar3 = **(uint **)(param_1 + 0xc7fc);
    if (uVar3 == *(uint *)(param_1 + 0xcf70)) {
      puVar4 = *(uint **)(param_1 + 0xc800);
      if (puVar4 != *(uint **)(param_1 + 0xc7fc)) goto LAB_10006f93;
    }
    else {
      *(uint *)(param_1 + 0xcd68) = uVar3 >> 0x18;
      *(uint *)(param_1 + 0xcd9c) = uVar3 & 0xff;
      *(uint *)(param_1 + 0xceac) = uVar3 >> 8 & 0xff;
      *(uint *)(param_1 + 0xcf44) = uVar3 >> 0x10 & 0xff;
      *(float *)(param_1 + 0xce90) = (float)*(int *)(param_1 + 0xcf44);
      *(float *)(param_1 + 0xce80) = (float)*(int *)(param_1 + 0xceac);
      *(float *)(param_1 + 0xce6c) = (float)*(int *)(param_1 + 0xcd9c);
      if (*(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
        if (*(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec) < 0) {
          if (*(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec) < -0x59) {
            if (-0xb4 < *(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec))
            goto LAB_10006621;
LAB_1000665c:
            *(float *)(param_1 + 0xce90) = (float)*(int *)(param_1 + 0xceac);
            *(float *)(param_1 + 0xce6c) = (float)*(int *)(param_1 + 0xcf44);
            *(float *)(param_1 + 0xce80) = (float)*(int *)(param_1 + 0xcd9c);
          }
        }
        else if (0x59 < *(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec)) {
          if (-0xb4 < *(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec))
          goto LAB_1000665c;
LAB_10006621:
          *(float *)(param_1 + 0xce90) = (float)*(int *)(param_1 + 0xcd9c);
          *(float *)(param_1 + 0xce6c) = (float)*(int *)(param_1 + 0xceac);
          *(float *)(param_1 + 0xce80) = (float)*(int *)(param_1 + 0xcf44);
        }
        *(float *)(param_1 + 0xcd08) =
             *(float *)(param_1 + 0xce90) *
             *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xcec0) * 4);
        *(float *)(param_1 + 0xcd04) =
             *(float *)(param_1 + 0xce80) *
             *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xcec0) * 4);
        *(float *)(param_1 + 0xcd00) =
             *(float *)(param_1 + 0xce6c) *
             *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xcec0) * 4);
        *(float *)(param_1 + 0xcd4c) = *(float *)(param_1 + 0xce90) - *(float *)(param_1 + 0xcd08);
        *(float *)(param_1 + 0xcd48) = *(float *)(param_1 + 0xce80) - *(float *)(param_1 + 0xcd04);
        *(float *)(param_1 + 0xcd44) = *(float *)(param_1 + 0xce6c) - *(float *)(param_1 + 0xcd00);
        if (*(int *)(param_1 + 0x318c + *(int *)(param_1 + 0xc900) * 0x1ec) < 0) {
          *(float *)(param_1 + 0xce90) = *(float *)(param_1 + 0xcd08) + *(float *)(param_1 + 0xcd44)
          ;
          *(float *)(param_1 + 0xce80) = *(float *)(param_1 + 0xcd04) + *(float *)(param_1 + 0xcd4c)
          ;
          *(float *)(param_1 + 0xce6c) = *(float *)(param_1 + 0xcd00) + *(float *)(param_1 + 0xcd48)
          ;
        }
        else {
          *(float *)(param_1 + 0xce90) = *(float *)(param_1 + 0xcd08) + *(float *)(param_1 + 0xcd48)
          ;
          *(float *)(param_1 + 0xce80) = *(float *)(param_1 + 0xcd04) + *(float *)(param_1 + 0xcd44)
          ;
          *(float *)(param_1 + 0xce6c) = *(float *)(param_1 + 0xcd00) + *(float *)(param_1 + 0xcd4c)
          ;
        }
      }
      if (*(int *)(param_1 + 0x3190 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
        *(float *)(param_1 + 0xce90) = *(float *)(param_1 + 0xce90) + *(float *)(param_1 + 0xce70);
        *(float *)(param_1 + 0xce80) = *(float *)(param_1 + 0xce80) + *(float *)(param_1 + 0xce70);
        *(float *)(param_1 + 0xce6c) = *(float *)(param_1 + 0xce6c) + *(float *)(param_1 + 0xce70);
      }
      if ((*(int *)(param_1 + 0xcfd0) != 0 || *(int *)(param_1 + 0xcfcc) != 0) ||
          *(int *)(param_1 + 0xcfc4) != 0) {
        if (*(int *)(param_1 + 0x3194 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
          if (*(int *)(param_1 + 0xcfd0) != 0) {
            *(float *)(param_1 + 0xce90) =
                 (*(float *)(param_1 + 0xcea0) - *(float *)(param_1 + 0xce90)) *
                 *(float *)(param_1 + 0xcb90) + *(float *)(param_1 + 0xce90);
          }
          if (*(int *)(param_1 + 0xcfcc) != 0) {
            *(float *)(param_1 + 0xce80) =
                 (*(float *)(param_1 + 0xce9c) - *(float *)(param_1 + 0xce80)) *
                 *(float *)(param_1 + 0xcb90) + *(float *)(param_1 + 0xce80);
          }
          if (*(int *)(param_1 + 0xcfc4) != 0) {
            *(float *)(param_1 + 0xce6c) =
                 (*(float *)(param_1 + 0xce94) - *(float *)(param_1 + 0xce6c)) *
                 *(float *)(param_1 + 0xcb90) + *(float *)(param_1 + 0xce6c);
          }
        }
        if (*(int *)(param_1 + 0x31b4 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0 &&
            *(int *)(param_1 + 0x31a8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
          if (*(int *)(param_1 + 0x31b4 + *(int *)(param_1 + 0xc900) * 0x1ec) < 1) {
            uVar2 = *(ushort *)
                     (*(int *)(param_1 + 0xc810) -
                     (*(int *)(param_1 + 0xc814) - *(int *)(param_1 + 0xc7fc))) & 0xff;
            *(undefined4 *)(param_1 + 0xc8f4) = 1;
            if (uVar2 < *(uint *)(param_1 + 0xcbb0)) {
              *(uint *)(param_1 + 0xc8f4) = *(int *)(param_1 + 0xcbb0) - uVar2;
            }
          }
          else {
            uVar2 = *(ushort *)
                     (*(int *)(param_1 + 0xc810) -
                     (*(int *)(param_1 + 0xc814) - *(int *)(param_1 + 0xc7fc))) & 0xff;
            if (*(uint *)(param_1 + 0xcbb0) < uVar2) goto LAB_10006b5c;
            *(uint *)(param_1 + 0xc8f4) = uVar2;
          }
          *(float *)(param_1 + 0xcb94) =
               (*(float *)(param_1 + 0xca74) -
               (float)*(int *)(param_1 + 0xc8f4) * *(float *)(param_1 + 0xc954)) / _DAT_100212dc;
          *(float *)(param_1 + 0xcb94) =
               *(float *)(param_1 + 0xcb94) *
               *(float *)(param_1 + 0xbc28 +
                         *(int *)(param_1 + 0x31d4 + *(int *)(param_1 + 0xc900) * 0x1ec) * 4);
          if (*(int *)(param_1 + 0xcfd0) != 0) {
            *(float *)(param_1 + 0xce90) =
                 (*(float *)(param_1 + 0xcea0) - *(float *)(param_1 + 0xce90)) *
                 *(float *)(param_1 + 0xcb94) + *(float *)(param_1 + 0xce90);
          }
          if (*(int *)(param_1 + 0xcfcc) != 0) {
            *(float *)(param_1 + 0xce80) =
                 (*(float *)(param_1 + 0xce9c) - *(float *)(param_1 + 0xce80)) *
                 *(float *)(param_1 + 0xcb94) + *(float *)(param_1 + 0xce80);
          }
          if (*(int *)(param_1 + 0xcfc4) != 0) {
            *(float *)(param_1 + 0xce6c) =
                 (*(float *)(param_1 + 0xce94) - *(float *)(param_1 + 0xce6c)) *
                 *(float *)(param_1 + 0xcb94) + *(float *)(param_1 + 0xce6c);
          }
        }
LAB_10006b5c:
        if (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0 &&
            *(int *)(param_1 + 0x31c0 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
          if (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) < 1) {
            if (*(int *)(param_1 + 0xcfd0) != 0 &&
                *(float *)(param_1 + 0xce90) < *(float *)(param_1 + 0xcea4)) {
              *(float *)(param_1 + 0xce90) =
                   (*(float *)(param_1 + 0xcea0) - *(float *)(param_1 + 0xce90)) *
                   *(float *)(param_1 + 0xcb98) + *(float *)(param_1 + 0xce90);
            }
            if (*(int *)(param_1 + 0xcfcc) != 0 &&
                *(float *)(param_1 + 0xce80) < *(float *)(param_1 + 0xcea4)) {
              *(float *)(param_1 + 0xce80) =
                   (*(float *)(param_1 + 0xce9c) - *(float *)(param_1 + 0xce80)) *
                   *(float *)(param_1 + 0xcb98) + *(float *)(param_1 + 0xce80);
            }
            if (*(int *)(param_1 + 0xcfc4) != 0 &&
                *(float *)(param_1 + 0xce6c) < *(float *)(param_1 + 0xcea4)) {
              *(float *)(param_1 + 0xce6c) =
                   (*(float *)(param_1 + 0xce94) - *(float *)(param_1 + 0xce6c)) *
                   *(float *)(param_1 + 0xcb98) + *(float *)(param_1 + 0xce6c);
            }
          }
          else {
            if (*(int *)(param_1 + 0xcfd0) != 0 &&
                *(float *)(param_1 + 0xcea4) <= *(float *)(param_1 + 0xce90)) {
              *(float *)(param_1 + 0xce90) =
                   (*(float *)(param_1 + 0xcea0) - *(float *)(param_1 + 0xce90)) *
                   *(float *)(param_1 + 0xcb98) + *(float *)(param_1 + 0xce90);
            }
            if (*(int *)(param_1 + 0xcfcc) != 0 &&
                *(float *)(param_1 + 0xcea4) <= *(float *)(param_1 + 0xce80)) {
              *(float *)(param_1 + 0xce80) =
                   (*(float *)(param_1 + 0xce9c) - *(float *)(param_1 + 0xce80)) *
                   *(float *)(param_1 + 0xcb98) + *(float *)(param_1 + 0xce80);
            }
            if (*(int *)(param_1 + 0xcfc4) != 0 &&
                *(float *)(param_1 + 0xcea4) <= *(float *)(param_1 + 0xce6c)) {
              *(float *)(param_1 + 0xce6c) =
                   (*(float *)(param_1 + 0xce94) - *(float *)(param_1 + 0xce6c)) *
                   *(float *)(param_1 + 0xcb98) + *(float *)(param_1 + 0xce6c);
            }
          }
        }
      }
      if (*(float *)(param_1 + 0xce90) < _DAT_10021260) {
        *(undefined4 *)(param_1 + 0xce90) = 0;
      }
      if (*(float *)(param_1 + 0xce80) < _DAT_10021260) {
        *(undefined4 *)(param_1 + 0xce80) = 0;
      }
      if (*(float *)(param_1 + 0xce6c) < _DAT_10021260) {
        *(undefined4 *)(param_1 + 0xce6c) = 0;
      }
      if (_DAT_100212d8 < *(float *)(param_1 + 0xce90)) {
        *(undefined4 *)(param_1 + 0xce90) = 0x437f0000;
      }
      if (_DAT_100212d8 < *(float *)(param_1 + 0xce80)) {
        *(undefined4 *)(param_1 + 0xce80) = 0x437f0000;
      }
      if (_DAT_100212d8 < *(float *)(param_1 + 0xce6c)) {
        *(undefined4 *)(param_1 + 0xce6c) = 0x437f0000;
      }
      lVar5 = __ftol();
      *(int *)(param_1 + 0xcf44) = (int)lVar5;
      lVar5 = __ftol();
      *(int *)(param_1 + 0xceac) = (int)lVar5;
      lVar5 = __ftol();
      uVar2 = (uint)((ulonglong)lVar5 >> 0x20);
      *(int *)(param_1 + 0xcd9c) = (int)lVar5;
      uVar3 = ((*(int *)(param_1 + 0xcd68) << 8 | *(uint *)(param_1 + 0xcf44)) << 8 |
              *(uint *)(param_1 + 0xceac)) << 8 | *(uint *)(param_1 + 0xcd9c);
      puVar4 = *(uint **)(param_1 + 0xc800);
LAB_10006f93:
      *puVar4 = uVar3;
    }
    *(int *)(param_1 + 0xc800) = *(int *)(param_1 + 0xc800) + 4;
    *(int *)(param_1 + 0xc7fc) = *(int *)(param_1 + 0xc7fc) + 4;
    piVar1 = (int *)(param_1 + 0xcba8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      return (ulonglong)uVar2 << 0x20;
    }
  } while( true );
}




======================================================================
// Function: PerPixelColorBlend @ 10006ff0
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 PerPixelColorBlend(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  longlong lVar11;
  
  if (*(int *)(param_1 + 0x32a8 + *(int *)(param_1 + 0xc900) * 0x1ec) == 2) {
    *(undefined4 *)(param_1 + 0x32a8 + *(int *)(param_1 + 0xc900) * 0x1ec) = 1;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x31a4 + *(int *)(param_1 + 0xc900) * 0x1ec);
    iVar3 = *(int *)(param_1 + 0x31a8 + *(int *)(param_1 + 0xc900) * 0x1ec);
    iVar4 = *(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec);
    iVar5 = *(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec);
    lVar11 = __ftol();
    *(int *)(param_1 + 0xc85c) =
         iVar3 + iVar2 * 0xff + iVar4 * 0x200 + iVar5 + (int)lVar11 +
         *(int *)(param_1 + 0x324c + *(int *)(param_1 + 0xc900) * 0x1ec) * 3 +
         *(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) + 1 +
         *(int *)(param_1 + 0x31f4 + *(int *)(param_1 + 0xc900) * 0x1ec);
    if (*(int *)(*(int *)(param_1 + 0xc814) + -4) == *(int *)(param_1 + 0xc85c)) {
      return 0;
    }
    *(int *)(*(int *)(param_1 + 0xc814) + -4) = *(int *)(param_1 + 0xc85c);
  }
  *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
  *(undefined4 *)(param_1 + 0xcbb0) =
       *(undefined4 *)(param_1 + 0x31a8 + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(undefined4 *)(param_1 + 0xcf4c) =
       *(undefined4 *)(param_1 + 0x15c + *(int *)(param_1 + 0xc900) * 0xe0);
  *(undefined4 *)(param_1 + 0xcfe4) = 0;
  *(undefined4 *)(param_1 + 0xcfe0) = 0;
  if (*(int *)(param_1 + 0x31a8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
    *(undefined4 *)(param_1 + 0xca64) =
         *(undefined4 *)(param_1 + 0x32ac + *(int *)(param_1 + 0xc900) * 0x1ec);
    *(undefined4 *)(param_1 + 0xcf94) =
         *(undefined4 *)(param_1 + 0x31a4 + *(int *)(param_1 + 0xc900) * 0x1ec);
    if (*(int *)(param_1 + 0x31a4 + *(int *)(param_1 + 0xc900) * 0x1ec) < 0) {
      *(int *)(param_1 + 0xcfd8) = -*(int *)(param_1 + 0x31a4 + *(int *)(param_1 + 0xc900) * 0x1ec);
    }
    else {
      *(undefined4 *)(param_1 + 0xcfd8) =
           *(undefined4 *)(param_1 + 0x31a4 + *(int *)(param_1 + 0xc900) * 0x1ec);
    }
    *(float *)(param_1 + 0xca78) = (float)*(int *)(param_1 + 0xcfd8);
    *(float *)(param_1 + 0xc938) = *(float *)(param_1 + 0xca78) / (float)*(int *)(param_1 + 0xcbb0);
    if (*(int *)(param_1 + 0xca64) < *(int *)(param_1 + 0xcbb0) / 3) {
      *(float *)(param_1 + 0xca78) =
           (float)(*(int *)(param_1 + 0xcbb0) / 3 - *(int *)(param_1 + 0xca64)) *
           *(float *)(param_1 + 0xc938) + *(float *)(param_1 + 0xca78);
    }
  }
  if ((((*(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec) == 0) &&
       (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) == 0)) &&
      (*(float *)(param_1 + 0x15c + *(int *)(param_1 + 0xc900) * 0xe0) == _DAT_10021260)) &&
     ((*(int *)(param_1 + 0x31a8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0 &&
      (*(int *)(param_1 + 0x31a4 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0)))) {
    if (*(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) < 2 ||
        *(int *)(param_1 + 0xd038) < *(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec)
       ) {
      lVar11 = __ftol();
      *(int *)(param_1 + 0xcfd8) = (int)lVar11;
      *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
      puVar9 = *(uint **)(param_1 + 0xc814);
      puVar10 = *(uint **)(param_1 + 0xc810);
      do {
        if ((*puVar9 != *(uint *)(param_1 + 0xcf70)) &&
           ((*puVar10 & 0xffff) <= *(uint *)(param_1 + 0xcbb0))) {
          uVar7 = *(uint *)(param_1 + 0xcfd8) -
                  (int)(((ulonglong)(*puVar10 & 0xffff) * (ulonglong)*(uint *)(param_1 + 0xcfd8)) /
                       (ulonglong)*(uint *)(param_1 + 0xcbb0));
          if (0xff < uVar7) {
            uVar7 = 0xff;
          }
          *puVar9 = *puVar9 & 0xffffff |
                    uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
        }
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
        piVar1 = (int *)(param_1 + 0xcba8);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
    }
    else {
      *(undefined4 *)(param_1 + 0xca18) =
           *(undefined4 *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec);
      *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
      if (*(int *)(param_1 + 0xcba8) <=
          *(int *)(param_1 + 0x314c + *(int *)(param_1 + 0xca18) * 0x1ec) *
          *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xca18) * 0x1ec)) {
        *(undefined4 *)(param_1 + 0xcd5c) =
             *(undefined4 *)(param_1 + 0x30ec + *(int *)(param_1 + 0xca18) * 0x1ec);
        if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xca18) * 0x1ec) == 1) {
          if (*(int *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec) == 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0xcd5c) =
               *(undefined4 *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec);
        }
        else if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xca18) * 0x1ec) == 2) {
          if (*(int *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec) == 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0xcd5c) =
               *(undefined4 *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec);
        }
        puVar9 = *(uint **)(param_1 + 0xc814);
        puVar10 = *(uint **)(param_1 + 0xcd5c);
        do {
          if (*puVar9 != *(uint *)(param_1 + 0xcf70)) {
            uVar8 = *puVar9 & 0xffffff;
            uVar7 = 0xff - (*puVar10 & 0xff);
            uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                    uVar7 * 0x1000000;
            uVar6 = uVar7 + uVar8;
            if (CARRY4(uVar7,uVar8)) {
              uVar6 = uVar6 | 0xff000000;
            }
            *puVar9 = uVar6;
          }
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
          piVar1 = (int *)(param_1 + 0xcba8);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
      lVar11 = __ftol();
      *(int *)(param_1 + 0xcfd8) = (int)lVar11;
      *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
      puVar9 = *(uint **)(param_1 + 0xc814);
      puVar10 = *(uint **)(param_1 + 0xc810);
      do {
        if ((*puVar9 != *(uint *)(param_1 + 0xcf70)) &&
           ((*puVar10 & 0xffff) <= *(uint *)(param_1 + 0xcbb0))) {
          uVar7 = *(uint *)(param_1 + 0xcfd8) -
                  (int)(((ulonglong)(*puVar10 & 0xffff) * (ulonglong)*(uint *)(param_1 + 0xcfd8)) /
                       (ulonglong)*(uint *)(param_1 + 0xcbb0));
          if (0xff < uVar7) {
            uVar7 = 0xff;
          }
          uVar6 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
          uVar7 = *puVar9 + uVar6;
          if (CARRY4(*puVar9,uVar6)) {
            uVar7 = uVar7 | 0xff000000;
          }
          *puVar9 = uVar7;
        }
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
        piVar1 = (int *)(param_1 + 0xcba8);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
    }
  }
  else if ((*(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec) == 0) &&
          ((*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) == 0 &&
           (*(float *)(param_1 + 0x15c + *(int *)(param_1 + 0xc900) * 0xe0) == _DAT_10021260)))) {
    if (1 < *(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) &&
        *(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) <=
        *(int *)(param_1 + 0xd038)) {
      *(undefined4 *)(param_1 + 0xca18) =
           *(undefined4 *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec);
      *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
      if (*(int *)(param_1 + 0xcba8) <=
          *(int *)(param_1 + 0x314c + *(int *)(param_1 + 0xca18) * 0x1ec) *
          *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xca18) * 0x1ec)) {
        *(undefined4 *)(param_1 + 0xcd5c) =
             *(undefined4 *)(param_1 + 0x30ec + *(int *)(param_1 + 0xca18) * 0x1ec);
        if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xca18) * 0x1ec) == 1) {
          if (*(int *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec) == 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0xcd5c) =
               *(undefined4 *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec);
        }
        else if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xca18) * 0x1ec) == 2) {
          if (*(int *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec) == 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0xcd5c) =
               *(undefined4 *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec);
        }
        puVar9 = *(uint **)(param_1 + 0xc814);
        puVar10 = *(uint **)(param_1 + 0xcd5c);
        do {
          if (*puVar9 != *(uint *)(param_1 + 0xcf70)) {
            uVar8 = *puVar9 & 0xffffff;
            uVar7 = 0xff - (*puVar10 & 0xff);
            uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                    uVar7 * 0x1000000;
            uVar6 = uVar7 + uVar8;
            if (CARRY4(uVar7,uVar8)) {
              uVar6 = uVar6 | 0xff000000;
            }
            *puVar9 = uVar6;
          }
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
          piVar1 = (int *)(param_1 + 0xcba8);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
    }
  }
  else {
    if ((*(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) &&
       (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0)) {
      *(undefined4 *)(param_1 + 0xcff8) =
           *(undefined4 *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec);
      if (*(int *)(param_1 + 0xcff8) < 0) {
        *(int *)(param_1 + 0xcff8) = -*(int *)(param_1 + 0xcff8);
      }
      else {
        *(int *)(param_1 + 0xcff8) = 0xff - *(int *)(param_1 + 0xcff8);
      }
      *(undefined4 *)(param_1 + 0xcf98) =
           *(undefined4 *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec);
      *(float *)(param_1 + 0xca80) = (float)*(int *)(param_1 + 0xcf98);
      *(float *)(param_1 + 0xc93c) = *(float *)(param_1 + 0xca80) / _DAT_100212d8;
    }
    puVar9 = *(uint **)(param_1 + 0xc814);
    puVar10 = *(uint **)(param_1 + 0xc810);
    *(uint **)(param_1 + 0xcc08) = puVar9;
    *(uint **)(param_1 + 0xcc04) = puVar10;
    do {
      if (*puVar9 != *(uint *)(param_1 + 0xcf70)) {
        if (*(int *)(param_1 + 0xcbb0) != 0) {
          uVar7 = *puVar10 & 0xffff;
          if (0x7fffffff < *(uint *)(param_1 + 0xcf94)) {
            uVar7 = (*(int *)(param_1 + 0xca64) - uVar7) + 1;
          }
          uVar6 = 0;
          if (uVar7 <= *(uint *)(param_1 + 0xcbb0)) {
            uVar6 = uVar7;
          }
          *(uint *)(param_1 + 0xc8f4) = uVar6;
          if (*(int *)(param_1 + 0xc8f4) != 0) {
            if (*(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) == 0) {
              *(float *)(param_1 + 0xcfe4) =
                   *(float *)(param_1 + 0xca78) -
                   (float)*(int *)(param_1 + 0xc8f4) * *(float *)(param_1 + 0xc938);
            }
            if (*(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) == 1) {
              if (*(int *)(param_1 + 0xcbb0) == *(int *)(param_1 + 0xc8f4)) {
                *(float *)(param_1 + 0xcfe4) = *(float *)(param_1 + 0xca78) / _DAT_100212e0;
              }
              else {
                *(undefined4 *)(param_1 + 0xcfe4) = *(undefined4 *)(param_1 + 0xca78);
              }
            }
            if (1 < *(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec)) {
              *(float *)(param_1 + 0xcfe4) =
                   *(float *)(param_1 + 0xca78) -
                   (float)*(int *)(param_1 + 0xc8f4) * *(float *)(param_1 + 0xc938);
            }
          }
        }
        if ((*(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) &&
           (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0)) {
          uVar7 = **(uint **)(param_1 + 0xcc08);
          uVar8 = uVar7 >> 8 & 0xff;
          uVar6 = (uVar7 & 0xff0000) >> 0x10;
          if (uVar6 < uVar8) {
            uVar6 = uVar8;
          }
          if (uVar6 < (uVar7 & 0xff)) {
            uVar6 = uVar7 & 0xff;
          }
          *(uint *)(param_1 + 0xca7c) = uVar6;
          if (*(int *)(param_1 + 0x31f4 + *(int *)(param_1 + 0xc900) * 0x1ec) == 0) {
            if (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) < 0) {
              if (*(int *)(param_1 + 0xca7c) < *(int *)(param_1 + 0xcff8)) {
                *(float *)(param_1 + 0xcfe0) =
                     *(float *)(param_1 + 0xca80) -
                     (float)*(int *)(param_1 + 0xca7c) * *(float *)(param_1 + 0xc93c);
              }
            }
            else if (*(int *)(param_1 + 0xcff8) < *(int *)(param_1 + 0xca7c)) {
              *(float *)(param_1 + 0xcfe0) =
                   *(float *)(param_1 + 0xca80) -
                   (float)(0xff - *(int *)(param_1 + 0xca7c)) * *(float *)(param_1 + 0xc93c);
            }
          }
          if (*(int *)(param_1 + 0x31f4 + *(int *)(param_1 + 0xc900) * 0x1ec) == 1) {
            if (*(int *)(param_1 + 0xcff8) == *(int *)(param_1 + 0xca7c)) {
              *(float *)(param_1 + 0xcfe0) =
                   (float)(*(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec) / 2);
            }
            else if (*(int *)(param_1 + 0x31b8 + *(int *)(param_1 + 0xc900) * 0x1ec) < 0) {
              if (*(int *)(param_1 + 0xca7c) < *(int *)(param_1 + 0xcff8)) {
                *(float *)(param_1 + 0xcfe0) =
                     (float)*(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec);
              }
            }
            else if (*(int *)(param_1 + 0xcff8) < *(int *)(param_1 + 0xca7c)) {
              *(float *)(param_1 + 0xcfe0) =
                   (float)*(int *)(param_1 + 0x31bc + *(int *)(param_1 + 0xc900) * 0x1ec);
            }
          }
        }
        lVar11 = __ftol();
        *(int *)(param_1 + 0xcfd8) = (int)lVar11;
        *(undefined4 *)(param_1 + 0xcfe4) = 0;
        *(undefined4 *)(param_1 + 0xcfe0) = 0;
        if (0xff < *(int *)(param_1 + 0xcfd8)) {
          *(undefined4 *)(param_1 + 0xcfd8) = 0xff;
        }
        puVar9 = *(uint **)(param_1 + 0xcc08);
        puVar10 = *(uint **)(param_1 + 0xcc04);
        uVar7 = *puVar9;
        uVar7 = (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18 |
                *(uint *)(param_1 + 0xcfd8);
        *puVar9 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                  *(uint *)(param_1 + 0xcfd8) << 0x18;
      }
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      piVar1 = (int *)(param_1 + 0xcba8);
      *piVar1 = *piVar1 + -1;
      *(uint **)(param_1 + 0xcc08) = puVar9;
      *(uint **)(param_1 + 0xcc04) = puVar10;
    } while (*piVar1 != 0);
    if (1 < *(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) &&
        *(int *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec) <=
        *(int *)(param_1 + 0xd038)) {
      *(undefined4 *)(param_1 + 0xca18) =
           *(undefined4 *)(param_1 + 0x31f0 + *(int *)(param_1 + 0xc900) * 0x1ec);
      *(int *)(param_1 + 0xcba8) = *(int *)(param_1 + 0xce5c) * *(int *)(param_1 + 0xce50);
      if (*(int *)(param_1 + 0xcba8) <=
          *(int *)(param_1 + 0x314c + *(int *)(param_1 + 0xca18) * 0x1ec) *
          *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xca18) * 0x1ec)) {
        *(undefined4 *)(param_1 + 0xcd5c) =
             *(undefined4 *)(param_1 + 0x30ec + *(int *)(param_1 + 0xca18) * 0x1ec);
        if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xca18) * 0x1ec) == 1) {
          if (*(int *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec) == 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0xcd5c) =
               *(undefined4 *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec);
        }
        else if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xca18) * 0x1ec) == 2) {
          if (*(int *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec) == 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0xcd5c) =
               *(undefined4 *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec);
        }
        puVar9 = *(uint **)(param_1 + 0xc814);
        puVar10 = *(uint **)(param_1 + 0xcd5c);
        do {
          uVar7 = *puVar9;
          if (uVar7 != *(uint *)(param_1 + 0xcf70)) {
            uVar6 = 0xff - (*puVar10 & 0xff);
            uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
                    uVar6 * 0x1000000;
            uVar8 = uVar6 + uVar7;
            if (CARRY4(uVar6,uVar7)) {
              uVar8 = uVar8 | 0xff000000;
            }
            *puVar9 = uVar8;
          }
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
          piVar1 = (int *)(param_1 + 0xcba8);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
    }
  }
  return 0;
}




======================================================================
// Function: Transform_PresetCoords @ 100081e0
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Transform_PresetCoords(int *param_1)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  int *piVar6;
  float10 extraout_ST0;
  longlong lVar7;
  
  iVar1 = param_1[param_1[0x3240] * 0x7b + 0xc54];
  iVar5 = param_1[param_1[0x3240] * 0x7b + 0xc53];
  param_1[0x3410] = iVar1 * iVar5;
  param_1[0x3203] = param_1[0x31fb] + iVar1 * iVar5 * 4;
  iVar1 = param_1[0x33dc];
  piVar6 = (int *)param_1[0x31fb];
  iVar5 = param_1[0x3410];
  do {
    *piVar6 = iVar1;
    piVar6 = piVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  param_1[0x33ba] = param_1[param_1[0x3240] * 0x7b + 0xc76];
  param_1[0x33bb] = param_1[param_1[0x3240] * 0x7b + 0xc77];
  if (param_1[param_1[0x3240] * 0x7b + 0xca8] == 1) {
    __ftol();
    lVar7 = __ftol();
    param_1[0x33ba] = (int)lVar7;
    __ftol();
    lVar7 = __ftol();
    param_1[0x33bb] = (int)lVar7;
  }
  if (param_1[param_1[0x3240] * 0x7b + 0xca8] == 2) {
    __ftol();
    lVar7 = __ftol();
    param_1[0x33ba] = (int)lVar7;
    __ftol();
    lVar7 = __ftol();
    param_1[0x33bb] = (int)lVar7;
  }
  param_1[0x3233] = param_1[param_1[0x3240] * 0x7b + 0xc53] / 2 + param_1[0x33ba];
  param_1[0x3235] = param_1[param_1[0x3240] * 0x7b + 0xc54] / 2 + param_1[0x33bb];
  param_1[0x33d0] = param_1[param_1[0x3240] * 0x7b + 0xc53];
  param_1[0x320f] = param_1[0x3205];
  iVar1 = param_1[0x3240];
  if ((float)param_1[iVar1 * 0x38 + 0x3e] != _DAT_10021260 ||
      (float)param_1[iVar1 * 0x38 + 0x3d] != _DAT_10021260) {
    param_1[0x33de] = param_1[iVar1 * 0x38 + 0x3d];
    param_1[0x33df] = param_1[param_1[0x3240] * 0x38 + 0x3e];
    param_1[0x33dd] = (int)((float)param_1[param_1[0x3240] * 0x38 + 0x43] * _DAT_10021310);
    if (param_1[param_1[0x3240] * 0x7b + 0xc88] == 1) {
      lVar7 = __ftol();
      param_1[0x33de] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33de]);
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xc88] == 2) {
      lVar7 = __ftol();
      param_1[0x33de] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33de]);
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xca3] == 1) {
      lVar7 = __ftol();
      param_1[0x33df] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33df]);
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xca3] == 2) {
      lVar7 = __ftol();
      param_1[0x33df] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33df]);
    }
  }
  iVar1 = param_1[0x3240];
  if ((float)param_1[iVar1 * 0x38 + 0x3f] != _DAT_10021260 ||
      (float)param_1[iVar1 * 0x38 + 0x40] != _DAT_10021260) {
    param_1[0x33ea] = param_1[iVar1 * 0x38 + 0x3f];
    param_1[0x33ef] = param_1[param_1[0x3240] * 0x38 + 0x40];
    param_1[0x33eb] = (int)((float)param_1[param_1[0x3240] * 0x38 + 0x43] * _DAT_10021310);
    if (param_1[param_1[0x3240] * 0x7b + 0xc89] == 1) {
      lVar7 = __ftol();
      param_1[0x33ea] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33ea]);
      lVar7 = __ftol();
      param_1[0x33ef] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33ef]);
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xc89] == 2) {
      lVar7 = __ftol();
      param_1[0x33ea] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33ea]);
      lVar7 = __ftol();
      param_1[0x33ef] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33ef]);
    }
  }
  iVar1 = param_1[0x3240];
  if ((float)param_1[iVar1 * 0x38 + 0x42] != _DAT_10021260 ||
      (float)param_1[iVar1 * 0x38 + 0x41] != _DAT_10021260) {
    param_1[0x3400] = param_1[iVar1 * 0x38 + 0x41];
    param_1[0x3401] = param_1[param_1[0x3240] * 0x38 + 0x42];
    param_1[0x33ff] = (int)((float)param_1[param_1[0x3240] * 0x38 + 0x43] * _DAT_10021310);
    param_1[0x33a2] = 0;
    param_1[0x33a3] = 0;
    if (param_1[param_1[0x3240] * 0x7b + 0xc8b] == 1) {
      param_1[0x33a2] = param_1[param_1[0x3240] * 0x38 + 0x46];
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xc8b] == 2) {
      param_1[0x33a2] = param_1[param_1[0x3240] * 0x38 + 0x48];
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xc8c] == 1) {
      param_1[0x33a3] = param_1[param_1[0x3240] * 0x38 + 0x46];
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xc8c] == 2) {
      param_1[0x33a3] = param_1[param_1[0x3240] * 0x38 + 0x48];
    }
  }
  fVar3 = (float)param_1[param_1[0x3240] * 0x38 + 0x44] *
          (float)param_1[param_1[0x3240] * 0x38 + 0x44];
  fVar3 = fVar3 + fVar3;
  param_1[0x331f] = (int)fVar3;
  iVar1 = param_1[0x3240];
  param_1[0x331e] = (int)(_DAT_1002130c / fVar3);
  param_1[0x33e7] = (int)((float)param_1[iVar1 * 0x7b + 0xc8f] * _DAT_10021308);
  if (param_1[iVar1 * 0x7b + 0xc81] == 1) {
    lVar7 = __ftol();
    param_1[0x33e7] = (int)(float)(extraout_ST0 * (float10)(float)param_1[(int)lVar7 + 0x2f0a]);
  }
  if (param_1[iVar1 * 0x7b + 0xc81] == 2) {
    lVar7 = __ftol();
    param_1[0x33e7] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33e7]);
  }
  fVar3 = (float)param_1[iVar1 * 0x38 + 0x4a] * (float)param_1[iVar1 * 0x38 + 0x4a];
  param_1[0x3321] = (int)(fVar3 + fVar3);
  param_1[0x33ec] = (int)((float)param_1[iVar1 * 0x38 + 0x4e] * _DAT_10021304);
  param_1[0x33ed] = (int)((float)param_1[iVar1 * 0x38 + 0x4f] * _DAT_10021304);
  param_1[0x33ee] = (int)((float)param_1[iVar1 * 0x38 + 0x50] * _DAT_10021304);
  param_1[0x32e1] = param_1[iVar1 * 0x38 + 0x4b];
  param_1[0x32e2] = param_1[iVar1 * 0x38 + 0x4c];
  param_1[0x32e3] = param_1[iVar1 * 0x38 + 0x4d];
  param_1[0x33b8] = 0x3f800000;
  param_1[0x3347] = 0x3f800000;
  if (param_1[iVar1 * 0x7b + 0xc91] == 1) {
    lVar7 = __ftol();
    param_1[0x33b8] = param_1[(int)lVar7 + 0x2f0a];
  }
  if (param_1[iVar1 * 0x7b + 0xc91] == 2) {
    lVar7 = __ftol();
    param_1[0x33b8] = param_1[(int)lVar7 + 0x2f0a];
  }
  if (param_1[iVar1 * 0x7b + 0xc92] == 1) {
    lVar7 = __ftol();
    param_1[0x3347] = param_1[(int)lVar7 + 0x2f0a];
  }
  if (param_1[iVar1 * 0x7b + 0xc92] == 2) {
    lVar7 = __ftol();
    param_1[0x3347] = param_1[(int)lVar7 + 0x2f0a];
  }
  if ((float)param_1[0x33b8] < _DAT_10021260) {
    param_1[0x33b8] = (int)-(float)param_1[0x33b8];
  }
  if ((float)param_1[0x3347] < _DAT_10021260) {
    param_1[0x3347] = (int)-(float)param_1[0x3347];
  }
  param_1[0x32e1] = (int)((float)param_1[0x33b8] * (float)param_1[0x32e1]);
  param_1[0x32e2] = (int)((float)param_1[0x33b8] * (float)param_1[0x32e2]);
  param_1[0x32e3] = (int)((float)param_1[0x33b8] * (float)param_1[0x32e3]);
  param_1[0x33ec] = (int)((float)param_1[0x33ec] * (float)param_1[0x3347]);
  param_1[0x33ed] = (int)((float)param_1[0x3347] * (float)param_1[0x33ed]);
  param_1[0x33ee] = (int)((float)param_1[0x33ee] * (float)param_1[0x3347]);
  param_1[0x33d4] = (int)((float)param_1[iVar1 * 0x38 + 0x43] * _DAT_10021300);
  bVar2 = (float)param_1[0x33d4] != _DAT_10021260;
  param_1[0x33d5] = param_1[iVar1 * 0x7b + 0xc79];
  param_1[0x33d6] = param_1[iVar1 * 0x7b + 0xc7a];
  param_1[0x33d7] = param_1[iVar1 * 0x7b + 0xc7b];
  if (bVar2) {
    if (param_1[iVar1 * 0x7b + 0xc94] == 1) {
      lVar7 = __ftol();
      param_1[0x33d4] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33d4]);
    }
    if (param_1[iVar1 * 0x7b + 0xc94] == 2) {
      lVar7 = __ftol();
      param_1[0x33d4] = (int)((float)param_1[(int)lVar7 + 0x2f0a] * (float)param_1[0x33d4]);
    }
  }
  if (param_1[0x33d5] != 0) {
    if (param_1[iVar1 * 0x7b + 0xc95] == 1) {
      lVar7 = __ftol();
      param_1[0x33d5] = (int)lVar7;
    }
    if (param_1[iVar1 * 0x7b + 0xc95] == 2) {
      lVar7 = __ftol();
      param_1[0x33d5] = (int)lVar7;
    }
    param_1[0x3349] = param_1[0x33d5];
  }
  if (param_1[0x33d6] != 0) {
    if (param_1[iVar1 * 0x7b + 0xc95] == 1) {
      lVar7 = __ftol();
      param_1[0x33d6] = (int)lVar7;
    }
    if (param_1[iVar1 * 0x7b + 0xc95] == 2) {
      lVar7 = __ftol();
      param_1[0x33d6] = (int)lVar7;
    }
    param_1[0x334a] = param_1[0x33d6];
  }
  if (param_1[0x33d7] != 0) {
    if (param_1[iVar1 * 0x7b + 0xc95] == 1) {
      lVar7 = __ftol();
      param_1[0x33d7] = (int)lVar7;
    }
    if (param_1[iVar1 * 0x7b + 0xc95] == 2) {
      lVar7 = __ftol();
      param_1[0x33d7] = (int)lVar7;
    }
    param_1[0x334b] = param_1[0x33d7];
  }
  if ((float)param_1[iVar1 * 0x38 + 0x3d] == _DAT_10021260 &&
      (((((((((float)param_1[iVar1 * 0x38 + 0x4d] == _DAT_10021260 &&
             (float)param_1[iVar1 * 0x38 + 0x4c] == _DAT_10021260) &&
             (float)param_1[iVar1 * 0x38 + 0x4b] == _DAT_10021260 ||
            (float)param_1[iVar1 * 0x38 + 0x4a] == _DAT_10021260) &&
           ((float)param_1[iVar1 * 0x7b + 0xc8f] == _DAT_10021260 ||
           (float)param_1[iVar1 * 0x38 + 0x44] == _DAT_10021260)) &&
          (float)param_1[iVar1 * 0x38 + 0x42] == _DAT_10021260) &&
         (float)param_1[iVar1 * 0x38 + 0x41] == _DAT_10021260) &&
        (float)param_1[iVar1 * 0x38 + 0x3f] == _DAT_10021260) &&
       (float)param_1[iVar1 * 0x38 + 0x40] == _DAT_10021260) &&
      (float)param_1[iVar1 * 0x38 + 0x3e] == _DAT_10021260)) {
    param_1[0x3286] = 0;
    while (param_1[0x3286] < param_1[0x3410]) {
      if (*(int *)param_1[0x320f] != param_1[0x33dc]) {
        param_1[0x336b] = *(int *)param_1[0x320f];
        param_1[0x32f2] = (uint)param_1[0x3286] / (uint)param_1[0x33d0];
        param_1[0x32f1] = (uint)param_1[0x3286] % (uint)param_1[0x33d0];
        param_1[0x32f3] = (int)(float)(param_1[0x32f1] - param_1[0x3233]);
        param_1[0x32f4] = (int)(float)(param_1[0x32f2] - param_1[0x3235]);
        (**(code **)(*param_1 + 0x274))(param_1);
        lVar7 = __ftol();
        iVar1 = (int)lVar7 + param_1[0x3233];
        param_1[0x3362] = iVar1;
        lVar7 = __ftol();
        iVar5 = (int)lVar7 + param_1[0x3235];
        param_1[0x3364] = iVar5;
        if (((iVar5 < param_1[param_1[0x3240] * 0x7b + 0xc54] &&
             iVar1 < param_1[param_1[0x3240] * 0x7b + 0xc53]) && -1 < iVar5) && -1 < iVar1) {
          piVar6 = (int *)(param_1[0x31fb] +
                          (iVar5 * param_1[param_1[0x3240] * 0x7b + 0xc53] + iVar1) * 4);
          param_1[0x3202] = (int)piVar6;
          if (piVar6 < (int *)param_1[0x3203]) {
            *piVar6 = param_1[0x336b];
          }
        }
      }
LAB_10009134:
      param_1[0x320f] = param_1[0x320f] + 4;
      param_1[0x3286] = param_1[0x3286] + 1;
    }
  }
  else {
    if (((param_1[iVar1 * 0x7b + 0xc79] == 0) && (param_1[iVar1 * 0x7b + 0xc7a] == 0)) &&
       (param_1[iVar1 * 0x7b + 0xc7b] == 0)) {
      bVar4 = 0;
    }
    else {
      bVar4 = 1;
    }
    if ((bool)(((((float)param_1[iVar1 * 0x38 + 0x4d] == _DAT_10021260 &&
                 (float)param_1[iVar1 * 0x38 + 0x4c] == _DAT_10021260) &&
                 (float)param_1[iVar1 * 0x38 + 0x4b] == _DAT_10021260 ||
                (float)param_1[iVar1 * 0x38 + 0x4a] == _DAT_10021260) &&
               ((float)param_1[iVar1 * 0x7b + 0xc8f] == _DAT_10021260 ||
               (float)param_1[iVar1 * 0x38 + 0x44] == _DAT_10021260)) & bVar4 &
              (float)param_1[iVar1 * 0x38 + 0x42] != _DAT_10021260) ||
        ((((float)param_1[iVar1 * 0x38 + 0x3f] == _DAT_10021260 &&
          (float)param_1[iVar1 * 0x38 + 0x40] == _DAT_10021260) &&
         (float)param_1[iVar1 * 0x38 + 0x3e] == _DAT_10021260) &&
        (float)param_1[iVar1 * 0x38 + 0x3d] == _DAT_10021260) &&
        (float)param_1[iVar1 * 0x38 + 0x41] != _DAT_10021260) {
      param_1[0x3286] = 0;
      if (0 < param_1[0x3410]) {
        do {
          if (*(int *)param_1[0x320f] != param_1[0x33dc]) {
            param_1[0x336b] = *(int *)param_1[0x320f];
            param_1[0x32f2] = (uint)param_1[0x3286] / (uint)param_1[0x33d0];
            param_1[0x32f1] = (uint)param_1[0x3286] % (uint)param_1[0x33d0];
            param_1[0x32f3] = (int)(float)(param_1[0x32f1] - param_1[0x3233]);
            param_1[0x32f4] = (int)(float)(param_1[0x32f2] - param_1[0x3235]);
            (**(code **)(*param_1 + 0x270))(param_1);
            (**(code **)(*param_1 + 0x274))(param_1);
            lVar7 = __ftol();
            iVar1 = (int)lVar7 + param_1[0x3233];
            param_1[0x3362] = iVar1;
            lVar7 = __ftol();
            iVar5 = (int)lVar7 + param_1[0x3235];
            param_1[0x3364] = iVar5;
            if (((iVar5 < param_1[param_1[0x3240] * 0x7b + 0xc54] &&
                 iVar1 < param_1[param_1[0x3240] * 0x7b + 0xc53]) && -1 < iVar5) && -1 < iVar1) {
              piVar6 = (int *)(param_1[0x31fb] +
                              (iVar5 * param_1[param_1[0x3240] * 0x7b + 0xc53] + iVar1) * 4);
              param_1[0x3202] = (int)piVar6;
              if ((int *)param_1[0x3203] <= piVar6) goto LAB_10009134;
              *piVar6 = param_1[0x336b];
            }
          }
          iVar1 = param_1[0x3286];
          param_1[0x320f] = param_1[0x320f] + 4;
          param_1[0x3286] = iVar1 + 1;
        } while (iVar1 + 1 < param_1[0x3410]);
        return 0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x3272) = 1;
      param_1[0x3286] = 0;
      if (0 < param_1[0x3410]) {
        do {
          if (*(int *)param_1[0x320f] != param_1[0x33dc]) {
            param_1[0x336b] = *(int *)param_1[0x320f];
            param_1[0x32f2] = (uint)param_1[0x3286] / (uint)param_1[0x33d0];
            param_1[0x32f1] = (uint)param_1[0x3286] % (uint)param_1[0x33d0];
            param_1[0x32f3] = (int)(float)(param_1[0x32f1] - param_1[0x3233]);
            param_1[0x32f4] = (int)(float)(param_1[0x32f2] - param_1[0x3235]);
            if ((float)param_1[param_1[0x3240] * 0x38 + 0x3e] != _DAT_10021260 ||
                (float)param_1[param_1[0x3240] * 0x38 + 0x3d] != _DAT_10021260) {
              (**(code **)(*param_1 + 0x264))(param_1);
            }
            if ((float)param_1[param_1[0x3240] * 0x38 + 0x3f] != _DAT_10021260 ||
                (float)param_1[param_1[0x3240] * 0x38 + 0x40] != _DAT_10021260) {
              (**(code **)(*param_1 + 0x268))(param_1);
            }
            if ((float)param_1[param_1[0x3240] * 0x38 + 0x42] != _DAT_10021260 ||
                (float)param_1[param_1[0x3240] * 0x38 + 0x41] != _DAT_10021260) {
              (**(code **)(*param_1 + 0x270))(param_1);
            }
            if ((((float)param_1[param_1[0x3240] * 0x38 + 0x44] == _DAT_10021260 ||
                  (float)param_1[param_1[0x3240] * 0x7b + 0xc8f] == _DAT_10021260) ||
                ((**(code **)(*param_1 + 0x26c))(param_1), (char)param_1[0x3277] != '\x01')) &&
               ((iVar1 = param_1[0x3240],
                (float)param_1[iVar1 * 0x38 + 0x4a] == _DAT_10021260 ||
                ((float)param_1[iVar1 * 0x38 + 0x4d] == _DAT_10021260 &&
                (float)param_1[iVar1 * 0x38 + 0x4c] == _DAT_10021260) &&
                (float)param_1[iVar1 * 0x38 + 0x4b] == _DAT_10021260 ||
                ((**(code **)(*param_1 + 0x278))(param_1), (char)param_1[0x3277] != '\x01')))) {
              iVar1 = param_1[0x3240];
              if (((param_1[iVar1 * 0x7b + 0xc79] != 0) || (param_1[iVar1 * 0x7b + 0xc7a] != 0)) ||
                 (param_1[iVar1 * 0x7b + 0xc7b] != 0)) {
                (**(code **)(*param_1 + 0x274))(param_1);
              }
              lVar7 = __ftol();
              iVar1 = (int)lVar7 + param_1[0x3233];
              param_1[0x3362] = iVar1;
              lVar7 = __ftol();
              iVar5 = (int)lVar7 + param_1[0x3235];
              param_1[0x3364] = iVar5;
              if (((iVar5 < param_1[param_1[0x3240] * 0x7b + 0xc54] &&
                   iVar1 < param_1[param_1[0x3240] * 0x7b + 0xc53]) && -1 < iVar5) && -1 < iVar1) {
                piVar6 = (int *)(param_1[0x31fb] +
                                (iVar5 * param_1[param_1[0x3240] * 0x7b + 0xc53] + iVar1) * 4);
                param_1[0x3202] = (int)piVar6;
                if (piVar6 < (int *)param_1[0x3203]) {
                  if ((char)param_1[0x3272] == '\0') {
                    if (*piVar6 == param_1[0x33dc]) {
                      *piVar6 = param_1[0x336b];
                    }
                  }
                  else {
                    *piVar6 = param_1[0x336b];
                  }
                }
              }
            }
          }
          iVar1 = param_1[0x3286];
          param_1[0x320f] = param_1[0x320f] + 4;
          param_1[0x3286] = iVar1 + 1;
        } while (iVar1 + 1 < param_1[0x3410]);
      }
    }
  }
  return 0;
}




======================================================================
// Function: Transform_PolarCoords @ 10009670
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Transform_PolarCoords(int *param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  
  param_1[0x3410] =
       param_1[param_1[0x3240] * 0x7b + 0xc54] * param_1[param_1[0x3240] * 0x7b + 0xc53];
  param_1[0x3202] = param_1[0x31fb];
  param_1[0x320f] = param_1[0x3205];
  param_1[0x33f5] = param_1[param_1[0x3240] * 0x7b + 0xc86];
  param_1[0x32e7] = (int)((float)param_1[param_1[0x3240] * 0x7b + 0xc85] / _DAT_100212dc);
  lVar6 = __ftol();
  param_1[0x33e9] = (int)lVar6;
  param_1[0x33f4] = param_1[param_1[0x3240] * 0x7b + 0xc66];
  param_1[0x33f3] = param_1[param_1[0x3240] * 0x7b + 0xc67];
  param_1[0x33f1] = param_1[param_1[0x3240] * 0x7b + 0xc68];
  param_1[0x33a8] = (int)(float)param_1[0x33f4];
  param_1[0x33a7] = (int)(float)param_1[0x33f3];
  param_1[0x33a5] = (int)(float)param_1[0x33f1];
  param_1[0x331f] =
       (int)((float)param_1[param_1[0x3240] * 0x38 + 0x30] *
             (float)param_1[param_1[0x3240] * 0x38 + 0x30] +
            (float)param_1[param_1[0x3240] * 0x38 + 0x30] *
            (float)param_1[param_1[0x3240] * 0x38 + 0x30]);
  param_1[0x3233] =
       param_1[param_1[0x3240] * 0x7b + 0xc53] / 2 + param_1[param_1[0x3240] * 0x7b + 0xc7f];
  param_1[0x3235] =
       param_1[param_1[0x3240] * 0x7b + 0xc54] / 2 + param_1[param_1[0x3240] * 0x7b + 0xc80];
  param_1[0x33d0] = param_1[param_1[0x3240] * 0x7b + 0xc53];
  param_1[0x3286] = 0;
  param_1[0x33a6] = 0;
  param_1[0x339a] = (int)((float)param_1[param_1[0x3240] * 0x38 + 0x3c] * _DAT_10021310);
  if ((float)param_1[param_1[0x3240] * 0x38 + 0x3b] != _DAT_10021260) {
    (**(code **)(*param_1 + 0x68))(param_1);
  }
  do {
    param_1[0x336b] = *(int *)param_1[0x320f];
    if (param_1[0x336b] == param_1[0x33dc]) {
LAB_1000a3eb:
      *(int *)param_1[0x3202] = param_1[0x336b];
    }
    else {
      param_1[0x32f2] = (uint)param_1[0x3286] / (uint)param_1[0x33d0];
      param_1[0x32f1] = (uint)param_1[0x3286] % (uint)param_1[0x33d0];
      if ((float)param_1[param_1[0x3240] * 0x38 + 0x3a] <= _DAT_10021260) {
        param_1[0x33f2] =
             (int)((float)-(param_1[param_1[0x3240] * 0x7b + 0xc54] - param_1[0x32f2]) *
                  (float)param_1[param_1[0x3240] * 0x38 + 0x3a]);
      }
      else {
        param_1[0x33f2] =
             (int)((float)param_1[0x32f2] * (float)param_1[param_1[0x3240] * 0x38 + 0x3a]);
      }
      param_1[0x32f1] = param_1[0x32f1] - param_1[0x3233];
      param_1[0x32f2] = param_1[0x32f2] - param_1[0x3235];
      param_1[0x32f3] =
           (int)((float)param_1[0x32f1] * (float)param_1[param_1[0x3240] * 0x38 + 0x33] +
                (float)param_1[0x32f1]);
      param_1[0x32f4] =
           (int)((float)param_1[0x32f2] * (float)param_1[param_1[0x3240] * 0x38 + 0x32] +
                (float)param_1[0x32f2]);
      if (((float)param_1[param_1[0x3240] * 0x38 + 0x39] != _DAT_10021260) &&
         ((float)param_1[0x32f3] != _DAT_10021260 && (float)param_1[0x32f4] != _DAT_10021260)) {
        if ((float)param_1[0x32f3] < _DAT_10021260) {
          param_1[0x32f3] = (int)-(float)param_1[0x32f3];
        }
        if ((float)param_1[0x32f4] < _DAT_10021260) {
          param_1[0x32f4] = (int)-(float)param_1[0x32f4];
        }
        if ((float)param_1[param_1[0x3240] * 0x38 + 0x39] <= _DAT_10021260) {
          if ((float)param_1[0x32f3] <= (float)param_1[0x32f4]) {
            param_1[0x32f8] = (int)((float)param_1[0x32f3] / (float)param_1[0x32f4]);
          }
          else {
            param_1[0x32f8] = (int)((float)param_1[0x32f4] / (float)param_1[0x32f3]);
          }
          if (-(float)param_1[param_1[0x3240] * 0x38 + 0x39] <= (float)param_1[0x32f8])
          goto LAB_10009d6e;
        }
        else {
          if ((float)param_1[0x32f3] <= (float)param_1[0x32f4]) {
            param_1[0x32f8] = (int)((float)param_1[0x32f3] / (float)param_1[0x32f4]);
          }
          else {
            param_1[0x32f8] = (int)((float)param_1[0x32f4] / (float)param_1[0x32f3]);
          }
          lVar6 = __ftol();
          param_1[0x32f8] = (int)((float)param_1[0x32f8] - (float)(int)lVar6);
          if (((float)param_1[0x32f8] <= (float)param_1[param_1[0x3240] * 0x38 + 0x39]) ||
             (_DAT_1002129c - (float)param_1[0x32f8] <=
              (float)param_1[param_1[0x3240] * 0x38 + 0x39])) goto LAB_10009d6e;
        }
LAB_1000a3b2:
        if (param_1[param_1[0x3240] * 0x7b + 0xc86] != 0) {
          uVar4 = param_1[0x33f5];
          uVar5 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
          puVar1 = (uint *)(param_1 + 0x336b);
          uVar4 = *puVar1;
          *puVar1 = *puVar1 + uVar5;
          if (CARRY4(uVar4,uVar5)) {
            param_1[0x336b] = param_1[0x336b] | 0xff000000;
          }
        }
        goto LAB_1000a3eb;
      }
LAB_10009d6e:
      param_1[0x32f3] = (int)((float)param_1[0x32f3] * (float)param_1[0x32f3]);
      param_1[0x32f4] = (int)((float)param_1[0x32f4] * (float)param_1[0x32f4]);
      lVar6 = __ftol();
      param_1[0x33e8] = (int)lVar6;
      if ((float)param_1[param_1[0x3240] * 0x38 + 0x30] <= _DAT_10021260) {
        lVar6 = __ftol();
        if ((int)lVar6 <= param_1[0x33e8]) goto LAB_10009e28;
        goto LAB_1000a3b2;
      }
      lVar6 = __ftol();
      if ((int)lVar6 < param_1[0x33e8]) goto LAB_1000a3b2;
LAB_10009e28:
      if (((float)param_1[param_1[0x3240] * 0x38 + 0x3a] != _DAT_10021260) &&
         ((float)param_1[0x33f2] < (float)param_1[0x32f3])) goto LAB_1000a3b2;
      if ((float)param_1[param_1[0x3240] * 0x38 + 0x3b] != _DAT_10021260) {
        param_1[0x325d] =
             *(int *)(param_1[0x322f] + param_1[0x3408] * param_1[0x32f2] * 4 + param_1[0x32f1] * 4)
        ;
      }
      param_1[0x32e4] =
           (int)(((float)param_1[0x33e8] * (float)param_1[param_1[0x3240] * 0x38 + 0x34]) /
                 (float)param_1[0x33e9] + (float)param_1[0x32e7]);
      param_1[0x3343] = 0;
      param_1[0x33a6] = (int)((float)param_1[0x33a6] + (float)param_1[0x339a]);
      if (_DAT_10021260 <= (float)param_1[param_1[0x3240] * 0x38 + 0x3c]) {
        param_1[0x3343] = (int)((float)param_1[0x32f3] * (float)param_1[0x33a6]);
      }
      else {
        param_1[0x3343] = (int)((float)param_1[0x33e8] * (float)param_1[0x33a6]);
      }
      iVar2 = param_1[0x3240];
      lVar6 = __ftol();
      param_1[0x340d] = param_1[iVar2 * 0x7b + 0xc82] + (int)lVar6;
      if (param_1[0x340d] < 0) {
        param_1[0x340d] = -param_1[0x340d];
      }
      if (0x167 < param_1[0x340d]) {
        param_1[0x340d] = (uint)param_1[0x340d] % 0x168;
      }
      param_1[0x32e4] =
           (int)(((float)param_1[param_1[0x3240] * 0x38 + 0x35] +
                 (float)param_1[param_1[0x340d] + 0x2f0a]) * (float)param_1[0x32e4]);
      if ((float)param_1[0x32e4] <= _DAT_10021260) goto LAB_1000a3b2;
      uVar4 = param_1[0x336b];
      param_1[0x335a] = uVar4 >> 0x18;
      param_1[0x3367] = uVar4 & 0xff;
      param_1[0x33ab] = uVar4 >> 8 & 0xff;
      param_1[0x33d1] = uVar4 >> 0x10 & 0xff;
      param_1[0x33a4] = (int)(float)param_1[0x33d1];
      param_1[0x33a0] = (int)(float)param_1[0x33ab];
      param_1[0x339b] = (int)(float)param_1[0x3367];
      if (param_1[0x33f4] != 0) {
        param_1[0x33a4] =
             (int)(((float)param_1[0x33a8] - (float)param_1[0x33a4]) * (float)param_1[0x32e4] +
                  (float)param_1[0x33a4]);
      }
      if (param_1[0x33f3] != 0) {
        param_1[0x33a0] =
             (int)(((float)param_1[0x33a7] - (float)param_1[0x33a0]) * (float)param_1[0x32e4] +
                  (float)param_1[0x33a0]);
      }
      if (param_1[0x33f1] != 0) {
        param_1[0x339b] =
             (int)(((float)param_1[0x33a5] - (float)param_1[0x339b]) * (float)param_1[0x32e4] +
                  (float)param_1[0x339b]);
      }
      iVar2 = param_1[0x335a];
      iVar3 = param_1[0x33f5];
      lVar6 = __ftol();
      param_1[0x335a] = (iVar2 + iVar3) - (int)lVar6;
      if ((float)param_1[0x33a4] < _DAT_10021260) {
        param_1[0x33a4] = 0;
      }
      if ((float)param_1[0x33a0] < _DAT_10021260) {
        param_1[0x33a0] = 0;
      }
      if ((float)param_1[0x339b] < _DAT_10021260) {
        param_1[0x339b] = 0;
      }
      if (_DAT_100212d8 < (float)param_1[0x33a4]) {
        param_1[0x33a4] = 0x437f0000;
      }
      if (_DAT_100212d8 < (float)param_1[0x33a0]) {
        param_1[0x33a0] = 0x437f0000;
      }
      if (_DAT_100212d8 < (float)param_1[0x339b]) {
        param_1[0x339b] = 0x437f0000;
      }
      if (0xff < param_1[0x335a]) {
        param_1[0x335a] = 0xff;
      }
      lVar6 = __ftol();
      param_1[0x33d1] = (int)lVar6;
      lVar6 = __ftol();
      param_1[0x33ab] = (int)lVar6;
      lVar6 = __ftol();
      param_1[0x3367] = (int)lVar6;
      param_1[0x336b] =
           ((param_1[0x335a] << 8 | param_1[0x33d1]) << 8 | param_1[0x33ab]) << 8 | param_1[0x3367];
      *(int *)param_1[0x3202] = param_1[0x336b];
    }
    param_1[0x320f] = param_1[0x320f] + 4;
    param_1[0x3202] = param_1[0x3202] + 4;
    param_1[0x3286] = param_1[0x3286] + 1;
    if (param_1[0x3410] <= param_1[0x3286]) {
      return 0;
    }
  } while( true );
}




======================================================================
// Function: Blend_AlphaComposite @ 1000a490
======================================================================

undefined4 Blend_AlphaComposite(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xd01c) < *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec)
      || *(int *)(param_1 + 0xd020) <
         *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c)) {
    *(undefined4 *)(param_1 + 0xc8fc) = 0;
    *(undefined4 *)(param_1 + 0xc87c) = 1;
    *(undefined4 *)(param_1 + 0xc8f8) = 1;
    *(undefined4 *)(param_1 + 0xcdc8) = 1;
    if (*(LPVOID *)(param_1 + 0xcab8) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)(param_1 + 0xcab8));
    }
    iVar3 = *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec);
    *(int *)(param_1 + 0xd01c) = iVar3;
    iVar1 = *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c);
    *(int *)(param_1 + 0xd020) = iVar1;
    if (iVar3 < iVar1) {
      *(int *)(param_1 + 0xd01c) = iVar1;
    }
    else {
      *(int *)(param_1 + 0xd020) = iVar3;
    }
    pvVar2 = _malloc((*(int *)(param_1 + 0xd020) + 1) * *(int *)(param_1 + 0xd01c) * 4);
    *(void **)(param_1 + 0xcab8) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0xc9d0) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0xc900) * 0xe0 + 0xec + param_1) = 0;
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0xd020);
    *(undefined4 *)(param_1 + 0xca18) = 1;
    pvVar2 = (void *)((int)pvVar2 + ((iVar3 * *(int *)(param_1 + 0xd01c)) / 2 + iVar3 / 2) * 4);
    *(void **)(param_1 + 0xc8bc) = pvVar2;
    *(int *)(param_1 + 0xc8e0) = (int)pvVar2 + -4;
    *(int *)(param_1 + 0xd048) = *(int *)(param_1 + 0xd01c) * iVar3;
    do {
      switch(*(undefined4 *)(param_1 + 0xc8fc)) {
      case 0:
        *(int *)(param_1 + 0xc8e0) = *(int *)(param_1 + 0xc8e0) + 4;
        break;
      case 1:
        iVar3 = -*(int *)(param_1 + 0xd020);
        goto LAB_1000a61c;
      case 2:
        *(int *)(param_1 + 0xc8e0) = *(int *)(param_1 + 0xc8e0) + -4;
        break;
      case 3:
        iVar3 = *(int *)(param_1 + 0xd020);
LAB_1000a61c:
        *(int *)(param_1 + 0xc8e0) = *(int *)(param_1 + 0xc8e0) + iVar3 * 4;
        break;
      default:
        goto switchD_1000a5f5_default;
      }
      **(undefined4 **)(param_1 + 0xc8e0) = *(undefined4 *)(param_1 + 0xca18);
switchD_1000a5f5_default:
      *(int *)(param_1 + 0xcdc8) = *(int *)(param_1 + 0xcdc8) + -1;
      if (*(int *)(param_1 + 0xcdc8) < 1) {
        iVar3 = *(int *)(param_1 + 0xc8fc) + 1;
        *(int *)(param_1 + 0xc8fc) = iVar3;
        if (3 < iVar3) {
          *(undefined4 *)(param_1 + 0xc8fc) = 0;
        }
        if (*(int *)(param_1 + 0xc8f8) == 0) {
          iVar3 = *(int *)(param_1 + 0xc87c) + 1;
          *(int *)(param_1 + 0xc87c) = iVar3;
          *(int *)(param_1 + 0xc8f8) = iVar3;
          *(int *)(param_1 + 0xcdc8) = iVar3;
        }
        else {
          *(int *)(param_1 + 0xcdc8) = *(int *)(param_1 + 0xc8f8);
          *(undefined4 *)(param_1 + 0xc8f8) = 0;
        }
      }
      iVar3 = *(int *)(param_1 + 0xca18) + 1;
      *(int *)(param_1 + 0xca18) = iVar3;
    } while (iVar3 < *(int *)(param_1 + 0xd048));
  }
  return 0;
}




======================================================================
// Function: Blend_LayerMerge @ 1000ac00
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Blend_LayerMerge(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  longlong lVar5;
  
  iVar1 = *(int *)(param_1 + 0xc900);
  *(undefined4 *)(param_1 + 0xcf34) = *(undefined4 *)(param_1 + 0xcbcc);
  *(undefined4 *)(param_1 + 0xcf38) = *(undefined4 *)(param_1 + 0xcbd0);
  iVar4 = param_1 + iVar1 * 0x1ec;
  iVar2 = *(int *)(param_1 + 0x3234 + iVar1 * 0x1ec);
  if (iVar2 < 0xd) {
    *(int *)(param_1 + 0xccec) = iVar2;
    *(float *)(param_1 + 0xcd74) =
         *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcffc)
         + (float)*(int *)(iVar4 + 0x3238);
    fVar3 = *(float *)(param_1 + 0xcffc) * *(float *)(param_1 + 0xcbcc) *
            *(float *)(param_1 + 0xcbcc);
  }
  else {
    fVar3 = *(float *)(param_1 + 0xcffc) * *(float *)(param_1 + 0xcbd0);
    *(int *)(param_1 + 0xccec) = iVar2 + -0xd;
    *(float *)(param_1 + 0xcd74) =
         fVar3 * *(float *)(param_1 + 0xcbcc) + (float)*(int *)(iVar4 + 0x3238);
    fVar3 = fVar3 * *(float *)(param_1 + 0xcbd0);
  }
  iVar2 = *(int *)(param_1 + 0xccec);
  *(float *)(param_1 + 0xcd78) = fVar3 + (float)*(int *)(iVar4 + 0x3238);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0xcf34) = *(undefined4 *)(param_1 + 0xcbcc);
    *(undefined4 *)(param_1 + 0xcf38) = *(undefined4 *)(param_1 + 0xcbd0);
  }
  if (iVar2 == 1) {
    fVar3 = *(float *)(param_1 + 0xcbcc) * _DAT_10021280;
    *(undefined4 *)(param_1 + 0xcf38) = *(undefined4 *)(param_1 + 0xcbd0);
    *(float *)(param_1 + 0xcf34) = fVar3;
  }
  if (iVar2 == 2) {
    fVar3 = *(float *)(param_1 + 0xcbd0) * _DAT_10021280;
    *(undefined4 *)(param_1 + 0xcf34) = *(undefined4 *)(param_1 + 0xcbcc);
    *(float *)(param_1 + 0xcf38) = fVar3;
  }
  if (iVar2 == 3) {
    *(float *)(param_1 + 0xcf34) = *(float *)(param_1 + 0xcbcc) * _DAT_10021280;
    *(float *)(param_1 + 0xcf38) = *(float *)(param_1 + 0xcbd0) * _DAT_10021280;
  }
  if (iVar2 == 4) {
    *(undefined4 *)(param_1 + 0xcf38) = *(undefined4 *)(param_1 + 0xcbd0);
    *(float *)(param_1 + 0xcf34) = *(float *)(param_1 + 0xcbcc) * *(float *)(param_1 + 0xcbcc);
  }
  if (iVar2 == 5) {
    *(undefined4 *)(param_1 + 0xcf34) = *(undefined4 *)(param_1 + 0xcbcc);
    *(float *)(param_1 + 0xcf38) = *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbd0);
  }
  if (iVar2 == 6) {
    *(float *)(param_1 + 0xcf34) = *(float *)(param_1 + 0xcbcc) * *(float *)(param_1 + 0xcbcc);
    *(float *)(param_1 + 0xcf38) = *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbd0);
  }
  if (iVar2 == 7) {
    *(undefined4 *)(param_1 + 0xcf38) = *(undefined4 *)(param_1 + 0xcbd0);
    *(float *)(param_1 + 0xcf34) = *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbcc);
  }
  if (iVar2 == 8) {
    *(undefined4 *)(param_1 + 0xcf34) = *(undefined4 *)(param_1 + 0xcbcc);
    *(float *)(param_1 + 0xcf38) = *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbcc);
  }
  if (iVar2 == 9) {
    fVar3 = *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbcc);
    *(float *)(param_1 + 0xcf34) = fVar3;
    *(float *)(param_1 + 0xcf38) = fVar3;
  }
  if (iVar2 == 10) {
    *(undefined4 *)(param_1 + 0xcf34) = *(undefined4 *)(param_1 + 0xcbcc);
    *(float *)(param_1 + 0xcf38) =
         (*(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbd0)) /
         *(float *)(param_1 + 0xcbcc);
  }
  if (iVar2 == 0xb) {
    *(undefined4 *)(param_1 + 0xcf38) = *(undefined4 *)(param_1 + 0xcbd0);
    *(float *)(param_1 + 0xcf34) =
         (*(float *)(param_1 + 0xcbcc) * *(float *)(param_1 + 0xcbcc)) /
         *(float *)(param_1 + 0xcbd0);
  }
  if (iVar2 == 0xc) {
    *(float *)(param_1 + 0xcf34) =
         (*(float *)(param_1 + 0xcbcc) * *(float *)(param_1 + 0xcbcc)) /
         *(float *)(param_1 + 0xcbd0);
    *(float *)(param_1 + 0xcf38) =
         (*(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbd0)) /
         *(float *)(param_1 + 0xcbcc);
  }
  if (*(float *)(iVar1 * 0xe0 + 0x104 + param_1) != _DAT_10021260) {
    if (*(float *)(param_1 + 0xcf38) < _DAT_10021260) {
      *(float *)(param_1 + 0xcf38) = -*(float *)(param_1 + 0xcf38);
    }
    lVar5 = __ftol();
    iVar4 = (int)lVar5;
    *(int *)(param_1 + 0xcad0) = iVar4;
    if (iVar4 < 0) {
      *(int *)(param_1 + 0xcad0) = -iVar4;
    }
    if (0x167 < *(int *)(param_1 + 0xcad0)) {
      *(uint *)(param_1 + 0xcad0) = *(uint *)(param_1 + 0xcad0) % 0x168;
    }
    *(float *)(param_1 + 0xcbcc) =
         *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xcad0) * 4) *
         *(float *)(param_1 + 0xcd74) + *(float *)(param_1 + 0xcbcc);
  }
  if (*(float *)(*(int *)(param_1 + 0xc900) * 0xe0 + 0x108 + param_1) != _DAT_10021260) {
    if (*(float *)(param_1 + 0xcf34) < _DAT_10021260) {
      *(float *)(param_1 + 0xcf34) = -*(float *)(param_1 + 0xcf34);
    }
    lVar5 = __ftol();
    iVar4 = (int)lVar5;
    *(int *)(param_1 + 0xcad4) = iVar4;
    if (iVar4 < 0) {
      *(int *)(param_1 + 0xcad4) = -iVar4;
    }
    if (0x167 < *(int *)(param_1 + 0xcad4)) {
      *(uint *)(param_1 + 0xcad4) = *(uint *)(param_1 + 0xcad4) % 0x168;
    }
    *(float *)(param_1 + 0xcbd0) =
         *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xcad4) * 4) *
         *(float *)(param_1 + 0xcd78) + *(float *)(param_1 + 0xcbd0);
  }
  return 0;
}




======================================================================
// Function: Blend_Additive @ 1000b020
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong Blend_Additive(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  
  iVar2 = *(int *)(param_1 + 0xc900);
  *(undefined1 *)(param_1 + 0xc9dc) = 0;
  *(float *)(param_1 + 0xcf34) = *(float *)(param_1 + 0xcbcc) * *(float *)(param_1 + 0xcbcc);
  *(float *)(param_1 + 0xcf38) = *(float *)(param_1 + 0xcbd0) * *(float *)(param_1 + 0xcbd0);
  iVar5 = param_1 + iVar2 * 0x1ec;
  *(undefined4 *)(param_1 + 0xccec) = *(undefined4 *)(param_1 + 0x31e0 + iVar2 * 0x1ec);
  lVar6 = __ftol();
  iVar4 = (int)lVar6;
  *(int *)(param_1 + 0xcfa0) = iVar4;
  if (*(float *)(iVar2 * 0xe0 + 0x110 + param_1) <= _DAT_10021260) {
    uVar7 = __ftol();
    if (iVar4 < (int)uVar7) goto LAB_1000b37a;
  }
  else {
    uVar7 = __ftol();
    if ((int)uVar7 < iVar4) {
      return uVar7 & 0xffffffff00000000;
    }
  }
  iVar2 = *(int *)(param_1 + 0xccec);
  if (iVar2 == 0) {
    lVar6 = __ftol();
    iVar5 = (int)lVar6 + *(int *)(iVar5 + 0x3208);
    *(int *)(param_1 + 0xd034) = iVar5;
    if (iVar5 < 0) {
      *(int *)(param_1 + 0xd034) = -iVar5;
    }
    if (0x167 < *(int *)(param_1 + 0xd034)) {
      *(uint *)(param_1 + 0xd034) = *(uint *)(param_1 + 0xd034) % 0x168;
    }
    fVar1 = *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xd034) * 4) *
            *(float *)(param_1 + 0xcf9c);
LAB_1000b177:
    *(float *)(param_1 + 0xcd6c) = fVar1;
    *(float *)(param_1 + 0xcbcc) = (fVar1 + _DAT_1002129c) * *(float *)(param_1 + 0xcbcc);
    *(float *)(param_1 + 0xcbd0) =
         (*(float *)(param_1 + 0xcd6c) + _DAT_1002129c) * *(float *)(param_1 + 0xcbd0);
  }
  else {
    if (iVar2 == 1) {
      lVar6 = __ftol();
      iVar5 = (int)lVar6 + *(int *)(iVar5 + 0x3208);
      *(int *)(param_1 + 0xd034) = iVar5;
      if (iVar5 < 0) {
        *(int *)(param_1 + 0xd034) = -iVar5;
      }
      if (0x167 < *(int *)(param_1 + 0xd034)) {
        *(uint *)(param_1 + 0xd034) = *(uint *)(param_1 + 0xd034) % 0x168;
      }
      fVar1 = *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xd034) * 4);
      fVar1 = *(float *)(param_1 + 0xbc28 + *(int *)(param_1 + 0xd034) * 4) *
              *(float *)(param_1 + 0xcf9c) * fVar1 * fVar1;
      goto LAB_1000b177;
    }
    if (iVar2 == 2) {
      fVar1 = *(float *)(param_1 + 0xcf9c) + _DAT_1002129c;
      *(float *)(param_1 + 0xcbcc) = fVar1 * *(float *)(param_1 + 0xcbcc);
      *(float *)(param_1 + 0xcbd0) = fVar1 * *(float *)(param_1 + 0xcbd0);
    }
    else if (iVar2 == 3) {
      fVar1 = *(float *)(param_1 + 0xcf9c) * _DAT_100212dc;
      if (*(float *)(param_1 + 0xcbcc) < _DAT_10021260) {
        fVar3 = *(float *)(param_1 + 0xcbcc) - fVar1;
      }
      else {
        fVar3 = fVar1 + *(float *)(param_1 + 0xcbcc);
      }
      *(float *)(param_1 + 0xcbcc) = fVar3;
      if (*(float *)(param_1 + 0xcbd0) < _DAT_10021260) {
        *(float *)(param_1 + 0xcbd0) = *(float *)(param_1 + 0xcbd0) - fVar1;
      }
      else {
        *(float *)(param_1 + 0xcbd0) = fVar1 + *(float *)(param_1 + 0xcbd0);
      }
    }
  }
  lVar6 = __ftol();
  iVar5 = (int)lVar6;
  *(int *)(param_1 + 0xcfa0) = iVar5;
  if (*(float *)(*(int *)(param_1 + 0xc900) * 0xe0 + 0x110 + param_1) <= _DAT_10021260) {
    uVar7 = __ftol();
    if (iVar5 < (int)uVar7) {
      *(undefined1 *)(param_1 + 0xc9dc) = 1;
    }
  }
  else {
    uVar7 = __ftol();
    if ((int)uVar7 < iVar5) {
      *(undefined1 *)(param_1 + 0xc9dc) = 1;
      return uVar7 & 0xffffffff00000000;
    }
  }
LAB_1000b37a:
  return uVar7 & 0xffffffff00000000;
}




======================================================================
// Function: Effect_Blur @ 1000b690
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Effect_Blur(int param_1)

{
  int iVar1;
  longlong lVar2;
  
  if (*(float *)(param_1 + 0xcf50) != _DAT_10021260) {
    lVar2 = __ftol();
    *(int *)(param_1 + 0xcfa0) = (int)lVar2;
    if (*(int *)(param_1 + 0x31e4 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
      lVar2 = __ftol();
      iVar1 = *(int *)(param_1 + 0xcd24) - (int)lVar2;
      *(int *)(param_1 + 0xcf54) = iVar1;
      while (iVar1 < 0) {
        iVar1 = *(int *)(param_1 + 0xcf54) + 0x168;
        *(int *)(param_1 + 0xcf54) = iVar1;
      }
      if (0x167 < *(int *)(param_1 + 0xcf54)) {
        *(uint *)(param_1 + 0xcf54) = *(uint *)(param_1 + 0xcf54) % 0x168;
      }
    }
    if (*(int *)(param_1 + 0x31e8 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
      lVar2 = __ftol();
      iVar1 = *(int *)(param_1 + 0xcd28) - (int)lVar2;
      *(int *)(param_1 + 0xcf58) = iVar1;
      while (iVar1 < 0) {
        iVar1 = *(int *)(param_1 + 0xcf58) + 0x168;
        *(int *)(param_1 + 0xcf58) = iVar1;
      }
      if (0x167 < *(int *)(param_1 + 0xcf58)) {
        *(uint *)(param_1 + 0xcf58) = *(uint *)(param_1 + 0xcf58) % 0x168;
      }
    }
    if (*(int *)(param_1 + 0x31ec + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
      lVar2 = __ftol();
      iVar1 = *(int *)(param_1 + 0xcd2c) - (int)lVar2;
      *(int *)(param_1 + 0xcf5c) = iVar1;
      while (iVar1 < 0) {
        iVar1 = *(int *)(param_1 + 0xcf5c) + 0x168;
        *(int *)(param_1 + 0xcf5c) = iVar1;
      }
      if (0x167 < *(int *)(param_1 + 0xcf5c)) {
        *(uint *)(param_1 + 0xcf5c) = *(uint *)(param_1 + 0xcf5c) % 0x168;
      }
    }
  }
  *(undefined4 *)(param_1 + 0xcf34) = *(undefined4 *)(param_1 + 0xcbcc);
  iVar1 = *(int *)(param_1 + 0xcf5c);
  if (iVar1 != 0) {
    *(float *)(param_1 + 0xcbcc) =
         *(float *)(param_1 + (0x3072 - iVar1) * 4) * *(float *)(param_1 + 0xcbcc) -
         *(float *)(param_1 + (0x31da - iVar1) * 4) * *(float *)(param_1 + 0xcbd0);
    *(float *)(param_1 + 0xcbd0) =
         *(float *)(param_1 + (0x3072 - iVar1) * 4) * *(float *)(param_1 + 0xcbd0) +
         *(float *)(param_1 + (0x31da - iVar1) * 4) * *(float *)(param_1 + 0xcf34);
  }
  if (*(int *)(param_1 + 0x31e4 + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
    *(float *)(param_1 + 0xcbd0) =
         *(float *)(param_1 + (0x3072 - *(int *)(param_1 + 0xcf54)) * 4) *
         *(float *)(param_1 + 0xcbd0);
  }
  if (*(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x31e8) != 0) {
    *(float *)(param_1 + 0xcbcc) =
         *(float *)(param_1 + (0x3072 - *(int *)(param_1 + 0xcf58)) * 4) *
         *(float *)(param_1 + 0xcbcc);
  }
  return 0;
}




======================================================================
// Function: Effect_Shadow @ 1000b900
======================================================================

undefined4 Effect_Shadow(int *param_1)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = param_1[0x3240];
  param_1[0x3369] = param_1[iVar1 * 0x7b + 0xc97];
  if (param_1[iVar1 * 0x7b + 0xc96] == 1) {
    __ftol();
    lVar2 = __ftol();
    param_1[0x3369] = (int)lVar2;
  }
  if (param_1[iVar1 * 0x7b + 0xc96] == 2) {
    __ftol();
    lVar2 = __ftol();
    param_1[0x3369] = (int)lVar2;
  }
  if (param_1[0x3369] < 0) {
    param_1[0x3369] = -param_1[0x3369];
  }
  param_1[0x33d0] = param_1[iVar1 * 0x7b + 0xc53];
  param_1[0x3410] = param_1[iVar1 * 0x7b + 0xc54] * param_1[iVar1 * 0x7b + 0xc53];
  param_1[0x3202] = param_1[0x31fb];
  param_1[0x320f] = param_1[0x3205];
  param_1[0x3286] = 0;
  do {
    iVar1 = *(int *)param_1[0x320f];
    param_1[0x336b] = iVar1;
    if (iVar1 != param_1[0x33dc]) {
      (**(code **)(*param_1 + 0x21c))(param_1);
      param_1[0x33d2] = param_1[0x33d1];
      param_1[0x33ac] = param_1[0x33ab];
      param_1[0x3368] = param_1[0x3367];
      param_1[0x32fb] = 1;
      param_1[0x32ef] = (uint)param_1[0x3286] / (uint)param_1[0x33d0];
      param_1[0x32ed] = (uint)param_1[0x3286] % (uint)param_1[0x33d0];
      param_1[0x32ee] = param_1[param_1[0x3240] * 0x7b + 0xc53] - param_1[0x32ed];
      param_1[0x32eb] = param_1[param_1[0x3240] * 0x7b + 0xc54] - param_1[0x32ef];
      if (param_1[0x3369] < param_1[0x32ed]) {
        param_1[0x32ed] = param_1[0x3369];
      }
      if (param_1[0x3369] < param_1[0x32ee]) {
        param_1[0x32ee] = param_1[0x3369];
      }
      if (param_1[0x3369] < param_1[0x32ef]) {
        param_1[0x32ef] = param_1[0x3369];
      }
      if (param_1[0x3369] < param_1[0x32eb]) {
        param_1[0x32eb] = param_1[0x3369];
      }
      iVar1 = param_1[0x32ee];
      while (iVar1 != 0) {
        iVar1 = *(int *)(param_1[0x320f] + param_1[0x32ee] * 4);
        param_1[0x336b] = iVar1;
        if (iVar1 != param_1[0x33dc]) {
          param_1[0x32fb] = param_1[0x32fb] + 1;
          (**(code **)(*param_1 + 0x21c))(param_1);
          param_1[0x33d2] = param_1[0x33d2] + param_1[0x33d1];
          param_1[0x33ac] = param_1[0x33ac] + param_1[0x33ab];
          param_1[0x3368] = param_1[0x3368] + param_1[0x3367];
        }
        iVar1 = param_1[0x32ee] + -1;
        param_1[0x32ee] = iVar1;
      }
      iVar1 = param_1[0x32ed];
      while (iVar1 != 0) {
        iVar1 = *(int *)(param_1[0x320f] + param_1[0x32ed] * -4);
        param_1[0x336b] = iVar1;
        if (iVar1 != param_1[0x33dc]) {
          param_1[0x32fb] = param_1[0x32fb] + 1;
          (**(code **)(*param_1 + 0x21c))(param_1);
          param_1[0x33d2] = param_1[0x33d2] + param_1[0x33d1];
          param_1[0x33ac] = param_1[0x33ac] + param_1[0x33ab];
          param_1[0x3368] = param_1[0x3368] + param_1[0x3367];
        }
        iVar1 = param_1[0x32ed] + -1;
        param_1[0x32ed] = iVar1;
      }
      iVar1 = param_1[0x32ef];
      while (iVar1 != 0) {
        iVar1 = *(int *)(param_1[0x320f] + param_1[0x33d0] * param_1[0x32ef] * -4);
        param_1[0x336b] = iVar1;
        if (iVar1 != param_1[0x33dc]) {
          param_1[0x32fb] = param_1[0x32fb] + 1;
          (**(code **)(*param_1 + 0x21c))(param_1);
          param_1[0x33d2] = param_1[0x33d2] + param_1[0x33d1];
          param_1[0x33ac] = param_1[0x33ac] + param_1[0x33ab];
          param_1[0x3368] = param_1[0x3368] + param_1[0x3367];
        }
        iVar1 = param_1[0x32ef] + -1;
        param_1[0x32ef] = iVar1;
      }
      iVar1 = param_1[0x32eb];
      while (iVar1 != 0) {
        iVar1 = *(int *)(param_1[0x320f] + param_1[0x33d0] * param_1[0x32eb] * 4);
        param_1[0x336b] = iVar1;
        if (iVar1 != param_1[0x33dc]) {
          param_1[0x32fb] = param_1[0x32fb] + 1;
          (**(code **)(*param_1 + 0x21c))(param_1);
          param_1[0x33d2] = param_1[0x33d2] + param_1[0x33d1];
          param_1[0x33ac] = param_1[0x33ac] + param_1[0x33ab];
          param_1[0x3368] = param_1[0x3368] + param_1[0x3367];
        }
        iVar1 = param_1[0x32eb] + -1;
        param_1[0x32eb] = iVar1;
      }
      iVar1 = param_1[0x32fb];
      param_1[0x33d1] = param_1[0x33d2] / iVar1;
      param_1[0x33ab] = param_1[0x33ac] / iVar1;
      param_1[0x3367] = param_1[0x3368] / iVar1;
      param_1[0x336b] =
           ((param_1[0x335a] << 8 | param_1[0x33d1]) << 8 | param_1[0x33ab]) << 8 | param_1[0x3367];
    }
    *(int *)param_1[0x3202] = param_1[0x336b];
    iVar1 = param_1[0x3286];
    param_1[0x3202] = param_1[0x3202] + 4;
    param_1[0x320f] = param_1[0x320f] + 4;
    param_1[0x3286] = iVar1 + 1;
  } while (iVar1 + 1 < param_1[0x3410]);
  return 0;
}




======================================================================
// Function: Effect_MotionBlur @ 1000be00
======================================================================

undefined4 Effect_MotionBlur(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xcdac);
  *(uint *)(param_1 + 0xcd68) = uVar1 >> 0x18;
  *(uint *)(param_1 + 0xcd9c) = uVar1 & 0xff;
  *(uint *)(param_1 + 0xceac) = uVar1 >> 8 & 0xff;
  *(uint *)(param_1 + 0xcf44) = uVar1 >> 0x10 & 0xff;
  return 0;
}




======================================================================
// Function: Effect_Fade2 @ 1000be50
======================================================================

undefined4 Effect_Fade2(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  param_1[0x33b3] = param_1[param_1[0x3240] * 0x7b + 0xc6c];
  if (param_1[0x33b3] < 0) {
    param_1[0x33b3] = -param_1[0x33b3];
  }
  if (0xff < param_1[param_1[0x3240] * 0x7b + 0xc93]) {
    param_1[param_1[0x3240] * 0x7b + 0xc93] = 0xff;
  }
  param_1[0x33d0] = param_1[param_1[0x3240] * 0x7b + 0xc53];
  param_1[0x3410] =
       param_1[param_1[0x3240] * 0x7b + 0xc54] * param_1[param_1[0x3240] * 0x7b + 0xc53];
  param_1[0x3202] = param_1[0x31fb];
  param_1[0x320f] = param_1[0x3205];
  param_1[0x3215] = param_1[0x3205];
  param_1[0x3214] = param_1[0x3205] + param_1[0x3410] * 4;
  param_1[0x3286] = 0;
  do {
    param_1[0x336b] = *(int *)param_1[0x320f];
    if (((param_1[0x336b] == param_1[0x33dc]) &&
        ((**(code **)(*param_1 + 0x1ec))(param_1), param_1[0x336b] != param_1[0x33dc])) &&
       (param_1[param_1[0x3240] * 0x7b + 0xc93] != 0)) {
      param_1[0x33f6] = param_1[param_1[0x3240] * 0x7b + 0xc93];
      param_1[0x33f6] = param_1[0x33f6] - param_1[0x321f] * param_1[param_1[0x3240] * 0x7b + 0xc98];
      if (0xff < param_1[0x33f6]) {
        param_1[0x33f6] = 0xff;
      }
      uVar2 = param_1[0x33f6];
      uVar3 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      puVar1 = (uint *)(param_1 + 0x336b);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar3;
      if (CARRY4(uVar2,uVar3)) {
        param_1[0x336b] = param_1[0x336b] | 0xff000000;
      }
    }
    *(int *)param_1[0x3202] = param_1[0x336b];
    param_1[0x3202] = param_1[0x3202] + 4;
    param_1[0x320f] = param_1[0x320f] + 4;
    param_1[0x3286] = param_1[0x3286] + 1;
  } while (param_1[0x3286] < param_1[0x3410]);
  return 0;
}




======================================================================
// Function: Render_PresetImage @ 1000c380
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong Render_PresetImage(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  
  iVar5 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  iVar4 = *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) * *(int *)(iVar5 + 0x314c)
  ;
  *(int *)(param_1 + 0xd040) = iVar4;
  *(int *)(param_1 + 0xc808) = *(int *)(param_1 + 0xc7ec);
  iVar4 = iVar4 * 4;
  *(int *)(param_1 + 0xc80c) = *(int *)(param_1 + 0xc7ec) + iVar4;
  iVar6 = *(int *)(param_1 + 0xc814);
  *(int *)(param_1 + 0xc83c) = iVar6;
  *(int *)(param_1 + 0xc854) = iVar6;
  *(int *)(param_1 + 0xc850) = iVar6 + iVar4;
  if (*(int *)(iVar5 + 0x329c) < 3) {
    uVar1 = *(undefined4 *)(param_1 + 0xcf70);
    puVar9 = *(undefined4 **)(param_1 + 0xc808);
    iVar5 = *(int *)(param_1 + 0xd040);
    do {
      *puVar9 = uVar1;
      puVar9 = puVar9 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  else {
    puVar9 = *(undefined4 **)(param_1 + 0xc83c);
    puVar10 = *(undefined4 **)(param_1 + 0xc808);
    iVar5 = *(int *)(param_1 + 0xd040);
    do {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  do {
    while( true ) {
      while( true ) {
        iVar5 = *(int *)(param_1 + 0xc900);
        iVar6 = iVar5 * 0xe0 + param_1;
        fVar3 = (float)*(int *)(param_1 + 0x314c + iVar5 * 0x1ec);
        if (*(float *)(iVar6 + 0x144) <= fVar3) break;
        *(float *)(iVar6 + 0x144) = *(float *)(iVar6 + 0x144) - fVar3;
      }
      if (-fVar3 <= *(float *)(iVar6 + 0x144)) break;
      *(float *)(iVar6 + 0x144) = fVar3 + *(float *)(iVar6 + 0x144);
    }
    fVar3 = (float)*(int *)(param_1 + iVar5 * 0x1ec + 0x3150);
    pfVar7 = (float *)(iVar6 + 0x148);
    if (*pfVar7 <= fVar3) {
      do {
        if (-fVar3 <= *pfVar7) {
          *(undefined4 *)(param_1 + 0xcf40) =
               *(undefined4 *)(param_1 + 0x314c + *(int *)(param_1 + 0xc900) * 0x1ec);
          *(undefined4 *)(param_1 + 0xcf3c) =
               *(undefined4 *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x3150);
          lVar11 = __ftol();
          *(int *)(param_1 + 0xcf68) = (int)lVar11;
          lVar11 = __ftol();
          *(int *)(param_1 + 0xcf6c) = (int)lVar11;
          if (*(int *)(param_1 + 0xcf68) < 0) {
            *(int *)(param_1 + 0xcf68) = -*(int *)(param_1 + 0xcf68);
          }
          if (*(int *)(param_1 + 0xcf6c) < 0) {
            *(int *)(param_1 + 0xcf6c) = -*(int *)(param_1 + 0xcf6c);
          }
          *(undefined4 *)(param_1 + 0xca18) = 0;
          goto LAB_1000c5b0;
        }
        *pfVar7 = fVar3 + *pfVar7;
        pfVar7 = (float *)(*(int *)(param_1 + 0xc900) * 0xe0 + 0x148 + param_1);
        fVar3 = (float)*(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec);
      } while (*pfVar7 <= fVar3);
    }
    pfVar7 = (float *)(*(int *)(param_1 + 0xc900) * 0xe0 + 0x148 + param_1);
    *pfVar7 = *pfVar7 - (float)*(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec);
  } while( true );
LAB_1000c5b0:
  iVar5 = **(int **)(param_1 + 0xc83c);
  *(int *)(param_1 + 0xcdac) = iVar5;
  if (iVar5 != *(int *)(param_1 + 0xcf70)) {
    *(uint *)(param_1 + 0xcbac) = *(uint *)(param_1 + 0xca18) / *(uint *)(param_1 + 0xcf40);
    *(uint *)(param_1 + 0xcbb4) = *(uint *)(param_1 + 0xca18) % *(uint *)(param_1 + 0xcf40);
    iVar6 = *(int *)(param_1 + 0xc900);
    iVar5 = param_1 + iVar6 * 0x1ec;
    *(int *)(param_1 + 0xcbb8) =
         *(int *)(param_1 + 0x314c + iVar6 * 0x1ec) - *(int *)(param_1 + 0xcbb4);
    iVar4 = *(int *)(param_1 + 0xc808);
    *(int *)(param_1 + 0xcbbc) = *(int *)(iVar5 + 0x3150) - *(int *)(param_1 + 0xcbac);
    iVar2 = *(int *)(param_1 + 0xcf68);
    *(int *)(param_1 + 0xc838) = iVar4;
    if (iVar2 != 0) {
      if (*(float *)(iVar6 * 0xe0 + 0x144 + param_1) <= _DAT_10021260) {
        if (*(int *)(param_1 + 0xcbb4) < iVar2) {
          if (0 < *(int *)(iVar5 + 0x329c) && *(int *)(iVar5 + 0x329c) < 4) goto LAB_1000c7cb;
          *(int *)(param_1 + 0xc838) = iVar4 + (*(int *)(param_1 + 0xcf40) - iVar2) * 4;
        }
        else {
          *(int *)(param_1 + 0xc838) = iVar4 + iVar2 * -4;
        }
      }
      else if (iVar2 < *(int *)(param_1 + 0xcbb8)) {
        *(int *)(param_1 + 0xc838) = iVar4 + iVar2 * 4;
      }
      else {
        if (0 < *(int *)(iVar5 + 0x329c) && *(int *)(iVar5 + 0x329c) < 4) goto LAB_1000c7cb;
        *(int *)(param_1 + 0xc838) = iVar4 + (iVar2 - *(int *)(param_1 + 0xcf40)) * 4;
      }
    }
    iVar4 = *(int *)(param_1 + 0xcf6c);
    if (iVar4 != 0) {
      if (*(float *)(iVar6 * 0xe0 + 0x148 + param_1) <= _DAT_10021260) {
        if (*(int *)(param_1 + 0xcbac) < iVar4) {
          if (0 < *(int *)(iVar5 + 0x329c) && *(int *)(iVar5 + 0x329c) < 4) goto LAB_1000c7cb;
          *(int *)(param_1 + 0xc838) =
               *(int *)(param_1 + 0xc838) +
               (*(int *)(param_1 + 0xd040) - iVar4 * *(int *)(param_1 + 0xcf40)) * 4;
          goto LAB_1000c7bd;
        }
        iVar4 = -(iVar4 * *(int *)(param_1 + 0xcf40));
      }
      else if (iVar4 < *(int *)(param_1 + 0xcbbc)) {
        iVar4 = iVar4 * *(int *)(param_1 + 0xcf40);
      }
      else {
        if (0 < *(int *)(iVar5 + 0x329c) && *(int *)(iVar5 + 0x329c) < 4) goto LAB_1000c7cb;
        iVar4 = iVar4 * *(int *)(param_1 + 0xcf40) - *(int *)(param_1 + 0xd040);
      }
      *(int *)(param_1 + 0xc838) = *(int *)(param_1 + 0xc838) + iVar4 * 4;
    }
LAB_1000c7bd:
    **(undefined4 **)(param_1 + 0xc838) = *(undefined4 *)(param_1 + 0xcdac);
  }
LAB_1000c7cb:
  iVar5 = *(int *)(param_1 + 0xca18) + 1;
  *(int *)(param_1 + 0xc808) = *(int *)(param_1 + 0xc808) + 4;
  *(int *)(param_1 + 0xc83c) = *(int *)(param_1 + 0xc83c) + 4;
  *(int *)(param_1 + 0xca18) = iVar5;
  if (*(int *)(param_1 + 0xd040) <= iVar5) {
    iVar5 = *(int *)(param_1 + 0xc900);
    iVar6 = *(int *)(param_1 + 0x329c + iVar5 * 0x1ec);
    uVar12 = (ulonglong)CONCAT14(iVar6 == 2,iVar5);
    if (iVar6 == 3 || iVar6 == 2) {
      pfVar7 = (float *)(iVar5 * 0xe0 + 0x148 + param_1);
      if (_DAT_1002129c <= *(float *)(iVar5 * 0xe0 + 0x148 + param_1)) {
        lVar11 = __ftol();
        *pfVar7 = *pfVar7 - (float)(int)lVar11;
      }
      iVar5 = *(int *)(param_1 + 0xc900) * 0xe0;
      pfVar7 = (float *)(iVar5 + 0x144 + param_1);
      if (_DAT_1002129c <= *(float *)(iVar5 + 0x144 + param_1)) {
        lVar11 = __ftol();
        *pfVar7 = *pfVar7 - (float)(int)lVar11;
      }
      iVar5 = *(int *)(param_1 + 0xc900) * 0xe0;
      pfVar7 = (float *)(iVar5 + 0x148 + param_1);
      if (*(float *)(iVar5 + 0x148 + param_1) <= _DAT_10021330) {
        lVar11 = __ftol();
        *pfVar7 = *pfVar7 - (float)(int)lVar11;
      }
      uVar8 = *(int *)(param_1 + 0xc900) * 0xe0;
      pfVar7 = (float *)(uVar8 + 0x144 + param_1);
      uVar12 = (ulonglong)uVar8 << 0x20;
      if (*(float *)(uVar8 + 0x144 + param_1) <= _DAT_10021330) {
        uVar12 = __ftol();
        *pfVar7 = *pfVar7 - (float)(int)uVar12;
      }
    }
    return uVar12 & 0xffffffff00000000;
  }
  goto LAB_1000c5b0;
}




======================================================================
// Function: Blend_WithOverlay @ 1000c940
======================================================================

undefined4 Blend_WithOverlay(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar4 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  iVar2 = *(int *)(param_1 + 0x3188 + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(int *)(param_1 + 0xced8) = iVar2;
  iVar6 = *(int *)(iVar4 + 0x314c);
  iVar4 = *(int *)(iVar4 + 0x3150);
  if ((*(int *)(param_1 + 0x314c + iVar2 * 0x1ec) != iVar6 ||
      *(int *)(param_1 + iVar2 * 0x1ec + 0x3150) != iVar4) || iVar2 == *(int *)(param_1 + 0xc900)) {
    return 0;
  }
  iVar6 = iVar6 * iVar4;
  iVar2 = iVar6 * 4;
  *(int *)(param_1 + 0xc808) = *(int *)(param_1 + 0xc7ec);
  *(int *)(param_1 + 0xc80c) = *(int *)(param_1 + 0xc7ec) + iVar2;
  iVar4 = *(int *)(param_1 + 0xc814);
  *(int *)(param_1 + 0xc83c) = iVar4;
  *(int *)(param_1 + 0xc854) = iVar4;
  *(int *)(param_1 + 0xc850) = iVar4 + iVar2;
  *(int *)(param_1 + 0xd040) = iVar6;
  *(undefined4 *)(param_1 + 0xced4) =
       *(undefined4 *)(param_1 + 0x313c + *(int *)(param_1 + 0xced8) * 0x1ec);
  *(undefined4 *)(param_1 + 0xc84c) =
       *(undefined4 *)(param_1 + 0x30ec + *(int *)(param_1 + 0xced8) * 0x1ec);
  iVar2 = *(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xced8) * 0x1ec);
  iVar4 = param_1 + *(int *)(param_1 + 0xced8) * 0x1ec;
  if (iVar2 == 1) {
    iVar4 = *(int *)(iVar4 + 0x3180);
  }
  else {
    if (iVar2 != 2) goto LAB_1000ca70;
    iVar4 = *(int *)(iVar4 + 0x3264);
  }
  if (iVar4 != 0) {
    *(int *)(param_1 + 0xc84c) = iVar4;
  }
LAB_1000ca70:
  uVar1 = *(undefined4 *)(param_1 + 0xcf70);
  puVar7 = *(undefined4 **)(param_1 + 0xc808);
  iVar4 = *(int *)(param_1 + 0xd040);
  do {
    *puVar7 = uVar1;
    puVar7 = puVar7 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(param_1 + 0xca18) = 0;
  do {
    if ((**(int **)(param_1 + 0xc84c) != *(int *)(param_1 + 0xced4)) &&
       (**(int **)(param_1 + 0xc83c) != *(int *)(param_1 + 0xcf70))) {
      *(int *)(param_1 + 0xcdac) = **(int **)(param_1 + 0xc83c);
      *(int *)(param_1 + 0xced0) = **(int **)(param_1 + 0xc84c);
      uVar5 = *(uint *)(param_1 + 0xced0) & 0xff000000;
      uVar3 = *(uint *)(param_1 + 0xcdac) + uVar5;
      if (CARRY4(*(uint *)(param_1 + 0xcdac),uVar5)) {
        uVar3 = uVar3 | 0xff000000;
      }
      *(uint *)(param_1 + 0xcdac) = uVar3;
      **(undefined4 **)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 0xcdac);
    }
    iVar4 = *(int *)(param_1 + 0xca18) + 1;
    *(int *)(param_1 + 0xc84c) = *(int *)(param_1 + 0xc84c) + 4;
    *(int *)(param_1 + 0xc808) = *(int *)(param_1 + 0xc808) + 4;
    *(int *)(param_1 + 0xc83c) = *(int *)(param_1 + 0xc83c) + 4;
    *(int *)(param_1 + 0xca18) = iVar4;
  } while (iVar4 < *(int *)(param_1 + 0xd040));
  return 0;
}




======================================================================
// Function: Blend_WithTransform @ 1000cb60
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Blend_WithTransform(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  longlong lVar9;
  
  iVar6 = *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
          *(int *)(param_1 + 0x314c + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(int *)(param_1 + 0xd040) = iVar6;
  *(int *)(param_1 + 0xc80c) = *(int *)(param_1 + 0xc7ec) + iVar6 * 4;
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0xc814);
  uVar1 = *(undefined4 *)(param_1 + 0xcf70);
  puVar8 = *(undefined4 **)(param_1 + 0xc7ec);
  iVar6 = *(int *)(param_1 + 0xd040);
  do {
    *puVar8 = uVar1;
    puVar8 = puVar8 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar2 = *(int *)(param_1 + 0xc900);
  iVar6 = param_1 + iVar2 * 0x1ec;
  *(int *)(param_1 + 0xc8cc) =
       *(int *)(iVar6 + 0x31d8) + *(int *)(param_1 + 0x314c + iVar2 * 0x1ec) / 2;
  *(int *)(param_1 + 0xc8d4) = *(int *)(iVar6 + 0x3150) / 2 + *(int *)(iVar6 + 0x31dc);
  *(undefined4 *)(param_1 + 0xcf40) = *(undefined4 *)(iVar6 + 0x314c);
  *(float *)(param_1 + 0xcf28) = *(float *)(iVar2 * 0xe0 + 0x154 + param_1) * _DAT_10021334;
  fVar4 = *(float *)(iVar2 * 0xe0 + param_1 + 0x158) * _DAT_10021334;
  *(undefined4 *)(param_1 + 0xca18) = 0;
  *(float *)(param_1 + 0xcf2c) = fVar4;
  do {
    iVar6 = **(int **)(param_1 + 0xc83c);
    *(int *)(param_1 + 0xcdac) = iVar6;
    if (iVar6 != *(int *)(param_1 + 0xcf70)) {
      *(uint *)(param_1 + 0xcbc8) = *(uint *)(param_1 + 0xca18) / *(uint *)(param_1 + 0xcf40);
      *(uint *)(param_1 + 0xcbc4) = *(uint *)(param_1 + 0xca18) % *(uint *)(param_1 + 0xcf40);
      iVar6 = *(int *)(param_1 + 0xc8cc);
      iVar2 = *(int *)(param_1 + 0xc900);
      fVar4 = (float)(*(int *)(param_1 + 0xcbc4) - iVar6);
      *(float *)(param_1 + 0xcbcc) = fVar4;
      fVar5 = (float)(*(int *)(param_1 + 0xcbc8) - *(int *)(param_1 + 0xc8d4));
      *(float *)(param_1 + 0xcbd0) = fVar5;
      if (*(float *)(iVar2 * 0xe0 + 0x154 + param_1) != _DAT_10021260) {
        *(float *)(param_1 + 0xcbcc) =
             (float)((*(int *)(param_1 + 0x31dc + iVar2 * 0x1ec) +
                     *(int *)(param_1 + iVar2 * 0x1ec + 0x3150)) - *(int *)(param_1 + 0xcbc8)) *
             fVar4 * *(float *)(param_1 + 0xcf28);
      }
      if (*(float *)(iVar2 * 0xe0 + param_1 + 0x158) != _DAT_10021260) {
        *(float *)(param_1 + 0xcbd0) =
             (float)((*(int *)(param_1 + 0x31d8 + iVar2 * 0x1ec) +
                     *(int *)(param_1 + 0x314c + iVar2 * 0x1ec)) - *(int *)(param_1 + 0xcbc4)) *
             *(float *)(param_1 + 0xcf2c) * fVar5;
      }
      lVar9 = __ftol();
      iVar6 = iVar6 + (int)lVar9;
      *(int *)(param_1 + 0xcd88) = iVar6;
      lVar9 = __ftol();
      iVar7 = (int)lVar9 + *(int *)(param_1 + 0xc8d4);
      *(int *)(param_1 + 0xcd90) = iVar7;
      iVar3 = *(int *)(param_1 + 0x314c + iVar2 * 0x1ec);
      if (((iVar7 < *(int *)(param_1 + 0x3150 + iVar2 * 0x1ec) && iVar6 < iVar3) && -1 < iVar7) &&
          -1 < iVar6) {
        puVar8 = (undefined4 *)(*(int *)(param_1 + 0xc7ec) + (iVar7 * iVar3 + iVar6) * 4);
        *(undefined4 **)(param_1 + 0xc808) = puVar8;
        *puVar8 = *(undefined4 *)(param_1 + 0xcdac);
      }
    }
    iVar6 = *(int *)(param_1 + 0xca18) + 1;
    *(int *)(param_1 + 0xc83c) = *(int *)(param_1 + 0xc83c) + 4;
    *(int *)(param_1 + 0xca18) = iVar6;
  } while (iVar6 < *(int *)(param_1 + 0xd040));
  return 0;
}




======================================================================
// Function: Blend_CopySecondary @ 1000ce40
======================================================================

undefined4 Blend_CopySecondary(int param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  *(int *)(param_1 + 0xd040) =
       *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) * *(int *)(iVar2 + 0x314c);
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 0xc7ec);
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0xc814);
  iVar2 = *(int *)(iVar2 + 0x3290);
  *(int *)(param_1 + 0xcdcc) = iVar2;
  *(undefined4 *)(param_1 + 0xc840) = *(undefined4 *)(param_1 + 0x30ec + iVar2 * 0x1ec);
  if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xcdcc) * 0x1ec) == 1) {
    *(undefined4 *)(param_1 + 0xc840) =
         *(undefined4 *)(param_1 + *(int *)(param_1 + 0xcdcc) * 0x1ec + 0x3180);
  }
  if (*(int *)(param_1 + 0x317c + *(int *)(param_1 + 0xcdcc) * 0x1ec) == 2) {
    *(undefined4 *)(param_1 + 0xc840) =
         *(undefined4 *)(param_1 + *(int *)(param_1 + 0xcdcc) * 0x1ec + 0x3264);
  }
  if (*(int *)(param_1 + 0xc840) != 0) {
    iVar2 = *(int *)(param_1 + 0xd040);
    puVar3 = *(uint **)(param_1 + 0xc808);
    do {
      uVar1 = **(uint **)(param_1 + 0xc83c);
      if ((uVar1 & 0xffffff) != *(uint *)(param_1 + 0xcf70)) {
        *puVar3 = *(uint *)(*(int *)(param_1 + 0xc840) + (uVar1 >> 0x18) * 4) | uVar1 & 0xff000000;
      }
      puVar3 = puVar3 + 1;
      *(int *)(param_1 + 0xc83c) = *(int *)(param_1 + 0xc83c) + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}




======================================================================
// Function: Blend_CopyBack @ 1000cf60
======================================================================

undefined4 Blend_CopyBack(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0xce48) < 1) {
    *(undefined4 *)(param_1 + 0xce48) = 1;
  }
  iVar1 = *(int *)(param_1 + 0xce48);
  if ((((iVar1 != 0xfe) && (iVar1 != 0xff)) && (iVar1 != 0x100)) &&
     ((iVar1 != 0x101 && (iVar1 != 0x102)))) {
    uVar2 = *(uint *)(param_1 + 0xcdd4);
    if (uVar2 < 0x80000000) {
      uVar2 = *(int *)(param_1 + 0xce48) * uVar2;
      uVar3 = uVar2 >> 8;
      if ((uVar2 >> 7 & 1) != 0) {
        uVar3 = uVar3 + 1;
      }
    }
    else {
      uVar2 = *(int *)(param_1 + 0xce48) * -uVar2;
      uVar3 = uVar2 >> 8;
      if ((uVar2 >> 7 & 1) != 0) {
        uVar3 = uVar3 + 1;
      }
      uVar3 = -uVar3;
    }
    *(uint *)(param_1 + 0xcdd4) = uVar3;
    uVar2 = *(uint *)(param_1 + 0xcddc);
    if (uVar2 < 0x80000000) {
      uVar2 = *(int *)(param_1 + 0xce48) * uVar2;
      uVar3 = uVar2 >> 8;
      if ((uVar2 >> 7 & 1) != 0) {
        uVar3 = uVar3 + 1;
      }
    }
    else {
      uVar2 = *(int *)(param_1 + 0xce48) * -uVar2;
      uVar3 = uVar2 >> 8;
      if ((uVar2 >> 7 & 1) != 0) {
        uVar3 = uVar3 + 1;
      }
      uVar3 = -uVar3;
    }
    *(uint *)(param_1 + 0xcddc) = uVar3;
  }
  return 0;
}




======================================================================
// Function: Blend_Screen @ 1000d020
======================================================================

undefined4 Blend_Screen(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0xce48) < 1) {
    *(undefined4 *)(param_1 + 0xce48) = 1;
  }
  iVar1 = *(int *)(param_1 + 0xce48);
  if ((((iVar1 != 0xfe) && (iVar1 != 0xff)) && (iVar1 != 0x100)) &&
     ((iVar1 != 0x101 && (iVar1 != 0x102)))) {
    if (0x2ff < iVar1) {
      *(undefined4 *)(param_1 + 0xce48) = 0x2ff;
    }
    uVar2 = *(uint *)(param_1 + 0xcdd4);
    if (uVar2 < 0x80000000) {
      uVar2 = (uVar2 << 8) / *(uint *)(param_1 + 0xce48);
    }
    else {
      uVar2 = -((uVar2 * -0x100) / *(uint *)(param_1 + 0xce48));
    }
    *(uint *)(param_1 + 0xcdd4) = uVar2;
    uVar2 = *(uint *)(param_1 + 0xcddc);
    if (uVar2 < 0x80000000) {
      uVar2 = (uVar2 << 8) / *(uint *)(param_1 + 0xce48);
    }
    else {
      uVar2 = -((uVar2 * -0x100) / *(uint *)(param_1 + 0xce48));
    }
    *(uint *)(param_1 + 0xcddc) = uVar2;
  }
  return 0;
}




======================================================================
// Function: Blend_Multiply @ 1000d200
======================================================================

undefined4 Blend_Multiply(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x3392];
  if ((((iVar1 != 0) && (iVar1 != 0xfe)) && (iVar1 != 0xff)) &&
     (((iVar1 != 0x100 && (iVar1 != 0x101)) && (iVar1 != 0x102)))) {
    (**(code **)(*param_1 + 0x104))(param_1);
    if (param_1[0x3274] != 1) {
      iVar1 = param_1[0x3392];
      if (iVar1 < 0x100) {
        (**(code **)(*param_1 + 0x224))(param_1);
      }
      else if (iVar1 < 0x201) {
        (**(code **)(*param_1 + 0x228))(param_1);
      }
      else {
        if (0x300 < iVar1) {
          param_1[0x3392] = 0x300;
        }
        (**(code **)(*param_1 + 0x22c))(param_1);
      }
      param_1[0x32cb] = param_1[0x3205];
      param_1[0x3205] = param_1[0x32c2];
      (**(code **)(*param_1 + 0x1ac))(param_1);
    }
  }
  return 0;
}




======================================================================
// Function: Blend_Overlay @ 1000d2c0
======================================================================

undefined4 Blend_Overlay(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x3392];
  if ((((iVar1 != 0) && (iVar1 != 0xfe)) && (iVar1 != 0xff)) &&
     (((iVar1 != 0x100 && (iVar1 != 0x101)) && (iVar1 != 0x102)))) {
    (**(code **)(*param_1 + 0x104))(param_1);
    if (param_1[0x3274] != 1) {
      iVar1 = param_1[0x3392];
      if (iVar1 < 0x100) {
        (**(code **)(*param_1 + 0x230))(param_1);
      }
      else if (iVar1 < 0x201) {
        (**(code **)(*param_1 + 0x234))(param_1);
      }
      else {
        if (0x300 < iVar1) {
          param_1[0x3392] = 0x300;
        }
        (**(code **)(*param_1 + 0x238))(param_1);
      }
      param_1[0x32cb] = param_1[0x3205];
      param_1[0x3205] = param_1[0x32c2];
      (**(code **)(*param_1 + 0x1ac))(param_1);
    }
  }
  return 0;
}




======================================================================
// Function: Blend_SoftLight @ 1000d380
======================================================================

undefined4 Blend_SoftLight(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  iVar1 = 0;
  uVar3 = 0x100 - *(int *)(param_1 + 0xce48);
  uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
  iVar2 = *(int *)(param_1 + 0xc998);
  uVar4 = 0;
  do {
    iVar1 = iVar1 + 1;
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        *(int *)(param_1 + 0xc998) = iVar1;
        iVar1 = 0;
        iVar2 = *(int *)(param_1 + 0xc994);
        uVar4 = 0;
        do {
          iVar1 = iVar1 + 1;
          do {
            iVar2 = iVar2 + -1;
            if (iVar2 == 0) {
              *(int *)(param_1 + 0xc994) = iVar1;
              iVar2 = *(int *)(param_1 + 0xcee4);
              if (iVar2 == 0) {
                return 0;
              }
              iVar1 = 0;
              uVar4 = 0;
              do {
                iVar1 = iVar1 + 1;
                do {
                  iVar2 = iVar2 + -1;
                  if (iVar2 == 0) {
                    *(int *)(param_1 + 0xcee4) = iVar1;
                    return 0;
                  }
                  bVar5 = CARRY4(uVar4,uVar3);
                  uVar4 = uVar4 + uVar3;
                } while (bVar5);
              } while( true );
            }
            bVar5 = CARRY4(uVar4,uVar3);
            uVar4 = uVar4 + uVar3;
          } while (bVar5);
        } while( true );
      }
      bVar5 = CARRY4(uVar4,uVar3);
      uVar4 = uVar4 + uVar3;
    } while (bVar5);
  } while( true );
}




======================================================================
// Function: Effect_Invert @ 1000d3f0
======================================================================

undefined4 Effect_Invert(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = 0x200 - *(int *)(param_1 + 0xce48);
  uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
  iVar3 = *(int *)(param_1 + 0xc998);
  uVar5 = 0;
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1;
    iVar1 = iVar2 + 1;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    bVar6 = CARRY4(uVar5,uVar4);
    uVar5 = uVar5 + uVar4;
    if (!bVar6) {
      iVar1 = iVar2 + 2;
    }
  }
  *(int *)(param_1 + 0xc998) = iVar1;
  iVar3 = *(int *)(param_1 + 0xc994);
  uVar5 = 0;
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1;
    iVar1 = iVar2 + 1;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    bVar6 = CARRY4(uVar5,uVar4);
    uVar5 = uVar5 + uVar4;
    if (!bVar6) {
      iVar1 = iVar2 + 2;
    }
  }
  *(int *)(param_1 + 0xc994) = iVar1;
  iVar3 = *(int *)(param_1 + 0xcee4);
  if (iVar3 != 0) {
    uVar5 = 0;
    iVar1 = 0;
    while( true ) {
      iVar2 = iVar1;
      iVar1 = iVar2 + 1;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) break;
      bVar6 = CARRY4(uVar5,uVar4);
      uVar5 = uVar5 + uVar4;
      if (!bVar6) {
        iVar1 = iVar2 + 2;
      }
    }
    *(int *)(param_1 + 0xcee4) = iVar1;
  }
  return 0;
}




======================================================================
// Function: Effect_Grayscale @ 1000d470
======================================================================

undefined4 Effect_Grayscale(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = 0x300 - *(int *)(param_1 + 0xce48);
  if (0xff < uVar4) {
    uVar4 = 0;
  }
  uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  iVar3 = *(int *)(param_1 + 0xc998);
  uVar5 = 0;
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1;
    iVar1 = iVar2 + 2;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    bVar6 = CARRY4(uVar5,uVar4);
    uVar5 = uVar5 + uVar4;
    if (!bVar6) {
      iVar1 = iVar2 + 3;
    }
  }
  *(int *)(param_1 + 0xc998) = iVar1;
  iVar3 = *(int *)(param_1 + 0xc994);
  uVar5 = 0;
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1;
    iVar1 = iVar2 + 2;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    bVar6 = CARRY4(uVar5,uVar4);
    uVar5 = uVar5 + uVar4;
    if (!bVar6) {
      iVar1 = iVar2 + 3;
    }
  }
  *(int *)(param_1 + 0xc994) = iVar1;
  iVar3 = *(int *)(param_1 + 0xcee4);
  if (iVar3 != 0) {
    uVar5 = 0;
    iVar1 = 0;
    while( true ) {
      iVar2 = iVar1;
      iVar1 = iVar2 + 2;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) break;
      bVar6 = CARRY4(uVar5,uVar4);
      uVar5 = uVar5 + uVar4;
      if (!bVar6) {
        iVar1 = iVar2 + 3;
      }
    }
    *(int *)(param_1 + 0xcee4) = iVar1;
  }
  return 0;
}




======================================================================
// Function: Effect_Brightness @ 1000d500
======================================================================

undefined4 Effect_Brightness(int param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  iVar4 = *(int *)(param_1 + 0xcc58);
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  if (iVar4 < 0x100) {
    *(undefined4 *)(param_1 + 0xcf8c) = 0x100;
  }
  else if (iVar4 < 0x201) {
    *(undefined4 *)(param_1 + 0xcf8c) = 0x200;
  }
  else if (iVar4 < 0x301) {
    *(undefined4 *)(param_1 + 0xcf8c) = 0x2ff;
  }
  iVar4 = *(int *)(param_1 + 0xcc5c);
  if (iVar4 < 0x100) {
    *(undefined4 *)(param_1 + 0xcf90) = 0x100;
  }
  else if (iVar4 < 0x201) {
    *(undefined4 *)(param_1 + 0xcf90) = 0x200;
  }
  else {
    if (0x300 < iVar4) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0xcf90) = 0x2ff;
  }
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  *(int *)(param_1 + 0xcb4c) = *(int *)(param_1 + 0xcb48) << 2;
  puVar8 = *(undefined4 **)(param_1 + 0xc814);
  puVar9 = *(undefined4 **)(param_1 + 0xcb08);
  *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(param_1 + 0xcb44);
  uVar6 = *(int *)(param_1 + 0xcf90) - *(int *)(param_1 + 0xcc5c);
  if ((0x200 < *(uint *)(param_1 + 0xcc5c)) && (uVar6 = uVar6 + 1, 0xff < uVar6)) {
    uVar6 = 0;
  }
  *(uint *)(param_1 + 0xccb8) =
       uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  uVar6 = *(int *)(param_1 + 0xcf8c) - *(int *)(param_1 + 0xcc58);
  if ((0x200 < *(uint *)(param_1 + 0xcc58)) && (uVar6 = uVar6 + 1, 0xff < uVar6)) {
    uVar6 = 0;
  }
  uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
LAB_1000d60b:
  do {
    iVar4 = *(int *)(param_1 + 0xcb48);
    uVar7 = 0;
    if (*(uint *)(param_1 + 0xcc58) < 0x101) {
      do {
        *puVar9 = *puVar8;
        puVar9 = puVar9 + 1;
        do {
          puVar8 = puVar8 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_1000d675;
          bVar11 = CARRY4(uVar7,uVar6);
          uVar7 = uVar7 + uVar6;
        } while (bVar11);
      } while( true );
    }
    if (*(uint *)(param_1 + 0xcc58) < 0x201) {
      while( true ) {
        puVar10 = puVar9;
        uVar3 = *puVar8;
        *puVar10 = uVar3;
        puVar9 = puVar10 + 1;
        puVar8 = puVar8 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
        bVar11 = CARRY4(uVar7,uVar6);
        uVar7 = uVar7 + uVar6;
        if (!bVar11) {
          *puVar9 = uVar3;
          puVar9 = puVar10 + 2;
        }
      }
    }
    else {
      while( true ) {
        puVar10 = puVar9;
        uVar3 = *puVar8;
        *puVar10 = uVar3;
        puVar10[1] = uVar3;
        puVar9 = puVar10 + 2;
        puVar8 = puVar8 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
        bVar11 = CARRY4(uVar7,uVar6);
        uVar7 = uVar7 + uVar6;
        if (!bVar11) {
          *puVar9 = uVar3;
          puVar9 = puVar10 + 3;
        }
      }
    }
LAB_1000d675:
    iVar4 = *(int *)(param_1 + 0xc7e8);
    if (iVar4 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0xcc88);
      do {
        *puVar9 = uVar3;
        puVar9 = puVar9 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    while (*(uint *)(param_1 + 0xcc5c) < 0x101) {
      piVar1 = (int *)(param_1 + 0xcdbc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        return 0;
      }
      puVar2 = (uint *)(param_1 + 0xccd0);
      uVar7 = *puVar2;
      *puVar2 = *puVar2 + *(uint *)(param_1 + 0xccb8);
      if (!CARRY4(uVar7,*(uint *)(param_1 + 0xccb8))) goto LAB_1000d60b;
      puVar8 = (undefined4 *)((int)puVar8 + *(int *)(param_1 + 0xcb4c));
    }
    if (*(uint *)(param_1 + 0xcc5c) < 0x201) {
      piVar1 = (int *)(param_1 + 0xcdbc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        return 0;
      }
      puVar2 = (uint *)(param_1 + 0xccd0);
      uVar7 = *puVar2;
      *puVar2 = *puVar2 + *(uint *)(param_1 + 0xccb8);
      if (!CARRY4(uVar7,*(uint *)(param_1 + 0xccb8))) {
        iVar4 = *(int *)(param_1 + 0xc894);
        puVar9 = puVar9 + -iVar4;
        iVar5 = iVar4;
        do {
          puVar9[iVar4] = *puVar9;
          puVar9 = puVar9 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        puVar9 = puVar9 + iVar4;
      }
    }
    else {
      iVar4 = *(int *)(param_1 + 0xc894);
      puVar9 = puVar9 + -iVar4;
      iVar5 = iVar4;
      do {
        puVar9[iVar4] = *puVar9;
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      puVar9 = puVar9 + iVar4;
      piVar1 = (int *)(param_1 + 0xcdbc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        return 0;
      }
      puVar2 = (uint *)(param_1 + 0xccd0);
      uVar7 = *puVar2;
      *puVar2 = *puVar2 + *(uint *)(param_1 + 0xccb8);
      if (!CARRY4(uVar7,*(uint *)(param_1 + 0xccb8))) {
        iVar4 = *(int *)(param_1 + 0xc894);
        puVar9 = puVar9 + -iVar4;
        iVar5 = iVar4;
        do {
          puVar9[iVar4] = *puVar9;
          puVar9 = puVar9 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        puVar9 = puVar9 + iVar4;
      }
    }
  } while( true );
}




======================================================================
// Function: Effect_Contrast @ 1000d770
======================================================================

undefined4 Effect_Contrast(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  iVar1 = 0;
  uVar3 = 0x100 - *(int *)(param_1 + 0xce48);
  uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
  iVar2 = *(int *)(param_1 + 0xcff0);
  uVar4 = 0;
  do {
    iVar1 = iVar1 + 1;
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        *(int *)(param_1 + 0xcff0) = iVar1;
        return 0;
      }
      bVar5 = CARRY4(uVar4,uVar3);
      uVar4 = uVar4 + uVar3;
    } while (bVar5);
  } while( true );
}




======================================================================
// Function: Effect_Saturation @ 1000d7b0
======================================================================

undefined4 Effect_Saturation(int param_1)

{
  int iVar1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int iVar2;
  
  uVar4 = 0x200 - *(int *)(param_1 + 0xce48);
  uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
  iVar3 = *(int *)(param_1 + 0xcff0);
  uVar5 = 0;
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1;
    iVar1 = iVar2 + 1;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    bVar6 = CARRY4(uVar5,uVar4);
    uVar5 = uVar5 + uVar4;
    if (!bVar6) {
      iVar1 = iVar2 + 2;
    }
  }
  *(int *)(param_1 + 0xcff0) = iVar1;
  return 0;
}




======================================================================
// Function: Effect_Hue @ 1000d7f0
======================================================================

undefined4 Effect_Hue(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = 0x300 - *(int *)(param_1 + 0xce48);
  if (0xff < uVar4) {
    uVar4 = 0;
  }
  uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  iVar3 = *(int *)(param_1 + 0xcff0);
  uVar5 = 0;
  iVar2 = 0;
  while( true ) {
    iVar1 = iVar2;
    iVar2 = iVar1 + 2;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    bVar6 = CARRY4(uVar5,uVar4);
    uVar5 = uVar5 + uVar4;
    if (!bVar6) {
      iVar2 = iVar1 + 3;
    }
  }
  *(int *)(param_1 + 0xcff0) = iVar2;
  return 0;
}




======================================================================
// Function: Effect_Gamma @ 1000d840
======================================================================

undefined4 Effect_Gamma(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  *(int *)(param_1 + 0xcb4c) = *(int *)(param_1 + 0xcb48) << 2;
  puVar6 = *(undefined4 **)(param_1 + 0xc814);
  puVar7 = *(undefined4 **)(param_1 + 0xcb08);
  *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(param_1 + 0xcb44);
  uVar4 = 0x100 - *(int *)(param_1 + 0xce48);
  uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
LAB_1000d88b:
  iVar3 = *(int *)(param_1 + 0xcb48);
  uVar5 = 0;
  do {
    *puVar7 = *puVar6;
    puVar7 = puVar7 + 1;
    do {
      puVar6 = puVar6 + 1;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) goto LAB_1000d8a6;
      bVar8 = CARRY4(uVar5,uVar4);
      uVar5 = uVar5 + uVar4;
    } while (bVar8);
  } while( true );
LAB_1000d8a6:
  while( true ) {
    piVar1 = (int *)(param_1 + 0xcdbc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      return 0;
    }
    puVar2 = (uint *)(param_1 + 0xccd0);
    uVar5 = *puVar2;
    *puVar2 = *puVar2 + uVar4;
    if (!CARRY4(uVar5,uVar4)) break;
    puVar6 = (undefined4 *)((int)puVar6 + *(int *)(param_1 + 0xcb4c));
  }
  goto LAB_1000d88b;
}




======================================================================
// Function: Effect_ColorBalance @ 1000d8d0
======================================================================

undefined4 Effect_ColorBalance(int param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  puVar8 = *(undefined4 **)(param_1 + 0xc814);
  puVar9 = *(undefined4 **)(param_1 + 0xcb08);
  *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(param_1 + 0xcb44);
  uVar6 = 0x200 - *(int *)(param_1 + 0xce48);
  uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
  while( true ) {
    iVar4 = *(int *)(param_1 + 0xcb48);
    uVar7 = 0;
    while( true ) {
      puVar10 = puVar9;
      uVar3 = *puVar8;
      *puVar10 = uVar3;
      puVar9 = puVar10 + 1;
      puVar8 = puVar8 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      bVar11 = CARRY4(uVar7,uVar6);
      uVar7 = uVar7 + uVar6;
      if (!bVar11) {
        *puVar9 = uVar3;
        puVar9 = puVar10 + 2;
      }
    }
    piVar1 = (int *)(param_1 + 0xcdbc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) break;
    puVar2 = (uint *)(param_1 + 0xccd0);
    uVar7 = *puVar2;
    *puVar2 = *puVar2 + uVar6;
    if (!CARRY4(uVar7,uVar6)) {
      iVar4 = *(int *)(param_1 + 0xc998);
      puVar9 = puVar9 + -iVar4;
      iVar5 = iVar4;
      do {
        puVar9[iVar4] = *puVar9;
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      puVar9 = puVar9 + iVar4;
    }
  }
  return 0;
}




======================================================================
// Function: Effect_ColorLookup @ 1000d970
======================================================================

undefined4 Effect_ColorLookup(int param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  puVar8 = *(undefined4 **)(param_1 + 0xc814);
  puVar9 = *(undefined4 **)(param_1 + 0xcb08);
  *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(param_1 + 0xcb44);
  uVar6 = 0x300 - *(int *)(param_1 + 0xce48);
  if (0xff < uVar6) {
    uVar6 = 0;
  }
  uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  while( true ) {
    iVar4 = *(int *)(param_1 + 0xcb48);
    uVar7 = 0;
    while( true ) {
      puVar10 = puVar9;
      uVar3 = *puVar8;
      *puVar10 = uVar3;
      puVar10[1] = uVar3;
      puVar9 = puVar10 + 2;
      puVar8 = puVar8 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      bVar11 = CARRY4(uVar7,uVar6);
      uVar7 = uVar7 + uVar6;
      if (!bVar11) {
        *puVar9 = uVar3;
        puVar9 = puVar10 + 3;
      }
    }
    iVar4 = *(int *)(param_1 + 0xc998);
    puVar9 = puVar9 + -iVar4;
    iVar5 = iVar4;
    do {
      puVar9[iVar4] = *puVar9;
      puVar9 = puVar9 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar9 = puVar9 + iVar4;
    piVar1 = (int *)(param_1 + 0xcdbc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) break;
    puVar2 = (uint *)(param_1 + 0xccd0);
    uVar7 = *puVar2;
    *puVar2 = *puVar2 + uVar6;
    if (!CARRY4(uVar7,uVar6)) {
      iVar4 = *(int *)(param_1 + 0xc998);
      puVar9 = puVar9 + -iVar4;
      iVar5 = iVar4;
      do {
        puVar9[iVar4] = *puVar9;
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      puVar9 = puVar9 + iVar4;
    }
  }
  return 0;
}




======================================================================
// Function: Effect_ChannelMix @ 1000da30
======================================================================

undefined4 Effect_ChannelMix(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  *(undefined4 *)(param_1 + 0xc96c) = 0;
  *(undefined4 *)(param_1 + 0xca54) = 0;
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  *(undefined4 *)(param_1 + 0xcdf4) = *(undefined4 *)(param_1 + 0xc930);
  *(int *)(param_1 + 0xcb4c) = *(int *)(param_1 + 0xcb48) << 2;
  puVar6 = *(undefined4 **)(param_1 + 0xc814);
  puVar7 = *(undefined4 **)(param_1 + 0xcb08);
  uVar3 = 0x100 - *(int *)(param_1 + 0xce48);
  uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
  do {
    *(int *)(param_1 + 0xca54) = *(int *)(param_1 + 0xca54) + 1;
    if (*(uint *)(param_1 + 0xcdf4) < *(uint *)(param_1 + 0xca54)) {
      if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
        return 0;
      }
      *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
      uVar4 = 0;
      puVar5 = puVar6;
      for (iVar2 = *(int *)(param_1 + 0xc940); iVar2 != 0; iVar2 = iVar2 + -1) {
        do {
          puVar5 = puVar5 + 1;
          bVar8 = CARRY4(uVar4,uVar3);
          uVar4 = uVar4 + uVar3;
        } while (bVar8);
      }
      iVar2 = *(int *)(param_1 + 0xc998);
      while( true ) {
        *puVar7 = *puVar5;
        puVar7 = puVar7 + 1;
        iVar2 = iVar2 + -1;
        if (iVar2 == 0) break;
        do {
          puVar5 = puVar5 + 1;
          bVar8 = CARRY4(uVar4,uVar3);
          uVar4 = uVar4 + uVar3;
        } while (bVar8);
      }
    }
    puVar6 = puVar6 + *(int *)(param_1 + 0xcb48);
    while( true ) {
      puVar1 = (uint *)(param_1 + 0xccd0);
      uVar4 = *puVar1;
      *puVar1 = *puVar1 + uVar3;
      if (!CARRY4(uVar4,uVar3)) break;
      puVar6 = (undefined4 *)((int)puVar6 + *(int *)(param_1 + 0xcb4c));
    }
  } while( true );
}




======================================================================
// Function: Render_ComplexScene @ 1000db10
======================================================================

undefined4 Render_ComplexScene(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  *(undefined4 *)(param_1 + 0xc96c) = 0;
  *(undefined4 *)(param_1 + 0xca54) = 0;
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  *(undefined4 *)(param_1 + 0xcdf4) = *(undefined4 *)(param_1 + 0xc930);
  puVar8 = *(undefined4 **)(param_1 + 0xc814);
  puVar10 = *(undefined4 **)(param_1 + 0xcb08);
  uVar6 = 0x200 - *(int *)(param_1 + 0xce48);
  uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
          *(int *)(param_1 + 0xce48) * -0x1000000;
LAB_1000db56:
  do {
    do {
      if (*(uint *)(param_1 + 0xcdf4) <= *(uint *)(param_1 + 0xca54)) {
        if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
          return 0;
        }
        *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
        iVar4 = *(int *)(param_1 + 0xc998);
        uVar7 = 0;
        iVar5 = *(int *)(param_1 + 0xc940);
        puVar9 = puVar8;
        if (iVar5 != 0) {
          while( true ) {
            iVar2 = iVar5 + -1;
            if (iVar2 == 0) {
              uVar3 = *puVar9;
              goto LAB_1000dbb8;
            }
            bVar11 = CARRY4(uVar7,uVar6);
            uVar7 = uVar7 + uVar6;
            if ((!bVar11) && (iVar2 = iVar5 + -2, iVar2 == 0)) break;
            iVar5 = iVar2;
            puVar9 = puVar9 + 1;
          }
          puVar9 = puVar9 + 1;
        }
        do {
          do {
            uVar3 = *puVar9;
            *puVar10 = uVar3;
            puVar10 = puVar10 + 1;
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) goto LAB_1000dbc5;
LAB_1000dbb8:
            puVar9 = puVar9 + 1;
            bVar11 = CARRY4(uVar7,uVar6);
            uVar7 = uVar7 + uVar6;
          } while (bVar11);
          *puVar10 = uVar3;
          puVar10 = puVar10 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
LAB_1000dbc5:
      puVar8 = puVar8 + *(int *)(param_1 + 0xcb48);
      *(int *)(param_1 + 0xca54) = *(int *)(param_1 + 0xca54) + 1;
      puVar1 = (uint *)(param_1 + 0xccd0);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 + uVar6;
    } while ((CARRY4(uVar7,uVar6)) ||
            (*(int *)(param_1 + 0xca54) = *(int *)(param_1 + 0xca54) + 1,
            *(uint *)(param_1 + 0xca54) <= *(uint *)(param_1 + 0xcdf4)));
    if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
      return 0;
    }
    *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
    if (*(int *)(param_1 + 0xc96c) == 1) {
      puVar9 = puVar8 + -*(int *)(param_1 + 0xcb48);
      iVar4 = *(int *)(param_1 + 0xc998);
      uVar7 = 0;
      iVar5 = *(int *)(param_1 + 0xc940);
      if (iVar5 != 0) {
        while( true ) {
          iVar2 = iVar5 + -1;
          if (iVar2 == 0) {
            uVar3 = *puVar9;
            goto LAB_1000dc62;
          }
          bVar11 = CARRY4(uVar7,uVar6);
          uVar7 = uVar7 + uVar6;
          if ((!bVar11) && (iVar2 = iVar5 + -2, iVar2 == 0)) break;
          puVar9 = puVar9 + 1;
          iVar5 = iVar2;
        }
        puVar9 = puVar9 + 1;
      }
      do {
        do {
          uVar3 = *puVar9;
          *puVar10 = uVar3;
          puVar10 = puVar10 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_1000db56;
LAB_1000dc62:
          puVar9 = puVar9 + 1;
          bVar11 = CARRY4(uVar7,uVar6);
          uVar7 = uVar7 + uVar6;
        } while (bVar11);
        *puVar10 = uVar3;
        puVar10 = puVar10 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      goto LAB_1000db56;
    }
    iVar4 = *(int *)(param_1 + 0xc998);
    puVar10 = puVar10 + -iVar4;
    iVar5 = iVar4;
    do {
      puVar10[iVar4] = *puVar10;
      puVar10 = puVar10 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar10 = puVar10 + iVar4;
  } while( true );
}




======================================================================
// Function: Render_Particles @ 1000dca0
======================================================================

undefined4 Render_Particles(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  
  *(undefined4 *)(param_1 + 0xc96c) = 0;
  *(undefined4 *)(param_1 + 0xca54) = 0;
  *(undefined4 *)(param_1 + 0xccd0) = 0;
  *(undefined4 *)(param_1 + 0xcdf4) = *(undefined4 *)(param_1 + 0xc930);
  puVar9 = *(undefined4 **)(param_1 + 0xc814);
  puVar11 = *(undefined4 **)(param_1 + 0xcb08);
  *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(param_1 + 0xcb44);
  uVar7 = 0x300 - *(int *)(param_1 + 0xce48);
  if (0xff < uVar7) {
    uVar7 = 0;
  }
  uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
LAB_1000dd00:
  do {
    do {
      if (*(uint *)(param_1 + 0xcdf4) <= *(uint *)(param_1 + 0xca54)) {
        if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
          return 0;
        }
        *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
        uVar8 = 0;
        iVar6 = *(int *)(param_1 + 0xc998);
        iVar2 = *(int *)(param_1 + 0xc940);
        puVar10 = puVar9;
        while (iVar2 != 0) {
          do {
            iVar3 = iVar2;
            if (iVar3 == 1) {
              uVar5 = *puVar10;
              goto LAB_1000dd5e;
            }
            if (iVar3 + -2 == 0) {
              uVar5 = *puVar10;
              goto LAB_1000dd66;
            }
            puVar10 = puVar10 + 1;
            bVar12 = CARRY4(uVar8,uVar7);
            uVar8 = uVar8 + uVar7;
            iVar2 = iVar3 + -2;
          } while (bVar12);
          iVar2 = iVar3 + -3;
        }
        do {
          do {
            uVar5 = *puVar10;
            *puVar11 = uVar5;
            puVar11 = puVar11 + 1;
            iVar6 = iVar6 + -1;
            if (iVar6 == 0) goto LAB_1000dd76;
LAB_1000dd5e:
            *puVar11 = uVar5;
            puVar11 = puVar11 + 1;
            iVar6 = iVar6 + -1;
            if (iVar6 == 0) goto LAB_1000dd76;
LAB_1000dd66:
            puVar10 = puVar10 + 1;
            bVar12 = CARRY4(uVar8,uVar7);
            uVar8 = uVar8 + uVar7;
          } while (bVar12);
          *puVar11 = uVar5;
          puVar11 = puVar11 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
LAB_1000dd76:
      iVar6 = *(int *)(param_1 + 0xcb48);
      puVar9 = puVar9 + iVar6;
      *(int *)(param_1 + 0xca54) = *(int *)(param_1 + 0xca54) + 1;
      *(int *)(param_1 + 0xca54) = *(int *)(param_1 + 0xca54) + 1;
      if (*(uint *)(param_1 + 0xcdf4) < *(uint *)(param_1 + 0xca54)) {
        if (*(int *)(param_1 + 0xc96c) == 0) {
          iVar2 = -iVar6;
          if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
            return 0;
          }
          *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
          uVar8 = 0;
          iVar6 = *(int *)(param_1 + 0xc998);
          iVar3 = *(int *)(param_1 + 0xc940);
          puVar10 = puVar9 + iVar2;
          while (iVar3 != 0) {
            do {
              iVar4 = iVar3;
              if (iVar4 == 1) {
                uVar5 = *puVar10;
                goto LAB_1000de39;
              }
              if (iVar4 + -2 == 0) {
                uVar5 = *puVar10;
                goto LAB_1000de41;
              }
              puVar10 = puVar10 + 1;
              bVar12 = CARRY4(uVar8,uVar7);
              uVar8 = uVar8 + uVar7;
              iVar3 = iVar4 + -2;
            } while (bVar12);
            iVar3 = iVar4 + -3;
          }
          do {
            do {
              uVar5 = *puVar10;
              *puVar11 = uVar5;
              puVar11 = puVar11 + 1;
              iVar6 = iVar6 + -1;
              if (iVar6 == 0) goto LAB_1000de50;
LAB_1000de39:
              *puVar11 = uVar5;
              puVar11 = puVar11 + 1;
              iVar6 = iVar6 + -1;
              if (iVar6 == 0) goto LAB_1000de50;
LAB_1000de41:
              puVar10 = puVar10 + 1;
              bVar12 = CARRY4(uVar8,uVar7);
              uVar8 = uVar8 + uVar7;
            } while (bVar12);
            *puVar11 = uVar5;
            puVar11 = puVar11 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
LAB_1000de50:
          iVar6 = *(int *)(param_1 + 0xcb48);
          puVar9 = puVar9 + iVar2 + iVar6;
        }
        else {
          if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
            return 0;
          }
          *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
          iVar6 = *(int *)(param_1 + 0xc998);
          puVar11 = puVar11 + -iVar6;
          iVar2 = iVar6;
          do {
            puVar11[iVar6] = *puVar11;
            puVar11 = puVar11 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          puVar11 = puVar11 + iVar6;
          iVar6 = 0;
        }
      }
      puVar1 = (uint *)(param_1 + 0xccd0);
      uVar8 = *puVar1;
      *puVar1 = *puVar1 + uVar7;
    } while ((CARRY4(uVar8,uVar7)) ||
            (*(int *)(param_1 + 0xca54) = *(int *)(param_1 + 0xca54) + 1,
            *(uint *)(param_1 + 0xca54) <= *(uint *)(param_1 + 0xcdf4)));
    if (*(int *)(param_1 + 0xc96c) == 0) {
      if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
        return 0;
      }
      *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
      uVar8 = 0;
      iVar2 = *(int *)(param_1 + 0xc998);
      iVar3 = *(int *)(param_1 + 0xc940);
      puVar10 = puVar9 + -iVar6;
      while (iVar3 != 0) {
        do {
          iVar4 = iVar3;
          if (iVar4 == 1) {
            uVar5 = *puVar10;
            goto LAB_1000df19;
          }
          if (iVar4 + -2 == 0) {
            uVar5 = *puVar10;
            goto LAB_1000df21;
          }
          puVar10 = puVar10 + 1;
          bVar12 = CARRY4(uVar8,uVar7);
          uVar8 = uVar8 + uVar7;
          iVar3 = iVar4 + -2;
        } while (bVar12);
        iVar3 = iVar4 + -3;
      }
      do {
        do {
          uVar5 = *puVar10;
          *puVar11 = uVar5;
          puVar11 = puVar11 + 1;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) goto LAB_1000df30;
LAB_1000df19:
          *puVar11 = uVar5;
          puVar11 = puVar11 + 1;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) goto LAB_1000df30;
LAB_1000df21:
          puVar10 = puVar10 + 1;
          bVar12 = CARRY4(uVar8,uVar7);
          uVar8 = uVar8 + uVar7;
        } while (bVar12);
        *puVar11 = uVar5;
        puVar11 = puVar11 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
LAB_1000df30:
      puVar9 = puVar9 + -iVar6 + *(int *)(param_1 + 0xcb48);
      goto LAB_1000dd00;
    }
    if (*(uint *)(param_1 + 0xc994) <= *(uint *)(param_1 + 0xc96c)) {
      return 0;
    }
    *(int *)(param_1 + 0xc96c) = *(int *)(param_1 + 0xc96c) + 1;
    iVar6 = *(int *)(param_1 + 0xc998);
    puVar11 = puVar11 + -iVar6;
    iVar2 = iVar6;
    do {
      puVar11[iVar6] = *puVar11;
      puVar11 = puVar11 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar11 = puVar11 + iVar6;
  } while( true );
}




======================================================================
// Function: Render_MipmapChain @ 1000df50
======================================================================

undefined4 Render_MipmapChain(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  longlong lVar6;
  
  iVar5 = param_1[0x3308];
  param_1[0x33d8] = param_1[0x3306];
  while( true ) {
    param_1[0x33d9] = iVar5;
    lVar6 = __ftol();
    iVar5 = (int)lVar6;
    param_1[0x3316] = iVar5;
    lVar6 = __ftol();
    param_1[0x3317] = (int)lVar6;
    if ((iVar5 < 0x301) && ((int)lVar6 < 0x301)) break;
    (**(code **)(*param_1 + 0xc4))(param_1);
    param_1[0x33d8] = param_1[0x33d8] << 1;
    iVar5 = param_1[0x33d9] << 1;
  }
  param_1[0x32d2] = param_1[0x3225];
  param_1[0x32d1] = param_1[0x3224];
  param_1[0x3205] = param_1[0x31fc];
  param_1[0x3392] = iVar5;
  param_1[0x33fc] = param_1[0x33d8];
  (**(code **)(*param_1 + 100))(param_1);
  param_1[0x3225] = param_1[0x33fc];
  param_1[0x3392] = param_1[0x3317];
  param_1[0x33fc] = param_1[0x33d9];
  (**(code **)(*param_1 + 100))(param_1);
  param_1[0x3224] = param_1[0x33fc];
  (**(code **)(*param_1 + 0x18c))(param_1);
  iVar5 = param_1[0x3225];
  param_1[0x3225] = iVar5 + param_1[0x31fa];
  pvVar4 = _malloc((iVar5 + param_1[0x31fa]) * param_1[0x3224] * 4);
  param_1[0x32ab] = (int)pvVar4;
  if (pvVar4 == (void *)0x0) {
    param_1[0x3274] = 1;
    return 0;
  }
  param_1[0x31fc] = (int)pvVar4;
  param_1[0x32c2] = (int)pvVar4;
  (**(code **)(*param_1 + 0x1b8))(param_1);
  param_1[0x3205] = param_1[0x32c2];
  if ((LPVOID)param_1[0x32aa] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x32aa]);
    param_1[0x32aa] = 0;
  }
  param_1[0x32aa] = param_1[0x32ab];
  iVar5 = param_1[0x32b0];
  if (iVar5 < param_1[0x3224]) {
    param_1[0x3224] = iVar5;
  }
  if (param_1[0x3229] == 8) {
    param_1[0x32c3] = 1;
  }
  iVar1 = param_1[0x3224];
  iVar2 = param_1[0x32af];
  iVar3 = param_1[0x3225];
  if (param_1[0x32c3] == 1 && (iVar5 != iVar1 || iVar2 != iVar3)) {
    param_1[0x3266] = iVar3;
    param_1[0x3265] = iVar1;
    param_1[0x3267] = iVar3 * 4;
    if (iVar3 < iVar2) {
      param_1[0x3225] = iVar2;
    }
    if (iVar1 < iVar5) {
      param_1[0x3224] = iVar5;
    }
    if (param_1[0x3225] < param_1[0x3266]) {
      param_1[0x3225] = param_1[0x3266];
    }
    param_1[0x3226] = param_1[0x3225] << 2;
    (**(code **)(*param_1 + 0x18c))(param_1);
    iVar5 = param_1[0x3225] + param_1[0x31fa];
    param_1[0x3225] = iVar5;
    param_1[0x3226] = iVar5 * 4;
    pvVar4 = _malloc(iVar5 * param_1[0x3224] * 4);
    param_1[0x32ab] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      param_1[0x3274] = 1;
      return 0;
    }
    param_1[0x31fc] = (int)pvVar4;
    param_1[0x3410] = param_1[0x3225] * param_1[0x3224];
    param_1[0x3202] = (int)pvVar4;
    param_1[0x3416] = 0;
    if (0 < param_1[0x3225] * param_1[0x3224]) {
      do {
        *(int *)param_1[0x3202] = param_1[0x3322];
        iVar5 = param_1[0x3416];
        param_1[0x3202] = param_1[0x3202] + 4;
        param_1[0x3416] = iVar5 + 1;
      } while (iVar5 + 1 < param_1[0x3410]);
    }
    param_1[0x320f] = param_1[0x3205];
    param_1[0x3202] = param_1[0x31fc];
    param_1[0x3416] = 0;
    if (0 < param_1[0x3265]) {
      do {
        param_1[0x3287] = 0;
        if (0 < param_1[0x3266]) {
          do {
            *(undefined4 *)param_1[0x3202] = *(undefined4 *)param_1[0x320f];
            iVar5 = param_1[0x3287];
            param_1[0x3202] = param_1[0x3202] + 4;
            param_1[0x320f] = param_1[0x320f] + 4;
            param_1[0x3287] = iVar5 + 1;
          } while (iVar5 + 1 < param_1[0x3266]);
        }
        iVar5 = param_1[0x3416];
        param_1[0x3202] = param_1[0x3202] + (param_1[0x3225] - param_1[0x3266]) * 4;
        param_1[0x3416] = iVar5 + 1;
      } while (iVar5 + 1 < param_1[0x3265]);
    }
    param_1[0x3205] = param_1[0x32c2];
    if ((LPVOID)param_1[0x32aa] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x32aa]);
      param_1[0x32aa] = 0;
    }
    iVar5 = param_1[0x32ab];
    param_1[0x32ab] = 0;
    param_1[0x32aa] = iVar5;
  }
  return 0;
}




======================================================================
// Function: FUN_1000e360 @ 1000e360
======================================================================

undefined4 FUN_1000e360(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  *(undefined4 *)(param_1 + 0xc814) = *(undefined4 *)(param_1 + 0xc7f0);
  iVar2 = *(int *)(param_1 + 0xc894);
  *(int *)(param_1 + 0xc998) = iVar2;
  *(int *)(param_1 + 0xc994) = *(int *)(param_1 + 0xc890);
  *(int *)(param_1 + 0xc99c) = iVar2 * 4;
  iVar2 = iVar2 + *(int *)(param_1 + 0xc7e8);
  *(int *)(param_1 + 0xc894) = iVar2;
  *(int *)(param_1 + 0xc898) = iVar2 * 4;
  pvVar3 = _malloc(iVar2 * *(int *)(param_1 + 0xc890) * 4);
  *(void **)(param_1 + 0xcaac) = pvVar3;
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0xc9d0) = 1;
    return 0;
  }
  *(void **)(param_1 + 0xc7f0) = pvVar3;
  puVar6 = *(undefined4 **)(param_1 + 0xc7f0);
  puVar5 = *(undefined4 **)(param_1 + 0xc814);
  iVar2 = *(int *)(param_1 + 0xc998);
  iVar4 = *(int *)(param_1 + 0xc994);
  do {
    do {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = *(int *)(param_1 + 0xc7e8);
    uVar1 = *(undefined4 *)(param_1 + 0xcc88);
    do {
      *puVar6 = uVar1;
      puVar6 = puVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = *(int *)(param_1 + 0xc998);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (*(LPVOID *)(param_1 + 0xcaa8) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(param_1 + 0xcaa8));
    *(undefined4 *)(param_1 + 0xcaa8) = 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0xcaac);
  *(undefined4 *)(param_1 + 0xcaac) = 0;
  *(undefined4 *)(param_1 + 0xcaa8) = uVar1;
  return 0;
}




======================================================================
// Function: FUN_1000e460 @ 1000e460
======================================================================

undefined4 FUN_1000e460(int param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar3 = *(int *)(param_1 + 0xc894);
  *(undefined4 *)(param_1 + 0xc814) = *(undefined4 *)(param_1 + 0xc7f0);
  *(int *)(param_1 + 0xc994) = *(int *)(param_1 + 0xc890);
  *(int *)(param_1 + 0xc998) = iVar3;
  *(int *)(param_1 + 0xc99c) = iVar3 * 4;
  pvVar2 = _malloc(*(int *)(param_1 + 0xc890) * iVar3 * 0x10);
  *(void **)(param_1 + 0xcaac) = pvVar2;
  if (pvVar2 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0xc9d0) = 1;
    return 0;
  }
  *(void **)(param_1 + 0xc7f0) = pvVar2;
  puVar6 = *(undefined4 **)(param_1 + 0xc7f0);
  puVar5 = *(undefined4 **)(param_1 + 0xc814);
  iVar3 = *(int *)(param_1 + 0xc998);
  iVar4 = *(int *)(param_1 + 0xc994);
  do {
    do {
      uVar1 = *puVar5;
      *puVar6 = uVar1;
      puVar6[1] = uVar1;
      puVar6 = puVar6 + 2;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = *(int *)(param_1 + 0xc998);
    puVar5 = (undefined4 *)((int)puVar5 - *(int *)(param_1 + 0xc99c));
    do {
      uVar1 = *puVar5;
      *puVar6 = uVar1;
      puVar6[1] = uVar1;
      puVar6 = puVar6 + 2;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = *(int *)(param_1 + 0xc998);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (*(LPVOID *)(param_1 + 0xcaa8) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(param_1 + 0xcaa8));
    *(undefined4 *)(param_1 + 0xcaa8) = 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0xcaac);
  *(undefined4 *)(param_1 + 0xcaac) = 0;
  *(int *)(param_1 + 0xc894) = *(int *)(param_1 + 0xc894) << 1;
  *(int *)(param_1 + 0xc890) = *(int *)(param_1 + 0xc890) << 1;
  *(undefined4 *)(param_1 + 0xcaa8) = uVar1;
  return 0;
}




======================================================================
// Function: FUN_1000e570 @ 1000e570
======================================================================

undefined4 FUN_1000e570(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0xcc18) != 0x15e || *(int *)(param_1 + 0xcc20) != 0x140) {
    if (*(LPVOID *)(param_1 + 0xcaa4) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)(param_1 + 0xcaa4));
    }
    *(undefined4 *)(param_1 + 0xcc18) = 0x15e;
    *(undefined4 *)(param_1 + 0xcc20) = 0x140;
    pvVar1 = _malloc(0x6d600);
    *(void **)(param_1 + 0xcaa4) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0xc9d0) = 1;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1000e5f0 @ 1000e5f0
======================================================================

undefined4 FUN_1000e5f0(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0xcc18) != 0xb4 || *(int *)(param_1 + 0xcc20) != 0x78) {
    if (*(LPVOID *)(param_1 + 0xcaa4) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)(param_1 + 0xcaa4));
    }
    *(undefined4 *)(param_1 + 0xcc18) = 0xb4;
    *(undefined4 *)(param_1 + 0xcc20) = 0x78;
    pvVar1 = _malloc(0x15180);
    *(void **)(param_1 + 0xcaa4) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0xc9d0) = 1;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1000e670 @ 1000e670
======================================================================

undefined4 FUN_1000e670(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0xcc18) != 0x160 || *(int *)(param_1 + 0xcc20) != 0x140) {
    if (*(LPVOID *)(param_1 + 0xcaa4) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)(param_1 + 0xcaa4));
    }
    *(undefined4 *)(param_1 + 0xcc18) = 0x160;
    *(undefined4 *)(param_1 + 0xcc20) = 0x140;
    pvVar1 = _malloc(0x6e000);
    *(void **)(param_1 + 0xcaa4) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0xc9d0) = 1;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1000e6f0 @ 1000e6f0
======================================================================

undefined4 FUN_1000e6f0(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0xcc18) != 400 || *(int *)(param_1 + 0xcc20) != 300) {
    if (*(LPVOID *)(param_1 + 0xcaa4) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)(param_1 + 0xcaa4));
    }
    *(undefined4 *)(param_1 + 0xcc18) = 400;
    *(undefined4 *)(param_1 + 0xcc20) = 300;
    pvVar1 = _malloc(480000);
    *(void **)(param_1 + 0xcaa4) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0xc9d0) = 1;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1000e770 @ 1000e770
======================================================================

undefined4 FUN_1000e770(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0xcc18) != *(int *)(param_1 + 0xcabc) ||
      *(int *)(param_1 + 0xcc20) != *(int *)(param_1 + 0xcac0)) {
    if (*(LPVOID *)(param_1 + 0xcaa4) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)(param_1 + 0xcaa4));
    }
    *(int *)(param_1 + 0xcc18) = *(int *)(param_1 + 0xcabc);
    *(int *)(param_1 + 0xcc20) = *(int *)(param_1 + 0xcac0);
    pvVar1 = _malloc(*(int *)(param_1 + 0xcabc) * *(int *)(param_1 + 0xcac0) * 4);
    *(void **)(param_1 + 0xcaa4) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0xc9d0) = 1;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1000e800 @ 1000e800
======================================================================

undefined4 FUN_1000e800(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 500))(param_1);
  if (iVar1 == 0) {
    param_1[0x326b] = 1;
    return 0;
  }
  param_1[0x326b] = 0;
  param_1[param_1[0x3240] * 0x7b + 0xc3f] = 1;
  iVar1 = param_1[0x3240];
  param_1[0x3420] = param_1[iVar1 * 0x7b + 0xc40];
  param_1[0x3425] = param_1[iVar1 * 0x7b + 0xc41];
  if (param_1[0x3420] < 0) {
    param_1[0x3420] = 0;
  }
  if (param_1[0x3425] < 0) {
    param_1[0x3425] = 0;
  }
  param_1[0x3225] = param_1[iVar1 * 0x7b + 0xc45];
  param_1[0x3224] = param_1[iVar1 * 0x7b + 0xc46];
  (**(code **)(*param_1 + 0x1fc))(param_1);
  (**(code **)(*param_1 + 0x1f8))(param_1);
  (**(code **)(*param_1 + 0x34))(param_1);
  return 0;
}




======================================================================
// Function: FUN_1000e8d0 @ 1000e8d0
======================================================================

undefined4 FUN_1000e8d0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x1f0))(param_1);
  if (iVar1 == 0) {
    param_1[0x326a] = 1;
    return 0;
  }
  iVar1 = param_1[0x3240];
  param_1[0x326a] = 0;
  param_1[0x3420] = param_1[iVar1 * 0x7b + 0xc36];
  param_1[0x3425] = param_1[iVar1 * 0x7b + 0xc37];
  if (param_1[0x3420] < 0) {
    param_1[0x3420] = 0;
  }
  if (param_1[0x3425] < 0) {
    param_1[0x3425] = 0;
  }
  param_1[0x3225] = param_1[iVar1 * 0x7b + 0xc3d];
  param_1[0x3224] = param_1[iVar1 * 0x7b + 0xc3e];
  (**(code **)(*param_1 + 0x1f8))(param_1);
  (**(code **)(*param_1 + 0x34))(param_1);
  return 0;
}




======================================================================
// Function: FUN_1000e970 @ 1000e970
======================================================================

undefined4 FUN_1000e970(int *param_1)

{
  int iVar1;
  
LAB_1000e984:
  param_1[0x3240] = 0;
  do {
    iVar1 = param_1[0x3240];
    if ((param_1[iVar1 * 0x7b + 0xc3f] == 2) && (param_1[iVar1 * 0x7b + 0xc31] == 2)) {
      param_1[0x3375] = param_1[iVar1 * 0x7b + 0xc40];
      param_1[0x3377] = param_1[iVar1 * 0x7b + 0xc41];
      param_1[0x3266] = param_1[iVar1 * 0x7b + 0xc45];
      param_1[0x3265] = param_1[iVar1 * 0x7b + 0xc46];
      if (param_1[0x3375] < 0) {
        param_1[0x3375] = 0;
      }
      if (param_1[0x3377] < 0) {
        param_1[0x3377] = 0;
      }
      (**(code **)(*param_1 + 0x38))(param_1);
      if (param_1[0x3288] == 1) {
        param_1[param_1[0x3240] * 0x7b + 0xc3f] = 1;
      }
      if (param_1[0x325e] == 1) break;
    }
    iVar1 = param_1[0x3240];
    param_1[0x3240] = iVar1 + 1U;
    if ((uint)param_1[0x32a1] <= iVar1 + 1U) {
      return 0;
    }
  } while( true );
  (**(code **)(*param_1 + 0xcc))(param_1);
  goto LAB_1000e984;
}




======================================================================
// Function: FUN_1000ea70 @ 1000ea70
======================================================================

undefined4 FUN_1000ea70(int *param_1)

{
  int iVar1;
  int iVar2;
  
LAB_1000ea84:
  param_1[0x3240] = 0;
  do {
    iVar1 = param_1[0x3240];
    if ((1 < param_1[iVar1 * 0x7b + 0xc35]) && (param_1[iVar1 * 0x7b + 0xc31] == 2)) {
      iVar2 = param_1[iVar1 * 0x7b + 0xc36];
      param_1[0x3375] = iVar2;
      param_1[0x3377] = param_1[iVar1 * 0x7b + 0xc37];
      if (iVar2 < 0) {
        param_1[0x3375] = 0;
      }
      if (param_1[0x3377] < 0) {
        param_1[0x3377] = 0;
      }
      param_1[0x3266] = param_1[iVar1 * 0x7b + 0xc3d];
      param_1[0x3265] = param_1[iVar1 * 0x7b + 0xc3e];
      (**(code **)(*param_1 + 0x38))(param_1);
      if (param_1[0x325e] == 1) break;
    }
    iVar1 = param_1[0x3240];
    param_1[0x3240] = iVar1 + 1U;
    if ((uint)param_1[0x32a1] <= iVar1 + 1U) {
      return 0;
    }
  } while( true );
  (**(code **)(*param_1 + 0xcc))(param_1);
  goto LAB_1000ea84;
}




======================================================================
// Function: FUN_1000ec00 @ 1000ec00
======================================================================

undefined4 FUN_1000ec00(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0xc894) & 3;
  if (uVar1 != 0) {
    iVar2 = 4 - uVar1;
    *(int *)(param_1 + 0xc894) = *(int *)(param_1 + 0xc894) + iVar2;
    if (*(uint *)(param_1 + 0xcc18) <
        (uint)(*(int *)(param_1 + 0xd080) + *(int *)(param_1 + 0xc894))) {
      *(int *)(param_1 + 0xd080) = *(int *)(param_1 + 0xd080) - iVar2;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1000ed10 @ 1000ed10
======================================================================

undefined4 FUN_1000ed10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar2 = *(int *)(param_1 + 0xcc18);
  *(undefined4 *)(param_1 + 0xc994) = *(undefined4 *)(param_1 + 0xcc20);
  *(int *)(param_1 + 0xc998) = iVar2;
  *(int *)(param_1 + 0xc94c) = (iVar2 - *(int *)(param_1 + 0xc894)) - *(int *)(param_1 + 0xd080);
  *(undefined4 *)(param_1 + 0xcdd4) = 0;
  *(undefined4 *)(param_1 + 0xcddc) = 0;
  *(int *)(param_1 + 0xc814) =
       *(int *)(param_1 + 0xcaa4) +
       (*(int *)(param_1 + 0xd094) * iVar2 + *(int *)(param_1 + 0xd080)) * 4;
  if (*(int *)(param_1 + 0xc7e0) == 0) {
    iVar2 = *(int *)(param_1 + 0xc890);
    iVar4 = *(int *)(param_1 + 0xc814);
    puVar6 = *(undefined4 **)(param_1 + 0xc7f0);
    do {
      iVar3 = 0;
      iVar1 = *(int *)(param_1 + 0xc894);
      do {
        *puVar6 = *(undefined4 *)(iVar4 + iVar3);
        iVar3 = iVar3 + 4;
        puVar6 = puVar6 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      iVar4 = iVar4 + *(int *)(param_1 + 0xcc1c);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0xc890);
  iVar4 = *(int *)(param_1 + 0xc814);
  puVar6 = *(undefined4 **)(param_1 + 0xc7f0);
  do {
    iVar1 = *(int *)(param_1 + 0xc894);
    *puVar6 = 0xffffff;
    iVar3 = 4;
    puVar6 = puVar6 + 1;
    iVar1 = iVar1 + -1;
    if (iVar1 != 0) {
      do {
        puVar5 = puVar6;
        *puVar5 = *(undefined4 *)(iVar4 + iVar3);
        iVar3 = iVar3 + 4;
        puVar6 = puVar5 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      *puVar5 = 0xffffff;
    }
    iVar4 = iVar4 + *(int *)(param_1 + 0xcc1c);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}




======================================================================
// Function: FUN_1000ee10 @ 1000ee10
======================================================================

void FUN_1000ee10(int param_1,WPARAM param_2,int *param_3)

{
  ushort uVar1;
  
  if (((param_1 == 0) && (DAT_10025028 != (int *)0x0)) && (*param_3 == 0x2e)) {
    uVar1 = GetAsyncKeyState(0x12);
    if ((uVar1 & 0x8000) != 0) {
      uVar1 = GetAsyncKeyState(0x11);
      if ((uVar1 & 0x8000) != 0) {
        Wnd_Destroy(DAT_10025028);
      }
    }
  }
  CallNextHookEx(DAT_10025024,param_1,param_2,(LPARAM)param_3);
  return;
}




======================================================================
// Function: InitWindowState @ 1000ee70
======================================================================

void __fastcall InitWindowState(int param_1)

{
  code *pcVar1;
  
  pcVar1 = DefWindowProcA_exref;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(code **)(param_1 + 0x68) = pcVar1;
  *(int *)(param_1 + 0x6c) = param_1;
  *(undefined4 *)(param_1 + 0x70) = 1;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0x280;
  *(undefined4 *)(param_1 + 0x7c) = 0x1e0;
  return;
}




======================================================================
// Function: Cleanup_WindowState @ 1000eed0
======================================================================

void __fastcall Cleanup_WindowState(int param_1)

{
  CleanupVizInstance(param_1);
  return;
}




======================================================================
// Function: Wnd_Destroy @ 1000eee0
======================================================================

void __fastcall Wnd_Destroy(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x11];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x4c))(piVar1);
  }
  (**(code **)(*param_1 + 0x10))(param_1);
  return;
}




======================================================================
// Function: Misc_HideCursor @ 1000f3e0
======================================================================

undefined4 Misc_HideCursor(void)

{
  SetCursor((HCURSOR)0x0);
  return 1;
}




======================================================================
// Function: WndProc_Viz @ 1000f3f0
======================================================================

undefined4 __thiscall WndProc_Viz(void *this,undefined4 param_1,undefined4 *param_2)

{
  DWORD DVar1;
  bool bVar2;
  
  if (param_2 == (undefined4 *)0x1b) {
    PostMessageA(*(HWND *)((int)this + 0x14),0x10,0,0);
  }
  else if ((param_2 == (undefined4 *)0x70) &&
          (bVar2 = *(char *)((int)this + 0x8c) == '\0', *(bool *)((int)this + 0x8c) = bVar2, bVar2))
  {
    *(undefined4 *)((int)this + 0x80) = 0;
    DVar1 = timeGetTime();
    *(DWORD *)((int)this + 0x84) = DVar1;
    *(undefined4 *)((int)this + 0x88) = 0;
  }
  (**(code **)(*(int *)this + 8))(this,param_2);
  *param_2 = 0;
  return 0;
}




======================================================================
// Function: PostCloseMessage @ 1000f470
======================================================================

undefined4 __thiscall PostCloseMessage(void *this)

{
  undefined4 *in_stack_00000010;
  
  PostMessageA(*(HWND *)((int)this + 0x14),0x10,0,0);
  *in_stack_00000010 = 0;
  return 0;
}




======================================================================
// Function: DestroyVizWindow @ 1000f490
======================================================================

undefined4 __thiscall DestroyVizWindow(void *this)

{
  int *piVar1;
  undefined4 *in_stack_00000010;
  
  if (*(HMODULE *)((int)this + 0x40) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)((int)this + 0x40));
    *(undefined4 *)((int)this + 0x40) = 0;
  }
  piVar1 = *(int **)((int)this + 0x44);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x4c))(piVar1);
  }
  piVar1 = *(int **)((int)this + 0x4c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)((int)this + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)((int)this + 0x44);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *in_stack_00000010 = 0;
  return 0;
}




======================================================================
// Function: CleanupVizInstance @ 1000f500
======================================================================

undefined4 CleanupVizInstance(int param_1)

{
  int *piVar1;
  code *pcVar2;
  LONG LVar3;
  
  if (*(HMODULE *)(param_1 + 0x40) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x44);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x4c))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x4c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x44);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  if (DAT_10025028 == param_1) {
    DAT_10025028 = 0;
    if (DAT_10025024 != (HHOOK)0x0) {
      UnhookWindowsHookEx(DAT_10025024);
      DAT_10025024 = (HHOOK)0x0;
    }
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    if (*(HWND *)(param_1 + 0x50) != (HWND)0x0) {
      LVar3 = GetWindowLongA(*(HWND *)(param_1 + 0x50),-4);
      if (param_1 + 0x54 == LVar3) {
        LVar3 = SetWindowLongA(*(HWND *)(param_1 + 0x50),-4,*(LONG *)(param_1 + 0x68));
        pcVar2 = DefWindowProcA_exref;
        if (LVar3 != 0) {
          *(undefined4 *)(param_1 + 0x50) = 0;
          *(code **)(param_1 + 0x68) = pcVar2;
        }
      }
    }
    DestroyWindow(*(HWND *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return 0;
}




======================================================================
// Function: FreeVisTextures @ 1000f740
======================================================================

undefined4 FreeVisTextures(int param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0xca18) = 0;
  if (-1 < *(int *)(param_1 + 0xd038)) {
    do {
      if ((*(int *)(param_1 + 0x30c8 + *(int *)(param_1 + 0xca18) * 0x1ec) == -1) &&
         (pvVar1 = *(LPVOID *)(param_1 + *(int *)(param_1 + 0xca18) * 0x1ec + 0x30ec),
         pvVar1 != (LPVOID)0x0)) {
        Mem_Free(pvVar1);
        *(undefined4 *)(param_1 + 0x30ec + *(int *)(param_1 + 0xca18) * 0x1ec) = 0;
      }
      *(undefined4 *)(param_1 + 0x317c + *(int *)(param_1 + 0xca18) * 0x1ec) = 0;
      pvVar1 = *(LPVOID *)(param_1 + 0x3184 + *(int *)(param_1 + 0xca18) * 0x1ec);
      if (pvVar1 != (LPVOID)0x0) {
        Mem_Free(pvVar1);
        *(undefined4 *)(param_1 + 0x3184 + *(int *)(param_1 + 0xca18) * 0x1ec) = 0;
      }
      pvVar1 = *(LPVOID *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec);
      if (pvVar1 != (LPVOID)0x0) {
        Mem_Free(pvVar1);
        *(undefined4 *)(param_1 + 0x3180 + *(int *)(param_1 + 0xca18) * 0x1ec) = 0;
      }
      pvVar1 = *(LPVOID *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec);
      if (pvVar1 != (LPVOID)0x0) {
        Mem_Free(pvVar1);
        *(undefined4 *)(param_1 + 0x3264 + *(int *)(param_1 + 0xca18) * 0x1ec) = 0;
      }
      iVar2 = *(int *)(param_1 + 0xca18) + 1;
      *(int *)(param_1 + 0xca18) = iVar2;
    } while (iVar2 <= *(int *)(param_1 + 0xd038));
  }
  return 0;
}




======================================================================
// Function: FreeAllBuffers @ 1000f890
======================================================================

undefined4 FreeAllBuffers(int *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  if (param_1[0x326d] != 0) {
    param_1[0x326d] = 0;
    param_1[0x3271] = 0;
    if ((LPVOID)param_1[0x32a9] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x32a9]);
      param_1[0x32a9] = 0;
    }
    if ((LPVOID)param_1[0x32aa] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x32aa]);
      param_1[0x32aa] = 0;
    }
    if ((LPVOID)param_1[0x3207] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x3207]);
      param_1[0x3207] = 0;
    }
    if ((LPVOID)param_1[0x32ad] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x32ad]);
      param_1[0x32ad] = 0;
    }
    if ((LPVOID)param_1[0x32ae] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x32ae]);
      param_1[0x32ae] = 0;
    }
    if ((LPVOID)param_1[0x3395] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x3395]);
      param_1[0x3395] = 0;
    }
    if ((LPVOID)param_1[0x333d] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x333d]);
      param_1[0x333d] = 0;
    }
    if ((LPVOID)param_1[0x334e] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x334e]);
      param_1[0x334e] = 0;
    }
    if ((LPVOID)param_1[0x3354] != (LPVOID)0x0) {
      Mem_Free((LPVOID)param_1[0x3354]);
      param_1[0x3354] = 0;
    }
    (**(code **)(*param_1 + 0xf4))(param_1);
    param_1[0x3298] = 0;
    do {
      pvVar1 = (LPVOID)param_1[param_1[0x3298] + 0x31ea];
      param_1[0x320b] = (int)pvVar1;
      if (pvVar1 != (LPVOID)0x0) {
        Mem_Free(pvVar1);
        param_1[param_1[0x3298] + 0x31ea] = 0;
      }
      iVar2 = param_1[0x3298];
      param_1[0x3298] = iVar2 + 1U;
    } while (iVar2 + 1U <= (uint)param_1[0x32a3]);
  }
  return 0;
}




======================================================================
// Function: InitStateDefaults @ 1000f9f0
======================================================================

int __fastcall InitStateDefaults(int param_1)

{
  *(undefined4 *)(param_1 + 0x98) = 0;
  InitWindowState(param_1 + 4);
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xc864) = 0;
  *(undefined4 *)(param_1 + 0xc9b4) = 0;
  *(undefined4 *)(param_1 + 0xca6c) = 0;
  *(undefined4 *)(param_1 + 0xcaa0) = 0;
  *(undefined4 *)(param_1 + 0xcb04) = 0;
  *(undefined4 *)(param_1 + 0xcbd8) = 0;
  *(undefined4 *)(param_1 + 0xcbdc) = 0;
  *(undefined4 *)(param_1 + 0xd024) = 0;
  *(undefined4 *)(param_1 + 0xd028) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0xff;
  *(undefined4 *)(param_1 + 0xc9e4) = 1;
  return param_1;
}




======================================================================
// Function: Destructor_VisObject @ 1000fa60
======================================================================

void __fastcall Destructor_VisObject(void *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_100207e8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  (**(code **)(*(int *)((int)param_1 + -4) + 0xf0))((int)param_1 + -4);
  puStack_8 = (undefined1 *)0xffffffff;
  Cleanup_WindowState(-(uint)(param_1 != (void *)0x4) & (uint)param_1);
  ExceptionList = param_1;
  return;
}




======================================================================
// Function: Shutdown_Stub @ 1000fac0
======================================================================

undefined4 Shutdown_Stub(void)

{
  return 0;
}




======================================================================
// Function: Init_RenderContext @ 1000fad0
======================================================================

void Init_RenderContext(void)

{
  return;
}




======================================================================
// Function: Texture_InitRender @ 1000fae0
======================================================================

undefined4 Texture_InitRender(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  DWORD DVar2;
  HWND pHVar3;
  
  if (*(int *)(param_1 + 0xcba0) != 0x1e) {
    *(undefined4 *)(param_1 + 0xc93c) = 0;
    *(undefined4 *)(param_1 + 0xc9d4) = param_3;
    if (*(int *)(param_1 + 0xc920) == 0) {
      piVar1 = (int *)(param_1 + -0x94);
      (**(code **)(*(int *)(param_1 + -0x94) + 0x1b0))(piVar1);
      *(undefined4 *)(param_1 + 0xc920) = 1;
      *(undefined4 *)(param_1 + 0xcb84) = 0x15e;
      *(undefined4 *)(param_1 + 0xcb8c) = 0x140;
      *(undefined4 *)(param_1 + 0xca28) = 0x15e;
      *(undefined4 *)(param_1 + 0xca2c) = 0x140;
      *(undefined4 *)(param_1 + 0xcbc4) = 0x100;
      *(undefined4 *)(param_1 + 0xcbc8) = 0x100;
      *(float *)(param_1 + 0xc834) = (float)(*(int *)(param_1 + 0xcb84) / 2);
      DVar2 = FUN_1001a169((int *)0x0);
      FUN_1001a13a(DVar2);
      *(undefined4 *)(param_1 + 0xc9cc) = 9;
      (**(code **)(*piVar1 + 0x164))(piVar1);
      (**(code **)(*piVar1 + 0x168))(piVar1);
      (**(code **)(*piVar1 + 0x178))(piVar1);
      (**(code **)(*piVar1 + 0x16c))(piVar1);
      pHVar3 = GetForegroundWindow();
      *(HWND *)(param_1 + 0xc980) = pHVar3;
      if (pHVar3 == (HWND)0x0) {
        pHVar3 = GetDesktopWindow();
        *(HWND *)(param_1 + 0xc980) = pHVar3;
      }
    }
    piVar1 = (int *)(param_1 + -0x94);
    *(undefined4 *)(param_1 + 0xc9cc) = 9;
    (**(code **)(*piVar1 + 0x164))(piVar1);
    if (*(int *)(param_1 + 0xc93c) == 1) {
      *(undefined4 *)(param_1 + 0xc920) = 0;
      return 0;
    }
    *(undefined4 *)(param_1 + 0xcbf4) = 0;
    *(int *)(param_1 + 0xcbcc) = *param_4;
    *(int *)(param_1 + 0xcbd0) = param_4[1];
    if (*(int *)(param_1 + 0xca28) == param_4[2] - *param_4 &&
        *(int *)(param_1 + 0xca2c) == param_4[3] - param_4[1]) {
      *(undefined4 *)(param_1 + 0xca78) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0xca78) = 1;
      *(undefined4 *)(param_1 + 0xcb50) = 0;
      *(int *)(param_1 + 0xca2c) = param_4[3] - param_4[1];
      *(int *)(param_1 + 0xca28) = param_4[2] - *param_4;
    }
    if (*(int *)(param_1 + 0xcb50) < 0x10) {
      *(int *)(param_1 + 0xcb50) = *(int *)(param_1 + 0xcb50) + 1;
    }
    else {
      *(undefined4 *)(param_1 + 0xcb50) = 0;
      *(undefined4 *)(param_1 + 0xca78) = 1;
    }
    (**(code **)(*piVar1 + 0x288))(piVar1,param_2);
  }
  return 0;
}




======================================================================
// Function: Init_GDIContext @ 100103f0
======================================================================

undefined4 Init_GDIContext(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + -0x7c) == 0) {
    iVar1 = GetDeviceCaps(*(HDC *)(param_1 + 0xc9d4),0xc);
    *(int *)(param_1 + 0xc810) = iVar1;
    return 0x80004005;
  }
  *(undefined4 *)(param_1 + 0xca2c) = *(undefined4 *)(param_1 + -0x14);
  *(undefined4 *)(param_1 + 0xca28) = *(undefined4 *)(param_1 + -0x18);
  if (*(int *)(param_1 + -0x84) < 2) {
    *(int *)(param_1 + -0x84) = *(int *)(param_1 + -0x84) + 1;
    *(undefined4 *)(param_1 + 0xca78) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0xca78) = 0;
  }
  (**(code **)(*(int *)(param_1 + -0x94) + 0x288))(param_1 + -0x94,param_2);
  return 0;
}




======================================================================
// Function: Load_DisplayName @ 10010480
======================================================================

undefined4 Load_DisplayName(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  CHAR local_204 [512];
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  iVar1 = LoadStringA(*(HINSTANCE *)(DAT_10025020 + 8),0x65,local_204,0x200);
  Ordinal_6();
  if (iVar1 != 0) {
    if (&stack0x00000000 == (undefined1 *)0x204) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      puVar2 = &stack0xfffffdec;
      iVar1 = lstrlenA(local_204);
      FUN_1001a250();
      MultiByteToWideChar(0,0,local_204,-1,(LPWSTR)&stack0xfffffdec,iVar1 + 1);
    }
    iVar1 = Ordinal_2(puVar2);
    if (iVar1 != 0) {
      *param_2 = iVar1;
      Ordinal_6(0);
      return 0;
    }
  }
  Ordinal_6(0);
  return 0x80004005;
}




======================================================================
// Function: ParseHexDWord @ 10010710
======================================================================

undefined4 ParseHexDWord(LPCWSTR param_1,uint *param_2)

{
  WCHAR WVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == (LPCWSTR)0x0) {
    return 0x80004003;
  }
  iVar2 = lstrlenW(param_1);
  if (iVar2 == 0) {
    return 0x80070057;
  }
  if (param_2 == (uint *)0x0) {
    return 0x80004003;
  }
  iVar2 = lstrlenW(param_1);
  if (iVar2 != 7) {
    return 0x80070057;
  }
  uVar3 = 0;
  iVar2 = 1;
  do {
    param_1 = param_1 + 1;
    WVar1 = *param_1;
    iVar4 = uVar3 * 0x10;
    if (((ushort)WVar1 < 0x30) || (0x39 < (ushort)WVar1)) {
      if (((ushort)WVar1 < 0x41) || (0x46 < (ushort)WVar1)) {
        if (((ushort)WVar1 < 0x61) || (0x66 < (ushort)WVar1)) {
          return 0x80070057;
        }
        uVar3 = iVar4 + -0x57 + (uint)(ushort)WVar1;
      }
      else {
        uVar3 = iVar4 + -0x37 + (uint)(ushort)WVar1;
      }
    }
    else {
      uVar3 = iVar4 + -0x30 + (uint)(ushort)WVar1;
    }
    iVar2 = iVar2 + 1;
    if (6 < iVar2) {
      *param_2 = uVar3 >> 0x10 & 0xff | (uVar3 & 0xff) << 0x10 | uVar3 & 0xff00;
      return 0;
    }
  } while( true );
}




======================================================================
// Function: FormatHexDWord @ 10010800
======================================================================

undefined4 FormatHexDWord(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  WCHAR local_10 [8];
  
  *param_1 = 0;
  wsprintfW(local_10,u___06X_10024124,
            param_2 >> 0x10 & 0xff | (param_2 & 0xff) << 0x10 | param_2 & 0xff00);
  uVar1 = Ordinal_2(local_10);
  *param_1 = uVar1;
  uVar1 = 0x80004005;
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = 0;
  }
  return uVar1;
}




======================================================================
// Function: FUN_100108a0 @ 100108a0
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_100108a0(HMODULE param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  int *piVar7;
  uint uVar8;
  
  if (param_2 == 1) {
    _DAT_100250b0 = &DAT_10024098;
    DAT_10025020 = &DAT_10025040;
    DAT_10025040 = 0x84;
    _DAT_100250a4 = 0x300;
    DAT_10025050 = &PTR_DAT_10024130;
    DAT_10025048 = param_1;
    _DAT_1002504c = param_1;
    DAT_10025044 = param_1;
    DAT_10025054 = 0;
    DAT_10025058 = (HANDLE)0x0;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1002505c);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_10025074);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1002508c);
    _DAT_100250a8 = 0;
    DAT_100250ac = 1;
    DAT_100250b4 = 0;
    _DAT_100250bc = 0;
    DAT_100250b8 = 0;
    DAT_100250c0 = (undefined4 *)0x0;
    if (DAT_10025050 != (undefined **)0x0) {
      puVar1 = *DAT_10025050;
      ppuVar6 = DAT_10025050;
      while (puVar1 != (undefined *)0x0) {
        (*(code *)ppuVar6[8])(1);
        if (DAT_10025040 == 100) {
          ppuVar6 = ppuVar6 + 7;
        }
        else {
          ppuVar6 = ppuVar6 + 9;
        }
        puVar1 = *ppuVar6;
      }
    }
    _DAT_10025030 = DAT_10021418;
    _DAT_10025034 = DAT_1002141c;
    _DAT_10025038 = DAT_10021420;
    _DAT_1002503c = DAT_10021424;
    DisableThreadLibraryCalls(param_1);
    return 1;
  }
  if (param_2 == 0) {
    if (DAT_10025050 != (undefined **)0x0) {
      iVar2 = (int)*DAT_10025050;
      piVar7 = (int *)DAT_10025050;
      while (iVar2 != 0) {
        piVar3 = (int *)piVar7[4];
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 8))(piVar3);
        }
        piVar7[4] = 0;
        (*(code *)piVar7[8])(0);
        if (DAT_10025040 == 100) {
          piVar7 = piVar7 + 7;
        }
        else {
          piVar7 = piVar7 + 9;
        }
        iVar2 = *piVar7;
      }
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1002505c);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_10025074);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1002508c);
    puVar5 = DAT_100250c0;
    while (puVar5 != (undefined4 *)0x0) {
      (*(code *)*puVar5)(puVar5[1]);
      puVar4 = (undefined4 *)puVar5[2];
      Mem_FreeObj(puVar5);
      puVar5 = puVar4;
    }
    if ((DAT_10025058 != (HANDLE)0x0) && (DAT_100250ac != '\0')) {
      if (DAT_100250b8 != 0) {
        uVar8 = 0;
        do {
          HeapDestroy(*(HANDLE *)(DAT_100250b8 + uVar8 * 4));
          uVar8 = uVar8 + 1;
        } while (uVar8 <= DAT_100250b4);
      }
      HeapDestroy(DAT_10025058);
    }
  }
  return 1;
}




======================================================================
// Function: DllCanUnloadNow @ 10010aa0
======================================================================

HRESULT DllCanUnloadNow(void)

{
                    /* 0x10aa0  1  DllCanUnloadNow */
  return (uint)(DAT_10025054 != 0);
}




======================================================================
// Function: DllGetClassObject @ 10010ab0
======================================================================

/* WARNING: Removing unreachable block (ram,0x10010abc) */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  ulong *puVar2;
  ulong uVar3;
  int iVar4;
  undefined4 *puVar5;
  
                    /* 0x10ab0  2  DllGetClassObject */
  puVar5 = DAT_10025050;
  iVar4 = 0;
  if (ppv == (LPVOID *)0x0) {
    return -0x7fffbffd;
  }
  *ppv = (LPVOID)0x0;
  puVar2 = (ulong *)*puVar5;
  do {
    if (puVar2 == (ulong *)0x0) {
LAB_10010b7e:
      if ((*ppv == (LPVOID)0x0) && (iVar4 == 0)) {
        iVar4 = -0x7ffbfeef;
      }
      return iVar4;
    }
    if ((((puVar5[2] != 0) && (rclsid->Data1 == *puVar2)) &&
        (uVar3._0_2_ = rclsid->Data2, uVar3._2_2_ = rclsid->Data3, uVar3 == puVar2[1])) &&
       ((*(ulong *)rclsid->Data4 == puVar2[2] && (*(ulong *)(rclsid->Data4 + 4) == puVar2[3])))) {
      piVar1 = puVar5 + 4;
      if (puVar5[4] == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002508c);
        if (*piVar1 == 0) {
          iVar4 = (*(code *)puVar5[2])(puVar5[3],&DAT_10021c80,piVar1);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002508c);
      }
      puVar5 = (undefined4 *)*piVar1;
      if (puVar5 != (undefined4 *)0x0) {
        iVar4 = (**(code **)*puVar5)(puVar5,riid,ppv);
      }
      goto LAB_10010b7e;
    }
    if (DAT_10025040 == 100) {
      puVar5 = puVar5 + 7;
    }
    else {
      puVar5 = puVar5 + 9;
    }
    puVar2 = (ulong *)*puVar5;
  } while( true );
}




======================================================================
// Function: DllRegisterServer @ 10010ba0
======================================================================

/* WARNING: Removing unreachable block (ram,0x10010ba9) */

int DllRegisterServer(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
                    /* 0x10ba0  3  DllRegisterServer */
  iVar4 = 0;
  piVar3 = DAT_10025050;
  if (*DAT_10025050 != 0) {
    do {
      if (((code *)piVar3[6] == (code *)0x0) || (iVar1 = (*(code *)piVar3[6])(), iVar1 == 0)) {
        iVar4 = (*(code *)piVar3[1])(1);
        if (iVar4 < 0) {
          return iVar4;
        }
        if (DAT_10025040 == 0x84) {
          iVar4 = 1;
          piVar2 = (int *)(*(code *)piVar3[7])();
          iVar4 = Util_RegisterClass(*piVar3,piVar2,iVar4);
          if (iVar4 < 0) {
            return iVar4;
          }
        }
      }
      if (DAT_10025040 == 100) {
        piVar3 = piVar3 + 7;
      }
      else {
        piVar3 = piVar3 + 9;
      }
    } while (*piVar3 != 0);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  iVar4 = Register_Server(0x10025040,(LPCWSTR)0x0);
  return iVar4;
}




======================================================================
// Function: DllUnregisterServer @ 10010c30
======================================================================

/* WARNING: Removing unreachable block (ram,0x10010c39) */

undefined4 DllUnregisterServer(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
                    /* 0x10c30  4  DllUnregisterServer */
  iVar1 = *DAT_10025050;
  piVar3 = DAT_10025050;
  do {
    if (iVar1 == 0) {
      Unregister_Server(0x10025040,(LPCWSTR)0x0);
      return 0;
    }
    if ((((code *)piVar3[6] == (code *)0x0) || (iVar1 = (*(code *)piVar3[6])(), iVar1 == 0)) &&
       ((*(code *)piVar3[1])(0), DAT_10025040 == 0x84)) {
      if ((code *)piVar3[7] != (code *)0x0) {
        iVar1 = 0;
        piVar2 = (int *)(*(code *)piVar3[7])();
        Util_RegisterClass(*piVar3,piVar2,iVar1);
        goto LAB_10010c7d;
      }
LAB_10010c8b:
      piVar3 = piVar3 + 9;
    }
    else {
LAB_10010c7d:
      if (DAT_10025040 != 100) goto LAB_10010c8b;
      piVar3 = piVar3 + 7;
    }
    iVar1 = *piVar3;
  } while( true );
}




======================================================================
// Function: FUN_10010cc0 @ 10010cc0
======================================================================

int FUN_10010cc0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1002080b;
  local_c = ExceptionList;
  iVar3 = -0x7ff8fff2;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x3c);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    Init_CriticalSection(puVar1 + 1);
    *puVar1 = &PTR_LAB_100214ec;
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 9));
    *puVar1 = &PTR_FUN_100214d8;
  }
  local_4 = 0xffffffff;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[8] = param_1;
    iVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
    iVar3 = 0;
    if (iVar2 != 0) {
      *puVar1 = &PTR_FUN_100214d8;
      puVar1[1] = 1;
      DeleteCriticalSection((LPCRITICAL_SECTION)(puVar1 + 9));
      DeleteCriticalSection((LPCRITICAL_SECTION)(puVar1 + 2));
      Mem_FreeObj(puVar1);
      ExceptionList = local_c;
      return iVar2;
    }
  }
  ExceptionList = local_c;
  return iVar3;
}




======================================================================
// Function: FUN_10010dd0 @ 10010dd0
======================================================================

LONG FUN_10010dd0(int param_1)

{
  LONG LVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (*(LONG *)(param_1 + 4) == 2) {
    InterlockedIncrement(&DAT_10025054);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  return LVar1;
}




======================================================================
// Function: FUN_10010e10 @ 10010e10
======================================================================

int FUN_10010e10(undefined4 *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  InterlockedDecrement(param_1 + 1);
  iVar1 = param_1[1];
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  if (iVar1 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      FUN_10010e70(param_1);
      Mem_FreeObj(param_1);
      return 0;
    }
  }
  else if (iVar1 == 1) {
    InterlockedDecrement(&DAT_10025054);
  }
  return iVar1;
}




======================================================================
// Function: FUN_10010e70 @ 10010e70
======================================================================

void __fastcall FUN_10010e70(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_100214d8;
  param_1[1] = 1;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  DeleteCriticalSection
            ((LPCRITICAL_SECTION)((-(uint)(param_1 != (undefined4 *)0x0) & (uint)(param_1 + 1)) + 4)
            );
  return;
}




======================================================================
// Function: FUN_10010ea0 @ 10010ea0
======================================================================

int FUN_10010ea0(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  
  ppuVar4 = &PTR_DAT_10021500;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  puVar2 = DAT_10021508;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    iVar3 = DAT_10021504 + (int)param_1;
    (**(code **)(*(int *)(DAT_10021504 + (int)param_1) + 4))(iVar3);
    *param_3 = iVar3;
    return 0;
  }
  do {
    if (puVar2 == (undefined *)0x0) {
      return -0x7fffbffe;
    }
    piVar5 = (int *)*ppuVar4;
    if ((piVar5 == (int *)0x0) ||
       (((*piVar5 == *param_2 && (piVar5[1] == param_2[1])) &&
        ((piVar5[2] == param_2[2] && (piVar5[3] == param_2[3])))))) {
      if ((code *)ppuVar4[2] == (code *)0x1) {
        piVar5 = (int *)(ppuVar4[1] + (int)param_1);
        (**(code **)(*piVar5 + 4))(piVar5);
        *param_3 = piVar5;
        return 0;
      }
      iVar3 = (*(code *)ppuVar4[2])(param_1,param_2,param_3,ppuVar4[1]);
      if (iVar3 == 0) {
        return 0;
      }
      if ((piVar5 != (int *)0x0) && (iVar3 < 0)) {
        return iVar3;
      }
    }
    ppuVar1 = ppuVar4 + 5;
    ppuVar4 = ppuVar4 + 3;
    puVar2 = *ppuVar1;
  } while( true );
}




======================================================================
// Function: CreateEffectObject @ 10010fa0
======================================================================

int CreateEffectObject(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1002082b;
  local_c = ExceptionList;
  iVar2 = -0x7ff8fff2;
  ExceptionList = &local_c;
  puVar1 = operator_new(0xd0a4);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    InitStateDefaults((int)puVar1);
    *puVar1 = &PTR_FUN_10021564;
    puVar1[1] = &PTR_LAB_10021550;
    puVar1[0x25] = &PTR_LAB_10021518;
    InterlockedIncrement(&DAT_10025054);
  }
  local_4 = 0xffffffff;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[0x26] = puVar1[0x26] + 1;
    iVar2 = Shutdown_Stub();
    puVar1[0x26] = puVar1[0x26] + -1;
    if ((iVar2 == 0) && (iVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3), iVar2 == 0)) {
      ExceptionList = local_c;
      return 0;
    }
    (**(code **)(puVar1[1] + 4))(1);
  }
  ExceptionList = local_c;
  return iVar2;
}




======================================================================
// Function: Get_SingletonObject @ 10011180
======================================================================

int * Get_SingletonObject(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  
  piVar1 = (int *)0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    piVar1 = (int *)0x0;
    if (DAT_10024194 == (int *)0x0) {
      piVar1 = FUN_10014260(&PTR_DAT_10024188,param_3);
    }
    *param_4 = DAT_10024194;
    if (DAT_10024194 != (int *)0x0) {
      (**(code **)(*DAT_10024194 + 4))(DAT_10024194);
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}




======================================================================
// Function: Create_VisObject2 @ 10011350
======================================================================

int Create_VisObject2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10020856;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = operator_new(0xd0ac);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    InitStateDefaults((int)(puVar1 + 2));
    puVar1[2] = &PTR_LAB_10021848;
    puVar1[3] = &PTR_LAB_10021834;
    puVar1[0x27] = &PTR_LAB_100217fc;
    puVar1[0x28] = param_1;
    *puVar1 = &PTR_FUN_100217f0;
    InterlockedIncrement(&DAT_10025054);
  }
  local_4 = 0xffffffff;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = Shutdown_Stub();
    if ((iVar2 == 0) && (iVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3), iVar2 == 0)) {
      ExceptionList = local_c;
      return 0;
    }
    *puVar1 = &PTR_FUN_100217f0;
    local_4 = 1;
    puVar1[1] = 1;
    Init_RenderContext();
    InterlockedDecrement(&DAT_10025054);
    local_4 = 0xffffffff;
    Destructor_VisObject(puVar1 + 3);
    Mem_FreeObj(puVar1);
    ExceptionList = local_c;
    return iVar2;
  }
  ExceptionList = local_c;
  return -0x7ff8fff2;
}




======================================================================
// Function: Init_CriticalSection @ 10011480
======================================================================

undefined4 * __fastcall Init_CriticalSection(undefined4 *param_1)

{
  *param_1 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return param_1;
}




======================================================================
// Function: QueryInterface_Table2 @ 100114f0
======================================================================

int QueryInterface_Table2(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  
  ppuVar4 = &PTR_DAT_10021ad8;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  puVar2 = DAT_10021ae0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    iVar3 = DAT_10021adc + (int)param_1;
    (**(code **)(*(int *)(DAT_10021adc + (int)param_1) + 4))(iVar3);
    *param_3 = iVar3;
    return 0;
  }
  do {
    if (puVar2 == (undefined *)0x0) {
      return -0x7fffbffe;
    }
    piVar5 = (int *)*ppuVar4;
    if ((piVar5 == (int *)0x0) ||
       (((*piVar5 == *param_2 && (piVar5[1] == param_2[1])) &&
        ((piVar5[2] == param_2[2] && (piVar5[3] == param_2[3])))))) {
      if ((code *)ppuVar4[2] == (code *)0x1) {
        piVar5 = (int *)(ppuVar4[1] + (int)param_1);
        (**(code **)(*piVar5 + 4))(piVar5);
        *param_3 = piVar5;
        return 0;
      }
      iVar3 = (*(code *)ppuVar4[2])(param_1,param_2,param_3,ppuVar4[1]);
      if (iVar3 == 0) {
        return 0;
      }
      if ((piVar5 != (int *)0x0) && (iVar3 < 0)) {
        return iVar3;
      }
    }
    ppuVar1 = ppuVar4 + 5;
    ppuVar4 = ppuVar4 + 3;
    puVar2 = *ppuVar1;
  } while( true );
}




======================================================================
// Function: IUnknown_Release2 @ 10011600
======================================================================

int IUnknown_Release2(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if ((iVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    Destructor_VisObject2(param_1);
    Mem_FreeObj(param_1);
  }
  return iVar1;
}




======================================================================
// Function: Destructor_VisObject2 @ 10011630
======================================================================

void __fastcall Destructor_VisObject2(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1002086b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_100217f0;
  local_4 = 0;
  param_1[1] = 1;
  Init_RenderContext();
  InterlockedDecrement(&DAT_10025054);
  local_4 = 0xffffffff;
  Destructor_VisObject(param_1 + 3);
  ExceptionList = local_c;
  return;
}




======================================================================
// Function: QueryInterface_Main @ 100116a0
======================================================================

int QueryInterface_Main(int *param_1,int *param_2,int *param_3)

{
  undefined **ppuVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    if (param_3 != (int *)0x0) {
      *param_3 = (int)param_1;
      (**(code **)(*param_1 + 4))(param_1);
      return 0;
    }
    return -0x7fffbffd;
  }
  piVar6 = param_1 + 2;
  ppuVar5 = &PTR_DAT_10021ad8;
  if (param_3 == (int *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  puVar3 = DAT_10021ae0;
  if (((*param_2 == 0) && (param_2[1] == 0)) && ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))
     ) {
    iVar4 = DAT_10021adc + (int)piVar6;
    (**(code **)(*(int *)(DAT_10021adc + (int)piVar6) + 4))(iVar4);
    *param_3 = iVar4;
    return 0;
  }
  do {
    if (puVar3 == (undefined *)0x0) {
      return -0x7fffbffe;
    }
    piVar2 = (int *)*ppuVar5;
    if ((piVar2 == (int *)0x0) ||
       (((*piVar2 == *param_2 && (piVar2[1] == param_2[1])) &&
        ((piVar2[2] == param_2[2] && (piVar2[3] == param_2[3])))))) {
      if ((code *)ppuVar5[2] == (code *)0x1) {
        piVar6 = (int *)(ppuVar5[1] + (int)piVar6);
        (**(code **)(*piVar6 + 4))(piVar6);
        *param_3 = (int)piVar6;
        return 0;
      }
      iVar4 = (*(code *)ppuVar5[2])(piVar6,param_2,param_3,ppuVar5[1]);
      if (iVar4 == 0) {
        return 0;
      }
      if ((piVar2 != (int *)0x0) && (iVar4 < 0)) {
        return iVar4;
      }
    }
    ppuVar1 = ppuVar5 + 5;
    ppuVar5 = ppuVar5 + 3;
    puVar3 = *ppuVar1;
  } while( true );
}




======================================================================
// Function: ScalarDeletingDestructor_Main @ 10011940
======================================================================

undefined4 * __thiscall ScalarDeletingDestructor_Main(void *this,byte param_1)

{
  Destructor_Main(this);
  if ((param_1 & 1) != 0) {
    Mem_FreeObj((LPVOID)((int)this + -4));
  }
  return (undefined4 *)((int)this + -4);
}




======================================================================
// Function: Destructor_Main @ 10011970
======================================================================

void __fastcall Destructor_Main(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10020888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[-1] = &PTR_FUN_10021564;
  *param_1 = &PTR_LAB_10021550;
  param_1[0x24] = &PTR_LAB_10021518;
  local_4 = 0;
  param_1[0x25] = 1;
  Init_RenderContext();
  InterlockedDecrement(&DAT_10025054);
  local_4 = 0xffffffff;
  Destructor_VisObject(param_1);
  ExceptionList = local_c;
  return;
}




======================================================================
// Function: thunk_FUN_1000fa60 @ 100119f0
======================================================================

void __fastcall thunk_FUN_1000fa60(void *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &LAB_100207e8;
  pvStack_c = ExceptionList;
  uStack_4 = 0;
  ExceptionList = &pvStack_c;
  (**(code **)(*(int *)((int)param_1 + -4) + 0xf0))((int)param_1 + -4);
  puStack_8 = (undefined1 *)0xffffffff;
  Cleanup_WindowState(-(uint)(param_1 != (void *)0x4) & (uint)param_1);
  ExceptionList = param_1;
  return;
}




======================================================================
// Function: ScalarDeletingDestructor_Main2 @ 10011a00
======================================================================

int __thiscall ScalarDeletingDestructor_Main2(void *this,byte param_1)

{
  thunk_FUN_1000fa60(this);
  if ((param_1 & 1) != 0) {
    Mem_FreeObj((LPVOID)((int)this + -4));
  }
  return (int)this + -4;
}




======================================================================
// Function: BuildRegScript @ 10011a90
======================================================================

/* WARNING: Removing unreachable block (ram,0x10011c6b) */
/* WARNING: Removing unreachable block (ram,0x10011cc8) */

LPCSTR BuildRegScript(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  WCHAR WVar2;
  LPCWSTR pWVar3;
  WCHAR *pWVar4;
  HMODULE pHVar5;
  DWORD DVar6;
  WCHAR *pWVar7;
  int iVar8;
  LPCSTR pCVar9;
  WCHAR *pWVar10;
  LPCWSTR lpString;
  CHAR local_228 [260];
  CHAR local_124 [260];
  void *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100208b8;
  local_10 = ExceptionList;
  local_1c = 0;
  local_18 = 10;
  ExceptionList = &local_10;
  local_20 = _malloc(0x28);
  local_8 = 0;
  GetModuleFileNameA(*(HMODULE *)(DAT_10025020 + 4),local_124,0x104);
  if ((*(int *)(param_1 + 4) == 0) ||
     (pHVar5 = GetModuleHandleA((LPCSTR)0x0), *(HMODULE *)(param_1 + 4) == pHVar5)) {
    DVar6 = GetShortPathNameA(local_124,local_228,0x104);
    if (DVar6 == 0x104) {
      local_8 = 1;
      FUN_10011e60((int *)&local_20);
      Mem_Free(local_20);
      ExceptionList = local_10;
      return (LPCSTR)0x8007000e;
    }
    if ((DVar6 == 0) || (DVar6 == 0x57)) {
      if (&stack0x00000000 == (undefined1 *)0x124) {
        lpString = (LPCWSTR)0x0;
        goto LAB_10011bde;
      }
      goto LAB_10011ba9;
    }
    if (&stack0x00000000 == (undefined1 *)0x228) {
      lpString = (LPCWSTR)0x0;
      goto LAB_10011bde;
    }
    iVar8 = lstrlenA(local_228);
    FUN_1001a250();
    pCVar9 = local_228;
  }
  else {
    if (&stack0x00000000 == (undefined1 *)0x124) {
      lpString = (LPCWSTR)0x0;
      goto LAB_10011bde;
    }
LAB_10011ba9:
    iVar8 = lstrlenA(local_124);
    FUN_1001a250();
    pCVar9 = local_124;
  }
  lpString = (LPCWSTR)&stack0xfffffdcc;
  MultiByteToWideChar(0,0,pCVar9,-1,(LPWSTR)&stack0xfffffdcc,iVar8 + 1);
LAB_10011bde:
  lstrlenW(lpString);
  FUN_1001a250();
  WVar2 = *lpString;
  pWVar10 = lpString;
  pWVar4 = (WCHAR *)&stack0xfffffdcc;
  while (WVar2 != L'\0') {
    *pWVar4 = *pWVar10;
    pWVar7 = pWVar4 + 1;
    if (*pWVar10 == L'\'') {
      *pWVar7 = L'\'';
      pWVar7 = pWVar4 + 2;
    }
    pWVar10 = pWVar10 + 1;
    pWVar4 = pWVar7;
    WVar2 = *pWVar10;
  }
  *pWVar4 = L'\0';
  StringBuffer_Append(&local_20,u_Module_100241ec,(LPCWSTR)&stack0xfffffdcc);
  if (param_4 != (undefined4 *)0x0) {
    pWVar3 = (LPCWSTR)*param_4;
    while (pWVar3 != (LPCWSTR)0x0) {
      StringBuffer_Append(&local_20,pWVar3,(LPCWSTR)param_4[1]);
      puVar1 = param_4 + 2;
      param_4 = param_4 + 2;
      pWVar3 = (LPCWSTR)*puVar1;
    }
  }
  if (param_3 == 0) {
    iVar8 = lstrlenW(u_REGISTRY_100241d8);
    FUN_1001a250();
    WideCharToMultiByte(0,0,u_REGISTRY_100241d8,-1,&stack0xfffffdcc,iVar8 * 2 + 2,(LPCSTR)0x0,
                        (LPBOOL)0x0);
  }
  else {
    iVar8 = lstrlenW(u_REGISTRY_100241d8);
    FUN_1001a250();
    WideCharToMultiByte(0,0,u_REGISTRY_100241d8,-1,&stack0xfffffdcc,iVar8 * 2 + 2,(LPCSTR)0x0,
                        (LPBOOL)0x0);
  }
  pCVar9 = ExecuteRegScript(lpString,(LPCSTR)(param_2 & 0xffff),&stack0xfffffdcc,(uint)(param_3 != 0));
  local_8 = 2;
  FUN_10011e60((int *)&local_20);
  Mem_Free(local_20);
  ExceptionList = local_10;
  return pCVar9;
}




======================================================================
// Function: StringBuffer_Append @ 10011d50
======================================================================

void __fastcall StringBuffer_Append(undefined4 *param_1)

{
  Mem_Free((LPVOID)*param_1);
  return;
}




======================================================================
// Function: StringBuffer_Append @ 10011d60
======================================================================

undefined4 __thiscall StringBuffer_Append(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  undefined4 *puVar1;
  int iVar2;
  LPVOID pvVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  puVar1 = operator_new(8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = lstrlenW(param_1);
    uVar6 = iVar2 * 2 + 2;
    iVar2 = lstrlenW(param_2);
    uVar7 = iVar2 * 2 + 2;
    pvVar3 = CoTaskMemAlloc(uVar6);
    *puVar1 = pvVar3;
    pvVar3 = CoTaskMemAlloc(uVar7);
    puVar8 = (undefined4 *)*puVar1;
    puVar1[1] = pvVar3;
    if ((puVar8 == (undefined4 *)0x0) || (pvVar3 == (LPVOID)0x0)) {
      CoTaskMemFree(puVar8);
      CoTaskMemFree((LPVOID)puVar1[1]);
      Mem_FreeObj(puVar1);
    }
    else {
      for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *(undefined4 *)param_1;
        param_1 = param_1 + 2;
        puVar8 = puVar8 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)puVar8 = (char)*param_1;
        param_1 = (LPCWSTR)((int)param_1 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar8 = (undefined4 *)puVar1[1];
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar8 = *(undefined4 *)param_2;
        param_2 = param_2 + 2;
        puVar8 = puVar8 + 1;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(char *)puVar8 = (char)*param_2;
        param_2 = (LPCWSTR)((int)param_2 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar2 = *(int *)((int)this + 8);
      if (*(int *)((int)this + 4) == iVar2) {
        *(int *)((int)this + 8) = iVar2 * 2;
        piVar4 = FUN_1001a296(*(int **)this,(uint *)(iVar2 * 8));
        *(int **)this = piVar4;
      }
      if (*(int *)this != 0) {
        *(undefined4 **)(*(int *)this + *(int *)((int)this + 4) * 4) = puVar1;
        *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
        return 0;
      }
    }
  }
  return 0x8007000e;
}




======================================================================
// Function: FUN_10011e60 @ 10011e60
======================================================================

undefined4 __fastcall FUN_10011e60(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1[1] < 1) {
    param_1[1] = 0;
    return 0;
  }
  do {
    puVar1 = *(undefined4 **)(*param_1 + iVar2 * 4);
    CoTaskMemFree((LPVOID)puVar1[1]);
    CoTaskMemFree((LPVOID)*puVar1);
    Mem_FreeObj(puVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < param_1[1]);
  param_1[1] = 0;
  return 0;
}




======================================================================
// Function: FUN_10011eb0 @ 10011eb0
======================================================================

void __fastcall FUN_10011eb0(int *param_1)

{
  undefined4 *puVar1;
  void **ppvVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_100208d8;
  local_c = ExceptionList;
  iVar3 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  ppvVar2 = &local_c;
  if (0 < param_1[1]) {
    do {
      puVar1 = *(undefined4 **)(*param_1 + iVar3 * 4);
      CoTaskMemFree((LPVOID)puVar1[1]);
      CoTaskMemFree((LPVOID)*puVar1);
      Mem_FreeObj(puVar1);
      iVar3 = iVar3 + 1;
      ppvVar2 = ExceptionList;
    } while (iVar3 < param_1[1]);
  }
  ExceptionList = ppvVar2;
  param_1[1] = 0;
  Mem_Free((LPVOID)*param_1);
  ExceptionList = local_c;
  return;
}




======================================================================
// Function: ExecuteRegScript @ 10011f30
======================================================================

LPCSTR ExecuteRegScript(LPCWSTR param_1,LPCSTR param_2,LPCSTR param_3,int param_4)

{
  char cVar1;
  int iVar2;
  HMODULE hModule;
  DWORD DVar3;
  HRSRC hResInfo;
  uint uVar4;
  char *lpsz;
  LPCWSTR pWVar5;
  HKEY pHVar6;
  LPCWSTR lpsz_00;
  code *pcVar7;
  LPCSTR pCVar8;
  CHAR *pCVar9;
  char local_1010 [4060];
  undefined4 uStackY_34;
  
  FUN_1001a250();
  pWVar5 = param_1;
  pCVar8 = (LPCSTR)0x0;
  if (param_1 != (LPCWSTR)0x0) {
    pCVar8 = &stack0xfffffff0;
    iVar2 = lstrlenW(param_1);
    FUN_1001a250();
    uStackY_34 = 0x10011f7e;
    WideCharToMultiByte(0,0,pWVar5,-1,&stack0xfffffff0,iVar2 * 2 + 2,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  hModule = LoadLibraryExA(pCVar8,(HANDLE)0x0,2);
  if (hModule == (HMODULE)0x0) {
    DVar3 = GetLastError();
    if (DVar3 == 0) {
      return (LPCSTR)0x0;
    }
    DVar3 = GetLastError();
    return (LPCSTR)(DVar3 & 0xffff | 0x80070000);
  }
  hResInfo = FindResourceA(hModule,param_2,param_3);
  pcVar7 = GetLastError_exref;
  if (hResInfo == (HRSRC)0x0) {
    DVar3 = GetLastError();
  }
  else {
    pCVar8 = LoadResource(hModule,hResInfo);
    pcVar7 = GetLastError_exref;
    if (pCVar8 != (LPCSTR)0x0) {
      DVar3 = SizeofResource(hModule,hResInfo);
      if (pCVar8[DVar3] != '\0') {
        FUN_1001a250();
        pCVar9 = &stack0xfffffff0;
        for (uVar4 = DVar3 + 1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pCVar9 = *(undefined4 *)pCVar8;
          pCVar8 = pCVar8 + 4;
          pCVar9 = pCVar9 + 4;
        }
        for (uVar4 = DVar3 + 1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pCVar9 = *pCVar8;
          pCVar8 = pCVar8 + 1;
          pCVar9 = pCVar9 + 1;
        }
        (&stack0xfffffff0)[DVar3] = 0;
        pCVar8 = &stack0xfffffff0;
      }
      pCVar8 = ExpandVariables(&stack0xfffffff4,pCVar8,&param_1);
      if (-1 < (int)pCVar8) {
        cVar1 = (char)*param_1;
        pWVar5 = param_1;
        while (cVar1 != '\0') {
          pCVar9 = local_1010;
          SkipWhitespace((undefined4 *)&stack0xfffffff4);
          pcVar7 = CharNextA_exref;
          cVar1 = (char)*pWVar5;
          if (cVar1 == '\0') {
LAB_100121fe:
            pCVar8 = (LPCSTR)0x80020009;
            break;
          }
          lpsz_00 = pWVar5;
          if (cVar1 == '\'') {
            lpsz = CharNextA((LPCSTR)pWVar5);
            if (*lpsz != '\0') {
              do {
                iVar2 = IsEscape((undefined4 *)&stack0xfffffff4);
                if (iVar2 != 0) break;
                pCVar8 = lpsz;
                if (*lpsz == '\'') {
                  pCVar8 = CharNextA(lpsz);
                }
                lpsz = CharNextA(pCVar8);
                if (&stack0xfffffff0 <= pCVar9 + 2) goto LAB_100121fe;
                for (; pCVar8 < lpsz; pCVar8 = pCVar8 + 1) {
                  *pCVar9 = *pCVar8;
                  pCVar9 = pCVar9 + 1;
                }
              } while (*lpsz != '\0');
              if (*lpsz != '\0') {
                *pCVar9 = '\0';
                pWVar5 = (LPCWSTR)CharNextA(lpsz);
                goto LAB_10012147;
              }
            }
            goto LAB_100121fe;
          }
          do {
            iVar2 = IsDelimiter(cVar1);
            pWVar5 = lpsz_00;
            if (iVar2 != 0) break;
            pWVar5 = (LPCWSTR)CharNextA((LPCSTR)lpsz_00);
            for (; lpsz_00 < pWVar5; lpsz_00 = (LPCWSTR)((int)lpsz_00 + 1)) {
              *pCVar9 = (CHAR)*lpsz_00;
              pCVar9 = pCVar9 + 1;
            }
            cVar1 = (char)*pWVar5;
            lpsz_00 = pWVar5;
          } while (cVar1 != '\0');
          *pCVar9 = '\0';
          pcVar7 = CharNextA_exref;
LAB_10012147:
          pHVar6 = (HKEY)FUN_10012270(local_1010);
          if (pHVar6 == (HKEY)0x0) goto LAB_100121fe;
          pCVar8 = (LPCSTR)ParseToken(&stack0xfffffff4,local_1010);
          if ((int)pCVar8 < 0) break;
          if (local_1010[0] != '{') goto LAB_100121fe;
          if (param_4 == 0) {
            pCVar8 = (LPCSTR)RegFileParser(local_1010,pHVar6,0,(LPSTR)0x0);
            if ((int)pCVar8 < 0) break;
          }
          else {
            pCVar8 = (LPCSTR)RegFileParser(local_1010,pHVar6,param_4,(LPSTR)0x0);
            pcVar7 = CharNextA_exref;
            if ((int)pCVar8 < 0) {
              RegFileParser(local_1010,pHVar6,0,(LPSTR)0x0);
              break;
            }
          }
          iVar2 = IsDelimiter((char)*pWVar5);
          while (iVar2 != 0) {
            pWVar5 = (LPCWSTR)(*pcVar7)();
            iVar2 = IsDelimiter((char)*pWVar5);
          }
          cVar1 = (char)*pWVar5;
        }
        CoTaskMemFree(param_1);
      }
      goto LAB_10012229;
    }
    DVar3 = GetLastError();
  }
  if (DVar3 == 0) {
    pCVar8 = (LPCSTR)0x0;
  }
  else {
    uVar4 = (*pcVar7)();
    pCVar8 = (LPCSTR)(uVar4 & 0xffff | 0x80070000);
  }
LAB_10012229:
  FreeLibrary(hModule);
  return pCVar8;
}




======================================================================
// Function: IsEscape @ 10012250
======================================================================

undefined4 __fastcall IsEscape(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (*(LPCSTR)*param_1 == '\'') {
    pCVar1 = CharNextA((LPCSTR)*param_1);
    if (*pCVar1 != '\'') {
      return 1;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_10012270 @ 10012270
======================================================================

undefined4 __cdecl FUN_10012270(LPCSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  ppuVar2 = &PTR_DAT_10021b08;
  do {
    iVar1 = lstrcmpiA(param_1,*ppuVar2);
    if (iVar1 == 0) {
      return (&DAT_10021b0c)[iVar3 * 2];
    }
    ppuVar2 = ppuVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (ppuVar2 < &PTR_DAT_10021b78);
  return 0;
}




======================================================================
// Function: IsDelimiter @ 100122b0
======================================================================

undefined4 IsDelimiter(undefined1 param_1)

{
  switch(param_1) {
  case 9:
  case 10:
  case 0xd:
  case 0x20:
    return 1;
  default:
    return 0;
  }
}




======================================================================
// Function: SkipWhitespace @ 10012300
======================================================================

void __fastcall SkipWhitespace(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  do {
    switch(*(LPCSTR)*param_1) {
    case '\t':
    case '\n':
    case '\r':
    case ' ':
      pCVar1 = CharNextA((LPCSTR)*param_1);
      *param_1 = pCVar1;
      break;
    default:
      return;
    }
  } while( true );
}




======================================================================
// Function: ParseToken @ 10012350
======================================================================

undefined4 __thiscall ParseToken(void *this,CHAR *param_1)

{
  CHAR CVar1;
  char cVar2;
  LPSTR pCVar3;
  LPCSTR pCVar4;
  CHAR *pCVar5;
  
  do {
    switch(**(LPCSTR *)this) {
    case '\t':
    case '\n':
    case '\r':
    case ' ':
      pCVar3 = CharNextA(*(LPCSTR *)this);
      *(LPSTR *)this = pCVar3;
      break;
    default:
      goto switchD_10012371_caseD_b;
    }
  } while( true );
switchD_10012371_caseD_b:
  pCVar4 = *(LPCSTR *)this;
  cVar2 = *pCVar4;
  if (cVar2 == '\0') {
    return 0x80020009;
  }
  if (cVar2 == '\'') {
    pCVar3 = CharNextA(pCVar4);
    *(LPSTR *)this = pCVar3;
    cVar2 = *pCVar3;
    pCVar5 = param_1;
    while( true ) {
      if ((cVar2 == '\0') ||
         ((**(LPCSTR *)this == '\'' && (pCVar3 = CharNextA(*(LPCSTR *)this), *pCVar3 != '\'')))) {
        if (**(char **)this == '\0') {
          return 0x80020009;
        }
        *pCVar5 = '\0';
        pCVar3 = CharNextA(*(LPCSTR *)this);
        *(LPSTR *)this = pCVar3;
        return 0;
      }
      if (**(LPCSTR *)this == '\'') {
        pCVar3 = CharNextA(*(LPCSTR *)this);
        *(LPSTR *)this = pCVar3;
      }
      pCVar4 = *(LPCSTR *)this;
      pCVar3 = CharNextA(pCVar4);
      *(LPSTR *)this = pCVar3;
      if (param_1 + 0x1000 <= pCVar5 + 2) break;
      if (pCVar4 < pCVar3) {
        do {
          CVar1 = *pCVar4;
          pCVar4 = pCVar4 + 1;
          *pCVar5 = CVar1;
          pCVar5 = pCVar5 + 1;
        } while (pCVar4 < *(LPCSTR *)this);
      }
      cVar2 = **(char **)this;
    }
    return 0x80020009;
  }
  do {
    switch(cVar2) {
    case '\t':
    case '\n':
    case '\r':
    case ' ':
      goto switchD_10012433_caseD_9;
    }
    pCVar3 = CharNextA(pCVar4);
    *(LPSTR *)this = pCVar3;
    if (pCVar4 < pCVar3) {
      do {
        CVar1 = *pCVar4;
        pCVar4 = pCVar4 + 1;
        *param_1 = CVar1;
        param_1 = param_1 + 1;
      } while (pCVar4 < *(LPCSTR *)this);
    }
    pCVar4 = *(LPCSTR *)this;
    cVar2 = *pCVar4;
  } while (cVar2 != '\0');
switchD_10012433_caseD_9:
  *param_1 = '\0';
  return 0;
}




======================================================================
// Function: ExpandVariables @ 100124b0
======================================================================

/* WARNING: Removing unreachable block (ram,0x10012623) */

LPCSTR __thiscall ExpandVariables(void *this,LPCSTR param_1,undefined4 *param_2)

{
  char cVar1;
  LPVOID pvVar2;
  BYTE BVar3;
  int iVar4;
  BYTE *pBVar5;
  BOOL BVar6;
  LPCWSTR lpString;
  BYTE *pBVar7;
  LPSTR pCVar8;
  CHAR local_44 [32];
  SIZE_T local_24;
  SIZE_T local_20;
  LPVOID local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100208f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_2 = 0;
  local_14 = this;
  iVar4 = lstrlenA(param_1);
  local_20 = iVar4 << 1;
  local_24 = 0;
  local_1c = CoTaskMemAlloc(local_20);
  local_8 = 0;
  if (local_1c == (LPVOID)0x0) {
    CoTaskMemFree((LPVOID)0x0);
    param_1 = (LPCSTR)0x8007000e;
  }
  else {
    *(LPCSTR *)this = param_1;
    cVar1 = *param_1;
    param_1 = (LPCSTR)0x0;
    while (cVar1 != '\0') {
      pBVar5 = *(BYTE **)this;
      if (*pBVar5 == '%') {
        pBVar5 = (BYTE *)CharNextA((LPCSTR)pBVar5);
        *(BYTE **)this = pBVar5;
        if (*pBVar5 != '%') {
          BVar3 = *pBVar5;
          if (BVar3 != '\0') {
            while (BVar3 != '%') {
              pBVar5 = (BYTE *)CharNextA((LPCSTR)pBVar5);
              BVar3 = *pBVar5;
              if (BVar3 == '\0') goto LAB_100126bd;
            }
            if (pBVar5 != (BYTE *)0x0) {
              iVar4 = (int)pBVar5 - (int)*(LPCSTR *)this;
              if (0x1f < iVar4) {
                param_1 = (LPCSTR)0x80004005;
                break;
              }
              lstrcpynA(local_44,*(LPCSTR *)this,iVar4 + 1);
              lpString = (LPCWSTR)FUN_10012750(*(void **)((int)this + 4),local_44);
              if (lpString != (LPCWSTR)0x0) {
                iVar4 = lstrlenW(lpString);
                local_18 = iVar4 * 2 + 2;
                FUN_1001a250();
                WideCharToMultiByte(0,0,lpString,-1,&stack0xffffffb0,local_18,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
                pBVar7 = (BYTE *)*local_14;
                this = local_14;
                while (local_14 = this, pBVar7 != pBVar5) {
                  pBVar7 = (BYTE *)CharNextA(*(LPCSTR *)this);
                  *(BYTE **)this = pBVar7;
                  this = local_14;
                }
                goto LAB_10012650;
              }
            }
          }
LAB_100126bd:
          param_1 = (LPCSTR)0x80020009;
          break;
        }
        if (local_24 == local_20) {
          local_20 = local_20 * 2;
          local_1c = CoTaskMemRealloc(local_1c,local_20);
        }
        *(BYTE *)((int)local_1c + local_24) = *pBVar5;
        local_24 = local_24 + 1;
        BVar6 = IsDBCSLeadByte(*pBVar5);
        if (BVar6 != 0) {
          *(BYTE *)((int)local_1c + local_24) = pBVar5[1];
          local_24 = local_24 + 1;
        }
      }
      else {
        if (local_24 == local_20) {
          local_20 = local_20 * 2;
          local_1c = CoTaskMemRealloc(local_1c,local_20);
        }
        *(BYTE *)((int)local_1c + local_24) = *pBVar5;
        local_24 = local_24 + 1;
        BVar6 = IsDBCSLeadByte(*pBVar5);
        if (BVar6 != 0) {
          *(BYTE *)((int)local_1c + local_24) = pBVar5[1];
          local_24 = local_24 + 1;
        }
      }
LAB_10012650:
      pCVar8 = CharNextA(*(LPCSTR *)this);
      *(LPSTR *)this = pCVar8;
      cVar1 = *pCVar8;
    }
    pBVar5 = *(BYTE **)this;
    if (local_24 == local_20) {
      local_20 = local_20 * 2;
      local_1c = CoTaskMemRealloc(local_1c,local_20);
    }
    *(BYTE *)((int)local_1c + local_24) = *pBVar5;
    local_24 = local_24 + 1;
    BVar6 = IsDBCSLeadByte(*pBVar5);
    pvVar2 = local_1c;
    if (BVar6 != 0) {
      *(BYTE *)((int)local_1c + local_24) = pBVar5[1];
      local_24 = local_24 + 1;
    }
    if (-1 < (int)param_1) {
      local_1c = (LPVOID)0x0;
      *param_2 = pvVar2;
    }
    CoTaskMemFree(local_1c);
  }
  ExceptionList = local_10;
  return param_1;
}




======================================================================
// Function: FUN_10012750 @ 10012750
======================================================================

undefined4 __thiscall FUN_10012750(void *this,LPCSTR param_1)

{
  LPCWSTR lpString;
  int iVar1;
  LPCSTR lpString1;
  int local_c;
  
  local_c = 0;
  if (0 < *(int *)((int)this + 4)) {
    do {
      lpString = (LPCWSTR)**(undefined4 **)(*(int *)this + local_c * 4);
      if (lpString == (LPCWSTR)0x0) {
        lpString1 = (LPCSTR)0x0;
      }
      else {
        lpString1 = &stack0xffffffe8;
        iVar1 = lstrlenW(lpString);
        FUN_1001a250();
        WideCharToMultiByte(0,0,lpString,-1,&stack0xffffffe8,iVar1 * 2 + 2,(LPCSTR)0x0,(LPBOOL)0x0);
      }
      iVar1 = lstrcmpiA(lpString1,param_1);
      if (iVar1 == 0) {
        return *(undefined4 *)(*(int *)(*(int *)this + local_c * 4) + 4);
      }
      local_c = local_c + 1;
    } while (local_c < *(int *)((int)this + 4));
  }
  return 0;
}




======================================================================
// Function: FUN_100127f0 @ 100127f0
======================================================================

void __fastcall FUN_100127f0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}




======================================================================
// Function: FUN_10012800 @ 10012800
======================================================================

undefined4 __thiscall FUN_10012800(void *this,BYTE *param_1)

{
  SIZE_T cb;
  LPVOID pvVar1;
  BOOL BVar2;
  
  if (*(int *)this == *(int *)((int)this + 4)) {
    cb = *(int *)((int)this + 4) * 2;
    *(SIZE_T *)((int)this + 4) = cb;
    pvVar1 = CoTaskMemRealloc(*(LPVOID *)((int)this + 8),cb);
    *(LPVOID *)((int)this + 8) = pvVar1;
  }
  *(BYTE *)(*(int *)((int)this + 8) + *(int *)this) = *param_1;
  *(int *)this = *(int *)this + 1;
  BVar2 = IsDBCSLeadByte(*param_1);
  if (BVar2 != 0) {
    *(BYTE *)(*(int *)((int)this + 8) + *(int *)this) = param_1[1];
    *(int *)this = *(int *)this + 1;
  }
  return 1;
}




======================================================================
// Function: RegFileParser @ 10012860
======================================================================

uint RegFileParser(LPCSTR param_1,HKEY param_2,int param_3,LPSTR param_4)

{
  CHAR CVar1;
  char cVar2;
  bool bVar3;
  LPSTR pCVar4;
  int iVar5;
  LPCSTR pCVar6;
  int iVar7;
  LPCSTR pCVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  LSTATUS LVar9;
  undefined4 *this;
  HKEY unaff_EDI;
  CHAR *pCVar10;
  uint uVar11;
  undefined **ppuVar12;
  CHAR local_2240 [4096];
  CHAR local_1240 [4096];
  CHAR local_240 [256];
  CHAR local_140 [256];
  undefined4 uStackY_40;
  LPSTR lpName;
  LPDWORD lpcchName;
  char *lpsz;
  LPCSTR lpsz_00;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020930;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001a250();
  local_8 = 0;
  lpName = param_4;
  SkipWhitespace(this);
  cVar2 = *(LPCSTR)*this;
  if (cVar2 != '\0') {
    pCVar6 = param_1;
    if (cVar2 == '\'') {
      pCVar4 = CharNextA((LPCSTR)*this);
      *this = pCVar4;
      cVar2 = *pCVar4;
      pCVar10 = param_1;
      while ((cVar2 != '\0' && (iVar5 = IsEscape(this), iVar5 == 0))) {
        if (*(LPCSTR)*this == '\'') {
          pCVar4 = CharNextA((LPCSTR)*this);
          *this = pCVar4;
        }
        pCVar6 = (LPCSTR)*this;
        pCVar4 = CharNextA(pCVar6);
        *this = pCVar4;
        if (param_1 + 0x1000 <= pCVar10 + 2) goto LAB_100132d9;
        if (pCVar6 < pCVar4) {
          do {
            CVar1 = *pCVar6;
            pCVar6 = pCVar6 + 1;
            *pCVar10 = CVar1;
            pCVar10 = pCVar10 + 1;
          } while (pCVar6 < (LPCSTR)*this);
        }
        cVar2 = *(char *)*this;
      }
      if (*(char *)*this == '\0') goto LAB_100132d9;
      *pCVar10 = '\0';
      pCVar4 = CharNextA((LPCSTR)*this);
      *this = pCVar4;
    }
    else {
      do {
        iVar5 = IsDelimiter(cVar2);
        if (iVar5 != 0) break;
        pCVar8 = (LPCSTR)*this;
        pCVar4 = CharNextA(pCVar8);
        *this = pCVar4;
        if (pCVar8 < pCVar4) {
          do {
            CVar1 = *pCVar8;
            pCVar8 = pCVar8 + 1;
            *pCVar6 = CVar1;
            pCVar6 = pCVar6 + 1;
          } while (pCVar8 < (LPCSTR)*this);
        }
        cVar2 = *(char *)*this;
      } while (cVar2 != '\0');
      *pCVar6 = '\0';
    }
    uVar11 = 0;
    cVar2 = *param_1;
    do {
      if (cVar2 == '}') {
LAB_10013291:
        local_8 = 0xffffffff;
        FUN_10013310((undefined4 *)&stack0xffffffec);
        ExceptionList = local_10;
        return uVar11;
      }
      iVar5 = lstrcmpiA(param_1,PTR_s_Delete_10021400);
      lpcchName = (LPDWORD)(uint)(iVar5 == 0);
      iVar7 = lstrcmpiA(param_1,PTR_s_ForceRemove_100213f8);
      if ((iVar7 != 0) && ((LPDWORD)(uint)(iVar5 == 0) == (LPDWORD)0x0)) goto LAB_10012d0c;
      SkipWhitespace(this);
      cVar2 = *(LPCSTR)*this;
      if (cVar2 == '\0') goto LAB_100132c6;
      pCVar6 = param_1;
      if (cVar2 == '\'') {
        pCVar4 = CharNextA((LPCSTR)*this);
        *this = pCVar4;
        cVar2 = *pCVar4;
        pCVar10 = param_1;
        while ((cVar2 != '\0' && (iVar5 = IsEscape(this), iVar5 == 0))) {
          if (*(LPCSTR)*this == '\'') {
            pCVar4 = CharNextA((LPCSTR)*this);
            *this = pCVar4;
          }
          pCVar6 = (LPCSTR)*this;
          pCVar4 = CharNextA(pCVar6);
          *this = pCVar4;
          if (param_1 + 0x1000 <= pCVar10 + 2) goto LAB_100132c6;
          if (pCVar6 < pCVar4) {
            do {
              CVar1 = *pCVar6;
              pCVar6 = pCVar6 + 1;
              *pCVar10 = CVar1;
              pCVar10 = pCVar10 + 1;
            } while (pCVar6 < (LPCSTR)*this);
          }
          cVar2 = *(char *)*this;
        }
        if (*(char *)*this == '\0') goto LAB_100132c6;
        *pCVar10 = '\0';
        pCVar4 = CharNextA((LPCSTR)*this);
        *this = pCVar4;
      }
      else {
        do {
          iVar5 = IsDelimiter(cVar2);
          if (iVar5 != 0) break;
          pCVar8 = (LPCSTR)*this;
          pCVar4 = CharNextA(pCVar8);
          *this = pCVar4;
          if (pCVar8 < pCVar4) {
            do {
              CVar1 = *pCVar8;
              pCVar8 = pCVar8 + 1;
              *pCVar6 = CVar1;
              pCVar6 = pCVar6 + 1;
            } while (pCVar8 < (LPCSTR)*this);
          }
          cVar2 = *(char *)*this;
        } while (cVar2 != '\0');
        *pCVar6 = '\0';
      }
      if (param_3 == 0) {
LAB_10012d0c:
        iVar5 = lstrcmpiA(param_1,PTR_s_NoRemove_100213fc);
        if (iVar5 == 0) {
          SkipWhitespace(this);
          cVar2 = *(LPCSTR)*this;
          if (cVar2 != '\0') {
            pCVar6 = param_1;
            if (cVar2 == '\'') {
              pCVar4 = CharNextA((LPCSTR)*this);
              *this = pCVar4;
              cVar2 = *pCVar4;
              pCVar10 = param_1;
              while ((cVar2 != '\0' && (iVar5 = IsEscape(this), iVar5 == 0))) {
                if (*(LPCSTR)*this == '\'') {
                  pCVar4 = CharNextA((LPCSTR)*this);
                  *this = pCVar4;
                }
                pCVar6 = (LPCSTR)*this;
                pCVar4 = CharNextA(pCVar6);
                *this = pCVar4;
                if (param_1 + 0x1000 <= pCVar10 + 2) goto LAB_100132c6;
                if (pCVar6 < pCVar4) {
                  do {
                    CVar1 = *pCVar6;
                    pCVar6 = pCVar6 + 1;
                    *pCVar10 = CVar1;
                    pCVar10 = pCVar10 + 1;
                  } while (pCVar6 < (LPCSTR)*this);
                }
                cVar2 = *(char *)*this;
              }
              if (*(char *)*this == '\0') goto LAB_100132c6;
              *pCVar10 = '\0';
              pCVar4 = CharNextA((LPCSTR)*this);
              *this = pCVar4;
            }
            else {
              do {
                iVar5 = IsDelimiter(cVar2);
                if (iVar5 != 0) break;
                pCVar8 = (LPCSTR)*this;
                pCVar4 = CharNextA(pCVar8);
                *this = pCVar4;
                if (pCVar8 < pCVar4) {
                  do {
                    CVar1 = *pCVar8;
                    pCVar8 = pCVar8 + 1;
                    *pCVar6 = CVar1;
                    pCVar6 = pCVar6 + 1;
                  } while (pCVar8 < (LPCSTR)*this);
                }
                cVar2 = *(char *)*this;
              } while (cVar2 != '\0');
              *pCVar6 = '\0';
            }
            goto LAB_10012df3;
          }
        }
        else {
LAB_10012df3:
          pCVar6 = PTR_DAT_100213f4;
          iVar5 = lstrcmpiA(param_1,PTR_DAT_100213f4);
          if (iVar5 != 0) {
            cVar2 = *param_1;
            pCVar8 = param_1;
            while (lpsz_00 = pCVar8, cVar2 != '\0') {
              if (cVar2 == '\\') {
                if (lpsz_00 != (LPCSTR)0x0) goto LAB_100132d9;
                break;
              }
              pCVar8 = CharNextA(lpsz_00);
              cVar2 = *pCVar8;
              pCVar6 = lpsz_00;
            }
            if (param_3 != 0) {
              iVar5 = FUN_100133a0(&stack0xffffffec,param_2,param_1,0xf003f);
              if (((iVar5 != 0) &&
                  (iVar5 = FUN_100133a0(&stack0xffffffec,param_2,param_1,0x20019), iVar5 != 0)) &&
                 (lpName = param_1,
                 iVar5 = FUN_10013330(&stack0xffffffec,param_2,param_1,(LPSTR)0x0,0,0xf003f,
                                      (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), iVar5 != 0))
              break;
              uVar11 = ParseToken(this,param_1);
              if ((-1 < (int)uVar11) &&
                 ((*param_1 != '=' ||
                  (uVar11 = RegWriteValue((undefined4 *)&stack0xffffffec,(LPCSTR)0x0,param_1),
                  -1 < (int)uVar11)))) goto LAB_10012cad;
              goto LAB_10013291;
            }
            if (param_4 == (LPSTR)0x0) {
              pCVar6 = (LPCSTR)0x20019;
              iVar5 = FUN_100133a0(&stack0xffffffec,param_2,param_1,0x20019);
              if (iVar5 != 0) {
                param_4 = (LPSTR)0x1;
              }
            }
            if (pCVar6 == (LPCSTR)0x0) {
              FUN_1001a250();
              pCVar6 = &stack0xffffffe4;
            }
            pCVar8 = (LPCSTR)0x10013151;
            lstrcpynA(pCVar6,param_1,0x104);
            if (((param_4 == (LPSTR)0x0) &&
                (bVar3 = FUN_10013960((HKEY)0x0), CONCAT31(extraout_var,bVar3) == 0)) &&
               (iVar5 = Reg_QueryKeyInfo(0,(char)unaff_EDI), iVar5 == 0)) {
LAB_1001322b:
              pCVar6 = (LPCSTR)0x10013233;
              LVar9 = FUN_10013310((undefined4 *)&stack0xffffffec);
              if (LVar9 != 0) break;
              pCVar4 = param_4;
              if (pCVar8 != (LPCSTR)0x0) {
                RegDeleteKeyA(param_2,pCVar6);
                FUN_10013310((undefined4 *)&stack0xffffffd8);
              }
            }
            else {
              uVar11 = ParseToken(this,param_1);
              if (((int)uVar11 < 0) || (uVar11 = Reg_ParseConfigValue(), (int)uVar11 < 0))
              goto LAB_10013291;
              if (*param_1 != '{') {
                if (param_4 != (LPSTR)0x0) goto LAB_10012cef;
LAB_100131dc:
                pCVar6 = (LPCSTR)0x0;
                bVar3 = FUN_10013960((HKEY)0x0);
                if (CONCAT31(extraout_var_00,bVar3) == 0) goto LAB_1001322b;
                ppuVar12 = &PTR_s_CLSID_10024030;
                do {
                  pCVar8 = *ppuVar12;
                  iVar5 = lstrcmpiA(pCVar6,pCVar8);
                  if (iVar5 == 0) goto LAB_10013218;
                  ppuVar12 = ppuVar12 + 1;
                  pCVar6 = pCVar8;
                } while ((int)ppuVar12 < 0x10024038);
                FUN_100133f0();
LAB_10013218:
                uVar11 = ParseToken(this,param_1);
                goto joined_r0x10013224;
              }
              pCVar8 = param_1;
              uVar11 = RegFileParser(param_1,(HKEY)0x0,0,param_4);
              if ((int)uVar11 < 0) goto LAB_10013291;
              pCVar4 = lpName;
              if (param_4 == (LPSTR)0x0) goto LAB_100131dc;
            }
            param_4 = pCVar4;
            uVar11 = ParseToken(this,param_1);
            if ((-1 < (int)uVar11) && (uVar11 = Reg_ParseConfigValue(), -1 < (int)uVar11))
            goto LAB_10012cef;
            goto LAB_10013291;
          }
          pCVar10 = local_140;
          SkipWhitespace(this);
          cVar2 = *(LPCSTR)*this;
          if (cVar2 != '\0') {
            if (cVar2 == '\'') {
              pCVar4 = CharNextA((LPCSTR)*this);
              *this = pCVar4;
              cVar2 = *pCVar4;
              while ((cVar2 != '\0' && (iVar5 = IsEscape(this), iVar5 == 0))) {
                if (*(LPCSTR)*this == '\'') {
                  pCVar4 = CharNextA((LPCSTR)*this);
                  *this = pCVar4;
                }
                pCVar6 = (LPCSTR)*this;
                pCVar4 = CharNextA(pCVar6);
                *this = pCVar4;
                if (&stack0x00000ec0 <= pCVar10 + 2) goto LAB_100132c6;
                for (; pCVar6 < pCVar4; pCVar6 = pCVar6 + 1) {
                  *pCVar10 = *pCVar6;
                  pCVar10 = pCVar10 + 1;
                }
                cVar2 = *pCVar4;
              }
              lpsz = (char *)*this;
              if (*lpsz == '\0') goto LAB_100132c6;
              *pCVar10 = '\0';
              pCVar4 = CharNextA(lpsz);
              *this = pCVar4;
            }
            else {
              do {
                iVar5 = IsDelimiter(cVar2);
                if (iVar5 != 0) break;
                pCVar6 = (LPCSTR)*this;
                pCVar4 = CharNextA(pCVar6);
                *this = pCVar4;
                for (; pCVar6 < pCVar4; pCVar6 = pCVar6 + 1) {
                  *pCVar10 = *pCVar6;
                  pCVar10 = pCVar10 + 1;
                }
                cVar2 = *pCVar4;
              } while (cVar2 != '\0');
              *pCVar10 = '\0';
            }
            SkipWhitespace(this);
            cVar2 = *(LPCSTR)*this;
            if (cVar2 != '\0') {
              pCVar6 = param_1;
              if (cVar2 == '\'') {
                pCVar4 = CharNextA((LPCSTR)*this);
                *this = pCVar4;
                cVar2 = *pCVar4;
                pCVar10 = param_1;
                while ((cVar2 != '\0' && (iVar5 = IsEscape(this), iVar5 == 0))) {
                  if (*(LPCSTR)*this == '\'') {
                    pCVar4 = CharNextA((LPCSTR)*this);
                    *this = pCVar4;
                  }
                  pCVar6 = (LPCSTR)*this;
                  pCVar4 = CharNextA(pCVar6);
                  *this = pCVar4;
                  if (param_1 + 0x1000 <= pCVar10 + 2) goto LAB_100132c6;
                  if (pCVar6 < pCVar4) {
                    do {
                      CVar1 = *pCVar6;
                      pCVar6 = pCVar6 + 1;
                      *pCVar10 = CVar1;
                      pCVar10 = pCVar10 + 1;
                    } while (pCVar6 < (LPCSTR)*this);
                  }
                  cVar2 = *(char *)*this;
                }
                if (*(char *)*this == '\0') goto LAB_100132c6;
                *pCVar10 = '\0';
                pCVar4 = CharNextA((LPCSTR)*this);
                *this = pCVar4;
              }
              else {
                do {
                  iVar5 = IsDelimiter(cVar2);
                  if (iVar5 != 0) break;
                  pCVar8 = (LPCSTR)*this;
                  pCVar4 = CharNextA(pCVar8);
                  *this = pCVar4;
                  if (pCVar8 < pCVar4) {
                    do {
                      CVar1 = *pCVar8;
                      pCVar8 = pCVar8 + 1;
                      *pCVar6 = CVar1;
                      pCVar6 = pCVar6 + 1;
                    } while (pCVar8 < (LPCSTR)*this);
                  }
                  cVar2 = *(char *)*this;
                } while (cVar2 != '\0');
                *pCVar6 = '\0';
              }
              if (*param_1 != '=') break;
              if (param_3 != 0) {
                local_8._0_1_ = 3;
                uVar11 = RegWriteValue((undefined4 *)&stack0xffffffe8,local_140,param_1);
                local_8 = (uint)local_8._1_3_ << 8;
                if ((int)uVar11 < 0) goto LAB_1001328c;
                goto LAB_10012ca8;
              }
              if (param_4 == (LPSTR)0x0) {
                RegDeleteValueA(param_2,local_140);
                FUN_10013310((undefined4 *)&stack0xffffffe8);
              }
              if (*param_1 == '=') {
                uVar11 = ParseToken(this,param_1);
                if ((int)uVar11 < 0) goto LAB_10013291;
                SkipWhitespace(this);
                uVar11 = ParseToken(this,local_2240);
                if (((int)uVar11 < 0) || (uVar11 = ParseToken(this,param_1), (int)uVar11 < 0))
                goto LAB_10013291;
              }
              uVar11 = 0;
              goto LAB_10012cef;
            }
          }
        }
LAB_100132c6:
        uVar11 = 0x80020009;
        goto LAB_10013291;
      }
      local_8._0_1_ = 1;
      cVar2 = *param_1;
      pCVar6 = param_1;
      while (cVar2 != '\0') {
        if (cVar2 == '\\') {
          if (pCVar6 != (LPCSTR)0x0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_10013310((undefined4 *)&stack0xffffffe8);
            goto LAB_100132d9;
          }
          break;
        }
        pCVar6 = CharNextA(pCVar6);
        cVar2 = *pCVar6;
      }
      ppuVar12 = &PTR_s_CLSID_10024030;
      do {
        iVar5 = lstrcmpiA(param_1,*ppuVar12);
        if (iVar5 == 0) goto LAB_10012b85;
        ppuVar12 = ppuVar12 + 1;
      } while ((int)ppuVar12 < 0x10024038);
      unaff_EDI = (HKEY)0x0;
      local_8 = CONCAT31(local_8._1_3_,2);
      iVar5 = FUN_100133a0(&stack0xffffffe4,param_2,param_1,0x2001f);
      if (iVar5 == 0) {
        lpcchName = (LPDWORD)&stack0xffffffdc;
        lpName = local_240;
        uStackY_40 = 0x10012b23;
        iVar5 = RegEnumKeyExA(unaff_EDI,0,lpName,lpcchName,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x100,
                              (PFILETIME)&stack0xffffffc4);
        while (iVar5 == 0) {
          iVar5 = FUN_100133f0();
          if (iVar5 != 0) goto LAB_10012b72;
          lpcchName = (LPDWORD)&stack0xffffffdc;
          lpName = local_240;
          uStackY_40 = 0x10012b5b;
          iVar5 = RegEnumKeyExA(unaff_EDI,0,lpName,lpcchName,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x100,
                                (PFILETIME)&stack0xffffffc4);
        }
        FUN_10013310((undefined4 *)&stack0xffffffe4);
        RegDeleteKeyA(param_2,param_1);
      }
LAB_10012b72:
      local_8._0_1_ = 1;
      FUN_10013310((undefined4 *)&stack0xffffffe4);
LAB_10012b85:
      if (lpcchName == (LPDWORD)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10013310((undefined4 *)&stack0xffffffe8);
        goto LAB_10012d0c;
      }
      SkipWhitespace(this);
      cVar2 = *(LPCSTR)*this;
      if (cVar2 == '\0') {
LAB_100132bf:
        uVar11 = 0x80020009;
LAB_10013285:
        local_8 = (uint)local_8._1_3_ << 8;
LAB_1001328c:
        FUN_10013310((undefined4 *)&stack0xffffffe8);
        goto LAB_10013291;
      }
      pCVar6 = param_1;
      if (cVar2 == '\'') {
        pCVar4 = CharNextA((LPCSTR)*this);
        *this = pCVar4;
        cVar2 = *pCVar4;
        pCVar10 = param_1;
        while ((cVar2 != '\0' && (iVar5 = IsEscape(this), iVar5 == 0))) {
          if (*(LPCSTR)*this == '\'') {
            pCVar4 = CharNextA((LPCSTR)*this);
            *this = pCVar4;
          }
          pCVar6 = (LPCSTR)*this;
          pCVar4 = CharNextA(pCVar6);
          *this = pCVar4;
          if (param_1 + 0x1000 <= pCVar10 + 2) goto LAB_100132bf;
          if (pCVar6 < pCVar4) {
            do {
              CVar1 = *pCVar6;
              pCVar6 = pCVar6 + 1;
              *pCVar10 = CVar1;
              pCVar10 = pCVar10 + 1;
            } while (pCVar6 < (LPCSTR)*this);
          }
          cVar2 = *(char *)*this;
        }
        if (*(char *)*this == '\0') goto LAB_100132bf;
        *pCVar10 = '\0';
        pCVar4 = CharNextA((LPCSTR)*this);
        *this = pCVar4;
      }
      else {
        do {
          iVar5 = IsDelimiter(cVar2);
          if (iVar5 != 0) break;
          pCVar8 = (LPCSTR)*this;
          pCVar4 = CharNextA(pCVar8);
          *this = pCVar4;
          if (pCVar8 < pCVar4) {
            do {
              CVar1 = *pCVar8;
              pCVar8 = pCVar8 + 1;
              *pCVar6 = CVar1;
              pCVar6 = pCVar6 + 1;
            } while (pCVar8 < (LPCSTR)*this);
          }
          cVar2 = *(char *)*this;
        } while (cVar2 != '\0');
        *pCVar6 = '\0';
      }
      if (*param_1 == '=') {
        uVar11 = ParseToken(this,param_1);
        if (-1 < (int)uVar11) {
          SkipWhitespace(this);
          uVar11 = ParseToken(this,local_1240);
          if ((-1 < (int)uVar11) && (uVar11 = ParseToken(this,param_1), -1 < (int)uVar11))
          goto LAB_10012c9f;
        }
        goto LAB_10013285;
      }
LAB_10012c9f:
      uVar11 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
LAB_10012ca8:
      FUN_10013310((undefined4 *)&stack0xffffffe8);
LAB_10012cad:
      if ((*param_1 == '{') && (iVar5 = lstrlenA(param_1), iVar5 == 1)) {
        uVar11 = RegFileParser(param_1,(HKEY)0x0,param_3,(LPSTR)0x0);
        if ((int)uVar11 < 0) goto LAB_10013291;
        uVar11 = ParseToken(this,param_1);
joined_r0x10013224:
        if ((int)uVar11 < 0) goto LAB_10013291;
      }
LAB_10012cef:
      cVar2 = *param_1;
    } while( true );
  }
LAB_100132d9:
  local_8 = 0xffffffff;
  FUN_10013310((undefined4 *)&stack0xffffffec);
  ExceptionList = local_10;
  return 0x80020009;
}




======================================================================
// Function: FUN_100132f0 @ 100132f0
======================================================================

void __fastcall FUN_100132f0(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  return;
}




======================================================================
// Function: FUN_10013310 @ 10013310
======================================================================

LSTATUS __fastcall FUN_10013310(undefined4 *param_1)

{
  LSTATUS LVar1;
  
  LVar1 = 0;
  if ((HKEY)*param_1 != (HKEY)0x0) {
    LVar1 = RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  return LVar1;
}




======================================================================
// Function: FUN_10013330 @ 10013330
======================================================================

void __thiscall
FUN_10013330(void *this,HKEY param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4,REGSAM param_5,
            LPSECURITY_ATTRIBUTES param_6,undefined4 *param_7)

{
  LSTATUS LVar1;
  HKEY local_4;
  
  local_4 = (HKEY)0x0;
  LVar1 = RegCreateKeyExA(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_4,
                          (LPDWORD)&param_6);
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_6;
  }
  if (LVar1 == 0) {
    if (*(HKEY *)this != (HKEY)0x0) {
      RegCloseKey(*(HKEY *)this);
      *(undefined4 *)this = 0;
    }
    *(HKEY *)this = local_4;
  }
  return;
}




======================================================================
// Function: FUN_100133a0 @ 100133a0
======================================================================

void __thiscall FUN_100133a0(void *this,HKEY param_1,LPCSTR param_2,REGSAM param_3)

{
  LSTATUS LVar1;
  HKEY local_4;
  
  local_4 = (HKEY)0x0;
  LVar1 = RegOpenKeyExA(param_1,param_2,0,param_3,&local_4);
  if (LVar1 == 0) {
    if (*(HKEY *)this != (HKEY)0x0) {
      RegCloseKey(*(HKEY *)this);
      *(undefined4 *)this = 0;
    }
    *(HKEY *)this = local_4;
  }
  return;
}




======================================================================
// Function: FUN_100133f0 @ 100133f0
======================================================================

/* WARNING: Removing unreachable block (ram,0x10013451) */
/* WARNING: Removing unreachable block (ram,0x10013466) */
/* WARNING: Removing unreachable block (ram,0x10013474) */

LSTATUS __thiscall FUN_100133f0(undefined4 *param_1,LPCSTR param_2)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  HKEY local_124;
  DWORD local_120;
  HKEY local_11c;
  undefined4 *local_118;
  _FILETIME local_114;
  CHAR local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1002094b;
  local_c = ExceptionList;
  local_4 = 0;
  local_11c = (HKEY)0x0;
  ExceptionList = &local_c;
  local_118 = param_1;
  LVar1 = RegOpenKeyExA((HKEY)*param_1,param_2,0,0x2001f,&local_11c);
  hKey = local_11c;
  if (LVar1 == 0) {
    local_124 = local_11c;
    local_120 = 0x100;
    iVar2 = RegEnumKeyExA(local_11c,0,local_10c,&local_120,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                          &local_114);
    while (iVar2 == 0) {
      iVar2 = FUN_100133f0(local_10c);
      if (iVar2 != 0) {
        if (hKey == (HKEY)0x0) {
          ExceptionList = local_c;
          return iVar2;
        }
        RegCloseKey(hKey);
        ExceptionList = local_c;
        return iVar2;
      }
      local_120 = 0x100;
      iVar2 = RegEnumKeyExA(hKey,0,local_10c,&local_120,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                            &local_114);
      param_1 = local_118;
    }
    if (hKey != (HKEY)0x0) {
      RegCloseKey(hKey);
      local_124 = (HKEY)0x0;
    }
    LVar1 = RegDeleteKeyA((HKEY)*param_1,param_2);
    if (local_124 != (HKEY)0x0) {
      RegCloseKey(local_124);
    }
  }
  ExceptionList = local_c;
  return LVar1;
}




======================================================================
// Function: RegWriteValue @ 10013550
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint RegWriteValue(undefined4 *param_1,LPCSTR param_2,CHAR *param_3)

{
  BYTE BVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  LPSTR pCVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *this;
  LPCSTR pCVar9;
  uint uVar10;
  CHAR *pCVar11;
  undefined4 *puVar12;
  CHAR local_2014 [4096];
  BYTE local_1014 [4072];
  undefined4 uStackY_2c;
  HKEY hKey;
  DWORD dwType;
  BYTE *lpData;
  uint uVar13;
  
  FUN_1001a250();
  pCVar11 = local_2014;
  iVar4 = IsDelimiter(*(undefined1 *)*this);
  while (iVar4 != 0) {
    pCVar5 = CharNextA((LPCSTR)*this);
    *this = pCVar5;
    iVar4 = IsDelimiter(*pCVar5);
  }
  cVar3 = *(LPCSTR)*this;
  if (cVar3 != '\0') {
    if (cVar3 == '\'') {
      pCVar5 = CharNextA((LPCSTR)*this);
      *this = pCVar5;
      cVar3 = *pCVar5;
      while ((cVar3 != '\0' && (iVar4 = IsEscape(this), iVar4 == 0))) {
        if (*(LPCSTR)*this == '\'') {
          pCVar5 = CharNextA((LPCSTR)*this);
          *this = pCVar5;
        }
        pCVar9 = (LPCSTR)*this;
        pCVar5 = CharNextA(pCVar9);
        *this = pCVar5;
        if (local_1014 <= pCVar11 + 2) {
          return 0x80020009;
        }
        for (; pCVar9 < pCVar5; pCVar9 = pCVar9 + 1) {
          *pCVar11 = *pCVar9;
          pCVar11 = pCVar11 + 1;
        }
        cVar3 = *pCVar5;
      }
      pCVar9 = (LPCSTR)*this;
      if (*pCVar9 == '\0') {
        return 0x80020009;
      }
      *pCVar11 = '\0';
      pCVar5 = CharNextA(pCVar9);
      *this = pCVar5;
    }
    else {
      do {
        iVar4 = IsDelimiter(cVar3);
        if (iVar4 != 0) break;
        pCVar9 = (LPCSTR)*this;
        pCVar5 = CharNextA(pCVar9);
        *this = pCVar5;
        for (; pCVar9 < pCVar5; pCVar9 = pCVar9 + 1) {
          *pCVar11 = *pCVar9;
          pCVar11 = pCVar11 + 1;
        }
        cVar3 = *pCVar5;
      } while (cVar3 != '\0');
      *pCVar11 = '\0';
    }
    if ((DAT_1002546c & 1) == 0) {
      DAT_1002546c = DAT_1002546c | 1;
      DAT_100250cc = 8;
      DAT_100250c8 = PTR_DAT_100213e8;
      DAT_100250d0 = PTR_DAT_100213ec;
      _DAT_100250d4 = 0x13;
      _DAT_100250d8 = PTR_DAT_100213f0;
      _DAT_100250dc = 0x11;
    }
    iVar4 = 0;
    puVar12 = &DAT_100250c8;
    do {
      iVar6 = lstrcmpiA(local_2014,(LPCSTR)*puVar12);
      if (iVar6 == 0) {
        sVar2 = (&DAT_100250cc)[iVar4 * 4];
        goto LAB_100136dc;
      }
      puVar12 = puVar12 + 2;
      iVar4 = iVar4 + 1;
    } while (puVar12 < &DAT_100250e0);
  }
  return 0x80020009;
LAB_100136dc:
  do {
    switch(*(LPCSTR)*this) {
    case '\t':
    case '\n':
    case '\r':
    case ' ':
      pCVar5 = CharNextA((LPCSTR)*this);
      *this = pCVar5;
      break;
    default:
      goto switchD_100136f1_caseD_b;
    }
  } while( true );
switchD_100136f1_caseD_b:
  uVar7 = ParseToken(this,(CHAR *)local_1014);
  if ((int)uVar7 < 0) {
    return uVar7;
  }
  if (sVar2 == 8) {
    iVar4 = lstrlenA((LPCSTR)local_1014);
    uVar7 = iVar4 + 1;
    lpData = local_1014;
    hKey = (HKEY)*param_1;
    dwType = 1;
  }
  else if (sVar2 == 0x11) {
    lpData = &stack0xfffffff0;
    uVar8 = lstrlenA((LPCSTR)local_1014);
    if ((uVar8 & 1) != 0) {
      return 0x80004005;
    }
    uVar7 = (int)uVar8 / 2;
    uVar13 = 0x100137eb;
    FUN_1001a250();
    puVar12 = (undefined4 *)&stack0xfffffff0;
    for (uVar10 = uVar7 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    for (uVar10 = uVar7 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined1 *)puVar12 = 0;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    if (&stack0x00000000 == (undefined1 *)0x10) {
      return 0x80004005;
    }
    uVar10 = 0;
    if (0 < (int)uVar8) {
      do {
        BVar1 = local_1014[uVar10];
        switch(BVar1) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          cVar3 = BVar1 + 0xd0;
          break;
        default:
          cVar3 = '\0';
          break;
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
          cVar3 = BVar1 + 0xc9;
          break;
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
          cVar3 = BVar1 + 0xa9;
        }
        iVar4 = (int)uVar10 / 2;
        uVar7 = uVar10 & 1;
        uVar10 = uVar10 + 1;
        (&stack0xfffffff0)[iVar4] =
             (&stack0xfffffff0)[iVar4] | cVar3 << (4U - (char)(uVar7 << 2) & 0x1f);
        uVar7 = uVar13;
      } while ((int)uVar10 < (int)uVar8);
    }
    hKey = (HKEY)*param_1;
    dwType = 3;
  }
  else {
    if (sVar2 != 0x13) goto LAB_100138c7;
    if (&stack0x00000000 != (undefined1 *)0x1014) {
      iVar4 = lstrlenA((LPCSTR)local_1014);
      FUN_1001a250();
      uStackY_2c = 0x1001377f;
      MultiByteToWideChar(0,0,(LPCSTR)local_1014,-1,(LPWSTR)&stack0xfffffff0,iVar4 + 1);
    }
    Ordinal_277();
    lpData = &stack0xfffffff8;
    uVar7 = 4;
    hKey = (HKEY)*param_1;
    dwType = 4;
  }
  uStackY_2c = 0x100138c7;
  RegSetValueExA(hKey,param_2,0,dwType,lpData,uVar7);
LAB_100138c7:
  uVar7 = ParseToken(this,param_3);
  return uVar7 & (-1 < (int)uVar7) - 1;
}




======================================================================
// Function: FUN_10013960 @ 10013960
======================================================================

bool FUN_10013960(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_4;
  
  local_4 = 0;
  LVar1 = RegQueryInfoKeyA(param_1,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_4,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar1 < 0) {
    return false;
  }
  return local_4 != 0;
}




======================================================================
// Function: Reg_QueryKeyInfo @ 100139b0
======================================================================

/* WARNING: Removing unreachable block (ram,0x10013a03) */
/* WARNING: Removing unreachable block (ram,0x10013a2a) */
/* WARNING: Removing unreachable block (ram,0x10013a32) */

undefined4 Reg_QueryKeyInfo(DWORD param_1,char param_2)

{
  LSTATUS LVar1;
  HKEY in_stack_0000100c;
  
  FUN_1001a250();
  LVar1 = RegQueryInfoKeyA(in_stack_0000100c,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)&stack0x00000000,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
  if (LVar1 != 0) {
    return 0;
  }
  return 0;
}




======================================================================
// Function: Reg_ParseConfigValue @ 10013a60
======================================================================

int Reg_ParseConfigValue(void)

{
  CHAR CVar1;
  char cVar2;
  int iVar3;
  LPSTR pCVar4;
  LPCSTR pCVar5;
  undefined4 *this;
  CHAR *pCVar6;
  CHAR *in_stack_00001004;
  
  FUN_1001a250();
  if (*in_stack_00001004 != '=') {
    return 0;
  }
  iVar3 = IsDelimiter(*(undefined1 *)*this);
  while (iVar3 != 0) {
    pCVar4 = CharNextA((LPCSTR)*this);
    *this = pCVar4;
    iVar3 = IsDelimiter(*pCVar4);
  }
  cVar2 = *(LPCSTR)*this;
  if (cVar2 != '\0') {
    pCVar6 = in_stack_00001004;
    if (cVar2 != '\'') {
      do {
        iVar3 = IsDelimiter(cVar2);
        if (iVar3 != 0) break;
        pCVar5 = (LPCSTR)*this;
        pCVar4 = CharNextA(pCVar5);
        *this = pCVar4;
        if (pCVar5 < pCVar4) {
          do {
            CVar1 = *pCVar5;
            pCVar5 = pCVar5 + 1;
            *pCVar6 = CVar1;
            pCVar6 = pCVar6 + 1;
          } while (pCVar5 < (LPCSTR)*this);
        }
        cVar2 = *(char *)*this;
      } while (cVar2 != '\0');
      *pCVar6 = '\0';
      goto LAB_10013b2b;
    }
    pCVar4 = CharNextA((LPCSTR)*this);
    *this = pCVar4;
    cVar2 = *pCVar4;
    while ((cVar2 != '\0' &&
           ((*(LPCSTR)*this != '\'' || (pCVar4 = CharNextA((LPCSTR)*this), *pCVar4 == '\''))))) {
      if (*(LPCSTR)*this == '\'') {
        pCVar4 = CharNextA((LPCSTR)*this);
        *this = pCVar4;
      }
      pCVar5 = (LPCSTR)*this;
      pCVar4 = CharNextA(pCVar5);
      *this = pCVar4;
      if (in_stack_00001004 + 0x1000 <= pCVar6 + 2) {
        return -0x7ffdfff7;
      }
      if (pCVar5 < pCVar4) {
        do {
          CVar1 = *pCVar5;
          pCVar5 = pCVar5 + 1;
          *pCVar6 = CVar1;
          pCVar6 = pCVar6 + 1;
        } while (pCVar5 < (LPCSTR)*this);
      }
      cVar2 = *(char *)*this;
    }
    if (*(char *)*this != '\0') {
      *pCVar6 = '\0';
      pCVar5 = (LPCSTR)*this;
      do {
        pCVar4 = CharNextA(pCVar5);
        *this = pCVar4;
LAB_10013b2b:
        pCVar5 = (LPCSTR)*this;
        switch(*pCVar5) {
        case '\t':
        case '\n':
        case '\r':
        case ' ':
          break;
        default:
          iVar3 = ParseToken(this,&stack0x00000000);
          if (iVar3 < 0) {
            return iVar3;
          }
          iVar3 = ParseToken(this,in_stack_00001004);
          if (-1 < iVar3) {
            return 0;
          }
          return iVar3;
        }
      } while( true );
    }
  }
  return -0x7ffdfff7;
}




======================================================================
// Function: Util_RegisterClass @ 10013be0
======================================================================

int Util_RegisterClass(undefined4 param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  HRESULT HVar3;
  int iVar4;
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10020968;
  local_c = ExceptionList;
  local_20 = (int *)0x0;
  local_4 = 0;
  if (param_2 != (int *)0x0) {
    ExceptionList = &local_c;
    HVar3 = CoCreateInstance((IID *)&DAT_10021c90,(LPUNKNOWN)0x0,1,(IID *)&DAT_10021ca0,&local_20);
    if (-1 < HVar3) {
      iVar4 = *param_2;
      while (iVar4 != 0) {
        puVar2 = (undefined4 *)param_2[1];
        local_1c = *puVar2;
        local_18 = puVar2[1];
        local_14 = puVar2[2];
        local_10 = puVar2[3];
        if (param_3 == 0) {
          if (*param_2 == 1) {
            (**(code **)(*local_20 + 0x18))();
          }
          else {
            (**(code **)(*local_20 + 0x20))(local_20,param_1,1,&local_1c);
          }
        }
        else {
          if (*param_2 == 1) {
            iVar4 = (**(code **)(*local_20 + 0x14))();
          }
          else {
            iVar4 = (**(code **)(*local_20 + 0x1c))(local_20,param_1,1,&local_1c);
          }
          if (iVar4 < 0) {
            local_4 = 0xffffffff;
            if (local_20 == (int *)0x0) {
              ExceptionList = local_c;
              return iVar4;
            }
            (**(code **)(*local_20 + 8))(local_20);
            ExceptionList = local_c;
            return iVar4;
          }
        }
        piVar1 = param_2 + 2;
        param_2 = param_2 + 2;
        iVar4 = *piVar1;
      }
    }
    if (local_20 != (int *)0x0) {
      local_4 = 0xffffffff;
      (**(code **)(*local_20 + 8))(local_20);
    }
  }
  ExceptionList = local_c;
  return 0;
}




======================================================================
// Function: Unregister_Server @ 10013d10
======================================================================

int Unregister_Server(int param_1,LPCWSTR param_2)

{
  LPCWSTR pWVar1;
  int iVar2;
  LPSTR lpString2;
  LPCSTR lpsz;
  int iVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  undefined2 uVar5;
  LPWSTR pWVar6;
  LPCSTR lpString1;
  LPWSTR pWVar7;
  char local_128 [272];
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10020990;
  local_10 = ExceptionList;
  local_8 = 1;
  local_18 = 0;
  local_14 = (int *)0x0;
  ExceptionList = &local_10;
  GetModuleFileNameA(*(HMODULE *)(param_1 + 0xc),local_128,0x104);
  pWVar1 = param_2;
  if (param_2 != (LPCWSTR)0x0) {
    iVar2 = lstrlenW(param_2);
    FUN_1001a250();
    lpString2 = FUN_10013f50(&stack0xfffffecc,pWVar1,iVar2 * 2 + 2,0);
    lstrcatA(local_128,lpString2);
  }
  if (&stack0x00000000 == (undefined1 *)0x128) {
    pWVar6 = (LPWSTR)0x0;
  }
  else {
    iVar2 = lstrlenA(local_128);
    FUN_1001a250();
    pWVar6 = FUN_10013f20((LPWSTR)&stack0xfffffecc,local_128,iVar2 + 1,0);
  }
  pWVar7 = (LPWSTR)&stack0xfffffec4;
  iVar2 = Ordinal_161();
  if (iVar2 < 0) {
    lpString1 = (LPCSTR)0x0;
    lpsz = local_128;
    if (local_128[0] == '\0') {
LAB_10013e12:
      lpString1 = lpsz;
    }
    else {
      do {
        if (local_128[0] == '.') {
          lpString1 = lpsz;
        }
        lpsz = CharNextA(lpsz);
        local_128[0] = *lpsz;
      } while (local_128[0] != '\0');
      if (lpString1 == (LPCSTR)0x0) goto LAB_10013e12;
    }
    lstrcpyA(lpString1,&DAT_100242d8);
    if (&stack0x00000000 == (undefined1 *)0x128) {
      pWVar7 = (LPWSTR)0x0;
    }
    else {
      iVar2 = lstrlenA(local_128);
      FUN_1001a250();
      MultiByteToWideChar(0,0,local_128,-1,(LPWSTR)&stack0xfffffec4,iVar2 + 1);
    }
    iVar2 = Ordinal_161(pWVar7,&local_14);
    pWVar6 = pWVar7;
    if (iVar2 < 0) goto LAB_10013ee2;
  }
  local_18 = Ordinal_2(pWVar6);
  if ((-1 < iVar2) && (iVar3 = (**(code **)(*local_14 + 0x1c))(local_14,&param_1), -1 < iVar3)) {
    hModule = LoadLibraryA(s_oleaut32_dll_100242c8);
    if (hModule != (HMODULE)0x0) {
      pFVar4 = GetProcAddress(hModule,s_UnRegisterTypeLib_100242b4);
      if (pFVar4 != (FARPROC)0x0) {
        uVar5 = (undefined2)((uint)*(undefined4 *)(param_1 + 0x10) >> 0x10);
        (*pFVar4)(param_1,CONCAT22(uVar5,*(undefined2 *)(param_1 + 0x18)),
                  CONCAT22(uVar5,*(undefined2 *)(param_1 + 0x1a)),*(undefined4 *)(param_1 + 0x10),
                  *(undefined4 *)(param_1 + 0x14));
      }
      FreeLibrary(hModule);
    }
    (**(code **)(*local_14 + 0x30))(local_14,param_1);
  }
LAB_10013ee2:
  local_8 = local_8 & 0xffffff00;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar2;
}




======================================================================
// Function: FUN_10013f20 @ 10013f20
======================================================================

LPWSTR FUN_10013f20(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

{
  *param_1 = L'\0';
  MultiByteToWideChar(param_4,0,param_2,-1,param_1,param_3);
  return param_1;
}




======================================================================
// Function: FUN_10013f50 @ 10013f50
======================================================================

LPSTR FUN_10013f50(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

{
  *param_1 = '\0';
  WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
  return param_1;
}




======================================================================
// Function: Register_Server @ 10013f80
======================================================================

int Register_Server(int param_1,LPCWSTR param_2)

{
  int iVar1;
  LPSTR lpString2;
  LPCSTR lpsz;
  uint uVar2;
  uint uVar3;
  LPWSTR pWVar4;
  LPCSTR lpString1;
  LPCWSTR pWVar5;
  short *psVar6;
  short local_220 [124];
  char local_128 [272];
  int *local_18;
  LPCWSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100209b0;
  local_10 = ExceptionList;
  local_8 = 1;
  local_14 = (LPCWSTR)0x0;
  local_18 = (int *)0x0;
  ExceptionList = &local_10;
  GetModuleFileNameA(*(HMODULE *)(param_1 + 0xc),local_128,0x104);
  if (param_2 != (LPCWSTR)0x0) {
    iVar1 = lstrlenW(param_2);
    FUN_1001a250();
    lpString2 = FUN_10013f50(&stack0xfffffdd4,param_2,iVar1 * 2 + 2,0);
    lstrcatA(local_128,lpString2);
  }
  if (&stack0x00000000 == (undefined1 *)0x128) {
    pWVar4 = (LPWSTR)0x0;
  }
  else {
    iVar1 = lstrlenA(local_128);
    FUN_1001a250();
    pWVar4 = FUN_10013f20((LPWSTR)&stack0xfffffdd4,local_128,iVar1 + 1,0);
  }
  iVar1 = Ordinal_161();
  if (iVar1 < 0) {
    lpString1 = (LPCSTR)0x0;
    lpsz = local_128;
    if (local_128[0] == '\0') {
LAB_1001407f:
      lpString1 = lpsz;
    }
    else {
      do {
        if (local_128[0] == '.') {
          lpString1 = lpsz;
        }
        lpsz = CharNextA(lpsz);
        local_128[0] = *lpsz;
      } while (local_128[0] != '\0');
      if (lpString1 == (LPCSTR)0x0) goto LAB_1001407f;
    }
    lstrcpyA(lpString1,&DAT_100242d8);
    if (&stack0x00000000 == (undefined1 *)0x128) {
      pWVar4 = (LPWSTR)0x0;
    }
    else {
      iVar1 = lstrlenA(local_128);
      FUN_1001a250();
      pWVar4 = FUN_10013f20((LPWSTR)&stack0xfffffdcc,local_128,iVar1 + 1,0);
    }
    iVar1 = Ordinal_161(pWVar4,&local_18);
    if (iVar1 < 0) goto LAB_100140e6;
  }
  local_14 = (LPCWSTR)Ordinal_2(pWVar4);
LAB_100140e6:
  if (-1 < iVar1) {
    iVar1 = lstrlenW(local_14);
    uVar3 = iVar1 * 2 + 2;
    pWVar5 = local_14;
    psVar6 = local_220;
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)psVar6 = *(undefined4 *)pWVar5;
      pWVar5 = pWVar5 + 2;
      psVar6 = psVar6 + 2;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)psVar6 = (char)*pWVar5;
      pWVar5 = (LPCWSTR)((int)pWVar5 + 1);
      psVar6 = (short *)((int)psVar6 + 1);
    }
    iVar1 = Str_FindFileNameW(local_220);
    pWVar5 = local_14;
    local_220[iVar1] = 0;
    iVar1 = Ordinal_163(local_18,pWVar5,local_220);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return iVar1;
}




======================================================================
// Function: Str_FindFileNameW @ 10014180
======================================================================

int Str_FindFileNameW(short *param_1)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  sVar1 = *param_1;
  psVar2 = param_1;
  psVar3 = param_1;
  while (sVar1 != 0) {
    sVar1 = *psVar3;
    if (sVar1 != 0) {
      psVar3 = psVar3 + 1;
    }
    if (((sVar1 == 0x5c) || (sVar1 == 0x2f)) || (sVar1 == 0x3a)) {
      psVar2 = psVar3;
    }
    sVar1 = *psVar3;
  }
  return (int)psVar2 - (int)param_1 >> 1;
}




======================================================================
// Function: FUN_100141c0 @ 100141c0
======================================================================

void FUN_100141c0(void)

{
  return;
}




======================================================================
// Function: FUN_10014260 @ 10014260
======================================================================

int * __thiscall FUN_10014260(void *this,undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 extraout_var;
  int *unaff_EBP;
  int *piVar6;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piStack_28;
  int iStack_24;
  int *piStack_20;
  int *local_1c;
  int *local_10;
  void *local_c;
  uint *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = (uint *)&LAB_100209eb;
  local_c = ExceptionList;
  if (*(int *)((int)this + 0xc) == 0) {
    local_1c = (int *)0x80004005;
    ExceptionList = &local_c;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002505c);
    if ((*(int *)((int)this + 0xc) == 0) &&
       (local_1c = (int *)Ordinal_162(*(undefined4 *)((int)this + 4),
                                      CONCAT22((short)((uint)&local_10 >> 0x10),
                                               *(undefined2 *)((int)this + 8)),
                                      CONCAT22(extraout_var,*(undefined2 *)((int)this + 10)),param_1
                                      ,&local_10), -1 < (int)local_1c)) {
      piStack_28 = (int *)0x0;
      uStack_4 = 0;
      piStack_28 = (int *)(**(code **)(*local_10 + 0x18))(local_10,*(undefined4 *)this,&piStack_28);
      if (-1 < (int)piStack_28) {
        piStack_20 = unaff_EBP;
        if (unaff_EBP != (int *)0x0) {
          (**(code **)(*unaff_EBP + 4))(unaff_EBP);
        }
        local_10 = (int *)CONCAT31(local_10._1_3_,2);
        iVar2 = (**(code **)*unaff_EBP)(unaff_EBP,&DAT_100242e0,&stack0xffffffd4);
        piVar6 = unaff_EBP;
        piVar10 = (int *)0x0;
        if (-1 < iVar2) {
          if (unaff_EDI != (int *)0x0) {
            (**(code **)(*unaff_EDI + 4))(unaff_EDI);
          }
          piVar6 = unaff_EDI;
          piVar10 = unaff_EDI;
          if (unaff_EBP != (int *)0x0) {
            (**(code **)(*unaff_EBP + 8))(unaff_EBP);
          }
        }
        iVar2 = (**(code **)(*piVar6 + 0xc))(piVar6,&stack0xffffffd0);
        if (-1 < iVar2) {
          uVar7 = (uint)*(ushort *)(iStack_24 + 0x2c);
          *(uint *)((int)this + 0x18) = uVar7;
          if (uVar7 == 0) {
            puVar3 = (uint *)0x0;
          }
          else {
            puStack_8 = operator_new(uVar7 * 0xc + 4);
            local_10._0_1_ = 3;
            if (puStack_8 == (uint *)0x0) {
              puVar3 = (uint *)0x0;
            }
            else {
              puVar3 = puStack_8 + 1;
              *puStack_8 = uVar7;
              FUN_1001a3ce(puVar3,0xc,uVar7,&LAB_100145a0);
            }
            local_10 = (int *)CONCAT31(local_10._1_3_,2);
          }
          iVar2 = 0;
          *(uint **)((int)this + 0x14) = puVar3;
          if (0 < *(int *)((int)this + 0x18)) {
            iVar8 = 0;
            do {
              iVar4 = (**(code **)(*piVar6 + 0x14))(piVar6,iVar2,&stack0xffffffd0);
              if (-1 < iVar4) {
                puStack_8 = (uint *)0x0;
                puVar9 = (undefined4 *)0x0;
                local_10 = (int *)CONCAT31(local_10._1_3_,4);
                iVar4 = (**(code **)(*piVar6 + 0x30))(piVar6,*unaff_ESI,&puStack_8,0,0);
                piVar1 = piStack_20;
                if (-1 < iVar4) {
                  piStack_20 = (int *)0x0;
                  *(int **)(iVar8 + *(int *)((int)this + 0x14)) = piVar1;
                  uVar5 = Ordinal_7(*(undefined4 *)(iVar8 + *(int *)((int)this + 0x14)));
                  *(undefined4 *)(iVar8 + 4 + *(int *)((int)this + 0x14)) = uVar5;
                  *(undefined4 *)(iVar8 + 8 + *(int *)((int)this + 0x14)) = *puVar9;
                }
                (**(code **)(*piVar6 + 0x50))(piVar6,puVar9);
                unaff_ESI = (undefined4 *)CONCAT31((int3)((uint)unaff_ESI >> 8),2);
                Ordinal_6(piStack_28);
              }
              iVar2 = iVar2 + 1;
              iVar8 = iVar8 + 0xc;
            } while (iVar2 < *(int *)((int)this + 0x18));
          }
          (**(code **)(*piVar6 + 0x4c))(piVar6,iStack_24);
        }
        piStack_20 = (int *)0x0;
        *(int **)((int)this + 0xc) = piVar6;
        local_10._0_1_ = 1;
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 8))(piVar10);
        }
        local_10 = (int *)((uint)local_10._1_3_ << 8);
      }
      (**(code **)(*local_1c + 8))(local_1c);
      uStack_4 = 0xffffffff;
      if (piStack_28 != (int *)0x0) {
        (**(code **)(*piStack_28 + 8))(piStack_28);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002505c);
    puVar9 = operator_new(0xc);
    if (puVar9 != (undefined4 *)0x0) {
      *puVar9 = FUN_10014540;
      puVar9[1] = this;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002505c);
      puVar9[2] = DAT_100250c0;
      DAT_100250c0 = puVar9;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002505c);
    }
    ExceptionList = local_c;
    return local_1c;
  }
  return (int *)0x0;
}




======================================================================
// Function: FUN_10014530 @ 10014530
======================================================================

void __fastcall FUN_10014530(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}




======================================================================
// Function: FUN_10014540 @ 10014540
======================================================================

void FUN_10014540(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  iVar2 = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (iVar2 != 0) {
    FUN_10019bf5(iVar2,0xc,*(int *)(iVar2 + -4),FUN_10001e40);
    Mem_FreeObj((LPVOID)(iVar2 + -4));
    *(undefined4 *)(param_1 + 0x14) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}




======================================================================
// Function: Motion_UpdateAll @ 10014690
======================================================================

undefined4 Motion_UpdateAll(int *param_1)

{
  int iVar1;
  longlong lVar2;
  
  if (param_1[0x326e] == 0) {
    return 0;
  }
  param_1[0x3240] = param_1[0x326c];
  do {
    (**(code **)(*param_1 + 0x25c))(param_1);
    iVar1 = param_1[0x3240];
    lVar2 = __ftol();
    param_1[iVar1 * 0x7b + 0xc58] = param_1[iVar1 * 0x7b + 0xc58] + (int)lVar2;
    if (200 < param_1[param_1[0x3240] * 0x7b + 0xc58]) {
      param_1[param_1[0x3240] * 0x7b + 0xc58] = 200;
      param_1[param_1[0x3240] * 0x38 + 0x2a] = (int)-(float)param_1[param_1[0x3240] * 0x38 + 0x2a];
    }
    if (param_1[param_1[0x3240] * 0x7b + 0xc58] < 0) {
      param_1[param_1[0x3240] * 0x7b + 0xc58] = 0;
      param_1[param_1[0x3240] * 0x38 + 0x2a] = (int)-(float)param_1[param_1[0x3240] * 0x38 + 0x2a];
    }
    param_1[param_1[0x3240] * 0x7b + 0xc35] = 2;
    iVar1 = param_1[0x3240];
    param_1[0x3240] = iVar1 + 1U;
  } while (iVar1 + 1U < (uint)param_1[0x3294]);
  return 0;
}




======================================================================
// Function: IterateActivePresets @ 10014870
======================================================================

undefined4 IterateActivePresets(int *param_1)

{
  int iVar1;
  
  param_1[0x3240] = 0;
  do {
    if (param_1[param_1[0x3240] * 0x7b + 0xc31] != -1) {
      (**(code **)(*param_1 + 0xc0))(param_1);
    }
    iVar1 = param_1[0x3240];
    param_1[0x3240] = iVar1 + 1U;
  } while (iVar1 + 1U < (uint)param_1[0x32a1]);
  return 0;
}




======================================================================
// Function: State_SetDefaults @ 10014e80
======================================================================

undefined4 State_SetDefaults(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  longlong lVar8;
  
  *(undefined4 *)(param_1 + 0xc814) =
       *(undefined4 *)(param_1 + 0x30ec + *(int *)(param_1 + 0xc900) * 0x1ec);
  iVar4 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  lVar8 = __ftol();
  *(int *)(param_1 + 0xcdb4) = (int)lVar8;
  *(undefined4 *)(param_1 + 0xcf70) = *(undefined4 *)(iVar4 + 0x313c);
  *(int *)(param_1 + 0xd040) = *(int *)(iVar4 + 0x3150) * *(int *)(iVar4 + 0x314c);
  *(undefined4 *)(param_1 + 0xcd5c) = *(undefined4 *)(iVar4 + 0x30ec);
  if (*(int *)(iVar4 + 0x317c) == 1) {
    iVar4 = *(int *)(iVar4 + 0x3180);
    if (iVar4 == 0) {
      return 0;
    }
  }
  else {
    if (*(int *)(iVar4 + 0x317c) != 2) goto LAB_10014f2a;
    iVar4 = *(int *)(iVar4 + 0x3264);
    if (iVar4 == 0) {
      return 0;
    }
  }
  *(int *)(param_1 + 0xcd5c) = iVar4;
LAB_10014f2a:
  puVar6 = *(uint **)(param_1 + 0xcd5c);
  puVar7 = *(uint **)(param_1 + 0xc814);
  iVar4 = *(int *)(param_1 + 0xd040);
  uVar1 = *(uint *)(param_1 + 0xcf70);
  uVar5 = *(uint *)(param_1 + 0xcdb4);
  uVar5 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  do {
    uVar2 = *puVar6;
    uVar3 = uVar2;
    if ((uVar2 != uVar1) && (uVar3 = uVar2 + uVar5, CARRY4(uVar2,uVar5))) {
      uVar3 = uVar1;
    }
    *puVar7 = uVar3;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(param_1 + 0x317c + *(int *)(param_1 + 0xc900) * 0x1ec) = 0;
  return 0;
}




======================================================================
// Function: Effect_RunPipeline @ 10014f90
======================================================================

undefined4 Effect_RunPipeline(int *param_1)

{
  (**(code **)(*param_1 + 0x200))(param_1);
  (**(code **)(*param_1 + 0x214))(param_1);
  (**(code **)(*param_1 + 0x210))(param_1);
  (**(code **)(*param_1 + 0x204))(param_1);
  (**(code **)(*param_1 + 0x218))(param_1);
  (**(code **)(*param_1 + 0x20c))(param_1);
  return 0;
}




======================================================================
// Function: Audio_RotateSpectrumBuffers @ 100151e0
======================================================================

undefined4 Audio_RotateSpectrumBuffers(int param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  uint *puVar11;
  bool bVar12;
  
  iVar5 = *(int *)(param_1 + 0xc924);
  if (iVar5 == 0xff) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0xc8e4);
  if (iVar4 == 0) {
    iVar4 = param_1 + 0x9ba8;
  }
  else {
    if (iVar4 == 1) {
      *(undefined4 *)(param_1 + 0xc8e4) = 2;
      *(int *)(param_1 + 0xc858) = param_1 + 0xa3c8;
      *(int *)(param_1 + 0xc818) = param_1 + 0xabe8;
      goto LAB_10015261;
    }
    if (iVar4 != 2) {
      return 0;
    }
    iVar4 = param_1 + 0xabe8;
  }
  *(int *)(param_1 + 0xc858) = iVar4;
  *(int *)(param_1 + 0xc818) = param_1 + 0xa3c8;
  *(undefined4 *)(param_1 + 0xc8e4) = 1;
LAB_10015261:
  if (iVar5 < 0xff) {
    iVar5 = *(int *)(param_1 + 0xc8ec);
    *(undefined4 *)(param_1 + 0xc8ec) = 0;
    uVar6 = 0x100 - *(int *)(param_1 + 0xc924);
    uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
            *(int *)(param_1 + 0xc924) * -0x1000000;
    puVar8 = *(undefined4 **)(param_1 + 0xc858);
    puVar10 = *(undefined4 **)(param_1 + 0xc818);
    uVar7 = 0;
    do {
      *(int *)(param_1 + 0xc8ec) = *(int *)(param_1 + 0xc8ec) + 1;
      *puVar10 = *puVar8;
      puVar10 = puVar10 + 1;
      do {
        puVar8 = puVar8 + 1;
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) {
          return 0;
        }
        bVar12 = CARRY4(uVar7,uVar6);
        uVar7 = uVar7 + uVar6;
      } while (bVar12);
    } while( true );
  }
  if (*(int *)(param_1 + 0xc8ec) < 0x200) {
    if (0x200 < iVar5) {
      *(undefined4 *)(param_1 + 0xc924) = 0x200;
    }
    if (*(int *)(param_1 + 0xc924) < 0x201) {
      iVar5 = *(int *)(param_1 + 0xc8ec);
      *(undefined4 *)(param_1 + 0xc8ec) = 0;
      uVar6 = 0x200 - *(int *)(param_1 + 0xc924);
      uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
              *(int *)(param_1 + 0xc924) * -0x1000000;
      uVar7 = 0;
      puVar2 = *(uint **)(param_1 + 0xc858);
      puVar3 = *(uint **)(param_1 + 0xc818);
      while (puVar11 = puVar3, puVar9 = puVar2,
            *(int *)(param_1 + 0xc8ec) = *(int *)(param_1 + 0xc8ec) + 1,
            *(uint *)(param_1 + 0xc8ec) < 0x200) {
        uVar1 = *puVar9;
        *puVar11 = uVar1;
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) {
          return 0;
        }
        bVar12 = CARRY4(uVar7,uVar6);
        uVar7 = uVar7 + uVar6;
        puVar2 = puVar9 + 1;
        puVar3 = puVar11 + 1;
        if (!bVar12) {
          *(int *)(param_1 + 0xc8ec) = *(int *)(param_1 + 0xc8ec) + 1;
          if (0x1ff < *(uint *)(param_1 + 0xc8ec)) {
            return 0;
          }
          puVar11[1] = uVar1 + puVar9[2] >> 1;
          puVar3 = puVar11 + 2;
        }
      }
    }
  }
  return 0;
}




======================================================================
// Function: State_ResetAudio @ 10015360
======================================================================

undefined4 State_ResetAudio(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  if ((*(int *)(param_1 + 0xc918) != 0) &&
     (*(undefined4 *)(param_1 + 0xca18) = 0, 0 < *(int *)(param_1 + 0xc8ec))) {
    do {
      iVar4 = *(int *)(param_1 + 0xc918);
      uVar1 = *(undefined4 *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xca18) * 4);
      *(undefined4 *)(param_1 + 0xca3c) = 0;
      *(undefined4 *)(param_1 + 0xcd84) = uVar1;
      if (-1 < iVar4) {
        do {
          iVar3 = *(int *)(param_1 + 0xca18);
          iVar2 = *(int *)(param_1 + 0xca3c) + iVar3;
          *(int *)(param_1 + 0xca1c) = iVar2;
          if (*(int *)(param_1 + 0xc8ec) <= iVar2) {
            *(int *)(param_1 + 0xca1c) = *(int *)(param_1 + 0xc8ec) + -1;
          }
          iVar2 = *(int *)(param_1 + 0xcd84) +
                  *(int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xca1c) * 4);
          *(int *)(param_1 + 0xcd84) = iVar2;
          if (iVar3 == 0 || iVar2 != 0) {
            iVar2 = iVar2 / (iVar4 + 1);
          }
          else {
            lVar5 = __ftol();
            iVar2 = (int)lVar5;
            *(int *)(param_1 + 0xcd84) = iVar2;
          }
          *(int *)(param_1 + 0x9ba8 + iVar3 * 4) = iVar2;
          iVar3 = *(int *)(param_1 + 0xca3c) + 1;
          *(int *)(param_1 + 0xca3c) = iVar3;
          iVar4 = *(int *)(param_1 + 0xc918);
        } while (iVar3 <= iVar4);
      }
      if (0xff < *(int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xca18) * 4)) {
        *(undefined4 *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xca18) * 4) = 0xff;
      }
      iVar4 = *(int *)(param_1 + 0xca18) + 1;
      *(int *)(param_1 + 0xca18) = iVar4;
    } while (iVar4 < *(int *)(param_1 + 0xc8ec));
  }
  return 0;
}




======================================================================
// Function: State_ResetAll @ 10015550
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 State_ResetAll(int param_1)

{
  int iVar1;
  longlong lVar2;
  
  if (*(int *)(param_1 + 0xc928) != 0) {
    if (100 < *(int *)(param_1 + 0xc928)) {
      *(undefined4 *)(param_1 + 0xc928) = 100;
    }
    if (*(int *)(param_1 + 0xc928) < 0) {
      *(undefined4 *)(param_1 + 0xc928) = 0;
    }
    *(undefined4 *)(param_1 + 0xca18) = 0;
    *(float *)(param_1 + 0xc9ec) = (float)*(int *)(param_1 + 0xc928) * _DAT_10021334;
    *(float *)(param_1 + 0xc9e8) = (float)(100 - *(int *)(param_1 + 0xc928)) * _DAT_10021334;
    if (-1 < *(int *)(param_1 + 0xc8ec)) {
      do {
        iVar1 = *(int *)(param_1 + 0xca18);
        lVar2 = __ftol();
        *(int *)(param_1 + 0x9ba8 + iVar1 * 4) = (int)lVar2;
        *(undefined4 *)(param_1 + 0xb408 + *(int *)(param_1 + 0xca18) * 4) =
             *(undefined4 *)
              (param_1 + 0x9ba8 +
              (*(int *)(param_1 + 0xca18) + *(int *)(param_1 + 0xc8e4) * 0x208) * 4);
        iVar1 = *(int *)(param_1 + 0xca18) + 1;
        *(int *)(param_1 + 0xca18) = iVar1;
      } while (iVar1 <= *(int *)(param_1 + 0xc8ec));
    }
  }
  return 0;
}




======================================================================
// Function: InitAllVisParams @ 10015640
======================================================================

undefined4 InitAllVisParams(int param_1)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0xd038) = 0x36;
  *(undefined4 *)(param_1 + 0xca84) = 0x37;
  *(undefined4 *)(param_1 + 0xc900) = 0;
  do {
    *(undefined4 *)(param_1 + 0xca18) = 0;
    do {
      *(undefined4 *)
       (param_1 + 0x30c4 + (*(int *)(param_1 + 0xc900) * 0x7b + *(int *)(param_1 + 0xca18)) * 4) = 0
      ;
      iVar2 = *(int *)(param_1 + 0xca18) + 1;
      *(int *)(param_1 + 0xca18) = iVar2;
    } while (iVar2 < 0x7b);
    *(undefined4 *)(param_1 + 0xca3c) = 0;
    do {
      *(undefined4 *)
       (param_1 + 0xa4 + (*(int *)(param_1 + 0xca3c) + *(int *)(param_1 + 0xc900) * 0x38) * 4) = 0;
      iVar2 = *(int *)(param_1 + 0xca3c) + 1;
      *(int *)(param_1 + 0xca3c) = iVar2;
    } while (iVar2 < 0x38);
    uVar3 = *(int *)(param_1 + 0xc900) + 1;
    *(uint *)(param_1 + 0xc900) = uVar3;
  } while (uVar3 <= *(uint *)(param_1 + 0xd038));
  *(undefined4 *)(param_1 + 0xca18) = 0;
  do {
    *(undefined4 *)(param_1 + 0xc7a8 + *(int *)(param_1 + 0xca18) * 4) = 0;
    iVar2 = *(int *)(param_1 + 0xca18) + 1;
    *(int *)(param_1 + 0xca18) = iVar2;
  } while (iVar2 < 10);
  *(undefined4 *)(param_1 + 0xca18) = 0;
  do {
    *(undefined4 *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xca18) * 4) = 0;
    iVar2 = *(int *)(param_1 + 0xca18) + 1;
    *(int *)(param_1 + 0xca18) = iVar2;
  } while (iVar2 < 0x208);
  *(undefined4 *)(param_1 + 0xca18) = 0;
  do {
    *(undefined4 *)(param_1 + 0xa3c8 + *(int *)(param_1 + 0xca18) * 4) = 0;
    iVar2 = *(int *)(param_1 + 0xca18) + 1;
    *(int *)(param_1 + 0xca18) = iVar2;
  } while (iVar2 < 0x208);
  *(undefined4 *)(param_1 + 0xca18) = 0;
  do {
    *(undefined4 *)(param_1 + 0xabe8 + *(int *)(param_1 + 0xca18) * 4) = 0;
    iVar2 = *(int *)(param_1 + 0xca18) + 1;
    *(int *)(param_1 + 0xca18) = iVar2;
  } while (iVar2 < 0x208);
  *(undefined4 *)(param_1 + 0xca18) = 0;
  do {
    *(undefined4 *)(param_1 + 0x9a78 + *(int *)(param_1 + 0xca18) * 4) = 0;
    iVar2 = *(int *)(param_1 + 0xca18) + 1;
    *(int *)(param_1 + 0xca18) = iVar2;
  } while (iVar2 < 9);
  *(undefined4 *)(param_1 + 0xc768) = 0x11;
  *(undefined4 *)(param_1 + 0xc76c) = 0x34;
  *(undefined4 *)(param_1 + 0xc770) = 0x82;
  *(undefined4 *)(param_1 + 0xc774) = 0x87;
  *(undefined4 *)(param_1 + 0xc778) = 0xc0;
  *(undefined4 *)(param_1 + 0xc77c) = 0xc5;
  *(undefined4 *)(param_1 + 0xc780) = 0xe1;
  *(undefined4 *)(param_1 + 0xc784) = 0xe6;
  *(undefined4 *)(param_1 + 0xc788) = 0xed;
  *(undefined4 *)(param_1 + 0xc78c) = 0x9a;
  *(undefined4 *)(param_1 + 0xc790) = 0xec;
  *(undefined4 *)(param_1 + 0xc794) = 0x9a;
  *(undefined4 *)(param_1 + 0xc798) = 0x93;
  *(undefined4 *)(param_1 + 0xc79c) = 0;
  *(undefined4 *)(param_1 + 0xc7a0) = 0xd8;
  *(undefined4 *)(param_1 + 0xc7a4) = 0xfe;
  *(undefined4 *)(param_1 + 0xc7e0) = 0;
  *(undefined4 *)(param_1 + 0xc81c) = 0;
  *(undefined4 *)(param_1 + 0xc82c) = 0;
  *(undefined4 *)(param_1 + 0xc868) = 0;
  *(undefined4 *)(param_1 + 0xc86c) = 0;
  *(undefined4 *)(param_1 + 0xc88c) = 0xffffff;
  *(undefined4 *)(param_1 + 0xc87c) = 1;
  *(undefined4 *)(param_1 + 0xc8a8) = 0;
  *(undefined4 *)(param_1 + 0xc8ac) = 0;
  *(undefined4 *)(param_1 + 0xc8b0) = 0;
  *(undefined4 *)(param_1 + 0xc8dc) = 0;
  *(undefined4 *)(param_1 + 0xc8ec) = 0xff;
  *(undefined4 *)(param_1 + 0xc8e4) = 0;
  *(undefined4 *)(param_1 + 0xc8e8) = 0;
  *(undefined4 *)(param_1 + 0xc8f8) = 1;
  *(undefined4 *)(param_1 + 0xc8fc) = 0;
  *(undefined4 *)(param_1 + 0xc900) = 0;
  *(undefined4 *)(param_1 + 0xc914) = 0;
  *(undefined4 *)(param_1 + 0xc918) = 0;
  *(undefined4 *)(param_1 + 0xc91c) = 0;
  *(undefined4 *)(param_1 + 0xc920) = 0;
  *(undefined4 *)(param_1 + 0xc924) = 0xff;
  *(undefined4 *)(param_1 + 0xc928) = 0;
  *(undefined4 *)(param_1 + 0xc92c) = 0;
  *(undefined4 *)(param_1 + 0xc930) = 0;
  *(undefined4 *)(param_1 + 0xc934) = 1;
  *(undefined4 *)(param_1 + 0xc940) = 0;
  *(undefined4 *)(param_1 + 0xc950) = 0;
  *(undefined4 *)(param_1 + 0xc958) = 0;
  *(undefined4 *)(param_1 + 0xc9a4) = 0;
  *(undefined4 *)(param_1 + 0xc9b8) = 0;
  *(undefined4 *)(param_1 + 0xc9bc) = 0;
  *(undefined4 *)(param_1 + 0xc9cc) = 0;
  *(undefined4 *)(param_1 + 0xc9c0) = 1;
  *(undefined4 *)(param_1 + 0xc9c4) = 0;
  *(undefined4 *)(param_1 + 0xc9e0) = 1;
  *(undefined4 *)(param_1 + 0xc9d8) = 0;
  *(undefined4 *)(param_1 + 0xc9fc) = 400;
  *(undefined4 *)(param_1 + 0xca34) = 0;
  *(undefined4 *)(param_1 + 0xca30) = 0;
  *(undefined4 *)(param_1 + 0xca38) = 0;
  *(undefined4 *)(param_1 + 0xca48) = 0;
  *(undefined4 *)(param_1 + 0xca4c) = 0;
  *(undefined4 *)(param_1 + 0xca50) = 5;
  *(undefined4 *)(param_1 + 0xca58) = 2;
  *(undefined4 *)(param_1 + 0xca60) = 0;
  *(undefined4 *)(param_1 + 0xca8c) = 9;
  *(undefined4 *)(param_1 + 0xca98) = 0x578;
  *(undefined4 *)(param_1 + 0xca9c) = 0x578;
  *(undefined4 *)(param_1 + 0xcaa4) = 0;
  *(undefined4 *)(param_1 + 0xcaa8) = 0;
  *(undefined4 *)(param_1 + 0xcaac) = 0;
  *(undefined4 *)(param_1 + 0xcab0) = 0;
  *(undefined4 *)(param_1 + 0xcab4) = 0;
  *(undefined4 *)(param_1 + 0xcab8) = 0;
  *(undefined4 *)(param_1 + 0xcabc) = 0x15e;
  *(undefined4 *)(param_1 + 0xcac0) = 0x140;
  *(undefined4 *)(param_1 + 0xcac4) = 0;
  *(undefined4 *)(param_1 + 0xcad8) = 0;
  *(undefined4 *)(param_1 + 0xcb04) = 0;
  *(undefined4 *)(param_1 + 0xcb0c) = 1;
  *(undefined4 *)(param_1 + 0xcb14) = 7;
  *(undefined4 *)(param_1 + 52000) = 0;
  *(int *)(param_1 + 0xcba0) = *(int *)(param_1 + 0xca90) / 2;
  *(undefined4 *)(param_1 + 0xcba4) = *(undefined4 *)(param_1 + 0xca94);
  *(undefined4 *)(param_1 + 0xcb24) = 0;
  *(undefined4 *)(param_1 + 0xcb28) = 0;
  *(undefined4 *)(param_1 + 0xcb30) = 0;
  *(undefined4 *)(param_1 + 0xcc0c) = 0;
  *(undefined4 *)(param_1 + 0xcc10) = 0;
  *(undefined4 *)(param_1 + 0xcc74) = 0;
  *(undefined4 *)(param_1 + 0xcc24) = 3;
  *(undefined4 *)(param_1 + 0xcc28) = 0;
  *(undefined4 *)(param_1 + 0xcc2c) = 0;
  *(undefined4 *)(param_1 + 0xcc30) = 0;
  *(undefined4 *)(param_1 + 0xcc58) = 0x100;
  *(undefined4 *)(param_1 + 0xcc5c) = 0x100;
  *(undefined4 *)(param_1 + 0xcc68) = 0;
  *(undefined4 *)(param_1 + 0xcc70) = 0x14;
  *(undefined4 *)(param_1 + 0xcc80) = 0;
  *(undefined4 *)(param_1 + 0xcdc8) = 1;
  *(undefined4 *)(param_1 + 0xccf0) = 0;
  *(undefined4 *)(param_1 + 0xccf4) = 0;
  *(undefined4 *)(param_1 + 0xccf8) = 0;
  *(undefined4 *)(param_1 + 0xccfc) = 0;
  *(undefined4 *)(param_1 + 0xcd38) = 0;
  *(undefined4 *)(param_1 + 0xcd3c) = 0;
  *(undefined4 *)(param_1 + 0xcd40) = 0;
  *(undefined4 *)(param_1 + 0xcd54) = 0;
  *(undefined4 *)(param_1 + 0xcd50) = 0;
  *(undefined4 *)(param_1 + 0xcd58) = 0;
  *(undefined4 *)(param_1 + 0xcdec) = 0;
  *(undefined4 *)(param_1 + 0xce54) = 0;
  *(undefined4 *)(param_1 + 0xce58) = 0;
  *(undefined4 *)(param_1 + 0xd01c) = 0;
  *(undefined4 *)(param_1 + 0xd018) = 0;
  *(undefined4 *)(param_1 + 0xd020) = 0;
  *(undefined4 *)(param_1 + 0xd05c) = 0;
  *(undefined4 *)(param_1 + 0xd060) = 0;
  *(undefined4 *)(param_1 + 0xd064) = 0;
  *(undefined4 *)(param_1 + 0xd0a0) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  DVar1 = timeGetTime();
  *(DWORD *)(param_1 + 0x88) = DVar1;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  return 0;
}




======================================================================
// Function: Resource_LoadPresetData @ 10015b20
======================================================================

undefined4 Resource_LoadPresetData(int *param_1)

{
  int iVar1;
  HGLOBAL hResData;
  LPVOID pvVar2;
  HRSRC hResInfo;
  
  hResInfo = (HRSRC)0x0;
  iVar1 = GetDeviceCaps((HDC)param_1[0x329a],0xc);
  param_1[0x3229] = iVar1;
  iVar1 = param_1[param_1[0x3298] + 0x31ea];
  param_1[0x320b] = iVar1;
  if (iVar1 == 0) {
    if (param_1[0x3298] == 9) {
      hResInfo = FindResourceA(DAT_10025048,s_FDATATABLE_10_100242ef + 1,(LPCSTR)0xa);
    }
    hResData = LoadResource(DAT_10025048,hResInfo);
    pvVar2 = LockResource(hResData);
    param_1[0x32ac] = (int)pvVar2;
    (**(code **)(*param_1 + 0x184))(param_1);
    param_1[param_1[0x3298] + 0x31ea] = param_1[0x32ac];
    param_1[0x320b] = param_1[0x32ac];
    FreeResource(hResData);
  }
  return 0;
}




======================================================================
// Function: State_InitParams @ 10015cd0
======================================================================

undefined4 State_InitParams(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0xf4))(param_1);
  param_1[0x3240] = 0;
  do {
    param_1[0x3286] = 0;
    do {
      param_1[param_1[0x3240] * 0x7b + param_1[0x3286] + 0xc31] = 0;
      iVar1 = param_1[0x3286];
      param_1[0x3286] = iVar1 + 1;
    } while (iVar1 + 1 < 0x7b);
    param_1[0x328f] = 0;
    do {
      param_1[param_1[0x328f] + param_1[0x3240] * 0x38 + 0x29] = 0;
      iVar1 = param_1[0x328f];
      param_1[0x328f] = iVar1 + 1;
    } while (iVar1 + 1 < 0x38);
    iVar1 = param_1[0x3240];
    param_1[0x3240] = iVar1 + 1U;
  } while (iVar1 + 1U <= (uint)param_1[0x340e]);
  param_1[0x341a] = 0x5a;
  param_1[0x3417] = 0;
  param_1[0x341b] = 0x17d8;
  param_1[0x341c] = 0x1989;
  param_1[0x341d] = -0x13e;
  param_1[0x3249] = 0xff;
  param_1[0x3246] = 0;
  param_1[0x3247] = 0;
  param_1[0x337b] = 0;
  param_1[0x3245] = 0;
  param_1[0x3248] = 0;
  param_1[0x324a] = 0;
  param_1[0x324b] = 0;
  param_1[0x3416] = 0;
  do {
    param_1[param_1[0x3416] + 0x2d02] = 0;
    iVar1 = param_1[0x3416];
    param_1[0x3416] = iVar1 + 1;
  } while (iVar1 + 1 < 0x208);
  param_1[0x3416] = 0;
  do {
    param_1[param_1[0x3416] + 0x26e0] = 0;
    iVar1 = param_1[0x3416];
    param_1[0x3416] = iVar1 + 1;
  } while (iVar1 + 1 < 10);
  param_1[0xc9a] = 0;
  param_1[0xc31] = 2;
  param_1[0xc55] = 0x479;
  param_1[0xc50] = 0x453;
  param_1[0xc51] = -0x1da;
  param_1[0xc58] = 0;
  param_1[0xc39] = 9;
  param_1[0xc3a] = 4;
  param_1[0xc4f] = 0;
  param_1[0xca9] = 1;
  param_1[0xc35] = 2;
  param_1[0x3240] = 0;
  (**(code **)(*param_1 + 0x160))(param_1);
  param_1[0xcac] = 2;
  param_1[0xcd0] = 0x58c;
  param_1[0xccb] = 0x522;
  param_1[0xccc] = -0x191;
  param_1[0xcd3] = 9;
  param_1[0xcb4] = 9;
  param_1[0xcb5] = 4;
  param_1[0xcca] = -1;
  param_1[0xcb0] = 2;
  param_1[0x3240] = 1;
  (**(code **)(*param_1 + 0x160))(param_1);
  param_1[0xd27] = 2;
  param_1[0xd90] = 0;
  param_1[0xd4b] = 0x58c;
  param_1[0xd46] = 0x453;
  param_1[0xd47] = -0x1db;
  param_1[0xd4e] = 0;
  param_1[0xd2f] = 9;
  param_1[0xd30] = 4;
  param_1[0xd45] = -1;
  param_1[0xcf] = 0x40000000;
  param_1[0xd9f] = 1;
  param_1[0xba] = 0x43960000;
  param_1[0xc3] = 0x3f800000;
  param_1[0xc4] = 0x3f000000;
  param_1[0xd9d] = 2;
  param_1[0xd2b] = 2;
  param_1[0x3240] = 2;
  (**(code **)(*param_1 + 0x160))(param_1);
  param_1[0x3240] = 3;
  param_1[0xda2] = 2;
  param_1[0xdc6] = 0x58c;
  param_1[0xdc1] = 0x524;
  param_1[0xdc2] = -0x191;
  param_1[0xdc9] = 0;
  param_1[0xdaa] = 9;
  param_1[0xdab] = 4;
  param_1[0xdc0] = 0;
  param_1[0xe1a] = 1;
  param_1[0xe0b] = -1;
  param_1[0xda6] = 2;
  (**(code **)(*param_1 + 0x160))(param_1);
  param_1[0xe44] = 0;
  param_1[0xe3b] = 0;
  param_1[0x3240] = 4;
  param_1[0xe1d] = 2;
  param_1[0xe41] = 0x58c;
  param_1[0xe3c] = 0x524;
  param_1[0xe3d] = -0x191;
  param_1[0xe25] = 9;
  param_1[0xe26] = 4;
  param_1[0xe86] = -1;
  param_1[0xe21] = 2;
  (**(code **)(*param_1 + 0x160))(param_1);
  param_1[0x3240] = 5;
  param_1[0xe98] = 2;
  param_1[0xebc] = 0x58c;
  param_1[0xeb7] = 0x4f5;
  param_1[0xeb8] = 0x35;
  param_1[0xebf] = -0x2e;
  param_1[0xea0] = 9;
  param_1[0xea1] = 4;
  param_1[0xeb6] = -1;
  param_1[0xf01] = -1;
  param_1[0xe9c] = 2;
  (**(code **)(*param_1 + 0x160))(param_1);
  return 0;
}




======================================================================
// Function: Motion_CalcPresetXY @ 100162e0
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Motion_CalcPresetXY(int param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0 + param_1;
  if (*(float *)(iVar1 + 0xbc) == _DAT_10021260) {
    return 0;
  }
  if (*(float *)(iVar1 + 0xbc) < *(float *)(iVar1 + 0xb8)) {
    *(undefined4 *)(iVar1 + 0xb8) = *(undefined4 *)(iVar1 + 0xbc);
  }
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar1 + param_1 + 0xbc) =
       *(float *)(iVar1 + 0xbc + param_1) - *(float *)(iVar1 + 0xb8 + param_1);
  iVar2 = *(int *)(param_1 + 0xc900) * 0xe0;
  iVar1 = iVar2 + param_1;
  *(float *)(param_1 + 0xc9f0) =
       *(float *)(iVar2 + 0xa4 + param_1) * *(float *)(iVar2 + 0xb8 + param_1);
  *(float *)(param_1 + 0xc9f4) = *(float *)(iVar1 + 0xa8) * *(float *)(iVar1 + 0xb8);
  *(float *)(iVar1 + 0xac) = *(float *)(iVar1 + 0xac) + *(float *)(param_1 + 0xc9f0);
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar1 + 0xb0 + param_1) =
       *(float *)(iVar1 + 0xb0 + param_1) + *(float *)(param_1 + 0xc9f4);
  iVar1 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x3140 + iVar1 * 0x1ec) = (int)lVar3;
  iVar1 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x3144 + iVar1 * 0x1ec) = (int)lVar3;
  return 0;
}




======================================================================
// Function: Motion_CalcPresetX @ 100165c0
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Motion_CalcPresetX(int param_1)

{
  float fVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = *(int *)(param_1 + 0xc900) * 0xe0 + param_1;
  if (*(float *)(iVar2 + 0xbc) == _DAT_10021260) {
    return 0;
  }
  if (*(float *)(iVar2 + 0xbc) < *(float *)(iVar2 + 0xb8)) {
    *(undefined4 *)(iVar2 + 0xb8) = *(undefined4 *)(iVar2 + 0xbc);
  }
  iVar2 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar2 + param_1 + 0xbc) =
       *(float *)(iVar2 + 0xbc + param_1) - *(float *)(iVar2 + 0xb8 + param_1);
  iVar2 = *(int *)(param_1 + 0xc900) * 0xe0;
  fVar1 = *(float *)(iVar2 + 0xb8 + param_1) * *(float *)(iVar2 + 0xa4 + param_1);
  *(float *)(param_1 + 0xc9f0) = fVar1;
  *(float *)(iVar2 + param_1 + 0xac) = fVar1 + *(float *)(iVar2 + param_1 + 0xac);
  iVar2 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x3140 + iVar2 * 0x1ec) = (int)lVar3;
  return 0;
}




======================================================================
// Function: Motion_CalcPresetXY2 @ 100166b0
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Motion_CalcPresetXY2(int param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0 + param_1;
  if (*(float *)(iVar1 + 0xbc) == _DAT_10021260) {
    return 0;
  }
  if (*(float *)(iVar1 + 0xbc) < *(float *)(iVar1 + 0xb8)) {
    *(undefined4 *)(iVar1 + 0xb8) = *(undefined4 *)(iVar1 + 0xbc);
  }
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar1 + param_1 + 0xbc) =
       *(float *)(iVar1 + 0xbc + param_1) - *(float *)(iVar1 + 0xb8 + param_1);
  iVar2 = *(int *)(param_1 + 0xc900) * 0xe0;
  iVar1 = iVar2 + param_1;
  *(float *)(param_1 + 0xc9f0) =
       *(float *)(iVar2 + 0xa4 + param_1) * *(float *)(iVar2 + 0xb8 + param_1);
  *(float *)(param_1 + 0xc9f4) = *(float *)(iVar1 + 0xa8) * *(float *)(iVar1 + 0xb8);
  *(float *)(iVar1 + 0xac) = *(float *)(iVar1 + 0xac) + *(float *)(param_1 + 0xc9f0);
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar1 + 0xb4 + param_1) =
       *(float *)(iVar1 + 0xb4 + param_1) + *(float *)(param_1 + 0xc9f4);
  iVar1 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x3140 + iVar1 * 0x1ec) = (int)lVar3;
  iVar1 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x3160 + iVar1 * 0x1ec) = (int)lVar3;
  return 0;
}




======================================================================
// Function: Motion_CalcPresetXYZ @ 10016a00
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Motion_CalcPresetXYZ(int param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0 + param_1;
  if (*(float *)(iVar1 + 0xbc) == _DAT_10021260) {
    return 0;
  }
  if (*(float *)(iVar1 + 0xbc) < *(float *)(iVar1 + 0xb8)) {
    *(undefined4 *)(iVar1 + 0xb8) = *(undefined4 *)(iVar1 + 0xbc);
  }
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar1 + param_1 + 0xbc) =
       *(float *)(iVar1 + 0xbc + param_1) - *(float *)(iVar1 + 0xb8 + param_1);
  iVar2 = *(int *)(param_1 + 0xc900) * 0xe0;
  iVar1 = iVar2 + param_1;
  *(float *)(param_1 + 0xc9f0) =
       *(float *)(iVar2 + 0xa4 + param_1) * *(float *)(iVar2 + 0xb8 + param_1);
  *(float *)(param_1 + 0xc9f4) = *(float *)(iVar1 + 0xa8) * *(float *)(iVar1 + 0xb8);
  *(float *)(param_1 + 0xc9f8) = *(float *)(iVar1 + 0x168) * *(float *)(iVar1 + 0xb8);
  *(float *)(iVar1 + 0xac) = *(float *)(param_1 + 0xc9f0) + *(float *)(iVar1 + 0xac);
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar1 + 0xb4 + param_1) =
       *(float *)(iVar1 + 0xb4 + param_1) + *(float *)(param_1 + 0xc9f4);
  iVar1 = *(int *)(param_1 + 0xc900) * 0xe0;
  *(float *)(iVar1 + 0x16c + param_1) =
       *(float *)(iVar1 + 0x16c + param_1) + *(float *)(param_1 + 0xc9f8);
  iVar1 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x3140 + iVar1 * 0x1ec) = (int)lVar3;
  iVar1 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x3160 + iVar1 * 0x1ec) = (int)lVar3;
  iVar1 = *(int *)(param_1 + 0xc900);
  lVar3 = __ftol();
  *(int *)(param_1 + 0x315c + iVar1 * 0x1ec) = (int)lVar3;
  return 0;
}




======================================================================
// Function: Render_PresetLoop @ 10016bc0
======================================================================

undefined4 Render_PresetLoop(int *param_1)

{
  if (param_1[0x3293] != param_1[0x330d]) {
    param_1[0x3293] = param_1[0x330d];
    param_1[0x3271] = 0;
    (**(code **)(*param_1 + 0x19c))(param_1);
    return 0;
  }
  param_1[0x3240] = 0;
  if (param_1[0xc3b] != 0) {
    if (param_1[0x3273] == 0 || param_1[0xd90] == -1) {
      if (param_1[0x3273] != 0 && param_1[0xc9a] != -1) {
        param_1[0x3240] = 0;
        (**(code **)(*param_1 + 0x78))(param_1);
      }
    }
    else {
      param_1[0x3240] = 0;
      (**(code **)(*param_1 + 0x154))(param_1);
    }
    if (param_1[0x3273] == 1) {
      (**(code **)(*param_1 + 0x170))(param_1);
    }
    (**(code **)(*param_1 + 0x19c))(param_1);
  }
  return 0;
}




======================================================================
// Function: Render_PresetSetup @ 10016c90
======================================================================

undefined4 Render_PresetSetup(int *param_1)

{
  param_1[0x3225] = param_1[0xc53];
  param_1[0x31fc] = param_1[0xc3b];
  param_1[0x3224] = param_1[0xc54];
  param_1[0x3420] = 0;
  param_1[0x3425] = 0;
  param_1[param_1[0x3240] * 0x7b + 0xc9a] = 0;
  if (param_1[param_1[0x3240] * 0x7b + 0xca5] == 0) {
    (**(code **)(*param_1 + 0x188))(param_1);
  }
  param_1[param_1[0x3240] * 0x7b + 0xc9a] = -1;
  return 0;
}




======================================================================
// Function: Render_SwapFrameBuffers @ 10016d20
======================================================================

undefined4 Render_SwapFrameBuffers(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  longlong lVar5;
  
  iVar2 = param_1[0x3240];
  param_1[0x3338] = param_1[iVar2 * 0x7b + 0xc3b];
  param_1[0x33dc] = param_1[iVar2 * 0x7b + 0xc4f];
  if (param_1[iVar2 * 0x7b + 0xc5f] == 1) {
    if (param_1[iVar2 * 0x7b + 0xc60] == 0) {
      return 0;
    }
    (**(code **)(*param_1 + 0x78))(param_1);
    param_1[0x3338] = param_1[param_1[0x3240] * 0x7b + 0xc60];
  }
  else if (param_1[iVar2 * 0x7b + 0xc5f] == 2) {
    if (param_1[iVar2 * 0x7b + 0xc99] == 0) {
      return 0;
    }
    (**(code **)(*param_1 + 0x78))(param_1);
    param_1[0x3338] = param_1[param_1[0x3240] * 0x7b + 0xc99];
  }
  param_1[0x3240] = 2;
  param_1[0x3357] = param_1[0xd31];
  if (param_1[0xd55] == 1) {
    iVar2 = param_1[0xd56];
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    if (param_1[0xd55] != 2) goto LAB_10016e14;
    iVar2 = param_1[0xd8f];
    if (iVar2 == 0) {
      return 0;
    }
  }
  param_1[0x3357] = iVar2;
LAB_10016e14:
  param_1[0x3410] = param_1[0xd4a] * param_1[0xd49];
  lVar5 = __ftol();
  param_1[0x336d] = (int)lVar5;
  piVar4 = (int *)param_1[0x3357];
  piVar3 = (int *)param_1[0x3338];
  iVar2 = param_1[0x3410];
  iVar1 = param_1[0x33dc];
  do {
    if (*piVar3 != iVar1) {
      *piVar4 = *piVar3;
      *piVar3 = iVar1;
    }
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (**(code **)(*param_1 + 0x9c))(param_1);
  return 0;
}




======================================================================
// Function: Waveform_CopyMultiBPP @ 100171b0
======================================================================

undefined4 Waveform_CopyMultiBPP(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0xc900) = 1;
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x3368) == 1) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x336c);
  }
  if (*(int *)(param_1 + 0x3368) == 2) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x3450);
  }
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 14000);
  piVar1 = (int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xd058) * 4);
  *(int *)(param_1 + 0xcce0) = *(int *)(param_1 + 0xc83c);
  *(undefined4 *)(param_1 + 0x3740) = 0;
  *(int *)(param_1 + 0xc83c) = *(int *)(param_1 + 0xc83c) + *(int *)(param_1 + 0x3338) * *piVar1 * 4
  ;
  iVar2 = *piVar1;
  *(undefined4 *)(param_1 + 0xcdd0) = *(undefined4 *)(param_1 + 0x3710);
  iVar2 = iVar2 + 1;
  *(int *)(param_1 + 0xd040) = iVar2;
  if (*(int *)(param_1 + 0x3714) < iVar2) {
    *(int *)(param_1 + 0xd040) = *(int *)(param_1 + 0x3714);
  }
  puVar4 = *(undefined4 **)(param_1 + 0xc808);
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc83c) + *(int *)(param_1 + 0xcc70));
  iVar2 = *(int *)(param_1 + 0xd040);
  *(undefined1 *)(puVar4 + -1) = 0;
  if (*(uint *)(param_1 + 0xcdd0) < 3) {
    if (*(uint *)(param_1 + 0xcdd0) == 2) {
      do {
        *puVar4 = *puVar3;
        puVar4[1] = puVar3[1];
        puVar3 = (undefined4 *)((int)(puVar3 + 1) - *(int *)(param_1 + 0xcc70));
        puVar4 = puVar4 + 2;
        if (puVar3 < *(undefined4 **)(param_1 + 0xcce0)) {
          puVar3 = *(undefined4 **)(param_1 + 0xcce0);
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    else {
      do {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = (undefined4 *)((int)puVar3 - *(int *)(param_1 + 0xcc70));
        if (puVar3 < *(undefined4 **)(param_1 + 0xcce0)) {
          puVar3 = *(undefined4 **)(param_1 + 0xcce0);
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else {
    do {
      *puVar4 = *puVar3;
      puVar4[1] = puVar3[1];
      puVar4[2] = puVar3[2];
      puVar3 = (undefined4 *)((int)(puVar3 + 2) - *(int *)(param_1 + 0xcc70));
      puVar4 = puVar4 + 3;
      if (puVar3 < *(undefined4 **)(param_1 + 0xcce0)) {
        puVar3 = *(undefined4 **)(param_1 + 0xcce0);
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}




======================================================================
// Function: Waveform_Copy4BPP @ 10017310
======================================================================

undefined4 Waveform_Copy4BPP(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0xc900) = 1;
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x3368) == 1) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x336c);
  }
  if (*(int *)(param_1 + 0x3368) == 2) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x3450);
  }
  iVar2 = *(int *)(param_1 + 0xc83c);
  *(undefined4 *)(param_1 + 0x3740) = 0;
  *(int *)(param_1 + 0xccb0) = iVar2;
  *(int *)(param_1 + 0xcce0) = iVar2 + *(int *)(param_1 + 0x333c) * *(int *)(param_1 + 0x3338) * 4;
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 14000);
  iVar1 = *(int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xd058) * 4);
  *(undefined4 *)(param_1 + 0xd040) = *(undefined4 *)(param_1 + 0x3714);
  *(int *)(param_1 + 0xc83c) = iVar2 + iVar1 * *(int *)(param_1 + 0x3338) * 4;
  *(undefined4 *)(param_1 + 0xcdd0) = *(undefined4 *)(param_1 + 0x3710);
  puVar4 = *(undefined4 **)(param_1 + 0xc808);
  puVar3 = *(undefined4 **)(param_1 + 0xc83c);
  iVar2 = *(int *)(param_1 + 0xd040);
  *(undefined1 *)(puVar4 + -1) = 0;
  do {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
    if (*(undefined4 **)(param_1 + 0xcce0) <= puVar3) {
      puVar3 = *(undefined4 **)(param_1 + 0xccb0);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}




======================================================================
// Function: Waveform_CopyWithScroll @ 10017410
======================================================================

longlong Waveform_CopyWithScroll(int param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 14000);
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x3368) == 1) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x336c);
  }
  if (*(int *)(param_1 + 0x3368) == 2) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x3450);
  }
  iVar3 = *(int *)(param_1 + 0xc86c) + 8;
  *(int *)(param_1 + 0xcce0) = *(int *)(param_1 + 0xc83c);
  *(int *)(param_1 + 0xc86c) = iVar3;
  if (*(int *)(param_1 + 0x333c) <= iVar3) {
    *(undefined4 *)(param_1 + 0xc86c) = 0;
  }
  *(int *)(param_1 + 0xd040) = *(int *)(param_1 + 0x333c) - *(int *)(param_1 + 0xc86c);
  *(int *)(param_1 + 0xc83c) =
       *(int *)(param_1 + 0xc83c) + *(int *)(param_1 + 0x3338) * *(int *)(param_1 + 0xc86c) * 4;
  *(undefined4 *)(param_1 + 0xcdd0) = *(undefined4 *)(param_1 + 0x3710);
  puVar5 = *(undefined4 **)(param_1 + 0xc808);
  puVar4 = *(undefined4 **)(param_1 + 0xc83c);
  *(undefined1 *)(puVar5 + -1) = 0;
  lVar1 = (ulonglong)*(uint *)(param_1 + 0xd040) * (ulonglong)*(uint *)(param_1 + 0xcdd0);
  uVar2 = (uint)((ulonglong)lVar1 >> 0x20);
  iVar3 = (int)lVar1;
  do {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar4 = *(undefined4 **)(param_1 + 0xcce0);
  if (*(uint *)(param_1 + 0xc86c) != 0) {
    lVar1 = (ulonglong)*(uint *)(param_1 + 0xcdd0) * (ulonglong)*(uint *)(param_1 + 0xc86c);
    uVar2 = (uint)((ulonglong)lVar1 >> 0x20);
    iVar3 = (int)lVar1;
    do {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return (ulonglong)uVar2 << 0x20;
}




======================================================================
// Function: Waveform_CopyAndFill @ 10017520
======================================================================

undefined4 Waveform_CopyAndFill(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x3368) == 1) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x336c);
  }
  if (*(int *)(param_1 + 0x3368) == 2) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x3450);
  }
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 14000);
  iVar2 = *(int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xd058) * 4) * *(int *)(param_1 + 0x3710);
  *(int *)(param_1 + 0xd040) = iVar2;
  *(int *)(param_1 + 0xd044) = *(int *)(param_1 + 0x3714) * *(int *)(param_1 + 0x3710) - iVar2;
  if (*(int *)(param_1 + 0xd040) <= *(int *)(param_1 + 0x333c) * *(int *)(param_1 + 0x3338)) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x3338) * 0x400 + *(int *)(param_1 + 0xc83c));
    *(undefined4 **)(param_1 + 0xcd60) = puVar3;
    *(undefined4 *)(param_1 + 0xcdac) = *puVar3;
    puVar3 = *(undefined4 **)(param_1 + 0xc808);
    puVar4 = *(undefined4 **)(param_1 + 0xc83c);
    *(undefined1 *)(puVar3 + -1) = 0;
    for (iVar2 = *(int *)(param_1 + 0xd040); iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
    }
    uVar1 = *(undefined4 *)(param_1 + 0xcdac);
    iVar2 = *(int *)(param_1 + 0xd044);
    do {
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    return 0;
  }
  return 0;
}




======================================================================
// Function: Waveform_CopyWithMirror @ 10017620
======================================================================

undefined4 Waveform_CopyWithMirror(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x3368) == 1) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x336c);
  }
  if (*(int *)(param_1 + 0x3368) == 2) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x3450);
  }
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 14000);
  iVar1 = *(int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xd058) * 4) * *(int *)(param_1 + 0x3710);
  *(int *)(param_1 + 0xd040) = iVar1;
  *(int *)(param_1 + 0xd044) = *(int *)(param_1 + 0x3714) * *(int *)(param_1 + 0x3710) - iVar1;
  if (*(int *)(param_1 + 0x333c) * *(int *)(param_1 + 0x3338) < *(int *)(param_1 + 0xd040)) {
    return 0;
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x3338) * 0x400 + *(int *)(param_1 + 0xc83c));
  *(undefined4 **)(param_1 + 0xcd60) = puVar2;
  *(undefined4 *)(param_1 + 0xcdac) = *puVar2;
  piVar6 = *(int **)(param_1 + 0xc808);
  piVar4 = *(int **)(param_1 + 0xc83c);
  *(undefined1 *)(piVar6 + -1) = 0;
  iVar1 = *(int *)(param_1 + 0xd040);
  if (iVar1 != 0) {
    do {
      piVar5 = piVar6;
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar6 = piVar5 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (2 < *(uint *)(param_1 + 0xd040)) {
      *piVar5 = *piVar5 + -0x80000000;
      piVar5[-1] = piVar5[-1] + 0x40000000;
      piVar5[-2] = piVar5[-2] + 0x20000000;
    }
  }
  iVar1 = *(int *)(param_1 + 0xcdac);
  iVar3 = *(int *)(param_1 + 0xd044);
  do {
    *piVar6 = iVar1;
    piVar6 = piVar6 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}




======================================================================
// Function: Waveform_CopyWithWrap @ 10017740
======================================================================

undefined4 Waveform_CopyWithWrap(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x3368) == 1) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x336c);
  }
  if (*(int *)(param_1 + 0x3368) == 2) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x3450);
  }
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 14000);
  iVar3 = *(int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xd058) * 4) * *(int *)(param_1 + 0x3710);
  *(int *)(param_1 + 0xd040) = iVar3;
  *(int *)(param_1 + 0xd044) = *(int *)(param_1 + 0x3714) * *(int *)(param_1 + 0x3710) - iVar3;
  if (*(int *)(param_1 + 0xd040) <= *(int *)(param_1 + 0x333c) * *(int *)(param_1 + 0x3338)) {
    *(undefined4 *)(param_1 + 0xcdac) = 0;
    *(int *)(param_1 + 0xcd60) = *(int *)(param_1 + 0x3338) * 0x400 + *(int *)(param_1 + 0xc83c);
    puVar7 = *(undefined4 **)(param_1 + 0xc808);
    puVar6 = *(undefined4 **)(param_1 + 0xc83c);
    *(undefined1 *)(puVar7 + -1) = 0;
    uVar1 = *(uint *)(param_1 + 0xd040);
    if (uVar1 != 0) {
      uVar4 = uVar1 >> 1;
      uVar5 = uVar4;
      if ((uVar1 & 1) != 0) {
        uVar5 = uVar4 + 1;
      }
      do {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + -1;
        puVar7 = puVar7 + 1;
      }
    }
    uVar2 = *(undefined4 *)(param_1 + 0xcdac);
    iVar3 = *(int *)(param_1 + 0xd044);
    do {
      *puVar7 = uVar2;
      puVar7 = puVar7 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}




======================================================================
// Function: Waveform_MirrorCopy @ 10017850
======================================================================

undefined4 Waveform_MirrorCopy(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  
  *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x3368) == 1) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x336c);
  }
  if (*(int *)(param_1 + 0x3368) == 2) {
    *(undefined4 *)(param_1 + 0xc83c) = *(undefined4 *)(param_1 + 0x3450);
  }
  *(undefined4 *)(param_1 + 0xc808) = *(undefined4 *)(param_1 + 14000);
  iVar1 = *(int *)(param_1 + 0x9ba8 + *(int *)(param_1 + 0xd058) * 4) * *(int *)(param_1 + 0x3710);
  *(int *)(param_1 + 0xd040) = iVar1;
  *(int *)(param_1 + 0xd044) = *(int *)(param_1 + 0x3714) * *(int *)(param_1 + 0x3710) - iVar1;
  if (*(int *)(param_1 + 0xd040) <= *(int *)(param_1 + 0x333c) * *(int *)(param_1 + 0x3338)) {
    *(int *)(param_1 + 0xcd60) = *(int *)(param_1 + 0x3338) * 0x400 + *(int *)(param_1 + 0xc83c);
    puVar7 = *(uint **)(param_1 + 0xc808);
    puVar6 = *(uint **)(param_1 + 0xc83c);
    *(undefined1 *)(puVar7 + -1) = 0;
    *(uint *)(param_1 + 0xcdb0) = *puVar6;
    *(uint *)(param_1 + 0xcdac) = puVar6[200];
    uVar5 = *(uint *)(param_1 + 0xd040);
    if (uVar5 != 0) {
      uVar2 = uVar5 >> 1;
      uVar3 = uVar2;
      if ((uVar5 & 1) != 0) {
        uVar3 = uVar2 + 1;
      }
      do {
        *puVar7 = *puVar6 | uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                            uVar3 << 0x18;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        uVar5 = uVar2 >> 2;
        *puVar7 = *puVar6 | uVar2 >> 0x1a | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 |
                            uVar5 << 0x18;
        puVar6 = puVar6 + -1;
        puVar7 = puVar7 + 1;
      }
    }
    uVar5 = *(uint *)(param_1 + 0xd044);
    if (uVar5 != 0) {
      uVar2 = *(uint *)(param_1 + 0xcdb0);
      uVar3 = uVar5 >> 1;
      uVar4 = uVar3;
      if ((uVar5 & 1) != 0) {
        uVar4 = uVar3 + 1;
      }
      do {
        *puVar7 = uVar2;
        uVar2 = uVar2 + 0x1000000;
        puVar7 = puVar7 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        uVar5 = uVar3 + 0x14;
        *puVar7 = *(uint *)(param_1 + 0xcdac) |
                  uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 |
                  uVar5 * 0x1000000;
        puVar7 = puVar7 + 1;
      }
    }
  }
  return 0;
}




======================================================================
// Function: FUN_100179b0 @ 100179b0
======================================================================

undefined4 FUN_100179b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *(int *)(param_1 + 0xd040) =
       *(int *)(param_1 + 0x3150 + *(int *)(param_1 + 0xc900) * 0x1ec) *
       *(int *)(param_1 + *(int *)(param_1 + 0xc900) * 0x1ec + 0x314c);
  *(undefined4 *)(param_1 + 0xcce0) = *(undefined4 *)(param_1 + 0x30ec);
  *(undefined4 *)(param_1 + 0xcf70) = *(undefined4 *)(param_1 + 0x313c);
  puVar3 = *(undefined4 **)(param_1 + 0xcce0);
  iVar2 = *(int *)(param_1 + 0xd040);
  uVar1 = *(undefined4 *)(param_1 + 0xcf70);
  do {
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}




======================================================================
// Function: Preset_FillBuffer @ 10017a20
======================================================================

ulonglong Preset_FillBuffer(int param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  if (*(int *)(param_1 + 0x30ec + *(int *)(param_1 + 0xc900) * 0x1ec) != 0) {
    *(undefined4 *)(param_1 + 0xcdd0) = *(undefined4 *)(iVar3 + 0x314c);
    *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(iVar3 + 0x3150);
    *(undefined4 *)(param_1 + 0xce4c) = *(undefined4 *)(iVar3 + 0x30ec);
    uVar2 = (ulonglong)*(uint *)(param_1 + 0xcdd0) * (ulonglong)*(uint *)(param_1 + 0xcdbc);
    iVar3 = (int)uVar2;
    if (iVar3 != 0) {
      puVar4 = *(undefined4 **)(param_1 + 0xce4c);
      uVar1 = *(undefined4 *)(param_1 + 0xcc88);
      do {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    return uVar2 & 0xffffffff00000000;
  }
  return 0;
}




======================================================================
// Function: FUN_10017ab0 @ 10017ab0
======================================================================

undefined4 FUN_10017ab0(int param_1)

{
  *(undefined4 *)(param_1 + 0x32a8 + *(int *)(param_1 + 0xc900) * 0x1ec) = 3;
  *(undefined4 *)(param_1 + 0x30d4 + *(int *)(param_1 + 0xc900) * 0x1ec) = 3;
  *(undefined4 *)(param_1 + 0xcd5c) =
       *(undefined4 *)(param_1 + 0x30ec + *(int *)(param_1 + 0xc900) * 0x1ec);
  *(undefined1 *)(*(int *)(param_1 + 0xcd5c) + -4) = 0;
  return 0;
}




======================================================================
// Function: FUN_10017b20 @ 10017b20
======================================================================

ulonglong FUN_10017b20(int param_1)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  bool bVar6;
  
  iVar1 = *(int *)(param_1 + 0x30ec + *(int *)(param_1 + 0xc900) * 0x1ec);
  iVar3 = param_1 + *(int *)(param_1 + 0xc900) * 0x1ec;
  uVar2 = CONCAT44(iVar1,iVar3);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0xcdd0) = *(undefined4 *)(iVar3 + 0x314c);
    *(undefined4 *)(param_1 + 0xcdbc) = *(undefined4 *)(iVar3 + 0x3150);
    *(undefined4 *)(param_1 + 0xce4c) = *(undefined4 *)(iVar3 + 0x30ec);
    uVar2 = (ulonglong)*(uint *)(param_1 + 0xcdd0) * (ulonglong)*(uint *)(param_1 + 0xcdbc);
    iVar3 = (int)uVar2;
    if (iVar3 != 0) {
      puVar5 = *(uint **)(param_1 + 0xce4c);
      do {
        uVar4 = *puVar5;
        if ((0xfe < (uVar4 & 0xff)) ||
           (bVar6 = CARRY4(uVar4,uVar4 * 0x1000000), uVar4 = uVar4 * 0x1000001, bVar6)) {
          uVar4 = uVar4 | 0xff000000;
        }
        uVar2 = CONCAT44(0xff,uVar4);
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return uVar2 & 0xffffffff00000000;
}




======================================================================
// Function: Audio_RandomSelect @ 10017d50
======================================================================

undefined4 Audio_RandomSelect(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  
  *(int *)(param_1 + 0xccb0) = *(int *)(param_1 + 0x32d8);
  if (*(int *)(param_1 + 0x32d8) != 0) {
    iVar1 = *(int *)(param_1 + 0xc860);
    lVar3 = __ftol();
    lVar4 = __ftol();
    if (0x2d < *(int *)(param_1 + 0xc8b0) && ((int)lVar3 < iVar1 || iVar1 < (int)lVar4)) {
      uVar2 = _rand();
      *(uint *)(param_1 + 0xc8ac) = uVar2 & 0xff;
      *(undefined4 *)(param_1 + 0xc8b0) = 0;
    }
    *(int *)(param_1 + 0xc8b0) = *(int *)(param_1 + 0xc8b0) + 1;
    if (0xff < *(int *)(param_1 + 0xc8ac)) {
      *(undefined4 *)(param_1 + 0xc8ac) = 0;
    }
    if (*(int *)(param_1 + 0xc860) < 3) {
      *(undefined4 *)(param_1 + 0xc8a8) = 0;
      return 0;
    }
    *(undefined4 *)(param_1 + 0xc8a8) =
         *(undefined4 *)(*(int *)(param_1 + 0xccb0) + *(int *)(param_1 + 0xc8ac) * 4);
  }
  return 0;
}




======================================================================
// Function: Waveform_CopyToDisplay @ 10017f50
======================================================================

undefined4 Waveform_CopyToDisplay(int *param_1)

{
  if (param_1[0x3271] == 0) {
    param_1[0x322a] = 0;
    if (param_1[0x3273] != 0) {
      param_1[0x3240] = 0;
      (**(code **)(*param_1 + 0x13c))(param_1);
      param_1[0x3240] = 2;
      (**(code **)(*param_1 + 0x13c))(param_1);
    }
    (**(code **)(*param_1 + 0x178))(param_1);
    param_1[0xd90] = 0;
    param_1[0x331c] = 1;
    param_1[0x3273] = 1;
  }
  (**(code **)(*param_1 + 0x1a0))(param_1);
  return 0;
}




======================================================================
// Function: DirectDrawCreate @ 10019b10
======================================================================

void DirectDrawCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x10019b10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreate();
  return;
}




======================================================================
// Function: Mem_Free @ 10019b16
======================================================================

void __cdecl Mem_Free(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    FUN_1001a73f(9);
    puVar1 = (uint *)FUN_1001a7f3((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_1001a81e(puVar1,(uint)param_1);
      FUN_1001a7a0(9);
      return;
    }
    FUN_1001a7a0(9);
    HeapFree(DAT_100257ec,0,param_1);
  }
  return;
}




======================================================================
// Function: _malloc @ 10019b5e
======================================================================

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_10025178);
  return pvVar1;
}




======================================================================
// Function: __nh_malloc @ 10019b70
======================================================================

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *piVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      piVar1 = FUN_10019b9c((uint *)_Size);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_1001b2f4(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}




======================================================================
// Function: FUN_10019b9c @ 10019b9c
======================================================================

int * __cdecl FUN_10019b9c(uint *param_1)

{
  int *piVar1;
  
  if (param_1 <= DAT_100243f8) {
    FUN_1001a73f(9);
    piVar1 = FUN_1001ab49(param_1);
    FUN_1001a7a0(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  piVar1 = HeapAlloc(DAT_100257ec,0,(int)param_1 + 0xfU & 0xfffffff0);
  return piVar1;
}




======================================================================
// Function: Mem_FreeObj @ 10019bea
======================================================================

void __cdecl Mem_FreeObj(LPVOID param_1)

{
  Mem_Free(param_1);
  return;
}




======================================================================
// Function: FUN_10019bf5 @ 10019bf5
======================================================================

void FUN_10019bf5(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021cb0;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_10019c5d();
  ExceptionList = local_14;
  return;
}




======================================================================
// Function: FUN_10019c5d @ 10019c5d
======================================================================

void FUN_10019c5d(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    FUN_10019c75(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(int *)(unaff_EBP + 0x10),*(undefined **)(unaff_EBP + 0x14));
  }
  return;
}




======================================================================
// Function: FUN_10019c75 @ 10019c75
======================================================================

void FUN_10019c75(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021cc0;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  ExceptionList = local_14;
  return;
}




======================================================================
// Function: FUN_10019ce9 @ 10019ce9
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10019ce9(void)

{
  void *extraout_ECX;
  
  FUN_10019d01();
  _DAT_100250e4 = FUN_1001b4f7();
  FUN_1001b4a7(extraout_ECX);
  return;
}




======================================================================
// Function: FUN_10019d01 @ 10019d01
======================================================================

void FUN_10019d01(void)

{
  PTR_LAB_10024404 = &LAB_1001b57a;
  PTR_LAB_10024400 = __cfltcvt;
  PTR_LAB_10024408 = __fassign;
  PTR_LAB_1002440c = FUN_1001b520;
  PTR_LAB_10024410 = &LAB_1001b5c8;
  PTR_LAB_10024414 = __cfltcvt;
  return;
}




======================================================================
// Function: __ftol @ 10019d3c
======================================================================

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}




======================================================================
// Function: FUN_10019d63 @ 10019d63
======================================================================

void FUN_10019d63(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x10019d8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}




======================================================================
// Function: FUN_10019d97 @ 10019d97
======================================================================

void FUN_10019d97(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x10019d9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}




======================================================================
// Function: FUN_10019d9e @ 10019d9e
======================================================================

void FUN_10019d9e(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x10019da3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}




======================================================================
// Function: FUN_10019da5 @ 10019da5
======================================================================

void FUN_10019da5(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x10019dcd,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}




======================================================================
// Function: FUN_10019df4 @ 10019df4
======================================================================

undefined4 __cdecl
FUN_10019df4(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_1001b946(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}




======================================================================
// Function: FUN_10019e2a @ 10019e2a
======================================================================

undefined4 __cdecl
FUN_10019e2a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_10019e7e;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}




======================================================================
// Function: FUN_10019e7e @ 10019e7e
======================================================================

void __cdecl FUN_10019e7e(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_1001b946(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}




======================================================================
// Function: FUN_10019ea3 @ 10019ea3
======================================================================

undefined4 __cdecl
FUN_10019ea3(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_10019f59;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x10019f2b;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_1001c221();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}




======================================================================
// Function: FUN_10019f59 @ 10019f59
======================================================================

undefined4 __cdecl FUN_10019f59(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_1001b946(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_10019da5(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x10019fc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}




======================================================================
// Function: FUN_10019fce @ 10019fce
======================================================================

int __cdecl FUN_10019fce(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x10);
  uVar4 = uVar5;
  uVar3 = uVar5;
  while (uVar2 = uVar4, -1 < param_2) {
    if (uVar5 == 0xffffffff) {
      FUN_1001b451();
    }
    uVar5 = uVar5 - 1;
    if (((*(int *)(iVar1 + 4 + uVar5 * 0x14) < param_3) &&
        (param_3 <= *(int *)(iVar1 + uVar5 * 0x14 + 8))) || (uVar4 = uVar2, uVar5 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar4 = uVar5;
      uVar3 = uVar2;
    }
  }
  uVar5 = uVar5 + 1;
  *param_4 = uVar5;
  *param_5 = uVar3;
  if ((*(uint *)(param_1 + 0xc) < uVar3) || (uVar3 < uVar5)) {
    FUN_1001b451();
  }
  return iVar1 + uVar5 * 0x14;
}




======================================================================
// Function: __global_unwind2 @ 1001a04c
======================================================================

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x1001a064,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}




======================================================================
// Function: __local_unwind2 @ 1001a08e
======================================================================

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_1001a06c;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_1001a122();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}




======================================================================
// Function: __abnormal_termination @ 1001a0f6
======================================================================

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(undefined1 **)((int)ExceptionList + 4) == &LAB_1001a06c) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}




======================================================================
// Function: __NLG_Notify1 @ 1001a119
======================================================================

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_1002431c = param_1;
  DAT_10024318 = in_EAX;
  DAT_10024320 = unaff_EBP;
  return;
}




======================================================================
// Function: FUN_1001a122 @ 1001a122
======================================================================

void FUN_1001a122(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_1002431c = *(undefined4 *)(unaff_EBP + 8);
  DAT_10024318 = in_EAX;
  DAT_10024320 = unaff_EBP;
  return;
}




======================================================================
// Function: FUN_1001a13a @ 1001a13a
======================================================================

void __cdecl FUN_1001a13a(DWORD param_1)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1001c221();
  pDVar1[5] = param_1;
  return;
}




======================================================================
// Function: _rand @ 1001a147
======================================================================

/* Library Function - Single Match
    _rand
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl _rand(void)

{
  DWORD *pDVar1;
  uint uVar2;
  
  pDVar1 = FUN_1001c221();
  uVar2 = pDVar1[5] * 0x343fd + 0x269ec3;
  pDVar1[5] = uVar2;
  return uVar2 >> 0x10 & 0x7fff;
}




======================================================================
// Function: FUN_1001a169 @ 1001a169
======================================================================

void __cdecl FUN_1001a169(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_100250f8._2_2_) {
    if (local_24.wHour == (WORD)DAT_100250f8) {
      if (local_24.wDay == DAT_100250f4._2_2_) {
        if (local_24.wMonth == DAT_100250f0._2_2_) {
          if (local_24.wYear == (WORD)DAT_100250f0) goto LAB_1001a213;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_100250e8 = -1;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_100250e8 = 1;
  }
  else {
    DAT_100250e8 = 0;
  }
  DAT_100250f0._0_2_ = local_24.wYear;
  DAT_100250f0._2_2_ = local_24.wMonth;
  DAT_100250f4._0_2_ = local_24.wDayOfWeek;
  DAT_100250f4._2_2_ = local_24.wDay;
  DAT_100250f8._0_2_ = local_24.wHour;
  DAT_100250f8._2_2_ = local_24.wMinute;
  DAT_100250fc._0_2_ = local_24.wSecond;
  DAT_100250fc._2_2_ = local_24.wMilliseconds;
LAB_1001a213:
  iVar2 = FUN_1001c328((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                       (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,
                       DAT_100250e8);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}




======================================================================
// Function: FUN_1001a250 @ 1001a250
======================================================================

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001a250(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}




======================================================================
// Function: operator_new @ 1001a288
======================================================================

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}




======================================================================
// Function: FUN_1001a296 @ 1001a296
======================================================================

int * __cdecl FUN_1001a296(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      Mem_Free(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_1001a73f(9);
          puVar2 = (uint *)FUN_1001a7f3((int)param_1);
          if (puVar2 == (uint *)0x0) {
            FUN_1001a7a0(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_100257ec,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_100243f8 < param_2) {
LAB_1001a335:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_100257ec,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_1001c3f0(piVar1,param_1,(uint)puVar4);
                FUN_1001a81e(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = FUN_1001affe(puVar2,(int)param_1,(int)param_2);
              piVar1 = param_1;
              if (iVar3 == 0) {
                piVar1 = FUN_1001ab49(param_2);
                if (piVar1 == (int *)0x0) goto LAB_1001a335;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_1001c3f0(piVar1,param_1,(uint)puVar4);
                FUN_1001a81e(puVar2,(uint)param_1);
              }
              if (piVar1 == (int *)0x0) goto LAB_1001a335;
            }
            FUN_1001a7a0(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_10025178 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_1001b2f4(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}




======================================================================
// Function: FUN_1001a3ce @ 1001a3ce
======================================================================

void FUN_1001a3ce(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021cd0;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_1001a438();
  ExceptionList = local_14;
  return;
}




======================================================================
// Function: FUN_1001a438 @ 1001a438
======================================================================

void FUN_1001a438(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    FUN_10019c75(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(int *)(unaff_EBP + -0x1c),*(undefined **)(unaff_EBP + 0x18));
  }
  return;
}




======================================================================
// Function: FUN_1001a450 @ 1001a450
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001a450(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    DAT_10025184 = GetVersion();
    iVar1 = FUN_1001a5f9(1);
    if (iVar1 != 0) {
      _DAT_10025190 = DAT_10025184 >> 8 & 0xff;
      _DAT_1002518c = DAT_10025184 & 0xff;
      DAT_10025184 = DAT_10025184 >> 0x10;
      _DAT_10025188 = _DAT_1002518c * 0x100 + _DAT_10025190;
      iVar1 = FUN_1001c19c();
      if (iVar1 != 0) {
        DAT_100257f0 = GetCommandLineA();
        DAT_10025104 = FUN_1001cd59();
        FUN_1001c843();
        FUN_1001cb0c();
        FUN_1001ca53();
        FUN_1001c725();
        DAT_10025100 = DAT_10025100 + 1;
        goto LAB_1001a523;
      }
      FUN_1001a635();
    }
LAB_1001a4b0:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_10025100 < 1) goto LAB_1001a4b0;
      DAT_10025100 = DAT_10025100 + -1;
      if (DAT_100251bc == 0) {
        FUN_1001c763();
      }
      FUN_1001c9ff();
      FUN_1001c1f0();
      FUN_1001a635();
    }
    else if (param_2 == 3) {
      FUN_1001c288((LPVOID)0x0);
    }
LAB_1001a523:
    uVar2 = 1;
  }
  return uVar2;
}




======================================================================
// Function: entry @ 1001a529
======================================================================

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_10025100;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_1001a571;
    if ((DAT_100257f4 != (code *)0x0) &&
       (iVar2 = (*DAT_100257f4)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_1001a450(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_1001a571:
  iVar2 = FUN_100108a0(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_1001a450(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_1001a450(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_100257f4 != (code *)0x0) {
      iVar2 = (*DAT_100257f4)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}




======================================================================
// Function: __amsg_exit @ 1001a5c6
======================================================================

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_1002510c == 1) || ((DAT_1002510c == 0 && (DAT_10025110 == 1)))) {
    FUN_1001ce8b();
  }
  FUN_1001cec4(param_1);
  (*(code *)PTR___exit_10024330)(0xff);
  return;
}




======================================================================
// Function: FUN_1001a5f9 @ 1001a5f9
======================================================================

undefined4 __cdecl FUN_1001a5f9(int param_1)

{
  int iVar1;
  
  DAT_100257ec = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_100257ec != (HANDLE)0x0) {
    iVar1 = FUN_1001a7b5();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_100257ec);
  }
  return 0;
}




======================================================================
// Function: FUN_1001a635 @ 1001a635
======================================================================

void FUN_1001a635(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < DAT_100257e4) {
    puVar2 = (undefined4 *)((int)DAT_100257e8 + 0xc);
    do {
      VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
      VirtualFree((LPVOID)*puVar2,0,0x8000);
      HeapFree(DAT_100257ec,0,(LPVOID)puVar2[1]);
      puVar2 = puVar2 + 5;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_100257e4);
  }
  HeapFree(DAT_100257ec,0,DAT_100257e8);
  HeapDestroy(DAT_100257ec);
  return;
}




======================================================================
// Function: FUN_1001a6aa @ 1001a6aa
======================================================================

void FUN_1001a6aa(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002437c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002436c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002435c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002433c);
  return;
}




======================================================================
// Function: FUN_1001a6d3 @ 1001a6d3
======================================================================

void FUN_1001a6d3(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)&DAT_10024338;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_1002437c)) && (ppuVar1 != &PTR_DAT_1002436c)) &&
       ((ppuVar1 != &PTR_DAT_1002435c && (ppuVar1 != &PTR_DAT_1002433c)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      Mem_Free(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x100243f8);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002435c);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002436c);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002437c);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1002433c);
  return;
}




======================================================================
// Function: FUN_1001a73f @ 1001a73f
======================================================================

void __cdecl FUN_1001a73f(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_10024338 + param_1;
  if ((&DAT_10024338)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_1001a73f(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      Mem_Free(lpCriticalSection);
    }
    FUN_1001a7a0(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}




======================================================================
// Function: FUN_1001a7a0 @ 1001a7a0
======================================================================

void __cdecl FUN_1001a7a0(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_10024338)[param_1]);
  return;
}




======================================================================
// Function: FUN_1001a7b5 @ 1001a7b5
======================================================================

undefined4 FUN_1001a7b5(void)

{
  DAT_100257e8 = HeapAlloc(DAT_100257ec,0,0x140);
  if (DAT_100257e8 == (LPVOID)0x0) {
    return 0;
  }
  DAT_100257e0 = 0;
  DAT_100257e4 = 0;
  DAT_100257dc = DAT_100257e8;
  DAT_100257d4 = 0x10;
  return 1;
}




======================================================================
// Function: FUN_1001a7f3 @ 1001a7f3
======================================================================

uint __cdecl FUN_1001a7f3(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_100257e8;
  while( true ) {
    if (DAT_100257e8 + DAT_100257e4 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}




======================================================================
// Function: FUN_1001a81e @ 1001a81e
======================================================================

void __cdecl FUN_1001a81e(uint *param_1,uint param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_10;
  
  uVar5 = param_1[4];
  iVar6 = *(int *)(param_2 - 4);
  piVar9 = (int *)(param_2 - 4);
  uVar10 = param_2 - param_1[3] >> 0xf;
  uVar7 = *(uint *)(param_2 - 8);
  local_10 = iVar6 + -1;
  piVar3 = (int *)(uVar10 * 0x204 + 0x144 + uVar5);
  uVar12 = *(uint *)(local_10 + (int)piVar9);
  if ((uVar12 & 1) == 0) {
    param_2 = ((int)uVar12 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    if (*(int *)(iVar6 + 3 + (int)piVar9) == *(int *)(iVar6 + 7 + (int)piVar9)) {
      if (param_2 < 0x20) {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 7 + (int)piVar9) + 4) =
         *(undefined4 *)(iVar6 + 3 + (int)piVar9);
    local_10 = local_10 + uVar12;
    *(undefined4 *)(*(int *)(iVar6 + 3 + (int)piVar9) + 8) =
         *(undefined4 *)(iVar6 + 7 + (int)piVar9);
  }
  uVar12 = (local_10 >> 4) - 1;
  if (0x3f < uVar12) {
    uVar12 = 0x3f;
  }
  if ((uVar7 & 1) == 0) {
    piVar9 = (int *)((int)piVar9 - uVar7);
    param_2 = ((int)uVar7 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    local_10 = local_10 + uVar7;
    uVar12 = (local_10 >> 4) - 1;
    if (0x3f < uVar12) {
      uVar12 = 0x3f;
    }
    if (param_2 != uVar12) {
      if (piVar9[1] == piVar9[2]) {
        if (param_2 < 0x20) {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(int *)(piVar9[2] + 4) = piVar9[1];
      *(int *)(piVar9[1] + 8) = piVar9[2];
    }
  }
  if (((uVar7 & 1) != 0) || (param_2 != uVar12)) {
    piVar9[1] = piVar3[uVar12 * 2 + 1];
    piVar9[2] = (int)(piVar3 + uVar12 * 2);
    (piVar3 + uVar12 * 2)[1] = (int)piVar9;
    *(int **)(piVar9[1] + 8) = piVar9;
    if (piVar9[1] == piVar9[2]) {
      cVar4 = *(char *)(uVar12 + 4 + uVar5);
      *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar12;
      if (uVar12 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  *piVar9 = local_10;
  *(int *)(local_10 + -4 + (int)piVar9) = local_10;
  *piVar3 = *piVar3 + -1;
  uVar5 = DAT_100257d8;
  puVar2 = DAT_100257e0;
  if ((*piVar3 == 0) && (uVar5 = uVar10, puVar2 = param_1, DAT_100257e0 != (uint *)0x0)) {
    VirtualFree((LPVOID)(DAT_100257d8 * 0x8000 + DAT_100257e0[3]),0x8000,0x4000);
    DAT_100257e0[2] = DAT_100257e0[2] | 0x80000000U >> ((byte)DAT_100257d8 & 0x1f);
    *(undefined4 *)(DAT_100257e0[4] + 0xc4 + DAT_100257d8 * 4) = 0;
    *(char *)(DAT_100257e0[4] + 0x43) = *(char *)(DAT_100257e0[4] + 0x43) + -1;
    if (*(char *)(DAT_100257e0[4] + 0x43) == '\0') {
      DAT_100257e0[1] = DAT_100257e0[1] & 0xfffffffe;
    }
    puVar2 = param_1;
    if (DAT_100257e0[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_100257e0[3],0,0x8000);
      HeapFree(DAT_100257ec,0,(LPVOID)DAT_100257e0[4]);
      FUN_1001d020(DAT_100257e0,DAT_100257e0 + 5,
                   (DAT_100257e4 * 0x14 - (int)DAT_100257e0) + -0x14 + DAT_100257e8);
      DAT_100257e4 = DAT_100257e4 + -1;
      if (DAT_100257e0 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_100257dc = DAT_100257e8;
      puVar2 = param_1;
    }
  }
  DAT_100257e0 = puVar2;
  DAT_100257d8 = uVar5;
  return;
}




======================================================================
// Function: FUN_1001ab49 @ 1001ab49
======================================================================

int * __cdecl FUN_1001ab49(uint *param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar8 = DAT_100257e8 + DAT_100257e4 * 5;
  uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar7 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar5 = (byte)iVar7;
  param_1 = DAT_100257dc;
  if (iVar7 < 0x20) {
    local_10 = 0xffffffff >> (bVar5 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    local_c = 0xffffffff >> (bVar5 - 0x20 & 0x1f);
    local_10 = 0;
  }
  for (; (param_1 < puVar8 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  puVar11 = DAT_100257e8;
  if (param_1 == puVar8) {
    for (; (puVar11 < DAT_100257dc && ((puVar11[1] & local_c) == 0 && (*puVar11 & local_10) == 0));
        puVar11 = puVar11 + 5) {
    }
    param_1 = puVar11;
    if (puVar11 == DAT_100257dc) {
      for (; (puVar11 < puVar8 && (puVar11[2] == 0)); puVar11 = puVar11 + 5) {
      }
      puVar12 = DAT_100257e8;
      param_1 = puVar11;
      if (puVar11 == puVar8) {
        for (; (puVar12 < DAT_100257dc && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {
        }
        param_1 = puVar12;
        if ((puVar12 == DAT_100257dc) && (param_1 = FUN_1001ae52(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar7 = FUN_1001af03((int)param_1);
      *(int *)param_1[4] = iVar7;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar4 = (int *)param_1[4];
  local_8 = *piVar4;
  if ((local_8 == -1) ||
     ((piVar4[local_8 + 0x31] & local_c) == 0 && (piVar4[local_8 + 0x11] & local_10) == 0)) {
    local_8 = 0;
    puVar8 = (uint *)(piVar4 + 0x11);
    if ((piVar4[0x31] & local_c) == 0 && (piVar4[0x11] & local_10) == 0) {
      do {
        puVar11 = puVar8 + 0x21;
        local_8 = local_8 + 1;
        puVar8 = puVar8 + 1;
      } while ((*puVar11 & local_c) == 0 && (local_10 & *puVar8) == 0);
    }
  }
  iVar7 = 0;
  piVar2 = piVar4 + local_8 * 0x81 + 0x51;
  local_10 = piVar4[local_8 + 0x11] & local_10;
  if (local_10 == 0) {
    local_10 = piVar4[local_8 + 0x31] & local_c;
    iVar7 = 0x20;
  }
  for (; -1 < (int)local_10; local_10 = local_10 << 1) {
    iVar7 = iVar7 + 1;
  }
  piVar10 = (int *)piVar2[iVar7 * 2 + 1];
  iVar9 = *piVar10 - uVar6;
  iVar14 = (iVar9 >> 4) + -1;
  if (0x3f < iVar14) {
    iVar14 = 0x3f;
  }
  DAT_100257dc = param_1;
  if (iVar14 != iVar7) {
    if (piVar10[1] == piVar10[2]) {
      if (iVar7 < 0x20) {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 & 0x1f));
        piVar4[local_8 + 0x11] = uVar13 & piVar4[local_8 + 0x11];
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar13;
        }
      }
      else {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 - 0x20 & 0x1f));
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] & uVar13;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar13;
        }
      }
    }
    *(int *)(piVar10[2] + 4) = piVar10[1];
    *(int *)(piVar10[1] + 8) = piVar10[2];
    if (iVar9 == 0) goto LAB_1001ae0f;
    piVar10[1] = piVar2[iVar14 * 2 + 1];
    piVar10[2] = (int)(piVar2 + iVar14 * 2);
    (piVar2 + iVar14 * 2)[1] = (int)piVar10;
    *(int **)(piVar10[1] + 8) = piVar10;
    if (piVar10[1] == piVar10[2]) {
      cVar3 = *(char *)(iVar14 + 4 + (int)piVar4);
      bVar5 = (byte)iVar14;
      if (iVar14 < 0x20) {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar5 & 0x1f);
        }
        piVar4[local_8 + 0x11] = piVar4[local_8 + 0x11] | 0x80000000U >> (bVar5 & 0x1f);
      }
      else {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
        }
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar9 != 0) {
    *piVar10 = iVar9;
    *(int *)(iVar9 + -4 + (int)piVar10) = iVar9;
  }
LAB_1001ae0f:
  piVar10 = (int *)((int)piVar10 + iVar9);
  *piVar10 = uVar6 + 1;
  *(uint *)((int)piVar10 + (uVar6 - 4)) = uVar6 + 1;
  iVar7 = *piVar2;
  *piVar2 = iVar7 + 1;
  if (((iVar7 == 0) && (param_1 == DAT_100257e0)) && (local_8 == DAT_100257d8)) {
    DAT_100257e0 = (uint *)0x0;
  }
  *piVar4 = local_8;
  return piVar10 + 1;
}




======================================================================
// Function: FUN_1001ae52 @ 1001ae52
======================================================================

undefined4 * FUN_1001ae52(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_100257e4 == DAT_100257d4) {
    pvVar2 = HeapReAlloc(DAT_100257ec,0,DAT_100257e8,(DAT_100257d4 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_100257d4 = DAT_100257d4 + 0x10;
    DAT_100257e8 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_100257e8 + DAT_100257e4 * 0x14);
  pvVar2 = HeapAlloc(DAT_100257ec,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_100257e4 = DAT_100257e4 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_100257ec,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}




======================================================================
// Function: FUN_1001af03 @ 1001af03
======================================================================

int __cdecl FUN_1001af03(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LPVOID pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *lpAddress;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar9 = 0;
  for (iVar4 = *(int *)(param_1 + 8); -1 < iVar4; iVar4 = iVar4 << 1) {
    iVar9 = iVar9 + 1;
  }
  iVar8 = 0x3f;
  iVar4 = iVar9 * 0x204 + 0x144 + iVar3;
  iVar5 = iVar4;
  do {
    *(int *)(iVar5 + 8) = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    iVar5 = iVar5 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  lpAddress = (int *)(iVar9 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar6 == (LPVOID)0x0) {
    iVar9 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      piVar7 = lpAddress + 4;
      do {
        piVar7[-2] = -1;
        piVar7[0x3fb] = -1;
        piVar7[-1] = 0xff0;
        *piVar7 = (int)(piVar7 + 0x3ff);
        piVar7[1] = (int)(piVar7 + -0x401);
        piVar7[0x3fa] = 0xff0;
        piVar1 = piVar7 + 0x3fc;
        piVar7 = piVar7 + 0x400;
      } while (piVar1 <= lpAddress + 0x1c00);
    }
    *(int **)(iVar4 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = iVar4 + 0x1f8;
    *(int **)(iVar4 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = iVar4 + 0x1f8;
    *(undefined4 *)(iVar3 + 0x44 + iVar9 * 4) = 0;
    *(undefined4 *)(iVar3 + 0xc4 + iVar9 * 4) = 1;
    cVar2 = *(char *)(iVar3 + 0x43);
    *(char *)(iVar3 + 0x43) = cVar2 + '\x01';
    if (cVar2 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar9 & 0x1f));
  }
  return iVar9;
}




======================================================================
// Function: FUN_1001affe @ 1001affe
======================================================================

undefined4 __cdecl FUN_1001affe(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_c;
  
  uVar5 = param_1[4];
  uVar12 = param_3 + 0x17U & 0xfffffff0;
  uVar10 = param_2 - param_1[3] >> 0xf;
  iVar3 = uVar10 * 0x204 + 0x144 + uVar5;
  iVar6 = *(int *)(param_2 + -4);
  iVar9 = iVar6 + -1;
  uVar13 = *(uint *)(iVar6 + -5 + param_2);
  iVar6 = iVar6 + -5 + param_2;
  if (iVar9 < (int)uVar12) {
    if (((uVar13 & 1) != 0) || ((int)(uVar13 + iVar9) < (int)uVar12)) {
      return 0;
    }
    local_c = ((int)uVar13 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
    iVar6 = uVar13 + (iVar9 - uVar12);
    if (0 < iVar6) {
      uVar13 = (iVar6 >> 4) - 1;
      iVar9 = param_2 + -4 + uVar12;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
      iVar3 = iVar3 + uVar13 * 8;
      *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar3 + 4);
      *(int *)(iVar9 + 8) = iVar3;
      *(int *)(iVar3 + 4) = iVar9;
      *(int *)(*(int *)(iVar9 + 4) + 8) = iVar9;
      if (*(int *)(iVar9 + 4) == *(int *)(iVar9 + 8)) {
        cVar4 = *(char *)(uVar13 + 4 + uVar5);
        *(char *)(uVar13 + 4 + uVar5) = cVar4 + '\x01';
        bVar8 = (byte)uVar13;
        if (uVar13 < 0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          bVar8 = bVar8 - 0x20;
        }
        *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
      }
      piVar2 = (int *)(param_2 + -4 + uVar12);
      *piVar2 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar2) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;
  }
  else if ((int)uVar12 < iVar9) {
    param_3 = iVar9 - uVar12;
    *(uint *)(param_2 + -4) = uVar12 + 1;
    piVar2 = (int *)(param_2 + -4 + uVar12);
    uVar11 = (param_3 >> 4) - 1;
    piVar2[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar12;
          }
        }
      }
      *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
      *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
      param_3 = param_3 + uVar13;
      uVar11 = (param_3 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar6 = iVar3 + uVar11 * 8;
    piVar2[1] = *(int *)(iVar3 + 4 + uVar11 * 8);
    piVar2[2] = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    *(int **)(piVar2[1] + 8) = piVar2;
    if (piVar2[1] == piVar2[2]) {
      cVar4 = *(char *)(uVar11 + 4 + uVar5);
      *(char *)(uVar11 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar11;
      if (uVar11 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        bVar8 = bVar8 - 0x20;
      }
      *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
    }
    *piVar2 = param_3;
    *(int *)(param_3 + -4 + (int)piVar2) = param_3;
  }
  return 1;
}




======================================================================
// Function: FUN_1001b2f4 @ 1001b2f4
======================================================================

undefined4 __cdecl FUN_1001b2f4(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_1002517c != (code *)0x0) {
    iVar1 = (*DAT_1002517c)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1001b3d5 @ 1001b3d5
======================================================================

void FUN_1001b3d5(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}




======================================================================
// Function: FUN_1001b3f0 @ 1001b3f0
======================================================================

void FUN_1001b3f0(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021ce0;
  puStack_10 = &LAB_1001b318;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_1001c221();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_1001c221();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_1001d355();
  return;
}




======================================================================
// Function: FUN_1001b451 @ 1001b451
======================================================================

void FUN_1001b451(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021cf8;
  puStack_10 = &LAB_1001b318;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_100243fc != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_100243fc)();
  }
  local_8 = 0xffffffff;
  FUN_1001b3f0();
  return;
}




======================================================================
// Function: FUN_1001b4a7 @ 1001b4a7
======================================================================

void __fastcall FUN_1001b4a7(void *param_1)

{
  FUN_1001d3a1(param_1,0x10000,0x30000);
  return;
}




======================================================================
// Function: FUN_1001b4b9 @ 1001b4b9
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001b4b9(void)

{
  if (_DAT_10021288 < _DAT_10021d10 - (_DAT_10021d10 / _DAT_10021d18) * _DAT_10021d18) {
    return 1;
  }
  return 0;
}




======================================================================
// Function: FUN_1001b4f7 @ 1001b4f7
======================================================================

void FUN_1001b4f7(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  FUN_1001b4b9();
  return;
}




======================================================================
// Function: FUN_1001b520 @ 1001b520
======================================================================

void __cdecl FUN_1001b520(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this;
  uint uVar3;
  undefined *puVar4;
  
  this = (undefined *)(int)*param_1;
  uVar3 = FUN_1001d547((uint)this);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_100244f0 < 2) {
        uVar3 = (byte)PTR_DAT_100244fc[*param_1 * 2] & 4;
        this = PTR_DAT_100244fc;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_1001d4d2(this,(int)*param_1,4);
        this = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_100244f4;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}




======================================================================
// Function: __fassign @ 1001b5e0
======================================================================

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  void *in_ECX;
  void *local_c;
  void *local_8;
  
  if (flag != 0) {
    local_c = in_ECX;
    local_8 = in_ECX;
    FUN_1001da13(in_ECX,(uint *)&local_c,(byte *)number);
    *(void **)argument = local_c;
    *(void **)(argument + 4) = local_8;
    return;
  }
  FUN_1001da40(in_ECX,(uint *)&number,(byte *)number);
  *(char **)argument = number;
  return;
}




======================================================================
// Function: FUN_1001b61e @ 1001b61e
======================================================================

undefined1 * __cdecl FUN_1001b61e(undefined8 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint local_2c [6];
  int local_14 [4];
  
  FUN_1001dae4((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),local_14,local_2c);
  FUN_1001da6d(param_2 + (uint)(0 < param_3) + (uint)(local_14[0] == 0x2d),param_3 + 1,(int)local_14
              );
  FUN_1001b67f(param_2,param_3,param_4,local_14,'\0');
  return param_2;
}




======================================================================
// Function: FUN_1001b67f @ 1001b67f
======================================================================

undefined1 * __cdecl
FUN_1001b67f(undefined1 *param_1,int param_2,int param_3,int *param_4,char param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint *puVar3;
  int iVar4;
  
  if (param_5 != '\0') {
    FUN_1001b921(param_1 + (*param_4 == 0x2d),(uint)(0 < param_2));
  }
  puVar1 = param_1;
  if (*param_4 == 0x2d) {
    *param_1 = 0x2d;
    puVar1 = param_1 + 1;
  }
  puVar2 = puVar1;
  if (0 < param_2) {
    puVar2 = puVar1 + 1;
    *puVar1 = puVar1[1];
    *puVar2 = DAT_100244f4;
  }
  puVar3 = FUN_1001dc00((uint *)(puVar2 + param_2 + (uint)(param_5 == '\0')),(uint *)"e+000");
  if (param_3 != 0) {
    *(undefined1 *)puVar3 = 0x45;
  }
  if (*(char *)param_4[3] != '0') {
    iVar4 = param_4[1] + -1;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      *(undefined1 *)((int)puVar3 + 1) = 0x2d;
    }
    if (99 < iVar4) {
      *(char *)((int)puVar3 + 2) = *(char *)((int)puVar3 + 2) + (char)(iVar4 / 100);
      iVar4 = iVar4 % 100;
    }
    if (9 < iVar4) {
      *(char *)((int)puVar3 + 3) = *(char *)((int)puVar3 + 3) + (char)(iVar4 / 10);
      iVar4 = iVar4 % 10;
    }
    *(char *)(puVar3 + 1) = (char)puVar3[1] + (char)iVar4;
  }
  return param_1;
}




======================================================================
// Function: FUN_1001b741 @ 1001b741
======================================================================

char * __cdecl FUN_1001b741(undefined8 *param_1,char *param_2,size_t param_3)

{
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_1001dae4((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  FUN_1001da6d(param_2 + (local_14 == 0x2d),local_10 + param_3,(int)&local_14);
  FUN_1001b796(param_2,param_3,&local_14,'\0');
  return param_2;
}




======================================================================
// Function: FUN_1001b796 @ 1001b796
======================================================================

char * __cdecl FUN_1001b796(char *param_1,size_t param_2,int *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = param_3[1];
  if ((param_4 != '\0') && (iVar1 - 1U == param_2)) {
    iVar2 = *param_3;
    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = '0';
    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = '\0';
  }
  pcVar3 = param_1;
  if (*param_3 == 0x2d) {
    *param_1 = '-';
    pcVar3 = param_1 + 1;
  }
  if (param_3[1] < 1) {
    FUN_1001b921(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + param_3[1];
  }
  if (0 < (int)param_2) {
    FUN_1001b921(pcVar3,1);
    *pcVar3 = DAT_100244f4;
    iVar1 = param_3[1];
    if (iVar1 < 0) {
      if ((param_4 != '\0') || (-iVar1 <= (int)param_2)) {
        param_2 = -iVar1;
      }
      FUN_1001b921(pcVar3 + 1,param_2);
      _memset(pcVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}




======================================================================
// Function: FUN_1001b83d @ 1001b83d
======================================================================

void __cdecl FUN_1001b83d(undefined8 *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_1001dae4((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  iVar1 = local_10 + -1;
  FUN_1001da6d(param_2 + (local_14 == 0x2d),param_3,(int)&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((int)param_3 <= local_10)) {
    FUN_1001b67f(param_2,param_3,param_4,&local_14,'\x01');
  }
  else {
    pcVar2 = param_2 + (local_14 == 0x2d);
    if (iVar1 < local_10) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_1001b796(param_2,param_3,&local_14,'\x01');
  }
  return;
}




======================================================================
// Function: __cfltcvt @ 1001b8d0
======================================================================

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_1001b61e(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_1001b741(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined1 *)FUN_1001b83d(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}




======================================================================
// Function: FUN_1001b921 @ 1001b921
======================================================================

void __cdecl FUN_1001b921(char *param_1,int param_2)

{
  size_t sVar1;
  
  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_1001d020((undefined4 *)(param_1 + param_2),(undefined4 *)param_1,sVar1 + 1);
  }
  return;
}




======================================================================
// Function: FUN_1001b946 @ 1001b946
======================================================================

undefined4 __cdecl
FUN_1001b946(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_1001b451();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_1001b9e1(param_1,param_2,param_3,param_4,(int)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_1001bc9b((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}




======================================================================
// Function: FUN_1001b9e1 @ 1001b9e1
======================================================================

void __cdecl
FUN_1001b9e1(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  bool bVar2;
  DWORD *pDVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_1001b451();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_1001c221();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_1001c221();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_1001c221();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_1001de38(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_1001b451();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_1001bb69;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_1001b451();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_10019fce(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_1001c0bd((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; iVar5 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_1001bc3e(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_1001bd39(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                iVar5 = local_14;
                goto LAB_1001bb49;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
        }
LAB_1001bb49:
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_1001bb69:
  if (param_6 == '\0') {
    FUN_1001bb94(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_1001b3f0();
  return;
}




======================================================================
// Function: FUN_1001bb94 @ 1001bb94
======================================================================

void __cdecl
FUN_1001bb94(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  pDVar1 = FUN_1001c221();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_10019ea3(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_10019fce(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_1001bd39(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}




======================================================================
// Function: FUN_1001bc3e @ 1001bc3e
======================================================================

undefined4 __cdecl FUN_1001bc3e(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_1001bc95:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_1001bc6f:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_1001bc95;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_1001bc6f;
    }
    uVar2 = 0;
  }
  return uVar2;
}




======================================================================
// Function: FUN_1001bc9b @ 1001bc9b
======================================================================

void __cdecl FUN_1001bc9b(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021d50;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_1001b451();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  ExceptionList = local_14;
  return;
}




======================================================================
// Function: FUN_1001bd39 @ 1001bd39
======================================================================

void __cdecl
FUN_1001bd39(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_1001bef9((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  FUN_10019da5(param_10,param_1);
  FUN_1001bc9b((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_1001bdb4((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_10019d63(UNRECOVERED_JUMPTABLE);
  }
  return;
}




======================================================================
// Function: FUN_1001bdb4 @ 1001bdb4
======================================================================

undefined4 __cdecl
FUN_1001bdb4(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_10021d60;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_1001c221();
  FUN_1001c221();
  pDVar1 = FUN_1001c221();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_1001c221();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_10019e2a(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_1001be81();
  ExceptionList = local_14;
  return uVar2;
}




======================================================================
// Function: FUN_1001be81 @ 1001be81
======================================================================

void FUN_1001be81(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_1001c221();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_1001c221();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_1001c0bd((int)unaff_EDI);
  }
  return;
}




======================================================================
// Function: FUN_1001bef9 @ 1001bef9
======================================================================

void __cdecl FUN_1001bef9(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar4;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  uint uVar5;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021d78;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  if (*(int *)(param_3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(param_3 + 8) == 0) {
    return;
  }
  piVar1 = (int *)(*(int *)(param_3 + 8) + 0xc + param_2);
  local_8 = 0;
  if ((*param_3 & 8) == 0) {
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        ExceptionList = &local_14;
        bVar2 = FUN_1001de38(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_1001de54(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_1001c124(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_1001d020(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_1001de38(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_1001de54(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_1001de70(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) != 0) {
            FUN_1001c124(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_10019d9e(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_1001c124(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_10019d97(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_1001de38(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_1001de54(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_1001d020(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_1001bf87;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_1001de38(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_1001de54(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_1001bf87:
      iVar3 = FUN_1001c124(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_1001b451();
  ExceptionList = local_14;
  return;
}




======================================================================
// Function: FUN_1001c0bd @ 1001c0bd
======================================================================

void __cdecl FUN_1001c0bd(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_10021d88;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_10019d97(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}




======================================================================
// Function: FUN_1001c124 @ 1001c124
======================================================================

int __cdecl FUN_1001c124(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  iVar2 = *param_2 + param_1;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]) + iVar1;
  }
  return iVar2;
}




======================================================================
// Function: __CallSettingFrame@12 @ 1001c150
======================================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}




======================================================================
// Function: FUN_1001c19c @ 1001c19c
======================================================================

undefined4 FUN_1001c19c(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_1001a6aa();
  DAT_10024420 = TlsAlloc();
  if (DAT_10024420 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_1001df14(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_10024420,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1001c20e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1001c1f0 @ 1001c1f0
======================================================================

void FUN_1001c1f0(void)

{
  FUN_1001a6d3();
  if (DAT_10024420 != 0xffffffff) {
    TlsFree(DAT_10024420);
    DAT_10024420 = 0xffffffff;
  }
  return;
}




======================================================================
// Function: FUN_1001c20e @ 1001c20e
======================================================================

void __cdecl FUN_1001c20e(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_10024740;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}




======================================================================
// Function: FUN_1001c221 @ 1001c221
======================================================================

DWORD * FUN_1001c221(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_10024420);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_1001df14(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_10024420,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1001c20e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_1001c27c;
      }
    }
    __amsg_exit(0x10);
  }
LAB_1001c27c:
  SetLastError(dwErrCode);
  return lpTlsValue;
}




======================================================================
// Function: FUN_1001c288 @ 1001c288
======================================================================

void __cdecl FUN_1001c288(LPVOID param_1)

{
  if (DAT_10024420 != 0xffffffff) {
    if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_10024420), param_1 != (LPVOID)0x0)) {
      if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)((int)param_1 + 0x24));
      }
      if (*(LPVOID *)((int)param_1 + 0x28) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)((int)param_1 + 0x28));
      }
      if (*(LPVOID *)((int)param_1 + 0x30) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)((int)param_1 + 0x30));
      }
      if (*(LPVOID *)((int)param_1 + 0x38) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)((int)param_1 + 0x38));
      }
      if (*(LPVOID *)((int)param_1 + 0x40) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)((int)param_1 + 0x40));
      }
      if (*(LPVOID *)((int)param_1 + 0x44) != (LPVOID)0x0) {
        Mem_Free(*(LPVOID *)((int)param_1 + 0x44));
      }
      if (*(undefined **)((int)param_1 + 0x50) != &DAT_10024740) {
        Mem_Free(*(undefined **)((int)param_1 + 0x50));
      }
      Mem_Free(param_1);
    }
    TlsSetValue(DAT_10024420,(LPVOID)0x0);
    return;
  }
  return;
}




======================================================================
// Function: FUN_1001c328 @ 1001c328
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
FUN_1001c328(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_28 [2];
  int local_20;
  int local_18;
  uint local_14;
  int local_c;
  
  uVar3 = param_1 - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    iVar2 = -1;
  }
  else {
    iVar4 = *(int *)(&DAT_100248ac + param_2 * 4) + param_3;
    if (((uVar3 & 3) == 0) && (2 < param_2)) {
      iVar4 = iVar4 + 1;
    }
    FUN_1001dfa1();
    local_20 = param_4;
    local_18 = param_2 + -1;
    iVar2 = ((param_4 + (uVar3 * 0x16d + iVar4 + (param_1 + -0x76d >> 2)) * 0x18) * 0x3c + param_5)
            * 0x3c + DAT_100247c8 + 0x7c558180 + param_6;
    if ((param_7 == 1) ||
       (((param_7 == -1 && (DAT_100247cc != 0)) &&
        (local_14 = uVar3, local_c = iVar4, bVar1 = FUN_1001e256(local_28),
        CONCAT31(extraout_var,bVar1) != 0)))) {
      iVar2 = iVar2 + _DAT_100247d0;
    }
  }
  return iVar2;
}




======================================================================
// Function: FUN_1001c3f0 @ 1001c3f0
======================================================================

undefined4 * __cdecl FUN_1001c3f0(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_1001c5a7_caseD_2;
        case 3:
          goto switchD_1001c5a7_caseD_3;
        }
        goto switchD_1001c5a7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_1001c5a7_caseD_0;
      case 1:
        goto switchD_1001c5a7_caseD_1;
      case 2:
        goto switchD_1001c5a7_caseD_2;
      case 3:
        goto switchD_1001c5a7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1001c5a7_caseD_2;
            case 3:
              goto switchD_1001c5a7_caseD_3;
            }
            goto switchD_1001c5a7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1001c5a7_caseD_2;
            case 3:
              goto switchD_1001c5a7_caseD_3;
            }
            goto switchD_1001c5a7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1001c5a7_caseD_2;
            case 3:
              goto switchD_1001c5a7_caseD_3;
            }
            goto switchD_1001c5a7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_1001c5a7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_1001c5a7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_1001c5a7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_1001c5a7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_1001c425_caseD_2;
      case 3:
        goto switchD_1001c425_caseD_3;
      }
      goto switchD_1001c425_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_1001c425_caseD_0;
    case 1:
      goto switchD_1001c425_caseD_1;
    case 2:
      goto switchD_1001c425_caseD_2;
    case 3:
      goto switchD_1001c425_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1001c425_caseD_2;
          case 3:
            goto switchD_1001c425_caseD_3;
          }
          goto switchD_1001c425_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1001c425_caseD_2;
          case 3:
            goto switchD_1001c425_caseD_3;
          }
          goto switchD_1001c425_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1001c425_caseD_2;
          case 3:
            goto switchD_1001c425_caseD_3;
          }
          goto switchD_1001c425_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_1001c425_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_1001c425_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_1001c425_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_1001c425_caseD_0:
  return param_1;
}




======================================================================
// Function: FUN_1001c725 @ 1001c725
======================================================================

void FUN_1001c725(void)

{
  if (PTR_FUN_10024308 != (undefined *)0x0) {
    (*(code *)PTR_FUN_10024308)();
  }
  FUN_1001c829((undefined4 *)&DAT_10024008,(undefined4 *)&DAT_10024014);
  FUN_1001c829((undefined4 *)&DAT_10024000,(undefined4 *)&DAT_10024004);
  return;
}




======================================================================
// Function: __exit @ 1001c752
======================================================================

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_1001c772(_Code,1,0);
  return;
}




======================================================================
// Function: FUN_1001c763 @ 1001c763
======================================================================

void FUN_1001c763(void)

{
  FUN_1001c772(0,0,1);
  return;
}




======================================================================
// Function: FUN_1001c772 @ 1001c772
======================================================================

void __cdecl FUN_1001c772(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_1001c817();
  if (DAT_100251c0 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_100251bc = 1;
  DAT_100251b8 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_100257d0 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_100257cc - 4), DAT_100257d0 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_100257d0 <= puVar1);
    }
    FUN_1001c829((undefined4 *)&DAT_10024018,(undefined4 *)&DAT_1002401c);
  }
  FUN_1001c829((undefined4 *)&DAT_10024020,(undefined4 *)&DAT_10024028);
  if (param_3 == 0) {
    DAT_100251c0 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_1001c820();
  return;
}




======================================================================
// Function: FUN_1001c817 @ 1001c817
======================================================================

void FUN_1001c817(void)

{
  FUN_1001a73f(0xd);
  return;
}




======================================================================
// Function: FUN_1001c820 @ 1001c820
======================================================================

void FUN_1001c820(void)

{
  FUN_1001a7a0(0xd);
  return;
}




======================================================================
// Function: FUN_1001c829 @ 1001c829
======================================================================

void __cdecl FUN_1001c829(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}




======================================================================
// Function: FUN_1001c843 @ 1001c843
======================================================================

void FUN_1001c843(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int iVar6;
  uint uVar7;
  UINT UVar8;
  UINT UVar9;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  puVar2 = _malloc(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_100257c0 = 0x20;
  DAT_100256c0 = puVar2;
  for (; puVar2 < DAT_100256c0 + 0x120; puVar2 = puVar2 + 9) {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = 0xffffffff;
    puVar2[2] = 0;
    *(undefined1 *)((int)puVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_8 = (byte *)((int)pUVar5 + UVar8);
    if (0x7ff < (int)UVar8) {
      UVar8 = 0x800;
    }
    UVar9 = UVar8;
    if ((int)DAT_100257c0 < (int)UVar8) {
      puVar2 = &DAT_100256c4;
      do {
        puVar3 = _malloc(0x480);
        UVar9 = DAT_100257c0;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_100257c0 = DAT_100257c0 + 0x20;
        *puVar2 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar2;
        }
        puVar2 = puVar2 + 1;
        UVar9 = UVar8;
      } while ((int)DAT_100257c0 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_100256c0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)local_8;
          *(byte *)(puVar2 + 1) = (byte)*pUVar5;
        }
        local_8 = local_8 + 4;
        uVar7 = uVar7 + 1;
        pUVar5 = (UINT *)((int)pUVar5 + 1);
      } while ((int)uVar7 < (int)UVar9);
    }
  }
  iVar6 = 0;
  do {
    puVar2 = DAT_100256c0 + iVar6 * 9;
    if (DAT_100256c0[iVar6 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;
          }
          goto LAB_1001c9e8;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_1001c9e8:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_100257c0);
      return;
    }
  } while( true );
}




======================================================================
// Function: FUN_1001c9ff @ 1001c9ff
======================================================================

void FUN_1001c9ff(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_100256c0;
  do {
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      if (uVar2 < uVar2 + 0x480) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar2 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          uVar2 = uVar2 + 0x24;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[1].OwningThread;
        } while (uVar2 < *puVar1 + 0x480);
      }
      Mem_Free((LPVOID)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x100257c0);
  return;
}




======================================================================
// Function: FUN_1001ca53 @ 1001ca53
======================================================================

void FUN_1001ca53(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_100257c8 == 0) {
    FUN_1001e93b();
  }
  iVar5 = 0;
  for (puVar6 = DAT_10025104; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_100251a0 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_10025104;
  puVar6 = DAT_10025104;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_1001dc00((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  Mem_Free(DAT_10025104);
  DAT_10025104 = (uint *)0x0;
  *puVar3 = 0;
  DAT_100257c4 = 1;
  return;
}




======================================================================
// Function: FUN_1001cb0c @ 1001cb0c
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cb0c(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_100257c8 == 0) {
    FUN_1001e93b();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_100251c4,0x104);
  _DAT_100251b0 = &DAT_100251c4;
  pbVar2 = &DAT_100251c4;
  if (*DAT_100257f0 != 0) {
    pbVar2 = DAT_100257f0;
  }
  FUN_1001cba5(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_1001cba5(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_10025198 = puVar1;
  _DAT_10025194 = local_8 + -1;
  return;
}




======================================================================
// Function: FUN_1001cba5 @ 1001cba5
======================================================================

void __cdecl FUN_1001cba5(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while( true ) {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      if (((*(byte *)((int)&DAT_100255a0 + bVar1 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      param_1 = pbVar4;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar4 == 0x22) {
      pbVar4 = param_1 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      if ((*(byte *)((int)&DAT_100255a0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_1001cc50;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_1001cc50:
      pbVar4 = pbVar4 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar2 = false;
  puVar7 = param_2;
  while (*pbVar4 != 0) {
    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {
    }
    if (*pbVar4 == 0) break;
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = param_3;
      puVar7 = puVar7 + 1;
      param_2 = puVar7;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar3 = true;
      uVar6 = 0;
      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {
        uVar6 = uVar6 + 1;
      }
      if (*pbVar4 == 0x22) {
        pbVar5 = pbVar4;
        if ((uVar6 & 1) == 0) {
          if ((!bVar2) || (pbVar5 = pbVar4 + 1, pbVar4[1] != 0x22)) {
            bVar3 = false;
            pbVar5 = pbVar4;
          }
          bVar2 = !bVar2;
          puVar7 = param_2;
        }
        uVar6 = uVar6 >> 1;
        pbVar4 = pbVar5;
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar4;
      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_100255a0 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_100255a0 + bVar1 + 1) & 4) != 0) {
            *param_3 = bVar1;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar4 = pbVar4 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}




======================================================================
// Function: FUN_1001cd59 @ 1001cd59
======================================================================

LPSTR FUN_1001cd59(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  size_t _Size;
  LPSTR pCVar6;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  LPSTR local_8;
  char *pcVar8;
  
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_100252c8 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_100252c8 = 1;
LAB_1001cdb0:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      local_8 = (LPSTR)0x0;
      if (((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) &&
         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0),
         local_8 = pCVar6, iVar5 == 0)) {
        Mem_Free(pCVar6);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_100252c8 = 2;
  }
  else {
    if (DAT_100252c8 == 1) goto LAB_1001cdb0;
    if (DAT_100252c8 != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  cVar1 = *pCVar9;
  pcVar7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      pcVar8 = pcVar7;
      pcVar7 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar8 + 2;
    cVar1 = *pcVar7;
  }
  pCVar6 = _malloc((size_t)(pcVar7 + (1 - (int)pCVar9)));
  if (pCVar6 == (LPSTR)0x0) {
    pCVar6 = (LPSTR)0x0;
  }
  else {
    FUN_1001c3f0((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}




======================================================================
// Function: FUN_1001ce8b @ 1001ce8b
======================================================================

void FUN_1001ce8b(void)

{
  if ((DAT_1002510c == 1) || ((DAT_1002510c == 0 && (DAT_10025110 == 1)))) {
    FUN_1001cec4(0xfc);
    if (DAT_100252cc != (code *)0x0) {
      (*DAT_100252cc)();
    }
    FUN_1001cec4(0xff);
  }
  return;
}




======================================================================
// Function: FUN_1001cec4 @ 1001cec4
======================================================================

void __cdecl FUN_1001cec4(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined1 auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];
  
  iVar5 = 0;
  pDVar2 = &DAT_10024458;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x100244e8);
  if (param_1 == (&DAT_10024458)[iVar5 * 2]) {
    if ((DAT_1002510c == 1) || ((DAT_1002510c == 0 && (DAT_10025110 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x1002445c);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_1001dc00(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_1001dc00(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_1001dc10(local_a4,_Dest);
      FUN_1001dc10(local_a4,(uint *)&DAT_10022048);
      FUN_1001dc10(local_a4,*(uint **)(iVar5 * 8 + 0x1002445c));
      auStackY_1e3._3_4_ = 0x1001cfe8;
      FUN_1001e957(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}




======================================================================
// Function: FUN_1001d020 @ 1001d020
======================================================================

undefined4 * __cdecl FUN_1001d020(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_1001d1d7_caseD_2;
        case 3:
          goto switchD_1001d1d7_caseD_3;
        }
        goto switchD_1001d1d7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_1001d1d7_caseD_0;
      case 1:
        goto switchD_1001d1d7_caseD_1;
      case 2:
        goto switchD_1001d1d7_caseD_2;
      case 3:
        goto switchD_1001d1d7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1001d1d7_caseD_2;
            case 3:
              goto switchD_1001d1d7_caseD_3;
            }
            goto switchD_1001d1d7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1001d1d7_caseD_2;
            case 3:
              goto switchD_1001d1d7_caseD_3;
            }
            goto switchD_1001d1d7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1001d1d7_caseD_2;
            case 3:
              goto switchD_1001d1d7_caseD_3;
            }
            goto switchD_1001d1d7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_1001d1d7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_1001d1d7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_1001d1d7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_1001d1d7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_1001d055_caseD_2;
      case 3:
        goto switchD_1001d055_caseD_3;
      }
      goto switchD_1001d055_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_1001d055_caseD_0;
    case 1:
      goto switchD_1001d055_caseD_1;
    case 2:
      goto switchD_1001d055_caseD_2;
    case 3:
      goto switchD_1001d055_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1001d055_caseD_2;
          case 3:
            goto switchD_1001d055_caseD_3;
          }
          goto switchD_1001d055_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1001d055_caseD_2;
          case 3:
            goto switchD_1001d055_caseD_3;
          }
          goto switchD_1001d055_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1001d055_caseD_2;
          case 3:
            goto switchD_1001d055_caseD_3;
          }
          goto switchD_1001d055_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_1001d055_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_1001d055_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_1001d055_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_1001d055_caseD_0:
  return param_1;
}




======================================================================
// Function: FUN_1001d355 @ 1001d355
======================================================================

void FUN_1001d355(void)

{
  FUN_1001cec4(10);
  FUN_1001eade((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}




======================================================================
// Function: FUN_1001d36c @ 1001d36c
======================================================================

uint __thiscall FUN_1001d36c(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_1001d3b7(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_1001d449(uVar1);
  return uVar1;
}




======================================================================
// Function: FUN_1001d3a1 @ 1001d3a1
======================================================================

void __thiscall FUN_1001d3a1(void *this,uint param_1,uint param_2)

{
  FUN_1001d36c(this,param_1,param_2 & 0xfff7ffff);
  return;
}




======================================================================
// Function: FUN_1001d3b7 @ 1001d3b7
======================================================================

uint __cdecl FUN_1001d3b7(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}




======================================================================
// Function: FUN_1001d449 @ 1001d449
======================================================================

uint __cdecl FUN_1001d449(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)((param_1 & 0x10) != 0);
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = param_1 & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((param_1 & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((param_1 & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}




======================================================================
// Function: FUN_1001d4d2 @ 1001d4d2
======================================================================

uint __thiscall FUN_1001d4d2(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_100244fc + param_1 * 2);
  }
  else {
    if ((PTR_DAT_100244fc[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_1001ec9d(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}




======================================================================
// Function: FUN_1001d547 @ 1001d547
======================================================================

uint __cdecl FUN_1001d547(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;
  
  if (DAT_100253d0 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_10025474);
    bVar1 = DAT_10025470 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_10025474);
      this = (void *)0x13;
      FUN_1001a73f(0x13);
    }
    param_1 = FUN_1001d5b6(this,param_1);
    if (bVar1) {
      FUN_1001a7a0(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_10025474);
    }
  }
  return param_1;
}




======================================================================
// Function: FUN_1001d5b6 @ 1001d5b6
======================================================================

uint __thiscall FUN_1001d5b6(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_100253d0 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      uVar1 = param_1 + 0x20;
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_100244f0 < 2) {
        uVar2 = (byte)PTR_DAT_100244fc[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_1001d4d2(this,param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_100244fc[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_1001ede6(DAT_100253d0,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}




======================================================================
// Function: FUN_1001d681 @ 1001d681
======================================================================

undefined4 __cdecl FUN_1001d681(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + (param_2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    piVar1 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar1 != 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}




======================================================================
// Function: FUN_1001d6ca @ 1001d6ca
======================================================================

void __cdecl FUN_1001d6ca(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = FUN_1001f00a(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_1001f00a(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}




======================================================================
// Function: FUN_1001d720 @ 1001d720
======================================================================

undefined4 __cdecl FUN_1001d720(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  puVar1 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  bVar3 = 0x1f - (char)(param_2 % 0x20);
  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&
     (iVar2 = FUN_1001d681(param_1,param_2 + 1), iVar2 == 0)) {
    local_8 = FUN_1001d6ca(param_1,param_2 + -1);
  }
  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}




======================================================================
// Function: FUN_1001d7ac @ 1001d7ac
======================================================================

void __cdecl FUN_1001d7ac(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 - (int)param_2;
  iVar2 = 3;
  do {
    *(undefined4 *)(iVar1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}




======================================================================
// Function: FUN_1001d7c7 @ 1001d7c7
======================================================================

void __cdecl FUN_1001d7c7(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}




======================================================================
// Function: FUN_1001d7d3 @ 1001d7d3
======================================================================

undefined4 __cdecl FUN_1001d7d3(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}




======================================================================
// Function: FUN_1001d7ee @ 1001d7ee
======================================================================

void __cdecl FUN_1001d7ee(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_8;
  
  local_8 = 3;
  iVar2 = (int)param_2 / 0x20;
  iVar5 = (int)param_2 % 0x20;
  param_2 = 0;
  bVar3 = (byte)iVar5;
  puVar6 = param_1;
  do {
    uVar1 = *puVar6;
    *puVar6 = uVar1 >> (bVar3 & 0x1f) | param_2;
    puVar6 = puVar6 + 1;
    param_2 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar5 = 2;
  iVar4 = 8;
  do {
    if (iVar5 < iVar2) {
      *(undefined4 *)(iVar4 + (int)param_1) = 0;
    }
    else {
      *(undefined4 *)(iVar4 + (int)param_1) = *(undefined4 *)(iVar4 + iVar2 * -4 + (int)param_1);
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -4;
  } while (-1 < iVar4);
  return;
}




======================================================================
// Function: FUN_1001d87b @ 1001d87b
======================================================================

undefined4 __cdecl FUN_1001d87b(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c [3];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  uVar3 = uVar1 & 0x7fff;
  iVar4 = uVar3 - 0x3fff;
  local_8 = (uint)*param_1 << 0x10;
  if (iVar4 == -0x3fff) {
    iVar4 = 0;
    iVar2 = FUN_1001d7d3((int *)&local_10);
    if (iVar2 != 0) {
LAB_1001d9a7:
      uVar5 = 0;
      goto LAB_1001d9a9;
    }
    FUN_1001d7c7(&local_10);
  }
  else {
    FUN_1001d7ac((int)local_1c,&local_10);
    iVar2 = FUN_1001d720((int)&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar4 < iVar2 - param_3[2]) {
      FUN_1001d7c7(&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*param_3 <= iVar4) {
          FUN_1001d7c7(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_1001d7ee(&local_10,param_3[3]);
          iVar4 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_1001d9a9;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = param_3[5] + iVar4;
        FUN_1001d7ee(&local_10,param_3[3]);
        goto LAB_1001d9a7;
      }
      FUN_1001d7ac((int)&local_10,local_1c);
      FUN_1001d7ee(&local_10,iVar2 - iVar4);
      FUN_1001d720((int)&local_10,param_3[2]);
      FUN_1001d7ee(&local_10,param_3[3] + 1);
    }
  }
  iVar4 = 0;
  uVar5 = 2;
LAB_1001d9a9:
  local_10 = iVar4 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar5;
}




======================================================================
// Function: FUN_1001d9e7 @ 1001d9e7
======================================================================

void __cdecl FUN_1001d9e7(ushort *param_1,uint *param_2)

{
  FUN_1001d87b(param_1,param_2,(int *)&DAT_10024708);
  return;
}




======================================================================
// Function: FUN_1001d9fd @ 1001d9fd
======================================================================

void __cdecl FUN_1001d9fd(ushort *param_1,uint *param_2)

{
  FUN_1001d87b(param_1,param_2,(int *)&DAT_10024720);
  return;
}




======================================================================
// Function: FUN_1001da13 @ 1001da13
======================================================================

void __thiscall FUN_1001da13(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_1001f1ab(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_1001d9e7(local_10,param_1);
  return;
}




======================================================================
// Function: FUN_1001da40 @ 1001da40
======================================================================

void __thiscall FUN_1001da40(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_1001f1ab(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_1001d9fd(local_10,param_1);
  return;
}




======================================================================
// Function: FUN_1001da6d @ 1001da6d
======================================================================

void __cdecl FUN_1001da6d(char *param_1,int param_2,int param_3)

{
  char *_Str;
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char cVar5;
  
  pcVar1 = param_1;
  pcVar4 = *(char **)(param_3 + 0xc);
  _Str = param_1 + 1;
  *param_1 = '0';
  pcVar2 = _Str;
  if (0 < param_2) {
    param_1 = (char *)param_2;
    param_2 = 0;
    do {
      cVar5 = *pcVar4;
      if (cVar5 == '\0') {
        cVar5 = '0';
      }
      else {
        pcVar4 = pcVar4 + 1;
      }
      *pcVar2 = cVar5;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  *pcVar2 = '\0';
  if ((-1 < param_2) && ('4' < *pcVar4)) {
    while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {
      *pcVar2 = '0';
    }
    *pcVar2 = *pcVar2 + '\x01';
  }
  if (*pcVar1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  }
  else {
    sVar3 = _strlen(_Str);
    FUN_1001d020((undefined4 *)pcVar1,(undefined4 *)_Str,sVar3 + 1);
  }
  return;
}




======================================================================
// Function: FUN_1001dae4 @ 1001dae4
======================================================================

int * __cdecl FUN_1001dae4(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 in_stack_ffffffbc;
  undefined2 uVar4;
  short local_2c;
  char local_2a;
  uint local_28 [6];
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffbc >> 0x10);
  FUN_1001db40(&local_10,&param_1);
  iVar3 = FUN_1001f67c(local_10,uStack_c,CONCAT22(uVar4,uStack_8),0x11,0,&local_2c);
  puVar2 = param_4;
  piVar1 = param_3;
  param_3[2] = iVar3;
  *param_3 = (int)local_2a;
  param_3[1] = (int)local_2c;
  FUN_1001dc00(param_4,local_28);
  piVar1[3] = (int)puVar2;
  return piVar1;
}




======================================================================
// Function: FUN_1001db40 @ 1001db40
======================================================================

void __cdecl FUN_1001db40(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  uVar2 = *param_2;
  local_8 = 0x80000000;
  if (uVar3 == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar4 = 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    iVar4 = 0x7fff;
  }
  else {
    iVar4 = uVar3 + 0x3c00;
  }
  local_8 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  param_1[1] = local_8;
  *param_1 = uVar2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = *param_1 >> 0x1f | local_8 * 2;
    *param_1 = *param_1 * 2;
    param_1[1] = local_8;
    iVar4 = iVar4 + 0xffff;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;
  return;
}




======================================================================
// Function: FUN_1001dc00 @ 1001dc00
======================================================================

uint * __cdecl FUN_1001dc00(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_1001dce8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_1001dce8:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}




======================================================================
// Function: FUN_1001dc10 @ 1001dc10
======================================================================

uint * __cdecl FUN_1001dc10(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_1001dc2c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_1001dc5f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x1001dc7b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_1001dc2c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x1001dc7b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x1001dc7b;
    }
  }
LAB_1001dc5f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x1001dc7b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_1001dce8:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_1001dce8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}




======================================================================
// Function: _memset @ 1001dcf0
======================================================================

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}




======================================================================
// Function: _strlen @ 1001dd50
======================================================================

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_1001dd70;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_1001dda3:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_1001dd70:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_1001dda3;
}




======================================================================
// Function: FUN_1001ddd4 @ 1001ddd4
======================================================================

int FUN_1001ddd4(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_1001b3f0();
    return iVar3;
  }
  if ((DAT_100252d0 != (FARPROC)0x0) &&
     (bVar2 = FUN_1001de70(DAT_100252d0), CONCAT31(extraout_var,bVar2) != 0)) {
    iVar3 = (*DAT_100252d0)(param_1);
    return iVar3;
  }
  return 0;
}




======================================================================
// Function: FUN_1001de38 @ 1001de38
======================================================================

bool __cdecl FUN_1001de38(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}




======================================================================
// Function: FUN_1001de54 @ 1001de54
======================================================================

bool __cdecl FUN_1001de54(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}




======================================================================
// Function: FUN_1001de70 @ 1001de70
======================================================================

bool __cdecl FUN_1001de70(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}




======================================================================
// Function: _strcmp @ 1001de90
======================================================================

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_1001ded4;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_1001dea0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_1001ded4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_1001ded4;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_1001dea0:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_1001ded4:
  return (uint)bVar5 * -2 + 1;
}




======================================================================
// Function: FUN_1001df14 @ 1001df14
======================================================================

int * __cdecl FUN_1001df14(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *_Size;
  uint *puVar3;
  
  _Size = (uint *)(param_1 * param_2);
  puVar3 = _Size;
  if (_Size < (uint *)0xffffffe1) {
    if (_Size == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
  }
  do {
    if (puVar3 < (uint *)0xffffffe1) {
      if (_Size < DAT_100243f8 || (int)_Size - (int)DAT_100243f8 == 0) {
        FUN_1001a73f(9);
        piVar1 = FUN_1001ab49(_Size);
        FUN_1001a7a0(9);
        if (piVar1 != (int *)0x0) {
          _memset(piVar1,0,(size_t)_Size);
          return piVar1;
        }
      }
      piVar1 = HeapAlloc(DAT_100257ec,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_10025178 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_1001b2f4(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}




======================================================================
// Function: FUN_1001dfa1 @ 1001dfa1
======================================================================

void FUN_1001dfa1(void)

{
  if (DAT_10025390 == 0) {
    FUN_1001a73f(0xb);
    if (DAT_10025390 == 0) {
      FUN_1001dfcf();
      DAT_10025390 = DAT_10025390 + 1;
    }
    FUN_1001a7a0(0xb);
  }
  return;
}




======================================================================
// Function: FUN_1001dfcf @ 1001dfcf
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001dfcf(void)

{
  char cVar1;
  char cVar2;
  uint *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  uint *_Source;
  int local_8;
  
  FUN_1001a73f(0xc);
  DAT_10024870 = 0xffffffff;
  DAT_10024860 = 0xffffffff;
  DAT_100252d8 = 0;
  _Str1 = (uint *)FUN_1001f99a("TZ");
  if (_Str1 == (uint *)0x0) {
    FUN_1001a7a0(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_100252e0);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_100247c8 = (void *)(DAT_100252e0 * 0x3c);
    DAT_100252d8 = 1;
    if (DAT_10025326 != 0) {
      DAT_100247c8 = (void *)((int)DAT_100247c8 + DAT_10025334 * 0x3c);
    }
    if ((DAT_1002537a == 0) || (DAT_10025388 == 0)) {
      DAT_100247cc = 0;
      _DAT_100247d0 = 0;
    }
    else {
      DAT_100247cc = 1;
      _DAT_100247d0 = (DAT_10025388 - DAT_10025334) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_100253e0,0x220,(LPCWSTR)&DAT_100252e4,-1,PTR_DAT_10024854,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_10024854 = 0;
    }
    else {
      PTR_DAT_10024854[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_100253e0,0x220,(LPCWSTR)&DAT_10025338,-1,PTR_DAT_10024858,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_10024858[0x3f] = 0;
      return;
    }
LAB_1001e240:
    *PTR_DAT_10024858 = 0;
  }
  else {
    if (((char)*_Str1 != '\0') &&
       ((DAT_1002538c == (uint *)0x0 ||
        (iVar4 = _strcmp((char *)_Str1,(char *)DAT_1002538c), iVar4 != 0)))) {
      Mem_Free(DAT_1002538c);
      sVar5 = _strlen((char *)_Str1);
      DAT_1002538c = _malloc(sVar5 + 1);
      if (DAT_1002538c != (uint *)0x0) {
        FUN_1001dc00(DAT_1002538c,_Str1);
        FUN_1001a7a0(0xc);
        _strncpy(PTR_DAT_10024854,(char *)_Str1,3);
        _Source = (uint *)((int)_Str1 + 3);
        PTR_DAT_10024854[3] = 0;
        cVar1 = *(char *)_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 1;
        }
        iVar4 = FUN_1001f90f(this,(byte *)_Source);
        DAT_100247c8 = (void *)(iVar4 * 0xe10);
        for (; (cVar2 = (char)*_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = (uint *)((int)_Source + 1)) {
        }
        if ((char)*_Source == ':') {
          _Source = (uint *)((int)_Source + 1);
          iVar4 = FUN_1001f90f(DAT_100247c8,(byte *)_Source);
          DAT_100247c8 = (void *)((int)DAT_100247c8 + iVar4 * 0x3c);
          for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
              _Source = (uint *)((int)_Source + 1)) {
          }
          if ((char)*_Source == ':') {
            _Source = (uint *)((int)_Source + 1);
            iVar4 = FUN_1001f90f(DAT_100247c8,(byte *)_Source);
            DAT_100247c8 = (void *)((int)DAT_100247c8 + iVar4);
            for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
                _Source = (uint *)((int)_Source + 1)) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_100247c8 = (void *)-(int)DAT_100247c8;
        }
        DAT_100247cc = (int)(char)*_Source;
        if (DAT_100247cc != 0) {
          _strncpy(PTR_DAT_10024858,(char *)_Source,3);
          PTR_DAT_10024858[3] = 0;
          return;
        }
        goto LAB_1001e240;
      }
    }
    FUN_1001a7a0(0xc);
  }
  return;
}




======================================================================
// Function: FUN_1001e256 @ 1001e256
======================================================================

bool __cdecl FUN_1001e256(int *param_1)

{
  bool bVar1;
  
  FUN_1001a73f(0xb);
  bVar1 = FUN_1001e277(param_1);
  FUN_1001a7a0(0xb);
  return bVar1;
}




======================================================================
// Function: FUN_1001e277 @ 1001e277
======================================================================

bool __cdecl FUN_1001e277(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (DAT_100247cc != 0) {
    uVar5 = param_1[5];
    if ((uVar5 != DAT_10024860) || (uVar5 != DAT_10024870)) {
      if (DAT_100252d8 == 0) {
        FUN_1001e423(1,1,uVar5,4,1,0,0,2,0,0,0);
        FUN_1001e423(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_10025378 != 0) {
          uVar6 = (uint)DAT_1002537e;
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)DAT_1002537c;
          uVar6 = 0;
          uVar4 = (uint)DAT_1002537e;
        }
        FUN_1001e423(1,(uint)(DAT_10025378 == 0),uVar5,(uint)DAT_1002537a,uVar4,uVar3,uVar6,
                     (uint)DAT_10025380,(uint)DAT_10025382,(uint)DAT_10025384,(uint)DAT_10025386);
        if (DAT_10025324 != 0) {
          uVar6 = (uint)DAT_1002532a;
          uVar3 = 0;
          uVar4 = 0;
          uVar5 = param_1[5];
        }
        else {
          uVar3 = (uint)DAT_10025328;
          uVar6 = 0;
          uVar4 = (uint)DAT_1002532a;
          uVar5 = param_1[5];
        }
        FUN_1001e423(0,(uint)(DAT_10025324 == 0),uVar5,(uint)DAT_10025326,uVar4,uVar3,uVar6,
                     (uint)DAT_1002532c,(uint)DAT_1002532e,(uint)DAT_10025330,(uint)DAT_10025332);
      }
    }
    iVar1 = param_1[7];
    if (DAT_10024864 < DAT_10024874) {
      if ((DAT_10024864 <= iVar1) && (iVar1 <= DAT_10024874)) {
        if ((DAT_10024864 < iVar1) && (iVar1 < DAT_10024874)) {
          return true;
        }
LAB_1001e3ef:
        iVar2 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_10024864) {
          return DAT_10024868 <= iVar2;
        }
        return iVar2 < DAT_10024878;
      }
    }
    else {
      if (iVar1 < DAT_10024874) {
        return true;
      }
      if (DAT_10024864 < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_10024874) || (DAT_10024864 <= iVar1)) goto LAB_1001e3ef;
    }
  }
  return false;
}




======================================================================
// Function: FUN_1001e423 @ 1001e423
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001e423(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = (&DAT_10024878)[param_4];
    }
    else {
      iVar1 = *(int *)(&DAT_100248ac + param_4 * 4);
    }
    iVar2 = (int)(param_3 * 0x16d + -0x63db + iVar1 + 1 + ((int)(param_3 - 1) >> 2)) % 7;
    if (param_6 < iVar2) {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_1002487c + param_4 * 4);
      }
      else {
        iVar2 = *(int *)(&DAT_100248b0 + param_4 * 4);
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = (&DAT_10024878)[param_4];
    }
    else {
      iVar1 = *(int *)(&DAT_100248ac + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_10024860 = param_3;
    DAT_10024868 = ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000 + param_11;
    DAT_10024864 = iVar1;
  }
  else {
    DAT_10024878 = ((param_8 * 0x3c + param_9) * 0x3c + _DAT_100247d0 + param_10) * 1000 + param_11;
    if (DAT_10024878 < 0) {
      DAT_10024878 = DAT_10024878 + 86400000;
      DAT_10024874 = iVar1 + -1;
    }
    else {
      DAT_10024874 = iVar1;
      if (86399999 < DAT_10024878) {
        DAT_10024878 = DAT_10024878 + -86400000;
        DAT_10024874 = iVar1 + 1;
      }
    }
    DAT_10024870 = param_3;
  }
  return;
}




======================================================================
// Function: FUN_1001e563 @ 1001e563
======================================================================

undefined4 __cdecl FUN_1001e563(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_1001a73f(0x19);
  CodePage = FUN_1001e710(param_1);
  if (CodePage != DAT_10025478) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_100248f0;
LAB_1001e5a0:
      if (*pUVar5 != CodePage) goto code_r0x1001e5a4;
      local_8 = 0;
      puVar15 = &DAT_100255a0;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x10024900);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_100248e8)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_100255a0 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_1002548c = 1;
      DAT_10025478 = CodePage;
      DAT_100256a4 = FUN_1001e75a(CodePage);
      DAT_10025480 = *(undefined4 *)(iVar12 + 0x100248f4);
      DAT_10025484 = *(undefined4 *)(iVar12 + 0x100248f8);
      DAT_10025488 = *(undefined4 *)(iVar12 + 0x100248fc);
      goto LAB_1001e6f4;
    }
    goto LAB_1001e6ef;
  }
  goto LAB_1001e58a;
code_r0x1001e5a4:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x100249df < (int)pUVar5) goto code_r0x1001e5af;
  goto LAB_1001e5a0;
code_r0x1001e5af:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_100256a4 = 0;
    puVar15 = &DAT_100255a0;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_1002548c = 0;
      DAT_10025478 = CodePage;
    }
    else {
      DAT_10025478 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_100255a0 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_100255a0 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_100256a4 = FUN_1001e75a(CodePage);
      DAT_1002548c = 1;
    }
    DAT_10025480 = 0;
    DAT_10025484 = 0;
    DAT_10025488 = 0;
  }
  else {
    if (DAT_10025394 == 0) {
      uVar14 = 0xffffffff;
      goto LAB_1001e701;
    }
LAB_1001e6ef:
    FUN_1001e78d();
  }
LAB_1001e6f4:
  FUN_1001e7b6();
LAB_1001e58a:
  uVar14 = 0;
LAB_1001e701:
  FUN_1001a7a0(0x19);
  return uVar14;
}




======================================================================
// Function: FUN_1001e710 @ 1001e710
======================================================================

int __cdecl FUN_1001e710(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_10025394 = 1;
                    /* WARNING: Could not recover jumptable at 0x1001e72a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_10025394 = 1;
                    /* WARNING: Could not recover jumptable at 0x1001e73f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_100253e0;
  }
  DAT_10025394 = (uint)bVar2;
  return param_1;
}




======================================================================
// Function: FUN_1001e75a @ 1001e75a
======================================================================

undefined4 __cdecl FUN_1001e75a(int param_1)

{
  if (param_1 == 0x3a4) {
    return 0x411;
  }
  if (param_1 == 0x3a8) {
    return 0x804;
  }
  if (param_1 == 0x3b5) {
    return 0x412;
  }
  if (param_1 != 0x3b6) {
    return 0;
  }
  return 0x404;
}




======================================================================
// Function: FUN_1001e78d @ 1001e78d
======================================================================

void FUN_1001e78d(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_100255a0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_10025478 = 0;
  DAT_1002548c = 0;
  DAT_100256a4 = 0;
  DAT_10025480 = 0;
  DAT_10025484 = 0;
  DAT_10025488 = 0;
  return;
}




======================================================================
// Function: FUN_1001e7b6 @ 1001e7b6
======================================================================

void FUN_1001e7b6(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 uVar8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;
  
  BVar2 = GetCPInfo(DAT_10025478,&local_18);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      local_118[uVar3] = (CHAR)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar9 = local_18.LeadByte + 1;
      do {
        uVar3 = (uint)local_18.LeadByte[0];
        if (uVar3 <= *pBVar9) {
          uVar5 = (*pBVar9 - uVar3) + 1;
          uVar6 = uVar5 >> 2;
          pCVar10 = local_118 + uVar3;
          while (uVar6 != 0) {
            uVar6 = uVar6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_1001ec9d(1,local_118,0x100,local_518,DAT_10025478,DAT_100256a4,0);
    FUN_1001ede6(DAT_100256a4,0x100,local_118,0x100,local_218,0x100,DAT_10025478,0);
    FUN_1001ede6(DAT_100256a4,0x200,local_118,0x100,local_318,0x100,DAT_10025478,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_100255a0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_1001e8c2;
        }
        (&DAT_100254a0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_100255a0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_1001e8c2:
        (&DAT_100254a0)[uVar3] = uVar8;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_100255a0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_1001e90c;
        }
        (&DAT_100254a0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_100255a0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_1001e90c:
        (&DAT_100254a0)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}




======================================================================
// Function: FUN_1001e93b @ 1001e93b
======================================================================

void FUN_1001e93b(void)

{
  if (DAT_100257c8 == 0) {
    FUN_1001e563(-3);
    DAT_100257c8 = 1;
  }
  return;
}




======================================================================
// Function: FUN_1001e957 @ 1001e957
======================================================================

int __cdecl FUN_1001e957(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_10025398 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_10025398 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_10025398 != (FARPROC)0x0) {
        DAT_1002539c = GetProcAddress(hModule,"GetActiveWindow");
        DAT_100253a0 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_1001e9a6;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_1001e9a6:
    if (DAT_1002539c != (FARPROC)0x0) {
      iVar1 = (*DAT_1002539c)();
      if ((iVar1 != 0) && (DAT_100253a0 != (FARPROC)0x0)) {
        iVar1 = (*DAT_100253a0)(iVar1);
      }
    }
    iVar1 = (*DAT_10025398)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}




======================================================================
// Function: _strncpy @ 1001e9e0
======================================================================

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x1001ea1e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1001ea5b;
        goto LAB_1001eac9;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x1001eac5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_1001eac9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1001ea5b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x1001eac5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x1001eac5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x1001eac5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x1001ea1e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_1001ea5b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}




======================================================================
// Function: FUN_1001eade @ 1001eade
======================================================================

undefined4 __cdecl FUN_1001eade(DWORD *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  DWORD local_10;
  DWORD local_c;
  
  bVar1 = false;
  if (param_1 == (DWORD *)0x2) {
    puVar7 = &DAT_100253a4;
    pcVar6 = DAT_100253a4;
LAB_1001eb64:
    bVar1 = true;
    FUN_1001a73f(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_100253b0;
        pcVar6 = DAT_100253b0;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_100253a8;
        pcVar6 = DAT_100253a8;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_100253ac;
        pcVar6 = DAT_100253ac;
      }
      goto LAB_1001eb64;
    }
    pDVar2 = FUN_1001c221();
    uVar3 = FUN_1001ec60((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_1001a7a0(1);
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_1001a7a0(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = 0;
    if (param_1 == (DWORD *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_1001ebd8;
    }
  }
  else {
LAB_1001ebd8:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_100247b8 < DAT_100247bc + DAT_100247b8) {
        iVar4 = DAT_100247b8 * 0xc;
        iVar5 = DAT_100247b8;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_100247bc + DAT_100247b8);
      }
      goto LAB_1001ec16;
    }
  }
  *puVar7 = 0;
LAB_1001ec16:
  if (bVar1) {
    FUN_1001a7a0(1);
  }
  if (param_1 == (DWORD *)0x8) {
    (*pcVar6)(8,pDVar2[0x16]);
  }
  else {
    (*pcVar6)(param_1);
    if ((param_1 != (DWORD *)0xb) && (param_1 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (param_1 == (DWORD *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}




======================================================================
// Function: FUN_1001ec60 @ 1001ec60
======================================================================

uint __cdecl FUN_1001ec60(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_100247c4 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_100247c4 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}




======================================================================
// Function: FUN_1001ec9d @ 1001ec9d
======================================================================

BOOL __cdecl
FUN_1001ec9d(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  undefined1 *puVar1;
  BOOL BVar2;
  int iVar3;
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_10022110;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_100253b8;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_100253b8 == 0) {
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    iVar3 = 1;
    puVar1 = local_1c;
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,"",1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  DAT_100253b8 = iVar3;
  if (DAT_100253b8 != 2) {
    if (DAT_100253b8 == 1) {
      if (param_5 == 0) {
        param_5 = DAT_100253e0;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_1001a250();
        local_1c = &stack0xffffffc8;
        _memset(&stack0xffffffc8,0,iVar3 * 2);
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),
           iVar3 != 0)) {
          BVar2 = GetStringTypeW(param_1,(LPCWSTR)&stack0xffffffc8,iVar3,param_4);
          ExceptionList = local_14;
          return BVar2;
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_6 == 0) {
    param_6 = DAT_100253d0;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}




======================================================================
// Function: FUN_1001ede6 @ 1001ede6
======================================================================

int __cdecl
FUN_1001ede6(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_10022120;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_100253e8 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_100253e8 = 2;
    }
    else {
      DAT_100253e8 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_100202be(param_3,param_4);
  }
  if (DAT_100253e8 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_100253e8 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_100253e0;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_1001a250();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_1001a250();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x3c) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,
                                 (LPWSTR)&stack0xffffffc4,iVar2);
            if (iVar1 == 0) {
              ExceptionList = local_14;
              return 0;
            }
            if (param_6 == 0) {
              param_6 = 0;
              param_5 = (LPWSTR)0x0;
            }
            iVar2 = WideCharToMultiByte(param_7,0x220,(LPCWSTR)&stack0xffffffc4,iVar2,(LPSTR)param_5
                                        ,param_6,(LPCSTR)0x0,(LPBOOL)0x0);
            iVar1 = iVar2;
          }
          else {
            if (param_6 == 0) {
              ExceptionList = local_14;
              return iVar2;
            }
            if (param_6 < iVar2) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,param_5,param_6);
          }
          if (iVar1 != 0) {
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}




======================================================================
// Function: FUN_1001f00a @ 1001f00a
======================================================================

undefined4 __cdecl FUN_1001f00a(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}




======================================================================
// Function: ___add_12 @ 1001f02b
======================================================================

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1001f00a(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_1001f00a(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_1001f00a(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_1001f00a(param_1[2],param_2[2],param_1 + 2);
  return;
}




======================================================================
// Function: FUN_1001f089 @ 1001f089
======================================================================

void __cdecl FUN_1001f089(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}




======================================================================
// Function: FUN_1001f0b7 @ 1001f0b7
======================================================================

void __cdecl FUN_1001f0b7(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}




======================================================================
// Function: FUN_1001f0e4 @ 1001f0e4
======================================================================

void __cdecl FUN_1001f0e4(char *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar1 = param_3;
  local_8 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_14 = *puVar1;
      local_10 = puVar1[1];
      local_c = puVar1[2];
      FUN_1001f089(puVar1);
      FUN_1001f089(puVar1);
      ___add_12(puVar1,&local_14);
      FUN_1001f089(puVar1);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint)*param_1;
      ___add_12(puVar1,&local_14);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  while (puVar1[2] == 0) {
    puVar1[2] = puVar1[1] >> 0x10;
    local_8 = local_8 + 0xfff0;
    puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;
    *puVar1 = *puVar1 << 0x10;
  }
  while ((puVar1[2] & 0x8000) == 0) {
    FUN_1001f089(puVar1);
    local_8 = local_8 + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;
  return;
}




======================================================================
// Function: FUN_1001f1ab @ 1001f1ab
======================================================================

undefined4 __thiscall
FUN_1001f1ab(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  char local_60 [23];
  char local_49;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  byte *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar8 = param_3;
  while( true ) {
    bVar6 = *pbVar8;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar6);
    if ((((bVar6 != 0x20) && (bVar6 != 9)) && (bVar6 != 10)) && (bVar6 != 0xd)) break;
    pbVar8 = pbVar8 + 1;
  }
  iVar1 = 4;
  iVar9 = 0;
  iVar5 = local_14;
LAB_1001f202:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_1001f21f:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_1001f444;
    }
    if (bVar6 == DAT_100244f4) goto LAB_1001f22e;
    if (bVar6 == 0x2b) {
      local_2c = 0;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else if (bVar6 == 0x2d) {
      local_2c = 0x8000;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_1001f51e;
    }
    goto LAB_1001f202;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_1001f21f;
    iVar9 = iVar1;
    if (bVar6 != DAT_100244f4) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_1001f2b3;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_1001f28c;
    }
    goto LAB_1001f202;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_1001f21f;
    if (bVar6 == DAT_100244f4) {
LAB_1001f22e:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = param_3;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_1001f523;
    }
    goto LAB_1001f202;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_100244f0 < 2) {
        uVar3 = (byte)PTR_DAT_100244fc[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_100244fc;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_1001d4d2(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      else {
        local_c = local_c + 1;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    iVar9 = iVar1;
    iVar5 = local_14;
    if (bVar6 != DAT_100244f4) goto LAB_1001f3a0;
    goto LAB_1001f202;
  case 4:
    local_14 = 1;
    local_28 = 1;
    iVar9 = iVar5;
    if (local_8 == 0) {
      while (iVar5 = local_28, iVar9 = local_14, bVar6 == 0x30) {
        local_c = local_c + -1;
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      }
    }
    while( true ) {
      local_14 = iVar9;
      local_28 = iVar5;
      if (DAT_100244f0 < 2) {
        uVar3 = (byte)PTR_DAT_100244fc[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_100244fc;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_1001d4d2(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      iVar5 = local_28;
      iVar9 = local_14;
    }
LAB_1001f3a0:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_1001f2b3:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_1001f28c:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_1001f51e;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_1001f202;
  case 5:
    local_28 = iVar5;
    if (DAT_100244f0 < 2) {
      uVar3 = (byte)PTR_DAT_100244fc[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_100244fc;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_1001d4d2(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = param_3;
    if (uVar3 != 0) goto LAB_1001f444;
    goto LAB_1001f523;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    param_3 = pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_1001f479;
      if (bVar6 == 0x2d) goto LAB_1001f46d;
      if (bVar6 != 0x30) goto LAB_1001f523;
LAB_1001f412:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_1001f202;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = param_3;
      if (bVar6 == 0x30) goto LAB_1001f412;
      goto LAB_1001f523;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_1001f51e;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_1001f4a4;
  default:
    goto switchD_1001f20e_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      if (bVar6 == 0x2b) {
LAB_1001f479:
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      else {
        param_3 = pbVar7;
        if (bVar6 != 0x2d) goto LAB_1001f523;
LAB_1001f46d:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      goto LAB_1001f202;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_1001f20e_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_1001f202;
    goto LAB_1001f523;
  }
  iVar9 = 9;
LAB_1001f444:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_1001f202;
LAB_1001f4a4:
  if (DAT_100244f0 < 2) {
    uVar3 = (byte)PTR_DAT_100244fc[(uint)bVar6 * 2] & 4;
    this = PTR_DAT_100244fc;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = FUN_1001d4d2(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_1001f4ee;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_1001f4e6;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_1001f4a4;
LAB_1001f4e6:
  pbVar7 = (byte *)0x1451;
LAB_1001f4ee:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_100244f0 < 2) {
      uVar3 = (byte)PTR_DAT_100244fc[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_100244fc;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_1001d4d2(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_1001f51e:
  pbVar7 = pbVar8 + -1;
LAB_1001f523:
  *param_2 = (int)pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_1001f631;
  }
  pcVar4 = local_10;
  if (0x18 < local_8) {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar4 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
  }
  else {
    while (pcVar4 = pcVar4 + -1, *pcVar4 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_1001f0e4(local_60,local_8,(uint *)&local_44);
    pbVar8 = local_20;
    if (local_1c < 0) {
      pbVar8 = (byte *)-(int)local_20;
    }
    pbVar8 = pbVar8 + local_c;
    if (local_24 == 0) {
      pbVar8 = pbVar8 + param_5;
    }
    if (local_28 == 0) {
      pbVar8 = pbVar8 + -param_6;
    }
    if ((int)pbVar8 < 0x1451) {
      if (-0x1451 < (int)pbVar8) {
        FUN_1001fcfa((int *)&local_44,(uint)pbVar8,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);
        goto LAB_1001f5b6;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)param_3;
    local_3e = param_3;
    local_44 = local_3a;
  }
LAB_1001f5b6:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = 0;
      local_3a = 0;
      local_3e = (byte *)0x0;
      param_3 = (byte *)0x0;
      local_18 = 1;
    }
  }
  else {
    param_3 = (byte *)0x0;
    local_3a = 0x7fff;
    local_3e = (byte *)0x80000000;
    local_44 = 0;
    local_18 = 2;
  }
LAB_1001f631:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = local_44;
  return local_18;
}




======================================================================
// Function: FUN_1001f67c @ 1001f67c
======================================================================

undefined4 __cdecl
FUN_1001f67c(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined1 local_a;
  char cStack_9;
  undefined4 local_8;
  
  psVar3 = param_6;
  uVar5 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 != 0) || (param_2 != 0)) || (param_1 != 0)) {
    if ((short)uVar5 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_1001f771;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_1001f771:
            pcVar11 = "1#QNAN";
            goto LAB_1001f776;
          }
          pcVar11 = "1#IND";
        }
        FUN_1001dc00((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_1001f776:
        FUN_1001dc00((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 6;
      }
      return 0;
    }
    local_14 = 0;
    local_a = (undefined1)uVar5;
    cStack_9 = (char)(uVar5 >> 8);
    sVar8 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                   0x10);
    local_e = param_2;
    local_12 = param_1;
    FUN_1001fcfa((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_1001fada((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = sVar8;
    iVar10 = param_4;
    if (((param_5 & 1) == 0) || (iVar10 = param_4 + sVar8, 0 < param_4 + sVar8)) {
      if (0x15 < iVar10) {
        iVar10 = 0x15;
      }
      iVar9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
      local_a = 0;
      cStack_9 = '\0';
      param_6 = (short *)0x8;
      do {
        FUN_1001f089((uint *)&local_14);
        param_6 = (short *)((int)param_6 + -1);
      } while (param_6 != (short *)0x0);
      if (iVar9 < 0) {
        param_6 = (short *)0x0;
        for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
          FUN_1001f0b7((uint *)&local_14);
        }
      }
      param_4 = iVar10 + 1;
      psVar6 = psVar3 + 2;
      param_6 = psVar6;
      uVar5 = local_12;
      uVar2 = local_e;
      if (0 < param_4) {
        do {
          local_e._2_2_ = (undefined2)(uVar2 >> 0x10);
          local_e._0_2_ = (undefined2)uVar2;
          local_12._2_2_ = (undefined2)(uVar5 >> 0x10);
          local_12._0_2_ = (undefined2)uVar5;
          param_1 = CONCAT22((undefined2)local_12,local_14);
          param_2 = CONCAT22((undefined2)local_e,local_12._2_2_);
          param_3 = CONCAT13(cStack_9,CONCAT12(local_a,local_e._2_2_));
          local_12 = uVar5;
          local_e = uVar2;
          FUN_1001f089((uint *)&local_14);
          FUN_1001f089((uint *)&local_14);
          ___add_12((uint *)&local_14,&param_1);
          FUN_1001f089((uint *)&local_14);
          cVar4 = cStack_9;
          cStack_9 = '\0';
          psVar6 = (short *)((int)param_6 + 1);
          param_4 = param_4 + -1;
          *(char *)param_6 = cVar4 + '0';
          param_6 = psVar6;
          uVar5 = local_12;
          uVar2 = local_e;
        } while (param_4 != 0);
      }
      psVar7 = psVar6 + -1;
      psVar1 = psVar3 + 2;
      if ('4' < *(char *)((int)psVar6 + -1)) {
        for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
          if ((char)*psVar7 != '9') {
            if (psVar1 <= psVar7) goto LAB_1001f8ce;
            break;
          }
          *(char *)psVar7 = '0';
        }
        psVar7 = (short *)((int)psVar7 + 1);
        *psVar3 = *psVar3 + 1;
LAB_1001f8ce:
        *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_1001f8d0:
        cVar4 = ((char)psVar7 - (char)psVar3) + -3;
        *(char *)((int)psVar3 + 3) = cVar4;
        *(undefined1 *)(cVar4 + 4 + (int)psVar3) = 0;
        return local_8;
      }
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if ((char)*psVar7 != '0') {
          if (psVar1 <= psVar7) goto LAB_1001f8d0;
          break;
        }
      }
      *psVar3 = 0;
      *(undefined1 *)(psVar3 + 1) = 0x20;
      *(undefined1 *)((int)psVar3 + 3) = 1;
      *(char *)psVar1 = '0';
      goto LAB_1001f906;
    }
  }
  *psVar3 = 0;
  *(undefined1 *)(psVar3 + 1) = 0x20;
  *(undefined1 *)((int)psVar3 + 3) = 1;
  *(undefined1 *)(psVar3 + 2) = 0x30;
LAB_1001f906:
  *(undefined1 *)((int)psVar3 + 5) = 0;
  return 1;
}




======================================================================
// Function: FUN_1001f90f @ 1001f90f
======================================================================

int __thiscall FUN_1001f90f(void *this,byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  
  while( true ) {
    if (DAT_100244f0 < 2) {
      uVar1 = (byte)PTR_DAT_100244fc[(uint)*param_1 * 2] & 8;
      this = PTR_DAT_100244fc;
    }
    else {
      puVar6 = (undefined *)0x8;
      uVar1 = FUN_1001d4d2(this,(uint)*param_1,8);
      this = puVar6;
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar5 = param_1 + 1;
  if ((uVar1 == 0x2d) || (uVar4 = uVar1, uVar1 == 0x2b)) {
    uVar4 = (uint)*pbVar5;
    pbVar5 = param_1 + 2;
  }
  iVar3 = 0;
  while( true ) {
    if (DAT_100244f0 < 2) {
      uVar2 = (byte)PTR_DAT_100244fc[uVar4 * 2] & 4;
    }
    else {
      puVar6 = (undefined *)0x4;
      uVar2 = FUN_1001d4d2(this,uVar4,4);
      this = puVar6;
    }
    if (uVar2 == 0) break;
    iVar3 = (uVar4 - 0x30) + iVar3 * 10;
    uVar4 = (uint)*pbVar5;
    pbVar5 = pbVar5 + 1;
  }
  if (uVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return iVar3;
}




======================================================================
// Function: FUN_1001f99a @ 1001f99a
======================================================================

int __cdecl FUN_1001f99a(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (((DAT_100257c4 != 0) &&
      ((DAT_100251a0 != (int *)0x0 ||
       (((DAT_100251a8 != 0 && (iVar1 = FUN_1001fdf3(), iVar1 == 0)) && (DAT_100251a0 != (int *)0x0)
        ))))) && (piVar3 = DAT_100251a0, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}




======================================================================
// Function: FUN_1001fa20 @ 1001fa20
======================================================================

int __cdecl FUN_1001fa20(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return iVar2;
}




======================================================================
// Function: _strncmp @ 1001fa60
======================================================================

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}




======================================================================
// Function: FUN_1001faa0 @ 1001faa0
======================================================================

byte * __cdecl FUN_1001faa0(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = param_1;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    param_1 = pbVar2 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return pbVar2;
}




======================================================================
// Function: FUN_1001fada @ 1001fada
======================================================================

void __cdecl FUN_1001fada(int *param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort uVar11;
  byte local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined1 uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;
  
  piVar5 = param_2;
  piVar4 = param_1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar6 = (ushort)uVar7;
  piVar1 = (int *)(uVar10 + uVar7);
  if (((uVar6 < 0x7fff) && (uVar9 = (ushort)uVar10, uVar9 < 0x7fff)) && ((ushort)piVar1 < 0xbffe)) {
    if ((ushort)piVar1 < 0x3fc0) {
LAB_1001fb7d:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_1001fb7d;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_1001f00a(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                 (uint *)(local_8 + -2));
            if (iVar8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1 = (int *)((int)param_1 + 0xc002);
      if ((short)(ushort)param_1 < 1) {
LAB_1001fc31:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_1001f0b7((uint *)&local_28);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_1001f089((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_1001fc31;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          iVar8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar8 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar8 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar8 = CONCAT22(local_24,uStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar8 >> 0x10);
      uStack_26 = (undefined2)iVar8;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined1)sVar2;
      if (0x7ffe < (ushort)param_1) goto LAB_1001fcda;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_1001fcda:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}




======================================================================
// Function: FUN_1001fcfa @ 1001fcfa
======================================================================

void __cdecl FUN_1001fcfa(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  undefined *puStack_8;
  
  ppuVar3 = &PTR_DAT_10024d00;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      ppuVar3 = (undefined **)0x10024e60;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      ppuVar3 = ppuVar3 + 0x15;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        ppuVar4 = ppuVar3 + uVar2 * 3;
        if (0x7fff < *(ushort *)(ppuVar3 + uVar2 * 3)) {
          local_10 = SUB42(*ppuVar4,0);
          local_e._0_2_ = (undefined2)((uint)*ppuVar4 >> 0x10);
          local_e._2_2_ = SUB42(ppuVar4[1],0);
          uStack_a = (undefined2)((uint)ppuVar4[1] >> 0x10);
          puStack_8 = ppuVar4[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          ppuVar4 = (undefined **)&local_10;
        }
        FUN_1001fada(param_1,(int *)ppuVar4);
      }
    }
  }
  return;
}




======================================================================
// Function: __mbsnbicoll @ 1001fdb4
======================================================================

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_10020041(DAT_100256a4,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_10025478);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}




======================================================================
// Function: FUN_1001fdf3 @ 1001fdf3
======================================================================

undefined4 FUN_1001fdf3(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  uint *lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpWideCharStr = (LPCWSTR)*DAT_100251a8;
  puVar2 = DAT_100251a8;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (uint *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,(LPSTR)lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_100202e9(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}




======================================================================
// Function: FUN_1001fe70 @ 1001fe70
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_1001fe70(void *this,byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  iVar2 = _DAT_10025474;
  if (DAT_100253d0 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_1001febe;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_1001febe:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_10025474 = _DAT_10025474 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_10025470;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_10025474 = iVar2;
      FUN_1001a73f(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_1001ff1f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_1001d5b6(this,uVar8);
      uVar7 = FUN_1001d5b6(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_1001ff1f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_10025474 = _DAT_10025474 + -1;
      UNLOCK();
    }
    else {
      FUN_1001a7a0(0x13);
    }
  }
  return uVar7;
}




======================================================================
// Function: FUN_1001ff40 @ 1001ff40
======================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1001ff40(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  void *this;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  
  iVar2 = _DAT_10025474;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_100253d0 == 0) {
      do {
        bVar3 = *param_1;
        cVar1 = *param_2;
        uVar4 = CONCAT11(bVar3,cVar1);
        if (bVar3 == 0) break;
        uVar4 = CONCAT11(bVar3,cVar1);
        uVar7 = (uint)uVar4;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar7 = (uint)CONCAT11(bVar3 + 0x20,cVar1);
        }
        uVar4 = (ushort)uVar7;
        bVar3 = (byte)uVar7;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar4 = (ushort)CONCAT31((int3)(uVar7 >> 8),bVar3 + 0x20);
        }
        bVar3 = (byte)(uVar4 >> 8);
        bVar8 = bVar3 < (byte)uVar4;
        if (bVar3 != (byte)uVar4) goto LAB_1001ff9f;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_1001ff9f:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_10025474 = _DAT_10025474 + 1;
      UNLOCK();
      bVar8 = 0 < DAT_10025470;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_10025474 = iVar2;
        FUN_1001a73f(0x13);
      }
      uVar9 = (uint)bVar8;
      uVar5 = 0;
      uVar7 = 0;
      do {
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_1);
        uVar7 = CONCAT31((int3)(uVar7 >> 8),*param_2);
        if ((uVar5 == 0) || (uVar7 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar7 = FUN_1001d5b6(param_3,uVar7);
        uVar5 = FUN_1001d5b6(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_10020015;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_10020015:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_10025474 = _DAT_10025474 + -1;
        UNLOCK();
      }
      else {
        FUN_1001a7a0(0x13);
      }
    }
  }
  return uVar6;
}




======================================================================
// Function: FUN_10020041 @ 10020041
======================================================================

int __cdecl
FUN_10020041(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
            UINT param_7)

{
  undefined1 *puVar1;
  int iVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  int iVar5;
  _cpinfo local_40;
  undefined1 *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_10022280;
  puStack_10 = &LAB_1001b318;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffb0;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffb0;
  if (DAT_10025460 == 0) {
    ExceptionList = &local_14;
    iVar2 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringA(0,0,"",1,"",1);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_10025460 = 2;
      puVar1 = local_1c;
    }
    else {
      DAT_10025460 = 1;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  if (0 < param_4) {
    param_4 = FUN_100202be((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_100202be((char *)param_5,param_6);
  }
  if (DAT_10025460 == 2) {
    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar2;
  }
  if (DAT_10025460 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_100253e0;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        ExceptionList = local_14;
        return 2;
      }
      if (1 < param_6) {
        ExceptionList = local_14;
        return 1;
      }
      if (1 < param_4) {
        ExceptionList = local_14;
        return 3;
      }
      BVar3 = GetCPInfo(param_7,&local_40);
      if (BVar3 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (0 < param_4) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 3;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 3;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 3;
      }
      if (0 < param_6) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 1;
      }
    }
    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      FUN_1001a250();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x50) &&
         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,
         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,
                                     local_20), iVar2 != 0)) {
        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          local_8 = 1;
          local_24 = iVar2;
          FUN_1001a250();
          local_8 = 0xffffffff;
          if ((&stack0x00000000 != (undefined1 *)0x50) &&
             (local_2c = &stack0xffffffb0, local_1c = &stack0xffffffb0,
             iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,(LPWSTR)&stack0xffffffb0,
                                         iVar2), iVar5 != 0)) {
            iVar2 = CompareStringW(param_1,param_2,local_28,local_20,(PCNZWCH)&stack0xffffffb0,iVar2
                                  );
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}




======================================================================
// Function: FUN_100202be @ 100202be
======================================================================

int __cdecl FUN_100202be(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = param_2;
  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)
  {
  }
  if (*pcVar1 != '\0') {
    return param_2;
  }
  return (int)pcVar1 - (int)param_1;
}




======================================================================
// Function: FUN_100202e9 @ 100202e9
======================================================================

undefined4 __cdecl FUN_100202e9(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = (uint *)FUN_10020615((byte *)param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(byte *)((int)puVar1 + 1) == 0;
  if (DAT_100251a0 == DAT_100251a4) {
    DAT_100251a0 = FUN_100204c8(DAT_100251a0);
  }
  if (DAT_100251a0 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_100251a8 == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_100251a0 = _malloc(4);
      if (DAT_100251a0 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_100251a0 = 0;
      if (DAT_100251a8 == (undefined4 *)0x0) {
        DAT_100251a8 = _malloc(4);
        if (DAT_100251a8 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_100251a8 = 0;
      }
    }
    else {
      iVar2 = FUN_1001fdf3();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_100251a0;
  iVar2 = FUN_10020470((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = FUN_1001a296(piVar3,(uint *)(iVar2 * 4 + 8));
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_1002041d;
    }
    piVar6 = piVar3 + iVar2;
    Mem_Free((LPVOID)piVar3[iVar2]);
    for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
      iVar2 = iVar2 + 1;
      *piVar6 = piVar6[1];
    }
    piVar3 = FUN_1001a296(piVar3,(uint *)(iVar2 << 2));
    if (piVar3 == (int *)0x0) goto LAB_1002041d;
  }
  DAT_100251a0 = piVar3;
LAB_1002041d:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (uint *)0x0) {
      FUN_1001dc00(lpName,param_1);
      pbVar5 = (byte *)(((int)lpName - (int)param_1) + (int)puVar1);
      *pbVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(pbVar5 + 1)));
      Mem_Free(lpName);
    }
  }
  return 0;
}




======================================================================
// Function: FUN_10020470 @ 10020470
======================================================================

int __cdecl FUN_10020470(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;
  
  _Str2 = (uchar *)*DAT_100251a0;
  piVar2 = DAT_100251a0;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_100251a0 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_100251a0 >> 2;
}




======================================================================
// Function: FUN_100204c8 @ 100204c8
======================================================================

undefined4 * __cdecl FUN_100204c8(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    puVar4 = (uint *)*param_1;
    puVar6 = puVar3;
    while (puVar4 != (uint *)0x0) {
      param_1 = param_1 + 1;
      puVar4 = FUN_100206ac(puVar4);
      *puVar6 = puVar4;
      puVar6 = puVar6 + 1;
      puVar4 = (uint *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}




======================================================================
// Function: FUN_10020615 @ 10020615
======================================================================

byte * __cdecl FUN_10020615(byte *param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (DAT_1002548c == 0) {
    pbVar2 = (byte *)_strchr((char *)param_1,param_2);
  }
  else {
    FUN_1001a73f(0x19);
    while( true ) {
      bVar1 = *param_1;
      uVar3 = (uint)bVar1;
      if (bVar1 == 0) break;
      if ((*(byte *)((int)&DAT_100255a0 + uVar3 + 1) & 4) == 0) {
        pbVar2 = param_1;
        if (param_2 == uVar3) break;
      }
      else {
        pbVar2 = param_1 + 1;
        if (param_1[1] == 0) {
          FUN_1001a7a0(0x19);
          return (byte *)0x0;
        }
        if (param_2 == CONCAT11(bVar1,param_1[1])) {
          FUN_1001a7a0(0x19);
          return param_1;
        }
      }
      param_1 = pbVar2 + 1;
    }
    FUN_1001a7a0(0x19);
    pbVar2 = (byte *)(~-(uint)(param_2 != uVar3) & (uint)param_1);
  }
  return pbVar2;
}




======================================================================
// Function: FUN_100206ac @ 100206ac
======================================================================

uint * __cdecl FUN_100206ac(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;
  
  if (param_1 != (uint *)0x0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      puVar2 = FUN_1001dc00(puVar2,param_1);
      return puVar2;
    }
  }
  return (uint *)0x0;
}




======================================================================
// Function: _strchr @ 100206f0
======================================================================

/* Library Function - Single Match
    _strchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}




======================================================================
// Function: RtlUnwind @ 100207ac
======================================================================

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x100207ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}




======================================================================
// Function: Unwind@100207c0 @ 100207c0
======================================================================

void Unwind_100207c0(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  Cleanup_WindowState(*(int *)(unaff_EBP + -0x14));
  return;
}




======================================================================
// Function: Unwind@10020800 @ 10020800
======================================================================

void Unwind_10020800(void)

{
  int unaff_EBP;
  
  Mem_FreeObj(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@10020820 @ 10020820
======================================================================

void Unwind_10020820(void)

{
  int unaff_EBP;
  
  Mem_FreeObj(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@10020840 @ 10020840
======================================================================

void Unwind_10020840(void)

{
  int unaff_EBP;
  
  Mem_FreeObj(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@1002084b @ 1002084b
======================================================================

void Unwind_1002084b(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000fa60((void *)(*(int *)(unaff_EBP + 4) + 0xc));
  return;
}




======================================================================
// Function: Unwind@10020860 @ 10020860
======================================================================

void Unwind_10020860(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000fa60((void *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}




======================================================================
// Function: Unwind@10020880 @ 10020880
======================================================================

void Unwind_10020880(void)

{
  int unaff_EBP;
  
  Destructor_VisObject(*(void **)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@100208a0 @ 100208a0
======================================================================

void Unwind_100208a0(void)

{
  int unaff_EBP;
  
  FUN_10011eb0((int *)(unaff_EBP + -0x1c));
  return;
}




======================================================================
// Function: Unwind@100208a8 @ 100208a8
======================================================================

void Unwind_100208a8(void)

{
  int unaff_EBP;
  
  StringBuffer_Append((undefined4 *)(unaff_EBP + -0x1c));
  return;
}




======================================================================
// Function: Unwind@100208b0 @ 100208b0
======================================================================

void Unwind_100208b0(void)

{
  int unaff_EBP;
  
  StringBuffer_Append((undefined4 *)(unaff_EBP + -0x1c));
  return;
}




======================================================================
// Function: Unwind@100208d0 @ 100208d0
======================================================================

void Unwind_100208d0(void)

{
  int unaff_EBP;
  
  StringBuffer_Append(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@100208f0 @ 100208f0
======================================================================

void Unwind_100208f0(void)

{
  int unaff_EBP;
  
  FUN_100127f0(unaff_EBP + -0x20);
  return;
}




======================================================================
// Function: Unwind@10020910 @ 10020910
======================================================================

void Unwind_10020910(void)

{
  int unaff_EBP;
  
  FUN_100132f0((undefined4 *)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@10020918 @ 10020918
======================================================================

void Unwind_10020918(void)

{
  int unaff_EBP;
  
  FUN_100132f0((undefined4 *)(unaff_EBP + -0x14));
  return;
}




======================================================================
// Function: Unwind@10020920 @ 10020920
======================================================================

void Unwind_10020920(void)

{
  int unaff_EBP;
  
  FUN_100132f0((undefined4 *)(unaff_EBP + -0x18));
  return;
}




======================================================================
// Function: Unwind@10020928 @ 10020928
======================================================================

void Unwind_10020928(void)

{
  int unaff_EBP;
  
  FUN_100132f0((undefined4 *)(unaff_EBP + -0x14));
  return;
}




======================================================================
// Function: Unwind@10020940 @ 10020940
======================================================================

void Unwind_10020940(void)

{
  int unaff_EBP;
  
  FUN_100132f0((undefined4 *)(unaff_EBP + -0x124));
  return;
}




======================================================================
// Function: Unwind@10020960 @ 10020960
======================================================================

void Unwind_10020960(void)

{
  int unaff_EBP;
  
  FUN_10014530((int *)(unaff_EBP + -0x20));
  return;
}




======================================================================
// Function: Unwind@10020980 @ 10020980
======================================================================

void Unwind_10020980(void)

{
  int unaff_EBP;
  
  Release_PresetData((undefined4 *)(unaff_EBP + -0x14));
  return;
}




======================================================================
// Function: Unwind@10020988 @ 10020988
======================================================================

void Unwind_10020988(void)

{
  int unaff_EBP;
  
  FUN_10014530((int *)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@100209a0 @ 100209a0
======================================================================

void Unwind_100209a0(void)

{
  int unaff_EBP;
  
  Release_PresetData((undefined4 *)(unaff_EBP + -0x10));
  return;
}




======================================================================
// Function: Unwind@100209a8 @ 100209a8
======================================================================

void Unwind_100209a8(void)

{
  int unaff_EBP;
  
  FUN_10014530((int *)(unaff_EBP + -0x14));
  return;
}




======================================================================
// Function: Unwind@100209c0 @ 100209c0
======================================================================

void Unwind_100209c0(void)

{
  int unaff_EBP;
  
  FUN_10014530((int *)(unaff_EBP + -0x28));
  return;
}




======================================================================
// Function: Unwind@100209c8 @ 100209c8
======================================================================

void Unwind_100209c8(void)

{
  int unaff_EBP;
  
  FUN_10014530((int *)(unaff_EBP + -0x14));
  return;
}




======================================================================
// Function: Unwind@100209d0 @ 100209d0
======================================================================

void Unwind_100209d0(void)

{
  int unaff_EBP;
  
  FUN_10014530((int *)(unaff_EBP + -0x20));
  return;
}




======================================================================
// Function: Unwind@100209d8 @ 100209d8
======================================================================

void Unwind_100209d8(void)

{
  int unaff_EBP;
  
  Mem_FreeObj(*(LPVOID *)(unaff_EBP + 4));
  return;
}




======================================================================
// Function: Unwind@100209e3 @ 100209e3
======================================================================

void Unwind_100209e3(void)

{
  int unaff_EBP;
  
  Release_PresetData((undefined4 *)(unaff_EBP + 4));
  return;
}





=== TOTAL: 395 functions ===
