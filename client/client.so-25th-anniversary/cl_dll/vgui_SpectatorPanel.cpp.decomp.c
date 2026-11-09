// Ghidra decompilation of functions from cl_dll/vgui_SpectatorPanel.cpp
// 10 functions, ordered by original source line

// HUD_ChatInputPosition  @ 0009cbb0  (line 26)

void HUD_ChatInputPosition(int *x,int *y)

{
  float fVar1;
  int iVar2;
  
  if ((g_iUser1 == 0) && (iVar2 = (*gEngfuncs.IsSpectateOnly)(), iVar2 == 0)) {
    return;
  }
  if ((gHUD.m_Spectator.m_pip)->value != 0.0) {
    fVar1 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
      fVar1 = 1.0;
    }
    *y = (int)(fVar1 * (float)(gHUD.m_Spectator.m_OverviewData.insetWindowHeight + 5));
    return;
  }
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar2 = 0x40;
  }
  else {
    iVar2 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
  }
  *y = iVar2;
  return;
}


// SpectatorPanel::SpectatorPanel  @ 0009cc70  (line 46)

/* DWARF original prototype: void SpectatorPanel(SpectatorPanel * this, int x, int y, int wide, int
   tall) */

void __thiscall SpectatorPanel::SpectatorPanel(SpectatorPanel *this,int x,int y,int wide,int tall)

