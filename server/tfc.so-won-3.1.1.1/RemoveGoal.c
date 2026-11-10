// RemoveGoal__FP11CBaseEntity  @ 00111ee0
void RemoveGoal__FP11CBaseEntity(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  param_1[0x86] = 3;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  return;
}


