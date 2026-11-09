// FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster  @ 000e7b50
void FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x4ec) != 8) {
    *(undefined4 *)(param_2 + 0x4ec) = 1;
  }
  ClearSchedule__12CBaseMonster(param_2);
  return;
}


// FixScriptMonsterSchedule__7CCineAIP12CBaseMonster  @ 000e7b80
void FixScriptMonsterSchedule__7CCineAIP12CBaseMonster(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iStack_10;
  char *pcStack_c;
  
  piVar2 = (int *)&stack0xfffffff8;
  if (*(int *)(param_1 + 0x620) != 0) {
    if (*(int *)(param_1 + 0x620) == 1) {
      pcStack_c = (char *)0x20;
      iStack_10 = param_2;
      uVar1 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x16c))();
      ChangeSchedule__12CBaseMonsterP10Schedule_t(param_2,uVar1);
      return;
    }
    pcStack_c = "FixScriptMonsterSchedule - no case!\n";
    piVar2 = &iStack_10;
    iStack_10 = 2;
    (*DAT_001755b4)();
  }
  *(int *)((int)piVar2 + -4) = param_2;
  *(undefined4 *)((int)piVar2 + -8) = 0xe7bd4;
  ClearSchedule__12CBaseMonster();
  return;
}


