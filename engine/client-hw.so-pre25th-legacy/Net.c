// Net_APICheckTimeouts  @ 002073f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_APICheckTimeouts(void)

{
  net_api_query_s *pnVar1;
  net_api_query_s *pnVar2;
  net_api_query_t *p;
  net_response_s local_48;
  
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
                    /* Unresolved local var: net_response_t r@[???] */
  pnVar2 = (net_api_query_s *)0x0;
  p = g_queries;
  while (p != (net_api_query_t *)0x0) {
    pnVar1 = p->next;
    if (realtime <= p->requesttime + p->timeout) {
      p->next = pnVar2;
      pnVar2 = p;
      p = pnVar1;
    }
    else {
      if (p->callback != (net_api_response_func_t)0x0) {
        local_48.context = p->context;
        local_48.type = p->type;
        local_48.error = 1;
        local_48.remote_address.type = (p->request).type;
        local_48.remote_address.ip = *&(p->request).ip;
        local_48.remote_address.ipx._0_4_ = *(undefined4 *)(p->request).ipx;
        local_48.response = (void *)0x0;
        local_48.remote_address.ipx._4_4_ = *(undefined4 *)((p->request).ipx + 4);
        local_48.remote_address._16_4_ = *(undefined4 *)((p->request).ipx + 8);
        local_48.ping = realtime - p->requesttime;
        (*p->callback)(&local_48);
      }
      Mem_Free(p);
      p = pnVar1;
    }
  }
  g_queries = pnVar2;
  return;
}


// Net_APIClearQueries  @ 00207180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_APIClearQueries(void)

{
  net_api_query_s *pnVar1;
  net_api_query_t *p;
  
  p = g_queries;
  while (p != (net_api_query_t *)0x0) {
    pnVar1 = p->next;
    Mem_Free(p);
    p = pnVar1;
  }
  g_queries = (net_api_query_t *)0x0;
  return;
}


// Net_APIFailed  @ 00207330
void Net_APIFailed(net_api_query_t *p)

{
  net_response_s local_38;
  
                    /* Unresolved local var: net_response_t r@[???] */
  if (p->callback != (net_api_response_func_t)0x0) {
    local_38.context = p->context;
    local_38.ping = realtime - p->requesttime;
    local_38.type = p->type;
    local_38.error = 1;
    local_38.remote_address.type = (p->request).type;
    local_38.remote_address.ip = *&(p->request).ip;
    local_38.remote_address.ipx._0_4_ = *(undefined4 *)(p->request).ipx;
    local_38.remote_address.ipx._4_4_ = *(undefined4 *)((p->request).ipx + 4);
    local_38.remote_address._16_4_ = *(undefined4 *)((p->request).ipx + 8);
    local_38.response = (void *)0x0;
    (*p->callback)(&local_38);
  }
  return;
}


// Net_APIFind  @ 00207250
net_api_query_t * Net_APIFind(int type,netadr_t *remote)

{
  net_api_query_s *pnVar1;
  netadrtype_t nVar2;
  uint uVar3;
  qboolean qVar4;
  
  pnVar1 = g_queries;
  do {
    if (pnVar1 == (net_api_query_t *)0x0) {
      return (net_api_query_t *)0x0;
    }
    if (pnVar1->type == type) {
      nVar2 = (pnVar1->request).type;
      if (nVar2 == NA_BROADCAST) {
        uVar3 = remote->type - NA_BROADCAST;
joined_r0x002072f8:
        if (uVar3 < 2) {
          return pnVar1;
        }
      }
      else if (nVar2 == NA_BROADCAST_IPX) {
        uVar3 = remote->type - NA_IPX;
        goto joined_r0x002072f8;
      }
      qVar4 = NET_CompareAdr(*remote,pnVar1->request);
      if (qVar4 != false) {
        return pnVar1;
      }
    }
    pnVar1 = pnVar1->next;
  } while( true );
}


// Net_APIFindContext  @ 00207300
net_api_query_t * Net_APIFindContext(int context)

{
  net_api_query_s *pnVar1;
  
                    /* Unresolved local var: net_api_query_t * p@[???] */
  pnVar1 = (net_api_query_t *)0x0;
  if (g_queries != (net_api_query_t *)0x0) {
    pnVar1 = g_queries;
    if (g_queries->context == context) {
      return g_queries;
    }
    do {
      pnVar1 = pnVar1->next;
      if (pnVar1 == (net_api_query_s *)0x0) {
        return (net_api_query_t *)0x0;
      }
    } while (pnVar1->context != context);
  }
  return pnVar1;
}


// Net_APIInit  @ 002071e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_APIInit(void)

{
  g_queries = (net_api_query_t *)0x0;
  g_addresses = (net_adrlist_t *)0x0;
  return;
}


// Net_APIKill  @ 002073a0
void Net_APIKill(net_api_query_t *kill)

