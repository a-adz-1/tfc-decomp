// SetBlending__14CBaseAnimatingif  @ 000c1d2c
void SetBlending__14CBaseAnimatingif(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  SetBlending__FPvP9entvars_sif(uVar1,*param_1,param_2,param_3);
  return;
}


// SetBlending__FPvP9entvars_sif  @ 00087658
longdouble SetBlending__FPvP9entvars_sif(int param_1,int param_2,int param_3,float param_4)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  int local_20;
  
  lVar5 = (longdouble)param_4;
  if (param_1 != 0) {
    iVar4 = *(int *)(param_2 + 0x128) * 0xb0 + param_1 + *(int *)(param_1 + 0xa8);
    iVar1 = param_3 * 4;
    uVar3 = *(uint *)(iVar1 + 0x80 + iVar4);
    if (uVar3 != 0) {
      if ((uVar3 & 0x38) != 0) {
        lVar6 = (longdouble)*(float *)(iVar1 + 0x90 + iVar4);
        lVar7 = (longdouble)*(float *)(iVar1 + 0x88 + iVar4);
        if (0x3f < (byte)((lVar7 < lVar6 |
                           (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) - 1)) {
          lVar5 = -lVar5;
        }
        lVar8 = (longdouble)359.0 + lVar7;
        if ((byte)(lVar8 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar6)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar8 == lVar6) << 0xe) >> 8)) != 1) {
          lVar7 = (longdouble)0.5 * (lVar7 + lVar6);
          lVar6 = lVar7 + (longdouble)180.0;
          if (0x3f < (byte)((lVar5 < lVar6 |
                             (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar6)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(lVar5 == lVar6) << 0xe) >> 8)) - 1)) {
            lVar5 = lVar5 - (longdouble)360.0;
          }
          lVar7 = lVar7 - (longdouble)180.0;
          if (0x3f < (byte)((lVar7 < lVar5 |
                             (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar5)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(lVar7 == lVar5) << 0xe) >> 8)) - 1)) {
            lVar5 = (longdouble)360.0 + lVar5;
          }
        }
      }
      lVar6 = (longdouble)*(float *)(iVar1 + iVar4 + 0x88);
      local_20 = (int)ROUND(((longdouble)255.0 * (lVar5 - lVar6)) /
                            ((longdouble)*(float *)(iVar1 + iVar4 + 0x90) - lVar6));
      if (local_20 < 0) {
        local_20 = 0;
      }
      if (0xff < local_20) {
        local_20 = 0xff;
      }
      *(undefined1 *)(param_3 + 0x140 + param_2) = (undefined1)local_20;
      fVar2 = *(float *)(iVar1 + iVar4 + 0x88);
      lVar5 = (longdouble)
              ((*(float *)(iVar1 + iVar4 + 0x90) - fVar2) * 0.003921569 * (float)local_20 + fVar2);
    }
  }
  return lVar5;
}


