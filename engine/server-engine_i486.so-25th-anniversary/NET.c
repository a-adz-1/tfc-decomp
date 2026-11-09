// NET_AddToLagged  @ 000afc20
void NET_AddToLagged(netsrc_t sock,packetlag_t *pList,packetlag_t *pPacket,netadr_t *net_from,
                    sizebuf_t messagedata,float timestamp)

{
  uchar *dest;
  
                    /* Unresolved local var: uchar * pStart@[???] */
  if ((pPacket->pPrev == (packetlag_s *)0x0) && (pPacket->pNext == (packetlag_s *)0x0)) {
    pPacket->pPrev = pList->pPrev;
    pList->pPrev->pNext = pPacket;
    pList->pPrev = pPacket;
    pPacket->pNext = pList;
    dest = Mem_Malloc(messagedata.cursize);
    pPacket->pPacketData = dest;
    Q_memcpy(dest,messagedata.data,messagedata.cursize);
    pPacket->nSize = messagedata.cursize;
    pPacket->receivedTime = timestamp;
    (pPacket->net_from).type = net_from->type;
    *(undefined4 *)(pPacket->net_from).ip = *(undefined4 *)net_from->ip;
    *(undefined4 *)(pPacket->net_from).ipx = *(undefined4 *)net_from->ipx;
    *(undefined4 *)((pPacket->net_from).ipx + 4) = *(undefined4 *)(net_from->ipx + 4);
    *(undefined4 *)((pPacket->net_from).ipx + 8) = *(undefined4 *)(net_from->ipx + 8);
    return;
  }
  Con_Printf("Packet already linked\n");
  return;
}


// NET_AdjustLag  @ 000afcf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_AdjustLag(void)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  
                    /* Unresolved local var: double dt@[???]
                       Unresolved local var: float diff@[???]
                       Unresolved local var: float converge@[???] */
  lVar3 = (longdouble)realtime - (longdouble)NET_AdjustLag::lasttime;
  if (lVar3 < (longdouble)0) {
    lVar3 = (longdouble)0;
  }
  else if ((longdouble)0.1 < lVar3) {
    lVar3 = (longdouble)0.1;
  }
  NET_AdjustLag::lasttime = realtime;
  if ((sv_cheats.value == 0.0) && (fakelag.value != 0.0)) {
                    /* Unresolved local var: double dt@[???]
                       Unresolved local var: float diff@[???]
                       Unresolved local var: float converge@[???] */
    Con_Printf("Server must enable cheats to activate fakelag\n");
    Cvar_SetValue("fakelag",0.0);
    gFakeLag = 0.0;
    return;
  }
  if (gFakeLag != fakelag.value) {
    fVar1 = ABS(fakelag.value - gFakeLag);
    fVar2 = (float)(lVar3 * (longdouble)200.0);
    if (fVar1 < (float)(lVar3 * (longdouble)200.0)) {
      fVar2 = fVar1;
    }
    if (fakelag.value - gFakeLag < 0.0) {
      fVar2 = -fVar2;
    }
    gFakeLag = fVar2 + gFakeLag;
  }
  return;
}


// NET_AdrToString  @ 000af550
char * NET_AdrToString(netadr_t a)

{
  Q_memset(NET_AdrToString::s,0,0x40);
  if (a.type == NA_LOOPBACK) {
    builtin_strncpy(NET_AdrToString::s,"loopback",9);
  }
  else if (a.type == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
    __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",a.ip[0],a.ip[1],a.ip[2],a.ip[3],
                   a.port >> 8 | a.port << 8);
  }
  return NET_AdrToString::s;
}


// NET_AllocMsg  @ 000b0e70
net_messages_t * NET_AllocMsg(int size)

{
  net_messages_t *pnVar1;
  uchar *puVar2;
  
                    /* Unresolved local var: net_messages_t * pmsg@[???] */
  if ((size < 0x601) && (pnVar1 = normalqueue, normalqueue != (net_messages_t *)0x0)) {
    normalqueue->buffersize = size;
    normalqueue = normalqueue->next;
    return pnVar1;
  }
                    /* Unresolved local var: uchar * pbuffer@[???] */
  pnVar1 = Mem_ZeroMalloc(0x24);
                    /* Unresolved local var: uchar * pbuffer@[DW_OP_reg0(EAX)] */
  puVar2 = Mem_ZeroMalloc(size);
  pnVar1->buffersize = size;
  pnVar1->preallocated = false;
  pnVar1->buffer = puVar2;
  return pnVar1;
}


// NET_AllocateQueues  @ 000b1260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_AllocateQueues(void)

{
  net_messages_t *pnVar1;
  uchar *puVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: net_messages_t * p@[???] */
  iVar3 = 0x28;
  do {
    pnVar1 = Mem_ZeroMalloc(0x24);
    puVar2 = Mem_ZeroMalloc(0x600);
    iVar3 = iVar3 + -1;
    pnVar1->preallocated = true;
    pnVar1->buffer = puVar2;
    pnVar1->next = normalqueue;
    normalqueue = pnVar1;
  } while (iVar3 != 0);
  if ((use_thread != 0) && (net_thread_initialized == false)) {
    net_thread_initialized = true;
    return;
  }
  return;
}


// NET_BaseAdrToString  @ 000af610
char * NET_BaseAdrToString(netadr_t a)

{
  Q_memset(NET_BaseAdrToString::s,0,0x40);
  if (a.type == NA_LOOPBACK) {
    builtin_strncpy(NET_BaseAdrToString::s,"loopback",9);
  }
  else if (a.type == NA_IP) {
    __snprintf_chk(NET_BaseAdrToString::s,0x40,1,0x40,"%i.%i.%i.%i",a.ip[0],a.ip[1],a.ip[2],a.ip[3])
    ;
    return NET_BaseAdrToString::s;
  }
  return NET_BaseAdrToString::s;
}


// NET_CheckCleanupFakeIPConnection  @ 000ba740
void NET_CheckCleanupFakeIPConnection(netsrc_t socketnumber,netadr_t_conflict *remote_address)

{
  ISteamNetworkingFakeUDPPort *pIVar1;
  short sVar2;
  int *piVar3;
  int32 iVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined4 local_22;
  undefined4 local_1e;
  undefined2 local_1a;
  undefined2 local_18;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  short local_12;
  int local_10;
  
                    /* Unresolved local var: ISteamNetworkingFakeUDPPort * pFakeUDPPort@[???]
                       Unresolved local var: ISteamNetworkingUtils * pSteamNetworkingUtils@[???]
                       Unresolved local var: SteamNetworkingIPAddr addr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((int)socketnumber < 3) &&
      (pIVar1 = ip_fakeudpports[socketnumber], pIVar1 != (ISteamNetworkingFakeUDPPort *)0x0)) &&
     (remote_address->type == NA_IP)) {
    piVar3 = (int *)SteamInternal_ContextInit
                              (SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
    piVar3 = (int *)*piVar3;
    if (piVar3 != (int *)0x0) {
      iVar4 = (*BigLong)(*(int32 *)remote_address->ip);
      iVar5 = (**(code **)(*piVar3 + 0x38))(piVar3,iVar4);
      if (1 < iVar5) {
        sVar2 = (*BigShort)(remote_address->port);
        iVar4 = (*BigLong)(*(int32 *)remote_address->ip);
        local_22 = 0;
        local_1e = 0;
        local_1a = 0;
        local_18 = 0xffff;
        local_16 = (undefined1)((uint)iVar4 >> 0x18);
        local_15 = (undefined1)((uint)iVar4 >> 0x10);
        local_14 = (undefined1)((uint)iVar4 >> 8);
        local_13 = (undefined1)iVar4;
        local_12 = sVar2;
        (**(code **)(*(int *)pIVar1 + 0xc))(pIVar1,&local_22);
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// NET_ClearLagData  @ 000b2c10
void NET_ClearLagData(qboolean bClient,qboolean bServer)

{
  packetlag_s *ppVar1;
  packetlag_t *ppVar2;
  
  ppVar2 = g_pLagData[0].pNext;
  if (bClient != false) {
    while ((ppVar2 != (packetlag_t *)0x0 && (ppVar2 != g_pLagData))) {
      ppVar1 = ppVar2->pNext;
      ppVar2->pPrev->pNext = ppVar1;
      ppVar2->pNext->pPrev = ppVar2->pPrev;
      ppVar2->pPrev = (packetlag_s *)0x0;
      ppVar2->pNext = (packetlag_s *)0x0;
      if (ppVar2->pPacketData != (uchar *)0x0) {
        Mem_Free(ppVar2->pPacketData);
        ppVar2->pPacketData = (uchar *)0x0;
      }
      Mem_Free(ppVar2);
      ppVar2 = ppVar1;
    }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[0].pPrev = g_pLagData;
    g_pLagData[0].pNext = g_pLagData;
    if ((g_pLagData[2].pNext != g_pLagData + 2) &&
       (ppVar2 = g_pLagData[2].pNext, g_pLagData[2].pNext != (packetlag_t *)0x0)) {
      do {
        ppVar1 = ppVar2->pNext;
        ppVar2->pPrev->pNext = ppVar1;
        ppVar2->pNext->pPrev = ppVar2->pPrev;
        ppVar2->pPrev = (packetlag_s *)0x0;
        ppVar2->pNext = (packetlag_s *)0x0;
        if (ppVar2->pPacketData != (uchar *)0x0) {
          Mem_Free(ppVar2->pPacketData);
          ppVar2->pPacketData = (uchar *)0x0;
        }
        Mem_Free(ppVar2);
      } while ((ppVar1 != (packetlag_s *)0x0) && (ppVar2 = ppVar1, ppVar1 != g_pLagData + 2));
    }
    g_pLagData[2].pPrev = g_pLagData + 2;
    g_pLagData[2].pNext = g_pLagData + 2;
  }
  if (bServer != false) {
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    if ((g_pLagData[1].pNext != g_pLagData + 1) &&
       (ppVar1 = g_pLagData[1].pNext, g_pLagData[1].pNext != (packetlag_s *)0x0)) {
      do {
        ppVar2 = ppVar1->pNext;
        ppVar1->pPrev->pNext = ppVar2;
        ppVar1->pNext->pPrev = ppVar1->pPrev;
        ppVar1->pPrev = (packetlag_s *)0x0;
        ppVar1->pNext = (packetlag_s *)0x0;
        if (ppVar1->pPacketData != (uchar *)0x0) {
          Mem_Free(ppVar1->pPacketData);
          ppVar1->pPacketData = (uchar *)0x0;
        }
        Mem_Free(ppVar1);
      } while ((ppVar2 != (packetlag_t *)0x0) && (ppVar1 = ppVar2, ppVar2 != g_pLagData + 1));
    }
    g_pLagData[1].pPrev = g_pLagData + 1;
    g_pLagData[1].pNext = g_pLagData + 1;
    return;
  }
  return;
}


// NET_ClearLaggedList  @ 000afbb0
void NET_ClearLaggedList(packetlag_t *pList)

{
  packetlag_s *ppVar1;
  packetlag_t *p;
  
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
  p = pList->pNext;
  while ((p != (packetlag_t *)0x0 && (pList != p))) {
    ppVar1 = p->pNext;
    p->pPrev->pNext = ppVar1;
    p->pNext->pPrev = p->pPrev;
    p->pPrev = (packetlag_s *)0x0;
    p->pNext = (packetlag_s *)0x0;
    if (p->pPacketData != (uchar *)0x0) {
      Mem_Free(p->pPacketData);
      p->pPacketData = (uchar *)0x0;
    }
    Mem_Free(p);
    p = ppVar1;
  }
  pList->pPrev = pList;
  pList->pNext = pList;
  return;
}


// NET_CompareAdr  @ 000af430
qboolean NET_CompareAdr(netadr_t a,netadr_t b)

{
  if (b.type == a.type) {
    if (b.type == NA_LOOPBACK) {
      return true;
    }
    if ((b.type == NA_IP) && (a.ip == b.ip)) {
      return (uint)(b.port == a.port);
    }
  }
  return false;
}


// NET_CompareBaseAdr  @ 000af510
qboolean NET_CompareBaseAdr(netadr_t a,netadr_t b)

{
  if (b.type == a.type) {
    if (b.type == NA_LOOPBACK) {
      return true;
    }
    if (b.type == NA_IP) {
      return (uint)(a.ip == b.ip);
    }
  }
  return false;
}


// NET_CompareClassBAdr  @ 000af470
qboolean NET_CompareClassBAdr(netadr_t a,netadr_t b)

{
  if (b.type == a.type) {
    if (b.type == NA_LOOPBACK) {
      return true;
    }
    if (b.type == NA_IP) {
      return (uint)(b.ip._0_2_ == a.ip._0_2_);
    }
  }
  return false;
}


// NET_Config  @ 000b28e0
void NET_Config(qboolean multiplayer)

{
  int __fd;
  netsrc_t socketnumber;
  qboolean qVar1;
  netsrc_t nVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (NET_Config::old_config != multiplayer) {
    NET_Config::old_config = multiplayer;
    if (multiplayer == false) {
      socketnumber = NS_CLIENT;
      __fd = ip_sockets[0];
      while( true ) {
        if (__fd != 0) {
          close(__fd);
          ip_sockets[socketnumber] = 0;
        }
        nVar2 = socketnumber + NS_SERVER;
        NET_SteamFakeIPDestroySocket(socketnumber);
        if (nVar2 == (NS_MULTICAST|NS_SERVER)) break;
        __fd = ip_sockets[nVar2];
        socketnumber = nVar2;
      }
    }
    else {
      if (noip == false) {
        NET_OpenIP();
      }
      if ((NET_Config::bFirst != false) && (qVar1 = NET_ShouldUseSteamFakeIP(), qVar1 == 0)) {
        NET_Config::bFirst = false;
        NET_GetLocalAddress();
      }
    }
    net_configured = (int)(multiplayer != false);
  }
  return;
}


// NET_CountLaggedList  @ 000afb80
int NET_CountLaggedList(packetlag_t *pList)

{
  int iVar1;
  packetlag_t *ppVar2;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: packetlag_t * p@[???] */
  iVar1 = 0;
  ppVar2 = pList->pNext;
  if ((ppVar2 != (packetlag_t *)0x0) && (pList != ppVar2)) {
    while( true ) {
      ppVar2 = ppVar2->pNext;
      iVar1 = iVar1 + 1;
      if (ppVar2 == (packetlag_s *)0x0) break;
      if (pList == ppVar2) {
        return iVar1;
      }
    }
  }
  return iVar1;
}


