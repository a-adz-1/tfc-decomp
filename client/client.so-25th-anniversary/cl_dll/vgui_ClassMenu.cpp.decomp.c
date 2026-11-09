// Ghidra decompilation of functions from cl_dll/vgui_ClassMenu.cpp
// 7 functions, ordered by original source line

// CClassMenuPanel::CClassMenuPanel  @ 00086c10  (line 56)

/* DWARF original prototype: void CClassMenuPanel(CClassMenuPanel * this, int iTrans, int iRemoveMe,
   int x, int y, int wide, int tall) */

void __thiscall
CClassMenuPanel::CClassMenuPanel
          (CClassMenuPanel *this,int iTrans,int iRemoveMe,int x,int y,int wide,int tall)

{
  code *pcVar1;
  ClassButton *pCVar2;
  ScrollPanel *pSVar3;
  float fVar4;
  int iVar5;
  CSchemeManager *this_00;
  SchemeHandle_t schemeHandle;
  SchemeHandle_t schemeHandle_00;
  Label *pLVar6;
  Font *pFVar7;
  char *pcVar8;
  CTFScrollPanel *this_01;
  LineBorder *pLVar9;
  int *piVar10;
  int iVar11;
  CImageLabel *pCVar12;
  int iVar13;
  int iVar14;
  byte *pbVar15;
  TextPanel *this_02;
  int iVar16;
  undefined4 *puVar17;
  CTransparentPanel *this_03;
  CommandButton *pCVar18;
  uint uVar19;
  uint uVar20;
  byte *pbVar21;
  CClassMenuPanel *pCVar22;
  int iVar23;
  CImageLabel *(*papCVar24) [12];
  int in_GS_OFFSET;
  bool bVar25;
  byte bVar26;
  ClassButton *local_180;
  int local_174;
  CClassMenuPanel *local_170;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  undefined2 local_120 [128];
  int local_20;
  
  bVar26 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Panel::Panel((Panel *)this,x,y,wide,tall);
  uVar20 = 0xc00;
  (this->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
                    /* Unresolved local var: bool bShowClassGraphic@[???]
                       Unresolved local var: CSchemeManager * pSchemes@[???]
                       Unresolved local var: SchemeHandle_t hTitleScheme@[???]
                       Unresolved local var: SchemeHandle_t hClassWindowText@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: Label * pLabel@[???]
                       Unresolved local var: int clientWide@[???] */
  papCVar24 = this->m_pClassImages;
  (this->super_CMenuPanel).m_iIsActive = 0;
  bVar25 = ((uint)papCVar24 & 1) != 0;
  (this->super_CMenuPanel).m_flOpenTime = 0.0;
  (this->super_CMenuPanel).super_CTransparentPanel.m_iTransparency = iTrans;
  *(undefined ***)&(this->super_CMenuPanel).super_CTransparentPanel = &PTR_setPos_000c4184;
  (this->super_CMenuPanel).m_iRemoveMe = iRemoveMe;
  iVar5 = gHUD.m_scrinfo.iWidth;
  if (bVar25) {
    uVar20 = 0xbff;
    papCVar24 = (CImageLabel *(*) [12])((int)this->m_pClassImages[0] + 1);
    *(undefined1 *)this->m_pClassImages[0] = 0;
  }
  if (((uint)papCVar24 & 2) != 0) {
    *(undefined2 *)*papCVar24 = 0;
    papCVar24 = (CImageLabel *(*) [12])((int)*papCVar24 + 2);
    uVar20 = uVar20 - 2;
  }
  if (((uint)papCVar24 & 4) != 0) {
    (*papCVar24)[0] = (CImageLabel *)0x0;
    uVar20 = uVar20 - 4;
    papCVar24 = (CImageLabel *(*) [12])(*papCVar24 + 1);
  }
  for (uVar19 = uVar20 >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
    (*papCVar24)[0] = (CImageLabel *)0x0;
    papCVar24 = (CImageLabel *(*) [12])((int)papCVar24 + (uint)bVar26 * -8 + 4);
  }
  if ((uVar20 & 2) != 0) {
    *(undefined2 *)*papCVar24 = 0;
    papCVar24 = (CImageLabel *(*) [12])((int)*papCVar24 + 2);
  }
  if (bVar25) {
    *(undefined1 *)*papCVar24 = 0;
  }
  this_00 = &gViewPort->m_SchemeManager;
  schemeHandle = CSchemeManager::getSchemeHandle(this_00,"Title Font");
  schemeHandle_00 = CSchemeManager::getSchemeHandle(this_00,"Briefing Text");
  pLVar6 = operator_new(0xd0);
  vgui::Label::Label(pLVar6,"",(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),
                     (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 32.0));
  vgui::Panel::setParent((Panel *)pLVar6);
  pcVar1 = *(code **)(*(int *)pLVar6 + 0x20c);
  pFVar7 = CSchemeManager::getFont(this_00,schemeHandle);
  (*pcVar1)(pLVar6,pFVar7);
  CSchemeManager::getFgColor(this_00,schemeHandle,&local_140,&local_13c,&local_138,&local_134);
  (**(code **)(*(int *)pLVar6 + 0x124))(pLVar6,local_140,local_13c,local_138,local_134);
  CSchemeManager::getBgColor(this_00,schemeHandle,&local_140,&local_13c,&local_138,&local_134);
  (**(code **)(*(int *)pLVar6 + 0x128))(pLVar6,local_140,local_13c,local_138,local_134);
  (**(code **)(*(int *)pLVar6 + 0x21c))(pLVar6,3);
  pcVar1 = *(code **)(*(int *)pLVar6 + 0x204);
  pcVar8 = CHudTextMessage::BufferedLocaliseTextString("#Title_SelectYourClass");
  (*pcVar1)(pLVar6,pcVar8);
  this_01 = operator_new(0xd0);
  CTFScrollPanel::CTFScrollPanel
            (this_01,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 176.0),
             (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 80.0),
             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 424.0),
             (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 312.0));
  this->m_pScrollPanel = &this_01->super_ScrollPanel;
  vgui::Panel::setParent((Panel *)this_01);
  (**(code **)(*(int *)this->m_pScrollPanel + 0x200))(this->m_pScrollPanel,0,0);
  (**(code **)(*(int *)this->m_pScrollPanel + 0x1fc))(this->m_pScrollPanel,1,1);
  pcVar1 = *(code **)(*(int *)this->m_pScrollPanel + 0xd4);
  vgui::Color::Color((Color *)local_120,0xb2,0x76,0,0);
  pLVar9 = operator_new(0x44);
  vgui::LineBorder::LineBorder(pLVar9,local_120);
  (*pcVar1)(this->m_pScrollPanel,pLVar9);
  (**(code **)(*(int *)this->m_pScrollPanel + 0x220))(this->m_pScrollPanel);
  piVar10 = (int *)(**(code **)(*(int *)this->m_pScrollPanel + 0x204))(this->m_pScrollPanel);
  iVar11 = (**(code **)(*piVar10 + 0x18))(piVar10);
  (**(code **)(*(int *)this->m_pScrollPanel + 0x200))(this->m_pScrollPanel,0,1);
  iVar23 = 0;
  (**(code **)(*(int *)this->m_pScrollPanel + 0x1fc))(this->m_pScrollPanel,0,0);
  (**(code **)(*(int *)this->m_pScrollPanel + 0x220))(this->m_pScrollPanel);
  pCVar22 = this;
  do {
    fVar4 = (float)gHUD.m_scrinfo.iHeight / 480.0;
    puVar17 = operator_new(0x108);
    pcVar8 = sTFClassSelection[iVar23];
    *puVar17 = &PTR_actionPerformed_000c3f68;
    strncpy((char *)(puVar17 + 1),pcVar8,0x100);
    puVar17[0x41] = 1;
    *(undefined1 *)((int)puVar17 + 0x103) = 0;
    *puVar17 = &PTR_actionPerformed_000c5ddc;
    pcVar8 = CHudTextMessage::BufferedLocaliseTextString(sLocalisedClasses[iVar23]);
    __sprintf_chk(local_120,1,0x100,&DAT_000c4b6e,pcVar8);
    local_180 = operator_new(0x134);
    CommandButton::CommandButton
              (&local_180->super_CommandButton,(char *)local_120,
               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),
               (int)(fVar4 * 80.0 + (float)iVar23 * (fVar4 * 8.0 + fVar4 * 24.0)),
               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 124.0),
               (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0),true);
    *(undefined ***)&local_180->super_CommandButton = &PTR_setPos_000c5240;
    local_180->m_iPlayerClass = iVar23;
    pCVar22->m_pButtons[0] = local_180;
    if (iVar23 - 1U < 9) {
      __sprintf_chk(local_120,1,0x100,"%d",iVar23);
      local_180 = pCVar22->m_pButtons[0];
    }
    else {
      local_120[0] = 0x30;
    }
    CommandButton::setBoundKey(&local_180->super_CommandButton,(char)local_120[0]._0_1_);
    (**(code **)(*(int *)&pCVar22->m_pButtons[0]->super_CommandButton + 0x21c))
              (pCVar22->m_pButtons[0],3);
    (**(code **)(*(int *)&pCVar22->m_pButtons[0]->super_CommandButton + 0x240))
              (pCVar22->m_pButtons[0],puVar17);
    pcVar1 = *(code **)(*(int *)&pCVar22->m_pButtons[0]->super_CommandButton + 0x70);
    puVar17 = operator_new(0xc);
    pCVar2 = pCVar22->m_pButtons[0];
    *puVar17 = &PTR_cursorMoved_000c5da8;
    puVar17[1] = iVar23;
    puVar17[2] = this;
    (*pcVar1)(pCVar2,puVar17);
    (**(code **)(*(int *)&pCVar22->m_pButtons[0]->super_CommandButton + 0x40))
              (pCVar22->m_pButtons[0],this);
    this_03 = operator_new(0xc0);
    vgui::Panel::Panel(&this_03->super_Panel,0,0,iVar11,
                       (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 312.0));
    pCVar22->m_pClassInfoPanel[0] = this_03;
    this_03->m_iTransparency = 0xff;
    pSVar3 = this->m_pScrollPanel;
    *(undefined ***)this_03 = &PTR_setPos_000c3f80;
    (**(code **)(*(int *)pSVar3 + 0x204))(pSVar3);
    vgui::Panel::setParent(&pCVar22->m_pClassInfoPanel[0]->super_Panel);
    if (iVar5 < 0x280) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] sz@[???]
                       Unresolved local var: int iYPos@[???]
                       Unresolved local var: ActionSignal * pASignal@[???]
                       Unresolved local var: int textOffs@[???]
                       Unresolved local var: char * localName@[???]
                       Unresolved local var: Label * pNameLabel@[???]
                       Unresolved local var: char * cText@[???]
                       Unresolved local var: char * pfile@[???]
                       Unresolved local var: TextPanel * pTextWindow@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: int xx@[???]
                       Unresolved local var: int yy@[???]
                       Unresolved local var: int maxX@[???]
                       Unresolved local var: int maxY@[???] */
      fVar4 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 8.0;
    }
    else {
      fVar4 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 150.0;
    }
    local_174 = (int)fVar4;
    __sprintf_chk(local_120,1,0x100,"#Title_%s",sTFClassSelection[iVar23]);
    pcVar8 = CHudTextMessage::BufferedLocaliseTextString((char *)local_120);
    pLVar6 = operator_new(0xd0);
    vgui::Label::Label(pLVar6,"",local_174,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 8.0));
    CSchemeManager::getFont(this_00,schemeHandle);
    vgui::Label::setFont((Font *)pLVar6);
    (**(code **)(*(int *)pLVar6 + 0x40))(pLVar6,pCVar22->m_pClassInfoPanel[0]);
    CSchemeManager::getFgColor(this_00,schemeHandle,&local_140,&local_13c,&local_138,&local_134);
    (**(code **)(*(int *)pLVar6 + 0x124))(pLVar6,local_140,local_13c,local_138,local_134);
    CSchemeManager::getBgColor(this_00,schemeHandle,&local_140,&local_13c,&local_138,&local_134);
    (**(code **)(*(int *)pLVar6 + 0x128))(pLVar6,local_140,local_13c,local_138,local_134);
    (**(code **)(*(int *)pLVar6 + 0x21c))(pLVar6,3);
    (**(code **)(*(int *)pLVar6 + 0x204))(pLVar6,&DAT_000c4b6e,pcVar8);
    if (0x27f < iVar5) {
      local_180 = (ClassButton *)0x0;
      local_170 = pCVar22;
      do {
                    /* Unresolved local var: int team@[???]
                       Unresolved local var: CImageLabel * pLabel@[???]
                       Unresolved local var: int xOut@[???]
                       Unresolved local var: int yOut@[???] */
        if (local_180 == (ClassButton *)0x1) {
          pcVar8 = "%sred";
        }
        else {
          pcVar8 = "%sblue";
        }
        __sprintf_chk(local_120,1,0x100,pcVar8,sTFClassSelection[iVar23]);
        pCVar12 = operator_new(0xd4);
        CImageLabel::CImageLabel
                  (pCVar12,(char *)local_120,0,0,
                   (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 150.0),
                   (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 80.0));
        local_170->m_pClassImages[0][0] = pCVar12;
        vgui::Panel::setParent((Panel *)pCVar12);
        if (local_180 != (ClassButton *)0x1) {
          (**(code **)(*(int *)pCVar12 + 0x24))(pCVar12,0);
        }
        (**(code **)(*(int *)pLVar6 + 0x210))(pLVar6,&local_128,&local_124);
        pcVar1 = (code *)**(undefined4 **)pCVar12;
        fVar4 = (float)gHUD.m_scrinfo.iWidth;
        iVar13 = local_124 / 2;
        iVar14 = (*(code *)(*(undefined4 **)pCVar12)[6])(pCVar12);
        (*pcVar1)(pCVar12,(int)(((fVar4 / 640.0) * 150.0 - (float)iVar14) * 0.5),iVar13);
        local_180 = (ClassButton *)((int)local_180 + 1);
        local_170 = (CClassMenuPanel *)
                    &(local_170->super_CMenuPanel).super_CTransparentPanel.field_0x30;
      } while (local_180 != (ClassButton *)0x2);
    }
    CHudTextMessage::LocaliseTextString
              ("#Title_CurrentlyOnYourTeam",this->m_sPlayersOnTeamString,0x80);
    pLVar6 = operator_new(0xd0);
    vgui::Label::Label(pLVar6,"",local_174,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 42.0));
    pCVar22->m_pPlayers[0] = pLVar6;
    vgui::Panel::setParent((Panel *)pLVar6);
    (**(code **)(*(int *)pCVar22->m_pPlayers[0] + 0x128))(pCVar22->m_pPlayers[0],0,0,0,0xff);
    (**(code **)(*(int *)pCVar22->m_pPlayers[0] + 0x21c))(pCVar22->m_pPlayers[0],3);
    pcVar1 = *(code **)(*(int *)pCVar22->m_pPlayers[0] + 0x20c);
    pFVar7 = CSchemeManager::getFont(this_00,schemeHandle_00);
    (*pcVar1)(pCVar22->m_pPlayers[0],pFVar7);
    __sprintf_chk(local_120,1,0x100,"classes/short_%s.txt",sTFClassSelection[iVar23]);
    pbVar15 = (*gEngfuncs.COM_LoadFile)((char *)local_120,5,(int *)0x0);
    pbVar21 = (byte *)"Class Description not available.";
    if (pbVar15 != (byte *)0x0) {
      pbVar21 = pbVar15;
    }
    this_02 = operator_new(0xc0);
    fVar4 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 80.0;
    vgui::TextPanel::TextPanel
              (this_02,(char *)pbVar21,local_174,(int)fVar4,
               (int)((((float)gHUD.m_scrinfo.iWidth / 640.0) * 424.0 - (float)local_174) - 5.0),
               (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 312.0 - fVar4));
    vgui::Panel::setParent((Panel *)this_02);
    pcVar1 = *(code **)(*(int *)this_02 + 0x204);
    pFVar7 = CSchemeManager::getFont(this_00,schemeHandle_00);
    (*pcVar1)(this_02,pFVar7);
    CSchemeManager::getFgColor(this_00,schemeHandle_00,&local_140,&local_13c,&local_138,&local_134);
    (**(code **)(*(int *)this_02 + 0x124))(this_02,local_140,local_13c,local_138,local_134);
    CSchemeManager::getBgColor(this_00,schemeHandle_00,&local_140,&local_13c,&local_138,&local_134);
    (**(code **)(*(int *)this_02 + 0x128))(this_02,local_140,local_13c,local_138,local_134);
    piVar10 = (int *)(**(code **)(*(int *)this_02 + 0x208))(this_02);
    (**(code **)(*piVar10 + 0x68))(piVar10,&local_130,&local_12c);
    (**(code **)(*(int *)this_02 + 8))(this_02,local_130,local_12c);
    (**(code **)(*(int *)this_02 + 4))(this_02,&local_128,&local_124);
    iVar13 = local_130 + local_128;
    iVar14 = local_12c + local_124;
    pCVar12 = pCVar22->m_pClassImages[0][0];
    if (pCVar12 != (CImageLabel *)0x0) {
      (**(code **)(*(int *)pCVar12 + 4))(pCVar12,&local_128,&local_124);
      pCVar12 = pCVar22->m_pClassImages[0][0];
      iVar16 = (**(code **)(*(int *)pCVar12 + 0x1c))(pCVar12);
      if (iVar14 < iVar16 + local_124) {
        pCVar12 = pCVar22->m_pClassImages[0][0];
        iVar14 = (**(code **)(*(int *)pCVar12 + 0x1c))(pCVar12);
        iVar14 = iVar14 + local_124;
      }
    }
    (**(code **)(*(int *)pCVar22->m_pClassInfoPanel[0] + 8))
              (pCVar22->m_pClassInfoPanel[0],iVar13,iVar14);
    if (pbVar15 != (byte *)0x0) {
      (*gEngfuncs.COM_FreeFile)(pbVar15);
    }
    iVar23 = iVar23 + 1;
    pCVar22 = (CClassMenuPanel *)&(pCVar22->super_CMenuPanel).super_CTransparentPanel.field_0x4;
  } while (iVar23 != 0xb);
  pcVar8 = CHudTextMessage::BufferedLocaliseTextString("#Menu_Cancel");
  pCVar18 = operator_new(0x130);
  CommandButton::CommandButton
            (pCVar18,pcVar8,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),0,
             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 124.0),
             (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0),false);
  this->m_pCancelButton = pCVar18;
  vgui::Panel::setParent((Panel *)pCVar18);
  pcVar1 = *(code **)(*(int *)this->m_pCancelButton + 0x240);
  puVar17 = operator_new(8);
  pCVar18 = this->m_pCancelButton;
  *puVar17 = &PTR_actionPerformed_000c3f74;
  puVar17[1] = 0;
  (*pcVar1)(pCVar18,puVar17);
  this->m_iCurrentInfo = 0;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CClassMenuPanel::Update  @ 000867c0  (line 254)

