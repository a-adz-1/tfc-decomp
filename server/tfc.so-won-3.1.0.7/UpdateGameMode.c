// UpdateGameMode__10CGameRulesP11CBasePlayer  @ 000b0a38
void UpdateGameMode__10CGameRulesP11CBasePlayer(void)

{
  return;
}


// UpdateGameMode__17CHalfLifeTeamplayP11CBasePlayer  @ 000f701c
void UpdateGameMode__17CHalfLifeTeamplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
  }
  else {
    (*DAT_001c10d8)(1,gmsgGameMode,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(1);
    (*DAT_001c10dc)();
  }
  return;
}


// UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer  @ 000aed00
void UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  (*DAT_001c10d8)(1,gmsgGameMode,0,*(undefined4 *)(*param_2 + 0x208));
  (*DAT_001c10e0)(0);
  (*DAT_001c10dc)();
  return;
}


