// ButtonResponseToTouch__11CBaseButton  @ 0008bef8
undefined4 ButtonResponseToTouch__11CBaseButton(int *param_1)

{
  if (1 < param_1[0x119] - 2U) {
    if (param_1[0x119] != 0) {
      return 1;
    }
    if ((param_1[0x13a] != 0) || ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0)) {
      if (param_1[0x119] != 0) {
        return 1;
      }
      if (((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0) && (param_1[0x13a] == 0)) {
        return 2;
      }
    }
  }
  return 0;
}


