// gets__7istreamPPcc  @ 0809d904
int * gets__7istreamPPcc(int *param_1,int *param_2,char param_3)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_8;
  
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
  }
  if (*(char *)(iVar2 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    iVar2 = ((int *)*param_1)[1];
    if (iVar2 != 0) {
      piVar3 = (int *)0x0;
      if (param_1 != (int *)0x0) {
        piVar3 = (int *)*param_1;
      }
      if (*(int *)(*piVar3 + 8) == *(int *)(*piVar3 + 4)) {
        flush__7ostream(iVar2);
      }
    }
    local_8 = 0;
    puVar4 = (undefined4 *)0x0;
    if (param_1 != (int *)0x0) {
      puVar4 = (undefined4 *)*param_1;
    }
    pbVar1 = (byte *)*puVar4;
    iVar5 = _sb_readline__FP9streambufRlc(pbVar1,&local_8,(int)param_3);
    *param_2 = iVar5;
    iVar2 = 0;
    if (iVar5 != 0) {
      iVar2 = local_8;
    }
    param_1[1] = iVar2;
    if ((*pbVar1 & 0x10) != 0) {
      iVar2 = 0;
      if (param_1 != (int *)0x0) {
        iVar2 = *param_1;
      }
      *(byte *)(iVar2 + 0x12) = *(byte *)(iVar2 + 0x12) | 1;
      if (param_1[1] == 0) {
        iVar2 = 0;
        if (param_1 != (int *)0x0) {
          iVar2 = *param_1;
        }
        *(byte *)(iVar2 + 0x12) = *(byte *)(iVar2 + 0x12) | 2;
      }
    }
  }
  else {
    iVar2 = 0;
    if (param_1 != (int *)0x0) {
      iVar2 = *param_1;
    }
    *(byte *)(iVar2 + 0x12) = *(byte *)(iVar2 + 0x12) | 2;
    param_1[1] = 0;
    *param_2 = 0;
  }
  return param_1;
}


