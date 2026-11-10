// InitHUD__13CTeamFortressP11CBasePlayer  @ 000fb5cc
void InitHUD__13CTeamFortressP11CBasePlayer(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  InitHUD__17CHalfLifeTeamplayP11CBasePlayer(param_1,param_2);
  uVar1 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208));
  uVar1 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar1);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%s><>\" entered the game\n",
             *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar1);
  uVar1 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208));
  uVar1 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar1);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%s><>\" joined team \"SPECTATOR\"\n",
             *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar1);
  if (1.0 <= number_of_teams) {
    iVar2 = 1;
    do {
      TeamFortress_TeamIncreaseScore__Fii(iVar2,0);
      iVar2 = iVar2 + 1;
    } while ((float)iVar2 <= number_of_teams);
  }
  TeamFortress_ExecMapScript__11CBasePlayer(param_2);
  param_2[0x28f] = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(g_flWeaponCheat) << 10) >> 8) |
            (byte)((ushort)((ushort)(g_flWeaponCheat == 0.0) << 0xe) >> 8)) == 0x40) {
    (*DAT_0019f758)(1,gmsgViewMode,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f75c)();
  }
  return;
}


// InitHUD__14CHalfLifeRulesP11CBasePlayer  @ 000b008c
void InitHUD__14CHalfLifeRulesP11CBasePlayer(void)

{
  return;
}


// InitHUD__17CHalfLifeTeamplayP11CBasePlayer  @ 000f93ec
void InitHUD__17CHalfLifeTeamplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    InitHUD__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
  }
  else {
    InitHUD__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
    for (local_8 = 1; local_8 <= *(int *)(gpGlobals + 0x90); local_8 = local_8 + 1) {
      iVar1 = (*DAT_0019f7c0)(local_8);
      local_c = (int *)0x0;
      if ((iVar1 != 0) && (*(int **)(iVar1 + 0x7c) != (int *)0x0)) {
        local_c = *(int **)(iVar1 + 0x7c);
      }
      if (local_c != (int *)0x0) {
        (*DAT_0019f758)(1,gmsgTeamInfo,0,*(undefined4 *)(*param_2 + 0x208));
        uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*local_c + 0x208));
        (*DAT_0019f760)(uVar2);
        uVar2 = (**(code **)(*g_pGameRules + 0xcc))(g_pGameRules,local_c);
        (*DAT_0019f778)(uVar2);
        (*DAT_0019f75c)();
      }
    }
  }
  return;
}


// InitHUD__18CHalfLifeMultiplayP11CBasePlayer  @ 000add1c
void InitHUD__18CHalfLifeMultiplayP11CBasePlayer(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar4 = "unconnected";
  iVar5 = *(int *)(*param_2 + 0x1d0);
  if ((iVar5 != 0) && (*(char *)(iVar5 + (int)gpGlobals[0x26]) != '\0')) {
    pcVar4 = (char *)(iVar5 + (int)gpGlobals[0x26]);
  }
  UTIL_ClientPrintAll__FiPCcN41(1,"#Game_playerjoin",pcVar4,0,0,0);
  (**(code **)(*param_1 + 0x40))(param_1,param_2);
  param_2[0x311] = (int)(*gpGlobals + 0.1);
  (*DAT_0019f758)(1,gmsgScoreInfo,0,*(undefined4 *)(*param_2 + 0x208));
  uVar1 = (*DAT_0019f7bc)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_0019f760)(uVar1);
  (*DAT_0019f768)(0);
  (*DAT_0019f768)(0);
  (*DAT_0019f768)(0);
  (*DAT_0019f768)(0);
  (*DAT_0019f75c)();
  iVar5 = 1;
  if (0 < (int)gpGlobals[0x24]) {
    do {
      iVar2 = (*DAT_0019f7c0)(iVar5);
      piVar3 = (int *)0x0;
      if ((iVar2 != 0) && (*(int **)(iVar2 + 0x7c) != (int *)0x0)) {
        piVar3 = *(int **)(iVar2 + 0x7c);
      }
      if (piVar3 != (int *)0x0) {
        (*DAT_0019f758)(1,gmsgScoreInfo,0,*(undefined4 *)(*param_2 + 0x208));
        (*DAT_0019f760)(iVar5);
        (*DAT_0019f768)((int)ROUND(*(float *)(*piVar3 + 0x164)));
        (*DAT_0019f768)(piVar3[0x27f]);
        (*DAT_0019f768)(*(undefined4 *)(*piVar3 + 0x20c));
        (*DAT_0019f768)(*(undefined4 *)(*piVar3 + 0x1ac));
        (*DAT_0019f75c)();
        (*DAT_0019f758)(1,gmsgSpectator,0,*(undefined4 *)(*param_2 + 0x208));
        (*DAT_0019f760)(iVar5);
        (*DAT_0019f760)(*(int *)(*piVar3 + 0x244) != 0);
        (*DAT_0019f75c)();
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= (int)gpGlobals[0x24]);
  }
  if (g_fGameOver != 0) {
    (*DAT_0019f758)(1,0x1e,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f75c)();
  }
  return;
}


