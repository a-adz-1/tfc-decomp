// vscan__7istreamPCcPv  @ 00053420
int * vscan__7istreamPCcPv(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_14 [16];
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    if ((*(byte *)(*param_1 + 0xc) & 1) == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = _skip_ws__7istream(param_1);
    }
    if (iVar2 != 0) {
      _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
      vscan__9streambufPCcPvP3ios(*(undefined4 *)*param_1,param_2,param_3,(undefined4 *)*param_1);
      _IO_funlockfile(*(_IO_FILE **)*param_1);
      _pthread_cleanup_pop_restore(local_14,0);
    }
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
  }
  return param_1;
}


// vscan__9streambufPCcPvP3ios  @ 000534f0
void vscan__9streambufPCcPvP3ios(_IO_FILE *param_1,char *param_2,__gnuc_va_list param_3,int param_4)

{
  int local_8;
  
  local_8 = 0;
  _IO_vfscanf(param_1,param_2,param_3,&local_8);
  if (param_4 != 0) {
    *(byte *)(param_4 + 0x12) = *(byte *)(param_4 + 0x12) | (byte)local_8;
  }
  return;
}


