// TeamFortress_Build__11CBasePlayeri  @ 0009c25c
void TeamFortress_Build__11CBasePlayeri(void)

{
  FUN_0009c267();
  return;
}


// TeamFortress_CalcEMPDmgRad__11CBaseEntityRfT1  @ 0008760c
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


// TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1  @ 000d7d94
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_CalcEMPDmgRad__11CBasePlayerRfT1(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = (float)_FUN_0013b838;
  *param_3 = fVar1 * (float)param_1[0x39] + (float)param_1[0x33] * 0.75;
  if (*(int *)(*param_1 + 0x20c) != 9) {
    *param_3 = fVar1 * (float)param_1[0x37] + *param_3;
  }
  *param_2 = *param_3;
  return;
}


// TeamFortress_CheckClassStats__11CBasePlayer  @ 000d6c94
void TeamFortress_CheckClassStats__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *(float *)(*param_1 + 0x1b8);
  fVar2 = (float)param_1[0x3b];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    *(int *)(*param_1 + 0x1b8) = param_1[0x3b];
  }
  fVar1 = *(float *)(*param_1 + 0x1bc);
  fVar2 = (float)param_1[0x3c];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    *(int *)(*param_1 + 0x1bc) = param_1[0x3c];
  }
  fVar1 = *(float *)(*param_1 + 0x1b8);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(*param_1 + 0x1b8) = 0;
  }
  fVar1 = *(float *)(*param_1 + 0x1bc);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(*param_1 + 0x1bc) = 0;
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
  fVar1 = *(float *)(iVar3 + 0x160);
  fVar2 = *(float *)(iVar3 + 0x1b0);
  if ((0x3f < (byte)((fVar1 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) &&
     ((*(byte *)((int)param_1 + 0x8a) & 1) == 0)) {
    *(undefined4 *)(iVar3 + 0x160) = *(undefined4 *)(iVar3 + 0x1b0);
  }
  fVar1 = *(float *)(*param_1 + 0x160);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(*param_1 + 0x160) = 0;
  }
  *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0x1f;
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
  return;
}


// TeamFortress_Concuss__11CBaseEntityP9entvars_s  @ 0010008c
void TeamFortress_Concuss__11CBaseEntityP9entvars_s(void)

{
  return;
}


// TeamFortress_Concuss__11CBasePlayerP9entvars_s  @ 000d82b8
void TeamFortress_Concuss__11CBasePlayerP9entvars_s(int *param_1)

{
  param_1[0x261] = 100;
  param_1[0x263] = 100;
  param_1[0x264] = *gpGlobals;
  param_1[0x265] = 0x41700000;
  if (*(int *)(*param_1 + 0x20c) == 5) {
    param_1[0x265] = 0x40e00000;
  }
  return;
}


// TeamFortress_DetpackStop__11CBasePlayer  @ 00091658
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
    (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x118))(param_1[0x211]);
  }
  return;
}


// TeamFortress_Discard__11CBasePlayer  @ 000f7a70
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
    FUN_000f7b1a();
    return;
  case 6:
    local_3c = param_1[0x39];
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
  if (*(int *)(*param_1 + 0x20c) != 9) goto LAB_000f7f09;
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
    if (local_44 != 0) goto LAB_000f7c6c;
  }
  else {
    local_44 = 0x14;
LAB_000f7c6c:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Drop_shells",0,0,0,0);
    param_1[0x37] = param_1[0x37] + local_44 * -2;
  }
  if (ROUND((float)iVar7 * 0.5) <= 10.0) {
    local_40 = (int)ROUND(ROUND((float)iVar7 * 0.5));
    if (local_40 != 0) goto LAB_000f7d34;
  }
  else {
    local_40 = 10;
LAB_000f7d34:
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
LAB_000f7f09:
  if (((local_38 != 0) || (local_3c != 0)) || (local_40 != 0)) {
    param_1[0x346] = param_1[0x346] + 1;
    if (3 < param_1[0x346]) {
      RemoveOldAmmobox__11CBasePlayer(param_1);
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/ammopickup1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    piVar6 = (int *)GetClassPtr__H1Z10CWeaponBox_PX01_PX01(0);
    (**(code **)(piVar6[0xf5] + 8))(piVar6);
    *(char **)(*piVar6 + 0x1d0) = "?tf_ammobox" + (1 - (int)gpGlobals[0x26]);
    *(char **)*piVar6 = "?tf_ammobox" + (1 - (int)gpGlobals[0x26]);
    *(undefined4 *)(*piVar6 + 400) = *(undefined4 *)(*param_1 + 0x208);
    piVar6[0xfc] = (int)(*gpGlobals + 2.0);
    piVar6[0x48] = param_1[0x48];
    piVar6[0xfd] = (int)*gpGlobals;
    piVar6[0x35] = local_38;
    piVar6[0x39] = local_3c;
    piVar6[0x37] = local_40;
    piVar6[0x33] = local_44;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar6,*param_1 + 8);
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
    iVar7 = *piVar6;
    *(undefined4 *)(iVar7 + 0x50) = g_vecZero;
    *(undefined4 *)(iVar7 + 0x54) = DAT_001a7e04;
    *(undefined4 *)(iVar7 + 0x58) = DAT_001a7e08;
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


// TeamFortress_DisplayDetectionItems__11CBasePlayer  @ 000f846c
void TeamFortress_DisplayDetectionItems__11CBasePlayer(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_tfdetect");
  if (iVar1 != 0) {
    DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(param_1,iVar1);
  }
  return;
}


// TeamFortress_DisplayLegalClasses__11CBasePlayer  @ 000d5bc0
void TeamFortress_DisplayLegalClasses__11CBasePlayer(undefined4 *param_1)

{
  uint uVar1;
  
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_legalclasses",0,0,0,0);
  uVar1 = *(uint *)(&illegalclasses + param_1[0x48] * 4);
  if ((((illegalclasses ^ 1) & 1) != 0) && ((((byte)uVar1 ^ 1) & 1) != 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Scout",0,0,0,0);
  }
  if (((illegalclasses & 2) == 0) && ((uVar1 & 2) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sniper",0,0,0,0);
  }
  if (((illegalclasses & 4) == 0) && ((uVar1 & 4) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Soldier",0,0,0,0);
  }
  if (((illegalclasses & 8) == 0) && ((uVar1 & 8) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Demoman",0,0,0,0);
  }
  if (((illegalclasses & 0x10) == 0) && ((uVar1 & 0x10) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Medic",0,0,0,0);
  }
  if (((illegalclasses & 0x20) == 0) && ((uVar1 & 0x20) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#HWGuy",0,0,0,0);
  }
  if (((illegalclasses & 0x40) == 0) && ((uVar1 & 0x40) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Pyro",0,0,0,0);
  }
  if (((DAT_001b49e1 & 1) == 0) && ((uVar1 & 0x100) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,&DAT_0013b3c0,0,0,0,0);
  }
  if (((DAT_001b49e1 & 2) == 0) && ((uVar1 & 0x200) == 0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Engineer",0,0,0,0);
  }
  if ((-1 < (char)illegalclasses) && (-1 < (char)(byte)uVar1)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#RandomPC",0,0,0,0);
  }
  return;
}


// TeamFortress_EMPExplode__11CBaseEntityP9entvars_sff  @ 00087460
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
    iVar2 = (*DAT_001a7f54)(0);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)0x0;
      goto LAB_000874a6;
    }
  }
  puVar3 = *(undefined4 **)(iVar2 + 0x7c);
LAB_000874a6:
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
  (*DAT_001a7ef8)(5,0x17,*param_1 + 8,0);
  (*DAT_001a7f00)(3);
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001a7f08)((int)g_sModelIndexFireball);
  (*DAT_001a7f00)(iVar2);
  (*DAT_001a7f00)(0xf);
  (*DAT_001a7f00)(3);
  (*DAT_001a7efc)();
  return;
}


// TeamFortress_EMPRemove__11CBaseEntity  @ 00087678
void TeamFortress_EMPRemove__11CBaseEntity(undefined4 param_1)

{
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// TeamFortress_EMPRemove__5CItem  @ 000abc28
void TeamFortress_EMPRemove__5CItem(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0xb8))(param_1);
  return;
}


// TeamFortress_EngineerBuild__11CBasePlayeri  @ 0009bdd4
void TeamFortress_EngineerBuild__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x88))(param_1);
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
      if (param_1[0x211] == 0) {
        return;
      }
      (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x118))(param_1[0x211]);
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


// TeamFortress_ExecClassScript__11CBasePlayer  @ 000d5ddc
void TeamFortress_ExecClassScript__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((((*(int *)(iVar1 + 0x20c) != 0xb) && (*(int *)(iVar1 + 0x20c) != 0)) &&
      (*(int *)(iVar1 + 0x20c) != 10)) &&
     ((param_1[0xc] != *(int *)(iVar1 + 0x20c) &&
      (param_1[0xc] = *(int *)(iVar1 + 0x20c), param_1[0x3d] != 0)))) {
    (*DAT_001a7ef8)(1,9,0,*(undefined4 *)(iVar1 + 0x208));
    (*DAT_001a7f18)(*(undefined4 *)(sClassCfgs + *(int *)(*param_1 + 0x20c) * 4));
    (*DAT_001a7efc)();
  }
  return;
}


