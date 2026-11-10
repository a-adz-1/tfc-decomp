// RemoveTail__10ObjectList  @ 000caa24
undefined4 RemoveTail__10ObjectList(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 8) == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(*(int *)(param_1 + 8) + 8);
    iVar1 = **(int **)(param_1 + 8);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = 0;
    }
    if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    Mem_Free(*(undefined4 *)(param_1 + 8));
    *(int *)(param_1 + 8) = iVar1;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  }
  return local_8;
}


