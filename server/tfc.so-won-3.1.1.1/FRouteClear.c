// FRouteClear__12CBaseMonster  @ 000c2b04
undefined4 FRouteClear__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(*(int *)(param_1 + 0x60c) * 0x10 + 0x594 + param_1) == 0) ||
     (*(int *)(param_1 + 0x608) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


