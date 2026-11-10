// Admin_CeaseFire__Fv  @ 000f7f48
void Admin_CeaseFire__Fv(void)

{
  int *piVar1;
  int iVar2;
  
  if (cease_fire == 0) {
    cease_fire = 1;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Admin_ceasefire",0,0,0,0);
    if (0 < (int)gpGlobals[0x24]) {
      iVar2 = 1;
      do {
        piVar1 = (int *)UTIL_PlayerByIndex__Fi(iVar2);
        if (piVar1 != (int *)0x0) {
          *(undefined4 *)(*piVar1 + 0x250) = 1;
          piVar1[99] = (int)(*gpGlobals + 10.0);
          *(byte *)((int)piVar1 + 0x86) = *(byte *)((int)piVar1 + 0x86) | 1;
          TeamFortress_SetSpeed__11CBasePlayer(piVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 <= (int)gpGlobals[0x24]);
    }
  }
  else {
    cease_fire = 0;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
    UTIL_LogPrintf__FPce("World triggered \"Resume_Fire\"\n");
    for (iVar2 = 1; iVar2 <= (int)gpGlobals[0x24]; iVar2 = iVar2 + 1) {
      piVar1 = (int *)UTIL_PlayerByIndex__Fi(iVar2);
      if (piVar1 != (int *)0x0) {
        *(undefined4 *)(*piVar1 + 0x250) = 0;
        piVar1[99] = (int)(*gpGlobals + 10.0);
        *(byte *)((int)piVar1 + 0x86) = *(byte *)((int)piVar1 + 0x86) & 0xfe;
        TeamFortress_SetSpeed__11CBasePlayer(piVar1);
      }
    }
  }
  return;
}


// Admin_Changelevel__11CBasePlayer  @ 000f8370
void Admin_Changelevel__11CBasePlayer(void)

{
  int iVar1;
  undefined4 uVar2;
  char local_100 [256];
  
  iVar1 = (*DAT_001c1170)();
  if (iVar1 == 2) {
    uVar2 = (*DAT_001c116c)(1);
    sprintf(local_100,"changelevel %s\n",uVar2);
    (*DAT_001c10bc)(local_100);
  }
  return;
}


// Admin_CountPlayers__11CBasePlayer  @ 000f7878
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


// Admin_CycleDeal__11CBasePlayer  @ 000f7a34
void Admin_CycleDeal__11CBasePlayer(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  iVar2 = TeamFortress_GetNoPlayers__Fv();
  if (iVar2 < 2) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Admin_gameempty",0,0,0,0);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x81,0);
    param_1[0x80] = 0;
  }
  else {
    iVar2 = 0;
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x81);
    if (iVar3 != 0) {
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x81);
      iVar2 = (*DAT_001c113c)(*(undefined4 *)(*piVar4 + 0x208));
      iVar2 = iVar2 + 1;
    }
    if (iVar2 <= *(int *)(gpGlobals + 0x90)) {
      puVar1 = param_1 + 0x81;
      do {
        uVar5 = UTIL_PlayerByIndex__Fi(iVar2);
        __as__7EHANDLEP11CBaseEntity(puVar1,uVar5);
        iVar3 = __opP11CBaseEntity__7EHANDLE(puVar1);
        if (iVar3 != 0) {
          puVar6 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(puVar1);
          if (puVar6 != param_1) {
            param_1[0x80] = 1;
            uVar8 = 0;
            uVar5 = 0;
            iVar2 = __rf__7EHANDLE(puVar1,0,0);
            iVar2 = *(int *)(iVar2 + 0x20c) + *(int *)(gpGlobals + 0x98);
            piVar4 = (int *)__rf__7EHANDLE(puVar1,iVar2);
            iVar3 = *(int *)(*piVar4 + 0x1d0) + *(int *)(gpGlobals + 0x98);
            pcVar7 = "#Admin_kickban";
            goto LAB_000f7b94;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 <= *(int *)(gpGlobals + 0x90));
    }
    param_1[0x80] = 0;
    uVar8 = 0;
    uVar5 = 0;
    iVar2 = 0;
    iVar3 = 0;
    pcVar7 = "#Admin_endlist";
LAB_000f7b94:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar7,iVar3,iVar2,uVar5,uVar8);
  }
  return;
}


// Admin_DoBan__11CBasePlayer  @ 000f7d78
void Admin_DoBan__11CBasePlayer(int *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  
  piVar5 = param_1 + 0x81;
  iVar1 = __opP11CBaseEntity__7EHANDLE(piVar5);
  if (iVar1 != 0) {
    piVar2 = (int *)__rf__7EHANDLE(piVar5,*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,
                                   0);
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Admin_ban",*(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    iVar1 = __rf__7EHANDLE(piVar5);
    if (*(int *)(iVar1 + 0x120) == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      iVar1 = __rf__7EHANDLE(piVar5);
      pcVar3 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120));
    }
    piVar5 = param_1 + 0x81;
    piVar2 = (int *)__rf__7EHANDLE(piVar5,pcVar3);
    uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*piVar2 + 0x208));
    piVar2 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*piVar2 + 0x208));
    piVar5 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    if (param_1[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_1[0x48],
                                       *(int *)(*piVar5 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    }
    uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
    uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar4);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%u><%s>\" triggered \"Admin_Ban\" against \"%s<%i><%u><%s>\"\n",
               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x81);
    BanPlayer__FP11CBaseEntity(uVar4);
    param_1[0x80] = 0;
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x81,0);
  }
  return;
}


// Admin_DoKick__11CBasePlayer  @ 000f7ba8
void Admin_DoKick__11CBasePlayer(int *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  
  piVar5 = param_1 + 0x81;
  iVar1 = __opP11CBaseEntity__7EHANDLE(piVar5);
  if (iVar1 != 0) {
    piVar2 = (int *)__rf__7EHANDLE(piVar5,*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,
                                   0);
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Admin_kick",*(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    iVar1 = __rf__7EHANDLE(piVar5);
    if (*(int *)(iVar1 + 0x120) == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      iVar1 = __rf__7EHANDLE(piVar5);
      pcVar3 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120));
    }
    piVar5 = param_1 + 0x81;
    piVar2 = (int *)__rf__7EHANDLE(piVar5,pcVar3);
    uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*piVar2 + 0x208));
    piVar2 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*piVar2 + 0x208));
    piVar5 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    if (param_1[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_1[0x48],
                                       *(int *)(*piVar5 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    }
    uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
    uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar4);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%u><%s>\" triggered \"Admin_Kick\" against \"%s<%i><%u><%s>\"\n",
               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x81);
    KickPlayer__FP11CBaseEntity(uVar4);
    param_1[0x80] = 0;
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x81,0);
  }
  return;
}


// Admin_ListIPs__11CBasePlayer  @ 000f7978
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


