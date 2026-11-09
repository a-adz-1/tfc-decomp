// CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::GetCallbackSizeBytes  @ 00128390
/* DWARF original prototype: int
   GetCallbackSizeBytes(CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t> * this) */

int __thiscall
CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::GetCallbackSizeBytes
          (CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t> *this)

{
  return 0x18;
}


// CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::Run  @ 00128350
/* DWARF original prototype: void Run(CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>
   * this, void * pvParam) */

void __thiscall
CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::Run
          (CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t> *this,void *pvParam)

{
  DownloadManager *pDVar1;
  _func___thiscall_void_DownloadManager_ptr_HTTPRequestCompleted_t_ptr_bool *p_Var2;
  
  p_Var2 = (this->m_Func).__pfn;
  pDVar1 = (DownloadManager *)
           ((int)&(this->m_pObj->m_HTTPRequestCompleted).super_CCallbackBase._vptr_CCallbackBase +
           (this->m_Func).__delta);
  if (((uint)p_Var2 & 1) != 0) {
    p_Var2 = *(_func___thiscall_void_DownloadManager_ptr_HTTPRequestCompleted_t_ptr_bool **)
              (p_Var2 + (int)(pDVar1->m_HTTPRequestCompleted).super_CCallbackBase.
                             _vptr_CCallbackBase + -1);
  }
  (*p_Var2)(pDVar1,pvParam,false);
  return;
}


// CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::Run  @ 0012c140
/* WARNING: Variable defined which should be unmapped: node */
/* DWARF original prototype: void Run(CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>
   * this, void * pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) */

void __thiscall
CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::Run
          (CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t> *this,void *pvParam,
          bool bIOFailure,SteamAPICall_t hSteamAPICall)

{
  int *piVar1;
  bool bVar2;
  Node_t *pNVar3;
  int iVar4;
  DownloadManager *pDVar5;
  _func___thiscall_void_DownloadManager_ptr_HTTPRequestCompleted_t_ptr_bool *p_Var6;
  int elem;
  SteamAPICall_t local_24 [2];
  int node;
  
                    /* Unresolved local var: int current@[???] */
  elem = (this->m_mapAPICalls).m_Root;
  if (elem != -1) {
    pNVar3 = (this->m_mapAPICalls).m_Elements.m_pMemory;
    do {
      while( true ) {
        local_24[0] = hSteamAPICall;
        bVar2 = (*(this->m_mapAPICalls).m_LessFunc)(local_24,&pNVar3[elem].m_Data);
        if (bVar2) break;
        bVar2 = (*(this->m_mapAPICalls).m_LessFunc)
                          (&(this->m_mapAPICalls).m_Elements.m_pMemory[elem].m_Data,local_24);
        if (!bVar2) {
          CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
          ::Unlink(&this->m_mapAPICalls,elem);
          (this->m_mapAPICalls).m_Elements.m_pMemory[elem].super_Links_t.m_Left = elem;
          (this->m_mapAPICalls).m_Elements.m_pMemory[elem].super_Links_t.m_Right =
               (this->m_mapAPICalls).m_FirstFree;
          p_Var6 = (this->m_Func).__pfn;
          iVar4 = (this->m_Func).__delta;
          pDVar5 = this->m_pObj;
          piVar1 = &(this->m_mapAPICalls).m_NumElements;
          *piVar1 = *piVar1 + -1;
          (this->m_mapAPICalls).m_FirstFree = elem;
          pDVar5 = (DownloadManager *)
                   ((int)&(pDVar5->m_HTTPRequestCompleted).super_CCallbackBase._vptr_CCallbackBase +
                   iVar4);
          if (((uint)p_Var6 & 1) != 0) {
            p_Var6 = *(_func___thiscall_void_DownloadManager_ptr_HTTPRequestCompleted_t_ptr_bool **)
                      (p_Var6 + (int)(pDVar5->m_HTTPRequestCompleted).super_CCallbackBase.
                                     _vptr_CCallbackBase + -1);
          }
          (*p_Var6)(pDVar5,pvParam,bIOFailure);
          return;
        }
        hSteamAPICall = local_24[0];
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          hSteamAPICall = local_24[0];
          if (iVar4 != 0) {
            CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
            ::Links::s_Sentinel.m_Right = -1;
            CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
            ::Links::s_Sentinel.m_Left = -1;
            CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
            ::Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
            hSteamAPICall = local_24[0];
          }
        }
        pNVar3 = (this->m_mapAPICalls).m_Elements.m_pMemory;
        elem = pNVar3[elem].super_Links_t.m_Right;
        if (elem == -1) {
          return;
        }
      }
      hSteamAPICall = local_24[0];
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        hSteamAPICall = local_24[0];
        if (iVar4 != 0) {
          CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
          ::Links::s_Sentinel.m_Left = -1;
          CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
          ::Links::s_Sentinel.m_Right = -1;
          CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
          ::Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          hSteamAPICall = local_24[0];
        }
      }
      pNVar3 = (this->m_mapAPICalls).m_Elements.m_pMemory;
      elem = pNVar3[elem].super_Links_t.m_Left;
    } while (elem != -1);
  }
  return;
}


