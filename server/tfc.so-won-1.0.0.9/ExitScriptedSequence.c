// ExitScriptedSequence__12CBaseMonster  @ 000e7be0
undefined4 ExitScriptedSequence__12CBaseMonster(int *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 0x150) == 1) {
    param_1[0x13b] = 8;
    uVar1 = 0;
  }
  else {
    if (param_1[0x183] != 0) {
      CancelScript__12CCineMonster(param_1[0x183]);
    }
    uVar1 = 1;
  }
  return uVar1;
}


