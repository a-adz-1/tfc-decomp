// getline__7istreamPScic  @ 000529f4
void getline__7istreamPScic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  getline__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// getline__7istreamPUcic  @ 00052990
void getline__7istreamPUcic(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  getline__7istreamPcic(param_1,param_2,param_3,(int)param_4);
  return;
}


// getline__7istreamPcic  @ 00052ec0
int * getline__7istreamPcic(int *param_1,int param_2,int param_3,byte param_4)

{
  undefined4 *puVar1;
  int iVar2;
  _IO_FILE *__fp;
  int iVar3;
  byte bVar4;
  uint local_18;
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
      __fp = *(_IO_FILE **)*param_1;
      iVar3 = _IO_getline_info(__fp,param_2,param_3 + -1,(int)(char)param_4,0xffffffff,&local_18);
      param_1[1] = iVar3;
      if (local_18 != 0xffffffff) {
        local_18 = _IO_getc(__fp);
      }
      if (local_18 == 0xffffffff) {
        bVar4 = 1;
        if (param_1[1] == 0) {
          bVar4 = 3;
        }
        *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | bVar4;
      }
      else if (local_18 != param_4) {
        *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 2;
        sungetc__9streambuf(__fp);
      }
      _IO_funlockfile(*(_IO_FILE **)*param_1);
      _pthread_cleanup_pop_restore(local_14,0);
    }
    else {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
      local_18 = 0xffffffff;
    }
    *(undefined1 *)(param_1[1] + param_2) = 0;
    if (local_18 == param_4) {
      param_1[1] = param_1[1] + 1;
    }
  }
  return param_1;
}


