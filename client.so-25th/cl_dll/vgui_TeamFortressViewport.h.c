// Ghidra decompilation of functions from cl_dll/vgui_TeamFortressViewport.h
// 119 functions, ordered by original source line

// CImageLabel::paintBackground  @ 0008b0d0  (line 120)

/* DWARF original prototype: void paintBackground(CImageLabel * this) */

void __thiscall CImageLabel::paintBackground(CImageLabel *this)

{
  return;
}


// CommandButton::IsNotValid  @ 0008b0e0  (line 193)

/* DWARF original prototype: int IsNotValid(CommandButton * this) */

int __thiscall CommandButton::IsNotValid(CommandButton *this)

{
  return 0;
}


// ColorButton::paintBackground  @ 000a0030  (line 235)

/* DWARF original prototype: void paintBackground(ColorButton * this) */

void __thiscall ColorButton::paintBackground(ColorButton *this)

{
  Color *pCVar1;
  char cVar2;
  int in_GS_OFFSET;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  Color local_1c [12];
  int local_10;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: Color bgcolor@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Color::Color(local_1c);
  cVar2 = (**(code **)(*(int *)&this->super_CommandButton + 0x248))(this);
  if (cVar2 == '\0') {
    pCVar1 = this->UnArmedBorderColor;
  }
  else {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: Color bgcolor@[???] */
    pCVar1 = this->ArmedBorderColor;
  }
  if (pCVar1 != (Color *)0x0) {
    (**(code **)(*(int *)pCVar1 + 0xc))(pCVar1,&local_2c,&local_28,&local_24,&local_20);
    (**(code **)(*(int *)&this->super_CommandButton + 0x178))
              (this,local_2c,local_28,local_24,local_20);
    (**(code **)(*(int *)&this->super_CommandButton + 0x180))
              (this,0,0,*(undefined4 *)&(this->super_CommandButton).field_0xc,
               *(undefined4 *)&(this->super_CommandButton).field_0x10);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ColorButton::paint  @ 000a0240  (line 265)

/* DWARF original prototype: void paint(ColorButton * this) */

void __thiscall ColorButton::paint(ColorButton *this)

{
  char cVar1;
  Color *pCVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [3];
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
  cVar1 = (**(code **)(*(int *)&this->super_CommandButton + 0x248))(this);
  if (cVar1 == '\0') {
    pCVar2 = this->UnArmedColor;
    if (pCVar2 == (Color *)0x0) {
      (**(code **)(*(int *)&this->super_CommandButton + 0x11c))(this,3);
      vgui::Label::paint();
      return;
    }
  }
  else {
    pCVar2 = this->ArmedColor;
    if (pCVar2 == (Color *)0x0) {
      (**(code **)(*(int *)&this->super_CommandButton + 0x11c))(this,7);
      goto LAB_000a02b8;
    }
  }
  (**(code **)(*(int *)pCVar2 + 0xc))(pCVar2,&local_1c,&local_18,&local_14,local_10);
  (**(code **)(*(int *)&this->super_CommandButton + 0x124))
            (this,local_1c,local_18,local_14,local_10[0]);
LAB_000a02b8:
  vgui::Label::paint();
  return;
}


// SpectButton::paintBackground  @ 0009c6c0  (line 326)

/* DWARF original prototype: void paintBackground(SpectButton * this) */

void __thiscall SpectButton::paintBackground(SpectButton *this)

{
  char cVar1;
  
  cVar1 = (**(code **)(*(int *)&this->super_CommandButton + 0x248))(this);
  if (cVar1 != '\0') {
    (**(code **)(*(int *)&this->super_CommandButton + 0x178))(this,0x8f,0x8f,0x36,0x7d);
    (**(code **)(*(int *)&this->super_CommandButton + 0x17c))
              (this,5,0,*(int *)&(this->super_CommandButton).field_0xc + -5,
               *(undefined4 *)&(this->super_CommandButton).field_0x10);
  }
  return;
}


// SpectButton::paint  @ 0009cb00  (line 335)

/* DWARF original prototype: void paint(SpectButton * this) */

void __thiscall SpectButton::paint(SpectButton *this)

{
  char cVar1;
  
  cVar1 = (**(code **)(*(int *)&this->super_CommandButton + 0x248))(this);
  if (cVar1 == '\0') {
    (**(code **)(*(int *)&this->super_CommandButton + 0x124))(this,0x8f,0x8f,0x36,0xf);
    vgui::Label::paint();
    return;
  }
  (**(code **)(*(int *)&this->super_CommandButton + 0x124))(this,0xc2,0xca,0x36,0);
  vgui::Label::paint();
  return;
}


// DropDownButton::setVisible  @ 0009fff0  (line 435)

/* DWARF original prototype: void setVisible(DropDownButton * this, bool state) */

void __thiscall DropDownButton::setVisible(DropDownButton *this,bool state)

{
  (**(code **)(*(int *)this->m_pOpenButton + 0x24))(this->m_pOpenButton,state);
  vgui::Panel::setVisible(this._0_1_);
  return;
}


// CImageButton::setVisible  @ 0009ffb0  (line 467)

/* DWARF original prototype: void setVisible(CImageButton * this, bool state) */

void __thiscall CImageButton::setVisible(CImageButton *this,bool state)

{
  (**(code **)(*(int *)this->m_pOpenButton + 0x24))(this->m_pOpenButton,state);
  vgui::Panel::setVisible(this._0_1_);
  return;
}


// CMenuHandler_StringCommand::actionPerformed  @ 00087dd0  (line 658)

/* DWARF original prototype: void actionPerformed(CMenuHandler_StringCommand * this, Panel * panel)
    */

void __thiscall
CMenuHandler_StringCommand::actionPerformed(CMenuHandler_StringCommand *this,Panel *panel)

{
  (*gEngfuncs.pfnClientCmd)(this->m_pszCommand);
  if (this->m_iCloseVGUIMenu == 0) {
    TeamFortressViewport::HideCommandMenu(gViewPort);
    return;
  }
  TeamFortressViewport::HideTopMenu(gViewPort);
  return;
}


// CMenuHandler_StringCommandWatch::actionPerformed  @ 000915b0  (line 683)

/* DWARF original prototype: void actionPerformed(CMenuHandler_StringCommandWatch * this, Panel *
   panel) */

void __thiscall
CMenuHandler_StringCommandWatch::actionPerformed(CMenuHandler_StringCommandWatch *this,Panel *panel)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 uVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  pcVar3 = (this->super_CMenuHandler_StringCommand).m_pszCommand;
  (*gEngfuncs.pfnClientCmd)(pcVar3);
  uVar5 = (this->super_CMenuHandler_StringCommand).m_iCloseVGUIMenu == 0;
  if ((bool)uVar5) {
    TeamFortressViewport::HideCommandMenu(gViewPort);
  }
  else {
    TeamFortressViewport::HideTopMenu(gViewPort);
  }
  iVar1 = 0xb;
  pcVar2 = pcVar3;
  pcVar4 = "jointeam 1";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    uVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + (uint)bVar7 * -2 + 1;
    pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
  } while ((bool)uVar5);
  if ((bool)uVar5) {
    g_iTeamNumber = 1;
    return;
  }
  iVar1 = 0xb;
  bVar6 = false;
  pcVar2 = pcVar3;
  pcVar4 = "jointeam 2";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + (uint)bVar7 * -2 + 1;
    pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
  } while (bVar6);
  if (bVar6) {
    g_iTeamNumber = 2;
  }
  else {
    iVar1 = 0xb;
    bVar6 = false;
    pcVar2 = pcVar3;
    pcVar4 = "jointeam 3";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + (uint)bVar7 * -2 + 1;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      g_iTeamNumber = 3;
      return;
    }
    iVar1 = 0xb;
    bVar6 = false;
    pcVar2 = "jointeam 4";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pcVar3 == *pcVar2;
      pcVar3 = pcVar3 + (uint)bVar7 * -2 + 1;
      pcVar2 = pcVar2 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      g_iTeamNumber = 4;
      return;
    }
  }
  return;
}


