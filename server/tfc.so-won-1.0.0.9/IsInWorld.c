// IsInWorld__11CBaseEntity  @ 000a18c0
undefined4 IsInWorld__11CBaseEntity(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = *(float *)(*param_1 + 8);
  if ((((((byte)((4096.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 4096.0) << 0xe) >> 8)) - 1) < 0x40) ||
        (fVar1 = *(float *)(*param_1 + 0xc),
        (byte)((4096.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 4096.0) << 0xe) >> 8)) - 1) < 0x40)) ||
       (fVar1 = *(float *)(*param_1 + 0x10),
       (byte)((4096.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 4096.0) << 0xe) >> 8)) - 1) < 0x40)) ||
      ((((*(float *)(*param_1 + 8) <= -4096.0 || (*(float *)(*param_1 + 0xc) <= -4096.0)) ||
        ((*(float *)(*param_1 + 0x10) <= -4096.0 ||
         ((fVar1 = *(float *)(*param_1 + 0x20),
          (byte)((2000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 2000.0) << 0xe) >> 8)) - 1) < 0x40 ||
          (fVar1 = *(float *)(*param_1 + 0x24),
          (byte)((2000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 2000.0) << 0xe) >> 8)) - 1) < 0x40)))))) ||
       (fVar1 = *(float *)(*param_1 + 0x28),
       (byte)((2000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 2000.0) << 0xe) >> 8)) - 1) < 0x40)))) ||
     (((*(float *)(*param_1 + 0x20) <= -2000.0 || (*(float *)(*param_1 + 0x24) <= -2000.0)) ||
      (*(float *)(*param_1 + 0x28) <= -2000.0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


