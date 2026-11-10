// TeamFortress_Build__11CBasePlayeri  @ 000a6bd4
void TeamFortress_Build__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  float local_38;
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
  
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  local_24 = gpGlobals[10];
  local_20 = gpGlobals[0xb];
  local_1c = SQRT(local_20 * local_20 + local_24 * local_24);
  if ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = 0.0;
    local_20 = 0.0;
    local_1c = 1.0;
  }
  else {
    local_1c = 1.0 / local_1c;
    local_24 = local_1c * local_24;
    local_20 = local_1c * local_20;
    local_1c = local_1c * 0.0;
  }
  local_18 = local_24 * 64.0;
  local_14 = local_20 * 64.0;
  local_10 = local_1c * 64.0;
  local_28 = *(float *)(*param_1 + 8) + local_18;
  local_24 = *(float *)(*param_1 + 0xc) + local_14;
  local_20 = *(float *)(*param_1 + 0x10) + local_10;
  local_c = (float)(int)ROUND(local_28);
  local_8 = (float)(int)ROUND(local_24);
  local_4 = local_20;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x44] == 15.0) << 0xe) >> 8)) == 0x40) {
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x184) = 0;
  }
  if (param_2 == 1) {
    fVar1 = (float)param_1[0x53];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      pcVar4 = "#Build_onedispenser";
      goto LAB_000a6e82;
    }
    if (99 < param_1[0x37]) {
      local_28 = local_c;
      local_24 = local_8;
      local_20 = local_4;
      iVar3 = *param_1;
      local_1c = *(float *)(iVar3 + 0x74);
      local_18 = *(float *)(iVar3 + 0x78);
      local_14 = *(float *)(iVar3 + 0x7c);
      uVar2 = CreateDispenser__12CTFDispenserG6VectorT1P11CBaseEntity(&local_28,&local_1c,param_1);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,uVar2);
      local_38 = 2.0;
LAB_000a6eef:
      uVar2 = __rf__7EHANDLE(param_1 + 0x4e,param_1);
      iVar3 = CheckArea__11CBaseEntityP11CBaseEntity(uVar2);
      if (iVar3 != 0) {
        if (iVar3 == 2) {
          pcVar4 = "#Build_nobuild";
        }
        else {
          pcVar4 = "#Build_noroom";
        }
        ClientPrint__FP9entvars_siPCcN42(*param_1,4,pcVar4,0,0,0,0);
        uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
        UTIL_Remove__FP11CBaseEntity(uVar2);
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
        return;
      }
      if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
        ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Build_air",0,0,0,0);
        uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
        UTIL_Remove__FP11CBaseEntity(uVar2);
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
        return;
      }
      param_1[0x1a] = 1;
      param_1[99] = (int)(*gpGlobals + 5.0);
      *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      if (param_1[0x22d] != 0) {
        (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x128))(param_1[0x22d],0);
      }
      piVar5 = (int *)CreateTimer__11CBaseEntityi(param_1,0xb);
      piVar5[3] = -0x10000;
      piVar5[4] = (int)Timer_FinishedBuilding__11CBaseEntity;
      *(float *)(*piVar5 + 0x104) = local_38 + *gpGlobals;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"weapons/building.wav",0x3f7ae148,0x3f4ccccd,0,
                 0x7d);
      return;
    }
  }
  else {
    if (param_2 != 2) {
      return;
    }
    fVar1 = (float)param_1[0x54];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      pcVar4 = "#Build_onesentry";
      goto LAB_000a6e82;
    }
    if (0x81 < param_1[0x37]) {
      local_28 = local_c;
      local_24 = local_8;
      local_20 = local_4;
      iVar3 = *param_1;
      local_1c = *(float *)(iVar3 + 0x74);
      local_18 = *(float *)(iVar3 + 0x78);
      local_14 = *(float *)(iVar3 + 0x7c);
      uVar2 = CreateSentryBase__16CTFSentrygunBaseG6VectorT1P11CBaseEntity
                        (&local_28,&local_1c,param_1);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,uVar2);
      local_38 = 5.0;
      goto LAB_000a6eef;
    }
  }
  pcVar4 = "#Build_notenoughmetal";
LAB_000a6e82:
  ClientPrint__FP9entvars_siPCcN42(*param_1,4,pcVar4,0,0,0,0);
  return;
}


// TeamFortress_CalcEMPDmgRad__11CBaseEntityRfT1  @ 0008f7b0
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


// TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1  @ 000e3b04
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = (float)_FUN_0014c218;
  *param_3 = fVar1 * (float)param_1[0x39] + (float)param_1[0x33] * 0.75;
  if (*(int *)(*param_1 + 0x20c) != 9) {
    *param_3 = fVar1 * (float)param_1[0x37] + *param_3;
  }
  *param_2 = *param_3;
  return;
}


// TeamFortress_CheckClassStats__11CBasePlayer  @ 000e2a04
void TeamFortress_CheckClassStats__11CBasePlayer(void)

{
  FUN_000e2a0a();
  return;
}


// TeamFortress_Concuss__11CBaseEntityP9entvars_s  @ 0010f3c0
void TeamFortress_Concuss__11CBaseEntityP9entvars_s(void)

{
  return;
}


// TeamFortress_Concuss__11CBasePlayerP9entvars_s  @ 000e4140
void TeamFortress_Concuss__11CBasePlayerP9entvars_s(int *param_1)

{
  param_1[0x27e] = 100;
  param_1[0x280] = 100;
  param_1[0x281] = *gpGlobals;
  param_1[0x282] = 0x41700000;
  if (*(int *)(*param_1 + 0x20c) == 5) {
    param_1[0x282] = 0x40e00000;
  }
  return;
}


// TeamFortress_DetpackStop__11CBasePlayer  @ 0009b6b0
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
    (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x120))(param_1[0x22d]);
  }
  return;
}


// TeamFortress_Discard__11CBasePlayer  @ 001055a0
void TeamFortress_Discard__11CBasePlayer(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int iVar7;
  longdouble lVar8;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  
  local_38 = 0;
  local_3c = 0;
  local_40 = 0;
  local_44 = 0;
  switch(*(undefined4 *)(*param_1 + 0x20c)) {
  case 1:
  case 8:
    local_3c = param_1[0x39];
    break;
  case 2:
  case 5:
    local_3c = param_1[0x39];
    local_40 = param_1[0x37];
    break;
  case 3:
  case 4:
    local_40 = param_1[0x37];
    goto LAB_0010564a;
  case 6:
    local_3c = param_1[0x39];
LAB_0010564a:
    local_38 = param_1[0x35];
    break;
  case 7:
    local_38 = param_1[0x35];
    break;
  case 9:
    local_3c = param_1[0x39];
  }
  param_1[0x35] = param_1[0x35] - local_38;
  param_1[0x39] = param_1[0x39] - local_3c;
  param_1[0x37] = param_1[0x37] - local_40;
  if (*(int *)(*param_1 + 0x20c) != 9) goto LAB_00105a39;
  iVar7 = 2;
  if (local_38 < 0x14) {
    iVar7 = 3;
  }
  if (local_3c < 10) {
    iVar7 = iVar7 + 1;
  }
  iVar7 = (int)ROUND(ROUND((longdouble)param_1[0x37] / (longdouble)iVar7));
  if (ROUND((float)iVar7 * 0.5) <= 20.0) {
    local_44 = (int)ROUND(ROUND((float)iVar7 * 0.5));
    if (local_44 != 0) goto LAB_0010579c;
  }
  else {
    local_44 = 0x14;
LAB_0010579c:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_shells",0,0,0,0);
    param_1[0x37] = param_1[0x37] + local_44 * -2;
  }
  if (ROUND((float)iVar7 * 0.5) <= 10.0) {
    local_40 = (int)ROUND(ROUND((float)iVar7 * 0.5));
    if (local_40 != 0) goto LAB_00105864;
  }
  else {
    local_40 = 10;
LAB_00105864:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_cells",0,0,0,0);
    param_1[0x37] = param_1[0x37] + local_40 * -2;
  }
  if (local_38 < 0x14) {
    lVar8 = (longdouble)(0x14 - local_38);
    if (ROUND((longdouble)iVar7) + (longdouble)local_38 <= lVar8) {
      lVar8 = ROUND((longdouble)iVar7) + (longdouble)local_38;
    }
    iVar1 = (int)ROUND(lVar8);
    if (iVar1 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_nails",0,0,0,0);
      param_1[0x37] = param_1[0x37] - iVar1;
    }
    local_38 = local_38 + iVar1;
  }
  if (local_3c < 10) {
    fVar2 = (float)(10 - local_3c);
    if (ROUND((float)iVar7 * 0.5) + (float)local_3c <= fVar2) {
      fVar2 = ROUND((float)iVar7 * 0.5) + (float)local_3c;
    }
    iVar7 = (int)ROUND(fVar2);
    if (iVar7 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_rockets",0,0,0,0);
      param_1[0x37] = param_1[0x37] + iVar7 * -2;
    }
    local_3c = local_3c + iVar7;
  }
LAB_00105a39:
  if (((local_38 != 0) || (local_3c != 0)) || (local_40 != 0)) {
    param_1[0x366] = param_1[0x366] + 1;
    if (3 < param_1[0x366]) {
      RemoveOldAmmobox__11CBasePlayer(param_1);
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/ammopickup1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    piVar6 = (int *)GetClassPtr__H1Z10CWeaponBox_PX01_PX01(0);
    (**(code **)(piVar6[0x111] + 0xc))(piVar6);
    *(char **)(*piVar6 + 0x1d0) = "?tf_ammobox" + (1 - (int)gpGlobals[0x26]);
    *(char **)*piVar6 = "?tf_ammobox" + (1 - (int)gpGlobals[0x26]);
    *(undefined4 *)(*piVar6 + 400) = *(undefined4 *)(*param_1 + 0x208);
    piVar6[0x118] = (int)(*gpGlobals + 2.0);
    piVar6[0x48] = param_1[0x48];
    piVar6[0x119] = (int)*gpGlobals;
    piVar6[0x35] = local_38;
    piVar6[0x39] = local_3c;
    piVar6[0x37] = local_40;
    piVar6[0x33] = local_44;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar6,*param_1 + 8);
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
    iVar7 = *piVar6;
    *(undefined4 *)(iVar7 + 0x50) = g_vecZero;
    *(undefined4 *)(iVar7 + 0x54) = DAT_001c0fe4;
    *(undefined4 *)(iVar7 + 0x58) = DAT_001c0fe8;
    iVar7 = *piVar6;
    fVar2 = gpGlobals[0xb];
    fVar3 = gpGlobals[0xc];
    fVar4 = gpGlobals[0xe];
    fVar5 = gpGlobals[0xf];
    *(float *)(iVar7 + 0x20) = gpGlobals[10] * 400.0 + gpGlobals[0xd] * 200.0;
    *(float *)(iVar7 + 0x24) = fVar2 * 400.0 + fVar4 * 200.0;
    *(float *)(iVar7 + 0x28) = fVar3 * 400.0 + fVar5 * 200.0;
    piVar6[3] = -0x10000;
    piVar6[4] = (int)Kill__10CWeaponBox;
    *(float *)(*piVar6 + 0x104) = *gpGlobals + 30.0;
  }
  return;
}


// TeamFortress_DisplayDetectionItems__11CBasePlayer  @ 00105f9c
void TeamFortress_DisplayDetectionItems__11CBasePlayer(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_tfdetect");
  if (iVar1 != 0) {
    DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(param_1,iVar1);
  }
  return;
}


// TeamFortress_DisplayLegalClasses__11CBasePlayer  @ 000e1688
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
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#HWGuy",0,0,0,0);
  }
  if ((((byte)illegalclasses & 0x40) == 0) && ((uVar1 & 0x40) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Pyro",0,0,0,0);
  }
  if (((illegalclasses._1_1_ & 1) == 0) && ((uVar1 & 0x100) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,&DAT_0014bd3c,0,0,0,0);
  }
  if (((illegalclasses._1_1_ & 2) == 0) && ((uVar1 & 0x200) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Engineer",0,0,0,0);
  }
  if ((-1 < (char)(byte)illegalclasses) && (-1 < (char)(byte)uVar1)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#RandomPC",0,0,0,0);
  }
  return;
}


// TeamFortress_EMPExplode__11CBaseEntityP9entvars_sff  @ 0008f604
void TeamFortress_EMPExplode__11CBaseEntityP9entvars_sff
               (int *param_1,int param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  iVar2 = *(int *)(param_2 + 0x198);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001c1134)(0);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)0x0;
      goto LAB_0008f64a;
    }
  }
  puVar3 = *(undefined4 **)(iVar2 + 0x7c);
