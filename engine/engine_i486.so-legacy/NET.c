// NET_AddToLagged  @ 000c4930
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


// NET_AdjustLag  @ 000c4a00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_AdjustLag(void)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: double dt@[???]
                       Unresolved local var: float diff@[???]
                       Unresolved local var: float converge@[???] */
  lVar3 = (longdouble)realtime - (longdouble)NET_AdjustLag::lasttime;
  lVar4 = (longdouble)0;
  if (((longdouble)0 <= lVar3) && (lVar4 = lVar3, (longdouble)0.1 < lVar3)) {
    lVar4 = (longdouble)0.1;
  }
  NET_AdjustLag::lasttime = realtime;
  if ((sv_cheats.value == 0.0) && (fakelag.value != 0.0)) {
    Con_Printf("Server must enable cheats to activate fakelag\n");
    Cvar_SetValue("fakelag",0.0);
    gFakeLag = 0.0;
    return;
  }
  if (gFakeLag != fakelag.value) {
    fVar1 = ABS(fakelag.value - gFakeLag);
    fVar2 = (float)(lVar4 * (longdouble)200.0);
    if (fVar1 < (float)(lVar4 * (longdouble)200.0)) {
      fVar2 = fVar1;
    }
    if (fakelag.value - gFakeLag < 0.0) {
      fVar2 = -fVar2;
    }
    gFakeLag = fVar2 + gFakeLag;
    return;
  }
  return;
}


// NET_AdrToString  @ 000c43a0
char * NET_AdrToString(netadr_t a)

{
  Q_memset(NET_AdrToString::s_1,0,0x40);
  if (a.type == NA_LOOPBACK) {
    snprintf(NET_AdrToString::s_1,0x40,"loopback");
  }
  else if (a.type == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
    snprintf(NET_AdrToString::s_1,0x40,"%i.%i.%i.%i:%i",(uint)a.ip[0],(uint)a.ip[1],(uint)a.ip[2],
             (uint)a.ip[3],(uint)(ushort)(a.port >> 8 | a.port << 8));
  }
  return NET_AdrToString::s_1;
}


// NET_AllocMsg  @ 000c5d00
net_messages_t * NET_AllocMsg(int size)

{
  net_messages_t *pnVar1;
  uchar *puVar2;
  
                    /* Unresolved local var: net_messages_t * pmsg@[???] */
  pnVar1 = normalqueue;
  if ((size < 0x601) && (normalqueue != (net_messages_t *)0x0)) {
    normalqueue->buffersize = size;
    normalqueue = normalqueue->next;
    return pnVar1;
  }
                    /* Unresolved local var: uchar * pbuffer@[???] */
  pnVar1 = Mem_ZeroMalloc(0x24);
                    /* Unresolved local var: uchar * pbuffer@[???] */
  puVar2 = Mem_ZeroMalloc(size);
  pnVar1->buffersize = size;
  pnVar1->preallocated = false;
  pnVar1->buffer = puVar2;
  return pnVar1;
}


// NET_AllocateQueues  @ 000c6000
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
  }
  return;
}


// NET_BaseAdrToString  @ 000c4450
char * NET_BaseAdrToString(netadr_t a)

{
  Q_memset(NET_BaseAdrToString::s,0,0x40);
  if (a.type == NA_LOOPBACK) {
    snprintf(NET_BaseAdrToString::s,0x40,"loopback");
  }
  else if (a.type == NA_IP) {
    snprintf(NET_BaseAdrToString::s,0x40,"%i.%i.%i.%i",(uint)a.ip[0],(uint)a.ip[1],(uint)a.ip[2],
             (uint)a.ip[3]);
    return NET_BaseAdrToString::s;
  }
  return NET_BaseAdrToString::s;
}


// NET_ClearLagData  @ 000c7410
void NET_ClearLagData(qboolean bClient,qboolean bServer)

{
  packetlag_t *ppVar1;
  packetlag_t *ppVar2;
  packetlag_s *p;
  
  if (bClient != false) {
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    ppVar1 = g_pLagData[0].pNext;
    if (g_pLagData[0].pNext != g_pLagData) {
      do {
        if (ppVar1 == (packetlag_t *)0x0) break;
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
        ppVar1 = ppVar2;
      } while (ppVar2 != g_pLagData);
    }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[0].pPrev = g_pLagData;
    g_pLagData[0].pNext = g_pLagData;
    ppVar1 = g_pLagData[2].pNext;
    if (g_pLagData[2].pNext != g_pLagData + 2) {
      do {
        if (ppVar1 == (packetlag_t *)0x0) break;
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
        ppVar1 = ppVar2;
      } while (ppVar2 != g_pLagData + 2);
    }
    g_pLagData[2].pPrev = g_pLagData + 2;
    g_pLagData[2].pNext = g_pLagData + 2;
  }
  if (bServer != false) {
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    if ((g_pLagData[1].pNext != (packetlag_s *)0x0) &&
       (p = g_pLagData[1].pNext, g_pLagData[1].pNext != g_pLagData + 1)) {
      do {
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
      } while ((ppVar1 != g_pLagData + 1) && (p = ppVar1, ppVar1 != (packetlag_t *)0x0));
    }
    g_pLagData[1].pPrev = g_pLagData + 1;
    g_pLagData[1].pNext = g_pLagData + 1;
    return;
  }
  return;
}


// NET_ClearLaggedList  @ 000c48b0
void NET_ClearLaggedList(packetlag_t *pList)

