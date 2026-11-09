// vscan__7istreamPCcPv  @ 0809da64
int * vscan__7istreamPCcPv(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = _skip_ws__7istream(param_1);
    }
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)0x0;
      if (param_1 != (int *)0x0) {
        puVar2 = (undefined4 *)*param_1;
      }
      vscan__9streambufPCcPvP3ios(*(undefined4 *)*param_1,param_2,param_3,puVar2);
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


// vscan__9streambufPCcPvP3ios  @ 0809daf0
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


