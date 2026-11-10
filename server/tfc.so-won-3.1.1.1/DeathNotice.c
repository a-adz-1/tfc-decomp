// DeathNotice__11CBaseEntityP9entvars_s  @ 00112f44
void DeathNotice__11CBaseEntityP9entvars_s(void)

{
  return;
}


// DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2  @ 000affc8
void DeathNotice__14CHalfLifeRulesP11CBasePlayerP9entvars_sT2(void)

{
  return;
}


// DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2  @ 000f952c
void DeathNotice__17CHalfLifeTeamplayP11CBasePlayerP9entvars_sT2
               (int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  int local_28;
  undefined1 local_24 [32];
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (iVar1 != 0) {
    if (param_1[4] != 0) {
      return;
    }
    if (((param_2 != (int *)0x0) && (param_3 != 0)) && ((*(byte *)(param_3 + 0x1a4) & 8) != 0)) {
      iVar1 = *(int *)(param_3 + 0x208);
      if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = *(int **)(iVar1 + 0x7c);
      }
      if (((piVar4 != (int *)0x0) && (piVar4 != param_2)) &&
         (iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_2,piVar4), iVar1 == 1)) {
        (*DAT_0019f758)(2,gmsgDeathMsg,0,0);
        uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(param_3 + 0x208));
        (*DAT_0019f760)(uVar2);
        uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_2 + 0x208));
        (*DAT_0019f760)(uVar2);
        (*DAT_0019f778)("teammate");
        (*DAT_0019f75c)();
        GetWeapon__FP9entvars_sT0Pc(param_4,param_3,local_24);
        iVar1 = *(int *)(param_3 + 0x208);
        if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
          local_28 = 0;
        }
        else {
          local_28 = *(int *)(iVar1 + 0x7c);
        }
        if (param_2[0x48] == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],local_24);
        }
        uVar2 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
        uVar2 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar2);
        if (*(int *)(local_28 + 0x120) == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(*(int *)(local_28 + 0x120),
                                           *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                           uVar2);
        }
        uVar2 = (*DAT_0019f8dc)(*(undefined4 *)(param_3 + 0x208),pcVar3);
        uVar2 = (*DAT_0019f864)(*(undefined4 *)(param_3 + 0x208),uVar2);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                   *(int *)(param_3 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar2);
        if (param_2[0x75] != 0) {
          return;
        }
        piVar4[0x7e] = piVar4[0x7e] + 1;
        CheckAutoKick__11CBasePlayer(piVar4);
        return;
      }
    }
  }
  DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2(param_1,param_2,param_3,param_4);
  return;
}


// DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2  @ 000ae298
void DeathNotice__18CHalfLifeMultiplayP11CBasePlayerP9entvars_sT2
               (undefined4 param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int *local_34;
  undefined1 local_30 [24];
  char *local_18;
  
  if (param_3[0x82] == 0) {
    (*DAT_0019f7b4)(0);
  }
  pcVar4 = "world";
  uVar3 = 0;
  if ((*(byte *)(param_3 + 0x69) & 8) == 0) {
    iVar2 = param_4[0x82];
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x3f8), iVar2 != 0)) goto LAB_000ae414;
LAB_000ae428:
    pcVar4 = (char *)(*param_4 + *(int *)(gpGlobals + 0x98));
  }
  else {
    uVar3 = (*DAT_0019f7bc)(param_3[0x82]);
    if (param_4 != (int *)0x0) {
      if (param_4 == param_3) {
        iVar2 = param_3[0x82];
        if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
          local_34 = (int *)0x0;
        }
        else {
          local_34 = *(int **)(iVar2 + 0x7c);
        }
        iVar1 = *(int *)((int)local_34 + 0x8dc);
        if (iVar1 != 0) {
          iVar2 = *(int *)(iVar1 + 0x3f8);
          if (iVar2 != 0) goto LAB_000ae414;
          iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x118))
                            (*(undefined4 *)((int)local_34 + 0x8dc),local_30);
          if (iVar2 != 0) {
            pcVar4 = local_18;
          }
        }
      }
      else {
        iVar2 = param_4[0x82];
        if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x7c);
        }
        if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0x3f8), iVar2 == 0)) goto LAB_000ae428;
LAB_000ae414:
        pcVar4 = (char *)(*(int *)(gpGlobals + 0x98) + iVar2);
      }
    }
  }
  iVar2 = strncmp(pcVar4,"weapon_",7);
  if (iVar2 == 0) {
    pcVar4 = pcVar4 + 7;
  }
  else {
    iVar2 = strncmp(pcVar4,"tf_weapon_",10);
    if (iVar2 == 0) {
      pcVar4 = pcVar4 + 10;
    }
    else {
      iVar2 = strncmp(pcVar4,"monster_",8);
      if (iVar2 == 0) {
        pcVar4 = pcVar4 + 8;
      }
      else {
        iVar2 = strncmp(pcVar4,"func_",5);
        if (iVar2 == 0) {
          pcVar4 = pcVar4 + 5;
        }
      }
    }
  }
  (*DAT_0019f758)(2,gmsgDeathMsg,0,0);
  (*DAT_0019f760)(uVar3);
  uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_0019f760)(uVar3);
  (*DAT_0019f778)(pcVar4);
  (*DAT_0019f75c)();
  local_34 = (int *)*param_2;
  if (local_34 == param_3) {
    if (param_2[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(param_2[0x48],pcVar4);
      local_34 = (int *)*param_2;
    }
    uVar3 = (*DAT_0019f8dc)(local_34[0x82],pcVar4);
    uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
    iVar2 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar4 = "\"%s<%i><%s><%s>\" committed suicide with \"%s\"\n";
  }
  else {
    if ((*(byte *)(param_3 + 0x69) & 8) != 0) {
      iVar2 = param_3[0x82];
      if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      if (param_2[0x48] == 0) {
        pcVar4 = "SPECTATOR";
      }
      else {
        pcVar4 = (char *)GetTeamName__Fi(param_2[0x48],pcVar4);
      }
      uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar4);
      uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
      if (*(int *)(iVar2 + 0x120) == 0) {
        pcVar4 = "SPECTATOR";
      }
      else {
        pcVar4 = (char *)GetTeamName__Fi(*(int *)(iVar2 + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                         uVar3);
      }
      uVar3 = (*DAT_0019f8dc)(param_3[0x82],pcVar4);
      uVar3 = (*DAT_0019f864)(param_3[0x82],uVar3);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                 param_3[0x74] + *(int *)(gpGlobals + 0x98),uVar3);
      goto LAB_000ae78a;
    }
    if (param_2[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(param_2[0x48],pcVar4);
      local_34 = (int *)*param_2;
    }
    uVar3 = (*DAT_0019f8dc)(local_34[0x82],pcVar4);
    uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
    iVar2 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar4 = "\"%s<%i><%s><%s>\" committed suicide with \"%s\" (world)\n";
  }
  UTIL_LogPrintf__FPce(pcVar4,iVar2,uVar3);
LAB_000ae78a:
  (*DAT_0019f758)(9,0x33,0,0);
  (*DAT_0019f760)(9);
  (*DAT_0019f760)(2);
  uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_0019f768)(uVar3);
  if (param_4 != (int *)0x0) {
    param_3 = param_4;
  }
  uVar3 = (*DAT_0019f7bc)(param_3[0x82]);
  (*DAT_0019f768)(uVar3);
  (*DAT_0019f76c)(0x27);
  (*DAT_0019f75c)();
  return;
}


