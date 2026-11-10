// TeamFortress_Build__11CBasePlayeri  @ 000b1130
void TeamFortress_Build__11CBasePlayeri(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  float **ppfVar6;
  char *pcVar7;
  float *pfStack_44;
  int *piStack_40;
  float local_30;
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
  
  piStack_40 = (int *)((int)*param_1 + 0x74);
  pfStack_44 = (float *)0xb1149;
  UTIL_MakeAimVectors__FRC6Vector();
  local_28 = gpGlobals[10];
  local_24 = gpGlobals[0xb];
  local_20 = SQRT(local_24 * local_24 + local_28 * local_28 + 0.0);
  if ((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_28 = 0.0;
    local_24 = 0.0;
    local_20 = 1.0;
  }
  else {
    local_20 = 1.0 / local_20;
    local_28 = local_20 * local_28;
    local_24 = local_20 * local_24;
    local_20 = local_20 * 0.0;
  }
  local_1c = local_28 * 64.0;
  local_18 = local_24 * 64.0;
  local_14 = local_20 * 64.0;
  fVar2 = *param_1;
  local_2c = *(float *)((int)fVar2 + 8) + local_1c;
  local_28 = *(float *)((int)fVar2 + 0xc) + local_18;
  local_24 = *(float *)((int)fVar2 + 0x10) + local_14;
  local_10 = local_2c;
  local_c = local_28;
  local_8 = local_24;
  if (param_2 == 1) {
    fVar1 = param_1[0x53];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      piStack_40 = (int *)0x0;
      pfStack_44 = (float *)0x0;
      ClientPrint__FP9entvars_tiPCcN42(fVar2,4,"#Build_onedispenser",0,0);
      return;
    }
    fVar2 = *param_1;
    local_20 = *(float *)((int)fVar2 + 0x74);
    local_1c = *(float *)((int)fVar2 + 0x78);
    local_18 = *(float *)((int)fVar2 + 0x7c);
    piStack_40 = (int *)param_1;
    pfStack_44 = &local_20;
    uVar3 = CreateDispenser__12CTFDispenserG6VectorT1P11CBaseEntity(&local_2c);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,uVar3);
    local_30 = 2.0;
  }
  else {
    if (param_2 != 2) {
      return;
    }
    fVar2 = param_1[0x54];
    if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
      piStack_40 = (int *)0x0;
      pfStack_44 = (float *)0x0;
      ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Build_onesentry",0,0);
      return;
    }
    fVar2 = *param_1;
    local_20 = *(float *)((int)fVar2 + 0x74);
    local_1c = *(float *)((int)fVar2 + 0x78);
    local_18 = *(float *)((int)fVar2 + 0x7c);
    piStack_40 = (int *)param_1;
    pfStack_44 = &local_20;
    uVar3 = CreateSentryBase__16CTFSentrygunBaseG6VectorT1P11CBaseEntity(&local_2c);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,uVar3);
    local_30 = 5.0;
  }
  piStack_40 = (int *)param_1;
  pfStack_44 = param_1 + 0x4e;
  pfStack_44 = (float *)__rf__7EHANDLE();
  iVar4 = CheckArea__11CBaseEntityP11CBaseEntity();
  if (iVar4 == 0) {
    if ((*(byte *)((int)*param_1 + 0x185) & 2) != 0) {
      param_1[0x1b] = 1.4013e-45;
      param_1[99] = *gpGlobals + 5.0;
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) | 1;
      piStack_40 = (int *)param_1;
      pfStack_44 = (float *)0xb1427;
      TeamFortress_SetSpeed__11CBasePlayer();
      if (param_1[0x20c] != 0.0) {
        piStack_40 = (int *)param_1[0x20c];
        pfStack_44 = (float *)0xb1448;
        (**(code **)(*(int *)((int)piStack_40 + 0x3c8) + 0x120))();
      }
      piStack_40 = (int *)0xb;
      pfStack_44 = param_1;
      piVar5 = (int *)CreateTimer__11CBaseEntityi();
      piVar5[3] = -0x10000;
      piVar5[4] = (int)Timer_FinishedBuilding__11CBaseEntity;
      *(float *)(*piVar5 + 0xe4) = local_30 + *gpGlobals;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x1e8),6,"weapons/building.wav",0x3f7ae148,
                 0x3f4ccccd,0,0x7d);
      return;
    }
    piStack_40 = (int *)0x0;
    pfStack_44 = (float *)0x0;
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Build_air",0,0);
    uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
    UTIL_Remove__FP11CBaseEntity(uVar3);
    ppfVar6 = (float **)&stack0xffffffc4;
  }
  else {
    if (iVar4 == 2) {
      pcVar7 = "#Build_nobuild";
    }
    else {
      pcVar7 = "#Build_noroom";
    }
    piStack_40 = (int *)0x0;
    pfStack_44 = (float *)0x0;
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,pcVar7,0,0);
    piStack_40 = (int *)(param_1 + 0x4e);
    pfStack_44 = (float *)0xb13a6;
    pfStack_44 = (float *)__opP11CBaseEntity__7EHANDLE();
    ppfVar6 = &pfStack_44;
    UTIL_Remove__FP11CBaseEntity();
  }
  *(undefined4 *)((int)ppfVar6 + -4) = 0;
  *(float **)((int)ppfVar6 + -8) = param_1 + 0x4e;
  *(undefined4 *)((int)ppfVar6 + -0xc) = 0xb13ed;
  __as__7EHANDLEP11CBaseEntity();
  return;
}


// TeamFortress_CalcEMPDmgRad__11CBaseEntityRfT1  @ 000a1cb0
void TeamFortress_CalcEMPDmgRad__11CBaseEntityRfT1(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  if (*(char *)(*param_1 + 0xf8) < '\0') {
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


// TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1  @ 000e35d0
void TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1(int param_1,float *param_2,float *param_3)

{
  *param_3 = (float)*(int *)(param_1 + 0xe4) * 1.5 + (float)*(int *)(param_1 + 0xcc) * 0.75;
  if (*(int *)(param_1 + 0x2c) != 9) {
    *param_3 = (float)*(int *)(param_1 + 0xdc) * 1.5 + *param_3;
  }
  *param_2 = *param_3;
  return;
}


// TeamFortress_CheckClassStats__11CBasePlayer  @ 000e2a80
void TeamFortress_CheckClassStats__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if ((float)param_1[0x3b] < *(float *)(*param_1 + 0x198)) {
    *(int *)(*param_1 + 0x198) = param_1[0x3b];
  }
  if ((float)param_1[0x3c] < *(float *)(*param_1 + 0x19c)) {
    *(int *)(*param_1 + 0x19c) = param_1[0x3c];
  }
  if (*(float *)(*param_1 + 0x198) < 0.0) {
    *(undefined4 *)(*param_1 + 0x198) = 0;
  }
  if (*(float *)(*param_1 + 0x19c) < 0.0) {
    *(undefined4 *)(*param_1 + 0x19c) = 0;
  }
  if (param_1[0x30] < param_1[0x33]) {
    param_1[0x33] = param_1[0x30];
  }
  if (param_1[0x33] < 0) {
    param_1[0x33] = 0;
  }
  if (param_1[0x34] < param_1[0x35]) {
    param_1[0x35] = param_1[0x34];
  }
  if (param_1[0x35] < 0) {
    param_1[0x35] = 0;
  }
  if (param_1[0x38] < param_1[0x39]) {
    param_1[0x39] = param_1[0x38];
  }
  if (param_1[0x39] < 0) {
    param_1[0x39] = 0;
  }
  if (param_1[0x36] < param_1[0x37]) {
    param_1[0x37] = param_1[0x36];
  }
  if (param_1[0x37] < 0) {
    param_1[0x37] = 0;
  }
  if (param_1[0x2e] < param_1[0x2f]) {
    param_1[0x2f] = param_1[0x2e];
  }
  if (param_1[0x2f] < 0) {
    param_1[0x2f] = 0;
  }
  if (param_1[0x32] < param_1[0x31]) {
    param_1[0x31] = param_1[0x32];
  }
  if (param_1[0x31] < 0) {
    param_1[0x31] = 0;
  }
  if (param_1[0x12] < 0) {
    param_1[0x12] = 0;
  }
  if (param_1[0x13] < 0) {
    param_1[0x13] = 0;
  }
  if (4 < param_1[0x12]) {
    param_1[0x12] = 4;
  }
  if (4 < param_1[0x13]) {
    param_1[0x13] = 4;
  }
  if ((param_1[0x14] == 3) && (2 < param_1[0x12])) {
    param_1[0x12] = 2;
  }
  if ((param_1[0x15] == 3) && (2 < param_1[0x13])) {
    param_1[0x13] = 2;
  }
  iVar2 = *param_1;
  if ((*(float *)(iVar2 + 400) < *(float *)(iVar2 + 0x140)) &&
     ((*(byte *)((int)param_1 + 0x8e) & 1) == 0)) {
    *(undefined4 *)(iVar2 + 0x140) = *(undefined4 *)(iVar2 + 400);
  }
  if (*(float *)(*param_1 + 0x140) < 0.0) {
    *(undefined4 *)(*param_1 + 0x140) = 0;
  }
  *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) & 0x1f;
  fVar1 = *(float *)(*param_1 + 0x198);
  if ((byte)((0.8 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.8) << 0xe) >> 8)) - 1) < 0x40) {
    *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) | 0x80;
  }
  else {
    fVar1 = *(float *)(*param_1 + 0x198);
    if ((byte)((0.6 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.6) << 0xe) >> 8)) - 1) < 0x40) {
      *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) | 0x40;
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x198);
      if ((byte)((0.3 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.3) << 0xe) >> 8)) - 1) < 0x40) {
        *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) | 0x20;
      }
    }
  }
  return;
}


// TeamFortress_Concuss__11CBaseEntityP9entvars_t  @ 0010ddc0
void TeamFortress_Concuss__11CBaseEntityP9entvars_t(void)

{
  return;
}


// TeamFortress_Concuss__11CBasePlayerP9entvars_t  @ 000e3ab0
void TeamFortress_Concuss__11CBasePlayerP9entvars_t(int param_1)

{
  *(undefined4 *)(param_1 + 0x968) = 100;
  *(undefined4 *)(param_1 + 0x970) = 100;
  *(undefined4 *)(param_1 + 0x974) = *gpGlobals;
  *(undefined4 *)(param_1 + 0x978) = 0x41700000;
  if (*(int *)(param_1 + 0x2c) == 5) {
    *(undefined4 *)(param_1 + 0x978) = 0x40e00000;
  }
  return;
}


// TeamFortress_DetpackStop__11CBasePlayer  @ 000a8160
void TeamFortress_DetpackStop__11CBasePlayer(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FindTimer__11CBaseEntityi(param_1,9);
  if (iVar1 != 0) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Detpack_retrieve",0,0,0,0);
    param_1[0x31] = param_1[0x31] + 1;
    dremove__FP11CBaseEntity(iVar1);
    *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xfe;
    param_1[0x1c] = 0;
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x118))(param_1[0x20c]);
  }
  return;
}


// TeamFortress_Discard__11CBasePlayer  @ 001069b0
void TeamFortress_Discard__11CBasePlayer(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  longdouble lVar10;
  int local_44;
  int local_40;
  int local_3c;
  
  local_3c = 0;
  iVar9 = 0;
  local_40 = 0;
  local_44 = 0;
  switch(param_1[0xb]) {
  case 1:
  case 8:
  case 9:
    iVar9 = param_1[0x39];
    break;
  case 2:
    iVar9 = param_1[0x39];
    local_40 = param_1[0x37];
    break;
  case 3:
  case 4:
    local_40 = param_1[0x37];
    goto LAB_00106a46;
  case 5:
    iVar9 = param_1[0x39];
    local_40 = param_1[0x37];
    break;
  case 6:
    iVar9 = param_1[0x39];
LAB_00106a46:
    local_3c = param_1[0x35];
    break;
  case 7:
    local_3c = param_1[0x35];
  }
  param_1[0x35] = param_1[0x35] - local_3c;
  param_1[0x39] = param_1[0x39] - iVar9;
  param_1[0x37] = param_1[0x37] - local_40;
  if (param_1[0xb] != 9) goto LAB_00106d76;
  iVar8 = 2;
  if (local_3c < 0x14) {
    iVar8 = 3;
  }
  if (iVar9 < 10) {
    iVar8 = iVar8 + 1;
  }
  iVar8 = (int)ROUND(ROUND((longdouble)param_1[0x37] / (longdouble)iVar8));
  fVar2 = ROUND((float)iVar8 * 0.5);
  if ((byte)(20.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 20.0) << 0xe) >> 8)) == 1) {
    local_44 = 0x14;
LAB_00106b5c:
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Drop_shells",0,0,0,0);
    param_1[0x37] = param_1[0x37] + local_44 * -2;
  }
  else {
    local_44 = (int)ROUND(ROUND((float)iVar8 * 0.5));
    if (local_44 != 0) goto LAB_00106b5c;
  }
  fVar2 = ROUND((float)iVar8 * 0.5);
  if ((byte)(10.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 10.0) << 0xe) >> 8)) == 1) {
    local_40 = 10;
LAB_00106bfc:
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Drop_cells",0,0,0,0);
    param_1[0x37] = param_1[0x37] + local_40 * -2;
  }
  else {
    local_40 = (int)ROUND(ROUND((float)iVar8 * 0.5));
    if (local_40 != 0) goto LAB_00106bfc;
  }
  if (local_3c < 0x14) {
    lVar10 = (longdouble)(0x14 - local_3c);
    if (ROUND((longdouble)iVar8) + (longdouble)local_3c <= lVar10) {
      lVar10 = ROUND((longdouble)iVar8) + (longdouble)local_3c;
    }
    iVar1 = (int)ROUND(lVar10);
    if (iVar1 != 0) {
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Drop_nails",0,0,0,0);
      param_1[0x37] = param_1[0x37] - iVar1;
    }
    local_3c = local_3c + iVar1;
  }
  if (iVar9 < 10) {
    fVar2 = (float)(10 - iVar9);
    if (ROUND((float)iVar8 * 0.5) + (float)iVar9 <= fVar2) {
      fVar2 = ROUND((float)iVar8 * 0.5) + (float)iVar9;
    }
    iVar8 = (int)ROUND(fVar2);
    if (iVar8 != 0) {
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Drop_rockets",0,0,0,0);
      param_1[0x37] = param_1[0x37] + iVar8 * -2;
    }
    iVar9 = iVar9 + iVar8;
  }