{
  vgui::Panel::Panel(&this->super_Panel,x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000ca68c;
  return;
}


// SpectatorPanel::~SpectatorPanel  @ 0009cb90  (line 50)

/* DWARF original prototype: void ~SpectatorPanel(SpectatorPanel * this, int __in_chrg) */

void __thiscall SpectatorPanel::~SpectatorPanel(SpectatorPanel *this,int __in_chrg)

{
  return;
}


// SpectatorPanel::~SpectatorPanel  @ 0009cba0  (line 53)

/* DWARF original prototype: void ~SpectatorPanel(SpectatorPanel * this, int __in_chrg) */

void __thiscall SpectatorPanel::~SpectatorPanel(SpectatorPanel *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// SpectatorPanel::ActionSignal  @ 0009f570  (line 56)

/* DWARF original prototype: void ActionSignal(SpectatorPanel * this, int cmd) */

void __thiscall SpectatorPanel::ActionSignal(SpectatorPanel *this,int cmd)

{
  int iNewInsetMode;
  
  switch(cmd) {
  case 0:
    goto switchD_0009f584_caseD_0;
  case 1:
    TeamFortressViewport::ShowCommandMenu(gViewPort,gViewPort->m_SpectatorOptionsMenu);
    return;
  case 2:
    CHudSpectator::FindNextPlayer(&gHUD.m_Spectator,false);
    return;
  case 3:
    CHudSpectator::FindNextPlayer(&gHUD.m_Spectator,true);
    return;
  case 4:
    ShowMenu(this,false);
    return;
  case 5:
    iNewInsetMode = CHudSpectator::ToggleInset(&gHUD.m_Spectator,false);
    CHudSpectator::SetModes(&gHUD.m_Spectator,-1,iNewInsetMode);
switchD_0009f584_caseD_0:
    return;
  case 6:
    TeamFortressViewport::ShowCommandMenu(gViewPort,gViewPort->m_SpectatorCameraMenu);
    return;
  case 7:
    TeamFortressViewport::ShowCommandMenu(gViewPort,gViewPort->m_PlayerMenu);
    return;
  default:
                    /* WARNING: Could not recover jumptable at 0x0009f688. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEngfuncs.Con_DPrintf)("Unknown SpectatorPanel ActionSingal %i.\n");
    return;
  }
}


// SpectatorPanel::Initialize  @ 0009ccb0  (line 91)

/* DWARF original prototype: void Initialize(SpectatorPanel * this) */

void __thiscall SpectatorPanel::Initialize(SpectatorPanel *this)

{
  CSchemeManager *this_00;
  code *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  SchemeHandle_t schemeHandle;
  CTransparentPanel *pCVar5;
  Label *pLVar6;
  Font *pFVar7;
  CImageLabel *pCVar8;
  Panel *this_01;
  char *pcVar9;
  DropDownButton *pDVar10;
  undefined4 *puVar11;
  Color *pCVar12;
  CImageButton *pCVar13;
  LineBorder *pLVar14;
  ColorButton *pCVar15;
  Label **ppLVar16;
  Label **ppLVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int in_GS_OFFSET;
  int *piVar21;
  undefined1 *puVar22;
  float local_58;
  int local_54;
  int local_50;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  int local_3c;
  undefined1 local_38 [4];
  int local_34;
  undefined1 local_30 [4];
  Color local_2c [12];
  int local_20;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: CSchemeManager * pSchemes@[???]
                       Unresolved local var: SchemeHandle_t hSmallScheme@[???]
                       Unresolved local var: float flLabelSize@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (**(code **)(*(int *)this + 0x14))(this,local_44,local_40,&local_3c,local_38);
  this_00 = &gViewPort->m_SchemeManager;
  schemeHandle = CSchemeManager::getSchemeHandle(this_00,"Team Info Text");
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar19 = 0x40;
  }
  else {
                    /* catch() { ... } // from try @ 0009c69f with catch @ 0009cd2e */
    iVar19 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
  }
  pCVar5 = operator_new(0xc0);
  vgui::Panel::Panel(&pCVar5->super_Panel,0,0,gHUD.m_scrinfo.iWidth,iVar19);
  *(undefined ***)pCVar5 = &PTR_setPos_000c3f80;
  pCVar5->m_iTransparency = 0x40;
  this->m_TopBorder = pCVar5;
  vgui::Panel::setParent(&pCVar5->super_Panel);
  fVar3 = (float)gHUD.m_scrinfo.iHeight;
  fVar2 = fVar3 / 720.0;
  if (fVar2 <= 1.0) {
    iVar19 = (int)(fVar3 - 64.0);
    if (1.0 < fVar2) {
      iVar20 = (int)(fVar2 * 64.0);
    }
    else {
      iVar20 = 0x40;
    }
  }
  else {
    iVar19 = (int)(fVar3 - fVar2 * 64.0);
    iVar20 = (int)(fVar2 * 64.0);
  }
  pCVar5 = operator_new(0xc0);
  vgui::Panel::Panel(&pCVar5->super_Panel,0,iVar19,gHUD.m_scrinfo.iWidth,iVar20);
  *(undefined ***)pCVar5 = &PTR_setPos_000c3f80;
  pCVar5->m_iTransparency = 0x40;
  this->m_BottomBorder = pCVar5;
  vgui::Panel::setParent(&pCVar5->super_Panel);
  (**(code **)(*(int *)this + 0xdc))(this,0);
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar19 = 0x40;
  }
  else {
    iVar19 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
  }
  pLVar6 = operator_new(0xd0);
  vgui::Label::Label(pLVar6,"Extra Info",0,0,local_3c,iVar19);
  this->m_ExtraInfo = pLVar6;
  vgui::Panel::setParent((Panel *)pLVar6);
  pcVar1 = *(code **)(*(int *)this->m_ExtraInfo + 0x20c);
  pFVar7 = CSchemeManager::getFont(this_00,schemeHandle);
  (*pcVar1)(this->m_ExtraInfo,pFVar7);
  (**(code **)(*(int *)this->m_ExtraInfo + 0xdc))(this->m_ExtraInfo,0);
  (**(code **)(*(int *)this->m_ExtraInfo + 0x124))(this->m_ExtraInfo,0x8f,0x8f,0x36,0);
  (**(code **)(*(int *)this->m_ExtraInfo + 0x21c))(this->m_ExtraInfo,3);
  pCVar8 = operator_new(0xd4);
  CImageLabel::CImageLabel(pCVar8,"timer",0,0,0xe,0xe);
  this->m_TimerImage = pCVar8;
  vgui::Panel::setParent((Panel *)pCVar8);
  if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
    iVar19 = 0x100;
  }
  else {
    iVar19 = (int)(((float)gHUD.m_scrinfo.iWidth / 1280.0) * 256.0);
  }
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar20 = 0x40;
  }
  else {
    iVar20 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
  }
  pCVar8 = operator_new(0xd4);
  CImageLabel::CImageLabel(pCVar8,"banner",0,0,iVar19,iVar20);
  this->m_TopBanner = pCVar8;
  vgui::Panel::setParent((Panel *)pCVar8);
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar19 = 0x40;
  }
  else {
    iVar19 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
  }
  pLVar6 = operator_new(0xd0);
  vgui::Label::Label(pLVar6,"00:00",0,0,local_3c,iVar19);
  this->m_CurrentTime = pLVar6;
  vgui::Panel::setParent((Panel *)pLVar6);
  pcVar1 = *(code **)(*(int *)this->m_CurrentTime + 0x20c);
  pFVar7 = CSchemeManager::getFont(this_00,schemeHandle);
  (*pcVar1)(this->m_CurrentTime,pFVar7);
  (**(code **)(*(int *)this->m_CurrentTime + 0xdc))(this->m_CurrentTime,0);
  (**(code **)(*(int *)this->m_CurrentTime + 0x124))(this->m_CurrentTime,0x8f,0x8f,0x36,0);
  (**(code **)(*(int *)this->m_CurrentTime + 0x21c))(this->m_CurrentTime,3);
  if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
    iVar19 = 0x40;
  }
  else {
    iVar19 = (int)(((float)gHUD.m_scrinfo.iWidth / 1280.0) * 64.0);
  }
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar20 = 0x60;
  }
  else {
    iVar20 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 96.0);
  }
  this_01 = operator_new(0xbc);
  vgui::Panel::Panel(this_01,0,0,iVar19,iVar20);
  this->m_Separator = this_01;
  vgui::Panel::setParent(this_01);
  (**(code **)(*(int *)this->m_Separator + 0x124))(this->m_Separator,0x3b,0x3a,0x22,0x30);
  (**(code **)(*(int *)this->m_Separator + 0x128))(this->m_Separator,0x3b,0x3a,0x22,0x30);
  ppLVar16 = this->m_TeamScores;
  do {
                    /* Unresolved local var: int j@[???] */
    if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
      iVar19 = 0x40;
    }
    else {
      iVar19 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
    }
    pLVar6 = operator_new(0xd0);
    vgui::Label::Label(pLVar6,"   ",0,0,local_3c,iVar19);
    *ppLVar16 = pLVar6;
    ppLVar17 = ppLVar16 + 1;
    vgui::Panel::setParent((Panel *)pLVar6);
    pcVar1 = *(code **)(*(int *)*ppLVar16 + 0x20c);
    pFVar7 = CSchemeManager::getFont(this_00,schemeHandle);
    (*pcVar1)(*ppLVar16,pFVar7);
    (**(code **)(*(int *)*ppLVar16 + 0xdc))(*ppLVar16,0);
    (**(code **)(*(int *)*ppLVar16 + 0x124))(*ppLVar16,0x8f,0x8f,0x36,0);
    (**(code **)(*(int *)*ppLVar16 + 0x21c))(*ppLVar16,3);
    (**(code **)(*(int *)*ppLVar16 + 0x24))(*ppLVar16,0);
    ppLVar16 = ppLVar17;
  } while (&this->m_TopBanner != (CImageLabel **)ppLVar17);
  pcVar9 = CHudTextMessage::BufferedLocaliseTextString("#SPECT_OPTIONS");
  fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
  if (fVar2 <= 1.0) {
    fVar3 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    if (fVar3 <= 1.0) {
      iVar19 = 0xf;
      goto LAB_0009ebcf;
    }
    iVar20 = (int)(fVar3 * 6.0);
    if (1.0 < fVar2) {
      iVar19 = 0xf;
      goto LAB_0009d3cd;
    }
    iVar19 = 0xf;
    local_50 = 0x60;
LAB_0009d3e1:
    local_54 = (int)(fVar3 * 20.0);
  }
  else {
    fVar3 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    iVar19 = (int)(fVar2 * 15.0);
    if (1.0 < fVar3) {
      iVar20 = (int)(fVar3 * 6.0);
LAB_0009d3cd:
      local_50 = (int)(fVar2 * 96.0);
      goto LAB_0009d3e1;
    }
LAB_0009ebcf:
    if (fVar2 <= 1.0) {
      local_50 = 0x60;
    }
    else {
      local_50 = (int)(fVar2 * 96.0);
    }
    if (1.0 < fVar3) {
      iVar20 = 6;
      goto LAB_0009d3e1;
    }
    iVar20 = 6;
    local_54 = 0x14;
  }
  pDVar10 = operator_new(0x144);
  CommandButton::CommandButton
            ((CommandButton *)pDVar10,pcVar9,iVar19,iVar20,local_50,local_54,false,false);
  (pDVar10->super_ColorButton).ArmedColor = (Color *)0x0;
  (pDVar10->super_ColorButton).UnArmedColor = (Color *)0x0;
  (pDVar10->super_ColorButton).ArmedBorderColor = (Color *)0x0;
  (pDVar10->super_ColorButton).UnArmedBorderColor = (Color *)0x0;
  *(undefined ***)&(pDVar10->super_ColorButton).super_CommandButton = &PTR_setPos_000ca1a0;
                    /* Unresolved local var: int textwide@[???]
                       Unresolved local var: int texttall@[???] */
  pCVar8 = operator_new(0xd4);
  CImageLabel::CImageLabel
            (pCVar8,"arrowup",
             (int)((((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0 - 2.0) *
                  ((float)gHUD.m_scrinfo.iWidth / 640.0)),
             (int)((((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 - 2.0) *
                  ((float)gHUD.m_scrinfo.iHeight / 480.0)));
  pDVar10->m_pOpenButton = pCVar8;
  vgui::Panel::setParent((Panel *)pCVar8);
  puVar22 = local_30;
  piVar21 = &local_34;
  vgui::Panel::getSize((int *)pDVar10,piVar21);
  iVar19 = local_34;
  puVar11 = *(undefined4 **)pDVar10->m_pOpenButton;
  pcVar1 = (code *)*puVar11;
  iVar20 = (*(code *)puVar11[0x8c])(pDVar10->m_pOpenButton,piVar21,puVar22);
  (*pcVar1)(pDVar10->m_pOpenButton,iVar19 - (iVar20 + 6),0xfffffffe);
  (**(code **)(*(int *)pDVar10->m_pOpenButton + 0x24))(pDVar10->m_pOpenButton,1);
  this->m_OptionButton = pDVar10;
  vgui::Panel::setParent((Panel *)pDVar10);
  (**(code **)(*(int *)&(this->m_OptionButton->super_ColorButton).super_CommandButton + 0x21c))
            (this->m_OptionButton,4);
  CommandButton::setBoundKey((CommandButton *)this->m_OptionButton,-1);
  pcVar1 = *(code **)(*(int *)&(this->m_OptionButton->super_ColorButton).super_CommandButton + 0x240
                     );
  puVar11 = operator_new(0xc);
  pDVar10 = this->m_OptionButton;
  *puVar11 = &PTR_actionPerformed_000ca680;
  puVar11[1] = this;
  puVar11[2] = 1;
  (*pcVar1)(pDVar10,puVar11);
  pDVar10 = this->m_OptionButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x3b,0x3a,0x22,0x30);
  (pDVar10->super_ColorButton).UnArmedBorderColor = pCVar12;
  pDVar10 = this->m_OptionButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pDVar10->super_ColorButton).ArmedBorderColor = pCVar12;
  pDVar10 = this->m_OptionButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x8f,0x8f,0x36,0);
  (pDVar10->super_ColorButton).UnArmedColor = pCVar12;
  pDVar10 = this->m_OptionButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pDVar10->super_ColorButton).ArmedColor = pCVar12;
  pcVar9 = CHudTextMessage::BufferedLocaliseTextString("#CAM_OPTIONS");
  fVar3 = (float)gHUD.m_scrinfo.iWidth;
  fVar2 = fVar3 / 1280.0;
  if (fVar2 <= 1.0) {
    fVar4 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    iVar19 = (int)(fVar3 - 215.0);
    if (fVar4 <= 1.0) goto LAB_0009eb68;
    iVar20 = (int)(fVar4 * 6.0);
    if (1.0 < fVar2) goto LAB_0009d744;
    local_50 = 200;
LAB_0009d758:
    local_54 = (int)(fVar4 * 20.0);
  }
  else {
    fVar4 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    iVar19 = (int)(fVar3 - fVar2 * 215.0);
    if (1.0 < fVar4) {
      iVar20 = (int)(fVar4 * 6.0);
LAB_0009d744:
      local_50 = (int)(fVar2 * 200.0);
      goto LAB_0009d758;
    }
LAB_0009eb68:
    if (fVar2 <= 1.0) {
      local_50 = 200;
    }
    else {
      local_50 = (int)(fVar2 * 200.0);
    }
    if (1.0 < fVar4) {
      iVar20 = 6;
      goto LAB_0009d758;
    }
    iVar20 = 6;
    local_54 = 0x14;
  }
  pDVar10 = operator_new(0x144);
  CommandButton::CommandButton
            ((CommandButton *)pDVar10,pcVar9,iVar19,iVar20,local_50,local_54,false,false);
  (pDVar10->super_ColorButton).ArmedColor = (Color *)0x0;
  (pDVar10->super_ColorButton).UnArmedColor = (Color *)0x0;
  (pDVar10->super_ColorButton).ArmedBorderColor = (Color *)0x0;
  (pDVar10->super_ColorButton).UnArmedBorderColor = (Color *)0x0;
  *(undefined ***)&(pDVar10->super_ColorButton).super_CommandButton = &PTR_setPos_000ca1a0;
                    /* Unresolved local var: int textwide@[???]
                       Unresolved local var: int texttall@[???] */
  pCVar8 = operator_new(0xd4);
  CImageLabel::CImageLabel
            (pCVar8,"arrowup",
             (int)((((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0 - 2.0) *
                  ((float)gHUD.m_scrinfo.iWidth / 640.0)),
             (int)((((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 - 2.0) *
                  ((float)gHUD.m_scrinfo.iHeight / 480.0)));
  pDVar10->m_pOpenButton = pCVar8;
  vgui::Panel::setParent((Panel *)pCVar8);
  puVar22 = local_30;
  piVar21 = &local_34;
  vgui::Panel::getSize((int *)pDVar10,piVar21);
  iVar19 = local_34;
  puVar11 = *(undefined4 **)pDVar10->m_pOpenButton;
  pcVar1 = (code *)*puVar11;
  iVar20 = (*(code *)puVar11[0x8c])(pDVar10->m_pOpenButton,piVar21,puVar22);
  (*pcVar1)(pDVar10->m_pOpenButton,iVar19 - (iVar20 + 6),0xfffffffe);
  (**(code **)(*(int *)pDVar10->m_pOpenButton + 0x24))(pDVar10->m_pOpenButton,1);
  this->m_CamButton = pDVar10;
  vgui::Panel::setParent((Panel *)pDVar10);
  (**(code **)(*(int *)&(this->m_CamButton->super_ColorButton).super_CommandButton + 0x21c))
            (this->m_CamButton,4);
  CommandButton::setBoundKey((CommandButton *)this->m_CamButton,-1);
  pcVar1 = *(code **)(*(int *)&(this->m_CamButton->super_ColorButton).super_CommandButton + 0x240);
  puVar11 = operator_new(0xc);
  pDVar10 = this->m_CamButton;
  *puVar11 = &PTR_actionPerformed_000ca680;
  puVar11[1] = this;
  puVar11[2] = 6;
  (*pcVar1)(pDVar10,puVar11);
  pDVar10 = this->m_CamButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x3b,0x3a,0x22,0x30);
  (pDVar10->super_ColorButton).UnArmedBorderColor = pCVar12;
  pDVar10 = this->m_CamButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pDVar10->super_ColorButton).ArmedBorderColor = pCVar12;
  pDVar10 = this->m_CamButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x8f,0x8f,0x36,0);
  (pDVar10->super_ColorButton).UnArmedColor = pCVar12;
  pDVar10 = this->m_CamButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pDVar10->super_ColorButton).ArmedColor = pCVar12;
  fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
  if (fVar2 <= 1.0) {
    fVar3 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    if (fVar3 <= 1.0) {
      iVar19 = 0x7e;
      goto LAB_0009eaff;
    }
    iVar19 = 0x7e;
    iVar20 = (int)(fVar3 * 6.0);
    if (1.0 < fVar2) goto LAB_0009dab0;
    local_58 = 3.36312e-44;
LAB_0009dac4:
    iVar18 = (int)(fVar3 * 20.0);
  }
  else {
    fVar3 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    iVar19 = (int)(fVar2 * 126.0);
    if (1.0 < fVar3) {
      iVar20 = (int)(fVar3 * 6.0);
LAB_0009dab0:
      local_58 = (float)(int)(fVar2 * 24.0);
      goto LAB_0009dac4;
    }
LAB_0009eaff:
    if (fVar2 <= 1.0) {
      local_58 = 3.36312e-44;
    }
    else {
      local_58 = (float)(int)(fVar2 * 24.0);
    }
    if (1.0 < fVar3) {
      iVar20 = 6;
      goto LAB_0009dac4;
    }
    iVar18 = 0x14;
    iVar20 = 6;
  }
  pCVar13 = operator_new(0x144);
  CommandButton::CommandButton
            ((CommandButton *)pCVar13," ",iVar19,iVar20,(int)local_58,iVar18,false,false);
  (pCVar13->super_ColorButton).ArmedColor = (Color *)0x0;
  (pCVar13->super_ColorButton).UnArmedColor = (Color *)0x0;
  (pCVar13->super_ColorButton).ArmedBorderColor = (Color *)0x0;
  (pCVar13->super_ColorButton).UnArmedBorderColor = (Color *)0x0;
  *(undefined ***)&(pCVar13->super_ColorButton).super_CommandButton = &PTR_setPos_000ca410;
  pCVar8 = operator_new(0xd4);
  CImageLabel::CImageLabel(pCVar8,"arrowleft",1,1,(int)local_58 + -2,iVar18 + -2);
  pCVar13->m_pOpenButton = pCVar8;
  vgui::Panel::setParent((Panel *)pCVar8);
  (**(code **)(*(int *)pCVar13->m_pOpenButton + 0x24))(pCVar13->m_pOpenButton,1);
  this->m_PrevPlayerButton = pCVar13;
  vgui::Panel::setParent((Panel *)pCVar13);
  (**(code **)(*(int *)&(this->m_PrevPlayerButton->super_ColorButton).super_CommandButton + 0x21c))
            (this->m_PrevPlayerButton,4);
  CommandButton::setBoundKey((CommandButton *)this->m_PrevPlayerButton,-1);
  pcVar1 = *(code **)(*(int *)&(this->m_PrevPlayerButton->super_ColorButton).super_CommandButton +
                     0x240);
  puVar11 = operator_new(0xc);
  pCVar13 = this->m_PrevPlayerButton;
  *puVar11 = &PTR_actionPerformed_000ca680;
  puVar11[1] = this;
  puVar11[2] = 2;
  (*pcVar1)(pCVar13,puVar11);
  pCVar13 = this->m_PrevPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x3b,0x3a,0x22,0x30);
  (pCVar13->super_ColorButton).UnArmedBorderColor = pCVar12;
  pCVar13 = this->m_PrevPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pCVar13->super_ColorButton).ArmedBorderColor = pCVar12;
  pCVar13 = this->m_PrevPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x8f,0x8f,0x36,0);
  (pCVar13->super_ColorButton).UnArmedColor = pCVar12;
  pCVar13 = this->m_PrevPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pCVar13->super_ColorButton).ArmedColor = pCVar12;
  fVar3 = (float)gHUD.m_scrinfo.iWidth;
  fVar2 = fVar3 / 1280.0;
  if (fVar2 <= 1.0) {
    fVar3 = fVar3 - 215.0;
    if (1.0 < fVar2) goto LAB_0009dd70;
    fVar4 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    iVar19 = (int)(fVar3 - 39.0);
    if (fVar4 <= 1.0) goto LAB_0009ea98;
    iVar20 = (int)(fVar4 * 6.0);
    if (1.0 < fVar2) goto LAB_0009ddc0;
    local_58 = 3.36312e-44;
LAB_0009ddd4:
    iVar18 = (int)(fVar4 * 20.0);
  }
  else {
    fVar3 = fVar3 - fVar2 * 215.0;
LAB_0009dd70:
    fVar4 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    iVar19 = (int)(fVar3 - fVar2 * 39.0);
    if (1.0 < fVar4) {
      iVar20 = (int)(fVar4 * 6.0);
LAB_0009ddc0:
      local_58 = (float)(int)(fVar2 * 24.0);
      goto LAB_0009ddd4;
    }
LAB_0009ea98:
    if (fVar2 <= 1.0) {
      local_58 = 3.36312e-44;
    }
    else {
      local_58 = (float)(int)(fVar2 * 24.0);
    }
    if (1.0 < fVar4) {
      iVar20 = 6;
      goto LAB_0009ddd4;
    }
    iVar18 = 0x14;
    iVar20 = 6;
  }
  pCVar13 = operator_new(0x144);
  CommandButton::CommandButton
            ((CommandButton *)pCVar13," ",iVar19,iVar20,(int)local_58,iVar18,false,false);
  (pCVar13->super_ColorButton).ArmedColor = (Color *)0x0;
  (pCVar13->super_ColorButton).UnArmedColor = (Color *)0x0;
  (pCVar13->super_ColorButton).ArmedBorderColor = (Color *)0x0;
  (pCVar13->super_ColorButton).UnArmedBorderColor = (Color *)0x0;
  *(undefined ***)&(pCVar13->super_ColorButton).super_CommandButton = &PTR_setPos_000ca410;
  pCVar8 = operator_new(0xd4);
  CImageLabel::CImageLabel(pCVar8,"arrowright",1,1,(int)local_58 + -2,iVar18 + -2);
  pCVar13->m_pOpenButton = pCVar8;
  vgui::Panel::setParent((Panel *)pCVar8);
  (**(code **)(*(int *)pCVar13->m_pOpenButton + 0x24))(pCVar13->m_pOpenButton,1);
  this->m_NextPlayerButton = pCVar13;
  vgui::Panel::setParent((Panel *)pCVar13);
  (**(code **)(*(int *)&(this->m_NextPlayerButton->super_ColorButton).super_CommandButton + 0x21c))
            (this->m_NextPlayerButton,4);
  CommandButton::setBoundKey((CommandButton *)this->m_NextPlayerButton,-1);
  pcVar1 = *(code **)(*(int *)&(this->m_NextPlayerButton->super_ColorButton).super_CommandButton +
                     0x240);
  puVar11 = operator_new(0xc);
  pCVar13 = this->m_NextPlayerButton;
  *puVar11 = &PTR_actionPerformed_000ca680;
  puVar11[1] = this;
  puVar11[2] = 3;
  (*pcVar1)(pCVar13,puVar11);
  pCVar13 = this->m_NextPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x3b,0x3a,0x22,0x30);
  (pCVar13->super_ColorButton).UnArmedBorderColor = pCVar12;
  pCVar13 = this->m_NextPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pCVar13->super_ColorButton).ArmedBorderColor = pCVar12;
  pCVar13 = this->m_NextPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x8f,0x8f,0x36,0);
  (pCVar13->super_ColorButton).UnArmedColor = pCVar12;
  pCVar13 = this->m_NextPlayerButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pCVar13->super_ColorButton).ArmedColor = pCVar12;
  fVar3 = (float)gHUD.m_scrinfo.iWidth;
  fVar2 = fVar3 / 1280.0;
  if (fVar2 <= 1.0) {
    if (1.0 < fVar2) {
      local_58 = ((fVar3 - 215.0) - fVar2 * 39.0) - fVar2 * 164.0;
      goto LAB_0009e0a0;
    }
    local_58 = (fVar3 - 215.0) - 39.0;
    if (1.0 < fVar2) goto LAB_0009e090;
    local_58 = local_58 - 164.0;
                    /* try { // try from 0009ea44 to 000aea48 has its CatchHandler @ 0009f82a */
    if (1.0 < fVar2) goto LAB_0009e0a0;
                    /* try { // try from 0009ea50 to 000af32f has its CatchHandler @ 0009f789 */
    iVar19 = 0x9d;
  }
  else {
    local_58 = (fVar3 - fVar2 * 215.0) - fVar2 * 39.0;
LAB_0009e090:
    local_58 = local_58 - fVar2 * 164.0;
LAB_0009e0a0:
    iVar19 = (int)(fVar2 * 157.0);
  }
  fVar2 = (float)gHUD.m_scrinfo.iHeight / 720.0;
  if (fVar2 <= 1.0) {
    if (1.0 < fVar2) {
      iVar20 = 6;
      iVar18 = (int)(fVar2 * 20.0);
    }
    else {
      iVar18 = 0x14;
      iVar20 = 6;
    }
  }
  else {
    iVar20 = (int)(fVar2 * 6.0);
    iVar18 = (int)(fVar2 * 20.0);
  }
  pDVar10 = operator_new(0x144);
  CommandButton::CommandButton
            ((CommandButton *)pDVar10,"Spectator Bottom",iVar19,iVar20,(int)local_58,iVar18,false,
             false);
  (pDVar10->super_ColorButton).ArmedColor = (Color *)0x0;
  (pDVar10->super_ColorButton).UnArmedColor = (Color *)0x0;
  (pDVar10->super_ColorButton).ArmedBorderColor = (Color *)0x0;
  (pDVar10->super_ColorButton).UnArmedBorderColor = (Color *)0x0;
  *(undefined ***)&(pDVar10->super_ColorButton).super_CommandButton = &PTR_setPos_000ca1a0;
                    /* Unresolved local var: int textwide@[???]
                       Unresolved local var: int texttall@[???] */
  pCVar8 = operator_new(0xd4);
  CImageLabel::CImageLabel
            (pCVar8,"arrowup",
             (int)((((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0 - 2.0) *
                  ((float)gHUD.m_scrinfo.iWidth / 640.0)),
             (int)((((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 - 2.0) *
                  ((float)gHUD.m_scrinfo.iHeight / 480.0)));
  pDVar10->m_pOpenButton = pCVar8;
  vgui::Panel::setParent((Panel *)pCVar8);
  puVar22 = local_30;
  piVar21 = &local_34;
  vgui::Panel::getSize((int *)pDVar10,piVar21);
  puVar11 = *(undefined4 **)pDVar10->m_pOpenButton;
  pcVar1 = (code *)*puVar11;
  iVar19 = (*(code *)puVar11[0x8c])(pDVar10->m_pOpenButton,piVar21,puVar22);
  (*pcVar1)(pDVar10->m_pOpenButton,local_34 - (iVar19 + 6),0xfffffffe);
  (**(code **)(*(int *)pDVar10->m_pOpenButton + 0x24))(pDVar10->m_pOpenButton,1);
  this->m_BottomMainButton = pDVar10;
  vgui::Panel::setParent((Panel *)pDVar10);
  (**(code **)(*(int *)&(this->m_BottomMainButton->super_ColorButton).super_CommandButton + 0xdc))
            (this->m_BottomMainButton,0);
  (**(code **)(*(int *)&(this->m_BottomMainButton->super_ColorButton).super_CommandButton + 0x11c))
            (this->m_BottomMainButton,3);
  (**(code **)(*(int *)&(this->m_BottomMainButton->super_ColorButton).super_CommandButton + 0x21c))
            (this->m_BottomMainButton,4);
  pcVar1 = *(code **)(*(int *)&(this->m_BottomMainButton->super_ColorButton).super_CommandButton +
                     0xd4);
  vgui::Color::Color(local_2c,0x3b,0x3a,0x22,0x30);
  pLVar14 = operator_new(0x44);
  vgui::LineBorder::LineBorder(pLVar14,local_2c);
  (*pcVar1)(this->m_BottomMainButton,pLVar14);
  CommandButton::setBoundKey((CommandButton *)this->m_BottomMainButton,-1);
  pcVar1 = *(code **)(*(int *)&(this->m_BottomMainButton->super_ColorButton).super_CommandButton +
                     0x240);
  puVar11 = operator_new(0xc);
  pDVar10 = this->m_BottomMainButton;
  *puVar11 = &PTR_actionPerformed_000ca680;
  puVar11[1] = this;
  puVar11[2] = 7;
  (*pcVar1)(pDVar10,puVar11);
  pDVar10 = this->m_BottomMainButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x3b,0x3a,0x22,0x30);
  (pDVar10->super_ColorButton).UnArmedBorderColor = pCVar12;
  pDVar10 = this->m_BottomMainButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pDVar10->super_ColorButton).ArmedBorderColor = pCVar12;
  pDVar10 = this->m_BottomMainButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x8f,0x8f,0x36,0);
  (pDVar10->super_ColorButton).UnArmedColor = pCVar12;
  pDVar10 = this->m_BottomMainButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  (pDVar10->super_ColorButton).ArmedColor = pCVar12;
  if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
    iVar19 = 0x9d;
  }
  else {
    iVar19 = (int)(((float)gHUD.m_scrinfo.iWidth / 1280.0) * 157.0);
  }
  fVar2 = (float)gHUD.m_scrinfo.iHeight / 720.0;
  if (fVar2 <= 1.0) {
    if (1.0 < fVar2) {
      iVar20 = 6;
      iVar18 = (int)(fVar2 * 20.0);
    }
    else {
      iVar18 = 0x14;
      iVar20 = 6;
    }
  }
  else {
    iVar20 = (int)(fVar2 * 6.0);
    iVar18 = (int)(fVar2 * 20.0);
  }
  pLVar6 = operator_new(0xd0);
                    /* catch() { ... } // from try @ 0009f77f with catch @ 0009e510 */
  vgui::Label::Label(pLVar6,"Spectator Bottom",iVar19,iVar20,(int)local_58,iVar18);
  this->m_BottomMainLabel = pLVar6;
  vgui::Panel::setParent((Panel *)pLVar6);
  (**(code **)(*(int *)this->m_BottomMainLabel + 0xdc))(this->m_BottomMainLabel,0);
  (**(code **)(*(int *)this->m_BottomMainLabel + 0x11c))(this->m_BottomMainLabel,3);
                    /* try { // try from 0009e56c to 000ae5f3 has its CatchHandler @ 0009e510 */
  (**(code **)(*(int *)this->m_BottomMainLabel + 0x21c))(this->m_BottomMainLabel,4);
  (**(code **)(*(int *)this->m_BottomMainLabel + 0xd4))(this->m_BottomMainLabel,0);
  (**(code **)(*(int *)this->m_BottomMainLabel + 0x24))(this->m_BottomMainLabel,0);
  fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
  if (fVar2 <= 1.0) {
    fVar3 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    if (fVar3 <= 1.0) {
      iVar19 = 2;
      goto LAB_0009e98f;
    }
    iVar19 = 2;
    iVar20 = (int)(fVar3 + fVar3);
    if (1.0 < fVar2) goto LAB_0009e5f0;
    local_54 = 0xf0;
  }
  else {
    fVar3 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    iVar19 = (int)(fVar2 + fVar2);
    if (fVar3 <= 1.0) {
LAB_0009e98f:
      if (fVar2 <= 1.0) {
        local_54 = 0xf0;
      }
      else {
        local_54 = (int)(fVar2 * 240.0);
      }
      if (fVar3 <= 1.0) {
        iVar20 = 2;
        local_58 = 2.52234e-43;
        goto LAB_0009e618;
      }
      iVar20 = 2;
    }
    else {
      iVar20 = (int)(fVar3 + fVar3);
LAB_0009e5f0:
      local_54 = (int)(fVar2 * 240.0);
    }
  }
  local_58 = (float)(int)(fVar3 * 180.0);
