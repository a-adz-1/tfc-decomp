// std::_Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>::_M_insert_unique<std::pair<int,_DetailMap*>_>  @ 0018a800
/* DWARF original name: _M_insert_unique<std::pair<int, DetailMap*> >
   DWARF original prototype: pair<std::_Rb_tree_iterator<std::pair<int_const,_DetailMap*>_>,_bool>
   _M_insert_unique<std::pair<int,_DetailMap*>_>(_Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
   * this, pair<int,_DetailMap*> * __v) */

pair<std::_Rb_tree_iterator<std::pair<int_const,_DetailMap*>_>,_bool> __thiscall
std::
_Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
::_M_insert_unique<std::pair<int,_DetailMap*>_>
          (_Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
           *this,pair<int,_DetailMap*> *__v)

{
  _Rb_tree_color _Var1;
  int iVar2;
  _Base_ptr p_Var3;
  DetailMap *pDVar4;
  _Rb_tree_node_base *p_Var5;
  undefined4 extraout_EDX;
  DetailMap *pDVar6;
  bool bVar7;
  pair<std::_Rb_tree_iterator<std::pair<int_const,_DetailMap*>_>,_bool> pVar8;
  pair<std::_Rb_tree_iterator<std::pair<int_const,_DetailMap*>_>,_bool> pVar9;
  _Rb_tree_color *in_stack_0000000c;
  
                    /* Unresolved local var:
                       pair<std::_Rb_tree_node_base*,_std::_Rb_tree_node_base*> __res@[???] */
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
  if ((DetailMap *)__v[1].first == (DetailMap *)0x0) {
    pDVar6 = (DetailMap *)&__v->second;
  }
  else {
    _Var1 = *in_stack_0000000c;
    pDVar6 = (DetailMap *)__v[1].first;
    do {
      pDVar4 = pDVar6;
      iVar2 = pDVar4->_oglTextureId;
      if ((int)_Var1 < iVar2) {
        pDVar6 = (DetailMap *)pDVar4->_sScale;
      }
      else {
        pDVar6 = (DetailMap *)pDVar4->_tScale;
      }
    } while (pDVar6 != (DetailMap *)0x0);
    pDVar6 = pDVar4;
    if (iVar2 <= (int)_Var1) {
      if (iVar2 < (int)_Var1) goto LAB_0018a884;
      goto LAB_0018a86e;
    }
  }
  if (((__v[1].second == pDVar6) ||
      (pDVar4 = (DetailMap *)std::_Rb_tree_decrement((_Rb_tree_node_base *)pDVar6),
      pDVar4->_oglTextureId < (int)*in_stack_0000000c)) &&
     (pDVar4 = (DetailMap *)0x0, pDVar6 != (DetailMap *)0x0)) {
LAB_0018a884:
                    /* Unresolved local var: _Alloc_node __an@[???]
                       Unresolved local var: bool __insert_left@[???]
                       Unresolved local var: _Link_type __z@[???] */
    if (pDVar6 == (DetailMap *)&__v->second) {
      bVar7 = true;
    }
    else {
      bVar7 = (int)*in_stack_0000000c < pDVar6->_oglTextureId;
    }
                    /* Unresolved local var: _Link_type __tmp@[???] */
    p_Var5 = operator_new(0x18);
    if (p_Var5 != (_Rb_tree_node_base *)0xfffffff0) {
      p_Var3 = (_Base_ptr)in_stack_0000000c[1];
      p_Var5[1]._M_color = *in_stack_0000000c;
      p_Var5[1]._M_parent = p_Var3;
    }
    std::_Rb_tree_insert_and_rebalance
              (bVar7,p_Var5,(_Rb_tree_node_base *)pDVar6,(_Rb_tree_node_base *)&__v->second);
    __v[2].second = (DetailMap *)((int)&((__v[2].second)->_diffuseName)._M_dataplus._M_p + 1);
    *(undefined1 *)&(this->_M_impl)._M_header._M_color = _S_black;
    *(_Rb_tree_node_base **)&this->_M_impl = p_Var5;
    pVar9._4_4_ = extraout_EDX;
    pVar9.first._M_node = (_Base_ptr)this;
    return pVar9;
  }
LAB_0018a86e:
  *(DetailMap **)&this->_M_impl = pDVar4;
  *(undefined1 *)&(this->_M_impl)._M_header._M_color = _S_red;
  pVar8._4_4_ = in_stack_0000000c;
  pVar8.first._M_node = (_Base_ptr)this;
  return pVar8;
}


// std::_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::_M_insert_unique<std::pair<std::basic_string<char>,_int>_>  @ 0018a900
/* DWARF original name: _M_insert_unique<std::pair<std::basic_string<char>, int> >
   DWARF original prototype:
   pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
   _M_insert_unique<std::pair<std::basic_string<char>,_int>_>(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int> * __v)
    */

pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
 __thiscall
std::
_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::_M_insert_unique<std::pair<std::basic_string<char>,_int>_>
          (_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           *this,pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                 *__v)

