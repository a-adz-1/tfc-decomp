// ResetAutoaim__11CBasePlayer  @ 000de9b4
void ResetAutoaim__11CBasePlayer(int *param_1)

{
  float fVar1;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x271]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x271] == 0.0) << 0xe) >> 8)) != 0x40) ||
     (fVar1 = (float)param_1[0x272],
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    param_1[0x271] = 0;
    param_1[0x272] = 0;
    param_1[0x273] = 0;
    (*DAT_001c1198)(*(undefined4 *)(*param_1 + 0x208),0,0);
  }
  param_1[0x274] = 0;
  return;
}


