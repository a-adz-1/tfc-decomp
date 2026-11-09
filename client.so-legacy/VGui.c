// VGui_GetPanel  @ 000abe00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VGui_GetPanel(void)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000abe05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (*gEngfuncs.VGui_GetPanel)();
  return pvVar1;
}


// VGui_Shutdown  @ 000abf10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Shutdown(void)

{
  TeamFortressViewport *pTVar1;
  int in_stack_ffffffe8;
  
  pTVar1 = gViewPort;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    *(undefined ***)gViewPort = &PTR_setPos_000ead68;
    CSchemeManager::~CSchemeManager(&pTVar1->m_SchemeManager,in_stack_ffffffe8);
    operator_delete(pTVar1);
  }
  gViewPort = (TeamFortressViewport *)0x0;
  return;
}


// VGui_Startup  @ 000abe10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Startup(void)

{
  code *pcVar1;
  int *piVar2;
  BorderLayout *this;
  int wide;
  int tall;
  TeamFortressViewport *this_00;
  
                    /* Unresolved local var: Panel * root@[DW_OP_reg3(EBX)] */
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
    (**(code **)(*(int *)this_00 + 0x40))(this_00,piVar2);
  }
  else {
    TeamFortressViewport::Initialize(gViewPort);
  }
  return;
}


// VGui_ViewportPaintBackground  @ 000abdf0
void VGui_ViewportPaintBackground(int *extents)

{
                    /* WARNING: Could not recover jumptable at 0x000abdf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.VGui_ViewportPaintBackground)(extents);
  return;
}


