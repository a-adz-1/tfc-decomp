// SetMovedir__FP9entvars_t  @ 000f0870
void SetMovedir__FP9entvars_t(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  bVar4 = false;
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x50)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x50) == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x54)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == -1.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(param_1 + 0x58);
    bVar4 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
  }
  if (bVar4) {
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    uVar3 = 0x3f800000;
  }
  else {
    bVar4 = false;
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x50)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(param_1 + 0x50) == 0.0) << 0xe) >> 8)) == 0x40)
       && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x54)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == -2.0) << 0xe) >> 8)) == 0x40
          )) {
      fVar1 = *(float *)(param_1 + 0x58);
      bVar4 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
    }
    if (bVar4) {
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      uVar3 = 0xbf800000;
    }
    else {
      UTIL_MakeVectors__FRC6Vector(param_1 + 0x50);
      iVar2 = gpGlobals;
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(gpGlobals + 0x28);
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar2 + 0x2c);
      uVar3 = *(undefined4 *)(iVar2 + 0x30);
    }
  }
  *(undefined4 *)(param_1 + 0x4c) = uVar3;
  *(undefined4 *)(param_1 + 0x50) = g_vecZero;
  *(undefined4 *)(param_1 + 0x54) = DAT_00175484;
  *(undefined4 *)(param_1 + 0x58) = DAT_00175488;
  return;
}


