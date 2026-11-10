// getNewDescriptor__10EasySocket  @ 000d5e24
undefined4 getNewDescriptor__10EasySocket(int *param_1)

{
  int iVar1;
  
  iVar1 = isInvalid__10EasySocket(param_1);
  if (iVar1 == 0) {
    close__10EasySocket(param_1);
  }
  iVar1 = param_1[1];
  if (iVar1 == 1) {
    iVar1 = socket(2,1,6);
    *param_1 = iVar1;
  }
  else if (iVar1 < 2) {
    if (iVar1 == 0) {
      return 0x3e9;
    }
  }
  else if (iVar1 == 2) {
    iVar1 = socket(2,2,0x11);
    *param_1 = iVar1;
  }
  return 0;
}


