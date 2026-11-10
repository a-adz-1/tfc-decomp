// MonsterInitDead__12CBaseMonster  @ 000c1dcc
void MonsterInitDead__12CBaseMonster(int *param_1)

{
  InitBoneControllers__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x138) = 0;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  *(undefined4 *)(*param_1 + 0x170) = 2;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (**(code **)(param_1[0x111] + 300))(param_1);
  param_1[3] = -0x10000;
  param_1[4] = (int)CorpseFallThink__12CBaseMonster;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  return;
}


