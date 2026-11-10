// Blocked__10CFuncTrainP11CBaseEntity  @ 000c33f4
void Blocked__10CFuncTrainP11CBaseEntity(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0xfe];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    param_1[0xfe] = (int)(*gpGlobals + 0.5);
    iVar3 = *param_1;
    (**(code **)(*(int *)(param_2 + 0x3d4) + 0x34))
              (param_2,iVar3,iVar3,*(undefined4 *)(iVar3 + 0x1e0),1);
  }
  return;
}


// Blocked__11CBaseEntityP11CBaseEntity  @ 00100420
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


// Blocked__12CCineMonsterP11CBaseEntity  @ 000dc080
void Blocked__12CCineMonsterP11CBaseEntity(void)

{
  return;
}


// Blocked__13CFuncRotatingP11CBaseEntity  @ 00081b6c
void Blocked__13CFuncRotatingP11CBaseEntity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  (**(code **)(*(int *)(param_2 + 0x3d4) + 0x34))
            (param_2,iVar1,iVar1,*(undefined4 *)(iVar1 + 0x1e0),1);
  return;
}


// Blocked__15CFuncTrackTrainP11CBaseEntity  @ 000c4138
void Blocked__15CFuncTrackTrainP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  iVar3 = *param_2;
  if ((*(byte *)(iVar3 + 0x1a5) & 2) != 0) {
    iVar4 = *(int *)(iVar3 + 0x19c) + 0x80;
    if (*(int *)(iVar3 + 0x19c) == 0) {
      iVar4 = 0;
    }
    if (iVar4 == *param_1) {
      fVar2 = ABS(*(float *)(iVar4 + 0x1f8));
      if (50.0 < fVar2) {
        fVar2 = 50.0;
      }
      fVar1 = *(float *)(iVar3 + 0x28);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        return;
      }
      *(float *)(iVar3 + 0x28) = fVar1 + fVar2;
      return;
    }
  }
  fStack_1c = *(float *)(iVar3 + 8) - *(float *)(*param_1 + 8);
  fStack_18 = *(float *)(iVar3 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar2 = *(float *)(iVar3 + 0x10) - *(float *)(*param_1 + 0x10);
  fStack_14 = SQRT(fVar2 * fVar2 + fStack_18 * fStack_18 + fStack_1c * fStack_1c);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_14) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_14 == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_1c = 0.0;
    fStack_18 = 0.0;
    fStack_14 = 1.0;
  }
  else {
    fStack_14 = 1.0 / fStack_14;
    fStack_1c = fStack_14 * fStack_1c;
    fStack_18 = fStack_14 * fStack_18;
    fStack_14 = fStack_14 * fVar2;
  }
  fVar2 = *(float *)(*param_1 + 0x1e0);
  *(float *)(iVar3 + 0x20) = fVar2 * fStack_1c;
  *(float *)(iVar3 + 0x24) = fVar2 * fStack_18;
  *(float *)(iVar3 + 0x28) = fVar2 * fStack_14;
  (*DAT_001a7f34)(2,"TRAIN(%s): Blocked by %s (dmg:%.2f)\n",
                  *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                  *(int *)*param_2 + *(int *)(gpGlobals + 0x98),(double)*(float *)(*param_1 + 0x1e0)
                 );
  iVar3 = *param_1;
  if (*(float *)(iVar3 + 0x1e0) <= 0.0) {
    return;
  }
  (**(code **)(param_2[0xf5] + 0x34))(param_2,iVar3,iVar3,*(undefined4 *)(iVar3 + 0x1e0),1);
  FUN_000c4370();
  return;
}


