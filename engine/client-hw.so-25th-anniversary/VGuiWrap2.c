// VGuiWrap2_CallEngineSurfaceAppHandler  @ 001a37e0
int VGuiWrap2_CallEngineSurfaceAppHandler(void *event,void *userData)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[6])(staticUIFuncs,event,userData);
    return 0;
  }
  return 0;
}


// VGuiWrap2_ClearConsole  @ 001a3cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_ClearConsole(void)

{
  if (staticGameConsole != (IGameConsole *)0x0) {
    (**(code **)(*(int *)staticGameConsole + 0x14))(staticGameConsole);
  }
  return;
}


// VGuiWrap2_ConDPrintf  @ 001a4080
void VGuiWrap2_ConDPrintf(char *msg)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  size_t __n;
  char *pcVar8;
  char *pcVar9;
  byte bVar10;
  
  bVar10 = 0;
  if (staticGameConsole != (IGameConsole *)0x0) {
    (**(code **)(*(int *)staticGameConsole + 0x20))(staticGameConsole,0x264d1c,msg);
    return;
  }
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int pos@[???] */
  sVar4 = strlen(msg);
  iVar6 = g_TempConsoleBuffer.m_Size;
  if (sVar4 == 0) goto LAB_001a40e9;
  iVar1 = sVar4 + g_TempConsoleBuffer.m_Size;
  iVar7 = iVar1;
  if (g_TempConsoleBuffer.m_Memory.m_NumAllocated < iVar1) {
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
    iVar5 = iVar1 - g_TempConsoleBuffer.m_Memory.m_NumAllocated;
    if (iVar5 < g_TempConsoleBuffer.m_Memory.m_GrowSize) {
      iVar5 = g_TempConsoleBuffer.m_Memory.m_GrowSize;
      if (((g_TempConsoleBuffer.m_Memory.m_GrowSize < 1) &&
          (g_TempConsoleBuffer.m_Memory.m_GrowSize == 0)) &&
         (iVar5 = 1, g_TempConsoleBuffer.m_Memory.m_NumAllocated != 0)) {
        iVar5 = g_TempConsoleBuffer.m_Memory.m_NumAllocated;
      }
    }
    else {
                    /* Unresolved local var: int growSize@[???] */
      if (g_TempConsoleBuffer.m_Memory.m_GrowSize < 0) goto LAB_001a4191;
    }
                    /* Unresolved local var: int growSize@[???] */
    g_TempConsoleBuffer.m_Memory.m_NumAllocated =
         iVar5 + g_TempConsoleBuffer.m_Memory.m_NumAllocated;
    if (g_TempConsoleBuffer.m_Memory.m_pMemory == (char *)0x0) {
      g_TempConsoleBuffer.m_Memory.m_pMemory = malloc(g_TempConsoleBuffer.m_Memory.m_NumAllocated);
    }
    else {
      g_TempConsoleBuffer.m_Memory.m_pMemory =
           realloc(g_TempConsoleBuffer.m_Memory.m_pMemory,
                   g_TempConsoleBuffer.m_Memory.m_NumAllocated);
      iVar7 = g_TempConsoleBuffer.m_Size + sVar4;
    }
  }
LAB_001a4191:
                    /* Unresolved local var: int numToMove@[???] */
  __n = (iVar7 - iVar6) - sVar4;
  g_TempConsoleBuffer.m_Size = iVar7;
  if ((0 < (int)__n) && (0 < (int)sVar4)) {
    memmove(g_TempConsoleBuffer.m_Memory.m_pMemory + iVar1,
            g_TempConsoleBuffer.m_Memory.m_pMemory + iVar6,__n);
  }
LAB_001a40e9:
  pcVar8 = g_TempConsoleBuffer.m_Memory.m_pMemory + iVar6;
  if (7 < sVar4) {
    pcVar9 = pcVar8;
    if (((uint)pcVar8 & 1) != 0) {
      cVar2 = *msg;
      pcVar9 = pcVar8 + 1;
      msg = msg + 1;
      sVar4 = sVar4 - 1;
      *pcVar8 = cVar2;
    }
    pcVar8 = pcVar9;
    if (((uint)pcVar9 & 2) != 0) {
      uVar3 = *(undefined2 *)msg;
      pcVar8 = pcVar9 + 2;
      msg = msg + 2;
      sVar4 = sVar4 - 2;
      *(undefined2 *)pcVar9 = uVar3;
    }
    if (((uint)pcVar8 & 4) != 0) {
      *(undefined4 *)pcVar8 = *(undefined4 *)msg;
      pcVar9 = msg + 4;
      pcVar8 = pcVar8 + 4;
      for (iVar6 = sVar4 - 4; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pcVar8 = *pcVar9;
        pcVar9 = pcVar9 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      }
      return;
    }
  }
  for (; sVar4 != 0; sVar4 = sVar4 - 1) {
    *pcVar8 = *msg;
    msg = msg + (uint)bVar10 * -2 + 1;
    pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
  }
  return;
}