// TeamFortress_ExecMapScript__11CBasePlayer  @ 000d5e84
void TeamFortress_ExecMapScript__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x3e] != 0) {
    (*DAT_001a7ef8)(1,9,0,*(undefined4 *)(*param_1 + 0x208));
    uVar1 = UTIL_VarArgs__FPce("exec mapdefault.cfg\nexec %s.cfg\n",
                               *(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98));
    (*DAT_001a7f18)(uVar1);
    (*DAT_001a7efc)();
  }
  return;
}


// TeamFortress_GetNoPlayers__Fv  @ 00100b08
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


// TeamFortress_InitStatusBar__11CBasePlayer  @ 000ee2d0
void TeamFortress_InitStatusBar__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0xd48) = 0;
  *(undefined1 *)(param_1 + 0xbac) = 0;
  *(undefined1 *)(param_1 + 0xc2c) = 0;
  return;
}


// TeamFortress_PrimeGrenade__11CBasePlayeri  @ 000d8328
void TeamFortress_PrimeGrenade__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((((*(byte *)(param_1 + 0x21) & 1) == 0) && ((*(byte *)((int)param_1 + 0x85) & 4) == 0)) &&
     (iVar1 = (**(code **)(param_1[0xf5] + 0x88))(param_1), iVar1 != 0)) {
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
        goto switchD_000d83a8_caseD_6;
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
switchD_000d83a8_caseD_6:
  return;
}


// TeamFortress_PrintClassName__11CBasePlayeri  @ 000d4220
void TeamFortress_PrintClassName__11CBasePlayeri(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = UTIL_VarArgs__FPce(&DAT_0013b0e8,*(undefined4 *)(sClassNames + param_2 * 4),0,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,uVar1);
  return;
}


// TeamFortress_RemoveDetpacks__11CBasePlayer  @ 000916d4
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


// TeamFortress_RemoveLiveGrenades__11CBasePlayer  @ 000d65f8
void TeamFortress_RemoveLiveGrenades__11CBasePlayer(undefined4 param_1)

{
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_napalmgrenade");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_nailgrenade");
  RemoveOwnedEnt__11CBasePlayerPc(param_1,"tf_weapon_gasgrenade");
  return;
}


// TeamFortress_RemoveTimers__11CBasePlayer  @ 000d6878
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
LAB_000d6a15:
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
        param_1[0xe0] = 0;
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x15c) = 0;
        iVar1 = *param_1;
        *(undefined4 *)(iVar1 + 0x150) = g_vecZero;
        *(undefined4 *)(iVar1 + 0x154) = DAT_001a7e04;
        *(undefined4 *)(iVar1 + 0x158) = DAT_001a7e08;
        *(undefined4 *)(*param_1 + 0x14c) = 0;
        return;
      }
    } while (*(int *)(*piVar4 + 0x198) != *(int *)(*param_1 + 0x208));
    if ((*(byte *)((int)piVar4 + 0x221) & 1) == 0) {
      tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar4,param_1,0);
    }
  } while (CTF_Map != 1);
  if (piVar4[0x84] != 1) goto code_r0x000d69cb;
  iVar1 = *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98);
  pcVar3 = "%s LOST the BLUE flag!\n";
  goto LAB_000d69f1;
code_r0x000d69cb:
  if (piVar4[0x84] == 2) {
    iVar1 = *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = "%s LOST the RED flag!\n";
LAB_000d69f1:
    uVar2 = UTIL_VarArgs__FPce(pcVar3,iVar1);
    UTIL_ClientPrintAll__FiPCcN41(4,uVar2,0,0,0,0);
  }
  goto LAB_000d6a15;
}


// TeamFortress_SaveMe__11CBasePlayer  @ 000f8188
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
    lVar6 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
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
       (iVar3 = (*DAT_001a7f58)(*(int *)(*piVar5 + 0x208)), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    if ((*piVar5 != 0) &&
       (((iVar3 = *piVar5, *(int *)(iVar3 + 0x20c) == 5 || (*(int *)(iVar3 + 0x20c) == 8)) ||
        (*(int *)(iVar3 + 0x20c) == 9)))) {
      (*DAT_001a7ef8)(1,0x17,0,*(undefined4 *)(*piVar5 + 0x208));
      (*DAT_001a7f00)(0x7c);
      uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(uVar4);
      (*DAT_001a7f14)(0x42480000);
      (*DAT_001a7f08)((int)g_sModelIndexSaveMe);
      (*DAT_001a7f08)(0x28);
      (*DAT_001a7efc)();
    }
  }
  return;
}


// TeamFortress_SetDetpack__11CBasePlayeri  @ 0009139c
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
        goto LAB_00091582;
      }
      piVar4 = (int *)0x0;
      goto LAB_00091503;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"player");
    if ((iVar1 == 0) && (local_4 != param_1)) {
      pcVar3 = "#Detpack_someone";
      goto LAB_00091566;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"building_sentrygun");
    if (iVar1 == 0) {
      pcVar3 = "#Detpack_sentry";
      goto LAB_00091566;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"building_dispenser");
    if (iVar1 == 0) {
      pcVar3 = "#Detpack_dispenser";
      goto LAB_00091566;
    }
    iVar1 = strcmp((char *)(*(int *)*local_4 + (int)gpGlobals[0x26]),"detpack");
  } while (iVar1 != 0);
  pcVar3 = "#Detpack_stack";
LAB_00091566:
  iVar1 = *param_1;
  goto LAB_00091582;
  while (iVar1 = *param_1, *(int *)(*piVar4 + 0x198) != *(int *)(iVar1 + 0x208)) {
LAB_00091503:
    piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"detpack");
    if (piVar4 == (int *)0x0) {
      if (4 < param_2) {
        param_1[0x1b] = 1;
        param_1[0x31] = param_1[0x31] + -1;
        param_1[99] = (int)(*gpGlobals + 10.0);
        *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
        TeamFortress_SetSpeed__11CBasePlayer(param_1);
        (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x120))(param_1[0x211],0);
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
      goto LAB_00091566;
    }
  }
  pcVar3 = "#Detpack_oneactive";
LAB_00091582:
  ClientPrint__FP9entvars_siPCcN42(iVar1,1,pcVar3,0,0,0,0);
  return;
}


// TeamFortress_SetEquipment__11CBasePlayer  @ 000d47f8
void TeamFortress_SetEquipment__11CBasePlayer(int *param_1)

{
  uint uVar1;
  int *piVar2;
  code *pcVar3;
  char *pcVar4;
  
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
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_axe");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
    pcVar4 = "tf_weapon_ng";
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ng");
    param_1[0x33] = param_1[0x33] + -8;
LAB_000d543b:
    SwitchWeapon__11CBasePlayerPCc(param_1,pcVar4);
    goto LAB_000d5532;
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
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_axe");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ng");
    pcVar4 = "tf_weapon_sniperrifle";
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
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_axe");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
    pcVar4 = "tf_weapon_rpg";
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
    param_1[0x202] = 6;
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_axe");
    GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
    pcVar4 = "tf_weapon_gl";
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
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_medikit");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
      pcVar3 = FUN_0013b248;
      GiveNamedItem__11CBasePlayerPc(param_1,FUN_0013b248);
      param_1[0x33] = param_1[0x33] + -0x18;
