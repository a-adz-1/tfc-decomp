// OverrideReset__10CFuncTrain  @ 000cf0e4
void OverrideReset__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x20))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x20)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x24),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_001c0fe4 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x28);
    bVar3 = (byte)(DAT_001c0fe8 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    iVar2 = *param_1;
    fVar1 = *(float *)(iVar2 + 0x104);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(undefined4 *)(iVar2 + 0x1c8) = *(undefined4 *)(iVar2 + 0x1d4);
      iVar2 = (**(code **)(param_1[0x111] + 0xac))(param_1);
      if (iVar2 == 0) {
        *(undefined4 *)(*param_1 + 0x104) = 0;
        iVar2 = *param_1;
        *(float *)(iVar2 + 0x20) = g_vecZero;
        *(float *)(iVar2 + 0x24) = DAT_001c0fe4;
        *(float *)(iVar2 + 0x28) = DAT_001c0fe8;
      }
      else {
        param_1[3] = -0x10000;
        param_1[4] = (int)Next__10CFuncTrain;
        *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
      }
    }
  }
  return;
}


// OverrideReset__11CBaseEntity  @ 0010f978
void OverrideReset__11CBaseEntity(void)

{
  return;
}


// OverrideReset__15CFuncTrackTrain  @ 000d0b70
void OverrideReset__15CFuncTrackTrain(int *param_1)

{
  NextThink__15CFuncTrackTrainfi(param_1,*(float *)(*param_1 + 0x100) + 0.1,0);
  param_1[3] = -0x10000;
  param_1[4] = (int)NearestPath__15CFuncTrackTrain;
  return;
}


// OverrideReset__16CFuncTrackChange  @ 000d1418
void OverrideReset__16CFuncTrackChange(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 1.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__16CFuncTrackChange;
  return;
}


