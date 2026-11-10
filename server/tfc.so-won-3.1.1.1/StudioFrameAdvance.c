// StudioFrameAdvance__14CBaseAnimatingf  @ 000bb614
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble StudioFrameAdvance__14CBaseAnimatingf(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar4 = (longdouble)param_2;
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    lVar4 = (longdouble)*gpGlobals - (longdouble)*(float *)(*param_1 + 0x134);
    lVar5 = (longdouble)_FUN_0014dc10;
    if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) != 1) {
      *(float *)(*param_1 + 0x134) = *gpGlobals;
      return (longdouble)0;
    }
  }
  iVar3 = *param_1;
  lVar5 = (longdouble)0;
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)*(float *)(iVar3 + 0x134)) || NAN(lVar5)) <<
                            10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)*(float *)(iVar3 + 0x134) == lVar5) << 0xe) >> 8))
      == 0x40) {
    lVar4 = lVar5;
  }
  *(float *)(iVar3 + 0x130) =
       (float)(lVar4 * (longdouble)(float)param_1[0x118] * (longdouble)*(float *)(iVar3 + 0x138) +
              (longdouble)*(float *)(iVar3 + 0x130));
  *(float *)(*param_1 + 0x134) = *gpGlobals;
  fVar1 = *(float *)(*param_1 + 0x130);
  if ((fVar1 < 0.0) || (256.0 <= fVar1)) {
    if (param_1[0x11c] == 0) {
      fVar2 = 0.0;
      if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
        fVar2 = 255.0;
      }
    }
    else {
      fVar2 = fVar1 - (float)(int)ROUND(fVar1 * 0.00390625) * 256.0;
    }
    *(float *)(*param_1 + 0x130) = fVar2;
    param_1[0x11b] = 1;
  }
  return lVar4;
}


