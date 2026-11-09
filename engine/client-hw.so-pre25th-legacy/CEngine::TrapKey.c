// CEngine::TrapKey_Event  @ 0014c9d0
/* DWARF original prototype: void TrapKey_Event(CEngine * this, int key, bool down) */

void __thiscall CEngine::TrapKey_Event(CEngine *this,int key,bool down)

{
  qboolean down_00;
  
  down_00 = (qboolean)down;
  if ((this->m_bTrapMode != false) && (down_00 = false, down)) {
    this->m_bTrapMode = false;
    this->m_bDoneTrapping = true;
    this->m_nTrapKey = key;
    this->m_nTrapButtons = 0;
    return;
  }
  Key_Event(key,down_00);
  return;
}


