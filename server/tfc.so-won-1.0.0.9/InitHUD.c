// InitHUD__13CTeamFortressP11CBasePlayer  @ 000f4fe0
void InitHUD__13CTeamFortressP11CBasePlayer(undefined4 param_1,int *param_2)

{
  float fVar1;
  byte bVar3;
  undefined4 uVar2;
  int iVar4;
  
  InitHUD__17CHalfLifeTeamplayP11CBasePlayer(param_1,param_2);
  uVar2 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
  UTIL_LogPrintf__FPce
            ("\"%s<%i>\" has entered the game\n",
             *(int *)(*param_2 + 0x1b0) + *(int *)(gpGlobals + 0x98),uVar2);
  iVar4 = 1;
  bVar3 = 1.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
          (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8);
  while ((byte)(bVar3 - 1) < 0x40) {
    TeamFortress_TeamIncreaseScore__Fii(iVar4,0);
    iVar4 = iVar4 + 1;
    fVar1 = (float)iVar4;
    bVar3 = fVar1 < number_of_teams |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8);
  }
  TeamFortress_ExecMapScript__11CBasePlayer(param_2);
  MapBriefingThink__11CBasePlayer(param_2);
  return;
}


// InitHUD__14CHalfLifeRulesP11CBasePlayer  @ 000b6fa0
void InitHUD__14CHalfLifeRulesP11CBasePlayer(void)

{
  return;
}


// InitHUD__17CHalfLifeTeamplayP11CBasePlayer  @ 000f3600
void InitHUD__17CHalfLifeTeamplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    InitHUD__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
  }
  else {
    InitHUD__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
    for (iVar1 = 1; iVar1 <= *(int *)(gpGlobals + 0x90); iVar1 = iVar1 + 1) {
      iVar2 = (*DAT_001755e0)(iVar1);
      piVar4 = (int *)0x0;
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0xd8) != 0)) {
        piVar4 = *(int **)(iVar2 + 0xd8);
      }
      if (piVar4 != (int *)0x0) {
        (*DAT_00175578)(1,gmsgTeamInfo,0,*(undefined4 *)(*param_2 + 0x1e8));
        uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar4 + 0x1e8));
        (*DAT_00175580)(uVar3);
        uVar3 = (**(code **)(*g_pGameRules + 0xcc))(g_pGameRules,piVar4);
        (*DAT_00175598)(uVar3);
        (*DAT_0017557c)();
      }
    }
  }
  return;
}


// InitHUD__18CHalfLifeMultiplayP11CBasePlayer  @ 000b76f0
void InitHUD__18CHalfLifeMultiplayP11CBasePlayer(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  
  pcVar3 = "unconnected";
  if (*(int *)(*param_2 + 0x1b0) != 0) {
    iVar5 = *(int *)(*param_2 + 0x1b0);
    if (*(char *)(iVar5 + (int)gpGlobals[0x26]) != '\0') {
      pcVar3 = (char *)(iVar5 + (int)gpGlobals[0x26]);
    }
  }
  UTIL_ClientPrintAll__FiPCcN41(1,"#Game_playerjoin",pcVar3,0,0,0);
  (**(code **)(*param_1 + 0x40))(param_1,param_2);
  param_2[0x2e4] = (int)(*gpGlobals + 0.1);
  (*DAT_00175578)(1,gmsgScoreInfo,0,*(undefined4 *)(*param_2 + 0x1e8));
  uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_2 + 0x1e8));
  (*DAT_00175580)(uVar1);
  (*DAT_00175588)(0);
  (*DAT_00175588)(0);
  (*DAT_0017557c)();
  for (iVar5 = 1; iVar5 <= (int)gpGlobals[0x24]; iVar5 = iVar5 + 1) {
    iVar2 = (*DAT_001755e0)(iVar5);
    piVar4 = (int *)0x0;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0xd8) != 0)) {
      piVar4 = *(int **)(iVar2 + 0xd8);
    }
    if (piVar4 != (int *)0x0) {
      (*DAT_00175578)(1,gmsgScoreInfo,0,*(undefined4 *)(*param_2 + 0x1e8));
      (*DAT_00175580)(iVar5);
      (*DAT_00175588)((int)ROUND(*(float *)(*piVar4 + 0x144)));
      (*DAT_00175588)(piVar4[0x253]);
      (*DAT_0017557c)();
    }
  }
  if (g_fGameOver != 0) {
    (*DAT_00175578)(1,0x1e,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_0017557c)();
  }
  return;
}


