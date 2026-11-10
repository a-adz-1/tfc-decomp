// CheckPut__10CUtlBufferi  @ 000d85fc
undefined4 CheckPut__10CUtlBufferi(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    while (iVar3 = NumAllocated__Ct10CUtlMemory1ZUc(param_1),
          iVar3 < *(int *)(param_1 + 0x10) + param_2) {
      cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZUc(param_1);
      if (cVar1 != '\0') {
        *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 1;
        return 0;
      }
      Grow__t10CUtlMemory1ZUci(param_1,0);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


