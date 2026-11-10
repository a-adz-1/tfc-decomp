// InitTrigger__12CBaseTrigger  @ 0010fd90
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
     (byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_00175484 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x58);
    bVar2 = (byte)(DAT_00175488 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar2) {
    SetMovedir__FP9entvars_t(*param_1);
  }
  *(undefined4 *)(*param_1 + 0xec) = 1;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  lVar3 = (longdouble)(*DAT_001755a4)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar3) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  }
  return;
}


