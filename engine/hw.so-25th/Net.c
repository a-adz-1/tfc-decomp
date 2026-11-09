// Net_APICheckTimeouts  @ 001b77a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_APICheckTimeouts(void)

{
  net_api_query_s *pnVar1;
  net_api_query_t *pnVar2;
  net_api_query_t *p;
  int in_GS_OFFSET;
  net_response_s local_4c;
  int local_20;
  
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  p = (net_api_query_t *)0x0;
  if (g_queries != (net_api_query_t *)0x0) {
                    /* Unresolved local var: net_response_t r@[???] */
    pnVar1 = g_queries;
    pnVar2 = (net_api_query_t *)0x0;
    do {
      while (p = pnVar1, pnVar1 = p->next, p->requesttime + p->timeout < realtime) {
        if (p->callback != (net_api_response_func_t)0x0) {
          local_4c.context = p->context;
          local_4c.type = p->type;
          local_4c.error = 1;
          local_4c.remote_address.type = (p->request).type;
          local_4c.remote_address.ip = *&(p->request).ip;
          local_4c.remote_address.ipx._0_4_ = *(undefined4 *)(p->request).ipx;
          local_4c.response = (void *)0x0;
          local_4c.remote_address.ipx._4_4_ = *(undefined4 *)((p->request).ipx + 4);
          local_4c.remote_address._16_4_ = *(undefined4 *)((p->request).ipx + 8);
          local_4c.ping = realtime - p->requesttime;
          (*p->callback)(&local_4c);
        }
        Mem_Free(p);
        p = pnVar2;
        if (pnVar1 == (net_api_query_s *)0x0) goto LAB_001b7864;
      }
      p->next = pnVar2;
      pnVar2 = p;
    } while (pnVar1 != (net_api_query_s *)0x0);
  }
LAB_001b7864:
  g_queries = p;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Net_APIClearQueries  @ 001b74e0
void Net_APIClearQueries(void)

{
  net_api_query_s *pnVar1;
  net_api_query_s *p;
  
  p = g_queries;
  if (g_queries == (net_api_query_t *)0x0) {
    g_queries = (net_api_query_t *)0x0;
    return;
  }
  do {
    pnVar1 = p->next;
    Mem_Free(p);
    p = pnVar1;
  } while (pnVar1 != (net_api_query_s *)0x0);
  g_queries = (net_api_query_t *)0x0;
  return;
}


// Net_APIFailed  @ 001b76c0
void Net_APIFailed(net_api_query_t *p)

{
  int in_GS_OFFSET;
  net_response_s local_3c;
  int local_10;
  
                    /* Unresolved local var: net_response_t r@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (p->callback != (net_api_response_func_t)0x0) {
    local_3c.context = p->context;
    local_3c.ping = realtime - p->requesttime;
    local_3c.type = p->type;
    local_3c.error = 1;
    local_3c.remote_address.type = (p->request).type;
    local_3c.remote_address.ip = *&(p->request).ip;
    local_3c.remote_address.ipx._0_4_ = *(undefined4 *)(p->request).ipx;
    local_3c.remote_address.ipx._4_4_ = *(undefined4 *)((p->request).ipx + 4);
    local_3c.remote_address._16_4_ = *(undefined4 *)((p->request).ipx + 8);
    local_3c.response = (void *)0x0;
    (*p->callback)(&local_3c);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Net_APIFind  @ 001b75d0
net_api_query_t * Net_APIFind(int type,netadr_t *remote)

{
  net_api_query_s *pnVar1;
  qboolean qVar2;
  
  pnVar1 = g_queries;
  while( true ) {
    if (pnVar1 == (net_api_query_t *)0x0) {
      return (net_api_query_t *)0x0;
    }
    if ((pnVar1->type == type) &&
       ((((pnVar1->request).type == NA_BROADCAST && (remote->type - NA_BROADCAST < 2)) ||
        (qVar2 = NET_CompareAdr(*remote,pnVar1->request), qVar2 != false)))) break;
    pnVar1 = pnVar1->next;
  }
  return pnVar1;
}


// Net_APIFindContext  @ 001b7680
net_api_query_t * Net_APIFindContext(int context)

{
  net_api_query_s *pnVar1;
  
                    /* Unresolved local var: net_api_query_t * p@[???] */
  if (g_queries == (net_api_query_t *)0x0) {
    pnVar1 = (net_api_query_t *)0x0;
  }
  else {
    pnVar1 = g_queries;
    if (context == g_queries->context) {
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


// Net_APIInit  @ 001b7560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_APIInit(void)

{
  g_queries = (net_api_query_t *)0x0;
  g_addresses = (net_adrlist_t *)0x0;
  return;
}


// Net_APIKill  @ 001b7750
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
      if (kill == pnVar2) {
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


// Net_APIProcess  @ 001b81c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Net_APIProcess(void)

{
  net_api_query_s *pnVar1;
  net_adrlist_s *pnVar2;
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t a_02;
  netadr_t a_03;
  net_adrlist_t *p;
  int iVar3;
  qboolean qVar4;
  net_api_query_t *pnVar5;
  net_api_query_s *pnVar6;
  net_api_query_s *pnVar7;
  net_api_query_t *pnVar8;
  int in_GS_OFFSET;
  net_response_s local_83c;
  net_adrlist_t local_810 [85];
  int local_10;
  
                    /* Unresolved local var: int iret@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_response_t r@[???]
                       Unresolved local var: char[2048] returninfo@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_810[0].next._0_1_ = 0;
  MSG_BeginReading();
  MSG_ReadLong();
  iVar3 = MSG_ReadByte();
  switch((char)iVar3) {
  case 'D':
    for (pnVar6 = g_queries; pnVar6 != (net_api_query_s *)0x0; pnVar6 = pnVar6->next) {
      if ((pnVar6->type == 3) &&
         ((((pnVar6->request).type == NA_BROADCAST && (net_from.type - NA_BROADCAST < 2)) ||
          (a_00.ip[0] = net_from.ip[0], a_00.ip[1] = net_from.ip[1], a_00.ip[2] = net_from.ip[2],
          a_00.ip[3] = net_from.ip[3], a_00.type = net_from.type, a_00.ipx[0] = net_from.ipx[0],
          a_00.ipx[1] = net_from.ipx[1], a_00.ipx[2] = net_from.ipx[2],
          a_00.ipx[3] = net_from.ipx[3], a_00.ipx[4] = net_from.ipx[4],
          a_00.ipx[5] = net_from.ipx[5], a_00.ipx[6] = net_from.ipx[6],
          a_00.ipx[7] = net_from.ipx[7], a_00.ipx[8] = net_from.ipx[8],
          a_00.ipx[9] = net_from.ipx[9], a_00.port = net_from.port,
          qVar4 = NET_CompareAdr(a_00,pnVar6->request), qVar4 != false)))) {
        if (pnVar6->callback != (net_api_response_func_t)0x0) {
          NET_ParsePlayersResponse((char *)local_810);
          local_83c.context = pnVar6->context;
          local_83c.type = pnVar6->type;
          local_83c.error = 0;
          local_83c.remote_address.type = net_from.type;
          local_83c.remote_address.ip[0] = net_from.ip[0];
          local_83c.remote_address.ip[1] = net_from.ip[1];
          local_83c.remote_address.ip[2] = net_from.ip[2];
          local_83c.remote_address.ip[3] = net_from.ip[3];
          local_83c.remote_address.ipx[0] = net_from.ipx[0];
          local_83c.remote_address.ipx[1] = net_from.ipx[1];
          local_83c.remote_address.ipx[2] = net_from.ipx[2];
          local_83c.remote_address.ipx[3] = net_from.ipx[3];
          local_83c.remote_address.ipx[4] = net_from.ipx[4];
          local_83c.remote_address.ipx[5] = net_from.ipx[5];
          local_83c.remote_address.ipx[6] = net_from.ipx[6];
          local_83c.remote_address.ipx[7] = net_from.ipx[7];
          local_83c.remote_address.ipx[8] = net_from.ipx[8];
          local_83c.remote_address.ipx[9] = net_from.ipx[9];
          local_83c.remote_address.port = net_from.port;
          local_83c.ping = realtime - pnVar6->requesttime;
          local_83c.response = local_810;
          (*pnVar6->callback)(&local_83c);
        }
        if ((pnVar6->flags & 1) == 0) {
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
          pnVar7 = (net_api_query_s *)0x0;
          if (g_queries != (net_api_query_t *)0x0) {
            pnVar7 = (net_api_query_s *)0x0;
            pnVar8 = g_queries;
            do {
              pnVar1 = pnVar8->next;
              if (pnVar8 == pnVar6) {
                Mem_Free(pnVar6);
              }
              else {
                pnVar8->next = pnVar7;
                pnVar7 = pnVar8;
              }
              pnVar8 = pnVar1;
            } while (pnVar1 != (net_api_query_s *)0x0);
          }
LAB_001b8344:
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
          iVar3 = 1;
          g_queries = pnVar7;
        }
        else {
LAB_001b85a6:
          iVar3 = 1;
        }
        goto LAB_001b85c2;
      }
    }
    break;
  case 'E':
    for (pnVar6 = g_queries; pnVar6 != (net_api_query_s *)0x0; pnVar6 = pnVar6->next) {
      if ((pnVar6->type == 2) &&
         ((((pnVar6->request).type == NA_BROADCAST && (net_from.type - NA_BROADCAST < 2)) ||
          (a_01.ip[0] = net_from.ip[0], a_01.ip[1] = net_from.ip[1], a_01.ip[2] = net_from.ip[2],
          a_01.ip[3] = net_from.ip[3], a_01.type = net_from.type, a_01.ipx[0] = net_from.ipx[0],
          a_01.ipx[1] = net_from.ipx[1], a_01.ipx[2] = net_from.ipx[2],
          a_01.ipx[3] = net_from.ipx[3], a_01.ipx[4] = net_from.ipx[4],
          a_01.ipx[5] = net_from.ipx[5], a_01.ipx[6] = net_from.ipx[6],
          a_01.ipx[7] = net_from.ipx[7], a_01.ipx[8] = net_from.ipx[8],
          a_01.ipx[9] = net_from.ipx[9], a_01.port = net_from.port,
          qVar4 = NET_CompareAdr(a_01,pnVar6->request), qVar4 != false)))) {
        if (pnVar6->callback != (net_api_response_func_t)0x0) {
          NET_ParseRulesResponse((char *)local_810);
          local_83c.context = pnVar6->context;
          local_83c.error = 0;
          local_83c.type = pnVar6->type;
          local_83c.remote_address.type = net_from.type;
          local_83c.remote_address.ip[0] = net_from.ip[0];
          local_83c.remote_address.ip[1] = net_from.ip[1];
          local_83c.remote_address.ip[2] = net_from.ip[2];
          local_83c.remote_address.ip[3] = net_from.ip[3];
          local_83c.remote_address.ipx[0] = net_from.ipx[0];
          local_83c.remote_address.ipx[1] = net_from.ipx[1];
          local_83c.remote_address.ipx[2] = net_from.ipx[2];
          local_83c.remote_address.ipx[3] = net_from.ipx[3];
          local_83c.remote_address.ipx[4] = net_from.ipx[4];
          local_83c.remote_address.ipx[5] = net_from.ipx[5];
          local_83c.remote_address.ipx[6] = net_from.ipx[6];
          local_83c.remote_address.ipx[7] = net_from.ipx[7];
          local_83c.remote_address.ipx[8] = net_from.ipx[8];
          local_83c.remote_address.ipx[9] = net_from.ipx[9];
          local_83c.remote_address.port = net_from.port;
          local_83c.ping = realtime - pnVar6->requesttime;
          local_83c.response = local_810;
          (*pnVar6->callback)(&local_83c);
        }
        if ((pnVar6->flags & 1) != 0) goto LAB_001b85a6;
        pnVar7 = (net_api_query_s *)0x0;
        if (g_queries != (net_api_query_t *)0x0) {
          pnVar7 = (net_api_query_s *)0x0;
          pnVar8 = g_queries;
          do {
            pnVar1 = pnVar8->next;
            if (pnVar8 == pnVar6) {
              Mem_Free(pnVar6);
            }
            else {
              pnVar8->next = pnVar7;
              pnVar7 = pnVar8;
            }
            pnVar8 = pnVar1;
          } while (pnVar1 != (net_api_query_s *)0x0);
        }
        goto LAB_001b8344;
      }
    }
    break;
  default:
    Con_Printf("Net_APIProcess: Unknown message type %i\n",(int)(char)iVar3);
    break;
  case 'f':
    iVar3 = NET_ParseServerList();
    if (iVar3 != 0) {
                    /* Unresolved local var: net_api_query_t * p@[???] */
      pnVar6 = g_queries;
      if (g_queries != (net_api_query_t *)0x0) {
LAB_001b875a:
        if ((pnVar6->type != 0) ||
           ((((pnVar6->request).type != NA_BROADCAST || (1 < net_from.type - NA_BROADCAST)) &&
            (a_03.ip[0] = net_from.ip[0], a_03.ip[1] = net_from.ip[1], a_03.ip[2] = net_from.ip[2],
            a_03.ip[3] = net_from.ip[3], a_03.type = net_from.type, a_03.ipx[0] = net_from.ipx[0],
            a_03.ipx[1] = net_from.ipx[1], a_03.ipx[2] = net_from.ipx[2],
            a_03.ipx[3] = net_from.ipx[3], a_03.ipx[4] = net_from.ipx[4],
            a_03.ipx[5] = net_from.ipx[5], a_03.ipx[6] = net_from.ipx[6],
            a_03.ipx[7] = net_from.ipx[7], a_03.ipx[8] = net_from.ipx[8],
            a_03.ipx[9] = net_from.ipx[9], a_03.port = net_from.port,
            qVar4 = NET_CompareAdr(a_03,pnVar6->request), qVar4 == false)))) goto LAB_001b8750;
        if (pnVar6->callback != (net_api_response_func_t)0x0) {
          Q_memset(&local_83c,0,0x2c);
          local_83c.context = pnVar6->context;
          local_83c.type = pnVar6->type;
          local_83c.error = 0;
          local_83c.response = g_addresses;
          local_83c.ping = realtime - pnVar6->requesttime;
          (*pnVar6->callback)(&local_83c);
        }
        pnVar8 = g_queries;
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
        if (((pnVar6->flags & 1) == 0) &&
           (pnVar8 = (net_api_query_t *)0x0, g_queries != (net_api_query_t *)0x0)) {
          pnVar8 = (net_api_query_t *)0x0;
          pnVar5 = g_queries;
          do {
            pnVar7 = pnVar5->next;
            if (pnVar5 == pnVar6) {
              Mem_Free(pnVar6);
            }
            else {
              pnVar5->next = pnVar8;
              pnVar8 = pnVar5;
            }
            pnVar5 = pnVar7;
          } while (pnVar7 != (net_api_query_s *)0x0);
        }
        g_queries = pnVar8;
        iVar3 = 1;
        p = g_addresses;
        goto joined_r0x001b8832;
      }
LAB_001b8890:
      iVar3 = 0;
      p = g_addresses;
joined_r0x001b8832:
      while (p != (net_adrlist_t *)0x0) {
        pnVar2 = p->next;
        Mem_Free(p);
        p = pnVar2;
      }
      g_addresses = (net_adrlist_t *)0x0;
      goto LAB_001b85c2;
    }
    break;
  case 'j':
    for (pnVar6 = g_queries; pnVar6 != (net_api_query_s *)0x0; pnVar6 = pnVar6->next) {
      if ((pnVar6->type == 1) &&
         ((((pnVar6->request).type == NA_BROADCAST && (net_from.type - NA_BROADCAST < 2)) ||
          (a_02.ip[0] = net_from.ip[0], a_02.ip[1] = net_from.ip[1], a_02.ip[2] = net_from.ip[2],
          a_02.ip[3] = net_from.ip[3], a_02.type = net_from.type, a_02.ipx[0] = net_from.ipx[0],
          a_02.ipx[1] = net_from.ipx[1], a_02.ipx[2] = net_from.ipx[2],
          a_02.ipx[3] = net_from.ipx[3], a_02.ipx[4] = net_from.ipx[4],
          a_02.ipx[5] = net_from.ipx[5], a_02.ipx[6] = net_from.ipx[6],
          a_02.ipx[7] = net_from.ipx[7], a_02.ipx[8] = net_from.ipx[8],
          a_02.ipx[9] = net_from.ipx[9], a_02.port = net_from.port,
          qVar4 = NET_CompareAdr(a_02,pnVar6->request), qVar4 != false)))) {
        if (pnVar6->callback != (net_api_response_func_t)0x0) {
          local_83c.context = pnVar6->context;
          local_83c.type = pnVar6->type;
          local_83c.error = 0;
          local_83c.remote_address.type = net_from.type;
          local_83c.remote_address.ip[0] = net_from.ip[0];
          local_83c.remote_address.ip[1] = net_from.ip[1];
          local_83c.remote_address.ip[2] = net_from.ip[2];
          local_83c.remote_address.ip[3] = net_from.ip[3];
          local_83c.remote_address.ipx[0] = net_from.ipx[0];
          local_83c.remote_address.ipx[1] = net_from.ipx[1];
          local_83c.remote_address.ipx[2] = net_from.ipx[2];
          local_83c.remote_address.ipx[3] = net_from.ipx[3];
          local_83c.remote_address.ipx[4] = net_from.ipx[4];
          local_83c.remote_address.ipx[5] = net_from.ipx[5];
          local_83c.remote_address.ipx[6] = net_from.ipx[6];
          local_83c.remote_address.ipx[7] = net_from.ipx[7];
          local_83c.remote_address.ipx[8] = net_from.ipx[8];
          local_83c.remote_address.ipx[9] = net_from.ipx[9];
          local_83c.remote_address.port = net_from.port;
          local_83c.response = local_810;
          local_83c.ping = realtime - pnVar6->requesttime;
          (*pnVar6->callback)(&local_83c);
        }
        if ((pnVar6->flags & 1) != 0) goto LAB_001b85a6;
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
        pnVar7 = (net_api_query_s *)0x0;
        if (g_queries != (net_api_query_t *)0x0) {
          pnVar7 = (net_api_query_s *)0x0;
          pnVar8 = g_queries;
          do {
            pnVar1 = pnVar8->next;
            if (pnVar8 == pnVar6) {
              Mem_Free(pnVar6);
            }
            else {
              pnVar8->next = pnVar7;
              pnVar7 = pnVar8;
            }
            pnVar8 = pnVar1;
          } while (pnVar1 != (net_api_query_s *)0x0);
        }
        goto LAB_001b8344;
      }
    }
    break;
  case 'm':
    pnVar6 = g_queries;
joined_r0x001b8210:
    if (pnVar6 != (net_api_query_t *)0x0) {
      if ((pnVar6->type != 4) ||
         ((((pnVar6->request).type != NA_BROADCAST || (1 < net_from.type - NA_BROADCAST)) &&
          (a.ip[0] = net_from.ip[0], a.ip[1] = net_from.ip[1], a.ip[2] = net_from.ip[2],
          a.ip[3] = net_from.ip[3], a.type = net_from.type, a.ipx[0] = net_from.ipx[0],
          a.ipx[1] = net_from.ipx[1], a.ipx[2] = net_from.ipx[2], a.ipx[3] = net_from.ipx[3],
          a.ipx[4] = net_from.ipx[4], a.ipx[5] = net_from.ipx[5], a.ipx[6] = net_from.ipx[6],
          a.ipx[7] = net_from.ipx[7], a.ipx[8] = net_from.ipx[8], a.ipx[9] = net_from.ipx[9],
          a.port = net_from.port, qVar4 = NET_CompareAdr(a,pnVar6->request), qVar4 == false))))
      goto LAB_001b8220;
      if (pnVar6->callback != (net_api_response_func_t)0x0) {
        NET_ParseServerInfoResponse((char *)local_810);
        local_83c.context = pnVar6->context;
        local_83c.error = 0;
        local_83c.type = pnVar6->type;
        local_83c.remote_address.type = net_from.type;
        local_83c.remote_address.ip[0] = net_from.ip[0];
        local_83c.remote_address.ip[1] = net_from.ip[1];
        local_83c.remote_address.ip[2] = net_from.ip[2];
        local_83c.remote_address.ip[3] = net_from.ip[3];
        local_83c.remote_address.ipx[0] = net_from.ipx[0];
        local_83c.remote_address.ipx[1] = net_from.ipx[1];
        local_83c.remote_address.ipx[2] = net_from.ipx[2];
        local_83c.remote_address.ipx[3] = net_from.ipx[3];
        local_83c.remote_address.ipx[4] = net_from.ipx[4];
        local_83c.remote_address.ipx[5] = net_from.ipx[5];
        local_83c.remote_address.ipx[6] = net_from.ipx[6];
        local_83c.remote_address.ipx[7] = net_from.ipx[7];
        local_83c.remote_address.ipx[8] = net_from.ipx[8];
        local_83c.remote_address.ipx[9] = net_from.ipx[9];
        local_83c.remote_address.port = net_from.port;
        local_83c.ping = realtime - pnVar6->requesttime;
        local_83c.response = local_810;
        (*pnVar6->callback)(&local_83c);
      }
      if ((pnVar6->flags & 1) == 0) {
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
        pnVar7 = (net_api_query_s *)0x0;
        pnVar8 = g_queries;
        while (pnVar8 != (net_api_query_t *)0x0) {
          pnVar1 = pnVar8->next;
          if (pnVar8 == pnVar6) {
            Mem_Free(pnVar6);
            pnVar8 = pnVar1;
          }
          else {
            pnVar8->next = pnVar7;
            pnVar7 = pnVar8;
            pnVar8 = pnVar1;
          }
        }
        goto LAB_001b8344;
      }
      goto LAB_001b85a6;
    }
    break;
  }
  iVar3 = 0;
LAB_001b85c2:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
LAB_001b8220:
  pnVar6 = pnVar6->next;
  goto joined_r0x001b8210;
LAB_001b8750:
  pnVar6 = pnVar6->next;
  if (pnVar6 == (net_api_query_s *)0x0) goto LAB_001b8890;
  goto LAB_001b875a;
}


// Net_APIShutDown  @ 001b7570
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


// Net_AdrToString  @ 001b7310
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


// Net_CancelAllRequests  @ 001b6fd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_CancelAllRequests(void)

{
  net_api_query_s *pnVar1;
  net_api_query_s *p;
  
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???] */
  p = g_queries;
  if (g_queries == (net_api_query_t *)0x0) {
    g_queries = (net_api_query_t *)0x0;
    return;
  }
  do {
    pnVar1 = p->next;
    Mem_Free(p);
    p = pnVar1;
  } while (pnVar1 != (net_api_query_s *)0x0);
  g_queries = (net_api_query_t *)0x0;
  return;
}


// Net_CancelRequest  @ 001b7470
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
                    /* Unresolved local var: net_api_query_t * p@[???]
                       Unresolved local var: net_api_query_t * n@[???]
                       Unresolved local var: net_api_query_t * newlist@[???] */
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


// Net_CheckOpenFakeUDPPorts  @ 0012d370
void Net_CheckOpenFakeUDPPorts(qboolean bClient)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
  if (bClient == 0) {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamGameServerNetworkingSockets_SteamAPI::
                               s_CallbackCounterAndContext_1);
    piVar1 = (int *)*piVar1;
                    /* Unresolved local var: bool bLanOnly@[???] */
    if ((piVar1 != (int *)0x0) && (sv_lan.value <= 0.0)) {
                    /* Unresolved local var: bool bLanOnly@[???] */
      iVar2 = PF_IsDedicatedServer();
      if ((iVar2 == 0) &&
         ((0.0 < sv_use_steam_networking.value &&
          (ip_fakeudpports[1] == (ISteamNetworkingFakeUDPPort *)0x0)))) {
        ip_fakeudpports[1] = (ISteamNetworkingFakeUDPPort *)(**(code **)(*piVar1 + 0xb8))(piVar1,0);
        if (ip_fakeudpports[1] == (ISteamNetworkingFakeUDPPort *)0x0) {
          Con_Printf("Failed to create fake UDP port, module %d fake port idx %d",1,0);
        }
      }
    }
  }
  else {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamNetworkingSockets_SteamAPI::s_CallbackCounterAndContext);
    piVar1 = (int *)*piVar1;
    if ((piVar1 != (int *)0x0) && (ip_fakeudpports[0] == (ISteamNetworkingFakeUDPPort *)0x0)) {
      ip_fakeudpports[0] =
           (ISteamNetworkingFakeUDPPort *)(**(code **)(*piVar1 + 0xb8))(piVar1,0xffffffff);
      if (ip_fakeudpports[0] == (ISteamNetworkingFakeUDPPort *)0x0) {
        Con_Printf("Failed to create fake UDP port, module %d fake port idx %d",0,0xffffffff);
      }
    }
  }
  return;
}


