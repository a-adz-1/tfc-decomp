// Steam_Activate  @ 000bda20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_Activate(void)

{
  CSteam3Server *this;
  
  if (s_Steam3Server == (CSteam3Server *)0x0) {
    this = operator_new(0xc0);
    CSteam3Server::CSteam3Server(this);
    s_Steam3Server = this;
  }
  CSteam3Server::Activate(s_Steam3Server);
  return;
}


// Steam_ActivateInputSet  @ 000be170
void Steam_ActivateInputSet(bool bInMenu)

{
  CSteam3Client::ActivateInputSet(&s_Steam3Client,bInMenu);
  return;
}


// Steam_ClientRunFrame  @ 000bdc90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_ClientRunFrame(void)

{
  SteamAPI_RunCallbacks();
  return;
}


// Steam_GSBLoggedOn  @ 000be320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Steam_GSBLoggedOn(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((s_Steam3Server->super_CSteam3).m_bLoggedOn == false) {
    return 0;
  }
  puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x20))((int *)*puVar1);
  return uVar2 & 0xff;
}


// Steam_GSBSecure  @ 000be300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Steam_GSBSecure(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1);
  return uVar2 & 0xff;
}


// Steam_GSBSecurePreference  @ 000be350
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Steam_GSBSecurePreference(void)

{
  return (uint)s_Steam3Server->m_bWantToBeSecure;
}


// Steam_GSGetSteamID  @ 000be2d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint64 Steam_GSGetSteamID(void)

{
  if (s_Steam3Server->m_bLanOnly != false) {
    return 0x100000000000000;
  }
  return (s_Steam3Server->m_SteamIDGS).m_steamid.m_unAll64Bits;
}


// Steam_GSInitiateGameConnection  @ 000bdda0
int Steam_GSInitiateGameConnection
              (void *pData,int cbMaxData,uint64 steamID,uint32 unIPServer,uint16 usPortServer,
              qboolean bSecure)

