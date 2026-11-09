// Ghidra decompilation of functions from cl_dll/vgui_int.cpp
// 4 functions, ordered by original source line

// VGui_ViewportPaintBackground  @ 00086490  (line 71)

void VGui_ViewportPaintBackground(int *extents)

{
                    /* WARNING: Could not recover jumptable at 0x00086490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.VGui_ViewportPaintBackground)(extents);
  return;
}


// VGui_GetPanel  @ 000864a0  (line 76)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VGui_GetPanel(void)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000864a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (*gEngfuncs.VGui_GetPanel)();
  return pvVar1;
}


// VGui_Startup  @ 000864b0  (line 80)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Startup(void)

{
  code *pcVar1;
  int *piVar2;
  BorderLayout *this;
  int wide;
  int tall;
  TeamFortressViewport *this_00;
  
                    /* Unresolved local var: Panel * root@[???] */
  piVar2 = (*gEngfuncs.VGui_GetPanel)();
  (**(code **)(*piVar2 + 0x128))(piVar2,0x80,0x80,0,0);
  pcVar1 = *(code **)(*piVar2 + 0xb4);
  this = operator_new(8);
  vgui::BorderLayout::BorderLayout(this,0);
  (*pcVar1)(piVar2,this);
  if (gViewPort == (TeamFortressViewport *)0x0) {
    wide = (**(code **)(*piVar2 + 0x18))(piVar2);
    tall = (**(code **)(*piVar2 + 0x1c))(piVar2);
    this_00 = TeamFortressViewport::operator_new(0xa5c);
    TeamFortressViewport::TeamFortressViewport(this_00,0,0,wide,tall);
    gViewPort = this_00;
    vgui::Panel::setParent(&this_00->super_Panel);
  }
  else {
    TeamFortressViewport::Initialize(gViewPort);
  }
  return;
}


// VGui_Shutdown  @ 000865c0  (line 114)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Shutdown(void)

{
  CSchemeManager *this;
  TeamFortressViewport *pTVar1;
  int in_stack_ffffffe8;
  
  pTVar1 = gViewPort;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    this = &gViewPort->m_SchemeManager;
    *(undefined ***)gViewPort = &PTR_setPos_000c9af8;
    CSchemeManager::~CSchemeManager(this,in_stack_ffffffe8);
    operator_delete(pTVar1);
  }
  gViewPort = (TeamFortressViewport *)0x0;
  return;
}