// NET_ErrorString  @ 000af9d0
char * NET_ErrorString(int code)

{
  char *pcVar1;
  
  pcVar1 = strerror(code);
  return pcVar1;
}


// NET_FlushQueues  @ 000b12d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_FlushQueues(void)

{
  net_messages_s *pnVar1;
  net_messages_t *pnVar2;
  net_messages_t **ppnVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: net_messages_t * p@[???]
                       Unresolved local var: net_messages_t * n@[???] */
  if ((use_thread != 0) && (net_thread_initialized != false)) {
    net_thread_initialized = false;
  }
  ppnVar3 = messages;
  do {
    pnVar2 = *ppnVar3;
    while (pnVar2 != (net_messages_t *)0x0) {
      pnVar1 = pnVar2->next;
      Mem_Free(pnVar2->buffer);
      Mem_Free(pnVar2);
      pnVar2 = pnVar1;
    }
    *ppnVar3 = (net_messages_t *)0x0;
    ppnVar3 = ppnVar3 + 1;
    pnVar2 = normalqueue;
  } while (ppnVar3 != (net_messages_t **)ip_sockets);
  while (pnVar2 != (net_messages_t *)0x0) {
    pnVar1 = pnVar2->next;
    Mem_Free(pnVar2->buffer);
    Mem_Free(pnVar2);
    pnVar2 = pnVar1;
  }
  normalqueue = (net_messages_t *)0x0;
  return;
}


// NET_FlushSocket  @ 000b0210
void NET_FlushSocket(netsrc_t sock)

{
  ssize_t sVar1;
  int iVar2;
  int in_GS_OFFSET;
  socklen_t local_17b0;
  sockaddr local_17aa;
  char local_179a [6010];
  int local_20;
  
                    /* Unresolved local var: sockaddr from@[???]
                       Unresolved local var: int fromlen@[???]
                       Unresolved local var: int net_socket@[???]
                       Unresolved local var: uchar[6010] buf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = ip_sockets[sock];
  if (iVar2 != 0) {
    local_17b0 = 0x10;
    do {
      sVar1 = recvfrom(iVar2,local_179a,0x177a,0,&local_17aa,&local_17b0);
    } while (0 < sVar1);
    do {
      iVar2 = NET_SteamFakeIPRecvFrom
                        (sock,local_179a,0x177a,0,0,(sockaddr *)&local_17aa,&local_17b0);
    } while (0 < iVar2);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// NET_FreeMsg  @ 000b0ef0
void NET_FreeMsg(net_messages_t *pmsg)

{
  if (pmsg->preallocated != false) {
    pmsg->next = normalqueue;
    normalqueue = pmsg;
    return;
  }
  Mem_Free(pmsg->buffer);
  Mem_Free(pmsg);
  return;
}


// NET_GetLocalAddress  @ 000b2110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_GetLocalAddress(void)

{
  uchar uVar1;
  uchar uVar2;
  netadrtype_t nVar3;
  uchar auVar4 [4];
  ushort uVar5;
  qboolean qVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  long lVar11;
  hostent *phVar12;
  int in_GS_OFFSET;
  socklen_t local_2a4;
  short local_2a0;
  ushort local_29e;
  uchar local_29c [4];
  sockaddr local_290 [7];
  undefined1 local_211;
  char local_210 [511];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[512] buff@[???]
                       Unresolved local var: sockaddr_in address@[???]
                       Unresolved local var: int namelen@[???]
                       Unresolved local var: int net_error@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (noip != false) {
    Con_Printf("TCP/IP Disabled.\n");
    Q_memset(&net_local_adr,0,0x14);
    goto LAB_000b2159;
  }
  qVar6 = NET_ShouldUseSteamFakeIP();
  if (qVar6 != 0) {
    if ((g_nFakeIP == 0) && (Net_PollSteamFakeIPResult(), g_nFakeIP == 0)) {
      Q_memset(&net_local_adr,0,0x14);
    }
    else if ((net_local_adr.type != NA_IP) ||
            ((uVar10 = NET_NetAdr_GetIPHostByteOrder((netadr_t_conflict *)&net_local_adr),
             uVar10 != g_nFakeIP ||
             (uVar5 = NET_NetAdr_GetPort((netadr_t_conflict *)&net_local_adr),
             g_arFakePorts[0] != uVar5)))) {
      net_local_adr.type = NA_IP;
      NET_NetAdr_SetIP((netadr_t_conflict *)&net_local_adr,g_nFakeIP);
      NET_NetAdr_SetPort((netadr_t_conflict *)&net_local_adr,g_arFakePorts[0]);
      Con_Printf("Using FakeIP\n");
      uVar5 = net_local_adr.port;
      auVar4 = net_local_adr.ip;
      nVar3 = net_local_adr.type;
      uVar10 = (uint)net_local_adr.ip >> 0x18;
      uVar1 = net_local_adr.ip[1];
      uVar2 = net_local_adr.ip[2];
      Q_memset(NET_AdrToString::s,0,0x40);
      if (nVar3 == NA_LOOPBACK) {
        builtin_strncpy(NET_AdrToString::s,"loopback",9);
      }
      else if (nVar3 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
        __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,
                       uVar2,uVar10,uVar5 >> 8 | uVar5 << 8);
      }
      Con_Printf("Server IP address %s\n",NET_AdrToString::s);
      uVar5 = net_local_adr.port;
      auVar4 = net_local_adr.ip;
      nVar3 = net_local_adr.type;
      uVar10 = (uint)net_local_adr.ip >> 0x18;
      uVar1 = net_local_adr.ip[1];
      uVar2 = net_local_adr.ip[2];
      Q_memset(NET_AdrToString::s,0,0x40);
      if (nVar3 == NA_LOOPBACK) {
        builtin_strncpy(NET_AdrToString::s,"loopback",9);
      }
      else if (nVar3 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
        __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,
                       uVar2,uVar10,uVar5 >> 8 | uVar5 << 8);
      }
      pcVar7 = va("%s",NET_AdrToString::s);
      Cvar_Set("net_address",pcVar7);
      Steam_UpdateRichPresence();
    }
    goto LAB_000b2159;
  }
  iVar8 = Q_strcmp(ipname.string,"localhost");
  if (iVar8 == 0) {
    gethostname(local_210,0x200);
  }
  else {
    Q_strncpy(local_210,ipname.string,0x1ff);
  }
  local_11 = 0;
  Q_memset(&net_local_adr,0,0x14);
                    /* Unresolved local var: sockaddr sadr@[???] */
  iVar8 = Q_strcmp(local_210,"localhost");
  if ((iVar8 == 0) || (iVar8 = Q_strcmp(local_210,"127.0.0.1"), iVar8 == 0)) {
    Q_memset(&net_local_adr,0,0x14);
    net_local_adr.type = NA_LOOPBACK;
  }
  else {
                    /* Unresolved local var: sockaddr sadr@[???]
                       Unresolved local var: hostent * h@[???]
                       Unresolved local var: char * colon@[???]
                       Unresolved local var: int val@[???]
                       Unresolved local var: char[128] copy@[???] */
    Q_memset(&local_2a0,0,0x10);
    local_2a0 = 2;
    local_29e = 0;
    Q_strncpy((char *)local_290,local_210,0x7f);
    local_211 = 0;
    pcVar7 = (char *)((int)&local_290[0].sa_family + 1);
    while ((char)local_290[0].sa_family != '\0') {
      if ((char)local_290[0].sa_family == ':') {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
        pcVar7[-1] = '\0';
        lVar11 = strtol(pcVar7,(char **)0x0,10);
        local_29e = (ushort)lVar11 >> 8 | (ushort)lVar11 << 8;
      }
      local_290[0].sa_family._0_1_ = *pcVar7;
      pcVar7 = pcVar7 + 1;
    }
    local_29c = (uchar  [4])inet_addr((char *)local_290);
    if (local_29c == (uchar  [4])0xffffffff) {
      phVar12 = gethostbyname((char *)local_290);
      if (phVar12 == (hostent *)0x0) goto LAB_000b23ab;
      local_29c = *(uchar (*) [4])*phVar12->h_addr_list;
    }
    if (local_2a0 == 2) {
      net_local_adr.ip[0] = local_29c[0];
      net_local_adr.ip[1] = local_29c[1];
      net_local_adr.ip[2] = local_29c[2];
      net_local_adr.ip[3] = local_29c[3];
      net_local_adr.type = NA_IP;
      net_local_adr.port = local_29e;
    }
  }
LAB_000b23ab:
  local_2a4 = 0x10;
  iVar8 = getsockname(ip_sockets[1],local_290,&local_2a4);
  auVar4 = net_local_adr.ip;
  nVar3 = net_local_adr.type;
  if (iVar8 == 0) {
    uVar10 = (uint)net_local_adr.ip >> 0x18;
    uVar1 = net_local_adr.ip[1];
    net_local_adr.port._0_1_ = local_290[0].sa_data[0];
    net_local_adr.port._1_1_ = local_290[0].sa_data[1];
    uVar2 = net_local_adr.ip[2];
    Q_memset(NET_AdrToString::s,0,0x40);
    if (nVar3 == NA_LOOPBACK) {
      builtin_strncpy(NET_AdrToString::s,"loopback",9);
    }
    else if (nVar3 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,uVar2
                     ,uVar10,(ushort)local_290[0].sa_data._0_2_ >> 8 |
                             local_290[0].sa_data._0_2_ << 8);
    }
    Con_Printf("Server IP address %s\n",NET_AdrToString::s);
    uVar5 = net_local_adr.port;
    auVar4 = net_local_adr.ip;
    nVar3 = net_local_adr.type;
    uVar10 = (uint)net_local_adr.ip >> 0x18;
    uVar1 = net_local_adr.ip[1];
    uVar2 = net_local_adr.ip[2];
    Q_memset(NET_AdrToString::s,0,0x40);
    if (nVar3 == NA_LOOPBACK) {
      builtin_strncpy(NET_AdrToString::s,"loopback",9);
    }
    else if (nVar3 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,uVar2
                     ,uVar10,uVar5 >> 8 | uVar5 << 8);
    }
    pcVar7 = va("%s",NET_AdrToString::s);
    Cvar_Set("net_address",pcVar7);
  }
  else {
    piVar9 = __errno_location();
    noip = true;
    pcVar7 = strerror(*piVar9);
    Con_Printf("Could not get TCP/IP address, TCP/IP disabled\nReason:  %s\n",pcVar7);
  }
