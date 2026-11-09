// VGui_CallEngineSurfaceAppHandler  @ 001b6af0
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


// VGui_GameUIKeyPressed  @ 001b6bd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VGui_GameUIKeyPressed(void)

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


// VGui_GetMouse  @ 001b6b60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_GetMouse(void)

{
  VGuiWrap_GetMouse();
  VGuiWrap2_GetMouse();
  return;
}


// VGui_GetPanel  @ 001b6b40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VGui_GetPanel(void)

{
  (*g_engdstAddrs.VGui_GetPanel)();
  return staticPanel;
}


// VGui_Key_Event  @ 001b6be0
int VGui_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_Key_Event(down,keynum,pszCurrentBinding);
  return (uint)(iVar1 != 0);
}


// VGui_LoadBMP  @ 001b6c10
int VGui_LoadBMP(FileHandle_t file,uchar *buffer,int bufsize,int *width,int *height)

{
  uchar *puVar1;
  byte bVar2;
  uchar uVar3;
  int iVar4;
  uint uVar5;
  void *pOutput;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_30;
  short local_2a [5];
  int local_20;
  
                    /* Unresolved local var: int success@[???]
                       Unresolved local var: BITMAPFILEHEADER bmfHeader@[???]
                       Unresolved local var: DWORD dwBitsSize@[???]
                       Unresolved local var: DWORD dwFileSize@[???]
                       Unresolved local var: LPBITMAPINFO lpbmi@[DW_OP_reg7(EDI)] */
  iVar8 = 0;
  uVar5 = FS_Size(file);
  FS_Read(local_2a,0xe,1,file);
  if (local_2a[0] == 0x4d42) {
                    /* Unresolved local var: char * pDIB@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int readWidth@[???]
                       Unresolved local var: uchar * rgba@[???] */
    pOutput = malloc(uVar5 - 0xe);
    FS_Read(pOutput,uVar5 - 0xe,1,file);
    *width = *(int *)((int)pOutput + 4);
    iVar8 = *(int *)((int)pOutput + 8);
    *height = iVar8;
    uVar5 = *width;
    local_30 = uVar5;
    if ((uVar5 & 3) != 0) {
      local_30 = uVar5 + (int)(uVar5 + 4) % 4;
    }
    iVar7 = 0;
    if (0 < iVar8) {
      do {
        if (0 < (int)uVar5) {
          iVar6 = 0;
          while( true ) {
                    /* Unresolved local var: int y@[???]
                       Unresolved local var: int offs@[???]
                       Unresolved local var: int offsdest@[???]
                       Unresolved local var: uchar * src@[???]
                       Unresolved local var: char * dst@[???] */
            puVar1 = buffer + (uVar5 * iVar7 + iVar6) * 4;
            iVar4 = iVar6 + local_20 + -0xe;
            iVar6 = iVar6 + 1;
            puVar1[3] = 0xff;
            bVar2 = *(byte *)((int)pOutput + ((iVar8 - iVar7) + -1) * local_30 + iVar4);
            *puVar1 = *(uchar *)((int)pOutput + (uint)bVar2 * 4 + 0x2a);
            uVar3 = *(uchar *)((int)pOutput + (uint)bVar2 * 4 + 0x28);
            puVar1[1] = *(uchar *)((int)pOutput + (uint)bVar2 * 4 + 0x29);
            puVar1[2] = uVar3;
            uVar5 = *width;
            if ((int)uVar5 <= iVar6) break;
            iVar8 = *height;
          }
          iVar8 = *height;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar8);
    }
    iVar8 = 1;
    free(pOutput);
  }
  FS_Close(file);
  return iVar8;
}


// VGui_Paint  @ 001b6b90
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


// VGui_ReleaseMouse  @ 001b6b50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_ReleaseMouse(void)

{
  VGuiWrap_ReleaseMouse();
  VGuiWrap2_ReleaseMouse();
  return;
}


// VGui_SetVisible  @ 001b6b70
void VGui_SetVisible(int state)

{
  VGuiWrap_SetVisible(state);
  VGuiWrap2_SetVisible(state);
  return;
}


// VGui_Shutdown  @ 001b6ad0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Shutdown(void)

{
  VGuiWrap_Shutdown();
  VGuiWrap2_Shutdown();
  EngineSurface::freeEngineSurface();
  return;
}


// VGui_Startup  @ 001b6ac0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGui_Startup(void)

{
  VGuiWrap_Startup();
  VGuiWrap2_Startup();
  return;
}


// VGui_ViewportPaintBackground  @ 00178c40
void VGui_ViewportPaintBackground(int *extents)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int local_34;
  int local_30 [3];
  undefined4 local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int[4] old@[???]
                       Unresolved local var: POINT pnt@[???]
                       Unresolved local var: RECT rect@[???] */
  (*g_engdstAddrs.VGui_ViewportPaintBackground)(&extents);
  GLFinishHud();
  iVar4 = glwidth;
  iVar3 = glx;
  iVar2 = gly;
  iVar1 = glheight;
  local_34 = 0;
  local_30[0] = 0;
  SDL_GetWindowPosition(*pmainwindow,&local_34,local_30);
  local_30[1] = 0;
  local_24 = 0;
  iVar5 = VideoMode_IsWindowed();
  if (iVar5 == 0) {
    VideoMode_GetCurrentVideoMode(local_30 + 2,local_20,(int *)0x0);
  }
  else {
    SDL_GetWindowSize(*pmainwindow,local_30 + 2,local_20);
  }
  glx = *extents - local_34;
  gly = glheight - (extents[3] - local_30[0]);
  glwidth = extents[2] - *extents;
  glheight = extents[3] - extents[1];
  SCR_CalcRefdef();
  V_RenderView();
  GLBeginHud();
  if ((cls.state == ca_active) && (cls.signon == 2)) {
                    /* Unresolved local var: bool bState@[???] */
    bVar6 = cl.intermission == 1;
    AllowFog(0);
    ClientDLL_HudRedraw((uint)bVar6);
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
  glheight = iVar1;
  gly = iVar2;
  glx = iVar3;
  glwidth = iVar4;
  SCR_CalcRefdef();
  GLBeginHud();
  return;
}