LAB_0009e618:
                    /* try { // try from 0009e61c to 000ae632 has its CatchHandler @ 0009f8b5 */
  pCVar15 = operator_new(0x140);
                    /* try { // try from 0009e638 to 000ae64e has its CatchHandler @ 0009f733 */
  CommandButton::CommandButton
            (&pCVar15->super_CommandButton,"",iVar19,iVar20,local_54,(int)local_58,false,false);
                    /* try { // try from 0009e65d to 000ae661 has its CatchHandler @ 0009f8bc */
  pCVar15->ArmedColor = (Color *)0x0;
                    /* try { // try from 0009e66c to 000ae670 has its CatchHandler @ 0009f733 */
  pCVar15->UnArmedColor = (Color *)0x0;
  pCVar15->ArmedBorderColor = (Color *)0x0;
                    /* try { // try from 0009e67f to 000ae683 has its CatchHandler @ 0009f8cb */
  pCVar15->UnArmedBorderColor = (Color *)0x0;
  *(undefined ***)&pCVar15->super_CommandButton = &PTR_setPos_000c9f30;
  this->m_InsetViewButton = pCVar15;
  vgui::Panel::setParent((Panel *)pCVar15);
  CommandButton::setBoundKey(&this->m_InsetViewButton->super_CommandButton,-1);
                    /* try { // try from 0009e6b5 to 000ae6ff has its CatchHandler @ 0009f8b5 */
  pcVar1 = *(code **)(*(int *)&this->m_InsetViewButton->super_CommandButton + 0x240);
  puVar11 = operator_new(0xc);
  pCVar15 = this->m_InsetViewButton;
  *puVar11 = &PTR_actionPerformed_000ca680;
  puVar11[1] = this;
  puVar11[2] = 5;
  (*pcVar1)(pCVar15,puVar11);
  pCVar15 = this->m_InsetViewButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x3b,0x3a,0x22,0x30);
  pCVar15->UnArmedBorderColor = pCVar12;
  pCVar15 = this->m_InsetViewButton;
                    /* try { // try from 0009e73b to 000ae73f has its CatchHandler @ 0009f8cd */
  pCVar12 = operator_new(0xc);
                    /* try { // try from 0009e763 to 000ae767 has its CatchHandler @ 0009f8d5 */
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
  pCVar15->ArmedBorderColor = pCVar12;
  pCVar15 = this->m_InsetViewButton;
  pCVar12 = operator_new(0xc);
  vgui::Color::Color(pCVar12,0x8f,0x8f,0x36,0);
                    /* try { // try from 0009e7ae to 000ae7c4 has its CatchHandler @ 0009f91a */
  pCVar15->UnArmedColor = pCVar12;
  pCVar15 = this->m_InsetViewButton;
  pCVar12 = operator_new(0xc);
                    /* try { // try from 0009e7ca to 000ae7e0 has its CatchHandler @ 0009f92e */
  vgui::Color::Color(pCVar12,0xc2,0xca,0x36,0);
                    /* try { // try from 0009e7ef to 000ae7f3 has its CatchHandler @ 0009f921 */
  pCVar15->ArmedColor = pCVar12;
  pDVar10 = this->m_CamButton;
                    /* try { // try from 0009e7fe to 000ae802 has its CatchHandler @ 0009f92e */
  this->m_menuVisible = false;
  this->m_insetVisible = false;
  pcVar1 = *(code **)(*(int *)&(pDVar10->super_ColorButton).super_CommandButton + 0x24);
                    /* try { // try from 0009e811 to 000ae815 has its CatchHandler @ 0009f82c */
  if (pcVar1 == DropDownButton::setVisible) {
    (**(code **)(*(int *)pDVar10->m_pOpenButton + 0x24))(pDVar10->m_pOpenButton,0);
    vgui::Panel::setVisible(SUB41(pDVar10,0));
  }
  else {
    (*pcVar1)(pDVar10,0);
  }
  pDVar10 = this->m_OptionButton;
  pcVar1 = *(code **)(*(int *)&(pDVar10->super_ColorButton).super_CommandButton + 0x24);
                    /* try { // try from 0009e847 to 000ae891 has its CatchHandler @ 0009f91a */
  if (pcVar1 == DropDownButton::setVisible) {
    (**(code **)(*(int *)pDVar10->m_pOpenButton + 0x24))(pDVar10->m_pOpenButton,0);
    vgui::Panel::setVisible(SUB41(pDVar10,0));
  }
  else {
    (*pcVar1)(pDVar10,0);
  }
  pCVar13 = this->m_NextPlayerButton;
  pcVar1 = *(code **)(*(int *)&(pCVar13->super_ColorButton).super_CommandButton + 0x24);
  if (pcVar1 == CImageButton::setVisible) {
    (**(code **)(*(int *)pCVar13->m_pOpenButton + 0x24))(pCVar13->m_pOpenButton,0);
    vgui::Panel::setVisible(SUB41(pCVar13,0));
  }
  else {
    (*pcVar1)(pCVar13,0);
  }
  pCVar13 = this->m_PrevPlayerButton;
  pcVar1 = *(code **)(*(int *)&(pCVar13->super_ColorButton).super_CommandButton + 0x24);
  if (pcVar1 == CImageButton::setVisible) {
    (**(code **)(*(int *)pCVar13->m_pOpenButton + 0x24))(pCVar13->m_pOpenButton,0);
    vgui::Panel::setVisible(SUB41(pCVar13,0));
  }
  else {
    (*pcVar1)(pCVar13,0);
  }
                    /* try { // try from 0009e8e9 to 000aea3a has its CatchHandler @ 0009f789 */
  (**(code **)(*(int *)this->m_TopBanner + 0x24))(this->m_TopBanner,0);
  (**(code **)(*(int *)this->m_ExtraInfo + 0x24))(this->m_ExtraInfo,0);
  (**(code **)(*(int *)this->m_Separator + 0x24))(this->m_Separator,0);
  (**(code **)(*(int *)this->m_TimerImage + 0x24))(this->m_TimerImage,0);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SpectatorPanel::ShowMenu  @ 0009f0e0  (line 248)