LAB_000b2159:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// NET_GetLong  @ 000b02e0
qboolean NET_GetLong(byte *pData,int size,int *outSize)

{
  undefined2 uVar1;
  bool bVar2;
  uint uVar3;
  qboolean qVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  undefined4 uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  char *pcVar14;
  char *pcVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte bVar18;
  
                    /* Unresolved local var: int packetNumber@[???]
                       Unresolved local var: int packetCount@[???]
                       Unresolved local var: int sequenceNumber@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: byte packetID@[???]
                       Unresolved local var: SPLITPACKET * pHeader@[???] */
  bVar18 = 0;
  bVar9 = pData[8] & 0xf;
  bVar6 = pData[8] >> 4;
  uVar3 = (uint)bVar6;
  if ((4 < bVar6) || (5 < bVar9)) {
    Con_Printf("Malformed packet number (%i)\n",uVar3);
    return false;
  }
  uVar11 = (uint)bVar9;
  iVar5 = *(int *)(pData + 4);
  if (((iVar5 == gNetSplit.currentSequence) && (gNetSplit.currentSequence != -1)) ||
     (gNetSplit.currentSequence = iVar5, gNetSplit.splitCount = uVar11, net_showpackets.value != 4.0
     )) {
    if (iVar5 != NET_GetLong::gNetSplitFlags[uVar3]) goto LAB_000b0365;
LAB_000b0460:
    Con_Printf("NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes )\n",uVar3 + 1,
               uVar11,size + -9);
    uVar3 = gNetSplit.totalSize;
  }
  else {
    Con_Printf("<-- Split packet restart %i count %i seq\n",uVar11,iVar5);
    if (iVar5 == NET_GetLong::gNetSplitFlags[uVar3]) goto LAB_000b0460;
LAB_000b0365:
    uVar13 = size - 9;
    if (uVar3 == uVar11 - 1) {
      uVar7 = uVar13 + uVar3 * 0x56f;
      gNetSplit.totalSize = uVar7;
    }
    else {
      uVar7 = uVar13 + uVar3 * 0x56f;
    }
    iVar10 = uVar3 * 0x56f;
    gNetSplit.splitCount = gNetSplit.splitCount + -1;
    bVar2 = net_showpackets.value == 4.0;
    NET_GetLong::gNetSplitFlags[uVar3] = iVar5;
    if (bVar2) {
      Con_Printf("<-- Split packet %i of %i, %i bytes %i seq\n",uVar3 + 1,uVar11,uVar13,iVar5);
    }
    if (0x177a < uVar7) {
      Con_Printf("Malformed packet size (%i, %i)\n",iVar10,uVar13);
      return false;
    }
    pcVar12 = gNetSplit.buffer + iVar10;
    pbVar17 = pData + 9;
    if (7 < uVar13) {
      pcVar14 = pcVar12;
      if (((uint)pcVar12 & 1) != 0) {
        pcVar14 = gNetSplit.buffer + iVar10 + 1;
        uVar13 = size - 10;
        pbVar17 = pData + 10;
        *pcVar12 = pData[9];
      }
      pcVar15 = pcVar14;
      if (((uint)pcVar14 & 2) != 0) {
        uVar1 = *(undefined2 *)pbVar17;
        pcVar15 = pcVar14 + 2;
        pbVar17 = pbVar17 + 2;
        uVar13 = uVar13 - 2;
        *(undefined2 *)pcVar14 = uVar1;
      }
      pcVar12 = pcVar15;
      if (((uint)pcVar15 & 4) != 0) {
        uVar8 = *(undefined4 *)pbVar17;
        pcVar12 = pcVar15 + 4;
        pbVar17 = pbVar17 + 4;
        uVar13 = uVar13 - 4;
        *(undefined4 *)pcVar15 = uVar8;
      }
    }
    for (; uVar3 = gNetSplit.totalSize, uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar12 = *pbVar17;
      pbVar17 = pbVar17 + (uint)bVar18 * -2 + 1;
      pcVar12 = pcVar12 + (uint)bVar18 * -2 + 1;
    }
  }
  if (0 < gNetSplit.splitCount) {
    gNetSplit.totalSize = uVar3;
    return false;
  }
                    /* Unresolved local var: int i@[???] */
  gNetSplit.totalSize = uVar3;
  if (uVar11 == 0) {
LAB_000b04e9:
    gNetSplit.currentSequence = -1;
    if (uVar3 < 0x177b) {
      pcVar12 = gNetSplit.buffer;
      if (7 < uVar3) {
        pbVar17 = pData;
        if (((uint)pData & 1) != 0) {
          pbVar17 = pData + 1;
          pcVar12 = gNetSplit.buffer + 1;
          *pData = gNetSplit.buffer[0];
          uVar3 = uVar3 - 1;
        }
        pbVar16 = pbVar17;
        if (((uint)pbVar17 & 2) != 0) {
          uVar1 = *(undefined2 *)pcVar12;
          pbVar16 = pbVar17 + 2;
          pcVar12 = pcVar12 + 2;
          uVar3 = uVar3 - 2;
          *(undefined2 *)pbVar17 = uVar1;
        }
        pData = pbVar16;
        if (((uint)pbVar16 & 4) != 0) {
          uVar8 = *(undefined4 *)pcVar12;
          pData = pbVar16 + 4;
          pcVar12 = pcVar12 + 4;
          uVar3 = uVar3 - 4;
          *(undefined4 *)pbVar16 = uVar8;
        }
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pData = *pcVar12;
        pcVar12 = pcVar12 + (uint)bVar18 * -2 + 1;
        pData = pData + (uint)bVar18 * -2 + 1;
      }
      *outSize = gNetSplit.totalSize;
      qVar4 = true;
    }
    else {
      Con_Printf("Split packet too large! %d bytes\n",uVar3);
      qVar4 = false;
    }
  }
  else {
    if (NET_GetLong::gNetSplitFlags[0] == gNetSplit.currentSequence) {
      if (uVar11 == 1) goto LAB_000b04e9;
      iVar10 = NET_GetLong::gNetSplitFlags[0];
      if (NET_GetLong::gNetSplitFlags[0] == NET_GetLong::gNetSplitFlags[1]) {
        if (uVar11 == 2) goto LAB_000b04e9;
        if (NET_GetLong::gNetSplitFlags[2] == NET_GetLong::gNetSplitFlags[0]) {
          if (uVar11 == 3) goto LAB_000b04e9;
          if (NET_GetLong::gNetSplitFlags[0] == NET_GetLong::gNetSplitFlags[3]) {
            if ((uVar11 == 4) || (NET_GetLong::gNetSplitFlags[0] == NET_GetLong::gNetSplitFlags[4]))
            goto LAB_000b04e9;
            uVar8 = 5;
            iVar5 = NET_GetLong::gNetSplitFlags[4];
          }
          else {
            uVar8 = 4;
            iVar5 = NET_GetLong::gNetSplitFlags[3];
          }
        }
        else {
          uVar8 = 3;
          iVar5 = NET_GetLong::gNetSplitFlags[2];
        }
      }
      else {
        uVar8 = 2;
        iVar5 = NET_GetLong::gNetSplitFlags[1];
      }
    }
    else {
      uVar8 = 1;
      iVar5 = NET_GetLong::gNetSplitFlags[0];
      iVar10 = gNetSplit.currentSequence;
    }
    Con_Printf("Split packet without all %i parts, part %i had wrong sequence %i/%i\n",uVar11,uVar8,
               iVar5,iVar10);
    qVar4 = false;
  }
  return qVar4;
}


// NET_GetLoopPacket  @ 000afa20
qboolean NET_GetLoopPacket(netsrc_t sock,netadr_t *in_from,sizebuf_t *msg)

{
  int iVar1;
  int count;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: loopback_t * loop@[???] */
  iVar1 = loopbacks[sock].send;
  uVar2 = loopbacks[sock].get;
  if (4 < (int)(iVar1 - uVar2)) {
    uVar2 = iVar1 - 4;
    loopbacks[sock].get = uVar2;
  }
  if ((int)uVar2 < iVar1) {
    loopbacks[sock].get = uVar2 + 1;
    count = loopbacks[sock].msgs[uVar2 & 3].datalen;
    Q_memcpy(msg->data,loopbacks[sock].msgs + (uVar2 & 3),count);
    msg->cursize = count;
    Q_memset(in_from,0,0x14);
    in_from->type = NA_LOOPBACK;
  }
  return (uint)((int)uVar2 < iVar1);
}


// NET_GetPacket  @ 000b0f30
qboolean NET_GetPacket(netsrc_t sock)