LAB_000d520a:
      SwitchWeapon__11CBasePlayerPCc(param_1,pcVar3);
      goto LAB_000d5532;
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
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_axe");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
      pcVar4 = "tf_weapon_ac";
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ac");
      param_1[0x33] = param_1[0x33] + -0x18;
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
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_axe");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_shotgun");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ic");
      pcVar4 = "tf_weapon_flamethrower";
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
        pcVar3 = (code *)0x13b1a0;
        GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_axe");
        goto LAB_000d520a;
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
          goto LAB_000d5532;
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
        pcVar4 = "tf_weapon_railgun";
        GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_railgun");
        GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
        param_1[0x33] = param_1[0x33] + -0x10;
        goto LAB_000d543b;
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
      param_1[0x3a] = (int)"CTFGoalItem";
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 7;
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_knife");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_supershotgun");
      pcVar4 = "tf_weapon_tranq";
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_tranq");
      GiveNamedItem__11CBasePlayerPc(param_1,"tf_weapon_ng");
      param_1[0x33] = param_1[0x33] + -0x10;
    }
  }
  SwitchWeapon__11CBasePlayerPCc(param_1,pcVar4);
LAB_000d5532:
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
    *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) | 4;
  }
  else {
    *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) & 0xfb;
  }
  return;
}


// TeamFortress_SetHealth__11CBasePlayer  @ 000d55b8
void TeamFortress_SetHealth__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x20c);
  if (iVar1 == 1) {
    *(undefined4 *)(*param_1 + 0x1b0) = 0x42960000;
    goto LAB_000d565c;
  }
  if (iVar1 != 2) {
    if (iVar1 == 3) {
LAB_000d55f6:
      *(undefined4 *)(*param_1 + 0x1b0) = 0x42c80000;
      goto LAB_000d565c;
    }
    if ((iVar1 != 4) && (iVar1 != 5)) {
      if ((iVar1 == 6) || (iVar1 == 7)) goto LAB_000d55f6;
      if (iVar1 == 0xb) {
        *(undefined4 *)(*param_1 + 0x1b0) = 0x42480000;
        goto LAB_000d565c;
      }
      if (iVar1 != 8) {
        if (iVar1 == 9) {
          *(undefined4 *)(*param_1 + 0x1b0) = 0x42a00000;
        }
        else if (iVar1 == 0) {
          *(undefined4 *)(*param_1 + 0x1b0) = 0x3f800000;
          *(undefined4 *)(*param_1 + 0x16c) = 0;
        }
        goto LAB_000d565c;
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x1b0) = 0x42b40000;
LAB_000d565c:
  *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
  return;
}


// TeamFortress_SetSkin__11CBasePlayer  @ 000d5878
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeamFortress_SetSkin__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = (*DAT_001a7fe8)(*(undefined4 *)(*param_1 + 0x208));
  param_1[99] = (int)(*gpGlobals + 10.0);
  iVar3 = *(int *)(*param_1 + 0x20c);
  if ((iVar3 == 8) && (param_1[0x76] != 0)) {
    iVar3 = param_1[0x76];
  }
  local_20 = param_1[0x48];
  if ((*(int *)(*param_1 + 0x20c) == 8) && (param_1[0x75] != 0)) {
    local_20 = param_1[0x75];
  }
  if (*(int *)(sClassModelFiles + iVar3 * 4) == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/player/scout/scout.mdl");
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  else {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/player/scout/scout.mdl");
    uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208),uVar1,"model",
                            *(undefined4 *)(sClassModels + iVar3 * 4));
    (*DAT_001a7ff4)(uVar2);
  }
  if (param_1[0x48] != 0) {
    iVar3 = *(int *)(teamcolors + local_20 * 4);
    uVar2 = UTIL_VarArgs__FPce(&DAT_0013b340,iVar3);
    uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208),uVar1,"topcolor",uVar2);
    (*DAT_001a7ff4)(uVar2);
    uVar2 = UTIL_VarArgs__FPce(&DAT_0013b340,iVar3 + -10);
    uVar1 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208),uVar1,"bottomcolor",uVar2);
    (*DAT_001a7ff4)(uVar1);
  }
  iVar3 = *param_1;
  if ((*(byte *)(iVar3 + 0x1a5) & 0x40) == 0) {
    local_14 = _FUN_0013b35c;
    local_10 = 0x42100000;
    puVar5 = &local_18;
    local_8 = 0xc1800000;
    local_4 = 0xc2100000;
    puVar4 = &local_c;
    iVar3 = *param_1;
  }
  else {
    local_8 = _FUN_0013b35c;
    local_4 = 0x41900000;
    puVar5 = &local_c;
    local_14 = 0xc1800000;
    local_10 = 0xc1900000;
    puVar4 = &local_18;
  }
  local_18 = local_14;
  local_c = local_8;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar3,puVar4,puVar5);
  g_ulModelIndexPlayer = *(undefined4 *)(*param_1 + 0xb4);
  return;
}


// TeamFortress_SetSpeed__11CBasePlayer  @ 000d566c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    *(undefined4 *)(iVar2 + 0x24) = DAT_001a7e04;
    *(undefined4 *)(iVar2 + 0x28) = DAT_001a7e08;
    *(undefined4 *)(*param_1 + 0x210) = 0x3f800000;
    return;
  }
  if (iVar3 == 1) {
    local_8 = 400.0;
    goto LAB_000d576a;
  }
  if (iVar3 != 2) {
    if (iVar3 == 3) {
LAB_000d574e:
      local_8 = 240.0;
      goto LAB_000d576a;
    }
    if (iVar3 == 4) {
      local_8 = 280.0;
      goto LAB_000d576a;
    }
    if (iVar3 == 5) {
      local_8 = 320.0;
      goto LAB_000d576a;
    }
    if (iVar3 == 6) {
      local_8 = 230.0;
      goto LAB_000d576a;
    }
    if (iVar3 != 7) {
      if (iVar3 == 0xb) goto LAB_000d574e;
      if ((iVar3 != 8) && (iVar3 != 9)) goto LAB_000d576a;
    }
  }
  local_8 = 300.0;
LAB_000d576a:
  piVar4 = (int *)0x0;
