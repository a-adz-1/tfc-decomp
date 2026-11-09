// Ghidra decompilation of functions from cl_dll/vgui_MOTDWindow.cpp
// 2 functions, ordered by original source line

// CMessageWindowPanel_Create  @ 0008bd00  (line 61)

CMenuPanel *
CMessageWindowPanel_Create
          (char *szMOTD,char *szTitle,int iShadeFullscreen,int iRemoveMe,int x,int y,int wide,
          int tall)

{
  CMessageWindowPanel *this;
  
  this = operator_new(0xd8);
  CMessageWindowPanel::CMessageWindowPanel
            (this,szMOTD,szTitle,iShadeFullscreen,iRemoveMe,x,y,wide,tall);
  return &this->super_CMenuPanel;
}


// CMessageWindowPanel::CMessageWindowPanel  @ 0008b4a0  (line 68)

/* DWARF original prototype: void CMessageWindowPanel(CMessageWindowPanel * this, char * szMOTD,
   char * szTitle, int iShadeFullscreen, int iRemoveMe, int x, int y, int wide, int tall) */

void __thiscall
CMessageWindowPanel::CMessageWindowPanel
          (CMessageWindowPanel *this,char *szMOTD,char *szTitle,int iShadeFullscreen,int iRemoveMe,
          int x,int y,int wide,int tall)

