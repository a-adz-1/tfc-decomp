// ipfx__7istreami  @ 00046350
undefined4 ipfx__7istreami(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
  }
  if (*(char *)(iVar2 + 0x12) != '\0') {
    iVar2 = 0;
    if (param_1 != (int *)0x0) {
      iVar2 = *param_1;
    }
    *(byte *)(iVar2 + 0x12) = *(byte *)(iVar2 + 0x12) | 2;
    return 0;
  }
  _IO_flockfile(*(_IO_FILE **)*param_1);
  piVar1 = (int *)*param_1;
  if (piVar1[1] != 0) {
    if (param_2 != 0) {
      piVar3 = (int *)0x0;
      if (param_1 != (int *)0x0) {
        piVar3 = piVar1;
      }
      if (param_2 <= *(int *)(*piVar3 + 8) - *(int *)(*piVar3 + 4)) goto LAB_000463bb;
    }
    flush__7ostream(piVar1[1]);
  }
LAB_000463bb:
  if (param_2 == 0) {
    iVar2 = 0;
    if (param_1 != (int *)0x0) {
      iVar2 = *param_1;
    }
    if ((*(byte *)(iVar2 + 0xc) & 1) != 0) {
      uVar4 = _skip_ws__7istream(param_1);
      return uVar4;
    }
  }
  return 1;
}


