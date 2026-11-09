// TeamFortressViewport::MsgFunc_AllowSpec  @ 000c0d10
/* DWARF original prototype: int MsgFunc_AllowSpec(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_AllowSpec
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CTeamMenuPanel *pCVar1;
  int iVar2;
  CCommandMenu *pCVar3;
  int iYOffset;
  
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  this->m_iAllowSpectators = iVar2;
  iVar2 = this->m_StandardMenu;
  if (iVar2 == this->m_PlayerMenu) {
    pCVar3 = this->m_pCommandMenus[iVar2];
    (**(code **)(*(int *)pCVar3 + 0x108))(pCVar3);
    pCVar3->m_iButtons = 0;
    UpdatePlayerMenu(this,this->m_PlayerMenu);
  }
  iYOffset = 0;
  pCVar3 = this->m_pCommandMenus[iVar2];
  CCommandMenu::RecalculateVisibles(pCVar3,0,false);
  CCommandMenu::RecalculatePositions(pCVar3,iYOffset);
  pCVar1 = this->m_pTeamMenu;
  if (pCVar1 != (CTeamMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar1->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar1);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_BuildSt  @ 000c0950
/* DWARF original prototype: int MsgFunc_BuildSt(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_BuildSt(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  CCommandMenu *pCVar2;
  int iYOffset;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_SHORT();
  this->m_iBuildState = iVar1;
  iVar1 = this->m_StandardMenu;
  if (iVar1 == this->m_PlayerMenu) {
    pCVar2 = this->m_pCommandMenus[iVar1];
    (**(code **)(*(int *)pCVar2 + 0x108))(pCVar2);
    pCVar2->m_iButtons = 0;
    UpdatePlayerMenu(this,this->m_PlayerMenu);
  }
  iYOffset = 0;
  pCVar2 = this->m_pCommandMenus[iVar1];
  CCommandMenu::RecalculateVisibles(pCVar2,0,false);
  CCommandMenu::RecalculatePositions(pCVar2,iYOffset);
  return 1;
}


// TeamFortressViewport::MsgFunc_Detpack  @ 000c06e0
/* DWARF original prototype: int MsgFunc_Detpack(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_Detpack(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  CCommandMenu *pCVar2;
  int iYOffset;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iIsSettingDetpack = iVar1;
  iVar1 = this->m_StandardMenu;
  if (iVar1 == this->m_PlayerMenu) {
    pCVar2 = this->m_pCommandMenus[iVar1];
    (**(code **)(*(int *)pCVar2 + 0x108))(pCVar2);
    pCVar2->m_iButtons = 0;
    UpdatePlayerMenu(this,this->m_PlayerMenu);
  }
  iYOffset = 0;
  pCVar2 = this->m_pCommandMenus[iVar1];
  CCommandMenu::RecalculateVisibles(pCVar2,0,false);
  CCommandMenu::RecalculatePositions(pCVar2,iYOffset);
  return 1;
}


// TeamFortressViewport::MsgFunc_Feign  @ 000c0630
/* DWARF original prototype: int MsgFunc_Feign(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_Feign(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  CCommandMenu *pCVar2;
  int iYOffset;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iIsFeigning = iVar1;
  iVar1 = this->m_StandardMenu;
  if (iVar1 == this->m_PlayerMenu) {
    pCVar2 = this->m_pCommandMenus[iVar1];
    (**(code **)(*(int *)pCVar2 + 0x108))(pCVar2);
    pCVar2->m_iButtons = 0;
    UpdatePlayerMenu(this,this->m_PlayerMenu);
  }
  iYOffset = 0;
  pCVar2 = this->m_pCommandMenus[iVar1];
  CCommandMenu::RecalculateVisibles(pCVar2,0,false);
  CCommandMenu::RecalculatePositions(pCVar2,iYOffset);
  return 1;
}


// TeamFortressViewport::MsgFunc_MOTD  @ 000c0860
/* DWARF original prototype: int MsgFunc_MOTD(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_MOTD(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CMenuPanel *pCVar1;
  int iVar2;
  size_t sVar3;
  char *__src;
  TeamFortressViewport *this_00;
  
                    /* Unresolved local var: int roomInArray@[???] */
  if (this->m_iGotAllMOTD != 0) {
    this->m_szMOTD[0] = '\0';
  }
  this_00 = (TeamFortressViewport *)this->m_szMOTD;
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  this->m_iGotAllMOTD = iVar2;
  sVar3 = strlen((char *)this_00);
  __src = READ_STRING();
  sVar3 = 0x5ff - sVar3;
  if ((int)sVar3 < 0) {
    sVar3 = 0;
  }
  strncat((char *)this_00,__src,sVar3);
  iVar2 = this->m_iGotAllMOTD;
  this->m_szMOTD[0x5ff] = '\0';
                    /* Unresolved local var: CMenuPanel * pNewMenu@[???] */
  if (((iVar2 != 0) && (iVar2 = (*gEngfuncs.IsSpectateOnly)(), iVar2 == 0)) &&
     (iVar2 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)(), iVar2 == 0)) {
    for (pCVar1 = this->m_pCurrentMenu; pCVar1 != (CMenuPanel *)0x0; pCVar1 = pCVar1->m_pNextMenu) {
                    /* Unresolved local var: CMenuPanel * pMenu@[???] */
      if (pCVar1->m_iMenuID == 5) {
        return 1;
      }
    }
    ShowVGUIMenu(this_00,(int)__src);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_RandomPC  @ 000c0a00
/* DWARF original prototype: int MsgFunc_RandomPC(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_RandomPC
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iRandomPC = iVar1;
  return 1;
}


// TeamFortressViewport::MsgFunc_ResetFade  @ 000c0dd0
/* DWARF original prototype: int MsgFunc_ResetFade(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ResetFade
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  bool bVar1;
  screenfade_s local_24;
  
                    /* Unresolved local var: screenfade_t sf@[???] */
  bVar1 = gpGlobals != (globalvars_t *)0x0;
  if (bVar1) {
    (*gEngfuncs.pfnGetScreenFade)(&local_24);
    local_24.fadeFlags = 0;
    local_24.fader = '\0';
    local_24.fadeg = '\0';
    local_24.fadeb = '\0';
    local_24.fadealpha = '\0';
    local_24.fadeSpeed = 0.0;
    local_24.fadeReset = gpGlobals->time + 0.0;
    local_24.fadeEnd = local_24.fadeReset + 0.1;
    (*gEngfuncs.pfnSetScreenFade)(&local_24);
  }
  return (uint)bVar1;
}