{
  net_api_query_s *pnVar1;
  net_api_query_t *pnVar2;
  net_api_query_s *pnVar3;
  
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
  pnVar3 = g_queries;
  if (kill != (net_api_query_t *)0x0) {
    pnVar3 = (net_api_query_s *)0x0;
    pnVar2 = g_queries;
    while (pnVar2 != (net_api_query_t *)0x0) {
      pnVar1 = pnVar2->next;
      if (pnVar2 == kill) {
        Mem_Free(kill);
        pnVar2 = pnVar1;
      }
      else {
        pnVar2->next = pnVar3;
        pnVar3 = pnVar2;
        pnVar2 = pnVar1;
      }
    }
  }
  g_queries = pnVar3;
  return;
}


// Net_APIProcess  @ 00207da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Net_APIProcess(void)

{
  netadrtype_t nVar1;
  net_api_query_s *pnVar2;
  net_adrlist_s *pnVar3;
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t a_02;
  netadr_t a_03;
  net_api_query_t *pnVar4;
  net_api_query_s *pnVar5;
  net_api_query_t *pnVar6;
  net_api_query_t *pnVar7;
  net_adrlist_t *p;
  int iVar8;
  uint uVar9;
  qboolean qVar10;
  net_api_query_s *pnVar11;
  net_adrlist_t local_838 [85];
  net_response_s local_38;
  
                    /* Unresolved local var: int iret@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_response_t r@[???]
                       Unresolved local var: char[2048] returninfo@[???] */
  local_838[0].next._0_1_ = 0;
  MSG_BeginReading();
  MSG_ReadLong();
  iVar8 = MSG_ReadByte();
  switch((char)iVar8) {
  case 'D':
                    /* Unresolved local var: net_api_query_t * p@[???] */
    pnVar11 = g_queries;
    if (g_queries == (net_api_query_t *)0x0) {
      return 0;
    }
    do {
      if (pnVar11->type == 3) {
        nVar1 = (pnVar11->request).type;
        if (nVar1 == NA_BROADCAST) {
          uVar9 = net_from.type - NA_BROADCAST;
joined_r0x002085ab:
          if (uVar9 < 2) goto LAB_00208022;
        }
        else if (nVar1 == NA_BROADCAST_IPX) {
          uVar9 = net_from.type - NA_IPX;
          goto joined_r0x002085ab;
        }
        a_00.ip[0] = net_from.ip[0];
        a_00.ip[1] = net_from.ip[1];
        a_00.ip[2] = net_from.ip[2];
        a_00.ip[3] = net_from.ip[3];
        a_00.type = net_from.type;
        a_00.ipx[0] = net_from.ipx[0];
        a_00.ipx[1] = net_from.ipx[1];
        a_00.ipx[2] = net_from.ipx[2];
        a_00.ipx[3] = net_from.ipx[3];
        a_00.ipx[4] = net_from.ipx[4];
        a_00.ipx[5] = net_from.ipx[5];
        a_00.ipx[6] = net_from.ipx[6];
        a_00.ipx[7] = net_from.ipx[7];
        a_00.ipx[8] = net_from.ipx[8];
        a_00.ipx[9] = net_from.ipx[9];
        a_00.port = net_from.port;
        qVar10 = NET_CompareAdr(a_00,pnVar11->request);
        if (qVar10 != false) {
LAB_00208022:
          if (pnVar11->callback != (net_api_response_func_t)0x0) {
            NET_ParsePlayersResponse((char *)local_838);
            local_38.context = pnVar11->context;
            local_38.type = pnVar11->type;
            local_38.error = 0;
            local_38.remote_address.type = net_from.type;
            local_38.remote_address.ip[0] = net_from.ip[0];
            local_38.remote_address.ip[1] = net_from.ip[1];
            local_38.remote_address.ip[2] = net_from.ip[2];
            local_38.remote_address.ip[3] = net_from.ip[3];
            local_38.remote_address.ipx[0] = net_from.ipx[0];
            local_38.remote_address.ipx[1] = net_from.ipx[1];
            local_38.remote_address.ipx[2] = net_from.ipx[2];
            local_38.remote_address.ipx[3] = net_from.ipx[3];
            local_38.remote_address.ipx[4] = net_from.ipx[4];
            local_38.remote_address.ipx[5] = net_from.ipx[5];
            local_38.remote_address.ipx[6] = net_from.ipx[6];
            local_38.remote_address.ipx[7] = net_from.ipx[7];
            local_38.remote_address.ipx[8] = net_from.ipx[8];
            local_38.remote_address.ipx[9] = net_from.ipx[9];
            local_38.remote_address.port = net_from.port;
            local_38.ping = realtime - pnVar11->requesttime;
            local_38.response = local_838;
            (*pnVar11->callback)(&local_38);
          }
          if ((pnVar11->flags & 1) != 0) {
            return 1;
          }
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
          pnVar5 = (net_api_query_s *)0x0;
          pnVar4 = g_queries;
          while (pnVar4 != (net_api_query_t *)0x0) {
            pnVar2 = pnVar4->next;
            if (pnVar4 == pnVar11) {
              Mem_Free(pnVar11);
              pnVar4 = pnVar2;
            }
            else {
              pnVar4->next = pnVar5;
              pnVar5 = pnVar4;
              pnVar4 = pnVar2;
            }
          }
          net_from.ipx[8] = net_from.ipx[8];
          net_from.ipx[9] = net_from.ipx[9];
          net_from.port = net_from.port;
          net_from.ipx[4] = net_from.ipx[4];
          net_from.ipx[5] = net_from.ipx[5];
          net_from.ipx[6] = net_from.ipx[6];
          net_from.ipx[7] = net_from.ipx[7];
          net_from.ipx[0] = net_from.ipx[0];
          net_from.ipx[1] = net_from.ipx[1];
          net_from.ipx[2] = net_from.ipx[2];
          net_from.ipx[3] = net_from.ipx[3];
          net_from.ip[0] = net_from.ip[0];
          net_from.ip[1] = net_from.ip[1];
          net_from.ip[2] = net_from.ip[2];
          net_from.ip[3] = net_from.ip[3];
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
          g_queries = pnVar5;
          return 1;
        }
      }
      pnVar11 = pnVar11->next;
    } while (pnVar11 != (net_api_query_s *)0x0);
    break;
  case 'E':
                    /* Unresolved local var: net_api_query_t * p@[???] */
    pnVar11 = g_queries;
    if (g_queries == (net_api_query_t *)0x0) {
      return 0;
    }
    do {
      if (pnVar11->type == 2) {
        nVar1 = (pnVar11->request).type;
        if (nVar1 == NA_BROADCAST) {
          uVar9 = net_from.type - NA_BROADCAST;
joined_r0x0020856b:
          if (uVar9 < 2) goto LAB_002082f2;
        }
        else if (nVar1 == NA_BROADCAST_IPX) {
          uVar9 = net_from.type - NA_IPX;
          goto joined_r0x0020856b;
        }
        a_02.ip[0] = net_from.ip[0];
        a_02.ip[1] = net_from.ip[1];
        a_02.ip[2] = net_from.ip[2];
        a_02.ip[3] = net_from.ip[3];
        a_02.type = net_from.type;
        a_02.ipx[0] = net_from.ipx[0];
        a_02.ipx[1] = net_from.ipx[1];
        a_02.ipx[2] = net_from.ipx[2];
        a_02.ipx[3] = net_from.ipx[3];
        a_02.ipx[4] = net_from.ipx[4];
        a_02.ipx[5] = net_from.ipx[5];
        a_02.ipx[6] = net_from.ipx[6];
        a_02.ipx[7] = net_from.ipx[7];
        a_02.ipx[8] = net_from.ipx[8];
        a_02.ipx[9] = net_from.ipx[9];
        a_02.port = net_from.port;
        qVar10 = NET_CompareAdr(a_02,pnVar11->request);
        if (qVar10 != false) {
LAB_002082f2:
          if (pnVar11->callback != (net_api_response_func_t)0x0) {
            NET_ParseRulesResponse((char *)local_838);
            local_38.context = pnVar11->context;
            local_38.type = pnVar11->type;
            local_38.error = 0;
            local_38.remote_address.type = net_from.type;
            local_38.remote_address.ip[0] = net_from.ip[0];
            local_38.remote_address.ip[1] = net_from.ip[1];
            local_38.remote_address.ip[2] = net_from.ip[2];
            local_38.remote_address.ip[3] = net_from.ip[3];
            local_38.remote_address.ipx[0] = net_from.ipx[0];
            local_38.remote_address.ipx[1] = net_from.ipx[1];
            local_38.remote_address.ipx[2] = net_from.ipx[2];
            local_38.remote_address.ipx[3] = net_from.ipx[3];
            local_38.remote_address.ipx[4] = net_from.ipx[4];
            local_38.remote_address.ipx[5] = net_from.ipx[5];
            local_38.remote_address.ipx[6] = net_from.ipx[6];
            local_38.remote_address.ipx[7] = net_from.ipx[7];
            local_38.remote_address.ipx[8] = net_from.ipx[8];
            local_38.remote_address.ipx[9] = net_from.ipx[9];
            local_38.remote_address.port = net_from.port;
            local_38.ping = realtime - pnVar11->requesttime;
            local_38.response = local_838;
            (*pnVar11->callback)(&local_38);
          }
          if ((pnVar11->flags & 1) != 0) {
            return 1;
          }
          pnVar5 = (net_api_query_s *)0x0;
          pnVar4 = g_queries;
          while (pnVar4 != (net_api_query_t *)0x0) {
            pnVar2 = pnVar4->next;
            if (pnVar4 == pnVar11) {
              Mem_Free(pnVar11);
              pnVar4 = pnVar2;
            }
            else {
              pnVar4->next = pnVar5;
              pnVar5 = pnVar4;
              pnVar4 = pnVar2;
            }
          }
          g_queries = pnVar5;
          net_from.ip[0] = net_from.ip[0];
          net_from.ip[1] = net_from.ip[1];
          net_from.ip[2] = net_from.ip[2];
          net_from.ip[3] = net_from.ip[3];
          net_from.ipx[0] = net_from.ipx[0];
          net_from.ipx[1] = net_from.ipx[1];
          net_from.ipx[2] = net_from.ipx[2];
          net_from.ipx[3] = net_from.ipx[3];
          net_from.ipx[4] = net_from.ipx[4];
          net_from.ipx[5] = net_from.ipx[5];
          net_from.ipx[6] = net_from.ipx[6];
          net_from.ipx[7] = net_from.ipx[7];
          net_from.ipx[8] = net_from.ipx[8];
          net_from.ipx[9] = net_from.ipx[9];
          net_from.port = net_from.port;
          return 1;
        }
      }
      pnVar11 = pnVar11->next;
    } while (pnVar11 != (net_api_query_s *)0x0);
    break;
  default:
    Con_Printf("Net_APIProcess: Unknown message type %i\n",(int)(char)iVar8);
    break;
  case 'f':
    iVar8 = NET_ParseServerList();
    pnVar4 = g_queries;
    if (iVar8 == 0) {
      return 0;
    }
    do {
      if (pnVar4 == (net_api_query_t *)0x0) {
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
        iVar8 = 0;
        p = g_addresses;
joined_r0x00208226:
        while (p != (net_adrlist_t *)0x0) {
          pnVar3 = p->next;
          Mem_Free(p);
          p = pnVar3;
        }
        g_addresses = (net_adrlist_t *)0x0;
        net_from.ip[0] = net_from.ip[0];
        net_from.ip[1] = net_from.ip[1];
        net_from.ip[2] = net_from.ip[2];
        net_from.ip[3] = net_from.ip[3];
        net_from.ipx[0] = net_from.ipx[0];
        net_from.ipx[1] = net_from.ipx[1];
        net_from.ipx[2] = net_from.ipx[2];
        net_from.ipx[3] = net_from.ipx[3];
        net_from.ipx[4] = net_from.ipx[4];
        net_from.ipx[5] = net_from.ipx[5];
        net_from.ipx[6] = net_from.ipx[6];
        net_from.ipx[7] = net_from.ipx[7];
        net_from.ipx[8] = net_from.ipx[8];
        net_from.ipx[9] = net_from.ipx[9];
        net_from.port = net_from.port;
        return iVar8;
      }
      if (pnVar4->type == 0) {
        nVar1 = (pnVar4->request).type;
        if (nVar1 == NA_BROADCAST) {
          uVar9 = net_from.type - NA_BROADCAST;
joined_r0x002085cb:
          if (1 < uVar9) goto LAB_00208150;
        }
        else {
          if (nVar1 == NA_BROADCAST_IPX) {
            uVar9 = net_from.type - NA_IPX;
            goto joined_r0x002085cb;
          }
LAB_00208150:
          a_01.ip[0] = net_from.ip[0];
          a_01.ip[1] = net_from.ip[1];
          a_01.ip[2] = net_from.ip[2];
          a_01.ip[3] = net_from.ip[3];
          a_01.type = net_from.type;
          a_01.ipx[0] = net_from.ipx[0];
          a_01.ipx[1] = net_from.ipx[1];
          a_01.ipx[2] = net_from.ipx[2];
          a_01.ipx[3] = net_from.ipx[3];
          a_01.ipx[4] = net_from.ipx[4];
          a_01.ipx[5] = net_from.ipx[5];
          a_01.ipx[6] = net_from.ipx[6];
          a_01.ipx[7] = net_from.ipx[7];
          a_01.ipx[8] = net_from.ipx[8];
          a_01.ipx[9] = net_from.ipx[9];
          a_01.port = net_from.port;
          qVar10 = NET_CompareAdr(a_01,pnVar4->request);
          if (qVar10 == false) goto LAB_00208120;
        }
        if (pnVar4->callback != (net_api_response_func_t)0x0) {
          Q_memset(&local_38,0,0x2c);
          local_38.context = pnVar4->context;
          local_38.type = pnVar4->type;
          local_38.error = 0;
          local_38.response = g_addresses;
          local_38.ping = realtime - pnVar4->requesttime;
          (*pnVar4->callback)(&local_38);
        }
        iVar8 = 1;
        p = g_addresses;
        if ((pnVar4->flags & 1) == 0) {
          pnVar6 = (net_api_query_t *)0x0;
          pnVar7 = g_queries;
          while (pnVar7 != (net_api_query_t *)0x0) {
            pnVar11 = pnVar7->next;
            if (pnVar7 == pnVar4) {
              Mem_Free(pnVar4);
              pnVar7 = pnVar11;
            }
            else {
              pnVar7->next = pnVar6;
              pnVar6 = pnVar7;
              pnVar7 = pnVar11;
            }
          }
          iVar8 = 1;
          g_queries = pnVar6;
          p = g_addresses;
        }
        goto joined_r0x00208226;
      }
LAB_00208120:
      pnVar4 = pnVar4->next;
    } while( true );
  case 'j':
                    /* Unresolved local var: net_api_query_t * p@[???] */
    pnVar11 = g_queries;
    if (g_queries == (net_api_query_t *)0x0) {
      return 0;
    }
    do {
      if (pnVar11->type == 1) {
        nVar1 = (pnVar11->request).type;
        if (nVar1 == NA_BROADCAST) {
          uVar9 = net_from.type - NA_BROADCAST;
joined_r0x0020854b:
          if (uVar9 < 2) goto LAB_0020846c;
        }
        else if (nVar1 == NA_BROADCAST_IPX) {
          uVar9 = net_from.type - NA_IPX;
          goto joined_r0x0020854b;
        }
        a_03.ip[0] = net_from.ip[0];
        a_03.ip[1] = net_from.ip[1];
        a_03.ip[2] = net_from.ip[2];
        a_03.ip[3] = net_from.ip[3];
        a_03.type = net_from.type;
        a_03.ipx[0] = net_from.ipx[0];
        a_03.ipx[1] = net_from.ipx[1];
        a_03.ipx[2] = net_from.ipx[2];
        a_03.ipx[3] = net_from.ipx[3];
        a_03.ipx[4] = net_from.ipx[4];
        a_03.ipx[5] = net_from.ipx[5];
        a_03.ipx[6] = net_from.ipx[6];
        a_03.ipx[7] = net_from.ipx[7];
        a_03.ipx[8] = net_from.ipx[8];
        a_03.ipx[9] = net_from.ipx[9];
        a_03.port = net_from.port;
        qVar10 = NET_CompareAdr(a_03,pnVar11->request);
        if (qVar10 != false) {
LAB_0020846c:
          if (pnVar11->callback != (net_api_response_func_t)0x0) {
            local_38.context = pnVar11->context;
            local_38.type = pnVar11->type;
            local_38.error = 0;
            local_38.remote_address.type = net_from.type;
            local_38.remote_address.ip[0] = net_from.ip[0];
            local_38.remote_address.ip[1] = net_from.ip[1];
            local_38.remote_address.ip[2] = net_from.ip[2];
            local_38.remote_address.ip[3] = net_from.ip[3];
            local_38.remote_address.ipx[0] = net_from.ipx[0];
            local_38.remote_address.ipx[1] = net_from.ipx[1];
            local_38.remote_address.ipx[2] = net_from.ipx[2];
            local_38.remote_address.ipx[3] = net_from.ipx[3];
            local_38.remote_address.ipx[4] = net_from.ipx[4];
            local_38.remote_address.ipx[5] = net_from.ipx[5];
            local_38.remote_address.ipx[6] = net_from.ipx[6];
            local_38.remote_address.ipx[7] = net_from.ipx[7];
            local_38.remote_address.ipx[8] = net_from.ipx[8];
            local_38.remote_address.ipx[9] = net_from.ipx[9];
            local_38.remote_address.port = net_from.port;
            local_38.response = local_838;
            local_38.ping = realtime - pnVar11->requesttime;
            (*pnVar11->callback)(&local_38);
          }
          if ((pnVar11->flags & 1) != 0) {
            return 1;
          }
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
          pnVar5 = (net_api_query_s *)0x0;
          pnVar4 = g_queries;
          while (pnVar4 != (net_api_query_t *)0x0) {
            pnVar2 = pnVar4->next;
            if (pnVar4 == pnVar11) {
              Mem_Free(pnVar11);
              pnVar4 = pnVar2;
            }
            else {
              pnVar4->next = pnVar5;
              pnVar5 = pnVar4;
              pnVar4 = pnVar2;
            }
          }
          g_queries = pnVar5;
          net_from.ip[0] = net_from.ip[0];
          net_from.ip[1] = net_from.ip[1];
          net_from.ip[2] = net_from.ip[2];
          net_from.ip[3] = net_from.ip[3];
          net_from.ipx[0] = net_from.ipx[0];
          net_from.ipx[1] = net_from.ipx[1];
          net_from.ipx[2] = net_from.ipx[2];
          net_from.ipx[3] = net_from.ipx[3];
          net_from.ipx[4] = net_from.ipx[4];
          net_from.ipx[5] = net_from.ipx[5];
          net_from.ipx[6] = net_from.ipx[6];
          net_from.ipx[7] = net_from.ipx[7];
          net_from.ipx[8] = net_from.ipx[8];
          net_from.ipx[9] = net_from.ipx[9];
          net_from.port = net_from.port;
          return 1;
        }
      }
      pnVar11 = pnVar11->next;
    } while (pnVar11 != (net_api_query_s *)0x0);
    break;
  case 'm':
                    /* Unresolved local var: net_api_query_t * p@[???] */
    pnVar11 = g_queries;
    if (g_queries == (net_api_query_t *)0x0) {
      return 0;
    }
    do {
      if (pnVar11->type == 4) {
        nVar1 = (pnVar11->request).type;
        if (nVar1 == NA_BROADCAST) {
          uVar9 = net_from.type - NA_BROADCAST;
joined_r0x0020858b:
          if (uVar9 < 2) goto LAB_00207e96;
        }
        else if (nVar1 == NA_BROADCAST_IPX) {
          uVar9 = net_from.type - NA_IPX;
          goto joined_r0x0020858b;
        }
        a.ip[0] = net_from.ip[0];
        a.ip[1] = net_from.ip[1];
        a.ip[2] = net_from.ip[2];
        a.ip[3] = net_from.ip[3];
        a.type = net_from.type;
        a.ipx[0] = net_from.ipx[0];
        a.ipx[1] = net_from.ipx[1];
        a.ipx[2] = net_from.ipx[2];
        a.ipx[3] = net_from.ipx[3];
        a.ipx[4] = net_from.ipx[4];
        a.ipx[5] = net_from.ipx[5];
        a.ipx[6] = net_from.ipx[6];
        a.ipx[7] = net_from.ipx[7];
        a.ipx[8] = net_from.ipx[8];
        a.ipx[9] = net_from.ipx[9];
        a.port = net_from.port;
        qVar10 = NET_CompareAdr(a,pnVar11->request);
        if (qVar10 != false) {
LAB_00207e96:
          if (pnVar11->callback != (net_api_response_func_t)0x0) {
            NET_ParseServerInfoResponse((char *)local_838);
            local_38.context = pnVar11->context;
            local_38.error = 0;
            local_38.type = pnVar11->type;
            local_38.remote_address.type = net_from.type;
            local_38.remote_address.ip[0] = net_from.ip[0];
            local_38.remote_address.ip[1] = net_from.ip[1];
            local_38.remote_address.ip[2] = net_from.ip[2];
            local_38.remote_address.ip[3] = net_from.ip[3];
            local_38.remote_address.ipx[0] = net_from.ipx[0];
            local_38.remote_address.ipx[1] = net_from.ipx[1];
            local_38.remote_address.ipx[2] = net_from.ipx[2];
            local_38.remote_address.ipx[3] = net_from.ipx[3];
            local_38.remote_address.ipx[4] = net_from.ipx[4];
            local_38.remote_address.ipx[5] = net_from.ipx[5];
            local_38.remote_address.ipx[6] = net_from.ipx[6];
            local_38.remote_address.ipx[7] = net_from.ipx[7];
            local_38.remote_address.ipx[8] = net_from.ipx[8];
            local_38.remote_address.ipx[9] = net_from.ipx[9];
            local_38.remote_address.port = net_from.port;
            local_38.ping = realtime - pnVar11->requesttime;
            local_38.response = local_838;
            (*pnVar11->callback)(&local_38);
          }
          if ((pnVar11->flags & 1) != 0) {
            return 1;
          }
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
          pnVar5 = (net_api_query_s *)0x0;
          pnVar4 = g_queries;
          while (pnVar4 != (net_api_query_t *)0x0) {
            pnVar2 = pnVar4->next;
            if (pnVar4 == pnVar11) {
              Mem_Free(pnVar11);
              pnVar4 = pnVar2;
            }
            else {
              pnVar4->next = pnVar5;
              pnVar5 = pnVar4;
              pnVar4 = pnVar2;
            }
          }
          g_queries = pnVar5;
          net_from.ip[0] = net_from.ip[0];
          net_from.ip[1] = net_from.ip[1];
          net_from.ip[2] = net_from.ip[2];
          net_from.ip[3] = net_from.ip[3];
          net_from.ipx[0] = net_from.ipx[0];
          net_from.ipx[1] = net_from.ipx[1];
          net_from.ipx[2] = net_from.ipx[2];
          net_from.ipx[3] = net_from.ipx[3];
          net_from.ipx[4] = net_from.ipx[4];
          net_from.ipx[5] = net_from.ipx[5];
          net_from.ipx[6] = net_from.ipx[6];
          net_from.ipx[7] = net_from.ipx[7];
          net_from.ipx[8] = net_from.ipx[8];
          net_from.ipx[9] = net_from.ipx[9];
          net_from.port = net_from.port;
          return 1;
        }
      }
      pnVar11 = pnVar11->next;
    } while (pnVar11 != (net_api_query_s *)0x0);
  }
  return 0;
}


