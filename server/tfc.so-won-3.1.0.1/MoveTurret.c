// MoveTurret__11CBaseTurret  @ 00108e8c
int MoveTurret__11CBaseTurret(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  iVar4 = 0;
  fVar1 = (float)param_1[0x19b];
  fVar2 = (float)param_1[0x19e];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = fVar3 * 0.1 * (float)param_1[0x18e] + (float)param_1[0x19b];
    param_1[0x19b] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      fVar2 = (float)param_1[0x19e];
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_00108f39:
        param_1[0x19b] = param_1[0x19e];
      }
    }
    else if ((float)param_1[0x19b] < (float)param_1[0x19e]) goto LAB_00108f39;
    if (param_1[400] == 0) {
      fVar1 = -(float)param_1[0x19b];
    }
    else {
      fVar1 = (float)param_1[0x19b];
    }
    SetBoneController__14CBaseAnimatingif(param_1,1,fVar1);
    iVar4 = 1;
  }
  fVar1 = (float)param_1[0x19c];
  fVar2 = (float)param_1[0x19f];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
    if (iVar4 != 0) {
      return iVar4;
    }
    param_1[399] = (int)(float)param_1[0x18e];
    return 0;
  }
  fVar3 = 1.0;
  if (fVar2 <= fVar1) {
    fVar3 = -1.0;
  }
  fVar1 = ABS((float)param_1[0x19f] - (float)param_1[0x19c]);
  if (180.0 < fVar1) {
    fVar1 = 360.0 - fVar1;
    fVar3 = -fVar3;
  }
  if ((byte)(30.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 30.0) << 0xe) >> 8)) == 1) {
    if ((float)param_1[399] < (float)(param_1[0x18e] * 10)) goto LAB_0010903b;
  }
  else {
    if ((float)param_1[399] <= 45.0) {
LAB_0010903b:
      fVar2 = (float)param_1[0x18e] + (float)param_1[399];
    }
    else {
      fVar2 = (float)param_1[399] - (float)param_1[0x18e];
    }
    param_1[399] = (int)fVar2;
  }
  fVar2 = fVar3 * 0.1 * (float)param_1[399] + (float)param_1[0x19c];
  param_1[0x19c] = (int)fVar2;
  if ((byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    if ((float)param_1[0x19c] < 360.0) goto LAB_001090b4;
    fVar2 = (float)param_1[0x19c] - 360.0;
  }
  else {
    fVar2 = fVar2 + 360.0;
  }
  param_1[0x19c] = (int)fVar2;
LAB_001090b4:
  fVar2 = (float)param_1[0x18e] * 0.05;
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    param_1[0x19c] = param_1[0x19f];
  }
  if (param_1[400] == 0) {
    fVar1 = (float)param_1[0x19c] - *(float *)(*param_1 + 0x54);
  }
  else {
    fVar1 = (*(float *)(*param_1 + 0x54) - 180.0) - (float)param_1[0x19c];
  }
  SetBoneController__14CBaseAnimatingif(param_1,0,fVar1);
  return 1;
}


// MoveTurret__12CTFSentrygun  @ 000e042c
int MoveTurret__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  float fStack_c;
  float fStack_8;
  
  iVar5 = 0;
  fVar1 = (float)param_1[0x18c];
  fVar2 = (float)param_1[399];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = fVar3 * 0.1 * (float)(param_1[0x18a] * 5) + (float)param_1[0x18c];
    param_1[0x18c] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      fVar2 = (float)param_1[399];
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_000e04e4:
        param_1[0x18c] = param_1[399];
      }
    }
    else if ((float)param_1[0x18c] < (float)param_1[399]) goto LAB_000e04e4;
    SetBoneController__14CBaseAnimatingif(param_1,1,-(float)param_1[0x18c]);
    if (param_1[0x23] == 3) {
      SetBoneController__14CBaseAnimatingif(param_1,2,-(float)param_1[0x18c]);
    }
    iVar5 = 1;
  }
  fVar1 = (float)param_1[0x18d];
  fVar2 = (float)param_1[400];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) goto LAB_000e07ca;
  fStack_8 = 1.0;
  if (fVar2 <= (float)param_1[0x18d]) {
    fStack_8 = -1.0;
  }
  fStack_c = ABS((float)param_1[400] - (float)param_1[0x18d]);
  bVar4 = 180.0 < fStack_c;
  if (bVar4) {
    fStack_c = 360.0 - fStack_c;
    fStack_8 = -fStack_8;
  }
  iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
  if (iVar5 == 0) {
    if (fStack_c <= 30.0) {
      fVar1 = (float)param_1[0x18b];
      fVar2 = (float)(param_1[0x18a] * 5);
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        fVar1 = (float)param_1[0x18b] - (float)param_1[0x18a];
        goto LAB_000e0678;
      }
    }
    else if ((float)param_1[0x18b] < (float)(param_1[0x18a] * 10)) {
      iVar5 = param_1[0x18a];
      goto LAB_000e0672;
    }
  }
  else if ((30.0 < fStack_c) && ((float)param_1[0x18b] < (float)(param_1[0x18a] * 0x1e))) {
    iVar5 = param_1[0x18a] * 3;
LAB_000e0672:
    fVar1 = (float)iVar5 + (float)param_1[0x18b];
LAB_000e0678:
    param_1[0x18b] = (int)fVar1;
  }
  param_1[0x18d] = (int)(fStack_8 * 0.1 * (float)param_1[0x18b] + (float)param_1[0x18d]);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_8) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_8 == -1.0) << 0xe) >> 8)) == 0x40) {
    if (((!bVar4) && ((float)param_1[0x18d] < (float)param_1[400])) ||
       ((bVar4 && ((float)param_1[400] < (float)param_1[0x18d])))) {
LAB_000e0723:
      param_1[0x18d] = param_1[400];
    }
  }
  else {
    if (!bVar4) {
      fVar1 = (float)param_1[400];
      fVar2 = (float)param_1[0x18d];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) goto LAB_000e0723;
    }
    if (bVar4) {
      fVar1 = (float)param_1[400];
      fVar2 = (float)param_1[0x18d];
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
      goto LAB_000e0723;
    }
  }
  fVar1 = (float)param_1[0x18d];
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (360.0 <= (float)param_1[0x18d]) {
      fVar1 = (float)param_1[0x18d] - 360.0;
      goto LAB_000e0771;
    }
  }
  else {
    fVar1 = (float)param_1[0x18d] + 360.0;
LAB_000e0771:
    param_1[0x18d] = (int)fVar1;
  }
  fVar1 = (float)param_1[0x18a] * 0.05;
  if (0x3f < (byte)((fVar1 < fStack_c |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fStack_c)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == fStack_c) << 0xe) >> 8)) - 1)) {
    param_1[0x18d] = param_1[400];
  }
  SetBoneController__14CBaseAnimatingif
            (param_1,0,(float)param_1[0x18d] - *(float *)(*param_1 + 0x54));
  iVar5 = 1;
LAB_000e07ca:
  if (iVar5 == 0) {
    param_1[0x18b] = (int)(float)param_1[0x18a];
  }
  return iVar5;
}


