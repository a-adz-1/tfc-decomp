// PlayerRelationship__14CHalfLifeRulesP11CBasePlayerP11CBaseEntity  @ 000afe60
undefined4 PlayerRelationship__14CHalfLifeRulesP11CBasePlayerP11CBaseEntity(void)

{
  return 0;
}


// PlayerRelationship__17CHalfLifeTeamplayP11CBasePlayerP11CBaseEntity  @ 000f97e8
undefined4
PlayerRelationship__17CHalfLifeTeamplayP11CBasePlayerP11CBaseEntity
          (int *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *__s1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 == 0) {
    uVar2 = PlayerRelationship__18CHalfLifeMultiplayP11CBasePlayerP11CBaseEntity
                      (param_1,param_2,param_3);
  }
  else {
    if (((param_2 != 0) && (param_3 != (int *)0x0)) && ((*(byte *)(*param_3 + 0x1a4) & 8) != 0)) {
      pcVar3 = (char *)(**(code **)(*param_1 + 0xcc))(param_1,param_2);
      if ((*pcVar3 != '\0') &&
         (pcVar3 = (char *)(**(code **)(*param_1 + 0xcc))(param_1,param_3), *pcVar3 != '\0')) {
        pcVar3 = (char *)(**(code **)(*param_1 + 0xcc))(param_1,param_3);
        __s1 = (char *)(**(code **)(*param_1 + 0xcc))(param_1,param_2);
        iVar1 = strcasecmp(__s1,pcVar3);
        if (iVar1 == 0) {
          return 1;
        }
      }
      iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_2,param_3);
      if (iVar1 != 0) {
        return 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// PlayerRelationship__18CHalfLifeMultiplayP11CBasePlayerP11CBaseEntity  @ 000af7ac
undefined4 PlayerRelationship__18CHalfLifeMultiplayP11CBasePlayerP11CBaseEntity(void)

{
  return 0;
}


