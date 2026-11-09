// SV_ActivateServer  @ 000a7880
void SV_ActivateServer(int runPhysics)

{
  UserMsg *pUVar1;
  client_t *pcVar2;
  int iVar3;
  sizebuf_t *sb;
  _UserMsg *p_Var4;
  int iVar5;
  byte abStack_10130 [65536];
  char local_130 [256];
  sizebuf_t local_30;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  Q_memset(&local_30,0,0x14);
  local_30.data = abStack_10130;
  local_30.buffername = "Activate Server";
  local_30.cursize = 0;
  local_30.maxsize = 0x10000;
  SetCStrikeFlags();
  Cvar_Set("sv_newunit","0");
  ContinueLoadingProgressBar("Server",8,0.0);
  (*gEntityInterface.pfnServerActivate)(sv.edicts,sv.num_edicts,svs.maxclients);
  Steam_Activate();
  ContinueLoadingProgressBar("Server",9,0.0);
  SV_CreateGenericResources();
  sv.active = true;
  sv.state = ss_active;
  ContinueLoadingProgressBar("Server",10,0.0);
  if (runPhysics == 0) {
    host_frametime._0_4_ = 0xd2f1a9fc;
    host_frametime._4_4_ = 0x3f50624d;
    SV_Physics();
  }
  else {
    host_frametime._0_4_ = 0x9999999a;
    if (svs.maxclients < 2) {
      host_frametime._4_4_ = 0x3fb99999;
      SV_Physics();
      SV_Physics();
    }
    else {
      host_frametime._4_4_ = 0x3fe99999;
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
      SV_Physics();
    }
  }
  SV_CreateBaseline();
  SV_CreateResourceList();
  sv.num_consistency = SV_TransferConsistencyInfo();
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar5 = 0;
    iVar3 = svs.maxclients;
    do {
      while (((host_client->active == false && (host_client->connected == false)) ||
             (host_client->fakeclient != false))) {
        iVar5 = iVar5 + 1;
        host_client = host_client + 1;
        if (iVar3 <= iVar5) goto LAB_000a7bc0;
      }
      Netchan_Clear(&host_client->netchan);
      if (svs.maxclients < 2) {
        SV_SendServerinfo(&local_30,host_client);
      }
      else {
        sb = &(host_client->netchan).message;
        MSG_WriteByte(sb,9);
        MSG_WriteString(sb,"reconnect\n");
        Netchan_Transmit(&host_client->netchan,0,(byte *)0x0);
      }
      pUVar1 = sv_gpNewUserMsgs;
      if (sv_gpUserMsgs != (UserMsg *)0x0) {
                    /* Unresolved local var: UserMsg * pTemp@[???] */
        sv_gpNewUserMsgs = sv_gpUserMsgs;
        p_Var4 = sv_gpUserMsgs;
        do {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
          MSG_WriteByte(&local_30,0x27);
          MSG_WriteByte(&local_30,p_Var4->iMsg);
          MSG_WriteByte(&local_30,p_Var4->iSize);
          MSG_WriteLong(&local_30,*(int *)p_Var4->szName);
          MSG_WriteLong(&local_30,*(int *)(p_Var4->szName + 4));
          MSG_WriteLong(&local_30,*(int *)(p_Var4->szName + 8));
          MSG_WriteLong(&local_30,*(int *)(p_Var4->szName + 0xc));
          p_Var4 = p_Var4->next;
        } while (p_Var4 != (_UserMsg *)0x0);
      }
      pcVar2 = host_client;
      iVar5 = iVar5 + 1;
      sv_gpNewUserMsgs = pUVar1;
      host_client->hasusrmsgs = true;
      Netchan_CreateFragments(true,&pcVar2->netchan,&local_30);
      Netchan_FragSend(&host_client->netchan);
      SZ_Clear(&local_30);
      host_client = host_client + 1;
      iVar3 = svs.maxclients;
    } while (iVar5 < svs.maxclients);
  }
LAB_000a7bc0:
  HPAK_FlushHostQueue();
  if (svs.maxclients < 2) {
    Con_DPrintf("Game started\n");
  }
  else {
    Con_DPrintf("%i player server started\n",svs.maxclients);
  }
  Log_Printf("Started map \"%s\" (CRC \"%i\")\n",0x506a28,sv.worldmapCRC);
  if ((mapchangecfgfile.string != (char *)0x0) && (*mapchangecfgfile.string != '\0')) {
                    /* Unresolved local var: char[256] szCommand@[???] */
    AlertMessage(at_console,"Executing map change config file\n");
    snprintf(local_130,0x100,"exec %s\n",mapchangecfgfile.string);
    Cbuf_AddText(local_130);
  }
  return;
}


// SV_AddCorrectGravity  @ 000b25d0
void SV_AddCorrectGravity(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  fVar1 = (ent->v).gravity;
  fVar2 = 1.0;
  if (fVar1 != 0.0) {
    fVar2 = fVar1;
  }
  (ent->v).velocity[2] =
       (float)host_frametime * (ent->v).basevelocity[2] +
       ((ent->v).velocity[2] - fVar2 * sv_gravity.value * 0.5 * (float)host_frametime);
  (ent->v).basevelocity[2] = 0.0;
  SV_CheckVelocity(ent);
  return;
}


// SV_AddFailedRcon  @ 000a1a80
void SV_AddFailedRcon(netadr_t *adr)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  qboolean qVar6;
  int iVar7;
  char *pcVar8;
  rcon_failure_t *prVar9;
  int iVar10;
  float local_28;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: float best_update@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: qboolean found@[???]
                       Unresolved local var: rcon_failure_t * r@[???]
                       Unresolved local var: int failed@[???] */
  iVar5 = (int)sv_rcon_minfailures.value;
  sv_rcon_minfailures.value = (float)iVar5;
  sv_rcon_maxfailures.value = (float)(int)sv_rcon_maxfailures.value;
  sv_rcon_minfailuretime.value = (float)(int)sv_rcon_minfailuretime.value;
  if ((float)iVar5 < 1.0) {
    Cvar_SetValue("sv_rcon_minfailures",1.0);
  }
  if (20.0 < sv_rcon_minfailures.value) {
    Cvar_SetValue("sv_rcon_minfailures",20.0);
  }
  if (sv_rcon_maxfailures.value < 1.0) {
    Cvar_SetValue("sv_rcon_maxfailures",1.0);
  }
  if (20.0 < sv_rcon_maxfailures.value) {
    Cvar_SetValue("sv_rcon_maxfailures",20.0);
  }
  fVar3 = sv_rcon_maxfailures.value;
  if (sv_rcon_maxfailures.value < sv_rcon_minfailures.value) {
                    /* Unresolved local var: float temp@[???] */
    Cvar_SetValue("sv_rcon_maxfailures",sv_rcon_minfailures.value);
    Cvar_SetValue("sv_rcon_minfailures",fVar3);
  }
  if (sv_rcon_minfailuretime.value < 1.0) {
    Cvar_SetValue("sv_rcon_minfailuretime",1.0);
  }
  iVar5 = 0;
  iVar10 = 0;
  local_28 = -99999.0;
  while( true ) {
    prVar9 = g_rgRconFailures + iVar10;
    if (g_rgRconFailures[iVar10].active == false) {
      fVar3 = (float)realtime;
      goto LAB_000a1bfd;
    }
    qVar6 = NET_CompareAdr(g_rgRconFailures[iVar10].adr,*adr);
    if (qVar6 != false) break;
    fVar3 = (float)realtime;
    fVar2 = fVar3 - g_rgRconFailures[iVar10].last_update;
    if (local_28 < fVar2) {
      iVar5 = iVar10;
      local_28 = fVar2;
    }
    iVar10 = iVar10 + 1;
    if (iVar10 == 0x20) {
      prVar9 = g_rgRconFailures + iVar5;
LAB_000a1bfd:
      prVar9->active = true;
      iVar5 = 0;
      prVar9->shouldreject = false;
      prVar9->last_update = fVar3;
      fVar2 = 0.0;
      (prVar9->adr).type = adr->type;
      *(undefined4 *)(prVar9->adr).ip = *(undefined4 *)adr->ip;
      *(undefined4 *)(prVar9->adr).ipx = *(undefined4 *)adr->ipx;
      *(undefined4 *)((prVar9->adr).ipx + 4) = *(undefined4 *)(adr->ipx + 4);
      uVar1 = *(undefined4 *)(adr->ipx + 8);
      prVar9->num_failures = 0;
      *(undefined4 *)((prVar9->adr).ipx + 8) = uVar1;
LAB_000a1c3d:
      fVar4 = sv_rcon_maxfailures.value;
      if (sv_rcon_maxfailures.value <= fVar2) {
        iVar10 = 1;
        if (1.0 < sv_rcon_maxfailures.value) {
          do {
            prVar9->failure_times[iVar10 + -1] = prVar9->failure_times[iVar10];
            iVar10 = iVar10 + 1;
          } while ((float)iVar10 < fVar4);
        }
        iVar5 = iVar5 + -1;
      }
      prVar9->failure_times[iVar5] = fVar3;
      iVar5 = iVar5 + 1;
      prVar9->num_failures = iVar5;
      fVar2 = 0.0;
      if (0 < iVar5) {
        iVar10 = 0;
        iVar7 = 0;
        do {
          if (fVar3 - prVar9->failure_times[iVar7] < sv_rcon_minfailuretime.value) {
            iVar10 = iVar10 + 1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 != iVar5);
        fVar2 = (float)iVar10;
      }
      if (sv_rcon_minfailures.value <= fVar2) {
        pcVar8 = NET_AdrToString(*adr);
        Con_Printf("User %s will be banned for rcon hacking\n",pcVar8);
        prVar9->shouldreject = true;
      }
      return;
    }
  }
  if (g_rgRconFailures[iVar10].shouldreject != false) {
    return;
  }
  fVar3 = (float)realtime;
  prVar9->active = true;
  g_rgRconFailures[iVar10].shouldreject = false;
  iVar5 = g_rgRconFailures[iVar10].num_failures;
  g_rgRconFailures[iVar10].last_update = fVar3;
  g_rgRconFailures[iVar10].adr.type = adr->type;
  *(undefined4 *)g_rgRconFailures[iVar10].adr.ip = *(undefined4 *)adr->ip;
  *(undefined4 *)g_rgRconFailures[iVar10].adr.ipx = *(undefined4 *)adr->ipx;
  *(undefined4 *)(g_rgRconFailures[iVar10].adr.ipx + 4) = *(undefined4 *)(adr->ipx + 4);
  *(undefined4 *)(g_rgRconFailures[iVar10].adr.ipx + 8) = *(undefined4 *)(adr->ipx + 8);
  fVar2 = (float)iVar5;
  goto LAB_000a1c3d;
}


// SV_AddGravity  @ 000b2560
void SV_AddGravity(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  fVar1 = (ent->v).gravity;
  fVar2 = 1.0;
  if (fVar1 != 0.0) {
    fVar2 = fVar1;
  }
  (ent->v).velocity[2] =
       (float)host_frametime * (ent->v).basevelocity[2] +
       ((ent->v).velocity[2] - fVar2 * sv_gravity.value * (float)host_frametime);
  (ent->v).basevelocity[2] = 0.0;
  SV_CheckVelocity(ent);
  return;
}


// SV_AddIP_f  @ 000a8ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_AddIP_f(void)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  ipfilter_t *piVar5;
  int iVar6;
  float fVar7;
  ipfilter_t local_1c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???]
                       Unresolved local var: ipfilter_t tempFilter@[???] */
  iVar2 = Cmd_Argc();
  if (iVar2 == 3) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???]
                       Unresolved local var: ipfilter_t tempFilter@[???] */
    pcVar3 = Cmd_Argv(1);
    fVar7 = Q_atof(pcVar3);
    pcVar3 = Cmd_Argv(2);
    qVar4 = StringToFilter(pcVar3,&local_1c);
    if (qVar4 == false) {
      Con_Printf(
                "Invalid IP address!\nUsage: addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n"
                );
    }
    else {
      if (numipfilters < 1) {
        iVar2 = 0;
      }
      else {
        piVar5 = ipfilters;
        iVar2 = 0;
        do {
          if ((piVar5->mask == local_1c.mask) && (piVar5->compare == local_1c.compare)) {
            ipfilters[iVar2].banTime = fVar7;
            fVar1 = 0.0;
            if (fVar7 != 0.0) {
              fVar1 = fVar7 * 60.0 + (float)realtime;
            }
            ipfilters[iVar2].banEndTime = fVar1;
            return;
          }
          iVar2 = iVar2 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar2 != numipfilters);
        if (0x7fff < iVar2) {
          Con_Printf("IP filter list is full\n");
          return;
        }
      }
      numipfilters = numipfilters + 1;
      if (0.01 <= fVar7) {
        ipfilters[iVar2].banTime = fVar7;
        fVar1 = 0.0;
        if (fVar7 != 0.0) {
          fVar1 = fVar7 * 60.0 + (float)realtime;
        }
      }
      else {
        ipfilters[iVar2].banTime = 0.0;
        fVar1 = 0.0;
      }
      host_client = svs.clients;
      ipfilters[iVar2].banEndTime = fVar1;
      ipfilters[iVar2].compare = local_1c.compare;
      ipfilters[iVar2].mask = local_1c.mask;
      if (0 < svs.maxclients) {
        iVar6 = 0;
        iVar2 = svs.maxclients;
        do {
          if ((((host_client->connected != false) && (host_client->active != false)) &&
              (host_client->spawned != false)) && (host_client->fakeclient == false)) {
            net_from.type = (host_client->netchan).remote_address.type;
            net_from.ip = *&(host_client->netchan).remote_address.ip;
            net_from.ipx._0_4_ = *(undefined4 *)(host_client->netchan).remote_address.ipx;
            net_from.ipx._4_4_ = *(undefined4 *)((host_client->netchan).remote_address.ipx + 4);
            net_from._16_4_ = *(undefined4 *)((host_client->netchan).remote_address.ipx + 8);
            qVar4 = SV_FilterPacket();
            iVar2 = svs.maxclients;
            if (qVar4 != false) {
              SV_ClientPrintf("The server operator has added you to banned list\n");
              SV_DropClient(host_client,false,"Added to banned list");
              iVar2 = svs.maxclients;
            }
          }
          iVar6 = iVar6 + 1;
          host_client = host_client + 1;
        } while (iVar6 < iVar2);
      }
    }
  }
  else {
    Con_Printf("Usage: addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n");
  }
  return;
}


// SV_AddLinksToPM  @ 000b9350
void SV_AddLinksToPM(areanode_t *node,vec_t *origin)

{
  undefined4 uVar1;
  vec_t vVar2;
  model_s *src;
  playermove_t *ppVar3;
  uint uVar4;
  bool bVar5;
  float local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t pmove_mins@[???]
                       Unresolved local var: vec3_t pmove_maxs@[???] */
  Q_memset(pmove->physents,0,0xe0);
  Q_memset(pmove->visents,0,0xe0);
  src = sv.worldmodel;
  ppVar3 = pmove;
  bVar5 = sv.worldmodel != (model_s *)0x0;
  pmove->physents[0].model = sv.worldmodel;
  if (bVar5) {
    Q_strncpy(ppVar3->physents[0].name,src->name,0x20);
    ppVar3 = pmove;
    pmove->physents[0].name[0x1f] = '\0';
  }
  vVar2 = vec3_origin[0];
  ppVar3->physents[0].info = 0;
  ppVar3->physents[0].solid = 4;
  ppVar3->physents[0].origin[0] = vVar2;
  vVar2 = vec3_origin[1];
  ppVar3->physents[0].takedamage = 1;
  ppVar3->physents[0].blooddecal = 0;
  ppVar3->numphysent = 1;
  ppVar3->physents[0].origin[1] = vVar2;
  vVar2 = vec3_origin[2];
  ppVar3->numvisent = 1;
  ppVar3->physents[0].origin[2] = vVar2;
  ppVar3->physents[0].movetype = 0;
  uVar4 = 0;
  do {
    uVar1 = *(undefined4 *)(ppVar3->physents[0].name + uVar4 + 4);
    *(undefined4 *)(ppVar3->visents[0].name + uVar4) =
         *(undefined4 *)(ppVar3->physents[0].name + uVar4);
    *(undefined4 *)(ppVar3->visents[0].name + uVar4 + 4) = uVar1;
    uVar4 = uVar4 + 8;
  } while (uVar4 < 0xe0);
  ppVar3->nummoveent = 0;
  local_3c = *origin - 256.0;
  local_2c = *origin + 256.0;
  local_38 = origin[1] - 256.0;
  local_28 = origin[1] + 256.0;
  local_34 = origin[2] - 256.0;
  local_24 = origin[2] + 256.0;
  SV_AddLinksToPM_(node,&local_3c,&local_2c);
  return;
}


// SV_AddLinksToPM_  @ 000b8eb0
void SV_AddLinksToPM_(areanode_t *node,float *pmove_mins,float *pmove_maxs)

{
  edict_t *e;
  link_s *plVar1;
  link_s *plVar2;
  int iVar3;
  undefined4 uVar4;
  link_s *plVar5;
  playermove_t *ppVar6;
  int iVar7;
  uint uVar8;
  link_s **pplVar9;
  physent_t *ppVar10;
  float fVar11;
  link_s *local_40;
  
  do {
    plVar2 = (node->solid_edicts).next;
joined_r0x000b8edd:
    while (plVar5 = plVar2, plVar5 != &node->solid_edicts) {
      plVar1 = plVar5[0x57].prev;
      plVar2 = plVar5->next;
      if (plVar1 == (link_s *)0x0) goto LAB_000b8f30;
      if (g_groupop == 0) goto code_r0x000b8f11;
      if ((g_groupop != 1) || (((sv_player->v).groupinfo & (uint)plVar1) == 0)) goto LAB_000b8f30;
    }
    iVar3 = node->axis;
    if (iVar3 == -1) {
      return;
    }
    iVar7 = iVar3 * 4;
    fVar11 = node->dist;
    if (fVar11 < pmove_maxs[iVar3]) {
      SV_AddLinksToPM_(node->children[0],pmove_mins,pmove_maxs);
      iVar7 = node->axis << 2;
      fVar11 = node->dist;
    }
    if (fVar11 <= *(float *)((int)pmove_mins + iVar7)) {
      return;
    }
    node = node->children[1];
  } while( true );
code_r0x000b8f11:
  if (((sv_player->v).groupinfo & (uint)plVar1) != 0) {
LAB_000b8f30:
    if (((edict_t_conflict *)plVar5[0x42].prev != sv_player) &&
       ((((plVar1 = plVar5[0x30].next, plVar1 == (link_s *)0x2 || (plVar1 == (link_s *)0x4)) ||
         (plVar1 == (link_s *)0x3)) || (plVar1 == (link_s *)0x0)))) {
      e = (edict_t *)(plVar5 + -1);
      iVar7 = NUM_FOR_EDICT(e);
      ppVar6 = pmove;
      iVar3 = pmove->numvisent;
      pmove->numvisent = iVar3 + 1;
      SV_CopyEdictToPhysent(ppVar6->visents + iVar3,iVar7,(edict_t_conflict *)e);
      if (((plVar5[0x30].next != (link_s *)0x0) ||
          ((plVar5[0x31].prev != (link_s *)0x0 && (plVar5[0x25].next != (link_s *)0x0)))) &&
         (((((((uint)plVar5[0x43].next & 0x800000) == 0 || (plVar5[0x30].next != (link_s *)0x4)) &&
            (e != (edict_t *)sv_player)) &&
           (((((uint)plVar5[0x43].next & 8) == 0 || (0.0 < (float)plVar5[0x3b].prev)) &&
            (((float)plVar5[0x2b].next != 0.0 || ((float)plVar5[0x2d].prev != 1.0)))))) &&
          (fVar11 = Length((vec_t *)&plVar5[0x2d].next), fVar11 != 0.0)))) {
        local_40 = plVar5 + 0x29;
        pplVar9 = &plVar5[0x27].next;
        if (((((((uint)plVar5[0x43].next & 8) != 0) && (host_client->lw != 0)) &&
             (host_client->lc != 0)) &&
            (((sv_unlag.value != 0.0 && (1 < svs.maxclients)) &&
             ((host_client->active != false &&
              ((iVar7 = iVar7 + -1, -1 < iVar7 && (iVar7 < svs.maxclients)))))))) &&
           ((truepositions[iVar7].active != 0 && (truepositions[iVar7].needrelink != 0)))) {
          pplVar9 = (link_s **)truepositions[iVar7].oldabsmin;
          local_40 = (link_s *)truepositions[iVar7].oldabsmax;
        }
        if (((((float)*pplVar9 <= *pmove_maxs) && (*pmove_mins <= (float)local_40->prev)) &&
            ((float)pplVar9[1] <= pmove_maxs[1])) &&
           (((pmove_mins[1] <= (float)local_40->next && ((float)pplVar9[2] <= pmove_maxs[2])) &&
            (pmove_mins[2] <= (float)local_40[1].prev)))) {
          if ((plVar5[0x30].next == (link_s *)0x0) && (plVar5[0x31].prev == (link_s *)0xfffffff0)) {
            iVar7 = pmove->nummoveent;
            if (0x3f < iVar7) {
              Con_DPrintf("SV_AddLinksToPM:  pmove->nummoveent >= MAX_MOVEENTS\n");
              goto joined_r0x000b8edd;
            }
            ppVar10 = pmove->moveents + iVar7;
            pmove->nummoveent = iVar7 + 1;
          }
          else {
            iVar7 = pmove->numphysent;
            if (599 < iVar7) {
              Con_DPrintf("SV_AddLinksToPM:  pmove->numphysent >= MAX_PHYSENTS\n");
              return;
            }
            ppVar10 = pmove->physents + iVar7;
            pmove->numphysent = iVar7 + 1;
          }
          uVar8 = 0;
          do {
            uVar4 = *(undefined4 *)(ppVar6->visents[iVar3].name + uVar8 + 4);
            *(undefined4 *)(ppVar10->name + uVar8) =
                 *(undefined4 *)(ppVar6->visents[iVar3].name + uVar8);
            *(undefined4 *)(ppVar10->name + uVar8 + 4) = uVar4;
            uVar8 = uVar8 + 8;
          } while (uVar8 < 0xe0);
        }
      }
    }
  }
  goto joined_r0x000b8edd;
}


// SV_AddLogAddress_f  @ 0009b3a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_AddLogAddress_f(void)

{
  netadr_t a;
  int iVar1;
  char *pcVar2;
  char *str;
  qboolean qVar3;
  loglist *plVar4;
  LOGLIST_T *pLVar5;
  uchar *puVar6;
  uchar *puVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  char local_140 [260];
  netadr_t local_3c [2];
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nPort@[???]
                       Unresolved local var: char[260] szAdr@[???]
                       Unresolved local var: netadr_t adr@[???] */
  bVar11 = 0;
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    str = Cmd_Argv(2);
    iVar1 = Q_atoi(str);
    if (iVar1 == 0) {
      Con_Printf("logaddress_add:  must specify a valid port\n");
    }
    else {
      if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
        Con_Printf("logaddress_add:  unparseable address\n");
        return;
      }
      snprintf(local_140,0x104,"%s:%i",pcVar2,iVar1);
      qVar3 = NET_StringToAdr(local_140,local_3c);
      if (qVar3 == false) {
        Con_Printf("logaddress_add:  unable to resolve %s\n",local_140);
      }
      else {
        bVar8 = false;
        if (firstLog == (LOGLIST_T *)0x0) {
          plVar4 = malloc(0x24);
          firstLog = plVar4;
          if (plVar4 == (loglist *)0x0) {
LAB_0009b60c:
            Con_Printf("logaddress_add:  error allocating new node\n");
          }
          else {
LAB_0009b540:
            (plVar4->log).net_address.type = local_3c[0].type;
            *&(plVar4->log).net_address.ip = local_3c[0].ip;
            *(undefined4 *)(plVar4->log).net_address.ipx = local_3c[0].ipx._0_4_;
            *(undefined4 *)((plVar4->log).net_address.ipx + 4) = local_3c[0].ipx._4_4_;
            plVar4->next = (loglist *)0x0;
            *(undefined4 *)((plVar4->log).net_address.ipx + 8) = local_3c[0]._16_4_;
            a.ip[0] = local_3c[0].ip[0];
            a.ip[1] = local_3c[0].ip[1];
            a.ip[2] = local_3c[0].ip[2];
            a.ip[3] = local_3c[0].ip[3];
            a.type = local_3c[0].type;
            a.ipx[0] = local_3c[0].ipx[0];
            a.ipx[1] = local_3c[0].ipx[1];
            a.ipx[2] = local_3c[0].ipx[2];
            a.ipx[3] = local_3c[0].ipx[3];
            a.ipx[4] = local_3c[0].ipx[4];
            a.ipx[5] = local_3c[0].ipx[5];
            a.ipx[6] = local_3c[0].ipx[6];
            a.ipx[7] = local_3c[0].ipx[7];
            a.ipx[8] = local_3c[0].ipx[8];
            a.ipx[9] = local_3c[0].ipx[9];
            a.port = local_3c[0].port;
            pcVar2 = NET_AdrToString(a);
            Con_Printf("logaddress_add:  %s\n",pcVar2);
          }
        }
        else {
                    /* Unresolved local var: LOGLIST_T * list@[???]
                       Unresolved local var: char found@[???] */
          iVar1 = 4;
          bVar9 = false;
          puVar6 = (firstLog->log).net_address.ip;
          puVar7 = local_3c[0].ip;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar8 = *puVar6 < *puVar7;
            bVar9 = *puVar6 == *puVar7;
            puVar6 = puVar6 + (uint)bVar11 * -2 + 1;
            puVar7 = puVar7 + (uint)bVar11 * -2 + 1;
          } while (bVar9);
          bVar10 = false;
          plVar4 = firstLog;
          if ((!bVar8 && !bVar9) == bVar8) {
            bVar10 = local_3c[0].port == (firstLog->log).net_address.port;
          }
          do {
            pLVar5 = plVar4;
            plVar4 = pLVar5->next;
            if (plVar4 == (loglist *)0x0) {
              if (!bVar10) {
                    /* Unresolved local var: LOGLIST_T * tmp@[???] */
                plVar4 = malloc(0x24);
                if (plVar4 == (loglist *)0x0) goto LAB_0009b60c;
                pLVar5->next = plVar4;
                goto LAB_0009b540;
              }
              break;
            }
            iVar1 = 4;
            bVar8 = false;
            puVar6 = (pLVar5->log).net_address.ip;
            puVar7 = local_3c[0].ip;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar8 = *puVar6 == *puVar7;
              puVar6 = puVar6 + (uint)bVar11 * -2 + 1;
              puVar7 = puVar7 + (uint)bVar11 * -2 + 1;
            } while (bVar8);
          } while ((!bVar8) || (local_3c[0].port != (pLVar5->log).net_address.port));
          Con_Printf("logaddress_add:  address already in list\n");
        }
      }
    }
  }
  else {
    Con_Printf("logaddress_add:  usage\nlogaddress_add ip port\n");
    for (plVar4 = firstLog; plVar4 != (LOGLIST_T *)0x0; plVar4 = plVar4->next) {
                    /* Unresolved local var: LOGLIST_T * list@[???] */
      pcVar2 = NET_AdrToString((plVar4->log).net_address);
      Con_Printf("current:  %s\n",pcVar2);
    }
  }
  return;
}


// SV_AddResource  @ 000a65c0
void SV_AddResource(resourcetype_t type,char *name,int size,uchar flags,int index)

{
  resource_t *dest;
  int iVar1;
  
                    /* Unresolved local var: resource_t * r@[???] */
  iVar1 = sv.num_resources;
  dest = sv.resourcelist + sv.num_resources;
  if (0x4ff < sv.num_resources) {
    Sys_Error("Too many resources on server.");
  }
  sv.num_resources = sv.num_resources + 1;
  sv.resourcelist[iVar1].type = type;
  Q_strncpy(dest->szFileName,name,0x3f);
  sv.resourcelist[iVar1].ucFlags = flags;
  sv.resourcelist[iVar1].szFileName[0x3f] = '\0';
  sv.resourcelist[iVar1].nDownloadSize = size;
  sv.resourcelist[iVar1].nIndex = index;
  return;
}


// SV_AddSampleToHashedLookupTable  @ 0009d1e0
void SV_AddSampleToHashedLookupTable(char *pszSample,int iSampleIndex)

{
  __int32_t **pp_Var1;
  char cVar2;
  uint uVar4;
  uint uVar5;
  int iVar3;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???] */
                    /* Unresolved local var: uint hash@[???] */
  uVar4 = 0;
  cVar2 = *pszSample;
  uVar5 = uVar4;
  if (cVar2 != '\0') {
    pp_Var1 = __ctype_tolower_loc();
    uVar4 = 0;
    do {
                    /* Unresolved local var: int __res@[???] */
      iVar3 = (int)cVar2;
      pszSample = pszSample + 1;
      cVar2 = *pszSample;
      uVar4 = uVar4 * 2 + (*pp_Var1)[iVar3];
    } while (cVar2 != '\0');
    uVar4 = uVar4 % 0x3ff;
    uVar5 = uVar4;
  }
  while (sv.sound_precache_hashedlookup[uVar4] != 0) {
    uVar4 = uVar4 + 1;
    hashstrings_collisions = hashstrings_collisions + 1;
    if (0x3fe < (int)uVar4) {
      uVar4 = 0;
    }
    if (uVar4 == uVar5) {
      Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
    }
  }
  sv.sound_precache_hashedlookup[uVar4] = (short)iSampleIndex;
  return;
}


// SV_AddToFatPAS  @ 000a4090
void SV_AddToFatPAS(vec_t *org,mnode_t *node)

{
  uint *puVar1;
  mplane_t *pmVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uchar *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  for (; iVar7 = node->contents, -1 < iVar7; node = node->children[1]) {
    while( true ) {
      pmVar2 = node->plane;
      fVar3 = (org[2] * pmVar2->normal[2] + org[1] * pmVar2->normal[1] + *org * pmVar2->normal[0]) -
              pmVar2->dist;
      if (fVar3 <= 8.0) break;
      node = node->children[0];
      iVar7 = node->contents;
      if (iVar7 < 0) goto LAB_000a40dd;
    }
    if (-8.0 <= fVar3) {
      SV_AddToFatPAS(org,node->children[0]);
    }
  }
LAB_000a40dd:
                    /* Unresolved local var: int leafnum@[???] */
  if ((iVar7 != -2) &&
     (puVar8 = CM_LeafPAS(((int)node - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555),
     iVar7 = fatpasbytes, 0 < fatpasbytes)) {
    uVar12 = (uint)fatpasbytes >> 4;
    iVar11 = uVar12 << 4;
    if ((uVar12 == 0) ||
       ((uint)fatpasbytes < 0x10 || localmodels[0x1ff] + 4 < puVar8 + 0x10 && puVar8 < fatpas + 0x11
       )) {
      iVar11 = 0;
    }
    else {
      iVar10 = 0;
      uVar9 = 0;
      do {
        uVar9 = uVar9 + 1;
        puVar1 = (uint *)(puVar8 + iVar10);
        uVar4 = puVar1[1];
        uVar5 = puVar1[2];
        uVar6 = puVar1[3];
        *(uint *)(fatpas + iVar10) = *puVar1 | *(uint *)(fatpas + iVar10);
        *(uint *)(fatpas + iVar10 + 4) = uVar4 | *(uint *)(fatpas + iVar10 + 4);
        *(uint *)(fatpas + iVar10 + 8) = uVar5 | *(uint *)(fatpas + iVar10 + 8);
        *(uint *)(fatpas + iVar10 + 0xc) = uVar6 | *(uint *)(fatpas + iVar10 + 0xc);
        iVar10 = iVar10 + 0x10;
      } while (uVar9 < uVar12);
      if (iVar7 == iVar11) {
        return;
      }
    }
    do {
      fatpas[iVar11] = fatpas[iVar11] | puVar8[iVar11];
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar7);
  }
  return;
}


// SV_AddToFatPVS  @ 000a3f00
void SV_AddToFatPVS(vec_t *org,mnode_t *node)

{
  uint *puVar1;
  float *pfVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  mleaf_s *pmVar8;
  uchar *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  for (; pmVar8 = (mleaf_s *)((mleaf_t *)node)->contents, -1 < (int)pmVar8;
      node = (mnode_t *)((mleaf_t *)node)->firstmarksurface) {
    while( true ) {
      pfVar2 = (float *)((mleaf_t *)node)->compressed_vis;
      fVar3 = (org[2] * pfVar2[2] + org[1] * pfVar2[1] + *org * *pfVar2) - pfVar2[3];
      if (fVar3 <= 8.0) break;
      node = (mnode_t *)((mleaf_t *)node)->efrags;
      pmVar8 = (mleaf_s *)((mleaf_t *)node)->contents;
      if ((int)pmVar8 < 0) goto LAB_000a3f4d;
    }
    if (-8.0 <= fVar3) {
      SV_AddToFatPVS(org,(mnode_t *)((mleaf_t *)node)->efrags);
    }
  }
LAB_000a3f4d:
  if ((pmVar8 != (mleaf_s *)0xfffffffe) &&
     (puVar9 = Mod_LeafPVS((mleaf_t *)node,sv.worldmodel), iVar7 = fatbytes, 0 < fatbytes)) {
    uVar13 = (uint)fatbytes >> 4;
    iVar12 = uVar13 << 4;
    if ((uVar13 == 0) ||
       ((uint)fatbytes < 0x10 || (uchar *)0x4864ff < puVar9 + 0x10 && puVar9 < fatpvs + 0x11)) {
      iVar12 = 0;
    }
    else {
      iVar11 = 0;
      uVar10 = 0;
      do {
        uVar10 = uVar10 + 1;
        puVar1 = (uint *)(puVar9 + iVar11);
        uVar4 = puVar1[1];
        uVar5 = puVar1[2];
        uVar6 = puVar1[3];
        *(uint *)(fatpvs + iVar11) = *puVar1 | *(uint *)(fatpvs + iVar11);
        *(uint *)(fatpvs + iVar11 + 4) = uVar4 | *(uint *)(fatpvs + iVar11 + 4);
        *(uint *)(fatpvs + iVar11 + 8) = uVar5 | *(uint *)(fatpvs + iVar11 + 8);
        *(uint *)(fatpvs + iVar11 + 0xc) = uVar6 | *(uint *)(fatpvs + iVar11 + 0xc);
        iVar11 = iVar11 + 0x10;
      } while (uVar10 < uVar13);
      if (iVar7 == iVar12) {
        return;
      }
    }
    do {
      fatpvs[iVar12] = fatpvs[iVar12] | puVar9[iVar12];
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar7);
  }
  return;
}


// SV_AddToResourceList  @ 000b7000
void SV_AddToResourceList(resource_t *pResource,resource_t *pList)

{
  if ((pResource->pPrev == (resource_s *)0x0) && (pResource->pNext == (resource_s *)0x0)) {
    pResource->pPrev = pList->pPrev;
    pList->pPrev->pNext = pResource;
    pList->pPrev = pResource;
    pResource->pNext = pList;
    return;
  }
  Con_Printf("Resource already linked\n");
  return;
}


// SV_AllocClientFrames  @ 0009c760
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_AllocClientFrames(void)

{
  client_frame_t *pcVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclientslimit) {
    iVar3 = 0;
    pcVar2 = svs.clients;
    do {
      if (pcVar2->frames != (client_frame_t *)0x0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar3 = iVar3 + 1;
      pcVar1 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1810);
      pcVar2->frames = pcVar1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 < svs.maxclientslimit);
  }
  return;
}


// SV_AllocPacketEntities  @ 0009c830
void SV_AllocPacketEntities(client_frame_t *frame,int numents)

{
  int iVar1;
  entity_state_s *peVar2;
  
                    /* Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: int allocatedslots@[???] */
  if (frame != (client_frame_t *)0x0) {
    peVar2 = (frame->entities).entities;
    if (peVar2 != (entity_state_s *)0x0) {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
      Mem_Free(peVar2);
      (frame->entities).entities = (entity_state_s *)0x0;
      (frame->entities).num_entities = 0;
    }
    iVar1 = 1;
    if (0 < numents) {
      iVar1 = numents;
    }
    peVar2 = Mem_ZeroMalloc(iVar1 * 0x154);
    (frame->entities).num_entities = numents;
    (frame->entities).entities = peVar2;
  }
  return;
}


// SV_BanId_f  @ 000ac2e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_BanId_f(void)

{
  float fVar1;
  client_t *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  USERID_t *id;
  int iVar7;
  client_s *pcVar8;
  int iVar9;
  bool bVar10;
  float fVar11;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  char local_dc;
  char local_db [62];
  undefined1 local_9d;
  char local_9c [63];
  undefined1 local_5d;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???]
                       Unresolved local var: USERID_t * id@[???]
                       Unresolved local var: char * pszCmdGiver@[???]
                       Unresolved local var: char[256] szreason@[???]
                       Unresolved local var: char[64] idstring@[???]
                       Unresolved local var: qboolean bKick@[???] */
  pcVar3 = Cmd_Argv(1);
  fVar11 = Q_atof(pcVar3);
  if (fVar11 < 0.01) {
    fVar11 = 0.0;
  }
  pcVar3 = Cmd_Argv(2);
  strncpy(&local_dc,pcVar3,0x3f);
  local_9d = 0;
  iVar4 = Cmd_Argc();
  bVar10 = false;
  if (3 < iVar4) {
    iVar4 = Cmd_Argc();
    pcVar3 = Cmd_Argv(iVar4 + -1);
    iVar4 = Q_strcasecmp(pcVar3,"kick");
    bVar10 = iVar4 == 0;
  }
  if (local_dc == '#') {
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int search@[???] */
    iVar4 = Q_strlen(&local_dc);
    if (iVar4 == 1) {
      iVar4 = Cmd_Argc();
      if (iVar4 < 3) {
        Con_Printf("Insufficient arguments to banid\n");
        return;
      }
      pcVar3 = Cmd_Argv(3);
      iVar4 = Q_atoi(pcVar3);
    }
    else {
      iVar4 = Q_atoi(local_db);
    }
    if (0 < svs.maxclients) {
      iVar9 = 0;
      pcVar8 = svs.clients;
      do {
        if ((((pcVar8->active != false) || (pcVar8->connected != false)) ||
            (pcVar8->spawned != false)) &&
           ((pcVar8->fakeclient == false && (pcVar8->userid == iVar4)))) {
          id = &pcVar8->network_userid;
          if (id != (USERID_t *)0x0) goto LAB_000ac4f8;
          break;
        }
        iVar9 = iVar9 + 1;
        pcVar8 = pcVar8 + 1;
      } while (iVar9 != svs.maxclients);
    }
    Con_Printf("SV_BanId_f:  Couldn\'t find #userid %u\n",iVar4);
    pcVar2 = host_client;
  }
  else {
                    /* Unresolved local var: client_t * cl@[???] */
    iVar4 = Q_strnicmp(&local_dc,"STEAM_",6);
    if ((iVar4 == 0) || (iVar4 = Q_strnicmp(&local_dc,"VALVE_",6), iVar4 == 0)) {
      pcVar3 = Cmd_Argv(6);
      pcVar5 = Cmd_Argv(4);
      pcVar6 = Cmd_Argv(2);
      snprintf(&local_dc,0x3f,"%s:%s:%s",pcVar6,pcVar5,pcVar3);
      local_9d = 0;
    }
    if (0 < svs.maxclients) {
      iVar9 = 0;
      iVar4 = svs.maxclients;
      pcVar8 = svs.clients;
      do {
        while ((((pcVar8->active == false && (pcVar8->connected == false)) &&
                (pcVar8->spawned == false)) || (pcVar8->fakeclient != false))) {
          iVar9 = iVar9 + 1;
          pcVar8 = pcVar8 + 1;
          if (iVar4 <= iVar9) goto LAB_000ac4b0;
        }
        SV_GetClientIDString::idstr[0] = '\0';
        if (((pcVar8->netchan).remote_address.type == NA_LOOPBACK) &&
           ((pcVar8->network_userid).idtype == 2)) {
          snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
        }
        else {
                    /* Unresolved local var: USERID_t * id@[???] */
          pcVar3 = SV_GetIDString(&pcVar8->network_userid);
          snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar3);
        }
        iVar4 = Q_stricmp(SV_GetClientIDString::idstr,&local_dc);
        if (iVar4 == 0) {
          id = &pcVar8->network_userid;
          if (id != (USERID_t *)0x0) goto LAB_000ac4f8;
          break;
        }
        iVar9 = iVar9 + 1;
        pcVar8 = pcVar8 + 1;
        iVar4 = svs.maxclients;
      } while (iVar9 < svs.maxclients);
    }
LAB_000ac4b0:
    id = SV_StringToUserID(&local_dc);
    if (id == (USERID_t *)0x0) {
      Con_Printf("SV_BanId_f:  Couldn\'t resolve uniqueid %s.\n",&local_dc);
      Con_Printf("Usage:  banid <minutes> <uniqueid or #userid> { kick }\n");
      Con_Printf("Use 0 minutes for permanent\n");
      pcVar2 = host_client;
    }
    else {
LAB_000ac4f8:
      iVar9 = 0;
      iVar4 = numuserfilters;
      if (0 < numuserfilters) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
        do {
          iVar7 = userfilters[iVar9].userid.idtype;
          if ((iVar7 == id->idtype) && (iVar7 - 1U < 2)) {
            pcVar3 = SV_GetIDString(&userfilters[iVar9].userid);
            strncpy(local_9c,pcVar3,0x3f);
            local_5d = 0;
            pcVar3 = SV_GetIDString(id);
            strncpy(local_5c,pcVar3,0x3f);
            local_1d = 0;
            iVar7 = strcasecmp(local_9c,local_5c);
            iVar4 = numuserfilters;
            if (iVar7 == 0) {
              if (iVar9 < numuserfilters) goto LAB_000ac5b3;
              break;
            }
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar4);
      }
      if (iVar4 < 0x8000) {
        numuserfilters = iVar4 + 1;
LAB_000ac5b3:
        userfilters[iVar9].banTime = fVar11;
        fVar1 = 0.0;
        if (fVar11 != 0.0) {
          fVar1 = (float)realtime + fVar11 * 60.0;
        }
        userfilters[iVar9].banEndTime = fVar1;
        userfilters[iVar9].userid.idtype = id->idtype;
        *(int *)&userfilters[iVar9].userid.m_SteamID = (int)id->m_SteamID;
        *(undefined4 *)((int)&userfilters[iVar9].userid.m_SteamID + 4) =
             *(undefined4 *)((int)&id->m_SteamID + 4);
        userfilters[iVar9].userid.clientip = id->clientip;
        if (fVar11 == 0.0) {
          local_1dc = 0x6d726570;
          local_1d8 = 0x6e656e61;
          local_1d4 = 0x796c74;
        }
        else {
          snprintf((char *)&local_1dc,0x100,"for %.2f minutes",(double)fVar11);
        }
        pcVar2 = host_client;
        pcVar3 = "Console";
        if (cmd_source != src_command) {
          pcVar3 = host_client->name;
        }
        if (bVar10) {
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: client_t * save@[???] */
          if (0 < svs.maxclients) {
            iVar9 = 0;
            iVar4 = svs.maxclients;
            pcVar8 = svs.clients;
            do {
              if ((((pcVar8->active != false) || (pcVar8->connected != false)) ||
                  (pcVar8->spawned != false)) &&
                 (((pcVar8->fakeclient == false &&
                   (iVar7 = (pcVar8->network_userid).idtype, iVar7 == id->idtype)) &&
                  (iVar7 - 1U < 2)))) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
                pcVar5 = SV_GetIDString(&pcVar8->network_userid);
                strncpy(local_5c,pcVar5,0x3f);
                local_1d = 0;
                pcVar5 = SV_GetIDString(id);
                strncpy(local_9c,pcVar5,0x3f);
                local_5d = 0;
                iVar7 = strcasecmp(local_5c,local_9c);
                iVar4 = svs.maxclients;
                if (iVar7 == 0) {
                  host_client = pcVar8;
                  if (sv_logbans.value != 0.0) {
                    SV_GetClientIDString::idstr[0] = '\0';
                    if (((pcVar8->netchan).remote_address.type == NA_LOOPBACK) &&
                       ((pcVar8->network_userid).idtype == 2)) {
                      snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
                    }
                    else {
                    /* Unresolved local var: USERID_t * id@[???] */
                      pcVar5 = SV_GetIDString(&pcVar8->network_userid);
                      snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar5);
                    }
                    Log_Printf("Ban: \"%s<%i><%s><>\" was kicked and banned \"%s\" by \"%s\"\n",
                               host_client->name,host_client->userid,SV_GetClientIDString::idstr,
                               &local_1dc,pcVar3);
                  }
                  SV_ClientPrintf("You have been kicked and banned %s by the server op.\n",
                                  &local_1dc);
                  SV_DropClient(host_client,false,"Kicked and banned");
                  host_client = pcVar2;
                  return;
                }
              }
              iVar9 = iVar9 + 1;
              pcVar8 = pcVar8 + 1;
            } while (iVar9 < iVar4);
          }
        }
        else if (sv_logbans.value != 0.0) {
          pcVar5 = SV_GetIDString(id);
          Log_Printf("Ban: \"<><%s><>\" was banned \"%s\" by \"%s\"\n",pcVar5,&local_1dc,pcVar3);
          return;
        }
      }
      else {
        Con_Printf("SV_BanId_f:  User filter list is full\n");
        pcVar2 = host_client;
      }
    }
  }
  host_client = pcVar2;
  return;
}


// SV_BanId_f  @ 000aca90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_BanId_f(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???]
                       Unresolved local var: USERID_t * id@[???]
                       Unresolved local var: char * pszCmdGiver@[???]
                       Unresolved local var: char[256] szreason@[???]
                       Unresolved local var: char[64] idstring@[???]
                       Unresolved local var: qboolean bKick@[???] */
  iVar1 = Cmd_Argc();
  if (2 < iVar1) {
    iVar1 = Cmd_Argc();
    if (iVar1 < 9) {
      SV_BanId_f();
      return;
    }
  }
  Con_Printf("Usage:  banid <minutes> <uniqueid or #userid> { kick }\n");
  Con_Printf("Use 0 minutes for permanent\n");
  return;
}


// SV_BatchUploadRequest  @ 000b7340
void SV_BatchUploadRequest(client_t *cl)

{
  resource_s *prVar1;
  resource_s *prVar2;
  client_t *pcVar3;
  char *pcVar4;
  qboolean qVar5;
  char local_120 [272];
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???]
                       Unresolved local var: char[260] filename@[???] */
  prVar1 = (cl->resourcesneeded).pNext;
joined_r0x000b736a:
  prVar2 = prVar1;
  if (prVar2 == &cl->resourcesneeded) {
    return;
  }
  prVar1 = prVar2->pNext;
  if ((prVar2->ucFlags & 2) != 0) goto code_r0x000b7382;
  prVar2->pPrev->pNext = prVar1;
  goto LAB_000b73c6;
code_r0x000b7382:
  if (prVar2->type == t_decal) {
    if ((prVar2->ucFlags & 4) == 0) {
      Con_Printf("Non customization in upload queue!\n");
      prVar2->pPrev->pNext = prVar2->pNext;
    }
    else {
      pcVar4 = MD5_Print(prVar2->rgucMD5_hash);
      snprintf(local_120,0x104,"!MD5%s",pcVar4);
      qVar5 = SV_CheckFile(&(cl->netchan).message,local_120);
      if (qVar5 == false) goto joined_r0x000b736a;
      prVar2->pPrev->pNext = prVar2->pNext;
    }
LAB_000b73c6:
    prVar2->pNext->pPrev = prVar2->pPrev;
    prVar2->pNext = (resource_s *)0x0;
    pcVar3 = host_client;
    prVar2->pPrev = (resource_s *)0x0;
    prVar2->pPrev = (pcVar3->resourcesonhand).pPrev;
    ((pcVar3->resourcesonhand).pPrev)->pNext = prVar2;
    (pcVar3->resourcesonhand).pPrev = prVar2;
    prVar2->pNext = &pcVar3->resourcesonhand;
  }
  goto joined_r0x000b736a;
}


// SV_BeginFileDownload_f  @ 000a9210
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_BeginFileDownload_f(void)

{
  char cVar1;
  client_t *pcVar2;
  int iVar3;
  char *s1;
  qboolean qVar4;
  size_t sVar5;
  resource_s local_d8;
  char local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  uchar local_3c [16];
  uchar *local_2c [4];
  int local_1c [4];
  
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: char[20] szModuleC@[???] */
  local_4d = 100;
  local_4c = 0x75;
  local_4b = 0x6c;
  local_4a = 0x65;
  local_49 = 0x43;
  local_50 = '!';
  local_4f = 0x4d;
  local_4e = 0x6f;
  local_48 = 0x2e;
  local_47 = 100;
  local_46 = 0x6c;
  local_45 = 0x6c;
  local_44 = 0;
  iVar3 = Cmd_Argc();
  if (iVar3 < 2) {
    return;
  }
  if (cmd_source == src_command) {
    return;
  }
  s1 = Cmd_Argv(1);
  if (s1 == (char *)0x0) {
    return;
  }
  if (*s1 == '\0') {
    return;
  }
  iVar3 = Q_strncmp(s1,&local_50,0xc);
  if ((iVar3 == 0) && (svs.isSecure != false)) {
    return;
  }
  qVar4 = IsSafeFileToDownload(s1);
  pcVar2 = host_client;
  if ((qVar4 == false) || (sv_allow_download.value == 0.0)) {
    cVar1 = *s1;
  }
  else {
    if (host_client->fully_connected == false) {
      cVar1 = *s1;
      if (cVar1 != '!') {
        if ((sv_send_resources.value != 0.0) &&
           ((((sv_downloadurl.string == (char *)0x0 || (*sv_downloadurl.string == '\0')) ||
             (sVar5 = strlen(sv_downloadurl.string), 0x7f < sVar5)) ||
            (sv_allow_dlfile.value != 0.0)))) {
          iVar3 = Netchan_CreateFileFragments(true,&pcVar2->netchan,s1);
          if (iVar3 != 0) {
            Netchan_FragSend(&host_client->netchan);
            return;
          }
          cVar1 = *s1;
        }
        goto joined_r0x000a9334;
      }
    }
    else {
      cVar1 = *s1;
      if (cVar1 != '!') goto joined_r0x000a9334;
    }
    iVar3 = Q_strlen(s1);
    if ((iVar3 == 0x24) && (iVar3 = Q_strnicmp(s1,"!MD5",4), iVar3 == 0)) {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: resource_t custResource@[???]
                       Unresolved local var: uchar * pbuf@[???]
                       Unresolved local var: int size@[???] */
      local_2c[0] = (uchar *)0x0;
      local_1c[0] = 0;
      if (sv_send_logos.value == 0.0) {
        SV_FailDownload(s1);
        return;
      }
      Q_memset(&local_d8,0,0x88);
      COM_HexConvert(s1 + 4,0x20,local_3c);
      qVar4 = HPAK_ResourceForHash("custom.hpk",local_3c,&local_d8);
      if (qVar4 == false) {
        return;
      }
      HPAK_GetDataPointer("custom.hpk",&local_d8,local_2c,local_1c);
      if (local_2c[0] == (uchar *)0x0) {
        return;
      }
      if (local_1c[0] == 0) {
        return;
      }
      Netchan_CreateFileFragmentsFromBuffer(true,&host_client->netchan,s1,local_2c[0],local_1c[0]);
      Netchan_FragSend(&host_client->netchan);
      Mem_Free(local_2c[0]);
      return;
    }
    cVar1 = *s1;
  }
joined_r0x000a9334:
  if (cVar1 != '\0') {
    MSG_WriteByte(&(host_client->netchan).message,0x31);
    MSG_WriteString(&(host_client->netchan).message,s1);
  }
  return;
}


// SV_BeginRedirect  @ 000a1a10
void SV_BeginRedirect(redirect_t rd,netadr_t *addr)

{
  sv_redirected = rd;
  sv_redirectto.type = addr->type;
  sv_redirectto.ip = *&addr->ip;
  sv_redirectto.ipx._0_4_ = *(undefined4 *)addr->ipx;
  sv_redirectto.ipx._4_4_ = *(undefined4 *)(addr->ipx + 4);
  outputbuf[0] = '\0';
  sv_redirectto._16_4_ = *(undefined4 *)(addr->ipx + 8);
  return;
}


// SV_BroadcastCommand  @ 000a7320
void SV_BroadcastCommand(char *fmt,...)

{
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  char local_4ac [1024];
  byte local_ac [128];
  sizebuf_t local_2c;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  local_2c.buffername = "Broadcast Command";
  local_2c.data = local_ac;
  local_2c.cursize = 0;
  local_2c.maxsize = 0x80;
  local_2c.flags = 1;
  if (sv.active != false) {
    vsnprintf(local_4ac,0x400,fmt,&stack0x00000008);
    MSG_WriteByte(&local_2c,9);
    MSG_WriteString(&local_2c,local_4ac);
    if ((local_2c.flags & 2) == 0) {
      if (0 < svs.maxclients) {
        iVar3 = 0;
        iVar1 = svs.maxclients;
        pcVar2 = svs.clients;
        do {
          if ((((pcVar2->active != false) || (pcVar2->connected != false)) ||
              (pcVar2->spawned != false)) && (pcVar2->fakeclient == false)) {
            SZ_Write(&(pcVar2->netchan).message,local_2c.data,local_2c.cursize);
            iVar1 = svs.maxclients;
          }
          iVar3 = iVar3 + 1;
          pcVar2 = pcVar2 + 1;
        } while (iVar3 < iVar1);
      }
    }
    else {
      Sys_Error("SV_BroadcastCommand:  Overflowed on %s, %i is max size\n",local_4ac,
                local_2c.maxsize);
    }
  }
  return;
}


// SV_BroadcastPrintf  @ 00073f40
void SV_BroadcastPrintf(char *fmt,...)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_40c [1024];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???]
                       Unresolved local var: int i@[???] */
  vsnprintf(local_40c,0x400,fmt,&stack0x00000008);
  if (0 < svs.maxclients) {
    iVar4 = 0;
    iVar2 = svs.maxclients;
    iVar3 = 0;
    do {
      while (((puVar1 = ((svs.clients)->netchan).remote_address.ip + iVar3 + -0x24,
              *(int *)puVar1 == 0 && (*(int *)(puVar1 + 4) == 0)) ||
             (*(int *)(puVar1 + 0x2438) != 0))) {
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x4ef8;
        if (iVar2 <= iVar4) goto LAB_00073ff0;
      }
      iVar4 = iVar4 + 1;
      MSG_WriteByte((sizebuf_t *)(puVar1 + 0x74),8);
      MSG_WriteString((sizebuf_t *)(((svs.clients)->netchan).message_buf + iVar3 + -0x14),local_40c)
      ;
      iVar2 = svs.maxclients;
      iVar3 = iVar3 + 0x4ef8;
    } while (iVar4 < svs.maxclients);
  }
LAB_00073ff0:
  Con_DPrintf("%s",local_40c);
  return;
}


// SV_BuildHashedSoundLookupTable  @ 0009cc00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_BuildHashedSoundLookupTable(void)

{
  __int32_t **pp_Var1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  char *pcVar6;
  int iVar7;
  int iVar5;
  
                    /* Unresolved local var: int sound_num@[???] */
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???]
                       Unresolved local var: uint hash@[???] */
  Q_memset(sv.sound_precache_hashedlookup,0,0x7fe);
  iVar7 = 0;
  do {
    pcVar6 = sv.sound_precache[iVar7];
    if (pcVar6 == (char *)0x0) {
      sv.sound_precache_hashedlookup_built = true;
      return;
    }
    cVar4 = *pcVar6;
    uVar2 = 0;
    uVar3 = uVar2;
    if (cVar4 != '\0') {
      pp_Var1 = __ctype_tolower_loc();
      uVar2 = 0;
      do {
                    /* Unresolved local var: int __res@[???] */
        iVar5 = (int)cVar4;
        pcVar6 = pcVar6 + 1;
        cVar4 = *pcVar6;
        uVar2 = uVar2 * 2 + (*pp_Var1)[iVar5];
      } while (cVar4 != '\0');
      uVar2 = uVar2 % 0x3ff;
      uVar3 = uVar2;
    }
    while (sv.sound_precache_hashedlookup[uVar2] != 0) {
      uVar2 = uVar2 + 1;
      hashstrings_collisions = hashstrings_collisions + 1;
      if (0x3fe < (int)uVar2) {
        uVar2 = 0;
      }
      if (uVar2 == uVar3) {
        Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
      }
    }
    sv.sound_precache_hashedlookup[uVar2] = (short)iVar7;
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x200);
  sv.sound_precache_hashedlookup_built = true;
  return;
}


// SV_BuildReconnect  @ 000a75b0
void SV_BuildReconnect(sizebuf_t *msg)

{
  MSG_WriteByte(msg,9);
  MSG_WriteString(msg,"reconnect\n");
  return;
}


// SV_BuildSoundMsg  @ 0009ce30
qboolean SV_BuildSoundMsg(edict_t_conflict *entity,int channel,char *sample,int volume,
                         float attenuation,int fFlags,int pitch,float *origin,sizebuf_t *buffer)

{
  float fVar1;
  uint32 data;
  int iVar2;
  uint32 local_28;
  uint32 local_24;
  uint32 local_20;
  
                    /* Unresolved local var: int sound_num@[???]
                       Unresolved local var: int field_mask@[???]
                       Unresolved local var: int ent@[???] */
  local_24 = volume;
  if (0xff < (uint)volume) {
    Con_Printf("SV_StartSound: volume = %i",volume);
    if (volume < 0) {
      local_24 = 0;
    }
    else {
      local_24 = 0xff;
    }
  }
  if (attenuation < 0.0) {
    fVar1 = 0.0;
LAB_0009cfea:
    Con_Printf("SV_StartSound: attenuation = %f",(double)attenuation);
    attenuation = fVar1;
  }
  else {
    fVar1 = 4.0;
    if (4.0 < attenuation) goto LAB_0009cfea;
  }
  if (7 < (uint)channel) {
    Con_Printf("SV_StartSound: channel = %i",channel);
    channel = ~(channel >> 0x1f) & 7;
  }
  local_20 = pitch;
  if (0xff < (uint)pitch) {
    Con_Printf("SV_StartSound: pitch = %i",pitch);
    if (pitch < 0) {
      local_20 = 0;
    }
    else {
      local_20 = 7;
    }
  }
  if (sample != (char *)0x0) {
    if (*sample == '!') {
      local_28 = Q_atoi(sample + 1);
      fFlags = fFlags | 0x10;
      if (0x5ff < (int)local_28) {
        Con_Printf("invalid sentence number: %s",sample + 1);
        return false;
      }
      goto LAB_0009cecf;
    }
    if (*sample == '#') {
      fFlags = fFlags | 0x10;
      iVar2 = Q_atoi(sample + 1);
      local_28 = iVar2 + 0x600;
      goto LAB_0009cecf;
    }
  }
  local_28 = SV_LookupSoundIndex(sample);
  if ((local_28 == 0) || (sv.sound_precache[local_28] == (char *)0x0)) {
    Con_Printf("SV_StartSound: %s not precached (%d)\n",sample,local_28);
    return false;
  }
LAB_0009cecf:
  data = NUM_FOR_EDICT((edict_t *)entity);
  if (local_24 != 0xff) {
    fFlags = fFlags | 1;
  }
  if (attenuation != 1.0) {
    fFlags = fFlags | 2;
  }
  if (local_20 != 100) {
    fFlags = fFlags | 8;
  }
  if (0xff < (int)local_28) {
    fFlags = fFlags | 4;
  }
  MSG_WriteByte(buffer,6);
  MSG_StartBitWriting(buffer);
  MSG_WriteBits(fFlags,9);
  if ((fFlags & 1U) != 0) {
    MSG_WriteBits(local_24,8);
  }
  if ((fFlags & 2U) != 0) {
    MSG_WriteBits((int)(attenuation * 64.0),8);
  }
  MSG_WriteBits(channel,3);
  MSG_WriteBits(data,0xb);
  if ((int)local_28 < 0x100) {
    MSG_WriteBits(local_28,8);
  }
  else {
    MSG_WriteBits(local_28,0x10);
  }
  MSG_WriteBitVec3Coord(origin);
  if ((fFlags & 8U) != 0) {
    MSG_WriteBits(local_20,8);
  }
  MSG_EndBitWriting(buffer);
  return true;
}


// SV_CalcClientTime  @ 000b9970
float SV_CalcClientTime(client_t *cl)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: float minping@[???]
                       Unresolved local var: float maxping@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int backtrack@[???] */
  fVar3 = 0.0;
  iVar6 = 1;
  if (0 < (int)sv_unlagsamples.value) {
    iVar6 = (int)sv_unlagsamples.value;
  }
  iVar8 = 0x10;
  if (SV_UPDATE_BACKUP < 0x11) {
    iVar8 = SV_UPDATE_BACKUP;
  }
  if (iVar6 < iVar8) {
    iVar8 = iVar6;
  }
  if (0 < iVar8) {
    iVar6 = (cl->netchan).incoming_acknowledged;
    iVar7 = 0;
    iVar9 = 0;
    do {
      fVar1 = cl->frames[iVar6 - iVar7 & SV_UPDATE_MASK].ping_time;
      if (0.0 < fVar1) {
        fVar3 = fVar1 + fVar3;
        iVar9 = iVar9 + 1;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != iVar8);
    if (iVar9 == 0) {
      fVar3 = 0.0;
    }
    else {
      iVar8 = 4;
      if (SV_UPDATE_BACKUP < 5) {
        iVar8 = SV_UPDATE_BACKUP;
      }
      if (0 < iVar8) {
        iVar7 = 0;
        fVar5 = 9999.0;
        fVar1 = -9999.0;
        do {
          fVar2 = cl->frames[iVar6 - iVar7 & SV_UPDATE_MASK].ping_time;
          fVar4 = fVar1;
          if (0.0 < fVar2) {
            if (fVar2 < fVar5) {
              fVar5 = fVar2;
            }
            fVar4 = fVar2;
            if (fVar2 <= fVar1) {
              fVar4 = fVar1;
            }
          }
          iVar7 = iVar7 + 1;
          fVar1 = fVar4;
        } while (iVar7 != iVar8);
        if ((fVar5 <= fVar4) && (0.2 < ABS(fVar4 - fVar5))) {
          return 0.0;
        }
      }
      fVar3 = fVar3 / (float)iVar9;
    }
  }
  return fVar3;
}


// SV_CalcPing  @ 000a3070
int SV_CalcPing(client_t *cl)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
  if (cl->fakeclient == false) {
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
    if (SV_UPDATE_BACKUP < 0x20) {
      iVar5 = SV_UPDATE_BACKUP / 2;
      if (iVar5 < 1) {
        return 0;
      }
    }
    else {
      iVar5 = 0x10;
    }
    fVar2 = 0.0;
    iVar4 = 0;
    iVar3 = 0;
    do {
      fVar1 = cl->frames[((cl->netchan).incoming_acknowledged + -1) - iVar3 & SV_UPDATE_MASK].
              ping_time;
      if (0.0 < fVar1) {
        fVar2 = fVar1 + fVar2;
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar5);
    if ((iVar4 != 0) && (0.0 <= fVar2 / (float)iVar4)) {
      return (int)((fVar2 / (float)iVar4) * 1000.0);
    }
  }
  return 0;
}


// SV_CheckAllEnts  @ 000b17f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckAllEnts(void)

{
  int iVar1;
  edict_t_conflict *peVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: edict_t.conflict * check@[???] */
  if (1 < sv.num_edicts) {
    iVar4 = 1;
    iVar5 = 0x324;
    iVar3 = sv.num_edicts;
    do {
      peVar2 = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar5 + -0x18);
      if ((((peVar2->free == 0) && (iVar1 = (peVar2->v).movetype, iVar1 != 0)) && (iVar1 != 7)) &&
         (((iVar1 != 0xc && (iVar1 != 8)) &&
          (peVar2 = SV_TestEntityPosition(peVar2), iVar3 = sv.num_edicts,
          peVar2 != (edict_t_conflict *)0x0)))) {
        Con_Printf("entity in invalid position\n");
        iVar3 = sv.num_edicts;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x324;
    } while (iVar4 < iVar3);
  }
  return;
}


// SV_CheckBlendingInterface  @ 0007e290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckBlendingInterface(void)

{
  code *pcVar1;
  int iVar2;
  extensiondll_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SV_BLENDING_INTERFACE_FUNC studio_interface@[???] */
  R_ResetSvBlending();
  if (0 < g_iextdllMac) {
    peVar3 = g_rgextdll;
    iVar4 = 0;
    do {
      pcVar1 = (code *)dlsym(peVar3->lDLLHandle,"Server_GetBlendingInterface");
      if (pcVar1 != (code *)0x0) {
        iVar2 = (*pcVar1)(1,&g_pSvBlendingAPI,&server_studio_api,rotationmatrix,bonetransform);
        if (iVar2 != 0) {
          return;
        }
        Con_DPrintf("Couldn\'t get server .dll studio model blending interface. Version mismatch?\n"
                   );
        R_ResetSvBlending();
      }
      iVar4 = iVar4 + 1;
      peVar3 = peVar3 + 1;
    } while (iVar4 < g_iextdllMac);
  }
  return;
}


// SV_CheckBottom  @ 000ae4d0
qboolean SV_CheckBottom(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  vec_t vVar7;
  int iVar8;
  qboolean monsterClipBrush;
  trace_t local_6c;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t stop@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: float mid@[???]
                       Unresolved local var: float bottom@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  fVar1 = (ent->v).origin[0];
  fVar4 = (ent->v).mins[0] + fVar1;
  g_groupmask = (ent->v).groupinfo;
  uVar3 = (ent->v).flags;
  fVar2 = (ent->v).origin[1];
  fVar5 = (ent->v).mins[1] + fVar2;
  fVar6 = (ent->v).origin[2] + (ent->v).mins[2];
  fVar1 = fVar1 + (ent->v).maxs[0];
  fVar2 = fVar2 + (ent->v).maxs[1];
  local_2c = fVar6 - 1.0;
  local_34 = fVar4;
  local_30 = fVar5;
  iVar8 = SV_PointContents(&local_34);
  if (iVar8 == -2) {
    g_groupmask = (ent->v).groupinfo;
    local_34 = fVar4;
    local_30 = fVar2;
    iVar8 = SV_PointContents(&local_34);
    if (iVar8 == -2) {
      g_groupmask = (ent->v).groupinfo;
      local_34 = fVar1;
      local_30 = fVar5;
      iVar8 = SV_PointContents(&local_34);
      if (iVar8 == -2) {
        g_groupmask = (ent->v).groupinfo;
        local_34 = fVar1;
        local_30 = fVar2;
        iVar8 = SV_PointContents(&local_34);
        if (iVar8 == -2) goto LAB_000ae5e4;
      }
    }
  }
  monsterClipBrush = (qboolean)((uVar3 & 0x800000) != 0);
  local_2c = fVar6 + sv_stepsize.value;
  c_no = c_no + 1;
  local_34 = (fVar4 + fVar1) * 0.5;
  local_30 = (fVar5 + fVar2) * 0.5;
  local_20 = local_2c - (sv_stepsize.value + sv_stepsize.value);
  local_28 = local_34;
  local_24 = local_30;
  SV_Move(&local_6c,&local_34,vec3_origin,vec3_origin,&local_28,1,ent,monsterClipBrush);
  vVar7 = local_6c.endpos[2];
  if (local_6c.fraction == 1.0) {
    return false;
  }
  local_34 = fVar4;
  local_30 = fVar5;
  local_28 = fVar4;
  local_24 = fVar5;
  SV_Move(&local_6c,&local_34,vec3_origin,vec3_origin,&local_28,1,ent,monsterClipBrush);
  if (local_6c.fraction == 1.0) {
    return false;
  }
  if (sv_stepsize.value < vVar7 - local_6c.endpos[2]) {
    return false;
  }
  local_34 = fVar4;
  local_30 = fVar2;
  local_28 = fVar4;
  local_24 = fVar2;
  SV_Move(&local_6c,&local_34,vec3_origin,vec3_origin,&local_28,1,ent,monsterClipBrush);
  if (local_6c.fraction == 1.0) {
    return false;
  }
  if (sv_stepsize.value < vVar7 - local_6c.endpos[2]) {
    return false;
  }
  local_34 = fVar1;
  local_30 = fVar5;
  local_28 = fVar1;
  local_24 = fVar5;
  SV_Move(&local_6c,&local_34,vec3_origin,vec3_origin,&local_28,1,ent,monsterClipBrush);
  if (local_6c.fraction == 1.0) {
    return false;
  }
  if (sv_stepsize.value < vVar7 - local_6c.endpos[2]) {
    return false;
  }
  local_34 = fVar1;
  local_30 = fVar2;
  local_28 = fVar1;
  local_24 = fVar2;
  SV_Move(&local_6c,&local_34,vec3_origin,vec3_origin,&local_28,1,ent,monsterClipBrush);
  if (local_6c.fraction == 1.0) {
    return false;
  }
  if (sv_stepsize.value < vVar7 - local_6c.endpos[2]) {
    return false;
  }
LAB_000ae5e4:
  c_yes = c_yes + 1;
  return true;
}


// SV_CheckChallenge  @ 0009f0e0
int SV_CheckChallenge(netadr_t *adr,int nChallengeValue)

{
  netadr_t a;
  qboolean qVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (adr == (netadr_t *)0x0) {
    Sys_Error("SV_CheckChallenge:  Null address\n");
    return 0;
  }
  qVar1 = NET_IsLocalAddress(*adr);
  if (qVar1 == false) {
    iVar2 = 0;
    while( true ) {
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
      qVar1 = NET_CompareBaseAdr(a,g_rg_sv_challenges[iVar2].adr);
      if (qVar1 != false) break;
                    /* Unresolved local var: int i@[???] */
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x400) {
        SV_RejectConnection(adr,"No challenge for your address.\n");
        return 0;
      }
    }
    if (nChallengeValue != g_rg_sv_challenges[iVar2].challenge) {
      SV_RejectConnection(adr,"Bad challenge.\n");
      return 0;
    }
  }
  return 1;
}


// SV_CheckCmdTimes  @ 000a9910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckCmdTimes(void)

{
  double dVar1;
  int iVar2;
  qboolean qVar3;
  client_s *pcVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float dif@[???] */
  qVar3 = Host_IsSinglePlayerGame();
  iVar2 = svs.maxclients;
  dVar1 = realtime;
  if (((qVar3 == false) &&
      (lVar6 = (longdouble)realtime,
      (longdouble)1 <= lVar6 - (longdouble)SV_CheckCmdTimes::lastreset)) &&
     (SV_CheckCmdTimes::lastreset = realtime, 0 < svs.maxclients)) {
    lVar7 = (longdouble)clockwindow.value;
    iVar5 = 0;
    pcVar4 = svs.clients;
    do {
      while ((pcVar4->connected != false && (pcVar4->active != false))) {
        lVar8 = (longdouble)pcVar4->connecttime;
        if ((longdouble)pcVar4->connecttime == (longdouble)0) {
          pcVar4->connecttime = dVar1;
          lVar8 = lVar6;
        }
        lVar9 = (longdouble)(float)(((longdouble)pcVar4->cmdtime + lVar8) - lVar6);
        if (lVar7 < lVar9) {
          pcVar4->ignorecmdtime = (double)(lVar6 + lVar7);
          pcVar4->cmdtime = (double)(lVar6 - lVar8);
          break;
        }
        if (-lVar7 <= lVar9) break;
        iVar5 = iVar5 + 1;
        pcVar4->cmdtime = (double)(lVar6 - lVar8);
        pcVar4 = pcVar4 + 1;
        if (iVar5 == iVar2) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 != iVar2);
  }
  return;
}


// SV_CheckFile  @ 000b6980
qboolean SV_CheckFile(sizebuf_t *msg,char *filename)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  resource_s local_94;
  
                    /* Unresolved local var: resource_t p@[???] */
  Q_memset(&local_94,0,0x88);
  iVar2 = Q_strlen(filename);
  if ((iVar2 == 0x24) && (iVar2 = Q_strnicmp(filename,"!MD5",4), iVar2 == 0)) {
    COM_HexConvert(filename + 4,0x20,local_94.rgucMD5_hash);
    qVar4 = HPAK_GetDataPointer("custom.hpk",&local_94,(uchar **)0x0,(int *)0x0);
    if (qVar4 != false) {
      return true;
    }
  }
  bVar1 = sv_allow_upload.value != 0.0;
  if (bVar1) {
    MSG_WriteByte(msg,9);
    pcVar3 = MD5_Print(local_94.rgucMD5_hash);
    pcVar3 = va("upload \"!MD5%s\"\n",pcVar3);
    MSG_WriteString(msg,pcVar3);
  }
  return (uint)!bVar1;
}


// SV_CheckForDuplicateNames  @ 0009f6b0
int SV_CheckForDuplicateNames(char *userinfo,qboolean bIsReconnecting,int nExcludeSlot)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  client_s *pcVar4;
  char *local_4c;
  int local_48;
  int local_44;
  char local_3c [44];
  
                    /* Unresolved local var: char[32] newname@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: char * val@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int dupc@[???]
                       Unresolved local var: int retval@[???] */
  local_4c = Info_ValueForKey(userinfo,"name");
  if (((((local_4c != (char *)0x0) && (*local_4c != '\0')) &&
       (iVar1 = Q_stricmp(local_4c,"console"), iVar1 != 0)) &&
      ((pcVar2 = Q_strstr(local_4c,".."), pcVar2 == (char *)0x0 &&
       (pcVar2 = Q_strstr(local_4c,"\""), pcVar2 == (char *)0x0)))) &&
     (pcVar2 = Q_strstr(local_4c,"\\"), pcVar2 == (char *)0x0)) {
    local_48 = 1;
    local_44 = 0;
    do {
      iVar1 = 0;
      pcVar4 = svs.clients;
      while (((iVar1 == nExcludeSlot && (bIsReconnecting != false)) ||
             ((pcVar4->connected == false || (iVar3 = Q_stricmp(pcVar4->name,local_4c), iVar3 != 0))
             ))) {
        iVar1 = iVar1 + 1;
        pcVar4 = pcVar4 + 1;
        if (iVar1 == 0x20) {
          return local_44;
        }
      }
      if (*local_4c == '(') {
        if (local_4c[2] == ')') {
          local_4c = local_4c + 3;
        }
        else if (local_4c[3] == ')') {
          local_4c = local_4c + 4;
        }
      }
      snprintf(local_3c,0x20,"(%d)%-0.*s",local_48,0x1c,local_4c);
      Info_SetValueForKey(userinfo,"name",local_3c,0x100);
      local_4c = Info_ValueForKey(userinfo,"name");
      local_44 = 1;
      local_48 = local_48 + 1;
    } while( true );
  }
  Info_SetValueForKey(userinfo,"name","unamed",0x100);
  return 1;
}


// SV_CheckForDuplicateSteamID  @ 000aaf20
int SV_CheckForDuplicateSteamID(client_t *client)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  client_s *pcVar5;
  char local_9c [63];
  undefined1 local_5d;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: int nRet@[???]
                       Unresolved local var: int nCount@[???] */
  if (sv_lan.value == 0.0) {
    if (svs.maxclients < 1) {
      return -1;
    }
    iVar4 = 0;
                    /* Unresolved local var: client_t * cl@[???] */
    iVar3 = svs.maxclients;
    do {
      pcVar5 = svs.clients + iVar4;
      if ((((pcVar5->connected != false) && (pcVar5->fakeclient == false)) &&
          (iVar2 = (pcVar5->network_userid).idtype, iVar2 - 1U < 2)) &&
         (((client != pcVar5 && (&pcVar5->network_userid != (USERID_t *)0x0)) &&
          ((&client->network_userid != (USERID_t *)0x0 && (iVar2 == (client->network_userid).idtype)
           ))))) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
        pcVar1 = SV_GetIDString(&client->network_userid);
        strncpy(local_9c,pcVar1,0x3f);
        local_5d = 0;
        pcVar1 = SV_GetIDString(&pcVar5->network_userid);
        strncpy(local_5c,pcVar1,0x3f);
        local_1d = 0;
        iVar2 = strcasecmp(local_9c,local_5c);
        iVar3 = svs.maxclients;
        if (iVar2 == 0) {
          return iVar4;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  return -1;
}


// SV_CheckForRcon  @ 000a9a20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckForRcon(void)

{
  netadr_t to;
  qboolean qVar1;
  char *text;
  netadr_t *net_from;
  int iVar2;
  char local_4c [68];
  
                    /* Unresolved local var: char[64] szMessage@[???] */
  if ((((sv.active == false) && (cls.state == ca_dedicated)) && (giActive != 3)) &&
     (host_initialized != false)) {
    while (qVar1 = NET_GetPacket(NS_SERVER), qVar1 != false) {
      qVar1 = SV_FilterPacket();
      if (qVar1 == false) {
        if (*(int *)net_message.data == -1) {
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * c@[???] */
          MSG_BeginReading();
          MSG_ReadLong();
          text = MSG_ReadStringLine();
          Cmd_TokenizeString(text);
          net_from = (netadr_t *)Cmd_Argv(0);
          iVar2 = Q_strcmp((char *)net_from,"getchallenge");
          if (iVar2 == 0) {
            SVC_GetChallenge();
          }
          else {
            iVar2 = Q_stricmp((char *)net_from,"challenge");
            if (iVar2 == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???] */
              iVar2 = Cmd_Argc();
              if (iVar2 == 2) {
                SVC_ServiceChallenge();
              }
            }
            else {
              iVar2 = Q_strcmp((char *)net_from,"rcon");
              if (iVar2 == 0) {
                SV_Rcon(net_from);
              }
            }
          }
        }
      }
      else {
        snprintf(local_4c,0x40,"You have been banned from this server.\n");
        SZ_Clear(&net_message);
        MSG_WriteLong(&net_message,-1);
        MSG_WriteByte(&net_message,0x6c);
        MSG_WriteString(&net_message,local_4c);
        to.ip[0] = ::net_from.ip[0];
        to.ip[1] = ::net_from.ip[1];
        to.ip[2] = ::net_from.ip[2];
        to.ip[3] = ::net_from.ip[3];
        to.type = ::net_from.type;
        to.ipx[0] = ::net_from.ipx[0];
        to.ipx[1] = ::net_from.ipx[1];
        to.ipx[2] = ::net_from.ipx[2];
        to.ipx[3] = ::net_from.ipx[3];
        to.ipx[4] = ::net_from.ipx[4];
        to.ipx[5] = ::net_from.ipx[5];
        to.ipx[6] = ::net_from.ipx[6];
        to.ipx[7] = ::net_from.ipx[7];
        to.ipx[8] = ::net_from.ipx[8];
        to.ipx[9] = ::net_from.ipx[9];
        to.port = ::net_from.port;
        NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,to);
        SZ_Clear(&net_message);
      }
    }
  }
  return;
}


// SV_CheckIPConnectionReuse  @ 0009f320
int SV_CheckIPConnectionReuse(netadr_t *adr)

{
  qboolean qVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
  if (0 < svs.maxclients) {
    iVar6 = 0;
    iVar4 = 0;
    iVar5 = 0;
    iVar3 = svs.maxclients;
    do {
                    /* Unresolved local var: client_t * cl@[???] */
      while ((*(int *)((int)(&((svs.clients)->netchan).remote_address + -1) + iVar6) != 0 &&
             (*(int *)(((svs.clients)->netchan).remote_address.ip + iVar6 + -0x1c) == 0))) {
        qVar1 = NET_CompareBaseAdr(*adr,*(netadr_t *)
                                         (((svs.clients)->netchan).remote_address.ip + iVar6 + -4));
        if (qVar1 != false) {
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 0x4ef8;
        iVar3 = svs.maxclients;
        if (svs.maxclients <= iVar4) goto LAB_0009f3d0;
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x4ef8;
    } while (iVar4 < iVar3);
LAB_0009f3d0:
    if (5 < iVar5) {
      pcVar2 = NET_AdrToString(*adr);
      Log_Printf("Too many connect packets from %s\n",pcVar2);
      return 0;
    }
  }
  return 1;
}


// SV_CheckIPRestrictions  @ 0009f230
int SV_CheckIPRestrictions(netadr_t *adr,int nAuthProtocol)

{
  bool bVar1;
  netadr_t b;
  uint uVar2;
  qboolean qVar3;
  
  bVar1 = true;
  if ((sv_lan.value == 0.0) && (bVar1 = false, nAuthProtocol == 3)) {
    return 1;
  }
  uVar2 = 1;
  if ((nAuthProtocol != 2) && (uVar2 = 0, bVar1)) {
    b.ip = net_local_adr.ip;
    b.type = net_local_adr.type;
    b.ipx._0_4_ = net_local_adr.ipx._0_4_;
    b.ipx._4_4_ = net_local_adr.ipx._4_4_;
    b._16_4_ = net_local_adr._16_4_;
    qVar3 = NET_CompareClassBAdr(*adr,b);
    uVar2 = 1;
    if (qVar3 == false) {
      qVar3 = NET_IsReservedAdr(*adr);
      uVar2 = (uint)(qVar3 != false);
    }
  }
  return uVar2;
}


// SV_CheckKeyInfo  @ 0009f500
int SV_CheckKeyInfo(netadr_t *adr,char *protinfo,ushort *port,int *pAuthProtocol,char *pszRaw,
                   int nRawSize,char *cdkey)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nAuthProtocol@[???] */
  pcVar1 = Info_ValueForKey(protinfo,"prot");
  iVar2 = Q_atoi(pcVar1);
  if (3 < iVar2 - 1U) {
    SV_RejectConnection(adr,"Invalid connection.\n");
    return 0;
  }
  pcVar1 = Info_ValueForKey(protinfo,"raw");
  iVar3 = Q_strlen(pcVar1);
  if (iVar3 < 1) {
LAB_0009f611:
    SV_RejectConnection(adr,"Invalid authentication certificate length.\n");
    iVar2 = 0;
  }
  else {
    if (iVar2 == 2) {
      iVar3 = Q_strlen(pcVar1);
      if (iVar3 != 0x20) goto LAB_0009f611;
      Q_strncpy(pszRaw,pcVar1,nRawSize);
      pszRaw[nRawSize + -1] = '\0';
      Q_strncpy(cdkey,pcVar1,0x40);
    }
    else {
      Q_strncpy(pszRaw,pcVar1,nRawSize);
      pszRaw[nRawSize + -1] = '\0';
      pcVar1 = Info_ValueForKey(protinfo,"cdkey");
      iVar3 = Q_strlen(pcVar1);
      if (iVar3 != 0x20) {
        SV_RejectConnection(adr,"Invalid hashed CD key.\n");
        return 0;
      }
      Q_strncpy(cdkey,pcVar1,0x40);
    }
    iVar3 = Q_atoi("27005");
    *port = (ushort)iVar3;
    *pAuthProtocol = iVar2;
    iVar2 = 1;
  }
  return iVar2;
}


// SV_CheckMapDifferences  @ 000a9c50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckMapDifferences(void)

{
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = svs.maxclients;
  if ((5.0 <= realtime - SV_CheckMapDifferences::lastcheck) &&
     (SV_CheckMapDifferences::lastcheck = realtime, 0 < svs.maxclients)) {
    iVar3 = 0;
    pcVar2 = svs.clients;
    do {
      if ((((pcVar2->active != false) && (pcVar2->crcValue != 0)) &&
          ((pcVar2->netchan).remote_address.type != NA_LOOPBACK)) &&
         (pcVar2->crcValue != sv.worldmapCRC)) {
        (pcVar2->netchan).message.flags = (pcVar2->netchan).message.flags | 2;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


// SV_CheckMovingGround  @ 000b95d0
void SV_CheckMovingGround(edict_t_conflict *player,float frametime)

{
  vec_t *pvVar1;
  edict_t_conflict *peVar2;
  uint uVar3;
  
                    /* Unresolved local var: edict_t.conflict * groundentity@[???] */
  uVar3 = (player->v).flags;
  if ((((uVar3 & 0x200) != 0) &&
      (peVar2 = (player->v).groundentity, peVar2 != (edict_t_conflict *)0x0)) &&
     (((peVar2->v).flags & 4) != 0)) {
    pvVar1 = (player->v).basevelocity;
    if ((uVar3 & 0x400000) == 0) {
      VectorScale((peVar2->v).movedir,(peVar2->v).speed,pvVar1);
    }
    else {
      VectorMA(pvVar1,(peVar2->v).speed,(peVar2->v).movedir,pvVar1);
    }
    uVar3 = (player->v).flags | 0x400000;
    (player->v).flags = uVar3;
  }
  if ((uVar3 & 0x400000) == 0) {
    pvVar1 = (player->v).velocity;
    VectorMA(pvVar1,frametime * 0.5 + 1.0,(player->v).basevelocity,pvVar1);
    uVar3 = (player->v).flags;
    (player->v).basevelocity[0] = 0.0;
    (player->v).basevelocity[1] = 0.0;
    (player->v).basevelocity[2] = 0.0;
  }
  (player->v).flags = uVar3 & 0xffbfffff;
  return;
}


// SV_CheckProtocol  @ 0009f020
int SV_CheckProtocol(netadr_t *adr,int nProtocol)

{
  int iVar1;
  char *pcVar2;
  
  if (adr == (netadr_t *)0x0) {
    Sys_Error("SV_CheckProtocol:  Null address\n");
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
    if (nProtocol != 0x30) {
      if (nProtocol < 0x31) {
        SV_RejectConnection(adr,
                            "This server is using a newer protocol ( %i ) than your client ( %i ).  You should check for updates to your client.\n"
                            ,0x30,nProtocol);
        return 0;
      }
      iVar1 = Q_strlen(sv_contact.string);
      pcVar2 = "(no email address specified)";
      if (0 < iVar1) {
        pcVar2 = sv_contact.string;
      }
      SV_RejectConnection(adr,
                          "This server is using an older protocol ( %i ) than your client ( %i ).  If you believe this server is outdated, you can contact the server administrator at %s.\n"
                          ,0x30,nProtocol,pcVar2);
      iVar1 = 0;
    }
  }
  return iVar1;
}


// SV_CheckRate  @ 000a2b40
void SV_CheckRate(client_t *cl)

{
  if ((0.0 < sv_maxrate.value) && (sv_maxrate.value < (float)(cl->netchan).rate)) {
    if (100000.0 <= sv_maxrate.value) {
      (cl->netchan).rate = 100000.0;
    }
    else {
      (cl->netchan).rate = (double)sv_maxrate.value;
    }
  }
  if ((0.0 < sv_minrate.value) && ((float)(cl->netchan).rate < sv_minrate.value)) {
    if (sv_minrate.value <= 1000.0) {
      (cl->netchan).rate = 1000.0;
    }
    else {
      (cl->netchan).rate = (double)sv_minrate.value;
    }
  }
  return;
}


// SV_CheckRconFailure  @ 000a1e60
qboolean SV_CheckRconFailure(netadr_t *adr)

{
  qboolean qVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: rcon_failure_t * r@[???] */
  iVar2 = 0;
  do {
    if (g_rgRconFailures[iVar2].active != false) {
      qVar1 = NET_CompareAdr(*adr,g_rgRconFailures[iVar2].adr);
      if ((qVar1 != false) && (g_rgRconFailures[iVar2].shouldreject != false)) {
        return true;
      }
    }
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x20) {
      return false;
    }
  } while( true );
}


// SV_CheckSaveGameCommentInterface  @ 0007e320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckSaveGameCommentInterface(void)

{
  SV_SAVEGAMECOMMENT_FUNC p_Var1;
  extensiondll_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pszFunction@[???]
                       Unresolved local var: SV_SAVEGAMECOMMENT_FUNC pTemp@[???] */
  if (0 < g_iextdllMac) {
    peVar2 = g_rgextdll;
    iVar3 = 0;
    do {
      p_Var1 = (SV_SAVEGAMECOMMENT_FUNC)dlsym(peVar2->lDLLHandle,"SV_SaveGameComment");
      if (p_Var1 != (SV_SAVEGAMECOMMENT_FUNC)0x0) {
        g_pSaveGameCommentFunc = p_Var1;
        return;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 < g_iextdllMac);
  }
  return;
}


// SV_CheckSphereIntersection  @ 00094a50
qboolean SV_CheckSphereIntersection(edict_t_conflict *ent,vec_t *start,vec_t *end)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  qboolean qVar5;
  void *pvVar6;
  int iVar7;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float radiusSquared@[???]
                       Unresolved local var: vec3_t maxDim@[???]
                       Unresolved local var: vec3_t traceOrg@[???]
                       Unresolved local var: vec3_t traceDir@[???]
                       Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  qVar5 = true;
  if (((ent->v).flags & 8) != 0) {
    local_24 = *start;
    local_20 = start[1];
    local_1c = start[2];
    local_18 = *end - local_24;
    local_14 = end[1] - local_20;
    local_10 = end[2] - local_1c;
    pvVar6 = Mod_Extradata(sv.models[(ent->v).modelindex]);
    iVar7 = (ent->v).sequence * 0xb0 + *(int *)((int)pvVar6 + 0xa8);
    fVar1 = ABS(*(float *)((int)pvVar6 + iVar7 + 0x60));
    fVar4 = ABS(*(float *)((int)pvVar6 + iVar7 + 0x6c));
    if (fVar1 <= fVar4) {
      fVar1 = fVar4;
    }
    fVar4 = ABS(*(float *)((int)pvVar6 + iVar7 + 100));
    fVar2 = ABS(*(float *)((int)pvVar6 + iVar7 + 0x70));
    if (fVar4 <= fVar2) {
      fVar4 = fVar2;
    }
    fVar2 = ABS(*(float *)((int)pvVar6 + iVar7 + 0x68));
    fVar3 = ABS(*(float *)((int)pvVar6 + iVar7 + 0x74));
    if (fVar2 <= fVar3) {
      fVar2 = fVar3;
    }
    qVar5 = DoesSphereIntersect((ent->v).origin,fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1 + 0.0,
                                &local_24,&local_18);
    qVar5 = (qboolean)(qVar5 != false);
  }
  return qVar5;
}


// SV_CheckTimeouts  @ 000a2fa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckTimeouts(void)

{
  float fVar1;
  int iVar2;
  client_s *cl;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float droptime@[???] */
  fVar1 = (float)realtime - sv_timeout.value;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    iVar2 = svs.maxclients;
    cl = svs.clients;
    do {
      while (((cl->fakeclient != false ||
              (((cl->connected == false && (cl->active == false)) && (cl->spawned == false)))) ||
             (fVar1 <= (cl->netchan).last_received))) {
        iVar3 = iVar3 + 1;
        cl = cl + 1;
        if (iVar2 <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      SV_BroadcastPrintf("%s timed out\n",cl->name);
      SV_DropClient(cl,false,"Timed out");
      iVar2 = svs.maxclients;
      cl = cl + 1;
    } while (iVar3 < svs.maxclients);
  }
  return;
}


// SV_CheckUpdateRate  @ 0009ed20
void SV_CheckUpdateRate(double *rate)

{
  if (*rate == 0.0) {
    *(undefined4 *)rate = 0x9999999a;
    *(undefined4 *)((int)rate + 4) = 0x3fa99999;
    return;
  }
  if ((sv_maxupdaterate.value <= 0.001) && (sv_maxupdaterate.value != 0.0)) {
    Cvar_Set("sv_maxupdaterate","30.0");
  }
  if ((sv_minupdaterate.value <= 0.001) && (sv_minupdaterate.value != 0.0)) {
    Cvar_Set("sv_minupdaterate","1.0");
  }
  if (NAN(sv_maxupdaterate.value)) {
    if (1.0 / sv_maxupdaterate.value <= (float)*rate) goto LAB_0009edd0;
  }
  else if ((sv_maxupdaterate.value == 0.0) || (1.0 / sv_maxupdaterate.value <= (float)*rate))
  goto LAB_0009edd0;
  *rate = (double)(1.0 / sv_maxupdaterate.value);
LAB_0009edd0:
  if ((sv_minupdaterate.value != 0.0) && (1.0 / sv_minupdaterate.value < (float)*rate)) {
    *rate = (double)(1.0 / sv_minupdaterate.value);
  }
  return;
}


// SV_CheckUserInfo  @ 0009f8b0
int SV_CheckUserInfo(netadr_t *adr,char *userinfo,qboolean bIsReconnecting,int nReconnectSlot,
                    char *name)

{
  float fVar1;
  char *pcVar2;
  char cVar3;
  qboolean qVar4;
  size_t sVar5;
  char *pcVar6;
  int iVar7;
  qboolean qVar8;
  client_s *pcVar9;
  int iVar10;
  char local_3c [31];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * pChar@[???]
                       Unresolved local var: char[32] newname@[???]
                       Unresolved local var: int proxies@[???]
                       Unresolved local var: int i@[???] */
  qVar4 = NET_IsLocalAddress(*adr);
  if (((qVar4 == false) && (*sv_password.string != '\0')) &&
     (iVar7 = Q_stricmp(sv_password.string,"none"), iVar7 != 0)) {
    pcVar6 = Info_ValueForKey(userinfo,"password");
    iVar7 = Q_strcmp(sv_password.string,pcVar6);
    if (iVar7 != 0) {
      pcVar6 = NET_AdrToString(*adr);
      Con_Printf("%s:  password failed\n",pcVar6);
      SZ_Clear(&net_message);
      MSG_WriteLong(&net_message,-1);
      MSG_WriteByte(&net_message,0x38);
      MSG_WriteString(&net_message,"BADPASSWORD");
      NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,*adr);
      SZ_Clear(&net_message);
      return 0;
    }
  }
  sVar5 = strlen(userinfo);
  if (((4 < sVar5) && (pcVar6 = strstr(userinfo,"\\\\"), pcVar6 == (char *)0x0)) &&
     (userinfo[sVar5 - 1] != '\\')) {
    Info_RemoveKey(userinfo,"password");
    pcVar6 = Info_ValueForKey(userinfo,"name");
    iVar7 = Q_strlen(pcVar6);
    if (iVar7 == 0) {
      Q_strcpy(local_3c,"unnamed");
    }
    else {
      Q_strncpy(local_3c,pcVar6,0x20);
      local_1d = 0;
    }
    pcVar6 = local_3c;
    cVar3 = local_3c[0];
    if (local_3c[0] != '\0') {
      do {
        if ((byte)(cVar3 - 0x25U) < 2) {
          *pcVar6 = ' ';
        }
        pcVar6 = pcVar6 + 1;
        pcVar2 = local_3c;
      } while ((pcVar6 != (char *)0x0) && (cVar3 = *pcVar6, *pcVar6 != '\0'));
      while (local_3c[0] == '#') {
        *pcVar2 = ' ';
        local_3c[0] = pcVar2[1];
        pcVar2 = pcVar2 + 1;
      }
    }
    TrimSpace(local_3c,name);
    qVar8 = Q_UnicodeValidate(name);
    if (qVar8 == 0) {
      Q_UnicodeRepair(name);
    }
    Info_SetValueForKey(userinfo,"name",name,0x100);
    iVar7 = SV_CheckForDuplicateNames(userinfo,bIsReconnecting,nReconnectSlot);
    if (iVar7 != 0) {
      pcVar6 = Info_ValueForKey(userinfo,"name");
      Q_strncpy(name,pcVar6,0x20);
      name[0x1f] = '\0';
    }
    pcVar6 = Info_ValueForKey(userinfo,"*hltv");
    iVar7 = Q_strlen(pcVar6);
    if (iVar7 == 0) {
      return 1;
    }
    iVar7 = Q_atoi(pcVar6);
    if (iVar7 == 1) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
      fVar1 = 0.0;
      if (0 < svs.maxclients) {
        iVar7 = 0;
        iVar10 = 0;
        pcVar9 = svs.clients;
        do {
          if (((pcVar9->active != false) || (pcVar9->spawned != false)) ||
             (pcVar9->connected != false)) {
            iVar7 = (iVar7 + 1) - (uint)(pcVar9->proxy == false);
          }
          iVar10 = iVar10 + 1;
          pcVar9 = pcVar9 + 1;
        } while (iVar10 != svs.maxclients);
        fVar1 = (float)iVar7;
      }
      if ((sv_proxies.value <= fVar1) && (bIsReconnecting == false)) {
        SV_RejectConnection(adr,"Proxy slots are full.\n");
        return 0;
      }
      return 1;
    }
    if (iVar7 == 3) {
      SV_RejectConnection(adr,"Please connect to HLTV master proxy.\n");
      return 0;
    }
    if (iVar7 == 0) {
      return 1;
    }
  }
  SV_RejectConnection(adr,"Unknown HLTV client type.\n");
  return 0;
}


// SV_CheckVelocity  @ 000b1880
void SV_CheckVelocity(edict_t_conflict *ent)

{
  float fVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???] */
  uVar2 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[0] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar2 = nanmask;
    (ent->v).velocity[0] = 0.0;
  }
  if (((uint)(ent->v).origin[0] & uVar2) == uVar2) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[0] = 0.0;
  }
  fVar1 = (ent->v).velocity[0];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = -sv_maxvelocity.value;
  }
  uVar2 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[1] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar2 = nanmask;
    (ent->v).velocity[1] = 0.0;
  }
  if (((uint)(ent->v).origin[1] & uVar2) == uVar2) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[1] = 0.0;
  }
  fVar1 = (ent->v).velocity[1];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = -sv_maxvelocity.value;
  }
  uVar2 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[2] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar2 = nanmask;
    (ent->v).velocity[2] = 0.0;
  }
  if (((uint)(ent->v).origin[2] & uVar2) == uVar2) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[2] = 0.0;
  }
  fVar1 = (ent->v).velocity[2];
  if (fVar1 <= sv_maxvelocity.value) {
    if (-sv_maxvelocity.value <= fVar1) {
      return;
    }
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[2] = -sv_maxvelocity.value;
    return;
  }
  Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
  (ent->v).velocity[2] = sv_maxvelocity.value;
  return;
}


// SV_CheckVisibility  @ 000a5040
int SV_CheckVisibility(edict_s *entity,uchar *pset)

{
  int iVar1;
  int iVar2;
  qboolean qVar3;
  int local_2c [7];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean visible@[???]
                       Unresolved local var: edict_t.conflict * e@[???] */
  iVar2 = 1;
  if (pset != (uchar *)0x0) {
    iVar2 = 0;
    if (entity->headnode < 0) {
      iVar2 = 0;
      if ((0 < entity->num_leafs) &&
         (iVar2 = 1,
         ((int)(uint)pset[(int)entity->leafnums[0] >> 3] >> ((byte)entity->leafnums[0] & 7) & 1U) ==
         0)) {
        iVar2 = 0;
        do {
          if (iVar2 + 1 == entity->num_leafs) {
            return 0;
          }
          iVar1 = iVar2 + 1;
          iVar2 = iVar2 + 1;
        } while (((int)(uint)pset[(int)entity->leafnums[iVar1] >> 3] >>
                  ((byte)entity->leafnums[iVar1] & 7) & 1U) == 0);
        return 1;
      }
    }
    else {
      do {
        local_2c[0] = (int)entity->leafnums[iVar2];
        if (local_2c[0] == -1) {
          local_2c[0] = -1;
          break;
        }
                    /* Unresolved local var: int leaf@[???] */
        if (((int)(uint)pset[local_2c[0] >> 3] >> ((byte)entity->leafnums[iVar2] & 7) & 1U) != 0) {
          return 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x30);
      qVar3 = CM_HeadnodeVisible((sv.worldmodel)->nodes + entity->headnode,pset,local_2c);
      iVar2 = 0;
      if (qVar3 != false) {
        iVar1 = entity->num_leafs;
        entity->leafnums[iVar1] = (short)local_2c[0];
        iVar2 = 2;
        entity->num_leafs = (iVar1 + 1) % 0x30;
      }
    }
  }
  return iVar2;
}


// SV_CheckWater  @ 000b37b0
qboolean SV_CheckWater(edict_t_conflict *ent)

{
  vec_t *veca;
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t point@[???]
                       Unresolved local var: int cont@[???]
                       Unresolved local var: int truecont@[???] */
  g_groupmask = (ent->v).groupinfo;
  (ent->v).waterlevel = 0;
  (ent->v).watertype = -1;
  local_28 = ((ent->v).absmin[0] + (ent->v).absmax[0]) * 0.5;
  local_24 = ((ent->v).absmin[1] + (ent->v).absmax[1]) * 0.5;
  local_20 = (ent->v).absmin[2] + 1.0;
  iVar3 = SV_PointContents(&local_28);
  if (iVar3 + 0xeU < 0xc) {
    fVar1 = (ent->v).absmin[2];
    fVar2 = (ent->v).absmax[2];
    (ent->v).watertype = iVar3;
    (ent->v).waterlevel = 1;
    if (fVar1 == fVar2) {
LAB_000b385c:
      (ent->v).waterlevel = 3;
      iVar4 = 3;
    }
    else {
      g_groupmask = (ent->v).groupinfo;
      local_20 = (fVar1 + fVar2) * 0.5;
      iVar4 = SV_PointContents(&local_28);
      if (iVar4 + 0xeU < 0xc) {
        local_28 = local_28 + (ent->v).view_ofs[0];
        g_groupmask = (ent->v).groupinfo;
        (ent->v).waterlevel = 2;
        local_24 = local_24 + (ent->v).view_ofs[1];
        local_20 = local_20 + (ent->v).view_ofs[2];
        iVar4 = SV_PointContents(&local_28);
        if (iVar4 + 0xeU < 0xc) goto LAB_000b385c;
      }
      iVar4 = (ent->v).waterlevel;
    }
    if (5 < iVar3 + 0xeU) goto LAB_000b38b0;
    veca = (ent->v).basevelocity;
    VectorMA(veca,(float)iVar4 * 50.0,SV_CheckWater::lexical_block_0::current_table[-9 - iVar3],veca
            );
  }
  iVar4 = (ent->v).waterlevel;
LAB_000b38b0:
  return (uint)(1 < iVar4);
}


// SV_CheckWaterTransition  @ 000b4910
void SV_CheckWaterTransition(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int cont@[???]
                       Unresolved local var: vec3_t point@[???] */
  g_groupmask = (ent->v).groupinfo;
  local_18 = ((ent->v).absmin[0] + (ent->v).absmax[0]) * 0.5;
  local_14 = ((ent->v).absmin[1] + (ent->v).absmax[1]) * 0.5;
  local_10 = (ent->v).absmin[2] + 1.0;
  iVar3 = SV_PointContents(&local_18);
  iVar4 = (ent->v).watertype;
  if (iVar4 == 0) {
    (ent->v).watertype = iVar3;
    (ent->v).waterlevel = 1;
    return;
  }
  if (iVar3 + 0xeU < 0xc) {
    if (iVar4 == -1) {
      SV_StartSound(0,ent,0,"player/pl_wade1.wav",0xff,1.0,0,100);
      (ent->v).velocity[2] = (ent->v).velocity[2] * 0.5;
    }
    fVar1 = (ent->v).absmin[2];
    fVar2 = (ent->v).absmax[2];
    (ent->v).watertype = iVar3;
    (ent->v).waterlevel = 1;
    if (fVar1 == fVar2) {
LAB_000b49b6:
      (ent->v).waterlevel = 3;
      return;
    }
    g_groupmask = (ent->v).groupinfo;
    local_10 = (fVar1 + fVar2) * 0.5;
    iVar4 = SV_PointContents(&local_18);
    if (iVar4 + 0xeU < 0xc) {
      local_18 = local_18 + (ent->v).view_ofs[0];
      (ent->v).waterlevel = 2;
      g_groupmask = (ent->v).groupinfo;
      local_14 = local_14 + (ent->v).view_ofs[1];
      local_10 = local_10 + (ent->v).view_ofs[2];
      iVar4 = SV_PointContents(&local_18);
      if (iVar4 + 0xeU < 0xc) goto LAB_000b49b6;
    }
  }
  else {
    if (iVar4 != -1) {
      SV_StartSound(0,ent,0,"player/pl_wade2.wav",0xff,1.0,0,100);
    }
    (ent->v).watertype = -1;
    (ent->v).waterlevel = 0;
  }
  return;
}


// SV_CleanupEnts  @ 000a5770
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CleanupEnts(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: edict_t.conflict * ent@[???] */
  if (1 < sv.num_edicts) {
    iVar2 = 1;
    iVar3 = 0x324;
    do {
      iVar2 = iVar2 + 1;
      puVar1 = (uint *)((int)((sv.edicts)->v).size + iVar3 + 0x24);
      *puVar1 = *puVar1 & 0xffffffdd;
      iVar3 = iVar3 + 0x324;
    } while (iVar2 < sv.num_edicts);
  }
  return;
}


// SV_ClearCaches  @ 000a6e60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearCaches(void)

{
  char **ppcVar1;
  
                    /* Unresolved local var: int i@[???] */
  ppcVar1 = &sv.event_precache[1].filename;
  do {
    if (*ppcVar1 == (char *)0x0) {
      return;
    }
    *ppcVar1 = (char *)0x0;
    if (ppcVar1[2] != (char *)0x0) {
      Mem_Free(ppcVar1[2]);
    }
    ppcVar1[2] = (char *)0x0;
    ppcVar1 = ppcVar1 + 4;
  } while (ppcVar1 != sv.sound_precache + 1);
  return;
}


// SV_ClearClientStates  @ 00074ae0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearClientStates(void)

{
  client_s *cl;
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar1 = 0;
    cl = svs.clients;
    do {
      iVar1 = iVar1 + 1;
      COM_ClearCustomizationList(&cl->customdata,false);
      SV_ClearResourceLists(cl);
      cl = cl + 1;
    } while (iVar1 < svs.maxclients);
  }
  return;
}


// SV_ClearEntities  @ 000a8750
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearEntities(void)

{
  edict_t_conflict *pEdict;
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < sv.num_edicts) {
    iVar3 = 0;
    iVar2 = 0;
    iVar1 = sv.num_edicts;
    do {
                    /* Unresolved local var: edict_t.conflict * pEdict@[???] */
      while (pEdict = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar3 + -0x18),
            pEdict->free == 0) {
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x324;
        ReleaseEntityDLLFields(pEdict);
        iVar1 = sv.num_edicts;
        if (sv.num_edicts <= iVar2) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x324;
    } while (iVar2 < iVar1);
  }
  return;
}


// SV_ClearFrames  @ 0009c8a0
void SV_ClearFrames(client_frame_t **frames)

{
  entity_state_s *p;
  client_frame_t *p_00;
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
  p_00 = *frames;
  if (p_00 != (client_frame_t *)0x0) {
    if (0 < SV_UPDATE_BACKUP) {
      iVar1 = 0;
      do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
        if (p_00 != (client_frame_t *)0x0) {
          p = (p_00->entities).entities;
          if (p != (entity_state_s *)0x0) {
            Mem_Free(p);
          }
          (p_00->entities).entities = (entity_state_s *)0x0;
          (p_00->entities).num_entities = 0;
        }
        *(undefined4 *)&p_00->senttime = 0;
        iVar1 = iVar1 + 1;
        *(undefined4 *)((int)&p_00->senttime + 4) = 0;
        p_00->ping_time = -1.0;
        p_00 = p_00 + 1;
      } while (iVar1 < SV_UPDATE_BACKUP);
      p_00 = *frames;
    }
    Mem_Free(p_00);
    *frames = (client_frame_t *)0x0;
  }
  return;
}


// SV_ClearPacketEntities  @ 0009c7f0
void SV_ClearPacketEntities(client_frame_t *frame)

{
  entity_state_s *p;
  
                    /* Unresolved local var: packet_entities_t * pack@[???] */
  if (frame != (client_frame_t *)0x0) {
    p = (frame->entities).entities;
    if (p != (entity_state_s *)0x0) {
      Mem_Free(p);
    }
    (frame->entities).entities = (entity_state_s *)0x0;
    (frame->entities).num_entities = 0;
  }
  return;
}


// SV_ClearResourceList  @ 000b7050
void SV_ClearResourceList(resource_t *pList)

{
  resource_s *prVar1;
  resource_t *p;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  p = pList->pNext;
  while ((pList != p && (p != (resource_t *)0x0))) {
    prVar1 = p->pNext;
    p->pPrev->pNext = prVar1;
    p->pNext->pPrev = p->pPrev;
    p->pPrev = (resource_s *)0x0;
    p->pNext = (resource_s *)0x0;
    Mem_Free(p);
    p = prVar1;
  }
  pList->pPrev = pList;
  pList->pNext = pList;
  return;
}


// SV_ClearResourceLists  @ 000b6ac0
void SV_ClearResourceLists(client_t *cl)

{
  resource_t *prVar1;
  resource_s *prVar2;
  resource_s *prVar3;
  
  if (cl == (client_t *)0x0) {
    Sys_Error("SV_ClearResourceLists with NULL client!");
  }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar1 = &cl->resourcesneeded;
  prVar3 = (cl->resourcesneeded).pNext;
  while ((prVar1 != prVar3 && (prVar3 != (resource_s *)0x0))) {
    prVar2 = prVar3->pNext;
    prVar3->pPrev->pNext = prVar2;
    prVar3->pNext->pPrev = prVar3->pPrev;
    prVar3->pPrev = (resource_s *)0x0;
    prVar3->pNext = (resource_s *)0x0;
    Mem_Free(prVar3);
    prVar3 = prVar2;
  }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar3 = (cl->resourcesonhand).pNext;
  (cl->resourcesneeded).pPrev = prVar1;
  (cl->resourcesneeded).pNext = prVar1;
  prVar1 = &cl->resourcesonhand;
  if ((prVar3 != (resource_s *)0x0) && (prVar1 != prVar3)) {
    do {
      prVar2 = prVar3->pNext;
      prVar3->pPrev->pNext = prVar2;
      prVar3->pNext->pPrev = prVar3->pPrev;
      prVar3->pPrev = (resource_s *)0x0;
      prVar3->pNext = (resource_s *)0x0;
      Mem_Free(prVar3);
      if (prVar1 == prVar2) break;
      prVar3 = prVar2;
    } while (prVar2 != (resource_s *)0x0);
  }
  (cl->resourcesonhand).pPrev = prVar1;
  (cl->resourcesonhand).pNext = prVar1;
  return;
}


// SV_ClearWorld  @ 000bf3a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearWorld(void)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  box_hull.firstclipnode = 0;
  box_hull.lastclipnode = 5;
  uVar1 = 0;
  box_hull.clipnodes = box_clipnodes;
  box_hull.planes = box_planes;
  do {
    *(undefined4 *)((int)beam_hull.clip_mins + (uVar1 - 0x10)) =
         *(undefined4 *)((int)box_hull.clip_mins + (uVar1 - 0x10));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x28);
  beam_hull.planes = beam_planes;
  box_clipnodes[0].planenum = 0;
  box_clipnodes[0].children[0] = -1;
  box_clipnodes[0].children[1] = 1;
  box_clipnodes[1].planenum = 1;
  box_clipnodes[1].children[1] = -1;
  box_clipnodes[2].children[0] = -1;
  box_clipnodes[2].children[1] = 3;
  box_clipnodes[3].planenum = 3;
  box_clipnodes[3].children[1] = -1;
  box_clipnodes[3].children[0] = 4;
  box_clipnodes[4].planenum = 4;
  box_clipnodes[5].planenum = 5;
  box_clipnodes[1].children[0] = 2;
  box_clipnodes[2].planenum = 2;
  box_clipnodes[5].children[1] = -1;
  box_clipnodes[4].children[0] = -1;
  box_clipnodes[4].children[1] = 5;
  box_planes[0].type = '\0';
  box_planes[0].normal[0] = 1.0;
  beam_planes[0].type = '\x05';
  box_planes[1].type = '\0';
  box_planes[1].normal[0] = 1.0;
  beam_planes[1].type = '\x05';
  box_planes[2].type = '\x01';
  box_planes[2].normal[1] = 1.0;
  beam_planes[2].type = '\x05';
  box_planes[3].type = '\x01';
  box_planes[3].normal[1] = 1.0;
  beam_planes[3].type = '\x05';
  box_planes[4].type = '\x02';
  box_planes[4].normal[2] = 1.0;
  beam_planes[4].type = '\x05';
  box_clipnodes[5].children[0] = -2;
  box_planes[5].type = '\x02';
  box_planes[5].normal[2] = 1.0;
  beam_planes[5].type = '\x05';
  Q_memset(sv_areanodes,0,0x400);
  sv_numareanodes = 0;
  SV_CreateAreaNode(0,(sv.worldmodel)->mins,(sv.worldmodel)->maxs);
  return;
}


// SV_ClientPrintf  @ 00073ec0
void SV_ClientPrintf(char *fmt,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  if (host_client->fakeclient == false) {
    vsnprintf(local_40c,0x400,fmt,&stack0x00000008);
    MSG_WriteByte(&(host_client->netchan).message,8);
    MSG_WriteString(&(host_client->netchan).message,local_40c);
  }
  return;
}


// SV_ClipMoveToEntity  @ 000c0a90
trace_t * SV_ClipMoveToEntity(trace_t *__return_storage_ptr__,edict_t_conflict *ent,vec_t *start,
                             vec_t *mins,vec_t *maxs,vec_t *end)

{
  uint uVar1;
  trace_t local_44;
  
                    /* Unresolved local var: trace_t goodtrace@[???] */
  SV_SingleClipMoveToEntity(ent,start,mins,maxs,end,&local_44);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_44.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  return __return_storage_ptr__;
}


// SV_ClipToLinks  @ 000c0af0
void SV_ClipToLinks(areanode_t *node,moveclip_t *clip)

{
  edict_t_conflict *ent;
  link_s *plVar1;
  link_s *plVar2;
  edict_t_conflict *peVar3;
  link_s *plVar4;
  int iVar5;
  qboolean qVar6;
  uint uVar7;
  undefined4 local_8c [14];
  trace_t local_54;
  
                    /* Unresolved local var: link_t * l@[???]
                       Unresolved local var: link_t * next@[???]
                       Unresolved local var: edict_t.conflict * touch@[???]
                       Unresolved local var: trace_t trace@[???] */
  do {
    plVar2 = (node->solid_edicts).next;
joined_r0x000c0b1e:
    while (plVar4 = plVar2, plVar4 != &node->solid_edicts) {
      plVar1 = plVar4[0x57].prev;
      plVar2 = plVar4->next;
      if (((plVar1 == (link_s *)0x0) || (clip->passedict == (edict_t_conflict *)0x0)) ||
         (uVar7 = (clip->passedict->v).groupinfo, uVar7 == 0)) goto LAB_000c0b70;
      if (g_groupop != 0) goto LAB_000c0e18;
      if ((uVar7 & (uint)plVar1) != 0) goto LAB_000c0b70;
    }
    iVar5 = node->axis;
    if (iVar5 == -1) {
      return;
    }
    if (node->dist < clip->boxmaxs[iVar5]) {
      SV_ClipToLinks(node->children[0],clip);
      if (node->dist <= clip->boxmins[node->axis]) {
        return;
      }
    }
    else if (node->dist <= clip->boxmins[iVar5]) {
      return;
    }
    node = node->children[1];
  } while( true );
LAB_000c0e18:
  if ((g_groupop != 1) || ((uVar7 & (uint)plVar1) == 0)) {
LAB_000c0b70:
    if ((plVar4[0x30].next != (link_s *)0x0) &&
       (ent = (edict_t_conflict *)(plVar4 + -1), clip->passedict != ent)) {
      if (plVar4[0x30].next == (link_s *)0x1) {
        Sys_Error("Trigger in clipping list");
      }
      if ((gNewDLLFunctions.pfnShouldCollide == (_func_int_edict_t_ptr_edict_t_ptr *)0x0) ||
         (iVar5 = (*gNewDLLFunctions.pfnShouldCollide)(ent,clip->passedict), iVar5 != 0)) {
        if (plVar4[0x30].next == (link_s *)0x4) {
          if ((((uint)plVar4[0x43].next & 0x800000) != 0) && (clip->monsterClipBrush == false))
          goto joined_r0x000c0b1e;
        }
        else if ((clip->type == 1) && (plVar4[0x30].prev != (link_s *)0xd)) goto joined_r0x000c0b1e;
        if ((((((clip->ignoretrans == 0) || (plVar4[0x38].prev == (link_s *)0x0)) ||
              (((uint)plVar4[0x43].next & 0x2000000) != 0)) &&
             (((clip->boxmins[0] <= (float)plVar4[0x29].prev &&
               (clip->boxmins[1] <= (float)plVar4[0x29].next)) &&
              (clip->boxmins[2] <= (float)plVar4[0x2a].prev)))) &&
            (((float)plVar4[0x27].next <= clip->boxmaxs[0] &&
             ((float)plVar4[0x28].prev <= clip->boxmaxs[1])))) &&
           ((((float)plVar4[0x28].next <= clip->boxmaxs[2] &&
             ((plVar4[0x30].next == (link_s *)0x3 ||
              (qVar6 = SV_CheckSphereIntersection(ent,clip->start,clip->end), qVar6 != false)))) &&
            ((peVar3 = clip->passedict, peVar3 == (edict_t_conflict *)0x0 ||
             (((peVar3->v).size[0] == 0.0 || ((float)plVar4[0x2d].next != 0.0)))))))) {
          if ((clip->trace).allsolid != false) {
            return;
          }
          if ((peVar3 == (edict_t_conflict *)0x0) ||
             ((peVar3 != (edict_t_conflict *)plVar4[0x42].prev && ((peVar3->v).owner != ent)))) {
            if (((uint)plVar4[0x43].next & 0x20) == 0) {
              SV_SingleClipMoveToEntity(ent,clip->start,clip->mins,clip->maxs,clip->end,&local_54);
              uVar7 = 0;
              do {
                *(undefined4 *)((int)local_8c + uVar7) =
                     *(undefined4 *)((int)local_54.endpos + (uVar7 - 0x14));
                uVar7 = uVar7 + 4;
              } while (uVar7 < 0x38);
            }
            else {
                    /* Unresolved local var: trace_t goodtrace@[???] */
              SV_SingleClipMoveToEntity(ent,clip->start,clip->mins2,clip->maxs2,clip->end,&local_54)
              ;
              uVar7 = 0;
              do {
                *(undefined4 *)((int)local_8c + uVar7) =
                     *(undefined4 *)((int)local_54.endpos + (uVar7 - 0x14));
                uVar7 = uVar7 + 4;
              } while (uVar7 < 0x38);
            }
                    /* Unresolved local var: trace_t goodtrace@[???] */
            if (((local_54.allsolid != false) || (local_54.startsolid != false)) ||
               (local_54.fraction < (clip->trace).fraction)) {
              if ((clip->trace).startsolid == false) {
                uVar7 = 0;
                do {
                  *(undefined4 *)((int)(clip->trace).endpos + (uVar7 - 0x14)) =
                       *(undefined4 *)((int)local_8c + uVar7);
                  uVar7 = uVar7 + 4;
                } while (uVar7 < 0x38);
                (clip->trace).fraction = local_54.fraction;
                (clip->trace).ent = ent;
                (clip->trace).allsolid = local_54.allsolid;
                (clip->trace).startsolid = local_54.startsolid;
              }
              else {
                uVar7 = 0;
                do {
                  *(undefined4 *)((int)(clip->trace).endpos + (uVar7 - 0x14)) =
                       *(undefined4 *)((int)local_8c + uVar7);
                  uVar7 = uVar7 + 4;
                } while (uVar7 < 0x38);
                (clip->trace).fraction = local_54.fraction;
                (clip->trace).ent = ent;
                (clip->trace).startsolid = true;
                (clip->trace).allsolid = local_54.allsolid;
              }
            }
          }
        }
      }
    }
  }
  goto joined_r0x000c0b1e;
}


// SV_ClipToWorldbrush  @ 000c0f70
void SV_ClipToWorldbrush(areanode_t *node,moveclip_t *clip)

{
  edict_t_conflict *ent;
  link_s *plVar1;
  int iVar2;
  link_s *plVar3;
  uint uVar4;
  undefined4 auStack_8c [14];
  trace_t local_54;
  
  while( true ) {
    plVar1 = (node->solid_edicts).next;
    while (plVar3 = plVar1, plVar3 != &node->solid_edicts) {
      plVar1 = plVar3->next;
      if ((((plVar3[0x30].next == (link_s *)0x4) &&
           (ent = (edict_t_conflict *)(plVar3 + -1), clip->passedict != ent)) &&
          (((uint)plVar3[0x43].next & 0x2000000) != 0)) &&
         ((((clip->boxmins[0] <= (float)plVar3[0x29].prev &&
            (clip->boxmins[1] <= (float)plVar3[0x29].next)) &&
           ((clip->boxmins[2] <= (float)plVar3[0x2a].prev &&
            (((float)plVar3[0x27].next <= clip->boxmaxs[0] &&
             ((float)plVar3[0x28].prev <= clip->boxmaxs[1])))))) &&
          ((float)plVar3[0x28].next <= clip->boxmaxs[2])))) {
        if ((clip->trace).allsolid != false) {
          return;
        }
                    /* Unresolved local var: trace_t goodtrace@[???] */
        SV_SingleClipMoveToEntity(ent,clip->start,clip->mins,clip->maxs,clip->end,&local_54);
        uVar4 = 0;
        do {
          *(undefined4 *)((int)auStack_8c + uVar4) =
               *(undefined4 *)((int)local_54.endpos + (uVar4 - 0x14));
          uVar4 = uVar4 + 4;
        } while (uVar4 < 0x38);
        if (((local_54.allsolid != false) || (local_54.startsolid != false)) ||
           (local_54.fraction < (clip->trace).fraction)) {
          if ((clip->trace).startsolid == false) {
            uVar4 = 0;
            do {
              *(undefined4 *)((int)(clip->trace).endpos + (uVar4 - 0x14)) =
                   *(undefined4 *)((int)auStack_8c + uVar4);
              uVar4 = uVar4 + 4;
            } while (uVar4 < 0x38);
            (clip->trace).fraction = local_54.fraction;
            (clip->trace).ent = ent;
            (clip->trace).startsolid = local_54.startsolid;
            (clip->trace).allsolid = local_54.allsolid;
          }
          else {
            uVar4 = 0;
            do {
              *(undefined4 *)((int)(clip->trace).endpos + (uVar4 - 0x14)) =
                   *(undefined4 *)((int)auStack_8c + uVar4);
              uVar4 = uVar4 + 4;
            } while (uVar4 < 0x38);
            (clip->trace).fraction = local_54.fraction;
            (clip->trace).ent = ent;
            (clip->trace).startsolid = true;
            (clip->trace).allsolid = local_54.allsolid;
          }
        }
      }
    }
    iVar2 = node->axis;
    if (iVar2 == -1) break;
    if (node->dist < clip->boxmaxs[iVar2]) {
      SV_ClipToWorldbrush(node->children[0],clip);
      if (node->dist <= clip->boxmins[node->axis]) {
        return;
      }
    }
    else if (node->dist <= clip->boxmins[iVar2]) {
      return;
    }
    node = node->children[1];
  }
  return;
}


// SV_CloseEnough  @ 000b0640
qboolean SV_CloseEnough(edict_t_conflict *ent,edict_t_conflict *goal,float dist)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???] */
  qVar1 = false;
  if (((((goal->v).absmin[0] <= (ent->v).absmax[0] + dist) &&
       ((ent->v).absmin[0] - dist <= (goal->v).absmax[0])) &&
      ((goal->v).absmin[1] <= (ent->v).absmax[1] + dist)) &&
     (((ent->v).absmin[1] - dist <= (goal->v).absmax[1] &&
      ((goal->v).absmin[2] <= (ent->v).absmax[2] + dist)))) {
    qVar1 = (qboolean)((ent->v).absmin[2] - dist <= (goal->v).absmax[2]);
  }
  return qVar1;
}


// SV_CompareUserID  @ 000abb40
qboolean SV_CompareUserID(USERID_t *id1,USERID_t *id2)

{
  qboolean qVar1;
  char *pcVar2;
  int iVar3;
  char local_8c [63];
  undefined1 local_4d;
  char local_4c [63];
  undefined1 local_d;
  
  if ((id2 == (USERID_t *)0x0) || (id1 == (USERID_t *)0x0)) {
    qVar1 = false;
  }
  else {
    qVar1 = false;
    if ((id1->idtype == id2->idtype) && (id1->idtype - 1U < 2)) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
      pcVar2 = SV_GetIDString(id1);
      strncpy(local_8c,pcVar2,0x3f);
      local_4d = 0;
      pcVar2 = SV_GetIDString(id2);
      strncpy(local_4c,pcVar2,0x3f);
      local_d = 0;
      iVar3 = strcasecmp(local_8c,local_4c);
      qVar1 = (qboolean)(iVar3 == 0);
    }
  }
  return qVar1;
}


// SV_ComputeLatency  @ 000b9ac0
void SV_ComputeLatency(client_t *cl)

{
  float fVar1;
  
  fVar1 = SV_CalcClientTime(cl);
  cl->latency = fVar1;
  return;
}


// SV_ConnectClient  @ 000acb50
/* WARNING: Removing unreachable block (ram,0x000ad625) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ConnectClient(void)

{
  resource_t *prVar1;
  bool bVar2;
  netadr_t adr;
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t a_02;
  netadr_t a_03;
  netadr_t a_04;
  netadr_t a_05;
  netadr_t a_06;
  netadr_t adr_00;
  netadr_t adr_01;
  netadr_t b;
  int iVar3;
  char *pcVar4;
  qboolean qVar5;
  netadrtype_t nVar6;
  char *pcVar7;
  client_frame_t *pcVar8;
  edict_t_conflict *peVar9;
  client_t *pcVar10;
  qboolean qVar11;
  uint uVar12;
  ushort uVar13;
  client_t *pcVar14;
  byte *pbVar15;
  int iVar16;
  netadr_t *pnVar17;
  netadr_t *pnVar18;
  netadrtype_t *pnVar19;
  netadrtype_t *pnVar20;
  netadrtype_t *pnVar21;
  netadrtype_t *pnVar22;
  undefined4 *puVar23;
  byte bVar24;
  client_t *pcVar25;
  usercmd_t *dest;
  netadrtype_t nVar26;
  netadrtype_t nVar27;
  char *userinfo;
  netadrtype_t in_stack_fffff118;
  uchar in_stack_fffff11c [4];
  code *pfnNetchan_Blocksize;
  char *local_ec4;
  ushort local_ec0;
  char local_ebc [1023];
  undefined1 local_abd;
  char local_abc [1023];
  undefined1 local_6bd;
  undefined4 local_6bc [383];
  undefined1 local_bd;
  char local_bc [64];
  char local_7c [32];
  undefined1 local_5c [8];
  uchar local_54 [4];
  uchar local_50 [6];
  ushort uStack_4a;
  client_t *local_3c;
  qboolean local_2c [7];
  
                    /* Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: int edictnum@[???]
                       Unresolved local var: int nClientSlot@[???]
                       Unresolved local var: char[1024] userinfo@[???]
                       Unresolved local var: char[1024] protinfo@[???]
                       Unresolved local var: char[64] cdkey@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[512] szRawCertificate@[???]
                       Unresolved local var: int nAuthProtocol@[???]
                       Unresolved local var: ushort port@[???]
                       Unresolved local var: qboolean reconnect@[???]
                       Unresolved local var: qboolean bIsSecure@[???] */
  bVar24 = 0;
  pnVar19 = (netadrtype_t *)&stack0xfffff104;
  pnVar20 = (netadrtype_t *)&stack0xfffff104;
  pnVar21 = (netadrtype_t *)&stack0xfffff104;
  pnVar22 = (netadrtype_t *)&stack0xfffff104;
  local_3c = (client_t *)0x0;
  local_5c._0_4_ = net_from.type;
  local_5c._4_4_ = net_from.ip;
  local_54 = (uchar  [4])net_from.ipx._0_4_;
  local_50._0_4_ = net_from.ipx._4_4_;
  stack0xffffffb4 = net_from._16_4_;
  Q_atoi("27005");
  iVar3 = Cmd_Argc();
  if (iVar3 < 5) {
    SV_RejectConnection((netadr_t *)local_5c,"Insufficient connection info\n");
    return;
  }
  pcVar4 = Cmd_Argv(1);
  iVar3 = Q_atoi(pcVar4);
  if (iVar3 != 0x30) {
    if (0x30 < iVar3) {
      Q_strlen(sv_contact.string);
      SV_RejectConnection((netadr_t *)local_5c,
                          "This server is using an older protocol ( %i ) than your client ( %i ).  If you believe this server is outdated, you can contact the server administrator at %s.\n"
                         );
      return;
    }
    SV_RejectConnection((netadr_t *)local_5c,
                        "This server is using a newer protocol ( %i ) than your client ( %i ).  You should check for updates to your client.\n"
                       );
    return;
  }
                    /* Unresolved local var: int i@[???] */
  iVar16 = 0;
  pcVar4 = Cmd_Argv(2);
  iVar3 = Q_atoi(pcVar4);
  adr.ip[0] = local_5c[4];
  adr.ip[1] = local_5c[5];
  adr.ip[2] = local_5c[6];
  adr.ip[3] = local_5c[7];
  adr.type = local_5c._0_4_;
  adr.ipx[0] = local_54[0];
  adr.ipx[1] = local_54[1];
  adr.ipx[2] = local_54[2];
  adr.ipx[3] = local_54[3];
  adr.ipx[4] = local_50[0];
  adr.ipx[5] = local_50[1];
  adr.ipx[6] = local_50[2];
  adr.ipx[7] = local_50[3];
  adr.ipx[8] = local_50[4];
  adr.ipx[9] = local_50[5];
  adr.port = uStack_4a;
  qVar5 = NET_IsLocalAddress(adr);
  if (qVar5 == false) {
    while( true ) {
      in_stack_fffff118 = g_rg_sv_challenges[iVar16].adr.type;
      in_stack_fffff11c = *&g_rg_sv_challenges[iVar16].adr.ip;
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
      qVar5 = NET_CompareBaseAdr(a,g_rg_sv_challenges[iVar16].adr);
      if (qVar5 != false) break;
                    /* Unresolved local var: int i@[???] */
      iVar16 = iVar16 + 1;
      if (iVar16 == 0x400) {
        SV_RejectConnection((netadr_t *)local_5c,"No challenge for your address.\n");
        return;
      }
    }
    if (iVar3 != g_rg_sv_challenges[iVar16].challenge) {
      SV_RejectConnection((netadr_t *)local_5c,"Bad challenge.\n");
      return;
    }
  }
  pcVar10 = (client_t *)(local_6bc + 0x100);
  Q_memset(pcVar10,0,0x200);
  pcVar4 = Cmd_Argv(3);
  iVar3 = Info_IsValid(pcVar4);
  if (iVar3 == 0) {
    SV_RejectConnection((netadr_t *)local_5c,"Invalid protinfo in connect command\n");
    return;
  }
  Q_strncpy(local_abc,pcVar4,0x3ff);
  local_6bd = 0;
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nAuthProtocol@[???] */
  pcVar4 = Info_ValueForKey(local_abc,"prot");
  nVar6 = Q_atoi(pcVar4);
  if (3 < nVar6 - NA_LOOPBACK) {
    SV_RejectConnection((netadr_t *)local_5c,"Invalid connection.\n");
    return;
  }
  pcVar4 = Info_ValueForKey(local_abc,"raw");
  iVar3 = Q_strlen(pcVar4);
  if (iVar3 < 1) {
LAB_000acf16:
    SV_RejectConnection((netadr_t *)local_5c,"Invalid authentication certificate length.\n");
  }
  else {
    if (nVar6 == NA_BROADCAST) {
      iVar3 = Q_strlen(pcVar4);
      if (iVar3 != 0x20) goto LAB_000acf16;
      Q_strncpy((char *)pcVar10,pcVar4,0x200);
      local_bd = 0;
      Q_strncpy(local_bc,pcVar4,0x40);
    }
    else {
      Q_strncpy((char *)pcVar10,pcVar4,0x200);
      local_bd = 0;
      pcVar4 = Info_ValueForKey(local_abc,"cdkey");
      iVar3 = Q_strlen(pcVar4);
      if (iVar3 != 0x20) {
        SV_RejectConnection((netadr_t *)local_5c,"Invalid hashed CD key.\n");
        return;
      }
      Q_strncpy(local_bc,pcVar4,0x40);
    }
    local_ec4 = local_bc;
    iVar3 = Q_atoi("27005");
    bVar2 = true;
    if ((((sv_lan.value == 0.0) && (bVar2 = false, nVar6 == NA_IP)) || (nVar6 == NA_BROADCAST)) ||
       ((bVar2 && ((a_00.ip[0] = local_5c[4], a_00.ip[1] = local_5c[5], a_00.ip[2] = local_5c[6],
                   a_00.ip[3] = local_5c[7], a_00.type = local_5c._0_4_, a_00.ipx[0] = local_54[0],
                   a_00.ipx[1] = local_54[1], a_00.ipx[2] = local_54[2], a_00.ipx[3] = local_54[3],
                   a_00.ipx[4] = local_50[0], a_00.ipx[5] = local_50[1], a_00.ipx[6] = local_50[2],
                   a_00.ipx[7] = local_50[3], a_00.ipx[8] = local_50[4], a_00.ipx[9] = local_50[5],
                   a_00.port = uStack_4a, b.ip[0] = net_local_adr.ip[0],
                   b.ip[1] = net_local_adr.ip[1], b.ip[2] = net_local_adr.ip[2],
                   b.ip[3] = net_local_adr.ip[3], b.type = net_local_adr.type,
                   b.ipx[0] = net_local_adr.ipx[0], b.ipx[1] = net_local_adr.ipx[1],
                   b.ipx[2] = net_local_adr.ipx[2], b.ipx[3] = net_local_adr.ipx[3],
                   b.ipx[4] = net_local_adr.ipx[4], b.ipx[5] = net_local_adr.ipx[5],
                   b.ipx[6] = net_local_adr.ipx[6], b.ipx[7] = net_local_adr.ipx[7],
                   b.ipx[8] = net_local_adr.ipx[8], b.ipx[9] = net_local_adr.ipx[9],
                   b.port = net_local_adr.port, in_stack_fffff118 = net_local_adr.type,
                   in_stack_fffff11c = net_local_adr.ip, qVar5 = NET_CompareClassBAdr(a_00,b),
                   qVar5 != false ||
                   (a_02.ip[0] = local_5c[4], a_02.ip[1] = local_5c[5], a_02.ip[2] = local_5c[6],
                   a_02.ip[3] = local_5c[7], a_02.type = local_5c._0_4_, a_02.ipx[0] = local_54[0],
                   a_02.ipx[1] = local_54[1], a_02.ipx[2] = local_54[2], a_02.ipx[3] = local_54[3],
                   a_02.ipx[4] = local_50[0], a_02.ipx[5] = local_50[1], a_02.ipx[6] = local_50[2],
                   a_02.ipx[7] = local_50[3], a_02.ipx[8] = local_50[4], a_02.ipx[9] = local_50[5],
                   a_02.port = uStack_4a, qVar5 = NET_IsReservedAdr(a_02), qVar5 != false)))))) {
      pcVar4 = Cmd_Argv(4);
      iVar16 = Q_strlen(pcVar4);
      if ((iVar16 < 0x101) && (iVar16 = Info_IsValid(pcVar4), iVar16 != 0)) {
        Q_strncpy(local_ebc,pcVar4,0x3ff);
        local_abd = 0;
        qVar5 = Master_IsLanGame();
        if (((qVar5 == false) && (nVar6 != NA_BROADCAST)) && (nVar6 != NA_IP)) {
          qVar5 = false;
        }
        else {
          local_2c[0] = false;
          if (0 < svs.maxclients) {
            do {
              local_3c = svs.clients + local_2c[0];
              pnVar18 = &(local_3c->netchan).remote_address;
              in_stack_fffff118 = pnVar18->type;
              in_stack_fffff11c = *&(local_3c->netchan).remote_address.ip;
              a_01.ip[0] = local_5c[4];
              a_01.ip[1] = local_5c[5];
              a_01.ip[2] = local_5c[6];
              a_01.ip[3] = local_5c[7];
              a_01.type = local_5c._0_4_;
              a_01.ipx[0] = local_54[0];
              a_01.ipx[1] = local_54[1];
              a_01.ipx[2] = local_54[2];
              a_01.ipx[3] = local_54[3];
              a_01.ipx[4] = local_50[0];
              a_01.ipx[5] = local_50[1];
              a_01.ipx[6] = local_50[2];
              a_01.ipx[7] = local_50[3];
              a_01.ipx[8] = local_50[4];
              a_01.ipx[9] = local_50[5];
              a_01.port = uStack_4a;
              qVar5 = NET_CompareAdr(a_01,*pnVar18);
              if (qVar5 != false) {
                qVar5 = true;
                goto LAB_000ad0aa;
              }
              local_2c[0] = local_2c[0] + true;
            } while ((int)local_2c[0] < svs.maxclients);
          }
          qVar5 = false;
        }
LAB_000ad0aa:
        pcVar4 = local_7c;
        iVar16 = SV_CheckUserInfo((netadr_t *)local_5c,local_ebc,qVar5,local_2c[0],pcVar4);
        if (iVar16 != 0) {
          userinfo = local_ebc;
          nVar26 = nVar6;
          iVar16 = SV_FinishCertificateCheck((netadr_t *)local_5c,nVar6,(char *)pcVar10,userinfo);
          if (iVar16 != 0) {
            if (qVar5 == false) {
              pcVar10 = (client_t *)&local_3c;
              iVar16 = SV_FindEmptySlot((netadr_t *)local_5c,(int *)local_2c,(client_t **)pcVar10);
              if (iVar16 == 0) {
                return;
              }
            }
            else {
              pcVar14 = local_3c;
              Steam_NotifyClientDisconnect((client_t_conflict *)local_3c);
              if (((local_3c->active != false) || (local_3c->spawned != false)) &&
                 (pcVar25 = (client_t *)local_3c->edict, pcVar25 != (client_t *)0x0)) {
                (*gEntityInterface.pfnClientDisconnect)((edict_t_conflict *)pcVar25);
                pcVar14 = pcVar25;
              }
              uVar12 = 0x14;
              pnVar18 = (netadr_t *)local_5c;
              if (((uint)&stack0xfffff104 & 4) != 0) {
                pnVar19 = (netadrtype_t *)(&stack0xfffff108 + (uint)bVar24 * -8);
                pnVar18 = (netadr_t *)(local_5c + (uint)bVar24 * -8 + 4);
                uVar12 = 0x10;
                pcVar14 = (client_t *)local_5c._0_4_;
              }
              for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                *pnVar19 = pnVar18->type;
                pnVar18 = (netadr_t *)((int)pnVar18 + (uint)bVar24 * -8 + 4);
                pnVar19 = pnVar19 + (uint)bVar24 * -2 + 1;
              }
              a_03.ip[0] = (char)nVar26;
              a_03.ip[1] = (char)(nVar26 >> 8);
              a_03.ip[2] = (char)(nVar26 >> 0x10);
              a_03.ip[3] = (char)(nVar26 >> 0x18);
              a_03.type = (netadrtype_t)pcVar14;
              a_03.ipx._0_4_ = pcVar10;
              a_03.ipx._4_4_ = userinfo;
              a_03._16_4_ = pcVar4;
              NET_AdrToString(a_03);
              Con_Printf("%s:reconnect\n");
            }
            iVar16 = SV_CheckIPConnectionReuse((netadr_t *)local_5c);
            pcVar14 = local_3c;
            if (iVar16 != 0) {
              local_3c->userid = g_userid;
              g_userid = g_userid + 1;
              host_client = local_3c;
              if (nVar6 == NA_IP) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: char[1024] szSteamAuthBuf@[???] */
                pcVar10 = (client_t *)(net_message.cursize - msg_readcount);
                if ((byte *)0x3fe < (byte *)((int)&pcVar10[-1].m_bSentNewResponse + 3U)) {
                  SV_RejectConnection((netadr_t *)local_5c,"STEAM certificate length error! %i/%i\n"
                                     );
                  return;
                }
                pbVar15 = net_message.data + msg_readcount;
                puVar23 = local_6bc;
                if ((client_t *)0x3 < pcVar10) {
                  for (uVar12 = (uint)pcVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *puVar23 = *(undefined4 *)pbVar15;
                    pbVar15 = pbVar15 + (uint)bVar24 * -8 + 4;
                    puVar23 = puVar23 + (uint)bVar24 * -2 + 1;
                  }
                }
                iVar16 = 0;
                if (((uint)pcVar10 & 2) != 0) {
                  *(undefined2 *)puVar23 = *(undefined2 *)pbVar15;
                  iVar16 = 2;
                }
                if (((uint)pcVar10 & 1) != 0) {
                  *(byte *)((int)puVar23 + iVar16) = pbVar15[iVar16];
                }
                (pcVar14->network_userid).clientip = local_5c._4_4_;
                if ((client_t *)local_5c._0_4_ == (client_t *)0x1) {
                  if (sv_lan.value <= 0.0) {
                    (pcVar14->network_userid).clientip = (uint)net_local_adr.ip;
                  }
                  else {
                    (pcVar14->network_userid).clientip = 0x7f000001;
                  }
                }
                local_ec0 = (ushort)iVar3;
                uVar13 = uStack_4a;
                if (uStack_4a == 0) {
                  uVar13 = local_ec0;
                }
                (pcVar14->netchan).remote_address.port = uVar13;
                qVar11 = Steam_NotifyClientConnect
                                   ((client_t_conflict *)local_3c,local_6bc,(uint)pcVar10);
                pcVar14 = host_client;
                if (qVar11 == 0) {
                  if (sv_lan.value == 0.0) {
                    SV_RejectConnection((netadr_t *)local_5c,"STEAM validation rejected\n");
                    return;
                  }
                  (host_client->network_userid).idtype = 1;
                  *(undefined4 *)&(pcVar14->network_userid).m_SteamID = 0;
                  *(undefined4 *)((int)&(pcVar14->network_userid).m_SteamID + 4) = 0;
                }
              }
              else {
                if (nVar6 != NA_BROADCAST) {
                  SV_RejectConnection((netadr_t *)local_5c,"Invalid authentication type\n");
                  return;
                }
                    /* Unresolved local var: char * val@[???] */
                pcVar7 = Info_ValueForKey(local_ebc,"*hltv");
                iVar3 = Q_strlen(pcVar7);
                    /* Unresolved local var: int i@[???] */
                if ((iVar3 == 0) || (iVar3 = Q_atoi(pcVar7), pcVar14 = host_client, iVar3 != 1)) {
                  SV_RejectConnection((netadr_t *)local_5c,"Invalid validation type\n");
                  return;
                }
                (host_client->network_userid).idtype = 3;
                (pcVar14->network_userid).clientip = local_5c._4_4_;
                *(undefined4 *)&(pcVar14->network_userid).m_SteamID = 0;
                *(undefined4 *)((int)&(pcVar14->network_userid).m_SteamID + 4) = 0;
                Steam_NotifyBotConnect((client_t_conflict *)local_3c);
                pcVar14 = host_client;
              }
              SV_ClearResourceLists(pcVar14);
              SV_ClearFrames(&host_client->frames);
              pcVar14 = host_client;
              pcVar8 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1810);
              pcVar14->frames = pcVar8;
              pcVar14 = host_client;
              prVar1 = &host_client->resourcesneeded;
              (host_client->resourcesneeded).pPrev = prVar1;
              (pcVar14->resourcesneeded).pNext = prVar1;
              (pcVar14->resourcesonhand).pPrev = &pcVar14->resourcesonhand;
              (pcVar14->resourcesonhand).pNext = &pcVar14->resourcesonhand;
              peVar9 = EDICT_NUM(local_2c[0] + true);
              pcVar14 = host_client;
              host_client->edict = peVar9;
              if (g_modfuncs.m_pfnConnectClient != (PFN_CONNECTCLIENT)0x0) {
                (*g_modfuncs.m_pfnConnectClient)(local_2c[0]);
                pcVar14 = host_client;
              }
              pnVar19 = (netadrtype_t *)&stack0xfffff10c;
              pfnNetchan_Blocksize = SV_GetFragmentSize;
              uVar12 = 0x14;
              iVar3 = ((int)local_3c - (int)svs.clients >> 3) * -0x6d690de1;
              pnVar18 = (netadr_t *)local_5c;
              if (((uint)pnVar19 & 4) != 0) {
                pnVar19 = (netadrtype_t *)(&stack0xfffff110 + (uint)bVar24 * -8);
                pnVar18 = (netadr_t *)(local_5c + (uint)bVar24 * -8 + 4);
                uVar12 = 0x10;
                pcVar10 = (client_t *)local_5c._0_4_;
              }
              pcVar25 = local_3c;
              for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                *pnVar19 = pnVar18->type;
                pnVar18 = (netadr_t *)((int)pnVar18 + (uint)bVar24 * -8 + 4);
                pnVar19 = pnVar19 + (uint)bVar24 * -2 + 1;
              }
              adr_01.ip = (uchar  [4])userinfo;
              adr_01.type = (netadrtype_t)pcVar10;
              adr_01.ipx._0_4_ = pcVar4;
              adr_01.ipx[4] = (char)in_stack_fffff118;
              adr_01.ipx[5] = (char)(in_stack_fffff118 >> 8);
              adr_01.ipx[6] = (char)(in_stack_fffff118 >> 0x10);
              adr_01.ipx[7] = (char)(in_stack_fffff118 >> 0x18);
              adr_01._16_4_ = in_stack_fffff11c;
              Netchan_Setup(NS_SERVER,&pcVar14->netchan,adr_01,iVar3,pcVar25,pfnNetchan_Blocksize);
              pcVar10 = host_client;
              host_client->delta_sequence = -1;
              pcVar10->next_messageinterval = 0.05;
              pcVar10->next_messagetime = realtime + 0.05;
              dest = &pcVar10->lastcmd;
              nVar27 = 0x34;
              nVar26 = NA_UNUSED;
              Q_memset(dest,0,0x34);
              pcVar10 = host_client;
              nVar6 = (host_client->netchan).remote_address.type;
              *(undefined4 *)&host_client->nextping = 0;
              *(undefined4 *)((int)&pcVar10->nextping + 4) = 0xbff00000;
              if (nVar6 == NA_LOOPBACK) {
                Con_DPrintf("Local connection.\n");
              }
              else {
                pnVar17 = &(pcVar10->netchan).remote_address;
                uVar12 = 0x14;
                pnVar18 = pnVar17;
                if (((uint)&stack0xfffff104 & 4) != 0) {
                  pnVar20 = (netadrtype_t *)(&stack0xfffff108 + (uint)bVar24 * -8);
                  pnVar18 = (netadr_t *)((int)pcVar10 + (uint)bVar24 * -8 + 0x24);
                  dest = (usercmd_t *)pnVar17->type;
                  uVar12 = 0x10;
                }
                for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                  *pnVar20 = pnVar18->type;
                  pnVar18 = (netadr_t *)((int)pnVar18 + (uint)bVar24 * -8 + 4);
                  pnVar20 = pnVar20 + (uint)bVar24 * -2 + 1;
                }
                a_04.ip[0] = (char)nVar26;
                a_04.ip[1] = (char)(nVar26 >> 8);
                a_04.ip[2] = (char)(nVar26 >> 0x10);
                a_04.ip[3] = (char)(nVar26 >> 0x18);
                a_04.type = (netadrtype_t)dest;
                a_04.ipx[0] = (char)nVar27;
                a_04.ipx[1] = (char)(nVar27 >> 8);
                a_04.ipx[2] = (char)(nVar27 >> 0x10);
                a_04.ipx[3] = (char)(nVar27 >> 0x18);
                a_04.ipx._4_4_ = userinfo;
                a_04._16_4_ = pcVar4;
                NET_AdrToString(a_04);
                Con_DPrintf("Client %s connected\nAdr: %s\n");
              }
              nVar6 = 0x20;
              pcVar7 = host_client->hashedcdkey;
              Q_strncpy(pcVar7,local_ec4,0x20);
              pcVar10 = host_client;
              host_client->active = false;
              pcVar10->hashedcdkey[0x20] = '\0';
              pcVar10 = host_client;
              host_client->spawned = false;
              pcVar10->connected = true;
              pcVar10->uploading = false;
              pcVar10->fully_connected = false;
              Steam_GSBSecure();
              build_number();
              uVar12 = 0x14;
              pnVar17 = &(host_client->netchan).remote_address;
              pnVar18 = pnVar17;
              if (((uint)&stack0xfffff104 & 4) != 0) {
                pnVar21 = (netadrtype_t *)(&stack0xfffff108 + (uint)bVar24 * -8);
                pnVar18 = (netadr_t *)((int)host_client + (uint)bVar24 * -8 + 0x24);
                pcVar7 = (char *)pnVar17->type;
                uVar12 = 0x10;
              }
              for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                *pnVar21 = pnVar18->type;
                pnVar18 = (netadr_t *)((int)pnVar18 + (uint)bVar24 * -8 + 4);
                pnVar21 = pnVar21 + (uint)bVar24 * -2 + 1;
              }
              a_05.ip = (uchar  [4])local_ec4;
              a_05.type = (netadrtype_t)pcVar7;
              a_05.ipx[0] = (char)nVar6;
              a_05.ipx[1] = (char)(nVar6 >> 8);
              a_05.ipx[2] = (char)(nVar6 >> 0x10);
              a_05.ipx[3] = (char)(nVar6 >> 0x18);
              a_05.ipx._4_4_ = userinfo;
              a_05._16_4_ = pcVar4;
              NET_AdrToString(a_05);
              pcVar7 = "%c %i \"%s\" %i %i";
              pnVar18 = (netadr_t *)local_5c;
              pnVar21 = (netadrtype_t *)&stack0xfffff108;
              for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
                *pnVar21 = pnVar18->type;
                pnVar18 = (netadr_t *)((int)pnVar18 + (uint)bVar24 * -8 + 4);
                pnVar21 = pnVar21 + (uint)bVar24 * -2 + 1;
              }
              nVar26 = NA_LOOPBACK;
              adr_00.ip[0] = (char)nVar6;
              adr_00.ip[1] = (char)(nVar6 >> 8);
              adr_00.ip[2] = (char)(nVar6 >> 0x10);
              adr_00.ip[3] = (char)(nVar6 >> 0x18);
              adr_00.type = (netadrtype_t)local_ec4;
              adr_00.ipx._0_4_ = userinfo;
              adr_00.ipx._4_4_ = pcVar4;
              adr_00.ipx[8] = (char)in_stack_fffff118;
              adr_00.ipx[9] = (char)(in_stack_fffff118 >> 8);
              adr_00.port = (short)(in_stack_fffff118 >> 0x10);
              Netchan_OutOfBandPrint(NS_SERVER,adr_00,pcVar7);
              uVar12 = 0x14;
              pnVar17 = &(host_client->netchan).remote_address;
              pnVar18 = pnVar17;
              if (((uint)&stack0xfffff104 & 4) != 0) {
                pnVar22 = (netadrtype_t *)(&stack0xfffff108 + (uint)bVar24 * -8);
                pnVar18 = (netadr_t *)((int)host_client + (uint)bVar24 * -8 + 0x24);
                nVar26 = pnVar17->type;
                uVar12 = 0x10;
              }
              for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                *pnVar22 = pnVar18->type;
                pnVar18 = (netadr_t *)((int)pnVar18 + (uint)bVar24 * -8 + 4);
                pnVar22 = pnVar22 + (uint)bVar24 * -2 + 1;
              }
              a_06.ip = (uchar  [4])local_ec4;
              a_06.type = nVar26;
              a_06.ipx[0] = (char)nVar6;
              a_06.ipx[1] = (char)(nVar6 >> 8);
              a_06.ipx[2] = (char)(nVar6 >> 0x10);
              a_06.ipx[3] = (char)(nVar6 >> 0x18);
              a_06.ipx._4_4_ = userinfo;
              a_06._16_4_ = pcVar4;
              NET_AdrToString(a_06);
              SV_GetClientIDString(host_client);
              Log_Printf("\"%s<%i><%s><>\" connected, address \"%s\"\n");
              Q_strncpy(host_client->userinfo,local_ebc,0x100);
              pcVar10 = host_client;
              host_client->userinfo[0xff] = '\0';
              SV_ExtractFromUserinfo(pcVar10);
              pcVar4 = va("%lld");
              Info_SetValueForStarKey(host_client->userinfo,"*sid",pcVar4,0x100);
              pcVar10 = host_client;
              (host_client->datagram).data = host_client->datagram_buf;
              (pcVar10->datagram).flags = 1;
              (pcVar10->datagram).maxsize = 4000;
              (pcVar10->datagram).buffername = pcVar10->name;
              pcVar10->sendinfo_time = 0.0;
            }
          }
        }
      }
      else {
        SV_RejectConnection((netadr_t *)local_5c,"Invalid userinfo in connect command\n");
      }
    }
    else {
      SV_RejectConnection((netadr_t *)local_5c,
                          "LAN servers are restricted to local clients (class C).\n");
    }
  }
  return;
}


// SV_ConnectionlessPacket  @ 000ad8e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ConnectionlessPacket(void)

{
  undefined1 uVar1;
  byte bVar2;
  netadr_t a;
  netadr_t to;
  char *pcVar3;
  netadr_t *net_from;
  int iVar4;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
                    /* Unresolved local var: char * args@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: char * c@[???] */
  MSG_BeginReading();
  MSG_ReadLong();
  pcVar3 = MSG_ReadStringLine();
  Cmd_TokenizeString(pcVar3);
  net_from = (netadr_t *)Cmd_Argv(0);
  iVar4 = Q_strcmp((char *)net_from,"ping");
  if (iVar4 != 0) {
    uVar1 = (undefined1)net_from->type;
    if (uVar1 == 0x69) {
      bVar2 = *(byte *)((int)&net_from->type + 1);
      if ((bVar2 == 10) || (bVar2 == 0)) goto LAB_000ad960;
    }
    else if (uVar1 == 0x6a) {
      bVar2 = *(byte *)((int)&net_from->type + 1);
      if ((bVar2 == 10) || (bVar2 == 0)) {
        a.ip[0] = ::net_from.ip[0];
        a.ip[1] = ::net_from.ip[1];
        a.ip[2] = ::net_from.ip[2];
        a.ip[3] = ::net_from.ip[3];
        a.type = ::net_from.type;
        a.ipx[0] = ::net_from.ipx[0];
        a.ipx[1] = ::net_from.ipx[1];
        a.ipx[2] = ::net_from.ipx[2];
        a.ipx[3] = ::net_from.ipx[3];
        a.ipx[4] = ::net_from.ipx[4];
        a.ipx[5] = ::net_from.ipx[5];
        a.ipx[6] = ::net_from.ipx[6];
        a.ipx[7] = ::net_from.ipx[7];
        a.ipx[8] = ::net_from.ipx[8];
        a.ipx[9] = ::net_from.ipx[9];
        a.port = ::net_from.port;
        pcVar3 = NET_AdrToString(a);
        Con_Printf("A2A_ACK from %s\n",pcVar3);
        return;
      }
    }
    else {
      if (uVar1 == 0x54) {
        return;
      }
      if (uVar1 == 0x57) {
        return;
      }
      if (uVar1 == 0x55) {
        return;
      }
      if (uVar1 == 0x56) {
        return;
      }
      if (uVar1 == 0x52) {
        return;
      }
      if (uVar1 == 0x4f) {
        return;
      }
      if (uVar1 == 0x73) {
        return;
      }
    }
    iVar4 = Q_stricmp((char *)net_from,"log");
    if (iVar4 == 0) {
      if (((pcVar3 != (char *)0x0) && (sv_logrelay.value != 0.0)) &&
         (iVar4 = Q_strlen(pcVar3), 4 < iVar4)) {
        iVar4 = Q_strlen("log ");
        pcVar3 = pcVar3 + iVar4;
        if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
          Con_Printf("%s\n",pcVar3);
        }
      }
    }
    else {
      iVar4 = Q_strcmp((char *)net_from,"getchallenge");
      if (iVar4 == 0) {
        SVC_GetChallenge();
      }
      else {
        iVar4 = Q_stricmp((char *)net_from,"challenge");
        if (iVar4 == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???] */
          iVar4 = Cmd_Argc();
          if (iVar4 == 2) {
            SVC_ServiceChallenge();
          }
        }
        else {
          iVar4 = Q_strcmp((char *)net_from,"connect");
          if (iVar4 == 0) {
            SV_ConnectClient();
          }
          else {
            iVar4 = Q_strcmp((char *)net_from,"pstat");
            if (iVar4 == 0) {
              if (g_modfuncs.m_pfnPlayerStatus != (PFN_PLAYERSTATUS)0x0) {
                (*g_modfuncs.m_pfnPlayerStatus)(net_message.data,net_message.cursize);
              }
            }
            else {
              iVar4 = Q_strcmp((char *)net_from,"rcon");
              if (iVar4 == 0) {
                SV_Rcon(net_from);
              }
              else {
                SVC_GameDllQuery(pcVar3);
              }
            }
          }
        }
      }
    }
    return;
  }
LAB_000ad960:
                    /* Unresolved local var: char[6] data@[???] */
  local_12 = 0xff;
  local_11 = 0xff;
  local_10 = 0xff;
  local_f = 0xff;
  local_e = 0x6a;
  local_d = 0;
  to.ip[0] = ::net_from.ip[0];
  to.ip[1] = ::net_from.ip[1];
  to.ip[2] = ::net_from.ip[2];
  to.ip[3] = ::net_from.ip[3];
  to.type = ::net_from.type;
  to.ipx[0] = ::net_from.ipx[0];
  to.ipx[1] = ::net_from.ipx[1];
  to.ipx[2] = ::net_from.ipx[2];
  to.ipx[3] = ::net_from.ipx[3];
  to.ipx[4] = ::net_from.ipx[4];
  to.ipx[5] = ::net_from.ipx[5];
  to.ipx[6] = ::net_from.ipx[6];
  to.ipx[7] = ::net_from.ipx[7];
  to.ipx[8] = ::net_from.ipx[8];
  to.ipx[9] = ::net_from.ipx[9];
  to.port = ::net_from.port;
  NET_SendPacket(NS_SERVER,6,&local_12,to);
  return;
}


// SV_ConvertPMTrace  @ 000b96d0
void SV_ConvertPMTrace(trace_t *dest,pmtrace_t *src,edict_t_conflict *ent)

{
  dest->allsolid = src->allsolid;
  dest->startsolid = src->startsolid;
  dest->inopen = src->inopen;
  dest->inwater = src->inwater;
  dest->fraction = src->fraction;
  dest->endpos[0] = src->endpos[0];
  dest->endpos[1] = src->endpos[1];
  dest->endpos[2] = src->endpos[2];
  (dest->plane).normal[0] = (src->plane).normal[0];
  (dest->plane).normal[1] = (src->plane).normal[1];
  (dest->plane).normal[2] = (src->plane).normal[2];
  (dest->plane).dist = (src->plane).dist;
  dest->hitgroup = src->hitgroup;
  dest->ent = ent;
  return;
}


// SV_CopyEdictToPhysent  @ 000b8ac0
void SV_CopyEdictToPhysent(physent_t *pe,int e,edict_t_conflict *check)

{
  vec_t vVar1;
  string_t sVar2;
  model_s *pmVar3;
  int iVar4;
  
  pe->info = e;
  pe->origin[0] = (check->v).origin[0];
  pe->origin[1] = (check->v).origin[1];
  pe->origin[2] = (check->v).origin[2];
  if ((e < 1) || (svs.maxclients < e)) {
    pe->player = 0;
  }
  else {
    if ((((((host_client->lw != 0) && (host_client->lc != 0)) && (sv_unlag.value != 0.0)) &&
         ((1 < svs.maxclients && (host_client->active != false)))) &&
        ((iVar4 = e + -1, -1 < iVar4 &&
         ((iVar4 < svs.maxclients && (truepositions[iVar4].active != 0)))))) &&
       (truepositions[iVar4].needrelink != 0)) {
      pe->origin[0] = truepositions[iVar4].oldorg[0];
      pe->origin[1] = truepositions[iVar4].oldorg[1];
      pe->origin[2] = truepositions[iVar4].oldorg[2];
    }
    pe->player = e;
  }
  pe->angles[0] = (check->v).angles[0];
  pe->angles[1] = (check->v).angles[1];
  vVar1 = (check->v).angles[2];
  pe->studiomodel = (model_s *)0x0;
  pe->angles[2] = vVar1;
  pe->rendermode = (check->v).rendermode;
  iVar4 = (check->v).solid;
  if (iVar4 == 4) {
    iVar4 = (check->v).modelindex;
  }
  else {
    if (iVar4 != 0) {
                    /* Unresolved local var: model_t * pModel@[???] */
      pe->model = (model_s *)0x0;
      if (iVar4 == 2) {
        iVar4 = (check->v).modelindex;
        if ((iVar4 != 0) && (pmVar3 = sv.models[iVar4], pmVar3 != (model_s *)0x0)) {
          if ((pmVar3->flags & 0x200) != 0) {
            pe->studiomodel = pmVar3;
          }
          Q_strncpy(pe->name,pmVar3->name,0x20);
          pe->name[0x1f] = '\0';
        }
        pe->mins[0] = (check->v).mins[0];
        pe->mins[1] = (check->v).mins[1];
        pe->mins[2] = (check->v).mins[2];
        pe->maxs[0] = (check->v).maxs[0];
        pe->maxs[1] = (check->v).maxs[1];
        pe->maxs[2] = (check->v).maxs[2];
      }
      else {
        pe->mins[0] = (check->v).mins[0];
        pe->mins[1] = (check->v).mins[1];
        pe->mins[2] = (check->v).mins[2];
        pe->maxs[0] = (check->v).maxs[0];
        pe->maxs[1] = (check->v).maxs[1];
        pe->maxs[2] = (check->v).maxs[2];
        sVar2 = (check->v).classname;
        if (sVar2 == 0) {
          pe->name[0] = '?';
          pe->name[1] = '\0';
        }
        else {
          Q_strncpy(pe->name,pr_strings + sVar2,0x20);
        }
        pe->name[0x1f] = '\0';
      }
      goto LAB_000b8b5f;
    }
    iVar4 = (check->v).modelindex;
    if (iVar4 == 0) {
      pe->model = (model_s *)0x0;
      goto LAB_000b8b5f;
    }
  }
  pmVar3 = sv.models[iVar4];
  pe->model = pmVar3;
  Q_strncpy(pe->name,pmVar3->name,0x20);
  pe->name[0x1f] = '\0';
LAB_000b8b5f:
  pe->solid = (check->v).solid;
  pe->skin = (check->v).skin;
  pe->frame = (check->v).frame;
  pe->sequence = (check->v).sequence;
  Q_memcpy(pe->controller,(check->v).controller,4);
  Q_memcpy(pe->blending,(check->v).blending,2);
  pe->movetype = (check->v).movetype;
  pe->takedamage = 0;
  pe->blooddecal = 0;
  pe->iuser1 = (check->v).iuser1;
  pe->iuser2 = (check->v).iuser2;
  pe->iuser3 = (check->v).iuser3;
  pe->iuser4 = (check->v).iuser4;
  pe->fuser1 = (check->v).fuser1;
  pe->fuser2 = (check->v).fuser2;
  pe->fuser3 = (check->v).fuser3;
  pe->fuser4 = (check->v).fuser4;
  pe->vuser1[0] = (check->v).vuser1[0];
  pe->vuser1[1] = (check->v).vuser1[1];
  pe->vuser1[2] = (check->v).vuser1[2];
  pe->vuser2[0] = (check->v).vuser2[0];
  pe->vuser2[1] = (check->v).vuser2[1];
  pe->vuser2[2] = (check->v).vuser2[2];
  pe->vuser3[0] = (check->v).vuser3[0];
  pe->vuser3[1] = (check->v).vuser3[1];
  pe->vuser3[2] = (check->v).vuser3[2];
  pe->vuser4[0] = (check->v).vuser4[0];
  pe->vuser4[1] = (check->v).vuser4[1];
  pe->vuser4[2] = (check->v).vuser4[2];
  return;
}


// SV_CountPlayers  @ 0009c940
void SV_CountPlayers(int *clients)

{
  client_s *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  *clients = 0;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    pcVar1 = svs.clients;
    iVar2 = svs.maxclients;
    do {
      if (((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false))
      {
        *clients = *clients + 1;
        iVar2 = svs.maxclients;
      }
      iVar3 = iVar3 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// SV_CountProxies  @ 0009c9a0
void SV_CountProxies(int *proxies)

{
  client_s *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  *proxies = 0;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    pcVar1 = svs.clients;
    iVar2 = svs.maxclients;
    do {
      if ((((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false)
          ) && (pcVar1->proxy != false)) {
        *proxies = *proxies + 1;
        iVar2 = svs.maxclients;
      }
      iVar3 = iVar3 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// SV_CreateAreaNode  @ 000bf260
areanode_t * SV_CreateAreaNode(int depth,vec_t *mins,vec_t *maxs)

{
  link_s *plVar1;
  areanode_t *paVar2;
  float fVar3;
  int iVar4;
  areanode_t *paVar5;
  uint uVar6;
  int iVar7;
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40 [4];
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
  iVar4 = sv_numareanodes;
  iVar7 = sv_numareanodes * 0x20;
  paVar2 = sv_areanodes + sv_numareanodes;
  plVar1 = (link_s *)(iVar7 + 0x5558f0);
  paVar5 = sv_areanodes + sv_numareanodes;
  sv_numareanodes = sv_numareanodes + 1;
  (paVar5->trigger_edicts).next = plVar1;
  sv_areanodes[iVar4].trigger_edicts.prev = plVar1;
  plVar1 = (link_s *)(iVar7 + 0x5558f8);
  sv_areanodes[iVar4].solid_edicts.next = plVar1;
  sv_areanodes[iVar4].solid_edicts.prev = plVar1;
  if (depth == 4) {
    sv_areanodes[iVar4].axis = -1;
    sv_areanodes[iVar4].children[1] = (areanode_s *)0x0;
    sv_areanodes[iVar4].children[0] = (areanode_s *)0x0;
  }
  else {
    uVar6 = (uint)(*maxs - *mins <= maxs[1] - mins[1]);
    sv_areanodes[iVar4].axis = uVar6;
    fVar3 = (maxs[uVar6] + mins[uVar6]) * 0.5;
    sv_areanodes[iVar4].dist = fVar3;
    local_48 = mins[1];
    local_4c = *mins;
    local_44 = mins[2];
    local_28 = *maxs;
    local_24 = maxs[1];
    local_40[2] = maxs[2];
    local_40[3] = local_4c;
    local_30 = local_48;
    local_40[uVar6 + 3] = fVar3;
    local_40[0] = local_28;
    local_40[1] = local_24;
    local_40[uVar6] = fVar3;
    local_2c = local_44;
    local_20 = local_40[2];
    paVar5 = SV_CreateAreaNode(depth + 1,local_40 + 3,local_40 + 6);
    sv_areanodes[iVar4].children[0] = paVar5;
    paVar5 = SV_CreateAreaNode(depth + 1,&local_4c,local_40);
    sv_areanodes[iVar4].children[1] = paVar5;
  }
  return paVar2;
}


// SV_CreateBaseline  @ 000a7030
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CreateBaseline(void)

{
  uint uVar1;
  delta_t *pFields;
  edict_s *peVar2;
  int iVar3;
  int iVar4;
  uint32 data;
  int iVar5;
  uchar local_160 [340];
  
                    /* Unresolved local var: edict_t.conflict * svent@[???]
                       Unresolved local var: int entnum@[???]
                       Unresolved local var: qboolean player@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: entity_state_t nullstate@[???] */
                    /* Unresolved local var: int i@[???] */
  iVar3 = 0;
  sv.instance_baselines = &g_sv_instance_baselines;
  Q_memset(local_160,0,0x154);
  sv_playermodel = -1;
  do {
    if (sv.model_precache[iVar3] == (char *)0x0) break;
    iVar4 = Q_strcasecmp(sv.model_precache[iVar3],"models/player.mdl");
    if (iVar4 == 0) {
      sv_playermodel = iVar3;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x200);
  if (0 < sv.num_edicts) {
    iVar5 = 0;
    iVar4 = 0;
    iVar3 = sv.num_edicts;
    do {
      peVar2 = (edict_s *)(sv.edicts + iVar4);
      if ((peVar2->free == false) && ((iVar4 <= svs.maxclients || ((peVar2->v).modelindex != 0)))) {
        uVar1 = 0;
        if (iVar4 != 0) {
          uVar1 = (uint)(iVar4 <= svs.maxclients);
        }
        *(int *)((int)(sv.baselines)->origin + iVar5 + -0xc) = iVar4;
        *(undefined4 *)((int)(sv.baselines)->origin + iVar5 + -0x10) = 1;
        if (((peVar2->v).flags & 0x20000000) != 0) {
          *(undefined4 *)((int)(sv.baselines)->origin + iVar5 + -0x10) = 2;
        }
        (*gEntityInterface.pfnCreateBaseline)
                  (uVar1,iVar4,(entity_state_s *)((int)(sv.baselines)->origin + iVar5 + -0x10),
                   peVar2,sv_playermodel,player_mins[0],player_maxs[0]);
        iVar3 = sv.num_edicts;
        sv_lastnum = iVar4;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x154;
    } while (iVar4 < iVar3);
  }
  (*gEntityInterface.pfnCreateInstancedBaselines)();
  MSG_WriteByte(&sv.signon,0x16);
  MSG_StartBitWriting(&sv.signon);
  if (0 < sv.num_edicts) {
    iVar4 = 0;
    data = 0;
    iVar3 = sv.num_edicts;
    do {
      if ((sv.edicts[data].free == 0) &&
         (((int)data <= svs.maxclients || (sv.edicts[data].v.modelindex != 0)))) {
        MSG_WriteBits(data,0xb);
        uVar1 = *(uint *)((int)(sv.baselines)->origin + iVar4 + -0x10);
        if ((uVar1 & 1) == 0) {
          MSG_WriteBits(uVar1,2);
          pFields = g_pcustomentitydelta;
        }
        else {
          MSG_WriteBits(uVar1,2);
          pFields = g_pentitydelta;
          if ((data != 0) && ((int)data <= svs.maxclients)) {
            pFields = g_pplayerdelta;
          }
        }
        DELTA_WriteDelta(local_160,(uchar *)((int)(sv.baselines)->origin + iVar4 + -0x10),true,
                         pFields,(_func_void *)0x0);
        iVar3 = sv.num_edicts;
      }
      data = data + 1;
      iVar4 = iVar4 + 0x154;
    } while ((int)data < iVar3);
  }
  MSG_WriteBits(0xffff,0x10);
  MSG_WriteBits((sv.instance_baselines)->number,6);
  if (0 < (sv.instance_baselines)->number) {
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      DELTA_WriteDelta(local_160,(uchar *)((sv.instance_baselines)->baseline + iVar3),true,
                       g_pentitydelta,(_func_void *)0x0);
      iVar3 = iVar4;
    } while (iVar4 < (sv.instance_baselines)->number);
  }
  MSG_EndBitWriting(&sv.signon);
  return;
}


// SV_CreateCustomizationList  @ 000b6bd0
/* WARNING: Removing unreachable block (ram,0x000b6c01) */

void SV_CreateCustomizationList(client_t *pHost)

{
  int iVar1;
  qboolean qVar2;
  customization_s *pcVar3;
  resource_t *pResource;
  customization_t *local_24;
  int local_20 [4];
  
                    /* Unresolved local var: resource_t * pResource@[???] */
  pResource = (pHost->resourcesonhand).pNext;
  (pHost->customdata).pNext = (customization_s *)0x0;
  if (pResource == &pHost->resourcesonhand) {
    return;
  }
LAB_000b6c70:
  do {
                    /* Unresolved local var: customization_t * pCust@[???]
                       Unresolved local var: qboolean bNoError@[???]
                       Unresolved local var: int nLumps@[???] */
    local_20[0] = 0;
    qVar2 = COM_CreateCustomization(&pHost->customdata,pResource,-1,3,&local_24,local_20);
    if (qVar2 != false) {
      local_24->nUserData2 = local_20[0];
      (*gEntityInterface.pfnPlayerCustomization)(pHost->edict,local_24);
      goto LAB_000b6c54;
    }
    if (sv_allow_upload.value == 0.0) {
      Con_Printf("Ignoring custom decal from %s\n",pHost->name);
      goto LAB_000b6c54;
    }
    Con_Printf("Ignoring invalid custom decal from %s\n",pHost->name);
    pResource = pResource->pNext;
    while( true ) {
      if (pResource == &pHost->resourcesonhand) {
        return;
      }
      pcVar3 = (pHost->customdata).pNext;
      if (pcVar3 == (customization_s *)0x0) break;
      while (iVar1 = Q_memcmp((pcVar3->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10),
            iVar1 != 0) {
        pcVar3 = pcVar3->pNext;
        if (pcVar3 == (customization_s *)0x0) goto LAB_000b6c70;
      }
      Con_DPrintf("SV_CreateCustomization list, ignoring dup. resource for player %s\n",pHost->name)
      ;
LAB_000b6c54:
      pResource = pResource->pNext;
    }
  } while( true );
}


// SV_CreateGenericResources  @ 000a6640
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CreateGenericResources(void)

{
  uchar *buffer;
  uchar *data;
  int iVar1;
  char *pcVar2;
  qboolean qVar3;
  char local_110 [260];
  
                    /* Unresolved local var: char[260] filename@[???]
                       Unresolved local var: char * buffer@[???]
                       Unresolved local var: char * data@[???] */
  pcVar2 = local_110;
  COM_StripExtension(sv.modelname,pcVar2);
  COM_DefaultExtension(pcVar2,".res");
  COM_FixSlashes(pcVar2);
  buffer = COM_LoadFile(pcVar2,5,(int *)0x0);
  if (buffer != (uchar *)0x0) {
    data = buffer;
    if (((*buffer == 0xef) && (buffer[1] == 0xbb)) && (data = buffer + 3, buffer[2] != 0xbf)) {
      data = buffer;
    }
    Con_DPrintf("Precaching from %s\n",pcVar2);
    Con_DPrintf("----------------------------------\n");
    sv.num_generic_names = 0;
LAB_000a66d0:
    data = (uchar *)COM_Parse((char *)data);
    iVar1 = Q_strlen(com_token);
    if (0 < iVar1) {
      if ((com_token[0] != '/') && (com_token[0] != '\\')) {
        pcVar2 = Q_strstr(com_token,"..");
        if (pcVar2 != (char *)0x0) {
          pcVar2 = com_token;
          Con_Printf("Can\'t precache resource with invalid relative path %s\n");
          goto LAB_000a66d0;
        }
        pcVar2 = Q_strstr(com_token,":");
        if (pcVar2 == (char *)0x0) {
          pcVar2 = Q_stristr(com_token,".cfg");
          if (pcVar2 == (char *)0x0) {
            pcVar2 = Q_stristr(com_token,".rc");
            if (pcVar2 == (char *)0x0) {
              pcVar2 = Q_stristr(com_token,".lst");
              if (pcVar2 == (char *)0x0) {
                pcVar2 = Q_stristr(com_token,".exe");
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = Q_stristr(com_token,".vbs");
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = Q_stristr(com_token,".com");
                    if (pcVar2 == (char *)0x0) {
                      pcVar2 = Q_stristr(com_token,".bat");
                      if (pcVar2 == (char *)0x0) {
                        pcVar2 = Q_stristr(com_token,".dll");
                        if (pcVar2 == (char *)0x0) {
                          pcVar2 = Q_stristr(com_token,".asi");
                          if (pcVar2 == (char *)0x0) {
                            pcVar2 = Q_stristr(com_token,".mix");
                            if (pcVar2 == (char *)0x0) {
                              pcVar2 = Q_stristr(com_token,".flt");
                              if (pcVar2 == (char *)0x0) {
                                qVar3 = PR_IsEmptyString(com_token);
                                if (qVar3 == false) {
                                  Q_strncpy(sv.generic_precache_names[sv.num_generic_names],
                                            com_token,0x3f);
                                  iVar1 = sv.num_generic_names;
                                  sv.generic_precache_names[sv.num_generic_names][0x3f] = '\0';
                                  PF_precache_generic_I(sv.generic_precache_names[iVar1]);
                                  pcVar2 = sv.generic_precache_names[sv.num_generic_names];
                                  Con_DPrintf("  %s\n",pcVar2);
                                  sv.num_generic_names = sv.num_generic_names + 1;
                                }
                                else {
                                  pcVar2 = com_token;
                                  Con_Printf("Can\'t precache invalid files:  %s\n");
                                }
                              }
                              else {
                                pcVar2 = com_token;
                                Con_Printf("Can\'t precache .flt files:  %s\n");
                              }
                            }
                            else {
                              pcVar2 = com_token;
                              Con_Printf("Can\'t precache .mix files:  %s\n");
                            }
                          }
                          else {
                            pcVar2 = com_token;
                            Con_Printf("Can\'t precache .asi files:  %s\n");
                          }
                        }
                        else {
                          pcVar2 = com_token;
                          Con_Printf("Can\'t precache .dll files:  %s\n");
                        }
                      }
                      else {
                        pcVar2 = com_token;
                        Con_Printf("Can\'t precache .bat files:  %s\n");
                      }
                    }
                    else {
                      pcVar2 = com_token;
                      Con_Printf("Can\'t precache .com files:  %s\n");
                    }
                  }
                  else {
                    pcVar2 = com_token;
                    Con_Printf("Can\'t precache .vbs files:  %s\n");
                  }
                }
                else {
                  pcVar2 = com_token;
                  Con_Printf("Can\'t precache .exe files:  %s\n");
                }
              }
              else {
                pcVar2 = com_token;
                Con_Printf("Can\'t precache .lst files:  %s\n");
              }
            }
            else {
              pcVar2 = com_token;
              Con_Printf("Can\'t precache .rc files:  %s\n");
            }
          }
          else {
            pcVar2 = com_token;
            Con_Printf("Can\'t precache .cfg files:  %s\n");
          }
          goto LAB_000a66d0;
        }
      }
      pcVar2 = com_token;
      Con_Printf("Can\'t precache resource with absolute path %s\n");
      goto LAB_000a66d0;
    }
    Con_DPrintf("----------------------------------\n",pcVar2);
    COM_FreeFile(buffer);
  }
  return;
}


// SV_CreatePacketEntities  @ 000a4860
int SV_CreatePacketEntities(sv_delta_t type,client_t *client,packet_entities_t *to,sizebuf_t *msg)

{
  entity_state_s *to_00;
  string_t sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  edict_t_conflict *peVar6;
  delta_t *pdVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  qboolean custom;
  int n;
  int index;
  int iVar11;
  packet_entities_t *local_64;
  int local_60;
  entity_state_t *local_5c;
  int local_3c [4];
  entity_state_s *local_2c [7];
  
                    /* Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: client_frame_t * fromframe@[???]
                       Unresolved local var: packet_entities_t * from@[???]
                       Unresolved local var: int oldindex@[???]
                       Unresolved local var: int newindex@[???]
                       Unresolved local var: int oldnum@[???]
                       Unresolved local var: int newnum@[???]
                       Unresolved local var: int oldmax@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: int numbase@[???] */
  local_3c[0] = 0;
  if (type == sv_packet_delta) {
    uVar9 = SV_UPDATE_MASK & client->delta_sequence;
    local_64 = &client->frames[uVar9].entities;
    local_60 = client->frames[uVar9].entities.num_entities;
    MSG_WriteByte(msg,0x29);
    MSG_WriteShort(msg,to->num_entities);
    MSG_WriteByte(msg,client->delta_sequence);
  }
  else {
    MSG_WriteByte(msg,0x28);
    MSG_WriteShort(msg,to->num_entities);
    local_60 = 0;
    local_64 = (packet_entities_t *)0x0;
  }
  iVar11 = 0;
  MSG_StartBitWriting(msg);
  iVar10 = to->num_entities;
  index = 0;
LAB_000a48e0:
  bVar2 = index < iVar10;
  bVar3 = iVar11 < local_60;
  if (local_60 <= iVar11) goto LAB_000a4980;
  do {
    n = 9999;
    if (bVar2) goto LAB_000a4990;
    while( true ) {
      iVar5 = 9999;
      if (bVar3) {
        iVar5 = local_64->entities[iVar11].number;
      }
      if (n == iVar5) {
        to_00 = to->entities + index;
        g_svdeltacallback.custom = (qboolean)((to_00->entityType & 2) != 0);
        g_svdeltacallback.remove = false;
        g_svdeltacallback.numbase = local_3c;
        g_svdeltacallback.newbl = false;
        g_svdeltacallback.newblindex = 0;
        g_svdeltacallback.full = false;
        g_svdeltacallback.offset = 0;
        if (g_svdeltacallback.custom == false) {
          pdVar7 = g_pentitydelta;
          if ((0 < n) && (n <= svs.maxclients)) {
            pdVar7 = g_pplayerdelta;
          }
          g_svdeltacallback.num = n;
          DELTA_WriteDelta((uchar *)(local_64->entities + iVar11),(uchar *)to_00,false,pdVar7,
                           SV_InvokeCallback);
        }
        else {
          g_svdeltacallback.num = n;
          DELTA_WriteDelta((uchar *)(local_64->entities + iVar11),(uchar *)to_00,false,
                           g_pcustomentitydelta,SV_InvokeCallback);
        }
        iVar11 = iVar11 + 1;
        index = index + 1;
        iVar10 = to->num_entities;
        goto LAB_000a48e0;
      }
      if (n < iVar5) {
                    /* Unresolved local var: entity_state_t * baseline@[???] */
        peVar6 = EDICT_NUM(n);
        local_5c = to->entities;
        custom = (qboolean)((local_5c[index].entityType & 2) != 0);
        g_svdeltacallback.newbl = false;
        g_svdeltacallback.remove = false;
        g_svdeltacallback.numbase = local_3c;
        g_svdeltacallback.newblindex = 0;
        g_svdeltacallback.full = (qboolean)(local_64 == (packet_entities_t *)0x0);
        g_svdeltacallback.offset = 0;
        local_2c[0] = sv.baselines + n;
        g_svdeltacallback.custom = custom;
        if (((sv_instancedbaseline.value == 0.0) ||
            (iVar10 = (sv.instance_baselines)->number, iVar10 == 0)) || (n <= sv_lastnum)) {
          g_svdeltacallback.num = n;
          if (local_64 == (packet_entities_t *)0x0) {
            iVar10 = SV_FindBestBaseline(index,local_2c,local_5c,n,custom);
            if (iVar10 == 0) {
              local_5c = to->entities;
            }
            else {
              g_svdeltacallback.remove = false;
              g_svdeltacallback.numbase = local_3c;
              local_5c = to->entities;
              g_svdeltacallback.newbl = false;
              g_svdeltacallback.full = true;
              g_svdeltacallback.newblindex = 0;
              g_svdeltacallback.num = n;
              g_svdeltacallback.custom = custom;
              g_svdeltacallback.offset = iVar10;
            }
          }
          goto LAB_000a4b33;
        }
                    /* Unresolved local var: int i@[???] */
        g_svdeltacallback.num = n;
        if (iVar10 < 1) goto LAB_000a4b33;
        sVar1 = (peVar6->v).classname;
        if ((sv.instance_baselines)->classname[0] != sVar1) {
          iVar8 = 0;
          goto LAB_000a4c8a;
        }
        iVar5 = 0;
        goto LAB_000a4d6e;
      }
      if (n <= iVar5) goto LAB_000a48e0;
      iVar11 = iVar11 + 1;
      SV_WriteDeltaHeader(iVar5,true,false,local_3c,false,0,false,0);
      iVar10 = to->num_entities;
      bVar2 = index < iVar10;
      bVar3 = iVar11 < local_60;
      if (iVar11 < local_60) break;
LAB_000a4980:
      if (!bVar2) {
        MSG_WriteBits(0,0x10);
        MSG_EndBitWriting(msg);
        return msg->cursize;
      }
LAB_000a4990:
      n = to->entities[index].number;
    }
  } while( true );
  while (iVar4 = iVar8 + 1, iVar8 = iVar5, (sv.instance_baselines)->classname[iVar4] != sVar1) {
LAB_000a4c8a:
    iVar5 = iVar8 + 1;
    if (iVar5 == iVar10) goto LAB_000a4b33;
  }
LAB_000a4d6e:
  g_svdeltacallback.newbl = true;
  local_2c[0] = (entity_state_s *)((sv.instance_baselines)->baseline + iVar5);
  g_svdeltacallback.newblindex = iVar5;
LAB_000a4b33:
  pdVar7 = g_pcustomentitydelta;
  if (((custom == false) && (pdVar7 = g_pentitydelta, 0 < n)) && (n <= svs.maxclients)) {
    pdVar7 = g_pplayerdelta;
  }
  DELTA_WriteDelta((uchar *)local_2c[0],(uchar *)(local_5c + index),true,pdVar7,SV_InvokeCallback);
  iVar10 = to->num_entities;
  index = index + 1;
  goto LAB_000a48e0;
}


// SV_CreateResourceList  @ 000a6a70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CreateResourceList(void)

{
  resource_t *prVar1;
  uchar uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  char **ppcVar9;
  uint uVar10;
  
                    /* Unresolved local var: char * * s@[???]
                       Unresolved local var: int ffirstsent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int nSize@[???] */
  sv.num_resources = 0;
  if (sv.generic_precache[1] != (char *)0x0) {
    pcVar6 = sv.generic_precache[1];
    iVar8 = 1;
    do {
      uVar10 = 0;
      if (1 < svs.maxclients) {
        uVar10 = FS_FileSize(pcVar6);
      }
                    /* Unresolved local var: resource_t * r@[???] */
      iVar5 = sv.num_resources;
      pcVar6 = sv.generic_precache[iVar8];
      prVar1 = sv.resourcelist + sv.num_resources;
      if (0x4ff < sv.num_resources) {
        Sys_Error("Too many resources on server.");
      }
      sv.num_resources = sv.num_resources + 1;
      sv.resourcelist[iVar5].type = t_generic;
      Q_strncpy(prVar1->szFileName,pcVar6,0x3f);
      sv.resourcelist[iVar5].nIndex = iVar8;
      sv.resourcelist[iVar5].szFileName[0x3f] = '\0';
      sv.resourcelist[iVar5].nDownloadSize = uVar10;
      sv.resourcelist[iVar5].ucFlags = '\x01';
      pcVar6 = sv.generic_precache[iVar8 + 1];
      iVar8 = iVar8 + 1;
    } while (pcVar6 != (char *)0x0);
  }
  if (sv.sound_precache[1] != (char *)0x0) {
    bVar3 = false;
    pcVar6 = sv.sound_precache[1];
    iVar8 = 1;
LAB_000a6be5:
    do {
      iVar5 = sv.num_resources;
      if (*pcVar6 == '!') {
        if (bVar3) {
          bVar3 = true;
          pcVar6 = sv.sound_precache[iVar8 + 1];
          iVar8 = iVar8 + 1;
          if (pcVar6 == (char *)0x0) break;
          goto LAB_000a6be5;
        }
                    /* Unresolved local var: resource_t * r@[???] */
        prVar1 = sv.resourcelist + sv.num_resources;
        if (0x4ff < sv.num_resources) {
          Sys_Error("Too many resources on server.");
        }
        sv.num_resources = sv.num_resources + 1;
        sv.resourcelist[iVar5].type = t_sound;
        Q_strncpy(prVar1->szFileName,"!",0x3f);
        sv.resourcelist[iVar5].szFileName[0x3f] = '\0';
        sv.resourcelist[iVar5].nDownloadSize = 0;
        sv.resourcelist[iVar5].ucFlags = '\x01';
        sv.resourcelist[iVar5].nIndex = iVar8;
        bVar3 = true;
      }
      else {
        uVar10 = 0;
        if (1 < svs.maxclients) {
          pcVar6 = va("sound/%s",pcVar6);
          uVar10 = FS_FileSize(pcVar6);
        }
                    /* Unresolved local var: resource_t * r@[???] */
        iVar5 = sv.num_resources;
        pcVar6 = sv.sound_precache[iVar8];
        prVar1 = sv.resourcelist + sv.num_resources;
        if (0x4ff < sv.num_resources) {
          Sys_Error("Too many resources on server.");
        }
        sv.num_resources = sv.num_resources + 1;
        sv.resourcelist[iVar5].type = t_sound;
        Q_strncpy(prVar1->szFileName,pcVar6,0x3f);
        sv.resourcelist[iVar5].szFileName[0x3f] = '\0';
        sv.resourcelist[iVar5].nDownloadSize = uVar10;
        sv.resourcelist[iVar5].ucFlags = '\0';
        sv.resourcelist[iVar5].nIndex = iVar8;
      }
      pcVar6 = sv.sound_precache[iVar8 + 1];
      iVar8 = iVar8 + 1;
    } while (pcVar6 != (char *)0x0);
  }
  if (sv.model_precache[1] != (char *)0x0) {
    pcVar6 = sv.model_precache[1];
    iVar8 = 1;
    do {
      uVar10 = 0;
      if ((1 < svs.maxclients) && (*pcVar6 != '*')) {
        uVar10 = FS_FileSize(pcVar6);
      }
                    /* Unresolved local var: resource_t * r@[???] */
      iVar5 = sv.num_resources;
      uVar2 = sv.model_precache_flags[iVar8];
      pcVar6 = sv.model_precache[iVar8];
      prVar1 = sv.resourcelist + sv.num_resources;
      if (0x4ff < sv.num_resources) {
        Sys_Error("Too many resources on server.");
      }
      sv.num_resources = sv.num_resources + 1;
      sv.resourcelist[iVar5].type = t_model;
      Q_strncpy(prVar1->szFileName,pcVar6,0x3f);
      sv.resourcelist[iVar5].nIndex = iVar8;
      sv.resourcelist[iVar5].szFileName[0x3f] = '\0';
      sv.resourcelist[iVar5].nDownloadSize = uVar10;
      sv.resourcelist[iVar5].ucFlags = uVar2;
      pcVar6 = sv.model_precache[iVar8 + 1];
      iVar8 = iVar8 + 1;
    } while (pcVar6 != (char *)0x0);
  }
  if (0 < sv_decalnamecount) {
    iVar8 = 0;
    do {
      iVar7 = Draw_DecalSize(iVar8);
      iVar5 = sv.num_resources;
                    /* Unresolved local var: resource_t * r@[???] */
      prVar1 = sv.resourcelist + sv.num_resources;
      if (0x4ff < sv.num_resources) {
        Sys_Error("Too many resources on server.");
      }
      sv.num_resources = sv.num_resources + 1;
      sv.resourcelist[iVar5].type = t_decal;
      Q_strncpy(prVar1->szFileName,sv_decalnames[iVar8].name,0x3f);
      sv.resourcelist[iVar5].nIndex = iVar8;
      iVar4 = sv_decalnamecount;
      iVar8 = iVar8 + 1;
      sv.resourcelist[iVar5].szFileName[0x3f] = '\0';
      sv.resourcelist[iVar5].nDownloadSize = iVar7;
      sv.resourcelist[iVar5].ucFlags = '\0';
    } while (iVar8 < iVar4);
  }
  ppcVar9 = &sv.event_precache[1].pszScript;
  iVar8 = 1;
  do {
    iVar5 = sv.num_resources;
    if (*ppcVar9 == (char *)0x0) {
      return;
    }
                    /* Unresolved local var: resource_t * r@[???] */
    iVar7 = (int)ppcVar9[-1];
    pcVar6 = ppcVar9[-2];
    prVar1 = sv.resourcelist + sv.num_resources;
    if (0x4ff < sv.num_resources) {
      Sys_Error("Too many resources on server.");
    }
    sv.num_resources = sv.num_resources + 1;
    ppcVar9 = ppcVar9 + 4;
    sv.resourcelist[iVar5].type = t_eventscript;
    Q_strncpy(prVar1->szFileName,pcVar6,0x3f);
    sv.resourcelist[iVar5].nIndex = iVar8;
    iVar8 = iVar8 + 1;
    sv.resourcelist[iVar5].szFileName[0x3f] = '\0';
    sv.resourcelist[iVar5].nDownloadSize = iVar7;
    sv.resourcelist[iVar5].ucFlags = '\x01';
  } while (iVar8 != 0x100);
  return;
}


// SV_Customization  @ 000b67d0
void __regparm3 SV_Customization(client_t *pPlayer,resource_t *pResource,qboolean bSkipPlayer)

{
  int iVar1;
  int iVar2;
  int c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int nPlayerNumber@[???] */
  host_client = svs.clients;
  if (svs.maxclients < 1) {
LAB_000b696e:
    Sys_Error("Couldn\'t find player index for customization.");
  }
  else {
    c = 0;
    if (svs.clients != pPlayer) {
      c = 0;
      do {
        c = c + 1;
        host_client = host_client + 1;
        if (c == svs.maxclients) goto LAB_000b696e;
      } while (pPlayer != host_client);
      host_client = pPlayer;
      if (c == -1) goto LAB_000b696e;
    }
    iVar2 = 0;
    host_client = svs.clients;
    iVar1 = svs.maxclients;
    do {
      while ((((host_client->active == false && (host_client->spawned == false)) ||
              (host_client->fakeclient != false)) || (pPlayer == host_client))) {
        iVar2 = iVar2 + 1;
        host_client = host_client + 1;
        if (iVar1 <= iVar2) {
          return;
        }
      }
      MSG_WriteByte(&(host_client->netchan).message,0x2e);
      MSG_WriteByte(&(host_client->netchan).message,c);
      MSG_WriteByte(&(host_client->netchan).message,pResource->type);
      MSG_WriteString(&(host_client->netchan).message,pResource->szFileName);
      MSG_WriteShort(&(host_client->netchan).message,pResource->nIndex);
      MSG_WriteLong(&(host_client->netchan).message,pResource->nDownloadSize);
      MSG_WriteByte(&(host_client->netchan).message,(uint)pResource->ucFlags);
      if ((pResource->ucFlags & 4) != 0) {
        SZ_Write(&(host_client->netchan).message,pResource->rgucMD5_hash,0x10);
      }
      iVar2 = iVar2 + 1;
      host_client = host_client + 1;
      iVar1 = svs.maxclients;
    } while (iVar2 < svs.maxclients);
  }
  return;
}


// SV_Customization  @ 000b6d30
void SV_Customization(client_t *pPlayer,resource_t *pResource,qboolean bSkipPlayer)

{
  int iVar1;
  int iVar2;
  int local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int nPlayerNumber@[???] */
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    if (svs.clients == pPlayer) {
      local_24 = 0;
    }
    else {
      local_24 = 0;
      do {
        local_24 = local_24 + 1;
        host_client = host_client + 1;
        if (local_24 == svs.maxclients) goto LAB_000b6eee;
      } while (pPlayer != host_client);
      host_client = pPlayer;
      if (local_24 == -1) goto LAB_000b6eee;
    }
    iVar2 = 0;
    host_client = svs.clients;
    iVar1 = svs.maxclients;
    do {
      while ((((host_client->active == false && (host_client->spawned == false)) ||
              (host_client->fakeclient != false)) ||
             ((pPlayer == host_client && (bSkipPlayer != false))))) {
        iVar2 = iVar2 + 1;
        host_client = host_client + 1;
        if (iVar1 <= iVar2) {
          return;
        }
      }
      MSG_WriteByte(&(host_client->netchan).message,0x2e);
      MSG_WriteByte(&(host_client->netchan).message,local_24);
      MSG_WriteByte(&(host_client->netchan).message,pResource->type);
      MSG_WriteString(&(host_client->netchan).message,pResource->szFileName);
      MSG_WriteShort(&(host_client->netchan).message,pResource->nIndex);
      MSG_WriteLong(&(host_client->netchan).message,pResource->nDownloadSize);
      MSG_WriteByte(&(host_client->netchan).message,(uint)pResource->ucFlags);
      if ((pResource->ucFlags & 4) != 0) {
        SZ_Write(&(host_client->netchan).message,pResource->rgucMD5_hash,0x10);
      }
      iVar2 = iVar2 + 1;
      host_client = host_client + 1;
      iVar1 = svs.maxclients;
    } while (iVar2 < svs.maxclients);
    return;
  }
LAB_000b6eee:
  Sys_Error("Couldn\'t find player index for customization.");
  return;
}


// SV_DeallocateDynamicData  @ 0009c6a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_DeallocateDynamicData(void)

{
  if (g_moved_edict != (edict_t_conflict **)0x0) {
    Mem_Free(g_moved_edict);
  }
  if (g_moved_from != (vec3_t *)0x0) {
    Mem_Free(g_moved_from);
  }
  g_moved_edict = (edict_t_conflict **)0x0;
  g_moved_from = (vec3_t *)0x0;
  return;
}


// SV_DelLogAddress_f  @ 0009b620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_DelLogAddress_f(void)

{
  loglist *plVar1;
  netadr_t a;
  LOGLIST_T *pLVar2;
  int iVar3;
  char *pcVar4;
  char *str;
  qboolean qVar5;
  LOGLIST_T *__ptr;
  uchar *puVar6;
  uchar *puVar7;
  bool bVar8;
  byte bVar9;
  LOGLIST_T *local_150;
  char local_140 [260];
  netadr_t local_3c [2];
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nPort@[???]
                       Unresolved local var: char[260] szAdr@[???]
                       Unresolved local var: netadr_t adr@[???] */
  bVar9 = 0;
  iVar3 = Cmd_Argc();
  if (iVar3 == 3) {
    pcVar4 = Cmd_Argv(1);
    str = Cmd_Argv(2);
    iVar3 = Q_atoi(str);
    if (iVar3 == 0) {
      Con_Printf("logaddress_del:  must specify a valid port\n");
    }
    else {
      if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
        Con_Printf("logaddress_del:  unparseable address\n");
        return;
      }
      snprintf(local_140,0x104,"%s:%i",pcVar4,iVar3);
      qVar5 = NET_StringToAdr(local_140,local_3c);
      if (qVar5 == false) {
        Con_Printf("logaddress_del:  unable to resolve %s\n",local_140);
      }
      else {
        if (firstLog != (LOGLIST_T *)0x0) {
          bVar8 = true;
                    /* Unresolved local var: LOGLIST_T * list@[???]
                       Unresolved local var: LOGLIST_T * prev@[???]
                       Unresolved local var: char found@[???] */
          local_150 = (LOGLIST_T *)0x0;
          pLVar2 = firstLog;
          do {
            __ptr = pLVar2;
            iVar3 = 4;
            puVar6 = (__ptr->log).net_address.ip;
            puVar7 = local_3c[0].ip;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar8 = *puVar6 == *puVar7;
              puVar6 = puVar6 + (uint)bVar9 * -2 + 1;
              puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
            } while (bVar8);
            if ((bVar8) && (local_3c[0].port == (__ptr->log).net_address.port)) {
              if (local_150 == (LOGLIST_T *)0x0) {
                firstLog = (LOGLIST_T *)0x0;
              }
              else {
                local_150->next = __ptr->next;
              }
              a.ip[0] = local_3c[0].ip[0];
              a.ip[1] = local_3c[0].ip[1];
              a.ip[2] = local_3c[0].ip[2];
              a.ip[3] = local_3c[0].ip[3];
              a.type = local_3c[0].type;
              a.ipx[0] = local_3c[0].ipx[0];
              a.ipx[1] = local_3c[0].ipx[1];
              a.ipx[2] = local_3c[0].ipx[2];
              a.ipx[3] = local_3c[0].ipx[3];
              a.ipx[4] = local_3c[0].ipx[4];
              a.ipx[5] = local_3c[0].ipx[5];
              a.ipx[6] = local_3c[0].ipx[6];
              a.ipx[7] = local_3c[0].ipx[7];
              a.ipx[8] = local_3c[0].ipx[8];
              a.ipx[9] = local_3c[0].ipx[9];
              a.port = local_3c[0].port;
              pcVar4 = NET_AdrToString(a);
              Con_Printf("deleting:  %s\n",pcVar4);
              free(__ptr);
              return;
            }
            if (__ptr->next == (loglist *)0x0) {
              Con_Printf("logaddress_del:  Couldn\'t find address in list\n");
              return;
            }
            bVar8 = false;
            pLVar2 = __ptr->next;
            local_150 = __ptr;
          } while( true );
        }
        Con_Printf("logaddress_del:  No addresses added yet\n");
      }
    }
  }
  else {
    Con_Printf("logaddress_del:  usage\nlogaddress_del ip port\n");
    for (plVar1 = firstLog; plVar1 != (LOGLIST_T *)0x0; plVar1 = plVar1->next) {
                    /* Unresolved local var: LOGLIST_T * list@[???] */
      pcVar4 = NET_AdrToString((plVar1->log).net_address);
      Con_Printf("current:  %s\n",pcVar4);
    }
  }
  return;
}


// SV_DownloadingModules  @ 0009c2f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_DownloadingModules(void)

{
  char local_40 [64];
  
                    /* Unresolved local var: char[52] message@[???] */
  builtin_strncpy(local_40,"Downloading Security Module from Speakeasy.net ...\n",0x34);
  Con_Printf(local_40);
  return;
}


// SV_DropClient  @ 00074090
void SV_DropClient(client_t *cl,qboolean crash,char *fmt,...)

{
  sizebuf_t *sb;
  float fVar1;
  int iVar2;
  double dVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint *puVar7;
  uint *puVar8;
  uint local_61c [256];
  byte local_21c;
  char local_21b [510];
  undefined1 local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[512] final@[???]
                       Unresolved local var: float connection_time@[???]
                       Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  vsnprintf((char *)local_61c,0x400,fmt,&stack0x00000010);
  if (crash == false) {
    pcVar6 = (char *)0x0;
    if (cl->fakeclient == false) {
      sb = &(cl->netchan).message;
      MSG_WriteByte(sb,2);
      MSG_WriteString(sb,(char *)local_61c);
      local_21c = '\x02';
      puVar8 = local_61c;
      do {
        puVar7 = puVar8;
        uVar4 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar5 = uVar4 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar5 == 0);
      if ((uVar4 & 0x8080) == 0) {
        puVar8 = (uint *)((int)puVar7 + 6);
        uVar5 = uVar5 >> 0x10;
      }
      pcVar6 = (char *)((int)puVar8 + (-(int)local_61c - (uint)CARRY1((byte)uVar5,(byte)uVar5)) + -2
                       );
      if ((char *)0x1ff < pcVar6) {
        pcVar6 = (char *)0x1ff;
      }
      strncpy(local_21b,(char *)local_61c,(size_t)pcVar6);
      local_1d = 0;
      puVar8 = local_61c;
      do {
        puVar7 = puVar8;
        uVar4 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar5 = uVar4 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar5 == 0);
      if ((uVar4 & 0x8080) == 0) {
        puVar8 = (uint *)((int)puVar7 + 6);
        uVar5 = uVar5 >> 0x10;
      }
      iVar2 = (-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)local_61c;
      pcVar6 = (char *)0x200;
      if ((char *)((int)puVar8 + iVar2 + 1) < (char *)0x200) {
        pcVar6 = (char *)((int)puVar8 + iVar2 + 2);
      }
    }
    if ((cl->edict != (edict_t_conflict *)0x0) && (cl->spawned != false)) {
      (*gEntityInterface.pfnClientDisconnect)(cl->edict);
    }
    Sys_Printf("Dropped %s from server\nReason:  %s\n",cl->name,local_61c);
    if (cl->fakeclient == false) {
      Netchan_Transmit(&cl->netchan,(int)pcVar6,&local_21c);
    }
  }
  fVar1 = (float)realtime - (cl->netchan).connect_time;
  if (60.0 < fVar1) {
    svs.stats.cumulative_sessiontime = fVar1 + svs.stats.cumulative_sessiontime;
    svs.stats.num_sessions = svs.stats.num_sessions + 1;
  }
  Netchan_Clear(&cl->netchan);
  Steam_NotifyClientDisconnect((client_t_conflict *)cl);
  cl->fakeclient = false;
  cl->active = false;
  cl->spawned = false;
  cl->proxy = false;
  dVar3 = realtime;
  cl->connected = false;
  cl->connection_started = dVar3;
  cl->hasusrmsgs = false;
  cl->fully_connected = false;
  cl->name[0] = '\0';
  COM_ClearCustomizationList(&cl->customdata,false);
  cl->edict = (edict_t_conflict *)0x0;
  Q_memset(cl->userinfo,0,0x100);
  Q_memset(cl->physinfo,0,0x100);
  SV_FullClientUpdate(cl,&sv.reliable_datagram);
  NotifyDedicatedServerUI("UpdatePlayers");
  return;
}


// SV_Drop_f  @ 000a19b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Drop_f(void)

{
  if (cmd_source != src_command) {
    SV_FlushRedirect();
    sv_redirected = RD_NONE;
    SV_BroadcastPrintf("%s dropped\n",host_client->name);
    SV_DropClient(host_client,false,"Client sent \'drop\'");
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// SV_EmitEvents  @ 000a3c00
void SV_EmitEvents(client_t *cl,packet_entities_t *pack,sizebuf_t *msg)

{
  event_info_s *peVar1;
  uint uVar2;
  entity_state_s *peVar3;
  int iVar4;
  int iVar5;
  uint32 data;
  entity_state_s *peVar6;
  int iVar7;
  int iVar8;
  uchar local_64 [84];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int ev@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * info@[???]
                       Unresolved local var: entity_state_t * state@[???]
                       Unresolved local var: int ev_count@[???]
                       Unresolved local var: int etofind@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: event_args_t nullargs@[???] */
  Q_memset(local_64,0,0x48);
  data = 0;
  iVar4 = 0;
  do {
    if ((cl->events).ei[iVar4].index != 0) {
      data = data + 1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x40);
  if (data != 0) {
    if (0x1f < (int)data) {
      data = 0x1f;
    }
    iVar4 = 0;
    do {
      peVar1 = (cl->events).ei + iVar4;
      if (peVar1->index != 0) {
        iVar7 = (int)peVar1->entity_index;
        iVar8 = pack->num_entities;
        if (iVar8 < 1) {
LAB_000a3cc4:
          peVar1->packet_index = (short)iVar8;
          (peVar1->args).entindex = iVar7;
        }
        else {
          iVar5 = 0;
          peVar6 = pack->entities;
          if (pack->entities->number != iVar7) {
            do {
              iVar5 = iVar5 + 1;
              if (iVar5 == iVar8) goto LAB_000a3cc4;
              peVar3 = peVar6 + 1;
              peVar6 = peVar6 + 1;
            } while (peVar3->number != iVar7);
            iVar5 = (int)(short)iVar5;
          }
          peVar1->packet_index = (short)iVar5;
          uVar2 = (peVar1->args).flags;
          (peVar1->args).ducking = 0;
          if ((uVar2 & 1) == 0) {
            (peVar1->args).origin[0] = 0.0;
            (peVar1->args).origin[1] = 0.0;
            (peVar1->args).origin[2] = 0.0;
          }
          if ((uVar2 & 2) == 0) {
            (peVar1->args).angles[0] = 0.0;
            (peVar1->args).angles[1] = 0.0;
            (peVar1->args).angles[2] = 0.0;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x40);
    iVar4 = 0;
    iVar8 = 0;
    MSG_WriteByte(msg,3);
    MSG_StartBitWriting(msg);
    MSG_WriteBits(data,5);
    do {
      while( true ) {
        peVar1 = (cl->events).ei + iVar8;
        if (peVar1->index == 0) break;
        if (iVar4 < (int)data) {
          MSG_WriteBits((uint)peVar1->index,10);
          if (peVar1->packet_index == -1) {
LAB_000a3ea8:
            MSG_WriteBits(0,1);
          }
          else {
            MSG_WriteBits(1,1);
            MSG_WriteBits((int)peVar1->packet_index,0xb);
            iVar7 = Q_memcmp(local_64,&peVar1->args,0x48);
            if (iVar7 == 0) goto LAB_000a3ea8;
            MSG_WriteBits(1,1);
            DELTA_WriteDelta(local_64,(uchar *)&peVar1->args,true,g_peventdelta,(_func_void *)0x0);
          }
          if (peVar1->fire_time == 0.0) {
            MSG_WriteBits(0,1);
          }
          else {
            MSG_WriteBits(1,1);
            MSG_WriteBits((int)(peVar1->fire_time * 100.0),0x10);
          }
        }
        iVar8 = iVar8 + 1;
        iVar4 = iVar4 + 1;
        peVar1->index = 0;
        peVar1->packet_index = -1;
        peVar1->entity_index = -1;
        if (iVar8 == 0x40) goto LAB_000a3d5c;
      }
      iVar8 = iVar8 + 1;
      peVar1->packet_index = -1;
      peVar1->entity_index = -1;
    } while (iVar8 != 0x40);
LAB_000a3d5c:
    MSG_EndBitWriting(msg);
  }
  return;
}


// SV_EmitPacketEntities  @ 000a4e00
void SV_EmitPacketEntities(client_t *client,packet_entities_t *to,sizebuf_t *msg)

{
  if (client->delta_sequence != -1) {
    SV_CreatePacketEntities(sv_packet_delta,client,to,msg);
    return;
  }
  SV_CreatePacketEntities(sv_packet_nodelta,client,to,msg);
  return;
}


// SV_EmitPings  @ 000a5190
void SV_EmitPings(client_t *client,sizebuf_t *msg)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  client_s *pcVar8;
  uint32 data;
  uint32 uVar9;
  uint data_00;
  uint local_30;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int ping@[???]
                       Unresolved local var: int packet_loss@[???] */
  MSG_WriteByte(msg,0x11);
  MSG_StartBitWriting(msg);
  if (0 < svs.maxclients) {
    iVar4 = svs.maxclients;
    pcVar8 = svs.clients;
    data = 0;
    do {
      while (pcVar8->active == false) {
        data = data + 1;
        pcVar8 = pcVar8 + 1;
        if (iVar4 <= (int)data) goto LAB_000a5345;
      }
                    /* Unresolved local var: int i@[???] */
      iVar4 = (int)pcVar8 - (int)svs.clients >> 3;
      if (realtime < pcVar8->nextping) {
        data_00 = (uint)SV_GetNetInfo::lastping[iVar4 * 0x1296f21f];
        local_30 = (uint)SV_GetNetInfo::lastloss[iVar4 * -0x6d690de1];
      }
      else {
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: int idx@[???] */
        pcVar8->nextping = realtime + 2.0;
        if (pcVar8->fakeclient == false) {
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
          if (SV_UPDATE_BACKUP < 0x20) {
            iVar7 = SV_UPDATE_BACKUP / 2;
            if (iVar7 < 1) goto LAB_000a52c2;
          }
          else {
            iVar7 = 0x10;
          }
          fVar2 = 0.0;
          local_30 = 0;
          iVar5 = 0;
          do {
            fVar1 = pcVar8->frames
                    [((pcVar8->netchan).incoming_acknowledged + -1) - iVar5 & SV_UPDATE_MASK].
                    ping_time;
            if (0.0 < fVar1) {
              local_30 = local_30 + 1;
              fVar2 = fVar1 + fVar2;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar7);
          if ((local_30 == 0) || (fVar2 / (float)(int)local_30 < 0.0)) goto LAB_000a52c2;
          uVar6 = (uint)((fVar2 / (float)(int)local_30) * 1000.0);
          data_00 = uVar6 & 0xffff;
          uVar3 = (ushort)uVar6;
        }
        else {
LAB_000a52c2:
          data_00 = 0;
          uVar3 = 0;
        }
        SV_GetNetInfo::lastping[iVar4 * 0x1296f21f] = uVar3;
        local_30 = (int)pcVar8->packet_loss & 0xff;
        SV_GetNetInfo::lastloss[iVar4 * -0x6d690de1] = (uchar)(int)pcVar8->packet_loss;
      }
      pcVar8 = pcVar8 + 1;
      MSG_WriteBits(1,1);
      uVar9 = data + 1;
      MSG_WriteBits(data,5);
      MSG_WriteBits(data_00,0xc);
      MSG_WriteBits(local_30,7);
      iVar4 = svs.maxclients;
      data = uVar9;
    } while ((int)uVar9 < svs.maxclients);
  }
LAB_000a5345:
  MSG_WriteBits(0,1);
  MSG_EndBitWriting(msg);
  return;
}


// SV_EndRedirect  @ 000a1a60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_EndRedirect(void)

{
  SV_FlushRedirect();
  sv_redirected = RD_NONE;
  return;
}


// SV_EstablishTimeBase  @ 000bb340
void SV_EstablishTimeBase(client_t *cl,usercmd_t *cmds,int dropped,int numbackup,int numcmds)

{
  byte bVar1;
  double dVar2;
  int iVar3;
  byte *pbVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double runcmd_time@[???]
                       Unresolved local var: double time_at_end@[???] */
  if (dropped < 0x18) {
    if (numbackup < dropped) {
      dVar2 = 0.0;
      do {
        dropped = dropped + -1;
        dVar2 = dVar2 + (double)(cl->lastcmd).msec / 1000.0;
      } while (dropped != numbackup);
    }
    else {
      dVar2 = 0.0;
    }
    if (0 < dropped) {
                    /* Unresolved local var: int cmdnum@[???] */
      pbVar4 = &cmds[dropped + -1 + numcmds].msec;
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + -0x34;
        dropped = dropped + -1;
        dVar2 = (double)bVar1 / 1000.0 + dVar2;
      } while (dropped != 0);
    }
  }
  else {
    dVar2 = 0.0;
  }
  iVar3 = numcmds + -1;
  if (-1 < iVar3) {
    pbVar4 = &cmds[iVar3].msec;
    do {
      bVar1 = *pbVar4;
      iVar3 = iVar3 + -1;
      pbVar4 = pbVar4 + -0x34;
      dVar2 = (double)bVar1 / 1000.0 + dVar2;
    } while (iVar3 != -1);
  }
  cl->svtimebase = (sv.time + host_frametime) - dVar2;
  return;
}


// SV_EstimateNeededResources  @ 000b7110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_EstimateNeededResources(void)

{
  resource_s *prVar1;
  qboolean qVar2;
  resource_s *prVar3;
  int iVar4;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: int missing@[???]
                       Unresolved local var: int size@[???] */
  iVar4 = 0;
  prVar3 = (host_client->resourcesneeded).pNext;
  prVar1 = &host_client->resourcesneeded;
  if (prVar3 != prVar1) {
    do {
      while (prVar3->type != t_decal) {
        prVar3 = prVar3->pNext;
        if (prVar3 == prVar1) {
          return iVar4;
        }
      }
      qVar2 = HPAK_ResourceForHash("custom.hpk",prVar3->rgucMD5_hash,(resource_s *)0x0);
      if ((qVar2 == false) && (prVar3->nDownloadSize != 0)) {
        prVar3->ucFlags = prVar3->ucFlags | 2;
        iVar4 = iVar4 + prVar3->nDownloadSize;
      }
      prVar3 = prVar3->pNext;
      prVar1 = &host_client->resourcesneeded;
    } while (prVar3 != prVar1);
  }
  return iVar4;
}


// SV_ExecuteClientMessage  @ 000bb9f0
void SV_ExecuteClientMessage(client_t *cl)

{
  longdouble lVar1;
  client_frame_t *pcVar2;
  uint uVar3;
  longdouble lVar4;
  longdouble lVar5;
  float fVar6;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: client_frame_t * frame@[???] */
  g_balreadymoved = false;
  lVar4 = (longdouble)realtime;
  pcVar2 = cl->frames + (SV_UPDATE_MASK & (cl->netchan).incoming_acknowledged);
  fVar6 = (float)((lVar4 - (longdouble)pcVar2->senttime) - (longdouble)cl->next_messageinterval);
  lVar5 = (longdouble)fVar6;
  pcVar2->ping_time = fVar6;
  lVar1 = (longdouble)0;
  if ((longdouble)pcVar2->senttime == lVar1) {
    pcVar2->ping_time = (float)lVar1;
    lVar5 = lVar1;
  }
  if ((lVar4 - (longdouble)cl->connection_started < (longdouble)2.0) && ((longdouble)0 < lVar5)) {
    pcVar2->ping_time = (float)(longdouble)0;
  }
  fVar6 = SV_CalcClientTime(cl);
  sv_player = cl->edict;
  host_client = cl;
  cl->delta_sequence = -1;
  pmove = &g_svmove;
  cl->latency = fVar6;
  while( true ) {
    if (msg_badread != false) {
      Con_Printf("SV_ReadClientMessage: badread\n");
      return;
    }
    uVar3 = MSG_ReadByte();
    if (uVar3 == 0xffffffff) break;
    if (0xb < uVar3) {
      Con_Printf("SV_ReadClientMessage: unknown command char (%d)\n",uVar3);
      SV_DropClient(cl,false,"Bad command character in client command");
      return;
    }
    if (sv_clcfuncs[uVar3].pfnParse != (_func_void_client_t_ptr *)0x0) {
                    /* Unresolved local var: _func_void_client_t_ptr * func@[???] */
      (*sv_clcfuncs[uVar3].pfnParse)(cl);
    }
  }
  return;
}


// SV_ExtractFromUserinfo  @ 000a5950
void SV_ExtractFromUserinfo(client_t *cl)

{
  client_s *pcVar1;
  float fVar2;
  double dVar3;
  char *pcVar4;
  char *pcVar5;
  qboolean qVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  client_s *pcVar11;
  int local_68;
  char local_5c [32];
  char local_3c [31];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * val@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: int dupc@[???]
                       Unresolved local var: char[32] newname@[???]
                       Unresolved local var: char[32] rawname@[???] */
  pcVar9 = cl->userinfo;
  pcVar4 = Info_ValueForKey(pcVar9,"name");
  Q_strncpy(local_3c,pcVar4,0x1f);
  local_1d = 0;
  Q_strcpy(local_5c,local_3c);
  pcVar5 = local_5c;
  while (local_5c[0] == '#') {
    *pcVar5 = ' ';
    pcVar5 = pcVar5 + 1;
    local_5c[0] = *pcVar5;
  }
  TrimSpace(local_5c,local_3c);
  qVar6 = Q_UnicodeValidate(local_3c);
  if (qVar6 == 0) {
    Q_UnicodeRepair(local_3c);
  }
  iVar7 = Q_strlen(local_3c);
  if ((((iVar7 < 1) || (iVar7 = Q_stricmp(local_3c,"console"), iVar7 == 0)) ||
      (pcVar5 = Q_strstr(local_3c,".."), pcVar5 != (char *)0x0)) ||
     ((pcVar5 = Q_strstr(local_3c,"\""), pcVar5 != (char *)0x0 ||
      (pcVar5 = Q_strstr(local_3c,"\\"), pcVar5 != (char *)0x0)))) {
    pcVar5 = "unnamed";
  }
  else {
    iVar7 = Q_strcmp(pcVar4,local_3c);
    if (iVar7 == 0) goto LAB_000a5a5c;
    pcVar5 = local_3c;
  }
  Info_SetValueForKey(pcVar9,"name",pcVar5,0x100);
  pcVar4 = Info_ValueForKey(pcVar9,"name");
LAB_000a5a5c:
  local_68 = 1;
  do {
    pcVar1 = svs.clients + 0x20;
    pcVar11 = svs.clients;
    while (((pcVar11->active == false || (pcVar11->spawned == false)) ||
           ((pcVar11 == cl || (iVar7 = Q_stricmp(pcVar11->name,pcVar4), iVar7 != 0))))) {
      pcVar11 = pcVar11 + 1;
      if (pcVar11 == pcVar1) {
        pcVar5 = cl->name;
        (*gEntityInterface.pfnClientUserInfoChanged)(cl->edict,pcVar9);
        pcVar4 = Info_ValueForKey(pcVar9,"name");
        Q_strncpy(pcVar5,pcVar4,0x1f);
        cl->name[0x1f] = '\0';
        ISteamGameServer_BUpdateUserData((cl->network_userid).m_SteamID,pcVar5,0);
        pcVar4 = Info_ValueForKey(pcVar9,"rate");
        iVar7 = Q_strlen(pcVar4);
        if (iVar7 != 0) {
          iVar7 = Q_atoi(pcVar4);
          if (iVar7 < 1000) {
            dVar3 = 1000.0;
          }
          else {
            iVar10 = 100000;
            if (iVar7 < 0x186a1) {
              iVar10 = iVar7;
            }
            dVar3 = (double)iVar10;
          }
          (cl->netchan).rate = dVar3;
        }
        pcVar4 = Info_ValueForKey(pcVar9,"topcolor");
        iVar7 = Q_strlen(pcVar4);
        if (iVar7 == 0) {
          Con_DPrintf("topcolor unchanged for %s\n",pcVar5);
        }
        else {
          iVar7 = Q_atoi(pcVar4);
          cl->topcolor = iVar7;
        }
        pcVar4 = Info_ValueForKey(pcVar9,"bottomcolor");
        iVar7 = Q_strlen(pcVar4);
        if (iVar7 == 0) {
          Con_DPrintf("bottomcolor unchanged for %s\n",pcVar5);
        }
        else {
          iVar7 = Q_atoi(pcVar4);
          cl->bottomcolor = iVar7;
        }
        pcVar5 = Info_ValueForKey(pcVar9,"cl_updaterate");
        iVar7 = Q_strlen(pcVar5);
        if (iVar7 != 0) {
          iVar7 = Q_atoi(pcVar5);
          if (iVar7 < 10) {
            fVar2 = 0.1;
          }
          else {
            fVar2 = 1.0 / (float)iVar7;
          }
          cl->next_messageinterval = (double)fVar2;
        }
        pcVar5 = Info_ValueForKey(pcVar9,"cl_lw");
        iVar7 = Q_strlen(pcVar5);
        if (iVar7 == 0) {
          cl->lw = 0;
        }
        else {
          iVar7 = Q_atoi(pcVar5);
          cl->lw = (uint)(iVar7 != 0);
        }
        pcVar5 = Info_ValueForKey(pcVar9,"cl_lc");
        iVar7 = Q_strlen(pcVar5);
        if (iVar7 == 0) {
          cl->lc = 0;
        }
        else {
          iVar7 = Q_atoi(pcVar5);
          cl->lc = (uint)(iVar7 != 0);
        }
        pcVar9 = Info_ValueForKey(pcVar9,"*hltv");
        iVar7 = Q_strlen(pcVar9);
        if (iVar7 == 0) {
          cl->proxy = false;
        }
        else {
          iVar7 = Q_atoi(pcVar9);
          cl->proxy = (uint)(iVar7 == 1);
        }
        SV_CheckUpdateRate(&cl->next_messageinterval);
        if ((0.0 < sv_maxrate.value) && (sv_maxrate.value < (float)(cl->netchan).rate)) {
          if (100000.0 <= sv_maxrate.value) {
            (cl->netchan).rate = 100000.0;
          }
          else {
            (cl->netchan).rate = (double)sv_maxrate.value;
          }
        }
        if ((0.0 < sv_minrate.value) && ((float)(cl->netchan).rate < sv_minrate.value)) {
          fVar2 = sv_minrate.value;
          if (sv_minrate.value <= 1000.0) {
            fVar2 = 1000.0;
          }
          (cl->netchan).rate = (double)fVar2;
        }
        return;
      }
    }
    uVar8 = Q_strlen(pcVar4);
    if (0x1f < uVar8) {
      pcVar4[0x1c] = '\0';
    }
    if (*pcVar4 == '(') {
      if (pcVar4[2] == ')') {
        pcVar4 = pcVar4 + 3;
      }
      else if (pcVar4[3] == ')') {
        pcVar4 = pcVar4 + 4;
      }
    }
    snprintf(local_3c,0x20,"(%d)%-0.*s",local_68,0x1c,pcVar4);
    Info_SetValueForKey(pcVar9,"name",local_3c,0x100);
    pcVar4 = Info_ValueForKey(pcVar9,"name");
    local_68 = local_68 + 1;
  } while( true );
}


// SV_FailDownload  @ 000a8f00
void SV_FailDownload(char *filename)

{
  if ((filename != (char *)0x0) && (*filename != '\0')) {
    MSG_WriteByte(&(host_client->netchan).message,0x31);
    MSG_WriteString(&(host_client->netchan).message,filename);
  }
  return;
}


// SV_FatPAS  @ 000a41d0
uchar * SV_FatPAS(float *org)

{
  fatpasbytes = (sv.worldmodel)->numleafs + 0x1f >> 3;
  Q_memset(fatpas,0,fatpasbytes);
  SV_AddToFatPAS(org,(sv.worldmodel)->nodes);
  return fatpas;
}


// SV_FatPVS  @ 000a4030
uchar * SV_FatPVS(float *org)

{
  fatbytes = (sv.worldmodel)->numleafs + 0x1f >> 3;
  Q_memset(fatpvs,0,fatbytes);
  SV_AddToFatPVS(org,(sv.worldmodel)->nodes);
  return fatpvs;
}


// SV_FileInConsistencyList  @ 000b86f0
qboolean SV_FileInConsistencyList(char *filename,consistency_t **ppconsist)

{
  qboolean qVar1;
  int iVar2;
  char *s2;
  consistency_t *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  qVar1 = false;
  if (sv.consistency_list[0].filename != (char *)0x0) {
    pcVar3 = sv.consistency_list;
    iVar4 = 0;
    s2 = sv.consistency_list[0].filename;
    while( true ) {
      pcVar3 = pcVar3 + 1;
      iVar2 = Q_stricmp(filename,s2);
      if (iVar2 == 0) break;
      iVar4 = iVar4 + 1;
      s2 = pcVar3->filename;
      if (s2 == (char *)0x0) {
        return false;
      }
    }
    qVar1 = true;
    if (ppconsist != (consistency_t **)0x0) {
      *ppconsist = sv.consistency_list + iVar4;
    }
  }
  return qVar1;
}


// SV_FilterPacket  @ 000a2db0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SV_FilterPacket(void)

{
  uchar auVar1 [4];
  ipfilter_t *piVar2;
  uint *puVar3;
  int iVar4;
  qboolean local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint in@[???] */
  auVar1 = net_from.ip;
  if (-1 < numipfilters + -1) {
    puVar3 = &ipfilters[numipfilters + -1].compare;
    iVar4 = numipfilters;
    do {
      if (((*puVar3 == 0xffffffff) || ((float)puVar3[1] == 0.0)) ||
         ((float)realtime < (float)puVar3[1])) {
        if (*puVar3 == (((ipfilter_t *)(puVar3 + -1))->mask & (uint)auVar1)) {
          local_24 = (qboolean)(longlong)ROUND(sv_filterban.value);
          return local_24;
        }
      }
      else {
        if (iVar4 < numipfilters) {
          piVar2 = ipfilters + iVar4;
          do {
            piVar2[-1].mask = piVar2->mask;
            piVar2[-1].compare = piVar2->compare;
            piVar2[-1].banEndTime = piVar2->banEndTime;
            piVar2[-1].banTime = piVar2->banTime;
            piVar2 = piVar2 + 1;
          } while (piVar2 != ipfilters + numipfilters);
        }
        numipfilters = numipfilters + -1;
      }
      puVar3 = puVar3 + -4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return (uint)(sv_filterban.value == 0.0);
}


// SV_FilterUser  @ 000ab800
qboolean SV_FilterUser(USERID_t *userid)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  userfilter_t *puVar5;
  float *pfVar6;
  qboolean local_ac;
  char local_9c [63];
  undefined1 local_5d;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (-1 < numuserfilters + -1) {
    pfVar6 = &userfilters[numuserfilters + -1].banEndTime;
    iVar4 = numuserfilters;
    do {
      iVar1 = iVar4 + -1;
      if ((*pfVar6 == 0.0) || ((float)realtime < *pfVar6)) {
        if (userid != (USERID_t *)0x0) {
          if ((userid->idtype == userfilters[iVar1].userid.idtype) && (userid->idtype - 1U < 2)) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
            pcVar3 = SV_GetIDString(userid);
            strncpy(local_9c,pcVar3,0x3f);
            local_5d = 0;
            pcVar3 = SV_GetIDString(&userfilters[iVar1].userid);
            strncpy(local_5c,pcVar3,0x3f);
            local_1d = 0;
            iVar4 = strcasecmp(local_9c,local_5c);
            if (iVar4 == 0) {
              local_ac = (qboolean)(longlong)ROUND(sv_filterban.value);
              return local_ac;
            }
          }
        }
      }
      else {
        if (iVar4 < numuserfilters) {
          puVar5 = userfilters + iVar4;
          do {
            uVar2 = 0;
            do {
              *(undefined4 *)((int)&puVar5[-1].userid.idtype + uVar2) =
                   *(undefined4 *)((int)&(puVar5->userid).idtype + uVar2);
              uVar2 = uVar2 + 4;
            } while (uVar2 < 0x18);
            puVar5 = puVar5 + 1;
          } while (puVar5 != userfilters + numuserfilters);
        }
        numuserfilters = numuserfilters + -1;
      }
      pfVar6 = pfVar6 + -6;
      iVar4 = iVar1;
    } while (iVar1 != 0);
  }
  return (uint)(sv_filterban.value == 0.0);
}


// SV_FindBestBaseline  @ 000a4550
int SV_FindBestBaseline(int index,entity_state_t **baseline,entity_state_t *to,int num,
                       qboolean custom)

{
  int iVar1;
  delta_t *pdVar2;
  int iVar3;
  int iVar4;
  entity_state_t *to_00;
  entity_state_t *peVar5;
  int local_20;
  
                    /* Unresolved local var: int bestbitnumber@[???]
                       Unresolved local var: int bitnumber@[???]
                       Unresolved local var: int bestfound@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = index + -1;
  pdVar2 = g_pcustomentitydelta;
  if (((custom == false) && (pdVar2 = g_pentitydelta, 0 < num)) && (num <= svs.maxclients)) {
    pdVar2 = g_pplayerdelta;
  }
  to_00 = to + index;
  iVar1 = DELTA_TestDelta((uchar *)*baseline,(uchar *)to_00,pdVar2);
  iVar1 = iVar1 + -6;
  if ((iVar1 < 1) || (iVar4 < 0)) {
    iVar4 = 0;
  }
  else {
    if (num < 1) {
      if (custom == false) {
        peVar5 = to + iVar4;
        local_20 = index;
        do {
          if ((to_00->entityType == peVar5->entityType) &&
             (iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,g_pentitydelta), iVar3 < iVar1)
             ) {
            iVar1 = iVar3;
            local_20 = iVar4;
          }
          iVar4 = iVar4 + -1;
        } while (((0 < iVar1) && (-1 < iVar4)) && (peVar5 = peVar5 + -1, iVar4 != index + -0x3f));
      }
      else {
        peVar5 = to + iVar4;
        local_20 = index;
        do {
          if ((to_00->entityType == peVar5->entityType) &&
             (iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,g_pcustomentitydelta),
             iVar3 < iVar1)) {
            iVar1 = iVar3;
            local_20 = iVar4;
          }
          iVar4 = iVar4 + -1;
        } while (((0 < iVar1) && (-1 < iVar4)) && (peVar5 = peVar5 + -1, iVar4 != index + -0x3f));
      }
    }
    else if (custom == false) {
      peVar5 = to + iVar4;
      local_20 = index;
      do {
        if (to_00->entityType == peVar5->entityType) {
          pdVar2 = g_pplayerdelta;
          if (svs.maxclients < num) {
            pdVar2 = g_pentitydelta;
          }
          iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,pdVar2);
          if (iVar3 < iVar1) {
            iVar1 = iVar3;
            local_20 = iVar4;
          }
        }
      } while (((0 < iVar1) && (iVar4 = iVar4 + -1, -1 < iVar4)) &&
              (peVar5 = peVar5 + -1, iVar4 != index + -0x3f));
    }
    else {
      peVar5 = to + iVar4;
      local_20 = index;
      do {
        if ((to_00->entityType == peVar5->entityType) &&
           (iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,g_pcustomentitydelta),
           iVar3 < iVar1)) {
          iVar1 = iVar3;
          local_20 = iVar4;
        }
        iVar4 = iVar4 + -1;
      } while (((0 < iVar1) && (-1 < iVar4)) && (peVar5 = peVar5 + -1, iVar4 != index + -0x3f));
    }
    iVar4 = index - local_20;
    if (iVar4 != 0) {
      *baseline = to + local_20;
    }
  }
  return iVar4;
}


// SV_FindEmptySlot  @ 0009fcb0
int SV_FindEmptySlot(netadr_t *adr,int *pslot,client_t **ppClient)

{
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int slot@[???]
                       Unresolved local var: int clients@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar2 = 0;
    pcVar1 = svs.clients;
    do {
      if (((pcVar1->active == false) && (pcVar1->spawned == false)) && (pcVar1->connected == false))
      {
        if (iVar2 < svs.maxclients) {
          *pslot = iVar2;
          *ppClient = pcVar1;
          return 1;
        }
        break;
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 != svs.maxclients);
  }
  SV_RejectConnection(adr,"Server is full.\n");
  return 0;
}


// SV_FindEntInPack  @ 000b9c70
entity_state_t * SV_FindEntInPack(int index,packet_entities_t *pack)

{
  entity_state_t *peVar1;
  entity_state_t *peVar2;
  entity_state_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  peVar3 = (entity_state_t *)0x0;
  if ((0 < pack->num_entities) && (peVar3 = pack->entities, peVar3->number != index)) {
    iVar4 = 0;
    peVar1 = peVar3;
    do {
      peVar3 = peVar1 + 1;
      iVar4 = iVar4 + 1;
      if (iVar4 == pack->num_entities) {
        return (entity_state_t *)0x0;
      }
      peVar2 = peVar1 + 1;
      peVar1 = peVar3;
    } while (peVar2->number != index);
  }
  return peVar3;
}


// SV_FindModelNumbers  @ 0009ca00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_FindModelNumbers(void)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  sv_playermodel = -1;
  do {
    if (sv.model_precache[iVar2] == (char *)0x0) {
      return;
    }
    iVar1 = Q_strcasecmp(sv.model_precache[iVar2],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x200);
  return;
}


// SV_FindTouchedLeafs  @ 000bf5b0
void SV_FindTouchedLeafs(edict_t_conflict *ent,mnode_t *node,int *topnode)

{
  byte bVar1;
  mplane_t *p;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: mleaf_t * leaf@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: int leafnum@[???] */
  if (node->contents == -2) {
    return;
  }
  if (-1 < node->contents) {
    do {
      p = node->plane;
      bVar1 = p->type;
      if (bVar1 < 3) {
        uVar4 = 0;
        if (p->dist <= (ent->v).absmin[bVar1]) goto LAB_000bf5f2;
        if (p->dist < (ent->v).absmax[bVar1]) goto LAB_000bf650;
      }
      else {
        uVar3 = BoxOnPlaneSide((ent->v).absmin,(ent->v).absmax,p);
        if (uVar3 == 3) {
LAB_000bf650:
          if (*topnode == -1) {
            *topnode = ((int)node - (int)(sv.worldmodel)->nodes >> 3) * -0x33333333;
          }
          uVar4 = 2;
        }
        else {
          uVar4 = uVar3 & 2;
          if ((uVar3 & 1) == 0) {
            if (uVar4 == 0) {
              return;
            }
            goto LAB_000bf611;
          }
        }
LAB_000bf5f2:
        SV_FindTouchedLeafs(ent,node->children[0],topnode);
        if (uVar4 == 0) {
          return;
        }
      }
LAB_000bf611:
      node = node->children[1];
      if (node->contents == -2) {
        return;
      }
    } while (-1 < node->contents);
  }
  iVar2 = ent->num_leafs;
  if (0x2f < iVar2) {
    ent->num_leafs = 0x31;
    return;
  }
  ent->leafnums[iVar2] = (short)((int)node - (int)(sv.worldmodel)->leafs >> 4) * -0x5555 + -1;
  ent->num_leafs = iVar2 + 1;
  return;
}


// SV_FinishCertificateCheck  @ 0009f430
int SV_FinishCertificateCheck(netadr_t *adr,int nAuthProtocol,char *szRawCertificate,char *userinfo)

{
  int iVar1;
  char *str;
  
                    /* Unresolved local var: int nHashCount@[???]
                       Unresolved local var: char * val@[???] */
  if (nAuthProtocol != 2) {
    iVar1 = strcasecmp(szRawCertificate,"steam");
    if (iVar1 == 0) {
      return 1;
    }
    SV_RejectConnection(adr,"Expecting STEAM authentication USERID ticket!\n");
    return 0;
  }
  iVar1 = Q_strlen(szRawCertificate);
  if (iVar1 == 0x20) {
    if (adr->type == NA_LOOPBACK) {
      return 1;
    }
    str = Info_ValueForKey(userinfo,"*hltv");
    iVar1 = Q_strlen(str);
                    /* Unresolved local var: int i@[???] */
    if ((iVar1 != 0) && (iVar1 = Q_atoi(str), iVar1 == 1)) {
      return 1;
    }
  }
  SV_RejectConnection(adr,"Invalid CD Key.\n");
  return 0;
}


// SV_FixCheckBottom  @ 000af860
void SV_FixCheckBottom(edict_t_conflict *ent)

{
  int *piVar1;
  
  piVar1 = &(ent->v).flags;
  *piVar1 = *piVar1 | 0x400;
  return;
}


// SV_FixupGravityVelocity  @ 000b2640
void SV_FixupGravityVelocity(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  fVar1 = (ent->v).gravity;
  fVar2 = 1.0;
  if (fVar1 != 0.0) {
    fVar2 = fVar1;
  }
  (ent->v).velocity[2] =
       (ent->v).velocity[2] - fVar2 * sv_gravity.value * (float)host_frametime * 0.5;
  SV_CheckVelocity(ent);
  return;
}


// SV_FlushRedirect  @ 000a1870
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_FlushRedirect(void)

{
  int iVar1;
  int iVar2;
  int iStackY_50;
  netadr_t nStack_40;
  char *local_20;
  undefined2 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  
  if (sv_redirected == RD_PACKET) {
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar * data@[???] */
    iStackY_50 = 0xa18dc;
    iVar1 = Q_strlen(outputbuf);
    local_20 = "Redirected Text";
    iVar1 = -(iVar1 + 0x25U & 0xfffffff0);
    *(char **)(&stack0xffffffb4 + iVar1) = outputbuf;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0xa18fb;
    iVar2 = Q_strlen(*(char **)(&stack0xffffffb4 + iVar1));
    local_18 = (int)&local_20 + iVar1;
    local_10 = 0;
    local_1c = 1;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_20;
    local_14 = iVar2 + 7;
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = 0xffffffff;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0xa1928;
    MSG_WriteLong(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1));
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = 0x6c;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_20;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0xa1939;
    MSG_WriteByte(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1));
    *(char **)(&stack0xffffffb8 + iVar1) = outputbuf;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_20;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0xa194a;
    MSG_WriteString(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(char **)(&stack0xffffffb8 + iVar1));
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = 0;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_20;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0xa1958;
    MSG_WriteByte(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1));
    *(undefined4 *)(&stack0xffffffb4 + iVar1) = 1;
    *(netadrtype_t *)((int)&nStack_40 + iVar1) = sv_redirectto.type;
    *(uchar (*) [4])((int)&nStack_40 + iVar1 + 4) = sv_redirectto.ip;
    *(undefined4 *)((int)&nStack_40 + iVar1 + 8) = sv_redirectto.ipx._0_4_;
    *(undefined4 *)((int)&nStack_40 + iVar1 + 0xc) = sv_redirectto.ipx._4_4_;
    *(undefined4 *)((int)&nStack_40 + iVar1 + 0x10) = sv_redirectto._16_4_;
    *(int *)(&stack0xffffffbc + iVar1) = local_18;
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = local_10;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0xa199f;
    NET_SendPacket(*(netsrc_t *)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1),
                   *(void **)(&stack0xffffffbc + iVar1),*(netadr_t *)((int)&nStack_40 + iVar1));
  }
  else if (sv_redirected == RD_CLIENT) {
    iStackY_50 = 0xa18ae;
    MSG_WriteByte(&(host_client->netchan).message,8);
    iStackY_50 = 0xa18c2;
    MSG_WriteString(&(host_client->netchan).message,outputbuf);
    outputbuf[0] = '\0';
    return;
  }
  outputbuf[0] = '\0';
  return;
}


// SV_FlyDirection  @ 000af820
qboolean SV_FlyDirection(edict_t_conflict *ent,vec_t *direction)

{
  qboolean qVar1;
  qboolean in_ECX;
  
                    /* Unresolved local var: vec3_t oldorigin@[???] */
  qVar1 = SV_movestep(ent,direction,in_ECX);
  if (qVar1 == false) {
    SV_LinkEdict(ent,true);
    return false;
  }
  SV_LinkEdict(ent,true);
  return true;
}


// SV_FlyMove  @ 000b1e90
int SV_FlyMove(edict_t_conflict *ent,float time,trace_t *steptrace)

{
  vec_t *maxs;
  vec_t *mins;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  qboolean monsterClipBrush;
  uint uVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  vec_t *normal;
  float fVar12;
  float local_178;
  int local_174;
  uint local_170;
  trace_t local_14c;
  vec_t local_10c [2];
  float local_104;
  vec_t local_100 [13];
  trace_t tStack_cc;
  trace_t tStack_94;
  float local_5c;
  float local_58;
  float local_54;
  float local_4c;
  float local_48;
  float fStack_44;
  float local_34;
  float local_30;
  float fStack_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int bumpcount@[???]
                       Unresolved local var: int numbumps@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: int numplanes@[???]
                       Unresolved local var: vec_t[5][3] planes@[???]
                       Unresolved local var: vec3_t primal_velocity@[???]
                       Unresolved local var: vec3_t original_velocity@[???]
                       Unresolved local var: vec3_t new_velocity@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: trace_t test@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: float time_left@[???]
                       Unresolved local var: int blocked@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  fVar1 = (ent->v).velocity[0];
  maxs = (ent->v).maxs;
  fVar2 = (ent->v).velocity[1];
  monsterClipBrush = (qboolean)(((ent->v).flags & 0x800000) != 0);
  iVar11 = 0;
  fVar3 = (ent->v).velocity[2];
  mins = (ent->v).mins;
  local_174 = 4;
  local_170 = 0;
  local_178 = time;
  fVar5 = fVar3;
  fVar4 = fVar2;
  fVar12 = fVar1;
  local_5c = fVar1;
  local_58 = fVar2;
  local_54 = fVar3;
  do {
    if (((fVar12 == 0.0) && (fVar4 == 0.0)) && (fVar5 == 0.0)) {
      return local_170;
    }
    local_28 = fVar12 * local_178 + (ent->v).origin[0];
    local_24 = fVar4 * local_178 + (ent->v).origin[1];
    local_20 = fVar5 * local_178 + (ent->v).origin[2];
    SV_Move(&local_14c,(ent->v).origin,mins,maxs,&local_28,0,ent,monsterClipBrush);
    uVar7 = 0;
    do {
      *(undefined4 *)((int)tStack_cc.endpos + (uVar7 - 0x14)) =
           *(undefined4 *)((int)local_14c.endpos + (uVar7 - 0x14));
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x38);
    if (tStack_cc.allsolid != false) {
      (ent->v).velocity[0] = vec3_origin[0];
      (ent->v).velocity[1] = vec3_origin[1];
      (ent->v).velocity[2] = vec3_origin[2];
      return 4;
    }
    iVar10 = iVar11;
    if ((0.0 < tStack_cc.fraction) &&
       (SV_Move(&tStack_94,tStack_cc.endpos,mins,maxs,tStack_cc.endpos,0,ent,monsterClipBrush),
       tStack_94.allsolid != true)) {
      (ent->v).origin[0] = tStack_cc.endpos[0];
      (ent->v).origin[1] = tStack_cc.endpos[1];
      (ent->v).origin[2] = tStack_cc.endpos[2];
      local_5c = (ent->v).velocity[0];
      local_58 = (ent->v).velocity[1];
      local_54 = (ent->v).velocity[2];
      iVar10 = 0;
    }
    if (tStack_cc.fraction == 1.0) {
      return local_170;
    }
    if (tStack_cc.ent == (edict_t_conflict *)0x0) {
      Sys_Error("SV_FlyMove: !trace.ent");
    }
    if (0.7 < tStack_cc.plane.normal[2]) {
      local_170 = local_170 | 1;
      iVar11 = ((tStack_cc.ent)->v).solid;
      if ((iVar11 == 4) || (((tStack_cc.ent)->v).movetype == 0xd)) {
        uVar7 = (ent->v).flags;
      }
      else {
        uVar7 = (ent->v).flags;
        if ((iVar11 != 3) && ((uVar7 & 8) == 0)) goto LAB_000b204e;
      }
      (ent->v).flags = uVar7 | 0x200;
      (ent->v).groundentity = tStack_cc.ent;
    }
LAB_000b204e:
    if ((tStack_cc.plane.normal[2] == 0.0) &&
       (local_170 = local_170 | 2, steptrace != (trace_t *)0x0)) {
      uVar7 = 0;
      do {
        *(undefined4 *)((int)steptrace->endpos + (uVar7 - 0x14)) =
             *(undefined4 *)((int)tStack_cc.endpos + (uVar7 - 0x14));
        uVar7 = uVar7 + 4;
      } while (uVar7 < 0x38);
    }
    SV_Impact(ent,tStack_cc.ent,&tStack_cc);
    fVar6 = tStack_cc.fraction;
    if (ent->free != 0) {
      return local_170;
    }
    if (4 < iVar10) {
LAB_000b252c:
      (ent->v).velocity[0] = vec3_origin[0];
      (ent->v).velocity[1] = vec3_origin[1];
      (ent->v).velocity[2] = vec3_origin[2];
      return local_170;
    }
    iVar11 = iVar10 + 1;
    local_10c[iVar10 * 3] = tStack_cc.plane.normal[0];
    local_10c[iVar10 * 3 + 1] = tStack_cc.plane.normal[1];
    local_100[iVar10 * 3 + -1] = tStack_cc.plane.normal[2];
    if (((iVar11 == 1) && ((ent->v).movetype == 3)) &&
       ((((ent->v).flags & 0x200) == 0 || ((ent->v).friction != 1.0)))) {
      if (local_104 <= 0.7) {
        fVar12 = (1.0 - (ent->v).friction) * sv_bounce.value + 1.0;
      }
      else {
        fVar12 = 1.0;
      }
      ClipVelocity(&local_5c,local_10c,&local_4c,fVar12);
      local_5c = local_4c;
      (ent->v).velocity[0] = local_4c;
      local_58 = local_48;
      (ent->v).velocity[1] = local_48;
      local_54 = fStack_44;
      (ent->v).velocity[2] = fStack_44;
      fVar4 = local_48;
      fVar5 = fStack_44;
      fVar12 = local_4c;
    }
    else {
      iVar10 = 0;
      normal = local_10c;
      do {
        ClipVelocity(&local_5c,normal,&local_4c,1.0);
        pfVar8 = local_10c;
        iVar9 = 0;
        do {
          if ((iVar9 != iVar10) &&
             (pfVar8[2] * fStack_44 + pfVar8[1] * local_48 + *pfVar8 * local_4c < 0.0)) break;
          iVar9 = iVar9 + 1;
          pfVar8 = pfVar8 + 3;
        } while (iVar9 < iVar11);
        if (iVar9 == iVar11) break;
        iVar10 = iVar10 + 1;
        normal = normal + 3;
      } while (iVar10 < iVar11);
      if (iVar10 == iVar11) {
        if (iVar11 != 2) {
          return local_170;
        }
        CrossProduct(local_10c,local_100,&local_34);
        VectorScale(&local_34,
                    fStack_2c * (ent->v).velocity[2] +
                    local_30 * (ent->v).velocity[1] + local_34 * (ent->v).velocity[0],
                    (ent->v).velocity);
        fVar12 = (ent->v).velocity[0];
        fVar4 = (ent->v).velocity[1];
        fVar5 = (ent->v).velocity[2];
      }
      else {
        (ent->v).velocity[0] = local_4c;
        (ent->v).velocity[1] = local_48;
        (ent->v).velocity[2] = fStack_44;
        fVar5 = fStack_44;
        fVar12 = local_4c;
        fVar4 = local_48;
      }
      if (fVar3 * fVar5 + fVar2 * fVar4 + fVar1 * fVar12 <= 0.0) goto LAB_000b252c;
    }
    local_174 = local_174 + -1;
    if (local_174 == 0) {
      return local_170;
    }
    local_178 = local_178 - fVar6 * local_178;
  } while( true );
}


// SV_ForceFullClientsUpdate  @ 000b9730
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ForceFullClientsUpdate(void)

{
  int iVar1;
  client_t *pcVar2;
  client_s *cl;
  int iVar3;
  byte local_2420 [9216];
  sizebuf_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: uchar[9216] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  Q_memset(&local_20,0,0x14);
  local_20.buffername = "Force Update";
  local_20.data = local_2420;
  local_20.cursize = 0;
  local_20.maxsize = 0x2400;
  pcVar2 = host_client;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    iVar1 = svs.maxclients;
    cl = svs.clients;
    do {
      if ((((cl == pcVar2) || (cl->active != false)) || (cl->connected != false)) ||
         (cl->spawned != false)) {
        SV_FullClientUpdate(cl,&local_20);
        iVar1 = svs.maxclients;
        pcVar2 = host_client;
      }
      iVar3 = iVar3 + 1;
      cl = cl + 1;
    } while (iVar3 < iVar1);
  }
  Con_DPrintf("Client %s started recording. Send full update.\n",pcVar2->name);
  Netchan_CreateFragments(true,&host_client->netchan,&local_20);
  Netchan_FragSend(&host_client->netchan);
  return;
}


// SV_Frame  @ 000adf40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Frame(void)

{
  float fVar1;
  int iVar2;
  client_s *pcVar3;
  int iVar4;
  
  if (sv.active == false) {
    return;
  }
  gGlobalVariables.frametime = (float)host_frametime;
  sv.oldtime = sv.time;
  SV_CheckCmdTimes();
  SV_ReadPackets();
  if ((sv.paused == false) &&
     ((1 < svs.maxclients ||
      ((key_dest == key_game && ((cls.state == ca_dedicated || (cls.state == ca_active)))))))) {
    SV_Physics();
    sv.time = sv.time + host_frametime;
  }
  SV_QueryMovevarsChanged();
  SV_RequestMissingResourcesFromClients();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float droptime@[???] */
  fVar1 = (float)realtime - sv_timeout.value;
  if (0 < svs.maxclients) {
    iVar4 = 0;
    iVar2 = svs.maxclients;
    pcVar3 = svs.clients;
    do {
      while ((pcVar3->fakeclient != false ||
             ((((pcVar3->connected == false && (pcVar3->active == false)) &&
               (pcVar3->spawned == false)) || (fVar1 <= (pcVar3->netchan).last_received))))) {
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
        if (iVar2 <= iVar4) goto LAB_000ae062;
      }
      iVar4 = iVar4 + 1;
      SV_BroadcastPrintf("%s timed out\n",pcVar3->name);
      SV_DropClient(pcVar3,false,"Timed out");
      iVar2 = svs.maxclients;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 < svs.maxclients);
  }
LAB_000ae062:
  SV_SendClientMessages();
  iVar2 = svs.maxclients;
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  if ((5.0 <= realtime - SV_CheckMapDifferences::lastcheck) &&
     (SV_CheckMapDifferences::lastcheck = realtime, 0 < svs.maxclients)) {
    iVar4 = 0;
    pcVar3 = svs.clients;
    do {
      if (((pcVar3->active != false) && (pcVar3->crcValue != 0)) &&
         (((pcVar3->netchan).remote_address.type != NA_LOOPBACK &&
          (pcVar3->crcValue != sv.worldmapCRC)))) {
        (pcVar3->netchan).message.flags = (pcVar3->netchan).message.flags | 2;
      }
      iVar4 = iVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 < iVar2);
  }
  SV_GatherStatistics();
  Steam_RunFrame();
  return;
}


// SV_FullClientUpdate  @ 000a3150
void SV_FullClientUpdate(client_t *cl,sizebuf_t *sb)

{
  int iVar1;
  char local_184 [255];
  undefined1 local_85;
  MD5Context_t local_84;
  uchar local_2c [28];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] info@[???]
                       Unresolved local var: char[16] digest@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
  iVar1 = (int)cl - (int)svs.clients;
  Q_strncpy(local_184,cl->userinfo,0xff);
  local_85 = 0;
  Info_RemovePrefixedKeys(local_184,'_');
  MSG_WriteByte(sb,0xd);
  MSG_WriteByte(sb,(iVar1 >> 3) * -0x6d690de1);
  MSG_WriteLong(sb,cl->userid);
  MSG_WriteString(sb,local_184);
  MD5Init(&local_84);
  MD5Update(&local_84,(uchar *)cl->hashedcdkey,0x40);
  MD5Final(local_2c,&local_84);
  MSG_WriteBuf(sb,0x10,local_2c);
  return;
}


// SV_FullUpdate_Internal  @ 000b9830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_FullUpdate_Internal(void)

{
  float fVar1;
  double dVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: int entIndex@[???]
                       Unresolved local var: float ltime@[???] */
  iVar3 = IndexOfEdict((edict_t *)host_client->edict);
  dVar2 = sv.time;
  lVar4 = (longdouble)s_LastFullUpdate[iVar3];
  lVar5 = (longdouble)sv.time;
  if (lVar5 < lVar4) {
    lVar4 = (longdouble)0;
    s_LastFullUpdate[iVar3] = (float)lVar4;
  }
  fVar1 = (float)(lVar5 - lVar4);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (0.45 <= fVar1) goto LAB_000b98b4;
  if ((longdouble)0.45 < lVar5) {
    Con_DPrintf("%s is spamming fullupdate: (%f) (%f) (%f)\n",host_client->name,dVar2,(double)lVar4,
                (double)fVar1);
    return 0;
  }
LAB_000b98b4:
  s_LastFullUpdate[iVar3] = (float)dVar2;
  SV_ForceFullClientsUpdate();
  return 1;
}


// SV_FullUpdate_Internal  @ 000bbcc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_FullUpdate_Internal(void)

{
  int iVar1;
  
  if (host_client->active != false) {
    iVar1 = SV_FullUpdate_Internal();
    return iVar1;
  }
  Con_DPrintf("%s is trying to fullupdate when not active at (%f)\n",host_client->name,sv.time);
  return 0;
}


// SV_FullUpdate_f  @ 000bbc50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_FullUpdate_f(void)

{
  int iVar1;
  
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (host_client->active == false) {
    Con_DPrintf("%s is trying to fullupdate when not active at (%f)\n",host_client->name,sv.time);
  }
  else {
    iVar1 = SV_FullUpdate_Internal();
    if (0 < iVar1) {
      (*gEntityInterface.pfnClientCommand)(sv_player);
      return;
    }
  }
  return;
}


// SV_GatherStatistics  @ 0009c410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_GatherStatistics(void)

{
  float fVar1;
  float fVar2;
  client_s *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int players@[???]
                       Unresolved local var: float occup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: float v@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (svs.next_cleartime < realtime) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
    iVar5 = 0;
    if (0 < svs.maxclients) {
      iVar4 = 0;
      pcVar3 = svs.clients;
      do {
        if (((pcVar3->active != false) || (pcVar3->spawned != false)) ||
           (pcVar3->connected != false)) {
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (iVar4 != svs.maxclients);
    }
    svs.next_cleartime = realtime + 3600.0;
    Q_memset(&svs.stats,0,0x38);
    svs.stats.maxusers = iVar5;
    svs.stats.minusers = iVar5;
    return;
  }
  if (svs.next_sampletime <= realtime) {
    svs.next_sampletime = realtime + 60.0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
    svs.stats.num_samples = svs.stats.num_samples + 1;
    if (svs.maxclients < 1) {
      fVar1 = 0.0;
      iVar5 = 0;
    }
    else {
      iVar4 = 0;
      iVar5 = 0;
      pcVar3 = svs.clients;
      do {
        if (((pcVar3->active != false) || (pcVar3->spawned != false)) ||
           (pcVar3->connected != false)) {
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (iVar4 != svs.maxclients);
      fVar1 = (float)iVar5 * 100.0;
    }
    svs.stats.cumulative_occupancy = fVar1 / (float)svs.maxclients + svs.stats.cumulative_occupancy;
    if (0 < svs.stats.num_samples) {
      svs.stats.occupancy = svs.stats.cumulative_occupancy / (float)svs.stats.num_samples;
    }
    iVar4 = iVar5;
    if ((svs.stats.minusers <= iVar5) && (iVar4 = svs.stats.minusers, svs.stats.maxusers < iVar5)) {
      svs.stats.maxusers = iVar5;
    }
    svs.stats.minusers = iVar4;
    if (svs.maxclients + -1 <= iVar5) {
      svs.stats.at_capacity = svs.stats.at_capacity + 1;
    }
    if (iVar5 < 2) {
      svs.stats.at_empty = svs.stats.at_empty + 1;
    }
    if (0 < svs.stats.num_samples) {
      svs.stats.capacity_percent =
           ((float)svs.stats.at_capacity * 100.0) / (float)svs.stats.num_samples;
      svs.stats.empty_percent = ((float)svs.stats.at_empty * 100.0) / (float)svs.stats.num_samples;
    }
    fVar1 = 0.0;
    if (0 < svs.maxclients) {
      iVar5 = 0;
      iVar4 = 0;
      pcVar3 = svs.clients;
      fVar2 = fVar1;
      do {
        if ((pcVar3->active != false) && (pcVar3->fakeclient == false)) {
          fVar2 = fVar2 + pcVar3->latency;
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (iVar4 != svs.maxclients);
      fVar1 = 0.0;
      if (iVar5 != 0) {
        fVar1 = fVar2 / (float)iVar5;
      }
    }
    svs.stats.cumulative_latency = fVar1 + svs.stats.cumulative_latency;
    if (0 < svs.stats.num_samples) {
      svs.stats.average_latency = svs.stats.cumulative_latency / (float)svs.stats.num_samples;
    }
    if (0 < svs.stats.num_sessions) {
      svs.stats.average_session_len =
           svs.stats.cumulative_sessiontime / (float)svs.stats.num_sessions;
      return;
    }
  }
  return;
}


// SV_GetClientIDString  @ 000acad0
char * SV_GetClientIDString(client_t *client)

{
  char *pcVar1;
  
  SV_GetClientIDString::idstr[0] = '\0';
  if (client != (client_t *)0x0) {
    if (((client->netchan).remote_address.type == NA_LOOPBACK) &&
       ((client->network_userid).idtype == 2)) {
      snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
    }
    else {
                    /* Unresolved local var: USERID_t * id@[???] */
      pcVar1 = SV_GetIDString(&client->network_userid);
      snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar1);
    }
  }
  return SV_GetClientIDString::idstr;
}


// SV_GetFakeClientCount  @ 000a02e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_GetFakeClientCount(void)

{
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fakeclients@[???] */
  iVar1 = 0;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    pcVar2 = svs.clients;
    do {
                    /* Unresolved local var: client_t * client@[???] */
      if (pcVar2->fakeclient != false) {
        iVar1 = iVar1 + 1;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 != svs.maxclients);
  }
  return iVar1;
}


// SV_GetFileNameModuleC  @ 00095730
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * SV_GetFileNameModuleC(void)

{
  char local_124 [260];
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
                    /* Unresolved local var: char[260] gamedir@[???]
                       Unresolved local var: char[20] szModule@[???] */
  local_20 = 0x4d;
  local_1c = 0x6c;
  local_1b = 0x65;
  local_1a = 0x43;
  local_19 = 0x2e;
  local_1f = 0x6f;
  local_1e = 100;
  local_1d = 0x75;
  local_18 = 100;
  local_17 = 0x6c;
  local_16 = 0x6c;
  local_15 = 0;
  COM_FileBase(com_gamedir,local_124);
  snprintf(SV_GetFileNameModuleC::moduleFileName,0x103,"%s/%s",local_124,&local_20);
  SV_GetFileNameModuleC::moduleFileName[0x103] = '\0';
  return SV_GetFileNameModuleC::moduleFileName;
}


// SV_GetFileNameModuleS  @ 00095640
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * SV_GetFileNameModuleS(void)

{
  char local_124 [260];
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  
                    /* Unresolved local var: char[260] gamedir@[???]
                       Unresolved local var: char[20] szModule@[???] */
  local_20 = 0x4d;
  local_1c = 0x6c;
  local_1b = 0x65;
  local_1a = 0x53;
  local_19 = 0x5f;
  local_18 = 0x69;
  local_17 = 0x33;
  local_1d = 0x75;
  local_13 = 0x73;
  local_1f = 0x6f;
  local_1e = 100;
  local_14 = 0x2e;
  local_12 = 0x6f;
  local_16 = 0x38;
  local_15 = 0x36;
  local_11 = 0;
  COM_FileBase(com_gamedir,local_124);
  snprintf(SV_GetFileNameModuleS::moduleFileName,0x103,"%s/%s",local_124,&local_20);
  SV_GetFileNameModuleS::moduleFileName[0x103] = '\0';
  return SV_GetFileNameModuleS::moduleFileName;
}


// SV_GetFragmentSize  @ 0009bcf0
int SV_GetFragmentSize(void *state)

{
  char *str;
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * cl@[???] */
  iVar2 = 0x400;
  if ((((*(int *)state != 0) && (*(int *)((int)state + 4) != 0)) &&
      (*(int *)((int)state + 0xc) != 0)) && (*(int *)((int)state + 8) != 0)) {
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * val@[???] */
    iVar2 = 0x100;
    str = Info_ValueForKey((char *)((int)state + 0x4aa0),"cl_dlmax");
    iVar1 = Q_strlen(str);
    if (iVar1 != 0) {
      iVar1 = Q_atoi(str);
      if (0xff < iVar1) {
        iVar2 = iVar1;
      }
      if (0x400 < iVar2) {
        iVar2 = 0x400;
      }
    }
  }
  return iVar2;
}


// SV_GetIDString  @ 000aacd0
char * SV_GetIDString(USERID_t *id)

{
  int iVar1;
  TSteamGlobalUserID_conflict local_24;
  TSteamGlobalUserID_conflict local_18 [2];
  
  SV_GetIDString::idstr._0_4_ = SV_GetIDString::idstr._0_4_ & 0xffffff00;
  if (id != (USERID_t *)0x0) {
    iVar1 = id->idtype;
    if (iVar1 == 2) {
      if (sv_lan.value == 0.0) {
        if (*(int *)((int)&id->m_SteamID + 4) == 0 && (int)id->m_SteamID == 0) {
          builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_PENDING",0x11);
        }
        else {
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
          Steam_Steam3IDtoSteam2(local_18,id->m_SteamID);
          snprintf(SV_GetIDString::idstr,0x3f,"VALVE_%u:%u:%u",(uint)local_18[0].m_SteamInstanceID,
                   local_18[0].m_SteamLocalUserID.Split.High32bits,
                   local_18[0].m_SteamLocalUserID.Split.Low32bits);
          SV_GetIDString::idstr[0x3f] = '\0';
        }
      }
      else {
        builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_LAN",0xc);
        SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
      }
    }
    else {
      if (iVar1 == 3) {
        builtin_strncpy(SV_GetIDString::idstr,"HLTV",4);
        SV_GetIDString::idstr._4_4_ = SV_GetIDString::idstr._4_4_ & 0xffffff00;
        return SV_GetIDString::idstr;
      }
      if (iVar1 == 1) {
        if (sv_lan.value == 0.0) {
          if (*(int *)((int)&id->m_SteamID + 4) == 0 && (int)id->m_SteamID == 0) {
            builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_PENDING",0x11);
          }
          else {
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
            Steam_Steam3IDtoSteam2(&local_24,id->m_SteamID);
            snprintf(SV_GetIDString::idstr,0x3f,"STEAM_%u:%u:%u",(uint)local_24.m_SteamInstanceID,
                     local_24.m_SteamLocalUserID.Split.High32bits,
                     local_24.m_SteamLocalUserID.Split.Low32bits);
            SV_GetIDString::idstr[0x3f] = '\0';
          }
        }
        else {
          builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_LAN",0xc);
          SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
        }
      }
      else {
        builtin_strncpy(SV_GetIDString::idstr,"UNKNOWN",8);
      }
    }
  }
  return SV_GetIDString::idstr;
}


// SV_GetModInfo  @ 000a0320
qboolean SV_GetModInfo(char *pszInfo,char *pszDL,int *version,int *size,qboolean *svonly,
                      qboolean *cldll,char *pszHLVersion)

{
  if (gmodinfo.bIsMod == false) {
    Q_strcpy(pszInfo,"");
    Q_strcpy(pszDL,"");
    Q_strcpy(pszHLVersion,"");
    *version = 1;
    *size = 0;
    *svonly = true;
    *cldll = false;
  }
  else {
    Q_strcpy(pszInfo,gmodinfo.szInfo);
    Q_strcpy(pszDL,gmodinfo.szDL);
    Q_strcpy(pszHLVersion,gmodinfo.szHLVersion);
    *version = gmodinfo.version;
    *size = gmodinfo.size;
    *svonly = gmodinfo.svonly;
    *cldll = gmodinfo.cldll;
  }
  return gmodinfo.bIsMod;
}


// SV_GetNetInfo  @ 000a4ee0
void SV_GetNetInfo(client_t *client,int *ping,int *packet_loss)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_20;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = (int)client - (int)svs.clients >> 3;
  if (realtime < client->nextping) {
    uVar6 = (uint)SV_GetNetInfo::lastloss[iVar3 * -0x6d690de1];
    uVar5 = (uint)SV_GetNetInfo::lastping[iVar3 * 0x1296f21f];
    goto LAB_000a500e;
  }
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: int idx@[???] */
  client->nextping = realtime + 2.0;
  if (client->fakeclient == false) {
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
    if (SV_UPDATE_BACKUP < 0x20) {
      iVar7 = SV_UPDATE_BACKUP / 2;
      if (iVar7 < 1) goto LAB_000a4fea;
    }
    else {
      iVar7 = 0x10;
    }
    iVar4 = 0;
    fVar2 = 0.0;
    local_20 = 0;
    do {
      fVar1 = client->frames
              [((client->netchan).incoming_acknowledged + -1) - iVar4 & SV_UPDATE_MASK].ping_time;
      if (0.0 < fVar1) {
        local_20 = local_20 + 1;
        fVar2 = fVar1 + fVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar7);
    if ((local_20 == 0) || (fVar2 / (float)local_20 < 0.0)) goto LAB_000a4fea;
    uVar5 = (int)((fVar2 / (float)local_20) * 1000.0) & 0xffff;
  }
  else {
LAB_000a4fea:
    uVar5 = 0;
  }
  SV_GetNetInfo::lastping[iVar3 * 0x1296f21f] = (ushort)uVar5;
  uVar6 = (int)client->packet_loss & 0xff;
  SV_GetNetInfo::lastloss[iVar3 * -0x6d690de1] = (uchar)(int)client->packet_loss;
LAB_000a500e:
  *ping = uVar5;
  *packet_loss = uVar6;
  return;
}


// SV_GetPlayerHulls  @ 00077d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_GetPlayerHulls(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iResult@[???] */
  iVar1 = (*gEntityInterface.pfnGetHullBounds)(0,player_mins[0],player_maxs[0]);
  if (iVar1 != 0) {
    iVar1 = (*gEntityInterface.pfnGetHullBounds)(1,(float *)0x10864c,(float *)0x10860c);
    if (iVar1 != 0) {
      iVar1 = (*gEntityInterface.pfnGetHullBounds)(2,(float *)0x108658,(float *)0x108618);
      if (iVar1 != 0) {
        (*gEntityInterface.pfnGetHullBounds)(3,(float *)0x108664,(float *)0x108624);
      }
    }
  }
  return;
}


// SV_GetTrueMinMax  @ 000b9be0
void SV_GetTrueMinMax(int player,float **fmin,float **fmax)

{
  if ((((((host_client->lw != 0) && (host_client->lc != 0)) && (sv_unlag.value != 0.0)) &&
       ((1 < svs.maxclients && (host_client->active != false)))) &&
      ((-1 < player && ((player < svs.maxclients && (truepositions[player].active != 0)))))) &&
     (truepositions[player].needrelink != 0)) {
    *fmin = truepositions[player].oldabsmin;
    *fmax = truepositions[player].oldabsmax;
  }
  return;
}


// SV_GetTrueOrigin  @ 000b9b40
void SV_GetTrueOrigin(int player,vec_t *origin)

{
  if ((((((host_client->lw != 0) && (host_client->lc != 0)) && (sv_unlag.value != 0.0)) &&
       ((1 < svs.maxclients && (host_client->active != false)))) &&
      ((-1 < player && ((player < svs.maxclients && (truepositions[player].active != 0)))))) &&
     (truepositions[player].needrelink != 0)) {
    *origin = truepositions[player].oldorg[0];
    origin[1] = truepositions[player].oldorg[1];
    origin[2] = truepositions[player].oldorg[2];
  }
  return;
}


// SV_HandleRconPacket  @ 000a9860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_HandleRconPacket(void)

{
  char *pcVar1;
  int iVar2;
  netadr_t *in_stack_00000004;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * c@[???] */
  MSG_BeginReading();
  MSG_ReadLong();
  pcVar1 = MSG_ReadStringLine();
  Cmd_TokenizeString(pcVar1);
  pcVar1 = Cmd_Argv(0);
  iVar2 = Q_strcmp(pcVar1,"getchallenge");
  if (iVar2 == 0) {
    SVC_GetChallenge();
    return;
  }
  iVar2 = Q_stricmp(pcVar1,"challenge");
  if (iVar2 == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???] */
    iVar2 = Cmd_Argc();
    if (iVar2 == 2) {
      SVC_ServiceChallenge();
      return;
    }
  }
  else {
    iVar2 = Q_strcmp(pcVar1,"rcon");
    if (iVar2 == 0) {
      SV_Rcon(in_stack_00000004);
      return;
    }
  }
  return;
}


// SV_HasEventsInQueue  @ 000a4ea0
qboolean SV_HasEventsInQueue(client_t *client)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  qVar1 = false;
  if (client != (client_t *)0x0) {
    while ((client->events).ei[qVar1].index == 0) {
      qVar1 = qVar1 + true;
      if (qVar1 == 0x40) {
        return false;
      }
    }
    qVar1 = true;
  }
  return qVar1;
}


// SV_HashString  @ 0009cbc0
int SV_HashString(char *string,int iBounds)

{
  __int32_t **pp_Var1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
                    /* Unresolved local var: uint hash@[???] */
  uVar2 = 0;
  cVar3 = *string;
  if (cVar3 != '\0') {
    pp_Var1 = __ctype_tolower_loc();
    uVar2 = 0;
    do {
                    /* Unresolved local var: int __res@[???] */
      iVar4 = (int)cVar3;
      string = string + 1;
      cVar3 = *string;
      uVar2 = uVar2 * 2 + (*pp_Var1)[iVar4];
    } while (cVar3 != '\0');
    uVar2 = uVar2 % (uint)iBounds;
  }
  return uVar2;
}


// SV_HitgroupForStudioHull  @ 00094530
int SV_HitgroupForStudioHull(int index)

{
  return studio_hull_hitgroup[index];
}


// SV_HullForBeam  @ 000bec80
hull_t * SV_HullForBeam(vec_t *start,vec_t *end,vec_t *size)

{
  vec_t local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: vec3_t tmp@[???] */
  beam_planes[0].normal[0] = *end - *start;
  beam_planes[0].normal[1] = end[1] - start[1];
  beam_planes[0].normal[2] = end[2] - start[2];
  VectorNormalize(beam_planes[0].normal);
  beam_planes[1].normal[0] = beam_planes[0].normal[0];
  beam_planes[1].normal[1] = beam_planes[0].normal[1];
  beam_planes[1].normal[2] = beam_planes[0].normal[2];
  beam_planes[0].dist =
       end[2] * beam_planes[0].normal[2] +
       end[1] * beam_planes[0].normal[1] + *end * beam_planes[0].normal[0];
  beam_planes[1].dist =
       start[2] * beam_planes[0].normal[2] +
       beam_planes[0].normal[1] * start[1] + beam_planes[0].normal[0] * *start;
  if (ABS(beam_planes[0].normal[2]) < 0.9) {
    local_14 = 1.0;
    local_1c = 0.0;
  }
  else {
    local_1c = 1.0;
    local_14 = 0.0;
  }
  local_18 = 0.0;
  CrossProduct(beam_planes[0].normal,&local_1c,beam_planes[2].normal);
  VectorNormalize(beam_planes[2].normal);
  beam_planes[3].normal[0] = beam_planes[2].normal[0];
  beam_planes[3].normal[1] = beam_planes[2].normal[1];
  beam_planes[3].normal[2] = beam_planes[2].normal[2];
  beam_planes[2].dist =
       (start[2] + beam_planes[2].normal[2]) * beam_planes[2].normal[2] +
       (start[1] + beam_planes[2].normal[1]) * beam_planes[2].normal[1] +
       (*start + beam_planes[2].normal[0]) * beam_planes[2].normal[0];
  local_1c = *start - beam_planes[2].normal[0];
  local_18 = start[1] - beam_planes[2].normal[1];
  local_14 = start[2] - beam_planes[2].normal[2];
  beam_planes[3].dist =
       local_1c * beam_planes[2].normal[0] + local_18 * beam_planes[2].normal[1] +
       beam_planes[2].normal[2] * local_14;
  CrossProduct(beam_planes[2].normal,beam_planes[0].normal,beam_planes[4].normal);
  VectorNormalize(beam_planes[4].normal);
  beam_planes[5].normal[0] = beam_planes[4].normal[0];
  beam_planes[5].normal[1] = beam_planes[4].normal[1];
  beam_planes[5].normal[2] = beam_planes[4].normal[2];
  beam_planes[0].dist =
       ABS(beam_planes[0].normal[2] * size[2]) +
       ABS(beam_planes[0].normal[1] * size[1]) + ABS(beam_planes[0].normal[0] * *size) +
       beam_planes[0].dist;
  beam_planes[1].dist =
       beam_planes[1].dist -
       (ABS(beam_planes[1].normal[2] * size[2]) +
       ABS(beam_planes[1].normal[1] * size[1]) + ABS(beam_planes[1].normal[0] * *size));
  beam_planes[2].dist =
       ABS(beam_planes[2].normal[2] * size[2]) +
       ABS(beam_planes[2].normal[1] * size[1]) + ABS(beam_planes[2].normal[0] * *size) +
       beam_planes[2].dist;
  beam_planes[3].dist =
       beam_planes[3].dist -
       (ABS(beam_planes[3].normal[2] * size[2]) +
       ABS(beam_planes[3].normal[1] * size[1]) + ABS(beam_planes[3].normal[0] * *size));
  beam_planes[4].dist =
       ABS(size[2] * beam_planes[4].normal[2]) +
       ABS(size[1] * beam_planes[4].normal[1]) + ABS(*size * beam_planes[4].normal[0]) +
       (start[2] + beam_planes[4].normal[2]) * beam_planes[4].normal[2] +
       (start[1] + beam_planes[4].normal[1]) * beam_planes[4].normal[1] +
       (*start + beam_planes[4].normal[0]) * beam_planes[4].normal[0];
  beam_planes[5].dist =
       ((start[2] - beam_planes[4].normal[2]) * beam_planes[4].normal[2] +
       (start[1] - beam_planes[4].normal[1]) * beam_planes[4].normal[1] +
       (*start - beam_planes[4].normal[0]) * beam_planes[4].normal[0]) -
       (ABS(beam_planes[4].normal[2] * size[2]) +
       ABS(beam_planes[4].normal[1] * size[1]) + ABS(beam_planes[4].normal[0] * *size));
  return &beam_hull;
}


// SV_HullForBox  @ 000bec30
hull_t * SV_HullForBox(vec_t *mins,vec_t *maxs)

{
  box_planes[0].dist = *maxs;
  box_planes[1].dist = *mins;
  box_planes[2].dist = maxs[1];
  box_planes[3].dist = mins[1];
  box_planes[4].dist = maxs[2];
  box_planes[5].dist = mins[2];
  return &box_hull;
}


// SV_HullForBsp  @ 000befa0
hull_s * SV_HullForBsp(edict_t_conflict *ent,vec_t *mins,vec_t *maxs,vec_t *offset)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  hull_s *phVar5;
  
                    /* Unresolved local var: model_t * model@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: vec3_t size@[???] */
  pmVar4 = sv.models[(ent->v).modelindex];
  if (pmVar4 == (model_s *)0x0) {
    Sys_Error("Hit a %s with no model (%s)",pr_strings + (ent->v).classname,
              pr_strings + (ent->v).model);
  }
  else if (pmVar4->type == mod_brush) goto LAB_000befe3;
  Sys_Error("Hit a %s with no model (%s)",pr_strings + (ent->v).classname,
            pr_strings + (ent->v).model);
  Sys_Error("MOVETYPE_PUSH with a non bsp model");
LAB_000befe3:
  fVar1 = *maxs - *mins;
  if (fVar1 <= 8.0) {
    fVar1 = pmVar4->hulls[0].clip_mins[0];
    phVar5 = pmVar4->hulls;
    *offset = fVar1;
    fVar2 = pmVar4->hulls[0].clip_mins[1];
    offset[1] = fVar2;
    fVar3 = pmVar4->hulls[0].clip_mins[2];
    offset[2] = fVar3;
  }
  else {
    phVar5 = pmVar4->hulls + 2;
    if (fVar1 <= 36.0) {
      phVar5 = pmVar4->hulls + 1;
      if (maxs[2] - mins[2] <= 36.0) {
        phVar5 = pmVar4->hulls + 3;
      }
    }
    fVar1 = phVar5->clip_mins[0] - *mins;
    *offset = fVar1;
    fVar2 = phVar5->clip_mins[1] - mins[1];
    offset[1] = fVar2;
    fVar3 = phVar5->clip_mins[2] - mins[2];
    offset[2] = fVar3;
  }
  *offset = fVar1 + (ent->v).origin[0];
  offset[1] = fVar2 + (ent->v).origin[1];
  offset[2] = fVar3 + (ent->v).origin[2];
  return phVar5;
}


// SV_HullForEntity  @ 000bf140
hull_t * SV_HullForEntity(edict_t_conflict *ent,vec_t *mins,vec_t *maxs,vec_t *offset)

{
  int iVar1;
  hull_s *phVar2;
  
                    /* Unresolved local var: vec3_t hullmins@[???]
                       Unresolved local var: vec3_t hullmaxs@[???]
                       Unresolved local var: hull_t * hull@[???] */
  if ((ent->v).solid != 4) {
    box_planes[1].dist = (ent->v).mins[0] - *maxs;
    box_planes[3].dist = (ent->v).mins[1] - maxs[1];
    box_planes[5].dist = (ent->v).mins[2] - maxs[2];
    box_planes[2].dist = (ent->v).maxs[1] - mins[1];
    box_planes[4].dist = (ent->v).maxs[2] - mins[2];
    box_planes[0].dist = (ent->v).maxs[0] - *mins;
    *offset = (ent->v).origin[0];
    offset[1] = (ent->v).origin[1];
    offset[2] = (ent->v).origin[2];
    return &box_hull;
  }
  iVar1 = (ent->v).movetype;
  if ((iVar1 != 0xd) && (iVar1 != 7)) {
    Sys_Error("SOLID_BSP without MOVETYPE_PUSH");
  }
  phVar2 = SV_HullForBsp(ent,mins,maxs,offset);
  return phVar2;
}


// SV_HullForStudioModel  @ 000946f0
hull_t * SV_HullForStudioModel(edict_t *pEdict,vec_t *mins,vec_t *maxs,vec_t *offset,int *pNumHulls)

{
  float scale;
  bool bVar1;
  int iVar2;
  hull_t *phVar3;
  uint bSkipShield;
  vec_t *pPitch;
  uchar *pcontroller;
  uchar *pblending;
  vec_t local_4c;
  float local_48;
  float local_44;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  int local_28;
  uchar local_22 [5];
  undefined1 local_1d;
  
                    /* Unresolved local var: qboolean useComplexHull@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: int bSkipShield@[???] */
  local_4c = *maxs - *mins;
  local_48 = maxs[1] - mins[1];
  local_44 = maxs[2] - mins[2];
  iVar2 = VectorCompare(vec3_origin,&local_4c);
  if ((iVar2 != 0) && (((byte)gGlobalVariables.trace_flags & 1) == 0)) {
    if (((pEdict->v).flags & 8) == 0) {
      bVar1 = true;
      scale = 0.5;
      goto LAB_00094768;
    }
    if (sv_clienttrace.value != 0.0) {
      scale = sv_clienttrace.value * 0.5;
      bVar1 = true;
      local_44 = 1.0;
      local_48 = 1.0;
      local_4c = 1.0;
      goto LAB_00094768;
    }
  }
  bVar1 = false;
  scale = 0.5;
LAB_00094768:
  bSkipShield = 0;
  if ((((pEdict->v).gamestate == 1) && (bSkipShield = 1, g_bIsTerrorStrike != 1)) &&
     (g_bIsCStrike != 1)) {
    bSkipShield = (uint)(g_bIsCZero == 1);
  }
  if ((!bVar1) && ((sv.models[(pEdict->v).modelindex]->flags & 0x200) == 0)) {
    *pNumHulls = 1;
    phVar3 = SV_HullForEntity((edict_t_conflict *)pEdict,mins,maxs,offset);
    return phVar3;
  }
  VectorScale(&local_4c,scale,&local_4c);
  *offset = 0.0;
  offset[1] = 0.0;
  offset[2] = 0.0;
  if (((pEdict->v).flags & 8) == 0) {
    pblending = (pEdict->v).blending;
    pcontroller = (pEdict->v).controller;
    pPitch = (pEdict->v).angles;
  }
  else {
                    /* Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: int iBlend@[???]
                       Unresolved local var: uchar[2] blending@[???]
                       Unresolved local var: uchar[4] controller@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
    pstudiohdr = Mod_Extradata(sv.models[(pEdict->v).modelindex]);
    pPitch = &local_34;
    local_34 = (pEdict->v).angles[0];
    local_30 = (pEdict->v).angles[1];
    local_2c = (pEdict->v).angles[2];
    R_StudioPlayerBlend((mstudioseqdesc_t *)
                        (pstudiohdr->name + (pEdict->v).sequence * 0xb0 + pstudiohdr->seqindex + -8)
                        ,&local_28,pPitch);
    local_1d = 0;
    builtin_memcpy(local_22,"\x7f\x7f\x7f\x7f",4);
    pblending = local_22 + 4;
    pcontroller = local_22;
  }
  phVar3 = R_StudioHull(sv.models[(pEdict->v).modelindex],(pEdict->v).frame,(pEdict->v).sequence,
                        pPitch,(pEdict->v).origin,&local_4c,pcontroller,pblending,pNumHulls,pEdict,
                        bSkipShield);
  return phVar3;
}


// SV_HullPointContents  @ 000bf710
int SV_HullPointContents(hull_t *hull,int num,vec_t *p)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  float fVar3;
  
  do {
    if (num < 0) {
      return num;
    }
    while( true ) {
      if ((num < hull->firstclipnode) || (hull->lastclipnode < num)) {
        Sys_Error("SV_HullPointContents: bad node number");
      }
      pdVar1 = hull->clipnodes + num;
      pmVar2 = hull->planes + pdVar1->planenum;
      if (pmVar2->type < 3) {
        fVar3 = p[pmVar2->type] - pmVar2->dist;
      }
      else {
        fVar3 = (pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p) -
                pmVar2->dist;
      }
      if (0.0 <= fVar3) break;
      num = (int)pdVar1->children[1];
      if (num < 0) {
        return num;
      }
    }
    num = (int)pdVar1->children[0];
  } while( true );
}


// SV_IgnoreHLTV  @ 000b7d50
void SV_IgnoreHLTV(client_t *cl)

{
  return;
}


// SV_Impact  @ 000b1ca0
void SV_Impact(edict_t_conflict *e1,edict_t_conflict *e2,trace_t *ptrace)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  gGlobalVariables.time = (float)sv.time;
  if ((((e2->v).flags | (e1->v).flags) & 0x40000000U) != 0) {
    return;
  }
  uVar1 = (e1->v).groupinfo;
  if ((uVar1 != 0) && (uVar2 = (e2->v).groupinfo, uVar2 != 0)) {
    if (g_groupop == 0) {
      if ((uVar2 & uVar1) == 0) {
        return;
      }
    }
    else if ((g_groupop == 1) && ((uVar2 & uVar1) != 0)) {
      return;
    }
  }
  if ((e1->v).solid == 0) {
    iVar3 = (e2->v).solid;
  }
  else {
    SV_SetGlobalTrace(ptrace);
    (*gEntityInterface.pfnTouch)(e1,e2);
    iVar3 = (e2->v).solid;
  }
  if (iVar3 == 0) {
    return;
  }
  SV_SetGlobalTrace(ptrace);
                    /* WARNING: Could not recover jumptable at 0x000b1d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEntityInterface.pfnTouch)(e2,e1);
  return;
}


// SV_InactivateClients  @ 000a8e00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InactivateClients(void)

{
  char *dest;
  int iVar1;
  client_s *cl;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar2 = 0;
    iVar1 = svs.maxclients;
    cl = svs.clients;
    do {
      while (((cl->active != false || (cl->connected != false)) || (cl->spawned != false))) {
        if (cl->fakeclient != false) {
          SV_DropClient(cl,false,"Dropping fakeclient on level change");
          iVar1 = svs.maxclients;
          break;
        }
        iVar2 = iVar2 + 1;
        cl->m_bSentNewResponse = false;
        cl->active = false;
        cl->connected = true;
        cl->spawned = false;
        cl->fully_connected = false;
        cl->hasusrmsgs = false;
        SZ_Clear(&(cl->netchan).message);
        SZ_Clear(&cl->datagram);
        COM_ClearCustomizationList(&cl->customdata,false);
        dest = cl->physinfo;
        cl = cl + 1;
        Q_memset(dest,0,0x100);
        iVar1 = svs.maxclients;
        if (svs.maxclients <= iVar2) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      cl = cl + 1;
    } while (iVar2 < iVar1);
  }
  return;
}


// SV_Init  @ 000aa430
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Init(void)

{
  int iVar1;
  uchar *dest;
  client_frame_t *pcVar2;
  undefined4 *p;
  int iVar3;
  client_s *pcVar4;
  char (*__s) [5];
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???] */
  Cmd_AddCommand("banid",SV_BanId_f);
  Cmd_AddCommand("removeid",SV_RemoveId_f);
  Cmd_AddCommand("listid",SV_ListId_f);
  Cmd_AddCommand("writeid",SV_WriteId_f);
  Cmd_AddCommand("resetrcon",SV_ResetRcon_f);
  Cmd_AddCommand("logaddress",SV_SetLogAddress_f);
  Cmd_AddCommand("logaddress_add",SV_AddLogAddress_f);
  Cmd_AddCommand("logaddress_del",SV_DelLogAddress_f);
  Cmd_AddCommand("log",SV_ServerLog_f);
  Cmd_AddCommand("serverinfo",SV_Serverinfo_f);
  Cmd_AddCommand("localinfo",SV_Localinfo_f);
  Cmd_AddCommand("showinfo",SV_ShowServerinfo_f);
  Cmd_AddCommand("user",SV_User_f);
  Cmd_AddCommand("users",SV_Users_f);
  Cmd_AddCommand("dlfile",SV_BeginFileDownload_f);
  Cmd_AddCommand("addip",SV_AddIP_f);
  Cmd_AddCommand("removeip",SV_RemoveIP_f);
  Cmd_AddCommand("listip",SV_ListIP_f);
  Cmd_AddCommand("writeip",SV_WriteIP_f);
  Cmd_AddCommand("dropclient",SV_Drop_f);
  Cmd_AddCommand("spawn",SV_Spawn_f);
  Cmd_AddCommand("new",SV_New_f);
  Cmd_AddCommand("sendres",SV_SendRes_f);
  Cmd_AddCommand("sendents",SV_SendEnts_f);
  Cmd_AddCommand("fullupdate",SV_FullUpdate_f);
  Cvar_RegisterVariable(&sv_failuretime);
  Cvar_RegisterVariable(&sv_voiceenable);
  Cvar_RegisterVariable(&rcon_password);
  Cvar_RegisterVariable(&sv_enableoldqueries);
  Cvar_RegisterVariable(&mp_consistency);
  Cvar_RegisterVariable(&sv_instancedbaseline);
  Cvar_RegisterVariable(&sv_contact);
  Cvar_RegisterVariable(&sv_unlag);
  Cvar_RegisterVariable(&sv_maxunlag);
  Cvar_RegisterVariable(&sv_unlagpush);
  Cvar_RegisterVariable(&sv_unlagsamples);
  Cvar_RegisterVariable(&sv_filterban);
  Cvar_RegisterVariable(&sv_maxupdaterate);
  Cvar_RegisterVariable(&sv_minupdaterate);
  Cvar_RegisterVariable(&sv_logrelay);
  Cvar_RegisterVariable(&sv_lan);
  iVar1 = PF_IsDedicatedServer();
  if (iVar1 == 0) {
    Cvar_DirectSet(&sv_lan,"1");
  }
  else {
    Cvar_DirectSet(&sv_lan,"0");
  }
  Cvar_RegisterVariable(&sv_lan_rate);
  Cvar_RegisterVariable(&sv_proxies);
  Cvar_RegisterVariable(&sv_outofdatetime);
  Cvar_RegisterVariable(&sv_visiblemaxplayers);
  Cvar_RegisterVariable(&sv_password);
  Cvar_RegisterVariable(&sv_aim);
  Cvar_RegisterVariable(&violence_hblood);
  Cvar_RegisterVariable(&violence_ablood);
  Cvar_RegisterVariable(&violence_hgibs);
  Cvar_RegisterVariable(&violence_agibs);
  Cvar_RegisterVariable(&sv_newunit);
  Cvar_RegisterVariable(&sv_gravity);
  Cvar_RegisterVariable(&sv_friction);
  Cvar_RegisterVariable(&sv_edgefriction);
  Cvar_RegisterVariable(&sv_stopspeed);
  Cvar_RegisterVariable(&sv_maxspeed);
  Cvar_RegisterVariable(&sv_footsteps);
  Cvar_RegisterVariable(&sv_accelerate);
  Cvar_RegisterVariable(&sv_stepsize);
  Cvar_RegisterVariable(&sv_bounce);
  Cvar_RegisterVariable(&sv_airaccelerate);
  Cvar_RegisterVariable(&sv_wateraccelerate);
  Cvar_RegisterVariable(&sv_waterfriction);
  Cvar_RegisterVariable(&sv_skycolor_r);
  Cvar_RegisterVariable(&sv_skycolor_g);
  Cvar_RegisterVariable(&sv_skycolor_b);
  Cvar_RegisterVariable(&sv_skyvec_x);
  Cvar_RegisterVariable(&sv_skyvec_y);
  Cvar_RegisterVariable(&sv_skyvec_z);
  Cvar_RegisterVariable(&sv_timeout);
  Cvar_RegisterVariable(&sv_clienttrace);
  Cvar_RegisterVariable(&sv_zmax);
  Cvar_RegisterVariable(&sv_wateramp);
  Cvar_RegisterVariable(&sv_skyname);
  Cvar_RegisterVariable(&sv_maxvelocity);
  Cvar_RegisterVariable(&sv_cheats);
  Cvar_HookVariable(sv_cheats.name,&sv_cheats_hook);
  iVar1 = COM_CheckParm("-dev");
  if (iVar1 != 0) {
    Cvar_SetValue("sv_cheats",1.0);
  }
  Cvar_RegisterVariable(&sv_spectatormaxspeed);
  Cvar_RegisterVariable(&sv_allow_download);
  Cvar_RegisterVariable(&sv_allow_upload);
  Cvar_RegisterVariable(&sv_max_upload);
  Cvar_RegisterVariable(&sv_send_logos);
  Cvar_RegisterVariable(&sv_send_resources);
  Cvar_RegisterVariable(&sv_logbans);
  Cvar_RegisterVariable(&hpk_maxsize);
  Cvar_RegisterVariable(&mapcyclefile);
  Cvar_HookVariable(mapcyclefile.name,&mapcyclefile_hook);
  Cvar_RegisterVariable(&motdfile);
  Cvar_RegisterVariable(&servercfgfile);
  Cvar_RegisterVariable(&mapchangecfgfile);
  Cvar_RegisterVariable(&lservercfgfile);
  Cvar_RegisterVariable(&logsdir);
  Cvar_RegisterVariable(&bannedcfgfile);
  Cvar_RegisterVariable(&sv_rcon_minfailures);
  Cvar_RegisterVariable(&sv_rcon_maxfailures);
  Cvar_RegisterVariable(&sv_rcon_minfailuretime);
  Cvar_RegisterVariable(&sv_rcon_banpenalty);
  Cvar_RegisterVariable(&sv_minrate);
  Cvar_RegisterVariable(&sv_maxrate);
  Cvar_RegisterVariable(&max_queries_sec);
  Cvar_RegisterVariable(&max_queries_sec_global);
  Cvar_RegisterVariable(&max_queries_window);
  Cvar_RegisterVariable(&sv_logblocks);
  Cvar_RegisterVariable(&sv_downloadurl);
  Cvar_RegisterVariable(&sv_version);
  Cvar_RegisterVariable(&sv_allow_dlfile);
  iVar1 = 0;
  __s = localmodels;
  do {
    iVar3 = iVar1 + 1;
    snprintf(*__s,5,"*%i",iVar1);
    iVar1 = iVar3;
    __s = __s + 1;
  } while (iVar3 != 0x200);
  svs.isSecure = false;
  if (0 < svs.maxclientslimit) {
    local_20 = 0;
    local_24 = 0;
    do {
      dest = ((svs.clients)->netchan).remote_address.ip + local_20 + -0x24;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
      p = *(undefined4 **)(dest + 0x3480);
      if (p != (undefined4 *)0x0) {
        if (0 < SV_UPDATE_BACKUP) {
          iVar1 = 0;
          do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
            if (p != (undefined4 *)0x0) {
              if ((void *)p[0x603] != (void *)0x0) {
                Mem_Free((void *)p[0x603]);
              }
              p[0x603] = 0;
              p[0x5fa] = 0;
            }
            *p = 0;
            iVar1 = iVar1 + 1;
            p[1] = 0;
            p[2] = 0xbf800000;
            p = p + 0x604;
          } while (iVar1 < SV_UPDATE_BACKUP);
          p = *(undefined4 **)(dest + 0x3480);
        }
        Mem_Free(p);
        *(undefined4 *)(dest + 0x3480) = 0;
      }
      Q_memset(dest,0,0x4ef8);
      local_24 = local_24 + 1;
      local_20 = local_20 + 0x4ef8;
      *(int *)(dest + 0x4c98) = (int)dest + 0x4c14;
      *(int *)(dest + 0x4c94) = (int)dest + 0x4c14;
      *(int *)(dest + 0x4d20) = (int)dest + 0x4c9c;
      *(int *)(dest + 0x4d1c) = (int)dest + 0x4c9c;
    } while (local_24 < svs.maxclientslimit);
  }
  PM_Init(&g_svmove);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclientslimit) {
    iVar1 = 0;
    pcVar4 = svs.clients;
    do {
      if (pcVar4->frames != (client_frame_t *)0x0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar1 = iVar1 + 1;
      pcVar2 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1810);
      pcVar4->frames = pcVar2;
      pcVar4 = pcVar4 + 1;
    } while (iVar1 < svs.maxclientslimit);
  }
  SV_InitDeltas();
  return;
}


// SV_InitBoxHull  @ 000bea90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitBoxHull(void)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  box_hull.clipnodes = box_clipnodes;
  box_hull.planes = box_planes;
  box_hull.firstclipnode = 0;
  box_hull.lastclipnode = 5;
  uVar1 = 0;
  do {
    *(undefined4 *)((int)beam_hull.clip_mins + (uVar1 - 0x10)) =
         *(undefined4 *)((int)box_hull.clip_mins + (uVar1 - 0x10));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x28);
  beam_hull.planes = beam_planes;
  box_clipnodes[0].children[1] = 1;
  box_clipnodes[1].planenum = 1;
  box_clipnodes[1].children[1] = -1;
  box_clipnodes[1].children[0] = 2;
  box_clipnodes[2].planenum = 2;
  box_clipnodes[2].children[0] = -1;
  box_clipnodes[3].children[1] = -1;
  box_clipnodes[3].children[0] = 4;
  box_clipnodes[4].planenum = 4;
  box_clipnodes[0].planenum = 0;
  box_clipnodes[0].children[0] = -1;
  box_clipnodes[4].children[0] = -1;
  box_clipnodes[2].children[1] = 3;
  box_clipnodes[3].planenum = 3;
  box_clipnodes[4].children[1] = 5;
  box_planes[0].type = '\0';
  box_planes[0].normal[0] = 1.0;
  beam_planes[0].type = '\x05';
  box_planes[1].type = '\0';
  box_planes[1].normal[0] = 1.0;
  beam_planes[1].type = '\x05';
  box_planes[2].type = '\x01';
  box_planes[2].normal[1] = 1.0;
  beam_planes[2].type = '\x05';
  box_planes[3].type = '\x01';
  box_planes[3].normal[1] = 1.0;
  beam_planes[3].type = '\x05';
  box_planes[4].type = '\x02';
  box_planes[4].normal[2] = 1.0;
  beam_planes[4].type = '\x05';
  box_clipnodes[5].planenum = 5;
  box_clipnodes[5].children[1] = -1;
  box_clipnodes[5].children[0] = -2;
  box_planes[5].type = '\x02';
  box_planes[5].normal[2] = 1.0;
  beam_planes[5].type = '\x05';
  return;
}


// SV_InitDeltas  @ 000a9d80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitDeltas(void)

{
  qboolean qVar1;
  delta_info_t *pdVar2;
  char *pcVar3;
  int iVar4;
  delta_t *local_10 [2];
  
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  Con_DPrintf("Initializing deltas\n");
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("clientdata_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("clientdata_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("entity_state_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("entity_state_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("entity_state_player_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("entity_state_player_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("custom_entity_state_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("custom_entity_state_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("usercmd_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("usercmd_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("weapon_data_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("weapon_data_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("event_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
    pdVar2 = g_sv_delta;
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("event_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
  for (; pdVar2 != (delta_info_t *)0x0; pdVar2 = pdVar2->next) {
                    /* Unresolved local var: delta_info_t * p@[???] */
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("entity_state_player_t",pcVar3);
    if (iVar4 == 0) {
      g_pplayerdelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pplayerdelta == (delta_t *)0x0) goto LAB_000aa0ad;
      goto joined_r0x000aa0c8;
    }
  }
  pcVar3 = "entity_state_player_t";
  Sys_Error("Couldn\'t find delta for %s\n","entity_state_player_t");
  g_pplayerdelta = (delta_t *)0x0;
LAB_000aa0ad:
  Sys_Error("No entity_state_player_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x000aa0c8:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("entity_state_t",pcVar3);
    if (iVar4 == 0) {
      g_pentitydelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pentitydelta == (delta_t *)0x0) goto LAB_000aa11c;
      goto joined_r0x000aa138;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "entity_state_t";
  Sys_Error("Couldn\'t find delta for %s\n","entity_state_t");
  g_pentitydelta = (delta_t *)0x0;
LAB_000aa11c:
  Sys_Error("No entity_state_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x000aa138:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("custom_entity_state_t",pcVar3);
    if (iVar4 == 0) {
      g_pcustomentitydelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pcustomentitydelta == (delta_t *)0x0) goto LAB_000aa18d;
      goto joined_r0x000aa1a8;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "custom_entity_state_t";
  Sys_Error("Couldn\'t find delta for %s\n","custom_entity_state_t");
  g_pcustomentitydelta = (delta_t *)0x0;
LAB_000aa18d:
  Sys_Error("No custom_entity_state_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x000aa1a8:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("clientdata_t",pcVar3);
    if (iVar4 == 0) {
      g_pclientdelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pclientdelta == (delta_t *)0x0) goto LAB_000aa1fd;
      goto joined_r0x000aa218;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "clientdata_t";
  Sys_Error("Couldn\'t find delta for %s\n","clientdata_t");
  g_pclientdelta = (delta_t *)0x0;
LAB_000aa1fd:
  Sys_Error("No clientdata_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x000aa218:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("weapon_data_t",pcVar3);
    if (iVar4 == 0) {
      g_pweapondelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pweapondelta == (delta_t *)0x0) goto LAB_000aa26c;
      goto joined_r0x000aa288;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "weapon_data_t";
  Sys_Error("Couldn\'t find delta for %s\n","weapon_data_t");
  g_pweapondelta = (delta_t *)0x0;
LAB_000aa26c:
  Sys_Error("No weapon_data_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x000aa288:
  do {
    if (pdVar2 == (delta_info_t *)0x0) {
      pcVar3 = "event_t";
      Sys_Error("Couldn\'t find delta for %s\n","event_t");
      g_peventdelta = (delta_t *)0x0;
LAB_000aa2dc:
      Sys_Error("No event_t encoder on server!\n",pcVar3);
      return;
    }
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("event_t",pcVar3);
    if (iVar4 == 0) {
      g_peventdelta = pdVar2->delta;
      if (g_peventdelta != (delta_t *)0x0) {
        return;
      }
      goto LAB_000aa2dc;
    }
    pdVar2 = pdVar2->next;
  } while( true );
}


// SV_InitEncoders  @ 000aa3f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitEncoders(void)

{
  char *str;
  delta_t *pdVar1;
  delta_info_s *pdVar2;
  int iVar3;
  encoder_t p_Var4;
  
  for (pdVar2 = g_sv_delta; pdVar2 != (delta_info_t *)0x0; pdVar2 = pdVar2->next) {
    pdVar1 = pdVar2->delta;
    str = pdVar1->conditionalencodename;
    iVar3 = Q_strlen(str);
    if (0 < iVar3) {
      p_Var4 = DELTA_LookupEncoder(str);
      pdVar1->conditionalencode = p_Var4;
    }
  }
  return;
}


// SV_InitStudioHull  @ 00092560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitStudioHull(void)

{
  hull_t *phVar1;
  mplane_t *pmVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  if (studio_hull[0].planes != (mplane_t *)0x0) {
    return;
  }
  studio_clipnodes[0].planenum = 0;
  studio_clipnodes[1].planenum = 1;
  studio_clipnodes[1].children[1] = -1;
  studio_clipnodes[1].children[0] = 2;
  studio_clipnodes[2].planenum = 2;
  studio_clipnodes[2].children[0] = -1;
  studio_clipnodes[2].children[1] = 3;
  studio_clipnodes[3].children[0] = 4;
  studio_clipnodes[4].planenum = 4;
  studio_clipnodes[4].children[0] = -1;
  studio_clipnodes[0].children[0] = -1;
  studio_clipnodes[4].children[1] = 5;
  studio_clipnodes[0].children[1] = 1;
  studio_clipnodes[3].planenum = 3;
  studio_clipnodes[5].planenum = 5;
  studio_clipnodes[5].children[1] = -1;
  phVar1 = studio_hull;
  studio_clipnodes[5].children[0] = -2;
  pmVar2 = studio_planes;
  studio_clipnodes[3].children[1] = -1;
  do {
    phVar1->planes = pmVar2;
    pmVar2 = pmVar2 + 6;
    phVar1->clipnodes = studio_clipnodes;
    phVar1->firstclipnode = 0;
    phVar1->lastclipnode = 5;
    phVar1 = phVar1 + 1;
  } while (phVar1 != (hull_t *)studio_clipnodes);
  return;
}


// SV_InvokeCallback  @ 000a44f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InvokeCallback(void)

{
  SV_WriteDeltaHeader(g_svdeltacallback.num,g_svdeltacallback.remove,g_svdeltacallback.custom,
                      g_svdeltacallback.numbase,g_svdeltacallback.newbl,g_svdeltacallback.newblindex
                      ,g_svdeltacallback.full,g_svdeltacallback.offset);
  return;
}


// SV_IsPlayerIndex  @ 0009c7d0
qboolean SV_IsPlayerIndex(int index)

{
  qboolean qVar1;
  
  qVar1 = false;
  if (0 < index) {
    qVar1 = (qboolean)(index <= svs.maxclients);
  }
  return qVar1;
}


// SV_IsSimulating  @ 000a9c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SV_IsSimulating(void)

{
  qboolean qVar1;
  
  qVar1 = false;
  if (((sv.paused == false) && (qVar1 = true, svs.maxclients < 2)) &&
     (qVar1 = false, key_dest == key_game)) {
    return (uint)(cls.state == ca_dedicated || cls.state == ca_active);
  }
  return qVar1;
}


// SV_KickPlayer  @ 000ab050
void SV_KickPlayer(int nPlayerSlot,int nReason)

{
  uchar *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  client_s *pcVar9;
  int iVar10;
  int iVar11;
  undefined4 local_42c;
  undefined4 uStack_428;
  char acStack_424 [4];
  char acStack_420 [1012];
  USERID_t local_2c;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: USERID_t id@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[1024] rgchT@[???] */
  pcVar9 = svs.clients;
  if ((-1 < nPlayerSlot) && (nPlayerSlot < svs.maxclients)) {
    if ((svs.clients[nPlayerSlot].connected != false) && (svs.isSecure != false)) {
      local_2c.idtype = svs.clients[nPlayerSlot].network_userid.idtype;
      local_2c.m_SteamID._0_4_ = (undefined4)svs.clients[nPlayerSlot].network_userid.m_SteamID;
      local_2c.m_SteamID._4_4_ =
           *(undefined4 *)((int)&svs.clients[nPlayerSlot].network_userid.m_SteamID + 4);
      local_2c.clientip = svs.clients[nPlayerSlot].network_userid.clientip;
      pcVar3 = SV_GetIDString(&local_2c);
      Log_Printf("Secure: \"%s<%i><%s><>\" was detected cheating and dropped from the server.\n",
                 pcVar9[nPlayerSlot].name,pcVar9[nPlayerSlot].userid,pcVar3,nReason);
      local_42c._0_1_ = 8;
      local_42c._1_1_ = 10;
      local_42c._2_2_ = 0x2a2a;
      uVar5 = 0;
      do {
        uVar4 = uVar5;
        uVar2 = *(undefined4 *)
                 (
                 "\n********************************************\nYou have been automatically disconnected\nfrom this secure server because an illegal\ncheat was detected on your computer.\nRepeat violators may be permanently banned\nfrom all secure servers.\n\nFor help cleaning your system of cheats, visit:\nhttp://www.counter-strike.net/cheat.html\n********************************************\n\n"
                 + uVar4 + 7);
        *(undefined4 *)((int)&uStack_428 + uVar4) =
             *(undefined4 *)
              (
              "\n********************************************\nYou have been automatically disconnected\nfrom this secure server because an illegal\ncheat was detected on your computer.\nRepeat violators may be permanently banned\nfrom all secure servers.\n\nFor help cleaning your system of cheats, visit:\nhttp://www.counter-strike.net/cheat.html\n********************************************\n\n"
              + uVar4 + 3);
        *(undefined4 *)(acStack_420 + (uVar4 - 4)) = uVar2;
        uVar5 = uVar4 + 8;
      } while (uVar4 + 8 < 0x170);
      acStack_420[uVar4] =
           "\n********************************************\nYou have been automatically disconnected\nfrom this secure server because an illegal\ncheat was detected on your computer.\nRepeat violators may be permanently banned\nfrom all secure servers.\n\nFor help cleaning your system of cheats, visit:\nhttp://www.counter-strike.net/cheat.html\n********************************************\n\n"
           [uVar4 + 0xb];
      puVar8 = &local_42c;
      do {
        puVar7 = puVar8;
        uVar4 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar5 = uVar4 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar5 == 0);
      if ((uVar4 & 0x8080) == 0) {
        puVar8 = (uint *)((int)puVar7 + 6);
        uVar5 = uVar5 >> 0x10;
      }
      Netchan_Transmit(&svs.clients[nPlayerSlot].netchan,
                       (int)((int)puVar8 +
                            (-(int)&local_42c - (uint)CARRY1((byte)uVar5,(byte)uVar5)) + -2),
                       (byte *)&local_42c);
      snprintf((char *)&local_42c,0x400,
               "%s was automatically disconnected\nfrom this secure server.\n",
               svs.clients[nPlayerSlot].name);
      pcVar9 = svs.clients;
      if (0 < svs.maxclients) {
        iVar10 = 0;
        iVar6 = svs.maxclients;
        iVar11 = 0;
        do {
          while (((puVar1 = (pcVar9->netchan).remote_address.ip + iVar11 + -0x24,
                  *(int *)puVar1 != 0 || (*(int *)(puVar1 + 4) != 0)) &&
                 (*(int *)(puVar1 + 0x2438) == 0))) {
            iVar10 = iVar10 + 1;
            MSG_WriteByte((sizebuf_t *)(puVar1 + 0x74),0x1a);
            MSG_WriteString((sizebuf_t *)(((svs.clients)->netchan).message_buf + iVar11 + -0x14),
                            (char *)&local_42c);
            iVar6 = svs.maxclients;
            pcVar9 = svs.clients;
            iVar11 = iVar11 + 0x4ef8;
            if (svs.maxclients <= iVar10) goto LAB_000ab28b;
          }
          iVar10 = iVar10 + 1;
          iVar11 = iVar11 + 0x4ef8;
        } while (iVar10 < iVar6);
      }
LAB_000ab28b:
      SV_DropClient(pcVar9 + nPlayerSlot,false,"Automatically dropped by cheat detector");
    }
  }
  return;
}


// SV_LinkContents  @ 000bfc90
int SV_LinkContents(areanode_t *node,vec_t *pos)

{
  link_s *plVar1;
  link_s *plVar2;
  link_s *plVar3;
  hull_s *hull;
  int iVar4;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: link_t * l@[???]
                       Unresolved local var: link_t * next@[???]
                       Unresolved local var: edict_t.conflict * touch@[???]
                       Unresolved local var: int contents@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t localPosition@[???]
                       Unresolved local var: model_t * pModel@[???] */
  plVar1 = (node->solid_edicts).next;
joined_r0x000bfca7:
  do {
    plVar3 = plVar1;
    if (plVar3 == &node->solid_edicts) {
      if (node->axis != -1) {
        if (node->dist < pos[node->axis]) {
          iVar4 = SV_LinkContents(node->children[0],pos);
          return iVar4;
        }
        if (pos[node->axis] < node->dist) {
          iVar4 = SV_LinkContents(node->children[1],pos);
          return iVar4;
        }
      }
      return -1;
    }
    plVar1 = plVar3->next;
  } while (plVar3[0x30].next != (link_s *)0x0);
  plVar2 = plVar3[0x57].prev;
  if (plVar2 != (link_s *)0x0) {
    if (g_groupop == 0) {
      if ((g_groupmask & (uint)plVar2) == 0) goto joined_r0x000bfca7;
    }
    else if ((g_groupop == 1) && ((g_groupmask & (uint)plVar2) != 0)) goto joined_r0x000bfca7;
  }
  if (((((sv.models[(int)plVar3[0x25].next] != (model_s *)0x0) &&
        (sv.models[(int)plVar3[0x25].next]->type == mod_brush)) &&
       (*pos <= (float)plVar3[0x29].prev)) &&
      ((pos[1] <= (float)plVar3[0x29].next && (pos[2] <= (float)plVar3[0x2a].prev)))) &&
     (((float)plVar3[0x27].next <= *pos &&
      (((float)plVar3[0x28].prev <= pos[1] && ((float)plVar3[0x28].next <= pos[2])))))) {
    if ((link_s **)0xc8 < &plVar3[0x31].prev[0xc].next) {
      Con_DPrintf("Invalid contents on trigger field: %s\n",pr_strings + (int)plVar3[0xf].prev);
    }
    hull = SV_HullForBsp((edict_t_conflict *)(plVar3 + -1),vec3_origin,vec3_origin,&local_34);
    local_28 = *pos - local_34;
    local_24 = pos[1] - local_30;
    local_20 = pos[2] - local_2c;
    iVar4 = SV_HullPointContents(hull,hull->firstclipnode,&local_28);
    if (iVar4 != -1) {
      return (int)plVar3[0x31].prev;
    }
  }
  goto joined_r0x000bfca7;
}


// SV_LinkEdict  @ 000bfa10
void SV_LinkEdict(edict_t_conflict *ent,qboolean touch_triggers)

{
  link_t *plVar1;
  link_s *plVar2;
  edict_t_conflict *peVar3;
  areanode_t *paVar4;
  int iVar5;
  int iVar6;
  int local_1c [6];
  
                    /* Unresolved local var: areanode_t * node@[???]
                       Unresolved local var: int topnode@[???] */
  plVar2 = (ent->area).prev;
  if (plVar2 != (link_s *)0x0) {
    ((ent->area).next)->prev = plVar2;
    ((ent->area).prev)->next = (ent->area).next;
    (ent->area).next = (link_s *)0x0;
    (ent->area).prev = (link_s *)0x0;
  }
  if ((sv.edicts != ent) && (ent->free == 0)) {
    (*gEntityInterface.pfnSetAbsBox)(ent);
    if (((ent->v).movetype == 0xc) && (peVar3 = (ent->v).aiment, peVar3 != (edict_t_conflict *)0x0))
    {
      ent->headnode = peVar3->headnode;
      ent->num_leafs = peVar3->num_leafs;
      Q_memcpy(ent->leafnums,peVar3->leafnums,0x60);
    }
    else {
      local_1c[0] = -1;
      iVar5 = (ent->v).modelindex;
      ent->num_leafs = 0;
      ent->headnode = -1;
      if ((iVar5 != 0) &&
         (SV_FindTouchedLeafs(ent,(sv.worldmodel)->nodes,local_1c), 0x30 < ent->num_leafs)) {
        ent->num_leafs = 0;
        ent->headnode = local_1c[0];
        Q_memset(ent->leafnums,0xff,0x60);
      }
    }
    iVar5 = (ent->v).solid;
    if (iVar5 == 0) {
      if (-2 < (ent->v).skin) {
        return;
      }
    }
    else {
                    /* Unresolved local var: model_t * model@[???] */
      if ((iVar5 == 4) && (sv.models[(ent->v).modelindex] == (model_s *)0x0)) {
        iVar5 = Q_strlen(pr_strings + (ent->v).model);
        if (iVar5 == 0) {
          Con_DPrintf("Inserted %s with no model\n",pr_strings + (ent->v).classname);
          return;
        }
        iVar5 = (ent->v).solid;
      }
    }
    for (paVar4 = sv_areanodes; iVar6 = paVar4->axis, iVar6 != -1; paVar4 = paVar4->children[1]) {
      while (paVar4->dist < (ent->v).absmin[iVar6]) {
        paVar4 = paVar4->children[0];
        iVar6 = paVar4->axis;
        if (iVar6 == -1) goto LAB_000bfad5;
      }
      if (paVar4->dist <= (ent->v).absmax[iVar6]) break;
    }
LAB_000bfad5:
    plVar1 = &ent->area;
    if (iVar5 == 1) {
      (ent->area).next = &paVar4->trigger_edicts;
      plVar2 = (paVar4->trigger_edicts).prev;
      (ent->area).prev = plVar2;
      plVar2->next = plVar1;
      ((ent->area).next)->prev = plVar1;
    }
    else {
      (ent->area).next = &paVar4->solid_edicts;
      plVar2 = (paVar4->solid_edicts).prev;
      (ent->area).prev = plVar2;
      plVar2->next = plVar1;
      ((ent->area).next)->prev = plVar1;
    }
    if ((touch_triggers != false) && (SV_LinkEdict::iTouchLinkSemaphore == 0)) {
      SV_LinkEdict::iTouchLinkSemaphore = 1;
      SV_TouchLinks(ent,sv_areanodes);
      SV_LinkEdict::iTouchLinkSemaphore = 0;
    }
  }
  return;
}


// SV_ListIP_f  @ 0009b990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ListIP_f(void)

{
  float *pfVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[4] b@[???] */
  if (numipfilters < 1) {
    Con_Printf("IP filter list: empty\n");
    return;
  }
  Con_Printf("IP filter list:\n");
  if (0 < numipfilters) {
    puVar3 = &ipfilters[0].compare;
    iVar4 = 0;
    do {
      while( true ) {
        pfVar1 = (float *)(puVar3 + 2);
        uVar2 = *puVar3;
        if ((double)*pfVar1 != 0.0) break;
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 4;
        Con_Printf("%3i.%3i.%3i.%3i : permanent\n",uVar2 & 0xff,uVar2 >> 8 & 0xff,
                   uVar2 >> 0x10 & 0xff,uVar2 >> 0x18);
        if (numipfilters <= iVar4) {
          return;
        }
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 4;
      Con_Printf("%3i.%3i.%3i.%3i : %.3f min\n",uVar2 & 0xff,uVar2 >> 8 & 0xff,uVar2 >> 0x10 & 0xff,
                 uVar2 >> 0x18,(double)*pfVar1);
    } while (iVar4 < numipfilters);
  }
  return;
}


// SV_ListId_f  @ 000ab2b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ListId_f(void)

{
  float fVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  float *pfVar5;
  
                    /* Unresolved local var: int i@[???] */
  if (numuserfilters < 1) {
    Con_Printf("UserID filter list: empty\n");
    return;
  }
  Con_Printf("UserID filter list: %i entries\n",numuserfilters);
  if (0 < numuserfilters) {
    pfVar5 = &userfilters[0].banTime;
    iVar4 = 1;
    do {
      while( true ) {
        fVar1 = *pfVar5;
        if (fVar1 != 0.0) break;
        pcVar3 = SV_GetIDString(&userfilters[iVar4 + -1].userid);
        pfVar5 = pfVar5 + 6;
        Con_Printf("%i %s : permanent\n",iVar4,pcVar3);
        bVar2 = numuserfilters <= iVar4;
        iVar4 = iVar4 + 1;
        if (bVar2) {
          return;
        }
      }
      pcVar3 = SV_GetIDString(&userfilters[iVar4 + -1].userid);
      pfVar5 = pfVar5 + 6;
      Con_Printf("%i %s : %.3f min\n",iVar4,pcVar3,(double)fVar1);
      bVar2 = iVar4 < numuserfilters;
      iVar4 = iVar4 + 1;
    } while (bVar2);
  }
  return;
}


// SV_LoadEntities  @ 000a8730
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_LoadEntities(void)

{
  ED_LoadFromFile((sv.worldmodel)->entities);
  return;
}


// SV_Localinfo_f  @ 0009be90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Localinfo_f(void)

{
  int iVar1;
  char *pcVar2;
  char *key;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Local info settings:\n");
    Info_Print(localinfo);
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    if (*pcVar2 != '*') {
      pcVar2 = Cmd_Argv(2);
      key = Cmd_Argv(1);
      Info_SetValueForKey(localinfo,key,pcVar2,0x8000);
      return;
    }
    Con_Printf("Star variables cannot be changed.\n");
  }
  else {
    Con_Printf("usage: localinfo [ <key> <value> ]\n");
  }
  return;
}


// SV_LookupDelta  @ 0009c190
delta_t * SV_LookupDelta(char *name)

{
  delta_info_s *pdVar1;
  int iVar2;
  
  pdVar1 = g_sv_delta;
  while( true ) {
    if (pdVar1 == (delta_info_t *)0x0) {
      Sys_Error("Couldn\'t find delta for %s\n",name);
      return (delta_t *)0x0;
    }
    iVar2 = Q_stricmp(name,pdVar1->name);
    if (iVar2 == 0) break;
    pdVar1 = pdVar1->next;
  }
  return pdVar1->delta;
}


// SV_LookupSoundIndex  @ 0009cd10
int SV_LookupSoundIndex(char *sample)

{
  __int32_t **pp_Var1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  uint uVar6;
  uint uVar7;
  int iVar5;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???] */
                    /* Unresolved local var: uint hash@[???] */
  uVar7 = 0;
  cVar4 = *sample;
  if (cVar4 != '\0') {
    pp_Var1 = __ctype_tolower_loc();
    uVar7 = 0;
    pcVar2 = sample;
    do {
                    /* Unresolved local var: int __res@[???] */
      iVar5 = (int)cVar4;
      pcVar2 = pcVar2 + 1;
      cVar4 = *pcVar2;
      uVar7 = uVar7 * 2 + (*pp_Var1)[iVar5];
    } while (cVar4 != '\0');
    uVar7 = uVar7 % 0x3ff;
  }
  uVar6 = uVar7;
  if (sv.sound_precache_hashedlookup_built == false) {
    if (sv.state == ss_loading) {
      iVar5 = 1;
      while( true ) {
        if (sv.sound_precache[iVar5] == (char *)0x0) {
          return 0;
        }
        iVar3 = Q_strcasecmp(sample,sv.sound_precache[iVar5]);
        if (iVar3 == 0) break;
        iVar5 = iVar5 + 1;
        if (iVar5 == 0x200) {
          return 0;
        }
      }
      return iVar5;
    }
    SV_BuildHashedSoundLookupTable();
  }
  while( true ) {
    iVar5 = (int)*(short *)(uVar6 + 0x51ffa8 + uVar6 + 0x195a0);
    if (iVar5 == 0) {
      return 0;
    }
    iVar5 = Q_strcasecmp(sample,sv.sound_precache[iVar5]);
    if (iVar5 == 0) break;
    uVar6 = uVar6 + 1;
    if (uVar6 == 0x3ff) {
      uVar6 = 0;
    }
    if (uVar6 == uVar7) {
      return 0;
    }
  }
  return (int)*(short *)(uVar6 + 0x51ffa8 + uVar6 + 0x195a0);
}


// SV_ModelIndex  @ 000a6550
int SV_ModelIndex(char *name)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  if ((name != (char *)0x0) && (*name != '\0')) {
    do {
      if (sv.model_precache[iVar2] == (char *)0x0) break;
      iVar1 = Q_strcasecmp(sv.model_precache[iVar2],name);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x200);
    Sys_Error("SV_ModelIndex: model %s not precached",name);
  }
  return iVar2;
}


// SV_Move  @ 000c1750
trace_t * SV_Move(trace_t *__return_storage_ptr__,vec_t *start,vec_t *mins,vec_t *maxs,vec_t *end,
                 int type,edict_t_conflict *passedict,qboolean monsterClipBrush)

{
  float fVar1;
  uint uVar2;
  moveclip_t local_12c;
  trace_t local_9c;
  undefined4 auStack_64 [14];
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  
                    /* Unresolved local var: moveclip_t clip@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t worldEndPoint@[???]
                       Unresolved local var: float worldFraction@[???] */
  Q_memset(&local_12c,0,0x84);
                    /* Unresolved local var: trace_t goodtrace@[???] */
  SV_SingleClipMoveToEntity(sv.edicts,start,mins,maxs,end,&local_9c);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)auStack_64 + uVar2) =
         *(undefined4 *)((int)local_9c.endpos + (uVar2 - 0x14));
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)local_12c.trace.endpos + (uVar2 - 0x14)) =
         *(undefined4 *)((int)auStack_64 + uVar2);
    fVar1 = local_12c.trace.fraction;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  if (local_12c.trace.fraction == 0.0) {
    uVar2 = 0;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar2 - 0x14)) =
           *(undefined4 *)((int)local_12c.trace.endpos + (uVar2 - 0x14));
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x38);
  }
  else {
    local_12c.trace.fraction = 1.0;
    local_12c.mins = mins;
    local_12c.start = start;
    local_2c = local_12c.trace.endpos[0];
    local_12c.maxs = maxs;
    local_12c.type = (short)(byte)type;
    local_28 = local_12c.trace.endpos[1];
    local_12c.ignoretrans = (short)((uint)type >> 8);
    local_24 = local_12c.trace.endpos[2];
    local_12c.end = &local_2c;
    local_12c.passedict = passedict;
    local_12c.monsterClipBrush = monsterClipBrush;
    if (type == 2) {
      local_12c.mins2[0] = -15.0;
      local_12c.maxs2[0] = 15.0;
      local_12c.mins2[1] = -15.0;
      local_12c.maxs2[1] = 15.0;
      local_12c.mins2[2] = -15.0;
      local_12c.maxs2[2] = 15.0;
    }
    else {
      local_12c.mins2[0] = *mins;
      local_12c.mins2[1] = mins[1];
      local_12c.mins2[2] = mins[2];
      local_12c.maxs2[0] = *maxs;
      local_12c.maxs2[1] = maxs[1];
      local_12c.maxs2[2] = maxs[2];
    }
    SV_MoveBounds(start,local_12c.mins2,local_12c.maxs2,local_12c.end,local_12c.boxmins,
                  local_12c.boxmaxs);
    SV_ClipToLinks(sv_areanodes,&local_12c);
    gGlobalVariables.trace_ent = local_12c.trace.ent;
    uVar2 = 0;
    local_12c.trace.fraction = fVar1 * local_12c.trace.fraction;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar2 - 0x14)) =
           *(undefined4 *)((int)local_12c.trace.endpos + (uVar2 - 0x14));
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x38);
  }
  return __return_storage_ptr__;
}


// SV_MoveBounds  @ 000c11b0
void SV_MoveBounds(vec_t *start,vec_t *mins,vec_t *maxs,vec_t *end,vec_t *boxmins,vec_t *boxmaxs)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (*start < *end) {
    *boxmins = (*start + *mins) - 1.0;
    *boxmaxs = *end + *maxs + 1.0;
    fVar1 = end[1];
    fVar2 = start[1];
    if (fVar2 < fVar1) goto LAB_000c1252;
  }
  else {
    *boxmins = (*end + *mins) - 1.0;
    *boxmaxs = *start + *maxs + 1.0;
    fVar1 = end[1];
    fVar2 = start[1];
    if (fVar2 < fVar1) {
LAB_000c1252:
      boxmins[1] = (fVar2 + mins[1]) - 1.0;
      boxmaxs[1] = end[1] + maxs[1] + 1.0;
      fVar1 = end[2];
      fVar2 = start[2];
      if (fVar1 <= fVar2) goto LAB_000c1282;
      goto LAB_000c122a;
    }
  }
  boxmins[1] = (fVar1 + mins[1]) - 1.0;
  boxmaxs[1] = start[1] + maxs[1] + 1.0;
  fVar1 = end[2];
  fVar2 = start[2];
  if (fVar1 <= fVar2) {
LAB_000c1282:
    boxmins[2] = (fVar1 + mins[2]) - 1.0;
    boxmaxs[2] = start[2] + maxs[2] + 1.0;
    return;
  }
LAB_000c122a:
  boxmins[2] = (fVar2 + mins[2]) - 1.0;
  boxmaxs[2] = end[2] + maxs[2] + 1.0;
  return;
}


// SV_MoveNoEnts  @ 000c1530
trace_t * SV_MoveNoEnts(trace_t *__return_storage_ptr__,vec_t *start,vec_t *mins,vec_t *maxs,
                       vec_t *end,int type,edict_t_conflict *passedict)

{
  float fVar1;
  uint uVar2;
  moveclip_t local_11c;
  trace_t local_98;
  undefined4 auStack_60 [14];
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: moveclip_t clip@[???]
                       Unresolved local var: vec3_t worldEndPoint@[???]
                       Unresolved local var: float worldFraction@[???] */
                    /* Unresolved local var: trace_t goodtrace@[???] */
  Q_memset(&local_11c,0,0x84);
  SV_SingleClipMoveToEntity(sv.edicts,start,mins,maxs,end,&local_98);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)auStack_60 + uVar2) =
         *(undefined4 *)((int)local_98.endpos + (uVar2 - 0x14));
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)local_11c.trace.endpos + (uVar2 - 0x14)) =
         *(undefined4 *)((int)auStack_60 + uVar2);
    fVar1 = local_11c.trace.fraction;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  uVar2 = 0;
  if (local_11c.trace.fraction == 0.0) {
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar2 - 0x14)) =
           *(undefined4 *)((int)local_11c.trace.endpos + (uVar2 - 0x14));
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x38);
  }
  else {
    local_11c.trace.fraction = 1.0;
    local_11c.mins = mins;
    local_11c.start = start;
    local_28 = local_11c.trace.endpos[0];
    local_11c.maxs = maxs;
    local_11c.monsterClipBrush = false;
    local_11c.type = (short)(byte)type;
    local_24 = local_11c.trace.endpos[1];
    local_11c.ignoretrans = (short)((uint)type >> 8);
    local_20 = local_11c.trace.endpos[2];
    local_11c.end = &local_28;
    local_11c.passedict = passedict;
    local_11c.mins2[0] = *mins;
    local_11c.mins2[1] = mins[1];
    local_11c.mins2[2] = mins[2];
    local_11c.maxs2[0] = *maxs;
    local_11c.maxs2[1] = maxs[1];
    local_11c.maxs2[2] = maxs[2];
    SV_MoveBounds(start,local_11c.mins2,local_11c.maxs2,local_11c.end,local_11c.boxmins,
                  local_11c.boxmaxs);
    SV_ClipToWorldbrush(sv_areanodes,&local_11c);
    gGlobalVariables.trace_ent = local_11c.trace.ent;
    uVar2 = 0;
    local_11c.trace.fraction = fVar1 * local_11c.trace.fraction;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar2 - 0x14)) =
           *(undefined4 *)((int)local_11c.trace.endpos + (uVar2 - 0x14));
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x38);
  }
  return __return_storage_ptr__;
}


// SV_MoveToOnHandList  @ 000b6f80
void SV_MoveToOnHandList(resource_t *pResource)

{
  client_t *pcVar1;
  
  if (pResource != (resource_t *)0x0) {
    pResource->pPrev->pNext = pResource->pNext;
    pResource->pNext->pPrev = pResource->pPrev;
    pResource->pPrev = (resource_s *)0x0;
    pcVar1 = host_client;
    pResource->pNext = (resource_s *)0x0;
    pResource->pPrev = (pcVar1->resourcesonhand).pPrev;
    ((pcVar1->resourcesonhand).pPrev)->pNext = pResource;
    (pcVar1->resourcesonhand).pPrev = pResource;
    pResource->pNext = &pcVar1->resourcesonhand;
    return;
  }
  Con_DPrintf("Null resource passed to SV_MoveToOnHandList\n");
  return;
}


// SV_MoveToOrigin_I  @ 000b1590
void SV_MoveToOrigin_I(edict_t_conflict *ent,float *pflGoal,float dist,int iStrafe)

{
  uint uVar1;
  float fVar2;
  qboolean qVar3;
  qboolean relink;
  qboolean relink_00;
  double local_54;
  double local_4c;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: vec3_t vecGoal@[???]
                       Unresolved local var: vec3_t vecDir@[???]
                       Unresolved local var: float flReturn@[???] */
  local_24 = *pflGoal;
  local_20 = pflGoal[1];
  local_1c = pflGoal[2];
  uVar1 = (ent->v).flags;
  if ((uVar1 & 0x203) != 0) {
    if (iStrafe == 0) {
      fVar2 = (ent->v).ideal_yaw * 3.1415927;
      local_40 = (fVar2 + fVar2) / 360.0;
      sincos((double)local_40,&local_4c,&local_54);
      local_10 = 0;
      local_18 = (float)local_54 * dist;
      local_14 = dist * (float)local_4c;
      qVar3 = SV_movestep(ent,&local_18,relink_00);
      if (qVar3 == false) {
        SV_LinkEdict(ent,true);
        SV_NewChaseDir2(ent,&local_24,dist);
        return;
      }
    }
    else {
      local_3c = local_24 - (ent->v).origin[0];
      local_38 = local_20 - (ent->v).origin[1];
      local_34 = local_1c - (ent->v).origin[2];
      if ((uVar1 & 3) == 0) {
        local_34 = 0.0;
      }
      VectorNormalize(&local_3c);
      VectorScale(&local_3c,dist,&local_3c);
                    /* Unresolved local var: vec3_t oldorigin@[???] */
      SV_movestep(ent,&local_3c,relink);
    }
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    SV_LinkEdict(ent,true);
  }
  return;
}


// SV_Multicast  @ 0009d3b0
void SV_Multicast(edict_t_conflict *ent,vec_t *origin,int to,qboolean reliable)

{
  uint uVar1;
  uint uVar2;
  client_t *pcVar3;
  client_t *pcVar4;
  mleaf_t *pmVar5;
  qboolean qVar6;
  sizebuf_t *buf;
  client_t *pcVar7;
  client_s *pcVar8;
  int iVar9;
  int iVar10;
  int local_2c;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int leafnum@[DW_OP_breg4(ESP): +32]
                       Unresolved local var: int j@[???]
                       Unresolved local var: sizebuf_t * pBuffer@[???]
                       Unresolved local var: client_t * save@[???] */
  pcVar4 = host_client;
                    /* Unresolved local var: mleaf_t * pLeaf@[???] */
  pmVar5 = Mod_PointInLeaf(origin,sv.worldmodel);
  local_2c = 0;
  if (pmVar5 != (mleaf_t *)0x0) {
    local_2c = ((int)pmVar5 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555;
  }
  if ((ent == (edict_t_conflict *)0x0) ||
     ((host_client != (client_t *)0x0 && (host_client->edict == ent)))) {
    pcVar7 = host_client;
    if (svs.maxclients < 1) goto LAB_0009d570;
  }
  else {
    if (svs.maxclients < 1) goto LAB_0009d570;
    pcVar7 = svs.clients;
    if ((svs.clients)->edict != ent) {
      iVar9 = 0;
      pcVar8 = svs.clients;
      do {
        iVar9 = iVar9 + 1;
        pcVar7 = host_client;
        if (iVar9 == svs.maxclients) break;
        pcVar7 = pcVar8 + 1;
        pcVar3 = pcVar8 + 1;
        pcVar8 = pcVar7;
      } while (pcVar3->edict != ent);
    }
  }
  host_client = pcVar7;
  iVar10 = 0;
  iVar9 = svs.maxclients;
  pcVar8 = svs.clients;
  do {
    if ((pcVar8->active == false) || (((to & 0x80U) != 0 && (pcVar8 == host_client))))
    goto LAB_0009d525;
    if ((ent == (edict_t_conflict *)0x0) ||
       ((uVar1 = (ent->v).groupinfo, uVar1 == 0 ||
        (uVar2 = (pcVar8->edict->v).groupinfo, uVar2 == 0)))) {
LAB_0009d4e0:
      qVar6 = SV_ValidClientMulticast(pcVar8,local_2c,to);
      iVar9 = svs.maxclients;
      if (qVar6 == false) {
        gPacketSuppressed = gPacketSuppressed + sv.multicast.cursize;
      }
      else {
        buf = &(pcVar8->netchan).message;
        if (reliable == false) {
          buf = &pcVar8->datagram;
        }
        if (sv.multicast.cursize < buf->maxsize - buf->cursize) {
          SZ_Write(buf,sv.multicast.data,sv.multicast.cursize);
          iVar9 = svs.maxclients;
        }
      }
    }
    else if (g_groupop == 0) {
      if ((uVar2 & uVar1) != 0) goto LAB_0009d4e0;
    }
    else if ((g_groupop != 1) || ((uVar2 & uVar1) == 0)) goto LAB_0009d4e0;
LAB_0009d525:
    iVar10 = iVar10 + 1;
    pcVar8 = pcVar8 + 1;
  } while (iVar10 < iVar9);
LAB_0009d570:
  SZ_Clear(&sv.multicast);
  host_client = pcVar4;
  return;
}


// SV_NewChaseDir  @ 000af870
void SV_NewChaseDir(edict_t_conflict *actor,edict_t_conflict *enemy,float dist)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  qboolean qVar7;
  int32 iVar8;
  uint uVar9;
  qboolean relink;
  uint uVar10;
  qboolean relink_00;
  qboolean relink_01;
  qboolean relink_02;
  qboolean extraout_ECX;
  qboolean extraout_ECX_00;
  qboolean extraout_ECX_01;
  qboolean extraout_ECX_02;
  qboolean extraout_ECX_03;
  qboolean extraout_ECX_04;
  qboolean extraout_ECX_05;
  qboolean extraout_ECX_06;
  qboolean extraout_ECX_07;
  qboolean extraout_ECX_08;
  qboolean extraout_ECX_09;
  qboolean extraout_ECX_10;
  qboolean extraout_ECX_11;
  qboolean extraout_ECX_12;
  qboolean relink_03;
  qboolean relink_04;
  float fVar11;
  float fVar12;
  double local_34;
  double local_2c;
  float local_20;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: float deltax@[???]
                       Unresolved local var: float deltay@[???]
                       Unresolved local var: float[3] d@[???]
                       Unresolved local var: float tdir@[???]
                       Unresolved local var: float olddir@[???]
                       Unresolved local var: float turnaround@[???] */
  fVar11 = anglemod((float)((int)((actor->v).ideal_yaw / 45.0) * 0x2d));
  fVar12 = anglemod(fVar11 - 180.0);
  fVar2 = (enemy->v).origin[0] - (actor->v).origin[0];
  fVar3 = (enemy->v).origin[1] - (actor->v).origin[1];
  fVar4 = 0.0;
  if (fVar2 <= 10.0) {
    fVar4 = 180.0;
    if (-10.0 <= fVar2) {
      fVar4 = -1.0;
    }
  }
  fVar5 = 270.0;
  if (-10.0 <= fVar3) {
    fVar5 = 90.0;
    if (fVar3 <= 10.0) {
      fVar5 = -1.0;
    }
  }
  if ((fVar4 != -1.0) && (fVar5 != -1.0)) {
    if (fVar4 == 0.0) {
      fVar6 = 45.0;
      if (fVar5 != 90.0) {
        fVar6 = 315.0;
      }
    }
    else {
      fVar6 = 135.0;
      if (fVar5 != 90.0) {
        fVar6 = 215.0;
      }
    }
    if (fVar6 != fVar12) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_20 = (fVar6 * 3.1415927 + fVar6 * 3.1415927) / 360.0;
      sincos((double)local_20,&local_2c,&local_34);
      local_10 = 0;
      local_18 = (float)local_34 * dist;
      local_14 = dist * (float)local_2c;
      qVar7 = SV_movestep(actor,&local_18,relink);
      if (qVar7 != false) goto LAB_000afdf0;
      SV_LinkEdict(actor,true);
    }
  }
  iVar8 = RandomLong(0,1);
  fVar6 = fVar5;
  if ((iVar8 == 0) &&
     (uVar9 = (int)fVar3 >> 0x1f, uVar10 = (int)fVar2 >> 0x1f,
     (int)(((int)fVar3 ^ uVar9) - uVar9) <= (int)(((int)fVar2 ^ uVar10) - uVar10))) {
    fVar6 = fVar4;
    fVar4 = fVar5;
  }
  if ((fVar6 != -1.0) && (fVar12 != fVar6)) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar6 * 3.1415927 + fVar6 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_03);
    if (qVar7 != false) goto LAB_000afdf0;
    SV_LinkEdict(actor,true);
  }
  if ((fVar4 != -1.0) && (fVar12 != fVar4)) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar4 * 3.1415927 + fVar4 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_04);
    if (qVar7 != false) goto LAB_000afdf0;
    SV_LinkEdict(actor,true);
  }
  if (fVar11 != -1.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar11 * 3.1415927 + fVar11 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_00);
    if (qVar7 != false) goto LAB_000afdf0;
    SV_LinkEdict(actor,true);
  }
  iVar8 = RandomLong(0,1);
  qVar7 = relink_01;
  if (iVar8 == 0) {
    if (fVar12 != 315.0) {
      local_18 = dist * 0.70710665;
      local_10 = 0;
      local_14 = dist * -0.7071069;
      qVar7 = SV_movestep(actor,&local_18,relink_01);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_00;
    }
    if (fVar12 != 270.0) {
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_02;
    }
    if (fVar12 != 225.0) {
      local_18 = dist * -0.7071068;
      local_10 = 0;
      local_14 = dist * -0.7071067;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_03;
    }
    if (fVar12 != 180.0) {
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_06;
    }
    if (fVar12 != 135.0) {
      local_18 = dist * -0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_08;
    }
    if (fVar12 != 90.0) {
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_09;
    }
    if (fVar12 != 45.0) {
      local_18 = dist * 0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_11;
    }
    if (fVar12 != 0.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist;
      local_14 = dist * 0.0;
      goto LAB_000afeea;
    }
  }
  else {
    if (fVar12 != 0.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist;
      local_14 = dist * 0.0;
      local_10 = 0;
      qVar7 = SV_movestep(actor,&local_18,relink_01);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX;
    }
    if (fVar12 != 45.0) {
      local_18 = dist * 0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_01;
    }
    if (fVar12 != 90.0) {
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_04;
    }
    if (fVar12 != 135.0) {
      local_18 = dist * -0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_05;
    }
    if (fVar12 != 180.0) {
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_07;
    }
    if (fVar12 != 225.0) {
      local_18 = dist * -0.7071068;
      local_10 = 0;
      local_14 = dist * -0.7071067;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_10;
    }
    if (fVar12 != 270.0) {
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b04f8;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_12;
    }
    if (fVar12 != 315.0) {
      local_18 = dist * 0.70710665;
      local_14 = dist * -0.7071069;
LAB_000afeea:
      local_10 = 0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) {
LAB_000b04f8:
        SV_LinkEdict(actor,true);
        return;
      }
      SV_LinkEdict(actor,true);
    }
  }
  if (fVar12 != -1.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar12 * 3.1415927 + fVar12 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_02);
    if (qVar7 != false) {
LAB_000afdf0:
      SV_LinkEdict(actor,true);
      return;
    }
    SV_LinkEdict(actor,true);
  }
  (actor->v).ideal_yaw = fVar11;
  qVar7 = SV_CheckBottom(actor);
  if (qVar7 == false) {
    piVar1 = &(actor->v).flags;
    *piVar1 = *piVar1 | 0x400;
  }
  return;
}


// SV_NewChaseDir2  @ 000b07c0
void SV_NewChaseDir2(edict_t_conflict *actor,vec_t *vecGoal,float dist)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  qboolean qVar7;
  int32 iVar8;
  uint uVar9;
  qboolean relink;
  uint uVar10;
  qboolean relink_00;
  qboolean relink_01;
  qboolean relink_02;
  qboolean extraout_ECX;
  qboolean extraout_ECX_00;
  qboolean extraout_ECX_01;
  qboolean extraout_ECX_02;
  qboolean extraout_ECX_03;
  qboolean extraout_ECX_04;
  qboolean extraout_ECX_05;
  qboolean extraout_ECX_06;
  qboolean extraout_ECX_07;
  qboolean extraout_ECX_08;
  qboolean extraout_ECX_09;
  qboolean extraout_ECX_10;
  qboolean extraout_ECX_11;
  qboolean extraout_ECX_12;
  qboolean relink_03;
  qboolean relink_04;
  float fVar11;
  float fVar12;
  double local_34;
  double local_2c;
  float local_20;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: float deltax@[???]
                       Unresolved local var: float deltay@[???]
                       Unresolved local var: float[3] d@[???]
                       Unresolved local var: float tdir@[???]
                       Unresolved local var: float olddir@[???]
                       Unresolved local var: float turnaround@[???] */
  fVar11 = anglemod((float)((int)((actor->v).ideal_yaw / 45.0) * 0x2d));
  fVar12 = anglemod(fVar11 - 180.0);
  fVar2 = *vecGoal - (actor->v).origin[0];
  fVar3 = vecGoal[1] - (actor->v).origin[1];
  fVar4 = 0.0;
  if (fVar2 <= 10.0) {
    fVar4 = 180.0;
    if (-10.0 <= fVar2) {
      fVar4 = -1.0;
    }
  }
  fVar5 = 270.0;
  if (-10.0 <= fVar3) {
    fVar5 = 90.0;
    if (fVar3 <= 10.0) {
      fVar5 = -1.0;
    }
  }
  if ((fVar4 != -1.0) && (fVar5 != -1.0)) {
    if (fVar4 == 0.0) {
      fVar6 = 45.0;
      if (fVar5 != 90.0) {
        fVar6 = 315.0;
      }
    }
    else {
      fVar6 = 135.0;
      if (fVar5 != 90.0) {
        fVar6 = 215.0;
      }
    }
    if (fVar6 != fVar12) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_20 = (fVar6 * 3.1415927 + fVar6 * 3.1415927) / 360.0;
      sincos((double)local_20,&local_2c,&local_34);
      local_10 = 0;
      local_18 = (float)local_34 * dist;
      local_14 = dist * (float)local_2c;
      qVar7 = SV_movestep(actor,&local_18,relink);
      if (qVar7 != false) goto LAB_000b0d40;
      SV_LinkEdict(actor,true);
    }
  }
  iVar8 = RandomLong(0,1);
  fVar6 = fVar5;
  if ((iVar8 == 0) &&
     (uVar9 = (int)fVar3 >> 0x1f, uVar10 = (int)fVar2 >> 0x1f,
     (int)(((int)fVar3 ^ uVar9) - uVar9) <= (int)(((int)fVar2 ^ uVar10) - uVar10))) {
    fVar6 = fVar4;
    fVar4 = fVar5;
  }
  if ((fVar6 != -1.0) && (fVar12 != fVar6)) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar6 * 3.1415927 + fVar6 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_03);
    if (qVar7 != false) goto LAB_000b0d40;
    SV_LinkEdict(actor,true);
  }
  if ((fVar4 != -1.0) && (fVar12 != fVar4)) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar4 * 3.1415927 + fVar4 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_04);
    if (qVar7 != false) goto LAB_000b0d40;
    SV_LinkEdict(actor,true);
  }
  if (fVar11 != -1.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar11 * 3.1415927 + fVar11 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_00);
    if (qVar7 != false) goto LAB_000b0d40;
    SV_LinkEdict(actor,true);
  }
  iVar8 = RandomLong(0,1);
  qVar7 = relink_01;
  if (iVar8 == 0) {
    if (fVar12 != 315.0) {
      local_18 = dist * 0.70710665;
      local_10 = 0;
      local_14 = dist * -0.7071069;
      qVar7 = SV_movestep(actor,&local_18,relink_01);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_00;
    }
    if (fVar12 != 270.0) {
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_02;
    }
    if (fVar12 != 225.0) {
      local_18 = dist * -0.7071068;
      local_10 = 0;
      local_14 = dist * -0.7071067;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_03;
    }
    if (fVar12 != 180.0) {
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_06;
    }
    if (fVar12 != 135.0) {
      local_18 = dist * -0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_08;
    }
    if (fVar12 != 90.0) {
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_09;
    }
    if (fVar12 != 45.0) {
      local_18 = dist * 0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_11;
    }
    if (fVar12 != 0.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist;
      local_14 = dist * 0.0;
      goto LAB_000b0e3a;
    }
  }
  else {
    if (fVar12 != 0.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist;
      local_14 = dist * 0.0;
      local_10 = 0;
      qVar7 = SV_movestep(actor,&local_18,relink_01);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX;
    }
    if (fVar12 != 45.0) {
      local_18 = dist * 0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_01;
    }
    if (fVar12 != 90.0) {
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_04;
    }
    if (fVar12 != 135.0) {
      local_18 = dist * -0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_05;
    }
    if (fVar12 != 180.0) {
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_07;
    }
    if (fVar12 != 225.0) {
      local_18 = dist * -0.7071068;
      local_10 = 0;
      local_14 = dist * -0.7071067;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_10;
    }
    if (fVar12 != 270.0) {
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) goto LAB_000b1448;
      SV_LinkEdict(actor,true);
      qVar7 = extraout_ECX_12;
    }
    if (fVar12 != 315.0) {
      local_18 = dist * 0.70710665;
      local_14 = dist * -0.7071069;
LAB_000b0e3a:
      local_10 = 0;
      qVar7 = SV_movestep(actor,&local_18,qVar7);
      if (qVar7 != false) {
LAB_000b1448:
        SV_LinkEdict(actor,true);
        return;
      }
      SV_LinkEdict(actor,true);
    }
  }
  if (fVar12 != -1.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_20 = (fVar12 * 3.1415927 + fVar12 * 3.1415927) / 360.0;
    sincos((double)local_20,&local_34,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_34;
    qVar7 = SV_movestep(actor,&local_18,relink_02);
    if (qVar7 != false) {
LAB_000b0d40:
      SV_LinkEdict(actor,true);
      return;
    }
    SV_LinkEdict(actor,true);
  }
  (actor->v).ideal_yaw = fVar11;
  qVar7 = SV_CheckBottom(actor);
  if (qVar7 == false) {
    piVar1 = &(actor->v).flags;
    *piVar1 = *piVar1 | 0x400;
  }
  return;
}


// SV_New_f  @ 000a3280
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_New_f(void)

{
  edict_t_conflict *peVar1;
  qboolean *pqVar2;
  UserMsg *pUVar3;
  client_t *pcVar4;
  char *pcVar5;
  qboolean qVar6;
  int iVar7;
  _UserMsg *p_Var8;
  client_s *cl;
  int iVar9;
  byte abStack_101f0 [65536];
  char local_1f0 [256];
  char local_f0 [128];
  char local_70 [64];
  sizebuf_t local_30;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: char[128] szRejectReason@[???]
                       Unresolved local var: char[256] szAddress@[???]
                       Unresolved local var: char[64] szName@[???] */
  Q_memset(&local_30,0,0x14);
  pcVar4 = host_client;
  local_30.buffername = "New Connection";
  local_30.data = abStack_101f0;
  local_30.cursize = 0;
  local_30.maxsize = 0x10000;
  if (((cmd_source != src_command) &&
      ((host_client->hasusrmsgs == false || (host_client->m_bSentNewResponse == false)))) &&
     ((host_client->spawned == false || (host_client->active != false)))) {
    peVar1 = host_client->edict;
    host_client->connection_started = realtime;
    pcVar4->connected = true;
    pcVar4->m_sendrescount = 0;
    SZ_Clear(&(pcVar4->netchan).message);
    SZ_Clear(&host_client->datagram);
    Netchan_Clear(&host_client->netchan);
    SV_SendServerinfo(&local_30,host_client);
    pUVar3 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != (UserMsg *)0x0) {
                    /* Unresolved local var: UserMsg * pTemp@[???] */
      sv_gpNewUserMsgs = sv_gpUserMsgs;
      p_Var8 = sv_gpUserMsgs;
      do {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
        MSG_WriteByte(&local_30,0x27);
        MSG_WriteByte(&local_30,p_Var8->iMsg);
        MSG_WriteByte(&local_30,p_Var8->iSize);
        MSG_WriteLong(&local_30,*(int *)p_Var8->szName);
        MSG_WriteLong(&local_30,*(int *)(p_Var8->szName + 4));
        MSG_WriteLong(&local_30,*(int *)(p_Var8->szName + 8));
        MSG_WriteLong(&local_30,*(int *)(p_Var8->szName + 0xc));
        p_Var8 = p_Var8->next;
      } while (p_Var8 != (_UserMsg *)0x0);
    }
    pcVar4 = host_client;
    pqVar2 = &host_client->active;
    sv_gpNewUserMsgs = pUVar3;
    host_client->hasusrmsgs = true;
    if (((*pqVar2 != false) || (pcVar4->spawned != false)) &&
       (pcVar4->edict != (edict_t_conflict *)0x0)) {
      (*gEntityInterface.pfnClientDisconnect)(pcVar4->edict);
      pcVar4 = host_client;
    }
    snprintf(local_70,0x40,"%s",pcVar4->name);
    pcVar5 = NET_AdrToString((host_client->netchan).remote_address);
    snprintf(local_1f0,0x100,"%s",pcVar5);
    snprintf(local_f0,0x80,"Connection rejected by game\n");
    qVar6 = (*gEntityInterface.pfnClientConnect)(peVar1,local_70,local_1f0,local_f0);
    if (qVar6 == false) {
      MSG_WriteByte(&(host_client->netchan).message,9);
      pcVar5 = va("echo %s\n",local_f0);
      MSG_WriteString(&(host_client->netchan).message,pcVar5);
      SV_DropClient(host_client,false,"Server refused connection because:  %s",local_f0);
      return;
    }
    iVar9 = 0;
    MSG_WriteByte(&local_30,9);
    pcVar5 = Info_Serverinfo();
    pcVar5 = va("fullserverinfo \"%s\"\n",pcVar5);
    MSG_WriteString(&local_30,pcVar5);
    iVar7 = svs.maxclients;
    pcVar4 = host_client;
    cl = svs.clients;
    if (0 < svs.maxclients) {
      do {
        if (((pcVar4 == cl) || (cl->active != false)) ||
           ((cl->connected != false || (cl->spawned != false)))) {
          SV_FullClientUpdate(cl,&local_30);
          iVar7 = svs.maxclients;
          pcVar4 = host_client;
        }
        iVar9 = iVar9 + 1;
        cl = cl + 1;
      } while (iVar9 < iVar7);
    }
    Netchan_CreateFragments(true,&pcVar4->netchan,&local_30);
    Netchan_FragSend(&host_client->netchan);
    host_client->m_bSentNewResponse = true;
  }
  return;
}


// SV_ParseConsistencyResponse  @ 000b8040
void SV_ParseConsistencyResponse(client_t *pSenderClient)

{
  uchar *src;
  int iVar1;
  uint32 uVar2;
  uint32 uVar3;
  int iVar4;
  char *pcVar5;
  int local_1c4;
  int local_1c0;
  char local_1bc [256];
  undefined1 local_bc [32];
  undefined1 local_9c [32];
  uchar local_7c;
  undefined1 local_7b [12];
  undefined1 local_6f [19];
  float local_5c;
  float local_58;
  float local_54;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int value@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: int dropclient@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t cmins@[???]
                       Unresolved local var: vec3_t cmaxs@[???]
                       Unresolved local var: uchar[32] readbuffer@[???]
                       Unresolved local var: uchar[32] nullbuffer@[???]
                       Unresolved local var: uchar[32] resbuffer@[???]
                       Unresolved local var: FORCE_TYPE ft@[???]
                       Unresolved local var: int length@[???] */
  Q_memset(local_9c,0,0x20);
  iVar1 = MSG_ReadShort();
  if ((iVar1 < 1) || (net_message.cursize < msg_readcount + iVar1)) {
    Sys_Error("SV_ParseConsistencyResponse: invalid length: %d\n",iVar1);
  }
  COM_UnMunge(net_message.data + msg_readcount,iVar1,svs.spawncount);
  MSG_StartBitReading(&net_message);
  local_1c4 = 0;
  local_1c0 = 0;
  do {
    uVar3 = MSG_ReadBits(1);
    if (uVar3 == 0) {
LAB_000b8221:
      MSG_EndBitReading(&net_message);
      if ((local_1c0 < 0) || (sv.num_consistency != local_1c4)) {
LAB_000b8245:
        msg_badread = true;
        pcVar5 = NET_AdrToString((host_client->netchan).remote_address);
        Con_Printf("SV_ParseConsistencyResponse:  %s:%s sent bad file data\n",host_client->name,
                   pcVar5);
        SV_DropClient(host_client,false,"Bad file data");
      }
      else {
        if (local_1c0 == 0) {
          host_client->has_force_unmodified = false;
          return;
        }
                    /* Unresolved local var: char[256] dropmessage@[???] */
        local_1bc[0] = '\0';
        iVar1 = (*gEntityInterface.pfnInconsistentFile)
                          ((edict_s *)host_client->edict,
                           (char *)((local_1c0 + -1) * 0x88 + 0x506b40),local_1bc);
        if (iVar1 != 0) {
          iVar1 = Q_strlen(local_1bc);
          if (0 < iVar1) {
            SV_ClientPrintf("%s",local_1bc);
          }
          SV_DropClient(host_client,false,"Bad file %s",local_1bc);
        }
      }
      return;
    }
    uVar3 = MSG_ReadBits(0xc);
    if ((((int)uVar3 < 0) || (sv.num_resources <= (int)uVar3)) ||
       (-1 < (char)sv.resourcelist[uVar3].ucFlags)) {
      MSG_EndBitReading(&net_message);
      goto LAB_000b8245;
    }
    src = sv.resourcelist[uVar3].rguc_reserved;
    Q_memcpy(local_bc,src,0x20);
    iVar4 = Q_memcmp(local_bc,local_9c,0x20);
    iVar1 = local_1c0;
    if (iVar4 == 0) {
      uVar2 = MSG_ReadBits(0x20);
      iVar1 = uVar3 + 1;
      if (*(uint32 *)sv.resourcelist[uVar3].rgucMD5_hash == uVar2) {
        iVar1 = local_1c0;
      }
    }
    else {
      MSG_ReadBitData(&local_3c,0xc);
      MSG_ReadBitData(&local_2c,0xc);
      Q_memcpy(&local_7c,src,0x20);
      COM_UnMunge(&local_7c,0x20,svs.spawncount);
      if (local_7c == '\x02') {
        Q_memcpy(&local_5c,local_7b,0xc);
        Q_memcpy(&local_4c,local_6f,0xc);
        if (local_5c <= local_3c) {
LAB_000b8421:
          if ((((local_2c <= local_4c) && (local_58 <= local_38)) && (local_28 <= local_48)) &&
             ((local_54 <= local_34 && (local_24 <= local_44)))) goto LAB_000b80e9;
        }
LAB_000b8359:
        iVar1 = uVar3 + 1;
      }
      else if (local_7c == '\x03') {
        Q_memcpy(&local_5c,local_7b,0xc);
        Q_memcpy(&local_4c,local_6f,0xc);
        if ((((local_3c != -1.0) || (local_38 != -1.0)) ||
            ((local_34 != -1.0 || ((local_2c != -1.0 || (local_28 != -1.0)))))) ||
           (local_24 != -1.0)) {
          if (local_5c <= local_3c) goto LAB_000b8421;
          goto LAB_000b8359;
        }
      }
      else {
        if (local_7c != '\x01') {
          local_1c0 = uVar3 + 1;
          msg_badread = true;
          goto LAB_000b8221;
        }
        Q_memcpy(&local_5c,local_7b,0xc);
        Q_memcpy(&local_4c,local_6f,0xc);
        iVar4 = VectorCompare(&local_3c,&local_5c);
        if ((iVar4 == 0) || (iVar4 = VectorCompare(&local_2c,&local_4c), iVar4 == 0))
        goto LAB_000b8359;
      }
    }
LAB_000b80e9:
    local_1c0 = iVar1;
    if (msg_badread != false) goto LAB_000b8221;
    local_1c4 = local_1c4 + 1;
  } while( true );
}


// SV_ParseCvarValue  @ 000b7d80
void SV_ParseCvarValue(client_t *cl)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * value@[???] */
  pcVar1 = MSG_ReadString();
  if (gNewDLLFunctions.pfnCvarValue != (_func_void_edict_t_ptr_char_ptr *)0x0) {
    (*gNewDLLFunctions.pfnCvarValue)((edict_t *)cl->edict,pcVar1);
  }
  Con_DPrintf("Cvar query response: name:%s, value:%s\n",cl->name,pcVar1);
  return;
}


// SV_ParseCvarValue2  @ 000b7de0
void SV_ParseCvarValue2(client_t *cl)

{
  int iVar1;
  char *pcVar2;
  char local_11b [254];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * value@[???]
                       Unresolved local var: char[255] cvarName@[???]
                       Unresolved local var: int requestID@[???] */
  iVar1 = MSG_ReadLong();
  pcVar2 = MSG_ReadString();
  Q_strncpy(local_11b,pcVar2,0xff);
  local_1d = 0;
  pcVar2 = MSG_ReadString();
  if (gNewDLLFunctions.pfnCvarValue2 != (_func_void_edict_t_ptr_int_char_ptr_char_ptr *)0x0) {
    (*gNewDLLFunctions.pfnCvarValue2)((edict_t *)cl->edict,iVar1,local_11b,pcVar2);
  }
  Con_DPrintf("Cvar query response: name:%s, request ID %d, cvar:%s, value:%s\n",cl->name,iVar1,
              local_11b,pcVar2);
  return;
}


// SV_ParseDelta  @ 000b7d60
void SV_ParseDelta(client_t *pSenderClient)

{
  client_t *pcVar1;
  int iVar2;
  
  pcVar1 = host_client;
  iVar2 = MSG_ReadByte();
  pcVar1->delta_sequence = iVar2;
  return;
}


// SV_ParseMove  @ 000bb440
void __regparm3 SV_ParseMove(client_t *pSenderClient)

{
  uint uVar1;
  float *pfVar2;
  usercmd_t *from;
  client_frame_t *pcVar3;
  float fVar4;
  int iVar5;
  client_t *pcVar6;
  edict_t_conflict *peVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int numbackup;
  float *pfVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  bool bVar17;
  byte local_d78;
  usercmd_t local_d5c [64];
  usercmd_t local_50;
  
                    /* Unresolved local var: usercmd_t[64] cmds@[???]
                       Unresolved local var: usercmd_t * from@[???]
                       Unresolved local var: usercmd_t * to@[???]
                       Unresolved local var: int numbackup@[???]
                       Unresolved local var: int numcmds@[???]
                       Unresolved local var: int totalcmds@[???]
                       Unresolved local var: float packet_loss@[???]
                       Unresolved local var: usercmd_t cmdNull@[???]
                       Unresolved local var: uchar cbpktchecksum@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int placeholder@[???]
                       Unresolved local var: uchar cbchecksum@[???]
                       Unresolved local var: int mlen@[???]
                       Unresolved local var: int packetLossByte@[???]
                       Unresolved local var: int bits@[???] */
  iVar5 = SV_UPDATE_MASK;
  g_balreadymoved = true;
  from = &local_50;
  pcVar3 = host_client->frames;
  uVar13 = (host_client->netchan).incoming_acknowledged;
  Q_memset(from,0,0x34);
  iVar16 = msg_readcount;
  uVar14 = msg_readcount + 1;
  iVar9 = MSG_ReadByte();
  iVar10 = MSG_ReadByte();
  if ((iVar9 < 1) || (net_message.maxsize < iVar16 + 2 + iVar9)) {
    Sys_Error("SV_ParseMove: invalid length: %d",iVar9);
  }
  iVar16 = iVar16 + 2;
  COM_UnMunge(net_message.data + iVar16,iVar9,(host_client->netchan).incoming_sequence);
  uVar11 = MSG_ReadByte();
  pSenderClient->m_bLoopback = (uint)((uVar11 & 0x80) != 0);
  numbackup = MSG_ReadByte();
  iVar9 = MSG_ReadByte();
  uVar1 = numbackup + iVar9;
  net_drop = net_drop + (1 - iVar9);
  if (uVar1 < 0x3f) {
    while (uVar1 = uVar1 - 1, uVar1 != 0xffffffff) {
      MSG_ReadUsercmd(local_d5c + uVar1,from);
      from = local_d5c + uVar1;
    }
    if ((sv.active != false) && ((host_client->active != false || (host_client->spawned != false))))
    {
      if (msg_badread != false) {
        pcVar15 = NET_AdrToString((host_client->netchan).remote_address);
        Con_Printf("Client %s:%s sent a bogus command packet\n",host_client->name,pcVar15);
        return;
      }
      bVar8 = COM_BlockSequenceCRCByte
                        (net_message.data + iVar16,~uVar14 + msg_readcount,
                         (host_client->netchan).incoming_sequence);
      peVar7 = sv_player;
      pcVar6 = host_client;
      local_d78 = (byte)iVar10;
      if (bVar8 == local_d78) {
        bVar17 = sv.paused == false;
        host_client->packet_loss = (float)(int)(uVar11 & 0xffffff7f);
        iVar16 = net_drop;
        if ((bVar17) &&
           (((1 < svs.maxclients || (key_dest == key_game)) && (((peVar7->v).flags & 0x1000) == 0)))
           ) {
          (peVar7->v).v_angle[0] = local_d5c[0].viewangles[0];
          (peVar7->v).v_angle[1] = local_d5c[0].viewangles[1];
          (peVar7->v).v_angle[2] = local_d5c[0].viewangles[2];
        }
        else {
          if (0 < iVar9) {
            pfVar12 = &local_d5c[0].forwardmove;
            pfVar2 = pfVar12 + iVar9 * 0xd;
            do {
              *(byte *)((int)pfVar12 + -0xe) = '\0';
              *pfVar12 = 0.0;
              pfVar12[1] = 0.0;
              pfVar12[2] = 0.0;
              *(ushort *)((int)pfVar12 + 0xe) = 0;
              if (((peVar7->v).flags & 0x1000) != 0) {
                *(byte *)(pfVar12 + 4) = '\0';
              }
              pfVar12[-3] = (peVar7->v).v_angle[0];
              pfVar12[-2] = (peVar7->v).v_angle[1];
              pfVar12[-1] = (peVar7->v).v_angle[2];
              pfVar12 = pfVar12 + 0xd;
            } while (pfVar12 != pfVar2);
          }
          iVar16 = 0;
          net_drop = 0;
        }
        (peVar7->v).button = (uint)local_d5c[0].buttons;
        (peVar7->v).light_level = (uint)local_d5c[0].lightlevel;
        SV_EstablishTimeBase(pcVar6,local_d5c,iVar16,numbackup,iVar9);
        if (net_drop < 0x18) {
          for (; numbackup < net_drop; net_drop = net_drop + -1) {
            SV_RunCmd(&host_client->lastcmd,0);
          }
          for (; 0 < net_drop; net_drop = net_drop + -1) {
                    /* Unresolved local var: int cmdnum@[???] */
            iVar16 = iVar9 + -1 + net_drop;
            SV_RunCmd(local_d5c + iVar16,(host_client->netchan).incoming_sequence - iVar16);
          }
        }
        iVar9 = iVar9 + -1;
        if (-1 < iVar9) {
          do {
            iVar16 = iVar9 + -1;
            SV_RunCmd(local_d5c + iVar9,(host_client->netchan).incoming_sequence - iVar9);
            iVar9 = iVar16;
          } while (iVar16 != -1);
        }
        pcVar6 = host_client;
        uVar13 = iVar5 & uVar13;
        uVar14 = 0;
        do {
          *(undefined4 *)((int)(pcVar6->lastcmd).viewangles + (uVar14 - 4)) =
               *(undefined4 *)((int)local_d5c[0].viewangles + (uVar14 - 4));
          uVar14 = uVar14 + 4;
        } while (uVar14 < 0x34);
        fVar4 = pcVar3[uVar13].ping_time - ((float)(pcVar6->lastcmd).msec * 0.5) / 1000.0;
        pcVar3[uVar13].ping_time = fVar4;
        if (fVar4 < 0.0) {
          pcVar3[uVar13].ping_time = 0.0;
        }
        if ((longdouble)sv.time + (longdouble)host_frametime < (longdouble)(sv_player->v).animtime)
        {
          (sv_player->v).animtime = (float)((longdouble)sv.time + (longdouble)host_frametime);
        }
      }
      else {
        pcVar15 = NET_AdrToString((host_client->netchan).remote_address);
        Con_DPrintf("Failed command checksum for %s:%s\n",host_client->name,pcVar15);
        msg_badread = true;
      }
    }
    return;
  }
  pcVar15 = NET_AdrToString((host_client->netchan).remote_address);
  Con_Printf("SV_ReadClientMessage: too many cmds %i sent for %s/%s\n",uVar1,host_client->name,
             pcVar15);
  SV_DropClient(host_client,false,"CMD_MAXBACKUP hit");
  msg_badread = true;
  return;
}


// SV_ParseMove  @ 000bb9c0
void SV_ParseMove(client_t *pSenderClient)

{
                    /* Unresolved local var: usercmd_t[64] cmds@[???]
                       Unresolved local var: usercmd_t * from@[???]
                       Unresolved local var: usercmd_t * to@[???]
                       Unresolved local var: int numbackup@[???]
                       Unresolved local var: int numcmds@[???]
                       Unresolved local var: int totalcmds@[???]
                       Unresolved local var: float packet_loss@[???]
                       Unresolved local var: usercmd_t cmdNull@[???]
                       Unresolved local var: uchar cbpktchecksum@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int bits@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int placeholder@[???]
                       Unresolved local var: uchar cbchecksum@[???]
                       Unresolved local var: int mlen@[???]
                       Unresolved local var: int packetLossByte@[???] */
  if (g_balreadymoved != false) {
    msg_badread = true;
    return;
  }
  SV_ParseMove(pSenderClient);
  return;
}


// SV_ParseResourceList  @ 000b7560
void SV_ParseResourceList(client_t *pSenderClient)

{
  resource_s *prVar1;
  float fVar2;
  int iVar3;
  resource_s *prVar4;
  char *src;
  resourcetype_t rVar5;
  int iVar6;
  uint uVar7;
  qboolean qVar8;
  resource_s *prVar9;
  client_t *pcVar10;
  resource_t *prVar11;
  int iVar12;
  client_t *pcVar13;
  double dVar14;
  client_t *local_44;
  resourceinfo_t local_3c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int totalsize@[???]
                       Unresolved local var: resource_t * resource@[???]
                       Unresolved local var: resourceinfo_t ri@[???] */
  iVar3 = MSG_ReadShort();
  pcVar13 = host_client;
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar11 = &host_client->resourcesneeded;
  prVar4 = (host_client->resourcesneeded).pNext;
  pcVar10 = host_client;
  while ((host_client = pcVar10, prVar11 != prVar4 && (prVar4 != (resource_s *)0x0))) {
    prVar9 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar9;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    prVar4 = prVar9;
    pcVar10 = host_client;
  }
  (pcVar13->resourcesneeded).pPrev = prVar11;
  (pcVar13->resourcesneeded).pNext = prVar11;
  prVar11 = &pcVar10->resourcesonhand;
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar4 = (pcVar10->resourcesonhand).pNext;
  while ((prVar11 != prVar4 && (prVar4 != (resource_s *)0x0))) {
    prVar9 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar9;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    prVar4 = prVar9;
  }
  (pcVar10->resourcesonhand).pPrev = prVar11;
  (pcVar10->resourcesonhand).pNext = prVar11;
  if (0 < iVar3) {
    iVar12 = 0;
    do {
      while( true ) {
        prVar4 = Mem_ZeroMalloc(0x88);
        src = MSG_ReadString();
        Q_strncpy(prVar4->szFileName,src,0x3f);
        prVar4->szFileName[0x3f] = '\0';
        rVar5 = MSG_ReadByte();
        prVar4->type = rVar5;
        iVar6 = MSG_ReadShort();
        prVar4->nIndex = iVar6;
        iVar6 = MSG_ReadLong();
        prVar4->nDownloadSize = iVar6;
        uVar7 = MSG_ReadByte();
        prVar4->pNext = (resource_s *)0x0;
        prVar4->pPrev = (resource_s *)0x0;
        prVar4->ucFlags = (byte)uVar7 & 0xfd;
        pcVar10 = host_client;
        if ((uVar7 & 4) != 0) {
          MSG_ReadBuf(0x10,prVar4->rgucMD5_hash);
          pcVar10 = host_client;
        }
        host_client = pcVar10;
        if (msg_badread != false) {
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
          prVar4 = (pcVar10->resourcesneeded).pNext;
          prVar11 = &pcVar10->resourcesneeded;
          if ((prVar11 == prVar4) || (prVar4 == (resource_s *)0x0)) goto LAB_000b788c;
          goto LAB_000b7846;
        }
        if ((t_world < prVar4->type) || (0x40000000 < prVar4->nDownloadSize)) {
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
          prVar4 = (pcVar10->resourcesneeded).pNext;
          prVar11 = &pcVar10->resourcesneeded;
          if ((prVar11 == prVar4) || (prVar4 == (resource_s *)0x0)) goto LAB_000b798c;
          goto LAB_000b7946;
        }
        if ((prVar4->pPrev != (resource_s *)0x0) || (prVar4->pNext != (resource_s *)0x0)) break;
        iVar12 = iVar12 + 1;
        prVar4->pPrev = (pcVar10->resourcesneeded).pPrev;
        ((pcVar10->resourcesneeded).pPrev)->pNext = prVar4;
        (pcVar10->resourcesneeded).pPrev = prVar4;
        prVar4->pNext = &pcVar10->resourcesneeded;
        if (iVar12 == iVar3) goto LAB_000b7780;
      }
      iVar12 = iVar12 + 1;
      Con_Printf("Resource already linked\n");
    } while (iVar12 != iVar3);
  }
LAB_000b7780:
  if (sv_allow_upload.value != 0.0) {
    Con_DPrintf("Verifying and uploading resources...\n");
  }
  iVar3 = COM_SizeofResourceList(&host_client->resourcesneeded,&local_3c);
  if ((iVar3 != 0) && (sv_allow_upload.value != 0.0)) {
                    /* Unresolved local var: int bytestodownload@[???] */
    dVar14 = (double)((float)iVar3 * 0.0009765625);
    Con_DPrintf("Custom resources total %.2fK\n",dVar14);
    if (local_3c.info[2].size != 0) {
      dVar14 = (double)local_3c.info[2].size * 0.0009765625;
      Con_DPrintf("  Models:  %.2fK\n",dVar14);
    }
    if (local_3c.info[0].size != 0) {
      dVar14 = (double)((float)local_3c.info[0].size * 0.0009765625);
      Con_DPrintf("  Sounds:  %.2fK\n",dVar14);
    }
    if (local_3c.info[3].size != 0) {
      dVar14 = (double)((float)local_3c.info[3].size * 0.0009765625);
      Con_DPrintf("  Decals:  %.2fK\n",dVar14);
    }
    if (local_3c.info[1].size != 0) {
      dVar14 = (double)((float)local_3c.info[1].size * 0.0009765625);
      Con_DPrintf("  Skins :  %.2fK\n",dVar14);
    }
    if (local_3c.info[4].size != 0) {
      dVar14 = (double)((float)local_3c.info[4].size * 0.0009765625);
      Con_DPrintf("  Generic :  %.2fK\n",dVar14);
    }
    if (local_3c.info[5].size != 0) {
      dVar14 = (double)((float)local_3c.info[5].size * 0.0009765625);
      Con_DPrintf("  Events  :  %.2fK\n",dVar14);
    }
    Con_DPrintf("----------------------\n",dVar14);
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: int missing@[???]
                       Unresolved local var: int size@[???] */
    prVar9 = (host_client->resourcesneeded).pNext;
    prVar4 = &host_client->resourcesneeded;
    pcVar10 = host_client;
    if (prVar9 == prVar4) {
      fVar2 = 0.0;
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      do {
        if (prVar9->type == t_decal) {
          qVar8 = HPAK_ResourceForHash("custom.hpk",prVar9->rgucMD5_hash,(resource_s *)0x0);
          if ((qVar8 == false) && (prVar9->nDownloadSize != 0)) {
            prVar9->ucFlags = prVar9->ucFlags | 2;
            iVar3 = iVar3 + prVar9->nDownloadSize;
          }
          prVar4 = &host_client->resourcesneeded;
          pcVar10 = host_client;
        }
        prVar9 = prVar9->pNext;
      } while (prVar9 != prVar4);
      fVar2 = (float)iVar3;
    }
    if (sv_max_upload.value * 1048576.0 < fVar2) {
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
      prVar9 = (pcVar10->resourcesneeded).pNext;
      local_44 = pcVar10;
      if ((prVar9 != (resource_s *)0x0) && (prVar4 != prVar9)) {
        do {
          prVar1 = prVar9->pNext;
          prVar9->pPrev->pNext = prVar1;
          prVar9->pNext->pPrev = prVar9->pPrev;
          prVar9->pPrev = (resource_s *)0x0;
          prVar9->pNext = (resource_s *)0x0;
          Mem_Free(prVar9);
          if (prVar4 == prVar1) break;
          prVar9 = prVar1;
        } while (prVar1 != (resource_s *)0x0);
        local_44 = host_client;
      }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
      (pcVar10->resourcesneeded).pPrev = prVar4;
      (pcVar10->resourcesneeded).pNext = prVar4;
      prVar11 = &local_44->resourcesonhand;
      prVar4 = (local_44->resourcesonhand).pNext;
      while ((prVar11 != prVar4 && (prVar4 != (resource_s *)0x0))) {
        prVar9 = prVar4->pNext;
        prVar4->pPrev->pNext = prVar9;
        prVar4->pNext->pPrev = prVar4->pPrev;
        prVar4->pPrev = (resource_s *)0x0;
        prVar4->pNext = (resource_s *)0x0;
        Mem_Free(prVar4);
        prVar4 = prVar9;
      }
      (local_44->resourcesonhand).pPrev = prVar11;
      (local_44->resourcesonhand).pNext = prVar11;
      return;
    }
    if (iVar3 < 0x401) {
      Con_DPrintf("Resources to request: %i bytes\n",iVar3);
    }
    else {
      Con_DPrintf("Resources to request: %.2fK\n",(double)(fVar2 * 0.0009765625));
    }
  }
  pcVar10 = host_client;
  host_client->uploading = true;
  pcVar10->uploaddoneregistering = false;
  SV_BatchUploadRequest(pcVar10);
  return;
  while (prVar4 = prVar9, prVar9 != (resource_s *)0x0) {
LAB_000b7846:
    prVar9 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar9;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    if (prVar11 == prVar9) break;
  }
LAB_000b788c:
  pcVar13 = host_client;
  (pcVar10->resourcesneeded).pPrev = prVar11;
  (pcVar10->resourcesneeded).pNext = prVar11;
  prVar4 = &pcVar13->resourcesonhand;
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar9 = (pcVar13->resourcesonhand).pNext;
  if ((prVar9 != (resource_s *)0x0) && (prVar4 != prVar9)) {
    do {
      prVar1 = prVar9->pNext;
      prVar9->pPrev->pNext = prVar1;
      prVar9->pNext->pPrev = prVar9->pPrev;
      prVar9->pPrev = (resource_s *)0x0;
      prVar9->pNext = (resource_s *)0x0;
      Mem_Free(prVar9);
      if (prVar4 == prVar1) break;
      prVar9 = prVar1;
    } while (prVar1 != (resource_s *)0x0);
  }
  goto LAB_000b7900;
  while (prVar4 = prVar9, prVar9 != (resource_s *)0x0) {
LAB_000b7946:
    prVar9 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar9;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    if (prVar11 == prVar9) break;
  }
LAB_000b798c:
  pcVar13 = host_client;
  (pcVar10->resourcesneeded).pPrev = prVar11;
  (pcVar10->resourcesneeded).pNext = prVar11;
  prVar4 = &pcVar13->resourcesonhand;
  prVar9 = (pcVar13->resourcesonhand).pNext;
  while ((prVar4 != prVar9 && (prVar9 != (resource_s *)0x0))) {
    prVar1 = prVar9->pNext;
    prVar9->pPrev->pNext = prVar1;
    prVar9->pNext->pPrev = prVar9->pPrev;
    prVar9->pPrev = (resource_s *)0x0;
    prVar9->pNext = (resource_s *)0x0;
    Mem_Free(prVar9);
    prVar9 = prVar1;
  }
LAB_000b7900:
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  (pcVar13->resourcesonhand).pPrev = prVar4;
  (pcVar13->resourcesonhand).pNext = prVar4;
  return;
}


// SV_ParseStringCommand  @ 000b8660
void SV_ParseStringCommand(client_t *pSenderClient)

{
  char *data;
  command_t s2;
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int ret@[???] */
  data = MSG_ReadString();
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???] */
  COM_Parse(data);
  if (clcommands[0].command != (char *)0x0) {
    iVar2 = 0;
    s2 = clcommands[0];
    do {
      iVar1 = Q_strcasecmp(com_token,s2.command);
      if (iVar1 == 0) {
        Cmd_ExecuteString(data,src_client);
        return;
      }
      iVar2 = iVar2 + 1;
      s2.command = clcommands[iVar2].command;
    } while (s2.command != (char *)0x0);
  }
  iVar2 = Q_strlen(data);
  if (0x7f < iVar2) {
    data[0x7f] = '\0';
  }
  Cmd_TokenizeString(data);
                    /* WARNING: Could not recover jumptable at 0x000b86ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEntityInterface.pfnClientCommand)(sv_player);
  return;
}


// SV_ParseVoiceData  @ 000b7eb0
void SV_ParseVoiceData(client_t *cl)

{
  uint iSize;
  int iVar1;
  client_s *pcVar2;
  sizebuf_t *sb;
  int iVar3;
  uint c;
  bool bVar4;
  undefined1 local_101c [4108];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iClient@[???]
                       Unresolved local var: int nDataLength@[???]
                       Unresolved local var: char[4096] chReceived@[???]
                       Unresolved local var: client_t * pDestClient@[???] */
  iVar3 = (int)cl - (int)svs.clients;
  iSize = MSG_ReadShort();
  if (0x1000 < iSize) {
    Con_DPrintf("SV_ParseVoiceData: invalid incoming packet.\n");
    SV_DropClient(cl,false,"Invalid voice data\n");
    return;
  }
  MSG_ReadBuf(iSize,local_101c);
  cl->m_lastvoicetime = sv.time;
  if (sv_voiceenable.value != 0.0) {
                    /* Unresolved local var: qboolean bLocal@[???]
                       Unresolved local var: int nSendLength@[???] */
    iVar1 = 0;
    do {
      while( true ) {
        pcVar2 = svs.clients + iVar1;
        bVar4 = pcVar2 == cl;
        if (((bVar4) || ((cl->m_VoiceStreams[0] & 1 << ((byte)iVar1 & 0x1f)) != 0)) &&
           ((pcVar2->active != false || (bVar4 || pcVar2->connected != false)))) break;
LAB_000b7f30:
        iVar1 = iVar1 + 1;
        if (iVar1 == 0x20) {
          return;
        }
      }
      c = iSize;
      if ((bVar4) && (c = 0, pcVar2->m_bLoopback != false)) {
        c = iSize;
      }
      if ((pcVar2->datagram).maxsize <= (int)((pcVar2->datagram).cursize + iSize + 6))
      goto LAB_000b7f30;
      sb = &pcVar2->datagram;
      MSG_WriteByte(sb,0x35);
      MSG_WriteByte(sb,(iVar3 >> 3) * -0x6d690de1 & 0xff);
      MSG_WriteShort(sb,c);
      MSG_WriteBuf(sb,c,local_101c);
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x20);
  }
  return;
}


// SV_Physics  @ 000b61f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Physics(void)

{
  vec_t *pvVar1;
  edict_t_conflict *peVar2;
  int iVar3;
  uint uVar4;
  edict_t_conflict *ent;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: edict_t.conflict * groundentity@[???] */
  gGlobalVariables.time = (float)sv.time;
  (*gEntityInterface.pfnStartFrame)();
  if (0 < sv.num_edicts) {
    iVar6 = 0;
    iVar5 = 0;
    iVar3 = sv.num_edicts;
    do {
      ent = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar6 + -0x18);
      if (ent->free == 0) {
        if (gGlobalVariables.force_retouch != 0.0) {
          SV_LinkEdict(ent,true);
        }
        if ((iVar5 == 0) || (iVar3 = sv.num_edicts, svs.maxclients < iVar5)) {
          uVar4 = (ent->v).flags;
          if (((uVar4 & 0x200) != 0) &&
             ((peVar2 = (ent->v).groundentity, peVar2 != (edict_t_conflict *)0x0 &&
              (((peVar2->v).flags & 4) != 0)))) {
            pvVar1 = (ent->v).basevelocity;
            if ((uVar4 & 0x400000) == 0) {
              VectorScale((peVar2->v).movedir,(peVar2->v).speed,pvVar1);
            }
            else {
              VectorMA(pvVar1,(peVar2->v).speed,(peVar2->v).movedir,pvVar1);
            }
            uVar4 = (ent->v).flags | 0x400000;
            (ent->v).flags = uVar4;
          }
          if ((uVar4 & 0x400000) == 0) {
            pvVar1 = (ent->v).velocity;
            VectorMA(pvVar1,(float)host_frametime * 0.5 + 1.0,(ent->v).basevelocity,pvVar1);
            uVar4 = (ent->v).flags;
            (ent->v).basevelocity[0] = vec3_origin[0];
            (ent->v).basevelocity[1] = vec3_origin[1];
            (ent->v).basevelocity[2] = vec3_origin[2];
          }
          (ent->v).flags = uVar4 & 0xffbfffff;
          iVar3 = (ent->v).movetype;
          if (iVar3 == 7) {
            SV_Physics_Pusher(ent);
            uVar4 = (ent->v).flags & 0x40000000;
          }
          else if (iVar3 == 0) {
                    /* Unresolved local var: float thinktime@[???] */
            if ((uVar4 & 0x40000000) == 0) {
              lVar7 = (longdouble)(ent->v).nextthink;
              iVar3 = sv.num_edicts;
              if (((longdouble)0 < lVar7) &&
                 (lVar7 <= (longdouble)host_frametime + (longdouble)sv.time)) {
                if (lVar7 < (longdouble)sv.time) {
                  lVar7 = (longdouble)(float)sv.time;
                }
                (ent->v).nextthink = 0.0;
                gGlobalVariables.time = (float)lVar7;
                (*gEntityInterface.pfnThink)(ent);
                    /* Unresolved local var: float thinktime@[???] */
                iVar3 = sv.num_edicts;
                if (((ent->v).flags & 0x40000000) != 0) goto LAB_000b6500;
              }
              goto LAB_000b6390;
            }
LAB_000b6500:
            ED_Free(ent);
            uVar4 = (ent->v).flags & 0x40000000;
          }
          else if (iVar3 == 0xc) {
            SV_Physics_Follow(ent);
            uVar4 = (ent->v).flags & 0x40000000;
          }
          else if (iVar3 == 8) {
            SV_Physics_Noclip(ent);
            uVar4 = (ent->v).flags & 0x40000000;
          }
          else if ((iVar3 == 4) || (iVar3 == 0xd)) {
            SV_Physics_Step(ent);
            uVar4 = (ent->v).flags & 0x40000000;
          }
          else if ((((iVar3 == 10) || (iVar3 == 6)) || (iVar3 == 0xb)) ||
                  ((iVar3 == 5 || (iVar3 == 9)))) {
            SV_Physics_Toss(ent);
            uVar4 = (ent->v).flags & 0x40000000;
          }
          else {
            Sys_Error("SV_Physics: %s bad movetype %d",pr_strings + (ent->v).classname,iVar3);
            uVar4 = (ent->v).flags & 0x40000000;
          }
          iVar3 = sv.num_edicts;
          if (uVar4 != 0) {
            ED_Free(ent);
            iVar3 = sv.num_edicts;
          }
        }
      }
LAB_000b6390:
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x324;
    } while (iVar5 < iVar3);
  }
  if (gGlobalVariables.force_retouch != 0.0) {
    gGlobalVariables.force_retouch = gGlobalVariables.force_retouch - 1.0;
    return;
  }
  return;
}


// SV_Physics_Follow  @ 000b46b0
void SV_Physics_Follow(edict_t_conflict *ent)

{
  edict_t_conflict *peVar1;
  longdouble lVar2;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar2 = (longdouble)(ent->v).nextthink;
    if ((lVar2 <= (longdouble)0) || ((longdouble)host_frametime + (longdouble)sv.time < lVar2))
    goto LAB_000b4700;
    if (lVar2 < (longdouble)sv.time) {
      lVar2 = (longdouble)(float)sv.time;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar2;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) != 0) goto LAB_000b46c1;
  }
  else {
LAB_000b46c1:
                    /* Unresolved local var: float thinktime@[???] */
    ED_Free(ent);
  }
  if (ent->free != 0) {
    return;
  }
LAB_000b4700:
  peVar1 = (ent->v).aiment;
  if (peVar1 == (edict_t_conflict *)0x0) {
    Con_DPrintf("%s movetype FOLLOW with NULL aiment\n",pr_strings + (ent->v).classname);
    (ent->v).movetype = 0;
    return;
  }
  (ent->v).origin[0] = (peVar1->v).origin[0] + (ent->v).v_angle[0];
  (ent->v).origin[1] = (peVar1->v).origin[1] + (ent->v).v_angle[1];
  (ent->v).origin[2] = (peVar1->v).origin[2] + (ent->v).v_angle[2];
  (ent->v).angles[0] = (peVar1->v).angles[0];
  (ent->v).angles[1] = (peVar1->v).angles[1];
  (ent->v).angles[2] = (peVar1->v).angles[2];
  SV_LinkEdict(ent,true);
  return;
}


// SV_Physics_Noclip  @ 000b4810
void SV_Physics_Noclip(edict_t_conflict *ent)

{
  vec_t *pvVar1;
  longdouble lVar2;
  longdouble lVar3;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar2 = (longdouble)(ent->v).nextthink;
    if ((longdouble)0 < lVar2) {
      lVar3 = (longdouble)host_frametime;
      if ((longdouble)sv.time + lVar3 < lVar2) goto LAB_000b48b6;
      if (lVar2 < (longdouble)sv.time) {
        lVar2 = (longdouble)(float)sv.time;
      }
      (ent->v).nextthink = 0.0;
      gGlobalVariables.time = (float)lVar2;
      (*gEntityInterface.pfnThink)(ent);
      if (((ent->v).flags & 0x40000000) != 0) goto LAB_000b4821;
      goto LAB_000b4829;
    }
  }
  else {
LAB_000b4821:
                    /* Unresolved local var: float thinktime@[???] */
    ED_Free(ent);
LAB_000b4829:
    if (ent->free != 0) {
      return;
    }
  }
  lVar3 = (longdouble)host_frametime;
LAB_000b48b6:
  pvVar1 = (ent->v).angles;
  VectorMA(pvVar1,(float)lVar3,(ent->v).avelocity,pvVar1);
  pvVar1 = (ent->v).origin;
  VectorMA(pvVar1,(float)host_frametime,(ent->v).velocity,pvVar1);
  SV_LinkEdict(ent,false);
  return;
}


// SV_Physics_None  @ 000b4600
void SV_Physics_None(edict_t_conflict *ent)

{
  longdouble lVar1;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar1 = (longdouble)(ent->v).nextthink;
    if (((longdouble)0 < lVar1) && (lVar1 <= (longdouble)host_frametime + (longdouble)sv.time)) {
      if (lVar1 < (longdouble)sv.time) {
        lVar1 = (longdouble)(float)sv.time;
      }
      (ent->v).nextthink = 0.0;
      gGlobalVariables.time = (float)lVar1;
      (*gEntityInterface.pfnThink)(ent);
      if (((ent->v).flags & 0x40000000) != 0) goto LAB_000b4611;
    }
    return;
  }
LAB_000b4611:
                    /* Unresolved local var: float thinktime@[???] */
  ED_Free(ent);
  return;
}


// SV_Physics_Pusher  @ 000b33c0
void SV_Physics_Pusher(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  ushort in_FPUStatusWord;
  ushort uVar6;
  ushort uVar7;
  longdouble lVar8;
  double dVar9;
  
                    /* Unresolved local var: float thinktime@[???]
                       Unresolved local var: float oldltime@[???]
                       Unresolved local var: float movetime@[???]
                       Unresolved local var: int i@[???] */
  fVar1 = (ent->v).ltime;
  fVar2 = (ent->v).nextthink;
  fVar3 = (float)host_frametime;
  uVar6 = in_FPUStatusWord & 0xfdff;
  if (((fVar3 + fVar1 <= fVar2) || (fVar3 = fVar2 - fVar1, 0.0 <= fVar3)) && (fVar3 != 0.0)) {
    if ((((ent->v).avelocity[0] == 0.0) && ((ent->v).avelocity[1] == 0.0)) &&
       ((ent->v).avelocity[2] == 0.0)) {
      SV_PushMove(ent,fVar3);
    }
    else if ((((ent->v).velocity[0] == 0.0) && ((ent->v).velocity[1] == 0.0)) &&
            ((ent->v).velocity[2] == 0.0)) {
      SV_PushRotate(ent,fVar3);
    }
    else {
                    /* Unresolved local var: float savetime@[???] */
      iVar5 = SV_PushRotate(ent,fVar3);
      if (iVar5 != 0) {
        fVar4 = (ent->v).ltime;
        (ent->v).ltime = fVar1;
        SV_PushMove(ent,fVar3);
        uVar6 = uVar6 & 0xfdff;
        if ((ent->v).ltime < fVar4) {
          (ent->v).ltime = fVar4;
        }
      }
    }
  }
  fVar3 = (ent->v).angles[0];
  lVar8 = (longdouble)fVar3;
  uVar7 = uVar6 & 0xfdff;
  if ((lVar8 < (longdouble)-3600.0) || ((longdouble)3600.0 < lVar8)) {
    do {
      lVar8 = lVar8 - (longdouble)(unkint10)(lVar8 / (longdouble)3600.0) * (longdouble)3600.0;
    } while ((uVar6 & 0x400) != 0);
    if (NAN(lVar8)) {
      dVar9 = fmod((double)fVar3,3600.0);
      lVar8 = (longdouble)dVar9;
    }
    (ent->v).angles[0] = (float)lVar8;
  }
  fVar3 = (ent->v).angles[1];
  lVar8 = (longdouble)fVar3;
  uVar6 = uVar7 & 0xfdff;
  if ((lVar8 < (longdouble)-3600.0) || ((longdouble)3600.0 < lVar8)) {
    do {
      lVar8 = lVar8 - (longdouble)(unkint10)(lVar8 / (longdouble)3600.0) * (longdouble)3600.0;
    } while ((uVar7 & 0x400) != 0);
    if (NAN(lVar8)) {
      dVar9 = fmod((double)fVar3,3600.0);
      lVar8 = (longdouble)dVar9;
    }
    (ent->v).angles[1] = (float)lVar8;
  }
  fVar3 = (ent->v).angles[2];
  lVar8 = (longdouble)fVar3;
  if ((lVar8 < (longdouble)-3600.0) || ((longdouble)3600.0 < lVar8)) {
    do {
      lVar8 = lVar8 - (longdouble)(unkint10)(lVar8 / (longdouble)3600.0) * (longdouble)3600.0;
    } while ((uVar6 & 0x400) != 0);
    if (NAN(lVar8)) {
      dVar9 = fmod((double)fVar3,3600.0);
      lVar8 = (longdouble)dVar9;
    }
    (ent->v).angles[2] = (float)lVar8;
  }
  if ((fVar1 < fVar2) && ((((ent->v).flags & 0x200000) != 0 || (fVar2 <= (ent->v).ltime)))) {
    gGlobalVariables.time = (float)sv.time;
    (ent->v).nextthink = 0.0;
                    /* WARNING: Could not recover jumptable at 0x000b3545. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEntityInterface.pfnThink)(ent);
    return;
  }
  return;
}


// SV_Physics_Step  @ 000b55f0
void SV_Physics_Step(edict_t_conflict *ent)

{
  vec_t *pvVar1;
  int *piVar2;
  vec_t *maxs;
  vec_t *mins;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  qboolean qVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  vec_t *normal;
  longdouble lVar15;
  float fVar16;
  float fVar17;
  float local_188;
  int local_184;
  trace_t local_15c;
  float local_110;
  vec_t local_10c [2];
  float local_104;
  vec_t local_100 [13];
  trace_t local_cc;
  trace_t tStack_94;
  float local_5c;
  float local_58;
  float local_54;
  float local_4c;
  float local_48;
  float fStack_44;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: qboolean wasonground@[???]
                       Unresolved local var: qboolean inwater@[???]
                       Unresolved local var: qboolean hitsound@[???]
                       Unresolved local var: float * vel@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float control@[???]
                       Unresolved local var: float friction@[???] */
  PF_WaterMove(ent);
  SV_CheckVelocity(ent);
  uVar13 = (ent->v).flags;
  qVar9 = SV_CheckWater(ent);
  uVar13 = uVar13 & 0x200;
  if ((((ent->v).flags & 0x8000) != 0) && (0 < (ent->v).waterlevel)) {
                    /* Unresolved local var: float waterLevel@[???] */
    fVar16 = SV_Submerged(ent);
    fVar3 = (float)host_frametime;
    iVar10 = (ent->v).skin;
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar17 = (ent->v).gravity;
    fVar4 = 1.0;
    if (fVar17 != 0.0) {
      fVar4 = fVar17;
    }
    local_110 = (ent->v).velocity[2] - fVar4 * sv_gravity.value * fVar3;
    (ent->v).velocity[2] = fVar3 * (ent->v).basevelocity[2] + local_110;
    (ent->v).basevelocity[2] = 0.0;
    SV_CheckVelocity(ent);
    (ent->v).velocity[2] = (ent->v).velocity[2] + (float)iVar10 * fVar16 * fVar3;
  }
  if ((((uVar13 == 0) && (uVar7 = (ent->v).flags, (uVar7 & 1) == 0)) &&
      (((uVar7 & 2) == 0 || ((ent->v).waterlevel < 1)))) && (qVar9 == false)) {
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar17 = (ent->v).gravity;
    fVar3 = 1.0;
    if (fVar17 != 0.0) {
      fVar3 = fVar17;
    }
    local_110 = (ent->v).velocity[2] - (float)host_frametime * fVar3 * sv_gravity.value;
    (ent->v).velocity[2] = (float)host_frametime * (ent->v).basevelocity[2] + local_110;
    (ent->v).basevelocity[2] = 0.0;
    SV_CheckVelocity(ent);
  }
  pvVar1 = (ent->v).velocity;
  iVar10 = VectorCompare(pvVar1,vec_origin);
  if ((iVar10 == 0) || (iVar10 = VectorCompare((ent->v).basevelocity,vec_origin), iVar10 == 0)) {
    piVar2 = &(ent->v).flags;
    *piVar2 = *piVar2 & 0xfffffdff;
    if ((uVar13 == 0) || (((ent->v).health <= 0.0 && (qVar9 = SV_CheckBottom(ent), qVar9 == false)))
       ) {
LAB_000b571b:
      fVar3 = (ent->v).velocity[0];
      fVar17 = (ent->v).velocity[1];
    }
    else {
      fVar17 = (ent->v).velocity[0];
      fVar3 = (ent->v).velocity[1];
      fVar3 = fVar3 * fVar3 + fVar17 * fVar17;
      fVar17 = SQRT(fVar3);
      if (NAN(fVar17)) {
        fVar17 = sqrtf(fVar3);
      }
      if (fVar17 == 0.0) goto LAB_000b571b;
      fVar4 = sv_friction.value * (ent->v).friction;
      (ent->v).friction = 1.0;
      fVar3 = sv_stopspeed.value;
      if (sv_stopspeed.value <= fVar17) {
        fVar3 = fVar17;
      }
      local_110 = fVar17 - fVar3 * (float)host_frametime * fVar4;
      fVar4 = 0.0;
      if (0.0 <= local_110) {
        fVar4 = local_110;
      }
      fVar3 = (ent->v).velocity[0] * (fVar4 / fVar17);
      (ent->v).velocity[0] = fVar3;
      fVar17 = (ent->v).velocity[1] * (fVar4 / fVar17);
      (ent->v).velocity[1] = fVar17;
    }
    (ent->v).velocity[0] = fVar3 + (ent->v).basevelocity[0];
    (ent->v).velocity[1] = fVar17 + (ent->v).basevelocity[1];
    (ent->v).velocity[2] = (ent->v).velocity[2] + (ent->v).basevelocity[2];
    SV_CheckVelocity(ent);
                    /* Unresolved local var: int bumpcount@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: int numplanes@[???]
                       Unresolved local var: vec_t[5][3] planes@[???]
                       Unresolved local var: vec3_t original_velocity@[???]
                       Unresolved local var: vec3_t new_velocity@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: trace_t test@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: float time_left@[???]
                       Unresolved local var: int blocked@[???]
                       Unresolved local var: qboolean monsterClip@[???]
                       Unresolved local var: int numbumps@[???]
                       Unresolved local var: vec3_t primal_velocity@[???] */
    maxs = (ent->v).maxs;
    mins = (ent->v).mins;
    local_188 = (float)host_frametime;
    fVar17 = (ent->v).velocity[0];
    fVar3 = (ent->v).velocity[1];
    qVar9 = (qboolean)(((ent->v).flags & 0x800000) != 0);
    iVar10 = 0;
    fVar4 = (ent->v).velocity[2];
    local_184 = 4;
    fVar16 = fVar17;
    fVar6 = fVar4;
    fVar5 = fVar3;
    local_5c = fVar17;
    local_58 = fVar3;
    local_54 = fVar4;
    while( true ) {
      if (((fVar16 == 0.0) && (fVar5 == 0.0)) && (fVar6 == 0.0)) goto LAB_000b5809;
      local_28 = fVar16 * local_188 + (ent->v).origin[0];
      local_24 = fVar5 * local_188 + (ent->v).origin[1];
      local_20 = fVar6 * local_188 + (ent->v).origin[2];
      SV_Move(&local_15c,(ent->v).origin,mins,maxs,&local_28,0,ent,qVar9);
      uVar13 = 0;
      do {
        *(undefined4 *)((int)local_cc.endpos + (uVar13 - 0x14)) =
             *(undefined4 *)((int)local_15c.endpos + (uVar13 - 0x14));
        uVar13 = uVar13 + 4;
      } while (uVar13 < 0x38);
      if (local_cc.allsolid != false) break;
      iVar14 = iVar10;
      if ((0.0 < local_cc.fraction) &&
         (SV_Move(&tStack_94,local_cc.endpos,mins,maxs,local_cc.endpos,0,ent,qVar9),
         tStack_94.allsolid != true)) {
        (ent->v).origin[0] = local_cc.endpos[0];
        (ent->v).origin[1] = local_cc.endpos[1];
        (ent->v).origin[2] = local_cc.endpos[2];
        local_5c = (ent->v).velocity[0];
        local_58 = (ent->v).velocity[1];
        local_54 = (ent->v).velocity[2];
        iVar14 = 0;
      }
      if (local_cc.fraction == 1.0) goto LAB_000b5809;
      if (local_cc.ent == (edict_t_conflict *)0x0) {
        Sys_Error("SV_FlyMove: !trace.ent");
      }
      if (0.7 < local_cc.plane.normal[2]) {
        iVar10 = ((local_cc.ent)->v).solid;
        if ((iVar10 == 4) || (((local_cc.ent)->v).movetype == 0xd)) {
          uVar13 = (ent->v).flags;
        }
        else {
          uVar13 = (ent->v).flags;
          if ((iVar10 != 3) && ((uVar13 & 8) == 0)) goto LAB_000b5b12;
        }
        (ent->v).flags = uVar13 | 0x200;
        (ent->v).groundentity = local_cc.ent;
      }
LAB_000b5b12:
      SV_Impact(ent,local_cc.ent,&local_cc);
      fVar8 = local_cc.fraction;
      if (ent->free != 0) goto LAB_000b5809;
      if (4 < iVar14) break;
      iVar10 = iVar14 + 1;
      local_10c[iVar14 * 3] = local_cc.plane.normal[0];
      local_10c[iVar14 * 3 + 1] = local_cc.plane.normal[1];
      local_100[iVar14 * 3 + -1] = local_cc.plane.normal[2];
      if (((iVar10 == 1) && ((ent->v).movetype == 3)) &&
         ((((ent->v).flags & 0x200) == 0 || ((ent->v).friction != 1.0)))) {
        if (local_104 <= 0.7) {
          fVar16 = (1.0 - (ent->v).friction) * sv_bounce.value + 1.0;
        }
        else {
          fVar16 = 1.0;
        }
        ClipVelocity(&local_5c,local_10c,&local_4c,fVar16);
        local_5c = local_4c;
        (ent->v).velocity[0] = local_4c;
        local_58 = local_48;
        (ent->v).velocity[1] = local_48;
        local_54 = fStack_44;
        (ent->v).velocity[2] = fStack_44;
        fVar6 = fStack_44;
        fVar16 = local_4c;
        fVar5 = local_48;
      }
      else {
        iVar14 = 0;
        normal = local_10c;
        do {
          ClipVelocity(&local_5c,normal,&local_4c,1.0);
          pfVar11 = local_10c;
          iVar12 = 0;
          do {
            if ((iVar14 != iVar12) &&
               (pfVar11[2] * fStack_44 + pfVar11[1] * local_48 + *pfVar11 * local_4c < 0.0)) break;
            iVar12 = iVar12 + 1;
            pfVar11 = pfVar11 + 3;
          } while (iVar12 < iVar10);
          if (iVar10 == iVar12) break;
          iVar14 = iVar14 + 1;
          normal = normal + 3;
        } while (iVar14 < iVar10);
        if (iVar10 == iVar14) {
          if (iVar10 != 2) goto LAB_000b5809;
          CrossProduct(local_10c,local_100,&local_34);
          VectorScale(&local_34,
                      local_2c * (ent->v).velocity[2] +
                      local_30 * (ent->v).velocity[1] + local_34 * (ent->v).velocity[0],pvVar1);
          fVar16 = (ent->v).velocity[0];
          fVar5 = (ent->v).velocity[1];
          fVar6 = (ent->v).velocity[2];
        }
        else {
          (ent->v).velocity[0] = local_4c;
          (ent->v).velocity[1] = local_48;
          (ent->v).velocity[2] = fStack_44;
          fVar16 = local_4c;
          fVar6 = fStack_44;
          fVar5 = local_48;
        }
        if (fVar4 * fVar6 + fVar3 * fVar5 + fVar17 * fVar16 <= 0.0) break;
      }
      local_184 = local_184 + -1;
      if (local_184 == 0) goto LAB_000b5809;
      local_188 = local_188 - local_188 * fVar8;
    }
    (ent->v).velocity[0] = vec3_origin[0];
    (ent->v).velocity[1] = vec3_origin[1];
    (ent->v).velocity[2] = vec3_origin[2];
LAB_000b5809:
    SV_CheckVelocity(ent);
    (ent->v).velocity[0] = (ent->v).velocity[0] - (ent->v).basevelocity[0];
    (ent->v).velocity[1] = (ent->v).velocity[1] - (ent->v).basevelocity[1];
    (ent->v).velocity[2] = (ent->v).velocity[2] - (ent->v).basevelocity[2];
    SV_CheckVelocity(ent);
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    g_groupmask = (ent->v).groupinfo;
    fVar17 = (ent->v).origin[0];
    fVar4 = (ent->v).mins[0] + fVar17;
    fVar3 = (ent->v).origin[1];
    fVar16 = (ent->v).mins[1] + fVar3;
    fVar17 = fVar17 + (ent->v).maxs[0];
    fVar3 = fVar3 + (ent->v).maxs[1];
    local_2c = ((ent->v).origin[2] + (ent->v).mins[2]) - 1.0;
    local_34 = fVar4;
    local_30 = fVar16;
    iVar10 = SV_PointContents(&local_34);
    if (iVar10 == -2) {
LAB_000b61c3:
      piVar2 = &(ent->v).flags;
      *piVar2 = *piVar2 | 0x200;
    }
    else {
      g_groupmask = (ent->v).groupinfo;
      local_34 = fVar4;
      local_30 = fVar3;
      iVar10 = SV_PointContents(&local_34);
      if (iVar10 == -2) goto LAB_000b61c3;
    }
    g_groupmask = (ent->v).groupinfo;
    local_34 = fVar17;
    local_30 = fVar16;
    iVar10 = SV_PointContents(&local_34);
    if (iVar10 == -2) {
LAB_000b61b2:
      piVar2 = &(ent->v).flags;
      *piVar2 = *piVar2 | 0x200;
    }
    else {
      g_groupmask = (ent->v).groupinfo;
      local_34 = fVar17;
      local_30 = fVar3;
      iVar10 = SV_PointContents(&local_34);
      if (iVar10 == -2) goto LAB_000b61b2;
    }
    SV_LinkEdict(ent,true);
  }
  else if (gGlobalVariables.force_retouch != 0.0) {
                    /* Unresolved local var: trace_t trace@[???] */
    pvVar1 = (ent->v).origin;
    SV_Move(&local_cc,pvVar1,(ent->v).mins,(ent->v).maxs,pvVar1,0,ent,
            (uint)(((ent->v).flags & 0x800000) != 0));
    if (((local_cc.fraction < 1.0) || (local_cc.startsolid != false)) &&
       (local_cc.ent != (edict_t_conflict *)0x0)) {
      SV_Impact(ent,local_cc.ent,&local_cc);
    }
  }
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar15 = (longdouble)(ent->v).nextthink;
    if ((lVar15 <= (longdouble)0) || ((longdouble)host_frametime + (longdouble)sv.time < lVar15))
    goto LAB_000b59b2;
    if (lVar15 < (longdouble)sv.time) {
      local_110 = (float)sv.time;
      lVar15 = (longdouble)local_110;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar15;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) == 0) goto LAB_000b59b2;
  }
                    /* Unresolved local var: float thinktime@[???] */
  ED_Free(ent);
LAB_000b59b2:
  SV_CheckWaterTransition(ent);
  return;
}


// SV_Physics_Toss  @ 000b4b30
void SV_Physics_Toss(edict_t_conflict *ent)

{
  vec_t *v1;
  vec_t *veca;
  int *piVar1;
  float fVar2;
  edict_t_conflict *peVar3;
  float fVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  uint uVar8;
  int iVar9;
  longdouble lVar10;
  trace_t local_bc;
  float local_70;
  int aiStack_6c [4];
  float fStack_5c;
  vec_t avStack_4c [2];
  float fStack_44;
  edict_t_conflict *peStack_3c;
  float local_2c;
  float local_28;
  float fStack_24;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: float backoff@[???] */
  SV_CheckWater(ent);
                    /* Unresolved local var: float thinktime@[???] */
  uVar8 = (ent->v).flags;
  if ((uVar8 & 0x40000000) == 0) {
    lVar10 = (longdouble)(ent->v).nextthink;
    if ((lVar10 <= (longdouble)0) || ((longdouble)host_frametime + (longdouble)sv.time < lVar10))
    goto LAB_000b4c00;
    if (lVar10 < (longdouble)sv.time) {
      local_70 = (float)sv.time;
      lVar10 = (longdouble)local_70;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar10;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) != 0) goto LAB_000b4b56;
    iVar9 = ent->free;
  }
  else {
LAB_000b4b56:
                    /* Unresolved local var: float thinktime@[???] */
    ED_Free(ent);
    iVar9 = ent->free;
  }
  if (iVar9 != 0) {
    return;
  }
  uVar8 = (ent->v).flags;
LAB_000b4c00:
  if (((0.0 < (ent->v).velocity[2]) ||
      (peVar3 = (ent->v).groundentity, peVar3 == (edict_t_conflict *)0x0)) ||
     (((peVar3->v).flags & 0x28) != 0)) {
    uVar8 = uVar8 & 0xfffffdff;
    (ent->v).flags = uVar8;
  }
  v1 = (ent->v).velocity;
  if (((uVar8 & 0x200) != 0) && (iVar9 = VectorCompare(v1,vec_origin), iVar9 != 0)) {
    (ent->v).avelocity[0] = vec3_origin[0];
    (ent->v).avelocity[1] = vec3_origin[1];
    (ent->v).avelocity[2] = vec3_origin[2];
    iVar9 = VectorCompare((ent->v).basevelocity,vec_origin);
    if (iVar9 != 0) {
      return;
    }
  }
  SV_CheckVelocity(ent);
  iVar9 = (ent->v).movetype;
  if (((iVar9 != 0xb) && (iVar9 != 5)) && (iVar9 != 9)) {
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar2 = (ent->v).gravity;
    fVar4 = 1.0;
    if (fVar2 != 0.0) {
      fVar4 = fVar2;
    }
    local_70 = (ent->v).velocity[2] - fVar4 * sv_gravity.value * (float)host_frametime;
    (ent->v).velocity[2] = (float)host_frametime * (ent->v).basevelocity[2] + local_70;
    (ent->v).basevelocity[2] = 0.0;
    SV_CheckVelocity(ent);
  }
  veca = (ent->v).angles;
  VectorMA(veca,(float)host_frametime,(ent->v).avelocity,veca);
  (ent->v).velocity[0] = (ent->v).velocity[0] + (ent->v).basevelocity[0];
  (ent->v).velocity[1] = (ent->v).velocity[1] + (ent->v).basevelocity[1];
  (ent->v).velocity[2] = (ent->v).velocity[2] + (ent->v).basevelocity[2];
  SV_CheckVelocity(ent);
  VectorScale(v1,(float)host_frametime,&local_2c);
  (ent->v).velocity[0] = (ent->v).velocity[0] - (ent->v).basevelocity[0];
  (ent->v).velocity[1] = (ent->v).velocity[1] - (ent->v).basevelocity[1];
  (ent->v).velocity[2] = (ent->v).velocity[2] - (ent->v).basevelocity[2];
  SV_PushEntity(&local_bc,ent,&local_2c);
  uVar8 = 0;
  do {
    *(undefined4 *)((int)aiStack_6c + uVar8) =
         *(undefined4 *)((int)local_bc.endpos + (uVar8 - 0x14));
    uVar8 = uVar8 + 4;
  } while (uVar8 < 0x38);
  SV_CheckVelocity(ent);
  vVar7 = vec3_origin[2];
  vVar6 = vec3_origin[1];
  vVar5 = vec3_origin[0];
  if (aiStack_6c[0] == 0) {
    if (fStack_5c != 1.0) {
      if (ent->free != 0) {
        return;
      }
      iVar9 = (ent->v).movetype;
      if (iVar9 == 10) {
        fVar2 = 2.0 - (ent->v).friction;
      }
      else {
        fVar2 = 2.0;
        if (iVar9 != 0xb) {
          fVar2 = 1.0;
        }
      }
      ClipVelocity(v1,avStack_4c,v1,fVar2);
      if (0.7 < fStack_44) {
                    /* Unresolved local var: float vel@[???] */
        local_2c = (ent->v).velocity[0] + (ent->v).basevelocity[0];
        local_28 = (ent->v).velocity[1] + (ent->v).basevelocity[1];
        fStack_24 = (ent->v).velocity[2] + (ent->v).basevelocity[2];
        fVar2 = (float)host_frametime;
        if (fStack_24 < fVar2 * sv_gravity.value) {
          piVar1 = &(ent->v).flags;
          *piVar1 = *piVar1 | 0x200;
          (ent->v).velocity[2] = 0.0;
          (ent->v).groundentity = peStack_3c;
        }
        vVar6 = vec3_origin[1];
        vVar5 = vec3_origin[0];
        if ((fStack_24 * fStack_24 + local_28 * local_28 + local_2c * local_2c < 900.0) ||
           (1 < (ent->v).movetype - 10U)) {
          piVar1 = &(ent->v).flags;
          *piVar1 = *piVar1 | 0x200;
          (ent->v).groundentity = peStack_3c;
          vVar7 = vec3_origin[2];
          (ent->v).velocity[0] = vVar5;
          (ent->v).velocity[1] = vVar6;
          (ent->v).avelocity[0] = vVar5;
          (ent->v).velocity[2] = vVar7;
          (ent->v).avelocity[1] = vVar6;
          (ent->v).avelocity[2] = vVar7;
        }
        else {
          VectorScale(v1,(1.0 - fStack_5c) * fVar2 * 0.9,&local_2c);
          VectorMA(&local_2c,(1.0 - fStack_5c) * (float)host_frametime * 0.9,(ent->v).basevelocity,
                   &local_2c);
          SV_PushEntity(&local_bc,ent,&local_2c);
          uVar8 = 0;
          do {
            *(undefined4 *)((int)aiStack_6c + uVar8) =
                 *(undefined4 *)((int)local_bc.endpos + (uVar8 - 0x14));
            uVar8 = uVar8 + 4;
          } while (uVar8 < 0x38);
        }
      }
    }
    SV_CheckWaterTransition(ent);
    return;
  }
  (ent->v).velocity[0] = vec3_origin[0];
  (ent->v).velocity[1] = vVar6;
  (ent->v).velocity[2] = vVar7;
  (ent->v).avelocity[0] = vVar5;
  (ent->v).avelocity[1] = vVar6;
  (ent->v).avelocity[2] = vVar7;
  return;
}


// SV_PlayerRunPreThink  @ 000b94f0
void SV_PlayerRunPreThink(edict_t_conflict *player,float time)

{
  gGlobalVariables.time = time;
                    /* WARNING: Could not recover jumptable at 0x000b94fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEntityInterface.pfnPlayerPreThink)(player);
  return;
}


// SV_PlayerRunThink  @ 000b9500
qboolean SV_PlayerRunThink(edict_t_conflict *ent,float frametime,double clienttimebase)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  
                    /* Unresolved local var: float thinktime@[???] */
  fVar3 = (float)clienttimebase;
  uVar2 = (ent->v).flags;
  if ((uVar2 & 0x40000000) == 0) {
    if ((int)uVar2 < 0) goto LAB_000b952a;
    fVar1 = (ent->v).nextthink;
    if (fVar1 <= 0.0) {
      return true;
    }
    if (fVar3 + frametime < fVar1) {
      return true;
    }
    if (fVar1 < fVar3) {
      fVar1 = fVar3;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = fVar1;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) == 0) goto LAB_000b952a;
  }
  ED_Free(ent);
LAB_000b952a:
  return (uint)(ent->free == 0);
}


// SV_PointContents  @ 000bfef0
int SV_PointContents(vec_t *p)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int cont@[???]
                       Unresolved local var: int entityContents@[???] */
  iVar1 = SV_HullPointContents((sv.worldmodel)->hulls,0,p);
  if (iVar1 + 0xeU < 6) {
    iVar1 = -3;
  }
  else if (iVar1 == -2) {
    return -2;
  }
  iVar2 = SV_LinkContents(sv_areanodes,p);
  if (iVar2 == -1) {
    iVar2 = iVar1;
  }
  return iVar2;
}


// SV_PointLeafnum  @ 000a4230
int SV_PointLeafnum(vec_t *p)

{
  mleaf_t *pmVar1;
  int iVar2;
  
                    /* Unresolved local var: mleaf_t * pLeaf@[???] */
  pmVar1 = Mod_PointInLeaf(p,sv.worldmodel);
  iVar2 = 0;
  if (pmVar1 != (mleaf_t *)0x0) {
    iVar2 = ((int)pmVar1 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555;
  }
  return iVar2;
}


// SV_PreRunCmd  @ 000b8ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_PreRunCmd(void)

{
  return;
}


// SV_ProcessFile  @ 000a2be0
void SV_ProcessFile(client_t *cl,char *filename)

{
  resource_s *prVar1;
  customization_s *pcVar2;
  resource_s *pResource;
  int iVar3;
  qboolean qVar4;
  uchar local_2c [28];
  
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: resource_t * resource@[???]
                       Unresolved local var: resource_t * next@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: qboolean bFound@[???]
                       Unresolved local var: qboolean bNoError@[???] */
  if (*filename == '!') {
    COM_HexConvert(filename + 4,0x20,local_2c);
    prVar1 = (cl->resourcesneeded).pNext;
    do {
      pResource = prVar1;
      if (pResource == &cl->resourcesneeded) {
        Con_Printf("SV_ProcessFile:  Unrequested decal\n");
        return;
      }
      prVar1 = pResource->pNext;
      iVar3 = Q_memcmp(pResource->rgucMD5_hash,local_2c,0x10);
    } while (iVar3 != 0);
    iVar3 = (cl->netchan).tempbuffersize;
    if (pResource->nDownloadSize == iVar3) {
      HPAK_AddLump(true,"custom.hpk",pResource,(cl->netchan).tempbuffer,(FileHandle_t)0x0);
      pResource->ucFlags = pResource->ucFlags & 0xfd;
      SV_MoveToOnHandList(pResource);
      for (pcVar2 = (cl->customdata).pNext; pcVar2 != (customization_s *)0x0; pcVar2 = pcVar2->pNext
          ) {
        iVar3 = Q_memcmp((pcVar2->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10);
        if (iVar3 == 0) {
          Con_DPrintf("Duplicate resource received and ignored.\n");
          return;
        }
      }
      qVar4 = COM_CreateCustomization
                        (&cl->customdata,pResource,-1,7,(customization_t **)0x0,(int *)0x0);
      if (qVar4 == false) {
        Con_Printf("Error parsing custom decal from %s\n",cl->name);
      }
    }
    else {
      Con_Printf("SV_ProcessFile:  Downloaded %i bytes for purported %i byte file\n",iVar3,
                 pResource->nDownloadSize);
    }
  }
  else {
    Con_Printf("Ignoring non-customization file upload of %s\n",filename);
  }
  return;
}


// SV_PropagateCustomizations  @ 000a6eb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_PropagateCustomizations(void)

{
  sizebuf_t *sb;
  client_t *pcVar1;
  int iVar2;
  customization_s *pcVar3;
  int c;
  
                    /* Unresolved local var: client_t * pHost@[???]
                       Unresolved local var: customization_t * pCust@[???]
                       Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: int i@[???] */
  pcVar1 = host_client;
  if (0 < svs.maxclients) {
    c = 0;
    sb = &(host_client->netchan).message;
    host_client = svs.clients;
    iVar2 = svs.maxclients;
    do {
      if (((host_client->active != false) || (host_client->spawned != false)) &&
         (host_client->fakeclient == false)) {
        pcVar3 = (host_client->customdata).pNext;
joined_r0x000a6f07:
        if (pcVar3 != (customization_s *)0x0) {
          do {
            if (pcVar3->bInUse != false) {
              MSG_WriteByte(sb,0x2e);
              MSG_WriteByte(sb,c);
              MSG_WriteByte(sb,(pcVar3->resource).type);
              MSG_WriteString(sb,(pcVar3->resource).szFileName);
              MSG_WriteShort(sb,(pcVar3->resource).nIndex);
              MSG_WriteLong(sb,(pcVar3->resource).nDownloadSize);
              MSG_WriteByte(sb,(uint)(pcVar3->resource).ucFlags);
              if (((pcVar3->resource).ucFlags & 4) != 0) goto code_r0x000a6f97;
            }
            pcVar3 = pcVar3->pNext;
            iVar2 = svs.maxclients;
            if (pcVar3 == (customization_s *)0x0) break;
          } while( true );
        }
      }
      c = c + 1;
      host_client = host_client + 1;
    } while (c < iVar2);
  }
  host_client = pcVar1;
  return;
code_r0x000a6f97:
  SZ_Write(sb,(pcVar3->resource).rgucMD5_hash,0x10);
  pcVar3 = pcVar3->pNext;
  iVar2 = svs.maxclients;
  goto joined_r0x000a6f07;
}


// SV_PushEntity  @ 000b2690
trace_t * SV_PushEntity(trace_t *__return_storage_ptr__,edict_t_conflict *ent,vec_t *push)

{
  uint uVar1;
  trace_t local_9c;
  trace_t tStack_5c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: qboolean monsterClip@[???]
                       Unresolved local var: int moveType@[???] */
  local_18 = (ent->v).origin[0] + *push;
  local_14 = (ent->v).origin[1] + push[1];
  local_10 = (ent->v).origin[2] + push[2];
  uVar1 = 2;
  if ((ent->v).movetype != 9) {
    uVar1 = (uint)((uint)(ent->v).solid < 2);
  }
  SV_Move(&local_9c,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_18,uVar1,ent,
          (uint)(((ent->v).flags & 0x800000) != 0));
  uVar1 = 0;
  do {
    *(undefined4 *)((int)tStack_5c.endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_9c.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  if (tStack_5c.fraction != 0.0) {
    (ent->v).origin[0] = tStack_5c.endpos[0];
    (ent->v).origin[1] = tStack_5c.endpos[1];
    (ent->v).origin[2] = tStack_5c.endpos[2];
  }
  SV_LinkEdict(ent,true);
  if (tStack_5c.ent != (edict_t_conflict *)0x0) {
    SV_Impact(ent,tStack_5c.ent,&tStack_5c);
  }
  uVar1 = 0;
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)tStack_5c.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  return __return_storage_ptr__;
}


// SV_PushMove  @ 000b27e0
void SV_PushMove(edict_t_conflict *pusher,float movetime)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec3_t *pavVar8;
  int iVar9;
  edict_t_conflict *peVar10;
  edict_t_conflict **ppeVar11;
  int iVar12;
  vec_t *pvVar13;
  edict_t_conflict *ent;
  int iVar14;
  int iVar15;
  int local_b0;
  trace_t local_8c;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: edict_t.conflict * check@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t entorig@[???]
                       Unresolved local var: vec3_t pushorig@[???]
                       Unresolved local var: int num_moved@[???] */
  local_2c = (pusher->v).velocity[0];
  if (((local_2c == 0.0) && ((pusher->v).velocity[1] == 0.0)) && ((pusher->v).velocity[2] == 0.0)) {
    (pusher->v).ltime = movetime + (pusher->v).ltime;
    return;
  }
  fVar2 = (pusher->v).origin[0];
  fVar3 = (pusher->v).origin[1];
  fVar4 = (pusher->v).origin[2];
  local_2c = local_2c * movetime;
  local_4c = (pusher->v).absmin[0] + local_2c;
  local_3c = (pusher->v).absmax[0] + local_2c;
  (pusher->v).origin[0] = local_2c + fVar2;
  local_28 = movetime * (pusher->v).velocity[1];
  local_48 = (pusher->v).absmin[1] + local_28;
  local_38 = (pusher->v).absmax[1] + local_28;
  (pusher->v).origin[1] = local_28 + fVar3;
  local_24 = movetime * (pusher->v).velocity[2];
  local_44 = (pusher->v).absmin[2] + local_24;
  local_34 = (pusher->v).absmax[2] + local_24;
  (pusher->v).origin[2] = local_24 + fVar4;
  (pusher->v).ltime = movetime + (pusher->v).ltime;
  SV_LinkEdict(pusher,false);
  if (((pusher->v).solid != 0) && (1 < sv.num_edicts)) {
    iVar15 = 1;
    local_b0 = 0;
    iVar14 = 0x324;
    iVar9 = sv.num_edicts;
    do {
      ent = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar14 + -0x18);
      if (((ent->free == 0) && (iVar12 = (ent->v).movetype, iVar12 != 0)) &&
         ((iVar12 != 7 && ((iVar12 != 0xc && (iVar12 != 8)))))) {
        if ((((ent->v).flags & 0x200) == 0) || ((ent->v).groundentity != pusher)) {
          if (((((local_3c <= (ent->v).absmin[0]) || (local_38 <= (ent->v).absmin[1])) ||
               (local_34 <= (ent->v).absmin[2])) ||
              (((ent->v).absmax[0] <= local_4c || ((ent->v).absmax[1] <= local_48)))) ||
             (((ent->v).absmax[2] <= local_44 ||
              (peVar10 = SV_TestEntityPosition(ent), iVar9 = sv.num_edicts,
              peVar10 == (edict_t_conflict *)0x0)))) goto LAB_000b29b0;
          iVar12 = (ent->v).movetype;
        }
        if (iVar12 != 3) {
          piVar1 = &(ent->v).flags;
          *piVar1 = *piVar1 & 0xfffffdff;
        }
        vVar5 = (ent->v).origin[1];
        vVar6 = (ent->v).origin[0];
        vVar7 = (ent->v).origin[2];
        g_moved_from[local_b0][0] = vVar6;
        pavVar8 = g_moved_from;
        g_moved_from[local_b0][1] = (ent->v).origin[1];
        pavVar8[local_b0][2] = (ent->v).origin[2];
        g_moved_edict[local_b0] = ent;
        local_b0 = local_b0 + 1;
        (pusher->v).solid = 0;
        SV_PushEntity(&local_8c,ent,&local_2c);
        (pusher->v).solid = 4;
        peVar10 = SV_TestEntityPosition(ent);
        iVar9 = sv.num_edicts;
        if ((peVar10 != (edict_t_conflict *)0x0) && ((ent->v).mins[0] != (ent->v).maxs[0])) {
          if (1 < (uint)(ent->v).solid) {
            (ent->v).origin[0] = vVar6;
            (ent->v).origin[1] = vVar5;
            (ent->v).origin[2] = vVar7;
            SV_LinkEdict(ent,true);
            (pusher->v).origin[0] = fVar2;
            (pusher->v).origin[1] = fVar3;
            (pusher->v).origin[2] = fVar4;
            SV_LinkEdict(pusher,false);
            (pusher->v).ltime = (pusher->v).ltime - movetime;
            (*gEntityInterface.pfnBlocked)(pusher,ent);
            iVar14 = 0;
            iVar9 = 0;
            do {
              iVar15 = iVar9 + 1;
              ppeVar11 = g_moved_edict + iVar9;
              pvVar13 = (vec_t *)((int)*g_moved_from + iVar14);
              iVar14 = iVar14 + 0xc;
              ((*ppeVar11)->v).origin[0] = *pvVar13;
              ((*ppeVar11)->v).origin[1] = pvVar13[1];
              ((*ppeVar11)->v).origin[2] = pvVar13[2];
              SV_LinkEdict(*ppeVar11,false);
              iVar9 = iVar15;
            } while (iVar15 < local_b0);
            return;
          }
          vVar5 = (ent->v).mins[2];
          (ent->v).mins[1] = 0.0;
          (ent->v).mins[0] = 0.0;
          (ent->v).maxs[0] = 0.0;
          (ent->v).maxs[1] = 0.0;
          (ent->v).maxs[2] = vVar5;
          iVar9 = sv.num_edicts;
        }
      }
LAB_000b29b0:
      iVar15 = iVar15 + 1;
      iVar14 = iVar14 + 0x324;
    } while (iVar15 < iVar9);
  }
  return;
}


// SV_PushRotate  @ 000b2cb0
int SV_PushRotate(edict_t_conflict *pusher,float movetime)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  vec_t vVar8;
  vec_t vVar9;
  vec_t vVar10;
  float fVar11;
  vec3_t *pavVar12;
  edict_t_conflict *peVar13;
  int iVar14;
  edict_t_conflict **ppeVar15;
  edict_t_conflict *peVar16;
  vec_t *pvVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int local_100;
  float local_cc;
  trace_t local_bc;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: edict_t.conflict * check@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t amove@[???]
                       Unresolved local var: vec3_t entorig@[???]
                       Unresolved local var: vec3_t pushorig@[???]
                       Unresolved local var: int num_moved@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t forwardNow@[???]
                       Unresolved local var: vec3_t rightNow@[???]
                       Unresolved local var: vec3_t upNow@[???] */
  fVar2 = (pusher->v).avelocity[0];
  fVar3 = (pusher->v).avelocity[1];
  if ((fVar2 == 0.0) && (fVar3 == 0.0)) {
    fVar4 = (pusher->v).avelocity[2];
    if (fVar4 == 0.0) {
      (pusher->v).ltime = movetime + (pusher->v).ltime;
      return 1;
    }
  }
  else {
    fVar4 = (pusher->v).avelocity[2];
  }
  pvVar17 = (pusher->v).angles;
  fVar3 = fVar3 * movetime;
  AngleVectors(pvVar17,&local_40,&local_34,&local_28);
  fVar5 = (pusher->v).angles[0];
  fVar6 = (pusher->v).angles[1];
  fVar7 = (pusher->v).angles[2];
  (pusher->v).angles[0] = fVar2 * movetime + fVar5;
  (pusher->v).angles[1] = fVar6 + fVar3;
  (pusher->v).angles[2] = fVar4 * movetime + fVar7;
  AngleVectorsTranspose(pvVar17,&local_64,&local_58,&local_4c);
  (pusher->v).ltime = movetime + (pusher->v).ltime;
  SV_LinkEdict(pusher,false);
  if (((pusher->v).solid != 0) && (1 < sv.num_edicts)) {
    iVar20 = 1;
    local_100 = 0;
    iVar19 = 0x324;
    iVar18 = sv.num_edicts;
    do {
      peVar16 = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar19 + -0x18);
      if ((((peVar16->free == 0) && (iVar14 = (peVar16->v).movetype, iVar14 != 0)) && (iVar14 != 7))
         && ((iVar14 != 0xc && (iVar14 != 8)))) {
        if ((((peVar16->v).flags & 0x200) == 0) || ((peVar16->v).groundentity != pusher)) {
          if (((((pusher->v).absmax[0] <= (peVar16->v).absmin[0]) ||
               ((pusher->v).absmax[1] <= (peVar16->v).absmin[1])) ||
              ((pusher->v).absmax[2] <= (peVar16->v).absmin[2])) ||
             (((((peVar16->v).absmax[0] <= (pusher->v).absmin[0] ||
                ((peVar16->v).absmax[1] <= (pusher->v).absmin[1])) ||
               ((peVar16->v).absmax[2] <= (pusher->v).absmin[2])) ||
              (peVar13 = SV_TestEntityPosition(peVar16), iVar18 = sv.num_edicts,
              peVar13 == (edict_t_conflict *)0x0)))) goto LAB_000b2ea0;
          iVar14 = (peVar16->v).movetype;
        }
        if (iVar14 != 3) {
          piVar1 = &(peVar16->v).flags;
          *piVar1 = *piVar1 & 0xfffffdff;
        }
        vVar8 = (peVar16->v).origin[1];
        vVar9 = (peVar16->v).origin[0];
        vVar10 = (peVar16->v).origin[2];
        g_moved_from[local_100][0] = vVar9;
        pavVar12 = g_moved_from;
        g_moved_from[local_100][1] = (peVar16->v).origin[1];
        pavVar12[local_100][2] = (peVar16->v).origin[2];
        g_moved_edict[local_100] = peVar16;
        local_100 = local_100 + 1;
        if (sv.max_edicts <= local_100) {
          Sys_Error("Out of edicts in simulator!\n");
        }
        if ((peVar16->v).movetype == 0xd) {
          local_70 = ((peVar16->v).absmin[0] + (peVar16->v).absmax[0]) * 0.5 - (pusher->v).origin[0]
          ;
          local_6c = ((peVar16->v).absmin[1] + (peVar16->v).absmax[1]) * 0.5 - (pusher->v).origin[1]
          ;
          local_cc = ((peVar16->v).absmin[2] + (peVar16->v).absmax[2]) * 0.5 - (pusher->v).origin[2]
          ;
        }
        else {
          local_70 = (peVar16->v).origin[0] - (pusher->v).origin[0];
          local_6c = (peVar16->v).origin[1] - (pusher->v).origin[1];
          local_cc = (peVar16->v).origin[2] - (pusher->v).origin[2];
        }
        (pusher->v).solid = 0;
        fVar11 = local_cc * local_38 + local_3c * local_6c + local_40 * local_70;
        fVar4 = -(local_cc * local_2c + local_30 * local_6c + local_34 * local_70);
        fVar2 = local_cc * local_20 + local_24 * local_6c + local_28 * local_70;
        local_70 = (fVar2 * local_5c + fVar4 * local_60 + fVar11 * local_64) - local_70;
        local_6c = (local_50 * fVar2 + local_54 * fVar4 + local_58 * fVar11) - local_6c;
        local_68 = (local_44 * fVar2 + local_48 * fVar4 + local_4c * fVar11) - local_cc;
        SV_PushEntity(&local_bc,peVar16,&local_70);
        (pusher->v).solid = 4;
        if ((peVar16->v).movetype != 0xd) {
          if (((peVar16->v).flags & 8) == 0) {
            (peVar16->v).angles[0] = (peVar16->v).angles[0] + 0.0;
            (peVar16->v).angles[1] = fVar3 + (peVar16->v).angles[1];
            (peVar16->v).angles[2] = (peVar16->v).angles[2] + 0.0;
          }
          else {
            fVar2 = (peVar16->v).avelocity[1];
            (peVar16->v).fixangle = 2;
            (peVar16->v).avelocity[1] = fVar3 + fVar2;
          }
        }
        peVar13 = SV_TestEntityPosition(peVar16);
        iVar18 = sv.num_edicts;
        if ((peVar13 != (edict_t_conflict *)0x0) && ((peVar16->v).mins[0] != (peVar16->v).maxs[0]))
        {
          if (1 < (uint)(peVar16->v).solid) {
            (peVar16->v).origin[0] = vVar9;
            (peVar16->v).origin[1] = vVar8;
            (peVar16->v).origin[2] = vVar10;
            SV_LinkEdict(peVar16,true);
            (pusher->v).angles[0] = fVar5;
            (pusher->v).angles[1] = fVar6;
            (pusher->v).angles[2] = fVar7;
            iVar19 = 0;
            SV_LinkEdict(pusher,false);
            (pusher->v).ltime = (pusher->v).ltime - movetime;
            iVar18 = 0;
            (*gEntityInterface.pfnBlocked)(pusher,peVar16);
            do {
              ppeVar15 = g_moved_edict + iVar18;
              pvVar17 = (vec_t *)((int)*g_moved_from + iVar19);
              ((*ppeVar15)->v).origin[0] = *pvVar17;
              ((*ppeVar15)->v).origin[1] = pvVar17[1];
              ((*ppeVar15)->v).origin[2] = pvVar17[2];
              peVar16 = *ppeVar15;
              if (((peVar16->v).flags & 8) == 0) {
                if ((peVar16->v).movetype != 0xd) {
                  (peVar16->v).angles[1] = (peVar16->v).angles[1] - fVar3;
                  peVar16 = *ppeVar15;
                }
              }
              else {
                (peVar16->v).avelocity[1] = 0.0;
                peVar16 = *ppeVar15;
              }
              iVar18 = iVar18 + 1;
              iVar19 = iVar19 + 0xc;
              SV_LinkEdict(peVar16,false);
            } while (iVar18 < local_100);
            return 0;
          }
          vVar8 = (peVar16->v).mins[2];
          (peVar16->v).mins[1] = 0.0;
          (peVar16->v).mins[0] = 0.0;
          (peVar16->v).maxs[0] = 0.0;
          (peVar16->v).maxs[1] = 0.0;
          (peVar16->v).maxs[2] = vVar8;
          iVar18 = sv.num_edicts;
        }
      }
LAB_000b2ea0:
      iVar20 = iVar20 + 1;
      iVar19 = iVar19 + 0x324;
    } while (iVar20 < iVar18);
  }
  return 1;
}


// SV_QueryMovevarsChanged  @ 0009def0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_QueryMovevarsChanged(void)

{
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (((((((((sv_maxspeed.value != movevars.maxspeed) || (sv_gravity.value != movevars.gravity)) ||
           (sv_stopspeed.value != movevars.stopspeed)) ||
          (((sv_spectatormaxspeed.value != movevars.spectatormaxspeed ||
            (sv_accelerate.value != movevars.accelerate)) ||
           ((sv_airaccelerate.value != movevars.airaccelerate ||
            ((sv_wateraccelerate.value != movevars.wateraccelerate ||
             (sv_friction.value != movevars.friction)))))))) ||
         (sv_edgefriction.value != movevars.edgefriction)) ||
        (((sv_waterfriction.value != movevars.waterfriction || (movevars.entgravity != 1.0)) ||
         (sv_bounce.value != movevars.bounce)))) ||
       (((sv_stepsize.value != movevars.stepsize || (sv_maxvelocity.value != movevars.maxvelocity))
        || ((sv_zmax.value != movevars.zmax ||
            ((sv_wateramp.value != movevars.waveHeight ||
             (sv_footsteps.value != (float)movevars.footsteps)))))))) ||
      ((sv_rollangle.value != movevars.rollangle ||
       (((((sv_rollspeed.value != movevars.rollspeed || (sv_skycolor_r.value != movevars.skycolor_r)
           ) || (sv_skycolor_g.value != movevars.skycolor_g)) ||
         ((sv_skycolor_b.value != movevars.skycolor_b || (sv_skyvec_x.value != movevars.skyvec_x))))
        || ((sv_skyvec_y.value != movevars.skyvec_y ||
            ((sv_skyvec_z.value != movevars.skyvec_z ||
             (iVar1 = Q_strcmp(sv_skyname.string,movevars.skyName), iVar1 != 0)))))))))) &&
     (SV_SetMoveVars(), 0 < svs.maxclients)) {
    iVar3 = 0;
    iVar1 = svs.maxclients;
    pcVar2 = svs.clients;
    do {
      if ((pcVar2->fakeclient == false) &&
         (((pcVar2->active != false || (pcVar2->spawned != false)) || (pcVar2->connected != false)))
         ) {
        SV_WriteMovevarsToClient(&(pcVar2->netchan).message);
        iVar1 = svs.maxclients;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


// SV_Rcon  @ 000a25c0
void SV_Rcon(netadr_t *net_from)

{
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t a_02;
  byte *pbVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char local_60c [1023];
  undefined1 local_20d;
  char local_20c [512];
  
                    /* Unresolved local var: int invalid@[???]
                       Unresolved local var: char[1024] remaining@[???]
                       Unresolved local var: char[512] rcon_buff@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char * data@[???] */
  iVar2 = SV_Rcon_Validate();
  iVar5 = net_message.cursize;
  iVar3 = Q_strlen("rcon");
  pbVar1 = net_message.data;
  iVar5 = iVar5 - iVar3;
  if ((0 < iVar5) && (iVar5 < 0x1ff)) {
    iVar3 = Q_strlen("rcon");
    Q_memcpy(local_20c,pbVar1 + iVar3,iVar5);
    local_20c[iVar5] = '\0';
    if (iVar2 == 0) {
      a.ip[0] = ::net_from.ip[0];
      a.ip[1] = ::net_from.ip[1];
      a.ip[2] = ::net_from.ip[2];
      a.ip[3] = ::net_from.ip[3];
      a.type = ::net_from.type;
      a.ipx[0] = ::net_from.ipx[0];
      a.ipx[1] = ::net_from.ipx[1];
      a.ipx[2] = ::net_from.ipx[2];
      a.ipx[3] = ::net_from.ipx[3];
      a.ipx[4] = ::net_from.ipx[4];
      a.ipx[5] = ::net_from.ipx[5];
      a.ipx[6] = ::net_from.ipx[6];
      a.ipx[7] = ::net_from.ipx[7];
      a.ipx[8] = ::net_from.ipx[8];
      a.ipx[9] = ::net_from.ipx[9];
      a.port = ::net_from.port;
      pcVar4 = NET_AdrToString(a);
      Con_Printf("Rcon from %s:\n%s\n",pcVar4,local_20c);
      a_00.ip[0] = ::net_from.ip[0];
      a_00.ip[1] = ::net_from.ip[1];
      a_00.ip[2] = ::net_from.ip[2];
      a_00.ip[3] = ::net_from.ip[3];
      a_00.type = ::net_from.type;
      a_00.ipx[0] = ::net_from.ipx[0];
      a_00.ipx[1] = ::net_from.ipx[1];
      a_00.ipx[2] = ::net_from.ipx[2];
      a_00.ipx[3] = ::net_from.ipx[3];
      a_00.ipx[4] = ::net_from.ipx[4];
      a_00.ipx[5] = ::net_from.ipx[5];
      a_00.ipx[6] = ::net_from.ipx[6];
      a_00.ipx[7] = ::net_from.ipx[7];
      a_00.ipx[8] = ::net_from.ipx[8];
      a_00.ipx[9] = ::net_from.ipx[9];
      a_00.port = ::net_from.port;
      pcVar4 = NET_AdrToString(a_00);
      Log_Printf("Rcon: \"%s\" from \"%s\"\n",local_20c,pcVar4);
      sv_redirected = RD_PACKET;
      outputbuf[0] = '\0';
                    /* Unresolved local var: char * data@[???] */
      sv_redirectto.type = ::net_from.type;
      sv_redirectto.ip[0] = ::net_from.ip[0];
      sv_redirectto.ip[1] = ::net_from.ip[1];
      sv_redirectto.ip[2] = ::net_from.ip[2];
      sv_redirectto.ip[3] = ::net_from.ip[3];
      sv_redirectto.ipx[0] = ::net_from.ipx[0];
      sv_redirectto.ipx[1] = ::net_from.ipx[1];
      sv_redirectto.ipx[2] = ::net_from.ipx[2];
      sv_redirectto.ipx[3] = ::net_from.ipx[3];
      sv_redirectto.ipx[4] = ::net_from.ipx[4];
      sv_redirectto.ipx[5] = ::net_from.ipx[5];
      sv_redirectto.ipx[6] = ::net_from.ipx[6];
      sv_redirectto.ipx[7] = ::net_from.ipx[7];
      sv_redirectto.ipx[8] = ::net_from.ipx[8];
      sv_redirectto.ipx[9] = ::net_from.ipx[9];
      sv_redirectto.port = ::net_from.port;
      pcVar4 = COM_Parse(local_20c);
      pcVar4 = COM_Parse(pcVar4);
      pcVar4 = COM_Parse(pcVar4);
      if (pcVar4 == (char *)0x0) {
        Con_Printf("Empty rcon\n");
        return;
      }
      Q_strncpy(local_60c,pcVar4,0x3ff);
      local_20d = 0;
      Cmd_ExecuteString(local_60c,src_command);
    }
    else {
      a_01.ip[0] = ::net_from.ip[0];
      a_01.ip[1] = ::net_from.ip[1];
      a_01.ip[2] = ::net_from.ip[2];
      a_01.ip[3] = ::net_from.ip[3];
      a_01.type = ::net_from.type;
      a_01.ipx[0] = ::net_from.ipx[0];
      a_01.ipx[1] = ::net_from.ipx[1];
      a_01.ipx[2] = ::net_from.ipx[2];
      a_01.ipx[3] = ::net_from.ipx[3];
      a_01.ipx[4] = ::net_from.ipx[4];
      a_01.ipx[5] = ::net_from.ipx[5];
      a_01.ipx[6] = ::net_from.ipx[6];
      a_01.ipx[7] = ::net_from.ipx[7];
      a_01.ipx[8] = ::net_from.ipx[8];
      a_01.ipx[9] = ::net_from.ipx[9];
      a_01.port = ::net_from.port;
      pcVar4 = NET_AdrToString(a_01);
      Con_Printf("Bad Rcon from %s:\n%s\n",pcVar4,local_20c);
      a_02.ip[0] = ::net_from.ip[0];
      a_02.ip[1] = ::net_from.ip[1];
      a_02.ip[2] = ::net_from.ip[2];
      a_02.ip[3] = ::net_from.ip[3];
      a_02.type = ::net_from.type;
      a_02.ipx[0] = ::net_from.ipx[0];
      a_02.ipx[1] = ::net_from.ipx[1];
      a_02.ipx[2] = ::net_from.ipx[2];
      a_02.ipx[3] = ::net_from.ipx[3];
      a_02.ipx[4] = ::net_from.ipx[4];
      a_02.ipx[5] = ::net_from.ipx[5];
      a_02.ipx[6] = ::net_from.ipx[6];
      a_02.ipx[7] = ::net_from.ipx[7];
      a_02.ipx[8] = ::net_from.ipx[8];
      a_02.ipx[9] = ::net_from.ipx[9];
      a_02.port = ::net_from.port;
      pcVar4 = NET_AdrToString(a_02);
      Log_Printf("Bad Rcon: \"%s\" from \"%s\"\n",local_20c,pcVar4);
      sv_redirected = RD_PACKET;
      outputbuf[0] = '\0';
      sv_redirectto.type = ::net_from.type;
      sv_redirectto.ip[0] = ::net_from.ip[0];
      sv_redirectto.ip[1] = ::net_from.ip[1];
      sv_redirectto.ip[2] = ::net_from.ip[2];
      sv_redirectto.ip[3] = ::net_from.ip[3];
      sv_redirectto.ipx[0] = ::net_from.ipx[0];
      sv_redirectto.ipx[1] = ::net_from.ipx[1];
      sv_redirectto.ipx[2] = ::net_from.ipx[2];
      sv_redirectto.ipx[3] = ::net_from.ipx[3];
      sv_redirectto.ipx[4] = ::net_from.ipx[4];
      sv_redirectto.ipx[5] = ::net_from.ipx[5];
      sv_redirectto.ipx[6] = ::net_from.ipx[6];
      sv_redirectto.ipx[7] = ::net_from.ipx[7];
      sv_redirectto.ipx[8] = ::net_from.ipx[8];
      sv_redirectto.ipx[9] = ::net_from.ipx[9];
      sv_redirectto.port = ::net_from.port;
      if ((iVar2 == 2) || (*rcon_password.string != '\0')) {
        Con_Printf("Bad rcon_password.\n");
      }
      else {
        Con_Printf("Bad rcon_password.\nNo password set for this server.\n");
      }
    }
    SV_FlushRedirect();
    sv_redirected = RD_NONE;
  }
  return;
}


// SV_Rcon  @ 000a2890
void SV_Rcon(netadr_t *net_from)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char local_61c [1023];
  undefined1 local_21d;
  char local_21c [524];
  
                    /* Unresolved local var: int invalid@[???]
                       Unresolved local var: char[1024] remaining@[???]
                       Unresolved local var: char[512] rcon_buff@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char * data@[???] */
  iVar2 = SV_Rcon_Validate();
  iVar5 = net_message.cursize;
  iVar3 = Q_strlen("rcon");
  pbVar1 = net_message.data;
  iVar5 = iVar5 - iVar3;
  if ((0 < iVar5) && (iVar5 < 0x1ff)) {
    iVar3 = Q_strlen("rcon");
    Q_memcpy(local_21c,pbVar1 + iVar3,iVar5);
    local_21c[iVar5] = '\0';
    if (iVar2 == 0) {
      pcVar4 = NET_AdrToString(*net_from);
      Con_Printf("Rcon from %s:\n%s\n",pcVar4,local_21c);
      pcVar4 = NET_AdrToString(*net_from);
      Log_Printf("Rcon: \"%s\" from \"%s\"\n",local_21c,pcVar4);
      sv_redirected = RD_PACKET;
      sv_redirectto.type = net_from->type;
      sv_redirectto.ip = *&net_from->ip;
      sv_redirectto.ipx._0_4_ = *(undefined4 *)net_from->ipx;
      sv_redirectto.ipx._4_4_ = *(undefined4 *)(net_from->ipx + 4);
      sv_redirectto._16_4_ = *(undefined4 *)(net_from->ipx + 8);
      outputbuf[0] = '\0';
                    /* Unresolved local var: char * data@[???] */
      pcVar4 = COM_Parse(local_21c);
      pcVar4 = COM_Parse(pcVar4);
      pcVar4 = COM_Parse(pcVar4);
      if (pcVar4 == (char *)0x0) {
        Con_Printf("Empty rcon\n");
        return;
      }
      Q_strncpy(local_61c,pcVar4,0x3ff);
      local_21d = 0;
      Cmd_ExecuteString(local_61c,src_command);
    }
    else {
      pcVar4 = NET_AdrToString(*net_from);
      Con_Printf("Bad Rcon from %s:\n%s\n",pcVar4,local_21c);
      pcVar4 = NET_AdrToString(*net_from);
      Log_Printf("Bad Rcon: \"%s\" from \"%s\"\n",local_21c,pcVar4);
      sv_redirected = RD_PACKET;
      sv_redirectto.type = net_from->type;
      sv_redirectto.ip = *&net_from->ip;
      sv_redirectto.ipx._0_4_ = *(undefined4 *)net_from->ipx;
      sv_redirectto.ipx._4_4_ = *(undefined4 *)(net_from->ipx + 4);
      sv_redirectto._16_4_ = *(undefined4 *)(net_from->ipx + 8);
      outputbuf[0] = '\0';
      if ((iVar2 == 2) || (*rcon_password.string != '\0')) {
        Con_Printf("Bad rcon_password.\n");
      }
      else {
        Con_Printf("Bad rcon_password.\nNo password set for this server.\n");
      }
    }
    SV_FlushRedirect();
    sv_redirected = RD_NONE;
  }
  return;
}


// SV_Rcon_Validate  @ 000a1f00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_Rcon_Validate(void)

{
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t adr;
  netadr_t a_02;
  netadr_t a_03;
  netadr_t b;
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  qboolean qVar7;
  char *pcVar8;
  char *s1;
  int iVar9;
  rcon_failure_t *prVar10;
  netadrtype_t nVar11;
  int iVar12;
  uchar auVar13 [4];
  float local_30;
  uchar local_2c [28];
  
  iVar12 = 1;
  iVar6 = Cmd_Argc();
  if ((2 < iVar6) && (iVar6 = Q_strlen(rcon_password.string), iVar6 != 0)) {
    if (sv_rcon_banpenalty.value < 0.0) {
      Cvar_SetValue("sv_rcon_banpenalty",0.0);
    }
    iVar6 = 0;
    do {
      if (((g_rgRconFailures[iVar6].active != false) &&
          (a.ip[0] = net_from.ip[0], a.ip[1] = net_from.ip[1], a.ip[2] = net_from.ip[2],
          a.ip[3] = net_from.ip[3], a.type = net_from.type, a.ipx[0] = net_from.ipx[0],
          a.ipx[1] = net_from.ipx[1], a.ipx[2] = net_from.ipx[2], a.ipx[3] = net_from.ipx[3],
          a.ipx[4] = net_from.ipx[4], a.ipx[5] = net_from.ipx[5], a.ipx[6] = net_from.ipx[6],
          a.ipx[7] = net_from.ipx[7], a.ipx[8] = net_from.ipx[8], a.ipx[9] = net_from.ipx[9],
          a.port = net_from.port, qVar7 = NET_CompareAdr(a,g_rgRconFailures[iVar6].adr),
          qVar7 != false)) && (g_rgRconFailures[iVar6].shouldreject != false)) {
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
        pcVar8 = NET_AdrToString(a_00);
        Con_Printf("Banning %s for rcon hacking attempts\n",pcVar8);
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
        pcVar8 = NET_BaseAdrToString(a_01);
        pcVar8 = va("addip %i %s\n",(int)sv_rcon_banpenalty.value,pcVar8);
        Cbuf_AddText(pcVar8);
        return 3;
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: rcon_failure_t * r@[???] */
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x20);
                    /* Unresolved local var: int i@[???] */
    iVar12 = 0;
    pcVar8 = Cmd_Argv(1);
    iVar6 = Q_atoi(pcVar8);
    adr.ip[0] = net_from.ip[0];
    adr.ip[1] = net_from.ip[1];
    adr.ip[2] = net_from.ip[2];
    adr.ip[3] = net_from.ip[3];
    adr.type = net_from.type;
    adr.ipx[0] = net_from.ipx[0];
    adr.ipx[1] = net_from.ipx[1];
    adr.ipx[2] = net_from.ipx[2];
    adr.ipx[3] = net_from.ipx[3];
    adr.ipx[4] = net_from.ipx[4];
    adr.ipx[5] = net_from.ipx[5];
    adr.ipx[6] = net_from.ipx[6];
    adr.ipx[7] = net_from.ipx[7];
    adr.ipx[8] = net_from.ipx[8];
    adr.ipx[9] = net_from.ipx[9];
    adr.port = net_from.port;
    qVar7 = NET_IsLocalAddress(adr);
    if (qVar7 == false) {
      do {
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
        qVar7 = NET_CompareBaseAdr(a_02,g_rg_sv_challenges[iVar12].adr);
        if (qVar7 != false) {
          if (iVar6 != g_rg_sv_challenges[iVar12].challenge) {
            SV_RejectConnection(&net_from,"Bad challenge.\n");
            return 2;
          }
          goto LAB_000a2172;
        }
                    /* Unresolved local var: int i@[???] */
        iVar12 = iVar12 + 1;
      } while (iVar12 != 0x400);
      iVar12 = 2;
      SV_RejectConnection(&net_from,"No challenge for your address.\n");
    }
    else {
LAB_000a2172:
      pcVar8 = rcon_password.string;
      iVar12 = 0;
      s1 = Cmd_Argv(2);
      iVar6 = Q_strcmp(s1,pcVar8);
      if (iVar6 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: float best_update@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: qboolean found@[???]
                       Unresolved local var: rcon_failure_t * r@[???]
                       Unresolved local var: int failed@[???] */
        iVar6 = (int)sv_rcon_minfailures.value;
        sv_rcon_minfailures.value = (float)iVar6;
        sv_rcon_maxfailures.value = (float)(int)sv_rcon_maxfailures.value;
        sv_rcon_minfailuretime.value = (float)(int)sv_rcon_minfailuretime.value;
        if ((float)iVar6 < 1.0) {
          Cvar_SetValue("sv_rcon_minfailures",1.0);
        }
        if (20.0 < sv_rcon_minfailures.value) {
          Cvar_SetValue("sv_rcon_minfailures",20.0);
        }
        if (sv_rcon_maxfailures.value < 1.0) {
          Cvar_SetValue("sv_rcon_maxfailures",1.0);
        }
        if (20.0 < sv_rcon_maxfailures.value) {
          Cvar_SetValue("sv_rcon_maxfailures",20.0);
        }
        fVar2 = sv_rcon_maxfailures.value;
        if (sv_rcon_maxfailures.value < sv_rcon_minfailures.value) {
                    /* Unresolved local var: float temp@[???] */
          Cvar_SetValue("sv_rcon_maxfailures",sv_rcon_minfailures.value);
          Cvar_SetValue("sv_rcon_minfailures",fVar2);
        }
        if (sv_rcon_minfailuretime.value < 1.0) {
          Cvar_SetValue("sv_rcon_minfailuretime",1.0);
        }
        iVar6 = 0;
        iVar12 = 0;
        local_30 = -99999.0;
        do {
          prVar10 = g_rgRconFailures + iVar12;
          if (g_rgRconFailures[iVar12].active == false) {
            fVar2 = (float)realtime;
            goto LAB_000a230e;
          }
          b.ip[0] = net_from.ip[0];
          b.ip[1] = net_from.ip[1];
          b.ip[2] = net_from.ip[2];
          b.ip[3] = net_from.ip[3];
          b.type = net_from.type;
          b.ipx[0] = net_from.ipx[0];
          b.ipx[1] = net_from.ipx[1];
          b.ipx[2] = net_from.ipx[2];
          b.ipx[3] = net_from.ipx[3];
          b.ipx[4] = net_from.ipx[4];
          b.ipx[5] = net_from.ipx[5];
          b.ipx[6] = net_from.ipx[6];
          b.ipx[7] = net_from.ipx[7];
          b.ipx[8] = net_from.ipx[8];
          b.ipx[9] = net_from.ipx[9];
          b.port = net_from.port;
          qVar7 = NET_CompareAdr(g_rgRconFailures[iVar12].adr,b);
          uVar4 = net_from.ipx._0_4_;
          if (qVar7 != false) {
            if (g_rgRconFailures[iVar12].shouldreject != false) {
              return 1;
            }
            local_30._0_1_ = net_from.ipx[0];
            local_30._1_1_ = net_from.ipx[1];
            local_30._2_1_ = net_from.ipx[2];
            local_30._3_1_ = net_from.ipx[3];
            fVar2 = (float)realtime;
            prVar10->active = true;
            nVar11 = net_from.type;
            g_rgRconFailures[iVar12].shouldreject = false;
            auVar13 = net_from.ip;
            iVar6 = g_rgRconFailures[iVar12].num_failures;
            *(undefined4 *)g_rgRconFailures[iVar12].adr.ipx = uVar4;
            uVar4 = net_from.ipx._4_4_;
            local_2c[0] = net_from.ipx[4];
            local_2c[1] = net_from.ipx[5];
            local_2c[2] = net_from.ipx[6];
            local_2c[3] = net_from.ipx[7];
            g_rgRconFailures[iVar12].last_update = fVar2;
            g_rgRconFailures[iVar12].adr.type = nVar11;
            *&g_rgRconFailures[iVar12].adr.ip = auVar13;
            *(undefined4 *)(g_rgRconFailures[iVar12].adr.ipx + 4) = uVar4;
            local_2c[4] = net_from.ipx[8];
            local_2c[5] = net_from.ipx[9];
            local_2c._6_2_ = net_from.port;
            *(undefined4 *)(g_rgRconFailures[iVar12].adr.ipx + 8) = net_from._16_4_;
            fVar1 = (float)iVar6;
            goto LAB_000a2367;
          }
          fVar2 = (float)realtime;
          fVar1 = fVar2 - g_rgRconFailures[iVar12].last_update;
          if (local_30 < fVar1) {
            iVar6 = iVar12;
            local_30 = fVar1;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 != 0x20);
        prVar10 = g_rgRconFailures + iVar6;
LAB_000a230e:
        local_30 = (float)net_from.ipx._0_4_;
        iVar6 = 0;
        prVar10->active = true;
        nVar11 = net_from.type;
        prVar10->shouldreject = false;
        auVar13 = net_from.ip;
        *(float *)(prVar10->adr).ipx = local_30;
        uVar4 = net_from.ipx._4_4_;
        prVar10->last_update = fVar2;
        (prVar10->adr).type = nVar11;
        fVar1 = 0.0;
        *&(prVar10->adr).ip = auVar13;
        prVar10->num_failures = 0;
        uVar5 = net_from.ipx._4_4_;
        net_from.ipx[4] = (uchar)uVar4;
        net_from.ipx[5] = SUB41(uVar4,1);
        net_from.ipx[6] = SUB41(uVar4,2);
        net_from.ipx[7] = SUB41(uVar4,3);
        local_2c[0] = net_from.ipx[4];
        local_2c[1] = net_from.ipx[5];
        local_2c[2] = net_from.ipx[6];
        local_2c[3] = net_from.ipx[7];
        net_from.ipx._4_4_ = uVar5;
        *(undefined4 *)((prVar10->adr).ipx + 4) = uVar4;
        local_2c._4_4_ = net_from._16_4_;
        *(undefined4 *)((prVar10->adr).ipx + 8) = net_from._16_4_;
LAB_000a2367:
        fVar3 = sv_rcon_maxfailures.value;
        if (sv_rcon_maxfailures.value <= fVar1) {
          iVar12 = 1;
          if (1.0 < sv_rcon_maxfailures.value) {
            do {
              prVar10->failure_times[iVar12 + -1] = prVar10->failure_times[iVar12];
              iVar12 = iVar12 + 1;
            } while ((float)iVar12 < fVar3);
          }
          iVar6 = iVar6 + -1;
        }
        prVar10->failure_times[iVar6] = fVar2;
        iVar6 = iVar6 + 1;
        iVar9 = 0;
        prVar10->num_failures = iVar6;
        if (0 < iVar6) {
          iVar12 = 0;
          do {
            if (fVar2 - prVar10->failure_times[iVar12] < sv_rcon_minfailuretime.value) {
              iVar9 = iVar9 + 1;
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 != iVar6);
        }
        iVar12 = 1;
        if (sv_rcon_minfailures.value <= (float)iVar9) {
          iVar12 = 1;
          a_03.ip[0] = auVar13[0];
          a_03.ip[1] = auVar13[1];
          a_03.ip[2] = auVar13[2];
          a_03.ip[3] = auVar13[3];
          a_03.type = nVar11;
          a_03.ipx._0_4_ = local_30;
          a_03.ipx[4] = local_2c[0];
          a_03.ipx[5] = local_2c[1];
          a_03.ipx[6] = local_2c[2];
          a_03.ipx[7] = local_2c[3];
          a_03._16_4_ = local_2c._4_4_;
          pcVar8 = NET_AdrToString(a_03);
          Con_Printf("User %s will be banned for rcon hacking\n",pcVar8);
          prVar10->shouldreject = true;
        }
      }
    }
  }
  return iVar12;
}


// SV_ReachedGoal  @ 000b0710
qboolean SV_ReachedGoal(edict_t_conflict *ent,vec_t *vecGoal,float flDist)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???] */
  qVar1 = false;
  if ((((*vecGoal <= (ent->v).absmax[0] + flDist) && ((ent->v).absmin[0] - flDist <= *vecGoal)) &&
      (vecGoal[1] <= (ent->v).absmax[1] + flDist)) &&
     (((ent->v).absmin[1] - flDist <= vecGoal[1] && (vecGoal[2] <= (ent->v).absmax[2] + flDist)))) {
    qVar1 = (qboolean)((ent->v).absmin[2] - flDist <= vecGoal[2]);
  }
  return qVar1;
}


// SV_ReadPackets  @ 000adbe0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ReadPackets(void)

{
  netchan_t *chan;
  netadr_t a;
  netadr_t_conflict adr;
  netadr_t a_00;
  netadr_t to;
  uint16_t port;
  qboolean qVar1;
  int iVar2;
  char *pcVar3;
  uint32_t fromip;
  client_s *cl;
  int iVar4;
  char local_5c [76];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: qboolean file@[???] */
                    /* Unresolved local var: char[64] szMessage@[???] */
  do {
    qVar1 = NET_GetPacket(NS_SERVER);
    while( true ) {
      if (qVar1 == false) {
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
        return;
      }
      qVar1 = SV_FilterPacket();
      if (qVar1 == false) break;
      snprintf(local_5c,0x40,"You have been banned from this server.\n");
      SZ_Clear(&net_message);
      MSG_WriteLong(&net_message,-1);
      MSG_WriteByte(&net_message,0x6c);
      MSG_WriteString(&net_message,local_5c);
      to.ip[0] = net_from.ip[0];
      to.ip[1] = net_from.ip[1];
      to.ip[2] = net_from.ip[2];
      to.ip[3] = net_from.ip[3];
      to.type = net_from.type;
      to.ipx[0] = net_from.ipx[0];
      to.ipx[1] = net_from.ipx[1];
      to.ipx[2] = net_from.ipx[2];
      to.ipx[3] = net_from.ipx[3];
      to.ipx[4] = net_from.ipx[4];
      to.ipx[5] = net_from.ipx[5];
      to.ipx[6] = net_from.ipx[6];
      to.ipx[7] = net_from.ipx[7];
      to.ipx[8] = net_from.ipx[8];
      to.ipx[9] = net_from.ipx[9];
      to.port = net_from.port;
      NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,to);
      SZ_Clear(&net_message);
      qVar1 = NET_GetPacket(NS_SERVER);
    }
    if (*(int *)net_message.data == -1) {
      adr.ip[0] = net_from.ip[0];
      adr.ip[1] = net_from.ip[1];
      adr.ip[2] = net_from.ip[2];
      adr.ip[3] = net_from.ip[3];
      adr.type = net_from.type;
      adr.ipx[0] = net_from.ipx[0];
      adr.ipx[1] = net_from.ipx[1];
      adr.ipx[2] = net_from.ipx[2];
      adr.ipx[3] = net_from.ipx[3];
      adr.ipx[4] = (char)net_from.ipx._4_2_;
      adr.ipx[5] = (char)((ushort)net_from.ipx._4_2_ >> 8);
      adr.ipx[6] = (char)net_from.ipx._6_2_;
      adr.ipx[7] = (char)((ushort)net_from.ipx._6_2_ >> 8);
      adr.ipx[8] = net_from.ipx[8];
      adr.ipx[9] = net_from.ipx[9];
      adr.port = net_from.port;
      iVar2 = CheckIP(adr);
      if (iVar2 == 0) {
        if (sv_logblocks.value != 0.0) {
          a_00.ip[0] = net_from.ip[0];
          a_00.ip[1] = net_from.ip[1];
          a_00.ip[2] = net_from.ip[2];
          a_00.ip[3] = net_from.ip[3];
          a_00.type = net_from.type;
          a_00.ipx[0] = net_from.ipx[0];
          a_00.ipx[1] = net_from.ipx[1];
          a_00.ipx[2] = net_from.ipx[2];
          a_00.ipx[3] = net_from.ipx[3];
          a_00.ipx[4] = (char)net_from.ipx._4_2_;
          a_00.ipx[5] = (char)((ushort)net_from.ipx._4_2_ >> 8);
          a_00.ipx[6] = (char)net_from.ipx._6_2_;
          a_00.ipx[7] = (char)((ushort)net_from.ipx._6_2_ >> 8);
          a_00.ipx[8] = net_from.ipx[8];
          a_00.ipx[9] = net_from.ipx[9];
          a_00.port = net_from.port;
          pcVar3 = NET_AdrToString(a_00);
          Log_Printf("Traffic from %s was blocked for exceeding rate limits\n",pcVar3);
        }
      }
      else {
        port = htons(net_from.port);
        fromip = ntohl((uint32_t)net_from.ip);
        Steam_HandleIncomingPacket(net_message.data,net_message.cursize,fromip,port);
        SV_ConnectionlessPacket();
      }
    }
    else if (0 < svs.maxclients) {
      iVar4 = 0;
      iVar2 = svs.maxclients;
      cl = svs.clients;
      do {
        if ((((cl->connected != false) || (cl->active != false)) || (cl->spawned != false)) &&
           (a.ip[0] = net_from.ip[0], a.ip[1] = net_from.ip[1], a.ip[2] = net_from.ip[2],
           a.ip[3] = net_from.ip[3], a.type = net_from.type, a.ipx[0] = net_from.ipx[0],
           a.ipx[1] = net_from.ipx[1], a.ipx[2] = net_from.ipx[2], a.ipx[3] = net_from.ipx[3],
           a.ipx[4] = (char)net_from.ipx._4_2_, a.ipx[5] = (char)((ushort)net_from.ipx._4_2_ >> 8),
           a.ipx[6] = (char)net_from.ipx._6_2_, a.ipx[7] = (char)((ushort)net_from.ipx._6_2_ >> 8),
           a.ipx[8] = net_from.ipx[8], a.ipx[9] = net_from.ipx[9], a.port = net_from.port,
           qVar1 = NET_CompareAdr(a,(cl->netchan).remote_address), iVar2 = svs.maxclients,
           qVar1 != false)) {
          chan = &cl->netchan;
          qVar1 = Netchan_Process(chan);
          if (qVar1 != false) {
            if (svs.maxclients == 1) {
              cl->send_message = true;
            }
            if (((cl->active == false) || (cl->spawned == false)) || (cl->fully_connected == false))
            {
              cl->send_message = true;
            }
            SV_ExecuteClientMessage(cl);
            gGlobalVariables.frametime = (float)host_frametime;
          }
          qVar1 = Netchan_IncomingReady(chan);
          iVar2 = svs.maxclients;
          if (qVar1 != false) {
            qVar1 = Netchan_CopyNormalFragments(chan);
            if (qVar1 != false) {
              MSG_BeginReading();
              SV_ExecuteClientMessage(cl);
            }
            qVar1 = Netchan_CopyFileFragments(chan);
            iVar2 = svs.maxclients;
            if (qVar1 != false) {
              host_client = cl;
              SV_ProcessFile(cl,(cl->netchan).incomingfilename);
              iVar2 = svs.maxclients;
            }
          }
        }
        iVar4 = iVar4 + 1;
        cl = cl + 1;
      } while (iVar4 < iVar2);
    }
  } while( true );
}


// SV_ReallocateDynamicData  @ 0009c6e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ReallocateDynamicData(void)

{
  int iVar1;
  
                    /* Unresolved local var: int nSize@[???] */
  iVar1 = sv.max_edicts;
  if (sv.max_edicts != 0) {
    if (g_moved_edict != (edict_t_conflict **)0x0) {
      Con_Printf("Reallocate on moved_edict\n");
    }
    g_moved_edict = Mem_ZeroMalloc(iVar1 * 4);
    if (g_moved_from != (vec3_t *)0x0) {
      Con_Printf("Reallocate on moved_from\n");
    }
    g_moved_from = Mem_ZeroMalloc(iVar1 * 0xc);
    return;
  }
  Con_DPrintf("SV_ReallocateDynamicData with sv.max_edicts == 0");
  return;
}


// SV_ReconnectAllClients  @ 000a75e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ReconnectAllClients(void)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  char local_3e [46];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[34] message@[???] */
  pcVar2 = "Server updating Security Module.\n";
  uVar5 = 0x22;
  bVar7 = ((uint)local_3e & 2) != 0;
  pcVar3 = local_3e;
  if (bVar7) {
    pcVar3 = local_3e + 2;
    pcVar2 = "rver updating Security Module.\n";
    uVar5 = 0x20;
    local_3e[0] = 'S';
    local_3e[1] = 'e';
  }
  uVar1 = 0;
  do {
    *(undefined4 *)(pcVar3 + uVar1) = *(undefined4 *)(pcVar2 + uVar1);
    uVar1 = uVar1 + 4;
  } while (uVar1 < (uVar5 & 0xfffffffc));
  if (!bVar7) {
    *(undefined2 *)(pcVar3 + uVar1) = *(undefined2 *)(pcVar2 + uVar1);
  }
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar6 = 0;
    iVar4 = svs.maxclients;
    do {
      while (((host_client->active != false || (host_client->connected != false)) &&
             (host_client->fakeclient == false))) {
        iVar6 = iVar6 + 1;
        Netchan_Clear(&host_client->netchan);
        MSG_WriteByte(&(host_client->netchan).message,8);
        MSG_WriteString(&(host_client->netchan).message,local_3e);
        MSG_WriteByte(&(host_client->netchan).message,9);
        MSG_WriteString(&(host_client->netchan).message,"retry\n");
        SV_DropClient(host_client,false,local_3e);
        host_client = host_client + 1;
        iVar4 = svs.maxclients;
        if (svs.maxclients <= iVar6) {
          return;
        }
      }
      iVar6 = iVar6 + 1;
      host_client = host_client + 1;
    } while (iVar6 < iVar4);
  }
  return;
}


// SV_RecursiveHullCheck  @ 000bff70
qboolean SV_RecursiveHullCheck
                   (hull_t *hull,int num,float p1f,float p2f,vec_t *p1,vec_t *p2,trace_t *trace)

{
  dclipnode_t *pdVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  mplane_t *pmVar5;
  uint uVar6;
  qboolean qVar7;
  int iVar8;
  qboolean qVar9;
  qboolean local_44;
  float local_40;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: float midf@[???] */
  if (-1 < num) {
    if (((num < hull->firstclipnode) || (hull->lastclipnode < num)) ||
       (pmVar5 = hull->planes, pmVar5 == (mplane_t *)0x0)) {
      Sys_Error("SV_RecursiveHullCheck: bad node number");
      pmVar5 = hull->planes;
    }
    pdVar1 = hull->clipnodes + num;
    pmVar5 = pmVar5 + pdVar1->planenum;
    bVar2 = pmVar5->type;
    if (bVar2 < 3) {
      fVar4 = p1[bVar2] - pmVar5->dist;
      fVar3 = p2[bVar2] - pmVar5->dist;
    }
    else {
      fVar4 = (p1[2] * pmVar5->normal[2] + p1[1] * pmVar5->normal[1] + *p1 * pmVar5->normal[0]) -
              pmVar5->dist;
      fVar3 = (pmVar5->normal[2] * p2[2] + pmVar5->normal[1] * p2[1] + pmVar5->normal[0] * *p2) -
              pmVar5->dist;
    }
    if ((0.0 <= fVar4) && (0.0 <= fVar3)) {
      qVar9 = SV_RecursiveHullCheck(hull,(int)pdVar1->children[0],p1f,p2f,p1,p2,trace);
      return qVar9;
    }
    if (fVar4 < 0.0) {
      if (fVar3 < 0.0) {
        qVar9 = SV_RecursiveHullCheck(hull,(int)pdVar1->children[1],p1f,p2f,p1,p2,trace);
        return qVar9;
      }
      local_40 = (fVar4 + 0.03125) / (fVar4 - fVar3);
    }
    else {
      local_40 = (fVar4 - 0.03125) / (fVar4 - fVar3);
    }
    if (local_40 < 0.0) {
      local_40 = 0.0;
    }
    else if (1.0 < local_40) {
      local_40 = 1.0;
    }
    qVar9 = false;
    if (nanmask != ((uint)local_40 & nanmask)) {
      fVar3 = (p2f - p1f) * local_40 + p1f;
      local_2c = (*p2 - *p1) * local_40 + *p1;
      local_28 = (p2[1] - p1[1]) * local_40 + p1[1];
      local_24 = (p2[2] - p1[2]) * local_40 + p1[2];
      uVar6 = (uint)(fVar4 < 0.0);
      local_44 = false;
      qVar7 = SV_RecursiveHullCheck(hull,(int)pdVar1->children[uVar6],p1f,fVar3,p1,&local_2c,trace);
      qVar9 = false;
      if (qVar7 != false) {
        iVar8 = SV_HullPointContents(hull,(int)pdVar1->children[uVar6 ^ 1],&local_2c);
        if (iVar8 == -2) {
          qVar9 = local_44;
          if (trace->allsolid == false) {
            if (uVar6 == 0) {
              (trace->plane).normal[0] = pmVar5->normal[0];
              (trace->plane).normal[1] = pmVar5->normal[1];
              (trace->plane).normal[2] = pmVar5->normal[2];
              (trace->plane).dist = pmVar5->dist;
            }
            else {
              (trace->plane).normal[0] = vec3_origin[0] - pmVar5->normal[0];
              (trace->plane).normal[1] = vec3_origin[1] - pmVar5->normal[1];
              (trace->plane).normal[2] = vec3_origin[2] - pmVar5->normal[2];
              (trace->plane).dist = -pmVar5->dist;
            }
            while (iVar8 = SV_HullPointContents(hull,hull->firstclipnode,&local_2c), iVar8 == -2) {
              local_40 = local_40 - 0.1;
              if (local_40 < 0.0) {
                trace->fraction = fVar3;
                trace->endpos[0] = local_2c;
                trace->endpos[1] = local_28;
                trace->endpos[2] = local_24;
                Con_DPrintf("backup past 0\n");
                return false;
              }
              fVar3 = (p2f - p1f) * local_40 + p1f;
              local_2c = (*p2 - *p1) * local_40 + *p1;
              local_28 = (p2[1] - p1[1]) * local_40 + p1[1];
              local_24 = (p2[2] - p1[2]) * local_40 + p1[2];
            }
            trace->fraction = fVar3;
            trace->endpos[0] = local_2c;
            trace->endpos[1] = local_28;
            trace->endpos[2] = local_24;
            qVar9 = false;
          }
        }
        else {
          qVar9 = SV_RecursiveHullCheck
                            (hull,(int)pdVar1->children[uVar6 ^ 1],fVar3,p2f,&local_2c,p2,trace);
        }
      }
    }
    return qVar9;
  }
  if (num == -2) {
    trace->startsolid = true;
    return true;
  }
  trace->allsolid = false;
  if (num == -1) {
    trace->inopen = true;
    return true;
  }
  if (num != -0xf) {
    trace->inwater = true;
    return true;
  }
  return true;
}


// SV_RecursiveWaterLevel  @ 000b3960
float SV_RecursiveWaterLevel(vec_t *center,float out,float in,int count)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  vec_t local_48;
  vec_t local_44;
  float local_40;
  vec_t local_3c;
  vec_t local_38;
  float local_34;
  vec_t local_30;
  vec_t local_2c;
  float local_28;
  vec_t local_24;
  vec_t local_20;
  float local_1c;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
  fVar1 = (out - in) * 0.5 + in;
  fVar6 = fVar1;
  if (count < 5) {
    local_48 = *center;
    local_40 = center[2] + fVar1;
    local_44 = center[1];
    iVar3 = SV_PointContents(&local_48);
    if (iVar3 != -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
      fVar6 = (fVar1 - in) * 0.5 + in;
      fVar5 = fVar6;
      if (count != 4) {
        local_30 = *center;
        local_28 = center[2] + fVar6;
        local_2c = center[1];
        iVar3 = SV_PointContents(&local_30);
        if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
          fVar2 = (fVar1 - fVar6) * 0.5 + fVar6;
          fVar5 = fVar2;
          if (count != 3) {
            local_24 = *center;
            local_1c = center[2] + fVar2;
            local_20 = center[1];
            iVar3 = SV_PointContents(&local_24);
            if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
              iVar3 = count + 4;
              fVar5 = fVar2 + (fVar1 - fVar2) * 0.5;
              if (iVar3 != 6) {
                local_3c = *center;
                local_34 = center[2] + fVar5;
                local_38 = center[1];
                iVar4 = SV_PointContents(&local_3c);
                if (iVar4 == -3) {
                  fVar5 = SV_RecursiveWaterLevel(center,fVar1,fVar5,iVar3);
                }
                else {
                  fVar5 = SV_RecursiveWaterLevel(center,fVar5,fVar2,iVar3);
                }
              }
            }
            else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
              iVar3 = count + 4;
              fVar5 = (fVar2 - fVar6) * 0.5 + fVar6;
              if (iVar3 != 6) {
                local_3c = *center;
                local_34 = center[2] + fVar5;
                local_38 = center[1];
                iVar4 = SV_PointContents(&local_3c);
                if (iVar4 == -3) {
                  fVar5 = SV_RecursiveWaterLevel(center,fVar2,fVar5,iVar3);
                }
                else {
                  fVar5 = SV_RecursiveWaterLevel(center,fVar5,fVar6,iVar3);
                }
              }
            }
          }
        }
        else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
          fVar1 = (fVar6 - in) * 0.5 + in;
          fVar5 = fVar1;
          if (count != 3) {
            local_3c = *center;
            local_34 = center[2] + fVar1;
            local_38 = center[1];
            iVar3 = SV_PointContents(&local_3c);
            if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
              fVar2 = (fVar6 - fVar1) * 0.5 + fVar1;
              fVar5 = fVar2;
              if (count != 2) {
                local_24 = *center;
                local_1c = center[2] + fVar2;
                local_20 = center[1];
                iVar3 = SV_PointContents(&local_24);
                if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
                  iVar3 = count + 5;
                  fVar5 = (fVar6 - fVar2) * 0.5 + fVar2;
                  if (iVar3 != 6) {
                    local_18 = *center;
                    local_10 = center[2] + fVar5;
                    local_14 = center[1];
                    iVar4 = SV_PointContents(&local_18);
                    if (iVar4 == -3) {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar6,fVar5,iVar3);
                    }
                    else {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar5,fVar2,iVar3);
                    }
                  }
                }
                else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
                  iVar3 = count + 5;
                  fVar5 = fVar1 + (fVar2 - fVar1) * 0.5;
                  if (iVar3 != 6) {
                    local_18 = *center;
                    local_10 = center[2] + fVar5;
                    local_14 = center[1];
                    iVar4 = SV_PointContents(&local_18);
                    if (iVar4 == -3) {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar2,fVar5,iVar3);
                    }
                    else {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar5,fVar1,iVar3);
                    }
                  }
                }
              }
            }
            else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
              fVar6 = (fVar1 - in) * 0.5 + in;
              fVar5 = fVar6;
              if (count != 2) {
                local_18 = *center;
                local_10 = center[2] + fVar6;
                local_14 = center[1];
                iVar3 = SV_PointContents(&local_18);
                if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
                  iVar3 = count + 5;
                  fVar5 = fVar6 + (fVar1 - fVar6) * 0.5;
                  if (iVar3 != 6) {
                    local_24 = *center;
                    local_1c = center[2] + fVar5;
                    local_20 = center[1];
                    iVar4 = SV_PointContents(&local_24);
                    if (iVar4 == -3) {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar1,fVar5,iVar3);
                    }
                    else {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar5,fVar6,iVar3);
                    }
                  }
                }
                else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
                  iVar3 = count + 5;
                  fVar5 = (fVar6 - in) * 0.5 + in;
                  if (iVar3 != 6) {
                    local_24 = *center;
                    local_1c = center[2] + fVar5;
                    local_20 = center[1];
                    iVar4 = SV_PointContents(&local_24);
                    if (iVar4 == -3) {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar6,fVar5,iVar3);
                    }
                    else {
                      fVar5 = SV_RecursiveWaterLevel(center,fVar5,in,iVar3);
                    }
                  }
                }
              }
            }
          }
        }
      }
      return fVar5;
    }
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
    fVar5 = (out - fVar1) * 0.5 + fVar1;
    fVar6 = fVar5;
    if (count != 4) {
      local_3c = *center;
      local_34 = center[2] + fVar5;
      local_38 = center[1];
      iVar3 = SV_PointContents(&local_3c);
      if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
        fVar1 = (out - fVar5) * 0.5 + fVar5;
        fVar6 = fVar1;
        if (count != 3) {
          local_30 = *center;
          local_28 = center[2] + fVar1;
          local_2c = center[1];
          iVar3 = SV_PointContents(&local_30);
          if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
            iVar3 = count + 4;
            fVar6 = fVar1 + (out - fVar1) * 0.5;
            if (iVar3 != 6) {
              local_24 = *center;
              local_1c = center[2] + fVar6;
              local_20 = center[1];
              iVar4 = SV_PointContents(&local_24);
              if (iVar4 == -3) {
                fVar6 = SV_RecursiveWaterLevel(center,out,fVar6,iVar3);
              }
              else {
                fVar6 = SV_RecursiveWaterLevel(center,fVar6,fVar1,iVar3);
              }
            }
          }
          else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
            iVar3 = count + 4;
            fVar6 = fVar5 + (fVar1 - fVar5) * 0.5;
            if (iVar3 != 6) {
              local_24 = *center;
              local_1c = center[2] + fVar6;
              local_20 = center[1];
              iVar4 = SV_PointContents(&local_24);
              if (iVar4 == -3) {
                fVar6 = SV_RecursiveWaterLevel(center,fVar1,fVar6,iVar3);
              }
              else {
                fVar6 = SV_RecursiveWaterLevel(center,fVar6,fVar5,iVar3);
              }
            }
          }
        }
      }
      else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
        fVar2 = (fVar5 - fVar1) * 0.5 + fVar1;
        fVar6 = fVar2;
        if (count != 3) {
          local_24 = *center;
          local_1c = center[2] + fVar2;
          local_20 = center[1];
          iVar3 = SV_PointContents(&local_24);
          if (iVar3 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
            iVar3 = count + 4;
            fVar6 = fVar2 + (fVar5 - fVar2) * 0.5;
            if (iVar3 != 6) {
              local_30 = *center;
              local_28 = center[2] + fVar6;
              local_2c = center[1];
              iVar4 = SV_PointContents(&local_30);
              if (iVar4 == -3) {
                fVar6 = SV_RecursiveWaterLevel(center,fVar5,fVar6,iVar3);
              }
              else {
                fVar6 = SV_RecursiveWaterLevel(center,fVar6,fVar2,iVar3);
              }
            }
          }
          else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
            iVar3 = count + 4;
            fVar6 = (fVar2 - fVar1) * 0.5 + fVar1;
            if (iVar3 != 6) {
              local_30 = *center;
              local_28 = center[2] + fVar6;
              local_2c = center[1];
              iVar4 = SV_PointContents(&local_30);
              if (iVar4 == -3) {
                fVar6 = SV_RecursiveWaterLevel(center,fVar2,fVar6,iVar3);
              }
              else {
                fVar6 = SV_RecursiveWaterLevel(center,fVar6,fVar1,iVar3);
              }
            }
          }
        }
      }
    }
  }
  return fVar6;
}


// SV_RegisterDelta  @ 000a9ce0
void SV_RegisterDelta(char *name,char *loadfile)

{
  qboolean qVar1;
  delta_info_t *pdVar2;
  char *pcVar3;
  delta_t *local_10;
  
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10 = (delta_t *)0x0;
  qVar1 = DELTA_Load(name,&local_10,loadfile);
  if (qVar1 != false) {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup(loadfile);
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup(name);
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10;
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
    return;
  }
  Sys_Error("Error parsing %s!!!\n",loadfile);
  return;
}


// SV_RegisterResources  @ 000b6f20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RegisterResources(void)

{
  resource_t *prVar1;
  resource_t *pResource;
  client_t *pHost;
  qboolean bSkipPlayer;
  
                    /* Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: client_t * pHost@[???] */
  pHost = host_client;
  pResource = (host_client->resourcesonhand).pNext;
  prVar1 = &host_client->resourcesonhand;
  host_client->uploading = false;
  for (; pResource != prVar1; pResource = pResource->pNext) {
    SV_CreateCustomizationList(pHost);
    SV_Customization(pHost,pResource,bSkipPlayer);
  }
  host_client = pHost;
  return;
}


// SV_RejectConnection  @ 0009ee90
void SV_RejectConnection(netadr_t *adr,char *fmt,...)

{
  char local_40c [1028];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] text@[???] */
  vsnprintf(local_40c,0x400,fmt,&stack0x0000000c);
  SZ_Clear(&net_message);
  MSG_WriteLong(&net_message,-1);
  MSG_WriteByte(&net_message,0x39);
  MSG_WriteString(&net_message,local_40c);
  NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,*adr);
  SZ_Clear(&net_message);
  return;
}


// SV_RejectConnectionForPassword  @ 0009ef70
void SV_RejectConnectionForPassword(netadr_t *adr)

{
  SZ_Clear(&net_message);
  MSG_WriteLong(&net_message,-1);
  MSG_WriteByte(&net_message,0x38);
  MSG_WriteString(&net_message,"BADPASSWORD");
  NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,*adr);
  SZ_Clear(&net_message);
  return;
}


// SV_RemoveFromResourceList  @ 000b70d0
void SV_RemoveFromResourceList(resource_t *pResource)

{
  pResource->pPrev->pNext = pResource->pNext;
  pResource->pNext->pPrev = pResource->pPrev;
  pResource->pPrev = (resource_s *)0x0;
  pResource->pNext = (resource_s *)0x0;
  return;
}


// SV_RemoveIP_f  @ 000a89a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RemoveIP_f(void)

{
  char *pcVar1;
  qboolean qVar2;
  ipfilter_t *piVar3;
  int iVar4;
  ipfilter_t local_1c;
  
                    /* Unresolved local var: ipfilter_t f@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  pcVar1 = Cmd_Argv(1);
  qVar2 = StringToFilter(pcVar1,&local_1c);
  if (qVar2 == false) {
    return;
  }
  if (0 < numipfilters) {
    piVar3 = ipfilters;
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      if ((local_1c.mask == piVar3->mask) && (piVar3->compare == local_1c.compare)) {
        if (iVar4 < numipfilters) {
          piVar3 = ipfilters + iVar4;
          do {
            piVar3[-1].mask = piVar3->mask;
            piVar3[-1].compare = piVar3->compare;
            piVar3[-1].banEndTime = piVar3->banEndTime;
            piVar3[-1].banTime = piVar3->banTime;
            piVar3 = piVar3 + 1;
          } while (piVar3 != ipfilters + numipfilters);
        }
        iVar4 = numipfilters + -1;
        numipfilters = iVar4;
        ipfilters[iVar4].compare = 0;
        ipfilters[iVar4].banTime = 0.0;
        ipfilters[iVar4].banEndTime = 0.0;
        ipfilters[iVar4].mask = 0;
        Con_Printf("IP filter removed.\n");
        return;
      }
      piVar3 = piVar3 + 1;
    } while (iVar4 != numipfilters);
  }
  pcVar1 = Cmd_Argv(1);
  Con_Printf("removeip: couldn\'t find %s.\n",pcVar1);
  return;
}


// SV_RemoveId_f  @ 000ab570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RemoveId_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  userfilter_t *puVar6;
  int iVar7;
  char local_6c;
  char local_6b [62];
  undefined1 local_2d;
  USERID_t local_2c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char[64] idstring@[???] */
  iVar1 = Cmd_Argc();
  if ((iVar1 != 2) && (iVar1 = Cmd_Argc(), iVar1 != 6)) {
    Con_Printf("Usage:  removeid <uniqueid | #slotnumber>\n");
    return;
  }
  pcVar2 = Cmd_Argv(1);
  strncpy(&local_6c,pcVar2,0x3f);
  local_2d = 0;
  if (local_6c == '\0') {
    Con_Printf("SV_RemoveId_f:  Id string is empty!\n");
    return;
  }
  if (local_6c != '#') {
    iVar1 = Q_strnicmp(&local_6c,"STEAM_",6);
    if ((iVar1 == 0) || (iVar1 = Q_strnicmp(&local_6c,"VALVE_",6), iVar1 == 0)) {
      pcVar2 = Cmd_Argv(5);
      pcVar3 = Cmd_Argv(3);
      pcVar4 = Cmd_Argv(1);
      snprintf(&local_6c,0x3f,"%s:%s:%s",pcVar4,pcVar3,pcVar2);
      local_2d = 0;
    }
    if (0 < numuserfilters) {
      iVar1 = 0;
      do {
        iVar7 = iVar1 + 1;
        pcVar2 = SV_GetIDString(&userfilters[iVar1].userid);
        iVar1 = Q_stricmp(pcVar2,&local_6c);
        if (iVar1 == 0) {
          if (iVar7 < numuserfilters) {
            puVar6 = userfilters + iVar7;
            do {
              uVar5 = 0;
              do {
                *(undefined4 *)((int)&puVar6[-1].userid.idtype + uVar5) =
                     *(undefined4 *)((int)&(puVar6->userid).idtype + uVar5);
                uVar5 = uVar5 + 4;
              } while (uVar5 < 0x18);
              puVar6 = puVar6 + 1;
            } while (puVar6 != userfilters + numuserfilters);
          }
          numuserfilters = numuserfilters + -1;
          Con_Printf("UserID filter removed for %s\n",&local_6c);
          return;
        }
        iVar1 = iVar7;
      } while (iVar7 < numuserfilters);
    }
    Con_Printf("removeid: couldn\'t find %s\n",&local_6c);
    return;
  }
                    /* Unresolved local var: int slot@[???] */
  iVar1 = Q_atoi(local_6b);
  if ((0 < iVar1) && (iVar1 <= numuserfilters)) {
                    /* Unresolved local var: USERID_t id@[???] */
    local_2c.idtype = userfilters[iVar1 + -1].userid.idtype;
    local_2c.m_SteamID._0_4_ = (undefined4)userfilters[iVar1 + -1].userid.m_SteamID;
    local_2c.m_SteamID._4_4_ = *(undefined4 *)((int)&userfilters[iVar1 + -1].userid.m_SteamID + 4);
    local_2c.clientip = userfilters[iVar1 + -1].userid.clientip;
    if (iVar1 < numuserfilters) {
      puVar6 = userfilters + iVar1;
      do {
        uVar5 = 0;
        do {
          *(undefined4 *)((int)&puVar6[-1].userid.idtype + uVar5) =
               *(undefined4 *)((int)&(puVar6->userid).idtype + uVar5);
          uVar5 = uVar5 + 4;
        } while (uVar5 < 0x18);
        puVar6 = puVar6 + 1;
      } while (puVar6 != userfilters + numuserfilters);
    }
    numuserfilters = numuserfilters + -1;
    pcVar2 = SV_GetIDString(&local_2c);
    Con_Printf("UserID filter removed for %s, id %s\n",&local_6c,pcVar2);
    return;
  }
  Con_Printf("SV_RemoveId_f:  invalid slot #%i\n",iVar1);
  return;
}


// SV_RequestMissingResources  @ 000b7490
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SV_RequestMissingResources(void)

{
  resource_t *prVar1;
  resource_t *pResource;
  client_t *pHost;
  qboolean bSkipPlayer;
  
  pHost = host_client;
  if (((host_client->uploading != false) && (host_client->uploaddoneregistering == false)) &&
     ((host_client->resourcesneeded).pNext == &host_client->resourcesneeded)) {
                    /* Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: client_t * pHost@[DW_OP_reg3(EBX)] */
    pResource = (host_client->resourcesonhand).pNext;
    prVar1 = &host_client->resourcesonhand;
    host_client->uploading = false;
    for (; prVar1 != pResource; pResource = pResource->pNext) {
      SV_CreateCustomizationList(pHost);
      SV_Customization(pHost,pResource,bSkipPlayer);
    }
    host_client = pHost;
    SV_PropagateCustomizations();
    if (sv_allow_upload.value != 0.0) {
      Con_DPrintf("Custom resource propagation complete.\n");
    }
    pHost->uploaddoneregistering = true;
  }
  return false;
}


// SV_RequestMissingResourcesFromClients  @ 000b7190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RequestMissingResourcesFromClients(void)

{
  resource_t *pResource;
  qboolean bSkipPlayer;
  int iVar1;
  client_s *pHost;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar2 = 0;
    iVar1 = svs.maxclients;
    pHost = svs.clients;
    do {
      if ((((pHost->active != false) || (host_client = pHost, pHost->spawned != false)) &&
          (host_client = pHost, pHost->uploading != false)) &&
         ((pHost->uploaddoneregistering == false &&
          ((pHost->resourcesneeded).pNext == &pHost->resourcesneeded)))) {
                    /* Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: client_t * pHost@[???] */
        pResource = (pHost->resourcesonhand).pNext;
        pHost->uploading = false;
        for (; pResource != &pHost->resourcesonhand; pResource = pResource->pNext) {
          SV_CreateCustomizationList(pHost);
          SV_Customization(pHost,pResource,bSkipPlayer);
        }
        host_client = pHost;
        SV_PropagateCustomizations();
        if (sv_allow_upload.value != 0.0) {
          Con_DPrintf("Custom resource propagation complete.\n");
        }
        iVar1 = svs.maxclients;
        pHost->uploaddoneregistering = true;
      }
      iVar2 = iVar2 + 1;
      pHost = host_client + 1;
      host_client = pHost;
    } while (iVar2 < iVar1);
  }
  return;
}


// SV_ResetModInfo  @ 000a00c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ResetModInfo(void)

{
  FileHandle_t file;
  undefined *size;
  char *pOutput;
  char *pcVar1;
  int iVar2;
  undefined *puVar3;
  char local_260 [260];
  char local_15c [255];
  undefined1 local_5d;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * pszInputStream@[???]
                       Unresolved local var: char * pStreamPos@[???]
                       Unresolved local var: char[260] szDllListFile@[???]
                       Unresolved local var: int nFileSize@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: FileHandle_t hLibListFile@[???]
                       Unresolved local var: char[64] szKey@[???]
                       Unresolved local var: char[256] szValue@[???] */
  Q_memset(&gmodinfo,0,0x244);
  gmodinfo.version = 1;
  gmodinfo.svonly = true;
  gmodinfo.num_edicts = 900;
  puVar3 = &DAT_000e5296;
  snprintf(local_260,0x104,"%s","liblist.gam");
  file = FS_Open(local_260,"rb");
  if (file != (FileHandle_t)0x0) {
    size = (undefined *)FS_Size(file);
    if ((0x40000 < (int)size) || (size == (undefined *)0x0)) {
      puVar3 = size;
      Sys_Error("Game listing file size is bogus [%s: size %i]","liblist.gam",size);
    }
    pOutput = Mem_Malloc((size_t)(size + 1));
    if (pOutput == (char *)0x0) {
      Sys_Error("Could not allocate space for game listing file of %i bytes",size + 1,puVar3);
    }
    puVar3 = (undefined *)FS_Read(pOutput,(int)size,1,file);
    if (puVar3 != size) {
      Sys_Error("Error reading in game listing file, expected %i bytes, read %i",size,puVar3);
    }
    pOutput[(int)size] = '\0';
    com_ignorecolons = true;
    pcVar1 = pOutput;
    while( true ) {
      pcVar1 = COM_Parse(pcVar1);
      iVar2 = Q_strlen(com_token);
      if (iVar2 < 1) break;
      Q_strncpy(local_5c,com_token,0x3f);
      local_1d = 0;
      pcVar1 = COM_Parse(pcVar1);
      Q_strncpy(local_15c,com_token,0xff);
      local_5d = 0;
      iVar2 = Q_stricmp(local_5c,"gamedll_linux");
      if (iVar2 != 0) {
        DLL_SetModKey(&gmodinfo,local_5c,local_15c);
      }
    }
    com_ignorecolons = false;
    Mem_Free(pOutput);
    FS_Close(file);
  }
  return;
}


// SV_ResetRcon_f  @ 0009b960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ResetRcon_f(void)

{
  Q_memset(g_rgRconFailures,0,0xe80);
  return;
}


// SV_RestoreMove  @ 000ba400
/* WARNING: Variable defined which should be unmapped: pos */

void SV_RestoreMove(client_t *host_client)

{
  int iVar1;
  int iVar2;
  client_s *pcVar3;
  int iVar4;
  sv_adjusted_positions_t *pos;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (nofind == false) {
    iVar1 = (*gEntityInterface.pfnAllowLagCompensation)();
    if (((((iVar1 != 0) && (1 < svs.maxclients)) && (sv_unlag.value != 0.0)) &&
        ((host_client->lw != 0 && (host_client->lc != 0)))) && (host_client->active != false)) {
      iVar4 = 0;
      iVar1 = svs.maxclients;
      do {
        pcVar3 = svs.clients + iVar4;
        if ((pcVar3 != host_client) && (pcVar3->active != false)) {
          iVar2 = VectorCompare(truepositions[iVar4].neworg,truepositions[iVar4].oldorg);
          iVar1 = svs.maxclients;
          if ((iVar2 == 0) && (truepositions[iVar4].needrelink != 0)) {
            if (truepositions[iVar4].active == 0) {
              Con_DPrintf("SV_RestoreMove:  Tried to restore \'inactive\' player %i/%s\n",iVar4,
                          pcVar3->name);
              iVar1 = svs.maxclients;
            }
            else {
              iVar2 = VectorCompare(truepositions[iVar4].initial_correction_org,
                                    (pcVar3->edict->v).origin);
              iVar1 = svs.maxclients;
              if (iVar2 != 0) {
                (pcVar3->edict->v).origin[0] = truepositions[iVar4].oldorg[0];
                (pcVar3->edict->v).origin[1] = truepositions[iVar4].oldorg[1];
                (pcVar3->edict->v).origin[2] = truepositions[iVar4].oldorg[2];
                SV_LinkEdict(pcVar3->edict,false);
                iVar1 = svs.maxclients;
              }
            }
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  else {
    nofind = false;
  }
  return;
}


// SV_RunCmd  @ 000ba580
void SV_RunCmd(usercmd_t *ucmd,int random_seed)

{
  float fVar1;
  undefined4 uVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  float frametime;
  client_t *pcVar6;
  model_s *src;
  uint uVar7;
  int iVar8;
  playermove_t *ppVar9;
  edict_t_conflict *peVar10;
  playermove_t *ppVar11;
  edict_t_conflict *peVar12;
  byte bVar13;
  int iVar14;
  pmtrace_t *ppVar15;
  bool bVar16;
  float fVar17;
  trace_t local_b4;
  usercmd_t local_7c;
  float local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: float frametime@[???]
                       Unresolved local var: usercmd_t cmd@[???] */
  pcVar6 = host_client;
  uVar7 = 0;
  do {
    *(undefined4 *)((int)local_7c.viewangles + (uVar7 - 4)) =
         *(undefined4 *)((int)ucmd->viewangles + (uVar7 - 4));
    uVar7 = uVar7 + 4;
  } while (uVar7 < 0x34);
  if (realtime < host_client->ignorecmdtime) {
    host_client->cmdtime = (double)((float)ucmd->msec / 1000.0 + (float)host_client->cmdtime);
    return;
  }
  *(undefined4 *)&host_client->ignorecmdtime = 0;
  *(undefined4 *)((int)&pcVar6->ignorecmdtime + 4) = 0;
  if (50.0 < (float)local_7c.msec) {
                    /* Unresolved local var: float oldmsec@[???] */
    bVar13 = (byte)(int)((float)ucmd->msec * 0.5);
    local_7c.msec = bVar13;
    SV_RunCmd(&local_7c,random_seed);
    local_7c.impulse = '\0';
    local_7c.msec = bVar13;
    SV_RunCmd(&local_7c,random_seed);
    return;
  }
  if (pcVar6->fakeclient == false) {
    SV_SetupMove(pcVar6);
  }
  (*gEntityInterface.pfnCmdStart)((edict_t *)sv_player,ucmd,random_seed);
  peVar12 = sv_player;
  pcVar6 = host_client;
  frametime = (float)ucmd->msec * 0.001;
  host_client->svtimebase = (double)frametime + host_client->svtimebase;
  pcVar6->cmdtime = (double)((float)ucmd->msec / 1000.0 + (float)pcVar6->cmdtime);
  if ((ucmd->impulse != 0) && ((peVar12->v).impulse = (uint)ucmd->impulse, ucmd->impulse == 0xcc)) {
    if (pcVar6->active == false) {
      Con_DPrintf("%s is trying to fullupdate when not active at (%f)\n",pcVar6->name,sv.time);
      peVar12 = sv_player;
    }
    else {
      SV_FullUpdate_Internal();
      peVar12 = sv_player;
    }
  }
  (peVar12->v).clbasevelocity[0] = 0.0;
  (peVar12->v).clbasevelocity[1] = 0.0;
  (peVar12->v).clbasevelocity[2] = 0.0;
  (peVar12->v).button = (uint)ucmd->buttons;
  SV_CheckMovingGround(peVar12,frametime);
  peVar12 = sv_player;
  ppVar11 = pmove;
  pmove->oldangles[0] = (sv_player->v).v_angle[0];
  ppVar11->oldangles[1] = (peVar12->v).v_angle[1];
  ppVar11->oldangles[2] = (peVar12->v).v_angle[2];
  if ((peVar12->v).fixangle == 0) {
    (peVar12->v).v_angle[0] = ucmd->viewangles[0];
    (peVar12->v).v_angle[1] = ucmd->viewangles[1];
    (peVar12->v).v_angle[2] = ucmd->viewangles[2];
  }
  gGlobalVariables.time = (float)host_client->svtimebase;
  (*gEntityInterface.pfnPlayerPreThink)(peVar12);
  peVar12 = sv_player;
  fVar17 = (float)host_client->svtimebase;
                    /* Unresolved local var: float thinktime@[???] */
  uVar7 = (sv_player->v).flags;
  if ((uVar7 & 0x40000000) == 0) {
    if ((((int)uVar7 < 0) || (fVar1 = (sv_player->v).nextthink, fVar1 <= 0.0)) ||
       (frametime + fVar17 < fVar1)) goto LAB_000ba780;
    gGlobalVariables.time = fVar1;
    if (fVar1 < fVar17) {
      gGlobalVariables.time = (float)host_client->svtimebase;
    }
    (sv_player->v).nextthink = 0.0;
    (*gEntityInterface.pfnThink)(peVar12);
    if (((peVar12->v).flags & 0x40000000) == 0) goto LAB_000ba780;
  }
  ED_Free(peVar12);
LAB_000ba780:
  fVar17 = Length((sv_player->v).basevelocity);
  peVar12 = sv_player;
  if (0.0 < fVar17) {
    (sv_player->v).clbasevelocity[0] = (sv_player->v).basevelocity[0];
    (peVar12->v).clbasevelocity[1] = (peVar12->v).basevelocity[1];
    (peVar12->v).clbasevelocity[2] = (peVar12->v).basevelocity[2];
  }
  pcVar6 = host_client;
  ppVar11 = pmove;
  pmove->server = true;
  ppVar11->multiplayer = (uint)(1 < svs.maxclients);
  ppVar11->time = (float)pcVar6->svtimebase * 1000.0;
  ppVar11->usehull = (uint)(((peVar12->v).flags & 0x4000) != 0);
  ppVar11->maxspeed = sv_maxspeed.value;
  ppVar11->clientmaxspeed = (peVar12->v).maxspeed;
  ppVar11->flDuckTime = (float)(peVar12->v).flDuckTime;
  ppVar11->bInDuck = (peVar12->v).bInDuck;
  ppVar11->flTimeStepSound = (peVar12->v).flTimeStepSound;
  ppVar11->iStepLeft = (peVar12->v).iStepLeft;
  ppVar11->flFallVelocity = (peVar12->v).flFallVelocity;
  ppVar11->flSwimTime = (float)(peVar12->v).flSwimTime;
  ppVar11->oldbuttons = (peVar12->v).oldbuttons;
  Q_strncpy(ppVar11->physinfo,pcVar6->physinfo,0xff);
  peVar12 = sv_player;
  ppVar11 = pmove;
  pmove->physinfo[0xff] = '\0';
  ppVar11->velocity[0] = (peVar12->v).velocity[0];
  ppVar11->velocity[1] = (peVar12->v).velocity[1];
  ppVar11->velocity[2] = (peVar12->v).velocity[2];
  ppVar11->movedir[0] = (peVar12->v).movedir[0];
  ppVar11->movedir[1] = (peVar12->v).movedir[1];
  ppVar11->movedir[2] = (peVar12->v).movedir[2];
  ppVar11->angles[0] = (peVar12->v).v_angle[0];
  ppVar11->angles[1] = (peVar12->v).v_angle[1];
  ppVar11->angles[2] = (peVar12->v).v_angle[2];
  ppVar11->basevelocity[0] = (peVar12->v).basevelocity[0];
  ppVar11->basevelocity[1] = (peVar12->v).basevelocity[1];
  ppVar11->basevelocity[2] = (peVar12->v).basevelocity[2];
  ppVar11->view_ofs[0] = (peVar12->v).view_ofs[0];
  ppVar11->view_ofs[1] = (peVar12->v).view_ofs[1];
  ppVar11->view_ofs[2] = (peVar12->v).view_ofs[2];
  ppVar11->punchangle[0] = (peVar12->v).punchangle[0];
  ppVar11->punchangle[1] = (peVar12->v).punchangle[1];
  ppVar11->punchangle[2] = (peVar12->v).punchangle[2];
  ppVar11->deadflag = (peVar12->v).deadflag;
  ppVar11->effects = (peVar12->v).effects;
  ppVar11->gravity = (peVar12->v).gravity;
  ppVar11->friction = (peVar12->v).friction;
  ppVar11->spectator = 0;
  ppVar11->waterjumptime = (peVar12->v).teleport_time;
  uVar7 = 0;
  do {
    *(undefined4 *)((int)(ppVar11->cmd).viewangles + (uVar7 - 4)) =
         *(undefined4 *)((int)local_7c.viewangles + (uVar7 - 4));
    uVar7 = uVar7 + 4;
  } while (uVar7 < 0x34);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t pmove_mins@[???]
                       Unresolved local var: vec3_t pmove_maxs@[???] */
  ppVar11->dead = (uint)((peVar12->v).health <= 0.0);
  ppVar11->movetype = (peVar12->v).movetype;
  ppVar11->flags = (peVar12->v).flags;
  iVar8 = NUM_FOR_EDICT((edict_t *)peVar12);
  ppVar11->player_index = iVar8 + -1;
  peVar12 = sv_player;
  ppVar11 = pmove;
  pmove->iuser1 = (sv_player->v).iuser1;
  ppVar11->iuser2 = (peVar12->v).iuser2;
  ppVar11->iuser3 = (peVar12->v).iuser3;
  ppVar11->iuser4 = (peVar12->v).iuser4;
  ppVar11->fuser1 = (peVar12->v).fuser1;
  ppVar11->fuser2 = (peVar12->v).fuser2;
  ppVar11->fuser3 = (peVar12->v).fuser3;
  ppVar11->fuser4 = (peVar12->v).fuser4;
  ppVar11->vuser1[0] = (peVar12->v).vuser1[0];
  ppVar11->vuser1[1] = (peVar12->v).vuser1[1];
  ppVar11->vuser1[2] = (peVar12->v).vuser1[2];
  ppVar11->vuser2[0] = (peVar12->v).vuser2[0];
  ppVar11->vuser2[1] = (peVar12->v).vuser2[1];
  ppVar11->vuser2[2] = (peVar12->v).vuser2[2];
  ppVar11->vuser3[0] = (peVar12->v).vuser3[0];
  ppVar11->vuser3[1] = (peVar12->v).vuser3[1];
  ppVar11->vuser3[2] = (peVar12->v).vuser3[2];
  ppVar11->vuser4[0] = (peVar12->v).vuser4[0];
  ppVar11->vuser4[1] = (peVar12->v).vuser4[1];
  ppVar11->vuser4[2] = (peVar12->v).vuser4[2];
  ppVar11->origin[0] = (peVar12->v).origin[0];
  ppVar11->origin[1] = (peVar12->v).origin[1];
  ppVar11->origin[2] = (peVar12->v).origin[2];
  Q_memset(ppVar11->physents,0,0xe0);
  Q_memset(pmove->visents,0,0xe0);
  src = sv.worldmodel;
  ppVar9 = pmove;
  bVar16 = sv.worldmodel != (model_s *)0x0;
  pmove->physents[0].model = sv.worldmodel;
  if (bVar16) {
    Q_strncpy(ppVar9->physents[0].name,src->name,0x20);
    ppVar9 = pmove;
    pmove->physents[0].name[0x1f] = '\0';
  }
  vVar3 = vec3_origin[0];
  ppVar9->physents[0].info = 0;
  ppVar9->physents[0].solid = 4;
  ppVar9->numphysent = 1;
  ppVar9->physents[0].origin[0] = vVar3;
  vVar3 = vec3_origin[1];
  ppVar9->numvisent = 1;
  ppVar9->physents[0].movetype = 0;
  ppVar9->physents[0].takedamage = 1;
  ppVar9->physents[0].origin[1] = vVar3;
  ppVar9->physents[0].origin[2] = vec3_origin[2];
  ppVar9->physents[0].blooddecal = 0;
  uVar7 = 0;
  do {
    uVar2 = *(undefined4 *)(ppVar9->physents[0].name + uVar7 + 4);
    *(undefined4 *)(ppVar9->visents[0].name + uVar7) =
         *(undefined4 *)(ppVar9->physents[0].name + uVar7);
    *(undefined4 *)(ppVar9->visents[0].name + uVar7 + 4) = uVar2;
    uVar7 = uVar7 + 8;
  } while (uVar7 < 0xe0);
  ppVar9->nummoveent = 0;
  local_3c = ppVar11->origin[0] - 256.0;
  local_2c = ppVar11->origin[0] + 256.0;
  local_38 = ppVar11->origin[1] - 256.0;
  local_28 = ppVar11->origin[1] + 256.0;
  local_34 = ppVar11->origin[2] - 256.0;
  local_24 = ppVar11->origin[2] + 256.0;
  SV_AddLinksToPM_(sv_areanodes,&local_3c,&local_2c);
  ppVar11 = pmove;
  pmove->runfuncs = true;
  ppVar11->PM_PlaySound = PM_SV_PlaySound;
  ppVar11->frametime = frametime;
  ppVar11->PM_TraceTexture = PM_SV_TraceTexture;
  ppVar11->PM_PlaybackEventFull = PM_SV_PlaybackEventFull;
  (*gEntityInterface.pfnPM_Move)(ppVar11,true);
  peVar12 = sv_player;
  ppVar11 = pmove;
  (sv_player->v).deadflag = pmove->deadflag;
  (peVar12->v).effects = ppVar11->effects;
  (peVar12->v).teleport_time = ppVar11->waterjumptime;
  (peVar12->v).waterlevel = ppVar11->waterlevel;
  (peVar12->v).watertype = ppVar11->watertype;
  uVar7 = ppVar11->flags;
  (peVar12->v).flags = uVar7;
  (peVar12->v).friction = ppVar11->friction;
  (peVar12->v).movetype = ppVar11->movetype;
  (peVar12->v).maxspeed = ppVar11->clientmaxspeed;
  (peVar12->v).iStepLeft = ppVar11->iStepLeft;
  (peVar12->v).view_ofs[0] = ppVar11->view_ofs[0];
  (peVar12->v).view_ofs[1] = ppVar11->view_ofs[1];
  (peVar12->v).view_ofs[2] = ppVar11->view_ofs[2];
  (peVar12->v).movedir[0] = ppVar11->movedir[0];
  (peVar12->v).movedir[1] = ppVar11->movedir[1];
  (peVar12->v).movedir[2] = ppVar11->movedir[2];
  (peVar12->v).punchangle[0] = ppVar11->punchangle[0];
  (peVar12->v).punchangle[1] = ppVar11->punchangle[1];
  (peVar12->v).punchangle[2] = ppVar11->punchangle[2];
  if (ppVar11->onground == -1) {
    (peVar12->v).flags = uVar7 & 0xfffffdff;
  }
  else {
    (peVar12->v).flags = uVar7 | 0x200;
    peVar10 = EDICT_NUM(ppVar11->physents[ppVar11->onground].info);
    (peVar12->v).groundentity = peVar10;
    ppVar11 = pmove;
    peVar12 = sv_player;
  }
  (peVar12->v).origin[0] = ppVar11->origin[0];
  (peVar12->v).origin[1] = ppVar11->origin[1];
  (peVar12->v).origin[2] = ppVar11->origin[2];
  (peVar12->v).velocity[0] = ppVar11->velocity[0];
  (peVar12->v).velocity[1] = ppVar11->velocity[1];
  (peVar12->v).velocity[2] = ppVar11->velocity[2];
  (peVar12->v).basevelocity[0] = ppVar11->basevelocity[0];
  (peVar12->v).basevelocity[1] = ppVar11->basevelocity[1];
  (peVar12->v).basevelocity[2] = ppVar11->basevelocity[2];
  if ((peVar12->v).fixangle == 0) {
    (peVar12->v).v_angle[0] = ppVar11->angles[0];
    (peVar12->v).v_angle[1] = ppVar11->angles[1];
    (peVar12->v).v_angle[2] = ppVar11->angles[2];
    (peVar12->v).angles[0] = ppVar11->angles[0];
    (peVar12->v).angles[1] = ppVar11->angles[1];
    (peVar12->v).angles[2] = ppVar11->angles[2];
    (peVar12->v).angles[0] = -ppVar11->angles[0] / 3.0;
  }
  (peVar12->v).bInDuck = ppVar11->bInDuck;
  (peVar12->v).flDuckTime = (int)ppVar11->flDuckTime;
  (peVar12->v).flTimeStepSound = ppVar11->flTimeStepSound;
  (peVar12->v).flFallVelocity = ppVar11->flFallVelocity;
  (peVar12->v).flSwimTime = (int)ppVar11->flSwimTime;
  (peVar12->v).oldbuttons = (uint)(ppVar11->cmd).buttons;
  (peVar12->v).iuser1 = ppVar11->iuser1;
  (peVar12->v).iuser2 = ppVar11->iuser2;
  (peVar12->v).iuser3 = ppVar11->iuser3;
  (peVar12->v).iuser4 = ppVar11->iuser4;
  (peVar12->v).fuser1 = ppVar11->fuser1;
  (peVar12->v).fuser2 = ppVar11->fuser2;
  (peVar12->v).fuser3 = ppVar11->fuser3;
  (peVar12->v).fuser4 = ppVar11->fuser4;
  (peVar12->v).vuser1[0] = ppVar11->vuser1[0];
  (peVar12->v).vuser1[1] = ppVar11->vuser1[1];
  (peVar12->v).vuser1[2] = ppVar11->vuser1[2];
  (peVar12->v).vuser2[0] = ppVar11->vuser2[0];
  (peVar12->v).vuser2[1] = ppVar11->vuser2[1];
  (peVar12->v).vuser2[2] = ppVar11->vuser2[2];
  (peVar12->v).vuser3[0] = ppVar11->vuser3[0];
  (peVar12->v).vuser3[1] = ppVar11->vuser3[1];
  (peVar12->v).vuser3[2] = ppVar11->vuser3[2];
  (peVar12->v).vuser4[0] = ppVar11->vuser4[0];
  (peVar12->v).vuser4[1] = ppVar11->vuser4[1];
  (peVar12->v).vuser4[2] = ppVar11->vuser4[2];
  SetMinMaxSize(peVar12,player_mins[ppVar11->usehull],player_maxs[ppVar11->usehull],false);
  peVar12 = sv_player;
  if ((host_client->edict->v).solid != 0) {
                    /* Unresolved local var: vec3_t vel@[???]
                       Unresolved local var: pmtrace_t * tr@[???] */
    SV_LinkEdict(sv_player,true);
    vVar3 = (sv_player->v).velocity[1];
    vVar4 = (sv_player->v).velocity[0];
    vVar5 = (sv_player->v).velocity[2];
    if (0 < pmove->numtouch) {
      iVar8 = 0;
      do {
        iVar14 = iVar8 + 1;
        local_b4.ent = EDICT_NUM(pmove->physents[pmove->touchindex[iVar8].ent].info);
        peVar12 = sv_player;
        ppVar15 = pmove->touchindex + iVar8;
        local_b4.allsolid = ppVar15->allsolid;
        local_b4.startsolid = ppVar15->startsolid;
        local_b4.inopen = ppVar15->inopen;
        local_b4.inwater = ppVar15->inwater;
        local_b4.fraction = ppVar15->fraction;
        local_b4.endpos[0] = ppVar15->endpos[0];
        local_b4.endpos[1] = ppVar15->endpos[1];
        local_b4.endpos[2] = ppVar15->endpos[2];
        local_b4.plane.normal[0] = (ppVar15->plane).normal[0];
        local_b4.plane.normal[1] = (ppVar15->plane).normal[1];
        local_b4.plane.normal[2] = (ppVar15->plane).normal[2];
        local_b4.plane.dist = (ppVar15->plane).dist;
        local_b4.hitgroup = ppVar15->hitgroup;
        (sv_player->v).velocity[0] = ppVar15->deltavelocity[0];
        (peVar12->v).velocity[1] = ppVar15->deltavelocity[1];
        (peVar12->v).velocity[2] = ppVar15->deltavelocity[2];
        SV_Impact(local_b4.ent,peVar12,&local_b4);
        iVar8 = iVar14;
      } while (iVar14 < pmove->numtouch);
    }
    peVar12 = sv_player;
    (sv_player->v).velocity[0] = vVar4;
    (peVar12->v).velocity[1] = vVar3;
    (peVar12->v).velocity[2] = vVar5;
  }
  gGlobalVariables.time = (float)host_client->svtimebase;
  gGlobalVariables.frametime = frametime;
  (*gEntityInterface.pfnPlayerPostThink)(peVar12);
  (*gEntityInterface.pfnCmdEnd)((edict_t *)sv_player);
  if (host_client->fakeclient != false) {
    return;
  }
  SV_RestoreMove(host_client);
  return;
}


// SV_RunThink  @ 000b1be0
qboolean SV_RunThink(edict_t_conflict *ent)

{
  longdouble lVar1;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar1 = (longdouble)(ent->v).nextthink;
    if (lVar1 <= (longdouble)0) {
      return true;
    }
    if ((longdouble)host_frametime + (longdouble)sv.time < lVar1) {
      return true;
    }
    if (lVar1 < (longdouble)sv.time) {
      lVar1 = (longdouble)(float)sv.time;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar1;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) == 0) goto LAB_000b1bf9;
  }
                    /* Unresolved local var: float thinktime@[???] */
  ED_Free(ent);
LAB_000b1bf9:
  return (uint)(ent->free == 0);
}


// SV_SendBan  @ 000a2ed0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendBan(void)

{
  netadr_t to;
  char local_4c [72];
  
                    /* Unresolved local var: char[64] szMessage@[???] */
  snprintf(local_4c,0x40,"You have been banned from this server.\n");
  SZ_Clear(&net_message);
  MSG_WriteLong(&net_message,-1);
  MSG_WriteByte(&net_message,0x6c);
  MSG_WriteString(&net_message,local_4c);
  to.ip[0] = net_from.ip[0];
  to.ip[1] = net_from.ip[1];
  to.ip[2] = net_from.ip[2];
  to.ip[3] = net_from.ip[3];
  to.type = net_from.type;
  to.ipx[0] = net_from.ipx[0];
  to.ipx[1] = net_from.ipx[1];
  to.ipx[2] = net_from.ipx[2];
  to.ipx[3] = net_from.ipx[3];
  to.ipx[4] = net_from.ipx[4];
  to.ipx[5] = net_from.ipx[5];
  to.ipx[6] = net_from.ipx[6];
  to.ipx[7] = net_from.ipx[7];
  to.ipx[8] = net_from.ipx[8];
  to.ipx[9] = net_from.ipx[9];
  to.port = net_from.port;
  NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,to);
  SZ_Clear(&net_message);
  return;
}


// SV_SendClientDatagram  @ 000a57b0
qboolean SV_SendClientDatagram(client_t *client)

{
  byte local_fc0 [4000];
  sizebuf_t local_20;
  
                    /* Unresolved local var: uchar[4000] buf@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  local_20.maxsize = 4000;
  local_20.cursize = 0;
  local_20.buffername = "Client Datagram";
  local_20.flags = 1;
  local_20.data = local_fc0;
  MSG_WriteByte(&local_20,7);
  MSG_WriteFloat(&local_20,(float)sv.time);
  SV_WriteClientdataToMessage(client,&local_20);
  SV_WriteEntitiesToClient(client,&local_20);
  if (((client->datagram).flags & 2) == 0) {
    SZ_Write(&local_20,(client->datagram).data,(client->datagram).cursize);
  }
  else {
    Con_Printf("WARNING: datagram overflowed for %s\n",client->name);
  }
  SZ_Clear(&client->datagram);
  if ((local_20.flags & 2) != 0) {
    Con_Printf("WARNING: msg overflowed for %s\n",client->name);
    SZ_Clear(&local_20);
  }
  Netchan_Transmit(&client->netchan,local_20.cursize,local_fc0);
  return true;
}


// SV_SendClientMessages  @ 000a6280
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendClientMessages(void)

{
  uint *puVar1;
  double dVar2;
  qboolean *pqVar3;
  client_t *pcVar4;
  qboolean qVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???] */
  SV_UpdateToReliableMessages();
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar7 = 0;
    iVar6 = svs.maxclients;
LAB_000a62c3:
    do {
      pcVar4 = host_client;
      pqVar3 = &host_client->active;
      if ((((*pqVar3 != false) || (host_client->connected != false)) ||
          (host_client->spawned != false)) && (host_client->fakeclient == false)) {
        if (host_client->skip_message == false) {
          if ((host_limitlocal.value == 0.0) &&
             ((host_client->netchan).remote_address.type == NA_LOOPBACK)) {
            host_client->send_message = true;
          }
          if (((*pqVar3 != false) && (pcVar4->spawned != false)) &&
             ((pcVar4->fully_connected != false &&
              (pcVar4->next_messagetime <= realtime + host_frametime)))) {
            pcVar4->send_message = true;
          }
          if (((pcVar4->netchan).message.flags & 2) == 0) {
            if (pcVar4->send_message == false) goto LAB_000a62b0;
            if ((double)sv_failuretime.value < realtime - (double)(pcVar4->netchan).last_received) {
              iVar7 = iVar7 + 1;
              pcVar4->send_message = false;
              host_client = pcVar4 + 1;
              if (iVar6 <= iVar7) break;
              goto LAB_000a62c3;
            }
          }
          else {
            SZ_Clear(&(pcVar4->netchan).message);
            SZ_Clear(&host_client->datagram);
            SV_BroadcastPrintf("%s overflowed\n",host_client->name);
            Con_Printf("WARNING: reliable overflow for %s\n",host_client->name);
            SV_DropClient(host_client,false,"Reliable channel overflowed");
            pcVar4 = host_client;
            host_client->send_message = true;
            *(undefined4 *)&(pcVar4->netchan).cleartime = 0;
            *(undefined4 *)((int)&(pcVar4->netchan).cleartime + 4) = 0;
          }
          qVar5 = Netchan_CanPacket(&pcVar4->netchan);
          pcVar4 = host_client;
          if (qVar5 == false) {
            host_client->chokecount = host_client->chokecount + 1;
            iVar6 = svs.maxclients;
          }
          else {
            dVar2 = realtime + host_frametime;
            qVar5 = host_client->active;
            host_client->send_message = false;
            pcVar4->next_messagetime = dVar2 + pcVar4->next_messageinterval;
            if (((qVar5 == false) || (pcVar4->spawned == false)) ||
               (pcVar4->fully_connected == false)) {
              Netchan_Transmit(&pcVar4->netchan,0,(byte *)0x0);
              pcVar4 = host_client;
              iVar6 = svs.maxclients;
            }
            else {
              SV_SendClientDatagram(pcVar4);
              pcVar4 = host_client;
              iVar6 = svs.maxclients;
            }
          }
        }
        else {
          host_client->skip_message = false;
        }
      }
LAB_000a62b0:
      iVar7 = iVar7 + 1;
      host_client = pcVar4 + 1;
    } while (iVar7 < iVar6);
  }
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: edict_t.conflict * ent@[???] */
  if (1 < sv.num_edicts) {
    iVar7 = 1;
    iVar6 = 0x324;
    do {
      iVar7 = iVar7 + 1;
      puVar1 = (uint *)((int)((sv.edicts)->v).size + iVar6 + 0x24);
      *puVar1 = *puVar1 & 0xffffffdd;
      iVar6 = iVar6 + 0x324;
    } while (iVar7 < sv.num_edicts);
  }
  return;
}


// SV_SendConsistencyList  @ 000b8980
void SV_SendConsistencyList(sizebuf_t *msg)

{
  client_t *pcVar1;
  uint32 uVar2;
  int iVar3;
  uint32 data;
  bool bVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: int lastcheck@[???]
                       Unresolved local var: int delta@[DW_OP_reg6(ESI)] */
  pcVar1 = host_client;
  bVar4 = svs.maxclients != 1;
  host_client->has_force_unmodified = false;
  if ((((bVar4) && (mp_consistency.value != 0.0)) && (sv.num_consistency != 0)) &&
     (pcVar1->proxy == false)) {
    pcVar1->has_force_unmodified = true;
    MSG_WriteBits(1,1);
    if (0 < sv.num_resources) {
      uVar2 = 0;
      data = 0;
      iVar3 = sv.num_resources;
      do {
        if ((char)sv.resourcelist[data].ucFlags < '\0') {
          MSG_WriteBits(1,1);
          if ((int)(data - uVar2) < 0x20) {
            MSG_WriteBits(1,1);
            MSG_WriteBits(data - uVar2,5);
            uVar2 = data;
            iVar3 = sv.num_resources;
          }
          else {
            MSG_WriteBits(0,1);
            MSG_WriteBits(data,10);
            uVar2 = data;
            iVar3 = sv.num_resources;
          }
        }
        data = data + 1;
      } while ((int)data < iVar3);
    }
  }
  MSG_WriteBits(0,1);
  return;
}


// SV_SendEnts_f  @ 000bbc10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendEnts_f(void)

{
  if (cmd_source != src_command) {
    if (((host_client->active != false) && (host_client->spawned != false)) &&
       (host_client->connected != false)) {
      host_client->fully_connected = true;
    }
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// SV_SendRes_f  @ 0009e7c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendRes_f(void)

{
  byte abStack_10020 [65536];
  sizebuf_t local_20;
  
                    /* Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  Q_memset(&local_20,0,0x14);
  local_20.buffername = "SendResources";
  local_20.data = abStack_10020;
  local_20.cursize = 0;
  local_20.maxsize = 0x10000;
  if (cmd_source != src_command) {
    if ((host_client->spawned != false) && (host_client->active == false)) {
      return;
    }
    if ((svs.maxclients < 2) || (host_client->m_sendrescount < 2)) {
      host_client->m_sendrescount = host_client->m_sendrescount + 1;
      SV_SendResources(&local_20);
      Netchan_CreateFragments(true,&host_client->netchan,&local_20);
      Netchan_FragSend(&host_client->netchan);
      return;
    }
  }
  return;
}


// SV_SendResources  @ 0009e590
void SV_SendResources(sizebuf_t *msg)

{
  uchar *m1;
  int iVar1;
  size_t sVar2;
  int iVar3;
  resourcetype_t *prVar4;
  undefined1 local_3c [44];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[32] nullbuffer@[???] */
  Q_memset(local_3c,0,0x20);
  MSG_WriteByte(msg,0x2d);
  MSG_WriteLong(msg,svs.spawncount);
  MSG_WriteLong(msg,0);
  if ((sv_downloadurl.string != (char *)0x0) && (*sv_downloadurl.string != '\0')) {
    sVar2 = strlen(sv_downloadurl.string);
    if (sVar2 < 0x80) {
      MSG_WriteByte(msg,0x38);
      MSG_WriteString(msg,sv_downloadurl.string);
    }
  }
  MSG_WriteByte(msg,0x2b);
  MSG_StartBitWriting(msg);
  MSG_WriteBits(sv.num_resources,0xc);
  if (0 < sv.num_resources) {
    prVar4 = &sv.resourcelist[0].type;
    iVar3 = 0;
    do {
      while( true ) {
        MSG_WriteBits(*prVar4,4);
        MSG_WriteBitString(sv.resourcelist[iVar3].szFileName);
        MSG_WriteBits(prVar4[1],0xc);
        MSG_WriteBits(prVar4[2],0x18);
        MSG_WriteBits(*(byte *)(prVar4 + 3) & 3,3);
        if ((*(byte *)(prVar4 + 3) & 4) != 0) {
          MSG_WriteBitData(sv.resourcelist[iVar3].rgucMD5_hash,0x10);
        }
        m1 = sv.resourcelist[iVar3].rguc_reserved;
        iVar1 = Q_memcmp(m1,local_3c,0x20);
        if (iVar1 != 0) break;
        iVar3 = iVar3 + 1;
        prVar4 = prVar4 + 0x22;
        MSG_WriteBits(0,1);
        if (sv.num_resources <= iVar3) goto LAB_0009e740;
      }
      iVar3 = iVar3 + 1;
      prVar4 = prVar4 + 0x22;
      MSG_WriteBits(1,1);
      MSG_WriteBitData(m1,0x20);
    } while (iVar3 < sv.num_resources);
  }
LAB_0009e740:
  SV_SendConsistencyList(msg);
  MSG_EndBitWriting(msg);
  return;
}


// SV_SendServerinfo  @ 0009e230
void SV_SendServerinfo(sizebuf_t *msg,client_t *client)

{
  int iVar1;
  int iVar2;
  char *s;
  uchar *s_00;
  uint c;
  char local_82c [2048];
  int local_2c [3];
  CRC32_t local_20 [4];
  
                    /* Unresolved local var: char[2048] message@[???]
                       Unresolved local var: int ffirstsent@[???]
                       Unresolved local var: int playernum@[???]
                       Unresolved local var: char * mapcyclelist@[???]
                       Unresolved local var: int len@[???] */
  if ((developer.value != 0.0) || (1 < svs.maxclients)) {
    MSG_WriteByte(msg,8);
    iVar2 = svs.spawncount;
    iVar1 = build_number();
    snprintf(local_82c,0x800,"%c\nBUILD %d SERVER (%i CRC)\nServer # %i\n",2,iVar1,0,iVar2);
    MSG_WriteString(msg,local_82c);
  }
  MSG_WriteByte(msg,0xb);
  MSG_WriteLong(msg,0x30);
  MSG_WriteLong(msg,svs.spawncount);
  iVar2 = NUM_FOR_EDICT((edict_t *)client->edict);
                    /* Unresolved local var: int mungebuffer@[???] */
  local_20[0] = sv.worldmapCRC;
  COM_Munge3((uchar *)local_20,4,0x100U - iVar2 & 0xff);
  MSG_WriteLong(msg,local_20[0]);
  MSG_WriteBuf(msg,0x10,sv.clientdllmd5);
  MSG_WriteByte(msg,svs.maxclients);
  MSG_WriteByte(msg,iVar2 + -1);
  if ((coop.value == 0.0) && (deathmatch.value != 0.0)) {
    MSG_WriteByte(msg,1);
  }
  else {
    MSG_WriteByte(msg,0);
  }
  COM_FileBase(com_gamedir,local_82c);
  MSG_WriteString(msg,local_82c);
  s = Cvar_VariableString("hostname");
  MSG_WriteString(msg,s);
  MSG_WriteString(msg,sv.modelname);
  s_00 = COM_LoadFileForMe(mapcyclefile.string,local_2c);
  if ((s_00 == (uchar *)0x0) || (local_2c[0] == 0)) {
    MSG_WriteString(msg,"mapcycle failure");
  }
  else {
    if (0x2000 < local_2c[0]) {
      local_2c[0] = 0x2000;
      s_00[0x1fff] = '\0';
    }
    MSG_WriteString(msg,(char *)s_00);
    COM_FreeFile(s_00);
  }
  MSG_WriteByte(msg,0);
  MSG_WriteByte(msg,0x36);
  MSG_WriteString(msg,com_clientfallback);
  c = 1;
  if (sv_cheats.value == 0.0) {
    c = (uint)NAN(sv_cheats.value);
  }
  MSG_WriteByte(msg,c);
  SV_WriteDeltaDescriptionsToClient(msg);
  SV_SetMoveVars();
  SV_WriteMovevarsToClient(msg);
  MSG_WriteByte(msg,0x20);
  MSG_WriteByte(msg,gGlobalVariables.cdAudioTrack);
  MSG_WriteByte(msg,gGlobalVariables.cdAudioTrack);
  MSG_WriteByte(msg,5);
  iVar2 = NUM_FOR_EDICT((edict_t *)client->edict);
  MSG_WriteShort(msg,iVar2);
  client->spawned = false;
  client->connected = true;
  client->fully_connected = false;
  return;
}


// SV_SendUserReg  @ 0009ec80
void SV_SendUserReg(sizebuf_t *msg)

{
  _UserMsg *p_Var1;
  
  for (p_Var1 = sv_gpNewUserMsgs; p_Var1 != (UserMsg *)0x0; p_Var1 = p_Var1->next) {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
    MSG_WriteByte(msg,0x27);
    MSG_WriteByte(msg,p_Var1->iMsg);
    MSG_WriteByte(msg,p_Var1->iSize);
    MSG_WriteLong(msg,*(int *)p_Var1->szName);
    MSG_WriteLong(msg,*(int *)(p_Var1->szName + 4));
    MSG_WriteLong(msg,*(int *)(p_Var1->szName + 8));
    MSG_WriteLong(msg,*(int *)(p_Var1->szName + 0xc));
  }
  return;
}


// SV_ServerLog_f  @ 0009b840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ServerLog_f(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    pcVar2 = Cmd_Argv(1);
    iVar1 = Q_stricmp(pcVar2,"off");
    if (iVar1 == 0) {
      if (svs.log.active != false) {
        if (svs.log.file != (void *)0x0) {
          Log_Printf("Log file closed\n");
          FS_Close(svs.log.file);
          svs.log.file = (void *)0x0;
        }
        Con_Printf("Server logging disabled.\n");
        svs.log.active = false;
        return;
      }
    }
    else {
      pcVar2 = Cmd_Argv(1);
      iVar1 = Q_stricmp(pcVar2,"on");
      if (iVar1 == 0) {
        svs.log.active = true;
        Log_Open();
        return;
      }
      pcVar2 = Cmd_Argv(1);
      Con_Printf("log:  unknown parameter %s, \'on\' and \'off\' are valid\n",pcVar2);
    }
  }
  else {
    Con_Printf("usage:  log < on | off >\n");
    if (svs.log.active != false) {
      Con_Printf("currently logging\n");
      return;
    }
    Con_Printf("not currently logging\n");
  }
  return;
}


// SV_ServerShutdown  @ 000a7cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ServerShutdown(void)

{
  Steam_NotifyOfLevelChange();
  gGlobalVariables.time = (float)sv.time;
  if ((svs.dll_initialized != false) && (sv.active != false)) {
                    /* WARNING: Could not recover jumptable at 0x000a7d08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEntityInterface.pfnServerDeactivate)();
    return;
  }
  return;
}


// SV_Serverinfo_f  @ 000a7480
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Serverinfo_f(void)

{
  int iVar1;
  char *pcVar2;
  char *key;
  char *s;
  cvar_t *pcVar3;
  float fVar4;
  
                    /* Unresolved local var: cvar_t * var@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Server info settings:\n");
    pcVar2 = Info_Serverinfo();
    Info_Print(pcVar2);
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    if (*pcVar2 != '*') {
                    /* Unresolved local var: cvar_t * var@[???] */
      pcVar2 = Cmd_Argv(2);
      key = Cmd_Argv(1);
      s = Info_Serverinfo();
      Info_SetValueForKey(s,key,pcVar2,0x200);
      pcVar2 = Cmd_Argv(1);
      pcVar3 = Cvar_FindVar(pcVar2);
      if (pcVar3 != (cvar_t *)0x0) {
        Z_Free(pcVar3->string);
        pcVar2 = Cmd_Argv(2);
        pcVar2 = CopyString(pcVar2);
        pcVar3->string = pcVar2;
        fVar4 = Q_atof(pcVar2);
        pcVar3->value = fVar4;
      }
      pcVar2 = Info_Serverinfo();
      SV_BroadcastCommand("fullserverinfo \"%s\"\n",pcVar2);
      return;
    }
    Con_Printf("Star variables cannot be changed.\n");
  }
  else {
    Con_Printf("usage: serverinfo [ <key> <value> ]\n");
  }
  return;
}


// SV_SetCallback  @ 000a4280
void SV_SetCallback(int num,qboolean remove,qboolean custom,int *numbase,qboolean full,int offset)

{
  g_svdeltacallback.num = num;
  g_svdeltacallback.remove = remove;
  g_svdeltacallback.custom = custom;
  g_svdeltacallback.numbase = numbase;
  g_svdeltacallback.newbl = false;
  g_svdeltacallback.newblindex = 0;
  g_svdeltacallback.full = full;
  g_svdeltacallback.offset = offset;
  return;
}


// SV_SetGlobalTrace  @ 0008cb90
void SV_SetGlobalTrace(trace_t *ptrace)

{
  gGlobalVariables.trace_allsolid = (float)ptrace->allsolid;
  gGlobalVariables.trace_startsolid = (float)ptrace->startsolid;
  gGlobalVariables.trace_fraction = ptrace->fraction;
  gGlobalVariables.trace_inwater = (float)ptrace->inwater;
  gGlobalVariables.trace_inopen = (float)ptrace->inopen;
  gGlobalVariables.trace_endpos[0] = ptrace->endpos[0];
  gGlobalVariables.trace_endpos[1] = ptrace->endpos[1];
  gGlobalVariables.trace_endpos[2] = ptrace->endpos[2];
  gGlobalVariables.trace_plane_normal[0] = (ptrace->plane).normal[0];
  gGlobalVariables.trace_plane_normal[1] = (ptrace->plane).normal[1];
  gGlobalVariables.trace_plane_normal[2] = (ptrace->plane).normal[2];
  gGlobalVariables.trace_plane_dist = (ptrace->plane).dist;
  gGlobalVariables.trace_ent = ptrace->ent;
  if (ptrace->ent == (edict_t_conflict *)0x0) {
    gGlobalVariables.trace_ent = sv.edicts;
  }
  gGlobalVariables.trace_hitgroup = ptrace->hitgroup;
  return;
}


// SV_SetLogAddress_f  @ 0009b1d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SetLogAddress_f(void)

{
  netadr_t a;
  netadr_t a_00;
  int iVar1;
  char *str;
  char *pcVar2;
  qboolean qVar3;
  char local_124 [260];
  netadr_t local_20;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nPort@[???]
                       Unresolved local var: char[260] szAdr@[???]
                       Unresolved local var: netadr_t adr@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    str = Cmd_Argv(2);
    iVar1 = Q_atoi(str);
    if (iVar1 == 0) {
      Con_Printf("logaddress:  must specify a valid port\n");
    }
    else if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
      Con_Printf("logaddress:  unparseable address\n");
    }
    else {
      snprintf(local_124,0x104,"%s:%i",pcVar2,iVar1);
      qVar3 = NET_StringToAdr(local_124,&local_20);
      if (qVar3 == false) {
        Con_Printf("logaddress:  unable to resolve %s\n",local_124);
      }
      else {
        svs.log.net_log = true;
        svs.log.net_address.type = local_20.type;
        svs.log.net_address.ip[0] = local_20.ip[0];
        svs.log.net_address.ip[1] = local_20.ip[1];
        svs.log.net_address.ip[2] = local_20.ip[2];
        svs.log.net_address.ip[3] = local_20.ip[3];
        svs.log.net_address.ipx[0] = local_20.ipx[0];
        svs.log.net_address.ipx[1] = local_20.ipx[1];
        svs.log.net_address.ipx[2] = local_20.ipx[2];
        svs.log.net_address.ipx[3] = local_20.ipx[3];
        svs.log.net_address.ipx[4] = local_20.ipx[4];
        svs.log.net_address.ipx[5] = local_20.ipx[5];
        svs.log.net_address.ipx[6] = local_20.ipx[6];
        svs.log.net_address.ipx[7] = local_20.ipx[7];
        svs.log.net_address.ipx[8] = local_20.ipx[8];
        svs.log.net_address.ipx[9] = local_20.ipx[9];
        svs.log.net_address.port = local_20.port;
        a_00.ip[0] = local_20.ip[0];
        a_00.ip[1] = local_20.ip[1];
        a_00.ip[2] = local_20.ip[2];
        a_00.ip[3] = local_20.ip[3];
        a_00.type = local_20.type;
        a_00.ipx[0] = local_20.ipx[0];
        a_00.ipx[1] = local_20.ipx[1];
        a_00.ipx[2] = local_20.ipx[2];
        a_00.ipx[3] = local_20.ipx[3];
        a_00.ipx[4] = local_20.ipx[4];
        a_00.ipx[5] = local_20.ipx[5];
        a_00.ipx[6] = local_20.ipx[6];
        a_00.ipx[7] = local_20.ipx[7];
        a_00.ipx[8] = local_20.ipx[8];
        a_00.ipx[9] = local_20.ipx[9];
        a_00.port = local_20.port;
        pcVar2 = NET_AdrToString(a_00);
        Con_Printf("logaddress:  %s\n",pcVar2);
      }
    }
  }
  else {
    Con_Printf("logaddress:  usage\nlogaddress ip port\n");
    if (svs.log.active != false) {
      a.ip[0] = svs.log.net_address.ip[0];
      a.ip[1] = svs.log.net_address.ip[1];
      a.ip[2] = svs.log.net_address.ip[2];
      a.ip[3] = svs.log.net_address.ip[3];
      a.type = svs.log.net_address.type;
      a.ipx[0] = svs.log.net_address.ipx[0];
      a.ipx[1] = svs.log.net_address.ipx[1];
      a.ipx[2] = svs.log.net_address.ipx[2];
      a.ipx[3] = svs.log.net_address.ipx[3];
      a.ipx[4] = svs.log.net_address.ipx[4];
      a.ipx[5] = svs.log.net_address.ipx[5];
      a.ipx[6] = svs.log.net_address.ipx[6];
      a.ipx[7] = svs.log.net_address.ipx[7];
      a.ipx[8] = svs.log.net_address.ipx[8];
      a.ipx[9] = svs.log.net_address.ipx[9];
      a.port = svs.log.net_address.port;
      pcVar2 = NET_AdrToString(a);
      Con_Printf("current:  %s\n",pcVar2);
    }
  }
  return;
}


// SV_SetMaxclients  @ 000a9580
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SetMaxclients(void)

{
  entity_state_s *p;
  client_s *pcVar1;
  client_frame_t *pcVar2;
  float value;
  int iVar3;
  client_s *local_24;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  local_24 = svs.clients;
  if (0 < svs.maxclientslimit) {
    local_20 = 0;
    iVar3 = svs.maxclientslimit;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
      pcVar2 = local_24->frames;
      if (pcVar2 != (client_frame_t *)0x0) {
        if (0 < SV_UPDATE_BACKUP) {
          iVar3 = 0;
          do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
            if (pcVar2 != (client_frame_t *)0x0) {
              p = (pcVar2->entities).entities;
              if (p != (entity_state_s *)0x0) {
                Mem_Free(p);
              }
              (pcVar2->entities).entities = (entity_state_s *)0x0;
              (pcVar2->entities).num_entities = 0;
            }
            *(undefined4 *)&pcVar2->senttime = 0;
            iVar3 = iVar3 + 1;
            *(undefined4 *)((int)&pcVar2->senttime + 4) = 0;
            pcVar2->ping_time = -1.0;
            pcVar2 = pcVar2 + 1;
          } while (iVar3 < SV_UPDATE_BACKUP);
          pcVar2 = local_24->frames;
        }
        Mem_Free(pcVar2);
        local_24->frames = (client_frame_t *)0x0;
        iVar3 = svs.maxclientslimit;
      }
      local_20 = local_20 + 1;
      local_24 = local_24 + 1;
    } while (local_20 < iVar3);
  }
  svs.maxclients = 1;
  iVar3 = COM_CheckParm("-maxplayers");
  if (iVar3 == 0) {
    if (g_bIsDedicatedServer != false) {
      svs.maxclients = 6;
      cls.state = ca_dedicated;
      goto LAB_000a96bb;
    }
  }
  else {
    svs.maxclients = Q_atoi(com_argv[iVar3 + 1]);
  }
  cls.state = (cactive_t)(g_bIsDedicatedServer == false);
  if (svs.maxclients < 1) {
    svs.maxclients = 6;
  }
  else if (0x20 < svs.maxclients) {
    svs.maxclients = 0x20;
  }
LAB_000a96bb:
  svs.maxclientslimit = 0x20;
  if ((g_bIsDedicatedServer == false) && (host_parms.memsize < 0x1000001)) {
    svs.maxclientslimit = 4;
  }
  SV_UPDATE_MASK = 7;
  if (svs.maxclients != 1) {
    SV_UPDATE_MASK = 0x3f;
  }
  SV_UPDATE_BACKUP = 8;
  if (svs.maxclients != 1) {
    SV_UPDATE_BACKUP = 0x40;
  }
  pcVar1 = Hunk_AllocName(svs.maxclientslimit * 0x4ef8,"clients");
  svs.clients = pcVar1;
  if (0 < svs.maxclientslimit) {
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      Q_memset(pcVar1,0,0x4ef8);
      (pcVar1->resourcesneeded).pPrev = &pcVar1->resourcesneeded;
      (pcVar1->resourcesneeded).pNext = &pcVar1->resourcesneeded;
      (pcVar1->resourcesonhand).pPrev = &pcVar1->resourcesonhand;
      (pcVar1->resourcesonhand).pNext = &pcVar1->resourcesonhand;
      pcVar1 = pcVar1 + 1;
    } while (iVar3 < svs.maxclientslimit);
  }
  value = 0.0;
  if (1 < svs.maxclients) {
    value = 1.0;
  }
  Cvar_SetValue("deathmatch",value);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclientslimit) {
    iVar3 = 0;
    pcVar1 = svs.clients;
    do {
      if (pcVar1->frames != (client_frame_t *)0x0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar3 = iVar3 + 1;
      pcVar2 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1810);
      pcVar1->frames = pcVar2;
      pcVar1 = pcVar1 + 1;
    } while (iVar3 < svs.maxclientslimit);
  }
  iVar3 = svs.maxclientslimit;
  if (svs.maxclients < svs.maxclientslimit) {
    iVar3 = svs.maxclients;
  }
  svs.maxclients = iVar3;
  return;
}


// SV_SetMoveVars  @ 0009dda0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SetMoveVars(void)

{
  qboolean local_1c;
  
  movevars.entgravity = 1.0;
  movevars.gravity = sv_gravity.value;
  movevars.stopspeed = sv_stopspeed.value;
  movevars.maxspeed = sv_maxspeed.value;
  movevars.spectatormaxspeed = sv_spectatormaxspeed.value;
  movevars.accelerate = sv_accelerate.value;
  movevars.airaccelerate = sv_airaccelerate.value;
  movevars.wateraccelerate = sv_wateraccelerate.value;
  movevars.friction = sv_friction.value;
  movevars.edgefriction = sv_edgefriction.value;
  movevars.waterfriction = sv_waterfriction.value;
  movevars.bounce = sv_bounce.value;
  movevars.stepsize = sv_stepsize.value;
  movevars.maxvelocity = sv_maxvelocity.value;
  movevars.zmax = sv_zmax.value;
  movevars.waveHeight = sv_wateramp.value;
  local_1c = (qboolean)(longlong)ROUND(sv_footsteps.value);
  movevars.footsteps = local_1c;
  movevars.rollangle = sv_rollangle.value;
  movevars.rollspeed = sv_rollspeed.value;
  movevars.skycolor_r = sv_skycolor_r.value;
  movevars.skycolor_g = sv_skycolor_g.value;
  movevars.skycolor_b = sv_skycolor_b.value;
  movevars.skyvec_x = sv_skyvec_x.value;
  movevars.skyvec_y = sv_skyvec_y.value;
  movevars.skyvec_z = sv_skyvec_z.value;
  Q_strncpy(movevars.skyName,sv_skyname.string,0x1f);
  movevars.skyName[0x1f] = '\0';
  return;
}


// SV_SetNewInfo  @ 000a42d0
void SV_SetNewInfo(int newblindex)

{
  g_svdeltacallback.newbl = true;
  g_svdeltacallback.newblindex = newblindex;
  return;
}


// SV_SetPlayer  @ 000bbb60
qboolean SV_SetPlayer(int idnum)

{
  client_s *pcVar1;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  pcVar1 = svs.clients;
  while ((((pcVar1->spawned == false || (pcVar1->active == false)) || (pcVar1->connected == false))
         || (pcVar1->userid != idnum))) {
    pcVar1 = pcVar1 + 1;
    if (pcVar1 == svs.clients + 0x20) {
      Con_Printf("Userid %i is not on the server\n",idnum);
      return false;
    }
  }
  host_client = pcVar1;
  sv_player = pcVar1->edict;
  return true;
}


// SV_SetStudioHullPlane  @ 00093c90
void SV_SetStudioHullPlane(mplane_t *pplane,int iBone,int k,float dist)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  pplane->type = '\x05';
  fVar1 = bonetransform[iBone][0][k];
  pplane->normal[0] = fVar1;
  fVar2 = bonetransform[iBone][1][k];
  pplane->normal[1] = fVar2;
  fVar3 = bonetransform[iBone][2][k];
  pplane->normal[2] = fVar3;
  pplane->dist = fVar3 * bonetransform[iBone][2][3] +
                 fVar2 * bonetransform[iBone][1][3] + fVar1 * bonetransform[iBone][0][3] + dist;
  return;
}


// SV_SetupMove  @ 000b9cc0
void SV_SetupMove(client_t *host_client)

{
  float fVar1;
  vec_t vVar2;
  entity_state_s *peVar3;
  entity_state_s *peVar4;
  entity_state_s *peVar5;
  int iVar6;
  client_s *pcVar7;
  int iVar8;
  int iVar9;
  entity_state_s *peVar10;
  int iVar11;
  client_frame_t *pcVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  vec_t *local_5c;
  uint local_58;
  client_frame_t *local_50;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int clindex@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float targettime@[???]
                       Unresolved local var: float cl_interptime@[???]
                       Unresolved local var: float correct@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: client_frame_t * pnext@[???]
                       Unresolved local var: int msg@[???]
                       Unresolved local var: packet_entities_t * ppack@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: entity_state_t * state@[???]
                       Unresolved local var: entity_state_t * pnextstate@[DW_OP_reg1(ECX)]
                       Unresolved local var: vec3_t origin@[???]
                       Unresolved local var: sv_adjusted_positions_t * pos@[???] */
  Q_memset(truepositions,0,0xb00);
  nofind = true;
  iVar6 = (*gEntityInterface.pfnAllowLagCompensation)();
  iVar13 = svs.maxclients;
  if (iVar6 == 0) {
    return;
  }
  if (sv_unlag.value == 0.0) {
    return;
  }
  if (host_client->lw == 0) {
    return;
  }
  if (host_client->lc == 0) {
    return;
  }
  if (svs.maxclients < 2) {
    return;
  }
  if (host_client->active == false) {
    return;
  }
  iVar6 = 0;
  nofind = false;
  pcVar7 = svs.clients;
  do {
    if ((pcVar7 != host_client) && (pcVar7->active != false)) {
      truepositions[iVar6].oldorg[0] = (pcVar7->edict->v).origin[0];
      truepositions[iVar6].oldorg[1] = (pcVar7->edict->v).origin[1];
      truepositions[iVar6].oldorg[2] = (pcVar7->edict->v).origin[2];
      truepositions[iVar6].oldabsmin[0] = (pcVar7->edict->v).absmin[0];
      truepositions[iVar6].oldabsmin[1] = (pcVar7->edict->v).absmin[1];
      truepositions[iVar6].oldabsmin[2] = (pcVar7->edict->v).absmin[2];
      truepositions[iVar6].oldabsmax[0] = (pcVar7->edict->v).absmax[0];
      truepositions[iVar6].oldabsmax[1] = (pcVar7->edict->v).absmax[1];
      vVar2 = (pcVar7->edict->v).absmax[2];
      truepositions[iVar6].active = 1;
      truepositions[iVar6].oldabsmax[2] = vVar2;
    }
    iVar6 = iVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (iVar6 != iVar13);
  lVar18 = (longdouble)host_client->latency;
  if ((longdouble)1.5 < (longdouble)host_client->latency) {
    lVar18 = (longdouble)1.5;
  }
  lVar16 = (longdouble)sv_maxunlag.value;
  if (lVar16 != (longdouble)0) {
    lVar17 = lVar18;
    if (lVar16 < (longdouble)0) {
      Cvar_SetValue("sv_maxunlag",(float)(longdouble)0);
      lVar16 = (longdouble)sv_maxunlag.value;
      lVar17 = (longdouble)(float)lVar18;
    }
    lVar18 = lVar16;
    if (lVar17 < lVar16) {
      lVar18 = lVar17;
    }
  }
  iVar9 = svs.maxclients;
  iVar6 = SV_UPDATE_BACKUP;
  iVar13 = SV_UPDATE_MASK;
  lVar17 = (longdouble)(host_client->lastcmd).lerp_msec / (longdouble)1000.0;
  lVar16 = (longdouble)0.1;
  if (lVar17 <= lVar16) {
    lVar16 = lVar17;
  }
  if (lVar16 < (longdouble)host_client->next_messageinterval) {
    lVar16 = (longdouble)(float)host_client->next_messageinterval;
  }
  lVar18 = (longdouble)
           (float)((((longdouble)realtime - lVar18) - lVar16) + (longdouble)sv_unlagpush.value);
  if ((longdouble)realtime < lVar18) {
    lVar18 = (longdouble)(float)realtime;
  }
  if (0 < SV_UPDATE_BACKUP) {
    local_50 = (client_frame_t *)0x0;
                    /* Unresolved local var: int i@[???] */
    local_58 = 0;
    do {
      pcVar12 = host_client->frames +
                (~local_58 + (host_client->netchan).outgoing_sequence & iVar13);
      iVar15 = (pcVar12->entities).num_entities;
      if (0 < iVar15) {
        iVar11 = 0;
        iVar8 = 0;
        do {
          peVar3 = (pcVar12->entities).entities;
          iVar14 = *(int *)((int)peVar3->origin + iVar11 + -0xc);
          if (((0 < iVar14) && (iVar14 <= iVar9)) &&
             (iVar14 = iVar14 + -1, truepositions[iVar14].deadflag == 0)) {
            if (*(int *)((int)peVar3->basevelocity + iVar11 + -0x10) < 1) {
              truepositions[iVar14].deadflag = 1;
            }
            if ((*(byte *)((int)peVar3->angles + iVar11 + 0x20) & 0x20) != 0) {
              truepositions[iVar14].deadflag = 1;
            }
            if (truepositions[iVar14].temp_org_setflag == 0) {
              truepositions[iVar14].temp_org_setflag = 1;
              fVar1 = *(float *)((int)peVar3->origin + iVar11);
            }
            else {
              fVar1 = *(float *)((int)peVar3->origin + iVar11);
              if (((128.0 < ABS(fVar1 - truepositions[iVar14].temp_org[0])) ||
                  (128.0 < ABS(*(float *)((int)peVar3->origin + iVar11 + 4) -
                               truepositions[iVar14].temp_org[1]))) ||
                 (128.0 < ABS(*(float *)((int)peVar3->origin + iVar11 + 8) -
                              truepositions[iVar14].temp_org[2]))) {
                truepositions[iVar14].deadflag = 1;
                fVar1 = *(float *)((int)peVar3->origin + iVar11);
              }
            }
            truepositions[iVar14].temp_org[0] = fVar1;
            truepositions[iVar14].temp_org[1] = *(vec_t *)((int)peVar3->origin + iVar11 + 4);
            truepositions[iVar14].temp_org[2] = *(vec_t *)((int)peVar3->origin + iVar11 + 8);
            iVar15 = (pcVar12->entities).num_entities;
          }
          iVar8 = iVar8 + 1;
          iVar11 = iVar11 + 0x154;
        } while (iVar8 < iVar15);
      }
      lVar16 = (longdouble)pcVar12->senttime;
      if (lVar16 < lVar18) {
        if (((int)local_58 < iVar6) && (lVar18 - lVar16 <= (longdouble)1)) {
          if (local_50 == (client_frame_t *)0x0) {
            lVar17 = (longdouble)0;
            local_50 = pcVar12;
          }
          else {
                    /* Unresolved local var: float dt@[???] */
            lVar19 = (longdouble)(float)((longdouble)local_50->senttime - lVar16);
            lVar17 = (longdouble)0;
            if (lVar19 != (longdouble)0) {
              lVar18 = (longdouble)(float)((lVar18 - lVar16) / lVar19);
              lVar17 = (longdouble)1;
              if ((lVar18 <= (longdouble)1) && (lVar17 = lVar18, lVar18 < (longdouble)0)) {
                lVar17 = (longdouble)0;
              }
            }
          }
          local_5c = (vec_t *)(pcVar12->entities).num_entities;
          if ((int)local_5c < 1) {
            return;
          }
          iVar13 = 0;
                    /* Unresolved local var: vec3_t delta@[???] */
          iVar6 = 0;
          goto LAB_000ba160;
        }
        break;
      }
      local_58 = local_58 + 1;
      local_50 = pcVar12;
    } while ((int)local_58 < iVar6);
  }
  Q_memset(truepositions,0,0xb00);
  nofind = true;
  return;
LAB_000ba160:
  peVar3 = (pcVar12->entities).entities;
  iVar9 = *(int *)((int)peVar3->origin + iVar6 + -0xc);
  if ((0 < iVar9) && (iVar9 <= svs.maxclients)) {
    iVar15 = iVar9 + -1;
    pcVar7 = svs.clients + iVar15;
    if ((pcVar7 != host_client) &&
       ((pcVar7->active != false && (truepositions[iVar15].deadflag == 0)))) {
      if (truepositions[iVar15].active == 0) {
        Con_DPrintf("tried to store off position of bogus player %i/%s\n",iVar13,pcVar7->name);
        local_5c = (vec_t *)(pcVar12->entities).num_entities;
      }
      else {
                    /* Unresolved local var: int i@[???] */
        iVar8 = (local_50->entities).num_entities;
        if (iVar8 < 1) {
LAB_000ba239:
          local_3c = *(vec_t *)((int)peVar3->origin + iVar6);
          local_38 = *(vec_t *)((int)peVar3->origin + iVar6 + 4);
          local_34 = *(vec_t *)((int)peVar3->origin + iVar6 + 8);
        }
        else {
          peVar10 = (local_50->entities).entities;
          if (iVar9 != peVar10->number) {
            iVar11 = 0;
            peVar4 = peVar10;
            do {
              peVar10 = peVar4 + 1;
              iVar11 = iVar11 + 1;
              if (iVar11 == iVar8) goto LAB_000ba239;
              peVar5 = peVar4 + 1;
              peVar4 = peVar10;
            } while (iVar9 != peVar5->number);
          }
          if (peVar10 == (entity_state_s *)0x0) goto LAB_000ba239;
          local_28 = peVar10->origin[0] - *(float *)((int)peVar3->origin + iVar6);
          local_24 = peVar10->origin[1] - *(float *)((int)peVar3->origin + iVar6 + 4);
          local_20 = peVar10->origin[2] - *(float *)((int)peVar3->origin + iVar6 + 8);
          VectorMA((vec_t *)((int)peVar3->origin + iVar6),(float)lVar17,&local_28,&local_3c);
        }
        local_5c = &local_3c;
        truepositions[iVar15].neworg[0] = local_3c;
        truepositions[iVar15].neworg[1] = local_38;
        truepositions[iVar15].neworg[2] = local_34;
        truepositions[iVar15].initial_correction_org[0] = local_3c;
        truepositions[iVar15].initial_correction_org[1] = local_38;
        truepositions[iVar15].initial_correction_org[2] = local_34;
        iVar9 = VectorCompare(local_5c,(pcVar7->edict->v).origin);
        if (iVar9 == 0) {
          (pcVar7->edict->v).origin[0] = local_3c;
          (pcVar7->edict->v).origin[1] = local_38;
          (pcVar7->edict->v).origin[2] = local_34;
          SV_LinkEdict(pcVar7->edict,false);
          truepositions[iVar15].needrelink = 1;
        }
        local_5c = (vec_t *)(pcVar12->entities).num_entities;
      }
    }
  }
  iVar13 = iVar13 + 1;
  iVar6 = iVar6 + 0x154;
  if ((int)local_5c <= iVar13) {
    return;
  }
  goto LAB_000ba160;
}


// SV_ShouldUpdatePing  @ 000a4e50
qboolean SV_ShouldUpdatePing(client_t *client)

{
  if (client->proxy == false) {
    return (client->lastcmd).buttons & 0x8000;
  }
  if (client->nextping <= realtime) {
    client->nextping = realtime + 2.0;
    return true;
  }
  return false;
}


// SV_ShowServerinfo_f  @ 000bbbe0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ShowServerinfo_f(void)

{
  char *s;
  
  if (cmd_source != src_command) {
    s = Info_Serverinfo();
    Info_Print(s);
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// SV_Shutdown  @ 000aac70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Shutdown(void)

{
  delta_info_s *pdVar1;
  delta_info_t *p;
  
  p = g_sv_delta;
  while (p != (delta_info_t *)0x0) {
    pdVar1 = p->next;
    if (p->delta != (delta_t *)0x0) {
      DELTA_FreeDescription(&p->delta);
    }
    Mem_Free(p->name);
    Mem_Free(p->loadfile);
    Mem_Free(p);
    p = pdVar1;
  }
  g_sv_delta = (delta_info_t *)0x0;
  return;
}


// SV_SingleClipMoveToEntity  @ 000c04e0
void SV_SingleClipMoveToEntity
               (edict_t_conflict *ent,vec_t *start,vec_t *mins,vec_t *maxs,vec_t *end,trace_t *trace
               )

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  hull_t *hull;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_b4;
  trace_t local_ac;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int local_2c [7];
  
                    /* Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???] */
  Q_memset(trace,0,0x38);
  trace->fraction = 1.0;
  trace->allsolid = true;
  trace->endpos[0] = *end;
  trace->endpos[1] = end[1];
  trace->endpos[2] = end[2];
  if (sv.models[(ent->v).modelindex]->type == mod_studio) {
    hull = SV_HullForStudioModel((edict_t *)ent,mins,maxs,&local_68,local_2c);
  }
  else {
    hull = SV_HullForEntity(ent,mins,maxs,&local_68);
    local_2c[0] = 1;
  }
  bVar7 = false;
  local_5c = *start - local_68;
  local_58 = start[1] - local_64;
  local_54 = start[2] - local_60;
  local_50 = *end - local_68;
  local_4c = end[1] - local_64;
  local_48 = end[2] - local_60;
  if (((ent->v).solid == 4) &&
     ((((ent->v).angles[0] != 0.0 || ((ent->v).angles[1] != 0.0)) || ((ent->v).angles[2] != 0.0))))
  {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
    AngleVectors((ent->v).angles,(vec_t *)&local_ac,&local_44,&local_38);
    bVar7 = true;
    fVar3 = local_54 * (float)local_ac.inopen;
    fVar1 = local_44 * local_5c;
    fVar2 = local_3c * local_54;
    local_54 = local_54 * local_30 + local_58 * local_34 + local_5c * local_38;
    fVar4 = (float)local_ac.inopen * local_48;
    fVar5 = local_44 * local_50;
    fVar6 = local_3c * local_48;
    local_48 = local_48 * local_30 + local_4c * local_34 + local_50 * local_38;
    local_5c = fVar3 + local_58 * (float)local_ac.startsolid + local_5c * (float)local_ac.allsolid;
    local_58 = -(fVar2 + local_40 * local_58 + fVar1);
    local_50 = fVar4 + (float)local_ac.startsolid * local_4c + (float)local_ac.allsolid * local_50;
    local_4c = -(fVar6 + local_40 * local_4c + fVar5);
  }
  if (local_2c[0] == 1) {
    SV_RecursiveHullCheck(hull,hull->firstclipnode,0.0,1.0,&local_5c,&local_50,trace);
  }
  else {
                    /* Unresolved local var: int closest@[???]
                       Unresolved local var: trace_t testtrace@[???] */
    if (local_2c[0] < 1) {
      local_b4 = 0;
    }
    else {
      local_b4 = 0;
      iVar9 = 0;
      do {
        while( true ) {
          iVar10 = iVar9;
          Q_memset(&local_ac,0,0x38);
          local_ac.allsolid = true;
          local_ac.endpos[0] = *end;
          local_ac.fraction = 1.0;
          local_ac.endpos[1] = end[1];
          local_ac.endpos[2] = end[2];
          SV_RecursiveHullCheck(hull,hull->firstclipnode,0.0,1.0,&local_5c,&local_50,&local_ac);
          if (((iVar10 == 0) || ((float)local_ac.allsolid != 0.0)) ||
             (((float)local_ac.startsolid != 0.0 || (local_ac.fraction < trace->fraction)))) break;
LAB_000c06e3:
          hull = hull + 1;
          iVar9 = iVar10 + 1;
          if (local_2c[0] <= iVar10 + 1) goto LAB_000c06f6;
        }
        uVar8 = 0;
        local_b4 = iVar10;
        if (trace->startsolid != false) {
          do {
            *(undefined4 *)((int)trace->endpos + (uVar8 - 0x14)) =
                 *(undefined4 *)((int)local_ac.endpos + (uVar8 - 0x14));
            uVar8 = uVar8 + 4;
          } while (uVar8 < 0x38);
          trace->startsolid = true;
          goto LAB_000c06e3;
        }
        do {
          *(undefined4 *)((int)trace->endpos + (uVar8 - 0x14)) =
               *(undefined4 *)((int)local_ac.endpos + (uVar8 - 0x14));
          uVar8 = uVar8 + 4;
        } while (uVar8 < 0x38);
        hull = hull + 1;
        iVar9 = iVar10 + 1;
      } while (iVar10 + 1 < local_2c[0]);
    }
LAB_000c06f6:
    iVar9 = SV_HitgroupForStudioHull(local_b4);
    trace->hitgroup = iVar9;
  }
  fVar1 = trace->fraction;
  if (fVar1 != 1.0) {
    if (bVar7) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
      AngleVectorsTranspose((ent->v).angles,&local_38,&local_44,(vec_t *)&local_ac);
      fVar1 = (trace->plane).normal[0];
      fVar2 = (trace->plane).normal[1];
      fVar3 = (trace->plane).normal[2];
      (trace->plane).normal[0] = local_30 * fVar3 + local_34 * fVar2 + local_38 * fVar1;
      (trace->plane).normal[1] = local_3c * fVar3 + local_40 * fVar2 + local_44 * fVar1;
      (trace->plane).normal[2] =
           fVar3 * (float)local_ac.inopen +
           fVar2 * (float)local_ac.startsolid + fVar1 * (float)local_ac.allsolid;
      fVar1 = trace->fraction;
    }
    trace->endpos[0] = (*end - *start) * fVar1 + *start;
    trace->endpos[1] = (end[1] - start[1]) * fVar1 + start[1];
    trace->endpos[2] = (end[2] - start[2]) * fVar1 + start[2];
  }
  if ((fVar1 < 1.0) || (trace->startsolid != false)) {
    trace->ent = ent;
  }
  return;
}


// SV_SkipUpdates  @ 000a58f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SkipUpdates(void)

{
  client_t *pcVar1;
  int iVar2;
  client_s *pcVar3;
  int iVar4;
  
  iVar2 = svs.maxclients;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  pcVar1 = host_client;
  if (0 < svs.maxclients) {
    iVar4 = 0;
    pcVar3 = svs.clients;
    do {
      if ((((pcVar3->active != false) || (pcVar3->connected != false)) || (pcVar3->spawned != false)
          ) && (pcVar1->fakeclient == false)) {
        pcVar3->skip_message = true;
      }
      iVar4 = iVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 != iVar2);
  }
  return;
}


// SV_SpawnServer  @ 000a7d10
int SV_SpawnServer(qboolean bIsDemo,char *server,char *startspot)

{
  edict_t_conflict *peVar1;
  entity_state_s *p;
  int iVar2;
  model_s *pmVar3;
  float fVar4;
  char *pcVar5;
  client_frame_t *pcVar6;
  BOOL BVar7;
  model_t *pmVar8;
  client_s *pcVar9;
  int iVar10;
  int iVar11;
  char (*name) [5];
  client_s *local_a8;
  int local_a4;
  char local_9c [63];
  undefined1 local_5d;
  char local_5c [76];
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * pszhost@[???]
                       Unresolved local var: char[64] oldname@[???] */
  if ((sv.active != false) && (1 < svs.maxclients)) {
    iVar11 = 0;
    iVar10 = svs.maxclients;
    pcVar9 = svs.clients;
    do {
      if ((((pcVar9->active != false) || (pcVar9->spawned != false)) || (pcVar9->connected != false)
          ) && ((peVar1 = pcVar9->edict, peVar1 != (edict_t_conflict *)0x0 && (peVar1->free == 0))))
      {
        if (peVar1->pvPrivateData == (void *)0x0) {
          Con_Printf("Skipping reconnect on %s, no pvPrivateData\n",pcVar9->name);
          iVar10 = svs.maxclients;
        }
        else {
          (*gEntityInterface.pfnClientDisconnect)(peVar1);
          iVar10 = svs.maxclients;
        }
      }
      iVar11 = iVar11 + 1;
      pcVar9 = pcVar9 + 1;
    } while (iVar11 < iVar10);
  }
  if (g_bOutOfDateRestart == true) {
    g_bOutOfDateRestart = false;
    Cmd_ExecuteString("quit\n",src_command);
  }
  Log_Open();
  Log_Printf("Loading map \"%s\"\n",server);
  Log_PrintServerVars();
  NET_Config((uint)(1 < svs.maxclients));
  pcVar5 = Cvar_VariableString("hostname");
  if ((pcVar5 != (char *)0x0) && (*pcVar5 == '\0')) {
    if (gEntityInterface.pfnGetGameDescription == (_func_char_ptr *)0x0) {
      Cvar_Set("hostname","Half-Life");
    }
    else {
      pcVar5 = (*gEntityInterface.pfnGetGameDescription)();
      Cvar_Set("hostname",pcVar5);
    }
  }
  scr_centertime_off = 0.0;
  if (startspot == (char *)0x0) {
    Con_DPrintf("Spawn Server %s\n",server);
  }
  else {
    Con_DPrintf("Spawn Server %s: [%s]\n",server,startspot);
  }
  gHostSpawnCount = gHostSpawnCount + 1;
  svs.spawncount = gHostSpawnCount;
  if (coop.value != 0.0) {
    Cvar_SetValue("deathmatch",0.0);
  }
  current_skill = (int)(skill.value + 0.5);
  if (current_skill < 0) {
    current_skill = 0;
  }
  else if (3 < current_skill) {
    current_skill = 3;
  }
  Cvar_SetValue("skill",(float)current_skill);
  ContinueLoadingProgressBar("Server",2,0.0);
  HPAK_CheckSize("custom");
  local_9c[0] = '\0';
  Q_strncpy(local_9c,sv.name,0x3f);
  local_5d = 0;
  Host_ClearMemory(false);
  iVar10 = svs.maxclientslimit;
  if (0 < svs.maxclientslimit) {
    local_a4 = 0;
    local_a8 = svs.clients;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
      pcVar6 = local_a8->frames;
      if (pcVar6 != (client_frame_t *)0x0) {
        if (0 < SV_UPDATE_BACKUP) {
          iVar10 = 0;
          do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
            if (pcVar6 != (client_frame_t *)0x0) {
              p = (pcVar6->entities).entities;
              if (p != (entity_state_s *)0x0) {
                Mem_Free(p);
              }
              (pcVar6->entities).entities = (entity_state_s *)0x0;
              (pcVar6->entities).num_entities = 0;
            }
            *(undefined4 *)&pcVar6->senttime = 0;
            iVar10 = iVar10 + 1;
            *(undefined4 *)((int)&pcVar6->senttime + 4) = 0;
            pcVar6->ping_time = -1.0;
            pcVar6 = pcVar6 + 1;
          } while (iVar10 < SV_UPDATE_BACKUP);
          pcVar6 = local_a8->frames;
        }
        Mem_Free(pcVar6);
        local_a8->frames = (client_frame_t *)0x0;
        iVar10 = svs.maxclientslimit;
      }
      local_a4 = local_a4 + 1;
      local_a8 = local_a8 + 1;
    } while (local_a4 < iVar10);
  }
  SV_UPDATE_MASK = 7;
  if (svs.maxclients != 1) {
    SV_UPDATE_MASK = 0x3f;
  }
  SV_UPDATE_BACKUP = 8;
  if (svs.maxclients != 1) {
    SV_UPDATE_BACKUP = 0x40;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < iVar10) {
    iVar10 = 0;
    pcVar9 = svs.clients;
    do {
      if (pcVar9->frames != (client_frame_t *)0x0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar10 = iVar10 + 1;
      pcVar6 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1810);
      pcVar9->frames = pcVar6;
      pcVar9 = pcVar9 + 1;
    } while (iVar10 < svs.maxclientslimit);
  }
  Q_memset(&sv,0,0x4640c);
  Q_strncpy(sv.oldname,local_9c,0x3f);
  sv.oldname[0x3f] = '\0';
  Q_strncpy(sv.name,server,0x3f);
  sv.name[0x3f] = '\0';
  if (startspot == (char *)0x0) {
    sv.startspot[0] = '\0';
  }
  else {
    Q_strncpy(sv.startspot,startspot,0x3f);
    sv.startspot[0x3f] = '\0';
  }
  pr_strings = gNullString;
  gGlobalVariables.pStringBase = gNullString;
  if (svs.maxclients == 1) {
    Cvar_SetValue("sv_clienttrace",1.0);
  }
  sv.max_edicts = COM_EntsForPlayerSlots(svs.maxclients);
  if (g_moved_edict != (edict_t_conflict **)0x0) {
    Mem_Free(g_moved_edict);
  }
  if (g_moved_from != (vec3_t *)0x0) {
    Mem_Free(g_moved_from);
  }
                    /* Unresolved local var: int nSize@[???] */
  iVar10 = sv.max_edicts;
  g_moved_edict = (edict_t_conflict **)0x0;
  g_moved_from = (vec3_t *)0x0;
  if (sv.max_edicts == 0) {
    Con_DPrintf("SV_ReallocateDynamicData with sv.max_edicts == 0");
  }
  else {
    g_moved_edict = Mem_ZeroMalloc(sv.max_edicts * 4);
    if (g_moved_from != (vec3_t *)0x0) {
      Con_Printf("Reallocate on moved_from\n");
    }
    g_moved_from = Mem_ZeroMalloc(iVar10 * 0xc);
  }
  gGlobalVariables.maxEntities = sv.max_edicts;
  sv.edicts = Hunk_AllocName(sv.max_edicts * 0x324,"edicts");
  sv.baselines = Hunk_AllocName(sv.max_edicts * 0x154,"baselines");
  gGlobalVariables.maxClients = svs.maxclients;
  sv.datagram.maxsize = 4000;
  sv.spectator.data = sv.spectator_buf;
  sv.datagram.cursize = 0;
  sv.datagram.data = sv.datagram_buf;
  sv.multicast.data = sv.multicast_buf;
  sv.datagram.buffername = "Server Datagram";
  sv.reliable_datagram.maxsize = 4000;
  sv.reliable_datagram.cursize = 0;
  sv.reliable_datagram.data = sv.reliable_datagram_buf;
  sv.reliable_datagram.buffername = "Server Reliable Datagram";
  sv.multicast.maxsize = 0x400;
  sv.signon.maxsize = 0x8000;
  sv.signon.cursize = 0;
  sv.signon.buffername = "Server Signon Buffer";
  sv.num_edicts = svs.maxclients + 1;
  sv.multicast.buffername = "Server Multicast Buffer";
  sv.spectator.maxsize = 0x400;
  sv.spectator.buffername = "Server Spectator Buffer";
  sv.signon.data = sv.signon_data;
  if (0 < svs.maxclients) {
    iVar11 = 0x324;
    iVar10 = 0;
    pcVar9 = svs.clients;
    do {
      iVar10 = iVar10 + 1;
      iVar2 = iVar11 + -0x18;
      iVar11 = iVar11 + 0x324;
      pcVar9->edict = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar2);
      pcVar9 = pcVar9 + 1;
    } while (iVar10 != gGlobalVariables.maxClients);
  }
  sv.time._0_4_ = 0;
  sv.time._4_4_ = 0x3ff00000;
  sv.state = ss_loading;
  sv.paused = false;
  gGlobalVariables.time = 1.0;
  ContinueLoadingProgressBar("Server",3,0.0);
  snprintf(sv.modelname,0x40,"maps/%s.bsp",server);
  sv.worldmodel = Mod_ForName(sv.modelname,false,false);
  if (sv.worldmodel != (model_t *)0x0) {
    ContinueLoadingProgressBar("Server",4,0.0);
    if (gmodinfo.clientcrccheck != false) {
                    /* Unresolved local var: char[64] szDllName@[???] */
      snprintf(local_5c,0x40,"cl_dlls//client.dll",server);
      COM_FixSlashes(local_5c);
      BVar7 = MD5_Hash_File(sv.clientdllmd5,local_5c,0,0,(uint *)0x0);
      if (BVar7 == 0) {
        Con_Printf("Couldn\'t CRC client side dll:  %s\n",local_5c);
        sv.active = false;
        return 0;
      }
    }
    ContinueLoadingProgressBar("Server",6,0.0);
    if (svs.maxclients < 2) {
      sv.worldmapCRC = 0;
    }
    else {
      CRC32_Init(&sv.worldmapCRC);
      iVar10 = CRC_MapFile(&sv.worldmapCRC,sv.modelname);
      if (iVar10 == 0) {
        Con_Printf("Couldn\'t CRC server map:  %s\n",0x506ae8);
        sv.active = false;
        return 0;
      }
      CM_CalcPAS(sv.worldmodel);
    }
    sv.models[1] = sv.worldmodel;
    SV_ClearWorld();
    sv.model_precache_flags[1] = sv.model_precache_flags[1] | 1;
    sv.model_precache[1] = sv.modelname;
    sv.sound_precache[0] = pr_strings;
    sv.model_precache[0] = pr_strings;
    sv.generic_precache[0] = pr_strings;
    if (1 < (sv.worldmodel)->numsubmodels) {
      name = localmodels;
      iVar10 = 1;
      do {
        name = name + 1;
        iVar11 = iVar10 + 1;
        sv.model_precache[iVar10 + 1] = *name;
        pmVar8 = Mod_ForName(*name,false,false);
        sv.models[iVar10 + 1] = pmVar8;
        sv.model_precache_flags[iVar10 + 1] = sv.model_precache_flags[iVar10 + 1] | 1;
        iVar10 = iVar11;
      } while (iVar11 < (sv.worldmodel)->numsubmodels);
    }
    peVar1 = sv.edicts;
    Q_memset(&(sv.edicts)->v,0,0x2a4);
    peVar1->free = 0;
    pmVar3 = sv.worldmodel;
    pcVar5 = pr_strings;
    (peVar1->v).modelindex = 1;
    fVar4 = coop.value;
    (peVar1->v).model = (int)pmVar3 - (int)pcVar5;
    (peVar1->v).solid = 4;
    (peVar1->v).movetype = 7;
    if (fVar4 == 0.0) {
      gGlobalVariables.deathmatch = deathmatch.value;
      fVar4 = gGlobalVariables.coop;
    }
    gGlobalVariables.coop = fVar4;
    gGlobalVariables.serverflags = (float)svs.serverflags;
    gGlobalVariables.mapname = 0x506a28 - (int)pcVar5;
    gGlobalVariables.startspot = 0x506aa8 - (int)pcVar5;
    SV_SetMoveVars();
    return 1;
  }
  Con_Printf("Couldn\'t spawn server %s\n",0x506ae8);
  sv.active = false;
  return 0;
}


// SV_Spawn_f  @ 000a3a20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Spawn_f(void)

{
  client_t *pcVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  byte abStack_10020 [65536];
  sizebuf_t local_20;
  
                    /* Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  Q_memset(&local_20,0,0x14);
  local_20.buffername = "Spawning";
  local_20.data = abStack_10020;
  local_20.cursize = 0;
  local_20.maxsize = 0x10000;
  iVar2 = Cmd_Argc();
  pcVar1 = host_client;
  if (iVar2 != 3) {
    Con_Printf("spawn is not valid\n");
    return;
  }
  if (cmd_source == src_command) {
    Con_Printf("spawn is not valid from the console\n");
  }
  else {
    if (host_client->spawned == false) {
      pcVar3 = Cmd_Argv(2);
      lVar4 = strtol(pcVar3,(char **)0x0,10);
      pcVar1->crcValue = lVar4;
      COM_UnMunge2((uchar *)&host_client->crcValue,4,0xffU - svs.spawncount & 0xff);
      if (cls.demoplayback == false) {
        pcVar3 = Cmd_Argv(1);
        iVar2 = Q_atoi(pcVar3);
        if (iVar2 != svs.spawncount) {
          SV_New_f();
          return;
        }
      }
      SZ_Write(&local_20,sv.signon.data,sv.signon.cursize);
      SV_WriteSpawn(&local_20);
      MSG_WriteByte(&local_20,0x34);
      MSG_WriteString(&local_20,"");
      MSG_WriteByte(&local_20,0);
      Netchan_CreateFragments(true,&host_client->netchan,&local_20);
      Netchan_FragSend(&host_client->netchan);
      return;
    }
    Con_Printf("spawn is not valid when already spawned\n");
  }
  return;
}


// SV_StartParticle  @ 0009ca50
void SV_StartParticle(vec_t *org,vec_t *dir,int color,int count)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int v@[???] */
  if (0xf90 < sv.datagram.cursize) {
    return;
  }
  MSG_WriteByte(&sv.datagram,0x12);
  MSG_WriteCoord(&sv.datagram,*org);
  MSG_WriteCoord(&sv.datagram,org[1]);
  MSG_WriteCoord(&sv.datagram,org[2]);
  iVar1 = (int)(*dir * 16.0);
  if (iVar1 < -0x80) {
    iVar1 = -0x80;
  }
  if (0x7f < iVar1) {
    iVar1 = 0x7f;
  }
  MSG_WriteChar(&sv.datagram,iVar1);
  iVar1 = (int)(dir[1] * 16.0);
  if (iVar1 < -0x80) {
    iVar1 = -0x80;
  }
  if (0x7f < iVar1) {
    iVar1 = 0x7f;
  }
  MSG_WriteChar(&sv.datagram,iVar1);
  iVar1 = -0x80;
  if (-0x81 < (int)(dir[2] * 16.0)) {
    iVar1 = (int)(dir[2] * 16.0);
  }
  if (0x7f < iVar1) {
    iVar1 = 0x7f;
  }
  MSG_WriteChar(&sv.datagram,iVar1);
  MSG_WriteByte(&sv.datagram,count);
  MSG_WriteByte(&sv.datagram,color);
  return;
}


// SV_StartSound  @ 0009d5e0
void SV_StartSound(int recipients,edict_t_conflict *entity,int channel,char *sample,int volume,
                  float attenuation,int fFlags,int pitch)

{
  float fVar1;
  uint32 data;
  uint32 data_00;
  uint32 data_01;
  qboolean qVar2;
  int to;
  uint data_02;
  int iVar3;
  uint32 local_38;
  uint32 local_34;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean sendPAS@[???]
                       Unresolved local var: vec3_t origin@[???] */
                    /* Unresolved local var: int sound_num@[???]
                       Unresolved local var: int field_mask@[???]
                       Unresolved local var: int ent@[???] */
  local_38 = volume;
  local_2c = ((entity->v).mins[0] + (entity->v).maxs[0]) * 0.5 + (entity->v).origin[0];
  local_28 = ((entity->v).mins[1] + (entity->v).maxs[1]) * 0.5 + (entity->v).origin[1];
  local_24 = ((entity->v).mins[2] + (entity->v).maxs[2]) * 0.5 + (entity->v).origin[2];
  if (0xff < (uint)volume) {
    Con_Printf("SV_StartSound: volume = %i",volume);
    if (volume < 0) {
      local_38 = 0;
    }
    else {
      local_38 = 0xff;
    }
  }
  if (attenuation < 0.0) {
    fVar1 = 0.0;
LAB_0009d862:
    Con_Printf("SV_StartSound: attenuation = %f",(double)attenuation);
    attenuation = fVar1;
  }
  else {
    fVar1 = 4.0;
    if (4.0 < attenuation) goto LAB_0009d862;
  }
  data = channel;
  if (7 < (uint)channel) {
    Con_Printf("SV_StartSound: channel = %i",channel);
    data = ~(channel >> 0x1f) & 7;
  }
  local_34 = pitch;
  if (0xff < (uint)pitch) {
    Con_Printf("SV_StartSound: pitch = %i",pitch);
    if (pitch < 0) {
      local_34 = 0;
    }
    else {
      local_34 = 7;
    }
  }
  if (sample != (char *)0x0) {
    if (*sample == '!') {
      data_00 = Q_atoi(sample + 1);
      data_02 = fFlags | 0x10;
      if (0x5ff < (int)data_00) {
        Con_Printf("invalid sentence number: %s",sample + 1);
        return;
      }
      goto LAB_0009d6e4;
    }
    if (*sample == '#') {
      iVar3 = Q_atoi(sample + 1);
      data_02 = fFlags | 0x10;
      data_00 = iVar3 + 0x600;
      goto LAB_0009d6e4;
    }
  }
  data_00 = SV_LookupSoundIndex(sample);
  if ((data_00 == 0) || (data_02 = fFlags, sv.sound_precache[data_00] == (char *)0x0)) {
    Con_Printf("SV_StartSound: %s not precached (%d)\n",sample,data_00);
    return;
  }
LAB_0009d6e4:
  data_01 = NUM_FOR_EDICT((edict_t *)entity);
  if (local_38 != 0xff) {
    data_02 = data_02 | 1;
  }
  if (attenuation != 1.0) {
    data_02 = data_02 | 2;
  }
  if (local_34 != 100) {
    data_02 = data_02 | 8;
  }
  if (0xff < (int)data_00) {
    data_02 = data_02 | 4;
  }
  MSG_WriteByte(&sv.multicast,6);
  MSG_StartBitWriting(&sv.multicast);
  MSG_WriteBits(data_02,9);
  if ((data_02 & 1) != 0) {
    MSG_WriteBits(local_38,8);
  }
  if ((data_02 & 2) != 0) {
    MSG_WriteBits((int)(attenuation * 64.0),8);
  }
  MSG_WriteBits(data,3);
  MSG_WriteBits(data_01,0xb);
  if ((int)data_00 < 0x100) {
    MSG_WriteBits(data_00,8);
  }
  else {
    MSG_WriteBits(data_00,0x10);
  }
  MSG_WriteBitVec3Coord(&local_2c);
  if ((data_02 & 8) != 0) {
    MSG_WriteBits(local_34,8);
  }
  MSG_EndBitWriting(&sv.multicast);
                    /* Unresolved local var: int flags@[???] */
  iVar3 = 1;
  if (recipients == 1) {
    iVar3 = 0x81;
  }
  to = 4;
  if (recipients == 1) {
    to = 0x84;
  }
  if (channel == 6 || (fFlags & 0x20U) != 0) {
    qVar2 = Host_IsSinglePlayerGame();
    if (qVar2 == false) {
      SV_Multicast(entity,&local_2c,iVar3,true);
      return;
    }
    SV_Multicast(entity,&local_2c,iVar3,false);
    return;
  }
  SV_Multicast(entity,&local_2c,to,false);
  return;
}


// SV_StepDirection  @ 000af780
qboolean SV_StepDirection(edict_t_conflict *ent,float yaw,float dist)

{
  qboolean qVar1;
  qboolean relink;
  double local_2c;
  double local_24;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
  sincos((double)((yaw * 3.1415927 + yaw * 3.1415927) / 360.0),&local_24,&local_2c);
  local_10 = 0;
  local_18 = (float)local_2c * dist;
  local_14 = dist * (float)local_24;
  qVar1 = SV_movestep(ent,&local_18,relink);
  if (qVar1 == false) {
    SV_LinkEdict(ent,true);
    return false;
  }
  SV_LinkEdict(ent,true);
  return true;
}


// SV_StringToUserID  @ 000a8d30
USERID_t * SV_StringToUserID(char *str)

{
  int iVar1;
  char local_8c [127];
  undefined1 local_d;
  
  Q_memset(&SV_StringToUserID::id,0,0x10);
  if ((str != (char *)0x0) && (*str != '\0')) {
                    /* Unresolved local var: char[128] szTemp@[???]
                       Unresolved local var: char * pszUserID@[???] */
    iVar1 = Q_strnicmp(str,"STEAM_",6);
    if (iVar1 == 0) {
      strncpy(local_8c,str + 6,0x7f);
      SV_StringToUserID::id.idtype = 1;
    }
    else {
      strncpy(local_8c,str + 6,0x7f);
      SV_StringToUserID::id.idtype = 2;
    }
    local_d = 0;
    SV_StringToUserID::id.m_SteamID = Steam_StringToSteamID(local_8c);
    return &SV_StringToUserID::id;
  }
  return &SV_StringToUserID::id;
}


// SV_StudioSetupBones  @ 00093580
void SV_StudioSetupBones(model_t *pModel,float frame,int sequence,vec_t *angles,vec_t *origin,
                        uchar *pcontroller,uchar *pblending,int iBone,edict_t *edict)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  vec_t *pvVar7;
  studiohdr_t *psVar8;
  studiohdr_t *psVar9;
  mstudioseqdesc_t *pseqdesc;
  mstudioanim_t *pmVar10;
  char *pcVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  vec_t (*pavVar15) [3];
  int iVar16;
  vec_t (*p) [4];
  uint uVar17;
  vec_t (*pavVar18) [3];
  int iVar19;
  float local_2a4;
  float local_2a0;
  int local_288;
  int local_27c [128];
  float local_7c [3];
  vec_t local_70;
  vec_t local_60;
  vec_t local_50;
  float local_4c [8];
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float[8] adj@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: float[3][4] bonematrix@[???]
                       Unresolved local var: int[128] chain@[???]
                       Unresolved local var: int chainlength@[???] */
  if ((sequence < 0) || (pstudiohdr->numseq <= sequence)) {
    Con_DPrintf("SV_StudioSetupBones:  sequence %i/%i out of range for model %s\n",sequence,
                pstudiohdr->numseq,pstudiohdr->name);
    local_288 = 0;
  }
  else {
    local_288 = sequence * 0xb0;
  }
  psVar8 = pstudiohdr;
  iVar4 = pstudiohdr->boneindex;
  pseqdesc = (mstudioseqdesc_t *)(pstudiohdr->name + local_288 + pstudiohdr->seqindex + -8);
  pmVar10 = R_GetAnim(pModel,pseqdesc);
  if ((iBone < -1) || (iVar16 = pstudiohdr->numbones, iVar16 <= iBone)) {
    iBone = 0;
LAB_00093662:
    iVar16 = 0;
    do {
      local_27c[iVar16] = iBone;
      iVar16 = iVar16 + 1;
      iBone = *(int *)(psVar8->name + iBone * 0x70 + iVar4 + 0x18);
    } while (iBone != -1);
  }
  else {
    if (iBone != -1) goto LAB_00093662;
    if (0 < iVar16) {
      iVar19 = iVar16 + -1;
      piVar12 = local_27c + iVar19;
      iVar13 = 0;
      do {
        *piVar12 = iVar13;
        iVar13 = iVar13 + 1;
        piVar12 = piVar12 + -1;
      } while (iVar13 != iVar16);
      iVar16 = pseqdesc->numframes;
      goto joined_r0x00093697;
    }
  }
  iVar19 = iVar16 + -1;
  iVar16 = pseqdesc->numframes;
joined_r0x00093697:
  if (iVar16 < 2) {
    iVar16 = 0;
    local_2a0 = 0.0;
  }
  else {
    local_2a0 = (float)(iVar16 + -1) * frame * 0.00390625;
    iVar16 = (int)local_2a0;
    local_2a0 = local_2a0 - (float)iVar16;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: mstudiobonecontroller_t * pbonecontroller@[???] */
  iVar13 = pstudiohdr->numbonecontrollers;
  pcVar11 = pstudiohdr->name + pstudiohdr->bonecontrollerindex + -8;
  if (0 < iVar13) {
    iVar14 = 0;
    do {
      while( true ) {
        if (*(int *)(pcVar11 + 0x14) < 4) {
          uVar17 = *(uint *)(pcVar11 + 4);
          bVar3 = pcontroller[*(int *)(pcVar11 + 0x14)];
          if ((uVar17 & 0x8000) == 0) {
            fVar1 = ((float)bVar3 + (float)bVar3 * 0.0) / 255.0;
            if (fVar1 < 0.0) {
              fVar2 = 0.0;
              fVar6 = 1.0;
            }
            else {
              fVar2 = 1.0;
              fVar6 = 0.0;
              if (fVar1 <= 1.0) {
                fVar2 = fVar1;
                fVar6 = 1.0 - fVar1;
              }
            }
            fVar1 = fVar2 * *(float *)(pcVar11 + 0xc) + fVar6 * *(float *)(pcVar11 + 8);
          }
          else {
            fVar1 = ((float)bVar3 + (float)bVar3 * 0.0) * 1.40625 + *(float *)(pcVar11 + 8);
          }
        }
        else {
          fVar1 = *(float *)(pcVar11 + 0xc) * 0.0 + *(float *)(pcVar11 + 8);
          uVar17 = *(uint *)(pcVar11 + 4);
        }
        uVar17 = (uVar17 & 0x7fff) - 1;
        if (uVar17 < 0x20) break;
LAB_00093780:
        iVar14 = iVar14 + 1;
        pcVar11 = pcVar11 + 0x18;
        if (iVar13 <= iVar14) goto LAB_000937db;
      }
      uVar17 = 1 << ((byte)uVar17 & 0x1f);
      if ((uVar17 & 0x80008080) == 0) {
        if ((uVar17 & 0xb) != 0) {
          iVar13 = pstudiohdr->numbonecontrollers;
          local_4c[iVar14] = fVar1;
        }
        goto LAB_00093780;
      }
      pcVar11 = pcVar11 + 0x18;
      local_4c[iVar14] = fVar1 * 0.017453292;
      iVar14 = iVar14 + 1;
      iVar13 = pstudiohdr->numbonecontrollers;
    } while (iVar14 < iVar13);
  }
LAB_000937db:
  if (-1 < iVar19) {
    iVar13 = iVar19;
    do {
      iVar14 = local_27c[iVar13];
      iVar13 = iVar13 + -1;
      R_StudioCalcBoneQuaterion
                (iVar16,local_2a0,(mstudiobone_t *)(psVar8->name + iVar14 * 0x70 + iVar4 + -8),
                 pmVar10 + iVar14,local_4c,SV_StudioSetupBones::q[iVar14]);
      R_StudioCalcBonePosition
                (iVar16,local_2a0,(mstudiobone_t *)(psVar8->name + iVar14 * 0x70 + iVar4 + -8),
                 pmVar10 + iVar14,local_4c,SV_StudioSetupBones::pos[iVar14]);
    } while (iVar13 != -1);
  }
  if (1 < pseqdesc->numblends) {
                    /* Unresolved local var: float b@[???] */
    pmVar10 = R_GetAnim(pModel,(mstudioseqdesc_t *)
                               (pstudiohdr->name + local_288 + pstudiohdr->seqindex + -8));
    iVar13 = pstudiohdr->numbones;
    if (-1 < iVar19) {
      iVar14 = iVar19;
      do {
        iVar5 = local_27c[iVar14];
        iVar14 = iVar14 + -1;
        R_StudioCalcBoneQuaterion
                  (iVar16,local_2a0,(mstudiobone_t *)(psVar8->name + iVar5 * 0x70 + iVar4 + -8),
                   pmVar10 + iVar13 + iVar5,local_4c,SV_StudioSetupBones::lexical_block_1::q2[iVar5]
                  );
        R_StudioCalcBonePosition
                  (iVar16,local_2a0,(mstudiobone_t *)(psVar8->name + iVar5 * 0x70 + iVar4 + -8),
                   pmVar10 + iVar13 + iVar5,local_4c,
                   SV_StudioSetupBones::lexical_block_1::pos2[iVar5]);
      } while (iVar14 != -1);
      iVar13 = pstudiohdr->numbones;
    }
    psVar9 = pstudiohdr;
    local_2a4 = (float)*pblending / 255.0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec4_t q3@[???]
                       Unresolved local var: float s1@[???] */
    if (0.0 <= local_2a4) {
      if (local_2a4 <= 1.0) {
        local_2a0 = 1.0 - local_2a4;
      }
      else {
        local_2a0 = 0.0;
        local_2a4 = 1.0;
      }
    }
    else {
      local_2a0 = 1.0;
      local_2a4 = 0.0;
    }
    if (0 < iVar13) {
      pavVar15 = SV_StudioSetupBones::lexical_block_1::pos2;
      iVar16 = 0;
      p = SV_StudioSetupBones::q;
      pavVar18 = SV_StudioSetupBones::pos;
      do {
        iVar16 = iVar16 + 1;
        QuaternionSlerp(*p,p[0xe0],local_2a4,&local_2c);
        (*p)[0] = local_2c;
        fVar1 = (*pavVar18)[0];
        (*p)[1] = local_28;
        fVar2 = (*pavVar15)[0];
        (*p)[2] = local_24;
        (*p)[3] = local_20;
        p = p + 1;
        (*pavVar18)[0] = local_2a4 * fVar2 + local_2a0 * fVar1;
        (*pavVar18)[1] = local_2a4 * (*pavVar15)[1] + local_2a0 * (*pavVar18)[1];
        pvVar7 = *pavVar15;
        pavVar15 = pavVar15 + 1;
        (*pavVar18)[2] = local_2a4 * pvVar7[2] + local_2a0 * (*pavVar18)[2];
        pavVar18 = pavVar18 + 1;
      } while (iVar16 < psVar9->numbones);
    }
  }
  AngleMatrix(angles,rotationmatrix);
  rotationmatrix[0][3] = *origin;
  rotationmatrix[1][3] = origin[1];
  rotationmatrix[2][3] = origin[2];
  if (-1 < iVar19) {
    do {
      while( true ) {
        iVar16 = local_27c[iVar19];
        QuaternionMatrix(SV_StudioSetupBones::q[iVar16],(float (*) [4])local_7c);
        local_70 = SV_StudioSetupBones::pos[iVar16][0];
        local_60 = SV_StudioSetupBones::pos[iVar16][1];
        local_50 = SV_StudioSetupBones::pos[iVar16][2];
        if (*(int *)(psVar8->name + iVar16 * 0x70 + iVar4 + 0x18) != -1) break;
        iVar19 = iVar19 + -1;
        R_ConcatTransforms(rotationmatrix,(float (*) [4])local_7c,bonetransform[iVar16]);
        if (iVar19 == -1) {
          return;
        }
      }
      iVar19 = iVar19 + -1;
      R_ConcatTransforms(bonetransform[*(int *)(psVar8->name + iVar16 * 0x70 + iVar4 + 0x18)],
                         (float (*) [4])local_7c,bonetransform[iVar16]);
    } while (iVar19 != -1);
  }
  return;
}


// SV_Submerged  @ 000b4460
float SV_Submerged(edict_t_conflict *ent)

{
  float fVar1;
  float in;
  int iVar2;
  float fVar3;
  float local_2c;
  float local_28;
  float local_24;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float start@[???]
                       Unresolved local var: float end@[???]
                       Unresolved local var: float bottom@[???]
                       Unresolved local var: vec3_t center@[???] */
  iVar2 = (ent->v).waterlevel;
  local_2c = ((ent->v).absmin[0] + (ent->v).absmax[0]) * 0.5;
  local_28 = ((ent->v).absmin[1] + (ent->v).absmax[1]) * 0.5;
  fVar1 = (ent->v).absmin[2];
  local_10 = (ent->v).absmax[2];
  local_24 = (fVar1 + local_10) * 0.5;
  fVar1 = fVar1 - local_24;
  if (iVar2 == 2) {
LAB_000b4554:
    fVar3 = local_10 - local_24;
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
    in = fVar3 * 0.5 + 0.0;
    local_10 = local_24 + in;
    local_18 = local_2c;
    local_14 = local_28;
    iVar2 = SV_PointContents(&local_18);
    if (iVar2 == -3) {
      fVar3 = SV_RecursiveWaterLevel(&local_2c,fVar3,in,1);
    }
    else {
      fVar3 = SV_RecursiveWaterLevel(&local_2c,in,0.0,1);
    }
    return fVar3 - fVar1;
  }
  if (iVar2 == 3) {
                    /* Unresolved local var: vec3_t point@[???] */
    g_groupmask = (ent->v).groupinfo;
    local_18 = local_2c;
    local_14 = local_28;
    iVar2 = SV_PointContents(&local_18);
    if (iVar2 != -3) {
      local_10 = (ent->v).absmax[2];
      goto LAB_000b4554;
    }
    fVar1 = (ent->v).maxs[2] - (ent->v).mins[2];
  }
  else {
    if (iVar2 == 1) {
      fVar3 = SV_RecursiveWaterLevel(&local_2c,0.0,fVar1,0);
      return fVar3 - fVar1;
    }
    fVar1 = 0.0;
  }
  return fVar1;
}


// SV_TestEntityPosition  @ 000c12d0
edict_t_conflict * SV_TestEntityPosition(edict_t_conflict *ent)

{
  vec_t *maxs;
  vec_t *start;
  vec_t *mins;
  float fVar1;
  uint uVar2;
  uint uVar3;
  edict_t_conflict *peVar4;
  moveclip_t local_18c;
  trace_t local_108;
  undefined4 local_d0 [14];
  trace_t local_98;
  undefined4 auStack_60 [14];
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
                    /* Unresolved local var: moveclip_t clip@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t worldEndPoint@[???]
                       Unresolved local var: float worldFraction@[???] */
                    /* Unresolved local var: trace_t goodtrace@[???] */
  uVar3 = (ent->v).flags;
  maxs = (ent->v).maxs;
  start = (ent->v).origin;
  mins = (ent->v).mins;
  Q_memset(&local_18c,0,0x84);
  SV_SingleClipMoveToEntity(sv.edicts,start,mins,maxs,start,&local_98);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)auStack_60 + uVar2) =
         *(undefined4 *)((int)local_98.endpos + (uVar2 - 0x14));
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)local_18c.trace.endpos + (uVar2 - 0x14)) =
         *(undefined4 *)((int)auStack_60 + uVar2);
    fVar1 = local_18c.trace.fraction;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  if (local_18c.trace.fraction == 0.0) {
    uVar3 = 0;
    do {
      *(undefined4 *)((int)local_d0 + uVar3) =
           *(undefined4 *)((int)local_18c.trace.endpos + (uVar3 - 0x14));
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x38);
  }
  else {
    local_18c.trace.fraction = 1.0;
    local_28 = local_18c.trace.endpos[0];
    local_18c.type = 0;
    local_18c.passedict = ent;
    local_18c.ignoretrans = 0;
    local_24 = local_18c.trace.endpos[1];
    local_18c.monsterClipBrush = (qboolean)((uVar3 & 0x800000) != 0);
    local_18c.mins2[0] = (ent->v).mins[0];
    local_20 = local_18c.trace.endpos[2];
    local_18c.end = &local_28;
    local_18c.mins2[1] = (ent->v).mins[1];
    local_18c.mins2[2] = (ent->v).mins[2];
    local_18c.maxs2[0] = (ent->v).maxs[0];
    local_18c.maxs2[1] = (ent->v).maxs[1];
    local_18c.maxs2[2] = (ent->v).maxs[2];
    local_18c.mins = mins;
    local_18c.maxs = maxs;
    local_18c.start = start;
    SV_MoveBounds(start,local_18c.mins2,local_18c.maxs2,local_18c.end,local_18c.boxmins,
                  local_18c.boxmaxs);
    SV_ClipToLinks(sv_areanodes,&local_18c);
    gGlobalVariables.trace_ent = local_18c.trace.ent;
    uVar3 = 0;
    local_18c.trace.fraction = fVar1 * local_18c.trace.fraction;
    do {
      *(undefined4 *)((int)local_d0 + uVar3) =
           *(undefined4 *)((int)local_18c.trace.endpos + (uVar3 - 0x14));
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x38);
  }
  uVar3 = 0;
  do {
    *(undefined4 *)((int)local_108.endpos + (uVar3 - 0x14)) = *(undefined4 *)((int)local_d0 + uVar3)
    ;
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x38);
  peVar4 = (edict_t_conflict *)0x0;
  if (local_108.startsolid != false) {
    SV_SetGlobalTrace(&local_108);
    peVar4 = local_108.ent;
  }
  return peVar4;
}


// SV_TouchLinks  @ 000bf7b0
void SV_TouchLinks(edict_t_conflict *ent,areanode_t *node)

{
  edict_t_conflict *ent_00;
  float fVar1;
  link_s *plVar2;
  link_s *plVar3;
  uint uVar4;
  link_s *plVar5;
  hull_s *hull;
  int iVar6;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: link_t * l@[???]
                       Unresolved local var: link_t * next@[???]
                       Unresolved local var: edict_t.conflict * touch@[???]
                       Unresolved local var: model_t * pModel@[???] */
                    /* Unresolved local var: int contents@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t localPosition@[???] */
  plVar2 = (node->trigger_edicts).next;
joined_r0x000bf7d1:
  while( true ) {
    do {
      plVar5 = plVar2;
      if (plVar5 == &node->trigger_edicts) {
        iVar6 = node->axis;
        if (iVar6 != -1) {
          fVar1 = node->dist;
          if (fVar1 < (ent->v).absmax[iVar6]) {
            SV_TouchLinks(ent,node->children[0]);
            iVar6 = node->axis;
            fVar1 = node->dist;
          }
          if ((ent->v).absmin[iVar6] < fVar1) {
            SV_TouchLinks(ent,node->children[1]);
            return;
          }
        }
        return;
      }
      ent_00 = (edict_t_conflict *)(plVar5 + -1);
      plVar2 = plVar5->next;
    } while (ent_00 == ent);
    plVar3 = plVar5[0x57].prev;
    if ((plVar3 == (link_s *)0x0) || (uVar4 = (ent->v).groupinfo, uVar4 == 0)) break;
    if (g_groupop == 0) goto code_r0x000bf814;
    if ((g_groupop != 1) || ((uVar4 & (uint)plVar3) == 0)) break;
  }
  goto LAB_000bf820;
code_r0x000bf814:
  if ((uVar4 & (uint)plVar3) != 0) {
LAB_000bf820:
    if (((plVar5[0x30].next == (link_s *)0x1) &&
        (((((ent->v).absmin[0] <= (float)plVar5[0x29].prev &&
           ((ent->v).absmin[1] <= (float)plVar5[0x29].next)) &&
          ((ent->v).absmin[2] <= (float)plVar5[0x2a].prev)) &&
         (((float)plVar5[0x27].next <= (ent->v).absmax[0] &&
          ((float)plVar5[0x28].prev <= (ent->v).absmax[1])))))) &&
       ((float)plVar5[0x28].next <= (ent->v).absmax[2])) {
      if ((sv.models[(int)plVar5[0x25].next] != (model_s *)0x0) &&
         (sv.models[(int)plVar5[0x25].next]->type == mod_brush)) {
        hull = SV_HullForBsp(ent_00,(ent->v).mins,(ent->v).maxs,&local_34);
        local_28 = (ent->v).origin[0] - local_34;
        local_24 = (ent->v).origin[1] - local_30;
        local_20 = (ent->v).origin[2] - local_2c;
        iVar6 = SV_HullPointContents(hull,hull->firstclipnode,&local_28);
        if (iVar6 != -2) goto joined_r0x000bf7d1;
      }
      gGlobalVariables.time = (float)sv.time;
      (*gEntityInterface.pfnTouch)(ent_00,ent);
    }
  }
  goto joined_r0x000bf7d1;
}


// SV_Trace_Toss  @ 000b65d0
trace_t * SV_Trace_Toss(trace_t *__return_storage_ptr__,edict_t_conflict *ent,
                       edict_t_conflict *ignore)

{
  vec_t *veca;
  float fVar1;
  float fVar2;
  double dVar3;
  uint uVar4;
  edict_t_conflict local_390;
  trace_t local_6c;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: edict_t tempent@[???]
                       Unresolved local var: edict_t.conflict * tent@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: double save_frametime@[???] */
  dVar3 = host_frametime;
  host_frametime = 0.05;
  veca = local_390.v.angles;
  Q_memcpy(&local_390,ent,0x324);
  do {
    SV_CheckVelocity(&local_390);
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar1 = 1.0;
    if (local_390.v.gravity != 0.0) {
      fVar1 = local_390.v.gravity;
    }
    fVar2 = (float)host_frametime * local_390.v.basevelocity[2];
    local_390.v.basevelocity[2] = 0.0;
    local_390.v.velocity[2] =
         fVar2 + (local_390.v.velocity[2] - fVar1 * sv_gravity.value * (float)host_frametime);
    SV_CheckVelocity(&local_390);
    VectorMA(veca,(float)host_frametime,local_390.v.avelocity,veca);
    VectorScale(local_390.v.velocity,(float)host_frametime,&local_34);
    local_28 = local_390.v.origin[0] + local_34;
    local_24 = local_390.v.origin[1] + local_30;
    local_20 = local_390.v.origin[2] + local_2c;
    SV_Move(&local_6c,local_390.v.origin,local_390.v.mins,local_390.v.maxs,&local_28,0,&local_390,
            false);
    local_390.v.origin[0] = local_6c.endpos[0];
    local_390.v.origin[1] = local_6c.endpos[1];
    local_390.v.origin[2] = local_6c.endpos[2];
  } while ((local_6c.ent == (edict_t_conflict *)0x0) || (local_6c.ent == ignore));
  uVar4 = 0;
  host_frametime = dVar3;
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar4 - 0x14)) =
         *(undefined4 *)((int)local_6c.endpos + (uVar4 - 0x14));
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x38);
  __return_storage_ptr__->ent = local_6c.ent;
  return __return_storage_ptr__;
}


// SV_TransferConsistencyInfo  @ 000b8770
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_TransferConsistencyInfo(void)

{
  uchar *puVar1;
  resource_t *s1;
  resourcetype_t rVar2;
  char *s2;
  int iVar3;
  float *src;
  consistency_t *pcVar4;
  int iVar5;
  int iVar6;
  int local_140;
  char local_138 [259];
  undefined1 local_35;
  float local_34 [3];
  float local_28 [6];
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: char[260] filename@[???]
                       Unresolved local var: consistency_t * pc@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???] */
  local_140 = 0;
  if (0 < sv.num_resources) {
    iVar5 = 0;
    iVar3 = sv.num_resources;
    do {
      s1 = sv.resourcelist + iVar5;
                    /* Unresolved local var: int i@[???] */
      if ((-1 < (char)sv.resourcelist[iVar5].ucFlags) &&
         (sv.consistency_list[0].filename != (char *)0x0)) {
        pcVar4 = sv.consistency_list;
        iVar6 = 0;
        s2 = sv.consistency_list[0].filename;
        do {
          pcVar4 = pcVar4 + 1;
          iVar3 = Q_stricmp(s1->szFileName,s2);
          if (iVar3 == 0) {
            rVar2 = sv.resourcelist[iVar5].type;
            puVar1 = &sv.resourcelist[iVar5].ucFlags;
            *puVar1 = *puVar1 | 0x80;
            if (rVar2 == t_sound) {
              snprintf(local_138,0x104,"sound/%s",s1);
            }
            else {
              Q_strncpy(local_138,s1->szFileName,0x103);
              local_35 = 0;
            }
            MD5_Hash_File(sv.resourcelist[iVar5].rgucMD5_hash,local_138,0,0,(uint *)0x0);
            if (sv.resourcelist[iVar5].type == t_model) {
              iVar3 = sv.consistency_list[iVar6].check_type;
              if (iVar3 == 1) {
                iVar3 = R_GetStudioBounds(local_138,local_34,local_28);
                if (iVar3 == 0) {
                  Host_Error("Server unable to get bounds for %s\n",local_138);
                  return 0;
                }
                Q_memcpy(sv.resourcelist[iVar5].rguc_reserved + 1,local_34,0xc);
                src = local_28;
              }
              else {
                if ((iVar3 < 1) || (3 < iVar3)) goto LAB_000b882f;
                Q_memcpy(sv.resourcelist[iVar5].rguc_reserved + 1,sv.consistency_list[iVar6].mins,
                         0xc);
                src = sv.consistency_list[iVar6].maxs;
              }
              Q_memcpy(sv.resourcelist[iVar5].rguc_reserved + 0xd,src,0xc);
              sv.resourcelist[iVar5].rguc_reserved[0] = (uchar)sv.consistency_list[iVar6].check_type
              ;
              COM_Munge(sv.resourcelist[iVar5].rguc_reserved,0x20,svs.spawncount);
            }
LAB_000b882f:
            local_140 = local_140 + 1;
            iVar3 = sv.num_resources;
            break;
          }
          iVar6 = iVar6 + 1;
          s2 = pcVar4->filename;
          iVar3 = sv.num_resources;
        } while (s2 != (char *)0x0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  return local_140;
}


// SV_UnlagCheckTeleport  @ 000b9ae0
int SV_UnlagCheckTeleport(vec_t *v1,vec_t *v2)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???] */
  uVar1 = 1;
  if ((ABS(*v1 - *v2) <= 128.0) && (ABS(v1[1] - v2[1]) <= 128.0)) {
    uVar1 = (uint)(128.0 < ABS(v1[2] - v2[2]));
  }
  return uVar1;
}


// SV_UnlinkEdict  @ 000bf580
void SV_UnlinkEdict(edict_t_conflict *ent)

{
  link_s *plVar1;
  
  plVar1 = (ent->area).prev;
  if (plVar1 != (link_s *)0x0) {
    ((ent->area).next)->prev = plVar1;
    ((ent->area).prev)->next = (ent->area).next;
    (ent->area).next = (link_s *)0x0;
    (ent->area).prev = (link_s *)0x0;
  }
  return;
}


// SV_UpdateToReliableMessages  @ 000a5f30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_UpdateToReliableMessages(void)

{
  sizebuf_t *sb;
  _UserMsg *p_Var1;
  float fVar2;
  client_s *pcVar3;
  int iVar4;
  UserMsg *pUVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: client_t * client@[???] */
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar6 = 0;
    pcVar3 = svs.clients;
    iVar4 = svs.maxclients;
    do {
      host_client = pcVar3;
      if (pcVar3->edict != (edict_t_conflict *)0x0) {
        if ((pcVar3->sendinfo != false) && (fVar2 = (float)realtime, pcVar3->sendinfo_time <= fVar2)
           ) {
          pcVar3->sendinfo = false;
          pcVar3->sendinfo_time = fVar2 + 1.0;
          SV_ExtractFromUserinfo(pcVar3);
          SV_FullClientUpdate(host_client,&sv.reliable_datagram);
        }
        iVar4 = svs.maxclients;
        if ((host_client->fakeclient == false) &&
           ((host_client->active != false || (host_client->connected != false)))) {
          sb = &(host_client->netchan).message;
          for (p_Var1 = sv_gpNewUserMsgs; svs.maxclients = iVar4, p_Var1 != (UserMsg *)0x0;
              p_Var1 = p_Var1->next) {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
            MSG_WriteByte(sb,0x27);
            MSG_WriteByte(sb,p_Var1->iMsg);
            MSG_WriteByte(sb,p_Var1->iSize);
            MSG_WriteLong(sb,*(int *)p_Var1->szName);
            MSG_WriteLong(sb,*(int *)(p_Var1->szName + 4));
            MSG_WriteLong(sb,*(int *)(p_Var1->szName + 8));
            MSG_WriteLong(sb,*(int *)(p_Var1->szName + 0xc));
            iVar4 = svs.maxclients;
          }
        }
      }
      iVar6 = iVar6 + 1;
      pcVar3 = host_client + 1;
      host_client = pcVar3;
    } while (iVar6 < iVar4);
  }
  if (sv_gpNewUserMsgs != (UserMsg *)0x0) {
    p_Var1 = sv_gpUserMsgs;
    pUVar5 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != (UserMsg *)0x0) {
      do {
        pUVar5 = p_Var1;
        p_Var1 = pUVar5->next;
      } while (p_Var1 != (_UserMsg *)0x0);
      pUVar5->next = sv_gpNewUserMsgs;
      pUVar5 = sv_gpUserMsgs;
    }
    sv_gpUserMsgs = pUVar5;
    sv_gpNewUserMsgs = (UserMsg *)0x0;
  }
  if (((byte)sv.datagram.flags & 2) != 0) {
    Con_DPrintf("sv.datagram overflowed!\n");
    SZ_Clear(&sv.datagram);
  }
  if (((byte)sv.spectator.flags & 2) != 0) {
    Con_DPrintf("sv.spectator overflowed!\n");
    SZ_Clear(&sv.spectator);
  }
  if (0 < svs.maxclients) {
    iVar6 = 0;
    iVar4 = svs.maxclients;
    pcVar3 = svs.clients;
    do {
      if ((pcVar3->fakeclient == false) && (pcVar3->active != false)) {
        if ((pcVar3->netchan).message.cursize + sv.reliable_datagram.cursize <
            (pcVar3->netchan).message.maxsize) {
          SZ_Write(&(pcVar3->netchan).message,sv.reliable_datagram.data,sv.reliable_datagram.cursize
                  );
        }
        else {
          Netchan_CreateFragments(true,&pcVar3->netchan,&sv.reliable_datagram);
        }
        if ((pcVar3->datagram).cursize + sv.datagram.cursize < (pcVar3->datagram).maxsize) {
          SZ_Write(&pcVar3->datagram,sv.datagram.data,sv.datagram.cursize);
        }
        else {
          Con_DPrintf("Warning:  Ignoring unreliable datagram for %s, would overflow\n",pcVar3->name
                     );
        }
        iVar4 = svs.maxclients;
        if ((pcVar3->proxy != false) &&
           ((pcVar3->datagram).cursize + sv.spectator.cursize < (pcVar3->datagram).maxsize)) {
          SZ_Write(&pcVar3->datagram,sv.spectator.data,sv.spectator.cursize);
          iVar4 = svs.maxclients;
        }
      }
      iVar6 = iVar6 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar6 < iVar4);
  }
  SZ_Clear(&sv.reliable_datagram);
  SZ_Clear(&sv.datagram);
  SZ_Clear(&sv.spectator);
  return;
}


// SV_UploadComplete  @ 000b7280
qboolean SV_UploadComplete(client_t *cl)

{
  resource_t *prVar1;
  resource_t *pResource;
  client_t *pHost;
  qboolean qVar2;
  qboolean bSkipPlayer;
  
  pHost = host_client;
  qVar2 = false;
  if ((cl->resourcesneeded).pNext == &cl->resourcesneeded) {
                    /* Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: client_t * pHost@[???] */
    pResource = (host_client->resourcesonhand).pNext;
    prVar1 = &host_client->resourcesonhand;
    host_client->uploading = false;
    for (; pResource != prVar1; pResource = pResource->pNext) {
      SV_CreateCustomizationList(pHost);
      SV_Customization(pHost,pResource,bSkipPlayer);
    }
    host_client = pHost;
    SV_PropagateCustomizations();
    if (sv_allow_upload.value != 0.0) {
      Con_DPrintf("Custom resource propagation complete.\n");
    }
    qVar2 = true;
    cl->uploaddoneregistering = true;
  }
  return qVar2;
}


// SV_User_f  @ 0009bd80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_User_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  client_s *pcVar5;
  int iVar6;
  
                    /* Unresolved local var: int uid@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (sv.active == false) {
    Con_Printf("Can\'t \'user\', not running a server\n");
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("Usage: user <username / userid>\n");
    return;
  }
                    /* Unresolved local var: int uid@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  pcVar2 = Cmd_Argv(1);
  iVar1 = Q_atoi(pcVar2);
  if (0 < svs.maxclients) {
    iVar6 = 0;
    iVar4 = svs.maxclients;
    pcVar5 = svs.clients;
    do {
      if ((((pcVar5->active != false) || (pcVar5->spawned != false)) || (pcVar5->connected != false)
          ) && ((pcVar5->fakeclient == false && (pcVar5->name[0] != '\0')))) {
        if (iVar1 == pcVar5->userid) {
LAB_0009be78:
          Info_Print(pcVar5->userinfo);
          return;
        }
        pcVar2 = Cmd_Argv(1);
        iVar3 = Q_strcmp(pcVar5->name,pcVar2);
        iVar4 = svs.maxclients;
        if (iVar3 == 0) goto LAB_0009be78;
      }
      iVar6 = iVar6 + 1;
      pcVar5 = pcVar5 + 1;
    } while (iVar6 < iVar4);
  }
  Con_Printf("User not in server.\n");
  return;
}


// SV_Users_f  @ 000ab9b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Users_f(void)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  client_s *pcVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (sv.active == false) {
    Con_Printf("Can\'t \'users\', not running a server\n");
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: client_t * cl@[???] */
  iVar7 = 0;
  Con_Printf("userid : uniqueid : name\n");
  Con_Printf("------ : ---------: ----\n");
  if (0 < svs.maxclients) {
    iVar6 = 0;
    iVar3 = svs.maxclients;
    pcVar5 = svs.clients;
    do {
      while ((((pcVar5->active == false && (pcVar5->spawned == false)) &&
              (pcVar5->connected == false)) ||
             ((pcVar5->fakeclient != false || (pcVar5->name[0] == '\0'))))) {
        iVar6 = iVar6 + 1;
        pcVar5 = pcVar5 + 1;
        if (iVar3 <= iVar6) goto LAB_000abad0;
      }
      SV_GetClientIDString::idstr[0] = '\0';
      pcVar1 = pcVar5->name;
      if (((pcVar5->netchan).remote_address.type == NA_LOOPBACK) &&
         ((pcVar5->network_userid).idtype == 2)) {
        snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
      }
      else {
                    /* Unresolved local var: USERID_t * id@[???] */
        pcVar4 = SV_GetIDString(&pcVar5->network_userid);
        snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar4);
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 1;
      piVar2 = &pcVar5->userid;
      pcVar5 = pcVar5 + 1;
      Con_Printf("%6i : %s : %s\n",*piVar2,SV_GetClientIDString::idstr,pcVar1);
      iVar3 = svs.maxclients;
    } while (iVar6 < svs.maxclients);
  }
LAB_000abad0:
  Con_Printf("%i users\n",iVar7);
  return;
}


// SV_ValidClientMulticast  @ 0009d290
qboolean SV_ValidClientMulticast(client_t *client,int soundLeaf,int to)

{
  qboolean qVar1;
  uint uVar2;
  mleaf_t *pmVar3;
  int iVar4;
  uchar *puVar5;
  byte bVar6;
  int iVar7;
  
                    /* Unresolved local var: uchar * mask@[???]
                       Unresolved local var: int destination@[???] */
  qVar1 = Host_IsSinglePlayerGame();
  if (qVar1 != false) {
    return true;
  }
  if (client->proxy != false) {
    return true;
  }
  uVar2 = to & 0xffffff7f;
  if (uVar2 == 2) {
    puVar5 = CM_LeafPVS(soundLeaf);
  }
  else {
    if (uVar2 != 4) {
      if (uVar2 == 1) {
        return true;
      }
      Con_Printf("MULTICAST: Error %d!\n",to);
      return false;
    }
    puVar5 = CM_LeafPAS(soundLeaf);
  }
  if (puVar5 == (uchar *)0x0) {
    return true;
  }
                    /* Unresolved local var: int bitNumber@[???]
                       Unresolved local var: mleaf_t * pLeaf@[???] */
  pmVar3 = Mod_PointInLeaf((client->edict->v).origin,sv.worldmodel);
  if (pmVar3 == (mleaf_t *)0x0) {
    bVar6 = 7;
    iVar7 = -1;
  }
  else {
    iVar4 = ((int)pmVar3 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
    iVar7 = iVar4 >> 3;
    bVar6 = (byte)iVar4 & 7;
  }
  return (uint)(((int)(uint)puVar5[iVar7] >> bVar6 & 1U) != 0);
}


// SV_ValidateClientCommand  @ 000b9910
int SV_ValidateClientCommand(char *pszCommand)

{
  int iVar1;
  int iVar2;
  command_t s2;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???] */
  COM_Parse(pszCommand);
  iVar1 = 0;
  if (clcommands[0].command != (char *)0x0) {
    iVar1 = 0;
    s2 = clcommands[0];
    while( true ) {
      iVar2 = Q_strcasecmp(com_token,s2.command);
      if (iVar2 == 0) break;
      iVar1 = iVar1 + 1;
      s2.command = clcommands[iVar1].command;
      if (s2.command == (char *)0x0) {
        return 0;
      }
    }
    iVar1 = 1;
  }
  return iVar1;
}


// SV_WriteClientdataToMessage  @ 0009e8a0
void SV_WriteClientdataToMessage(client_t *client,sizebuf_t *msg)

{
  clientdata_t *to;
  edict_s *peVar1;
  client_frame_t *pcVar2;
  double dVar3;
  int iVar4;
  uint32 data;
  uint uVar5;
  clientdata_t *from;
  weapon_data_t *from_00;
  client_frame_t *pcVar6;
  clientdata_t local_250;
  weapon_data_t local_74;
  
                    /* Unresolved local var: int bits@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: clientdata_t * from@[???]
                       Unresolved local var: clientdata_t * to@[???]
                       Unresolved local var: clientdata_t baseline@[???]
                       Unresolved local var: qboolean force@[???] */
  from = &local_250;
  Q_memset(from,0,0x1dc);
  dVar3 = realtime;
  peVar1 = (edict_s *)client->edict;
  pcVar6 = client->frames + (SV_UPDATE_MASK & (client->netchan).outgoing_sequence);
  pcVar6->ping_time = -1.0;
  pcVar6->senttime = dVar3;
  if (client->chokecount != 0) {
    MSG_WriteByte(msg,0x2a);
    client->chokecount = 0;
  }
  iVar4 = (peVar1->v).fixangle;
  if (iVar4 != 0) {
    if (iVar4 == 2) {
      MSG_WriteByte(msg,0x26);
      MSG_WriteHiresAngle(msg,(peVar1->v).avelocity[1]);
      (peVar1->v).avelocity[1] = 0.0;
    }
    else {
      MSG_WriteByte(msg,10);
      MSG_WriteHiresAngle(msg,(peVar1->v).angles[0]);
      MSG_WriteHiresAngle(msg,(peVar1->v).angles[1]);
      MSG_WriteHiresAngle(msg,(peVar1->v).angles[2]);
    }
    (peVar1->v).fixangle = 0;
  }
  to = &pcVar6->clientdata;
  Q_memset(to,0,0x1dc);
  (*gEntityInterface.pfnUpdateClientData)(peVar1,SUB14(host_client->lw != 0,0),to);
  MSG_WriteByte(msg,0xf);
  if (client->proxy != false) {
    return;
  }
  MSG_StartBitWriting(msg);
  if (host_client->delta_sequence == 0xffffffff) {
    MSG_WriteBits(0,1);
  }
  else {
    uVar5 = SV_UPDATE_MASK & host_client->delta_sequence;
    pcVar2 = host_client->frames;
    MSG_WriteBits(1,1);
    from = &pcVar2[uVar5].clientdata;
    MSG_WriteBits(host_client->delta_sequence,8);
  }
  DELTA_WriteDelta((uchar *)from,(uchar *)to,true,g_pclientdelta,(_func_void *)0x0);
  if (host_client->lw != 0) {
                    /* Unresolved local var: weapon_data_t * fdata@[???]
                       Unresolved local var: weapon_data_t * tdata@[???]
                       Unresolved local var: weapon_data_t wbaseline@[???] */
    Q_memset(&local_74,0,0x58);
    iVar4 = (*gEntityInterface.pfnGetWeaponData)((edict_s *)host_client->edict,pcVar6->weapondata);
    if (iVar4 != 0) {
      data = 0;
      do {
        from_00 = &local_74;
        if (host_client->delta_sequence != 0xffffffff) {
          from_00 = host_client->frames[host_client->delta_sequence & SV_UPDATE_MASK].weapondata +
                    data;
        }
        iVar4 = DELTA_CheckDelta((uchar *)from_00,(uchar *)(pcVar6->weapondata + data),
                                 g_pweapondelta);
        if (iVar4 != 0) {
          MSG_WriteBits(1,1);
          MSG_WriteBits(data,6);
          DELTA_WriteDelta((uchar *)from_00,(uchar *)(pcVar6->weapondata + data),true,g_pweapondelta
                           ,(_func_void *)0x0);
        }
        data = data + 1;
      } while (data != 0x40);
    }
  }
  MSG_WriteBits(0,1);
  MSG_EndBitWriting(msg);
  return;
}


// SV_WriteDeltaDescriptionsToClient  @ 0009dcb0
void SV_WriteDeltaDescriptionsToClient(sizebuf_t *msg)

{
  uint32 data;
  delta_info_s *pdVar1;
  int iVar2;
  uint32 uVar3;
  int iVar4;
  uchar local_60 [80];
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: delta_info_t * p@[???]
                       Unresolved local var: delta_description_t nulldesc@[???]
                       Unresolved local var: delta_description_t * from@[???]
                       Unresolved local var: delta_description_t * to@[???] */
  Q_memset(local_60,0,0x44);
  for (pdVar1 = g_sv_delta; pdVar1 != (delta_info_t *)0x0; pdVar1 = pdVar1->next) {
    MSG_WriteByte(msg,0xe);
    MSG_WriteString(msg,pdVar1->name);
    data = pdVar1->delta->fieldCount;
    MSG_StartBitWriting(msg);
    MSG_WriteBits(data,0x10);
    if (0 < (int)data) {
      uVar3 = 0;
      iVar4 = 0;
      do {
        uVar3 = uVar3 + 1;
        iVar2 = iVar4 + -4;
        iVar4 = iVar4 + 0x44;
        DELTA_WriteDelta(local_60,(uchar *)(pdVar1->delta->pdd->fieldName + iVar2),true,&g_MetaDelta
                         ,(_func_void *)0x0);
      } while (uVar3 != data);
    }
    MSG_EndBitWriting(msg);
  }
  return;
}


// SV_WriteDeltaHeader  @ 000a42f0
void SV_WriteDeltaHeader(int num,qboolean remove,qboolean custom,int *numbase,qboolean newbl,
                        int newblindex,qboolean full,int offset)

{
  uint32 data;
  uint data_00;
  
                    /* Unresolved local var: int delta@[???] */
  data = num - *numbase;
  if (full == false) {
    data_00 = (uint)(remove != false);
LAB_000a435e:
    MSG_WriteBits(data_00,1);
    if (0x3e < data - 1) {
      MSG_WriteBits(1,1);
      MSG_WriteBits(num,0xb);
      goto LAB_000a4391;
    }
    MSG_WriteBits(0,1);
    MSG_WriteBits(data,6);
    *numbase = num;
  }
  else {
    if (data != 1) {
      data_00 = 0;
      goto LAB_000a435e;
    }
    MSG_WriteBits(1,1);
LAB_000a4391:
    *numbase = num;
  }
  if (remove == false) {
    MSG_WriteBits((uint)(custom != false),1);
    if ((sv.instance_baselines)->number != 0) {
      if (newbl != false) {
        MSG_WriteBits(1,1);
        remove = 6;
        num = newblindex;
        goto LAB_000a442c;
      }
      MSG_WriteBits(0,1);
    }
    if ((full != false) && (newbl == false)) {
      if (offset == 0) {
        remove = true;
        num = 0;
      }
      else {
        MSG_WriteBits(1,1);
        num = offset;
        remove = 6;
      }
LAB_000a442c:
      MSG_WriteBits(num,remove);
      return;
    }
  }
  return;
}


// SV_WriteEntitiesToClient  @ 000a53d0
void SV_WriteEntitiesToClient(client_t *client,sizebuf_t *msg)

{
  uchar *puVar1;
  client_frame_t *pcVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  entity_state_s *peVar6;
  ushort uVar7;
  packet_entities_t *to;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iStack_1543c;
  entity_state_s aeStack_15438 [256];
  uchar *local_2c [3];
  uchar *local_20 [4];
  
                    /* Unresolved local var: full_packet_entities_t fullpack@[???]
                       Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: qboolean sendping@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: uchar * pvs@[???]
                       Unresolved local var: uchar * pas@[???]
                       Unresolved local var: int ev_count@[???]
                       Unresolved local var: int skipents@[???]
                       Unresolved local var: uchar * pSet@[???] */
  local_2c[0] = (uchar *)0x0;
  local_20[0] = (uchar *)0x0;
  pcVar2 = client->frames + (SV_UPDATE_MASK & (client->netchan).outgoing_sequence);
  (*gEntityInterface.pfnSetupVisibility)
            (client->pViewEntity,(edict_s *)client->edict,local_2c,local_20);
                    /* Unresolved local var: packet_entities_t * pack@[???] */
  if (pcVar2 != (client_frame_t *)0x0) {
    peVar6 = (pcVar2->entities).entities;
    if (peVar6 != (entity_state_s *)0x0) {
      Mem_Free(peVar6);
    }
    (pcVar2->entities).entities = (entity_state_s *)0x0;
    (pcVar2->entities).num_entities = 0;
  }
  puVar1 = local_2c[0];
  iStack_1543c = 0;
  to = &pcVar2->entities;
  if (client->proxy == false) {
    uVar7 = (client->lastcmd).buttons & 0x8000;
  }
  else if (realtime < client->nextping) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
    client->nextping = realtime + 2.0;
  }
  iVar5 = client->lw;
  iVar11 = 0;
  if (1 < sv.num_edicts) {
    iVar10 = 0;
    iVar12 = 0x324;
    iVar9 = 1;
    iVar8 = sv.num_edicts;
    do {
                    /* Unresolved local var: int player@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: entity_state_t * state@[???] */
      iVar3 = 0;
      if (svs.maxclients < iVar9) {
LAB_000a5561:
        if (0xff < iVar11) {
          Con_DPrintf("Too many entities in visible packet list.\n");
          iVar11 = iStack_1543c;
          break;
        }
        iVar3 = (*gEntityInterface.pfnAddToFullPack)
                          (aeStack_15438 + iVar11,iVar9,
                           (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar12 + -0x18),
                           host_client->edict,SUB14(iVar5 != 0,0),iVar3,puVar1);
        iVar8 = sv.num_edicts;
        iVar11 = iStack_1543c;
        if (iVar3 != 0) {
          iVar11 = iStack_1543c + 1;
          iStack_1543c = iVar11;
        }
      }
      else {
        puVar4 = ((svs.clients)->netchan).remote_address.ip + iVar10 + -0x24;
        if (((*(int *)puVar4 != 0) || (*(int *)(puVar4 + 4) != 0)) &&
           (*(int *)(puVar4 + 0x243c) == 0)) {
          iVar3 = 1;
          goto LAB_000a5561;
        }
      }
      iVar9 = iVar9 + 1;
      iVar12 = iVar12 + 0x324;
      iVar10 = iVar10 + 0x4ef8;
    } while (iVar9 < iVar8);
  }
  iVar5 = iRam000017e8;
  if (pcVar2 != (client_frame_t *)0x0) {
    peVar6 = (pcVar2->entities).entities;
    if (peVar6 != (entity_state_s *)0x0) {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
      Mem_Free(peVar6);
      (pcVar2->entities).entities = (entity_state_s *)0x0;
      (pcVar2->entities).num_entities = 0;
    }
    iVar5 = 1;
    if (0 < iVar11) {
      iVar5 = iVar11;
    }
    peVar6 = Mem_ZeroMalloc(iVar5 * 0x154);
    (pcVar2->entities).num_entities = iVar11;
    (pcVar2->entities).entities = peVar6;
    iVar5 = iVar11;
  }
  if (iVar5 != 0) {
    Q_memcpy((pcVar2->entities).entities,aeStack_15438,iVar5 * 0x154);
  }
  if (client->delta_sequence == -1) {
    SV_CreatePacketEntities(sv_packet_nodelta,client,to,msg);
  }
  else {
    SV_CreatePacketEntities(sv_packet_delta,client,to,msg);
  }
  SV_EmitEvents(client,to,msg);
  if (uVar7 != 0) {
    SV_EmitPings(client,msg);
  }
  return;
}


// SV_WriteIP_f  @ 0009ba80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_WriteIP_f(void)

{
  uint uVar1;
  FileHandle_t file;
  int iVar2;
  int iVar3;
  char local_110 [264];
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: uchar[4] b@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???] */
  snprintf(local_110,0x104,"listip.cfg");
  Con_Printf("Writing %s.\n",local_110);
  file = FS_Open(local_110,"wb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("Couldn\'t open %s\n",local_110);
  }
  else {
    if (0 < numipfilters) {
      iVar3 = 0;
      iVar2 = numipfilters;
      do {
        while (uVar1 = ipfilters[iVar3].compare, ipfilters[iVar3].banTime == 0.0) {
          iVar3 = iVar3 + 1;
          FS_FPrintf(file,"addip 0.0 %i.%i.%i.%i\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
                     uVar1 >> 0x10 & 0xff,uVar1 >> 0x18);
          iVar2 = numipfilters;
          if (numipfilters <= iVar3) goto LAB_0009bb44;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
LAB_0009bb44:
    FS_Close(file);
  }
  return;
}


// SV_WriteId_f  @ 000ab390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_WriteId_f(void)

{
  char *pcVar1;
  int iVar2;
  FileHandle_t file;
  int iVar3;
  float *pfVar4;
  char local_110 [260];
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???] */
  if ((((*bannedcfgfile.string == '/') ||
       (pcVar1 = Q_strstr(bannedcfgfile.string,":"), pcVar1 != (char *)0x0)) ||
      (pcVar1 = Q_strstr(bannedcfgfile.string,".."), pcVar1 != (char *)0x0)) ||
     (pcVar1 = Q_strstr(bannedcfgfile.string,"\\"), pcVar1 != (char *)0x0)) {
    Con_Printf("Couldn\'t open %s (contains illegal characters).\n",bannedcfgfile.string);
  }
  else {
    Q_strncpy(local_110,bannedcfgfile.string,0xff);
    COM_DefaultExtension(local_110,".cfg");
    pcVar1 = COM_LastFileExtension(local_110);
    iVar2 = Q_strcmp(pcVar1,"cfg");
    if (iVar2 == 0) {
      Con_Printf("Writing %s.\n",local_110);
      file = FS_Open(local_110,"wt");
      if (file == (FileHandle_t)0x0) {
        Con_Printf("Couldn\'t open %s\n",local_110);
      }
      else {
        if (0 < numuserfilters) {
          pfVar4 = &userfilters[0].banTime;
          iVar3 = 0;
          iVar2 = numuserfilters;
          do {
            if (*pfVar4 == 0.0) {
              pcVar1 = SV_GetIDString(&userfilters[iVar3].userid);
              FS_FPrintf(file,"banid 0.0 %s\n",pcVar1);
              iVar2 = numuserfilters;
            }
            iVar3 = iVar3 + 1;
            pfVar4 = pfVar4 + 6;
          } while (iVar3 < iVar2);
        }
        FS_Close(file);
      }
    }
    else {
      Con_Printf("Couldn\'t open %s (wrong file extension, must be .cfg).\n",local_110);
    }
  }
  return;
}


// SV_WriteId_f  @ 000ab540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_WriteId_f(void)

{
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???] */
  if ((bannedcfgfile.string != (char *)0x0) && (*bannedcfgfile.string != '\0')) {
    SV_WriteId_f();
    return;
  }
  Con_Printf("Couldn\'t open banned config file, no file name specified.\n");
  return;
}


// SV_WriteMovevarsToClient  @ 0009dad0
void SV_WriteMovevarsToClient(sizebuf_t *message)

{
  MSG_WriteByte(message,0x2c);
  MSG_WriteFloat(message,movevars.gravity);
  MSG_WriteFloat(message,movevars.stopspeed);
  MSG_WriteFloat(message,movevars.maxspeed);
  MSG_WriteFloat(message,movevars.spectatormaxspeed);
  MSG_WriteFloat(message,movevars.accelerate);
  MSG_WriteFloat(message,movevars.airaccelerate);
  MSG_WriteFloat(message,movevars.wateraccelerate);
  MSG_WriteFloat(message,movevars.friction);
  MSG_WriteFloat(message,movevars.edgefriction);
  MSG_WriteFloat(message,movevars.waterfriction);
  MSG_WriteFloat(message,movevars.entgravity);
  MSG_WriteFloat(message,movevars.bounce);
  MSG_WriteFloat(message,movevars.stepsize);
  MSG_WriteFloat(message,movevars.maxvelocity);
  MSG_WriteFloat(message,movevars.zmax);
  MSG_WriteFloat(message,movevars.waveHeight);
  MSG_WriteByte(message,(uint)(movevars.footsteps != false));
  MSG_WriteFloat(message,movevars.rollangle);
  MSG_WriteFloat(message,movevars.rollspeed);
  MSG_WriteFloat(message,movevars.skycolor_r);
  MSG_WriteFloat(message,movevars.skycolor_g);
  MSG_WriteFloat(message,movevars.skycolor_b);
  MSG_WriteFloat(message,movevars.skyvec_x);
  MSG_WriteFloat(message,movevars.skyvec_y);
  MSG_WriteFloat(message,movevars.skyvec_z);
  MSG_WriteString(message,movevars.skyName);
  return;
}


// SV_WriteSpawn  @ 000a3640
void SV_WriteSpawn(sizebuf_t *msg)

{
  int *piVar1;
  char **ppcVar2;
  edict_t_conflict *peVar3;
  edict_t_conflict *peVar4;
  client_t *pcVar5;
  char *pcVar6;
  client_s *cl;
  int iVar7;
  int iVar8;
  undefined1 local_680 [36];
  int local_65c;
  char local_654 [1352];
  char local_10c [256];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: SAVERESTOREDATA currentLevelData@[???]
                       Unresolved local var: client_t * client@[???] */
  if (sv.loadgame == false) {
    sv.state = ss_loading;
    ReleaseEntityDLLFields(sv_player);
    Q_memset(&sv_player->v,0,0x2a4);
    InitEntityDLLFields(sv_player);
    peVar3 = sv_player;
    iVar7 = NUM_FOR_EDICT((edict_t *)sv_player);
    peVar4 = sv_player;
    pcVar5 = host_client;
    (peVar3->v).colormap = iVar7;
    (peVar4->v).netname = (int)pcVar5 + (0x4be8 - (int)pr_strings);
    if (pcVar5->proxy != false) {
      piVar1 = &(peVar4->v).flags;
      *piVar1 = *piVar1 | 0x100000;
    }
    gGlobalVariables.time = (float)sv.time;
    (*gEntityInterface.pfnClientPutInServer)(peVar4);
    sv.state = ss_active;
  }
  else {
    if (host_client->proxy != false) {
      Con_Printf("ERROR! Spectator mode doesn\'t work with saved game.\n");
      return;
    }
    sv.paused = false;
  }
  SZ_Clear(&(host_client->netchan).message);
  SZ_Clear(&host_client->datagram);
  MSG_WriteByte(msg,7);
  MSG_WriteFloat(msg,(float)sv.time);
  cl = svs.clients;
  pcVar5 = host_client;
  host_client->sendinfo = true;
  if (0 < svs.maxclients) {
    iVar8 = 0;
    iVar7 = svs.maxclients;
    while( true ) {
      if ((((cl == pcVar5) || (cl->active != false)) || (cl->connected != false)) ||
         (cl->spawned != false)) {
        SV_FullClientUpdate(cl,msg);
        iVar7 = svs.maxclients;
      }
      iVar8 = iVar8 + 1;
      if (iVar7 <= iVar8) break;
      cl = cl + 1;
      pcVar5 = host_client;
    }
  }
  iVar7 = 0;
  do {
    MSG_WriteByte(msg,0xc);
    MSG_WriteByte(msg,iVar7);
    ppcVar2 = sv.lightstyles + iVar7;
    iVar7 = iVar7 + 1;
    MSG_WriteString(msg,*ppcVar2);
  } while (iVar7 != 0x40);
  if (host_client->proxy == false) {
    MSG_WriteByte(msg,10);
    MSG_WriteHiresAngle(msg,(sv_player->v).v_angle[0]);
    MSG_WriteHiresAngle(msg,(sv_player->v).v_angle[1]);
    MSG_WriteHiresAngle(msg,0.0);
    SV_WriteClientdataToMessage(host_client,msg);
    if (sv.loadgame != false) {
      Q_memset(local_680,0,0x574);
      gGlobalVariables.pSaveData = local_680;
      (*gEntityInterface.pfnParmsChangeLevel)();
      MSG_WriteByte(msg,0x21);
      pcVar6 = Host_SaveGameDirectory();
      snprintf(local_10c,0x100,"%s%s.HL2",pcVar6,0x506a28);
      COM_FixSlashes(local_10c);
      MSG_WriteString(msg,local_10c);
      MSG_WriteByte(msg,local_65c);
      if (0 < local_65c) {
        iVar7 = 0;
        do {
          iVar8 = iVar7 + 1;
          MSG_WriteString(msg,local_654 + iVar7 * 0x50);
          iVar7 = iVar8;
        } while (iVar8 < local_65c);
      }
      sv.loadgame = false;
      gGlobalVariables.pSaveData = (void *)0x0;
    }
  }
  MSG_WriteByte(msg,0x19);
  MSG_WriteByte(msg,1);
  host_client->active = true;
  pcVar5 = host_client;
  *(undefined4 *)&host_client->connecttime = 0;
  *(undefined4 *)((int)&pcVar5->connecttime + 4) = 0;
  *(undefined4 *)&pcVar5->ignorecmdtime = 0;
  *(undefined4 *)((int)&pcVar5->ignorecmdtime + 4) = 0;
  *(undefined4 *)&pcVar5->cmdtime = 0;
  *(undefined4 *)((int)&pcVar5->cmdtime + 4) = 0;
  pcVar5->spawned = true;
  pcVar5->connected = true;
  pcVar5->fully_connected = false;
  NotifyDedicatedServerUI("UpdatePlayers");
  return;
}


// SV_WriteVoiceCodec  @ 000a6ff0
void SV_WriteVoiceCodec(sizebuf_t *pBuf)

{
  MSG_WriteByte(pBuf,0x34);
  MSG_WriteString(pBuf,"");
  MSG_WriteByte(pBuf,0);
  return;
}


// SV_movestep  @ 000ae950
qboolean __regparm3 SV_movestep(edict_t_conflict *ent,vec_t *move,qboolean relink)

{
  vec_t *pvVar1;
  vec_t *pvVar2;
  vec_t *start;
  float fVar3;
  float fVar4;
  float fVar5;
  edict_t_conflict *peVar6;
  uint uVar7;
  qboolean qVar8;
  int iVar9;
  trace_t local_bc;
  int local_7c [4];
  float local_6c;
  vec_t local_68;
  vec_t local_64;
  vec_t vStack_60;
  edict_t_conflict *peStack_4c;
  float local_3c;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float dz@[???]
                       Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t.conflict * enemy@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  fVar3 = (ent->v).origin[0];
  fVar4 = (ent->v).origin[1];
  fVar5 = (ent->v).origin[2];
  local_3c = *move + fVar3;
  uVar7 = (ent->v).flags;
  qVar8 = (qboolean)((uVar7 & 0x800000) != 0);
  local_38 = move[1] + fVar4;
  local_34 = move[2] + fVar5;
  if ((uVar7 & 3) != 0) {
    peVar6 = (ent->v).enemy;
    if (peVar6 != (edict_t_conflict *)0x0) {
      fVar5 = fVar5 - (peVar6->v).origin[2];
      if (40.0 < fVar5) {
        local_34 = local_34 - 8.0;
      }
      if (fVar5 < 30.0) {
        local_34 = local_34 + 8.0;
      }
    }
    pvVar1 = (ent->v).maxs;
    pvVar2 = (ent->v).mins;
    start = (ent->v).origin;
    SV_Move(&local_bc,start,pvVar2,pvVar1,&local_3c,0,ent,qVar8);
    uVar7 = 0;
    do {
      *(undefined4 *)((int)local_7c + uVar7) =
           *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x38);
    if (local_6c != 1.0) {
      if (peVar6 == (edict_t_conflict *)0x0) {
        return false;
      }
      local_3c = (ent->v).origin[0] + *move;
      local_38 = (ent->v).origin[1] + move[1];
      local_34 = (ent->v).origin[2] + move[2];
      SV_Move(&local_bc,start,pvVar2,pvVar1,&local_3c,0,ent,qVar8);
      uVar7 = 0;
      do {
        *(undefined4 *)((int)local_7c + uVar7) =
             *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
        uVar7 = uVar7 + 4;
      } while (uVar7 < 0x38);
      if (local_6c != 1.0) {
        return false;
      }
    }
    g_groupmask = (ent->v).groupinfo;
    if ((((ent->v).flags & 2) != 0) && (iVar9 = SV_PointContents(&local_68), iVar9 == -1)) {
      return false;
    }
    (ent->v).origin[0] = local_68;
    (ent->v).origin[1] = local_64;
    (ent->v).origin[2] = vStack_60;
    return true;
  }
  pvVar1 = (ent->v).maxs;
  local_34 = local_34 + sv_stepsize.value;
  pvVar2 = (ent->v).mins;
  local_20 = local_34 - (sv_stepsize.value + sv_stepsize.value);
  local_28 = local_3c;
  local_24 = local_38;
  SV_Move(&local_bc,&local_3c,pvVar2,pvVar1,&local_28,0,ent,qVar8);
  uVar7 = 0;
  do {
    *(undefined4 *)((int)local_7c + uVar7) = *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
    uVar7 = uVar7 + 4;
  } while (uVar7 < 0x38);
  if (local_7c[0] != 0) {
    return false;
  }
  if (local_7c[1] != 0) {
    local_34 = local_34 - sv_stepsize.value;
    SV_Move(&local_bc,&local_3c,pvVar2,pvVar1,&local_28,0,ent,qVar8);
    uVar7 = 0;
    do {
      *(undefined4 *)((int)local_7c + uVar7) =
           *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x38);
    if (local_7c[0] != 0) {
      return false;
    }
    if (local_7c[1] != 0) {
      return false;
    }
  }
  if (local_6c == 1.0) {
    uVar7 = (ent->v).flags;
    if ((uVar7 & 0x400) == 0) {
      return false;
    }
    (ent->v).origin[0] = (ent->v).origin[0] + *move;
    (ent->v).origin[1] = (ent->v).origin[1] + move[1];
    fVar3 = (ent->v).origin[2];
    fVar4 = move[2];
    (ent->v).flags = uVar7 & 0xfffffdff;
    (ent->v).origin[2] = fVar3 + fVar4;
    return true;
  }
  (ent->v).origin[0] = local_68;
  (ent->v).origin[1] = local_64;
  (ent->v).origin[2] = vStack_60;
  qVar8 = SV_CheckBottom(ent);
  if (qVar8 != false) {
    uVar7 = (ent->v).flags;
    if ((uVar7 & 0x400) != 0) {
      (ent->v).flags = uVar7 & 0xfffffbff;
    }
    (ent->v).groundentity = peStack_4c;
    return true;
  }
  if (((ent->v).flags & 0x400) != 0) {
    return true;
  }
  (ent->v).origin[0] = fVar3;
  (ent->v).origin[1] = fVar4;
  (ent->v).origin[2] = fVar5;
  return false;
}


// SV_movestep  @ 000af1b0
qboolean SV_movestep(edict_t_conflict *ent,vec_t *move,qboolean relink)

{
  vec_t *pvVar1;
  vec_t *pvVar2;
  vec_t *start;
  float fVar3;
  float fVar4;
  float fVar5;
  edict_t_conflict *peVar6;
  uint uVar7;
  qboolean qVar8;
  int iVar9;
  trace_t local_bc;
  int local_7c [4];
  float local_6c;
  vec_t local_68;
  vec_t local_64;
  vec_t vStack_60;
  edict_t_conflict *peStack_4c;
  float local_3c;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float dz@[???]
                       Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t.conflict * enemy@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  fVar3 = (ent->v).origin[0];
  fVar4 = (ent->v).origin[1];
  fVar5 = (ent->v).origin[2];
  local_3c = *move + fVar3;
  uVar7 = (ent->v).flags;
  qVar8 = (qboolean)((uVar7 & 0x800000) != 0);
  local_38 = move[1] + fVar4;
  local_34 = move[2] + fVar5;
  if ((uVar7 & 3) == 0) {
    pvVar1 = (ent->v).maxs;
    local_34 = local_34 + sv_stepsize.value;
    pvVar2 = (ent->v).mins;
    local_20 = local_34 - (sv_stepsize.value + sv_stepsize.value);
    local_28 = local_3c;
    local_24 = local_38;
    SV_Move(&local_bc,&local_3c,pvVar2,pvVar1,&local_28,0,ent,qVar8);
    uVar7 = 0;
    do {
      *(undefined4 *)((int)local_7c + uVar7) =
           *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x38);
    if (local_7c[0] != 0) {
      return false;
    }
    if (local_7c[1] != 0) {
      local_34 = local_34 - sv_stepsize.value;
      SV_Move(&local_bc,&local_3c,pvVar2,pvVar1,&local_28,0,ent,qVar8);
      uVar7 = 0;
      do {
        *(undefined4 *)((int)local_7c + uVar7) =
             *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
        uVar7 = uVar7 + 4;
      } while (uVar7 < 0x38);
      if (local_7c[0] != 0) {
        return false;
      }
      if (local_7c[1] != 0) {
        return false;
      }
    }
    if (local_6c == 1.0) {
      uVar7 = (ent->v).flags;
      if ((uVar7 & 0x400) == 0) {
        return false;
      }
      (ent->v).origin[0] = (ent->v).origin[0] + *move;
      (ent->v).origin[1] = (ent->v).origin[1] + move[1];
      (ent->v).origin[2] = (ent->v).origin[2] + move[2];
      if (relink != false) {
        SV_LinkEdict(ent,true);
        uVar7 = (ent->v).flags;
      }
      (ent->v).flags = uVar7 & 0xfffffdff;
      return true;
    }
    (ent->v).origin[0] = local_68;
    (ent->v).origin[1] = local_64;
    (ent->v).origin[2] = vStack_60;
    qVar8 = SV_CheckBottom(ent);
    if (qVar8 == false) {
      if (((ent->v).flags & 0x400) == 0) {
        (ent->v).origin[0] = fVar3;
        (ent->v).origin[1] = fVar4;
        (ent->v).origin[2] = fVar5;
        return false;
      }
    }
    else {
      uVar7 = (ent->v).flags;
      if ((uVar7 & 0x400) != 0) {
        (ent->v).flags = uVar7 & 0xfffffbff;
      }
      (ent->v).groundentity = peStack_4c;
    }
  }
  else {
    peVar6 = (ent->v).enemy;
    if (peVar6 != (edict_t_conflict *)0x0) {
      fVar5 = fVar5 - (peVar6->v).origin[2];
      if (40.0 < fVar5) {
        local_34 = local_34 - 8.0;
      }
      if (fVar5 < 30.0) {
        local_34 = local_34 + 8.0;
      }
    }
    pvVar1 = (ent->v).maxs;
    pvVar2 = (ent->v).mins;
    start = (ent->v).origin;
    SV_Move(&local_bc,start,pvVar2,pvVar1,&local_3c,0,ent,qVar8);
    uVar7 = 0;
    do {
      *(undefined4 *)((int)local_7c + uVar7) =
           *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x38);
    if (local_6c != 1.0) {
      if (peVar6 == (edict_t_conflict *)0x0) {
        return false;
      }
      local_3c = (ent->v).origin[0] + *move;
      local_38 = (ent->v).origin[1] + move[1];
      local_34 = (ent->v).origin[2] + move[2];
      SV_Move(&local_bc,start,pvVar2,pvVar1,&local_3c,0,ent,qVar8);
      uVar7 = 0;
      do {
        *(undefined4 *)((int)local_7c + uVar7) =
             *(undefined4 *)((int)local_bc.endpos + (uVar7 - 0x14));
        uVar7 = uVar7 + 4;
      } while (uVar7 < 0x38);
      if (local_6c != 1.0) {
        return false;
      }
    }
    g_groupmask = (ent->v).groupinfo;
    if ((((ent->v).flags & 2) != 0) && (iVar9 = SV_PointContents(&local_68), iVar9 == -1)) {
      return false;
    }
    (ent->v).origin[0] = local_68;
    (ent->v).origin[1] = local_64;
    (ent->v).origin[2] = vStack_60;
  }
  if (relink != false) {
    SV_LinkEdict(ent,true);
  }
  return true;
}


// SV_movetest  @ 000aeed0
qboolean SV_movetest(edict_t_conflict *ent,vec_t *move,qboolean relink)

{
  vec_t *maxs;
  vec_t *mins;
  float fVar1;
  float fVar2;
  float fVar3;
  qboolean qVar4;
  uint uVar5;
  qboolean local_80;
  trace_t local_6c;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???] */
  fVar1 = (ent->v).origin[0];
  maxs = (ent->v).maxs;
  mins = (ent->v).mins;
  fVar2 = (ent->v).origin[1];
  fVar3 = (ent->v).origin[2];
  local_34 = fVar1 + *move;
  local_30 = fVar2 + move[1];
  local_2c = fVar3 + move[2] + sv_stepsize.value;
  local_20 = local_2c - (sv_stepsize.value + sv_stepsize.value);
  local_28 = local_34;
  local_24 = local_30;
  SV_MoveNoEnts(&local_6c,&local_34,mins,maxs,&local_28,0,ent);
  local_80 = false;
  if (local_6c.allsolid == false) {
    if (local_6c.startsolid != false) {
      local_2c = local_2c - sv_stepsize.value;
      SV_MoveNoEnts(&local_6c,&local_34,mins,maxs,&local_28,0,ent);
      if (local_6c.allsolid != false) {
        return false;
      }
      if (local_6c.startsolid != false) {
        return false;
      }
    }
    if (local_6c.fraction == 1.0) {
      uVar5 = (ent->v).flags;
      local_80 = false;
      if ((uVar5 & 0x400) != 0) {
        (ent->v).origin[0] = (ent->v).origin[0] + *move;
        (ent->v).origin[1] = (ent->v).origin[1] + move[1];
        (ent->v).origin[2] = (ent->v).origin[2] + move[2];
        if (relink != false) {
          SV_LinkEdict(ent,true);
          uVar5 = (ent->v).flags;
        }
        local_80 = true;
        (ent->v).flags = uVar5 & 0xfffffdff;
      }
    }
    else {
      (ent->v).origin[0] = local_6c.endpos[0];
      (ent->v).origin[1] = local_6c.endpos[1];
      (ent->v).origin[2] = local_6c.endpos[2];
      qVar4 = SV_CheckBottom(ent);
      if (qVar4 == false) {
        if (((ent->v).flags & 0x400) == 0) {
          (ent->v).origin[0] = fVar1;
          (ent->v).origin[1] = fVar2;
          (ent->v).origin[2] = fVar3;
          return false;
        }
      }
      else {
        uVar5 = (ent->v).flags;
        if ((uVar5 & 0x400) != 0) {
          (ent->v).flags = uVar5 & 0xfffffbff;
        }
        (ent->v).groundentity = local_6c.ent;
      }
      local_80 = true;
      if (relink != false) {
        local_80 = true;
        SV_LinkEdict(ent,true);
      }
    }
  }
  return local_80;
}