LAB_000d57cb:
  do {
    piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"item_tfgoal");
    if (piVar4 == (int *)0x0) {
      if ((short)param_1[0x21] < 0) {
        local_8 = local_8 * 0.5;
      }
      fVar1 = (float)param_1[0x68];
      if ((byte)(_FUN_0013b318 < fVar1 |
                 (byte)((ushort)((ushort)(NAN(_FUN_0013b318) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(_FUN_0013b318 == fVar1) << 0xe) >> 8)) != 0x40) {
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
  if ((*(byte *)(piVar4 + 0x88) & 2) == 0) goto LAB_000d579c;
  fVar1 = 0.5;
  goto LAB_000d57bb;
LAB_000d579c:
  if (piVar4[200] != 0) {
    fVar1 = (float)piVar4[200] * 0.01;
LAB_000d57bb:
    local_8 = fVar1 * local_8;
  }
  goto LAB_000d57cb;
}


// TeamFortress_SetupRespawn__11CBasePlayeri  @ 000d6adc
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
    param_1[0x1f6] = 0;
    param_1[0x1f7] = 0;
    *(undefined1 *)(param_1 + 0x179) = 0;
    fVar1 = *gpGlobals + 1.0;
    if (0x3f < (byte)((fVar1 < cb_prematch_time |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) - 1)) {
      if (param_2 != 0) {
        if (0 < (int)param_1[0x49]) {
          param_1[0x49] = param_1[0x49] + -1;
        }
        local_10 = (float)param_1[0x19f] - *gpGlobals;
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


// TeamFortress_SortTeams__Fv  @ 0010148c
int TeamFortress_SortTeams__Fv(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_28;
  int iStack_24;
  int iStack_1c;
  int iStack_18;
  int aiStack_14 [5];
  
  iStack_18 = 0;
  iStack_1c = 0;
  iStack_24 = 1;
  g_iOrderedTeams = 0;
  DAT_001b4a24 = 0;
  DAT_001b4a28 = 0;
  DAT_001b4a2c = 0;
  DAT_001b4a30 = 0;
  iStack_28 = 1;
  if (1.0 <= number_of_teams) {
    iVar5 = 4;
    do {
      iVar2 = iStack_18;
      iVar4 = 0;
      iVar3 = 1;
      if (1.0 <= number_of_teams) {
        do {
          if ((iVar4 <= *(int *)(teamscores + iVar3 * 4)) && (aiStack_14[iVar3] == 0)) {
            iVar4 = *(int *)(teamscores + iVar3 * 4);
            iStack_18 = iVar3;
          }
          iVar3 = iVar3 + 1;
          fVar1 = (float)iVar3;
        } while ((byte)((fVar1 < number_of_teams |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) <
                 0x40);
      }
      if ((((1 < iStack_28) && (iStack_24 == 1)) &&
          ((((byte)(*(int *)((int)&teamallies + iVar5) >> ((char)iVar2 - 1U & 0x1f)) ^ 1) & 1) != 0)
          ) && (iVar4 != iStack_1c)) {
        iStack_24 = 0;
      }
      aiStack_14[iStack_18] = 1;
      *(int *)((int)&g_iOrderedTeams + iVar5) = iStack_18;
      iVar5 = iVar5 + 4;
      iStack_28 = iStack_28 + 1;
      fVar1 = (float)iStack_28;
      iStack_1c = iVar4;
    } while ((byte)((fVar1 < number_of_teams |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40);
  }
  return iStack_24;
}


// TeamFortress_SpyCalcName__11CBasePlayer  @ 000e50e8
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
         (*(int *)(*piVar2 + 0x20c) == *(int *)(param_1 + 0x1d8))) goto LAB_000e5195;
    }
    for (iVar3 = 1; iVar3 <= *(int *)(gpGlobals + 0x90); iVar3 = iVar3 + 1) {
      piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
      if ((piVar2 != (int *)0x0) && (piVar2[0x48] == *(int *)(param_1 + 0x1d4))) {
LAB_000e5195:
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x1dc,piVar2);
        return;
      }
    }
  }
  return;
}


// TeamFortress_SpyChangeColor__11CBasePlayeri  @ 000e534c
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
  else if ((param_1[0x33e] == 0) && (param_2 != param_1[0x75])) {
    if (((*(byte *)(*param_1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_start",0,0,0,0);
      param_1[0x19] = 2;
      piVar1 = (int *)CreateTimer__11CBaseEntityi(param_1,0xd);
      piVar1[3] = -0x10000;
      piVar1[4] = (int)Timer_SpyUndercoverThink__11CBaseEntity;
      *(float *)(*piVar1 + 0x104) = *gpGlobals + 4.0;
      piVar1[0x48] = param_2;
    }
    else {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spy_unable",0,0,0,0);
    }
  }
  return;
}


// TeamFortress_SpyChangeSkin__11CBasePlayeri  @ 000e51c0
void TeamFortress_SpyChangeSkin__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_4;
  
  local_4 = 4;
  iVar1 = param_1[0x33e];
  if (iVar1 != 0) {
    if ((iVar1 != param_1[0x75]) && (iVar1 != param_1[0x48])) {
      local_4 = 8;
    }
    if ((param_2 == 8) || (param_2 == param_1[0x76])) {
      param_1[0x33e] = 0;
    }
    TeamFortress_SpyChangeColor__11CBasePlayeri(param_1,iVar1);
    param_1[0x33e] = 0;
  }
  if (param_2 == 8) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_resetclass",0,0,0,0);
    param_1[0x76] = 0;
    if ((param_1[0x75] == 0) && (iVar1 == 0)) {
      param_1[0x19] = 0;
    }
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


// TeamFortress_SpyDisguiseEnemy__11CBasePlayerii  @ 000e545c
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
        iVar1 = (*DAT_001a7fa8)(1,(int)ROUND(number_of_teams));
      } while (iVar1 == *(int *)(param_1 + 0x120));
    }
  }
  TeamFortress_SpyDisguise__11CBasePlayerii(param_1,iVar1,param_3);
  return;
}


// TeamFortress_SpyDisguise__11CBasePlayerii  @ 000e54fc
void TeamFortress_SpyDisguise__11CBasePlayerii(int *param_1,int param_2,int param_3)

{
  if (((*(byte *)(*param_1 + 0x118) & 9) == 0) && (param_1[0x1d] != 1)) {
    param_1[0x33e] = param_2;
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
  return;
}


// TeamFortress_SpyFeignDeath__11CBasePlayeri  @ 000e47e8
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
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50 [4];
  int local_4c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  fVar1 = (float)param_1[0x176];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  param_1[0x176] = 0x3f000000;
  if (param_1[0x1c] == 0) {
    if (param_1[0x1d] == 1) {
      pcVar5 = "#Feign_unable";
    }
    else {
      iVar2 = *param_1;
      if (((*(byte *)(iVar2 + 0x1a5) & 2) == 0) && (*(int *)(iVar2 + 0x1c0) == 0)) {
        pcVar5 = "#Feign_air";
        goto LAB_000e4b27;
      }
      iVar2 = CanFeign__11CBasePlayer(param_1);
      if (iVar2 == 0) {
        pcVar5 = "#Feign_onspy";
      }
      else {
        iVar2 = *param_1;
        if ((*(byte *)(iVar2 + 0x1a5) & 0x40) == 0) {
LAB_000e4bc6:
          param_1[0x25e] = 0;
          SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
          param_1[99] = (int)(*gpGlobals + 5.0);
          *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 1;
          TeamFortress_SetSpeed__11CBasePlayer(param_1);
          *(undefined4 *)(*param_1 + 0x170) = 5;
          param_1[0x1c] = 1;
          param_1[0xec] = 0;
          TeamFortress_SetSkin__11CBasePlayer(param_1);
          if (param_1[0x211] != 0) {
            (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x120))(param_1[0x211],0);
          }
          local_74 = _FUN_0013cf3c;
          local_6c = 0xc2000000;
          local_68 = 0xc1800000;
          local_60 = 0xc2100000;
          local_70 = local_74;
          local_64 = local_68;
          UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_68,&local_74);
          iVar2 = *param_1;
          local_6c = 0x40800000;
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
            lVar4 = (longdouble)(*DAT_001a7fac)(0,0x43960000);
            *(float *)(*param_1 + 0x28) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x28));
          }
          if (param_2 == 0) {
            (**(code **)(param_1[0xf5] + 0x200))(param_1);
          }
          *(undefined4 *)(*param_1 + 0x50) = 0;
          *(undefined4 *)(*param_1 + 0x58) = 0;
          piVar7 = (int *)0x0;
LAB_000e4e15:
          do {
            do {
              piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"item_tfgoal");
              if (piVar7 == (int *)0x0) {
                *(undefined4 *)(*param_1 + 0x24c) = 1;
                return;
              }
            } while (*(int *)(*piVar7 + 0x198) != *(int *)(*param_1 + 0x208));
            if (((*(byte *)((int)piVar7 + 0x221) & 1) == 0) || (param_1[0x1e] == 1)) {
              tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar7,param_1,0);
            }
          } while (CTF_Map != 1);
          if (piVar7[0x84] != 1) goto code_r0x000e4dcb;
          iVar2 = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
          pcVar5 = "%s LOST the BLUE flag!\n";
          goto LAB_000e4df9;
        }
        local_18 = *(undefined4 *)(iVar2 + 8);
        local_14 = *(undefined4 *)(iVar2 + 0xc);
        local_10 = *(float *)(iVar2 + 0x10);
        if ((*(byte *)(iVar2 + 0x1a5) & 2) != 0) {
          local_74 = 0xc1800000;
          local_60 = 0xc1900000;
          local_6c = 0xc2100000;
          local_54 = 0x41900000;
          local_5c = 0;
          local_58 = 0;
          local_10 = local_10 + 18.0;
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
            local_54 = 0xc2100000;
            local_6c = 0x41900000;
            local_74 = 0;
            local_70 = 0;
            local_c = *(undefined4 *)(iVar2 + 8);
            local_8 = *(undefined4 *)(iVar2 + 0xc);
            local_4 = *(float *)(iVar2 + 0x10) + 18.0;
            *(undefined4 *)(iVar2 + 8) = local_c;
            *(undefined4 *)(iVar2 + 0xc) = local_8;
            *(float *)(iVar2 + 0x10) = local_4;
            local_64 = local_68;
            local_5c = local_68;
            local_58 = local_68;
          }
          goto LAB_000e4bc6;
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
      *(undefined4 *)(iVar2 + 0x24) = DAT_001a7e04;
      *(undefined4 *)(iVar2 + 0x28) = DAT_001a7e08;
      iVar2 = *param_1;
      if ((*(byte *)(iVar2 + 0x1a5) & 0x40) == 0) {
        local_14 = _FUN_0013cf3c;
        local_10 = 36.0;
        puVar8 = &local_18;
        local_8 = 0xc1800000;
        local_4 = -36.0;
        puVar6 = &local_c;
        iVar2 = *param_1;
      }
      else {
        local_8 = _FUN_0013cf3c;
        local_4 = 18.0;
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
      if (param_1[0x211] != 0) {
        (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x118))(param_1[0x211]);
      }
      *(undefined4 *)(*param_1 + 0x138) = 0xbf800000;
      param_1[0x25e] = 0;
      SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
      *(undefined4 *)(*param_1 + 0x24c) = 0;
      return;
    }
    pcVar5 = "#Feign_unabletogetup";
  }
  iVar2 = *param_1;
