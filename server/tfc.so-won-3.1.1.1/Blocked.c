// Blocked__10CFuncTrainP11CBaseEntity  @ 000d251c
void Blocked__10CFuncTrainP11CBaseEntity(void)

{
  FUN_000d2529();
  return;
}


// Blocked__11CBaseEntityP11CBaseEntity  @ 00112bf4
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


// Blocked__12CCineMonsterP11CBaseEntity  @ 000eb5bc
void Blocked__12CCineMonsterP11CBaseEntity(void)

{
  return;
}


// Blocked__13CFuncRotatingP11CBaseEntity  @ 00089768
void Blocked__13CFuncRotatingP11CBaseEntity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  (**(code **)(*(int *)(param_2 + 0x454) + 0x38))
            (param_2,iVar1,iVar1,*(undefined4 *)(iVar1 + 0x1e0),1);
  return;
}


// Blocked__15CFuncTrackTrainP11CBaseEntity  @ 000ce9c0
void Blocked__15CFuncTrackTrainP11CBaseEntity(void)

{
  FUN_000ce9ce();
  return;
}


// Blocked__9CBaseDoorP11CBaseEntity  @ 0009e1d8
void Blocked__9CBaseDoorP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int local_c;
  
  local_c = 0;
  iVar4 = *param_1;
  (**(code **)(param_2[0x115] + 0x38))(param_2,iVar4,iVar4,*(float *)(iVar4 + 0x1e0) + 1.0,1);
  iVar4 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"detpack");
  if (iVar4 == 0) {
    Remove__8CDetpack(param_2);
  }
  else {
    iVar4 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"building_dispenser");
    if (iVar4 == 0) {
      Remove__12CTFDispenser(param_2);
    }
    else {
      iVar4 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"building_sentrygun");
      if (iVar4 == 0) {
        Remove__12CTFSentrygun(param_2);
      }
      else {
        iVar4 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"building_sentrygun_base");
        if (iVar4 == 0) {
          Remove__16CTFSentrygunBase(param_2);
        }
        else {
          iVar4 = (**(code **)(param_2[0x115] + 0x2c))(param_2);
          if ((iVar4 == 2) && (*(int *)(*param_2 + 0x20c) == 8)) {
            iVar4 = *param_1;
            (**(code **)(param_2[0x115] + 0x38))
                      (param_2,iVar4,iVar4,*(float *)(iVar4 + 0x1e0) + 5.0,1);
          }
          if (0.0 <= (float)param_1[0x120]) {
            if (param_1[0x11d] == 3) {
              DoorGoUp__9CBaseDoor(param_1);
            }
            else {
              DoorGoDown__9CBaseDoor(param_1);
            }
          }
          fVar1 = *gpGlobals;
          fVar2 = (float)param_1[0x149];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            param_1[0x149] = (int)(fVar1 + 0.3);
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(*param_1 + 0x208),6,
                       *(int *)(*param_1 + 0x1ec) + (int)gpGlobals[0x26],0,0,0x20,100);
          }
          if (*(int *)(*param_1 + 0x1cc) != 0) {
LAB_0009e5fc:
            do {
              local_c = (*DAT_0019f6d8)(local_c,"targetname",
                                        *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26]);
              piVar5 = (int *)(local_c + 0x80);
              piVar6 = piVar5;
              if (local_c == 0) {
                piVar6 = (int *)0x0;
              }
            } while (piVar6 == (int *)*param_1);
            bVar7 = false;
            if ((local_c == 0) || (iVar4 = (*DAT_0019f7b8)(local_c), iVar4 == 0)) {
              bVar7 = true;
            }
            if (!bVar7) {
              piVar6 = piVar5;
              if (local_c == 0) {
                piVar6 = (int *)0x0;
              }
              iVar4 = strcmp((char *)(*piVar6 + (int)gpGlobals[0x26]),"func_door");
              if (iVar4 != 0) goto code_r0x0009e41f;
              goto LAB_0009e452;
            }
          }
        }
      }
    }
  }
  return;