{
  int iVar1;
  undefined2 uVar2;
  netadr_t adr;
  uint64 uVar3;
  short sVar4;
  int32 iVar5;
  undefined4 *puVar6;
  int iVar7;
  qboolean qVar8;
  int iVar9;
  uint16 auVar10 [1];
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  int in_GS_OFFSET;
  byte bVar14;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  bVar14 = 0;
                    /* Unresolved local var: netadr_t.conflict server_adr@[???]
                       Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  uVar11 = unIPServer >> 0x18 | (unIPServer & 0xff0000) >> 8 | (unIPServer & 0xff00) << 8 |
           unIPServer << 0x18;
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
  auVar10[0] = usPortServer >> 8 | usPortServer << 8;
  iVar5 = (*BigLong)(uVar11);
  sVar4 = (*BigShort)(auVar10[0]);
  if ((g_nFakeIP == 0) ||
     (adr.ip[0] = (char)iVar5, adr.ip[1] = (char)((uint)iVar5 >> 8),
     adr.ip[2] = (char)((uint)iVar5 >> 0x10), adr.ip[3] = (char)((uint)iVar5 >> 0x18), adr.type = 3,
     adr.ipx._0_4_ = local_2c, adr.ipx._4_4_ = local_28, adr.ipx[8] = (undefined1)local_24,
     adr.ipx[9] = local_24._1_1_, adr.port = sVar4, qVar8 = NET_IsLocalAddress(adr), qVar8 == false)
     ) {
    if (g_nCurrentGameConnectionIP != uVar11) goto LAB_000bde31;
LAB_000bdf8e:
    if (((g_nCurrentGameConnectionPort != auVar10[0]) || (steamID != g_currentGameConnectionSteamID)
        ) || ((bSecure != 0) != CSteam3Client::InitiateGameConnection::g_currentGameConnectionSecure
             )) goto LAB_000bde31;
  }
  else {
    uVar11 = g_nFakeIP;
    auVar10[0] = g_arFakePorts[0];
    if (g_nCurrentGameConnectionIP == g_nFakeIP) goto LAB_000bdf8e;
LAB_000bde31:
    if ((g_nCurrentGameConnectionIP != 0) || (g_nCurrentGameConnectionPort != 0)) {
      puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar6 + 0x10))
                ((int *)*puVar6,g_nCurrentGameConnectionIP,g_nCurrentGameConnectionPort);
    }
    CSteam3Client::InitiateGameConnection::g_currentGameConnectionSecure = bSecure != 0;
    g_nCurrentGameConnectionPort = auVar10[0];
    g_nCurrentGameConnectionIP = uVar11;
    g_currentGameConnectionSteamID = steamID;
    puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    CSteam3Client::InitiateGameConnection::g_cbCurrentGameConnectionBlob =
         (**(code **)(*(int *)*puVar6 + 0xc))
                   ((int *)*puVar6,
                    CSteam3Client::InitiateGameConnection::g_currentGameConnectionBlob,0x400,
                    g_currentGameConnectionSteamID,g_nCurrentGameConnectionIP,
                    g_nCurrentGameConnectionPort,
                    CSteam3Client::InitiateGameConnection::g_currentGameConnectionSecure);
  }
  iVar7 = CSteam3Client::InitiateGameConnection::g_cbCurrentGameConnectionBlob;
  if (cbMaxData < CSteam3Client::InitiateGameConnection::g_cbCurrentGameConnectionBlob) {
    iVar7 = 0;
    uVar3 = g_currentGameConnectionSteamID;
  }
  else {
    pcVar12 = CSteam3Client::InitiateGameConnection::g_currentGameConnectionBlob;
    iVar9 = CSteam3Client::InitiateGameConnection::g_cbCurrentGameConnectionBlob;
    if (7 < (uint)CSteam3Client::InitiateGameConnection::g_cbCurrentGameConnectionBlob) {
      pcVar13 = pData;
      if (((uint)pData & 1) != 0) {
        pcVar13 = (char *)((int)pData + 1);
        pcVar12 = CSteam3Client::InitiateGameConnection::g_currentGameConnectionBlob + 1;
        iVar9 = CSteam3Client::InitiateGameConnection::g_cbCurrentGameConnectionBlob + -1;
        *(char *)pData = CSteam3Client::InitiateGameConnection::g_currentGameConnectionBlob[0];
      }
      pData = pcVar13;
      if (((uint)pcVar13 & 2) != 0) {
        uVar2 = *(undefined2 *)pcVar12;
        pData = pcVar13 + 2;
        pcVar12 = pcVar12 + 2;
        iVar9 = iVar9 + -2;
        *(undefined2 *)pcVar13 = uVar2;
      }
      if (((uint)pData & 4) != 0) {
        *(undefined4 *)pData = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = (char *)((int)pData + 4);
        for (iVar9 = iVar9 + -4; uVar3 = g_currentGameConnectionSteamID, iVar9 != 0;
            iVar9 = iVar9 + -1) {
          *pcVar13 = *pcVar12;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar14 * -2 + 1;
        }
        goto LAB_000bded3;
      }
    }
    for (; uVar3 = g_currentGameConnectionSteamID, iVar9 != 0; iVar9 = iVar9 + -1) {
      *(char *)pData = *pcVar12;
      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
      pData = (char *)((int)pData + (uint)bVar14 * -2 + 1);
    }
  }
LAB_000bded3:
  g_currentGameConnectionSteamID._4_4_ = (undefined4)(uVar3 >> 0x20);
  g_currentGameConnectionSteamID._0_4_ = (undefined4)uVar3;
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
    g_currentGameConnectionSteamID = uVar3;
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}


// Steam_GSSteamIDIsValidOrLAN  @ 000be410
qboolean Steam_GSSteamIDIsValidOrLAN(uint64 uSteamId)

{
  byte bVar1;
  
                    /* Unresolved local var: CSteamID steamId@[???] */
  bVar1 = (byte)(uSteamId >> 0x30) & 0xf0;
  if ((((uSteamId & 0xf0000000000000) != 0) && (((byte)(uSteamId._4_4_ >> 0x14) & 0xf) < 0xb)) &&
     ((byte)((char)(uSteamId >> 0x38) - 1U) < 4)) {
    if (bVar1 == 0x10) {
      if (((int)uSteamId != 0) && ((uSteamId._4_4_ & 0xfffff) == 1)) {
        return 1;
      }
    }
    else if (bVar1 == 0x70) {
      if (((int)uSteamId != 0) && ((uSteamId & 0xfffff00000000) == 0)) {
        return 1;
      }
    }
    else {
      if (bVar1 != 0x30) {
        return 1;
      }
      if ((int)uSteamId != 0) {
        return 1;
      }
    }
  }
  return (uint)(uSteamId == 0x100000000000000);
}