/* DWARF original prototype: void ShowMenu(SpectatorPanel * this, bool isVisible) */

void __thiscall SpectatorPanel::ShowMenu(SpectatorPanel *this,bool isVisible)

{
  DropDownButton *pDVar1;
  code *pcVar2;
  CImageButton *pCVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  int in_GS_OFFSET;
  TeamFortressViewport *this_00;
  int local_68;
  undefined1 local_64 [4];
  uint local_60 [15];
  undefined1 local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pDVar1 = this->m_OptionButton;
  pcVar2 = *(code **)(*(int *)&(pDVar1->super_ColorButton).super_CommandButton + 0x24);
  if (pcVar2 == DropDownButton::setVisible) {
    (**(code **)(*(int *)pDVar1->m_pOpenButton + 0x24))(pDVar1->m_pOpenButton,isVisible);
    vgui::Panel::setVisible(SUB41(pDVar1,0));
  }
  else {
    (*pcVar2)(pDVar1,isVisible);
  }
  (**(code **)(*(int *)&(this->m_OptionButton->super_ColorButton).super_CommandButton + 0x234))
            (this->m_OptionButton,0);
  pDVar1 = this->m_CamButton;
  pcVar2 = *(code **)(*(int *)&(pDVar1->super_ColorButton).super_CommandButton + 0x24);
  if (pcVar2 == DropDownButton::setVisible) {
    (**(code **)(*(int *)pDVar1->m_pOpenButton + 0x24))(pDVar1->m_pOpenButton,isVisible);
    vgui::Panel::setVisible(SUB41(pDVar1,0));
  }
  else {
    (*pcVar2)(pDVar1,isVisible);
  }
  (**(code **)(*(int *)&(this->m_CamButton->super_ColorButton).super_CommandButton + 0x234))
            (this->m_CamButton,0);
  pCVar3 = this->m_NextPlayerButton;
  pcVar2 = *(code **)(*(int *)&(pCVar3->super_ColorButton).super_CommandButton + 0x24);
  if (pcVar2 == CImageButton::setVisible) {
    (**(code **)(*(int *)pCVar3->m_pOpenButton + 0x24))(pCVar3->m_pOpenButton,isVisible);
    vgui::Panel::setVisible(SUB41(pCVar3,0));
  }
  else {
    (*pcVar2)(pCVar3,isVisible);
  }
  (**(code **)(*(int *)&(this->m_NextPlayerButton->super_ColorButton).super_CommandButton + 0x234))
            (this->m_NextPlayerButton,0);
  pCVar3 = this->m_PrevPlayerButton;
  pcVar2 = *(code **)(*(int *)&(pCVar3->super_ColorButton).super_CommandButton + 0x24);
  if (pcVar2 == CImageButton::setVisible) {
    (**(code **)(*(int *)pCVar3->m_pOpenButton + 0x24))(pCVar3->m_pOpenButton,isVisible);
    vgui::Panel::setVisible(SUB41(pCVar3,0));
  }
  else {
    (*pcVar2)(pCVar3,isVisible);
  }
  (**(code **)(*(int *)&(this->m_PrevPlayerButton->super_ColorButton).super_CommandButton + 0x234))
            (this->m_PrevPlayerButton,0);
  if (isVisible) {
    if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
      iVar9 = 6;
    }
    else {
      iVar9 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 6.0);
    }
    if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
      iVar5 = 0x9d;
    }
    else {
      iVar5 = (int)(((float)gHUD.m_scrinfo.iWidth / 1280.0) * 157.0);
    }
    (*(code *)**(undefined4 **)&(this->m_BottomMainButton->super_ColorButton).super_CommandButton)
              (this->m_BottomMainButton,iVar5,iVar9);
    (**(code **)(*(int *)this->m_BottomMainLabel + 0x24))(this->m_BottomMainLabel,0);
    pDVar1 = this->m_BottomMainButton;
    pcVar2 = *(code **)(*(int *)&(pDVar1->super_ColorButton).super_CommandButton + 0x24);
    if (pcVar2 == DropDownButton::setVisible) {
      (**(code **)(*(int *)pDVar1->m_pOpenButton + 0x24))(pDVar1->m_pOpenButton,1);
      iVar5 = 1;
      vgui::Panel::setVisible(SUB41(pDVar1,0));
    }
    else {
      iVar5 = 1;
      (*pcVar2)(pDVar1,1);
    }
  }
  else {
                    /* Unresolved local var: int iLabelSizeX@[???]
                       Unresolved local var: int iLabelSizeY@[???] */
    (**(code **)(*(int *)this->m_BottomMainLabel + 0x24))(this->m_BottomMainLabel,1);
    pDVar1 = this->m_BottomMainButton;
    pcVar2 = *(code **)(*(int *)&(pDVar1->super_ColorButton).super_CommandButton + 0x24);
    if (pcVar2 == DropDownButton::setVisible) {
      (**(code **)(*(int *)pDVar1->m_pOpenButton + 0x24))(pDVar1->m_pOpenButton,0);
      vgui::Panel::setVisible(SUB41(pDVar1,0));
    }
    else {
      (*pcVar2)(pDVar1,0);
    }
    (**(code **)(*(int *)this->m_BottomMainLabel + 0xc))(this->m_BottomMainLabel,&local_68,local_64)
    ;
                    /* try { // try from 0009f3b2 to 000af3b6 has its CatchHandler @ 0009f819 */
    if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
      iVar9 = 6;
    }
    else {
                    /* try { // try from 0009f3c4 to 000af705 has its CatchHandler @ 0009f789 */
      iVar9 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 6.0);
    }
    iVar5 = gHUD.m_scrinfo.iWidth / 2 - local_68 / 2;
    (*(code *)**(undefined4 **)this->m_BottomMainLabel)(this->m_BottomMainLabel,iVar5,iVar9);
    TeamFortressViewport::HideCommandMenu(gViewPort);
    if ((this->m_menuVisible != false) &&
       (cVar4 = (**(code **)(*(int *)this + 0x28))(this), cVar4 != '\0')) {
                    /* Unresolved local var: char[64] string@[???] */
      pcVar6 = CHudTextMessage::BufferedLocaliseTextString("#Spec_Duck");
      __snprintf_chk(local_60,0x3f,1,0x40,&DAT_000bfb94,4,pcVar6);
      local_21 = 0;
      puVar11 = local_60;
      do {
        puVar10 = puVar11;
        uVar7 = *puVar10 + 0xfefefeff & ~*puVar10;
        uVar8 = uVar7 & 0x80808080;
        puVar11 = puVar10 + 1;
      } while (uVar8 == 0);
      if ((uVar7 & 0x8080) == 0) {
        puVar11 = (uint *)((int)puVar10 + 6);
        uVar8 = uVar8 >> 0x10;
      }
      iVar5 = 0;
      CHudTextMessage::MsgFunc_TextMsg
                (&gHUD.m_TextMessage,(char *)0x0,
                 (int)puVar11 + (-(int)local_60 - (uint)CARRY1((byte)uVar8,(byte)uVar8)) + -2,
                 local_60);
    }
  }
  this_00 = gViewPort;
  this->m_menuVisible = isVisible;
  TeamFortressViewport::UpdateCursorState(this_00);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(this_00,iVar5);
  }
  return;
}


