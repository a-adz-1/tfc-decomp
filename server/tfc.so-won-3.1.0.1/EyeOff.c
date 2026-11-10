// EyeOff__11CBaseTurret  @ 00107438
void EyeOff__11CBaseTurret(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x624) != 0) && (0 < *(int *)(param_1 + 0x628))) {
    iVar1 = *(int *)(param_1 + 0x628) + -0x1e;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x628) = iVar1;
    *(float *)(**(int **)(param_1 + 0x624) + 0x14c) = (float)iVar1;
  }
  return;
}


