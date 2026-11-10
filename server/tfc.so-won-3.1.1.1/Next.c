// Next__10CFuncTrain  @ 000ce124
void Next__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  longdouble lVar5;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  piVar3 = (int *)(**(code **)(param_1[0x115] + 0xac))();
  if (piVar3 == (int *)0x0) {
    iVar4 = *param_1;
    if (*(int *)(iVar4 + 0x1e8) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar4 + 0x208),6,
                 *(int *)(iVar4 + 0x1e8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
      iVar4 = *param_1;
    }
    if (*(int *)(iVar4 + 0x1ec) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar4 + 0x208),2,
                 *(int *)(iVar4 + 0x1ec) + *(int *)(gpGlobals + 0x98),param_1[0x13f],0x3f4ccccd,0,
                 100);
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x1d4) = *(undefined4 *)(*param_1 + 0x1c8);
    *(undefined4 *)(*param_1 + 0x1c8) = *(undefined4 *)(*piVar3 + 0x1c8);
    lVar5 = (longdouble)(**(code **)(piVar3[0x115] + 0x68))();
    param_1[0x120] = (int)(float)lVar5;
    if ((param_1[0x140] != 0) &&
       (fVar1 = *(float *)(param_1[0x140] + 0x1f8),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      *(float *)(*param_1 + 0x1f8) = fVar1;
      (*DAT_0019f794)(2,"Train %s speed to %4.2f\n",
                      *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                      (double)*(float *)(*param_1 + 0x1f8));
    }
    param_1[0x140] = *piVar3;
    *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*piVar3 + 0x208);
    if ((*(byte *)(param_1[0x140] + 0x1a0) & 2) == 0) {
      iVar4 = *param_1;
      if (*(int *)(iVar4 + 0x1e8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar4 + 0x208),6,
                   *(int *)(iVar4 + 0x1e8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
        iVar4 = *param_1;
        if (*(int *)(iVar4 + 0x1e8) != 0) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(iVar4 + 0x208),6,
                     *(int *)(iVar4 + 0x1e8) + *(int *)(gpGlobals + 0x98),param_1[0x13f],0x3f4ccccd,
                     0,100);
          iVar4 = *param_1;
        }
      }
      *(byte *)(iVar4 + 0x118) = *(byte *)(iVar4 + 0x118) & 0xdf;
      iVar4 = *param_1;
      param_1[0x134] = -0x10000;
      param_1[0x135] = (int)Wait__10CFuncTrain;
      local_10 = *(float *)(iVar4 + 0xdc) + *(float *)(iVar4 + 0xe8);
      local_c = *(float *)(iVar4 + 0xe0) + *(float *)(iVar4 + 0xec);
      local_8 = *(float *)(iVar4 + 0xe4) + *(float *)(iVar4 + 0xf0);
      local_1c = local_10 * 0.5;
      local_18 = local_c * 0.5;
      local_14 = local_8 * 0.5;
      iVar2 = *piVar3;
      local_28 = *(float *)(iVar2 + 8) - local_1c;
      local_24 = *(float *)(iVar2 + 0xc) - local_18;
      local_20 = *(float *)(iVar2 + 0x10) - local_14;
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_28,*(undefined4 *)(iVar4 + 0x1f8));
    }
    else {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
      iVar4 = *param_1;
      local_28 = *(float *)(iVar4 + 0xdc) + *(float *)(iVar4 + 0xe8);
      local_24 = *(float *)(iVar4 + 0xe0) + *(float *)(iVar4 + 0xec);
      local_20 = *(float *)(iVar4 + 0xe4) + *(float *)(iVar4 + 0xf0);
      local_1c = local_28 * 0.5;
      local_18 = local_24 * 0.5;
      local_14 = local_20 * 0.5;
      iVar2 = *piVar3;
      local_10 = *(float *)(iVar2 + 8) - local_1c;
      local_c = *(float *)(iVar2 + 0xc) - local_18;
      local_8 = *(float *)(iVar2 + 0x10) - local_14;
      UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar4,&local_10);
      Wait__10CFuncTrain(param_1);
    }
  }
  return;
}


// Next__10CGunTarget  @ 000d1400
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
  uVar3 = (**(code **)(param_1[0x115] + 0xac))(param_1);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x141,uVar3);
  piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
  if (piVar4 == (int *)0x0) {
    (**(code **)(param_1[0x115] + 0x154))(param_1);
  }
  else {
    iVar1 = *param_1;
    param_1[0x134] = -0x10000;
    param_1[0x135] = (int)Wait__10CGunTarget;
    iVar2 = *piVar4;
    local_10 = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xdc) + *(float *)(iVar1 + 0xe8)) * 0.5;
    local_c = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xe0) + *(float *)(iVar1 + 0xec)) * 0.5;
    local_8 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xe4) + *(float *)(iVar1 + 0xf0)) * 0.5
    ;
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(iVar1 + 0x1f8));
  }
  return;
}


