// ShouldAutoAim__10CGameRulesP11CBasePlayerP7edict_s  @ 000b0350
undefined4 ShouldAutoAim__10CGameRulesP11CBasePlayerP7edict_s(void)

{
  return 1;
}


// ShouldAutoAim__17CHalfLifeTeamplayP11CBasePlayerP7edict_s  @ 000f9970
undefined4
ShouldAutoAim__17CHalfLifeTeamplayP11CBasePlayerP7edict_s
          (int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 != 0) {
    if ((param_3 == 0) && (param_3 = (*DAT_0019f7b4)(0), param_3 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_3 + 0x7c);
    }
    if (((iVar1 != 0) && (iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x2c))(iVar1), iVar2 == 2))
       && (iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_2,iVar1), iVar1 == 1)) {
      return 0;
    }
  }
  return 1;
}


