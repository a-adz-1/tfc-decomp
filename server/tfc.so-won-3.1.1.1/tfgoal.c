// tfgoal_timer_tick__11CBaseEntity  @ 00111ad4
void tfgoal_timer_tick__11CBaseEntity(int *param_1)

{
  int iVar1;
  float *pfVar2;
  
  if (param_1[0x86] != 3) {
    if (cb_prematch_time <= *gpGlobals) {
      iVar1 = APMeetsCriteria__FP11CBaseEntityT0(param_1,0);
      if (iVar1 != 0) {
        DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,0,1);
        FUN_00111b78();
        return;
      }
      param_1[3] = -0x10000;
      param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
      pfVar2 = gpGlobals;
    }
    else {
      param_1[3] = -0x10000;
      param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
      pfVar2 = &cb_prematch_time;
    }
    *(float *)(*param_1 + 0x104) = *pfVar2 + (float)param_1[0x95];
  }
  return;
}


// tfgoal_touch__11CBaseEntityP11CBaseEntity  @ 0010f290
void tfgoal_touch__11CBaseEntityP11CBaseEntity(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  
  fVar1 = *gpGlobals;
  if ((byte)(fVar1 < cb_prematch_time |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) == 1) {
    return;
  }
  if (((*(byte *)(param_1 + 0x228) ^ 1) & 1) != 0) {
    return;
  }
  iVar3 = (**(code **)(*(int *)(param_2 + 0x454) + 0x2c))(param_2);
  if (iVar3 != 2) {
    return;
  }
  iVar3 = (**(code **)(*(int *)(param_2 + 0x454) + 0x8c))(param_2);
  if (iVar3 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x218) == 1) {
    return;
  }
  if (CTF_Map != 0) {
    if ((*(int *)(param_1 + 0x210) == 3) && (*(int *)(param_2 + 0x120) == 1)) {
      piVar5 = (int *)0x0;
      do {
        piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
        if (piVar5 == (int *)0x0) {
          (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",1);
          piVar5 = (int *)0x0;
          break;
        }
      } while (piVar5[0x84] != 1);
      if (piVar5[0x86] == 1) {
        return;
      }
      iVar3 = *piVar5;
      bVar4 = false;
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
        bVar4 = (byte)(fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (!bVar4) {
        return;
      }
    }
    if ((*(int *)(param_1 + 0x210) == 4) && (*(int *)(param_2 + 0x120) == 2)) {
      piVar5 = (int *)0x0;
      do {
        piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
        if (piVar5 == (int *)0x0) {
          (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",2);
          piVar5 = (int *)0x0;
          break;
        }
      } while (piVar5[0x84] != 2);
      if (piVar5[0x86] == 1) {
        return;
      }
      iVar3 = *piVar5;
      bVar4 = false;
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
        bVar4 = (byte)(fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (!bVar4) {
        return;
      }
    }
  }
  iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_1);
  if (iVar3 != 0) {
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,param_2,1);
  }
  return;
}


