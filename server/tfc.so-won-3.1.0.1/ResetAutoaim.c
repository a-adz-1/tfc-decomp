// ResetAutoaim__11CBasePlayer  @ 000d32b0
void ResetAutoaim__11CBasePlayer(int *param_1)

{
  float fVar1;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x254]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x254] == 0.0) << 0xe) >> 8)) != 0x40) ||
     (fVar1 = (float)param_1[0x255],
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    param_1[0x254] = 0;
    param_1[0x255] = 0;
    param_1[0x256] = 0;
    (*DAT_001a7fb8)(*(undefined4 *)(*param_1 + 0x208),0,0);
  }
  param_1[599] = 0;
  return;
}