/* DWARF original prototype: void Update(CClassMenuPanel * this) */

void __thiscall CClassMenuPanel::Update(CClassMenuPanel *this)

{
  int *in_EAX;
  char *pcVar1;
  hud_player_info_t *phVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int in_GS_OFFSET;
  int *local_140;
  int local_134;
  undefined1 local_120 [256];
  int local_20;
  
                    /* Unresolved local var: int iYPos@[???] */
                    /* Unresolved local var: int i@[???] */
  iVar5 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_134 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 80.0);
  local_140 = in_EAX + 0x5b;
  do {
                    /* Unresolved local var: bool bCivilian@[???]
                       Unresolved local var: int iTotal@[???]
                       Unresolved local var: char[256] sz@[???] */
    iVar3 = gViewPort->m_iValidClasses[g_iTeamNumber];
    if (iVar3 == -1) {
      if (iVar5 == 0) {
        (**(code **)(*(int *)in_EAX[0x4d] + 0x24))((int *)in_EAX[0x4d],1);
        (**(code **)(*in_EAX + 0x20c))();
        local_134 = (int)((float)local_134 +
                         ((float)gHUD.m_scrinfo.iHeight / 480.0) * 8.0 +
                         ((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0);
      }
      else {
LAB_00086845:
        (**(code **)(*(int *)local_140[-0xe] + 0x24))((int *)local_140[-0xe],0);
      }
    }
    else {
      iVar6 = (**(code **)(*(int *)local_140[-0xe] + 0x260))((int *)local_140[-0xe]);
      if ((iVar6 != 0) || (iVar5 == 0)) goto LAB_00086845;
      (**(code **)(*(int *)local_140[-0xe] + 0x24))((int *)local_140[-0xe],1);
      (*(code *)**(undefined4 **)local_140[-0xe])
                ((undefined4 *)local_140[-0xe],(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),
                 local_134);
      local_134 = (int)((float)local_134 +
                       ((float)gHUD.m_scrinfo.iHeight / 480.0) * 8.0 +
                       ((float)gHUD.m_scrinfo.iHeight / 480.0) * 24.0);
      if (in_EAX[0x35b] == 0) {
        (**(code **)(*in_EAX + 0x20c))();
      }
    }
                    /* Unresolved local var: int j@[???] */
    phVar2 = g_PlayerInfoList + 1;
    pcVar1 = g_PlayerExtraInfo[1].teamname;
    iVar6 = 0;
    do {
      while (((((phVar2->name == (char *)0x0 || (*pcVar1 == '\0')) || (phVar2->thisplayer != '\0'))
              || (*(short *)(pcVar1 + -2) != g_iTeamNumber)) ||
             ((*(short *)(pcVar1 + -8) != iVar5 && (iVar3 != -1))))) {
        pcVar1 = pcVar1 + 0x1c;
        phVar2 = phVar2 + 1;
        if (pcVar1 == g_PlayerExtraInfo[0x40].teamname) goto LAB_000868c0;
      }
      pcVar1 = pcVar1 + 0x1c;
      iVar6 = iVar6 + 1;
      phVar2 = phVar2 + 1;
    } while (pcVar1 != g_PlayerExtraInfo[0x40].teamname);
LAB_000868c0:
    __sprintf_chk(local_120,1,0x100,in_EAX + 0x35c,iVar6);
    (**(code **)(*(int *)local_140[-0x1a] + 0x204))((int *)local_140[-0x1a],&DAT_000c4b6e,local_120)
    ;
    iVar3 = g_iTeamNumber % iNumberOfTeamColors;
    (**(code **)(*(int *)local_140[-0x1a] + 0x124))
              ((int *)local_140[-0x1a],iTeamColors[iVar3][0],iTeamColors[iVar3][1],
               iTeamColors[iVar3][2],0);
    piVar7 = local_140;
    do {
      while( true ) {
        piVar4 = (int *)*piVar7;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x24))(piVar4,0);
        }
        piVar4 = (int *)in_EAX[iVar5 + (g_iTeamNumber * 3 + -3) * 4 + 0x5b];
        if ((piVar4 != (int *)0x0) || (piVar4 = (int *)*local_140, piVar4 != (int *)0x0)) break;
        piVar7 = piVar7 + 0xc;
        if (local_140 + 0x300 == piVar7) goto LAB_000869c0;
      }
                    /* Unresolved local var: int team@[???] */
      piVar7 = piVar7 + 0xc;
      (**(code **)(*piVar4 + 0x24))(piVar4,1);
    } while (local_140 + 0x300 != piVar7);
