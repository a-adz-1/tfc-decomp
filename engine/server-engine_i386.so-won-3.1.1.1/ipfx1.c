// ipfx1__7istream  @ 00052b64
undefined4 ipfx1__7istream(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    iVar2 = ((int *)*param_1)[1];
    if ((iVar2 != 0) && (iVar3 = *(int *)*param_1, *(int *)(iVar3 + 8) == *(int *)(iVar3 + 4))) {
      flush__7ostream(iVar2);
    }
    uVar4 = 1;
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    uVar4 = 0;
  }
  return uVar4;
}