LAB_00106d76:
  if (((local_3c != 0) || (iVar9 != 0)) || (local_40 != 0)) {
    param_1[0x33a] = param_1[0x33a] + 1;
    if (3 < param_1[0x33a]) {
      RemoveOldAmmobox__11CBasePlayer(param_1);
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"items/ammopickup1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    piVar7 = (int *)GetClassPtr__H1Z10CWeaponBox_PX01_PX01(0);
    (**(code **)(piVar7[0xf2] + 8))(piVar7);
    pfVar6 = gpGlobals;
    *(int *)(*piVar7 + 0x1b0) = (int)"tf_ammobox" - (int)gpGlobals[0x26];
    *(int *)*piVar7 = (int)"tf_ammobox" - (int)pfVar6[0x26];
    *(undefined4 *)(*piVar7 + 0x170) = *(undefined4 *)(*param_1 + 0x1e8);
    piVar7[0xf9] = (int)(*pfVar6 + 2.0);
    piVar7[0x48] = param_1[0x48];
    piVar7[0xfa] = (int)*pfVar6;
    piVar7[0x35] = local_3c;
    piVar7[0x39] = iVar9;
    piVar7[0x37] = local_40;
    piVar7[0x33] = local_44;
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar7,*param_1 + 8);
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
    iVar9 = *piVar7;
    *(undefined4 *)(iVar9 + 0x50) = g_vecZero;
    *(undefined4 *)(iVar9 + 0x54) = DAT_00175484;
    *(undefined4 *)(iVar9 + 0x58) = DAT_00175488;
    pfVar6 = gpGlobals;
    iVar9 = *piVar7;
    fVar2 = gpGlobals[0xb];
    fVar3 = gpGlobals[0xc];
    fVar4 = gpGlobals[0xe];
    fVar5 = gpGlobals[0xf];
    *(float *)(iVar9 + 0x20) = gpGlobals[10] * 400.0 + gpGlobals[0xd] * 200.0;
    *(float *)(iVar9 + 0x24) = fVar2 * 400.0 + fVar4 * 200.0;
    *(float *)(iVar9 + 0x28) = fVar3 * 400.0 + fVar5 * 200.0;
    piVar7[3] = -0x10000;
    piVar7[4] = (int)Kill__10CWeaponBox;
    *(float *)(*piVar7 + 0xe4) = *pfVar6 + 30.0;
  }
  return;
}


// TeamFortress_DisplayDetectionItems__11CBasePlayer  @ 001071e0
void TeamFortress_DisplayDetectionItems__11CBasePlayer(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_tfdetect");
  if (iVar1 != 0) {
    DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(param_1,iVar1);
  }
  return;
}


// TeamFortress_DisplayLegalClasses__11CBasePlayer  @ 000e1cd0
void TeamFortress_DisplayLegalClasses__11CBasePlayer(undefined4 *param_1)

{
  uint uVar1;
  
  ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_legalclasses",0,0,0,0);
  uVar1 = *(uint *)(&illegalclasses + param_1[0x48] * 4);
  if ((((illegalclasses ^ 1) & 1) != 0) && ((((byte)uVar1 ^ 1) & 1) != 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Scout",0,0,0,0);
  }
  if (((illegalclasses & 2) == 0) && ((uVar1 & 2) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Sniper",0,0,0,0);
  }
  if (((illegalclasses & 4) == 0) && ((uVar1 & 4) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Soldier",0,0,0,0);
  }
  if (((illegalclasses & 8) == 0) && ((uVar1 & 8) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Demoman",0,0,0,0);
  }
  if (((illegalclasses & 0x10) == 0) && ((uVar1 & 0x10) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Medic",0,0,0,0);
  }
  if (((illegalclasses & 0x20) == 0) && ((uVar1 & 0x20) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#HWGuy",0,0,0,0);
  }
  if (((illegalclasses & 0x40) == 0) && ((uVar1 & 0x40) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Pyro",0,0,0,0);
  }
  if (((DAT_00182001 & 1) == 0) && ((uVar1 & 0x100) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,&DAT_0013a7f4,0,0,0,0);
  }
  if (((DAT_00182001 & 2) == 0) && ((uVar1 & 0x200) == 0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Engineer",0,0,0,0);
  }
  if ((-1 < (char)illegalclasses) && (-1 < (char)(byte)uVar1)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#RandomPC",0,0,0,0);
  }
  return;
}


// TeamFortress_EMPExplode__11CBaseEntityP9entvars_tff  @ 000a1b50
void TeamFortress_EMPExplode__11CBaseEntityP9entvars_tff
               (int *param_1,int param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  iVar2 = *(int *)(param_2 + 0x178);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001755d4)(0);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)0x0;
      goto LAB_000a1b92;
    }
  }
  puVar3 = *(undefined4 **)(iVar2 + 0xd8);
LAB_000a1b92:
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
  RadiusDamage__FG6VectorP9entvars_tT1ffii(&local_1c,param_2,*puVar3,param_3,param_4,0,0x4000040);
  (*DAT_00175578)(5,0x17,*param_1 + 8,0);
  (*DAT_00175580)(3);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175588)((int)g_sModelIndexFireball);
  (*DAT_00175580)(iVar2);
  (*DAT_00175580)(0xf);
  (*DAT_00175580)(3);
  (*DAT_0017557c)();
  return;
}


// TeamFortress_EMPRemove__11CBaseEntity  @ 000a1d20
void TeamFortress_EMPRemove__11CBaseEntity(undefined4 param_1)

{
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// TeamFortress_EMPRemove__5CItem  @ 000bd8b0
void TeamFortress_EMPRemove__5CItem(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0xb8))(param_1);
  return;
}


// TeamFortress_EngineerBuild__11CBasePlayer  @ 000b0d30
void TeamFortress_EngineerBuild__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(*param_1 + 0x185) & 2) == 0) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Build_air",0,0,0,0);
  }
  else if (param_1[0x1b] == 0) {
    if (((param_1[0x37] < 100) &&
        ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x53]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_1[0x53] == 0.0) << 0xe) >> 8)) == 0x40)) &&
       ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x54]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x54] == 0.0) << 0xe) >> 8)) == 0x40)) {
      ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Build_nometal",0,0,0,0);
    }
    else {
      param_1[0x45] = 0x41700000;
    }
  }
  else if (param_1[0x1b] == 1) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Build_stop",0,0,0,0);
    *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xfe;
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    iVar1 = FindTimer__11CBaseEntityi(param_1,0xb);
    if (iVar1 != 0) {
      dremove__FP11CBaseEntity(iVar1);
    }
    uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
    UTIL_Remove__FP11CBaseEntity(uVar2);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
    param_1[0x1b] = 0;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,"weapons/building.wav",0,0,0x20,100);
    if (param_1[0x20c] != 0) {
      (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x118))(param_1[0x20c]);
    }
  }
  return;
}


// TeamFortress_ExecClassScript__11CBasePlayer  @ 000e1ea0
void TeamFortress_ExecClassScript__11CBasePlayer(int *param_1)

{
  if ((((param_1[0xb] != 0xb) && (param_1[0xb] != 0)) && (param_1[0xb] != 10)) &&
     ((param_1[0xd] != param_1[0xb] && (param_1[0xd] = param_1[0xb], param_1[0x3f] != 0)))) {
    (*DAT_00175578)(1,9,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175598)(*(undefined4 *)(sClassCfgs + param_1[0xb] * 4));
    (*DAT_0017557c)();
  }
  return;
}


// TeamFortress_ExecMapScript__11CBasePlayer  @ 000e1f10
void TeamFortress_ExecMapScript__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x40] != 0) {
    (*DAT_00175578)(1,9,0,*(undefined4 *)(*param_1 + 0x1e8));
    uVar1 = UTIL_VarArgs__FPce("exec mapdefault.cfg\nexec %s.cfg\n",
                               *(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98));
    (*DAT_00175598)(uVar1);
    (*DAT_0017557c)();
  }
  return;
}


// TeamFortress_GetNoPlayers__Fv  @ 0010e8f0
int TeamFortress_GetNoPlayers__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar2 = 1; iVar2 <= *(int *)(gpGlobals + 0x90); iVar2 = iVar2 + 1) {
    iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
    if (iVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}


// TeamFortress_InitStatusBar__11CBasePlayer  @ 000f69e0
void TeamFortress_InitStatusBar__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0xd18) = 0;
  *(undefined1 *)(param_1 + 0xb94) = 0;
  *(undefined1 *)(param_1 + 0xc14) = 0;
  return;
}


// TeamFortress_PrimeGrenade__11CBasePlayeri  @ 000e3b20
void TeamFortress_PrimeGrenade__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((((*(byte *)(param_1 + 0x22) & 1) == 0) && ((*(byte *)((int)param_1 + 0x89) & 4) == 0)) &&
     (iVar1 = (**(code **)(param_1[0xf2] + 0x88))(param_1), iVar1 != 0)) {
    if (param_2 == 1) {
      iVar1 = param_1[0x14];
      piVar2 = param_1 + 0x12;
    }
    else {
      iVar1 = param_1[0x15];
      piVar2 = param_1 + 0x13;
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
        goto switchD_000e3b89_caseD_6;
      case 7:
        Prime__13CTFGasGrenadeP11CBaseEntity(param_1);
        break;
      case 8:
        Prime__13CTFEMPGrenadeP11CBaseEntity(param_1);
        break;
      case 9:
        Prime__17CTFCaltropGrenadeP11CBaseEntity(param_1);
      }
      *piVar2 = *piVar2 + -1;
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),1,"weapons/ax1.wav",0x3f666666,0x3f4ccccd,0,100);
    }
  }
switchD_000e3b89_caseD_6:
  return;
}


// TeamFortress_PrintClassName__11CBasePlayeri  @ 000e0440
void TeamFortress_PrintClassName__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = UTIL_VarArgs__FPce(&DAT_0013a55e,*(undefined4 *)(sClassNames + param_2 * 4),0,0,0,0);
  ClientPrint__FP9entvars_tiPCcN42(*param_1,1,uVar1);
  return;
}


// TeamFortress_RemoveDetpacks__11CBasePlayer  @ 000a81e0
void TeamFortress_RemoveDetpacks__11CBasePlayer(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  do {
    piVar1 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar1,"detpack");
    if (piVar1 == (int *)0x0) {
      return;
    }
  } while (*(int *)(*piVar1 + 0x178) != *(int *)(*param_1 + 0x1e8));
  dremove__FP11CBaseEntity(piVar1);
  return;
}


// TeamFortress_RemoveTimers__11CBasePlayer  @ 000e2680
void TeamFortress_RemoveTimers__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  char *pcVar5;
  
  param_1[0x68] = 0;
  param_1[0x1a] = 0;
  if ((*(byte *)((int)param_1 + 0x89) & 8) != 0) {
    *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0xf7;
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    param_1[0x61] = 0;
  }
  if (param_1[0x1b] != 0) {
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
    if (iVar2 != 0) {
      uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
      UTIL_Remove__FP11CBaseEntity(uVar3);
    }
  }
  param_1[0x1b] = 0;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
  if ((*(byte *)(param_1 + 0x22) & 0x10) != 0) {
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) & 0xef;
  }
  if ((*(byte *)((int)param_1 + 0x89) & 0x40) != 0) {
    *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0xbf;
  }
  while (iVar2 = FindTimer__11CBaseEntityi(param_1,0), iVar2 != 0) {
    fVar1 = *(float *)(iVar2 + 0x1c4);
    if ((byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
      SUB_Remove__11CBaseEntity(iVar2);
    }
  }
  piVar4 = (int *)0x0;
LAB_000e280d:
  do {
    do {
      piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"item_tfgoal");
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
        while (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"detpack"),
              piVar4 != (int *)0x0) {
          if (((byte)((byte)((ushort)((ushort)NAN((float)piVar4[0x43]) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)piVar4[0x43] == 1.0) << 0xe) >> 8)) == 0x40) &&
             (*(int *)(*piVar4 + 0x170) == *(int *)(*param_1 + 0x1e8))) {
            piVar4[0x43] = 0;
          }
        }
        ExplodeOldPipebomb__11CBasePlayeri(param_1,1);
        param_1[0xdd] = 0;
        ResetMenu__11CBasePlayer(param_1);
        return;
      }
    } while (*(int *)(*piVar4 + 0x178) != *(int *)(*param_1 + 0x1e8));
    if ((*(byte *)((int)piVar4 + 0x221) & 1) == 0) {
      tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar4,param_1,0);
    }
  } while (CTF_Map != 1);
  if (piVar4[0x84] != 1) goto code_r0x000e27c9;
  iVar2 = *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98);
  pcVar5 = "%s LOST the BLUE flag!\n";
  goto LAB_000e27ec;