// Net_APIShutDown  @ 002071f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_APIShutDown(void)

{
  net_api_query_s *pnVar1;
  net_adrlist_s *pnVar2;
  net_api_query_t *p;
  net_adrlist_t *p_00;
  
  p = g_queries;
  while (p != (net_api_query_t *)0x0) {
    pnVar1 = p->next;
    Mem_Free(p);
    p = pnVar1;
  }
                    /* Unresolved local var: net_adrlist_t * p@[???]
                       Unresolved local var: net_adrlist_t * n@[???] */
  g_queries = (net_api_query_t *)0x0;
  p_00 = g_addresses;
  while (p_00 != (net_adrlist_t *)0x0) {
    pnVar2 = p_00->next;
    Mem_Free(p_00);
    p_00 = pnVar2;
  }
  g_addresses = (net_adrlist_t *)0x0;
  return;
}


// Net_AdrToString  @ 00206e40
char * Net_AdrToString(netadr_s *a)

{
  netadr_t a_00;
  char *pcVar1;
  
  a_00.type = a->type;
  a_00.ip[0] = a->ip[0];
  a_00.ip[1] = a->ip[1];
  a_00.ip[2] = a->ip[2];
  a_00.ip[3] = a->ip[3];
  a_00.ipx[0] = a->ipx[0];
  a_00.ipx[1] = a->ipx[1];
  a_00.ipx[2] = a->ipx[2];
  a_00.ipx[3] = a->ipx[3];
  a_00.ipx[4] = a->ipx[4];
  a_00.ipx[5] = a->ipx[5];
  a_00.ipx[6] = a->ipx[6];
  a_00.ipx[7] = a->ipx[7];
  a_00.ipx[8] = a->ipx[8];
  a_00.ipx[9] = a->ipx[9];
  a_00.port = a->port;
  pcVar1 = NET_AdrToString(a_00);
  return pcVar1;
}


