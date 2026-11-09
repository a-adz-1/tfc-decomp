// std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::_M_dispose  @ 00098dc0
/* WARNING: Removing unreachable block (ram,0x00098dd7) */
/* DWARF original prototype: void _M_dispose(_Rep * this, allocator<char> * __a) */

void __thiscall
std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::_M_dispose
          (_Rep *this,allocator<char> *__a)

{
  allocator *paVar1;
  int iVar2;
  allocator *in_EAX;
  
  LOCK();
  paVar1 = in_EAX + 8;
  iVar2 = *(int *)paVar1;
  *(int *)paVar1 = *(int *)paVar1 + -1;
  UNLOCK();
  if (iVar2 < 1) {
    std::string::_Rep::_M_destroy(in_EAX);
  }
  return;
}


// std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::_M_dispose  @ 0012c610
/* WARNING: Removing unreachable block (ram,0x0012c630) */
/* DWARF original prototype: void _M_dispose(_Rep * this, allocator<char> * __a) */

void __thiscall
std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::_M_dispose
          (_Rep *this,allocator<char> *__a)

{
  allocator *paVar1;
  int iVar2;
  allocator *in_EAX;
  
  LOCK();
  paVar1 = in_EAX + 8;
  iVar2 = *(int *)paVar1;
  *(int *)paVar1 = *(int *)paVar1 + -1;
  UNLOCK();
  if (0 < iVar2) {
    return;
  }
  std::string::_Rep::_M_destroy(in_EAX);
  return;
}


