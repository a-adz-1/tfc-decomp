// GetTeamID__13CTeamFortressP11CBaseEntity  @ 000f5320
void GetTeamID__13CTeamFortressP11CBaseEntity(undefined4 param_1,int param_2)

{
  GetTeamName__Fi(*(undefined4 *)(param_2 + 0x120));
  return;
}


// GetTeamID__14CHalfLifeRulesP11CBaseEntity  @ 000b88d0
undefined * GetTeamID__14CHalfLifeRulesP11CBaseEntity(void)

{
  return &DAT_00131cc6;
}


// GetTeamID__17CHalfLifeTeamplayP11CBaseEntity  @ 000f3b30
undefined * GetTeamID__17CHalfLifeTeamplayP11CBaseEntity(void)

{
  (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  return &DAT_0013f106;
}


// GetTeamID__18CHalfLifeMultiplayP11CBaseEntity  @ 000b8890
undefined * GetTeamID__18CHalfLifeMultiplayP11CBaseEntity(void)

{
  return &DAT_00131cc6;
}


