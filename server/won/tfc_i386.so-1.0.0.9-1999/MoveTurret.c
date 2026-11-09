// MoveTurret__11CBaseTurret  @ 00115b60
int MoveTurret__11CBaseTurret(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = 0;
  fVar1 = (float)param_1[0x198];
  fVar2 = (float)param_1[0x19b];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = (float)param_1[0x18c] * 0.1 * fVar3 + (float)param_1[0x198];
    param_1[0x198] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      if ((float)param_1[0x19b] < fVar1) {
LAB_00115bf6:
        param_1[0x198] = param_1[0x19b];
      }
    }
    else {
      fVar1 = (float)param_1[0x198];
      fVar2 = (float)param_1[0x19b];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) goto LAB_00115bf6;
    }
    if (param_1[0x18d] == 0) {
      fVar1 = -(float)param_1[0x198];
    }
    else {
      fVar1 = (float)param_1[0x198];
    }
    SetBoneController__14CBaseAnimatingif(param_1,1,fVar1);
    iVar5 = 1;
  }
  fVar1 = (float)param_1[0x199];
  fVar2 = (float)param_1[0x19c];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
    if (iVar5 != 0) {
      return iVar5;
    }
    param_1[0x18c] = (int)(float)param_1[0x18b];
    return 0;
  }
  fVar3 = 1.0;
  if (fVar2 <= fVar1) {
    fVar3 = -1.0;
  }
  fVar1 = ABS((float)param_1[0x19c] - (float)param_1[0x199]);
  if ((byte)(180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) == 1) {
    fVar1 = 360.0 - fVar1;
    fVar3 = -fVar3;
  }
  if ((byte)(30.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 30.0) << 0xe) >> 8)) == 1) {
    fVar2 = (float)param_1[0x18c];
    fVar4 = (float)(param_1[0x18b] * 10);
    if ((byte)(fVar2 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) == 1) goto LAB_00115d12;
  }
  else {
    fVar2 = (float)param_1[0x18c];
    if ((byte)(45.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 45.0) << 0xe) >> 8)) == 1) {
      fVar2 = (float)param_1[0x18c] - (float)param_1[0x18b];
    }
    else {
LAB_00115d12:
      fVar2 = (float)param_1[0x18b] + (float)param_1[0x18c];
    }
    param_1[0x18c] = (int)fVar2;
  }
  fVar2 = (float)param_1[0x18c] * 0.1 * fVar3 + (float)param_1[0x199];
  param_1[0x199] = (int)fVar2;
  if (0.0 <= fVar2) {
    fVar2 = (float)param_1[0x199];
    if (0x3f < (byte)((360.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == 360.0) << 0xe) >> 8)) - 1))
    goto LAB_00115d85;
    fVar2 = (float)param_1[0x199] - 360.0;
  }
  else {
    fVar2 = fVar2 + 360.0;
  }
  param_1[0x199] = (int)fVar2;
LAB_00115d85:
  if (fVar1 < (float)param_1[0x18b] * 0.05) {
    param_1[0x199] = param_1[0x19c];
  }
  if (param_1[0x18d] == 0) {
    fVar1 = (float)param_1[0x199] - *(float *)(*param_1 + 0x54);
  }
  else {
    fVar1 = (*(float *)(*param_1 + 0x54) - 180.0) - (float)param_1[0x199];
  }
  SetBoneController__14CBaseAnimatingif(param_1,0,fVar1);
  return 1;
}


