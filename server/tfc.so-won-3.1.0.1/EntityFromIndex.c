// EntityFromIndex__18CSaveRestoreBufferi  @ 0010cee4
int EntityFromIndex__18CSaveRestoreBufferi(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((*param_1 != 0) && (-1 < param_2)) {
    iVar4 = 0;
    iVar1 = *param_1;
    if (0 < *(int *)(iVar1 + 0x20)) {
      iVar3 = 0;
      do {
        piVar2 = (int *)(*(int *)(iVar1 + 0x28) + iVar3);
        if (*piVar2 == param_2) {
          return piVar2[1];
        }
        iVar3 = iVar3 + 0x18;
        iVar4 = iVar4 + 1;
        iVar1 = *param_1;
      } while (iVar4 < *(int *)(iVar1 + 0x20));
    }
  }
  return 0;
}


