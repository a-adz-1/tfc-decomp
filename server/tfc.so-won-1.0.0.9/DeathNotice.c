// DeathNotice__11CBaseEntityP9entvars_t  @ 0010e520
void DeathNotice__11CBaseEntityP9entvars_t(void)

{
  return;
}


// DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_tT2  @ 000b7070
void DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_tT2(void)

{
  return;
}


// DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_tT2  @ 000f3700
void DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_tT2
               (int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 != 0) {
    if (param_1[3] != 0) {
      return;
    }
    if (((param_2 != (int *)0x0) && (param_3 != 0)) && ((*(byte *)(param_3 + 0x184) & 8) != 0)) {
      iVar1 = *(int *)(param_3 + 0x1e8);
      if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = *(int **)(iVar1 + 0xd8);
      }
      if (((piVar3 != (int *)0x0) && (piVar3 != param_2)) &&
         (iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_2,piVar3), iVar1 == 1)) {
        (*DAT_00175578)(2,gmsgDeathMsg,0,0);
        uVar2 = (*DAT_001755dc)(*(undefined4 *)(param_3 + 0x1e8));
        (*DAT_00175580)(uVar2);
        uVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_2 + 0x1e8));
        (*DAT_00175580)(uVar2);
        (*DAT_00175598)("teammate");
        (*DAT_0017557c)();
        uVar2 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
        uVar2 = (*DAT_00175684)(*(undefined4 *)(param_3 + 0x1e8),
                                *(int *)(*param_2 + 0x1b0) + *(int *)(gpGlobals + 0x98),uVar2);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" killed (teammate) \"%s<%i>\"\n",
                   *(int *)(param_3 + 0x1b0) + *(int *)(gpGlobals + 0x98),uVar2);
        return;
      }
    }
  }
  DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_tT2(param_1,param_2,param_3,param_4);
  return;
}


// DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_tT2  @ 000b7d60
void DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_tT2
               (undefined4 param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 local_34;
  undefined1 local_30 [24];
  char *local_18;
  
  if (param_3[0x7a] == 0) {
    (*DAT_001755d4)(0);
  }
  pcVar3 = "world";
  local_34 = 0;
  if ((*(byte *)(param_3 + 0x61) & 8) == 0) {
    iVar1 = param_4[0x7a];
    if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xd8);
    }
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x36c) == 0)) {
LAB_000b7f10:
      iVar1 = *param_4;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x36c);
    }
  }
  else {
    local_34 = (*DAT_001755dc)(param_3[0x7a]);
    if (param_4 == (int *)0x0) goto LAB_000b7f20;
    if (param_4 == param_3) {
      iVar1 = param_3[0x7a];
      if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0xd8);
      }
      if (*(int *)(iVar1 + 0x830) == 0) goto LAB_000b7f20;
      if (*(int *)(*(int *)(iVar1 + 0x830) + 0x36c) == 0) {
        iVar1 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x830) + 0x3c8) + 0x110))
                          (*(undefined4 *)(iVar1 + 0x830),local_30);
        if (iVar1 != 0) {
          pcVar3 = local_18;
        }
        goto LAB_000b7f20;
      }
      iVar1 = *(int *)(*(int *)(iVar1 + 0x830) + 0x36c);
    }
    else {
      iVar1 = param_4[0x7a];
      if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0xd8);
      }
      if ((iVar1 == 0) || (*(int *)(iVar1 + 0x36c) == 0)) goto LAB_000b7f10;
      iVar1 = *(int *)(iVar1 + 0x36c);
    }
  }
  pcVar3 = (char *)(*(int *)(gpGlobals + 0x98) + iVar1);
LAB_000b7f20:
  iVar1 = strncmp(pcVar3,"weapon_",7);
  if (iVar1 == 0) {
    pcVar3 = pcVar3 + 7;
  }
  else {
    iVar1 = strncmp(pcVar3,"tf_weapon_",10);
    if (iVar1 == 0) {
      pcVar3 = pcVar3 + 10;
    }
    else {
      iVar1 = strncmp(pcVar3,"monster_",8);
      if (iVar1 == 0) {
        pcVar3 = pcVar3 + 8;
      }
      else {
        iVar1 = strncmp(pcVar3,"func_",5);
        if (iVar1 == 0) {
          pcVar3 = pcVar3 + 5;
        }
      }
    }
  }
  (*DAT_00175578)(2,gmsgDeathMsg,0,0);
  (*DAT_00175580)(local_34);
  uVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_2 + 0x1e8));
  (*DAT_00175580)(uVar2);
  (*DAT_00175598)(pcVar3);
  (*DAT_0017557c)();
  if ((int *)*param_2 == param_3) {
    uVar2 = (*DAT_00175684)(param_3[0x7a],pcVar3);
    iVar1 = *(int *)(*param_2 + 0x1b0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = "\"%s<%i>\" killed self with \"%s\"\n";
  }
  else {
    if ((*(byte *)(param_3 + 0x61) & 8) != 0) {
      uVar2 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8),pcVar3);
      uVar2 = (*DAT_00175684)(param_3[0x7a],*(int *)(*param_2 + 0x1b0) + *(int *)(gpGlobals + 0x98),
                              uVar2);
      UTIL_LogPrintf__FPce(FUN_00131ea0,param_3[0x6c] + *(int *)(gpGlobals + 0x98),uVar2);
      return;
    }
    uVar2 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8),pcVar3);
    iVar1 = *(int *)(*param_2 + 0x1b0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = (char *)FUN_00131ee0;
  }
  UTIL_LogPrintf__FPce(pcVar3,iVar1,uVar2);
  return;
}


