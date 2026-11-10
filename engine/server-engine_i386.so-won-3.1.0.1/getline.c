// getline__7istreamPScic  @ 00046450
void getline__7istreamPScic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  getline__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// getline__7istreamPUcic  @ 000464d0
void getline__7istreamPUcic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  getline__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// getline__7istreamPcic  @ 000469c0
int * getline__7istreamPcic(int *param_1,int param_2,int param_3,byte param_4)

{
  _IO_FILE *__fp;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint local_8;
  
  param_1[1] = 0;
  if (param_3 < 1) {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if (*(char *)(iVar1 + 0x12) == '\0') {
      _IO_flockfile(*(_IO_FILE **)*param_1);
      iVar1 = ((int *)*param_1)[1];
      if (iVar1 != 0) {
        piVar2 = (int *)0x0;
        if (param_1 != (int *)0x0) {
          piVar2 = (int *)*param_1;
        }
        if (*(int *)(*piVar2 + 8) == *(int *)(*piVar2 + 4)) {
          flush__7ostream(iVar1);
        }
      }
      puVar3 = (undefined4 *)0x0;
      if (param_1 != (int *)0x0) {
        puVar3 = (undefined4 *)*param_1;
      }
      __fp = (_IO_FILE *)*puVar3;
      iVar1 = _IO_getline_info(__fp,param_2,param_3 + -1,(int)(char)param_4,0xffffffff,&local_8);
      param_1[1] = iVar1;
      if (local_8 != 0xffffffff) {
        local_8 = _IO_getc(__fp);
      }
      if (local_8 == 0xffffffff) {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        bVar4 = 1;
        if (param_1[1] == 0) {
          bVar4 = 3;
        }
        *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | bVar4;
      }
      else if (local_8 != param_4) {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
        sungetc__9streambuf(__fp);
      }
    }
    else {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
      local_8 = 0xffffffff;
    }
    *(undefined1 *)(param_1[1] + param_2) = 0;
    if (local_8 == param_4) {
      param_1[1] = param_1[1] + 1;
    }
  }
  return param_1;
}


