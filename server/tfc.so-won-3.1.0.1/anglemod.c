// anglemod__Ff  @ 000ac6e8
void anglemod__Ff(float param_1)

{
  if (360.0 <= param_1) {
    do {
      param_1 = param_1 - 360.0;
    } while ((byte)((360.0 < param_1 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_1 == 360.0) << 0xe) >> 8)) - 1) < 0x40);
  }
  if (0x3f < (byte)((0.0 < param_1 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) - 1)) {
    do {
      param_1 = param_1 + 360.0;
    } while ((byte)(param_1 < 0.0 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) == 1);
  }
  return;
}


