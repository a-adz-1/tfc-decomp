// GetPrivateKey__11AuthRequest  @ 080911f0
undefined4 GetPrivateKey__11AuthRequest(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8044) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x8040);
  }
  return uVar1;
}


