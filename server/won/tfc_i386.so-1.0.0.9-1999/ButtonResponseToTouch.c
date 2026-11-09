// ButtonResponseToTouch__11CBaseButton  @ 0009e9f0
undefined4 ButtonResponseToTouch__11CBaseButton(int *param_1)

{
  if (1 < param_1[0xfa] - 2U) {
    if (param_1[0xfa] != 0) {
      return 1;
    }
    if ((param_1[0x11b] != 0) || ((*(byte *)(*param_1 + 0x180) & 0x20) != 0)) {
      if (param_1[0xfa] != 0) {
        return 1;
      }
      if (((*(byte *)(*param_1 + 0x180) & 0x20) != 0) && (param_1[0x11b] == 0)) {
        return 2;
      }
    }
  }
  return 0;
}


