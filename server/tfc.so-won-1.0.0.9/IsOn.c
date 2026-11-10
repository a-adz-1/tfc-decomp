// IsOn__15CFuncWallToggle  @ 0009b7c0
bool IsOn__15CFuncWallToggle(int *param_1)

{
  return *(int *)(*param_1 + 0xec) != 0;
}


// IsOn__6CLaser  @ 000adae0
bool IsOn__6CLaser(int *param_1)

{
  return -1 < *(char *)(*param_1 + 0xf8);
}


