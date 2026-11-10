// TeamFortress_Build__11CBasePlayeri  @ 000a67d4
void TeamFortress_Build__11CBasePlayeri(float *param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  float **ppfVar6;
  float *pfVar7;
  float *pfStack_54;
  float *pfStack_50;
  float local_3c;
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
  
  pfStack_50 = (float *)((int)*param_1 + 0x50);
  pfStack_54 = (float *)0xa67fa;
  UTIL_MakeAimVectors__FRC6Vector();
  local_28 = gpGlobals[10];
  local_24 = gpGlobals[0xb];
  fVar1 = SQRT(local_24 * local_24 + local_28 * local_28);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_28 = 0.0;
    local_24 = 0.0;
    local_20 = 1.0;
  }
  else {
    local_20 = 0.0;
    local_28 = local_28 * (1.0 / fVar1);
    local_24 = (1.0 / fVar1) * local_24;
  }
  local_1c = local_28 * 64.0;
  local_18 = local_24 * 64.0;
  local_14 = local_20 * 64.0;
  local_2c = *(float *)((int)*param_1 + 8) + local_1c;
  local_28 = *(float *)((int)*param_1 + 0xc) + local_18;
  local_24 = *(float *)((int)*param_1 + 0x10) + local_14;
  local_10 = (float)(int)ROUND(local_2c);
  local_c = (float)(int)ROUND(local_28);
  local_8 = local_24;
  if ((byte)((byte)((ushort)((ushort)NAN(param_1[0x44]) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1[0x44] == 15.0) << 0xe) >> 8)) == 0x40) {
    pfStack_50 = param_1;
    pfStack_54 = (float *)0xa692c;
    ResetMenu__11CBasePlayer();
    *(undefined4 *)((int)*param_1 + 0x184) = 0;
  }
  if (param_2 == 1) {
    fVar1 = param_1[0x53];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      pcVar4 = "#Build_onedispenser";
      goto LAB_000a6a16;
    }
    if (99 < (int)param_1[0x37]) {
      local_2c = local_10;
      local_28 = local_c;
      local_24 = local_8;
      fVar1 = *param_1;
      local_20 = *(float *)((int)fVar1 + 0x74);
      local_1c = *(float *)((int)fVar1 + 0x78);
      local_18 = *(float *)((int)fVar1 + 0x7c);
      pfStack_50 = param_1;
      pfStack_54 = &local_20;
      uVar2 = CreateDispenser__12CTFDispenserG6VectorT1P11CBaseEntity(&local_2c);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,uVar2);
      local_3c = 2.0;
LAB_000a6a76:
      pfVar7 = param_1 + 0x4e;
      pfStack_50 = param_1;
      pfStack_54 = pfVar7;
      pfStack_54 = (float *)__rf__7EHANDLE();
      iVar3 = CheckArea__11CBaseEntityP11CBaseEntity();
      if (iVar3 == 0) {
        if ((*(byte *)((int)*param_1 + 0x1a5) & 2) != 0) {
          param_1[0x1a] = 1.4013e-45;
          fVar1 = *gpGlobals;
          *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
          param_1[99] = fVar1 + 5.0;
          pfStack_50 = param_1;
          pfStack_54 = (float *)0xa6b3a;
          TeamFortress_SetSpeed__11CBasePlayer();
          pfStack_54 = (float *)param_1[0x237];
          if (pfStack_54 != (float *)0x0) {
            pfStack_50 = (float *)0x0;
            (**(code **)((int)pfStack_54[0x115] + 0x128))();
          }
          pfStack_50 = (float *)0xb;
          pfStack_54 = param_1;
          piVar5 = (int *)CreateTimer__11CBaseEntityi();
          piVar5[3] = -0x10000;
          piVar5[4] = (int)Timer_FinishedBuilding__11CBaseEntity;
          *(float *)(*piVar5 + 0x104) = local_3c + *gpGlobals;
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)((int)*param_1 + 0x208),6,"weapons/building.wav",0x3f7ae148,
                     0x3f4ccccd,0,0x7d);
          return;
        }
        pfStack_50 = (float *)0x0;
        pfStack_54 = (float *)0x0;
        ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Build_air",0,0);
        uVar2 = __opP11CBaseEntity__7EHANDLE(pfVar7);
        UTIL_Remove__FP11CBaseEntity(uVar2);
        ppfVar6 = (float **)&stack0xffffffb4;
      }
      else {
        if (iVar3 == 2) {
          pcVar4 = "#Build_nobuild";
        }
        else {
          pcVar4 = "#Build_noroom";
        }
        pfStack_50 = (float *)0x0;
        pfStack_54 = (float *)0x0;
        ClientPrint__FP9entvars_siPCcN42(*param_1,4,pcVar4,0,0);
        pfStack_54 = (float *)0xa6ac6;
        pfStack_50 = pfVar7;
        pfStack_54 = (float *)__opP11CBaseEntity__7EHANDLE();
        ppfVar6 = &pfStack_54;
        UTIL_Remove__FP11CBaseEntity();
      }
      *(undefined4 *)((int)ppfVar6 + -4) = 0;
      *(float **)((int)ppfVar6 + -8) = pfVar7;
      *(undefined4 *)((int)ppfVar6 + -0xc) = 0xa6b09;
      __as__7EHANDLEP11CBaseEntity();
      return;
    }
  }
  else {
    if (param_2 != 2) {
      return;
    }
    fVar1 = param_1[0x54];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      pcVar4 = "#Build_onesentry";
      goto LAB_000a6a16;
    }
    if (0x81 < (int)param_1[0x37]) {
      local_2c = local_10;
      local_28 = local_c;
      local_24 = local_8;
      fVar1 = *param_1;
      local_20 = *(float *)((int)fVar1 + 0x74);
      local_1c = *(float *)((int)fVar1 + 0x78);
      local_18 = *(float *)((int)fVar1 + 0x7c);
      pfStack_50 = param_1;
      pfStack_54 = &local_20;
      uVar2 = CreateSentryBase__16CTFSentrygunBaseG6VectorT1P11CBaseEntity(&local_2c);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,uVar2);
      local_3c = 5.0;
      goto LAB_000a6a76;
    }
  }
  pcVar4 = "#Build_notenoughmetal";
LAB_000a6a16:
  pfStack_50 = (float *)0x0;
  pfStack_54 = (float *)0x0;
  ClientPrint__FP9entvars_siPCcN42(*param_1,4,pcVar4,0,0);
  return;
}


// TeamFortress_CalcEMPDmgRad__11CBaseEntityRfT1  @ 0008e930
void TeamFortress_CalcEMPDmgRad__11CBaseEntityRfT1(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  if (*(char *)(*param_1 + 0x118) < '\0') {
    *param_2 = 0.0;
    *param_3 = 0.0;
  }
  else {
    fVar1 = (float)param_1[0x37] * 1.5 + (float)param_1[0x39] * 1.5 + (float)param_1[0x33] * 0.75;
    *param_2 = fVar1;
    *param_3 = fVar1;
  }
  return;
}


// TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1  @ 000e4038
void TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = (float)param_1[0x39] * 1.5 + (float)param_1[0x33] * 0.75;
  *param_3 = fVar1;
  if (*(int *)(*param_1 + 0x20c) != 9) {
    *param_3 = (float)param_1[0x37] * 1.5 + fVar1;
  }
  *param_2 = *param_3;
  return;
}


// TeamFortress_CheckClassStats__11CBasePlayer  @ 000e2174
void TeamFortress_CheckClassStats__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *param_1;
  if ((float)param_1[0x3b] < *(float *)(iVar3 + 0x1b8)) {
    *(int *)(iVar3 + 0x1b8) = param_1[0x3b];
    iVar3 = *param_1;
  }
  if ((float)param_1[0x3c] < *(float *)(iVar3 + 0x1bc)) {
    *(int *)(iVar3 + 0x1bc) = param_1[0x3c];
    iVar3 = *param_1;
  }
  fVar1 = *(float *)(iVar3 + 0x1b8);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(iVar3 + 0x1b8) = 0;
    iVar3 = *param_1;
  }
  fVar1 = *(float *)(iVar3 + 0x1bc);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(iVar3 + 0x1bc) = 0;
  }
  iVar3 = param_1[0x30];
  iVar2 = param_1[0x33];
  if (iVar3 < param_1[0x33]) {
    param_1[0x33] = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    param_1[0x33] = 0;
  }
  iVar3 = param_1[0x34];
  iVar2 = param_1[0x35];
  if (iVar3 < param_1[0x35]) {
    param_1[0x35] = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    param_1[0x35] = 0;
  }
  iVar3 = param_1[0x38];
  iVar2 = param_1[0x39];
  if (iVar3 < param_1[0x39]) {
    param_1[0x39] = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    param_1[0x39] = 0;
  }
  iVar3 = param_1[0x36];
  iVar2 = param_1[0x37];
  if (iVar3 < param_1[0x37]) {
    param_1[0x37] = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    param_1[0x37] = 0;
  }
  iVar3 = param_1[0x2e];
  iVar2 = param_1[0x2f];
  if (iVar3 < param_1[0x2f]) {
    param_1[0x2f] = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    param_1[0x2f] = 0;
  }
  iVar3 = param_1[0x32];
  iVar2 = param_1[0x31];
  if (iVar3 < param_1[0x31]) {
    param_1[0x31] = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    param_1[0x31] = 0;
  }
  if (param_1[0x11] < 0) {
    param_1[0x11] = 0;
  }
  if (param_1[0x12] < 0) {
    param_1[0x12] = 0;
  }
  if (4 < param_1[0x11]) {
    param_1[0x11] = 4;
  }
  if (4 < param_1[0x12]) {
    param_1[0x12] = 4;
  }
  if ((param_1[0x13] == 3) && (2 < param_1[0x11])) {
    param_1[0x11] = 2;
  }
  if ((param_1[0x14] == 3) && (2 < param_1[0x12])) {
    param_1[0x12] = 2;
  }
  if ((param_1[0x13] == 4) && (2 < param_1[0x11])) {
    param_1[0x11] = 2;
  }
  if ((param_1[0x14] == 4) && (2 < param_1[0x12])) {
    param_1[0x12] = 2;
  }
  if ((param_1[0x13] == 2) && (3 < param_1[0x11])) {
    param_1[0x11] = 3;
  }
  if ((param_1[0x14] == 2) && (3 < param_1[0x12])) {
    param_1[0x12] = 3;
  }
  if ((param_1[0x13] == 9) && (3 < param_1[0x11])) {
    param_1[0x11] = 3;
  }
  if ((param_1[0x14] == 9) && (3 < param_1[0x12])) {
    param_1[0x12] = 3;
  }
  iVar3 = *param_1;
  if ((*(float *)(iVar3 + 0x1b0) < *(float *)(iVar3 + 0x160)) &&
     ((*(byte *)((int)param_1 + 0x8a) & 1) == 0)) {
    *(float *)(iVar3 + 0x160) = *(float *)(iVar3 + 0x1b0);
    iVar3 = *param_1;
  }
  fVar1 = *(float *)(iVar3 + 0x160);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(iVar3 + 0x160) = 0;
  }
  uVar4 = param_1[0x22] & 0xffff1fff;
  param_1[0x22] = uVar4;
  fVar1 = *(float *)(*param_1 + 0x1b8);
  if (fVar1 < 0.8) {
    if (fVar1 < 0.6) {
      if (fVar1 < 0.3) {
        return;
      }
      uVar4 = uVar4 | 0x2000;
    }
    else {
      uVar4 = uVar4 | 0x4000;
    }
    param_1[0x22] = uVar4;
    return;
  }
  FUN_000e2452();
  return;
}


// TeamFortress_Concuss__11CBaseEntityP9entvars_s  @ 00112828
void TeamFortress_Concuss__11CBaseEntityP9entvars_s(void)

{
  return;
}


// TeamFortress_Concuss__11CBasePlayerP9entvars_s  @ 000e3fd8
void TeamFortress_Concuss__11CBasePlayerP9entvars_s(int *param_1)

{
  param_1[0x288] = 100;
  param_1[0x28a] = 100;
  param_1[0x28b] = *gpGlobals;
  param_1[0x28c] = 0x41700000;
  if (*(int *)(*param_1 + 0x20c) == 5) {
    param_1[0x28c] = 0x40e00000;
  }
  return;
}


// TeamFortress_DetpackStop__11CBasePlayer  @ 0009ab54
void TeamFortress_DetpackStop__11CBasePlayer(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FindTimer__11CBaseEntityi(param_1,9);
  if (iVar1 != 0) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Detpack_retrieve",0,0,0,0);
    param_1[0x31] = param_1[0x31] + 1;
    dremove__FP11CBaseEntity(iVar1);
    *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) & 0xfe;
    param_1[0x1b] = 0;
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    (**(code **)(*(int *)(param_1[0x237] + 0x454) + 0x120))(param_1[0x237]);
  }
  return;
}


