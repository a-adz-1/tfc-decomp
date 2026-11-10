// GetTeamID__13CTeamFortressP11CBaseEntity  @ 000ec828
void GetTeamID__13CTeamFortressP11CBaseEntity(undefined4 param_1,int param_2)

{
  GetTeamName__Fi(*(undefined4 *)(param_2 + 0x120));
  return;
}


// GetTeamID__14CHalfLifeRulesP11CBaseEntity  @ 000a5c18
undefined * GetTeamID__14CHalfLifeRulesP11CBaseEntity(void)

{
  return &DAT_00135e06;
}


// GetTeamID__17CHalfLifeTeamplayP11CBaseEntity  @ 000ea9b8
undefined * GetTeamID__17CHalfLifeTeamplayP11CBaseEntity(void)

{
  (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  return &DAT_0013d706;
}


// GetTeamID__18CHalfLifeMultiplayP11CBaseEntity  @ 000a5bbc
undefined * GetTeamID__18CHalfLifeMultiplayP11CBaseEntity(void)

{
  return &DAT_00135e06;
}


