// SetMovedir__FP9entvars_s  @ 000e71c4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetMovedir__FP9entvars_s(int param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x50)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x50) == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x54)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == -1.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(param_1 + 0x58);
    bVar3 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
  }
  if (bVar3) {
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0x3f800000;
  }
  else {
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x50)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(param_1 + 0x50) == 0.0) << 0xe) >> 8)) == 0x40)
       && ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(param_1 + 0x54)) || NAN(_FUN_0013d2e0)) <<
                                 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == _FUN_0013d2e0) << 0xe) >> 8)
                 ) == 0x40)) {
      fVar1 = *(float *)(param_1 + 0x58);
      bVar3 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
    }
    if (bVar3) {
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x4c) = 0xbf800000;
    }
    else {
      UTIL_MakeVectors__FRC6Vector(param_1 + 0x50);
      iVar2 = gpGlobals;
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(gpGlobals + 0x28);
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar2 + 0x2c);
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar2 + 0x30);
    }
  }
  *(undefined4 *)(param_1 + 0x50) = g_vecZero;
  *(undefined4 *)(param_1 + 0x54) = DAT_001a7e04;
  *(undefined4 *)(param_1 + 0x58) = DAT_001a7e08;
  return;
}


