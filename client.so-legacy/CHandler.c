// CHandler_ButtonHighlight::cursorEntered  @ 000b0db0
/* DWARF original prototype: void cursorEntered(CHandler_ButtonHighlight * this, Panel * panel) */

void __thiscall CHandler_ButtonHighlight::cursorEntered(CHandler_ButtonHighlight *this,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000b0dcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->m_pButton + 0x234))();
  return;
}


// CHandler_ButtonHighlight::cursorExited  @ 000b0dd0
/* DWARF original prototype: void cursorExited(CHandler_ButtonHighlight * this, Panel * Panel) */

void __thiscall CHandler_ButtonHighlight::cursorExited(CHandler_ButtonHighlight *this,Panel *Panel)

{
                    /* WARNING: Could not recover jumptable at 0x000b0de9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->m_pButton + 0x234))();
  return;
}


// CHandler_ButtonHighlight::cursorMoved  @ 000b0e10
/* DWARF original prototype: void cursorMoved(CHandler_ButtonHighlight * this, int x, int y, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::cursorMoved(CHandler_ButtonHighlight *this,int x,int y,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyFocusTicked  @ 000b0e70
/* DWARF original prototype: void keyFocusTicked(CHandler_ButtonHighlight * this, Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::keyFocusTicked(CHandler_ButtonHighlight *this,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyPressed  @ 000b0e40
/* DWARF original prototype: void keyPressed(CHandler_ButtonHighlight * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::keyPressed(CHandler_ButtonHighlight *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyReleased  @ 000b0e60
/* DWARF original prototype: void keyReleased(CHandler_ButtonHighlight * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::keyReleased(CHandler_ButtonHighlight *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::keyTyped  @ 000b0e50
/* DWARF original prototype: void keyTyped(CHandler_ButtonHighlight * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::keyTyped(CHandler_ButtonHighlight *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::mouseDoublePressed  @ 000b0e20
/* DWARF original prototype: void mouseDoublePressed(CHandler_ButtonHighlight * this, MouseCode
   code, Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::mouseDoublePressed
          (CHandler_ButtonHighlight *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::mousePressed  @ 000b0df0
/* DWARF original prototype: void mousePressed(CHandler_ButtonHighlight * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::mousePressed(CHandler_ButtonHighlight *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::mouseReleased  @ 000b0e00
/* DWARF original prototype: void mouseReleased(CHandler_ButtonHighlight * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_ButtonHighlight::mouseReleased(CHandler_ButtonHighlight *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_ButtonHighlight::mouseWheeled  @ 000b0e30
/* DWARF original prototype: void mouseWheeled(CHandler_ButtonHighlight * this, int delta, Panel *
   panel) */

void __thiscall
CHandler_ButtonHighlight::mouseWheeled(CHandler_ButtonHighlight *this,int delta,Panel *panel)

{
  return;
}


// CHandler_CommandButtonHighlight::cursorEntered  @ 000b0ec0
/* DWARF original prototype: void cursorEntered(CHandler_CommandButtonHighlight * this, Panel *
   panel) */

void __thiscall
CHandler_CommandButtonHighlight::cursorEntered(CHandler_CommandButtonHighlight *this,Panel *panel)

{
  CommandButton *pCVar1;
  CCommandMenu *this_00;
  CommandButton *this_01;
  
  pCVar1 = this->m_pCommandButton;
                    /* Unresolved local var: CCommandMenu * containingMenu@[DW_OP_reg6(ESI)] */
  this_00 = pCVar1->m_pParentMenu;
  if (this_00 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[DW_OP_reg0(EAX)] */
    CCommandMenu::ClearButtonsOfArmedState(this_00);
    if (this_00->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
      this_01 = CCommandMenu::FindButtonWithSubmenu(this_00->m_pParentMenu,this_00);
      CommandButton::cursorEntered(this_01);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000b0f22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pCVar1 + 0x234))();
  return;
}


// CHandler_CommandButtonHighlight::cursorExited  @ 000b0e80
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
                    /* WARNING: Could not recover jumptable at 0x000b0eb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pCVar1 + 0x234))();
  return;
}


// CHandler_MenuButtonOver::cursorEntered  @ 000af3c0
/* DWARF original prototype: void cursorEntered(CHandler_MenuButtonOver * this, Panel * panel) */

void __thiscall CHandler_MenuButtonOver::cursorEntered(CHandler_MenuButtonOver *this,Panel *panel)

{
  if ((gViewPort != (TeamFortressViewport *)0x0) && (this->m_pMenuPanel != (CMenuPanel *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000af3e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)&this->m_pMenuPanel->super_CTransparentPanel + 0x20c))();
    return;
  }
  return;
}


// CHandler_MenuButtonOver::cursorExited  @ 000b0d50
/* DWARF original prototype: void cursorExited(CHandler_MenuButtonOver * this, Panel * panel) */

void __thiscall CHandler_MenuButtonOver::cursorExited(CHandler_MenuButtonOver *this,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::cursorMoved  @ 000b0d10
/* DWARF original prototype: void cursorMoved(CHandler_MenuButtonOver * this, int x, int y, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::cursorMoved(CHandler_MenuButtonOver *this,int x,int y,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyFocusTicked  @ 000b0da0
/* DWARF original prototype: void keyFocusTicked(CHandler_MenuButtonOver * this, Panel * panel) */

void __thiscall CHandler_MenuButtonOver::keyFocusTicked(CHandler_MenuButtonOver *this,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyPressed  @ 000b0d70
/* DWARF original prototype: void keyPressed(CHandler_MenuButtonOver * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::keyPressed(CHandler_MenuButtonOver *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyReleased  @ 000b0d90
/* DWARF original prototype: void keyReleased(CHandler_MenuButtonOver * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::keyReleased(CHandler_MenuButtonOver *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::keyTyped  @ 000b0d80
/* DWARF original prototype: void keyTyped(CHandler_MenuButtonOver * this, KeyCode code, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::keyTyped(CHandler_MenuButtonOver *this,KeyCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mouseDoublePressed  @ 000b0d40
/* DWARF original prototype: void mouseDoublePressed(CHandler_MenuButtonOver * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_MenuButtonOver::mouseDoublePressed
          (CHandler_MenuButtonOver *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mousePressed  @ 000b0d20
/* DWARF original prototype: void mousePressed(CHandler_MenuButtonOver * this, MouseCode code, Panel
   * panel) */

void __thiscall
CHandler_MenuButtonOver::mousePressed(CHandler_MenuButtonOver *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mouseReleased  @ 000b0d30
/* DWARF original prototype: void mouseReleased(CHandler_MenuButtonOver * this, MouseCode code,
   Panel * panel) */

void __thiscall
CHandler_MenuButtonOver::mouseReleased(CHandler_MenuButtonOver *this,MouseCode code,Panel *panel)

{
  return;
}


// CHandler_MenuButtonOver::mouseWheeled  @ 000b0d60
/* DWARF original prototype: void mouseWheeled(CHandler_MenuButtonOver * this, int delta, Panel *
   panel) */

void __thiscall
CHandler_MenuButtonOver::mouseWheeled(CHandler_MenuButtonOver *this,int delta,Panel *panel)

{
  return;
}