{
  packetlag_s *ppVar1;
  packetlag_t *p;
  
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
  p = pList->pNext;
  while ((pList != p && (p != (packetlag_t *)0x0))) {
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


// NET_CompareAdr  @ 000c4280
qboolean NET_CompareAdr(netadr_t a,netadr_t b)

{
  qboolean qVar1;
  
  qVar1 = false;
  if ((((b.type == a.type) && (qVar1 = true, b.type != NA_LOOPBACK)) &&
      (qVar1 = false, b.type == NA_IP)) && (a.ip == b.ip)) {
    return (uint)(b.port == a.port);
  }
  return qVar1;
}


// NET_CompareBaseAdr  @ 000c4370
qboolean NET_CompareBaseAdr(netadr_t a,netadr_t b)

{
  qboolean qVar1;
  
  qVar1 = false;
  if (((b.type == a.type) && (qVar1 = true, b.type != NA_LOOPBACK)) &&
     (qVar1 = false, b.type == NA_IP)) {
    return (uint)(a.ip == b.ip);
  }
  return qVar1;
}


// NET_CompareClassBAdr  @ 000c42c0
qboolean NET_CompareClassBAdr(netadr_t a,netadr_t b)

{
  qboolean qVar1;
  
  qVar1 = false;
  if (((b.type == a.type) && (qVar1 = true, b.type != NA_LOOPBACK)) &&
     (qVar1 = false, b.type == NA_IP)) {
    return (uint)(b.ip._0_2_ == a.ip._0_2_);
  }
  return qVar1;
}


// NET_Config  @ 000c70b0
void NET_Config(qboolean multiplayer)

{
                    /* Unresolved local var: int i@[???] */
  if (NET_Config::old_config == multiplayer) {
    return;
  }
  NET_Config::old_config = multiplayer;
  if (multiplayer == false) {
    if (ip_sockets[0] != 0) {
      close(ip_sockets[0]);
      ip_sockets[0] = 0;
    }
    if (ip_sockets[1] != 0) {
      close(ip_sockets[1]);
      ip_sockets[1] = 0;
    }
    if (ip_sockets[2] != 0) {
      close(ip_sockets[2]);
      ip_sockets[2] = 0;
      net_configured = 0;
      return;
    }
  }
  else {
    if (noip == false) {
      NET_OpenIP();
    }
    if (NET_Config::bFirst != false) {
      NET_Config::bFirst = false;
      NET_GetLocalAddress();
    }
  }
  net_configured = (uint)(multiplayer != false);
  return;
}


// NET_CountLaggedList  @ 000c4880
int NET_CountLaggedList(packetlag_t *pList)

{
  int iVar1;
  packetlag_t *ppVar2;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: packetlag_t * p@[???] */
  iVar1 = 0;
  ppVar2 = pList->pNext;
  if ((pList != ppVar2) && (ppVar2 != (packetlag_t *)0x0)) {
    while( true ) {
      ppVar2 = ppVar2->pNext;
      iVar1 = iVar1 + 1;
      if (pList == ppVar2) break;
      if (ppVar2 == (packetlag_s *)0x0) {
        return iVar1;
      }
    }
  }
  return iVar1;
}


// NET_ErrorString  @ 000c46e0
char * NET_ErrorString(int code)

{
  char *pcVar1;
  
  pcVar1 = strerror(code);
  return pcVar1;
}


// NET_FlushQueues  @ 000c6070
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_FlushQueues(void)

{
  net_messages_s *pnVar1;
  net_messages_t *pnVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: net_messages_t * p@[???]
                       Unresolved local var: net_messages_t * n@[???] */
  if ((use_thread != 0) && (net_thread_initialized != false)) {
    net_thread_initialized = false;
  }
  iVar3 = 0;
  do {
    pnVar2 = messages[iVar3];
    while (pnVar2 != (net_messages_t *)0x0) {
      pnVar1 = pnVar2->next;
      Mem_Free(pnVar2->buffer);
      Mem_Free(pnVar2);
      pnVar2 = pnVar1;
    }
    messages[iVar3] = (net_messages_t *)0x0;
    iVar3 = iVar3 + 1;
    pnVar2 = normalqueue;
  } while (iVar3 != 3);
  while (pnVar2 != (net_messages_t *)0x0) {
    pnVar1 = pnVar2->next;
    Mem_Free(pnVar2->buffer);
    Mem_Free(pnVar2);
    pnVar2 = pnVar1;
  }
  normalqueue = (net_messages_t *)0x0;
  return;
}


// NET_FlushSocket  @ 000c4ef0
void NET_FlushSocket(netsrc_t sock)

{
  int __fd;
  ssize_t sVar1;
  undefined1 local_fe6 [4010];
  sockaddr local_3c;
  socklen_t local_2c [7];
  
                    /* Unresolved local var: sockaddr from@[???]
                       Unresolved local var: int fromlen@[???]
                       Unresolved local var: int net_socket@[???]
                       Unresolved local var: uchar[4010] buf@[???] */
  __fd = ip_sockets[sock];
  if (__fd != 0) {
    local_2c[0] = 0x10;
    do {
      sVar1 = recvfrom(__fd,local_fe6,0xfaa,0,&local_3c,local_2c);
    } while (0 < sVar1);
  }
  return;
}


// NET_FreeMsg  @ 000c5d80
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


// NET_GetLocalAddress  @ 000c6ce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_GetLocalAddress(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  netadrtype_t nVar4;
  ushort uVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  qboolean qVar9;
  uint uVar10;
  char local_23c [511];
  undefined1 local_3d;
  undefined1 local_3c [28];
  sockaddr local_20;
  socklen_t local_10;
  
                    /* Unresolved local var: char[512] buff@[???]
                       Unresolved local var: sockaddr_in address@[???]
                       Unresolved local var: int namelen@[???]
                       Unresolved local var: int net_error@[???] */
  Q_memset(&net_local_adr,0,0x14);
  if (noip != false) {
    Con_Printf("TCP/IP Disabled.\n");
    return;
  }
  iVar6 = Q_strcmp(ipname.string,"localhost");
  if (iVar6 == 0) {
    gethostname(local_23c,0x200);
  }
  else {
    Q_strncpy(local_23c,ipname.string,0x1ff);
  }
  local_3d = 0;
                    /* Unresolved local var: sockaddr sadr@[???] */
  iVar6 = Q_strcmp(local_23c,"localhost");
  if (iVar6 != 0) {
    iVar6 = Q_strcmp(local_23c,"127.0.0.1");
    if (iVar6 != 0) {
      qVar9 = NET_StringToSockaddr(local_23c,(sockaddr *)local_3c);
      if ((qVar9 != false) && (local_3c._0_2_ == 2)) {
        net_local_adr.ip[0] = local_3c[4];
        net_local_adr.ip[1] = local_3c[5];
        net_local_adr.ip[2] = local_3c[6];
        net_local_adr.ip[3] = local_3c[7];
        net_local_adr.type = NA_IP;
        net_local_adr.port = local_3c._2_2_;
      }
      goto LAB_000c6da1;
    }
  }
  Q_memset(&net_local_adr,0,0x14);
  net_local_adr.type = NA_LOOPBACK;
LAB_000c6da1:
  local_10 = 0x10;
  iVar6 = getsockname(ip_sockets[1],&local_20,&local_10);
  nVar4 = net_local_adr.type;
  if (iVar6 == 0) {
    uVar3 = (uint)net_local_adr.ip >> 8;
    uVar10 = (uint)net_local_adr.ip & 0xff;
    uVar2 = (uint)net_local_adr.ip >> 0x10;
    net_local_adr.port._0_1_ = local_20.sa_data[0];
    net_local_adr.port._1_1_ = local_20.sa_data[1];
    uVar1 = (uint)net_local_adr.ip >> 0x18;
    Q_memset(NET_AdrToString::s_1,0,0x40);
    if (nVar4 == NA_LOOPBACK) {
      snprintf(NET_AdrToString::s_1,0x40,"loopback");
    }
    else if (nVar4 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      snprintf(NET_AdrToString::s_1,0x40,"%i.%i.%i.%i:%i",uVar10,uVar3 & 0xff,uVar2 & 0xff,uVar1,
               (uint)(ushort)((ushort)local_20.sa_data._0_2_ >> 8 | local_20.sa_data._0_2_ << 8));
    }
    Con_Printf("Server IP address %s\n",NET_AdrToString::s_1);
    uVar5 = net_local_adr.port;
    nVar4 = net_local_adr.type;
    uVar3 = (uint)net_local_adr.ip >> 8;
    uVar10 = (uint)net_local_adr.ip & 0xff;
    uVar2 = (uint)net_local_adr.ip >> 0x10;
    uVar1 = (uint)net_local_adr.ip >> 0x18;
    Q_memset(NET_AdrToString::s_1,0,0x40);
    if (nVar4 == NA_LOOPBACK) {
      snprintf(NET_AdrToString::s_1,0x40,"loopback");
    }
    else if (nVar4 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      snprintf(NET_AdrToString::s_1,0x40,"%i.%i.%i.%i:%i",uVar10,uVar3 & 0xff,uVar2 & 0xff,uVar1,
               (uint)(ushort)(uVar5 >> 8 | uVar5 << 8));
    }
    pcVar7 = va("%s",NET_AdrToString::s_1);
    Cvar_Set("net_address",pcVar7);
    return;
  }
  piVar8 = __errno_location();
  noip = true;
  pcVar7 = strerror(*piVar8);
  Con_Printf("Could not get TCP/IP address, TCP/IP disabled\nReason:  %s\n",pcVar7);
  return;
}


// NET_GetLong  @ 000c4f70
qboolean NET_GetLong(uchar *pData,int size,int *outSize)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  qboolean qVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uchar *puVar13;
  char *pcVar14;
  byte bVar15;
  
                    /* Unresolved local var: int packetNumber@[???]
                       Unresolved local var: int packetCount@[???]
                       Unresolved local var: int sequenceNumber@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: uchar packetID@[???]
                       Unresolved local var: SPLITPACKET * pHeader@[???] */
  bVar15 = 0;
  bVar1 = pData[8];
  iVar9 = *(int *)(pData + 4);
  uVar11 = bVar1 & 0xf;
  uVar12 = (uint)(bVar1 >> 4);
  if ((5 < uVar11) || (4 < uVar12)) {
    Con_Printf("Malformed packet number (%i)\n",uVar12);
    return false;
  }
  if (((gNetSplit.currentSequence == -1) || (iVar9 != gNetSplit.currentSequence)) &&
     (gNetSplit.currentSequence = iVar9, gNetSplit.splitCount = uVar11, net_showpackets.value == 4.0
     )) {
    Con_Printf("<-- Split packet restart %i count %i seq\n",uVar11,iVar9);
    iVar10 = NET_GetLong::gNetSplitFlags[uVar12];
  }
  else {
    iVar10 = NET_GetLong::gNetSplitFlags[uVar12];
  }
  if (iVar10 == iVar9) {
    Con_Printf("NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes )\n",uVar12 + 1,
               uVar11,size + -9);
    uVar12 = gNetSplit.totalSize;
  }
  else {
    uVar5 = size - 9;
    if (uVar11 - 1 == uVar12) {
      gNetSplit.totalSize = uVar12 * 0x56f + uVar5;
    }
    gNetSplit.splitCount = gNetSplit.splitCount + -1;
    bVar4 = net_showpackets.value == 4.0;
    NET_GetLong::gNetSplitFlags[uVar12] = iVar9;
    if (bVar4) {
      Con_Printf("<-- Split packet %i of %i, %i bytes %i seq\n",uVar12 + 1,uVar11,uVar5,iVar9);
    }
    iVar9 = uVar12 * 0x56f;
    if (0xfaa < iVar9 + uVar5) {
      Con_Printf("Malformed packet size (%i, %i)\n",iVar9,uVar5);
      return false;
    }
    pcVar14 = gNetSplit.buffer + iVar9;
    puVar13 = pData + 9;
    if (7 < uVar5) {
      uVar12 = uVar5;
      if (((uint)pcVar14 & 1) != 0) {
        pcVar14 = gNetSplit.buffer + iVar9 + 1;
        uVar12 = size - 10;
        puVar13 = pData + 10;
        gNetSplit.buffer[iVar9] = pData[9];
      }
      if (((uint)pcVar14 & 2) != 0) {
        uVar2 = *(undefined2 *)puVar13;
        uVar12 = uVar12 - 2;
        puVar13 = puVar13 + 2;
        *(undefined2 *)pcVar14 = uVar2;
        pcVar14 = pcVar14 + 2;
      }
      if (((uint)pcVar14 & 4) != 0) {
        uVar3 = *(undefined4 *)puVar13;
        uVar12 = uVar12 - 4;
        puVar13 = puVar13 + 4;
        *(undefined4 *)pcVar14 = uVar3;
        pcVar14 = pcVar14 + 4;
      }
      uVar5 = uVar12 & 3;
      for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)puVar13;
        puVar13 = puVar13 + (uint)bVar15 * -8 + 4;
        pcVar14 = pcVar14 + ((uint)bVar15 * -2 + 1) * 4;
      }
    }
    iVar9 = 0;
    if ((uVar5 & 4) != 0) {
      *(undefined4 *)pcVar14 = *(undefined4 *)puVar13;
      iVar9 = 4;
    }
    if ((uVar5 & 2) != 0) {
      *(undefined2 *)(pcVar14 + iVar9) = *(undefined2 *)(puVar13 + iVar9);
      iVar9 = iVar9 + 2;
    }
    uVar12 = gNetSplit.totalSize;
    if ((uVar5 & 1) != 0) {
      pcVar14[iVar9] = puVar13[iVar9];
      uVar12 = gNetSplit.totalSize;
    }
  }
  qVar7 = false;
  gNetSplit.totalSize = uVar12;
  if (gNetSplit.splitCount < 1) {
                    /* Unresolved local var: int i@[???] */
    if ((bVar1 & 0xf) == 0) {
LAB_000c519c:
      gNetSplit.currentSequence = -1;
      if (uVar12 < 0xfab) {
        pcVar14 = gNetSplit.buffer;
        if (7 < uVar12) {
          uVar11 = uVar12;
          if (((uint)pData & 1) != 0) {
            pcVar14 = gNetSplit.buffer + 1;
            uVar11 = uVar12 - 1;
            *pData = gNetSplit.buffer[0];
            pData = pData + 1;
          }
          if (((uint)pData & 2) != 0) {
            uVar2 = *(undefined2 *)pcVar14;
            uVar11 = uVar11 - 2;
            pcVar14 = pcVar14 + 2;
            *(undefined2 *)pData = uVar2;
            pData = pData + 2;
          }
          if (((uint)pData & 4) != 0) {
            uVar3 = *(undefined4 *)pcVar14;
            uVar11 = uVar11 - 4;
            pcVar14 = pcVar14 + 4;
            *(undefined4 *)pData = uVar3;
            pData = pData + 4;
          }
          uVar12 = uVar11 & 3;
          for (uVar11 = uVar11 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined4 *)pData = *(undefined4 *)pcVar14;
            pcVar14 = pcVar14 + ((uint)bVar15 * -2 + 1) * 4;
            pData = pData + (uint)bVar15 * -8 + 4;
          }
        }
        iVar9 = 0;
        if ((uVar12 & 4) != 0) {
          *(undefined4 *)pData = *(undefined4 *)pcVar14;
          iVar9 = 4;
        }
        if ((uVar12 & 2) != 0) {
          *(undefined2 *)(pData + iVar9) = *(undefined2 *)(pcVar14 + iVar9);
          iVar9 = iVar9 + 2;
        }
        if ((uVar12 & 1) != 0) {
          pData[iVar9] = pcVar14[iVar9];
        }
        *outSize = gNetSplit.totalSize;
        qVar7 = true;
      }
      else {
        Con_Printf("Split packet too large! %d bytes\n",uVar12);
        qVar7 = false;
      }
    }
    else {
      if (NET_GetLong::gNetSplitFlags[0] == gNetSplit.currentSequence) {
        uVar5 = 0;
        do {
          uVar6 = uVar5;
          uVar5 = uVar6 + 1;
          if (uVar5 == uVar11) goto LAB_000c519c;
        } while (NET_GetLong::gNetSplitFlags[uVar5] == NET_GetLong::gNetSplitFlags[0]);
        iVar8 = uVar6 + 2;
        iVar9 = NET_GetLong::gNetSplitFlags[0];
        iVar10 = NET_GetLong::gNetSplitFlags[uVar5];
      }
      else {
        iVar8 = 1;
        iVar9 = gNetSplit.currentSequence;
        iVar10 = NET_GetLong::gNetSplitFlags[0];
      }
      Con_Printf("Split packet without all %i parts, part %i had wrong sequence %i/%i\n",uVar11,
                 iVar8,iVar10,iVar9);
      qVar7 = false;
    }
  }
  return qVar7;
}