// TeamFortress_Discard__11CBasePlayer  @ 0010786c
void TeamFortress_Discard__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  local_3c = 0;
  local_40 = 0;
  local_44 = 0;
  local_48 = 0;
  switch(*(undefined4 *)(*param_1 + 0x20c)) {
  case 1:
  case 8:
    local_40 = param_1[0x39];
    break;
  case 2:
  case 5:
    local_40 = param_1[0x39];
    local_44 = param_1[0x37];
    break;
  case 3:
  case 4:
    local_44 = param_1[0x37];
    goto LAB_00107923;
  case 6:
    local_40 = param_1[0x39];
LAB_00107923:
    local_3c = param_1[0x35];
    break;
  case 7:
    local_3c = param_1[0x35];
    break;
  case 9:
    local_40 = param_1[0x39];
  }
  param_1[0x35] = param_1[0x35] - local_3c;
  param_1[0x39] = param_1[0x39] - local_40;
  iVar5 = param_1[0x37];
  param_1[0x37] = iVar5 - local_44;
  if (*(int *)(*param_1 + 0x20c) != 9) goto LAB_00107cac;
  iVar8 = 2;
  if (local_3c < 0x14) {
    iVar8 = 3;
  }
  if (local_40 < 10) {
    iVar8 = iVar8 + 1;
  }
  fVar2 = (float)(int)ROUND(ROUND((double)(iVar5 - local_44) / (double)iVar8));
  fVar1 = ROUND(fVar2 * 0.5);
  if ((byte)((fVar1 < 20.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 20.0) << 0xe) >> 8)) - 1) < 0x40) {
    local_48 = (int)ROUND(ROUND(fVar2 * 0.5));
    if (local_48 != 0) goto LAB_00107a63;
  }
  else {
    local_48 = 0x14;
LAB_00107a63:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_shells",0,0,0,0);
    param_1[0x37] = param_1[0x37] + local_48 * -2;
  }
  fVar1 = ROUND(fVar2 * 0.5);
  if ((byte)((fVar1 < 10.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1) < 0x40) {
    local_44 = (int)ROUND(ROUND(fVar2 * 0.5));
    if (local_44 != 0) goto LAB_00107b07;
  }
  else {
    local_44 = 10;
LAB_00107b07:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_cells",0,0,0,0);
    param_1[0x37] = param_1[0x37] + local_44 * -2;
  }
  if (local_3c < 0x14) {
    fVar1 = (float)(0x14 - local_3c);
    if (ROUND(fVar2) + (float)local_3c <= fVar1) {
      fVar1 = ROUND(fVar2) + (float)local_3c;
    }
    iVar5 = (int)ROUND(fVar1);
    if (iVar5 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_nails",0,0,0,0);
      param_1[0x37] = param_1[0x37] - iVar5;
    }
    local_3c = local_3c + iVar5;
  }
  if (local_40 < 10) {
    fVar1 = (float)(10 - local_40);
    if (ROUND(fVar2 * 0.5) + (float)local_40 <= fVar1) {
      fVar1 = ROUND(fVar2 * 0.5) + (float)local_40;
    }
    iVar5 = (int)ROUND(fVar1);
    if (iVar5 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_rockets",0,0,0,0);
      param_1[0x37] = param_1[0x37] + iVar5 * -2;
    }
    local_40 = local_40 + iVar5;
  }
LAB_00107cac:
  if (((local_3c != 0) || (local_40 != 0)) || (local_44 != 0)) {
    iVar5 = param_1[0x36d];
    param_1[0x36d] = iVar5 + 1;
    if (3 < iVar5 + 1) {
      piVar9 = (int *)0x0;
      piVar6 = (int *)0x0;
      while (piVar9 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar9,"tf_ammobox"),
            piVar9 != (int *)0x0) {
        iVar5 = *(int *)(*piVar9 + 400);
        if ((iVar5 == 0) && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = *(int **)(iVar5 + 0x7c);
        }
        if ((piVar7 == param_1) &&
           ((piVar6 == (int *)0x0 || ((float)piVar9[0x11d] < (float)piVar6[0x11d])))) {
          piVar6 = piVar9;
        }
      }
      if (piVar6 != (int *)0x0) {
        *(float *)(*piVar6 + 0x104) = *gpGlobals;
      }
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/ammopickup1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    piVar6 = (int *)GetClassPtr__H1Z10CWeaponBox_PX01_PX01(0);
    (**(code **)(piVar6[0x115] + 0xc))(piVar6);
    *(char **)(*piVar6 + 0x1d0) = "?tf_ammobox" + (1 - (int)gpGlobals[0x26]);
    *(char **)*piVar6 = "?tf_ammobox" + (1 - (int)gpGlobals[0x26]);
    *(undefined4 *)(*piVar6 + 400) = *(undefined4 *)(*param_1 + 0x208);
    piVar6[0x11c] = (int)(*gpGlobals + 2.0);
    piVar6[0x48] = param_1[0x48];
    piVar6[0x11d] = (int)*gpGlobals;
    piVar6[0x35] = local_3c;
    piVar6[0x39] = local_40;
    piVar6[0x37] = local_44;
    piVar6[0x33] = local_48;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar6,*param_1 + 8);
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
    iVar5 = *piVar6;
    *(undefined4 *)(iVar5 + 0x50) = g_vecZero;
    *(undefined4 *)(iVar5 + 0x54) = DAT_0019f664;
    *(undefined4 *)(iVar5 + 0x58) = DAT_0019f668;
    iVar5 = *piVar6;
    fVar1 = gpGlobals[0xb];
    fVar2 = gpGlobals[0xc];
    fVar3 = gpGlobals[0xe];
    fVar4 = gpGlobals[0xf];
    *(float *)(iVar5 + 0x20) = gpGlobals[10] * 400.0 + gpGlobals[0xd] * 200.0;
    *(float *)(iVar5 + 0x24) = fVar1 * 400.0 + fVar3 * 200.0;
    *(float *)(iVar5 + 0x28) = fVar2 * 400.0 + fVar4 * 200.0;
    piVar6[3] = -0x10000;
    piVar6[4] = (int)Kill__10CWeaponBox;
    *(float *)(*piVar6 + 0x104) = *gpGlobals + 30.0;
  }
  return;
}


// TeamFortress_DisplayDetectionItems__11CBasePlayer  @ 00108218
void TeamFortress_DisplayDetectionItems__11CBasePlayer(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_tfdetect");
  if (iVar1 != 0) {
    DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(param_1,iVar1);
  }
  return;
}


// TeamFortress_DisplayLegalClasses__11CBasePlayer  @ 000e10c4
void TeamFortress_DisplayLegalClasses__11CBasePlayer(undefined4 *param_1)

{
  uint uVar1;
  
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_legalclasses",0,0,0,0);
  uVar1 = (&illegalclasses)[param_1[0x48]];
  if (((((byte)illegalclasses ^ 1) & 1) != 0) && ((((byte)uVar1 ^ 1) & 1) != 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Scout",0,0,0,0);
  }
  if ((((byte)illegalclasses & 2) == 0) && ((uVar1 & 2) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sniper",0,0,0,0);
  }
  if ((((byte)illegalclasses & 4) == 0) && ((uVar1 & 4) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Soldier",0,0,0,0);
  }
  if ((((byte)illegalclasses & 8) == 0) && ((uVar1 & 8) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Demoman",0,0,0,0);
  }
  if ((((byte)illegalclasses & 0x10) == 0) && ((uVar1 & 0x10) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Medic",0,0,0,0);
  }
  if ((((byte)illegalclasses & 0x20) == 0) && ((uVar1 & 0x20) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,&UNK_00150f9b,0,0,0,0);
  }
  if ((((byte)illegalclasses & 0x40) == 0) && ((uVar1 & 0x40) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,&UNK_00150fa2,0,0,0,0);
  }
  if (((illegalclasses._1_1_ & 1) == 0) && ((uVar1 & 0x100) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,&UNK_00150fa8,0,0,0,0);
  }
  if (((illegalclasses._1_1_ & 2) == 0) && ((uVar1 & 0x200) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Engineer",0,0,0,0);
  }
  if ((-1 < (char)(byte)illegalclasses) && (-1 < (char)(byte)uVar1)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#RandomPC",0,0,0,0);
  }
  return;
}


// TeamFortress_EMPExplode__11CBaseEntityP9entvars_sff  @ 0008e760
void TeamFortress_EMPExplode__11CBaseEntityP9entvars_sff
               (int *param_1,int param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  iVar2 = *(int *)(param_2 + 0x198);
  if (iVar2 == 0) {
    iVar2 = (*DAT_0019f7b4)(0);
    if (iVar2 == 0) {
      local_20 = (undefined4 *)0x0;
      goto LAB_0008e7ab;
    }
  }
  local_20 = *(undefined4 **)(iVar2 + 0x7c);
LAB_0008e7ab:
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  local_10 = (int)ROUND(param_3 * 0.75);
  if (local_10 < 0x100) {
    iVar2 = local_10;
    if (local_10 < 5) {
      iVar2 = 5;
    }
  }
  else {
    iVar2 = 0xff;
  }
  iVar1 = *param_1;
  local_1c = *(undefined4 *)(iVar1 + 8);
  local_18 = *(undefined4 *)(iVar1 + 0xc);
  local_14 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii(&local_1c,param_2,*local_20,param_3,param_4,0,0x4000040);
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(3);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)((int)g_sModelIndexFireball);
  (*DAT_0019f760)(iVar2);
  (*DAT_0019f760)(0xf);
  (*DAT_0019f760)(3);
  (*DAT_0019f75c)();
  return;
}


// TeamFortress_EMPRemove__11CBaseEntity  @ 0008e910
void TeamFortress_EMPRemove__11CBaseEntity(undefined4 param_1)

{
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// TeamFortress_EMPRemove__5CItem  @ 000b5ee0
void TeamFortress_EMPRemove__5CItem(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x454) + 0xc0))(param_1);
  return;
}


// TeamFortress_EngineerBuild__11CBasePlayeri  @ 000a63a8
void TeamFortress_EngineerBuild__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar2 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
  if (iVar2 == 0) {
    return;
  }
  fVar1 = *gpGlobals;
  if ((byte)(fVar1 < cb_prematch_time |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) == 1) {
    return;
  }
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a5) & 2) == 0) {
    pcVar3 = "#Build_air";
  }
  else {
    if (param_1[0x1a] != 0) {
      if (param_1[0x1a] != 1) {
        return;
      }
      ClientPrint__FP9entvars_siPCcN42(iVar2,4,"#Build_stop",0,0,0,0);
      *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      iVar2 = FindTimer__11CBaseEntityi(param_1,0xb);
      if (iVar2 != 0) {
        dremove__FP11CBaseEntity(iVar2);
      }
      uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
      UTIL_Remove__FP11CBaseEntity(uVar4);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
      param_1[0x1a] = 0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"weapons/building.wav",0,0,0x20,100);
      iVar2 = param_1[0x237];
      if (iVar2 == 0) {
        return;
      }
      (**(code **)(*(int *)(iVar2 + 0x454) + 0x120))(iVar2);
      return;
    }
    if (0 < param_2) {
      TeamFortress_Build__11CBasePlayeri(param_1,param_2);
      return;
    }
    if (((99 < param_1[0x37]) ||
        ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x53]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_1[0x53] == 0.0) << 0xe) >> 8)) != 0x40)) ||
       ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x54]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x54] == 0.0) << 0xe) >> 8)) != 0x40)) {
      param_1[0x44] = 0x41700000;
      return;
    }
    pcVar3 = "#Build_nometal";
  }
  ClientPrint__FP9entvars_siPCcN42(iVar2,4,pcVar3,0,0,0,0);
  return;
}


// TeamFortress_ExecClassScript__11CBasePlayer  @ 000e4340
void TeamFortress_ExecClassScript__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x20c);
  if ((((iVar1 != 0xb) && (iVar1 != 0)) && (iVar1 != 10)) &&
     ((param_1[0xc] != iVar1 && (param_1[0xc] = iVar1, param_1[0x3d] != 0)))) {
    (*DAT_0019f758)(1,9,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f778)(*(undefined4 *)(sClassCfgs + *(int *)(*param_1 + 0x20c) * 4));
    (*DAT_0019f75c)();
  }
  return;
}


// TeamFortress_ExecMapScript__11CBasePlayer  @ 000e42bc
void TeamFortress_ExecMapScript__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x3e] != 0) {
    (*DAT_0019f758)(1,9,0,*(undefined4 *)(*param_1 + 0x208));
    uVar1 = UTIL_VarArgs__FPce("exec mapdefault.cfg\nexec %s.cfg\n",
                               *(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98));
    (*DAT_0019f778)(uVar1);
    (*DAT_0019f75c)();
  }
  return;
}


// TeamFortress_GetNoPlayers__Fv  @ 001141ec
int TeamFortress_GetNoPlayers__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    iVar2 = 1;
    do {
      iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
      if (iVar1 != 0) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(gpGlobals + 0x90));
  }
  return iVar3;
}


// TeamFortress_InitStatusBar__11CBasePlayer  @ 000fec44
void TeamFortress_InitStatusBar__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0xde4) = 0;
  *(undefined1 *)(param_1 + 0xc48) = 0;
  *(undefined1 *)(param_1 + 0xcc8) = 0;
  return;
}


// TeamFortress_PrimeGrenade__11CBasePlayeri  @ 000e37f4
void TeamFortress_PrimeGrenade__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((((param_1[0x21] & 1U) == 0) && ((param_1[0x21] & 0x400U) == 0)) &&
     (iVar1 = (**(code **)(param_1[0x115] + 0x8c))(param_1), iVar1 != 0)) {
    if (param_2 == 1) {
      iVar1 = param_1[0x13];
      piVar2 = param_1 + 0x11;
    }
    else {
      iVar1 = param_1[0x14];
      piVar2 = param_1 + 0x12;
    }
    if (0 < *piVar2) {
      switch(iVar1) {
      case 1:
        Prime__16CTFNormalGrenadeP11CBaseEntity(param_1);
        break;
      case 2:
        Prime__20CTFConcussionGrenadeP11CBaseEntity(param_1);
        break;
      case 3:
        Prime__14CTFNailGrenadeP11CBaseEntity(param_1);
        break;
      case 4:
        Prime__14CTFMirvGrenadeP11CBaseEntity(param_1);
        break;
      case 5:
        Prime__16CTFNapalmGrenadeP11CBaseEntity(param_1);
        break;
      default:
        goto switchD_000e386c_caseD_6;
      case 7:
        Prime__13CTFGasGrenadeP11CBaseEntity(param_1);
        break;
      case 8:
        Prime__13CTFEMPGrenadeP11CBaseEntity(param_1);
        break;
      case 9:
        func_0x00086654(param_1);
      }
      *piVar2 = *piVar2 + -1;
      *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) | 1;
      param_1[0x24] = param_2;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),1,FUN_001514b0,0x3f666666,0x3f4ccccd,0,100);
    }
  }
switchD_000e386c_caseD_6:
  return;
}


// TeamFortress_PrintClassName__11CBasePlayeri  @ 000e4610
void TeamFortress_PrintClassName__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = UTIL_VarArgs__FPce(&DAT_00150cb5,(&sClassNames)[param_2],0,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,uVar1);
  return;
}


// TeamFortress_RemoveBuildings__11CBasePlayer  @ 000a61c8
void TeamFortress_RemoveBuildings__11CBasePlayer(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_c;
  
  iVar4 = 0;
  do {
    iVar4 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar4,"building_dispenser");
    if (iVar4 == 0) goto LAB_000a6266;
    puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(iVar4 + 0x144);
  } while (puVar3 != param_1);
  if (param_1[0x36b] == 0) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Dispenser_destroyed",0,0,0,0);
  }
  param_1[0x53] = 0;
  param_1[0x36b] = 0;
  dremove__FP11CBaseEntity(iVar4);
LAB_000a6266:
  iVar4 = 0;
  do {
    iVar4 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar4,"building_sentrygun");
    if (iVar4 == 0) goto LAB_000a6352;
    puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(iVar4 + 0x144);
  } while (puVar3 != param_1);
  if (param_1[0x36a] == 0) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Sentry_destroyed",0,0,0,0);
  }
  local_c = 1;
  param_1[0x54] = 0;
  param_1[0x36a] = 0;
  for (; local_c <= *(int *)(gpGlobals + 0x90); local_c = local_c + 1) {
    iVar1 = UTIL_PlayerByIndex__Fi(local_c);
    if (iVar1 != 0) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1 + 0x138);
      if (iVar2 == iVar4) {
        ResetMenu__11CBasePlayer(iVar1);
        __as__7EHANDLEP11CBaseEntity(iVar1 + 0x138,0);
      }
    }
  }
  dremove__FP11CBaseEntity(iVar4);
LAB_000a6352:
  iVar4 = 0;
  do {
    iVar4 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar4,"building_sentrygun_base");
    if (iVar4 == 0) {
      return;
    }
    puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(iVar4 + 0x144);
  } while (puVar3 != param_1);
  dremove__FP11CBaseEntity(iVar4);
  return;
}


// TeamFortress_RemoveDetpacks__11CBasePlayer  @ 0009aaf8
void TeamFortress_RemoveDetpacks__11CBasePlayer(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  do {
    piVar1 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar1,"detpack");
    if (piVar1 == (int *)0x0) {
      return;
    }
  } while (*(int *)(*piVar1 + 0x198) != *(int *)(*param_1 + 0x208));
  dremove__FP11CBaseEntity(piVar1);
  return;
}


// TeamFortress_RemoveLiveGrenades__11CBasePlayer  @ 000e419c
void TeamFortress_RemoveLiveGrenades__11CBasePlayer(undefined4 param_1)

{
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_napalmgrenade");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_nailgrenade");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_gasgrenade");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_caltrop");
  return;
}


// TeamFortress_RemoveRockets__11CBasePlayer  @ 000e4164
void TeamFortress_RemoveRockets__11CBasePlayer(undefined4 param_1)

{
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_rpg_rocket");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_ic_rocket");
  return;
}


