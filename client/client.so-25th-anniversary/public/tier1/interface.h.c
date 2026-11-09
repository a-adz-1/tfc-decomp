// Ghidra decompilation of functions from public/tier1/interface.h
// 2 functions, ordered by original source line

// IBaseInterface::~IBaseInterface  @ 0006b0a0  (line 53)

/* DWARF original prototype: void ~IBaseInterface(IBaseInterface * this, int __in_chrg) */

void __thiscall IBaseInterface::~IBaseInterface(IBaseInterface *this,int __in_chrg)

{
  return;
}


// IBaseInterface::~IBaseInterface  @ 0006b170  (line 53)

/* DWARF original prototype: void ~IBaseInterface(IBaseInterface * this, int __in_chrg) */

void __thiscall IBaseInterface::~IBaseInterface(IBaseInterface *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