// Steam_GSTerminateGameConnection  @ 000be040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_GSTerminateGameConnection(void)

{
  undefined4 *puVar1;
  
  if (g_nCurrentGameConnectionIP != 0) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0x10))
              ((int *)*puVar1,g_nCurrentGameConnectionIP,g_nCurrentGameConnectionPort);
    g_nCurrentGameConnectionIP = 0;
    g_nCurrentGameConnectionPort = 0;
    g_currentGameConnectionSteamID._0_4_ = 0;
    g_currentGameConnectionSteamID._4_4_ = 0;
  }
  puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar1 + 0x50))((int *)*puVar1,0,0,0,0);
  g_szRichPresenceNiceMap[0] = '\0';
  g_szRichPresenceOverride[0] = '\0';
  g_szRichPresenceGameMode[0] = '\0';
  return;
}


// Steam_GetCommunityName  @ 000bc760
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Steam_GetCommunityName(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  piVar1 = (int *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
  if (*piVar1 == 0) {
    pcVar3 = (char *)0x0;
  }
  else {
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
    pcVar3 = (char *)(*(code *)**(undefined4 **)*puVar2)((undefined4 *)*puVar2);
  }
  return pcVar3;
}


// Steam_GetGSUniverse  @ 000be4a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Steam_GetGSUniverse(void)

{
  char *pcVar1;
  char cVar2;
  
                    /* Unresolved local var: CSteamID steamID@[???] */
  cVar2 = '\x01';
  if (s_Steam3Server->m_bLanOnly == false) {
    cVar2 = (char)((uint)*(undefined4 *)((int)&(s_Steam3Server->m_SteamIDGS).m_steamid + 4) >> 0x18)
    ;
  }
  pcVar1 = "(u)";
  if ((byte)(cVar2 - 1U) < 3) {
    pcVar1 = (&CSWTCH_337)[(byte)(cVar2 - 1U)];
  }
  return pcVar1;
}


// Steam_HandleIncomingPacket  @ 000be6b0
void Steam_HandleIncomingPacket(byte *data,int len,int fromip,uint16 port)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar1 + 0x88))((int *)*puVar1,data,len,fromip,port);
  return;
}


// Steam_InitClient  @ 000bdca0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_InitClient(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  FILE *__stream;
  
  if (s_Steam3Client.super_CSteam3.m_bLoggedOn) {
    return;
  }
  s_Steam3Client.super_CSteam3.m_bLoggedOn = true;
  unlink("steam_appid.txt");
  pcVar2 = getenv("SteamAppId");
  if (pcVar2 == (char *)0x0) {
                    /* Unresolved local var: int nAppID@[???] */
    iVar5 = GetGameAppID();
    if (0 < iVar5) {
                    /* Unresolved local var: FILE * f@[???] */
      __stream = fopen("steam_appid.txt","w+");
      if (__stream != (FILE *)0x0) {
        __fprintf_chk(__stream,1,"%d\n",iVar5);
        fclose(__stream);
      }
    }
  }
  cVar1 = SteamAPI_Init();
  if (cVar1 == '\0') {
    Sys_Error("Failed to initalize authentication interface. Exiting...\n");
  }
  else {
    piVar3 = (int *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
    if (*piVar3 != 0) {
      puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
      (*(code *)**(undefined4 **)*puVar4)((undefined4 *)*puVar4,0);
    }
    s_Steam3Client.super_CSteam3.m_bLogOnResult = false;
  }
  return;
}


