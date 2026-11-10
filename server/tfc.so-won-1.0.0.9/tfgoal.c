// tfgoal_timer_tick__11CBaseEntity  @ 0010dbe0
void tfgoal_timer_tick__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (param_1[0x86] != 3) {
    iVar1 = APMeetsCriteria__FP11CBaseEntityT0(param_1,0);
    if (iVar1 == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0x93];
    }
    else {
      DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,0,1);
    }
  }
  return;
}


// tfgoal_touch__11CBaseEntityP11CBaseEntity  @ 0010c1e0
void tfgoal_touch__11CBaseEntityP11CBaseEntity(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  if ((((cb_prematch_time <= *gpGlobals) && (((*(byte *)(param_1 + 0x220) ^ 1) & 1) == 0)) &&
      (iVar3 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x28))(param_2), iVar3 == 2)) &&
     (*(int *)(param_1 + 0x218) != 1)) {
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


