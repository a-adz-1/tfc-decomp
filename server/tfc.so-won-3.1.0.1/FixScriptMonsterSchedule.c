// FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster  @ 000dcae8
void FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x4f8) != 8) {
    *(undefined4 *)(param_2 + 0x4f8) = 1;
  }
  ClearSchedule__12CBaseMonster(param_2);
  return;
}


// FixScriptMonsterSchedule__7CCineAIP12CBaseMonster  @ 000dcb18
void FixScriptMonsterSchedule__7CCineAIP12CBaseMonster(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x62c) == 0) {
    ClearSchedule__12CBaseMonster(param_2);
  }
  else if (*(int *)(param_1 + 0x62c) == 1) {
    uVar1 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x16c))(param_2,0x20);
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_2,uVar1);
  }
  else {
    (*DAT_001a7f34)(2,"FixScriptMonsterSchedule - no case!\n");
    ClearSchedule__12CBaseMonster(param_2);
  }
  return;
}