// GetSpectatorLabel  @ 0009f690  (line 294)

char * GetSpectatorLabel(int iMode)

{
  char *pcVar1;
  
  pcVar1 = "#OBS_NONE";
  if (iMode - 1U < 6) {
    pcVar1 = *(char **)(CSWTCH_75 + (iMode - 1U) * 4);
  }
  return pcVar1;
}


// SpectatorPanel::EnableInsetView  @ 0009fb90  (line 324)

/* DWARF original prototype: void EnableInsetView(SpectatorPanel * this, bool isEnabled) */

void __thiscall SpectatorPanel::EnableInsetView(SpectatorPanel *this,bool isEnabled)

{
  float fVar1;
  CImageLabel *pCVar2;
  code *UNRECOVERED_JUMPTABLE;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *msg;
  int iVar11;
  
  iVar10 = gHUD.m_Spectator.m_OverviewData.insetWindowWidth;
  iVar8 = gHUD.m_Spectator.m_OverviewData.insetWindowHeight;
  iVar6 = gHUD.m_Spectator.m_OverviewData.insetWindowY;
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: int offset@[???] */
  iVar9 = gHUD.m_Spectator.m_OverviewData.insetWindowX;
  if (!isEnabled) {
    iVar9 = (*gEngfuncs.IsSpectateOnly)();
    pCVar2 = this->m_TopBanner;
    if (iVar9 == 0) {
      (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,0);
    }
    else {
      (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,1);
      (*(code *)**(undefined4 **)this->m_TopBanner)(this->m_TopBanner,0,0);
    }
    if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
      iVar9 = 0x40;
    }
    else {
      iVar9 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
    }
    (**(code **)(*(int *)this->m_TopBorder + 0x10))
              (this->m_TopBorder,0,0,gHUD.m_scrinfo.iWidth,iVar9);
    (**(code **)(*(int *)&this->m_InsetViewButton->super_CommandButton + 0x24))
              (this->m_InsetViewButton,0);
    goto LAB_0009fd53;
  }
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar11 = 0x40;
  }
  else {
    iVar11 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 64.0);
  }
  iVar7 = gHUD.m_Spectator.m_OverviewData.insetWindowX + 2 +
          gHUD.m_Spectator.m_OverviewData.insetWindowWidth;
  fVar5 = (float)iVar7;
  fVar1 = (float)iVar7;
  fVar4 = (float)gHUD.m_scrinfo.iWidth;
  fVar3 = fVar4 / 1280.0;
  if (fVar3 <= 1.0) {
    iVar7 = (int)(fVar4 - fVar5);
    fVar4 = fVar1;
    if (1.0 < fVar3) {
      fVar4 = fVar3 * fVar5;
    }
  }
  else {
    iVar7 = (int)(fVar4 - fVar3 * fVar1);
    fVar4 = fVar3 * fVar1;
  }
  (**(code **)(*(int *)this->m_TopBorder + 0x10))(this->m_TopBorder,(int)fVar4,0,iVar7,iVar11);
  iVar11 = (*gEngfuncs.IsSpectateOnly)();
  pCVar2 = this->m_TopBanner;
  if (iVar11 == 0) {
    (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,0);
  }
  else {
    (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,1);
    fVar3 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
    if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
      fVar3 = 1.0;
    }
    (*(code *)**(undefined4 **)this->m_TopBanner)(this->m_TopBanner,(int)(fVar3 * fVar1),0);
  }
  fVar1 = (float)gHUD.m_scrinfo.iHeight / 720.0;
  if (fVar1 <= 1.0) {
    iVar8 = (int)(float)iVar8;
    fVar5 = (float)(iVar10 + 2);
    fVar3 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
    if (fVar3 <= 1.0) goto LAB_0009feca;
    iVar10 = (int)(fVar5 * fVar3);
    if (1.0 < fVar1) goto LAB_0009fd00;
    fVar1 = (float)iVar6;
  }
  else {
    iVar8 = (int)((float)iVar8 * fVar1);
    fVar5 = (float)(iVar10 + 2);
    fVar3 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
    if (1.0 < fVar3) {
      iVar10 = (int)(fVar5 * fVar3);
LAB_0009fd00:
      fVar1 = (float)iVar6 * fVar1;
    }
    else {
LAB_0009feca:
      iVar10 = (int)fVar5;
      if (fVar1 <= 1.0) {
        fVar1 = 1.0;
      }
      fVar1 = fVar1 * (float)iVar6;
      if (fVar3 <= 1.0) {
        fVar3 = 1.0;
      }
    }
  }
  (**(code **)(*(int *)&this->m_InsetViewButton->super_CommandButton + 0x10))
            (this->m_InsetViewButton,(int)((float)(iVar9 + -1) * fVar3),(int)fVar1,iVar10,iVar8);
  (**(code **)(*(int *)&this->m_InsetViewButton->super_CommandButton + 0x24))
            (this->m_InsetViewButton,1);