{
  int iVar1;
  net_messages_t *p;
  float fVar2;
  float fVar3;
  uint uVar4;
  qboolean qVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: net_messages_t * pmsg@[???]
                       Unresolved local var: qboolean bret@[???] */
                    /* Unresolved local var: double dt@[???]
                       Unresolved local var: float diff@[???]
                       Unresolved local var: float converge@[???] */
  lVar6 = (longdouble)realtime - (longdouble)NET_AdjustLag::lasttime;
  if (lVar6 < (longdouble)0) {
    lVar6 = (longdouble)0;
  }
  else if ((longdouble)0.1 < lVar6) {
    lVar6 = (longdouble)0.1;
  }
  NET_AdjustLag::lasttime = realtime;
  if ((sv_cheats.value == 0.0) && (fakelag.value != 0.0)) {
                    /* Unresolved local var: double dt@[???]
                       Unresolved local var: float diff@[???]
                       Unresolved local var: float converge@[???] */
    Con_Printf("Server must enable cheats to activate fakelag\n");
    Cvar_SetValue("fakelag",0.0);
    gFakeLag = 0.0;
  }
  else if (fakelag.value != gFakeLag) {
    fVar2 = ABS(fakelag.value - gFakeLag);
    fVar3 = (float)(lVar6 * (longdouble)200.0);
    if (fVar2 < (float)(lVar6 * (longdouble)200.0)) {
      fVar3 = fVar2;
    }
    if (fakelag.value - gFakeLag < 0.0) {
      fVar3 = -fVar3;
    }
    gFakeLag = gFakeLag + fVar3;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: loopback_t * loop@[???] */
  iVar1 = loopbacks[sock].send;
  uVar4 = loopbacks[sock].get;
  if (4 < (int)(iVar1 - uVar4)) {
    uVar4 = iVar1 - 4;
    loopbacks[sock].get = uVar4;
  }
  if ((int)uVar4 < iVar1) {
    loopbacks[sock].get = uVar4 + 1;
    iVar1 = loopbacks[sock].msgs[uVar4 & 3].datalen;
    Q_memcpy(in_message.data,loopbacks[sock].msgs + (uVar4 & 3),iVar1);
    in_message.cursize = iVar1;
    Q_memset(&in_from,0,0x14);
    in_from.type = NA_LOOPBACK;
    qVar5 = NET_LagPacket(true,sock,&in_from,&in_message);
  }
  else {
    if ((use_thread == 0) && (qVar5 = NET_QueuePacket(sock), qVar5 != false)) goto LAB_000b11e0;
    qVar5 = NET_LagPacket(false,sock,(netadr_t *)0x0,(sizebuf_t *)0x0);
  }
  if (qVar5 == false) {
    p = messages[sock];
    qVar5 = false;
    if (p != (net_messages_t *)0x0) {
      messages[sock] = p->next;
      net_message.cursize = p->buffersize;
      Q_memcpy(net_message.data,p->buffer,net_message.cursize);
      net_from.type = (p->from).type;
      msg_readcount = 0;
      net_from.ip = *&(p->from).ip;
      net_from.ipx._0_4_ = *(undefined4 *)(p->from).ipx;
      net_from.ipx._4_4_ = *(undefined4 *)((p->from).ipx + 4);
      net_from._16_4_ = *(undefined4 *)((p->from).ipx + 8);
      if (p->preallocated == false) {
        Mem_Free(p->buffer);
        Mem_Free(p);
        return true;
      }
      p->next = normalqueue;
      qVar5 = true;
      normalqueue = p;
    }
    return qVar5;
  }
LAB_000b11e0:
  Q_memcpy(net_message.data,in_message.data,in_message.cursize);
  net_message.cursize = in_message.cursize;
  net_from.type = in_from.type;
  net_from.ip[0] = in_from.ip[0];
  net_from.ip[1] = in_from.ip[1];
  net_from.ip[2] = in_from.ip[2];
  net_from.ip[3] = in_from.ip[3];
  net_from.ipx[0] = in_from.ipx[0];
  net_from.ipx[1] = in_from.ipx[1];
  net_from.ipx[2] = in_from.ipx[2];
  net_from.ipx[3] = in_from.ipx[3];
  net_from.ipx[4] = in_from.ipx[4];
  net_from.ipx[5] = in_from.ipx[5];
  net_from.ipx[6] = in_from.ipx[6];
  net_from.ipx[7] = in_from.ipx[7];
  net_from.ipx[8] = in_from.ipx[8];
  net_from.ipx[9] = in_from.ipx[9];
  net_from.port = in_from.port;
  return qVar5;
}


// NET_HostToNetShort  @ 000af420
ushort NET_HostToNetShort(ushort us_in)

{
                    /* Unresolved local var: ushort __v@[DW_OP_reg0(EAX)]
                       Unresolved local var: ushort __x@[???] */
  return us_in >> 8 | us_in << 8;
}


// NET_IPSocket  @ 000b1b50
/* WARNING: Type propagation algorithm not settling */

int NET_IPSocket(char *net_interface,int port,qboolean multicast)

{
  int __fd;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  undefined4 local_3c;
  uint local_38 [2];
  sockaddr local_30;
  int local_20;
  
                    /* Unresolved local var: int newsocket@[???]
                       Unresolved local var: sockaddr_in address@[???]
                       Unresolved local var: qboolean _true@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int err@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = 1;
  local_38[0] = 1;
  __fd = socket(2,2,0x11);
  if (__fd == -1) {
    piVar2 = __errno_location();
    __fd = 0;
    if (*piVar2 != 0x61) {
      pcVar3 = strerror(*piVar2);
      Con_Printf("WARNING: UDP_OpenSocket: port: %d socket: %s",port,pcVar3);
    }
  }
  else {
    iVar1 = ioctl(__fd,0x5421,&local_3c);
    if (iVar1 == -1) {
      piVar2 = __errno_location();
      __fd = 0;
      pcVar3 = strerror(*piVar2);
      Con_Printf("WARNING: UDP_OpenSocket: port: %d  ioctl FIONBIO: %s\n",port,pcVar3);
    }
    else {
      iVar1 = setsockopt(__fd,1,6,local_38,4);
      if (iVar1 == -1) {
        piVar2 = __errno_location();
        __fd = 0;
        pcVar3 = strerror(*piVar2);
        Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt SO_BROADCAST: %s\n",port,pcVar3);
      }
      else {
        iVar1 = COM_CheckParm("-reuse");
        if (((iVar1 == 0) && (multicast == false)) ||
           (iVar1 = setsockopt(__fd,1,2,&local_3c,4), iVar1 != -1)) {
          iVar1 = COM_CheckParm("-tos");
          if (iVar1 != 0) {
                    /* Unresolved local var: int tos@[???] */
            local_38[1] = 0x10;
            Con_Printf("Enabling LOWDELAY TOS option\n");
            iVar1 = setsockopt(__fd,0,1,local_38 + 1,4);
            if (iVar1 < 0) {
              piVar2 = __errno_location();
              if (*piVar2 != 0x5c) {
                __fd = 0;
                pcVar3 = strerror(*piVar2);
                Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt IP_TOS: %s\n",port,pcVar3)
                ;
                goto LAB_000b1cd0;
              }
            }
          }
          if (((net_interface == (char *)0x0) || (*net_interface == '\0')) ||
             (iVar1 = Q_stricmp(net_interface,"localhost"), iVar1 == 0)) {
            local_30.sa_data[2] = '\0';
            local_30.sa_data[3] = '\0';
            local_30.sa_data[4] = '\0';
            local_30.sa_data[5] = '\0';
          }
          else {
            NET_StringToSockaddr(net_interface,(sockaddr *)&local_30);
          }
          if (port == -1) {
            local_30.sa_data[0] = '\0';
            local_30.sa_data[1] = '\0';
          }
          else {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
            local_30.sa_data._0_2_ = (ushort)port >> 8 | (ushort)port << 8;
          }
          local_30.sa_family = 2;
          iVar1 = bind(__fd,&local_30,0x10);
          if (iVar1 == -1) {
            piVar2 = __errno_location();
            pcVar3 = strerror(*piVar2);
            Con_Printf("WARNING: UDP_OpenSocket: port: %d  bind: %s\n",port,pcVar3);
            close(__fd);
            __fd = 0;
          }
          else {
            iVar1 = COM_CheckParm("-loopback");
            local_38[0] = (uint)(iVar1 != 0);
            iVar1 = setsockopt(__fd,0,0x22,local_38,4);
            if (iVar1 == -1) {
              piVar2 = __errno_location();
              pcVar3 = strerror(*piVar2);
              Con_DPrintf("WARNING: UDP_OpenSocket: port %d setsockopt IP_MULTICAST_LOOP: %s\n",port
                          ,pcVar3);
            }
          }
        }
        else {
          piVar2 = __errno_location();
          __fd = 0;
          pcVar3 = strerror(*piVar2);
          Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt SO_REUSEADDR: %s\n",port,pcVar3)
          ;
        }
      }
    }
  }
LAB_000b1cd0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __fd;
}


// NET_Init  @ 000b2990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_Init(void)

{
  int iVar1;
  net_messages_t *pnVar2;
  uchar *puVar3;
  double dVar4;
  
                    /* Unresolved local var: int i@[???] */
  Cmd_AddCommand("maxplayers",MaxPlayers_f);
  Cvar_RegisterVariable(&net_address);
  Cvar_RegisterVariable(&ipname);
  Cvar_RegisterVariable(&iphostport);
  Cvar_RegisterVariable(&hostport);
  Cvar_RegisterVariable(&defport);
  Cvar_RegisterVariable(&ip_clientport);
  Cvar_RegisterVariable(&clientport);
  Cvar_RegisterVariable(&clockwindow);
  Cvar_RegisterVariable(&multicastport);
  Cvar_RegisterVariable(&fakelag);
  Cvar_RegisterVariable(&fakeloss);
  Cvar_RegisterVariable(&net_graph);
  Cvar_RegisterVariable(&net_graphwidth);
  Cvar_RegisterVariable(&net_scale);
  Cvar_RegisterVariable(&net_graphpos);
  iVar1 = COM_CheckParm("-netsleep");
  if (iVar1 != 0) {
    net_sleepforever = 0;
  }
  iVar1 = COM_CheckParm("-noip");
  if (iVar1 != 0) {
    noip = true;
  }
  iVar1 = COM_CheckParm("-port");
  if (iVar1 != 0) {
    dVar4 = strtod(com_argv[iVar1 + 1],(char **)0x0);
    Cvar_SetValue("hostport",(float)dVar4);
  }
  iVar1 = COM_CheckParm("-clockwindow");
  if (iVar1 != 0) {
    dVar4 = strtod(com_argv[iVar1 + 1],(char **)0x0);
    Cvar_SetValue("clockwindow",(float)dVar4);
  }
  net_message.flags = 0;
  net_message.buffername = "net_message";
  in_message.maxsize = 0x10000;
  in_message.data = in_message_buf;
  in_message.flags = 0;
  in_message.buffername = "in_message";
  net_message.maxsize = 0x10000;
  net_message.data = net_message_buffer;
  g_pLagData[2].pPrev = g_pLagData + 2;
  g_pLagData[1].pNext = g_pLagData + 1;
  g_pLagData[0].pPrev = g_pLagData;
  g_pLagData[0].pNext = g_pLagData;
  g_pLagData[1].pPrev = g_pLagData + 1;
  g_pLagData[2].pNext = g_pLagData + 2;
  iVar1 = 0x28;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: net_messages_t * p@[???] */
    pnVar2 = Mem_ZeroMalloc(0x24);
    puVar3 = Mem_ZeroMalloc(0x600);
    iVar1 = iVar1 + -1;
    pnVar2->preallocated = true;
    pnVar2->buffer = puVar3;
    pnVar2->next = normalqueue;
    normalqueue = pnVar2;
  } while (iVar1 != 0);
  if ((use_thread != 0) && (net_thread_initialized == false)) {
    net_thread_initialized = true;
  }
  Con_DPrintf("Base networking initialized.\n");
  return;
}


// NET_InternalOpenOrCloseFakeUDPPorts  @ 000ba190
void __regparm3 NET_InternalOpenOrCloseFakeUDPPorts(bool bClient,bool bOpen)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
  if (!bClient) {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamGameServerNetworkingSockets_SteamAPI::
                               s_CallbackCounterAndContext_1);
    piVar1 = (int *)*piVar1;
    if (piVar1 == (int *)0x0) {
      return;
    }
                    /* Unresolved local var: bool bLanOnly@[???] */
                    /* Unresolved local var: bool bLanOnly@[???] */
    if (((0.0 < sv_lan.value) || (iVar2 = PF_IsDedicatedServer(), iVar2 != 0)) ||
       (sv_use_steam_networking.value <= 0.0)) {
      if (bOpen) {
        return;
      }
    }
    else if (bOpen) {
      if (ip_fakeudpports[1] != (ISteamNetworkingFakeUDPPort *)0x0) {
        return;
      }
      ip_fakeudpports[1] = (ISteamNetworkingFakeUDPPort *)(**(code **)(*piVar1 + 0xb8))(piVar1,0);
      if (ip_fakeudpports[1] != (ISteamNetworkingFakeUDPPort *)0x0) {
        return;
      }
      Con_Printf("Failed to create fake UDP port, module %d fake port idx %d",1,0);
      return;
    }
    if (ip_fakeudpports[1] == (ISteamNetworkingFakeUDPPort *)0x0) {
      return;
    }
    (*(code *)**(undefined4 **)ip_fakeudpports[1])(ip_fakeudpports[1]);
    ip_fakeudpports[1] = (ISteamNetworkingFakeUDPPort *)0x0;
    return;
  }
  piVar1 = (int *)SteamInternal_ContextInit
                            (SteamNetworkingSockets_SteamAPI::s_CallbackCounterAndContext);
  piVar1 = (int *)*piVar1;
  if (piVar1 == (int *)0x0) {
    return;
  }
  if (!bOpen) {
    if (ip_fakeudpports[0] == (ISteamNetworkingFakeUDPPort *)0x0) {
      return;
    }
    (*(code *)**(undefined4 **)ip_fakeudpports[0])(ip_fakeudpports[0]);
    ip_fakeudpports[0] = (ISteamNetworkingFakeUDPPort *)0x0;
    return;
  }
  if (ip_fakeudpports[0] != (ISteamNetworkingFakeUDPPort *)0x0) {
    return;
  }
  ip_fakeudpports[0] =
       (ISteamNetworkingFakeUDPPort *)(**(code **)(*piVar1 + 0xb8))(piVar1,0xffffffff);
  if (ip_fakeudpports[0] != (ISteamNetworkingFakeUDPPort *)0x0) {
    return;
  }
  Con_Printf("Failed to create fake UDP port, module %d fake port idx %d",0,0xffffffff);
  return;
}


// NET_IsConfigured  @ 000b28d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int NET_IsConfigured(void)

{
  return net_configured;
}


// NET_IsLocalAddress  @ 000af990
qboolean NET_IsLocalAddress(netadr_t adr)

{
  if (adr.type == NA_LOOPBACK) {
    return true;
  }
  if (adr.type != NA_IP) {
    return false;
  }
  return (uint)(adr.ip == (uchar  [4])0x100007f);
}


// NET_IsReservedAdr  @ 000af4b0
qboolean NET_IsReservedAdr(netadr_t a)

{
  if (a.type != NA_LOOPBACK) {
    if (a.type != NA_IP) {
      return false;
    }
    if ((a.ip[0] != '\n') && (a.ip[0] != '\x7f')) {
      if (a.ip[0] != 0xac) {
        return (uint)(a.ip[0] == 0xc0 && 0xa7 < a.ip[1]);
      }
      return (uint)((byte)(a.ip[1] - 0x10) < 0x10);
    }
  }
  return true;
}


// NET_IsSteamFakeIP  @ 000ba840
qboolean NET_IsSteamFakeIP(netsrc_t socketnumber,sockaddr *to)

