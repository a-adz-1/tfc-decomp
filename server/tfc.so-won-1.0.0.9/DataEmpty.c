// DataEmpty__5CSavePCci  @ 001198e0
undefined4 DataEmpty__5CSavePCci(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_3) {
    do {
      if (*(char *)(iVar1 + param_2) != '\0') {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_3);
  }
  return 1;
}