// TeamFortressViewport::MsgFunc_ScoreInfo  @ 000c0a80
/* DWARF original prototype: int MsgFunc_ScoreInfo(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ScoreInfo
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CTeamMenuPanel *pCVar1;
  CClassMenuPanel *pCVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: short cl@[???]
                       Unresolved local var: short frags@[???]
                       Unresolved local var: short deaths@[???]
                       Unresolved local var: short playerclass@[???]
                       Unresolved local var: short teamnumber@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar4 = READ_BYTE();
  sVar3 = (short)iVar4;
  iVar4 = READ_SHORT();
  iVar5 = READ_SHORT();
  iVar6 = READ_SHORT();
  iVar7 = READ_SHORT();
  if ((ushort)(sVar3 - 1U) < 0x40) {
    g_PlayerExtraInfo[sVar3].deaths = (short)iVar5;
    g_PlayerExtraInfo[sVar3].playerclass = (short)iVar6;
    g_PlayerExtraInfo[sVar3].teamnumber = (short)iVar7;
    g_PlayerExtraInfo[sVar3].frags = (short)iVar4;
    if ((short)iVar7 < 0) {
      pCVar1 = this->m_pTeamMenu;
      g_PlayerExtraInfo[sVar3].teamnumber = 0;
    }
    else {
      pCVar1 = this->m_pTeamMenu;
    }
    if (pCVar1 != (CTeamMenuPanel *)0x0) {
      (**(code **)(*(int *)&(pCVar1->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar1);
    }
    pCVar2 = this->m_pClassMenu;
    if (pCVar2 != (CClassMenuPanel *)0x0) {
      (**(code **)(*(int *)&(pCVar2->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar2);
    }
    if (this->m_pScoreBoard != (ScorePanel *)0x0) {
      ScorePanel::Update(this->m_pScoreBoard);
    }
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_ServerName  @ 000c0a30
/* DWARF original prototype: int MsgFunc_ServerName(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ServerName
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  char *__src;
  
  BEGIN_READ(pbuf,iSize);
  __src = READ_STRING();
  strncpy(this->m_szServerName,__src,0x40);
  this->m_szServerName[0x3f] = '\0';
  return 1;
}


// TeamFortressViewport::MsgFunc_SpecFade  @ 000c0e40
/* DWARF original prototype: int MsgFunc_SpecFade(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_SpecFade
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int team_no;
  int iVar6;
  Vector *pVVar7;
  ushort uVar8;
  screenfade_s local_2c;
  
                    /* Unresolved local var: int iIndex@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar5 = READ_BYTE();
  if ((g_iUser1 == 4) && (g_iUser2 == iVar5)) {
                    /* Unresolved local var: int iFade@[???]
                       Unresolved local var: int iTeam@[???]
                       Unresolved local var: float flTime@[???]
                       Unresolved local var: int iAlpha@[???]
                       Unresolved local var: Vector team@[???]
                       Unresolved local var: screenfade_t sf@[???] */
    iVar5 = READ_BYTE();
    team_no = READ_BYTE();
    iVar6 = READ_SHORT();
    fVar4 = (float)iVar6 / 100.0;
    iVar6 = READ_BYTE();
    pVVar7 = GetTeamColor(team_no);
    fVar1 = pVVar7->x;
    fVar2 = pVVar7->y;
    fVar3 = pVVar7->z;
    (*gEngfuncs.pfnGetScreenFade)(&local_2c);
    local_2c.fadealpha = (byte)iVar6;
    uVar8 = (ushort)iVar6 & 0xff;
    local_2c.fader = (byte)(int)fVar1;
    local_2c.fadeg = (byte)(int)fVar2;
    local_2c.fadeSpeed = 0.0;
    local_2c.fadeb = (byte)(int)fVar3;
    if (iVar5 == 0) {
      local_2c.fadeFlags = 1;
      if (fVar4 != 0.0) {
        local_2c.fadeSpeed = -(float)uVar8 / fVar4;
      }
      local_2c.fadeEnd = gpGlobals->time + fVar4;
      local_2c.fadeReset = local_2c.fadeEnd + fVar4;
      local_2c.fadeTotalEnd = local_2c.fadeEnd;
    }
    else {
      local_2c.fadeFlags = 0;
      if (fVar4 != 0.0) {
        local_2c.fadeSpeed = (float)uVar8 / fVar4;
      }
      local_2c.fadeReset = gpGlobals->time + 0.0;
      local_2c.fadeEnd = local_2c.fadeReset + fVar4;
    }
    (*gEngfuncs.pfnSetScreenFade)(&local_2c);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_Spectator  @ 000c0cd0
