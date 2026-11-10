// FixupAngles__FR6Vector  @ 000ced88
void FixupAngles__FR6Vector(float *param_1)

{
  float fVar1;
  
  fVar1 = *param_1;
  if (fVar1 < 0.0) {
    do {
      fVar1 = fVar1 + 360.0;
    } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
  }
  if (360.0 < fVar1) {
    do {
      fVar1 = fVar1 - 360.0;
    } while ((byte)(360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) == 1);
  }
  *param_1 = fVar1;
  fVar1 = param_1[1];
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    do {
      fVar1 = fVar1 + 360.0;
    } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
  }
  if (360.0 < fVar1) {
    do {
      fVar1 = fVar1 - 360.0;
    } while ((byte)(360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) == 1);
  }
  param_1[1] = fVar1;
  fVar1 = param_1[2];
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    do {
      fVar1 = fVar1 + 360.0;
    } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
  }
  if (360.0 < fVar1) {
    do {
      fVar1 = fVar1 - 360.0;
    } while ((byte)(360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) == 1);
  }
  param_1[2] = fVar1;
  return;
}


