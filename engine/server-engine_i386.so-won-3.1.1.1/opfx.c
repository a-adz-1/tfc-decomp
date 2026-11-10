// opfx__7ostream  @ 0005266c
undefined4 opfx__7ostream(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(*param_1 + 0x12) == '\0') {
    iVar1 = *(int *)(*param_1 + 4);
    if (iVar1 != 0) {
      flush__7ostream(iVar1);
    }
    _IO_flockfile(*(_IO_FILE **)*param_1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