LAB_0009fd53:
  this->m_insetVisible = isEnabled;
  Update(this);
  msg = "#OBS_NONE";
  UNRECOVERED_JUMPTABLE =
       *(code **)(*(int *)&(this->m_CamButton->super_ColorButton).super_CommandButton + 0x264);
  if (g_iUser1 - 1U < 6) {
    msg = *(char **)(CSWTCH_75 + (g_iUser1 - 1U) * 4);
  }
  CHudTextMessage::BufferedLocaliseTextString(msg);
                    /* WARNING: Could not recover jumptable at 0x0009fdaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// SpectatorPanel::Update  @ 0009f6b0  (line 376)

/* DWARF original prototype: void Update(SpectatorPanel * this) */

void __thiscall SpectatorPanel::Update(SpectatorPanel *this)

{
  Label **ppLVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int iTextWidth@[???]
                       Unresolved local var: int iTextHeight@[???]
                       Unresolved local var: int iTimeHeight@[???]
                       Unresolved local var: int iTimeWidth@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: bool visible@[???]
                       Unresolved local var: int xPos@[???] */
  iVar6 = 0;
  if (this->m_insetVisible != false) {
    iVar6 = gHUD.m_Spectator.m_OverviewData.insetWindowWidth +
            gHUD.m_Spectator.m_OverviewData.insetWindowX + 2;
  }
  fVar2 = (gHUD.m_Spectator.m_drawstatus)->value;
  bVar3 = fVar2 != 0.0;
  (**(code **)(*(int *)this->m_ExtraInfo + 0x24))(this->m_ExtraInfo,bVar3);
  (**(code **)(*(int *)this->m_TimerImage + 0x24))(this->m_TimerImage,bVar3);
  (**(code **)(*(int *)this->m_CurrentTime + 0x24))(this->m_CurrentTime,bVar3);
                    /* catch() { ... } // from try @ 0009e66c with catch @ 0009f733 */
  (**(code **)(*(int *)this->m_Separator + 0x24))(this->m_Separator,bVar3);
  (**(code **)(*(int *)this->m_TeamScores[0] + 0x24))(this->m_TeamScores[0],bVar3);
  (**(code **)(*(int *)this->m_TeamScores[1] + 0x24))(this->m_TeamScores[1],bVar3);
  if (fVar2 == 0.0) {
    return;
  }
                    /* catch() { ... } // from try @ 0009f3c4 with catch @ 0009f789 */
  (**(code **)(*(int *)this->m_ExtraInfo + 0x210))(this->m_ExtraInfo,&local_34,&local_30);
  (**(code **)(*(int *)this->m_CurrentTime + 0x210))(this->m_CurrentTime,&local_28,&local_2c);
  fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
  if (fVar2 <= 1.0) {
    iVar5 = (int)((float)local_28 + 31.0);
    if (1.0 < fVar2) {
      fVar4 = fVar2 * 15.0;
      iVar7 = (int)fVar4;
      goto LAB_0009f810;
    }
    if (fVar2 <= 1.0) {
      iVar7 = 0xf;
      fVar4 = 15.0;
      goto LAB_0009f810;
    }
    fVar4 = 15.0;
  }
  else {
    fVar4 = fVar2 * 15.0;
    iVar5 = (int)(fVar2 * 31.0 + (float)local_28);
  }
  iVar7 = (int)(fVar2 * 15.0);
LAB_0009f810:
                    /* catch() { ... } // from try @ 0009f3b2 with catch @ 0009f819 */
                    /* catch() { ... } // from try @ 0009ea44 with catch @ 0009f82a */
                    /* catch() { ... } // from try @ 0009e811 with catch @ 0009f82c */
  local_28 = (int)((float)iVar5 + (fVar4 - (float)(iVar5 % iVar7)));
  if (local_34 < local_28) {
    local_34 = local_28;
  }
  if (fVar2 <= 1.0) {
    fVar2 = 1.0;
  }
  iVar5 = (int)((float)gHUD.m_scrinfo.iWidth - ((float)local_34 + (float)(iVar6 + 0xf) * fVar2));
  (**(code **)(*(int *)this->m_ExtraInfo + 0x10))(this->m_ExtraInfo,iVar5,0xf,local_34,local_30);
                    /* catch() { ... } // from try @ 0009e6b5 with catch @ 0009f8b5 */
  if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
    iVar7 = 0x1f;
  }
  else {
                    /* catch() { ... } // from try @ 0009e65d with catch @ 0009f8bc */
                    /* catch() { ... } // from try @ 0009e67f with catch @ 0009f8cb */
    iVar7 = (int)(((float)gHUD.m_scrinfo.iWidth / 1280.0) * 31.0);
  }
                    /* catch() { ... } // from try @ 0009e73b with catch @ 0009f8cd */
                    /* catch() { ... } // from try @ 0009e763 with catch @ 0009f8d5 */
  (**(code **)(*(int *)this->m_TimerImage + 0x10))
            (this->m_TimerImage,iVar5,local_30 + 0xf,iVar7,0x10);
                    /* catch() { ... } // from try @ 0009e847 with catch @ 0009f91a */
                    /* catch() { ... } // from try @ 0009e7ef with catch @ 0009f921 */
                    /* catch() { ... } // from try @ 0009e7fe with catch @ 0009f92e */
  if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
    fVar2 = 31.0;
  }
  else {
    fVar2 = ((float)gHUD.m_scrinfo.iWidth / 1280.0) * 31.0;
  }
  (**(code **)(*(int *)this->m_CurrentTime + 0x10))
            (this->m_CurrentTime,(int)(fVar2 + (float)iVar5),local_30 + 0xf,local_28,local_2c);
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar5 = 5;
  }
  else {
    iVar5 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 5.0);
  }
  fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
  if (fVar2 <= 1.0) {
    fVar2 = 1.0;
  }
  (*(code *)**(undefined4 **)this->m_Separator)
            (this->m_Separator,
             (int)((float)gHUD.m_scrinfo.iWidth - (fVar2 * (float)(iVar6 + 0x25) + (float)local_34))
             ,iVar5);
  if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
    iVar5 = 0x36;
  }
  else {
    iVar5 = (int)(((float)gHUD.m_scrinfo.iHeight / 720.0) * 54.0);
  }
  if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
    iVar7 = 1;
  }
  else {
    iVar7 = (int)((float)gHUD.m_scrinfo.iWidth / 1280.0);
  }
  (**(code **)(*(int *)this->m_Separator + 8))(this->m_Separator,iVar7,iVar5);
  iVar5 = 0;
  do {
                    /* Unresolved local var: int iwidth@[???]
                       Unresolved local var: int iheight@[???] */
    (**(code **)(*(int *)this->m_TeamScores[iVar5] + 0x210))
              (this->m_TeamScores[iVar5],&local_24,local_20);
    ppLVar1 = this->m_TeamScores + iVar5;
    fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
    iVar7 = local_20[0] * iVar5;
    if (fVar2 <= 1.0) {
      fVar2 = 1.0;
    }
    iVar5 = iVar5 + 1;
    (**(code **)(*(int *)*ppLVar1 + 0x10))
              (*ppLVar1,(int)((float)gHUD.m_scrinfo.iWidth -
                             ((float)local_24 + fVar2 * (float)(iVar6 + 0x2d) + (float)local_34)),
               iVar7 + 0xf,local_24,local_20[0]);
  } while (iVar5 != 2);
  return;
}


