// tfgoal_timer_tick__11CBaseEntity  @ 000ffdf8
void tfgoal_timer_tick__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  
  if (param_1[0x86] != 3) {
    fVar1 = *gpGlobals;
    if ((byte)((cb_prematch_time < fVar1 |
                (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      iVar2 = APMeetsCriteria__FP11CBaseEntityT0(param_1,0);
      if (iVar2 != 0) {
        DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,0,1);
        return;
      }
      param_1[3] = -0x10000;
      param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
      iVar2 = *param_1;
      pfVar3 = gpGlobals;
    }
    else {
      param_1[3] = -0x10000;
      param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
      iVar2 = *param_1;
      pfVar3 = &cb_prematch_time;
    }
    *(float *)(iVar2 + 0x104) = *pfVar3 + (float)param_1[0x93];
  }
  return;
}


// tfgoal_touch__11CBaseEntityP11CBaseEntity  @ 000fdd70
void tfgoal_touch__11CBaseEntityP11CBaseEntity(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  if ((((cb_prematch_time <= *gpGlobals) && (((*(byte *)(param_1 + 0x220) ^ 1) & 1) == 0)) &&
      (iVar3 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x28))(param_2), iVar3 == 2)) &&
     ((iVar3 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x88))(param_2), iVar3 != 0 &&
      (*(int *)(param_1 + 0x218) != 1)))) {
    if (CTF_Map != 0) {
      if ((*(int *)(param_1 + 0x210) == 3) && (*(int *)(param_2 + 0x120) == 1)) {
        piVar4 = (int *)Finditem__Fi(1);
        if (piVar4[0x86] == 1) {
          return;
        }
        iVar3 = *piVar4;
        bVar5 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) ||
                                            NAN(*(float *)(iVar3 + 8))) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) <<
                                  0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                           NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) <<
                                 0xe) >> 8)) == 0x40)) {
          fVar1 = *(float *)(iVar3 + 0x10);
          fVar2 = *(float *)(iVar3 + 0x1c);
          bVar5 = (byte)(fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
        }
        if (!bVar5) {
          return;
        }
      }
      if ((*(int *)(param_1 + 0x210) == 4) && (*(int *)(param_2 + 0x120) == 2)) {
        piVar4 = (int *)Finditem__Fi(2);
        if (piVar4[0x86] == 1) {
          return;
        }
        iVar3 = *piVar4;
        bVar5 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) ||
                                            NAN(*(float *)(iVar3 + 8))) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) <<
                                  0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                           NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) <<
                                 0xe) >> 8)) == 0x40)) {
          fVar1 = *(float *)(iVar3 + 0x10);
          fVar2 = *(float *)(iVar3 + 0x1c);
          bVar5 = (byte)(fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
        }
        if (!bVar5) {
          return;
        }
      }
    }
    ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_1);
  }
  return;
}