// NET_GetLoopPacket  @ 000c4730
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


// NET_GetPacket  @ 000c5dc0
qboolean NET_GetPacket(netsrc_t sock)

{
  int iVar1;
  net_messages_t *p;
  uint uVar2;
  qboolean qVar3;
  
                    /* Unresolved local var: net_messages_t * pmsg@[???]
                       Unresolved local var: qboolean bret@[???] */
  NET_AdjustLag();
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
    iVar1 = loopbacks[sock].msgs[uVar2 & 3].datalen;
    Q_memcpy(in_message.data,loopbacks[sock].msgs + (uVar2 & 3),iVar1);
    in_message.cursize = iVar1;
    Q_memset(&in_from,0,0x14);
    in_from.type = NA_LOOPBACK;
    qVar3 = NET_LagPacket(true,sock,&in_from,&in_message);
  }
  else {
    if (use_thread == 0) {
      qVar3 = NET_QueuePacket(sock);
      if (qVar3 != false) goto LAB_000c5ed0;
    }
    qVar3 = NET_LagPacket(false,sock,(netadr_t *)0x0,(sizebuf_t *)0x0);
  }
  if (qVar3 == false) {
    p = messages[sock];
    qVar3 = false;
    if (p != (net_messages_t *)0x0) {
      messages[sock] = p->next;
      net_message.cursize = p->buffersize;
      Q_memcpy(net_message.data,p->buffer,net_message.cursize);
      net_from.type = (p->from).type;
      net_from.ip = *&(p->from).ip;
      net_from.ipx._0_4_ = *(undefined4 *)(p->from).ipx;
      net_from.ipx._4_4_ = *(undefined4 *)((p->from).ipx + 4);
      net_from._16_4_ = *(undefined4 *)((p->from).ipx + 8);
      msg_readcount = 0;
      if (p->preallocated == false) {
        Mem_Free(p->buffer);
        Mem_Free(p);
        return true;
      }
      p->next = normalqueue;
      qVar3 = true;
      normalqueue = p;
    }
    return qVar3;
  }
LAB_000c5ed0:
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
  return qVar3;
}


// NET_HostToNetShort  @ 000c4270
ushort NET_HostToNetShort(ushort us_in)

{
                    /* Unresolved local var: ushort __v@[DW_OP_reg0(EAX)]
                       Unresolved local var: ushort __x@[???] */
  return us_in >> 8 | us_in << 8;
}


// NET_IPSocket  @ 000c6780
/* WARNING: Type propagation algorithm not settling */

int NET_IPSocket(char *net_interface,int port,qboolean multicast)

