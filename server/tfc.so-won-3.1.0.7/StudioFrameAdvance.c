// StudioFrameAdvance__14CBaseAnimatingf  @ 000ba444
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble StudioFrameAdvance__14CBaseAnimatingf(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar3 = (longdouble)param_2;
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0.0) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0.0 == lVar3) << 0xe) >> 8)) == 0x40) {
    lVar3 = (longdouble)*gpGlobals - (longdouble)*(float *)(*param_1 + 0x134);
    lVar4 = (longdouble)_FUN_00148710;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 1) {
      *(float *)(*param_1 + 0x134) = *gpGlobals;
      return (longdouble)0.0;
    }
  }
  lVar4 = (longdouble)0.0;
  if ((byte)((byte)((ushort)((ushort)(NAN(lVar4) || NAN((longdouble)*(float *)(*param_1 + 0x134)))
                            << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == (longdouble)*(float *)(*param_1 + 0x134)) << 0xe) >> 8
                  )) == 0x40) {
    lVar3 = lVar4;
  }
  iVar2 = *param_1;
  *(float *)(iVar2 + 0x130) =
       (float)(lVar3 * (longdouble)(float)param_1[0x114] * (longdouble)*(float *)(iVar2 + 0x138) +
              (longdouble)*(float *)(iVar2 + 0x130));
  *(float *)(*param_1 + 0x134) = *gpGlobals;
  if ((*(float *)(*param_1 + 0x130) < 0.0) || (256.0 <= *(float *)(*param_1 + 0x130))) {
    if (param_1[0x118] == 0) {
      iVar2 = *param_1;
      fVar1 = 0.0;
      if (0.0 <= *(float *)(iVar2 + 0x130)) {
        fVar1 = 255.0;
      }
    }
    else {
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar2 + 0x130) -
              (float)(int)ROUND(*(float *)(iVar2 + 0x130) * 0.00390625) * 256.0;
    }
    *(float *)(iVar2 + 0x130) = fVar1;
    param_1[0x117] = 1;
  }
  return lVar3;
}


