// UpdateGameMode__10CGameRulesP11CBasePlayer  @ 000b0368
void UpdateGameMode__10CGameRulesP11CBasePlayer(void)

{
  return;
}


// UpdateGameMode__17CHalfLifeTeamplayP11CBasePlayer  @ 000f9b1c
void UpdateGameMode__17CHalfLifeTeamplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
  }
  else {
    (*DAT_0019f758)(1,gmsgGameMode,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(1);
    (*DAT_0019f75c)();
  }
  return;
}


// UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer  @ 000afc08
void UpdateGameMode__18CHalfLifeMultiplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  (*DAT_0019f758)(1,gmsgGameMode,0,*(undefined4 *)(*param_2 + 0x208));
  (*DAT_0019f760)(0);
  (*DAT_0019f75c)();
  return;
}


