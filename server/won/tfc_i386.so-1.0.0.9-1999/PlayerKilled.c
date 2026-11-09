// PlayerKilled__14CHalfLifeRulesP11CBasePlayerP9entvars_tT2  @ 000b7060
void PlayerKilled__14CHalfLifeRulesP11CBasePlayerP9entvars_tT2(void)

{
  return;
}


// PlayerKilled__17CHalfLifeTeamplayP11CBasePlayerP9entvars_tT2  @ 000f3880
void PlayerKilled__17CHalfLifeTeamplayP11CBasePlayerP9entvars_tT2
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x10) == 0)) {
    PlayerKilled__18CHalfLifeMultiplayP11CBasePlayerP9entvars_tT2(param_1,param_2,param_3,param_4);
  }
  return;
}


// PlayerKilled__18CHalfLifeMultiplayP11CBasePlayerP9entvars_tT2  @ 000b7c60
void PlayerKilled__18CHalfLifeMultiplayP11CBasePlayerP9entvars_tT2
               (int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3,param_4);
  param_2[0x253] = param_2[0x253] + 1;
  iVar1 = *(int *)(param_3 + 0x1e8);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 != 0) goto LAB_000b7ca8;
    iVar1 = 0;
  }
  else {
LAB_000b7ca8:
    iVar1 = *(int *)(iVar1 + 0xd8);
  }
  iVar4 = 0;
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x28))(iVar1);
    if (iVar2 == 2) {
      iVar4 = iVar1;
    }
  }
  if ((*param_2 == param_3) || ((*(byte *)(param_3 + 0x184) & 8) == 0)) {
    TF_AddFrags__11CBasePlayeri(param_2,0xffffffff);
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x70))(param_1,iVar4,param_2);
    TF_AddFrags__11CBasePlayeri(iVar4,uVar3);
  }
  iVar1 = *(int *)(param_3 + 0x1e8);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_000b7d32;
    }
  }
  iVar1 = *(int *)(iVar1 + 0xd8);
LAB_000b7d32:
  if (iVar1 != 0) {
    iVar4 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x28))(iVar1);
    if (iVar4 == 2) {
      *(undefined4 *)(iVar1 + 0x980) = *gpGlobals;
    }
  }
  return;
}


