// VGuiWrap2_CallEngineSurfaceAppHandler  @ 001f3070
int VGuiWrap2_CallEngineSurfaceAppHandler(void *event,void *userData)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[6])(staticUIFuncs,event,userData);
  }
  return 0;
}


// VGuiWrap2_ClearConsole  @ 001f3420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_ClearConsole(void)

{
  if (staticGameConsole != (IGameConsole *)0x0) {
    (**(code **)(*(int *)staticGameConsole + 0x14))(staticGameConsole);
  }
  return;
}


// VGuiWrap2_ConDPrintf  @ 001f36b0
void VGuiWrap2_ConDPrintf(char *msg)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  size_t sVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  byte bVar9;
  CUtlVector<char> *this;
  int in_stack_ffffffe8;
  
  bVar9 = 0;
  if (staticGameConsole == (IGameConsole *)0x0) {
    this = (CUtlVector<char> *)msg;
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int pos@[DW_OP_reg7(EDI)] */
    uVar4 = strlen(msg);
    iVar7 = g_TempConsoleBuffer.m_Size;
    if (uVar4 != 0) {
      CUtlVector<char>::GrowVector(this,in_stack_ffffffe8);
                    /* Unresolved local var: int numToMove@[???] */
      sVar5 = (g_TempConsoleBuffer.m_Size - iVar7) - uVar4;
      if ((0 < (int)sVar5) && (0 < (int)uVar4)) {
        memmove(g_TempConsoleBuffer.m_Memory.m_pMemory + uVar4 + iVar7,
                g_TempConsoleBuffer.m_Memory.m_pMemory + iVar7,sVar5);
      }
    }
    pcVar8 = g_TempConsoleBuffer.m_Memory.m_pMemory + iVar7;
    if (7 < uVar4) {
      sVar5 = uVar4;
      if (((uint)pcVar8 & 1) != 0) {
        cVar1 = *msg;
        sVar5 = uVar4 - 1;
        msg = msg + 1;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
      }
      if (((uint)pcVar8 & 2) != 0) {
        uVar2 = *(undefined2 *)msg;
        sVar5 = sVar5 - 2;
        msg = msg + 2;
        *(undefined2 *)pcVar8 = uVar2;
        pcVar8 = pcVar8 + 2;
      }
      if (((uint)pcVar8 & 4) != 0) {
        uVar3 = *(undefined4 *)msg;
        sVar5 = sVar5 - 4;
        msg = msg + 4;
        *(undefined4 *)pcVar8 = uVar3;
        pcVar8 = pcVar8 + 4;
      }
      uVar4 = sVar5 & 3;
      for (uVar6 = sVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)msg;
        msg = msg + (uint)bVar9 * -8 + 4;
        pcVar8 = pcVar8 + (uint)bVar9 * -8 + 4;
      }
    }
    iVar7 = 0;
    if ((uVar4 & 4) != 0) {
      *(undefined4 *)pcVar8 = *(undefined4 *)msg;
      iVar7 = 4;
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)(pcVar8 + iVar7) = *(undefined2 *)(msg + iVar7);
      iVar7 = iVar7 + 2;
    }
    if ((uVar4 & 1) != 0) {
      pcVar8[iVar7] = msg[iVar7];
      return;
    }
  }
  else {
    (**(code **)(*(int *)staticGameConsole + 0x20))(staticGameConsole,"%s",msg);
  }
  return;
}


