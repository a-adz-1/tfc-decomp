// R_StudioDrawModel  @ 0008f3e0
int R_StudioDrawModel(int flags)

{
  int iVar1;
  
  iVar1 = CStudioModelRenderer::StudioDrawModel(&g_StudioRenderer.super_CStudioModelRenderer,flags);
  return iVar1;
}


// R_StudioDrawPlayer  @ 0008f400
int R_StudioDrawPlayer(int flags,entity_state_t *pplayer)

{
  int iVar1;
  
  iVar1 = CStudioModelRenderer::StudioDrawPlayer
                    (&g_StudioRenderer.super_CStudioModelRenderer,flags,pplayer);
  return iVar1;
}


// R_StudioInit  @ 0008f450
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioInit(void)

{
  CStudioModelRenderer::Init(&g_StudioRenderer.super_CStudioModelRenderer);
  return;
}


