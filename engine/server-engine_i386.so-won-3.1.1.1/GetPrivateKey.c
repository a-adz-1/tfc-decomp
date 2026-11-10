// GetPrivateKey__11AuthRequest  @ 000d1404
undefined4 GetPrivateKey__11AuthRequest(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8194) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x81ac);
  }
  return uVar1;
}


