// Ghidra decompilation of functions from cl_dll/hud.cpp
// 46 functions, ordered by original source line

// CHLVoiceStatusHelper::~CHLVoiceStatusHelper  @ 0005f790  (line 37)

/* DWARF original prototype: void ~CHLVoiceStatusHelper(CHLVoiceStatusHelper * this, int __in_chrg)
    */

void __thiscall
CHLVoiceStatusHelper::~CHLVoiceStatusHelper(CHLVoiceStatusHelper *this,int __in_chrg)

{
  return;
}


// CHLVoiceStatusHelper::~CHLVoiceStatusHelper  @ 0005f7b0  (line 37)

/* DWARF original prototype: void ~CHLVoiceStatusHelper(CHLVoiceStatusHelper * this, int __in_chrg)
    */

void __thiscall
CHLVoiceStatusHelper::~CHLVoiceStatusHelper(CHLVoiceStatusHelper *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CHLVoiceStatusHelper::GetPlayerTextColor  @ 0005f7c0  (line 40)

/* DWARF original prototype: void GetPlayerTextColor(CHLVoiceStatusHelper * this, int entindex, int
   * color) */

void __thiscall
CHLVoiceStatusHelper::GetPlayerTextColor(CHLVoiceStatusHelper *this,int entindex,int *color)

{
  int iVar1;
  
  color[2] = 0xff;
  color[1] = 0xff;
  *color = 0xff;
  if ((uint)entindex < 0x41) {
                    /* Unresolved local var: int iTeam@[???] */
    iVar1 = (int)g_PlayerExtraInfo[entindex].teamnumber;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    iVar1 = iVar1 % iNumberOfTeamColors;
    *color = iTeamColors[iVar1][0];
    color[1] = iTeamColors[iVar1][1];
    color[2] = iTeamColors[iVar1][2];
  }
  return;
}


// CHLVoiceStatusHelper::UpdateCursorState  @ 0005f7a0  (line 63)

/* DWARF original prototype: void UpdateCursorState(CHLVoiceStatusHelper * this) */

void __thiscall CHLVoiceStatusHelper::UpdateCursorState(CHLVoiceStatusHelper *this)

{
  TeamFortressViewport::UpdateCursorState(gViewPort);
  return;
}


// CHLVoiceStatusHelper::GetAckIconHeight  @ 0005f740  (line 68)

/* DWARF original prototype: int GetAckIconHeight(CHLVoiceStatusHelper * this) */

int __thiscall CHLVoiceStatusHelper::GetAckIconHeight(CHLVoiceStatusHelper *this)

{
  return gHUD.m_scrinfo.iHeight + gHUD.m_iFontHeight * -3 + -6;
}


// CHLVoiceStatusHelper::CanShowSpeakerLabels  @ 0005f760  (line 73)

/* DWARF original prototype: bool CanShowSpeakerLabels(CHLVoiceStatusHelper * this) */

bool __thiscall CHLVoiceStatusHelper::CanShowSpeakerLabels(CHLVoiceStatusHelper *this)

{
  ScorePanel *pSVar1;
  byte bVar2;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (pSVar1 = gViewPort->m_pScoreBoard, pSVar1 != (ScorePanel *)0x0)) {
    bVar2 = (**(code **)(*(int *)pSVar1 + 0x28))(pSVar1);
    return (bool)(bVar2 ^ 1);
  }
  return false;
}


// __MsgFunc_Logo  @ 0005e880  (line 93)

int __MsgFunc_Logo(char *pszName,int iSize,void *pbuf)

{
  BEGIN_READ(pbuf,iSize);
  gHUD.m_iLogo = READ_BYTE();
  return 1;
}


// __MsgFunc_ResetHUD  @ 0005e2e0  (line 99)

int __MsgFunc_ResetHUD(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHud::MsgFunc_ResetHUD(&gHUD,pszName,iSize,pbuf);
  return iVar1;
}


// __MsgFunc_InitHUD  @ 0005e310  (line 104)

int __MsgFunc_InitHUD(char *pszName,int iSize,void *pbuf)

{
  CHud::MsgFunc_InitHUD(&gHUD,pszName,iSize,pbuf);
  return 1;
}


// __MsgFunc_ViewMode  @ 0005e340  (line 110)

int __MsgFunc_ViewMode(char *pszName,int iSize,void *pbuf)

