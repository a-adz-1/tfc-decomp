// CEngine::TrapMouse_Event  @ 0007f1c0
/* DWARF original prototype: void TrapMouse_Event(CEngine * this, int buttons, bool down) */

void __thiscall CEngine::TrapMouse_Event(CEngine *this,int buttons,bool down)

{
  if ((this->m_bTrapMode != false) && (down < (buttons != 0))) {
    this->m_bTrapMode = false;
    this->m_bDoneTrapping = true;
    this->m_nTrapKey = 0;
    this->m_nTrapButtons = buttons;
  }
  return;
}


