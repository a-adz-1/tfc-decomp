// Ghidra decompilation of functions from cl_dll/hud_spectator.h
// 2 functions, ordered by original source line

// CHudSpectator::~CHudSpectator  @ 00058530  (line 68)

/* DWARF original prototype: void ~CHudSpectator(CHudSpectator * this, int __in_chrg) */

void __thiscall CHudSpectator::~CHudSpectator(CHudSpectator *this,int __in_chrg)

{
  (this->super_CHudBase)._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudSpectator_000bfe54;
  CInterpolation::~CInterpolation(&this->m_WayInterpolation,__in_chrg);
  return;
}


// CHudSpectator::~CHudSpectator  @ 00058550  (line 68)

/* DWARF original prototype: void ~CHudSpectator(CHudSpectator * this, int __in_chrg) */

void __thiscall CHudSpectator::~CHudSpectator(CHudSpectator *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_CHudBase)._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudSpectator_000bfe54;
  CInterpolation::~CInterpolation(&this->m_WayInterpolation,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