LAB_0008f64a:
  _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
  local_c = (int)ROUND(param_3 * 0.75);
  if (local_c < 0x100) {
    iVar2 = local_c;
    if (local_c < 5) {
      iVar2 = 5;
    }
  }
  else {
    iVar2 = 0xff;
  }
  iVar1 = *param_1;
  local_18 = *(undefined4 *)(iVar1 + 8);
  local_14 = *(undefined4 *)(iVar1 + 0xc);
  local_10 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii(&local_18,param_2,*puVar3,param_3,param_4,0,0x4000040);
  (*DAT_001c10d8)(5,0x17,*param_1 + 8,0);
  (*DAT_001c10e0)(3);
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001c10e8)((int)g_sModelIndexFireball);
  (*DAT_001c10e0)(iVar2);
  (*DAT_001c10e0)(0xf);
  (*DAT_001c10e0)(3);
  (*DAT_001c10dc)();
  return;
}


// TeamFortress_EMPRemove__11CBaseEntity  @ 0008f81c
void TeamFortress_EMPRemove__11CBaseEntity(undefined4 param_1)

{
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// TeamFortress_EMPRemove__5CItem  @ 000b6d08
void TeamFortress_EMPRemove__5CItem(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x444) + 0xc0))(param_1);
  return;
}


// TeamFortress_EngineerBuild__11CBasePlayeri  @ 000a674c
void TeamFortress_EngineerBuild__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
  if (iVar1 == 0) {
    return;
  }
  if (*gpGlobals < cb_prematch_time) {
    return;
  }
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x1a5) & 2) == 0) {
    pcVar3 = "#Build_air";
  }
  else {
    if (param_1[0x1a] != 0) {
      if (param_1[0x1a] != 1) {
        return;
      }
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Build_stop",0,0,0,0);
      *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      iVar1 = FindTimer__11CBaseEntityi(param_1,0xb);
      if (iVar1 != 0) {
        dremove__FP11CBaseEntity(iVar1);
      }
      uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
      UTIL_Remove__FP11CBaseEntity(uVar2);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
      param_1[0x1a] = 0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"weapons/building.wav",0,0,0x20,100);
      if (param_1[0x22d] == 0) {
        return;
      }
      (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x120))(param_1[0x22d]);
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
    iVar1 = *param_1;
  }
  ClientPrint__FP9entvars_siPCcN42(iVar1,4,pcVar3,0,0,0,0);
  return;
}


// TeamFortress_ExecClassScript__11CBasePlayer  @ 000e18a4
void TeamFortress_ExecClassScript__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((((*(int *)(iVar1 + 0x20c) != 0xb) && (*(int *)(iVar1 + 0x20c) != 0)) &&
      (*(int *)(iVar1 + 0x20c) != 10)) &&
     ((param_1[0xc] != *(int *)(iVar1 + 0x20c) &&
      (param_1[0xc] = *(int *)(iVar1 + 0x20c), param_1[0x3d] != 0)))) {
    (*DAT_001c10d8)(1,9,0,*(undefined4 *)(iVar1 + 0x208));
    (*DAT_001c10f8)(*(undefined4 *)(sClassCfgs + *(int *)(*param_1 + 0x20c) * 4));
    (*DAT_001c10dc)();
  }
  return;
}


// TeamFortress_ExecMapScript__11CBasePlayer  @ 000e194c
void TeamFortress_ExecMapScript__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x3e] != 0) {
    (*DAT_001c10d8)(1,9,0,*(undefined4 *)(*param_1 + 0x208));
    uVar1 = UTIL_VarArgs__FPce(FUN_0014bd60,*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98));
    (*DAT_001c10f8)(uVar1);
    (*DAT_001c10dc)();
  }
  return;
}


// TeamFortress_GetNoPlayers__Fv  @ 00110180
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


// TeamFortress_InitStatusBar__11CBasePlayer  @ 000fb3b8
void TeamFortress_InitStatusBar__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0xdc8) = 0;
  *(undefined1 *)(param_1 + 0xc20) = 0;
  *(undefined1 *)(param_1 + 0xca0) = 0;
  return;
}


// TeamFortress_PrimeGrenade__11CBasePlayeri  @ 000e41b0
void TeamFortress_PrimeGrenade__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((((*(byte *)(param_1 + 0x21) & 1) == 0) && ((*(byte *)((int)param_1 + 0x85) & 4) == 0)) &&
     (iVar1 = (**(code **)(param_1[0x111] + 0x8c))(param_1), iVar1 != 0)) {
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
        goto switchD_000e4230_caseD_6;
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
      *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) | 1;
      param_1[0x24] = param_2;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),1,"weapons/ax1.wav",0x3f666666,0x3f4ccccd,0,100);
    }
  }
switchD_000e4230_caseD_6:
  return;
}


// TeamFortress_PrintClassName__11CBasePlayeri  @ 000df9fc
void TeamFortress_PrintClassName__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = UTIL_VarArgs__FPce(&DAT_0014ba48,(&sClassNames)[param_2],0,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,uVar1);
  return;
}


// TeamFortress_RemoveBuildings__11CBasePlayer  @ 000a6554
void TeamFortress_RemoveBuildings__11CBasePlayer(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    iVar5 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar5,"building_dispenser");
    if (iVar5 == 0) goto LAB_000a65ff;
    puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(iVar5 + 0x144);
  } while (puVar3 != param_1);
  if (param_1[0x364] == 0) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Dispenser_destroyed",0,0,0,0);
  }
  param_1[0x53] = 0;
  param_1[0x364] = 0;
  dremove__FP11CBaseEntity(iVar5);
LAB_000a65ff:
  iVar5 = 0;
  do {
    iVar5 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar5,"building_sentrygun");
    if (iVar5 == 0) goto LAB_000a66ef;
    puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(iVar5 + 0x144);
  } while (puVar3 != param_1);
  if (param_1[0x363] == 0) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Sentry_destroyed",0,0,0,0);
  }
  param_1[0x54] = 0;
  param_1[0x363] = 0;
  for (iVar4 = 1; iVar4 <= *(int *)(gpGlobals + 0x90); iVar4 = iVar4 + 1) {
    iVar1 = UTIL_PlayerByIndex__Fi(iVar4);
    if (iVar1 != 0) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1 + 0x138);
      if (iVar2 == iVar5) {
        ResetMenu__11CBasePlayer(iVar1);
        __as__7EHANDLEP11CBaseEntity(iVar1 + 0x138,0);
      }
    }
  }
  dremove__FP11CBaseEntity(iVar5);
LAB_000a66ef:
  iVar5 = 0;
  do {
    iVar5 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar5,"building_sentrygun_base");
    if (iVar5 == 0) {
      return;
    }
    puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(iVar5 + 0x144);
  } while (puVar3 != param_1);
  dremove__FP11CBaseEntity(iVar5);
  return;
}


// TeamFortress_RemoveDetpacks__11CBasePlayer  @ 0009b72c
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


// TeamFortress_RemoveLiveGrenades__11CBasePlayer  @ 000e21f8
void TeamFortress_RemoveLiveGrenades__11CBasePlayer(undefined4 param_1)

{
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_napalmgrenade");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_nailgrenade");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_gasgrenade");
  return;
}


// TeamFortress_RemoveRockets__11CBasePlayer  @ 000e2238
void TeamFortress_RemoveRockets__11CBasePlayer(undefined4 param_1)

{
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_rpg_rocket");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_ic_rocket");
  return;
}


// TeamFortress_RemoveTimers__11CBasePlayer  @ 000e24ac
void TeamFortress_RemoveTimers__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  
  param_1[0x68] = 0;
  param_1[0x19] = 0;
  if ((*(byte *)((int)param_1 + 0x85) & 8) != 0) {
    *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) & 0xf7;
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
  if ((*(byte *)(param_1 + 0x21) & 0x10) != 0) {
    *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xef;
  }
  if ((*(byte *)((int)param_1 + 0x85) & 0x40) != 0) {
    *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) & 0xbf;
  }
  while (iVar1 = FindTimer__11CBaseEntityi(param_1,0), iVar1 != 0) {
    if (*(float *)(iVar1 + 0x1c4) <= 0.0) {
      SUB_Remove__11CBaseEntity(iVar1);
    }
  }
  piVar4 = (int *)0x0;
LAB_000e276f:
  do {
    do {
      piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"item_tfgoal");
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
        while (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"detpack"),
              piVar4 != (int *)0x0) {
          if (((byte)((byte)((ushort)((ushort)NAN((float)piVar4[0x42]) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)piVar4[0x42] == 1.0) << 0xe) >> 8)) == 0x40) &&
             (*(int *)(*piVar4 + 400) == *(int *)(*param_1 + 0x208))) {
            piVar4[0x42] = 0;
          }
        }
        ExplodeOldPipebomb__11CBasePlayerii(param_1,1,1);
        param_1[0xfc] = 0;
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x15c) = 0;
        iVar1 = *param_1;
        *(undefined4 *)(iVar1 + 0x150) = g_vecZero;
        *(undefined4 *)(iVar1 + 0x154) = DAT_001c0fe4;
        *(undefined4 *)(iVar1 + 0x158) = DAT_001c0fe8;
        *(undefined4 *)(*param_1 + 0x14c) = 0;
        *(undefined4 *)(*param_1 + 0x148) = 0;
        *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
        return;
      }
    } while (*(int *)(*piVar4 + 0x198) != *(int *)(*param_1 + 0x208));
    if ((*(byte *)((int)piVar4 + 0x229) & 1) == 0) {
      tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar4,param_1,0);
    }
  } while (CTF_Map != 1);
  if (piVar4[0x84] != 1) goto code_r0x000e269f;
  uVar2 = UTIL_VarArgs__FPce("%s LOST the BLUE flag!\n",
                             *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
  UTIL_ClientPrintAll__FiPCcN41(4,uVar2,0,0,0,0);
  if (param_1[0x48] == 0) {
    pcVar3 = "SPECTATOR";
  }
  else {
    pcVar3 = (char *)GetTeamName__Fi(param_1[0x48]);
  }
  uVar2 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
  uVar2 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar2);
  iVar1 = *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98);
  pcVar3 = "\"%s<%i><%u><%s>\" triggered \"Dropped_Blue_Flag\"\n";
  goto LAB_000e275e;
code_r0x000e269f:
  if (piVar4[0x84] == 2) {
    uVar2 = UTIL_VarArgs__FPce("%s LOST the RED flag!\n",
                               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    UTIL_ClientPrintAll__FiPCcN41(4,uVar2,0,0,0,0);
    if (param_1[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_1[0x48]);
    }
    uVar2 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
    uVar2 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar2);
    iVar1 = *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = "\"%s<%i><%u><%s>\" triggered \"Dropped_Red_Flag\"\n";
LAB_000e275e:
    UTIL_LogPrintf__FPce(pcVar3,iVar1,uVar2);
  }
  goto LAB_000e276f;
}


