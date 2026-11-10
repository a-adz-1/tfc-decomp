// StickyGibTouch__4CGibP11CBaseEntity  @ 00096808
void StickyGibTouch__4CGibP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 unaff_EBP;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined1 local_44 [36];
  float local_20;
  float local_1c;
  float local_18;
  
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 10.0;
  iVar1 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"worldspawn");
  if (iVar1 == 0) {
    iVar1 = *param_1;
    local_5c = *(float *)(iVar1 + 0x20) * 32.0;
    local_58 = *(float *)(iVar1 + 0x24) * 32.0;
    local_54 = *(float *)(iVar1 + 0x28) * 32.0;
    local_50 = *(float *)(iVar1 + 8) + local_5c;
    local_4c = *(float *)(iVar1 + 0xc) + local_58;
    local_48 = *(float *)(iVar1 + 0x10) + local_54;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar1 + 8,&local_50,1,*(undefined4 *)(iVar1 + 0x208),local_44);
    UTIL_BloodDecalTrace__FP11TraceResulti(local_44,param_1[0x112]);
    iVar1 = *param_1;
    local_5c = local_20 * -1.0;
    local_58 = local_1c * -1.0;
    local_54 = local_18 * -1.0;
    *(float *)(iVar1 + 0x20) = local_5c;
    *(float *)(iVar1 + 0x24) = local_58;
    *(float *)(iVar1 + 0x28) = local_54;
    iVar1 = *param_1;
    UTIL_VecToAngles__FRC6Vector(&local_5c,iVar1 + 0x20);
    *(undefined4 *)(iVar1 + 0x50) = unaff_EBP;
    *(float *)(iVar1 + 0x54) = local_5c;
    *(float *)(iVar1 + 0x58) = local_58;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_001c0fe4;
    *(undefined4 *)(iVar1 + 0x28) = DAT_001c0fe8;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x60) = DAT_001c0fe4;
    *(undefined4 *)(iVar1 + 100) = DAT_001c0fe8;
    *(undefined4 *)(*param_1 + 0x108) = 0;
  }
  else {
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