// TeamFortress_RemoveTimers__11CBasePlayer  @ 000e1c58
void TeamFortress_RemoveTimers__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  
  param_1[0x68] = 0;
  param_1[0x19] = 0;
  if ((param_1[0x21] & 0x800U) != 0) {
    param_1[0x21] = param_1[0x21] & 0xfffff7ff;
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    param_1[0x61] = 0;
  }
  if (param_1[0x1a] != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
    if (iVar1 != 0) {
      uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
      UTIL_Remove__FP11CBaseEntity(uVar2);
    }
  }
  param_1[0x1a] = 0;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
  uVar3 = param_1[0x21];
  if ((uVar3 & 0x10) != 0) {
    uVar3 = uVar3 & 0xffffffef;
    param_1[0x21] = uVar3;
  }
  if ((uVar3 & 0x4000) != 0) {
    param_1[0x21] = uVar3 & 0xffffbfff;
  }
  while (iVar1 = FindTimer__11CBaseEntityi(param_1,0), iVar1 != 0) {
    if (*(float *)(iVar1 + 0x1c4) <= 0.0) {
      SUB_Remove__11CBaseEntity(iVar1);
    }
  }
  piVar5 = (int *)0x0;
LAB_000e1f0b:
  do {
    do {
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
        while (piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"detpack"),
              piVar5 != (int *)0x0) {
          if (((byte)((byte)((ushort)((ushort)NAN((float)piVar5[0x42]) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)piVar5[0x42] == 1.0) << 0xe) >> 8)) == 0x40) &&
             (*(int *)(*piVar5 + 400) == *(int *)(*param_1 + 0x208))) {
            piVar5[0x42] = 0;
          }
        }
        ExplodeOldPipebomb__11CBasePlayerii(param_1,1,1);
        param_1[0x100] = 0;
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x15c) = 0;
        iVar1 = *param_1;
        *(undefined4 *)(iVar1 + 0x150) = g_vecZero;
        *(undefined4 *)(iVar1 + 0x154) = DAT_0019f664;
        *(undefined4 *)(iVar1 + 0x158) = DAT_0019f668;
        *(undefined4 *)(*param_1 + 0x14c) = 0;
        *(undefined4 *)(*param_1 + 0x148) = 0;
        *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
        return;
      }
    } while (*(int *)(*piVar5 + 0x198) != *(int *)(*param_1 + 0x208));
    if ((*(byte *)((int)piVar5 + 0x229) & 1) == 0) {
      tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar5,param_1,0);
    }
  } while (CTF_Map != 1);
  if (piVar5[0x84] != 1) goto LAB_000e1e44;
  uVar2 = UTIL_VarArgs__FPce("%s LOST the BLUE flag!\n",
                             *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
  UTIL_ClientPrintAll__FiPCcN41(4,uVar2,0,0,0,0);
  if (param_1[0x48] == 0) {
    pcVar4 = "SPECTATOR";
  }
  else {
    pcVar4 = (char *)GetTeamName__Fi(param_1[0x48]);
  }
  uVar2 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar4);
  uVar2 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar2);
  iVar1 = *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98);
  pcVar4 = "\"%s<%i><%s><%s>\" triggered \"Dropped_Blue_Flag\"\n";
  goto LAB_000e1efa;
LAB_000e1e44:
  if (piVar5[0x84] == 2) {
    uVar2 = UTIL_VarArgs__FPce("%s LOST the RED flag!\n",
                               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    UTIL_ClientPrintAll__FiPCcN41(4,uVar2,0,0,0,0);
    if (param_1[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(param_1[0x48]);
    }
    uVar2 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar4);
    uVar2 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar2);
    iVar1 = *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar4 = "\"%s<%i><%s><%s>\" triggered \"Dropped_Red_Flag\"\n";
LAB_000e1efa:
    UTIL_LogPrintf__FPce(pcVar4,iVar1,uVar2);
  }
  goto LAB_000e1f0b;
}


// TeamFortress_SaveMe__11CBasePlayer  @ 00107f7c
void TeamFortress_SaveMe__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  longdouble lVar8;
  longdouble lVar9;
  int *piStack_8;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[100];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    lVar8 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
    lVar9 = (longdouble)0.8;
    if ((byte)((lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) - 1) < 0x40) {
      uVar7 = *(undefined4 *)(*param_1 + 0x208);
      pcVar5 = "speech/saveme2.wav";
    }
    else {
      uVar7 = *(undefined4 *)(*param_1 + 0x208);
      pcVar5 = "speech/saveme1.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar7,1,pcVar5,0x3f800000,0x3f4ccccd,0,100);
    param_1[100] = (int)(*gpGlobals + 4.0);
  }
  piStack_8 = (int *)0x0;
  while( true ) {
    piStack_8 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piStack_8,"player");
    if (piStack_8 == (int *)0x0) {
      return;
    }
    bVar4 = false;
    if ((*(int *)(*piStack_8 + 0x208) == 0) ||
       (iVar6 = (*DAT_0019f7b8)(*(int *)(*piStack_8 + 0x208)), iVar6 == 0)) {
      bVar4 = true;
    }
    if (bVar4) break;
    iVar6 = *piStack_8;
    if ((iVar6 != 0) &&
       (((iVar3 = *(int *)(iVar6 + 0x20c), iVar3 == 5 || (iVar3 == 8)) || (iVar3 == 9)))) {
      (*DAT_0019f758)(1,0x17,0,*(undefined4 *)(iVar6 + 0x208));
      (*DAT_0019f760)(0x7c);
      uVar7 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(uVar7);
      (*DAT_0019f774)(0x42480000);
      (*DAT_0019f768)((int)g_sModelIndexSaveMe);
      (*DAT_0019f768)(0x28);
      (*DAT_0019f75c)();
    }
  }
  return;
}


// TeamFortress_SetDetpack__11CBasePlayeri  @ 0009a81c
void TeamFortress_SetDetpack__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int *local_8;
  
  if ((*(byte *)((int)param_1 + 0x156) & 2) == 0) {
    return;
  }
  if (param_1[0x31] < 1) {
    return;
  }
  local_8 = (int *)0x0;
  do {
    local_8 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                               (local_8,*param_1 + 8,0x42820000);
    if (local_8 == (int *)0x0) {
      if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Detpack_air",0,0,0,0);
        return;
      }
      piVar5 = (int *)0x0;
      while (piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"detpack"),
            piVar5 != (int *)0x0) {
        if (*(int *)(*piVar5 + 0x198) == *(int *)(*param_1 + 0x208)) {
          ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Detpack_oneactive",0,0,0,0);
          return;
        }
      }
      if (4 < param_2) {
        param_1[0x1b] = 1;
        param_1[0x31] = param_1[0x31] + -1;
        fVar1 = *gpGlobals;
        *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
        param_1[99] = (int)(fVar1 + 10.0);
        TeamFortress_SetSpeed__11CBasePlayer(param_1);
        (**(code **)(*(int *)(param_1[0x237] + 0x454) + 0x128))(param_1[0x237],0);
        *(undefined4 *)(*param_1 + 0xc0) = 0;
        uVar4 = UTIL_dtos1__Fi(param_2,0,0,0);
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Detpack_set",uVar4);
        piVar5 = (int *)CreateTimer__11CBaseEntityi(param_1,9);
        *(float *)(*piVar5 + 0x104) = *gpGlobals + 3.0;
        piVar5[3] = -0x10000;
        piVar5[4] = (int)Timer_DetpackSet__11CBaseEntity;
        *(float *)(*piVar5 + 0x160) = (float)param_2;
        return;
      }
      pcVar3 = "#Detpack_fivesec";
      goto LAB_0009a9fa;
    }
    iVar2 = strcmp((char *)(*(int *)*local_8 + (int)gpGlobals[0x26]),"player");
    if ((iVar2 == 0) && (local_8 != param_1)) {
      pcVar3 = "#Detpack_someone";
      goto LAB_0009a9fa;
    }
    iVar2 = strcmp((char *)(*(int *)*local_8 + (int)gpGlobals[0x26]),"building_sentrygun");
    if (iVar2 == 0) {
      pcVar3 = "#Detpack_sentry";
      goto LAB_0009a9fa;
    }
    iVar2 = strcmp((char *)(*(int *)*local_8 + (int)gpGlobals[0x26]),"building_dispenser");
    if (iVar2 == 0) {
      pcVar3 = "#Detpack_dispenser";
      goto LAB_0009a9fa;
    }
    iVar2 = strcmp((char *)(*(int *)*local_8 + (int)gpGlobals[0x26]),"detpack");
  } while (iVar2 != 0);
  pcVar3 = "#Detpack_stack";
LAB_0009a9fa:
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar3,0,0,0,0);
  return;
}


// TeamFortress_SetEquipment__11CBasePlayer  @ 000de548
void TeamFortress_SetEquipment__11CBasePlayer(int *param_1)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  
  uVar2 = param_1[0xf];
  param_1[0x22] = 0;
  param_1[0x57] = 0;
  param_1[0x55] = 0;
  param_1[0xf] = 0;
  param_1[0x58] = 0;
  param_1[0x56] = 0;
  if (*(int *)(*param_1 + 0x20c) != 1) {
    param_1[0x10] = 0;
  }
  param_1[0xe] = 0;
  param_1[0x76] = 0;
  param_1[0x75] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x19] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x2f] = 0;
  param_1[0x2e] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x3a] = 0;
  *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xfd;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x42] = 0;
  param_1[0x4c] = 0;
  param_1[0x61] = 0;
  if (param_1[0x48] == 0) {
    param_1[0x49] = -1;
  }
  param_1[0x22] = param_1[0x22] | uVar2 & 0x60000;
  iVar5 = *param_1;
  iVar6 = *(int *)(iVar5 + 0x20c);
  if (iVar6 == 1) {
    param_1[0x55] = param_1[0x55] | 0x290;
    param_1[0x39] = 0;
    param_1[0x35] = 100;
    param_1[0x33] = 0x19;
    param_1[0x37] = 0x32;
    param_1[0x38] = 0x19;
    param_1[0x34] = 200;
    param_1[0x30] = 0x32;
    param_1[0x36] = 100;
    param_1[0x11] = 2;
    param_1[0x12] = 3;
    param_1[0x13] = 9;
    param_1[0x14] = 2;
    param_1[0xf] = 1;
    param_1[0x7c] = 0;
    if (param_1[0x10] < 1) {
      param_1[0x10] = param_1[0x10] | 1;
    }
    *(undefined4 *)(*param_1 + 0x1b8) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x41c80000;
    param_1[0x3a] = 0x290;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 5;
    param_1[0x3b] = 0x3e99999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x44000000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_axe");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_shotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_ng");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_ng";
    param_1[0x33] = param_1[0x33] + -8;
  }
  else if (iVar6 == 2) {
    param_1[0x55] = param_1[0x55] | 0x270;
    param_1[0x39] = 0;
    param_1[0x35] = 0x32;
    param_1[0x33] = 0x3c;
    param_1[0x37] = 0;
    param_1[0x38] = 0x19;
    param_1[0x34] = 100;
    param_1[0x30] = 0x4b;
    param_1[0x36] = 0x32;
    param_1[0x11] = 2;
    param_1[0x12] = 0;
    param_1[0x13] = 1;
    param_1[0x14] = 0;
    param_1[0xf] = 0;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0;
    param_1[0x3a] = 0x270;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 7;
    param_1[0x3b] = 0x3e99999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x42000000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_axe");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_ng");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_sniperrifle");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_autorifle");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_sniperrifle";
  }
  else if (iVar6 == 3) {
    param_1[0x55] = param_1[0x55] | 0x2190;
    param_1[0x39] = 10;
    param_1[0x35] = 0;
    param_1[0x33] = 0x32;
    param_1[0x37] = 0;
    param_1[0x38] = 0x32;
    param_1[0x34] = 100;
    param_1[0x30] = 100;
    param_1[0x36] = 0x32;
    param_1[0x11] = 2;
    param_1[0x12] = 1;
    param_1[0x13] = 1;
    param_1[0x14] = 3;
    param_1[0xf] = 0;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3f4ccccd;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x42c80000;
    param_1[0x3a] = 0x2190;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x23;
    param_1[0x3b] = 0x3f4ccccd;
    param_1[0x3c] = 0x43480000;
    param_1[0x56] = 0x46000000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_axe");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_shotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_supershotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_rpg");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_rpg";
    param_1[0x33] = param_1[0x33] + -0x18;
    param_1[0x39] = param_1[0x39] + -4;
  }
  else if (iVar6 == 4) {
    param_1[0x55] = param_1[0x55] | 0x20890;
    param_1[0x39] = 0x14;
    param_1[0x35] = 0;
    param_1[0x33] = 0x1e;
    param_1[0x37] = 0;
    param_1[0x38] = 0x32;
    param_1[0x34] = 0x32;
    param_1[0x30] = 0x4b;
    param_1[0x36] = 0x32;
    param_1[0x11] = 2;
    param_1[0x12] = 2;
    param_1[0x13] = 1;
    param_1[0x14] = 4;
    param_1[0xf] = 0;
    param_1[0x31] = 1;
    param_1[0x32] = 1;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3f19999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x42480000;
    param_1[0x3a] = 0x20890;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x11;
    param_1[0x228] = 6;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42f00000;
    param_1[0x56] = 0x45000000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_axe");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_shotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_gl");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_pl");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_gl";
    param_1[0x33] = param_1[0x33] + -8;
    param_1[0x39] = param_1[0x39] + -6;
  }
  else if (iVar6 == 5) {
    param_1[0x55] = param_1[0x55] | 0x586;
    param_1[0x39] = 0;
    param_1[0x35] = 0x32;
    param_1[0x33] = 0x32;
    param_1[0x37] = 0;
    param_1[0x38] = 0x19;
    param_1[0x34] = 0x96;
    param_1[0x30] = 0x4b;
    param_1[0x36] = 0x32;
    param_1[0x11] = 2;
    param_1[0x12] = 2;
    param_1[0x13] = 1;
    param_1[0x14] = 2;
    param_1[0xf] = 0;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x42480000;
    param_1[0x2f] = 0x32;
    param_1[0x2e] = 100;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42c80000;
    param_1[0x56] = 0x44800000;
    piVar7 = (int *)CreateTimer__11CBaseEntityi(param_1,6);
    *(float *)(*piVar7 + 0x104) = *gpGlobals + 3.0;
    piVar7[3] = -0x10000;
    piVar7[4] = (int)Timer_Regeneration__11CBaseEntity;
    param_1[0x3a] = 0x586;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0xb;
    uVar4 = (*DAT_0019f7ac)(FUN_00150e04);
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_shotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_supershotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_superng");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_superng";
    param_1[0x33] = param_1[0x33] + -0x18;
  }
  else if (iVar6 == 6) {
    param_1[0x55] = param_1[0x55] | 0x8190;
    param_1[0x39] = 0;
    param_1[0x35] = 0;
    param_1[0x33] = 200;
    param_1[0x37] = 0x1e;
    param_1[0x38] = 0x19;
    param_1[0x34] = 200;
    param_1[0x30] = 200;
    param_1[0x36] = 0x32;
    param_1[0x11] = 2;
    param_1[0x12] = 1;
    param_1[0x13] = 1;
    param_1[0x14] = 4;
    param_1[0xf] = 0;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3f4ccccd;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x43160000;
    param_1[0x3a] = 0x8190;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x23;
    param_1[0x3b] = 0x3f4ccccd;
    param_1[0x3c] = 0x43960000;
    param_1[0x56] = 0x47000000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_axe");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_shotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_supershotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_ac");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_ac";
    param_1[0x33] = param_1[0x33] + -0x18;
  }
  else if (iVar6 == 7) {
    param_1[0x55] = param_1[0x55] | 0x5090;
    param_1[0x39] = 5;
    param_1[0x35] = 0;
    param_1[0x33] = 0x14;
    param_1[0x37] = 0x78;
    param_1[0x38] = 0x14;
    param_1[0x34] = 0x32;
    param_1[0x30] = 0x28;
    param_1[0x36] = 200;
    param_1[0x11] = 2;
    param_1[0x12] = 4;
    param_1[0x13] = 1;
    param_1[0x14] = 5;
    param_1[0xf] = 0;
    *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) | 0x10;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3f19999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x42480000;
    param_1[0x3a] = 0x5090;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x31;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x43160000;
    param_1[0x56] = 0x45800000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_axe");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_shotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_ic");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_flamethrower");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_flamethrower";
    param_1[0x33] = param_1[0x33] + -8;
  }
  else if (iVar6 == 0xb) {
    *(byte *)(param_1 + 0x55) = *(byte *)(param_1 + 0x55) | 0x10;
    param_1[0x39] = 0;
    param_1[0x35] = 0;
    param_1[0x33] = 0;
    param_1[0x37] = 0;
    param_1[0x38] = 0;
    param_1[0x34] = 0;
    param_1[0x30] = 0;
    param_1[0x36] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0xf] = 0;
    *(undefined4 *)(iVar5 + 0x1b8) = 0;
    *(undefined4 *)(*param_1 + 0x1bc) = 0;
    param_1[0x3a] = 0x10;
    param_1[0x22] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    param_1[0x56] = 0x41800000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_axe");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_axe";
  }
  else if (iVar6 == 8) {
    param_1[0x55] = param_1[0x55] | 0x40310;
    param_1[0x39] = 0;
    param_1[0x35] = 0x32;
    param_1[0x33] = 0x28;
    param_1[0x37] = 10;
    param_1[0x38] = 0xf;
    param_1[0x34] = 100;
    param_1[0x30] = 0x28;
    param_1[0x36] = 0x1e;
    param_1[0x11] = 2;
    param_1[0x12] = 2;
    param_1[0x13] = 1;
    param_1[0x14] = 7;
    param_1[0xf] = 0;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3f19999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x41c80000;
    param_1[0x3a] = (int)"e__12CTalkMonsterR5CSave";
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 7;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42c80000;
    param_1[0x56] = 0x48800000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_knife");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_supershotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_tranq");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_ng");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_tranq";
    param_1[0x33] = param_1[0x33] + -0x10;
  }
  else {
    if (iVar6 != 9) {
      if (*(int *)(iVar5 + 0x20c) == 0) {
        param_1[0x22] = 0;
        param_1[0x39] = 0;
        param_1[0x35] = 0;
        param_1[0x33] = 0;
        param_1[0x37] = 0;
        param_1[0x11] = 0;
        param_1[0x12] = 0;
        param_1[0x13] = 0;
        param_1[0x14] = 0;
        param_1[0xe] = 0;
        *(undefined4 *)(iVar5 + 0x1b8) = 0;
        *(undefined4 *)(*param_1 + 0x1bc) = 0;
        param_1[0x55] = 0;
        param_1[0x56] = 0;
        *(uint *)(*param_1 + 0x1a4) = *(uint *)(*param_1 + 0x1a4) & 0x100000;
        *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x88;
        *(undefined4 *)(*param_1 + 0x1c0) = 3;
        *(undefined4 *)(*param_1 + 0x16c) = 0;
        *(undefined4 *)(*param_1 + 0x10c) = 0;
        *(undefined4 *)(*param_1 + 0x108) = 8;
        *(undefined4 *)(*param_1 + 0xb4) = 0;
        *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) | 2;
        *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
      }
      goto LAB_000e0aef;
    }
    param_1[0x55] = param_1[0x55] | 0x80108;
    param_1[0x39] = 0;
    param_1[0x35] = 0x19;
    param_1[0x33] = 0x14;
    param_1[0x37] = 100;
    param_1[0x38] = 0x1e;
    param_1[0x34] = 0x32;
    param_1[0x30] = 0x32;
    param_1[0x36] = 200;
    param_1[0x11] = 2;
    param_1[0x12] = 2;
    param_1[0x13] = 1;
    param_1[0x14] = 8;
    param_1[0xf] = 0;
    *(undefined4 *)(iVar5 + 0x1b8) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x41c80000;
    param_1[0x3a] = 0x80108;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 3;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x49000000;
    uVar4 = (*DAT_0019f7ac)("tf_weapon_spanner");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_railgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    uVar4 = (*DAT_0019f7ac)("tf_weapon_supershotgun");
    iVar5 = (*DAT_0019f6fc)(uVar4);
    bVar3 = false;
    if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      (*DAT_0019f794)(1,"NULL Ent in GiveNamedItem!\n");
    }
    else {
      iVar6 = iVar5 + 0x80;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      iVar8 = *param_1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar8 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
      *(byte *)(iVar5 + 0x223) = *(byte *)(iVar5 + 0x223) | 0x40;
      DispatchSpawn__FP7edict_s(iVar5);
      DispatchTouch__FP7edict_sT0(iVar5,*(undefined4 *)(*param_1 + 0x208));
    }
    pcVar9 = "tf_weapon_railgun";
    param_1[0x33] = param_1[0x33] + -0x10;
  }
  SwitchWeapon__11CBasePlayerPCc(param_1,pcVar9);