// Net_CancelAllRequests  @ 00206e80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_CancelAllRequests(void)

{
  net_api_query_s *pnVar1;
  net_api_query_t *p;
  
  p = g_queries;
  while (p != (net_api_query_t *)0x0) {
    pnVar1 = p->next;
    Mem_Free(p);
    p = pnVar1;
  }
  g_queries = (net_api_query_t *)0x0;
  return;
}


// Net_CancelRequest  @ 00206eb0
void Net_CancelRequest(int context)

{
  int iVar1;
  net_api_query_s *p;
  net_api_query_s *pnVar2;
  net_api_query_t *pnVar3;
  net_api_query_t *pnVar4;
  
                    /* Unresolved local var: net_api_query_t * p@[???] */
                    /* Unresolved local var: net_api_query_t * p@[???] */
  if (g_queries != (net_api_query_t *)0x0) {
    iVar1 = g_queries->context;
    p = g_queries;
    while( true ) {
      if (context == iVar1) {
        pnVar4 = (net_api_query_t *)0x0;
        pnVar3 = g_queries;
        do {
          pnVar2 = pnVar3->next;
          if (p == pnVar3) {
            Mem_Free(p);
          }
          else {
            pnVar3->next = pnVar4;
            pnVar4 = pnVar3;
          }
          pnVar3 = pnVar2;
        } while (pnVar2 != (net_api_query_s *)0x0);
        g_queries = pnVar4;
        return;
      }
      p = p->next;
      if (p == (net_api_query_s *)0x0) break;
      iVar1 = p->context;
    }
  }
  return;
}


