// Ghidra decompilation of functions from cl_dll/death.cpp
// 6 functions, ordered by original source line

// __MsgFunc_DeathMsg  @ 000696d0  (line 27)

int __MsgFunc_DeathMsg(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHudDeathNotice::MsgFunc_DeathMsg(&gHUD.m_DeathNotice,pszName,iSize,pbuf);
  return iVar1;
}


// GetClientColor  @ 000690e0  (line 55)

float * GetClientColor(int clientIndex)

{
  float *pfVar1;
  
  pfVar1 = g_ColorGrey;
  if ((ushort)g_PlayerExtraInfo[clientIndex].teamnumber < 5) {
    pfVar1 = *(float **)(CSWTCH_43 + (uint)(ushort)g_PlayerExtraInfo[clientIndex].teamnumber * 4);
  }
  return pfVar1;
}


// CHudDeathNotice::Init  @ 00068cd0  (line 71)

/* DWARF original prototype: int Init(CHudDeathNotice * this) */

int __thiscall CHudDeathNotice::Init(CHudDeathNotice *this)

{
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  (*gEngfuncs.pfnHookUserMsg)("DeathMsg",__MsgFunc_DeathMsg);
  (*gEngfuncs.pfnRegisterVariable)("hud_deathnotice_time","6",1);
  return 1;
}


// CHudDeathNotice::VidInit  @ 00068d30  (line 89)

/* DWARF original prototype: int VidInit(CHudDeathNotice * this) */

int __thiscall CHudDeathNotice::VidInit(CHudDeathNotice *this)

{
  int iVar1;
  
  iVar1 = CHud::GetSpriteIndex(&gHUD,"d_skull");
  this->m_HUD_d_skull = iVar1;
  return 1;
}


// CHudDeathNotice::Draw  @ 00068d60  (line 96)

/* DWARF original prototype: int Draw(CHudDeathNotice * this, float flTime) */

int __thiscall CHudDeathNotice::Draw(CHudDeathNotice *this,float flTime)