LAB_000e0aef:
  param_1[0x239] = 0;
  if ((param_1[0x367] == 0) && (param_1[0x23a] != 0)) {
    iVar5 = 0;
    do {
      for (iVar6 = param_1[iVar5 + 0x231]; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x478)) {
        if ((*(char **)(_15CBasePlayerItem_ItemInfoArray + *(int *)(iVar6 + 0x47c) * 0x2c + 0x18) !=
             (char *)0x0) &&
           (iVar8 = strcmp(*(char **)(_15CBasePlayerItem_ItemInfoArray +
                                     *(int *)(iVar6 + 0x47c) * 0x2c + 0x18),(char *)param_1[0x23a]),
           iVar8 == 0)) {
          param_1[0x239] = iVar6;
          goto LAB_000e0b6b;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 6);
  }
LAB_000e0b6b:
  iVar5 = *param_1;
  fVar1 = *(float *)(iVar5 + 0x1b8);
  if (fVar1 < 0.8) {
    if (fVar1 < 0.6) {
      if (0.3 <= fVar1) {
        *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) | 0x20;
      }
    }
    else {
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) | 0x40;
    }
  }
  else {
    *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) | 0x80;
  }
  if ((*(int *)(iVar5 + 0x20c) == 0) && (*(int *)(iVar5 + 0x244) == 0)) {
    *(byte *)(param_1 + 0x22d) = *(byte *)(param_1 + 0x22d) | 4;
  }
  else {
    *(byte *)(param_1 + 0x22d) = *(byte *)(param_1 + 0x22d) & 0xfb;
  }
  return;
}


// TeamFortress_SetHealth__11CBasePlayer  @ 000e44ac
void TeamFortress_SetHealth__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x20c);
  if (iVar1 == 1) {
    *(undefined4 *)(iVar2 + 0x1b0) = 0x42960000;
    goto LAB_000e4556;
  }
  if (iVar1 == 2) {
LAB_000e4519:
    *(undefined4 *)(iVar2 + 0x1b0) = 0x42b40000;
  }
  else if (iVar1 == 3) {
LAB_000e44f2:
    *(undefined4 *)(iVar2 + 0x1b0) = 0x42c80000;
  }
  else {
    if ((iVar1 == 4) || (iVar1 == 5)) goto LAB_000e4519;
    if ((iVar1 == 6) || (iVar1 == 7)) goto LAB_000e44f2;
    if (iVar1 == 0xb) {
      *(undefined4 *)(iVar2 + 0x1b0) = 0x42480000;
    }
    else {
      if (iVar1 == 8) goto LAB_000e4519;
      if (iVar1 == 9) {
        *(undefined4 *)(iVar2 + 0x1b0) = 0x42a00000;
      }
      else {
        if (iVar1 != 0) goto LAB_000e4558;
        *(undefined4 *)(iVar2 + 0x1b0) = 0x3f800000;
        *(undefined4 *)(*param_1 + 0x16c) = 0;
      }
    }
  }
LAB_000e4556:
  iVar2 = *param_1;
LAB_000e4558:
  *(undefined4 *)(iVar2 + 0x160) = *(undefined4 *)(iVar2 + 0x1b0);
  return;
}


// TeamFortress_SetSkin__11CBasePlayer  @ 000e0df4
void TeamFortress_SetSkin__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_28;
  int local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = (*DAT_0019f848)(*(undefined4 *)(*param_1 + 0x208));
  iVar2 = *param_1;
  param_1[99] = (int)(*gpGlobals + 10.0);
  local_24 = *(int *)(iVar2 + 0x20c);
  if ((local_24 == 8) && (param_1[0x76] != 0)) {
    local_24 = param_1[0x76];
  }
  local_28 = param_1[0x48];
  if ((*(int *)(iVar2 + 0x20c) == 8) && (param_1[0x75] != 0)) {
    local_28 = param_1[0x75];
  }
  if (param_1[0xa6] == 0) {
    if (*(int *)(sOldClassModelFiles + local_24 * 4) == 0) {
      (*DAT_0019f6a8)(*(undefined4 *)(iVar2 + 0x208),"models/player/scout/scout.mdl");
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
      goto LAB_000e0f68;
    }
    (*DAT_0019f6a8)(*(undefined4 *)(iVar2 + 0x208),"models/player/scout/scout.mdl");
    uVar3 = *(undefined4 *)(sClassModels + local_24 * 4);
    iVar2 = *param_1;
  }
  else {
    uVar3 = UTIL_VarArgs__FPce(&DAT_00150f24,param_1[0xa6] + (int)gpGlobals[0x26]);
    iVar2 = *param_1;
  }
  uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(iVar2 + 0x208),uVar1,"model",uVar3);
  (*DAT_0019f854)(uVar3);
LAB_000e0f68:
  if (param_1[0x48] != 0) {
    iVar2 = local_28 * 0x60 + local_24 * 8;
    uVar3 = UTIL_VarArgs__FPce(&DAT_00150f27,*(undefined4 *)(teamcolors + iVar2));
    uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208),uVar1,"topcolor",uVar3);
    (*DAT_0019f854)(uVar3);
    uVar3 = UTIL_VarArgs__FPce(&DAT_00150f27,*(undefined4 *)(teamcolors + iVar2 + 4));
    uVar1 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208),uVar1,"bottomcolor",uVar3);
    (*DAT_0019f854)(uVar1);
  }
  if ((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) {
    puVar5 = &local_1c;
    local_18 = 0x41800000;
    local_14 = 0x42100000;
    local_c = 0xc1800000;
    local_8 = 0xc2100000;
    puVar4 = &local_10;
  }
  else {
    puVar5 = &local_10;
    local_c = 0x41800000;
    local_8 = 0x41900000;
    local_18 = 0xc1800000;
    local_14 = 0xc1900000;
    puVar4 = &local_1c;
  }
  local_1c = local_18;
  local_10 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,puVar4,puVar5);
  g_ulModelIndexPlayer = *(undefined4 *)(*param_1 + 0xb4);
  return;
}


// TeamFortress_SetSpeed__11CBasePlayer  @ 000e0c00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_SetSpeed__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int *piVar5;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 0x20c);
  if (*(int *)(iVar2 + 0x244) != 0) {
    if (*(int *)(iVar2 + 0x244) == 3) {
      *(undefined4 *)(iVar2 + 0x210) = 0x43c80000;
      return;
    }
    *(undefined4 *)(iVar2 + 0x210) = 0;
    return;
  }
  if (((*(byte *)((int)param_1 + 0x86) & 1) != 0) || (iVar3 == 0)) {
    *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar2 + 0x28) = DAT_0019f668;
    *(undefined4 *)(*param_1 + 0x210) = 0x3f800000;
    return;
  }
  if (iVar3 == 1) {
    fVar4 = 400.0;
    goto LAB_000e0cfe;
  }
  if (iVar3 != 2) {
    if (iVar3 == 3) {
LAB_000e0ce2:
      fVar4 = 240.0;
      goto LAB_000e0cfe;
    }
    if (iVar3 == 4) {
      fVar4 = 280.0;
      goto LAB_000e0cfe;
    }
    fVar4 = _FUN_00150edc;
    if (iVar3 == 5) goto LAB_000e0cfe;
    if (iVar3 == 6) {
      fVar4 = 230.0;
      goto LAB_000e0cfe;
    }
    if (iVar3 != 7) {
      if (iVar3 == 0xb) goto LAB_000e0ce2;
      if ((iVar3 != 8) && (fVar4 = 0.0, iVar3 != 9)) goto LAB_000e0cfe;
    }
  }
  fVar4 = 300.0;
LAB_000e0cfe:
  piVar5 = (int *)0x0;
LAB_000e0d59:
  do {
    piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
    if (piVar5 == (int *)0x0) {
      if ((short)param_1[0x21] < 0) {
        fVar4 = fVar4 * 0.5;
      }
      fVar1 = (float)param_1[0x68];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        if (6.0 < fVar1) {
          param_1[0x68] = 0x40c00000;
          fVar1 = 6.0;
        }
        fVar4 = (10.0 - fVar1) * fVar4 * 0.1;
      }
      if (((*(byte *)((int)param_1 + 0x85) & 8) != 0) && (80.0 < fVar4)) {
        fVar4 = 80.0;
      }
      *(float *)(*param_1 + 0x210) = fVar4;
      return;
    }
  } while (*(int *)(*piVar5 + 0x198) != *(int *)(*param_1 + 0x208));
  if ((*(byte *)(piVar5 + 0x8a) & 2) == 0) goto LAB_000e0d30;
  fVar1 = 0.5;
  goto LAB_000e0d4f;
LAB_000e0d30:
  if (piVar5[0xcf] != 0) {
    fVar1 = (float)piVar5[0xcf] * 0.01;
LAB_000e0d4f:
    fVar4 = fVar1 * fVar4;
  }
  goto LAB_000e0d59;
}


// TeamFortress_SetupRespawn__11CBasePlayeri  @ 000e1fe4
void TeamFortress_SetupRespawn__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float fStack_14;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x4c];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    fStack_14 = (float)tfc_respawndelay._12_4_;
    param_1[0x21c] = 0;
    param_1[0x21d] = 0;
    *(undefined1 *)(param_1 + 0x199) = 0;
    fVar1 = *gpGlobals + 1.0;
    if (0x3f < (byte)((fVar1 < cb_prematch_time |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) - 1)) {
      if (param_2 != 0) {
        if (0 < (int)param_1[0x49]) {
          param_1[0x49] = param_1[0x49] + -1;
        }
        fStack_14 = (float)param_1[0x1c4] - *gpGlobals;
      }
      iVar3 = param_1[0x49];
      if (0 < iVar3) {
        iVar3 = iVar3 + -1;
        param_1[0x49] = iVar3;
      }
      if (iVar3 != -1) {
        if (iVar3 == 0) {
          ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Game_nolives",0,0,0,0);
          StartDeathCam__11CBasePlayer(param_1);
          return;
        }
        if (iVar3 == 1) {
          uVar9 = 0;
          uVar8 = 0;
          uVar7 = 0;
          uVar6 = 0;
          pcVar5 = "#Game_lastlife";
          uVar4 = 4;
        }
        else {
          uVar9 = 0;
          uVar8 = 0;
          uVar7 = 0;
          uVar6 = UTIL_dtos1__Fi(iVar3,0,0,0);
          pcVar5 = "#Game_Xlives";
          uVar4 = 1;
        }
        ClientPrint__FP9entvars_siPCcN42(*param_1,uVar4,pcVar5,uVar6,uVar7,uVar8,uVar9);
      }
    }
    param_1[0x4c] = fStack_14 + *gpGlobals;
    if (3.0 < fStack_14) {
      uVar6 = UTIL_dtos1__Fi((int)ROUND(fStack_14),0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_tillrespawn",uVar6);
    }
  }
  return;
}


