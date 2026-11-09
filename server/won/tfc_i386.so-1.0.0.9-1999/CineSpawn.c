// CineSpawn__18CLegacyCineMonsterPc  @ 000bb070
void CineSpawn__18CLegacyCineMonsterPc(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (*g_engfuncs)(param_2);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),param_2);
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x42800000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0xe8) = 4;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x140) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x90) = 0x41200000;
  *(undefined4 *)(*param_1 + 0x108) = *(undefined4 *)(*param_1 + 0x164);
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x118) = 0;
  param_1[0x178] = 0xf7;
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1ac) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__18CLegacyCineMonster;
    *(float *)(iVar1 + 0xe4) = *(float *)(iVar1 + 0xe4) + 1.0;
  }
  return;
}


