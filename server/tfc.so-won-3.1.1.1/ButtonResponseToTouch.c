// ButtonResponseToTouch__11CBaseButton  @ 0008cd9c
undefined4 ButtonResponseToTouch__11CBaseButton(int *param_1)

{
  if (1 < param_1[0x11d] - 2U) {
    if (param_1[0x11d] != 0) {
      return 1;
    }
    if ((((param_1[0x13e] != 0) || ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0)) &&
        ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0)) && (param_1[0x13e] == 0)) {
      return 2;
    }
  }
  return 0;
}