// Blocked__9CBaseDoorP11CBaseEntity  @ 00094700
void Blocked__9CBaseDoorP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int local_8;
  
  local_8 = 0;
  iVar4 = *param_1;
  (**(code **)(param_2[0xf5] + 0x34))(param_2,iVar4,iVar4,*(float *)(iVar4 + 0x1e0) + 1.0,1);
  iVar4 = (**(code **)(param_2[0xf5] + 0x28))(param_2);
  if ((iVar4 == 2) && (*(int *)(*param_2 + 0x20c) == 8)) {
    iVar4 = *param_1;
    (**(code **)(param_2[0xf5] + 0x34))(param_2,iVar4,iVar4,*(float *)(iVar4 + 0x1e0) + 5.0,1);
  }
  if (0.0 <= (float)param_1[0x100]) {
    if (param_1[0xfd] == 3) {
      DoorGoUp__9CBaseDoor(param_1);
    }
    else {
      DoorGoDown__9CBaseDoor(param_1);
    }
  }
  if ((float)param_1[0x129] <= *gpGlobals) {
    param_1[0x129] = (int)(*gpGlobals + 0.3);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,*(int *)(*param_1 + 0x1ec) + (int)gpGlobals[0x26]
               ,0,0,0x20,100);
  }
  if (*(int *)(*param_1 + 0x1cc) != 0) {
LAB_0009487c:
    do {
      local_8 = (*DAT_001a7e78)(local_8,"targetname",
                                *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26]);
      iVar4 = local_8 + 0x80;
      if (local_8 == 0) {
        iVar4 = 0;
      }
    } while (iVar4 == *param_1);
    bVar7 = false;
    if ((local_8 == 0) || (iVar4 = (*DAT_001a7f58)(local_8), iVar4 == 0)) {
      bVar7 = true;
    }
    if (!bVar7) {
      piVar5 = (int *)(local_8 + 0x80);
      if (local_8 == 0) {
        piVar5 = (int *)0x0;
      }
      iVar4 = strcmp((char *)(*piVar5 + (int)gpGlobals[0x26]),"func_door");
      if (iVar4 != 0) goto code_r0x0009494b;
      goto LAB_00094983;
    }
  }
  return;
code_r0x0009494b:
  piVar5 = (int *)(local_8 + 0x80);
  if (local_8 == 0) {
    piVar5 = (int *)0x0;
  }
  iVar4 = strcmp((char *)(*piVar5 + (int)gpGlobals[0x26]),"func_door_rotating");
  if (iVar4 == 0) {
LAB_00094983:
    iVar4 = local_8 + 0x80;
    if (local_8 == 0) {
      iVar4 = 0;
    }
    piVar5 = (int *)GetClassPtr__H1Z9CBaseDoor_PX01_PX01(iVar4);
    if (0.0 <= (float)piVar5[0x100]) {
      iVar4 = *piVar5;
      iVar3 = *param_1;
      bVar7 = false;
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
        iVar4 = *piVar5;
        iVar3 = *param_1;
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
          piVar6 = (int *)(local_8 + 0x80);
          if (local_8 == 0) {
            piVar6 = (int *)0x0;
          }
          iVar4 = strcmp((char *)(*piVar6 + (int)gpGlobals[0x26]),"func_door");
          if (iVar4 == 0) {
            iVar4 = *piVar5;
            iVar3 = *param_1;
            *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar3 + 8);
            *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
            *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
            iVar4 = *piVar5;
            *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
            *(undefined4 *)(iVar4 + 0x24) = DAT_001a7e04;
            *(undefined4 *)(iVar4 + 0x28) = DAT_001a7e08;
          }
          else {
            iVar4 = *piVar5;
            iVar3 = *param_1;
            *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar3 + 0x50);
            *(undefined4 *)(iVar4 + 0x54) = *(undefined4 *)(iVar3 + 0x54);
            *(undefined4 *)(iVar4 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
            iVar4 = *piVar5;
            *(undefined4 *)(iVar4 + 0x5c) = g_vecZero;
            *(undefined4 *)(iVar4 + 0x60) = DAT_001a7e04;
            *(undefined4 *)(iVar4 + 100) = DAT_001a7e08;
          }
        }
      }
      if (piVar5[0xfd] == 3) {
        DoorGoUp__9CBaseDoor(piVar5);
      }
      else {
        DoorGoDown__9CBaseDoor(piVar5);
      }
    }
  }
  goto LAB_0009487c;
}


// Blocked__9CFuncPlatP11CBaseEntity  @ 000c2d64
void Blocked__9CFuncPlatP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  code *pcVar2;
  
  (*DAT_001a7f34)(2,"%s Blocked by %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                  *(int *)*param_2 + *(int *)(gpGlobals + 0x98));
  (**(code **)(param_2[0xf5] + 0x34))(param_2,*param_1,*param_1,0x3f800000,1);
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),6,*(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
  }
  if (param_1[0xfd] == 2) {
    pcVar2 = *(code **)(param_1[0xf5] + 0x10c);
  }
  else {
    if (param_1[0xfd] != 3) {
      return;
    }
    pcVar2 = *(code **)(param_1[0xf5] + 0x108);
  }
  (*pcVar2)(param_1);
  return;
}


// Blocked__9CPendulumP11CBaseEntity  @ 000820ec
void Blocked__9CPendulumP11CBaseEntity(int param_1)

{
  *(undefined4 *)(param_1 + 0x3e0) = *gpGlobals;
  return;
}


