// FRouteClear__12CBaseMonster  @ 000af500
undefined4 FRouteClear__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(*(int *)(param_1 + 0x58c) * 0x10 + 0x514 + param_1) == 0) ||
     (*(int *)(param_1 + 0x588) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


