// ShouldAnimate__13CCyclerSprite  @ 000bc3f0
undefined4 ShouldAnimate__13CCyclerSprite(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(int *)(param_1 + 0x3cc) != 0) &&
     (fVar1 = *(float *)(param_1 + 0x3d4),
     (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1)) {
    uVar2 = 1;
  }
  return uVar2;
}