LAB_000e4b27:
  ClientPrint__FP9entvars_siPCcN42(iVar2,4,pcVar5,0,0,0,0);
  return;
code_r0x000e4dcb:
  if (piVar7[0x84] == 2) {
    iVar2 = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    pcVar5 = "%s LOST the RED flag!\n";
LAB_000e4df9:
    uVar3 = UTIL_VarArgs__FPce(pcVar5,iVar2,0,0,0,0);
    UTIL_ClientPrintAll__FiPCcN41(1,uVar3);
  }
  goto LAB_000e4e15;
}


// TeamFortress_SpyGoUndercover__11CBasePlayer  @ 000e5054
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


// TeamFortress_StatusQuery__Fv  @ 001013cc
void TeamFortress_StatusQuery__Fv(void)

{
  undefined4 uVar1;
  
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi();
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(3,uVar1);
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(2,uVar1);
  uVar1 = TeamFortress_TeamGetNoPlayers__Fi(1,uVar1);
  (*DAT_001a7f34)(1,"players per team: %d %d %d %d\n",uVar1);
  (*DAT_001a7f34)(1,"    equalisation: %0.1f %0.1f %0.1f %0.1f\n",(double)DAT_001b4a74,
                  (double)DAT_001b4a78,(double)DAT_001b4a7c,(double)DAT_001b4a80);
  (*DAT_001a7f34)(1,"Teamplay is %d\n",(double)*(float *)(gpGlobals + 0x1c));
  return;
}


// TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_sf  @ 00087698
void TeamFortress_TakeConcussionBlast__11CBaseEntityP9entvars_sf(void)

{
  return;
}


// TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_sf  @ 000d8008
void TeamFortress_TakeConcussionBlast__11CBasePlayerP9entvars_sf
               (int *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = (**(code **)(param_1[0xf5] + 0x88))(param_1);
  if (iVar3 == 0) {
    return;
  }
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x20c) != 0) {
    local_c = *(float *)(iVar3 + 8) - *(float *)(param_2 + 8);
    local_8 = *(float *)(iVar3 + 0xc) - *(float *)(param_2 + 0xc);
    local_4 = *(float *)(iVar3 + 0x10) - *(float *)(param_2 + 0x10);
    iVar3 = *(int *)(param_2 + 0x208);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar3 + 0x7c);
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
        (iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,uVar4), iVar3 != 0)) &&
       (*(int *)(param_2 + 0x198) != *(int *)(*param_1 + 0x208))) {
      return;
    }
    (*DAT_001a7ef8)(1,gmsgDamage,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)(0);
    (*DAT_001a7f00)(0);
    (*pcRam001a7f0c)(0x200);
    (*DAT_001a7f14)(*(undefined4 *)(param_2 + 8));
    (*DAT_001a7f14)(*(undefined4 *)(param_2 + 0xc));
    (*DAT_001a7f14)(*(undefined4 *)(param_2 + 0x10));
    (*DAT_001a7efc)();
    (**(code **)(param_1[0xf5] + 0xfc))(param_1,param_2);
    return;
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_s  @ 000f4830
void TeamFortress_TakeEMPBlast__10CTFGrenadeP9entvars_s(int *param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"tf_gl_pipebomb");
  if (iVar1 == 0) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_s  @ 00112090
void TeamFortress_TakeEMPBlast__10CWeaponBoxP9entvars_s(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fStack_8;
  undefined4 local_4;
  
  if (*(int *)(param_2 + 0x198) == 0) {
    (*DAT_001a7f54)(0);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001a7f54)(0);
  }
  (**(code **)(param_1[0xf5] + 0xec))(param_1,&fStack_8,&local_4);
  if (0x3f < (byte)((fStack_8 < 0.0 | (byte)((ushort)((ushort)NAN(fStack_8) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_8 == 0.0) << 0xe) >> 8)) - 1)) {
    (**(code **)(param_1[0xf5] + 0xe8))(param_1,param_2,fStack_8,local_4);
    fVar1 = (float)param_1[0xfd];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      iVar2 = *(int *)(*param_1 + 400);
      if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      if ((iVar2 != 0) && (iVar3 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x28))(iVar2), iVar3 == 2)
         ) {
        *(int *)(iVar2 + 0xd18) = *(int *)(iVar2 + 0xd18) + -1;
      }
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_s  @ 00087694
void TeamFortress_TakeEMPBlast__11CBaseEntityP9entvars_s(void)

{
  return;
}


// TeamFortress_TakeEMPBlast__11CBasePlayerP9entvars_s  @ 000d7e00
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
  if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001a7f54)(0);
  }
  if ((*(int *)(*param_1 + 0x20c) != 0) &&
     (((local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord)),
       ((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) == 0 ||
       (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar2), iVar1 == 0)) ||
      (piVar2 == param_1)))) {
    (**(code **)(param_1[0xf5] + 0xec))(param_1,&local_18,&local_14);
    param_1[0x33] = (int)ROUND((double)param_1[0x33] - ROUND((double)param_1[0x33] * 0.25));
    param_1[0x39] = (int)ROUND((double)param_1[0x39] - ROUND((double)param_1[0x39] * 0.25));
    if (*(int *)(*param_1 + 0x20c) != 9) {
      param_1[0x37] = (int)ROUND((double)param_1[0x37] - ROUND((double)param_1[0x37] * 0.25));
    }
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    local_10 = in_FPUControlWord & 0xf3ff | 0x800;
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    if (0.0 < local_18) {
      (**(code **)(param_1[0xf5] + 0xe8))(param_1,param_2,local_18,local_14);
    }
  }
  return;
}


// TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_s  @ 00092dac
void TeamFortress_TakeEMPBlast__12CTFDispenserP9entvars_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001a7f54)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar2), iVar1 != 0)) &&
     (puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar2 != puVar3)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x34))(param_1,param_2,*puVar2,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_s  @ 000df944
void TeamFortress_TakeEMPBlast__12CTFSentrygunP9entvars_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_2 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 0x7c);
  }
  if (*(int *)(param_2 + 0x208) == 0) {
    (*DAT_001a7f54)(0);
  }
  if (((((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) != 0) &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,puVar2), iVar1 != 0)) &&
     (puVar3 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x144), puVar2 != puVar3)) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x34))(param_1,param_2,*puVar2,0x43480000,0x40);
  return;
}


// TeamFortress_TakeEMPBlast__8CDetpackP9entvars_s  @ 000909ac
void TeamFortress_TakeEMPBlast__8CDetpackP9entvars_s(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_001a7fac)(0,0x40000000);
  *(float *)(*param_1 + 0x160) = (float)((longdouble)1.0 + (longdouble)*gpGlobals + lVar1);
  return;
}


// TeamFortress_TeamGetNoPlayers__Fi  @ 00100ab8
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


// TeamFortress_TeamGetScoreFrags__Fi  @ 00100a94
undefined4 TeamFortress_TeamGetScoreFrags__Fi(int param_1)

{
  return *(undefined4 *)(teamscores + param_1 * 4);
}


// TeamFortress_TeamIncreaseScore__Fii  @ 001009f0
void TeamFortress_TeamIncreaseScore__Fii(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    *(int *)(teamscores + param_1 * 4) = *(int *)(teamscores + param_1 * 4) + param_2;
    (*DAT_001a7ef8)(2,gmsgTeamScore,0,0);
    uVar1 = GetTeamName__Fi(param_1);
    (*DAT_001a7f18)(uVar1);
    (*DAT_001a7f08)(*(undefined4 *)(teamscores + param_1 * 4));
    (*DAT_001a7f08)(0);
    (*DAT_001a7efc)();
  }
  return;
}


// TeamFortress_TeamIsCivilian__Ff  @ 00100ccc
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


// TeamFortress_TeamPutPlayerInTeam__11CBasePlayer  @ 000d5f00
void TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float local_18;
  
  iVar2 = 1;
  lVar4 = (longdouble)(*DAT_001a7fac)(0,number_of_teams);
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


// TeamFortress_TeamSetColor__Fi  @ 0010087c
void TeamFortress_TeamSetColor__Fi(void)

