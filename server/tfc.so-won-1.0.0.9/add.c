// add_fdes  @ 00120aa4
void add_fdes(int *param_1,int *param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint local_c;
  uint local_8;
  
  local_c = *param_3;
  local_8 = *param_4;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    if ((param_1[1] != 0) && (param_1[2] != 0)) {
      *(int **)(*param_2 + param_2[1] * 4) = param_1;
      param_2[1] = param_2[1] + 1;
      uVar2 = param_1[2];
      if (uVar2 < local_c) {
        local_c = uVar2;
      }
      if (local_8 < uVar2 + param_1[3]) {
        local_8 = uVar2 + param_1[3];
      }
    }
    iVar1 = *(int *)((int)param_1 + *param_1 + 4);
    param_1 = (int *)((int)param_1 + *param_1 + 4);
  }
  *param_3 = local_c;
  *param_4 = local_8;
  return;
}