// Steam_NotifyBotConnect  @ 000bd830
qboolean Steam_NotifyBotConnect(client_t_conflict *cl)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14 [4];
  
  if (((s_Steam3Server != (CSteam3Server *)0x0) && (cl != (client_t_conflict *)0x0)) &&
     ((s_Steam3Server->super_CSteam3).m_bLoggedOn != false)) {
    (cl->network_userid).idtype = 3;
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0x9c))(local_14,(int *)*puVar1);
    *(undefined4 *)&(cl->network_userid).m_SteamID = local_18;
    *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4) = local_14[0];
    return 1;
  }
  return 0;
}


// Steam_NotifyClientConnect  @ 000bd770
qboolean Steam_NotifyClientConnect(client_t_conflict *cl,void *pvSteam2Key,uint ucbSteam2Key)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: CSteamID steamIDClient@[???]
                       Unresolved local var: bool bRet@[???] */
  if (((s_Steam3Server != (CSteam3Server *)0x0) && (cl != (client_t_conflict *)0x0)) &&
     ((s_Steam3Server->super_CSteam3).m_bLoggedOn != false)) {
                    /* Unresolved local var: CSteamID steamIDClient@[???]
                       Unresolved local var: bool bRet@[???] */
    (cl->network_userid).idtype = 1;
    local_14 = 0;
    local_10 = 0;
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
    uVar2 = (cl->network_userid).clientip;
    uVar2 = (**(code **)(*(int *)*puVar1 + 0x98))
                      ((int *)*puVar1,
                       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                       uVar2 << 0x18,pvSteam2Key,ucbSteam2Key,&local_14);
    *(undefined4 *)&(cl->network_userid).m_SteamID = local_14;
    *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4) = local_10;
    return uVar2 & 0xff;
  }
  return 0;
}


// Steam_NotifyClientDisconnect  @ 000bd8b0
void Steam_NotifyClientDisconnect(client_t_conflict *cl)

{
  undefined4 *puVar1;
  
  if ((((s_Steam3Server != (CSteam3Server *)0x0) && (cl != (client_t_conflict *)0x0)) &&
      ((s_Steam3Server->super_CSteam3).m_bLoggedOn != false)) &&
     (((cl->network_userid).idtype & 0xfffffffdU) == 1)) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0xa0))
              ((int *)*puVar1,(int)(cl->network_userid).m_SteamID,
               *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4));
    return;
  }
  return;
}


// Steam_NotifyOfLevelChange  @ 000bd920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_NotifyOfLevelChange(void)

{
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    CSteam3Server::NotifyOfLevelChange(s_Steam3Server,false);
  }
  return;
}


// Steam_ProcessInsecureLaunchParameters  @ 000be4e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_ProcessInsecureLaunchParameters(void)

{
  undefined4 *puVar1;
  size_t size;
  char *pchUnsafeCmdLine;
  int cubSize;
  
  if ((cls.state != ca_dedicated) &&
     (!Steam_ProcessInsecureLaunchParameters::s_bProcessedCommandLine)) {
                    /* Unresolved local var: int nBytes@[???]
                       Unresolved local var: char * szCmdLine@[???]
                       Unresolved local var: int nBytesWritten@[???] */
    Steam_ProcessInsecureLaunchParameters::s_bProcessedCommandLine = true;
    Con_Printf("OnNewUrlLaunchParameters\n");
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
    size = (**(code **)(*(int *)*puVar1 + 0x68))((int *)*puVar1,0,0);
    pchUnsafeCmdLine = Mem_ZeroMalloc(size);
    if (pchUnsafeCmdLine != (char *)0x0) {
      puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar1 + 0x68))((int *)*puVar1,pchUnsafeCmdLine,size);
      UnsafeCmdLineProcessor(pchUnsafeCmdLine,cubSize);
      Mem_Free(pchUnsafeCmdLine);
    }
    return;
  }
  return;
}