{
  ISteamNetworkingFakeUDPPort *pIVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
                    /* Unresolved local var: ISteamNetworkingFakeUDPPort * pFakeUDPPort@[???]
                       Unresolved local var: ISteamNetworkingUtils * pSteamNetworkingUtils@[???] */
  pIVar1 = ip_fakeudpports[socketnumber];
  piVar2 = (int *)SteamInternal_ContextInit
                            (SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
  piVar2 = (int *)*piVar2;
  uVar3 = 0;
  if ((piVar2 != (int *)0x0) && (to->sa_family == 2)) {
                    /* Unresolved local var: sockaddr_in * to_addr_ipv4@[???]
                       Unresolved local var: uint32 nIPv4@[???] */
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
    uVar3 = *(uint *)(to->sa_data + 2);
    iVar4 = (**(code **)(*piVar2 + 0x38))
                      (piVar2,uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                              uVar3 << 0x18);
    uVar3 = (uint)(1 < iVar4 && pIVar1 != (ISteamNetworkingFakeUDPPort *)0x0);
  }
  return uVar3;
}


// NET_JoinGroup  @ 000b2fa0
qboolean NET_JoinGroup(netsrc_t sock,netadr_t addr)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  qboolean qVar4;
  uchar local_14 [4];
  undefined4 local_10;
  
                    /* Unresolved local var: int net_socket@[???]
                       Unresolved local var: int err@[???]
                       Unresolved local var: ip_mreq mreq@[???] */
  qVar4 = true;
  local_14[0] = addr.ip[0];
  local_14[1] = addr.ip[1];
  local_14[2] = addr.ip[2];
  local_14[3] = addr.ip[3];
  local_10 = 0;
  iVar1 = setsockopt(ip_sockets[sock],0,0x23,local_14,8);
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    qVar4 = false;
    if (*piVar2 != 0x61) {
      pcVar3 = strerror(*piVar2);
      Con_Printf("WARNING: NET_JoinGroup: IP_ADD_MEMBERSHIP: %s",pcVar3);
      return false;
    }
  }
  return qVar4;
}


// NET_LagPacket  @ 000afdf0
/* WARNING: Type propagation algorithm not settling */

qboolean NET_LagPacket(qboolean newdata,netsrc_t sock,netadr_t *from,sizebuf_t *data)

{
  float fVar1;
  int iVar2;
  packetlag_t *p;
  byte *src;
  size_t size;
  float fVar3;
  int32 iVar4;
  packetlag_s *ppVar5;
  uchar *dest;
  int iVar6;
  int iVar7;
  packetlag_t *ppVar8;
  
                    /* Unresolved local var: packetlag_t * pNewPacketLag@[???]
                       Unresolved local var: packetlag_t * pPacket@[???]
                       Unresolved local var: float curtime@[???] */
  fVar1 = fakeloss.value;
  if (gFakeLag <= 0.0) {
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    if ((g_pLagData[0].pNext != g_pLagData) &&
       (ppVar5 = g_pLagData[0].pNext, g_pLagData[0].pNext != (packetlag_s *)0x0)) {
      do {
        ppVar8 = ppVar5->pNext;
        ppVar5->pPrev->pNext = ppVar8;
        ppVar5->pNext->pPrev = ppVar5->pPrev;
        ppVar5->pPrev = (packetlag_s *)0x0;
        ppVar5->pNext = (packetlag_s *)0x0;
        if (ppVar5->pPacketData != (uchar *)0x0) {
          Mem_Free(ppVar5->pPacketData);
          ppVar5->pPacketData = (uchar *)0x0;
        }
        Mem_Free(ppVar5);
      } while ((ppVar8 != (packetlag_t *)0x0) && (ppVar5 = ppVar8, ppVar8 != g_pLagData));
    }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[0].pPrev = g_pLagData;
    g_pLagData[0].pNext = g_pLagData;
    ppVar8 = g_pLagData[2].pNext;
    while ((ppVar8 != (packetlag_t *)0x0 && (ppVar8 != g_pLagData + 2))) {
      ppVar5 = ppVar8->pNext;
      ppVar8->pPrev->pNext = ppVar5;
      ppVar8->pNext->pPrev = ppVar8->pPrev;
      ppVar8->pPrev = (packetlag_s *)0x0;
      ppVar8->pNext = (packetlag_s *)0x0;
      if (ppVar8->pPacketData != (uchar *)0x0) {
        Mem_Free(ppVar8->pPacketData);
        ppVar8->pPacketData = (uchar *)0x0;
      }
      Mem_Free(ppVar8);
      ppVar8 = ppVar5;
    }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[2].pPrev = g_pLagData + 2;
    g_pLagData[2].pNext = g_pLagData + 2;
    ppVar8 = g_pLagData[1].pNext;
    while ((ppVar8 != (packetlag_t *)0x0 && (ppVar8 != g_pLagData + 1))) {
      ppVar5 = ppVar8->pNext;
      ppVar8->pPrev->pNext = ppVar5;
      ppVar8->pNext->pPrev = ppVar8->pPrev;
      ppVar8->pPrev = (packetlag_s *)0x0;
      ppVar8->pNext = (packetlag_s *)0x0;
      if (ppVar8->pPacketData != (uchar *)0x0) {
        Mem_Free(ppVar8->pPacketData);
        ppVar8->pPacketData = (uchar *)0x0;
      }
      Mem_Free(ppVar8);
      ppVar8 = ppVar5;
    }
    g_pLagData[1].pPrev = g_pLagData + 1;
    g_pLagData[1].pNext = g_pLagData + 1;
    in_from.ip[0] = in_from.ip[0];
    in_from.ip[1] = in_from.ip[1];
    in_from.ip[2] = in_from.ip[2];
    in_from.ip[3] = in_from.ip[3];
    in_from.ipx[0] = in_from.ipx[0];
    in_from.ipx[1] = in_from.ipx[1];
    in_from.ipx[2] = in_from.ipx[2];
    in_from.ipx[3] = in_from.ipx[3];
    in_from.ipx[4] = in_from.ipx[4];
    in_from.ipx[5] = in_from.ipx[5];
    in_from.ipx[6] = in_from.ipx[6];
    in_from.ipx[7] = in_from.ipx[7];
    in_from.ipx[8] = in_from.ipx[8];
    in_from.ipx[9] = in_from.ipx[9];
    in_from.port = in_from.port;
    return newdata;
  }
  fVar3 = (float)realtime;
  if (newdata == false) {
    ppVar8 = g_pLagData + sock;
  }
  else {
    if (fakeloss.value != 0.0) {
      if (sv_cheats.value == 0.0) {
        Cvar_SetValue("fakeloss",0.0);
      }
      else {
        iVar2 = NET_LagPacket::losscount[sock];
        NET_LagPacket::losscount[sock] = iVar2 + 1;
        if (fVar1 <= 0.0) {
                    /* Unresolved local var: int ninterval@[???] */
          iVar7 = (int)ABS(fVar1);
          iVar6 = 2;
          if (1 < iVar7) {
            iVar6 = iVar7;
          }
          if ((iVar2 + 1) % iVar6 == 0) {
            return false;
          }
        }
        else {
          iVar4 = RandomLong(0,100);
          if (iVar4 <= (int)fakeloss.value) {
            return false;
          }
        }
      }
    }
    ppVar5 = Mem_ZeroMalloc(0x28);
                    /* Unresolved local var: uchar * pStart@[???] */
    ppVar8 = g_pLagData + sock;
    if ((ppVar5->pPrev == (packetlag_s *)0x0) && (ppVar5->pNext == (packetlag_s *)0x0)) {
      src = data->data;
      size = data->cursize;
      ppVar5->pPrev = g_pLagData[sock].pPrev;
      (g_pLagData[sock].pPrev)->pNext = ppVar5;
      g_pLagData[sock].pPrev = ppVar5;
      ppVar5->pNext = ppVar8;
      dest = Mem_Malloc(size);
      ppVar5->pPacketData = dest;
      Q_memcpy(dest,src,size);
      ppVar5->nSize = size;
      ppVar5->receivedTime = fVar3;
      (ppVar5->net_from).type = from->type;
      *(undefined4 *)(ppVar5->net_from).ip = *(undefined4 *)from->ip;
      *(undefined4 *)(ppVar5->net_from).ipx = *(undefined4 *)from->ipx;
      *(undefined4 *)((ppVar5->net_from).ipx + 4) = *(undefined4 *)(from->ipx + 4);
      *(undefined4 *)((ppVar5->net_from).ipx + 8) = *(undefined4 *)(from->ipx + 8);
    }
    else {
      Con_Printf("Packet already linked\n");
    }
  }
  p = g_pLagData[sock].pNext;
  if (p != ppVar8) {
    fVar1 = p->receivedTime;
    while( true ) {
      if (fVar1 <= fVar3 - gFakeLag / 1000.0) {
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
        iVar2 = p->nSize;
        p->pPrev = (packetlag_s *)0x0;
        p->pNext = (packetlag_s *)0x0;
        Q_memcpy(in_message.data,p->pPacketData,iVar2);
        in_from.type = (p->net_from).type;
        in_from.ip = *&(p->net_from).ip;
        in_from.ipx._0_4_ = *(undefined4 *)(p->net_from).ipx;
        in_from.ipx._4_4_ = *(undefined4 *)((p->net_from).ipx + 4);
        in_from._16_4_ = *(undefined4 *)((p->net_from).ipx + 8);
        in_message.cursize = iVar2;
        if (p->pPacketData != (uchar *)0x0) {
          free(p->pPacketData);
        }
        Mem_Free(p);
        return true;
      }
      p = p->pNext;
      if (p == ppVar8) break;
      fVar1 = p->receivedTime;
    }
  }
  return false;
}


// NET_LeaveGroup  @ 000b3030
qboolean NET_LeaveGroup(netsrc_t sock,netadr_t addr)

{
  int iVar1;
  int *piVar2;
  uchar local_14 [4];
  undefined4 local_10;
  
                    /* Unresolved local var: int net_socket@[???]
                       Unresolved local var: int err@[???]
                       Unresolved local var: ip_mreq mreq@[???] */
  local_14[0] = addr.ip[0];
  local_14[1] = addr.ip[1];
  local_14[2] = addr.ip[2];
  local_14[3] = addr.ip[3];
  local_10 = 0;
  iVar1 = setsockopt(ip_sockets[sock],0,0x24,local_14,8);
  if (iVar1 != -1) {
    return true;
  }
  piVar2 = __errno_location();
  return (uint)(*piVar2 == 0x61);
}


// NET_NetAdr_GetIPHostByteOrder  @ 000ba720
uint NET_NetAdr_GetIPHostByteOrder(netadr_t_conflict *addr)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000ba72b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*BigLong)(*(int32 *)addr->ip);
  return uVar1;
}


// NET_NetAdr_GetIPNetworkByteOrder  @ 000ba710
uint NET_NetAdr_GetIPNetworkByteOrder(netadr_t_conflict *addr)

{
  return *(uint *)addr->ip;
}


// NET_NetAdr_GetPort  @ 000ba6f0
ushort NET_NetAdr_GetPort(netadr_t_conflict *addr)

{
  ushort uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000ba6fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*BigShort)(addr->port);
  return uVar1;
}


// NET_NetAdr_SetIP  @ 000ba6b0
void NET_NetAdr_SetIP(netadr_t_conflict *addr,uint ip)

{
  int32 iVar1;
  
  iVar1 = (*BigLong)(ip);
  *(int32 *)addr->ip = iVar1;
  return;
}


// NET_NetAdr_SetPort  @ 000ba6d0
void NET_NetAdr_SetPort(netadr_t_conflict *addr,ushort port)

{
  ushort uVar1;
  
  uVar1 = (*BigShort)(port);
  addr->port = uVar1;
  return;
}


// NET_OpenIP  @ 000b1f40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_OpenIP(void)