// Next__15CFuncTrackTrain  @ 000cf070
void Next__15CFuncTrackTrain(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  int *piVar9;
  longdouble lVar10;
  longdouble lVar11;
  undefined4 *puVar12;
  float *pfVar13;
  undefined4 local_38;
  float local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar6 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar6 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar6 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    iVar6 = *(int *)(iVar6 + 0x1cc) + *(int *)(gpGlobals + 0x98);
    pcVar7 = "TRAIN(%s): Speed is 0\n";
LAB_000cf0fa:
    (*DAT_0019f794)(2,pcVar7,iVar6);
    if ((param_1[0x122] != 0) && (*(int *)(*param_1 + 0x1e8) != 0)) {
      (*DAT_0019f88c)(10,*(undefined4 *)(*param_1 + 0x208),(short)param_1[0x127],0,&g_vecZero,
                      &g_vecZero,0,0,(*(ushort *)(param_1 + 0x123) & 7) << 0xc,0,1,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"plats/ttrain_brake1.wav",param_1[0x124],
                 0x3f4ccccd,0,100);
    }
    param_1[0x122] = 0;
    return;
  }
  if (param_1[0x116] == 0) {
    iVar6 = *(int *)(iVar6 + 0x1cc) + *(int *)(gpGlobals + 0x98);
    pcVar7 = "TRAIN(%s): Lost path\n";
    goto LAB_000cf0fa;
  }
  UpdateSound__15CFuncTrackTrain(param_1);
  local_10 = *(float *)(*param_1 + 8);
  local_c = *(float *)(*param_1 + 0xc);
  local_8 = *(float *)(*param_1 + 0x10) - (float)param_1[0x118];
  local_14 = *(float *)(*param_1 + 0x1f8) * 0.1;
  piVar8 = (int *)LookAhead__10CPathTrackP6Vectorfi(param_1[0x116],&local_10,local_14,1);
  local_8 = local_8 + (float)param_1[0x118];
  iVar6 = *param_1;
  local_20 = (local_10 - *(float *)(iVar6 + 8)) * 10.0;
  local_1c = (local_c - *(float *)(iVar6 + 0xc)) * 10.0;
  local_18 = (local_8 - *(float *)(iVar6 + 0x10)) * 10.0;
  *(float *)(iVar6 + 0x20) = local_20;
  *(float *)(iVar6 + 0x24) = local_1c;
  *(float *)(iVar6 + 0x28) = local_18;
  local_2c = *(float *)(*param_1 + 8);
  local_28 = *(float *)(*param_1 + 0xc);
  local_24 = *(float *)(*param_1 + 0x10) - (float)param_1[0x118];
  fVar2 = (float)param_1[0x117];
  if ((byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    fVar2 = 100.0;
  }
  LookAhead__10CPathTrackP6Vectorfi(param_1[0x116],&local_2c,fVar2,0);
  local_24 = local_24 + (float)param_1[0x118];
  iVar6 = *param_1;
  local_20 = local_2c - *(float *)(iVar6 + 8);
  local_1c = local_28 - *(float *)(iVar6 + 0xc);
  local_18 = local_24 - *(float *)(iVar6 + 0x10);
  pfVar13 = &local_20;
  puVar12 = &local_38;
  UTIL_VecToAngles__FRC6Vector();
  local_34 = local_34 + 180.0;
  FixupAngles__FR6Vector(&local_38,puVar12,pfVar13);
  FixupAngles__FR6Vector(*param_1 + 0x50);
  if ((piVar8 == (int *)0x0) ||
     (((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40 &&
      ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40)))) {
    iVar6 = *param_1;
    local_38 = *(undefined4 *)(iVar6 + 0x50);
    local_34 = *(float *)(iVar6 + 0x54);
    local_30 = *(undefined4 *)(iVar6 + 0x58);
  }
  iVar6 = *param_1;
  if (((*(byte *)(iVar6 + 0x1a0) ^ 1) & 1) == 0) {
    lVar10 = (longdouble)0;
  }
  else {
    lVar10 = (longdouble)UTIL_AngleDistance__Fff(local_38,*(undefined4 *)(iVar6 + 0x50));
    iVar6 = *param_1;
  }
  lVar11 = (longdouble)UTIL_AngleDistance__Fff(local_34,*(undefined4 *)(iVar6 + 0x54));
  *(float *)(*param_1 + 0x60) = (float)(lVar11 * (longdouble)10.0);
  *(float *)(*param_1 + 0x5c) = (float)(lVar10 * (longdouble)10.0);
  fVar2 = (float)param_1[0x125];
  if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_000cf499;
  iVar6 = *param_1;
  if (-5.0 <= *(float *)(iVar6 + 0x60)) {
    if (5.0 < *(float *)(iVar6 + 0x60)) {
      uVar3 = *(undefined4 *)(iVar6 + 0x58);
      fVar4 = fVar2;
      goto LAB_000cf428;
    }
    lVar10 = (longdouble)
             UTIL_ApproachAngle__Ffff
                       (0,*(undefined4 *)(iVar6 + 0x58),fVar2 * 4.0,*(undefined4 *)(iVar6 + 0x58));
    lVar10 = (longdouble)UTIL_AngleDistance__Fff((float)lVar10);
    iVar6 = *param_1;
    lVar10 = lVar10 * (longdouble)4.0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar6 + 0x58);
    fVar4 = -fVar2;
LAB_000cf428:
    lVar10 = (longdouble)
             UTIL_ApproachAngle__Ffff(fVar4,*(undefined4 *)(iVar6 + 0x58),fVar2 + fVar2,uVar3);
    lVar10 = (longdouble)UTIL_AngleDistance__Fff((float)lVar10);
    iVar6 = *param_1;
  }
  *(float *)(iVar6 + 100) = (float)lVar10;