code_r0x0009e41f:
  piVar6 = piVar5;
  if (local_c == 0) {
    piVar6 = (int *)0x0;
  }
  iVar4 = strcmp((char *)(*piVar6 + (int)gpGlobals[0x26]),"func_door_rotating");
  if (iVar4 == 0) {
LAB_0009e452:
    piVar6 = piVar5;
    if (local_c == 0) {
      piVar6 = (int *)0x0;
    }
    piVar6 = (int *)GetClassPtr__H1Z9CBaseDoor_PX01_PX01(piVar6);
    if (0.0 <= (float)piVar6[0x120]) {
      iVar4 = *piVar6;
      bVar7 = false;
      iVar3 = *param_1;
      if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x20)) ||
                                          NAN(*(float *)(iVar4 + 0x20))) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x20) == *(float *)(iVar4 + 0x20)) <<
                                0xe) >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x24)) ||
                                         NAN(*(float *)(iVar4 + 0x24))) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x24) == *(float *)(iVar4 + 0x24)) <<
                               0xe) >> 8)) == 0x40)) {
        fVar1 = *(float *)(iVar4 + 0x28);
        fVar2 = *(float *)(iVar3 + 0x28);
        bVar7 = (byte)(fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar7) {
        bVar7 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x20)) ||
                                            NAN(*(float *)(iVar4 + 0x5c))) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x20) == *(float *)(iVar4 + 0x5c)) <<
                                  0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x24)) ||
                                           NAN(*(float *)(iVar4 + 0x60))) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x24) == *(float *)(iVar4 + 0x60)) <<
                                 0xe) >> 8)) == 0x40)) {
          fVar1 = *(float *)(iVar4 + 100);
          fVar2 = *(float *)(iVar3 + 0x28);
          bVar7 = (byte)(fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
        }
        if (bVar7) {
          if (local_c == 0) {
            piVar5 = (int *)0x0;
          }
          iVar4 = strcmp((char *)(*piVar5 + (int)gpGlobals[0x26]),"func_door");
          if (iVar4 == 0) {
            iVar4 = *piVar6;
            iVar3 = *param_1;
            *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar3 + 8);
            *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
            *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
            iVar4 = *piVar6;
            *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
            *(undefined4 *)(iVar4 + 0x24) = DAT_0019f664;
            *(undefined4 *)(iVar4 + 0x28) = DAT_0019f668;
          }
          else {
            iVar4 = *piVar6;
            iVar3 = *param_1;
            *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar3 + 0x50);
            *(undefined4 *)(iVar4 + 0x54) = *(undefined4 *)(iVar3 + 0x54);
            *(undefined4 *)(iVar4 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
            iVar4 = *piVar6;
            *(undefined4 *)(iVar4 + 0x5c) = g_vecZero;
            *(undefined4 *)(iVar4 + 0x60) = DAT_0019f664;
            *(undefined4 *)(iVar4 + 100) = DAT_0019f668;
          }
        }
      }
      if (piVar6[0x11d] == 3) {
        DoorGoUp__9CBaseDoor(piVar6);
      }
      else {
        DoorGoDown__9CBaseDoor(piVar6);
      }
    }
  }
  goto LAB_0009e5fc;
}


// Blocked__9CFuncPlatP11CBaseEntity  @ 000cda28
void Blocked__9CFuncPlatP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  code *pcVar2;
  
  (*DAT_0019f794)(2,"%s Blocked by %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                  *(int *)*param_2 + *(int *)(gpGlobals + 0x98));
  (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,*param_1,0x3f800000,1);
  iVar1 = *(int *)(*param_1 + 0x1e8);
  if (iVar1 != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,iVar1 + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
  }
  if (param_1[0x11d] == 2) {
    pcVar2 = *(code **)(param_1[0x115] + 0x114);
  }
  else {
    if (param_1[0x11d] != 3) {
      return;
    }
    pcVar2 = *(code **)(param_1[0x115] + 0x110);
  }
  (*pcVar2)(param_1);
  return;
}


// Blocked__9CPendulumP11CBaseEntity  @ 000894f0
void Blocked__9CPendulumP11CBaseEntity(int param_1)

{
  *(undefined4 *)(param_1 + 0x460) = *gpGlobals;
  return;
}


