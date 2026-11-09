// VideoMode_Create  @ 002129a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VideoMode_Create(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  _func_int_varargs *p_Var4;
  undefined1 uVar5;
  
                    /* Unresolved local var: bool windowed@[???]
                       Unresolved local var: bool d3d@[???] */
  iVar1 = (*registry->_vptr_IRegistry[2])(registry,"ScreenWindowed",0);
  iVar2 = COM_CheckParm("-sw");
  if ((((iVar2 == 0) && (iVar2 = COM_CheckParm("-startwindowed"), iVar2 == 0)) &&
      (iVar2 = COM_CheckParm("-windowed"), iVar2 == 0)) &&
     (iVar2 = COM_CheckParm("-window"), iVar2 == 0)) {
    iVar2 = COM_CheckParm("-full");
    if ((iVar2 != 0) || (iVar2 = COM_CheckParm("-fullscreen"), iVar2 != 0)) {
      uVar5 = 0;
      uVar3 = 0;
      p_Var4 = registry->_vptr_IRegistry[3];
      goto LAB_002129e7;
    }
    p_Var4 = registry->_vptr_IRegistry[3];
    if (iVar1 == 0) {
      uVar5 = 0;
      uVar3 = 0;
      goto LAB_002129e7;
    }
  }
  else {
    p_Var4 = registry->_vptr_IRegistry[3];
  }
  uVar5 = 1;
  uVar3 = 1;
LAB_002129e7:
  (*p_Var4)(registry,"ScreenWindowed",uVar3);
  (*registry->_vptr_IRegistry[2])(registry,"EngineD3D",0);
  iVar1 = COM_CheckParm("-d3d");
  if (iVar1 == 0) {
    COM_CheckParm("-gl");
  }
  videomode = operator_new(0x1bc);
  videomode[0x67]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  videomode[0x68]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  videomode[0x69]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  videomode[0x6a]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  videomode[100]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  videomode[0x65]._vptr_IVideoMode = (_func_int_varargs **)0x0;
  videomode[0x61]._vptr_IVideoMode = (_func_int_varargs **)0x280;
  videomode->_vptr_IVideoMode = (_func_int_varargs **)&PTR_GetName_00295528;
  *(undefined1 *)&videomode[0x66]._vptr_IVideoMode = 0;
  videomode[0x62]._vptr_IVideoMode = (_func_int_varargs **)0x1e0;
  videomode[99]._vptr_IVideoMode = (_func_int_varargs **)0x20;
  *(undefined1 *)&videomode[0x6e]._vptr_IVideoMode = uVar5;
  return;
}


// VideoMode_GetCurrentRenderer  @ 00212c80
void VideoMode_GetCurrentRenderer
               (char *name,int namelen,int *windowed,int *hdmodels,int *addons_folder,int *vid_level
               )

{
  uint uVar1;
  int iVar2;
  char *__src;
  
  if ((0 < namelen) && (name != (char *)0x0)) {
    __src = (char *)(**videomode->_vptr_IVideoMode)(videomode);
    strncpy(name,__src,namelen);
  }
  if (windowed != (int *)0x0) {
    uVar1 = (*videomode->_vptr_IVideoMode[7])(videomode);
    *windowed = uVar1 & 0xff;
  }
  if (hdmodels != (int *)0x0) {
    iVar2 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",1);
    *hdmodels = (uint)(0 < iVar2);
  }
  if (addons_folder != (int *)0x0) {
    iVar2 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0);
    *addons_folder = (uint)(0 < iVar2);
  }
  if (vid_level != (int *)0x0) {
    iVar2 = (*registry->_vptr_IRegistry[2])(registry,"vid_level",0);
    *vid_level = iVar2;
  }
  return;
}


// VideoMode_GetCurrentVideoMode  @ 00212c20
void VideoMode_GetCurrentVideoMode(int *wide,int *tall,int *bpp)

{
  int *piVar1;
  
                    /* Unresolved local var: vmode_t * mode@[???] */
  piVar1 = (int *)(*videomode->_vptr_IVideoMode[4])(videomode);
  if (piVar1 != (int *)0x0) {
    if (wide != (int *)0x0) {
      *wide = *piVar1;
    }
    if (tall != (int *)0x0) {
      *tall = piVar1[1];
    }
    if (bpp != (int *)0x0) {
      *bpp = piVar1[2];
    }
  }
  return;
}


// VideoMode_GetVideoModes  @ 00212be0
void VideoMode_GetVideoModes(vmode_s **liststart,int *count)

{
  int iVar1;
  vmode_s *pvVar2;
  
  iVar1 = (*videomode->_vptr_IVideoMode[6])(videomode);
  *count = iVar1;
  pvVar2 = (vmode_s *)(*videomode->_vptr_IVideoMode[5])(videomode,0);
  *liststart = pvVar2;
  return;
}


// VideoMode_IsWindowed  @ 00212da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VideoMode_IsWindowed(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (videomode != (IVideoMode *)0x0) {
    uVar1 = (*videomode->_vptr_IVideoMode[7])(videomode);
    uVar1 = uVar1 & 0xff;
  }
  return uVar1;
}


// VideoMode_RestoreVideo  @ 00212dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VideoMode_RestoreVideo(void)

{
  (*videomode->_vptr_IVideoMode[0xc])(videomode);
  return;
}


// VideoMode_SetVideoMode  @ 00212b70
void VideoMode_SetVideoMode(int width,int height,int bpp)

{
  (*registry->_vptr_IRegistry[3])(registry,"ScreenWidth",width);
  (*registry->_vptr_IRegistry[3])(registry,"ScreenHeight",height);
                    /* WARNING: Could not recover jumptable at 0x00212bd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*registry->_vptr_IRegistry[3])();
  return;
}


// VideoMode_SwitchMode  @ 00212b40
void VideoMode_SwitchMode(int hardware,int windowed)

{
  (*registry->_vptr_IRegistry[3])(registry,"ScreenWindowed",windowed);
  return;
}


