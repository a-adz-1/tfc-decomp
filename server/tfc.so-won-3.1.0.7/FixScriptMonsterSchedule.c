// FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster  @ 000e8b84
void FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x568) != 8) {
    *(undefined4 *)(param_2 + 0x568) = 1;
  }
  ClearSchedule__12CBaseMonster(param_2);
  return;
}


// FixScriptMonsterSchedule__7CCineAIP12CBaseMonster  @ 000e8bb4
void FixScriptMonsterSchedule__7CCineAIP12CBaseMonster(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x69c) == 0) {
    ClearSchedule__12CBaseMonster(param_2);
  }
  else {
    if (*(int *)(param_1 + 0x69c) != 1) {
      FUN_000e8c08();
      return;
    }
    uVar1 = (**(code **)(*(int *)(param_2 + 0x444) + 0x174))(param_2,0x20);
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_2,uVar1);
  }
  return;
}