{
  CSchemeManager *this_00;
  code *pcVar1;
  float fVar2;
  float fVar3;
  TeamFortressViewport *pTVar4;
  SchemeHandle_t schemeHandle;
  SchemeHandle_t schemeHandle_00;
  CTransparentPanel *this_01;
  LineBorder *pLVar5;
  Label *this_02;
  Font *pFVar6;
  CTFScrollPanel *this_03;
  TextPanel *this_04;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char *text;
  CommandButton *this_05;
  undefined4 *puVar11;
  int in_GS_OFFSET;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  Color local_2c [12];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Panel::Panel((Panel *)this,x,y,wide,tall);
                    /* Unresolved local var: CSchemeManager * pSchemes@[???]
                       Unresolved local var: SchemeHandle_t hTitleScheme@[???]
                       Unresolved local var: SchemeHandle_t hMOTDText@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int iXSize@[???]
                       Unresolved local var: int iYSize@[???]
                       Unresolved local var: int iXPos@[???]
                       Unresolved local var: int iYPos@[???]
                       Unresolved local var: Label * pLabel@[???]
                       Unresolved local var: ScrollPanel * pScrollPanel@[???]
                       Unresolved local var: TextPanel * pText@[???]
                       Unresolved local var: int iScrollSizeX@[???]
                       Unresolved local var: int iScrollSizeY@[???]
                       Unresolved local var: CommandButton * pButton@[???] */
  (this->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
  *(undefined ***)&(this->super_CMenuPanel).super_CTransparentPanel = &PTR_setPos_000c5e18;
  (this->super_CMenuPanel).super_CTransparentPanel.m_iTransparency =
       (-(uint)(iShadeFullscreen == 0) & 0x9b) + 100;
  pTVar4 = gViewPort;
  (this->super_CMenuPanel).m_iIsActive = 0;
  (this->super_CMenuPanel).m_flOpenTime = 0.0;
  (this->super_CMenuPanel).m_iRemoveMe = iRemoveMe;
  this_00 = &pTVar4->m_SchemeManager;
  schemeHandle = CSchemeManager::getSchemeHandle(this_00,"Title Font");
  schemeHandle_00 = CSchemeManager::getSchemeHandle(this_00,"Briefing Text");
  this_01 = operator_new(0xc0);
  vgui::Panel::Panel(&this_01->super_Panel,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 112.0),
                     (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 80.0),
                     (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 424.0),
                     (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 312.0));
  this_01->m_iTransparency = (-(uint)(iShadeFullscreen == 0) & 0xffffff65) + 0xff;
  *(undefined ***)this_01 = &PTR_setPos_000c3f80;
  this->m_pBackgroundPanel = this_01;
  vgui::Panel::setParent(&this_01->super_Panel);
  pcVar1 = *(code **)(*(int *)this->m_pBackgroundPanel + 0xd4);
  vgui::Color::Color(local_2c,0xb2,0x76,0,0);
  pLVar5 = operator_new(0x44);
  vgui::LineBorder::LineBorder(pLVar5,local_2c);
  (*pcVar1)(this->m_pBackgroundPanel,pLVar5);
  (**(code **)(*(int *)this->m_pBackgroundPanel + 0x24))(this->m_pBackgroundPanel,1);
  (**(code **)(*(int *)this->m_pBackgroundPanel + 4))(this->m_pBackgroundPanel,&local_3c,&local_38);
  (**(code **)(*(int *)this->m_pBackgroundPanel + 0xc))
            (this->m_pBackgroundPanel,&local_44,&local_40);
  this_02 = operator_new(0xd0);
  vgui::Label::Label(this_02,"",
                     (int)((float)local_3c + ((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0),
                     (int)((float)local_38 + ((float)gHUD.m_scrinfo.iHeight / 480.0) * 16.0));
  vgui::Panel::setParent((Panel *)this_02);
  pcVar1 = *(code **)(*(int *)this_02 + 0x20c);
  pFVar6 = CSchemeManager::getFont(this_00,schemeHandle);
  (*pcVar1)(this_02,pFVar6);
  (**(code **)(*(int *)this_02 + 0x208))(this_02,1);
  CSchemeManager::getFgColor(this_00,schemeHandle,&local_54,&local_50,&local_4c,&local_48);
  (**(code **)(*(int *)this_02 + 0x124))(this_02,local_54,local_50,local_4c,local_48);
  (**(code **)(*(int *)this_02 + 0x11c))(this_02,3);
  CSchemeManager::getBgColor(this_00,schemeHandle,&local_54,&local_50,&local_4c,&local_48);
  (**(code **)(*(int *)this_02 + 0x128))(this_02,local_54,local_50,local_4c,local_48);
  (**(code **)(*(int *)this_02 + 0x21c))(this_02,3);
  (**(code **)(*(int *)this_02 + 0x204))(this_02,&DAT_000c4b6e,szTitle);
  this_03 = operator_new(0xd0);
  fVar2 = (float)gHUD.m_scrinfo.iHeight / 480.0;
  fVar3 = fVar2 * 16.0;
  CTFScrollPanel::CTFScrollPanel
            (this_03,(int)((float)local_3c + ((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0),
             (int)(fVar3 + fVar3 + (float)local_38 + fVar3),
             (int)((float)local_44 - ((float)gHUD.m_scrinfo.iWidth / 640.0) * 32.0),
             (int)((float)local_40 - (fVar2 * 48.0 + fVar2 * 30.0 + fVar2 * 30.0)));
  vgui::Panel::setParent((Panel *)this_03);
  (**(code **)(*(int *)this_03 + 0x200))(this_03,0,0);
  (**(code **)(*(int *)this_03 + 0x1fc))(this_03,1,1);
  (**(code **)(*(int *)this_03 + 0x220))(this_03);
  this_04 = operator_new(0xc0);
  vgui::TextPanel::TextPanel(this_04,"",0,0,0x40,0x40);
  (**(code **)(*(int *)this_03 + 0x204))(this_03);
  vgui::Panel::setParent((Panel *)this_04);
  pcVar1 = *(code **)(*(int *)this_04 + 0x204);
  pFVar6 = CSchemeManager::getFont(this_00,schemeHandle_00);
  (*pcVar1)(this_04,pFVar6);
  CSchemeManager::getFgColor(this_00,schemeHandle_00,&local_54,&local_50,&local_4c,&local_48);
  (**(code **)(*(int *)this_04 + 0x124))(this_04,local_54,local_50,local_4c,local_48);
  CSchemeManager::getBgColor(this_00,schemeHandle_00,&local_54,&local_50,&local_4c,&local_48);
  (**(code **)(*(int *)this_04 + 0x128))(this_04,local_54,local_50,local_4c,local_48);
  (**(code **)(*(int *)this_04 + 0x1fc))(this_04,szMOTD);
  piVar7 = (int *)(**(code **)(*(int *)this_04 + 0x208))(this_04);
  pcVar1 = *(code **)(*piVar7 + 0x14);
  piVar8 = (int *)(**(code **)(*(int *)this_03 + 0x208))(this_03);
  uVar9 = (**(code **)(*piVar8 + 0x1c))(piVar8);
  piVar8 = (int *)(**(code **)(*(int *)this_03 + 0x208))(this_03);
  uVar10 = (**(code **)(*piVar8 + 0x18))(piVar8);
  (*pcVar1)(piVar7,uVar10,uVar9);
  piVar7 = (int *)(**(code **)(*(int *)this_04 + 0x208))(this_04);
  (**(code **)(*piVar7 + 0x68))(piVar7,&local_34,&local_30);
  (**(code **)(*(int *)this_04 + 8))(this_04,local_34,local_30);
  (**(code **)(*(int *)this_03 + 0x200))(this_03,1,1);
  (**(code **)(*(int *)this_03 + 0x1fc))(this_03,0,0);
  (**(code **)(*(int *)this_03 + 0x220))(this_03);
  text = CHudTextMessage::BufferedLocaliseTextString("#Menu_OK");
  this_05 = operator_new(0x130);
  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
  CommandButton::CommandButton
            (this_05,text,(int)((float)local_3c + ((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0),
             (int)(((float)(local_40 + local_38) - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 16.0) -
                  fVar2),(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,false);
  puVar11 = operator_new(8);
  *puVar11 = &PTR_actionPerformed_000c3f74;
  puVar11[1] = 0;
  vgui::Button::addActionSignal((ActionSignal *)this_05);
  (**(code **)(*(int *)this_05 + 0x40))(this_05,this);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


