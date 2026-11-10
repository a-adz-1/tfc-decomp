// ShouldAnimate__13CCyclerSprite  @ 000aa4d0
bool ShouldAnimate__13CCyclerSprite(int param_1)

{
  float fVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(int *)(param_1 + 0x3d8) != 0) {
    fVar1 = *(float *)(param_1 + 0x3e0);
    bVar2 = (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1;
  }
  return bVar2;
}


