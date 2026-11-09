// std::_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::_M_insert_  @ 001df360
/* DWARF original prototype: iterator
   _M_insert_(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, _Const_Base_ptr __x, _Const_Base_ptr __p,
   pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int> * __v) */

iterator __thiscall
std::
_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::_M_insert_(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
             *this,_Const_Base_ptr __x,_Const_Base_ptr __p,
            pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
            *__v)

{
  uint uVar1;
  uint uVar2;
  _Rb_tree_node_base *p_Var3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  string *in_stack_00000014;
  _Base_ptr *local_24;
  
                    /* Unresolved local var: bool __insert_left@[???]
                       Unresolved local var: _Link_type __z@[DW_OP_reg7(EDI)] */
  if (__p == (_Const_Base_ptr)0x0) {
    bVar8 = true;
    if (__v != (pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                *)&__x->_M_parent) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
      pbVar6 = (byte *)(in_stack_00000014->_M_dataplus)._M_p;
      pbVar7 = (byte *)__v[2].first._M_dataplus._M_p;
      uVar1 = *(uint *)(pbVar6 + -0xc);
      uVar2 = *(uint *)(pbVar7 + -0xc);
      uVar4 = uVar2;
      if (uVar1 < uVar2) {
        uVar4 = uVar1;
      }
      bVar8 = false;
      bVar9 = true;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
                    /* Unresolved local var: difference_type __d@[???] */
      iVar5 = (int)(char)((!bVar8 && !bVar9) - bVar8);
      if (iVar5 == 0) {
        iVar5 = uVar1 - uVar2;
      }
      bVar8 = SUB41((uint)iVar5 >> 0x1f,0);
    }
  }
  else {
    bVar8 = true;
  }
                    /* Unresolved local var: _Link_type __tmp@[???] */
  local_24 = &__x->_M_parent;
  p_Var3 = operator_new(0x18);
  if (p_Var3 + 1 != (_Rb_tree_node_base *)0x0) {
    std::string::string(p_Var3 + 1,in_stack_00000014);
    p_Var3[1]._M_parent = (_Base_ptr)in_stack_00000014[1]._M_dataplus._M_p;
  }
  std::_Rb_tree_insert_and_rebalance
            (bVar8,p_Var3,(_Rb_tree_node_base *)__v,(_Rb_tree_node_base *)local_24);
  __x[1]._M_parent = (_Base_ptr)((int)&(__x[1]._M_parent)->_M_color + 1);
  *(_Rb_tree_node_base **)&this->_M_impl = p_Var3;
  return (iterator)(_Base_ptr)this;
}


