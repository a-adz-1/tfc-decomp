// std::_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::_M_erase  @ 0018acb0
/* WARNING: Removing unreachable block (ram,0x0018b1f7) */
/* WARNING: Removing unreachable block (ram,0x0018afa2) */
/* WARNING: Removing unreachable block (ram,0x0018ad59) */
/* WARNING: Removing unreachable block (ram,0x0018ae9e) */
/* WARNING: Removing unreachable block (ram,0x0018aebe) */
/* WARNING: Removing unreachable block (ram,0x0018aecb) */
/* WARNING: Removing unreachable block (ram,0x0018aee9) */
/* WARNING: Removing unreachable block (ram,0x0018ae90) */
/* WARNING: Removing unreachable block (ram,0x0018aef0) */
/* WARNING: Removing unreachable block (ram,0x0018af09) */
/* WARNING: Removing unreachable block (ram,0x0018af1c) */
/* WARNING: Removing unreachable block (ram,0x0018b1a1) */
/* WARNING: Removing unreachable block (ram,0x0018b205) */
/* WARNING: Removing unreachable block (ram,0x0018b0cf) */
/* WARNING: Removing unreachable block (ram,0x0018b1af) */
/* WARNING: Removing unreachable block (ram,0x0018b196) */
/* DWARF original prototype: void
   _M_erase(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, _Link_type __x) */

void __thiscall
std::
_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::_M_erase(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           *this,_Link_type __x)