code_r0x000e27c9:
  if (piVar4[0x84] == 2) {
    iVar2 = *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98);
    pcVar5 = "%s LOST the RED flag!\n";
LAB_000e27ec:
    uVar3 = UTIL_VarArgs__FPce(pcVar5,iVar2);
    UTIL_ClientPrintAll__FiPCcN41(4,uVar3,0,0,0,0);
  }
  goto LAB_000e280d;
}


// TeamFortress_SaveMe__11CBasePlayer  @ 00106f50
void TeamFortress_SaveMe__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  longdouble lVar7;
  char *pcVar8;
  
  fVar1 = (float)param_1[100];
  fVar2 = *gpGlobals;
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
    lVar7 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
    if ((longdouble)0.8 <= lVar7) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar8 = "speech/saveme2.wav";
    }
    else {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar8 = "speech/saveme1.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,1,pcVar8,0x3f800000,0x3f4ccccd,0,100);
    param_1[100] = (int)(*gpGlobals + 4.0);
  }
  piVar6 = (int *)0x0;
  while( true ) {
    piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"player");
    if (piVar6 == (int *)0x0) {
      return;
    }
    bVar3 = false;
    if ((*(int *)(*piVar6 + 0x1e8) == 0) ||
       (iVar4 = (*DAT_001755d8)(*(int *)(*piVar6 + 0x1e8)), iVar4 == 0)) {
      bVar3 = true;
    }
    if (bVar3) break;
    if ((*piVar6 != 0) && (((piVar6[0xb] == 5 || (piVar6[0xb] == 8)) || (piVar6[0xb] == 9)))) {
      (*DAT_00175578)(1,0x17,0,*(undefined4 *)(*piVar6 + 0x1e8));
      (*DAT_00175580)(0x7c);
      uVar5 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(uVar5);
      (*DAT_00175594)(0x42480000);
      (*DAT_00175588)((int)g_sModelIndexSaveMe);
      (*DAT_00175588)(0x28);
      (*DAT_0017557c)();
    }
  }
  return;
}


// TeamFortress_SetDetpack__11CBasePlayeri  @ 000a7ed0
void TeamFortress_SetDetpack__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  
  if ((*(byte *)((int)param_1 + 0x156) & 2) == 0) {
    return;
  }
  if (param_1[0x31] < 1) {
    return;
  }
  piVar3 = (int *)0x0;
LAB_000a7f9c:
  piVar3 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf(piVar3,*param_1 + 8,0x42820000)
  ;
  if (piVar3 != (int *)0x0) {
    iVar1 = strcmp((char *)(*(int *)*piVar3 + (int)gpGlobals[0x26]),"player");
    if ((iVar1 == 0) && (piVar3 != param_1)) {
      pcVar4 = "#Detpack_someone";
    }
    else {
      iVar1 = strcmp((char *)(*(int *)*piVar3 + (int)gpGlobals[0x26]),"building_sentrygun");
      if (iVar1 == 0) {
        pcVar4 = "#Detpack_sentry";
      }
      else {
        iVar1 = strcmp((char *)(*(int *)*piVar3 + (int)gpGlobals[0x26]),"building_dispensor");
        if (iVar1 != 0) goto code_r0x000a7f76;
        pcVar4 = "#Detpack_dispenser";
      }
    }
    goto LAB_000a806d;
  }
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x185) & 2) != 0) {
    piVar3 = (int *)0x0;
    while (piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"detpack"),
          piVar3 != (int *)0x0) {
      if (*(int *)(*piVar3 + 0x178) == *(int *)(*param_1 + 0x1e8)) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Detpack_oneactive",0,0,0,0);
        return;
      }
    }
    if (4 < param_2) {
      param_1[0x1c] = 1;
      param_1[0x31] = param_1[0x31] + -1;
      param_1[99] = (int)(*gpGlobals + 10.0);
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) | 1;
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x120))(param_1[0x20c]);
      *(undefined4 *)(*param_1 + 0xa0) = 0;
      uVar2 = UTIL_dtos1__Fi(param_2,0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Detpack_set",uVar2);
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_1,9);
      *(float *)(*piVar3 + 0xe4) = *gpGlobals + 3.0;
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_DetpackSet__11CBaseEntity;
      *(float *)(*piVar3 + 0x140) = (float)param_2;
      return;
    }
    pcVar4 = "#Detpack_fivesec";
    goto LAB_000a806d;
  }
  pcVar4 = "#Detpack_air";
  goto LAB_000a8071;
code_r0x000a7f76:
  iVar1 = strcmp((char *)(*(int *)*piVar3 + (int)gpGlobals[0x26]),"detpack");
  if (iVar1 == 0) {
    pcVar4 = "#Detpack_stack";
LAB_000a806d:
    iVar1 = *param_1;
LAB_000a8071:
    ClientPrint__FP9entvars_tiPCcN42(iVar1,1,pcVar4,0,0,0,0);
    return;
  }
  goto LAB_000a7f9c;
}


// TeamFortress_SetEquipment__11CBasePlayer  @ 000e0890
void TeamFortress_SetEquipment__11CBasePlayer(int *param_1)

{
  float fVar1;
  uint uVar2;
  int *piVar3;
  char **ppcVar4;
  char *pcStack_24;
  int *piStack_20;
  char *pcStack_1c;
  int *piStack_18;
  char *pcStack_14;
  int *piStack_10;
  char *pcStack_c;
  
  uVar2 = param_1[0x10];
  param_1[0x23] = 0;
  param_1[0x58] = 0;
  param_1[0x57] = 0;
  param_1[0x56] = 0;
  param_1[0x55] = 0;
  param_1[0x10] = 0;
  if (param_1[0xb] != 1) {
    param_1[0x11] = 0;
  }
  param_1[0xf] = 0;
  param_1[0x76] = 0;
  param_1[0x75] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1a] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x2f] = 0;
  param_1[0x2e] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x43] = 0;
  param_1[0x4c] = 0;
  param_1[0x61] = 0;
  param_1[0x22] = param_1[0x22] - (param_1[0x22] & 2U);
  if (param_1[0x48] == 0) {
    param_1[0x49] = -1;
  }
  param_1[0x23] = param_1[0x23] | uVar2 & 0x60000;
  if (param_1[0xb] == 1) {
    param_1[0x55] = param_1[0x55] | 0x290;
    param_1[0x39] = 0;
    param_1[0x35] = 100;
    param_1[0x33] = 0x19;
    param_1[0x37] = 0x32;
    param_1[0x38] = 0x19;
    param_1[0x34] = 200;
    param_1[0x30] = 0x32;
    param_1[0x36] = 100;
    param_1[0x12] = 2;
    param_1[0x13] = 3;
    param_1[0x14] = 9;
    param_1[0x15] = 2;
    param_1[0x10] = 1;
    param_1[0x7c] = 0;
    if (param_1[0x11] < 1) {
      *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 1;
    }
    *(undefined4 *)(*param_1 + 0x198) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x19c) = 0x41c80000;
    param_1[0x3b] = 0x3e99999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x44000000;
    param_1[0x3a] = 0x290;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 5;
    pcStack_c = "tf_weapon_axe";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe0a9d;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_shotgun";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe0aa8;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_ng";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe0ab3;
    GiveNamedItem__11CBasePlayerPc();
    param_1[0x33] = param_1[0x33] + -8;
    ppcVar4 = &pcStack_24;
    pcStack_24 = "tf_weapon_ng";
  }
  else if (param_1[0xb] == 2) {
    param_1[0x55] = param_1[0x55] | 0x270;
    param_1[0x39] = 0;
    param_1[0x35] = 0x32;
    param_1[0x33] = 0x3c;
    param_1[0x37] = 0;
    param_1[0x38] = 0x19;
    param_1[0x34] = 100;
    param_1[0x30] = 0x4b;
    param_1[0x36] = 0x32;
    param_1[0x12] = 2;
    param_1[0x13] = 0;
    param_1[0x14] = 1;
    param_1[0x15] = 0;
    param_1[0x10] = 0;
    *(undefined4 *)(*param_1 + 0x198) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x19c) = 0;
    param_1[0x3b] = 0x3e99999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x42000000;
    param_1[0x3a] = 0x270;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 7;
    pcStack_c = "tf_weapon_axe";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe0ba9;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_ng";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe0bb4;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_sniperrifle";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe0bbf;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_24 = "tf_weapon_autorifle";
    GiveNamedItem__11CBasePlayerPc(param_1);
    ppcVar4 = &pcStack_c;
    pcStack_c = "tf_weapon_sniperrifle";
  }
  else if (param_1[0xb] == 3) {
    param_1[0x55] = param_1[0x55] | 0x2190;
    param_1[0x39] = 10;
    param_1[0x35] = 0;
    param_1[0x33] = 0x32;
    param_1[0x37] = 0;
    param_1[0x38] = 0x32;
    param_1[0x34] = 100;
    param_1[0x30] = 100;
    param_1[0x36] = 0x32;
    param_1[0x12] = 4;
    param_1[0x13] = 1;
    param_1[0x14] = 1;
    param_1[0x15] = 3;
    param_1[0x10] = 0;
    *(undefined4 *)(*param_1 + 0x198) = 0x3f4ccccd;
    *(undefined4 *)(*param_1 + 0x19c) = 0x42c80000;
    param_1[0x3b] = 0x3f4ccccd;
    param_1[0x3c] = 0x43480000;
    param_1[0x56] = 0x46000000;
    param_1[0x3a] = 0x2190;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 0x23;
    pcStack_c = "tf_weapon_axe";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe0cb9;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_shotgun";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe0cc4;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_supershotgun";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe0ccf;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_24 = "tf_weapon_rpg";
    GiveNamedItem__11CBasePlayerPc(param_1);
    param_1[0x33] = param_1[0x33] + -0x18;
    param_1[0x39] = param_1[0x39] + -4;
    ppcVar4 = &pcStack_c;
    pcStack_c = "tf_weapon_rpg";
  }
  else if (param_1[0xb] == 4) {
    param_1[0x55] = param_1[0x55] | 0x20890;
    param_1[0x39] = 0x14;
    param_1[0x35] = 0;
    param_1[0x33] = 0x1e;
    param_1[0x37] = 0;
    param_1[0x38] = 0x32;
    param_1[0x34] = 0x32;
    param_1[0x30] = 0x4b;
    param_1[0x36] = 0x32;
    param_1[0x12] = 4;
    param_1[0x13] = 4;
    param_1[0x14] = 1;
    param_1[0x15] = 4;
    param_1[0x10] = 0;
    param_1[0x31] = 1;
    param_1[0x32] = 1;
    *(undefined4 *)(*param_1 + 0x198) = 0x3f19999a;
    *(undefined4 *)(*param_1 + 0x19c) = 0x42480000;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42f00000;
    param_1[0x56] = 0x45000000;
    param_1[0x3a] = 0x20890;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 0x11;
    param_1[0x1fd] = 6;
    pcStack_c = "tf_weapon_axe";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe0df7;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_shotgun";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe0e02;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_gl";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe0e0d;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_24 = "tf_weapon_pl";
    GiveNamedItem__11CBasePlayerPc(param_1);
    param_1[0x33] = param_1[0x33] + -8;
    param_1[0x39] = param_1[0x39] + -6;
    ppcVar4 = &pcStack_c;
    pcStack_c = "tf_weapon_gl";
  }
  else if (param_1[0xb] == 5) {
    param_1[0x55] = param_1[0x55] | 0x586;
    param_1[0x39] = 0;
    param_1[0x35] = 0x32;
    param_1[0x33] = 0x32;
    param_1[0x37] = 0;
    param_1[0x38] = 0x19;
    param_1[0x34] = 0x96;
    param_1[0x30] = 0x4b;
    param_1[0x36] = 0x32;
    param_1[0x12] = 3;
    param_1[0x13] = 2;
    param_1[0x14] = 1;
    param_1[0x15] = 2;
    param_1[0x10] = 0;
    *(undefined4 *)(*param_1 + 0x198) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x19c) = 0x42480000;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42c80000;
    param_1[0x56] = 0x44800000;
    param_1[0x2f] = 0x32;
    param_1[0x2e] = 100;
    pcStack_c = (char *)0x6;
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe0f19;
    piVar3 = (int *)CreateTimer__11CBaseEntityi();
    *(float *)(*piVar3 + 0xe4) = *gpGlobals + 3.0;
    piVar3[3] = -0x10000;
    piVar3[4] = (int)Timer_Regeneration__11CBaseEntity;
    param_1[0x3a] = 0x586;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 0xb;
    pcStack_14 = "tf_weapon_medikit";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe0f5f;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_shotgun";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe0f6a;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_24 = "tf_weapon_supershotgun";
    GiveNamedItem__11CBasePlayerPc(param_1);
    pcStack_c = "tf_weapon_superng";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe0f83;
    GiveNamedItem__11CBasePlayerPc();
    param_1[0x33] = param_1[0x33] + -0x18;
    ppcVar4 = &pcStack_14;
    pcStack_14 = "tf_weapon_superng";
  }
  else if (param_1[0xb] == 6) {
    param_1[0x55] = param_1[0x55] | 0x8190;
    param_1[0x39] = 0;
    param_1[0x35] = 0;
    param_1[0x33] = 200;
    param_1[0x37] = 0x1e;
    param_1[0x38] = 0x19;
    param_1[0x34] = 200;
    param_1[0x30] = 200;
    param_1[0x36] = 0x32;
    param_1[0x12] = 4;
    param_1[0x13] = 1;
    param_1[0x14] = 1;
    param_1[0x15] = 4;
    param_1[0x10] = 0;
    *(undefined4 *)(*param_1 + 0x198) = 0x3f4ccccd;
    *(undefined4 *)(*param_1 + 0x19c) = 0x43160000;
    param_1[0x3b] = 0x3f4ccccd;
    param_1[0x3c] = 0x43960000;
    param_1[0x56] = 0x47000000;
    param_1[0x3a] = 0x8190;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 0x23;
    pcStack_c = "tf_weapon_axe";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe1079;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_shotgun";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe1084;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_supershotgun";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe108f;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_24 = "tf_weapon_ac";
    GiveNamedItem__11CBasePlayerPc(param_1);
    param_1[0x33] = param_1[0x33] + -0x18;
    ppcVar4 = &pcStack_c;
    pcStack_c = "tf_weapon_ac";
  }
  else if (param_1[0xb] == 7) {
    param_1[0x55] = param_1[0x55] | 0x5090;
    param_1[0x39] = 5;
    param_1[0x35] = 0;
    param_1[0x33] = 0x14;
    param_1[0x37] = 0x78;
    param_1[0x38] = 0x14;
    param_1[0x34] = 0x32;
    param_1[0x30] = 0x28;
    param_1[0x36] = 200;
    param_1[0x12] = 1;
    param_1[0x13] = 4;
    param_1[0x14] = 1;
    param_1[0x15] = 5;
    param_1[0x10] = 0;
    *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) | 0x10;
    *(undefined4 *)(*param_1 + 0x198) = 0x3f19999a;
    *(undefined4 *)(*param_1 + 0x19c) = 0x42480000;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x43160000;
    param_1[0x56] = 0x45800000;
    param_1[0x3a] = 0x5090;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 0x31;
    pcStack_c = "tf_weapon_axe";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe118d;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_shotgun";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe1198;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_ic";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe11a3;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_24 = "tf_weapon_flamethrower";
    GiveNamedItem__11CBasePlayerPc(param_1);
    param_1[0x33] = param_1[0x33] + -8;
    ppcVar4 = &pcStack_c;
    pcStack_c = "tf_weapon_flamethrower";
  }
  else if (param_1[0xb] == 0xb) {
    *(byte *)(param_1 + 0x55) = *(byte *)(param_1 + 0x55) | 0x10;
    param_1[0x39] = 0;
    param_1[0x35] = 0;
    param_1[0x33] = 0;
    param_1[0x37] = 0;
    param_1[0x38] = 0;
    param_1[0x34] = 0;
    param_1[0x30] = 0;
    param_1[0x36] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x10] = 0;
    *(undefined4 *)(*param_1 + 0x198) = 0;
    *(undefined4 *)(*param_1 + 0x19c) = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    param_1[0x56] = 0x41800000;
    param_1[0x3a] = 0x10;
    param_1[0x23] = 0;
    pcStack_c = "tf_weapon_axe";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe12a9;
    GiveNamedItem__11CBasePlayerPc();
    ppcVar4 = &pcStack_14;
    pcStack_14 = "tf_weapon_axe";
  }
  else if (param_1[0xb] == 8) {
    param_1[0x55] = param_1[0x55] | 0x40310;
    param_1[0x39] = 0;
    param_1[0x35] = 0x32;
    param_1[0x33] = 0x28;
    param_1[0x37] = 10;
    param_1[0x38] = 0xf;
    param_1[0x34] = 100;
    param_1[0x30] = 0x28;
    param_1[0x36] = 0x1e;
    param_1[0x12] = 2;
    param_1[0x13] = 2;
    param_1[0x14] = 1;
    param_1[0x15] = 7;
    param_1[0x10] = 0;
    *(undefined4 *)(*param_1 + 0x198) = 0x3f19999a;
    *(undefined4 *)(*param_1 + 0x19c) = 0x41c80000;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42c80000;
    param_1[0x56] = 0x48800000;
    param_1[0x3a] = (int)"ity";
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 7;
    pcStack_c = "tf_weapon_knife";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe1399;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_supershotgun";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe13a4;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_tranq";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe13af;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_24 = "tf_weapon_ng";
    GiveNamedItem__11CBasePlayerPc(param_1);
    param_1[0x33] = param_1[0x33] + -0x10;
    ppcVar4 = &pcStack_c;
    pcStack_c = "tf_weapon_tranq";
  }
  else {
    if (param_1[0xb] != 9) {
      if (param_1[0xb] == 0) {
        param_1[0x23] = 0;
        param_1[0x39] = 0;
        param_1[0x35] = 0;
        param_1[0x33] = 0;
        param_1[0x37] = 0;
        param_1[0x12] = 0;
        param_1[0x13] = 0;
        param_1[0x14] = 0;
        param_1[0x15] = 0;
        param_1[0xf] = 0;
        *(undefined4 *)(*param_1 + 0x198) = 0;
        *(undefined4 *)(*param_1 + 0x19c) = 0;
        param_1[0x56] = 0;
        param_1[0x55] = 0;
        *(undefined4 *)(*param_1 + 0x184) = 0x88;
        *(undefined4 *)(*param_1 + 0x1a0) = 3;
        *(undefined4 *)(*param_1 + 0x14c) = 0;
        *(undefined4 *)(*param_1 + 0xec) = 0;
        *(undefined4 *)(*param_1 + 0xe8) = 8;
        *(undefined4 *)(*param_1 + 0x94) = 0;
        *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 2;
        *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
      }
      goto LAB_000e15c3;
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
    param_1[0x12] = 2;
    param_1[0x13] = 2;
    param_1[0x14] = 1;
    param_1[0x15] = 8;
    param_1[0x10] = 0;
    *(undefined4 *)(*param_1 + 0x198) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x19c) = 0x41c80000;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x49000000;
    param_1[0x3a] = 0x80108;
    *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 3;
    pcStack_c = "tf_weapon_spanner";
    piStack_10 = param_1;
    pcStack_14 = (char *)0xe14a9;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_14 = "tf_weapon_railgun";
    piStack_18 = param_1;
    pcStack_1c = (char *)0xe14b4;
    GiveNamedItem__11CBasePlayerPc();
    pcStack_1c = "tf_weapon_supershotgun";
    piStack_20 = param_1;
    pcStack_24 = (char *)0xe14bf;
    GiveNamedItem__11CBasePlayerPc();
    param_1[0x33] = param_1[0x33] + -0x10;
    ppcVar4 = &pcStack_24;
    pcStack_24 = "tf_weapon_railgun";
  }
  *(int **)((int)ppcVar4 + -4) = param_1;
  *(undefined4 *)((int)ppcVar4 + -8) = 0xe14d1;
  SwitchWeapon__11CBasePlayerPCc();
