// Ghidra decompilation of functions from cl_dll/health.h
// 2 functions, ordered by original source line

// CHudHealth::~CHudHealth  @ 0006d910  (line 101)

/* DWARF original prototype: void ~CHudHealth(CHudHealth * this, int __in_chrg) */

void __thiscall CHudHealth::~CHudHealth(CHudHealth *this,int __in_chrg)

{
  return;
}


// CHudHealth::~CHudHealth  @ 0006d920  (line 101)

/* DWARF original prototype: void ~CHudHealth(CHudHealth * this, int __in_chrg) */

void __thiscall CHudHealth::~CHudHealth(CHudHealth *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


