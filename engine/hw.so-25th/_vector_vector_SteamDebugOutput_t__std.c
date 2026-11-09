// std::vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>::~vector  @ 00131b10
/* WARNING: Removing unreachable block (ram,0x00131b2d) */
/* WARNING: Removing unreachable block (ram,0x00131bc7) */
/* WARNING: Removing unreachable block (ram,0x00131ba0) */
/* WARNING: Removing unreachable block (ram,0x00131bad) */
/* WARNING: Removing unreachable block (ram,0x00131bc0) */
/* DWARF original prototype: void
   ~vector(vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_> * this, int __in_chrg) */

void __thiscall
std::vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>::~vector
          (vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_> *this,int __in_chrg)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  pointer pSVar5;
  pointer pSVar6;
  
  pSVar6 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
           _M_impl._M_finish;
  pSVar5 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
           _M_impl._M_start;
  if (pSVar6 != pSVar5) {
    do {
      while( true ) {
        pcVar4 = (pSVar5->m_sMsg)._M_dataplus._M_p;
        paVar1 = (allocator *)(pcVar4 + -0xc);
        if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) break;
LAB_00131b38:
        pSVar5 = pSVar5 + 1;
        if (pSVar6 == pSVar5) goto LAB_00131b80;
      }
      LOCK();
      piVar2 = (int *)(pcVar4 + -4);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (0 < iVar3) goto LAB_00131b38;
      pSVar5 = pSVar5 + 1;
      std::string::_Rep::_M_destroy(paVar1);
    } while (pSVar6 != pSVar5);
LAB_00131b80:
    pSVar6 = (this->super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>).
             _M_impl._M_start;
  }
  if (pSVar6 != (pointer)0x0) {
    operator_delete(pSVar6);
  }
  return;
}


