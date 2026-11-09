// Ghidra decompilation of functions from cl_dll/GameStudioModelRenderer.h
// 2 functions, ordered by original source line

// CGameStudioModelRenderer::~CGameStudioModelRenderer  @ 0006bbc0  (line 13)

/* DWARF original prototype: void ~CGameStudioModelRenderer(CGameStudioModelRenderer * this, int
   __in_chrg) */

void __thiscall
CGameStudioModelRenderer::~CGameStudioModelRenderer(CGameStudioModelRenderer *this,int __in_chrg)

{
  (this->super_CStudioModelRenderer)._vptr_CStudioModelRenderer =
       (_func_int_varargs **)&PTR__CGameStudioModelRenderer_000c25f0;
  CStudioModelRenderer::~CStudioModelRenderer(&this->super_CStudioModelRenderer,__in_chrg);
  return;
}


// CGameStudioModelRenderer::~CGameStudioModelRenderer  @ 0006bbd0  (line 13)

/* DWARF original prototype: void ~CGameStudioModelRenderer(CGameStudioModelRenderer * this, int
   __in_chrg) */

void __thiscall
CGameStudioModelRenderer::~CGameStudioModelRenderer(CGameStudioModelRenderer *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_CStudioModelRenderer)._vptr_CStudioModelRenderer =
       (_func_int_varargs **)&PTR__CGameStudioModelRenderer_000c25f0;
  CStudioModelRenderer::~CStudioModelRenderer(&this->super_CStudioModelRenderer,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


