// ServerSide__10CLightning  @ 0009b658
undefined4 ServerSide__10CLightning(int *param_1)

{
  undefined4 uVar1;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf9]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0xf9] == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((*(byte *)(*param_1 + 0x1a0) & 8) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


