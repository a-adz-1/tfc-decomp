// CHudDeathNotice::MsgFunc_DeathMsg  @ 0008ca70
/* DWARF original prototype: int MsgFunc_DeathMsg(CHudDeathNotice * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall
CHudDeathNotice::MsgFunc_DeathMsg(CHudDeathNotice *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  int victim;
  char *pcVar3;
  char cVar4;
  float *pfVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  undefined1 uVar10;
  byte bVar11;
  longdouble extraout_ST0;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  
  bVar11 = 0;
  piVar1 = &(this->super_CHudBase).m_iFlags;
                    /* Unresolved local var: int killer@[???]
                       Unresolved local var: int victim@[???]
                       Unresolved local var: char[32] killedwith@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * killer_name@[???]
                       Unresolved local var: char * victim_name@[???]
                       Unresolved local var: int spr@[???] */
  *piVar1 = *piVar1 | 1;
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  victim = READ_BYTE();
  local_3c = CONCAT13(local_3c._3_1_,0x5f64);
  pcVar3 = READ_STRING();
  strncat((char *)&local_3c,pcVar3,0x20);
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::DeathMsg(gViewPort,iVar2,victim);
  }
  iVar6 = 0;
  CHudSpectator::DeathMessage(&gHUD.m_Spectator,victim);
  if ((((rgDeathNoticeList[0].iId != 0) && (iVar6 = 1, rgDeathNoticeList[1].iId != 0)) &&
      (iVar6 = 2, rgDeathNoticeList[2].iId != 0)) && (iVar6 = 3, rgDeathNoticeList[3].iId != 0)) {
    memmove(rgDeathNoticeList,rgDeathNoticeList + 1,0x270);
  }
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::GetAllPlayersInfo(gViewPort);
  }
  pcVar3 = g_PlayerInfoList[iVar2].name;
  cVar4 = (char)victim;
  if (pcVar3 == (char *)0x0) {
    rgDeathNoticeList[iVar6].szKiller[0] = '\0';
    if (cVar4 != -1) goto LAB_0008cbd0;
LAB_0008ced0:
    rgDeathNoticeList[iVar6].szVictim[0] = '\0';
    if (cVar4 == -1) {
      rgDeathNoticeList[iVar6].iNonPlayerKill = 1;
      strcpy(rgDeathNoticeList[iVar6].szVictim,(char *)((int)&local_3c + 2));
      goto LAB_0008cc7b;
    }
  }
  else {
    pfVar5 = g_ColorGrey;
    if ((ushort)g_PlayerExtraInfo[iVar2].teamnumber < 5) {
      pfVar5 = *(float **)(CSWTCH_82 + (uint)(ushort)g_PlayerExtraInfo[iVar2].teamnumber * 4);
    }
    rgDeathNoticeList[iVar6].KillerColor = pfVar5;
    strncpy(rgDeathNoticeList[iVar6].szKiller,pcVar3,0x20);
    rgDeathNoticeList[iVar6].szKiller[0x1f] = '\0';
    if (cVar4 == -1) goto LAB_0008ced0;
LAB_0008cbd0:
    pcVar3 = g_PlayerInfoList[victim].name;
    if (pcVar3 == (char *)0x0) goto LAB_0008ced0;
    pfVar5 = g_ColorGrey;
    if ((ushort)g_PlayerExtraInfo[victim].teamnumber < 5) {
      pfVar5 = *(float **)(CSWTCH_82 + (uint)(ushort)g_PlayerExtraInfo[victim].teamnumber * 4);
    }
    rgDeathNoticeList[iVar6].VictimColor = pfVar5;
    strncpy(rgDeathNoticeList[iVar6].szVictim,pcVar3,0x20);
    rgDeathNoticeList[iVar6].szVictim[0x1f] = '\0';
  }
  if ((iVar2 == 0) || (bVar9 = false, iVar2 == victim)) {
    bVar9 = iVar6 * 0x9b == 0;
    rgDeathNoticeList[iVar6].iSuicide = 1;
  }
  iVar2 = 0xb;
  pcVar3 = (char *)&local_3c;
  pcVar7 = "d_teammate";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar9 = *pcVar3 == *pcVar7;
    pcVar3 = pcVar3 + (uint)bVar11 * -2 + 1;
    pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
  } while (bVar9);
  if (bVar9) {
    rgDeathNoticeList[iVar6].iTeamKill = 1;
  }