LAB_000e15c3:
  fVar1 = *(float *)(*param_1 + 0x198);
  if ((byte)((0.8 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.8) << 0xe) >> 8)) - 1) < 0x40) {
    *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) | 0x80;
  }
  else {
    fVar1 = *(float *)(*param_1 + 0x198);
    if ((byte)((0.6 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.6) << 0xe) >> 8)) - 1) < 0x40) {
      *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) | 0x40;
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x198);
      if ((byte)((0.3 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.3) << 0xe) >> 8)) - 1) < 0x40) {
        *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) | 0x20;
      }
    }
  }
  return;
}


// TeamFortress_SetHealth__11CBasePlayer  @ 000e1650
void TeamFortress_SetHealth__11CBasePlayer(int *param_1)

{
  if (param_1[0xb] == 1) {
    *(undefined4 *)(*param_1 + 400) = 0x42960000;
    goto LAB_000e172e;
  }
  if (param_1[0xb] != 2) {
    if (param_1[0xb] == 3) {
LAB_000e1694:
      *(undefined4 *)(*param_1 + 400) = 0x42c80000;
      goto LAB_000e172e;
    }
    if ((param_1[0xb] != 4) && (param_1[0xb] != 5)) {
      if ((param_1[0xb] == 6) || (param_1[0xb] == 7)) goto LAB_000e1694;
      if (param_1[0xb] == 0xb) {
        *(undefined4 *)(*param_1 + 400) = 0x42480000;
        goto LAB_000e172e;
      }
      if (param_1[0xb] != 8) {
        if (param_1[0xb] == 9) {
          *(undefined4 *)(*param_1 + 400) = 0x42a00000;
        }
        else if (param_1[0xb] == 0) {
          *(undefined4 *)(*param_1 + 400) = 0x3f800000;
          *(undefined4 *)(*param_1 + 0x14c) = 0;
        }
        goto LAB_000e172e;
      }
    }
  }
  *(undefined4 *)(*param_1 + 400) = 0x42b40000;
LAB_000e172e:
  *(undefined4 *)(*param_1 + 0x140) = *(undefined4 *)(*param_1 + 400);
  return;
}


// TeamFortress_SetSkin__11CBasePlayer  @ 000e19d0
void TeamFortress_SetSkin__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = (*DAT_00175668)(*(undefined4 *)(*param_1 + 0x1e8));
  param_1[99] = (int)(*gpGlobals + 10.0);
  iVar3 = param_1[0xb];
  if ((iVar3 == 8) && (param_1[0x76] != 0)) {
    iVar3 = param_1[0x76];
  }
  local_20 = param_1[0x48];
  if ((param_1[0xb] == 8) && (param_1[0x75] != 0)) {
    local_20 = param_1[0x75];
  }
  if (*(int *)(sClassModelFiles + iVar3 * 4) == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/player/scout/scout.mdl");
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  }
  else {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/player/scout/scout.mdl");
    uVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8),uVar1,"model",
                            *(undefined4 *)(sClassModels + iVar3 * 4));
    (*DAT_00175674)(uVar2);
  }
  if (param_1[0x48] != 0) {
    iVar3 = *(int *)(teamcolors + local_20 * 4);
    uVar2 = UTIL_VarArgs__FPce(&DAT_0013a778,iVar3);
    uVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8),uVar1,"topcolor",uVar2);
    (*DAT_00175674)(uVar2);
    uVar2 = UTIL_VarArgs__FPce(&DAT_0013a778,iVar3 + -10);
    uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8),uVar1,"bottomcolor",uVar2);
    (*DAT_00175674)(uVar1);
  }
  iVar3 = *param_1;
  if ((*(byte *)(iVar3 + 0x185) & 0x40) == 0) {
    uStack_1c = 0x41800000;
    uStack_18 = 0x41800000;
    uStack_14 = 0x42100000;
    puVar5 = &uStack_1c;
    uStack_10 = 0xc1800000;
    uStack_c = 0xc1800000;
    uStack_8 = 0xc2100000;
    puVar4 = &uStack_10;
    iVar3 = *param_1;
  }
  else {
    uStack_10 = 0x41800000;
    uStack_c = 0x41800000;
    uStack_8 = 0x41900000;
    puVar5 = &uStack_10;
    uStack_1c = 0xc1800000;
    uStack_18 = 0xc1800000;
    uStack_14 = 0xc1900000;
    puVar4 = &uStack_1c;
  }
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar3,puVar4,puVar5);
  g_ulModelIndexPlayer = *(undefined4 *)(*param_1 + 0x94);
  return;
}


// TeamFortress_SetSpeed__11CBasePlayer  @ 000e1740
void TeamFortress_SetSpeed__11CBasePlayer(int *param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  if (((*(byte *)((int)param_1 + 0x8a) & 1) != 0) || (param_1[0xb] == 0)) {
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar3 + 0x24) = DAT_00175484;
    *(undefined4 *)(iVar3 + 0x28) = DAT_00175488;
    iVar3 = 0x3f800000;
    goto LAB_000e19aa;
  }
  if (param_1[0xb] == 1) {
    param_1[0x3d] = 0x43e10000;
    param_1[0x3e] = 0x43e10000;
  }
  else {
    if (param_1[0xb] == 2) goto LAB_000e184c;
    if (param_1[0xb] == 3) {
LAB_000e181c:
      param_1[0x3d] = 0x43700000;
      param_1[0x3e] = 0x43700000;
    }
    else if (param_1[0xb] == 4) {
      param_1[0x3d] = 0x438c0000;
      param_1[0x3e] = 0x438c0000;
    }
    else if (param_1[0xb] == 5) {
      param_1[0x3d] = 0x43a00000;
      param_1[0x3e] = 0x43a00000;
    }
    else if (param_1[0xb] == 6) {
      param_1[0x3d] = 0x43660000;
      param_1[0x3e] = 0x43660000;
    }
    else {
      if (param_1[0xb] != 7) {
        if (param_1[0xb] == 0xb) goto LAB_000e181c;
        if ((param_1[0xb] != 8) && (param_1[0xb] != 9)) goto LAB_000e1860;
      }
LAB_000e184c:
      param_1[0x3d] = 0x43960000;
      param_1[0x3e] = 0x43960000;
    }
  }
