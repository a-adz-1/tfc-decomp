// APMeetsCriteria__FP11CBaseEntityT0  @ 0010a9e0
undefined4 APMeetsCriteria__FP11CBaseEntityT0(int param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  
  if (param_2 != (int *)0x0) {
    if ((*(int *)(param_1 + 0x120) != 0) && (*(int *)(param_1 + 0x120) != param_2[0x48])) {
      return 0;
    }
    if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x2c) != param_2[0xb])) {
      return 0;
    }
    if (*(int *)(param_1 + 0xe8) != 0) {
      piVar3 = (int *)Finditem__Fi(*(undefined4 *)(param_1 + 0xe8));
      if (piVar3 == (int *)0x0) {
        return 0;
      }
      if (*(int *)(*piVar3 + 0x178) != *(int *)(*param_2 + 0x1e8)) {
        return 0;
      }
    }
  }
  if (*(int *)(param_1 + 0x234) != 0) {
    iVar4 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x234));
    if (iVar4 == 0) {
      return 0;
    }
    if (*(int *)(iVar4 + 0x218) != 1) {
      return 0;
    }
  }
  if (*(int *)(param_1 + 0x238) != 0) {
    iVar4 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x238));
    if (iVar4 == 0) {
      return 0;
    }
    if (*(int *)(iVar4 + 0x218) != 2) {
      return 0;
    }
  }
  if (*(int *)(param_1 + 0x23c) != 0) {
    iVar4 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x23c));
    if (iVar4 == 0) {
      return 0;
    }
    if (*(int *)(iVar4 + 0x218) != 3) {
      return 0;
    }
  }
  if ((*(int *)(param_1 + 0x240) != 0) &&
     (iVar4 = AllGoalsInState__Fii(*(undefined4 *)(param_1 + 0x240),1), iVar4 == 0)) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x244) != 0) &&
     (iVar4 = AllGoalsInState__Fii(*(undefined4 *)(param_1 + 0x244),2), iVar4 == 0)) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x248) != 0) &&
     (iVar4 = AllGoalsInState__Fii(*(undefined4 *)(param_1 + 0x248),3), iVar4 == 0)) {
    return 0;
  }
  if (*(int *)(param_1 + 0x2a0) != 0) {
    piVar3 = (int *)Finditem__Fi(*(undefined4 *)(param_1 + 0x2a0));
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    if (piVar3[0x86] != 1) {
      iVar4 = *piVar3;
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar4 + 0x14)) ||
                                          NAN(*(float *)(iVar4 + 8))) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x14) == *(float *)(iVar4 + 8)) << 0xe)
                       >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar4 + 0x18)) ||
                                         NAN(*(float *)(iVar4 + 0xc))) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x18) == *(float *)(iVar4 + 0xc)) << 0xe
                               ) >> 8)) == 0x40)) {
        fVar1 = *(float *)(iVar4 + 0x10);
        fVar2 = *(float *)(iVar4 + 0x1c);
        bVar5 = (byte)(fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar5) {
        return 0;
      }
    }
  }
  if (*(int *)(param_1 + 0x2a4) != 0) {
    piVar3 = (int *)Finditem__Fi(*(undefined4 *)(param_1 + 0x2a4));
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    if (piVar3[0x86] == 1) {
      return 0;
    }
    iVar4 = *piVar3;
    bVar5 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar4 + 0x14)) || NAN(*(float *)(iVar4 + 8))
                                        ) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x14) == *(float *)(iVar4 + 8)) << 0xe)
                     >> 8)) == 0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar4 + 0x18)) ||
                                       NAN(*(float *)(iVar4 + 0xc))) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x18) == *(float *)(iVar4 + 0xc)) << 0xe)
                    >> 8)) == 0x40)) {
      fVar1 = *(float *)(iVar4 + 0x10);
      fVar2 = *(float *)(iVar4 + 0x1c);
      bVar5 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar5) {
      return 0;
    }
  }
  if ((param_2 != (int *)0x0) &&
     (((*(int *)(param_1 + 0x290) != 0 &&
       (iVar4 = HasItemFromGroup__FP11CBaseEntityi(param_2,*(undefined4 *)(param_1 + 0x290)),
       iVar4 == 0)) ||
      ((*(int *)(param_1 + 0x294) != 0 &&
       (iVar4 = HasItemFromGroup__FP11CBaseEntityi(param_2,*(undefined4 *)(param_1 + 0x294)),
       iVar4 != 0)))))) {
    return 0;
  }
  return 1;
}