// VGuiWrap2_ConPrintf  @ 001a3cf0
void VGuiWrap2_ConPrintf(char *msg)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  size_t __n;
  char *pcVar8;
  char *pcVar9;
  byte bVar10;
  
  bVar10 = 0;
  if (staticGameConsole != (IGameConsole *)0x0) {
    (**(code **)(*(int *)staticGameConsole + 0x1c))(staticGameConsole,0x264d1c,msg);
    return;
  }
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int pos@[???] */
  sVar4 = strlen(msg);
  iVar6 = g_TempConsoleBuffer.m_Size;
  if (sVar4 == 0) goto LAB_001a3d59;
  iVar1 = g_TempConsoleBuffer.m_Size + sVar4;
  iVar7 = iVar1;
  if (g_TempConsoleBuffer.m_Memory.m_NumAllocated < iVar1) {
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
    iVar5 = iVar1 - g_TempConsoleBuffer.m_Memory.m_NumAllocated;
    if (iVar5 < g_TempConsoleBuffer.m_Memory.m_GrowSize) {
      iVar5 = g_TempConsoleBuffer.m_Memory.m_GrowSize;
      if (((g_TempConsoleBuffer.m_Memory.m_GrowSize < 1) &&
          (g_TempConsoleBuffer.m_Memory.m_GrowSize == 0)) &&
         (iVar5 = 1, g_TempConsoleBuffer.m_Memory.m_NumAllocated != 0)) {
        iVar5 = g_TempConsoleBuffer.m_Memory.m_NumAllocated;
      }
    }
    else {
                    /* Unresolved local var: int growSize@[???] */
      if (g_TempConsoleBuffer.m_Memory.m_GrowSize < 0) goto LAB_001a3e01;
    }
                    /* Unresolved local var: int growSize@[???] */
    g_TempConsoleBuffer.m_Memory.m_NumAllocated =
         iVar5 + g_TempConsoleBuffer.m_Memory.m_NumAllocated;
    if (g_TempConsoleBuffer.m_Memory.m_pMemory == (char *)0x0) {
      g_TempConsoleBuffer.m_Memory.m_pMemory = malloc(g_TempConsoleBuffer.m_Memory.m_NumAllocated);
    }
    else {
      g_TempConsoleBuffer.m_Memory.m_pMemory =
           realloc(g_TempConsoleBuffer.m_Memory.m_pMemory,
                   g_TempConsoleBuffer.m_Memory.m_NumAllocated);
      iVar7 = g_TempConsoleBuffer.m_Size + sVar4;
    }
  }
LAB_001a3e01:
                    /* Unresolved local var: int numToMove@[???] */
  __n = (iVar7 - iVar6) - sVar4;
  g_TempConsoleBuffer.m_Size = iVar7;
  if ((0 < (int)__n) && (0 < (int)sVar4)) {
    memmove(g_TempConsoleBuffer.m_Memory.m_pMemory + iVar1,
            g_TempConsoleBuffer.m_Memory.m_pMemory + iVar6,__n);
  }
LAB_001a3d59:
  pcVar8 = g_TempConsoleBuffer.m_Memory.m_pMemory + iVar6;
  if (7 < sVar4) {
    pcVar9 = pcVar8;
    if (((uint)pcVar8 & 1) != 0) {
      cVar2 = *msg;
      pcVar9 = pcVar8 + 1;
      msg = msg + 1;
      sVar4 = sVar4 - 1;
      *pcVar8 = cVar2;
    }
    pcVar8 = pcVar9;
    if (((uint)pcVar9 & 2) != 0) {
      uVar3 = *(undefined2 *)msg;
      pcVar8 = pcVar9 + 2;
      msg = msg + 2;
      sVar4 = sVar4 - 2;
      *(undefined2 *)pcVar9 = uVar3;
    }
    if (((uint)pcVar8 & 4) != 0) {
      *(undefined4 *)pcVar8 = *(undefined4 *)msg;
      pcVar9 = msg + 4;
      pcVar8 = pcVar8 + 4;
      for (iVar6 = sVar4 - 4; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pcVar8 = *pcVar9;
        pcVar9 = pcVar9 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      }
      return;
    }
  }
  for (; sVar4 != 0; sVar4 = sVar4 - 1) {
    *pcVar8 = *msg;
    msg = msg + (uint)bVar10 * -2 + 1;
    pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
  }
  return;
}