// Steam_RunFrame  @ 000bda90
/* WARNING: Removing unreachable block (ram,0x000bdb2a) */
/* WARNING: Removing unreachable block (ram,0x000bdc10) */
/* WARNING: Removing unreachable block (ram,0x000bdc1e) */
/* WARNING: Removing unreachable block (ram,0x000bdbd8) */
/* WARNING: Removing unreachable block (ram,0x000bdbe5) */
/* WARNING: Removing unreachable block (ram,0x000bdc00) */
/* WARNING: Removing unreachable block (ram,0x000bdc25) */
/* WARNING: Removing unreachable block (ram,0x000bdc07) */
/* WARNING: Removing unreachable block (ram,0x000bdc3e) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_RunFrame(void)

{
  allocator *paVar1;
  int *piVar2;
  char *pcVar3;
  pointer pSVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  pointer pSVar8;
  pointer pSVar9;
  mutex *this;
  undefined4 in_stack_ffffffc8;
  undefined4 uStack_34;
  
                    /* Unresolved local var: int __e@[???] */
  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&g_SteamDebugOutputMutex);
  pSVar4 = g_SteamDebugOutputQueue.
           super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
           _M_finish;
  if (iVar5 != 0) {
    std::__throw_system_error(iVar5);
    if (s_Steam3Server != (CSteam3Server *)0x0) {
      puVar7 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar7 + 0x50))((int *)*puVar7,in_stack_ffffffc8,uStack_34);
    }
    return;
  }
                    /* Unresolved local var: SteamDebugOutput_t * debugOutput@[???]
                       Unresolved local var:
                       vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_> *
                       __for_range@[???]
                       Unresolved local var: iterator __for_begin@[???]
                       Unresolved local var: iterator __for_end@[???] */
  pSVar8 = g_SteamDebugOutputQueue.
           super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
           _M_start;
  if (g_SteamDebugOutputQueue.
      super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl._M_start
      != g_SteamDebugOutputQueue.
         super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
         _M_finish) {
LAB_000bdadf:
    do {
      if (pSVar8->m_nType <
          (k_ESteamNetworkingSocketsDebugOutputType_Everything|
          k_ESteamNetworkingSocketsDebugOutputType_Bug)) {
        uVar6 = 1 << ((byte)pSVar8->m_nType & 0x1f);
        if ((uVar6 & 0x1e8) != 0) {
          pSVar9 = pSVar8 + 1;
          Con_DPrintf("[SteamNetworkingSockets] %s\n",(pSVar8->m_sMsg)._M_dataplus._M_p);
          pSVar8 = pSVar9;
          if (pSVar4 == pSVar9) break;
          goto LAB_000bdadf;
        }
        if ((uVar6 & 0x16) != 0) {
          Con_Printf("[SteamNetworkingSockets] %s\n",(pSVar8->m_sMsg)._M_dataplus._M_p);
          Log_Printf("[SteamNetworkingSockets] %s\n",(pSVar8->m_sMsg)._M_dataplus._M_p);
        }
      }
      pSVar8 = pSVar8 + 1;
    } while (pSVar4 != pSVar8);
    pSVar8 = g_SteamDebugOutputQueue.
             super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
             _M_finish;
    pSVar4 = g_SteamDebugOutputQueue.
             super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
             _M_start;
    pSVar9 = g_SteamDebugOutputQueue.
             super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
             _M_start;
    if (g_SteamDebugOutputQueue.
        super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl._M_start
        != g_SteamDebugOutputQueue.
           super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
           _M_finish) {
      do {
        while( true ) {
          pcVar3 = (pSVar9->m_sMsg)._M_dataplus._M_p;
          paVar1 = (allocator *)(pcVar3 + -0xc);
          if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) break;
LAB_000bdb30:
          pSVar9 = pSVar9 + 1;
          if (pSVar9 == pSVar8) goto LAB_000bdb70;
        }
        LOCK();
        piVar2 = (int *)(pcVar3 + -4);
        iVar5 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (0 < iVar5) goto LAB_000bdb30;
        pSVar9 = pSVar9 + 1;
        std::string::_Rep::_M_destroy(paVar1);
      } while (pSVar9 != pSVar8);
LAB_000bdb70:
      g_SteamDebugOutputQueue.
      super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl._M_finish
           = pSVar4;
      pSVar4 = g_SteamDebugOutputQueue.
               super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
               _M_finish;
    }
  }
  g_SteamDebugOutputQueue.
  super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl._M_finish =
       pSVar4;
  this = &g_SteamDebugOutputMutex;
  pthread_mutex_unlock((pthread_mutex_t *)&g_SteamDebugOutputMutex);
                    /* Unresolved local var: double fCurTime@[???] */
  if ((s_Steam3Server != (CSteam3Server *)0x0) && (1 < svs.maxclients)) {
    CSteam3Server::RunFrame((CSteam3Server *)this);
  }
  return;
}