// Net_CompareAdr  @ 00206db0
int Net_CompareAdr(netadr_s *a,netadr_s *b)

{
  netadr_t a_00;
  netadr_t b_00;
  qboolean qVar1;
  
  b_00.type = b->type;
  b_00.ip[0] = b->ip[0];
  b_00.ip[1] = b->ip[1];
  b_00.ip[2] = b->ip[2];
  b_00.ip[3] = b->ip[3];
  b_00.ipx[0] = b->ipx[0];
  b_00.ipx[1] = b->ipx[1];
  b_00.ipx[2] = b->ipx[2];
  b_00.ipx[3] = b->ipx[3];
  b_00.ipx[4] = b->ipx[4];
  b_00.ipx[5] = b->ipx[5];
  b_00.ipx[6] = b->ipx[6];
  b_00.ipx[7] = b->ipx[7];
  b_00.ipx[8] = b->ipx[8];
  b_00.ipx[9] = b->ipx[9];
  b_00.port = b->port;
  a_00.type = a->type;
  a_00.ip[0] = a->ip[0];
  a_00.ip[1] = a->ip[1];
  a_00.ip[2] = a->ip[2];
  a_00.ip[3] = a->ip[3];
  a_00.ipx[0] = a->ipx[0];
  a_00.ipx[1] = a->ipx[1];
  a_00.ipx[2] = a->ipx[2];
  a_00.ipx[3] = a->ipx[3];
  a_00.ipx[4] = a->ipx[4];
  a_00.ipx[5] = a->ipx[5];
  a_00.ipx[6] = a->ipx[6];
  a_00.ipx[7] = a->ipx[7];
  a_00.ipx[8] = a->ipx[8];
  a_00.ipx[9] = a->ipx[9];
  a_00.port = a->port;
  qVar1 = NET_CompareAdr(a_00,b_00);
  return qVar1;
}


