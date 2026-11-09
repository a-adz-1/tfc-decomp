// VGuiWrap_CallEngineSurfaceAppHandler  @ 001a49d0
int VGuiWrap_CallEngineSurfaceAppHandler(void *event,void *userData)

{
  if (staticEngineSurface != (EngineSurfaceWrap *)0x0) {
    (**(code **)(*(int *)staticEngineSurface + 0x8c))(staticEngineSurface,event,userData);
    return 0;
  }
  return 0;
}


// VGuiWrap_GetMouse  @ 001a4ac0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap_GetMouse(void)

{
  int iVar1;
  
  if (staticEngineSurface != (EngineSurfaceWrap *)0x0) {
    iVar1 = VGuiWrap2_UseVGUI1();
    if (iVar1 != 0) {
      (**(code **)(*(int *)staticEngineSurface + 0x94))(staticEngineSurface);
    }
    ClientDLL_ActivateMouse();
    SetMouseEnable(true);
  }
  return;
}


// VGuiWrap_GetPanel  @ 001a4a10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VGuiWrap_GetPanel(void)

{
  (*g_engdstAddrs.VGui_GetPanel)();
  return staticPanel;
}


// VGuiWrap_Paint  @ 001a4b60
void VGuiWrap_Paint(int paintAll)

{
  Panel *pPVar1;
  int *piVar2;
  int local_1c;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [8];
  
                    /* Unresolved local var: Panel * panel@[???] */
  (*g_engdstAddrs.VGui_GetPanel)();
  pPVar1 = staticPanel;
  if (staticPanel != (Panel *)0x0) {
    VGuiWrap_SetRootPanelSize();
    (**(code **)(*(int *)pPVar1 + 0x30))(pPVar1);
    piVar2 = (int *)vgui::App::getInstance();
    (**(code **)(*piVar2 + 8))(piVar2);
    if (paintAll != 0) {
      (**(code **)(*(int *)pPVar1 + 0x164))(pPVar1);
      return;
    }
                    /* Unresolved local var: int[4] extents@[???] */
    (**(code **)(*(int *)pPVar1 + 0x38))(pPVar1,&local_1c,local_18,local_14,local_10);
    VGui_ViewportPaintBackground(&local_1c);
  }
  return;
}


// VGuiWrap_ReleaseMouse  @ 001a4a30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap_ReleaseMouse(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar2 = vgui::App::getInstance();
  if ((iVar2 != 0) && (staticEngineSurface != (EngineSurfaceWrap *)0x0)) {
    iVar2 = VGuiWrap2_UseVGUI1();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*(int *)staticEngineSurface + 0x78);
      piVar3 = (int *)vgui::App::getInstance();
      piVar3 = (int *)(**(code **)(*piVar3 + 0x54))(piVar3);
      uVar4 = (**(code **)(*piVar3 + 0x14))(piVar3,2);
      (*pcVar1)(staticEngineSurface,uVar4);
      (**(code **)(*(int *)staticEngineSurface + 0x90))(staticEngineSurface);
    }
    ClientDLL_DeactivateMouse();
    SetMouseEnable(false);
  }
  return;
}


// VGuiWrap_SetRootPanelSize  @ 001a48b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap_SetRootPanelSize(void)

{
  Panel *pPVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [3];
  
                    /* Unresolved local var: Panel * panel@[???]
                       Unresolved local var: POINT pnt@[???]
                       Unresolved local var: RECT rect@[???] */
  (*g_engdstAddrs.VGui_GetPanel)();
  pPVar1 = staticPanel;
  if (staticPanel != (Panel *)0x0) {
    local_24 = 0;
    local_20 = 0;
    SDL_GetWindowPosition(*pmainwindow,&local_24,&local_20);
    local_1c = 0;
    local_14 = 0;
    iVar2 = VideoMode_IsWindowed();
    if (iVar2 == 0) {
      VideoMode_GetCurrentVideoMode(&local_18,local_10,(int *)0x0);
    }
    else {
      SDL_GetWindowSize(*pmainwindow,&local_18,local_10);
    }
    local_18 = local_1c + local_18;
    local_10[0] = local_14 + local_10[0];
    (**(code **)(*(int *)pPVar1 + 0x10))(pPVar1,local_24,local_20,local_18,local_10[0]);
  }
  return;
}


// VGuiWrap_SetVisible  @ 001a4b10
void VGuiWrap_SetVisible(int state)

{
  if (staticPanel != (Panel *)0x0) {
    if (state == 0) {
      (**(code **)(*(int *)staticPanel + 0x24))(staticPanel,0);
    }
    else {
      (**(code **)(*(int *)staticPanel + 0x24))(staticPanel,1);
    }
  }
  return;
}


// VGuiWrap_Shutdown  @ 001a4990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap_Shutdown(void)

{
  EngineSurfaceWrap *pEVar1;
  int in_stack_ffffffe8;
  
  operator_delete(staticPanel);
  pEVar1 = staticEngineSurface;
  staticPanel = (Panel *)0x0;
  if (staticEngineSurface != (EngineSurfaceWrap *)0x0) {
    EngineSurfaceWrap::~EngineSurfaceWrap(staticEngineSurface,in_stack_ffffffe8);
    operator_delete(pEVar1);
  }
  staticEngineSurface = (EngineSurfaceWrap *)0x0;
  return;
}


// VGuiWrap_Startup  @ 001a4be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap_Startup(void)

{
  code *pcVar1;
  int *piVar2;
  Panel *this;
  undefined4 uVar3;
  CreateInterfaceFn p_Var4;
  IEngineSurface *engineSurface;
  EngineSurfaceWrap *this_00;
  
                    /* Unresolved local var: CreateInterfaceFn engineFactory@[???] */
  if (staticEngineSurface != (EngineSurfaceWrap *)0x0) {
    return;
  }
  piVar2 = (int *)vgui::App::getInstance();
  (**(code **)(*piVar2 + 0x74))(piVar2);
  this = operator_new(0xbc);
  vgui::Panel::Panel(this,0,0,0x140,0xf0);
  staticPanel = this;
  vgui::Panel::setPaintBorderEnabled(SUB41(this,0));
  (**(code **)(*(int *)staticPanel + 0xdc))(staticPanel,0);
  (**(code **)(*(int *)staticPanel + 0xe0))(staticPanel,0);
  pcVar1 = *(code **)(*(int *)staticPanel + 0x90);
  piVar2 = (int *)vgui::App::getInstance();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x54))(piVar2);
  uVar3 = (**(code **)(*piVar2 + 0x14))(piVar2,1);
  (*pcVar1)(staticPanel,uVar3);
  p_Var4 = Sys_GetFactoryThis();
  engineSurface = (*p_Var4)("EngineSurface007",(int *)0x0);
  this_00 = operator_new(0x30);
  EngineSurfaceWrap::EngineSurfaceWrap(this_00,staticPanel,engineSurface);
  staticEngineSurface = this_00;
  VGuiWrap_SetRootPanelSize();
  return;
}


