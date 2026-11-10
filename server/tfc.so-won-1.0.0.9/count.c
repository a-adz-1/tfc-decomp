// count_fdes  @ 00120a74
int count_fdes(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    if ((param_1[1] != 0) && (param_1[2] != 0)) {
      iVar2 = iVar2 + 1;
    }
    iVar1 = *(int *)((int)param_1 + *param_1 + 4);
    param_1 = (int *)((int)param_1 + *param_1 + 4);
  }
  return iVar2;
}


