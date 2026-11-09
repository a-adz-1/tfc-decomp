// Ghidra decompilation of functions from cl_dll/hud_servers.cpp
// 49 functions, ordered by original source line

// ListResponse  @ 000a4330  (line 38)

void ListResponse(net_response_s *response)

{
  undefined4 *puVar1;
  CHudServers *pCVar2;
  request_t *prVar3;
  
  pCVar2 = g_pServers;
                    /* Unresolved local var: request_t * list@[???]
                       Unresolved local var: request_t * p@[???]
                       Unresolved local var: int c@[???] */
  if (((g_pServers != (CHudServers *)0x0) && (response->error == 0)) && (response->type == 0)) {
                    /* Unresolved local var: request_t * list@[???]
                       Unresolved local var: request_t * p@[???]
                       Unresolved local var: int c@[???] */
    for (puVar1 = response->response; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      prVar3 = operator_new(0x1c);
      prVar3->context = -1;
      (prVar3->remote_address).type = puVar1[1];
      *(undefined4 *)(prVar3->remote_address).ip = puVar1[2];
                    /* catch() { ... } // from try @ 000a44dd with catch @ 000a4390 */
      *(undefined4 *)(prVar3->remote_address).ipx = puVar1[3];
      *(undefined4 *)((prVar3->remote_address).ipx + 4) = puVar1[4];
      *(undefined4 *)((prVar3->remote_address).ipx + 8) = puVar1[5];
      prVar3->next = pCVar2->m_pServerList;
      pCVar2->m_pServerList = prVar3;
    }
    (*gEngfuncs.Con_Printf)("got list\n");
    pCVar2->m_nQuerying = 1;
    pCVar2->m_nActiveQueries = 0;
    return;
  }
  return;
}


// ServerResponse  @ 000a4a10  (line 54)

void ServerResponse(net_response_s *response)

{
  if (g_pServers != (CHudServers *)0x0) {
    CHudServers::ServerResponse(g_pServers,response);
  }
  return;
}


// PingResponse  @ 000a43e0  (line 68)

void PingResponse(net_response_s *response)

