// scan__7istreamPCce  @ 00046df0
int * scan__7istreamPCce(int *param_1,undefined4 param_2)

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
      vscan__9streambufPCcPvP3ios(*(undefined4 *)*param_1,param_2,&stack0x0000000c,puVar2);
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


// scan__9streambufPCce  @ 00046f70
void scan__9streambufPCce(_IO_FILE *param_1,char *param_2)

{
  _IO_vfscanf(param_1,param_2,&stack0x0000000c,(int *)0x0);
  return;
}


