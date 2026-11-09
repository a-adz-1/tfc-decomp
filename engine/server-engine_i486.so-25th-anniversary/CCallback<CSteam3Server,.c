// CCallback<CSteam3Server,_GSClientApprove_t,_true>::Run  @ 000beaa0
/* DWARF original prototype: void Run(CCallback<CSteam3Server,_GSClientApprove_t,_true> * this, void
   * pvParam) */

void __thiscall
CCallback<CSteam3Server,_GSClientApprove_t,_true>::Run
          (CCallback<CSteam3Server,_GSClientApprove_t,_true> *this,void *pvParam)

{
  CSteam3Server *pCVar1;
  _func___thiscall_void_CSteam3Server_ptr_GSClientApprove_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Server *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Server_ptr_GSClientApprove_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000beac6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback  @ 000bedb0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientApprove_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientApprove_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<16>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<16>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de624;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback  @ 000bedd0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientApprove_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientApprove_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<16>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<16>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de624;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_GSClientDeny_t,_true>::Run  @ 000bea60
/* DWARF original prototype: void Run(CCallback<CSteam3Server,_GSClientDeny_t,_true> * this, void *
   pvParam) */

void __thiscall
CCallback<CSteam3Server,_GSClientDeny_t,_true>::Run
          (CCallback<CSteam3Server,_GSClientDeny_t,_true> *this,void *pvParam)

{
  CSteam3Server *pCVar1;
  _func___thiscall_void_CSteam3Server_ptr_GSClientDeny_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Server *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Server_ptr_GSClientDeny_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000bea86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback  @ 000beff0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientDeny_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientDeny_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<140>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<140>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de65c;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback  @ 000bf010
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientDeny_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientDeny_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<140>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<140>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de65c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_GSClientKick_t,_true>::Run  @ 000bea20
/* DWARF original prototype: void Run(CCallback<CSteam3Server,_GSClientKick_t,_true> * this, void *
   pvParam) */

void __thiscall
CCallback<CSteam3Server,_GSClientKick_t,_true>::Run
          (CCallback<CSteam3Server,_GSClientKick_t,_true> *this,void *pvParam)

{
  CSteam3Server *pCVar1;
  _func___thiscall_void_CSteam3Server_ptr_GSClientKick_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Server *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Server_ptr_GSClientKick_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000bea46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback  @ 000bf040
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientKick_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientKick_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<12>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<12>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de694;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback  @ 000bf060
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientKick_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientKick_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<12>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<12>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de694;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::Run  @ 000be9f0
/* DWARF original prototype: void Run(CCallback<CSteam3Server,_GSPolicyResponse_t,_true> * this,
   void * pvParam) */

void __thiscall
CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::Run
          (CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *this,void *pvParam)

{
  CSteam3Server *pCVar1;
  _func___thiscall_void_CSteam3Server_ptr_GSPolicyResponse_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Server *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Server_ptr_GSPolicyResponse_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000bea16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback  @ 000bec70
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback  @ 000bec90
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::Run  @ 000be950
/* DWARF original prototype: void Run(CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>
   * this, void * pvParam) */

void __thiscall
CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::Run
          (CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true> *this,void *pvParam)

{
  CSteam3Server *pCVar1;
  _func___thiscall_void_CSteam3Server_ptr_SteamNetworkingFakeIPResult_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Server *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Server_ptr_SteamNetworkingFakeIPResult_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000be976. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::~CCallback  @ 000bf090
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true> * this, int __in_chrg)
    */

void __thiscall
CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<160>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<160>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de758;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::~CCallback  @ 000bf0b0
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true> * this, int __in_chrg)
    */

void __thiscall
CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<160>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<160>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de758;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::Run  @ 000be990
/* DWARF original prototype: void Run(CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> *
   this, void * pvParam) */

void __thiscall
CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::Run
          (CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> *this,void *pvParam)

{
  CSteam3Server *pCVar1;
  _func___thiscall_void_CSteam3Server_ptr_SteamServerConnectFailure_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Server *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Server_ptr_SteamServerConnectFailure_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000be9b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback  @ 000beea0
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<8>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<8>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de720;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback  @ 000beec0
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<8>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<8>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de720;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_SteamServersConnected_t,_true>::Run  @ 000be9c0
/* DWARF original prototype: void Run(CCallback<CSteam3Server,_SteamServersConnected_t,_true> *
   this, void * pvParam) */

void __thiscall
CCallback<CSteam3Server,_SteamServersConnected_t,_true>::Run
          (CCallback<CSteam3Server,_SteamServersConnected_t,_true> *this,void *pvParam)

{
  CSteam3Server *pCVar1;
  _func___thiscall_void_CSteam3Server_ptr_SteamServersConnected_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Server *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Server_ptr_SteamServersConnected_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000be9e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback  @ 000becc0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_SteamServersConnected_t,_true>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServersConnected_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback  @ 000bece0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_SteamServersConnected_t,_true>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServersConnected_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