{
  int in_GS_OFFSET;
  undefined1 auStack_30 [32];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (((g_pServers != (CHudServers *)0x0) && (response->error == 0)) && (response->type == 1)) {
    __sprintf_chk(auStack_30,1,0x20,&DAT_000caff6,(double)((float)response->ping * 1000.0));
    (*gEngfuncs.Con_Printf)("ping == %s\n",auStack_30);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// RulesResponse  @ 000a4480  (line 83)

void RulesResponse(net_response_s *response)

{
                    /* Unresolved local var: char * szresponse@[???] */
  if ((((g_pServers != (CHudServers *)0x0) && (response->error == 0)) && (response->type == 2)) &&
     (response->response != (void *)0x0)) {
    (*gEngfuncs.Con_Printf)("rules %s\n",response->response);
    return;
  }
  return;
}


// PlayersResponse  @ 000a44d0  (line 97)

void PlayersResponse(net_response_s *response)

{
                    /* try { // try from 000a44dd to 000b45e7 has its CatchHandler @ 000a4390 */
                    /* Unresolved local var: char * szresponse@[???] */
                    /* Unresolved local var: char * szresponse@[???] */
                    /* Unresolved local var: char * szresponse@[???] */
  if ((((g_pServers != (CHudServers *)0x0) && (response->error == 0)) && (response->type == 3)) &&
     (response->response != (void *)0x0)) {
    (*gEngfuncs.Con_Printf)("players %s\n",response->response);
    return;
  }
  return;
}


// CHudServers::ListResponse  @ 000a4620  (line 110)

/* DWARF original prototype: void ListResponse(CHudServers * this, net_response_s * response) */

void __thiscall CHudServers::ListResponse(CHudServers *this,net_response_s *response)

{
  undefined4 *puVar1;
  request_t *prVar2;
  request_t *prVar3;
  
                    /* Unresolved local var: request_t * list@[???]
                       Unresolved local var: request_t * p@[???]
                       Unresolved local var: int c@[???] */
  if ((response->error == 0) && (response->type == 0)) {
                    /* Unresolved local var: request_t * list@[???]
                       Unresolved local var: request_t * p@[???]
                       Unresolved local var: int c@[???] */
    for (puVar1 = response->response; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      prVar3 = operator_new(0x1c);
      prVar3->context = -1;
      (prVar3->remote_address).type = puVar1[1];
      *(undefined4 *)(prVar3->remote_address).ip = puVar1[2];
      *(undefined4 *)(prVar3->remote_address).ipx = puVar1[3];
      *(undefined4 *)((prVar3->remote_address).ipx + 4) = puVar1[4];
      *(undefined4 *)((prVar3->remote_address).ipx + 8) = puVar1[5];
      prVar2 = this->m_pServerList;
      this->m_pServerList = prVar3;
      prVar3->next = prVar2;
    }
    (*gEngfuncs.Con_Printf)("got list\n");
    this->m_nQuerying = 1;
    this->m_nActiveQueries = 0;
  }
  return;
}


// CHudServers::ServerResponse  @ 000a46c0  (line 156)

/* DWARF original prototype: void ServerResponse(CHudServers * this, net_response_s * response) */

void __thiscall CHudServers::ServerResponse(CHudServers *this,net_response_s *response)

{
  uint uVar1;
  double dVar2;
  request_s *prVar3;
  _func_void_char_ptr_char_ptr_char_ptr_int *p_Var4;
  request_s *prVar5;
  size_t sVar6;
  server_s *psVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  request_t *prVar12;
  server_s *psVar13;
  server_t *psVar14;
  server_t *psVar15;
  request_t *prVar16;
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: char * szresponse@[???]
                       Unresolved local var: request_t * p@[???]
                       Unresolved local var: server_t * browser@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char[32] sz@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  prVar12 = this->m_pActiveList;
                    /* Unresolved local var: request_t * p@[???] */
  if (prVar12 != (request_t *)0x0) {
    iVar10 = prVar12->context;
    prVar3 = prVar12;
    while (response->context != iVar10) {
      prVar3 = prVar3->next;
      if (prVar3 == (request_s *)0x0) goto LAB_000a4712;
      iVar10 = prVar3->context;
    }
                    /* Unresolved local var: request_t * p@[???]
                       Unresolved local var: request_t * n@[???]
                       Unresolved local var: request_t * newlist@[???] */
    if (this != (CHudServers *)0xfffffbec) {
      prVar16 = (request_t *)0x0;
      do {
        prVar5 = prVar12->next;
        if (prVar3 != prVar12) {
          prVar12->next = prVar16;
          prVar16 = prVar12;
        }
        prVar12 = prVar5;
      } while (prVar5 != (request_s *)0x0);
      this->m_pActiveList = prVar16;
    }
    this->m_nActiveQueries = this->m_nActiveQueries + -1;
  }
LAB_000a4712:
                    /* Unresolved local var: char * szresponse@[???]
                       Unresolved local var: request_t * p@[???]
                       Unresolved local var: server_t * browser@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char[32] sz@[???] */
  if (((response->error != 0) || (response->type != 4)) ||
     (pcVar9 = response->response, pcVar9 == (char *)0x0)) goto LAB_000a48b0;
  sVar6 = strlen(pcVar9);
  uVar1 = sVar6 + 0x65;
  __sprintf_chk(local_40,1,0x20,"%i",(int)((float)response->ping * 1000.0));
  psVar7 = operator_new(0x20);
  (psVar7->remote_address).type = (response->remote_address).type;
  *(undefined4 *)(psVar7->remote_address).ip = *(undefined4 *)(response->remote_address).ip;
  *(undefined4 *)(psVar7->remote_address).ipx = *(undefined4 *)(response->remote_address).ipx;
  *(undefined4 *)((psVar7->remote_address).ipx + 4) =
       *(undefined4 *)((response->remote_address).ipx + 4);
  *(undefined4 *)((psVar7->remote_address).ipx + 8) =
       *(undefined4 *)((response->remote_address).ipx + 8);
  pcVar8 = operator_new__(uVar1);
  dVar2 = response->ping;
  psVar7->info = pcVar8;
  psVar7->ping = (int)(dVar2 * 1000.0);
  strcpy(pcVar8,pcVar9);
  p_Var4 = (gEngfuncs.pNetAPI)->SetValueForKey;
  pcVar9 = (*(gEngfuncs.pNetAPI)->AdrToString)(&response->remote_address);
  (*p_Var4)(psVar7->info,"address",pcVar9,uVar1);
  (*(gEngfuncs.pNetAPI)->SetValueForKey)(psVar7->info,"ping",local_40,uVar1);
                    /* Unresolved local var: server_t * list@[???] */
  if ((this == (CHudServers *)0xfffffbe8) || (psVar7 == (server_s *)0x0)) goto LAB_000a48b0;
                    /* Unresolved local var: server_t * list@[???] */
  psVar14 = this->m_pServers;
  this->m_nServerCount = this->m_nServerCount + 1;
  if (psVar14 == (server_t *)0x0) {
    psVar7->next = (server_s *)0x0;
    this->m_pServers = psVar7;
    goto LAB_000a48b0;
  }
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
  if (psVar7->ping < psVar14->ping) {
LAB_000a49d5:
    psVar7->next = psVar14;
    this->m_pServers = psVar7;
  }
  else {
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
    if (((psVar7->ping == psVar14->ping) && (psVar7->info != (char *)0x0)) &&
       (psVar14->info != (char *)0x0)) {
      pcVar9 = (*(gEngfuncs.pNetAPI)->ValueForKey)(psVar7->info,"hostname");
      pcVar8 = (*(gEngfuncs.pNetAPI)->ValueForKey)(psVar14->info,"hostname");
      if (((pcVar9 != (char *)0x0) && (pcVar8 != (char *)0x0)) &&
         (iVar10 = strcasecmp(pcVar9,pcVar8), iVar10 < 0)) {
        psVar14 = this->m_pServers;
        goto LAB_000a49d5;
      }
    }
    psVar13 = psVar14->next;
    if (psVar13 == (server_s *)0x0) {
LAB_000a49e2:
      psVar7->next = (server_s *)0x0;
      psVar14->next = psVar7;
    }
    else {
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
      iVar10 = psVar7->ping;
      iVar11 = psVar13->ping;
      psVar15 = psVar14;
      if (iVar11 <= iVar10) {
        do {
          psVar14 = psVar13;
          if (((iVar11 == iVar10) && (psVar7->info != (char *)0x0)) &&
             (psVar13->info != (char *)0x0)) {
            pcVar9 = (*(gEngfuncs.pNetAPI)->ValueForKey)(psVar7->info,"hostname");
            pcVar8 = (*(gEngfuncs.pNetAPI)->ValueForKey)(psVar13->info,"hostname");
            if (((pcVar9 != (char *)0x0) && (pcVar8 != (char *)0x0)) &&
               (iVar10 = strcasecmp(pcVar9,pcVar8), iVar10 < 0)) {
              psVar13 = psVar15->next;
              break;
            }
            psVar14 = psVar15->next;
          }
          psVar13 = psVar14->next;
          if (psVar13 == (server_s *)0x0) goto LAB_000a49e2;
          iVar10 = psVar7->ping;
          iVar11 = psVar13->ping;
          psVar15 = psVar14;
        } while (iVar11 <= iVar10);
      }
      psVar7->next = psVar13->next;
      psVar15->next = psVar7;
    }
  }
LAB_000a48b0:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudServers::PingResponse  @ 000a4a30  (line 207)

/* DWARF original prototype: void PingResponse(CHudServers * this, net_response_s * response) */

void __thiscall CHudServers::PingResponse(CHudServers *this,net_response_s *response)

{
  int in_GS_OFFSET;
  undefined1 local_30 [32];
  int local_10;
  
                    /* Unresolved local var: char[32] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char[32] sz@[???] */
  if ((response->error == 0) && (response->type == 1)) {
    __sprintf_chk(local_30,1,0x20,&DAT_000caff6,(double)((float)response->ping * 1000.0));
    (*gEngfuncs.Con_Printf)("ping == %s\n",local_30);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
                    /* try { // try from 000a4a61 to 000b4a65 has its CatchHandler @ 000a6768 */
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudServers::RulesResponse  @ 000a4ac0  (line 232)

/* DWARF original prototype: void RulesResponse(CHudServers * this, net_response_s * response) */

void __thiscall CHudServers::RulesResponse(CHudServers *this,net_response_s *response)

{
                    /* Unresolved local var: char * szresponse@[???] */
                    /* Unresolved local var: char * szresponse@[???] */
  if (((response->error == 0) && (response->type == 2)) && (response->response != (void *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000a4ae4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEngfuncs.Con_Printf)("rules %s\n");
    return;
  }
  return;
}


// CHudServers::PlayersResponse  @ 000a4b00  (line 260)

/* DWARF original prototype: void PlayersResponse(CHudServers * this, net_response_s * response) */

void __thiscall CHudServers::PlayersResponse(CHudServers *this,net_response_s *response)

{
                    /* Unresolved local var: char * szresponse@[???] */
                    /* Unresolved local var: char * szresponse@[???] */
  if (((response->error == 0) && (response->type == 3)) && (response->response != (void *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000a4b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEngfuncs.Con_Printf)("players %s\n");
    return;
  }
  return;
}


// CHudServers::CompareServers  @ 000a4b40  (line 289)

/* DWARF original prototype: int CompareServers(CHudServers * this, server_t * p1, server_t * p2) */

int __thiscall CHudServers::CompareServers(CHudServers *this,server_t *p1,server_t *p2)

{
  int iVar1;
  char *__s1;
  char *__s2;
  uint uVar2;
  
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
  iVar1 = 1;
  if (p2->ping <= p1->ping) {
    if (((p1->ping == p2->ping) && (p1->info != (char *)0x0)) && (p2->info != (char *)0x0)) {
      __s1 = (*(gEngfuncs.pNetAPI)->ValueForKey)(p1->info,"hostname");
      __s2 = (*(gEngfuncs.pNetAPI)->ValueForKey)(p2->info,"hostname");
      if ((__s1 != (char *)0x0) && (__s2 != (char *)0x0)) {
        uVar2 = strcasecmp(__s1,__s2);
        return uVar2 >> 0x1f;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


// CHudServers::AddServer  @ 000a4bd0  (line 321)

/* DWARF original prototype: void AddServer(CHudServers * this, server_t * * ppList, server_t * p)
    */

void __thiscall CHudServers::AddServer(CHudServers *this,server_t **ppList,server_t *p)

{
  server_s *psVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  server_t *psVar5;
  server_t *psVar6;
  
                    /* Unresolved local var: server_t * list@[???] */
  if ((ppList != (server_t **)0x0) && (p != (server_t *)0x0)) {
                    /* Unresolved local var: server_t * list@[???] */
    this->m_nServerCount = this->m_nServerCount + 1;
    psVar5 = *ppList;
    if (psVar5 == (server_t *)0x0) {
      p->next = (server_s *)0x0;
      *ppList = p;
                    /* try { // try from 000a4d28 to 000b4d2c has its CatchHandler @ 000a6783 */
    }
    else {
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
      if (p->ping < psVar5->ping) {
LAB_000a4c99:
        p->next = psVar5;
        *ppList = p;
        return;
      }
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
      if (((p->ping == psVar5->ping) && (p->info != (char *)0x0)) && (psVar5->info != (char *)0x0))
      {
        pcVar2 = (*(gEngfuncs.pNetAPI)->ValueForKey)(p->info,"hostname");
        pcVar3 = (*(gEngfuncs.pNetAPI)->ValueForKey)(psVar5->info,"hostname");
        if ((pcVar2 != (char *)0x0) && (pcVar3 != (char *)0x0)) {
          iVar4 = strcasecmp(pcVar2,pcVar3);
          if (iVar4 < 0) {
            psVar5 = *ppList;
            goto LAB_000a4c99;
          }
        }
      }
      while (psVar1 = psVar5->next, psVar6 = psVar5, psVar5->next != (server_s *)0x0) {
        while( true ) {
          psVar5 = psVar1;
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
          if (p->ping < psVar5->ping) goto LAB_000a4d12;
          if (((p->ping == psVar5->ping) && (p->info != (char *)0x0)) &&
             (psVar5->info != (char *)0x0)) break;
                    /* Unresolved local var: char * n1@[???]
                       Unresolved local var: char * n2@[???] */
          psVar1 = psVar5->next;
          psVar6 = psVar5;
          if (psVar5->next == (server_s *)0x0) goto LAB_000a4c2d;
        }
        pcVar2 = (*(gEngfuncs.pNetAPI)->ValueForKey)(p->info,"hostname");
        pcVar3 = (*(gEngfuncs.pNetAPI)->ValueForKey)(psVar5->info,"hostname");
        if ((pcVar2 != (char *)0x0) && (pcVar3 != (char *)0x0)) {
          iVar4 = strcasecmp(pcVar2,pcVar3);
          if (iVar4 < 0) {
            psVar5 = psVar6->next;
LAB_000a4d12:
            p->next = psVar5->next;
            psVar6->next = p;
            return;
          }
        }
        psVar5 = psVar6->next;
      }
LAB_000a4c2d:
      p->next = (server_s *)0x0;
      psVar5->next = p;
    }
  }
  return;
}


// CHudServers::Think  @ 000a4d30  (line 374)

/* DWARF original prototype: void Think(CHudServers * this, double time) */

void __thiscall CHudServers::Think(CHudServers *this,double time)

{
  int iVar1;
  request_t *prVar2;
  
  this->m_fElapsed = this->m_fElapsed + time;
  if ((this->m_nRequesting != 0) && (this->m_nQuerying != 0)) {
    if ((this->m_nDone == 0) && (this->m_nActiveQueries < 0x15)) {
      prVar2 = this->m_pServerList;
      if (prVar2 != (request_t *)0x0) {
        do {
          this->m_pServerList = prVar2->next;
          iVar1 = context_id;
          prVar2->context = context_id;
          context_id = context_id + 1;
          (*(gEngfuncs.pNetAPI)->SendRequest)
                    (iVar1,4,0,2.0,&prVar2->remote_address,::ServerResponse);
          this->m_nActiveQueries = this->m_nActiveQueries + 1;
          prVar2->next = this->m_pActiveList;
          this->m_pActiveList = prVar2;
          if (0x14 < this->m_nActiveQueries) {
            return;
          }
          prVar2 = this->m_pServerList;
        } while (prVar2 != (request_t *)0x0);
        return;
      }
      prVar2 = this->m_pActiveList;
    }
    else {
      prVar2 = this->m_pActiveList;
      if (this->m_pServerList != (request_t *)0x0) {
        return;
      }
    }
    if (prVar2 == (request_t *)0x0) {
      this->m_nDone = 0;
      this->m_nQuerying = 0;
      *(undefined4 *)&this->m_dStarted = 0;
      *(undefined4 *)((int)&this->m_dStarted + 4) = 0;
      this->m_nRequesting = 0;
      this->m_nActiveQueries = 0;
    }
  }
  return;
}


// CHudServers::QueryThink  @ 000a4e90  (line 402)

/* DWARF original prototype: void QueryThink(CHudServers * this) */

void __thiscall CHudServers::QueryThink(CHudServers *this)

{
  request_t *prVar1;
  int iVar2;
  
                    /* Unresolved local var: request_t * p@[???] */
  if (((this->m_nRequesting != 0) && (this->m_nDone == 0)) && (this->m_nQuerying != 0)) {
                    /* Unresolved local var: request_t * p@[???] */
    while ((this->m_nActiveQueries < 0x15 &&
           (prVar1 = this->m_pServerList, prVar1 != (request_t *)0x0))) {
      this->m_pServerList = prVar1->next;
      iVar2 = context_id;
      prVar1->context = context_id;
      context_id = context_id + 1;
                    /* try { // try from 000a4ee5 to 000b4ee9 has its CatchHandler @ 000a6785 */
                    /* try { // try from 000a4f25 to 000b4f81 has its CatchHandler @ 000a45f0 */
      (*(gEngfuncs.pNetAPI)->SendRequest)(iVar2,4,0,2.0,&prVar1->remote_address,::ServerResponse);
      this->m_nActiveQueries = this->m_nActiveQueries + 1;
      prVar1->next = this->m_pActiveList;
      this->m_pActiveList = prVar1;
    }
  }
  return;
}


// CHudServers::ServerListSize  @ 000a4f50  (line 456)

/* DWARF original prototype: int ServerListSize(CHudServers * this) */

int __thiscall CHudServers::ServerListSize(CHudServers *this)

{
  request_t *prVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: request_t * p@[???] */
  iVar2 = 0;
  for (prVar1 = this->m_pServerList; prVar1 != (request_t *)0x0; prVar1 = prVar1->next) {
    iVar2 = iVar2 + 1;
  }
  for (prVar1 = this->m_pActiveList; prVar1 != (request_t *)0x0; prVar1 = prVar1->next) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// CHudServers::FindRequest  @ 000a4f90  (line 485)

/* DWARF original prototype: request_t * FindRequest(CHudServers * this, int context, request_t *
   pList) */

request_t * __thiscall CHudServers::FindRequest(CHudServers *this,int context,request_t *pList)

{
                    /* Unresolved local var: request_t * p@[???] */
  if (pList == (request_t *)0x0) {
    pList = (request_t *)0x0;
  }
  else {
    if (context == pList->context) {
      return pList;
    }
    do {
      pList = pList->next;
      if (pList == (request_t *)0x0) {
        return (request_t *)0x0;
      }
    } while (pList->context != context);
  }
  return pList;
}


// CHudServers::RemoveServerFromList  @ 000a4fd0  (line 506)

/* DWARF original prototype: void RemoveServerFromList(CHudServers * this, request_t * * ppList,
   request_t * item) */

void __thiscall
CHudServers::RemoveServerFromList(CHudServers *this,request_t **ppList,request_t *item)

{
  request_s *prVar1;
  request_t *prVar2;
  request_s *prVar3;
  
                    /* Unresolved local var: request_t * p@[???]
                       Unresolved local var: request_t * n@[???]
                       Unresolved local var: request_t * newlist@[???] */
  if (ppList != (request_t **)0x0) {
    prVar1 = *ppList;
    prVar3 = (request_s *)0x0;
    while (prVar2 = prVar1, prVar2 != (request_t *)0x0) {
      prVar1 = prVar2->next;
      if (item != prVar2) {
        prVar2->next = prVar3;
        prVar3 = prVar2;
      }
    }
    *ppList = prVar3;
  }
  return;
}


// CHudServers::ClearRequestList  @ 000a5010  (line 534)

/* DWARF original prototype: void ClearRequestList(CHudServers * this, request_t * * ppList) */

void __thiscall CHudServers::ClearRequestList(CHudServers *this,request_t **ppList)

{
  request_s *prVar1;
  request_t *prVar2;
  
                    /* Unresolved local var: request_t * p@[???]
                       Unresolved local var: request_t * n@[???] */
  if (ppList != (request_t **)0x0) {
    prVar2 = *ppList;
    while (prVar2 != (request_t *)0x0) {
      prVar1 = prVar2->next;
      operator_delete(prVar2);
      prVar2 = prVar1;
    }
    *ppList = (request_t *)0x0;
  }
  return;
}


// CHudServers::ClearServerList  @ 000a5050  (line 557)

/* DWARF original prototype: void ClearServerList(CHudServers * this, server_t * * ppList) */

void __thiscall CHudServers::ClearServerList(CHudServers *this,server_t **ppList)

{
  server_s *psVar1;
  server_t *psVar2;
  
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: server_t * n@[???] */
  if (ppList != (server_t **)0x0) {
    psVar2 = *ppList;
    while (psVar2 != (server_t *)0x0) {
      psVar1 = psVar2->next;
      if (psVar2->info != (char *)0x0) {
        operator_delete__(psVar2->info);
      }
      operator_delete(psVar2);
      psVar2 = psVar1;
    }
    *ppList = (server_t *)0x0;
  }
  return;
}


// CompareField  @ 000a50a0  (line 575)

int CompareField(server_t *p1,server_t *p2,char *fieldname,int iSortOrder)

{
  float fVar1;
  float fVar2;
  char *__nptr;
  char *__nptr_00;
  int iVar3;
  double dVar4;
  
                    /* Unresolved local var: char * sz1@[???]
                       Unresolved local var: char * sz2@[???]
                       Unresolved local var: float fv1@[???]
                       Unresolved local var: float fv2@[???] */
  __nptr = (*(gEngfuncs.pNetAPI)->ValueForKey)(p1->info,fieldname);
  __nptr_00 = (*(gEngfuncs.pNetAPI)->ValueForKey)(p2->info,fieldname);
  dVar4 = strtod(__nptr,(char **)0x0);
  fVar1 = (float)dVar4;
  dVar4 = strtod(__nptr_00,(char **)0x0);
  fVar2 = (float)dVar4;
  if ((fVar1 != 0.0) && (fVar2 != 0.0)) {
    if ((fVar1 <= fVar2) && (iSortOrder = -iSortOrder, fVar2 <= fVar1)) {
      iSortOrder = 0;
    }
    return iSortOrder;
  }
  iVar3 = strcasecmp(__nptr,__nptr_00);
  return iVar3;
}


// ServerListCompareFunc  @ 000a51a0  (line 600)

int ServerListCompareFunc(server_t *p1,server_t *p2,char *fieldname)

{
  float fVar1;
  float fVar2;
  char *__nptr;
  char *__nptr_00;
  int iVar3;
  double dVar4;
  
                    /* Unresolved local var: int iSortOrder@[???]
                       Unresolved local var: int retval@[???] */
  if ((p1 == (server_t *)0x0) || (p2 == (server_t *)0x0)) {
    iVar3 = 0;
  }
  else {
                    /* Unresolved local var: int iSortOrder@[???]
                       Unresolved local var: int retval@[???]
                       Unresolved local var: char * sz1@[???]
                       Unresolved local var: char * sz2@[???]
                       Unresolved local var: float fv1@[???]
                       Unresolved local var: float fv2@[???] */
    __nptr = (*(gEngfuncs.pNetAPI)->ValueForKey)(p1->info,fieldname);
    __nptr_00 = (*(gEngfuncs.pNetAPI)->ValueForKey)(p2->info,fieldname);
    dVar4 = strtod(__nptr,(char **)0x0);
    fVar1 = (float)dVar4;
    dVar4 = strtod(__nptr_00,(char **)0x0);
    fVar2 = (float)dVar4;
    if ((fVar1 == 0.0) || (fVar2 == 0.0)) {
      iVar3 = strcasecmp(__nptr,__nptr_00);
      return iVar3;
    }
    iVar3 = 1;
    if (fVar1 <= fVar2) {
      return -(uint)(fVar1 < fVar2);
    }
  }
  return iVar3;
}


// FnServerCompare  @ 000a4520  (line 615)

int FnServerCompare(void *elem1,void *elem2)

{
  float fVar1;
  float fVar2;
  char *__nptr;
  char *__nptr_00;
  int iVar3;
  double dVar4;
  
                    /* Unresolved local var: server_t * list1@[???]
                       Unresolved local var: server_t * list2@[???] */
  iVar3 = *(int *)elem2;
                    /* Unresolved local var: int iSortOrder@[???]
                       Unresolved local var: int retval@[???] */
  if ((*(int *)elem1 == 0) || (iVar3 == 0)) {
    iVar3 = 0;
  }
  else {
                    /* Unresolved local var: int iSortOrder@[???]
                       Unresolved local var: int retval@[???]
                       Unresolved local var: char * sz1@[???]
                       Unresolved local var: char * sz2@[???]
                       Unresolved local var: float fv1@[???]
                       Unresolved local var: float fv2@[???] */
    __nptr = (*(gEngfuncs.pNetAPI)->ValueForKey)(*(char **)(*(int *)elem1 + 0x18),g_fieldname);
    __nptr_00 = (*(gEngfuncs.pNetAPI)->ValueForKey)(*(char **)(iVar3 + 0x18),g_fieldname);
    dVar4 = strtod(__nptr,(char **)0x0);
    fVar1 = (float)dVar4;
    dVar4 = strtod(__nptr_00,(char **)0x0);
    fVar2 = (float)dVar4;
    if ((fVar1 == 0.0) || (fVar2 == 0.0)) {
      iVar3 = strcasecmp(__nptr,__nptr_00);
      return iVar3;
    }
    iVar3 = 1;
    if (fVar1 <= fVar2) {
                    /* catch() { ... } // from try @ 000a4496 with catch @ 000a45d6 */
      return -(uint)(fVar1 < fVar2);
    }
  }
                    /* catch() { ... } // from try @ 000a48a5 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a4941 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a4a8e with catch @ 000a45f0
                       catch() { ... } // from try @ 000a4b5e with catch @ 000a45f0
                       catch() { ... } // from try @ 000a4c61 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a4d47 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a4f25 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a502d with catch @ 000a45f0
                       catch() { ... } // from try @ 000a518b with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5301 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a53f1 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a54be with catch @ 000a45f0
                       catch() { ... } // from try @ 000a553f with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5647 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a56c7 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a57d4 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a588b with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5925 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a59fb with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5b97 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5c27 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5cf2 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5dc2 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5eff with catch @ 000a45f0
                       catch() { ... } // from try @ 000a5fc6 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a607d with catch @ 000a45f0
                       catch() { ... } // from try @ 000a620b with catch @ 000a45f0
                       catch() { ... } // from try @ 000a62d0 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6392 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a649e with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6563 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6628 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a66ed with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6888 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a694d with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6a1c with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6ae1 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6c28 with catch @ 000a45f0
                       catch() { ... } // from try @ 000a6ced with catch @ 000a45f0 */
  return iVar3;
}


// CHudServers::SortServers  @ 000a52b0  (line 625)

/* WARNING: Removing unreachable block (ram,0x000a5459) */
/* WARNING: Removing unreachable block (ram,0x000a542a) */
/* DWARF original prototype: void SortServers(CHudServers * this, char * fieldname) */

void __thiscall CHudServers::SortServers(CHudServers *this,char *fieldname)

{
  int *piVar1;
  int *piVar2;
  server_t *psVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  size_t sVar7;
  int *piVar8;
  int *piVar9;
  byte bVar10;
  int iVar11;
  int iStack_24;
  size_t sStack_20;
  
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: server_t * * pSortArray@[???]
                       Unresolved local var: size_t nCount@[???]
                       Unresolved local var: size_t nSize@[???] */
  bVar10 = 0;
  if (this->m_pServers == (server_t *)0x0) {
    return;
  }
  iVar11 = 0x100;
  __strcpy_chk(g_fieldname);
  psVar3 = this->m_pServers;
  if (psVar3 == (server_t *)0x0) {
    piVar2 = operator_new__(0);
    psVar3 = this->m_pServers;
    if (psVar3 != (server_t *)0x0) {
      sVar7 = 0xffffffff;
      iStack_24 = -4;
      sStack_20 = 0;
      piVar8 = piVar2;
      goto LAB_000a5370;
    }
    qsort(piVar2,0,4,FnServerCompare);
    this->m_pServers = (server_t *)*piVar2;
    iStack_24 = -4;
    goto LAB_000a53bd;
  }
  sStack_20 = 0;
  do {
    sVar7 = sStack_20;
    psVar3 = psVar3->next;
    sStack_20 = sVar7 + 1;
  } while (psVar3 != (server_s *)0x0);
  if (0x1fc00000 < (int)sStack_20) {
    __cxa_throw_bad_array_new_length();
    piVar2 = *(int **)(fieldname + 0x418);
    if ((piVar2 != (int *)0x0) && (iVar11 != 0)) {
      iVar6 = 0;
      do {
        piVar2 = (int *)*piVar2;
        iVar6 = iVar6 + 1;
        if (piVar2 == (int *)0x0) {
          return;
        }
      } while (iVar11 != iVar6);
    }
    return;
  }
  uVar5 = sStack_20 * 4;
  iStack_24 = uVar5 - 4;
  piVar2 = operator_new__(uVar5);
  piVar9 = piVar2;
  if (uVar5 < 8) {
    if ((uVar5 & 4) == 0) goto LAB_000a5349;
    *piVar2 = 0;
    piVar9 = piVar2 + 1;
  }
  else {
    uVar4 = uVar5;
    if (((uint)piVar2 & 1) != 0) {
      *(undefined1 *)piVar2 = 0;
      piVar9 = (int *)((int)piVar2 + 1);
      uVar4 = uVar5 - 1;
    }
    if (((uint)piVar9 & 2) != 0) {
      *(undefined2 *)piVar9 = 0;
      uVar4 = uVar4 - 2;
      piVar9 = (int *)((int)piVar9 + 2);
    }
    if (((uint)piVar9 & 4) != 0) {
      *piVar9 = 0;
      uVar4 = uVar4 - 4;
      piVar9 = piVar9 + 1;
    }
    uVar5 = uVar4 & 3;
    for (uVar4 = uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *piVar9 = 0;
      piVar9 = piVar9 + (uint)bVar10 * -2 + 1;
    }
LAB_000a5349:
    if ((uVar5 & 2) != 0) {
      *(undefined2 *)piVar9 = 0;
      piVar9 = (int *)((int)piVar9 + 2);
    }
  }
  piVar8 = piVar2;
  if ((uVar5 & 1) == 0) {
    psVar3 = this->m_pServers;
  }
  else {
    *(undefined1 *)piVar9 = 0;
    psVar3 = this->m_pServers;
  }
  for (; psVar3 != (server_t *)0x0; psVar3 = psVar3->next) {
LAB_000a5370:
    *piVar2 = (int)psVar3;
    piVar2 = piVar2 + 1;
  }
  qsort(piVar8,sStack_20,4,FnServerCompare);
  this->m_pServers = (server_t *)*piVar8;
  piVar2 = piVar8;
  if (0 < (int)sVar7) {
    piVar9 = piVar8;
    do {
      piVar1 = (int *)*piVar9;
      piVar9 = piVar9 + 1;
      *piVar1 = *piVar9;
    } while (piVar8 + sVar7 != piVar9);
  }
LAB_000a53bd:
  **(undefined4 **)((int)piVar2 + iStack_24) = 0;
  if (piVar2 == (int *)0x0) {
    return;
  }
  operator_delete__(piVar2);
  return;
}


// CHudServers::GetServer  @ 000a5500  (line 692)

/* DWARF original prototype: server_t * GetServer(CHudServers * this, int server) */

server_t * __thiscall CHudServers::GetServer(CHudServers *this,int server)

{
  server_t *psVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: server_t * p@[???] */
  psVar1 = this->m_pServers;
  if (psVar1 == (server_t *)0x0) {
    psVar1 = (server_t *)0x0;
  }
  else if (server != 0) {
    iVar2 = 0;
    do {
      psVar1 = psVar1->next;
      iVar2 = iVar2 + 1;
      if (psVar1 == (server_s *)0x0) {
        return (server_t *)0x0;
      }
                    /* try { // try from 000a5522 to 000b5526 has its CatchHandler @ 000a67d5 */
    } while (server != iVar2);
  }
  return psVar1;
}


// CHudServers::GetServerInfo  @ 000a5540  (line 692)

/* DWARF original prototype: char * GetServerInfo(CHudServers * this, int server) */

char * __thiscall CHudServers::GetServerInfo(CHudServers *this,int server)

{
  server_t *psVar1;
  int iVar2;
  
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: int c@[???] */
  psVar1 = this->m_pServers;
  if (psVar1 == (server_t *)0x0) {
    return (char *)0x0;
  }
  if (server != 0) {
    iVar2 = 0;
    do {
      psVar1 = psVar1->next;
      iVar2 = iVar2 + 1;
      if (psVar1 == (server_s *)0x0) {
        return (char *)0x0;
      }
    } while (server != iVar2);
  }
  return psVar1->info;
}


// CHudServers::CancelRequest  @ 000a5580  (line 729)

/* DWARF original prototype: void CancelRequest(CHudServers * this) */

void __thiscall CHudServers::CancelRequest(CHudServers *this)

{
  this->m_nRequesting = 0;
  this->m_nQuerying = 0;
  this->m_nDone = 1;
                    /* WARNING: Could not recover jumptable at 0x000a55a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pNetAPI)->CancelAllRequests)();
  return;
}


// CHudServers::LoadMasterAddresses  @ 000a55b0  (line 745)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int LoadMasterAddresses(CHudServers * this, int maxservers, int *
   count, netadr_t * padr) */

int __thiscall
CHudServers::LoadMasterAddresses(CHudServers *this,int maxservers,int *count,netadr_t *padr)

{
  netadr_t *pnVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  int in_GS_OFFSET;
  bool bVar10;
  byte *local_378;
  netadr_s local_374;
  char local_360 [64];
  char local_320 [4];
  undefined2 uStack_31c;
  char acStack_31a [250];
  char local_220 [256];
  undefined1 local_120 [256];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] szMaster@[???]
                       Unresolved local var: char[256] szMasterFile@[???]
                       Unresolved local var: char * pbuffer@[???]
                       Unresolved local var: char * pstart@[???]
                       Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: char[64] szAdr@[???]
                       Unresolved local var: int nPort@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: bool bIgnore@[???]
                       Unresolved local var: int nDefaultPort@[???] */
  local_378 = (byte *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = 0;
  do {
    uVar8 = uVar3;
    *(undefined4 *)(local_320 + uVar8) = *(undefined4 *)("half-life.east.won.net" + uVar8);
    uVar3 = uVar8 + 4;
  } while (uVar8 + 4 < 0x14);
  cVar2 = "half-life.east.won.net"[uVar8 + 6];
                    /* try { // try from 000a5625 to 000b5629 has its CatchHandler @ 000a6792 */
  builtin_strncpy(local_220 + 4,"ecomm.ls",8);
  *(undefined2 *)((int)&uStack_31c + uVar8) = *(undefined2 *)("half-life.east.won.net" + uVar8 + 4);
  acStack_31a[uVar8] = cVar2;
  local_220[0xc] = 't';
  local_220[0xd] = '\0';
                    /* try { // try from 000a5647 to 000b564b has its CatchHandler @ 000a45f0 */
  builtin_strncpy(local_220,"valv",4);
  iVar4 = (*gEngfuncs.CheckParm)("-comm",(char **)&local_378);
  if ((iVar4 != 0) && (local_378 != (byte *)0x0)) {
                    /* try { // try from 000a58ed to 000b58f1 has its CatchHandler @ 000a6b0d */
    __strcpy_chk(local_220,local_378,0x100);
  }
  pbVar5 = (*gEngfuncs.COM_LoadFile)(local_220,5,(int *)0x0);
  if (pbVar5 == (byte *)0x0) {
    uVar3 = 0;
    do {
      uVar8 = uVar3;
      *(undefined4 *)(local_320 + uVar8) = *(undefined4 *)("half-life.east.won.net" + uVar8);
      uVar3 = uVar8 + 4;
    } while (uVar8 + 4 < 0x14);
    cVar2 = "half-life.east.won.net"[uVar8 + 6];
    *(undefined2 *)((int)&uStack_31c + uVar8) =
         *(undefined2 *)("half-life.east.won.net" + uVar8 + 4);
                    /* try { // try from 000a59fb to 000b5aef has its CatchHandler @ 000a45f0 */
    acStack_31a[uVar8] = cVar2;
    iVar4 = (*(gEngfuncs.pNetAPI)->StringToAdr)(local_320,&local_374);
    if (iVar4 == 0) {
      *count = 0;
      iVar4 = 0;
    }
    else {
      iVar4 = 1;
      padr->type = local_374.type;
      *&padr->ip = local_374.ip;
      *(undefined4 *)padr->ipx = local_374.ipx._0_4_;
      *(undefined4 *)(padr->ipx + 4) = local_374.ipx._4_4_;
      *(undefined4 *)(padr->ipx + 8) = local_374._16_4_;
      *count = 1;
    }
  }
  else {
    local_378 = pbVar5;
    if (maxservers < 1) {
LAB_000a5930:
      uVar3 = 0;
      do {
        uVar8 = uVar3;
        *(undefined4 *)(local_320 + uVar8) = *(undefined4 *)("half-life.east.won.net" + uVar8);
        uVar3 = uVar8 + 4;
      } while (uVar8 + 4 < 0x14);
      cVar2 = "half-life.east.won.net"[uVar8 + 6];
      *(undefined2 *)((int)&uStack_31c + uVar8) =
           *(undefined2 *)("half-life.east.won.net" + uVar8 + 4);
      acStack_31a[uVar8] = cVar2;
      iVar4 = (*(gEngfuncs.pNetAPI)->StringToAdr)(local_320,&local_374);
      if (iVar4 == 0) {
        *count = 0;
        iVar4 = 0;
      }
      else {
        iVar4 = 1;
        padr->type = local_374.type;
        *&padr->ip = local_374.ip;
        *(undefined4 *)padr->ipx = local_374.ipx._0_4_;
        *(undefined4 *)(padr->ipx + 4) = local_374.ipx._4_4_;
        *(undefined4 *)(padr->ipx + 8) = local_374._16_4_;
        *count = 1;
                    /* try { // try from 000a59c3 to 000b59c7 has its CatchHandler @ 000a6754 */
      }
    }
    else {
                    /* try { // try from 000a56ad to 000b56b1 has its CatchHandler @ 000a6796 */
      iVar9 = 0;
                    /* Unresolved local var: char[256] base@[???] */
      pbVar6 = pbVar5;
                    /* try { // try from 000a56c7 to 000b5733 has its CatchHandler @ 000a45f0 */
      while (pbVar6 = (byte *)(*gEngfuncs.COM_ParseFile)((char *)pbVar6,this->m_szToken),
            local_378 = pbVar6, this->m_szToken[0] != '\0') {
        iVar4 = strcasecmp(this->m_szToken,"Master");
        bVar10 = iVar4 != 0;
        pbVar6 = (byte *)(*gEngfuncs.COM_ParseFile)((char *)pbVar6,this->m_szToken);
        local_378 = pbVar6;
        if ((this->m_szToken[0] == '\0') || (iVar4 = strcasecmp(this->m_szToken,"{"), iVar4 != 0))
        break;
                    /* try { // try from 000a5793 to 000b5797 has its CatchHandler @ 000a6b15 */
        while ((pbVar6 = (byte *)(*gEngfuncs.COM_ParseFile)((char *)pbVar6,this->m_szToken),
               local_378 = pbVar6, this->m_szToken[0] != '\0' &&
               (iVar4 = strcasecmp(this->m_szToken,"}"), iVar4 != 0))) {
          __sprintf_chk(local_120,1,0x100,&DAT_000c4b6e,this);
                    /* try { // try from 000a57d4 to 000b57eb has its CatchHandler @ 000a45f0 */
          pbVar6 = (byte *)(*gEngfuncs.COM_ParseFile)((char *)local_378,this->m_szToken);
          local_378 = pbVar6;
          if ((this->m_szToken[0] == '\0') ||
             ((iVar4 = strcasecmp(this->m_szToken,":"), iVar4 != 0 ||
              (pbVar6 = (byte *)(*gEngfuncs.COM_ParseFile)((char *)pbVar6,this->m_szToken),
              local_378 = pbVar6, this->m_szToken[0] == '\0')))) break;
          lVar7 = strtol(this->m_szToken,(char **)0x0,10);
                    /* try { // try from 000a584b to 000b584f has its CatchHandler @ 000a6766 */
          if (lVar7 == 0) {
            lVar7 = 0x6982;
          }
          __sprintf_chk(local_360,1,0x40,"%s:%i",local_120,lVar7);
                    /* try { // try from 000a588b to 000b588f has its CatchHandler @ 000a45f0 */
          iVar4 = (*(gEngfuncs.pNetAPI)->StringToAdr)(local_360,&local_374);
          if (iVar4 == 0) {
            bVar10 = true;
          }
          else if (!bVar10) {
            pnVar1 = padr + iVar9;
            pnVar1->type = local_374.type;
            *&pnVar1->ip = local_374.ip;
            *(undefined4 *)pnVar1->ipx = local_374.ipx._0_4_;
            *(undefined4 *)(pnVar1->ipx + 4) = local_374.ipx._4_4_;
            *(undefined4 *)(pnVar1->ipx + 8) = local_374._16_4_;
            iVar9 = iVar9 + 1;
          }
          pbVar6 = local_378;
          if (maxservers <= iVar9) goto LAB_000a58a7;
        }
        if (maxservers <= iVar9) goto LAB_000a58a7;
      }
      if (iVar9 == 0) goto LAB_000a5930;
LAB_000a58a7:
      iVar4 = 1;
      *count = iVar9;
    }
    (*gEngfuncs.COM_FreeFile)(pbVar5);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudServers::RequestList  @ 000a5a80  (line 878)

/* DWARF original prototype: void RequestList(CHudServers * this) */

void __thiscall CHudServers::RequestList(CHudServers *this)

{
  request_s *prVar1;
  server_s *psVar2;
  request_t *prVar3;
  server_t *psVar4;
  int iVar5;
  int in_GS_OFFSET;
  int local_38;
  netadr_t local_34;
  int local_20;
  
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: netadr_t adr@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  this->m_nRequesting = 1;
  this->m_nDone = 0;
  this->m_dStarted = this->m_fElapsed;
  local_38 = 0;
  iVar5 = LoadMasterAddresses(this,1,&local_38,&local_34);
  if (iVar5 == 0) {
    (*gEngfuncs.Con_DPrintf)("SendRequest:  Unable to read master server addresses\n");
  }
  else {
                    /* Unresolved local var: request_t * p@[???]
                       Unresolved local var: request_t * n@[???] */
    if (this != (CHudServers *)0xfffffbec) {
      prVar3 = this->m_pActiveList;
      while (prVar3 != (request_t *)0x0) {
        prVar1 = prVar3->next;
        operator_delete(prVar3);
        prVar3 = prVar1;
      }
      this->m_pActiveList = (request_t *)0x0;
    }
                    /* Unresolved local var: request_t * p@[???]
                       Unresolved local var: request_t * n@[???] */
    if (this != (CHudServers *)0xfffffbf0) {
      prVar3 = this->m_pServerList;
      while (prVar3 != (request_t *)0x0) {
        prVar1 = prVar3->next;
        operator_delete(prVar3);
        prVar3 = prVar1;
      }
      this->m_pServerList = (request_t *)0x0;
    }
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: server_t * n@[???] */
    if (this != (CHudServers *)0xfffffbe8) {
      psVar4 = this->m_pServers;
      while (psVar4 != (server_t *)0x0) {
        psVar2 = psVar4->next;
        if (psVar4->info != (char *)0x0) {
          operator_delete__(psVar4->info);
        }
        operator_delete(psVar4);
        psVar4 = psVar2;
      }
      this->m_pServers = (server_t *)0x0;
    }
    this->m_nServerCount = 0;
                    /* try { // try from 000a5b97 to 000b5bbd has its CatchHandler @ 000a45f0 */
    (*(gEngfuncs.pNetAPI)->InitNetworking)();
    (*(gEngfuncs.pNetAPI)->CancelAllRequests)();
    iVar5 = context_id;
    context_id = context_id + 1;
    (*(gEngfuncs.pNetAPI)->SendRequest)(iVar5,0,0,5.0,&local_34,::ListResponse);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudServers::RequestBroadcastList  @ 000a5c20  (line 909)

/* DWARF original prototype: void RequestBroadcastList(CHudServers * this, int clearpending) */

void __thiscall CHudServers::RequestBroadcastList(CHudServers *this,int clearpending)

{
  request_s *prVar1;
  server_s *psVar2;
  request_t *prVar3;
  server_t *psVar4;
  net_api_s *pnVar5;
  int iVar6;
  int in_GS_OFFSET;
  netadr_s local_24;
  int local_10;
  
                    /* Unresolved local var: netadr_t adr@[???] */
                    /* try { // try from 000a5c27 to 000b5c86 has its CatchHandler @ 000a45f0 */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_24.ipx[0] = '\0';
  local_24.ipx[1] = '\0';
  local_24.ipx[2] = '\0';
  local_24.ipx[3] = '\0';
  this->m_nRequesting = 1;
  this->m_nDone = 0;
  this->m_dStarted = this->m_fElapsed;
  local_24.type = NA_UNUSED;
  local_24.ip[0] = '\0';
  local_24.ip[1] = '\0';
  local_24.ip[2] = '\0';
  local_24.ip[3] = '\0';
  local_24.ipx[4] = '\0';
  local_24.ipx[5] = '\0';
  local_24.ipx[6] = '\0';
  local_24.ipx[7] = '\0';
  local_24.ipx[8] = '\0';
  local_24.ipx[9] = '\0';
  local_24.port = 0;
  if (clearpending == 0) {
    local_24.ipx[8] = '\0';
    local_24.ipx[9] = '\0';
    local_24.port = 0x8769;
    (*(gEngfuncs.pNetAPI)->InitNetworking)();
  }
  else {
                    /* Unresolved local var: request_t * p@[???]
                       Unresolved local var: request_t * n@[???] */
    if (this != (CHudServers *)0xfffffbec) {
      prVar3 = this->m_pActiveList;
      while (prVar3 != (request_t *)0x0) {
        prVar1 = prVar3->next;
        operator_delete(prVar3);
        prVar3 = prVar1;
      }
      this->m_pActiveList = (request_t *)0x0;
    }
                    /* Unresolved local var: request_t * p@[???]
                       Unresolved local var: request_t * n@[???] */
    if (this != (CHudServers *)0xfffffbf0) {
      prVar3 = this->m_pServerList;
      while (prVar3 != (request_t *)0x0) {
        prVar1 = prVar3->next;
        operator_delete(prVar3);
        prVar3 = prVar1;
      }
                    /* try { // try from 000a5ce6 to 000b5cea has its CatchHandler @ 000a674d */
      this->m_pServerList = (request_t *)0x0;
    }
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: server_t * n@[???] */
    if (this != (CHudServers *)0xfffffbe8) {
                    /* try { // try from 000a5cf2 to 000b5d51 has its CatchHandler @ 000a45f0 */
      psVar4 = this->m_pServers;
      while (psVar4 != (server_t *)0x0) {
        psVar2 = psVar4->next;
        if (psVar4->info != (char *)0x0) {
          operator_delete__(psVar4->info);
        }
        operator_delete(psVar4);
        psVar4 = psVar2;
      }
      this->m_pServers = (server_t *)0x0;
    }
    pnVar5 = gEngfuncs.pNetAPI;
    this->m_nServerCount = 0;
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
    local_24.port = 0x8769;
    (*pnVar5->InitNetworking)();
    (*(gEngfuncs.pNetAPI)->CancelAllRequests)();
  }
  iVar6 = context_id;
  local_24.type = NA_BROADCAST;
  context_id = context_id + 1;
  (*(gEngfuncs.pNetAPI)->SendRequest)(iVar6,4,1,5.0,&local_24,::ServerResponse);
  iVar6 = context_id;
  local_24.type = NA_BROADCAST_IPX;
                    /* try { // try from 000a5db1 to 000b5db5 has its CatchHandler @ 000a6b65 */
                    /* try { // try from 000a5dc2 to 000b5e7b has its CatchHandler @ 000a45f0 */
  context_id = context_id + 1;
  (*(gEngfuncs.pNetAPI)->SendRequest)(iVar6,4,1,5.0,&local_24,::ServerResponse);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudServers::ServerPing  @ 000a5e20  (line 950)

/* DWARF original prototype: void ServerPing(CHudServers * this, int server) */

void __thiscall CHudServers::ServerPing(CHudServers *this,int server)

{
  int iVar1;
  server_t *psVar2;
  
                    /* Unresolved local var: server_t * p@[???] */
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: server_t * p@[???] */
  psVar2 = this->m_pServers;
  if (psVar2 == (server_t *)0x0) {
    return;
  }
  if (server != 0) {
    iVar1 = 0;
    do {
      psVar2 = psVar2->next;
      iVar1 = iVar1 + 1;
      if (psVar2 == (server_s *)0x0) {
        return;
      }
    } while (server != iVar1);
  }
  (*(gEngfuncs.pNetAPI)->InitNetworking)();
  iVar1 = context_id;
  context_id = context_id + 1;
  (*(gEngfuncs.pNetAPI)->SendRequest)(iVar1,1,0,5.0,&psVar2->remote_address,::PingResponse);
  return;
}


// CHudServers::ServerRules  @ 000a5eb0  (line 965)

/* DWARF original prototype: void ServerRules(CHudServers * this, int server) */

void __thiscall CHudServers::ServerRules(CHudServers *this,int server)

{
  int iVar1;
  server_t *psVar2;
  
                    /* Unresolved local var: server_t * p@[???] */
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: server_t * p@[???] */
  psVar2 = this->m_pServers;
  if (psVar2 == (server_t *)0x0) {
    return;
  }
  if (server != 0) {
    iVar1 = 0;
    do {
      psVar2 = psVar2->next;
      iVar1 = iVar1 + 1;
      if (psVar2 == (server_s *)0x0) {
        return;
      }
    } while (server != iVar1);
  }
  (*(gEngfuncs.pNetAPI)->InitNetworking)();
  iVar1 = context_id;
                    /* try { // try from 000a5eff to 000b5f2d has its CatchHandler @ 000a45f0 */
  context_id = context_id + 1;
  (*(gEngfuncs.pNetAPI)->SendRequest)(iVar1,2,0,5.0,&psVar2->remote_address,::RulesResponse);
  return;
}


// CHudServers::ServerPlayers  @ 000a5f40  (line 980)

/* DWARF original prototype: void ServerPlayers(CHudServers * this, int server) */

void __thiscall CHudServers::ServerPlayers(CHudServers *this,int server)

{
  int iVar1;
  server_t *psVar2;
  
                    /* Unresolved local var: server_t * p@[???] */
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: server_t * p@[???] */
  psVar2 = this->m_pServers;
  if (psVar2 == (server_t *)0x0) {
    return;
  }
  if (server != 0) {
    iVar1 = 0;
    do {
      psVar2 = psVar2->next;
      iVar1 = iVar1 + 1;
      if (psVar2 == (server_s *)0x0) {
        return;
      }
    } while (server != iVar1);
  }
  (*(gEngfuncs.pNetAPI)->InitNetworking)();
  iVar1 = context_id;
                    /* try { // try from 000a5f97 to 000b5f9b has its CatchHandler @ 000a6b25 */
  context_id = context_id + 1;
  (*(gEngfuncs.pNetAPI)->SendRequest)(iVar1,3,0,5.0,&psVar2->remote_address,::PlayersResponse);
  return;
}


// CHudServers::isQuerying  @ 000a5fd0  (line 996)

/* DWARF original prototype: int isQuerying(CHudServers * this) */

int __thiscall CHudServers::isQuerying(CHudServers *this)

{
  return (uint)(this->m_nRequesting != 0);
}


// CHudServers::GetServerCount  @ 000a5ff0  (line 1009)

/* DWARF original prototype: int GetServerCount(CHudServers * this) */

int __thiscall CHudServers::GetServerCount(CHudServers *this)

{
  return this->m_nServerCount;
}


// CHudServers::CHudServers  @ 000a6000  (line 1018)

/* DWARF original prototype: void CHudServers(CHudServers * this) */

void __thiscall CHudServers::CHudServers(CHudServers *this)

{
  this->m_nRequesting = 0;
  this->m_nDone = 0;
  this->m_dStarted = 0.0;
  this->m_pServerList = (request_t *)0x0;
  this->m_pServers = (server_t *)0x0;
  this->m_pActiveList = (request_t *)0x0;
  this->m_nQuerying = 0;
  this->m_nActiveQueries = 0;
  this->m_pPingRequest = (request_t *)0x0;
                    /* try { // try from 000a6050 to 000b6054 has its CatchHandler @ 000a6752 */
  this->m_fElapsed = 0.0;
  this->m_pRulesRequest = (request_t *)0x0;
  this->m_pPlayersRequest = (request_t *)0x0;
  return;
}


// CHudServers::~CHudServers  @ 000a6070  (line 1043)

/* WARNING: Control flow encountered bad instruction data */
/* DWARF original prototype: void ~CHudServers(CHudServers * this, int __in_chrg) */

void __thiscall CHudServers::~CHudServers(CHudServers *this,int __in_chrg)

{
  request_s *prVar1;
  server_s *psVar2;
  request_t *prVar3;
  server_t *psVar4;
  
  if (this != (CHudServers *)0xfffffbec) {
    prVar3 = this->m_pActiveList;
    while (prVar3 != (request_t *)0x0) {
      prVar1 = prVar3->next;
      operator_delete(prVar3);
      prVar3 = prVar1;
    }
    this->m_pActiveList = (request_t *)0x0;
  }
  if (this != (CHudServers *)0xfffffbf0) {
    prVar3 = this->m_pServerList;
    while (prVar3 != (request_t *)0x0) {
      prVar1 = prVar3->next;
      operator_delete(prVar3);
      prVar3 = prVar1;
    }
    this->m_pServerList = (request_t *)0x0;
  }
  if (this != (CHudServers *)0xfffffbe8) {
    psVar4 = this->m_pServers;
    while (psVar4 != (server_t *)0x0) {
      psVar2 = psVar4->next;
      if (psVar4->info != (char *)0x0) {
        operator_delete__(psVar4->info);
      }
      operator_delete(psVar4);
      psVar4 = psVar2;
    }
    this->m_pServers = (server_t *)0x0;
  }
  this->m_nServerCount = 0;
  if (this->m_pPingRequest != (request_t *)0x0) {
    operator_delete(this->m_pPingRequest);
    this->m_pPingRequest = (request_t *)0x0;
  }
  if (this->m_pRulesRequest != (request_t *)0x0) {
    operator_delete(this->m_pRulesRequest);
    this->m_pRulesRequest = (request_t *)0x0;
  }
  if (this->m_pPlayersRequest != (request_t *)0x0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ServersGetCount  @ 000a6180  (line 1085)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ServersGetCount(void)

{
  if (g_pServers != (CHudServers *)0x0) {
    return g_pServers->m_nServerCount;
  }
  return 0;
}


// ServersIsQuerying  @ 000a61a0  (line 1094)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ServersIsQuerying(void)

{
  if (g_pServers != (CHudServers *)0x0) {
    return (uint)(g_pServers->m_nRequesting != 0);
  }
  return 0;
}


// ServersGetInfo  @ 000a61d0  (line 1109)

char * ServersGetInfo(int server)

{
  server_t *psVar1;
  int iVar2;
  
  if ((g_pServers != (CHudServers *)0x0) &&
     (psVar1 = g_pServers->m_pServers, psVar1 != (server_t *)0x0)) {
    if (server != 0) {
      iVar2 = 0;
      do {
        psVar1 = psVar1->next;
        iVar2 = iVar2 + 1;
        if (psVar1 == (server_s *)0x0) {
          return (char *)0x0;
        }
      } while (server != iVar2);
    }
    return psVar1->info;
  }
  return (char *)0x0;
}


// SortServers  @ 000a6210  (line 1119)

void SortServers(char *fieldname)

{
  if (g_pServers != (CHudServers *)0x0) {
    CHudServers::SortServers(g_pServers,fieldname);
  }
  return;
}


// ServersShutdown  @ 000a6230  (line 1132)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ServersShutdown(void)

{
  CHudServers *pCVar1;
  int in_stack_ffffffe8;
  
  pCVar1 = g_pServers;
  if (g_pServers != (CHudServers *)0x0) {
    CHudServers::~CHudServers(g_pServers,in_stack_ffffffe8);
    operator_delete(pCVar1);
    g_pServers = (CHudServers *)0x0;
  }
  return;
}


// ServersInit  @ 000a6260  (line 1147)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ServersInit(void)

{
  CHudServers *pCVar1;
  int in_stack_ffffffe8;
  
  pCVar1 = g_pServers;
  if (g_pServers != (CHudServers *)0x0) {
    CHudServers::~CHudServers(g_pServers,in_stack_ffffffe8);
    operator_delete(pCVar1);
    g_pServers = (CHudServers *)0x0;
  }
  g_pServers = operator_new(0x43c);
  g_pServers->m_nRequesting = 0;
  *(undefined4 *)&g_pServers->m_dStarted = 0;
  *(undefined4 *)((int)&g_pServers->m_dStarted + 4) = 0;
  g_pServers->m_nDone = 0;
  g_pServers->m_pServerList = (request_t *)0x0;
  g_pServers->m_pServers = (server_t *)0x0;
  g_pServers->m_pActiveList = (request_t *)0x0;
  g_pServers->m_nQuerying = 0;
  g_pServers->m_nActiveQueries = 0;
  *(undefined4 *)&g_pServers->m_fElapsed = 0;
  *(undefined4 *)((int)&g_pServers->m_fElapsed + 4) = 0;
  g_pServers->m_pPingRequest = (request_t *)0x0;
  g_pServers->m_pRulesRequest = (request_t *)0x0;
  g_pServers->m_pPlayersRequest = (request_t *)0x0;
  return;
}


// ServersThink  @ 000a6310  (line 1161)

void ServersThink(double time)

{
  int *piVar1;
  CHudServers *pCVar2;
  int iVar3;
  request_t *prVar4;
  
  pCVar2 = g_pServers;
  if (((g_pServers != (CHudServers *)0x0) &&
      (piVar1 = &g_pServers->m_nRequesting, g_pServers->m_fElapsed = time + g_pServers->m_fElapsed,
      *piVar1 != 0)) && (pCVar2->m_nQuerying != 0)) {
                    /* Unresolved local var: request_t * p@[???] */
    if ((pCVar2->m_nDone == 0) && (pCVar2->m_nActiveQueries < 0x15)) {
      prVar4 = pCVar2->m_pServerList;
      if (prVar4 != (request_t *)0x0) {
        do {
          pCVar2->m_pServerList = prVar4->next;
          iVar3 = context_id;
          prVar4->context = context_id;
          context_id = context_id + 1;
          (*(gEngfuncs.pNetAPI)->SendRequest)(iVar3,4,0,2.0,&prVar4->remote_address,ServerResponse);
          pCVar2->m_nActiveQueries = pCVar2->m_nActiveQueries + 1;
          prVar4->next = pCVar2->m_pActiveList;
          pCVar2->m_pActiveList = prVar4;
          if (0x14 < pCVar2->m_nActiveQueries) {
            return;
          }
          prVar4 = pCVar2->m_pServerList;
        } while (prVar4 != (request_t *)0x0);
        return;
      }
      prVar4 = pCVar2->m_pActiveList;
    }
    else {
      prVar4 = pCVar2->m_pActiveList;
      if (pCVar2->m_pServerList != (request_t *)0x0) {
        return;
      }
    }
    if (prVar4 == (request_t *)0x0) {
      pCVar2->m_nDone = 0;
      pCVar2->m_nQuerying = 0;
      *(undefined4 *)&pCVar2->m_dStarted = 0;
      *(undefined4 *)((int)&pCVar2->m_dStarted + 4) = 0;
      pCVar2->m_nRequesting = 0;
      pCVar2->m_nActiveQueries = 0;
    }
  }
  return;
}


// ServersCancel  @ 000a6480  (line 1176)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ServersCancel(void)

{
  CHudServers *pCVar1;
  
  pCVar1 = g_pServers;
  if (g_pServers != (CHudServers *)0x0) {
    g_pServers->m_nRequesting = 0;
    pCVar1->m_nQuerying = 0;
                    /* try { // try from 000a649e to 000b64cb has its CatchHandler @ 000a45f0 */
    pCVar1->m_nDone = 1;
                    /* WARNING: Could not recover jumptable at 0x000a64a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(gEngfuncs.pNetAPI)->CancelAllRequests)();
    return;
  }
  return;
}


// ServersList  @ 000a64c0  (line 1191)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ServersList(void)

{
  if (g_pServers != (CHudServers *)0x0) {
    CHudServers::RequestList(g_pServers);
  }
  return;
}


// BroadcastServersList  @ 000a64e0  (line 1199)

void BroadcastServersList(int clearpending)

{
  if (g_pServers != (CHudServers *)0x0) {
    CHudServers::RequestBroadcastList(g_pServers,clearpending);
  }
  return;
}


// ServerPing  @ 000a6500  (line 1206)

void ServerPing(int server)

{
  int iVar1;
  server_t *psVar2;
  
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: int c@[???] */
  if ((g_pServers != (CHudServers *)0x0) &&
     (psVar2 = g_pServers->m_pServers, psVar2 != (server_t *)0x0)) {
    if (server != 0) {
      iVar1 = 0;
      do {
        psVar2 = psVar2->next;
        iVar1 = iVar1 + 1;
        if (psVar2 == (server_s *)0x0) {
          return;
        }
      } while (server != iVar1);
    }
    (*(gEngfuncs.pNetAPI)->InitNetworking)();
    iVar1 = context_id;
                    /* try { // try from 000a6563 to 000b6590 has its CatchHandler @ 000a45f0 */
    context_id = context_id + 1;
    (*(gEngfuncs.pNetAPI)->SendRequest)(iVar1,1,0,5.0,&psVar2->remote_address,PingResponse);
    return;
  }
  return;
}


// ServerRules  @ 000a65a0  (line 1214)

void ServerRules(int server)

{
  int iVar1;
  server_t *psVar2;
  
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: int c@[???] */
  if ((g_pServers != (CHudServers *)0x0) &&
     (psVar2 = g_pServers->m_pServers, psVar2 != (server_t *)0x0)) {
    if (server != 0) {
      iVar1 = 0;
      do {
        psVar2 = psVar2->next;
        iVar1 = iVar1 + 1;
        if (psVar2 == (server_s *)0x0) {
          return;
        }
      } while (server != iVar1);
    }
    (*(gEngfuncs.pNetAPI)->InitNetworking)();
    iVar1 = context_id;
    context_id = context_id + 1;
    (*(gEngfuncs.pNetAPI)->SendRequest)(iVar1,2,0,5.0,&psVar2->remote_address,RulesResponse);
    return;
  }
  return;
}


// ServerPlayers  @ 000a6640  (line 1222)

void ServerPlayers(int server)

{
  int iVar1;
  server_t *psVar2;
  
                    /* Unresolved local var: server_t * p@[???]
                       Unresolved local var: int c@[???] */
  if ((g_pServers != (CHudServers *)0x0) &&
     (psVar2 = g_pServers->m_pServers, psVar2 != (server_t *)0x0)) {
    if (server != 0) {
      iVar1 = 0;
      do {
        psVar2 = psVar2->next;
        iVar1 = iVar1 + 1;
        if (psVar2 == (server_s *)0x0) {
          return;
        }
      } while (server != iVar1);
    }
    (*(gEngfuncs.pNetAPI)->InitNetworking)();
    iVar1 = context_id;
    context_id = context_id + 1;
                    /* try { // try from 000a66c7 to 000b66cb has its CatchHandler @ 000a6737 */
    (*(gEngfuncs.pNetAPI)->SendRequest)(iVar1,3,0,5.0,&psVar2->remote_address,PlayersResponse);
    return;
  }
  return;
}