// TeamFortress_SaveMe__11CBasePlayer  @ 00105cb8
void TeamFortress_SaveMe__11CBasePlayer(int *param_1)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  longdouble lVar6;
  longdouble lVar7;
  
  if ((float)param_1[100] < *gpGlobals) {
    lVar6 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
    lVar7 = (longdouble)0.8;
    if ((byte)((lVar7 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) - 1) < 0x40) {
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "speech/saveme2.wav";
    }
    else {
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "speech/saveme1.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar4,1,pcVar2,0x3f800000,0x3f4ccccd,0,100);
    param_1[100] = (int)(*gpGlobals + 4.0);
  }
  piVar5 = (int *)0x0;
  while( true ) {
    piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"player");
    if (piVar5 == (int *)0x0) {
      return;
    }
    bVar1 = false;
    if ((*(int *)(*piVar5 + 0x208) == 0) ||
       (iVar3 = (*DAT_001c1138)(*(int *)(*piVar5 + 0x208)), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    if ((*piVar5 != 0) &&
       (((iVar3 = *piVar5, *(int *)(iVar3 + 0x20c) == 5 || (*(int *)(iVar3 + 0x20c) == 8)) ||
        (*(int *)(iVar3 + 0x20c) == 9)))) {
      (*DAT_001c10d8)(1,0x17,0,*(undefined4 *)(*piVar5 + 0x208));
      (*DAT_001c10e0)(0x7c);
      uVar4 = (*DAT_001c113c)(*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001c10e0)(uVar4);
      (*DAT_001c10f4)(0x42480000);
      (*DAT_001c10e8)((int)g_sModelIndexSaveMe);
      (*DAT_001c10e8)(0x28);
      (*DAT_001c10dc)();
    }
  }
  return;
}


// TeamFortress_SetDetpack__11CBasePlayeri  @ 0009b3f4
void TeamFortress_SetDetpack__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  int *local_4;
  
  if ((*(byte *)((int)param_1 + 0x156) & 2) == 0) {
    return;
  }
  if (param_1[0x31] < 1) {
    return;
  }
  local_4 = (int *)0x0;
  do {
    local_4 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                               (local_4,*param_1 + 8,0x42820000);
    if (local_4 == (int *)0x0) {
      iVar1 = *param_1;
      if ((*(byte *)(iVar1 + 0x1a5) & 2) == 0) {
        pcVar3 = "#Detpack_air";
        goto LAB_0009b5da;
      }
      piVar4 = (int *)0x0;
      goto LAB_0009b55b;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"player");
    if ((iVar1 == 0) && (local_4 != param_1)) {
      pcVar3 = "#Detpack_someone";
      goto LAB_0009b5be;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"building_sentrygun");
    if (iVar1 == 0) {
      pcVar3 = "#Detpack_sentry";
      goto LAB_0009b5be;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"building_dispenser");
    if (iVar1 == 0) {
      pcVar3 = "#Detpack_dispenser";
      goto LAB_0009b5be;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"detpack");
  } while (iVar1 != 0);
  pcVar3 = "#Detpack_stack";
LAB_0009b5be:
  iVar1 = *param_1;
  goto LAB_0009b5da;
  while (iVar1 = *param_1, *(int *)(*piVar4 + 0x198) != *(int *)(iVar1 + 0x208)) {
LAB_0009b55b:
    piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"detpack");
    if (piVar4 == (int *)0x0) {
      if (4 < param_2) {
        param_1[0x1b] = 1;
        param_1[0x31] = param_1[0x31] + -1;
        param_1[99] = (int)(*gpGlobals + 10.0);
        *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
        TeamFortress_SetSpeed__11CBasePlayer(param_1);
        (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x128))(param_1[0x22d],0);
        *(undefined4 *)(*param_1 + 0xc0) = 0;
        uVar2 = UTIL_dtos1__Fi(param_2,0,0,0);
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Detpack_set",uVar2);
        piVar4 = (int *)CreateTimer__11CBaseEntityi(param_1,9);
        *(float *)(*piVar4 + 0x104) = *gpGlobals + 3.0;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)Timer_DetpackSet__11CBaseEntity;
        *(float *)(*piVar4 + 0x160) = (float)param_2;
        return;
      }
      pcVar3 = "#Detpack_fivesec";
      goto LAB_0009b5be;
    }
  }
  pcVar3 = "#Detpack_oneactive";
LAB_0009b5da:
  ClientPrint__FP9entvars_siPCcN42(iVar1,1,pcVar3,0,0,0,0);
  return;
}


// TeamFortress_SetEquipment__11CBasePlayer  @ 000e02a4
void TeamFortress_SetEquipment__11CBasePlayer(int *param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  
  uVar1 = param_1[0xf];
  param_1[0x22] = 0;
  param_1[0x58] = 0;
  param_1[0x57] = 0;
  param_1[0x56] = 0;
  param_1[0x55] = 0;
  param_1[0xf] = 0;
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
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x42] = 0;
  param_1[0x4c] = 0;
  param_1[0x61] = 0;
  param_1[0x21] = param_1[0x21] - (param_1[0x21] & 2U);
  if (param_1[0x48] == 0) {
    param_1[0x49] = -1;
  }
  param_1[0x22] = param_1[0x22] | uVar1 & 0x60000;
  if (*(int *)(*param_1 + 0x20c) == 1) {
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
      *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 1;
    }
    *(undefined4 *)(*param_1 + 0x1b8) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x41c80000;
    param_1[0x3b] = 0x3e99999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x44000000;
    param_1[0x3a] = 0x290;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 5;
    GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bb28);
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
    pcVar3 = "tf_weapon_ng";
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ng");
    param_1[0x33] = param_1[0x33] + -8;
LAB_000e0ee7:
    SwitchWeapon__11CBasePlayerPCc(param_1,pcVar3);
    goto LAB_000e0fde;
  }
  if (*(int *)(*param_1 + 0x20c) == 2) {
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
    *(undefined4 *)(*param_1 + 0x1b8) = 0x3e99999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0;
    param_1[0x3b] = 0x3e99999a;
    param_1[0x3c] = 0x42480000;
    param_1[0x56] = 0x42000000;
    param_1[0x3a] = 0x270;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 7;
    GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bb28);
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ng");
    pcVar3 = "tf_weapon_sniperrifle";
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_sniperrifle");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_autorifle");
  }
  else if (*(int *)(*param_1 + 0x20c) == 3) {
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
    *(undefined4 *)(*param_1 + 0x1b8) = 0x3f4ccccd;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x42c80000;
    param_1[0x3b] = 0x3f4ccccd;
    param_1[0x3c] = 0x43480000;
    param_1[0x56] = 0x46000000;
    param_1[0x3a] = 0x2190;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x23;
    GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bb28);
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
    pcVar3 = "tf_weapon_rpg";
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_rpg");
    param_1[0x33] = param_1[0x33] + -0x18;
    param_1[0x39] = param_1[0x39] + -4;
  }
  else if (*(int *)(*param_1 + 0x20c) == 4) {
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
    *(undefined4 *)(*param_1 + 0x1b8) = 0x3f19999a;
    *(undefined4 *)(*param_1 + 0x1bc) = 0x42480000;
    param_1[0x3b] = 0x3f19999a;
    param_1[0x3c] = 0x42f00000;
    param_1[0x56] = 0x45000000;
    param_1[0x3a] = 0x20890;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x11;
    param_1[0x21e] = 6;
    GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bb28);
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
    pcVar3 = "tf_weapon_gl";
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_gl");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_pl");
    param_1[0x33] = param_1[0x33] + -8;
    param_1[0x39] = param_1[0x39] + -6;
  }
  else {
    if (*(int *)(*param_1 + 0x20c) == 5) {
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
      *(undefined4 *)(*param_1 + 0x1b8) = 0x3e99999a;
      *(undefined4 *)(*param_1 + 0x1bc) = 0x42480000;
      param_1[0x3b] = 0x3f19999a;
      param_1[0x3c] = 0x42c80000;
      param_1[0x56] = 0x44800000;
      param_1[0x2f] = 0x32;
      param_1[0x2e] = 100;
      piVar2 = (int *)CreateTimer__11CBaseEntityi(param_1,6);
      *(float *)(*piVar2 + 0x104) = *gpGlobals + 3.0;
      piVar2[3] = -0x10000;
      piVar2[4] = (int)Timer_Regeneration__11CBaseEntity;
      param_1[0x3a] = 0x586;
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0xb;
      GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bbb0);
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
      pcVar3 = "tf_weapon_superng";
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_superng");
      param_1[0x33] = param_1[0x33] + -0x18;
LAB_000e0cb6:
      SwitchWeapon__11CBasePlayerPCc(param_1,pcVar3);
      goto LAB_000e0fde;
    }
    if (*(int *)(*param_1 + 0x20c) == 6) {
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
      *(undefined4 *)(*param_1 + 0x1b8) = 0x3f4ccccd;
      *(undefined4 *)(*param_1 + 0x1bc) = 0x43160000;
      param_1[0x3b] = 0x3f4ccccd;
      param_1[0x3c] = 0x43960000;
      param_1[0x56] = 0x47000000;
      param_1[0x3a] = 0x8190;
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x23;
      GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bb28);
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
      GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bbd4);
      param_1[0x33] = param_1[0x33] + -0x18;
      pcVar3 = (char *)FUN_0014bbd4;
    }
    else if (*(int *)(*param_1 + 0x20c) == 7) {
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
      *(undefined4 *)(*param_1 + 0x1b8) = 0x3f19999a;
      *(undefined4 *)(*param_1 + 0x1bc) = 0x42480000;
      param_1[0x3b] = 0x3f19999a;
      param_1[0x3c] = 0x43160000;
      param_1[0x56] = 0x45800000;
      param_1[0x3a] = 0x5090;
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 0x31;
      GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bb28);
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ic");
      pcVar3 = "tf_weapon_flamethrower";
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_flamethrower");
      param_1[0x33] = param_1[0x33] + -8;
    }
    else {
      if (*(int *)(*param_1 + 0x20c) == 0xb) {
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
        *(undefined4 *)(*param_1 + 0x1b8) = 0;
        *(undefined4 *)(*param_1 + 0x1bc) = 0;
        param_1[0x3b] = 0;
        param_1[0x3c] = 0;
        param_1[0x56] = 0x41800000;
        param_1[0x3a] = 0x10;
        param_1[0x22] = 0;
        GiveNamedItem__11CBasePlayerPc(param_1,FUN_0014bb28);
        pcVar3 = (char *)FUN_0014bb28;
        goto LAB_000e0cb6;
      }
      if (*(int *)(*param_1 + 0x20c) != 8) {
        if (*(int *)(*param_1 + 0x20c) != 9) {
          if (*(int *)(*param_1 + 0x20c) == 0) {
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
            *(undefined4 *)(*param_1 + 0x1b8) = 0;
            *(undefined4 *)(*param_1 + 0x1bc) = 0;
            param_1[0x56] = 0;
            param_1[0x55] = 0;
            *(undefined4 *)(*param_1 + 0x1a4) = 0x88;
            *(undefined4 *)(*param_1 + 0x1c0) = 3;
            *(undefined4 *)(*param_1 + 0x16c) = 0;
            *(undefined4 *)(*param_1 + 0x10c) = 0;
            *(undefined4 *)(*param_1 + 0x108) = 8;
            *(undefined4 *)(*param_1 + 0xb4) = 0;
            *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) | 2;
            *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
          }
          goto LAB_000e0fde;
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
        *(undefined4 *)(*param_1 + 0x1b8) = 0x3e99999a;
        *(undefined4 *)(*param_1 + 0x1bc) = 0x41c80000;
        param_1[0x3b] = 0x3f19999a;
        param_1[0x3c] = 0x42480000;
        param_1[0x56] = 0x49000000;
        param_1[0x3a] = 0x80108;
        *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 3;
        GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_spanner");
        pcVar3 = "tf_weapon_railgun";
        GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_railgun");
        GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
        param_1[0x33] = param_1[0x33] + -0x10;
        goto LAB_000e0ee7;
      }
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
      *(undefined4 *)(*param_1 + 0x1b8) = 0x3f19999a;
      *(undefined4 *)(*param_1 + 0x1bc) = 0x41c80000;
      param_1[0x3b] = 0x3f19999a;
      param_1[0x3c] = 0x42c80000;
      param_1[0x56] = 0x48800000;
      param_1[0x3a] = (int)"amplayP11CBasePlayer";
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 7;
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_knife");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
      pcVar3 = "tf_weapon_tranq";
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_tranq");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ng");
      param_1[0x33] = param_1[0x33] + -0x10;
    }
  }
  SwitchWeapon__11CBasePlayerPCc(param_1,pcVar3);