LAB_000cf499:
  if (piVar8 == (int *)0x0) {
    if ((param_1[0x122] != 0) && (*(int *)(*param_1 + 0x1e8) != 0)) {
      (*DAT_0019f88c)(10,*(undefined4 *)(*param_1 + 0x208),(short)param_1[0x127],0,&g_vecZero,
                      &g_vecZero,0,0,(*(ushort *)(param_1 + 0x123) & 7) << 0xc,0,1,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"plats/ttrain_brake1.wav",param_1[0x124],
                 0x3f4ccccd,0,100);
    }
    param_1[0x122] = 0;
    iVar6 = *param_1;
    *(float *)(iVar6 + 0x20) = local_10 - *(float *)(iVar6 + 8);
    *(float *)(iVar6 + 0x24) = local_c - *(float *)(iVar6 + 0xc);
    *(float *)(iVar6 + 0x28) = local_8 - *(float *)(iVar6 + 0x10);
    iVar6 = *param_1;
    *(undefined4 *)(iVar6 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar6 + 0x60) = DAT_0019f664;
    *(undefined4 *)(iVar6 + 100) = DAT_0019f668;
    iVar6 = *param_1;
    fVar2 = SQRT(*(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
                 *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
                 *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20));
    param_1[0x126] = *(int *)(iVar6 + 0x1f8);
    *(undefined4 *)(iVar6 + 0x1f8) = 0;
    if (fVar2 <= 0.0) {
      DeadEnd__15CFuncTrackTrain();
      return;
    }
    fVar4 = (float)param_1[0x126];
    fVar5 = fVar4 / fVar2;
    iVar6 = *param_1;
    *(float *)(iVar6 + 0x20) = *(float *)(iVar6 + 0x20) * fVar5;
    *(float *)(iVar6 + 0x24) = *(float *)(iVar6 + 0x24) * fVar5;
    *(float *)(iVar6 + 0x28) = fVar5 * *(float *)(iVar6 + 0x28);
    param_1[3] = -0x10000;
    param_1[4] = (int)DeadEnd__15CFuncTrackTrain;
    fVar2 = fVar2 / fVar4 + *(float *)(*param_1 + 0x100);
    pbVar1 = (byte *)(*param_1 + 0x1a6);
    *pbVar1 = *pbVar1 & 0xdf;
  }
  else {
    if (piVar8 != (int *)param_1[0x116]) {
      fVar2 = *(float *)(*param_1 + 0x1f8);
      piVar9 = piVar8;
      if (0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
        piVar9 = (int *)param_1[0x116];
      }
      param_1[0x116] = (int)piVar8;
      iVar6 = *piVar9;
      if (*(int *)(iVar6 + 0x1d4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(iVar6 + 0x1d4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
        iVar6 = *piVar9;
        if ((*(byte *)(iVar6 + 0x1a0) & 2) != 0) {
          *(undefined4 *)(iVar6 + 0x1d4) = 0;
          iVar6 = *piVar9;
        }
      }
      if ((*(byte *)(iVar6 + 0x1a0) & 8) != 0) {
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 2;
      }
      if (((*(byte *)(*param_1 + 0x1a0) & 2) != 0) &&
         (fVar2 = *(float *)(*piVar9 + 0x1f8),
         (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
        *(float *)(*param_1 + 0x1f8) = fVar2;
        (*DAT_0019f794)(2,"TrackTrain %s speed to %4.2f\n",
                        *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                        (double)*(float *)(*param_1 + 0x1f8));
      }
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)Next__15CFuncTrackTrain;
    fVar2 = *(float *)(*param_1 + 0x100) + 0.5;
    pbVar1 = (byte *)(*param_1 + 0x1a6);
    *pbVar1 = *pbVar1 | 0x20;
  }
  *(float *)(*param_1 + 0x104) = fVar2;
  return;
}