{
  teamcolors._4_4_ = 0x96;
  teamcolors._8_4_ = 0xfa;
  teamcolors._12_4_ = 0x2d;
  teamcolors._16_4_ = 100;
  rgbcolors = 0x437f0000;
  DAT_001b49a4 = 0x437f0000;
  DAT_001b49a8 = 0x437f0000;
  DAT_001b49ac = 0;
  DAT_001b49b0 = 0;
  DAT_001b49b4 = 0x437f0000;
  DAT_001b49b8 = 0x437f0000;
  DAT_001b49bc = 0;
  DAT_001b49c0 = 0;
  DAT_001b49c4 = 0x437f0000;
  DAT_001b49c8 = 0x437f0000;
  DAT_001b49cc = 0x41f00000;
  DAT_001b49d0 = 0;
  DAT_001b49d4 = 0x437f0000;
  DAT_001b49d8 = 0;
  return;
}


// TeamFortress_TeamSet__11CBasePlayeri  @ 000d601c
undefined4 TeamFortress_TeamSet__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if ((0 < param_1[0x48]) && (param_1[0x48] == param_2)) {
    return 0;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(gpGlobals[7]) << 10) >> 8) |
            (byte)((ushort)((ushort)(gpGlobals[7] == 0.0) << 0xe) >> 8)) == 0x40) {
    pcVar5 = "#Game_noteams";
  }
  else {
    fVar1 = (float)param_2;
    if ((0x3f < (byte)((fVar1 < number_of_teams |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1)) &&
       ((byte)(0.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
              (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) != 0x40)) {
      uVar8 = 0;
      uVar7 = 0;
      uVar6 = 0;
      uVar2 = UTIL_dtos1__Fi((int)ROUND(number_of_teams),0,0,0);
      pcVar5 = "Game_onlyteams";
      iVar3 = *param_1;
      goto LAB_000d6154;
    }
    iVar3 = TeamFortress_TeamGetNoPlayers__Fi(param_2);
    if (iVar3 < *(int *)(teammaxplayers + param_2 * 4)) {
      if (*(int *)(teamcolors + param_2 * 4) != 0) {
        if (param_1[0x48] < 1) {
          uVar2 = UTIL_dtos1__Fi(param_2,0,0);
          UTIL_ClientPrintAll__FiPCcN41
                    (1,"#Game_joinedteam",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar2);
          uVar2 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208),param_2);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i>\" joined team \"%d\".\n",
                     *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar2);
        }
        else {
          uVar2 = UTIL_dtos1__Fi(param_2,0,0);
          UTIL_ClientPrintAll__FiPCcN41
                    (1,"#Game_changedteam",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar2);
          uVar2 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208),param_2);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i>\" changed to team \"%d\".\n",
                     *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar2);
          Engineer_RemoveBuildings__11CBasePlayer(param_1);
          TeamFortress_RemoveDetpacks__11CBasePlayer(param_1);
          TeamFortress_RemoveLiveGrenades__11CBasePlayer(param_1);
          *(undefined4 *)(*param_1 + 0x20c) = 0;
          param_1[0x1f9] = 1;
          param_1[0x1fc] = 0;
          param_1[0xb] = 0;
          param_1[0x21] = 0;
          RemoveAllItems__11CBasePlayeri(param_1,0);
          param_1[0x1a0] = (int)(*gpGlobals + 0.2);
          *(undefined4 *)(*param_1 + 0x160) = 0;
          (**(code **)(param_1[0xf5] + 0x3c))(param_1,*param_1,1);
          iVar3 = param_1[0x4b];
          param_1[0x4b] = iVar3 + 1;
          *(float *)(*param_1 + 0x164) = (float)(iVar3 + 1);
          param_1[600] = param_1[600] + -1;
        }
        param_1[0x48] = param_2;
        *(int *)(*param_1 + 0x1ac) = param_2;
        param_1[0x49] = *(int *)(teamlives + param_2 * 4);
        for (iVar3 = 1; iVar3 <= (int)gpGlobals[0x24]; iVar3 = iVar3 + 1) {
          piVar4 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
          if (piVar4 != (int *)0x0) {
            (*DAT_001a7ef8)(1,gmsgTeamInfo,0,*(undefined4 *)(*piVar4 + 0x208));
            uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
            (*DAT_001a7f00)(uVar2);
            uVar2 = (**(code **)(*g_pGameRules + 0xcc))(g_pGameRules,param_1);
            (*DAT_001a7f18)(uVar2);
            (*DAT_001a7efc)();
          }
        }
        TeamFortress_TeamIncreaseScore__Fii(param_1[0x48],0);
        TeamFortress_SetSkin__11CBasePlayer(param_1);
        Menu_Class__11CBasePlayer(param_1);
        return 1;
      }
      pcVar5 = "#Game_noteamstart";
    }
    else {
      if (param_1[0x48] == 0) {
        Menu_Team__11CBasePlayer(param_1);
      }
      pcVar5 = "#Game_teamfull";
    }
  }
  uVar8 = 0;
  uVar7 = 0;
  uVar6 = 0;
  uVar2 = 0;
  iVar3 = *param_1;
LAB_000d6154:
  ClientPrint__FP9entvars_siPCcN42(iVar3,1,pcVar5,uVar2,uVar6,uVar7,uVar8);
  return 0;
}


// TeamFortress_TeamShowMemberClasses__11CBasePlayer  @ 000d6410
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
        uVar4 = UTIL_VarArgs__FPce(&DAT_0013b0e8,
                                   *(undefined4 *)(sClassNames + *(int *)(*piVar2 + 0x20c) * 4),0,0)
        ;
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


// TeamFortress_TeamShowScores__FiP11CBasePlayer  @ 0010076c
void TeamFortress_TeamShowScores__FiP11CBasePlayer(int param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 1;
  if (1.0 <= number_of_teams) {
    iVar3 = 4;
    do {
      if (param_1 == 0) {
        uVar2 = UTIL_VarArgs__FPce("%s: %d\n",*(undefined4 *)(g_szTeamColors + iVar3),
                                   *(undefined4 *)(teamscores + iVar3),0,0,0,0);
LAB_00100808:
        UTIL_ClientPrintAll__FiPCcN41(1,uVar2);
      }
      else {
        if (param_2 == (undefined4 *)0x0) {
          uVar2 = UTIL_VarArgs__FPce("Team %d (%s): %d\n",iVar4,
                                     *(undefined4 *)(g_szTeamColors + iVar3),
                                     *(undefined4 *)(teamscores + iVar3),0,0,0,0);
          goto LAB_00100808;
        }
        uVar2 = UTIL_VarArgs__FPce("Team %d (%s): %d\n",iVar4,
                                   *(undefined4 *)(g_szTeamColors + iVar3),
                                   *(undefined4 *)(teamscores + iVar3),0,0,0,0);
        ClientPrint__FP9entvars_siPCcN42(*param_2,1,uVar2);
      }
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 1;
      fVar1 = (float)iVar4;
    } while ((byte)((fVar1 < number_of_teams |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40);
  }
  return;
}


// TeamFortress_ThrowPrimedGrenade__11CBasePlayer  @ 000d8310
void TeamFortress_ThrowPrimedGrenade__11CBasePlayer(int param_1)

{
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    *(byte *)(param_1 + 0x85) = *(byte *)(param_1 + 0x85) | 4;
  }
  return;
}


// TeamFortress_UpdateStatusBar__11CBasePlayer  @ 000ee2f0
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
  int iStack_130;
  int local_12c;
  ushort uStack_128;
  undefined2 uStack_126;
  float local_124;
  ushort local_120 [2];
  char local_11c [124];
  char acStack_a0 [4];
  undefined4 local_9c;
  char acStack_98 [124];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  memset(&local_1c,0,0x1c);
  local_9c = local_9c & 0xffffff00;
  strcpy(local_11c,(char *)(param_1 + 0x30b));
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
      (**(code **)(param_1[0xf5] + 200))(&local_170,param_1);
      local_180 = local_174 + gpGlobals[10] * 2048.0;
      local_17c = local_170 + gpGlobals[0xb] * 2048.0;
      local_178 = local_16c + gpGlobals[0xc] * 2048.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_170,&local_180,0,*(undefined4 *)(*unaff_retaddr + 0x208),local_168);
      if ((byte)(1.0 < local_158 | (byte)((ushort)((ushort)NAN(local_158) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_158 == 1.0) << 0xe) >> 8)) != 0x40) {
        bVar16 = false;
        if ((local_138 == 0) || (iVar9 = (*DAT_001a7f58)(local_138), iVar9 == 0)) {
          bVar16 = true;
        }
        if (bVar16) {
          fVar2 = (float)unaff_retaddr[0x352];
          fVar3 = *gpGlobals;
          if (0x3f < (byte)((fVar2 < fVar3 |
                             (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
            local_1c = unaff_retaddr[0x34c];
            local_18 = unaff_retaddr[0x34d];
            local_14 = unaff_retaddr[0x34e];
          }
        }
        else {
          if ((local_138 == 0) && (local_138 = (*DAT_001a7f54)(0), local_138 == 0)) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = *(int **)(local_138 + 0x7c);
          }
          bVar16 = false;
          iVar9 = (**(code **)(piVar6[0xf5] + 0x28))(piVar6);
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
                local_1c = (*DAT_001a7f5c)(*(undefined4 *)(*piVar6 + 0x208));
                pcVar7 = "1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
                puVar11 = local_120;
                for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *(undefined4 *)puVar11 = *(undefined4 *)pcVar7;
                  pcVar7 = pcVar7 + 4;
                  puVar11 = puVar11 + 2;
                }
                *(char *)puVar11 = *pcVar7;
                bVar16 = true;
                __as__7EHANDLEP11CBaseEntity(unaff_retaddr + 0x353,piVar6);
              }
            }
LAB_000ee9f4:
            if (!bVar16) goto LAB_000eeb38;
          }
          else {
            iVar9 = strcmp((char *)(*(int *)*piVar6 + (int)gpGlobals[0x26]),"building_sentrygun");
            if (iVar9 != 0) {
              iVar9 = strcmp((char *)(*(int *)*piVar6 + (int)gpGlobals[0x26]),"building_dispenser");
              if (iVar9 == 0) {
                piVar15 = (int *)__rf__7EHANDLE(piVar6 + 0x51);
                local_1c = (*DAT_001a7f5c)(*(undefined4 *)(*piVar15 + 0x208));
                pcVar7 = "1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
                puVar11 = local_120;
                for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *(undefined4 *)puVar11 = *(undefined4 *)pcVar7;
                  pcVar7 = pcVar7 + 4;
                  puVar11 = puVar11 + 2;
                }
                *(char *)puVar11 = *pcVar7;
                bVar16 = true;
              }
              goto LAB_000ee9f4;
            }
            piVar15 = (int *)__rf__7EHANDLE(piVar6 + 0x51);
            local_1c = (*DAT_001a7f5c)(*(undefined4 *)(*piVar15 + 0x208));
            puVar11 = (ushort *)"1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
            puVar13 = local_120;
            for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {
              *(undefined4 *)puVar13 = *(undefined4 *)puVar11;
              puVar11 = puVar11 + 2;
              puVar13 = puVar13 + 2;
            }
            *puVar13 = *puVar11;
          }
          iVar9 = IsAlly__11CBaseEntityP11CBaseEntity(unaff_retaddr,piVar6);
          if (((iVar9 != 0) || (*(int *)(*unaff_retaddr + 0x20c) == 5)) ||
             (*(int *)(*unaff_retaddr + 0x244) != 0)) {
            local_18 = (int)ROUND((*(float *)(*piVar6 + 0x160) / *(float *)(*piVar6 + 0x1b0)) *
                                  100.0);
            _uStack_128 = CONCAT22(uStack_126,in_FPUControlWord);
            iStack_130 = CONCAT22(uStack_126,CONCAT11(0xc,(char)in_FPUControlWord));
            local_14 = (int)ROUND((*(float *)(*piVar6 + 0x1bc) / (float)piVar6[0x3c]) * 100.0);
          }
          unaff_retaddr[0x352] = (int)(*gpGlobals + 1.0);
        }
