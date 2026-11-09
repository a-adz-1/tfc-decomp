// Ghidra decompilation of functions from cl_dll/voice_status.cpp
// 29 functions, ordered by original source line

// GetClientVoiceMgr  @ 000a1d00  (line 62)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CVoiceStatus * GetClientVoiceMgr(void)

{
  return &g_VoiceStatus;
}


// __MsgFunc_VoiceMask  @ 000a1be0  (line 73)

int __MsgFunc_VoiceMask(char *pszName,int iSize,void *pbuf)

{
  CVoiceStatus *pCVar1;
  uint32 uVar2;
  int iVar3;
  int in_GS_OFFSET;
  longdouble lVar4;
  char local_110 [256];
  int local_10;
  
  pCVar1 = g_pInternalVoiceStatus;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (g_pInternalVoiceStatus != (CVoiceStatus *)0x0) {
                    /* Unresolved local var: ulong dw@[???] */
    BEGIN_READ(pbuf,iSize);
    uVar2 = READ_LONG();
    (pCVar1->m_AudiblePlayers).m_DWords[0] = uVar2;
    uVar2 = READ_LONG();
    (pCVar1->m_ServerBannedPlayers).m_DWords[0] = uVar2;
    lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
    if (lVar4 != (longdouble)0) {
                    /* Unresolved local var: char[256] str@[???] */
      (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::HandleVoiceMaskMsg\n");
      __sprintf_chk(local_110,1,0x100,"    - m_AudiblePlayers[%d] = %lu\n",0,
                    (pCVar1->m_AudiblePlayers).m_DWords[0]);
      (*gEngfuncs.pfnConsolePrint)(local_110);
      __sprintf_chk(local_110,1,0x100,"    - m_ServerBannedPlayers[%d] = %lu\n",0,
                    (pCVar1->m_ServerBannedPlayers).m_DWords[0]);
      (*gEngfuncs.pfnConsolePrint)(local_110);
    }
    iVar3 = READ_BYTE();
    pCVar1->m_bServerModEnable = iVar3;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}


// __MsgFunc_ReqState  @ 000a2680  (line 81)

int __MsgFunc_ReqState(char *pszName,int iSize,void *pbuf)

{
  CVoiceStatus *this;
  longdouble lVar1;
  
  this = g_pInternalVoiceStatus;
  if (g_pInternalVoiceStatus != (CVoiceStatus *)0x0) {
    lVar1 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
    if (lVar1 != (longdouble)0) {
                    /* try { // try from 000a26d0 to 000b2770 has its CatchHandler @ 000a2f92 */
      (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::HandleReqStateMsg\n");
    }
    CVoiceStatus::UpdateServerState(this,true);
  }
  return 1;
}


// ForEachBannedPlayer  @ 000a1a50  (line 91)

void ForEachBannedPlayer(char *id)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char[256] str@[???] */
  iVar1 = g_BannedPlayerPrintCount;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  g_BannedPlayerPrintCount = g_BannedPlayerPrintCount + 1;
  __sprintf_chk(local_120,1,0x100,"Ban %d: %2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x\n",iVar1
                ,(int)*id,(int)id[1],(int)id[2],(int)id[3],(int)id[4],(int)id[5],(int)id[6],
                (int)id[7],(int)id[8],(int)id[9],(int)id[10],(int)id[0xb],(int)id[0xc],(int)id[0xd],
                (int)id[0xe],(int)id[0xf]);
  (*gEngfuncs.pfnConsolePrint)(local_120);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ShowBannedCallback  @ 000a1b90  (line 109)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ShowBannedCallback(void)

{
  if (g_pInternalVoiceStatus != (CVoiceStatus *)0x0) {
    g_BannedPlayerPrintCount = 0;
    (*gEngfuncs.pfnConsolePrint)("------- BANNED PLAYERS -------\n");
    CVoiceBanMgr::ForEachBannedPlayer(&g_pInternalVoiceStatus->m_BanMgr,ForEachBannedPlayer);
    (*gEngfuncs.pfnConsolePrint)("------------------------------\n");
  }
  return;
}


// CVoiceStatus::CVoiceStatus  @ 000a1d10  (line 123)

/* DWARF original prototype: void CVoiceStatus(CVoiceStatus * this) */

void __thiscall CVoiceStatus::CVoiceStatus(CVoiceStatus *this)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  Label **ppLVar4;
  bool bVar5;
  
                    /* Unresolved local var: int i@[???] */
  this->m_VoicePlayers = (uint32  [1])0x0;
  this->m_AudiblePlayers = (uint32  [1])0x0;
  this->m_VoiceEnabledPlayers = (uint32  [1])0x0;
  this->m_ServerBannedPlayers = (uint32  [1])0x0;
  (this->super_CHudBase)._vptr_CHudBase = (_func_int_varargs **)&PTR__CVoiceStatus_000caf94;
  (this->super_CDefaultInputSignal).super_InputSignal._vptr_InputSignal =
       (_func_int_varargs **)&PTR_cursorMoved_000cafc0;
  CVoiceBanMgr::CVoiceBanMgr(&this->m_BanMgr);
  this->m_pSpeakerLabelIcon = (Image *)0x0;
  this->m_pScoreboardSpeaking2 = (BitmapTGA *)0x0;
  this->m_pScoreboardSquelch = (BitmapTGA *)0x0;
  this->m_pScoreboardNeverSpoken = (BitmapTGA *)0x0;
  ppLVar4 = this->m_pBanButtons;
  this->m_pScoreboardBanned = (BitmapTGA *)0x0;
  this->m_pLocalBitmap = (BitmapTGA *)0x0;
  bVar5 = ((uint)ppLVar4 & 1) != 0;
  this->m_pScoreboardNotSpeaking = (BitmapTGA *)0x0;
  uVar2 = 0x80;
  this->m_bBanMgrInitialized = false;
  this->m_LastUpdateServerState = 0.0;
  this->m_pScoreboardSpeaking = (BitmapTGA *)0x0;
  this->m_pAckBitmap = (BitmapTGA *)0x0;
  this->m_bServerAcked = false;
  this->m_bTalking = false;
  if (bVar5) {
    ppLVar4 = (Label **)((int)this->m_pBanButtons + 1);
    uVar2 = 0x7f;
    *(undefined1 *)this->m_pBanButtons = 0;
  }
  if (((uint)ppLVar4 & 2) != 0) {
    *(undefined2 *)ppLVar4 = 0;
    uVar2 = uVar2 - 2;
    ppLVar4 = (Label **)((int)ppLVar4 + 2);
  }
  uVar1 = 0;
  do {
    *(undefined4 *)((int)ppLVar4 + uVar1) = 0;
    *(undefined4 *)((int)ppLVar4 + uVar1 + 4) = 0;
    uVar1 = uVar1 + 8;
  } while (uVar1 < (uVar2 & 0xfffffff8));
  puVar3 = (undefined4 *)((int)ppLVar4 + uVar1);
  if ((uVar2 & 4) != 0) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if ((uVar2 & 2) != 0) {
    *(undefined2 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 2);
  }
  if (bVar5) {
    *(undefined1 *)puVar3 = 0;
  }
  this->m_pParentPanel = (Panel **)0x0;
  this->m_bServerModEnable = -1;
  this->m_pchGameDir = (char *)0x0;
  return;
}


// CVoiceStatus::~CVoiceStatus  @ 000a37c0  (line 151)

/* DWARF original prototype: void ~CVoiceStatus(CVoiceStatus * this, int __in_chrg) */

void __thiscall CVoiceStatus::~CVoiceStatus(CVoiceStatus *this,int __in_chrg)

{
  char *pGameDir;
  CVoiceLabel *pCVar1;
  CVoiceLabel *pCVar2;
  
  g_pInternalVoiceStatus = (CVoiceStatus *)0x0;
  (this->super_CHudBase)._vptr_CHudBase = (_func_int_varargs **)&PTR__CVoiceStatus_000caf94;
  (this->super_CDefaultInputSignal).super_InputSignal._vptr_InputSignal =
       (_func_int_varargs **)&PTR_cursorMoved_000cafc0;
  pCVar1 = this->m_Labels;
  do {
                    /* Unresolved local var: int i@[???] */
    pCVar2 = pCVar1 + 1;
    operator_delete(pCVar1->m_pLabel);
    pCVar1->m_pLabel = (Label *)0x0;
    operator_delete(pCVar1->m_pIcon);
    pCVar1->m_pIcon = (ImagePanel *)0x0;
    operator_delete(pCVar1->m_pBackground);
    pCVar1->m_pBackground = (Label *)0x0;
    pCVar1 = pCVar2;
  } while (pCVar2 != (CVoiceLabel *)&this->m_pchGameDir);
  operator_delete(this->m_pLocalLabel);
  this->m_pLocalLabel = (ImagePanel *)0x0;
  FreeBitmaps(this);
  pGameDir = this->m_pchGameDir;
  if (pGameDir != (char *)0x0) {
    if (this->m_bBanMgrInitialized != false) {
      CVoiceBanMgr::SaveState(&this->m_BanMgr,pGameDir);
      pGameDir = this->m_pchGameDir;
    }
    free(pGameDir);
  }
  CVoiceBanMgr::~CVoiceBanMgr(&this->m_BanMgr,__in_chrg);
  return;
}


// CVoiceStatus::~CVoiceStatus  @ 000a3cd0  (line 151)

/* DWARF original prototype: void ~CVoiceStatus(CVoiceStatus * this, int __in_chrg) */

void __thiscall CVoiceStatus::~CVoiceStatus(CVoiceStatus *this,int __in_chrg)

{
  char *pGameDir;
  CVoiceLabel *pCVar1;
  CVoiceLabel *pCVar2;
  char *in_stack_ffffffe8;
  
  g_pInternalVoiceStatus = (CVoiceStatus *)0x0;
  (this->super_CHudBase)._vptr_CHudBase = (_func_int_varargs **)&PTR__CVoiceStatus_000caf94;
  (this->super_CDefaultInputSignal).super_InputSignal._vptr_InputSignal =
       (_func_int_varargs **)&PTR_cursorMoved_000cafc0;
  pCVar1 = this->m_Labels;
  do {
                    /* Unresolved local var: int i@[???] */
    pCVar2 = pCVar1 + 1;
    operator_delete(pCVar1->m_pLabel);
    pCVar1->m_pLabel = (Label *)0x0;
    operator_delete(pCVar1->m_pIcon);
    pCVar1->m_pIcon = (ImagePanel *)0x0;
    operator_delete(pCVar1->m_pBackground);
    pCVar1->m_pBackground = (Label *)0x0;
    pCVar1 = pCVar2;
  } while (pCVar2 != (CVoiceLabel *)&this->m_pchGameDir);
  operator_delete(this->m_pLocalLabel);
  this->m_pLocalLabel = (ImagePanel *)0x0;
  FreeBitmaps(this);
  pGameDir = this->m_pchGameDir;
  if (pGameDir != (char *)0x0) {
    if (this->m_bBanMgrInitialized != false) {
      in_stack_ffffffe8 = pGameDir;
      CVoiceBanMgr::SaveState(&this->m_BanMgr,pGameDir);
      pGameDir = this->m_pchGameDir;
    }
    free(pGameDir);
  }
  CVoiceBanMgr::~CVoiceBanMgr(&this->m_BanMgr,(int)in_stack_ffffffe8);
  operator_delete(this);
  return;
}


// CVoiceStatus::Init  @ 000a3ff0  (line 187)

/* DWARF original prototype: int Init(CVoiceStatus * this, IVoiceStatusHelper * pHelper, Panel * *
   pParentPanel) */

int __thiscall
CVoiceStatus::Init(CVoiceStatus *this,IVoiceStatusHelper *pHelper,Panel **pParentPanel)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  Label *pLVar4;
  ImagePanel *pIVar5;
  size_t sVar6;
  char *__dest;
  uint uVar7;
  CVoiceLabel *pCVar8;
  undefined4 *puVar9;
  CVoiceLabel *pCVar10;
  bool bVar11;
  
                    /* Unresolved local var: char * pchGameDirT@[???] */
  (*gEngfuncs.pfnRegisterVariable)("voice_modenable","1",1);
  (*gEngfuncs.pfnRegisterVariable)("voice_clientdebug","0",0);
  (*gEngfuncs.pfnAddCommand)("voice_showbanned",ShowBannedCallback);
  pcVar2 = (*gEngfuncs.pfnGetGameDirectory)();
  if (pcVar2 != (char *)0x0) {
    pcVar2 = (*gEngfuncs.pfnGetGameDirectory)();
    CVoiceBanMgr::Init(&this->m_BanMgr,pcVar2);
    this->m_bBanMgrInitialized = true;
  }
  uVar7 = 0x70;
  pCVar10 = this->m_Labels;
  *(undefined4 *)&this->m_BlinkTimer = 0;
  *(undefined4 *)((int)&this->m_BlinkTimer + 4) = 0;
  bVar11 = ((uint)pCVar10 & 1) != 0;
  g_pInternalVoiceStatus = this;
  this->m_VoiceHeadModel = 0;
  pCVar8 = pCVar10;
  if (bVar11) {
    uVar7 = 0x6f;
    *(undefined1 *)&this->m_Labels[0].m_pLabel = 0;
    pCVar8 = (CVoiceLabel *)((int)&this->m_Labels[0].m_pLabel + 1);
  }
  if (((uint)pCVar8 & 2) != 0) {
    *(undefined2 *)&pCVar8->m_pLabel = 0;
    uVar7 = uVar7 - 2;
    pCVar8 = (CVoiceLabel *)((int)&pCVar8->m_pLabel + 2);
  }
  uVar1 = 0;
  do {
    uVar3 = uVar1;
    *(undefined4 *)((int)&pCVar8->m_pLabel + uVar3) = 0;
    *(undefined4 *)((int)&pCVar8->m_pBackground + uVar3) = 0;
    uVar1 = uVar3 + 8;
  } while (uVar3 + 8 < (uVar7 & 0xfffffff8));
  puVar9 = (undefined4 *)((int)&pCVar8->m_pIcon + uVar3);
  if ((uVar7 & 4) != 0) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  if ((uVar7 & 2) != 0) {
    *(undefined2 *)puVar9 = 0;
    puVar9 = (undefined4 *)((int)puVar9 + 2);
  }
  if (bVar11) {
    *(undefined1 *)puVar9 = 0;
  }
  do {
    pLVar4 = operator_new(0xd0);
    vgui::Label::Label(pLVar4,"");
    pCVar10->m_pBackground = pLVar4;
    pLVar4 = operator_new(0xd0);
    vgui::Label::Label(pLVar4,"");
    pCVar10->m_pLabel = pLVar4;
    if (pLVar4 != (Label *)0x0) {
      vgui::Panel::setVisible(SUB41(pLVar4,0));
      (**(code **)(*(int *)pCVar10->m_pLabel + 0x208))(pCVar10->m_pLabel,2);
      (**(code **)(*(int *)pCVar10->m_pLabel + 0x218))(pCVar10->m_pLabel,5);
      (**(code **)(*(int *)pCVar10->m_pLabel + 0x21c))(pCVar10->m_pLabel,5);
      (**(code **)(*(int *)pCVar10->m_pLabel + 0x40))(pCVar10->m_pLabel,pCVar10->m_pBackground);
    }
    pIVar5 = operator_new(0xc0);
    vgui::ImagePanel::ImagePanel(pIVar5,(Image *)0x0);
    pCVar10->m_pIcon = pIVar5;
    if (pIVar5 != (ImagePanel *)0x0) {
      vgui::Panel::setVisible(SUB41(pIVar5,0));
      (**(code **)(*(int *)pCVar10->m_pIcon + 0x40))(pCVar10->m_pIcon,pCVar10->m_pBackground);
    }
    pCVar10->m_clientindex = -1;
    pCVar10 = pCVar10 + 1;
  } while (pCVar10 != (CVoiceLabel *)&this->m_pchGameDir);
  pIVar5 = operator_new(0xc0);
  vgui::ImagePanel::ImagePanel(pIVar5,(Image *)0x0);
  this->m_pLocalLabel = pIVar5;
  this->m_bInSquelchMode = false;
  this->m_pHelper = pHelper;
  this->m_pParentPanel = pParentPanel;
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  (this->super_CHudBase).m_iFlags = 1;
  (*gEngfuncs.pfnHookUserMsg)("VoiceMask",__MsgFunc_VoiceMask);
  (*gEngfuncs.pfnHookUserMsg)("ReqState",__MsgFunc_ReqState);
  pcVar2 = (*gEngfuncs.pfnGetGameDirectory)();
  sVar6 = strlen(pcVar2);
  __dest = malloc(sVar6 + 1);
  this->m_pchGameDir = __dest;
  strcpy(__dest,pcVar2);
  return 1;
}


// CVoiceStatus::VidInit  @ 000a38a0  (line 253)

/* DWARF original prototype: int VidInit(CVoiceStatus * this) */

int __thiscall CVoiceStatus::VidInit(CVoiceStatus *this)

{
  code *pcVar1;
  int iVar2;
  BitmapTGA *pBVar3;
  byte *pbVar4;
  HANDLE_SPRITE HVar5;
  int in_GS_OFFSET;
  double dVar6;
  Color local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: char * pFile@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  FreeBitmaps(this);
  pBVar3 = vgui_LoadTGA("gfx/vgui/icntlk_pl.tga");
  this->m_pLocalBitmap = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,0x87);
    (*pcVar1)(this->m_pLocalBitmap,local_1010);
  }
  pBVar3 = vgui_LoadTGA("gfx/vgui/icntlk_sv.tga");
  this->m_pAckBitmap = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,0x87);
    (*pcVar1)(this->m_pAckBitmap,local_1010);
  }
  (**(code **)(*(int *)this->m_pLocalLabel + 0x1fc))(this->m_pLocalLabel,this->m_pLocalBitmap);
  (**(code **)(*(int *)this->m_pLocalLabel + 0x24))(this->m_pLocalLabel,0);
  pBVar3 = vgui_LoadTGANoInvertAlpha("gfx/vgui/speaker4.tga");
  this->m_pSpeakerLabelIcon = (Image *)pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,1);
    (*pcVar1)(this->m_pSpeakerLabelIcon,local_1010);
  }
  pBVar3 = vgui_LoadTGANoInvertAlpha("gfx/vgui/640_speaker1.tga");
  this->m_pScoreboardNeverSpoken = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,1);
    (*pcVar1)(this->m_pScoreboardNeverSpoken,local_1010);
  }
  pBVar3 = vgui_LoadTGANoInvertAlpha("gfx/vgui/640_speaker2.tga");
  this->m_pScoreboardNotSpeaking = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,1);
    (*pcVar1)(this->m_pScoreboardNotSpeaking,local_1010);
  }
  pBVar3 = vgui_LoadTGANoInvertAlpha("gfx/vgui/640_speaker3.tga");
  this->m_pScoreboardSpeaking = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,1);
    (*pcVar1)(this->m_pScoreboardSpeaking,local_1010);
  }
  pBVar3 = vgui_LoadTGANoInvertAlpha("gfx/vgui/640_speaker4.tga");
  this->m_pScoreboardSpeaking2 = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,1);
    (*pcVar1)(this->m_pScoreboardSpeaking2,local_1010);
  }
  pBVar3 = vgui_LoadTGA("gfx/vgui/icntlk_squelch.tga");
  this->m_pScoreboardSquelch = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,1);
    (*pcVar1)(this->m_pScoreboardSquelch,local_1010);
  }
  pBVar3 = vgui_LoadTGA("gfx/vgui/640_voiceblocked.tga");
  this->m_pScoreboardBanned = pBVar3;
  if (pBVar3 != (BitmapTGA *)0x0) {
    pcVar1 = *(code **)(*(int *)pBVar3 + 0xc);
    vgui::Color::Color(local_1010,0xff,0xff,0xff,1);
    (*pcVar1)(this->m_pScoreboardBanned,local_1010);
  }
  this->m_VoiceHeadModelHeight = 45.0;
  pbVar4 = (*gEngfuncs.COM_LoadFile)("scripts/voicemodel.txt",5,(int *)0x0);
  if (pbVar4 != (byte *)0x0) {
                    /* Unresolved local var: char[4096] token@[???] */
    (*gEngfuncs.COM_ParseFile)((char *)pbVar4,(char *)local_1010);
    if ((byte)((char)local_1010[0] - 0x30U) < 10) {
      dVar6 = strtod((char *)local_1010,(char **)0x0);
      this->m_VoiceHeadModelHeight = (float)dVar6;
    }
    (*gEngfuncs.COM_FreeFile)(pbVar4);
  }
  HVar5 = (*gEngfuncs.pfnSPR_Load)("sprites/voiceicon.spr");
  iVar2 = *(int *)(in_GS_OFFSET + 0x14);
  this->m_VoiceHeadModel = HVar5;
  if (local_10 == iVar2) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CVoiceStatus::Frame  @ 000a23d0  (line 313)

