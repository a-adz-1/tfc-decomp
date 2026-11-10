// FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster  @ 000eb318
void FixScriptMonsterSchedule__12CCineMonsterP12CBaseMonster(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x578) != 8) {
    *(undefined4 *)(param_2 + 0x578) = 1;
  }
  ClearSchedule__12CBaseMonster(param_2);
  return;
}


// FixScriptMonsterSchedule__7CCineAIP12CBaseMonster  @ 000eb2b0
void FixScriptMonsterSchedule__7CCineAIP12CBaseMonster(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iStack_14;
  char *pcStack_10;
  
  piVar2 = (int *)&stack0xfffffff4;
  pcStack_10 = (char *)0xeb2ba;
  if (*(int *)(param_1 + 0x6ac) != 0) {
    if (*(int *)(param_1 + 0x6ac) == 1) {
      pcStack_10 = (char *)0x20;
      iStack_14 = param_2;
      uVar1 = (**(code **)(*(int *)(param_2 + 0x454) + 0x174))();
      ChangeSchedule__12CBaseMonsterP10Schedule_t(param_2,uVar1);
      return;
    }
    pcStack_10 = "FixScriptMonsterSchedule - no case!\n";
    piVar2 = &iStack_14;
    iStack_14 = 2;
    (*DAT_0019f794)();
  }
  *(int *)((int)piVar2 + -4) = param_2;
  *(undefined4 *)((int)piVar2 + -8) = 0xeb30d;
  ClearSchedule__12CBaseMonster();
  return;
}