// Net_GetBatchServerList  @ 002074b0
void Net_GetBatchServerList(sizebuf_t *msg,int batch)

{
  MSG_WriteByte(msg,0x65);
  MSG_WriteLong(msg,batch);
  return;
}


// Net_GetPacketLoss  @ 00208670
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Net_GetPacketLoss(void)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int packet_loss@[???] */
  if (cls.state != ca_active) {
    return 0;
  }
  iVar2 = (int)cls.packet_loss;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  iVar1 = 100;
  if (iVar2 < 0x65) {
    iVar1 = iVar2;
  }
  return iVar1;
}


// Net_InitNetworking  @ 00206e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_InitNetworking(void)

{
  NET_Config(true);
  return;
}


// Net_KillServerList  @ 002071b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_KillServerList(void)

{
  net_adrlist_s *pnVar1;
  net_adrlist_t *p;
  
  p = g_addresses;
  while (p != (net_adrlist_t *)0x0) {
    pnVar1 = p->next;
    Mem_Free(p);
    p = pnVar1;
  }
  g_addresses = (net_adrlist_t *)0x0;
  return;
}


// Net_SendRequest  @ 00206f20
void Net_SendRequest(int context,int request,int flags,double timeout,netadr_s *remote_address,
                    net_api_response_func_t response)

