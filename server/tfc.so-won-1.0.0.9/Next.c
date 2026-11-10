// Next__10CFuncTrain  @ 000d2440
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Next__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  piVar4 = (int *)(**(code **)(param_1[0xf2] + 0xa4))();
  if (piVar4 == (int *)0x0) {
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1c8) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x1e8),6,
                 *(int *)(iVar2 + 0x1c8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
    }
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1cc) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x1e8),2,
                 *(int *)(iVar2 + 0x1cc) + *(int *)(gpGlobals + 0x98),param_1[0x11c],0x3f4ccccd,0,
                 100);
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x1b4) = *(undefined4 *)(*param_1 + 0x1a8);
    *(undefined4 *)(*param_1 + 0x1a8) = *(undefined4 *)(*piVar4 + 0x1a8);
    lVar5 = (longdouble)(**(code **)(piVar4[0xf2] + 100))();
    param_1[0xfd] = (int)(float)lVar5;
    if ((param_1[0x11d] != 0) &&
       (fVar1 = *(float *)(param_1[0x11d] + 0x1d8),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      *(float *)(*param_1 + 0x1d8) = fVar1;
      (*DAT_001755b4)(2,"Train %s speed to %4.2f\n",
                      *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98),
                      (double)*(float *)(*param_1 + 0x1d8));
    }
    param_1[0x11d] = *piVar4;
    *(undefined4 *)(*param_1 + 0x170) = *(undefined4 *)(*piVar4 + 0x1e8);
    if ((*(byte *)(param_1[0x11d] + 0x180) & 2) == 0) {
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x1c8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar2 + 0x1e8),6,
                   *(int *)(iVar2 + 0x1c8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
        iVar2 = *param_1;
        if (*(int *)(iVar2 + 0x1c8) != 0) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(iVar2 + 0x1e8),6,
                     *(int *)(iVar2 + 0x1c8) + *(int *)(gpGlobals + 0x98),param_1[0x11c],0x3f4ccccd,
                     0,100);
        }
      }
      *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0xdf;
      param_1[0x111] = -0x10000;
      param_1[0x112] = (int)Wait__10CFuncTrain;
      iVar2 = *param_1;
      fStack_10 = *(float *)(iVar2 + 0xbc) + *(float *)(iVar2 + 200);
      fStack_c = *(float *)(iVar2 + 0xc0) + *(float *)(iVar2 + 0xcc);
      fStack_8 = *(float *)(iVar2 + 0xc4) + *(float *)(iVar2 + 0xd0);
      fStack_1c = fStack_10 * _FUN_001380b0;
      fStack_18 = fStack_c * _FUN_001380b0;
      fStack_14 = _FUN_001380b0 * fStack_8;
      iVar3 = *piVar4;
      fStack_28 = *(float *)(iVar3 + 8) - fStack_1c;
      fStack_24 = *(float *)(iVar3 + 0xc) - fStack_18;
      fStack_20 = *(float *)(iVar3 + 0x10) - fStack_14;
      LinearMove__11CBaseToggleG6Vectorf(param_1,&fStack_28,*(undefined4 *)(iVar2 + 0x1d8));
    }
    else {
      *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x20;
      iVar2 = *param_1;
      fStack_28 = *(float *)(iVar2 + 0xbc) + *(float *)(iVar2 + 200);
      fStack_24 = *(float *)(iVar2 + 0xc0) + *(float *)(iVar2 + 0xcc);
      fStack_20 = *(float *)(iVar2 + 0xc4) + *(float *)(iVar2 + 0xd0);
      fStack_1c = fStack_28 * _FUN_001380b0;
      fStack_18 = fStack_24 * _FUN_001380b0;
      fStack_14 = _FUN_001380b0 * fStack_20;
      iVar3 = *piVar4;
      fStack_10 = *(float *)(iVar3 + 8) - fStack_1c;
      fStack_c = *(float *)(iVar3 + 0xc) - fStack_18;
      fStack_8 = *(float *)(iVar3 + 0x10) - fStack_14;
      UTIL_SetOrigin__FP9entvars_tRC6Vector(iVar2,&fStack_10);
      Wait__10CFuncTrain(param_1);
    }
  }
  return;
}


// Next__10CGunTarget  @ 000d5880
void Next__10CGunTarget(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  float local_10;
  float local_c;
  float local_8;
  
  param_1[3] = 0;
  param_1[4] = 0;
  uVar3 = (**(code **)(param_1[0xf2] + 0xa4))(param_1);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x11e,uVar3);
  piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x11e);
  if (piVar4 == (int *)0x0) {
    (**(code **)(param_1[0xf2] + 0x14c))(param_1);
  }
  else {
    param_1[0x111] = -0x10000;
    param_1[0x112] = (int)Wait__10CGunTarget;
    iVar1 = *param_1;
    iVar2 = *piVar4;
    local_10 = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xbc) + *(float *)(iVar1 + 200)) * 0.5;
    local_c = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xc0) + *(float *)(iVar1 + 0xcc)) * 0.5;
    local_8 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xc4) + *(float *)(iVar1 + 0xd0)) * 0.5
    ;
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(iVar1 + 0x1d8));
  }
  return;
}


