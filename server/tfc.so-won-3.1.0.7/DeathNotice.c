// DeathNotice__11CBaseEntityP9entvars_s  @ 0010fa28
void DeathNotice__11CBaseEntityP9entvars_s(void)

{
  return;
}


// DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2  @ 000ae4b4
void DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2(void)

{
  return;
}


// DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2  @ 000f71e0
void DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2
               (int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 local_20 [32];
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 != 0) {
    if (param_1[4] != 0) {
      return;
    }
    if (((param_2 != (int *)0x0) && (param_3 != 0)) && ((*(byte *)(param_3 + 0x1a4) & 8) != 0)) {
      iVar1 = *(int *)(param_3 + 0x208);
      if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = *(int **)(iVar1 + 0x7c);
      }
      if (((piVar2 != (int *)0x0) && (piVar2 != param_2)) &&
         (iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_2,piVar2), iVar1 == 1)) {
        (*DAT_001c10d8)(2,gmsgDeathMsg,0,0);
        uVar3 = (*DAT_001c113c)(*(undefined4 *)(param_3 + 0x208));
        (*DAT_001c10e0)(uVar3);
        uVar3 = (*DAT_001c113c)(*(undefined4 *)(*param_2 + 0x208));
        (*DAT_001c10e0)(uVar3);
        (*DAT_001c10f8)("teammate");
        (*DAT_001c10dc)();
        GetWeapon__FP9entvars_sT0Pc(param_4,param_3,local_20);
        iVar1 = *(int *)(param_3 + 0x208);
        if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(iVar1 + 0x7c);
        }
        if (param_2[0x48] == 0) {
          pcVar4 = "SPECTATOR";
        }
        else {
          pcVar4 = (char *)GetTeamName__Fi(param_2[0x48],local_20);
        }
        uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar4);
        uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar3);
        if (*(int *)(iVar1 + 0x120) == 0) {
          pcVar4 = "SPECTATOR";
        }
        else {
          pcVar4 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120),
                                           *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                           uVar3);
        }
        uVar3 = (*DAT_001c11f4)(*(undefined4 *)(param_3 + 0x208),pcVar4);
        uVar3 = (*DAT_001c11e4)(*(undefined4 *)(param_3 + 0x208),uVar3);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%u><%s>\" killed \"%s<%i><%u><%s>\" with \"%s\"\n",
                   *(int *)(param_3 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3);
        if (param_2[0x75] != 0) {
          return;
        }
        piVar2[0x7e] = piVar2[0x7e] + 1;
        CheckAutoKick__11CBasePlayer(piVar2);
        return;
      }
    }
  }
  DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2(param_1,param_2,param_3,param_4);
  return;
}


// DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2  @ 000af470
void DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2
               (undefined4 param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 local_30;
  undefined1 local_2c [24];
  char *local_14;
  
  if (param_3[0x82] == 0) {
    (*DAT_001c1134)(0);
  }
  pcVar3 = "world";
  local_30 = 0;
  if ((*(byte *)(param_3 + 0x69) & 8) == 0) {
    iVar1 = param_4[0x82];
    if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x7c);
    }
    if ((iVar1 == 0) || (*(int *)(iVar1 + 1000) == 0)) {
LAB_000af624:
      iVar1 = *param_4;
    }
    else {
      iVar1 = *(int *)(iVar1 + 1000);
    }
  }
  else {
    local_30 = (*DAT_001c113c)(param_3[0x82]);
    if (param_4 == (int *)0x0) goto LAB_000af636;
    if (param_4 == param_3) {
      iVar1 = param_3[0x82];
      if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if (*(int *)(iVar1 + 0x8b4) == 0) goto LAB_000af636;
      if (*(int *)(*(int *)(iVar1 + 0x8b4) + 1000) == 0) {
        iVar1 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x8b4) + 0x444) + 0x118))
                          (*(undefined4 *)(iVar1 + 0x8b4),local_2c);
        if (iVar1 != 0) {
          pcVar3 = local_14;
        }
        goto LAB_000af636;
      }
      iVar1 = *(int *)(*(int *)(iVar1 + 0x8b4) + 1000);
    }
    else {
      iVar1 = param_4[0x82];
      if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if ((iVar1 == 0) || (*(int *)(iVar1 + 1000) == 0)) goto LAB_000af624;
      iVar1 = *(int *)(iVar1 + 1000);
    }
  }
  pcVar3 = (char *)(*(int *)(gpGlobals + 0x98) + iVar1);
LAB_000af636:
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
  (*DAT_001c10d8)(2,gmsgDeathMsg,0,0);
  (*DAT_001c10e0)(local_30);
  uVar2 = (*DAT_001c113c)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_001c10e0)(uVar2);
  (*DAT_001c10f8)(pcVar3);
  (*DAT_001c10dc)();
  if ((int *)*param_2 == param_3) {
    if (param_2[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],pcVar3);
    }
    uVar2 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
    uVar2 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar2);
    iVar1 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = "\"%s<%i><%u><%s>\" committed suicide with \"%s\"\n";
  }
  else {
    if ((*(byte *)(param_3 + 0x69) & 8) != 0) {
      iVar1 = param_3[0x82];
      if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if (param_2[0x48] == 0) {
        pcVar3 = "SPECTATOR";
      }
      else {
        pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],pcVar3);
      }
      uVar2 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
      uVar2 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar2);
      if (*(int *)(iVar1 + 0x120) == 0) {
        pcVar3 = "SPECTATOR";
      }
      else {
        pcVar3 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                         uVar2);
      }
      uVar2 = (*DAT_001c11f4)(param_3[0x82],pcVar3);
      uVar2 = (*DAT_001c11e4)(param_3[0x82],uVar2);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" killed \"%s<%i><%u><%s>\" with \"%s\"\n",
                 param_3[0x74] + *(int *)(gpGlobals + 0x98),uVar2);
      return;
    }
    if (param_2[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],pcVar3);
    }
    uVar2 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
    uVar2 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar2);
    iVar1 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = "\"%s<%i><%u><%s>\" committed suicide with \"%s\" (world)\n";
  }
  UTIL_LogPrintf__FPce(pcVar3,iVar1,uVar2);
  return;
}