{
  net_adrlist_s *pnVar1;
  net_adrlist_t *p;
  net_api_query_t *pnVar2;
  net_api_query_t *pnVar3;
  byte local_43c [1024];
  sizebuf_t local_3c [2];
  
                    /* Unresolved local var: uchar[1024] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: net_api_query_t * q@[???] */
  Q_memset(local_3c,0,0x14);
  local_3c[0].data = local_43c;
  local_3c[0].cursize = 0;
  local_3c[0].buffername = "Net_SendRequest";
  local_3c[0].maxsize = 0x400;
  pnVar3 = Mem_ZeroMalloc(0x38);
  pnVar3->type = request;
  pnVar3->context = context;
  pnVar3->requesttime = realtime;
  pnVar3->flags = flags;
  pnVar3->timeout = timeout;
  (pnVar3->request).type = remote_address->type;
  *(undefined4 *)(pnVar3->request).ip = *(undefined4 *)remote_address->ip;
  *(undefined4 *)(pnVar3->request).ipx = *(undefined4 *)remote_address->ipx;
  *(undefined4 *)((pnVar3->request).ipx + 4) = *(undefined4 *)(remote_address->ipx + 4);
  *(undefined4 *)((pnVar3->request).ipx + 8) = *(undefined4 *)(remote_address->ipx + 8);
  pnVar3->callback = response;
  pnVar2 = pnVar3;
  pnVar3->next = g_queries;
  g_queries = pnVar2;
  switch(request) {
  case 0:
    p = g_addresses;
    while (p != (net_adrlist_t *)0x0) {
      pnVar1 = p->next;
      Mem_Free(p);
      p = pnVar1;
    }
    g_addresses = (net_adrlist_t *)0x0;
    MSG_WriteByte(local_3c,0x65);
    MSG_WriteLong(local_3c,0);
    break;
  case 1:
    MSG_WriteLong(local_3c,-1);
    MSG_WriteString(local_3c,"ping\n");
    break;
  case 2:
    MSG_WriteLong(local_3c,-1);
    MSG_WriteString(local_3c,"rules\n");
    break;
  case 3:
    MSG_WriteLong(local_3c,-1);
    MSG_WriteString(local_3c,"players\n");
    break;
  case 4:
    MSG_WriteLong(local_3c,-1);
    MSG_WriteString(local_3c,"details\n");
    break;
  default:
    Con_Printf("Unknown request type:  %i\n",request);
  }
  if (0 < local_3c[0].cursize) {
    NET_SendPacket(NS_CLIENT,local_3c[0].cursize,local_3c[0].data,pnVar3->request);
  }
  return;
}


