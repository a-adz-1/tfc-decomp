// CEngine::TrapKey_Event  @ 000ea290
/* DWARF original prototype: void TrapKey_Event(CEngine * this, int key, bool down) */

void __thiscall CEngine::TrapKey_Event(CEngine *this,int key,bool down)

{
  if (this->m_bTrapMode == false) {
    Key_Event(key,(uint)down);
    return;
  }
  if (!down) {
    Key_Event(key,false);
    return;
  }
  this->m_bTrapMode = false;
  this->m_bDoneTrapping = true;
  this->m_nTrapKey = key;
  this->m_nTrapButtons = 0;
  return;
}


