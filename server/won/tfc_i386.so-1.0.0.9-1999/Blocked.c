// Blocked__10CFuncTrainP11CBaseEntity  @ 000d2120
void Blocked__10CFuncTrainP11CBaseEntity(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0xfb];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    param_1[0xfb] = (int)(*gpGlobals + 0.5);
    iVar3 = *param_1;
    (**(code **)(*(int *)(param_2 + 0x3c8) + 0x34))
              (param_2,iVar3,iVar3,*(undefined4 *)(iVar3 + 0x1c0),1);
  }
  return;
}


// Blocked__11CBaseEntityP11CBaseEntity  @ 0010e180
void Blocked__11CBaseEntityP11CBaseEntity(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (*(short *)(param_1 + 0x26) != 0) {
    if (*(short *)(param_1 + 0x26) < 1) {
      pcVar1 = *(code **)(param_1 + 0x28);
    }
    else {
      pcVar1 = *(code **)(*(int *)(*(short *)(param_1 + 0x28) + param_1) + -4 +
                         *(short *)(param_1 + 0x26) * 4);
    }
    (*pcVar1)(*(short *)(param_1 + 0x24) + param_1,param_2);
  }
  return;
}


// Blocked__12CCineMonsterP11CBaseEntity  @ 000e7190
void Blocked__12CCineMonsterP11CBaseEntity(void)

{
  return;
}


// Blocked__13CFuncRotatingP11CBaseEntity  @ 0009ca50
void Blocked__13CFuncRotatingP11CBaseEntity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  (**(code **)(*(int *)(param_2 + 0x3c8) + 0x34))
            (param_2,iVar1,iVar1,*(undefined4 *)(iVar1 + 0x1c0),1);
  return;
}


// Blocked__15CFuncTrackTrainP11CBaseEntity  @ 000d2da0
void Blocked__15CFuncTrackTrainP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar2 = *param_2;
  if ((*(byte *)(iVar2 + 0x185) & 2) != 0) {
    if (*(int *)(iVar2 + 0x17c) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x17c) + 0xdc;
    }
    if (iVar3 == *param_1) {
      fVar1 = ABS(*(float *)(iVar3 + 0x1d8));
      if ((byte)(50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 50.0) << 0xe) >> 8)) == 1) {
        fVar1 = 50.0;
      }
      if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x28)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x28) == 0.0) << 0xe) >> 8)) != 0x40) {
        return;
      }
      *(float *)(iVar2 + 0x28) = fVar1 + *(float *)(iVar2 + 0x28);
      return;
    }
  }
  local_20 = *(float *)(iVar2 + 8) - *(float *)(*param_1 + 8);
  local_1c = *(float *)(iVar2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar1 = *(float *)(iVar2 + 0x10) - *(float *)(*param_1 + 0x10);
  local_18 = SQRT(fVar1 * fVar1 + local_1c * local_1c + local_20 * local_20);
  if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_20 = 0.0;
    local_1c = 0.0;
    local_18 = 1.0;
  }
  else {
    local_18 = 1.0 / local_18;
    local_20 = local_18 * local_20;
    local_1c = local_18 * local_1c;
    local_18 = local_18 * fVar1;
  }
  fVar1 = *(float *)(*param_1 + 0x1c0);
  *(float *)(iVar2 + 0x20) = fVar1 * local_20;
  *(float *)(iVar2 + 0x24) = fVar1 * local_1c;
  *(float *)(iVar2 + 0x28) = fVar1 * local_18;
  (*DAT_001755b4)(2,"TRAIN(%s): Blocked by %s (dmg:%.2f)\n",
                  *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98),
                  *(int *)*param_2 + *(int *)(gpGlobals + 0x98),(double)*(float *)(*param_1 + 0x1c0)
                 );
  iVar2 = *param_1;
  if (0.0 < *(float *)(iVar2 + 0x1c0)) {
    (**(code **)(param_2[0xf2] + 0x34))(param_2,iVar2,iVar2,*(undefined4 *)(iVar2 + 0x1c0),1);
  }
  return;
}


// Blocked__9CBaseDoorP11CBaseEntity  @ 000aa4b0
void Blocked__9CBaseDoorP11CBaseEntity(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  int local_8;
  
  local_8 = 0;
  iVar6 = *param_1;
  fVar1 = *(float *)(iVar6 + 0x1c0);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    (**(code **)(*(int *)(param_2 + 0x3c8) + 0x34))
              (param_2,iVar6,iVar6,*(undefined4 *)(iVar6 + 0x1c0),1);
  }
  fVar1 = (float)param_1[0xfd];
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (param_1[0xfa] == 3) {
      DoorGoUp__9CBaseDoor(param_1);
    }
    else {
      DoorGoDown__9CBaseDoor(param_1);
    }
  }
  if (*(int *)(*param_1 + 0x1ac) != 0) {
LAB_000aa550:
    do {
      local_8 = (*DAT_001754f8)(local_8,"targetname",
                                *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98));
      if (local_8 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = local_8 + 0xdc;
      }
    } while (iVar6 == *param_1);
    bVar7 = false;
    if ((local_8 == 0) || (iVar6 = (*DAT_001755d8)(local_8), iVar6 == 0)) {
      bVar7 = true;
    }
    if (!bVar7) {
      if (local_8 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)(local_8 + 0xdc);
      }
      iVar6 = strcmp((char *)(*piVar4 + *(int *)(gpGlobals + 0x98)),"func_door");
      if (iVar6 != 0) goto code_r0x000aa609;
      goto LAB_000aa64d;
    }
  }
  return;
