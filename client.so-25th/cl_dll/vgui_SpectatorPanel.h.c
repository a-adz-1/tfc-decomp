// Ghidra decompilation of functions from cl_dll/vgui_SpectatorPanel.h
// 1 functions, ordered by original source line

// CSpectatorHandler_Command::actionPerformed  @ 000a0120  (line 105)

/* DWARF original prototype: void actionPerformed(CSpectatorHandler_Command * this, Panel * panel)
    */

void __thiscall
CSpectatorHandler_Command::actionPerformed(CSpectatorHandler_Command *this,Panel *panel)

{
  int iNewInsetMode;
  
  switch(this->m_cmd) {
  case 0:
    goto switchD_000a0133_caseD_0;
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
    SpectatorPanel::ShowMenu(this->m_pFather,false);
    return;
  case 5:
    iNewInsetMode = CHudSpectator::ToggleInset(&gHUD.m_Spectator,false);
    CHudSpectator::SetModes(&gHUD.m_Spectator,-1,iNewInsetMode);
switchD_000a0133_caseD_0:
    return;
  case 6:
    TeamFortressViewport::ShowCommandMenu(gViewPort,gViewPort->m_SpectatorCameraMenu);
    return;
  case 7:
    TeamFortressViewport::ShowCommandMenu(gViewPort,gViewPort->m_PlayerMenu);
    return;
  default:
                    /* WARNING: Could not recover jumptable at 0x000a0238. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEngfuncs.Con_DPrintf)("Unknown SpectatorPanel ActionSingal %i.\n");
    return;
  }
}


