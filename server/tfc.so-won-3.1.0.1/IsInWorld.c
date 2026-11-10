// IsInWorld__11CBaseEntity  @ 000871b8
undefined4 IsInWorld__11CBaseEntity(int *param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 8);
  if (((((0x3f < (byte)((4096.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 4096.0) << 0xe) >> 8)) - 1)) &&
        (fVar1 = *(float *)(*param_1 + 0xc),
        0x3f < (byte)((4096.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 4096.0) << 0xe) >> 8)) - 1))) &&
       (fVar1 = *(float *)(*param_1 + 0x10),
       0x3f < (byte)((4096.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 4096.0) << 0xe) >> 8)) - 1))) &&
      ((((-4096.0 < *(float *)(*param_1 + 8) && (-4096.0 < *(float *)(*param_1 + 0xc))) &&
        ((-4096.0 < *(float *)(*param_1 + 0x10) &&
         ((fVar1 = *(float *)(*param_1 + 0x20),
          0x3f < (byte)((2000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 2000.0) << 0xe) >> 8)) - 1) &&
          (fVar1 = *(float *)(*param_1 + 0x24),
          0x3f < (byte)((2000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 2000.0) << 0xe) >> 8)) - 1))))))) &&
       (fVar1 = *(float *)(*param_1 + 0x28),
       0x3f < (byte)((2000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 2000.0) << 0xe) >> 8)) - 1))))) &&
     (((-2000.0 < *(float *)(*param_1 + 0x20) && (-2000.0 < *(float *)(*param_1 + 0x24))) &&
      (-2000.0 < *(float *)(*param_1 + 0x28))))) {
    return 1;
  }
  return 0;
}