LAB_000e0fde:
  SetLastWeapon__11CBasePlayer(param_1);
  if (*(float *)(*param_1 + 0x1b8) < 0.8) {
    if (*(float *)(*param_1 + 0x1b8) < 0.6) {
      if (0.3 <= *(float *)(*param_1 + 0x1b8)) {
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
  if ((*(int *)(*param_1 + 0x20c) == 0) && (*(int *)(*param_1 + 0x244) == 0)) {
    *(byte *)(param_1 + 0x223) = *(byte *)(param_1 + 0x223) | 4;
  }
  else {
    *(byte *)(param_1 + 0x223) = *(byte *)(param_1 + 0x223) & 0xfb;
  }
  return;
}


// TeamFortress_SetHealth__11CBasePlayer  @ 000e1070
void TeamFortress_SetHealth__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x20c);
  if (iVar1 == 1) {
    *(undefined4 *)(*param_1 + 0x1b0) = 0x42960000;
    goto LAB_000e1114;
  }
  if (iVar1 != 2) {
    if (iVar1 == 3) {
LAB_000e10ae:
      *(undefined4 *)(*param_1 + 0x1b0) = 0x42c80000;
      goto LAB_000e1114;
    }
    if ((iVar1 != 4) && (iVar1 != 5)) {
      if ((iVar1 == 6) || (iVar1 == 7)) goto LAB_000e10ae;
      if (iVar1 == 0xb) {
        *(undefined4 *)(*param_1 + 0x1b0) = 0x42480000;
        goto LAB_000e1114;
      }
      if (iVar1 != 8) {
        if (iVar1 == 9) {
          *(undefined4 *)(*param_1 + 0x1b0) = 0x42a00000;
        }
        else if (iVar1 == 0) {
          *(undefined4 *)(*param_1 + 0x1b0) = 0x3f800000;
          *(undefined4 *)(*param_1 + 0x16c) = 0;
        }
        goto LAB_000e1114;
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x1b0) = 0x42b40000;
LAB_000e1114:
  *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
  return;
}


// TeamFortress_SetSkin__11CBasePlayer  @ 000e1330
void TeamFortress_SetSkin__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (*DAT_001c11c8)(*(undefined4 *)(*param_1 + 0x208));
  param_1[99] = (int)(*gpGlobals + 10.0);
  iVar3 = *(int *)(*param_1 + 0x20c);
  if ((iVar3 == 8) && (param_1[0x76] != 0)) {
    iVar3 = param_1[0x76];
  }
  iStack_20 = param_1[0x48];
  if ((*(int *)(*param_1 + 0x20c) == 8) && (param_1[0x75] != 0)) {
    iStack_20 = param_1[0x75];
  }
  if (*(int *)(sOldClassModelFiles + iVar3 * 4) == 0) {
    (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),"models/player/scout/scout.mdl");
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  else {
    (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),"models/player/scout/scout.mdl");
    uVar2 = (*DAT_001c113c)(*(undefined4 *)(*param_1 + 0x208),uVar1,"model",
                            *(undefined4 *)(sClassModels + iVar3 * 4));
    (*DAT_001c11d4)(uVar2);
  }
  if (param_1[0x48] != 0) {
    iVar3 = iStack_20 * 0x60 + iVar3 * 8;
    uVar2 = UTIL_VarArgs__FPce(&UNK_0014bcb8,*(undefined4 *)(teamcolors + iVar3));
    uVar2 = (*DAT_001c113c)(*(undefined4 *)(*param_1 + 0x208),uVar1,"topcolor",uVar2);
    (*DAT_001c11d4)(uVar2);
    uVar2 = UTIL_VarArgs__FPce(&UNK_0014bcb8,*(undefined4 *)(teamcolors + iVar3 + 4));
    uVar1 = (*DAT_001c113c)(*(undefined4 *)(*param_1 + 0x208),uVar1,"bottomcolor",uVar2);
    (*DAT_001c11d4)(uVar1);
  }
  iVar3 = *param_1;
  if ((*(byte *)(iVar3 + 0x1a5) & 0x40) == 0) {
    uStack_14 = 0x41800000;
    uStack_10 = 0x42100000;
    puVar5 = &uStack_18;
    uStack_8 = 0xc1800000;
    uStack_4 = 0xc2100000;
    puVar4 = &uStack_c;
    iVar3 = *param_1;
  }
  else {
    uStack_8 = 0x41800000;
    uStack_4 = 0x41900000;
    puVar5 = &uStack_c;
    uStack_14 = 0xc1800000;
    uStack_10 = 0xc1900000;
    puVar4 = &uStack_18;
  }
  uStack_18 = uStack_14;
  uStack_c = uStack_8;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar3,puVar4,puVar5);
  g_ulModelIndexPlayer = *(undefined4 *)(*param_1 + 0xb4);
  return;
}


// TeamFortress_SetSpeed__11CBasePlayer  @ 000e1124
void TeamFortress_SetSpeed__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float local_8;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 0x20c);
  if (*(int *)(iVar2 + 0x244) != 0) {
    if (*(int *)(iVar2 + 0x244) == 3) {
      *(undefined4 *)(iVar2 + 0x210) = 0x43c80000;
      return;
    }
    *(undefined4 *)(*param_1 + 0x210) = 0;
    return;
  }
  if (((*(byte *)((int)param_1 + 0x86) & 1) != 0) || (iVar3 == 0)) {
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x24) = DAT_001c0fe4;
    *(undefined4 *)(iVar2 + 0x28) = DAT_001c0fe8;
    *(undefined4 *)(*param_1 + 0x210) = 0x3f800000;
    return;
  }
  if (iVar3 == 1) {
    local_8 = 400.0;
    goto LAB_000e1222;
  }
  if (iVar3 != 2) {
    if (iVar3 == 3) {
LAB_000e1206:
      local_8 = 240.0;
      goto LAB_000e1222;
    }
    if (iVar3 == 4) {
      local_8 = 280.0;
      goto LAB_000e1222;
    }
    if (iVar3 == 5) {
      local_8 = 320.0;
      goto LAB_000e1222;
    }
    if (iVar3 == 6) {
      local_8 = 230.0;
      goto LAB_000e1222;
    }
    if (iVar3 != 7) {
      if (iVar3 == 0xb) goto LAB_000e1206;
      if ((iVar3 != 8) && (iVar3 != 9)) goto LAB_000e1222;
    }
  }
  local_8 = 300.0;
LAB_000e1222:
  piVar4 = (int *)0x0;
LAB_000e1283:
  do {
    piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"item_tfgoal");
    if (piVar4 == (int *)0x0) {
      if ((short)param_1[0x21] < 0) {
        local_8 = local_8 * 0.5;
      }
      fVar1 = (float)param_1[0x68];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        if (6.0 < fVar1) {
          param_1[0x68] = 0x40c00000;
        }
        local_8 = (10.0 - (float)param_1[0x68]) * local_8 * 0.1;
      }
      if (((*(byte *)((int)param_1 + 0x85) & 8) != 0) && (80.0 < local_8)) {
        local_8 = 80.0;
      }
      *(float *)(*param_1 + 0x210) = local_8;
      return;
    }
  } while (*(int *)(*piVar4 + 0x198) != *(int *)(*param_1 + 0x208));
  if ((*(byte *)(piVar4 + 0x8a) & 2) == 0) goto LAB_000e1254;
  fVar1 = 0.5;
  goto LAB_000e1273;
LAB_000e1254:
  if (piVar4[0xcb] != 0) {
    fVar1 = (float)piVar4[0xcb] * 0.01;
LAB_000e1273:
    local_8 = fVar1 * local_8;
  }
  goto LAB_000e1283;
}


// TeamFortress_SetupRespawn__11CBasePlayeri  @ 000e284c
void TeamFortress_SetupRespawn__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float local_10;
  
  if ((float)param_1[0x4c] <= *gpGlobals) {
    local_10 = (float)tfc_respawndelay._12_4_;
    param_1[0x212] = 0;
    param_1[0x213] = 0;
    *(undefined1 *)(param_1 + 0x195) = 0;
    fVar1 = *gpGlobals + 1.0;
    if (0x3f < (byte)((fVar1 < cb_prematch_time |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) - 1)) {
      if (param_2 != 0) {
        if (0 < (int)param_1[0x49]) {
          param_1[0x49] = param_1[0x49] + -1;
        }
        local_10 = (float)param_1[0x1bb] - *gpGlobals;
      }
      if (0 < (int)param_1[0x49]) {
        param_1[0x49] = param_1[0x49] + -1;
      }
      if (param_1[0x49] != -1) {
        if (param_1[0x49] == 0) {
          ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Game_nolives",0,0,0,0);
          StartDeathCam__11CBasePlayer(param_1);
          return;
        }
        if (param_1[0x49] == 1) {
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = 0;
          uVar4 = 0;
          pcVar3 = "#Game_lastlife";
          uVar2 = 4;
        }
        else {
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = 0;
          uVar4 = UTIL_dtos1__Fi(param_1[0x49],0,0,0);
          pcVar3 = "#Game_Xlives";
          uVar2 = 1;
        }
        ClientPrint__FP9entvars_siPCcN42(*param_1,uVar2,pcVar3,uVar4,uVar5,uVar6,uVar7);
      }
    }
    param_1[0x4c] = local_10 + *gpGlobals;
    if (3.0 < local_10) {
      uVar4 = UTIL_dtos1__Fi((int)ROUND(local_10),0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_tillrespawn",uVar4);
    }
  }
  return;
}


// TeamFortress_SortTeams__Fv  @ 00110b3c
int TeamFortress_SortTeams__Fv(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_14 [5];
  
  local_18 = 0;
  local_1c = 0;
  local_24 = 1;
  g_iOrderedTeams = 0;
  DAT_001cddd8 = 0;
  DAT_001cdddc = 0;
  DAT_001cdde0 = 0;
  DAT_001cdde4 = 0;
  local_28 = 1;
  if (1.0 <= number_of_teams) {
    iVar5 = 4;
    do {
      iVar2 = local_18;
      iVar4 = 0;
      iVar3 = 1;
      if (1.0 <= number_of_teams) {
        do {
          if ((iVar4 <= *(int *)(teamscores + iVar3 * 4)) && (local_14[iVar3] == 0)) {
            iVar4 = *(int *)(teamscores + iVar3 * 4);
            local_18 = iVar3;
          }
          iVar3 = iVar3 + 1;
          fVar1 = (float)iVar3;
        } while ((byte)((fVar1 < number_of_teams |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) <
                 0x40);
      }
      if ((((1 < local_28) && (local_24 == 1)) &&
          ((((byte)(*(int *)((int)&teamallies + iVar5) >> ((char)iVar2 - 1U & 0x1f)) ^ 1) & 1) != 0)
          ) && (iVar4 != local_1c)) {
        local_24 = 0;
      }
      local_14[local_18] = 1;
      *(int *)((int)&g_iOrderedTeams + iVar5) = local_18;
      iVar5 = iVar5 + 4;
      local_28 = local_28 + 1;
      fVar1 = (float)local_28;
      local_1c = iVar4;
    } while ((byte)((fVar1 < number_of_teams |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40);
  }
  return local_24;
}


// TeamFortress_SpyCalcName__11CBasePlayer  @ 000f1ce8
void TeamFortress_SpyCalcName__11CBasePlayer(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x1dc);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x1dc,0);
  if (*(int *)(param_1 + 0x1d4) != 0) {
    for (iVar3 = 1; iVar3 <= *(int *)(gpGlobals + 0x90); iVar3 = iVar3 + 1) {
      piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
      if ((((piVar2 != (int *)0x0) && (piVar2 != piVar1)) &&
          (piVar2[0x48] == *(int *)(param_1 + 0x1d4))) &&
         (*(int *)(*piVar2 + 0x20c) == *(int *)(param_1 + 0x1d8))) goto LAB_000f1d95;
    }
    for (iVar3 = 1; iVar3 <= *(int *)(gpGlobals + 0x90); iVar3 = iVar3 + 1) {
      piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
      if ((piVar2 != (int *)0x0) && (piVar2[0x48] == *(int *)(param_1 + 0x1d4))) {
LAB_000f1d95:
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x1dc,piVar2);
        return;
      }
    }
  }
  return;
}


