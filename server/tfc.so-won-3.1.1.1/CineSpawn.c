// CineSpawn__18CLegacyCineMonsterPc  @ 000b3098
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
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),param_2);
  local_10 = 0x41800000;
  local_8 = 0x42800000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x160) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0xb0) = 0x41200000;
  *(undefined4 *)(*param_1 + 0x128) = *(undefined4 *)(*param_1 + 0x184);
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x138) = 0;
  iVar1 = *param_1;
  param_1[0x19b] = 0xf7;
  if (*(int *)(iVar1 + 0x1cc) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__18CLegacyCineMonster;
    *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x104) + 1.0;
  }
  return;
}


