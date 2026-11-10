// ipfx0__7istream  @ 000462d0
undefined4 ipfx0__7istream(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
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
      uVar2 = 1;
    }
    else {
      uVar2 = _skip_ws__7istream(param_1);
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
    uVar2 = 0;
  }
  return uVar2;
}


