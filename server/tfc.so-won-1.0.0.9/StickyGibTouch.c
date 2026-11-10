// StickyGibTouch__4CGibP11CBaseEntity  @ 000a5300
void StickyGibTouch__4CGibP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  float *pfVar1;
  int iVar2;
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
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 10.0;
  iVar2 = strcmp((char *)(*(int *)*param_2 + (int)pfVar1[0x26]),"worldspawn");
  if (iVar2 == 0) {
    iVar2 = *param_1;
    local_60 = *(float *)(iVar2 + 0x20) * 32.0;
    local_5c = *(float *)(iVar2 + 0x24) * 32.0;
    local_58 = *(float *)(iVar2 + 0x28) * 32.0;
    local_54 = *(float *)(iVar2 + 8) + local_60;
    local_50 = *(float *)(iVar2 + 0xc) + local_5c;
    local_4c = *(float *)(iVar2 + 0x10) + local_58;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar2 + 8,&local_54,1,*(undefined4 *)(iVar2 + 0x1e8),local_48);
    UTIL_BloodDecalTrace__FP11TraceResulti(local_48,param_1[0xf3]);
    iVar2 = *param_1;
    local_60 = local_24 * -1.0;
    local_5c = local_20 * -1.0;
    local_58 = local_1c * -1.0;
    *(float *)(iVar2 + 0x20) = local_60;
    *(float *)(iVar2 + 0x24) = local_5c;
    *(float *)(iVar2 + 0x28) = local_58;
    iVar2 = *param_1;
    UTIL_VecToAngles__FRC6Vector(&local_60,iVar2 + 0x20);
    *(float *)(iVar2 + 0x50) = local_60;
    *(float *)(iVar2 + 0x54) = local_5c;
    *(float *)(iVar2 + 0x58) = local_58;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x24) = DAT_00175484;
    *(undefined4 *)(iVar2 + 0x28) = DAT_00175488;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x60) = DAT_00175484;
    *(undefined4 *)(iVar2 + 100) = DAT_00175488;
    *(undefined4 *)(*param_1 + 0xe8) = 0;
  }
  else {
    *(float *)(*param_1 + 0xe4) = *gpGlobals;
  }
  return;
}


