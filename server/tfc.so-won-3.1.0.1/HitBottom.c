// HitBottom__12CFuncPlatRot  @ 000c3084
void HitBottom__12CFuncPlatRot(int *param_1)

{
  int iVar1;
  
  HitBottom__9CFuncPlat(param_1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x123];
  *(int *)(iVar1 + 0x54) = param_1[0x124];
  *(int *)(iVar1 + 0x58) = param_1[0x125];
  return;
}


// HitBottom__16CFuncTrackChange  @ 000c6aec
void HitBottom__16CFuncTrackChange(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  HitBottom__12CFuncPlatRot(param_1);
  if (param_1[300] == 2) {
    piVar1 = (int *)param_1[0x128];
    iVar2 = *piVar1;
    local_c = *(undefined4 *)(iVar2 + 8);
    local_8 = *(undefined4 *)(iVar2 + 0xc);
    local_4 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x127],&local_c);
    piVar1[0xf6] = iVar2;
  }
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
  (**(code **)(param_1[0xf5] + 0x118))(param_1,param_1[0xfd]);
  param_1[0x12e] = 1;
  return;
}


// HitBottom__9CFuncPlat  @ 000c2b20
void HitBottom__9CFuncPlat(int *param_1)

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
  param_1[0xfd] = 1;
  return;
}