// Steam_SetCVar  @ 000bdc50
void Steam_SetCVar(char *pchKey,char *pchValue)

{
  undefined4 *puVar1;
  
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0x50))((int *)*puVar1,pchKey,pchValue);
  }
  return;
}


// Steam_SetRichPresenceGameMode  @ 000be230
void Steam_SetRichPresenceGameMode(char *pszString)

{
  g_szRichPresenceGameMode[0] = '\0';
  if ((pszString != (char *)0x0) && (*pszString != '\0')) {
    Q_strncpy_s(g_szRichPresenceGameMode,pszString,0x20);
  }
  return;
}


// Steam_SetRichPresenceInfo  @ 000be1b0
void Steam_SetRichPresenceInfo(char *pszNiceMapName)

{
  g_szRichPresenceNiceMap[0] = '\0';
  if ((pszNiceMapName != (char *)0x0) && (*pszNiceMapName != '\0')) {
    Q_strncpy_s(g_szRichPresenceNiceMap,pszNiceMapName,0x20);
  }
  return;
}


// Steam_SetRichPresenceOverride  @ 000be1f0
void Steam_SetRichPresenceOverride(char *pszString)

{
  g_szRichPresenceOverride[0] = '\0';
  if ((pszString != (char *)0x0) && (*pszString != '\0')) {
    Q_strncpy_s(g_szRichPresenceOverride,pszString,0x80);
  }
  return;
}


// Steam_ShowOnScreenKeyboard  @ 000be270
void Steam_ShowOnScreenKeyboard(int fieldX,int fieldY)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = (int *)SteamInternal_ContextInit(SteamUtils::s_CallbackCounterAndContext);
  if (*piVar1 != 0) {
                    /* Unresolved local var: int nWidth@[???]
                       Unresolved local var: int nHeight@[???] */
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamUtils::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar2 + 0x8c))((int *)*puVar2,0,0,0,0x500,fieldY + 0x24);
  }
  return;
}


// Steam_Shutdown  @ 000bd940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_Shutdown(void)

{
  CSteam3Server *pCVar1;
  _func_int_varargs **pp_Var2;
  undefined4 *puVar3;
  
  pCVar1 = s_Steam3Server;
  if (s_Steam3Server == (CSteam3Server *)0x0) {
    return;
  }
  pp_Var2 = (s_Steam3Server->super_CSteam3)._vptr_CSteam3;
  if (pp_Var2[2] == CSteam3Server::Shutdown) {
    if ((s_Steam3Server->super_CSteam3).m_bLoggedOn == false) goto LAB_000bd965;
    NET_InternalOpenOrCloseFakeUDPPorts(false,false);
    puVar3 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar3 + 0x60))((int *)*puVar3,0);
    puVar3 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar3 + 0x1c))((int *)*puVar3);
    SteamGameServer_Shutdown();
                    /* Unresolved local var: int i@[???] */
    (pCVar1->super_CSteam3).m_bLoggedOn = false;
    g_arFakePorts[0] = 0;
    g_nFakeIP = 0;
    if (ip_sockets[1] != 0) {
      NET_GetLocalAddress();
    }
  }
  else {
    (*pp_Var2[2])(s_Steam3Server);
  }
  if (s_Steam3Server == (CSteam3Server *)0x0) {
    s_Steam3Server = (CSteam3Server *)0x0;
    return;
  }
  pp_Var2 = (s_Steam3Server->super_CSteam3)._vptr_CSteam3;