{
  int port;
  int port_00;
  bool bVar1;
  
                    /* Unresolved local var: cvar_t * ip@[???]
                       Unresolved local var: int port@[???]
                       Unresolved local var: int dedicated@[???]
                       Unresolved local var: int sv_port@[???]
                       Unresolved local var: int cl_port@[???]
                       Unresolved local var: int mc_port@[???] */
  bVar1 = cls.state == ca_dedicated;
  port = 0;
  if (ip_sockets[1] == 0) {
    port = (int)iphostport.value;
    if ((port == 0) && (port = (int)hostport.value, port == 0)) {
      port = (int)defport.value;
      hostport.value = defport.value;
    }
    ip_sockets[1] = NET_IPSocket(ipname.string,port,false);
    if ((ip_sockets[1] == 0) && (bVar1)) {
      Sys_Error("Couldn\'t allocate dedicated server IP port %d.",port);
    }
  }
  if (cls.state != ca_dedicated) {
    port_00 = 0;
    if (ip_sockets[0] == 0) {
      port_00 = (int)ip_clientport.value;
      if ((port_00 == 0) && (port_00 = (int)clientport.value, port_00 == 0)) {
        port_00 = -1;
      }
      ip_sockets[0] = NET_IPSocket(ipname.string,port_00,false);
      if (ip_sockets[0] == 0) {
        ip_sockets[0] = NET_IPSocket(ipname.string,-1,false);
      }
    }
    if ((ip_sockets[2] == 0) &&
       (ip_sockets[2] = NET_IPSocket(ipname.string,(int)multicastport.value,true),
       !bVar1 && ip_sockets[2] == 0)) {
      Con_Printf("Warning! Couldn\'t allocate multicast IP port.\n");
    }
    Net_CheckOpenFakeUDPPorts(1);
    Net_CheckOpenFakeUDPPorts(0);
    if (NET_OpenIP::bFirst != false) {
      NET_OpenIP::bFirst = false;
      Con_Printf("NET Ports:  server %i, client %i\n",port,port_00);
      return;
    }
  }
  return;
}


// NET_QueuePacket  @ 000b06a0
qboolean NET_QueuePacket(netsrc_t sock)

{
  float fVar1;
  int iVar2;
  packetlag_s *ppVar3;
  uchar uVar4;
  uchar uVar5;
  ushort uVar6;
  netadrtype_t nVar7;
  uchar auVar8 [4];
  qboolean qVar9;
  uint uVar10;
  int *piVar11;
  char *pcVar12;
  packetlag_t *ppVar13;
  int in_GS_OFFSET;
  socklen_t local_17b0;
  sockaddr local_17aa;
  char local_179a [6010];
  int local_20;
  
                    /* Unresolved local var: int ret@[???]
                       Unresolved local var: sockaddr from@[???]
                       Unresolved local var: int fromlen@[???]
                       Unresolved local var: int net_socket@[???]
                       Unresolved local var: int protocol@[???]
                       Unresolved local var: int err@[???]
                       Unresolved local var: uchar[6010] buf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (ip_sockets[sock] != 0) {
    local_17b0 = 0x10;
    uVar10 = recvfrom(ip_sockets[sock],local_179a,0x177a,0,&local_17aa,&local_17b0);
    if (((int)uVar10 < 1) &&
       (uVar10 = NET_SteamFakeIPRecvFrom
                           (sock,local_179a,0x177a,0,uVar10,(sockaddr *)&local_17aa,&local_17b0),
       uVar10 == 0xffffffff)) {
      piVar11 = __errno_location();
      iVar2 = *piVar11;
      if ((iVar2 != 0xb && iVar2 != 0x68) && (iVar2 != 0x6f)) {
        if (iVar2 == 0x5a) {
          Con_DPrintf("NET_QueuePacket:  Ignoring oversized network message\n");
        }
        else if (cls.state == ca_dedicated) {
          pcVar12 = strerror(iVar2);
          Con_Printf("NET_QueuePacket: %s\n",pcVar12);
        }
        else {
          pcVar12 = strerror(iVar2);
          Sys_Error("NET_QueuePacket: %s",pcVar12);
        }
      }
    }
    else {
      if (local_17aa.sa_family == 2) {
        in_from.ip[2] = local_17aa.sa_data[4];
        in_from.ip[3] = local_17aa.sa_data[5];
        in_from.ip[0] = local_17aa.sa_data[2];
        in_from.ip[1] = local_17aa.sa_data[3];
        in_from.type = NA_IP;
        in_from.port._0_1_ = local_17aa.sa_data[0];
        in_from.port._1_1_ = local_17aa.sa_data[1];
      }
      auVar8 = in_from.ip;
      nVar7 = in_from.type;
      if (uVar10 != 0x177a) {
        Q_memcpy(in_message.data,local_179a,uVar10);
        in_message.cursize = uVar10;
        if (*(int *)in_message.data == -2) {
          if (uVar10 < 9) {
            Con_Printf("Invalid split packet length %i\n",uVar10);
            qVar9 = false;
          }
          else {
            qVar9 = NET_GetLong(in_message.data,uVar10,&in_message.cursize);
          }
        }
        else {
          qVar9 = NET_LagPacket(true,sock,&in_from,&in_message);
        }
        goto LAB_000b0732;
      }
      uVar10 = (uint)in_from.ip >> 0x18;
      uVar6 = in_from.port;
      uVar4 = in_from.ip[1];
      uVar5 = in_from.ip[2];
      Q_memset(NET_AdrToString::s,0,0x40);
      if (nVar7 == NA_LOOPBACK) {
        builtin_strncpy(NET_AdrToString::s,"loopback",9);
      }
      else if (nVar7 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
        __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar8 & 0xff,uVar4,
                       uVar5,uVar10,uVar6 >> 8 | uVar6 << 8);
      }
      Con_Printf("NET_QueuePacket:  Oversize packet from %s\n",NET_AdrToString::s);
    }
  }
                    /* Unresolved local var: packetlag_t * pNewPacketLag@[???]
                       Unresolved local var: packetlag_t * pPacket@[???]
                       Unresolved local var: float curtime@[???] */
  ppVar13 = g_pLagData[0].pNext;
  if (gFakeLag <= 0.0) {
    while ((ppVar13 != (packetlag_t *)0x0 && (ppVar13 != g_pLagData))) {
      ppVar3 = ppVar13->pNext;
      ppVar13->pPrev->pNext = ppVar3;
      ppVar13->pNext->pPrev = ppVar13->pPrev;
      ppVar13->pPrev = (packetlag_s *)0x0;
      ppVar13->pNext = (packetlag_s *)0x0;
      if (ppVar13->pPacketData != (uchar *)0x0) {
        Mem_Free(ppVar13->pPacketData);
        ppVar13->pPacketData = (uchar *)0x0;
      }
      Mem_Free(ppVar13);
      ppVar13 = ppVar3;
    }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[0].pPrev = g_pLagData;
    g_pLagData[0].pNext = g_pLagData;
    ppVar13 = g_pLagData[2].pNext;
    while ((ppVar13 != (packetlag_t *)0x0 && (ppVar13 != g_pLagData + 2))) {
      ppVar3 = ppVar13->pNext;
      ppVar13->pPrev->pNext = ppVar3;
      ppVar13->pNext->pPrev = ppVar13->pPrev;
      ppVar13->pPrev = (packetlag_s *)0x0;
      ppVar13->pNext = (packetlag_s *)0x0;
      if (ppVar13->pPacketData != (uchar *)0x0) {
        Mem_Free(ppVar13->pPacketData);
        ppVar13->pPacketData = (uchar *)0x0;
      }
      Mem_Free(ppVar13);
      ppVar13 = ppVar3;
    }
    g_pLagData[2].pNext = g_pLagData + 2;
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[2].pPrev = g_pLagData + 2;
    if ((g_pLagData[1].pNext != g_pLagData + 1) &&
       (ppVar13 = g_pLagData[1].pNext, g_pLagData[1].pNext != (packetlag_t *)0x0)) {
      do {
        ppVar3 = ppVar13->pNext;
        ppVar13->pPrev->pNext = ppVar3;
        ppVar13->pNext->pPrev = ppVar13->pPrev;
        ppVar13->pPrev = (packetlag_s *)0x0;
        ppVar13->pNext = (packetlag_s *)0x0;
        if (ppVar13->pPacketData != (uchar *)0x0) {
          Mem_Free(ppVar13->pPacketData);
          ppVar13->pPacketData = (uchar *)0x0;
        }
        Mem_Free(ppVar13);
      } while ((ppVar3 != (packetlag_s *)0x0) && (ppVar13 = ppVar3, ppVar3 != g_pLagData + 1));
    }
    g_pLagData[1].pPrev = g_pLagData + 1;
    qVar9 = false;
    g_pLagData[1].pNext = g_pLagData + 1;
  }
  else {
    ppVar13 = g_pLagData[sock].pNext;
    if (g_pLagData + sock == ppVar13) {
LAB_000b0730:
      qVar9 = false;
    }
    else {
      fVar1 = ppVar13->receivedTime;
      while ((float)realtime - gFakeLag / 1000.0 < fVar1) {
        ppVar13 = ppVar13->pNext;
        if (g_pLagData + sock == ppVar13) goto LAB_000b0730;
        fVar1 = ppVar13->receivedTime;
      }
      ppVar13->pPrev->pNext = ppVar13->pNext;
      ppVar13->pNext->pPrev = ppVar13->pPrev;
      iVar2 = ppVar13->nSize;
      ppVar13->pPrev = (packetlag_s *)0x0;
      ppVar13->pNext = (packetlag_s *)0x0;
      Q_memcpy(in_message.data,ppVar13->pPacketData,iVar2);
      in_from.type = (ppVar13->net_from).type;
      in_from.ip = *&(ppVar13->net_from).ip;
      in_from.ipx._0_4_ = *(undefined4 *)(ppVar13->net_from).ipx;
      in_from.ipx._4_4_ = *(undefined4 *)((ppVar13->net_from).ipx + 4);
      in_from._16_4_ = *(undefined4 *)((ppVar13->net_from).ipx + 8);
      in_message.cursize = iVar2;
      if (ppVar13->pPacketData != (uchar *)0x0) {
        free(ppVar13->pPacketData);
      }
      Mem_Free(ppVar13);
      qVar9 = true;
    }
  }
LAB_000b0732:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar9;
}


// NET_RemoveFromPacketList  @ 000afb50
void NET_RemoveFromPacketList(packetlag_t *pPacket)

{
  pPacket->pPrev->pNext = pPacket->pNext;
  pPacket->pNext->pPrev = pPacket->pPrev;
  pPacket->pPrev = (packetlag_s *)0x0;
  pPacket->pNext = (packetlag_s *)0x0;
  return;
}


