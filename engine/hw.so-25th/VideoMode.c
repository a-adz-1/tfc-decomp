// VideoMode_Create  @ 001c4860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VideoMode_Create(void)

{
  int iVar1;
  int iVar2;
  IVideoMode *pIVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_20 [4];
  _func_int_varargs **local_1c;
  _func_int_varargs **local_18;
  
                    /* Unresolved local var: bool windowed@[???]
                       Unresolved local var: bool d3d@[???] */
  iVar1 = (*registry->_vptr_IRegistry[2])(registry,"ScreenWindowed",0);
  iVar2 = COM_CheckParm("-sw");
  if (iVar2 == 0) {
    iVar2 = COM_CheckParm("-startwindowed");
    if (iVar2 == 0) {
      iVar2 = COM_CheckParm("-windowed");
      if (iVar2 == 0) {
        iVar2 = COM_CheckParm("-window");
        if (iVar2 == 0) {
          iVar2 = COM_CheckParm("-full");
          if (iVar2 == 0) {
            iVar2 = COM_CheckParm("-fullscreen");
            if (iVar2 == 0) {
              bVar5 = iVar1 != 0;
              uVar4 = (uint)bVar5;
              goto LAB_001c489e;
            }
          }
          bVar5 = false;
          uVar4 = 0;
          goto LAB_001c489e;
        }
      }
    }
  }
  uVar4 = 1;
  bVar5 = true;
LAB_001c489e:
  (*registry->_vptr_IRegistry[3])(registry,"ScreenWindowed",uVar4);
  (*registry->_vptr_IRegistry[2])(registry,"EngineD3D",0);
  iVar1 = COM_CheckParm("-d3d");
  if (iVar1 == 0) {
    COM_CheckParm("-gl");
  }
  pIVar3 = operator_new(0x1bc);
  pIVar3->_vptr_IVideoMode = (_func_int_varargs **)&PTR___cxa_pure_virtual_002700b8;
  pIVar3[0x67]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  pIVar3[0x68]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  pIVar3[0x69]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  pIVar3[0x6a]._vptr_IVideoMode = (_func_int_varargs **)0x0;
                    /* Unresolved local var: SDL_DisplayMode.conflict mode@[???] */
  pIVar3[100]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  pIVar3[0x65]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  *(undefined1 *)&pIVar3[0x6e]._vptr_IVideoMode = 0;
  *(undefined1 *)&pIVar3[0x66]._vptr_IVideoMode = 0;
  SDL_GetDesktopDisplayMode(0,local_20);
  pIVar3->_vptr_IVideoMode = (_func_int_varargs **)&PTR_GetName_00270110;
  *(bool *)&pIVar3[0x6e]._vptr_IVideoMode = bVar5;
  videomode = pIVar3;
  pIVar3[0x61]._vptr_IVideoMode = local_1c;
  pIVar3[0x62]._vptr_IVideoMode = local_18;
  pIVar3[99]._vptr_IVideoMode = (_func_int_varargs **)0x20;
  return;
}


// VideoMode_GetCurrentRenderer  @ 001c4580
void VideoMode_GetCurrentRenderer
               (char *name,int namelen,int *windowed,int *hdmodels,int *addons_folder)

{
  uint uVar1;
  int iVar2;
  char *__src;
  
  if ((name != (char *)0x0) && (0 < namelen)) {
    __src = "gl";
    if (*videomode->_vptr_IVideoMode != CVideoMode_OpenGL::GetName) {
      __src = (char *)(**videomode->_vptr_IVideoMode)(videomode);
    }
    strncpy(name,__src,namelen);
  }
  if (windowed != (int *)0x0) {
    if (videomode->_vptr_IVideoMode[8] == CVideoMode_Common::IsWindowedMode) {
      uVar1 = (uint)*(byte *)&videomode[0x6e]._vptr_IVideoMode;
    }
    else {
      uVar1 = (*videomode->_vptr_IVideoMode[8])(videomode);
    }
    *windowed = uVar1 & 0xff;
  }
  if (hdmodels != (int *)0x0) {
    iVar2 = (*registry->_vptr_IRegistry[2])(registry,0x2577b6,0);
    *hdmodels = (uint)(0 < iVar2);
  }
  if (addons_folder != (int *)0x0) {
    iVar2 = (*registry->_vptr_IRegistry[2])(registry,0x258ec0,0);
    *addons_folder = (uint)(0 < iVar2);
  }
  return;
}