LAB_000bd965:
  (*pp_Var2[1])(s_Steam3Server);
  s_Steam3Server = (CSteam3Server *)0x0;
  return;
}


// Steam_ShutdownClient  @ 000be0e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_ShutdownClient(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (!s_Steam3Client.super_CSteam3.m_bLoggedOn) {
    return;
  }
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
  piVar1 = (int *)SteamInternal_ContextInit
                            (SteamNetworkingSockets_SteamAPI::s_CallbackCounterAndContext);
  if ((*piVar1 != 0) && (ip_fakeudpports[0] != (ISteamNetworkingFakeUDPPort *)0x0)) {
    (*(code *)**(undefined4 **)ip_fakeudpports[0])(ip_fakeudpports[0]);
    ip_fakeudpports[0] = (ISteamNetworkingFakeUDPPort *)0x0;
  }
  piVar1 = (int *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
  if (*piVar1 != 0) {
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
    (**(code **)(*(int *)*puVar2 + 4))((int *)*puVar2);
  }
  iVar3 = (*eng->_vptr_IEngine[0x10])(eng);
  if (iVar3 == 1) {
    SteamAPI_Shutdown();
  }
  s_Steam3Client.super_CSteam3.m_bLoggedOn = false;
  return;
}


// Steam_Steam3IDtoSteam2  @ 000be360
TSteamGlobalUserID_conflict *
Steam_Steam3IDtoSteam2(TSteamGlobalUserID_conflict *__return_storage_ptr__,uint64 unSteamID)

{
                    /* Unresolved local var: CSteamID steamID@[???] */
                    /* Unresolved local var: TSteamGlobalUserID.conflict steamGlobalUserID@[???] */
  __return_storage_ptr__->m_SteamInstanceID = 0;
  (__return_storage_ptr__->m_SteamLocalUserID).Split.High32bits = (uint)unSteamID & 1;
  (__return_storage_ptr__->m_SteamLocalUserID).Split.Low32bits = (uint)unSteamID >> 1;
  return __return_storage_ptr__;
}


// Steam_StringToSteamID  @ 000be380
uint64 Steam_StringToSteamID(char *pStr)

{
  uint uVar1;
  SteamID_t local_14 [2];
  
                    /* Unresolved local var: CSteamID steamID@[???] */
  local_14[0].m_comp.m_unAccountID = 0;
  local_14[0].m_unAll64Bits._4_2_ = 0;
  local_14[0].m_unAll64Bits._6_1_ = 0;
  local_14[0].m_comp.m_EUniverse = 0;
  if (s_Steam3Server == (CSteam3Server *)0x0) {
    SteamIDFromSteam2String(pStr,k_EUniversePublic,(CSteamID *)&local_14[0].m_comp);
  }
  else {
    uVar1 = 0x1000000;
    if (s_Steam3Server->m_bLanOnly == false) {
      uVar1 = *(uint *)((int)&(s_Steam3Server->m_SteamIDGS).m_steamid + 4);
    }
    SteamIDFromSteam2String(pStr,uVar1 >> 0x18,(CSteamID *)&local_14[0].m_comp);
  }
  return CONCAT17(local_14[0].m_comp.m_EUniverse,
                  CONCAT16(local_14[0].m_unAll64Bits._6_1_,
                           CONCAT24(local_14[0].m_unAll64Bits._4_2_,local_14[0].m_comp.m_unAccountID
                                   )));
}


// Steam_UpdateRichPresence  @ 000be190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_UpdateRichPresence(void)

{
  CSteam3Client::UpdateRichPresence(&s_Steam3Client);
  return;
}


