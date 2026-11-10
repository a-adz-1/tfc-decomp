// ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc  @ 000b0a18
void ClientUserInfoChanged__10CGameRulesP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc  @ 000f937c
void ClientUserInfoChanged__13CTeamFortressP11CBasePlayerPc
               (undefined4 param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  char *pcVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  bool bVar6;
  code *local_4;
  
  TeamFortress_SetSkin__11CBasePlayer(param_2);
  *(undefined4 *)(param_2 + 0xf4) = 0;
  local_4 = (code *)(*DAT_001c11cc)(param_3,&DAT_0014eb48);
  if ((local_4 == (code *)0x0) || (*local_4 == (code)0x0)) {
    local_4 = (code *)(*DAT_001c11cc)(param_3,"exec_class");
  }
  if ((local_4 != (code *)0x0) && (*local_4 != (code)0x0)) {
    iVar3 = 2;
    bVar6 = true;
    pcVar1 = local_4;
    pcVar4 = (code *)&DAT_0014eb56;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar1 == *pcVar4;
      pcVar1 = pcVar1 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar3 = 3;
      bVar6 = true;
      pcVar1 = FUN_0014eb58;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *local_4 == *pcVar1;
        local_4 = local_4 + 1;
        pcVar1 = pcVar1 + 1;
      } while (bVar6);
      if (!bVar6) goto LAB_000f9437;
    }
    *(undefined4 *)(param_2 + 0xf4) = 1;
  }
LAB_000f9437:
  *(undefined4 *)(param_2 + 0xf8) = 0;
  pcVar1 = (code *)(*DAT_001c11cc)(param_3,&DAT_0014eb5b);
  if ((pcVar1 == (code *)0x0) || (*pcVar1 == (code)0x0)) {
    (*DAT_001c11cc)(param_3,"exec_map");
  }
  if ((pcVar1 != (code *)0x0) && (*pcVar1 != (code)0x0)) {
    iVar3 = 2;
    bVar6 = true;
    pcVar4 = pcVar1;
    pcVar5 = (code *)&DAT_0014eb56;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar3 = 3;
      bVar6 = true;
      pcVar4 = FUN_0014eb58;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar1 == *pcVar4;
        pcVar1 = pcVar1 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar6);
      if (!bVar6) goto LAB_000f94d1;
    }
    *(undefined4 *)(param_2 + 0xf8) = 1;
  }
LAB_000f94d1:
  *(undefined4 *)(param_2 + 0xfc) = 0;
  *(undefined4 *)(param_2 + 0x100) = 0;
  local_4 = (code *)(*DAT_001c11cc)(param_3,"take_sshot");
  if ((local_4 == (code *)0x0) || (*local_4 == (code)0x0)) {
    local_4 = (code *)(*DAT_001c11cc)(param_3,&DAT_0014eb72);
  }
  if ((local_4 != (code *)0x0) && (*local_4 != (code)0x0)) {
    iVar3 = 2;
    bVar6 = true;
    pcVar1 = local_4;
    pcVar4 = (code *)&DAT_0014eb56;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar1 == *pcVar4;
      pcVar1 = pcVar1 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar3 = 3;
      bVar6 = true;
      pcVar1 = FUN_0014eb58;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *local_4 == *pcVar1;
        local_4 = local_4 + 1;
        pcVar1 = pcVar1 + 1;
      } while (bVar6);
      if (!bVar6) goto LAB_000f9579;
    }
    *(undefined4 *)(param_2 + 0x100) = 1;
  }
LAB_000f9579:
  *(undefined4 *)(param_2 + 0x104) = 1;
  pcVar2 = (char *)(*DAT_001c11cc)(param_3,"cl_lb");
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    iVar3 = __strtol_internal(pcVar2,0,10,0);
    *(uint *)(param_2 + 0x104) = (uint)(iVar3 != 0);
  }
  return;
}


// ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc  @ 000f71dc
void ClientUserInfoChanged__17CHalfLifeTeamplayP11CBasePlayerPc(void)

{
  return;
}


// ClientUserInfoChanged__FP7edict_sPc  @ 00091ba4
/* WARNING: Removing unreachable block (ram,0x00091c7b) */
/* WARNING: Removing unreachable block (ram,0x00091c76) */
/* WARNING: Removing unreachable block (ram,0x00091c80) */
/* WARNING: Removing unreachable block (ram,0x00091c8a) */
/* WARNING: Removing unreachable block (ram,0x00091c94) */
/* WARNING: Removing unreachable block (ram,0x00091c9c) */
/* WARNING: Removing unreachable block (ram,0x00091c9d) */
/* WARNING: Removing unreachable block (ram,0x00091ca2) */
/* WARNING: Removing unreachable block (ram,0x00091ca7) */
/* WARNING: Removing unreachable block (ram,0x00091caa) */
/* WARNING: Removing unreachable block (ram,0x00091cab) */
/* WARNING: Removing unreachable block (ram,0x00091cb0) */
/* WARNING: Removing unreachable block (ram,0x00091cb5) */
/* WARNING: Removing unreachable block (ram,0x00091cb8) */

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
      pcVar1 = (char *)(*DAT_001c11cc)(param_2,&DAT_00142de4);
      iVar2 = strcmp((char *)(*(int *)(param_1 + 0x250) + *(int *)(iVar2 + 0x98)),pcVar1);
      if (iVar2 != 0) {
        __src = (char *)(*DAT_001c11cc)(param_2,&DAT_00142de4);
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
        uVar3 = (*DAT_001c113c)(param_1,param_2,&DAT_00142de4,local_100);
        (*DAT_001c11d4)(uVar3);
        uVar3 = (*DAT_001c11cc)(param_2,&DAT_00142de4);
        sprintf(local_200,"* %s changed name to %s\n",
                *(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98),uVar3);
        (*DAT_001c10d8)(2,gmsgSayText,0,0);
        uVar3 = (*DAT_001c113c)(param_1);
        (*DAT_001c10e0)(uVar3);
        (*DAT_001c10f8)(local_200);
        (*DAT_001c10dc)();
        iVar2 = param_1;
        if ((param_1 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x7c);
        }
        uVar3 = (*DAT_001c11cc)(param_2,&DAT_00142de4);
        if (*(int *)(iVar2 + 0x120) == 0) {
          pcVar1 = "SPECTATOR";
        }
        else {
          pcVar1 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar2 + 0x120),uVar3);
        }
        uVar3 = (*DAT_001c11f4)(param_1,pcVar1);
        uVar3 = (*DAT_001c11e4)(param_1,uVar3);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%u><%s>\" changed name to \"%s\"\n",
                   *(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98),uVar3);
      }
    }
    iVar2 = *g_pGameRules;
    uVar3 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1 + 0x80,param_2);
    (**(code **)(iVar2 + 0x6c))(g_pGameRules,uVar3);
  }
  return;
}


