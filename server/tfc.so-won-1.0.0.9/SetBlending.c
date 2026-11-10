// SetBlending__14CBaseAnimatingif  @ 000c5b80
void SetBlending__14CBaseAnimatingif(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  SetBlending__FPvP9entvars_tif(uVar1,*param_1,param_2,param_3);
  return;
}


// SetBlending__FPvP9entvars_tif  @ 0009b1f0
longdouble SetBlending__FPvP9entvars_tif(int param_1,int param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  lVar5 = (longdouble)param_4;
  if ((param_1 != 0) &&
     (iVar3 = param_1 + *(int *)(param_1 + 0xa8) + *(int *)(param_2 + 0x108) * 0xb0,
     *(int *)(iVar3 + 0x80 + param_3 * 4) != 0)) {
    iVar4 = param_3 * 4;
    if ((*(byte *)(iVar4 + 0x80 + iVar3) & 0x38) != 0) {
      fVar1 = *(float *)(iVar4 + 0x90 + iVar3);
      fVar2 = *(float *)(iVar4 + 0x88 + iVar3);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        lVar5 = -lVar5;
      }
      iVar4 = param_3 * 4;
      if (*(float *)(iVar4 + iVar3 + 0x90) <= *(float *)(iVar4 + iVar3 + 0x88) + 359.0) {
        lVar6 = (longdouble)180.0 +
                (longdouble)0.5 *
                ((longdouble)*(float *)(iVar4 + iVar3 + 0x88) +
                (longdouble)*(float *)(iVar4 + iVar3 + 0x90));
        if ((byte)(lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) == 1) {
          lVar5 = lVar5 - (longdouble)360.0;
        }
        if (lVar5 < (longdouble)0.5 *
                    ((longdouble)*(float *)(iVar3 + 0x88 + param_3 * 4) +
                    (longdouble)*(float *)(iVar3 + 0x90 + param_3 * 4)) - (longdouble)180.0) {
          lVar5 = (longdouble)360.0 + lVar5;
        }
      }
    }
    iVar4 = param_3 * 4;
    iVar4 = (int)ROUND(((longdouble)255.0 * (lVar5 - (longdouble)*(float *)(iVar4 + iVar3 + 0x88)))
                       / ((longdouble)*(float *)(iVar4 + 0x90 + iVar3) -
                         (longdouble)*(float *)(iVar4 + iVar3 + 0x88)));
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (0xff < iVar4) {
      iVar4 = 0xff;
    }
    *(char *)(param_3 + 0x120 + param_2) = (char)iVar4;
    param_3 = param_3 * 4;
    lVar5 = (longdouble)
            ((*(float *)(param_3 + 0x90 + iVar3) - *(float *)(param_3 + iVar3 + 0x88)) *
             (float)iVar4 * 0.003921569 + *(float *)(param_3 + iVar3 + 0x88));
  }
  return lVar5;
}


