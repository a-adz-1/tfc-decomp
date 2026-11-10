// RemoveHead__10ObjectList  @ 000ca92c
undefined4 RemoveHead__10ObjectList(int param_1)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 4) == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(*(int *)(param_1 + 4) + 8);
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
    }
    if (*(int *)(param_1 + 8) == *(int *)(param_1 + 4)) {
      *(undefined4 *)(param_1 + 8) = 0;
    }
    Mem_Free(*(undefined4 *)(param_1 + 4));
    *(undefined4 **)(param_1 + 4) = puVar1;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  }
  return local_8;
}


