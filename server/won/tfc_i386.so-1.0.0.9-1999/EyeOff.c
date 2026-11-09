// EyeOff__11CBaseTurret  @ 00114320
void EyeOff__11CBaseTurret(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x618) != 0) && (0 < *(int *)(param_1 + 0x61c))) {
    iVar1 = *(int *)(param_1 + 0x61c) + -0x1e;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x61c) = iVar1;
    *(float *)(**(int **)(param_1 + 0x618) + 300) = (float)iVar1;
  }
  return;
}


