// CmdEnd__FPC7edict_s  @ 0008bf50
void CmdEnd__FPC7edict_s(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x288);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_0008bf8e;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_0008bf8e:
  if ((piVar2 != (int *)0x0) && (*(int *)(*piVar2 + 0x240) != 0)) {
    UTIL_UnsetGroupTrace__Fv();
  }
  return;
}


