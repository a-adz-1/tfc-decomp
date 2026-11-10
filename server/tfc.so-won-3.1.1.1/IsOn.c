// IsOn__15CFuncWallToggle  @ 00089e54
bool IsOn__15CFuncWallToggle(int *param_1)

{
  return *(int *)(*param_1 + 0x10c) != 0;
}


// IsOn__6CLaser  @ 000a4d6c
bool IsOn__6CLaser(int *param_1)

{
  return -1 < *(char *)(*param_1 + 0x118);
}


