// gets__7istreamPPcc  @ 00053244
int * gets__7istreamPPcc(int *param_1,int *param_2,char param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int local_18;
  undefined1 local_14 [16];
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    iVar4 = ((int *)*param_1)[1];
    if ((iVar4 != 0) && (iVar3 = *(int *)*param_1, *(int *)(iVar3 + 8) == *(int *)(iVar3 + 4))) {
      flush__7ostream(iVar4);
    }
    _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
    local_18 = 0;
    pbVar2 = *(byte **)*param_1;
    iVar3 = _sb_readline__FP9streambufRlc(pbVar2,&local_18,(int)param_3);
    *param_2 = iVar3;
    iVar4 = 0;
    if (iVar3 != 0) {
      iVar4 = local_18;
    }
    param_1[1] = iVar4;
    if (((*pbVar2 & 0x10) != 0) &&
       (*(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 1, param_1[1] == 0)) {
      *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 2;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    _pthread_cleanup_pop_restore(local_14,0);
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    param_1[1] = 0;
    *param_2 = 0;
  }
  return param_1;
}


