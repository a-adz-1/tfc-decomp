// StudioFrameAdvance__14CBaseAnimatingf  @ 000c1710
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble StudioFrameAdvance__14CBaseAnimatingf(int *param_1,float param_2)

{
  float fVar1;
  longdouble lVar2;
  int iVar3;
  longdouble lVar4;
  
  lVar4 = (longdouble)param_2;
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    lVar4 = (longdouble)*gpGlobals - (longdouble)*(float *)(*param_1 + 0x114);
    if (lVar4 <= (longdouble)0.001) {
      *(float *)(*param_1 + 0x114) = *gpGlobals;
      return (longdouble)0;
    }
  }
  lVar2 = (longdouble)0;
  if ((byte)((byte)((ushort)((ushort)(NAN(lVar2) || NAN((longdouble)*(float *)(*param_1 + 0x114)))
                            << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar2 == (longdouble)*(float *)(*param_1 + 0x114)) << 0xe) >> 8
                  )) == 0x40) {
    lVar4 = lVar2;
  }
  iVar3 = *param_1;
  *(float *)(iVar3 + 0x110) =
       (float)(lVar4 * (longdouble)(float)param_1[0xf5] * (longdouble)*(float *)(iVar3 + 0x118) +
              (longdouble)*(float *)(iVar3 + 0x110));
  *(float *)(*param_1 + 0x114) = *gpGlobals;
  fVar1 = *(float *)(*param_1 + 0x110);
  if ((fVar1 < 0.0) ||
     ((byte)((256.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 256.0) << 0xe) >> 8)) - 1) < 0x40)) {
    if (param_1[0xf9] == 0) {
      iVar3 = *param_1;
      fVar1 = 0.0;
      if (0.0 <= *(float *)(iVar3 + 0x110)) {
        fVar1 = 255.0;
      }
    }
    else {
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0x110) -
              (float)(int)ROUND((float)_FUN_00135a80 * *(float *)(iVar3 + 0x110)) * 256.0;
    }
    *(float *)(iVar3 + 0x110) = fVar1;
    param_1[0xf8] = 1;
  }
  return lVar4;
}