// TeamFortress_SpyChangeColor__11CBasePlayeri  @ 000f1f54
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_SpyChangeColor__11CBasePlayeri(int *param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 == param_1[0x48]) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_resetteam",0,0,0,0);
    param_1[0x75] = 0;
    if (param_1[0x76] == 0) {
      param_1[0x19] = 0;
    }
    TeamFortress_SetSkin__11CBasePlayer(param_1);
  }
  else if ((param_1[0x35b] == 0) && (param_2 != param_1[0x75])) {
    if (((*(byte *)(*param_1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_start",0,0,0,0);
      param_1[0x19] = 2;
      piVar1 = (int *)CreateTimer__11CBaseEntityi(param_1,0xd);
      piVar1[3] = -0x10000;
      piVar1[4] = (int)Timer_SpyUndercoverThink__11CBaseEntity;
      *(float *)(*piVar1 + 0x104) = _FUN_0014de94 + *gpGlobals;
      piVar1[0x48] = param_2;
    }
    else {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spy_unable",0,0,0,0);
    }
  }
  return;
}


// TeamFortress_SpyChangeSkin__11CBasePlayeri  @ 000f1dc0
void TeamFortress_SpyChangeSkin__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_4;
  
  local_4 = 4;
  iVar1 = param_1[0x35b];
  if (iVar1 != 0) {
    if ((iVar1 != param_1[0x75]) && (iVar1 != param_1[0x48])) {
      local_4 = 8;
    }
    if ((param_2 == 8) || (param_2 == param_1[0x76])) {
      param_1[0x35b] = 0;
    }
    TeamFortress_SpyChangeColor__11CBasePlayeri(param_1,iVar1);
    param_1[0x35b] = 0;
  }
  if ((param_2 == 8) && (iVar1 == param_1[0x48])) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_resetclass",0,0,0,0);
    param_1[0x76] = 0;
    param_1[0x75] = 0;
    param_1[0x19] = 0;
    Spy_ResetExternalWeaponModel__11CBasePlayer(param_1);
    TeamFortress_SetSkin__11CBasePlayer(param_1);
  }
  else if (param_2 != param_1[0x76]) {
    if (((*(byte *)(*param_1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_start",0,0,0,0);
      param_1[0x19] = 2;
      iVar2 = FindTimer__11CBaseEntityi(param_1,0xd);
      if (iVar2 != 0) {
        UTIL_Remove__FP11CBaseEntity(iVar2);
      }
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_1,0xd);
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_SpyUndercoverThink__11CBaseEntity;
      *(float *)(*piVar3 + 0x104) = (float)local_4 + *gpGlobals;
      *(int *)(*piVar3 + 0x110) = param_2;
      piVar3[0x48] = iVar1;
      TeamFortress_SetSkin__11CBasePlayer(param_1);
    }
    else {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spy_unable",0,0,0,0);
    }
  }
  return;
}


// TeamFortress_SpyDisguiseEnemy__11CBasePlayerii  @ 000f2064
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
        iVar1 = (*DAT_001c1188)(1,(int)ROUND(number_of_teams));
      } while (iVar1 == *(int *)(param_1 + 0x120));
    }
  }
  TeamFortress_SpyDisguise__11CBasePlayerii(param_1,iVar1,param_3);
  return;
}


// TeamFortress_SpyDisguise__11CBasePlayerii  @ 000f2104
void TeamFortress_SpyDisguise__11CBasePlayerii(int *param_1,int param_2,int param_3)

{
  if ((((float)param_2 <= number_of_teams) && (0 < param_2)) && (param_3 - 1U < 9)) {
    if (((*(byte *)(*param_1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
      param_1[0x35b] = param_2;
      if (param_3 - 1U < 9) {
        TeamFortress_SpyChangeSkin__11CBasePlayeri(param_1,param_3);
      }
      else {
        param_1[0x44] = 0x41500000;
      }
    }
    else {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spy_unable",0,0,0,0);
    }
  }
  return;
}


// TeamFortress_SpyFeignDeath__11CBasePlayeri  @ 000f12c4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_SpyFeignDeath__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  char *pcVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 local_74;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined1 local_50 [4];
  int local_4c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  fVar1 = (float)param_1[0x192];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  param_1[0x192] = 0x3f000000;
  if (param_1[0x1c] == 0) {
    if (param_1[0x1d] == 1) {
      pcVar5 = "#Feign_unable";
    }
    else {
      iVar2 = *param_1;
      if (((*(byte *)(iVar2 + 0x1a5) & 2) == 0) && (*(int *)(iVar2 + 0x1c0) == 0)) {
        pcVar5 = "#Feign_air";
        goto LAB_000f1603;
      }
      iVar2 = CanFeign__11CBasePlayer(param_1);
      if (iVar2 == 0) {
        pcVar5 = "#Feign_onspy";
      }
      else {
        iVar2 = *param_1;
        if ((*(byte *)(iVar2 + 0x1a5) & 0x40) == 0) {
LAB_000f16a2:
          param_1[0x27b] = 0;
          SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
          param_1[99] = (int)(*gpGlobals + 5.0);
          *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
          TeamFortress_SetSpeed__11CBasePlayer(param_1);
          *(undefined4 *)(*param_1 + 0x170) = 5;
          param_1[0x1c] = 1;
          param_1[0x108] = 0;
          TeamFortress_SetSkin__11CBasePlayer(param_1);
          if (param_1[0x22d] != 0) {
            (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x128))(param_1[0x22d],0);
            *(undefined4 *)(*param_1 + 0xbc) = 0;
            *(undefined4 *)(*param_1 + 0xc0) = 0;
          }
          local_74 = 0x41800000;
          local_6c = -32.0;
          local_68 = 0xc1800000;
          local_60 = 0xc2100000;
          local_70 = local_74;
          local_64 = local_68;
          UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_68,&local_74);
          iVar2 = *param_1;
          local_6c = 4.0;
          local_74 = 0;
          local_70 = 0;
          *(undefined4 *)(iVar2 + 0x174) = 0;
          *(undefined4 *)(iVar2 + 0x178) = 0;
          *(undefined4 *)(iVar2 + 0x17c) = 0x40800000;
          *(undefined4 *)(*param_1 + 0x108) = 6;
          *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
          fVar1 = *(float *)(*param_1 + 0x28);
          if (0x3f < (byte)((10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1)) {
            lVar4 = (longdouble)(*DAT_001c118c)(0,0x43960000);
            *(float *)(*param_1 + 0x28) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x28));
          }
          if (param_2 == 0) {
            (**(code **)(param_1[0x111] + 0x208))(param_1);
          }
          *(undefined4 *)(*param_1 + 0x50) = 0;
          *(undefined4 *)(*param_1 + 0x58) = 0;
          piVar7 = (int *)0x0;
LAB_000f1a2b:
          do {
            do {
              piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"item_tfgoal");
              if (piVar7 == (int *)0x0) {
                *(undefined4 *)(*param_1 + 0x24c) = 1;
                return;
              }
            } while (*(int *)(*piVar7 + 0x198) != *(int *)(*param_1 + 0x208));
            if (((*(byte *)((int)piVar7 + 0x229) & 1) == 0) || (param_1[0x1e] == 1)) {
              tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar7,param_1,0);
            }
          } while (CTF_Map != 1);
          if (piVar7[0x84] != 1) goto code_r0x000f195b;
          uVar3 = UTIL_VarArgs__FPce("%s LOST the BLUE flag!\n",
                                     *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar3);
          if (param_1[0x48] == 0) {
            pcVar5 = "SPECTATOR";
          }
          else {
            pcVar5 = (char *)GetTeamName__Fi(param_1[0x48]);
          }
          uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar5);
          uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar3);
          iVar2 = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
          pcVar5 = "\"%s<%i><%u><%s>\" triggered \"Dropped_Blue_Flag\"\n";
          goto LAB_000f1a1a;
        }
        local_18 = *(undefined4 *)(iVar2 + 8);
        local_14 = *(undefined4 *)(iVar2 + 0xc);
        local_10 = *(float *)(iVar2 + 0x10);
        if ((*(byte *)(iVar2 + 0x1a5) & 2) != 0) {
          local_74 = 0xc1800000;
          local_60 = 0xc1900000;
          local_6c = -36.0;
          local_54 = _FUN_0014dd14;
          local_5c = 0;
          local_58 = 0;
          local_10 = local_10 + _FUN_0014dd14;
          local_70 = local_74;
          local_68 = local_74;
          local_64 = local_74;
          local_c = local_18;
          local_8 = local_14;
          local_4 = local_10;
        }
        UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                  (&local_18,&local_18,0,1,*(undefined4 *)(*param_1 + 0x208),local_50);
        if (local_4c == 0) {
          iVar2 = *param_1;
          if ((*(byte *)(iVar2 + 0x1a5) & 2) != 0) {
            local_68 = 0xc1800000;
            local_60 = 0xc1900000;
            local_54 = -36.0;
            local_6c = _FUN_0014dd14;
            local_74 = 0;
            local_70 = 0;
            local_c = *(undefined4 *)(iVar2 + 8);
            local_8 = *(undefined4 *)(iVar2 + 0xc);
            local_4 = *(float *)(iVar2 + 0x10) + _FUN_0014dd14;
            *(undefined4 *)(iVar2 + 8) = local_c;
            *(undefined4 *)(iVar2 + 0xc) = local_8;
            *(float *)(iVar2 + 0x10) = local_4;
            local_64 = local_68;
            local_5c = local_68;
            local_58 = local_68;
          }
          goto LAB_000f16a2;
        }
        pcVar5 = "#Feign_noroom";
      }
    }
  }
  else {
    iVar2 = CanFeign__11CBasePlayer(param_1);
    if (iVar2 != 0) {
      param_1[0x1c] = 0;
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar2 + 0x24) = DAT_001c0fe4;
      *(undefined4 *)(iVar2 + 0x28) = DAT_001c0fe8;
      iVar2 = *param_1;
      if ((*(byte *)(iVar2 + 0x1a5) & 0x40) == 0) {
        local_14 = 0x41800000;
        local_10 = 36.0;
        puVar8 = &local_18;
        local_8 = 0xc1800000;
        local_4 = -36.0;
        puVar6 = &local_c;
        iVar2 = *param_1;
      }
      else {
        local_8 = 0x41800000;
        local_4 = _FUN_0014dd14;
        puVar8 = &local_c;
        local_14 = 0xc1800000;
        local_10 = -18.0;
        puVar6 = &local_18;
      }
      local_18 = local_14;
      local_c = local_8;
      UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,puVar6,puVar8);
      iVar2 = *param_1;
      local_10 = 28.0;
      local_18 = 0;
      local_14 = 0;
      *(undefined4 *)(iVar2 + 0x174) = 0;
      *(undefined4 *)(iVar2 + 0x178) = 0;
      *(undefined4 *)(iVar2 + 0x17c) = 0x41e00000;
      *(undefined4 *)(*param_1 + 0x108) = 3;
      *(undefined4 *)(*param_1 + 0x170) = 0;
      *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
      *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      if (param_1[0x22d] != 0) {
        (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x120))(param_1[0x22d]);
      }
      *(undefined4 *)(*param_1 + 0x138) = 0xbf800000;
      param_1[0x27b] = 0;
      SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
      *(undefined4 *)(*param_1 + 0x24c) = 0;
      return;
    }
    pcVar5 = "#Feign_unabletogetup";
  }
  iVar2 = *param_1;
LAB_000f1603:
  ClientPrint__FP9entvars_siPCcN42(iVar2,4,pcVar5,0,0,0,0);
  return;
code_r0x000f195b:
  if (piVar7[0x84] == 2) {
    uVar3 = UTIL_VarArgs__FPce("%s LOST the RED flag!\n",
                               *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
    UTIL_ClientPrintAll__FiPCcN41(1,uVar3);
    if (param_1[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_1[0x48]);
    }
    uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar5);
    uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar3);
    iVar2 = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    pcVar5 = "\"%s<%i><%u><%s>\" triggered \"Dropped_Red_Flag\"\n";
LAB_000f1a1a:
    UTIL_LogPrintf__FPce(pcVar5,iVar2,uVar3);
  }
  goto LAB_000f1a2b;
}