// NET_SendLong  @ 000b1450
int NET_SendLong(netsrc_t sock,int s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  ushort uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  qboolean qVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int in_GS_OFFSET;
  char *local_5e4;
  int local_5e0;
  char local_5ca;
  undefined4 local_598;
  int32 local_594;
  char local_590;
  undefined1 local_58f [1391];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((sock == NS_SERVER) && (0x578 < len)) {
                    /* Unresolved local var: char[1400] packet@[???]
                       Unresolved local var: int totalSent@[???]
                       Unresolved local var: int ret@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int packetCount@[???]
                       Unresolved local var: int packetNumber@[???]
                       Unresolved local var: SPLITPACKET * pPacket@[???] */
    NET_SendLong::gSequenceNumber = NET_SendLong::gSequenceNumber + 1;
    if (NET_SendLong::gSequenceNumber < 0) {
      NET_SendLong::gSequenceNumber = 1;
    }
    local_598 = 0xfffffffe;
    local_5e4 = buf;
    local_5e0 = 1;
    uVar4 = (len + 0x56eU) / 0x56f;
    local_5ca = '\0';
    iVar8 = 0;
    local_594 = NET_SendLong::gSequenceNumber;
    do {
      uVar7 = 0x56f;
      if ((uint)len < 0x570) {
        uVar7 = len;
      }
      local_590 = local_5ca * '\x10' + (char)uVar4;
      __memcpy_chk(local_58f,local_5e4,uVar7,0x56f);
      if (net_showpackets.value == 4.0) {
                    /* Unresolved local var: netadr_t adr@[???] */
        if (to->sa_family == 2) {
          uVar1 = *(ushort *)to->sa_data;
          uVar2 = *(uint *)(to->sa_data + 2);
          Q_memset(NET_AdrToString::s,0,0x40);
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
          __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",uVar2 & 0xff,
                         uVar2 >> 8 & 0xff,uVar2 >> 0x10 & 0xff,uVar2 >> 0x18,
                         uVar1 >> 8 | uVar1 << 8);
        }
        else {
          Q_memset(NET_AdrToString::s,0,0x40);
        }
        Con_DPrintf("Sending split %i of %i with %i bytes and seq %i to %s\n",local_5e0,uVar4,uVar7,
                    NET_SendLong::gSequenceNumber,NET_AdrToString::s);
      }
      qVar5 = NET_IsSteamFakeIP(NS_SERVER,to);
      if (qVar5 == 0) {
        iVar6 = sendto(s,&local_598,uVar7 + 9,flags,(sockaddr *)to,tolen);
      }
      else {
        iVar6 = NET_SteamFakeIPSendTo(NS_SERVER,s,(char *)&local_598,uVar7 + 9,flags,to,tolen);
      }
      if (iVar6 < 0) break;
      bVar3 = (int)uVar7 <= iVar6;
      iVar6 = iVar8;
      if (bVar3) {
        iVar6 = iVar8 + uVar7;
      }
      len = len - uVar7;
      local_5e0 = local_5e0 + 1;
      local_5ca = local_5ca + '\x01';
      local_5e4 = local_5e4 + 0x56f;
      iVar8 = iVar6;
    } while (0 < len);
  }
  else {
                    /* Unresolved local var: int nSend@[???] */
    qVar5 = NET_IsSteamFakeIP(sock,to);
    if (qVar5 == 0) {
      iVar6 = sendto(s,buf,len,flags,(sockaddr *)to,tolen);
    }
    else {
      iVar6 = NET_SteamFakeIPSendTo(sock,s,buf,len,flags,to,tolen);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}


// NET_SendLoopPacket  @ 000afae0
void NET_SendLoopPacket(netsrc_t sock,int length,void *data,netadr_t to)

{
  uint uVar1;
  netsrc_t nVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: loopback_t * loop@[???] */
  nVar2 = sock ^ NS_SERVER;
  uVar1 = loopbacks[nVar2].send;
  loopbacks[nVar2].send = uVar1 + 1;
  Q_memcpy(loopbacks[nVar2].msgs + (uVar1 & 3),data,length);
  loopbacks[nVar2].msgs[uVar1 & 3].datalen = length;
  return;
}


// NET_SendPacket  @ 000b1800
void NET_SendPacket(netsrc_t sock,int length,void *data,netadr_t to)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int unaff_EBX;
  netsrc_t nVar5;
  int in_GS_OFFSET;
  undefined1 local_30 [4];
  uchar local_2c [4];
  int local_20;
  
                    /* Unresolved local var: int ret@[???]
                       Unresolved local var: sockaddr addr@[???]
                       Unresolved local var: int net_socket@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (to.type == NA_LOOPBACK) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: loopback_t * loop@[???] */
    nVar5 = sock ^ NS_SERVER;
    uVar1 = loopbacks[nVar5].send;
    loopbacks[nVar5].send = uVar1 + 1;
    Q_memcpy(loopbacks[nVar5].msgs + (uVar1 & 3),data,length);
    loopbacks[nVar5].msgs[uVar1 & 3].datalen = length;
  }
  else {
    if (to.type == NA_BROADCAST) {
      unaff_EBX = ip_sockets[sock];
      if (unaff_EBX == 0) goto LAB_000b18b7;
      Q_memset(local_30,0,0x10);
      local_30._0_2_ = 2;
      local_30._2_2_ = to.port;
      local_2c[0] = 0xff;
      local_2c[1] = 0xff;
      local_2c[2] = 0xff;
      local_2c[3] = 0xff;
    }
    else if (to.type == NA_IP) {
      unaff_EBX = ip_sockets[sock];
      if (unaff_EBX == 0) goto LAB_000b18b7;
      Q_memset(local_30,0,0x10);
      local_2c = to.ip;
      local_30._0_2_ = 2;
      local_30._2_2_ = to.port;
    }
    else {
      Sys_Error("NET_SendPacket: bad address type");
      Q_memset(local_30,0,0x10);
    }
    iVar2 = NET_SendLong(sock,unaff_EBX,data,length,0,(sockaddr *)local_30,0x10);
    if (iVar2 == -1) {
                    /* Unresolved local var: int err@[???] */
      piVar3 = __errno_location();
      iVar2 = *piVar3;
      if (((iVar2 != 0xb && iVar2 != 0x6f) && (iVar2 != 0x68)) &&
         ((to.type != NA_BROADCAST || (iVar2 != 99)))) {
        if (cls.state == ca_dedicated) {
          pcVar4 = strerror(iVar2);
          Con_Printf("NET_SendPacket ERROR: %s\n",pcVar4);
        }
        else if ((iVar2 == 0x69) || (iVar2 == 99)) {
          Q_memset(NET_AdrToString::s,0,0x40);
          if (to.type == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
            __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",to.ip[0],to.ip[1],
                           to.ip[2],to.ip[3],to.port >> 8 | to.port << 8);
          }
          pcVar4 = strerror(iVar2);
          Con_DPrintf("NET_SendPacket Warning: %s : %s\n",pcVar4,NET_AdrToString::s);
        }
        else {
          pcVar4 = strerror(iVar2);
          Sys_Error("NET_SendPacket ERROR: %s\n",pcVar4);
        }
      }
    }
  }
LAB_000b18b7:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// NET_SendToImpl  @ 000b1380
int NET_SendToImpl(netsrc_t sock,int s,char *packet,int len,int flags,sockaddr *to,int tolen)

{
  qboolean qVar1;
  ssize_t sVar2;
  int iVar3;
  
  qVar1 = NET_IsSteamFakeIP(sock,to);
  if (qVar1 == 0) {
    sVar2 = sendto(s,packet,len,flags,(sockaddr *)to,tolen);
    return sVar2;
  }
  iVar3 = NET_SteamFakeIPSendTo(sock,s,packet,len,flags,to,tolen);
  return iVar3;
}


// NET_ShouldUseSteamFakeIP  @ 000bb930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean NET_ShouldUseSteamFakeIP(void)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: bool bLanOnly@[???] */
  if (0.0 < sv_lan.value) {
    return 0;
  }
                    /* Unresolved local var: bool bLanOnly@[???] */
  iVar1 = PF_IsDedicatedServer();
  if (iVar1 == 0) {
    uVar2 = (uint)(0.0 < sv_use_steam_networking.value);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// NET_Shutdown  @ 000b2da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_Shutdown(void)

{
  packetlag_s *ppVar1;
  net_messages_s *pnVar2;
  net_messages_t *pnVar3;
  packetlag_t *ppVar4;
  netsrc_t socketnumber;
  netsrc_t nVar5;
  net_messages_t **ppnVar6;
  
  ppVar4 = g_pLagData[0].pNext;
  while ((ppVar4 != (packetlag_t *)0x0 && (ppVar4 != g_pLagData))) {
    ppVar1 = ppVar4->pNext;
    ppVar4->pPrev->pNext = ppVar1;
    ppVar4->pNext->pPrev = ppVar4->pPrev;
    ppVar4->pPrev = (packetlag_s *)0x0;
    ppVar4->pNext = (packetlag_s *)0x0;
    if (ppVar4->pPacketData != (uchar *)0x0) {
      Mem_Free(ppVar4->pPacketData);
      ppVar4->pPacketData = (uchar *)0x0;
    }
    Mem_Free(ppVar4);
    ppVar4 = ppVar1;
  }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
  g_pLagData[0].pPrev = g_pLagData;
  g_pLagData[0].pNext = g_pLagData;
  if ((g_pLagData[1].pNext != g_pLagData + 1) &&
     (ppVar4 = g_pLagData[1].pNext, g_pLagData[1].pNext != (packetlag_t *)0x0)) {
    do {
      ppVar1 = ppVar4->pNext;
      ppVar4->pPrev->pNext = ppVar1;
      ppVar4->pNext->pPrev = ppVar4->pPrev;
      ppVar4->pPrev = (packetlag_s *)0x0;
      ppVar4->pNext = (packetlag_s *)0x0;
      if (ppVar4->pPacketData != (uchar *)0x0) {
        Mem_Free(ppVar4->pPacketData);
        ppVar4->pPacketData = (uchar *)0x0;
      }
      Mem_Free(ppVar4);
    } while ((ppVar1 != (packetlag_s *)0x0) && (ppVar4 = ppVar1, ppVar1 != g_pLagData + 1));
  }
  g_pLagData[1].pPrev = g_pLagData + 1;
  g_pLagData[1].pNext = g_pLagData + 1;
                    /* Unresolved local var: int i@[???] */
  if (NET_Config::old_config != false) {
    NET_Config::old_config = false;
    socketnumber = NS_CLIENT;
    do {
      if (ip_sockets[socketnumber] != 0) {
        close(ip_sockets[socketnumber]);
        ip_sockets[socketnumber] = 0;
      }
      nVar5 = socketnumber + NS_SERVER;
      NET_SteamFakeIPDestroySocket(socketnumber);
      socketnumber = nVar5;
    } while (nVar5 != (NS_MULTICAST|NS_SERVER));
    net_configured = 0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: net_messages_t * p@[???]
                       Unresolved local var: net_messages_t * n@[???] */
  if ((use_thread != 0) && (net_thread_initialized != false)) {
    net_thread_initialized = false;
  }
  ppnVar6 = messages;
  do {
    pnVar3 = *ppnVar6;
    while (pnVar3 != (net_messages_t *)0x0) {
      pnVar2 = pnVar3->next;
      Mem_Free(pnVar3->buffer);
      Mem_Free(pnVar3);
      pnVar3 = pnVar2;
    }
    *ppnVar6 = (net_messages_t *)0x0;
    ppnVar6 = ppnVar6 + 1;
    pnVar3 = normalqueue;
  } while (ppnVar6 != (net_messages_t **)ip_sockets);
  while (pnVar3 != (net_messages_t *)0x0) {
    pnVar2 = pnVar3->next;
    Mem_Free(pnVar3->buffer);
    Mem_Free(pnVar3);
    pnVar3 = pnVar2;
  }
  normalqueue = (net_messages_t *)0x0;
  return;
}


// NET_Sleep  @ 000b0d70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int NET_Sleep(void)

{
  qboolean qVar1;
  byte bVar2;
  timeval *__timeout;
  int iVar3;
  int *piVar4;
  qboolean qVar5;
  __fd_mask *p_Var6;
  timeval local_a4;
  uint local_9c [35];
  
  p_Var6 = (__fd_mask *)local_9c;
                    /* Unresolved local var: fd_set fdset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int sock@[???]
                       Unresolved local var: timeval tv@[???]
                       Unresolved local var: int number@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: int __d0@[???]
                       Unresolved local var: int __d1@[???] */
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *p_Var6 = 0;
    p_Var6 = p_Var6 + 1;
  }
  piVar4 = ip_sockets;
  qVar5 = false;
  do {
    if (*piVar4 != false) {
                    /* Unresolved local var: ulong __d@[???] */
      iVar3 = __fdelt_chk(*piVar4);
      qVar1 = *piVar4;
      bVar2 = (byte)((int)qVar1 >> 0x1f);
      local_9c[iVar3] =
           local_9c[iVar3] | 1 << (((char)qVar1 + (bVar2 >> 3) & 0x1f) - (bVar2 >> 3) & 0x1f);
      if ((int)qVar5 < (int)qVar1) {
        qVar5 = qVar1;
      }
    }
    piVar4 = piVar4 + 1;
  } while ((qboolean *)piVar4 != &noip);
  local_a4.tv_sec = 0;
  __timeout = &local_a4;
  local_a4.tv_usec = 20000;
  if (net_sleepforever != 0) {
    __timeout = (timeval *)0x0;
  }
  iVar3 = select(qVar5 + true,(fd_set *)local_9c,(fd_set *)0x0,(fd_set *)0x0,__timeout);
  return iVar3;
}


// NET_Sleep_Timeout  @ 000b0c10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int NET_Sleep_Timeout(void)

{
  qboolean qVar1;
  int32 iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  __fd_mask *p_Var6;
  qboolean qVar7;
  double dVar8;
  timeval local_a4;
  fd_set local_9c;
  
                    /* Unresolved local var: fd_set fdset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int sock@[???]
                       Unresolved local var: timeval tv@[???]
                       Unresolved local var: int number@[???]
                       Unresolved local var: int fps@[???]
                       Unresolved local var: int32 curtime@[???] */
  iVar5 = (int)sys_ticrate.value;
  dVar8 = Sys_FloatTime();
  iVar3 = (int)dVar8;
  iVar2 = iVar3;
  if ((NET_Sleep_Timeout::lasttime != 0) &&
     (iVar2 = NET_Sleep_Timeout::lasttime, 1 < iVar3 - NET_Sleep_Timeout::lasttime)) {
    NET_Sleep_Timeout::staggerFrames = iVar5 / 100 + 1;
    NET_Sleep_Timeout::numFrames = iVar5;
    iVar2 = iVar3;
  }
  NET_Sleep_Timeout::lasttime = iVar2;
                    /* Unresolved local var: int __d0@[???]
                       Unresolved local var: int __d1@[???] */
  iVar3 = 0x20;
  p_Var6 = local_9c.fds_bits;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    *p_Var6 = 0;
    p_Var6 = p_Var6 + 1;
  }
  piVar4 = ip_sockets;
  qVar7 = false;
  do {
    if (*piVar4 != false) {
                    /* Unresolved local var: ulong __d@[???] */
      iVar3 = __fdelt_chk(*piVar4);
      qVar1 = *piVar4;
      local_9c.fds_bits[iVar3] = local_9c.fds_bits[iVar3] | 1 << ((byte)((int)qVar1 % 0x20) & 0x1f);
      if ((int)qVar7 < (int)qVar1) {
        qVar7 = qVar1;
      }
    }
    piVar4 = piVar4 + 1;
  } while ((qboolean *)piVar4 != &noip);
  local_a4.tv_sec = 0;
  local_a4.tv_usec = (int)(1000 / (longlong)iVar5) * 1000;
  if (local_a4.tv_usec < 1) {
    local_a4.tv_usec = 1;
  }
  if ((NET_Sleep_Timeout::numFrames < 1) ||
     (NET_Sleep_Timeout::numFrames % NET_Sleep_Timeout::staggerFrames == 0)) {
    iVar3 = select(0,(fd_set *)0x0,(fd_set *)0x0,(fd_set *)0x0,&local_a4);
  }
  else {
    iVar3 = select(qVar7 + true,&local_9c,(fd_set *)0x0,(fd_set *)0x0,&local_a4);
  }
  NET_Sleep_Timeout::numFrames = NET_Sleep_Timeout::numFrames + -1;
  return iVar3;
}


