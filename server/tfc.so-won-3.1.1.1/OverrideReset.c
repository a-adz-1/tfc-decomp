// OverrideReset__10CFuncTrain  @ 000ce704
void OverrideReset__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x20))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x20)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x24))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x24)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x28);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if ((!bVar3) &&
     (fVar1 = *(float *)(iVar2 + 0x104),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    *(undefined4 *)(iVar2 + 0x1c8) = *(undefined4 *)(iVar2 + 0x1d4);
    iVar2 = (**(code **)(param_1[0x115] + 0xac))(param_1);
    if (iVar2 == 0) {
      *(undefined4 *)(*param_1 + 0x104) = 0;
      iVar2 = *param_1;
      *(float *)(iVar2 + 0x20) = g_vecZero;
      *(float *)(iVar2 + 0x24) = DAT_0019f664;
      *(float *)(iVar2 + 0x28) = DAT_0019f668;
    }
    else {
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__10CFuncTrain;
      *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
    }
  }
  return;
}


// OverrideReset__11CBaseEntity  @ 00112e64
void OverrideReset__11CBaseEntity(void)

{
  return;
}


// OverrideReset__15CFuncTrackTrain  @ 000d218c
void OverrideReset__15CFuncTrackTrain(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = *param_1;
  pbVar1 = (byte *)(iVar2 + 0x1a6);
  *pbVar1 = *pbVar1 & 0xdf;
  *(float *)(*param_1 + 0x104) = *(float *)(iVar2 + 0x100) + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)NearestPath__15CFuncTrackTrain;
  return;
}


// OverrideReset__16CFuncTrackChange  @ 000d1d58
void OverrideReset__16CFuncTrackChange(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 1.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__16CFuncTrackChange;
  return;
}


