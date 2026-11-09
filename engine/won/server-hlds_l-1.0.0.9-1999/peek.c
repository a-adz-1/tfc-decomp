// peek__7istream  @ 0809ac64
int peek__7istream(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    piVar3 = (int *)*param_1;
    if (piVar3[1] != 0) {
      piVar2 = (int *)0x0;
      if (param_1 != (int *)0x0) {
        piVar2 = piVar3;
      }
      if (*(int *)(*piVar2 + 8) == *(int *)(*piVar2 + 4)) {
        flush__7ostream(piVar3[1]);
        piVar3 = (int *)*param_1;
      }
    }
    iVar1 = _IO_peekc_locked((_IO_FILE *)*piVar3);
    if (iVar1 == -1) {
      iVar4 = 0;
      if (param_1 != (int *)0x0) {
        iVar4 = *param_1;
      }
      *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) | 1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


