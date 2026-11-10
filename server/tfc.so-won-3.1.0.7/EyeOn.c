// EyeOn__11CBaseTurret  @ 00116ecc
void EyeOn__11CBaseTurret(int param_1)

{
  if (*(int *)(param_1 + 0x694) != 0) {
    if (*(int *)(param_1 + 0x698) != 0xff) {
      *(undefined4 *)(param_1 + 0x698) = 0xff;
    }
    *(float *)(**(int **)(param_1 + 0x694) + 0x14c) = (float)*(int *)(param_1 + 0x698);
  }
  return;
}


