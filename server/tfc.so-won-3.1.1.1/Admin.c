// Admin_CeaseFire__Fv  @ 000fa208
void Admin_CeaseFire__Fv(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  if (cease_fire == 0) {
    cease_fire = 1;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Admin_ceasefire",0,0,0,0);
    iVar3 = 1;
    if (0 < (int)gpGlobals[0x24]) {
      do {
        piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
        if (piVar2 != (int *)0x0) {
          *(undefined4 *)(*piVar2 + 0x250) = 1;
          fVar1 = *gpGlobals;
          *(byte *)((int)piVar2 + 0x86) = *(byte *)((int)piVar2 + 0x86) | 1;
          piVar2[99] = (int)(fVar1 + 10.0);
          TeamFortress_SetSpeed__11CBasePlayer(piVar2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= (int)gpGlobals[0x24]);
    }
  }
  else {
    cease_fire = 0;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
    UTIL_LogPrintf__FPce("World triggered \"Resume_Fire\"\n");
    iVar3 = 1;
    if (0 < (int)gpGlobals[0x24]) {
      do {
        piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
        if (piVar2 != (int *)0x0) {
          *(undefined4 *)(*piVar2 + 0x250) = 0;
          fVar1 = *gpGlobals;
          *(byte *)((int)piVar2 + 0x86) = *(byte *)((int)piVar2 + 0x86) & 0xfe;
          piVar2[99] = (int)(fVar1 + 10.0);
          TeamFortress_SetSpeed__11CBasePlayer(piVar2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= (int)gpGlobals[0x24]);
    }
  }
  return;
}


// Admin_Changelevel__11CBasePlayer  @ 000fa550
void Admin_Changelevel__11CBasePlayer(void)

{
  int iVar1;
  undefined4 uVar2;
  char local_104 [256];
  
  iVar1 = (*DAT_0019f7f0)();
  if (iVar1 == 2) {
    uVar2 = (*DAT_0019f7ec)(1);
    sprintf(local_104,"changelevel %s\n",uVar2);
    (*DAT_0019f73c)(local_104);
  }
  return;
}


// Admin_CountPlayers__11CBasePlayer  @ 000fa7a8
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
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}


// Admin_CycleDeal__11CBasePlayer  @ 000f9cd4
void Admin_CycleDeal__11CBasePlayer(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  iVar1 = TeamFortress_GetNoPlayers__Fv();
  if (iVar1 < 2) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Admin_gameempty",0,0,0,0);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x81,0);
    param_1[0x80] = 0;
  }
  else {
    iVar1 = 0;
    puVar6 = param_1 + 0x81;
    iVar2 = __opP11CBaseEntity__7EHANDLE(puVar6);
    if (iVar2 != 0) {
      piVar3 = (int *)__rf__7EHANDLE(puVar6);
      iVar1 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar3 + 0x208));
      iVar1 = iVar1 + 1;
    }
    if (iVar1 <= *(int *)(gpGlobals + 0x90)) {
      do {
        uVar4 = UTIL_PlayerByIndex__Fi(iVar1);
        __as__7EHANDLEP11CBaseEntity(puVar6,uVar4);
        iVar2 = __opP11CBaseEntity__7EHANDLE(puVar6);
        if ((iVar2 != 0) &&
           (puVar5 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(puVar6), puVar5 != param_1)) {
          param_1[0x80] = 1;
          uVar8 = 0;
          uVar4 = 0;
          iVar1 = __rf__7EHANDLE(puVar6,0,0);
          iVar1 = *(int *)(iVar1 + 0x20c) + *(int *)(gpGlobals + 0x98);
          piVar3 = (int *)__rf__7EHANDLE(puVar6,iVar1);
          iVar2 = *(int *)(*piVar3 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          pcVar7 = "#Admin_kickban";
          goto LAB_000f9e54;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 <= *(int *)(gpGlobals + 0x90));
    }
    param_1[0x80] = 0;
    uVar8 = 0;
    uVar4 = 0;
    iVar1 = 0;
    iVar2 = 0;
    pcVar7 = "#Admin_endlist";
LAB_000f9e54:
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar7,iVar2,iVar1,uVar4,uVar8);
  }
  return;
}


// Admin_DoBan__11CBasePlayer  @ 000fa038
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
    piVar2 = (int *)__rf__7EHANDLE(piVar5,pcVar3);
    uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar2 + 0x208));
    piVar2 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    uVar4 = (*DAT_0019f864)(*(undefined4 *)(*piVar2 + 0x208));
    piVar2 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    if (param_1[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_1[0x48],
                                       *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    }
    uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
    uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%s><%s>\" triggered \"Admin_Ban\" against \"%s<%i><%s><%s>\"\n",
               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    uVar4 = __opP11CBaseEntity__7EHANDLE(piVar5);
    BanPlayer__FP11CBaseEntity(uVar4);
    param_1[0x80] = 0;
    __as__7EHANDLEP11CBaseEntity(piVar5,0);
  }
  return;
}


// Admin_DoKick__11CBasePlayer  @ 000f9e68
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
    piVar2 = (int *)__rf__7EHANDLE(piVar5,pcVar3);
    uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar2 + 0x208));
    piVar2 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    uVar4 = (*DAT_0019f864)(*(undefined4 *)(*piVar2 + 0x208));
    piVar2 = (int *)__rf__7EHANDLE(piVar5,uVar4);
    if (param_1[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_1[0x48],
                                       *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    }
    uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
    uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%s><%s>\" triggered \"Admin_Kick\" against \"%s<%i><%s><%s>\"\n",
               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    uVar4 = __opP11CBaseEntity__7EHANDLE(piVar5);
    KickPlayer__FP11CBaseEntity(uVar4);
    param_1[0x80] = 0;
    __as__7EHANDLEP11CBaseEntity(piVar5,0);
  }
  return;
}


// Admin_ListIPs__11CBasePlayer  @ 000fa6d0
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
    iVar1 = 1;
    if (0 < *(int *)(gpGlobals + 0x90)) {
      do {
        piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar1);
        if (piVar2 != (int *)0x0) {
          ClientPrint__FP9entvars_siPCcN42
                    (*param_1,1,"#Admin_listip",
                     *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                     piVar2[0x83] + *(int *)(gpGlobals + 0x98),0,0);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 <= *(int *)(gpGlobals + 0x90));
    }
    pcVar3 = "#Admin_endlist";
  }
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar3,0,0,0,0);
  return;
}


