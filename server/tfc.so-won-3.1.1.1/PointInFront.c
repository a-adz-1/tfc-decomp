// PointInFront__6CPlaneRC6Vector  @ 000cd028
undefined4 PointInFront__6CPlaneRC6Vector(float *param_1,float *param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  if ((param_1[4] == 0.0) ||
     (fVar1 = (param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2) - param_1[3]
     , 0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


