// EyeOff__11CBaseTurret  @ 0011cfe0
void EyeOff__11CBaseTurret(int param_1)

{
  int iVar1;
  
  if ((*(int **)(param_1 + 0x6a4) != (int *)0x0) && (0 < *(int *)(param_1 + 0x6a8))) {
    iVar1 = *(int *)(param_1 + 0x6a8) + -0x1e;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x6a8) = iVar1;
    *(float *)(**(int **)(param_1 + 0x6a4) + 0x14c) = (float)iVar1;
  }
  return;
}


