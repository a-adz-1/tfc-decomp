// MoveTurret__11CBaseTurret  @ 00118958
int MoveTurret__11CBaseTurret(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  iVar4 = 0;
  fVar1 = (float)param_1[0x1b7];
  fVar2 = (float)param_1[0x1ba];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = fVar3 * 0.1 * (float)param_1[0x1aa] + (float)param_1[0x1b7];
    param_1[0x1b7] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      fVar2 = (float)param_1[0x1ba];
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_00118a05:
        param_1[0x1b7] = param_1[0x1ba];
      }
    }
    else if ((float)param_1[0x1b7] < (float)param_1[0x1ba]) goto LAB_00118a05;
    if (param_1[0x1ac] == 0) {
      fVar1 = -(float)param_1[0x1b7];
    }
    else {
      fVar1 = (float)param_1[0x1b7];
    }
    SetBoneController__14CBaseAnimatingif(param_1,1,fVar1);
    iVar4 = 1;
  }
  fVar1 = (float)param_1[0x1b8];
  fVar2 = (float)param_1[0x1bb];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
    if (iVar4 != 0) {
      return iVar4;
    }
    param_1[0x1ab] = (int)(float)param_1[0x1aa];
    return 0;
  }
  fVar3 = 1.0;
  if (fVar2 <= fVar1) {
    fVar3 = -1.0;
  }
  fVar1 = ABS((float)param_1[0x1bb] - (float)param_1[0x1b8]);
  if (180.0 < fVar1) {
    fVar1 = 360.0 - fVar1;
    fVar3 = -fVar3;
  }
  if ((byte)(30.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 30.0) << 0xe) >> 8)) == 1) {
    if ((float)param_1[0x1ab] < (float)(param_1[0x1aa] * 10)) goto LAB_00118b07;
  }
  else {
    if ((float)param_1[0x1ab] <= 45.0) {
LAB_00118b07:
      fVar2 = (float)param_1[0x1aa] + (float)param_1[0x1ab];
    }
    else {
      fVar2 = (float)param_1[0x1ab] - (float)param_1[0x1aa];
    }
    param_1[0x1ab] = (int)fVar2;
  }
  fVar2 = fVar3 * 0.1 * (float)param_1[0x1ab] + (float)param_1[0x1b8];
  param_1[0x1b8] = (int)fVar2;
  if ((byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    if ((float)param_1[0x1b8] < 360.0) goto LAB_00118b80;
    fVar2 = (float)param_1[0x1b8] - 360.0;
  }
  else {
    fVar2 = fVar2 + 360.0;
  }
  param_1[0x1b8] = (int)fVar2;
LAB_00118b80:
  fVar2 = (float)param_1[0x1aa] * 0.05;
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    param_1[0x1b8] = param_1[0x1bb];
  }
  if (param_1[0x1ac] == 0) {
    fVar1 = (float)param_1[0x1b8] - *(float *)(*param_1 + 0x54);
  }
  else {
    fVar1 = (*(float *)(*param_1 + 0x54) - 180.0) - (float)param_1[0x1b8];
  }
  SetBoneController__14CBaseAnimatingif(param_1,0,fVar1);
  return 1;
}


// MoveTurret__12CTFSentrygun  @ 000ece18
int MoveTurret__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  float local_c;
  float local_8;
  
  iVar5 = 0;
  fVar1 = (float)param_1[0x1a8];
  fVar2 = (float)param_1[0x1ab];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = fVar3 * 0.1 * (float)(param_1[0x1a6] * 5) + (float)param_1[0x1a8];
    param_1[0x1a8] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      fVar2 = (float)param_1[0x1ab];
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_000eced0:
        param_1[0x1a8] = param_1[0x1ab];
      }
    }
    else if ((float)param_1[0x1a8] < (float)param_1[0x1ab]) goto LAB_000eced0;
    SetBoneController__14CBaseAnimatingif(param_1,1,-(float)param_1[0x1a8]);
    if (param_1[0x23] == 3) {
      SetBoneController__14CBaseAnimatingif(param_1,2,-(float)param_1[0x1a8]);
    }
    iVar5 = 1;
  }
  fVar1 = (float)param_1[0x1a9];
  fVar2 = (float)param_1[0x1ac];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) goto LAB_000ed1b6;
  local_8 = 1.0;
  if (fVar2 <= (float)param_1[0x1a9]) {
    local_8 = -1.0;
  }
  local_c = ABS((float)param_1[0x1ac] - (float)param_1[0x1a9]);
  bVar4 = 180.0 < local_c;
  if (bVar4) {
    local_c = 360.0 - local_c;
    local_8 = -local_8;
  }
  iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
  if (iVar5 == 0) {
    if (local_c <= 30.0) {
      fVar1 = (float)param_1[0x1a7];
      fVar2 = (float)(param_1[0x1a6] * 5);
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        fVar1 = (float)param_1[0x1a7] - (float)param_1[0x1a6];
        goto LAB_000ed064;
      }
    }
    else if ((float)param_1[0x1a7] < (float)(param_1[0x1a6] * 10)) {
      iVar5 = param_1[0x1a6];
      goto LAB_000ed05e;
    }
  }
  else if ((30.0 < local_c) && ((float)param_1[0x1a7] < (float)(param_1[0x1a6] * 0x1e))) {
    iVar5 = param_1[0x1a6] * 3;
LAB_000ed05e:
    fVar1 = (float)iVar5 + (float)param_1[0x1a7];
LAB_000ed064:
    param_1[0x1a7] = (int)fVar1;
  }
  param_1[0x1a9] = (int)(local_8 * 0.1 * (float)param_1[0x1a7] + (float)param_1[0x1a9]);
  if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_8 == -1.0) << 0xe) >> 8)) == 0x40) {
    if (((!bVar4) && ((float)param_1[0x1a9] < (float)param_1[0x1ac])) ||
       ((bVar4 && ((float)param_1[0x1ac] < (float)param_1[0x1a9])))) {
LAB_000ed10f:
      param_1[0x1a9] = param_1[0x1ac];
    }
  }
  else {
    if (!bVar4) {
      fVar1 = (float)param_1[0x1ac];
      fVar2 = (float)param_1[0x1a9];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) goto LAB_000ed10f;
    }
    if (bVar4) {
      fVar1 = (float)param_1[0x1ac];
      fVar2 = (float)param_1[0x1a9];
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
      goto LAB_000ed10f;
    }
  }
  fVar1 = (float)param_1[0x1a9];
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (360.0 <= (float)param_1[0x1a9]) {
      fVar1 = (float)param_1[0x1a9] - 360.0;
      goto LAB_000ed15d;
    }
  }
  else {
    fVar1 = (float)param_1[0x1a9] + 360.0;
LAB_000ed15d:
    param_1[0x1a9] = (int)fVar1;
  }
  fVar1 = (float)param_1[0x1a6] * 0.05;
  if (0x3f < (byte)((fVar1 < local_c |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_c)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == local_c) << 0xe) >> 8)) - 1)) {
    param_1[0x1a9] = param_1[0x1ac];
  }
  SetBoneController__14CBaseAnimatingif
            (param_1,0,(float)param_1[0x1a9] - *(float *)(*param_1 + 0x54));
  iVar5 = 1;
LAB_000ed1b6:
  if (iVar5 == 0) {
    param_1[0x1a7] = (int)(float)param_1[0x1a6];
  }
  return iVar5;
}


