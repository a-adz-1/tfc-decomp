// CmdEnd__FPC7edict_s  @ 00093bd4
void CmdEnd__FPC7edict_s(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x288);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_00093c16;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_00093c16:
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    if (*(int *)(iVar1 + 0x240) != 0) {
      UTIL_UnsetGroupTrace__Fv();
      iVar1 = *piVar2;
    }
    if (*(int *)(iVar1 + 0x170) == 5) {
      local_10 = 0x41800000;
      local_8 = 0xc2000000;
      local_1c = 0xc1800000;
      local_14 = 0xc2100000;
      local_18 = local_1c;
      local_c = local_10;
      UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar2,&local_1c,&local_10);
    }
  }
  return;
}