// Net_CloseFakeUDPPorts  @ 0012d470
void Net_CloseFakeUDPPorts(qboolean bClient)

{
  int *piVar1;
  
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
  if (bClient == 0) {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamGameServerNetworkingSockets_SteamAPI::
                               s_CallbackCounterAndContext_1);
    if (*piVar1 != 0) {
                    /* Unresolved local var: bool bLanOnly@[???] */
      if (sv_lan.value <= 0.0) {
                    /* Unresolved local var: bool bLanOnly@[???] */
        PF_IsDedicatedServer();
      }
      if (ip_fakeudpports[1] != (ISteamNetworkingFakeUDPPort *)0x0) {
        (*(code *)**(undefined4 **)ip_fakeudpports[1])(ip_fakeudpports[1]);
        ip_fakeudpports[1] = (ISteamNetworkingFakeUDPPort *)0x0;
        return;
      }
    }
  }
  else {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamNetworkingSockets_SteamAPI::s_CallbackCounterAndContext);
    if ((*piVar1 != 0) && (ip_fakeudpports[0] != (ISteamNetworkingFakeUDPPort *)0x0)) {
      (*(code *)**(undefined4 **)ip_fakeudpports[0])(ip_fakeudpports[0]);
      ip_fakeudpports[0] = (ISteamNetworkingFakeUDPPort *)0x0;
    }
  }
  return;
}


