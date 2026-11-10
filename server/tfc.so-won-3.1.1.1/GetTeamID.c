// GetTeamID__13CTeamFortressP11CBaseEntity  @ 000fbb20
void GetTeamID__13CTeamFortressP11CBaseEntity(undefined4 param_1,int param_2)

{
  GetTeamName__Fi(*(undefined4 *)(param_2 + 0x120));
  return;
}


// GetTeamID__14CHalfLifeRulesP11CBaseEntity  @ 000b0290
undefined * GetTeamID__14CHalfLifeRulesP11CBaseEntity(void)

{
  return &DAT_0014bc46;
}


// GetTeamID__17CHalfLifeTeamplayP11CBaseEntity  @ 000f98c0
undefined * GetTeamID__17CHalfLifeTeamplayP11CBaseEntity(void)

{
  (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  return &DAT_00153646;
}


// GetTeamID__18CHalfLifeMultiplayP11CBaseEntity  @ 000b0228
undefined * GetTeamID__18CHalfLifeMultiplayP11CBaseEntity(void)

{
  return &DAT_0014bc46;
}


