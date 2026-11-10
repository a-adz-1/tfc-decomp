// DeathNotice__11CBaseEntityP9entvars_s  @ 00100720
void DeathNotice__11CBaseEntityP9entvars_s(void)

{
  return;
}


// DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2  @ 000a397c
void DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2(void)

{
  return;
}


// DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2  @ 000ea4e4
void DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2
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
    if (((param_2 != (int *)0x0) && (param_3 != 0)) && ((*(byte *)(param_3 + 0x1a4) & 8) != 0)) {
      iVar1 = *(int *)(param_3 + 0x208);
      if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = *(int **)(iVar1 + 0x7c);
      }
      if (((piVar3 != (int *)0x0) && (piVar3 != param_2)) &&
         (iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_2,piVar3), iVar1 == 1)) {
        (*DAT_001a7ef8)(2,gmsgDeathMsg,0,0);
        uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(param_3 + 0x208));
        (*DAT_001a7f00)(uVar2);
        uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_2 + 0x208));
        (*DAT_001a7f00)(uVar2);
        (*DAT_001a7f18)("teammate");
        (*DAT_001a7efc)();
        uVar2 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        uVar2 = (*DAT_001a8004)(*(undefined4 *)(param_3 + 0x208),
                                *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar2);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" killed (teammate) \"%s<%i>\"\n",
                   *(int *)(param_3 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar2);
        if (param_2[0x75] != 0) {
          return;
        }
        piVar3[0x7e] = piVar3[0x7e] + 1;
        CheckAutoKick__11CBasePlayer(piVar3);
        return;
      }
    }
  }
  DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2(param_1,param_2,param_3,param_4);
  return;
}


// DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2  @ 000a484c
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
    (*DAT_001a7f54)(0);
  }
  pcVar3 = "world";
  local_30 = 0;
  if ((*(byte *)(param_3 + 0x69) & 8) == 0) {
    iVar1 = param_4[0x82];
    if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x7c);
    }
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x378) == 0)) {
LAB_000a49f0:
      iVar1 = *param_4;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x378);
    }
  }
  else {
    local_30 = (*DAT_001a7f5c)(param_3[0x82]);
    if (param_4 == (int *)0x0) goto LAB_000a4a02;
    if (param_4 == param_3) {
      iVar1 = param_3[0x82];
      if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if (*(int *)(iVar1 + 0x844) == 0) goto LAB_000a4a02;
      if (*(int *)(*(int *)(iVar1 + 0x844) + 0x378) == 0) {
        iVar1 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x844) + 0x3d4) + 0x110))
                          (*(undefined4 *)(iVar1 + 0x844),local_2c);
        if (iVar1 != 0) {
          pcVar3 = local_14;
        }
        goto LAB_000a4a02;
      }
      iVar1 = *(int *)(*(int *)(iVar1 + 0x844) + 0x378);
    }
    else {
      iVar1 = param_4[0x82];
      if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if ((iVar1 == 0) || (*(int *)(iVar1 + 0x378) == 0)) goto LAB_000a49f0;
      iVar1 = *(int *)(iVar1 + 0x378);
    }
  }
  pcVar3 = (char *)(*(int *)(gpGlobals + 0x98) + iVar1);
LAB_000a4a02:
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
  (*DAT_001a7ef8)(2,gmsgDeathMsg,0,0);
  (*DAT_001a7f00)(local_30);
  uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_001a7f00)(uVar2);
  (*DAT_001a7f18)(pcVar3);
  (*DAT_001a7efc)();
  if ((int *)*param_2 == param_3) {
    uVar2 = (*DAT_001a8004)(param_3[0x82],pcVar3);
    iVar1 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = "\"%s<%i>\" killed self with \"%s\"\n";
  }
  else {
    if ((*(byte *)(param_3 + 0x69) & 8) != 0) {
      uVar2 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
      uVar2 = (*DAT_001a8004)(param_3[0x82],*(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                              uVar2);
      UTIL_LogPrintf__FPce
                ("\"%s<%i>\" killed \"%s<%i>\" with \"%s\"\n",
                 param_3[0x74] + *(int *)(gpGlobals + 0x98),uVar2);
      return;
    }
    uVar2 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
    iVar1 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar3 = "\"%s<%i>\" killed by world with \"%s\"\n";
  }
  UTIL_LogPrintf__FPce(pcVar3,iVar1,uVar2);
  return;
}


