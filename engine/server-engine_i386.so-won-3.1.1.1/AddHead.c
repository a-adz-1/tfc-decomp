// AddHead__10ObjectListPv  @ 000ca8b4
undefined4 AddHead__10ObjectListPv(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_ZeroMalloc(0xc);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 8) = param_2;
    if (*(int *)(param_1 + 4) != 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 4);
      **(int **)(param_1 + 4) = iVar1;
    }
    *(int *)(param_1 + 4) = iVar1;
    if (*(int *)(param_1 + 8) == 0) {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    }
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    uVar2 = 1;
  }
  return uVar2;
}