// VGuiWrap2_ConPrintf  @ 001f3440
void VGuiWrap2_ConPrintf(char *msg)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  size_t sVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  byte bVar9;
  CUtlVector<char> *this;
  int in_stack_ffffffe8;
  
  bVar9 = 0;
  if (staticGameConsole == (IGameConsole *)0x0) {
    this = (CUtlVector<char> *)msg;
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int pos@[DW_OP_reg7(EDI)] */
    uVar4 = strlen(msg);
    iVar7 = g_TempConsoleBuffer.m_Size;
    if (uVar4 != 0) {
      CUtlVector<char>::GrowVector(this,in_stack_ffffffe8);
                    /* Unresolved local var: int numToMove@[???] */
      sVar5 = (g_TempConsoleBuffer.m_Size - iVar7) - uVar4;
      if ((0 < (int)sVar5) && (0 < (int)uVar4)) {
        memmove(g_TempConsoleBuffer.m_Memory.m_pMemory + uVar4 + iVar7,
                g_TempConsoleBuffer.m_Memory.m_pMemory + iVar7,sVar5);
      }
    }
    pcVar8 = g_TempConsoleBuffer.m_Memory.m_pMemory + iVar7;
    if (7 < uVar4) {
      sVar5 = uVar4;
      if (((uint)pcVar8 & 1) != 0) {
        cVar1 = *msg;
        sVar5 = uVar4 - 1;
        msg = msg + 1;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
      }
      if (((uint)pcVar8 & 2) != 0) {
        uVar2 = *(undefined2 *)msg;
        sVar5 = sVar5 - 2;
        msg = msg + 2;
        *(undefined2 *)pcVar8 = uVar2;
        pcVar8 = pcVar8 + 2;
      }
      if (((uint)pcVar8 & 4) != 0) {
        uVar3 = *(undefined4 *)msg;
        sVar5 = sVar5 - 4;
        msg = msg + 4;
        *(undefined4 *)pcVar8 = uVar3;
        pcVar8 = pcVar8 + 4;
      }
      uVar4 = sVar5 & 3;
      for (uVar6 = sVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)msg;
        msg = msg + (uint)bVar9 * -8 + 4;
        pcVar8 = pcVar8 + (uint)bVar9 * -8 + 4;
      }
    }
    iVar7 = 0;
    if ((uVar4 & 4) != 0) {
      *(undefined4 *)pcVar8 = *(undefined4 *)msg;
      iVar7 = 4;
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)(pcVar8 + iVar7) = *(undefined2 *)(msg + iVar7);
      iVar7 = iVar7 + 2;
    }
    if ((uVar4 & 1) != 0) {
      pcVar8[iVar7] = msg[iVar7];
      return;
    }
  }
  else {
    (**(code **)(*(int *)staticGameConsole + 0x1c))(staticGameConsole,"%s",msg);
  }
  return;
}


// VGuiWrap2_GameUIKeyPressed  @ 001f3130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_GameUIKeyPressed(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    iVar1 = (**(code **)(*(int *)staticGameUIFuncs + 0x1c))(staticGameUIFuncs);
    if (iVar1 == 0) {
      (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[9])(staticUIFuncs);
      return 1;
    }
    iVar1 = 1;
    if (cl.levelname[0] != '\0') {
      (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[8])(staticUIFuncs);
      return 1;
    }
  }
  return iVar1;
}


// VGuiWrap2_GetLocalizedStringLength  @ 001f3b50
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


// VGuiWrap2_GetMouse  @ 001f3110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_GetMouse(void)

{
  return;
}


// VGuiWrap2_GetPanel  @ 001f30f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VGuiWrap2_GetPanel(void)

{
  return (void *)0x0;
}


// VGuiWrap2_HideConsole  @ 001f3400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_HideConsole(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[10])(staticUIFuncs);
  }
  return;
}


// VGuiWrap2_HideGameUI  @ 001f3360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_HideGameUI(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[8])(staticUIFuncs);
  }
  return;
}


// VGuiWrap2_IsConsoleVisible  @ 001f3380
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_IsConsoleVisible(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (staticGameConsole != (IGameConsole *)0x0) {
    uVar1 = (**(code **)(*(int *)staticGameConsole + 0x18))(staticGameConsole);
    uVar1 = uVar1 & 0xff;
  }
  return uVar1;
}


// VGuiWrap2_IsGameUIVisible  @ 001f30a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_IsGameUIVisible(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    iVar1 = (**(code **)(*(int *)staticGameUIFuncs + 0x1c))(staticGameUIFuncs);
  }
  return iVar1;
}


// VGuiWrap2_IsInCareerMatch  @ 001f3b20
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


// VGuiWrap2_Key_Event  @ 001f31a0
int VGuiWrap2_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 1;
  if (staticUIFuncs != (IBaseUI *)0x0) {
    iVar2 = (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[5])
                      (staticUIFuncs,down,keynum,pszCurrentBinding);
    uVar1 = (uint)(iVar2 == 0);
  }
  return uVar1;
}


// VGuiWrap2_LoadingFinished  @ 001f3840
void VGuiWrap2_LoadingFinished(char *resourceType,char *resourceName)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x38))(staticGameUIFuncs,resourceType,resourceName);
  }
  return;
}


// VGuiWrap2_LoadingStarted  @ 001f3810
void VGuiWrap2_LoadingStarted(char *resourceType,char *resourceName)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x34))(staticGameUIFuncs,resourceType,resourceName);
  }
  return;
}


