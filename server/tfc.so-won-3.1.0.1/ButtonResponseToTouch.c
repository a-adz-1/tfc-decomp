// ButtonResponseToTouch__11CBaseButton  @ 00083ef4
undefined4 ButtonResponseToTouch__11CBaseButton(int *param_1)

{
  if (1 < param_1[0xfd] - 2U) {
    if (param_1[0xfd] != 0) {
      return 1;
    }
    if ((param_1[0x11e] != 0) || ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0)) {
      if (param_1[0xfd] != 0) {
        return 1;
      }
      if (((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0) && (param_1[0x11e] == 0)) {
        return 2;
      }
    }
  }
  return 0;
}