// VideoMode_GetCurrentVideoMode  @ 001c44d0
void VideoMode_GetCurrentVideoMode(int *wide,int *tall,int *bpp)

{
  _func_int_varargs *p_Var1;
  _func_int_varargs **pp_Var2;
  IVideoMode *pIVar3;
  
                    /* Unresolved local var: vmode_t * mode@[???] */
  p_Var1 = videomode->_vptr_IVideoMode[5];
  if (p_Var1 == CVideoMode_Common::GetCurrentMode) {
    p_Var1 = videomode->_vptr_IVideoMode[6];
    pp_Var2 = videomode[0x65]._vptr_IVideoMode;
    if (p_Var1 == CVideoMode_Common::GetMode) {
      if (((int)videomode[100]._vptr_IVideoMode <= (int)pp_Var2) ||
         (pIVar3 = videomode + (int)pp_Var2 * 3 + 1, (int)pp_Var2 < 0)) {
        pIVar3 = videomode + 0x61;
      }
    }
    else {
      pIVar3 = (IVideoMode *)(*p_Var1)(videomode,pp_Var2);
    }
  }
  else {
    pIVar3 = (IVideoMode *)(*p_Var1)(videomode);
  }
  if (pIVar3 != (IVideoMode *)0x0) {
    if (wide != (int *)0x0) {
      *wide = (int)pIVar3->_vptr_IVideoMode;
    }
    if (tall != (int *)0x0) {
      *tall = (int)pIVar3[1]._vptr_IVideoMode;
    }
    if (bpp != (int *)0x0) {
      *bpp = (int)pIVar3[2]._vptr_IVideoMode;
    }
  }
  return;
}


// VideoMode_GetVideoModes  @ 001c4450
void VideoMode_GetVideoModes(vmode_s **liststart,int *count)

{
  _func_int_varargs **pp_Var1;
  vmode_s *pvVar2;
  
  if (videomode->_vptr_IVideoMode[7] == CVideoMode_Common::GetModeCount) {
    pp_Var1 = videomode[100]._vptr_IVideoMode;
  }
  else {
    pp_Var1 = (_func_int_varargs **)(*videomode->_vptr_IVideoMode[7])(videomode);
  }
  *count = (int)pp_Var1;
  if (videomode->_vptr_IVideoMode[6] == CVideoMode_Common::GetMode) {
    pvVar2 = (vmode_s *)(videomode + 1);
    if ((int)videomode[100]._vptr_IVideoMode < 1) {
      pvVar2 = (vmode_s *)(videomode + 0x61);
    }
    *liststart = pvVar2;
    return;
  }
  pvVar2 = (vmode_s *)(*videomode->_vptr_IVideoMode[6])(videomode,0);
  *liststart = pvVar2;
  return;
}


// VideoMode_IsWindowed  @ 001c46a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VideoMode_IsWindowed(void)

{
  uint uVar1;
  
  if (videomode == (IVideoMode *)0x0) {
    return 0;
  }
  if (videomode->_vptr_IVideoMode[8] == CVideoMode_Common::IsWindowedMode) {
    return (uint)*(byte *)&videomode[0x6e]._vptr_IVideoMode;
  }
  uVar1 = (*videomode->_vptr_IVideoMode[8])(videomode);
  return uVar1 & 0xff;
}


// VideoMode_RestoreVideo  @ 001c46e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VideoMode_RestoreVideo(void)

{
  (*videomode->_vptr_IVideoMode[0xd])(videomode);
  return;
}


// VideoMode_SetVideoMode  @ 001c43e0
void VideoMode_SetVideoMode(int width,int height,int bpp)

{
  (*registry->_vptr_IRegistry[3])(registry,"DisplayWidth",width);
  (*registry->_vptr_IRegistry[3])(registry,"DisplayHeight",height);
                    /* WARNING: Could not recover jumptable at 0x001c4445. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*registry->_vptr_IRegistry[3])();
  return;
}


// VideoMode_SwitchMode  @ 001c4330
void VideoMode_SwitchMode(int hardware,int windowed)

{
  if (hardware == 0) {
    (*registry->_vptr_IRegistry[5])(registry,"EngineDLL","sw.so");
    (*registry->_vptr_IRegistry[3])(registry,"EngineD3D",0);
  }
  else {
    (*registry->_vptr_IRegistry[5])(registry,"EngineDLL","hw.so");
    (*registry->_vptr_IRegistry[3])(registry,"EngineD3D",(uint)(hardware == 2));
  }
  (*registry->_vptr_IRegistry[3])(registry,"ScreenWindowed",windowed);
  return;
}


