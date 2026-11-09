// UpdateGameMode__10CGameRulesP11CBasePlayer  @ 000b89b0
void UpdateGameMode__10CGameRulesP11CBasePlayer(void)

{
  return;
}


// UpdateGameMode__17CHalfLifeTeamplayP11CBasePlayer  @ 000f3590
void UpdateGameMode__17CHalfLifeTeamplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
  }
  else {
    (*DAT_00175578)(1,gmsgGameMode,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(1);
    (*DAT_0017557c)();
  }
  return;
}


// UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer  @ 000b76b0
void UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  (*DAT_00175578)(1,gmsgGameMode,0,*(undefined4 *)(*param_2 + 0x1e8));
  (*DAT_00175580)(0);
  (*DAT_0017557c)();
  return;
}


