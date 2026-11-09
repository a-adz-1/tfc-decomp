// ignore__7istreamii  @ 0809accc
int * ignore__7istreamii(int *param_1,int param_2,int param_3)

{
  _IO_FILE *__fp;
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = 0;
  param_1[1] = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    piVar3 = (int *)*param_1;
    if (piVar3[1] != 0) {
      piVar2 = (int *)0x0;
      if (param_1 != (int *)0x0) {
        piVar2 = piVar3;
      }
      if (*(int *)(*piVar2 + 8) == *(int *)(*piVar2 + 4)) {
        flush__7ostream(piVar3[1]);
        piVar3 = (int *)*param_1;
      }
    }
    __fp = (_IO_FILE *)*piVar3;
    if (param_3 == -1) {
      iVar1 = ignore__9streambufi(__fp,param_2);
      param_1[1] = iVar1;
    }
    else {
      param_2 = param_2 + -1;
      if (-1 < param_2) {
        while (iVar1 = _IO_getc(__fp), iVar1 != -1) {
          param_1[1] = param_1[1] + 1;
          if (iVar1 == param_3) {
            return param_1;
          }
          param_2 = param_2 + -1;
          if (param_2 < 0) {
            return param_1;
          }
        }
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 3;
      }
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  return param_1;
}


