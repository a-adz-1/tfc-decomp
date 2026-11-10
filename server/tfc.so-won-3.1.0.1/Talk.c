// Talk__12CTalkMonsterf  @ 000e9728
void Talk__12CTalkMonsterf(int param_1,float param_2)

{
  if ((byte)(0.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) != 1) {
    param_2 = 3.0;
  }
  *(float *)(param_1 + 0x680) = param_2 + *gpGlobals;
  return;
}