// TeamFortress_SortTeams__Fv  @ 00113fac
int TeamFortress_SortTeams__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_18 [5];
  
  local_1c = 0;
  local_24 = 0;
  local_2c = 1;
  iVar3 = 0;
  do {
    local_18[iVar3] = 0;
    iVar1 = iVar3 + 1;
    (&g_iOrderedTeams)[iVar3] = 0;
    iVar3 = iVar1;
  } while (iVar1 < 5);
  if (1.0 <= number_of_teams) {
    iVar3 = 1;
    do {
      iVar1 = local_1c;
      local_20 = 0;
      iVar2 = 1;
      if (1.0 <= number_of_teams) {
        do {
          if ((local_20 <= *(int *)(teamscores + iVar2 * 4)) && (local_18[iVar2] == 0)) {
            local_20 = *(int *)(teamscores + iVar2 * 4);
            local_1c = iVar2;
          }
          iVar2 = iVar2 + 1;
        } while ((float)iVar2 <= number_of_teams);
      }
      if ((((1 < iVar3) && (local_2c == 1)) &&
          ((((byte)((int)(&teamallies)[iVar3] >> ((char)iVar1 - 1U & 0x1f)) ^ 1) & 1) != 0)) &&
         (local_20 != local_24)) {
        local_2c = 0;
      }
      local_24 = local_20;
      local_18[local_1c] = 1;
      (&g_iOrderedTeams)[iVar3] = local_1c;
      iVar3 = iVar3 + 1;
    } while ((float)iVar3 <= number_of_teams);
  }
  return local_2c;
}


// TeamFortress_SpyCalcName__11CBasePlayer  @ 000f3e88
void TeamFortress_SpyCalcName__11CBasePlayer(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 + 0x1dc;
  piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(iVar4);
  __as__7EHANDLEP11CBaseEntity(iVar4,0);
  if (*(int *)(param_1 + 0x1d4) != 0) {
    if (0 < *(int *)(gpGlobals + 0x90)) {
      iVar3 = 1;
      do {
        piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
        if ((((piVar2 != (int *)0x0) && (piVar2 != piVar1)) &&
            (piVar2[0x48] == *(int *)(param_1 + 0x1d4))) &&
           (*(int *)(*piVar2 + 0x20c) == *(int *)(param_1 + 0x1d8))) goto LAB_000f3f5c;
        iVar3 = iVar3 + 1;
      } while (iVar3 <= *(int *)(gpGlobals + 0x90));
    }
    if (0 < *(int *)(gpGlobals + 0x90)) {
      iVar3 = 1;
      do {
        piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
        if ((piVar2 != (int *)0x0) && (piVar2[0x48] == *(int *)(param_1 + 0x1d4))) {
LAB_000f3f5c:
          __as__7EHANDLEP11CBaseEntity(iVar4,piVar2);
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= *(int *)(gpGlobals + 0x90));
    }
  }
  return;
}


// TeamFortress_SpyChangeColor__11CBasePlayeri  @ 000f4164
void TeamFortress_SpyChangeColor__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 == param_1[0x48]) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,FUN_0015303c,0,0,0,0);
    param_1[0x75] = 0;
    if (param_1[0x76] == 0) {
      param_1[0x19] = 0;
    }
    TeamFortress_SetSkin__11CBasePlayer(param_1);
  }
  else if ((param_1[0x365] == 0) && (param_2 != param_1[0x75])) {
    iVar1 = *param_1;
    if (((*(byte *)(iVar1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
      ClientPrint__FP9entvars_siPCcN42(iVar1,4,"#Disguise_start",0,0,0,0);
      param_1[0x19] = 2;
      piVar2 = (int *)CreateTimer__11CBaseEntityi(param_1,0xd);
      piVar2[3] = -0x10000;
      piVar2[4] = (int)Timer_SpyUndercoverThink__11CBaseEntity;
      *(float *)(*piVar2 + 0x104) = *gpGlobals + 4.0;
      piVar2[0x48] = param_2;
    }
    else {
      ClientPrint__FP9entvars_siPCcN42(iVar1,4,"#Spy_unable",0,0,0,0);
    }
  }
  return;
}


// TeamFortress_SpyChangeSkin__11CBasePlayeri  @ 000f3f84
void TeamFortress_SpyChangeSkin__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  int local_8;
  
  local_8 = 4;
  iVar1 = param_1[0x365];
  if (iVar1 != 0) {
    if ((iVar1 != param_1[0x75]) && (iVar1 != param_1[0x48])) {
      local_8 = 8;
    }
    if ((param_2 == 8) || (param_2 == param_1[0x76])) {
      param_1[0x365] = 0;
    }
    TeamFortress_SpyChangeColor__11CBasePlayeri();
    param_1[0x365] = 0;
  }
  if ((param_2 == 8) && (iVar1 == param_1[0x48])) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_resetclass",0,0);
    param_1[0x76] = 0;
    param_1[0x75] = 0;
    param_1[0x19] = 0;
    puVar4 = &stack0xffffffe8;
    if (param_1[0x1c] == 0) {
      *(int *)(*param_1 + 0xc0) = param_1[0x364] - (int)gpGlobals[0x26];
      strcpy((char *)(param_1 + 0x352),(char *)(param_1 + 0x35c));
      param_1[0x35a] = 0;
      puVar4 = &stack0xffffffe8;
    }
  }
  else {
    if (param_2 == param_1[0x76]) {
      return;
    }
    iVar2 = *param_1;
    if (((*(byte *)(iVar2 + 0x118) & 9) != 0) || (param_1[0x1d] == 1)) {
      ClientPrint__FP9entvars_siPCcN42(iVar2,4,"#Spy_unable",0,0);
      return;
    }
    ClientPrint__FP9entvars_siPCcN42(iVar2,4,"#Disguise_start",0,0);
    param_1[0x19] = 2;
    iVar2 = FindTimer__11CBaseEntityi(param_1,0xd);
    if (iVar2 != 0) {
      UTIL_Remove__FP11CBaseEntity();
    }
    puVar4 = &stack0xffffffe0;
    piVar3 = (int *)CreateTimer__11CBaseEntityi();
    piVar3[3] = -0x10000;
    piVar3[4] = (int)Timer_SpyUndercoverThink__11CBaseEntity;
    *(float *)(*piVar3 + 0x104) = *gpGlobals + (float)local_8;
    *(int *)(*piVar3 + 0x110) = param_2;
    piVar3[0x48] = iVar1;
  }
  *(int **)(puVar4 + -4) = param_1;
  *(undefined4 *)(puVar4 + -8) = 0xf4159;
  TeamFortress_SetSkin__11CBasePlayer();
  return;
}


// TeamFortress_SpyDisguiseEnemy__11CBasePlayerii  @ 000f42f4
void TeamFortress_SpyDisguiseEnemy__11CBasePlayerii(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x120);
  }
  else {
    iVar1 = 1;
    if (1.0 < number_of_teams) {
      do {
        iVar1 = (*DAT_0019f808)(1,(int)ROUND(number_of_teams));
      } while (iVar1 == *(int *)(param_1 + 0x120));
    }
  }
  TeamFortress_SpyDisguise__11CBasePlayerii(param_1,iVar1,param_3);
  return;
}


// TeamFortress_SpyDisguise__11CBasePlayerii  @ 000f4270
void TeamFortress_SpyDisguise__11CBasePlayerii(int *param_1,int param_2,int param_3)

{
  float fVar1;
  
  fVar1 = (float)param_2;
  if ((((byte)(number_of_teams < fVar1 |
               (byte)((ushort)((ushort)(NAN(number_of_teams) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(number_of_teams == fVar1) << 0xe) >> 8)) != 1) &&
      (0 < param_2)) && (param_3 - 1U < 9)) {
    if (((*(byte *)(*param_1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
      param_1[0x365] = param_2;
      TeamFortress_SpyChangeSkin__11CBasePlayeri(param_1,param_3);
    }
    else {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spy_unable",0,0,0,0);
    }
  }
  return;
}


// TeamFortress_SpyFeignDeath__11CBasePlayeri  @ 000f35dc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_SpyFeignDeath__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *piVar6;
  longdouble lVar7;
  undefined4 *puVar8;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  float fStack_58;
  undefined1 auStack_54 [4];
  int iStack_50;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  fVar1 = (float)param_1[0x196];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  param_1[0x196] = 0x3f000000;
  if (param_1[0x1c] == 0) {
    if (param_1[0x1d] == 1) {
      pcVar5 = "#Feign_unable";
    }
    else {
      iVar2 = *param_1;
      if (((*(byte *)(iVar2 + 0x1a5) & 2) == 0) && (*(int *)(iVar2 + 0x1c0) == 0)) {
        ClientPrint__FP9entvars_siPCcN42(iVar2,4,"#Feign_air",0,0,0,0);
        return;
      }
      piVar6 = (int *)0x0;
      do {
        piVar6 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                  (piVar6,*param_1 + 8,0x42800000);
        if (piVar6 == (int *)0x0) {
          iVar2 = *param_1;
          if ((*(byte *)(iVar2 + 0x1a5) & 0x40) != 0) {
            local_1c = *(undefined4 *)(iVar2 + 8);
            local_18 = *(undefined4 *)(iVar2 + 0xc);
            local_14 = *(float *)(iVar2 + 0x10);
            if ((*(byte *)(iVar2 + 0x1a5) & 2) != 0) {
              local_78 = 0xc1800000;
              fStack_58 = _FUN_00152ed4;
              local_14 = local_14 + _FUN_00152ed4;
              local_64 = 0xc1900000;
              local_70 = -36.0;
              local_60 = 0;
              uStack_5c = 0;
              local_74 = local_78;
              local_6c = local_78;
              local_68 = local_78;
              local_10 = local_1c;
              local_c = local_18;
              local_8 = local_14;
            }
            UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                      (&local_1c,&local_1c,0,1,*(undefined4 *)(*param_1 + 0x208),auStack_54);
            if (iStack_50 != 0) {
              pcVar5 = "#Feign_noroom";
              goto LAB_000f3965;
            }
            iVar2 = *param_1;
            if ((*(byte *)(iVar2 + 0x1a5) & 2) != 0) {
              local_6c = 0xc1800000;
              local_64 = 0xc1900000;
              fStack_58 = -36.0;
              local_70 = _FUN_00152ed4;
              local_78 = 0;
              local_74 = 0;
              local_8 = _FUN_00152ed4 + *(float *)(iVar2 + 0x10);
              local_10 = *(undefined4 *)(iVar2 + 8);
              local_c = *(undefined4 *)(iVar2 + 0xc);
              *(undefined4 *)(iVar2 + 8) = local_10;
              *(undefined4 *)(iVar2 + 0xc) = local_c;
              *(float *)(iVar2 + 0x10) = local_8;
              local_68 = local_6c;
              local_60 = local_6c;
              uStack_5c = local_6c;
            }
          }
          param_1[0x285] = 0;
          SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
          fVar1 = *gpGlobals;
          *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
          param_1[99] = (int)(fVar1 + 5.0);
          TeamFortress_SetSpeed__11CBasePlayer(param_1);
          *(undefined4 *)(*param_1 + 0x170) = 5;
          param_1[0x1c] = 1;
          param_1[0x10c] = 0;
          TeamFortress_SetSkin__11CBasePlayer(param_1);
          iVar2 = param_1[0x237];
          if (iVar2 != 0) {
            (**(code **)(*(int *)(iVar2 + 0x454) + 0x128))(iVar2,0);
            *(undefined4 *)(*param_1 + 0xbc) = 0;
            *(undefined4 *)(*param_1 + 0xc0) = 0;
          }
          local_78 = 0x41800000;
          local_70 = -32.0;
          local_6c = 0xc1800000;
          local_64 = 0xc2100000;
          local_74 = local_78;
          local_68 = local_6c;
          UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_6c,&local_78);
          iVar2 = *param_1;
          local_78 = 0;
          local_70 = 4.0;
          local_74 = 0;
          *(undefined4 *)(iVar2 + 0x174) = 0;
          *(undefined4 *)(iVar2 + 0x178) = 0;
          *(undefined4 *)(iVar2 + 0x17c) = 0x40800000;
          *(undefined4 *)(*param_1 + 0x108) = 6;
          *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
          fVar1 = *(float *)(*param_1 + 0x28);
          if (0x3f < (byte)((10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1)) {
            lVar7 = (longdouble)(*DAT_0019f80c)(0,0x43960000);
            *(float *)(*param_1 + 0x28) = (float)(lVar7 + (longdouble)*(float *)(*param_1 + 0x28));
          }
          if (param_2 == 0) {
            (**(code **)(param_1[0x115] + 0x208))(param_1);
          }
          *(undefined4 *)(*param_1 + 0x50) = 0;
          *(undefined4 *)(*param_1 + 0x58) = 0;
          piVar6 = (int *)0x0;
          goto LAB_000f3d3f;
        }
      } while (((((*(byte *)(*piVar6 + 0x1a4) & 8) == 0) ||
                (iVar2 = (**(code **)(piVar6[0x115] + 0x8c))(piVar6), iVar2 == 0)) ||
               (piVar6 == param_1)) &&
              (iVar2 = (**(code **)(piVar6[0x115] + 0x2c))(piVar6), iVar2 != 1));
      pcVar5 = "#Feign_onspy";
    }
  }
  else {
    piVar6 = (int *)0x0;
    do {
      piVar6 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                (piVar6,*param_1 + 8,0x42800000);
      if (piVar6 == (int *)0x0) {
        param_1[0x1c] = 0;
        iVar2 = *param_1;
        *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar2 + 0x24) = DAT_0019f664;
        *(undefined4 *)(iVar2 + 0x28) = DAT_0019f668;
        if ((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) {
          puVar8 = &local_1c;
          local_18 = 0x41800000;
          local_14 = 36.0;
          local_c = 0xc1800000;
          local_8 = -36.0;
          puVar3 = &local_10;
        }
        else {
          puVar8 = &local_10;
          local_c = 0x41800000;
          local_8 = _FUN_00152ed4;
          local_18 = 0xc1800000;
          local_14 = -18.0;
          puVar3 = &local_1c;
        }
        local_1c = local_18;
        local_10 = local_c;
        UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,puVar3,puVar8);
        iVar2 = *param_1;
        local_1c = 0;
        local_14 = 28.0;
        local_18 = 0;
        *(undefined4 *)(iVar2 + 0x174) = 0;
        *(undefined4 *)(iVar2 + 0x178) = 0;
        *(undefined4 *)(iVar2 + 0x17c) = 0x41e00000;
        *(undefined4 *)(*param_1 + 0x108) = 3;
        *(undefined4 *)(*param_1 + 0x170) = 0;
        *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
        *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) & 0xfe;
        TeamFortress_SetSpeed__11CBasePlayer(param_1);
        iVar2 = param_1[0x237];
        if (iVar2 != 0) {
          (**(code **)(*(int *)(iVar2 + 0x454) + 0x120))(iVar2);
        }
        *(undefined4 *)(*param_1 + 0x138) = 0xbf800000;
        param_1[0x285] = 0;
        SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
        *(undefined4 *)(*param_1 + 0x24c) = 0;
        return;
      }
    } while (((((*(byte *)(*piVar6 + 0x1a4) & 8) == 0) ||
              (iVar2 = (**(code **)(piVar6[0x115] + 0x8c))(piVar6), iVar2 == 0)) ||
             (piVar6 == param_1)) &&
            (iVar2 = (**(code **)(piVar6[0x115] + 0x2c))(piVar6), iVar2 != 1));
    pcVar5 = "#Feign_unabletogetup";
  }
LAB_000f3965:
  ClientPrint__FP9entvars_siPCcN42(*param_1,4,pcVar5,0,0,0,0);
  return;
LAB_000f3d3f:
  do {
    do {
      piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"item_tfgoal");
      if (piVar6 == (int *)0x0) {
        *(undefined4 *)(*param_1 + 0x24c) = 1;
        return;
      }
    } while (*(int *)(*piVar6 + 0x198) != *(int *)(*param_1 + 0x208));
    if (((*(byte *)((int)piVar6 + 0x229) & 1) == 0) || (param_1[0x1e] == 1)) {
      tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar6,param_1,0);
    }
  } while (CTF_Map != 1);
  if (piVar6[0x84] != 1) goto LAB_000f3c78;
  uVar4 = UTIL_VarArgs__FPce("%s LOST the BLUE flag!\n",
                             *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
  UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
  if (param_1[0x48] == 0) {
    pcVar5 = "SPECTATOR";
  }
  else {
    pcVar5 = (char *)GetTeamName__Fi(param_1[0x48]);
  }
  uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar5);
  uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
  iVar2 = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
  pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Dropped_Blue_Flag\"\n";
  goto LAB_000f3d2e;
