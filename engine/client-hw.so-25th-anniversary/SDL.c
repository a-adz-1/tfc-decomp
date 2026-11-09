// SDL_GetMousePos  @ 00167570
void SDL_GetMousePos(POINT *ppt)

{
  int iVar1;
  float fVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [4];
  
  (*g_engdstAddrs.pfnGetMousePos)((tagPOINT **)&ppt);
  SDL_GetMouseState(ppt,&ppt->y);
  iVar1 = VideoMode_IsWindowed();
  if (iVar1 == 0) {
                    /* Unresolved local var: int wW@[???]
                       Unresolved local var: int wT@[???]
                       Unresolved local var: int vW@[???]
                       Unresolved local var: int vT@[???]
                       Unresolved local var: float fXCenterDelta@[???]
                       Unresolved local var: float fYCenterDelta@[???] */
    SDL_GetWindowSize(*pmainwindow,&local_1c,&local_18);
    VideoMode_GetCurrentVideoMode(&local_14,local_10,(int *)0x0);
    ppt->x = (int)((float)ppt->x * ((float)local_14 / (float)local_1c));
    ppt->y = (int)((float)ppt->y * ((float)local_10[0] / (float)local_18));
    iVar1 = ppt->x;
    fVar2 = GetXMouseAspectRatioAdjustment();
    ppt->x = (int)((float)ppt->x + (fVar2 - 1.0) * (float)(iVar1 - local_14 / 2));
    iVar1 = ppt->y;
    fVar2 = GetYMouseAspectRatioAdjustment();
    ppt->y = (int)((float)ppt->y + (fVar2 - 1.0) * (float)(iVar1 - local_10[0] / 2));
  }
  return;
}


// SDL_SetAttributes  @ 001c5240
void SDL_SetAttributes(bool tryNewCtx)

{
  int iVar1;
  
  SDL_GL_ResetAttributes();
  SDL_GL_SetAttribute(5,1);
  SDL_GL_SetAttribute(0xf,1);
  SDL_GL_SetAttribute(6,0x18);
  SDL_GL_SetAttribute(0,4);
  SDL_GL_SetAttribute(1,4);
  SDL_GL_SetAttribute(2,4);
  SDL_GL_SetAttribute(3,0);
  iVar1 = (*videomode->_vptr_IVideoMode[8])(videomode);
  if ((char)iVar1 != '\0') {
    SDL_GL_SetAttribute(0xd,1);
    SDL_GL_SetAttribute(0xe,4);
  }
  if (tryNewCtx) {
    SDL_GL_SetAttribute(0x11,4);
    SDL_GL_SetAttribute(0x12,2);
    SDL_GL_SetAttribute(0x15,2);
  }
  return;
}


// SDL_SetMousePos  @ 001676b0
void SDL_SetMousePos(int x,int y)

{
  SDL_WarpMouseInWindow(*pmainwindow,x,y);
  return;
}


