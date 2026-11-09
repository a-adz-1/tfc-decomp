// BuildLinkLookups__6CGraph  @ 000ce5b0
void BuildLinkLookups__6CGraph(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = (*(int *)(param_1 + 0x1c) * 3) / 2 + 3;
  *(int *)(param_1 + 0x20c0) = iVar2;
  HashChoosePrimes__6CGraphi(param_1,iVar2);
  pvVar3 = calloc(2,*(size_t *)(param_1 + 0x20c0));
  *(void **)(param_1 + 0x20bc) = pvVar3;
  if (pvVar3 == (void *)0x0) {
    (*DAT_001755b4)(2,"Couldn\'t allocated Link Lookup Table.\n");
  }
  else {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x20c0)) {
      do {
        *(undefined2 *)(*(int *)(param_1 + 0x20bc) + iVar2 * 2) = 0xffff;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x20c0));
    }
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      do {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x10) + iVar2 * 0x18);
        HashInsert__6CGraphiii(param_1,*puVar1,puVar1[1],iVar2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x1c));
    }
  }
  return;
}


