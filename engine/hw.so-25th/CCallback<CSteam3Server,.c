// CCallback<CSteam3Server,_GSClientApprove_t,_true>::Run  @ 001311e0
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
                    /* WARNING: Could not recover jumptable at 0x00131206. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback  @ 001314f0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientApprove_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientApprove_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<16>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<16>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002630a4;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback  @ 00131510
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientApprove_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientApprove_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientApprove_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<16>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<16>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002630a4;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_GSClientDeny_t,_true>::Run  @ 001311a0
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
                    /* WARNING: Could not recover jumptable at 0x001311c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback  @ 00131730
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientDeny_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientDeny_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<140>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<140>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002630dc;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback  @ 00131750
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientDeny_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientDeny_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientDeny_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<140>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<140>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002630dc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_GSClientKick_t,_true>::Run  @ 00131160
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
                    /* WARNING: Could not recover jumptable at 0x00131186. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback  @ 00131780
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientKick_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientKick_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<12>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<12>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_00263114;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback  @ 001317a0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSClientKick_t,_true> * this,
   int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSClientKick_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSClientKick_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<12>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<12>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_00263114;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::Run  @ 00131130
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
                    /* WARNING: Could not recover jumptable at 0x00131156. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback  @ 001313b0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_0026314c;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback  @ 001313d0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *
   this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_GSPolicyResponse_t,_true>::~CCallback
          (CCallback<CSteam3Server,_GSPolicyResponse_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_0026314c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::Run  @ 00131090
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
                    /* WARNING: Could not recover jumptable at 0x001310b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::~CCallback  @ 001317d0
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
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002631d8;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::~CCallback  @ 001317f0
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
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002631d8;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::Run  @ 001310d0
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
                    /* WARNING: Could not recover jumptable at 0x001310f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback  @ 001315e0
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<8>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<8>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002631a0;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback  @ 00131600
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServerConnectFailure_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
                    /* try { // try from 00131604 to 00141608 has its CatchHandler @ 001315d0 */
  bVar1 = (this->super_CCallbackImpl<8>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<8>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002631a0;
  if ((bVar1 & 1) != 0) {
                    /* try { // try from 00131614 to 00141828 has its CatchHandler @ 00131937 */
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CCallback<CSteam3Server,_SteamServersConnected_t,_true>::Run  @ 00131100
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
                    /* WARNING: Could not recover jumptable at 0x00131126. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback  @ 00131400
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_SteamServersConnected_t,_true>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServersConnected_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_0026314c;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback  @ 00131420
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Server,_SteamServersConnected_t,_true>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Server,_SteamServersConnected_t,_true>::~CCallback
          (CCallback<CSteam3Server,_SteamServersConnected_t,_true> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<1>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<1>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_0026314c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


