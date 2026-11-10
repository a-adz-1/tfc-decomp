// IPointsForKill__14CHalfLifeRulesP11CBasePlayerT1  @ 000a3970
undefined4 IPointsForKill__14CHalfLifeRulesP11CBasePlayerT1(void)

{
  return 1;
}


// IPointsForKill__17CHalfLifeTeamplayP11CBasePlayerT1  @ 000ea934
undefined4 IPointsForKill__17CHalfLifeTeamplayP11CBasePlayerT1(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    uVar2 = IPointsForKill__18CHalfLifeMultiplayP11CBasePlayerT1(param_1,param_2,param_3);
  }
  else if (param_3 == 0) {
    uVar2 = 0;
  }
  else if (param_2 == 0) {
    uVar2 = 1;
  }
  else {
    if ((param_2 != param_3) &&
       (iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_2,param_3), iVar1 == 1)) {
      return 0xffffffff;
    }
    uVar2 = 1;
  }
  return uVar2;
}


// IPointsForKill__18CHalfLifeMultiplayP11CBasePlayerT1  @ 000a472c
undefined4 IPointsForKill__18CHalfLifeMultiplayP11CBasePlayerT1(void)

{
  return 1;
}


