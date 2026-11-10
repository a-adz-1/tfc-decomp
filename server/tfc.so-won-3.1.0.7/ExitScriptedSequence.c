// ExitScriptedSequence__12CBaseMonster  @ 000e8c2c
undefined4 ExitScriptedSequence__12CBaseMonster(int *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 0x170) == 1) {
    param_1[0x15a] = 8;
    uVar1 = 0;
  }
  else {
    if (param_1[0x1a2] != 0) {
      CancelScript__12CCineMonster(param_1[0x1a2]);
    }
    uVar1 = 1;
  }
  return uVar1;
}