LAB_000f3c78:
  if (piVar6[0x84] == 2) {
    uVar4 = UTIL_VarArgs__FPce("%s LOST the RED flag!\n",
                               *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
    UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
    if (param_1[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_1[0x48]);
    }
    uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar5);
    uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
    iVar2 = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Dropped_Red_Flag\"\n";
LAB_000f3d2e:
    UTIL_LogPrintf__FPce(pcVar5,iVar2,uVar4);
  }
  goto LAB_000f3d3f;
}


// TeamFortress_SpyGoUndercover__11CBasePlayer  @ 000f4384
void TeamFortress_SpyGoUndercover__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
    if (param_1[0x19] == 2) {
      ClientPrint__FP9entvars_siPCcN42(iVar1,4,"#Disguise_stop",0,0,0,0);
      iVar1 = FindTimer__11CBaseEntityi(param_1,0xd);
      if (iVar1 != 0) {
        UTIL_Remove__FP11CBaseEntity(iVar1);
      }
      param_1[0x19] = 0;
    }
    else {
      param_1[0x44] = 0x41400000;
    }
  }
  else {
    ClientPrint__FP9entvars_siPCcN42(iVar1,4,"#Spy_unable",0,0,0,0);
  }
  return;
}


// TeamFortress_StatusQuery__Fv  @ 00113e0c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_StatusQuery__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar4 = 0;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    iVar3 = 1;
    do {
      iVar1 = UTIL_PlayerByIndex__Fi();
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x120) == 4)) {
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(gpGlobals + 0x90));
  }
  iVar3 = 0;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    iVar1 = 1;
    do {
      iVar2 = UTIL_PlayerByIndex__Fi(iVar1);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x120) == 3)) {
        iVar3 = iVar3 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= *(int *)(gpGlobals + 0x90));
  }
  uVar5 = CONCAT44(iVar4,iVar3);
  iVar4 = 0;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    iVar3 = 1;
    do {
      iVar1 = UTIL_PlayerByIndex__Fi(iVar3,uVar5);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x120) == 2)) {
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(gpGlobals + 0x90));
  }
  iVar3 = 0;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    iVar1 = 1;
    do {
      iVar2 = UTIL_PlayerByIndex__Fi(iVar1,iVar4);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x120) == 1)) {
        iVar3 = iVar3 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= *(int *)(gpGlobals + 0x90));
  }
  (*DAT_0019f794)(1,"players per team: %d %d %d %d\n",iVar3);
  (*DAT_0019f794)(1,"    equalisation: %0.1f %0.1f %0.1f %0.1f\n",(double)DAT_001ac4c8,
                  (double)_DAT_001ac4cc,(double)_DAT_001ac4d0,(double)_DAT_001ac4d4);
  (*DAT_0019f794)(1,"Teamplay is %d\n",(double)*(float *)(gpGlobals + 0x1c));
  return;
}


// TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_sf  @ 0008e900
void TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_sf(void)

{
  return;
}


// TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_sf  @ 000e343c
void TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_sf
               (int *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
  if (iVar3 == 0) {
    return;
  }
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x20c) != 0) {
    local_10 = *(float *)(iVar3 + 8) - *(float *)(param_2 + 8);
    local_c = *(float *)(iVar3 + 0xc) - *(float *)(param_2 + 0xc);
    local_8 = *(float *)(iVar3 + 0x10) - *(float *)(param_2 + 0x10);
    iVar3 = *(int *)(param_2 + 0x208);
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar3 + 0x7c);
    }
    fVar1 = local_8 * local_8 + local_c * local_c + local_10 * local_10;
    fVar2 = (param_3 - SQRT(fVar1) * 0.5) * 0.03;
    fVar1 = SQRT(fVar1);
    if (0x3f < (byte)((16.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 16.0) << 0xe) >> 8)) - 1)) {
      iVar3 = *param_1;
      local_10 = *(float *)(iVar3 + 0x20) * 0.33;
      local_c = *(float *)(iVar3 + 0x24) * 0.33;
      local_8 = *(float *)(iVar3 + 0x28) * 0.33;
    }
    iVar3 = *param_1;
    *(float *)(iVar3 + 0x20) = local_10;
    *(float *)(iVar3 + 0x24) = local_c;
    *(float *)(iVar3 + 0x28) = local_8;
    *(float *)(*param_1 + 0x20) = *(float *)(*param_1 + 0x20) * fVar2;
    *(float *)(*param_1 + 0x24) = *(float *)(*param_1 + 0x24) * fVar2;
    *(float *)(*param_1 + 0x28) = *(float *)(*param_1 + 0x28) * fVar2 * 1.5;
    if ((((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) && (0 < param_1[0x48])) &&
        (iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,uVar5), iVar3 != 0)) &&
       (*(int *)(param_2 + 0x198) != *(int *)(*param_1 + 0x208))) {
      return;
    }
    (*DAT_0019f758)(1,gmsgDamage,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(0);
    (*DAT_0019f760)(0);
    (*DAT_0019f76c)(0x200);
    (*DAT_0019f774)(*(undefined4 *)(param_2 + 8));
    (*DAT_0019f774)(*(undefined4 *)(param_2 + 0xc));
    (*DAT_0019f774)(*(undefined4 *)(param_2 + 0x10));
    (*DAT_0019f75c)();
    (**(code **)(param_1[0x115] + 0x104))(param_1,param_2);
    iVar3 = *(int *)(param_2 + 0x198);
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(iVar3 + 0x7c);
    }
    if (param_1[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(param_1[0x48]);
    }
    uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar4);
    uVar5 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar5);
    if (piVar6[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(piVar6[0x48],
                                       *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar5
                                      );
    }
    uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(param_2 + 0x198),pcVar4);
    uVar5 = (*DAT_0019f864)(*(undefined4 *)(param_2 + 0x198),uVar5);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%s><%s>\" triggered \"Concussion_Grenade\" against \"%s<%i><%s><%s>\"\n",
               *(int *)(*piVar6 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar5);
    return;
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_s  @ 0010458c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_s(int *param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"tf_gl_pipebomb");
  if (iVar1 == 0) {
    *(float *)(*param_1 + 0x104) = (float)_FUN_00154d00 + *gpGlobals;
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_s  @ 00124b30
void TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_s(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_c;
  undefined4 local_8;
  
  if (*(int *)(param_2 + 0x198) == 0) {
    (*DAT_0019f7b4)(0);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_0019f7b4)(0);
  }
  (**(code **)(param_1[0x115] + 0xf4))(param_1,&local_c,&local_8);
  if (0x3f < (byte)((local_c < 0.0 | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) - 1)) {
    (**(code **)(param_1[0x115] + 0xf0))(param_1,param_2,local_c,local_8);
    fVar1 = (float)param_1[0x11d];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      iVar2 = *(int *)(*param_1 + 400);
      if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      if ((iVar2 != 0) && (iVar3 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x2c))(iVar2), iVar3 == 2)
         ) {
        *(int *)(iVar2 + 0xdb4) = *(int *)(iVar2 + 0xdb4) + -1;
      }
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_s  @ 0008e908
void TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_s(void)

{
  return;
}


// TeamFortress_TakeEMPBlast__11CBasePlayerP9entvars_s  @ 000e325c
void TeamFortress_TakeEMPBlast__11CBasePlayerP9entvars_s(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  ushort in_FPUControlWord;
  float local_1c;
  undefined4 local_18;
  ushort local_14;
  undefined4 local_10;
  ushort local_8;
  undefined2 uStack_6;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_0019f7b4)(0);
  }
  if ((*(int *)(*param_1 + 0x20c) != 0) &&
     (((local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord)),
       ((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) == 0 ||
       (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar2), iVar1 == 0)) ||
      (piVar2 == param_1)))) {
    (**(code **)(param_1[0x115] + 0xf4))(param_1,&local_1c,&local_18);
    param_1[0x33] = (int)ROUND((double)param_1[0x33] - ROUND((double)param_1[0x33] * 0.25));
    param_1[0x39] = (int)ROUND((double)param_1[0x39] - ROUND((double)param_1[0x39] * 0.25));
    if (*(int *)(*param_1 + 0x20c) != 9) {
      param_1[0x37] = (int)ROUND((double)param_1[0x37] - ROUND((double)param_1[0x37] * 0.25));
    }
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_14 = in_FPUControlWord & 0xf3ff | 0x800;
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    if (0.0 < local_1c) {
      (**(code **)(param_1[0x115] + 0xf0))(param_1,param_2,local_1c,local_18);
    }
  }
  return;
}


// TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_s  @ 0009c61c
void TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_0019f7b4)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar3), iVar1 != 0)) &&
     (puVar2 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar3 != puVar2)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x454) + 0x38))(param_1,param_2,*puVar3,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_s  @ 000ed618
void TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_0019f7b4)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar3), iVar1 != 0)) &&
     (puVar2 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar3 != puVar2)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x454) + 0x38))(param_1,param_2,*puVar3,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__8CDetpackP9entvars_s  @ 0009ac58
void TeamFortress_TakeEMPBlast__8CDetpackP9entvars_s(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_0019f80c)(0,0x40000000);
  *(float *)(*param_1 + 0x160) = (float)((longdouble)1 + (longdouble)*gpGlobals + lVar1);
  return;
}


// TeamFortress_TeamGetNoPlayers__Fi  @ 00114244
int TeamFortress_TeamGetNoPlayers__Fi(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    iVar2 = 1;
    do {
      iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x120) == param_1)) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(gpGlobals + 0x90));
  }
  return iVar3;
}


// TeamFortress_TeamGetScoreFrags__Fi  @ 001142a8
undefined4 TeamFortress_TeamGetScoreFrags__Fi(int param_1)

{
  return *(undefined4 *)(teamscores + param_1 * 4);
}


// TeamFortress_TeamIncreaseScore__Fii  @ 00113548
void TeamFortress_TeamIncreaseScore__Fii(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_1 != 0) {
    *(int *)(teamscores + param_1 * 4) = *(int *)(teamscores + param_1 * 4) + param_2;
    (*DAT_0019f758)(2,gmsgTeamScore,0,0);
    if (param_1 < 1) {
      puVar1 = &DAT_00157c9c;
    }
    else if ((&team_names)[param_1] == 0) {
      puVar1 = *(undefined **)(sTNameCvars + param_1 * 4 + 0x1c);
    }
    else {
      puVar1 = (undefined *)(*(int *)(gpGlobals + 0x98) + (&team_names)[param_1]);
    }
    (*DAT_0019f778)(puVar1);
    (*DAT_0019f768)(*(undefined4 *)(teamscores + param_1 * 4));
    (*DAT_0019f768)(0);
    (*DAT_0019f75c)();
  }
  return;
}


// TeamFortress_TeamIsCivilian__Ff  @ 0011411c
undefined4 TeamFortress_TeamIsCivilian__Ff(float param_1)

{
  byte bVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == 1.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = civilianteams & 1;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_1 == 2.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = civilianteams & 2;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_1 == 3.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = civilianteams & 4;
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_1 == 4.0) << 0xe) >> 8)) != 0x40) {
      if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) != 0x40) {
        return 0;
      }
      if (illegalclasses == -1) {
        return 1;
      }
      return 0;
    }
    bVar1 = civilianteams & 8;
  }
  if (bVar1 != 0) {
    return 1;
  }
  return 0;
}


// TeamFortress_TeamPutPlayerInTeam__11CBasePlayer  @ 000e12e8
void TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  
  lVar6 = (longdouble)(*DAT_0019f80c)(0,number_of_teams);
  fVar1 = (float)ROUND(lVar6);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = number_of_teams;
  }
  fVar2 = number_of_teams + 1.0;
  iVar5 = 0x21;
  if (0x3f < (byte)((fVar2 < 1.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) - 1)) {
    iVar4 = 1;
    do {
      iVar3 = TeamFortress_TeamGetNoPlayers__Fi(iVar4);
      if (iVar4 == *(int *)(*param_1 + 0x1ac)) {
        iVar3 = iVar3 + -1;
      }
      if ((iVar3 < iVar5) && (iVar3 < *(int *)(teammaxplayers + iVar4 * 4))) {
        fVar1 = (float)iVar4;
        iVar5 = iVar3;
      }
      iVar4 = iVar4 + 1;
    } while ((float)iVar4 < number_of_teams + 1.0);
  }
  TeamFortress_TeamSet__11CBasePlayeri(param_1,(int)ROUND(fVar1));
  return;
}


// TeamFortress_TeamSetColor__Fi  @ 00113100
void TeamFortress_TeamSetColor__Fi(void)

