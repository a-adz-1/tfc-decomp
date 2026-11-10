// MergeData__15DBAreaClassDataP15DBAreaClassData  @ 00086fc8
void MergeData__15DBAreaClassDataP15DBAreaClassData(int *param_1,int *param_2)

{
  *param_1 = *param_1 + *param_2;
  param_1[1] = param_1[1] + param_2[1];
  param_1[2] = param_1[2] + param_2[2];
  Clear__15DBAreaClassData(param_2);
  return;
}


// MergeData__8CAreaDefP8CAreaDef  @ 00087298
void MergeData__8CAreaDefP8CAreaDef(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  param_1 = param_1 + 0x448;
  param_2 = param_2 + 0x448;
  do {
    MergeData__15DBAreaClassDataP15DBAreaClassData(param_1,param_2);
    MergeData__15DBAreaClassDataP15DBAreaClassData(param_1 + 0xc,param_2 + 0xc);
    MergeData__15DBAreaClassDataP15DBAreaClassData(param_1 + 0x18,param_2 + 0x18);
    MergeData__15DBAreaClassDataP15DBAreaClassData(param_1 + 0x24,param_2 + 0x24);
    MergeData__15DBAreaClassDataP15DBAreaClassData(param_1 + 0x30,param_2 + 0x30);
    MergeData__15DBAreaClassDataP15DBAreaClassData(param_1 + 0x3c,param_2 + 0x3c);
    param_1 = param_1 + 0x48;
    param_2 = param_2 + 0x48;
    iVar1 = iVar1 + 6;
  } while (iVar1 < 0xc);
  return;
}


