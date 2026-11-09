// std::_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::_M_erase  @ 001dee70
/* WARNING: Removing unreachable block (ram,0x001df0c7) */
/* WARNING: Removing unreachable block (ram,0x001df2dd) */
/* WARNING: Removing unreachable block (ram,0x001df0bc) */
/* WARNING: Removing unreachable block (ram,0x001def20) */
/* WARNING: Removing unreachable block (ram,0x001df1a8) */
/* WARNING: Removing unreachable block (ram,0x001df215) */
/* WARNING: Removing unreachable block (ram,0x001df222) */
/* WARNING: Removing unreachable block (ram,0x001df1c8) */
/* WARNING: Removing unreachable block (ram,0x001df20c) */
/* WARNING: Removing unreachable block (ram,0x001df1d4) */
/* WARNING: Removing unreachable block (ram,0x001df266) */
/* WARNING: Removing unreachable block (ram,0x001df326) */
/* WARNING: Removing unreachable block (ram,0x001df136) */
/* WARNING: Removing unreachable block (ram,0x001df2cf) */
/* WARNING: Removing unreachable block (ram,0x001df31b) */
/* DWARF original prototype: void
   _M_erase(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, _Link_type __x) */

void __thiscall
std::
_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::_M_erase(_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           *this,_Link_type __x)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  _Base_ptr p_Var4;
  _Base_ptr p_Var5;
  _Base_ptr p_Var6;
  _Base_ptr p_Var7;
  _Base_ptr p_Var8;
  _Base_ptr p_Var9;
  _Link_type p_Var10;
  char *pcVar11;
  _Base_ptr p_Var12;
  _Base_ptr p_Var13;
  _Base_ptr p_Var14;
  
  while (__x != (_Link_type)0x0) {
    p_Var14 = (__x->super__Rb_tree_node_base)._M_right;
                    /* Unresolved local var: _Link_type __y@[DW_OP_reg3(EBX)] */
    while (p_Var14 != (_Base_ptr)0x0) {
      p_Var13 = p_Var14->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
      while (p_Var13 != (_Base_ptr)0x0) {
        p_Var12 = p_Var13->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
        while (p_Var12 != (_Base_ptr)0x0) {
          p_Var9 = p_Var12->_M_right;
                    /* Unresolved local var: _Link_type __y@[???] */
          while (p_Var9 != (_Base_ptr)0x0) {
            p_Var8 = p_Var9->_M_right;
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
                    /* Unresolved local var: _Link_type __y@[???] */
                    _M_erase(this,(_Link_type)p_Var5->_M_right);
                    p_Var4 = p_Var5->_M_left;
                    paVar1 = (allocator *)(p_Var5[1]._M_color - 0xc);
                    if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
                      LOCK();
                      piVar2 = (int *)(p_Var5[1]._M_color - 4);
                      iVar3 = *piVar2;
                      *piVar2 = *piVar2 + -1;
                      UNLOCK();
                      if (iVar3 < 1) {
                        std::string::_Rep::_M_destroy(paVar1);
                      }
                    }
                    operator_delete(p_Var5);
                    p_Var5 = p_Var4;
                  }
                  p_Var5 = p_Var6->_M_left;
                  paVar1 = (allocator *)(p_Var6[1]._M_color - 0xc);
                  if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
                    LOCK();
                    piVar2 = (int *)(p_Var6[1]._M_color - 4);
                    iVar3 = *piVar2;
                    *piVar2 = *piVar2 + -1;
                    UNLOCK();
                    if (iVar3 < 1) {
                      std::string::_Rep::_M_destroy(paVar1);
                    }
                  }
                  operator_delete(p_Var6);
                  p_Var6 = p_Var5;
                }
                p_Var6 = p_Var7->_M_left;
                paVar1 = (allocator *)(p_Var7[1]._M_color - 0xc);
                if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
                  LOCK();
                  piVar2 = (int *)(p_Var7[1]._M_color - 4);
                  iVar3 = *piVar2;
                  *piVar2 = *piVar2 + -1;
                  UNLOCK();
                  if (iVar3 < 1) {
                    std::string::_Rep::_M_destroy(paVar1);
                  }
                }
                operator_delete(p_Var7);
                p_Var7 = p_Var6;
              }
              p_Var7 = p_Var8->_M_left;
              paVar1 = (allocator *)(p_Var8[1]._M_color - 0xc);
              if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
                LOCK();
                piVar2 = (int *)(p_Var8[1]._M_color - 4);
                iVar3 = *piVar2;
                *piVar2 = *piVar2 + -1;
                UNLOCK();
                if (iVar3 < 1) {
                  std::string::_Rep::_M_destroy(paVar1);
                }
              }
              operator_delete(p_Var8);
              p_Var8 = p_Var7;
            }
            p_Var8 = p_Var9->_M_left;
            paVar1 = (allocator *)(p_Var9[1]._M_color - 0xc);
            if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
              LOCK();
              piVar2 = (int *)(p_Var9[1]._M_color - 4);
              iVar3 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
              if (iVar3 < 1) {
                std::string::_Rep::_M_destroy(paVar1);
              }
            }
            operator_delete(p_Var9);
            p_Var9 = p_Var8;
          }
          p_Var9 = p_Var12->_M_left;
          paVar1 = (allocator *)(p_Var12[1]._M_color - 0xc);
          if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            LOCK();
            piVar2 = (int *)(p_Var12[1]._M_color - 4);
            iVar3 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if (iVar3 < 1) {
              std::string::_Rep::_M_destroy(paVar1);
            }
          }
          operator_delete(p_Var12);
          p_Var12 = p_Var9;
        }
        p_Var12 = p_Var13->_M_left;
        paVar1 = (allocator *)(p_Var13[1]._M_color - 0xc);
        if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          LOCK();
          piVar2 = (int *)(p_Var13[1]._M_color - 4);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 < 1) {
            std::string::_Rep::_M_destroy(paVar1);
          }
        }
        operator_delete(p_Var13);
        p_Var13 = p_Var12;
      }
      p_Var13 = p_Var14->_M_left;
      paVar1 = (allocator *)(p_Var14[1]._M_color - 0xc);
      if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)(p_Var14[1]._M_color - 4);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          std::string::_Rep::_M_destroy(paVar1);
        }
      }
      operator_delete(p_Var14);
      p_Var14 = p_Var13;
    }
    p_Var10 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    pcVar11 = (__x->_M_value_field).first._M_dataplus._M_p;
    paVar1 = (allocator *)(pcVar11 + -0xc);
    if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar2 = (int *)(pcVar11 + -4);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 < 1) {
        std::string::_Rep::_M_destroy(paVar1);
      }
    }
    operator_delete(__x);
    __x = p_Var10;
  }
  return;
}


