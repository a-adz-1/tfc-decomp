// Spray__11CBloodSplat  @ 000dd5b0
void Spray__11CBloodSplat(int *param_1)

{
  int iVar1;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [56];
  
  if (g_Language != 1) {
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    iVar1 = *param_1;
    fStack_48 = *(float *)(iVar1 + 8) + gpGlobals[10] * 128.0;
    fStack_44 = *(float *)(iVar1 + 0xc) + gpGlobals[0xb] * 128.0;
    fStack_40 = *(float *)(iVar1 + 0x10) + gpGlobals[0xc] * 128.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar1 + 8,&fStack_48,1,*(undefined4 *)(iVar1 + 0x178),auStack_3c);
    UTIL_BloodDecalTrace__FP11TraceResulti(auStack_3c,0xf7);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


