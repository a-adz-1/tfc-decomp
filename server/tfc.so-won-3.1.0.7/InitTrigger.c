// InitTrigger__12CBaseTrigger  @ 001118d8
void InitTrigger__12CBaseTrigger(int *param_1)

{
  float fVar1;
  bool bVar2;
  longdouble lVar3;
  
  bVar2 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x50))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x54),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_001c0fe4 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x58);
    bVar2 = (byte)(DAT_001c0fe8 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar2) {
    SetMovedir__FP9entvars_s(*param_1);
  }
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar3 = (longdouble)(*DAT_001c1104)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0.0) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0.0 == lVar3) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  return;
}


