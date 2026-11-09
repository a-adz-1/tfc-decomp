// Ghidra decompilation of functions from cl_dll/vgui_teammenu.cpp
// 7 functions, ordered by original source line

// CTeamMenuPanel::CTeamMenuPanel  @ 000a0cd0  (line 49)

/* DWARF original prototype: void CTeamMenuPanel(CTeamMenuPanel * this, int iTrans, int iRemoveMe,
   int x, int y, int wide, int tall) */

void __thiscall
CTeamMenuPanel::CTeamMenuPanel
          (CTeamMenuPanel *this,int iTrans,int iRemoveMe,int x,int y,int wide,int tall)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  CSchemeManager *this_00;
  SchemeHandle_t schemeHandle;
  SchemeHandle_t schemeHandle_00;
  SchemeHandle_t schemeHandle_01;
  Font *pFVar5;
  Label *pLVar6;
  char *pcVar7;
  CTransparentPanel *this_01;
  LineBorder *pLVar8;
  CTFScrollPanel *this_02;
  TextPanel *pTVar9;
  undefined4 uVar10;
  CommandButton *pCVar11;
  undefined4 *puVar12;
  int iVar13;
  CommandButton **ppCVar14;
  int iVar15;
  int in_GS_OFFSET;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  Color local_120 [256];
  int local_20;
  
                    /* Unresolved local var: CSchemeManager * pSchemes@[???]
                       Unresolved local var: SchemeHandle_t hTitleScheme@[???]
                       Unresolved local var: SchemeHandle_t hTeamWindowText@[???]
                       Unresolved local var: SchemeHandle_t hTeamInfoText@[???]
                       Unresolved local var: Font * pTitleFont@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: Label * pLabel@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Panel::Panel((Panel *)this,x,y,wide,tall);
  *(undefined ***)&(this->super_CMenuPanel).super_CTransparentPanel = &PTR_setPos_000ca938;
  (this->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
  (this->super_CMenuPanel).m_iIsActive = 0;
  (this->super_CMenuPanel).super_CTransparentPanel.m_iTransparency = iTrans;
  (this->super_CMenuPanel).m_flOpenTime = 0.0;
  (this->super_CMenuPanel).m_iRemoveMe = iRemoveMe;
  this_00 = &gViewPort->m_SchemeManager;
  schemeHandle = CSchemeManager::getSchemeHandle(this_00,"Title Font");
  schemeHandle_00 = CSchemeManager::getSchemeHandle(this_00,"Briefing Text");
  schemeHandle_01 = CSchemeManager::getSchemeHandle(this_00,"Team Info Text");
  pFVar5 = CSchemeManager::getFont(this_00,schemeHandle);
  pLVar6 = operator_new(0xd0);
  vgui::Label::Label(pLVar6,"",(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),
                     (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 32.0));
  vgui::Panel::setParent((Panel *)pLVar6);
  (**(code **)(*(int *)pLVar6 + 0x20c))(pLVar6,pFVar5);
  CSchemeManager::getFgColor(this_00,schemeHandle,&local_130,&local_12c,&local_128,&local_124);
  (**(code **)(*(int *)pLVar6 + 0x124))(pLVar6,local_130,local_12c,local_128,local_124);
  CSchemeManager::getBgColor(this_00,schemeHandle,&local_130,&local_12c,&local_128,&local_124);
  (**(code **)(*(int *)pLVar6 + 0x128))(pLVar6,local_130,local_12c,local_128,local_124);
  (**(code **)(*(int *)pLVar6 + 0x21c))(pLVar6,3);
  pcVar1 = *(code **)(*(int *)pLVar6 + 0x204);
  pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Title_SelectYourTeam");
  (*pcVar1)(pLVar6,&DAT_000c4b6e,pcVar7);
  this_01 = operator_new(0xc0);
  vgui::Panel::Panel(&this_01->super_Panel,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 176.0),
                     (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 80.0),
                     (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 424.0),
                     (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 312.0));
  this_01->m_iTransparency = 0xff;
  *(undefined ***)this_01 = &PTR_setPos_000c3f80;
  this->m_pTeamWindow = this_01;
  vgui::Panel::setParent(&this_01->super_Panel);
  pcVar1 = *(code **)(*(int *)this->m_pTeamWindow + 0xd4);
  vgui::Color::Color(local_120,0xb2,0x76,0,0);
  pLVar8 = operator_new(0x44);
  vgui::LineBorder::LineBorder(pLVar8,local_120);
  (*pcVar1)(this->m_pTeamWindow,pLVar8);
  pLVar6 = operator_new(0xd0);
  vgui::Label::Label(pLVar6,"",(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0),
                     (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 16.0));
  this->m_pMapTitle = pLVar6;
  vgui::Label::setFont((Font *)pLVar6);
  (**(code **)(*(int *)this->m_pMapTitle + 0x40))(this->m_pMapTitle,this->m_pTeamWindow);
  CSchemeManager::getFgColor(this_00,schemeHandle,&local_130,&local_12c,&local_128,&local_124);
  (**(code **)(*(int *)this->m_pMapTitle + 0x124))
            (this->m_pMapTitle,local_130,local_12c,local_128,local_124);
  CSchemeManager::getBgColor(this_00,schemeHandle,&local_130,&local_12c,&local_128,&local_124);
  (**(code **)(*(int *)this->m_pMapTitle + 0x128))
            (this->m_pMapTitle,local_130,local_12c,local_128,local_124);
  (**(code **)(*(int *)this->m_pMapTitle + 0x21c))(this->m_pMapTitle,3);
  this_02 = operator_new(0xd0);
  fVar2 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0;
  CTFScrollPanel::CTFScrollPanel
            (this_02,(int)fVar2,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 48.0),
             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 424.0 - (fVar2 + fVar2)),
             (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 178.0));
  this->m_pScrollPanel = &this_02->super_ScrollPanel;
  vgui::Panel::setParent((Panel *)this_02);
  (**(code **)(*(int *)this->m_pScrollPanel + 0x1fc))(this->m_pScrollPanel,0,0);
  pTVar9 = operator_new(0xc0);
  vgui::TextPanel::TextPanel
            (pTVar9,"",0,0,
             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 424.0 -
                  ((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0),
             (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 178.0));
  iVar13 = *(int *)pTVar9;
  this->m_pBriefing = pTVar9;
  pcVar1 = *(code **)(iVar13 + 0x40);
  uVar10 = (**(code **)(*(int *)this->m_pScrollPanel + 0x204))(this->m_pScrollPanel);
  (*pcVar1)(this->m_pBriefing,uVar10);
  pcVar1 = *(code **)(*(int *)this->m_pBriefing + 0x204);
  pFVar5 = CSchemeManager::getFont(this_00,schemeHandle_00);
  (*pcVar1)(this->m_pBriefing,pFVar5);
  CSchemeManager::getFgColor(this_00,schemeHandle_00,&local_130,&local_12c,&local_128,&local_124);
  (**(code **)(*(int *)this->m_pBriefing + 0x124))
            (this->m_pBriefing,local_130,local_12c,local_128,local_124);
  CSchemeManager::getBgColor(this_00,schemeHandle_00,&local_130,&local_12c,&local_128,&local_124);
  (**(code **)(*(int *)this->m_pBriefing + 0x128))
            (this->m_pBriefing,local_130,local_12c,local_128,local_124);
  pcVar1 = *(code **)(*(int *)this->m_pBriefing + 0x1fc);
  pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Map_Description_not_available");
  (*pcVar1)(this->m_pBriefing,pcVar7);
  ppCVar14 = this->m_pButtons;
  iVar13 = 1;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] sz@[???]
                       Unresolved local var: int iYPos@[???] */
    ppCVar14 = ppCVar14 + 1;
    fVar2 = (float)gHUD.m_scrinfo.iHeight / 480.0;
    pCVar11 = operator_new(0x130);
    CommandButton::CommandButton
              (pCVar11,"",(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),
               (int)(fVar2 * 80.0 + (float)iVar13 * (fVar2 * 8.0 + fVar2 * 24.0)),
               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 124.0),
               (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0),true);
    *ppCVar14 = pCVar11;
    vgui::Panel::setParent((Panel *)pCVar11);
    (**(code **)(*(int *)*ppCVar14 + 0x21c))(*ppCVar14,3);
    (**(code **)(*(int *)*ppCVar14 + 0x24))(*ppCVar14,0);
    if (iVar13 == 5) {
      CommandButton::setBoundKey(this->m_pButtons[5],'5');
      pcVar1 = *(code **)(*(int *)this->m_pButtons[5] + 0x264);
      pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Team_AutoAssign");
      (*pcVar1)(this->m_pButtons[5],pcVar7);
      (**(code **)(*(int *)this->m_pButtons[5] + 0x24))(this->m_pButtons[5],1);
    }
    __sprintf_chk(local_120,1,0x100,"jointeam %d",iVar13);
    pcVar1 = *(code **)(*(int *)*ppCVar14 + 0x240);
    puVar12 = operator_new(0x108);
    strncpy((char *)(puVar12 + 1),(char *)local_120,0x100);
    puVar12[0x41] = 1;
    pCVar11 = *ppCVar14;
    *(undefined1 *)((int)puVar12 + 0x103) = 0;
    *puVar12 = &PTR_actionPerformed_000c64ac;
    (*pcVar1)(pCVar11,puVar12);
    pcVar1 = *(code **)(*(int *)*ppCVar14 + 0x70);
    puVar12 = operator_new(0xc);
    pCVar11 = *ppCVar14;
    *puVar12 = &PTR_cursorMoved_000c5da8;
    puVar12[1] = iVar13;
    puVar12[2] = this;
    (*pcVar1)(pCVar11,puVar12);
    pTVar9 = operator_new(0xc0);
    fVar2 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 424.0;
    fVar4 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 234.0;
    fVar3 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0;
    vgui::TextPanel::TextPanel
              (pTVar9,"",(int)fVar3,(int)fVar4,(int)(fVar2 - fVar3),(int)(fVar2 - fVar4));
    ppCVar14[-6] = (CommandButton *)pTVar9;
    vgui::Panel::setParent((Panel *)pTVar9);
    pcVar1 = *(code **)(*(int *)ppCVar14[-6] + 0x204);
    pFVar5 = CSchemeManager::getFont(this_00,schemeHandle_01);
    (*pcVar1)((TextPanel *)ppCVar14[-6],pFVar5);
    iVar15 = iVar13 + 1;
    iVar13 = iVar13 % iNumberOfTeamColors;
    (**(code **)(*(int *)ppCVar14[-6] + 0x124))
              ((TextPanel *)ppCVar14[-6],iTeamColors[iVar13][0],iTeamColors[iVar13][1],
               iTeamColors[iVar13][2],0);
    (**(code **)(*(int *)ppCVar14[-6] + 0x128))((TextPanel *)ppCVar14[-6],0,0,0,0xff);
    iVar13 = iVar15;
  } while (iVar15 != 6);
  pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Menu_Cancel");
  pCVar11 = operator_new(0x130);
  CommandButton::CommandButton
            (pCVar11,pcVar7,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),0,
             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 124.0),
             (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0),false);
  this->m_pCancelButton = pCVar11;
  vgui::Panel::setParent((Panel *)pCVar11);
  pcVar1 = *(code **)(*(int *)this->m_pCancelButton + 0x240);
  puVar12 = operator_new(8);
  pCVar11 = this->m_pCancelButton;
  *puVar12 = &PTR_actionPerformed_000c3f74;
  puVar12[1] = 0;
  (*pcVar1)(pCVar11,puVar12);
  pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Menu_Spectate");
  pCVar11 = operator_new(0x130);
  CommandButton::CommandButton
            (pCVar11,pcVar7,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),0,
             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 124.0),
             (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0),true);
  *(undefined ***)pCVar11 = &PTR_setPos_000c8684;
  this->m_pSpectateButton = pCVar11;
  vgui::Panel::setParent((Panel *)pCVar11);
  pcVar1 = *(code **)(*(int *)this->m_pSpectateButton + 0x240);
  puVar12 = operator_new(0x108);
  *puVar12 = &PTR_actionPerformed_000c3f68;
  strncpy((char *)(puVar12 + 1),"spectate",0x100);
  pCVar11 = this->m_pSpectateButton;
  puVar12[0x41] = 1;
  *(undefined1 *)((int)puVar12 + 0x103) = 0;
  (*pcVar1)(pCVar11,puVar12);
  CommandButton::setBoundKey(this->m_pSpectateButton,'6');
  pcVar1 = *(code **)(*(int *)this->m_pSpectateButton + 0x70);
  puVar12 = operator_new(0xc);
  pCVar11 = this->m_pSpectateButton;
  *puVar12 = &PTR_cursorMoved_000c5da8;
  puVar12[1] = 6;
  puVar12[2] = this;
  (*pcVar1)(pCVar11,puVar12);
  this->m_bUpdatedMapName = false;
  this->m_iCurrentInfo = 0;
  (**(code **)(*(int *)this->m_pScrollPanel + 0x20c))(this->m_pScrollPanel,0,0);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTeamMenuPanel::Initialize  @ 000a0310  (line 161)

