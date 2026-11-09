// std::_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>::_M_insert_unique  @ 001dcf40
/* DWARF original prototype: pair<std::_Rb_tree_iterator<std::pair<const_int,_DetailMap*>_>,_bool>
   _M_insert_unique(_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
   * this, pair<const_int,_DetailMap*> * __v) */

pair<std::_Rb_tree_iterator<std::pair<const_int,_DetailMap*>_>,_bool> __thiscall
std::
_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
::_M_insert_unique(_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
                   *this,pair<const_int,_DetailMap*> *__v)

{
  _Rb_tree_color _Var1;
  _Rb_tree_iterator<std::pair<const_int,_DetailMap*>_> in_EAX;
  _Base_ptr p_Var2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_color *in_EDX;
  _Rb_tree_color _Var4;
  undefined4 extraout_EDX;
  bool bVar5;
  _Rb_tree_node_base *p_Var6;
  pair<std::_Rb_tree_iterator<std::pair<const_int,_DetailMap*>_>,_bool> pVar7;
  pair<std::_Rb_tree_iterator<std::pair<const_int,_DetailMap*>_>,_bool> pVar8;
  
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???]
                       Unresolved local var: bool __insert_left@[???]
                       Unresolved local var: _Link_type __z@[DW_OP_reg0(EAX)] */
  if (g_idMap._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0) {
    p_Var6 = &g_idMap._M_t._M_impl._M_header;
LAB_001dcfa0:
    if (g_idMap._M_t._M_impl._M_header._M_left == p_Var6) {
                    /* Unresolved local var: bool __insert_left@[???]
                       Unresolved local var: _Link_type __z@[DW_OP_reg0(EAX)] */
      bVar5 = true;
      if (p_Var6 != &g_idMap._M_t._M_impl._M_header) {
        bVar5 = (int)*in_EDX < (int)p_Var6[1]._M_color;
      }
                    /* Unresolved local var: _Link_type __tmp@[???] */
      p_Var3 = operator_new(0x18);
      if (p_Var3 != (_Rb_tree_node_base *)0xfffffff0) {
        p_Var2 = (_Base_ptr)in_EDX[1];
        p_Var3[1]._M_color = *in_EDX;
        p_Var3[1]._M_parent = p_Var2;
      }
      goto LAB_001dd060;
    }
    p_Var2 = (_Base_ptr)std::_Rb_tree_decrement(p_Var6);
    _Var4 = *in_EDX;
    if ((int)_Var4 <= (int)p_Var2[1]._M_color) {
LAB_001dcf85:
      (in_EAX._M_node)->_M_color = (_Rb_tree_color)p_Var2;
      *(undefined1 *)&(in_EAX._M_node)->_M_parent = 0;
      pVar7._4_4_ = _Var4;
      pVar7.first._M_node = in_EAX._M_node;
      return pVar7;
    }
  }
  else {
    _Var4 = *in_EDX;
    p_Var2 = g_idMap._M_t._M_impl._M_header._M_parent;
    do {
      p_Var6 = p_Var2;
      _Var1 = p_Var6[1]._M_color;
      if ((int)_Var4 < (int)_Var1) {
        p_Var2 = p_Var6->_M_left;
      }
      else {
        p_Var2 = p_Var6->_M_right;
      }
    } while (p_Var2 != (_Base_ptr)0x0);
    if ((int)_Var4 < (int)_Var1) goto LAB_001dcfa0;
    p_Var2 = p_Var6;
    if ((int)_Var4 <= (int)_Var1) goto LAB_001dcf85;
  }
  bVar5 = true;
  if (p_Var6 != &g_idMap._M_t._M_impl._M_header) {
    bVar5 = (int)_Var4 < (int)p_Var6[1]._M_color;
  }
                    /* Unresolved local var: _Link_type __tmp@[???] */
  p_Var3 = operator_new(0x18);
  if (p_Var3 != (_Rb_tree_node_base *)0xfffffff0) {
    p_Var2 = (_Base_ptr)in_EDX[1];
    p_Var3[1]._M_color = *in_EDX;
    p_Var3[1]._M_parent = p_Var2;
  }
