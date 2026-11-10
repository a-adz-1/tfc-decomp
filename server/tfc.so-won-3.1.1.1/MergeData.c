// MergeData__15DBAreaClassDataP15DBAreaClassData  @ 00086ff8
void MergeData__15DBAreaClassDataP15DBAreaClassData(int *param_1,int *param_2)

{
  *param_1 = *param_1 + *param_2;
  param_1[1] = param_1[1] + param_2[1];
  param_1[2] = param_1[2] + param_2[2];
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  return;
}


// MergeData__8CAreaDefP8CAreaDef  @ 00086d8c
void MergeData__8CAreaDefP8CAreaDef(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    piVar1 = (int *)(param_1 + 0x458 + iVar3 * 0xc);
    piVar2 = (int *)(param_2 + 0x458 + iVar3 * 0xc);
    iVar3 = iVar3 + 1;
    *piVar1 = *piVar1 + *piVar2;
    piVar1[1] = piVar1[1] + piVar2[1];
    piVar1[2] = piVar1[2] + piVar2[2];
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 0;
  } while (iVar3 < 0xc);
  return;
}


