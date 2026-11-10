// EyeOff__11CBaseTurret  @ 00116f04
void EyeOff__11CBaseTurret(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x694) != 0) && (0 < *(int *)(param_1 + 0x698))) {
    iVar1 = *(int *)(param_1 + 0x698) + -0x1e;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x698) = iVar1;
    *(float *)(**(int **)(param_1 + 0x694) + 0x14c) = (float)iVar1;
  }
  return;
}


