// std::vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::_M_emplace_back_aux<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>  @ 0018b3d0
/* WARNING: Removing unreachable block (ram,0x0018b4a0) */
/* WARNING: Removing unreachable block (ram,0x0018b547) */
/* WARNING: Removing unreachable block (ram,0x0018b554) */
/* WARNING: Removing unreachable block (ram,0x0018b561) */
/* WARNING: Removing unreachable block (ram,0x0018b540) */
/* WARNING: Removing unreachable block (ram,0x0018b578) */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original name: _M_emplace_back_aux<std::pair<std::basic_string<char,
   std::char_traits<char>, std::allocator<char> >, int> >
   DWARF original prototype: void
   _M_emplace_back_aux<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>(vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this) */

void __thiscall
std::
vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::
_M_emplace_back_aux<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>
          (vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           *this)

{
  allocator *paVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  pointer ppVar5;
  pointer ppVar6;
  pointer ppVar7;
  int iVar8;
  undefined4 *puVar9;
  pointer ppVar10;
  uint uVar11;
  pointer ppVar12;
  undefined4 *in_stack_00000008;
  pointer local_38;
  pointer local_34;
  
                    /* Unresolved local var: size_type __len@[???]
                       Unresolved local var: pointer __new_start@[???]
                       Unresolved local var: pointer __new_finish@[???] */
  ppVar12 = (this->
            super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
            )._M_impl._M_finish;
  ppVar6 = (this->
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           )._M_impl._M_start;
                    /* Unresolved local var: size_type __len@[???] */
  iVar8 = (int)ppVar12 - (int)ppVar6;
  uVar11 = iVar8 >> 3;
  if (uVar11 == 0) {
    uVar11 = 8;
  }
  else {
    uVar4 = uVar11 * 2;
    if ((uVar4 < uVar11) || (0x1fffffff < uVar4)) {
      uVar11 = 0xfffffff8;
    }
    else {
      if (uVar4 == 0) {
        local_34 = (pointer)0x0;
        ppVar5 = (pointer)0x0;
        local_38 = (pointer)&DAT_00000008;
        goto LAB_0018b42d;
      }
      uVar11 = uVar11 << 4;
    }
  }
  ppVar5 = operator_new(uVar11);
  ppVar12 = (this->
            super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
            )._M_impl._M_finish;
  local_34 = (pointer)((int)&(ppVar5->first)._M_dataplus._M_p + uVar11);
  ppVar6 = (this->
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           )._M_impl._M_start;
  local_38 = ppVar5 + 1;
  iVar8 = (int)ppVar12 - (int)ppVar6;
LAB_0018b42d:
  puVar9 = (undefined4 *)((int)&(ppVar5->first)._M_dataplus._M_p + iVar8);
  if (puVar9 != (undefined4 *)0x0) {
    *puVar9 = *in_stack_00000008;
    *in_stack_00000008 = &nothrow;
    puVar9[1] = in_stack_00000008[1];
    ppVar12 = (this->
              super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
              )._M_impl._M_finish;
    ppVar6 = (this->
             super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
             )._M_impl._M_start;
  }
                    /* Unresolved local var: bool __assignable@[???]
                       Unresolved local var:
                       pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                       * __cur@[???] */
  ppVar7 = ppVar5;
  ppVar10 = ppVar6;
  if (ppVar12 != ppVar6) {
    do {
      if (ppVar7 != (pointer)0x0) {
        (ppVar7->first)._M_dataplus._M_p = (ppVar10->first)._M_dataplus._M_p;
        iVar8 = ppVar10->second;
        (ppVar10->first)._M_dataplus._M_p = (char *)&nothrow;
        ppVar7->second = iVar8;
      }
      ppVar10 = ppVar10 + 1;
      ppVar7 = ppVar7 + 1;
    } while (ppVar10 != ppVar12);
    ppVar7 = (this->
             super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
             )._M_impl._M_start;
    local_38 = (pointer)((int)&ppVar5[2].first._M_dataplus._M_p +
                        ((int)ppVar12 - (int)(ppVar6 + 1) & 0xfffffff8U));
    ppVar12 = (this->
              super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
              )._M_impl._M_finish;
    if (ppVar12 != ppVar7) {
      do {
        while( true ) {
          pcVar3 = (ppVar7->first)._M_dataplus._M_p;
          paVar1 = (allocator *)(pcVar3 + -0xc);
          if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) break;
LAB_0018b4a8:
          ppVar7 = ppVar7 + 1;
          if (ppVar12 == ppVar7) goto LAB_0018b4f0;
        }
        LOCK();
        piVar2 = (int *)(pcVar3 + -4);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (0 < iVar8) goto LAB_0018b4a8;
        ppVar7 = ppVar7 + 1;
        std::string::_Rep::_M_destroy(paVar1);
      } while (ppVar12 != ppVar7);
LAB_0018b4f0:
      ppVar12 = (this->
                super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                )._M_impl._M_start;
    }
  }
  if (ppVar12 != (pointer)0x0) {
    operator_delete(ppVar12);
  }
  (this->
  super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  )._M_impl._M_start = ppVar5;
  (this->
  super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  )._M_impl._M_finish = local_38;
  (this->
  super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  )._M_impl._M_end_of_storage = local_34;
  return;
}


