// opfx__7ostream  @ 0809d4d8
undefined4 opfx__7ostream(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar3 = (undefined4 *)*param_1;
    if (puVar3[1] != 0) {
      flush__7ostream(puVar3[1]);
      puVar3 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar3);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


