// ipfx0__7istream  @ 00052b00
undefined4 ipfx0__7istream(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    if ((*(byte *)(*param_1 + 0xc) & 1) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = _skip_ws__7istream(param_1);
    }
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    uVar2 = 0;
  }
  return uVar2;
}


