// Next__10CFuncTrain  @ 000cea80
void Next__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar4 = (int *)(**(code **)(param_1[0x111] + 0xac))();
  if (piVar4 == (int *)0x0) {
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1e8) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),6,
                 *(int *)(iVar2 + 0x1e8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
    }
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1ec) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),2,
                 *(int *)(iVar2 + 0x1ec) + *(int *)(gpGlobals + 0x98),param_1[0x13b],0x3f4ccccd,0,
                 100);
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x1d4) = *(undefined4 *)(*param_1 + 0x1c8);
    *(undefined4 *)(*param_1 + 0x1c8) = *(undefined4 *)(*piVar4 + 0x1c8);
    lVar5 = (longdouble)(**(code **)(piVar4[0x111] + 0x68))();
    param_1[0x11c] = (int)(float)lVar5;
    if ((param_1[0x13c] != 0) &&
       (fVar1 = *(float *)(param_1[0x13c] + 0x1f8),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      *(float *)(*param_1 + 0x1f8) = fVar1;
      (*DAT_001c1114)(2,"Train %s speed to %4.2f\n",
                      *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                      (double)*(float *)(*param_1 + 0x1f8));
    }
    param_1[0x13c] = *piVar4;
    *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*piVar4 + 0x208);
    if ((*(byte *)(param_1[0x13c] + 0x1a0) & 2) == 0) {
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x1e8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar2 + 0x208),6,
                   *(int *)(iVar2 + 0x1e8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
        iVar2 = *param_1;
        if (*(int *)(iVar2 + 0x1e8) != 0) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(iVar2 + 0x208),6,
                     *(int *)(iVar2 + 0x1e8) + *(int *)(gpGlobals + 0x98),param_1[0x13b],0x3f4ccccd,
                     0,100);
        }
      }
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0xdf;
      param_1[0x130] = -0x10000;
      param_1[0x131] = (int)Wait__10CFuncTrain;
      iVar2 = *param_1;
      fStack_c = *(float *)(iVar2 + 0xdc) + *(float *)(iVar2 + 0xe8);
      fStack_8 = *(float *)(iVar2 + 0xe0) + *(float *)(iVar2 + 0xec);
      fStack_4 = *(float *)(iVar2 + 0xe4) + *(float *)(iVar2 + 0xf0);
      fStack_18 = fStack_c * 0.5;
      fStack_14 = fStack_8 * 0.5;
      fStack_10 = fStack_4 * 0.5;
      iVar3 = *piVar4;
      fStack_24 = *(float *)(iVar3 + 8) - fStack_18;
      fStack_20 = *(float *)(iVar3 + 0xc) - fStack_14;
      fStack_1c = *(float *)(iVar3 + 0x10) - fStack_10;
      LinearMove__11CBaseToggleG6Vectorf(param_1,&fStack_24,*(undefined4 *)(iVar2 + 0x1f8));
    }
    else {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
      iVar2 = *param_1;
      fStack_24 = *(float *)(iVar2 + 0xdc) + *(float *)(iVar2 + 0xe8);
      fStack_20 = *(float *)(iVar2 + 0xe0) + *(float *)(iVar2 + 0xec);
      fStack_1c = *(float *)(iVar2 + 0xe4) + *(float *)(iVar2 + 0xf0);
      fStack_18 = fStack_24 * 0.5;
      fStack_14 = fStack_20 * 0.5;
      fStack_10 = fStack_1c * 0.5;
      iVar3 = *piVar4;
      fStack_c = *(float *)(iVar3 + 8) - fStack_18;
      fStack_8 = *(float *)(iVar3 + 0xc) - fStack_14;
      fStack_4 = *(float *)(iVar3 + 0x10) - fStack_10;
      UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar2,&fStack_c);
      Wait__10CFuncTrain(param_1);
    }
  }
  return;
}


// Next__10CGunTarget  @ 000d24a8
void Next__10CGunTarget(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  float local_c;
  float local_8;
  float local_4;
  
  param_1[3] = 0;
  param_1[4] = 0;
  uVar3 = (**(code **)(param_1[0x111] + 0xac))(param_1);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x13d,uVar3);
  piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
  if (piVar4 == (int *)0x0) {
    (**(code **)(param_1[0x111] + 0x154))(param_1);
  }
  else {
    param_1[0x130] = -0x10000;
    param_1[0x131] = (int)Wait__10CGunTarget;
    iVar1 = *param_1;
    iVar2 = *piVar4;
    local_c = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xdc) + *(float *)(iVar1 + 0xe8)) * 0.5;
    local_8 = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xe0) + *(float *)(iVar1 + 0xec)) * 0.5;
    local_4 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xe4) + *(float *)(iVar1 + 0xf0)) * 0.5
    ;
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(iVar1 + 0x1f8));
  }
  return;
}