// MoveTurret__12CTFSentrygun  @ 000eaa50
int MoveTurret__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  float local_10;
  float local_c;
  
  iVar4 = 0;
  fVar1 = (float)param_1[0x188];
  fVar2 = (float)param_1[0x18b];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    fVar3 = 1.0;
    if (fVar2 <= fVar1) {
      fVar3 = -1.0;
    }
    fVar1 = (float)(param_1[0x186] * 5) * 0.1 * fVar3 + (float)param_1[0x188];
    param_1[0x188] = (int)fVar1;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) == 0x40) {
      if ((float)param_1[0x18b] < fVar1) {
LAB_000eaaf1:
        param_1[0x188] = param_1[0x18b];
      }
    }
    else {
      fVar1 = (float)param_1[0x188];
      fVar2 = (float)param_1[0x18b];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) goto LAB_000eaaf1;
    }
    SetBoneController__14CBaseAnimatingif(param_1,1,-(float)param_1[0x188]);
    if (param_1[0x24] == 3) {
      SetBoneController__14CBaseAnimatingif(param_1,2,-(float)param_1[0x188]);
    }
    iVar4 = 1;
  }
  fVar1 = (float)param_1[0x189];
  fVar2 = (float)param_1[0x18c];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
    if (iVar4 != 0) {
      return iVar4;
    }
    param_1[0x187] = (int)(float)param_1[0x186];
    return 0;
  }
  local_c = 1.0;
  if (fVar2 <= fVar1) {
    local_c = -1.0;
  }
  local_10 = ABS((float)param_1[0x18c] - (float)param_1[0x189]);
  bVar5 = (byte)(180.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_10 == 180.0) << 0xe) >> 8)) == 1;
  if (bVar5) {
    local_10 = 360.0 - local_10;
    local_c = -local_c;
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
  if (iVar4 == 0) {
    if ((byte)(30.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_10 == 30.0) << 0xe) >> 8)) == 1) {
      fVar1 = (float)param_1[0x187];
      fVar2 = (float)(param_1[0x186] * 10);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        iVar4 = param_1[0x186];
LAB_000eac83:
        fVar1 = (float)iVar4 + (float)param_1[0x187];
LAB_000eac89:
        param_1[0x187] = (int)fVar1;
      }
    }
    else if ((float)(param_1[0x186] * 5) < (float)param_1[0x187]) {
      fVar1 = (float)param_1[0x187] - (float)param_1[0x186];
      goto LAB_000eac89;
    }
  }
  else if ((byte)(30.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_10 == 30.0) << 0xe) >> 8)) == 1) {
    fVar1 = (float)param_1[0x187];
    fVar2 = (float)(param_1[0x186] * 0x1e);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      iVar4 = param_1[0x186] * 3;
      goto LAB_000eac83;
    }
  }
  param_1[0x189] = (int)((float)param_1[0x187] * 0.1 * local_c + (float)param_1[0x189]);
  if ((byte)((byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_c == -1.0) << 0xe) >> 8)) == 0x40) {
    if ((!bVar5) && ((float)param_1[0x189] < (float)param_1[0x18c])) goto LAB_000ead32;
    if (bVar5) {
      fVar1 = (float)param_1[0x18c];
      fVar2 = (float)param_1[0x189];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) goto LAB_000ead32;
    }
  }
  else {
    if (!bVar5) {
      fVar1 = (float)param_1[0x18c];
      fVar2 = (float)param_1[0x189];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) goto LAB_000ead32;
    }
    if ((!bVar5) || ((float)param_1[0x18c] <= (float)param_1[0x189])) goto LAB_000ead3e;
LAB_000ead32:
    param_1[0x189] = param_1[0x18c];
  }
LAB_000ead3e:
  if (0.0 <= (float)param_1[0x189]) {
    fVar1 = (float)param_1[0x189];
    if (0x3f < (byte)((360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1))
    goto LAB_000ead88;
    fVar1 = (float)param_1[0x189] - 360.0;
  }
  else {
    fVar1 = (float)param_1[0x189] + 360.0;
  }
  param_1[0x189] = (int)fVar1;
LAB_000ead88:
  if (local_10 < (float)param_1[0x186] * 0.05) {
    param_1[0x189] = param_1[0x18c];
  }
  SetBoneController__14CBaseAnimatingif
            (param_1,0,(float)param_1[0x189] - *(float *)(*param_1 + 0x54));
  return 1;
}


