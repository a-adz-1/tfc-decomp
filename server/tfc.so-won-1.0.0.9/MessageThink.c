// MessageThink__12CRevertSaved  @ 000e0140
void MessageThink__12CRevertSaved(int *param_1)

{
  float fVar1;
  
  UTIL_ShowMessageAll__FPCc(*(int *)(*param_1 + 0x1b4) + (int)gpGlobals[0x26]);
  fVar1 = (float)param_1[0xf4] - (float)param_1[0xf3];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(float *)(*param_1 + 0xe4) = fVar1 + *gpGlobals;
    param_1[3] = -0x10000;
    param_1[4] = (int)LoadThink__12CRevertSaved;
  }
  else {
    LoadThink__12CRevertSaved(param_1);
  }
  return;
}


