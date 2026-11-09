// TurnOn__15CFuncWallToggle  @ 0009b790
void TurnOn__15CFuncWallToggle(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 4;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// TurnOn__6CLaser  @ 000adb50
void TurnOn__6CLaser(int *param_1)

{
  undefined4 *puVar1;
  
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
  if (param_1[0xf3] != 0) {
    TurnOn__7CSprite(param_1[0xf3]);
  }
  puVar1 = gpGlobals;
  *(undefined4 *)(*param_1 + 0x1c4) = *gpGlobals;
  *(undefined4 *)(*param_1 + 0xe4) = *puVar1;
  return;
}


// TurnOn__7CSprite  @ 000ae440
void TurnOn__7CSprite(int *param_1)

{
  float fVar1;
  int *piVar2;
  
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  fVar1 = *(float *)(*param_1 + 0x118);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_000ae47a:
    if ((*(byte *)(*param_1 + 0x180) & 2) == 0) goto LAB_000ae4af;
  }
  else {
    fVar1 = (float)param_1[0xf4];
    if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 1) goto LAB_000ae47a;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)AnimateThink__7CSprite;
  piVar2 = gpGlobals;
  *(int *)(*param_1 + 0xe4) = *gpGlobals;
  param_1[0xf3] = *piVar2;
LAB_000ae4af:
  *(undefined4 *)(*param_1 + 0x110) = 0;
  return;
}


