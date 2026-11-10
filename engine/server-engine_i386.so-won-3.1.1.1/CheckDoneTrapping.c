// CheckDoneTrapping__7CEngineRiT1  @ 00099eb0
undefined4 CheckDoneTrapping__7CEngineRiT1(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x28) == '\0') {
    if (*(char *)(param_1 + 0x29) == '\0') {
      uVar1 = 0;
    }
    else {
      *param_3 = *(undefined4 *)(param_1 + 0x2c);
      *param_2 = *(undefined4 *)(param_1 + 0x30);
      *(undefined1 *)(param_1 + 0x29) = 0;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


