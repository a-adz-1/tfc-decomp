// TurnOn__15CFuncWallToggle  @ 000885a4
void TurnOn__15CFuncWallToggle(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// TurnOn__6CLaser  @ 000a2c1c
void TurnOn__6CLaser(int *param_1)

{
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
  if (param_1[0x112] != 0) {
    TurnOn__7CSprite(param_1[0x112]);
  }
  *(undefined4 *)(*param_1 + 0x1e4) = *gpGlobals;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// TurnOn__7CSprite  @ 000a368c
void TurnOn__7CSprite(int *param_1)

{
  float fVar1;
  
  *(undefined4 *)(*param_1 + 0x118) = 0;
  fVar1 = *(float *)(*param_1 + 0x138);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_000a36d9:
    if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) goto LAB_000a371a;
  }
  else {
    fVar1 = (float)param_1[0x113];
    if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 1) goto LAB_000a36d9;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)AnimateThink__7CSprite;
  *(int *)(*param_1 + 0x104) = *gpGlobals;
  param_1[0x112] = *gpGlobals;
LAB_000a371a:
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


