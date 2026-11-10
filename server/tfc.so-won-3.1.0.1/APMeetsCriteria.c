// APMeetsCriteria__FP11CBaseEntityT0  @ 000fc250
undefined4 APMeetsCriteria__FP11CBaseEntityT0(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  if ((param_2 != (int *)0x0) && (iVar3 = (**(code **)(param_2[0xf5] + 0x28))(param_2), iVar3 == 2))
  {
    if ((param_1[0x48] != 0) && (param_1[0x48] != param_2[0x48])) {
      return 0;
    }
    if ((*(int *)(*param_1 + 0x20c) != 0) &&
       (*(int *)(*param_1 + 0x20c) != *(int *)(*param_2 + 0x20c))) {
      return 0;
    }
    if (param_1[0x3a] != 0) {
      piVar4 = (int *)Finditem__Fi(param_1[0x3a]);
      if (piVar4 == (int *)0x0) {
        return 0;
      }
      if (*(int *)(*piVar4 + 0x198) != *(int *)(*param_2 + 0x208)) {
        return 0;
      }
    }
  }
  if (param_1[0x8d] != 0) {
    iVar3 = Findgoal__Fi(param_1[0x8d]);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(iVar3 + 0x218) != 1) {
      return 0;
    }
  }
  if (param_1[0x8e] != 0) {
    iVar3 = Findgoal__Fi(param_1[0x8e]);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(iVar3 + 0x218) != 2) {
      return 0;
    }
  }
  if (param_1[0x8f] != 0) {
    iVar3 = Findgoal__Fi(param_1[0x8f]);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(iVar3 + 0x218) != 3) {
      return 0;
    }
  }
  if ((param_1[0x90] != 0) && (iVar3 = AllGoalsInState__Fii(param_1[0x90],1), iVar3 == 0)) {
    return 0;
  }
  if ((param_1[0x91] != 0) && (iVar3 = AllGoalsInState__Fii(param_1[0x91],2), iVar3 == 0)) {
    return 0;
  }
  if ((param_1[0x92] != 0) && (iVar3 = AllGoalsInState__Fii(param_1[0x92],3), iVar3 == 0)) {
    return 0;
  }
  if (param_1[0xa8] != 0) {
    piVar4 = (int *)Finditem__Fi(param_1[0xa8]);
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    if (piVar4[0x86] != 1) {
      iVar3 = *piVar4;
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) ||
                                          NAN(*(float *)(iVar3 + 8))) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) << 0xe)
                       >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                         NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) << 0xe
                               ) >> 8)) == 0x40)) {
        fVar1 = *(float *)(iVar3 + 0x10);
        fVar2 = *(float *)(iVar3 + 0x1c);
        bVar5 = (byte)(fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar5) {
        return 0;
      }
    }
  }
  if (param_1[0xa9] != 0) {
    piVar4 = (int *)Finditem__Fi(param_1[0xa9]);
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    if (piVar4[0x86] == 1) {
      return 0;
    }
    iVar3 = *piVar4;
    bVar5 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) || NAN(*(float *)(iVar3 + 8))
                                        ) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) << 0xe)
                     >> 8)) == 0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                       NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) << 0xe)
                    >> 8)) == 0x40)) {
      fVar1 = *(float *)(iVar3 + 0x10);
      fVar2 = *(float *)(iVar3 + 0x1c);
      bVar5 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar5) {
      return 0;
    }
  }
  if (((param_2 != (int *)0x0) && (iVar3 = (**(code **)(param_2[0xf5] + 0x28))(param_2), iVar3 == 2)
      ) && (((param_1[0xa4] != 0 &&
             (iVar3 = HasItemFromGroup__FP11CBaseEntityi(param_2,param_1[0xa4]), iVar3 == 0)) ||
            ((param_1[0xa5] != 0 &&
             (iVar3 = HasItemFromGroup__FP11CBaseEntityi(param_2,param_1[0xa5]), iVar3 != 0)))))) {
    return 0;
  }
  return 1;
}