// VGuiWrap2_NotifyOfServerConnect  @ 001f3a20
void VGuiWrap2_NotifyOfServerConnect(char *game,int IP,int port)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    gfExtendedError = false;
    gszDisconnectReason[0] = '\0';
    gszExtendedDisconnectReason[0] = '\0';
    StopLoadingProgressBar();
    (**(code **)(*(int *)staticGameUIFuncs + 0x24))(staticGameUIFuncs,game,IP,port);
  }
  return;
}


// VGuiWrap2_NotifyOfServerDisconnect  @ 001f3340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_NotifyOfServerDisconnect(void)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x28))(staticGameUIFuncs);
  }
  return;
}


// VGuiWrap2_Paint  @ 001f31e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_Paint(void)

{
  char cVar1;
  int iVar2;
  qboolean qVar3;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10 [3];
  
                    /* Unresolved local var: POINT pnt@[???]
                       Unresolved local var: RECT rect@[???] */
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    local_14 = 0;
    local_10[0] = 0;
    local_1c = 0;
    iVar2 = VideoMode_IsWindowed();
    if (iVar2 == 0) {
      local_10[0] = 0;
      local_14 = 0;
      VideoMode_GetCurrentVideoMode(&local_20,&local_18,(int *)0x0);
    }
    else {
      SDL_GetWindowPosition(*pmainwindow,&local_14,local_10);
      SDL_GetWindowSize(*pmainwindow,&local_20,&local_18);
    }
    local_18 = local_18 + local_1c;
    AllowFog(0);
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[7])
              (staticUIFuncs,local_14,local_10[0],local_20,local_18);
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


// VGuiWrap2_ReleaseMouse  @ 001f3100
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_ReleaseMouse(void)

{
  return;
}


// VGuiWrap2_SetVisible  @ 001f3120
void VGuiWrap2_SetVisible(int state)

{
  return;
}


// VGuiWrap2_ShowConsole  @ 001f33a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_ShowConsole(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[9])(staticUIFuncs);
    if (staticUIFuncs != (IBaseUI *)0x0) {
      (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[0xb])(staticUIFuncs);
    }
  }
  return;
}


// VGuiWrap2_ShowDemoPlayer  @ 001f33d0
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


// VGuiWrap2_Shutdown  @ 001f3050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_Shutdown(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[4])(staticUIFuncs);
    staticUIFuncs = (IBaseUI *)0x0;
  }
  return;
}


// VGuiWrap2_Startup  @ 001f35a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGuiWrap2_Startup(void)

{
  int iVar1;
  CreateInterfaceFn p_Var2;
  CUtlVector<char> *this;
  cl_enginefunc_t *num;
  CreateInterfaceFn local_14;
  CreateInterfaceFn local_10;
  
                    /* Unresolved local var: _func_IBaseInterface_ptr_char_ptr_int_ptr *[2]
                       factories@[???] */
  if (staticUIFuncs == (IBaseUI *)0x0) {
    local_14 = Sys_GetFactoryThis();
    local_10 = g_FileSystemFactory;
    p_Var2 = Sys_GetFactoryThis();
    staticUIFuncs = (IBaseUI *)(*p_Var2)("BaseUI001",(int *)0x0);
    (*((IBaseInterface *)staticUIFuncs)->_vptr_IBaseInterface[2])(staticUIFuncs,&local_14,2);
    num = &cl_enginefuncs;
    this = (CUtlVector<char> *)staticUIFuncs;
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[3])
              (staticUIFuncs,&cl_enginefuncs,7);
    iVar1 = g_TempConsoleBuffer.m_Size;
    CUtlVector<char>::GrowVector(this,(int)num);
                    /* Unresolved local var: int numToMove@[???] */
    if (0 < ~iVar1 + g_TempConsoleBuffer.m_Size) {
      memmove(g_TempConsoleBuffer.m_Memory.m_pMemory + iVar1 + 1,
              g_TempConsoleBuffer.m_Memory.m_pMemory + iVar1,~iVar1 + g_TempConsoleBuffer.m_Size);
    }
    if (g_TempConsoleBuffer.m_Memory.m_pMemory + iVar1 != (char *)0x0) {
      g_TempConsoleBuffer.m_Memory.m_pMemory[iVar1] = '\0';
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
  }
  return;
}


// VGuiWrap2_UseVGUI1  @ 001f30c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGuiWrap2_UseVGUI1(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (staticClient != (IClientVGUI *)0x0) {
    uVar1 = (**(code **)(*(int *)staticClient + 0x14))(staticClient);
    uVar1 = uVar1 & 0xff;
  }
  return uVar1;
}


