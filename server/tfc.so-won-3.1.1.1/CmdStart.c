// CmdStart__FPC7edict_sPC9usercmd_sUi  @ 00094360
void CmdStart__FPC7edict_sPC9usercmd_sUi(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x288);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_000943a2;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_000943a2:
  if (piVar2 != (int *)0x0) {
    if (*(int *)(*piVar2 + 0x240) != 0) {
      UTIL_SetGroupTrace__Fii(*(undefined4 *)(*piVar2 + 0x240),0);
    }
    piVar2[0x1ac] = param_3;
  }
  return;
}