{
  CHud::MsgFunc_ViewMode(&gHUD,pszName,iSize,pbuf);
  return 1;
}


// __MsgFunc_SetFOV  @ 0005e8b0  (line 116)

int __MsgFunc_SetFOV(char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  
                    /* Unresolved local var: int newfov@[???]
                       Unresolved local var: int def_fov@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("default_fov");
  if ((cl_lw == (cvar_t *)0x0) || (cl_lw->value == 0.0)) {
    iVar3 = (int)lVar4;
    fVar1 = (float)iVar2;
    gHUD.m_iFOV = iVar3;
    g_lastFOV = fVar1;
    if ((iVar2 != 0) && (gHUD.m_iFOV = iVar2, iVar2 != iVar3)) {
      fVar5 = IN_GetMouseSensitivity();
      lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("zoom_sensitivity_ratio");
      gHUD.m_flMouseSensitivity = (float)(lVar4 * (longdouble)((fVar1 / (float)iVar3) * fVar5));
      return 1;
    }
    gHUD.m_flMouseSensitivity = 0.0;
  }
  return 1;
}


// __MsgFunc_Concuss  @ 0005e370  (line 121)

int __MsgFunc_Concuss(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHud::MsgFunc_Concuss(&gHUD,pszName,iSize,pbuf);
  return iVar1;
}


// __MsgFunc_GameMode  @ 0005e3a0  (line 126)

int __MsgFunc_GameMode(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHud::MsgFunc_GameMode(&gHUD,pszName,iSize,pbuf);
  return iVar1;
}


// __CmdFunc_OpenCommandMenu  @ 0005e3d0  (line 133)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_OpenCommandMenu(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::ShowCommandMenu(gViewPort,gViewPort->m_StandardMenu);
  }
  return;
}


// __CmdFunc_InputPlayerSpecial  @ 0005e400  (line 142)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_InputPlayerSpecial(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::InputPlayerSpecial(gViewPort);
  }
  return;
}


// __CmdFunc_CloseCommandMenu  @ 0005e420  (line 150)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_CloseCommandMenu(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::InputSignalHideCommandMenu(gViewPort);
  }
  return;
}


// __CmdFunc_ForceCloseCommandMenu  @ 0005e440  (line 158)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_ForceCloseCommandMenu(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::HideCommandMenu(gViewPort);
  }
  return;
}


// __CmdFunc_ToggleServerBrowser  @ 0005e460  (line 166)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_ToggleServerBrowser(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::ToggleServerBrowser(gViewPort);
  }
  return;
}


// __MsgFunc_ValClass  @ 0005e480  (line 175)

int __MsgFunc_ValClass(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ValClass(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_TeamNames  @ 0005e4c0  (line 182)

int __MsgFunc_TeamNames(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_TeamNames(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_Feign  @ 0005e500  (line 189)

int __MsgFunc_Feign(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_Feign(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_Detpack  @ 0005e540  (line 196)

int __MsgFunc_Detpack(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_Detpack(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_VGUIMenu  @ 0005e580  (line 203)

int __MsgFunc_VGUIMenu(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_VGUIMenu(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_MOTD  @ 0005e5c0  (line 210)

int __MsgFunc_MOTD(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_MOTD(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_BuildSt  @ 0005e600  (line 217)

int __MsgFunc_BuildSt(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_BuildSt(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_RandomPC  @ 0005e640  (line 224)

int __MsgFunc_RandomPC(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_RandomPC(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_ServerName  @ 0005e680  (line 231)

int __MsgFunc_ServerName(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ServerName(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_ScoreInfo  @ 0005e6c0  (line 238)

int __MsgFunc_ScoreInfo(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ScoreInfo(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_TeamScore  @ 0005e700  (line 245)

int __MsgFunc_TeamScore(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_TeamScore(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_TeamInfo  @ 0005e740  (line 252)

int __MsgFunc_TeamInfo(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_TeamInfo(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_Spectator  @ 0005e780  (line 259)

int __MsgFunc_Spectator(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_Spectator(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_SpecFade  @ 0005e7c0  (line 266)

int __MsgFunc_SpecFade(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_SpecFade(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_ResetFade  @ 0005e800  (line 273)

int __MsgFunc_ResetFade(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ResetFade(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// __MsgFunc_AllowSpec  @ 0005e840  (line 280)

int __MsgFunc_AllowSpec(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_AllowSpec(gViewPort,pszName,iSize,pbuf);
    return iVar1;
  }
  return 0;
}


// CHud::Init  @ 0005e990  (line 287)

/* DWARF original prototype: void Init(CHud * this) */

void __thiscall CHud::Init(CHud *this)

{
  HUDLIST *__ptr;
  cvar_s *pcVar1;
  CVoiceStatus *pCVar2;
  
  (*gEngfuncs.pfnHookUserMsg)("Logo",__MsgFunc_Logo);
  (*gEngfuncs.pfnHookUserMsg)("ResetHUD",__MsgFunc_ResetHUD);
  (*gEngfuncs.pfnHookUserMsg)("GameMode",__MsgFunc_GameMode);
  (*gEngfuncs.pfnHookUserMsg)("InitHUD",__MsgFunc_InitHUD);
  (*gEngfuncs.pfnHookUserMsg)("ViewMode",__MsgFunc_ViewMode);
  (*gEngfuncs.pfnHookUserMsg)("SetFOV",__MsgFunc_SetFOV);
  (*gEngfuncs.pfnHookUserMsg)("Concuss",__MsgFunc_Concuss);
  (*gEngfuncs.pfnAddCommand)("+commandmenu",__CmdFunc_OpenCommandMenu);
  (*gEngfuncs.pfnAddCommand)("-commandmenu",__CmdFunc_CloseCommandMenu);
  (*gEngfuncs.pfnAddCommand)("ForceCloseCommandMenu",__CmdFunc_ForceCloseCommandMenu);
  (*gEngfuncs.pfnAddCommand)("special",__CmdFunc_InputPlayerSpecial);
  (*gEngfuncs.pfnAddCommand)("togglebrowser",__CmdFunc_ToggleServerBrowser);
  (*gEngfuncs.pfnHookUserMsg)("ValClass",__MsgFunc_ValClass);
  (*gEngfuncs.pfnHookUserMsg)("TeamNames",__MsgFunc_TeamNames);
  (*gEngfuncs.pfnHookUserMsg)("Feign",__MsgFunc_Feign);
  (*gEngfuncs.pfnHookUserMsg)("Detpack",__MsgFunc_Detpack);
  (*gEngfuncs.pfnHookUserMsg)("MOTD",__MsgFunc_MOTD);
  (*gEngfuncs.pfnHookUserMsg)("BuildSt",__MsgFunc_BuildSt);
  (*gEngfuncs.pfnHookUserMsg)("RandomPC",__MsgFunc_RandomPC);
  (*gEngfuncs.pfnHookUserMsg)("ServerName",__MsgFunc_ServerName);
  (*gEngfuncs.pfnHookUserMsg)("ScoreInfo",__MsgFunc_ScoreInfo);
  (*gEngfuncs.pfnHookUserMsg)("TeamScore",__MsgFunc_TeamScore);
  (*gEngfuncs.pfnHookUserMsg)("TeamInfo",__MsgFunc_TeamInfo);
  (*gEngfuncs.pfnHookUserMsg)("Spectator",__MsgFunc_Spectator);
  (*gEngfuncs.pfnHookUserMsg)("AllowSpec",__MsgFunc_AllowSpec);
  (*gEngfuncs.pfnHookUserMsg)("SpecFade",__MsgFunc_SpecFade);
  (*gEngfuncs.pfnHookUserMsg)("ResetFade",__MsgFunc_ResetFade);
  (*gEngfuncs.pfnHookUserMsg)("VGUIMenu",__MsgFunc_VGUIMenu);
  (*gEngfuncs.pfnRegisterVariable)("hud_classautokill","1",3);
  (*gEngfuncs.pfnRegisterVariable)("hud_takesshots","0",1);
  tfc_newmodels = (*gEngfuncs.pfnRegisterVariable)("tfc_newmodels","1",0x11);
  this->m_iLogo = 0;
  this->m_iFOV = 0;
  (*gEngfuncs.pfnRegisterVariable)("zoom_sensitivity_ratio","1.2",1);
  (*gEngfuncs.pfnRegisterVariable)("cl_autowepswitch","1",3);
  pcVar1 = (*gEngfuncs.pfnRegisterVariable)("default_fov","90",1);
  this->default_fov = pcVar1;
  pcVar1 = (*gEngfuncs.pfnRegisterVariable)("hud_capturemouse","1",1);
  this->m_pCvarStealMouse = pcVar1;
  pcVar1 = (*gEngfuncs.pfnRegisterVariable)("hud_draw","1",1);
  this->m_pCvarDraw = pcVar1;
  cl_lw = (*gEngfuncs.pfnGetCvarPointer)("cl_lw");
  this->m_pSpriteList = (client_sprite_t *)0x0;
  __ptr = this->m_pHudList;
  while (__ptr != (HUDLIST *)0x0) {
                    /* Unresolved local var: HUDLIST * pList@[???] */
    this->m_pHudList = __ptr->pNext;
    free(__ptr);
    __ptr = this->m_pHudList;
  }
  this->m_flTime = 1.0;
  CHudAmmo::Init(&this->m_Ammo);
  CHudHealth::Init(&this->m_Health);
  CHudSayText::Init(&this->m_SayText);
  CHudSpectator::Init(&this->m_Spectator);
  CHudGeiger::Init(&this->m_Geiger);
  CHudTrain::Init(&this->m_Train);
  CHudBattery::Init(&this->m_Battery);
  CHudFlashlight::Init(&this->m_Flash);
  CHudMessage::Init(&this->m_Message);
  CHudStatusBar::Init(&this->m_StatusBar);
  CHudDeathNotice::Init(&this->m_DeathNotice);
  CHudAmmoSecondary::Init(&this->m_AmmoSecondary);
  CHudTextMessage::Init(&this->m_TextMessage);
  CHudStatusIcons::Init(&this->m_StatusIcons);
  pCVar2 = GetClientVoiceMgr();
  (*(pCVar2->super_CHudBase)._vptr_CHudBase[8])(pCVar2,&g_VoiceStatusHelper,&gViewPort);
  CHudMenu::Init(&this->m_Menu);
  CHudBenchmark::Init(&this->m_Benchmark);
  ServersInit();
  MsgFunc_ResetHUD(this,(char *)0x0,0,(void *)0x0);
  (*gEngfuncs.pfnClientCmd)("richpresence_gamemode\n");
                    /* WARNING: Could not recover jumptable at 0x0005ee8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnClientCmd)("richpresence_update\n");
  return;
}


// CHud::~CHud  @ 0005f6c0  (line 386)

/* DWARF original prototype: void ~CHud(CHud * this, int __in_chrg) */

void __thiscall CHud::~CHud(CHud *this,int __in_chrg)

{
  HUDLIST *__ptr;
  
  if (this->m_rghSprites != (HANDLE_SPRITE *)0x0) {
    operator_delete__(this->m_rghSprites);
  }
  if (this->m_rgrcRects != (wrect_t *)0x0) {
    operator_delete__(this->m_rgrcRects);
  }
  if (this->m_rgszSpriteNames != (char *)0x0) {
    operator_delete__(this->m_rgszSpriteNames);
  }
  while (__ptr = this->m_pHudList, __ptr != (HUDLIST *)0x0) {
                    /* Unresolved local var: HUDLIST * pList@[???] */
    this->m_pHudList = __ptr->pNext;
    free(__ptr);
  }
  ServersShutdown();
  (this->m_Spectator).super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudSpectator_000bfe54;
  CInterpolation::~CInterpolation(&(this->m_Spectator).m_WayInterpolation,__in_chrg);
  return;
}


// CHud::GetSpriteIndex  @ 0005eea0  (line 412)

/* DWARF original prototype: int GetSpriteIndex(CHud * this, char * SpriteName) */

int __thiscall CHud::GetSpriteIndex(CHud *this,char *SpriteName)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__s2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = this->m_iSpriteCount;
  if (0 < iVar1) {
    __s2 = this->m_rgszSpriteNames;
    iVar3 = 0;
    do {
      iVar2 = strncmp(SpriteName,__s2,0x18);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      __s2 = __s2 + 0x18;
    } while (iVar3 != iVar1);
  }
  return -1;
}


// CHud::VidInit  @ 0005ef00  (line 424)

/* DWARF original prototype: void VidInit(CHud * this) */

void __thiscall CHud::VidInit(CHud *this)

{
  int iVar1;
  HANDLE_SPRITE HVar2;
  CVoiceStatus *pCVar3;
  client_sprite_s *pcVar4;
  HANDLE_SPRITE *pHVar5;
  wrect_t *pwVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  client_sprite_t *__src;
  int iVar12;
  char *pcVar13;
  int in_GS_OFFSET;
  bool bVar14;
  byte bVar15;
  int local_134;
  char local_120 [256];
  int local_20;
  
  bVar15 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (this->m_scrinfo).iSize = 0x214;
  (*gEngfuncs.pfnGetScreenInfo)(&this->m_scrinfo);
  iVar1 = 0x280;
  this->m_hsprLogo = 0;
  this->m_hsprCursor = 0;
  if (gHUD.m_scrinfo.iWidth < 0x280) {
    iVar1 = 0x140;
  }
  this->m_iRes = iVar1;
  if (this->m_pSpriteList == (client_sprite_t *)0x0) {
    pcVar4 = (*gEngfuncs.pfnSPR_GetList)("sprites/hud.txt",&this->m_iSpriteCountAllRes);
    this->m_pSpriteList = pcVar4;
    if (pcVar4 != (client_sprite_s *)0x0) {
                    /* Unresolved local var: client_sprite_t * p@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int index@[???] */
      this->m_iSpriteCount = 0;
      if (this->m_iSpriteCountAllRes < 1) {
        uVar7 = 0;
LAB_0005f1d7:
        pHVar5 = operator_new__(uVar7);
        this->m_rghSprites = pHVar5;
        if ((uint)this->m_iSpriteCount < 0x7f00001) {
          pwVar6 = operator_new__(this->m_iSpriteCount << 4);
          this->m_rgrcRects = pwVar6;
          pcVar10 = operator_new__(this->m_iSpriteCount * 0x18);
          __src = this->m_pSpriteList;
          this->m_rgszSpriteNames = pcVar10;
          iVar1 = this->m_iSpriteCountAllRes;
          if (0 < iVar1) {
            iVar12 = 0;
            iVar8 = 0;
            do {
              iVar9 = iVar8;
              if (__src->iRes == this->m_iRes) {
                    /* Unresolved local var: char[256] sz@[???] */
                __sprintf_chk(local_120,1,0x100,"sprites/%s.spr",__src->szSprite);
                pHVar5 = this->m_rghSprites;
                HVar2 = (*gEngfuncs.pfnSPR_Load)(local_120);
                pHVar5[iVar8] = HVar2;
                pwVar6 = this->m_rgrcRects + iVar8;
                pwVar6->left = (__src->rc).left;
                pwVar6->right = (__src->rc).right;
                pwVar6->top = (__src->rc).top;
                pwVar6->bottom = (__src->rc).bottom;
                iVar9 = iVar8 + 1;
                strncpy(this->m_rgszSpriteNames + iVar8 * 0x18,__src->szName,0x18);
                iVar1 = this->m_iSpriteCountAllRes;
              }
              iVar12 = iVar12 + 1;
              __src = __src + 1;
              iVar8 = iVar9;
            } while (iVar12 < iVar1);
          }
          goto LAB_0005f000;
        }
      }
      else {
        iVar1 = 0;
        iVar8 = 0;
        do {
          if (pcVar4->iRes == this->m_iRes) {
            iVar1 = iVar1 + 1;
            this->m_iSpriteCount = iVar1;
          }
          iVar8 = iVar8 + 1;
          pcVar4 = pcVar4 + 1;
        } while (iVar8 != this->m_iSpriteCountAllRes);
        if (iVar1 < 0x1fc00001) {
          uVar7 = iVar1 << 2;
          goto LAB_0005f1d7;
        }
      }
      __cxa_throw_bad_array_new_length();
      goto LAB_0005f305;
    }
  }
  else {
                    /* Unresolved local var: client_sprite_t * p@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: int j@[???] */
    iVar8 = this->m_iSpriteCountAllRes;
    if (0 < iVar8) {
      iVar12 = 0;
      pcVar10 = this->m_pSpriteList->szSprite;
                    /* Unresolved local var: char[256] sz@[???] */
      local_134 = 0;
      do {
        if (*(int *)(pcVar10 + 0x44) == iVar1) {
          __sprintf_chk(local_120,1,0x100,"sprites/%s.spr",pcVar10);
          pHVar5 = this->m_rghSprites + local_134;
          HVar2 = (*gEngfuncs.pfnSPR_Load)(local_120);
          local_134 = local_134 + 1;
          *pHVar5 = HVar2;
          iVar8 = this->m_iSpriteCountAllRes;
          if (iVar8 <= iVar12 + 1) break;
        }
        else if (iVar8 <= iVar12 + 1) break;
        iVar12 = iVar12 + 1;
        pcVar10 = pcVar10 + 0x98;
        iVar1 = this->m_iRes;
      } while( true );
    }
  }
LAB_0005f000:
                    /* Unresolved local var: int i@[???] */
  if (this->m_iSpriteCount < 1) {
    iVar1 = -0x10;
    iVar8 = -1;
  }
  else {
    pcVar10 = this->m_rgszSpriteNames;
    iVar8 = 0;
    bVar14 = true;
    do {
      iVar1 = 9;
      pcVar11 = "number_0";
      pcVar13 = pcVar10;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar14 = *pcVar11 == *pcVar13;
        pcVar11 = pcVar11 + (uint)bVar15 * -2 + 1;
        pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
      } while (bVar14);
      if (bVar14) {
        iVar1 = iVar8 << 4;
        goto LAB_0005f045;
      }
      iVar8 = iVar8 + 1;
      pcVar10 = pcVar10 + 0x18;
      bVar14 = iVar8 == this->m_iSpriteCount;
    } while (!bVar14);
    iVar1 = -0x10;
    iVar8 = -1;
  }
LAB_0005f045:
  this->m_HUD_number_0 = iVar8;
  this->m_iFontHeight =
       *(int *)((int)&this->m_rgrcRects->bottom + iVar1) -
       *(int *)((int)&this->m_rgrcRects->top + iVar1);
  CHudAmmo::VidInit(&this->m_Ammo);
  CHudHealth::VidInit(&this->m_Health);
  CHudSpectator::VidInit(&this->m_Spectator);
  CHudGeiger::VidInit(&this->m_Geiger);
  CHudTrain::VidInit(&this->m_Train);
  CHudBattery::VidInit(&this->m_Battery);
  CHudFlashlight::VidInit(&this->m_Flash);
  CHudMessage::VidInit(&this->m_Message);
  CHudStatusBar::VidInit(&this->m_StatusBar);
  CHudDeathNotice::VidInit(&this->m_DeathNotice);
  CHudSayText::VidInit(&this->m_SayText);
  CHudMenu::VidInit(&this->m_Menu);
  CHudAmmoSecondary::VidInit(&this->m_AmmoSecondary);
  CHudStatusIcons::VidInit(&this->m_StatusIcons);
  CHudBenchmark::VidInit(&this->m_Benchmark);
  pCVar3 = GetClientVoiceMgr();
  (*(pCVar3->super_CHudBase)._vptr_CHudBase[3])(pCVar3);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
LAB_0005f305:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHud::MsgFunc_Logo  @ 0005f310  (line 537)

/* DWARF original prototype: int MsgFunc_Logo(CHud * this, char * pszName, int iSize, void * pbuf)
    */

int __thiscall CHud::MsgFunc_Logo(CHud *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iLogo = iVar1;
  return 1;
}


// COM_FileBase  @ 0005f340  (line 555)

void COM_FileBase(char *in,char *out)

{
  size_t sVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???] */
  sVar1 = strlen(in);
  iVar2 = sVar1 - 1;
  if (iVar2 == 0) {
    cVar4 = *in;
    iVar5 = 0;
    if (cVar4 == '.') {
      iVar5 = -1;
      goto LAB_0005f3be;
    }
  }
  else {
    cVar4 = in[iVar2];
    iVar5 = iVar2;
    cVar3 = cVar4;
    if ((1 < (byte)(cVar4 - 0x2eU)) && (cVar4 != '\\')) {
      while (iVar5 = iVar5 + -1, iVar5 != 0) {
        cVar3 = in[iVar5];
        if (((byte)(cVar3 - 0x2eU) < 2) || (cVar3 == '\\')) goto LAB_0005f399;
      }
      cVar3 = *in;
    }
LAB_0005f399:
    iVar5 = iVar5 + -1;
    if (cVar3 != '.') {
      iVar5 = iVar2;
    }
    if (iVar2 < 0) goto LAB_0005f3c8;
  }
  while( true ) {
    if ((cVar4 == '\\') || (cVar4 == '/')) goto LAB_0005f3c8;
LAB_0005f3be:
    iVar2 = iVar2 + -1;
    if (iVar2 == -1) break;
    cVar4 = in[iVar2];
  }
  cVar4 = in[-1];
LAB_0005f3c8:
  if ((cVar4 == '/') || (cVar4 == '\\')) {
    iVar2 = iVar2 + 1;
  }
  else {
    iVar2 = 0;
  }
  sVar1 = (iVar5 - iVar2) + 1;
  strncpy(out,in + iVar2,sVar1);
  out[sVar1] = '\0';
  return;
}


