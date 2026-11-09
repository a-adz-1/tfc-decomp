// CSteam3Client::CCallbackInternal_OnGameRichPresenceJoinRequested::Run  @ 000bf1f0
/* DWARF original prototype: void Run(CCallbackInternal_OnGameRichPresenceJoinRequested * this, void
   * pvParam) */

void __thiscall
CSteam3Client::CCallbackInternal_OnGameRichPresenceJoinRequested::Run
          (CCallbackInternal_OnGameRichPresenceJoinRequested *this,void *pvParam)

{
  int cubSize;
  
                    /* Unresolved local var: CSteam3Client * pOuter@[???] */
                    /* Unresolved local var: char * szConCommand@[???] */
  Con_Printf("OnGameRichPresenceJoinRequested\n");
  if ((pvParam != (void *)0x0) && (*(char *)((int)pvParam + 8) != '\0')) {
    UnsafeCmdLineProcessor((char *)((int)pvParam + 8),cubSize);
    return;
  }
  return;
}


// CSteam3Client::CCallbackInternal_OnGameRichPresenceJoinRequested::~CCallbackInternal_OnGameRichPresenceJoinRequested  @ 000bed60
/* DWARF original prototype: void
   ~CCallbackInternal_OnGameRichPresenceJoinRequested(CCallbackInternal_OnGameRichPresenceJoinRequested
   * this, int __in_chrg) */

void __thiscall
CSteam3Client::CCallbackInternal_OnGameRichPresenceJoinRequested::
~CCallbackInternal_OnGameRichPresenceJoinRequested
          (CCallbackInternal_OnGameRichPresenceJoinRequested *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<264>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<264>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de81c;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CSteam3Client::CCallbackInternal_OnGameRichPresenceJoinRequested::~CCallbackInternal_OnGameRichPresenceJoinRequested  @ 000bed80
/* DWARF original prototype: void
   ~CCallbackInternal_OnGameRichPresenceJoinRequested(CCallbackInternal_OnGameRichPresenceJoinRequested
   * this, int __in_chrg) */

void __thiscall
CSteam3Client::CCallbackInternal_OnGameRichPresenceJoinRequested::
~CCallbackInternal_OnGameRichPresenceJoinRequested
          (CCallbackInternal_OnGameRichPresenceJoinRequested *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->super_CCallbackImpl<264>).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CCallbackImpl<264>).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de81c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(this);
  }
  operator_delete(this);
  return;
}


// CSteam3Client::CCallbackInternal_OnNewUrlLaunchParameters::Run  @ 000bf660
/* DWARF original prototype: void Run(CCallbackInternal_OnNewUrlLaunchParameters * this, void *
   pvParam) */

void __thiscall
CSteam3Client::CCallbackInternal_OnNewUrlLaunchParameters::Run
          (CCallbackInternal_OnNewUrlLaunchParameters *this,void *pvParam)

{
  undefined4 *puVar1;
  size_t size;
  char *pchUnsafeCmdLine;
  int cubSize;
  
                    /* Unresolved local var: CSteam3Client * pOuter@[???] */
                    /* Unresolved local var: int nBytes@[???]
                       Unresolved local var: char * szCmdLine@[???]
                       Unresolved local var: int nBytesWritten@[???] */
  Con_Printf("OnNewUrlLaunchParameters\n");
  puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
  size = (**(code **)(*(int *)*puVar1 + 0x68))((int *)*puVar1,0,0);
  pchUnsafeCmdLine = Mem_ZeroMalloc(size);
  if (pchUnsafeCmdLine != (char *)0x0) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0x68))((int *)*puVar1,pchUnsafeCmdLine,size);
    UnsafeCmdLineProcessor(pchUnsafeCmdLine,cubSize);
    Mem_Free(pchUnsafeCmdLine);
    return;
  }
  return;
}


// CSteam3Client::CCallbackInternal_OnNewUrlLaunchParameters::~CCallbackInternal_OnNewUrlLaunchParameters  @ 000bed10
/* DWARF original prototype: void
   ~CCallbackInternal_OnNewUrlLaunchParameters(CCallbackInternal_OnNewUrlLaunchParameters * this,
   int __in_chrg) */

void __thiscall
CSteam3Client::CCallbackInternal_OnNewUrlLaunchParameters::
~CCallbackInternal_OnNewUrlLaunchParameters
          (CCallbackInternal_OnNewUrlLaunchParameters *this,int __in_chrg)

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


// CSteam3Client::CCallbackInternal_OnNewUrlLaunchParameters::~CCallbackInternal_OnNewUrlLaunchParameters  @ 000bed30
/* DWARF original prototype: void
   ~CCallbackInternal_OnNewUrlLaunchParameters(CCallbackInternal_OnNewUrlLaunchParameters * this,
   int __in_chrg) */

void __thiscall
CSteam3Client::CCallbackInternal_OnNewUrlLaunchParameters::
~CCallbackInternal_OnNewUrlLaunchParameters
          (CCallbackInternal_OnNewUrlLaunchParameters *this,int __in_chrg)

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