LAB_000e1860:
  piVar2 = (int *)0x0;
  while (piVar2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar2,"item_tfgoal"),
        piVar2 != (int *)0x0) {
    if ((*(int *)(*piVar2 + 0x178) == *(int *)(*param_1 + 0x1e8)) &&
       ((*(byte *)(piVar2 + 0x88) & 2) != 0)) {
      param_1[0x3d] = (int)((float)param_1[0x3d] * 0.5);
      param_1[0x3e] = (int)((float)param_1[0x3e] * 0.5);
    }
  }
  if ((short)param_1[0x22] < 0) {
    param_1[0x3d] = (int)((float)param_1[0x3d] * 0.5);
    param_1[0x3e] = (int)((float)param_1[0x3e] * 0.5);
  }
  fVar1 = (float)param_1[0x68];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((byte)(6.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 6.0) << 0xe) >> 8)) == 1) {
      param_1[0x68] = 0x40c00000;
    }
    param_1[0x3d] = (int)(((10.0 - (float)param_1[0x68]) / 10.0) * (float)param_1[0x3d]);
    param_1[0x3e] = (int)(((10.0 - (float)param_1[0x68]) * (float)param_1[0x3e]) / 10.0);
  }
  if ((*(byte *)((int)param_1 + 0x89) & 8) != 0) {
    fVar1 = (float)param_1[0x3d];
    if ((byte)(80.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 80.0) << 0xe) >> 8)) == 1) {
      param_1[0x3d] = 0x42a00000;
    }
    fVar1 = (float)param_1[0x3e];
    if ((byte)(80.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 80.0) << 0xe) >> 8)) == 1) {
      param_1[0x3e] = 0x42a00000;
    }
  }
  iVar3 = param_1[0x3d];
LAB_000e19aa:
  (*DAT_00175658)(*(undefined4 *)(*param_1 + 0x1e8),iVar3);
  return;
}


// TeamFortress_SetupRespawn__11CBasePlayeri  @ 000e28a0
void TeamFortress_SetupRespawn__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float local_14;
  
  if ((float)param_1[0x4c] <= *gpGlobals) {
    local_14 = (float)tfc_respawndelay._12_4_;
    fVar1 = *gpGlobals;
    if ((byte)(cb_prematch_time < fVar1 |
               (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) == 1) {
      if (param_2 != 0) {
        if (0 < param_1[0x49]) {
          param_1[0x49] = param_1[0x49] + -1;
        }
        local_14 = (float)param_1[0x19b] - *gpGlobals;
      }
      if (0 < param_1[0x49]) {
        param_1[0x49] = param_1[0x49] + -1;
      }
      if (param_1[0x49] != -1) {
        if (param_1[0x49] == 0) {
          ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Game_nolives",0,0,0,0);
          param_1[0xb] = 0;
          *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) & 0xf7;
          *(undefined4 *)(*param_1 + 0xe8) = 8;
          *(undefined4 *)(*param_1 + 0xec) = 0;
          *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
          iVar2 = *param_1;
          *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
          *(undefined4 *)(iVar2 + 0x24) = DAT_00175484;
          *(undefined4 *)(iVar2 + 0x28) = DAT_00175488;
          iVar2 = *param_1;
          *(undefined4 *)(iVar2 + 0x5c) = g_vecZero;
          *(undefined4 *)(iVar2 + 0x60) = DAT_00175484;
          *(undefined4 *)(iVar2 + 100) = DAT_00175488;
          (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/player/scout/scout.mdl");
          return;
        }
        if (param_1[0x49] == 1) {
          uVar8 = 0;
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = 0;
          pcVar4 = "#Game_lastlife";
          uVar3 = 4;
        }
        else {
          uVar8 = 0;
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = UTIL_dtos1__Fi(param_1[0x49],0,0,0);
          pcVar4 = "#Game_Xlives";
          uVar3 = 1;
        }
        ClientPrint__FP9entvars_tiPCcN42(*param_1,uVar3,pcVar4,uVar5,uVar6,uVar7,uVar8);
      }
    }
    param_1[0x4c] = (int)(local_14 + *gpGlobals);
    if ((byte)(3.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 3.0) << 0xe) >> 8)) == 1) {
      uVar5 = UTIL_dtos1__Fi((int)ROUND(local_14),0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_tillrespawn",uVar5);
    }
  }
  return;
}


// TeamFortress_SortTeams__Fv  @ 0010f160
int TeamFortress_SortTeams__Fv(void)

{
  float fVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_28;
  int iStack_20;
  int local_1c;
  int aiStack_18 [5];
  
  local_1c = 0;
  iStack_20 = 0;
  iStack_28 = 1;
  iVar4 = 0;
  do {
    aiStack_18[iVar4] = 0;
    (&g_iOrderedTeams)[iVar4] = 0;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  iVar4 = 1;
  bVar3 = 1.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
          (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8);
  iVar2 = local_1c;
  while ((byte)(bVar3 - 1) < 0x40) {
    iVar6 = 0;
    iVar5 = 1;
    bVar3 = 1.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
            (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8);
    local_1c = iVar2;
    while ((byte)(bVar3 - 1) < 0x40) {
      if ((iVar6 <= *(int *)(teamscores + iVar5 * 4)) && (aiStack_18[iVar5] == 0)) {
        iVar6 = *(int *)(teamscores + iVar5 * 4);
        local_1c = iVar5;
      }
      iVar5 = iVar5 + 1;
      fVar1 = (float)iVar5;
      bVar3 = fVar1 < number_of_teams |
              (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8);
    }
    if ((((1 < iVar4) && (iStack_28 == 1)) &&
        ((((byte)((int)(&teamallies)[iVar4] >> ((char)iVar2 - 1U & 0x1f)) ^ 1) & 1) != 0)) &&
       (iVar6 != iStack_20)) {
      iStack_28 = 0;
    }
    aiStack_18[local_1c] = 1;
    (&g_iOrderedTeams)[iVar4] = local_1c;
    iVar4 = iVar4 + 1;
    fVar1 = (float)iVar4;
    iVar2 = local_1c;
    iStack_20 = iVar6;
    bVar3 = fVar1 < number_of_teams |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8);
  }
  return iStack_28;
}


// TeamFortress_SpyCalcName__11CBasePlayer  @ 000ef010
void TeamFortress_SpyCalcName__11CBasePlayer(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1dc);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x1dc,0);
  if (*(int *)(param_1 + 0x1d4) != 0) {
    for (iVar3 = 1; iVar3 <= *(int *)(gpGlobals + 0x90); iVar3 = iVar3 + 1) {
      iVar2 = UTIL_PlayerByIndex__Fi(iVar3);
      if ((((iVar2 != 0) && (iVar2 != iVar1)) &&
          (*(int *)(iVar2 + 0x120) == *(int *)(param_1 + 0x1d4))) &&
         (*(int *)(iVar2 + 0x2c) == *(int *)(param_1 + 0x1d8))) goto LAB_000ef0bd;
    }
    for (iVar1 = 1; iVar1 <= *(int *)(gpGlobals + 0x90); iVar1 = iVar1 + 1) {
      iVar2 = UTIL_PlayerByIndex__Fi(iVar1);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x120) == *(int *)(param_1 + 0x1d4))) {
LAB_000ef0bd:
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x1dc,iVar2);
        return;
      }
    }
  }
  return;
}


// TeamFortress_SpyChangeColor__11CBasePlayeri  @ 000ef1b0
void TeamFortress_SpyChangeColor__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 == param_1[0x48]) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Disguise_resetteam",0,0,0,0);
    param_1[0x75] = 0;
    if (param_1[0x76] == 0) {
      param_1[0x1a] = 0;
    }
    TeamFortress_SetSkin__11CBasePlayer(param_1);
  }
  else {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Disguise_start",0,0,0,0);
    param_1[0x1a] = 2;
    piVar1 = (int *)CreateTimer__11CBaseEntityi(param_1,0xd);
    piVar1[3] = -0x10000;
    piVar1[4] = (int)Timer_SpyUndercoverThink__11CBaseEntity;
    *(float *)(*piVar1 + 0xe4) = *gpGlobals + 4.0;
    piVar1[0x48] = param_2;
  }
  return;
}


// TeamFortress_SpyChangeSkin__11CBasePlayeri  @ 000ef0f0
void TeamFortress_SpyChangeSkin__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 == 8) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Disguise_resetclass",0,0,0,0);
    param_1[0x76] = 0;
    if (param_1[0x75] == 0) {
      param_1[0x1a] = 0;
    }
  }
  else {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Disguise_start",0,0,0,0);
    param_1[0x1a] = 2;
    piVar1 = (int *)CreateTimer__11CBaseEntityi(param_1,0xd);
    piVar1[3] = -0x10000;
    piVar1[4] = (int)Timer_SpyUndercoverThink__11CBaseEntity;
    *(float *)(*piVar1 + 0xe4) = *gpGlobals + 4.0;
    *(int *)(*piVar1 + 0xf0) = param_2;
  }
  TeamFortress_SetSkin__11CBasePlayer(param_1);
  return;
}


// TeamFortress_SpyFeignDeath__11CBasePlayeri  @ 000ee840
void TeamFortress_SpyFeignDeath__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  char *pcVar6;
  float *pfVar7;
  int *piVar8;
  float *pfVar9;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  int local_54;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x173];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
    return;
  }
  local_8 = *gpGlobals + 0.5;
  param_1[0x173] = (int)local_8;
  if (param_1[0x1d] == 0) {
    if (param_1[0x1e] == 1) {
      pcVar6 = "#Feign_unable";
    }
    else {
      iVar3 = *param_1;
      if (((*(byte *)(iVar3 + 0x185) & 2) == 0) && (*(int *)(iVar3 + 0x1a0) == 0)) {
        ClientPrint__FP9entvars_tiPCcN42(iVar3,4,"#Feign_air",0,0,0,0);
        return;
      }
      iVar3 = CanFeign__11CBasePlayer(param_1);
      if (iVar3 != 0) {
        iVar3 = *param_1;
        if ((*(byte *)(iVar3 + 0x185) & 0x40) != 0) {
          local_20 = *(float *)(iVar3 + 8);
          local_1c = *(float *)(iVar3 + 0xc);
          local_18 = *(float *)(iVar3 + 0x10);
          if ((*(byte *)(iVar3 + 0x185) & 2) != 0) {
            local_70 = 0xc1800000;
            local_6c = 0xc1800000;
            local_68 = 0xc1900000;
            local_7c = 0xc1800000;
            local_78 = 0xc1800000;
            local_74 = 0xc2100000;
            local_64 = 0;
            local_60 = 0;
            local_5c = 0x41900000;
            local_20 = local_20 + 0.0;
            local_1c = local_1c + 0.0;
            local_18 = local_18 + 18.0;
            local_14 = local_20;
            local_10 = local_1c;
            local_c = local_18;
          }
          UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                    (&local_20,&local_20,0,1,*(undefined4 *)(*param_1 + 0x1e8),local_58);
          if (local_54 != 0) {
            pcVar6 = "#Feign_noroom";
            goto LAB_000eeb4e;
          }
          iVar3 = *param_1;
          if ((*(byte *)(iVar3 + 0x185) & 2) != 0) {
            local_70 = 0xc1800000;
            local_6c = 0xc1800000;
            local_68 = 0xc1900000;
            local_64 = 0xc1800000;
            local_60 = 0xc1800000;
            local_5c = 0xc2100000;
            local_7c = 0;
            local_78 = 0;
            local_74 = 0x41900000;
            local_14 = *(float *)(iVar3 + 8) + 0.0;
            local_10 = *(float *)(iVar3 + 0xc) + 0.0;
            local_c = *(float *)(iVar3 + 0x10) + 18.0;
            *(float *)(iVar3 + 8) = local_14;
            *(float *)(iVar3 + 0xc) = local_10;
            *(float *)(iVar3 + 0x10) = local_c;
          }
        }
        param_1[599] = 0;
        SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
        param_1[99] = (int)(*gpGlobals + 5.0);
        *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) | 1;
        TeamFortress_SetSpeed__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x150) = 99;
        param_1[0x1d] = 1;
        param_1[0xe9] = 0;
        TeamFortress_SetSkin__11CBasePlayer(param_1);
        if (param_1[0x20c] != 0) {
          (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x120))(param_1[0x20c]);
        }
        local_7c = 0x41800000;
        local_78 = 0x41800000;
        local_74 = 0xc2000000;
        local_70 = 0xc1800000;
        local_6c = 0xc1800000;
        local_68 = 0xc2100000;
        UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_70,&local_7c);
        iVar3 = *param_1;
        local_7c = 0;
        local_78 = 0;
        local_74 = 0x40800000;
        *(undefined4 *)(iVar3 + 0x154) = 0;
        *(undefined4 *)(iVar3 + 0x158) = 0;
        *(undefined4 *)(iVar3 + 0x15c) = 0x40800000;
        *(undefined4 *)(*param_1 + 0xe8) = 6;
        *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
        if (*(float *)(*param_1 + 0x28) < 10.0) {
          lVar5 = (longdouble)(*DAT_0017562c)(0,0x43960000);
          *(float *)(*param_1 + 0x28) = (float)(lVar5 + (longdouble)*(float *)(*param_1 + 0x28));
        }
        if (param_2 == 0) {
          (**(code **)(param_1[0xf2] + 0x200))(param_1);
        }
        *(undefined4 *)(*param_1 + 0x50) = 0;
        *(undefined4 *)(*param_1 + 0x58) = 0;
        piVar8 = (int *)0x0;
