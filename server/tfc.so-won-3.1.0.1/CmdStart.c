// CmdStart__FPC7edict_sPC9usercmd_sUi  @ 0008bee0
void CmdStart__FPC7edict_sPC9usercmd_sUi(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x288);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_0008bf1e;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_0008bf1e:
  if (piVar2 != (int *)0x0) {
    if (*(int *)(*piVar2 + 0x240) != 0) {
      UTIL_SetGroupTrace__Fii(*(undefined4 *)(*piVar2 + 0x240),0);
    }
    piVar2[0x187] = param_3;
  }
  return;
}