// Next__15CFuncTrackTrain  @ 000d33c0
void Next__15CFuncTrackTrain(int *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  longdouble lVar6;
  undefined4 uVar7;
  char *pcVar9;
  undefined8 uVar8;
  undefined4 *puVar10;
  float *pfVar11;
  float fStack_4c;
  undefined4 uStack_38;
  float fStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    iVar4 = *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98);
    pcVar9 = "TRAIN(%s): Speed is 0\n";
LAB_000d3433:
    uVar8 = CONCAT44(pcVar9,2);
    (*DAT_001755b4)(2);
    StopSound__15CFuncTrackTrain(param_1,uVar8,iVar4);
    return;
  }
  if (param_1[0xf3] == 0) {
    iVar4 = *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98);
    pcVar9 = "TRAIN(%s): Lost path\n";
    goto LAB_000d3433;
  }
  UpdateSound__15CFuncTrackTrain(param_1);
  fStack_10 = *(float *)(*param_1 + 8);
  fStack_c = *(float *)(*param_1 + 0xc);
  fStack_8 = *(float *)(*param_1 + 0x10) - (float)param_1[0xf5];
  fStack_14 = *(float *)(*param_1 + 0x1d8) * 0.1;
  piVar3 = (int *)LookAhead__10CPathTrackP6Vectorfi(param_1[0xf3],&fStack_10,fStack_14,1);
  fStack_8 = fStack_8 + (float)param_1[0xf5];
  iVar4 = *param_1;
  fStack_20 = (fStack_10 - *(float *)(iVar4 + 8)) * 10.0;
  fStack_1c = (fStack_c - *(float *)(iVar4 + 0xc)) * 10.0;
  fStack_18 = (fStack_8 - *(float *)(iVar4 + 0x10)) * 10.0;
  *(float *)(iVar4 + 0x20) = fStack_20;
  *(float *)(iVar4 + 0x24) = fStack_1c;
  *(float *)(iVar4 + 0x28) = fStack_18;
  fStack_2c = *(float *)(*param_1 + 8);
  fStack_28 = *(float *)(*param_1 + 0xc);
  fStack_24 = *(float *)(*param_1 + 0x10) - (float)param_1[0xf5];
  fVar1 = (float)param_1[0xf4];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    uVar8 = CONCAT44(fVar1,&fStack_2c);
  }
  else {
    uVar8 = CONCAT44(0x42c80000,&fStack_2c);
  }
  LookAhead__10CPathTrackP6Vectorfi(param_1[0xf3],uVar8,0);
  fStack_24 = fStack_24 + (float)param_1[0xf5];
  iVar4 = *param_1;
  fStack_20 = fStack_2c - *(float *)(iVar4 + 8);
  fStack_1c = fStack_28 - *(float *)(iVar4 + 0xc);
  fStack_18 = fStack_24 - *(float *)(iVar4 + 0x10);
  pfVar11 = &fStack_20;
  puVar10 = &uStack_38;
  UTIL_VecToAngles__FRC6Vector();
  fStack_34 = fStack_34 + 180.0;
  FixupAngles__FR6Vector(&uStack_38,puVar10,pfVar11);
  FixupAngles__FR6Vector(*param_1 + 0x50);
  if ((piVar3 == (int *)0x0) ||
     (((byte)((byte)((ushort)((ushort)NAN(fStack_20) << 10) >> 8) |
             (byte)((ushort)((ushort)(fStack_20 == 0.0) << 0xe) >> 8)) == 0x40 &&
      ((byte)((byte)((ushort)((ushort)NAN(fStack_1c) << 10) >> 8) |
             (byte)((ushort)((ushort)(fStack_1c == 0.0) << 0xe) >> 8)) == 0x40)))) {
    iVar4 = *param_1;
    uStack_38 = *(undefined4 *)(iVar4 + 0x50);
    fStack_34 = *(float *)(iVar4 + 0x54);
    uStack_30 = *(undefined4 *)(iVar4 + 0x58);
  }
  if (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) == 0) {
    fStack_4c = 0.0;
  }
  else {
    lVar6 = (longdouble)UTIL_AngleDistance__Fff(uStack_38,*(undefined4 *)(*param_1 + 0x50));
    fStack_4c = (float)lVar6;
  }
  lVar6 = (longdouble)UTIL_AngleDistance__Fff(fStack_34,*(undefined4 *)(*param_1 + 0x54));
  *(float *)(*param_1 + 0x60) = (float)(lVar6 * (longdouble)10.0);
  *(float *)(*param_1 + 0x5c) = (float)((longdouble)10.0 * (longdouble)fStack_4c);
  fVar1 = (float)param_1[0x102];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_000d376d;
  iVar4 = *param_1;
  if (-5.0 <= *(float *)(iVar4 + 0x60)) {
    iVar4 = *param_1;
    fVar1 = *(float *)(iVar4 + 0x60);
    if ((byte)(5.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 5.0) << 0xe) >> 8)) == 1) {
      fVar1 = (float)param_1[0x102];
      uVar8 = CONCAT44(*(undefined4 *)(iVar4 + 0x58),fVar1 + fVar1);
      uVar7 = *(undefined4 *)(iVar4 + 0x58);
      goto LAB_000d36fd;
    }
    lVar6 = (longdouble)
            UTIL_ApproachAngle__Ffff
                      (0,*(undefined4 *)(*param_1 + 0x58),(float)param_1[0x102] * 4.0,
                       *(undefined4 *)(*param_1 + 0x58));
    lVar6 = (longdouble)UTIL_AngleDistance__Fff((float)lVar6);
    iVar4 = *param_1;
    lVar6 = lVar6 * (longdouble)4.0;
  }
  else {
    uVar8 = CONCAT44(*(undefined4 *)(iVar4 + 0x58),fVar1 + fVar1);
    uVar7 = *(undefined4 *)(iVar4 + 0x58);
    fVar1 = -fVar1;
LAB_000d36fd:
    lVar6 = (longdouble)UTIL_ApproachAngle__Ffff(fVar1,uVar7,uVar8);
    lVar6 = (longdouble)UTIL_AngleDistance__Fff((float)lVar6);
    iVar4 = *param_1;
  }
  *(float *)(iVar4 + 100) = (float)lVar6;