// Net_CompareAdr  @ 001b7010
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


// Net_GetBatchServerList  @ 001b7890
void Net_GetBatchServerList(sizebuf_t *msg,int batch)

{
  MSG_WriteByte(msg,0x65);
  MSG_WriteLong(msg,batch);
  return;
}


// Net_GetPacketLoss  @ 001b8910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Net_GetPacketLoss(void)

{
  int iVar1;
  
                    /* Unresolved local var: int packet_loss@[???] */
  if (cls.state != ca_active) {
    return 0;
  }
                    /* Unresolved local var: int packet_loss@[???] */
  iVar1 = 0;
  if (-1 < (int)cls.packet_loss) {
    iVar1 = (int)cls.packet_loss;
  }
  if (100 < iVar1) {
    iVar1 = 100;
  }
  return iVar1;
}


// Net_InitNetworking  @ 001b7350
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_InitNetworking(void)

{
  NET_Config(true);
  return;
}


// Net_KillServerList  @ 001b7520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_KillServerList(void)

{
  net_adrlist_s *pnVar1;
  net_adrlist_s *p;
  
                    /* Unresolved local var: net_adrlist_t * p@[???]
                       Unresolved local var: net_adrlist_t * n@[???] */
  p = g_addresses;
  if (g_addresses == (net_adrlist_t *)0x0) {
    g_addresses = (net_adrlist_t *)0x0;
    return;
  }
  do {
    pnVar1 = p->next;
    Mem_Free(p);
    p = pnVar1;
  } while (pnVar1 != (net_adrlist_s *)0x0);
  g_addresses = (net_adrlist_t *)0x0;
  return;
}


