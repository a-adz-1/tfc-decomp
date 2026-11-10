// FRouteClear__12CBaseMonster  @ 000ba760
undefined4 FRouteClear__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(*(int *)(param_1 + 0x5fc) * 0x10 + 0x584 + param_1) == 0) ||
     (*(int *)(param_1 + 0x5f8) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


