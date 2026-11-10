// ws__FR7istream  @ 0809c730
/* WARNING: Removing unreachable block (ram,0x0809c798) */
/* WARNING: Removing unreachable block (ram,0x0809c7ee) */

int * ws__FR7istream(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
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
    iVar1 = skip_ws__FP9streambuf(*piVar3);
    if (iVar1 == -1) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 1;
    }
    else {
      sputbackc__9streambufc(*(undefined4 *)*param_1,(int)(char)iVar1);
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  return param_1;
}


