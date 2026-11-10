// CheckGet__10CUtlBufferi  @ 000d8044
undefined4 CheckGet__10CUtlBufferi(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    iVar2 = NumAllocated__Ct10CUtlMemory1ZUc(param_1);
    if (iVar2 < *(int *)(param_1 + 0xc) + param_2) {
      *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 2;
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


