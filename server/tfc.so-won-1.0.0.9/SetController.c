// SetController__FPvP9entvars_tif  @ 0009b040
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble SetController__FPvP9entvars_tif(int param_1,int param_2,int param_3,float param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  lVar5 = (longdouble)param_4;
  if (param_1 == 0) {
    return lVar5;
  }
  if (*(int *)(param_1 + 0x94) <= param_3) {
    return lVar5;
  }
  iVar1 = param_1 + *(int *)(param_1 + 0x98) + param_3 * 0x18;
  if ((*(byte *)(iVar1 + 4) & 0x38) != 0) {
    fVar2 = *(float *)(iVar1 + 0xc);
    fVar3 = *(float *)(iVar1 + 8);
    if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
      lVar5 = -lVar5;
    }
    if (*(float *)(iVar1 + 8) + 359.0 < *(float *)(iVar1 + 0xc)) {
      lVar6 = (longdouble)360.0;
      if ((byte)(lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) == 1) {
        lVar5 = lVar5 - (longdouble)360.0 * (longdouble)(int)ROUND(lVar5 / (longdouble)360.0);
      }
      else {
        if ((longdouble)0 <= lVar5) goto LAB_0009b17c;
        lVar5 = (longdouble)360.0 *
                (longdouble)(int)ROUND((longdouble)1 + lVar5 / (longdouble)-360.0) + lVar5;
      }
      lVar5 = (longdouble)(float)lVar5;
    }
    else {
      lVar6 = (longdouble)180.0 +
              (longdouble)0.5 *
              ((longdouble)*(float *)(iVar1 + 8) + (longdouble)*(float *)(iVar1 + 0xc));
      if ((byte)(lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) == 1) {
        lVar5 = lVar5 - (longdouble)360.0;
      }
      if (lVar5 < (longdouble)0.5 *
                  ((longdouble)*(float *)(iVar1 + 8) + (longdouble)*(float *)(iVar1 + 0xc)) -
                  (longdouble)180.0) {
        lVar5 = (longdouble)360.0 + lVar5;
      }
    }
  }
LAB_0009b17c:
  iVar4 = (int)ROUND(((longdouble)255.0 * (lVar5 - (longdouble)*(float *)(iVar1 + 8))) /
                     ((longdouble)*(float *)(iVar1 + 0xc) - (longdouble)*(float *)(iVar1 + 8)));
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (0xff < iVar4) {
    iVar4 = 0xff;
  }
  *(char *)(param_3 + 0x11c + param_2) = (char)iVar4;
  return (longdouble)
         ((*(float *)(iVar1 + 0xc) - *(float *)(iVar1 + 8)) * (float)_FUN_0012aa40 * (float)iVar4 +
         *(float *)(iVar1 + 8));
}