{
  char *pcVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  TeamFortressViewport *this_00;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  HANDLE_SPRITE HVar9;
  int iVar10;
  bool bVar11;
  int local_238;
  int local_234;
  SCREENINFO_s local_230;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int texty@[???]
                       Unresolved local var: int gap@[???]
                       Unresolved local var: wrect_t * sprite@[???]
                       Unresolved local var: SCREENINFO screenInfo@[???] */
  local_230.iSize = 0x214;
  iVar7 = gHUD.m_rgrcRects[this->m_HUD_d_skull].bottom - gHUD.m_rgrcRects[this->m_HUD_d_skull].top;
  (*gEngfuncs.pfnGetScreenInfo)(&local_230);
  if (iVar7 <= local_230.iCharHeight) {
    iVar7 = local_230.iCharHeight;
  }
                    /* Unresolved local var: int i@[???] */
  iVar10 = 0;
  do {
    while( true ) {
      this_00 = gViewPort;
      if (rgDeathNoticeList[iVar10].iId == 0) {
        return 1;
      }
      fVar2 = rgDeathNoticeList[iVar10].flDisplayTime;
      if (flTime <= fVar2) break;
      memmove(rgDeathNoticeList + iVar10,rgDeathNoticeList + iVar10 + 1,(4 - iVar10) * 0x9c);
      if (iVar10 == 4) {
        return 1;
      }
    }
    if ((float)DEATHNOTICE_DISPLAY_TIME + gHUD.m_flTime < fVar2) {
      fVar2 = (float)DEATHNOTICE_DISPLAY_TIME + gHUD.m_flTime;
    }
    bVar11 = gViewPort != (TeamFortressViewport *)0x0;
    rgDeathNoticeList[iVar10].flDisplayTime = fVar2;
    if ((bVar11) &&
       (bVar11 = TeamFortressViewport::AllowedToPrintText(this_00), iVar6 = gHUD.m_scrinfo.iWidth,
       bVar11)) {
                    /* Unresolved local var: int id@[???] */
      iVar8 = rgDeathNoticeList[iVar10].iId;
      iVar5 = iVar7 * iVar10 + 0x26;
      if (iVar8 == -1) {
        iVar8 = this->m_HUD_d_skull;
      }
                    /* Unresolved local var: int _width@[???]
                       Unresolved local var: int _height@[???] */
      pcVar1 = (char *)(iVar10 * 0x9c + 0xf88c0);
      (*gEngfuncs.pfnDrawConsoleStringLen)(pcVar1,&local_238,&local_234);
      iVar6 = (((iVar6 - local_238) + gHUD.m_rgrcRects[iVar8].left) - gHUD.m_rgrcRects[iVar8].right)
              + -4;
      if (rgDeathNoticeList[iVar10].iSuicide == 0) {
                    /* Unresolved local var: int _width@[???]
                       Unresolved local var: int _height@[???] */
        (*gEngfuncs.pfnDrawConsoleStringLen)
                  (rgDeathNoticeList[iVar10].szKiller,&local_238,&local_234);
        iVar6 = iVar6 - local_238;
        pfVar3 = rgDeathNoticeList[iVar10].KillerColor;
        if (pfVar3 != (float *)0x0) {
          (*gEngfuncs.pfnDrawSetTextColor)(*pfVar3,pfVar3[1],pfVar3[2]);
        }
        iVar6 = (*gEngfuncs.pfnDrawConsoleString)
                          (iVar6 + -5,iVar5,rgDeathNoticeList[iVar10].szKiller);
        iVar6 = iVar6 + 5;
      }
      if (iVar8 < 0) {
        HVar9 = 0;
      }
      else {
        HVar9 = gHUD.m_rghSprites[iVar8];
      }
      (*gEngfuncs.pfnSPR_Set)
                (HVar9,(SUB14(rgDeathNoticeList[iVar10].iTeamKill == 0,0) * 0xff & 0xf5U) + 10,
                 (-(uint)(rgDeathNoticeList[iVar10].iTeamKill == 0) & 0xffffff60) + 0xf0,
                 ~(SUB14(rgDeathNoticeList[iVar10].iTeamKill == 0,0) * 0xff) & 10);
      (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar6,iVar7 * iVar10 + 0x22,gHUD.m_rgrcRects + iVar8);
      if (rgDeathNoticeList[iVar10].iNonPlayerKill == 0) {
        pfVar3 = rgDeathNoticeList[iVar10].VictimColor;
        iVar4 = gHUD.m_rgrcRects[iVar8].right;
        iVar8 = gHUD.m_rgrcRects[iVar8].left;
        if (pfVar3 != (float *)0x0) {
          (*gEngfuncs.pfnDrawSetTextColor)(*pfVar3,pfVar3[1],pfVar3[2]);
        }
        (*gEngfuncs.pfnDrawConsoleString)((iVar4 - iVar8) + iVar6,iVar5,pcVar1);
      }
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 != 4);
  return 1;
}


// CHudDeathNotice::MsgFunc_DeathMsg  @ 00069110  (line 172)

/* DWARF original prototype: int MsgFunc_DeathMsg(CHudDeathNotice * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall
CHudDeathNotice::MsgFunc_DeathMsg(CHudDeathNotice *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  DeathNoticeItem *pDVar2;
  int iVar3;
  int victim;
  char *pcVar4;
  float *pfVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  bool bVar9;
  undefined1 uVar10;
  byte bVar11;
  longdouble extraout_ST0;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  int local_20;
  
                    /* Unresolved local var: int killer@[???]
                       Unresolved local var: int victim@[???]
                       Unresolved local var: char[32] killedwith@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * killer_name@[???]
                       Unresolved local var: char * victim_name@[???]
                       Unresolved local var: int spr@[???] */
  bVar11 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  victim = READ_BYTE();
  local_40 = CONCAT13(local_40._3_1_,0x5f64);
  pcVar4 = READ_STRING();
  __strncat_chk(&local_40,pcVar4,0x20,0x20);
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::DeathMsg(gViewPort,iVar3,victim);
  }
  CHudSpectator::DeathMessage(&gHUD.m_Spectator,victim);
  if (rgDeathNoticeList[0].iId == 0) {
    iVar6 = 0;
  }
  else if (rgDeathNoticeList[1].iId == 0) {
    iVar6 = 1;
  }
  else if (rgDeathNoticeList[2].iId == 0) {
    iVar6 = 2;
  }
  else if (rgDeathNoticeList[3].iId == 0) {
    iVar6 = 3;
  }
  else {
    memmove(rgDeathNoticeList,rgDeathNoticeList + 1,0x270);
    iVar6 = 3;
  }
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::GetAllPlayersInfo(gViewPort);
  }
  pcVar4 = g_PlayerInfoList[iVar3].name;
  if (pcVar4 == (char *)0x0) {
    rgDeathNoticeList[iVar6].szKiller[0] = '\0';
  }
  else {
    pfVar5 = g_ColorGrey;
    if ((ushort)g_PlayerExtraInfo[iVar3].teamnumber < 5) {
      pfVar5 = *(float **)(CSWTCH_43 + (uint)(ushort)g_PlayerExtraInfo[iVar3].teamnumber * 4);
    }
    rgDeathNoticeList[iVar6].KillerColor = pfVar5;
    strncpy(rgDeathNoticeList[iVar6].szKiller,pcVar4,0x20);
    rgDeathNoticeList[iVar6].szKiller[0x1f] = '\0';
  }
  if ((char)victim == -1) {
    rgDeathNoticeList[iVar6].iNonPlayerKill = 1;
    rgDeathNoticeList[iVar6].szVictim[0] = '\0';
    pcVar4 = rgDeathNoticeList[iVar6].szVictim;
    __strcpy_chk(pcVar4,(int)&local_40 + 2,0x40);
  }
  else {
    pcVar7 = g_PlayerInfoList[victim].name;
    if (pcVar7 == (char *)0x0) {
      rgDeathNoticeList[iVar6].szVictim[0] = '\0';
      pcVar4 = rgDeathNoticeList[iVar6].szVictim;
    }
    else {
      pfVar5 = g_ColorGrey;
      if ((ushort)g_PlayerExtraInfo[victim].teamnumber < 5) {
        pfVar5 = *(float **)(CSWTCH_43 + (uint)(ushort)g_PlayerExtraInfo[victim].teamnumber * 4);
      }
      rgDeathNoticeList[iVar6].VictimColor = pfVar5;
      pcVar4 = rgDeathNoticeList[iVar6].szVictim;
      strncpy(pcVar4,pcVar7,0x20);
      rgDeathNoticeList[iVar6].szVictim[0x1f] = '\0';
    }
    if ((iVar3 == victim) || (bVar9 = false, iVar3 == 0)) {
      bVar9 = iVar6 * 0x9b == 0;
      rgDeathNoticeList[iVar6].iSuicide = 1;
    }
    iVar3 = 0xb;
    pcVar7 = (char *)&local_40;
    pcVar8 = "d_teammate";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pcVar7 == *pcVar8;
      pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
      pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
    } while (bVar9);
    if (bVar9) {
      rgDeathNoticeList[iVar6].iTeamKill = 1;
    }
  }
  iVar3 = CHud::GetSpriteIndex(&gHUD,(char *)&local_40);
  pDVar2 = rgDeathNoticeList + iVar6;
  rgDeathNoticeList[iVar6].iId = iVar3;
  (*gEngfuncs.pfnGetCvarFloat)("hud_deathnotice_time");
  DEATHNOTICE_DISPLAY_TIME = (int)extraout_ST0;
  iVar3 = rgDeathNoticeList[iVar6].iNonPlayerKill;
  rgDeathNoticeList[iVar6].flDisplayTime = (float)DEATHNOTICE_DISPLAY_TIME + gHUD.m_flTime;
  if (iVar3 == 0) {
    uVar10 = rgDeathNoticeList[iVar6].iSuicide == 0;
    if ((bool)uVar10) {
      if (rgDeathNoticeList[iVar6].iTeamKill == 0) {
        (*gEngfuncs.pfnConsolePrint)(pDVar2->szKiller);
        (*gEngfuncs.pfnConsolePrint)(" killed ");
        (*gEngfuncs.pfnConsolePrint)(pcVar4);
      }
      else {
        (*gEngfuncs.pfnConsolePrint)(pDVar2->szKiller);
        (*gEngfuncs.pfnConsolePrint)(" killed his teammate ");
        (*gEngfuncs.pfnConsolePrint)(pcVar4);
      }
    }
    else {
      (*gEngfuncs.pfnConsolePrint)(pcVar4);
      iVar3 = 8;
      pcVar4 = (char *)&local_40;
      pcVar7 = "d_world";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        uVar10 = *pcVar4 == *pcVar7;
        pcVar4 = pcVar4 + (uint)bVar11 * -2 + 1;
        pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
      } while ((bool)uVar10);
      if ((bool)uVar10) {
        (*gEngfuncs.pfnConsolePrint)(" died");
      }
      else {
        (*gEngfuncs.pfnConsolePrint)(" killed self");
      }
    }
    bVar9 = (char)local_40 == '\r';
    if ('\r' < (char)local_40) {
      iVar3 = 8;
      pcVar4 = (char *)&local_40;
      pcVar7 = "d_world";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar9 = *pcVar4 == *pcVar7;
        pcVar4 = pcVar4 + (uint)bVar11 * -2 + 1;
        pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
      } while (bVar9);
      if ((!bVar9) && (uVar10 = rgDeathNoticeList[iVar6].iTeamKill == 0, (bool)uVar10)) {
        (*gEngfuncs.pfnConsolePrint)(" with ");
        pcVar4 = (char *)((int)&local_40 + 2);
        iVar3 = 5;
        pcVar7 = pcVar4;
        pcVar8 = "egon";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          uVar10 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
          pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        } while ((bool)uVar10);
        if ((bool)uVar10) {
          local_40 = 0x6c675f64;
          local_3c = 0x206e6f75;
          local_38 = 0x6e7567;
        }
        iVar3 = 6;
        pcVar7 = pcVar4;
        pcVar8 = "gauss";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          uVar10 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + (uint)bVar11 * -2 + 1;
          pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        } while ((bool)uVar10);
        if ((bool)uVar10) {
          local_40 = 0x61745f64;
          local_3c = 0x61632075;
          local_38 = 0x6e6f6e6e;
          local_34 = 0;
        }
        (*gEngfuncs.pfnConsolePrint)(pcVar4);
      }
    }
    (*gEngfuncs.pfnConsolePrint)("\n");
  }
  else {
    (*gEngfuncs.pfnConsolePrint)(pDVar2->szKiller);
    (*gEngfuncs.pfnConsolePrint)(" killed a ");
    (*gEngfuncs.pfnConsolePrint)(pcVar4);
    (*gEngfuncs.pfnConsolePrint)("\n");
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


