// GetModuleHandle__FPCc  @ 000d7910
void GetModuleHandle__FPCc(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_000d7968();
    return;
  }
  iVar1 = dlopen(param_1,2);
  if (iVar1 == 0) {
    FUN_000d7968();
    return;
  }
  dlclose(iVar1);
  FUN_000d7968();
  return;
}


// GetModuleHandle__FPc  @ 0007fbec
int GetModuleHandle__FPc(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = dlopen(param_1,2);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      dlclose(iVar1);
    }
  }
  return iVar1;
}


