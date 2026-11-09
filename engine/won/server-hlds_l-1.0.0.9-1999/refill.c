// refill__t24__default_alloc_template2b1i0Ui  @ 0809df50
int refill__t24__default_alloc_template2b1i0Ui(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_8;
  
  local_8 = 0x14;
  iVar1 = chunk_alloc__t24__default_alloc_template2b1i0UiRi(param_1,&local_8);
  if (local_8 != 1) {
    puVar2 = (undefined4 *)(param_1 + iVar1);
    *(undefined4 **)(&DAT_080ab95c + (param_1 + 7U >> 3) * 4) = puVar2;
    iVar4 = 1;
    puVar3 = puVar2;
    if (local_8 != 2) {
      do {
        puVar2 = (undefined4 *)(param_1 + (int)puVar3);
        *puVar3 = puVar2;
        iVar4 = iVar4 + 1;
        puVar3 = puVar2;
      } while (local_8 + -1 != iVar4);
    }
    *puVar2 = 0;
  }
  return iVar1;
}


