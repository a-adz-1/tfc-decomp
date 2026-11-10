// EyeOn__11CBaseTurret  @ 0011d01c
void EyeOn__11CBaseTurret(int param_1)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x6a4) != (int *)0x0) {
    iVar1 = *(int *)(param_1 + 0x6a8);
    if (iVar1 != 0xff) {
      *(undefined4 *)(param_1 + 0x6a8) = 0xff;
      iVar1 = 0xff;
    }
    *(float *)(**(int **)(param_1 + 0x6a4) + 0x14c) = (float)iVar1;
  }
  return;
}


