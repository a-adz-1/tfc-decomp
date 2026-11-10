// MoveTurret__11CBaseTurret  @ 0011c104
int MoveTurret__11CBaseTurret(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  iVar4 = 0;
  fVar1 = (float)param_1[0x1bb];
  fVar2 = (float)param_1[0x1be];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = fVar3 * 0.1 * (float)param_1[0x1ae] + fVar1;
    param_1[0x1bb] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_0011c199:
        param_1[0x1bb] = (int)fVar2;
      }
    }
    else if (fVar1 < fVar2) goto LAB_0011c199;
    if (param_1[0x1b0] == 0) {
      fVar1 = -(float)param_1[0x1bb];
    }
    else {
      fVar1 = (float)param_1[0x1bb];
    }
    SetBoneController__14CBaseAnimatingif(param_1,1,fVar1);
    iVar4 = 1;
  }
  fVar1 = (float)param_1[0x1bc];
  fVar2 = (float)param_1[0x1bf];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
    if (iVar4 != 0) {
      return iVar4;
    }
    param_1[0x1af] = (int)(float)param_1[0x1ae];
    return 0;
  }
  fVar3 = 1.0;
  if (fVar2 <= fVar1) {
    fVar3 = -1.0;
  }
  fVar1 = ABS(fVar2 - fVar1);
  if (180.0 < fVar1) {
    fVar3 = -fVar3;
    fVar1 = 360.0 - fVar1;
  }
  if (fVar1 <= 30.0) {
    fVar2 = (float)param_1[0x1af];
    if (fVar2 <= 45.0) {
      fVar2 = fVar2 + (float)param_1[0x1ae];
    }
    else {
      fVar2 = fVar2 - (float)param_1[0x1ae];
    }
LAB_0011c296:
    param_1[0x1af] = (int)fVar2;
  }
  else {
    fVar2 = (float)param_1[0x1af];
    if (fVar2 < (float)(param_1[0x1ae] * 10)) {
      fVar2 = fVar2 + (float)param_1[0x1ae];
      goto LAB_0011c296;
    }
  }
  fVar2 = fVar2 * fVar3 * 0.1 + (float)param_1[0x1bc];
  param_1[0x1bc] = (int)fVar2;
  if ((byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (fVar2 < 360.0) goto LAB_0011c2f1;
    fVar2 = fVar2 - 360.0;
  }
  else {
    fVar2 = fVar2 + 360.0;
  }
  param_1[0x1bc] = (int)fVar2;
LAB_0011c2f1:
  fVar2 = (float)param_1[0x1ae] * 0.05;
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    param_1[0x1bc] = param_1[0x1bf];
  }
  if (param_1[0x1b0] == 0) {
    fVar1 = (float)param_1[0x1bc] - *(float *)(*param_1 + 0x54);
  }
  else {
    fVar1 = (*(float *)(*param_1 + 0x54) - 180.0) - (float)param_1[0x1bc];
  }
  SetBoneController__14CBaseAnimatingif(param_1,0,fVar1);
  return 1;
}


// MoveTurret__12CTFSentrygun  @ 000ee7e4
int MoveTurret__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  int iVar6;
  
  iVar6 = 0;
  fVar1 = (float)param_1[0x1ac];
  fVar2 = (float)param_1[0x1af];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = fVar3 * 0.1 * (float)(param_1[0x1aa] * 5) + fVar1;
    param_1[0x1ac] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_000ee885:
        param_1[0x1ac] = (int)fVar2;
      }
    }
    else if (fVar1 < fVar2) goto LAB_000ee885;
    SetBoneController__14CBaseAnimatingif(param_1,1,-(float)param_1[0x1ac]);
    if (param_1[0x23] == 3) {
      SetBoneController__14CBaseAnimatingif(param_1,2,-(float)param_1[0x1ac]);
    }
    iVar6 = 1;
  }
  fVar1 = (float)param_1[0x1ad];
  fVar2 = (float)param_1[0x1b0];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
    if (iVar6 != 0) {
      return iVar6;
    }
    param_1[0x1ab] = (int)(float)param_1[0x1aa];
    return 0;
  }
  fVar3 = 1.0;
  if (fVar2 <= fVar1) {
    fVar3 = -1.0;
  }
  fVar1 = ABS(fVar2 - fVar1);
  bVar4 = 180.0 < fVar1;
  if (bVar4) {
    fVar3 = -fVar3;
    fVar1 = 360.0 - fVar1;
  }
  iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
  if (iVar6 == 0) {
    if (fVar1 <= 30.0) {
      fVar2 = (float)param_1[0x1ab];
      fVar5 = (float)(param_1[0x1aa] * 5);
      if (0x3f < (byte)((fVar2 < fVar5 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar5)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar5) << 0xe) >> 8)) - 1)) {
        fVar2 = fVar2 - (float)param_1[0x1aa];
        goto LAB_000ee9fe;
      }
    }
    else if ((float)param_1[0x1ab] < (float)(param_1[0x1aa] * 10)) {
      fVar2 = (float)param_1[0x1ab] + (float)param_1[0x1aa];
LAB_000ee9fe:
      param_1[0x1ab] = (int)fVar2;
    }
  }
  else if (30.0 < fVar1) {
    if ((float)param_1[0x1ab] < (float)(param_1[0x1aa] * 0x1e)) {
      fVar2 = (float)param_1[0x1ab] + (float)(param_1[0x1aa] * 3);
      goto LAB_000ee9fe;
    }
  }
  fVar2 = fVar3 * 0.1 * (float)param_1[0x1ab] + (float)param_1[0x1ad];
  param_1[0x1ad] = (int)fVar2;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == -1.0) << 0xe) >> 8)) == 0x40) {
    if (((!bVar4) && (fVar3 = (float)param_1[0x1b0], fVar2 < fVar3)) ||
       ((bVar4 && (fVar3 = (float)param_1[0x1b0], fVar3 < fVar2)))) {
LAB_000eeaa3:
      param_1[0x1ad] = (int)fVar3;
    }
  }
  else if (((!bVar4) &&
           (fVar3 = (float)param_1[0x1b0],
           (byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) == 1)) ||
          ((bVar4 && (fVar3 = (float)param_1[0x1b0],
                     0x3f < (byte)((fVar3 < fVar2 |
                                    (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8)
                                   | (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1))))
          ) goto LAB_000eeaa3;
  fVar2 = (float)param_1[0x1ad];
  if ((byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (fVar2 < 360.0) goto LAB_000eeaed;
    fVar2 = fVar2 - 360.0;
  }
  else {
    fVar2 = fVar2 + 360.0;
  }
  param_1[0x1ad] = (int)fVar2;
LAB_000eeaed:
  fVar2 = (float)param_1[0x1aa] * 0.05;
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    param_1[0x1ad] = param_1[0x1b0];
  }
  SetBoneController__14CBaseAnimatingif
            (param_1,0,(float)param_1[0x1ad] - *(float *)(*param_1 + 0x54));
  return 1;
}


