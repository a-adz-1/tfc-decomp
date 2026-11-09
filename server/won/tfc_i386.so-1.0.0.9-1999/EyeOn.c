// EyeOn__11CBaseTurret  @ 001142e0
void EyeOn__11CBaseTurret(int param_1)

{
  if (*(int *)(param_1 + 0x618) != 0) {
    if (*(int *)(param_1 + 0x61c) != 0xff) {
      *(undefined4 *)(param_1 + 0x61c) = 0xff;
    }
    *(float *)(**(int **)(param_1 + 0x618) + 300) = (float)*(int *)(param_1 + 0x61c);
  }
  return;
}


