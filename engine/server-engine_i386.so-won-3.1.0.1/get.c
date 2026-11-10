// get__7istream  @ 00046190
int get__7istream(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = 0;
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
    iVar1 = _IO_getc((_IO_FILE *)*piVar3);
    if (iVar1 == -1) {
      iVar4 = 0;
      if (param_1 != (int *)0x0) {
        iVar4 = *param_1;
      }
      *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) | 1;
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
    iVar1 = -1;
  }
  return iVar1;
}


// get__7istreamPScic  @ 00046480
void get__7istreamPScic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  get__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// get__7istreamPUcic  @ 00046520
void get__7istreamPUcic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  get__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// get__7istreamPcic  @ 00046b00
int * get__7istreamPcic(int *param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int local_8;
  
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
      iVar1 = _IO_getline_info(*puVar3,param_2,param_3 + -1,(int)param_4,0xffffffff,&local_8);
      param_1[1] = iVar1;
      if ((iVar1 == 0) && (local_8 == -1)) {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 3;
      }
    }
    else {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
    }
    *(undefined1 *)(param_1[1] + param_2) = 0;
  }
  return param_1;
}


// get__7istreamRSc  @ 000464b0
void get__7istreamRSc(undefined4 param_1,undefined4 param_2)

{
  get__7istreamRc(param_1,param_2);
  return;
}


// get__7istreamRUc  @ 00046500
void get__7istreamRUc(undefined4 param_1,undefined4 param_2)

{
  get__7istreamRc(param_1,param_2);
  return;
}


// get__7istreamRc  @ 00043b20
int * get__7istreamRc(int *param_1,undefined1 *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = 0;
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
    iVar1 = _IO_getc((_IO_FILE *)*piVar3);
    if (iVar1 != -1) {
      *param_2 = (char)iVar1;
      param_1[1] = 1;
      return param_1;
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 3;
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  param_1[1] = 0;
  return param_1;
}


// get_reg  @ 000a0550
undefined4 get_reg(int param_1,int *param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x5c + (int)param_2);
  if (cVar1 == '\x01') {
    uVar2 = *(undefined4 *)(param_2[param_1 + 4] + *param_2);
  }
  else {
    if ((cVar1 != '\x02') || (param_3 == 0)) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    uVar2 = get_reg(param_2[param_1 + 4],param_3,0);
  }
  return uVar2;
}