// CMenuHandler_PopupSubMenuInput::cursorMoved  @ 0009bde0  (line 728)

/* DWARF original prototype: void cursorMoved(CMenuHandler_PopupSubMenuInput * this, int x, int y,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::cursorMoved
          (CMenuHandler_PopupSubMenuInput *this,int x,int y,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::cursorEntered  @ 0009c740  (line 733)

/* DWARF original prototype: void cursorEntered(CMenuHandler_PopupSubMenuInput * this, Panel *
   panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::cursorEntered(CMenuHandler_PopupSubMenuInput *this,Panel *panel)

{
  CCommandMenu **ppCVar1;
  CCommandMenu *pCVar2;
  TeamFortressViewport *pTVar3;
  int iVar4;
  
  pTVar3 = gViewPort;
                    /* Unresolved local var: int i@[???] */
  pCVar2 = this->m_pSubMenu;
  if (0 < gViewPort->m_iNumMenus) {
    iVar4 = 0;
    do {
      ppCVar1 = pTVar3->m_pCommandMenus + iVar4;
      iVar4 = iVar4 + 1;
      (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
    } while (iVar4 < pTVar3->m_iNumMenus);
  }
  pTVar3->m_pCurrentCommandMenu = pCVar2;
  for (; pCVar2 != (CCommandMenu *)0x0; pCVar2 = pCVar2->m_pParentMenu) {
    (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,1);
  }
  if (this->m_pButton != (Button *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009c7ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)this->m_pButton + 0x234))();
    return;
  }
  return;
}


// CMenuHandler_PopupSubMenuInput::cursorExited  @ 0009bdf0  (line 740)

/* DWARF original prototype: void cursorExited(CMenuHandler_PopupSubMenuInput * this, Panel * Panel)
    */