// TeamFortress_SpyGoUndercover__11CBasePlayer  @ 000f1c54
void TeamFortress_SpyGoUndercover__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  if (((*(byte *)(*param_1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
    if (param_1[0x19] == 2) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_stop",0,0,0,0);
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
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spy_unable",0,0,0,0);
  }
  return;
}


// TeamFortress_StatusQuery__Fv  @ 00110a7c
void TeamFortress_StatusQuery__Fv(void)

{
  undefined4 uVar1;
  
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi();
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(3,uVar1);
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(2,uVar1);
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(1,uVar1);
  (*DAT_001c1114)(1,"players per team: %d %d %d %d\n",uVar1);
  (*DAT_001c1114)(1,"    equalisation: %0.1f %0.1f %0.1f %0.1f\n",(double)(float)teamadvantage._4_4_
                  ,(double)(float)teamadvantage._8_4_,(double)(float)teamadvantage._12_4_,
                  (double)(float)teamadvantage._16_4_);
  (*DAT_001c1114)(1,"Teamplay is %d\n",(double)*(float *)(gpGlobals + 0x1c));
  return;
}


// TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_sf  @ 0008f83c
void TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_sf(void)

{
  return;
}


// TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_sf  @ 000e3d78
void TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_sf
               (int *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
  if (iVar3 == 0) {
    return;
  }
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x20c) != 0) {
    local_c = *(float *)(iVar3 + 8) - *(float *)(param_2 + 8);
    local_8 = *(float *)(iVar3 + 0xc) - *(float *)(param_2 + 0xc);
    local_4 = *(float *)(iVar3 + 0x10) - *(float *)(param_2 + 0x10);
    iVar3 = *(int *)(param_2 + 0x208);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar3 + 0x7c);
    }
    fVar2 = (param_3 - SQRT(local_4 * local_4 + local_8 * local_8 + local_c * local_c) * 0.5) * 0.03
    ;
    fVar1 = SQRT(local_4 * local_4 + local_8 * local_8 + local_c * local_c);
    if (0x3f < (byte)((16.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 16.0) << 0xe) >> 8)) - 1)) {
      iVar3 = *param_1;
      local_c = *(float *)(iVar3 + 0x20) * 0.33;
      local_8 = *(float *)(iVar3 + 0x24) * 0.33;
      local_4 = *(float *)(iVar3 + 0x28) * 0.33;
    }
    iVar3 = *param_1;
    *(float *)(iVar3 + 0x20) = local_c;
    *(float *)(iVar3 + 0x24) = local_8;
    *(float *)(iVar3 + 0x28) = local_4;
    *(float *)(*param_1 + 0x20) = fVar2 * *(float *)(*param_1 + 0x20);
    *(float *)(*param_1 + 0x24) = fVar2 * *(float *)(*param_1 + 0x24);
    *(float *)(*param_1 + 0x28) = fVar2 * *(float *)(*param_1 + 0x28) * 1.5;
    if ((((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) && (0 < param_1[0x48])) &&
        (iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,uVar5), iVar3 != 0)) &&
       (*(int *)(param_2 + 0x198) != *(int *)(*param_1 + 0x208))) {
      return;
    }
    (*DAT_001c10d8)(1,gmsgDamage,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)(0);
    (*DAT_001c10e0)(0);
    (*DAT_001c10ec)(0x200);
    (*DAT_001c10f4)(*(undefined4 *)(param_2 + 8));
    (*DAT_001c10f4)(*(undefined4 *)(param_2 + 0xc));
    (*DAT_001c10f4)(*(undefined4 *)(param_2 + 0x10));
    (*DAT_001c10dc)();
    (**(code **)(param_1[0x111] + 0x104))(param_1,param_2);
    iVar3 = *(int *)(param_2 + 0x198);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
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
    uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar4);
    uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar5);
    if (piVar6[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(piVar6[0x48],
                                       *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar5
                                      );
    }
    uVar5 = (*DAT_001c11f4)(*(undefined4 *)(param_2 + 0x198),pcVar4);
    uVar5 = (*DAT_001c11e4)(*(undefined4 *)(param_2 + 0x198),uVar5);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%u><%s>\" triggered \"Concussion_Grenade\" against \"%s<%i><%u><%s>\"\n",
               *(int *)(*piVar6 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar5);
    return;
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_s  @ 00101fac
void TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_s(int *param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"tf_gl_pipebomb");
  if (iVar1 == 0) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_s  @ 00121be0
void TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_s(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_8;
  undefined4 local_4;
  
  if (*(int *)(param_2 + 0x198) == 0) {
    (*DAT_001c1134)(0);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001c1134)(0);
  }
  (**(code **)(param_1[0x111] + 0xf4))(param_1,&local_8,&local_4);
  if (0x3f < (byte)((local_8 < 0.0 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_8 == 0.0) << 0xe) >> 8)) - 1)) {
    (**(code **)(param_1[0x111] + 0xf0))(param_1,param_2,local_8,local_4);
    fVar1 = (float)param_1[0x119];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      iVar2 = *(int *)(*param_1 + 400);
      if ((iVar2 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      if ((iVar2 != 0) && (iVar3 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x2c))(iVar2), iVar3 == 2)
         ) {
        *(int *)(iVar2 + 0xd98) = *(int *)(iVar2 + 0xd98) + -1;
      }
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_s  @ 0008f838
void TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_s(void)

{
  return;
}


// TeamFortress_TakeEMPBlast__11CBasePlayerP9entvars_s  @ 000e3b70
void TeamFortress_TakeEMPBlast__11CBasePlayerP9entvars_s(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  ushort in_FPUControlWord;
  float local_18;
  undefined4 local_14;
  ushort local_10;
  undefined4 local_c;
  ushort local_4;
  undefined2 uStack_2;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001c1134)(0);
  }
  if ((*(int *)(*param_1 + 0x20c) != 0) &&
     (((local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord)),
       ((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) == 0 ||
       (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar2), iVar1 == 0)) ||
      (piVar2 == param_1)))) {
    (**(code **)(param_1[0x111] + 0xf4))(param_1,&local_18,&local_14);
    param_1[0x33] = (int)ROUND((double)param_1[0x33] - ROUND((double)param_1[0x33] * 0.25));
    param_1[0x39] = (int)ROUND((double)param_1[0x39] - ROUND((double)param_1[0x39] * 0.25));
    if (*(int *)(*param_1 + 0x20c) != 9) {
      param_1[0x37] = (int)ROUND((double)param_1[0x37] - ROUND((double)param_1[0x37] * 0.25));
    }
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    local_10 = in_FPUControlWord & 0xf3ff | 0x800;
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    if (0.0 < local_18) {
      (**(code **)(param_1[0x111] + 0xf0))(param_1,param_2,local_18,local_14);
    }
  }
  return;
}


// TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_s  @ 0009d26c
void TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001c1134)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar2), iVar1 != 0)) &&
     (puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar2 != puVar3)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x444) + 0x38))(param_1,param_2,*puVar2,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_s  @ 000ebb28
void TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001c1134)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar2), iVar1 != 0)) &&
     (puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar2 != puVar3)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x444) + 0x38))(param_1,param_2,*puVar2,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__8CDetpackP9entvars_s  @ 0009a818
void TeamFortress_TakeEMPBlast__8CDetpackP9entvars_s(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_001c118c)(0,0x40000000);
  *(float *)(*param_1 + 0x160) = (float)((longdouble)1.0 + (longdouble)*gpGlobals + lVar1);
  return;
}


// TeamFortress_TeamGetNoPlayers__Fi  @ 00110130
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


// TeamFortress_TeamGetScoreFrags__Fi  @ 0011010c
undefined4 TeamFortress_TeamGetScoreFrags__Fi(int param_1)

{
  return *(undefined4 *)(teamscores + param_1 * 4);
}


// TeamFortress_TeamIncreaseScore__Fii  @ 00110068
void TeamFortress_TeamIncreaseScore__Fii(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    *(int *)(teamscores + param_1 * 4) = *(int *)(teamscores + param_1 * 4) + param_2;
    (*DAT_001c10d8)(2,gmsgTeamScore,0,0);
    uVar1 = GetTeamName__Fi(param_1);
    (*DAT_001c10f8)(uVar1);
    (*DAT_001c10e8)(*(undefined4 *)(teamscores + param_1 * 4));
    (*DAT_001c10e8)(0);
    (*DAT_001c10dc)();
  }
  return;
}


// TeamFortress_TeamIsCivilian__Ff  @ 00110344
undefined4 TeamFortress_TeamIsCivilian__Ff(float param_1)

{
  byte bVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == 1.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = (byte)civilianteams & 1;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_1 == 2.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = (byte)civilianteams & 2;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_1 == 3.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = (byte)civilianteams & 4;
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
    bVar1 = (byte)civilianteams & 8;
  }
  if (bVar1 != 0) {
    return 1;
  }
  return 0;
}


// TeamFortress_TeamPutPlayerInTeam__11CBasePlayer  @ 000e19c8
void TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float local_18;
  
  iVar2 = 1;
  lVar4 = (longdouble)(*DAT_001c118c)(0,number_of_teams);
  local_18 = (float)ROUND(lVar4);
  if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_18 = number_of_teams;
  }
  iVar3 = 0x21;
  while( true ) {
    if (number_of_teams + 1.0 <= (float)iVar2) break;
    iVar1 = TeamFortress_TeamGetNoPlayers__Fi(iVar2);
    if (iVar2 == *(int *)(*param_1 + 0x1ac)) {
      iVar1 = iVar1 + -1;
    }
    if ((iVar1 < iVar3) && (iVar1 < *(int *)(teammaxplayers + iVar2 * 4))) {
      local_18 = (float)iVar2;
      iVar3 = iVar1;
    }
    iVar2 = iVar2 + 1;
  }
  TeamFortress_TeamSet__11CBasePlayeri(param_1,(int)ROUND(local_18));
  return;
}


// TeamFortress_TeamSetColor__Fi  @ 0010fbb4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  _DAT_001cdb84 = 0x437f0000;
  _DAT_001cdb88 = 0x437f0000;
  _DAT_001cdb8c = 0;
  uRam001cdb90 = 0;
  uRam001cdb94 = 0x437f0000;
  _DAT_001cdb98 = 0x437f0000;
  uRam001cdb9c = 0;
  uRam001cdba0 = 0;
  _DAT_001cdba4 = 0x437f0000;
  uRam001cdba8 = 0x437f0000;
  uRam001cdbac = 0x41f00000;
  _DAT_001cdbb0 = 0;
  uRam001cdbb4 = 0x437f0000;
  uRam001cdbb8 = 0;
  return;
}


// TeamFortress_TeamSet__11CBasePlayeri  @ 000e1ae4
void TeamFortress_TeamSet__11CBasePlayeri(void)

{
  FUN_000e1af0();
  return;
}


// TeamFortress_TeamShowMemberClasses__11CBasePlayer  @ 000e2010
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
          ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_others",0,0,0,0);
        }
        uVar4 = UTIL_VarArgs__FPce(&DAT_0014ba48,(&sClassNames)[*(int *)(*piVar2 + 0x20c)],0,0);
        ClientPrint__FP9entvars_siPCcN42
                  (*param_1,1,"#Game_othersdetails",
                   *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
      }
    }
  }
  if (!bVar1) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_noothers",0,0,0,0);
  }
  return;
}


// TeamFortress_TeamShowScores__FiP11CBasePlayer  @ 0010faa4
void TeamFortress_TeamShowScores__FiP11CBasePlayer(void)

{
  FUN_0010faad();
  return;
}


// TeamFortress_ThrowPrimedGrenade__11CBasePlayer  @ 000e4198
void TeamFortress_ThrowPrimedGrenade__11CBasePlayer(int param_1)

{
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    *(byte *)(param_1 + 0x85) = *(byte *)(param_1 + 0x85) | 4;
  }
  return;
}


// TeamFortress_UpdateStatusBar__11CBasePlayer  @ 000fb3d8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_UpdateStatusBar__11CBasePlayer(int *param_1)