// VGuiWrap2_GameUIKeyPressed  @ 001a38c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_GameUIKeyPressed(void)

{
  int iVar1;
  
  if (staticGameUIFuncs == (IGameUI *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*(int *)staticGameUIFuncs + 0x1c))(staticGameUIFuncs);
  if (iVar1 != 0) {
    if (cl.levelname[0] == '\0') {
      return 1;
    }
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[8])(staticUIFuncs);
    return 1;
  }
  (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[9])(staticUIFuncs);
  return 1;
}


// VGuiWrap2_GetLocalizedStringLength  @ 001a4530
int VGuiWrap2_GetLocalizedStringLength(char *label)

{
  ILocalize *pIVar1;
  wchar_t *__s;
  size_t sVar2;
  
                    /* Unresolved local var: wchar_t * str@[???] */
  if (label != (char *)0x0) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,label);
    if (__s != (wchar_t *)0x0) {
      sVar2 = wcslen(__s);
      return sVar2;
    }
  }
  return 0;
}


// VGuiWrap2_GetMouse  @ 001a38a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_GetMouse(void)

{
  return;
}


// VGuiWrap2_GetPanel  @ 001a3880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VGuiWrap2_GetPanel(void)

{
  return (void *)0x0;
}


// VGuiWrap2_HideConsole  @ 001a3cb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_HideConsole(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[10])(staticUIFuncs);
  }
  return;
}


// VGuiWrap2_HideGameUI  @ 001a3c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_HideGameUI(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[8])(staticUIFuncs);
  }
  return;
}


// VGuiWrap2_IsConsoleVisible  @ 001a3c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_IsConsoleVisible(void)

{
  uint uVar1;
  
  if (staticGameConsole != (IGameConsole *)0x0) {
    uVar1 = (**(code **)(*(int *)staticGameConsole + 0x18))(staticGameConsole);
    return uVar1 & 0xff;
  }
  return 0;
}


// VGuiWrap2_IsGameUIVisible  @ 001a3820
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_IsGameUIVisible(void)

{
  int iVar1;
  
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    iVar1 = (**(code **)(*(int *)staticGameUIFuncs + 0x1c))(staticGameUIFuncs);
    return iVar1;
  }
  return 0;
}


// VGuiWrap2_IsInCareerMatch  @ 001a4500
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_IsInCareerMatch(void)

{
  CareerStateType CVar1;
  
  CVar1 = CAREER_NONE;
  if (staticCareerUI != (ICareerUI *)0x0) {
    CVar1 = g_careerState;
  }
  return CVar1;
}


// VGuiWrap2_Key_Event  @ 001a3940
int VGuiWrap2_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  int iVar1;
  
  if (staticUIFuncs != (IBaseUI *)0x0) {
    iVar1 = (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[5])
                      (staticUIFuncs,down,keynum,pszCurrentBinding);
    return (uint)(iVar1 == 0);
  }
  return 1;
}


// VGuiWrap2_LoadingFinished  @ 001a4290
void VGuiWrap2_LoadingFinished(char *resourceType,char *resourceName)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x38))(staticGameUIFuncs,resourceType,resourceName);
  }
  return;
}


// VGuiWrap2_LoadingStarted  @ 001a4260
void VGuiWrap2_LoadingStarted(char *resourceType,char *resourceName)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x34))(staticGameUIFuncs,resourceType,resourceName);
  }
  return;
}


// VGuiWrap2_NotifyOfServerConnect  @ 001a3af0
void VGuiWrap2_NotifyOfServerConnect(char *game,int IP,int port)

