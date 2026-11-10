// IsOn__15CFuncWallToggle  @ 000806b8
bool IsOn__15CFuncWallToggle(int *param_1)

{
  return *(int *)(*param_1 + 0x10c) != 0;
}


// IsOn__6CLaser  @ 00098640
bool IsOn__6CLaser(int *param_1)

{
  return -1 < *(char *)(*param_1 + 0x118);
}


