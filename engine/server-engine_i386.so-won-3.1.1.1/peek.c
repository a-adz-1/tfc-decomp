// peek__7istream  @ 000505d4
int peek__7istream(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (*(char *)((int)piVar1 + 0x12) == '\0') {
    if ((piVar1[1] != 0) && (*(int *)(*piVar1 + 8) == *(int *)(*piVar1 + 4))) {
      flush__7ostream(piVar1[1]);
    }
    iVar2 = _IO_peekc_locked(*(_IO_FILE **)*param_1);
    if (iVar2 == -1) {
      *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 1;
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