LAB_000869c0:
    iVar5 = iVar5 + 1;
    local_140 = local_140 + 1;
    if (iVar5 == 0xb) {
      if (g_iPlayerClass == 0) {
        (**(code **)(*(int *)in_EAX[0x59] + 0x24))((int *)in_EAX[0x59],0);
      }
      else {
        (*(code *)**(undefined4 **)in_EAX[0x59])
                  ((undefined4 *)in_EAX[0x59],(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 40.0),
                   local_134);
        (**(code **)(*(int *)in_EAX[0x59] + 0x24))((int *)in_EAX[0x59],1);
      }
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}


// CClassMenuPanel::Update  @ 00086b90  (line 257)

/* DWARF original prototype: void Update(CClassMenuPanel * this) */

void __thiscall CClassMenuPanel::Update(CClassMenuPanel *this)

{
                    /* Unresolved local var: int iYPos@[???] */
  if (g_iTeamNumber != 0) {
    Update(this);
    return;
  }
  return;
}


// CClassMenuPanel::SlotInput  @ 00086710  (line 365)

/* DWARF original prototype: bool SlotInput(CClassMenuPanel * this, int iSlot) */

bool __thiscall CClassMenuPanel::SlotInput(CClassMenuPanel *this,int iSlot)

{
  ClassButton *pCVar1;
  int iVar2;
  
  if (((uint)iSlot < 10) && (pCVar1 = this->m_pButtons[iSlot], pCVar1 != (ClassButton *)0x0)) {
    if (iSlot == 0) {
      if (gViewPort->m_iValidClasses[g_iTeamNumber] == -1) {
        (**(code **)(*(int *)&this->m_pButtons[0]->super_CommandButton + 600))(this->m_pButtons[0]);
        return true;
      }
      pCVar1 = this->m_pButtons[10];
      iSlot = 10;
    }
    iVar2 = (**(code **)(*(int *)&pCVar1->super_CommandButton + 0x260))(pCVar1);
    if (iVar2 == 0) {
      (**(code **)(*(int *)&this->m_pButtons[iSlot]->super_CommandButton + 600))
                (this->m_pButtons[iSlot]);
      return true;
    }
  }
  return false;
}