{
  bool bVar1;
  
  if (staticGameUIFuncs == (IGameUI *)0x0) {
    return;
  }
  gfExtendedError = false;
  gszDisconnectReason[0] = '\0';
  gszExtendedDisconnectReason[0] = '\0';
  if (cls.state == ca_active) {
    if (staticUIFuncs != (IBaseUI *)0x0) {
      (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[8])(staticUIFuncs);
      goto LAB_001a3b51;
    }
    bVar1 = false;
  }
  else {
    if (staticUIFuncs != (IBaseUI *)0x0) {
      if (staticClient != (IClientVGUI *)0x0) {
        (**(code **)(*(int *)staticClient + 0x1c))(staticClient);
      }
      (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[9])(staticUIFuncs);
LAB_001a3b51:
      if (staticGameUIFuncs == (IGameUI *)0x0) goto LAB_001a3b83;
    }
    bVar1 = gfExtendedError != false;
  }
  (**(code **)(*(int *)staticGameUIFuncs + 0x44))
            (staticGameUIFuncs,bVar1,gszDisconnectReason,gszExtendedDisconnectReason);
LAB_001a3b83:
  gfExtendedError = false;
  gszDisconnectReason[0] = '\0';
  gszExtendedDisconnectReason[0] = '\0';
  (**(code **)(*(int *)staticGameUIFuncs + 0x24))(staticGameUIFuncs,game,IP,port);
  return;
}


// VGuiWrap2_NotifyOfServerDisconnect  @ 001a3be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_NotifyOfServerDisconnect(void)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x28))(staticGameUIFuncs);
  }
  return;
}


// VGuiWrap2_Paint  @ 001a3990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_Paint(void)

{
  char cVar1;
  int iVar2;
  qboolean qVar3;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [3];
  
                    /* Unresolved local var: POINT pnt@[???]
                       Unresolved local var: RECT rect@[???] */
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    local_20 = 0;
    local_14 = 0;
    local_24 = 0;
    local_1c = 0;
    iVar2 = VideoMode_IsWindowed();
    if (iVar2 == 0) {
      local_20 = 0;
      local_24 = 0;
      VideoMode_GetCurrentVideoMode(&local_18,local_10,(int *)0x0);
    }
    else {
      SDL_GetWindowPosition(*pmainwindow,&local_24,&local_20);
      SDL_GetWindowSize(*pmainwindow,&local_18,local_10);
    }
    local_18 = local_18 + local_1c;
    local_10[0] = local_10[0] + local_14;
    AllowFog(0);
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[7])
              (staticUIFuncs,local_24,local_20,local_18,local_10[0]);
                    /* Unresolved local var: qboolean excl@[???] */
    if (((staticClient == (IClientVGUI *)0x0) ||
        (cVar1 = (**(code **)(*(int *)staticClient + 0x14))(staticClient),
        qVar3 = staticExclusiveInputShadow, cVar1 != '\0')) &&
       (qVar3 = (**(code **)(*(int *)staticGameUIFuncs + 0x1c))(staticGameUIFuncs),
       qVar3 != staticExclusiveInputShadow)) {
      if (qVar3 == 0) {
        VGuiWrap_GetMouse();
        ClearIOStates();
      }
      else {
        VGuiWrap_ReleaseMouse();
      }
    }
    staticExclusiveInputShadow = qVar3;
    AllowFog(1);
  }
  return;
}


// VGuiWrap2_ReleaseMouse  @ 001a3890
void VGuiWrap2_ReleaseMouse(void)

{
  return;
}


// VGuiWrap2_SetVisible  @ 001a38b0
void VGuiWrap2_SetVisible(int state)

{
  return;
}


// VGuiWrap2_ShowConsole  @ 001a3c50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_ShowConsole(void)

{
  if ((staticUIFuncs != (IBaseUI *)0x0) &&
     ((*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[9])(staticUIFuncs),
     staticUIFuncs != (IBaseUI *)0x0)) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[0xb])(staticUIFuncs);
  }
  return;
}


// VGuiWrap2_ShowDemoPlayer  @ 001a3c80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_ShowDemoPlayer(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[9])(staticUIFuncs);
  }
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x18))(staticGameUIFuncs);
  }
  return;
}


// VGuiWrap2_Shutdown  @ 001a37c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_Shutdown(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[4])(staticUIFuncs);
    staticUIFuncs = (IBaseUI *)0x0;
  }
  return;
}


// VGuiWrap2_Startup  @ 001a3ed0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_Startup(void)

