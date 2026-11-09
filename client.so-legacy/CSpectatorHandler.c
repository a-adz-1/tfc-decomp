// CSpectatorHandler_Command::actionPerformed  @ 000c47a0
/* DWARF original prototype: void actionPerformed(CSpectatorHandler_Command * this, Panel * panel)
    */

void __thiscall
CSpectatorHandler_Command::actionPerformed(CSpectatorHandler_Command *this,Panel *panel)

{
  SpectatorPanel::ActionSignal(this->m_pFather,this->m_cmd);
  return;
}