void __thiscall
CMenuHandler_PopupSubMenuInput::cursorExited(CMenuHandler_PopupSubMenuInput *this,Panel *Panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mousePressed  @ 0009be00  (line 741)

/* DWARF original prototype: void mousePressed(CMenuHandler_PopupSubMenuInput * this, MouseCode
   code, Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mousePressed
          (CMenuHandler_PopupSubMenuInput *this,MouseCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mouseDoublePressed  @ 0009be10  (line 742)

/* DWARF original prototype: void mouseDoublePressed(CMenuHandler_PopupSubMenuInput * this,
   MouseCode code, Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mouseDoublePressed
          (CMenuHandler_PopupSubMenuInput *this,MouseCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mouseReleased  @ 0009be20  (line 743)

/* DWARF original prototype: void mouseReleased(CMenuHandler_PopupSubMenuInput * this, MouseCode
   code, Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mouseReleased
          (CMenuHandler_PopupSubMenuInput *this,MouseCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mouseWheeled  @ 0009be30  (line 744)

/* DWARF original prototype: void mouseWheeled(CMenuHandler_PopupSubMenuInput * this, int delta,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mouseWheeled
          (CMenuHandler_PopupSubMenuInput *this,int delta,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyPressed  @ 0009be40  (line 745)

/* DWARF original prototype: void keyPressed(CMenuHandler_PopupSubMenuInput * this, KeyCode code,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyPressed
          (CMenuHandler_PopupSubMenuInput *this,KeyCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyTyped  @ 0009be50  (line 746)

/* DWARF original prototype: void keyTyped(CMenuHandler_PopupSubMenuInput * this, KeyCode code,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyTyped
          (CMenuHandler_PopupSubMenuInput *this,KeyCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyReleased  @ 0009be60  (line 747)

/* DWARF original prototype: void keyReleased(CMenuHandler_PopupSubMenuInput * this, KeyCode code,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyReleased
          (CMenuHandler_PopupSubMenuInput *this,KeyCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyFocusTicked  @ 0009be70  (line 748)

/* DWARF original prototype: void keyFocusTicked(CMenuHandler_PopupSubMenuInput * this, Panel *
   panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyFocusTicked(CMenuHandler_PopupSubMenuInput *this,Panel *panel)

{
  return;
}


// CMenuHandler_TextWindow::actionPerformed  @ 00087e10  (line 794)

/* DWARF original prototype: void actionPerformed(CMenuHandler_TextWindow * this, Panel * panel) */

void __thiscall CMenuHandler_TextWindow::actionPerformed(CMenuHandler_TextWindow *this,Panel *panel)

{
  if (this->m_iState != 0) {
    TeamFortressViewport::HideCommandMenu(gViewPort);
    TeamFortressViewport::ShowVGUIMenu(gViewPort,this->m_iState);
    return;
  }
  TeamFortressViewport::HideTopMenu(gViewPort);
  return;
}


// CMenuHandler_ToggleCvar::actionPerformed  @ 0009c8e0  (line 819)

/* DWARF original prototype: void actionPerformed(CMenuHandler_ToggleCvar * this, Panel * panel) */

void __thiscall CMenuHandler_ToggleCvar::actionPerformed(CMenuHandler_ToggleCvar *this,Panel *panel)

{
  CCommandMenu **ppCVar1;
  float fVar2;
  TeamFortressViewport *this_00;
  int iVar3;
  
  this_00 = gViewPort;
  if (this->m_cvar->value == 0.0) {
    fVar2 = 1.0;
  }
  else {
    fVar2 = 0.0;
  }
  this->m_cvar->value = fVar2;
  if (this_00->m_iInitialized != 0) {
    if (this_00->m_pCommandMenus[this_00->m_StandardMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this_00->m_pCommandMenus[this_00->m_StandardMenu]);
    }
    if (this_00->m_pCommandMenus[this_00->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState
                (this_00->m_pCommandMenus[this_00->m_SpectatorOptionsMenu]);
    }
    if (this_00->m_pCommandMenus[this_00->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState
                (this_00->m_pCommandMenus[this_00->m_SpectatorCameraMenu]);
    }
    if (this_00->m_pCommandMenus[this_00->m_PlayerMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this_00->m_pCommandMenus[this_00->m_PlayerMenu]);
    }
                    /* Unresolved local var: int i@[???] */
    this_00->m_flMenuOpenTime = 0.0;
    if (0 < this_00->m_iNumMenus) {
      iVar3 = 0;
      do {
        ppCVar1 = this_00->m_pCommandMenus + iVar3;
        iVar3 = iVar3 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar3 < this_00->m_iNumMenus);
    }
    this_00->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
    TeamFortressViewport::UpdateCursorState(this_00);
    TeamFortressViewport::UpdateSpectatorPanel(gViewPort);
    return;
  }
  TeamFortressViewport::UpdateSpectatorPanel(this_00);
  return;
}


// CMenuHandler_SpectateFollow::actionPerformed  @ 0009c7e0  (line 848)

/* DWARF original prototype: void actionPerformed(CMenuHandler_SpectateFollow * this, Panel * panel)
    */

void __thiscall
CMenuHandler_SpectateFollow::actionPerformed(CMenuHandler_SpectateFollow *this,Panel *panel)

{
  CCommandMenu **ppCVar1;
  TeamFortressViewport *this_00;
  int iVar2;
  
  CHudSpectator::FindPlayer(&gHUD.m_Spectator,this->m_szplayer);
  this_00 = gViewPort;
  if (gViewPort->m_iInitialized == 0) {
    return;
  }
  if (gViewPort->m_pCommandMenus[gViewPort->m_StandardMenu] != (CCommandMenu *)0x0) {
    CCommandMenu::ClearButtonsOfArmedState(gViewPort->m_pCommandMenus[gViewPort->m_StandardMenu]);
  }
  if (this_00->m_pCommandMenus[this_00->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
    CCommandMenu::ClearButtonsOfArmedState
              (this_00->m_pCommandMenus[this_00->m_SpectatorOptionsMenu]);
  }
  if (this_00->m_pCommandMenus[this_00->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
    CCommandMenu::ClearButtonsOfArmedState(this_00->m_pCommandMenus[this_00->m_SpectatorCameraMenu])
    ;
  }
  if (this_00->m_pCommandMenus[this_00->m_PlayerMenu] != (CCommandMenu *)0x0) {
    CCommandMenu::ClearButtonsOfArmedState(this_00->m_pCommandMenus[this_00->m_PlayerMenu]);
  }
                    /* Unresolved local var: int i@[???] */
  this_00->m_flMenuOpenTime = 0.0;
  if (0 < this_00->m_iNumMenus) {
    iVar2 = 0;
    do {
      ppCVar1 = this_00->m_pCommandMenus + iVar2;
      iVar2 = iVar2 + 1;
      (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
    } while (iVar2 < this_00->m_iNumMenus);
  }
  this_00->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
  TeamFortressViewport::UpdateCursorState(this_00);
  return;
}


// CDragNDropHandler::mouseDoublePressed  @ 0009be80  (line 876)

/* DWARF original prototype: void mouseDoublePressed(CDragNDropHandler * this, MouseCode code, Panel
   * panel) */

void __thiscall
CDragNDropHandler::mouseDoublePressed(CDragNDropHandler *this,MouseCode code,Panel *panel)

{
  return;
}


// CDragNDropHandler::cursorEntered  @ 0009be90  (line 877)

/* DWARF original prototype: void cursorEntered(CDragNDropHandler * this, Panel * panel) */

void __thiscall CDragNDropHandler::cursorEntered(CDragNDropHandler *this,Panel *panel)

{
  return;
}


// CDragNDropHandler::cursorExited  @ 0009bea0  (line 878)

/* DWARF original prototype: void cursorExited(CDragNDropHandler * this, Panel * panel) */

void __thiscall CDragNDropHandler::cursorExited(CDragNDropHandler *this,Panel *panel)

{
  return;
}


// CDragNDropHandler::mouseWheeled  @ 0009beb0  (line 879)

/* DWARF original prototype: void mouseWheeled(CDragNDropHandler * this, int delta, Panel * panel)
    */

void __thiscall CDragNDropHandler::mouseWheeled(CDragNDropHandler *this,int delta,Panel *panel)

{
  return;
}


// CDragNDropHandler::keyPressed  @ 0009bec0  (line 880)

/* DWARF original prototype: void keyPressed(CDragNDropHandler * this, KeyCode code, Panel * panel)
    */

void __thiscall CDragNDropHandler::keyPressed(CDragNDropHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// CDragNDropHandler::keyTyped  @ 0009bed0  (line 881)

/* DWARF original prototype: void keyTyped(CDragNDropHandler * this, KeyCode code, Panel * panel) */

void __thiscall CDragNDropHandler::keyTyped(CDragNDropHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// CDragNDropHandler::keyReleased  @ 0009bee0  (line 882)

/* DWARF original prototype: void keyReleased(CDragNDropHandler * this, KeyCode code, Panel * panel)
    */

void __thiscall CDragNDropHandler::keyReleased(CDragNDropHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// CDragNDropHandler::keyFocusTicked  @ 0009bef0  (line 883)

/* DWARF original prototype: void keyFocusTicked(CDragNDropHandler * this, Panel * panel) */

void __thiscall CDragNDropHandler::keyFocusTicked(CDragNDropHandler *this,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::cursorMoved  @ 0008b0f0  (line 900)

/* DWARF original prototype: void cursorMoved(CHandler_MenuButtonOver * this, int x, int y, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::cursorMoved(CHandler_MenuButtonOver *this,int x,int y,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mousePressed  @ 0008b100  (line 901)

/* DWARF original prototype: void mousePressed(CHandler_MenuButtonOver * this, MouseCode code, Panel
   * panel) */

void __thiscall
CHandler_MenuButtonOver::mousePressed(CHandler_MenuButtonOver *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mouseReleased  @ 0008b110  (line 902)

/* DWARF original prototype: void mouseReleased(CHandler_MenuButtonOver * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_MenuButtonOver::mouseReleased(CHandler_MenuButtonOver *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mouseDoublePressed  @ 0008b120  (line 903)

/* DWARF original prototype: void mouseDoublePressed(CHandler_MenuButtonOver * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_MenuButtonOver::mouseDoublePressed
          (CHandler_MenuButtonOver *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::cursorExited  @ 0008b130  (line 904)

/* DWARF original prototype: void cursorExited(CHandler_MenuButtonOver * this, Panel * panel) */

void __thiscall CHandler_MenuButtonOver::cursorExited(CHandler_MenuButtonOver *this,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mouseWheeled  @ 0008b140  (line 905)

/* DWARF original prototype: void mouseWheeled(CHandler_MenuButtonOver * this, int delta, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::mouseWheeled(CHandler_MenuButtonOver *this,int delta,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyPressed  @ 0008b150  (line 906)

/* DWARF original prototype: void keyPressed(CHandler_MenuButtonOver * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::keyPressed(CHandler_MenuButtonOver *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyTyped  @ 0008b160  (line 907)

/* DWARF original prototype: void keyTyped(CHandler_MenuButtonOver * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::keyTyped(CHandler_MenuButtonOver *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyReleased  @ 0008b170  (line 908)

/* DWARF original prototype: void keyReleased(CHandler_MenuButtonOver * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::keyReleased(CHandler_MenuButtonOver *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyFocusTicked  @ 0008b180  (line 909)

/* DWARF original prototype: void keyFocusTicked(CHandler_MenuButtonOver * this, Panel * panel) */

void __thiscall CHandler_MenuButtonOver::keyFocusTicked(CHandler_MenuButtonOver *this,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::cursorEntered  @ 0008b190  (line 924)

/* DWARF original prototype: void cursorEntered(CHandler_ButtonHighlight * this, Panel * panel) */

void __thiscall CHandler_ButtonHighlight::cursorEntered(CHandler_ButtonHighlight *this,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x0008b1a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->m_pButton + 0x234))();
  return;
}


// CHandler_ButtonHighlight::cursorExited  @ 0008b1b0  (line 928)

/* DWARF original prototype: void cursorExited(CHandler_ButtonHighlight * this, Panel * Panel) */

void __thiscall CHandler_ButtonHighlight::cursorExited(CHandler_ButtonHighlight *this,Panel *Panel)

{
                    /* WARNING: Could not recover jumptable at 0x0008b1c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->m_pButton + 0x234))();
  return;
}


// CHandler_ButtonHighlight::mousePressed  @ 0008b1d0  (line 930)

/* DWARF original prototype: void mousePressed(CHandler_ButtonHighlight * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::mousePressed(CHandler_ButtonHighlight *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::mouseReleased  @ 0008b1e0  (line 931)

/* DWARF original prototype: void mouseReleased(CHandler_ButtonHighlight * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::mouseReleased(CHandler_ButtonHighlight *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::cursorMoved  @ 0008b1f0  (line 932)

/* DWARF original prototype: void cursorMoved(CHandler_ButtonHighlight * this, int x, int y, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::cursorMoved(CHandler_ButtonHighlight *this,int x,int y,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::mouseDoublePressed  @ 0008b200  (line 933)

/* DWARF original prototype: void mouseDoublePressed(CHandler_ButtonHighlight * this, MouseCode
   code, Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::mouseDoublePressed
          (CHandler_ButtonHighlight *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::mouseWheeled  @ 0008b210  (line 934)

/* DWARF original prototype: void mouseWheeled(CHandler_ButtonHighlight * this, int delta, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::mouseWheeled(CHandler_ButtonHighlight *this,int delta,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyPressed  @ 0008b220  (line 935)

/* DWARF original prototype: void keyPressed(CHandler_ButtonHighlight * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::keyPressed(CHandler_ButtonHighlight *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyTyped  @ 0008b230  (line 936)

/* DWARF original prototype: void keyTyped(CHandler_ButtonHighlight * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::keyTyped(CHandler_ButtonHighlight *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyReleased  @ 0008b240  (line 937)

/* DWARF original prototype: void keyReleased(CHandler_ButtonHighlight * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::keyReleased(CHandler_ButtonHighlight *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyFocusTicked  @ 0008b250  (line 938)

/* DWARF original prototype: void keyFocusTicked(CHandler_ButtonHighlight * this, Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::keyFocusTicked(CHandler_ButtonHighlight *this,Panel *panel)

{
  return;
}


// CHandler_CommandButtonHighlight::cursorEntered  @ 0008b2a0  (line 954)

/* DWARF original prototype: void cursorEntered(CHandler_CommandButtonHighlight * this, Panel *
   panel) */

void __thiscall
CHandler_CommandButtonHighlight::cursorEntered(CHandler_CommandButtonHighlight *this,Panel *panel)

{
  CommandButton *pCVar1;
  CCommandMenu *pCVar2;
  CommandButton *pCVar3;
  CommandButton *pCVar4;
  CommandButton *pCVar5;
  CommandButton *pCVar6;
  CommandButton *pCVar7;
  CommandButton *this_00;
  
  pCVar1 = this->m_pCommandButton;
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
  pCVar2 = pCVar1->m_pParentMenu;
  if (pCVar2 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
    CCommandMenu::ClearButtonsOfArmedState(pCVar2);
    if (pCVar2->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
      pCVar3 = CCommandMenu::FindButtonWithSubmenu(pCVar2->m_pParentMenu,pCVar2);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
      pCVar2 = pCVar3->m_pParentMenu;
      if (pCVar2 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
        CCommandMenu::ClearButtonsOfArmedState(pCVar2);
        if (pCVar2->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
          pCVar4 = CCommandMenu::FindButtonWithSubmenu(pCVar2->m_pParentMenu,pCVar2);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
          pCVar2 = pCVar4->m_pParentMenu;
          if (pCVar2 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
            CCommandMenu::ClearButtonsOfArmedState(pCVar2);
            if (pCVar2->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
              pCVar5 = CCommandMenu::FindButtonWithSubmenu(pCVar2->m_pParentMenu,pCVar2);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
              pCVar2 = pCVar5->m_pParentMenu;
              if (pCVar2 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
                CCommandMenu::ClearButtonsOfArmedState(pCVar2);
                if (pCVar2->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
                  pCVar6 = CCommandMenu::FindButtonWithSubmenu(pCVar2->m_pParentMenu,pCVar2);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
                  pCVar2 = pCVar6->m_pParentMenu;
                  if (pCVar2 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
                    CCommandMenu::ClearButtonsOfArmedState(pCVar2);
                    if (pCVar2->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
                      pCVar7 = CCommandMenu::FindButtonWithSubmenu(pCVar2->m_pParentMenu,pCVar2);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
                      pCVar2 = pCVar7->m_pParentMenu;
                      if (pCVar2 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
                        CCommandMenu::ClearButtonsOfArmedState(pCVar2);
                        if (pCVar2->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
                          this_00 = CCommandMenu::FindButtonWithSubmenu
                                              (pCVar2->m_pParentMenu,pCVar2);
                          CommandButton::cursorEntered(this_00);
                        }
                      }
                      (**(code **)(*(int *)pCVar7 + 0x234))(pCVar7,1);
                    }
                  }
                  (**(code **)(*(int *)pCVar6 + 0x234))(pCVar6,1);
                }
              }
              (**(code **)(*(int *)pCVar5 + 0x234))(pCVar5,1);
            }
          }
          (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,1);
        }
      }
      (**(code **)(*(int *)pCVar3 + 0x234))(pCVar3,1);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0008b49b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pCVar1 + 0x234))();
  return;
}


// CHandler_CommandButtonHighlight::cursorExited  @ 0008b260  (line 961)

/* DWARF original prototype: void cursorExited(CHandler_CommandButtonHighlight * this, Panel *
   panel) */

void __thiscall
CHandler_CommandButtonHighlight::cursorExited(CHandler_CommandButtonHighlight *this,Panel *panel)

{
  CommandButton *pCVar1;
  
  pCVar1 = this->m_pCommandButton;
  if ((pCVar1->m_pParentMenu != (CCommandMenu *)0x0) && (pCVar1->m_pSubMenu != (CCommandMenu *)0x0))
  {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008b28c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pCVar1 + 0x234))();
  return;
}


// TeamButton::IsNotValid  @ 0009bf00  (line 992)

/* DWARF original prototype: int IsNotValid(TeamButton * this) */

int __thiscall TeamButton::IsNotValid(TeamButton *this)

{
  int iVar1;
  
                    /* Unresolved local var: int iTeams@[???] */
  if (gViewPort->m_iNumberOfTeams != 1) {
    iVar1 = this->m_iTeamNumber;
    if (iVar1 == 5) {
                    /* catch() { ... } // from try @ 0009c0aa with catch @ 0009bf40
                       catch() { ... } // from try @ 0009c6f2 with catch @ 0009bf40 */
      return 0;
    }
    if (iVar1 <= gViewPort->m_iNumberOfTeams) {
      return (uint)(g_iTeamNumber == iVar1);
    }
  }
  return 1;
}


// FeignButton::IsNotValid  @ 0009bf50  (line 1023)

/* DWARF original prototype: int IsNotValid(FeignButton * this) */

int __thiscall FeignButton::IsNotValid(FeignButton *this)

{
  if (g_iPlayerClass != 8) {
    return 1;
  }
  return (uint)(gViewPort->m_iIsFeigning != this->m_iFeignState);
}


// SpectateButton::IsNotValid  @ 0009bf80  (line 1040)

/* DWARF original prototype: int IsNotValid(SpectateButton * this) */

int __thiscall SpectateButton::IsNotValid(SpectateButton *this)

{
  return (uint)(gViewPort->m_iAllowSpectators == 0);
}


// DisguiseButton::IsNotValid  @ 0009c600  (line 1069)

/* DWARF original prototype: int IsNotValid(DisguiseButton * this) */

int __thiscall DisguiseButton::IsNotValid(DisguiseButton *this)

{
  int iVar1;
  
                    /* Unresolved local var: int iTmp@[???] */
  iVar1 = 1;
                    /* Unresolved local var: int iTmp@[???] */
  if ((g_iPlayerClass == 8) && (iVar1 = 0, this->m_iValidTeamsBits != 0)) {
    return (uint)((1 << ((char)gViewPort->m_iNumberOfTeams - 1U & 0x1f) & this->m_iValidTeamsBits)
                 == 0);
  }
  return iVar1;
}


// DetpackButton::IsNotValid  @ 0009bfa0  (line 1098)

/* DWARF original prototype: int IsNotValid(DetpackButton * this) */

int __thiscall DetpackButton::IsNotValid(DetpackButton *this)

{
  if (g_iPlayerClass != 4) {
    return 1;
  }
  return (uint)(gViewPort->m_iIsSettingDetpack != this->m_iDetpackState);
}


// BuildButton::IsNotValid  @ 0009c4c0  (line 1138)

/* DWARF original prototype: int IsNotValid(BuildButton * this) */

int __thiscall BuildButton::IsNotValid(BuildButton *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  if (g_iPlayerClass == 9) {
    uVar1 = this->m_iBuildState;
    uVar2 = gViewPort->m_iBuildState;
    if ((uVar1 & 2) == 0) {
      if ((uVar2 & 1) != 0) {
        return 1;
      }
    }
    else if ((uVar2 & 1) == 0) {
      return iVar3;
    }
    if ((uVar1 & 4) != 0) {
      return (uint)((uVar2 & 0x1fe) == 0);
    }
    if ((uVar1 & 1) != 0) {
      iVar3 = this->m_iBuildData;
      if (iVar3 == 0) {
        if ((uVar2 & 2) == 0) {
          return 1;
        }
        if ((uVar1 & 8) == 0) {
          return 0;
        }
        goto LAB_0009c5a5;
      }
      if (iVar3 == 1) {
        if ((uVar2 & 4) == 0) {
          return 1;
        }
        if ((uVar1 & 8) == 0) {
          return 0;
        }
        goto LAB_0009c5c0;
      }
      if (iVar3 == 2) {
        if ((uVar2 & 0x20) == 0) {
          return 1;
        }
        if ((uVar1 & 8) == 0) {
          return 0;
        }
        goto LAB_0009c5e2;
      }
      if (iVar3 == 3) {
        if ((uVar2 & 0x40) == 0) {
          return 1;
        }
        if ((uVar1 & 8) == 0) {
          return 0;
        }
        goto LAB_0009c582;
      }
    }
    iVar3 = 0;
    if ((uVar1 & 8) != 0) {
      iVar3 = this->m_iBuildData;
      if (iVar3 != 0) {
        if (iVar3 != 1) {
          if (iVar3 != 2) {
            if (iVar3 != 3) {
              return 1;
            }
LAB_0009c582:
            return (uint)((uVar2 & 0x100) == 0);
          }
LAB_0009c5e2:
          return (uint)((uVar2 & 0x80) == 0);
        }
LAB_0009c5c0:
        return (uint)((uVar2 & 0x10) == 0);
      }
LAB_0009c5a5:
      return (uint)((uVar2 & 8) == 0);
    }
  }
  return iVar3;
}


// MapButton::IsNotValid  @ 0009c360  (line 1210)

/* WARNING: Struct "MapButton": ignoring overlapping field "m_szMapName" */
/* DWARF original prototype: int IsNotValid(MapButton * this) */

int __thiscall MapButton::IsNotValid(MapButton *this)

{
  char *__s2;
  int iVar1;
  
                    /* Unresolved local var: char * level@[???] */
  __s2 = (*gEngfuncs.pfnGetLevelName)();
  if (__s2 != (char *)0x0) {
    iVar1 = strcmp(&(this->super_CommandButton).field_0x12d,__s2);
    return (uint)(iVar1 != 0);
  }
  return 1;
}


// TeamOnlyCommandButton::IsNotValid  @ 0009bfd0  (line 1236)

/* DWARF original prototype: int IsNotValid(TeamOnlyCommandButton * this) */

int __thiscall TeamOnlyCommandButton::IsNotValid(TeamOnlyCommandButton *this)

{
  return (uint)(this->m_iTeamNum != g_iTeamNumber);
}


// ToggleCommandButton::cursorEntered  @ 0009c3f0  (line 1284)

/* non-virtual thunk to ToggleCommandButton::cursorEntered(vgui::Panel*) */

void __thiscall ToggleCommandButton::cursorEntered(ToggleCommandButton *this,Panel *param_1)

{
  cursorEntered((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1);
  return;
}


// ToggleCommandButton::cursorEntered  @ 0009c3e0  (line 1286)

/* DWARF original prototype: void cursorEntered(ToggleCommandButton * this, Panel * panel) */

void __thiscall ToggleCommandButton::cursorEntered(ToggleCommandButton *this,Panel *panel)

{
  CCommandMenu *pCVar1;
  CommandButton *pCVar2;
  CommandButton *pCVar3;
  CommandButton *pCVar4;
  CommandButton *pCVar5;
  CommandButton *this_00;
  
  pCVar1 = (this->super_CommandButton).m_pParentMenu;
  if (pCVar1 != (CCommandMenu *)0x0) {
    CCommandMenu::ClearButtonsOfArmedState(pCVar1);
    if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
      pCVar2 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
      pCVar1 = pCVar2->m_pParentMenu;
      if (pCVar1 != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(pCVar1);
        if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
          pCVar3 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
          pCVar1 = pCVar3->m_pParentMenu;
          if (pCVar1 != (CCommandMenu *)0x0) {
            CCommandMenu::ClearButtonsOfArmedState(pCVar1);
            if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
              pCVar4 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
              pCVar1 = pCVar4->m_pParentMenu;
              if (pCVar1 != (CCommandMenu *)0x0) {
                CCommandMenu::ClearButtonsOfArmedState(pCVar1);
                if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                  pCVar5 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                  pCVar1 = pCVar5->m_pParentMenu;
                  if (pCVar1 != (CCommandMenu *)0x0) {
                    CCommandMenu::ClearButtonsOfArmedState(pCVar1);
                    if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                      this_00 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                      CommandButton::cursorEntered(this_00);
                    }
                  }
                  (**(code **)(*(int *)pCVar5 + 0x234))(pCVar5,1);
                }
              }
              (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,1);
            }
          }
          (**(code **)(*(int *)pCVar3 + 0x234))(pCVar3,1);
        }
      }
      (**(code **)(*(int *)pCVar2 + 0x234))(pCVar2,1);
    }
  }
  (**(code **)(*(int *)&this->super_CommandButton + 0x234))(this,1);
  return;
}


// ToggleCommandButton::cursorExited  @ 0009c3b0  (line 1289)

/* non-virtual thunk to ToggleCommandButton::cursorExited(vgui::Panel*) */

void __thiscall ToggleCommandButton::cursorExited(ToggleCommandButton *this,Panel *param_1)

{
  cursorExited((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1);
  return;
}


// ToggleCommandButton::cursorExited  @ 0009c3a0  (line 1291)

/* DWARF original prototype: void cursorExited(ToggleCommandButton * this, Panel * panel) */

void __thiscall ToggleCommandButton::cursorExited(ToggleCommandButton *this,Panel *panel)

{
  if (((this->super_CommandButton).m_pParentMenu != (CCommandMenu *)0x0) &&
     ((this->super_CommandButton).m_pSubMenu != (CCommandMenu *)0x0)) {
    return;
  }
  (**(code **)(*(int *)&this->super_CommandButton + 0x234))(this,0);
  return;
}


// ToggleCommandButton::mousePressed  @ 0009bff0  (line 1294)

/* DWARF original prototype: void mousePressed(ToggleCommandButton * this, MouseCode code, Panel *
   panel) */

void __thiscall
ToggleCommandButton::mousePressed(ToggleCommandButton *this,MouseCode code,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x0009bff6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)&this->super_CommandButton + 0x23c))();
  return;
}


// ToggleCommandButton::mousePressed  @ 0009c000  (line 1294)

/* non-virtual thunk to ToggleCommandButton::mousePressed(vgui::MouseCode, vgui::Panel*) */

void __thiscall
ToggleCommandButton::mousePressed(ToggleCommandButton *this,MouseCode param_1,Panel *param_2)

{
  mousePressed((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2);
  return;
}


// ToggleCommandButton::cursorMoved  @ 0009c010  (line 1299)

/* DWARF original prototype: void cursorMoved(ToggleCommandButton * this, int x, int y, Panel *
   panel) */

void __thiscall ToggleCommandButton::cursorMoved(ToggleCommandButton *this,int x,int y,Panel *panel)

{
  return;
}


// ToggleCommandButton::cursorMoved  @ 0009c020  (line 1299)

/* non-virtual thunk to ToggleCommandButton::cursorMoved(int, int, vgui::Panel*) */

void __thiscall
ToggleCommandButton::cursorMoved(ToggleCommandButton *this,int param_1,int param_2,Panel *param_3)

{
  cursorMoved((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2,
              param_3);
  return;
}


// ToggleCommandButton::mouseDoublePressed  @ 0009c030  (line 1301)

/* DWARF original prototype: void mouseDoublePressed(ToggleCommandButton * this, MouseCode code,
   Panel * panel) */

void __thiscall
ToggleCommandButton::mouseDoublePressed(ToggleCommandButton *this,MouseCode code,Panel *panel)

{
  return;
}


// ToggleCommandButton::mouseDoublePressed  @ 0009c040  (line 1301)

/* non-virtual thunk to ToggleCommandButton::mouseDoublePressed(vgui::MouseCode, vgui::Panel*) */

void __thiscall
ToggleCommandButton::mouseDoublePressed(ToggleCommandButton *this,MouseCode param_1,Panel *param_2)

{
  mouseDoublePressed((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2
                    );
  return;
}


// ToggleCommandButton::mouseReleased  @ 0009c050  (line 1302)

/* DWARF original prototype: void mouseReleased(ToggleCommandButton * this, MouseCode code, Panel *
   panel) */

void __thiscall
ToggleCommandButton::mouseReleased(ToggleCommandButton *this,MouseCode code,Panel *panel)

{
  return;
}


// ToggleCommandButton::mouseReleased  @ 0009c060  (line 1302)

/* non-virtual thunk to ToggleCommandButton::mouseReleased(vgui::MouseCode, vgui::Panel*) */

void __thiscall
ToggleCommandButton::mouseReleased(ToggleCommandButton *this,MouseCode param_1,Panel *param_2)

{
  mouseReleased((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2);
  return;
}


// ToggleCommandButton::mouseWheeled  @ 0009c070  (line 1303)

/* DWARF original prototype: void mouseWheeled(ToggleCommandButton * this, int delta, Panel * panel)
    */

void __thiscall ToggleCommandButton::mouseWheeled(ToggleCommandButton *this,int delta,Panel *panel)

{
  return;
}


// ToggleCommandButton::mouseWheeled  @ 0009c080  (line 1303)

/* non-virtual thunk to ToggleCommandButton::mouseWheeled(int, vgui::Panel*) */

void __thiscall
ToggleCommandButton::mouseWheeled(ToggleCommandButton *this,int param_1,Panel *param_2)

{
  mouseWheeled((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2);
  return;
}


// ToggleCommandButton::keyPressed  @ 0009c090  (line 1304)

/* DWARF original prototype: void keyPressed(ToggleCommandButton * this, KeyCode code, Panel *
   panel) */

void __thiscall ToggleCommandButton::keyPressed(ToggleCommandButton *this,KeyCode code,Panel *panel)

{
  return;
}


// ToggleCommandButton::keyPressed  @ 0009c0a0  (line 1304)

/* non-virtual thunk to ToggleCommandButton::keyPressed(vgui::KeyCode, vgui::Panel*) */

void __thiscall
ToggleCommandButton::keyPressed(ToggleCommandButton *this,KeyCode param_1,Panel *param_2)

{
  keyPressed((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2);
  return;
}


// ToggleCommandButton::keyTyped  @ 0009c0b0  (line 1305)

/* DWARF original prototype: void keyTyped(ToggleCommandButton * this, KeyCode code, Panel * panel)
    */

void __thiscall ToggleCommandButton::keyTyped(ToggleCommandButton *this,KeyCode code,Panel *panel)

{
  return;
}


// ToggleCommandButton::keyTyped  @ 0009c0c0  (line 1305)

/* non-virtual thunk to ToggleCommandButton::keyTyped(vgui::KeyCode, vgui::Panel*) */

void __thiscall
ToggleCommandButton::keyTyped(ToggleCommandButton *this,KeyCode param_1,Panel *param_2)

{
  keyTyped((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2);
  return;
}


// ToggleCommandButton::keyReleased  @ 0009c0d0  (line 1306)

/* DWARF original prototype: void keyReleased(ToggleCommandButton * this, KeyCode code, Panel *
   panel) */

void __thiscall
ToggleCommandButton::keyReleased(ToggleCommandButton *this,KeyCode code,Panel *panel)

{
  return;
}


// ToggleCommandButton::keyReleased  @ 0009c0e0  (line 1306)

/* non-virtual thunk to ToggleCommandButton::keyReleased(vgui::KeyCode, vgui::Panel*) */

void __thiscall
ToggleCommandButton::keyReleased(ToggleCommandButton *this,KeyCode param_1,Panel *param_2)

{
  keyReleased((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1,param_2);
  return;
}


// ToggleCommandButton::keyFocusTicked  @ 0009c0f0  (line 1307)

/* DWARF original prototype: void keyFocusTicked(ToggleCommandButton * this, Panel * panel) */

void __thiscall ToggleCommandButton::keyFocusTicked(ToggleCommandButton *this,Panel *panel)

{
  return;
}


// ToggleCommandButton::keyFocusTicked  @ 0009c100  (line 1307)

/* non-virtual thunk to ToggleCommandButton::keyFocusTicked(vgui::Panel*) */

void __thiscall ToggleCommandButton::keyFocusTicked(ToggleCommandButton *this,Panel *param_1)

{
  keyFocusTicked((ToggleCommandButton *)&this[-1].super_CommandButton.field_0x10,param_1);
  return;
}


// ToggleCommandButton::paint  @ 0009c420  (line 1309)

/* DWARF original prototype: void paint(ToggleCommandButton * this) */

void __thiscall ToggleCommandButton::paint(ToggleCommandButton *this)

{
  CImageLabel *pCVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (this->m_cvar == (cvar_s *)0x0) {
    pCVar1 = this->pLabelOff;
    iVar2 = *(int *)pCVar1;
    uVar3 = 0;
  }
  else {
    pCVar1 = this->pLabelOff;
    iVar2 = *(int *)pCVar1;
    if (this->m_cvar->value != 0.0) {
      (**(code **)(iVar2 + 0x24))(pCVar1,0);
      (**(code **)(*(int *)this->pLabelOn + 0x24))(this->pLabelOn,1);
      CommandButton::paint(&this->super_CommandButton);
      return;
    }
    uVar3 = 1;
  }
  (**(code **)(iVar2 + 0x24))(pCVar1,uVar3);
  (**(code **)(*(int *)this->pLabelOn + 0x24))(this->pLabelOn,0);
  CommandButton::paint(&this->super_CommandButton);
  return;
}


// SpectToggleButton::cursorEntered  @ 0009c410  (line 1356)

/* non-virtual thunk to SpectToggleButton::cursorEntered(vgui::Panel*) */

void __thiscall SpectToggleButton::cursorEntered(SpectToggleButton *this,Panel *param_1)

{
  cursorEntered((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1);
  return;
}


// SpectToggleButton::cursorEntered  @ 0009c400  (line 1358)

/* DWARF original prototype: void cursorEntered(SpectToggleButton * this, Panel * panel) */

void __thiscall SpectToggleButton::cursorEntered(SpectToggleButton *this,Panel *panel)

{
  CCommandMenu *pCVar1;
  CommandButton *pCVar2;
  CommandButton *pCVar3;
  CommandButton *pCVar4;
  CommandButton *pCVar5;
  CommandButton *this_00;
  
  pCVar1 = (this->super_CommandButton).m_pParentMenu;
  if (pCVar1 != (CCommandMenu *)0x0) {
    CCommandMenu::ClearButtonsOfArmedState(pCVar1);
    if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
      pCVar2 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
      pCVar1 = pCVar2->m_pParentMenu;
      if (pCVar1 != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(pCVar1);
        if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
          pCVar3 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
          pCVar1 = pCVar3->m_pParentMenu;
          if (pCVar1 != (CCommandMenu *)0x0) {
            CCommandMenu::ClearButtonsOfArmedState(pCVar1);
            if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
              pCVar4 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
              pCVar1 = pCVar4->m_pParentMenu;
              if (pCVar1 != (CCommandMenu *)0x0) {
                CCommandMenu::ClearButtonsOfArmedState(pCVar1);
                if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                  pCVar5 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                  pCVar1 = pCVar5->m_pParentMenu;
                  if (pCVar1 != (CCommandMenu *)0x0) {
                    CCommandMenu::ClearButtonsOfArmedState(pCVar1);
                    if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                      this_00 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                      CommandButton::cursorEntered(this_00);
                    }
                  }
                  (**(code **)(*(int *)pCVar5 + 0x234))(pCVar5,1);
                }
              }
              (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,1);
            }
          }
          (**(code **)(*(int *)pCVar3 + 0x234))(pCVar3,1);
        }
      }
      (**(code **)(*(int *)pCVar2 + 0x234))(pCVar2,1);
    }
  }
  (**(code **)(*(int *)&this->super_CommandButton + 0x234))(this,1);
  return;
}


// SpectToggleButton::cursorExited  @ 0009c3d0  (line 1361)

/* non-virtual thunk to SpectToggleButton::cursorExited(vgui::Panel*) */

void __thiscall SpectToggleButton::cursorExited(SpectToggleButton *this,Panel *param_1)

{
  cursorExited((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1);
  return;
}


// SpectToggleButton::cursorExited  @ 0009c3c0  (line 1363)

/* DWARF original prototype: void cursorExited(SpectToggleButton * this, Panel * panel) */

void __thiscall SpectToggleButton::cursorExited(SpectToggleButton *this,Panel *panel)

{
  if (((this->super_CommandButton).m_pParentMenu != (CCommandMenu *)0x0) &&
     ((this->super_CommandButton).m_pSubMenu != (CCommandMenu *)0x0)) {
    return;
  }
  (**(code **)(*(int *)&this->super_CommandButton + 0x234))(this,0);
  return;
}


// SpectToggleButton::mousePressed  @ 0009c110  (line 1366)

/* DWARF original prototype: void mousePressed(SpectToggleButton * this, MouseCode code, Panel *
   panel) */

void __thiscall SpectToggleButton::mousePressed(SpectToggleButton *this,MouseCode code,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x0009c116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)&this->super_CommandButton + 0x23c))();
  return;
}


// SpectToggleButton::mousePressed  @ 0009c120  (line 1366)

/* non-virtual thunk to SpectToggleButton::mousePressed(vgui::MouseCode, vgui::Panel*) */

void __thiscall
SpectToggleButton::mousePressed(SpectToggleButton *this,MouseCode param_1,Panel *param_2)

{
  mousePressed((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2);
  return;
}


// SpectToggleButton::cursorMoved  @ 0009c130  (line 1371)

/* DWARF original prototype: void cursorMoved(SpectToggleButton * this, int x, int y, Panel * panel)
    */

void __thiscall SpectToggleButton::cursorMoved(SpectToggleButton *this,int x,int y,Panel *panel)

{
  return;
}


// SpectToggleButton::cursorMoved  @ 0009c140  (line 1371)

/* non-virtual thunk to SpectToggleButton::cursorMoved(int, int, vgui::Panel*) */

void __thiscall
SpectToggleButton::cursorMoved(SpectToggleButton *this,int param_1,int param_2,Panel *param_3)

{
  cursorMoved((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2,param_3);
  return;
}


// SpectToggleButton::mouseDoublePressed  @ 0009c150  (line 1373)

/* DWARF original prototype: void mouseDoublePressed(SpectToggleButton * this, MouseCode code, Panel
   * panel) */

void __thiscall
SpectToggleButton::mouseDoublePressed(SpectToggleButton *this,MouseCode code,Panel *panel)

{
  return;
}


// SpectToggleButton::mouseDoublePressed  @ 0009c160  (line 1373)

/* non-virtual thunk to SpectToggleButton::mouseDoublePressed(vgui::MouseCode, vgui::Panel*) */

void __thiscall
SpectToggleButton::mouseDoublePressed(SpectToggleButton *this,MouseCode param_1,Panel *param_2)

{
  mouseDoublePressed((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2);
  return;
}


// SpectToggleButton::mouseReleased  @ 0009c170  (line 1374)

/* DWARF original prototype: void mouseReleased(SpectToggleButton * this, MouseCode code, Panel *
   panel) */

void __thiscall
SpectToggleButton::mouseReleased(SpectToggleButton *this,MouseCode code,Panel *panel)

{
  return;
}


// SpectToggleButton::mouseReleased  @ 0009c180  (line 1374)

/* non-virtual thunk to SpectToggleButton::mouseReleased(vgui::MouseCode, vgui::Panel*) */

void __thiscall
SpectToggleButton::mouseReleased(SpectToggleButton *this,MouseCode param_1,Panel *param_2)

{
  mouseReleased((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2);
  return;
}


// SpectToggleButton::mouseWheeled  @ 0009c190  (line 1375)

/* DWARF original prototype: void mouseWheeled(SpectToggleButton * this, int delta, Panel * panel)
    */

void __thiscall SpectToggleButton::mouseWheeled(SpectToggleButton *this,int delta,Panel *panel)

{
  return;
}


// SpectToggleButton::mouseWheeled  @ 0009c1a0  (line 1375)

/* non-virtual thunk to SpectToggleButton::mouseWheeled(int, vgui::Panel*) */

void __thiscall SpectToggleButton::mouseWheeled(SpectToggleButton *this,int param_1,Panel *param_2)

{
  mouseWheeled((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2);
  return;
}


// SpectToggleButton::keyPressed  @ 0009c1b0  (line 1376)

/* DWARF original prototype: void keyPressed(SpectToggleButton * this, KeyCode code, Panel * panel)
    */

void __thiscall SpectToggleButton::keyPressed(SpectToggleButton *this,KeyCode code,Panel *panel)

{
  return;
}


// SpectToggleButton::keyPressed  @ 0009c1c0  (line 1376)

/* non-virtual thunk to SpectToggleButton::keyPressed(vgui::KeyCode, vgui::Panel*) */

void __thiscall
SpectToggleButton::keyPressed(SpectToggleButton *this,KeyCode param_1,Panel *param_2)

{
  keyPressed((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2);
  return;
}


// SpectToggleButton::keyTyped  @ 0009c1d0  (line 1377)

/* DWARF original prototype: void keyTyped(SpectToggleButton * this, KeyCode code, Panel * panel) */

void __thiscall SpectToggleButton::keyTyped(SpectToggleButton *this,KeyCode code,Panel *panel)

{
  return;
}


// SpectToggleButton::keyTyped  @ 0009c1e0  (line 1377)

/* non-virtual thunk to SpectToggleButton::keyTyped(vgui::KeyCode, vgui::Panel*) */

void __thiscall SpectToggleButton::keyTyped(SpectToggleButton *this,KeyCode param_1,Panel *param_2)

{
  keyTyped((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2);
  return;
}


// SpectToggleButton::keyReleased  @ 0009c1f0  (line 1378)

/* DWARF original prototype: void keyReleased(SpectToggleButton * this, KeyCode code, Panel * panel)
    */

void __thiscall SpectToggleButton::keyReleased(SpectToggleButton *this,KeyCode code,Panel *panel)

{
  return;
}


// SpectToggleButton::keyReleased  @ 0009c200  (line 1378)

/* non-virtual thunk to SpectToggleButton::keyReleased(vgui::KeyCode, vgui::Panel*) */

void __thiscall
SpectToggleButton::keyReleased(SpectToggleButton *this,KeyCode param_1,Panel *param_2)

{
  keyReleased((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1,param_2);
  return;
}


// SpectToggleButton::keyFocusTicked  @ 0009c210  (line 1379)

/* DWARF original prototype: void keyFocusTicked(SpectToggleButton * this, Panel * panel) */

void __thiscall SpectToggleButton::keyFocusTicked(SpectToggleButton *this,Panel *panel)

{
  return;
}


// SpectToggleButton::keyFocusTicked  @ 0009c220  (line 1379)

/* non-virtual thunk to SpectToggleButton::keyFocusTicked(vgui::Panel*) */

void __thiscall SpectToggleButton::keyFocusTicked(SpectToggleButton *this,Panel *param_1)

{
  keyFocusTicked((SpectToggleButton *)&this[-1].super_CommandButton.field_0xc,param_1);
  return;
}


// SpectToggleButton::paintBackground  @ 0009c640  (line 1381)

/* DWARF original prototype: void paintBackground(SpectToggleButton * this) */

void __thiscall SpectToggleButton::paintBackground(SpectToggleButton *this)

{
  char cVar1;
  
  cVar1 = (**(code **)(*(int *)&this->super_CommandButton + 0x248))(this);
  if (cVar1 != '\0') {
    (**(code **)(*(int *)&this->super_CommandButton + 0x178))(this,0x8f,0x8f,0x36,0x7d);
    (**(code **)(*(int *)&this->super_CommandButton + 0x17c))
              (this,5,0,*(int *)&(this->super_CommandButton).field_0xc + -5,
               *(undefined4 *)&(this->super_CommandButton).field_0x10);
  }
  return;
}


// SpectToggleButton::paint  @ 0009ca00  (line 1390)

/* DWARF original prototype: void paint(SpectToggleButton * this) */

void __thiscall SpectToggleButton::paint(SpectToggleButton *this)

{
  CImageLabel *pCVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*(int *)&this->super_CommandButton + 0x248))(this);
  if (cVar2 == '\0') {
    (**(code **)(*(int *)&this->super_CommandButton + 0x124))(this,0x8f,0x8f,0x36,0xf);
  }
  else {
    (**(code **)(*(int *)&this->super_CommandButton + 0x124))(this,0xc2,0xca,0x36,0);
  }
  if (this->m_cvar == (cvar_s *)0x0) {
    (**(code **)(*(int *)this->pLabelOn + 0x24))(this->pLabelOn,0);
  }
  else {
    pCVar1 = this->pLabelOn;
    if (this->m_cvar->value != 0.0) {
      (**(code **)(*(int *)pCVar1 + 0x24))(pCVar1,1);
      vgui::Label::paint();
      return;
    }
    (**(code **)(*(int *)pCVar1 + 0x24))(pCVar1,0);
  }
  vgui::Label::paint();
  return;
}


// DragNDropPanel::setDragged  @ 0009c230  (line 1515)

/* DWARF original prototype: void setDragged(DragNDropPanel * this, bool bState) */

void __thiscall DragNDropPanel::setDragged(DragNDropPanel *this,bool bState)

{
  this->m_bBeingDragged = bState;
  if (!bState) {
                    /* WARNING: Could not recover jumptable at 0x0009c250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)this + 0xd4))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0009c26a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0xd4))();
  return;
}


// CTransparentPanel::paintBackground  @ 00087c90  (line 1538)

/* DWARF original prototype: void paintBackground(CTransparentPanel * this) */

void __thiscall CTransparentPanel::paintBackground(CTransparentPanel *this)

{
  if (this->m_iTransparency != 0) {
    (**(code **)(*(int *)this + 0x178))(this,0,0,0,this->m_iTransparency);
    (**(code **)(*(int *)this + 0x17c))
              (this,0,0,*(undefined4 *)&this->field_0xc,*(undefined4 *)&this->field_0x10);
  }
  return;
}


// CMenuPanel::Reset  @ 00087cf0  (line 1572)

/* DWARF original prototype: void Reset(CMenuPanel * this) */

void __thiscall CMenuPanel::Reset(CMenuPanel *this)

{
  this->m_pNextMenu = (CMenuPanel *)0x0;
  this->m_iIsActive = 0;
  this->m_flOpenTime = 0.0;
  return;
}


// CMenuPanel::Open  @ 00087d10  (line 1597)

/* DWARF original prototype: void Open(CMenuPanel * this) */

void __thiscall CMenuPanel::Open(CMenuPanel *this)

{
  (**(code **)(*(int *)&this->super_CTransparentPanel + 0x24))(this,1);
  this->m_flOpenTime = gHUD.m_flTime;
  return;
}


// CMenuPanel::Close  @ 00087d40  (line 1605)

/* DWARF original prototype: void Close(CMenuPanel * this) */

void __thiscall CMenuPanel::Close(CMenuPanel *this)

{
  (**(code **)(*(int *)&this->super_CTransparentPanel + 0x24))(this,0);
  this->m_iIsActive = 0;
  if (this->m_iRemoveMe != 0) {
    (**(code **)(*(int *)gViewPort + 0x4c))(gViewPort,this);
  }
  return;
}


// CMenuPanel::SlotInput  @ 00087d80  (line 1623)

/* DWARF original prototype: bool SlotInput(CMenuPanel * this, int iSlot) */

bool __thiscall CMenuPanel::SlotInput(CMenuPanel *this,int iSlot)

{
  return false;
}


// CMenuPanel::SetActiveInfo  @ 00087d90  (line 1624)

/* DWARF original prototype: void SetActiveInfo(CMenuPanel * this, int iInput) */

void __thiscall CMenuPanel::SetActiveInfo(CMenuPanel *this,int iInput)

{
  return;
}


// CClassMenuPanel::Reset  @ 00087da0  (line 1687)

/* DWARF original prototype: void Reset(CClassMenuPanel * this) */

void __thiscall CClassMenuPanel::Reset(CClassMenuPanel *this)

{
  (this->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
  (this->super_CMenuPanel).m_iIsActive = 0;
  (this->super_CMenuPanel).m_flOpenTime = 0.0;
  this->m_iCurrentInfo = 0;
  return;
}


// CTeamMenuPanel::Reset  @ 0009c270  (line 1720)

/* DWARF original prototype: void Reset(CTeamMenuPanel * this) */

void __thiscall CTeamMenuPanel::Reset(CTeamMenuPanel *this)

{
  (this->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
  (this->super_CMenuPanel).m_iIsActive = 0;
  (this->super_CMenuPanel).m_flOpenTime = 0.0;
  this->m_iCurrentInfo = 0;
  return;
}


