// MessageThink__12CRevertSaved  @ 000d3ea8
void MessageThink__12CRevertSaved(int *param_1)

{
  UTIL_ShowMessageAll__FPCc(*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26]);
  if ((float)param_1[0xf7] - (float)param_1[0xf6] <= 0.0) {
    LoadThink__12CRevertSaved(param_1);
  }
  else {
    *(float *)(*param_1 + 0x104) = ((float)param_1[0xf7] - (float)param_1[0xf6]) + *gpGlobals;
    param_1[3] = -0x10000;
    param_1[4] = (int)LoadThink__12CRevertSaved;
  }
  return;
}


