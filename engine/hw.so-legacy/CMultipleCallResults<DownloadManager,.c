// CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::GetCallbackSizeBytes  @ 00184f10
/* DWARF original prototype: int
   GetCallbackSizeBytes(CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t> * this) */

int __thiscall
CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::GetCallbackSizeBytes
          (CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t> *this)

{
  return 0x14;
}


// CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::Run  @ 00184ed0
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


// CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::Run  @ 00188b50
/* DWARF original prototype: void Run(CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>
   * this, void * pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) */

void __thiscall
CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t>::Run
          (CMultipleCallResults<DownloadManager,_HTTPRequestCompleted_t> *this,void *pvParam,
          bool bIOFailure,SteamAPICall_t hSteamAPICall)

{
  bool bVar1;
  DownloadManager *pDVar2;
  _func___thiscall_void_DownloadManager_ptr_HTTPRequestCompleted_t_ptr_bool *p_Var3;
  SteamAPICall_t local_14;
  
  local_14 = hSteamAPICall;
  bVar1 = CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
          ::Remove(&this->m_mapAPICalls,&local_14);
  if (bVar1) {
    p_Var3 = (this->m_Func).__pfn;
    pDVar2 = (DownloadManager *)
             ((int)&(this->m_pObj->m_HTTPRequestCompleted).super_CCallbackBase._vptr_CCallbackBase +
             (this->m_Func).__delta);
    if (((uint)p_Var3 & 1) != 0) {
      p_Var3 = *(_func___thiscall_void_DownloadManager_ptr_HTTPRequestCompleted_t_ptr_bool **)
                (p_Var3 + (int)(pDVar2->m_HTTPRequestCompleted).super_CCallbackBase.
                               _vptr_CCallbackBase + -1);
    }
    (*p_Var3)(pDVar2,pvParam,bIOFailure);
  }
  return;
}