{
  int __fd;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  sockaddr local_3c;
  undefined4 local_28;
  uint local_24 [5];
  
                    /* Unresolved local var: int newsocket@[???]
                       Unresolved local var: sockaddr_in address@[???]
                       Unresolved local var: qboolean _true@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int err@[???] */
  local_24[0] = 1;
  local_28 = 1;
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
    iVar1 = ioctl(__fd,0x5421,&local_28);
    if (iVar1 == -1) {
      piVar2 = __errno_location();
      __fd = 0;
      pcVar3 = strerror(*piVar2);
      Con_Printf("WARNING: UDP_OpenSocket: port: %d  ioctl FIONBIO: %s\n",port,pcVar3);
    }
    else {
      iVar1 = setsockopt(__fd,1,6,local_24,4);
      if (iVar1 == -1) {
        piVar2 = __errno_location();
        __fd = 0;
        pcVar3 = strerror(*piVar2);
        Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt SO_BROADCAST: %s\n",port,pcVar3);
      }
      else {
        iVar1 = COM_CheckParm("-reuse");
        if (((iVar1 == 0) && (multicast == false)) ||
           (iVar1 = setsockopt(__fd,1,2,&local_28,4), iVar1 != -1)) {
          iVar1 = COM_CheckParm("-tos");
          if (iVar1 != 0) {
                    /* Unresolved local var: int tos@[???] */
            local_24[1] = 0x10;
            Con_Printf("Enabling LOWDELAY TOS option\n");
            iVar1 = setsockopt(__fd,0,1,local_24 + 1,4);
            if (iVar1 < 0) {
              piVar2 = __errno_location();
              if (*piVar2 != 0x5c) {
                pcVar3 = strerror(*piVar2);
                Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt IP_TOS: %s\n",port,pcVar3)
                ;
                return 0;
              }
            }
          }
          if (((net_interface == (char *)0x0) || (*net_interface == '\0')) ||
             (iVar1 = Q_stricmp(net_interface,"localhost"), iVar1 == 0)) {
            local_3c.sa_data[2] = '\0';
            local_3c.sa_data[3] = '\0';
            local_3c.sa_data[4] = '\0';
            local_3c.sa_data[5] = '\0';
          }
          else {
            NET_StringToSockaddr(net_interface,(sockaddr *)&local_3c);
          }
          if (port == -1) {
            local_3c.sa_data[0] = '\0';
            local_3c.sa_data[1] = '\0';
          }
          else {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
            local_3c.sa_data._0_2_ = (ushort)port >> 8 | (ushort)port << 8;
          }
          local_3c.sa_family = 2;
          iVar1 = bind(__fd,&local_3c,0x10);
          if (iVar1 == -1) {
            piVar2 = __errno_location();
            pcVar3 = strerror(*piVar2);
            Con_Printf("WARNING: UDP_OpenSocket: port: %d  bind: %s\n",port,pcVar3);
            close(__fd);
            __fd = 0;
          }
          else {
            iVar1 = COM_CheckParm("-loopback");
            local_24[0] = (uint)(iVar1 != 0);
            iVar1 = setsockopt(__fd,0,0x22,local_24,4);
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
  return __fd;
}


// NET_Init  @ 000c7190
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
  net_message.data = net_message_buffer;
  net_message.flags = 0;
  net_message.buffername = "net_message";
  in_message.maxsize = 0x10000;
  in_message.data = in_message_buf;
  in_message.flags = 0;
  g_pLagData[1].pNext = g_pLagData + 1;
  net_message.maxsize = 0x10000;
  g_pLagData[2].pPrev = g_pLagData + 2;
  g_pLagData[1].pPrev = g_pLagData + 1;
  in_message.buffername = "in_message";
  g_pLagData[0].pPrev = g_pLagData;
  g_pLagData[0].pNext = g_pLagData;
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


// NET_IsConfigured  @ 000c70a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int NET_IsConfigured(void)

{
  return net_configured;
}


// NET_IsLocalAddress  @ 000c46b0
qboolean NET_IsLocalAddress(netadr_t adr)

{
  qboolean qVar1;
  
  qVar1 = true;
  if ((adr.type != NA_LOOPBACK) && (qVar1 = false, adr.type == NA_IP)) {
    return (uint)(adr.ip == (uchar  [4])0x100007f);
  }
  return qVar1;
}


// NET_IsReservedAdr  @ 000c4300
qboolean NET_IsReservedAdr(netadr_t a)

{
  qboolean qVar1;
  
  qVar1 = true;
  if ((a.type != NA_LOOPBACK) && (qVar1 = false, a.type == NA_IP)) {
    if ((a.ip[0] == '\x7f') || (a.ip[0] == '\n')) {
      return true;
    }
    if (a.ip[0] == 0xac) {
      if (0xf < a.ip[1]) {
        return (uint)(a.ip[1] < 0x20);
      }
    }
    else if (a.ip[0] == 0xc0) {
      return (uint)(0xa7 < a.ip[1]);
    }
  }
  return qVar1;
}


// NET_JoinGroup  @ 000c77d0
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


// NET_LagPacket  @ 000c4b20
qboolean NET_LagPacket(qboolean newdata,netsrc_t sock,netadr_t *from,sizebuf_t *data)

{
  float fVar1;
  int iVar2;
  float timestamp;
  packetlag_t *ppVar3;
  int32 iVar4;
  int iVar5;
  int iVar6;
  packetlag_s *ppVar7;
  
                    /* Unresolved local var: packetlag_t * pNewPacketLag@[???]
                       Unresolved local var: packetlag_t * pPacket@[???]
                       Unresolved local var: float curtime@[???] */
  fVar1 = fakeloss.value;
  if (gFakeLag <= 0.0) {
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    if ((g_pLagData[0].pNext != (packetlag_s *)0x0) &&
       (ppVar7 = g_pLagData[0].pNext, g_pLagData[0].pNext != g_pLagData)) {
      do {
        ppVar3 = ppVar7->pNext;
        ppVar7->pPrev->pNext = ppVar3;
        ppVar7->pNext->pPrev = ppVar7->pPrev;
        ppVar7->pPrev = (packetlag_s *)0x0;
        ppVar7->pNext = (packetlag_s *)0x0;
        if (ppVar7->pPacketData != (uchar *)0x0) {
          Mem_Free(ppVar7->pPacketData);
          ppVar7->pPacketData = (uchar *)0x0;
        }
        Mem_Free(ppVar7);
      } while ((ppVar3 != g_pLagData) && (ppVar7 = ppVar3, ppVar3 != (packetlag_t *)0x0));
    }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[0].pPrev = g_pLagData;
    g_pLagData[0].pNext = g_pLagData;
    if ((g_pLagData[2].pNext != (packetlag_s *)0x0) &&
       (ppVar7 = g_pLagData[2].pNext, g_pLagData[2].pNext != g_pLagData + 2)) {
      do {
        ppVar3 = ppVar7->pNext;
        ppVar7->pPrev->pNext = ppVar3;
        ppVar7->pNext->pPrev = ppVar7->pPrev;
        ppVar7->pPrev = (packetlag_s *)0x0;
        ppVar7->pNext = (packetlag_s *)0x0;
        if (ppVar7->pPacketData != (uchar *)0x0) {
          Mem_Free(ppVar7->pPacketData);
          ppVar7->pPacketData = (uchar *)0x0;
        }
        Mem_Free(ppVar7);
      } while ((ppVar3 != g_pLagData + 2) && (ppVar7 = ppVar3, ppVar3 != (packetlag_t *)0x0));
    }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
    g_pLagData[2].pPrev = g_pLagData + 2;
    g_pLagData[2].pNext = g_pLagData + 2;
    if ((g_pLagData[1].pNext != (packetlag_s *)0x0) &&
       (ppVar7 = g_pLagData[1].pNext, g_pLagData[1].pNext != g_pLagData + 1)) {
      do {
        ppVar3 = ppVar7->pNext;
        ppVar7->pPrev->pNext = ppVar3;
        ppVar7->pNext->pPrev = ppVar7->pPrev;
        ppVar7->pPrev = (packetlag_s *)0x0;
        ppVar7->pNext = (packetlag_s *)0x0;
        if (ppVar7->pPacketData != (uchar *)0x0) {
          Mem_Free(ppVar7->pPacketData);
          ppVar7->pPacketData = (uchar *)0x0;
        }
        Mem_Free(ppVar7);
      } while ((ppVar3 != g_pLagData + 1) && (ppVar7 = ppVar3, ppVar3 != (packetlag_t *)0x0));
    }
    g_pLagData[1].pPrev = g_pLagData + 1;
    g_pLagData[1].pNext = g_pLagData + 1;
    return newdata;
  }
  timestamp = (float)realtime;
  if (newdata != false) {
    if (fakeloss.value != 0.0) {
      if (sv_cheats.value == 0.0) {
        Cvar_SetValue("fakeloss",0.0);
      }
      else {
        iVar2 = NET_LagPacket::losscount[sock];
        NET_LagPacket::losscount[sock] = iVar2 + 1;
        if (0.0 < fVar1) {
          iVar4 = RandomLong(0,100);
          if (iVar4 <= (int)fakeloss.value) {
            return false;
          }
        }
        else {
                    /* Unresolved local var: int ninterval@[???] */
          iVar6 = (int)ABS(fVar1);
          iVar5 = 2;
          if (1 < iVar6) {
            iVar5 = iVar6;
          }
          if ((iVar2 + 1) % iVar5 == 0) {
            return false;
          }
        }
      }
    }
    ppVar3 = Mem_ZeroMalloc(0x28);
    NET_AddToLagged(sock,g_pLagData + sock,ppVar3,from,*data,timestamp);
  }
  ppVar3 = g_pLagData[sock].pNext;
  if (ppVar3 != g_pLagData + sock) {
    fVar1 = ppVar3->receivedTime;
    while( true ) {
      if (fVar1 <= timestamp - gFakeLag / 1000.0) {
        ppVar3->pPrev->pNext = ppVar3->pNext;
        ppVar3->pNext->pPrev = ppVar3->pPrev;
        iVar2 = ppVar3->nSize;
        ppVar3->pPrev = (packetlag_s *)0x0;
        ppVar3->pNext = (packetlag_s *)0x0;
        Q_memcpy(in_message.data,ppVar3->pPacketData,iVar2);
        in_from.type = (ppVar3->net_from).type;
        in_from.ip = *&(ppVar3->net_from).ip;
        in_from.ipx._0_4_ = *(undefined4 *)(ppVar3->net_from).ipx;
        in_from.ipx._4_4_ = *(undefined4 *)((ppVar3->net_from).ipx + 4);
        in_from._16_4_ = *(undefined4 *)((ppVar3->net_from).ipx + 8);
        in_message.cursize = iVar2;
        if (ppVar3->pPacketData != (uchar *)0x0) {
          free(ppVar3->pPacketData);
        }
        Mem_Free(ppVar3);
        return true;
      }
      ppVar3 = ppVar3->pNext;
      if (ppVar3 == g_pLagData + sock) break;
      fVar1 = ppVar3->receivedTime;
    }
  }
  return false;
}


// NET_LeaveGroup  @ 000c7860
qboolean NET_LeaveGroup(netsrc_t sock,netadr_t addr)

{
  int iVar1;
  int *piVar2;
  uchar local_14 [4];
  undefined4 local_10;
  
                    /* Unresolved local var: int net_socket@[???]
                       Unresolved local var: int err@[???]
                       Unresolved local var: ip_mreq mreq@[???] */
  local_10 = 0;
  local_14[0] = addr.ip[0];
  local_14[1] = addr.ip[1];
  local_14[2] = addr.ip[2];
  local_14[3] = addr.ip[3];
  iVar1 = setsockopt(ip_sockets[sock],0,0x24,local_14,8);
  if (iVar1 != -1) {
    return true;
  }
  piVar2 = __errno_location();
  return (uint)(*piVar2 == 0x61);
}


// NET_OpenIP  @ 000c6b30
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
  port_00 = 0;
  if (ip_sockets[1] == 0) {
    port_00 = (int)iphostport.value;
    if ((port_00 == 0) && (port_00 = (int)hostport.value, port_00 == 0)) {
      port_00 = (int)defport.value;
      hostport.value = defport.value;
    }
    ip_sockets[1] = NET_IPSocket(ipname.string,port_00,false);
    if ((ip_sockets[1] == 0) && (bVar1)) {
      Sys_Error("Couldn\'t allocate dedicated server IP port %d.",port_00);
    }
  }
  if (cls.state != ca_dedicated) {
    port = 0;
    if (ip_sockets[0] == 0) {
      port = (int)ip_clientport.value;
      if ((port == 0) && (port = (int)clientport.value, port == 0)) {
        port = -1;
      }
      ip_sockets[0] = NET_IPSocket(ipname.string,port,false);
      if (ip_sockets[0] == 0) {
        ip_sockets[0] = NET_IPSocket(ipname.string,-1,false);
      }
    }
    if ((ip_sockets[2] == 0) &&
       (ip_sockets[2] = NET_IPSocket(ipname.string,(int)multicastport.value,true),
       ip_sockets[2] == 0 && !bVar1)) {
      Con_Printf("Warning! Couldn\'t allocate multicast IP port.\n");
    }
    if (NET_OpenIP::bFirst != false) {
      NET_OpenIP::bFirst = false;
      Con_Printf("NET Ports:  server %i, client %i\n",port_00,port);
      return;
    }
  }
  return;
}


// NET_QueuePacket  @ 000c5370
qboolean NET_QueuePacket(netsrc_t sock)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  netadrtype_t nVar6;
  uchar auVar7 [4];
  ushort uVar8;
  qboolean qVar9;
  sockaddr *psVar10;
  int *piVar11;
  char *pcVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  sockaddr *psVar18;
  undefined1 *puVar19;
  byte *pbVar20;
  char *pcVar21;
  byte *pbVar22;
  byte bVar23;
  sockaddr *psVar24;
  char *pcVar25;
  sockaddr *__addr;
  sockaddr *psVar26;
  undefined1 local_fe6 [4010];
  undefined1 local_3c [28];
  socklen_t local_20 [4];
  
                    /* Unresolved local var: int ret@[???]
                       Unresolved local var: sockaddr from@[???]
                       Unresolved local var: int fromlen@[???]
                       Unresolved local var: int net_socket@[???]
                       Unresolved local var: int protocol@[???]
                       Unresolved local var: int err@[???]
                       Unresolved local var: uchar[4010] buf@[???] */
  bVar23 = 0;
  if (ip_sockets[sock] != 0) {
    __addr = (sockaddr *)local_3c;
    pcVar25 = (char *)0x0;
    local_20[0] = 0x10;
    psVar10 = (sockaddr *)recvfrom(ip_sockets[sock],local_fe6,0xfaa,0,__addr,local_20);
    if (psVar10 == (sockaddr *)0xffffffff) {
      piVar11 = __errno_location();
      iVar16 = *piVar11;
      if (((iVar16 != 0xb) && (iVar16 != 0x68)) && (iVar16 != 0x6f)) {
        if (iVar16 == 0x5a) {
          Con_DPrintf("NET_QueuePacket:  Ignoring oversized network message\n");
        }
        else if (cls.state == ca_dedicated) {
          pcVar25 = strerror(iVar16);
          Con_Printf("NET_QueuePacket: %s\n",pcVar25);
        }
        else {
          pcVar25 = strerror(iVar16);
          Sys_Error("NET_QueuePacket: %s",pcVar25);
        }
      }
    }
    else {
      if (local_3c._0_2_ == 2) {
        in_from.type = NA_IP;
        in_from.ip[0] = local_3c[4];
        in_from.ip[1] = local_3c[5];
        in_from.ip[2] = local_3c[6];
        in_from.ip[3] = local_3c[7];
        in_from.port = local_3c._2_2_;
      }
      uVar8 = in_from.port;
      auVar7 = in_from.ip;
      nVar6 = in_from.type;
      if (psVar10 != (sockaddr *)0xfaa) {
        psVar24 = psVar10;
        Q_memcpy(in_message.data,local_fe6,(int)psVar10);
        pbVar20 = in_message.data;
        in_message.cursize = (int)psVar10;
        if (*(int *)in_message.data != -2) {
          qVar9 = NET_LagPacket(true,sock,&in_from,&in_message);
          return qVar9;
        }
        if (psVar10 < (sockaddr *)0x9) {
          Con_Printf("Invalid split packet length %i\n",psVar10);
          return false;
        }
                    /* Unresolved local var: int packetNumber@[???]
                       Unresolved local var: int packetCount@[???]
                       Unresolved local var: int sequenceNumber@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: uchar packetID@[???]
                       Unresolved local var: SPLITPACKET * pHeader@[???] */
        bVar1 = in_message.data[8];
        psVar26 = *(sockaddr **)(in_message.data + 4);
        psVar18 = (sockaddr *)(bVar1 & 0xf);
        puVar19 = (undefined1 *)(uint)(bVar1 >> 4);
        if (((sockaddr *)0x5 < psVar18) || ((undefined1 *)0x4 < puVar19)) {
          Con_Printf("Malformed packet number (%i)\n",puVar19);
          return false;
        }
        if (((gNetSplit.currentSequence == -1) || (psVar26 != (sockaddr *)gNetSplit.currentSequence)
            ) && (gNetSplit.currentSequence = (int)psVar26, gNetSplit.splitCount = (int)psVar18,
                 net_showpackets.value == 4.0)) {
          psVar24 = psVar26;
          Con_Printf("<-- Split packet restart %i count %i seq\n",psVar18,psVar26);
        }
        pcVar12 = psVar10[-1].sa_data + 5;
        if (psVar26 == (sockaddr *)NET_GetLong::gNetSplitFlags[(int)puVar19]) {
          psVar24 = psVar18;
          Con_Printf("NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes )\n",
                     puVar19 + 1,psVar18,pcVar12);
        }
        else {
          if (puVar19 == psVar18[-1].sa_data + 0xd) {
            pcVar21 = pcVar12 + (int)puVar19 * 0x56f;
            gNetSplit.totalSize = (int)pcVar21;
          }
          else {
            pcVar21 = pcVar12 + (int)puVar19 * 0x56f;
          }
          iVar16 = (int)puVar19 * 0x56f;
          gNetSplit.splitCount = gNetSplit.splitCount + -1;
          bVar4 = net_showpackets.value == 4.0;
          NET_GetLong::gNetSplitFlags[(int)puVar19] = (int)psVar26;
          if (bVar4) {
            psVar24 = psVar18;
            pcVar25 = pcVar12;
            Con_Printf("<-- Split packet %i of %i, %i bytes %i seq\n",puVar19 + 1,psVar18,pcVar12,
                       psVar26);
            __addr = psVar26;
          }
          if ((char *)0xfaa < pcVar21) {
            Con_Printf("Malformed packet size (%i, %i)\n",iVar16,pcVar12,pcVar25,__addr);
            return false;
          }
          pcVar21 = gNetSplit.buffer + iVar16;
          pbVar22 = pbVar20 + 9;
          if ((char *)0x7 < pcVar12) {
            pcVar14 = pcVar12;
            if (((uint)pcVar21 & 1) != 0) {
              pbVar22 = pbVar20 + 10;
              pcVar14 = psVar10[-1].sa_data + 4;
              *pcVar21 = pbVar20[9];
              pcVar21 = gNetSplit.buffer + iVar16 + 1;
            }
            if (((uint)pcVar21 & 2) != 0) {
              uVar2 = *(undefined2 *)pbVar22;
              pcVar14 = pcVar14 + -2;
              pbVar22 = pbVar22 + 2;
              *(undefined2 *)pcVar21 = uVar2;
              pcVar21 = pcVar21 + 2;
            }
            if (((uint)pcVar21 & 4) != 0) {
              uVar3 = *(undefined4 *)pbVar22;
              pcVar14 = pcVar14 + -4;
              pbVar22 = pbVar22 + 4;
              *(undefined4 *)pcVar21 = uVar3;
              pcVar21 = pcVar21 + 4;
            }
            pcVar12 = (char *)((uint)pcVar14 & 3);
            for (uVar13 = (uint)pcVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined4 *)pcVar21 = *(undefined4 *)pbVar22;
              pbVar22 = pbVar22 + (uint)bVar23 * -8 + 4;
              pcVar21 = pcVar21 + (uint)bVar23 * -8 + 4;
            }
          }
          iVar16 = 0;
          if (((uint)pcVar12 & 4) != 0) {
            *(undefined4 *)pcVar21 = *(undefined4 *)pbVar22;
            iVar16 = 4;
          }
          if (((uint)pcVar12 & 2) != 0) {
            *(undefined2 *)(pcVar21 + iVar16) = *(undefined2 *)(pbVar22 + iVar16);
            iVar16 = iVar16 + 2;
          }
          uVar13 = (uint)pcVar12 & 1;
          pcVar12 = pcVar25;
          if (uVar13 != 0) {
            pcVar21[iVar16] = pbVar22[iVar16];
          }
        }
        if (0 < gNetSplit.splitCount) {
          return false;
        }
                    /* Unresolved local var: int i@[???] */
        if ((bVar1 & 0xf) != 0) {
          if (NET_GetLong::gNetSplitFlags[0] == gNetSplit.currentSequence) {
            psVar10 = (sockaddr *)0x0;
            do {
              psVar10 = (sockaddr *)((int)&psVar10->sa_family + 1);
              if (psVar10 == psVar18) goto LAB_000c55d4;
              iVar16 = NET_GetLong::gNetSplitFlags[0];
              iVar17 = NET_GetLong::gNetSplitFlags[(int)psVar10];
            } while (NET_GetLong::gNetSplitFlags[0] == NET_GetLong::gNetSplitFlags[(int)psVar10]);
          }
          else {
            psVar10 = (sockaddr *)0x0;
            iVar16 = gNetSplit.currentSequence;
            iVar17 = NET_GetLong::gNetSplitFlags[0];
          }
          Con_Printf("Split packet without all %i parts, part %i had wrong sequence %i/%i\n",psVar18
                     ,(undefined1 *)((int)&psVar10->sa_family + 1),iVar17,iVar16);
          return false;
        }
LAB_000c55d4:
        gNetSplit.currentSequence = -1;
        if ((uint)gNetSplit.totalSize < 0xfab) {
          pcVar25 = gNetSplit.buffer;
          uVar13 = gNetSplit.totalSize;
          if (7 < (uint)gNetSplit.totalSize) {
            uVar15 = gNetSplit.totalSize;
            pbVar22 = pbVar20;
            if (((uint)pbVar20 & 1) != 0) {
              pbVar22 = pbVar20 + 1;
              pcVar25 = gNetSplit.buffer + 1;
              uVar15 = gNetSplit.totalSize - 1;
              *pbVar20 = gNetSplit.buffer[0];
            }
            if (((uint)pbVar22 & 2) != 0) {
              uVar2 = *(undefined2 *)pcVar25;
              uVar15 = uVar15 - 2;
              pcVar25 = pcVar25 + 2;
              *(undefined2 *)pbVar22 = uVar2;
              pbVar22 = pbVar22 + 2;
            }
            if (((uint)pbVar22 & 4) != 0) {
              uVar3 = *(undefined4 *)pcVar25;
              uVar15 = uVar15 - 4;
              pcVar25 = pcVar25 + 4;
              *(undefined4 *)pbVar22 = uVar3;
              pbVar22 = pbVar22 + 4;
            }
            uVar13 = uVar15 & 3;
            pbVar20 = pbVar22;
            for (uVar15 = uVar15 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
              *(undefined4 *)pbVar20 = *(undefined4 *)pcVar25;
              pcVar25 = pcVar25 + ((uint)bVar23 * -2 + 1) * 4;
              pbVar20 = pbVar20 + (uint)bVar23 * -8 + 4;
            }
          }
          iVar16 = 0;
          if ((uVar13 & 4) != 0) {
            *(undefined4 *)pbVar20 = *(undefined4 *)pcVar25;
            iVar16 = 4;
          }
          if ((uVar13 & 2) != 0) {
            *(undefined2 *)(pbVar20 + iVar16) = *(undefined2 *)(pcVar25 + iVar16);
            iVar16 = iVar16 + 2;
          }
          if ((uVar13 & 1) != 0) {
            pbVar20[iVar16] = pcVar25[iVar16];
          }
          in_message.cursize = gNetSplit.totalSize;
          return true;
        }
        Con_Printf("Split packet too large! %d bytes\n",gNetSplit.totalSize,psVar24,pcVar12,__addr);
        return false;
      }
      uVar13 = (uint)in_from.ip >> 8;
      uVar5 = (uint)in_from.ip >> 0x10;
      uVar15 = (uint)in_from.ip >> 0x18;
      Q_memset(NET_AdrToString::s_1,0,0x40);
      if (nVar6 == NA_LOOPBACK) {
        snprintf(NET_AdrToString::s_1,0x40,"loopback");
      }
      else if (nVar6 == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
        snprintf(NET_AdrToString::s_1,0x40,"%i.%i.%i.%i:%i",(uint)auVar7 & 0xff,uVar13 & 0xff,
                 uVar5 & 0xff,uVar15,(uint)(ushort)(uVar8 >> 8 | uVar8 << 8));
      }
      Con_Printf("NET_QueuePacket:  Oversize packet from %s\n",NET_AdrToString::s_1);
    }
  }
  qVar9 = NET_LagPacket(false,sock,(netadr_t *)0x0,(sizebuf_t *)0x0);
  return qVar9;
}


// NET_RemoveFromPacketList  @ 000c4850
void NET_RemoveFromPacketList(packetlag_t *pPacket)

{
  pPacket->pPrev->pNext = pPacket->pNext;
  pPacket->pNext->pPrev = pPacket->pPrev;
  pPacket->pPrev = (packetlag_s *)0x0;
  pPacket->pNext = (packetlag_s *)0x0;
  return;
}


// NET_SendLong  @ 000c3e30
int __regparm3 NET_SendLong(netsrc_t sock,int s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  undefined2 uVar1;
  undefined4 uVar2;
  ssize_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  byte bVar11;
  int local_5e0;
  char *local_5dc;
  int local_5d8;
  uint local_5d4;
  ushort local_5b0;
  undefined4 local_5ac;
  int32 local_5a8;
  char local_5a4;
  char local_5a3;
  char acStack_5a2 [1398];
  uint local_2c;
  
  bVar11 = 0;
  if ((len < 0x579) || (sock != NS_SERVER)) {
                    /* Unresolved local var: int nSend@[???] */
    sVar3 = sendto(s,buf,len,0,(sockaddr *)flags,0x10);
    return sVar3;
  }
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
  local_5ac = 0xfffffffe;
  uVar6 = (len + 0x56eU) / 0x56f;
  local_5e0 = 0;
  local_5d8 = 0;
  local_5dc = buf;
  local_5a8 = NET_SendLong::gSequenceNumber;
  while( true ) {
    uVar8 = 0x56f;
    if ((uint)len < 0x570) {
      uVar8 = len;
    }
    pcVar10 = &local_5a3;
    local_5a4 = (char)local_5e0 * '\x10' + (char)uVar6;
    uVar4 = uVar8;
    pcVar9 = local_5dc;
    if (7 < uVar8) {
      uVar5 = uVar8;
      if (((uint)&local_5a3 & 1) != 0) {
        local_5a3 = *local_5dc;
        pcVar10 = acStack_5a2;
        pcVar9 = local_5dc + 1;
        uVar5 = uVar8 - 1;
      }
      if (((uint)pcVar10 & 2) != 0) {
        uVar1 = *(undefined2 *)pcVar9;
        uVar5 = uVar5 - 2;
        pcVar9 = pcVar9 + 2;
        *(undefined2 *)pcVar10 = uVar1;
        pcVar10 = pcVar10 + 2;
      }
      if (((uint)pcVar10 & 4) != 0) {
        uVar2 = *(undefined4 *)pcVar9;
        uVar5 = uVar5 - 4;
        pcVar9 = pcVar9 + 4;
        *(undefined4 *)pcVar10 = uVar2;
        pcVar10 = pcVar10 + 4;
      }
      uVar4 = uVar5 & 3;
      for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + (uint)bVar11 * -8 + 4;
        pcVar10 = pcVar10 + ((uint)bVar11 * -2 + 1) * 4;
      }
    }
    iVar7 = 0;
    if ((uVar4 & 4) != 0) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
      iVar7 = 4;
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)(pcVar10 + iVar7) = *(undefined2 *)(pcVar9 + iVar7);
      iVar7 = iVar7 + 2;
    }
    if ((uVar4 & 1) != 0) {
      pcVar10[iVar7] = pcVar9[iVar7];
    }
    if (net_showpackets.value == 4.0) {
                    /* Unresolved local var: netadr_t adr@[???] */
      if (*(short *)flags == 2) {
        local_5d4 = *(uint *)(flags + 4);
        local_5b0 = *(ushort *)(flags + 2);
      }
      local_2c = local_5d4;
      Q_memset(NET_AdrToString::s_1,0,0x40);
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      snprintf(NET_AdrToString::s_1,0x40,"%i.%i.%i.%i:%i",local_5d4 & 0xff,local_5d4 >> 8 & 0xff,
               local_5d4 >> 0x10 & 0xff,local_5d4 >> 0x18,
               (uint)(ushort)(local_5b0 >> 8 | local_5b0 << 8));
      Con_DPrintf("Sending split %i of %i with %i bytes and seq %i to %s\n",local_5e0 + 1,uVar6,
                  uVar8,NET_SendLong::gSequenceNumber,NET_AdrToString::s_1);
    }
    sVar3 = sendto(s,&local_5ac,uVar8 + 9,0,(sockaddr *)flags,0x10);
    if (sVar3 < 0) break;
    iVar7 = local_5d8 + uVar8;
    if (sVar3 < (int)uVar8) {
      iVar7 = local_5d8;
    }
    len = len - uVar8;
    local_5e0 = local_5e0 + 1;
    local_5dc = local_5dc + 0x56f;
    local_5d8 = iVar7;
    if (len < 1) {
      return iVar7;
    }
  }
  return sVar3;
}


