// ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc  @ 000b8960
void ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc  @ 000f5090
void ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc
               (undefined4 param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  TeamFortress_SetSkin__11CBasePlayer(param_2);
  *(undefined4 *)(param_2 + 0xfc) = 0;
  pcVar1 = (char *)(*DAT_0017566c)(param_3,&DAT_0013f71f);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    pcVar1 = (char *)(*DAT_0017566c)(param_3,"exec_class");
  }
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    iVar2 = 2;
    bVar5 = true;
    pcVar3 = pcVar1;
    pcVar4 = "1";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 3;
      bVar5 = true;
      pcVar3 = "on";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar1 == *pcVar3;
        pcVar1 = pcVar1 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar5);
      if (!bVar5) goto LAB_000f511b;
    }
    *(undefined4 *)(param_2 + 0xfc) = 1;
  }
LAB_000f511b:
  *(undefined4 *)(param_2 + 0x100) = 0;
  pcVar1 = (char *)(*DAT_0017566c)(param_3,&DAT_0013f732);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    (*DAT_0017566c)(param_3,"exec_map");
  }
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    iVar2 = 2;
    bVar5 = true;
    pcVar3 = pcVar1;
    pcVar4 = "1";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 3;
      bVar5 = true;
      pcVar3 = "on";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar1 == *pcVar3;
        pcVar1 = pcVar1 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar5);
      if (!bVar5) goto LAB_000f5195;
    }
    *(undefined4 *)(param_2 + 0x100) = 1;
  }
LAB_000f5195:
  *(undefined4 *)(param_2 + 0x104) = 1;
  pcVar1 = (char *)(*DAT_0017566c)(param_3,&DAT_0013f73e);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    iVar2 = 2;
    bVar5 = true;
    pcVar3 = pcVar1;
    pcVar4 = "0";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 4;
      bVar5 = true;
      pcVar3 = "off";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar1 == *pcVar3;
        pcVar1 = pcVar1 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar5);
      if (!bVar5) goto LAB_000f51f3;
    }
    *(undefined4 *)(param_2 + 0x104) = 0;
  }
LAB_000f51f3:
  *(undefined4 *)(param_2 + 0x108) = 0;
  pcVar1 = (char *)(*DAT_0017566c)(param_3,"take_sshot");
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    pcVar1 = (char *)(*DAT_0017566c)(param_3,&DAT_0013f752);
  }
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    iVar2 = 2;
    bVar5 = true;
    pcVar3 = pcVar1;
    pcVar4 = "1";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 3;
      bVar5 = true;
      pcVar3 = "on";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar1 == *pcVar3;
        pcVar1 = pcVar1 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar5);
      if (!bVar5) {
        return;
      }
    }
    *(undefined4 *)(param_2 + 0x108) = 1;
  }
  return;
}


// ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc  @ 000f36f0
void ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__FP7edict_sPc  @ 000a3020
void ClientUserInfoChanged__FP7edict_sPc(int param_1,undefined4 param_2)

{
  char *__s2;
  int iVar1;
  undefined4 uVar2;
  char local_104 [256];
  
  iVar1 = gpGlobals;
  if (*(int *)(param_1 + 0xd8) != 0) {
    if ((*(int *)(param_1 + 0x28c) != 0) &&
       (*(char *)(*(int *)(param_1 + 0x28c) + *(int *)(gpGlobals + 0x98)) != '\0')) {
      __s2 = (char *)(*DAT_0017566c)(param_2,&DAT_0012c7dd);
      iVar1 = strcmp((char *)(*(int *)(param_1 + 0x28c) + *(int *)(iVar1 + 0x98)),__s2);
      if (iVar1 != 0) {
        uVar2 = (*DAT_0017566c)(param_2,&DAT_0012c7dd);
        sprintf(local_104,"* %s changed name to %s\n",
                *(int *)(param_1 + 0x28c) + *(int *)(gpGlobals + 0x98),uVar2);
        (*DAT_00175578)(2,gmsgSayText,0,0);
        uVar2 = (*DAT_001755dc)(param_1);
        (*DAT_00175580)(uVar2);
        (*DAT_00175598)(local_104);
        (*DAT_0017557c)();
        uVar2 = (*DAT_00175684)(param_1);
        uVar2 = (*DAT_0017566c)(param_2,&DAT_0012c7dd,uVar2);
        uVar2 = (*DAT_00175684)(param_1,uVar2);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" changed name to \"%s<%i>\"\n",
                   *(int *)(param_1 + 0x28c) + *(int *)(gpGlobals + 0x98),uVar2);
      }
    }
    iVar1 = *g_pGameRules;
    uVar2 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1 + 0xdc,param_2);
    (**(code **)(iVar1 + 0x6c))(g_pGameRules,uVar2);
  }
  return;
}


