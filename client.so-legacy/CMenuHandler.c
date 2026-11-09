// CMenuHandler_PopupSubMenuInput::cursorEntered  @ 000c1a20
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
                    /* WARNING: Could not recover jumptable at 0x000c1aae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)this->m_pButton + 0x234))();
    return;
  }
  return;
}


// CMenuHandler_PopupSubMenuInput::cursorExited  @ 000c0ff0
/* DWARF original prototype: void cursorExited(CMenuHandler_PopupSubMenuInput * this, Panel * Panel)
    */

void __thiscall
CMenuHandler_PopupSubMenuInput::cursorExited(CMenuHandler_PopupSubMenuInput *this,Panel *Panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::cursorMoved  @ 000c0fe0
/* DWARF original prototype: void cursorMoved(CMenuHandler_PopupSubMenuInput * this, int x, int y,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::cursorMoved
          (CMenuHandler_PopupSubMenuInput *this,int x,int y,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyFocusTicked  @ 000c1070
/* DWARF original prototype: void keyFocusTicked(CMenuHandler_PopupSubMenuInput * this, Panel *
   panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyFocusTicked(CMenuHandler_PopupSubMenuInput *this,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyPressed  @ 000c1040
/* DWARF original prototype: void keyPressed(CMenuHandler_PopupSubMenuInput * this, KeyCode code,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyPressed
          (CMenuHandler_PopupSubMenuInput *this,KeyCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyReleased  @ 000c1060
/* DWARF original prototype: void keyReleased(CMenuHandler_PopupSubMenuInput * this, KeyCode code,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyReleased
          (CMenuHandler_PopupSubMenuInput *this,KeyCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::keyTyped  @ 000c1050
/* DWARF original prototype: void keyTyped(CMenuHandler_PopupSubMenuInput * this, KeyCode code,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::keyTyped
          (CMenuHandler_PopupSubMenuInput *this,KeyCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mouseDoublePressed  @ 000c1010
/* DWARF original prototype: void mouseDoublePressed(CMenuHandler_PopupSubMenuInput * this,
   MouseCode code, Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mouseDoublePressed
          (CMenuHandler_PopupSubMenuInput *this,MouseCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mousePressed  @ 000c1000
/* DWARF original prototype: void mousePressed(CMenuHandler_PopupSubMenuInput * this, MouseCode
   code, Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mousePressed
          (CMenuHandler_PopupSubMenuInput *this,MouseCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mouseReleased  @ 000c1020
/* DWARF original prototype: void mouseReleased(CMenuHandler_PopupSubMenuInput * this, MouseCode
   code, Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mouseReleased
          (CMenuHandler_PopupSubMenuInput *this,MouseCode code,Panel *panel)

{
  return;
}


// CMenuHandler_PopupSubMenuInput::mouseWheeled  @ 000c1030
/* DWARF original prototype: void mouseWheeled(CMenuHandler_PopupSubMenuInput * this, int delta,
   Panel * panel) */

void __thiscall
CMenuHandler_PopupSubMenuInput::mouseWheeled
          (CMenuHandler_PopupSubMenuInput *this,int delta,Panel *panel)

{
  return;
}


// CMenuHandler_SpectateFollow::actionPerformed  @ 000c1b00
/* DWARF original prototype: void actionPerformed(CMenuHandler_SpectateFollow * this, Panel * panel)
    */

void __thiscall
CMenuHandler_SpectateFollow::actionPerformed(CMenuHandler_SpectateFollow *this,Panel *panel)

{
  CHudSpectator::FindPlayer(&gHUD.m_Spectator,this->m_szplayer);
  if (gViewPort->m_iInitialized != 0) {
    TeamFortressViewport::HideCommandMenu((TeamFortressViewport *)this);
    return;
  }
  return;
}


// CMenuHandler_StringCommand::CMenuHandler_StringCommand  @ 000c1ac0
/* DWARF original prototype: void CMenuHandler_StringCommand(CMenuHandler_StringCommand * this, char
   * pszCommand) */

void __thiscall
CMenuHandler_StringCommand::CMenuHandler_StringCommand
          (CMenuHandler_StringCommand *this,char *pszCommand)

{
  (this->super_ActionSignal)._vptr_ActionSignal =
       (_func_int_varargs **)&PTR_actionPerformed_000e7170;
  strncpy(this->m_pszCommand,pszCommand,0x100);
  this->m_pszCommand[0xff] = '\0';
  this->m_iCloseVGUIMenu = 0;
  return;
}


// CMenuHandler_StringCommand::actionPerformed  @ 000ada00
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


// CMenuHandler_StringCommandClassSelect::actionPerformed  @ 000af710
/* DWARF original prototype: void actionPerformed(CMenuHandler_StringCommandClassSelect * this,
   Panel * panel) */

void __thiscall
CMenuHandler_StringCommandClassSelect::actionPerformed
          (CMenuHandler_StringCommandClassSelect *this,Panel *panel)

{
  (*gEngfuncs.pfnClientCmd)((this->super_CMenuHandler_StringCommand).m_pszCommand);
  if ((this->super_CMenuHandler_StringCommand).m_iCloseVGUIMenu == 0) {
    TeamFortressViewport::HideCommandMenu(gViewPort);
    return;
  }
  TeamFortressViewport::HideTopMenu(gViewPort);
  return;
}


// CMenuHandler_StringCommandWatch::actionPerformed  @ 000b6b30
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


// CMenuHandler_TextWindow::actionPerformed  @ 000ada40
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


// CMenuHandler_ToggleCvar::actionPerformed  @ 000c1b40
/* DWARF original prototype: void actionPerformed(CMenuHandler_ToggleCvar * this, Panel * panel) */

void __thiscall CMenuHandler_ToggleCvar::actionPerformed(CMenuHandler_ToggleCvar *this,Panel *panel)

{
  float fVar1;
  TeamFortressViewport *in_stack_fffffff4;
  
  if (this->m_cvar->value == 0.0) {
    fVar1 = 1.0;
  }
  else {
    fVar1 = 0.0;
  }
  this->m_cvar->value = fVar1;
  if (gViewPort->m_iInitialized != 0) {
    TeamFortressViewport::HideCommandMenu(in_stack_fffffff4);
  }
  TeamFortressViewport::UpdateSpectatorPanel(gViewPort);
  return;
}