{
  int *piVar1;
  _Base_ptr p_Var2;
  _Base_ptr p_Var3;
  _Base_ptr p_Var4;
  _Base_ptr p_Var5;
  _Base_ptr p_Var6;
  _Base_ptr p_Var7;
  int iVar8;
  _Link_type p_Var9;
  _Base_ptr p_Var10;
  _Rb_tree_color _Var11;
  allocator *paVar12;
  _Base_ptr p_Var13;
  _Base_ptr p_Var14;
  
  do {
    if (__x == (_Link_type)0x0) {
      return;
    }
    p_Var10 = (__x->super__Rb_tree_node_base)._M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
    while (p_Var10 != (_Base_ptr)0x0) {
      p_Var7 = p_Var10->_M_right;
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
                p_Var14 = p_Var3->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
                if (p_Var14 != (_Base_ptr)0x0) {
                  p_Var13 = p_Var14->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
                  if (p_Var13 == (_Base_ptr)0x0) goto LAB_0018adea;
LAB_0018ad6e:
                  do {
                    _M_erase(this,(_Link_type)p_Var13->_M_right);
                    p_Var2 = p_Var13->_M_left;
                    paVar12 = (allocator *)(p_Var13[1]._M_color - 0xc);
                    if (paVar12 == (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
LAB_0018ad60:
                    /* Unresolved local var: _Link_type __y@[???] */
                      operator_delete(p_Var13);
                    }
                    else {
                      LOCK();
                      piVar1 = (int *)(p_Var13[1]._M_color - 4);
                      iVar8 = *piVar1;
                      *piVar1 = *piVar1 + -1;
                      UNLOCK();
                      if (0 < iVar8) goto LAB_0018ad60;
                      std::string::_Rep::_M_destroy(paVar12);
                      operator_delete(p_Var13);
                    }
                    p_Var13 = p_Var2;
                    if (p_Var2 == (_Base_ptr)0x0) {
                      _Var11 = p_Var14[1]._M_color;
                      p_Var13 = p_Var14->_M_left;
                      paVar12 = (allocator *)(_Var11 - 0xc);
                      if (paVar12 != (allocator *)&std::string::_Rep::_S_empty_rep_storage)
                      goto LAB_0018ae08;
                      do {
                        operator_delete(p_Var14);
                        p_Var14 = p_Var13;
                        while( true ) {
                          if (p_Var14 == (_Base_ptr)0x0) goto LAB_0018ae40;
                          p_Var13 = p_Var14->_M_right;
                          if (p_Var13 != (_Base_ptr)0x0) goto LAB_0018ad6e;
LAB_0018adea:
                          _Var11 = p_Var14[1]._M_color;
                          p_Var13 = p_Var14->_M_left;
                          paVar12 = (allocator *)(_Var11 - 0xc);
                          if (paVar12 == (allocator *)&std::string::_Rep::_S_empty_rep_storage)
                          break;
LAB_0018ae08:
                          LOCK();
                          piVar1 = (int *)(_Var11 - 4);
                          iVar8 = *piVar1;
                          *piVar1 = *piVar1 + -1;
                          UNLOCK();
                          if (0 < iVar8) break;
                          std::string::_Rep::_M_destroy(paVar12);
                          operator_delete(p_Var14);
                          p_Var14 = p_Var13;
                        }
                      } while( true );
                    }
                  } while( true );
                }
LAB_0018ae40:
                p_Var14 = p_Var3->_M_left;
                paVar12 = (allocator *)(p_Var3[1]._M_color - 0xc);
                if (paVar12 == (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
LAB_0018ae59:
                  operator_delete(p_Var3);
                  p_Var3 = p_Var14;
                }
                else {
                  LOCK();
                  piVar1 = (int *)(p_Var3[1]._M_color - 4);
                  iVar8 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (0 < iVar8) goto LAB_0018ae59;
                  std::string::_Rep::_M_destroy(paVar12);
                  operator_delete(p_Var3);
                  p_Var3 = p_Var14;
                }
              }
              p_Var3 = p_Var4->_M_left;
              paVar12 = (allocator *)(p_Var4[1]._M_color - 0xc);
              if (paVar12 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
                piVar1 = (int *)(p_Var4[1]._M_color - 4);
                LOCK();
                iVar8 = *piVar1;
                *piVar1 = *piVar1 + -1;
                UNLOCK();
                if (iVar8 < 1) {
                  std::string::_Rep::_M_destroy(paVar12);
                }
              }
              operator_delete(p_Var4);
              p_Var4 = p_Var3;
            }
            p_Var4 = p_Var5->_M_left;
            paVar12 = (allocator *)(p_Var5[1]._M_color - 0xc);
            if (paVar12 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
              piVar1 = (int *)(p_Var5[1]._M_color - 4);
              LOCK();
              iVar8 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar8 < 1) {
                std::string::_Rep::_M_destroy(paVar12);
              }
            }
            operator_delete(p_Var5);
            p_Var5 = p_Var4;
          }
          p_Var5 = p_Var6->_M_left;
          paVar12 = (allocator *)(p_Var6[1]._M_color - 0xc);
          if (paVar12 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            piVar1 = (int *)(p_Var6[1]._M_color - 4);
            LOCK();
            iVar8 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar8 < 1) {
              std::string::_Rep::_M_destroy(paVar12);
            }
          }
          operator_delete(p_Var6);
          p_Var6 = p_Var5;
        }
        p_Var6 = p_Var7->_M_left;
        paVar12 = (allocator *)(p_Var7[1]._M_color - 0xc);
        if (paVar12 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          piVar1 = (int *)(p_Var7[1]._M_color - 4);
          LOCK();
          iVar8 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar8 < 1) {
            std::string::_Rep::_M_destroy(paVar12);
          }
        }
        operator_delete(p_Var7);
        p_Var7 = p_Var6;
      }
      p_Var7 = p_Var10->_M_left;
      paVar12 = (allocator *)(p_Var10[1]._M_color - 0xc);
      if (paVar12 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        piVar1 = (int *)(p_Var10[1]._M_color - 4);
        LOCK();
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar8 < 1) {
          std::string::_Rep::_M_destroy(paVar12);
        }
      }
      operator_delete(p_Var10);
      p_Var10 = p_Var7;
    }
    iVar8 = *(int *)(__x->_M_storage)._M_storage;
    p_Var9 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    paVar12 = (allocator *)(iVar8 + -0xc);
    if (paVar12 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      piVar1 = (int *)(iVar8 + -4);
      LOCK();
      iVar8 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar8 < 1) {
        std::string::_Rep::_M_destroy(paVar12);
      }
    }
    operator_delete(__x);
    __x = p_Var9;
  } while( true );
}