LAB_000eee0d:
        do {
          do {
            piVar8 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar8,"item_tfgoal");
            if (piVar8 == (int *)0x0) {
              return;
            }
          } while (*(int *)(*piVar8 + 0x178) != *(int *)(*param_1 + 0x1e8));
          if (((*(byte *)((int)piVar8 + 0x221) & 1) == 0) || (param_1[0x1f] == 1)) {
            tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar8,param_1,0);
          }
        } while (CTF_Map != 1);
        if (piVar8[0x84] != 1) goto code_r0x000eedc9;
        iVar3 = *(int *)(*param_1 + 0x1b0) + (int)gpGlobals[0x26];
        pcVar6 = "%s LOST the BLUE flag!\n";
        goto LAB_000eedf4;
      }
      pcVar6 = "#Feign_onspy";
    }
  }
  else {
    iVar3 = CanFeign__11CBasePlayer(param_1);
    if (iVar3 != 0) {
      param_1[0x1d] = 0;
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar3 + 0x24) = DAT_00175484;
      *(undefined4 *)(iVar3 + 0x28) = DAT_00175488;
      iVar3 = *param_1;
      if ((*(byte *)(iVar3 + 0x185) & 0x40) == 0) {
        local_20 = 16.0;
        local_1c = 16.0;
        local_18 = 36.0;
        pfVar9 = &local_20;
        local_14 = -16.0;
        local_10 = -16.0;
        local_c = -36.0;
        pfVar7 = &local_14;
        iVar3 = *param_1;
      }
      else {
        local_14 = 16.0;
        local_10 = 16.0;
        local_c = 18.0;
        pfVar9 = &local_14;
        local_20 = -16.0;
        local_1c = -16.0;
        local_18 = -18.0;
        pfVar7 = &local_20;
      }
      UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar3,pfVar7,pfVar9);
      iVar3 = *param_1;
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 28.0;
      *(undefined4 *)(iVar3 + 0x154) = 0;
      *(undefined4 *)(iVar3 + 0x158) = 0;
      *(undefined4 *)(iVar3 + 0x15c) = 0x41e00000;
      *(undefined4 *)(*param_1 + 0xe8) = 3;
      *(undefined4 *)(*param_1 + 0x150) = 0;
      *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      if (param_1[0x20c] != 0) {
        (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x118))(param_1[0x20c]);
      }
      *(undefined4 *)(*param_1 + 0x118) = 0xbf800000;
      param_1[599] = 0;
      SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
      return;
    }
    pcVar6 = "#Feign_unabletogetup";
  }
LAB_000eeb4e:
  ClientPrint__FP9entvars_tiPCcN42(*param_1,4,pcVar6,0,0,0,0);
  return;
code_r0x000eedc9:
  if (piVar8[0x84] == 2) {
    iVar3 = *(int *)(*param_1 + 0x1b0) + (int)gpGlobals[0x26];
    pcVar6 = "%s LOST the RED flag!\n";
LAB_000eedf4:
    uVar4 = UTIL_VarArgs__FPce(pcVar6,iVar3,0,0,0,0);
    UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
  }
  goto LAB_000eee0d;
}


// TeamFortress_SpyGoUndercover__11CBasePlayer  @ 000eef70
void TeamFortress_SpyGoUndercover__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  if (((*(byte *)(*param_1 + 0xf8) & 9) == 0) && (param_1[0x1e] != 1)) {
    if (param_1[0x1a] == 2) {
      ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Disguise_stop",0,0,0,0);
      iVar1 = FindTimer__11CBaseEntityi(param_1,0xd);
      if (iVar1 != 0) {
        UTIL_Remove__FP11CBaseEntity(iVar1);
      }
      param_1[0x1a] = 0;
    }
    else {
      param_1[0x45] = 0x41400000;
    }
  }
  else {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Spy_unable",0,0,0,0);
  }
  return;
}


// TeamFortress_StatusQuery__Fv  @ 0010f0c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_StatusQuery__Fv(void)

{
  undefined4 uVar1;
  
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi();
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(3,uVar1);
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(2,uVar1);
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(1,uVar1);
  (*DAT_001755b4)(1,"players per team: %d %d %d %d\n",uVar1);
  (*DAT_001755b4)(1,"    equalisation: %0.1f %0.1f %0.1f %0.1f\n",(double)DAT_00182094,
                  (double)_DAT_00182098,(double)_DAT_0018209c,(double)_DAT_001820a0);
  (*DAT_001755b4)(1,"Teamplay is %d\n",(double)*(float *)(gpGlobals + 0x1c));
  return;
}


// TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_tf  @ 000a1d40
void TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_tf(void)

{
  return;
}


// TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_tf  @ 000e37f0
void TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_tf
               (int *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  
  iVar5 = (**(code **)(param_1[0xf2] + 0x88))(param_1);
  if ((iVar5 != 0) && (param_1[0xb] != 0)) {
    iVar5 = *param_1;
    fVar1 = *(float *)(iVar5 + 8) - *(float *)(param_2 + 8);
    fVar2 = *(float *)(iVar5 + 0xc) - *(float *)(param_2 + 0xc);
    fVar3 = *(float *)(iVar5 + 0x10) - *(float *)(param_2 + 0x10);
    iVar5 = *(int *)(param_2 + 0x1e8);
    if ((iVar5 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(undefined4 *)(iVar5 + 0xd8);
    }
    fVar4 = (param_3 - SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) * 0.5) / 20.0;
    iVar5 = *param_1;
    *(float *)(iVar5 + 0x20) = *(float *)(iVar5 + 0x20) + fVar1;
    *(float *)(iVar5 + 0x24) = *(float *)(iVar5 + 0x24) + fVar2;
    *(float *)(iVar5 + 0x28) = *(float *)(iVar5 + 0x28) + fVar3;
    bVar7 = false;
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x20)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x20) == 0.0) << 0xe) >> 8)) == 0x40)
       && (fVar1 = *(float *)(*param_1 + 0x24),
          (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
      fVar1 = *(float *)(*param_1 + 0x28);
      bVar7 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
    }
    if (bVar7) {
      iVar5 = *param_1;
      lVar8 = (longdouble)(*DAT_0017562c)(0xc2700000,0x42700000);
      lVar9 = (longdouble)(*DAT_0017562c)(0xc2700000,0x42700000);
      lVar10 = (longdouble)(*DAT_0017562c)(0x40a00000,0x42700000);
      *(float *)(iVar5 + 0x20) = (float)lVar8;
      *(float *)(iVar5 + 0x24) = (float)lVar9;
      *(float *)(iVar5 + 0x28) = (float)lVar10;
    }
    iVar5 = *param_1;
    *(float *)(iVar5 + 0x20) = fVar4 * *(float *)(iVar5 + 0x20);
    *(float *)(iVar5 + 0x24) = fVar4 * *(float *)(iVar5 + 0x24);
    *(float *)(iVar5 + 0x28) = fVar4 * *(float *)(iVar5 + 0x28);
    if ((((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) == 0) || (param_1[0x48] < 1)) ||
        (iVar5 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,uVar6), iVar5 == 0)) ||
       (*(int *)(param_2 + 0x178) == *(int *)(*param_1 + 0x1e8))) {
      (*DAT_00175578)(1,gmsgDamage,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(0);
      (*DAT_00175580)(0);
      (*DAT_0017558c)(0x200);
      (*DAT_00175594)(*(undefined4 *)(param_2 + 8));
      (*DAT_00175594)(*(undefined4 *)(param_2 + 0xc));
      (*DAT_00175594)(*(undefined4 *)(param_2 + 0x10));
      (*DAT_0017557c)();
      (**(code **)(param_1[0xf2] + 0xfc))(param_1,param_2);
    }
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_t  @ 000fb580
void TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_t(int *param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"tf_gl_pipebomb");
  if (iVar1 == 0) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_t  @ 0011c9b0
void TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_t(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_c;
  undefined4 local_8;
  
  if (*(int *)(param_2 + 0x178) == 0) {
    (*DAT_001755d4)(0);
  }
  if (*(int *)(param_2 + 0x1e8) == 0) {
    (*DAT_001755d4)(0);
  }
  (**(code **)(param_1[0xf2] + 0xec))(param_1,&local_c,&local_8);
  if (0.0 < local_c) {
    (**(code **)(param_1[0xf2] + 0xe8))(param_1,param_2,local_c,local_8);
    fVar1 = (float)param_1[0xfa];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      iVar2 = *(int *)(*param_1 + 0x170);
      if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0xd8);
      }
      if ((iVar2 != 0) && (iVar3 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x28))(iVar2), iVar3 == 2)
         ) {
        *(int *)(iVar2 + 0xce8) = *(int *)(iVar2 + 0xce8) + -1;
      }
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_t  @ 000a1d30
void TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_t(void)

{
  return;
}


// TeamFortress_TakeEMPBlast__11CBasePlayerP9entvars_t  @ 000e3630
void TeamFortress_TakeEMPBlast__11CBasePlayerP9entvars_t(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ushort in_FPUControlWord;
  float local_1c;
  undefined4 local_18;
  ushort local_14;
  undefined4 local_10;
  ushort local_8;
  undefined2 uStack_6;
  
  iVar1 = *(int *)(param_2 + 0x178);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xd8);
  }
  if (*(int *)(param_2 + 0x1e8) == 0) {
    (*DAT_001755d4)(0);
  }
  if ((*(int *)(param_1 + 0x2c) != 0) &&
     (((local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord)),
       ((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) == 0 ||
       (iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,iVar1), iVar2 == 0)) ||
      (iVar1 == param_1)))) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0xec))(param_1,&local_1c,&local_18);
    *(int *)(param_1 + 0xcc) =
         (int)ROUND((double)*(int *)(param_1 + 0xcc) -
                    ROUND((double)*(int *)(param_1 + 0xcc) * 0.25));
    *(int *)(param_1 + 0xe4) =
         (int)ROUND((double)*(int *)(param_1 + 0xe4) -
                    ROUND((double)*(int *)(param_1 + 0xe4) * 0.25));
    if (*(int *)(param_1 + 0x2c) != 9) {
      *(int *)(param_1 + 0xdc) =
           (int)ROUND((double)*(int *)(param_1 + 0xdc) -
                      ROUND((double)*(int *)(param_1 + 0xdc) * 0.25));
    }
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_14 = in_FPUControlWord & 0xf3ff | 0x800;
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    if ((byte)(0.0 < local_1c | (byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 1) {
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0xe8))(param_1,param_2,local_1c,local_18);
    }
  }
  return;
}


// TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_t  @ 000a8df0
void TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_t(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x178);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 0xd8);
  }
  if (*(int *)(param_2 + 0x1e8) == 0) {
    (*DAT_001755d4)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar2), iVar1 != 0)) &&
     (puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar2 != puVar3)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x34))(param_1,param_2,*puVar2,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_t  @ 000ea3f0
void TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_t(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x178);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 0xd8);
  }
  if (*(int *)(param_2 + 0x1e8) == 0) {
    (*DAT_001755d4)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar2), iVar1 != 0)) &&
     (puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar2 != puVar3)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x34))(param_1,param_2,*puVar2,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__8CDetpackP9entvars_t  @ 000a7750
void TeamFortress_TakeEMPBlast__8CDetpackP9entvars_t(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_0017562c)(0,0x40000000);
  *(float *)(*param_1 + 0x140) = (float)((longdouble)1 + (longdouble)*gpGlobals + lVar1);
  return;
}


// TeamFortress_TeamGetNoPlayers__Fi  @ 0010e8a0
int TeamFortress_TeamGetNoPlayers__Fi(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar2 = 1; iVar2 <= *(int *)(gpGlobals + 0x90); iVar2 = iVar2 + 1) {
    iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x120) == param_1)) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}


// TeamFortress_TeamGetScoreFrags__Fi  @ 0010e880
undefined4 TeamFortress_TeamGetScoreFrags__Fi(int param_1)

{
  return *(undefined4 *)(teamscores + param_1 * 4);
}


// TeamFortress_TeamIncreaseScore__Fii  @ 0010e810
void TeamFortress_TeamIncreaseScore__Fii(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    *(int *)(teamscores + param_1 * 4) = *(int *)(teamscores + param_1 * 4) + param_2;
    (*DAT_00175578)(2,gmsgTeamScore,0,0);
    uVar1 = GetTeamName__Fi(param_1);
    (*DAT_00175598)(uVar1);
    (*DAT_00175588)(*(undefined4 *)(teamscores + param_1 * 4));
    (*DAT_00175588)(0);
    (*DAT_0017557c)();
  }
  return;
}


// TeamFortress_TeamIsCivilian__Ff  @ 0010eab0
undefined4 TeamFortress_TeamIsCivilian__Ff(float param_1)

