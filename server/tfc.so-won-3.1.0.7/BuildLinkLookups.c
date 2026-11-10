// BuildLinkLookups__6CGraph  @ 000c98bc
void BuildLinkLookups__6CGraph(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = (*(int *)(param_1 + 0x1c) * 3) / 2 + 3;
  *(int *)(param_1 + 0x20c0) = iVar1;
  HashChoosePrimes__6CGraphi(param_1,iVar1);
  pvVar2 = calloc(2,*(size_t *)(param_1 + 0x20c0));
  *(void **)(param_1 + 0x20bc) = pvVar2;
  if (pvVar2 == (void *)0x0) {
    (*DAT_001c1114)(2,"Couldn\'t allocated Link Lookup Table.\n");
  }
  else {
    if (0 < *(int *)(param_1 + 0x20c0)) {
      iVar1 = 0;
      do {
        *(undefined2 *)(*(int *)(param_1 + 0x20bc) + iVar1 * 2) = 0xffff;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x20c0));
    }
    if (0 < *(int *)(param_1 + 0x1c)) {
      iVar4 = 0;
      iVar1 = 0;
      do {
        puVar3 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0x10));
        HashInsert__6CGraphiii(param_1,*puVar3,puVar3[1],iVar1);
        iVar4 = iVar4 + 0x18;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x1c));
    }
  }
  return;
}