{
  void *__s1;
  void *pvVar1;
  void *__s2;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  void *__n;
  bool bVar5;
  int *piVar6;
  int iVar7;
  _Rb_tree_node_base *p_Var8;
  uint __n_00;
  void *in_EDX;
  void *extraout_EDX;
  undefined4 extraout_EDX_00;
  _Rb_tree_node_base *p_Var9;
  _Rb_tree_node_base *p_Var10;
  pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
  pVar11;
  pair<std::_Rb_tree_iterator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_bool>
  pVar12;
  _Rb_tree_color *in_stack_0000000c;
  
                    /* Unresolved local var:
                       pair<std::_Rb_tree_node_base*,_std::_Rb_tree_node_base*> __res@[???] */
  p_Var8 = (_Rb_tree_node_base *)__v[1].first._M_dataplus._M_p;
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
  piVar6 = &__v->second;
  p_Var9 = (_Rb_tree_node_base *)piVar6;
  if (p_Var8 == (_Rb_tree_node_base *)0x0) {
LAB_0018a9b0:
    if ((_Rb_tree_node_base *)__v[1].second != p_Var9) {
      p_Var10 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var9);
      __s1 = (void *)*in_stack_0000000c;
      __s2 = (void *)p_Var10[1]._M_color;
      pvVar1 = *(void **)((int)__s1 + -0xc);
      pvVar2 = *(void **)((int)__s2 + -0xc);
      in_EDX = __s1;
      __n = pvVar1;
      if (pvVar2 <= pvVar1) {
        __n = pvVar2;
      }
      goto joined_r0x0018a98d;
    }
  }
  else {
    __s1 = (void *)*in_stack_0000000c;
    pvVar1 = *(void **)((int)__s1 + -0xc);
    do {
      p_Var10 = p_Var8;
      __s2 = (void *)p_Var10[1]._M_color;
      pvVar2 = *(void **)((int)__s2 + -0xc);
      in_EDX = pvVar1;
      if (pvVar2 <= pvVar1) {
        in_EDX = pvVar2;
      }
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[DW_OP_reg0(EAX)] */
      if ((in_EDX == (void *)0x0) || (iVar7 = memcmp(__s1,__s2,(size_t)in_EDX), iVar7 == 0)) {
                    /* Unresolved local var: difference_type __d@[???] */
        iVar7 = (int)pvVar1 - (int)pvVar2;
        if (iVar7 < 0) goto LAB_0018a976;
LAB_0018a954:
        p_Var8 = p_Var10->_M_right;
      }
      else {
        if (-1 < iVar7) goto LAB_0018a954;
LAB_0018a976:
        p_Var8 = p_Var10->_M_left;
      }
    } while (p_Var8 != (_Base_ptr)0x0);
    p_Var9 = p_Var10;
    __n = in_EDX;
    if (iVar7 < 0) goto LAB_0018a9b0;
joined_r0x0018a98d:
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[DW_OP_reg0(EAX)] */
    if ((__n == (void *)0x0) ||
       (iVar7 = memcmp(__s2,__s1,(size_t)__n), in_EDX = extraout_EDX, iVar7 == 0)) {
                    /* Unresolved local var: difference_type __d@[???] */
      iVar7 = (int)pvVar2 - (int)pvVar1;
    }
    if (-1 < iVar7) goto LAB_0018a997;
  }
  if (p_Var9 != (_Rb_tree_node_base *)0x0) {
                    /* Unresolved local var: _Alloc_node __an@[???]
                       Unresolved local var: bool __insert_left@[???]
                       Unresolved local var: _Link_type __z@[???] */
    if ((_Rb_tree_node_base *)piVar6 == p_Var9) {
      bVar5 = true;
    }
    else {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[DW_OP_reg0(EAX)] */
      uVar3 = *(uint *)((int)p_Var9[1]._M_color + -0xc);
      uVar4 = *(uint *)((int)*in_stack_0000000c + -0xc);
      __n_00 = uVar3;
      if (uVar4 <= uVar3) {
        __n_00 = uVar4;
      }
      if ((__n_00 == 0) ||
         (iVar7 = memcmp((void *)*in_stack_0000000c,(void *)p_Var9[1]._M_color,__n_00), iVar7 == 0))
      {
                    /* Unresolved local var: difference_type __d@[???] */
        iVar7 = uVar4 - uVar3;
      }
      bVar5 = SUB41((uint)iVar7 >> 0x1f,0);
    }
                    /* Unresolved local var: _Link_type __tmp@[???] */
    p_Var8 = operator_new(0x18);
    if (p_Var8 != (_Rb_tree_node_base *)0xfffffff0) {
      p_Var8[1]._M_color = *in_stack_0000000c;
      *in_stack_0000000c = (_Rb_tree_color)&nothrow;
      p_Var8[1]._M_parent = (_Base_ptr)in_stack_0000000c[1];
    }
    std::_Rb_tree_insert_and_rebalance(bVar5,p_Var8,p_Var9,(_Rb_tree_node_base *)piVar6);
    __v[2].second = __v[2].second + 1;
    *(_Rb_tree_node_base **)&this->_M_impl = p_Var8;
    *(undefined1 *)&(this->_M_impl)._M_header._M_color = _S_black;
    pVar12._4_4_ = extraout_EDX_00;
    pVar12.first._M_node = (_Base_ptr)this;
    return pVar12;
  }
  p_Var10 = (_Rb_tree_node_base *)0x0;
LAB_0018a997:
  *(_Rb_tree_node_base **)&this->_M_impl = p_Var10;
  *(undefined1 *)&(this->_M_impl)._M_header._M_color = _S_red;
  pVar11._4_4_ = in_EDX;
  pVar11.first._M_node = (_Base_ptr)this;
  return pVar11;
}