LAB_000d376d:
  if (piVar3 == (int *)0x0) {
    StopSound__15CFuncTrackTrain();
    iVar4 = *param_1;
    *(float *)(iVar4 + 0x20) = fStack_10 - *(float *)(iVar4 + 8);
    *(float *)(iVar4 + 0x24) = fStack_c - *(float *)(iVar4 + 0xc);
    *(float *)(iVar4 + 0x28) = fStack_8 - *(float *)(iVar4 + 0x10);
    iVar4 = *param_1;
    *(undefined4 *)(iVar4 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar4 + 0x60) = DAT_00175484;
    *(undefined4 *)(iVar4 + 100) = DAT_00175488;
    iVar4 = *param_1;
    fVar1 = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                 *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                 *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
    param_1[0x103] = *(int *)(iVar4 + 0x1d8);
    *(undefined4 *)(iVar4 + 0x1d8) = 0;
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      DeadEnd__15CFuncTrackTrain();
      return;
    }
    fVar2 = fVar1 / (float)param_1[0x103];
    iVar4 = *param_1;
    fVar1 = (float)param_1[0x103] / fVar1;
    *(float *)(iVar4 + 0x20) = fVar1 * *(float *)(iVar4 + 0x20);
    *(float *)(iVar4 + 0x24) = fVar1 * *(float *)(iVar4 + 0x24);
    *(float *)(iVar4 + 0x28) = fVar1 * *(float *)(iVar4 + 0x28);
    param_1[3] = -0x10000;
    param_1[4] = (int)DeadEnd__15CFuncTrackTrain;
    uVar7 = 0;
    iVar4 = *param_1;
  }
  else {
    if (piVar3 != (int *)param_1[0xf3]) {
      fVar1 = *(float *)(*param_1 + 0x1d8);
      piVar5 = piVar3;
      if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        piVar5 = (int *)param_1[0xf3];
      }
      param_1[0xf3] = (int)piVar3;
      if (*(int *)(*piVar5 + 0x1b4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*piVar5 + 0x1b4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
        if ((*(byte *)(*piVar5 + 0x180) & 2) != 0) {
          *(undefined4 *)(*piVar5 + 0x1b4) = 0;
        }
      }
      if ((*(byte *)(*piVar5 + 0x180) & 8) != 0) {
        *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 2;
      }
      if (((*(byte *)(*param_1 + 0x180) & 2) != 0) &&
         (fVar1 = *(float *)(*piVar5 + 0x1d8),
         (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
        *(float *)(*param_1 + 0x1d8) = fVar1;
        (*DAT_001755b4)(2,"TrackTrain %s speed to %4.2f\n",
                        *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98),
                        (double)*(float *)(*param_1 + 0x1d8));
      }
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)Next__15CFuncTrackTrain;
    uVar7 = 1;
    iVar4 = *param_1;
    fVar2 = 0.5;
  }
  NextThink__15CFuncTrackTrainfi(param_1,fVar2 + *(float *)(iVar4 + 0xe0),uVar7);
  return;
}