// Next__15CFuncTrackTrain  @ 000cfc78
void Next__15CFuncTrackTrain(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  longdouble lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  float *pfVar9;
  float *pfVar10;
  int *local_54;
  float local_4c;
  float local_48;
  undefined4 local_38;
  float local_34;
  undefined4 local_30;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    iVar3 = *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98);
    pcVar4 = "TRAIN(%s): Speed is 0\n";
LAB_000cfd00:
    (*DAT_001c1114)(2,pcVar4,iVar3);
    StopSound__15CFuncTrackTrain(param_1);
    return;
  }
  if (param_1[0x112] == 0) {
    iVar3 = *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98);
    pcVar4 = "TRAIN(%s): Lost path\n";
    goto LAB_000cfd00;
  }
  UpdateSound__15CFuncTrackTrain(param_1);
  local_c = *(float *)(*param_1 + 8);
  local_8 = *(float *)(*param_1 + 0xc);
  local_4 = *(float *)(*param_1 + 0x10) - (float)param_1[0x114];
  local_10 = *(float *)(*param_1 + 0x1f8) * 0.1;
  piVar5 = (int *)LookAhead__10CPathTrackP6Vectorfi(param_1[0x112],&local_c,local_10,1);
  local_4 = local_4 + (float)param_1[0x114];
  iVar3 = *param_1;
  local_1c = (local_c - *(float *)(iVar3 + 8)) * 10.0;
  local_18 = (local_8 - *(float *)(iVar3 + 0xc)) * 10.0;
  local_14 = (local_4 - *(float *)(iVar3 + 0x10)) * 10.0;
  *(float *)(iVar3 + 0x20) = local_1c;
  *(float *)(iVar3 + 0x24) = local_18;
  *(float *)(iVar3 + 0x28) = local_14;
  local_28 = *(float *)(*param_1 + 8);
  local_24 = *(float *)(*param_1 + 0xc);
  local_20 = *(float *)(*param_1 + 0x10) - (float)param_1[0x114];
  if ((float)param_1[0x113] <= 0.0) {
    uVar8 = CONCAT44(0x42c80000,&local_28);
  }
  else {
    uVar8 = CONCAT44(param_1[0x113],&local_28);
  }
  LookAhead__10CPathTrackP6Vectorfi(param_1[0x112],uVar8,0);
  local_20 = local_20 + (float)param_1[0x114];
  iVar3 = *param_1;
  local_1c = local_28 - *(float *)(iVar3 + 8);
  local_18 = local_24 - *(float *)(iVar3 + 0xc);
  local_14 = local_20 - *(float *)(iVar3 + 0x10);
  pfVar10 = &local_1c;
  pfVar9 = &local_34;
  UTIL_VecToAngles__FRC6Vector();
  local_34 = local_34 + 180.0;
  FixupAngles__FR6Vector(&local_34,pfVar9,pfVar10);
  FixupAngles__FR6Vector(*param_1 + 0x50);
  if ((piVar5 == (int *)0x0) ||
     (((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40 &&
      ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40)))) {
    iVar3 = *param_1;
    local_38 = *(undefined4 *)(iVar3 + 0x50);
    local_34 = *(float *)(iVar3 + 0x54);
    local_30 = *(undefined4 *)(iVar3 + 0x58);
  }
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) == 0) {
    local_4c = 0.0;
  }
  else {
    lVar6 = (longdouble)UTIL_AngleDistance__Fff(local_38,*(undefined4 *)(*param_1 + 0x50));
    local_4c = (float)lVar6;
  }
  lVar6 = (longdouble)UTIL_AngleDistance__Fff(local_34,*(undefined4 *)(*param_1 + 0x54));
  *(float *)(*param_1 + 0x60) = (float)(lVar6 * (longdouble)10.0);
  *(float *)(*param_1 + 0x5c) = (float)((longdouble)10.0 * (longdouble)local_4c);
  fVar1 = (float)param_1[0x121];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_000d007d;
  iVar3 = *param_1;
  fVar2 = *(float *)(iVar3 + 0x60);
  if ((byte)((-5.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == -5.0) << 0xe) >> 8)) - 1) < 0x40) {
    iVar3 = *param_1;
    if (5.0 < *(float *)(iVar3 + 0x60)) {
      fVar1 = (float)param_1[0x121];
      uVar8 = CONCAT44(*(undefined4 *)(iVar3 + 0x58),fVar1 + fVar1);
      uVar7 = *(undefined4 *)(iVar3 + 0x58);
      goto LAB_000d0011;
    }
    lVar6 = (longdouble)
            UTIL_ApproachAngle__Ffff
                      (0,*(undefined4 *)(*param_1 + 0x58),(float)param_1[0x121] * 4.0,
                       *(undefined4 *)(*param_1 + 0x58));
    lVar6 = (longdouble)UTIL_AngleDistance__Fff((float)lVar6);
    iVar3 = *param_1;
    lVar6 = lVar6 * (longdouble)4.0;
  }
  else {
    uVar8 = CONCAT44(*(undefined4 *)(iVar3 + 0x58),fVar1 + fVar1);
    uVar7 = *(undefined4 *)(iVar3 + 0x58);
    fVar1 = -fVar1;
LAB_000d0011:
    lVar6 = (longdouble)UTIL_ApproachAngle__Ffff(fVar1,uVar7,uVar8);
    lVar6 = (longdouble)UTIL_AngleDistance__Fff((float)lVar6);
    iVar3 = *param_1;
  }
  *(float *)(iVar3 + 100) = (float)lVar6;
