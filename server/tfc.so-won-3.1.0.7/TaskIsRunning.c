// TaskIsRunning__12CBaseMonster  @ 000bdcb4
undefined4 TaskIsRunning__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x56c) == 4) || (*(int *)(param_1 + 0x56c) == 2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


