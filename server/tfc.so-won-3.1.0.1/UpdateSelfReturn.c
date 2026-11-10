// UpdateSelfReturn__19CMomentaryRotButtonf  @ 00085100
void UpdateSelfReturn__19CMomentaryRotButtonf(int *param_1,float param_2)

{
  int iVar1;
  float fVar2;
  
  if ((byte)(0.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) == 1) {
    iVar1 = *param_1;
    fVar2 = -(float)param_1[0x120];
    *(float *)(iVar1 + 0x5c) = fVar2 * *(float *)(iVar1 + 0x44);
    *(float *)(iVar1 + 0x60) = fVar2 * *(float *)(iVar1 + 0x48);
    *(float *)(iVar1 + 100) = fVar2 * *(float *)(iVar1 + 0x4c);
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  }
  else {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
    *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x121];
    *(int *)(iVar1 + 0x54) = param_1[0x122];
    *(int *)(iVar1 + 0x58) = param_1[0x123];
    *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  return;
}


