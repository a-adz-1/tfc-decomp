// HitBottom__12CFuncPlatRot  @ 000cdd00
void HitBottom__12CFuncPlatRot(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),6,*(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
    iVar1 = *param_1;
  }
  if (*(int *)(iVar1 + 0x1ec) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),1,*(int *)(iVar1 + 0x1ec) + *(int *)(gpGlobals + 0x98)
               ,param_1[0x13f],0x3f4ccccd,0,100);
  }
  param_1[0x11d] = 1;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x143];
  *(int *)(iVar1 + 0x54) = param_1[0x144];
  *(int *)(iVar1 + 0x58) = param_1[0x145];
  return;
}


// HitBottom__16CFuncTrackChange  @ 000d1b8c
void HitBottom__16CFuncTrackChange(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  HitBottom__12CFuncPlatRot(param_1);
  if (param_1[0x14c] == 2) {
    piVar1 = (int *)param_1[0x148];
    iVar2 = *piVar1;
    uStack_10 = *(undefined4 *)(iVar2 + 8);
    uStack_c = *(undefined4 *)(iVar2 + 0xc);
    uStack_8 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x147],&uStack_10);
    piVar1[0x116] = iVar2;
  }
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
  (**(code **)(param_1[0x115] + 0x120))(param_1,param_1[0x11d]);
  param_1[0x14e] = 1;
  return;
}


// HitBottom__9CFuncPlat  @ 000d2b1c
void HitBottom__9CFuncPlat(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),6,*(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
    iVar1 = *param_1;
  }
  if (*(int *)(iVar1 + 0x1ec) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),1,*(int *)(iVar1 + 0x1ec) + *(int *)(gpGlobals + 0x98)
               ,param_1[0x13f],0x3f4ccccd,0,100);
  }
  param_1[0x11d] = 1;
  return;
}


