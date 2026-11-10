// IsOn__15CFuncWallToggle  @ 000885dc
bool IsOn__15CFuncWallToggle(int *param_1)

{
  return *(int *)(*param_1 + 0x10c) != 0;
}


// IsOn__6CLaser  @ 000a2bc0
bool IsOn__6CLaser(int *param_1)

{
  return -1 < *(char *)(*param_1 + 0x118);
}


