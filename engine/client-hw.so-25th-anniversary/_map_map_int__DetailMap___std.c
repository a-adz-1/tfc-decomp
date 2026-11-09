// std::map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>::~map  @ 0018ac60
/* DWARF original prototype: void
   ~map(map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_> *
   this, int __in_chrg) */

void __thiscall
std::map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>::~map
          (map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
           *this,int __in_chrg)

{
  _Base_ptr p_Var1;
  _Base_ptr p_Var2;
  
  p_Var2 = (this->_M_t)._M_impl._M_header._M_parent;
  while (p_Var2 != (_Base_ptr)0x0) {
                    /* Unresolved local var: _Link_type __y@[???] */
    _Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
    ::_M_erase(&this->_M_t,(_Link_type)p_Var2->_M_right);
    p_Var1 = p_Var2->_M_left;
    operator_delete(p_Var2);
    p_Var2 = p_Var1;
  }
  return;
}


