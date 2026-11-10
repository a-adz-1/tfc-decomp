// Admin_CeaseFire__11CBasePlayer  @ 000eb040
void Admin_CeaseFire__11CBasePlayer(void)

{
  int iVar1;
  int iVar2;
  
  if (cease_fire == 0) {
    cease_fire = 1;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Admin_ceasefire",0,0,0,0);
    if (0 < (int)gpGlobals[0x24]) {
      iVar2 = 1;
      do {
        iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
        if (iVar1 != 0) {
          *(float *)(iVar1 + 0x18c) = *gpGlobals + 10.0;
          *(byte *)(iVar1 + 0x86) = *(byte *)(iVar1 + 0x86) | 1;
          TeamFortress_SetSpeed__11CBasePlayer(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 <= (int)gpGlobals[0x24]);
    }
  }
  else {
    cease_fire = 0;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
    UTIL_LogPrintf__FPce("RESUME FIRE\n");
    for (iVar2 = 1; iVar2 <= (int)gpGlobals[0x24]; iVar2 = iVar2 + 1) {
      iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
      if (iVar1 != 0) {
        *(float *)(iVar1 + 0x18c) = *gpGlobals + 10.0;
        *(byte *)(iVar1 + 0x86) = *(byte *)(iVar1 + 0x86) & 0xfe;
        TeamFortress_SetSpeed__11CBasePlayer(iVar1);
      }
    }
  }
  return;
}


// Admin_Changelevel__11CBasePlayer  @ 000eb408
void Admin_Changelevel__11CBasePlayer(void)

{
  int iVar1;
  undefined4 uVar2;
  char local_100 [256];
  
  iVar1 = (*DAT_001a7f90)();
  if (iVar1 == 2) {
    uVar2 = (*DAT_001a7f8c)(1);
    sprintf(local_100,"changelevel %s\n",uVar2);
    (*DAT_001a7edc)(local_100);
  }
  return;
}


// Admin_CountPlayers__11CBasePlayer  @ 000eaac8
void Admin_CountPlayers__11CBasePlayer(undefined4 *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = TeamFortress_GetNoPlayers__Fv();
  uVar2 = UTIL_dtos1__Fi(uVar2,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Admin_noplayers",uVar2);
  iVar3 = 0;
  do {
    fVar1 = (float)iVar3;
    if (0x3f < (byte)((number_of_teams < fVar1 |
                       (byte)((ushort)((ushort)(NAN(number_of_teams) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(number_of_teams == fVar1) << 0xe) >> 8)) - 1)) {
      uVar2 = TeamFortress_TeamGetNoPlayers__Fi(iVar3 + 1);
      uVar2 = UTIL_dtos2__Fi(uVar2,0,0);
      uVar2 = UTIL_dtos1__Fi(iVar3 + 1,uVar2);
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Admin_noteamplayers",uVar2);
    }
    fVar1 = (float)(iVar3 + 1);
    if (0x3f < (byte)((number_of_teams < fVar1 |
                       (byte)((ushort)((ushort)(NAN(number_of_teams) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(number_of_teams == fVar1) << 0xe) >> 8)) - 1)) {
      uVar2 = TeamFortress_TeamGetNoPlayers__Fi(iVar3 + 2);
      uVar2 = UTIL_dtos2__Fi(uVar2,0,0);
      uVar2 = UTIL_dtos1__Fi(iVar3 + 2,uVar2);
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Admin_noteamplayers",uVar2);
    }
    iVar3 = iVar3 + 2;
  } while (iVar3 < 4);
  return;
}


// Admin_CycleDeal__11CBasePlayer  @ 000eac84
void Admin_CycleDeal__11CBasePlayer(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar2 = TeamFortress_GetNoPlayers__Fv();
  if (iVar2 < 2) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Admin_gameempty",0,0,0,0);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x81,0);
    param_1[0x80] = 0;
  }
  else {
    iVar7 = 0;
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x81);
    if (iVar2 != 0) {
      piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x81);
      iVar7 = (*DAT_001a7f5c)(*(undefined4 *)(*piVar3 + 0x208));
    }
    if (iVar7 <= *(int *)(gpGlobals + 0x90)) {
      puVar1 = param_1 + 0x81;
      do {
        uVar4 = UTIL_PlayerByIndex__Fi(iVar7);
        __as__7EHANDLEP11CBaseEntity(puVar1,uVar4);
        iVar2 = __opP11CBaseEntity__7EHANDLE(puVar1);
        if (iVar2 != 0) {
          puVar5 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(puVar1);
          if (puVar5 != param_1) {
            param_1[0x80] = 1;
            uVar8 = 0;
            uVar4 = 0;
            iVar2 = __rf__7EHANDLE(puVar1,0,0);
            iVar2 = *(int *)(iVar2 + 0x20c) + *(int *)(gpGlobals + 0x98);
            piVar3 = (int *)__rf__7EHANDLE(puVar1,iVar2);
            iVar7 = *(int *)(*piVar3 + 0x1d0) + *(int *)(gpGlobals + 0x98);
            pcVar6 = "#Admin_kickban";
            goto LAB_000eade4;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 <= *(int *)(gpGlobals + 0x90));
    }
    param_1[0x80] = 0;
    uVar8 = 0;
    uVar4 = 0;
    iVar2 = 0;
    iVar7 = 0;
    pcVar6 = "#Admin_endlist";
LAB_000eade4:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar6,iVar7,iVar2,uVar4,uVar8);
  }
  return;
}


// Admin_DoBan__11CBasePlayer  @ 000eaf1c
void Admin_DoBan__11CBasePlayer(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar1 = param_1 + 0x81;
  iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar2 != 0) {
    piVar3 = (int *)__rf__7EHANDLE(piVar1,*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,
                                   0);
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Admin_ban",*(int *)(*piVar3 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    piVar3 = (int *)__rf__7EHANDLE(piVar1);
    uVar4 = (*DAT_001a8004)(*(undefined4 *)(*piVar3 + 0x208));
    piVar3 = (int *)__rf__7EHANDLE(piVar1,uVar4);
    uVar4 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208),
                            *(int *)(*piVar3 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    UTIL_LogPrintf__FPce
              ("\"%s<%i>\" BANNED \"%s<%i>\".\n",
               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    uVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
    BanPlayer__FP11CBaseEntity(uVar4);
    param_1[0x80] = 0;
    __as__7EHANDLEP11CBaseEntity(piVar1,0);
  }
  return;
}


// Admin_DoKick__11CBasePlayer  @ 000eadf8
void Admin_DoKick__11CBasePlayer(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar1 = param_1 + 0x81;
  iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar2 != 0) {
    piVar3 = (int *)__rf__7EHANDLE(piVar1,*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,
                                   0);
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Admin_kick",*(int *)(*piVar3 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    piVar3 = (int *)__rf__7EHANDLE(piVar1);
    uVar4 = (*DAT_001a8004)(*(undefined4 *)(*piVar3 + 0x208));
    piVar3 = (int *)__rf__7EHANDLE(piVar1,uVar4);
    uVar4 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208),
                            *(int *)(*piVar3 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    UTIL_LogPrintf__FPce
              ("\"%s<%i>\" KICKED \"%s<%i>\".\n",
               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    uVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
    KickPlayer__FP11CBaseEntity(uVar4);
    param_1[0x80] = 0;
    __as__7EHANDLEP11CBaseEntity(piVar1,0);
  }
  return;
}


// Admin_ListIPs__11CBasePlayer  @ 000eabc8
void Admin_ListIPs__11CBasePlayer(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  
  iVar1 = TeamFortress_GetNoPlayers__Fv();
  if (iVar1 < 2) {
    pcVar3 = "#Admin_gameempty";
  }
  else {
    for (iVar1 = 1; iVar1 <= *(int *)(gpGlobals + 0x90); iVar1 = iVar1 + 1) {
      piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar1);
      if (piVar2 != (int *)0x0) {
        ClientPrint__FP9entvars_siPCcN42
                  (*param_1,1,"#Admin_listip",*(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98)
                   ,piVar2[0x83] + *(int *)(gpGlobals + 0x98),0,0);
      }
    }
    pcVar3 = "#Admin_endlist";
  }
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar3,0,0,0,0);
  return;
}


