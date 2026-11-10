// InitTrigger__12CBaseTrigger  @ 001196ac
void InitTrigger__12CBaseTrigger(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x58);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    SetMovedir__FP9entvars_s(iVar2);
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  return;
}


