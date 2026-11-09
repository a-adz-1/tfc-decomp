// VGui_CallEngineSurfaceAppHandler  @ 002067d0
void VGui_CallEngineSurfaceAppHandler(void *event,void *userData)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_CallEngineSurfaceAppHandler(event,userData);
  if (iVar1 != 0) {
    return;
  }
  VGuiWrap_CallEngineSurfaceAppHandler(event,userData);
  return;
}


// VGui_GameUIKeyPressed  @ 002068b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGui_GameUIKeyPressed(void)

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


// VGui_GetMouse  @ 00206840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_GetMouse(void)

{
  VGuiWrap_GetMouse();
  VGuiWrap2_GetMouse();
  return;
}


// VGui_GetPanel  @ 00206820
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VGui_GetPanel(void)

{
  (*g_engdstAddrs.VGui_GetPanel)();
  return staticPanel;
}


// VGui_Key_Event  @ 002068c0
int VGui_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_Key_Event(down,keynum,pszCurrentBinding);
  return (uint)(iVar1 != 0);
}


// VGui_LoadBMP  @ 002068f0
/* WARNING: Variable defined which should be unmapped: rgba */

int VGui_LoadBMP(FileHandle_t file,uchar *buffer,int bufsize,int *width,int *height)

{
  uchar *puVar1;
  uchar uVar2;
  uint uVar3;
  void *pOutput;
  int iVar4;
  int iVar5;
  int local_34;
  uint local_30;
  short local_2c [5];
  int local_22;
  uchar *rgba;
  
                    /* Unresolved local var: int success@[???]
                       Unresolved local var: BITMAPFILEHEADER bmfHeader@[???]
                       Unresolved local var: DWORD dwBitsSize@[???]
                       Unresolved local var: DWORD dwFileSize@[???]
                       Unresolved local var: LPBITMAPINFO lpbmi@[???] */
  iVar4 = 0;
  uVar3 = FS_Size(file);
  FS_Read(local_2c,0xe,1,file);
  if (local_2c[0] == 0x4d42) {
                    /* Unresolved local var: char * pDIB@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int readWidth@[???] */
    pOutput = malloc(uVar3 - 0xe);
    FS_Read(pOutput,uVar3 - 0xe,1,file);
    *width = *(int *)((int)pOutput + 4);
    iVar4 = *(int *)((int)pOutput + 8);
    *height = iVar4;
    uVar3 = *width;
    local_30 = uVar3;
    if ((uVar3 & 3) != 0) {
      local_30 = (int)(uVar3 + 4) % 4 + uVar3;
    }
    iVar5 = 0;
    if (0 < iVar4) {
      do {
        if (0 < (int)uVar3) {
          local_34 = 0;
          while( true ) {
                    /* Unresolved local var: int y@[???]
                       Unresolved local var: int offs@[???]
                       Unresolved local var: int offsdest@[???]
                       Unresolved local var: uchar * src@[???]
                       Unresolved local var: char * dst@[???] */
            iVar4 = *(byte *)((int)pOutput +
                             ((iVar4 - iVar5) + -1) * local_30 + local_34 + local_22 + -0xe) + 8;
            puVar1 = buffer + (uVar3 * iVar5 + local_34) * 4;
            *puVar1 = *(uchar *)((int)pOutput + iVar4 * 4 + 10);
            puVar1[1] = *(uchar *)((int)pOutput + iVar4 * 4 + 9);
            uVar2 = *(uchar *)((int)pOutput + iVar4 * 4 + 8);
            puVar1[3] = 0xff;
            puVar1[2] = uVar2;
            uVar3 = *width;
            if ((int)uVar3 <= local_34 + 1) break;
            iVar4 = *height;
            local_34 = local_34 + 1;
          }
          iVar4 = *height;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
    }
    iVar4 = 1;
    free(pOutput);
  }
  FS_Close(file);
  return iVar4;
}


// VGui_Paint  @ 00206870
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Paint(void)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_UseVGUI1();
  if (iVar1 == 0) {
    VGuiWrap_Paint(0);
    VGuiWrap2_Paint();
    return;
  }
  iVar1 = VGuiWrap2_IsGameUIVisible();
  VGuiWrap_Paint((uint)(iVar1 == 0));
  VGuiWrap2_Paint();
  return;
}


// VGui_ReleaseMouse  @ 00206830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_ReleaseMouse(void)

{
  VGuiWrap_ReleaseMouse();
  VGuiWrap2_ReleaseMouse();
  return;
}


// VGui_SetVisible  @ 00206850
void VGui_SetVisible(int state)

{
  VGuiWrap_SetVisible(state);
  VGuiWrap2_SetVisible(state);
  return;
}


// VGui_Shutdown  @ 002067b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Shutdown(void)

{
  VGuiWrap_Shutdown();
  VGuiWrap2_Shutdown();
  EngineSurface::freeEngineSurface();
  return;
}


// VGui_Startup  @ 002067a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Startup(void)

{
  VGuiWrap_Startup();
  VGuiWrap2_Startup();
  return;
}


// VGui_ViewportPaintBackground  @ 001cf250
void VGui_ViewportPaintBackground(int *extents)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30 [3];
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int[4] old@[???]
                       Unresolved local var: POINT pnt@[???]
                       Unresolved local var: RECT rect@[???] */
  (*g_engdstAddrs.VGui_ViewportPaintBackground)(&extents);
  GLFinishHud();
  iVar4 = glwidth;
  iVar3 = glx;
  iVar2 = gly;
  iVar1 = SCR_CalcRefdef::h;
  local_24 = 0;
  local_20[0] = 0;
  SDL_GetWindowPosition(*pmainwindow,&local_24,local_20);
  local_30[1] = 0;
  iVar5 = VideoMode_IsWindowed();
  if (iVar5 == 0) {
    VideoMode_GetCurrentVideoMode(local_30,local_30 + 2,(int *)0x0);
  }
  else {
    SDL_GetWindowSize(*pmainwindow,local_30,local_30 + 2);
  }
  glx = *extents - local_24;
  gly = (local_20[0] - extents[3]) + SCR_CalcRefdef::h;
  glwidth = extents[2] - *extents;
  SCR_CalcRefdef::h = extents[3] - extents[1];
  SCR_CalcRefdef();
  V_RenderView();
  GLBeginHud();
  iVar5 = cl.intermission;
  if ((cls.state == ca_active) && (cls.signon == 2)) {
                    /* Unresolved local var: bool bState@[???] */
    AllowFog(0);
    ClientDLL_HudRedraw((uint)(iVar5 == 1));
    AllowFog(1);
  }
  if ((scr_drawloading == false) && ((cl.intermission != 1 || (key_dest != key_game)))) {
    SCR_DrawConsole();
  }
  SCR_DrawLoading();
  if ((cls.state == ca_active) && (cls.signon == 2)) {
    Sbar_Draw();
  }
  GLFinishHud();
  SCR_CalcRefdef::h = iVar1;
  gly = iVar2;
  glx = iVar3;
  glwidth = iVar4;
  SCR_CalcRefdef();
  GLBeginHud();
  return;
}


