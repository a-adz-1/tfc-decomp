// ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc  @ 000a5ca8
void ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc  @ 000ec530
void ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc
               (undefined4 param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  char *local_4;
  
  TeamFortress_SetSkin__11CBasePlayer(param_2);
  *(undefined4 *)(param_2 + 0xf4) = 0;
  local_4 = (char *)(*DAT_001a7fec)(param_3,&DAT_0013dccc);
  if ((local_4 == (char *)0x0) || (*local_4 == '\0')) {
    local_4 = (char *)(*DAT_001a7fec)(param_3,"exec_class");
  }
  if ((local_4 != (char *)0x0) && (*local_4 != '\0')) {
    iVar2 = 2;
    bVar5 = true;
    pcVar1 = local_4;
    pcVar3 = "1";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar1 == *pcVar3;
      pcVar1 = pcVar1 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 3;
      bVar5 = true;
      pcVar1 = "on";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *local_4 == *pcVar1;
        local_4 = local_4 + 1;
        pcVar1 = pcVar1 + 1;
      } while (bVar5);
      if (!bVar5) goto LAB_000ec5eb;
    }
    *(undefined4 *)(param_2 + 0xf4) = 1;
  }
LAB_000ec5eb:
  *(undefined4 *)(param_2 + 0xf8) = 0;
  pcVar1 = (char *)(*DAT_001a7fec)(param_3,&DAT_0013dcdf);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    (*DAT_001a7fec)(param_3,"exec_map");
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
      if (!bVar5) goto LAB_000ec685;
    }
    *(undefined4 *)(param_2 + 0xf8) = 1;
  }
LAB_000ec685:
  *(undefined4 *)(param_2 + 0xfc) = 0;
  *(undefined4 *)(param_2 + 0x100) = 0;
  local_4 = (char *)(*DAT_001a7fec)(param_3,"take_sshot");
  if ((local_4 == (char *)0x0) || (*local_4 == '\0')) {
    local_4 = (char *)(*DAT_001a7fec)(param_3,&DAT_0013dcf6);
  }
  if ((local_4 != (char *)0x0) && (*local_4 != '\0')) {
    iVar2 = 2;
    bVar5 = true;
    pcVar1 = local_4;
    pcVar3 = "1";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar1 == *pcVar3;
      pcVar1 = pcVar1 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 3;
      bVar5 = true;
      pcVar1 = "on";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *local_4 == *pcVar1;
        local_4 = local_4 + 1;
        pcVar1 = pcVar1 + 1;
      } while (bVar5);
      if (!bVar5) goto LAB_000ec72d;
    }
    *(undefined4 *)(param_2 + 0x100) = 1;
  }
LAB_000ec72d:
  *(undefined4 *)(param_2 + 0x104) = 1;
  pcVar1 = (char *)(*DAT_001a7fec)(param_3,"cl_lb");
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    iVar2 = __strtol_internal(pcVar1,0,10,0);
    *(uint *)(param_2 + 0x104) = (uint)(iVar2 != 0);
  }
  return;
}


// ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc  @ 000ea4e0
void ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__FP7edict_sPc  @ 000898f0
/* WARNING: Removing unreachable block (ram,0x000899ce) */
/* WARNING: Removing unreachable block (ram,0x000899c9) */
/* WARNING: Removing unreachable block (ram,0x000899d3) */
/* WARNING: Removing unreachable block (ram,0x000899dd) */
/* WARNING: Removing unreachable block (ram,0x000899e7) */
/* WARNING: Removing unreachable block (ram,0x000899ef) */
/* WARNING: Removing unreachable block (ram,0x000899f0) */
/* WARNING: Removing unreachable block (ram,0x000899f5) */
/* WARNING: Removing unreachable block (ram,0x000899fa) */
/* WARNING: Removing unreachable block (ram,0x000899fd) */
/* WARNING: Removing unreachable block (ram,0x000899fe) */
/* WARNING: Removing unreachable block (ram,0x00089a03) */
/* WARNING: Removing unreachable block (ram,0x00089a08) */
/* WARNING: Removing unreachable block (ram,0x00089a0b) */
/* WARNING: Removing unreachable block (ram,0x00089a0e) */

void ClientUserInfoChanged__FP7edict_sPc(int param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  char *__src;
  undefined4 uVar3;
  char local_200 [256];
  char local_100 [255];
  undefined1 local_1;
  
  iVar2 = gpGlobals;
  if (*(int *)(param_1 + 0x7c) != 0) {
    if ((*(int *)(param_1 + 0x250) != 0) &&
       (*(char *)(*(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98)) != '\0')) {
      pcVar1 = (char *)(*DAT_001a7fec)(param_2,&DAT_00132c84);
      iVar2 = strcmp((char *)(*(int *)(param_1 + 0x250) + *(int *)(iVar2 + 0x98)),pcVar1);
      if (iVar2 != 0) {
        __src = (char *)(*DAT_001a7fec)(param_2,&DAT_00132c84);
        pcVar1 = local_100;
        strncpy(pcVar1,__src,0xff);
        local_1 = 0;
        do {
          if (*pcVar1 == '\0') break;
          if (*pcVar1 == '%') {
            *pcVar1 = ' ';
          }
          if (pcVar1[1] == '\0') break;
          if (pcVar1[1] == '%') {
            pcVar1[1] = ' ';
          }
          if (pcVar1[2] == '\0') break;
          if (pcVar1[2] == '%') {
            pcVar1[2] = ' ';
          }
          if (pcVar1[3] == '\0') break;
          if (pcVar1[3] == '%') {
            pcVar1[3] = ' ';
          }
          pcVar1 = pcVar1 + 4;
        } while (pcVar1 != (char *)0x0);
        uVar3 = (*DAT_001a7f5c)(param_1,param_2,&DAT_00132c84,local_100);
        (*DAT_001a7ff4)(uVar3);
        uVar3 = (*DAT_001a7fec)(param_2,&DAT_00132c84);
        sprintf(local_200,"* %s changed name to %s\n",
                *(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98),uVar3);
        (*DAT_001a7ef8)(2,gmsgSayText,0,0);
        uVar3 = (*DAT_001a7f5c)(param_1);
        (*DAT_001a7f00)(uVar3);
        (*DAT_001a7f18)(local_200);
        (*DAT_001a7efc)();
        uVar3 = (*DAT_001a8004)(param_1);
        uVar3 = (*DAT_001a7fec)(param_2,&DAT_00132c84,uVar3);
        uVar3 = (*DAT_001a8004)(param_1,uVar3);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" changed name to \"%s<%i>\"\n",
                   *(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98),uVar3);
      }
    }
    iVar2 = *g_pGameRules;
    uVar3 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1 + 0x80,param_2);
    (**(code **)(iVar2 + 0x6c))(g_pGameRules,uVar3);
  }
  return;
}


