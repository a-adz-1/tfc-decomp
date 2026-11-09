// std::map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::~map  @ 0018b210
/* WARNING: Removing unreachable block (ram,0x0018b22b) */
/* WARNING: Removing unreachable block (ram,0x0018b2ce) */
/* WARNING: Removing unreachable block (ram,0x0018b298) */
/* WARNING: Removing unreachable block (ram,0x0018b2a5) */
/* WARNING: Removing unreachable block (ram,0x0018b2c0) */
/* DWARF original prototype: void
   ~map(map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, int __in_chrg) */

void __thiscall
std::
map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::~map(map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
       *this,int __in_chrg)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  _Base_ptr p_Var4;
  _Base_ptr p_Var5;
  
  p_Var5 = (this->_M_t)._M_impl._M_header._M_parent;
  do {
    while( true ) {
      if (p_Var5 == (_Base_ptr)0x0) {
        return;
      }
      _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ::_M_erase(&this->_M_t,(_Link_type)p_Var5->_M_right);
      p_Var4 = p_Var5->_M_left;
      paVar1 = (allocator *)(p_Var5[1]._M_color - 0xc);
      if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) break;
LAB_0018b230:
                    /* Unresolved local var: _Link_type __y@[???] */
      operator_delete(p_Var5);
      p_Var5 = p_Var4;
    }
    LOCK();
    piVar2 = (int *)(p_Var5[1]._M_color - 4);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (0 < iVar3) goto LAB_0018b230;
    std::string::_Rep::_M_destroy(paVar1);
    operator_delete(p_Var5);
    p_Var5 = p_Var4;
  } while( true );
}