// NET_SendLong  @ 000c6120
int NET_SendLong(netsrc_t sock,int s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  undefined2 uVar1;
  undefined4 uVar2;
  ssize_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  byte bVar11;
  int local_5dc;
  char *local_5d8;
  int local_5d4;
  uint local_5d0;
  ushort local_5b0;
  undefined4 local_5ac;
  int32 local_5a8;
  char local_5a4;
  char local_5a3;
  char acStack_5a2 [1398];
  uint local_2c;
  
  bVar11 = 0;
  if ((len < 0x579) || (sock != NS_SERVER)) {
                    /* Unresolved local var: int nSend@[???] */
    sVar3 = sendto(s,buf,len,flags,(sockaddr *)to,tolen);
    return sVar3;
  }
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
  local_5ac = 0xfffffffe;
  local_5d8 = buf;
  local_5dc = 0;
  local_5d4 = 0;
  uVar6 = (len + 0x56eU) / 0x56f;
  local_5a8 = NET_SendLong::gSequenceNumber;
  while( true ) {
    uVar8 = 0x56f;
    if ((uint)len < 0x570) {
      uVar8 = len;
    }
    pcVar10 = &local_5a3;
    local_5a4 = (char)local_5dc * '\x10' + (char)uVar6;
    uVar4 = uVar8;
    pcVar9 = local_5d8;
    if (7 < uVar8) {
      uVar5 = uVar8;
      if (((uint)&local_5a3 & 1) != 0) {
        local_5a3 = *local_5d8;
        pcVar10 = acStack_5a2;
        pcVar9 = local_5d8 + 1;
        uVar5 = uVar8 - 1;
      }
      if (((uint)pcVar10 & 2) != 0) {
        uVar1 = *(undefined2 *)pcVar9;
        uVar5 = uVar5 - 2;
        pcVar9 = pcVar9 + 2;
        *(undefined2 *)pcVar10 = uVar1;
        pcVar10 = pcVar10 + 2;
      }
      if (((uint)pcVar10 & 4) != 0) {
        uVar2 = *(undefined4 *)pcVar9;
        uVar5 = uVar5 - 4;
        pcVar9 = pcVar9 + 4;
        *(undefined4 *)pcVar10 = uVar2;
        pcVar10 = pcVar10 + 4;
      }
      uVar4 = uVar5 & 3;
      for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + (uint)bVar11 * -8 + 4;
        pcVar10 = pcVar10 + ((uint)bVar11 * -2 + 1) * 4;
      }
    }
    iVar7 = 0;
    if ((uVar4 & 4) != 0) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
      iVar7 = 4;
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)(pcVar10 + iVar7) = *(undefined2 *)(pcVar9 + iVar7);
      iVar7 = iVar7 + 2;
    }
    if ((uVar4 & 1) != 0) {
      pcVar10[iVar7] = pcVar9[iVar7];
    }
    if (net_showpackets.value == 4.0) {
                    /* Unresolved local var: netadr_t adr@[???] */
      if (to->sa_family == 2) {
        local_5d0 = *(uint *)(to->sa_data + 2);
        local_5b0 = *(ushort *)to->sa_data;
      }
      else {
      }
      local_2c = local_5d0;
      Q_memset(NET_AdrToString::s_1,0,0x40);
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      snprintf(NET_AdrToString::s_1,0x40,"%i.%i.%i.%i:%i",(uint)(byte)local_5d0,
               local_5d0 >> 8 & 0xff,local_5d0 >> 0x10 & 0xff,local_5d0 >> 0x18,
               (uint)(ushort)(local_5b0 >> 8 | local_5b0 << 8));
      Con_DPrintf("Sending split %i of %i with %i bytes and seq %i to %s\n",local_5dc + 1,uVar6,
                  uVar8,NET_SendLong::gSequenceNumber,NET_AdrToString::s_1);
    }
    sVar3 = sendto(s,&local_5ac,uVar8 + 9,flags,(sockaddr *)to,tolen);
    if (sVar3 < 0) break;
    iVar7 = local_5d4 + uVar8;
    if (sVar3 < (int)uVar8) {
      iVar7 = local_5d4;
    }
    len = len - uVar8;
    local_5dc = local_5dc + 1;
    local_5d8 = local_5d8 + 0x56f;
    local_5d4 = iVar7;
    if (len < 1) {
      return iVar7;
    }
  }
  return sVar3;
}


