// HitBottom__12CFuncPlatRot  @ 000ce3e4
void HitBottom__12CFuncPlatRot(int *param_1)

{
  int iVar1;
  
  HitBottom__9CFuncPlat(param_1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 100) = DAT_001c0fe8;
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x13f];
  *(int *)(iVar1 + 0x54) = param_1[0x140];
  *(int *)(iVar1 + 0x58) = param_1[0x141];
  return;
}


// HitBottom__16CFuncTrackChange  @ 000d1e4c
void HitBottom__16CFuncTrackChange(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  HitBottom__12CFuncPlatRot(param_1);
  if (param_1[0x148] == 2) {
    piVar1 = (int *)param_1[0x144];
    iVar2 = *piVar1;
    local_c = *(undefined4 *)(iVar2 + 8);
    local_8 = *(undefined4 *)(iVar2 + 0xc);
    local_4 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x143],&local_c);
    piVar1[0x112] = iVar2;
  }
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
  (**(code **)(param_1[0x111] + 0x120))(param_1,param_1[0x119]);
  param_1[0x14a] = 1;
  return;
}


// HitBottom__9CFuncPlat  @ 000cde80
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
               ,param_1[0x13b],0x3f4ccccd,0,100);
  }
  param_1[0x119] = 1;
  return;
}


