// DataEmpty__5CSavePCci  @ 0011de9c
undefined4 DataEmpty__5CSavePCci(undefined4 param_1,char *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (0 < (int)param_3) {
    uVar2 = param_3 & 3;
    if (uVar2 != 0) {
      if (1 < uVar2) {
        if (2 < uVar2) {
          if (*param_2 != '\0') {
            return 0;
          }
          iVar1 = 1;
        }
        if (param_2[iVar1] != '\0') {
          return 0;
        }
        iVar1 = iVar1 + 1;
      }
      if (param_2[iVar1] != '\0') {
        return 0;
      }
      iVar1 = iVar1 + 1;
      if ((int)param_3 <= iVar1) {
        return 1;
      }
    }
    do {
      if (param_2[iVar1] != '\0') {
        return 0;
      }
      if (param_2[iVar1 + 1] != '\0') {
        return 0;
      }
      if (param_2[iVar1 + 2] != '\0') {
        return 0;
      }
      if (param_2[iVar1 + 3] != '\0') {
        return 0;
      }
      iVar1 = iVar1 + 4;
    } while (iVar1 < (int)param_3);
  }
  return 1;
}


