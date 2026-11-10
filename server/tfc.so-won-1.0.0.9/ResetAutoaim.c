// ResetAutoaim__11CBasePlayer  @ 000df790
void ResetAutoaim__11CBasePlayer(int *param_1)

{
  float fVar1;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x24f]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x24f] == 0.0) << 0xe) >> 8)) != 0x40) ||
     (fVar1 = (float)param_1[0x250],
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    param_1[0x24f] = 0;
    param_1[0x250] = 0;
    param_1[0x251] = 0;
    (*DAT_00175638)(*(undefined4 *)(*param_1 + 0x1e8),0,0);
  }
  param_1[0x252] = 0;
  return;
}