code_r0x000aa609:
  if (local_8 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(local_8 + 0xdc);
  }
  iVar6 = strcmp((char *)(*piVar4 + *(int *)(gpGlobals + 0x98)),"func_door_rotating");
  if (iVar6 == 0) {
LAB_000aa64d:
    if (local_8 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = local_8 + 0xdc;
    }
    piVar4 = (int *)GetClassPtr__H1Z9CBaseDoor_PX01_PX01(iVar6);
    fVar1 = (float)piVar4[0xfd];
    if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
      iVar6 = *piVar4;
      iVar3 = *param_1;
      bVar7 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x20)) ||
                                          NAN(*(float *)(iVar6 + 0x20))) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x20) == *(float *)(iVar6 + 0x20)) <<
                                0xe) >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x24)) ||
                                         NAN(*(float *)(iVar6 + 0x24))) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x24) == *(float *)(iVar6 + 0x24)) <<
                               0xe) >> 8)) == 0x40)) {
        fVar1 = *(float *)(iVar6 + 0x28);
        fVar2 = *(float *)(iVar3 + 0x28);
        bVar7 = (byte)(fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar7) {
        iVar6 = *piVar4;
        iVar3 = *param_1;
        bVar7 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x20)) ||
                                            NAN(*(float *)(iVar6 + 0x5c))) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x20) == *(float *)(iVar6 + 0x5c)) <<
                                  0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x24)) ||
                                           NAN(*(float *)(iVar6 + 0x60))) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x24) == *(float *)(iVar6 + 0x60)) <<
                                 0xe) >> 8)) == 0x40)) {
          fVar1 = *(float *)(iVar6 + 100);
          fVar2 = *(float *)(iVar3 + 0x28);
          bVar7 = (byte)(fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
        }
        if (bVar7) {
          if (local_8 == 0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = (int *)(local_8 + 0xdc);
          }
          iVar6 = strcmp((char *)(*piVar5 + *(int *)(gpGlobals + 0x98)),"func_door");
          if (iVar6 == 0) {
            iVar6 = *piVar4;
            iVar3 = *param_1;
            *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar3 + 8);
            *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
            *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
            iVar6 = *piVar4;
            *(undefined4 *)(iVar6 + 0x20) = g_vecZero;
            *(undefined4 *)(iVar6 + 0x24) = DAT_00175484;
            *(undefined4 *)(iVar6 + 0x28) = DAT_00175488;
          }
          else {
            iVar6 = *piVar4;
            iVar3 = *param_1;
            *(undefined4 *)(iVar6 + 0x50) = *(undefined4 *)(iVar3 + 0x50);
            *(undefined4 *)(iVar6 + 0x54) = *(undefined4 *)(iVar3 + 0x54);
            *(undefined4 *)(iVar6 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
            iVar6 = *piVar4;
            *(undefined4 *)(iVar6 + 0x5c) = g_vecZero;
            *(undefined4 *)(iVar6 + 0x60) = DAT_00175484;
            *(undefined4 *)(iVar6 + 100) = DAT_00175488;
          }
        }
      }
      if (piVar4[0xfa] == 3) {
        DoorGoUp__9CBaseDoor(piVar4);
      }
      else {
        DoorGoDown__9CBaseDoor(piVar4);
      }
    }
  }
  goto LAB_000aa550;
}


// Blocked__9CFuncPlatP11CBaseEntity  @ 000d1bd0
void Blocked__9CFuncPlatP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  code *pcVar2;
  
  (*DAT_001755b4)(2,"%s Blocked by %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                  *(int *)*param_2 + *(int *)(gpGlobals + 0x98));
  (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*param_1,0x3f800000,1);
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1c8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),6,*(int *)(iVar1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
  }
  if (param_1[0xfa] == 2) {
    pcVar2 = *(code **)(param_1[0xf2] + 0x10c);
  }
  else {
    if (param_1[0xfa] != 3) {
      return;
    }
    pcVar2 = *(code **)(param_1[0xf2] + 0x108);
  }
  (*pcVar2)(param_1);
  return;
}


// Blocked__9CPendulumP11CBaseEntity  @ 0009cf40
void Blocked__9CPendulumP11CBaseEntity(int param_1)

{
  *(undefined4 *)(param_1 + 0x3d4) = *gpGlobals;
  return;
}


