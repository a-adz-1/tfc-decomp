// MonsterInitDead__12CBaseMonster  @ 000c7d90
void MonsterInitDead__12CBaseMonster(int *param_1)

{
  InitBoneControllers__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 2;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_1 + 0x140);
  *(undefined4 *)(*param_1 + 0x150) = 2;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (**(code **)(param_1[0xf2] + 0x124))(param_1);
  param_1[3] = -0x10000;
  param_1[4] = (int)CorpseFallThink__12CBaseMonster;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
  return;
}