LAB_000d007d:
  if (piVar5 == (int *)0x0) {
    StopSound__15CFuncTrackTrain();
    iVar3 = *param_1;
    *(float *)(iVar3 + 0x20) = local_10 - *(float *)(iVar3 + 8);
    *(float *)(iVar3 + 0x24) = local_c - *(float *)(iVar3 + 0xc);
    *(float *)(iVar3 + 0x28) = local_8 - *(float *)(iVar3 + 0x10);
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar3 + 0x60) = DAT_001c0fe4;
    *(undefined4 *)(iVar3 + 100) = DAT_001c0fe8;
    iVar3 = *param_1;
    fVar1 = SQRT(*(float *)(iVar3 + 0x28) * *(float *)(iVar3 + 0x28) +
                 *(float *)(iVar3 + 0x24) * *(float *)(iVar3 + 0x24) +
                 *(float *)(iVar3 + 0x20) * *(float *)(iVar3 + 0x20));
    param_1[0x122] = *(int *)(iVar3 + 0x1f8);
    *(undefined4 *)(iVar3 + 0x1f8) = 0;
    if (fVar1 <= 0.0) {
      DeadEnd__15CFuncTrackTrain();
      return;
    }
    local_48 = fVar1 / (float)param_1[0x122];
    iVar3 = *param_1;
    fVar1 = (float)param_1[0x122] / fVar1;
    *(float *)(iVar3 + 0x20) = fVar1 * *(float *)(iVar3 + 0x20);
    *(float *)(iVar3 + 0x24) = fVar1 * *(float *)(iVar3 + 0x24);
    *(float *)(iVar3 + 0x28) = fVar1 * *(float *)(iVar3 + 0x28);
    param_1[3] = -0x10000;
    param_1[4] = (int)DeadEnd__15CFuncTrackTrain;
    uVar7 = 0;
    iVar3 = *param_1;
  }
  else {
    if (piVar5 != (int *)param_1[0x112]) {
      fVar1 = *(float *)(*param_1 + 0x1f8);
      local_54 = piVar5;
      if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        local_54 = (int *)param_1[0x112];
      }
      param_1[0x112] = (int)piVar5;
      if (*(int *)(*local_54 + 0x1d4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*local_54 + 0x1d4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
        if ((*(byte *)(*local_54 + 0x1a0) & 2) != 0) {
          *(undefined4 *)(*local_54 + 0x1d4) = 0;
        }
      }
      if ((*(byte *)(*local_54 + 0x1a0) & 8) != 0) {
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 2;
      }
      if (((*(byte *)(*param_1 + 0x1a0) & 2) != 0) &&
         (fVar1 = *(float *)(*local_54 + 0x1f8),
         (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
        *(float *)(*param_1 + 0x1f8) = fVar1;
        (*DAT_001c1114)(2,"TrackTrain %s speed to %4.2f\n",
                        *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                        (double)*(float *)(*param_1 + 0x1f8));
      }
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)Next__15CFuncTrackTrain;
    uVar7 = 1;
    iVar3 = *param_1;
  }
  NextThink__15CFuncTrackTrainfi(param_1,local_48 + *(float *)(iVar3 + 0x100),uVar7);
  return;
}


