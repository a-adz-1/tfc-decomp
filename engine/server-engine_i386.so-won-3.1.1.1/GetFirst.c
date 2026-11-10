// GetFirst__10ObjectList  @ 000cacac
undefined4 GetFirst__10ObjectList(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 4) + 4);
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 4) + 8);
  }
  return uVar1;
}