{
  int iVar1;
  int iVar2;
  CreateInterfaceFn p_Var3;
  int iVar4;
  int iVar5;
  size_t __n;
  CreateInterfaceFn local_14;
  CreateInterfaceFn local_10;
  
                    /* Unresolved local var: CreateInterfaceFn[2] factories@[???] */
  if (staticUIFuncs != (IBaseUI *)0x0) {
    return;
  }
  local_14 = Sys_GetFactoryThis();
  local_10 = g_FileSystemFactory;
  p_Var3 = Sys_GetFactoryThis();
  staticUIFuncs = (*p_Var3)("BaseUI001",(int *)0x0);
  (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[2])(staticUIFuncs,&local_14,2);
  (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[3])(staticUIFuncs,&cl_enginefuncs,7);
  iVar2 = g_TempConsoleBuffer.m_Size;
  iVar1 = g_TempConsoleBuffer.m_Size + 1;
  iVar5 = iVar1;
  if (g_TempConsoleBuffer.m_Memory.m_NumAllocated < iVar1) {
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
    if (iVar1 - g_TempConsoleBuffer.m_Memory.m_NumAllocated <
        g_TempConsoleBuffer.m_Memory.m_GrowSize) {
                    /* Unresolved local var: int growSize@[???] */
      iVar4 = g_TempConsoleBuffer.m_Memory.m_GrowSize;
      if (((g_TempConsoleBuffer.m_Memory.m_GrowSize < 1) &&
          (g_TempConsoleBuffer.m_Memory.m_GrowSize == 0)) &&
         (iVar4 = 1, g_TempConsoleBuffer.m_Memory.m_NumAllocated != 0)) {
        iVar4 = g_TempConsoleBuffer.m_Memory.m_NumAllocated;
      }
    }
    else {
      iVar4 = iVar1 - g_TempConsoleBuffer.m_Memory.m_NumAllocated;
      if (g_TempConsoleBuffer.m_Memory.m_GrowSize < 0) goto LAB_001a3fbe;
    }
                    /* Unresolved local var: int growSize@[???] */
    g_TempConsoleBuffer.m_Memory.m_NumAllocated =
         g_TempConsoleBuffer.m_Memory.m_NumAllocated + iVar4;
    if (g_TempConsoleBuffer.m_Memory.m_pMemory == (char *)0x0) {
      g_TempConsoleBuffer.m_Memory.m_pMemory = malloc(g_TempConsoleBuffer.m_Memory.m_NumAllocated);
    }
    else {
      g_TempConsoleBuffer.m_Memory.m_pMemory =
           realloc(g_TempConsoleBuffer.m_Memory.m_pMemory,
                   g_TempConsoleBuffer.m_Memory.m_NumAllocated);
      iVar5 = g_TempConsoleBuffer.m_Size + 1;
    }
  }
LAB_001a3fbe:
                    /* Unresolved local var: int numToMove@[???] */
  __n = (iVar5 - iVar2) - 1;
  g_TempConsoleBuffer.m_Size = iVar5;
  if (0 < (int)__n) {
    memmove(g_TempConsoleBuffer.m_Memory.m_pMemory + iVar1,
            g_TempConsoleBuffer.m_Memory.m_pMemory + iVar2,__n);
  }
  if (g_TempConsoleBuffer.m_Memory.m_pMemory + iVar2 != (char *)0x0) {
    g_TempConsoleBuffer.m_Memory.m_pMemory[iVar2] = '\0';
  }
  VGuiWrap2_ConPrintf(g_TempConsoleBuffer.m_Memory.m_pMemory);
  g_TempConsoleBuffer.m_Size = 0;
  if (-1 < g_TempConsoleBuffer.m_Memory.m_GrowSize) {
    if (g_TempConsoleBuffer.m_Memory.m_pMemory != (char *)0x0) {
      free(g_TempConsoleBuffer.m_Memory.m_pMemory);
      g_TempConsoleBuffer.m_Memory.m_pMemory = (char *)0x0;
    }
    g_TempConsoleBuffer.m_Memory.m_NumAllocated = 0;
  }
  return;
}


// VGuiWrap2_UseVGUI1  @ 001a3850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_UseVGUI1(void)

{
  uint uVar1;
  
  if (staticClient != (IClientVGUI *)0x0) {
    uVar1 = (**(code **)(*(int *)staticClient + 0x14))(staticClient);
    return uVar1 & 0xff;
  }
  return 1;
}