LAB_000eeb38:
        if ((local_1c < 0) || ((int)gpGlobals[0x24] < local_1c)) {
          printf("ERROR: SBAR_ID_TARGETNAME = %d\n",local_1c);
          local_1c = 0;
        }
      }
      if (*(int *)(*unaff_retaddr + 0x20c) == 8) {
        if (unaff_retaddr[0x19] == 0) {
          if (unaff_retaddr[0x75] == 0) {
            if (unaff_retaddr[0x76] == 0) goto LAB_000eece8;
            goto LAB_000eebb4;
          }
        }
        else {
LAB_000eebb4:
          if ((unaff_retaddr[0x75] == 0) && (unaff_retaddr[0x76] == 0)) {
            builtin_strncpy(acStack_a0,"#Spy",4);
            local_9c._0_1_ = '_';
            local_9c._1_1_ = 'd';
            local_9c._2_1_ = 'i';
            local_9c._3_1_ = 's';
            builtin_strncpy(acStack_98,"guising",8);
            goto LAB_000eece8;
          }
        }
        pcVar7 = "#Spy_disguised";
        pcVar14 = acStack_a0;
        for (iVar9 = 3; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar14 = pcVar14 + 4;
        }
        *(undefined2 *)pcVar14 = *(undefined2 *)pcVar7;
        pcVar14[2] = pcVar7[2];
        if (unaff_retaddr[0x75] != 0) {
          strcat(acStack_a0," ");
          pcVar7 = (char *)GetTeamName__Fi(unaff_retaddr[0x75]);
          strcat(acStack_a0,pcVar7);
        }
        if (unaff_retaddr[0x76] == 0) {
          strcat(acStack_a0," #");
          pcVar7 = (char *)sClassNames._32_4_;
        }
        else {
          strcat(acStack_a0," #");
          pcVar7 = *(char **)(sClassNames + unaff_retaddr[0x76] * 4);
        }
        strcat(acStack_a0,pcVar7);
      }