/* DWARF original prototype: int MsgFunc_Spectator(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_Spectator
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: short cl@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  if ((ushort)((short)iVar1 - 1U) < 0x40) {
    iVar2 = READ_BYTE();
    g_IsSpectator[(short)iVar1] = iVar2;
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_TeamInfo  @ 000c0c20
/* DWARF original prototype: int MsgFunc_TeamInfo(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_TeamInfo
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  char *__src;
  
                    /* Unresolved local var: short cl@[???] */
  if (this->m_pScoreBoard != (ScorePanel *)0x0) {
    BEGIN_READ(pbuf,iSize);
    iVar1 = READ_BYTE();
    if ((ushort)((short)iVar1 - 1U) < 0x40) {
      __src = READ_STRING();
      strncpy(g_PlayerExtraInfo[(short)iVar1].teamname,__src,0x10);
    }
    ScorePanel::RebuildTeams(this->m_pScoreBoard);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_TeamNames  @ 000c0570
/* DWARF original prototype: int MsgFunc_TeamNames(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_TeamNames
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  char (*dst_buffer) [32];
  CommandButton *pCVar1;
  CTeamMenuPanel *pCVar2;
  int iVar3;
  char *msg;
  int iVar4;
  TeamFortressViewport *pTVar5;
  
                    /* Unresolved local var: int i@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  this->m_iNumberOfTeams = iVar3;
  iVar4 = 0;
  pTVar5 = this;
  if (0 < iVar3) {
    do {
                    /* Unresolved local var: int teamNum@[???] */
      iVar3 = iVar4 + 1;
      dst_buffer = this->m_sTeamNames + iVar4 + 1;
      msg = READ_STRING();
      CHudTextMessage::LocaliseTextString(msg,*dst_buffer,0x20);
      pCVar1 = pTVar5->m_pTeamButtons[0];
      if (pCVar1 != (CommandButton *)0x0) {
        (**(code **)(*(int *)pCVar1 + 0x264))(pCVar1,dst_buffer);
      }
      if ((iVar3 < 5) && (pCVar1 = pTVar5->m_pDisguiseButtons[1], pCVar1 != (CommandButton *)0x0)) {
        (**(code **)(*(int *)pCVar1 + 0x264))(pCVar1,dst_buffer);
      }
      pTVar5 = (TeamFortressViewport *)&pTVar5->field_0x4;
      iVar4 = iVar3;
    } while (iVar3 < this->m_iNumberOfTeams);
  }
  pCVar2 = this->m_pTeamMenu;
  if (pCVar2 != (CTeamMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar2->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar2);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_TeamScore  @ 000c0b80
/* DWARF original prototype: int MsgFunc_TeamScore(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_TeamScore
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  char *__s1;
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: char * TeamName@[???]
                       Unresolved local var: int i@[???] */
  BEGIN_READ(pbuf,iSize);
  __s1 = READ_STRING();
  iVar2 = this->m_pScoreBoard->m_iNumTeams;
  if (0 < iVar2) {
    iVar3 = 1;
    do {
      iVar1 = strcasecmp(__s1,g_TeamInfo[iVar3].name);
      if (iVar1 == 0) {
        g_TeamInfo[iVar3].scores_overriden = 1;
        iVar2 = READ_SHORT();
        g_TeamInfo[iVar3].frags = (short)iVar2;
        iVar2 = READ_SHORT();
        g_TeamInfo[iVar3].deaths = (short)iVar2;
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar2);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_VGUIMenu  @ 000c0790
/* DWARF original prototype: int MsgFunc_VGUIMenu(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_VGUIMenu
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CMenuPanel *pCVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int iMenu@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  if (iVar2 == 4) {
    iSize = (int)READ_STRING();
    pbuf = this->m_sMapName;
    strncpy(pbuf,(char *)iSize,0x40);
    this->m_sMapName[0x3f] = '\0';
  }
                    /* Unresolved local var: CMenuPanel * pNewMenu@[???] */
  iVar3 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if ((iVar3 == 0) && ((iVar2 == 5 || (gHUD.m_iIntermission == 0)))) {
    pCVar1 = this->m_pCurrentMenu;
    while( true ) {
      if (pCVar1 == (CMenuPanel *)0x0) {
        ShowVGUIMenu(pbuf,iSize);
        return 1;
      }
      if (iVar2 == pCVar1->m_iMenuID) break;
      pCVar1 = pCVar1->m_pNextMenu;
                    /* Unresolved local var: CMenuPanel * pMenu@[???] */
    }
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_ValClass  @ 000c0490
/* DWARF original prototype: int MsgFunc_ValClass(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ValClass
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  CCommandMenu *pCVar2;
  int iYOffset;
  
  BEGIN_READ(pbuf,iSize);
                    /* Unresolved local var: int i@[???] */
  iVar1 = READ_SHORT();
  this->m_iValidClasses[0] = iVar1;
  iVar1 = READ_SHORT();
  this->m_iValidClasses[1] = iVar1;
  iVar1 = READ_SHORT();
  this->m_iValidClasses[2] = iVar1;
  iVar1 = READ_SHORT();
  this->m_iValidClasses[3] = iVar1;
  iVar1 = READ_SHORT();
  this->m_iValidClasses[4] = iVar1;
  iVar1 = this->m_StandardMenu;
  if (iVar1 == this->m_PlayerMenu) {
    pCVar2 = this->m_pCommandMenus[iVar1];
    (**(code **)(*(int *)pCVar2 + 0x108))(pCVar2);
    pCVar2->m_iButtons = 0;
    UpdatePlayerMenu(this,this->m_PlayerMenu);
  }
  iYOffset = 0;
  pCVar2 = this->m_pCommandMenus[iVar1];
  CCommandMenu::RecalculateVisibles(pCVar2,0,false);
  CCommandMenu::RecalculatePositions(pCVar2,iYOffset);
  return 1;
}