// NET_StartThread  @ 000b0e20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_StartThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized == false)) {
    net_thread_initialized = true;
  }
  return;
}


// NET_SteamFakeIPDestroySocket  @ 000bac20
void NET_SteamFakeIPDestroySocket(netsrc_t socketnumber)

{
  ISteamNetworkingFakeUDPPort *pIVar1;
  
  if (((int)socketnumber < 3) &&
     (pIVar1 = ip_fakeudpports[socketnumber], pIVar1 != (ISteamNetworkingFakeUDPPort *)0x0)) {
    (*(code *)**(undefined4 **)pIVar1)(pIVar1);
    ip_fakeudpports[socketnumber] = (ISteamNetworkingFakeUDPPort *)0x0;
  }
  return;
}


// NET_SteamFakeIPRecvFrom  @ 000ba9f0
int NET_SteamFakeIPRecvFrom
              (netsrc_t socketnumber,char *packet,int max_len,int flags,int ret,sockaddr *from,
              socklen_t *fromlen)

{
  char cVar1;
  undefined2 uVar2;
  ISteamNetworkingFakeUDPPort *pIVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  byte bVar13;
  undefined4 *local_94;
  undefined1 local_90 [128];
  int local_10;
  
                    /* Unresolved local var: ISteamNetworkingFakeUDPPort * pFakeUDPPort@[???] */
  bVar13 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pIVar3 = ip_fakeudpports[socketnumber];
                    /* Unresolved local var: SteamNetworkingMessage_t * pMsg@[???] */
  if ((pIVar3 != (ISteamNetworkingFakeUDPPort *)0x0) &&
     (iVar6 = (**(code **)(*(int *)pIVar3 + 8))(pIVar3,&local_94,1), iVar6 == 1)) {
    if (local_94[3] == 1) {
      uVar4 = local_94[1];
      if (max_len < (int)uVar4) {
        puVar9 = local_94 + 5;
        puVar7 = (undefined4 *)
                 SteamInternal_ContextInit
                           (SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
        (**(code **)(*(int *)*puVar7 + 0x50))((int *)*puVar7,puVar9,local_90,0x30,1);
        Con_Printf("Ignoring message of size %d on FakeUDP port %d from %s\n",local_94[1],
                   (uint)g_arFakePorts[0],local_90);
      }
      else {
        if (from != (sockaddr *)0x0) {
                    /* Unresolved local var: sockaddr_in * from_ipv4@[???] */
          from->sa_family = 2;
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
          uVar8 = 0;
          if (((local_94[6] == 0 && local_94[5] == 0) && (*(short *)(local_94 + 7) == 0)) &&
             (*(short *)((int)local_94 + 0x1e) == -1)) {
            uVar8 = local_94[8];
            uVar8 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
          }
          *(uint *)(from->sa_data + 2) =
               uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
          *(ushort *)from->sa_data = (ushort)local_94[9] >> 8 | (ushort)local_94[9] << 8;
        }
        pcVar10 = (char *)*local_94;
        uVar8 = uVar4;
        if (7 < uVar4) {
          pcVar12 = packet;
          if (((uint)packet & 1) != 0) {
            cVar1 = *pcVar10;
            pcVar12 = packet + 1;
            pcVar10 = pcVar10 + 1;
            uVar8 = uVar4 - 1;
            *packet = cVar1;
          }
          pcVar11 = pcVar12;
          if (((uint)pcVar12 & 2) != 0) {
            uVar2 = *(undefined2 *)pcVar10;
            pcVar11 = pcVar12 + 2;
            pcVar10 = pcVar10 + 2;
            uVar8 = uVar8 - 2;
            *(undefined2 *)pcVar12 = uVar2;
          }
          packet = pcVar11;
          if (((uint)pcVar11 & 4) != 0) {
            uVar5 = *(undefined4 *)pcVar10;
            packet = pcVar11 + 4;
            pcVar10 = pcVar10 + 4;
            uVar8 = uVar8 - 4;
            *(undefined4 *)pcVar11 = uVar5;
          }
        }
        for (; ret = uVar4, uVar8 != 0; uVar8 = uVar8 - 1) {
          *packet = *pcVar10;
          pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
          packet = packet + (uint)bVar13 * -2 + 1;
        }
      }
    }
    else {
      puVar9 = local_94 + 3;
      puVar7 = (undefined4 *)
               SteamInternal_ContextInit(SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar7 + 0x5c))((int *)*puVar7,puVar9,local_90,0x80);
      Con_Printf("Ignoring message on FakeUDP port %d from %s -- not a fakeUDP identity?\n",
                 (uint)g_arFakePorts[0],local_90);
    }
    (*(code *)local_94[0x2c])(local_94);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ret;
}


// NET_SteamFakeIPSendTo  @ 000ba8b0
int NET_SteamFakeIPSendTo
              (netsrc_t socketnumber,int s,char *packet,int len,int flags,sockaddr *to,int tolen)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_GS_OFFSET;
  undefined4 local_62;
  undefined4 local_5e;
  undefined2 local_5a;
  undefined2 local_58;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  ushort local_52;
  undefined1 local_50 [48];
  int local_20;
  
                    /* Unresolved local var: ISteamNetworkingFakeUDPPort * pFakeUDPPort@[???]
                       Unresolved local var: sockaddr_in * to_addr_ipv4@[???]
                       Unresolved local var: uint32 nIPv4@[???]
                       Unresolved local var: SteamNetworkingIPAddr addrSteamNetworking@[???]
                       Unresolved local var: EResult r@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
  uVar1 = *(undefined4 *)(to->sa_data + 2);
  local_62 = 0;
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
  local_54 = (undefined1)((uint)uVar1 >> 0x10);
  local_55 = (undefined1)((uint)uVar1 >> 8);
  local_56 = (undefined1)uVar1;
  local_52 = *(ushort *)to->sa_data >> 8 | *(ushort *)to->sa_data << 8;
  local_5e = 0;
  local_5a = 0;
  local_58 = 0xffff;
  local_53 = (undefined1)((uint)uVar1 >> 0x18);
  iVar2 = (**(code **)(*(int *)ip_fakeudpports[socketnumber] + 4))
                    (ip_fakeudpports[socketnumber],&local_62,packet,len,1);
  if (iVar2 != 1) {
    puVar3 = (undefined4 *)
             SteamInternal_ContextInit(SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar3 + 0x50))((int *)*puVar3,&local_62,local_50,0x30,1);
    Con_Printf("SendMessageToFakeIP to %s returned %d\n",local_50,iVar2);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return len;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// NET_StopThread  @ 000b0e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_StopThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized != false)) {
    net_thread_initialized = false;
  }
  return;
}


// NET_StringToAdr  @ 000af7f0
qboolean NET_StringToAdr(char *s,netadr_t *a)

{
  int iVar1;
  qboolean qVar2;
  long lVar3;
  hostent *phVar4;
  char *__nptr;
  int in_GS_OFFSET;
  short local_a0;
  ushort local_9e;
  in_addr_t local_9c;
  char local_90 [127];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: sockaddr sadr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = Q_strcmp(s,"localhost");
  if ((iVar1 == 0) || (iVar1 = Q_strcmp(s,"127.0.0.1"), iVar1 == 0)) {
    Q_memset(a,0,0x14);
    qVar2 = true;
    a->type = NA_LOOPBACK;
  }
  else {
                    /* Unresolved local var: sockaddr sadr@[???]
                       Unresolved local var: hostent * h@[???]
                       Unresolved local var: char * colon@[???]
                       Unresolved local var: int val@[???]
                       Unresolved local var: char[128] copy@[???] */
    Q_memset(&local_a0,0,0x10);
    __nptr = local_90;
    local_a0 = 2;
    local_9e = 0;
    Q_strncpy(local_90,s,0x7f);
    local_11 = 0;
    while (local_90[0] != '\0') {
      while (__nptr = __nptr + 1, local_90[0] != ':') {
        local_90[0] = *__nptr;
        if (local_90[0] == '\0') goto LAB_000af920;
      }
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      __nptr[-1] = '\0';
      lVar3 = strtol(__nptr,(char **)0x0,10);
      local_9e = (ushort)lVar3 >> 8 | (ushort)lVar3 << 8;
      local_90[0] = *__nptr;
    }
LAB_000af920:
    local_9c = inet_addr(local_90);
    if (local_9c == 0xffffffff) {
      phVar4 = gethostbyname(local_90);
      if (phVar4 == (hostent *)0x0) {
        qVar2 = false;
        goto LAB_000af862;
      }
      local_9c = *(in_addr_t *)*phVar4->h_addr_list;
    }
    if (local_a0 == 2) {
      a->type = NA_IP;
      *(in_addr_t *)a->ip = local_9c;
      a->port = local_9e;
    }
    qVar2 = true;
  }
LAB_000af862:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// NET_StringToSockaddr  @ 000af6d0
qboolean NET_StringToSockaddr(char *s,sockaddr *sadr)

{
  long lVar1;
  in_addr_t iVar2;
  qboolean qVar3;
  hostent *phVar4;
  char *__nptr;
  int in_GS_OFFSET;
  char local_90 [127];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: hostent * h@[???]
                       Unresolved local var: char * colon@[???]
                       Unresolved local var: int val@[???]
                       Unresolved local var: char[128] copy@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(sadr,0,0x10);
  sadr->sa_family = 2;
  sadr->sa_data[0] = '\0';
  sadr->sa_data[1] = '\0';
  __nptr = local_90;
  Q_strncpy(local_90,s,0x7f);
  local_11 = 0;
  while (local_90[0] != '\0') {
    while (__nptr = __nptr + 1, local_90[0] != ':') {
      local_90[0] = *__nptr;
      if (local_90[0] == '\0') goto LAB_000af790;
    }
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
    __nptr[-1] = '\0';
    lVar1 = strtol(__nptr,(char **)0x0,10);
    *(ushort *)sadr->sa_data = (ushort)lVar1 >> 8 | (ushort)lVar1 << 8;
    local_90[0] = *__nptr;
  }
LAB_000af790:
  iVar2 = inet_addr(local_90);
  *(in_addr_t *)(sadr->sa_data + 2) = iVar2;
  if (iVar2 == 0xffffffff) {
    phVar4 = gethostbyname(local_90);
    if (phVar4 == (hostent *)0x0) {
      qVar3 = false;
      goto LAB_000af7a3;
    }
    *(undefined4 *)(sadr->sa_data + 2) = *(undefined4 *)*phVar4->h_addr_list;
  }
  qVar3 = true;
LAB_000af7a3:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// NET_ThreadLock  @ 000af330
void NET_ThreadLock(void)

{
  return;
}


// NET_ThreadUnlock  @ 000af340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_ThreadUnlock(void)

{
  return;
}


// NET_TransferRawData  @ 000af9e0
void NET_TransferRawData(sizebuf_t *msg,uchar *pStart,int nSize)

{
  Q_memcpy(msg->data,pStart,nSize);
  msg->cursize = nSize;
  return;
}


