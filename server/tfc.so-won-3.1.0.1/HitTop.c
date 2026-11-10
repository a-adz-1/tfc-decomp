// HitTop__12CFuncPlatRot  @ 000c3118
void HitTop__12CFuncPlatRot(int *param_1)

{
  int iVar1;
  
  HitTop__9CFuncPlat(param_1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x120];
  *(int *)(iVar1 + 0x54) = param_1[0x121];
  *(int *)(iVar1 + 0x58) = param_1[0x122];
  return;
}


// HitTop__16CFuncTrackChange  @ 000c6b94
void HitTop__16CFuncTrackChange(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  HitTop__12CFuncPlatRot(param_1);
  if (param_1[300] == 2) {
    piVar1 = (int *)param_1[0x128];
    iVar2 = *piVar1;
    local_c = *(undefined4 *)(iVar2 + 8);
    local_8 = *(undefined4 *)(iVar2 + 0xc);
    local_4 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x126],&local_c);
    piVar1[0xf6] = iVar2;
  }
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
  (**(code **)(param_1[0xf5] + 0x118))(param_1,param_1[0xfd]);
  param_1[0x12e] = 1;
  return;
}


// HitTop__9CFuncPlat  @ 000c2c84
void HitTop__9CFuncPlat(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),6,*(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
  }
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1ec) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),1,*(int *)(iVar1 + 0x1ec) + *(int *)(gpGlobals + 0x98)
               ,param_1[0x11f],0x3f4ccccd,0,100);
  }
  param_1[0xfd] = 0;
  iVar1 = (**(code **)(param_1[0xf5] + 0x104))(param_1);
  if (iVar1 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CallGoDown__9CFuncPlat;
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 3.0;
  }
  return;
}


