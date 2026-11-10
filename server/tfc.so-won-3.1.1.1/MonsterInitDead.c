// MonsterInitDead__12CBaseMonster  @ 000c0dcc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MonsterInitDead__12CBaseMonster(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  SetController__FPvP9entvars_sif(uVar1,*param_1,0,0);
  SetController__FPvP9entvars_sif(uVar1,*param_1,1,0);
  SetController__FPvP9entvars_sif(uVar1,*param_1,2,0);
  SetController__FPvP9entvars_sif(uVar1,*param_1,3,0);
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  GetSequenceInfo__FPvP9entvars_sPfT2(uVar1,*param_1,param_1 + 0x118,param_1 + 0x119);
  uVar2 = GetSequenceFlags__14CBaseAnimating(param_1);
  param_1[0x11c] = uVar2 & 1;
  *(float *)(*param_1 + 0x134) = *gpGlobals;
  *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  param_1[0x11b] = 0;
  param_1[0x11a] = (int)*gpGlobals;
  *(undefined4 *)(*param_1 + 0x138) = 0;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  *(undefined4 *)(*param_1 + 0x170) = 2;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (**(code **)(param_1[0x115] + 300))(param_1);
  param_1[3] = -0x10000;
  param_1[4] = (int)CorpseFallThink__12CBaseMonster;
  *(float *)(*param_1 + 0x104) = (float)_FUN_0014e180 + *gpGlobals;
  return;
}