// CClassMenuPanel::Open  @ 00086bb0  (line 397)

/* DWARF original prototype: void Open(CClassMenuPanel * this) */

void __thiscall CClassMenuPanel::Open(CClassMenuPanel *this)

{
  int iVar1;
  CClassMenuPanel *in_stack_ffffffe4;
  
  iVar1 = *(int *)&(this->super_CMenuPanel).super_CTransparentPanel;
  if (*(code **)(iVar1 + 0x210) == Update) {
                    /* Unresolved local var: int iYPos@[???] */
    if (g_iTeamNumber != 0) {
      Update(in_stack_ffffffe4);
      iVar1 = *(int *)&(this->super_CMenuPanel).super_CTransparentPanel;
    }
  }
  else {
    (**(code **)(iVar1 + 0x210))(this);
    iVar1 = *(int *)&(this->super_CMenuPanel).super_CTransparentPanel;
  }
  (**(code **)(iVar1 + 0x24))(this,1);
  (this->super_CMenuPanel).m_flOpenTime = gHUD.m_flTime;
  return;
}


// CClassMenuPanel::Initialize  @ 00086600  (line 406)

/* DWARF original prototype: void Initialize(CClassMenuPanel * this) */

void __thiscall CClassMenuPanel::Initialize(CClassMenuPanel *this)

