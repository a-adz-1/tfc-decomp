// PlayerSpawn__13CTeamFortressP11CBasePlayer  @ 000ec304
void PlayerSpawn__13CTeamFortressP11CBasePlayer(undefined4 param_1,int *param_2)

{
  *(byte *)(*param_2 + 0x16b) = *(byte *)(*param_2 + 0x16b) | 0x80;
  return;
}


// PlayerSpawn__14CHalfLifeRulesP11CBasePlayer  @ 000a3924
void PlayerSpawn__14CHalfLifeRulesP11CBasePlayer(void)

{
  return;
}


// PlayerSpawn__17CHalfLifeTeamplayP11CBasePlayer  @ 000ea298
void PlayerSpawn__17CHalfLifeTeamplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    PlayerSpawn__18CHalfLifeMultiplayP11CBasePlayer(param_1,param_2);
  }
  else {
    *(byte *)(*param_2 + 0x16b) = *(byte *)(*param_2 + 0x16b) | 0x80;
  }
  return;
}


// PlayerSpawn__18CHalfLifeMultiplayP11CBasePlayer  @ 000a4678
void PlayerSpawn__18CHalfLifeMultiplayP11CBasePlayer(undefined4 param_1,int *param_2)

{
  *(byte *)(*param_2 + 0x16b) = *(byte *)(*param_2 + 0x16b) | 0x80;
  GiveNamedItem__11CBasePlayerPc(param_2,"weapon_crowbar");
  GiveNamedItem__11CBasePlayerPc(param_2,"weapon_9mmhandgun");
  (**(code **)(param_2[0xf5] + 0x60))(param_2,0x44,&DAT_00135fc1,0xfa,0);
  return;
}


