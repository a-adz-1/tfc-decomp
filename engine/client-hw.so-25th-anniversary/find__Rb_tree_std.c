// std::_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::find  @ 0018a720
/* DWARF original prototype: iterator
   find(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, basic_string<char,_std::char_traits<char>,_std::allocator<char>_> * __k) */

iterator __thiscall
std::
_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::find(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
       *this,basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *__k)

{
  basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *pbVar1;
  basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *pbVar2;
  void *__s2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *pbVar8;
  undefined4 *in_stack_0000000c;
  basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *local_24;
  
                    /* Unresolved local var: iterator __j@[???] */
  pbVar2 = (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)
           __k[2]._M_dataplus._M_p;
  pbVar1 = __k + 1;
  if (pbVar2 != (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)0x0) {
    __s2 = (void *)*in_stack_0000000c;
    uVar3 = *(uint *)((int)__s2 + -0xc);
    local_24 = pbVar1;
    do {
      while( true ) {
        pbVar8 = pbVar2;
        pcVar4 = pbVar8[4]._M_dataplus._M_p;
        uVar5 = *(uint *)(pcVar4 + -0xc);
        uVar7 = uVar3;
        if (uVar5 <= uVar3) {
          uVar7 = uVar5;
        }
        if (uVar7 == 0) break;
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[DW_OP_reg0(EAX)] */
        iVar6 = memcmp(pcVar4,__s2,uVar7);
        if (iVar6 == 0) break;
        if (-1 < iVar6) goto LAB_0018a768;
LAB_0018a78c:
        pbVar2 = (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)
                 pbVar8[3]._M_dataplus._M_p;
        if (pbVar2 == (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)0x0)
        goto LAB_0018a793;
      }
                    /* Unresolved local var: difference_type __d@[???] */
      if ((int)(uVar5 - uVar3) < 0) goto LAB_0018a78c;
LAB_0018a768:
      pbVar2 = (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)
               pbVar8[2]._M_dataplus._M_p;
      local_24 = pbVar8;
    } while (pbVar2 != (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)0x0);
LAB_0018a793:
    if (local_24 == pbVar1) goto LAB_0018a7e8;
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[DW_OP_reg0(EAX)] */
    pcVar4 = local_24[4]._M_dataplus._M_p;
    uVar5 = *(uint *)(pcVar4 + -0xc);
    uVar7 = uVar5;
    if (uVar3 <= uVar5) {
      uVar7 = uVar3;
    }
    if (uVar7 != 0) {
      iVar6 = memcmp(__s2,pcVar4,uVar7);
      if (iVar6 != 0) {
        if (iVar6 < 0) goto LAB_0018a7e8;
        goto LAB_0018a7b8;
      }
    }
                    /* Unresolved local var: difference_type __d@[???] */
    if (-1 < (int)(uVar3 - uVar5)) {
LAB_0018a7b8:
      *(basic_string<char,_std::char_traits<char>,_std::allocator<char>_> **)&this->_M_impl =
           local_24;
      return (iterator)(_Base_ptr)this;
    }
  }
LAB_0018a7e8:
  *(basic_string<char,_std::char_traits<char>,_std::allocator<char>_> **)&this->_M_impl = pbVar1;
  return (iterator)(_Base_ptr)this;
}


