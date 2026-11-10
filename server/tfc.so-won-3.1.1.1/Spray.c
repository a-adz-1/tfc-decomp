// Spray__11CBloodSplat  @ 000da9d0
void Spray__11CBloodSplat(int *param_1)

{
  int iVar1;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [56];
  
  if (g_Language != 1) {
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    iVar1 = *param_1;
    local_48 = gpGlobals[10] * 128.0 + *(float *)(iVar1 + 8);
    local_44 = gpGlobals[0xb] * 128.0 + *(float *)(iVar1 + 0xc);
    local_40 = gpGlobals[0xc] * 128.0 + *(float *)(iVar1 + 0x10);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar1 + 8,&local_48,1,*(undefined4 *)(iVar1 + 0x198),local_3c);
    UTIL_BloodDecalTrace__FP11TraceResulti(local_3c,0xf7);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


