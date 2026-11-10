// InRange__9CFuncTankf  @ 000ac878
undefined4 InRange__9CFuncTankf(int param_1,float param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = *(float *)(param_1 + 0x49c);
  if (((byte)(param_2 < fVar1 | (byte)((ushort)((ushort)(NAN(param_2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == fVar1) << 0xe) >> 8)) == 1) ||
     ((0.0 < *(float *)(param_1 + 0x4a0) && (*(float *)(param_1 + 0x4a0) < param_2)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


