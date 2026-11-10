// ignore__7istreamii  @ 00050630
int * ignore__7istreamii(int *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  _IO_FILE *__fp;
  int iVar3;
  undefined1 local_14 [16];
  
  puVar1 = (undefined4 *)*param_1;
  param_1[1] = 0;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    iVar3 = ((int *)*param_1)[1];
    if ((iVar3 != 0) && (iVar2 = *(int *)*param_1, *(int *)(iVar2 + 8) == *(int *)(iVar2 + 4))) {
      flush__7ostream(iVar3);
    }
    _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
    __fp = *(_IO_FILE **)*param_1;
    if (param_3 == -1) {
      iVar3 = ignore__9streambufi(__fp,param_2);
      param_1[1] = iVar3;
    }
    else {
      do {
        param_2 = param_2 + -1;
        if (param_2 < 0) break;
        iVar3 = _IO_getc(__fp);
        if (iVar3 == -1) {
          *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 3;
          break;
        }
        param_1[1] = param_1[1] + 1;
      } while (iVar3 != param_3);
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    _pthread_cleanup_pop_restore(local_14,0);
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
  }
  return param_1;
}


