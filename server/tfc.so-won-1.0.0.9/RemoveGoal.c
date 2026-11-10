// RemoveGoal__FP11CBaseEntity  @ 00109d70
void RemoveGoal__FP11CBaseEntity(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  param_1[0x86] = 3;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  return;
}


