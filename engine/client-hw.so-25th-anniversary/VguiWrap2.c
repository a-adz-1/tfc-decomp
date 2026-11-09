// VguiWrap2_GetCareerUI  @ 001a4520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * VguiWrap2_GetCareerUI(void)

{
  return staticCareerUI;
}


// VguiWrap2_GetMouseDelta  @ 001a4850
void VguiWrap2_GetMouseDelta(int *x,int *y)

{
  BaseUISurface::GetMouseDelta(&g_BaseUISurface,x,y);
  return;
}