// Net_Status  @ 00206cb0
void Net_Status(net_status_s *status)

{
  double dVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
                    /* Unresolved local var: int connected@[???] */
  if (status == (net_status_s *)0x0) {
    return;
  }
  bVar6 = cls.state != ca_disconnected;
  status->connected = (uint)bVar6;
  (status->local_address).type = net_local_adr.type;
  *&(status->local_address).ip = net_local_adr.ip;
  *(undefined4 *)(status->local_address).ipx = net_local_adr.ipx._0_4_;
  *(undefined4 *)((status->local_address).ipx + 4) = net_local_adr.ipx._4_4_;
  *(undefined4 *)((status->local_address).ipx + 8) = net_local_adr._16_4_;
  (status->remote_address).type = cls.netchan.remote_address.type;
  *&(status->remote_address).ip = cls.netchan.remote_address.ip;
  *(undefined4 *)(status->remote_address).ipx = cls.netchan.remote_address.ipx._0_4_;
  *(undefined4 *)((status->remote_address).ipx + 4) = cls.netchan.remote_address.ipx._4_4_;
  *(undefined4 *)((status->remote_address).ipx + 8) = cls.netchan.remote_address._16_4_;
  dVar3 = realtime;
  if (bVar6 == 0) {
    status->packet_loss = 0;
    status->connection_time = 0.0;
    fVar2 = rate.value;
    *(undefined4 *)&status->latency = 0;
    *(undefined4 *)((int)&status->latency + 4) = 0;
    status->rate = (double)fVar2;
    return;
  }
                    /* Unresolved local var: int packet_loss@[???] */
  iVar4 = 0;
  if (cls.state == ca_active) {
    iVar5 = (int)cls.packet_loss;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    iVar4 = 100;
    if (iVar5 < 0x65) {
      iVar4 = iVar5;
    }
  }
  status->latency = g_flLatency;
  dVar1 = (double)cls.netchan.connect_time;
  status->packet_loss = iVar4;
  status->connection_time = dVar3 - dVar1;
  status->rate = (double)rate.value;
  return;
}


// Net_StringToAdr  @ 00206e30
int Net_StringToAdr(char *s,netadr_s *a)

{
  int iVar1;
  qboolean qVar2;
  sockaddr sStack_1c;
  
  iVar1 = Q_strcmp(s,"localhost");
  if ((iVar1 == 0) || (iVar1 = Q_strcmp(s,"127.0.0.1"), iVar1 == 0)) {
    Q_memset(a,0,0x14);
    a->type = NA_LOOPBACK;
    return 1;
  }
  qVar2 = NET_StringToSockaddr(s,&sStack_1c);
  if (qVar2 == false) {
    return 0;
  }
  if (sStack_1c.sa_family != 2) {
    return 1;
  }
  a->type = NA_IP;
  *(undefined4 *)a->ip = sStack_1c.sa_data._2_4_;
  a->port = sStack_1c.sa_data._0_2_;
  return 1;
}


