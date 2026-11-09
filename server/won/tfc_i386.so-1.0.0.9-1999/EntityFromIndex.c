// EntityFromIndex__18CSaveRestoreBufferi  @ 00118dd0
int EntityFromIndex__18CSaveRestoreBufferi(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((*param_1 != 0) && (-1 < param_2)) {
    iVar2 = 0;
    iVar3 = *param_1;
    if (0 < *(int *)(iVar3 + 0x20)) {
      do {
        piVar1 = (int *)(*(int *)(iVar3 + 0x28) + iVar2 * 0x18);
        if (*piVar1 == param_2) {
          return piVar1[1];
        }
        iVar2 = iVar2 + 1;
        iVar3 = *param_1;
      } while (iVar2 < *(int *)(iVar3 + 0x20));
    }
  }
  return 0;
}


