// getDestAddr__10EasySocket  @ 0009cb00
undefined4 getDestAddr__10EasySocket(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = isInvalid__10EasySocket(param_1);
  if ((iVar1 == 0) && (*(int *)(param_1 + 0x18) != 0)) {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