/* DWARF original prototype: void Frame(CVoiceStatus * this, double frametime) */

void __thiscall CVoiceStatus::Frame(CVoiceStatus *this,double frametime)

{
  Label *pLVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  Label **ppLVar6;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  double dVar7;
  byte local_54;
  char local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (*gEngfuncs.GetClientTime)();
  if ((longdouble)1 < extraout_ST0 - (longdouble)this->m_LastUpdateServerState) {
    UpdateServerState(this,false);
  }
  this->m_BlinkTimer = frametime + this->m_BlinkTimer;
  iVar4 = (*this->m_pHelper->_vptr_IVoiceStatusHelper[5])(this->m_pHelper);
  if ((char)iVar4 == '\0') {
    ppLVar6 = &this->m_Labels[0].m_pBackground;
    do {
                    /* Unresolved local var: int i@[???] */
      pLVar1 = *ppLVar6;
      ppLVar6 = ppLVar6 + 4;
      (**(code **)(*(int *)pLVar1 + 0x24))(pLVar1);
    } while (this + 1 != (CVoiceStatus *)ppLVar6);
  }
  else {
    ppLVar6 = &this->m_Labels[0].m_pBackground;
    do {
                    /* Unresolved local var: int i@[???] */
      pLVar1 = *ppLVar6;
      ppLVar6 = ppLVar6 + 4;
      (**(code **)(*(int *)pLVar1 + 0x24))(pLVar1);
    } while (this + 1 != (CVoiceStatus *)ppLVar6);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Label * pPanel@[???]
                       Unresolved local var: char[16] playerID@[???]
                       Unresolved local var: bool bBlink@[???]
                       Unresolved local var: bool bTalking@[???]
                       Unresolved local var: bool bBanned@[???]
                       Unresolved local var: bool bNeverSpoken@[???] */
  iVar4 = 1;
  do {
    while( true ) {
      pLVar1 = this->m_pBanButtons[iVar4 + -1];
      local_54 = (char)iVar4 - 1;
      if ((pLVar1 != (Label *)0x0) && (bVar3 = HACK_GetPlayerUniqueID(iVar4,local_30), bVar3))
      break;
LAB_000a2488:
      iVar4 = iVar4 + 1;
      if (iVar4 == 0x21) goto LAB_000a2570;
    }
    dVar7 = fmod(this->m_BlinkTimer,0.6);
    uVar2 = (this->m_VoicePlayers).m_DWords[0];
                    /* catch() { ... } // from try @ 000a2ed5 with catch @ 000a24f0 */
    bVar3 = CVoiceBanMgr::GetPlayerBan(&this->m_BanMgr,local_30);
    if (bVar3) {
      (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1);
      goto LAB_000a2488;
    }
    uVar5 = 1 << (local_54 & 0x1f);
    if ((uVar2 & uVar5) == 0) {
                    /* try { // try from 000a2598 to 000b2604 has its CatchHandler @ 000a24f0 */
      if (((this->m_VoiceEnabledPlayers).m_DWords[0] & uVar5) == 0) {
        (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1);
        (**(code **)(*(int *)pLVar1 + 0x124))(pLVar1,100,100,100,1);
      }
      else {
        (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1);
      }
      goto LAB_000a2488;
    }
    if (0.3 <= dVar7) {
                    /* try { // try from 000a260e to 000b26b1 has its CatchHandler @ 000a2f94 */
      (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1);
    }
    else {
      (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1);
    }
    iVar4 = iVar4 + 1;
    (**(code **)(*(int *)pLVar1 + 0x124))(pLVar1,0xff,0xaa,0,1);
  } while (iVar4 != 0x21);
LAB_000a2570:
                    /* try { // try from 000a257c to 000b2580 has its CatchHandler @ 000a2f44 */
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CVoiceStatus::CreateEntities  @ 000a1e60  (line 340)

/* DWARF original prototype: void CreateEntities(CVoiceStatus * this) */

void __thiscall CVoiceStatus::CreateEntities(CVoiceStatus *this)

{
  cl_entity_s *pcVar1;
  cl_entity_s *pcVar2;
  cl_entity_s *pcVar3;
  model_s *pmVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  cl_entity_s *pcVar8;
  bool bVar9;
  byte bVar10;
  int local_28;
  
                    /* Unresolved local var: cl_entity_t * localPlayer@[???]
                       Unresolved local var: int iOutModel@[???] */
  bVar10 = 0;
  if (this->m_VoiceHeadModel != 0) {
    pcVar2 = (*gEngfuncs.GetLocalPlayer)();
    iVar7 = 1;
    local_28 = 0;
    do {
                    /* Unresolved local var: cl_entity_s * pClient@[???]
                       Unresolved local var: cl_entity_s * pEnt@[???] */
      if ((((((this->m_VoicePlayers).m_DWords[0] & 1 << ((char)iVar7 - 1U & 0x1f)) != 0) &&
           (pcVar3 = (*gEngfuncs.GetEntityByIndex)(iVar7), pcVar3 != (cl_entity_s *)0x0)) &&
          ((pcVar2->curstate).messagenum <= (pcVar3->curstate).messagenum)) &&
         ((((pcVar3->curstate).effects & 0x80) == 0 &&
          ((pcVar2 != pcVar3 || (cam_thirdperson != 0)))))) {
        pcVar1 = this->m_VoiceHeadModels + local_28;
        bVar9 = ((uint)pcVar1 & 1) != 0;
        uVar6 = 3000;
        pcVar8 = pcVar1;
        if (bVar9) {
          *(undefined1 *)&this->m_VoiceHeadModels[local_28].index = 0;
          pcVar8 = (cl_entity_s *)((int)&this->m_VoiceHeadModels[local_28].index + 1);
          uVar6 = 2999;
        }
        if (((uint)pcVar8 & 2) != 0) {
          *(undefined2 *)&pcVar8->index = 0;
          uVar6 = uVar6 - 2;
          pcVar8 = (cl_entity_s *)((int)&pcVar8->index + 2);
        }
        if (((uint)pcVar8 & 4) != 0) {
          pcVar8->index = 0;
          uVar6 = uVar6 - 4;
          pcVar8 = (cl_entity_s *)&pcVar8->player;
        }
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          pcVar8->index = 0;
          pcVar8 = (cl_entity_s *)((int)pcVar8 + (uint)bVar10 * -8 + 4);
        }
        if ((uVar6 & 2) != 0) {
          *(undefined2 *)&pcVar8->index = 0;
          pcVar8 = (cl_entity_s *)((int)&pcVar8->index + 2);
        }
        if (bVar9) {
          *(undefined1 *)&pcVar8->index = 0;
        }
        this->m_VoiceHeadModels[local_28].curstate.rendermode = 5;
        this->m_VoiceHeadModels[local_28].curstate.renderamt = 0xff;
        this->m_VoiceHeadModels[local_28].baseline.renderamt = 0xff;
        this->m_VoiceHeadModels[local_28].curstate.renderfx = 0xe;
        this->m_VoiceHeadModels[local_28].curstate.framerate = 1.0;
        this->m_VoiceHeadModels[local_28].curstate.frame = 0.0;
        pmVar4 = (*gEngfuncs.GetSpritePointer)(this->m_VoiceHeadModel);
        this->m_VoiceHeadModels[local_28].model = pmVar4;
        this->m_VoiceHeadModels[local_28].angles.z = 0.0;
        this->m_VoiceHeadModels[local_28].angles.y = 0.0;
        this->m_VoiceHeadModels[local_28].angles.x = 0.0;
        this->m_VoiceHeadModels[local_28].curstate.scale = 0.5;
        this->m_VoiceHeadModels[local_28].origin.y = 0.0;
        this->m_VoiceHeadModels[local_28].origin.x = 0.0;
        this->m_VoiceHeadModels[local_28].origin.z = 45.0;
        this->m_VoiceHeadModels[local_28].origin.x =
             this->m_VoiceHeadModels[local_28].origin.x + (pcVar3->origin).x;
        this->m_VoiceHeadModels[local_28].origin.y =
             this->m_VoiceHeadModels[local_28].origin.y + (pcVar3->origin).y;
        this->m_VoiceHeadModels[local_28].origin.z =
             this->m_VoiceHeadModels[local_28].origin.z + (pcVar3->origin).z;
        (*gEngfuncs.CL_CreateVisibleEntity)(0,pcVar1);
        local_28 = local_28 + 1;
      }
      iVar7 = iVar7 + 1;
                    /* Unresolved local var: int i@[???] */
    } while (iVar7 != 0x21);
  }
  return;
}


// CVoiceStatus::UpdateSpeakerStatus  @ 000a3110  (line 393)

/* DWARF original prototype: void UpdateSpeakerStatus(CVoiceStatus * this, int entindex, qboolean
   bTalking) */

void __thiscall CVoiceStatus::UpdateSpeakerStatus(CVoiceStatus *this,int entindex,qboolean bTalking)

{
  int iVar1;
  Label **ppLVar2;
  char *pcVar3;
  int *piVar4;
  code *pcVar5;
  cl_entity_s *pcVar6;
  cvar_s *pcVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  hud_player_info_s local_23c;
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: cvar_t * pVoiceLoopback@[???]
                       Unresolved local var: int iLocalPlayerIndex@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((this->m_pParentPanel == (Panel **)0x0) || (*this->m_pParentPanel == (Panel *)0x0))
  goto LAB_000a3228;
  (*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
  if (extraout_ST0 == (longdouble)0) {
    pcVar6 = (*gEngfuncs.GetLocalPlayer)();
    uVar8 = pcVar6->index;
    if (entindex == -1) goto LAB_000a32b9;
LAB_000a3196:
    pcVar7 = (cvar_s *)0x0;
    if (entindex == -2) {
      this->m_bServerAcked = bTalking != 0;
      RepositionLabels(this);
      goto LAB_000a3228;
    }
  }
  else {
                    /* Unresolved local var: char[256] msg@[???] */
    __snprintf_chk(local_220,0x100,1,0x100,
                   "CVoiceStatus::UpdateSpeakerStatus: ent %d talking = %d\n",entindex,bTalking);
    (*gEngfuncs.pfnConsolePrint)(local_220);
    pcVar6 = (*gEngfuncs.GetLocalPlayer)();
    uVar8 = pcVar6->index;
    if (entindex != -1) goto LAB_000a3196;
LAB_000a32b9:
    this->m_bTalking = bTalking != 0;
    if (bTalking != 0) {
      (*gEngfuncs.pfnClientCmd)("voice_modenable 1");
    }
    pcVar7 = (*gEngfuncs.pfnGetCvarPointer)("voice_loopback");
    entindex = uVar8;
  }
  if (0x20 < (uint)entindex) goto LAB_000a3220;
                    /* Unresolved local var: int iClient@[???]
                       Unresolved local var: CVoiceLabel * pLabel@[???] */
  iVar1 = entindex - 1;
  if (iVar1 == -1) goto LAB_000a3228;
                    /* Unresolved local var: int i@[???] */
  bVar9 = (byte)iVar1;
  if (iVar1 == this->m_Labels[0].m_clientindex) {
    iVar10 = 0;
LAB_000a3310:
    ppLVar2 = &this->m_Labels[iVar10 + -1].m_pBackground;
    if (bTalking == 0) {
      (this->m_VoicePlayers).m_DWords[0] =
           (this->m_VoicePlayers).m_DWords[0] &
           (-2 << (bVar9 & 0x1f) | 0xfffffffeU >> 0x20 - (bVar9 & 0x1f));
      if (ppLVar2 != (Label **)0xfffffff4) {
        (**(code **)(*(int *)ppLVar2[4] + 0x24))(ppLVar2[4],0);
        ppLVar2[6] = (Label *)0xffffffff;
        RepositionLabels(this);
        goto LAB_000a3228;
      }
    }
    else {
      uVar11 = 1 << (bVar9 & 0x1f);
      (this->m_VoicePlayers).m_DWords[0] = (this->m_VoicePlayers).m_DWords[0] | uVar11;
      (this->m_VoiceEnabledPlayers).m_DWords[0] = (this->m_VoiceEnabledPlayers).m_DWords[0] | uVar11
      ;
      if (ppLVar2 == (Label **)0xfffffff4) goto LAB_000a3350;
    }
  }
  else {
    if (iVar1 == this->m_Labels[1].m_clientindex) {
      iVar10 = 1;
      goto LAB_000a3310;
    }
    if (iVar1 == this->m_Labels[2].m_clientindex) {
      iVar10 = 2;
      goto LAB_000a3310;
    }
    if (iVar1 == this->m_Labels[3].m_clientindex) {
      iVar10 = 3;
      goto LAB_000a3310;
    }
    if (iVar1 == this->m_Labels[4].m_clientindex) {
      iVar10 = 4;
      goto LAB_000a3310;
    }
    if (iVar1 == this->m_Labels[5].m_clientindex) {
      iVar10 = 5;
      goto LAB_000a3310;
    }
    iVar10 = 6;
    if (iVar1 == this->m_Labels[6].m_clientindex) goto LAB_000a3310;
    if (bTalking == 0) {
      (this->m_VoicePlayers).m_DWords[0] =
           (this->m_VoicePlayers).m_DWords[0] &
           (-2 << (bVar9 & 0x1f) | 0xfffffffeU >> 0x20 - (bVar9 & 0x1f));
      goto LAB_000a3220;
    }
    uVar11 = 1 << (bVar9 & 0x1f);
    (this->m_VoicePlayers).m_DWords[0] = (this->m_VoicePlayers).m_DWords[0] | uVar11;
    (this->m_VoiceEnabledPlayers).m_DWords[0] = (this->m_VoiceEnabledPlayers).m_DWords[0] | uVar11;
LAB_000a3350:
    if ((entindex != uVar8) || ((pcVar7 != (cvar_s *)0x0 && (pcVar7->value != 0.0)))) {
                    /* Unresolved local var: int i@[???] */
      if (this->m_Labels[0].m_clientindex == -1) {
        iVar10 = 0;
      }
      else if (this->m_Labels[1].m_clientindex == -1) {
        iVar10 = 1;
      }
      else if (this->m_Labels[2].m_clientindex == -1) {
        iVar10 = 2;
      }
      else if (this->m_Labels[3].m_clientindex == -1) {
        iVar10 = 3;
      }
      else if (this->m_Labels[4].m_clientindex == -1) {
        iVar10 = 4;
      }
      else if (this->m_Labels[5].m_clientindex == -1) {
        iVar10 = 5;
      }
      else {
        iVar10 = 6;
        if (this->m_Labels[6].m_clientindex != -1) goto LAB_000a3220;
      }
      if (this->m_Labels + iVar10 != (CVoiceLabel *)0x0) {
                    /* Unresolved local var: hud_player_info_t info@[???]
                       Unresolved local var: char[512] paddedName@[???]
                       Unresolved local var: int[3] color@[???] */
        uVar8 = 0;
        do {
          uVar11 = uVar8;
          *(undefined4 *)((int)&local_23c.name + uVar11) = 0;
          pcVar3 = local_220 + (uVar11 - 0x18);
          pcVar3[0] = '\0';
          pcVar3[1] = '\0';
          pcVar3[2] = '\0';
          pcVar3[3] = '\0';
          uVar8 = uVar11 + 8;
        } while (uVar11 + 8 < 0x18);
        pcVar3 = local_220 + (uVar11 - 0x14);
        pcVar3[0] = '\0';
        pcVar3[1] = '\0';
        pcVar3[2] = '\0';
        pcVar3[3] = '\0';
        (*gEngfuncs.pfnGetPlayerInfo)(entindex,&local_23c);
        __snprintf_chk(local_220,0x200,1,0x200,&DAT_000cae1f,local_23c.name);
        (*this->m_pHelper->_vptr_IVoiceStatusHelper[2])(this->m_pHelper,entindex,&local_248);
        piVar4 = *(int **)((int)&__DT_REL[iVar10 * 2 + 0x531].r_offset +
                          (int)this->m_VoiceHeadModels);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x128))(piVar4,local_248,local_244,local_240,0x87);
          piVar4 = *(int **)((int)&__DT_REL[iVar10 * 2 + 0x531].r_offset +
                            (int)this->m_VoiceHeadModels);
          (**(code **)(*piVar4 + 0x40))(piVar4,*this->m_pParentPanel);
          pcVar5 = *(code **)(**(int **)((int)&__DT_REL[iVar10 * 2 + 0x531].r_offset +
                                        (int)this->m_VoiceHeadModels) + 0x24);
          uVar8 = (*this->m_pHelper->_vptr_IVoiceStatusHelper[5])(this->m_pHelper);
          (*pcVar5)(*(undefined4 *)
                     ((int)&__DT_REL[iVar10 * 2 + 0x531].r_offset + (int)this->m_VoiceHeadModels),
                    uVar8 & 0xff);
        }
        piVar4 = *(int **)((int)&__DT_REL[iVar10 * 2 + 0x530].r_info + (int)this->m_VoiceHeadModels)
        ;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x124))(piVar4,0xff,0xff,0xff,0);
          piVar4 = *(int **)((int)&__DT_REL[iVar10 * 2 + 0x530].r_info +
                            (int)this->m_VoiceHeadModels);
          (**(code **)(*piVar4 + 0x128))(piVar4,0,0,0,0xff);
          piVar4 = *(int **)((int)&__DT_REL[iVar10 * 2 + 0x530].r_info +
                            (int)this->m_VoiceHeadModels);
          (**(code **)(*piVar4 + 0x204))(piVar4,&DAT_000c4b6e,local_220);
        }
        *(int *)((int)&__DT_REL[iVar10 * 2 + 0x532].r_offset + (int)this->m_VoiceHeadModels) = iVar1
        ;
      }
    }
  }
