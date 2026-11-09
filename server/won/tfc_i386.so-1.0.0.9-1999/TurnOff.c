// TurnOff__15CFuncWallToggle  @ 0009b760
void TurnOff__15CFuncWallToggle(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// TurnOff__6CLaser  @ 000adb10
void TurnOff__6CLaser(int *param_1)

{
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  *(undefined4 *)(*param_1 + 0xe4) = 0;
  if (param_1[0xf3] != 0) {
    TurnOff__7CSprite(param_1[0xf3]);
  }
  return;
}


// TurnOff__7CSprite  @ 000ae410
void TurnOff__7CSprite(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  *(undefined4 *)(*param_1 + 0xe4) = 0;
  return;
}


