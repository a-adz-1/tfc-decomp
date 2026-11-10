// Spray__11CBloodSplat  @ 000db728
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spray__11CBloodSplat(int *param_1)

{
  int iVar1;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [56];
  
  if (g_Language != 1) {
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    iVar1 = *param_1;
    local_44 = *(float *)(iVar1 + 8) + gpGlobals[10] * _FUN_0014b788;
    local_40 = *(float *)(iVar1 + 0xc) + gpGlobals[0xb] * _FUN_0014b788;
    local_3c = *(float *)(iVar1 + 0x10) + _FUN_0014b788 * gpGlobals[0xc];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar1 + 8,&local_44,1,*(undefined4 *)(iVar1 + 0x198),local_38);
    UTIL_BloodDecalTrace__FP11TraceResulti(local_38,0xf7);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