LAB_0008cc7b:
  iVar2 = CHud::GetSpriteIndex(&gHUD,(char *)&local_3c);
  rgDeathNoticeList[iVar6].iId = iVar2;
  (*gEngfuncs.pfnGetCvarFloat)("hud_deathnotice_time");
  DEATHNOTICE_DISPLAY_TIME = (int)extraout_ST0;
  rgDeathNoticeList[iVar6].flDisplayTime = (float)DEATHNOTICE_DISPLAY_TIME + gHUD.m_flTime;
  if (rgDeathNoticeList[iVar6].iNonPlayerKill != 0) {
    (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar6].szKiller);
    (*gEngfuncs.pfnConsolePrint)(" killed a ");
    (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar6].szVictim);
    (*gEngfuncs.pfnConsolePrint)("\n");
    return 1;
  }
  if (rgDeathNoticeList[iVar6].iSuicide == 0) {
    if (rgDeathNoticeList[iVar6].iTeamKill == 0) {
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar6].szKiller);
      (*gEngfuncs.pfnConsolePrint)(" killed ");
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar6].szVictim);
    }
    else {
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar6].szKiller);
      (*gEngfuncs.pfnConsolePrint)(" killed his teammate ");
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar6].szVictim);
    }
  }
  else {
    uVar10 = rgDeathNoticeList[iVar6].szVictim == (char *)0x0;
    (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar6].szVictim);
    iVar2 = 8;
    pcVar3 = (char *)&local_3c;
    pcVar7 = "d_world";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      uVar10 = *pcVar3 == *pcVar7;
      pcVar3 = pcVar3 + (uint)bVar11 * -2 + 1;
      pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
    } while ((bool)uVar10);
    if ((bool)uVar10) {
      (*gEngfuncs.pfnConsolePrint)(" died");
    }
    else {
      (*gEngfuncs.pfnConsolePrint)(" killed self");
    }
  }
  bVar9 = (char)local_3c == '\r';
  if ('\r' < (char)local_3c) {
    iVar2 = 8;
    pcVar3 = (char *)&local_3c;
    pcVar7 = "d_world";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pcVar3 == *pcVar7;
      pcVar3 = pcVar3 + (uint)bVar11 * -2 + 1;
      pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
    } while (bVar9);
    if ((!bVar9) && (uVar10 = rgDeathNoticeList[iVar6].iTeamKill == 0, (bool)uVar10)) {
      (*gEngfuncs.pfnConsolePrint)(" with ");
      pcVar3 = (char *)((int)&local_3c + 2);
      iVar2 = 5;
      pcVar7 = pcVar3;
      pcVar8 = "egon";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        uVar10 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
      } while ((bool)uVar10);
      if ((bool)uVar10) {
        local_3c = 0x6c675f64;
        local_38 = 0x206e6f75;
        local_34 = 0x6e7567;
      }
      iVar2 = 6;
      pcVar7 = pcVar3;
      pcVar8 = "gauss";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        uVar10 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
      } while ((bool)uVar10);
      if ((bool)uVar10) {
        local_3c = 0x61745f64;
        local_38 = 0x61632075;
        local_34 = 0x6e6f6e6e;
        local_30 = 0;
      }
      (*gEngfuncs.pfnConsolePrint)(pcVar3);
    }
  }
  (*gEngfuncs.pfnConsolePrint)("\n");
  return 1;
}


