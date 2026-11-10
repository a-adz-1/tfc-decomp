// IsTalking__12CTalkMonster  @ 000f89c4
bool IsTalking__12CTalkMonster(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *gpGlobals;
  fVar2 = *(float *)(param_1 + 0x700);
  return (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1;
}


