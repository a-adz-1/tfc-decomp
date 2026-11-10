// AddTail__10ObjectListPv  @ 000ca9ac
undefined4 AddTail__10ObjectListPv(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)Mem_ZeroMalloc(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    puVar1[2] = param_2;
    if (*(int *)(param_1 + 8) != 0) {
      *puVar1 = *(undefined4 *)(param_1 + 8);
      *(undefined4 **)(*(int *)(param_1 + 8) + 4) = puVar1;
    }
    *(undefined4 **)(param_1 + 8) = puVar1;
    if (*(int *)(param_1 + 4) == 0) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 8);
    }
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    uVar2 = 1;
  }
  return uVar2;
}