{
  undefined1 *puVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  bool bVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  ushort *puVar13;
  char *pcVar14;
  int *piVar15;
  bool bVar16;
  ushort in_FPUControlWord;
  int *unaff_retaddr;
  float local_180;
  float local_17c;
  float local_178;
  float local_174;
  float local_170;
  float local_16c;
  float local_168 [4];
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  int local_138;
  int local_130;
  int local_12c;
  ushort local_128;
  undefined2 uStack_126;
  float local_124;
  ushort local_120 [2];
  char local_11c [124];
  char local_a0 [4];
  undefined4 local_9c;
  char local_98 [124];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  memset(&local_1c,0,0x1c);
  local_9c = local_9c & 0xffffff00;
  strcpy(local_11c,(char *)(param_1 + 0x328));
  if (cb_prematch_time <= *gpGlobals) {
    fVar2 = (float)param_1[0x4c];
    fVar3 = *gpGlobals;
    if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
      iVar9 = *param_1;
      local_170 = *(float *)(iVar9 + 0x74) + *(float *)(iVar9 + 0x68);
      local_16c = *(float *)(iVar9 + 0x78) + *(float *)(iVar9 + 0x6c);
      local_168[0] = *(float *)(iVar9 + 0x7c) + *(float *)(iVar9 + 0x70);
      UTIL_MakeVectors__FRC6Vector();
      (**(code **)(param_1[0x111] + 0xd0))(&local_170,param_1);
      local_180 = local_174 + gpGlobals[10] * 2048.0;
      local_17c = local_170 + gpGlobals[0xb] * 2048.0;
      local_178 = local_16c + gpGlobals[0xc] * 2048.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_170,&local_180,0,*(undefined4 *)(*unaff_retaddr + 0x208),local_168);
      if ((byte)(1.0 < local_158 | (byte)((ushort)((ushort)NAN(local_158) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_158 == 1.0) << 0xe) >> 8)) != 0x40) {
        bVar16 = false;
        if ((local_138 == 0) || (iVar9 = (*DAT_001c1138)(local_138), iVar9 == 0)) {
          bVar16 = true;
        }
        if (bVar16) {
          fVar2 = (float)unaff_retaddr[0x372];
          fVar3 = *gpGlobals;
          if (0x3f < (byte)((fVar2 < fVar3 |
                             (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
            local_1c = unaff_retaddr[0x36c];
            local_18 = unaff_retaddr[0x36d];
            local_14 = unaff_retaddr[0x36e];
          }
        }
        else {
          if ((local_138 == 0) && (local_138 = (*DAT_001c1134)(0), local_138 == 0)) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = *(int **)(local_138 + 0x7c);
          }
          bVar16 = false;
          iVar9 = (**(code **)(piVar6[0x111] + 0x2c))(piVar6);
          if (iVar9 == 2) {
            if (((piVar6[0x1c] == 0) ||
                (iVar9 = IsAlly__11CBaseEntityP11CBaseEntity(unaff_retaddr,piVar6), iVar9 != 0)) ||
               (*(int *)(*unaff_retaddr + 0x244) != 0)) {
              bVar5 = false;
              iVar9 = IsAlly__11CBaseEntityP11CBaseEntity(unaff_retaddr,piVar6);
              if (((iVar9 != 0) ||
                  (local_124 = SQRT((local_16c - local_14c) * (local_16c - local_14c) +
                                    (local_170 - local_150) * (local_170 - local_150) +
                                    (local_174 - local_154) * (local_174 - local_154)),
                  local_124 <= 1024.0)) || (*(int *)(*unaff_retaddr + 0x244) != 0)) {
                bVar5 = true;
              }
              if (bVar5) {
                if ((*(int *)(*unaff_retaddr + 0x244) == 0) && (unaff_retaddr[0x48] != 0)) {
                  iVar9 = __opP11CBaseEntity__7EHANDLE(piVar6 + 0x77);
                  if ((iVar9 != 0) &&
                     ((unaff_retaddr[0x48] != piVar6[0x48] && (*(int *)(*piVar6 + 0x20c) == 8)))) {
                    piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(piVar6 + 0x77);
                  }
                }
                if (((byte)(2.0 < (float)tfc_playerid._12_4_ |
                            (byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                           (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 2.0) << 0xe) >> 8)
                           ) == 0x40) ||
                   ((((byte)((byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                            (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 1.0) << 0xe) >> 8
                                  )) == 0x40 &&
                     (iVar9 = IsAlly__11CBaseEntityP11CBaseEntity(unaff_retaddr,piVar6), iVar9 == 0)
                     ) && (*(int *)(*unaff_retaddr + 0x244) == 0)))) {
                  local_120[0] = 0x20;
                }
                else {
                  pcVar7 = "1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
                  puVar11 = local_120;
                  for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *(undefined4 *)puVar11 = *(undefined4 *)pcVar7;
                    pcVar7 = pcVar7 + 4;
                    puVar11 = puVar11 + 2;
                  }
                  *(char *)puVar11 = *pcVar7;
                }
                local_1c = (*DAT_001c113c)(*(undefined4 *)(*piVar6 + 0x208));
                bVar16 = true;
                __as__7EHANDLEP11CBaseEntity(unaff_retaddr + 0x373,piVar6);
              }
            }
LAB_000fbc5a:
            if (!bVar16) goto LAB_000fbd9c;
          }
          else {
            iVar9 = strcmp((char *)(*(int *)*piVar6 + (int)gpGlobals[0x26]),"building_sentrygun");
            if (iVar9 != 0) {
              iVar9 = strcmp((char *)(*(int *)*piVar6 + (int)gpGlobals[0x26]),"building_dispenser");
              if (iVar9 == 0) {
                piVar15 = (int *)__rf__7EHANDLE(piVar6 + 0x51);
                local_1c = (*DAT_001c113c)(*(undefined4 *)(*piVar15 + 0x208));
                if (((byte)(2.0 < (float)tfc_playerid._12_4_ |
                            (byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                           (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 2.0) << 0xe) >> 8)
                           ) == 0x40) ||
                   ((((byte)((byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                            (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 1.0) << 0xe) >> 8
                                  )) == 0x40 && (*(int *)(*unaff_retaddr + 0x244) == 0)) &&
                    (iVar9 = IsAlly__11CBaseEntityP11CBaseEntity(unaff_retaddr,piVar6), iVar9 == 0))
                   )) {
                  local_120[0] = 0x20;
                }
                else {
                  pcVar7 = "1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
                  puVar11 = local_120;
                  for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *(undefined4 *)puVar11 = *(undefined4 *)pcVar7;
                    pcVar7 = pcVar7 + 4;
                    puVar11 = puVar11 + 2;
                  }
                  *(char *)puVar11 = *pcVar7;
                }
                bVar16 = true;
              }
              goto LAB_000fbc5a;
            }
            piVar15 = (int *)__rf__7EHANDLE(piVar6 + 0x51);
            local_1c = (*DAT_001c113c)(*(undefined4 *)(*piVar15 + 0x208));
            if (((byte)(2.0 < (float)tfc_playerid._12_4_ |
                        (byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                       (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 2.0) << 0xe) >> 8)) ==
                 0x40) ||
               ((((byte)((byte)((ushort)((ushort)NAN((float)tfc_playerid._12_4_) << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)tfc_playerid._12_4_ == 1.0) << 0xe) >> 8))
                  == 0x40 && (*(int *)(*unaff_retaddr + 0x244) == 0)) &&
                (iVar9 = IsAlly__11CBaseEntityP11CBaseEntity(unaff_retaddr,piVar6), iVar9 == 0)))) {
              local_120[0] = 0x20;
            }
            else {
              puVar11 = (ushort *)"1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
              puVar13 = local_120;
              for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {
                *(undefined4 *)puVar13 = *(undefined4 *)puVar11;
                puVar11 = puVar11 + 2;
                puVar13 = puVar13 + 2;
              }
              *puVar13 = *puVar11;
            }
          }
          iVar9 = IsAlly__11CBaseEntityP11CBaseEntity(unaff_retaddr,piVar6);
          if (((iVar9 != 0) || (*(int *)(*unaff_retaddr + 0x20c) == 5)) ||
             (*(int *)(*unaff_retaddr + 0x244) != 0)) {
            local_18 = (int)ROUND((*(float *)(*piVar6 + 0x160) / *(float *)(*piVar6 + 0x1b0)) *
                                  100.0);
            _local_128 = CONCAT22(uStack_126,in_FPUControlWord);
            local_130 = CONCAT22(uStack_126,CONCAT11(0xc,(char)in_FPUControlWord));
            local_14 = (int)ROUND((*(float *)(*piVar6 + 0x1bc) / (float)piVar6[0x3c]) * 100.0);
          }
          unaff_retaddr[0x372] = (int)(*gpGlobals + 1.0);
        }
LAB_000fbd9c:
        if ((local_1c < 0) || ((int)gpGlobals[0x24] < local_1c)) {
          printf("ERROR: SBAR_ID_TARGETNAME = %d\n",local_1c);
          local_1c = 0;
        }
      }
      if (*(int *)(*unaff_retaddr + 0x20c) == 8) {
        if (unaff_retaddr[0x19] == 0) {
          if (unaff_retaddr[0x75] == 0) {
            if (unaff_retaddr[0x76] == 0) goto LAB_000fbf4c;
            goto LAB_000fbe18;
          }
        }
        else {
LAB_000fbe18:
          if ((unaff_retaddr[0x75] == 0) && (unaff_retaddr[0x76] == 0)) {
            builtin_strncpy(local_a0,"#Spy",4);
            local_9c._0_1_ = '_';
            local_9c._1_1_ = 'd';
            local_9c._2_1_ = 'i';
            local_9c._3_1_ = 's';
            builtin_strncpy(local_98,"guising",8);
            goto LAB_000fbf4c;
          }
        }
        pcVar7 = "#Spy_disguised";
        pcVar14 = local_a0;
        for (iVar9 = 3; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar14 = pcVar14 + 4;
        }
        *(undefined2 *)pcVar14 = *(undefined2 *)pcVar7;
        pcVar14[2] = pcVar7[2];
        if (unaff_retaddr[0x75] != 0) {
          strcat(local_a0," ");
          pcVar7 = (char *)GetTeamName__Fi(unaff_retaddr[0x75]);
          strcat(local_a0,pcVar7);
        }
        if (unaff_retaddr[0x76] == 0) {
          strcat(local_a0," #");
          pcVar7 = PTR_DAT_00169240;
        }
        else {
          strcat(local_a0," #");
          pcVar7 = (&sClassNames)[unaff_retaddr[0x76]];
        }
        strcat(local_a0,pcVar7);
      }
