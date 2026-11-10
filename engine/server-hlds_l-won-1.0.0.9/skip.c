// skip__7istreami  @ 0809cb0c
uint skip__7istreami(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*param_1 + 0xc);
  if (param_2 == 0) {
    uVar2 = uVar1 & 0xfffffffe;
  }
  else {
    uVar2 = uVar1 | 1;
  }
  *(uint *)(*param_1 + 0xc) = uVar2;
  return uVar1 & 1;
}


// skip_ws__FP9streambuf  @ 0809ab9c
int skip_ws__FP9streambuf(_IO_FILE *param_1)

{
  int iVar1;
  
  do {
    iVar1 = _IO_getc(param_1);
    if (iVar1 == -1) {
      return -1;
    }
  } while ((*(byte *)(__ctype_b + 1 + iVar1 * 2) & 0x20) != 0);
  return iVar1;
}