LAB_001dd060:
  std::_Rb_tree_insert_and_rebalance(bVar5,p_Var3,p_Var6,&g_idMap._M_t._M_impl._M_header);
  *(undefined1 *)&(in_EAX._M_node)->_M_parent = 1;
  g_idMap._M_t._M_impl._M_node_count = g_idMap._M_t._M_impl._M_node_count + 1;
  (in_EAX._M_node)->_M_color = (_Rb_tree_color)p_Var3;
  pVar8._4_4_ = extraout_EDX;
  pVar8.first._M_node = in_EAX._M_node;
  return pVar8;
}


// std::_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::_M_insert_unique  @ 001df450
/* DWARF original prototype:
   pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
   _M_insert_unique(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int> *
   __v) */

pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
 __thiscall
std::
_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::_M_insert_unique(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                   *this,pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                         *__v)

{
  _Rb_tree_node_base *p_Var1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 extraout_EDX;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
  pVar13;
  pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
  pVar14;
  undefined4 *in_stack_0000000c;
  uint local_30;
  _Rb_tree_node_base *local_2c;
  _Rb_tree_node_base *local_24;
  less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_> local_20;
  undefined3 uStack_1f;
  
  bVar12 = 0;
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
  p_Var1 = (_Rb_tree_node_base *)__v[1].first._M_dataplus._M_p;
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    local_2c = (_Rb_tree_node_base *)&__v->second;
LAB_001df526:
    if (local_2c == (_Rb_tree_node_base *)__v[1].second) goto LAB_001df58b;
    local_24 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(local_2c);
    pbVar9 = (byte *)*in_stack_0000000c;
    local_30 = *(uint *)(pbVar9 + -0xc);
    pbVar5 = (byte *)local_24[1]._M_color;
    uVar6 = *(uint *)(pbVar5 + -0xc);
    uVar4 = local_30;
    if (uVar6 < local_30) {
      uVar4 = uVar6;
    }
  }
  else {
    pbVar9 = (byte *)*in_stack_0000000c;
    local_30 = *(uint *)(pbVar9 + -0xc);
    do {
      local_2c = p_Var1;
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
      pbVar5 = (byte *)local_2c[1]._M_color;
      uVar6 = *(uint *)(pbVar5 + -0xc);
      uVar4 = local_30;
      if (uVar6 < local_30) {
        uVar4 = uVar6;
      }
      bVar10 = false;
      bVar11 = true;
      uVar2 = uVar4;
      pbVar7 = pbVar9;
      pbVar8 = pbVar5;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar10 = *pbVar7 < *pbVar8;
        bVar11 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar11);
                    /* Unresolved local var: difference_type __d@[???] */
      iVar3 = (int)(char)((!bVar10 && !bVar11) - bVar10);
      if (iVar3 == 0) {
        iVar3 = local_30 - uVar6;
      }
      if (iVar3 < 0) {
        p_Var1 = local_2c->_M_left;
      }
      else {
        p_Var1 = local_2c->_M_right;
      }
    } while (p_Var1 != (_Base_ptr)0x0);
    local_24 = local_2c;
    if (iVar3 < 0) goto LAB_001df526;
  }
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
  bVar10 = false;
  bVar11 = true;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar10 = *pbVar5 < *pbVar9;
    bVar11 = *pbVar5 == *pbVar9;
    pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
    pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
  } while (bVar11);
                    /* Unresolved local var: difference_type __d@[???] */
  iVar3 = (int)(char)((!bVar10 && !bVar11) - bVar10);
  if (iVar3 == 0) {
    iVar3 = uVar6 - local_30;
  }
  if (-1 < iVar3) {
    *(undefined1 *)&(this->_M_impl)._M_header._M_color = _S_red;
    *(_Rb_tree_node_base **)&this->_M_impl = local_24;
    pVar13._4_4_ = local_24;
    pVar13.first._M_node = (_Base_ptr)this;
    return pVar13;
  }
LAB_001df58b:
  _M_insert_((_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
              *)&stack0xffffffe0,(_Const_Base_ptr)__v,(_Const_Base_ptr)0x0,
             (pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
              *)local_2c);
  *(undefined1 *)&(this->_M_impl)._M_header._M_color = _S_black;
  (this->_M_impl)._M_key_compare =
       (less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>)
       local_20.
       super_binary_function<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_bool>
  ;
  *(undefined3 *)&(this->_M_impl).field_0x1 = uStack_1f;
  pVar14._4_4_ = extraout_EDX;
  pVar14.first._M_node = (_Base_ptr)this;
  return pVar14;
}


