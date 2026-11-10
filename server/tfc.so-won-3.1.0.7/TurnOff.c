// TurnOff__15CFuncWallToggle  @ 0008856c
void TurnOff__15CFuncWallToggle(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// TurnOff__6CLaser  @ 000a2bdc
void TurnOff__6CLaser(int *param_1)

{
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  *(undefined4 *)(*param_1 + 0x104) = 0;
  if (param_1[0x112] != 0) {
    TurnOff__7CSprite(param_1[0x112]);
  }
  return;
}


// TurnOff__7CSprite  @ 000a366c
void TurnOff__7CSprite(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  *(undefined4 *)(*param_1 + 0x104) = 0;
  return;
}


