// anglemod__Ff  @ 000be190
void anglemod__Ff(float param_1)

{
  byte bVar1;
  
  bVar1 = 360.0 < param_1 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
          (byte)((ushort)((ushort)(param_1 == 360.0) << 0xe) >> 8);
  while ((byte)(bVar1 - 1) < 0x40) {
    param_1 = param_1 - 360.0;
    bVar1 = 360.0 < param_1 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == 360.0) << 0xe) >> 8);
  }
  if (param_1 < 0.0) {
    do {
      param_1 = param_1 + 360.0;
    } while ((byte)(param_1 < 0.0 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) == 1);
  }
  return;
}


