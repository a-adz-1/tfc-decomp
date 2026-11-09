// OnControls__11CBaseEntityP9entvars_t  @ 0010e3e0
undefined4 OnControls__11CBaseEntityP9entvars_t(void)

{
  return 0;
}


// OnControls__15CFuncTrackTrainP9entvars_t  @ 000d3bb0
undefined4 OnControls__15CFuncTrackTrainP9entvars_t(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar2 = *param_1;
  fVar3 = *(float *)(param_2 + 8) - *(float *)(iVar2 + 8);
  fVar1 = *(float *)(param_2 + 0xc) - *(float *)(iVar2 + 0xc);
  fVar4 = *(float *)(param_2 + 0x10) - *(float *)(iVar2 + 0x10);
  if ((*(byte *)(iVar2 + 0x180) & 2) == 0) {
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    fVar6 = fVar4 * *(float *)(gpGlobals + 0x30) +
            fVar1 * *(float *)(gpGlobals + 0x2c) + fVar3 * *(float *)(gpGlobals + 0x28);
    fVar5 = -(fVar4 * *(float *)(gpGlobals + 0x48) +
             fVar1 * *(float *)(gpGlobals + 0x44) + fVar3 * *(float *)(gpGlobals + 0x40));
    fVar3 = fVar4 * *(float *)(gpGlobals + 0x3c) +
            fVar1 * *(float *)(gpGlobals + 0x38) + fVar3 * *(float *)(gpGlobals + 0x34);
    if (((((float)param_1[0xf9] <= fVar6) && ((float)param_1[0xfa] <= fVar5)) &&
        ((float)param_1[0xfb] <= fVar3)) &&
       (((fVar1 = (float)param_1[0xfc],
         (byte)((fVar6 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar6) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar6 == fVar1) << 0xe) >> 8)) - 1) < 0x40 &&
         (fVar1 = (float)param_1[0xfd],
         (byte)((fVar5 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar5) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar5 == fVar1) << 0xe) >> 8)) - 1) < 0x40)) &&
        (fVar1 = (float)param_1[0xfe],
        (byte)((fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40)))) {
      return 1;
    }
  }
  return 0;
}


// OnControls__9CFuncTankP9entvars_t  @ 000b44d0
undefined4 OnControls__9CFuncTankP9entvars_t(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if (((*(byte *)(*param_1 + 0x180) & 0x20) != 0) &&
     (fVar1 = (float)param_1[0xf5] - *(float *)(param_2 + 8),
     fVar3 = (float)param_1[0xf6] - *(float *)(param_2 + 0xc),
     fVar2 = (float)param_1[0xf7] - *(float *)(param_2 + 0x10),
     SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) < 30.0)) {
    return 1;
  }
  return 0;
}


