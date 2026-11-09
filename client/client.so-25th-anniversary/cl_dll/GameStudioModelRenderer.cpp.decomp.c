// Ghidra decompilation of functions from cl_dll/GameStudioModelRenderer.cpp
// 6 functions, ordered by original source line

// CGameStudioModelRenderer::CGameStudioModelRenderer  @ 0006bb30  (line 34)

/* DWARF original prototype: void CGameStudioModelRenderer(CGameStudioModelRenderer * this) */

void __thiscall CGameStudioModelRenderer::CGameStudioModelRenderer(CGameStudioModelRenderer *this)

{
  CStudioModelRenderer::CStudioModelRenderer(&this->super_CStudioModelRenderer);
  (this->super_CStudioModelRenderer)._vptr_CStudioModelRenderer =
       (_func_int_varargs **)&PTR__CGameStudioModelRenderer_000c25f0;
  return;
}


// R_StudioDrawPlayer  @ 0006bb00  (line 49)

int R_StudioDrawPlayer(int flags,entity_state_t *pplayer)

{
  int iVar1;
  
  iVar1 = CStudioModelRenderer::StudioDrawPlayer
                    (&g_StudioRenderer.super_CStudioModelRenderer,flags,pplayer);
  return iVar1;
}


// R_StudioDrawModel  @ 0006bae0  (line 60)

int R_StudioDrawModel(int flags)

{
  int iVar1;
  
  iVar1 = CStudioModelRenderer::StudioDrawModel(&g_StudioRenderer.super_CStudioModelRenderer,flags);
  return iVar1;
}


// R_StudioInit  @ 0006bb50  (line 71)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioInit(void)

{
  CStudioModelRenderer::Init(&g_StudioRenderer.super_CStudioModelRenderer);
  return;
}


// HUD_GetStudioModelInterface  @ 0006bb70  (line 91)

int HUD_GetStudioModelInterface
              (int version,r_studio_interface_s **ppinterface,engine_studio_api_s *pstudio)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = 0;
  if (version == 1) {
    *ppinterface = &studio;
    uVar3 = 0;
    do {
      uVar1 = *(undefined4 *)((int)&pstudio->Cache_Check + uVar3);
      uVar4 = uVar3 + 8;
      *(undefined4 *)((int)&IEngineStudio.Mem_Calloc + uVar3) =
           *(undefined4 *)((int)&pstudio->Mem_Calloc + uVar3);
      *(undefined4 *)((int)&IEngineStudio.Cache_Check + uVar3) = uVar1;
      uVar3 = uVar4;
    } while (uVar4 < 0xb8);
    CStudioModelRenderer::Init(&g_StudioRenderer.super_CStudioModelRenderer);
    iVar2 = 1;
  }
  return iVar2;
}


// _GLOBAL__sub_I_g_StudioRenderer  @ 00047ac0  (line 108)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_StudioRenderer(void)

{
  CStudioModelRenderer::CStudioModelRenderer(&g_StudioRenderer.super_CStudioModelRenderer);
  g_StudioRenderer.super_CStudioModelRenderer._vptr_CStudioModelRenderer =
       (_func_int_varargs **)&PTR__CGameStudioModelRenderer_000c25f0;
  __cxa_atexit(CGameStudioModelRenderer::~CGameStudioModelRenderer,&g_StudioRenderer,&__dso_handle);
  return;
}


