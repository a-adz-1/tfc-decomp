// CmdEnd__FPC7edict_s  @ 00094a0c
void CmdEnd__FPC7edict_s(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 0x288);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_00094a4e;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_00094a4e:
  if (piVar2 != (int *)0x0) {
    if (*(int *)(*piVar2 + 0x240) != 0) {
      UTIL_UnsetGroupTrace__Fv();
    }
    if (*(int *)(*piVar2 + 0x170) == 5) {
      local_c = 0x41800000;
      local_4 = 0xc2000000;
      local_18 = 0xc1800000;
      local_10 = 0xc2100000;
      local_14 = local_18;
      local_8 = local_c;
      UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar2,&local_18,&local_c);
    }
  }
  return;
}