{
  teamcolors._104_4_ = 0x99;
  teamcolors._108_4_ = 0x8b;
  teamcolors._112_4_ = 0x99;
  teamcolors._116_4_ = 0x91;
  teamcolors._120_4_ = 0x99;
  teamcolors._124_4_ = 0x82;
  teamcolors._128_4_ = 0x99;
  teamcolors._132_4_ = 0x91;
  teamcolors._136_4_ = 0x99;
  teamcolors._140_4_ = 0x8c;
  teamcolors._144_4_ = 0x94;
  teamcolors._148_4_ = 0x8a;
  teamcolors._152_4_ = 0x8c;
  teamcolors._156_4_ = 0x91;
  teamcolors._160_4_ = 0x96;
  teamcolors._164_4_ = 0x91;
  teamcolors._168_4_ = 0x8c;
  teamcolors._172_4_ = 0x94;
  teamcolors._184_4_ = 0x96;
  teamcolors._188_4_ = 0x8c;
  teamcolors._176_4_ = 0x96;
  teamcolors._180_4_ = 0;
  teamcolors._200_4_ = 0xff;
  teamcolors._204_4_ = 10;
  teamcolors._208_4_ = 0xff;
  teamcolors._212_4_ = 10;
  teamcolors._216_4_ = 0xfa;
  teamcolors._220_4_ = 0x1c;
  teamcolors._224_4_ = 0xff;
  teamcolors._228_4_ = 0x14;
  teamcolors._232_4_ = 0xff;
  teamcolors._236_4_ = 0xfa;
  teamcolors._240_4_ = 0xff;
  teamcolors._244_4_ = 0x19;
  teamcolors._248_4_ = 0xfa;
  teamcolors._252_4_ = 0x19;
  teamcolors._256_4_ = 0xfa;
  teamcolors._260_4_ = 0xf0;
  teamcolors._264_4_ = 5;
  teamcolors._268_4_ = 0xfa;
  teamcolors._280_4_ = 0xfa;
  teamcolors._284_4_ = 0xf0;
  teamcolors._272_4_ = 0xfa;
  teamcolors._276_4_ = 0;
  teamcolors._296_4_ = 0x2d;
  teamcolors._300_4_ = 0x23;
  teamcolors._304_4_ = 0x2d;
  teamcolors._308_4_ = 0x23;
  teamcolors._312_4_ = 0x2d;
  teamcolors._316_4_ = 0x23;
  teamcolors._320_4_ = 0x2d;
  teamcolors._324_4_ = 0x23;
  teamcolors._328_4_ = 0x2d;
  teamcolors._332_4_ = 0x23;
  teamcolors._336_4_ = 0x2d;
  teamcolors._340_4_ = 0x28;
  teamcolors._344_4_ = 0x2d;
  teamcolors._348_4_ = 0x23;
  teamcolors._352_4_ = 0x2d;
  teamcolors._356_4_ = 0x23;
  teamcolors._360_4_ = 0x2d;
  teamcolors._364_4_ = 0x2d;
  teamcolors._376_4_ = 0x2d;
  teamcolors._380_4_ = 0x23;
  teamcolors._368_4_ = 0x2d;
  teamcolors._372_4_ = 0;
  teamcolors._392_4_ = 100;
  teamcolors._396_4_ = 0x5a;
  teamcolors._400_4_ = 0x50;
  teamcolors._404_4_ = 0x5a;
  teamcolors._408_4_ = 100;
  teamcolors._412_4_ = 0x28;
  teamcolors._416_4_ = 100;
  teamcolors._420_4_ = 0x5a;
  teamcolors._424_4_ = 100;
  teamcolors._428_4_ = 0x5a;
  teamcolors._432_4_ = 100;
  teamcolors._436_4_ = 0x5a;
  teamcolors._440_4_ = 100;
  teamcolors._444_4_ = 0x32;
  teamcolors._448_4_ = 100;
  teamcolors._452_4_ = 0x5a;
  teamcolors._456_4_ = 100;
  teamcolors._460_4_ = 0x5a;
  teamcolors._472_4_ = 100;
  teamcolors._476_4_ = 0x5a;
  teamcolors._464_4_ = 100;
  teamcolors._468_4_ = 0;
  rgbcolors = 0x437f0000;
  DAT_001ac224 = 0x437f0000;
  DAT_001ac228 = 0x437f0000;
  DAT_001ac22c = 0;
  DAT_001ac230 = 0;
  DAT_001ac234 = 0x437f0000;
  DAT_001ac238 = 0x437f0000;
  DAT_001ac23c = 0;
  DAT_001ac240 = 0;
  DAT_001ac244 = 0x437f0000;
  DAT_001ac248 = 0x437f0000;
  DAT_001ac24c = 0x41f00000;
  DAT_001ac250 = 0;
  DAT_001ac254 = 0x437f0000;
  DAT_001ac258 = 0;
  return;
}


// TeamFortress_TeamSet__11CBasePlayeri  @ 000e13fc
undefined4 TeamFortress_TeamSet__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if ((param_1[0x48] < 1) || (param_1[0x48] != param_2)) {
    if ((byte)((byte)((ushort)((ushort)NAN(gpGlobals[7]) << 10) >> 8) |
              (byte)((ushort)((ushort)(gpGlobals[7] == 0.0) << 0xe) >> 8)) == 0x40) {
      uVar7 = 0;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = 0;
      pcVar3 = "#Game_noteams";
      iVar1 = *param_1;
    }
    else if (((float)param_2 <= number_of_teams) ||
            ((byte)(number_of_teams < 0.0 |
                    (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                   (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) == 0x40)) {
      if (*(int *)(*param_1 + 0x170) == 1) {
        return 0;
      }
      if (*gpGlobals < (float)param_1[0x1c6]) {
        return 0;
      }
      iVar1 = TeamFortress_TeamGetNoPlayers__Fi(param_2);
      if (iVar1 < *(int *)(teammaxplayers + param_2 * 4)) {
        if (param_1[0x48] < 1) {
          uVar4 = UTIL_dtos1__Fi(param_2,0,0);
          UTIL_ClientPrintAll__FiPCcN41
                    (1,"#Game_joinedteam",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          if (param_2 == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_2);
          }
          if (param_1[0x48] == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_1[0x48],pcVar3);
          }
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" joined team \"%s\"\n",
                     *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
        }
        else {
          uVar4 = UTIL_dtos1__Fi(param_2,0,0);
          UTIL_ClientPrintAll__FiPCcN41
                    (1,"#Game_changedteam",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          if (param_2 == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_2);
          }
          if (param_1[0x48] == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_1[0x48],pcVar3);
          }
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" joined team \"%s\"\n",
                     *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          if ((param_1[0x21] & 1U) != 0) {
            param_1[0x20] = 1;
            param_1[0x21] = param_1[0x21] & 0xfffffffe;
          }
          TeamFortress_RemoveBuildings__11CBasePlayer(param_1);
          TeamFortress_RemoveDetpacks__11CBasePlayer(param_1);
          TeamFortress_RemoveLiveGrenades__11CBasePlayer(param_1);
          TeamFortress_RemoveRockets__11CBasePlayer(param_1);
          *(undefined4 *)(*param_1 + 0x20c) = 0;
          param_1[0x21f] = 1;
          param_1[0x222] = 0;
          param_1[0xb] = 0;
          if (((*(byte *)(param_1 + 0x21) & 0x10) != 0) &&
             (piVar2 = (int *)FindTimer__11CBaseEntityi(param_1,2), piVar2 != (int *)0x0)) {
            iVar1 = *(int *)(*piVar2 + 400);
            if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
              uVar4 = 0;
            }
            else {
              uVar4 = *(undefined4 *)(iVar1 + 0x7c);
            }
            TF_AddFrags__11CBasePlayeri(uVar4,1);
          }
          param_1[0x21] = 0;
          RemoveAllItems__11CBasePlayeri(param_1,0);
          param_1[0x1c5] = (int)(*gpGlobals + 0.2);
          *(undefined4 *)(*param_1 + 0x160) = 0;
          (**(code **)(param_1[0x115] + 0x40))(param_1,0,*param_1,1);
          iVar1 = param_1[0x4b];
          param_1[0x4b] = iVar1 + 1;
          *(float *)(*param_1 + 0x164) = (float)(iVar1 + 1);
          param_1[0x27f] = param_1[0x27f] + -1;
        }
        param_1[0x48] = param_2;
        param_1[0x367] = 1;
        param_1[0x23a] = 0;
        *(int *)(*param_1 + 0x1ac) = param_2;
        param_1[0x49] = *(int *)(teamlives + param_2 * 4);
        param_1[0x1c6] = (int)(*gpGlobals + 1.0);
        iVar1 = 1;
        if (0 < (int)gpGlobals[0x24]) {
          do {
            piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar1);
            if (piVar2 != (int *)0x0) {
              (*DAT_0019f758)(1,gmsgTeamInfo,0,*(undefined4 *)(*piVar2 + 0x208));
              uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
              (*DAT_0019f760)(uVar4);
              uVar4 = (**(code **)(*g_pGameRules + 0xcc))(g_pGameRules,param_1);
              (*DAT_0019f778)(uVar4);
              (*DAT_0019f75c)();
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 <= (int)gpGlobals[0x24]);
        }
        TeamFortress_TeamIncreaseScore__Fii(param_1[0x48],0);
        TeamFortress_SetSkin__11CBasePlayer(param_1);
        Menu_Class__11CBasePlayer(param_1);
        return 1;
      }
      if (param_1[0x48] == 0) {
        Menu_Team__11CBasePlayer(param_1);
      }
      uVar7 = 0;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = 0;
      pcVar3 = "#Game_teamfull";
      iVar1 = *param_1;
    }
    else {
      uVar7 = 0;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = UTIL_dtos1__Fi((int)ROUND(number_of_teams),0,0,0);
      pcVar3 = "Game_onlyteams";
      iVar1 = *param_1;
    }
    ClientPrint__FP9entvars_siPCcN42(iVar1,1,pcVar3,uVar4,uVar5,uVar6,uVar7);
  }
  return 0;
}


// TeamFortress_TeamShowMemberClasses__11CBasePlayer  @ 000e19a8
void TeamFortress_TeamShowMemberClasses__11CBasePlayer(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  bVar1 = false;
  iVar5 = 1;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    do {
      piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar5);
      if (((piVar2 != (int *)0x0) && (piVar2 != param_1)) &&
         (iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar2), iVar3 != 0)) {
        if (!bVar1) {
          bVar1 = true;
          ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_others",0,0,0,0);
        }
        uVar4 = UTIL_VarArgs__FPce(&DAT_00150cb5,(&sClassNames)[*(int *)(*piVar2 + 0x20c)],0,0);
        ClientPrint__FP9entvars_siPCcN42
                  (*param_1,1,"#Game_othersdetails",
                   *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= *(int *)(gpGlobals + 0x90));
  }
  if (!bVar1) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_noothers",0,0,0,0);
  }
  return;
}


// TeamFortress_TeamShowScores__FiP11CBasePlayer  @ 00112fe8
void TeamFortress_TeamShowScores__FiP11CBasePlayer(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 1;
  if (1.0 <= number_of_teams) {
    do {
      if (param_1 == 0) {
        uVar1 = UTIL_VarArgs__FPce("%s: %d\n",*(undefined4 *)(g_szTeamColors + iVar2 * 4),
                                   *(undefined4 *)(teamscores + iVar2 * 4),0,0,0,0);
LAB_0011308b:
        UTIL_ClientPrintAll__FiPCcN41(1,uVar1);
      }
      else {
        if (param_2 == (undefined4 *)0x0) {
          uVar1 = UTIL_VarArgs__FPce("Team %d (%s): %d\n",iVar2,
                                     *(undefined4 *)(g_szTeamColors + iVar2 * 4),
                                     *(undefined4 *)(teamscores + iVar2 * 4),0,0,0,0);
          goto LAB_0011308b;
        }
        uVar1 = UTIL_VarArgs__FPce("Team %d (%s): %d\n",iVar2,
                                   *(undefined4 *)(g_szTeamColors + iVar2 * 4),
                                   *(undefined4 *)(teamscores + iVar2 * 4),0,0,0,0);
        ClientPrint__FP9entvars_siPCcN42(*param_2,1,uVar1);
      }
      iVar2 = iVar2 + 1;
    } while ((float)iVar2 <= number_of_teams);
  }
  return;
}


// TeamFortress_ThrowPrimedGrenade__11CBasePlayer  @ 000e3fb8
void TeamFortress_ThrowPrimedGrenade__11CBasePlayer(int param_1)

{
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    *(byte *)(param_1 + 0x85) = *(byte *)(param_1 + 0x85) | 4;
  }
  return;
}


// TeamFortress_UpdateStatusBar__11CBasePlayer  @ 000fdd14
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void TeamFortress_UpdateStatusBar__11CBasePlayer(int *param_1)

