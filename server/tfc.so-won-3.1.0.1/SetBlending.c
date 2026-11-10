// SetBlending__14CBaseAnimatingif  @ 000b422c
void SetBlending__14CBaseAnimatingif(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001a7f68)(*(undefined4 *)(*param_1 + 0x208));
  SetBlending__FPvP9entvars_sif(uVar1,*param_1,param_2,param_3);
  return;
}


// SetBlending__FPvP9entvars_sif  @ 0007fe64
longdouble SetBlending__FPvP9entvars_sif(int param_1,int param_2,int param_3,float param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  lVar5 = (longdouble)param_4;
  if ((param_1 != 0) &&
     (iVar1 = *(int *)(param_2 + 0x128) * 0xb0 + param_1 + *(int *)(param_1 + 0xa8),
     *(int *)(iVar1 + 0x80 + param_3 * 4) != 0)) {
    iVar4 = param_3 * 4;
    if ((*(byte *)(iVar4 + 0x80 + iVar1) & 0x38) != 0) {
      if (*(float *)(iVar4 + 0x90 + iVar1) < *(float *)(iVar4 + 0x88 + iVar1)) {
        lVar5 = -lVar5;
      }
      iVar4 = param_3 * 4;
      fVar3 = *(float *)(iVar4 + iVar1 + 0x88) + 359.0;
      fVar2 = *(float *)(iVar4 + iVar1 + 0x90);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        if ((longdouble)180.0 +
            (longdouble)0.5 *
            ((longdouble)*(float *)(iVar4 + iVar1 + 0x88) +
            (longdouble)*(float *)(iVar4 + iVar1 + 0x90)) < lVar5) {
          lVar5 = lVar5 - (longdouble)360.0;
        }
        lVar6 = (longdouble)0.5 *
                ((longdouble)*(float *)(iVar1 + 0x88 + param_3 * 4) +
                (longdouble)*(float *)(iVar1 + 0x90 + param_3 * 4)) - (longdouble)180.0;
        if (0x3f < (byte)((lVar6 < lVar5 |
                           (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)) {
          lVar5 = (longdouble)360.0 + lVar5;
        }
      }
    }
    iVar4 = param_3 * 4;
    iVar4 = (int)ROUND(((longdouble)255.0 * (lVar5 - (longdouble)*(float *)(iVar4 + iVar1 + 0x88)))
                       / ((longdouble)*(float *)(iVar4 + 0x90 + iVar1) -
                         (longdouble)*(float *)(iVar4 + iVar1 + 0x88)));
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (0xff < iVar4) {
      iVar4 = 0xff;
    }
    *(char *)(param_3 + 0x140 + param_2) = (char)iVar4;
    param_3 = param_3 * 4;
    lVar5 = (longdouble)
            ((*(float *)(param_3 + 0x90 + iVar1) - *(float *)(param_3 + iVar1 + 0x88)) * 0.003921569
             * (float)iVar4 + *(float *)(param_3 + iVar1 + 0x88));
  }
  return lVar5;
}


