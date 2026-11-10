// InitHUD__13CTeamFortressP11CBasePlayer  @ 000f9284
void InitHUD__13CTeamFortressP11CBasePlayer(undefined4 param_1,int *param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  
  InitHUD__17CHalfLifeTeamplayP11CBasePlayer(param_1,param_2);
  uVar2 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208));
  uVar2 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar2);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%u><>\" entered the game\n",
             *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar2);
  iVar3 = 1;
  fVar1 = 1.0;
  while ((byte)((fVar1 < number_of_teams |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40) {
    TeamFortress_TeamIncreaseScore__Fii(iVar3,0);
    iVar3 = iVar3 + 1;
    fVar1 = (float)iVar3;
  }
  TeamFortress_ExecMapScript__11CBasePlayer(param_2);
  param_2[0x285] = 0;
  return;
}


// InitHUD__14CHalfLifeRulesP11CBasePlayer  @ 000ae424
void InitHUD__14CHalfLifeRulesP11CBasePlayer(void)

{
  return;
}


// InitHUD__17CHalfLifeTeamplayP11CBasePlayer  @ 000f70a4
void InitHUD__17CHalfLifeTeamplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_4;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    InitHUD__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
  }
  else {
    InitHUD__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
    for (iVar1 = 1; iVar1 <= *(int *)(gpGlobals + 0x90); iVar1 = iVar1 + 1) {
      iVar2 = (*DAT_001c1140)(iVar1);
      local_4 = (int *)0x0;
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x7c) != 0)) {
        local_4 = *(int **)(iVar2 + 0x7c);
      }
      if (local_4 != (int *)0x0) {
        (*DAT_001c10d8)(1,gmsgTeamInfo,0,*(undefined4 *)(*param_2 + 0x208));
        uVar3 = (*DAT_001c113c)(*(undefined4 *)(*local_4 + 0x208));
        (*DAT_001c10e0)(uVar3);
        uVar3 = (**(code **)(*g_pGameRules + 0xcc))(g_pGameRules,local_4);
        (*DAT_001c10f8)(uVar3);
        (*DAT_001c10dc)();
      }
    }
  }
  return;
}


// InitHUD__18CHalfLifeMultiplayP11CBasePlayer  @ 000aed5c
void InitHUD__18CHalfLifeMultiplayP11CBasePlayer(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  
  pcVar3 = "unconnected";
  if (*(int *)(*param_2 + 0x1d0) != 0) {
    iVar5 = *(int *)(*param_2 + 0x1d0);
    if (*(char *)(iVar5 + (int)gpGlobals[0x26]) != '\0') {
      pcVar3 = (char *)(iVar5 + (int)gpGlobals[0x26]);
    }
  }
  UTIL_ClientPrintAll__FiPCcN41(1,"#Game_playerjoin",pcVar3,0,0,0);
  (**(code **)(*param_1 + 0x40))(param_1,param_2);
  param_2[0x307] = (int)(*gpGlobals + 0.1);
  (*DAT_001c10d8)(1,gmsgScoreInfo,0,*(undefined4 *)(*param_2 + 0x208));
  uVar1 = (*DAT_001c113c)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_001c10e0)(uVar1);
  (*DAT_001c10e8)(0);
  (*DAT_001c10e8)(0);
  (*DAT_001c10e8)(0);
  (*DAT_001c10e8)(0);
  (*DAT_001c10dc)();
  for (iVar5 = 1; iVar5 <= (int)gpGlobals[0x24]; iVar5 = iVar5 + 1) {
    iVar2 = (*DAT_001c1140)(iVar5);
    piVar4 = (int *)0x0;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x7c) != 0)) {
      piVar4 = *(int **)(iVar2 + 0x7c);
    }
    if (piVar4 != (int *)0x0) {
      (*DAT_001c10d8)(1,gmsgScoreInfo,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_001c10e0)(iVar5);
      (*DAT_001c10e8)((int)ROUND(*(float *)(*piVar4 + 0x164)));
      (*DAT_001c10e8)(piVar4[0x275]);
      (*DAT_001c10e8)(*(undefined4 *)(*piVar4 + 0x20c));
      (*DAT_001c10e8)(*(undefined4 *)(*piVar4 + 0x1ac));
      (*DAT_001c10dc)();
      (*DAT_001c10d8)(1,gmsgSpectator,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_001c10e0)(iVar5);
      (*DAT_001c10e0)(*(int *)(*piVar4 + 0x244) != 0);
      (*DAT_001c10dc)();
    }
  }
  if (g_fGameOver != 0) {
    (*DAT_001c10d8)(1,0x1e,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10dc)();
  }
  return;
}