{
  if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == 1.0) << 0xe) >> 8)) == 0x40) {
    if (((byte)civilianteams & 1) != 0) {
      return 1;
    }
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_1 == 2.0) << 0xe) >> 8)) == 0x40) {
    if (((byte)civilianteams & 2) != 0) {
      return 1;
    }
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_1 == 3.0) << 0xe) >> 8)) == 0x40) {
    if (((byte)civilianteams & 4) != 0) {
      return 1;
    }
  }
  else if (((byte)civilianteams & 8) != 0) {
    return 1;
  }
  return 0;
}


// TeamFortress_TeamPutPlayerInTeam__11CBasePlayer  @ 000e1f70
void TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fStack_1c;
  
  iVar2 = 1;
  lVar4 = (longdouble)(*DAT_0017562c)(0,number_of_teams);
  fStack_1c = (float)ROUND(lVar4);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_1c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_1c == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_1c = number_of_teams;
  }
  iVar3 = 0x21;
  while( true ) {
    if (number_of_teams + 1.0 <= (float)iVar2) break;
    iVar1 = TeamFortress_TeamGetNoPlayers__Fi(iVar2);
    if ((iVar1 < iVar3) && (iVar1 < *(int *)(teammaxplayers + iVar2 * 4))) {
      fStack_1c = (float)iVar2;
      iVar3 = iVar1;
    }
    iVar2 = iVar2 + 1;
  }
  TeamFortress_TeamSet__11CBasePlayeri(param_1,(int)ROUND(fStack_1c));
  return;
}


// TeamFortress_TeamSetColor__Fi  @ 0010e6c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_TeamSetColor__Fi(void)

{
  teamcolors._4_4_ = 0x96;
  teamcolors._8_4_ = 0xfa;
  teamcolors._12_4_ = 0x2d;
  teamcolors._16_4_ = 100;
  rgbcolors = 0x437f0000;
  DAT_00181fc4 = 0x437f0000;
  DAT_00181fc8 = 0x437f0000;
  _DAT_00181fcc = 0;
  DAT_00181fd0 = 0;
  DAT_00181fd4 = 0x437f0000;
  _DAT_00181fd8 = 0x437f0000;
  DAT_00181fdc = 0;
  DAT_00181fe0 = 0;
  _DAT_00181fe4 = 0x437f0000;
  DAT_00181fe8 = 0x437f0000;
  uRam00181fec = 0x41f00000;
  _DAT_00181ff0 = 0;
  DAT_00181ff4 = 0x437f0000;
  DAT_00181ff8 = 0;
  return;
}


// TeamFortress_TeamSet__11CBasePlayeri  @ 000e2050
undefined4 TeamFortress_TeamSet__11CBasePlayeri(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if ((0 < param_1[0x48]) && (param_1[0x48] == param_2)) {
    return 0;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x1c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x1c) == 0.0) << 0xe) >> 8)) == 0x40) {
    pcVar3 = "#Game_noteams";
  }
  else {
    if ((number_of_teams < (float)param_2) &&
       ((byte)(0.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
              (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) != 0x40)) {
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = 0;
      uVar1 = UTIL_dtos1__Fi((int)ROUND(number_of_teams),0,0,0);
      pcVar3 = "Game_onlyteams";
      iVar2 = *param_1;
      goto LAB_000e215c;
    }
    iVar2 = TeamFortress_TeamGetNoPlayers__Fi(param_2);
    if (iVar2 < *(int *)(teammaxplayers + param_2 * 4)) {
      if (*(int *)(teamcolors + param_2 * 4) != 0) {
        if (param_1[0x48] < 1) {
          uVar1 = UTIL_dtos1__Fi(param_2,0,0);
          UTIL_ClientPrintAll__FiPCcN41
                    (1,"#Game_joinedteam",*(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),
                     uVar1);
          uVar1 = (*DAT_00175684)(*(undefined4 *)(*param_1 + 0x1e8),param_2);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i>\" joined team \"%d\".\n",
                     *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),uVar1);
        }
        else {
          uVar1 = UTIL_dtos1__Fi(param_2,0,0);
          UTIL_ClientPrintAll__FiPCcN41
                    (1,"#Game_changedteam",*(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),
                     uVar1);
          uVar1 = (*DAT_00175684)(*(undefined4 *)(*param_1 + 0x1e8),param_2);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i>\" changed to team \"%d\".\n",
                     *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),uVar1);
          Engineer_RemoveBuildings__11CBasePlayer(param_1);
          TeamFortress_RemoveDetpacks__11CBasePlayer(param_1);
          param_1[0xb] = 0;
          param_1[0xc] = 0;
          param_1[0x22] = 0;
          *(undefined4 *)(*param_1 + 0x140) = 0;
          (**(code **)(param_1[0xf2] + 0x3c))(param_1,*param_1,1);
        }
        param_1[0x48] = param_2;
        param_1[0x49] = *(int *)(teamlives + param_2 * 4);
        TeamFortress_TeamShowMemberClasses__11CBasePlayer(param_1);
        (*DAT_00175578)(2,gmsgTeamInfo,0,0);
        uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_00175580)(uVar1);
        uVar1 = (**(code **)(*g_pGameRules + 0xcc))(g_pGameRules,param_1);
        (*DAT_00175598)(uVar1);
        (*DAT_0017557c)();
        (*DAT_00175578)(1,gmsgSayText,0,*(undefined4 *)(*param_1 + 0x1e8));
        uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_00175580)(uVar1);
        uVar1 = (**(code **)(*g_pGameRules + 0xcc))(g_pGameRules,param_1);
        uVar1 = UTIL_VarArgs__FPce("* You have joined team %s\n",uVar1);
        (*DAT_00175598)(uVar1);
        (*DAT_0017557c)();
        TeamFortress_TeamIncreaseScore__Fii(param_1[0x48],0);
        TeamFortress_SetSkin__11CBasePlayer(param_1);
        return 1;
      }
      pcVar3 = "#Game_noteamstart";
    }
    else {
      pcVar3 = "#Game_teamfull";
    }
  }
  uVar6 = 0;
  uVar5 = 0;
  uVar4 = 0;
  uVar1 = 0;
  iVar2 = *param_1;
LAB_000e215c:
  ClientPrint__FP9entvars_tiPCcN42(iVar2,1,pcVar3,uVar1,uVar4,uVar5,uVar6);
  return 0;
}


// TeamFortress_TeamShowMemberClasses__11CBasePlayer  @ 000e2390
void TeamFortress_TeamShowMemberClasses__11CBasePlayer(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  bVar1 = false;
  for (iVar5 = 1; iVar5 <= *(int *)(gpGlobals + 0x90); iVar5 = iVar5 + 1) {
    piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar5);
    if ((piVar2 != (int *)0x0) && (piVar2 != param_1)) {
      iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar2);
      if (iVar3 != 0) {
        if (!bVar1) {
          bVar1 = true;
          ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_others",0,0,0,0);
        }
        uVar4 = UTIL_VarArgs__FPce(&DAT_0013a55e,*(undefined4 *)(sClassNames + piVar2[0xb] * 4),0,0)
        ;
        ClientPrint__FP9entvars_tiPCcN42
                  (*param_1,1,"#Game_othersdetails",
                   *(int *)(*piVar2 + 0x1b0) + *(int *)(gpGlobals + 0x98),uVar4);
      }
    }
  }
  if (!bVar1) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_noothers",0,0,0,0);
  }
  return;
}


// TeamFortress_TeamShowScores__FiP11CBasePlayer  @ 0010e5b0
void TeamFortress_TeamShowScores__FiP11CBasePlayer(int param_1,undefined4 *param_2)

{
  float fVar1;
  byte bVar3;
  undefined4 uVar2;
  int iVar4;
  
  iVar4 = 1;
  bVar3 = 1.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
          (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8);
  do {
    if (0x3f < (byte)(bVar3 - 1)) {
      return;
    }
    if (param_1 == 0) {
      uVar2 = UTIL_VarArgs__FPce("%s: %d\n",*(undefined4 *)(g_szTeamColors + iVar4 * 4),
                                 *(undefined4 *)(teamscores + iVar4 * 4),0,0,0,0);
LAB_0010e63f:
      UTIL_ClientPrintAll__FiPCcN41(1,uVar2);
    }
    else {
      if (param_2 == (undefined4 *)0x0) {
        uVar2 = UTIL_VarArgs__FPce("Team %d (%s): %d\n",iVar4,
                                   *(undefined4 *)(g_szTeamColors + iVar4 * 4),
                                   *(undefined4 *)(teamscores + iVar4 * 4),0,0,0,0);
        goto LAB_0010e63f;
      }
      uVar2 = UTIL_VarArgs__FPce("Team %d (%s): %d\n",iVar4,
                                 *(undefined4 *)(g_szTeamColors + iVar4 * 4),
                                 *(undefined4 *)(teamscores + iVar4 * 4),0,0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*param_2,1,uVar2);
    }
    iVar4 = iVar4 + 1;
    fVar1 = (float)iVar4;
    bVar3 = fVar1 < number_of_teams |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8);
  } while( true );
}


// TeamFortress_ThrowPrimedGrenade__11CBasePlayer  @ 000e3b00
void TeamFortress_ThrowPrimedGrenade__11CBasePlayer(int param_1)

{
  if (((*(byte *)(param_1 + 0x88) ^ 1) & 1) == 0) {
    *(byte *)(param_1 + 0x89) = *(byte *)(param_1 + 0x89) | 4;
  }
  return;
}


