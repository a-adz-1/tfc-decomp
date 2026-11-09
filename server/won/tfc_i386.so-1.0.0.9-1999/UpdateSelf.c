// UpdateSelf__19CMomentaryRotButtonf  @ 0009f730
void UpdateSelf__19CMomentaryRotButtonf(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = param_1[0x11b];
  if (iVar3 == 0) {
    param_1[0x11c] = -param_1[0x11c];
  }
  param_1[0x11b] = 1;
  *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.1;
  if ((param_1[0x11c] < 1) ||
     (0x3f < (byte)((1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) - 1))) {
    if ((-1 < param_1[0x11c]) || (0.0 < param_2)) {
      if (iVar3 == 0) {
        PlaySound__19CMomentaryRotButton(param_1);
      }
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0xe4);
      fVar2 = *(float *)(iVar3 + 0xe0);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        *(float *)(iVar3 + 0xe4) = *(float *)(iVar3 + 0xe0) + 0.1;
      }
      else {
        *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe4) + 0.1;
      }
      iVar3 = *param_1;
      fVar1 = (float)param_1[0x11c] * *(float *)(iVar3 + 0x1d8);
      *(float *)(iVar3 + 0x5c) = fVar1 * *(float *)(iVar3 + 0x44);
      *(float *)(iVar3 + 0x60) = fVar1 * *(float *)(iVar3 + 0x48);
      *(float *)(iVar3 + 100) = fVar1 * *(float *)(iVar3 + 0x4c);
      param_1[3] = -0x10000;
      param_1[4] = (int)Off__19CMomentaryRotButton;
    }
    else {
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar3 + 0x60) = DAT_00175484;
      *(undefined4 *)(iVar3 + 100) = DAT_00175488;
      iVar3 = *param_1;
      *(int *)(iVar3 + 0x50) = param_1[0x11e];
      *(int *)(iVar3 + 0x54) = param_1[0x11f];
      *(int *)(iVar3 + 0x58) = param_1[0x120];
    }
  }
  else {
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar3 + 0x60) = DAT_00175484;
    *(undefined4 *)(iVar3 + 100) = DAT_00175488;
    iVar3 = *param_1;
    *(int *)(iVar3 + 0x50) = param_1[0x121];
    *(int *)(iVar3 + 0x54) = param_1[0x122];
    *(int *)(iVar3 + 0x58) = param_1[0x123];
  }
  return;
}


