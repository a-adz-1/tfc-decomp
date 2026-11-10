// StickyGibTouch__4CGibP11CBaseEntity  @ 0009611c
void StickyGibTouch__4CGibP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined1 local_48 [36];
  float local_24;
  float local_20;
  float local_1c;
  
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 10.0;
  iVar1 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"worldspawn");
  if (iVar1 == 0) {
    iVar1 = *param_1;
    local_60 = *(float *)(iVar1 + 0x20) * 32.0;
    local_5c = *(float *)(iVar1 + 0x24) * 32.0;
    local_58 = *(float *)(iVar1 + 0x28) * 32.0;
    local_54 = local_60 + *(float *)(iVar1 + 8);
    local_50 = local_5c + *(float *)(iVar1 + 0xc);
    local_4c = local_58 + *(float *)(iVar1 + 0x10);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar1 + 8,&local_54,1,*(undefined4 *)(iVar1 + 0x208),local_48);
    UTIL_BloodDecalTrace__FP11TraceResulti(local_48,param_1[0x116]);
    local_60 = -local_24;
    local_5c = -local_20;
    local_58 = -local_1c;
    iVar1 = *param_1;
    *(float *)(iVar1 + 0x20) = local_60;
    *(float *)(iVar1 + 0x24) = local_5c;
    *(float *)(iVar1 + 0x28) = local_58;
    iVar1 = *param_1;
    UTIL_VecToAngles__FRC6Vector(&local_60,iVar1 + 0x20);
    *(float *)(iVar1 + 0x50) = local_60;
    *(float *)(iVar1 + 0x54) = local_5c;
    *(float *)(iVar1 + 0x58) = local_58;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar1 + 0x28) = DAT_0019f668;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
    *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
    *(undefined4 *)(*param_1 + 0x108) = 0;
  }
  else {
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