// TeamFortress_UpdateStatusBar__11CBasePlayer  @ 000f6a10
void TeamFortress_UpdateStatusBar__11CBasePlayer(int *param_1)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  float fVar4;
  char *pcVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  char *pcVar13;
  undefined4 *puVar14;
  undefined2 in_FPUControlWord;
  int *piStack_194;
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
  undefined2 uStack_128;
  undefined2 uStack_126;
  undefined4 uStack_124;
  char acStack_120 [128];
  undefined4 uStack_a0;
  char acStack_9c [124];
  int aiStack_20 [7];
  
  memset(aiStack_20,0,0x1c);
  uStack_a0 = uStack_a0 & 0xffffff00;
  strcpy(acStack_120,(char *)(param_1 + 0x305));
  if ((*gpGlobals < cb_prematch_time) || (*gpGlobals < (float)param_1[0x4c])) {
    if (cb_prematch_time <= *gpGlobals) {
      builtin_strncpy(acStack_120,"#Sbar_dead",0xb);
      fVar1 = (float)param_1[0x4c];
    }
    else {
      pcVar5 = "#Sbar_prematch";
      pcVar13 = acStack_120;
      for (iVar10 = 3; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar13 = pcVar13 + 4;
      }
      *(undefined2 *)pcVar13 = *(undefined2 *)pcVar5;
      pcVar13[2] = pcVar5[2];
      pcVar5 = "#Sbar_battleid";
      puVar14 = &uStack_a0;
      for (iVar10 = 3; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        puVar14 = puVar14 + 1;
      }
      *(undefined2 *)puVar14 = *(undefined2 *)pcVar5;
      *(char *)((int)puVar14 + 2) = pcVar5[2];
      aiStack_20[5] = param_1[0x7d];
      aiStack_20[6] = cease_fire;
      fVar1 = cb_prematch_time;
    }
    iVar10 = (int)ROUND(ROUND(fVar1 - *gpGlobals)) % 0x3c;
    if (iVar10 == 1) {
      aiStack_20[3] = 1;
    }
    else {
      aiStack_20[1] = iVar10;
    }
    uVar2 = CONCAT22(in_FPUControlWord,in_FPUControlWord) & 0xfffff3ff;
    uStack_124 = (float)(uVar2 | 0x800);
    fVar4 = uStack_124;
    uStack_124._2_2_ = (undefined2)(uVar2 >> 0x10);
    _uStack_128 = CONCAT22(uStack_126,uStack_124._2_2_);
    iStack_130 = (int)ROUND(ROUND(fVar1 - *gpGlobals) / 60.0);
    uStack_124 = fVar4;
    if (iStack_130 == 1) {
      aiStack_20[4] = 1;
      puVar11 = &stack0xfffffe20;
    }
    else {
      aiStack_20[2] = iStack_130;
      puVar11 = &stack0xfffffe20;
    }
    goto LAB_000f73f2;
  }
  iVar10 = *param_1;
  fStack_174 = *(float *)(iVar10 + 0x74) + *(float *)(iVar10 + 0x68);
  fStack_170 = *(float *)(iVar10 + 0x78) + *(float *)(iVar10 + 0x6c);
  fStack_16c = *(float *)(iVar10 + 0x7c) + *(float *)(iVar10 + 0x70);
  UTIL_MakeVectors__FRC6Vector();
  (**(code **)(param_1[0xf2] + 200))(&fStack_174,param_1);
  fStack_180 = fStack_174 + gpGlobals[10] * 2048.0;
  fStack_17c = fStack_170 + gpGlobals[0xb] * 2048.0;
  fStack_178 = fStack_16c + gpGlobals[0xc] * 2048.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_174,&fStack_180,0,*(undefined4 *)(*param_1 + 0x1e8),auStack_168);
  if ((byte)(1.0 < fStack_158 | (byte)((ushort)((ushort)NAN(fStack_158) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_158 == 1.0) << 0xe) >> 8)) != 0x40) {
    bVar3 = false;
    if ((iStack_138 == 0) || (iVar10 = (*DAT_001755d8)(iStack_138), iVar10 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      if (*gpGlobals < (float)param_1[0x346]) {
        aiStack_20[1] = param_1[0x340];
        aiStack_20[2] = param_1[0x341];
        aiStack_20[3] = param_1[0x342];
      }
    }
    else {
      if ((iStack_138 == 0) && (iStack_138 = (*DAT_001755d4)(0), iStack_138 == 0)) {
        piStack_194 = (int *)0x0;
      }
      else {
        piStack_194 = *(int **)(iStack_138 + 0xd8);
      }
      bVar3 = false;
      iVar10 = (**(code **)(piStack_194[0xf2] + 0x28))(piStack_194);
      if (iVar10 == 2) {
        if (((piStack_194[0x1d] != 0) &&
            (iVar10 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_194), iVar10 == 0)) ||
           ((iVar10 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_194), iVar10 == 0 &&
            (uStack_124 = SQRT((fStack_16c - fStack_14c) * (fStack_16c - fStack_14c) +
                               (fStack_170 - fStack_150) * (fStack_170 - fStack_150) +
                               (fStack_174 - fStack_154) * (fStack_174 - fStack_154)),
            1024.0 < uStack_124)))) {
LAB_000f6f90:
          if (!bVar3) goto LAB_000f70ab;
        }
        else {
          if (param_1[0x48] != 0) {
            iVar10 = __opP11CBaseEntity__7EHANDLE(piStack_194 + 0x77);
            if (((iVar10 != 0) && (param_1[0x48] != piStack_194[0x48])) && (piStack_194[0xb] == 8))
            {
              piStack_194 = (int *)__opP11CBaseEntity__7EHANDLE(piStack_194 + 0x77);
            }
          }
          aiStack_20[1] = (*DAT_001755dc)(*(undefined4 *)(*piStack_194 + 0x1e8));
          pcVar5 = "1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
          pcVar13 = acStack_120;
          for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
            pcVar5 = pcVar5 + 4;
            pcVar13 = pcVar13 + 4;
          }
          *pcVar13 = *pcVar5;
        }
      }
      else {
        iVar10 = strcmp((char *)(*(int *)*piStack_194 + (int)gpGlobals[0x26]),"building_sentrygun");
        if (iVar10 != 0) {
          iVar10 = strcmp((char *)(*(int *)*piStack_194 + (int)gpGlobals[0x26]),"building_dispenser"
                         );
          if (iVar10 == 0) {
            piVar6 = (int *)__rf__7EHANDLE(piStack_194 + 0x51);
            aiStack_20[1] = (*DAT_001755dc)(*(undefined4 *)(*piVar6 + 0x1e8));
            pcVar5 = "1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
            pcVar13 = acStack_120;
            for (iVar10 = 0xf; iVar10 != 0; iVar10 = iVar10 + -1) {
              *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
              pcVar5 = pcVar5 + 4;
              pcVar13 = pcVar13 + 4;
            }
            *pcVar13 = *pcVar5;
            bVar3 = true;
          }
          goto LAB_000f6f90;
        }
        piVar6 = (int *)__rf__7EHANDLE(piStack_194 + 0x51);
        aiStack_20[1] = (*DAT_001755dc)(*(undefined4 *)(*piVar6 + 0x1e8));
        pcVar5 = "1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
        pcVar13 = acStack_120;
        for (iVar10 = 0xf; iVar10 != 0; iVar10 = iVar10 + -1) {
          *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar13 = pcVar13 + 4;
        }
        *(undefined2 *)pcVar13 = *(undefined2 *)pcVar5;
      }
      iVar10 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piStack_194);
      if ((iVar10 != 0) || (param_1[0xb] == 5)) {
        aiStack_20[2] =
             (int)ROUND((*(float *)(*piStack_194 + 0x140) / *(float *)(*piStack_194 + 400)) * 100.0)
        ;
        _uStack_128 = CONCAT22(uStack_126,in_FPUControlWord);
        iStack_130 = CONCAT22(uStack_126,CONCAT11(0xc,(char)in_FPUControlWord));
        aiStack_20[3] =
             (int)ROUND((*(float *)(*piStack_194 + 0x19c) / (float)piStack_194[0x3c]) * 100.0);
      }
      param_1[0x346] = (int)(*gpGlobals + 1.0);
    }
  }
LAB_000f70ab:
  if (param_1[0xb] == 8) {
    if (param_1[0x1a] == 0) {
      if (param_1[0x75] == 0) {
        if (param_1[0x76] == 0) goto LAB_000f71cb;
        goto LAB_000f70d4;
      }
    }
    else {
LAB_000f70d4:
      if ((param_1[0x75] == 0) && (param_1[0x76] == 0)) {
        uStack_a0._0_1_ = '#';
        uStack_a0._1_1_ = 'S';
        uStack_a0._2_1_ = 'p';
        uStack_a0._3_1_ = 'y';
        builtin_strncpy(acStack_9c,"_disguising",0xc);
        goto LAB_000f71cb;
      }
    }
    pcVar5 = "#Spy_disguised";
    puVar14 = &uStack_a0;
    for (iVar10 = 3; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar14 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      puVar14 = puVar14 + 1;
    }
    *(undefined2 *)puVar14 = *(undefined2 *)pcVar5;
    *(char *)((int)puVar14 + 2) = pcVar5[2];
    if (param_1[0x75] != 0) {
      strcat((char *)&uStack_a0," ");
      pcVar5 = (char *)GetTeamName__Fi(param_1[0x75]);
      strcat((char *)&uStack_a0,pcVar5);
    }
    if (param_1[0x76] == 0) {
      strcat((char *)&uStack_a0," #");
      pcVar5 = (char *)sClassNames._32_4_;
    }
    else {
      strcat((char *)&uStack_a0," #");
      pcVar5 = *(char **)(sClassNames + param_1[0x76] * 4);
    }
    strcat((char *)&uStack_a0,pcVar5);
  }
LAB_000f71cb:
  if (param_1[0xb] == 9) {
    if (param_1[0x1b] == 0) {
      if (((param_1[0xb] == 9) &&
          (fVar1 = (float)param_1[0x54],
          (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) &&
         (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_sentrygun"),
         piVar6 != (int *)0x0)) {
        do {
          piVar7 = (int *)__opP11CBaseEntity__7EHANDLE(piVar6 + 0x51);
          if (piVar7 == param_1) {
            _uStack_128 = CONCAT22(uStack_126,in_FPUControlWord);
            iStack_130 = (int)ROUND((*(float *)(*piVar6 + 0x140) / *(float *)(*piVar6 + 400)) *
                                    100.0);
            iVar10 = iStack_130;
            if (iStack_130 < 0) {
              iVar10 = 0;
            }
            if (100 < iVar10) {
              iVar10 = 100;
            }
            sprintf((char *)&uStack_a0,"#Sentry_sbar %d",iVar10);
            strcat((char *)&uStack_a0,"%%\n4   ammo: %i4%%\n0 ");
            if (piVar6[0x33] == 0) {
LAB_000f7311:
              if ((piVar6[0x39] == 0) && (piVar6[0x24] == 3)) {
                pcVar5 = "#No_Ammo";
              }
              else {
                pcVar5 = "#No_Shells";
              }
            }
            else {
              _uStack_128 = CONCAT22(uStack_126,in_FPUControlWord);
              iStack_130 = CONCAT22(uStack_126,CONCAT11(0xc,(char)in_FPUControlWord));
              aiStack_20[4] = (int)ROUND(((float)piVar6[0x33] / (float)piVar6[0x30]) * 100.0);
              if (piVar6[0x33] == 0) goto LAB_000f7311;
              if ((piVar6[0x39] != 0) || (piVar6[0x24] != 3)) goto LAB_000f7360;
              pcVar5 = "#No_Rockets";
            }
            strcat((char *)&uStack_a0,pcVar5);
          }
LAB_000f7360:
          piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                    (piVar6,"building_sentrygun");
        } while (piVar6 != (int *)0x0);
      }
    }
    else {
      pcVar5 = "#Engineer_building";
      puVar14 = &uStack_a0;
      for (iVar10 = 4; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        puVar14 = puVar14 + 1;
      }
      *(undefined2 *)puVar14 = *(undefined2 *)pcVar5;
      *(char *)((int)puVar14 + 2) = pcVar5[2];
    }
  }
  if ((param_1[0xb] == 4) && (param_1[0x1c] != 0)) {
    pcVar5 = "#Demoman_detpacking";
    puVar14 = &uStack_a0;
    for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar14 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      puVar14 = puVar14 + 1;
    }
  }
  puVar11 = &stack0xfffffe1c;
  if (((char)uStack_a0 == '\0') &&
     (puVar11 = &stack0xfffffe1c,
     (byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
           (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) == 0x40)) {
    aiStack_20[5] = teamscores._4_4_;
    aiStack_20[6] = teamscores._8_4_;
    uVar8 = GetTeamName__Fi(2);
    uVar8 = GetTeamName__Fi(1,uVar8);
    sprintf((char *)&uStack_a0,"5%s: %%i5  \n6%s: %%i6\n",uVar8);
    puVar11 = &stack0xfffffe1c;
  }
LAB_000f73f2:
  *(int **)(puVar11 + -4) = param_1 + 0x2e5;
  *(undefined4 **)(puVar11 + -8) = &uStack_a0;
  *(undefined4 *)(puVar11 + -0xc) = 0xf7412;
  iVar10 = strcmp(*(char **)(puVar11 + -8),*(char **)(puVar11 + -4));
  if (iVar10 != 0) {
    *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(*param_1 + 0x1e8);
    *(undefined4 *)(puVar11 + -8) = 0;
    *(undefined4 *)(puVar11 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar11 + -0x10) = 1;
    *(undefined4 *)(puVar11 + -0x14) = 0xf7438;
    (*DAT_00175578)();
    *(undefined4 *)(puVar11 + -4) = 0;
    *(undefined4 *)(puVar11 + -8) = 0xf7444;
    (*DAT_00175580)();
    *(undefined4 **)(puVar11 + -8) = &uStack_a0;
    *(undefined4 *)(puVar11 + -0xc) = 0xf744d;
    (*DAT_00175598)();
    *(undefined4 *)(puVar11 + -0xc) = 0xf7454;
    (*DAT_0017557c)();
    *(undefined4 **)(puVar11 + -0xc) = &uStack_a0;
    *(int **)(puVar11 + -0x10) = param_1 + 0x2e5;
    *(undefined4 *)(puVar11 + -0x14) = 0xf745b;
    strcpy(*(char **)(puVar11 + -0x10),*(char **)(puVar11 + -0xc));
  }
  *(int **)(puVar11 + -4) = param_1 + 0x305;
  *(char **)(puVar11 + -8) = acStack_120;
  *(undefined4 *)(puVar11 + -0xc) = 0xf747e;
  iVar9 = strcmp(*(char **)(puVar11 + -8),*(char **)(puVar11 + -4));
  if (iVar9 != 0) {
    *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(*param_1 + 0x1e8);
    *(undefined4 *)(puVar11 + -8) = 0;
    *(undefined4 *)(puVar11 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar11 + -0x10) = 1;
    *(undefined4 *)(puVar11 + -0x14) = 0xf74a4;
    (*DAT_00175578)();
    *(undefined4 *)(puVar11 + -4) = 1;
    *(undefined4 *)(puVar11 + -8) = 0xf74b0;
    (*DAT_00175580)();
    *(char **)(puVar11 + -8) = acStack_120;
    *(undefined4 *)(puVar11 + -0xc) = 0xf74b9;
    (*DAT_00175598)();
    *(undefined4 *)(puVar11 + -0xc) = 0xf74c0;
    (*DAT_0017557c)();
    *(char **)(puVar11 + -0xc) = acStack_120;
    *(int **)(puVar11 + -0x10) = param_1 + 0x305;
    *(undefined4 *)(puVar11 + -0x14) = 0xf74c7;
    strcpy(*(char **)(puVar11 + -0x10),*(char **)(puVar11 + -0xc));
  }
  iVar12 = 1;
  do {
    if ((aiStack_20[iVar12] != param_1[iVar12 + 0x33f]) || (iVar9 != 0 || iVar10 != 0)) {
      *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(*param_1 + 0x1e8);
      *(undefined4 *)(puVar11 + -8) = 0;
      *(undefined4 *)(puVar11 + -0xc) = gmsgStatusValue;
      *(undefined4 *)(puVar11 + -0x10) = 1;
      *(undefined4 *)(puVar11 + -0x14) = 0xf7521;
      (*DAT_00175578)();
      *(int *)(puVar11 + -4) = iVar12;
      *(undefined4 *)(puVar11 + -8) = 0xf752d;
      (*DAT_00175580)();
      *(int *)(puVar11 + -8) = aiStack_20[iVar12];
      *(undefined4 *)(puVar11 + -0xc) = 0xf7540;
      (*DAT_00175588)();
      *(undefined4 *)(puVar11 + -0xc) = 0xf7547;
      (*DAT_0017557c)();
      param_1[iVar12 + 0x33f] = aiStack_20[iVar12];
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 < 7);
  return;
}


