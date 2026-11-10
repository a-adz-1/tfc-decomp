// PlayerKilled__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2  @ 000affd0
void PlayerKilled__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2(void)

{
  return;
}


// PlayerKilled__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2  @ 000f9ac4
void PlayerKilled__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x14) == 0)) {
    PlayerKilled__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2(param_1,param_2,param_3,param_4);
  }
  return;
}


// PlayerKilled__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2  @ 000ae174
void PlayerKilled__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2
               (int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3,param_4);
  param_2[0x27f] = param_2[0x27f] + 1;
  local_8 = 0;
  iVar1 = *(int *)(param_3 + 0x208);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 != 0) goto LAB_000ae1d7;
    iVar1 = 0;
  }
  else {
LAB_000ae1d7:
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x2c))(iVar1);
    if (iVar2 == 2) {
      local_8 = iVar1;
    }
  }
  if ((*param_2 == param_3) || ((*(byte *)(param_3 + 0x1a4) & 8) == 0)) {
    TF_AddFrags__11CBasePlayeri(param_2,0xffffffff);
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x70))(param_1,local_8,param_2);
    TF_AddFrags__11CBasePlayeri(local_8,uVar3);
  }
  iVar1 = *(int *)(param_3 + 0x208);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_000ae266;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_000ae266:
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x2c))(iVar1);
    if (iVar2 == 2) {
      *(undefined4 *)(iVar1 + 0xa38) = *gpGlobals;
    }
  }
  return;
}


