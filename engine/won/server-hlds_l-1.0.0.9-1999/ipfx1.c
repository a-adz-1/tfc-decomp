// ipfx1__7istream  @ 0809cfc0
undefined4 ipfx1__7istream(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    iVar1 = ((int *)*param_1)[1];
    if (iVar1 != 0) {
      piVar3 = (int *)0x0;
      if (param_1 != (int *)0x0) {
        piVar3 = (int *)*param_1;
      }
      if (*(int *)(*piVar3 + 8) == *(int *)(*piVar3 + 4)) {
        flush__7ostream(iVar1);
      }
    }
    uVar2 = 1;
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


