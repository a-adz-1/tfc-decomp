// CanFire__9CFuncTank  @ 000a2cd0
bool CanFire__9CFuncTank(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = *gpGlobals - *(float *)(param_1 + 0x414);
  fVar1 = *(float *)(param_1 + 0x418);
  return (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1;
}


