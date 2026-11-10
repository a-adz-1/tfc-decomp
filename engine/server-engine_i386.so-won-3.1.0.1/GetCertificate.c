// GetCertificate__11AuthRequest  @ 00098ccc
undefined4 GetCertificate__11AuthRequest(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8194) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x819c);
  }
  return uVar1;
}


