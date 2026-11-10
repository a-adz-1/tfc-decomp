// UpdateSpeed__13CFuncConveyorf  @ 000807d4
void UpdateSpeed__13CFuncConveyorf(int *param_1,float param_2)

{
  if ((byte)((0.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    *(undefined4 *)(*param_1 + 0x150) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x150) = 0x3f800000;
  }
  *(float *)(*param_1 + 0x154) = (float)((int)ROUND(ABS(param_2) * 16.0) >> 8);
  *(float *)(*param_1 + 0x158) = (float)((int)ROUND(ABS(param_2) * 16.0) & 0xff);
  return;
}