// NET_SendLoopPacket  @ 000c47e0
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


// NET_SendPacket  @ 000c64a0
void NET_SendPacket(netsrc_t sock,int length,void *data,netadr_t to)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int unaff_EBP;
  netsrc_t nVar5;
  sockaddr *to_00;
  int in_stack_ffffffb0;
  undefined2 local_2c;
  ushort local_2a;
  uchar local_28 [4];
  
                    /* Unresolved local var: int ret@[???]
                       Unresolved local var: sockaddr addr@[???]
                       Unresolved local var: int net_socket@[???] */
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
      unaff_EBP = ip_sockets[sock];
      if (unaff_EBP == 0) {
        return;
      }
      to_00 = (sockaddr *)0x10;
      Q_memset(&local_2c,0,0x10);
      local_28[0] = 0xff;
      local_28[1] = 0xff;
      local_28[2] = 0xff;
      local_28[3] = 0xff;
      local_2c = 2;
      local_2a = to.port;
    }
    else if (to.type == NA_IP) {
      unaff_EBP = ip_sockets[sock];
      if (unaff_EBP == 0) {
        return;
      }
      to_00 = (sockaddr *)0x10;
      Q_memset(&local_2c,0,0x10);
      local_28 = to.ip;
      local_2c = 2;
      local_2a = to.port;
    }
    else {
      Sys_Error("NET_SendPacket: bad address type");
      to_00 = (sockaddr *)0x10;
      Q_memset(&local_2c,0,0x10);
    }
    iVar2 = NET_SendLong(sock,unaff_EBP,data,length,(int)&local_2c,to_00,in_stack_ffffffb0);
    if (iVar2 == -1) {
                    /* Unresolved local var: int err@[???] */
      piVar3 = __errno_location();
      iVar2 = *piVar3;
      if ((((iVar2 != 0xb) && (iVar2 != 0x6f)) && (iVar2 != 0x68)) &&
         ((iVar2 != 99 || (to.type != NA_BROADCAST)))) {
        if (cls.state == ca_dedicated) {
          pcVar4 = strerror(iVar2);
          Con_Printf("NET_SendPacket ERROR: %s\n",pcVar4);
        }
        else if ((iVar2 == 0x69) || (iVar2 == 99)) {
          Q_memset(NET_AdrToString::s_1,0,0x40);
          if (to.type == NA_IP) {
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
            snprintf(NET_AdrToString::s_1,0x40,"%i.%i.%i.%i:%i",(uint)to.ip[0],(uint)to.ip[1],
                     (uint)to.ip[2],(uint)to.ip[3],(uint)(ushort)(to.port >> 8 | to.port << 8));
          }
          pcVar4 = strerror(iVar2);
          Con_DPrintf("NET_SendPacket Warning: %s : %s\n",pcVar4,NET_AdrToString::s_1);
        }
        else {
          pcVar4 = strerror(iVar2);
          Sys_Error("NET_SendPacket ERROR: %s\n",pcVar4);
        }
      }
    }
  }
  return;
}


