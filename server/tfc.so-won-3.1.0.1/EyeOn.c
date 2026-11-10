// EyeOn__11CBaseTurret  @ 00107400
void EyeOn__11CBaseTurret(int param_1)

{
  if (*(int *)(param_1 + 0x624) != 0) {
    if (*(int *)(param_1 + 0x628) != 0xff) {
      *(undefined4 *)(param_1 + 0x628) = 0xff;
    }
    *(float *)(**(int **)(param_1 + 0x624) + 0x14c) = (float)*(int *)(param_1 + 0x628);
  }
  return;
}