LAB_000fbf4c:
      if (*(int *)(*unaff_retaddr + 0x20c) == 9) {
        if (unaff_retaddr[0x1a] == 0) {
          if (((*(int *)(*unaff_retaddr + 0x20c) == 9) &&
              (fVar2 = (float)unaff_retaddr[0x54],
              (byte)(_FUN_0014f1c8 < fVar2 |
                     (byte)((ushort)((ushort)(NAN(_FUN_0014f1c8) || NAN(fVar2)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(_FUN_0014f1c8 == fVar2) << 0xe) >> 8)) != 0x40)) &&
             (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_sentrygun")
             , piVar6 != (int *)0x0)) {
            do {
              piVar15 = (int *)__opP11CBaseEntity__7EHANDLE(piVar6 + 0x51);
              if (piVar15 == unaff_retaddr) {
                _local_128 = CONCAT22(uStack_126,in_FPUControlWord);
                local_130 = (int)ROUND((*(float *)(*piVar6 + 0x160) / *(float *)(*piVar6 + 0x1b0)) *
                                       100.0);
                iVar9 = local_130;
                if (local_130 < 0) {
                  iVar9 = 0;
                }
                if (100 < iVar9) {
                  iVar9 = 100;
                }
                sprintf(local_a0,"#Sentry_sbar %d",iVar9);
                strcat(local_a0,"%%\n4   ammo: %i4%%\n0 ");
                if (piVar6[0x33] == 0) {
LAB_000fc0cd:
                  if ((piVar6[0x39] == 0) && (piVar6[0x23] == 3)) {
                    pcVar7 = "#No_Ammo";
                  }
                  else {
                    pcVar7 = "#No_Shells";
                  }
                }
                else {
                  _local_128 = CONCAT22(uStack_126,in_FPUControlWord);
                  local_130 = CONCAT22(uStack_126,CONCAT11(0xc,(char)in_FPUControlWord));
                  local_10 = (int)ROUND(((float)piVar6[0x33] / (float)piVar6[0x30]) * 100.0);
                  if (piVar6[0x33] == 0) goto LAB_000fc0cd;
                  if ((piVar6[0x39] != 0) || (piVar6[0x23] != 3)) goto LAB_000fc112;
                  pcVar7 = "#No_Rockets";
                }
                strcat(local_a0,pcVar7);
              }
LAB_000fc112:
              piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                        (piVar6,"building_sentrygun");
            } while (piVar6 != (int *)0x0);
          }
        }
        else {
          pcVar7 = "#Engineer_building";
          pcVar14 = local_a0;
          for (iVar9 = 4; iVar9 != 0; iVar9 = iVar9 + -1) {
            *(undefined4 *)pcVar14 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar14 = pcVar14 + 4;
          }
          *(undefined2 *)pcVar14 = *(undefined2 *)pcVar7;
          pcVar14[2] = pcVar7[2];
        }
      }
      puVar10 = &stack0xfffffdfc;
      if ((*(int *)(*unaff_retaddr + 0x20c) == 4) &&
         (puVar10 = &stack0xfffffdfc, unaff_retaddr[0x1b] != 0)) {
        pcVar7 = "#Demoman_detpacking";
        pcVar14 = local_a0;
        for (iVar9 = 5; puVar10 = &stack0xfffffdfc, iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar14 = pcVar14 + 4;
        }
      }
      goto LAB_000fc160;
    }
  }
  fVar2 = *gpGlobals;
  if ((byte)((cb_prematch_time < fVar2 |
              (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(cb_prematch_time == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    builtin_strncpy(local_11c,"#Sbar_dead",0xb);
    fVar2 = (float)param_1[0x4c];
  }
  else {
    pcVar7 = "#Sbar_prematch";
    pcVar14 = local_11c;
    for (iVar9 = 3; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined4 *)pcVar14 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar14 = pcVar14 + 4;
    }
    *(undefined2 *)pcVar14 = *(undefined2 *)pcVar7;
    pcVar14[2] = pcVar7[2];
    if ((byte)((float)tfc_clanbattle._12_4_ < _FUN_0014f1c8 |
               (byte)((ushort)((ushort)(NAN((float)tfc_clanbattle._12_4_) || NAN(_FUN_0014f1c8)) <<
                              10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == _FUN_0014f1c8) << 0xe) >> 8))
        != 0x40) {
      pcVar7 = "#Sbar_battleid";
      puVar12 = &local_9c;
      for (iVar9 = 3; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        puVar12 = puVar12 + 1;
      }
      *(undefined2 *)puVar12 = *(undefined2 *)pcVar7;
      *(char *)((int)puVar12 + 2) = pcVar7[2];
      if ((byte)((float)tfc_clanbattle._12_4_ < _FUN_0014f1c8 |
                 (byte)((ushort)((ushort)(NAN((float)tfc_clanbattle._12_4_) || NAN(_FUN_0014f1c8))
                                << 10) >> 8) |
                (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == _FUN_0014f1c8) << 0xe) >> 8
                      )) != 0x40) {
        local_8 = param_1[0x7d];
      }
    }
    local_4 = cease_fire;
    fVar2 = cb_prematch_time;
  }
  iVar9 = (int)ROUND(ROUND(fVar2 - *gpGlobals)) % 0x3c;
  if (iVar9 == 1) {
    local_10 = 1;
  }
  else {
    local_18 = iVar9;
  }
  local_120[1] = in_FPUControlWord;
  local_120[0] = in_FPUControlWord & 0xf3ff | 0x800;
  local_124 = (float)CONCAT22(local_124._2_2_,in_FPUControlWord);
  local_12c = (int)ROUND(ROUND(fVar2 - *gpGlobals) * 0.016666668);
  if (local_12c == 1) {
    local_c = 1;
    puVar10 = &stack0xfffffe00;
  }
  else {
    local_14 = local_12c;
    puVar10 = &stack0xfffffe00;
  }
LAB_000fc160:
  *(undefined4 *)(puVar10 + 0x68) = 0;
  fVar2 = *(float *)(*(int *)(puVar10 + 0x204) + 0x130);
  if (((byte)(_FUN_0014f1c8 < fVar2 |
              (byte)((ushort)((ushort)(NAN(_FUN_0014f1c8) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(_FUN_0014f1c8 == fVar2) << 0xe) >> 8)) != 0x40) &&
     (fVar2 < *gpGlobals)) {
    iVar9 = 0xb;
    bVar16 = true;
    pcVar7 = puVar10 + 0xe4;
    pcVar14 = "#Sbar_dead";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      bVar16 = *pcVar7 == *pcVar14;
      pcVar7 = pcVar7 + 1;
      pcVar14 = pcVar14 + 1;
    } while (bVar16);
    if (bVar16) {
      puVar10[0xe4] = 0;
    }
  }
  iVar9 = *(int *)(puVar10 + 0x204);
  *(int *)(puVar10 + -4) = iVar9 + 0xc20;
  puVar1 = puVar10 + 0x164;
  *(undefined1 **)(puVar10 + -8) = puVar1;
  *(undefined4 *)(puVar10 + -0xc) = 0xfc1dd;
  iVar8 = strcmp(*(char **)(puVar10 + -8),*(char **)(puVar10 + -4));
  if (iVar8 != 0) {
    uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x204) + 0x208);
    *(undefined4 *)(puVar10 + 0x60) = uVar4;
    *(undefined4 *)(puVar10 + -4) = uVar4;
    *(undefined4 *)(puVar10 + -8) = 0;
    *(undefined4 *)(puVar10 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar10 + -0x10) = 1;
    *(code **)(puVar10 + 0x60) = DAT_001c10d8;
    *(undefined4 *)(puVar10 + -0x14) = 0xfc21d;
    (*DAT_001c10d8)();
    *(undefined4 *)(puVar10 + -4) = 0;
    *(code **)(puVar10 + 0x60) = DAT_001c10e0;
    *(undefined4 *)(puVar10 + -8) = 0xfc236;
    (*DAT_001c10e0)();
    *(undefined1 **)(puVar10 + -8) = puVar1;
    *(code **)(puVar10 + 0x60) = DAT_001c10f8;
    *(undefined4 *)(puVar10 + -0xc) = 0xfc24b;
    (*DAT_001c10f8)();
    *(code **)(puVar10 + 0x60) = DAT_001c10dc;
    *(undefined4 *)(puVar10 + -0xc) = 0xfc25f;
    (*DAT_001c10dc)();
    *(undefined1 **)(puVar10 + -0xc) = puVar1;
    *(int *)(puVar10 + -0x10) = iVar9 + 0xc20;
    *(undefined4 *)(puVar10 + -0x14) = 0xfc266;
    strcpy(*(char **)(puVar10 + -0x10),*(char **)(puVar10 + -0xc));
    *(undefined4 *)(puVar10 + 0x68) = 1;
  }
  iVar9 = *(int *)(puVar10 + 0x204);
  *(int *)(puVar10 + -4) = iVar9 + 0xca0;
  puVar1 = puVar10 + 0xe4;
  *(undefined1 **)(puVar10 + -8) = puVar1;
  *(undefined4 *)(puVar10 + -0xc) = 0xfc28c;
  iVar8 = strcmp(*(char **)(puVar10 + -8),*(char **)(puVar10 + -4));
  if (iVar8 != 0) {
    uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x204) + 0x208);
    *(undefined4 *)(puVar10 + 0x60) = uVar4;
    *(undefined4 *)(puVar10 + -4) = uVar4;
    *(undefined4 *)(puVar10 + -8) = 0;
    *(undefined4 *)(puVar10 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar10 + -0x10) = 1;
    *(code **)(puVar10 + 0x60) = DAT_001c10d8;
    *(undefined4 *)(puVar10 + -0x14) = 0xfc2cc;
    (*DAT_001c10d8)();
    *(undefined4 *)(puVar10 + -4) = 1;
    *(code **)(puVar10 + 0x60) = DAT_001c10e0;
    *(undefined4 *)(puVar10 + -8) = 0xfc2e5;
    (*DAT_001c10e0)();
    *(undefined1 **)(puVar10 + -8) = puVar1;
    *(code **)(puVar10 + 0x60) = DAT_001c10f8;
    *(undefined4 *)(puVar10 + -0xc) = 0xfc2fa;
    (*DAT_001c10f8)();
    *(code **)(puVar10 + 0x60) = DAT_001c10dc;
    *(undefined4 *)(puVar10 + -0xc) = 0xfc30e;
    (*DAT_001c10dc)();
    *(undefined1 **)(puVar10 + -0xc) = puVar1;
    *(int *)(puVar10 + -0x10) = iVar9 + 0xca0;
    *(undefined4 *)(puVar10 + -0x14) = 0xfc315;
    strcpy(*(char **)(puVar10 + -0x10),*(char **)(puVar10 + -0xc));
    *(undefined4 *)(puVar10 + 0x68) = 1;
  }
  iVar9 = 1;
  piVar15 = (int *)(*(int *)(puVar10 + 0x204) + 0xdb0);
  piVar6 = (int *)(puVar10 + 0x1e8);
  do {
    if ((*piVar6 != *piVar15) || (*(int *)(puVar10 + 0x68) != 0)) {
      uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x204) + 0x208);
      *(undefined4 *)(puVar10 + 0x60) = uVar4;
      *(undefined4 *)(puVar10 + -4) = uVar4;
      *(undefined4 *)(puVar10 + -8) = 0;
      *(undefined4 *)(puVar10 + -0xc) = gmsgStatusValue;
      *(undefined4 *)(puVar10 + -0x10) = 1;
      *(code **)(puVar10 + 0x60) = DAT_001c10d8;
      *(undefined4 *)(puVar10 + -0x14) = 0xfc37e;
      (*DAT_001c10d8)();
      *(int *)(puVar10 + -4) = iVar9;
      *(code **)(puVar10 + 0x60) = DAT_001c10e0;
      *(undefined4 *)(puVar10 + -8) = 0xfc396;
      (*DAT_001c10e0)();
      *(int *)(puVar10 + -8) = *piVar6;
      *(code **)(puVar10 + 0x60) = DAT_001c10e8;
      *(undefined4 *)(puVar10 + -0xc) = 0xfc3ad;
      (*DAT_001c10e8)();
      *(code **)(puVar10 + 0x60) = DAT_001c10dc;
      *(undefined4 *)(puVar10 + -0xc) = 0xfc3c1;
      (*DAT_001c10dc)();
      *piVar15 = *piVar6;
    }
    *(int *)(puVar10 + 100) = iVar9 + 1;
    if ((piVar6[1] != piVar15[1]) || (*(int *)(puVar10 + 0x68) != 0)) {
      uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x204) + 0x208);
      *(undefined4 *)(puVar10 + 0x60) = uVar4;
      *(undefined4 *)(puVar10 + -4) = uVar4;
      *(undefined4 *)(puVar10 + -8) = 0;
      *(undefined4 *)(puVar10 + -0xc) = gmsgStatusValue;
      *(undefined4 *)(puVar10 + -0x10) = 1;
      *(code **)(puVar10 + 0x60) = DAT_001c10d8;
      *(undefined4 *)(puVar10 + -0x14) = 0xfc417;
      (*DAT_001c10d8)();
      *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(puVar10 + 100);
      *(code **)(puVar10 + 0x60) = DAT_001c10e0;
      *(undefined4 *)(puVar10 + -8) = 0xfc433;
      (*DAT_001c10e0)();
      *(int *)(puVar10 + -8) = piVar6[1];
      *(code **)(puVar10 + 0x60) = DAT_001c10e8;
      *(undefined4 *)(puVar10 + -0xc) = 0xfc44b;
      (*DAT_001c10e8)();
      *(code **)(puVar10 + 0x60) = DAT_001c10dc;
      *(undefined4 *)(puVar10 + -0xc) = 0xfc45f;
      (*DAT_001c10dc)();
      piVar15[1] = piVar6[1];
    }
    piVar15 = piVar15 + 2;
    piVar6 = piVar6 + 2;
    iVar9 = iVar9 + 2;
  } while (iVar9 < 7);
  return;
}


