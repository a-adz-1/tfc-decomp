// EntityFromIndex__18CSaveRestoreBufferi  @ 00121604
int EntityFromIndex__18CSaveRestoreBufferi(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  if ((iVar2 != 0) && (-1 < param_2)) {
    iVar3 = 0;
    if (0 < *(int *)(iVar2 + 0x20)) {
      do {
        piVar1 = (int *)(*(int *)(iVar2 + 0x28) + iVar3 * 0x18);
        if (*piVar1 == param_2) {
          return piVar1[1];
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(iVar2 + 0x20));
    }
  }
  return 0;
}


