// UpdateSelf__19CMomentaryRotButtonf  @ 0008bce4
void UpdateSelf__19CMomentaryRotButtonf(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = param_1[0x13e];
  if (iVar3 == 0) {
    param_1[0x13f] = -param_1[0x13f];
  }
  param_1[0x13e] = 1;
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  if ((param_1[0x13f] < 1) || (param_2 < 1.0)) {
    if ((param_1[0x13f] < 0) &&
       ((byte)(0.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) != 1)) {
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar3 + 0x60) = DAT_0019f664;
      *(undefined4 *)(iVar3 + 100) = DAT_0019f668;
      iVar3 = *param_1;
      *(int *)(iVar3 + 0x50) = param_1[0x141];
      *(int *)(iVar3 + 0x54) = param_1[0x142];
      *(int *)(iVar3 + 0x58) = param_1[0x143];
    }
    else {
      if (iVar3 == 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),2,
                   *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,
                   100);
      }
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0x104);
      fVar2 = *(float *)(iVar3 + 0x100);
      if (0x3f < (byte)((fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
        fVar1 = fVar2;
      }
      *(float *)(iVar3 + 0x104) = fVar1 + 0.1;
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0x1f8) * (float)param_1[0x13f];
      *(float *)(iVar3 + 0x5c) = *(float *)(iVar3 + 0x44) * fVar1;
      *(float *)(iVar3 + 0x60) = *(float *)(iVar3 + 0x48) * fVar1;
      *(float *)(iVar3 + 100) = fVar1 * *(float *)(iVar3 + 0x4c);
      param_1[3] = -0x10000;
      param_1[4] = (int)Off__19CMomentaryRotButton;
    }
  }
  else {
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar3 + 0x60) = DAT_0019f664;
    *(undefined4 *)(iVar3 + 100) = DAT_0019f668;
    iVar3 = *param_1;
    *(int *)(iVar3 + 0x50) = param_1[0x144];
    *(int *)(iVar3 + 0x54) = param_1[0x145];
    *(int *)(iVar3 + 0x58) = param_1[0x146];
  }
  return;
}