LAB_000eece8:
      if (*(int *)(*unaff_retaddr + 0x20c) == 9) {
        if (unaff_retaddr[0x1a] == 0) {
          if (((*(int *)(*unaff_retaddr + 0x20c) == 9) &&
              (fVar2 = (float)unaff_retaddr[0x54],
              (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) &&
             (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_sentrygun")
             , piVar6 != (int *)0x0)) {
            do {
              piVar15 = (int *)__opP11CBaseEntity__7EHANDLE(piVar6 + 0x51);
              if (piVar15 == unaff_retaddr) {
                _uStack_128 = CONCAT22(uStack_126,in_FPUControlWord);
                iStack_130 = (int)ROUND((*(float *)(*piVar6 + 0x160) / *(float *)(*piVar6 + 0x1b0))
                                        * 100.0);
                iVar9 = iStack_130;
                if (iStack_130 < 0) {
                  iVar9 = 0;
                }
                if (100 < iVar9) {
                  iVar9 = 100;
                }
                sprintf(acStack_a0,"#Sentry_sbar %d",iVar9);
                strcat(acStack_a0,"%%\n4   ammo: %i4%%\n0 ");
                if (piVar6[0x33] == 0) {
LAB_000eee69:
                  if ((piVar6[0x39] == 0) && (piVar6[0x23] == 3)) {
                    pcVar7 = "#No_Ammo";
                  }
                  else {
                    pcVar7 = "#No_Shells";
                  }
                }
                else {
                  _uStack_128 = CONCAT22(uStack_126,in_FPUControlWord);
                  iStack_130 = CONCAT22(uStack_126,CONCAT11(0xc,(char)in_FPUControlWord));
                  local_10 = (int)ROUND(((float)piVar6[0x33] / (float)piVar6[0x30]) * 100.0);
                  if (piVar6[0x33] == 0) goto LAB_000eee69;
                  if ((piVar6[0x39] != 0) || (piVar6[0x23] != 3)) goto LAB_000eeeae;
                  pcVar7 = "#No_Rockets";
                }
                strcat(acStack_a0,pcVar7);
              }
LAB_000eeeae:
              piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                        (piVar6,"building_sentrygun");
            } while (piVar6 != (int *)0x0);
          }
        }
        else {
          pcVar7 = "#Engineer_building";
          pcVar14 = acStack_a0;
          for (iVar9 = 4; iVar9 != 0; iVar9 = iVar9 + -1) {
            *(undefined4 *)pcVar14 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar14 = pcVar14 + 4;
          }
          *(undefined2 *)pcVar14 = *(undefined2 *)pcVar7;
          pcVar14[2] = pcVar7[2];
        }
      }
      puVar10 = &stack0xfffffe08;
      if ((*(int *)(*unaff_retaddr + 0x20c) == 4) &&
         (puVar10 = &stack0xfffffe08, unaff_retaddr[0x1b] != 0)) {
        pcVar7 = "#Demoman_detpacking";
        pcVar14 = acStack_a0;
        for (iVar9 = 5; puVar10 = &stack0xfffffe08, iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar14 = pcVar14 + 4;
        }
      }
      goto LAB_000eeefc;
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
    if ((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
    {
      pcVar7 = "#Sbar_battleid";
      puVar12 = &local_9c;
      for (iVar9 = 3; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        puVar12 = puVar12 + 1;
      }
      *(undefined2 *)puVar12 = *(undefined2 *)pcVar7;
      *(char *)((int)puVar12 + 2) = pcVar7[2];
      if ((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
         ) {
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
    puVar10 = &stack0xfffffe0c;
  }
  else {
    local_14 = local_12c;
    puVar10 = &stack0xfffffe0c;
  }
LAB_000eeefc:
  *(undefined4 *)(puVar10 + 0x5c) = 0;
  fVar2 = *(float *)(*(int *)(puVar10 + 0x1f8) + 0x130);
  if (((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) && (fVar2 < *gpGlobals))
  {
    iVar9 = 0xb;
    bVar16 = true;
    pcVar7 = puVar10 + 0xd8;
    pcVar14 = "#Sbar_dead";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      bVar16 = *pcVar7 == *pcVar14;
      pcVar7 = pcVar7 + 1;
      pcVar14 = pcVar14 + 1;
    } while (bVar16);
    if (bVar16) {
      puVar10[0xd8] = '\0';
    }
  }
  iVar9 = *(int *)(puVar10 + 0x1f8);
  *(int *)(puVar10 + -4) = iVar9 + 0xbac;
  puVar1 = puVar10 + 0x158;
  *(undefined1 **)(puVar10 + -8) = puVar1;
  *(undefined4 *)(puVar10 + -0xc) = 0xeef79;
  iVar8 = strcmp(*(char **)(puVar10 + -8),*(char **)(puVar10 + -4));
  if (iVar8 != 0) {
    uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x1f8) + 0x208);
    *(undefined4 *)(puVar10 + 0x54) = uVar4;
    *(undefined4 *)(puVar10 + -4) = uVar4;
    *(undefined4 *)(puVar10 + -8) = 0;
    *(undefined4 *)(puVar10 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar10 + -0x10) = 1;
    *(code **)(puVar10 + 0x54) = DAT_001a7ef8;
    *(undefined4 *)(puVar10 + -0x14) = 0xeefb9;
    (*DAT_001a7ef8)();
    *(undefined4 *)(puVar10 + -4) = 0;
    *(code **)(puVar10 + 0x54) = DAT_001a7f00;
    *(undefined4 *)(puVar10 + -8) = 0xeefd2;
    (*DAT_001a7f00)();
    *(undefined1 **)(puVar10 + -8) = puVar1;
    *(code **)(puVar10 + 0x54) = DAT_001a7f18;
    *(undefined4 *)(puVar10 + -0xc) = 0xeefe7;
    (*DAT_001a7f18)();
    *(code **)(puVar10 + 0x54) = DAT_001a7efc;
    *(undefined4 *)(puVar10 + -0xc) = 0xeeffb;
    (*DAT_001a7efc)();
    *(undefined1 **)(puVar10 + -0xc) = puVar1;
    *(int *)(puVar10 + -0x10) = iVar9 + 0xbac;
    *(undefined4 *)(puVar10 + -0x14) = 0xef002;
    strcpy(*(char **)(puVar10 + -0x10),*(char **)(puVar10 + -0xc));
    *(undefined4 *)(puVar10 + 0x5c) = 1;
  }
  iVar9 = *(int *)(puVar10 + 0x1f8);
  *(int *)(puVar10 + -4) = iVar9 + 0xc2c;
  puVar1 = puVar10 + 0xd8;
  *(undefined1 **)(puVar10 + -8) = puVar1;
  *(undefined4 *)(puVar10 + -0xc) = 0xef028;
  iVar8 = strcmp(*(char **)(puVar10 + -8),*(char **)(puVar10 + -4));
  if (iVar8 != 0) {
    uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x1f8) + 0x208);
    *(undefined4 *)(puVar10 + 0x54) = uVar4;
    *(undefined4 *)(puVar10 + -4) = uVar4;
    *(undefined4 *)(puVar10 + -8) = 0;
    *(undefined4 *)(puVar10 + -0xc) = gmsgStatusText;
    *(undefined4 *)(puVar10 + -0x10) = 1;
    *(code **)(puVar10 + 0x54) = DAT_001a7ef8;
    *(undefined4 *)(puVar10 + -0x14) = 0xef068;
    (*DAT_001a7ef8)();
    *(undefined4 *)(puVar10 + -4) = 1;
    *(code **)(puVar10 + 0x54) = DAT_001a7f00;
    *(undefined4 *)(puVar10 + -8) = 0xef081;
    (*DAT_001a7f00)();
    *(undefined1 **)(puVar10 + -8) = puVar1;
    *(code **)(puVar10 + 0x54) = DAT_001a7f18;
    *(undefined4 *)(puVar10 + -0xc) = 0xef096;
    (*DAT_001a7f18)();
    *(code **)(puVar10 + 0x54) = DAT_001a7efc;
    *(undefined4 *)(puVar10 + -0xc) = 0xef0aa;
    (*DAT_001a7efc)();
    *(undefined1 **)(puVar10 + -0xc) = puVar1;
    *(int *)(puVar10 + -0x10) = iVar9 + 0xc2c;
    *(undefined4 *)(puVar10 + -0x14) = 0xef0b1;
    strcpy(*(char **)(puVar10 + -0x10),*(char **)(puVar10 + -0xc));
    *(undefined4 *)(puVar10 + 0x5c) = 1;
  }
  iVar9 = 1;
  piVar15 = (int *)(*(int *)(puVar10 + 0x1f8) + 0xd30);
  piVar6 = (int *)(puVar10 + 0x1dc);
  do {
    if ((*piVar6 != *piVar15) || (*(int *)(puVar10 + 0x5c) != 0)) {
      uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x1f8) + 0x208);
      *(undefined4 *)(puVar10 + 0x54) = uVar4;
      *(undefined4 *)(puVar10 + -4) = uVar4;
      *(undefined4 *)(puVar10 + -8) = 0;
      *(undefined4 *)(puVar10 + -0xc) = gmsgStatusValue;
      *(undefined4 *)(puVar10 + -0x10) = 1;
      *(code **)(puVar10 + 0x54) = DAT_001a7ef8;
      *(undefined4 *)(puVar10 + -0x14) = 0xef11a;
      (*DAT_001a7ef8)();
      *(int *)(puVar10 + -4) = iVar9;
      *(code **)(puVar10 + 0x54) = DAT_001a7f00;
      *(undefined4 *)(puVar10 + -8) = 0xef132;
      (*DAT_001a7f00)();
      *(int *)(puVar10 + -8) = *piVar6;
      *(code **)(puVar10 + 0x54) = DAT_001a7f08;
      *(undefined4 *)(puVar10 + -0xc) = 0xef149;
      (*DAT_001a7f08)();
      *(code **)(puVar10 + 0x54) = DAT_001a7efc;
      *(undefined4 *)(puVar10 + -0xc) = 0xef15d;
      (*DAT_001a7efc)();
      *piVar15 = *piVar6;
    }
    *(int *)(puVar10 + 0x58) = iVar9 + 1;
    if ((piVar6[1] != piVar15[1]) || (*(int *)(puVar10 + 0x5c) != 0)) {
      uVar4 = *(undefined4 *)(**(int **)(puVar10 + 0x1f8) + 0x208);
      *(undefined4 *)(puVar10 + 0x54) = uVar4;
      *(undefined4 *)(puVar10 + -4) = uVar4;
      *(undefined4 *)(puVar10 + -8) = 0;
      *(undefined4 *)(puVar10 + -0xc) = gmsgStatusValue;
      *(undefined4 *)(puVar10 + -0x10) = 1;
      *(code **)(puVar10 + 0x54) = DAT_001a7ef8;
      *(undefined4 *)(puVar10 + -0x14) = 0xef1b3;
      (*DAT_001a7ef8)();
      *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(puVar10 + 0x58);
      *(code **)(puVar10 + 0x54) = DAT_001a7f00;
      *(undefined4 *)(puVar10 + -8) = 0xef1cf;
      (*DAT_001a7f00)();
      *(int *)(puVar10 + -8) = piVar6[1];
      *(code **)(puVar10 + 0x54) = DAT_001a7f08;
      *(undefined4 *)(puVar10 + -0xc) = 0xef1e7;
      (*DAT_001a7f08)();
      *(code **)(puVar10 + 0x54) = DAT_001a7efc;
      *(undefined4 *)(puVar10 + -0xc) = 0xef1fb;
      (*DAT_001a7efc)();
      piVar15[1] = piVar6[1];
    }
    piVar15 = piVar15 + 2;
    piVar6 = piVar6 + 2;
    iVar9 = iVar9 + 2;
  } while (iVar9 < 7);
  return;
}


