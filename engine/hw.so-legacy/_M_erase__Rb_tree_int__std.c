// std::_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>::_M_erase  @ 001decb0
/* DWARF original prototype: void
   _M_erase(_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
   * this, _Link_type __x) */

void __thiscall
std::
_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
::_M_erase(_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
           *this,_Link_type __x)

{
  _Base_ptr p_Var1;
  _Base_ptr p_Var2;
  _Base_ptr p_Var3;
  _Base_ptr p_Var4;
  _Base_ptr p_Var5;
  _Base_ptr p_Var6;
  _Base_ptr p_Var7;
  _Base_ptr p_Var8;
  _Link_type p_Var9;
  _Base_ptr p_Var10;
  
  while (__x != (_Link_type)0x0) {
    p_Var10 = (__x->super__Rb_tree_node_base)._M_right;
                    /* Unresolved local var: _Link_type __y@[DW_OP_reg3(EBX)] */
    while (p_Var10 != (_Base_ptr)0x0) {
      p_Var8 = p_Var10->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
      while (p_Var8 != (_Base_ptr)0x0) {
        p_Var7 = p_Var8->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
        while (p_Var7 != (_Base_ptr)0x0) {
          p_Var6 = p_Var7->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
          while (p_Var6 != (_Base_ptr)0x0) {
            p_Var5 = p_Var6->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
            while (p_Var5 != (_Base_ptr)0x0) {
              p_Var4 = p_Var5->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
              while (p_Var4 != (_Base_ptr)0x0) {
                p_Var3 = p_Var4->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
                while (p_Var3 != (_Base_ptr)0x0) {
                  p_Var2 = p_Var3->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
                  while (p_Var2 != (_Base_ptr)0x0) {
                    /* Unresolved local var: _Link_type __y@[???] */
                    _M_erase(this,(_Link_type)p_Var2->_M_right);
                    p_Var1 = p_Var2->_M_left;
                    operator_delete(p_Var2);
                    p_Var2 = p_Var1;
                  }
                  p_Var2 = p_Var3->_M_left;
                  operator_delete(p_Var3);
                  p_Var3 = p_Var2;
                }
                p_Var3 = p_Var4->_M_left;
                operator_delete(p_Var4);
                p_Var4 = p_Var3;
              }
              p_Var4 = p_Var5->_M_left;
              operator_delete(p_Var5);
              p_Var5 = p_Var4;
            }
            p_Var5 = p_Var6->_M_left;
            operator_delete(p_Var6);
            p_Var6 = p_Var5;
          }
          p_Var6 = p_Var7->_M_left;
          operator_delete(p_Var7);
          p_Var7 = p_Var6;
        }
        p_Var7 = p_Var8->_M_left;
        operator_delete(p_Var8);
        p_Var8 = p_Var7;
      }
      p_Var8 = p_Var10->_M_left;
      operator_delete(p_Var10);
      p_Var10 = p_Var8;
    }
    p_Var9 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    operator_delete(__x);
    __x = p_Var9;
  }
  return;
}