{
  (**(code **)(*(int *)&(this->super_CMenuPanel).super_CTransparentPanel + 0x24))(this,0);
  (**(code **)(*(int *)this->m_pScrollPanel + 0x20c))(this->m_pScrollPanel,0,0);
  return;
}


// CClassMenuPanel::SetActiveInfo  @ 00086640  (line 414)

/* DWARF original prototype: void SetActiveInfo(CClassMenuPanel * this, int iInput) */

void __thiscall CClassMenuPanel::SetActiveInfo(CClassMenuPanel *this,int iInput)

{
  ClassButton **ppCVar1;
  ClassButton **ppCVar2;
  
  ppCVar1 = this->m_pButtons;
  do {
                    /* Unresolved local var: int i@[???] */
    ppCVar2 = ppCVar1 + 1;
    (**(code **)(*(int *)&(*ppCVar1)->super_CommandButton + 0x234))(*ppCVar1,0);
    (**(code **)(*(int *)ppCVar1[-0x18] + 0x24))((CTransparentPanel *)ppCVar1[-0x18],0);
    ppCVar1 = ppCVar2;
  } while (ppCVar2 != this->m_pButtons + 0xb);
  if (10 < (uint)iInput) {
    iInput = 0;
  }
  (**(code **)(*(int *)&this->m_pButtons[iInput]->super_CommandButton + 0x234))
            (this->m_pButtons[iInput],1);
  (**(code **)(*(int *)this->m_pClassInfoPanel[iInput] + 0x24))(this->m_pClassInfoPanel[iInput],1);
  this->m_iCurrentInfo = iInput;
  (**(code **)(*(int *)this->m_pScrollPanel + 0x20c))(this->m_pScrollPanel,0,0);
                    /* WARNING: Could not recover jumptable at 0x00086706. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->m_pScrollPanel + 0x220))();
  return;
}


