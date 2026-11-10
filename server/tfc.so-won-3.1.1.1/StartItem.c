// StartItem__11CTFGoalItem  @ 00112250
void StartItem__11CTFGoalItem(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)PlaceItem__11CTFGoalItem;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  if (param_1[0x86] == 3) {
    RemoveGoal__FP11CBaseEntity(param_1);
  }
  return;
}


