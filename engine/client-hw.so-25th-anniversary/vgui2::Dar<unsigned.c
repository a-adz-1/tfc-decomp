// vgui2::Dar<unsigned_int>::~Dar  @ 001d67f0
/* DWARF original prototype: void ~Dar(Dar<unsigned_int> * this, int __in_chrg) */

void __thiscall vgui2::Dar<unsigned_int>::~Dar(Dar<unsigned_int> *this,int __in_chrg)

{
  if (this->_data != (uint *)0x0) {
    operator_delete__(this->_data);
    return;
  }
  return;
}