// HUD_IsGame  @ 0005f420  (line 597)

int HUD_IsGame(char *game)

{
  char *in;
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: char * gamedir@[???]
                       Unresolved local var: char[1024] gd@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  in = (*gEngfuncs.pfnGetGameDirectory)();
  if (in == (char *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (*in != '\0') {
      COM_FileBase(in,local_410);
      iVar2 = strcasecmp(local_410,game);
      uVar1 = (uint)(iVar2 == 0);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// HUD_GetFOV  @ 0005f4c0  (line 619)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float HUD_GetFOV(void)

{
  int iVar1;
  int in_GS_OFFSET;
  float local_74 [25];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*(gEngfuncs.pDemoAPI)->IsRecording)();
  if (iVar1 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[100] buf@[???] */
    local_74[0] = g_lastFOV;
    Demo_WriteBuffer(1,4,(uchar *)local_74);
  }
  iVar1 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if (iVar1 != 0) {
    g_lastFOV = g_demozoom;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return g_lastFOV;
}


// CHud::MsgFunc_SetFOV  @ 0005f560  (line 641)

/* DWARF original prototype: int MsgFunc_SetFOV(CHud * this, char * pszName, int iSize, void * pbuf)
    */

int __thiscall CHud::MsgFunc_SetFOV(CHud *this,char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  
                    /* Unresolved local var: int newfov@[???]
                       Unresolved local var: int def_fov@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("default_fov");
  if ((cl_lw == (cvar_t *)0x0) || (cl_lw->value == 0.0)) {
    iVar3 = (int)lVar4;
    fVar1 = (float)iVar2;
    g_lastFOV = fVar1;
    if (iVar2 == 0) {
      this->m_iFOV = iVar3;
    }
    else {
      this->m_iFOV = iVar2;
      if (iVar2 != iVar3) {
        fVar5 = IN_GetMouseSensitivity();
        lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("zoom_sensitivity_ratio");
        this->m_flMouseSensitivity = (float)(lVar4 * (longdouble)((fVar1 / (float)iVar3) * fVar5));
        return 1;
      }
    }
    this->m_flMouseSensitivity = 0.0;
  }
  return 1;
}


// CHud::AddHudElem  @ 0005f650  (line 681)

/* DWARF original prototype: void AddHudElem(CHud * this, CHudBase * phudelem) */

void __thiscall CHud::AddHudElem(CHud *this,CHudBase *phudelem)

{
  HUDLIST *pHVar1;
  HUDLIST *pHVar2;
  HUDLIST *pHVar3;
  
                    /* Unresolved local var: HUDLIST * pdl@[???]
                       Unresolved local var: HUDLIST * ptemp@[???] */
  if ((phudelem != (CHudBase *)0x0) && (pHVar2 = calloc(8,1), pHVar2 != (HUDLIST *)0x0)) {
    pHVar2->p = phudelem;
    pHVar1 = this->m_pHudList;
    if (this->m_pHudList == (HUDLIST *)0x0) {
      this->m_pHudList = pHVar2;
    }
    else {
      do {
        pHVar3 = pHVar1;
        pHVar1 = pHVar3->pNext;
      } while (pHVar1 != (HUDLIST *)0x0);
      pHVar3->pNext = pHVar2;
    }
  }
  return;
}


// CHud::GetSensitivity  @ 0005f6b0  (line 712)

/* DWARF original prototype: float GetSensitivity(CHud * this) */

float __thiscall CHud::GetSensitivity(CHud *this)

{
  return this->m_flMouseSensitivity;
}


// _GLOBAL__sub_I_g_PlayerInfoList  @ 00047970  (line 713)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_PlayerInfoList(void)

{
  __cxa_atexit(CHLVoiceStatusHelper::~CHLVoiceStatusHelper,&g_VoiceStatusHelper,&__dso_handle);
  return;
}


