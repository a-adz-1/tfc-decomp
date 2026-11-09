// SDL_GetMousePos  @ 001be6f0
void SDL_GetMousePos(POINT *ppt)

{
  POINT *pPVar1;
  POINT *pPVar2;
  int iVar3;
  float fVar4;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
  (*g_engdstAddrs.pfnGetMousePos)((tagPOINT **)&ppt);
  SDL_GetMouseState(ppt,&ppt->y);
  iVar3 = VideoMode_IsWindowed();
  if (iVar3 == 0) {
                    /* Unresolved local var: int wW@[???]
                       Unresolved local var: int wT@[???]
                       Unresolved local var: int vW@[???]
                       Unresolved local var: int vT@[???]
                       Unresolved local var: float fXCenterDelta@[???]
                       Unresolved local var: float fYCenterDelta@[???] */
    SDL_GetWindowSize(*pmainwindow,&local_1c,&local_18);
    VideoMode_GetCurrentVideoMode(&local_14,local_10,(int *)0x0);
    pPVar1 = ppt;
    ppt->x = (int)(((float)local_14 / (float)local_1c) * (float)ppt->x);
    iVar3 = ppt->x;
    ppt->y = (int)(((float)local_10[0] / (float)local_18) * (float)ppt->y);
    fVar4 = GetXMouseAspectRatioAdjustment();
    pPVar2 = ppt;
    pPVar1->x = (int)((fVar4 - 1.0) * (float)(iVar3 - local_14 / 2) + (float)iVar3);
    iVar3 = ppt->y;
    fVar4 = GetYMouseAspectRatioAdjustment();
    pPVar2->y = (int)((fVar4 - 1.0) * (float)(iVar3 - local_10[0] / 2) + (float)iVar3);
  }
  return;
}


// SDL_SetMousePos  @ 001be6c0
void SDL_SetMousePos(int x,int y)

{
  SDL_WarpMouseInWindow(*pmainwindow,x,y);
  return;
}


