// ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc  @ 000b0330
void ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc  @ 000fb754
void ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc(void)

{
  FUN_000fb762();
  return;
}


// ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc  @ 000f9b14
void ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__FP7edict_sPc  @ 000915b8
void ClientUserInfoChanged__FP7edict_sPc(int param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char local_204 [256];
  char local_104 [255];
  undefined1 local_5;
  
  iVar2 = gpGlobals;
  if (*(int *)(param_1 + 0x7c) == 0) {
    return;
  }
  if ((*(int *)(param_1 + 0x250) != 0) &&
     (*(char *)(*(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98)) != '\0')) {
    pcVar1 = (char *)(*DAT_0019f84c)(param_2,&DAT_0014852a);
    iVar2 = strcmp((char *)(*(int *)(param_1 + 0x250) + *(int *)(iVar2 + 0x98)),pcVar1);
    if (iVar2 != 0) {
      pcVar1 = (char *)(*DAT_0019f84c)(param_2,&DAT_0014852a);
      strncpy(local_104,pcVar1,0xff);
      local_5 = 0;
      pcVar1 = local_104;
      do {
        if (*pcVar1 == '\0') break;
        if (*pcVar1 == '%') {
          *pcVar1 = ' ';
        }
        pcVar1 = pcVar1 + 1;
      } while (pcVar1 != (char *)0x0);
      uVar3 = (*DAT_0019f7bc)(param_1,param_2,&DAT_0014852a,local_104);
      (*DAT_0019f854)(uVar3);
      uVar3 = (*DAT_0019f84c)(param_2,&DAT_0014852a);
      sprintf(local_204,"* %s changed name to %s\n",
              *(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98),uVar3);
      (*DAT_0019f758)(2,gmsgSayText,0,0);
      uVar3 = (*DAT_0019f7bc)(param_1);
      (*DAT_0019f760)(uVar3);
      (*DAT_0019f778)(local_204);
      (*DAT_0019f75c)();
      iVar2 = param_1;
      if ((param_1 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      uVar3 = (*DAT_0019f84c)(param_2,&DAT_0014852a);
      if (*(int *)(iVar2 + 0x120) == 0) {
        pcVar1 = "SPECTATOR";
      }
      else {
        pcVar1 = (char *)GetTeamName__Fi(*(int *)(iVar2 + 0x120),uVar3);
      }
      uVar3 = (*DAT_0019f8dc)(param_1,pcVar1);
      uVar3 = (*DAT_0019f864)(param_1,uVar3);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" changed name to \"%s\"\n",
                 *(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98),uVar3);
    }
  }
  iVar2 = *g_pGameRules;
  uVar3 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1 + 0x80,param_2);
  (**(code **)(iVar2 + 0x6c))(g_pGameRules,uVar3);
  return;
}


