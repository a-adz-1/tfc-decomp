// CEngine::TrapMouse_Event  @ 0014c990
/* DWARF original prototype: void TrapMouse_Event(CEngine * this, int buttons, bool down) */

void __thiscall CEngine::TrapMouse_Event(CEngine *this,int buttons,bool down)

{
  if (((this->m_bTrapMode != false) && (buttons != 0)) && (!down)) {
    this->m_bTrapMode = false;
    this->m_bDoneTrapping = true;
    this->m_nTrapKey = 0;
    this->m_nTrapButtons = buttons;
    return;
  }
  ClientDLL_MouseEvent(buttons);
  return;
}