// Net_PollSteamFakeIPResult  @ 0012d500
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_PollSteamFakeIPResult(void)

{
  netadr_t a;
  netadr_t a_00;
  short sVar1;
  int *piVar2;
  int32 iVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  uint local_b0 [35];
  uint32 local_24;
  uint16 local_20;
  int local_10;
  
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                       Unresolved local var: SteamNetworkingFakeIPResult_t result@[???]
                       Unresolved local var: netadr_t.conflict adr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  piVar2 = (int *)SteamInternal_ContextInit
                            (SteamGameServerNetworkingSockets_SteamAPI::
                             s_CallbackCounterAndContext_1);
  piVar2 = (int *)*piVar2;
  if ((g_nFakeIP == 0) && (piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 0xac))(piVar2,0,local_b0);
    if ((local_b0[0] & 0xffffffdf) != 10) {
      if (local_b0[0] != 1) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("FakeIP allocation failed with error code %d",local_b0[0]);
      }
      g_nFakeIP = local_24;
      iVar3 = (*BigLong)(local_24);
      sVar1 = (*BigShort)(local_20);
      a.ip[0] = (char)iVar3;
      a.ip[1] = (char)((uint)iVar3 >> 8);
      a.ip[2] = (char)((uint)iVar3 >> 0x10);
      a.ip[3] = (char)((uint)iVar3 >> 0x18);
      a.type = 3;
      a.ipx._0_4_ = local_bc;
      a.ipx._4_4_ = local_b8;
      a.ipx[8] = (undefined1)local_b4;
      a.ipx[9] = local_b4._1_1_;
      a.port = sVar1;
      pcVar4 = NET_AdrToString(a);
      Con_Printf("FakeIP allocation succeeded: %s",pcVar4);
      a_00.ip[0] = (char)iVar3;
      a_00.ip[1] = (char)((uint)iVar3 >> 8);
      a_00.ip[2] = (char)((uint)iVar3 >> 0x10);
      a_00.ip[3] = (char)((uint)iVar3 >> 0x18);
      a_00.type = 3;
      a_00.ipx._0_4_ = local_bc;
      a_00.ipx._4_4_ = local_b8;
      a_00.ipx[8] = (undefined1)local_b4;
      a_00.ipx[9] = local_b4._1_1_;
      a_00.port = sVar1;
      pcVar4 = NET_AdrToString(a_00);
      Log_Printf("FakeIP allocation succeeded: %s",pcVar4);
                    /* Unresolved local var: int i@[???] */
      g_arFakePorts[0] = local_20;
      Con_Printf("\n");
      Log_Printf("\n");
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Net_SendRequest  @ 001b7070
void Net_SendRequest(int context,int request,int flags,double timeout,netadr_s *remote_address,
                    net_api_response_func_t response)

{
  undefined4 uVar1;
  net_adrlist_s *pnVar2;
  net_adrlist_t *p;
  net_api_query_t *pnVar3;
  net_api_query_t *pnVar4;
  int in_GS_OFFSET;
  sizebuf_t local_434;
  byte local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: uchar[1024] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: net_api_query_t * q@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&local_434,0,0x14);
  local_434.data = local_420;
  local_434.cursize = 0;
  local_434.buffername = "Net_SendRequest";
  local_434.maxsize = 0x400;
  pnVar4 = Mem_ZeroMalloc(0x38);
  pnVar4->type = request;
  pnVar4->timeout = timeout;
  pnVar4->context = context;
  pnVar4->requesttime = realtime;
  pnVar4->flags = flags;
  (pnVar4->request).type = remote_address->type;
  *(undefined4 *)(pnVar4->request).ip = *(undefined4 *)remote_address->ip;
  *(undefined4 *)(pnVar4->request).ipx = *(undefined4 *)remote_address->ipx;
  *(undefined4 *)((pnVar4->request).ipx + 4) = *(undefined4 *)(remote_address->ipx + 4);
  uVar1 = *(undefined4 *)(remote_address->ipx + 8);
  pnVar4->callback = response;
  *(undefined4 *)((pnVar4->request).ipx + 8) = uVar1;
  pnVar3 = pnVar4;
  pnVar4->next = g_queries;
  g_queries = pnVar3;
  switch(request) {
  case 0:
    p = g_addresses;
    while (p != (net_adrlist_t *)0x0) {
      pnVar2 = p->next;
      Mem_Free(p);
      p = pnVar2;
    }
    g_addresses = (net_adrlist_t *)0x0;
    MSG_WriteByte(&local_434,0x65);
    MSG_WriteLong(&local_434,0);
    break;
  case 1:
    MSG_WriteLong(&local_434,-1);
    MSG_WriteString(&local_434,"ping\n");
    break;
  case 2:
    MSG_WriteLong(&local_434,-1);
    MSG_WriteString(&local_434,"rules\n");
    break;
  case 3:
    MSG_WriteLong(&local_434,-1);
    MSG_WriteString(&local_434,"players\n");
    break;
  case 4:
    MSG_WriteLong(&local_434,-1);
    MSG_WriteString(&local_434,"details\n");
    break;
  default:
    Con_Printf("Unknown request type:  %i\n",request);
  }
  if (0 < local_434.cursize) {
    NET_SendPacket(NS_CLIENT,local_434.cursize,local_434.data,pnVar4->request);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Net_Status  @ 001b7370
void Net_Status(net_status_s *status)

{
  double dVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  bool bVar5;
  
                    /* Unresolved local var: int connected@[???] */
  if (status == (net_status_s *)0x0) {
    return;
  }
  bVar5 = cls.state != ca_disconnected;
  status->connected = (uint)bVar5;
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
  if (!bVar5) {
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
                    /* Unresolved local var: int packet_loss@[???] */
    if (-1 < (int)cls.packet_loss) {
      iVar4 = (int)cls.packet_loss;
    }
    if (100 < iVar4) {
      iVar4 = 100;
    }
  }
  status->latency = g_flLatency;
  dVar1 = (double)cls.netchan.connect_time;
  status->packet_loss = iVar4;
  status->connection_time = dVar3 - dVar1;
  status->rate = (double)rate.value;
  return;
}


// Net_StringToAdr  @ 001b7300
int Net_StringToAdr(char *s,netadr_s *a)

{
  int iVar1;
  long lVar2;
  hostent *phVar3;
  char *__nptr;
  int in_GS_OFFSET;
  short sStack_a0;
  ushort uStack_9e;
  in_addr_t iStack_9c;
  char acStack_90 [127];
  undefined1 uStack_11;
  int iStack_10;
  
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = Q_strcmp(s,"localhost");
  if ((iVar1 == 0) || (iVar1 = Q_strcmp(s,"127.0.0.1"), iVar1 == 0)) {
    Q_memset(a,0,0x14);
    iVar1 = 1;
    a->type = NA_LOOPBACK;
  }
  else {
    Q_memset(&sStack_a0,0,0x10);
    __nptr = acStack_90;
    sStack_a0 = 2;
    uStack_9e = 0;
    Q_strncpy(acStack_90,s,0x7f);
    uStack_11 = 0;
    while (acStack_90[0] != '\0') {
      while (__nptr = __nptr + 1, acStack_90[0] != ':') {
        acStack_90[0] = *__nptr;
        if (acStack_90[0] == '\0') goto LAB_0011ace0;
      }
      __nptr[-1] = '\0';
      lVar2 = strtol(__nptr,(char **)0x0,10);
      uStack_9e = (ushort)lVar2 >> 8 | (ushort)lVar2 << 8;
      acStack_90[0] = *__nptr;
    }
LAB_0011ace0:
    iStack_9c = inet_addr(acStack_90);
    if (iStack_9c == 0xffffffff) {
      phVar3 = gethostbyname(acStack_90);
      if (phVar3 == (hostent *)0x0) {
        iVar1 = 0;
        goto LAB_0011ac22;
      }
      iStack_9c = *(in_addr_t *)*phVar3->h_addr_list;
    }
    if (sStack_a0 == 2) {
      a->type = NA_IP;
      *(in_addr_t *)a->ip = iStack_9c;
      a->port = uStack_9e;
    }
    iVar1 = 1;
  }
LAB_0011ac22:
  if (iStack_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


