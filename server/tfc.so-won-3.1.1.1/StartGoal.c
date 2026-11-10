// StartGoal__7CTFGoal  @ 001121e8
void StartGoal__7CTFGoal(int *param_1)

{
  param_1[0x9f] = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)PlaceGoal__7CTFGoal;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  if (param_1[0x86] == 3) {
    RemoveGoal__FP11CBaseEntity(param_1);
  }
  return;
}


