// CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>::Run  @ 000be900
/* DWARF original prototype: void Run(CCallback<CSteam3Client,_ClientGameServerDeny_t,_false> *
   this, void * pvParam) */

void __thiscall
CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>::Run
          (CCallback<CSteam3Client,_ClientGameServerDeny_t,_false> *this,void *pvParam)

{
  CSteam3Client *pCVar1;
  _func___thiscall_void_CSteam3Client_ptr_ClientGameServerDeny_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Client *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Client_ptr_ClientGameServerDeny_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000be926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>::~CCallback  @ 000bee00
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>::~CCallback
          (CCallback<CSteam3Client,_ClientGameServerDeny_t,_false> *this,int __in_chrg)

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


// CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>::~CCallback  @ 000bee20
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Client,_ClientGameServerDeny_t,_false>::~CCallback
          (CCallback<CSteam3Client,_ClientGameServerDeny_t,_false> *this,int __in_chrg)

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


// CCallback<CSteam3Client,_GameOverlayActivated_t,_false>::Run  @ 000be870
/* DWARF original prototype: void Run(CCallback<CSteam3Client,_GameOverlayActivated_t,_false> *
   this, void * pvParam) */

void __thiscall
CCallback<CSteam3Client,_GameOverlayActivated_t,_false>::Run
          (CCallback<CSteam3Client,_GameOverlayActivated_t,_false> *this,void *pvParam)

{
  CSteam3Client *pCVar1;
  _func___thiscall_void_CSteam3Client_ptr_GameOverlayActivated_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Client *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Client_ptr_GameOverlayActivated_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000be896. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Client,_GameOverlayActivated_t,_false>::~CCallback  @ 000beef0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Client,_GameOverlayActivated_t,_false>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Client,_GameOverlayActivated_t,_false>::~CCallback
          (CCallback<CSteam3Client,_GameOverlayActivated_t,_false> *this,int __in_chrg)

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


// CCallback<CSteam3Client,_GameOverlayActivated_t,_false>::~CCallback  @ 000befc0
/* DWARF original prototype: void ~CCallback(CCallback<CSteam3Client,_GameOverlayActivated_t,_false>
   * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Client,_GameOverlayActivated_t,_false>::~CCallback
          (CCallback<CSteam3Client,_GameOverlayActivated_t,_false> *this,int __in_chrg)

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


// CCallback<CSteam3Client,_GameServerChangeRequested_t,_false>::Run  @ 000be8c0
/* DWARF original prototype: void Run(CCallback<CSteam3Client,_GameServerChangeRequested_t,_false> *
   this, void * pvParam) */

void __thiscall
CCallback<CSteam3Client,_GameServerChangeRequested_t,_false>::Run
          (CCallback<CSteam3Client,_GameServerChangeRequested_t,_false> *this,void *pvParam)

{
  CSteam3Client *pCVar1;
  _func___thiscall_void_CSteam3Client_ptr_GameServerChangeRequested_t_ptr *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_Func).__pfn;
  pCVar1 = (CSteam3Client *)
           ((int)&(this->m_pObj->super_CSteam3)._vptr_CSteam3 + (this->m_Func).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(_func___thiscall_void_CSteam3Client_ptr_GameServerChangeRequested_t_ptr **)
          (UNRECOVERED_JUMPTABLE + (int)(pCVar1->super_CSteam3)._vptr_CSteam3 + -1);
  }
                    /* WARNING: Could not recover jumptable at 0x000be8e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pCVar1,pvParam);
  return;
}


// CCallback<CSteam3Client,_GameServerChangeRequested_t,_false>::~CCallback  @ 000bee50
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Client,_GameServerChangeRequested_t,_false> * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Client,_GameServerChangeRequested_t,_false>::~CCallback
          (CCallback<CSteam3Client,_GameServerChangeRequested_t,_false> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<128>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<128>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de7ac;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CCallback<CSteam3Client,_GameServerChangeRequested_t,_false>::~CCallback  @ 000bee70
/* DWARF original prototype: void
   ~CCallback(CCallback<CSteam3Client,_GameServerChangeRequested_t,_false> * this, int __in_chrg) */

void __thiscall
CCallback<CSteam3Client,_GameServerChangeRequested_t,_false>::~CCallback
          (CCallback<CSteam3Client,_GameServerChangeRequested_t,_false> *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<128>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<128>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de7ac;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


