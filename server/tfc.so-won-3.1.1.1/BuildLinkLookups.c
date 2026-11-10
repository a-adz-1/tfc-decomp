// BuildLinkLookups__6CGraph  @ 000c8fb0
void BuildLinkLookups__6CGraph(int param_1)

{
  undefined4 *puVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  undefined2 local_c;
  undefined2 local_a;
  uint local_8;
  
  iVar5 = (*(int *)(param_1 + 0x1c) * 3) / 2 + 3;
  *(int *)(param_1 + 0x20c0) = iVar5;
  HashChoosePrimes__6CGraphi(param_1,iVar5);
  pvVar6 = calloc(2,*(size_t *)(param_1 + 0x20c0));
  *(void **)(param_1 + 0x20bc) = pvVar6;
  if (pvVar6 == (void *)0x0) {
    (*DAT_0019f794)(2,"Couldn\'t allocated Link Lookup Table.\n");
  }
  else {
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x20c0)) {
      do {
        *(undefined2 *)(*(int *)(param_1 + 0x20bc) + iVar5 * 2) = 0xffff;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0x20c0));
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      do {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x10) + iVar5 * 0x18);
        local_c = (undefined2)*puVar1;
        local_a = (undefined2)puVar1[1];
        (*DAT_0019f7f8)(&local_8);
        (*DAT_0019f7fc)(&local_8,&local_c,4);
        local_8 = (*DAT_0019f804)(local_8);
        uVar3 = *(uint *)(param_1 + 0x20c0);
        uVar7 = (local_8 >> 4) % uVar3;
        iVar4 = *(int *)(param_1 + 0x20bc);
        sVar2 = *(short *)(iVar4 + uVar7 * 2);
        while (sVar2 != -1) {
          uVar7 = uVar7 + *(int *)(param_1 + 0x207c + (local_8 & 0xf) * 4);
          if ((int)uVar3 <= (int)uVar7) {
            uVar7 = uVar7 - uVar3;
          }
          sVar2 = *(short *)(iVar4 + uVar7 * 2);
        }
        *(short *)(iVar4 + uVar7 * 2) = (short)iVar5;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0x1c));
    }
  }
  return;
}


