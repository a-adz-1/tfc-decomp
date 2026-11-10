// get__7istream  @ 00052bd4
int get__7istream(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    iVar3 = ((int *)*param_1)[1];
    if ((iVar3 != 0) && (iVar2 = *(int *)*param_1, *(int *)(iVar2 + 8) == *(int *)(iVar2 + 4))) {
      flush__7ostream(iVar3);
    }
    iVar3 = _IO_getc(*(_IO_FILE **)*param_1);
    if (iVar3 == -1) {
      *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 1;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    iVar3 = -1;
  }
  return iVar3;
}


// get__7istreamPScic  @ 000529d0
void get__7istreamPScic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  get__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// get__7istreamPUcic  @ 00052950
void get__7istreamPUcic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  get__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// get__7istreamPcic  @ 00053020
int * get__7istreamPcic(int *param_1,int param_2,int param_3,char param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_18;
  undefined1 local_14 [16];
  
  param_1[1] = 0;
  if (param_3 < 1) {
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 2;
  }
  else {
    puVar1 = (undefined4 *)*param_1;
    if (*(byte *)((int)puVar1 + 0x12) == 0) {
      _IO_flockfile((_IO_FILE *)*puVar1);
      iVar3 = ((int *)*param_1)[1];
      if ((iVar3 != 0) && (iVar2 = *(int *)*param_1, *(int *)(iVar2 + 8) == *(int *)(iVar2 + 4))) {
        flush__7ostream(iVar3);
      }
      _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
      iVar3 = _IO_getline_info(*(undefined4 *)*param_1,param_2,param_3 + -1,(int)param_4,0xffffffff,
                               &local_18);
      param_1[1] = iVar3;
      if ((iVar3 == 0) && (local_18 == -1)) {
        *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 3;
      }
      _IO_funlockfile(*(_IO_FILE **)*param_1);
      _pthread_cleanup_pop_restore(local_14,0);
    }
    else {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    }
    *(undefined1 *)(param_1[1] + param_2) = 0;
  }
  return param_1;
}


// get__7istreamRSc  @ 000529b4
void get__7istreamRSc(undefined4 param_1,undefined4 param_2)

{
  get__7istreamRc(param_1,param_2);
  return;
}


// get__7istreamRUc  @ 00052974
void get__7istreamRUc(undefined4 param_1,undefined4 param_2)

{
  get__7istreamRc(param_1,param_2);
  return;
}


// get__7istreamRc  @ 000504f8
int * get__7istreamRc(int *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 local_14 [16];
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    iVar3 = ((int *)*param_1)[1];
    if ((iVar3 != 0) && (iVar2 = *(int *)*param_1, *(int *)(iVar2 + 8) == *(int *)(iVar2 + 4))) {
      flush__7ostream(iVar3);
    }
    _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
    iVar3 = _IO_getc(*(_IO_FILE **)*param_1);
    if (iVar3 == -1) {
      *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 3;
      param_1[1] = 0;
    }
    else {
      *param_2 = (char)iVar3;
      param_1[1] = 1;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    _pthread_cleanup_pop_restore(local_14,0);
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    param_1[1] = 0;
  }
  return param_1;
}