LAB_000a3220:
  RepositionLabels(this);
LAB_000a3228:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CVoiceStatus::UpdateServerState  @ 000a20a0  (line 501)

/* DWARF original prototype: void UpdateServerState(CVoiceStatus * this, bool bForce) */

void __thiscall CVoiceStatus::UpdateServerState(CVoiceStatus *this,bool bForce)

{
  int iVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  qboolean qVar5;
  uint uVar6;
  int iVar7;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  uint local_a3c;
  char *local_a34;
  char *local_a30;
  char local_a20 [512];
  char local_820 [2048];
  int local_20;
  
                    /* Unresolved local var: char * pLevelName@[???]
                       Unresolved local var: int bCVarModEnable@[???]
                       Unresolved local var: char[2048] str@[???]
                       Unresolved local var: bool bChange@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar3 = (*gEngfuncs.pfnGetLevelName)();
  if (*pcVar3 == '\0') {
    (*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
    if (extraout_ST0 != (longdouble)0) {
      (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::UpdateServerState: pLevelName[0]==0\n");
    }
  }
  else {
    (*gEngfuncs.pfnGetCvarFloat)("voice_modenable");
    uVar4 = (uint)(NAN((longdouble)0) || NAN(extraout_ST0_00));
    if ((longdouble)0 != extraout_ST0_00) {
      uVar4 = 1;
    }
    if ((bForce) || (uVar4 != this->m_bServerModEnable)) {
                    /* Unresolved local var: char[256] str@[???] */
      this->m_bServerModEnable = uVar4;
      __snprintf_chk(local_a20,0x100,1,0x100,"VModEnable %d",uVar4);
      (*gEngfuncs.pfnServerCmd)(local_a20);
      (*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
      if (extraout_ST0_01 != (longdouble)0) {
                    /* Unresolved local var: char[256] msg@[???] */
        __sprintf_chk(local_820,1,0x100,"CVoiceStatus::UpdateServerState: Sending \'%s\'\n",
                      local_a20);
        (*gEngfuncs.pfnConsolePrint)(local_820);
      }
    }
    local_a30 = local_820;
    local_a34 = local_a20;
    builtin_strncpy(local_820,"vban",5);
    uVar4 = 0;
    local_a3c = 0;
                    /* Unresolved local var: ulong dw@[???]
                       Unresolved local var: ulong serverBanMask@[???]
                       Unresolved local var: ulong banMask@[???]
                       Unresolved local var: char[512] numStr@[???]
                       Unresolved local var: ulong i@[???]
                       Unresolved local var: char[16] playerID@[???] */
    iVar7 = 0;
    do {
      while( true ) {
        iVar1 = iVar7 + 1;
        qVar5 = (*gEngfuncs.GetPlayerUniqueID)(iVar1,local_a34);
        if (qVar5 == 0) break;
        bVar2 = CVoiceBanMgr::GetPlayerBan(&this->m_BanMgr,local_a34);
        if (bVar2) {
          local_a3c = local_a3c | 1 << ((byte)iVar7 & 0x1f);
        }
        uVar6 = 1 << ((byte)iVar7 & 0x1f);
        if (((this->m_ServerBannedPlayers).m_DWords[0] & uVar6) != 0) {
          uVar4 = uVar4 | uVar6;
        }
        iVar7 = iVar1;
        if (iVar1 == 0x20) goto LAB_000a2252;
      }
      iVar7 = iVar1;
    } while (iVar1 != 0x20);
LAB_000a2252:
    __sprintf_chk(local_a34,1,0x200,&DAT_000cadfa,local_a3c);
    __strcat_chk(local_a30,local_a34,0x800);
    if ((local_a3c != uVar4) || (bForce)) {
      (*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
      if (extraout_ST0_04 != (longdouble)0) {
                    /* Unresolved local var: char[256] msg@[???] */
        __sprintf_chk(local_a34,1,0x100,"CVoiceStatus::UpdateServerState: Sending \'%s\'\n",
                      local_a30);
        (*gEngfuncs.pfnConsolePrint)(local_a34);
      }
      (*gEngfuncs.pfnServerCmdUnreliable)(local_a30);
      (*gEngfuncs.GetClientTime)();
      this->m_LastUpdateServerState = (float)extraout_ST0_05;
    }
    else {
      (*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
      if (extraout_ST0_02 != (longdouble)0) {
        (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::UpdateServerState: no change\n");
      }
      (*gEngfuncs.GetClientTime)();
      this->m_LastUpdateServerState = (float)extraout_ST0_03;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CVoiceStatus::UpdateSpeakerImage  @ 000a26e0  (line 584)

/* DWARF original prototype: void UpdateSpeakerImage(CVoiceStatus * this, Label * pLabel, int
   iPlayer) */

void __thiscall CVoiceStatus::UpdateSpeakerImage(CVoiceStatus *this,Label *pLabel,int iPlayer)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int in_GS_OFFSET;
  double dVar5;
  char local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: Label * pPanel@[???]
                       Unresolved local var: char[16] playerID@[???]
                       Unresolved local var: bool bBlink@[???]
                       Unresolved local var: bool bTalking@[???]
                       Unresolved local var: bool bBanned@[???]
                       Unresolved local var: bool bNeverSpoken@[???] */
  this->m_pBanButtons[iPlayer + -1] = pLabel;
  if (pLabel != (Label *)0x0) {
    bVar2 = HACK_GetPlayerUniqueID(iPlayer,local_30);
    if (bVar2) {
      dVar5 = fmod(this->m_BlinkTimer,0.6);
                    /* try { // try from 000a277c to 000b2780 has its CatchHandler @ 000a24f0 */
      iVar4 = iPlayer + -1 >> 5;
      uVar1 = (&this->m_VoicePlayers)[iVar4].m_DWords[0];
                    /* try { // try from 000a278f to 000b281d has its CatchHandler @ 000a2f86 */
      bVar2 = CVoiceBanMgr::GetPlayerBan(&this->m_BanMgr,local_30);
      if (bVar2) {
                    /* try { // try from 000a2829 to 000b282d has its CatchHandler @ 000a24f0 */
        (**(code **)(*(int *)pLabel + 0x1fc))(pLabel,this->m_pScoreboardBanned);
      }
      else {
        uVar3 = 1 << ((byte)(iPlayer + -1) & 0x1f);
        if ((uVar1 & uVar3) == 0) {
          if (((&this->m_VoiceEnabledPlayers)[iVar4].m_DWords[0] & uVar3) == 0) {
            (**(code **)(*(int *)pLabel + 0x1fc))(pLabel,this->m_pScoreboardNeverSpoken);
            (**(code **)(*(int *)pLabel + 0x124))(pLabel,100,100,100,1);
          }
          else {
            (**(code **)(*(int *)pLabel + 0x1fc))(pLabel,this->m_pScoreboardNotSpeaking);
          }
        }
        else {
          if (dVar5 < 0.3) {
            (**(code **)(*(int *)pLabel + 0x1fc))(pLabel,this->m_pScoreboardSpeaking2);
          }
          else {
            (**(code **)(*(int *)pLabel + 0x1fc))(pLabel,this->m_pScoreboardSpeaking);
          }
          (**(code **)(*(int *)pLabel + 0x124))(pLabel,0xff,0xaa,0,1);
        }
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CVoiceStatus::UpdateBanButton  @ 000a28d0  (line 590)

/* DWARF original prototype: void UpdateBanButton(CVoiceStatus * this, int iClient) */

void __thiscall CVoiceStatus::UpdateBanButton(CVoiceStatus *this,int iClient)

{
  Label *pLVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int in_GS_OFFSET;
  double dVar5;
  char acStack_30 [16];
  int iStack_20;
  
                    /* Unresolved local var: Label * pPanel@[???]
                       Unresolved local var: char[16] playerID@[???]
                       Unresolved local var: bool bBlink@[???]
                       Unresolved local var: bool bTalking@[???]
                       Unresolved local var: bool bBanned@[???]
                       Unresolved local var: bool bNeverSpoken@[???] */
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  pLVar1 = this->m_pBanButtons[iClient];
  if (pLVar1 != (Label *)0x0) {
    bVar3 = HACK_GetPlayerUniqueID(iClient + 1,acStack_30);
    if (bVar3) {
      dVar5 = fmod(this->m_BlinkTimer,0.6);
      uVar2 = (&this->m_VoicePlayers)[iClient >> 5].m_DWords[0];
      bVar3 = CVoiceBanMgr::GetPlayerBan(&this->m_BanMgr,acStack_30);
      if (bVar3) {
        (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1,this->m_pScoreboardBanned);
      }
      else {
        uVar4 = 1 << ((byte)iClient & 0x1f);
        if ((uVar2 & uVar4) == 0) {
          if (((&this->m_VoiceEnabledPlayers)[iClient >> 5].m_DWords[0] & uVar4) == 0) {
            (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1,this->m_pScoreboardNeverSpoken);
            (**(code **)(*(int *)pLVar1 + 0x124))(pLVar1,100,100,100,1);
          }
          else {
            (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1,this->m_pScoreboardNotSpeaking);
          }
        }
        else {
          if (dVar5 < 0.3) {
            (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1,this->m_pScoreboardSpeaking2);
          }
          else {
            (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1,this->m_pScoreboardSpeaking);
          }
          (**(code **)(*(int *)pLVar1 + 0x124))(pLVar1,0xff,0xaa,0,1);
        }
      }
    }
  }
  if (iStack_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CVoiceStatus::HandleVoiceMaskMsg  @ 000a2ab0  (line 637)

/* DWARF original prototype: void HandleVoiceMaskMsg(CVoiceStatus * this, int iSize, void * pbuf) */

void __thiscall CVoiceStatus::HandleVoiceMaskMsg(CVoiceStatus *this,int iSize,void *pbuf)

{
  uint32 uVar1;
  int iVar2;
  int in_GS_OFFSET;
  longdouble lVar3;
  char acStack_110 [256];
  int local_10;
  
                    /* Unresolved local var: ulong dw@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  BEGIN_READ(pbuf,iSize);
  uVar1 = READ_LONG();
  (this->m_AudiblePlayers).m_DWords[0] = uVar1;
  uVar1 = READ_LONG();
  (this->m_ServerBannedPlayers).m_DWords[0] = uVar1;
  lVar3 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
  if (lVar3 != (longdouble)0) {
                    /* Unresolved local var: char[256] str@[???] */
    (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::HandleVoiceMaskMsg\n");
    __sprintf_chk(acStack_110,1,0x100,"    - m_AudiblePlayers[%d] = %lu\n",0,
                  (this->m_AudiblePlayers).m_DWords[0]);
    (*gEngfuncs.pfnConsolePrint)(acStack_110);
    __sprintf_chk(acStack_110,1,0x100,"    - m_ServerBannedPlayers[%d] = %lu\n",0,
                  (this->m_ServerBannedPlayers).m_DWords[0]);
    (*gEngfuncs.pfnConsolePrint)(acStack_110);
  }
  iVar2 = READ_BYTE();
  this->m_bServerModEnable = iVar2;
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CVoiceStatus::HandleReqStateMsg  @ 000a2bd0  (line 663)

/* DWARF original prototype: void HandleReqStateMsg(CVoiceStatus * this, int iSize, void * pbuf) */

void __thiscall CVoiceStatus::HandleReqStateMsg(CVoiceStatus *this,int iSize,void *pbuf)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
  if (lVar1 != (longdouble)0) {
    (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::HandleReqStateMsg\n");
  }
  UpdateServerState(this,true);
  return;
}


// CVoiceStatus::StartSquelchMode  @ 000a2c20  (line 673)

/* DWARF original prototype: void StartSquelchMode(CVoiceStatus * this) */

void __thiscall CVoiceStatus::StartSquelchMode(CVoiceStatus *this)

{
  if (this->m_bInSquelchMode != false) {
    return;
  }
  this->m_bInSquelchMode = true;
                    /* WARNING: Could not recover jumptable at 0x000a2c43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*this->m_pHelper->_vptr_IVoiceStatusHelper[3])();
  return;
}


// CVoiceStatus::StopSquelchMode  @ 000a2c50  (line 682)

/* DWARF original prototype: void StopSquelchMode(CVoiceStatus * this) */

void __thiscall CVoiceStatus::StopSquelchMode(CVoiceStatus *this)

{
  this->m_bInSquelchMode = false;
                    /* WARNING: Could not recover jumptable at 0x000a2c67. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*this->m_pHelper->_vptr_IVoiceStatusHelper[3])();
  return;
}


// CVoiceStatus::IsInSquelchMode  @ 000a2c70  (line 689)

/* DWARF original prototype: bool IsInSquelchMode(CVoiceStatus * this) */

bool __thiscall CVoiceStatus::IsInSquelchMode(CVoiceStatus *this)

{
  return this->m_bInSquelchMode;
}


// CVoiceStatus::FindVoiceLabel  @ 000a2c80  (line 693)

/* DWARF original prototype: CVoiceLabel * FindVoiceLabel(CVoiceStatus * this, int clientindex) */

CVoiceLabel * __thiscall CVoiceStatus::FindVoiceLabel(CVoiceStatus *this,int clientindex)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (clientindex == this->m_Labels[0].m_clientindex) {
    iVar1 = 0;
  }
  else if (clientindex == this->m_Labels[1].m_clientindex) {
    iVar1 = 1;
  }
  else if (clientindex == this->m_Labels[2].m_clientindex) {
    iVar1 = 2;
  }
  else if (clientindex == this->m_Labels[3].m_clientindex) {
    iVar1 = 3;
  }
  else if (clientindex == this->m_Labels[4].m_clientindex) {
    iVar1 = 4;
  }
  else if (clientindex == this->m_Labels[5].m_clientindex) {
    iVar1 = 5;
  }
  else {
    if (this->m_Labels[6].m_clientindex != clientindex) {
      return (CVoiceLabel *)0x0;
    }
    iVar1 = 6;
  }
  return this->m_Labels + iVar1;
}


// CVoiceStatus::GetFreeVoiceLabel  @ 000a2d30  (line 705)

/* DWARF original prototype: CVoiceLabel * GetFreeVoiceLabel(CVoiceStatus * this) */

CVoiceLabel * __thiscall CVoiceStatus::GetFreeVoiceLabel(CVoiceStatus *this)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (this->m_Labels[0].m_clientindex == -1) {
    iVar1 = 0;
  }
  else if (this->m_Labels[1].m_clientindex == -1) {
    iVar1 = 1;
  }
  else if (this->m_Labels[2].m_clientindex == -1) {
    iVar1 = 2;
  }
  else if (this->m_Labels[3].m_clientindex == -1) {
    iVar1 = 3;
  }
  else if (this->m_Labels[4].m_clientindex == -1) {
    iVar1 = 4;
  }
  else if (this->m_Labels[5].m_clientindex == -1) {
    iVar1 = 5;
  }
  else {
    if (this->m_Labels[6].m_clientindex != -1) {
      return (CVoiceLabel *)0x0;
    }
    iVar1 = 6;
  }
  return this->m_Labels + iVar1;
}


// CVoiceStatus::RepositionLabels  @ 000a2df0  (line 711)

/* DWARF original prototype: void RepositionLabels(CVoiceStatus * this) */

void __thiscall CVoiceStatus::RepositionLabels(CVoiceStatus *this)

{
  Image *pIVar1;
  Label *pLVar2;
  int iVar3;
  ImagePanel *pIVar4;
  int iVar5;
  int iVar6;
  Label **ppLVar7;
  longdouble extraout_ST0;
  int local_38;
  int local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int y@[???]
                       Unresolved local var: int iconWide@[???]
                       Unresolved local var: int iconTall@[???] */
  local_2c = 8;
  local_28 = 8;
  local_38 = gHUD.m_scrinfo.iHeight / 2;
  pIVar1 = this->m_pSpeakerLabelIcon;
  if (pIVar1 != (Image *)0x0) {
    (**(code **)(*(int *)pIVar1 + 8))(pIVar1,&local_2c,&local_28);
  }
                    /* try { // try from 000a2e49 to 000b2e91 has its CatchHandler @ 000a24f0 */
  ppLVar7 = &this->m_Labels[0].m_pBackground;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceLabel * pLabel@[???]
                       Unresolved local var: int textWide@[???]
                       Unresolved local var: int textTall@[???]
                       Unresolved local var: int border@[???]
                       Unresolved local var: int bgWide@[???]
                       Unresolved local var: int bgTall@[???]
                       Unresolved local var: int iconLeft@[???]
                       Unresolved local var: int iconTop@[???] */
  do {
                    /* catch() { ... } // from try @ 000a260e with catch @ 000a2f94 */
    while ((ppLVar7[2] != (Label *)0xffffffff &&
           (pLVar2 = ((CVoiceLabel *)(ppLVar7 + -1))->m_pLabel, pLVar2 != (Label *)0x0))) {
      (**(code **)(*(int *)pLVar2 + 0x214))(pLVar2,&local_24,local_20);
      iVar3 = (gHUD.m_scrinfo.iWidth * 2) / 3;
      if (iVar3 < local_24) {
        local_24 = iVar3;
      }
      iVar6 = local_24 + local_2c + 6;
                    /* try { // try from 000a2ec3 to 000b2ec7 has its CatchHandler @ 000a2f56 */
      iVar3 = local_28;
      if (local_28 <= local_20[0]) {
        iVar3 = local_20[0];
      }
      iVar5 = iVar3 + 4;
                    /* try { // try from 000a2ed5 to 000b2f67 has its CatchHandler @ 000a24f0 */
      (**(code **)(*(int *)*ppLVar7 + 0x10))
                (*ppLVar7,(gHUD.m_scrinfo.iWidth - iVar6) + -8,local_38,iVar6,iVar5);
      (**(code **)(*(int *)((CVoiceLabel *)(ppLVar7 + -1))->m_pLabel + 0x10))
                (((CVoiceLabel *)(ppLVar7 + -1))->m_pLabel,2,(iVar5 - local_20[0]) / 2,local_24,
                 local_20[0]);
      pIVar4 = (ImagePanel *)ppLVar7[1];
      if (pIVar4 != (ImagePanel *)0x0) {
        iVar5 = iVar5 - local_28;
                    /* catch() { ... } // from try @ 000a257c with catch @ 000a2f44 */
        iVar6 = local_24 + 4;
        (**(code **)(*(int *)pIVar4 + 0x1fc))(pIVar4,this->m_pSpeakerLabelIcon);
                    /* catch() { ... } // from try @ 000a2ec3 with catch @ 000a2f56 */
                    /* catch() { ... } // from try @ 000a2e35 with catch @ 000a2f68 */
                    /* catch() { ... } // from try @ 000a2da7 with catch @ 000a2f6a */
                    /* catch() { ... } // from try @ 000a2b5d with catch @ 000a2f72 */
        (**(code **)(*(int *)ppLVar7[1] + 0x10))
                  ((ImagePanel *)ppLVar7[1],iVar6,iVar5 / 2,local_2c,local_28);
      }
                    /* catch() { ... } // from try @ 000a2b2c with catch @ 000a2f7e */
                    /* catch() { ... } // from try @ 000a28f4 with catch @ 000a2f82 */
                    /* catch() { ... } // from try @ 000a283c with catch @ 000a2f84 */
      local_38 = local_38 + 6 + iVar3;
LAB_000a2f8b:
      ppLVar7 = ppLVar7 + 4;
                    /* catch() { ... } // from try @ 000a26d0 with catch @ 000a2f92 */
      if (this + 1 == (CVoiceStatus *)ppLVar7) goto LAB_000a2fbb;
    }
    pLVar2 = *ppLVar7;
    if (pLVar2 == (Label *)0x0) goto LAB_000a2f8b;
    ppLVar7 = ppLVar7 + 4;
    (**(code **)(*(int *)pLVar2 + 0x24))(pLVar2,0);
  } while (this + 1 != (CVoiceStatus *)ppLVar7);
LAB_000a2fbb:
  if ((this->m_pLocalBitmap == (BitmapTGA *)0x0) || (this->m_pAckBitmap == (BitmapTGA *)0x0)) {
    pIVar4 = this->m_pLocalLabel;
  }
  else {
    pIVar4 = this->m_pLocalLabel;
    if ((pIVar4 != (ImagePanel *)0x0) &&
       ((this->m_bTalking != false || (this->m_bServerAcked != false)))) {
                    /* Unresolved local var: int sizeX@[???]
                       Unresolved local var: int sizeY@[???]
                       Unresolved local var: int local_xPos@[???]
                       Unresolved local var: int local_yPos@[???] */
      (**(code **)(*(int *)pIVar4 + 0x40))(pIVar4,*this->m_pParentPanel);
      (**(code **)(*(int *)this->m_pLocalLabel + 0x24))(this->m_pLocalLabel,1);
      if ((this->m_bServerAcked == false) ||
         ((*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug"), extraout_ST0 == (longdouble)0)) {
        (**(code **)(*(int *)this->m_pLocalLabel + 0x1fc))(this->m_pLocalLabel,this->m_pLocalBitmap)
        ;
      }
      else {
        (**(code **)(*(int *)this->m_pLocalLabel + 0x1fc))(this->m_pLocalLabel,this->m_pAckBitmap);
      }
      (**(code **)(*(int *)this->m_pLocalBitmap + 8))(this->m_pLocalBitmap,&local_24,local_20);
      iVar6 = gHUD.m_scrinfo.iWidth - local_24;
      iVar3 = (*this->m_pHelper->_vptr_IVoiceStatusHelper[4])(this->m_pHelper);
      (*(code *)**(undefined4 **)this->m_pLocalLabel)
                (this->m_pLocalLabel,iVar6 + -10,iVar3 - local_20[0]);
      return;
    }
  }
  (**(code **)(*(int *)pIVar4 + 0x24))(pIVar4,0);
  return;
}


// CVoiceStatus::FreeBitmaps  @ 000a36a0  (line 788)

/* DWARF original prototype: void FreeBitmaps(CVoiceStatus * this) */

void __thiscall CVoiceStatus::FreeBitmaps(CVoiceStatus *this)

{
  Label *pLVar1;
  ImagePanel *pIVar2;
  Label **ppLVar3;
  
  operator_delete(this->m_pLocalBitmap);
  this->m_pLocalBitmap = (BitmapTGA *)0x0;
  ppLVar3 = this->m_pBanButtons;
  operator_delete(this->m_pAckBitmap);
  this->m_pAckBitmap = (BitmapTGA *)0x0;
  operator_delete(this->m_pSpeakerLabelIcon);
  this->m_pSpeakerLabelIcon = (Image *)0x0;
  operator_delete(this->m_pScoreboardNeverSpoken);
  this->m_pScoreboardNeverSpoken = (BitmapTGA *)0x0;
  operator_delete(this->m_pScoreboardNotSpeaking);
  this->m_pScoreboardNotSpeaking = (BitmapTGA *)0x0;
  operator_delete(this->m_pScoreboardSpeaking);
  this->m_pScoreboardSpeaking = (BitmapTGA *)0x0;
  operator_delete(this->m_pScoreboardSpeaking2);
  this->m_pScoreboardSpeaking2 = (BitmapTGA *)0x0;
  operator_delete(this->m_pScoreboardSquelch);
  this->m_pScoreboardSquelch = (BitmapTGA *)0x0;
  operator_delete(this->m_pScoreboardBanned);
  this->m_pScoreboardBanned = (BitmapTGA *)0x0;
  do {
                    /* Unresolved local var: int i@[???] */
    pLVar1 = *ppLVar3;
    if (pLVar1 != (Label *)0x0) {
      (**(code **)(*(int *)pLVar1 + 0x1fc))(pLVar1,0);
    }
    ppLVar3 = ppLVar3 + 1;
  } while (ppLVar3 != (Label **)&this->m_bInSquelchMode);
  pIVar2 = this->m_pLocalLabel;
  if (pIVar2 != (ImagePanel *)0x0) {
    (**(code **)(*(int *)pIVar2 + 0x1fc))(pIVar2,0);
  }
  return;
}


// CVoiceStatus::IsPlayerBlocked  @ 000a3db0  (line 836)

/* DWARF original prototype: bool IsPlayerBlocked(CVoiceStatus * this, int iPlayer) */

bool __thiscall CVoiceStatus::IsPlayerBlocked(CVoiceStatus *this,int iPlayer)

{
  bool bVar1;
  qboolean qVar2;
  int in_GS_OFFSET;
  char local_20 [16];
  int local_10;
  
                    /* Unresolved local var: char[16] playerID@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  qVar2 = (*gEngfuncs.GetPlayerUniqueID)(iPlayer,local_20);
  bVar1 = false;
  if (qVar2 != 0) {
    bVar1 = CVoiceBanMgr::GetPlayerBan(&this->m_BanMgr,local_20);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CVoiceStatus::IsPlayerAudible  @ 000a3e20  (line 850)

/* DWARF original prototype: bool IsPlayerAudible(CVoiceStatus * this, int iPlayer) */

bool __thiscall CVoiceStatus::IsPlayerAudible(CVoiceStatus *this,int iPlayer)

{
  return ((&this->m_AudiblePlayers)[iPlayer + -1 >> 5].m_DWords[0] &
         1 << ((byte)(iPlayer + -1) & 0x1f)) != 0;
}


// CVoiceStatus::SetPlayerBlockedState  @ 000a3e50  (line 860)

/* DWARF original prototype: void SetPlayerBlockedState(CVoiceStatus * this, int iPlayer, bool
   blocked) */

void __thiscall CVoiceStatus::SetPlayerBlockedState(CVoiceStatus *this,int iPlayer,bool blocked)

{
  bool bVar1;
  qboolean qVar2;
  int in_GS_OFFSET;
  longdouble lVar3;
  char local_130 [16];
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char[16] playerID@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  lVar3 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
  if (lVar3 != (longdouble)0) {
    (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::SetPlayerBlockedState part 1\n");
  }
  qVar2 = (*gEngfuncs.GetPlayerUniqueID)(iPlayer,local_130);
  if (qVar2 != 0) {
    lVar3 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
    if (lVar3 != (longdouble)0) {
      (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::SetPlayerBlockedState part 2\n");
    }
    lVar3 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
                    /* Unresolved local var: char[256] str@[???] */
    if (lVar3 != (longdouble)0) {
      bVar1 = CVoiceBanMgr::GetPlayerBan(&this->m_BanMgr,local_130);
      __sprintf_chk(local_120,1,0x100,
                    "CVoiceStatus::SetPlayerBlockedState: setting player %d ban to %d\n",iPlayer,
                    !bVar1);
      (*gEngfuncs.pfnConsolePrint)(local_120);
    }
    CVoiceBanMgr::SetPlayerBan(&this->m_BanMgr,local_130,blocked);
    UpdateServerState(this,false);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// _GLOBAL__sub_I_g_VoiceStatus  @ 00047b20  (line 885)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_VoiceStatus(void)

{
  CVoiceStatus::CVoiceStatus(&g_VoiceStatus);
  __cxa_atexit(CVoiceStatus::~CVoiceStatus,&g_VoiceStatus,&__dso_handle);
  return;
}


