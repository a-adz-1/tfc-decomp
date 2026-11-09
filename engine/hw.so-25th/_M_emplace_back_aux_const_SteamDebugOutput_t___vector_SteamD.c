// std::vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>::_M_emplace_back_aux<const_SteamDebugOutput_t&>  @ 001320f0
/* WARNING: Removing unreachable block (ram,0x001321b1) */
/* WARNING: Removing unreachable block (ram,0x00132257) */
/* WARNING: Removing unreachable block (ram,0x00132265) */
/* WARNING: Removing unreachable block (ram,0x00132272) */
/* WARNING: Removing unreachable block (ram,0x00132250) */
/* WARNING: Removing unreachable block (ram,0x00132288) */
/* DWARF original name: _M_emplace_back_aux<const SteamDebugOutput_t&>
   DWARF original prototype: void
   _M_emplace_back_aux<const_SteamDebugOutput_t&>(vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>
   * this) */

void __thiscall
std::vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>::
_M_emplace_back_aux<const_SteamDebugOutput_t&>
          (vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_> *this)

{
  allocator *paVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  pointer pSVar6;
  undefined4 *puVar7;
  pointer pSVar8;
  pointer pSVar9;
  pointer pSVar10;
  pointer pSVar11;
  undefined4 *in_stack_00000008;
  uint local_38;
  pointer local_34;
  
                    /* Unresolved local var: size_type __len@[???]
                       Unresolved local var: pointer __new_start@[???]
                       Unresolved local var: pointer __new_finish@[???] */
  pSVar10 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
            _M_impl._M_finish;
  pSVar11 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
            _M_impl._M_start;
                    /* Unresolved local var: size_type __len@[???] */
  iVar5 = (int)pSVar10 - (int)pSVar11;
  local_38 = iVar5 >> 3;
  if (local_38 == 0) {
    local_38 = 8;
  }
  else {
    uVar4 = local_38 * 2;
    if ((uVar4 < local_38) || (0x1fffffff < uVar4)) {
      local_38 = 0xfffffff8;
    }
    else {
      if (uVar4 == 0) {
        pSVar6 = (pointer)0x0;
        local_38 = 0;
        goto LAB_0013213e;
      }
      local_38 = local_38 << 4;
    }
  }
  pSVar6 = operator_new(local_38);
  pSVar10 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
            _M_impl._M_finish;
  pSVar11 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
            _M_impl._M_start;
  iVar5 = (int)pSVar10 - (int)pSVar11;
LAB_0013213e:
  puVar7 = (undefined4 *)((int)&pSVar6->m_nType + iVar5);
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = *in_stack_00000008;
    std::string::string(puVar7 + 1,(string *)(in_stack_00000008 + 1));
    pSVar10 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
              _M_impl._M_finish;
    pSVar11 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
              _M_impl._M_start;
  }
                    /* Unresolved local var: bool __assignable@[???]
                       Unresolved local var: SteamDebugOutput_t * __cur@[???] */
  pSVar8 = pSVar11;
  pSVar9 = pSVar6;
  if (pSVar11 == pSVar10) {
    local_34 = pSVar6 + 1;
  }
  else {
    do {
      if (pSVar9 != (pointer)0x0) {
        pSVar9->m_nType = pSVar8->m_nType;
        (pSVar9->m_sMsg)._M_dataplus._M_p = (pSVar8->m_sMsg)._M_dataplus._M_p;
        (pSVar8->m_sMsg)._M_dataplus._M_p = (char *)&nothrow;
      }
      pSVar8 = pSVar8 + 1;
      pSVar9 = pSVar9 + 1;
    } while (pSVar8 != pSVar10);
    pSVar9 = pSVar11 + 1;
    pSVar10 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
              _M_impl._M_start;
    pSVar11 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
              _M_impl._M_finish;
    local_34 = (pointer)((int)&pSVar6[2].m_nType + ((int)pSVar8 - (int)pSVar9 & 0xfffffff8U));
    if (pSVar11 != pSVar10) {
      do {
        while( true ) {
          pcVar3 = (pSVar10->m_sMsg)._M_dataplus._M_p;
          paVar1 = (allocator *)(pcVar3 + -0xc);
          if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) break;
LAB_001321c0:
          pSVar10 = pSVar10 + 1;
          if (pSVar11 == pSVar10) goto LAB_00132200;
        }
        LOCK();
        piVar2 = (int *)(pcVar3 + -4);
        iVar5 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (0 < iVar5) goto LAB_001321c0;
        pSVar10 = pSVar10 + 1;
        std::string::_Rep::_M_destroy(paVar1);
      } while (pSVar11 != pSVar10);
LAB_00132200:
      pSVar11 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
                _M_impl._M_start;
    }
  }
  if (pSVar11 != (pointer)0x0) {
    operator_delete(pSVar11);
  }
  (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>)._M_impl.
  _M_start = pSVar6;
  (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>)._M_impl.
  _M_finish = local_34;
  (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>)._M_impl.
  _M_end_of_storage = (pointer)((int)&pSVar6->m_nType + local_38);
  return;
}


