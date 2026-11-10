// SetController__FPvP9entvars_sif  @ 0008749c
longdouble SetController__FPvP9entvars_sif(int param_1,int param_2,int param_3,float param_4)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  lVar3 = (longdouble)param_4;
  if (param_1 == 0) {
    return lVar3;
  }
  if (*(int *)(param_1 + 0x94) <= param_3) {
    return lVar3;
  }
  iVar1 = param_1 + *(int *)(param_1 + 0x98) + param_3 * 0x18;
  if ((*(byte *)(iVar1 + 4) & 0x38) != 0) {
    lVar4 = (longdouble)*(float *)(iVar1 + 0xc);
    lVar5 = (longdouble)*(float *)(iVar1 + 8);
    if (0x3f < (byte)((lVar5 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
      lVar3 = -lVar3;
    }
    lVar6 = (longdouble)359.0 + lVar5;
    if ((byte)(lVar6 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar6 == lVar4) << 0xe) >> 8)) == 1) {
      if (lVar3 <= (longdouble)360.0) {
        lVar4 = (longdouble)0;
        if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40)
        goto LAB_000875e7;
        lVar3 = (longdouble)360.0 *
                (longdouble)(int)ROUND((longdouble)1 + lVar3 * (longdouble)-0.002777777777777778) +
                lVar3;
      }
      else {
        lVar3 = lVar3 - (longdouble)360.0 *
                        (longdouble)(int)ROUND(lVar3 * (longdouble)0.002777777777777778);
      }
      lVar3 = (longdouble)(float)lVar3;
    }
    else {
      lVar5 = (longdouble)0.5 * (lVar5 + lVar4);
      lVar4 = lVar5 + (longdouble)180.0;
      if (0x3f < (byte)((lVar3 < lVar4 |
                         (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) - 1)) {
        lVar3 = lVar3 - (longdouble)360.0;
      }
      lVar5 = lVar5 - (longdouble)180.0;
      if (0x3f < (byte)((lVar5 < lVar3 |
                         (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar5 == lVar3) << 0xe) >> 8)) - 1)) {
        lVar3 = (longdouble)360.0 + lVar3;
      }
    }
  }
LAB_000875e7:
  iVar2 = (int)ROUND(((longdouble)255.0 * (lVar3 - (longdouble)*(float *)(iVar1 + 8))) /
                     ((longdouble)*(float *)(iVar1 + 0xc) - (longdouble)*(float *)(iVar1 + 8)));
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (0xff < iVar2) {
    iVar2 = 0xff;
  }
  *(char *)(param_3 + 0x13c + param_2) = (char)iVar2;
  return (longdouble)
         ((*(float *)(iVar1 + 0xc) - *(float *)(iVar1 + 8)) * 0.003921569 * (float)iVar2 +
         *(float *)(iVar1 + 8));
}