// NET_Shutdown  @ 000c75b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_Shutdown(void)

{
  packetlag_t *ppVar1;
  packetlag_t *ppVar2;
  net_messages_s *pnVar3;
  net_messages_t *pnVar4;
  packetlag_s *p;
  int iVar5;
  
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
  ppVar2 = g_pLagData[0].pNext;
  if (g_pLagData[0].pNext != g_pLagData) {
    do {
      if (ppVar2 == (packetlag_t *)0x0) break;
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
    } while (ppVar1 != g_pLagData);
  }
                    /* Unresolved local var: packetlag_t * p@[???]
                       Unresolved local var: packetlag_t * n@[???] */
  g_pLagData[0].pPrev = g_pLagData;
  g_pLagData[0].pNext = g_pLagData;
  if ((g_pLagData[1].pNext != (packetlag_s *)0x0) &&
     (p = g_pLagData[1].pNext, g_pLagData[1].pNext != g_pLagData + 1)) {
    do {
      ppVar2 = p->pNext;
      p->pPrev->pNext = ppVar2;
      p->pNext->pPrev = p->pPrev;
      p->pPrev = (packetlag_s *)0x0;
      p->pNext = (packetlag_s *)0x0;
      if (p->pPacketData != (uchar *)0x0) {
        Mem_Free(p->pPacketData);
        p->pPacketData = (uchar *)0x0;
      }
      Mem_Free(p);
    } while ((ppVar2 != g_pLagData + 1) && (p = ppVar2, ppVar2 != (packetlag_t *)0x0));
  }
                    /* Unresolved local var: int i@[???] */
  g_pLagData[1].pPrev = g_pLagData + 1;
  g_pLagData[1].pNext = g_pLagData + 1;
  if (NET_Config::old_config != false) {
    NET_Config::old_config = false;
    if (ip_sockets[0] != 0) {
      close(ip_sockets[0]);
      ip_sockets[0] = 0;
    }
    if (ip_sockets[1] != 0) {
      close(ip_sockets[1]);
      ip_sockets[1] = 0;
    }
    if (ip_sockets[2] != 0) {
      close(ip_sockets[2]);
      ip_sockets[2] = 0;
    }
    net_configured = 0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: net_messages_t * p@[???]
                       Unresolved local var: net_messages_t * n@[???] */
  if ((use_thread != 0) && (net_thread_initialized != false)) {
    net_thread_initialized = false;
  }
  iVar5 = 0;
  do {
    pnVar4 = messages[iVar5];
    while (pnVar4 != (net_messages_t *)0x0) {
      pnVar3 = pnVar4->next;
      Mem_Free(pnVar4->buffer);
      Mem_Free(pnVar4);
      pnVar4 = pnVar3;
    }
    messages[iVar5] = (net_messages_t *)0x0;
    iVar5 = iVar5 + 1;
    pnVar4 = normalqueue;
  } while (iVar5 != 3);
  while (pnVar4 != (net_messages_t *)0x0) {
    pnVar3 = pnVar4->next;
    Mem_Free(pnVar4->buffer);
    Mem_Free(pnVar4);
    pnVar4 = pnVar3;
  }
  normalqueue = (net_messages_t *)0x0;
  return;
}


// NET_Sleep  @ 000c5ba0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int NET_Sleep(void)

{
  byte *pbVar1;
  timeval *__timeout;
  int iVar2;
  __fd_mask *p_Var3;
  int iVar4;
  fd_set local_9c;
  timeval local_1c [2];
  
                    /* Unresolved local var: fd_set fdset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int sock@[???]
                       Unresolved local var: timeval tv@[???]
                       Unresolved local var: int number@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: int __d0@[???]
                       Unresolved local var: int __d1@[???] */
  iVar2 = 0x20;
  p_Var3 = local_9c.fds_bits;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    *p_Var3 = 0;
    p_Var3 = p_Var3 + 1;
  }
  iVar2 = 0;
  if (ip_sockets[0] != 0) {
    iVar2 = ip_sockets[0] + 0x1f;
    if (-1 < ip_sockets[0]) {
      iVar2 = ip_sockets[0];
    }
    pbVar1 = (byte *)((int)local_9c.fds_bits + (ip_sockets[0] % 0x20 >> 3) + (iVar2 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (ip_sockets[0] % 0x20 & 7U);
    iVar2 = ip_sockets[0];
    if (ip_sockets[0] < 1) {
      iVar2 = 0;
    }
  }
  if (ip_sockets[1] != 0) {
    iVar4 = ip_sockets[1] + 0x1f;
    if (-1 < ip_sockets[1]) {
      iVar4 = ip_sockets[1];
    }
    pbVar1 = (byte *)((int)local_9c.fds_bits + (ip_sockets[1] % 0x20 >> 3) + (iVar4 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (ip_sockets[1] % 0x20 & 7U);
    if (iVar2 < ip_sockets[1]) {
      iVar2 = ip_sockets[1];
    }
  }
  if (ip_sockets[2] != 0) {
    iVar4 = ip_sockets[2] + 0x1f;
    if (-1 < ip_sockets[2]) {
      iVar4 = ip_sockets[2];
    }
    pbVar1 = (byte *)((int)local_9c.fds_bits + (ip_sockets[2] % 0x20 >> 3) + (iVar4 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (ip_sockets[2] % 0x20 & 7U);
    if (iVar2 < ip_sockets[2]) {
      iVar2 = ip_sockets[2];
    }
  }
  local_1c[0].tv_sec = 0;
  local_1c[0].tv_usec = 20000;
  __timeout = (timeval *)0x0;
  if (net_sleepforever == 0) {
    __timeout = local_1c;
  }
  iVar2 = select(iVar2 + 1,&local_9c,(fd_set *)0x0,(fd_set *)0x0,__timeout);
  return iVar2;
}


// NET_Sleep_Timeout  @ 000c59c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int NET_Sleep_Timeout(void)

{
  byte *pbVar1;
  int32 iVar2;
  int iVar3;
  int iVar4;
  __fd_mask *p_Var5;
  int iVar6;
  double dVar7;
  fd_set local_9c;
  timeval local_1c [2];
  
                    /* Unresolved local var: fd_set fdset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int sock@[???]
                       Unresolved local var: timeval tv@[???]
                       Unresolved local var: int number@[???]
                       Unresolved local var: int fps@[???]
                       Unresolved local var: int32 curtime@[???] */
  iVar4 = (int)sys_ticrate.value;
  dVar7 = Sys_FloatTime();
  iVar3 = (int)dVar7;
  iVar2 = iVar3;
  if ((NET_Sleep_Timeout::lasttime != 0) &&
     (iVar2 = NET_Sleep_Timeout::lasttime, 1 < iVar3 - NET_Sleep_Timeout::lasttime)) {
    NET_Sleep_Timeout::staggerFrames = iVar4 / 100 + 1;
    iVar2 = iVar3;
    NET_Sleep_Timeout::numFrames = iVar4;
  }
                    /* Unresolved local var: int __d0@[???]
                       Unresolved local var: int __d1@[???] */
  NET_Sleep_Timeout::lasttime = iVar2;
  iVar3 = 0x20;
  p_Var5 = local_9c.fds_bits;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    *p_Var5 = 0;
    p_Var5 = p_Var5 + 1;
  }
  iVar3 = 0;
  if (ip_sockets[0] != 0) {
    iVar3 = ip_sockets[0] + 0x1f;
    if (-1 < ip_sockets[0]) {
      iVar3 = ip_sockets[0];
    }
    pbVar1 = (byte *)((int)local_9c.fds_bits + (ip_sockets[0] % 0x20 >> 3) + (iVar3 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (ip_sockets[0] % 0x20 & 7U);
    iVar3 = ip_sockets[0];
    if (ip_sockets[0] < 1) {
      iVar3 = 0;
    }
  }
  if (ip_sockets[1] != 0) {
    iVar6 = ip_sockets[1] + 0x1f;
    if (-1 < ip_sockets[1]) {
      iVar6 = ip_sockets[1];
    }
    pbVar1 = (byte *)((int)local_9c.fds_bits + (ip_sockets[1] % 0x20 >> 3) + (iVar6 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (ip_sockets[1] % 0x20 & 7U);
    if (iVar3 < ip_sockets[1]) {
      iVar3 = ip_sockets[1];
    }
  }
  if (ip_sockets[2] != 0) {
    iVar6 = ip_sockets[2] + 0x1f;
    if (-1 < ip_sockets[2]) {
      iVar6 = ip_sockets[2];
    }
    pbVar1 = (byte *)((int)local_9c.fds_bits + (ip_sockets[2] % 0x20 >> 3) + (iVar6 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (ip_sockets[2] % 0x20 & 7U);
    if (iVar3 < ip_sockets[2]) {
      iVar3 = ip_sockets[2];
    }
  }
  local_1c[0].tv_sec = 0;
  iVar4 = (int)(1000 / (longlong)iVar4) * 1000;
  local_1c[0].tv_usec = 1;
  if (0 < iVar4) {
    local_1c[0].tv_usec = iVar4;
  }
  if ((0 < NET_Sleep_Timeout::numFrames) &&
     (NET_Sleep_Timeout::numFrames % NET_Sleep_Timeout::staggerFrames != 0)) {
    iVar3 = select(iVar3 + 1,&local_9c,(fd_set *)0x0,(fd_set *)0x0,local_1c);
    NET_Sleep_Timeout::numFrames = NET_Sleep_Timeout::numFrames + -1;
    return iVar3;
  }
  iVar3 = select(0,(fd_set *)0x0,(fd_set *)0x0,(fd_set *)0x0,local_1c);
  NET_Sleep_Timeout::numFrames = NET_Sleep_Timeout::numFrames + -1;
  return iVar3;
}


// NET_StartThread  @ 000c5cb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_StartThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized == false)) {
    net_thread_initialized = true;
  }
  return;
}


// NET_StopThread  @ 000c5cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_StopThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized != false)) {
    net_thread_initialized = false;
  }
  return;
}


// NET_StringToAdr  @ 000c4610
qboolean NET_StringToAdr(char *s,netadr_t *a)

{
  int iVar1;
  qboolean qVar2;
  sockaddr local_1c;
  
                    /* Unresolved local var: sockaddr sadr@[???] */
  iVar1 = Q_strcmp(s,"localhost");
  if ((iVar1 == 0) || (iVar1 = Q_strcmp(s,"127.0.0.1"), iVar1 == 0)) {
    Q_memset(a,0,0x14);
    a->type = NA_LOOPBACK;
    return true;
  }
  qVar2 = NET_StringToSockaddr(s,&local_1c);
  if (qVar2 == false) {
    return false;
  }
  if (local_1c.sa_family != 2) {
    return true;
  }
  a->type = NA_IP;
  *(undefined4 *)a->ip = local_1c.sa_data._2_4_;
  a->port = local_1c.sa_data._0_2_;
  return true;
}


// NET_StringToSockaddr  @ 000c4510
qboolean NET_StringToSockaddr(char *s,sockaddr *sadr)

{
  long lVar1;
  in_addr_t iVar2;
  qboolean qVar3;
  hostent *phVar4;
  char *pcVar5;
  char local_9c [127];
  undefined1 local_1d;
  
                    /* Unresolved local var: hostent * h@[???]
                       Unresolved local var: char * colon@[???]
                       Unresolved local var: int val@[???]
                       Unresolved local var: char[128] copy@[???] */
  Q_memset(sadr,0,0x10);
  sadr->sa_family = 2;
  sadr->sa_data[0] = '\0';
  sadr->sa_data[1] = '\0';
  Q_strncpy(local_9c,s,0x7f);
  local_1d = 0;
  pcVar5 = local_9c;
  if (local_9c[0] != '\0') {
    while( true ) {
      if (local_9c[0] == ':') {
        *pcVar5 = '\0';
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
        lVar1 = strtol(pcVar5 + 1,(char **)0x0,10);
        *(ushort *)sadr->sa_data = (ushort)lVar1 >> 8 | (ushort)lVar1 << 8;
        local_9c[0] = pcVar5[1];
      }
      else {
        local_9c[0] = pcVar5[1];
      }
      if (local_9c[0] == '\0') break;
      pcVar5 = pcVar5 + 1;
    }
  }
  iVar2 = inet_addr(local_9c);
  *(in_addr_t *)(sadr->sa_data + 2) = iVar2;
  qVar3 = true;
  if (iVar2 == 0xffffffff) {
    phVar4 = gethostbyname(local_9c);
    qVar3 = false;
    if (phVar4 != (hostent *)0x0) {
      *(undefined4 *)(sadr->sa_data + 2) = *(undefined4 *)*phVar4->h_addr_list;
      return true;
    }
  }
  return qVar3;
}


// NET_ThreadLock  @ 000c4180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_ThreadLock(void)

{
  return;
}


// NET_ThreadUnlock  @ 000c4190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NET_ThreadUnlock(void)

{
  return;
}


// NET_TransferRawData  @ 000c46f0
void NET_TransferRawData(sizebuf_t *msg,uchar *pStart,int nSize)

{
  Q_memcpy(msg->data,pStart,nSize);
  msg->cursize = nSize;
  return;
}