/* DWARF original prototype: void Initialize(CTeamMenuPanel * this) */

void __thiscall CTeamMenuPanel::Initialize(CTeamMenuPanel *this)

{
  this->m_iCurrentInfo = 0;
  this->m_bUpdatedMapName = false;
  (**(code **)(*(int *)this->m_pScrollPanel + 0x20c))(this->m_pScrollPanel,0,0);
  return;
}


// CTeamMenuPanel::Update  @ 000a0470  (line 171)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Update(CTeamMenuPanel * this) */

void __thiscall CTeamMenuPanel::Update(CTeamMenuPanel *this)

{
  char cVar1;
  CommandButton *pCVar2;
  size_t sVar3;
  char *pcVar4;
  byte *pbVar5;
  int *piVar6;
  hud_player_info_t *phVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int in_GS_OFFSET;
  char *pcVar11;
  int local_9e4;
  CommandButton **local_9dc;
  int local_9d8;
  team_info_t *local_9d0;
  undefined4 local_9c4;
  undefined4 local_9c0;
  char local_9ba [32];
  undefined2 local_99a [542];
  undefined1 local_55e;
  char local_55d [1340];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int iYPos@[???] */
                    /* Unresolved local var: int i@[???] */
  iVar9 = 1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_9d0 = g_TeamInfo;
  local_9dc = this->m_pButtons;
  local_9d8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 80.0);
  do {
    local_9dc = local_9dc + 1;
    pCVar2 = *local_9dc;
    if (pCVar2 != (CommandButton *)0x0) {
      if (gViewPort->m_iNumberOfTeams < iVar9) {
        (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,0);
      }
      else {
                    /* Unresolved local var: char[32] sz@[???]
                       Unresolved local var: char[1085] szPlayerList@[???]
                       Unresolved local var: int iTotal@[???] */
        (**(code **)(*(int *)pCVar2 + 0x264))(pCVar2,gViewPort->m_sTeamNames[iVar9]);
        __sprintf_chk(local_9ba,1,0x20,"%d",iVar9);
        CommandButton::setBoundKey(*local_9dc,local_9ba[0]);
        (**(code **)(*(int *)*local_9dc + 0x24))(*local_9dc,1);
        (*(code *)**(undefined4 **)*local_9dc)
                  (*local_9dc,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),local_9d8);
        local_9d8 = (int)((float)local_9d8 +
                         ((float)gHUD.m_scrinfo.iHeight / 480.0) * 8.0 +
                         ((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0);
        if (this->m_iCurrentInfo == 0) {
          (**(code **)(*(int *)&(this->super_CMenuPanel).super_CTransparentPanel + 0x20c))
                    (this,iVar9);
        }
        phVar7 = g_PlayerInfoList + 1;
        local_99a[0] = 10;
        psVar10 = &g_PlayerExtraInfo[1].teamnumber;
        local_9e4 = 0;
        do {
          while (((pcVar11 = phVar7->name, pcVar11 != (char *)0x0 && (phVar7->thisplayer == '\0'))
                 && (*psVar10 == iVar9))) {
            local_9e4 = local_9e4 + 1;
            if (local_9e4 != 1) {
              sVar3 = strlen((char *)local_99a);
              __strncat_chk(local_99a,&DAT_000ca8a0,0x43d - sVar3,0x43d);
            }
            phVar7 = phVar7 + 1;
            psVar10 = psVar10 + 0xe;
            sVar3 = strlen((char *)local_99a);
            __strncat_chk(local_99a,pcVar11,0x43d - sVar3,0x43d);
            local_55e = 0;
            if (phVar7 == g_PlayerInfoList + 0x40) goto LAB_000a06b0;
          }
          phVar7 = phVar7 + 1;
          psVar10 = psVar10 + 0xe;
                    /* Unresolved local var: int j@[???] */
        } while (phVar7 != g_PlayerInfoList + 0x40);
LAB_000a06b0:
        if (local_9e4 == 0) {
          (**(code **)(*(int *)local_9dc[-6] + 0x1fc))((TextPanel *)local_9dc[-6],"");
        }
        else {
                    /* Unresolved local var: char[1341] szText@[???] */
          if (local_9e4 == 1) {
            local_9e4 = 1;
            pcVar11 = "%s: %d Player (%d points)";
          }
          else {
            pcVar11 = "%s: %d Players (%d points)";
          }
          __sprintf_chk(local_55d,1,0x53d,pcVar11,gViewPort->m_sTeamNames + iVar9,local_9e4,
                        (int)local_9d0[1].frags);
          sVar3 = strlen(local_55d);
          __strncat_chk(local_55d,local_99a,0x53d - sVar3,0x53d);
          local_21 = 0;
          (**(code **)(*(int *)local_9dc[-6] + 0x1fc))((TextPanel *)local_9dc[-6],local_55d);
        }
      }
    }
    local_9d0 = local_9d0 + 1;
    iVar9 = iVar9 + 1;
    if (iVar9 == 5) {
      (*(code *)**(undefined4 **)this->m_pButtons[5])
                (this->m_pButtons[5],(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),local_9d8)
      ;
      iVar8 = (int)((float)local_9d8 +
                   ((float)gHUD.m_scrinfo.iHeight / 480.0) * 8.0 +
                   ((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0);
      iVar9 = (**(code **)(*(int *)this->m_pSpectateButton + 0x260))(this->m_pSpectateButton);
      if (iVar9 == 0) {
        (*(code *)**(undefined4 **)this->m_pSpectateButton)
                  (this->m_pSpectateButton,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),
                   iVar8);
        (**(code **)(*(int *)this->m_pSpectateButton + 0x24))(this->m_pSpectateButton,1);
        iVar8 = (int)((float)iVar8 +
                     ((float)gHUD.m_scrinfo.iHeight / 480.0) * 8.0 +
                     ((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0);
      }
      else {
        (**(code **)(*(int *)this->m_pSpectateButton + 0x24))(this->m_pSpectateButton,0);
      }
      if (g_iTeamNumber == 0) {
        (**(code **)(*(int *)this->m_pCancelButton + 0x24))(this->m_pCancelButton,0);
        cVar1 = this->m_bUpdatedMapName;
      }
      else {
        (*(code *)**(undefined4 **)this->m_pCancelButton)
                  (this->m_pCancelButton,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),iVar8)
        ;
        (**(code **)(*(int *)this->m_pCancelButton + 0x24))(this->m_pCancelButton,1);
        cVar1 = this->m_bUpdatedMapName;
      }
                    /* Unresolved local var: char * level@[???] */
      if (((cVar1 == '\0') && (pcVar11 = (*gEngfuncs.pfnGetLevelName)(), pcVar11 != (char *)0x0)) &&
         (*pcVar11 != '\0')) {
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: char[256] szTitle@[???]
                       Unresolved local var: char * ch@[???]
                       Unresolved local var: char * pfile@[???] */
        __strcpy_chk(local_99a,pcVar11,0x100);
        pcVar4 = strchr((char *)local_99a,0x2f);
        if (pcVar4 == (char *)0x0) {
          pcVar4 = strchr((char *)local_99a,0x5c);
        }
        __strcpy_chk(local_55d,pcVar4 + 1,0x100);
        pcVar4 = strchr(local_55d,0x2e);
        *pcVar4 = '\0';
        (**(code **)(*(int *)this->m_pMapTitle + 0x204))(this->m_pMapTitle,&DAT_000c4b6e,local_55d);
        *pcVar4 = '.';
        __strcpy_chk(local_99a,pcVar11,0x100);
        pcVar11 = strchr((char *)local_99a,0x2e);
        *pcVar11 = '\0';
        __strcat_chk(local_99a,".txt",0x100);
        pbVar5 = (*gEngfuncs.COM_LoadFile)((char *)local_99a,5,(int *)0x0);
        if (pbVar5 != (byte *)0x0) {
                    /* Unresolved local var: int iXSize@[???]
                       Unresolved local var: int iYSize@[???] */
          (**(code **)(*(int *)this->m_pBriefing + 0x1fc))(this->m_pBriefing,pbVar5);
          piVar6 = (int *)(**(code **)(*(int *)this->m_pBriefing + 0x208))(this->m_pBriefing);
          (**(code **)(*piVar6 + 100))(piVar6,&local_9c4,&local_9c0);
          (**(code **)(*(int *)this->m_pBriefing + 8))(this->m_pBriefing,local_9c4,local_9c0);
          (*gEngfuncs.COM_FreeFile)(pbVar5);
        }
        this->m_bUpdatedMapName = true;
      }
      (**(code **)(*(int *)this->m_pScrollPanel + 0x220))(this->m_pScrollPanel);
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}


// CTeamMenuPanel::SlotInput  @ 000a0ba0  (line 319)

/* DWARF original prototype: bool SlotInput(CTeamMenuPanel * this, int iSlot) */

bool __thiscall CTeamMenuPanel::SlotInput(CTeamMenuPanel *this,int iSlot)

{
  CommandButton *pCVar1;
  bool bVar2;
  char cVar3;
  
  if (iSlot == 5) {
    (**(code **)(*(int *)this->m_pButtons[5] + 600))(this->m_pButtons[5]);
    bVar2 = true;
  }
  else if (iSlot == 6) {
    (**(code **)(*(int *)this->m_pSpectateButton + 600))(this->m_pSpectateButton);
    bVar2 = true;
  }
  else {
    if ((0 < iSlot) && (iSlot <= gViewPort->m_iNumberOfTeams)) {
      pCVar1 = this->m_pButtons[iSlot];
      if (pCVar1 != (CommandButton *)0x0) {
        cVar3 = (**(code **)(*(int *)pCVar1 + 0x28))(pCVar1);
        if (cVar3 != '\0') {
          (**(code **)(*(int *)this->m_pButtons[iSlot] + 600))(this->m_pButtons[iSlot]);
          return (bool)cVar3;
        }
      }
    }
    bVar2 = false;
  }
  return bVar2;
}


// CTeamMenuPanel::Open  @ 000a0350  (line 353)

/* DWARF original prototype: void Open(CTeamMenuPanel * this) */

void __thiscall CTeamMenuPanel::Open(CTeamMenuPanel *this)

{
  (**(code **)(*(int *)&(this->super_CMenuPanel).super_CTransparentPanel + 0x210))(this);
  (**(code **)(*(int *)&(this->super_CMenuPanel).super_CTransparentPanel + 0x24))(this,1);
  (this->super_CMenuPanel).m_flOpenTime = gHUD.m_flTime;
  return;
}


// CTeamMenuPanel::paintBackground  @ 000a0c50  (line 359)

/* DWARF original prototype: void paintBackground(CTeamMenuPanel * this) */

void __thiscall CTeamMenuPanel::paintBackground(CTeamMenuPanel *this)

{
  int iVar1;
  
  if (this->m_bUpdatedMapName == false) {
    (**(code **)(*(int *)&(this->super_CMenuPanel).super_CTransparentPanel + 0x210))(this);
  }
  iVar1 = (this->super_CMenuPanel).super_CTransparentPanel.m_iTransparency;
  if (iVar1 != 0) {
    (**(code **)(*(int *)&(this->super_CMenuPanel).super_CTransparentPanel + 0x178))
              (this,0,0,0,iVar1);
    (**(code **)(*(int *)&(this->super_CMenuPanel).super_CTransparentPanel + 0x17c))
              (this,0,0,*(undefined4 *)&(this->super_CMenuPanel).super_CTransparentPanel.field_0xc,
               *(undefined4 *)&(this->super_CMenuPanel).super_CTransparentPanel.field_0x10);
  }
  return;
}


// CTeamMenuPanel::SetActiveInfo  @ 000a0390  (line 370)

/* DWARF original prototype: void SetActiveInfo(CTeamMenuPanel * this, int iInput) */

void __thiscall CTeamMenuPanel::SetActiveInfo(CTeamMenuPanel *this,int iInput)

{
  CommandButton **ppCVar1;
  CommandButton **ppCVar2;
  
  (**(code **)(*(int *)this->m_pSpectateButton + 0x234))(this->m_pSpectateButton,0);
  ppCVar1 = this->m_pButtons + 1;
  do {
                    /* Unresolved local var: int i@[???] */
    ppCVar2 = ppCVar1 + 1;
    (**(code **)(*(int *)*ppCVar1 + 0x234))(*ppCVar1,0);
    (**(code **)(*(int *)ppCVar1[-6] + 0x24))((TextPanel *)ppCVar1[-6],0);
    ppCVar1 = ppCVar2;
  } while (ppCVar2 != (CommandButton **)&this->m_bUpdatedMapName);
  if (iInput == 6) {
    (**(code **)(*(int *)this->m_pSpectateButton + 0x234))(this->m_pSpectateButton,1);
  }
  else {
    (**(code **)(*(int *)this->m_pButtons[iInput] + 0x234))(this->m_pButtons[iInput],1);
    (**(code **)(*(int *)this->m_pTeamInfoPanel[iInput] + 0x24))(this->m_pTeamInfoPanel[iInput],1);
  }
  this->m_iCurrentInfo = iInput;
                    /* WARNING: Could not recover jumptable at 0x000a0445. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->m_pScrollPanel + 0x220))();
  return;
}