{
  float fVar1;
  bool bVar2;
  char *pcVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *__src;
  undefined1 *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  uint *puVar11;
  char *pcVar12;
  int iVar13;
  bool bVar14;
  ushort in_FPUControlWord;
  int iStack_1cc;
  undefined4 *puStack_1c0;
  int *piStack_1a4;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  undefined1 auStack_168 [16];
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  int iStack_138;
  int iStack_130;
  undefined4 uStack_128;
  float fStack_124;
  uint local_120;
  char acStack_11c [124];
  undefined4 local_a0;
  char acStack_9c [124];
  int local_20 [6];
  undefined4 uStack_8;
  
  memset(local_20,0,0x1c);
  local_a0 = local_a0 & 0xffffff00;
  __src = param_1 + 0x332;
  strcpy((char *)&local_120,(char *)__src);
  fVar1 = *gpGlobals;
  if (((byte)(fVar1 < cb_prematch_time |
              (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) == 1) ||
     (fVar1 < (float)param_1[0x4c])) {
    if ((byte)((cb_prematch_time < fVar1 |
                (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      local_120._0_1_ = '#';
      local_120._1_1_ = 'S';
      local_120._2_1_ = 'b';
      local_120._3_1_ = 'a';
      builtin_strncpy(acStack_11c,"r_dead",7);
      fVar1 = (float)param_1[0x4c];
    }
    else {
      puVar9 = (uint *)"#Sbar_prematch";
      puVar11 = &local_120;
      for (iVar7 = 3; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      *(short *)puVar11 = (short)*puVar9;
      *(char *)((int)puVar11 + 2) = *(char *)((int)puVar9 + 2);
      if ((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
         ) {
        pcVar3 = "#Sbar_battleid";
        puVar10 = &local_a0;
        for (iVar7 = 3; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar10 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          puVar10 = puVar10 + 1;
        }
        *(undefined2 *)puVar10 = *(undefined2 *)pcVar3;
        *(char *)((int)puVar10 + 2) = pcVar3[2];
        if ((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
                   (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) !=
            0x40) {
          local_20[5] = param_1[0x7d];
        }
      }
      uStack_8 = cease_fire;
      fVar1 = cb_prematch_time;
    }
                    /* WARNING: Ignoring partial resolution of indirect */
    fStack_124._0_2_ = in_FPUControlWord & 0xf3ff | 0x800;
    iVar7 = (int)ROUND(ROUND(fVar1 - *gpGlobals)) % 0x3c;
    if (iVar7 == 1) {
      local_20[3] = 1;
    }
    else {
      local_20[1] = iVar7;
    }
                    /* WARNING: Ignoring partial resolution of indirect */
    fStack_124._0_2_ = in_FPUControlWord & 0xf3ff | 0x800;
    uStack_128 = CONCAT22(uStack_128._2_2_,in_FPUControlWord);
    iStack_130 = (int)ROUND(ROUND(fVar1 - *gpGlobals) * 0.016666668);
    if (iStack_130 == 1) {
      local_20[4] = 1;
      puVar8 = &stack0xfffffdd0;
    }
    else {
      local_20[2] = iStack_130;
      puVar8 = &stack0xfffffdd0;
    }
    goto LAB_000fe9f5;
  }
  iVar7 = *param_1;
  fStack_174 = *(float *)(iVar7 + 0x74) + *(float *)(iVar7 + 0x68);
  fStack_170 = *(float *)(iVar7 + 0x78) + *(float *)(iVar7 + 0x6c);
  fStack_16c = *(float *)(iVar7 + 0x7c) + *(float *)(iVar7 + 0x70);
  UTIL_MakeVectors__FRC6Vector();
  (**(code **)(param_1[0x115] + 0xd0))(&fStack_174,param_1);
  fStack_180 = gpGlobals[10] * 2048.0 + fStack_174;
  fStack_17c = gpGlobals[0xb] * 2048.0 + fStack_170;
  fStack_178 = gpGlobals[0xc] * 2048.0 + fStack_16c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_174,&fStack_180,0,*(undefined4 *)(*param_1 + 0x208),auStack_168);
  if ((byte)(1.0 < fStack_158 | (byte)((ushort)((ushort)NAN(fStack_158) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_158 == 1.0) << 0xe) >> 8)) != 0x40) {
    bVar14 = false;
    if ((iStack_138 == 0) || (iVar7 = (*DAT_0019f7b8)(iStack_138), iVar7 == 0)) {
      bVar14 = true;
    }
    if (bVar14) {
      if (*gpGlobals < (float)param_1[0x379]) {
        local_20[1] = param_1[0x373];
        local_20[2] = param_1[0x374];
        local_20[3] = param_1[0x375];
      }
    }
    else {
      if ((iStack_138 == 0) && (iStack_138 = (*DAT_0019f7b4)(0), iStack_138 == 0)) {
        piStack_1a4 = (int *)0x0;
      }
      else {
        piStack_1a4 = *(int **)(iStack_138 + 0x7c);
      }
      bVar14 = false;
      iVar7 = (**(code **)(piStack_1a4[0x115] + 0x2c))(piStack_1a4);
      if (iVar7 == 2) {
        if (((piStack_1a4[0x1c] == 0) ||
            (iVar7 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_1a4), iVar7 != 0)) ||
           (*(int *)(*param_1 + 0x244) != 0)) {
          bVar2 = false;
          iVar7 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_1a4);
          if (((iVar7 != 0) ||
              (fStack_124 = SQRT((fStack_16c - fStack_14c) * (fStack_16c - fStack_14c) +
                                 (fStack_170 - fStack_150) * (fStack_170 - fStack_150) +
                                 (fStack_174 - fStack_154) * (fStack_174 - fStack_154)),
              fStack_124 <= 1024.0)) || (*(int *)(*param_1 + 0x244) != 0)) {
            bVar2 = true;
          }
          if (bVar2) {
            if ((*(int *)(*param_1 + 0x244) == 0) && (param_1[0x48] != 0)) {
              iVar7 = __opP11CBaseEntity__7EHANDLE(piStack_1a4 + 0x77);
              if ((iVar7 != 0) &&
                 ((param_1[0x48] != piStack_1a4[0x48] && (*(int *)(*piStack_1a4 + 0x20c) == 8)))) {
                piStack_1a4 = (int *)__opP11CBaseEntity__7EHANDLE(piStack_1a4 + 0x77);
              }
            }
            if (((byte)((float)tfc_playerid._12_4_ < 2.0 |
                        (byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                       (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 2.0) << 0xe) >> 8)) ==
                 0x40) ||
               ((((byte)((byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 1.0) << 0xe) >> 8))
                  == 0x40 &&
                 (iVar7 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_1a4), iVar7 == 0)) &&
                (*(int *)(*param_1 + 0x244) == 0)))) {
              local_120 = CONCAT22(local_120._2_2_,0x20);
            }
            else {
              puVar9 = (uint *)"1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
              puVar11 = &local_120;
              for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar11 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar11 = puVar11 + 1;
              }
              *(char *)puVar11 = (char)*puVar9;
            }
            local_20[1] = (*DAT_0019f7bc)(*(undefined4 *)(*piStack_1a4 + 0x208));
            bVar14 = true;
            __as__7EHANDLEP11CBaseEntity(param_1 + 0x37a,piStack_1a4);
          }
        }
LAB_000fe53f:
        if (!bVar14) goto LAB_000fe66a;
      }
      else {
        iVar7 = strcmp((char *)(*(int *)*piStack_1a4 + (int)gpGlobals[0x26]),"building_sentrygun");
        if (iVar7 != 0) {
          iVar7 = strcmp((char *)(*(int *)*piStack_1a4 + (int)gpGlobals[0x26]),"building_dispenser")
          ;
          if (iVar7 == 0) {
            piVar4 = (int *)__rf__7EHANDLE(piStack_1a4 + 0x51);
            local_20[1] = (*DAT_0019f7bc)(*(undefined4 *)(*piVar4 + 0x208));
            if (((byte)((float)tfc_playerid._12_4_ < 2.0 |
                        (byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                       (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 2.0) << 0xe) >> 8)) ==
                 0x40) ||
               ((((byte)((byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 1.0) << 0xe) >> 8))
                  == 0x40 && (*(int *)(*param_1 + 0x244) == 0)) &&
                (iVar7 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_1a4), iVar7 == 0)))) {
              local_120 = CONCAT22(local_120._2_2_,0x20);
            }
            else {
              puVar9 = (uint *)"1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
              puVar11 = &local_120;
              for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar11 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar11 = puVar11 + 1;
              }
              *(char *)puVar11 = (char)*puVar9;
            }
            bVar14 = true;
          }
          goto LAB_000fe53f;
        }
        piVar4 = (int *)__rf__7EHANDLE(piStack_1a4 + 0x51);
        local_20[1] = (*DAT_0019f7bc)(*(undefined4 *)(*piVar4 + 0x208));
        if (((byte)((float)tfc_playerid._12_4_ < 2.0 |
                    (byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 2.0) << 0xe) >> 8)) ==
             0x40) ||
           ((((byte)((byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 1.0) << 0xe) >> 8)) ==
              0x40 && (*(int *)(*param_1 + 0x244) == 0)) &&
            (iVar7 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_1a4), iVar7 == 0)))) {
          local_120 = CONCAT22(local_120._2_2_,0x20);
        }
        else {
          puVar9 = (uint *)"1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
          puVar11 = &local_120;
          for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          *(short *)puVar11 = (short)*puVar9;
        }
      }
      iVar7 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_1a4);
      if (((iVar7 != 0) || (*(int *)(*param_1 + 0x20c) == 5)) || (*(int *)(*param_1 + 0x244) != 0))
      {
        local_20[2] = (int)ROUND((*(float *)(*piStack_1a4 + 0x160) /
                                 *(float *)(*piStack_1a4 + 0x1b0)) * 100.0);
        uStack_128 = CONCAT22(uStack_128._2_2_,in_FPUControlWord);
        iStack_130 = CONCAT22(uStack_128._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
        local_20[3] = (int)ROUND((*(float *)(*piStack_1a4 + 0x1bc) / (float)piStack_1a4[0x3c]) *
                                 100.0);
      }
      param_1[0x379] = (int)(*gpGlobals + 1.0);
    }
LAB_000fe66a:
    if ((local_20[1] < 0) || ((int)gpGlobals[0x24] < local_20[1])) {
      printf("ERROR: SBAR_ID_TARGETNAME = %d\n",local_20[1]);
      local_20[1] = 0;
    }
  }
  iVar7 = *param_1;
  if (*(int *)(iVar7 + 0x20c) == 8) {
    if (param_1[0x19] == 0) {
      if (param_1[0x75] == 0) {
        if (param_1[0x76] == 0) goto LAB_000fe7f0;
        goto LAB_000fe6c6;
      }
    }
    else {
LAB_000fe6c6:
      if ((param_1[0x75] == 0) && (param_1[0x76] == 0)) {
        local_a0._0_1_ = '#';
        local_a0._1_1_ = 'S';
        local_a0._2_1_ = 'p';
        local_a0._3_1_ = 'y';
        builtin_strncpy(acStack_9c,"_disguising",0xc);
        goto LAB_000fe7f0;
      }
    }
    pcVar3 = "#Spy_disguised";
    pcVar12 = (char *)&local_a0;
    for (iVar7 = 3; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar12 = pcVar12 + 4;
    }
    *(undefined2 *)pcVar12 = *(undefined2 *)pcVar3;
    pcVar12[2] = pcVar3[2];
    if (param_1[0x75] != 0) {
      strcat((char *)&local_a0," ");
      pcVar3 = (char *)GetTeamName__Fi(param_1[0x75]);
      strcat((char *)&local_a0,pcVar3);
    }
    if (param_1[0x76] == 0) {
      strcat((char *)&local_a0," #");
      strcat((char *)&local_a0,PTR_DAT_0016e360);
      iVar7 = *param_1;
    }
    else {
      strcat((char *)&local_a0," #");
      strcat((char *)&local_a0,(&sClassNames)[param_1[0x76]]);
      iVar7 = *param_1;
    }
  }
LAB_000fe7f0:
  if (*(int *)(iVar7 + 0x20c) == 9) {
    if (param_1[0x1a] == 0) {
      fVar1 = (float)param_1[0x54];
      if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        for (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_sentrygun");
            piVar4 != (int *)0x0;
            piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                      (piVar4,"building_sentrygun")) {
          piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 0x51);
          if (piVar5 == param_1) {
            uStack_128 = CONCAT22(uStack_128._2_2_,in_FPUControlWord);
            iStack_130 = CONCAT22(uStack_128._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
            iStack_1cc = (int)ROUND((*(float *)(*piVar4 + 0x160) / *(float *)(*piVar4 + 0x1b0)) *
                                    100.0);
            if (iStack_1cc < 0) {
              iStack_1cc = 0;
            }
            if (100 < iStack_1cc) {
              iStack_1cc = 100;
            }
            sprintf((char *)&local_a0,"#Sentry_sbar %d",iStack_1cc);
            strcat((char *)&local_a0,"%%\n4   ammo: %i4%%\n0 ");
            if (piVar4[0x33] == 0) {
LAB_000fe953:
              if ((piVar4[0x39] == 0) && (piVar4[0x23] == 3)) {
                pcVar3 = "#No_Ammo";
              }
              else {
                pcVar3 = "#No_Shells";
              }
            }
            else {
              uStack_128 = CONCAT22(uStack_128._2_2_,in_FPUControlWord);
              iStack_130 = CONCAT22(uStack_128._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
              local_20[4] = (int)ROUND(((float)piVar4[0x33] / (float)piVar4[0x30]) * 100.0);
              if (piVar4[0x33] == 0) goto LAB_000fe953;
              if ((piVar4[0x39] != 0) || (piVar4[0x23] != 3)) goto LAB_000fe9b0;
              pcVar3 = "#No_Rockets";
            }
            strcat((char *)&local_a0,pcVar3);
          }
LAB_000fe9b0:
        }
      }
    }
    else {
      pcVar3 = "#Engineer_building";
      pcVar12 = (char *)&local_a0;
      for (iVar7 = 4; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined4 *)pcVar12 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar12 = pcVar12 + 4;
      }
      *(undefined2 *)pcVar12 = *(undefined2 *)pcVar3;
      pcVar12[2] = pcVar3[2];
    }
  }
  puStack_1c0 = &local_a0;
  puVar8 = &stack0xfffffdcc;
  if ((*(int *)(*param_1 + 0x20c) == 4) && (puVar8 = &stack0xfffffdcc, param_1[0x1b] != 0)) {
    pcVar3 = "#Demoman_detpacking";
    for (iVar7 = 5; puVar8 = &stack0xfffffdcc, iVar7 != 0; iVar7 = iVar7 + -1) {
      *puStack_1c0 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puStack_1c0 = puStack_1c0 + 1;
    }
  }
LAB_000fe9f5:
  puStack_1c0 = &local_a0;
  fVar1 = (float)param_1[0x4c];
  if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) && (fVar1 < *gpGlobals))
  {
    iVar7 = 0xb;
    bVar14 = true;
    puVar9 = &local_120;
    pcVar3 = "#Sbar_dead";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar14 = (char)*puVar9 == *pcVar3;
      puVar9 = (uint *)((int)puVar9 + 1);
      pcVar3 = pcVar3 + 1;
    } while (bVar14);
    if (bVar14) {
      local_120 = local_120 & 0xffffff00;
    }
  }
  *(int **)(puVar8 + -4) = param_1 + 0x312;
  *(undefined4 **)(puVar8 + -8) = puStack_1c0;
  *(undefined4 *)(puVar8 + -0xc) = 0xfea67;
  iVar7 = strcmp(*(char **)(puVar8 + -8),*(char **)(puVar8 + -4));
  if (iVar7 != 0) {
    *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)(puVar8 + -8) = 0;
    *(undefined4 *)(puVar8 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar8 + -0x10) = 1;
    *(undefined4 *)(puVar8 + -0x14) = 0xfea97;
    (*DAT_0019f758)();
    *(undefined4 *)(puVar8 + -4) = 0;
    *(undefined4 *)(puVar8 + -8) = 0xfeaaa;
    (*DAT_0019f760)();
    *(undefined4 **)(puVar8 + -8) = puStack_1c0;
    *(undefined4 *)(puVar8 + -0xc) = 0xfeabf;
    (*DAT_0019f778)();
    *(undefined4 *)(puVar8 + -0xc) = 0xfeacd;
    (*DAT_0019f75c)();
    *(undefined4 **)(puVar8 + -0xc) = puStack_1c0;
    *(int **)(puVar8 + -0x10) = param_1 + 0x312;
    *(undefined4 *)(puVar8 + -0x14) = 0xfeada;
    strcpy(*(char **)(puVar8 + -0x10),*(char **)(puVar8 + -0xc));
  }
  *(int **)(puVar8 + -4) = __src;
  *(uint **)(puVar8 + -8) = &local_120;
  *(undefined4 *)(puVar8 + -0xc) = 0xfeafa;
  iVar6 = strcmp(*(char **)(puVar8 + -8),*(char **)(puVar8 + -4));
  if (iVar6 != 0) {
    *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)(puVar8 + -8) = 0;
    *(undefined4 *)(puVar8 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar8 + -0x10) = 1;
    *(undefined4 *)(puVar8 + -0x14) = 0xfeb2a;
    (*DAT_0019f758)();
    *(undefined4 *)(puVar8 + -4) = 1;
    *(undefined4 *)(puVar8 + -8) = 0xfeb3d;
    (*DAT_0019f760)();
    *(uint **)(puVar8 + -8) = &local_120;
    *(undefined4 *)(puVar8 + -0xc) = 0xfeb52;
    (*DAT_0019f778)();
    *(undefined4 *)(puVar8 + -0xc) = 0xfeb60;
    (*DAT_0019f75c)();
    *(uint **)(puVar8 + -0xc) = &local_120;
    *(int **)(puVar8 + -0x10) = __src;
    *(undefined4 *)(puVar8 + -0x14) = 0xfeb73;
    strcpy(*(char **)(puVar8 + -0x10),*(char **)(puVar8 + -0xc));
  }
  iVar13 = 1;
  do {
    if ((local_20[iVar13] != param_1[iVar13 + 0x372]) || (iVar6 != 0 || iVar7 != 0)) {
      *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(*param_1 + 0x208);
      *(undefined4 *)(puVar8 + -8) = 0;
      *(undefined4 *)(puVar8 + -0xc) = gmsgStatusValue;
      *(undefined4 *)(puVar8 + -0x10) = 1;
      *(undefined4 *)(puVar8 + -0x14) = 0xfebdf;
      (*DAT_0019f758)();
      *(int *)(puVar8 + -4) = iVar13;
      *(undefined4 *)(puVar8 + -8) = 0xfebf1;
      (*DAT_0019f760)();
      *(int *)(puVar8 + -8) = local_20[iVar13];
      *(undefined4 *)(puVar8 + -0xc) = 0xfec09;
      (*DAT_0019f768)();
      *(undefined4 *)(puVar8 + -0xc) = 0xfec17;
      (*DAT_0019f75c)();
      param_1[iVar13 + 0x372] = local_20[iVar13];
    }
    iVar13 = iVar13 + 1;
  } while (iVar13 < 7);
  return;
}


