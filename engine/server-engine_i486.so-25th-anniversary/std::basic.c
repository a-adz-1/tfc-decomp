// std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::_M_dispose  @ 000b9f40
/* WARNING: Removing unreachable block (ram,0x000b9f60) */
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


