// HitTop__12CFuncPlatRot  @ 000d1f40
void HitTop__12CFuncPlatRot(int *param_1)

{
  int iVar1;
  
  HitTop__9CFuncPlat(param_1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x11d];
  *(int *)(iVar1 + 0x54) = param_1[0x11e];
  *(int *)(iVar1 + 0x58) = param_1[0x11f];
  return;
}


// HitTop__16CFuncTrackChange  @ 000d5330
void HitTop__16CFuncTrackChange(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  HitTop__12CFuncPlatRot(param_1);
  if (param_1[0x129] == 2) {
    piVar1 = (int *)param_1[0x125];
    iVar2 = *piVar1;
    local_10 = *(undefined4 *)(iVar2 + 8);
    local_c = *(undefined4 *)(iVar2 + 0xc);
    local_8 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x123],&local_10);
    piVar1[0xf3] = iVar2;
  }
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined4 *)(*param_1 + 0xe4) = 0xbf800000;
  (**(code **)(param_1[0xf2] + 0x118))(param_1,param_1[0xfa]);
  param_1[299] = 1;
  return;
}


// HitTop__9CFuncPlat  @ 000d1b00
void HitTop__9CFuncPlat(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1c8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),6,*(int *)(iVar1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
  }
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1cc) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),1,*(int *)(iVar1 + 0x1cc) + *(int *)(gpGlobals + 0x98)
               ,param_1[0x11c],0x3f4ccccd,0,100);
  }
  param_1[0xfa] = 0;
  iVar1 = (**(code **)(param_1[0xf2] + 0x104))(param_1);
  if (iVar1 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CallGoDown__9CFuncPlat;
    *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 3.0;
  }
  return;
}


