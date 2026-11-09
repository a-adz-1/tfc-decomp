// CL_AddEntityToPhysList  @ 0013d7c0
qboolean CL_AddEntityToPhysList(int entIndex)

{
  int iVar1;
  cl_entity_t *pcVar2;
  playermove_t_conflict *ppVar3;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  ppVar3 = pmove;
  iVar1 = pmove->numphysent;
  if (599 < iVar1) {
    Con_DPrintf("CL_AddEntityToPhysList:  pmove->numphysent >= MAX_PHYSENTS\n");
    return false;
  }
  if (cl_entities[entIndex].curstate.modelindex == 0) {
    return false;
  }
  pcVar2 = cl_entities + entIndex;
  pmove->numphysent = iVar1 + 1;
  CL_AddStateToEntlist
            ((physent_t_conflict1 *)(ppVar3->physents + iVar1),
             (entity_state_t_conflict *)&pcVar2->curstate);
  return true;
}


// CL_AddModelEffects  @ 001349b0
void CL_AddModelEffects(int keynum,cl_entity_t_conflict2 *ent,model_t_conflict *model)

{
  vec_t vVar1;
  uint uVar2;
  dlight_t *pdVar3;
  int iVar4;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: vec3_t oldorigin@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  if (model == (model_t_conflict *)0x0) {
    return;
  }
  local_18 = *(float *)&(ent->latched).field_0xc;
  local_14 = *(undefined4 *)&(ent->latched).field_0x10;
  local_10 = *(undefined4 *)&(ent->latched).field_0x14;
  uVar2 = ent->model->flags;
  if ((uVar2 & 4) == 0) {
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x10) == 0) {
        if ((uVar2 & 0x40) == 0) {
          if ((uVar2 & 1) != 0) {
            (*efx.R_RocketTrail)(&local_18,(float *)&ent->field_0xb48,0);
            pdVar3 = (*efx.CL_AllocDlight)(keynum);
            pdVar3->origin[0] = *(vec_t *)&ent->field_0xb48;
            pdVar3->origin[1] = *(vec_t *)&ent->field_0xb4c;
            vVar1 = *(vec_t *)&ent->field_0xb50;
            pdVar3->radius = 200.0;
            (pdVar3->color).b = 200;
            pdVar3->origin[2] = vVar1;
            (pdVar3->color).g = 200;
            (pdVar3->color).r = 200;
            pdVar3->die = (float)((longdouble)0.01 + (longdouble)cl.time);
            return;
          }
          if ((uVar2 & 2) == 0) {
            if ((uVar2 & 0x80) == 0) {
              return;
            }
            iVar4 = 6;
          }
          else {
            iVar4 = 1;
          }
        }
        else {
          iVar4 = 5;
        }
      }
      else {
        iVar4 = 3;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  else {
    iVar4 = 2;
  }
  (*efx.R_RocketTrail)(&local_18,(float *)&ent->field_0xb48,iVar4);
  return;
}


// CL_AddResource  @ 00146220
resource_t *
CL_AddResource(resourcetype_t type,char *name,int size,qboolean bFatalIfMissing,int index)

{
  uchar *puVar1;
  resource_t *dest;
  resource_t *prVar2;
  int iVar3;
  
                    /* Unresolved local var: resource_t * r@[???] */
  iVar3 = cl.num_resources;
  dest = cl.resourcelist + cl.num_resources;
  if (0x4ff < cl.num_resources) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Too many resources on client.");
  }
  prVar2 = cl.resourcelist + cl.num_resources;
  cl.num_resources = cl.num_resources + 1;
  prVar2->type = type;
  Q_strncpy(dest->szFileName,name,0x3f);
  cl.resourcelist[iVar3].szFileName[0x3f] = '\0';
  cl.resourcelist[iVar3].nDownloadSize = size;
  puVar1 = &cl.resourcelist[iVar3].ucFlags;
  *puVar1 = *puVar1 | bFatalIfMissing != false;
  cl.resourcelist[iVar3].nIndex = index;
  return dest;
}


// CL_AddStateToEntlist  @ 001359a0
void CL_AddStateToEntlist(physent_t_conflict1 *pe,entity_state_t_conflict *state)

{
  int iVar1;
  model_t *pmVar2;
  
  iVar1 = state->number;
  pe->info = iVar1;
  if ((0 < iVar1) && (iVar1 <= cl.maxclients)) {
    pe->player = iVar1;
  }
  pe->origin[0] = *(vec_t *)&state->field_0x10;
  pe->origin[1] = *(vec_t *)&state->field_0x14;
  pe->origin[2] = *(vec_t *)&state->field_0x18;
  pe->angles[0] = *(vec_t *)&state->field_0x1c;
  pe->angles[1] = *(vec_t *)&state->field_0x20;
  pe->angles[2] = *(vec_t *)&state->field_0x24;
  pe->mins[0] = *(vec_t *)&state->field_0x7c;
  pe->mins[1] = *(vec_t *)&state->field_0x80;
  pe->mins[2] = *(vec_t *)&state->field_0x84;
  pe->maxs[0] = *(vec_t *)&state->field_0x88;
  pe->maxs[1] = *(vec_t *)&state->field_0x8c;
  pe->maxs[2] = *(vec_t *)&state->field_0x90;
  pe->frame = state->frame;
  pe->sequence = state->sequence;
  pe->rendermode = state->rendermode;
  pe->skin = (int)state->skin;
  pe->solid = (int)state->solid;
  Q_memcpy(pe->controller,state->controller,4);
  Q_memcpy(pe->blending,state->blending,2);
  pe->movetype = state->movetype;
  pe->takedamage = 0;
  pe->blooddecal = 0;
  if (pe->solid == 4) {
LAB_00135ae1:
    pmVar2 = CL_GetModelByIndex(state->modelindex);
    pe->studiomodel = (model_s_conflict1 *)0x0;
    pe->model = (model_s_conflict1 *)pmVar2;
  }
  else {
    if (pe->solid == 2) {
                    /* Unresolved local var: model_t.conflict * pModel@[???] */
      pe->model = (model_s_conflict1 *)0x0;
      pe->studiomodel = (model_s_conflict1 *)0x0;
      pmVar2 = CL_GetModelByIndex(state->modelindex);
      Q_strncpy(pe->name,pmVar2->name,0x20);
      pe->name[0x1f] = '\0';
      if ((pmVar2->flags & 0x200) != 0) {
        pe->studiomodel = (model_s_conflict1 *)pmVar2;
      }
      goto LAB_00135b0f;
    }
    pmVar2 = CL_GetModelByIndex(state->modelindex);
    if (pmVar2->type != mod_studio) goto LAB_00135ae1;
    pe->model = (model_s_conflict1 *)0x0;
    pmVar2 = CL_GetModelByIndex(state->modelindex);
    pe->studiomodel = (model_s_conflict1 *)pmVar2;
  }
  Q_strncpy(pe->name,pmVar2->name,0x20);
  pe->name[0x1f] = '\0';
LAB_00135b0f:
  pe->iuser1 = state->iuser1;
  pe->iuser2 = state->iuser2;
  pe->iuser3 = state->iuser3;
  pe->iuser4 = state->iuser4;
  pe->fuser1 = state->fuser1;
  pe->fuser2 = state->fuser2;
  pe->fuser3 = state->fuser3;
  pe->fuser4 = state->fuser4;
  pe->vuser1[0] = *(vec_t *)&state->field_0x124;
  pe->vuser1[1] = *(vec_t *)&state->field_0x128;
  pe->vuser1[2] = *(vec_t *)&state->field_0x12c;
  pe->vuser2[0] = *(vec_t *)&state->field_0x130;
  pe->vuser2[1] = *(vec_t *)&state->field_0x134;
  pe->vuser2[2] = *(vec_t *)&state->field_0x138;
  pe->vuser3[0] = *(vec_t *)&state->field_0x13c;
  pe->vuser3[1] = *(vec_t *)&state->field_0x140;
  pe->vuser3[2] = *(vec_t *)&state->field_0x144;
  pe->vuser4[0] = *(vec_t *)&state->field_0x148;
  pe->vuser4[1] = *(vec_t *)&state->field_0x14c;
  pe->vuser4[2] = *(vec_t *)&state->field_0x150;
  pe->blending[0] = state->blending[0];
  pe->blending[1] = state->blending[1];
  pe->controller[0] = state->controller[0];
  pe->controller[1] = state->controller[1];
  pe->controller[2] = state->controller[2];
  pe->controller[3] = state->controller[3];
  pe->rendermode = state->rendermode;
  pe->sequence = state->sequence;
  pe->team = state->team;
  pe->classnumber = state->playerclass;
  return;
}


// CL_AddToResourceList  @ 00155730
void CL_AddToResourceList(resource_t *pResource,resource_t *pList)

{
  if ((pResource->pPrev != (resource_s *)0x0) || (pResource->pNext != (resource_s *)0x0)) {
    Con_Printf("Resource already linked\n");
    return;
  }
  if ((pList->pPrev != (resource_s *)0x0) && (pList->pNext != (resource_s *)0x0)) {
    pResource->pPrev = pList->pPrev;
    pList->pPrev->pNext = pResource;
    pList->pPrev = pResource;
    pResource->pNext = pList;
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Resource list corrupted.\n");
}


// CL_AddToServerCache  @ 001450d0
/* WARNING: Removing unreachable block (ram,0x00145207) */

void CL_AddToServerCache(server_cache_t *server)

{
  qboolean qVar1;
  int iVar2;
  server_cache_t *psVar3;
  byte bVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float fCurrentTime@[???] */
  bVar4 = 0;
  if ((num_servers < 0x10) &&
     ((cl_slisttimeout.value <= 0.0 || ((float)realtime - cls.slist_time < cl_slisttimeout.value))))
  {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float fCurrentTime@[???] */
    iVar2 = 0;
    if (0 < num_servers) {
      do {
        qVar1 = NET_CompareAdr(cached_servers[iVar2].adr,server->adr);
        if (qVar1 != false) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < num_servers);
    }
    psVar3 = cached_servers + num_servers;
    for (iVar2 = 0x112; iVar2 != 0; iVar2 = iVar2 + -1) {
      psVar3->inuse = server->inuse;
      server = (server_cache_t *)((int)server + (uint)bVar4 * -8 + 4);
      psVar3 = (server_cache_t *)((int)psVar3 + ((uint)bVar4 * -2 + 1) * 4);
    }
    psVar3 = cached_servers + num_servers;
    num_servers = num_servers + 1;
    psVar3->inuse = 1;
    Con_Printf("------------------\n");
                    /* Unresolved local var: server_cache_t * p@[???]
                       Unresolved local var: char * pszDedicated@[???]
                       Unresolved local var: char * pszOS@[???]
                       Unresolved local var: char * pszVisibility@[???]
                       Unresolved local var: char * pszSecure@[???] */
    if (num_servers - 1U < 0x10) {
      CL_PrintCachedServer(num_servers - 1U);
      return;
    }
  }
  return;
}


// CL_AddVisibleEntity  @ 0014bd70
int CL_AddVisibleEntity(cl_entity_t *pEntity)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  model_s *pmVar4;
  mnode_t *pmVar5;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???] */
  pmVar4 = pEntity->model;
  if (pmVar4 != (model_s *)0x0) {
    local_24 = pmVar4->mins[0] + pEntity->origin[0];
    local_18 = pmVar4->maxs[0] + pEntity->origin[0];
    local_20 = pmVar4->mins[1] + pEntity->origin[1];
    local_14 = pmVar4->maxs[1] + pEntity->origin[1];
    local_1c = pmVar4->mins[2] + pEntity->origin[2];
    local_10 = pmVar4->maxs[2] + pEntity->origin[2];
    pmVar5 = PVSNode((cl.worldmodel)->nodes,&local_24,&local_18);
    if (pmVar5 != (mnode_t *)0x0) {
      vVar1 = pEntity->angles[0];
      (pEntity->curstate).angles[0] = vVar1;
      vVar2 = pEntity->angles[1];
      (pEntity->curstate).angles[1] = vVar2;
      vVar3 = pEntity->angles[2];
      (pEntity->curstate).angles[2] = vVar3;
      (pEntity->latched).prevangles[0] = vVar1;
      (pEntity->latched).prevangles[1] = vVar2;
      (pEntity->latched).prevangles[2] = vVar3;
      ClientDLL_AddEntity(2,pEntity);
      return 1;
    }
  }
  return 0;
}


// CL_AddVoiceToDatagram  @ 000b8d20
void CL_AddVoiceToDatagram(qboolean bFinal)

{
  qboolean qVar1;
  int iSize;
  int in_GS_OFFSET;
  char local_810 [2048];
  int local_10;
  
                    /* Unresolved local var: char[2048] uchVoiceData@[???]
                       Unresolved local var: int nDataLength@[???]
                       Unresolved local var: sizebuf_t * pBuf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state == ca_active) {
    qVar1 = Voice_IsRecording();
    if (qVar1 != 0) {
      iSize = Voice_GetCompressedData(local_810,0x800,bFinal);
      if ((iSize != 0) && (iSize + 3 + cls.datagram.cursize < cls.datagram.maxsize)) {
        MSG_WriteByte(&cls.datagram,8);
        MSG_WriteShort(0xdf6ff8,(int)(short)iSize);
        MSG_WriteBuf(&cls.datagram,iSize,local_810);
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_AdjustClock  @ 00137850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_AdjustClock(void)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double msec@[???]
                       Unresolved local var: double adjust@[???]
                       Unresolved local var: double sign@[???] */
  if (((g_clockdelta != 0.0) && (dVar2 = (double)cl_fixtimerate.value, dVar2 != 0.0)) &&
     (0.001 <= ABS(g_clockdelta))) {
    if (dVar2 < 0.0) {
      cl_fixtimerate.value = 7.5;
      dVar2 = 7.5;
    }
    dVar1 = 1.0;
    if (0.0 <= (double)(int)(g_clockdelta * 1000.0)) {
      dVar1 = -1.0;
    }
    dVar3 = ABS((double)(int)(g_clockdelta * 1000.0));
    if (dVar3 < dVar2) {
      dVar2 = dVar3;
    }
    dVar1 = (dVar2 / 1000.0) * dVar1;
    if (ABS(dVar1) < ABS(g_clockdelta)) {
      g_clockdelta = g_clockdelta + dVar1;
      cl.time = dVar1 + cl.time;
    }
    if (cl.time < cl.oldtime) {
      cl.oldtime = cl.time;
    }
  }
  return;
}


// CL_AllocCustomTempEntity  @ 00153ba0
TEMPENTITY *
CL_AllocCustomTempEntity
          (float *origin,model_s *model,int high,_func_void_tempent_s_ptr_float_float *callback)

{
  TEMPENTITY *pTVar1;
  
                    /* Unresolved local var: TEMPENTITY * p@[???] */
  if (high == 0) {
    pTVar1 = (*efx.CL_TempEntAlloc)(origin,model);
  }
  else {
    pTVar1 = (*efx.CL_TempEntAllocHigh)(origin,model);
  }
  if (pTVar1 != (TEMPENTITY *)0x0) {
    pTVar1->flags = pTVar1->flags | 0x80000;
    pTVar1->callback = callback;
    pTVar1->die = (float)cl.time;
  }
  return pTVar1;
}


// CL_AllocDlight  @ 00149b10
dlight_t * CL_AllocDlight(int key)

{
  uint uVar1;
  int iVar2;
  dlight_t *dest;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  if (key != 0) {
    dest = cl_dlights;
    iVar2 = 0;
    do {
      if (key == dest->key) goto LAB_00149b3e;
      iVar2 = iVar2 + 1;
      dest = dest + 1;
    } while (iVar2 != 0x20);
  }
  dest = cl_dlights;
  iVar2 = 0;
  while (cl.time <= (double)dest->die) {
    iVar2 = iVar2 + 1;
    dest = dest + 1;
    if (iVar2 == 0x20) {
      Q_memset(cl_dlights,0,0x28);
      cl_dlights[0].key = key;
      r_dlightchanged = r_dlightchanged | 1;
      r_dlightactive = r_dlightactive | 1;
      return cl_dlights;
    }
  }
LAB_00149b3e:
  Q_memset(dest,0,0x28);
  dest->key = key;
  uVar1 = 1 << ((byte)iVar2 & 0x1f);
  r_dlightchanged = r_dlightchanged | uVar1;
  r_dlightactive = r_dlightactive | uVar1;
  return dest;
}


// CL_AllocElight  @ 00149bf0
dlight_t * CL_AllocElight(int key)

{
  dlight_t *dest;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * el@[???] */
  if (key != 0) {
    dest = cl_elights;
    do {
      if (key == dest->key) goto LAB_00149c18;
      dest = dest + 1;
    } while (dest != (dlight_t *)&cl_playerindex);
  }
  dest = cl_elights;
  while (cl.time <= (double)dest->die) {
    dest = dest + 1;
    if (dest == (dlight_t *)&cl_playerindex) {
      Q_memset(cl_elights,0,0x28);
      cl_elights[0].key = key;
      return cl_elights;
    }
  }
LAB_00149c18:
  Q_memset(dest,0,0x28);
  dest->key = key;
  return dest;
}


// CL_AppendDemo_f  @ 0013e3d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_AppendDemo_f(void)

{
  demoentry_t *pdVar1;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  FILE *src;
  uint uVar5;
  int iVar6;
  int in_GS_OFFSET;
  longdouble lVar7;
  undefined1 local_335;
  float local_334;
  int32 local_330;
  char local_32c [260];
  char local_228 [260];
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: int track@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: byte cmd@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szMapName@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: int swlen@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    if ((cls.demorecording == false) && (cls.demoplayback == false)) {
      if (cls.state == ca_active) {
        iVar2 = Cmd_Argc();
        if (iVar2 - 2U < 2) {
          pcVar3 = Cmd_Argv(1);
          pcVar3 = Q_strstr(pcVar3,"..");
          if (pcVar3 == (char *)0x0) {
            iVar6 = -1;
            if (iVar2 == 3) {
              pcVar3 = Cmd_Argv(2);
              iVar6 = Q_atoi(pcVar3);
              Con_Printf("Forcing CD track to %i\n",iVar6);
            }
            pcVar3 = Cmd_Argv(1);
            snprintf(local_32c,0x100,"%s",pcVar3);
            COM_DefaultExtension(local_32c,".dem");
            qVar4 = COM_HasFileExtension(local_32c,"dem");
            if (qVar4 == false) {
              Con_Printf("Error: couldn\'t open %s, demo files must have .dem extension.\n",
                         local_32c);
            }
            else {
              Con_Printf("Appending to demo %s.\n",local_32c);
              Q_strncpy(cls.demofilename,local_32c,0xff);
              cls.demofilename[0xff] = '\0';
              src = FS_OpenPathID(local_32c,"rb","GAMECONFIG");
              if (src == (FILE *)0x0) {
                Con_Printf("Error:  couldn\'t open demo file %s for appending.\n",local_32c);
              }
              else {
                COM_StripExtension(local_32c,local_228);
                COM_AddExtension(local_228,".dm2",0x104);
                qVar4 = COM_HasFileExtension(local_228,"dm2");
                if (qVar4 == false) {
                  Con_Printf("Error: could not open temporary file %s.\n",local_228);
                  FS_Close(src);
                }
                else {
                  cls.demofile = FS_OpenPathID(local_228,"w+b","GAMECONFIG");
                  if (cls.demofile == (FileHandle_t)0x0) {
                    Con_Printf("ERROR: couldn\'t open %s.\n",local_32c);
                    FS_Close(src);
                  }
                  else {
                    FS_Seek(src,0,FILESYSTEM_SEEK_TAIL);
                    uVar5 = FS_Tell(src);
                    FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
                    FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
                    CL_DemoCopyFileChunk(cls.demofile,src,uVar5);
                    FS_Close(src);
                    FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
                    FS_Read(&demoheader,0x220,1,cls.demofile);
                    iVar2 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
                    if (iVar2 == 0) {
                      COM_FileBase((cl.worldmodel)->name,local_124);
                      iVar2 = Q_strcmp(demoheader.szMapName,local_124);
                      if (iVar2 == 0) {
                        if ((demoheader.nNetProtocolVersion == 0x30) &&
                           (demoheader.nDemoProtocol == 5)) {
                          FS_Seek(cls.demofile,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                          FS_Read(&demodir,4,1,cls.demofile);
                          if (demodir.nEntries - 1U < 0x400) {
                            demodir.p_rgEntries = Mem_Malloc((demodir.nEntries + 1) * 0x5c);
                            FS_Read(demodir.p_rgEntries,demodir.nEntries * 0x5c,1,cls.demofile);
                            nCurEntryIndex = demodir.nEntries;
                            pCurrentEntry = demodir.p_rgEntries + demodir.nEntries;
                            demodir.nEntries = demodir.nEntries + 1;
                            Q_memset(pCurrentEntry,0,0x5c);
                            FS_Seek(cls.demofile,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                            pCurrentEntry->nEntryType = 1;
                            __snprintf_chk(pCurrentEntry->szDescription,0x40,1,0x40,&LAB_00264855,
                                           demodir.nEntries + -1);
                            pdVar1 = pCurrentEntry;
                            pCurrentEntry->nFlags = 0;
                            pdVar1->nCDTrack = iVar6;
                            pdVar1->fTrackTime = 0.0;
                            uVar5 = FS_Tell(cls.demofile);
                            local_335 = 2;
                            cls.demostarttime = (float)realtime;
                            pdVar1->nOffset = uVar5;
                            cls.demoframecount = 0;
                            cls.demostartframe = host_framecount;
                            FS_Write(&local_335,1,1,cls.demofile);
                            lVar7 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
                            local_334 = (float)lVar7;
                            FS_Write(&local_334,4,1,cls.demofile);
                            local_330 = (*LittleLong)(host_framecount - cls.demostartframe);
                            FS_Write(&local_330,4,1,cls.demofile);
                            cls.td_startframe = host_framecount;
                            cls.demowaiting = true;
                            cls.demorecording = true;
                            cls.td_lastframe = -1;
                            cls.demoappending = true;
                          }
                          else {
                            Con_Printf("ERROR: demo had bogus # of directory entries:  %i\n",
                                       demodir.nEntries);
                            FS_Close(cls.demofile);
                            cls.demofile = (FileHandle_t)0x0;
                          }
                          goto LAB_0013e40a;
                        }
                        Con_Printf("ERROR: demo protocol outdated\nDemo file protocols %iN:%iD\nServer protocol is at %iN:%iD\n"
                                   ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
                      }
                      else {
                        Con_Printf("%s was recorded on a different map, cannot append.\n",local_32c)
                        ;
                      }
                    }
                    else {
                      Con_Printf("%s is not a demo file\n",local_32c);
                    }
                    unlink(local_228);
                    FS_Close(cls.demofile);
                    cls.demofile = (FileHandle_t)0x0;
                  }
                }
              }
            }
          }
          else {
            Con_Printf("Relative pathnames are not allowed.\n");
          }
        }
        else {
          Con_Printf("appenddemo <demoname> <cd track>\n");
        }
      }
      else {
        Con_Printf("You must be in an active map spawned on a machine that allows creation of files in %s\n"
                   ,com_gamedir);
      }
    }
    else {
      Con_Printf("Appenddemo only available when not running or recording a demo.\n");
    }
  }
LAB_0013e40a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_BatchResourceRequest  @ 00155910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_BatchResourceRequest(void)

{
  int iVar1;
  resource_s *prVar2;
  resource_t *prVar3;
  qboolean qVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  resource_s *pResource;
  int in_GS_OFFSET;
  sizebuf_t sStack_10124;
  char acStack_10110 [256];
  byte abStack_10010 [65540];
  
                    /* Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&sStack_10124,0,0x14);
  sStack_10124.buffername = "Client to Server Resource Batch";
  sStack_10124.data = abStack_10010;
  sStack_10124.cursize = 0;
  sStack_10124.maxsize = 0x10000;
  CL_HTTPStop_f();
  pResource = cl.resourcesneeded.pNext;
  if (cl.resourcesneeded.pNext != &cl.resourcesneeded) {
    do {
      if (pResource == (resource_t *)0x0) break;
      prVar2 = pResource->pNext;
      if ((pResource->ucFlags & 2) == 0) goto switchD_001559d0_caseD_1;
      if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
        Con_Printf("Skipping in game download of %s\n",pResource);
        CL_MoveToOnHandList(pResource);
        goto switchD_001559d0_default;
      }
      qVar4 = IsSafeFileToDownload(pResource->szFileName);
      if (qVar4 == false) {
        if ((pResource->pPrev == (resource_s *)0x0) ||
           (prVar3 = pResource->pNext, prVar3 == (resource_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
        }
        if ((pResource == prVar3) || (pResource == pResource->pPrev)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Attempt to free last entry in list.");
        }
        pResource->pPrev->pNext = prVar3;
        pResource->pNext->pPrev = pResource->pPrev;
        pResource->pPrev = (resource_s *)0x0;
        pResource->pNext = (resource_s *)0x0;
        Con_Printf("Invalid file type...skipping download of %s\n",pResource);
        Mem_Free(pResource);
        goto switchD_001559d0_default;
      }
      switch(pResource->type) {
      case t_sound:
        if (pResource->szFileName[0] != '*') {
          pcVar7 = va("sound/%s",pResource);
          qVar4 = CL_CheckFile(&sStack_10124,pcVar7);
          if (qVar4 == false) break;
        }
      case t_skin:
switchD_001559d0_caseD_1:
        CL_MoveToOnHandList(pResource);
        break;
      case t_model:
        if (pResource->szFileName[0] != '*') goto switchD_001559d0_caseD_4;
        goto switchD_001559d0_caseD_1;
      case t_decal:
        qVar4 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
        if (qVar4 != false) goto switchD_001559d0_caseD_1;
        if ((pResource->ucFlags & 8) == 0) {
                    /* Unresolved local var: char[256] filename@[???] */
          pcVar7 = COM_BinPrintf(pResource->rgucMD5_hash,0x10);
          __snprintf_chk(acStack_10110,0x100,1,0x100,0x257b13,pcVar7);
          MSG_WriteByte(&sStack_10124,3);
          pcVar7 = va("dlfile %s",acStack_10110);
          MSG_WriteString(&sStack_10124,pcVar7);
          pResource->ucFlags = pResource->ucFlags | 8;
        }
        break;
      case t_generic:
      case t_eventscript:
switchD_001559d0_caseD_4:
        qVar4 = CL_CheckFile(&sStack_10124,pResource->szFileName);
        if (qVar4 != false) goto switchD_001559d0_caseD_1;
      }
switchD_001559d0_default:
      pResource = prVar2;
    } while (prVar2 != &cl.resourcesneeded);
  }
  iVar5 = CL_GetDownloadQueueSize();
  if (0 < iVar5) {
    uVar6 = 0;
    do {
      *(undefined4 *)(acStack_10110 + uVar6) = *(undefined4 *)(cl.downloadUrl + uVar6);
      uVar6 = uVar6 + 4;
    } while (uVar6 < 0x80);
                    /* Unresolved local var: char[128] tmpUrl@[???] */
    CL_MarkMapAsUsingHTTPDownload();
    CL_Disconnect();
    iVar5 = CL_GetDownloadQueueSize();
    StartLoadingProgressBar(acStack_10110,iVar5);
    SetLoadingProgressBarStatusText("#GameUI_VerifyingAndDownloading");
  }
  if (cls.state != ca_disconnected) {
    if ((sStack_10124.cursize == 0) && (qVar4 = CL_PrecacheResources(), qVar4 != false)) {
      CL_RegisterResources(&sStack_10124);
    }
    if (cls.passive == false) {
      Netchan_CreateFragments(false,&cls.netchan,&sStack_10124);
      Netchan_FragSend(&cls.netchan);
    }
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_BeginDemoStartup  @ 00141460
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_BeginDemoStartup(void)

{
  if (cls.demoheader != (FileHandle_t)0x0) {
    FS_Close(cls.demoheader);
  }
  cls.demoheader = FS_OpenPathID("demoheader.dmf","w+b","GAMECONFIG");
  if (cls.demoheader != (FileHandle_t)0x0) {
    Con_DPrintf("Spooling demo header.\n");
    return;
  }
  Con_DPrintf("ERROR: couldn\'t open temporary header file.\n");
  return;
}


// CL_BeginUpload_f  @ 00143c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_BeginUpload_f(void)

{
  uchar *hash;
  char *pcVar1;
  int iVar2;
  qboolean qVar3;
  int in_GS_OFFSET;
  uchar *local_128;
  uint local_124;
  uchar local_120 [16];
  uchar local_110 [16];
  MD5Context_t local_100;
  resource_s local_a8;
  int local_20;
  
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: uchar * buf@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: resource_t custResource@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_128 = (uchar *)0x0;
  local_124 = 0;
  pcVar1 = Cmd_Argv(1);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    Con_Printf("Upload without filename\n");
  }
  else if (cl_allow_upload.value == 0.0) {
    Con_Printf("Ingoring decal upload ( cl_allow_upload is 0 )\n");
  }
  else {
    iVar2 = Q_strlen(pcVar1);
    if ((iVar2 == 0x24) && (iVar2 = Q_strnicmp(pcVar1,"!MD5",4), iVar2 == 0)) {
      ContinueLoadingProgressBar("ClientConnect",10,0.0);
      Q_memset(&local_a8,0,0x88);
      COM_HexConvert(pcVar1 + 4,0x20,local_120);
      qVar3 = HPAK_ResourceForHash("custom.hpk",local_120,&local_a8);
      if (qVar3 != false) {
        hash = local_a8.rgucMD5_hash;
        iVar2 = Q_memcmp(local_120,hash,0x10);
        if (iVar2 != 0) {
          Con_DPrintf("Bogus data retrieved from custom.hpk, attempting to delete entry\n");
          HPAK_RemoveLump("custom.hpk",&local_a8);
          goto LAB_00143cc0;
        }
        qVar3 = HPAK_GetDataPointer("custom.hpk",&local_a8,&local_128,(int *)&local_124);
        if (qVar3 != false) {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
          Q_memset(&local_100,0,0x58);
          MD5Init(&local_100);
          MD5Update(&local_100,local_128,local_124);
          MD5Final(local_110,&local_100);
          iVar2 = Q_memcmp(hash,local_110,0x10);
          if (iVar2 != 0) {
            Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
            pcVar1 = MD5_Print(hash);
            Con_Printf("Purported:  %s\n",pcVar1);
            pcVar1 = MD5_Print(local_110);
            Con_Printf("Actual   :  %s\n",pcVar1);
            Con_Printf("Removing conflicting lump\n");
            HPAK_RemoveLump("custom.hpk",&local_a8);
            goto LAB_00143cc0;
          }
        }
      }
      if ((local_128 == (uchar *)0x0) || (local_124 == 0)) {
        Con_Printf("Ingoring customization upload, couldn\'t find decal locally\n");
      }
      else {
        Netchan_CreateFileFragmentsFromBuffer(false,&cls.netchan,pcVar1,local_128,local_124);
        Netchan_FragSend(&cls.netchan);
        Mem_Free(local_128);
      }
    }
    else {
      Con_Printf("Ingoring upload of non-customization\n");
    }
  }
LAB_00143cc0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_BoundInterpolationFraction  @ 0013caa0
void CL_BoundInterpolationFraction(float *frac)

{
  if (0.0 <= *frac) {
    if (1.2 < *frac) {
      *frac = 1.2;
    }
    return;
  }
  *frac = 0.0;
  return;
}


// CL_BuildMapCycleListHints  @ 00156cb0
int CL_BuildMapCycleListHints(char **hints,char *mapCycleMsg,char *firstMap)

{
  size_t sVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  int in_GS_OFFSET;
  char local_53c [260];
  uint local_438 [130];
  undefined1 local_22d;
  uint local_22c [131];
  int local_20;
  
                    /* Unresolved local var: char[524] szMap@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char * aFileList@[???]
                       Unresolved local var: char[260] szMod@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar1 = strlen(mapCycleMsg);
  COM_FileBase(com_gamedir,local_53c);
  if ((mapCycleMsg == (char *)0x0) || (sVar1 == 0)) {
    iVar7 = 1;
  }
  else {
    pcVar2 = GetCurrentSteamAppName();
    pcVar8 = szCommonPreloads;
    pcVar6 = szReslistsExt;
    pcVar3 = GetCurrentSteamAppName();
    __sprintf_chk(local_438,1,0x20c,"%s\\%s\\%s%s\r\n%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar3,
                  pcVar8,pcVar6,szReslistsBaseDir,pcVar2,firstMap,pcVar6);
    puVar10 = local_438;
    do {
      puVar9 = puVar10;
      uVar4 = *puVar9 + 0xfefefeff & ~*puVar9;
      uVar5 = uVar4 & 0x80808080;
      puVar10 = puVar9 + 1;
    } while (uVar5 == 0);
    if ((uVar4 & 0x8080) == 0) {
      puVar10 = (uint *)((int)puVar9 + 6);
      uVar5 = uVar5 >> 0x10;
    }
    pcVar6 = Mem_ZeroMalloc((size_t)((int)puVar10 +
                                    (-(int)local_438 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) + -2))
    ;
    *hints = pcVar6;
    if (pcVar6 == (char *)0x0) {
      iVar7 = 0;
    }
    else {
      strcpy(pcVar6,(char *)local_438);
      while (mapCycleMsg = COM_Parse(mapCycleMsg), com_token[0] != '\0') {
        strncpy((char *)local_438,com_token,0x20b);
        local_22d = 0;
        iVar7 = COM_TokenWaiting(mapCycleMsg);
        if (iVar7 != 0) {
          mapCycleMsg = COM_Parse(mapCycleMsg);
        }
        iVar7 = PF_IsMapValid_I((char *)local_438);
                    /* Unresolved local var: size_t __s1_len@[???]
                       Unresolved local var: size_t __s2_len@[???] */
        if ((iVar7 != 0) &&
           (iVar7 = strcmp(firstMap,(char *)local_438), pcVar6 = szReslistsExt, iVar7 != 0)) {
                    /* Unresolved local var: char[524] mapLine@[???] */
          pcVar8 = GetCurrentSteamAppName();
          __sprintf_chk(local_22c,1,0x20c,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar8,local_438,
                        pcVar6);
          pcVar6 = *hints;
          sVar1 = strlen(pcVar6);
          puVar10 = local_22c;
          do {
            puVar9 = puVar10;
            uVar4 = *puVar9 + 0xfefefeff & ~*puVar9;
            uVar5 = uVar4 & 0x80808080;
            puVar10 = puVar9 + 1;
          } while (uVar5 == 0);
          if ((uVar4 & 0x8080) == 0) {
            puVar10 = (uint *)((int)puVar9 + 6);
            uVar5 = uVar5 >> 0x10;
          }
          pcVar6 = Mem_Realloc(pcVar6,(int)puVar10 +
                                      sVar1 + (-(int)local_22c -
                                              (uint)CARRY1((byte)uVar5,(byte)uVar5)) + -1);
          *hints = pcVar6;
          iVar7 = 0;
          if (pcVar6 == (char *)0x0) goto LAB_00156f25;
          strcat(pcVar6,(char *)local_22c);
        }
      }
      pcVar6 = GetCurrentSteamAppName();
      __sprintf_chk(local_438,1,0x20c,"%s\\%s\\mp_maps.txt\r\n",szReslistsBaseDir,pcVar6);
      pcVar6 = *hints;
      sVar1 = strlen(pcVar6);
      puVar10 = local_438;
      do {
        puVar9 = puVar10;
        uVar4 = *puVar9 + 0xfefefeff & ~*puVar9;
        uVar5 = uVar4 & 0x80808080;
        puVar10 = puVar9 + 1;
      } while (uVar5 == 0);
      if ((uVar4 & 0x8080) == 0) {
        puVar10 = (uint *)((int)puVar9 + 6);
        uVar5 = uVar5 >> 0x10;
      }
      pcVar6 = realloc(pcVar6,(size_t)((int)puVar10 +
                                      sVar1 + (-(int)local_438 -
                                              (uint)CARRY1((byte)uVar5,(byte)uVar5)) + -1));
      *hints = pcVar6;
      strcat(pcVar6,(char *)local_438);
      iVar7 = 1;
    }
  }
LAB_00156f25:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}


// CL_CalcPlayerVelocity  @ 00138d90
void CL_CalcPlayerVelocity(int idx,vec_t *velocity)

{
  float fVar1;
  float fVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: clientdata_t * pcd@[???] */
  *velocity = 0.0;
  velocity[1] = 0.0;
  velocity[2] = 0.0;
  iVar4 = cl.parsecountmod;
  if ((0 < idx) && (idx <= cl.maxclients)) {
    if (idx + -1 == cl.playernum) {
      *velocity = cl.frames[cl.parsecountmod].clientdata.velocity[0];
      velocity[1] = cl.frames[iVar4].clientdata.velocity[1];
      velocity[2] = cl.frames[iVar4].clientdata.velocity[2];
    }
    else {
                    /* Unresolved local var: clientdata_t * pcd@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float dt@[???] */
      fVar1 = cl_entities[idx].curstate.velocity[0];
      local_18 = fVar1 - cl_entities[idx].prevstate.velocity[0];
      local_14 = cl_entities[idx].curstate.velocity[1] - cl_entities[idx].prevstate.velocity[1];
      local_10 = cl_entities[idx].curstate.velocity[2] - cl_entities[idx].prevstate.velocity[2];
      fVar2 = cl_entities[idx].curstate.animtime - cl_entities[idx].prevstate.animtime;
      if (fVar2 != 0.0) {
        VectorScale(&local_18,1.0 / fVar2,velocity);
        return;
      }
      *velocity = fVar1;
      pcVar3 = cl_entities;
      velocity[1] = cl_entities[idx].curstate.velocity[1];
      velocity[2] = pcVar3[idx].curstate.velocity[2];
    }
  }
  return;
}


// CL_CalculateDevOverviewParameters  @ 0013d5b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CalculateDevOverviewParameters(void)

{
  mvertex_t *pmVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  mvertex_t *pmVar10;
  float local_4;
  
                    /* Unresolved local var: vec3_t min@[???]
                       Unresolved local var: vec3_t max@[???]
                       Unresolved local var: vec3_t v@[???]
                       Unresolved local var: float xSize@[???]
                       Unresolved local var: float ySize@[???]
                       Unresolved local var: float xScale@[???]
                       Unresolved local var: float yScale@[???]
                       Unresolved local var: int i@[???] */
  if ((cl.worldmodel)->numvertexes < 1) {
    fVar2 = -64000.0;
    gDevOverview.z_min = -31999.0;
    gDevOverview.z_max = 31999.0;
    local_4 = -64000.0;
    gDevOverview.origin[0] = 0.0;
    gDevOverview.origin[1] = 0.0;
    gDevOverview.origin[2] = 0.0;
  }
  else {
    pmVar10 = (cl.worldmodel)->vertexes;
    fVar9 = 32000.0;
    fVar6 = -32000.0;
    fVar8 = -32000.0;
    fVar5 = 32000.0;
    fVar7 = -32000.0;
    pmVar1 = pmVar10 + (cl.worldmodel)->numvertexes;
    local_4 = 32000.0;
    do {
      fVar2 = pmVar10->position[0];
      fVar3 = pmVar10->position[1];
      if (fVar6 < fVar2) {
        fVar6 = fVar2;
      }
      if (fVar8 < fVar3) {
        fVar8 = fVar3;
      }
      fVar4 = pmVar10->position[2];
      if (fVar7 < fVar4) {
        fVar7 = fVar4;
      }
      if (fVar2 < fVar5) {
        fVar5 = fVar2;
      }
      if (fVar3 < fVar9) {
        fVar9 = fVar3;
      }
      fVar3 = local_4;
      if (fVar4 < local_4) {
        fVar3 = fVar4;
      }
      pmVar10 = pmVar10 + 1;
      local_4 = fVar3;
    } while (pmVar1 != pmVar10);
    local_4 = fVar6 - fVar5;
    fVar2 = fVar8 - fVar9;
    gDevOverview.z_min = fVar7 + 1.0;
    gDevOverview.z_max = fVar3 - 1.0;
    gDevOverview.origin[0] = (fVar5 + fVar6) * 0.5;
    gDevOverview.origin[1] = (fVar9 + fVar8) * 0.5;
    gDevOverview.origin[2] = (fVar7 + fVar3) * 0.5;
    if (local_4 < fVar2) {
      gDevOverview.rotated = false;
      local_4 = local_4 * 1.3333;
      goto LAB_0013d6b7;
    }
  }
  gDevOverview.rotated = true;
  fVar2 = fVar2 * 1.3333;
LAB_0013d6b7:
  gDevOverview.zoom = 8192.0 / fVar2;
  if (8192.0 / local_4 < 8192.0 / fVar2) {
    gDevOverview.zoom = 8192.0 / local_4;
  }
  return;
}


// CL_CanUseHTTPDownload  @ 001275a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_CanUseHTTPDownload(void)

{
  char **ppcVar1;
  int iVar2;
  char *__s1;
  int iVar3;
  int iVar4;
  
  if (cl.downloadUrl[0] == '\0') {
    return 0;
  }
                    /* Unresolved local var: char * serverMapName@[???] */
  __s1 = DL_SharedVarArgs("%s:%s",cls.servername,0xde4738);
  iVar2 = TheDownloadManager.m_downloadedMaps.m_Size;
  ppcVar1 = TheDownloadManager.m_downloadedMaps.m_Memory.m_pMemory;
                    /* Unresolved local var: int i@[???] */
  if ((__s1 != (char *)0x0) && (0 < TheDownloadManager.m_downloadedMaps.m_Size)) {
    iVar4 = 0;
    do {
                    /* Unresolved local var: char * oldServerMapName@[???] */
      if ((ppcVar1[iVar4] != (char *)0x0) && (iVar3 = strcasecmp(__s1,ppcVar1[iVar4]), iVar3 == 0))
      {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar2);
  }
  return 1;
}


// CL_CheckCRCs  @ 00154bb0
qboolean CL_CheckCRCs(char *pszMap)

{
  qboolean qVar1;
  BOOL BVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_CheckCRCs()");
  }
  ContinueLoadingProgressBar("ClientConnect",4,0.0);
  SetLoadingProgressBarStatusText("#GameUI_CheckCRCs");
  qVar1 = Host_IsServerActive();
  if (qVar1 == false) {
    CRC32_Init(&cl.mapCRC);
    iVar3 = CRC_MapFile(&cl.mapCRC,pszMap);
    if (iVar3 == 0) {
      iVar3 = FS_FileExists(pszMap);
      if (iVar3 != 0) {
        COM_ExplainDisconnection(true,"#GameUI_ConnectionFailed",pszMap);
                    /* WARNING: Subroutine does not return */
        Host_Error("Disconnected");
      }
      if (cl_allow_download.value == 0.0) {
        COM_ExplainDisconnection
                  (true,"Refusing to download map %s, (cl_allow_download is 0 ) disconnecting.\n",
                   pszMap);
                    /* WARNING: Subroutine does not return */
        Host_Error("Disconnected");
      }
      Con_Printf("Couldn\'t find map %s, server will download the map\n",pszMap);
      cl.mapCRC = cl.serverCRC;
    }
    else if ((cl.serverCRC != cl.mapCRC) && (cls.demoplayback == false)) {
      COM_ExplainDisconnection(true,"Your map [%s] differs from the server\'s.",pszMap);
                    /* WARNING: Subroutine does not return */
      Host_Error("Disconnected");
    }
  }
  if (gmodinfo.clientcrccheck != false) {
                    /* Unresolved local var: char[64] szDllName@[???] */
    builtin_strncpy(local_50,"cl_dlls//client.dll",0x14);
    BVar2 = MD5_Hash_File(cls.md5_clientdll,local_50,0,0,(uint *)0x0);
    if (BVar2 == 0) {
      COM_ExplainDisconnection(true,"Couldn\'t CRC client side dll %s.",local_50);
                    /* WARNING: Subroutine does not return */
      Host_Error("Disconnected");
    }
    iVar3 = Q_memcmp(cl.clientdllmd5,cls.md5_clientdll,0x10);
    if (iVar3 != 0) {
      if ((cls.demoplayback == false) && (cls.spectator == false)) {
        COM_ExplainDisconnection(true,"Your .dll [%s] differs from the server\'s.",local_50);
                    /* WARNING: Subroutine does not return */
        Host_Error("Disconnected");
      }
      Con_Printf("Your client side .dll [%s] failed the CRC check.\nThe .dll may be out of date, or the demo may have been recorded using an old version of the .dll.\nConsider obtaining an updated version of the .dll from the server operator.\nDemo playback proceeding.\n"
                 ,local_50);
    }
  }
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_CheckCRCs()");
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return true;
}


// CL_CheckClientState  @ 00144cc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CheckClientState(void)

{
  netadr_t *pnVar1;
  uint uVar2;
  startup_timing_t *psVar3;
  int iVar4;
  
  if ((cls.state - ca_connected < 2) && (cls.signon == 2)) {
    cls.state = ca_active;
    if (fs_startup_timings.value != 0.0) {
                    /* Unresolved local var: int i@[???] */
      Con_Printf("Startup timings (%.2f total)\n",
                 (double)(g_StartupTimings[g_iCurrentTiming].time - g_StartupTimings[0].time));
      Con_Printf("    0.00    Startup\n");
      if (0 < g_iCurrentTiming) {
        psVar3 = g_StartupTimings;
        iVar4 = 1;
        do {
          psVar3 = psVar3 + 1;
          iVar4 = iVar4 + 1;
          Con_Printf("    %.2f    %s\n",(double)(psVar3->time - psVar3[-1].time),psVar3->name);
        } while (iVar4 <= g_iCurrentTiming);
      }
    }
                    /* Unresolved local var: uchar * IPPtr@[???]
                       Unresolved local var: short port@[???] */
    uVar2 = (uint)(short)cls.netchan.remote_address.port;
    pnVar1 = &cls.netchan.remote_address;
    if (uVar2 == 0) {
      uVar2 = (uint)(short)net_local_adr.port;
      pnVar1 = &net_local_adr;
    }
    uVar2 = Q_ntohs(uVar2 & 0xffff);
    VGuiWrap2_NotifyOfServerConnect(com_gamedir,*(int *)pnVar1->ip,uVar2 & 0xffff);
    return;
  }
  return;
}


// CL_CheckFile  @ 001547a0
qboolean CL_CheckFile(sizebuf_t *msg,char *filename)

{
  int iVar1;
  char *s;
  qboolean qVar2;
  int in_GS_OFFSET;
  char local_114 [259];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[260] file@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_strncpy(local_114,filename,0x103);
  local_11 = 0;
  if (cl_allow_download.value == 0.0) {
    qVar2 = true;
    Con_DPrintf("Download refused, cl_allow_download is 0\n");
  }
  else if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
    qVar2 = true;
    Con_DPrintf("In-game download refused...\n");
  }
  else {
    qVar2 = true;
    iVar1 = FS_FileExists(local_114);
    if (iVar1 == 0) {
      if ((cls.passive == false) && (cls.demoplayback == false)) {
        iVar1 = CL_CanUseHTTPDownload();
        qVar2 = false;
        if (iVar1 == 0) {
          MSG_WriteByte(msg,3);
          s = va("dlfile %s",local_114);
          MSG_WriteString(msg,s);
        }
        else {
          CL_QueueHTTPDownload(local_114);
        }
      }
      else {
        qVar2 = true;
        Con_Printf("Warning! File %s missing during demo playback.\n",local_114);
      }
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar2;
}


// CL_CheckForResend  @ 001493f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CheckForResend(void)

{
  netadr_t addr;
  netadr_t addr_00;
  netadr_t to;
  double dVar1;
  _func_short_short *p_Var2;
  int iVar3;
  qboolean qVar4;
  int in_GS_OFFSET;
  netadr_t local_928;
  char local_914 [259];
  undefined1 local_811;
  char local_810 [2048];
  int local_10;
  
                    /* Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: char[2048] data@[???]
                       Unresolved local var: char[260] szServerName@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((cls.state == ca_disconnected) && (qVar4 = Host_IsServerActive(), qVar4 != false)) {
    cls.state = ca_connecting;
    gfExtendedError = false;
    Q_strncpy(cls.servername,"localhost",0x103);
    cls.servername[0x103] = '\0';
    cls.authprotocol = '\x03';
    CL_SendConnectPacket();
  }
  else if (cls.state == ca_connecting) {
    if (cls.passive == false) {
      dVar1 = (double)cl_resend.value;
      if (dVar1 < 1.5) {
        Cvar_SetValue("cl_resend",1.5);
        dVar1 = (double)cl_resend.value;
      }
      else if (20.0 < dVar1) {
        Cvar_SetValue("cl_resend",20.0);
        dVar1 = (double)cl_resend.value;
      }
      if (dVar1 <= realtime - cls.connect_time) {
        Q_strncpy(local_914,cls.servername,0x104);
        local_811 = 0;
        iVar3 = Q_stricmp(cls.servername,"local");
        if (iVar3 == 0) {
          builtin_strncpy(local_914,"localhost",10);
        }
        qVar4 = NET_StringToAdr(local_914,&local_928);
        p_Var2 = BigShort;
        if (qVar4 == false) {
          Con_Printf("Bad server address\n");
          cls.state = ca_disconnected;
          Q_memset(&g_GameServerAddress,0,0x14);
        }
        else {
          if (local_928.port == 0) {
            iVar3 = Q_atoi("27015");
            local_928.port = (*p_Var2)((short)iVar3);
          }
          if (cls.connect_retry < 4) {
            cls.connect_time = realtime;
            iVar3 = Q_stricmp(local_914,"localhost");
            if (iVar3 != 0) {
              if (cls.connect_retry == 0) {
                Con_Printf("Connecting to %s...\n",local_914);
              }
              else {
                if (cls.connect_retry == 2) {
                  SetLoadingProgressBarStatusText("#GameUI_RetryingConnectionToServer2");
                }
                else if (cls.connect_retry == 3) {
                  SetLoadingProgressBarStatusText("#GameUI_RetryingConnectionToServer3");
                }
                else {
                  SetLoadingProgressBarStatusText("#GameUI_RetryingConnectionToServer");
                }
                Con_Printf("Retrying %s...\n",local_914);
              }
            }
            cls.connect_retry = cls.connect_retry + 1;
            __snprintf_chk(local_810,0x800,1,0x800,&LAB_002650bc,0xff,0xff,0xff,0xff);
            g_GameServerAddress.type = local_928.type;
            g_GameServerAddress.ip[0] = local_928.ip[0];
            g_GameServerAddress.ip[1] = local_928.ip[1];
            g_GameServerAddress.ip[2] = local_928.ip[2];
            g_GameServerAddress.ip[3] = local_928.ip[3];
            g_GameServerAddress.ipx[0] = local_928.ipx[0];
            g_GameServerAddress.ipx[1] = local_928.ipx[1];
            g_GameServerAddress.ipx[2] = local_928.ipx[2];
            g_GameServerAddress.ipx[3] = local_928.ipx[3];
            g_GameServerAddress.ipx[4] = local_928.ipx[4];
            g_GameServerAddress.ipx[5] = local_928.ipx[5];
            g_GameServerAddress.ipx[6] = local_928.ipx[6];
            g_GameServerAddress.ipx[7] = local_928.ipx[7];
            g_GameServerAddress.ipx[8] = local_928.ipx[8];
            g_GameServerAddress.ipx[9] = local_928.ipx[9];
            g_GameServerAddress.port = local_928.port;
            iVar3 = Q_strlen(local_810);
            to.ip[0] = local_928.ip[0];
            to.ip[1] = local_928.ip[1];
            to.ip[2] = local_928.ip[2];
            to.ip[3] = local_928.ip[3];
            to.type = local_928.type;
            to.ipx[0] = local_928.ipx[0];
            to.ipx[1] = local_928.ipx[1];
            to.ipx[2] = local_928.ipx[2];
            to.ipx[3] = local_928.ipx[3];
            to.ipx[4] = local_928.ipx[4];
            to.ipx[5] = local_928.ipx[5];
            to.ipx[6] = local_928.ipx[6];
            to.ipx[7] = local_928.ipx[7];
            to.ipx[8] = local_928.ipx[8];
            to.ipx[9] = local_928.ipx[9];
            to.port = local_928.port;
            NET_SendPacket(NS_CLIENT,iVar3,local_810,to);
          }
          else {
            COM_ExplainDisconnection(true,"#GameUI_CouldNotContactGameServer");
            cls.connect_time = -99999.0;
            cls.connect_retry = 0;
            cls.state = ca_disconnected;
            Q_memset(&g_GameServerAddress,0,0x14);
            CL_Disconnect();
          }
        }
      }
    }
    else if (30.0 < realtime - cls.connect_time) {
      if (cls.challenge == 0) {
        COM_ExplainDisconnection
                  (true,"Joining multicast group failed after %.0f seconds.",0,0x403e0000);
        cls.connect_time = -99999.0;
        cls.connect_retry = 0;
        cls.state = ca_disconnected;
        Q_memset(&g_GameServerAddress,0,0x14);
        cls.passive = false;
        addr_00.ip[0] = cls.connect_stream.ip[0];
        addr_00.ip[1] = cls.connect_stream.ip[1];
        addr_00.ip[2] = cls.connect_stream.ip[2];
        addr_00.ip[3] = cls.connect_stream.ip[3];
        addr_00.type = cls.connect_stream.type;
        addr_00.ipx[0] = cls.connect_stream.ipx[0];
        addr_00.ipx[1] = cls.connect_stream.ipx[1];
        addr_00.ipx[2] = cls.connect_stream.ipx[2];
        addr_00.ipx[3] = cls.connect_stream.ipx[3];
        addr_00.ipx[4] = cls.connect_stream.ipx[4];
        addr_00.ipx[5] = cls.connect_stream.ipx[5];
        addr_00.ipx[6] = cls.connect_stream.ipx[6];
        addr_00.ipx[7] = cls.connect_stream.ipx[7];
        addr_00.ipx[8] = cls.connect_stream.ipx[8];
        addr_00.ipx[9] = cls.connect_stream.ipx[9];
        addr_00.port = cls.connect_stream.port;
        NET_LeaveGroup(cls.netchan.sock,addr_00);
      }
      else {
        Con_Printf("Multicast failed. Falling back to unicast...\n");
        cls.passive = false;
        addr.ip[0] = cls.connect_stream.ip[0];
        addr.ip[1] = cls.connect_stream.ip[1];
        addr.ip[2] = cls.connect_stream.ip[2];
        addr.ip[3] = cls.connect_stream.ip[3];
        addr.type = cls.connect_stream.type;
        addr.ipx[0] = cls.connect_stream.ipx[0];
        addr.ipx[1] = cls.connect_stream.ipx[1];
        addr.ipx[2] = cls.connect_stream.ipx[2];
        addr.ipx[3] = cls.connect_stream.ipx[3];
        addr.ipx[4] = cls.connect_stream.ipx[4];
        addr.ipx[5] = cls.connect_stream.ipx[5];
        addr.ipx[6] = cls.connect_stream.ipx[6];
        addr.ipx[7] = cls.connect_stream.ipx[7];
        addr.ipx[8] = cls.connect_stream.ipx[8];
        addr.ipx[9] = cls.connect_stream.ipx[9];
        addr.port = cls.connect_stream.port;
        NET_LeaveGroup(cls.netchan.sock,addr);
        CL_SendConnectPacket();
      }
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_CheckGameDirectory  @ 00156bf0
qboolean CL_CheckGameDirectory(char *gamedir)

{
  qboolean qVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] szGD@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((gamedir == (char *)0x0) || (*gamedir == '\0')) {
    Con_Printf("Server didn\'t specify a gamedir, assuming no change\n");
    qVar1 = true;
  }
  else {
    COM_FileBase(com_gamedir,local_114);
    iVar2 = Q_stricmp(local_114,gamedir);
    qVar1 = true;
    if (iVar2 != 0) {
                    /* Unresolved local var: char[260] szGD@[???] */
      Con_Printf("Server is running game %s.  Restart in that game to connect.\n",gamedir);
      CL_Disconnect_f();
      qVar1 = false;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_CheckPredictionError  @ 0013a530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CheckPredictionError(void)

{
  vec_t vVar1;
  vec_t vVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int frame@[???]
                       Unresolved local var: int command@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float len@[???] */
  iVar4 = cl.parsecountmod;
  uVar5 = cls.netchan.incoming_acknowledged & CL_UPDATE_MASK;
  iVar3 = cl.playernum * 0x154 + cl.parsecountmod * 0x4318;
  local_18 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar3 + 0x111e0) -
             cl.predicted_origins[uVar5][0];
  local_14 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar3 + 0x111e4) -
             cl.predicted_origins[uVar5][1];
  local_10 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar3 + 0x111e8) -
             cl.predicted_origins[uVar5][2];
  fVar6 = Length(&local_18);
  if (fVar6 <= 64.0) {
    if ((cl_showerror.value != 0.0) && (0.5 < fVar6)) {
      CL_CheckPredictionError::pos = CL_CheckPredictionError::pos + 1;
      Con_NPrintf((CL_CheckPredictionError::pos & 3U) + 10,"pred. error %.3f units",(double)fVar6);
    }
    cl.prediction_error[0] = local_18;
    cl.prediction_error[1] = local_14;
    iVar3 = cl.playernum * 0x154 + iVar4 * 0x4318;
    vVar1 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar3 + 0x111e4);
    vVar2 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar3 + 0x111e8);
    cl.prediction_error[2] = local_10;
    cl.predicted_origins[iVar4][0] =
         *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar3 + 0x111e0);
    cl.predicted_origins[iVar4][1] = vVar1;
    cl.predicted_origins[iVar4][2] = vVar2;
    if ((0.25 < fVar6) && (cl.maxclients != 1)) {
      cl_correction_time = (double)cl_smoothtime.value;
      return;
    }
  }
  else {
    cl.prediction_error[0] = vec3_origin[0];
    cl.prediction_error[1] = vec3_origin[1];
    cl.prediction_error[2] = vec3_origin[2];
  }
  return;
}


// CL_CleanFileName  @ 001460d0
char * CL_CleanFileName(char *filename)

{
                    /* Unresolved local var: char * pfilename@[???] */
  if (filename != (char *)0x0) {
    if (*filename == '!') {
      filename = "customization";
    }
    return filename;
  }
  return (char *)0x0;
}


// CL_ClearCaches  @ 001462e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ClearCaches(void)

{
  event_s *peVar1;
  event_s *dest;
  
                    /* Unresolved local var: int i@[???] */
  dest = cl.event_precache + 1;
  do {
    if (dest->pszScript == (char *)0x0) {
      return;
    }
    Mem_Free(dest->pszScript);
    Mem_Free(dest->filename);
    peVar1 = dest + 1;
    Q_memset(dest,0,0x10);
    dest = peVar1;
  } while (peVar1 != (event_s *)cl.model_precache);
  return;
}


// CL_ClearClientState  @ 00146340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ClearClientState(void)

{
  int iVar1;
  entity_state_s **ppeVar2;
  customization_t *pHead;
  customization_t *pcVar3;
  event_s *peVar4;
  event_s *dest;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: packet_entities_t * pClientPack@[???] */
  if (0 < CL_UPDATE_BACKUP) {
    iVar5 = 0;
    iVar1 = CL_UPDATE_BACKUP;
    ppeVar2 = &cl.frames[0].packet_entities.entities;
    do {
      if (*ppeVar2 != (entity_state_s *)0x0) {
        Mem_Free(*ppeVar2);
        iVar1 = CL_UPDATE_BACKUP;
      }
      iVar5 = iVar5 + 1;
      *ppeVar2 = (entity_state_s *)0x0;
      ((packet_entities_t *)(ppeVar2 + -0x21))->num_entities = 0;
      ppeVar2 = ppeVar2 + 0x10c6;
    } while (iVar5 < iVar1);
  }
  CL_ClearResourceLists();
  pHead = &cl.players[0].customdata;
  do {
    pcVar3 = (customization_t *)(pHead[3].resource.rguc_reserved + 2);
    COM_ClearCustomizationList(pHead,false);
    pHead = pcVar3;
  } while (pcVar3 != (customization_t *)&cl.instanced_baseline[1].scale);
  dest = cl.event_precache + 1;
  do {
    if (dest->pszScript == (char *)0x0) break;
                    /* Unresolved local var: int i@[???] */
    Mem_Free(dest->pszScript);
    Mem_Free(dest->filename);
    peVar4 = dest + 1;
    Q_memset(dest,0,0x10);
    dest = peVar4;
  } while (peVar4 != (event_s *)cl.model_precache);
  Q_memset(&cl,0,0x1b0e68);
  cl.resourcesneeded.pNext = &cl.resourcesneeded;
  cl.resourcesonhand.pPrev = &cl.resourcesonhand;
  cl.resourcesonhand.pNext = &cl.resourcesonhand;
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int nSize@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: uchar[16] rgucMD5_hash@[???]
                       Unresolved local var: resource_t * pNewResource@[???] */
  cl.resourcesneeded.pPrev = &cl.resourcesneeded;
  if (cls.state == ca_dedicated) {
    return;
  }
  CL_CreateResourceList();
  return;
}


// CL_ClearPacket  @ 00132bc0
void CL_ClearPacket(packet_entities_t *pPacket)

{
  if (pPacket->entities != (entity_state_s *)0x0) {
    Mem_Free(pPacket->entities);
  }
  pPacket->entities = (entity_state_s *)0x0;
  pPacket->num_entities = 0;
  return;
}


// CL_ClearResourceList  @ 00154930
void CL_ClearResourceList(resource_t *pList)

{
  resource_t *prVar1;
  resource_t *p;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  p = pList->pNext;
  if ((pList != p) && (p != (resource_t *)0x0)) {
    do {
      prVar1 = p->pNext;
      if ((p->pPrev == (resource_s *)0x0) || (prVar1 == (resource_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
      }
      if ((p == prVar1) || (p->pPrev == p)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Attempt to free last entry in list.");
      }
      p->pPrev->pNext = prVar1;
      p->pNext->pPrev = p->pPrev;
      p->pPrev = (resource_s *)0x0;
      p->pNext = (resource_s *)0x0;
      Mem_Free(p);
    } while ((prVar1 != (resource_t *)0x0) && (p = prVar1, pList != prVar1));
  }
  pList->pPrev = pList;
  pList->pNext = pList;
  return;
}


// CL_ClearResourceLists  @ 00154a00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ClearResourceLists(void)

{
  resource_s *prVar1;
  resource_s *prVar2;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  cl.downloadUrl[0] = '\0';
  if ((cl.resourcesneeded.pNext != &cl.resourcesneeded) &&
     (prVar2 = cl.resourcesneeded.pNext, cl.resourcesneeded.pNext != (resource_s *)0x0)) {
    do {
      prVar1 = prVar2->pNext;
      if ((prVar2->pPrev == (resource_s *)0x0) || (prVar1 == (resource_s *)0x0)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
      }
      if ((prVar2 == prVar1) || (prVar2->pPrev == prVar2)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Attempt to free last entry in list.");
      }
      prVar2->pPrev->pNext = prVar1;
      prVar2->pNext->pPrev = prVar2->pPrev;
      prVar2->pPrev = (resource_s *)0x0;
      prVar2->pNext = (resource_s *)0x0;
      Mem_Free(prVar2);
    } while ((prVar1 != (resource_s *)0x0) && (prVar2 = prVar1, prVar1 != &cl.resourcesneeded));
  }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  cl.resourcesneeded.pPrev = &cl.resourcesneeded;
  cl.resourcesneeded.pNext = &cl.resourcesneeded;
  prVar2 = cl.resourcesonhand.pNext;
  while( true ) {
    if ((prVar2 == (resource_s *)0x0) || (prVar2 == &cl.resourcesonhand)) {
      cl.resourcesonhand.pPrev = &cl.resourcesonhand;
      cl.resourcesonhand.pNext = &cl.resourcesonhand;
      return;
    }
    prVar1 = prVar2->pNext;
    if ((prVar2->pPrev == (resource_s *)0x0) || (prVar1 == (resource_s *)0x0)) break;
    if ((prVar2 == prVar1) || (prVar2->pPrev == prVar2)) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Attempt to free last entry in list.");
    }
    prVar2->pPrev->pNext = prVar1;
    prVar2->pNext->pPrev = prVar2->pPrev;
    prVar2->pPrev = (resource_s *)0x0;
    prVar2->pNext = (resource_s *)0x0;
    Mem_Free(prVar2);
    prVar2 = prVar1;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
}


// CL_ClearState  @ 00146470
void CL_ClearState(qboolean bQuiet)

{
  int iVar1;
  qboolean qVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  qVar2 = Host_IsServerActive();
  if (qVar2 == false) {
    Host_ClearMemory(bQuiet);
  }
  CL_ClearClientState();
  SZ_Clear(&cls.netchan.message);
  Q_memset(cl_efrags,0,0x2800);
  Q_memset(cl_dlights,0,0x500);
  Q_memset(cl_elights,0,0xa00);
  Q_memset(cl_lightstyle,0,0x1100);
  CL_TempEntInit();
  cl.free_efrags = cl_efrags;
  iVar3 = 0;
  do {
    iVar1 = iVar3 + 0x10;
    *(int *)((int)&(cl.free_efrags)->entnext + iVar3) = (int)&cl.free_efrags[1].leaf + iVar3;
    iVar3 = iVar1;
  } while (iVar1 != 0x27f0);
  cl.free_efrags[0x27f].entnext = (efrag_s *)0x0;
  return;
}


// CL_ClientDllQuery  @ 001445f0
/* WARNING: Type propagation algorithm not settling */

int __regparm3 CL_ClientDllQuery(char *s)

{
  netadr_t to;
  int iVar1;
  int in_GS_OFFSET;
  int local_814 [2];
  char local_80c [2044];
  int local_10;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int valid@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_814 + 1,0,0x800);
  local_814[0] = 0x7fc;
  iVar1 = ClientDLL_ConnectionlessPacket(&net_from,s,local_80c,local_814);
  if ((local_814[0] < 0x7fd) && (local_814[0] != 0)) {
    local_814[1] = 0xffffffff;
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
    NET_SendPacket(NS_CLIENT,local_814[0] + 4,local_814 + 1,to);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ClientDllQuery  @ 00145b10
int CL_ClientDllQuery(char *s)

{
  qboolean qVar1;
  int iVar2;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int valid@[???] */
  qVar1 = Host_IsServerActive();
  if (qVar1 != false) {
    qVar1 = Host_IsSinglePlayerGame();
    if (qVar1 == false) {
      iVar2 = CL_ClientDllQuery(s);
      return iVar2;
    }
  }
  return 0;
}


// CL_ClientQueueEvent  @ 001390b0
void CL_ClientQueueEvent(int flags,int index,int client_index,float delay,event_args_t *pargs)

{
  float fVar1;
  int iVar2;
  event_info_s *peVar3;
  event_state_t *peVar4;
  uint uVar5;
  event_state_t *peVar6;
  
                    /* Unresolved local var: event_info_t * ei@[???] */
  peVar6 = &cl.events;
  peVar4 = &cl.events;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  iVar2 = 0;
  do {
    if (peVar4->ei[0].index == 0) {
      peVar3 = cl.events.ei + iVar2;
      if (peVar3 != (event_info_s *)0x0) goto LAB_00139111;
      break;
    }
    iVar2 = iVar2 + 1;
    peVar4 = (event_state_t *)(peVar4->ei + 1);
  } while (iVar2 != 0x40);
  if ((flags & 2U) != 0) {
    iVar2 = 0;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
      if ((peVar6->ei[0].index == 0) || ((peVar6->ei[0].flags & 2) == 0)) {
        peVar3 = cl.events.ei + iVar2;
        if (peVar3 == (event_info_s *)0x0) {
          return;
        }
LAB_00139111:
        peVar3->packet_index = 0;
        peVar3->index = (ushort)index;
        uVar5 = 0;
        do {
          *(undefined4 *)((int)(peVar3->args).origin + (uVar5 - 8)) =
               *(undefined4 *)((int)pargs->origin + (uVar5 - 8));
          uVar5 = uVar5 + 4;
        } while (uVar5 < 0x48);
        fVar1 = 0.0;
        if (delay != 0.0) {
          fVar1 = delay + (float)cl.time;
        }
        peVar3->fire_time = fVar1;
        peVar3->flags = flags;
        return;
      }
      iVar2 = iVar2 + 1;
      peVar6 = (event_state_t *)(peVar6->ei + 1);
    } while (iVar2 != 0x40);
  }
  return;
}


// CL_Commentator_f  @ 00144050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Commentator_f(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * val@[???] */
  iVar1 = Cmd_Argc();
  if (1 < iVar1) {
    pcVar2 = Cmd_Args();
    iVar1 = Q_atoi(pcVar2);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      if (iVar1 != 1) {
        return;
      }
      uVar3 = 3;
    }
    pcVar2 = va("%i",uVar3);
    Info_SetValueForStarKey(cls.userinfo,"*hltv",pcVar2,0x100);
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * val@[???] */
  pcVar2 = Info_ValueForKey(cls.userinfo,"*hltv");
  iVar1 = Q_strlen(pcVar2);
  if ((iVar1 != 0) && (iVar1 = Q_atoi(pcVar2), iVar1 == 3)) {
    Con_Printf("HLTV commentator mode enabled.\n");
    return;
  }
  Con_Printf("HLTV commentator mode disabled.\n");
  return;
}


// CL_CompareTimestamps  @ 00132380
qboolean CL_CompareTimestamps(float t1,float t2)

{
                    /* Unresolved local var: int iTime1@[???]
                       Unresolved local var: int iTime2@[???] */
  return (uint)(((int)(t1 * 1000.0) - (int)(t2 * 1000.0)) + 1U < 3);
}


// CL_ComputeClientInterpolationAmount  @ 00149fc0
void CL_ComputeClientInterpolationAmount(usercmd_t *cmd)

{
  float fVar1;
  float fVar2;
  char *value;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: float minupdaterate@[???]
                       Unresolved local var: float maxupdaterate@[???]
                       Unresolved local var: int minexinterp@[???]
                       Unresolved local var: int maxexinterp@[???]
                       Unresolved local var: int interpolation_msec@[???]
                       Unresolved local var: qboolean forced@[???] */
  if (cl_updaterate.value < 10.0) {
    Cvar_Set("cl_updaterate","20");
    Con_Printf("cl_updaterate minimum is %f, resetting to default (20)\n",0);
  }
  if (102.0 < cl_updaterate.value) {
    Cvar_Set("cl_updaterate","102");
    Con_Printf("cl_updaterate maximum is %f, resetting to maximum (102)\n",0,0x40598000);
  }
  iVar3 = (-(uint)(cls.spectator == false) & 0xffffff9c) + 200;
  if (cl_updaterate.value <= 0.0) {
    iVar4 = 0x32;
  }
  else {
    iVar4 = (int)(1000.0 / cl_updaterate.value);
    if (iVar4 < 1) {
      iVar4 = 1;
    }
  }
  iVar5 = (int)(ex_interp.value * 1000.0);
  if (iVar5 + 1 < iVar4) {
    Con_Printf("ex_interp forced up to %i msec\n",iVar4);
    iVar5 = iVar4;
  }
  else {
    if (iVar5 + -1 <= iVar3) goto LAB_0014a052;
    Con_Printf("ex_interp forced down to %i msec\n",iVar3);
    iVar5 = iVar3;
  }
                    /* Unresolved local var: float interpolation_sec@[???] */
  value = va("%f",(double)((float)iVar5 / 1000.0));
  Cvar_Set("ex_interp",value);
LAB_0014a052:
  if (iVar4 < iVar5) {
    iVar4 = iVar5;
  }
                    /* Unresolved local var: int msec@[???]
                       Unresolved local var: float fgoal@[???] */
  if (iVar3 <= iVar4) {
    iVar4 = iVar3;
  }
  if ((float)iVar4 / 1000.0 != g_flInterpolationAmount) {
                    /* Unresolved local var: float maxmove@[???]
                       Unresolved local var: float diff@[???] */
    fVar2 = (float)host_frametime * 0.05;
    fVar1 = (float)iVar4 / 1000.0 - g_flInterpolationAmount;
    if (fVar1 <= 0.0) {
      if (fVar2 < -fVar1) {
        fVar1 = -fVar2;
      }
    }
    else if (fVar2 < fVar1) {
      fVar1 = fVar2;
    }
    g_flInterpolationAmount = fVar1 + g_flInterpolationAmount;
  }
  iVar3 = (int)(g_flInterpolationAmount * 1000.0);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (100 < iVar3) {
    iVar3 = 100;
  }
  cmd->lerp_msec = (short)iVar3;
  return;
}


// CL_ComputePacketLoss  @ 00149e50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ComputePacketLoss(void)

{
  uint uVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frm@[DW_OP_reg0(EAX)]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int lost@[???] */
  if (cls.packet_loss_recalc_time <= realtime) {
    cls.packet_loss_recalc_time = realtime + 1.0;
    uVar1 = (cls.netchan.incoming_sequence - CL_UPDATE_BACKUP) + 1;
    if (cls.netchan.incoming_sequence < (int)uVar1) {
      cls.packet_loss = 0.0;
    }
    else {
      iVar2 = 0;
      do {
        while (cl.frames[uVar1 & CL_UPDATE_MASK].receivedtime == -1.0) {
          uVar1 = uVar1 + 1;
          iVar2 = iVar2 + 1;
          if (cls.netchan.incoming_sequence + 1U == uVar1) goto LAB_00149ec4;
        }
        uVar1 = uVar1 + 1;
      } while (cls.netchan.incoming_sequence + 1U != uVar1);
LAB_00149ec4:
      cls.packet_loss =
           ((float)iVar2 * 100.0) /
           (float)(cls.netchan.incoming_sequence -
                  (cls.netchan.incoming_sequence - CL_UPDATE_BACKUP));
    }
  }
  return;
}


// CL_ComputePlayerOrigin  @ 0013cf20
void CL_ComputePlayerOrigin(cl_entity_t *ent)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  vec_t in_XMM0_Da;
  float local_40;
  float local_3c;
  float local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: vec3_t target_origin@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: float targettime@[???] */
  if ((ent->player != false) && (ent->index + -1 != cl.playernum)) {
    fVar4 = (float)cl.time - ex_interp.value;
                    /* Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t0@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: int i0@[???]
                       Unresolved local var: int i1@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float at@[???]
                       Unresolved local var: int imod@[???] */
    uVar3 = ent->current_position;
    uVar7 = uVar3 & 0x3f;
    uVar5 = uVar3 - 1;
    uVar6 = uVar5 & 0x3f;
    if (fVar4 <= ent->ph[uVar7].animtime) {
      do {
        fVar1 = ent->ph[uVar5 & 0x3f].animtime;
        if (fVar1 == 0.0) break;
        if (fVar1 < fVar4) {
          uVar7 = uVar5 + 1 & 0x3f;
          uVar6 = uVar5 & 0x3f;
          break;
        }
        uVar5 = uVar5 - 1;
      } while (uVar3 - 0x3f != uVar5);
    }
    if (ent->ph + uVar7 == (position_history_t *)0x0) {
      local_20 = NAN;
      local_30 = NAN;
      local_24 = NAN;
      local_28 = NAN;
      local_34 = NAN;
      local_2c = in_XMM0_Da;
    }
    else if (ent->ph + uVar6 == (position_history_t *)0x0) {
      local_20 = NAN;
      local_30 = NAN;
      local_24 = NAN;
      local_28 = NAN;
      local_34 = NAN;
      local_2c = in_XMM0_Da;
    }
    else {
      fVar1 = ent->ph[uVar7].animtime;
      if (fVar1 == 0.0) {
        local_34 = ent->ph[uVar6].origin[0];
        local_30 = ent->ph[uVar6].origin[1];
        local_28 = ent->ph[uVar6].angles[0];
        local_2c = ent->ph[uVar6].origin[2];
        local_24 = ent->ph[uVar6].angles[1];
        local_20 = ent->ph[uVar6].angles[2];
      }
      else {
        fVar2 = ent->ph[uVar6].animtime;
        local_40 = ent->ph[uVar7].origin[0] - ent->ph[uVar6].origin[0];
        local_3c = ent->ph[uVar7].origin[1] - ent->ph[uVar6].origin[1];
        local_38 = ent->ph[uVar7].origin[2] - ent->ph[uVar6].origin[2];
        if (fVar2 == fVar1) {
          fVar4 = 1.0;
        }
        else {
          fVar4 = (fVar4 - fVar2) / (fVar1 - fVar2);
          if (fVar4 < 0.0) {
            fVar4 = 0.0;
          }
          else if (1.2 < fVar4) {
            fVar4 = 1.2;
          }
        }
        VectorMA(ent->ph[uVar6].origin,fVar4,&local_40,&local_34);
        InterpolateAngles(ent->ph[uVar6].angles,ent->ph[uVar7].angles,&local_28,fVar4);
      }
    }
    ent->angles[0] = local_28;
    ent->angles[1] = local_24;
    ent->angles[2] = local_20;
    ent->origin[0] = local_34;
    ent->origin[1] = local_30;
    ent->origin[2] = local_2c;
  }
  return;
}


// CL_ConnectClient  @ 00145850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ConnectClient(void)

{
  netadr_t a;
  netadr_t a_00;
  netadr_t adr;
  int iVar1;
  char *pcVar2;
  double dVar3;
  
  ContinueLoadingProgressBar("ClientConnect",2,0.0);
  if (cls.state == ca_connected) {
    if (cls.demoplayback == false) {
      Con_DPrintf("Duplicate connect ack. received.  Ignored.\n");
      return;
    }
  }
  else {
    cls.userid = 0;
    cls.trueaddress[0] = '\0';
    iVar1 = Cmd_Argc();
    if (2 < iVar1) {
      pcVar2 = Cmd_Argv(1);
      cls.userid = Q_atoi(pcVar2);
      pcVar2 = Cmd_Argv(2);
      Q_strncpy(cls.trueaddress,pcVar2,0x1f);
      cls.trueaddress[0x1f] = '\0';
      iVar1 = Cmd_Argc();
      if (4 < iVar1) {
        pcVar2 = Cmd_Argv(4);
        cls.build_num = Q_atoi(pcVar2);
      }
    }
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
    Netchan_Setup(NS_CLIENT,&cls.netchan,adr,-1,&cls,CL_GetFragmentSize);
    NET_ClearLagData(true,false);
    if (fs_startup_timings.value != 0.0) {
      iVar1 = g_iCurrentTiming + 1;
      g_iCurrentTiming = iVar1;
      g_StartupTimings[iVar1].name = "connection accepted by server";
      dVar3 = Sys_FloatTime();
      g_StartupTimings[iVar1].time = (float)dVar3;
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
    pcVar2 = NET_AdrToString(a);
    iVar1 = Q_stricmp("loopback",pcVar2);
    if (iVar1 == 0) {
      Con_DPrintf("Connection accepted.\n");
    }
    else {
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
      pcVar2 = NET_AdrToString(a_00);
      Con_Printf("Connection accepted by %s\n",pcVar2);
    }
    cls.state = ca_connected;
    MSG_WriteByte(&cls.netchan.message,3);
    MSG_WriteString(&cls.netchan.message,"new");
    cls.signon = 0;
    cls.connect_time = realtime;
    cl.validsequence = 0;
    cl.delta_sequence = -1;
    cls.demonum = -1;
    cls.nextcmdtime = (float)realtime;
    cls.lastoutgoingcommand = -1;
  }
  return;
}


// CL_ConnectTest  @ 001479a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ConnectTest(void)

{
                    /* Unresolved local var: double disconnect_time@[???]
                       Unresolved local var: double connect_time@[???] */
  return;
}


// CL_Connect_f  @ 00147460
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Connect_f(void)

{
  CareerStateType CVar1;
  int iVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  char local_114 [259];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char * server@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int num@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = Cmd_Argc();
  if (iVar2 < 2) {
    Con_Printf("usage: connect <server>\n");
  }
  else {
    SetCStrikeFlags();
    if (((g_bIsCStrike == 0) && (g_bIsCZero == 0)) || (cmd_source == src_command)) {
      pcVar3 = Cmd_Args();
      if (pcVar3 != (char *)0x0) {
        Q_strncpy(local_114,pcVar3,0x104);
        local_11 = 0;
        if (cls.demoplayback != false) {
          CL_StopPlayback();
        }
                    /* Unresolved local var: CareerStateType careerState@[???] */
        CVar1 = g_careerState;
        CL_Disconnect();
        if (CVar1 == CAREER_LOADING) {
          g_careerState = CAREER_LOADING;
        }
        StartLoadingProgressBar("Connecting",0xc);
        SetLoadingProgressBarStatusText("#GameUI_EstablishingConnection");
        iVar2 = Q_atoi(local_114);
        pcVar3 = Q_strstr(local_114,".");
        if (((0 < iVar2) && (pcVar3 == (char *)0x0)) && (iVar2 <= num_servers)) {
          pcVar3 = NET_AdrToString(cached_servers[iVar2 + -1].adr);
          Q_strncpy(local_114,pcVar3,0x104);
          local_11 = 0;
        }
        Q_memset(msg_buckets,0,0x100);
        Q_memset(total_data,0,0x100);
        Q_strncpy(cls.servername,local_114,0x103);
        cls.state = ca_connecting;
        cls.connect_time._0_4_ = 0;
        cls.connect_time._4_4_ = 0xc0f869f0;
        cls.connect_retry = 0;
        cls.passive = false;
        cls.build_num = 0;
        cls.spectator = false;
        cls.isVAC2Secure = false;
        cls.servername[0x103] = '\0';
        cls.GameServerSteamID._0_4_ = 0;
        cls.GameServerSteamID._4_4_ = 0;
        Q_memset(&g_GameServerAddress,0,0x14);
        cls.challenge = 0;
        gfExtendedError = false;
        g_LastScreenUpdateTime = 0.0;
        iVar2 = Q_strnicmp(cls.servername,"local",5);
        if (iVar2 != 0) {
          NET_Config(true);
        }
      }
    }
    else {
      Con_Printf("Connect only works from the console.\n");
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ConnectionlessPacket  @ 00148000
/* WARNING: Removing unreachable block (ram,0x00148dfd) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ConnectionlessPacket(void)

{
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t a_02;
  netadr_t a_03;
  netadr_t a_04;
  netadr_t a_05;
  netadr_t a_06;
  netadr_t a_07;
  netadr_t a_08;
  netadr_t a_09;
  netadr_t a_10;
  netadr_t a_11;
  netadr_t a_12;
  netadr_t to;
  netadr_t b;
  netadr_t b_00;
  netadr_t b_01;
  netadr_t b_02;
  netadr_t b_03;
  netadr_t b_04;
  netadr_t b_05;
  netadr_t b_06;
  netadr_t b_07;
  netadr_t b_08;
  netadr_t b_09;
  netadr_t b_10;
  netadr_t b_11;
  netadr_t b_12;
  ulonglong uVar1;
  ushort uVar2;
  char *pcVar3;
  byte *s1;
  int iVar4;
  uint uVar5;
  qboolean qVar6;
  char *pcVar7;
  uint uVar8;
  byte bVar9;
  server_cache_t *psVar10;
  int in_GS_OFFSET;
  byte bVar11;
  int local_89c;
  netadrtype_t local_898;
  uchar local_894 [4];
  uchar local_890 [4];
  uchar local_88c [8];
  netadrtype_t local_884;
  uchar local_880 [4];
  uchar local_87c [4];
  uchar local_878 [8];
  netadrtype_t local_870;
  uchar local_86c [4];
  uchar local_868 [4];
  uchar local_864 [8];
  netadrtype_t local_85c;
  uchar local_858 [4];
  uchar local_854 [4];
  uchar local_850 [8];
  netadrtype_t local_848;
  uchar local_844 [4];
  uchar local_840 [4];
  uchar local_83c [8];
  netadrtype_t local_834;
  uchar local_830 [4];
  uchar local_82c [4];
  uchar local_828 [8];
  server_cache_t local_820;
  int local_20;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * cmd@[???]
                       Unresolved local var: char * args@[???]
                       Unresolved local var: uchar c@[???] */
  bVar11 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  MSG_BeginReading();
  MSG_ReadLong();
  pcVar3 = MSG_ReadStringLine();
  Cmd_TokenizeString(pcVar3);
  s1 = (byte *)Cmd_Argv(0);
  if (s1 == (byte *)0x0) {
    iVar4 = Q_stricmp((char *)0x0,"challenge");
    if (iVar4 == 0) goto LAB_00148238;
    bVar9 = 0;
  }
  else {
    bVar9 = *s1;
    iVar4 = Q_stricmp((char *)s1,"challenge");
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    if (iVar4 == 0) {
LAB_00148238:
      local_898 = net_from.type;
      local_894[0] = net_from.ip[0];
      local_894[1] = net_from.ip[1];
      local_894[2] = net_from.ip[2];
      local_894[3] = net_from.ip[3];
      local_890[0] = net_from.ipx[0];
      local_890[1] = net_from.ipx[1];
      local_890[2] = net_from.ipx[2];
      local_890[3] = net_from.ipx[3];
      local_88c[0] = net_from.ipx[4];
      local_88c[1] = net_from.ipx[5];
      local_88c[2] = net_from.ipx[6];
      local_88c[3] = net_from.ipx[7];
      local_88c._4_4_ = net_from._16_4_;
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
      b.ip[0] = g_GameServerAddress.ip[0];
      b.ip[1] = g_GameServerAddress.ip[1];
      b.ip[2] = g_GameServerAddress.ip[2];
      b.ip[3] = g_GameServerAddress.ip[3];
      b.type = g_GameServerAddress.type;
      b.ipx[0] = g_GameServerAddress.ipx[0];
      b.ipx[1] = g_GameServerAddress.ipx[1];
      b.ipx[2] = g_GameServerAddress.ipx[2];
      b.ipx[3] = g_GameServerAddress.ipx[3];
      b.ipx[4] = g_GameServerAddress.ipx[4];
      b.ipx[5] = g_GameServerAddress.ipx[5];
      b.ipx[6] = g_GameServerAddress.ipx[6];
      b.ipx[7] = g_GameServerAddress.ipx[7];
      b.ipx[8] = g_GameServerAddress.ipx[8];
      b.ipx[9] = g_GameServerAddress.ipx[9];
      b.port = g_GameServerAddress.port;
      qVar6 = NET_CompareAdr(a,b);
      if (qVar6 == false) {
        a_00.ip[0] = local_894[0];
        a_00.ip[1] = local_894[1];
        a_00.ip[2] = local_894[2];
        a_00.ip[3] = local_894[3];
        a_00.type = local_898;
        a_00.ipx[0] = local_890[0];
        a_00.ipx[1] = local_890[1];
        a_00.ipx[2] = local_890[2];
        a_00.ipx[3] = local_890[3];
        a_00.ipx[4] = local_88c[0];
        a_00.ipx[5] = local_88c[1];
        a_00.ipx[6] = local_88c[2];
        a_00.ipx[7] = local_88c[3];
        a_00._16_4_ = local_88c._4_4_;
        b_00.ip[0] = g_rconaddress.ip[0];
        b_00.ip[1] = g_rconaddress.ip[1];
        b_00.ip[2] = g_rconaddress.ip[2];
        b_00.ip[3] = g_rconaddress.ip[3];
        b_00.type = g_rconaddress.type;
        b_00.ipx[0] = g_rconaddress.ipx[0];
        b_00.ipx[1] = g_rconaddress.ipx[1];
        b_00.ipx[2] = g_rconaddress.ipx[2];
        b_00.ipx[3] = g_rconaddress.ipx[3];
        b_00.ipx[4] = g_rconaddress.ipx[4];
        b_00.ipx[5] = g_rconaddress.ipx[5];
        b_00.ipx[6] = g_rconaddress.ipx[6];
        b_00.ipx[7] = g_rconaddress.ipx[7];
        b_00.ipx[8] = g_rconaddress.ipx[8];
        b_00.ipx[9] = g_rconaddress.ipx[9];
        b_00.port = g_rconaddress.port;
        qVar6 = NET_CompareAdr(a_00,b_00);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (qVar6 == false) goto LAB_001482c0;
      }
      CL_ServiceChallenge();
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      goto LAB_001482c0;
    }
    if (bVar9 == 0x42) {
      local_884 = net_from.type;
      local_880[0] = net_from.ip[0];
      local_880[1] = net_from.ip[1];
      local_880[2] = net_from.ip[2];
      local_880[3] = net_from.ip[3];
      local_87c[0] = net_from.ipx[0];
      local_87c[1] = net_from.ipx[1];
      local_87c[2] = net_from.ipx[2];
      local_87c[3] = net_from.ipx[3];
      local_878[0] = net_from.ipx[4];
      local_878[1] = net_from.ipx[5];
      local_878[2] = net_from.ipx[6];
      local_878[3] = net_from.ipx[7];
      local_878._4_4_ = net_from._16_4_;
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
      b_01.ip[0] = g_GameServerAddress.ip[0];
      b_01.ip[1] = g_GameServerAddress.ip[1];
      b_01.ip[2] = g_GameServerAddress.ip[2];
      b_01.ip[3] = g_GameServerAddress.ip[3];
      b_01.type = g_GameServerAddress.type;
      b_01.ipx[0] = g_GameServerAddress.ipx[0];
      b_01.ipx[1] = g_GameServerAddress.ipx[1];
      b_01.ipx[2] = g_GameServerAddress.ipx[2];
      b_01.ipx[3] = g_GameServerAddress.ipx[3];
      b_01.ipx[4] = g_GameServerAddress.ipx[4];
      b_01.ipx[5] = g_GameServerAddress.ipx[5];
      b_01.ipx[6] = g_GameServerAddress.ipx[6];
      b_01.ipx[7] = g_GameServerAddress.ipx[7];
      b_01.ipx[8] = g_GameServerAddress.ipx[8];
      b_01.ipx[9] = g_GameServerAddress.ipx[9];
      b_01.port = g_GameServerAddress.port;
      qVar6 = NET_CompareAdr(a_01,b_01);
      if (qVar6 == false) {
        a_08.ip[0] = local_880[0];
        a_08.ip[1] = local_880[1];
        a_08.ip[2] = local_880[2];
        a_08.ip[3] = local_880[3];
        a_08.type = local_884;
        a_08.ipx[0] = local_87c[0];
        a_08.ipx[1] = local_87c[1];
        a_08.ipx[2] = local_87c[2];
        a_08.ipx[3] = local_87c[3];
        a_08.ipx[4] = local_878[0];
        a_08.ipx[5] = local_878[1];
        a_08.ipx[6] = local_878[2];
        a_08.ipx[7] = local_878[3];
        a_08._16_4_ = local_878._4_4_;
        b_08.ip[0] = g_rconaddress.ip[0];
        b_08.ip[1] = g_rconaddress.ip[1];
        b_08.ip[2] = g_rconaddress.ip[2];
        b_08.ip[3] = g_rconaddress.ip[3];
        b_08.type = g_rconaddress.type;
        b_08.ipx[0] = g_rconaddress.ipx[0];
        b_08.ipx[1] = g_rconaddress.ipx[1];
        b_08.ipx[2] = g_rconaddress.ipx[2];
        b_08.ipx[3] = g_rconaddress.ipx[3];
        b_08.ipx[4] = g_rconaddress.ipx[4];
        b_08.ipx[5] = g_rconaddress.ipx[5];
        b_08.ipx[6] = g_rconaddress.ipx[6];
        b_08.ipx[7] = g_rconaddress.ipx[7];
        b_08.ipx[8] = g_rconaddress.ipx[8];
        b_08.ipx[9] = g_rconaddress.ipx[9];
        b_08.port = g_rconaddress.port;
        qVar6 = NET_CompareAdr(a_08,b_08);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (qVar6 == false) goto LAB_001482c0;
      }
      CL_ConnectClient();
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      goto LAB_001482c0;
    }
    if (bVar9 == 0x47) {
      if (cls.state == ca_connecting) {
        iVar4 = Cmd_Argc();
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (iVar4 == 4) {
          pcVar3 = Cmd_Argv(1);
          cls.challenge = Q_atoi(pcVar3);
          pcVar3 = Cmd_Argv(2);
          uVar5 = Q_atoi(pcVar3);
          cls.authprotocol = (byte)uVar5;
          if (cls.authprotocol == 0xff) {
            cls.authprotocol = '\x02';
          }
          else if (cls.authprotocol != '\x02') {
            Con_Printf("Invalid multicast authentication type (%i).\n",uVar5 & 0xff);
            CL_Disconnect();
            qVar6 = Host_IsServerActive();
            uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
            if (qVar6 != false) {
              Host_ShutdownServer(false);
              uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
            }
            goto LAB_001482c0;
          }
          pcVar3 = Cmd_Argv(3);
          CL_Listen(pcVar3);
          uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        }
      }
      goto LAB_001482c0;
    }
    if (bVar9 == 0x41) {
      local_870 = net_from.type;
      local_86c[0] = net_from.ip[0];
      local_86c[1] = net_from.ip[1];
      local_86c[2] = net_from.ip[2];
      local_86c[3] = net_from.ip[3];
      local_868[0] = net_from.ipx[0];
      local_868[1] = net_from.ipx[1];
      local_868[2] = net_from.ipx[2];
      local_868[3] = net_from.ipx[3];
      local_864[0] = net_from.ipx[4];
      local_864[1] = net_from.ipx[5];
      local_864[2] = net_from.ipx[6];
      local_864[3] = net_from.ipx[7];
      local_864._4_4_ = net_from._16_4_;
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
      b_02.ip[0] = g_GameServerAddress.ip[0];
      b_02.ip[1] = g_GameServerAddress.ip[1];
      b_02.ip[2] = g_GameServerAddress.ip[2];
      b_02.ip[3] = g_GameServerAddress.ip[3];
      b_02.type = g_GameServerAddress.type;
      b_02.ipx[0] = g_GameServerAddress.ipx[0];
      b_02.ipx[1] = g_GameServerAddress.ipx[1];
      b_02.ipx[2] = g_GameServerAddress.ipx[2];
      b_02.ipx[3] = g_GameServerAddress.ipx[3];
      b_02.ipx[4] = g_GameServerAddress.ipx[4];
      b_02.ipx[5] = g_GameServerAddress.ipx[5];
      b_02.ipx[6] = g_GameServerAddress.ipx[6];
      b_02.ipx[7] = g_GameServerAddress.ipx[7];
      b_02.ipx[8] = g_GameServerAddress.ipx[8];
      b_02.ipx[9] = g_GameServerAddress.ipx[9];
      b_02.port = g_GameServerAddress.port;
      qVar6 = NET_CompareAdr(a_02,b_02);
      if (qVar6 == false) {
        a_05.ip[0] = local_86c[0];
        a_05.ip[1] = local_86c[1];
        a_05.ip[2] = local_86c[2];
        a_05.ip[3] = local_86c[3];
        a_05.type = local_870;
        a_05.ipx[0] = local_868[0];
        a_05.ipx[1] = local_868[1];
        a_05.ipx[2] = local_868[2];
        a_05.ipx[3] = local_868[3];
        a_05.ipx[4] = local_864[0];
        a_05.ipx[5] = local_864[1];
        a_05.ipx[6] = local_864[2];
        a_05.ipx[7] = local_864[3];
        a_05._16_4_ = local_864._4_4_;
        b_05.ip[0] = g_rconaddress.ip[0];
        b_05.ip[1] = g_rconaddress.ip[1];
        b_05.ip[2] = g_rconaddress.ip[2];
        b_05.ip[3] = g_rconaddress.ip[3];
        b_05.type = g_rconaddress.type;
        b_05.ipx[0] = g_rconaddress.ipx[0];
        b_05.ipx[1] = g_rconaddress.ipx[1];
        b_05.ipx[2] = g_rconaddress.ipx[2];
        b_05.ipx[3] = g_rconaddress.ipx[3];
        b_05.ipx[4] = g_rconaddress.ipx[4];
        b_05.ipx[5] = g_rconaddress.ipx[5];
        b_05.ipx[6] = g_rconaddress.ipx[6];
        b_05.ipx[7] = g_rconaddress.ipx[7];
        b_05.ipx[8] = g_rconaddress.ipx[8];
        b_05.ipx[9] = g_rconaddress.ipx[9];
        b_05.port = g_rconaddress.port;
        qVar6 = NET_CompareAdr(a_05,b_05);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (qVar6 == false) goto LAB_001482c0;
      }
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (cls.state == ca_connecting) {
        iVar4 = Cmd_Argc();
        if (iVar4 != 3) {
          iVar4 = Cmd_Argc();
          uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
          if (iVar4 != 5) goto LAB_001482c0;
        }
        pcVar3 = Cmd_Argv(1);
        cls.challenge = Q_atoi(pcVar3);
        pcVar3 = Cmd_Argv(2);
        iVar4 = Q_atoi(pcVar3);
        cls.authprotocol = (byte)iVar4;
        if (cls.authprotocol == 0xff) {
          cls.authprotocol = '\x02';
        }
        else if (cls.authprotocol == '\x03') {
                    /* Unresolved local var: char * pchGSSteamID@[???]
                       Unresolved local var: char * pchBSecure@[???] */
          iVar4 = Cmd_Argc();
          uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
          if (iVar4 == 5) {
            pcVar3 = Cmd_Argv(3);
            if (pcVar3 == (char *)0x0) {
              Con_Printf("STEAM keysize is bogus (1)\n");
              CL_Disconnect_f();
              uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
            }
            else {
              pcVar7 = Cmd_Argv(4);
              if (pcVar7 == (char *)0x0) {
                Con_Printf("STEAM keysize is bogus (2)\n");
                CL_Disconnect_f();
                uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
              }
              else {
                cls.isVAC2Secure = Q_atoi(pcVar7);
                cls.GameServerSteamID = strtoll(pcVar3,(char **)0x0,10);
                CL_SendConnectPacket();
                uVar1 = cls.GameServerSteamID;
              }
            }
          }
          goto LAB_001482c0;
        }
        CL_SendConnectPacket();
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      }
      goto LAB_001482c0;
    }
    if (bVar9 == 0x6c) {
      local_85c = net_from.type;
      local_858[0] = net_from.ip[0];
      local_858[1] = net_from.ip[1];
      local_858[2] = net_from.ip[2];
      local_858[3] = net_from.ip[3];
      local_854[0] = net_from.ipx[0];
      local_854[1] = net_from.ipx[1];
      local_854[2] = net_from.ipx[2];
      local_854[3] = net_from.ipx[3];
      local_850[0] = net_from.ipx[4];
      local_850[1] = net_from.ipx[5];
      local_850[2] = net_from.ipx[6];
      local_850[3] = net_from.ipx[7];
      local_850._4_4_ = net_from._16_4_;
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
      b_03.ip[0] = g_GameServerAddress.ip[0];
      b_03.ip[1] = g_GameServerAddress.ip[1];
      b_03.ip[2] = g_GameServerAddress.ip[2];
      b_03.ip[3] = g_GameServerAddress.ip[3];
      b_03.type = g_GameServerAddress.type;
      b_03.ipx[0] = g_GameServerAddress.ipx[0];
      b_03.ipx[1] = g_GameServerAddress.ipx[1];
      b_03.ipx[2] = g_GameServerAddress.ipx[2];
      b_03.ipx[3] = g_GameServerAddress.ipx[3];
      b_03.ipx[4] = g_GameServerAddress.ipx[4];
      b_03.ipx[5] = g_GameServerAddress.ipx[5];
      b_03.ipx[6] = g_GameServerAddress.ipx[6];
      b_03.ipx[7] = g_GameServerAddress.ipx[7];
      b_03.ipx[8] = g_GameServerAddress.ipx[8];
      b_03.ipx[9] = g_GameServerAddress.ipx[9];
      b_03.port = g_GameServerAddress.port;
      qVar6 = NET_CompareAdr(a_03,b_03);
      if (qVar6 == false) {
        a_06.ip[0] = local_858[0];
        a_06.ip[1] = local_858[1];
        a_06.ip[2] = local_858[2];
        a_06.ip[3] = local_858[3];
        a_06.type = local_85c;
        a_06.ipx[0] = local_854[0];
        a_06.ipx[1] = local_854[1];
        a_06.ipx[2] = local_854[2];
        a_06.ipx[3] = local_854[3];
        a_06.ipx[4] = local_850[0];
        a_06.ipx[5] = local_850[1];
        a_06.ipx[6] = local_850[2];
        a_06.ipx[7] = local_850[3];
        a_06._16_4_ = local_850._4_4_;
        b_06.ip[0] = g_rconaddress.ip[0];
        b_06.ip[1] = g_rconaddress.ip[1];
        b_06.ip[2] = g_rconaddress.ip[2];
        b_06.ip[3] = g_rconaddress.ip[3];
        b_06.type = g_rconaddress.type;
        b_06.ipx[0] = g_rconaddress.ipx[0];
        b_06.ipx[1] = g_rconaddress.ipx[1];
        b_06.ipx[2] = g_rconaddress.ipx[2];
        b_06.ipx[3] = g_rconaddress.ipx[3];
        b_06.ipx[4] = g_rconaddress.ipx[4];
        b_06.ipx[5] = g_rconaddress.ipx[5];
        b_06.ipx[6] = g_rconaddress.ipx[6];
        b_06.ipx[7] = g_rconaddress.ipx[7];
        b_06.ipx[8] = g_rconaddress.ipx[8];
        b_06.ipx[9] = g_rconaddress.ipx[9];
        b_06.port = g_rconaddress.port;
        qVar6 = NET_CompareAdr(a_06,b_06);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (qVar6 == false) goto LAB_001482c0;
      }
      MSG_BeginReading();
      MSG_ReadLong();
      MSG_ReadByte();
      pcVar3 = MSG_ReadString();
      Con_Printf("%s\n",pcVar3);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      goto LAB_001482c0;
    }
    if (bVar9 == 0x38) {
      local_848 = net_from.type;
      local_844[0] = net_from.ip[0];
      local_844[1] = net_from.ip[1];
      local_844[2] = net_from.ip[2];
      local_844[3] = net_from.ip[3];
      local_840[0] = net_from.ipx[0];
      local_840[1] = net_from.ipx[1];
      local_840[2] = net_from.ipx[2];
      local_840[3] = net_from.ipx[3];
      local_83c[0] = net_from.ipx[4];
      local_83c[1] = net_from.ipx[5];
      local_83c[2] = net_from.ipx[6];
      local_83c[3] = net_from.ipx[7];
      local_83c._4_4_ = net_from._16_4_;
      a_04.ip[0] = net_from.ip[0];
      a_04.ip[1] = net_from.ip[1];
      a_04.ip[2] = net_from.ip[2];
      a_04.ip[3] = net_from.ip[3];
      a_04.type = net_from.type;
      a_04.ipx[0] = net_from.ipx[0];
      a_04.ipx[1] = net_from.ipx[1];
      a_04.ipx[2] = net_from.ipx[2];
      a_04.ipx[3] = net_from.ipx[3];
      a_04.ipx[4] = net_from.ipx[4];
      a_04.ipx[5] = net_from.ipx[5];
      a_04.ipx[6] = net_from.ipx[6];
      a_04.ipx[7] = net_from.ipx[7];
      a_04.ipx[8] = net_from.ipx[8];
      a_04.ipx[9] = net_from.ipx[9];
      a_04.port = net_from.port;
      b_04.ip[0] = g_GameServerAddress.ip[0];
      b_04.ip[1] = g_GameServerAddress.ip[1];
      b_04.ip[2] = g_GameServerAddress.ip[2];
      b_04.ip[3] = g_GameServerAddress.ip[3];
      b_04.type = g_GameServerAddress.type;
      b_04.ipx[0] = g_GameServerAddress.ipx[0];
      b_04.ipx[1] = g_GameServerAddress.ipx[1];
      b_04.ipx[2] = g_GameServerAddress.ipx[2];
      b_04.ipx[3] = g_GameServerAddress.ipx[3];
      b_04.ipx[4] = g_GameServerAddress.ipx[4];
      b_04.ipx[5] = g_GameServerAddress.ipx[5];
      b_04.ipx[6] = g_GameServerAddress.ipx[6];
      b_04.ipx[7] = g_GameServerAddress.ipx[7];
      b_04.ipx[8] = g_GameServerAddress.ipx[8];
      b_04.ipx[9] = g_GameServerAddress.ipx[9];
      b_04.port = g_GameServerAddress.port;
      qVar6 = NET_CompareAdr(a_04,b_04);
      if (qVar6 == false) {
        a_10.ip[0] = local_844[0];
        a_10.ip[1] = local_844[1];
        a_10.ip[2] = local_844[2];
        a_10.ip[3] = local_844[3];
        a_10.type = local_848;
        a_10.ipx[0] = local_840[0];
        a_10.ipx[1] = local_840[1];
        a_10.ipx[2] = local_840[2];
        a_10.ipx[3] = local_840[3];
        a_10.ipx[4] = local_83c[0];
        a_10.ipx[5] = local_83c[1];
        a_10.ipx[6] = local_83c[2];
        a_10.ipx[7] = local_83c[3];
        a_10._16_4_ = local_83c._4_4_;
        b_10.ip[0] = g_rconaddress.ip[0];
        b_10.ip[1] = g_rconaddress.ip[1];
        b_10.ip[2] = g_rconaddress.ip[2];
        b_10.ip[3] = g_rconaddress.ip[3];
        b_10.type = g_rconaddress.type;
        b_10.ipx[0] = g_rconaddress.ipx[0];
        b_10.ipx[1] = g_rconaddress.ipx[1];
        b_10.ipx[2] = g_rconaddress.ipx[2];
        b_10.ipx[3] = g_rconaddress.ipx[3];
        b_10.ipx[4] = g_rconaddress.ipx[4];
        b_10.ipx[5] = g_rconaddress.ipx[5];
        b_10.ipx[6] = g_rconaddress.ipx[6];
        b_10.ipx[7] = g_rconaddress.ipx[7];
        b_10.ipx[8] = g_rconaddress.ipx[8];
        b_10.ipx[9] = g_rconaddress.ipx[9];
        b_10.port = g_rconaddress.port;
        qVar6 = NET_CompareAdr(a_10,b_10);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (qVar6 == false) goto LAB_001482c0;
      }
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (cls.state == ca_connecting) {
        pcVar3 = pcVar3 + 1;
        iVar4 = Q_strlen("BADPASSWORD");
        iVar4 = Q_strncasecmp(pcVar3,0x25da74,iVar4);
        if (iVar4 == 0) {
          iVar4 = Q_strlen("BADPASSWORD");
          pcVar3 = pcVar3 + iVar4;
        }
        Con_Printf("%s",pcVar3);
        COM_ExplainDisconnection(false,"#GameUI_ServerConnectionFailedBadPassword");
        Con_Printf("Invalid server password.\n");
        CL_Disconnect();
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      }
      goto LAB_001482c0;
    }
    if (bVar9 == 0x4c) {
      local_834 = net_from.type;
      local_830[0] = net_from.ip[0];
      local_830[1] = net_from.ip[1];
      local_830[2] = net_from.ip[2];
      local_830[3] = net_from.ip[3];
      local_82c[0] = net_from.ipx[0];
      local_82c[1] = net_from.ipx[1];
      local_82c[2] = net_from.ipx[2];
      local_82c[3] = net_from.ipx[3];
      local_828[0] = net_from.ipx[4];
      local_828[1] = net_from.ipx[5];
      local_828[2] = net_from.ipx[6];
      local_828[3] = net_from.ipx[7];
      local_828._4_4_ = net_from._16_4_;
      a_07.ip[0] = net_from.ip[0];
      a_07.ip[1] = net_from.ip[1];
      a_07.ip[2] = net_from.ip[2];
      a_07.ip[3] = net_from.ip[3];
      a_07.type = net_from.type;
      a_07.ipx[0] = net_from.ipx[0];
      a_07.ipx[1] = net_from.ipx[1];
      a_07.ipx[2] = net_from.ipx[2];
      a_07.ipx[3] = net_from.ipx[3];
      a_07.ipx[4] = net_from.ipx[4];
      a_07.ipx[5] = net_from.ipx[5];
      a_07.ipx[6] = net_from.ipx[6];
      a_07.ipx[7] = net_from.ipx[7];
      a_07.ipx[8] = net_from.ipx[8];
      a_07.ipx[9] = net_from.ipx[9];
      a_07.port = net_from.port;
      b_07.ip[0] = g_GameServerAddress.ip[0];
      b_07.ip[1] = g_GameServerAddress.ip[1];
      b_07.ip[2] = g_GameServerAddress.ip[2];
      b_07.ip[3] = g_GameServerAddress.ip[3];
      b_07.type = g_GameServerAddress.type;
      b_07.ipx[0] = g_GameServerAddress.ipx[0];
      b_07.ipx[1] = g_GameServerAddress.ipx[1];
      b_07.ipx[2] = g_GameServerAddress.ipx[2];
      b_07.ipx[3] = g_GameServerAddress.ipx[3];
      b_07.ipx[4] = g_GameServerAddress.ipx[4];
      b_07.ipx[5] = g_GameServerAddress.ipx[5];
      b_07.ipx[6] = g_GameServerAddress.ipx[6];
      b_07.ipx[7] = g_GameServerAddress.ipx[7];
      b_07.ipx[8] = g_GameServerAddress.ipx[8];
      b_07.ipx[9] = g_GameServerAddress.ipx[9];
      b_07.port = g_GameServerAddress.port;
      qVar6 = NET_CompareAdr(a_07,b_07);
      if (qVar6 == false) {
        a_11.ip[0] = local_830[0];
        a_11.ip[1] = local_830[1];
        a_11.ip[2] = local_830[2];
        a_11.ip[3] = local_830[3];
        a_11.type = local_834;
        a_11.ipx[0] = local_82c[0];
        a_11.ipx[1] = local_82c[1];
        a_11.ipx[2] = local_82c[2];
        a_11.ipx[3] = local_82c[3];
        a_11.ipx[4] = local_828[0];
        a_11.ipx[5] = local_828[1];
        a_11.ipx[6] = local_828[2];
        a_11.ipx[7] = local_828[3];
        a_11._16_4_ = local_828._4_4_;
        b_11.ip[0] = g_rconaddress.ip[0];
        b_11.ip[1] = g_rconaddress.ip[1];
        b_11.ip[2] = g_rconaddress.ip[2];
        b_11.ip[3] = g_rconaddress.ip[3];
        b_11.type = g_rconaddress.type;
        b_11.ipx[0] = g_rconaddress.ipx[0];
        b_11.ipx[1] = g_rconaddress.ipx[1];
        b_11.ipx[2] = g_rconaddress.ipx[2];
        b_11.ipx[3] = g_rconaddress.ipx[3];
        b_11.ipx[4] = g_rconaddress.ipx[4];
        b_11.ipx[5] = g_rconaddress.ipx[5];
        b_11.ipx[6] = g_rconaddress.ipx[6];
        b_11.ipx[7] = g_rconaddress.ipx[7];
        b_11.ipx[8] = g_rconaddress.ipx[8];
        b_11.ipx[9] = g_rconaddress.ipx[9];
        b_11.port = g_rconaddress.port;
        qVar6 = NET_CompareAdr(a_11,b_11);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (qVar6 == false) goto LAB_001482c0;
      }
                    /* Unresolved local var: char[260] szCommand@[???] */
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (cls.state == ca_connecting) {
        pcVar3 = pcVar3 + 1;
        pcVar7 = strchr(pcVar3,10);
        if ((pcVar7 == (char *)0x0) && (pcVar7 = strchr(pcVar3,0x3b), pcVar7 == (char *)0x0)) {
          __snprintf_chk(&local_820,0x104,1,0x104,&LAB_0026279a,pcVar3);
          Cbuf_AddText((char *)&local_820);
          Con_Printf("Redirecting connection to %s.\n",pcVar3);
          g_bRedirectedToProxy = 1;
          uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        }
        else {
          COM_ExplainDisconnection
                    (true,"Invalid command separator in redirect server name, disconnecting.\n");
          CL_Disconnect();
          uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        }
      }
      goto LAB_001482c0;
    }
    if (bVar9 == 0x39) {
      local_820.inuse = net_from.type;
      local_820.adr.type._0_1_ = net_from.ip[0];
      local_820.adr.type._1_1_ = net_from.ip[1];
      local_820.adr.type._2_1_ = net_from.ip[2];
      local_820.adr.type._3_1_ = net_from.ip[3];
      local_820.adr.ip[0] = net_from.ipx[0];
      local_820.adr.ip[1] = net_from.ipx[1];
      local_820.adr.ip[2] = net_from.ipx[2];
      local_820.adr.ip[3] = net_from.ipx[3];
      local_820.adr.ipx[0] = net_from.ipx[4];
      local_820.adr.ipx[1] = net_from.ipx[5];
      local_820.adr.ipx[2] = net_from.ipx[6];
      local_820.adr.ipx[3] = net_from.ipx[7];
      local_820.adr.ipx._4_4_ = net_from._16_4_;
      a_09.ip[0] = net_from.ip[0];
      a_09.ip[1] = net_from.ip[1];
      a_09.ip[2] = net_from.ip[2];
      a_09.ip[3] = net_from.ip[3];
      a_09.type = net_from.type;
      a_09.ipx[0] = net_from.ipx[0];
      a_09.ipx[1] = net_from.ipx[1];
      a_09.ipx[2] = net_from.ipx[2];
      a_09.ipx[3] = net_from.ipx[3];
      a_09.ipx[4] = net_from.ipx[4];
      a_09.ipx[5] = net_from.ipx[5];
      a_09.ipx[6] = net_from.ipx[6];
      a_09.ipx[7] = net_from.ipx[7];
      a_09.ipx[8] = net_from.ipx[8];
      a_09.ipx[9] = net_from.ipx[9];
      a_09.port = net_from.port;
      b_09.ip[0] = g_GameServerAddress.ip[0];
      b_09.ip[1] = g_GameServerAddress.ip[1];
      b_09.ip[2] = g_GameServerAddress.ip[2];
      b_09.ip[3] = g_GameServerAddress.ip[3];
      b_09.type = g_GameServerAddress.type;
      b_09.ipx[0] = g_GameServerAddress.ipx[0];
      b_09.ipx[1] = g_GameServerAddress.ipx[1];
      b_09.ipx[2] = g_GameServerAddress.ipx[2];
      b_09.ipx[3] = g_GameServerAddress.ipx[3];
      b_09.ipx[4] = g_GameServerAddress.ipx[4];
      b_09.ipx[5] = g_GameServerAddress.ipx[5];
      b_09.ipx[6] = g_GameServerAddress.ipx[6];
      b_09.ipx[7] = g_GameServerAddress.ipx[7];
      b_09.ipx[8] = g_GameServerAddress.ipx[8];
      b_09.ipx[9] = g_GameServerAddress.ipx[9];
      b_09.port = g_GameServerAddress.port;
      qVar6 = NET_CompareAdr(a_09,b_09);
      if (qVar6 == false) {
        a_12.ip[0] = (undefined1)local_820.adr.type;
        a_12.ip[1] = local_820.adr.type._1_1_;
        a_12.ip[2] = local_820.adr.type._2_1_;
        a_12.ip[3] = local_820.adr.type._3_1_;
        a_12.type = local_820.inuse;
        a_12.ipx[0] = local_820.adr.ip[0];
        a_12.ipx[1] = local_820.adr.ip[1];
        a_12.ipx[2] = local_820.adr.ip[2];
        a_12.ipx[3] = local_820.adr.ip[3];
        a_12.ipx[4] = local_820.adr.ipx[0];
        a_12.ipx[5] = local_820.adr.ipx[1];
        a_12.ipx[6] = local_820.adr.ipx[2];
        a_12.ipx[7] = local_820.adr.ipx[3];
        a_12._16_4_ = local_820.adr.ipx._4_4_;
        b_12.ip[0] = g_rconaddress.ip[0];
        b_12.ip[1] = g_rconaddress.ip[1];
        b_12.ip[2] = g_rconaddress.ip[2];
        b_12.ip[3] = g_rconaddress.ip[3];
        b_12.type = g_rconaddress.type;
        b_12.ipx[0] = g_rconaddress.ipx[0];
        b_12.ipx[1] = g_rconaddress.ipx[1];
        b_12.ipx[2] = g_rconaddress.ipx[2];
        b_12.ipx[3] = g_rconaddress.ipx[3];
        b_12.ipx[4] = g_rconaddress.ipx[4];
        b_12.ipx[5] = g_rconaddress.ipx[5];
        b_12.ipx[6] = g_rconaddress.ipx[6];
        b_12.ipx[7] = g_rconaddress.ipx[7];
        b_12.ipx[8] = g_rconaddress.ipx[8];
        b_12.ipx[9] = g_rconaddress.ipx[9];
        b_12.port = g_rconaddress.port;
        qVar6 = NET_CompareAdr(a_12,b_12);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (qVar6 == false) goto LAB_001482c0;
      }
      iVar4 = COM_CheckParm("-steam");
      if ((iVar4 != 0) ||
         (uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID),
         cls.state == ca_connecting)) {
        COM_ExplainDisconnection(true,pcVar3 + 1);
        CL_Disconnect();
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      }
      goto LAB_001482c0;
    }
    if (bVar9 == 0x49) {
                    /* Unresolved local var: server_cache_t server@[???]
                       Unresolved local var: int infoByte@[???] */
      psVar10 = &local_820;
      for (iVar4 = 0x112; iVar4 != 0; iVar4 = iVar4 + -1) {
        psVar10->inuse = 0;
        psVar10 = (server_cache_t *)((int)psVar10 + (uint)bVar11 * -8 + 4);
      }
      local_820.adr.type = net_from.type;
      local_820.adr.ip[0] = net_from.ip[0];
      local_820.adr.ip[1] = net_from.ip[1];
      local_820.adr.ip[2] = net_from.ip[2];
      local_820.adr.ip[3] = net_from.ip[3];
      local_820.adr.ipx[0] = net_from.ipx[0];
      local_820.adr.ipx[1] = net_from.ipx[1];
      local_820.adr.ipx[2] = net_from.ipx[2];
      local_820.adr.ipx[3] = net_from.ipx[3];
      local_820.adr.ipx[4] = net_from.ipx[4];
      local_820.adr.ipx[5] = net_from.ipx[5];
      local_820.adr.ipx[6] = net_from.ipx[6];
      local_820.adr.ipx[7] = net_from.ipx[7];
      local_820.adr.ipx[8] = net_from.ipx[8];
      local_820.adr.ipx[9] = net_from.ipx[9];
      local_820.adr.port = net_from.port;
      Q_strncpy_s(local_820.name,pcVar3 + 2,0x100);
      pcVar3 = MSG_ReadString();
      Q_strncpy_s(local_820.map,pcVar3,0x100);
      MSG_SkipString();
      pcVar3 = MSG_ReadString();
      Q_strncpy_s(local_820.desc,pcVar3,0x100);
      MSG_ReadShort();
      local_820.players = MSG_ReadByte();
      local_820.maxplayers = MSG_ReadByte();
      local_820.bots = MSG_ReadByte();
      iVar4 = MSG_ReadByte();
      local_820.type = (char)iVar4;
      iVar4 = MSG_ReadByte();
      local_820.os = (char)iVar4;
      iVar4 = MSG_ReadByte();
      local_820.is_private = (qboolean)(iVar4 != 0);
      iVar4 = MSG_ReadByte();
      local_820.is_vac = (qboolean)(iVar4 != 0);
      MSG_SkipString();
      uVar5 = MSG_ReadByte();
      if (msg_badread == false) {
        if ((uVar5 & 0x80) != 0) {
          uVar8 = MSG_ReadShort();
          uVar2 = Q_ntohs(uVar8 & 0xffff);
          local_820.adr.port = uVar2;
        }
        if ((uVar5 & 0x10) != 0) {
          MSG_ReadLong();
          MSG_ReadLong();
        }
        if ((uVar5 & 0x40) != 0) {
          local_820.spec_adr.type = net_from.type;
          local_820.spec_adr.ip[0] = net_from.ip[0];
          local_820.spec_adr.ip[1] = net_from.ip[1];
          local_820.spec_adr.ip[2] = net_from.ip[2];
          local_820.spec_adr.ip[3] = net_from.ip[3];
          local_820.spec_adr.ipx[0] = net_from.ipx[0];
          local_820.spec_adr.ipx[1] = net_from.ipx[1];
          local_820.spec_adr.ipx[2] = net_from.ipx[2];
          local_820.spec_adr.ipx[3] = net_from.ipx[3];
          local_820.spec_adr.ipx[4] = net_from.ipx[4];
          local_820.spec_adr.ipx[5] = net_from.ipx[5];
          local_820.spec_adr.ipx[6] = net_from.ipx[6];
          local_820.spec_adr.ipx[7] = net_from.ipx[7];
          local_820.spec_adr.ipx[8] = net_from.ipx[8];
          local_820.spec_adr.ipx[9] = net_from.ipx[9];
          local_820.spec_adr.port = net_from.port;
          uVar8 = MSG_ReadShort();
          uVar2 = Q_ntohs(uVar8 & 0xffff);
          local_820.spec_adr.port = uVar2;
          pcVar3 = MSG_ReadString();
          Q_strncpy_s(local_820.spec_name,pcVar3,0x100);
          local_820.has_spectator_address = 1;
        }
        if ((uVar5 & 0x20) != 0) {
          MSG_SkipString();
        }
        if ((uVar5 & 1) != 0) {
          MSG_ReadLong();
          MSG_ReadLong();
        }
      }
      CL_AddToServerCache(&local_820);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      goto LAB_001482c0;
    }
  }
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int valid@[???] */
  qVar6 = Host_IsServerActive();
  if ((qVar6 != false) && (qVar6 = Host_IsSinglePlayerGame(), qVar6 == false)) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int valid@[???] */
    Q_memset(&local_820,0,0x800);
    local_89c = 0x7fc;
    iVar4 = ClientDLL_ConnectionlessPacket(&net_from,pcVar3,(char *)&local_820.adr,&local_89c);
    if ((local_89c < 0x7fd) && (local_89c != 0)) {
      local_820.inuse = ~NA_UNUSED;
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
      NET_SendPacket(NS_CLIENT,local_89c + 4,&local_820,to);
    }
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    if (iVar4 != 0) goto LAB_001482c0;
  }
  Con_Printf("Unknown command:\n%c\n",(uint)bVar9);
  uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
LAB_001482c0:
  cls.GameServerSteamID._4_4_ = (undefined4)(uVar1 >> 0x20);
  cls.GameServerSteamID._0_4_ = (undefined4)uVar1;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
  cls.GameServerSteamID = uVar1;
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_CreateCustomizationList  @ 00156b50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CreateCustomizationList(void)

{
  int iVar1;
  int iVar2;
  qboolean qVar3;
  int iVar4;
  resource_t *pResource;
  
  iVar1 = cl.playernum;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: player_info_t * pPlayer@[???] */
  iVar2 = cl.num_resources;
  cl.players[cl.playernum].customdata.pNext = (customization_s *)0x0;
  if (iVar2 < 1) {
    return;
  }
  pResource = cl.resourcelist;
  iVar4 = 0;
  iVar2 = iVar1;
  do {
    qVar3 = COM_CreateCustomization
                      (&cl.players[iVar1].customdata,pResource,iVar2,0,(customization_t **)0x0,
                       (int *)0x0);
    if (qVar3 == false) {
      Con_DPrintf("Problem with client customization %i, ignoring...",iVar4);
      if (cl.num_resources <= iVar4 + 1) {
        return;
      }
    }
    else if (cl.num_resources <= iVar4 + 1) {
      return;
    }
    pResource = pResource + 1;
    iVar4 = iVar4 + 1;
    iVar2 = cl.playernum;
  } while( true );
}


// CL_CreateResourceList  @ 001447a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CreateResourceList(void)

{
  resource_s *pResource;
  byte bVar1;
  resource_t *prVar2;
  int iVar3;
  FileHandle_t file;
  uint uVar4;
  int in_GS_OFFSET;
  uchar local_134 [16];
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int nSize@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: uchar[16] rgucMD5_hash@[???]
                       Unresolved local var: resource_t * pNewResource@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  HPAK_FlushHostQueue();
  cl.num_resources = 0;
  builtin_strncpy(local_124,"tempdecal.wad",0xe);
  Q_memset(local_134,0,0x10);
  file = FS_OpenPathID(local_124,"rb","GAMECONFIG");
  if (file != (FileHandle_t)0x0) {
    uVar4 = FS_Size(file);
    MD5_Hash_File(local_134,local_124,0,0,(uint *)0x0);
    iVar3 = cl.num_resources;
    if (uVar4 != 0) {
                    /* Unresolved local var: resource_t * r@[???] */
      pResource = cl.resourcelist + cl.num_resources;
      if (0x4ff < cl.num_resources) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Too many resources on client.");
      }
      prVar2 = cl.resourcelist + cl.num_resources;
      cl.num_resources = cl.num_resources + 1;
      prVar2->type = t_decal;
      Q_strncpy(pResource->szFileName,local_124,0x3f);
      bVar1 = cl.resourcelist[iVar3].ucFlags;
      cl.resourcelist[iVar3].nIndex = 0;
      cl.resourcelist[iVar3].szFileName[0x3f] = '\0';
      cl.resourcelist[iVar3].nDownloadSize = uVar4;
      cl.resourcelist[iVar3].ucFlags = bVar1 | 4;
      Q_memcpy(cl.resourcelist[iVar3].rgucMD5_hash,local_134,0x10);
      HPAK_AddLump(false,"custom.hpk",pResource,(void *)0x0,file);
    }
    FS_Close(file);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_CreateResourceList  @ 001462c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CreateResourceList(void)

{
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int nSize@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: uchar[16] rgucMD5_hash@[???]
                       Unresolved local var: resource_t * pNewResource@[???] */
  if (cls.state == ca_dedicated) {
    return;
  }
  CL_CreateResourceList();
  return;
}


// CL_CreateResponse  @ 00145d20
void CL_CreateResponse(netadr_t *to,char *varname,char *value)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: char[1024] response@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (value == (char *)0x0) {
    __snprintf_chk(local_410,0x400,1,0x400,&LAB_00264e43,0xff,0xff,0xff,0xff,varname);
  }
  else {
    __snprintf_chk(local_410,0x400,1,0x400,0x264e30,0xff,0xff,0xff,0xff,varname,value);
  }
  iVar1 = Q_strlen(local_410);
  NET_SendPacket(NS_CLIENT,iVar1 + 1,local_410,*to);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_CreateVisibleEntity  @ 00166e40
int CL_CreateVisibleEntity(int type,cl_entity_s *ent)

{
  cl_entity_t **ppcVar1;
  int iVar2;
  
                    /* Unresolved local var: int iret@[???] */
  (*g_engdstAddrs.CL_CreateVisibleEntity)(&type,(cl_entity_s_conflict **)&ent);
  if (type == 3) {
    iVar2 = 0;
    if (cl_numbeamentities < 0x40) {
      ppcVar1 = cl_beamentities + cl_numbeamentities;
      cl_numbeamentities = cl_numbeamentities + 1;
      *ppcVar1 = ent;
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 0;
    if (cl_numvisedicts < 0x200) {
      ppcVar1 = cl_visedicts + cl_numvisedicts;
      cl_numvisedicts = cl_numvisedicts + 1;
      *ppcVar1 = ent;
      return 1;
    }
  }
  return iVar2;
}


// CL_DeallocateDynamicData  @ 00156a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DeallocateDynamicData(void)

{
  if (cl_entities != (cl_entity_t *)0x0) {
    Mem_Free(cl_entities);
    cl_entities = (cl_entity_t *)0x0;
    R_DestroyObjects();
    return;
  }
  R_DestroyObjects();
  return;
}


// CL_DecayLights  @ 00149ca0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DecayLights(void)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  dlight_t *pdVar5;
  dlight_t *pdVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  longdouble lVar11;
  longdouble lVar12;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * dl@[???]
                       Unresolved local var: float time@[???] */
  if (cls.signon != 2) {
    return;
  }
  bVar7 = 0;
  uVar10 = 0;
  uVar8 = 0;
  lVar11 = (longdouble)cl.time;
  lVar12 = (longdouble)cl.oldtime;
  r_dlightchanged = 0;
  pdVar5 = cl_dlights;
  r_dlightactive = 0;
  bVar3 = false;
  bVar4 = false;
  do {
    while (*(float *)(((lightstyle_t *)pdVar5)->map + 8) == 0.0) {
LAB_00149d12:
      pdVar5 = (dlight_t *)(((lightstyle_t *)pdVar5)->map + 0x24);
      bVar7 = bVar7 + 1;
      if ((lightstyle_t *)pdVar5 == cl_lightstyle) goto LAB_00149d68;
    }
    if ((longdouble)*(float *)(((lightstyle_t *)pdVar5)->map + 0x10) < lVar11) {
      uVar8 = uVar8 | 1 << (bVar7 & 0x1f);
      bVar3 = true;
      ((lightstyle_t *)pdVar5)->map[8] = '\0';
      ((lightstyle_t *)pdVar5)->map[9] = '\0';
      ((lightstyle_t *)pdVar5)->map[10] = '\0';
      ((lightstyle_t *)pdVar5)->map[0xb] = '\0';
      goto LAB_00149d12;
    }
    if (*(float *)(((lightstyle_t *)pdVar5)->map + 0x14) != 0.0) {
      uVar9 = 1 << (bVar7 & 0x1f);
      uVar8 = uVar8 | uVar9;
      fVar1 = *(float *)(((lightstyle_t *)pdVar5)->map + 8) -
              *(float *)(((lightstyle_t *)pdVar5)->map + 0x14) * (float)(lVar11 - lVar12);
      *(float *)(((lightstyle_t *)pdVar5)->map + 8) = fVar1;
      if (fVar1 < 0.0) {
        ((lightstyle_t *)pdVar5)->map[8] = '\0';
        ((lightstyle_t *)pdVar5)->map[9] = '\0';
        ((lightstyle_t *)pdVar5)->map[10] = '\0';
        ((lightstyle_t *)pdVar5)->map[0xb] = '\0';
        bVar3 = true;
      }
      else {
        bVar3 = true;
        if (fVar1 != 0.0) goto LAB_00149d56;
      }
      goto LAB_00149d12;
    }
    uVar9 = 1 << (bVar7 & 0x1f);
LAB_00149d56:
    pdVar5 = (dlight_t *)(((lightstyle_t *)pdVar5)->map + 0x24);
    uVar10 = uVar10 | uVar9;
    bVar7 = bVar7 + 1;
    bVar4 = true;
  } while ((lightstyle_t *)pdVar5 != cl_lightstyle);
LAB_00149d68:
  if (bVar3) {
    r_dlightchanged = uVar8;
  }
  if (bVar4) {
    r_dlightactive = uVar10;
  }
  pdVar5 = cl_elights;
  do {
    while (pdVar5->radius == 0.0) {
LAB_00149d9a:
      pdVar5 = pdVar5 + 1;
      if (pdVar5 == (dlight_t *)&cl_playerindex) {
        return;
      }
    }
    if ((longdouble)pdVar5->die < lVar11) {
      pdVar5->radius = 0.0;
      goto LAB_00149d9a;
    }
    fVar1 = pdVar5->radius - pdVar5->decay * (float)(lVar11 - lVar12);
    fVar2 = 0.0;
    if (0.0 <= fVar1) {
      fVar2 = fVar1;
    }
    pdVar6 = pdVar5 + 1;
    pdVar5->radius = fVar2;
    pdVar5 = pdVar6;
    if (pdVar6 == (dlight_t *)&cl_playerindex) {
      return;
    }
  } while( true );
}


// CL_DemoAPIPlayback  @ 0013db60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_DemoAPIPlayback(void)

{
                    /* catch() { ... } // from try @ 0013ded5 with catch @ 0013db60 */
  return (uint)(cls.demoplayback != false);
}


// CL_DemoAPIRecording  @ 0013db50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_DemoAPIRecording(void)

{
  return (uint)(cls.demorecording != false);
}


// CL_DemoAPITimedemo  @ 0013db70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_DemoAPITimedemo(void)

{
  return (uint)(cls.timedemo != false);
}


// CL_DemoAnim  @ 00140bd0
void CL_DemoAnim(int anim,int body)

{
  longdouble lVar1;
  undefined1 local_1d;
  float local_1c;
  int32 local_18;
  int32 local_14;
  int32 local_10;
  
                    /* Unresolved local var: demo_anim_t demcmd@[???] */
  if (cls.demofile != (FileHandle_t)0x0) {
    local_1d = 7;
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_1c = (float)lVar1;
    local_18 = (*LittleLong)(host_framecount - cls.demostartframe);
    local_14 = (*LittleLong)(anim);
    local_10 = (*LittleLong)(body);
    FS_Write(&local_1d,0x11,1,cls.demofile);
  }
  return;
}


// CL_DemoCopyFileChunk  @ 0013dd20
void CL_DemoCopyFileChunk(FILE *dst,FILE *src,int nSize)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined1 local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: int copysize@[???]
                       Unresolved local var: char[1024] copybuf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* try { // try from 0013dd49 to 0014dd4d has its CatchHandler @ 0013deda */
  if (0x400 < nSize) {
    iVar1 = nSize;
    do {
      iVar1 = iVar1 + -0x400;
      FS_Read(local_420,0x400,1,src);
      FS_Write(local_420,0x400,1,dst);
    } while (0x400 < iVar1);
    nSize = (nSize + -0x400) - (nSize - 0x401U & 0xfffffc00);
  }
  FS_Read(local_420,nSize,1,src);
  FS_Write(local_420,nSize,1,dst);
  FS_Flush(src);
  FS_Flush(dst);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_DemoEvent  @ 001411f0
void CL_DemoEvent(int flags,int idx,float delay,event_args_t *pargs)

{
  longdouble lVar1;
  undefined1 local_21;
  float local_20;
  int32 local_1c;
  int32 local_18;
  int32 local_14;
  float local_10;
  
                    /* Unresolved local var: demo_event_t demcmd@[???] */
  if (cls.demofile != (FileHandle_t)0x0) {
    local_21 = 6;
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_20 = (float)lVar1;
    local_1c = (*LittleLong)(host_framecount - cls.demostartframe);
    local_18 = (*LittleLong)(flags);
    local_14 = (*LittleLong)(idx);
    lVar1 = (longdouble)(*LittleFloat)(delay);
    local_10 = (float)lVar1;
    FS_Write(&local_21,0x15,1,cls.demofile);
    FS_Write(pargs,0x48,1,cls.demofile);
  }
  return;
}


// CL_DemoFrameInfo  @ 00140810
void CL_DemoFrameInfo(demo_info_t *rp,float time)

{
  demo_info_t *src;
  undefined4 uVar1;
  uint uVar2;
  demo_info_t *dest;
  uint uVar3;
  
                    /* Unresolved local var: int i@[???] */
  dest = dem_frames + 0x1f;
  do {
    src = dest + -1;
    Q_memcpy(dest,src,0x1b4);
    dest = src;
  } while (src != dem_frames);
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    uVar1 = *(undefined4 *)((int)(rp->rp).vieworg + uVar3);
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + (uVar3 - 4)) =
         *(undefined4 *)((int)(rp->rp).vieworg + (uVar3 - 4));
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar3) = uVar1;
    uVar2 = uVar3 + 8;
  } while (uVar3 + 8 < 0x1b0);
  *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar3 + 4) =
       *(undefined4 *)((int)(rp->rp).vieworg + uVar3 + 4);
  dem_frames[0].rp.cmd = &dem_frames[0].cmd;
  dem_frames[0].rp.movevars = &dem_frames[0].movevars;
  dem_frames[0].timestamp = time;
  return;
}


// CL_DemoInTime  @ 0013dce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float CL_DemoInTime(void)

{
  return g_demotimescale * (float)realtime;
}


// CL_DemoOutTime  @ 0013dcc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float CL_DemoOutTime(void)

{
  return (float)realtime;
}


// CL_DemoParseAnim  @ 001413d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DemoParseAnim(void)

{
  int32 iAnim;
  int32 local_10 [2];
  
                    /* Unresolved local var: int anim@[???]
                       Unresolved local var: int body@[???]
                       Unresolved local var: int i@[???] */
  FS_Read(local_10,4,1,cls.demofile);
  iAnim = (*LittleLong)(local_10[0]);
  local_10[0] = iAnim;
  FS_Read(local_10,4,1,cls.demofile);
  local_10[0] = (*LittleLong)(local_10[0]);
  hudWeaponAnim(iAnim,local_10[0]);
  return;
}


// CL_DemoParseEvent  @ 001412d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DemoParseEvent(void)

{
  int32 flags;
  int32 index;
  longdouble lVar1;
  float local_5c;
  int32 local_58;
  event_args_t local_54;
  
                    /* Unresolved local var: int flags@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: float delay@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: int i@[???] */
  FS_Read(&local_58,4,1,cls.demofile);
  flags = (*LittleLong)(local_58);
  local_58 = flags;
  FS_Read(&local_58,4,1,cls.demofile);
  index = (*LittleLong)(local_58);
  local_58 = index;
  FS_Read(&local_5c,4,1,cls.demofile);
  lVar1 = (longdouble)(*LittleFloat)(local_5c);
  local_5c = (float)lVar1;
  FS_Read(&local_54,0x48,1,cls.demofile);
  CL_QueueEvent(flags,index,(float)lVar1,&local_54);
  return;
}


// CL_DemoParseSound  @ 00140f30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DemoParseSound(void)

{
  int32 entchannel;
  uint flags;
  int32 pitch;
  int iVar1;
  sfx_t *sfxin;
  int in_GS_OFFSET;
  longdouble lVar2;
  longdouble lVar3;
  float fStack_170;
  uint uStack_16c;
  sfx_t sStack_168;
  char acStack_120 [256];
  int local_20;
  
                    /* Unresolved local var: int channel@[???]
                       Unresolved local var: char[256] sample@[???]
                       Unresolved local var: float volume@[???]
                       Unresolved local var: float attenuation@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  FS_Read(&uStack_16c,4,1,cls.demofile);
  entchannel = (*LittleLong)(uStack_16c);
  FS_Read(&uStack_16c,4,1,cls.demofile);
  uStack_16c = (*LittleLong)(uStack_16c);
  if (0xff < uStack_16c) {
    uStack_16c = 0xff;
  }
  FS_Read(acStack_120,uStack_16c,1,cls.demofile);
  acStack_120[uStack_16c] = '\0';
  FS_Read(&fStack_170,4,1,cls.demofile);
  lVar2 = (longdouble)(*LittleFloat)(fStack_170);
  FS_Read(&fStack_170,4,1,cls.demofile);
  lVar3 = (longdouble)(*LittleFloat)(fStack_170);
  FS_Read(&uStack_16c,4,1,cls.demofile);
  flags = (*LittleLong)(uStack_16c);
  FS_Read(&uStack_16c,4,1,cls.demofile);
  pitch = (*LittleLong)(uStack_16c);
  if ((flags & 0x10) == 0) {
    sfxin = CL_LookupSound(acStack_120);
    if (sfxin == (sfx_s *)0x0) goto LAB_00141167;
  }
  else {
    iVar1 = Q_atoi(acStack_120 + 1);
    sfxin = &sStack_168;
    __snprintf_chk(sfxin,0x40,1,0x40,&DAT_00263ab4,rgpszrawsentence[iVar1]);
  }
  if (entchannel == 6) {
    S_StartStaticSound(cl.playernum + 1,6,sfxin,cl.simorg,(float)lVar3,(float)lVar2,flags,pitch);
  }
  else {
    S_StartDynamicSound(cl.playernum + 1,entchannel,sfxin,cl.simorg,(float)lVar3,(float)lVar2,flags,
                        pitch);
  }
LAB_00141167:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_DemoPlaySound  @ 00140dc0
void CL_DemoPlaySound(int channel,char *sample,float attenuation,float volume,int flags,int pitch)

{
  int iVar1;
  sfx_t *sfxin;
  int in_GS_OFFSET;
  sfx_t local_58;
  int local_10;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((flags & 0x10U) == 0) {
    sfxin = CL_LookupSound(sample);
    if (sfxin == (sfx_s *)0x0) goto LAB_00140e98;
  }
  else {
    sfxin = &local_58;
    iVar1 = Q_atoi(sample + 1);
    __snprintf_chk(sfxin,0x40,1,0x40,&DAT_00263ab4,rgpszrawsentence[iVar1]);
  }
  if (channel == 6) {
    S_StartStaticSound(cl.playernum + 1,6,sfxin,cl.simorg,volume,attenuation,flags,pitch);
  }
  else {
    S_StartDynamicSound(cl.playernum + 1,channel,sfxin,cl.simorg,volume,attenuation,flags,pitch);
  }
LAB_00140e98:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_DemoQueueSound  @ 00140c70
void CL_DemoQueueSound(int channel,char *sample,float volume,float attenuation,int flags,int pitch)

{
  _func_int32_int32 *p_Var1;
  FileHandle_t file;
  int iVar2;
  longdouble lVar3;
  float local_2d;
  float local_29;
  int32 local_25;
  int32 local_21;
  undefined1 local_1d;
  float local_1c;
  int32 local_18;
  int32 local_14;
  int32 local_10;
  
                    /* Unresolved local var: demo_sound1_s demcmd1@[???]
                       Unresolved local var: demo_sound2_s demcmd2@[???] */
  if (cls.demofile != (FileHandle_t)0x0) {
    local_1d = 8;
    lVar3 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_1c = (float)lVar3;
    local_18 = (*LittleLong)(host_framecount - cls.demostartframe);
    local_14 = (*LittleLong)(channel);
    p_Var1 = LittleLong;
    iVar2 = Q_strlen(sample);
    local_10 = (*p_Var1)(iVar2);
    FS_Write(&local_1d,0x11,1,cls.demofile);
    file = cls.demofile;
    iVar2 = Q_strlen(sample);
    FS_Write(sample,iVar2,1,file);
    lVar3 = (longdouble)(*LittleFloat)(volume);
    local_2d = (float)lVar3;
    lVar3 = (longdouble)(*LittleFloat)(attenuation);
    local_29 = (float)lVar3;
    local_25 = (*LittleLong)(flags);
    local_21 = (*LittleLong)(pitch);
    FS_Write(&local_2d,0x10,1,cls.demofile);
  }
  return;
}


// CL_DemoReadCmdInfo  @ 001408a0
void CL_DemoReadCmdInfo(float time)

{
  demo_info_t *src;
  undefined4 uVar1;
  uint uVar2;
  demo_info_t *dest;
  uint uVar3;
  int in_GS_OFFSET;
  vec_t local_1c4 [108];
  int local_14;
  int local_10;
  
                    /* Unresolved local var: demo_info_t rp@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  FS_Read(local_1c4,0x1b4,1,cls.demofile);
  uVar3 = 0;
  do {
    uVar2 = uVar3 + 4;
    *(undefined4 *)((int)g_rp.cmd.viewangles + (uVar3 - 4)) =
         *(undefined4 *)((int)local_1c4 + uVar3 + 0xec);
    uVar3 = uVar2;
  } while (uVar2 < 0x34);
  uVar3 = 0;
  do {
    uVar2 = uVar3;
    uVar1 = *(undefined4 *)((int)local_1c4 + uVar2 + 0x124);
    *(undefined4 *)(g_rp.movevars.skyName + (uVar2 - 0x44)) =
         *(undefined4 *)((int)local_1c4 + uVar2 + 0x120);
    *(undefined4 *)(g_rp.movevars.skyName + (uVar2 - 0x40)) = uVar1;
    uVar3 = uVar2 + 8;
  } while (uVar2 + 8 < 0x80);
  *(undefined4 *)(g_rp.movevars.skyName + (uVar2 - 0x3c)) =
       *(undefined4 *)((int)local_1c4 + uVar2 + 0x128);
  g_rp.view[0] = local_1c4[0x69];
  g_rp.view[1] = local_1c4[0x6a];
  g_rp.view[2] = local_1c4[0x6b];
  g_rp.viewmodel = local_14;
  dest = dem_frames + 0x1f;
  do {
    src = dest + -1;
                    /* Unresolved local var: int i@[???] */
    Q_memcpy(dest,src,0x1b4);
    dest = src;
  } while (src != dem_frames);
  uVar3 = 0;
  do {
    uVar2 = uVar3;
    uVar1 = *(undefined4 *)((int)local_1c4 + uVar2 + 4);
    uVar3 = uVar2 + 8;
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + (uVar2 - 4)) =
         *(undefined4 *)((int)local_1c4 + uVar2);
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar2) = uVar1;
  } while (uVar3 < 0x1b0);
  *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar2 + 4) =
       *(undefined4 *)((int)local_1c4 + uVar3);
  dem_frames[0].rp.cmd = &dem_frames[0].cmd;
  dem_frames[0].rp.movevars = &dem_frames[0].movevars;
  dem_frames[0].timestamp = time;
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_DemoSectionStart  @ 001403b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DemoSectionStart(void)

{
  uint uVar1;
  int in_GS_OFFSET;
  char local_90 [128];
  int local_10;
  
                    /* Unresolved local var: char[128] szCommand@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pCurrentEntry != (demoentry_t *)0x0) {
    uVar1 = pCurrentEntry->nFlags;
    if ((uVar1 & 4) != 0) {
      __snprintf_chk(local_90,0x80,1,0x80,&LAB_0026496f,pCurrentEntry->nCDTrack);
      Cbuf_AddText(local_90);
      uVar1 = pCurrentEntry->nFlags;
    }
    if ((uVar1 & 0x10) != 0) {
      sf_demo.duration = 0x800;
      sf_demo.holdTime = 0;
      sf_demo.fadeFlags = 0;
      sf_demo.r = '\0';
      sf_demo.g = '\0';
      sf_demo.b = '\0';
      sf_demo.a = 0xff;
      V_ScreenFade((char *)0x0,0,&sf_demo);
      uVar1 = pCurrentEntry->nFlags;
    }
    if ((uVar1 & 8) != 0) {
      sf_demo.duration = 0x2000;
      sf_demo.holdTime = 0;
      sf_demo.r = '\0';
      sf_demo.g = '\0';
      sf_demo.b = '\0';
      sf_demo.a = 0xff;
      sf_demo.fadeFlags = 0;
      V_ScreenFade((char *)0x0,0,&sf_demo);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_DemoWriteCmdInfo  @ 001407e0
void CL_DemoWriteCmdInfo(FileHandle_t fp)

{
  FS_Write(&g_rp,0x1b4,1,fp);
  return;
}


// CL_DemoWriteSequenceInfo  @ 001405e0
void CL_DemoWriteSequenceInfo(FileHandle_t fp,int length)

{
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int32 local_10;
  
                    /* Unresolved local var: sequence_info_t si@[???] */
  local_2c = cls.netchan.incoming_sequence;
  local_28 = cls.netchan.incoming_acknowledged;
  local_24 = cls.netchan.incoming_reliable_acknowledged;
  local_20 = cls.netchan.incoming_reliable_sequence;
  local_1c = cls.netchan.outgoing_sequence;
  local_18 = cls.netchan.reliable_sequence;
  local_14 = cls.netchan.last_reliable_sequence;
  local_10 = (*LittleLong)(length);
  FS_Write(&local_2c,0x20,1,fp);
  return;
}


// CL_DescribeEvent  @ 00138ec0
void CL_DescribeEvent(int slot,char *eventname)

{
                    /* Unresolved local var: int idx@[???] */
  if ((cl_showevents.value != 0.0) && (eventname != (char *)0x0)) {
    Con_NPrintf(slot & 0x1f,"%i %f %s",slot,cl.time,eventname);
    return;
  }
  return;
}


// CL_Disconnect  @ 00146560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Disconnect(void)

{
  int iVar1;
  netadr_t addr;
  netadr_t addr_00;
  qboolean qVar2;
  int iVar3;
  int in_GS_OFFSET;
  byte local_24;
  char local_23 [19];
  int local_10;
  
                    /* Unresolved local var: byte[20] final@[???]
                       Unresolved local var: uint unIP@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  cls.connect_time._0_4_ = 0;
  cls.connect_time._4_4_ = 0xc0f869f0;
  cls.connect_retry = 0;
  g_careerState = CAREER_NONE;
  SetCareerAudioState(0);
  SPR_Shutdown_NoModelFree();
  S_StopAllSounds(true);
  if (cls.demoplayback == false) {
    if (cls.state - ca_connecting < 4) {
      if (cls.demorecording != false) {
        CL_Stop_f();
      }
      FS_LogLevelLoadStarted("ExitGame");
      if (cls.passive == false) {
        if (cls.netchan.remote_address.type != NA_UNUSED) {
          local_24 = '\x03';
          Q_strcpy(local_23,"dropclient\n");
          Netchan_Transmit(&cls.netchan,0xd,&local_24);
          Netchan_Transmit(&cls.netchan,0xd,&local_24);
          Netchan_Transmit(&cls.netchan,0xd,&local_24);
        }
      }
      else {
        addr.ip[0] = cls.connect_stream.ip[0];
        addr.ip[1] = cls.connect_stream.ip[1];
        addr.ip[2] = cls.connect_stream.ip[2];
        addr.ip[3] = cls.connect_stream.ip[3];
        addr.type = cls.connect_stream.type;
        addr.ipx[0] = cls.connect_stream.ipx[0];
        addr.ipx[1] = cls.connect_stream.ipx[1];
        addr.ipx[2] = cls.connect_stream.ipx[2];
        addr.ipx[3] = cls.connect_stream.ipx[3];
        addr.ipx[4] = cls.connect_stream.ipx[4];
        addr.ipx[5] = cls.connect_stream.ipx[5];
        addr.ipx[6] = cls.connect_stream.ipx[6];
        addr.ipx[7] = cls.connect_stream.ipx[7];
        addr.ipx[8] = cls.connect_stream.ipx[8];
        addr.ipx[9] = cls.connect_stream.ipx[9];
        addr.port = cls.connect_stream.port;
        NET_LeaveGroup(cls.netchan.sock,addr);
        addr_00.ip[0] = cls.game_stream.ip[0];
        addr_00.ip[1] = cls.game_stream.ip[1];
        addr_00.ip[2] = cls.game_stream.ip[2];
        addr_00.ip[3] = cls.game_stream.ip[3];
        addr_00.type = cls.game_stream.type;
        addr_00.ipx[0] = cls.game_stream.ipx[0];
        addr_00.ipx[1] = cls.game_stream.ipx[1];
        addr_00.ipx[2] = cls.game_stream.ipx[2];
        addr_00.ipx[3] = cls.game_stream.ipx[3];
        addr_00.ipx[4] = cls.game_stream.ipx[4];
        addr_00.ipx[5] = cls.game_stream.ipx[5];
        addr_00.ipx[6] = cls.game_stream.ipx[6];
        addr_00.ipx[7] = cls.game_stream.ipx[7];
        addr_00.ipx[8] = cls.game_stream.ipx[8];
        addr_00.ipx[9] = cls.game_stream.ipx[9];
        addr_00.port = cls.game_stream.port;
        NET_LeaveGroup(cls.netchan.sock,addr_00);
      }
      cls.state = ca_disconnected;
      Steam_GSTerminateGameConnection();
      Q_memset(&g_GameServerAddress,0,0x14);
      qVar2 = Host_IsServerActive();
      if (qVar2 != false) {
        Host_ShutdownServer(false);
      }
      CloseSecurityModule();
    }
  }
  else {
    CL_StopPlayback();
  }
  cls.timedemo = false;
  cls.demoplayback = false;
  cls.signon = 0;
                    /* Unresolved local var: int i@[???] */
  qVar2 = Host_IsServerActive();
  if (qVar2 == false) {
    Host_ClearMemory(true);
  }
  CL_ClearClientState();
  SZ_Clear(&cls.netchan.message);
  Q_memset(cl_efrags,0,0x2800);
  Q_memset(cl_dlights,0,0x500);
  Q_memset(cl_elights,0,0xa00);
  Q_memset(cl_lightstyle,0,0x1100);
  CL_TempEntInit();
  cl.free_efrags = cl_efrags;
  iVar3 = 0;
  do {
    iVar1 = iVar3 + 0x10;
    *(int *)((int)&(cl.free_efrags)->entnext + iVar3) = (int)&cl.free_efrags[1].leaf + iVar3;
    iVar3 = iVar1;
  } while (iVar1 != 0x27f0);
  cl.free_efrags[0x27f].entnext = (efrag_s *)0x0;
  NET_CheckCleanupFakeIPConnection
            (cls.netchan.sock,(netadr_t_conflict *)&cls.netchan.remote_address);
  Netchan_Clear(&cls.netchan);
  CL_DeallocateDynamicData();
  scr_downloading.value = -1.0;
  sys_timescale.value = 1.0;
  g_LastScreenUpdateTime = 0.0;
  qVar2 = Host_IsServerActive();
  if (qVar2 == false) {
    Cvar_DirectSet(&sv_allow_autoaim,"0");
    Cvar_DirectSet(&sv_allow_shaders,"0");
  }
  VGuiWrap2_NotifyOfServerDisconnect();
  StopLoadingProgressBar();
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_Disconnect_f  @ 00147430
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Disconnect_f(void)

{
  qboolean qVar1;
  
  CL_Disconnect();
  qVar1 = Host_IsServerActive();
  if (qVar1 != false) {
    Host_ShutdownServer(false);
  }
  return;
}


// CL_DriftInterpolationAmount  @ 00149f20
int CL_DriftInterpolationAmount(int goal)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: int msec@[???]
                       Unresolved local var: float fgoal@[???] */
  if ((float)goal / 1000.0 != g_flInterpolationAmount) {
                    /* Unresolved local var: float maxmove@[???]
                       Unresolved local var: float diff@[???] */
    fVar2 = (float)host_frametime * 0.05;
    fVar1 = (float)goal / 1000.0 - g_flInterpolationAmount;
    if (fVar1 <= 0.0) {
      if (fVar2 < -fVar1) {
        fVar1 = -fVar2;
      }
    }
    else if (fVar2 < fVar1) {
      fVar1 = fVar2;
    }
    g_flInterpolationAmount = fVar1 + g_flInterpolationAmount;
  }
  iVar3 = (int)(g_flInterpolationAmount * 1000.0);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (100 < iVar3) {
    iVar3 = 100;
  }
  return iVar3;
}


// CL_DumpMessageLoad_f  @ 00157eb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DumpMessageLoad_f(void)

{
  char *pcVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int total@[???] */
  iVar4 = 0;
  ppcVar3 = &cl_parsefuncs[0].pszname;
  iVar2 = 0;
  Con_Printf("-------- Message Load ---------\n");
  do {
    if (msg_buckets[iVar2] != 0) {
      if (iVar2 < 0x3c) {
        pcVar1 = *ppcVar3;
      }
      else {
        pcVar1 = "bogus #";
      }
      Con_Printf("%i:%s: %i msgs:%.2fK\n",iVar2,pcVar1,msg_buckets[iVar2],
                 (double)total_data[iVar2] * 0.0009765625);
      iVar4 = iVar4 + msg_buckets[iVar2];
    }
    iVar2 = iVar2 + 1;
    ppcVar3 = ppcVar3 + 3;
  } while (iVar2 != 0x3f);
  Con_Printf("User messages:  %i:%.2fK\n",msg_buckets[0x3f],
             (double)((float)total_data[0x3f] * 0.0009765625));
  Con_Printf("------ End:  %i Total----\n",iVar4 + msg_buckets[0x3f]);
  return;
}


// CL_EmitEntities  @ 00136b10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_EmitEntities(void)

{
  cl_entity_t **ppcVar1;
  float fVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  cl_entity_t *pcVar5;
  qboolean qVar6;
  cl_entity_t **ppcVar7;
  mleaf_t *leaf;
  byte *ppvs;
  longdouble lVar8;
  longdouble lVar9;
  
                    /* Unresolved local var: mleaf_t * pleaf@[???]
                       Unresolved local var: byte * ppvs@[???] */
  qVar6 = cls.spectator;
  cl_numvisedicts = 0;
  cl_numbeamentities = 0;
                    /* catch() { ... } // from try @ 00136c0d with catch @ 00136b30
                       catch() { ... } // from try @ 00136e63 with catch @ 00136b30 */
  if (((cls.state == ca_active) && (cl.validsequence != 0)) &&
     (cl.frames[cl.parsecountmod].invalid == false)) {
                    /* Unresolved local var: double f@[???]
                       Unresolved local var: double frac@[???] */
    lVar8 = (longdouble)cl.mtime[0];
    if ((lVar8 - (longdouble)cl.mtime[1] == (longdouble)0) || (cls.timedemo != false)) {
                    /* Unresolved local var: float fgap@[???] */
      lVar9 = (longdouble)cl.time;
      cl.time = cl.mtime[0];
      if (cls.demoplayback == false) {
        fVar2 = 1.0;
      }
      else {
                    /* try { // try from 00136c9d to 00146e3c has its CatchHandler @ 00136e47 */
        cl.oldtime = (double)(lVar8 - (longdouble)(float)(lVar9 - (longdouble)cl.oldtime));
        fVar2 = 1.0;
      }
    }
    else if ((longdouble)ex_interp.value <= (longdouble)0.001) {
      fVar2 = 1.0;
    }
    else {
      fVar2 = (float)(((longdouble)cl.time - lVar8) / (longdouble)ex_interp.value);
    }
    cl.commands[cls.netchan.outgoing_sequence - 1U & CL_UPDATE_MASK].frame_lerp = fVar2;
    if (qVar6 != false) {
      leaf = Mod_PointInLeaf(cl.simorg,cl.worldmodel);
      ppvs = Mod_LeafPVS(leaf,cl.worldmodel);
      PVSMark(cl.worldmodel,ppvs);
    }
    CL_LinkPlayers();
    CL_LinkPacketEntities();
    pcVar5 = cl_entities;
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: int i@[???] */
    if (0 < cl_numvisedicts) {
      ppcVar7 = cl_visedicts;
      ppcVar1 = cl_visedicts + cl_numvisedicts;
      do {
        pcVar3 = *ppcVar7;
        iVar4 = (pcVar3->curstate).aiment;
        if ((iVar4 != 0) && ((pcVar3->curstate).movetype == 0xc)) {
          pcVar3->origin[0] = pcVar5[iVar4].origin[0];
          pcVar3->origin[1] = pcVar5[iVar4].origin[1];
          pcVar3->origin[2] = pcVar5[iVar4].origin[2];
        }
        ppcVar7 = ppcVar7 + 1;
                    /* try { // try from 00136c0d to 00146c8d has its CatchHandler @ 00136b30 */
      } while (ppcVar7 != ppcVar1);
    }
    ClientDLL_CreateEntities();
    CL_TempEntUpdate();
    if (cls.spectator != false) {
      r_oldviewleaf = (mleaf_t *)0x0;
      R_MarkLeaves();
    }
    CL_FireEvents();
    return;
  }
  return;
}


// CL_EndMovie_f  @ 00143fc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_EndMovie_f(void)

{
  if (cl_inmovie != false) {
    cl_inmovie = false;
    host_framerate.value = 0.0;
    Con_Printf("Stopped recording movie...\n");
    return;
  }
  Con_Printf("No movie started.\n");
  return;
}


// CL_EntityNum  @ 00154040
cl_entity_t * CL_EntityNum(int num)

{
  if (cl.num_entities <= num) {
    if (cl.max_edicts <= num) {
                    /* WARNING: Subroutine does not return */
      Host_Error("CL_EntityNum: %i is an invalid number, cl.max_edicts is %i",num,cl.max_edicts);
    }
    do {
      cl_entities[num].index = num;
      cl.num_entities = cl.num_entities + 1;
    } while (cl.num_entities <= num);
  }
  cl_entities[num].index = num;
  return cl_entities + num;
}


// CL_EntityTeleported  @ 00132320
qboolean CL_EntityTeleported(cl_entity_t_conflict2 *ent)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t distance@[???] */
  if ((*(float *)&(ent->curstate).field_0x10 - *(float *)&(ent->prevstate).field_0x10 <= 128.0) &&
     (*(float *)&(ent->curstate).field_0x14 - *(float *)&(ent->prevstate).field_0x14 <= 128.0)) {
    return (uint)(128.0 < *(float *)&(ent->curstate).field_0x18 -
                          *(float *)&(ent->prevstate).field_0x18);
  }
  return true;
}


// CL_EstimateNeededResources  @ 00155840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_EstimateNeededResources(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pFileName;
  resource_s *pFileName_00;
  int iVar4;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: int nTotalSize@[???]
                       Unresolved local var: int nSize@[???] */
  iVar4 = 0;
  if (cl.resourcesneeded.pNext != &cl.resourcesneeded) {
    iVar4 = 0;
    pFileName_00 = cl.resourcesneeded.pNext;
    do {
      switch(pFileName_00->type) {
      case t_sound:
        if (pFileName_00->szFileName[0] != '*') {
          pFileName = va("sound/%s",pFileName_00);
          uVar2 = FS_FileSize(pFileName);
          goto joined_r0x0015588a;
        }
        break;
      case t_skin:
      case t_generic:
      case t_eventscript:
switchD_00155869_caseD_1:
        uVar2 = FS_FileSize(pFileName_00->szFileName);
joined_r0x0015588a:
        if ((uVar2 != 0) && (uVar2 != 0xffffffff)) break;
        bVar1 = pFileName_00->ucFlags;
LAB_001558bd:
        pFileName_00->ucFlags = bVar1 | 2;
        iVar3 = pFileName_00->nDownloadSize;
        goto LAB_00155891;
      case t_model:
        if ((pFileName_00->szFileName[0] != '*') && (pFileName_00->ucFlags != '\0'))
        goto switchD_00155869_caseD_1;
        break;
      case t_decal:
        bVar1 = pFileName_00->ucFlags;
        if ((bVar1 & 4) != 0) goto LAB_001558bd;
      }
      iVar3 = 0;
LAB_00155891:
      pFileName_00 = pFileName_00->pNext;
      iVar4 = iVar4 + iVar3;
    } while (pFileName_00 != &cl.resourcesneeded);
  }
  return iVar4;
}


// CL_Exec  @ 00139e20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Exec(void)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  char local_1410 [1024];
  char local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: char[1024] pchExecBuf@[???]
                       Unresolved local var: int nExecType@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = MSG_ReadByte();
  if (iVar1 == 0) {
                    /* Unresolved local var: char[4096] pchMapName@[???] */
    if (g_bIsTFC != 0) {
      Cbuf_AddText("exec mapdefault.cfg\n");
      uVar2 = Q_strlen(cl.levelname);
      if (uVar2 < 0xfff) {
        COM_FileBase(cl.levelname,local_1010);
        if (local_1010[0] != '\0') {
          __snprintf_chk(local_1410,0x400,1,0x400,&LAB_002639be,local_1010);
          Cbuf_AddText(local_1410);
        }
      }
    }
  }
  else if (iVar1 == 1) {
                    /* Unresolved local var: int nClassNum@[???] */
    uVar2 = MSG_ReadByte();
    if ((g_bIsTFC != 0) && (uVar2 < 0xc)) {
      Cbuf_AddText(CL_Exec::lexical_block_1::sClassCfgs[uVar2]);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_FindEmptyEvent  @ 00139060
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

event_info_t * CL_FindEmptyEvent(void)

{
  int iVar1;
  event_state_t *peVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  peVar2 = &cl.events;
  iVar1 = 0;
  do {
    if (peVar2->ei[0].index == 0) {
      return cl.events.ei + iVar1;
    }
    iVar1 = iVar1 + 1;
    peVar2 = (event_state_t *)(peVar2->ei + 1);
  } while (iVar1 != 0x40);
  return (event_info_t *)0x0;
}


// CL_FindEventHook  @ 00139ac0
event_hook_s * CL_FindEventHook(char *name)

{
  event_hook_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: event_hook_t * hook@[???] */
  peVar1 = g_pEventHooks;
  if (name != (char *)0x0) {
    for (; peVar1 != (event_hook_t *)0x0; peVar1 = peVar1->next) {
      if ((peVar1->name != (char *)0x0) && (iVar2 = Q_stricmp(name,peVar1->name), iVar2 == 0)) {
        return peVar1;
      }
    }
  }
  return (event_hook_s *)0x0;
}


// CL_FindInterpolationUpdates  @ 0013c980
qboolean CL_FindInterpolationUpdates
                   (cl_entity_t *ent,float targettime,position_history_t **ph0,
                   position_history_t **ph1,int *ph0Index)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  qboolean qVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: int i0@[???]
                       Unresolved local var: int i1@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float at@[???]
                       Unresolved local var: int imod@[???] */
  uVar2 = ent->current_position;
  uVar5 = uVar2 & 0x3f;
  uVar3 = uVar2 - 1;
  uVar6 = uVar3 & 0x3f;
  if (targettime <= ent->ph[uVar5].animtime) {
    do {
      uVar7 = uVar3 & 0x3f;
      fVar1 = ent->ph[uVar7].animtime;
      if (fVar1 == 0.0) break;
      if (fVar1 < targettime) {
        uVar5 = uVar3 + 1 & 0x3f;
        qVar4 = false;
        goto LAB_0013ca25;
      }
      uVar3 = uVar3 - 1;
    } while (uVar3 != uVar2 - 0x3f);
  }
  qVar4 = true;
  uVar7 = uVar6;
LAB_0013ca25:
  if (ph0 != (position_history_t **)0x0) {
    *ph0 = ent->ph + uVar5;
  }
  if (ph1 != (position_history_t **)0x0) {
    *ph1 = ent->ph + uVar7;
  }
  if (ph0Index != (int *)0x0) {
    *ph0Index = uVar5;
  }
  return qVar4;
}


// CL_FindUnreliableEvent  @ 00139090
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

event_info_t * CL_FindUnreliableEvent(void)

{
  event_info_t *peVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  peVar1 = cl.events.ei;
  while( true ) {
    if (((event_info_s *)&peVar1->index)->index == 0) {
      return peVar1;
    }
    if ((peVar1->flags & 2) == 0) break;
    peVar1 = peVar1 + 1;
    if (peVar1 == (event_info_t *)cl.downloadUrl) {
      return (event_info_t *)0x0;
    }
  }
  return peVar1;
}


// CL_FinishGameGauge  @ 00142990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_FinishGameGauge(void)

{
  double dVar1;
  double dVar2;
  float fVar3;
  FileHandle_t file;
  int iVar4;
  char *pcVar5;
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: int frames@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float time@[???] */
  Cvar_Set("cl_gg","0");
  fVar3 = 1.0;
  if ((float)realtime - cls.td_starttime != 0.0) {
    fVar3 = (float)realtime - cls.td_starttime;
  }
  pcVar5 = gpszVersionString;
  fVar3 = (float)((host_framecount - cls.td_startframe) + -1) / fVar3;
  dVar1 = (double)fVar3;
  dVar2 = (double)fVar3;
  Con_Printf("%5.2f Half-Life v%s\n",SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20),
             gpszVersionString);
  Con_Printf("%d Min\n",g_iMinFPS);
  Con_Printf("%d Max\n",g_iMaxFPS);
  if (0 < g_iSecond) {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Con_Printf("%d Second %d\n",*(undefined4 *)(iVar4 * 4 + 0xbd283c),iVar4,pcVar5);
    } while (iVar4 < g_iSecond);
  }
  file = FS_OpenPathID("fps.txt","w","GAMECONFIG");
  pcVar5 = gpszVersionString;
  FS_FPrintf(file,"%5.2f Half-Life v%s\n",SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20),
             gpszVersionString);
  FS_FPrintf(file,"%d Min\n",g_iMinFPS);
  FS_FPrintf(file,"%d Max\n",g_iMaxFPS);
  if (0 < g_iSecond) {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      FS_FPrintf(file,"%d Second %d\n",*(undefined4 *)(iVar4 * 4 + 0xbd283c),iVar4,pcVar5);
    } while (iVar4 < g_iSecond);
  }
  FS_Close(file);
  iVar4 = COM_CheckParm("-noquit");
  if (iVar4 == 0) {
    Cbuf_AddText("quit\n");
  }
  return;
}


// CL_FinishTimeDemo  @ 00142780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_FinishTimeDemo(void)

{
  float fVar1;
  int iVar2;
  
                    /* Unresolved local var: int frames@[???]
                       Unresolved local var: float time@[???] */
  fVar1 = (float)realtime - cls.td_starttime;
  cls.timedemo = false;
  iVar2 = (host_framecount - cls.td_startframe) + -1;
  if (fVar1 == 0.0) {
    fVar1 = 1.0;
  }
  Con_Printf("%i frames %5.3f seconds %5.3f fps\n",iVar2,(double)fVar1,
             (double)((float)iVar2 / fVar1));
  return;
}


// CL_FireEvents  @ 00138f20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_FireEvents(void)

{
  event_hook_s **ppeVar1;
  uint uVar2;
  int iVar3;
  event_hook_s *peVar4;
  uint uVar5;
  event_args_s *dest;
  char *pcVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???]
                       Unresolved local var: event_hook_t * hook@[???] */
  uVar5 = 0;
  dest = &cl.events.ei[0].args;
  do {
    uVar2 = (uint)(ushort)dest[-1].iparam2;
    if ((uVar2 != 0) &&
       (((float)dest[-1].bparam2 == 0.0 || ((float)dest[-1].bparam2 <= (float)cl.time)))) {
                    /* Unresolved local var: event_hook_t * hook@[???] */
      pcVar6 = cl.event_precache[uVar2].filename;
      if ((pcVar6 != (char *)0x0) && (peVar4 = g_pEventHooks, g_pEventHooks != (event_hook_t *)0x0))
      {
        do {
          if ((peVar4->name != (char *)0x0) && (iVar3 = Q_stricmp(pcVar6,peVar4->name), iVar3 == 0))
          {
                    /* Unresolved local var: int idx@[???] */
            pcVar6 = cl.event_precache[(ushort)dest[-1].iparam2].filename;
            if ((cl_showevents.value != 0.0) && (pcVar6 != (char *)0x0)) {
              Con_NPrintf(uVar5 & 0x1f,"%i %f %s",uVar5,cl.time,pcVar6);
            }
            (*peVar4->pfnEvent)(dest);
            goto LAB_00138fc0;
          }
          ppeVar1 = &peVar4->next;
          peVar4 = *ppeVar1;
        } while (*ppeVar1 != (event_hook_s *)0x0);
        uVar2 = (uint)(ushort)dest[-1].iparam2;
        pcVar6 = cl.event_precache[uVar2].filename;
      }
      Con_DPrintf("CL_FireEvents:  Unknown event %i:%s\n",uVar2,pcVar6);
LAB_00138fc0:
      *(undefined2 *)&dest[-1].iparam2 = 0;
      Q_memset(dest,0,0x48);
      dest[-1].bparam2 = 0;
      dest[1].flags = 0;
    }
    uVar5 = uVar5 + 1;
    dest = (event_args_s *)(dest[1].origin + 2);
    if (uVar5 == 0x40) {
      return;
    }
  } while( true );
}


// CL_FixPointers  @ 0013dd00
void CL_FixPointers(demo_info_t *info)

{
  (info->rp).cmd = &info->cmd;
  (info->rp).movevars = &info->movevars;
  return;
}


// CL_FlushEntityPacket  @ 001328e0
void CL_FlushEntityPacket(qboolean needbitencodingframe)

{
  delta_t **ppdVar1;
  delta_t **ppdVar2;
  delta_t **ppdVar3;
  uint32 uVar4;
  delta_t *pFields;
  uint32 uVar5;
  int in_GS_OFFSET;
  bool bVar6;
  bool bVar7;
  uint32 local_2ec;
  con_nprint_s local_2dc;
  uchar local_2c8 [340];
  uchar local_174 [340];
  int local_20;
  
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: entity_state_t.conflict olde@[???]
                       Unresolved local var: entity_state_t.conflict newe@[???]
                       Unresolved local var: uint peeklong@[???]
                       Unresolved local var: qboolean remove@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: qboolean newbl@[???]
                       Unresolved local var: int newblindex@[???]
                       Unresolved local var: int numbase@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: con_nprint_t np@[???]
                       Unresolved local var: delta_t * * ppentity@[???]
                       Unresolved local var: delta_t * * ppcustom@[???]
                       Unresolved local var: delta_t * * ppplayer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ppdVar1 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar2 = DELTA_LookupRegistration("entity_state_t");
  ppdVar3 = DELTA_LookupRegistration("custom_entity_state_t");
  local_2dc.time_to_live = 1.0;
  local_2dc.color[0] = 1.0;
  local_2dc.color[1] = 0.2;
  local_2dc.color[2] = 0.0;
  local_2dc.index = 0;
  Con_NXPrintf(&local_2dc,"WARNING:  CL_FlushEntityPacket");
  Q_memset(local_2c8,0,0x154);
  cl.validsequence = 0;
  cl.frames[cl.parsecountmod].invalid = true;
  if (needbitencodingframe != false) {
    MSG_StartBitReading(&net_message);
  }
  local_2ec = 0;
  bVar6 = false;
  bVar7 = false;
LAB_001329c0:
  uVar4 = MSG_PeekBits(0x10);
  if (uVar4 != 0) goto LAB_00132a49;
  do {
    uVar4 = MSG_ReadBits(0x10);
    while( true ) {
      if (msg_badread != false) {
                    /* WARNING: Subroutine does not return */
        Host_EndGame("msg_badread in packetentities\n");
      }
      if (uVar4 == 0) {
        if (needbitencodingframe != false) {
          MSG_EndBitReading(&net_message);
        }
        if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      if (bVar6) {
        bVar6 = true;
        goto LAB_001329c0;
      }
      bVar6 = false;
      if (bVar7) {
        bVar7 = true;
        DELTA_ParseDelta(local_2c8,local_174,*ppdVar3,0x154);
        goto LAB_001329c0;
      }
      if (((int)uVar4 < 1) || (cl.maxclients < (int)uVar4)) {
        pFields = *ppdVar2;
      }
      else {
        pFields = *ppdVar1;
      }
      DELTA_ParseDelta(local_2c8,local_174,pFields,0x154);
      uVar4 = MSG_PeekBits(0x10);
      if (uVar4 == 0) break;
LAB_00132a49:
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int delta@[???]
                       Unresolved local var: qboolean isdelta@[???]
                       Unresolved local var: qboolean isnext@[???] */
      uVar5 = MSG_ReadBits(1);
      bVar6 = uVar5 != 0;
      uVar4 = MSG_ReadBits(1);
      if (uVar4 == 0) {
        uVar4 = MSG_ReadBits(6);
        uVar4 = local_2ec + uVar4;
      }
      else {
        uVar4 = MSG_ReadBits(0xb);
      }
      local_2ec = uVar4;
      if (uVar5 == 0) {
        uVar5 = MSG_ReadBits(1);
        bVar7 = uVar5 != 0;
        if ((cl.instanced_baseline_number != 0) && (uVar5 = MSG_ReadBits(1), uVar5 != 0)) {
          MSG_ReadBits(6);
        }
      }
      else {
        bVar7 = false;
      }
    }
  } while( true );
}


// CL_FlushEventSystem  @ 00139c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_FlushEventSystem(void)

{
  event_hook_s *peVar1;
  event_hook_t *p;
  
  p = g_pEventHooks;
  while (p != (event_hook_t *)0x0) {
    peVar1 = p->next;
    Mem_Free(p->name);
    Mem_Free(p);
    p = peVar1;
  }
  g_pEventHooks = (event_hook_t *)0x0;
  return;
}


// CL_FullServerinfo_f  @ 00144000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_FullServerinfo_f(void)

{
  int iVar1;
  char *src;
  
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("usage: fullserverinfo <complete info string>\n");
    return;
  }
  src = Cmd_Argv(1);
  Q_strncpy(cl.serverinfo,src,0x1ff);
  cl.serverinfo[0x1ff] = '\0';
  return;
}


// CL_FxBlend  @ 00152f80
int CL_FxBlend(cl_entity_t *ent)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int32 iVar4;
  int iVar5;
  double dVar6;
  double local_24;
  
                    /* Unresolved local var: int blend@[???]
                       Unresolved local var: float offset@[???] */
  dVar6 = cl.time;
  fVar1 = (float)(ent->curstate).number * 363.0;
  iVar5 = (ent->curstate).renderfx;
  switch(iVar5) {
  default:
    goto switchD_00152fa3_caseD_0;
  case 1:
    dVar6 = cl.time + cl.time;
    goto LAB_001530b8;
  case 2:
    dVar6 = cl.time * 8.0;
LAB_001530b8:
    dVar6 = sin(dVar6 + (double)fVar1);
    iVar5 = (int)(dVar6 * 16.0 + (double)(ent->curstate).renderamt);
    break;
  case 3:
    dVar6 = cl.time + cl.time;
    goto LAB_00153108;
  case 4:
    dVar6 = cl.time * 8.0;
LAB_00153108:
    dVar6 = sin(dVar6 + (double)fVar1);
    iVar5 = (int)(dVar6 * 64.0 + (double)(ent->curstate).renderamt);
    break;
  case 5:
    iVar3 = (ent->curstate).renderamt;
    iVar5 = 0;
    if (0 < iVar3) {
      iVar5 = iVar3 + -1;
    }
    (ent->curstate).renderamt = iVar5;
    break;
  case 6:
    iVar3 = (ent->curstate).renderamt;
    iVar5 = 0;
    if (3 < iVar3) {
      iVar5 = iVar3 + -4;
    }
    (ent->curstate).renderamt = iVar5;
    break;
  case 7:
    iVar3 = (ent->curstate).renderamt;
    iVar5 = 0xff;
    if (iVar3 < 0xff) {
      iVar5 = iVar3 + 1;
    }
    (ent->curstate).renderamt = iVar5;
    goto LAB_00152fed;
  case 8:
    iVar3 = (ent->curstate).renderamt;
    iVar5 = 0xff;
    if (iVar3 < 0xfc) {
      iVar5 = iVar3 + 4;
    }
    (ent->curstate).renderamt = iVar5;
    goto LAB_00152fed;
  case 9:
    fVar2 = 4.0;
    goto LAB_001531be;
  case 10:
    fVar2 = 16.0;
LAB_001531be:
    dVar6 = sin((double)(fVar2 * (float)cl.time + fVar1));
LAB_001531d0:
    if ((int)(dVar6 * 20.0) < 0) {
      return 0;
    }
switchD_00152fa3_caseD_0:
    iVar5 = (ent->curstate).renderamt;
    break;
  case 0xb:
    dVar6 = sin((double)((float)cl.time * 36.0 + fVar1));
    goto LAB_001531d0;
  case 0xc:
    local_24 = sin(cl.time + cl.time);
    dVar6 = dVar6 * 17.0 + (double)fVar1;
    goto LAB_0015324d;
  case 0xd:
    local_24 = sin(cl.time * 16.0);
    dVar6 = dVar6 * 23.0 + (double)fVar1;
LAB_0015324d:
    dVar6 = sin(dVar6);
    dVar6 = dVar6 + local_24;
    goto LAB_001531d0;
  case 0xf:
  case 0x10:
                    /* Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: float dist@[???] */
    if (iVar5 == 0xf) {
      (ent->curstate).renderamt = 0xb4;
      iVar5 = 0xb4;
    }
    else {
      fVar1 = (ent->origin[2] - r_origin[2]) * vpn[2] +
              (ent->origin[1] - r_origin[1]) * vpn[1] + vpn[0] * (ent->origin[0] - r_origin[0]);
      if (fVar1 <= 0.0) {
        return 0;
      }
      (ent->curstate).renderamt = 0xb4;
      if (fVar1 <= 100.0) {
        iVar5 = 0xb4;
      }
      else {
        iVar5 = (int)((1.0 - (fVar1 - 100.0) * 0.0025) * 180.0);
      }
    }
    iVar4 = RandomLong(-0x20,0x1f);
    iVar5 = iVar5 + iVar4;
  }
  if (0xff < iVar5) {
    return 0xff;
  }
LAB_00152fed:
  iVar3 = 0;
  if (-1 < iVar5) {
    iVar3 = iVar5;
  }
  return iVar3;
}


// CL_FxTransform  @ 001532c0
void CL_FxTransform(cl_entity_t *ent,float (*transform) [4])

{
  int32 iVar1;
  int iVar2;
  vec_t *in;
  float fVar3;
  
  iVar2 = (ent->curstate).renderfx;
  if (0xe < iVar2) {
    if (iVar2 < 0x11) {
      iVar1 = RandomLong(0,0x31);
      if (iVar1 == 0) {
                    /* Unresolved local var: int axis@[???] */
        iVar1 = RandomLong(0,1);
        iVar2 = 0x20;
        if (iVar1 != 1) {
          iVar2 = iVar1 << 4;
        }
        in = (vec_t *)((int)*transform + iVar2);
        fVar3 = RandomFloat(1.0,1.484);
        VectorScale(in,fVar3,in);
        return;
      }
      iVar1 = RandomLong(0,0x31);
      if (iVar1 == 0) {
                    /* Unresolved local var: float offset@[???]
                       Unresolved local var: int axis@[???] */
        RandomLong(0,1);
        fVar3 = RandomFloat(-10.0,10.0);
        iVar1 = RandomLong(0,2);
        transform[iVar1][3] = fVar3 + transform[iVar1][3];
      }
    }
    else if (iVar2 == 0x12) {
                    /* Unresolved local var: float scale@[???] */
      fVar3 = ((float)cl.time - (ent->curstate).animtime) * 10.0 + 1.0;
      if (2.0 < fVar3) {
        fVar3 = 2.0;
      }
      (*transform)[1] = (*transform)[1] * fVar3;
      transform[1][1] = transform[1][1] * fVar3;
      transform[2][1] = fVar3 * transform[2][1];
    }
  }
  return;
}


// CL_GGSpeeds  @ 00142c80
void CL_GGSpeeds(float flCurTime)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = host_framecount;
  if (g_flTime != 0.0) {
    if (1.0 <= flCurTime - g_flTime) {
      if (scr_con_current == 0.0) {
                    /* Unresolved local var: int frames@[???] */
        iVar3 = host_framecount - g_iFrames;
        if (g_iMaxFPS < iVar3) {
          g_iMaxFPS = iVar3;
        }
        if (iVar3 < g_iMinFPS) {
          g_iMinFPS = iVar3;
        }
        if (g_iSecond < 300) {
          piVar1 = g_rgFPS + g_iSecond;
          g_iSecond = g_iSecond + 1;
          *piVar1 = iVar3;
        }
      }
      else {
        cls.td_startframe = host_framecount;
        cls.td_starttime = (float)realtime;
      }
      g_iFrames = iVar2;
      g_flTime = flCurTime;
    }
    return;
  }
  g_flTime = flCurTime;
  return;
}


// CL_GameDir_f  @ 00147720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_GameDir_f(void)

{
  int iVar1;
  qboolean qVar2;
  char *pcVar3;
  
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("gamedir is %s\n",com_gamedir);
    return;
  }
  CL_Disconnect();
  qVar2 = Host_IsServerActive();
  if (qVar2 != false) {
    Host_ShutdownServer(false);
  }
  pcVar3 = Cmd_Argv(1);
  Con_Printf("Setting gamedir to %s\n",pcVar3);
  pcVar3 = Cmd_Argv(1);
  CL_CheckGameDirectory(pcVar3);
  return;
}


// CL_GameGauge_f  @ 001428e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_GameGauge_f(void)

{
  int iVar1;
  
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    CL_PlayDemo_f();
    Cvar_Set("cl_gg","1");
    g_iFrames = host_framecount;
    g_iMaxFPS = 0;
    g_iMinFPS = 0x7fffffff;
    cls.td_starttime = (float)realtime;
    g_iSecond = 0;
    g_flTime = 0.0;
    cls.timedemo = true;
    cls.td_lastframe = -1;
    cls.td_startframe = g_iFrames;
  }
  else {
    Con_Printf("gg <demoname> : Game Gauge 99\n");
  }
  return;
}


// CL_GetCDKeyHash  @ 00147810
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * CL_GetCDKeyHash(void)

{
  char *pcVar1;
  int in_GS_OFFSET;
  uint local_180;
  int local_17c;
  uchar local_178 [16];
  MD5Context_t local_168;
  uchar local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] szKeyBuffer@[???]
                       Unresolved local var: int nKeyLength@[???]
                       Unresolved local var: int bDedicated@[???]
                       Unresolved local var: MD5Context_t ctx@[???]
                       Unresolved local var: uchar[16] digest@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_17c = 0;
  local_180 = 0x40;
  Sys_GetCDKey((char *)local_110,(int *)&local_180,&local_17c);
  if (local_17c == 0) {
    if (local_180 - 1 < 0xff) {
      local_110[local_180] = '\0';
      Q_memset(&local_168,0,0x58);
      Q_memset(local_178,0,0x10);
      MD5Init(&local_168);
      MD5Update(&local_168,local_110,local_180);
      MD5Final(local_178,&local_168);
      Q_memset(CL_GetCDKeyHash::szHashedKeyBuffer,0,0x100);
      pcVar1 = MD5_Print(local_178);
      Q_strncpy(CL_GetCDKeyHash::szHashedKeyBuffer,pcVar1,0xff);
      pcVar1 = CL_GetCDKeyHash::szHashedKeyBuffer;
      CL_GetCDKeyHash::szHashedKeyBuffer[0xff] = '\0';
    }
    else {
      Con_Printf("Bogus key length on CD Key...\n");
      pcVar1 = "";
    }
  }
  else {
    Con_Printf("Key has no meaning on dedicated server...\n");
    pcVar1 = "";
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pcVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_GetDemoViewInfo  @ 0013e370
void CL_GetDemoViewInfo(ref_params_t *rp,float *view,int *viewmodel)

{
  int iVar1;
  
  iVar1 = DemoPlayer_IsActive();
  if (iVar1 != 0) {
    DemoPlayer_GetDemoViewInfo(rp,view,viewmodel);
    return;
  }
  CL_GetDemoViewInfo_OLD(rp,view,viewmodel);
  return;
}


// CL_GetDemoViewInfo_OLD  @ 0013df30
void CL_GetDemoViewInfo_OLD(ref_params_t *rp,vec_t *view,int *viewmodel)

{
  demo_info_t *pdVar1;
  float fVar2;
  float fVar3;
  movevars_s *pmVar4;
  usercmd_s *puVar5;
  undefined4 uVar6;
  float fVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int iVar10;
  uint uVar11;
  demo_info_t *pdVar12;
  int iVar13;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  int local_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  
                    /* Unresolved local var: float targettime@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???]
                       Unresolved local var: demo_info_t * from@[???]
                       Unresolved local var: demo_info_t * to@[???]
                       Unresolved local var: usercmd_t * oldcmd@[???]
                       Unresolved local var: movevars_t * oldmv@[???]
                       Unresolved local var: int[4] oldviewport@[???] */
  uVar11 = 0;
  pmVar4 = rp->movevars;
  local_2c = rp->viewport[0];
  iStack_28 = rp->viewport[1];
  uVar8 = *(undefined8 *)rp->viewport;
  iStack_24 = rp->viewport[2];
  iStack_20 = rp->viewport[3];
  uVar9 = *(undefined8 *)(rp->viewport + 2);
  puVar5 = rp->cmd;
  do {
    uVar6 = *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar11 + 4);
    *(undefined4 *)((int)rp->vieworg + uVar11) =
         *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar11);
    *(undefined4 *)((int)rp->vieworg + uVar11 + 4) = uVar6;
    uVar11 = uVar11 + 8;
  } while (uVar11 < 0xe8);
  rp->cmd = puVar5;
  rp->movevars = pmVar4;
  *(undefined8 *)rp->viewport = uVar8;
  *(undefined8 *)(rp->viewport + 2) = uVar9;
  if (cls.timedemo == false) {
    fVar3 = (g_demotimescale * (float)realtime - cls.demostarttime) - 0.02;
    pdVar12 = dem_frames;
    iVar10 = 1;
    do {
      iVar13 = iVar10;
      pdVar1 = pdVar12 + 1;
      pdVar12[1].rp.cmd = &pdVar12[1].cmd;
      pdVar12[1].rp.movevars = &pdVar12[1].movevars;
      fVar2 = pdVar12[1].timestamp;
      if (fVar2 == 0.0) {
        return;
      }
    } while ((fVar3 <= fVar2) && (pdVar12 = pdVar1, iVar10 = iVar13 + 1, iVar13 + 1 != 0x1f));
    if (fVar2 != pdVar12->timestamp) {
      fVar3 = (fVar3 - fVar2) / (pdVar12->timestamp - fVar2);
      if (fVar3 <= 1.0) {
        fVar2 = 0.0;
        if (0.0 <= fVar3) {
          fVar2 = fVar3;
        }
      }
      else {
        fVar2 = 1.0;
      }
      fStack_38 = (pdVar12->rp).vieworg[0] - dem_frames[iVar13].rp.vieworg[0];
      fStack_34 = (pdVar12->rp).vieworg[1] - dem_frames[iVar13].rp.vieworg[1];
      fStack_30 = (pdVar12->rp).vieworg[2] - dem_frames[iVar13].rp.vieworg[2];
      VectorMA(dem_frames[iVar13].rp.vieworg,fVar2,&fStack_38,rp->vieworg);
      fVar3 = dem_frames[iVar13].rp.viewangles[0];
      fVar7 = (pdVar12->rp).viewangles[0] - fVar3;
      if (180.0 < fVar7) {
        fVar7 = fVar7 - 360.0;
      }
      else if (fVar7 < -180.0) {
        fVar7 = fVar7 + 360.0;
      }
      rp->viewangles[0] = fVar7 * fVar2 + fVar3;
      fVar3 = dem_frames[iVar13].rp.viewangles[1];
      fVar7 = (pdVar12->rp).viewangles[1] - fVar3;
      if (180.0 < fVar7) {
        fVar7 = fVar7 - 360.0;
      }
      else if (fVar7 < -180.0) {
        fVar7 = fVar7 + 360.0;
      }
      rp->viewangles[1] = fVar7 * fVar2 + fVar3;
      fVar3 = dem_frames[iVar13].rp.viewangles[2];
      fVar7 = (pdVar12->rp).viewangles[2] - fVar3;
      if (fVar7 <= 180.0) {
        if (fVar7 < -180.0) {
          fVar7 = fVar7 + 360.0;
        }
      }
      else {
        fVar7 = fVar7 - 360.0;
      }
      rp->viewangles[2] = fVar3 + fVar7 * fVar2;
      COM_NormalizeAngles(rp->viewangles);
      fStack_38 = (pdVar12->rp).simvel[0] - dem_frames[iVar13].rp.simvel[0];
      fStack_34 = (pdVar12->rp).simvel[1] - dem_frames[iVar13].rp.simvel[1];
      fStack_30 = (pdVar12->rp).simvel[2] - dem_frames[iVar13].rp.simvel[2];
      VectorMA(dem_frames[iVar13].rp.simvel,fVar2,&fStack_38,rp->simvel);
      fStack_38 = (pdVar12->rp).simorg[0] - dem_frames[iVar13].rp.simorg[0];
      fStack_34 = (pdVar12->rp).simorg[1] - dem_frames[iVar13].rp.simorg[1];
      fStack_30 = (pdVar12->rp).simorg[2] - dem_frames[iVar13].rp.simorg[2];
      VectorMA(dem_frames[iVar13].rp.simorg,fVar2,&fStack_38,rp->simorg);
      rp->viewheight[0] =
           ((pdVar12->rp).viewheight[0] - dem_frames[iVar13].rp.viewheight[0]) * fVar2 +
           dem_frames[iVar13].rp.viewheight[0];
      rp->viewheight[1] =
           ((pdVar12->rp).viewheight[1] - dem_frames[iVar13].rp.viewheight[1]) * fVar2 +
           dem_frames[iVar13].rp.viewheight[1];
      rp->viewheight[2] =
           ((pdVar12->rp).viewheight[2] - dem_frames[iVar13].rp.viewheight[2]) * fVar2 +
           dem_frames[iVar13].rp.viewheight[2];
      fStack_38 = pdVar12->view[0] - dem_frames[iVar13].view[0];
      fStack_34 = pdVar12->view[1] - dem_frames[iVar13].view[1];
      fStack_30 = pdVar12->view[2] - dem_frames[iVar13].view[2];
      VectorMA(dem_frames[iVar13].view,fVar2,&fStack_38,view);
      *viewmodel = pdVar12->viewmodel;
    }
    return;
  }
  *view = dem_frames[0].view[0];
  view[1] = dem_frames[0].view[1];
  view[2] = dem_frames[0].view[2];
  *viewmodel = dem_frames[0].viewmodel;
  return;
}


// CL_GetDownloadQueueSize  @ 00127590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_GetDownloadQueueSize(void)

{
  return TheDownloadManager.m_queuedRequests.m_Size;
}


// CL_GetEstimatedFrame  @ 000dc940
float CL_GetEstimatedFrame(cl_entity_t *ent)

{
  int iVar1;
  float fVar2;
  model_t *mod;
  int iVar3;
  cl_entity_t *pcVar4;
  void *pvVar5;
  int iVar6;
  
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: cl_entity_t * oldce@[???] */
  pcVar4 = currententity;
  mod = ent->model;
  if (((mod == (model_t *)0x0) || (mod->type != mod_studio)) ||
     (pvVar5 = Mod_Extradata(mod), pvVar5 == (void *)0x0)) {
    return 0.0;
  }
  iVar6 = (ent->curstate).sequence * 0xb0 + *(int *)((int)pvVar5 + 0xa8);
                    /* Unresolved local var: double dfdt@[???]
                       Unresolved local var: double f@[???] */
  if (r_dointerp == 0) {
LAB_000dc9bd:
    fVar2 = 0.0;
  }
  else {
    fVar2 = (ent->curstate).animtime;
    if ((float)cl.time < fVar2) goto LAB_000dc9bd;
    fVar2 = ((float)cl.time - fVar2) * (ent->curstate).framerate *
            *(float *)((int)pvVar5 + iVar6 + 0x20);
  }
  iVar3 = *(int *)((int)pvVar5 + iVar6 + 0x38);
  if (iVar3 < 2) {
    fVar2 = fVar2 + 0.0;
    if ((*(byte *)((int)pvVar5 + iVar6 + 0x24) & 1) == 0) goto LAB_000dca34;
  }
  else {
                    /* Unresolved local var: float baseframe@[???] */
    iVar1 = iVar3 + -1;
    fVar2 = (float)iVar1 * (ent->curstate).frame * 0.00390625 + fVar2;
    if ((*(byte *)((int)pvVar5 + iVar6 + 0x24) & 1) == 0) {
LAB_000dca34:
      if ((float)iVar3 - 1.001 <= fVar2) {
        fVar2 = (float)iVar3 - 1.001;
      }
      if (0.0 <= fVar2) {
        currententity = pcVar4;
        return fVar2;
      }
      currententity = pcVar4;
      return 0.0;
    }
    fVar2 = fVar2 - (float)((int)(fVar2 / (float)iVar1) * iVar1);
  }
  if (fVar2 < 0.0) {
    fVar2 = (float)(iVar3 + -1) + fVar2;
  }
  currententity = pcVar4;
  return fVar2;
}


// CL_GetFragmentSize  @ 00143f60
int CL_GetFragmentSize(void *state)

{
  int iVar1;
  
                    /* Unresolved local var: int * state_value@[???]
                       Unresolved local var: int retval@[???] */
  iVar1 = 0x80;
                    /* Unresolved local var: int * state_value@[???]
                       Unresolved local var: int retval@[???] */
  if (((*(int *)state == 5) && (iVar1 = 0x100, 16.0 <= cl_dlmax.value)) &&
     (iVar1 = 0x400, cl_dlmax.value <= 1024.0)) {
    return (int)cl_dlmax.value;
  }
  return iVar1;
}


// CL_GetMessage  @ 001461d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_GetMessage(void)

{
  qboolean qVar1;
  
  if (cls.demoplayback != false) {
    qVar1 = CL_ReadDemoMessage();
    return qVar1;
  }
  if (cls.passive == false) {
    qVar1 = NET_GetPacket(NS_CLIENT);
    return qVar1;
  }
  qVar1 = NET_GetPacket(NS_MULTICAST);
  return qVar1;
}


// CL_GetModelByIndex  @ 0014b870
model_t * CL_GetModelByIndex(int index)

{
  model_t *mod;
  double dVar1;
  double dVar2;
  
                    /* Unresolved local var: model_t * mod@[???] */
  if (index < 0x200) {
    mod = cl.model_precache[index];
    if (mod != (model_t *)0x0) {
      if (1 < mod->needload - true) {
        return mod;
      }
      if (fs_precache_timings.value != 0.0) {
                    /* Unresolved local var: double end@[???]
                       Unresolved local var: double start@[???] */
        dVar1 = Sys_FloatTime();
        Mod_LoadModel(mod,false,false);
        dVar2 = Sys_FloatTime();
        Con_DPrintf("fs_precache_timings: loaded model %s in time %.3f sec\n",mod,
                    (double)(float)((longdouble)dVar2 - (longdouble)dVar1));
        return cl.model_precache[index];
      }
      Mod_LoadModel(mod,false,false);
      return cl.model_precache[index];
    }
  }
  return (model_t *)0x0;
}


// CL_GetPlayerHulls  @ 0014ace0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_GetPlayerHulls(void)

{
  int iVar1;
  int hullnumber;
  vec_t (*maxs) [3];
  vec_t (*mins) [3];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iResult@[DW_OP_reg0(EAX)] */
  mins = player_mins;
  maxs = player_maxs;
  hullnumber = 0;
  do {
    iVar1 = ClientDLL_GetHullBounds(hullnumber,*mins,*maxs);
    if (iVar1 == 0) {
      return;
    }
    hullnumber = hullnumber + 1;
    mins = mins + 1;
    maxs = maxs + 1;
  } while (hullnumber != 4);
  return;
}


// CL_GetServerCount  @ 0014b980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_GetServerCount(void)

{
  return cl.servercount;
}


// CL_GetTargetTime  @ 0013b430
void CL_GetTargetTime(float *target)

{
  *target = (float)realtime;
  return;
}


// CL_GetWorldModel  @ 0014b970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

model_t * CL_GetWorldModel(void)

{
  return cl.worldmodel;
}


// CL_HTTPCancel_f  @ 00127540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_HTTPCancel_f(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  DownloadManager::Reset(&TheDownloadManager);
                    /* Unresolved local var: int i@[???] */
  iVar1 = TheDownloadManager.m_downloadedMaps.m_Size;
  if (0 < TheDownloadManager.m_downloadedMaps.m_Size) {
    do {
      if (TheDownloadManager.m_downloadedMaps.m_Memory.m_pMemory[iVar2] != (char *)0x0) {
        operator_delete__(TheDownloadManager.m_downloadedMaps.m_Memory.m_pMemory[iVar2]);
        iVar1 = TheDownloadManager.m_downloadedMaps.m_Size;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  TheDownloadManager.m_downloadedMaps.m_Size = 0;
  return;
}


// CL_HTTPStop_f  @ 00127520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_HTTPStop_f(void)

{
  DownloadManager::Reset(&TheDownloadManager);
  return;
}


// CL_HTTPUpdate  @ 00128290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_HTTPUpdate(void)

{
  int *piVar1;
  DownloadManager *in_stack_00000004;
  
  DownloadManager::CheckActiveDownload(&TheDownloadManager);
  if (TheDownloadManager.m_queuedRequests.m_Size != 0) {
    piVar1 = (int *)SteamInternal_ContextInit(SteamHTTP::s_CallbackCounterAndContext);
    if (*piVar1 != 0) {
      DownloadManager::StartNewDownload(in_stack_00000004);
      return;
    }
  }
  return;
}


// CL_HookEvent  @ 00139b10
void CL_HookEvent(char *name,_func_void_event_args_s_ptr *pfnEvent)

{
  int iVar1;
  event_hook_t *peVar2;
  char *pcVar3;
  
                    /* Unresolved local var: event_hook_t * hook@[???] */
  (*g_engdstAddrs.pfnHookEvent)(&name,&pfnEvent);
  pcVar3 = name;
  if ((name == (char *)0x0) || (*name == '\0')) {
    Con_Printf("CL_HookEvent:  Must provide a valid event name\n");
    return;
  }
  peVar2 = g_pEventHooks;
  if (pfnEvent == (_func_void_event_args_s_ptr *)0x0) {
    Con_Printf("CL_HookEvent:  Must provide an event hook callback\n");
  }
  else {
    for (; peVar2 != (event_hook_t *)0x0; peVar2 = peVar2->next) {
      if ((peVar2->name != (char *)0x0) && (iVar1 = Q_stricmp(pcVar3,peVar2->name), iVar1 == 0)) {
        Con_DPrintf("CL_HookEvent:  Called on existing hook, updating event hook\n");
        peVar2->pfnEvent = pfnEvent;
        return;
      }
    }
    peVar2 = Mem_ZeroMalloc(0xc);
    pcVar3 = Mem_Strdup(name);
    peVar2->name = pcVar3;
    peVar2->pfnEvent = pfnEvent;
    peVar2->next = g_pEventHooks;
    g_pEventHooks = peVar2;
  }
  return;
}


// CL_HudMessage  @ 0014ac50
void CL_HudMessage(char *pMessage)

{
  int iSize;
  
  iSize = Q_strlen(pMessage);
  DispatchDirectUserMsg("HudText",iSize,pMessage);
  return;
}


// CL_Init  @ 0014af50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Init(void)

{
  char *value;
  int iVar1;
  
                    /* Unresolved local var: int iMouseGrab@[???]
                       Unresolved local var: char * pchSteamCommunityName@[???] */
  value = Steam_GetCommunityName();
  if (value == (char *)0x0) {
    value = "unknown";
  }
  Info_SetValueForKey(cls.userinfo,"name",value,0x100);
  Info_SetValueForKey(cls.userinfo,"topcolor","0",0x100);
  Info_SetValueForKey(cls.userinfo,"bottomcolor","0",0x100);
  Info_SetValueForKey(cls.userinfo,"rate","2500",0x100);
  Info_SetValueForKey(cls.userinfo,"cl_updaterate","20",0x100);
  Info_SetValueForKey(cls.userinfo,"cl_lw","1",0x100);
  Info_SetValueForKey(cls.userinfo,"cl_lc","1",0x100);
  Net_APIInit();
  CL_InitTEnts();
  CL_InitExtrap();
  TextMessageInit();
  Sequence_Init();
  Cvar_RegisterVariable(&cl_weaponlistfix);
  Cvar_RegisterVariable(&cl_fixtimerate);
  Cvar_RegisterVariable(&cl_showmessages);
  Cvar_RegisterVariable(&cl_name);
  Cvar_RegisterVariable(&password);
  Cvar_RegisterVariable(&team);
  Cvar_RegisterVariable(&cl_model);
  Cvar_RegisterVariable(&skin);
  Cvar_RegisterVariable(&topcolor);
  Cvar_RegisterVariable(&bottomcolor);
  Cvar_RegisterVariable(&rate);
  Cvar_RegisterVariable(&cl_updaterate);
  Cvar_RegisterVariable(&cl_lw);
  Cvar_RegisterVariable(&cl_lc);
  Cvar_RegisterVariable(&cl_dlmax);
  Cvar_RegisterVariable(&fs_startup_timings);
  Cvar_RegisterVariable(&fs_lazy_precache);
  Cvar_RegisterVariable(&fs_precache_timings);
  Cvar_RegisterVariable(&fs_perf_warnings);
  Cvar_RegisterVariable(&cl_clockreset);
  Cvar_RegisterVariable(&cl_showevents);
  Cvar_RegisterVariable(&cl_himodels);
  Cvar_RegisterVariable(&cl_gaitestimation);
  Cvar_RegisterVariable(&cl_idealpitchscale);
  Cvar_RegisterVariable(&cl_resend);
  Cvar_RegisterVariable(&cl_timeout);
  Cvar_RegisterVariable(&cl_cmdbackup);
  Cvar_RegisterVariable(&cl_shownet);
  Cvar_RegisterVariable(&rcon_address);
  Cvar_RegisterVariable(&rcon_port);
  Cvar_RegisterVariable(&cl_solid_players);
  Cvar_RegisterVariable(&cl_slisttimeout);
  Cvar_RegisterVariable(&cl_download_ingame);
  Cvar_RegisterVariable(&cl_allow_download);
  Cvar_RegisterVariable(&cl_allow_upload);
  Cvar_RegisterVariable(&cl_gamegauge);
  Cvar_RegisterVariable(&cl_cmdrate);
  Cvar_RegisterVariable(&cl_showfps);
  Cvar_RegisterVariable(&cl_needinstanced);
  Cvar_RegisterVariable(&dev_overview);
  Cvar_RegisterVariable(&cl_logofile);
  Cvar_RegisterVariable(&cl_logocolor);
  Cvar_RegisterVariable(&cl_mousegrab);
  Cvar_RegisterVariable(&m_rawinput);
  Cvar_RegisterVariable(&cl_filterstuffcmd);
  Cvar_RegisterVariable(&cl_fixmodelinterpolationartifacts);
  Cvar_RegisterVariable(&cl_skipvid);
  iVar1 = COM_CheckParm("-nomousegrab");
  if (iVar1 != 0) {
    Cvar_Set("cl_mousegrab","0");
  }
  iVar1 = COM_CheckParm("-novid");
  if (iVar1 == 0) {
    iVar1 = COM_CheckParm("-dev");
    if (iVar1 == 0) goto LAB_0014b307;
  }
  Cvar_Set("cl_skipvid","1");
LAB_0014b307:
  ClientDLL_HudInit();
  Cmd_AddCommand("gamedir",CL_GameDir_f);
  Cmd_AddCommandWithFlags("connect",CL_Connect_f,8);
  Cmd_AddCommand("fullserverinfo",CL_FullServerinfo_f);
  Cmd_AddCommandWithFlags("retry",CL_Retry_f,8);
  Cmd_AddCommand("disconnect",CL_Disconnect_f);
  Cmd_AddCommand("record",CL_Record_f);
  Cmd_AddCommand("stop",CL_Stop_f);
  Cmd_AddCommand("playdemo",CL_PlayDemo_f);
  Cmd_AddCommand("viewdemo",CL_ViewDemo_f);
  Cmd_AddCommand("timedemo",CL_TimeDemo_f);
  Cmd_AddCommand("gg",CL_GameGauge_f);
  Cmd_AddCommand("listdemo",CL_ListDemo_f);
  Cmd_AddCommand("appenddemo",CL_AppendDemo_f);
  Cmd_AddCommandWithFlags("removedemo",CL_RemoveDemo_f,0x10);
  Cmd_AddCommand("swapdemo",CL_SwapDemo_f);
  Cmd_AddCommand("setdemoinfo",CL_SetDemoInfo_f);
  Cmd_AddCommand("listen",CL_Listen_f);
  Cmd_AddCommand("commentator",CL_Commentator_f);
  Cmd_AddCommand("waveplaylen",CL_WavePlayLen_f);
  Cmd_AddCommand("snapshot",CL_TakeSnapshot_f);
  Cmd_AddCommand("startmovie",CL_StartMovie_f);
  Cmd_AddCommand("endmovie",CL_EndMovie_f);
  Cmd_AddCommand("entities",CL_PrintEntities_f);
  Cmd_AddCommandWithFlags("rcon",CL_Rcon_f,8);
  Cmd_AddCommand("cl_messages",CL_DumpMessageLoad_f);
  Cmd_AddCommand("pingservers",CL_PingServers_f);
  Cmd_AddCommand("slist",CL_Slist_f);
  Cmd_AddCommand("list",CL_ListCachedServers_f);
  Cmd_AddCommand("upload",CL_BeginUpload_f);
  CL_InitPrediction();
  Cmd_AddCommand("httpstop",CL_HTTPCancel_f);
  Cmd_AddCommand("spec_pos",CL_SpecPos_f);
  cls.datagram.data = cls.datagram_buf;
  cls.datagram.cursize = 0;
  cls.datagram.maxsize = 6000;
  cls.datagram.flags = 0;
  cls.datagram.buffername = "cls.datagram";
  cls.isVAC2Secure = false;
  cls.build_num = 0;
  cls.GameServerSteamID._4_4_ = 0;
  cls.GameServerSteamID._0_4_ = 0;
  Q_memset(&cl,0,0x1b0e68);
  cl.resourcesneeded.pPrev = &cl.resourcesneeded;
  cl.resourcesneeded.pNext = &cl.resourcesneeded;
  cl.resourcesonhand.pPrev = &cl.resourcesonhand;
  cl.resourcesonhand.pNext = &cl.resourcesonhand;
  DELTA_RegisterDescription("clientdata_t");
  DELTA_RegisterDescription("entity_state_t");
  DELTA_RegisterDescription("entity_state_player_t");
  DELTA_RegisterDescription("custom_entity_state_t");
  DELTA_RegisterDescription("usercmd_t");
  DELTA_RegisterDescription("weapon_data_t");
  DELTA_RegisterDescription("event_t");
  return;
}


// CL_InitEventSystem  @ 00139bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitEventSystem(void)

{
  g_pEventHooks = (event_hook_t *)0x0;
  return;
}


// CL_InitExtrap  @ 0013c960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitExtrap(void)

{
  Cvar_RegisterVariable(&ex_interp);
  return;
}


// CL_InitPrediction  @ 0013c930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitPrediction(void)

{
  Cvar_RegisterVariable(&cl_smoothtime);
  Cvar_RegisterVariable(&cl_nosmooth);
  Cvar_RegisterVariable(&cl_showerror);
  return;
}


// CL_InitSpectator  @ 0013d730
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitSpectator(void)

{
  Q_memset(&spectatorState,0,0x1930);
  Q_memset(&gDevOverview,0,0x1c);
  CL_CalculateDevOverviewParameters();
  if (cls.spectator != false) {
    spectatorState.playerstate.friction = 1.0;
    spectatorState.playerstate.movetype = 8;
    spectatorState.playerstate.number = cl.playernum + 1;
    spectatorState.client.maxspeed = movevars.spectatormaxspeed;
    spectatorState.playerstate.usehull = 1;
    spectatorState.playerstate.gravity = 1.0;
  }
  return;
}


// CL_InitTEnts  @ 0014bee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitTEnts(void)

{
  model_t *pmVar1;
  undefined *puVar2;
  
  Cvar_RegisterVariable(&tracerSpeed);
  Cvar_RegisterVariable(&tracerOffset);
  Cvar_RegisterVariable(&tracerLength);
  Cvar_RegisterVariable(&tracerRed);
  Cvar_RegisterVariable(&tracerGreen);
  Cvar_RegisterVariable(&tracerBlue);
  Cvar_RegisterVariable(&tracerAlpha);
  cl_sfx_ric1 = S_PrecacheSound("weapons/ric1.wav");
  cl_sfx_ric2 = S_PrecacheSound("weapons/ric2.wav");
  cl_sfx_ric3 = S_PrecacheSound("weapons/ric3.wav");
  cl_sfx_ric4 = S_PrecacheSound("weapons/ric4.wav");
  cl_sfx_ric5 = S_PrecacheSound("weapons/ric5.wav");
  cl_sfx_r_exp1 = S_PrecacheSound("weapons/explode3.wav");
  cl_sfx_r_exp2 = S_PrecacheSound("weapons/explode4.wav");
  cl_sfx_r_exp3 = S_PrecacheSound("weapons/explode5.wav");
  cl_sfx_pl_shell1 = S_PrecacheSound("player/pl_shell1.wav");
  cl_sfx_pl_shell2 = S_PrecacheSound("player/pl_shell2.wav");
  cl_sfx_pl_shell3 = S_PrecacheSound("player/pl_shell3.wav");
  cl_sfx_sshell1 = S_PrecacheSound("weapons/sshell1.wav");
  cl_sfx_sshell2 = S_PrecacheSound("weapons/sshell2.wav");
  cl_sfx_sshell3 = S_PrecacheSound("weapons/sshell3.wav");
  cl_sfx_wood1 = S_PrecacheSound("debris/wood1.wav");
  cl_sfx_wood2 = S_PrecacheSound("debris/wood2.wav");
  cl_sfx_wood3 = S_PrecacheSound("debris/wood3.wav");
  cl_sfx_metal1 = S_PrecacheSound("debris/metal1.wav");
  cl_sfx_metal2 = S_PrecacheSound("debris/metal2.wav");
  cl_sfx_metal3 = S_PrecacheSound("debris/metal3.wav");
  cl_sfx_glass1 = S_PrecacheSound("debris/glass1.wav");
  cl_sfx_glass2 = S_PrecacheSound("debris/glass2.wav");
  cl_sfx_glass3 = S_PrecacheSound("debris/glass3.wav");
  cl_sfx_concrete1 = S_PrecacheSound("debris/concrete1.wav");
  cl_sfx_concrete2 = S_PrecacheSound("debris/concrete2.wav");
                    /* Unresolved local var: model_t * pModel@[???] */
  cl_sfx_concrete3 = S_PrecacheSound("debris/concrete3.wav");
  cl_sfx_flesh1 = S_PrecacheSound("debris/flesh1.wav");
  cl_sfx_flesh2 = S_PrecacheSound("debris/flesh2.wav");
  cl_sfx_flesh3 = S_PrecacheSound("debris/flesh3.wav");
  cl_sfx_flesh4 = S_PrecacheSound("debris/flesh5.wav");
  cl_sfx_flesh5 = S_PrecacheSound("debris/flesh6.wav");
  cl_sfx_flesh6 = S_PrecacheSound("debris/flesh7.wav");
  cl_sfx_geiger1 = S_PrecacheSound("player/geiger1.wav");
  cl_sfx_geiger2 = S_PrecacheSound("player/geiger2.wav");
  cl_sfx_geiger3 = S_PrecacheSound("player/geiger3.wav");
  cl_sfx_geiger4 = S_PrecacheSound("player/geiger4.wav");
  cl_sfx_geiger5 = S_PrecacheSound("player/geiger5.wav");
  cl_sfx_geiger6 = S_PrecacheSound("player/geiger6.wav");
  pmVar1 = Mod_ForName("sprites/dot.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_dot = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/lgtning.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_lightning = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/white.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_white = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/animglow01.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_glow = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/muzzleflash1.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_muzzleflash[0] = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/muzzleflash2.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_muzzleflash[1] = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/muzzleflash3.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_muzzleflash[2] = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/richo1.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_ricochet = pmVar1;
                    /* Unresolved local var: model_t * pModel@[???] */
  pmVar1 = Mod_ForName("sprites/shellchrome.spr",true,false);
  Mod_MarkClient(pmVar1);
  cl_sprite_shell = pmVar1;
                    /* Unresolved local var: int i@[???] */
  Q_memset(gTempEnts,0,0x176830);
  puVar2 = (undefined *)0x37081c;
  do {
    *(undefined **)(puVar2 + -0xbd0) = puVar2;
    puVar2 = puVar2 + 0xbfc;
  } while (puVar2 != &DAT_004e6450);
  gTempEnts[499].next = (tempent_s *)0x0;
  gpTempEntFree = gTempEnts;
  gpTempEntActive = (TEMPENTITY *)0x0;
  return;
}


// CL_InterpolateEntity  @ 0013d260
void CL_InterpolateEntity(cl_entity_t *ent)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  vec_t in_XMM0_Da;
  float local_40;
  float local_3c;
  float local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: vec3_t target_origin@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: float targettime@[???] */
  fVar4 = (float)cl.time - ex_interp.value;
                    /* Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t0@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: int i0@[???]
                       Unresolved local var: int i1@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float at@[???]
                       Unresolved local var: int imod@[???] */
  uVar3 = ent->current_position;
  uVar7 = uVar3 & 0x3f;
  uVar5 = uVar3 - 1;
  uVar6 = uVar5 & 0x3f;
  if (fVar4 <= ent->ph[uVar7].animtime) {
    do {
      fVar1 = ent->ph[uVar5 & 0x3f].animtime;
      if (fVar1 == 0.0) break;
      if (fVar1 < fVar4) {
        uVar7 = uVar5 + 1 & 0x3f;
        uVar6 = uVar5 & 0x3f;
        break;
      }
      uVar5 = uVar5 - 1;
    } while (uVar3 - 0x3f != uVar5);
  }
  if (ent->ph + uVar7 == (position_history_t *)0x0) {
    local_20 = NAN;
    local_30 = NAN;
    local_24 = NAN;
    local_28 = NAN;
    local_34 = NAN;
    local_2c = in_XMM0_Da;
  }
  else if (ent->ph + uVar6 == (position_history_t *)0x0) {
    local_20 = NAN;
    local_30 = NAN;
    local_24 = NAN;
    local_28 = NAN;
    local_34 = NAN;
    local_2c = in_XMM0_Da;
  }
  else {
    fVar1 = ent->ph[uVar7].animtime;
    if (fVar1 == 0.0) {
      local_34 = ent->ph[uVar6].origin[0];
      local_30 = ent->ph[uVar6].origin[1];
      local_28 = ent->ph[uVar6].angles[0];
      local_24 = ent->ph[uVar6].angles[1];
      local_2c = ent->ph[uVar6].origin[2];
      local_20 = ent->ph[uVar6].angles[2];
    }
    else {
      fVar2 = ent->ph[uVar6].animtime;
      local_40 = ent->ph[uVar7].origin[0] - ent->ph[uVar6].origin[0];
      local_3c = ent->ph[uVar7].origin[1] - ent->ph[uVar6].origin[1];
      local_38 = ent->ph[uVar7].origin[2] - ent->ph[uVar6].origin[2];
      if (fVar2 == fVar1) {
        fVar4 = 1.0;
      }
      else {
        fVar4 = (fVar4 - fVar2) / (fVar1 - fVar2);
        if (fVar4 < 0.0) {
          fVar4 = 0.0;
        }
        else if (1.2 < fVar4) {
          fVar4 = 1.2;
        }
      }
      VectorMA(ent->ph[uVar6].origin,fVar4,&local_40,&local_34);
      InterpolateAngles(ent->ph[uVar6].angles,ent->ph[uVar7].angles,&local_28,fVar4);
    }
  }
  ent->angles[0] = local_28;
  ent->angles[1] = local_24;
  ent->angles[2] = local_20;
  ent->origin[0] = local_34;
  ent->origin[2] = local_2c;
  ent->origin[1] = local_30;
  return;
}


// CL_InterpolateModel  @ 00132bf0
int CL_InterpolateModel(cl_entity_t_conflict2 *e)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  position_history_t *local_38;
  position_history_t *local_34;
  float local_30;
  float local_2c;
  float local_28;
  vec_t local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???] */
  uVar1 = *(undefined4 *)&(e->curstate).field_0x14;
  uVar2 = *(undefined4 *)&(e->curstate).field_0x18;
  uVar3 = *(undefined4 *)&(e->curstate).field_0x1c;
  uVar4 = *(undefined4 *)&(e->curstate).field_0x20;
  uVar5 = *(undefined4 *)&(e->curstate).field_0x24;
  *(undefined4 *)&e->field_0xb48 = *(undefined4 *)&(e->curstate).field_0x10;
  *(undefined4 *)&e->field_0xb4c = uVar1;
  *(undefined4 *)&e->field_0xb50 = uVar2;
  *(undefined4 *)&e->field_0xb54 = uVar3;
  *(undefined4 *)&e->field_0xb58 = uVar4;
  *(undefined4 *)&e->field_0xb5c = uVar5;
  if (cls.timedemo != false) {
    return 1;
  }
  if (e->model == (model_s_conflict1 *)0x0) {
    return 1;
  }
  if ((e->model->name[0] == '*') && (r_bmodelinterp.value == 0.0)) {
    return 1;
  }
  if (cl.maxclients == 1) {
    return 1;
  }
  if ((cl.moving != 0) && (cl.onground == e->index)) {
    return 1;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???] */
  fVar8 = (float)cl.time - ex_interp.value;
  CL_FindInterpolationUpdates((cl_entity_t *)e,fVar8,&local_38,&local_34,(int *)0x0);
  if ((local_38 != (position_history_t *)0x0) && (local_34 != (position_history_t *)0x0)) {
    fVar6 = local_34->animtime;
    fVar8 = fVar8 - fVar6;
    if (0.0 <= fVar8) {
      if (fVar6 != 0.0) {
        fVar7 = local_38->animtime;
        iVar9 = VectorCompare(local_34->origin,vec3_origin);
        if ((iVar9 == 0) || (iVar9 = VectorCompare(local_38->origin,vec3_origin), iVar9 != 0)) {
          if (fVar6 == fVar7) {
            *(vec_t *)&e->field_0xb48 = local_38->origin[0];
            *(vec_t *)&e->field_0xb4c = local_38->origin[1];
            *(vec_t *)&e->field_0xb50 = local_38->origin[2];
            *(vec_t *)&e->field_0xb54 = local_38->angles[0];
            *(vec_t *)&e->field_0xb58 = local_38->angles[1];
            *(vec_t *)&e->field_0xb5c = local_38->angles[2];
            return 1;
          }
          local_30 = local_38->origin[0] - local_34->origin[0];
          local_2c = local_38->origin[1] - local_34->origin[1];
          local_28 = local_38->origin[2] - local_34->origin[2];
          fVar8 = fVar8 / (fVar7 - fVar6);
          if (fVar8 < 0.0) {
            return 0;
          }
          if (1.0 < fVar8) {
            fVar8 = 1.0;
          }
          VectorMA(local_34->origin,fVar8,&local_30,&local_24);
                    /* Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???]
                       Unresolved local var: float d@[???] */
          fVar6 = local_38->angles[0] - local_34->angles[0];
          if (180.0 < fVar6) {
            fVar6 = fVar6 - 360.0;
          }
          else if (fVar6 < -180.0) {
            fVar6 = fVar6 + 360.0;
          }
          local_18 = fVar6 * fVar8 + local_34->angles[0];
          fVar6 = local_38->angles[1] - local_34->angles[1];
          if (180.0 < fVar6) {
            fVar6 = fVar6 - 360.0;
          }
          else if (fVar6 < -180.0) {
            fVar6 = fVar6 + 360.0;
          }
          local_14 = fVar6 * fVar8 + local_34->angles[1];
          fVar6 = local_38->angles[2] - local_34->angles[2];
          if (fVar6 <= 180.0) {
            if (fVar6 < -180.0) {
              fVar6 = fVar6 + 360.0;
            }
          }
          else {
            fVar6 = fVar6 - 360.0;
          }
          local_10 = local_34->angles[2] + fVar6 * fVar8;
          COM_NormalizeAngles(&local_18);
          *(vec_t *)&e->field_0xb48 = local_24;
          *(undefined4 *)&e->field_0xb50 = local_1c;
          *(undefined4 *)&e->field_0xb4c = local_20;
          *(float *)&e->field_0xb58 = local_14;
          *(float *)&e->field_0xb54 = local_18;
          *(float *)&e->field_0xb5c = local_10;
          return 1;
        }
      }
      *(vec_t *)&e->field_0xb48 = local_38->origin[0];
      *(vec_t *)&e->field_0xb4c = local_38->origin[1];
      *(vec_t *)&e->field_0xb50 = local_38->origin[2];
      *(vec_t *)&e->field_0xb54 = local_38->angles[0];
      *(vec_t *)&e->field_0xb58 = local_38->angles[1];
      *(vec_t *)&e->field_0xb5c = local_38->angles[2];
    }
  }
  return 0;
}


// CL_InterpolateVector  @ 0013b3f0
void CL_InterpolateVector(float frac,vec_t *src,vec_t *dest,vec_t *output)

{
                    /* Unresolved local var: int i@[???] */
  *output = (*dest - *src) * frac + *src;
  output[1] = (dest[1] - src[1]) * frac + src[1];
  output[2] = (dest[2] - src[2]) * frac + src[2];
  return;
}


// CL_IsDevOverviewMode  @ 0013d560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_IsDevOverviewMode(void)

{
  if (dev_overview.value == 0.0) {
    return 0;
  }
  if (sv_cheats.value != 0.0) {
    return 1;
  }
  return (uint)(cls.spectator != false);
}


// CL_IsPlayerIndex  @ 00133620
qboolean CL_IsPlayerIndex(int index)

{
  if (0 < index) {
    return (uint)(index <= cl.maxclients);
  }
  return false;
}


// CL_IsSpectateOnly  @ 0013d540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_IsSpectateOnly(void)

{
  (*g_engdstAddrs.IsSpectateOnly)();
  return (uint)(cls.spectator != false);
}


// CL_KeepConnectionActive  @ 0014b770
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_KeepConnectionActive(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int in_GS_OFFSET;
  double dVar4;
  sizebuf_t local_44;
  byte local_30 [32];
  int local_10;
  
                    /* Unresolved local var: float flCurrentTime@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  dVar4 = Sys_FloatTime();
  fVar1 = (float)dVar4;
  if (fVar1 < CL_KeepConnectionActive::flLastKeepaliveTime) {
    CL_KeepConnectionActive::flLastKeepaliveTime = fVar1;
  }
  fVar2 = CL_KeepConnectionActive::flLastKeepaliveTime;
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte[32] szData@[???]
                       Unresolved local var: int iCount@[???] */
  if ((5.0 < fVar1 - CL_KeepConnectionActive::flLastKeepaliveTime) &&
     (fVar2 = fVar1, cls.state != ca_disconnected)) {
    local_44.data = local_30;
    local_44.cursize = 0;
    iVar3 = 0x20;
    local_44.buffername = "Client Keepalive";
    local_44.maxsize = 0x20;
    local_44.flags = 0;
    do {
      MSG_WriteByte(&local_44,1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    Netchan_Transmit(&cls.netchan,local_44.cursize,local_44.data);
  }
  CL_KeepConnectionActive::flLastKeepaliveTime = fVar2;
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_LerpPoint  @ 00136a50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float CL_LerpPoint(void)

{
  longdouble lVar1;
  longdouble lVar2;
  
                    /* Unresolved local var: double f@[???]
                       Unresolved local var: double frac@[???] */
  lVar1 = (longdouble)cl.mtime[0];
  if ((lVar1 - (longdouble)cl.mtime[1] != (longdouble)0) && (cls.timedemo == false)) {
    if ((longdouble)0.001 < (longdouble)ex_interp.value) {
      return (float)(((longdouble)cl.time - lVar1) / (longdouble)ex_interp.value);
    }
    return 1.0;
  }
                    /* Unresolved local var: float fgap@[???] */
  lVar2 = (longdouble)cl.time;
  cl.time = cl.mtime[0];
  if (cls.demoplayback != false) {
    cl.oldtime = (double)(lVar1 - (longdouble)(float)(lVar2 - (longdouble)cl.oldtime));
  }
  return 1.0;
}


// CL_LinkCustomEntity  @ 00134b20
void CL_LinkCustomEntity(cl_entity_t_conflict2 *ent,entity_state_t_conflict *state)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  cl_entity_t *pcVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  (ent->curstate).movetype = state->modelindex;
  if (ent->model->type != mod_sprite) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Bad model on beam ( not sprite ) ");
  }
  uVar8 = 0;
  do {
    uVar9 = uVar8;
    uVar6 = *(undefined4 *)((ent->curstate).controller + (uVar9 - 100));
    *(undefined4 *)((ent->prevstate).controller + (uVar9 - 0x68)) =
         *(undefined4 *)((ent->curstate).controller + (uVar9 - 0x68));
    *(undefined4 *)((ent->prevstate).controller + (uVar9 - 100)) = uVar6;
    uVar8 = uVar9 + 8;
  } while (uVar9 + 8 < 0x150);
  *(undefined4 *)((ent->prevstate).controller + (uVar9 - 0x60)) =
       *(undefined4 *)((ent->curstate).controller + (uVar9 - 0x60));
  pcVar7 = cl_entities;
  uVar6 = *(undefined4 *)&ent->field_0xb48;
  uVar1 = *(undefined4 *)&ent->field_0xb4c;
  uVar2 = *(undefined4 *)&ent->field_0xb50;
  (ent->latched).prevsequence = (ent->curstate).sequence;
  uVar3 = *(undefined4 *)&ent->field_0xb54;
  iVar10 = ent->index;
  uVar4 = *(undefined4 *)&ent->field_0xb58;
  uVar5 = *(undefined4 *)&ent->field_0xb5c;
  *(undefined4 *)&(ent->latched).field_0xc = uVar6;
  *(undefined4 *)&(ent->latched).field_0x10 = uVar1;
  *(undefined4 *)&(ent->latched).field_0x14 = uVar2;
  *(undefined4 *)&(ent->latched).field_0x18 = uVar3;
  *(undefined4 *)&(ent->latched).field_0x1c = uVar4;
  *(undefined4 *)&(ent->latched).field_0x20 = uVar5;
  iVar10 = ClientDLL_AddEntity(3,pcVar7 + iVar10);
  if (iVar10 != 0) {
    return;
  }
  Con_DPrintf("Overflow beam entity list!\n");
  return;
}


// CL_LinkPacketEntities  @ 00134c50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_LinkPacketEntities(void)

{
  entity_state_s *peVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  float fVar7;
  float fVar8;
  byte bVar9;
  int iVar10;
  undefined4 uVar11;
  cl_entity_t *pcVar12;
  int iVar13;
  uint uVar14;
  model_s *pmVar15;
  uint uVar16;
  int iVar17;
  dlight_t *pdVar18;
  cl_entity_t *ent;
  int iVar19;
  float fVar20;
  
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: dlight_t * dl@[???]
                       Unresolved local var: int pnum@[???]
                       Unresolved local var: float saveTime@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean parametric@[???] */
  iVar13 = cl.parsecountmod;
  iVar17 = cl.frames[cl.parsecountmod].packet_entities.num_entities;
  if (iVar17 < 1) {
    return;
  }
  iVar19 = 0;
LAB_00134c80:
  do {
    while( true ) {
      peVar1 = cl.frames[iVar13].packet_entities.entities + iVar19;
      iVar10 = peVar1->number;
      if ((((iVar10 < 1) || (cl.maxclients < iVar10)) && (peVar1->modelindex != 0)) &&
         ((peVar1->effects & 0x80) == 0)) break;
LAB_00134f10:
      iVar19 = iVar19 + 1;
      if (iVar17 <= iVar19) {
        return;
      }
    }
    ent = cl_entities + iVar10;
    uVar14 = 0;
    do {
      uVar16 = uVar14;
      uVar11 = *(undefined4 *)((int)peVar1->origin + (uVar16 - 0x10));
      *(undefined4 *)((int)(ent->curstate).origin + (uVar16 - 0xc)) =
           *(undefined4 *)((int)peVar1->origin + (uVar16 - 0xc));
      *(undefined4 *)((int)(ent->curstate).origin + (uVar16 - 0x10)) = uVar11;
      uVar14 = uVar16 + 8;
    } while (uVar16 + 8 < 0x150);
    *(undefined4 *)((int)(ent->curstate).origin + (uVar16 - 8)) =
         *(undefined4 *)((int)peVar1->origin + (uVar16 - 8));
    pmVar15 = ent->model;
    if (pmVar15 != (model_s *)0x0) {
      if (((ent->curstate).impacttime == 0.0) || ((ent->curstate).starttime == 0.0)) {
        if ((ent->curstate).animtime == (ent->prevstate).animtime) {
          iVar17 = VectorCompare((ent->curstate).origin,(ent->prevstate).origin);
          if (iVar17 == 0) {
            ent->lastmove = (float)((longdouble)0.2 + (longdouble)cl.time);
          }
          pmVar15 = ent->model;
        }
        if (((((ent->curstate).eflags & 1) == 0) ||
            (fVar20 = (ent->curstate).animtime, fVar20 == 0.0)) || (pmVar15->type != mod_studio)) {
LAB_00134f72:
          if (pmVar15->name[0] == '*') goto LAB_00135311;
          iVar17 = (ent->curstate).movetype;
          if ((iVar17 - 3U < 3) || (iVar17 == 0)) goto LAB_00135120;
        }
        else {
          if ((float)cl.time <= ent->lastmove) {
                    /* Unresolved local var: float animtime@[???] */
            (ent->curstate).movetype = 0;
            R_ResetLatched(ent,true);
            if (1.0 <= cl_fixmodelinterpolationartifacts.value) {
              (ent->curstate).animtime = fVar20;
              (ent->latched).prevanimtime = fVar20;
            }
            vVar2 = (ent->curstate).angles[0];
            vVar3 = (ent->curstate).angles[1];
            (ent->latched).prevorigin[0] = (ent->curstate).origin[0];
            pmVar15 = ent->model;
            vVar4 = (ent->curstate).origin[1];
            (ent->latched).prevangles[0] = vVar2;
            (ent->latched).prevangles[1] = vVar3;
            (ent->latched).prevorigin[1] = vVar4;
            (ent->latched).prevorigin[2] = (ent->curstate).origin[2];
            (ent->latched).prevangles[2] = (ent->curstate).angles[2];
            goto LAB_00134f72;
          }
          (ent->curstate).movetype = 4;
          if (pmVar15->name[0] == '*') goto LAB_00135311;
          iVar17 = 4;
LAB_00135120:
          if ((((g_bIsCStrike == 0) && (g_bIsCZero == 0)) || (iVar17 != 4)) ||
             (cls.netchan.remote_address.type == NA_LOOPBACK)) {
            vVar2 = (ent->curstate).origin[1];
            vVar3 = (ent->curstate).origin[2];
            vVar4 = (ent->curstate).angles[0];
            vVar5 = (ent->curstate).angles[1];
            vVar6 = (ent->curstate).angles[2];
            ent->origin[0] = (ent->curstate).origin[0];
            ent->origin[1] = vVar2;
            ent->origin[2] = vVar3;
            ent->angles[0] = vVar4;
            ent->angles[1] = vVar5;
            ent->angles[2] = vVar6;
            goto LAB_00134db2;
          }
        }
        iVar17 = CL_InterpolateModel((cl_entity_t_conflict2 *)ent);
        if (iVar17 != 0) {
          bVar9 = (byte)peVar1->entityType;
          goto joined_r0x00134fb0;
        }
      }
      else {
        if (pmVar15->name[0] == '*') {
LAB_00135311:
          CL_InterpolateModel((cl_entity_t_conflict2 *)ent);
        }
        else {
          CL_ParametricMove((cl_entity_t_conflict2 *)ent);
          vVar2 = (ent->curstate).origin[1];
          vVar3 = (ent->curstate).angles[1];
          ent->origin[0] = (ent->curstate).origin[0];
          ent->origin[1] = vVar2;
          vVar2 = (ent->curstate).angles[0];
          vVar4 = (ent->curstate).angles[2];
          ent->origin[2] = (ent->curstate).origin[2];
          ent->angles[0] = vVar2;
          ent->angles[1] = vVar3;
          ent->angles[2] = vVar4;
        }
LAB_00134db2:
        bVar9 = (byte)peVar1->entityType;
joined_r0x00134fb0:
        if ((bVar9 & 1) == 0) {
          (ent->curstate).movetype = peVar1->modelindex;
          if (ent->model->type != mod_sprite) {
                    /* WARNING: Subroutine does not return */
            Sys_Error("Bad model on beam ( not sprite ) ");
          }
          uVar14 = 0;
          do {
            uVar16 = uVar14;
            *(undefined4 *)((int)(ent->prevstate).origin + (uVar16 - 0x10)) =
                 *(undefined4 *)((int)(ent->curstate).origin + (uVar16 - 0x10));
            *(undefined4 *)((int)(ent->prevstate).origin + (uVar16 - 0xc)) =
                 *(undefined4 *)((int)(ent->curstate).origin + (uVar16 - 0xc));
            pcVar12 = cl_entities;
            uVar14 = uVar16 + 8;
          } while (uVar16 + 8 < 0x150);
          *(undefined4 *)((int)(ent->prevstate).origin + (uVar16 - 8)) =
               *(undefined4 *)((int)(ent->curstate).origin + (uVar16 - 8));
          vVar2 = ent->origin[0];
          vVar3 = ent->origin[1];
          vVar4 = ent->origin[2];
          (ent->latched).prevsequence = (ent->curstate).sequence;
          (ent->latched).prevorigin[0] = vVar2;
          iVar17 = ent->index;
          (ent->latched).prevorigin[1] = vVar3;
          (ent->latched).prevorigin[2] = vVar4;
          vVar2 = ent->angles[1];
          vVar3 = ent->angles[2];
          (ent->latched).prevangles[0] = ent->angles[0];
          (ent->latched).prevangles[1] = vVar2;
          (ent->latched).prevangles[2] = vVar3;
          iVar17 = ClientDLL_AddEntity(3,pcVar12 + iVar17);
          if (iVar17 == 0) {
            iVar19 = iVar19 + 1;
            Con_DPrintf("Overflow beam entity list!\n");
            iVar17 = cl.frames[iVar13].packet_entities.num_entities;
            if (iVar17 <= iVar19) {
              return;
            }
            goto LAB_00134c80;
          }
        }
        else {
          if (cl_numvisedicts == 0x200) {
            return;
          }
          if ((ent->curstate).aiment != 0) {
            (ent->curstate).movetype = 0xc;
          }
          if (((ent->curstate).effects & 0x20) != 0) {
            R_ResetLatched(ent,false);
          }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t distance@[???] */
          fVar20 = (ent->curstate).origin[0];
          fVar7 = (ent->curstate).origin[1];
          fVar8 = (ent->curstate).origin[2];
          if (((128.0 < fVar20 - (ent->prevstate).origin[0]) ||
              (128.0 < fVar7 - (ent->prevstate).origin[1])) ||
             (128.0 < fVar8 - (ent->prevstate).origin[2])) {
            vVar2 = (ent->curstate).angles[0];
            vVar3 = (ent->curstate).angles[1];
            vVar4 = (ent->curstate).angles[2];
            (ent->latched).prevorigin[0] = fVar20;
            (ent->latched).prevangles[0] = vVar2;
            (ent->latched).prevorigin[1] = fVar7;
            (ent->latched).prevangles[1] = vVar3;
            (ent->latched).prevorigin[2] = fVar8;
            (ent->latched).prevangles[2] = vVar4;
            CL_ResetPositions(ent);
          }
          uVar14 = (ent->curstate).effects;
          if ((uVar14 & 1) != 0) {
            (*efx.R_EntityParticles)(ent);
            uVar14 = (ent->curstate).effects;
          }
          if (ent->index != 1) {
            if ((uVar14 & 4) != 0) {
              pdVar18 = (*efx.CL_AllocDlight)(ent->index);
              pdVar18->origin[0] = ent->origin[0];
              pdVar18->origin[1] = ent->origin[1];
              fVar20 = ent->origin[2];
              (pdVar18->color).b = 0xfa;
              (pdVar18->color).g = 0xfa;
              (pdVar18->color).r = 0xfa;
              pdVar18->origin[2] = fVar20 + 16.0;
              fVar20 = RandomFloat(400.0,431.0);
              pdVar18->radius = fVar20;
              pdVar18->die = (float)((longdouble)0.001 + (longdouble)cl.time);
              uVar14 = (ent->curstate).effects;
            }
            if ((uVar14 & 8) != 0) {
              pdVar18 = (*efx.CL_AllocDlight)(ent->index);
              pdVar18->origin[0] = ent->origin[0];
              pdVar18->origin[1] = ent->origin[1];
              vVar2 = ent->origin[2];
              (pdVar18->color).b = 'd';
              (pdVar18->color).g = 'd';
              pdVar18->origin[2] = vVar2;
              (pdVar18->color).r = 'd';
              fVar20 = RandomFloat(200.0,231.0);
              pdVar18->radius = fVar20;
              pdVar18->die = (float)((longdouble)0.001 + (longdouble)cl.time);
              uVar14 = (ent->curstate).effects;
            }
          }
          if ((uVar14 & 0x40) != 0) {
                    /* Unresolved local var: dlight_t * dl@[???] */
            pdVar18 = (*efx.CL_AllocDlight)(peVar1->number);
            pdVar18->origin[0] = ent->origin[0];
            pdVar18->origin[1] = ent->origin[1];
            vVar2 = ent->origin[2];
            pdVar18->radius = 200.0;
            (pdVar18->color).b = 'd';
            pdVar18->origin[2] = vVar2;
            (pdVar18->color).g = 'd';
            (pdVar18->color).r = 'd';
            pdVar18->die = (float)((longdouble)0.001 + (longdouble)cl.time);
            (*efx.R_RocketFlare)(ent->origin);
          }
          CL_AddModelEffects(peVar1->number,(cl_entity_t_conflict2 *)ent,
                             (model_t_conflict *)ent->model);
          vVar2 = ent->origin[0];
          ent->attachment[0][0] = vVar2;
          vVar3 = ent->origin[1];
          ent->attachment[0][1] = vVar3;
          vVar4 = ent->origin[2];
          ent->attachment[0][2] = vVar4;
          ent->attachment[1][0] = vVar2;
          ent->attachment[1][1] = vVar3;
          ent->attachment[1][2] = vVar4;
          ent->attachment[2][0] = vVar2;
          ent->attachment[2][1] = vVar3;
          ent->attachment[2][2] = vVar4;
          ent->attachment[3][0] = vVar2;
          ent->attachment[3][1] = vVar3;
          ent->attachment[3][2] = vVar4;
          ClientDLL_AddEntity(0,ent);
        }
      }
      iVar17 = cl.frames[iVar13].packet_entities.num_entities;
      goto LAB_00134f10;
    }
    iVar19 = iVar19 + 1;
    Con_Printf("Tried to link edict %i without model\n",ent->index);
    iVar17 = cl.frames[iVar13].packet_entities.num_entities;
    if (iVar17 <= iVar19) {
      return;
    }
  } while( true );
}


// CL_LinkPlayers  @ 00135520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_LinkPlayers(void)

{
  int iVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  float fVar7;
  float fVar8;
  vec_t vVar9;
  uint uVar10;
  int iVar11;
  dlight_t *pdVar12;
  int iVar13;
  cl_entity_t *ent;
  int iVar14;
  int iVar15;
  float fVar16;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  iVar15 = 3000;
  iVar13 = 1;
  iVar14 = cl.parsecountmod * 0x4318 + 0xc6aa3c;
  do {
    iVar1 = iVar13 + -1;
    if ((*(int *)(iVar14 + 0xc) == cl.parsecount) &&
       ((((iVar11 = ClientDLL_IsThirdPerson(), iVar11 != 0 || (cl.viewentity + -1 != iVar1)) ||
         (chase_active.value != 0.0)) &&
        ((*(int *)(iVar14 + 0x28) != 0 && ((*(byte *)(iVar14 + 0x3c) & 0x80) == 0)))))) {
      if (0x1ff < cl_numvisedicts) break;
      ent = (cl_entity_t *)((int)(cl_entities->baseline).origin + iVar15 + -0x18);
      if (ent->index != iVar13) {
        ent->index = iVar13;
      }
      if (cl.playernum == iVar1) {
        vVar5 = *(vec_t *)(iVar14 + 0x10);
        vVar2 = (ent->curstate).angles[0];
        ent->origin[0] = vVar5;
        vVar6 = *(vec_t *)(iVar14 + 0x14);
        vVar3 = (ent->curstate).angles[1];
        ent->origin[1] = vVar6;
        vVar9 = *(vec_t *)(iVar14 + 0x18);
        vVar4 = (ent->curstate).angles[2];
        ent->origin[2] = vVar9;
        (ent->curstate).origin[0] = vVar5;
        (ent->curstate).origin[1] = vVar6;
        (ent->curstate).origin[2] = vVar9;
        (ent->prevstate).origin[0] = vVar5;
        (ent->prevstate).origin[1] = vVar6;
        (ent->prevstate).origin[2] = vVar9;
        ent->angles[0] = vVar2;
        ent->angles[1] = vVar3;
        ent->angles[2] = vVar4;
      }
      if (((ent->curstate).effects & 0x20) != 0) {
        R_ResetLatched(ent,false);
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t distance@[???] */
      fVar16 = (ent->curstate).origin[0];
      fVar7 = (ent->curstate).origin[1];
      fVar8 = (ent->curstate).origin[2];
      if (((128.0 < fVar16 - (ent->prevstate).origin[0]) ||
          (128.0 < fVar7 - (ent->prevstate).origin[1])) ||
         (128.0 < fVar8 - (ent->prevstate).origin[2])) {
        vVar2 = (ent->curstate).angles[0];
        vVar3 = (ent->curstate).angles[1];
        vVar4 = (ent->curstate).angles[2];
        (ent->latched).prevorigin[0] = fVar16;
        (ent->latched).prevangles[0] = vVar2;
        (ent->latched).prevorigin[1] = fVar7;
        (ent->latched).prevangles[1] = vVar3;
        (ent->latched).prevorigin[2] = fVar8;
        (ent->latched).prevangles[2] = vVar4;
        CL_ResetPositions(ent);
      }
      if (cl.playernum == iVar1) {
        ent->origin[0] = cl.simorg[0];
        ent->origin[1] = cl.simorg[1];
        ent->origin[2] = cl.simorg[2];
      }
      else {
        vVar2 = (ent->curstate).origin[1];
        vVar3 = (ent->curstate).origin[2];
        vVar4 = (ent->curstate).angles[0];
        vVar5 = (ent->curstate).angles[1];
        vVar6 = (ent->curstate).angles[2];
        ent->origin[0] = (ent->curstate).origin[0];
        ent->origin[1] = vVar2;
        ent->origin[2] = vVar3;
        ent->angles[0] = vVar4;
        ent->angles[1] = vVar5;
        ent->angles[2] = vVar6;
        CL_ComputePlayerOrigin(ent);
      }
      if (cl.viewentity + -1 != iVar1) {
        uVar10 = (ent->curstate).effects;
        if ((uVar10 & 4) != 0) {
          pdVar12 = (*efx.CL_AllocDlight)(4);
          pdVar12->origin[0] = ent->origin[0];
          pdVar12->origin[1] = ent->origin[1];
          fVar16 = ent->origin[2];
          (pdVar12->color).b = 0xfa;
          (pdVar12->color).g = 0xfa;
          (pdVar12->color).r = 0xfa;
          pdVar12->origin[2] = fVar16 + 16.0;
          fVar16 = RandomFloat(400.0,431.0);
          pdVar12->radius = fVar16;
          pdVar12->die = (float)((longdouble)0.001 + (longdouble)cl.time);
          uVar10 = (ent->curstate).effects;
        }
        if ((uVar10 & 8) != 0) {
          pdVar12 = (*efx.CL_AllocDlight)(4);
          pdVar12->origin[0] = ent->origin[0];
          pdVar12->origin[1] = ent->origin[1];
          vVar2 = ent->origin[2];
          (pdVar12->color).b = 'd';
          (pdVar12->color).g = 'd';
          pdVar12->origin[2] = vVar2;
          (pdVar12->color).r = 'd';
          fVar16 = RandomFloat(200.0,231.0);
          pdVar12->radius = fVar16;
          pdVar12->die = (float)((longdouble)0.001 + (longdouble)cl.time);
        }
      }
      vVar2 = ent->origin[0];
      ent->attachment[0][0] = vVar2;
      vVar3 = ent->origin[1];
      ent->attachment[0][1] = vVar3;
      vVar4 = ent->origin[2];
      ent->attachment[0][2] = vVar4;
      ent->attachment[1][0] = vVar2;
      ent->attachment[1][1] = vVar3;
      ent->attachment[1][2] = vVar4;
      ent->attachment[2][0] = vVar2;
      ent->attachment[2][1] = vVar3;
      ent->attachment[2][2] = vVar4;
      ent->attachment[3][0] = vVar2;
      ent->attachment[3][1] = vVar3;
      ent->attachment[3][2] = vVar4;
      ClientDLL_AddEntity(1,ent);
    }
    iVar13 = iVar13 + 1;
    iVar14 = iVar14 + 0x154;
    iVar15 = iVar15 + 3000;
  } while (iVar13 != 0x21);
  CL_PlayerFlashlight();
  return;
}


// CL_ListCachedServers_f  @ 00144560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ListCachedServers_f(void)

{
  int iVar1;
  uint slot;
  server_cache_t *psVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: server_cache_t * p@[???] */
  if (num_servers == 0) {
    Con_Printf("No local servers in list.\nTry \'slist\' to search again.\n");
    return;
  }
  psVar2 = cached_servers;
  slot = 0;
  iVar1 = num_servers;
  if (0 < num_servers) {
    do {
      while (psVar2->inuse == 0) {
        slot = slot + 1;
        psVar2 = psVar2 + 1;
        if (iVar1 <= (int)slot) {
          return;
        }
      }
      Con_Printf("------------------\n");
                    /* Unresolved local var: server_cache_t * p@[???]
                       Unresolved local var: char * pszDedicated@[???]
                       Unresolved local var: char * pszOS@[???]
                       Unresolved local var: char * pszVisibility@[???]
                       Unresolved local var: char * pszSecure@[???] */
      if (slot < 0x10) {
        CL_PrintCachedServer(slot);
      }
      slot = slot + 1;
      psVar2 = psVar2 + 1;
      iVar1 = num_servers;
    } while ((int)slot < num_servers);
  }
  return;
}


// CL_ListDemo_f  @ 0013ff50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ListDemo_f(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int in_GS_OFFSET;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  double dVar10;
  int iVar11;
  double dVar12;
  char *pcStack_36c;
  void *pvStack_368;
  undefined4 uStack_364;
  undefined4 uStack_360;
  undefined4 uStack_35c;
  undefined2 uStack_358;
  undefined1 uStack_356;
  char local_344 [260];
  char local_240 [8];
  undefined4 local_238;
  undefined4 local_234;
  undefined1 local_230 [260];
  undefined1 local_12c [264];
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: demoheader_t header@[???]
                       Unresolved local var: demodirectory_t directory@[???]
                       Unresolved local var: demoentry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[32] type@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    if ((cls.demorecording == false) && (cls.demoplayback == false)) {
      pcVar1 = Cmd_Argv(1);
      snprintf(local_344,0x100,"%s",pcVar1);
      COM_DefaultExtension(local_344,".dem");
      Con_Printf("Demo contents for %s.\n",local_344);
      cls.demofile = FS_Open(local_344,"rb");
      if (cls.demofile == (FileHandle_t)0x0) {
        Con_Printf("ERROR: couldn\'t open.\n");
      }
      else {
        FS_Read(local_240,0x220,1,cls.demofile);
        iVar2 = Q_strncmp(local_240,"HLDEMO",6);
        if (iVar2 == 0) {
          Con_Printf("Demo file protocols %iN:%iD\nServer protocols at %iN:%iD\n",local_234,
                     local_238,0x30,5);
          Con_Printf("Map name :  %s\n",local_230);
          Con_Printf("Game .dll:  %s\n",local_12c);
                    /* catch() { ... } // from try @ 00140177 with catch @ 00140160
                       catch() { ... } // from try @ 001401bd with catch @ 00140160 */
          FS_Seek(cls.demofile,local_24,FILESYSTEM_SEEK_HEAD);
          FS_Read(&pcStack_36c,4,1,cls.demofile);
          if (pcStack_36c + -1 < (char *)0x400) {
            pvStack_368 = Mem_Malloc((int)pcStack_36c * 0x5c);
            FS_Read(pvStack_368,(int)pcStack_36c * 0x5c,1,cls.demofile);
            Con_Printf("\n");
            if (0 < (int)pcStack_36c) {
              iVar2 = 0;
              piVar5 = (int *)0x0;
              do {
                piVar4 = (int *)((int)pvStack_368 + iVar2);
                if (*piVar4 == 0) {
                  uStack_364 = 0x72617453;
                  uStack_360 = 0x65732074;
                  uStack_35c = 0x6e656d67;
                  uStack_358 = 0x74;
                }
                else {
                  uStack_364 = 0x6d726f4e;
                  uStack_360 = 0x73206c61;
                  uStack_35c = 0x656d6765;
                  uStack_358 = 0x746e;
                  uStack_356 = 0;
                }
                piVar7 = piVar4 + 1;
                piVar5 = (int *)((int)piVar5 + 1);
                dVar12 = (double)((float)piVar4[0x16] * 0.0009765625);
                iVar11 = piVar4[0x14];
                dVar10 = (double)(float)piVar4[0x13];
                piVar6 = piVar5;
                puVar8 = &uStack_364;
                piVar9 = piVar7;
                Con_Printf("%i:  %s\n  \"%20s\"\nTime:  %.2f s.\nFrames:  %i\nSize:  %.2fK\n",piVar5
                           ,&uStack_364,piVar7,dVar10,iVar11,dVar12);
                uVar3 = 0;
                if (piVar4[0x11] != 0) {
                  Con_Printf("  Flags:\n",piVar6,puVar8,piVar9,dVar10,iVar11,dVar12);
                  uVar3 = piVar4[0x11];
                  if ((uVar3 & 1) != 0) {
                    Con_Printf("     Title \"%s\"\n",piVar7,puVar8,piVar9,dVar10,iVar11,dVar12);
                    uVar3 = piVar4[0x11];
                    piVar6 = piVar7;
                  }
                  if ((uVar3 & 4) != 0) {
                    piVar6 = (int *)piVar4[0x12];
                    Con_Printf("     Play %i\n",piVar6,puVar8,piVar9,dVar10,iVar11,dVar12);
                    uVar3 = piVar4[0x11];
                  }
                  if ((uVar3 & 8) != 0) {
                    Con_Printf("     Fade in slow\n",piVar6,puVar8,piVar9,dVar10,iVar11,dVar12);
                    uVar3 = piVar4[0x11];
                  }
                }
                if ((uVar3 & 0x10) != 0) {
                  Con_Printf("     Fade in fast\n",piVar6,puVar8,piVar9,dVar10,iVar11,dVar12);
                  uVar3 = piVar4[0x11];
                }
                if ((uVar3 & 0x20) != 0) {
                  Con_Printf("     Fade out slow\n",piVar6,puVar8,piVar9,dVar10,iVar11,dVar12);
                  uVar3 = piVar4[0x11];
                }
                if ((uVar3 & 0x40) != 0) {
                  Con_Printf("     Fade out fast\n",piVar6,puVar8,piVar9,dVar10,iVar11,dVar12);
                }
                iVar2 = iVar2 + 0x5c;
                Con_Printf("\n");
              } while ((int)piVar5 < (int)pcStack_36c);
            }
            FS_Close(cls.demofile);
            cls.demofile = (FileHandle_t)0x0;
            Mem_Free(pvStack_368);
            goto LAB_0013ff8a;
          }
          pcVar1 = "ERROR: demo had bogus # of directory entries:  %i\n";
        }
        else {
          pcVar1 = "%s is not a demo file\n";
          pcStack_36c = local_344;
        }
        Con_Printf(pcVar1,pcStack_36c);
        FS_Close(cls.demofile);
        cls.demofile = (FileHandle_t)0x0;
      }
    }
    else {
      Con_Printf("Listdemo only available when not running or recording.\n");
    }
  }
LAB_0013ff8a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Listen  @ 001468f0
void CL_Listen(char *address)

{
  netadr_t a;
  netadr_t addr;
  netadr_t adr;
  _func_short_short *p_Var1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  
  if (cls.demoplayback != false) {
    CL_StopPlayback();
  }
  CL_Disconnect();
  Q_memset(msg_buckets,0,0x100);
  Q_memset(total_data,0,0x100);
  cls.connect_retry = 0;
  gfExtendedError = false;
  NET_Config(true);
  adr.ip[0] = cls.connect_stream.ip[0];
  adr.ip[1] = cls.connect_stream.ip[1];
  adr.ip[2] = cls.connect_stream.ip[2];
  adr.ip[3] = cls.connect_stream.ip[3];
  adr.type = cls.connect_stream.type;
  adr.ipx[0] = cls.connect_stream.ipx[0];
  adr.ipx[1] = cls.connect_stream.ipx[1];
  adr.ipx[2] = cls.connect_stream.ipx[2];
  adr.ipx[3] = cls.connect_stream.ipx[3];
  adr.ipx[4] = cls.connect_stream.ipx[4];
  adr.ipx[5] = cls.connect_stream.ipx[5];
  adr.ipx[6] = cls.connect_stream.ipx[6];
  adr.ipx[7] = cls.connect_stream.ipx[7];
  adr.ipx[8] = cls.connect_stream.ipx[8];
  adr.ipx[9] = cls.connect_stream.ipx[9];
  adr.port = cls.connect_stream.port;
  Netchan_Setup(NS_MULTICAST,&cls.netchan,adr,-1,&cls,CL_GetFragmentSize);
  NET_FlushSocket(NS_MULTICAST);
  p_Var1 = BigShort;
  cls.passive = true;
  if (cls.connect_stream.port == 0) {
    iVar4 = Q_atoi("27025");
    uVar2 = (*p_Var1)((short)iVar4);
    cls.connect_stream.port = uVar2;
  }
  addr.ip[0] = cls.connect_stream.ip[0];
  addr.ip[1] = cls.connect_stream.ip[1];
  addr.ip[2] = cls.connect_stream.ip[2];
  addr.ip[3] = cls.connect_stream.ip[3];
  addr.type = cls.connect_stream.type;
  addr.ipx[0] = cls.connect_stream.ipx[0];
  addr.ipx[1] = cls.connect_stream.ipx[1];
  addr.ipx[2] = cls.connect_stream.ipx[2];
  addr.ipx[3] = cls.connect_stream.ipx[3];
  addr.ipx[4] = cls.connect_stream.ipx[4];
  addr.ipx[5] = cls.connect_stream.ipx[5];
  addr.ipx[6] = cls.connect_stream.ipx[6];
  addr.ipx[7] = cls.connect_stream.ipx[7];
  addr.ipx[8] = cls.connect_stream.ipx[8];
  addr.ipx[9] = cls.connect_stream.ipx[9];
  addr.port = cls.connect_stream.port;
  NET_JoinGroup(cls.netchan.sock,addr);
  a.ip[0] = cls.connect_stream.ip[0];
  a.ip[1] = cls.connect_stream.ip[1];
  a.ip[2] = cls.connect_stream.ip[2];
  a.ip[3] = cls.connect_stream.ip[3];
  a.type = cls.connect_stream.type;
  a.ipx[0] = cls.connect_stream.ipx[0];
  a.ipx[1] = cls.connect_stream.ipx[1];
  a.ipx[2] = cls.connect_stream.ipx[2];
  a.ipx[3] = cls.connect_stream.ipx[3];
  a.ipx[4] = cls.connect_stream.ipx[4];
  a.ipx[5] = cls.connect_stream.ipx[5];
  a.ipx[6] = cls.connect_stream.ipx[6];
  a.ipx[7] = cls.connect_stream.ipx[7];
  a.ipx[8] = cls.connect_stream.ipx[8];
  a.ipx[9] = cls.connect_stream.ipx[9];
  a.port = cls.connect_stream.port;
  pcVar3 = NET_AdrToString(a);
  Con_Printf("Joining multicast group %s ...\n",pcVar3);
  NET_ClearLagData(true,false);
  cl.validsequence = 0;
  cl.delta_sequence = -1;
  cls.signon = 0;
  cls.connect_time = realtime;
  cls.state = ca_connecting;
  cls.demonum = -1;
  cls.nextcmdtime = (float)realtime;
  cls.lastoutgoingcommand = -1;
  return;
}


// CL_Listen  @ 00146b00
void CL_Listen(char *address)

{
  if (address != (char *)0x0) {
    Net_StringToAdr(address,&cls.connect_stream);
    cls.connect_stream.type = NA_IP;
    if ((byte)(cls.connect_stream.ip[0] + 0x20) < 0x10) {
      CL_Listen(address);
      return;
    }
    Con_Printf("%s is not a class D IP.\n",address);
  }
  return;
}


// CL_Listen_f  @ 00146b60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Listen_f(void)

{
  int iVar1;
  char *s;
  char *in_stack_00000004;
  
                    /* Unresolved local var: char * server@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("usage: listen <IP>\n");
  }
  else {
    s = Cmd_Args();
    if (s != (char *)0x0) {
      cls.challenge = 0;
      Net_StringToAdr(s,&cls.connect_stream);
      cls.connect_stream.type = NA_IP;
      if ((byte)(cls.connect_stream.ip[0] + 0x20) < 0x10) {
        CL_Listen(in_stack_00000004);
        return;
      }
      Con_Printf("%s is not a class D IP.\n",s);
      return;
    }
  }
  return;
}


// CL_LoadModel  @ 001676f0
model_s * CL_LoadModel(char *modelname,int *index)

{
  model_s *s2;
  int index_00;
  int iVar1;
  model_t *pmVar2;
  
                    /* Unresolved local var: int i@[???] */
  (*g_engdstAddrs.CL_LoadModel)(&modelname,&index);
  index_00 = 1;
  s2 = cl.model_precache[1];
                    /* Unresolved local var: model_t * mod@[???] */
  while( true ) {
    if (s2 == (model_s *)0x0) {
      if (index == (int *)0x0) {
        return (model_s *)0x0;
      }
      *index = -1;
      return (model_s *)0x0;
    }
    iVar1 = Q_stricmp(modelname,s2->name);
    if (iVar1 == 0) break;
    s2 = cl.model_precache[index_00 + 1];
    index_00 = index_00 + 1;
  }
  pmVar2 = CL_GetModelByIndex(index_00);
  if (index == (int *)0x0) {
    return pmVar2;
  }
  *index = index_00;
  return pmVar2;
}


// CL_LookupSound  @ 000df9f0
sfx_s * CL_LookupSound(char *pName)

{
  sfx_s *s2;
  int iVar1;
  sfx_t *psVar2;
  sfx_s **ppsVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: sfx_t * pSound@[???] */
  ppsVar3 = cl.sound_precache;
  do {
    s2 = *ppsVar3;
    if (s2 != (sfx_s *)0x0) {
      iVar1 = Q_strcmp(pName,s2->name);
      if (iVar1 == 0) {
        return s2;
      }
    }
    ppsVar3 = ppsVar3 + 1;
  } while ((consistency_t *)ppsVar3 != cl.consistency_list);
  psVar2 = S_PrecacheSound(pName);
  return psVar2;
}


// CL_MapLocalizationString  @ 000be040
char * CL_MapLocalizationString(char *pszBSPName)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  do {
    iVar1 = Q_strlen(gTitleComments[iVar2].pBSPName);
    iVar1 = Q_strnicmp(pszBSPName,gTitleComments[iVar2].pBSPName,iVar1);
    if (iVar1 == 0) {
      return gTitleComments[iVar2].pTitleName;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x54);
  return pszBSPName;
}


// CL_MarkMapAsUsingHTTPDownload  @ 00127640
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_MarkMapAsUsingHTTPDownload(void)

{
  char *serverMapName;
  
                    /* Unresolved local var: char * serverMapName@[???] */
  serverMapName = DL_SharedVarArgs("%s:%s",cls.servername,0xde4738);
  DownloadManager::MarkMapAsDownloadedFromServer(&TheDownloadManager,serverMapName);
  return;
}


// CL_Move  @ 0014a220
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Move(void)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  uint uVar6;
  qboolean qVar7;
  int iVar8;
  qboolean qVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  usercmd_t *puVar13;
  uint uVar14;
  int iVar15;
  int c;
  int in_GS_OFFSET;
  bool bVar16;
  con_nprint_s local_87c;
  sizebuf_t local_868;
  usercmd_t local_854;
  byte local_820 [2048];
  int local_20;
  
  dVar5 = realtime;
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: usercmd_t * cmd@[???]
                       Unresolved local var: usercmd_t * from@[???]
                       Unresolved local var: usercmd_t * to@[???]
                       Unresolved local var: usercmd_t cmdbaseline@[???]
                       Unresolved local var: int checksumposition@[???]
                       Unresolved local var: int numbackup@[???]
                       Unresolved local var: int numcmds@[???]
                       Unresolved local var: int newcmds@[???]
                       Unresolved local var: int cmdnumber@[???]
                       Unresolved local var: cmd_t * pcmd@[???]
                       Unresolved local var: int active@[???]
                       Unresolved local var: int packet_loss@[???]
                       Unresolved local var: double dmsec@[???]
                       Unresolved local var: int msec@[???] */
  fVar4 = cl_cmdbackup.value;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state < ca_connected) goto LAB_0014a5a0;
  if (cls.state == ca_connected) {
    if (cls.passive == false) {
      Netchan_Transmit(&cls.netchan,0,(byte *)0x0);
    }
    goto LAB_0014a5a0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frm@[DW_OP_reg0(EAX)]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int lost@[???] */
  if (cls.packet_loss_recalc_time <= realtime) {
    cls.packet_loss_recalc_time = realtime + 1.0;
    uVar6 = (cls.netchan.incoming_sequence - CL_UPDATE_BACKUP) + 1;
    if (cls.netchan.incoming_sequence < (int)uVar6) {
      cls.packet_loss = 0.0;
    }
    else {
      iVar10 = 0;
      do {
        while (cl.frames[uVar6 & CL_UPDATE_MASK].receivedtime != -1.0) {
          uVar6 = uVar6 + 1;
          if (cls.netchan.incoming_sequence + 1U == uVar6) goto LAB_0014a2dc;
        }
        uVar6 = uVar6 + 1;
        iVar10 = iVar10 + 1;
      } while (cls.netchan.incoming_sequence + 1U != uVar6);
LAB_0014a2dc:
      cls.packet_loss =
           ((float)iVar10 * 100.0) /
           (float)(cls.netchan.incoming_sequence -
                  (cls.netchan.incoming_sequence - CL_UPDATE_BACKUP));
    }
  }
  local_868.data = local_820;
  local_868.maxsize = 0x800;
  uVar14 = CL_UPDATE_MASK & cls.netchan.outgoing_sequence;
  cl.commands[uVar14].processedfuncs = false;
  cl.commands[uVar14].heldback = false;
  cl.commands[uVar14].sendsize = 0;
  cl.commands[uVar14].senttime = (float)dVar5;
  local_868.cursize = 0;
  cl.commands[uVar14].receivedtime = -1.0;
  puVar13 = &cl.commands[uVar14].cmd;
  local_868.buffername = "Client Move";
  local_868.flags = 0;
  Q_memset(puVar13,0,0x34);
  bVar16 = cls.signon == 2;
  CL_SetSolidEntities();
  CL_PushPMStates();
  CL_SetSolidPlayers(cl.playernum);
  ClientDLL_CreateMove((float)host_frametime,puVar13,(uint)bVar16);
  CL_PopPMStates();
  CL_ComputeClientInterpolationAmount(puVar13);
  cl.commands[uVar14].cmd.lightlevel = (byte)cl.light_level;
  MSG_WriteByte(&local_868,2);
  iVar10 = local_868.cursize;
  MSG_WriteByte(&local_868,0);
  MSG_WriteByte(&local_868,0);
  uVar6 = (uint)cls.packet_loss;
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  uVar12 = 100;
  if ((int)uVar6 < 0x65) {
    uVar12 = uVar6;
  }
  qVar7 = Voice_GetLoopback();
  if (qVar7 != 0) {
    uVar12 = uVar12 | 0x80;
  }
  MSG_WriteByte(&local_868,uVar12);
  iVar8 = (int)((float)host_frametime * 1000.0);
  fVar3 = (float)iVar8;
  fVar2 = ((float)host_frametime * 1000.0 - fVar3) + (float)frametime_remainder;
  if (1.0 < fVar2) {
    fVar2 = fVar2 - 1.0;
    iVar8 = iVar8 + 1;
    fVar3 = (float)iVar8;
  }
  frametime_remainder = (double)fVar2;
  bVar11 = (byte)iVar8;
  if (255.0 < fVar3) {
    bVar11 = 0xff;
    iVar8 = 0xff;
  }
  cl.commands[uVar14].cmd.msec = bVar11;
  uVar6 = 0;
  do {
    uVar12 = uVar6 + 4;
    *(undefined4 *)((int)cl.cmd.viewangles + (uVar6 - 4)) =
         *(undefined4 *)(uVar14 * 0x4c + 0xd77024 + uVar6);
    uVar6 = uVar12;
  } while (uVar12 < 0x34);
  if ((cls.passive != false) || (cls.demoplayback != false)) goto LAB_0014a5a0;
  CL_PredictMove(false);
  if (cl_cmdrate.value < 10.0) {
    Cvar_Set("cl_cmdrate","10");
  }
  if (((((cls.spectator != false) && (cls.state == ca_active)) &&
       (cl.delta_sequence == cl.validsequence)) &&
      ((cls.demorecording == false || (cls.demowaiting == false)))) &&
     ((float)realtime < cls.nextcmdtime + 1.0)) goto LAB_0014a5a0;
  if ((iVar8 < 1) ||
     (((cl.maxclients != 1 &&
       ((cls.netchan.remote_address.type != NA_LOOPBACK || (host_limitlocal.value != 0.0)))) &&
      (((float)realtime < cls.nextcmdtime ||
       (qVar9 = Netchan_CanPacket(&cls.netchan), qVar9 == false)))))) {
    uVar6 = CL_UPDATE_MASK & cls.netchan.outgoing_sequence;
    cls.netchan.outgoing_sequence = cls.netchan.outgoing_sequence + 1;
    cl.commands[uVar6].heldback = true;
  }
  else {
                    /* Unresolved local var: int outgoing_sequence@[???] */
    if (cl_cmdrate.value <= 0.0) {
      cls.nextcmdtime = (float)realtime;
    }
    else {
      cls.nextcmdtime = 1.0 / cl_cmdrate.value + (float)realtime;
    }
    if (cls.lastoutgoingcommand == -1) {
      cls.lastoutgoingcommand = cls.netchan.outgoing_sequence;
    }
    if (cls.spectator == false) {
      iVar8 = (int)fVar4;
      if (8 < iVar8) {
        iVar8 = 8;
      }
      iVar15 = 0;
      if (-1 < iVar8) {
        iVar15 = iVar8;
      }
      MSG_WriteByte(&local_868,iVar15);
      iVar8 = cls.netchan.outgoing_sequence - cls.lastoutgoingcommand;
      if (cls.build_num < 0x1753) {
        c = 0x10;
        if (iVar8 < 0x11) {
          c = iVar8;
        }
      }
      else {
        c = 0x3e - iVar15;
        if (iVar8 <= 0x3e - iVar15) {
          c = iVar8;
        }
      }
      iVar15 = c + -1 + iVar15;
      MSG_WriteByte(&local_868,c);
      Q_memset(&local_854,0,0x34);
      puVar13 = &local_854;
      if (-1 < iVar15) {
        do {
          uVar6 = cls.netchan.outgoing_sequence - iVar15;
          iVar15 = iVar15 + -1;
          uVar6 = uVar6 & CL_UPDATE_MASK;
          MSG_WriteUsercmd(&local_868,&cl.commands[uVar6].cmd,puVar13);
          puVar13 = &cl.commands[uVar6].cmd;
        } while (iVar15 != -1);
      }
      uVar6 = iVar10 + 1;
      if ((int)(local_868.cursize - uVar6) < 0x100) {
        bVar11 = ((char)local_868.cursize + -1) - (char)uVar6;
      }
      else {
        bVar11 = 0xff;
      }
      local_868.data[iVar10] = bVar11;
      pbVar1 = local_868.data + uVar6;
      bVar11 = COM_BlockSequenceCRCByte
                         (local_868.data + iVar10 + 2,~uVar6 + local_868.cursize,
                          cls.netchan.outgoing_sequence);
      *pbVar1 = bVar11;
      iVar8 = 0xff;
      if ((int)(local_868.cursize - uVar6) < 0x100) {
        iVar8 = (local_868.cursize - uVar6) + -1;
      }
      COM_Munge(local_868.data + iVar10 + 2,iVar8,cls.netchan.outgoing_sequence);
    }
    else {
      SZ_Clear(&local_868);
    }
    if ((((cls.state != ca_active) || (cls.signon != 2)) ||
        (cls.netchan.outgoing_sequence - cls.netchan.incoming_acknowledged < CL_UPDATE_MASK)) ||
       (realtime - (double)cls.netchan.last_received <= 15.0)) {
      if (((cl.validsequence == 0) || (cl_nodelta.value != 0.0)) ||
         ((cls.state != ca_active || ((cls.demorecording != false && (cls.demowaiting != false))))))
      goto LAB_0014a6d4;
      cl.delta_sequence = cl.validsequence;
      MSG_WriteByte(&local_868,4);
      MSG_WriteByte(&local_868,cl.validsequence & 0xff);
    }
    else {
                    /* Unresolved local var: con_nprint_t np@[???] */
      local_87c.index = 0;
      local_87c.time_to_live = 1.0;
      local_87c.color[0] = 1.0;
      local_87c.color[1] = 0.2;
      local_87c.color[2] = 0.0;
      Con_NXPrintf(&local_87c,"WARNING:  Connection Problem");
      cl.validsequence = 0;
LAB_0014a6d4:
      cl.delta_sequence = -1;
    }
    cls.lastoutgoingcommand = cls.netchan.outgoing_sequence;
    cl.commands[cls.netchan.outgoing_sequence & CL_UPDATE_MASK].sendsize = local_868.cursize;
    CL_AddVoiceToDatagram(false);
    if (cls.datagram.cursize <= local_868.maxsize - local_868.cursize) {
      Q_memcpy(local_868.data + local_868.cursize,cls.datagram.data,cls.datagram.cursize);
      local_868.cursize = cls.datagram.cursize + local_868.cursize;
    }
    cls.datagram.cursize = 0;
    Netchan_Transmit(&cls.netchan,local_868.cursize,local_868.data);
  }
  Netchan_UpdateProgress(&cls.netchan);
LAB_0014a5a0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_MoveAiments  @ 001369d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_MoveAiments(void)

{
  cl_entity_t **ppcVar1;
  cl_entity_t *pcVar2;
  int iVar3;
  cl_entity_t *pcVar4;
  cl_entity_t **ppcVar5;
  
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: int i@[???] */
  pcVar4 = cl_entities;
  if (0 < cl_numvisedicts) {
    ppcVar5 = cl_visedicts;
    ppcVar1 = cl_visedicts + cl_numvisedicts;
    do {
      while( true ) {
        pcVar2 = *ppcVar5;
        iVar3 = (pcVar2->curstate).aiment;
        if ((iVar3 == 0) || ((pcVar2->curstate).movetype != 0xc)) break;
        ppcVar5 = ppcVar5 + 1;
        pcVar2->origin[0] = pcVar4[iVar3].origin[0];
        pcVar2->origin[1] = pcVar4[iVar3].origin[1];
        pcVar2->origin[2] = pcVar4[iVar3].origin[2];
        if (ppcVar5 == ppcVar1) {
          return;
        }
      }
      ppcVar5 = ppcVar5 + 1;
    } while (ppcVar5 != ppcVar1);
  }
  return;
}


// CL_MoveSpectatorCamera  @ 0013d860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_MoveSpectatorCamera(void)

{
  uint local_2c;
  double local_14 [2];
  
                    /* Unresolved local var: double time@[???]
                       Unresolved local var: qboolean added@[???] */
  local_14[0] = cl.time;
  if ((cls.state == ca_active) && (cls.spectator != false)) {
    CL_SetUpPlayerPrediction(false,true);
    CL_SetSolidPlayers(cl.playernum);
    local_2c = (uint)(longlong)ROUND((float)local_14[0] * 100.0);
    CL_RunUsercmd(&spectatorState,&spectatorState,&cl.cmd,true,local_14,local_2c);
    cl.simvel[0] = spectatorState.client.velocity[0];
    cl.simvel[1] = spectatorState.client.velocity[1];
    cl.simvel[2] = spectatorState.client.velocity[2];
    cl.simorg[0] = (vec_t)spectatorState.playerstate._16_4_;
    cl.simorg[1] = (vec_t)spectatorState.playerstate._20_4_;
    cl.simorg[2] = (vec_t)spectatorState.playerstate._24_4_;
    cl.punchangle[0] = spectatorState.client.punchangle[0];
    cl.punchangle[1] = spectatorState.client.punchangle[1];
    cl.punchangle[2] = spectatorState.client.punchangle[2];
    cl.viewheight[0] = spectatorState.client.view_ofs[0];
    cl.viewheight[1] = spectatorState.client.view_ofs[1];
    cl.viewheight[2] = spectatorState.client.view_ofs[2];
  }
  return;
}


// CL_MoveToOnHandList  @ 00146080
void CL_MoveToOnHandList(resource_t *pResource)

{
  if (pResource != (resource_t *)0x0) {
    CL_RemoveFromResourceList(pResource);
    CL_AddToResourceList(pResource,&cl.resourcesonhand);
    return;
  }
  Con_DPrintf("Null resource passed to CL_MoveToOnHandList\n");
  return;
}


// CL_MsgInfo  @ 00158270
char * CL_MsgInfo(int cmd)

{
  UserMsg *pUVar1;
  
  Q_strcpy(CL_MsgInfo::sz,"???");
  pUVar1 = gClientUserMsgs;
  if (cmd < 0x3c) {
    Q_strncpy(CL_MsgInfo::sz,cl_parsefuncs[cmd].pszname,0xff);
    CL_MsgInfo::sz[0xff] = '\0';
    return CL_MsgInfo::sz;
  }
  do {
    if (pUVar1 == (UserMsg *)0x0) {
LAB_001582ce:
      return CL_MsgInfo::sz;
    }
    if (cmd == pUVar1->iMsg) {
      Q_strncpy(CL_MsgInfo::sz,pUVar1->szName,0xff);
      CL_MsgInfo::sz[0xff] = '\0';
      goto LAB_001582ce;
    }
    pUVar1 = pUVar1->next;
  } while( true );
}


// CL_ParametricMove  @ 001323c0
qboolean CL_ParametricMove(cl_entity_t_conflict2 *ent)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  qboolean qVar5;
  float fVar6;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float dt@[???] */
  fVar6 = (ent->curstate).starttime;
  qVar5 = false;
  if (fVar6 != 0.0) {
    fVar3 = (ent->curstate).impacttime;
    qVar5 = false;
    if (fVar3 != 0.0) {
      local_18 = *(float *)&(ent->curstate).field_0xf0 - *(float *)&(ent->curstate).field_0xe4;
      local_14 = *(float *)&(ent->curstate).field_0xf4 - *(float *)&(ent->curstate).field_0xe8;
      local_10 = *(float *)&(ent->curstate).field_0xf8 - *(float *)&(ent->curstate).field_0xec;
      fVar3 = fVar3 - fVar6;
      if (fVar3 != 0.0) {
                    /* Unresolved local var: float t@[???] */
        fVar4 = ent->lastmove;
        if (fVar4 <= (float)cl.time) {
          fVar4 = (float)cl.time;
        }
        fVar3 = (fVar4 - fVar6) / fVar3;
        if (fVar3 <= 1.0) {
          fVar6 = 0.0;
          if (0.0 <= fVar3) {
            fVar6 = fVar3;
          }
        }
        else {
          fVar6 = 1.0;
        }
        VectorMA((vec_t *)&(ent->curstate).field_0xe4,fVar6,&local_18,
                 (vec_t *)&(ent->curstate).field_0x10);
        ent->lastmove = fVar4;
      }
      uVar1 = *(undefined4 *)&(ent->curstate).field_0x14;
      uVar2 = *(undefined4 *)&(ent->curstate).field_0x18;
      *(undefined4 *)&ent->field_0xb48 = *(undefined4 *)&(ent->curstate).field_0x10;
      *(undefined4 *)&ent->field_0xb4c = uVar1;
      *(undefined4 *)&ent->field_0xb50 = uVar2;
      VectorNormalize(&local_18);
      fVar6 = Length(&local_18);
      if (fVar6 <= 0.0) {
        return true;
      }
      VectorAngles(&local_18,(vec_t *)&(ent->curstate).field_0x1c);
      qVar5 = true;
    }
  }
  return qVar5;
}


// CL_ParseBaseline  @ 001575d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseBaseline(void)

{
  undefined4 uVar1;
  cl_entity_t *pcVar2;
  uint uVar3;
  delta_t **ppdVar4;
  delta_t **ppdVar5;
  delta_t **ppdVar6;
  uint32 uVar7;
  uint32 index;
  delta_t *pFields;
  qboolean qVar8;
  uint uVar9;
  entity_state_t *to;
  cl_entity_t *unaff_EBX;
  int iVar10;
  int in_GS_OFFSET;
  uchar local_174 [340];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: byte type@[???]
                       Unresolved local var: entity_state_t nullstate@[???]
                       Unresolved local var: delta_t * * ppentity@[???]
                       Unresolved local var: delta_t * * ppcustom@[???]
                       Unresolved local var: delta_t * * ppplayer@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ppdVar4 = DELTA_LookupRegistration("entity_state_t");
  ppdVar5 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar6 = DELTA_LookupRegistration("custom_entity_state_t");
  Q_memset(local_174,0,0x154);
  MSG_StartBitReading(&net_message);
  ContinueLoadingProgressBar("ClientConnect",0xb,0.0);
  SetLoadingProgressBarStatusText("#GameUI_ParseBaseline");
  cl.highentity = 0;
  while (uVar7 = MSG_PeekBits(0x10), uVar7 != 0xffff) {
    index = MSG_ReadBits(0xb);
    uVar7 = index;
    if ((int)index <= cl.highentity) {
      uVar7 = cl.highentity;
    }
    cl.highentity = uVar7;
    if (cl.num_entities <= (int)index) {
      if (cl.max_edicts <= (int)index) {
                    /* WARNING: Subroutine does not return */
        Host_Error("CL_EntityNum: %i is an invalid number, cl.max_edicts is %i",index,cl.max_edicts)
        ;
      }
      do {
        cl_entities[index].index = index;
        cl.num_entities = cl.num_entities + 1;
      } while (cl.num_entities <= (int)index);
    }
    cl_entities[index].index = index;
    pcVar2 = cl_entities;
    uVar7 = MSG_ReadBits(2);
    unaff_EBX = pcVar2 + index;
    if ((uVar7 & 2) == 0) {
      qVar8 = CL_IsPlayerIndex(index);
      if (qVar8 == false) {
        pFields = *ppdVar4;
      }
      else {
        pFields = *ppdVar5;
      }
    }
    else {
      pFields = *ppdVar6;
    }
    DELTA_ParseDelta(local_174,(uchar *)&unaff_EBX->baseline,pFields,0x154);
    (unaff_EBX->baseline).entityType = uVar7 & 0xff;
  }
  iVar10 = 0;
  MSG_ReadBits(0x10);
  Q_memset(cl.instanced_baseline,0,0x5500);
  cl.instanced_baseline_number = MSG_ReadBits(6);
  to = cl.instanced_baseline;
  if (0 < cl.instanced_baseline_number) {
    do {
      iVar10 = iVar10 + 1;
      DELTA_ParseDelta(local_174,(uchar *)to,*ppdVar4,0x154);
      to = to + 1;
    } while (iVar10 < cl.instanced_baseline_number);
  }
  MSG_EndBitReading(&net_message);
  uVar3 = 0;
  do {
    uVar9 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0xc));
    *(undefined4 *)((int)(unaff_EBX->curstate).origin + (uVar9 - 0x10)) =
         *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0x10));
    *(undefined4 *)((int)(unaff_EBX->curstate).origin + (uVar9 - 0xc)) = uVar1;
    uVar3 = uVar9 + 8;
  } while (uVar9 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_EBX->curstate).origin + (uVar9 - 8)) =
       *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 8));
  uVar3 = 0;
  do {
    uVar9 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0xc));
    *(undefined4 *)((int)(unaff_EBX->prevstate).origin + (uVar9 - 0x10)) =
         *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0x10));
    *(undefined4 *)((int)(unaff_EBX->prevstate).origin + (uVar9 - 0xc)) = uVar1;
    uVar3 = uVar9 + 8;
  } while (uVar9 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_EBX->prevstate).origin + (uVar9 - 8)) =
       *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 8));
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ParseBatchModList  @ 00145390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseBatchModList(void)

{
  netadr_t a;
  netadr_t to;
  char *pcVar1;
  int iVar2;
  char *str;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_1a0 [128];
  char local_120 [255];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char * pszModName@[???]
                       Unresolved local var: char[256] szName@[???]
                       Unresolved local var: int nPlayers@[???]
                       Unresolved local var: int nServers@[???]
                       Unresolved local var: char * pszServers@[???]
                       Unresolved local var: char * pszPlayers@[???]
                       Unresolved local var: int nCount@[???] */
  iVar4 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  MSG_ReadByte();
  local_120[0] = '\0';
LAB_001453c0:
  pcVar1 = MSG_ReadString();
  do {
    if (pcVar1 == (char *)0x0) {
      Con_Printf("%i servers\n",iVar4);
LAB_001454b5:
      Con_Printf("Done.\n",iVar4);
LAB_001454c1:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    if (((*pcVar1 == '\0') || (iVar2 = Q_stricmp(pcVar1,"end-of-list"), iVar2 == 0)) ||
       (iVar2 = Q_stricmp(pcVar1,"more-in-list"), iVar2 == 0)) {
      Con_Printf("%i servers\n",iVar4);
      if (*pcVar1 != '\0') {
        iVar4 = 0x264db3;
        iVar2 = Q_stricmp(pcVar1,"more-in-list");
        if (iVar2 == 0) {
                    /* Unresolved local var: char[128] szRequest@[???] */
          __snprintf_chk(local_1a0,0x80,1,0x80,&LAB_00264dcb_1,0x78,local_120);
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
          pcVar1 = NET_AdrToString(a);
          Con_DPrintf("Requesting next batch ( >%s ) of mods from %s\n",local_120,pcVar1);
          iVar4 = Q_strlen(local_1a0);
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
          NET_SendPacket(NS_CLIENT,iVar4 + 1,local_1a0,to);
          goto LAB_001454c1;
        }
      }
      goto LAB_001454b5;
    }
    iVar4 = iVar4 + 1;
    Q_strncpy(local_120,pcVar1,0xff);
    local_21 = 0;
    pcVar1 = MSG_ReadString();
    iVar2 = Q_atoi(pcVar1);
    str = MSG_ReadString();
    iVar3 = Q_atoi(str);
    if ((pcVar1 == (char *)0x0) || (str == (char *)0x0)) goto LAB_001453c0;
    Con_Printf("%3i %5i %s\n",iVar2,iVar3,local_120);
    pcVar1 = MSG_ReadString();
  } while( true );
}


// CL_ParseBatchUserList  @ 001455e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseBatchUserList(void)

{
  netadr_t a;
  netadr_t to;
  _func_short_short *p_Var1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int in_GS_OFFSET;
  char local_b8 [4];
  char local_b4;
  int aiStack_b3 [4];
  undefined4 local_a0;
  int aiStack_9c [35];
  
                    /* Unresolved local var: char[128] szAddress@[???]
                       Unresolved local var: uchar[4] cIP@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: ushort iIPPort@[???]
                       Unresolved local var: int nNumAddresses@[???]
                       Unresolved local var: int unique@[???]
                       Unresolved local var: int hash@[???] */
  aiStack_9c[0x1f] = *(int *)(in_GS_OFFSET + 0x14);
  local_a0 = 0;
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    *(undefined4 *)((int)aiStack_9c + uVar4) = 0;
    *(undefined4 *)((int)aiStack_9c + uVar4 + 4) = 0;
    uVar2 = uVar4 + 8;
  } while (uVar4 + 8 < 0x78);
  *(undefined4 *)((int)aiStack_9c + uVar4 + 8) = 0;
  MSG_ReadByte();
  iVar5 = MSG_ReadLong();
  iVar6 = MSG_ReadLong();
  iVar7 = (net_message.cursize - msg_readcount) / 6;
  iVar10 = iVar7 + -1;
  if (0 < iVar7) {
    do {
      Q_memset(&local_a0,0,0x80);
      pcVar8 = local_b8;
      do {
        iVar7 = MSG_ReadByte();
        pcVar9 = pcVar8 + 1;
        *pcVar8 = (char)iVar7;
        pcVar8 = pcVar9;
      } while (pcVar9 != &local_b4);
      iVar10 = iVar10 + -1;
      __snprintf_chk(&local_a0,0x80,1,0x80,0x261038,local_b8[0],local_b8[1],local_b8[2],local_b8[3])
      ;
      p_Var1 = BigShort;
      iVar7 = MSG_ReadShort();
      sVar3 = (*p_Var1)((short)iVar7);
      Con_Printf("%4i:  %s:%i\n",CL_ParseBatchUserList::count,&local_a0,sVar3);
      CL_ParseBatchUserList::count = CL_ParseBatchUserList::count + 1;
    } while (iVar10 != -1);
  }
  if ((iVar6 == 0) || (iVar5 == 0)) {
    Con_Printf("%i users\n",CL_ParseBatchUserList::count);
    CL_ParseBatchUserList::count = 0;
    Con_Printf("Done.\n");
  }
  else {
                    /* Unresolved local var: uchar[20] c@[???]
                       Unresolved local var: int i@[???] */
    Q_strcpy(&local_b4,"users");
    iVar10 = Q_strlen("users");
    *(int *)((int)aiStack_b3 + iVar10 + 4) = iVar6;
    *(int *)((int)aiStack_b3 + iVar10) = iVar5;
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
    pcVar8 = NET_AdrToString(a);
    Con_DPrintf("Requesting next batch ( %i ) user list from %s\n",iVar6,pcVar8);
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
    NET_SendPacket(NS_CLIENT,iVar10 + 9,&local_b4,to);
  }
  if (aiStack_9c[0x1f] != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_ParseClientdata  @ 001336e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseClientdata(void)

{
  clientdata_t *to;
  float fVar1;
  double dVar2;
  double dVar3;
  local_state_t *plVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  qboolean qVar9;
  delta_t **ppdVar10;
  delta_t **ppdVar11;
  uint uVar12;
  local_state_t *ps;
  uint32 uVar13;
  uint32 uVar14;
  weapon_data_s *pwd;
  int iVar15;
  local_state_t *pps;
  uint uVar16;
  weapon_data_s *wd;
  clientdata_s *pcd;
  int in_GS_OFFSET;
  uchar local_254 [88];
  uchar local_1fc [476];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int command_ack@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: int bits@[???]
                       Unresolved local var: clientdata_t baseline@[???]
                       Unresolved local var: clientdata_t * from@[???]
                       Unresolved local var: clientdata_t * to@[???]
                       Unresolved local var: int fromframe@[???]
                       Unresolved local var: delta_t * * ppdelta@[???]
                       Unresolved local var: delta_t * * ppweapon@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ppdVar10 = DELTA_LookupRegistration("clientdata_t");
  ppdVar11 = DELTA_LookupRegistration("weapon_data_t");
  Q_memset(local_1fc,0,0x1dc);
  iVar8 = cls.netchan.incoming_acknowledged;
  iVar15 = cls.netchan.incoming_sequence;
  iVar7 = CL_ParseClientdata::last_incoming_sequence;
  iVar5 = CL_UPDATE_MASK;
  uVar16 = CL_ParseClientdata::last_incoming_sequence + 1;
  if ((int)uVar16 < cls.netchan.incoming_sequence) {
    do {
      uVar12 = iVar5 & uVar16;
      if (0.0 <= cl.frames[uVar12].receivedtime) {
        *(undefined4 *)&cl.frames[uVar12].receivedtime = 0;
        *(undefined4 *)((int)&cl.frames[uVar12].receivedtime + 4) = 0xbff00000;
        *(undefined4 *)&cl.frames[uVar12].latency = 0;
        *(undefined4 *)((int)&cl.frames[uVar12].latency + 4) = 0;
      }
      uVar16 = uVar16 + 1;
    } while (iVar15 != uVar16);
  }
  dVar2 = cl.mtime[0];
  uVar16 = iVar5 & iVar15;
  cl.parsecountmod = uVar16;
  cl.frames[uVar16].tentitybytes = 0;
  cl.frames[uVar16].time = dVar2;
  cl.frames[uVar16].playerinfobytes = 0;
  cl.frames[uVar16].soundbytes = 0;
  cl.frames[uVar16].usrbytes = 0;
  cl.frames[uVar16].eventbytes = 0;
  fVar1 = cl.commands[iVar8 & iVar5].senttime;
  dVar3 = (double)fVar1;
  cl.frames[uVar16].voicebytes = 0;
  dVar2 = realtime;
  iVar6 = CL_ParseClientdata::last_command_ack;
  parsecounttime = (double)fVar1;
  cl.commands[iVar8 & iVar5].receivedtime = (float)realtime;
  cl.frames[uVar16].clientbytes = 0;
  cl.parsecount = iVar15;
  cl.frames[uVar16].receivedtime = dVar2;
  cl.frames[uVar16].packetentitybytes = 0;
  cl.frames[uVar16].msgbytes = 0;
  if (iVar6 != -1) {
                    /* Unresolved local var: int last_predicted@[???]
                       Unresolved local var: entity_state_t.conflict * ps@[???]
                       Unresolved local var: entity_state_t.conflict * pps@[???]
                       Unresolved local var: clientdata_t * pcd@[???]
                       Unresolved local var: clientdata_t * ppcd@[???]
                       Unresolved local var: weapon_data_t * wd@[???]
                       Unresolved local var: weapon_data_t * pwd@[???] */
    if (cls.spectator == false) {
      uVar12 = iVar5 & (iVar8 - iVar6) + iVar7;
      pcd = &cl.frames[uVar16].clientdata;
      ps = (local_state_t *)(uVar16 * 0x4318 + 0xc6aa3c + cl.playernum * 0x154);
      pps = cl.predicted_frames + uVar12;
      plVar4 = cl.predicted_frames + uVar12;
      pwd = cl.predicted_frames[uVar12].weapondata;
      wd = cl.frames[uVar16].weapondata;
    }
    else {
      pwd = spectatorState.weapondata;
      plVar4 = &spectatorState;
      pps = &spectatorState;
      pcd = &spectatorState.client;
      ps = &spectatorState;
      wd = pwd;
    }
    ClientDLL_TxferPredictionData
              ((entity_state_s *)ps,(entity_state_s *)pps,pcd,&plVar4->client,wd,pwd);
    iVar15 = cls.netchan.incoming_sequence;
    dVar2 = realtime;
    dVar3 = parsecounttime;
  }
  qVar9 = cls.spectator;
  g_flLatency = dVar2 - dVar3;
  CL_ParseClientdata::last_command_ack = iVar8;
  CL_ParseClientdata::last_incoming_sequence = iVar15;
  cl.frames[uVar16].latency = g_flLatency;
  if (qVar9 == false) {
    to = &cl.frames[uVar16].clientdata;
    MSG_StartBitReading(&net_message);
    uVar13 = MSG_ReadBits(1);
    if (uVar13 == 0) {
                    /* Unresolved local var: int moreweapons@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: weapon_data_t * fdata@[???]
                       Unresolved local var: weapon_data_t * tdata@[???]
                       Unresolved local var: weapon_data_t wbaseline@[???] */
      DELTA_ParseDelta(local_1fc,(uchar *)to,*ppdVar10,0x1dc);
      Q_memset(local_254,0,0x58);
      while (uVar13 = MSG_ReadBits(1), uVar13 != 0) {
        uVar13 = MSG_ReadBits(6);
        DELTA_ParseDelta(local_254,(uchar *)(uVar16 * 0x4318 + 0xc6d6a0 + uVar13 * 0x58),*ppdVar11,
                         0x58);
      }
    }
    else {
      uVar13 = MSG_ReadBits(8);
      DELTA_ParseDelta((uchar *)&cl.frames[CL_UPDATE_MASK & uVar13].clientdata,(uchar *)to,*ppdVar10
                       ,0x1dc);
      Q_memset(local_254,0,0x58);
      while (uVar14 = MSG_ReadBits(1), uVar14 != 0) {
        uVar14 = MSG_ReadBits(6);
        DELTA_ParseDelta((uchar *)(uVar14 * 0x58 + 0xc6d6a0 + (CL_UPDATE_MASK & uVar13) * 0x4318),
                         (uchar *)(uVar14 * 0x58 + 0xc6d6a0 + uVar16 * 0x4318),*ppdVar11,0x58);
      }
    }
    MSG_EndBitReading(&net_message);
    Q_strncpy(cls.physinfo,cl.frames[uVar16].clientdata.physinfo,0xff);
    cl.pushmsec = cl.frames[uVar16].clientdata.pushmsec;
    cl.stats[0] = (int)cl.frames[uVar16].clientdata.health;
    cls.physinfo[0xff] = '\0';
    cl.maxspeed = cl.frames[uVar16].clientdata.maxspeed;
    cl.weapons = cl.frames[uVar16].clientdata.weapons;
  }
  else {
    cl.stats[0] = 1;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_ParseConsistencyInfo  @ 00155e00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseConsistencyInfo(void)

{
  consistency_t *dest;
  resourcetype_t rVar1;
  uint32 uVar2;
  uint32 uVar3;
  char *pcVar4;
  uint32 uVar5;
  int iVar6;
  int iVar7;
  resource_s *__haystack;
  resource_s *prVar8;
  int in_GS_OFFSET;
  undefined1 local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int lastcheck@[???]
                       Unresolved local var: int delta@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int isdelta@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: resource_t * skip_crc_change@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: qboolean hasinfo@[???]
                       Unresolved local var: consistency_t * pc@[???]
                       Unresolved local var: byte[32] nullbuffer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_ParseConsistencyInfo()");
  }
  Q_memset(local_40,0,0x20);
  __haystack = cl.resourcesneeded.pNext;
  uVar2 = MSG_ReadBits(1);
  cl.need_force_consistency_response = (qboolean)(uVar2 != 0);
  if (uVar2 != 0) {
    uVar2 = MSG_ReadBits(1);
    if (uVar2 != 0) {
      uVar2 = 0;
      prVar8 = (resource_s *)0x0;
      do {
        uVar3 = MSG_ReadBits(1);
        if (uVar3 == 0) {
          uVar3 = MSG_ReadBits(10);
        }
        else {
          uVar3 = MSG_ReadBits(5);
          uVar3 = uVar2 + uVar3;
        }
        iVar7 = (uVar3 - uVar2) + -1;
        if (0 < (int)(uVar3 - uVar2)) {
          do {
            if ((prVar8 != __haystack) &&
               (pcVar4 = strstr(__haystack->szFileName,"models/"), pcVar4 != (char *)0x0)) {
              Mod_NeedCRC(__haystack->szFileName,false);
            }
            iVar7 = iVar7 + -1;
            __haystack = __haystack->pNext;
          } while (iVar7 != -1);
        }
        pcVar4 = strstr(__haystack->szFileName,"models/");
        if (pcVar4 != (char *)0x0) {
          Mod_NeedCRC(__haystack->szFileName,true);
        }
        iVar7 = cl.num_consistency;
        if (0x1ff < cl.num_consistency) {
                    /* WARNING: Subroutine does not return */
          Host_Error("Consistency:  server sent too many filenames\n");
        }
        dest = cl.consistency_list + cl.num_consistency;
        cl.num_consistency = cl.num_consistency + 1;
        Q_memset(dest,0,0x2c);
        rVar1 = __haystack->type;
        cl.consistency_list[iVar7].filename = __haystack->szFileName;
        cl.consistency_list[iVar7].orig_index = uVar3;
        cl.consistency_list[iVar7].issound = (uint)(rVar1 == t_sound);
        cl.consistency_list[iVar7].value = 0;
        if (__haystack->type == t_model) {
          iVar6 = Q_memcmp(local_40,__haystack->rguc_reserved,0x20);
          if (iVar6 != 0) {
            COM_UnMunge(__haystack->rguc_reserved,0x20,cl.servercount);
            cl.consistency_list[iVar7].check_type = (uint)__haystack->rguc_reserved[0];
          }
        }
        uVar5 = MSG_ReadBits(1);
        uVar2 = uVar3;
        prVar8 = __haystack;
      } while (uVar5 != 0);
    }
    if (fs_startup_timings.value != 0.0) {
      AddStartupTiming("end   CL_ParseConsistencyInfo()");
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ParseCustomization  @ 00156620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseCustomization(void)

{
  bool bVar1;
  uint nPlayerNum;
  resource_s *pResource;
  resourcetype_t rVar2;
  char *src;
  int iVar3;
  uint uVar4;
  qboolean qVar5;
  customization_s *pcVar6;
  resourceinfo_t local_2c;
  
                    /* Unresolved local var: resource_t * resource@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: customization_t * pExistingCustomization@[???]
                       Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
  nPlayerNum = MSG_ReadByte();
  if (0x1f < nPlayerNum) {
                    /* WARNING: Subroutine does not return */
    Host_Error("Bogus player index during customization parsing.\n");
  }
  pResource = Mem_ZeroMalloc(0x88);
  rVar2 = MSG_ReadByte();
  pResource->type = rVar2;
  src = MSG_ReadString();
  Q_strncpy(pResource->szFileName,src,0x3f);
  pResource->szFileName[0x3f] = '\0';
  iVar3 = MSG_ReadShort();
  pResource->nIndex = iVar3;
  iVar3 = MSG_ReadLong();
  pResource->nDownloadSize = iVar3;
  uVar4 = MSG_ReadByte();
  pResource->pNext = (resource_s *)0x0;
  pResource->pPrev = (resource_s *)0x0;
  pResource->ucFlags = (byte)uVar4 & 0xfd;
  if ((uVar4 & 4) != 0) {
    MSG_ReadBuf(0x10,pResource->rgucMD5_hash);
  }
  uVar4 = nPlayerNum & 0xff;
  bVar1 = cl_allow_download.value == 0.0;
  pResource->playernum = (uchar)nPlayerNum;
  if (bVar1) {
    Con_DPrintf("Refusing new resource, cl_allow_download set to 0\n");
    Mem_Free(pResource);
    return;
  }
  if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
    Con_DPrintf("Refusing new resource, cl_download_ingame set to 0\n");
    Mem_Free(pResource);
  }
  else {
                    /* Unresolved local var: customization_t * pList@[???] */
    for (pcVar6 = cl.players[nPlayerNum].customdata.pNext; pcVar6 != (customization_t *)0x0;
        pcVar6 = pcVar6->pNext) {
      if (pResource->type == (pcVar6->resource).type) {
        CL_RemoveCustomization(nPlayerNum,pcVar6);
        uVar4 = (uint)pResource->playernum;
        break;
      }
    }
    pcVar6 = cl.players[uVar4].customdata.pNext;
    if (pcVar6 != (customization_s *)0x0) {
      do {
        iVar3 = Q_memcmp((pcVar6->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10);
        if (iVar3 == 0) {
          qVar5 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
          if (qVar5 == false) goto LAB_00156850;
          Con_DPrintf("Duplicate resource ignored for local client\n");
          goto LAB_001567fb;
        }
        pcVar6 = pcVar6->pNext;
      } while (pcVar6 != (customization_s *)0x0);
    }
    qVar5 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
    if (qVar5 != false) {
                    /* Unresolved local var: qboolean bNoError@[???] */
      qVar5 = COM_CreateCustomization
                        (&cl.players[pResource->playernum].customdata,pResource,
                         (uint)pResource->playernum,1,(customization_t **)0x0,(int *)0x0);
      if (qVar5 == false) {
        Con_DPrintf("Error loading customization\n");
      }
LAB_001567fb:
      Mem_Free(pResource);
      return;
    }
LAB_00156850:
    pResource->ucFlags = pResource->ucFlags | 2;
    if ((pResource->pPrev == (resource_s *)0x0) && (pResource->pNext == (resource_s *)0x0)) {
      if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
         (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Resource list corrupted.\n");
      }
      pResource->pPrev = cl.resourcesneeded.pPrev;
      (cl.resourcesneeded.pPrev)->pNext = pResource;
      cl.resourcesneeded.pPrev = pResource;
      pResource->pNext = &cl.resourcesneeded;
    }
    else {
      Con_Printf("Resource already linked\n");
    }
    Con_Printf("Requesting %s from server\n",pResource);
                    /* Unresolved local var: resourceinfo_t ri@[???] */
    if (fs_startup_timings.value != 0.0) {
      AddStartupTiming("begin CL_StartResourceDownloading()");
    }
    Con_DPrintf("%s","Custom resource propagation...\n");
    cls.dl.nTotalSize = COM_SizeofResourceList(&cl.resourcesneeded,&local_2c);
    cls.dl.nTotalToTransfer = CL_EstimateNeededResources();
    cls.dl.custom = true;
    cls.dl.fLastStatusUpdate = (float)realtime;
    cls.dl.doneregistering = false;
    cls.dl.nRemainingToTransfer = cls.dl.nTotalToTransfer;
    Q_memset(cls.dl.rgStats,0,0x60);
    cls.dl.nCurStat = 0;
    if (fs_startup_timings.value != 0.0) {
      AddStartupTiming("end   CL_StartResourceDownloading()");
    }
    CL_BatchResourceRequest();
  }
  return;
}


// CL_ParseDeltaHeader  @ 00132750
int CL_ParseDeltaHeader(qboolean *remove,qboolean *custom,int *numbase,qboolean *newbl,
                       int *newblindex,qboolean full,int *offset)

{
  qboolean qVar1;
  uint32 uVar2;
  uint32 uVar3;
  
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int delta@[???]
                       Unresolved local var: qboolean isdelta@[???]
                       Unresolved local var: qboolean isnext@[???] */
  *custom = false;
  *newbl = false;
  if (full == false) {
    uVar2 = MSG_ReadBits(1);
    *remove = (uint)(uVar2 != 0);
LAB_001327d6:
    uVar2 = MSG_ReadBits(1);
    if (uVar2 != 0) {
      uVar2 = MSG_ReadBits(0xb);
      goto LAB_001327a2;
    }
    uVar2 = MSG_ReadBits(6);
    uVar2 = uVar2 + *numbase;
    *numbase = uVar2;
    qVar1 = *remove;
  }
  else {
    *remove = false;
    uVar2 = MSG_ReadBits(1);
    if (uVar2 == 0) goto LAB_001327d6;
    uVar2 = *numbase + 1;
LAB_001327a2:
    *numbase = uVar2;
    qVar1 = *remove;
  }
  if (qVar1 != false) {
    return uVar2;
  }
  uVar3 = MSG_ReadBits(1);
  *custom = (uint)(uVar3 != 0);
  if (cl.instanced_baseline_number == 0) {
    *newbl = false;
    if (full != false) {
LAB_00132890:
      uVar3 = MSG_ReadBits(1);
      *offset = uVar3;
      if (uVar3 == 0) {
        return uVar2;
      }
      uVar3 = MSG_ReadBits(6);
      *offset = uVar3;
      return uVar2;
    }
  }
  else {
    uVar3 = MSG_ReadBits(1);
    *newbl = (uint)(uVar3 != 0);
    if (uVar3 != 0) {
      uVar3 = MSG_ReadBits(6);
      *newblindex = uVar3;
    }
    if ((full != false) && (*newbl == false)) goto LAB_00132890;
  }
  *offset = 0;
  return uVar2;
}


// CL_ParseEvent  @ 00139290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseEvent(void)

{
  int iVar1;
  entity_state_s *peVar2;
  float fVar3;
  delta_t **ppdVar4;
  uint32 uVar5;
  uint32 uVar6;
  uint32 uVar7;
  int iVar8;
  event_state_t *peVar9;
  uint uVar10;
  uint32 uVar11;
  uint32 uVar12;
  float local_c0;
  uchar local_ac [72];
  uchar local_64 [4];
  int local_60;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  float local_50;
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44 [3];
  uint local_38;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int num_events@[???]
                       Unresolved local var: int event_index@[???]
                       Unresolved local var: int referenced@[???]
                       Unresolved local var: int packet_index@[???]
                       Unresolved local var: qboolean hasargs@[???]
                       Unresolved local var: qboolean hasdelay@[???]
                       Unresolved local var: float delay@[???]
                       Unresolved local var: event_args_t nullargs@[???]
                       Unresolved local var: event_args_t newargs@[???]
                       Unresolved local var: event_args_t * from@[???]
                       Unresolved local var: event_args_t * to@[???]
                       Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: entity_state_t * state@[???]
                       Unresolved local var: delta_t * * ppevent@[???] */
  ppdVar4 = DELTA_LookupRegistration("event_t");
  Q_memset(local_ac,0,0x48);
  Q_memset(local_64,0,0x48);
  MSG_StartBitReading(&net_message);
  uVar5 = MSG_ReadBits(5);
  local_c0 = 0.0;
  if (0 < (int)uVar5) {
    uVar12 = 0;
    do {
      while( true ) {
        uVar11 = 0xffffffff;
        uVar6 = MSG_ReadBits(10);
        uVar7 = MSG_ReadBits(1);
        if (uVar7 == 0) {
          uVar7 = MSG_ReadBits(1);
        }
        else {
          uVar11 = MSG_ReadBits(0xb);
          uVar7 = MSG_ReadBits(1);
        }
        if (uVar7 != 0) {
          DELTA_ParseDelta(local_ac,local_64,*ppdVar4,0x48);
        }
        uVar7 = MSG_ReadBits(1);
        if (uVar7 != 0) {
          uVar7 = MSG_ReadBits(0x10);
          local_c0 = (float)uVar7 / 100.0;
        }
        if (uVar11 == 0xffffffff) break;
        if ((int)uVar11 < cl.frames[cl.parsecountmod].packet_entities.num_entities) {
          peVar2 = cl.frames[cl.parsecountmod].packet_entities.entities;
          local_60 = peVar2[uVar11].number;
          iVar8 = VectorCompare(&local_5c,vec3_origin);
          if (iVar8 != 0) {
            local_5c = peVar2[uVar11].origin[0];
            local_58 = peVar2[uVar11].origin[1];
            local_54 = peVar2[uVar11].origin[2];
          }
          iVar8 = VectorCompare(&local_50,vec3_origin);
          if (iVar8 != 0) {
            local_50 = peVar2[uVar11].angles[0];
            local_4c = peVar2[uVar11].angles[1];
            local_48 = peVar2[uVar11].angles[2];
          }
          COM_NormalizeAngles(&local_50);
          if ((0 < peVar2[uVar11].number) && (peVar2[uVar11].number <= cl.maxclients)) {
            local_50 = local_50 * -3.0;
            CL_CalcPlayerVelocity(peVar2[uVar11].number,local_44);
            local_38 = (uint)(peVar2[uVar11].usehull == 1);
          }
        }
        else if (local_60 == 0) {
          Con_DPrintf("CL_ParseEvent:  Received non-packet entity index 0 for event\n");
        }
        else if ((0 < local_60) && (local_60 <= cl.maxclients)) {
          local_50 = local_50 * -3.0;
        }
        peVar9 = &cl.events;
                    /* Unresolved local var: event_info_t * ei@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???] */
        iVar8 = 0;
        while (peVar9->ei[0].index != 0) {
          iVar8 = iVar8 + 1;
          peVar9 = (event_state_t *)(peVar9->ei + 1);
          if (iVar8 == 0x40) goto LAB_001393d0;
        }
        iVar1 = iVar8 * 0x58;
        if (iVar1 == -0xdef268) break;
        uVar10 = 0;
        cl.events.ei[iVar8].index = (ushort)uVar6;
        *(undefined2 *)((int)(cl.instanced_baseline + 0x40) + iVar1 + 10) = 0;
        do {
          *(undefined4 *)(iVar1 + 0xdef274 + uVar10) = *(undefined4 *)(local_64 + uVar10);
          uVar10 = uVar10 + 4;
        } while (uVar10 < 0x48);
        fVar3 = 0.0;
        if (local_c0 != 0.0) {
          fVar3 = local_c0 + (float)cl.time;
        }
        uVar12 = uVar12 + 1;
        *(float *)((int)(cl.instanced_baseline + 0x40) + (iVar8 * 0x16 + 4) * 4) = fVar3;
        *(int *)((int)(cl.instanced_baseline + 0x40) + (iVar8 * 0x16 + 0x17) * 4) = 0;
        if (uVar5 == uVar12) goto LAB_001393d9;
      }
LAB_001393d0:
      uVar12 = uVar12 + 1;
    } while (uVar5 != uVar12);
  }
LAB_001393d9:
  MSG_EndBitReading(&net_message);
  return;
}


// CL_ParseFileTxferFailed  @ 00139c40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseFileTxferFailed(void)

{
  char *filename;
  
                    /* Unresolved local var: char * name@[???] */
  filename = MSG_ReadString();
  if ((filename != (char *)0x0) && (*filename != '\0')) {
    if (cls.demoplayback != false) {
      return;
    }
    CL_ProcessFile(false,filename);
    return;
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("CL_ParseFileTxferFailed:  empty filename\n");
}


// CL_ParseHLTV  @ 00158e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseHLTV(void)

{
  netadr_t addr;
  int iVar1;
  char *s;
  
                    /* Unresolved local var: int cmd@[???]
                       Unresolved local var: uint flags@[???] */
  iVar1 = MSG_ReadByte();
  if (iVar1 == 1) {
    MSG_ReadLong();
    MSG_ReadShort();
    MSG_ReadWord();
    MSG_ReadLong();
    MSG_ReadLong();
    MSG_ReadWord();
    return;
  }
  if (iVar1 != 2) {
    if (iVar1 != 0) {
      Con_Printf(" CL_Parse_HLTV: unknown HLTV command.\n");
      return;
    }
    cls.spectator = true;
    g_bRedirectedToProxy = 0;
    return;
  }
                    /* Unresolved local var: char * stream_IP@[???] */
  cls.signon = 2;
  s = MSG_ReadString();
  Net_StringToAdr(s,&cls.game_stream);
  addr.ip[0] = cls.game_stream.ip[0];
  addr.ip[1] = cls.game_stream.ip[1];
  addr.ip[2] = cls.game_stream.ip[2];
  addr.ip[3] = cls.game_stream.ip[3];
  addr.type = cls.game_stream.type;
  addr.ipx[0] = cls.game_stream.ipx[0];
  addr.ipx[1] = cls.game_stream.ipx[1];
  addr.ipx[2] = cls.game_stream.ipx[2];
  addr.ipx[3] = cls.game_stream.ipx[3];
  addr.ipx[4] = cls.game_stream.ipx[4];
  addr.ipx[5] = cls.game_stream.ipx[5];
  addr.ipx[6] = cls.game_stream.ipx[6];
  addr.ipx[7] = cls.game_stream.ipx[7];
  addr.ipx[8] = cls.game_stream.ipx[8];
  addr.ipx[9] = cls.game_stream.ipx[9];
  addr.port = cls.game_stream.port;
  NET_JoinGroup(cls.netchan.sock,addr);
  SCR_EndLoadingPlaque();
  return;
}


// CL_ParseListen  @ 00157560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseListen(void)

{
  netadr_t addr;
  char *s;
  
                    /* Unresolved local var: char * stream_IP@[???] */
  cls.signon = 2;
  s = MSG_ReadString();
  Net_StringToAdr(s,&cls.game_stream);
  addr.ip[0] = cls.game_stream.ip[0];
  addr.ip[1] = cls.game_stream.ip[1];
  addr.ip[2] = cls.game_stream.ip[2];
  addr.ip[3] = cls.game_stream.ip[3];
  addr.type = cls.game_stream.type;
  addr.ipx[0] = cls.game_stream.ipx[0];
  addr.ipx[1] = cls.game_stream.ipx[1];
  addr.ipx[2] = cls.game_stream.ipx[2];
  addr.ipx[3] = cls.game_stream.ipx[3];
  addr.ipx[4] = cls.game_stream.ipx[4];
  addr.ipx[5] = cls.game_stream.ipx[5];
  addr.ipx[6] = cls.game_stream.ipx[6];
  addr.ipx[7] = cls.game_stream.ipx[7];
  addr.ipx[8] = cls.game_stream.ipx[8];
  addr.ipx[9] = cls.game_stream.ipx[9];
  addr.port = cls.game_stream.port;
  NET_JoinGroup(cls.netchan.sock,addr);
  SCR_EndLoadingPlaque();
  return;
}


// CL_ParseMovevars  @ 00157a30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseMovevars(void)

{
  char *src;
  
  movevars.gravity = MSG_ReadFloat();
  movevars.stopspeed = MSG_ReadFloat();
  movevars.maxspeed = MSG_ReadFloat();
  movevars.spectatormaxspeed = MSG_ReadFloat();
  movevars.accelerate = MSG_ReadFloat();
  movevars.airaccelerate = MSG_ReadFloat();
  movevars.wateraccelerate = MSG_ReadFloat();
  movevars.friction = MSG_ReadFloat();
  movevars.edgefriction = MSG_ReadFloat();
  movevars.waterfriction = MSG_ReadFloat();
  movevars.entgravity = MSG_ReadFloat();
  movevars.bounce = MSG_ReadFloat();
  movevars.stepsize = MSG_ReadFloat();
  movevars.maxvelocity = MSG_ReadFloat();
  movevars.zmax = MSG_ReadFloat();
  movevars.waveHeight = MSG_ReadFloat();
  movevars.footsteps = MSG_ReadByte();
  movevars.rollangle = MSG_ReadFloat();
  movevars.rollspeed = MSG_ReadFloat();
  movevars.skycolor_r = MSG_ReadFloat();
  movevars.skycolor_g = MSG_ReadFloat();
  movevars.skycolor_b = MSG_ReadFloat();
  movevars.skyvec_x = MSG_ReadFloat();
  movevars.skyvec_y = MSG_ReadFloat();
  movevars.skyvec_z = MSG_ReadFloat();
  src = MSG_ReadString();
  Q_strncpy(movevars.skyName,src,0x1f);
  movevars.skyName[0x1f] = '\0';
  if (movevars.zmax != gl_zmax.value) {
    Cvar_SetValue("gl_zmax",movevars.zmax);
  }
  if (movevars.waveHeight != gl_wateramp.value) {
    Cvar_SetValue("gl_wateramp",movevars.waveHeight);
  }
  if (cl_entities != (cl_entity_t *)0x0) {
    (cl_entities->curstate).scale = gl_wateramp.value;
  }
  return;
}


// CL_ParsePacketEntities  @ 00133b90
void CL_ParsePacketEntities(qboolean delta,int *playerbits)

{
  undefined4 *puVar1;
  byte *pbVar2;
  entity_state_s *peVar3;
  undefined4 uVar4;
  int iVar5;
  delta_t **ppdVar6;
  delta_t **ppdVar7;
  delta_t **ppdVar8;
  int iVar9;
  entity_state_s *peVar10;
  uint32 uVar11;
  uint32 uVar12;
  uint uVar13;
  model_s *pmVar14;
  delta_t **ppdVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  packet_entities_t *dest;
  int in_GS_OFFSET;
  int local_f4;
  qboolean local_e8;
  qboolean local_c0;
  qboolean local_bc;
  qboolean local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  packet_entities_t local_a8;
  int local_20;
  
                    /* Unresolved local var: int oldpacket@[???]
                       Unresolved local var: int newpacket@[???]
                       Unresolved local var: packet_entities_t * oldp@[???]
                       Unresolved local var: packet_entities_t * newp@[???]
                       Unresolved local var: packet_entities_t dummy@[???]
                       Unresolved local var: int oldindex@[???]
                       Unresolved local var: int newindex@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int newnum@[???]
                       Unresolved local var: int oldnum@[???]
                       Unresolved local var: qboolean full@[???]
                       Unresolved local var: byte from@[???]
                       Unresolved local var: uint peeklong@[???]
                       Unresolved local var: int newp_number@[???]
                       Unresolved local var: int entsinpacket@[???]
                       Unresolved local var: qboolean berror@[???]
                       Unresolved local var: int backup@[???]
                       Unresolved local var: int parsed_bits@[???]
                       Unresolved local var: qboolean remove@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: qboolean newbl@[???]
                       Unresolved local var: int newblindex@[???]
                       Unresolved local var: int numbase@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: delta_t * * ppentity@[???]
                       Unresolved local var: delta_t * * ppcustom@[???]
                       Unresolved local var: delta_t * * ppplayer@[???] */
  local_c0 = false;
  local_bc = false;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_b4 = 0;
  local_b8 = false;
  local_b0 = 0;
  ppdVar6 = DELTA_LookupRegistration("entity_state_t");
  ppdVar7 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar8 = DELTA_LookupRegistration("custom_entity_state_t");
  if (cls.signon == 1) {
    cls.signon = 2;
    CL_SignonReply();
  }
  iVar5 = cl.parsecountmod;
  cl.frames[cl.parsecountmod].invalid = false;
  iVar9 = MSG_ReadShort();
  iVar17 = 1;
  if (0 < iVar9) {
    iVar17 = iVar9;
  }
  peVar10 = cl.frames[iVar5].packet_entities.entities;
  if (peVar10 != (entity_state_s *)0x0) {
    Mem_Free(peVar10);
  }
  peVar10 = Mem_ZeroMalloc(iVar17 * 0x154);
  cl.frames[iVar5].packet_entities.entities = peVar10;
  cl.frames[iVar5].packet_entities.num_entities = iVar9;
  Q_memset(cl.frames[iVar5].packet_entities.flags,0,0x80);
  if (delta == false) {
    if (cls.demowaiting != false) {
      cls.demowaiting = false;
      MSG_WriteChar(0xdf3c9c,3);
      MSG_WriteString(&cls.netchan.message,"fullupdate");
    }
    if (cl.max_edicts != 0) {
      dest = &local_a8;
      Q_memset(dest,0,0x88);
      local_a8.num_entities = 0;
      local_e8 = true;
LAB_00133d5c:
      cl.validsequence = cls.netchan.incoming_sequence;
      MSG_StartBitReading(&net_message);
      local_f4 = 0;
      iVar17 = 0;
LAB_00133d90:
      do {
        uVar11 = MSG_PeekBits(0x10);
        if (uVar11 == 0) {
          uVar11 = MSG_ReadBits(0x10);
        }
        else {
          uVar11 = CL_ParseDeltaHeader(&local_c0,&local_bc,&local_b0,&local_b8,&local_b4,local_e8,
                                       &local_ac);
        }
        if (uVar11 == 0) {
          if (iVar17 < dest->num_entities) {
            iVar17 = iVar17 - local_f4;
            iVar9 = local_f4 * 0x154;
            do {
              if (0x3ff < local_f4) {
                    /* WARNING: Subroutine does not return */
                Host_EndGame("CL_ParsePacketEntities: newindex == MAX_PACKET_ENTITIES");
              }
              peVar10 = dest->entities;
              peVar3 = cl.frames[iVar5].packet_entities.entities;
              uVar13 = 0;
              do {
                iVar16 = uVar13 + iVar9;
                puVar1 = (undefined4 *)((int)peVar3->origin + uVar13 + iVar9 + -0x10);
                uVar4 = *(undefined4 *)((int)peVar10[iVar17].origin + uVar13 + iVar9 + -0x10);
                uVar13 = uVar13 + 8;
                puVar1[1] = *(undefined4 *)((int)peVar10[iVar17].origin + iVar16 + -0xc);
                *puVar1 = uVar4;
              } while (uVar13 < 0x150);
              local_f4 = local_f4 + 1;
              *(undefined4 *)((int)peVar3->origin + uVar13 + iVar9 + -0x10) =
                   *(undefined4 *)((int)peVar10[iVar17].origin + uVar13 + iVar9 + -0x10);
              iVar9 = iVar9 + 0x154;
            } while (local_f4 + iVar17 < dest->num_entities);
          }
          goto LAB_00133f16;
        }
        uVar12 = 9999;
        if (iVar17 < dest->num_entities) {
          uVar12 = dest->entities[iVar17].number;
        }
        if ((int)uVar12 < (int)uVar11) {
          if (local_e8 != false) {
            Con_Printf("WARNING: oldcopy invalid on non-delta compressed update\n");
            CL_FlushEntityPacket(false);
            peVar10 = cl.frames[iVar5].packet_entities.entities;
            if (peVar10 != (entity_state_s *)0x0) {
              Mem_Free(peVar10);
            }
            cl.frames[iVar5].packet_entities.entities = (entity_state_s *)0x0;
            cl.frames[iVar5].packet_entities.num_entities = 0;
            goto LAB_00133d90;
          }
          iVar9 = local_f4 - iVar17;
          iVar18 = iVar17 - local_f4;
          iVar16 = iVar17 * 0x154;
          do {
            if (0x3ff < local_f4) {
                    /* WARNING: Subroutine does not return */
              Host_EndGame("CL_ParsePacketEntities: newindex == MAX_PACKET_ENTITIES");
            }
            peVar10 = dest->entities;
            peVar3 = cl.frames[iVar5].packet_entities.entities;
            uVar13 = 0;
            do {
              puVar1 = (undefined4 *)((int)peVar10->origin + uVar13 + iVar16 + -0x10);
              uVar4 = puVar1[1];
              *(undefined4 *)((int)peVar3[iVar9].origin + uVar13 + iVar16 + -0x10) = *puVar1;
              *(undefined4 *)((int)peVar3[iVar9].origin + uVar13 + iVar16 + -0xc) = uVar4;
              uVar13 = uVar13 + 8;
            } while (uVar13 < 0x150);
            local_f4 = local_f4 + 1;
            *(undefined4 *)((int)peVar3[iVar9].origin + uVar13 + iVar16 + -0x10) =
                 *(undefined4 *)((int)peVar10->origin + uVar13 + iVar16 + -0x10);
            iVar17 = iVar18 + local_f4;
            uVar12 = 9999;
            if (iVar17 < dest->num_entities) {
              uVar12 = *(uint32 *)((int)dest->entities[1].origin + iVar16 + -0xc);
            }
            iVar16 = iVar16 + 0x154;
          } while ((int)uVar12 < (int)uVar11);
        }
        if ((int)uVar12 <= (int)uVar11) {
          if (uVar11 == uVar12) {
            if (local_e8 != false) {
              cl.validsequence = 0;
              Con_Printf("WARNING: delta on full update");
            }
            if (local_c0 == false) {
              if (local_bc == false) {
                if ((int)uVar11 < 1) {
                  DELTA_ParseDelta((uchar *)(dest->entities + iVar17),
                                   (uchar *)(cl.frames[iVar5].packet_entities.entities + local_f4),
                                   *ppdVar6,0x154);
                  cl.frames[iVar5].packet_entities.entities[local_f4].entityType = 1;
                }
                else {
                  ppdVar15 = ppdVar7;
                  if (cl.maxclients < (int)uVar11) {
                    ppdVar15 = ppdVar6;
                  }
                  iVar9 = DELTA_ParseDelta((uchar *)(dest->entities + iVar17),
                                           (uchar *)(cl.frames[iVar5].packet_entities.entities +
                                                    local_f4),*ppdVar15,0x154);
                  cl.frames[iVar5].packet_entities.entities[local_f4].entityType = 1;
                  if (((int)uVar11 <= cl.maxclients) && (playerbits != (int *)0x0)) {
                    *playerbits = *playerbits + iVar9;
                  }
                }
              }
              else {
                DELTA_ParseDelta((uchar *)(dest->entities + iVar17),
                                 (uchar *)(cl.frames[iVar5].packet_entities.entities + local_f4),
                                 *ppdVar8,0x154);
                cl.frames[iVar5].packet_entities.entities[local_f4].entityType = 2;
              }
              iVar17 = iVar17 + 1;
              cl.frames[iVar5].packet_entities.entities[local_f4].number = uVar11;
              local_f4 = local_f4 + 1;
            }
            else {
              iVar17 = iVar17 + 1;
              R_KillDeadBeams(uVar11);
            }
          }
          goto LAB_00133d90;
        }
                    /* Unresolved local var: entity_state_t.conflict * baseline@[???] */
        if (local_c0 == false) {
          if (0x3ff < local_f4) {
                    /* WARNING: Subroutine does not return */
            Host_EndGame("CL_ParsePacketEntities: newindex == MAX_PACKET_ENTITIES");
          }
          if (local_b8 == false) {
            if (local_ac == 0) {
              peVar10 = &cl_entities[uVar11].baseline;
            }
            else {
              peVar10 = cl.frames[iVar5].packet_entities.entities + (local_f4 - local_ac);
            }
          }
          else {
            peVar10 = cl.instanced_baseline + local_b4;
          }
          CL_EntityNum(uVar11);
          if (local_bc == false) {
            if ((int)uVar11 < 1) {
              DELTA_ParseDelta((uchar *)peVar10,
                               (uchar *)(cl.frames[iVar5].packet_entities.entities + local_f4),
                               *ppdVar6,0x154);
              cl.frames[iVar5].packet_entities.entities[local_f4].entityType = 1;
            }
            else {
              ppdVar15 = ppdVar7;
              if (cl.maxclients < (int)uVar11) {
                ppdVar15 = ppdVar6;
              }
              iVar9 = DELTA_ParseDelta((uchar *)peVar10,
                                       (uchar *)(cl.frames[iVar5].packet_entities.entities +
                                                local_f4),*ppdVar15,0x154);
              cl.frames[iVar5].packet_entities.entities[local_f4].entityType = 1;
              if (((int)uVar11 <= cl.maxclients) && (playerbits != (int *)0x0)) {
                *playerbits = *playerbits + iVar9;
              }
            }
          }
          else {
            DELTA_ParseDelta((uchar *)peVar10,
                             (uchar *)(cl.frames[iVar5].packet_entities.entities + local_f4),
                             *ppdVar8,0x154);
            cl.frames[iVar5].packet_entities.entities[local_f4].entityType = 2;
          }
          cl.frames[iVar5].packet_entities.entities[local_f4].number = uVar11;
          if (((cl_needinstanced.value != 0.0) && (cl.highentity < (int)uVar11)) &&
             (local_b8 == false)) {
            iVar9 = cl.frames[iVar5].packet_entities.entities[local_f4].modelindex;
            pmVar14 = (model_s *)&LAB_00255a7a;
            if (iVar9 != 0) {
              pmVar14 = cl.model_precache[iVar9];
            }
            Con_DPrintf("Non-instanced %i %s without baseline\n",uVar11,pmVar14);
          }
          if ((local_e8 == false) || (cls.passive == false)) {
            pbVar2 = (byte *)(iVar5 * 0x4318 + 0xc6eca4 + (local_f4 >> 3));
            *pbVar2 = *pbVar2 | (byte)(1 << ((byte)local_f4 & 7));
          }
          local_f4 = local_f4 + 1;
          goto LAB_00133d90;
        }
      } while (local_e8 == false);
      Con_Printf("WARNING: remove invalid on non-delta compressed update\n");
      CL_FlushEntityPacket(false);
      peVar10 = cl.frames[iVar5].packet_entities.entities;
      if (peVar10 != (entity_state_s *)0x0) {
        Mem_Free(peVar10);
      }
      cl.frames[iVar5].packet_entities.entities = (entity_state_s *)0x0;
      cl.frames[iVar5].packet_entities.num_entities = 0;
LAB_00133f16:
      MSG_EndBitReading(&net_message);
      if (msg_badread != false) {
                    /* WARNING: Subroutine does not return */
        Host_EndGame("msg_badread in packetentities\n");
      }
      CL_ProcessPacket(cl.frames + iVar5);
      goto LAB_00133cfe;
    }
LAB_00133cc0:
    CL_FlushEntityPacket(true);
    peVar10 = cl.frames[iVar5].packet_entities.entities;
  }
  else {
    uVar13 = MSG_ReadByte();
    if (cl.max_edicts == 0) goto LAB_00133cc0;
    if ((int)(cls.netchan.incoming_sequence - (uVar13 & 0xff) & 0xff) < CL_UPDATE_MASK) {
      local_e8 = false;
      dest = &cl.frames[CL_UPDATE_MASK & uVar13 & 0xff].packet_entities;
      goto LAB_00133d5c;
    }
    CL_FlushEntityPacket(true);
    peVar10 = cl.frames[iVar5].packet_entities.entities;
  }
  if (peVar10 != (entity_state_s *)0x0) {
    Mem_Free(peVar10);
  }
  cl.frames[iVar5].packet_entities.entities = (entity_state_s *)0x0;
  cl.frames[iVar5].packet_entities.num_entities = 0;
LAB_00133cfe:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ParseResourceList  @ 00156080
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseResourceList(void)

{
  uint32 uVar1;
  resource_s *dest;
  resourcetype_t rVar2;
  char *src;
  uint32 uVar3;
  uint32 uVar4;
  resourceinfo_t local_2c;
  
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * resource@[???] */
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_ParseResourceList()");
  }
  uVar4 = 0;
  MSG_StartBitReading(&net_message);
  uVar1 = MSG_ReadBits(0xc);
  if (0 < (int)uVar1) {
    do {
      while( true ) {
        dest = Mem_ZeroMalloc(0x88);
        rVar2 = MSG_ReadBits(4);
        dest->type = rVar2;
        src = MSG_ReadBitString();
        Q_strncpy(dest->szFileName,src,0x3f);
        dest->szFileName[0x3f] = '\0';
        uVar3 = MSG_ReadBits(0xc);
        dest->nIndex = uVar3;
        uVar3 = MSG_ReadBits(0x18);
        dest->nDownloadSize = uVar3;
        uVar3 = MSG_ReadBits(3);
        dest->ucFlags = (byte)uVar3 & 0xfd;
        if ((uVar3 & 4) != 0) {
          MSG_ReadBitData(dest->rgucMD5_hash,0x10);
        }
        uVar3 = MSG_ReadBits(1);
        if (uVar3 != 0) {
          MSG_ReadBitData(dest->rguc_reserved,0x20);
        }
        if ((dest->pPrev != (resource_s *)0x0) || (dest->pNext != (resource_s *)0x0)) break;
        if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
           (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Resource list corrupted.\n");
        }
        dest->pPrev = cl.resourcesneeded.pPrev;
        uVar4 = uVar4 + 1;
        (cl.resourcesneeded.pPrev)->pNext = dest;
        cl.resourcesneeded.pPrev = dest;
        dest->pNext = &cl.resourcesneeded;
        if (uVar1 == uVar4) goto LAB_001561d0;
      }
      Con_Printf("Resource already linked\n");
      uVar4 = uVar4 + 1;
    } while (uVar1 != uVar4);
  }
LAB_001561d0:
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_ParseResourceList()");
  }
  CL_ParseConsistencyInfo();
  MSG_EndBitReading(&net_message);
  SetLoadingProgressBarStatusText("#GameUI_VerifyingResources");
                    /* Unresolved local var: resourceinfo_t ri@[???] */
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_StartResourceDownloading()");
  }
  Con_DPrintf("%s","Verifying and downloading resources...\n");
  cls.dl.nTotalSize = COM_SizeofResourceList(&cl.resourcesneeded,&local_2c);
  cls.dl.nTotalToTransfer = CL_EstimateNeededResources();
  cls.state = ca_uninitialized;
  cls.dl.custom = false;
  cls.dl.fLastStatusUpdate = (float)realtime;
  gfExtendedError = false;
  cls.dl.doneregistering = false;
  cls.dl.nRemainingToTransfer = cls.dl.nTotalToTransfer;
  Q_memset(cls.dl.rgStats,0,0x60);
  cls.dl.nCurStat = 0;
  if (fs_startup_timings.value == 0.0) {
    CL_BatchResourceRequest();
    return;
  }
  AddStartupTiming("end   CL_StartResourceDownloading()");
  CL_BatchResourceRequest();
  return;
}


// CL_ParseResourceLocation  @ 00156390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseResourceLocation(void)

{
  char *__s2;
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: char * url@[???] */
  __s2 = MSG_ReadString();
  if (__s2 != (char *)0x0) {
    iVar1 = strncasecmp("http://",__s2,7);
    if (iVar1 != 0) {
      iVar1 = strncasecmp("https://",__s2,8);
      if (iVar1 != 0) {
        return;
      }
    }
                    /* Unresolved local var: char * lastSlash@[???] */
    pcVar2 = strrchr(__s2,0x2f);
    if ((pcVar2 == (char *)0x0) || (pcVar2[1] != '\0')) {
      __snprintf_chk(0xdf0868,0x80,1,0x80,&DAT_00266b9e,__s2);
    }
    else {
      strncpy(cl.downloadUrl,__s2,0x80);
      cl.downloadUrl[0x7f] = '\0';
    }
    Con_DPrintf("Using %s as primary download location\n",0xdf0868);
  }
  return;
}


// CL_ParseServerInfo  @ 00157020
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseServerInfo(void)

{
  netadr_t addr;
  float value;
  int iVar1;
  int iVar2;
  qboolean qVar3;
  char *pcVar4;
  customization_t *pHead;
  customization_t *pcVar5;
  int iVar6;
  resource_t *pResource;
  int in_GS_OFFSET;
  char local_1024 [20];
  char local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: char * str@[???]
                       Unresolved local var: char * gamedir@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int mungebuffer@[???]
                       Unresolved local var: char[4096] mapBaseName@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_ParseServerInfo()");
  }
  HPAK_CheckSize("custom");
  Con_DPrintf("Serverinfo packet received.\n");
  ContinueLoadingProgressBar("ClientConnect",3,0.0);
  SetLoadingProgressBarStatusText("#GameUI_ParseServerInfo");
  if (cls.passive != false) {
    addr.ip[0] = cls.connect_stream.ip[0];
    addr.ip[1] = cls.connect_stream.ip[1];
    addr.ip[2] = cls.connect_stream.ip[2];
    addr.ip[3] = cls.connect_stream.ip[3];
    addr.type = cls.connect_stream.type;
    addr.ipx[0] = cls.connect_stream.ipx[0];
    addr.ipx[1] = cls.connect_stream.ipx[1];
    addr.ipx[2] = cls.connect_stream.ipx[2];
    addr.ipx[3] = cls.connect_stream.ipx[3];
    addr.ipx[4] = cls.connect_stream.ipx[4];
    addr.ipx[5] = cls.connect_stream.ipx[5];
    addr.ipx[6] = cls.connect_stream.ipx[6];
    addr.ipx[7] = cls.connect_stream.ipx[7];
    addr.ipx[8] = cls.connect_stream.ipx[8];
    addr.ipx[9] = cls.connect_stream.ipx[9];
    addr.port = cls.connect_stream.port;
    NET_LeaveGroup(cls.netchan.sock,addr);
  }
  CL_ClearState(false);
  ClientDLL_HudVidInit();
  cls.demowaiting = false;
  iVar2 = MSG_ReadLong();
  if ((iVar2 == 0x30) || (cls.demoplayback != false)) {
    cl.servercount = MSG_ReadLong();
    if (cls.demoplayback != false) {
      gHostSpawnCount = gHostSpawnCount + 1;
      cl.servercount = gHostSpawnCount;
    }
    cl.serverCRC = MSG_ReadLong();
    MSG_ReadBuf(0x10,cl.clientdllmd5);
    cl.maxclients = MSG_ReadByte();
    if (cl.maxclients - 1U < 0x20) {
      value = mp_decals.value;
      if (cl.maxclients == 1) {
        value = sp_decals.value;
      }
      Cvar_SetValue("r_decals",value);
      R_ForceCVars((uint)(1 < cl.maxclients));
      if (cl_entities != (cl_entity_t *)0x0) {
        Mem_Free(cl_entities);
        cl_entities = (cl_entity_t *)0x0;
      }
      R_DestroyObjects();
      cl.max_edicts = COM_EntsForPlayerSlots(cl.maxclients);
      if (cl.max_edicts < 1) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("CL_ReallocateDynamicData allocating 0 entities");
      }
      if (cl_entities != (cl_entity_t *)0x0) {
        Con_Printf("CL_Reallocate cl_entities\n");
      }
      cl_entities = Mem_ZeroMalloc(cl.max_edicts * 3000);
      R_AllocObjects(cl.max_edicts);
      Q_memset(cl.frames,0,CL_UPDATE_BACKUP * 0x4318);
      cl.playernum = MSG_ReadByte();
      COM_UnMunge3((uchar *)&cl.serverCRC,4,(uint)(byte)~(byte)cl.playernum);
      pHead = &cl.players[0].customdata;
      do {
        pcVar5 = (customization_t *)(pHead[3].resource.rguc_reserved + 2);
        COM_ClearCustomizationList(pHead,true);
        iVar1 = cl.playernum;
        iVar2 = cl.num_resources;
        pHead = pcVar5;
      } while (pcVar5 != (customization_t *)&cl.instanced_baseline[1].scale);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: player_info_t * pPlayer@[???] */
      cl.players[cl.playernum].customdata.pNext = (customization_s *)0x0;
      if (0 < iVar2) {
        pResource = cl.resourcelist;
        iVar6 = 0;
        iVar2 = iVar1;
        do {
          qVar3 = COM_CreateCustomization
                            (&cl.players[iVar1].customdata,pResource,iVar2,0,(customization_t **)0x0
                             ,(int *)0x0);
          if (qVar3 == false) {
            Con_DPrintf("Problem with client customization %i, ignoring...",iVar6);
            if (cl.num_resources <= iVar6 + 1) break;
          }
          else if (cl.num_resources <= iVar6 + 1) break;
          pResource = pResource + 1;
          iVar6 = iVar6 + 1;
          iVar2 = cl.playernum;
        } while( true );
      }
      cl.gametype = MSG_ReadByte();
      pcVar4 = MSG_ReadString();
                    /* Unresolved local var: char[260] szGD@[???] */
      if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
        Con_Printf("Server didn\'t specify a gamedir, assuming no change\n");
      }
      else {
        COM_FileBase(com_gamedir,local_1010);
        iVar2 = Q_stricmp(local_1010,pcVar4);
        if (iVar2 != 0) {
                    /* Unresolved local var: char[260] szGD@[???] */
          Con_Printf("Server is running game %s.  Restart in that game to connect.\n",pcVar4);
          CL_Disconnect_f();
          goto LAB_00157390;
        }
      }
      pcVar4 = MSG_ReadString();
      Con_DPrintf("Remote host:  %s\n",pcVar4);
      pcVar4 = MSG_ReadString();
      Q_strncpy(cl.levelname,pcVar4,0x27);
      cl.levelname[0x27] = '\0';
      MSG_SkipString();
      COM_FileBase(cl.levelname,local_1010);
      if (1 < cl.maxclients) {
                    /* Unresolved local var: char * mapcycle@[???] */
        FS_LogLevelLoadStarted(local_1010);
        VGuiWrap2_LoadingStarted("level",local_1010);
      }
      cls.isVAC2Secure = MSG_ReadByte();
      qVar3 = CL_CheckCRCs(cl.levelname);
      if (qVar3 != false) {
                    /* Unresolved local var: char[20] szSendres@[???] */
        cls.state = ca_connected;
        gHostSpawnCount = cl.servercount;
        CL_BeginDemoStartup();
        SetSecondaryProgressBar(100.0);
        builtin_strncpy(local_1024,"sendres",8);
        MSG_WriteByte(&cls.netchan.message,3);
        MSG_WriteString(&cls.netchan.message,local_1024);
        if (fs_startup_timings.value != 0.0) {
          AddStartupTiming("end   CL_ParseServerInfo()");
        }
        Steam_UpdateRichPresence();
      }
    }
    else {
      Con_Printf("Bad maxclients (%u) from server\n",cl.maxclients);
    }
  }
  else {
    Con_Printf("Server returned version %i, not %i\n",iVar2,0x30);
  }
LAB_00157390:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ParseServerList  @ 00145220
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseServerList(void)

{
  _func_short_short *p_Var1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int in_GS_OFFSET;
  undefined4 local_a4;
  undefined4 local_a0;
  int aiStack_9c [35];
  
                    /* Unresolved local var: char[128] szAddress@[???]
                       Unresolved local var: uchar[4] cIP@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: ushort iIPPort@[???]
                       Unresolved local var: int nNumAddresses@[???]
                       Unresolved local var: int count@[???] */
  aiStack_9c[0x1f] = *(int *)(in_GS_OFFSET + 0x14);
  local_a0 = 0;
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    *(undefined4 *)((int)aiStack_9c + uVar4) = 0;
    *(undefined4 *)((int)aiStack_9c + uVar4 + 4) = 0;
    uVar2 = uVar4 + 8;
  } while (uVar4 + 8 < 0x78);
  *(undefined4 *)((int)aiStack_9c + uVar4 + 8) = 0;
  MSG_ReadByte();
  iVar8 = (net_message.cursize + -6) / 6;
  if (iVar8 < 1) {
    iVar8 = 1;
  }
  else {
    iVar8 = iVar8 + 1;
    iVar9 = 1;
    do {
      Q_memset(&local_a0,0,0x80);
      puVar6 = &local_a4;
      do {
        iVar5 = MSG_ReadByte();
        puVar7 = (undefined4 *)((int)puVar6 + 1);
        *(char *)puVar6 = (char)iVar5;
        puVar6 = puVar7;
      } while (puVar7 != &local_a0);
      __snprintf_chk(&local_a0,0x80,1,0x80,0x261038,(undefined1)local_a4,local_a4._1_1_,
                     local_a4._2_1_,local_a4._3_1_);
      p_Var1 = BigShort;
      iVar5 = MSG_ReadShort();
      sVar3 = (*p_Var1)((short)iVar5);
      if (iVar9 < 0x65) {
        Con_Printf("%4i:  %s:%i\n",iVar9,&local_a0,sVar3);
      }
      iVar9 = iVar9 + 1;
    } while (iVar8 != iVar9);
  }
  Con_Printf("%i total servers\n",iVar8);
  if (aiStack_9c[0x1f] != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_ParseServerMessage  @ 00158640
/* WARNING: Removing unreachable block (ram,0x00158ad7) */
/* WARNING: Removing unreachable block (ram,0x00158aaf) */
/* WARNING: Removing unreachable block (ram,0x00158ac3) */
/* WARNING: Removing unreachable block (ram,0x00158e28) */
/* WARNING: Removing unreachable block (ram,0x00158e10) */
/* WARNING: Removing unreachable block (ram,0x00158af0) */
/* WARNING: Removing unreachable block (ram,0x00158c7d) */
/* WARNING: Removing unreachable block (ram,0x00158c93) */
/* WARNING: Removing unreachable block (ram,0x00158ca9) */

void CL_ParseServerMessage(qboolean normal_message)

{
  ushort *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  code *pcVar6;
  char *str;
  short sVar7;
  short sVar8;
  short sVar9;
  cactive_t cVar10;
  int start;
  double dVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  
                    /* Unresolved local var: int cmd@[???]
                       Unresolved local var: int playerbits@[???]
                       Unresolved local var: int starting_count@[???]
                       Unresolved local var: int bufStart@[???]
                       Unresolved local var: int bufEnd@[???] */
  start = msg_readcount;
  if (cl_shownet.value == 1.0) {
    Con_Printf("%i ",net_message.cursize);
  }
  else if (cl_shownet.value == 2.0) {
    Con_Printf("------------------\n");
  }
  Q_memset(last_data,0,0x100);
  dVar11 = cl.mtime[0];
  iVar14 = msg_readcount;
  if (normal_message != false) {
    uVar12 = cls.netchan.incoming_sequence & CL_UPDATE_MASK;
    if (cls.state == ca_active) {
      cl.frames[uVar12].invalid = true;
      cl.frames[uVar12].choked = false;
      iVar14 = msg_readcount;
    }
    else {
      cl.frames[uVar12].receivedtime = realtime;
      cl.frames[uVar12].time = dVar11;
      cl.frames[uVar12].invalid = false;
      cl.frames[uVar12].choked = false;
      *(undefined4 *)&cl.frames[uVar12].latency = 0;
      *(undefined4 *)((int)&cl.frames[uVar12].latency + 4) = 0;
      cl.frames[uVar12].clientbytes = 0;
      cl.frames[uVar12].packetentitybytes = 0;
      cl.frames[uVar12].tentitybytes = 0;
      cl.frames[uVar12].playerinfobytes = 0;
      cl.frames[uVar12].soundbytes = 0;
      cl.frames[uVar12].usrbytes = 0;
      cl.frames[uVar12].eventbytes = 0;
      cl.frames[uVar12].msgbytes = 0;
      iVar14 = msg_readcount;
    }
  }
joined_r0x00158757:
  while( true ) {
    msg_readcount = iVar14;
    if (msg_badread != false) {
                    /* WARNING: Subroutine does not return */
      Host_Error("CL_ParseServerMessage: Bad server message");
    }
    uVar12 = MSG_ReadByte();
    if (uVar12 == 0xffffffff) {
      cVar10 = cls.state;
      if ((cl_shownet.value == 2.0) &&
         (iVar14 = Q_strlen("END OF MESSAGE"), cVar10 = cls.state, 1 < iVar14)) {
        Con_Printf("%3i:%s\n",msg_readcount + -1,"END OF MESSAGE");
        cVar10 = cls.state;
      }
      cls.state = cVar10;
      if (cVar10 == ca_active) {
        puVar1 = &cl.frames[cl.parsecountmod].msgbytes;
        *puVar1 = *puVar1 + (short)net_message.cursize;
      }
      total_data[0] = last_data[0] + total_data[0];
      total_data[1] = last_data[1] + total_data[1];
      total_data[2] = last_data[2] + total_data[2];
      total_data[3] = last_data[3] + total_data[3];
      total_data[4] = last_data[4] + total_data[4];
      total_data[5] = last_data[5] + total_data[5];
      total_data[6] = last_data[6] + total_data[6];
      total_data[7] = last_data[7] + total_data[7];
      total_data[8] = last_data[8] + total_data[8];
      total_data[9] = last_data[9] + total_data[9];
      total_data[10] = last_data[10] + total_data[10];
      total_data[0xb] = last_data[0xb] + total_data[0xb];
      total_data[0xc] = last_data[0xc] + total_data[0xc];
      total_data[0xd] = last_data[0xd] + total_data[0xd];
      total_data[0xe] = last_data[0xe] + total_data[0xe];
      total_data[0xf] = last_data[0xf] + total_data[0xf];
      total_data[0x10] = last_data[0x10] + total_data[0x10];
      total_data[0x11] = last_data[0x11] + total_data[0x11];
      total_data[0x12] = last_data[0x12] + total_data[0x12];
      total_data[0x13] = last_data[0x13] + total_data[0x13];
      total_data[0x14] = last_data[0x14] + total_data[0x14];
      total_data[0x15] = last_data[0x15] + total_data[0x15];
      total_data[0x16] = last_data[0x16] + total_data[0x16];
      total_data[0x17] = last_data[0x17] + total_data[0x17];
      total_data[0x18] = last_data[0x18] + total_data[0x18];
      total_data[0x19] = last_data[0x19] + total_data[0x19];
      total_data[0x1a] = last_data[0x1a] + total_data[0x1a];
      total_data[0x1b] = last_data[0x1b] + total_data[0x1b];
      total_data[0x1c] = last_data[0x1c] + total_data[0x1c];
      total_data[0x1d] = last_data[0x1d] + total_data[0x1d];
      total_data[0x1e] = last_data[0x1e] + total_data[0x1e];
      total_data[0x1f] = last_data[0x1f] + total_data[0x1f];
      total_data[0x20] = last_data[0x20] + total_data[0x20];
      total_data[0x21] = last_data[0x21] + total_data[0x21];
      total_data[0x22] = last_data[0x22] + total_data[0x22];
      total_data[0x23] = last_data[0x23] + total_data[0x23];
      total_data[0x24] = last_data[0x24] + total_data[0x24];
      total_data[0x25] = last_data[0x25] + total_data[0x25];
      total_data[0x26] = last_data[0x26] + total_data[0x26];
      total_data[0x27] = last_data[0x27] + total_data[0x27];
      total_data[0x28] = last_data[0x28] + total_data[0x28];
      total_data[0x29] = last_data[0x29] + total_data[0x29];
      total_data[0x2a] = last_data[0x2a] + total_data[0x2a];
      total_data[0x2b] = last_data[0x2b] + total_data[0x2b];
      total_data[0x2c] = last_data[0x2c] + total_data[0x2c];
      total_data[0x2d] = last_data[0x2d] + total_data[0x2d];
      total_data[0x2e] = last_data[0x2e] + total_data[0x2e];
      total_data[0x2f] = last_data[0x2f] + total_data[0x2f];
      total_data[0x30] = last_data[0x30] + total_data[0x30];
      total_data[0x31] = last_data[0x31] + total_data[0x31];
      total_data[0x32] = last_data[0x32] + total_data[0x32];
      total_data[0x33] = last_data[0x33] + total_data[0x33];
      total_data[0x34] = last_data[0x34] + total_data[0x34];
      total_data[0x35] = last_data[0x35] + total_data[0x35];
      total_data[0x36] = last_data[0x36] + total_data[0x36];
      total_data[0x37] = last_data[0x37] + total_data[0x37];
      total_data[0x38] = last_data[0x38] + total_data[0x38];
      total_data[0x39] = last_data[0x39] + total_data[0x39];
      total_data[0x3a] = last_data[0x3a] + total_data[0x3a];
      total_data[0x3b] = last_data[0x3b] + total_data[0x3b];
      total_data[0x3c] = last_data[0x3c] + total_data[0x3c];
      total_data[0x3d] = last_data[0x3d] + total_data[0x3d];
      total_data[0x3e] = last_data[0x3e] + total_data[0x3e];
      total_data[0x3f] = last_data[0x3f] + total_data[0x3f];
      if (cls.demoplayback == false) {
        if (cVar10 != ca_active) {
          CL_WriteDemoStartup(start,&net_message);
        }
        if ((cls.demorecording != false) && (cls.demowaiting == false)) {
          CL_WriteDemoMessage(start,&net_message);
          return;
        }
      }
      return;
    }
    sVar8 = (short)iVar14;
    if (uVar12 == 1) break;
    uVar15 = currentcmd & 0x1f;
    oldcmd[uVar15].command = uVar12;
    oldcmd[uVar15].starting_offset = iVar14;
    currentcmd = currentcmd + 1;
    oldcmd[uVar15].frame_number = host_framecount;
    if ((int)uVar12 < 0x3c) {
      if (cl_shownet.value == 2.0) goto LAB_00158950;
      goto joined_r0x001587d5;
    }
    msg_buckets[0x3f] = msg_buckets[0x3f] + 1;
    DispatchUserMsg(uVar12);
    last_data[0x3f] = last_data[0x3f] + (msg_readcount - iVar14);
    uVar3 = cl.frames[cl.parsecountmod].usrbytes;
    cl.frames[cl.parsecountmod].usrbytes = (uVar3 + (short)msg_readcount) - sVar8;
    iVar14 = msg_readcount;
  }
  if (cl_shownet.value == 2.0) {
LAB_00158950:
    str = cl_parsefuncs[uVar12].pszname;
    iVar13 = Q_strlen(str);
    if (1 < iVar13) {
      Con_Printf("%3i:%s\n",msg_readcount + -1,str);
    }
joined_r0x001587d5:
    if ((uVar12 < 0x40) && (msg_buckets[uVar12] = msg_buckets[uVar12] + 1, uVar12 == 0)) {
      CL_WriteMessageHistory(start,0);
                    /* WARNING: Subroutine does not return */
      Host_Error("CL_ParseServerMessage: Illegible server message - %s\n","svc_bad");
    }
    pcVar6 = cl_parsefuncs[uVar12].pfnParse;
    if (pcVar6 != (code *)0x0) {
                    /* Unresolved local var: _func_void * func@[???] */
      if (cl_showmessages.value != 0.0) {
        Con_DPrintf("Msg: %s\n",cl_parsefuncs[uVar12].pszname);
      }
      (*pcVar6)();
    }
    iVar13 = msg_readcount;
    last_data[uVar12] = last_data[uVar12] + (msg_readcount - iVar14);
    iVar14 = cl.parsecountmod;
    sVar7 = (short)iVar13;
    if (uVar12 - 0x28 < 2) {
                    /* Unresolved local var: int playerbytes@[???] */
      iVar13 = cls.playerbits + 7;
      if (-1 < cls.playerbits) {
        iVar13 = cls.playerbits;
      }
      sVar9 = (short)(iVar13 >> 3);
      uVar4 = cl.frames[cl.parsecountmod].packetentitybytes;
      cl.frames[cl.parsecountmod].packetentitybytes = sVar7 + ((uVar4 - sVar8) - sVar9);
      puVar1 = &cl.frames[iVar14].playerinfobytes;
      *puVar1 = *puVar1 + sVar9;
      iVar14 = msg_readcount;
      goto joined_r0x00158757;
    }
    if (uVar12 == 0x17) {
      cl.frames[cl.parsecountmod].tentitybytes =
           (sVar7 + cl.frames[cl.parsecountmod].tentitybytes) - sVar8;
      iVar14 = msg_readcount;
      goto joined_r0x00158757;
    }
    if (uVar12 == 6) {
      uVar5 = cl.frames[cl.parsecountmod].soundbytes;
      cl.frames[cl.parsecountmod].soundbytes = (sVar7 + uVar5) - sVar8;
      iVar14 = msg_readcount;
      goto joined_r0x00158757;
    }
    if (uVar12 == 0xf) {
      uVar2 = cl.frames[cl.parsecountmod].clientbytes;
      cl.frames[cl.parsecountmod].clientbytes = (sVar7 + uVar2) - sVar8;
      iVar14 = msg_readcount;
      goto joined_r0x00158757;
    }
  }
  else {
    msg_buckets[1] = msg_buckets[1] + 1;
    last_data[1] = last_data[1] + (msg_readcount - iVar14);
    iVar13 = msg_readcount;
  }
  if ((uVar12 == 3) || (iVar14 = msg_readcount, uVar12 == 0x15)) {
    cl.frames[cl.parsecountmod].eventbytes =
         (short)iVar13 + (cl.frames[cl.parsecountmod].eventbytes - sVar8);
    iVar14 = msg_readcount;
  }
  goto joined_r0x00158757;
}


// CL_ParseSoundFade  @ 00157bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseSoundFade(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int percent@[???]
                       Unresolved local var: int inTime@[???]
                       Unresolved local var: int holdTime@[???]
                       Unresolved local var: int outTime@[DW_OP_reg0(EAX)] */
  iVar1 = MSG_ReadByte();
  iVar2 = MSG_ReadByte();
  iVar3 = MSG_ReadByte();
  cls.soundfade.soundFadeOutTime = MSG_ReadByte();
  cls.soundfade.soundFadeStartTime = realtime;
  cls.soundfade.nStartPercent = iVar1;
  cls.soundfade.soundFadeHoldTime = iVar2;
  cls.soundfade.soundFadeInTime = iVar3;
  return;
}


// CL_ParseStatic  @ 001578b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseStatic(void)

{
  return;
}


// CL_ParseStaticSound  @ 001578c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseStaticSound(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int entnum;
  int pitch;
  uint flags;
  sfx_t *psVar4;
  sfx_s *sfxin;
  int in_GS_OFFSET;
  float fVar5;
  undefined1 local_74 [84];
  int local_20;
  
                    /* Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int sound_num@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: float atten@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int ent@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  psVar4 = (sfx_t *)local_74;
  do {
    sfxin = (sfx_s *)(psVar4->name + 4);
    fVar5 = MSG_ReadCoord(&net_message);
    *(float *)psVar4->name = fVar5;
    psVar4 = sfxin;
  } while (sfxin != (sfx_t *)(local_74 + 0xc));
  iVar1 = MSG_ReadShort();
  iVar2 = MSG_ReadByte();
  iVar3 = MSG_ReadByte();
  entnum = MSG_ReadShort();
  pitch = MSG_ReadByte();
  flags = MSG_ReadByte();
  if ((flags & 0x10) == 0) {
    sfxin = cl.sound_precache[iVar1];
  }
  else {
    __snprintf_chk(sfxin,0x40,1,0x40,&DAT_00263ab4,rgpszrawsentence[iVar1]);
  }
  S_StartStaticSound(entnum,6,sfxin,(vec_t *)local_74,(float)iVar2 / 255.0,(float)iVar3 * 0.015625,
                     flags,pitch);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ParseTEnt  @ 0014fbb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseTEnt(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  customization_s *pcVar5;
  cachewad_t *wad;
  _func_void_cl_entity_s_ptr_int_int *p_Var6;
  _func_void_TEMPENTITY_ptr_float_int *p_Var7;
  _func_void_TEMPENTITY_ptr_float *p_Var8;
  _func_void_float_ptr_float_float_int_int *p_Var9;
  _func_TEMPENTITY_ptr_float_ptr_float_ptr_float_ptr_float_int_int *p_Var10;
  _func_void_int_int_int_float_ptr_int *p_Var11;
  _func_BEAM_ptr_float_ptr_float_ptr_int_float_float_float_float_float_int_float_float_float_float
  *p_Var12;
  double dVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  texture_t *ptexture;
  int32 iVar20;
  dlight_t *pdVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  TEMPENTITY *pTVar28;
  int unaff_EBP;
  longdouble lVar29;
  longdouble lVar30;
  float fVar31;
  float fVar32;
  int local_a4;
  int local_74;
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
  vec_t local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int type@[???]
                       Unresolved local var: int soundtype@[???]
                       Unresolved local var: int speed@[???]
                       Unresolved local var: int color@[???]
                       Unresolved local var: int iRand@[???]
                       Unresolved local var: int entnumber@[???]
                       Unresolved local var: int modelIndex@[???]
                       Unresolved local var: int modelIndex2@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: vec3_t endpos@[???]
                       Unresolved local var: dlight_t * dl@[???]
                       Unresolved local var: int colorStart@[???]
                       Unresolved local var: int colorLength@[???]
                       Unresolved local var: int startEnt@[???]
                       Unresolved local var: int endEnt@[???]
                       Unresolved local var: int startFrame@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: float life@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: float frameRate@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int[1] index_array@[???]
                       Unresolved local var: uchar br@[???]
                       Unresolved local var: uchar bg@[???]
                       Unresolved local var: uchar bb@[???] */
  iVar15 = MSG_ReadByte();
  switch(iVar15) {
  case 0:
  case 1:
  case 8:
    if (iVar15 == 8) {
      unaff_EBP = MSG_ReadShort();
      local_74 = MSG_ReadShort();
    }
    else {
      if (iVar15 == 1) {
        unaff_EBP = MSG_ReadShort();
      }
      else {
        local_64 = MSG_ReadCoord(&net_message);
        local_60 = MSG_ReadCoord(&net_message);
        local_5c = MSG_ReadCoord(&net_message);
      }
      local_4c = MSG_ReadCoord(&net_message);
      local_48 = MSG_ReadCoord(&net_message);
      local_44 = MSG_ReadCoord(&net_message);
    }
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    fVar31 = (float)((longdouble)0.1 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar32 = (float)((longdouble)0.1 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    local_58 = (float)uVar22;
    iVar18 = MSG_ReadByte();
    local_54 = (float)iVar18;
    uVar22 = MSG_ReadByte();
    fVar1 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar2 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar3 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar4 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    iVar18 = MSG_ReadByte();
    iVar18 = (int)((float)iVar18 * 0.1);
    if (iVar15 == 8) {
      (*efx.R_BeamEnts)(unaff_EBP,local_74,iVar16,fVar32,local_58 * 0.1,local_54 * 0.01,fVar4,
                        (float)iVar18,iVar17,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar15 == 1) {
      (*efx.R_BeamEntPoint)
                (unaff_EBP,&local_4c,iVar16,fVar32,local_58 * 0.1,local_54 * 0.01,fVar4,
                 (float)iVar18,iVar17,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar15 == 0) {
      (*efx.R_BeamPoints)(&local_64,&local_4c,iVar16,fVar32,local_58 * 0.1,local_54 * 0.01,fVar4,
                          (float)iVar18,iVar17,fVar31,fVar1,fVar2,fVar3);
    }
    break;
  case 2:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    (*efx.R_RunParticleEffect)(&local_64,vec3_origin,0,0x14);
    (*efx.R_RicochetSound)(&local_64);
    break;
  case 3:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    local_58 = (float)iVar16 * 0.1;
    iVar16 = MSG_ReadByte();
    local_54 = (float)iVar16;
    uVar22 = MSG_ReadByte();
    fVar31 = local_58;
    p_Var7 = efx.R_Sprite_Explode;
    if (local_58 != 0.0) {
      pTVar28 = R_DefaultSprite(&local_64,iVar15,local_54);
      (*p_Var7)(pTVar28,fVar31,uVar22);
      if ((uVar22 & 8) == 0) {
        (*efx.R_FlickerParticles)(&local_64);
      }
      if ((uVar22 & 2) == 0) {
        pdVar21 = (*efx.CL_AllocDlight)(0);
        pdVar21->origin[0] = local_64;
        pdVar21->origin[1] = local_60;
        pdVar21->radius = 200.0;
        (pdVar21->color).g = 0xfa;
        pdVar21->origin[2] = local_5c;
        (pdVar21->color).r = 0xfa;
        (pdVar21->color).b = 0x96;
        pdVar21->die = (float)((longdouble)0.01 + (longdouble)cl.time);
        pdVar21->decay = 800.0;
        pdVar21 = (*efx.CL_AllocDlight)(0);
        pdVar21->origin[0] = local_64;
        pdVar21->origin[1] = local_60;
        pdVar21->radius = 150.0;
        (pdVar21->color).r = 0xff;
        pdVar21->origin[2] = local_5c;
        (pdVar21->color).g = 0xbe;
        (pdVar21->color).b = '(';
        pdVar21->die = (float)cl.time + 1.0;
        pdVar21->decay = 200.0;
      }
    }
    if ((uVar22 & 4) != 0) {
      return;
    }
    iVar20 = RandomLong(0,2);
    if (iVar20 == 1) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp2,&local_64,1.0,0.3,0,100);
      return;
    }
    if (iVar20 == 2) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp3,&local_64,1.0,0.3,0,100);
      return;
    }
    if (iVar20 != 0) {
      return;
    }
    fVar31 = 0.3;
    goto LAB_00151cfb;
  case 4:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    (*efx.R_BlobExplosion)(&local_64);
    fVar31 = 1.0;
    goto LAB_00151cfb;
  case 5:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    local_58 = (float)iVar16 * 0.1;
    iVar16 = MSG_ReadByte();
    fVar31 = local_58;
    p_Var8 = efx.R_Sprite_Smoke;
    local_54 = (float)iVar16;
    pTVar28 = R_DefaultSprite(&local_64,iVar15,local_54);
    (*p_Var8)(pTVar28,fVar31);
    break;
  case 6:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    (*efx.R_TracerEffect)(&local_64,&local_4c);
    break;
  case 7:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    local_58 = (float)iVar16;
    iVar16 = MSG_ReadByte();
    local_54 = (float)iVar16;
    iVar16 = MSG_ReadShort();
    (*efx.R_BeamLightning)
              (&local_64,&local_4c,iVar16,(float)iVar15 * 0.1,local_58 * 0.1,local_54 * 0.01,0.6,3.5
              );
    break;
  case 9:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    (*efx.R_SparkEffect)(&local_64,8,-200,200);
    break;
  case 10:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    (*efx.R_LavaSplash)(&local_64);
    break;
  case 0xb:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    (*efx.R_TeleportSplash)(&local_64);
    break;
  case 0xc:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_ParticleExplosion2)(&local_64,iVar15,iVar16);
    pdVar21 = (*efx.CL_AllocDlight)(0);
    pdVar21->origin[0] = local_64;
    pdVar21->origin[1] = local_60;
    pdVar21->radius = 350.0;
    pdVar21->origin[2] = local_5c;
    pdVar21->die = (float)cl.time + 0.5;
    pdVar21->decay = 300.0;
    fVar31 = 0.6;
LAB_00151cfb:
    S_StartDynamicSound(-1,0,cl_sfx_r_exp1,&local_64,1.0,fVar31,0,100);
    break;
  case 0xd:
  case 0x68:
  case 0x74:
  case 0x75:
  case 0x76:
                    /* Unresolved local var: int decalTextureIndex@[???] */
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    if (iVar15 == 0xd) {
      iVar16 = MSG_ReadShort();
      iVar17 = MSG_ReadShort();
      if (iVar17 != 0) {
        iVar18 = MSG_ReadShort();
        local_a4 = 1;
        goto LAB_00151bbd;
      }
      iVar18 = 0;
      local_a4 = 1;
    }
    else {
      iVar16 = MSG_ReadByte();
      if ((iVar15 == 0x68) || (iVar15 == 0x76)) {
        iVar17 = MSG_ReadShort();
        iVar18 = 0;
        local_a4 = 0;
      }
      else {
        iVar17 = 0;
        local_a4 = 0;
        iVar18 = 0;
      }
LAB_00151bbd:
      if (iVar15 - 0x75U < 2) {
        iVar16 = iVar16 + 0x100;
      }
    }
    p_Var11 = efx.R_DecalShoot;
    if (cl.max_edicts <= iVar17) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Decal: entity = %i",iVar17);
    }
    if (r_decals.value != 0.0) {
      iVar15 = (*efx.Draw_DecalIndex)(iVar16);
      (*p_Var11)(iVar15,iVar17,iVar18,&local_64,local_a4);
    }
    break;
  case 0xe:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    local_58 = (float)iVar15;
    iVar15 = MSG_ReadByte();
    local_54 = (float)iVar15;
    iVar15 = MSG_ReadByte();
    local_50 = (float)iVar15 / 10.0;
    (*efx.R_Implosion)(&local_64,local_58,(int)local_54,local_50);
    break;
  case 0xf:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    if ((longdouble)uVar23 == (longdouble)0) {
      local_58 = 1.0;
    }
    else {
      local_58 = (float)((longdouble)0.1 * (longdouble)uVar23);
    }
    iVar17 = MSG_ReadByte();
    local_54 = (float)iVar17 * 10.0;
    iVar17 = MSG_ReadByte();
    (*efx.R_Sprite_Trail)
              (0xf,&local_64,&local_4c,iVar15,iVar16,(float)((longdouble)0.1 * (longdouble)uVar22),
               local_58,local_54,0xff,(float)(int)((double)iVar17 * 10.0));
    break;
  default:
                    /* WARNING: Subroutine does not return */
    Sys_Error("CL_ParseTEnt: bad type");
  case 0x11:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    local_58 = (float)iVar16 * 0.1;
    uVar22 = MSG_ReadByte();
    (*efx.R_TempSprite)(&local_64,vec3_origin,local_58,iVar15,5,0,
                        (float)((longdouble)0.00392156862745098 * (longdouble)uVar22),0.0,0x100);
    break;
  case 0x12:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    p_Var12 = efx.R_BeamPoints;
    fVar31 = RandomFloat(0.5,0.655);
    (*p_Var12)(&local_64,&local_4c,iVar15,0.01,0.4,0.0,fVar31,5.0,0,0.0,1.0,0.0,0.0);
    (*efx.R_TempSprite)(&local_4c,vec3_origin,0.1,iVar16,5,0,0.35,0.01,0);
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    local_58 = (float)uVar24;
    iVar18 = MSG_ReadByte();
    local_54 = (float)iVar18;
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    uVar27 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamCirclePoints)
              (iVar15,&local_64,&local_4c,iVar16,(float)((longdouble)uVar23 * lVar30),local_58,
               local_54 * 0.01,(float)((longdouble)uVar27 * lVar29),
               (float)(int)((longdouble)iVar18 * lVar30),iVar17,(float)((longdouble)uVar22 * lVar30)
               ,(float)((longdouble)uVar24 * lVar29),(float)((longdouble)uVar25 * lVar29),
               (float)((longdouble)uVar26 * lVar29));
    break;
  case 0x16:
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    local_58 = (float)uVar23;
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    (*efx.R_BeamFollow)(iVar15,iVar16,(float)((longdouble)0.1 * (longdouble)uVar22),local_58,
                        (float)((longdouble)uVar23 * lVar29),(float)((longdouble)uVar24 * lVar29),
                        (float)((longdouble)uVar25 * lVar29),(float)((longdouble)uVar26 * lVar29));
    break;
  case 0x17:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    uVar22 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    local_58 = (float)iVar16 * 0.1;
    uVar23 = MSG_ReadByte();
    (*efx.R_TempSprite)(&local_64,vec3_origin,local_58,iVar15,3,0xe,
                        (float)((longdouble)0.00392156862745098 * (longdouble)uVar23),
                        (float)((longdouble)0.1 * (longdouble)uVar22),0x80);
    break;
  case 0x18:
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    iVar18 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    local_58 = (float)uVar24;
    iVar19 = MSG_ReadByte();
    local_54 = (float)iVar19;
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    uVar27 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamRing)(iVar15,iVar16,iVar17,(float)((longdouble)uVar23 * lVar30),
                      (float)(lVar30 * (longdouble)local_58),local_54 * 0.01,
                      (float)((longdouble)uVar27 * lVar29),(float)(int)((longdouble)iVar19 * lVar30)
                      ,iVar18,(float)((longdouble)uVar22 * lVar30),
                      (float)((longdouble)uVar24 * lVar29),(float)((longdouble)uVar25 * lVar29),
                      (float)((longdouble)uVar26 * lVar29));
    break;
  case 0x19:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    iVar18 = MSG_ReadShort();
    (*efx.R_StreakSplash)(&local_64,&local_28,iVar15,iVar16,(float)iVar17,-iVar18,iVar18);
    break;
  case 0x1b:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    pdVar21 = (*efx.CL_AllocDlight)(0);
    pdVar21->origin[0] = local_64;
    pdVar21->origin[1] = local_60;
    pdVar21->origin[2] = local_5c;
    iVar15 = MSG_ReadByte();
    pdVar21->radius = (float)(iVar15 * 10);
    iVar15 = MSG_ReadByte();
    (pdVar21->color).r = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).g = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).b = (byte)iVar15;
    dVar13 = cl.time;
    iVar15 = MSG_ReadByte();
    pdVar21->die = (float)iVar15 * 0.1 + (float)dVar13;
    iVar15 = MSG_ReadByte();
    pdVar21->decay = (float)(iVar15 * 10);
    break;
  case 0x1c:
    iVar15 = MSG_ReadShort();
    pdVar21 = (*efx.CL_AllocElight)(iVar15);
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->origin[0] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->origin[1] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->origin[2] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->radius = fVar31;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).r = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).g = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).b = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    fVar31 = (float)iVar15 * 0.1;
    pdVar21->die = fVar31 + (float)cl.time;
    fVar32 = MSG_ReadCoord(&net_message);
    if (fVar31 != 0.0) {
      fVar32 = fVar32 / fVar31;
    }
    pdVar21->decay = fVar32;
    break;
  case 0x1d:
    CL_ParseTextMessage();
    break;
  case 0x1e:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    local_58 = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    fVar31 = local_58;
                    /* Unresolved local var: int pcolor@[???] */
    local_a4._0_1_ = (uchar)iVar15;
    sVar14 = R_LookupColor((uchar)local_a4,(uchar)iVar16,(uchar)iVar17);
    PM_ParticleLine(&local_64,&local_4c,(int)sVar14,fVar31,0.0);
    break;
  case 0x1f:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    local_58 = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    fVar31 = local_58;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int pcolor@[???]
                       Unresolved local var: vec3_t mmin@[???]
                       Unresolved local var: vec3_t mmax@[???]
                       Unresolved local var: vec3_t origin@[???] */
    local_a4._0_1_ = (uchar)iVar15;
    sVar14 = R_LookupColor((uchar)local_a4,(uchar)iVar16,(uchar)iVar17);
    local_28 = (local_64 + local_4c) * 0.5;
    local_34 = local_4c - local_28;
    local_40 = local_64 - local_28;
    local_24 = (local_48 + local_60) * 0.5;
    local_30 = local_48 - local_24;
    local_3c = local_60 - local_24;
    local_20 = (local_44 + local_5c) * 0.5;
    local_2c = local_44 - local_20;
    local_38 = local_5c - local_20;
    PM_DrawBBox(&local_40,&local_34,&local_28,(int)sVar14,fVar31);
    break;
  case 99:
    iVar15 = MSG_ReadShort();
    (*efx.R_BeamKill)(iVar15);
    break;
  case 100:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    (*efx.R_LargeFunnel)(&local_64,iVar16);
    (*efx.R_FunnelSprite)(&local_64,iVar15,iVar16);
    break;
  case 0x65:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodStream)(&local_64,&local_28,iVar15,iVar16);
    }
    break;
  case 0x66:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    (*efx.R_ShowLine)(&local_64,&local_4c);
    break;
  case 0x67:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_Blood)(&local_64,&local_28,iVar15,iVar16);
    }
    break;
  case 0x69:
    iVar15 = MSG_ReadShort();
    if (cl.max_edicts <= iVar15) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Bubble: entity = %i",iVar15);
    }
    iVar16 = MSG_ReadShort();
    p_Var6 = efx.R_FizzEffect;
    iVar17 = MSG_ReadByte();
    (*p_Var6)(cl_entities + iVar15,iVar16,iVar17);
    break;
  case 0x6a:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    local_4c = 0.0;
    local_48 = MSG_ReadAngle();
    local_44 = 0.0;
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    p_Var10 = efx.R_TempModel;
    iVar17 = MSG_ReadByte();
    (*p_Var10)(&local_64,&local_28,&local_4c,(float)iVar17 * 0.1,iVar15,iVar16);
    break;
  case 0x6b:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    p_Var9 = efx.R_TempSphereModel;
    iVar17 = MSG_ReadByte();
    (*p_Var9)(&local_64,local_28,(float)iVar17 * 0.1,iVar16,iVar15);
    break;
  case 0x6c:
                    /* Unresolved local var: float flTime@[???] */
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_58 = MSG_ReadCoord(&net_message);
    local_54 = MSG_ReadCoord(&net_message);
    local_50 = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    (*efx.R_BreakModel)(&local_64,&local_58,&local_28,(float)iVar15 * 10.0,(float)iVar18 * 0.1,
                        iVar17,iVar16,(char)iVar19);
    break;
  case 0x6d:
                    /* Unresolved local var: int decalTextureIndex@[???] */
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    (*efx.R_BulletImpactParticles)(&local_64);
    iVar20 = RandomLong(0,0x7fff);
    if (iVar20 < 0x3fff) {
      switch(iVar20 % 5) {
      case 0:
        S_StartDynamicSound(-1,0,cl_sfx_ric1,&local_64,1.0,1.0,0,100);
        break;
      case 1:
        S_StartDynamicSound(-1,0,cl_sfx_ric2,&local_64,1.0,1.0,0,100);
        break;
      case 2:
        S_StartDynamicSound(-1,0,cl_sfx_ric3,&local_64,1.0,1.0,0,100);
        break;
      case 3:
        S_StartDynamicSound(-1,0,cl_sfx_ric4,&local_64,1.0,1.0,0,100);
        break;
      case 4:
        S_StartDynamicSound(-1,0,cl_sfx_ric5,&local_64,1.0,1.0,0,100);
      }
    }
    p_Var11 = efx.R_DecalShoot;
    if (cl.max_edicts <= iVar15) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Decal: entity = %i",iVar15);
    }
    if (r_decals.value != 0.0) {
      iVar16 = (*efx.Draw_DecalIndex)(iVar16);
      (*p_Var11)(iVar16,iVar15,0,&local_64,0);
    }
    break;
  case 0x6e:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_Sprite_Spray)(&local_64,&local_28,iVar15,iVar16,iVar17 * 2,iVar18);
    break;
  case 0x6f:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    local_58 = (float)iVar15 * 0.1;
    (*efx.R_RicochetSprite)(&local_64,cl_sprite_ricochet,0.1,local_58);
    (*efx.R_RicochetSound)(&local_64);
    break;
  case 0x70:
                    /* Unresolved local var: int decalTextureIndex@[???]
                       Unresolved local var: int playernum@[???]
                       Unresolved local var: customization_t * pCust@[???]
                       Unresolved local var: texture_t * pTexture@[???] */
    iVar15 = MSG_ReadByte();
    if (iVar15 - 1U < 0x20) {
      pcVar5 = cl.players[iVar15 + -1].customdata.pNext;
      local_64 = MSG_ReadCoord(&net_message);
      local_60 = MSG_ReadCoord(&net_message);
      local_5c = MSG_ReadCoord(&net_message);
      iVar17 = MSG_ReadShort();
      iVar16 = MSG_ReadByte();
      if (cl.max_edicts <= iVar17) {
LAB_001526e8:
                    /* WARNING: Subroutine does not return */
        Sys_Error("Decal: entity = %i",iVar17);
      }
      if (pcVar5 != (customization_s *)0x0) {
        if (pcVar5->pBuffer == (void *)0x0) {
          return;
        }
        wad = pcVar5->pInfo;
        if (wad == (cachewad_t *)0x0) {
          return;
        }
        if (((pcVar5->resource).ucFlags & 4) == 0) {
          return;
        }
        if ((pcVar5->resource).type != t_decal) {
          return;
        }
        if (pcVar5->bTranslated == false) {
          return;
        }
        iVar18 = wad->lumpCount + -1;
        if (iVar18 <= iVar16) {
          iVar16 = iVar18;
        }
        pcVar5->nUserData1 = iVar16;
        ptexture = Draw_CustomCacheGet(wad,pcVar5->pBuffer,(pcVar5->resource).nDownloadSize,iVar16);
        if (r_decals.value == 0.0) {
          return;
        }
        if (ptexture == (texture_t *)0x0) {
          return;
        }
        R_CustomDecalShoot(ptexture,iVar15 - 1U,iVar17,0,&local_64,4);
        return;
      }
    }
    else {
      local_64 = MSG_ReadCoord(&net_message);
      local_60 = MSG_ReadCoord(&net_message);
      local_5c = MSG_ReadCoord(&net_message);
      iVar17 = MSG_ReadShort();
      iVar16 = MSG_ReadByte();
      if (cl.max_edicts <= iVar17) goto LAB_001526e8;
    }
    p_Var11 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      iVar15 = (*efx.Draw_DecalIndex)(iVar16);
      (*p_Var11)(iVar15,iVar17,0,&local_64,4);
    }
    break;
  case 0x71:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    local_58 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    local_54 = MSG_ReadCoord(&net_message);
    (*efx.R_Bubbles)(&local_64,&local_4c,local_58,iVar15,iVar16,local_54);
    break;
  case 0x72:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_4c = MSG_ReadCoord(&net_message);
    local_48 = MSG_ReadCoord(&net_message);
    local_44 = MSG_ReadCoord(&net_message);
    local_58 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    local_54 = MSG_ReadCoord(&net_message);
    (*efx.R_BubbleTrail)(&local_64,&local_4c,local_58,iVar15,iVar16,local_54);
    break;
  case 0x73:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    local_58 = (float)iVar18;
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodSprite)(&local_64,iVar17,iVar15,iVar16,local_58);
    }
    break;
  case 0x77:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_Projectile)(&local_64,&local_28,iVar15,(int)(float)iVar16,iVar17,
                        (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0);
    break;
  case 0x78:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    (*efx.R_Spray)(&local_64,&local_28,iVar15,iVar16,iVar17,iVar18,iVar19);
    break;
  case 0x79:
                    /* Unresolved local var: int isize@[???] */
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_PlayerSprites)(iVar15,iVar16,iVar17,iVar18);
    break;
  case 0x7a:
                    /* Unresolved local var: int radius@[???] */
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_ParticleBurst)(&local_64,iVar15,iVar16,(float)iVar17 / 10.0);
    break;
  case 0x7b:
                    /* Unresolved local var: int radius@[???] */
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    (*efx.R_FireField)(&local_64,iVar15,iVar16,iVar17,iVar18,(float)iVar19 / 10.0);
    break;
  case 0x7c:
                    /* Unresolved local var: float offset@[???] */
    iVar15 = MSG_ReadByte();
    fVar31 = MSG_ReadCoord(&net_message);
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    (*efx.R_AttachTentToPlayer)(iVar15,iVar16,fVar31,(float)iVar17 / 10.0);
    break;
  case 0x7d:
    iVar15 = MSG_ReadByte();
    (*efx.R_KillAttachedTents)(iVar15);
    break;
  case 0x7e:
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_28 = local_28 / 10.0;
    local_24 = MSG_ReadCoord(&net_message);
    local_24 = local_24 / 10.0;
    local_20 = MSG_ReadCoord(&net_message);
    local_20 = local_20 / 10.0;
    local_58 = MSG_ReadCoord(&net_message);
    local_54 = MSG_ReadCoord(&net_message);
    local_50 = 0.0;
    local_58 = local_58 / 100.0;
    local_54 = local_54 / 100.0;
    iVar15 = MSG_ReadByte();
    local_34 = (vec_t)MSG_ReadByte();
    (*efx.R_MultiGunshot)(&local_64,&local_28,&local_58,iVar15,1,(int *)&local_34);
    break;
  case 0x7f:
                    /* Unresolved local var: float length@[???] */
    local_64 = MSG_ReadCoord(&net_message);
    local_60 = MSG_ReadCoord(&net_message);
    local_5c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_UserTracerParticle)
              (&local_64,&local_28,(float)iVar15 / 10.0,iVar16,(float)iVar17 / 10.0,'\0',
               (_func_void_particle_s_ptr *)0x0);
  }
  return;
}


// CL_ParseTextMessage  @ 0014fa60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseTextMessage(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
                    /* Unresolved local var: int channel@[???]
                       Unresolved local var: client_textmessage_t * pNetMessage@[???] */
  iVar1 = MSG_ReadByte();
  iVar1 = iVar1 % 4;
  iVar2 = MSG_ReadShort();
  gNetworkTextMessage[iVar1].x = (float)iVar2 * 0.00012207031;
  iVar2 = MSG_ReadShort();
  gNetworkTextMessage[iVar1].y = (float)iVar2 * 0.00012207031;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].effect = iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].r1 = (byte)iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].g1 = (byte)iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].b1 = (byte)iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].a1 = (byte)iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].r2 = (byte)iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].g2 = (byte)iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].b2 = (byte)iVar2;
  iVar2 = MSG_ReadByte();
  gNetworkTextMessage[iVar1].a2 = (byte)iVar2;
  iVar2 = MSG_ReadWord();
  gNetworkTextMessage[iVar1].fadein = (float)iVar2 * 0.00390625;
  iVar2 = MSG_ReadWord();
  gNetworkTextMessage[iVar1].fadeout = (float)iVar2 * 0.00390625;
  iVar2 = MSG_ReadWord();
  gNetworkTextMessage[iVar1].holdtime = (float)iVar2 * 0.00390625;
  if (gNetworkTextMessage[iVar1].effect == 2) {
    iVar2 = MSG_ReadWord();
    gNetworkTextMessage[iVar1].fxtime = (float)iVar2 * 0.00390625;
  }
  pcVar3 = gNetworkMessageNames[iVar1];
  gNetworkTextMessage[iVar1].pMessage = gNetworkTextMessageBuffer[iVar1];
  gNetworkTextMessage[iVar1].pName = pcVar3;
  pcVar3 = MSG_ReadString();
  Q_strncpy(gNetworkTextMessageBuffer[iVar1],pcVar3,0x1ff);
  pcVar3 = gNetworkTextMessage[iVar1].pName;
  gNetworkTextMessageBuffer[iVar1][0x1ff] = '\0';
  CL_HudMessage(pcVar3);
  return;
}


// CL_Parse_AddAngle  @ 00138880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_AddAngle(void)

{
  float fVar1;
  
                    /* Unresolved local var: float ang@[???] */
  fVar1 = MSG_ReadHiresAngle();
  cl.viewangles[1] = fVar1 + cl.viewangles[1];
  return;
}


// CL_Parse_CDTrack  @ 00138a60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_CDTrack(void)

{
  int iVar1;
  
  cl.cdtrack = MSG_ReadByte();
  cl.looptrack = MSG_ReadByte();
  iVar1 = COM_CheckParm("-nocdaudio");
  if (iVar1 == 0) {
    if (((cls.demoplayback != false) || (cls.demorecording != false)) && (cls.forcetrack != -1)) {
      CDAudio_Play(cls.forcetrack,1);
      return;
    }
    CDAudio_Play(cl.cdtrack,1);
  }
  return;
}


// CL_Parse_CenterPrint  @ 00137d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_CenterPrint(void)

{
  char *str;
  
  str = MSG_ReadString();
  SCR_CenterPrint(str);
  return;
}


// CL_Parse_Choke  @ 00138cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Choke(void)

{
  cl.frames[cls.netchan.incoming_sequence & CL_UPDATE_MASK].choked = true;
  return;
}


// CL_Parse_ClientData  @ 00137a40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ClientData(void)

{
  clientdata_t *to;
  float fVar1;
  double dVar2;
  double dVar3;
  local_state_t *plVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  qboolean qVar9;
  delta_t **ppdVar10;
  delta_t **ppdVar11;
  uint uVar12;
  local_state_t *ps;
  uint32 uVar13;
  uint32 uVar14;
  weapon_data_s *pwd;
  int iVar15;
  local_state_t *pps;
  uint uVar16;
  weapon_data_s *wd;
  clientdata_s *pcd;
  int in_GS_OFFSET;
  uchar auStack_254 [88];
  uchar auStack_1fc [476];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  ppdVar10 = DELTA_LookupRegistration("clientdata_t");
  ppdVar11 = DELTA_LookupRegistration("weapon_data_t");
  Q_memset(auStack_1fc,0,0x1dc);
  iVar8 = cls.netchan.incoming_acknowledged;
  iVar15 = cls.netchan.incoming_sequence;
  iVar7 = CL_ParseClientdata::last_incoming_sequence;
  iVar5 = CL_UPDATE_MASK;
  uVar16 = CL_ParseClientdata::last_incoming_sequence + 1;
  if ((int)uVar16 < cls.netchan.incoming_sequence) {
    do {
      uVar12 = iVar5 & uVar16;
      if (0.0 <= cl.frames[uVar12].receivedtime) {
        *(undefined4 *)&cl.frames[uVar12].receivedtime = 0;
        *(undefined4 *)((int)&cl.frames[uVar12].receivedtime + 4) = 0xbff00000;
        *(undefined4 *)&cl.frames[uVar12].latency = 0;
        *(undefined4 *)((int)&cl.frames[uVar12].latency + 4) = 0;
      }
      uVar16 = uVar16 + 1;
    } while (iVar15 != uVar16);
  }
  dVar2 = cl.mtime[0];
  uVar16 = iVar5 & iVar15;
  cl.parsecountmod = uVar16;
  cl.frames[uVar16].tentitybytes = 0;
  cl.frames[uVar16].time = dVar2;
  cl.frames[uVar16].playerinfobytes = 0;
  cl.frames[uVar16].soundbytes = 0;
  cl.frames[uVar16].usrbytes = 0;
  cl.frames[uVar16].eventbytes = 0;
  fVar1 = cl.commands[iVar8 & iVar5].senttime;
  dVar3 = (double)fVar1;
  cl.frames[uVar16].voicebytes = 0;
  dVar2 = realtime;
  iVar6 = CL_ParseClientdata::last_command_ack;
  parsecounttime = (double)fVar1;
  cl.commands[iVar8 & iVar5].receivedtime = (float)realtime;
  cl.frames[uVar16].clientbytes = 0;
  cl.parsecount = iVar15;
  cl.frames[uVar16].receivedtime = dVar2;
  cl.frames[uVar16].packetentitybytes = 0;
  cl.frames[uVar16].msgbytes = 0;
  if (iVar6 != -1) {
    if (cls.spectator == false) {
      uVar12 = iVar5 & (iVar8 - iVar6) + iVar7;
      pcd = &cl.frames[uVar16].clientdata;
      ps = (local_state_t *)(uVar16 * 0x4318 + 0xc6aa3c + cl.playernum * 0x154);
      pps = cl.predicted_frames + uVar12;
      plVar4 = cl.predicted_frames + uVar12;
      pwd = cl.predicted_frames[uVar12].weapondata;
      wd = cl.frames[uVar16].weapondata;
    }
    else {
      pwd = spectatorState.weapondata;
      plVar4 = &spectatorState;
      pps = &spectatorState;
      pcd = &spectatorState.client;
      ps = &spectatorState;
      wd = pwd;
    }
    ClientDLL_TxferPredictionData
              ((entity_state_s *)ps,(entity_state_s *)pps,pcd,&plVar4->client,wd,pwd);
    iVar15 = cls.netchan.incoming_sequence;
    dVar2 = realtime;
    dVar3 = parsecounttime;
  }
  qVar9 = cls.spectator;
  g_flLatency = dVar2 - dVar3;
  CL_ParseClientdata::last_command_ack = iVar8;
  CL_ParseClientdata::last_incoming_sequence = iVar15;
  cl.frames[uVar16].latency = g_flLatency;
  if (qVar9 == false) {
    to = &cl.frames[uVar16].clientdata;
    MSG_StartBitReading(&net_message);
    uVar13 = MSG_ReadBits(1);
    if (uVar13 == 0) {
      DELTA_ParseDelta(auStack_1fc,(uchar *)to,*ppdVar10,0x1dc);
      Q_memset(auStack_254,0,0x58);
      while (uVar13 = MSG_ReadBits(1), uVar13 != 0) {
        uVar13 = MSG_ReadBits(6);
        DELTA_ParseDelta(auStack_254,(uchar *)(uVar16 * 0x4318 + 0xc6d6a0 + uVar13 * 0x58),*ppdVar11
                         ,0x58);
      }
    }
    else {
      uVar13 = MSG_ReadBits(8);
      DELTA_ParseDelta((uchar *)&cl.frames[CL_UPDATE_MASK & uVar13].clientdata,(uchar *)to,*ppdVar10
                       ,0x1dc);
      Q_memset(auStack_254,0,0x58);
      while (uVar14 = MSG_ReadBits(1), uVar14 != 0) {
        uVar14 = MSG_ReadBits(6);
        DELTA_ParseDelta((uchar *)(uVar14 * 0x58 + 0xc6d6a0 + (CL_UPDATE_MASK & uVar13) * 0x4318),
                         (uchar *)(uVar14 * 0x58 + 0xc6d6a0 + uVar16 * 0x4318),*ppdVar11,0x58);
      }
    }
    MSG_EndBitReading(&net_message);
    Q_strncpy(cls.physinfo,cl.frames[uVar16].clientdata.physinfo,0xff);
    cl.pushmsec = cl.frames[uVar16].clientdata.pushmsec;
    cl.stats[0] = (int)cl.frames[uVar16].clientdata.health;
    cls.physinfo[0xff] = '\0';
    cl.maxspeed = cl.frames[uVar16].clientdata.maxspeed;
    cl.weapons = cl.frames[uVar16].clientdata.weapons;
  }
  else {
    cl.stats[0] = 1;
  }
  if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_Parse_CrosshairAngle  @ 001388a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_CrosshairAngle(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadChar();
  cl.crosshairangle[0] = (float)iVar1 * 0.2;
  iVar1 = MSG_ReadChar();
  cl.crosshairangle[1] = (float)iVar1 * 0.2;
  return;
}


// CL_Parse_Customization  @ 00138d30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Customization(void)

{
  bool bVar1;
  uint nPlayerNum;
  resource_s *pResource;
  resourcetype_t rVar2;
  char *src;
  int iVar3;
  uint uVar4;
  qboolean qVar5;
  customization_s *pcVar6;
  resourceinfo_t rStack_2c;
  
  nPlayerNum = MSG_ReadByte();
  if (0x1f < nPlayerNum) {
                    /* WARNING: Subroutine does not return */
    Host_Error("Bogus player index during customization parsing.\n");
  }
  pResource = Mem_ZeroMalloc(0x88);
  rVar2 = MSG_ReadByte();
  pResource->type = rVar2;
  src = MSG_ReadString();
  Q_strncpy(pResource->szFileName,src,0x3f);
  pResource->szFileName[0x3f] = '\0';
  iVar3 = MSG_ReadShort();
  pResource->nIndex = iVar3;
  iVar3 = MSG_ReadLong();
  pResource->nDownloadSize = iVar3;
  uVar4 = MSG_ReadByte();
  pResource->pNext = (resource_s *)0x0;
  pResource->pPrev = (resource_s *)0x0;
  pResource->ucFlags = (byte)uVar4 & 0xfd;
  if ((uVar4 & 4) != 0) {
    MSG_ReadBuf(0x10,pResource->rgucMD5_hash);
  }
  uVar4 = nPlayerNum & 0xff;
  bVar1 = cl_allow_download.value == 0.0;
  pResource->playernum = (uchar)nPlayerNum;
  if (bVar1) {
    Con_DPrintf("Refusing new resource, cl_allow_download set to 0\n");
    Mem_Free(pResource);
    return;
  }
  if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
    Con_DPrintf("Refusing new resource, cl_download_ingame set to 0\n");
    Mem_Free(pResource);
  }
  else {
    for (pcVar6 = cl.players[nPlayerNum].customdata.pNext; pcVar6 != (customization_t *)0x0;
        pcVar6 = pcVar6->pNext) {
      if (pResource->type == (pcVar6->resource).type) {
        CL_RemoveCustomization(nPlayerNum,pcVar6);
        uVar4 = (uint)pResource->playernum;
        break;
      }
    }
    pcVar6 = cl.players[uVar4].customdata.pNext;
    if (pcVar6 != (customization_s *)0x0) {
      do {
        iVar3 = Q_memcmp((pcVar6->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10);
        if (iVar3 == 0) {
          qVar5 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
          if (qVar5 == false) goto LAB_00156850;
          Con_DPrintf("Duplicate resource ignored for local client\n");
          goto LAB_001567fb;
        }
        pcVar6 = pcVar6->pNext;
      } while (pcVar6 != (customization_s *)0x0);
    }
    qVar5 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
    if (qVar5 != false) {
      qVar5 = COM_CreateCustomization
                        (&cl.players[pResource->playernum].customdata,pResource,
                         (uint)pResource->playernum,1,(customization_t **)0x0,(int *)0x0);
      if (qVar5 == false) {
        Con_DPrintf("Error loading customization\n");
      }
LAB_001567fb:
      Mem_Free(pResource);
      return;
    }
LAB_00156850:
    pResource->ucFlags = pResource->ucFlags | 2;
    if ((pResource->pPrev == (resource_s *)0x0) && (pResource->pNext == (resource_s *)0x0)) {
      if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
         (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Resource list corrupted.\n");
      }
      pResource->pPrev = cl.resourcesneeded.pPrev;
      (cl.resourcesneeded.pPrev)->pNext = pResource;
      cl.resourcesneeded.pPrev = pResource;
      pResource->pNext = &cl.resourcesneeded;
    }
    else {
      Con_Printf("Resource already linked\n");
    }
    Con_Printf("Requesting %s from server\n",pResource);
    if (fs_startup_timings.value != 0.0) {
      AddStartupTiming("begin CL_StartResourceDownloading()");
    }
    Con_DPrintf("%s","Custom resource propagation...\n");
    cls.dl.nTotalSize = COM_SizeofResourceList(&cl.resourcesneeded,&rStack_2c);
    cls.dl.nTotalToTransfer = CL_EstimateNeededResources();
    cls.dl.custom = true;
    cls.dl.fLastStatusUpdate = (float)realtime;
    cls.dl.doneregistering = false;
    cls.dl.nRemainingToTransfer = cls.dl.nTotalToTransfer;
    Q_memset(cls.dl.rgStats,0,0x60);
    cls.dl.nCurStat = 0;
    if (fs_startup_timings.value != 0.0) {
      AddStartupTiming("end   CL_StartResourceDownloading()");
    }
    CL_BatchResourceRequest();
  }
  return;
}


// CL_Parse_CutScene  @ 00138c40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_CutScene(void)

{
  char *str;
  
  vid.recalc_refdef = 1;
  cl.intermission = 3;
  str = MSG_ReadString();
  SCR_CenterPrint(str);
  return;
}


// CL_Parse_Damage  @ 00138bc0
void CL_Parse_Damage(void)

{
  return;
}


// CL_Parse_DecalName  @ 00138b40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_DecalName(void)

{
  int decal;
  char *name;
  
                    /* Unresolved local var: int i@[???] */
  decal = MSG_ReadByte();
  name = MSG_ReadString();
  Draw_DecalSetName(decal,name);
  return;
}


// CL_Parse_DeltaDescription  @ 00153eb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_DeltaDescription(void)

{
  char *src;
  delta_t **ppdesc;
  uint32 uVar1;
  delta_t *pdVar2;
  delta_description_s *pdVar3;
  uint32 uVar4;
  delta_description_s *to;
  int in_GS_OFFSET;
  uchar local_164 [68];
  char local_120 [255];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char[256] szDesc@[???]
                       Unresolved local var: delta_t * * ppdelta@[???]
                       Unresolved local var: delta_description_t * pdesc@[???]
                       Unresolved local var: delta_description_t nulldesc@[???]
                       Unresolved local var: delta_description_t * from@[???]
                       Unresolved local var: delta_description_t * to@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_164,0,0x44);
  src = MSG_ReadString();
  if ((src == (char *)0x0) || (*src == '\0')) {
                    /* WARNING: Subroutine does not return */
    Host_Error("CL_Parse_DeltaDescription:  Illegible description name\n");
  }
  Q_strncpy(local_120,src,0xff);
  local_21 = 0;
  ppdesc = DELTA_LookupRegistration(local_120);
  if ((ppdesc != (delta_t **)0x0) && (*ppdesc != (delta_t *)0x0)) {
    DELTA_FreeDescription(ppdesc);
  }
  MSG_StartBitReading(&net_message);
  uVar1 = MSG_ReadBits(0x10);
  pdVar2 = Mem_ZeroMalloc(0x30);
  *ppdesc = pdVar2;
  pdVar3 = Mem_ZeroMalloc(uVar1 * 0x44);
  (*ppdesc)->dynamic = 1;
  uVar4 = 0;
  (*ppdesc)->fieldCount = uVar1;
  to = pdVar3;
  if (0 < (int)uVar1) {
    do {
      uVar4 = uVar4 + 1;
      DELTA_ParseDelta(local_164,(uchar *)to,&g_MetaDelta,0x44);
      to = to + 1;
    } while (uVar1 != uVar4);
  }
  (*ppdesc)->pdd = pdVar3;
  MSG_EndBitReading(&net_message);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_Parse_DeltaPacketEntities  @ 00138ca0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_DeltaPacketEntities(void)

{
  cls.playerbits = 0;
  CL_ParsePacketEntities(true,&cls.playerbits);
  CL_SetSolidEntities();
  return;
}


// CL_Parse_Director  @ 001398c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Director(void)

{
  int iSize;
  
                    /* Unresolved local var: int length@[???] */
  iSize = MSG_ReadByte();
  ClientDLL_DirectorMessage(iSize,net_message.data + msg_readcount);
  msg_readcount = msg_readcount + iSize;
  return;
}


// CL_Parse_Disconnect  @ 00137a50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Disconnect(void)

{
  char *fmt;
  int iVar1;
  
                    /* Unresolved local var: char * msg@[???] */
  fmt = MSG_ReadString();
  SCR_EndLoadingPlaque();
  if ((fmt == (char *)0x0) || (*fmt == '\0')) {
    COM_ExplainDisconnection(true,"#GameUI_DisconnectedFromServer");
  }
  else {
    COM_ExplainDisconnection(true,"#GameUI_DisconnectedFromServerExtended");
    COM_ExtendedExplainDisconnection(true,fmt);
    iVar1 = strncasecmp(fmt,"Invalid VALVE CD Key\n",0x15);
    if (iVar1 == 0) {
      ValidateCDKey(1,1);
    }
    else {
      iVar1 = strncasecmp(fmt,"Invalid STEAM UserID Ticket\n",0x1c);
      if (iVar1 == 0) {
        VGUI2_OnDisconnectFromServer(1);
      }
      else {
        iVar1 = Q_stricmp(fmt,"No Steam logon\n");
        if (iVar1 == 0) {
          VGUI2_OnDisconnectFromServer(2);
        }
        else {
          iVar1 = Q_stricmp(fmt,"Steam connection lost\n");
          if (iVar1 == 0) {
            VGUI2_OnDisconnectFromServer(5);
          }
          else {
            iVar1 = Q_stricmp(fmt,"Unable to connect to Steam\n");
            if (iVar1 == 0) {
              VGUI2_OnDisconnectFromServer(6);
            }
            else {
              iVar1 = Q_stricmp(fmt,"This Steam account is being used in another location\n");
              if (iVar1 == 0) {
                VGUI2_OnDisconnectFromServer(4);
              }
              else {
                iVar1 = Q_stricmp(fmt,"VAC banned from secure server\n");
                if (iVar1 == 0) {
                  VGUI2_OnDisconnectFromServer(3);
                }
                else {
                  VGUI2_OnDisconnectFromServer(0);
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  Host_EndGame("Server disconnected\n");
}


// CL_Parse_Finale  @ 00138c10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Finale(void)

{
  char *str;
  
  vid.recalc_refdef = 1;
  cl.intermission = 2;
  str = MSG_ReadString();
  SCR_CenterPrint(str);
  return;
}


// CL_Parse_FoundSecret  @ 00138be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_FoundSecret(void)

{
  return;
}


// CL_Parse_HLTV  @ 001398b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_HLTV(void)

{
  netadr_t addr;
  int iVar1;
  char *s;
  
  iVar1 = MSG_ReadByte();
  if (iVar1 == 1) {
    MSG_ReadLong();
    MSG_ReadShort();
    MSG_ReadWord();
    MSG_ReadLong();
    MSG_ReadLong();
    MSG_ReadWord();
    return;
  }
  if (iVar1 != 2) {
    if (iVar1 != 0) {
      Con_Printf(" CL_Parse_HLTV: unknown HLTV command.\n");
      return;
    }
    cls.spectator = true;
    g_bRedirectedToProxy = 0;
    return;
  }
  cls.signon = 2;
  s = MSG_ReadString();
  Net_StringToAdr(s,&cls.game_stream);
  addr.ip[0] = cls.game_stream.ip[0];
  addr.ip[1] = cls.game_stream.ip[1];
  addr.ip[2] = cls.game_stream.ip[2];
  addr.ip[3] = cls.game_stream.ip[3];
  addr.type = cls.game_stream.type;
  addr.ipx[0] = cls.game_stream.ipx[0];
  addr.ipx[1] = cls.game_stream.ipx[1];
  addr.ipx[2] = cls.game_stream.ipx[2];
  addr.ipx[3] = cls.game_stream.ipx[3];
  addr.ipx[4] = cls.game_stream.ipx[4];
  addr.ipx[5] = cls.game_stream.ipx[5];
  addr.ipx[6] = cls.game_stream.ipx[6];
  addr.ipx[7] = cls.game_stream.ipx[7];
  addr.ipx[8] = cls.game_stream.ipx[8];
  addr.ipx[9] = cls.game_stream.ipx[9];
  addr.port = cls.game_stream.port;
  NET_JoinGroup(cls.netchan.sock,addr);
  SCR_EndLoadingPlaque();
  return;
}


// CL_Parse_Intermission  @ 00138bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Intermission(void)

{
  cl.intermission = 1;
  vid.recalc_refdef = 1;
  return;
}


// CL_Parse_KilledMonster  @ 00138bd0
void CL_Parse_KilledMonster(void)

{
  return;
}


// CL_Parse_LightStyle  @ 001388e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_LightStyle(void)

{
  int iVar1;
  char *src;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = MSG_ReadByte();
  if (0x3f < iVar1) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("svc_lightstyle > MAX_LIGHTSTYLES");
  }
  src = MSG_ReadString();
  Q_strncpy(cl_lightstyle[iVar1].map,src,0x3f);
  cl_lightstyle[iVar1].map[0x3f] = '\0';
  iVar2 = Q_strlen(cl_lightstyle[iVar1].map);
  cl_lightstyle[iVar1].length = iVar2;
  return;
}


// CL_Parse_NewMoveVars  @ 00138d10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_NewMoveVars(void)

{
  char *src;
  
  movevars.gravity = MSG_ReadFloat();
  movevars.stopspeed = MSG_ReadFloat();
  movevars.maxspeed = MSG_ReadFloat();
  movevars.spectatormaxspeed = MSG_ReadFloat();
  movevars.accelerate = MSG_ReadFloat();
  movevars.airaccelerate = MSG_ReadFloat();
  movevars.wateraccelerate = MSG_ReadFloat();
  movevars.friction = MSG_ReadFloat();
  movevars.edgefriction = MSG_ReadFloat();
  movevars.waterfriction = MSG_ReadFloat();
  movevars.entgravity = MSG_ReadFloat();
  movevars.bounce = MSG_ReadFloat();
  movevars.stepsize = MSG_ReadFloat();
  movevars.maxvelocity = MSG_ReadFloat();
  movevars.zmax = MSG_ReadFloat();
  movevars.waveHeight = MSG_ReadFloat();
  movevars.footsteps = MSG_ReadByte();
  movevars.rollangle = MSG_ReadFloat();
  movevars.rollspeed = MSG_ReadFloat();
  movevars.skycolor_r = MSG_ReadFloat();
  movevars.skycolor_g = MSG_ReadFloat();
  movevars.skycolor_b = MSG_ReadFloat();
  movevars.skyvec_x = MSG_ReadFloat();
  movevars.skyvec_y = MSG_ReadFloat();
  movevars.skyvec_z = MSG_ReadFloat();
  src = MSG_ReadString();
  Q_strncpy(movevars.skyName,src,0x1f);
  movevars.skyName[0x1f] = '\0';
  if (movevars.zmax != gl_zmax.value) {
    Cvar_SetValue("gl_zmax",movevars.zmax);
  }
  if (movevars.waveHeight != gl_wateramp.value) {
    Cvar_SetValue("gl_wateramp",movevars.waveHeight);
  }
  if (cl_entities != (cl_entity_t *)0x0) {
    (cl_entities->curstate).scale = gl_wateramp.value;
  }
  return;
}


// CL_Parse_NewUserMsg  @ 00138ba0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_NewUserMsg(void)

{
  bool bVar1;
  int iVar2;
  UserMsg *dest;
  _UserMsg *p_Var3;
  int in_GS_OFFSET;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  char acStack_28 [4];
  char acStack_24 [4];
  char acStack_20 [4];
  char acStack_1c [3];
  undefined1 uStack_19;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  iStack_30 = MSG_ReadByte();
  iStack_2c = MSG_ReadByte();
  uStack_14 = 0;
  if (iStack_2c == 0xff) {
    iStack_2c = -1;
  }
  iStack_34 = MSG_ReadLong();
  Q_strncpy(acStack_28,(char *)&iStack_34,4);
  iStack_34 = MSG_ReadLong();
  Q_strncpy(acStack_24,(char *)&iStack_34,4);
  iStack_34 = MSG_ReadLong();
  bVar1 = false;
  Q_strncpy(acStack_20,(char *)&iStack_34,4);
  iStack_34 = MSG_ReadLong();
  Q_strncpy(acStack_1c,(char *)&iStack_34,4);
  uStack_19 = 0;
  p_Var3 = gClientUserMsgs;
  if (gClientUserMsgs != (UserMsg *)0x0) {
    do {
      if (p_Var3->iMsg == iStack_30) {
        p_Var3->iMsg = 0;
      }
      iVar2 = Q_stricmp(p_Var3->szName,acStack_28);
      if (iVar2 == 0) {
        bVar1 = true;
        p_Var3->iMsg = iStack_30;
        p_Var3->iSize = iStack_2c;
      }
      p_Var3 = p_Var3->next;
    } while (p_Var3 != (_UserMsg *)0x0);
    if (bVar1) goto LAB_001541dc;
  }
  dest = Mem_Malloc(0x20);
  Q_memcpy(dest,&iStack_30,0x20);
  dest->next = gClientUserMsgs;
  gClientUserMsgs = dest;
LAB_001541dc:
  if (iStack_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_Parse_PacketEntities  @ 00138c70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_PacketEntities(void)

{
  cls.playerbits = 0;
  CL_ParsePacketEntities(false,&cls.playerbits);
  CL_SetSolidEntities();
  return;
}


// CL_Parse_Particle  @ 00138980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Particle(void)

{
  int iVar1;
  int color;
  vec_t *pvVar2;
  vec_t *pvVar3;
  float fVar4;
  vec_t avStack_34 [3];
  vec_t avStack_28 [3];
  vec_t avStack_1c [3];
  
  pvVar3 = avStack_34;
  do {
    pvVar2 = pvVar3 + 1;
    fVar4 = MSG_ReadCoord(&net_message);
    *pvVar3 = fVar4;
    pvVar3 = pvVar2;
  } while (pvVar2 != avStack_28);
  pvVar3 = avStack_28;
  do {
    iVar1 = MSG_ReadChar();
    pvVar2 = pvVar3 + 1;
    *pvVar3 = (float)iVar1 * 0.0625;
    pvVar3 = pvVar2;
  } while (avStack_1c != pvVar2);
  iVar1 = MSG_ReadByte();
  color = MSG_ReadByte();
  if (iVar1 == 0xff) {
    iVar1 = 0x400;
  }
  R_RunParticleEffect(avStack_34,avStack_28,color,iVar1);
  return;
}


// CL_Parse_Pings  @ 00139830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Pings(void)

{
  uint32 uVar1;
  uint32 uVar2;
  uint32 uVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean hasping@[???]
                       Unresolved local var: int ping@[???]
                       Unresolved local var: int packet_loss@[???] */
  MSG_StartBitReading(&net_message);
  while( true ) {
    uVar3 = MSG_ReadBits(1);
    if (uVar3 == 0) break;
    uVar3 = MSG_ReadBits(5);
    uVar1 = MSG_ReadBits(0xc);
    uVar2 = MSG_ReadBits(7);
    cl.players[uVar3].ping = uVar1;
    cl.players[uVar3].packet_loss = uVar2;
  }
  MSG_EndBitReading(&net_message);
  return;
}


// CL_Parse_Print  @ 00137d20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Print(void)

{
  char *pcVar1;
  
  pcVar1 = MSG_ReadString();
  Con_Printf("%s",pcVar1);
  return;
}


// CL_Parse_ReliableEvent  @ 00139650
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ReliableEvent(void)

{
  float fVar1;
  float fVar2;
  delta_t **ppdVar3;
  uint32 uVar4;
  uint32 uVar5;
  int iVar6;
  event_info_s *peVar7;
  event_state_t *peVar8;
  event_state_t *peVar9;
  uint uVar10;
  uchar local_ac [72];
  uchar local_64 [4];
  int local_60;
  float local_50;
  
                    /* Unresolved local var: int event_index@[???]
                       Unresolved local var: qboolean hasdelay@[???]
                       Unresolved local var: float delay@[???]
                       Unresolved local var: event_args_t nullargs@[???]
                       Unresolved local var: event_args_t newargs@[???]
                       Unresolved local var: event_args_t * from@[???]
                       Unresolved local var: event_args_t * to@[???]
                       Unresolved local var: delta_t * * ppevent@[???] */
  ppdVar3 = DELTA_LookupRegistration("event_t");
  Q_memset(local_ac,0,0x48);
  Q_memset(local_64,0,0x48);
  MSG_StartBitReading(&net_message);
  uVar4 = MSG_ReadBits(10);
  DELTA_ParseDelta(local_ac,local_64,*ppdVar3,0x48);
  uVar5 = MSG_ReadBits(1);
  if (uVar5 == 0) {
    fVar2 = 0.0;
  }
  else {
    uVar5 = MSG_ReadBits(0x10);
    fVar2 = (float)uVar5 / 100.0;
  }
  if ((0 < local_60) && (local_60 <= cl.maxclients)) {
    local_50 = local_50 * -3.0;
  }
  peVar8 = &cl.events;
                    /* Unresolved local var: event_info_t * ei@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???] */
  iVar6 = 0;
  peVar9 = &cl.events;
  do {
    if (peVar9->ei[0].index == 0) {
      peVar7 = cl.events.ei + iVar6;
      iVar6 = 0;
      if (peVar7 != (event_info_s *)0x0) goto LAB_00139769;
      goto LAB_00139730;
    }
    iVar6 = iVar6 + 1;
    peVar9 = (event_state_t *)(peVar9->ei + 1);
  } while (iVar6 != 0x40);
  iVar6 = 0;
LAB_00139730:
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
    if ((peVar8->ei[0].index == 0) || ((peVar8->ei[0].flags & 2) == 0)) {
      peVar7 = cl.events.ei + iVar6;
      if (peVar7 != (event_info_s *)0x0) {
LAB_00139769:
        peVar7->index = (ushort)uVar4;
        uVar10 = 0;
        peVar7->packet_index = 0;
        do {
          *(undefined4 *)((int)(peVar7->args).origin + (uVar10 - 8)) =
               *(undefined4 *)(local_64 + uVar10);
          uVar10 = uVar10 + 4;
        } while (uVar10 < 0x48);
        fVar1 = 0.0;
        if (fVar2 != 0.0) {
          fVar1 = fVar2 + (float)cl.time;
        }
        peVar7->fire_time = fVar1;
        peVar7->flags = 2;
      }
      goto LAB_001397aa;
    }
    iVar6 = iVar6 + 1;
    peVar8 = (event_state_t *)(peVar8->ei + 1);
    if (iVar6 == 0x40) {
LAB_001397aa:
      MSG_EndBitReading(&net_message);
      return;
    }
  } while( true );
}


// CL_Parse_ResourceList  @ 00138cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ResourceList(void)

{
  uint32 uVar1;
  resource_s *dest;
  resourcetype_t rVar2;
  char *src;
  uint32 uVar3;
  uint32 uVar4;
  resourceinfo_t rStack_2c;
  
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_ParseResourceList()");
  }
  uVar4 = 0;
  MSG_StartBitReading(&net_message);
  uVar1 = MSG_ReadBits(0xc);
  if (0 < (int)uVar1) {
    do {
      while( true ) {
        dest = Mem_ZeroMalloc(0x88);
        rVar2 = MSG_ReadBits(4);
        dest->type = rVar2;
        src = MSG_ReadBitString();
        Q_strncpy(dest->szFileName,src,0x3f);
        dest->szFileName[0x3f] = '\0';
        uVar3 = MSG_ReadBits(0xc);
        dest->nIndex = uVar3;
        uVar3 = MSG_ReadBits(0x18);
        dest->nDownloadSize = uVar3;
        uVar3 = MSG_ReadBits(3);
        dest->ucFlags = (byte)uVar3 & 0xfd;
        if ((uVar3 & 4) != 0) {
          MSG_ReadBitData(dest->rgucMD5_hash,0x10);
        }
        uVar3 = MSG_ReadBits(1);
        if (uVar3 != 0) {
          MSG_ReadBitData(dest->rguc_reserved,0x20);
        }
        if ((dest->pPrev != (resource_s *)0x0) || (dest->pNext != (resource_s *)0x0)) break;
        if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
           (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Resource list corrupted.\n");
        }
        dest->pPrev = cl.resourcesneeded.pPrev;
        uVar4 = uVar4 + 1;
        (cl.resourcesneeded.pPrev)->pNext = dest;
        cl.resourcesneeded.pPrev = dest;
        dest->pNext = &cl.resourcesneeded;
        if (uVar1 == uVar4) goto LAB_001561d0;
      }
      Con_Printf("Resource already linked\n");
      uVar4 = uVar4 + 1;
    } while (uVar1 != uVar4);
  }
LAB_001561d0:
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_ParseResourceList()");
  }
  CL_ParseConsistencyInfo();
  MSG_EndBitReading(&net_message);
  SetLoadingProgressBarStatusText("#GameUI_VerifyingResources");
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_StartResourceDownloading()");
  }
  Con_DPrintf("%s","Verifying and downloading resources...\n");
  cls.dl.nTotalSize = COM_SizeofResourceList(&cl.resourcesneeded,&rStack_2c);
  cls.dl.nTotalToTransfer = CL_EstimateNeededResources();
  cls.state = ca_uninitialized;
  cls.dl.custom = false;
  cls.dl.fLastStatusUpdate = (float)realtime;
  gfExtendedError = false;
  cls.dl.doneregistering = false;
  cls.dl.nRemainingToTransfer = cls.dl.nTotalToTransfer;
  Q_memset(cls.dl.rgStats,0,0x60);
  cls.dl.nCurStat = 0;
  if (fs_startup_timings.value == 0.0) {
    CL_BatchResourceRequest();
    return;
  }
  AddStartupTiming("end   CL_StartResourceDownloading()");
  CL_BatchResourceRequest();
  return;
}


// CL_Parse_ResourceLocation  @ 00138d00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ResourceLocation(void)

{
  char *__s2;
  int iVar1;
  char *pcVar2;
  
  __s2 = MSG_ReadString();
  if (__s2 != (char *)0x0) {
    iVar1 = strncasecmp("http://",__s2,7);
    if (iVar1 != 0) {
      iVar1 = strncasecmp("https://",__s2,8);
      if (iVar1 != 0) {
        return;
      }
    }
    pcVar2 = strrchr(__s2,0x2f);
    if ((pcVar2 == (char *)0x0) || (pcVar2[1] != '\0')) {
      __snprintf_chk(0xdf0868,0x80,1,0x80,&DAT_00266b9e,__s2);
    }
    else {
      strncpy(cl.downloadUrl,__s2,0x80);
      cl.downloadUrl[0x7f] = '\0';
    }
    Con_DPrintf("Using %s as primary download location\n",0xdf0868);
  }
  return;
}


// CL_Parse_ResourceRequest  @ 00138d20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ResourceRequest(void)

{
  uchar *data;
  int iVar1;
  int iVar2;
  resource_t *s;
  int in_GS_OFFSET;
  sizebuf_t sStack_10024;
  byte abStack_10010 [65540];
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  ContinueLoadingProgressBar("ClientConnect",6,0.0);
  Q_memset(&sStack_10024,0,0x14);
  sStack_10024.buffername = "Client to Server Resource Block";
  sStack_10024.data = abStack_10010;
  sStack_10024.cursize = 0;
  sStack_10024.maxsize = 0x10000;
  if (cls.state < ca_connecting) {
    Con_Printf("custom resource list not valid -- not connected\n");
  }
  else {
    iVar2 = MSG_ReadLong();
    if ((cls.demoplayback == false) && (iVar2 != cl.servercount)) {
      Con_Printf("CL_SendResourceListBlock_f from different level\n");
    }
    else {
      iVar2 = MSG_ReadLong();
      if ((iVar2 < 0) || (cl.num_resources < iVar2)) {
        Con_Printf("custom resource list request out of range\n");
      }
      else {
        MSG_WriteByte(&sStack_10024,5);
        MSG_WriteShort(&sStack_10024,cl.num_resources);
        if (iVar2 < cl.num_resources) {
          s = cl.resourcelist + iVar2;
          do {
            while( true ) {
              MSG_WriteString(&sStack_10024,s->szFileName);
              MSG_WriteByte(&sStack_10024,s->type);
              MSG_WriteShort(&sStack_10024,s->nIndex);
              MSG_WriteLong(&sStack_10024,s->nDownloadSize);
              MSG_WriteByte(&sStack_10024,(uint)s->ucFlags);
              if ((s->ucFlags & 4) == 0) break;
              data = s->rgucMD5_hash;
              iVar2 = iVar2 + 1;
              s = s + 1;
              SZ_Write(&sStack_10024,data,0x10);
              if (cl.num_resources <= iVar2) goto LAB_0014ac15;
            }
            iVar2 = iVar2 + 1;
            s = s + 1;
          } while (iVar2 < cl.num_resources);
        }
LAB_0014ac15:
        if (0 < sStack_10024.cursize) {
          Netchan_CreateFragments(false,&cls.netchan,&sStack_10024);
          Netchan_FragSend(&cls.netchan);
        }
      }
    }
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Parse_Restore  @ 00138af0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Restore(void)

{
  char *fileName;
  
  fileName = MSG_ReadString();
  CL_Restore(fileName);
  return;
}


// CL_Parse_RoomType  @ 00138b70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_RoomType(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  Cvar_SetValue("room_type",(float)iVar1);
  return;
}


// CL_Parse_ServerInfo  @ 00138830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ServerInfo(void)

{
  CL_ParseServerInfo();
  vid.recalc_refdef = 1;
  sys_timescale.value = 1.0;
  return;
}


// CL_Parse_SetAngle  @ 00138850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SetAngle(void)

{
                    /* Unresolved local var: int i@[???] */
  cl.viewangles[0] = MSG_ReadHiresAngle();
  cl.viewangles[1] = MSG_ReadHiresAngle();
  cl.viewangles[2] = MSG_ReadHiresAngle();
  return;
}


// CL_Parse_SetPause  @ 001389c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SetPause(void)

{
  int iVar1;
  
  cl.paused = MSG_ReadByte();
  iVar1 = VGuiWrap2_IsInCareerMatch();
  if (iVar1 != 0) {
    return;
  }
  if (cl.paused == false) {
    CDAudio_Resume();
    return;
  }
  CDAudio_Pause();
  return;
}


// CL_Parse_SetView  @ 00137d00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SetView(void)

{
  cl.viewentity = MSG_ReadShort();
  return;
}


// CL_Parse_SignonNum  @ 00138a10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SignonNum(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = MSG_ReadByte();
  if (cls.signon < iVar1) {
    cls.signon = iVar1;
    CL_SignonReply();
    return;
  }
  Con_Printf("Received signon %i when at %i\n",iVar1,cls.signon);
  CL_Disconnect_f();
  return;
}


// CL_Parse_Sound  @ 00153bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Sound(void)

{
  uint32 flags;
  uint32 uVar1;
  uint32 entnum;
  uint32 uVar2;
  sfx_t *sfxin;
  char *pcVar3;
  int in_GS_OFFSET;
  undefined *puVar4;
  float local_90;
  float local_8c;
  uint32 local_88;
  vec_t local_74 [3];
  sfx_t local_68;
  int local_20;
  
                    /* Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: int channel@[???]
                       Unresolved local var: int ent@[???]
                       Unresolved local var: int sound_num@[???]
                       Unresolved local var: float volume@[???]
                       Unresolved local var: int field_mask@[???]
                       Unresolved local var: float attenuation@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  MSG_StartBitReading(&net_message);
  flags = MSG_ReadBits(9);
  local_90 = 1.0;
  if ((flags & 1) != 0) {
    uVar1 = MSG_ReadBits(8);
    local_90 = (float)uVar1 / 255.0;
  }
  local_8c = 1.0;
  if ((flags & 2) != 0) {
    uVar1 = MSG_ReadBits(8);
    local_8c = (float)uVar1 * 0.015625;
  }
  uVar1 = MSG_ReadBits(3);
  entnum = MSG_ReadBits(0xb);
  if ((flags & 4) == 0) {
    uVar2 = MSG_ReadBits(8);
  }
  else {
    uVar2 = MSG_ReadBits(0x10);
  }
  MSG_ReadBitVec3Coord(local_74);
  local_88 = 100;
  if ((flags & 8) != 0) {
    local_88 = MSG_ReadBits(8);
  }
  MSG_EndBitReading(&net_message);
  if ((int)entnum < cl.max_edicts) {
    if ((flags & 0x10) == 0) {
      sfxin = cl.sound_precache[uVar2];
    }
    else {
      if ((int)uVar2 < 0x800) {
        pcVar3 = rgpszrawsentence[uVar2];
        puVar4 = &DAT_00263ab4;
      }
      else {
        pcVar3 = (char *)(uVar2 - 0x800);
        puVar4 = &DAT_00266970;
      }
      sfxin = &local_68;
      __snprintf_chk(sfxin,0x40,1,0x40,puVar4,pcVar3);
    }
    if (uVar1 == 6) {
      S_StartStaticSound(entnum,6,sfxin,local_74,local_90,local_8c,flags,local_88);
    }
    else {
      S_StartDynamicSound(entnum,uVar1,sfxin,local_74,local_90,local_8c,flags,local_88);
    }
  }
  else {
    Con_DPrintf("CL_Parse_Sound: ent = %i, cl.max_edicts %i\n",entnum,cl.max_edicts);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Parse_SoundFade  @ 00138d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SoundFade(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = MSG_ReadByte();
  iVar2 = MSG_ReadByte();
  iVar3 = MSG_ReadByte();
  cls.soundfade.soundFadeOutTime = MSG_ReadByte();
  cls.soundfade.soundFadeStartTime = realtime;
  cls.soundfade.nStartPercent = iVar1;
  cls.soundfade.soundFadeHoldTime = iVar2;
  cls.soundfade.soundFadeInTime = iVar3;
  return;
}


// CL_Parse_SpawnBaseline  @ 00138990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SpawnBaseline(void)

{
  undefined4 uVar1;
  cl_entity_t *pcVar2;
  uint uVar3;
  delta_t **ppdVar4;
  delta_t **ppdVar5;
  delta_t **ppdVar6;
  uint32 uVar7;
  uint32 index;
  delta_t *pFields;
  qboolean qVar8;
  uint uVar9;
  entity_state_t *to;
  cl_entity_t *unaff_EBX;
  int iVar10;
  int in_GS_OFFSET;
  uchar auStack_174 [340];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  ppdVar4 = DELTA_LookupRegistration("entity_state_t");
  ppdVar5 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar6 = DELTA_LookupRegistration("custom_entity_state_t");
  Q_memset(auStack_174,0,0x154);
  MSG_StartBitReading(&net_message);
  ContinueLoadingProgressBar("ClientConnect",0xb,0.0);
  SetLoadingProgressBarStatusText("#GameUI_ParseBaseline");
  cl.highentity = 0;
  while (uVar7 = MSG_PeekBits(0x10), uVar7 != 0xffff) {
    index = MSG_ReadBits(0xb);
    uVar7 = index;
    if ((int)index <= cl.highentity) {
      uVar7 = cl.highentity;
    }
    cl.highentity = uVar7;
    if (cl.num_entities <= (int)index) {
      if (cl.max_edicts <= (int)index) {
                    /* WARNING: Subroutine does not return */
        Host_Error("CL_EntityNum: %i is an invalid number, cl.max_edicts is %i",index,cl.max_edicts)
        ;
      }
      do {
        cl_entities[index].index = index;
        cl.num_entities = cl.num_entities + 1;
      } while (cl.num_entities <= (int)index);
    }
    cl_entities[index].index = index;
    pcVar2 = cl_entities;
    uVar7 = MSG_ReadBits(2);
    unaff_EBX = pcVar2 + index;
    if ((uVar7 & 2) == 0) {
      qVar8 = CL_IsPlayerIndex(index);
      if (qVar8 == false) {
        pFields = *ppdVar4;
      }
      else {
        pFields = *ppdVar5;
      }
    }
    else {
      pFields = *ppdVar6;
    }
    DELTA_ParseDelta(auStack_174,(uchar *)&unaff_EBX->baseline,pFields,0x154);
    (unaff_EBX->baseline).entityType = uVar7 & 0xff;
  }
  iVar10 = 0;
  MSG_ReadBits(0x10);
  Q_memset(cl.instanced_baseline,0,0x5500);
  cl.instanced_baseline_number = MSG_ReadBits(6);
  to = cl.instanced_baseline;
  if (0 < cl.instanced_baseline_number) {
    do {
      iVar10 = iVar10 + 1;
      DELTA_ParseDelta(auStack_174,(uchar *)to,*ppdVar4,0x154);
      to = to + 1;
    } while (iVar10 < cl.instanced_baseline_number);
  }
  MSG_EndBitReading(&net_message);
  uVar3 = 0;
  do {
    uVar9 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0xc));
    *(undefined4 *)((int)(unaff_EBX->curstate).origin + (uVar9 - 0x10)) =
         *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0x10));
    *(undefined4 *)((int)(unaff_EBX->curstate).origin + (uVar9 - 0xc)) = uVar1;
    uVar3 = uVar9 + 8;
  } while (uVar9 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_EBX->curstate).origin + (uVar9 - 8)) =
       *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 8));
  uVar3 = 0;
  do {
    uVar9 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0xc));
    *(undefined4 *)((int)(unaff_EBX->prevstate).origin + (uVar9 - 0x10)) =
         *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 0x10));
    *(undefined4 *)((int)(unaff_EBX->prevstate).origin + (uVar9 - 0xc)) = uVar1;
    uVar3 = uVar9 + 8;
  } while (uVar9 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_EBX->prevstate).origin + (uVar9 - 8)) =
       *(undefined4 *)((int)(unaff_EBX->baseline).origin + (uVar9 - 8));
  if (iStack_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Parse_SpawnStatic  @ 001389a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SpawnStatic(void)

{
  return;
}


// CL_Parse_SpawnStaticSound  @ 00138a50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SpawnStaticSound(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int entnum;
  int pitch;
  uint flags;
  sfx_t *psVar4;
  sfx_s *sfxin;
  int in_GS_OFFSET;
  float fVar5;
  undefined1 auStack_74 [84];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  psVar4 = (sfx_t *)auStack_74;
  do {
    sfxin = (sfx_s *)(psVar4->name + 4);
    fVar5 = MSG_ReadCoord(&net_message);
    *(float *)psVar4->name = fVar5;
    psVar4 = sfxin;
  } while (sfxin != (sfx_t *)(auStack_74 + 0xc));
  iVar1 = MSG_ReadShort();
  iVar2 = MSG_ReadByte();
  iVar3 = MSG_ReadByte();
  entnum = MSG_ReadShort();
  pitch = MSG_ReadByte();
  flags = MSG_ReadByte();
  if ((flags & 0x10) == 0) {
    sfxin = cl.sound_precache[iVar1];
  }
  else {
    __snprintf_chk(sfxin,0x40,1,0x40,&DAT_00263ab4,rgpszrawsentence[iVar1]);
  }
  S_StartStaticSound(entnum,6,sfxin,(vec_t *)auStack_74,(float)iVar2 / 255.0,(float)iVar3 * 0.015625
                     ,flags,pitch);
  if (iStack_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Parse_StopSound  @ 00138960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_StopSound(void)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???] */
  uVar1 = MSG_ReadShort();
  S_StopSound((int)uVar1 >> 3,uVar1 & 7);
  return;
}


// CL_Parse_StuffText  @ 00138710
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_StuffText(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  qboolean qVar4;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * pchTokCmd@[???] */
  pcVar1 = MSG_ReadString();
  Cmd_TokenizeString(pcVar1);
  pcVar2 = Cmd_Argv(0);
  if (pcVar2 != (char *)0x0) {
    iVar3 = strcasecmp(pcVar2,"allow_autoaim");
    if (iVar3 == 0) {
      pcVar1 = Cmd_Argv(1);
      if (pcVar1 == (char *)0x0) {
        return;
      }
      pcVar1 = Cmd_Argv(1);
      pcVar2 = "1";
      if (*pcVar1 == '0') {
        pcVar2 = "0";
      }
      Cvar_DirectSet(&sv_allow_autoaim,pcVar2);
      return;
    }
    iVar3 = strcasecmp(pcVar2,"allow_shaders");
    if (iVar3 == 0) {
      pcVar1 = Cmd_Argv(1);
      if (pcVar1 == (char *)0x0) {
        return;
      }
      pcVar1 = Cmd_Argv(1);
      pcVar2 = "1";
      if (*pcVar1 == '0') {
        pcVar2 = "0";
      }
      Cvar_DirectSet(&sv_allow_shaders,pcVar2);
      return;
    }
  }
  qVar4 = ValidStuffText(pcVar1);
  if (qVar4 != false) {
    Cbuf_AddFilteredText(pcVar1);
    return;
  }
  Con_Printf("Server tried to send invalid command:\"%s\"\n",pcVar1);
  return;
}


// CL_Parse_TempEntity  @ 001389b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_TempEntity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  customization_s *pcVar5;
  cachewad_t *wad;
  _func_void_cl_entity_s_ptr_int_int *p_Var6;
  _func_void_TEMPENTITY_ptr_float_int *p_Var7;
  _func_void_TEMPENTITY_ptr_float *p_Var8;
  _func_void_float_ptr_float_float_int_int *p_Var9;
  _func_TEMPENTITY_ptr_float_ptr_float_ptr_float_ptr_float_int_int *p_Var10;
  _func_void_int_int_int_float_ptr_int *p_Var11;
  _func_BEAM_ptr_float_ptr_float_ptr_int_float_float_float_float_float_int_float_float_float_float
  *p_Var12;
  double dVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  texture_t *ptexture;
  int32 iVar20;
  dlight_t *pdVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  TEMPENTITY *pTVar28;
  int unaff_EBP;
  longdouble lVar29;
  longdouble lVar30;
  float fVar31;
  float fVar32;
  int iStack_a4;
  int iStack_74;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  vec_t vStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
  iVar15 = MSG_ReadByte();
  switch(iVar15) {
  case 0:
  case 1:
  case 8:
    if (iVar15 == 8) {
      unaff_EBP = MSG_ReadShort();
      iStack_74 = MSG_ReadShort();
    }
    else {
      if (iVar15 == 1) {
        unaff_EBP = MSG_ReadShort();
      }
      else {
        fStack_64 = MSG_ReadCoord(&net_message);
        fStack_60 = MSG_ReadCoord(&net_message);
        fStack_5c = MSG_ReadCoord(&net_message);
      }
      fStack_4c = MSG_ReadCoord(&net_message);
      fStack_48 = MSG_ReadCoord(&net_message);
      fStack_44 = MSG_ReadCoord(&net_message);
    }
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    fVar31 = (float)((longdouble)0.1 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar32 = (float)((longdouble)0.1 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fStack_58 = (float)uVar22;
    iVar18 = MSG_ReadByte();
    fStack_54 = (float)iVar18;
    uVar22 = MSG_ReadByte();
    fVar1 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar2 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar3 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    uVar22 = MSG_ReadByte();
    fVar4 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar22);
    iVar18 = MSG_ReadByte();
    iVar18 = (int)((float)iVar18 * 0.1);
    if (iVar15 == 8) {
      (*efx.R_BeamEnts)(unaff_EBP,iStack_74,iVar16,fVar32,fStack_58 * 0.1,fStack_54 * 0.01,fVar4,
                        (float)iVar18,iVar17,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar15 == 1) {
      (*efx.R_BeamEntPoint)
                (unaff_EBP,&fStack_4c,iVar16,fVar32,fStack_58 * 0.1,fStack_54 * 0.01,fVar4,
                 (float)iVar18,iVar17,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar15 == 0) {
      (*efx.R_BeamPoints)(&fStack_64,&fStack_4c,iVar16,fVar32,fStack_58 * 0.1,fStack_54 * 0.01,fVar4
                          ,(float)iVar18,iVar17,fVar31,fVar1,fVar2,fVar3);
    }
    break;
  case 2:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    (*efx.R_RunParticleEffect)(&fStack_64,vec3_origin,0,0x14);
    (*efx.R_RicochetSound)(&fStack_64);
    break;
  case 3:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    fStack_58 = (float)iVar16 * 0.1;
    iVar16 = MSG_ReadByte();
    fStack_54 = (float)iVar16;
    uVar22 = MSG_ReadByte();
    fVar31 = fStack_58;
    p_Var7 = efx.R_Sprite_Explode;
    if (fStack_58 != 0.0) {
      pTVar28 = R_DefaultSprite(&fStack_64,iVar15,fStack_54);
      (*p_Var7)(pTVar28,fVar31,uVar22);
      if ((uVar22 & 8) == 0) {
        (*efx.R_FlickerParticles)(&fStack_64);
      }
      if ((uVar22 & 2) == 0) {
        pdVar21 = (*efx.CL_AllocDlight)(0);
        pdVar21->origin[0] = fStack_64;
        pdVar21->origin[1] = fStack_60;
        pdVar21->radius = 200.0;
        (pdVar21->color).g = 0xfa;
        pdVar21->origin[2] = fStack_5c;
        (pdVar21->color).r = 0xfa;
        (pdVar21->color).b = 0x96;
        pdVar21->die = (float)((longdouble)0.01 + (longdouble)cl.time);
        pdVar21->decay = 800.0;
        pdVar21 = (*efx.CL_AllocDlight)(0);
        pdVar21->origin[0] = fStack_64;
        pdVar21->origin[1] = fStack_60;
        pdVar21->radius = 150.0;
        (pdVar21->color).r = 0xff;
        pdVar21->origin[2] = fStack_5c;
        (pdVar21->color).g = 0xbe;
        (pdVar21->color).b = '(';
        pdVar21->die = (float)cl.time + 1.0;
        pdVar21->decay = 200.0;
      }
    }
    if ((uVar22 & 4) != 0) {
      return;
    }
    iVar20 = RandomLong(0,2);
    if (iVar20 == 1) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp2,&fStack_64,1.0,0.3,0,100);
      return;
    }
    if (iVar20 == 2) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp3,&fStack_64,1.0,0.3,0,100);
      return;
    }
    if (iVar20 != 0) {
      return;
    }
    fVar31 = 0.3;
    goto LAB_00151cfb;
  case 4:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    (*efx.R_BlobExplosion)(&fStack_64);
    fVar31 = 1.0;
    goto LAB_00151cfb;
  case 5:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    fStack_58 = (float)iVar16 * 0.1;
    iVar16 = MSG_ReadByte();
    fVar31 = fStack_58;
    p_Var8 = efx.R_Sprite_Smoke;
    fStack_54 = (float)iVar16;
    pTVar28 = R_DefaultSprite(&fStack_64,iVar15,fStack_54);
    (*p_Var8)(pTVar28,fVar31);
    break;
  case 6:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    (*efx.R_TracerEffect)(&fStack_64,&fStack_4c);
    break;
  case 7:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    fStack_58 = (float)iVar16;
    iVar16 = MSG_ReadByte();
    fStack_54 = (float)iVar16;
    iVar16 = MSG_ReadShort();
    (*efx.R_BeamLightning)
              (&fStack_64,&fStack_4c,iVar16,(float)iVar15 * 0.1,fStack_58 * 0.1,fStack_54 * 0.01,0.6
               ,3.5);
    break;
  case 9:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    (*efx.R_SparkEffect)(&fStack_64,8,-200,200);
    break;
  case 10:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    (*efx.R_LavaSplash)(&fStack_64);
    break;
  case 0xb:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    (*efx.R_TeleportSplash)(&fStack_64);
    break;
  case 0xc:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_ParticleExplosion2)(&fStack_64,iVar15,iVar16);
    pdVar21 = (*efx.CL_AllocDlight)(0);
    pdVar21->origin[0] = fStack_64;
    pdVar21->origin[1] = fStack_60;
    pdVar21->radius = 350.0;
    pdVar21->origin[2] = fStack_5c;
    pdVar21->die = (float)cl.time + 0.5;
    pdVar21->decay = 300.0;
    fVar31 = 0.6;
LAB_00151cfb:
    S_StartDynamicSound(-1,0,cl_sfx_r_exp1,&fStack_64,1.0,fVar31,0,100);
    break;
  case 0xd:
  case 0x68:
  case 0x74:
  case 0x75:
  case 0x76:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    if (iVar15 == 0xd) {
      iVar16 = MSG_ReadShort();
      iVar17 = MSG_ReadShort();
      if (iVar17 != 0) {
        iVar18 = MSG_ReadShort();
        iStack_a4 = 1;
        goto LAB_00151bbd;
      }
      iVar18 = 0;
      iStack_a4 = 1;
    }
    else {
      iVar16 = MSG_ReadByte();
      if ((iVar15 == 0x68) || (iVar15 == 0x76)) {
        iVar17 = MSG_ReadShort();
        iVar18 = 0;
        iStack_a4 = 0;
      }
      else {
        iVar17 = 0;
        iStack_a4 = 0;
        iVar18 = 0;
      }
LAB_00151bbd:
      if (iVar15 - 0x75U < 2) {
        iVar16 = iVar16 + 0x100;
      }
    }
    p_Var11 = efx.R_DecalShoot;
    if (cl.max_edicts <= iVar17) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Decal: entity = %i",iVar17);
    }
    if (r_decals.value != 0.0) {
      iVar15 = (*efx.Draw_DecalIndex)(iVar16);
      (*p_Var11)(iVar15,iVar17,iVar18,&fStack_64,iStack_a4);
    }
    break;
  case 0xe:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    fStack_58 = (float)iVar15;
    iVar15 = MSG_ReadByte();
    fStack_54 = (float)iVar15;
    iVar15 = MSG_ReadByte();
    fStack_50 = (float)iVar15 / 10.0;
    (*efx.R_Implosion)(&fStack_64,fStack_58,(int)fStack_54,fStack_50);
    break;
  case 0xf:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    if ((longdouble)uVar23 == (longdouble)0) {
      fStack_58 = 1.0;
    }
    else {
      fStack_58 = (float)((longdouble)0.1 * (longdouble)uVar23);
    }
    iVar17 = MSG_ReadByte();
    fStack_54 = (float)iVar17 * 10.0;
    iVar17 = MSG_ReadByte();
    (*efx.R_Sprite_Trail)
              (0xf,&fStack_64,&fStack_4c,iVar15,iVar16,(float)((longdouble)0.1 * (longdouble)uVar22)
               ,fStack_58,fStack_54,0xff,(float)(int)((double)iVar17 * 10.0));
    break;
  default:
                    /* WARNING: Subroutine does not return */
    Sys_Error("CL_ParseTEnt: bad type");
  case 0x11:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    fStack_58 = (float)iVar16 * 0.1;
    uVar22 = MSG_ReadByte();
    (*efx.R_TempSprite)(&fStack_64,vec3_origin,fStack_58,iVar15,5,0,
                        (float)((longdouble)0.00392156862745098 * (longdouble)uVar22),0.0,0x100);
    break;
  case 0x12:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    p_Var12 = efx.R_BeamPoints;
    fVar31 = RandomFloat(0.5,0.655);
    (*p_Var12)(&fStack_64,&fStack_4c,iVar15,0.01,0.4,0.0,fVar31,5.0,0,0.0,1.0,0.0,0.0);
    (*efx.R_TempSprite)(&fStack_4c,vec3_origin,0.1,iVar16,5,0,0.35,0.01,0);
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    fStack_58 = (float)uVar24;
    iVar18 = MSG_ReadByte();
    fStack_54 = (float)iVar18;
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    uVar27 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamCirclePoints)
              (iVar15,&fStack_64,&fStack_4c,iVar16,(float)((longdouble)uVar23 * lVar30),fStack_58,
               fStack_54 * 0.01,(float)((longdouble)uVar27 * lVar29),
               (float)(int)((longdouble)iVar18 * lVar30),iVar17,(float)((longdouble)uVar22 * lVar30)
               ,(float)((longdouble)uVar24 * lVar29),(float)((longdouble)uVar25 * lVar29),
               (float)((longdouble)uVar26 * lVar29));
    break;
  case 0x16:
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    fStack_58 = (float)uVar23;
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    (*efx.R_BeamFollow)(iVar15,iVar16,(float)((longdouble)0.1 * (longdouble)uVar22),fStack_58,
                        (float)((longdouble)uVar23 * lVar29),(float)((longdouble)uVar24 * lVar29),
                        (float)((longdouble)uVar25 * lVar29),(float)((longdouble)uVar26 * lVar29));
    break;
  case 0x17:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    uVar22 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    fStack_58 = (float)iVar16 * 0.1;
    uVar23 = MSG_ReadByte();
    (*efx.R_TempSprite)(&fStack_64,vec3_origin,fStack_58,iVar15,3,0xe,
                        (float)((longdouble)0.00392156862745098 * (longdouble)uVar23),
                        (float)((longdouble)0.1 * (longdouble)uVar22),0x80);
    break;
  case 0x18:
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    iVar18 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    fStack_58 = (float)uVar24;
    iVar19 = MSG_ReadByte();
    fStack_54 = (float)iVar19;
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    uVar27 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamRing)(iVar15,iVar16,iVar17,(float)((longdouble)uVar23 * lVar30),
                      (float)(lVar30 * (longdouble)fStack_58),fStack_54 * 0.01,
                      (float)((longdouble)uVar27 * lVar29),(float)(int)((longdouble)iVar19 * lVar30)
                      ,iVar18,(float)((longdouble)uVar22 * lVar30),
                      (float)((longdouble)uVar24 * lVar29),(float)((longdouble)uVar25 * lVar29),
                      (float)((longdouble)uVar26 * lVar29));
    break;
  case 0x19:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    iVar18 = MSG_ReadShort();
    (*efx.R_StreakSplash)(&fStack_64,&fStack_28,iVar15,iVar16,(float)iVar17,-iVar18,iVar18);
    break;
  case 0x1b:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    pdVar21 = (*efx.CL_AllocDlight)(0);
    pdVar21->origin[0] = fStack_64;
    pdVar21->origin[1] = fStack_60;
    pdVar21->origin[2] = fStack_5c;
    iVar15 = MSG_ReadByte();
    pdVar21->radius = (float)(iVar15 * 10);
    iVar15 = MSG_ReadByte();
    (pdVar21->color).r = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).g = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).b = (byte)iVar15;
    dVar13 = cl.time;
    iVar15 = MSG_ReadByte();
    pdVar21->die = (float)iVar15 * 0.1 + (float)dVar13;
    iVar15 = MSG_ReadByte();
    pdVar21->decay = (float)(iVar15 * 10);
    break;
  case 0x1c:
    iVar15 = MSG_ReadShort();
    pdVar21 = (*efx.CL_AllocElight)(iVar15);
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->origin[0] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->origin[1] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->origin[2] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar21->radius = fVar31;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).r = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).g = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    (pdVar21->color).b = (byte)iVar15;
    iVar15 = MSG_ReadByte();
    fVar31 = (float)iVar15 * 0.1;
    pdVar21->die = fVar31 + (float)cl.time;
    fVar32 = MSG_ReadCoord(&net_message);
    if (fVar31 != 0.0) {
      fVar32 = fVar32 / fVar31;
    }
    pdVar21->decay = fVar32;
    break;
  case 0x1d:
    CL_ParseTextMessage();
    break;
  case 0x1e:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    fStack_58 = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    fVar31 = fStack_58;
    iStack_a4._0_1_ = (uchar)iVar15;
    sVar14 = R_LookupColor((uchar)iStack_a4,(uchar)iVar16,(uchar)iVar17);
    PM_ParticleLine(&fStack_64,&fStack_4c,(int)sVar14,fVar31,0.0);
    break;
  case 0x1f:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    fStack_58 = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    fVar31 = fStack_58;
    iStack_a4._0_1_ = (uchar)iVar15;
    sVar14 = R_LookupColor((uchar)iStack_a4,(uchar)iVar16,(uchar)iVar17);
    fStack_28 = (fStack_64 + fStack_4c) * 0.5;
    vStack_34 = fStack_4c - fStack_28;
    fStack_40 = fStack_64 - fStack_28;
    fStack_24 = (fStack_48 + fStack_60) * 0.5;
    fStack_30 = fStack_48 - fStack_24;
    fStack_3c = fStack_60 - fStack_24;
    fStack_20 = (fStack_44 + fStack_5c) * 0.5;
    fStack_2c = fStack_44 - fStack_20;
    fStack_38 = fStack_5c - fStack_20;
    PM_DrawBBox(&fStack_40,&vStack_34,&fStack_28,(int)sVar14,fVar31);
    break;
  case 99:
    iVar15 = MSG_ReadShort();
    (*efx.R_BeamKill)(iVar15);
    break;
  case 100:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    (*efx.R_LargeFunnel)(&fStack_64,iVar16);
    (*efx.R_FunnelSprite)(&fStack_64,iVar15,iVar16);
    break;
  case 0x65:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodStream)(&fStack_64,&fStack_28,iVar15,iVar16);
    }
    break;
  case 0x66:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    (*efx.R_ShowLine)(&fStack_64,&fStack_4c);
    break;
  case 0x67:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_Blood)(&fStack_64,&fStack_28,iVar15,iVar16);
    }
    break;
  case 0x69:
    iVar15 = MSG_ReadShort();
    if (cl.max_edicts <= iVar15) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Bubble: entity = %i",iVar15);
    }
    iVar16 = MSG_ReadShort();
    p_Var6 = efx.R_FizzEffect;
    iVar17 = MSG_ReadByte();
    (*p_Var6)(cl_entities + iVar15,iVar16,iVar17);
    break;
  case 0x6a:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    fStack_4c = 0.0;
    fStack_48 = MSG_ReadAngle();
    fStack_44 = 0.0;
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    p_Var10 = efx.R_TempModel;
    iVar17 = MSG_ReadByte();
    (*p_Var10)(&fStack_64,&fStack_28,&fStack_4c,(float)iVar17 * 0.1,iVar15,iVar16);
    break;
  case 0x6b:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    p_Var9 = efx.R_TempSphereModel;
    iVar17 = MSG_ReadByte();
    (*p_Var9)(&fStack_64,fStack_28,(float)iVar17 * 0.1,iVar16,iVar15);
    break;
  case 0x6c:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_58 = MSG_ReadCoord(&net_message);
    fStack_54 = MSG_ReadCoord(&net_message);
    fStack_50 = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    (*efx.R_BreakModel)(&fStack_64,&fStack_58,&fStack_28,(float)iVar15 * 10.0,(float)iVar18 * 0.1,
                        iVar17,iVar16,(char)iVar19);
    break;
  case 0x6d:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    (*efx.R_BulletImpactParticles)(&fStack_64);
    iVar20 = RandomLong(0,0x7fff);
    if (iVar20 < 0x3fff) {
      switch(iVar20 % 5) {
      case 0:
        S_StartDynamicSound(-1,0,cl_sfx_ric1,&fStack_64,1.0,1.0,0,100);
        break;
      case 1:
        S_StartDynamicSound(-1,0,cl_sfx_ric2,&fStack_64,1.0,1.0,0,100);
        break;
      case 2:
        S_StartDynamicSound(-1,0,cl_sfx_ric3,&fStack_64,1.0,1.0,0,100);
        break;
      case 3:
        S_StartDynamicSound(-1,0,cl_sfx_ric4,&fStack_64,1.0,1.0,0,100);
        break;
      case 4:
        S_StartDynamicSound(-1,0,cl_sfx_ric5,&fStack_64,1.0,1.0,0,100);
      }
    }
    p_Var11 = efx.R_DecalShoot;
    if (cl.max_edicts <= iVar15) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Decal: entity = %i",iVar15);
    }
    if (r_decals.value != 0.0) {
      iVar16 = (*efx.Draw_DecalIndex)(iVar16);
      (*p_Var11)(iVar16,iVar15,0,&fStack_64,0);
    }
    break;
  case 0x6e:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_Sprite_Spray)(&fStack_64,&fStack_28,iVar15,iVar16,iVar17 * 2,iVar18);
    break;
  case 0x6f:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    fStack_58 = (float)iVar15 * 0.1;
    (*efx.R_RicochetSprite)(&fStack_64,cl_sprite_ricochet,0.1,fStack_58);
    (*efx.R_RicochetSound)(&fStack_64);
    break;
  case 0x70:
    iVar15 = MSG_ReadByte();
    if (iVar15 - 1U < 0x20) {
      pcVar5 = cl.players[iVar15 + -1].customdata.pNext;
      fStack_64 = MSG_ReadCoord(&net_message);
      fStack_60 = MSG_ReadCoord(&net_message);
      fStack_5c = MSG_ReadCoord(&net_message);
      iVar17 = MSG_ReadShort();
      iVar16 = MSG_ReadByte();
      if (cl.max_edicts <= iVar17) {
LAB_001526e8:
                    /* WARNING: Subroutine does not return */
        Sys_Error("Decal: entity = %i",iVar17);
      }
      if (pcVar5 != (customization_s *)0x0) {
        if (pcVar5->pBuffer == (void *)0x0) {
          return;
        }
        wad = pcVar5->pInfo;
        if (wad == (cachewad_t *)0x0) {
          return;
        }
        if (((pcVar5->resource).ucFlags & 4) == 0) {
          return;
        }
        if ((pcVar5->resource).type != t_decal) {
          return;
        }
        if (pcVar5->bTranslated == false) {
          return;
        }
        iVar18 = wad->lumpCount + -1;
        if (iVar18 <= iVar16) {
          iVar16 = iVar18;
        }
        pcVar5->nUserData1 = iVar16;
        ptexture = Draw_CustomCacheGet(wad,pcVar5->pBuffer,(pcVar5->resource).nDownloadSize,iVar16);
        if (r_decals.value == 0.0) {
          return;
        }
        if (ptexture == (texture_t *)0x0) {
          return;
        }
        R_CustomDecalShoot(ptexture,iVar15 - 1U,iVar17,0,&fStack_64,4);
        return;
      }
    }
    else {
      fStack_64 = MSG_ReadCoord(&net_message);
      fStack_60 = MSG_ReadCoord(&net_message);
      fStack_5c = MSG_ReadCoord(&net_message);
      iVar17 = MSG_ReadShort();
      iVar16 = MSG_ReadByte();
      if (cl.max_edicts <= iVar17) goto LAB_001526e8;
    }
    p_Var11 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      iVar15 = (*efx.Draw_DecalIndex)(iVar16);
      (*p_Var11)(iVar15,iVar17,0,&fStack_64,4);
    }
    break;
  case 0x71:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    fStack_58 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    fStack_54 = MSG_ReadCoord(&net_message);
    (*efx.R_Bubbles)(&fStack_64,&fStack_4c,fStack_58,iVar15,iVar16,fStack_54);
    break;
  case 0x72:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_4c = MSG_ReadCoord(&net_message);
    fStack_48 = MSG_ReadCoord(&net_message);
    fStack_44 = MSG_ReadCoord(&net_message);
    fStack_58 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    fStack_54 = MSG_ReadCoord(&net_message);
    (*efx.R_BubbleTrail)(&fStack_64,&fStack_4c,fStack_58,iVar15,iVar16,fStack_54);
    break;
  case 0x73:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    fStack_58 = (float)iVar18;
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodSprite)(&fStack_64,iVar17,iVar15,iVar16,fStack_58);
    }
    break;
  case 0x77:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_Projectile)(&fStack_64,&fStack_28,iVar15,(int)(float)iVar16,iVar17,
                        (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0);
    break;
  case 0x78:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    (*efx.R_Spray)(&fStack_64,&fStack_28,iVar15,iVar16,iVar17,iVar18,iVar19);
    break;
  case 0x79:
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_PlayerSprites)(iVar15,iVar16,iVar17,iVar18);
    break;
  case 0x7a:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_ParticleBurst)(&fStack_64,iVar15,iVar16,(float)iVar17 / 10.0);
    break;
  case 0x7b:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    iVar19 = MSG_ReadByte();
    (*efx.R_FireField)(&fStack_64,iVar15,iVar16,iVar17,iVar18,(float)iVar19 / 10.0);
    break;
  case 0x7c:
    iVar15 = MSG_ReadByte();
    fVar31 = MSG_ReadCoord(&net_message);
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    (*efx.R_AttachTentToPlayer)(iVar15,iVar16,fVar31,(float)iVar17 / 10.0);
    break;
  case 0x7d:
    iVar15 = MSG_ReadByte();
    (*efx.R_KillAttachedTents)(iVar15);
    break;
  case 0x7e:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_28 = fStack_28 / 10.0;
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_24 = fStack_24 / 10.0;
    fStack_20 = MSG_ReadCoord(&net_message);
    fStack_20 = fStack_20 / 10.0;
    fStack_58 = MSG_ReadCoord(&net_message);
    fStack_54 = MSG_ReadCoord(&net_message);
    fStack_50 = 0.0;
    fStack_58 = fStack_58 / 100.0;
    fStack_54 = fStack_54 / 100.0;
    iVar15 = MSG_ReadByte();
    vStack_34 = (vec_t)MSG_ReadByte();
    (*efx.R_MultiGunshot)(&fStack_64,&fStack_28,&fStack_58,iVar15,1,(int *)&vStack_34);
    break;
  case 0x7f:
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_60 = MSG_ReadCoord(&net_message);
    fStack_5c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_20 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_UserTracerParticle)
              (&fStack_64,&fStack_28,(float)iVar15 / 10.0,iVar16,(float)iVar17 / 10.0,'\0',
               (_func_void_particle_s_ptr *)0x0);
  }
  return;
}


// CL_Parse_Time  @ 00137980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Time(void)

{
  double dVar1;
  float fVar2;
  
                    /* Unresolved local var: double dt@[???] */
  cl.mtime[1] = cl.mtime[0];
  fVar2 = MSG_ReadFloat();
  cl.mtime[0] = (double)fVar2;
  if (cl.maxclients == 1) {
    cl.time = (double)fVar2;
  }
  dVar1 = cl.time - (double)fVar2;
  if (ABS(dVar1) <= (double)cl_clockreset.value) {
    if (dVar1 == 0.0) {
                    /* catch() { ... } // from try @ 00137d6c with catch @ 001379f0 */
      dVar1 = g_clockdelta;
    }
  }
  else {
    cl.time = (double)fVar2;
    g_clockdelta = 0.0;
    dVar1 = g_clockdelta;
  }
  g_clockdelta = dVar1;
  if (cl.time < cl.oldtime) {
    cl.oldtime = cl.time;
  }
  return;
}


// CL_Parse_Timescale  @ 001398f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Timescale(void)

{
  sys_timescale.value = MSG_ReadFloat();
  if (((cls.spectator != false) || (cls.demoplayback != false)) && (0.1 <= sys_timescale.value)) {
    return;
  }
  sys_timescale.value = 1.0;
  return;
}


// CL_Parse_UpdateUserInfo  @ 00138bb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_UpdateUserInfo(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint64 uVar6;
  
  iVar2 = MSG_ReadByte();
  if (iVar2 < 0x20) {
    iVar3 = MSG_ReadLong();
    pcVar5 = cl.players[iVar2].userinfo;
    cl.players[iVar2].userid = iVar3;
    pcVar4 = MSG_ReadString();
    Q_strncpy(pcVar5,pcVar4,0xff);
    cl.players[iVar2].userinfo[0xff] = '\0';
    MSG_ReadBuf(0x10,cl.players[iVar2].hashedcdkey);
    pcVar4 = Info_ValueForKey(pcVar5,"name");
    Q_strncpy(cl.players[iVar2].name,pcVar4,0x1f);
    cl.players[iVar2].name[0x1f] = '\0';
    pcVar4 = Info_ValueForKey(pcVar5,"model");
    Q_strncpy(cl.players[iVar2].model,pcVar4,0x3f);
    cl.players[iVar2].model[0x3f] = '\0';
    pcVar4 = Info_ValueForKey(pcVar5,"topcolor");
    iVar3 = Q_atoi(pcVar4);
    cl.players[iVar2].topcolor = iVar3;
    pcVar4 = Info_ValueForKey(pcVar5,"bottomcolor");
    iVar3 = Q_atoi(pcVar4);
    cl.players[iVar2].bottomcolor = iVar3;
    pcVar4 = Info_ValueForKey(pcVar5,"*hltv");
    iVar3 = Q_atoi(pcVar4);
    cl.players[iVar2].spectator = iVar3;
    pcVar5 = Info_ValueForKey(pcVar5,"*sid");
    uVar6 = strtoll(pcVar5,(char **)0x0,10);
    cVar1 = cl.players[iVar2].userinfo[0];
    cl.players[iVar2].m_nSteamID = uVar6;
    if ((cVar1 == '\0') || (cl.players[iVar2].name[0] == '\0')) {
      COM_ClearCustomizationList(&cl.players[iVar2].customdata,true);
    }
    Steam_UpdateRichPresence();
    return;
  }
                    /* WARNING: Subroutine does not return */
  Host_EndGame("CL_ParseServerMessage: svc_updateuserinfo > MAX_CLIENTS");
}


// CL_Parse_Version  @ 00137c40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Version(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = MSG_ReadLong();
  if (iVar1 != 0x30) {
                    /* WARNING: Subroutine does not return */
    Host_Error("CL_Parse_Version: Server is protocol %i instead of %i\n",iVar1,0x30);
  }
  return;
}


// CL_Parse_VoiceData  @ 00139970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_VoiceData(void)

{
  int nEntity;
  int iVar1;
  int iVar2;
  uint uVar3;
  uint iSize;
  int in_GS_OFFSET;
  char local_2020 [8192];
  int local_20;
  
                    /* Unresolved local var: int iEntity@[???]
                       Unresolved local var: int nDataLength@[???]
                       Unresolved local var: int nChannel@[???]
                       Unresolved local var: char[8192] chReceived@[???]
                       Unresolved local var: int startReadCount@[???] */
  iVar1 = msg_readcount;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = MSG_ReadByte();
  nEntity = iVar2 + 1;
  uVar3 = MSG_ReadShort();
  iSize = 0x2000;
  if (uVar3 < 0x2001) {
    iSize = uVar3;
  }
  uVar3 = iSize;
  MSG_ReadBuf(iSize,local_2020);
  cl.frames[cl.parsecountmod].voicebytes =
       (cl.frames[cl.parsecountmod].voicebytes + (short)msg_readcount) - (short)iVar1;
  if ((-1 < nEntity) && (nEntity < cl.num_entities)) {
    if (nEntity == cl.playernum + 1) {
      uVar3 = 1;
      Voice_LocalPlayerTalkingAck();
    }
    if (iSize != 0) {
      uVar3 = Voice_GetChannel(nEntity);
      if (uVar3 == 0xffffffff) {
        uVar3 = Voice_AssignChannel(nEntity);
        if (uVar3 == 0xffffffff) {
          uVar3 = 0x263760;
          Con_DPrintf("CL_ParseVoiceData: Voice_AssignChannel failed for client %d!\n",iVar2);
          goto LAB_00139a08;
        }
      }
      Voice_AddIncomingData(uVar3,local_2020,iSize,cls.netchan.incoming_sequence);
    }
  }
LAB_00139a08:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}


// CL_Parse_VoiceInit  @ 00139940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_VoiceInit(void)

{
  int quality;
  
                    /* Unresolved local var: char * pCodec@[???]
                       Unresolved local var: int quality@[???] */
  MSG_ReadString();
  quality = MSG_ReadByte();
  Voice_Init("",quality);
  return;
}


// CL_Parse_WeaponAnim  @ 00138b10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_WeaponAnim(void)

{
  cl.weaponstarttime = 0.0;
  cl.weaponsequence = MSG_ReadByte();
  cl.viewent.curstate.body = MSG_ReadByte();
  return;
}


// CL_Particle  @ 00134620
void CL_Particle(vec_t *origin,int color,float life,int zpos,int zvel)

{
  particle_s **pppVar1;
  float fVar2;
  vec_t vVar3;
  vec_t vVar4;
  particle_t *ppVar5;
  particle_t *ppVar6;
  
  ppVar6 = free_particles;
  ppVar5 = active_particles;
                    /* Unresolved local var: particle_t * active_particles@[???]
                       Unresolved local var: particle_t * free_particles@[???]
                       Unresolved local var: particle_t * p@[DW_OP_reg0(EAX)] */
  vVar3 = vec3_origin[0];
  if (free_particles != (particle_t *)0x0) {
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar5;
    ppVar6->die = life + (float)cl.time;
    ppVar6->color = (short)color;
    ppVar6->packedColor = 0;
    vVar4 = vec3_origin[1];
    fVar2 = (float)zvel + vec3_origin[2];
    ppVar6->vel[0] = vVar3;
    ppVar6->type = pt_static;
    ppVar6->vel[1] = vVar4;
    ppVar6->vel[2] = fVar2;
    ppVar6->org[0] = *origin;
    ppVar6->org[1] = origin[1];
    ppVar6->org[2] = (float)zpos + origin[2];
  }
  return;
}


// CL_PingServers_f  @ 00143840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PingServers_f(void)

{
  netadr_t adr;
  _func_short_short *p_Var1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: netadr_t adr@[???] */
  iVar5 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Con_Printf("Searching for local servers...\n");
  cls.slist_time = (float)realtime;
  NET_Config(true);
  Q_memset(&local_24,0,0x14);
  do {
    while( true ) {
      p_Var1 = BigShort;
      iVar4 = Q_atoi("27015");
      sVar3 = (*p_Var1)((short)iVar4 + (short)iVar5);
      local_14 = CONCAT22(sVar3,(undefined2)local_14);
      uVar2 = local_14;
      if (noip != false) break;
      local_24 = 2;
      iVar5 = iVar5 + 1;
      adr.ip[0] = (undefined1)local_20;
      adr.ip[1] = local_20._1_1_;
      adr.ip[2] = local_20._2_1_;
      adr.ip[3] = local_20._3_1_;
      adr.type = 2;
      adr.ipx[0] = (undefined1)local_1c;
      adr.ipx[1] = local_1c._1_1_;
      adr.ipx[2] = local_1c._2_1_;
      adr.ipx[3] = local_1c._3_1_;
      adr.ipx[4] = (undefined1)local_18;
      adr.ipx[5] = local_18._1_1_;
      adr.ipx[6] = local_18._2_1_;
      adr.ipx[7] = local_18._3_1_;
      adr.ipx[8] = (undefined1)local_14;
      adr.ipx[9] = local_14._1_1_;
      adr.port = sVar3;
      local_14 = uVar2;
      Netchan_OutOfBandPrint(NS_CLIENT,adr,"%c%s",0x54,0x25db9d);
      if (iVar5 == 10) goto LAB_0014392d;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 10);
LAB_0014392d:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_PlayDemo_f  @ 00142160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PlayDemo_f(void)

{
  netadr_t adr;
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] name@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    iVar1 = Cmd_Argc();
    if ((iVar1 == 2) || (iVar1 = Cmd_Argc(), iVar1 == 3)) {
      g_demotimescale = 1.0;
      iVar1 = Cmd_Argc();
      if (iVar1 == 3) {
        pcVar2 = Cmd_Argv(2);
        g_demotimescale = Q_atof(pcVar2);
        if (g_demotimescale <= 0.001) {
          g_demotimescale = 1.0;
        }
        Con_Printf("Playdemo:  Time scale %f\n",SUB84((double)g_demotimescale,0),
                   (int)((ulonglong)(double)g_demotimescale >> 0x20));
      }
      CL_Disconnect();
      DemoPlayer_SetActive(0);
      pcVar2 = Cmd_Argv(1);
      Q_strncpy(local_110,pcVar2,0xfb);
      COM_DefaultExtension(local_110,".dem");
      Con_Printf("Playing demo from %s.\n",local_110);
      cls.demofile = FS_Open(local_110,"rb");
      if (cls.demofile == (FileHandle_t)0x0) {
        Con_Printf("ERROR: couldn\'t open.\n");
        cls.demonum = -1;
      }
      else {
        FS_Read(&demoheader,0x220,1,cls.demofile);
        iVar1 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
        if (iVar1 == 0) {
          if ((demoheader.nNetProtocolVersion != 0x30) || (demoheader.nDemoProtocol != 5)) {
            Con_Printf("WARNING! demo protocol outdated.\nDemo file protocols %i:%i, Engine protocol is at %i:%i\n"
                       ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
          }
                    /* try { // try from 001422e0 to 001522e4 has its CatchHandler @ 00142304 */
          FS_Seek(cls.demofile,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                    /* catch(type#1 @ 00010000) { ... } // from try @ 001422e0 with catch @ 00142304
                        */
                    /* try { // try from 0014230e to 00152312 has its CatchHandler @ 001420f0 */
          FS_Read(&demodir,4,1,cls.demofile);
          if (demodir.nEntries - 1U < 0x400) {
            demodir.p_rgEntries = Mem_Malloc(demodir.nEntries * 0x5c);
            FS_Read(demodir.p_rgEntries,demodir.nEntries * 0x5c,1,cls.demofile);
            nCurEntryIndex = 0;
            pCurrentEntry = demodir.p_rgEntries;
            FS_Seek(cls.demofile,(demodir.p_rgEntries)->nOffset,FILESYSTEM_SEEK_HEAD);
            cls.forcetrack = pCurrentEntry->nCDTrack;
            cls.demostarttime = g_demotimescale * (float)realtime;
            cls.demoplayback = true;
            cls.state = ca_connected;
            cls.passive = false;
            cls.spectator = false;
            cls.demostartframe = host_framecount;
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
            Netchan_Setup(NS_CLIENT,&cls.netchan,adr,-1,&cls,CL_GetFragmentSize);
            NET_ClearLagData(true,false);
            cls.demoframecount = 0;
            cls.lastoutgoingcommand = -1;
            cls.nextcmdtime = (float)realtime;
            DispatchDirectUserMsg("InitHUD",0,(void *)0x0);
          }
          else {
            COM_ExplainDisconnection(true,"Error: Corrupt demo file.");
            FS_Close(cls.demofile);
            cls.demofile = (FileHandle_t)0x0;
            cls.demonum = -1;
            CL_Disconnect();
          }
        }
        else {
          Con_Printf("%s is not a demo file\n",local_110);
          FS_Close(cls.demofile);
          cls.demofile = (FileHandle_t)0x0;
          cls.demonum = -1;
        }
      }
    }
    else {
      Con_Printf("playdemo <demoname> <replayspeed>: plays a demo\n");
      Con_Printf("replayspeed == 1.0 default\n");
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_PlayerDropped  @ 00154010
void CL_PlayerDropped(int nPlayerNumber)

{
  COM_ClearCustomizationList(&cl.players[nPlayerNumber].customdata,true);
  return;
}


// CL_PlayerFlashlight  @ 001346e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PlayerFlashlight(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  dlight_t *veca;
  cl_entity_t *pcVar6;
  uint uVar7;
  vec_t local_68 [3];
  vec_t local_5c [3];
  pmtrace_t local_50;
  
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  pcVar6 = cl_entities;
  iVar1 = cl.playernum + 1;
  uVar7 = cl_entities[iVar1].curstate.effects;
  if (((uVar7 & 0xc) == 0) || (cl.worldmodel == (model_s *)0x0)) {
    if ((cl.pLight != (dlight_t *)0x0) && ((cl.pLight)->key == 1)) {
      (cl.pLight)->die = (float)cl.time;
    }
    cl.pLight = (dlight_t *)0x0;
  }
  else {
    if ((cl.pLight == (dlight_t *)0x0) || (veca = cl.pLight, (cl.pLight)->key != 1)) {
      veca = (*efx.CL_AllocDlight)(1);
      uVar7 = pcVar6[iVar1].curstate.effects;
    }
    if ((uVar7 & 4) == 0) {
                    /* Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: float falloff@[???]
                       Unresolved local var: vec3_t vecForward@[???] */
      AngleVectors(r_playerViewportAngles,local_5c,(vec_t *)0x0,(vec_t *)0x0);
      fVar2 = pcVar6[iVar1].origin[0];
      veca->origin[0] = fVar2;
      fVar3 = pcVar6[iVar1].origin[1];
      veca->origin[1] = fVar3;
      fVar4 = pcVar6[iVar1].origin[2];
      veca->origin[2] = fVar4;
      veca->origin[0] = fVar2 + cl.viewheight[0];
      veca->origin[1] = fVar3 + cl.viewheight[1];
      veca->origin[2] = fVar4 + cl.viewheight[2];
      VectorMA(veca->origin,2000.0,local_5c,local_68);
      pmove->usehull = 2;
      PM_PlayerTrace(&local_50,veca->origin,local_68,2,-1);
      if ((0 < local_50.ent) && (pmove->physents[local_50.ent].studiomodel != (model_s *)0x0)) {
        local_50.endpos[0] = pmove->physents[local_50.ent].origin[0];
        local_50.endpos[1] = pmove->physents[local_50.ent].origin[1];
        local_50.endpos[2] = pmove->physents[local_50.ent].origin[2];
      }
      veca->origin[0] = local_50.endpos[0];
      bVar5 = 0xff;
      veca->origin[1] = local_50.endpos[1];
      veca->origin[2] = local_50.endpos[2];
      if (500.0 <= local_50.fraction * 2000.0) {
        fVar2 = 500.0 / (local_50.fraction * 2000.0);
        bVar5 = (byte)(int)(fVar2 * fVar2 * 255.0);
      }
      veca->radius = 80.0;
      (veca->color).b = bVar5;
      (veca->color).g = bVar5;
      (veca->color).r = bVar5;
    }
    else {
      (veca->color).b = 0xfa;
      (veca->color).g = 0xfa;
      (veca->color).r = 0xfa;
      veca->radius = 400.0;
      veca->origin[0] = pcVar6[iVar1].origin[0];
      veca->origin[1] = pcVar6[iVar1].origin[1];
      veca->origin[2] = pcVar6[iVar1].origin[2] + 16.0;
    }
    cl.pLight = veca;
    veca->die = (float)((longdouble)0.2 + (longdouble)cl.time);
                    /* Unresolved local var: int i@[???] */
    uVar7 = ((int)&veca[-0x4e5b7].decay >> 3) * -0x33333333;
    pcVar6 = cl_entities;
    if (uVar7 < 0x20) {
      r_dlightchanged = r_dlightchanged | 1 << ((byte)uVar7 & 0x1f);
    }
  }
  if ((pcVar6[cl.viewentity].curstate.effects & 2) != 0) {
    cl.viewent.curstate.effects = cl.viewent.curstate.effects | 2;
  }
  return;
}


// CL_PlayerHasCustomization  @ 00156490
customization_t * CL_PlayerHasCustomization(int nPlayerNum,resourcetype_t type)

{
  customization_s *pcVar1;
  
                    /* Unresolved local var: customization_t * pList@[???] */
  pcVar1 = cl.players[nPlayerNum].customdata.pNext;
  if (pcVar1 == (customization_s *)0x0) {
    pcVar1 = (customization_t *)0x0;
  }
  else {
    if (type == (pcVar1->resource).type) {
      return pcVar1;
    }
    do {
      pcVar1 = pcVar1->pNext;
      if (pcVar1 == (customization_s *)0x0) {
        return (customization_t *)0x0;
      }
    } while ((pcVar1->resource).type != type);
  }
  return pcVar1;
}


// CL_PopPMStates  @ 0013b4a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PopPMStates(void)

{
  playermove_t_conflict *ppVar1;
  
  ppVar1 = pmove;
  if (pushed != 0) {
    pushed = pushed + -1;
    pmove->numphysent = oldphysent;
    ppVar1->numvisent = oldvisent;
    return;
  }
  Con_Printf("CL_PopPMStates called without stack\n");
  return;
}


// CL_PrecacheBSPModels  @ 00154ea0
void CL_PrecacheBSPModels(char *pfilename)

{
  resource_s *prVar1;
  int iVar2;
  char *pcVar3;
  model_t *pmVar4;
  resource_s *name;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  if (pfilename != (char *)0x0) {
    iVar2 = Q_strlen("maps/");
    iVar2 = Q_strnicmp(pfilename,"maps/",iVar2);
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
    if (((iVar2 == 0) && (pcVar3 = Q_strstr(pfilename,".bsp"), pcVar3 != (char *)0x0)) &&
       (ContinueLoadingProgressBar("ClientConnect",9,0.0), name = cl.resourcesonhand.pNext,
       cl.resourcesonhand.pNext != &cl.resourcesonhand)) {
      do {
        prVar1 = name->pNext;
        if ((name->type == t_model) && (name->szFileName[0] == '*')) {
          iVar2 = name->nIndex;
          pmVar4 = Mod_ForName(name->szFileName,false,false);
          cl.model_precache[iVar2] = pmVar4;
          if ((cl.model_precache[name->nIndex] == (model_s *)0x0) &&
             (Con_Printf("Model %s not found\n",name), (name->ucFlags & 1) != 0)) {
            COM_ExplainDisconnection(true,"Cannot continue without model %s, disconnecting.",name);
            CL_Disconnect();
            return;
          }
        }
        name = prVar1;
      } while (prVar1 != &cl.resourcesonhand);
    }
  }
  return;
}


// CL_PrecacheResources  @ 00146be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_PrecacheResources(void)

{
  resource_s *prVar1;
  model_s *pmVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  model_t *pmVar6;
  char *pcVar7;
  byte *pbVar8;
  sfx_t *psVar9;
  resource_s *strSource;
  double dVar10;
  
                    /* Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: resource_t * next@[???] */
  SetLoadingProgressBarStatusText("#GameUI_PrecachingResources");
  ContinueLoadingProgressBar("ClientConnect",7,0.0);
  if (fs_startup_timings.value != 0.0) {
    iVar4 = g_iCurrentTiming + 1;
    g_iCurrentTiming = iVar4;
    g_StartupTimings[iVar4].name = "begin CL_PrecacheResources()";
    dVar10 = Sys_FloatTime();
    g_StartupTimings[iVar4].time = (float)dVar10;
  }
  strSource = cl.resourcesonhand.pNext;
  if (cl.resourcesonhand.pNext != &cl.resourcesonhand) {
    do {
      if (strSource == (resource_s *)0x0) break;
      bVar3 = strSource->ucFlags;
      prVar1 = strSource->pNext;
      if ((bVar3 & 0x10) != 0) goto LAB_00146ce5;
      switch(strSource->type) {
      case t_sound:
        if ((bVar3 & 2) != 0) {
          cl.sound_precache[strSource->nIndex] = (sfx_s *)0x0;
          strSource->ucFlags = strSource->ucFlags | 0x10;
          goto LAB_00146ce5;
        }
        S_BeginPrecaching();
        iVar4 = strSource->nIndex;
        psVar9 = S_PrecacheSound(strSource->szFileName);
        cl.sound_precache[iVar4] = psVar9;
        S_EndPrecaching();
        bVar3 = strSource->ucFlags;
        if ((cl.sound_precache[strSource->nIndex] == (sfx_s *)0x0) && ((bVar3 & 1) != 0)) {
          COM_ExplainDisconnection
                    (true,"Cannot continue without sound %s, disconnecting.",strSource);
          CL_Disconnect();
          return false;
        }
        break;
      case t_skin:
      case t_generic:
        break;
      case t_model:
        if ((cl.model_precache_count <= strSource->nIndex) &&
           (cl.model_precache_count = strSource->nIndex + 1, 0x200 < cl.model_precache_count)) {
          cl.model_precache_count = 0x200;
        }
        if (strSource->szFileName[0] != '*') {
          if (fs_lazy_precache.value == 0.0) {
            iVar4 = strSource->nIndex;
LAB_00146c83:
            pmVar6 = Mod_ForName(strSource->szFileName,false,true);
            cl.model_precache[iVar4] = pmVar6;
            pmVar2 = cl.model_precache[strSource->nIndex];
          }
          else {
            iVar5 = Q_strnicmp(strSource->szFileName,"maps",4);
            iVar4 = strSource->nIndex;
            if (iVar5 == 0) goto LAB_00146c83;
            pmVar6 = Mod_FindName(true,strSource->szFileName);
            cl.model_precache[iVar4] = pmVar6;
            pmVar2 = cl.model_precache[strSource->nIndex];
          }
          if (((pmVar2 == (model_s *)0x0) && (strSource->ucFlags != '\0')) &&
             (Con_Printf("Model %s not found and not available from server\n",strSource),
             (strSource->ucFlags & 1) != 0)) {
            COM_ExplainDisconnection
                      (true,"Cannot continue without model %s, disconnecting.",strSource);
            CL_Disconnect();
            return false;
          }
          iVar4 = Q_stricmp(strSource->szFileName,"models/player.mdl");
          if (iVar4 == 0) {
            cl_playerindex = strSource->nIndex;
            bVar3 = strSource->ucFlags;
            break;
          }
        }
        goto LAB_00146e6b;
      case t_decal:
        if ((bVar3 & 4) == 0) {
          Draw_DecalSetName(strSource->nIndex,strSource->szFileName);
          strSource->ucFlags = strSource->ucFlags | 0x10;
          goto LAB_00146ce5;
        }
        break;
      case t_eventscript:
        iVar4 = strSource->nIndex;
        pcVar7 = Mem_Strdup(strSource->szFileName);
        cl.event_precache[iVar4].filename = pcVar7;
        iVar4 = strSource->nIndex;
        pbVar8 = COM_LoadFile(strSource->szFileName,5,(int *)0x0);
        cl.event_precache[iVar4].pszScript = (char *)pbVar8;
        if (cl.event_precache[strSource->nIndex].pszScript != (char *)0x0) goto LAB_00146e6b;
        Con_Printf("Script %s not found and not available from server\n",strSource);
        bVar3 = strSource->ucFlags;
        if ((bVar3 & 1) != 0) {
          COM_ExplainDisconnection
                    (true,"Cannot continue without script %s, disconnecting.",strSource);
          CL_Disconnect();
          return false;
        }
        break;
      default:
        Con_DPrintf("Unknown resource type\n");
LAB_00146e6b:
        strSource->ucFlags = strSource->ucFlags | 0x10;
        goto LAB_00146ce5;
      }
      strSource->ucFlags = bVar3 | 0x10;
LAB_00146ce5:
      strSource = prVar1;
    } while (prVar1 != &cl.resourcesonhand);
  }
  if (fs_startup_timings.value == 0.0) {
    return true;
  }
  iVar4 = g_iCurrentTiming + 1;
  g_StartupTimings[iVar4].name = "end  CL_PrecacheResources()";
  g_iCurrentTiming = iVar4;
  dVar10 = Sys_FloatTime();
  g_StartupTimings[iVar4].time = (float)dVar10;
  return true;
}


// CL_PredictMove  @ 0013b4f0
void CL_PredictMove(qboolean repredicting)

{
  vec_t vVar1;
  vec_t vVar2;
  float fVar3;
  double dVar4;
  usercmd_t *puVar5;
  usercmd_t *u;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  local_state_t *to;
  float fVar14;
  usercmd_t *local_58;
  double *local_50;
  local_state_t *local_4c;
  double local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: cmd_t * fcmd@[???]
                       Unresolved local var: cmd_t * tcmd@[???]
                       Unresolved local var: float targettime@[???]
                       Unresolved local var: frame_t * fromframe@[???]
                       Unresolved local var: local_state_t * from@[???]
                       Unresolved local var: local_state_t * to@[???]
                       Unresolved local var: entity_state_t * ts@[???]
                       Unresolved local var: entity_state_t * fs@[???]
                       Unresolved local var: clientdata_t * fcd@[???]
                       Unresolved local var: clientdata_t * tcd@[???]
                       Unresolved local var: double dTime@[???]
                       Unresolved local var: int stoppoint@[???] */
  if ((cls.state != ca_active) || (cls.spectator != false)) {
    return;
  }
  pmove = &g_clmove;
  CL_SetUpPlayerPrediction(false,false);
  iVar13 = cl.parsecountmod;
  dVar4 = realtime;
  if (cl.intermission != 0) {
    return;
  }
  if (cl.validsequence == 0) {
    return;
  }
  if (CL_UPDATE_MASK <= (cls.netchan.outgoing_sequence + 1) - cls.netchan.incoming_acknowledged) {
    return;
  }
  cl.simangles[0] = cl.viewangles[0];
  cl.simangles[1] = cl.viewangles[1];
  cl.simangles[2] = cl.viewangles[2];
  if (cls.demoplayback != false) {
    cl.simangles[0] = cl.viewangles[0];
    cl.simangles[1] = cl.viewangles[1];
    cl.simangles[2] = cl.viewangles[2];
    return;
  }
  iVar9 = cl.parsecountmod * 0x1930;
  iVar10 = cl.parsecountmod * 0x4318 + 0xc6aa30 + cl.playernum * 0x154;
  uVar6 = 0;
  do {
    *(undefined4 *)(iVar9 + 0xd78324 + uVar6) = *(undefined4 *)(iVar10 + 0xc + uVar6);
    *(undefined4 *)(iVar9 + 0xd78328 + uVar6) = *(undefined4 *)(iVar10 + 0x10 + uVar6);
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x150);
  iVar12 = iVar13 * 0x1930;
  *(undefined4 *)(iVar9 + 0xd78324 + uVar6) = *(undefined4 *)(iVar10 + 0xc + uVar6);
  iVar10 = iVar13 * 0x4318;
  uVar6 = 0;
  do {
    *(undefined4 *)(iVar12 + 0xd78478 + uVar6) = *(undefined4 *)(iVar10 + 0xc6d4c4 + uVar6);
    *(undefined4 *)(iVar12 + 0xd7847c + uVar6) = *(undefined4 *)(iVar10 + 0xc6d4c8 + uVar6);
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x1d8);
  *(undefined4 *)(iVar12 + 0xd78478 + uVar6) = *(undefined4 *)(iVar10 + 0xc6d4c4 + uVar6);
  Q_memcpy(cl.predicted_frames[iVar13].weapondata,cl.frames[iVar13].weapondata,0x1600);
  fVar14 = (float)dVar4;
  if (cl.frames[iVar13].invalid != false) {
    return;
  }
  local_34 = cl.frames[iVar13].time;
  cl.onground = -1;
  local_4c = cl.predicted_frames + cl.parsecountmod;
  local_58 = &cl.commands[cls.netchan.incoming_acknowledged & CL_UPDATE_MASK].cmd;
  CL_PushPMStates();
  CL_SetSolidPlayers(cl.playernum);
  g_i = 1;
  if ((CL_UPDATE_BACKUP < 3) ||
     (uVar6 = cls.netchan.incoming_acknowledged + 1,
     (int)((uint)(repredicting == false) + cls.netchan.outgoing_sequence) <= (int)uVar6)) {
    CL_PopPMStates();
    puVar5 = local_58;
    if (CL_UPDATE_MASK < 2) {
      return;
    }
LAB_0013be4f:
    local_58 = puVar5;
    to = local_4c;
    puVar5 = local_58;
    if (repredicting == false) {
      return;
    }
  }
  else {
    uVar11 = CL_UPDATE_MASK;
    if (repredicting == false) {
      do {
        iVar13 = g_i;
        local_50 = &local_34;
        uVar7 = uVar6 & uVar11;
        u = &cl.commands[uVar7].cmd;
        uVar8 = cl.parsecountmod + g_i & uVar11;
        to = cl.predicted_frames + uVar8;
        CL_RunUsercmd(local_4c,to,u,(uint)(cl.commands[uVar7].processedfuncs == false),local_50,
                      uVar6);
        iVar10 = cls.netchan.incoming_acknowledged;
        uVar11 = CL_UPDATE_MASK;
        cl.commands[uVar7].processedfuncs = true;
        uVar6 = iVar10 + iVar13 & uVar11;
        fVar3 = cl.commands[uVar7].senttime;
        vVar1 = *(vec_t *)&cl.predicted_frames[uVar8].playerstate.field_0x14;
        vVar2 = *(vec_t *)&cl.predicted_frames[uVar8].playerstate.field_0x18;
        cl.predicted_origins[uVar6][0] =
             *(vec_t *)&cl.predicted_frames[uVar8].playerstate.field_0x10;
        cl.predicted_origins[uVar6][1] = vVar1;
        cl.predicted_origins[uVar6][2] = vVar2;
        puVar5 = local_58;
        if ((fVar14 <= fVar3) ||
           (iVar13 = iVar13 + 1, local_4c = to, g_i = iVar13, puVar5 = u,
           CL_UPDATE_BACKUP + -1 <= iVar13)) break;
        uVar6 = iVar10 + iVar13;
        local_58 = u;
      } while ((int)uVar6 < cls.netchan.outgoing_sequence + 1);
    }
    else {
      do {
        iVar13 = g_i;
        uVar7 = uVar11 & uVar6;
        u = &cl.commands[uVar7].cmd;
        uVar8 = cl.parsecountmod + g_i & uVar11;
        to = cl.predicted_frames + uVar8;
        CL_RunUsercmd(local_4c,to,u,false,&local_34,uVar6);
        iVar10 = cls.netchan.incoming_acknowledged;
        cl.commands[uVar7].processedfuncs = true;
        uVar11 = CL_UPDATE_MASK;
        uVar6 = iVar13 + iVar10 & CL_UPDATE_MASK;
        vVar1 = *(vec_t *)&cl.predicted_frames[uVar8].playerstate.field_0x14;
        vVar2 = *(vec_t *)&cl.predicted_frames[uVar8].playerstate.field_0x18;
        fVar3 = cl.commands[uVar7].senttime;
        cl.predicted_origins[uVar6][0] =
             *(vec_t *)&cl.predicted_frames[uVar8].playerstate.field_0x10;
        cl.predicted_origins[uVar6][1] = vVar1;
        cl.predicted_origins[uVar6][2] = vVar2;
        puVar5 = local_58;
        if ((fVar14 <= fVar3) ||
           (iVar13 = iVar13 + 1, local_4c = to, g_i = iVar13, puVar5 = u,
           CL_UPDATE_BACKUP + -1 <= iVar13)) break;
        uVar6 = iVar10 + iVar13;
        local_58 = u;
      } while ((int)uVar6 < (int)((uint)(repredicting == false) + cls.netchan.outgoing_sequence));
    }
    local_58 = u;
    CL_PopPMStates();
    if (CL_UPDATE_MASK <= iVar13) {
      return;
    }
    if (to == (local_state_t *)0x0) goto LAB_0013be4f;
  }
  fVar3 = *(float *)(puVar5 + 1);
  if (*(float *)(local_58 + 1) == fVar3) {
    fVar3 = 0.0;
  }
  else {
    fVar14 = (fVar14 - fVar3) / (*(float *)(local_58 + 1) - fVar3);
    fVar3 = 0.0;
    if (0.0 <= fVar14) {
      fVar3 = fVar14;
    }
  }
  if (((128.0 < ABS(*(float *)&(to->playerstate).field_0x10 -
                    *(float *)&(local_4c->playerstate).field_0x10)) ||
      (128.0 < ABS(*(float *)&(to->playerstate).field_0x14 -
                   *(float *)&(local_4c->playerstate).field_0x14))) ||
     (128.0 < ABS(*(float *)&(to->playerstate).field_0x18 -
                  *(float *)&(local_4c->playerstate).field_0x18))) {
    cl.simvel[0] = (to->client).velocity[0];
    cl.simvel[1] = (to->client).velocity[1];
    cl.simvel[2] = (to->client).velocity[2];
    cl.simorg[0] = *(vec_t *)&(to->playerstate).field_0x10;
    cl.simorg[1] = *(vec_t *)&(to->playerstate).field_0x14;
    cl.simorg[2] = *(vec_t *)&(to->playerstate).field_0x18;
    cl.punchangle[0] = (to->client).punchangle[0];
    cl.punchangle[1] = (to->client).punchangle[1];
    cl.punchangle[2] = (to->client).punchangle[2];
    cl.viewheight[0] = (to->client).view_ofs[0];
    cl.viewheight[1] = (to->client).view_ofs[1];
    cl.viewheight[2] = (to->client).view_ofs[2];
  }
  else {
    iVar13 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      iVar10 = iVar13 + 4;
      *(float *)((int)cl.simorg + iVar13) =
           (*(float *)((to->playerstate).controller + iVar13 + -0x58) -
           *(float *)((local_4c->playerstate).controller + iVar13 + -0x58)) * fVar3 +
           *(float *)((local_4c->playerstate).controller + iVar13 + -0x58);
      iVar13 = iVar10;
    } while (iVar10 != 0xc);
    iVar13 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      iVar10 = iVar13 + 4;
      *(float *)((int)cl.simvel + iVar13) =
           (*(float *)((int)(to->client).velocity + iVar13) -
           *(float *)((int)(local_4c->client).velocity + iVar13)) * fVar3 +
           *(float *)((int)(local_4c->client).velocity + iVar13);
      iVar13 = iVar10;
    } while (iVar10 != 0xc);
    iVar13 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      iVar10 = iVar13 + 4;
      *(float *)((int)cl.punchangle + iVar13) =
           (*(float *)((int)(to->client).punchangle + iVar13) -
           *(float *)((int)(local_4c->client).punchangle + iVar13)) * fVar3 +
           *(float *)((int)(local_4c->client).punchangle + iVar13);
      iVar13 = iVar10;
    } while (iVar10 != 0xc);
    if ((local_4c->playerstate).usehull == (to->playerstate).usehull) {
      iVar13 = 0;
      do {
                    /* Unresolved local var: int i@[???] */
        iVar10 = iVar13 + 4;
        *(float *)((int)cl.viewheight + iVar13) =
             (*(float *)((int)(to->client).view_ofs + iVar13) -
             *(float *)((int)(local_4c->client).view_ofs + iVar13)) * fVar3 +
             *(float *)((int)(local_4c->client).view_ofs + iVar13);
        iVar13 = iVar10;
      } while (iVar10 != 0xc);
    }
    else {
      cl.viewheight[0] = (to->client).view_ofs[0];
      cl.viewheight[1] = (to->client).view_ofs[1];
      cl.viewheight[2] = (to->client).view_ofs[2];
    }
  }
  if (((to->client).flags & 0x200) == 0) {
    cl.onground = -1;
    cl.waterlevel = (to->client).waterlevel;
    cl.usehull = (to->playerstate).usehull;
    cl.stats[2] = (to->client).viewmodel;
    cl.moving = 0;
  }
  else {
    cl.onground = g_lastground;
    cl.waterlevel = (to->client).waterlevel;
    cl.usehull = (to->playerstate).usehull;
    cl.stats[2] = (to->client).viewmodel;
    cl.moving = 0;
    if ((0 < g_lastground) && (g_lastground < cl.num_entities)) {
                    /* Unresolved local var: vec3_t delta@[???] */
      local_28 = cl_entities[g_lastground].curstate.origin[0] -
                 cl_entities[g_lastground].prevstate.origin[0];
      local_24 = cl_entities[g_lastground].curstate.origin[1] -
                 cl_entities[g_lastground].prevstate.origin[1];
      local_20 = 0.0;
      fVar14 = Length(&local_28);
      if (0.0 < fVar14) {
        cl.moving = 1;
      }
      if (cl.moving != 0) {
        cl_correction_time = 0.0;
        goto LAB_0013bb2a;
      }
    }
  }
  if (((0.0 < cl_correction_time) && (cl_nosmooth.value == 0.0)) && (cl_smoothtime.value != 0.0)) {
                    /* Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???] */
    if (repredicting == false) {
      cl_correction_time = cl_correction_time - host_frametime;
    }
    if (cl_smoothtime.value <= 0.0) {
      Cvar_DirectSet(&cl_smoothtime,"0.1");
    }
    fVar14 = 0.0;
    if (0.0 <= (float)cl_correction_time) {
      fVar14 = (float)cl_correction_time;
    }
    if (cl_smoothtime.value <= fVar14) {
      fVar14 = cl_smoothtime.value;
    }
    cl_correction_time = (double)fVar14;
    local_28 = cl.simorg[0] - CL_PredictMove::lastsimorg[0];
    local_24 = cl.simorg[1] - CL_PredictMove::lastsimorg[1];
    local_20 = cl.simorg[2] - CL_PredictMove::lastsimorg[2];
    VectorScale(&local_28,1.0 - fVar14 / cl_smoothtime.value,&local_28);
    cl.simorg[0] = CL_PredictMove::lastsimorg[0] + local_28;
    cl.simorg[1] = CL_PredictMove::lastsimorg[1] + local_24;
    cl.simorg[2] = CL_PredictMove::lastsimorg[2] + local_20;
  }
LAB_0013bb2a:
  CL_PredictMove::lastsimorg[0] = cl.simorg[0];
  CL_PredictMove::lastsimorg[1] = cl.simorg[1];
  CL_PredictMove::lastsimorg[2] = cl.simorg[2];
  CL_SetIdealPitch();
  return;
}


// CL_PrintCachedServer  @ 00144340
void __regparm3 CL_PrintCachedServer(int slot)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
                    /* Unresolved local var: server_cache_t * p@[DW_OP_breg0(EAX): 0; DW_OP_const2u:
                       1096; DW_OP_mul; DW_OP_addr: bc3300; DW_OP_plus; DW_OP_stack_value]
                       Unresolved local var: char * pszDedicated@[???]
                       Unresolved local var: char * pszOS@[???]
                       Unresolved local var: char * pszVisibility@[???]
                       Unresolved local var: char * pszSecure@[???] */
  iVar6 = slot * 0x448;
  if (cached_servers[slot].inuse != 0) {
    Con_Printf("%d ",slot + 1);
    Con_Printf("Name: %s\n",iVar6 + 0xbd332c);
    pcVar2 = NET_AdrToString(cached_servers[slot].adr);
    Con_Printf("Address: %s\n",pcVar2);
    Con_Printf("Map: %s\n",iVar6 + 0xbd352c);
    Con_Printf("Description: %s\n",iVar6 + 0xbd362c);
    Con_Printf("Players: %d/%d   Bots: %d\n",cached_servers[slot].players,
               cached_servers[slot].maxplayers,cached_servers[slot].bots);
    cVar1 = cached_servers[slot].type;
    if (cVar1 == 'd') {
      puVar4 = &LAB_00264c58;
    }
    else if (cVar1 == 'p') {
      puVar4 = &LAB_00264c62;
    }
    else {
      puVar4 = (undefined1 *)0x264c68;
      if (cVar1 != 'l') {
        puVar4 = (undefined1 *)0x2628f5;
      }
    }
    if (cached_servers[slot].os == 'w') {
      uVar5 = 0x264c6f;
    }
    else {
      uVar5 = 0x264c77;
      if (cached_servers[slot].os != 'l') {
        uVar5 = 0x264c7d;
      }
    }
    uVar3 = 0x264c8b;
    if (cached_servers[slot].is_private != false) {
      uVar3 = 0x264c83;
    }
    uVar7 = 0x264c92;
    if (cached_servers[slot].is_vac == false) {
      uVar7 = 0x264c99;
    }
    Con_Printf("%s - %s - %s - %s\n",puVar4,uVar5,uVar3,uVar7);
    if (cached_servers[slot].has_spectator_address != 0) {
      pcVar2 = NET_AdrToString(cached_servers[slot].spec_adr);
      Con_Printf("Spectator Address: %s\n",pcVar2);
    }
  }
  return;
}


// CL_PrintCachedServer  @ 00144eb0
void CL_PrintCachedServer(int slot)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
                    /* Unresolved local var: server_cache_t * p@[???]
                       Unresolved local var: char * pszDedicated@[???]
                       Unresolved local var: char * pszOS@[???]
                       Unresolved local var: char * pszVisibility@[???]
                       Unresolved local var: char * pszSecure@[???] */
                    /* Unresolved local var: server_cache_t * p@[???]
                       Unresolved local var: char * pszDedicated@[???]
                       Unresolved local var: char * pszOS@[???]
                       Unresolved local var: char * pszVisibility@[???]
                       Unresolved local var: char * pszSecure@[???] */
  if (((uint)slot < 0x10) && (iVar6 = slot * 0x448, cached_servers[slot].inuse != 0)) {
    Con_Printf("%d ",slot + 1);
    Con_Printf("Name: %s\n",iVar6 + 0xbd332c);
    pcVar2 = NET_AdrToString(cached_servers[slot].adr);
    Con_Printf("Address: %s\n",pcVar2);
    Con_Printf("Map: %s\n",iVar6 + 0xbd352c);
    Con_Printf("Description: %s\n",iVar6 + 0xbd362c);
    Con_Printf("Players: %d/%d   Bots: %d\n",cached_servers[slot].players,
               cached_servers[slot].maxplayers,cached_servers[slot].bots);
    cVar1 = cached_servers[slot].type;
    if (cVar1 == 'd') {
      puVar4 = &LAB_00264c58;
    }
    else if (cVar1 == 'p') {
      puVar4 = &LAB_00264c62;
    }
    else {
      puVar4 = (undefined1 *)0x264c68;
      if (cVar1 != 'l') {
        puVar4 = (undefined1 *)0x2628f5;
      }
    }
    if (cached_servers[slot].os == 'w') {
      uVar5 = 0x264c6f;
    }
    else {
      uVar5 = 0x264c77;
      if (cached_servers[slot].os != 'l') {
        uVar5 = 0x264c7d;
      }
    }
    uVar3 = 0x264c8b;
    if (cached_servers[slot].is_private != false) {
      uVar3 = 0x264c83;
    }
    uVar7 = 0x264c92;
    if (cached_servers[slot].is_vac == false) {
      uVar7 = 0x264c99;
    }
    Con_Printf("%s - %s - %s - %s\n",puVar4,uVar5,uVar3,uVar7);
    if (cached_servers[slot].has_spectator_address != 0) {
      pcVar2 = NET_AdrToString(cached_servers[slot].spec_adr);
      Con_Printf("Spectator Address: %s\n",pcVar2);
    }
  }
  return;
}


// CL_PrintEntities_f  @ 00143790
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PrintEntities_f(void)

{
  cl_entity_t *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: cl_entity_t * ent@[???]
                       Unresolved local var: int i@[???] */
  if (0 < cl.num_entities) {
    iVar2 = 0;
    pcVar1 = cl_entities;
    do {
      Con_Printf("%3i:",iVar2);
      if (pcVar1->model != (model_s *)0x0) {
        Con_Printf("%s:%2i  (%5.1f,%5.1f,%5.1f) [%5.1f %5.1f %5.1f]\n",pcVar1->model,
                   (double)(pcVar1->curstate).frame,(double)pcVar1->origin[0],
                   (double)pcVar1->origin[1],(double)pcVar1->origin[2],(double)pcVar1->angles[0],
                   (double)pcVar1->angles[1],(double)pcVar1->angles[2]);
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 < cl.num_entities);
  }
  return;
}


// CL_PrintEntity  @ 00134610
void CL_PrintEntity(cl_entity_t_conflict2 *ent)

{
  return;
}


// CL_ProcessEntityUpdate  @ 00132560
void CL_ProcessEntityUpdate(cl_entity_t_conflict2 *ent)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  model_t *pmVar11;
  
                    /* Unresolved local var: int i@[???] */
  ent->index = (ent->curstate).number;
  pmVar11 = CL_GetModelByIndex((ent->curstate).modelindex);
  ent->model = (model_s_conflict1 *)pmVar11;
  COM_NormalizeAngles((vec_t *)&(ent->curstate).field_0x1c);
  if (((ent->model == (model_s_conflict1 *)0x0) || (ent->model->name[0] != '*')) &&
     ((iVar6 = (ent->curstate).movetype, iVar6 - 3U < 3 ||
      (((iVar6 == 0 || ((ent->curstate).starttime != 0.0)) || ((ent->curstate).impacttime != 0.0))))
     )) {
    fVar5 = (ent->curstate).animtime;
  }
  else {
    fVar5 = (ent->curstate).msg_time;
    (ent->curstate).animtime = fVar5;
  }
                    /* Unresolved local var: int iTime1@[???]
                       Unresolved local var: int iTime2@[???] */
  if ((2 < ((int)(fVar5 * 1000.0) - (int)((ent->prevstate).animtime * 1000.0)) + 1U) ||
     ((ent->curstate).movetype == 0)) {
    R_UpdateLatchedVars((cl_entity_t *)ent);
    CL_UpdatePositions((cl_entity_t *)ent);
  }
  if (ent->player != 0) {
    *(float *)&(ent->curstate).field_0x1c = *(float *)&(ent->curstate).field_0x1c / -3.0;
  }
  uVar1 = *(undefined4 *)&(ent->curstate).field_0x14;
  *(undefined4 *)&ent->field_0xb48 = *(undefined4 *)&(ent->curstate).field_0x10;
  uVar2 = *(undefined4 *)&(ent->curstate).field_0x18;
  *(undefined4 *)&ent->field_0xb4c = uVar1;
  *(undefined4 *)&ent->field_0xb50 = uVar2;
  CL_ParametricMove(ent);
  uVar1 = *(undefined4 *)&(ent->curstate).field_0x10;
  uVar2 = *(undefined4 *)&(ent->curstate).field_0x14;
  uVar9 = *(undefined4 *)&(ent->curstate).field_0x10;
  uVar10 = *(undefined4 *)&(ent->curstate).field_0x14;
  uVar7 = *(undefined4 *)&(ent->curstate).field_0x10;
  uVar8 = *(undefined4 *)&(ent->curstate).field_0x14;
  *(undefined4 *)&ent->field_0xb58 = *(undefined4 *)&(ent->curstate).field_0x20;
  uVar3 = *(undefined4 *)&(ent->curstate).field_0x18;
  uVar4 = *(undefined4 *)&(ent->curstate).field_0x24;
  *(undefined4 *)&ent->field_0xb54 = *(undefined4 *)&(ent->curstate).field_0x1c;
  *(undefined4 *)((int)(ent->attachment + 0) + 0) = uVar7;
  *(undefined4 *)((int)(ent->attachment + 0) + 4) = uVar8;
  *(ulonglong *)(ent->attachment[0] + 2) = CONCAT44(uVar1,uVar3);
  *(undefined4 *)&ent->field_0xb5c = uVar4;
  *(ulonglong *)(ent->attachment[1] + 1) = CONCAT44(uVar3,uVar2);
  *(undefined4 *)((int)(ent->attachment + 2) + 0) = uVar9;
  *(undefined4 *)((int)(ent->attachment + 2) + 4) = uVar10;
  *(ulonglong *)(ent->attachment[2] + 2) = CONCAT44(uVar1,uVar3);
  *(ulonglong *)(ent->attachment[3] + 1) = CONCAT44(uVar3,uVar2);
  return;
}


// CL_ProcessFile  @ 00146fd0
void CL_ProcessFile(qboolean successfully_received,char *filename)

{
  char cVar1;
  resource_s *prVar2;
  int iVar3;
  uint playernumber;
  char *pcVar4;
  qboolean qVar5;
  customization_s *pcVar6;
  resource_s *pResource;
  int in_GS_OFFSET;
  sizebuf_t local_5044;
  uchar local_5030 [16];
  byte local_5020 [20480];
  int local_20;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???]
                       Unresolved local var: char * pfilename@[???]
                       Unresolved local var: uchar[16] rgucMD5_hash@[???]
                       Unresolved local var: char[20] szModuleC@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((successfully_received == false) || (filename == (char *)0x0)) {
    if (successfully_received == false) {
                    /* Unresolved local var: char * pfilename@[???] */
      if (filename == (char *)0x0) {
        pcVar4 = (char *)0x0;
      }
      else {
        pcVar4 = "customization";
        if (*filename != '!') {
          pcVar4 = filename;
        }
      }
      Con_Printf("Error: server failed to transmit file \'%s\'\n",pcVar4);
    }
  }
  else if (*filename != '!') {
    Con_Printf("Processing %s\n",filename);
  }
  iVar3 = Q_strlen("sound/");
  iVar3 = Q_strnicmp(filename,"sound/",iVar3);
  pcVar4 = filename;
  if (iVar3 == 0) {
    iVar3 = Q_strlen("sound/");
    pcVar4 = filename + iVar3;
  }
  if (cl.resourcesneeded.pNext != &cl.resourcesneeded) {
    pResource = cl.resourcesneeded.pNext;
    do {
      while( true ) {
        prVar2 = pResource->pNext;
        iVar3 = Q_strnicmp(filename,"!MD5",4);
        if (iVar3 != 0) break;
        COM_HexConvert(pcVar4 + 4,0x20,local_5030);
        iVar3 = Q_memcmp(pResource->rgucMD5_hash,local_5030,0x10);
        if (iVar3 == 0) {
LAB_001470ed:
          if (successfully_received == false) {
            cVar1 = *filename;
          }
          else {
            pResource->ucFlags = pResource->ucFlags & 0xfd;
            cVar1 = *filename;
          }
          if (cVar1 != '!') goto LAB_00147105;
          if (cls.netchan.tempbuffer == (void *)0x0) goto LAB_00147116;
          if (pResource->nDownloadSize != cls.netchan.tempbuffersize) {
            Con_Printf("CL_ProcessFile:  Downloaded %i bytes for purported %i byte file, ignoring download\n"
                       ,cls.netchan.tempbuffersize,pResource->nDownloadSize);
            goto LAB_00147105;
          }
          if ((pResource->ucFlags & 4) == 0) goto LAB_0014710e;
          HPAK_AddLump(true,"custom.hpk",pResource,cls.netchan.tempbuffer,(FileHandle_t)0x0);
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
          playernumber = (uint)pResource->playernum;
          pcVar6 = cl.players[playernumber].customdata.pNext;
          if (pcVar6 == (customization_s *)0x0) goto LAB_001473c7;
          goto LAB_001472e6;
        }
LAB_0014709e:
        pResource = prVar2;
        if (prVar2 == &cl.resourcesneeded) goto LAB_00147147;
      }
      if (pResource->type != t_generic) {
        iVar3 = Q_stricmp(pResource->szFileName,pcVar4);
        if (iVar3 != 0) goto LAB_0014709e;
        goto LAB_001470ed;
      }
      iVar3 = Q_stricmp(pResource->szFileName,filename);
      if (iVar3 == 0) goto LAB_001470ed;
      pResource = prVar2;
    } while (prVar2 != &cl.resourcesneeded);
    goto LAB_00147147;
  }
  if (cls.state == ca_disconnected) goto LAB_00147197;
LAB_00147345:
                    /* Unresolved local var: uchar[20480] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  Q_memset(&local_5044,0,0x14);
  local_5044.buffername = "Resource Registration";
  local_5044.data = local_5020;
  local_5044.cursize = 0;
  local_5044.maxsize = 0x5000;
  qVar5 = CL_PrecacheResources();
  if (qVar5 != false) {
    CL_RegisterResources(&local_5044);
  }
  if (0 < local_5044.cursize) {
    Netchan_CreateFragments(false,&cls.netchan,&local_5044);
    Netchan_FragSend(&cls.netchan);
  }
  goto LAB_00147160;
  while (pcVar6 = pcVar6->pNext, pcVar6 != (customization_s *)0x0) {
LAB_001472e6:
    iVar3 = Q_memcmp((pcVar6->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10);
    if (iVar3 == 0) {
      Con_DPrintf("Duplicate resource received and ignored.\n");
      goto LAB_00147105;
    }
  }
  playernumber = (uint)pResource->playernum;
LAB_001473c7:
  qVar5 = COM_CreateCustomization
                    (&cl.players[playernumber].customdata,pResource,playernumber,1,
                     (customization_t **)0x0,(int *)0x0);
  if (qVar5 == false) {
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
    Con_Printf("Unable to create custom decal for player %i\n",(uint)pResource->playernum);
  }
LAB_00147105:
  if (cls.netchan.tempbuffer != (void *)0x0) {
LAB_0014710e:
    Mem_Free(cls.netchan.tempbuffer);
  }
LAB_00147116:
  cls.netchan.tempbuffer = (void *)0x0;
  cls.netchan.tempbuffersize = 0;
  if (pResource == (resource_t *)0x0) {
    Con_DPrintf("Null resource passed to CL_MoveToOnHandList\n");
  }
  else {
    CL_RemoveFromResourceList(pResource);
    CL_AddToResourceList(pResource,&cl.resourcesonhand);
  }
LAB_00147147:
  if (cls.state == ca_disconnected) goto LAB_00147197;
  if (cl.resourcesneeded.pNext == &cl.resourcesneeded) goto LAB_00147345;
LAB_00147160:
  if (cls.netchan.tempbuffer != (void *)0x0) {
    Con_Printf("CL_ProcessFile: Received a decal %s, but didn\'t find it in resources needed list!\n"
               ,pcVar4);
    Mem_Free(cls.netchan.tempbuffer);
  }
  cls.netchan.tempbuffer = (void *)0x0;
  cls.netchan.tempbuffersize = 0;
LAB_00147197:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ProcessPacket  @ 001331b0
void CL_ProcessPacket(frame_t *frame)

{
  vec_t vVar1;
  vec_t vVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  int iVar8;
  undefined4 uVar9;
  qboolean qVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  model_t *pmVar15;
  entity_state_s *state;
  cl_entity_t *pcVar16;
  int iVar17;
  int local_30;
  
                    /* Unresolved local var: packet_entities_t * pPacket@[???]
                       Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: int pnum@[???] */
  local_30 = 0;
  if (0 < (frame->packet_entities).num_entities) {
    iVar17 = 0;
    do {
      pcVar16 = cl_entities;
      state = (entity_state_s *)
              ((int)((frame->packet_entities).entities)->origin + local_30 + -0x10);
      state->messagenum = cl.parsecount;
      state->msg_time = (float)cl.mtime[0];
      iVar8 = state->number;
      pcVar16 = pcVar16 + iVar8;
      if (iVar8 < 1) {
        pcVar16->player = false;
        if (state->number + -1 == cl.playernum) goto LAB_001334e5;
      }
      else {
        pcVar16->player = (uint)(iVar8 <= cl.maxclients);
        if (state->number + -1 == cl.playernum) {
LAB_001334e5:
          ClientDLL_TxferLocalOverrides(state,&frame->clientdata);
        }
      }
      uVar13 = 0;
      do {
        uVar14 = uVar13;
        *(undefined4 *)((int)(pcVar16->prevstate).origin + (uVar14 - 0x10)) =
             *(undefined4 *)((int)(pcVar16->curstate).origin + (uVar14 - 0x10));
        *(undefined4 *)((int)(pcVar16->prevstate).origin + (uVar14 - 0xc)) =
             *(undefined4 *)((int)(pcVar16->curstate).origin + (uVar14 - 0xc));
        uVar13 = uVar14 + 8;
      } while (uVar14 + 8 < 0x150);
      *(undefined4 *)((int)(pcVar16->prevstate).origin + (uVar14 - 8)) =
           *(undefined4 *)((int)(pcVar16->curstate).origin + (uVar14 - 8));
      uVar13 = 0;
      do {
        uVar14 = uVar13;
        uVar9 = *(undefined4 *)((int)state->origin + (uVar14 - 0x10));
        *(undefined4 *)((int)(pcVar16->curstate).origin + (uVar14 - 0xc)) =
             *(undefined4 *)((int)state->origin + (uVar14 - 0xc));
        *(undefined4 *)((int)(pcVar16->curstate).origin + (uVar14 - 0x10)) = uVar9;
        uVar13 = uVar14 + 8;
      } while (uVar14 + 8 < 0x150);
      *(undefined4 *)((int)(pcVar16->curstate).origin + (uVar14 - 8)) =
           *(undefined4 *)((int)state->origin + (uVar14 - 8));
                    /* Unresolved local var: int i@[???] */
      pcVar16->index = (pcVar16->curstate).number;
      pmVar15 = CL_GetModelByIndex((pcVar16->curstate).modelindex);
      pcVar16->model = pmVar15;
      COM_NormalizeAngles((pcVar16->curstate).angles);
      if (((pcVar16->model == (model_s *)0x0) || (pcVar16->model->name[0] != '*')) &&
         ((iVar8 = (pcVar16->curstate).movetype, iVar8 - 3U < 3 ||
          (((iVar8 == 0 || ((pcVar16->curstate).starttime != 0.0)) ||
           ((pcVar16->curstate).impacttime != 0.0)))))) {
        fVar3 = (pcVar16->curstate).animtime;
      }
      else {
        fVar3 = (pcVar16->curstate).msg_time;
        (pcVar16->curstate).animtime = fVar3;
      }
                    /* Unresolved local var: int iTime1@[???]
                       Unresolved local var: int iTime2@[???] */
      if ((2 < ((int)(fVar3 * 1000.0) - (int)((pcVar16->prevstate).animtime * 1000.0)) + 1U) ||
         ((pcVar16->curstate).movetype == 0)) {
        R_UpdateLatchedVars(pcVar16);
        CL_UpdatePositions(pcVar16);
      }
      if (pcVar16->player != false) {
        (pcVar16->curstate).angles[0] = (pcVar16->curstate).angles[0] / -3.0;
      }
      vVar1 = (pcVar16->curstate).origin[1];
      vVar2 = (pcVar16->curstate).origin[2];
      pcVar16->origin[0] = (pcVar16->curstate).origin[0];
      pcVar16->origin[1] = vVar1;
      pcVar16->origin[2] = vVar2;
      CL_ParametricMove((cl_entity_t_conflict2 *)pcVar16);
                    /* Unresolved local var: int bytenum@[???]
                       Unresolved local var: int bitnum@[???] */
      vVar1 = (pcVar16->curstate).angles[0];
      pcVar16->angles[0] = vVar1;
      vVar2 = (pcVar16->curstate).angles[1];
      pcVar16->angles[1] = vVar2;
      vVar4 = (pcVar16->curstate).angles[2];
      pcVar16->angles[2] = vVar4;
      vVar5 = (pcVar16->curstate).origin[0];
      pcVar16->attachment[0][0] = vVar5;
      vVar6 = (pcVar16->curstate).origin[1];
      pcVar16->attachment[0][1] = vVar6;
      vVar7 = (pcVar16->curstate).origin[2];
      pcVar16->attachment[0][2] = vVar7;
      pcVar16->attachment[1][0] = vVar5;
      pcVar16->attachment[1][1] = vVar6;
      pcVar16->attachment[1][2] = vVar7;
      pcVar16->attachment[2][0] = vVar5;
      pcVar16->attachment[2][1] = vVar6;
      pcVar16->attachment[2][2] = vVar7;
      pcVar16->attachment[3][0] = vVar5;
      pcVar16->attachment[3][1] = vVar6;
      pcVar16->attachment[3][2] = vVar7;
      if ((1 << ((byte)iVar17 & 7) & (uint)(frame->packet_entities).flags[iVar17 >> 3]) == 0) {
LAB_0013349e:
        qVar10 = pcVar16->player;
      }
      else {
        (pcVar16->latched).prevorigin[0] = vVar5;
        (pcVar16->latched).prevorigin[1] = vVar6;
        (pcVar16->latched).prevorigin[2] = vVar7;
        (pcVar16->latched).prevangles[0] = vVar1;
        (pcVar16->latched).prevangles[1] = vVar2;
        (pcVar16->latched).prevangles[2] = vVar4;
        R_ResetLatched(pcVar16,true);
        CL_ResetPositions(pcVar16);
                    /* Unresolved local var: int bytenum@[???]
                       Unresolved local var: int bitnum@[???] */
        if (((pcVar16->curstate).starttime == 0.0) || ((pcVar16->curstate).impacttime == 0.0))
        goto LAB_0013349e;
        pcVar16->lastmove = (float)cl.time;
        qVar10 = pcVar16->player;
      }
      if (qVar10 != false) {
                    /* Unresolved local var: int playerindex@[???] */
        iVar11 = state->number;
                    /* Unresolved local var: entity_state_t.conflict * ps@[???] */
        fVar3 = (float)cl.mtime[0];
        iVar8 = cl.parsecountmod * 0x4318 + iVar11 * 0x154 + -0x154;
        *(int *)((int)cl.predicted_origins + iVar8 + 0x394) = iVar11;
        iVar12 = cl.parsecount;
        *(float *)((int)cl.predicted_origins + iVar8 + 0x398) = fVar3;
        *(int *)((int)cl.predicted_origins + iVar8 + 0x39c) = iVar12;
        ClientDLL_ProcessPlayerState
                  ((entity_state_s *)((int)cl.predicted_origins + iVar8 + 0x390),state);
        if (iVar11 + -1 == cl.playernum) {
          CL_CheckPredictionError();
        }
      }
      iVar17 = iVar17 + 1;
      local_30 = local_30 + 0x154;
    } while (iVar17 < (frame->packet_entities).num_entities);
  }
  return;
}


// CL_ProcessPlayerState  @ 00133150
void CL_ProcessPlayerState(int playerindex,entity_state_t_conflict *state)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: entity_state_t.conflict * ps@[???] */
  iVar3 = cl.parsecountmod;
  fVar1 = (float)cl.mtime[0];
  cl.frames[cl.parsecountmod].playerstate[playerindex].number = state->number;
  iVar2 = cl.parsecount;
  cl.frames[iVar3].playerstate[playerindex].msg_time = fVar1;
  cl.frames[iVar3].playerstate[playerindex].messagenum = iVar2;
  ClientDLL_ProcessPlayerState(cl.frames[iVar3].playerstate + playerindex,(entity_state_s *)state);
  return;
}


// CL_PureOrigin  @ 0013cc40
void CL_PureOrigin(cl_entity_t *ent,float t,vec_t *outorigin,vec_t *outangles)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float local_40;
  float local_3c;
  float local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t0@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???] */
                    /* Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: int i0@[???]
                       Unresolved local var: int i1@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float at@[???]
                       Unresolved local var: int imod@[???] */
  uVar3 = ent->current_position;
  uVar6 = uVar3 & 0x3f;
  uVar4 = uVar3 - 1;
  uVar5 = uVar4 & 0x3f;
  if (t <= ent->ph[uVar6].animtime) {
    do {
      fVar1 = ent->ph[uVar4 & 0x3f].animtime;
      if (fVar1 == 0.0) break;
      if (fVar1 < t) {
        uVar6 = uVar4 + 1 & 0x3f;
        uVar5 = uVar4 & 0x3f;
        break;
      }
      uVar4 = uVar4 - 1;
    } while (uVar3 - 0x3f != uVar4);
  }
  if ((ent->ph + uVar6 != (position_history_t *)0x0) &&
     (ent->ph + uVar5 != (position_history_t *)0x0)) {
    fVar1 = ent->ph[uVar6].animtime;
    if (fVar1 == 0.0) {
      *outorigin = ent->ph[uVar5].origin[0];
      outorigin[1] = ent->ph[uVar5].origin[1];
      outorigin[2] = ent->ph[uVar5].origin[2];
      *outangles = ent->ph[uVar5].angles[0];
      outangles[1] = ent->ph[uVar5].angles[1];
      outangles[2] = ent->ph[uVar5].angles[2];
      return;
    }
    fVar2 = ent->ph[uVar5].animtime;
    local_40 = ent->ph[uVar6].origin[0] - ent->ph[uVar5].origin[0];
    local_3c = ent->ph[uVar6].origin[1] - ent->ph[uVar5].origin[1];
    local_38 = ent->ph[uVar6].origin[2] - ent->ph[uVar5].origin[2];
    if (fVar2 == fVar1) {
      fVar1 = 1.0;
    }
    else {
      fVar1 = (t - fVar2) / (fVar1 - fVar2);
      if (fVar1 < 0.0) {
        fVar1 = 0.0;
      }
      else if (1.2 < fVar1) {
        fVar1 = 1.2;
      }
    }
    VectorMA(ent->ph[uVar5].origin,fVar1,&local_40,&local_34);
    InterpolateAngles(ent->ph[uVar5].angles,ent->ph[uVar6].angles,&local_28,fVar1);
    *outorigin = local_34;
    outorigin[1] = local_30;
    outorigin[2] = local_2c;
    *outangles = local_28;
    outangles[1] = local_24;
    outangles[2] = local_20;
  }
  return;
}


// CL_PushPMStates  @ 0013b450
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PushPMStates(void)

{
  if (pushed == 0) {
    oldphysent = pmove->numphysent;
    oldvisent = pmove->numvisent;
    pushed = 1;
    return;
  }
  Con_Printf("CL_PushPMStates called with pushed stack\n");
  return;
}


// CL_QueueEvent  @ 001391a0
void CL_QueueEvent(int flags,int index,float delay,event_args_t *pargs)

{
  float fVar1;
  int iVar2;
  event_info_s *peVar3;
  event_state_t *peVar4;
  uint uVar5;
  event_state_t *peVar6;
  
                    /* Unresolved local var: event_info_t * ei@[???] */
  peVar6 = &cl.events;
  peVar4 = &cl.events;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  iVar2 = 0;
  do {
    if (peVar4->ei[0].index == 0) {
      peVar3 = cl.events.ei + iVar2;
      if (peVar3 != (event_info_s *)0x0) goto LAB_00139201;
      break;
    }
    iVar2 = iVar2 + 1;
    peVar4 = (event_state_t *)(peVar4->ei + 1);
  } while (iVar2 != 0x40);
  if ((flags & 2U) != 0) {
    iVar2 = 0;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
      if ((peVar6->ei[0].index == 0) || ((peVar6->ei[0].flags & 2) == 0)) {
        peVar3 = cl.events.ei + iVar2;
        if (peVar3 == (event_info_s *)0x0) {
          return;
        }
LAB_00139201:
        peVar3->packet_index = 0;
        peVar3->index = (ushort)index;
        uVar5 = 0;
        do {
          *(undefined4 *)((int)(peVar3->args).origin + (uVar5 - 8)) =
               *(undefined4 *)((int)pargs->origin + (uVar5 - 8));
          uVar5 = uVar5 + 4;
        } while (uVar5 < 0x48);
        fVar1 = 0.0;
        if (delay != 0.0) {
          fVar1 = delay + (float)cl.time;
        }
        peVar3->fire_time = fVar1;
        peVar3->flags = flags;
        return;
      }
      iVar2 = iVar2 + 1;
      peVar6 = (event_state_t *)(peVar6->ei + 1);
    } while (iVar2 != 0x40);
  }
  return;
}


// CL_QueueHTTPDownload  @ 00127840
void CL_QueueHTTPDownload(char *filename)

{
  netadr_t a;
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  RequestContext *pRVar6;
  bool bVar7;
  byte bVar8;
  RequestContext *local_10 [2];
  
  bVar8 = 0;
                    /* Unresolved local var: RequestContext * rc@[???] */
  bVar7 = false;
  iVar2 = 6;
  pcVar1 = "local";
  pcVar5 = cls.servername;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar7 = *pcVar1 == *pcVar5;
    pcVar1 = pcVar1 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar7);
  if (!bVar7) {
                    /* Unresolved local var: RequestContext * rc@[???] */
    TheDownloadManager.m_totalRequests = TheDownloadManager.m_totalRequests + 1;
    local_10[0] = operator_new(0xc0c);
    CUtlVector<RequestContext*>::InsertBefore
              (&TheDownloadManager.m_queuedRequests,TheDownloadManager.m_queuedRequests.m_Size,
               local_10);
    uVar4 = 0xc0c;
    bVar7 = ((uint)local_10[0] & 1) != 0;
    pRVar6 = local_10[0];
    if (bVar7) {
      *(undefined1 *)&local_10[0]->status = HTTP_CONNECTING;
      uVar4 = 0xc0b;
      pRVar6 = (RequestContext *)((int)&local_10[0]->status + 1);
    }
    if (((uint)pRVar6 & 2) != 0) {
      *(undefined2 *)&pRVar6->status = HTTP_CONNECTING;
      uVar4 = uVar4 - 2;
      pRVar6 = (RequestContext *)((int)&pRVar6->status + 2);
    }
    if (((uint)pRVar6 & 4) != 0) {
      pRVar6->status = HTTP_CONNECTING;
      uVar4 = uVar4 - 4;
      pRVar6 = (RequestContext *)&pRVar6->error;
    }
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pRVar6->status = HTTP_CONNECTING;
      pRVar6 = (RequestContext *)((int)pRVar6 + (uint)bVar8 * -8 + 4);
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)&pRVar6->status = HTTP_CONNECTING;
      pRVar6 = (RequestContext *)((int)&pRVar6->status + 2);
    }
    if (bVar7) {
      *(undefined1 *)&pRVar6->status = HTTP_CONNECTING;
    }
    local_10[0]->status = HTTP_CONNECTING;
    snprintf(local_10[0]->baseURL,0x400,"%s",0xdf0868);
    snprintf(local_10[0]->gamePath,0x400,"%s",filename);
    a.ip[0] = cls.netchan.remote_address.ip[0];
    a.ip[1] = cls.netchan.remote_address.ip[1];
    a.ip[2] = cls.netchan.remote_address.ip[2];
    a.ip[3] = cls.netchan.remote_address.ip[3];
    a.type = cls.netchan.remote_address.type;
    a.ipx[0] = cls.netchan.remote_address.ipx[0];
    a.ipx[1] = cls.netchan.remote_address.ipx[1];
    a.ipx[2] = cls.netchan.remote_address.ipx[2];
    a.ipx[3] = cls.netchan.remote_address.ipx[3];
    a.ipx[4] = cls.netchan.remote_address.ipx[4];
    a.ipx[5] = cls.netchan.remote_address.ipx[5];
    a.ipx[6] = cls.netchan.remote_address.ipx[6];
    a.ipx[7] = cls.netchan.remote_address.ipx[7];
    a.ipx[8] = cls.netchan.remote_address.ipx[8];
    a.ipx[9] = cls.netchan.remote_address.ipx[9];
    a.port = cls.netchan.remote_address.port;
    pcVar1 = NET_AdrToString(a);
    snprintf(local_10[0]->serverURL,0x400,"%s",pcVar1);
    return;
  }
  return;
}


// CL_Rate_f  @ 0014ad20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Rate_f(void)

{
  int iVar1;
  char *str;
  float fVar2;
  
                    /* Unresolved local var: float fNewRate@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("Usage:  cl_rate <num>\nClient to server transmission rate (bytes/sec)\nCurrent:  %.5f\n"
               ,cls.netchan.rate);
    return;
  }
  str = Cmd_Argv(1);
  fVar2 = Q_atof(str);
  if (fVar2 == 0.0) {
    fVar2 = 30000.0;
  }
  else if ((fVar2 < 1000.0) || (100000.0 < fVar2)) {
    Con_Printf("cl_rate:  Maximum %f, Minimum %f\n","vparser7ClusterD2Ev",1000);
    return;
  }
  cls.netchan.rate = (double)fVar2;
  return;
}


// CL_Rcon_f  @ 00143950
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Rcon_f(void)

{
  netadr_t adr;
  short sVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  qboolean qVar5;
  int in_GS_OFFSET;
  netadr_t local_24;
  int local_10;
  
                    /* Unresolved local var: netadr_t to@[???]
                       Unresolved local var: ushort port@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (rcon_password.string == (char *)0x0) {
    Con_Printf("You must set \'rcon_password\' before\nissuing an rcon command.\n");
    goto LAB_00143a86;
  }
  pcVar3 = Cmd_Args();
  if (pcVar3 == (char *)0x0) {
    Con_Printf("Rcon:  Empty rcon string\n");
    goto LAB_00143a86;
  }
  if (cls.state < ca_connected) {
    NET_Config(true);
    iVar4 = Q_strlen(rcon_address.string);
    if (iVar4 == 0) {
      Con_Printf(
                "You must either be connected,\nor set the \'rcon_address\' cvar\nto issue rcon commands\n"
                );
      goto LAB_00143a86;
    }
LAB_00143ad0:
    qVar5 = NET_StringToAdr(rcon_address.string,&local_24);
    if (qVar5 == false) {
      Con_Printf("Unable to resolve rcon address %s\n",rcon_address.string);
      goto LAB_00143a86;
    }
  }
  else {
    iVar4 = Q_strlen(rcon_address.string);
    if (iVar4 != 0) goto LAB_00143ad0;
    local_24.type = cls.netchan.remote_address.type;
    local_24.ip[0] = cls.netchan.remote_address.ip[0];
    local_24.ip[1] = cls.netchan.remote_address.ip[1];
    local_24.ip[2] = cls.netchan.remote_address.ip[2];
    local_24.ip[3] = cls.netchan.remote_address.ip[3];
    local_24.ipx[0] = cls.netchan.remote_address.ipx[0];
    local_24.ipx[1] = cls.netchan.remote_address.ipx[1];
    local_24.ipx[2] = cls.netchan.remote_address.ipx[2];
    local_24.ipx[3] = cls.netchan.remote_address.ipx[3];
    local_24.ipx[4] = cls.netchan.remote_address.ipx[4];
    local_24.ipx[5] = cls.netchan.remote_address.ipx[5];
    local_24.ipx[6] = cls.netchan.remote_address.ipx[6];
    local_24.ipx[7] = cls.netchan.remote_address.ipx[7];
    local_24.ipx[8] = cls.netchan.remote_address.ipx[8];
    local_24.ipx[9] = cls.netchan.remote_address.ipx[9];
    local_24.port = cls.netchan.remote_address.port;
  }
  sVar1 = (short)(int)rcon_port.value;
  if (((int)rcon_port.value & 0xffffU) == 0) {
    if (cls.state < ca_connected) {
      iVar4 = Q_atoi("27015");
      sVar1 = (short)iVar4;
    }
    else {
      sVar1 = (*BigShort)(cls.netchan.remote_address.port);
    }
  }
  uVar2 = (*BigShort)(sVar1);
  local_24.port = uVar2;
  pcVar3 = Cmd_Args();
  Q_strncpy(g_lastrconcommand,pcVar3,0x3ff);
  g_lastrconcommand[0x3ff] = '\0';
  g_rconaddress.type = local_24.type;
  g_rconaddress.ip[0] = local_24.ip[0];
  g_rconaddress.ip[1] = local_24.ip[1];
  g_rconaddress.ip[2] = local_24.ip[2];
  g_rconaddress.ip[3] = local_24.ip[3];
  g_rconaddress.ipx[0] = local_24.ipx[0];
  g_rconaddress.ipx[1] = local_24.ipx[1];
  g_rconaddress.ipx[2] = local_24.ipx[2];
  g_rconaddress.ipx[3] = local_24.ipx[3];
  g_rconaddress.ipx[4] = local_24.ipx[4];
  g_rconaddress.ipx[5] = local_24.ipx[5];
  g_rconaddress.ipx[6] = local_24.ipx[6];
  g_rconaddress.ipx[7] = local_24.ipx[7];
  g_rconaddress.ipx[8] = local_24.ipx[8];
  g_rconaddress.ipx[9] = local_24.ipx[9];
  g_rconaddress.port = local_24.port;
  adr.ip[0] = local_24.ip[0];
  adr.ip[1] = local_24.ip[1];
  adr.ip[2] = local_24.ip[2];
  adr.ip[3] = local_24.ip[3];
  adr.type = local_24.type;
  adr.ipx[0] = local_24.ipx[0];
  adr.ipx[1] = local_24.ipx[1];
  adr.ipx[2] = local_24.ipx[2];
  adr.ipx[3] = local_24.ipx[3];
  adr.ipx[4] = local_24.ipx[4];
  adr.ipx[5] = local_24.ipx[5];
  adr.ipx[6] = local_24.ipx[6];
  adr.ipx[7] = local_24.ipx[7];
  adr.ipx[8] = local_24.ipx[8];
  adr.ipx[9] = local_24.ipx[9];
  adr.port = local_24.port;
  Netchan_OutOfBandPrint(NS_CLIENT,adr,"challenge rcon\n");
LAB_00143a86:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ReadClientDLLData  @ 00142d50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ReadClientDLLData(void)

{
  int in_GS_OFFSET;
  uint local_8014;
  uchar local_8010 [32768];
  int local_10;
  
                    /* Unresolved local var: uchar[32768] data@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_8010,0,0x8000);
  FS_Read(&local_8014,4,1,cls.demofile);
  local_8014 = (*LittleLong)(local_8014);
  if (0x8000 < local_8014) {
    local_8014 = 0x8000;
  }
  FS_Read(local_8010,local_8014,1,cls.demofile);
  ClientDLL_ReadDemoBuffer(local_8014,local_8010);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ReadDemoMessage  @ 00143700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_ReadDemoMessage(void)

{
  int iVar1;
  qboolean qVar2;
  
  iVar1 = DemoPlayer_IsActive();
  if (iVar1 == 0) {
    qVar2 = CL_ReadDemoMessage_OLD();
    return qVar2;
  }
  net_message.cursize = DemoPlayer_ReadDemoMessage(net_message.data,net_message.maxsize);
  if (net_message.cursize == 0) {
    return false;
  }
  DemoPlayer_ReadNetchanState
            (&cls.netchan.incoming_sequence,&cls.netchan.incoming_acknowledged,
             &cls.netchan.incoming_reliable_acknowledged,&cls.netchan.incoming_reliable_sequence,
             &cls.netchan.outgoing_sequence,&cls.netchan.reliable_sequence,
             &cls.netchan.last_reliable_sequence);
  return true;
}


// CL_ReadDemoMessage_OLD  @ 00142e20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_ReadDemoMessage_OLD(void)

{
  int iVar1;
  float time;
  float fVar2;
  uint uVar3;
  vec_t iAnim;
  int iVar4;
  qboolean qVar5;
  int in_GS_OFFSET;
  longdouble lVar6;
  char cStack_1004d;
  int iStack_1004c;
  float fStack_10048;
  int32 iStack_10044;
  client_data_t cStack_10040;
  uchar auStack_10020 [65552];
  
                    /* Unresolved local var: int msglen@[???]
                       Unresolved local var: byte[65536] msgbuf@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: float ft@[???]
                       Unresolved local var: byte cmd@[???]
                       Unresolved local var: int32 curpos@[???]
                       Unresolved local var: float fElapsedTime@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: qboolean bSkipMessage@[???]
                       Unresolved local var: int nElapsedFrames@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  iStack_1004c = 0;
  if (cls.demofile == (FileHandle_t)0x0) {
    qVar5 = false;
    cls.demoplayback = false;
    CL_Disconnect_f();
    Con_Printf("Tried to read a demo message with no demo file\n");
  }
  else {
                    /* Unresolved local var: uchar[32768] data@[???]
                       Unresolved local var: int i@[???] */
    fVar2 = cls.demostarttime;
    iVar4 = cls.demostartframe;
    while( true ) {
      cls.demostartframe = iVar4;
      cls.demostarttime = fVar2;
      uVar3 = FS_Tell(cls.demofile);
      net_message.cursize = 0;
      FS_Read(&cStack_1004d,1,1,cls.demofile);
      FS_Read(&fStack_10048,4,1,cls.demofile);
      lVar6 = (longdouble)(*LittleFloat)(fStack_10048);
      fStack_10048 = (float)lVar6;
      FS_Read(&iStack_10044,4,1,cls.demofile);
      iStack_10044 = (*LittleLong)(iStack_10044);
      time = g_demotimescale * (float)realtime - cls.demostarttime;
      if (((cls.timedemo == false) && (cStack_1004d != '\x05' && cStack_1004d != '\0')) &&
         (time <= fStack_10048)) break;
      fVar2 = g_demotimescale * (float)realtime;
      iVar4 = host_framecount;
      if (cStack_1004d != '\x02') {
        if (cStack_1004d == '\x05') {
                    /* Unresolved local var: float ft@[???] */
          if (((0 < nCurEntryIndex) && (pCurrentEntry != (demoentry_t *)0x0)) &&
             ((pCurrentEntry->nFlags & 4) != 0)) {
            Cbuf_AddText("cd stop\n");
          }
          nCurEntryIndex = nCurEntryIndex + 1;
          if (demodir.nEntries <= nCurEntryIndex) {
                    /* WARNING: Subroutine does not return */
            Host_EndGame("End of demo.\n");
          }
          pCurrentEntry = demodir.p_rgEntries + nCurEntryIndex;
          cls.forcetrack = pCurrentEntry->nCDTrack;
          FS_Seek(cls.demofile,pCurrentEntry->nOffset,FILESYSTEM_SEEK_HEAD);
          cls.demoframecount = 0;
          cls.demostartframe = host_framecount;
          fVar2 = g_demotimescale * (float)realtime;
          iVar4 = cls.demostartframe;
        }
        else if (cStack_1004d == '\x03') {
                    /* Unresolved local var: char[64] szCmdName@[???] */
          FS_Read(auStack_10020,0x40,1,cls.demofile);
          qVar5 = ValidStuffText((char *)auStack_10020);
          fVar2 = cls.demostarttime;
          iVar4 = cls.demostartframe;
          if (qVar5 != false) {
            Cbuf_AddFilteredText((char *)auStack_10020);
            Cbuf_AddFilteredText("\n");
            fVar2 = cls.demostarttime;
            iVar4 = cls.demostartframe;
          }
        }
        else if (cStack_1004d == '\x04') {
                    /* Unresolved local var: float scr_fov_value@[???]
                       Unresolved local var: client_data_t cdat@[???] */
          FS_Read(&cStack_10040,0x20,1,cls.demofile);
          ClientDLL_DemoUpdateClientData(&cStack_10040);
          scr_fov_value = cStack_10040.fov;
          fVar2 = cls.demostarttime;
          iVar4 = cls.demostartframe;
        }
        else if (cStack_1004d == '\x06') {
          CL_DemoParseEvent();
          fVar2 = cls.demostarttime;
          iVar4 = cls.demostartframe;
        }
        else if (cStack_1004d == '\a') {
                    /* Unresolved local var: int anim@[???]
                       Unresolved local var: int body@[???]
                       Unresolved local var: int i@[???] */
          FS_Read(&cStack_10040,4,1,cls.demofile);
          iAnim = (vec_t)(*LittleLong)((int32)cStack_10040.origin[0]);
          cStack_10040.origin[0] = iAnim;
          FS_Read(&cStack_10040,4,1,cls.demofile);
          cStack_10040.origin[0] = (vec_t)(*LittleLong)((int32)cStack_10040.origin[0]);
          hudWeaponAnim((int)iAnim,(int)cStack_10040.origin[0]);
          fVar2 = cls.demostarttime;
          iVar4 = cls.demostartframe;
        }
        else if (cStack_1004d == '\b') {
          CL_DemoParseSound();
          fVar2 = cls.demostarttime;
          iVar4 = cls.demostartframe;
        }
        else {
          if (cStack_1004d != '\t') {
            if ((cls.timedemo == false) ||
               (CL_ReadDemoMessage_OLD::tdlastdemoframe != host_framecount)) {
              CL_ReadDemoMessage_OLD::tdlastdemoframe = host_framecount;
              if (cls.td_startframe + 1 == host_framecount) {
                cls.td_starttime = (float)realtime;
              }
              if ((nCurEntryIndex == 0) ||
                 ((cls.demoframecount == 0 && (CL_DemoSectionStart(), nCurEntryIndex == 0)))) {
                cls.demoframecount = cls.demoframecount + 1;
              }
              else {
                if (cls.demoframecount == 1) {
                  bInFadeout = false;
                  if ((pCurrentEntry->nFlags & 1) != 0) {
                    SetDemoMessage(pCurrentEntry->szDescription,0.01,1.0,2.0);
                    CL_HudMessage("__DEMOMESSAGE__");
                  }
                  if (cls.timedemo == false) {
                    cls.demostarttime = g_demotimescale * (float)realtime;
                  }
                  cls.demoframecount = cls.demoframecount + 1;
                  if (nCurEntryIndex == 0) goto LAB_00143430;
                }
                else {
                  cls.demoframecount = cls.demoframecount + 1;
                }
                if (bInFadeout == false) {
                  if (((pCurrentEntry->nFlags & 0x40U) == 0) ||
                     (time + 0.5 < pCurrentEntry->fTrackTime + 0.02)) {
                    if ((pCurrentEntry->nFlags & 0x20U) != 0) goto LAB_001432c4;
                  }
                  else {
                    sf_demo.holdTime = 0x199;
                    sf_demo.fadeFlags = 1;
                    bInFadeout = true;
                    sf_demo.duration = 0x800;
                    sf_demo.r = '\0';
                    sf_demo.g = '\0';
                    sf_demo.b = '\0';
                    sf_demo.a = 0xff;
                    V_ScreenFade((char *)0x0,0,&sf_demo);
                    if (((pCurrentEntry->nFlags & 0x20) != 0) && (bInFadeout == false)) {
LAB_001432c4:
                      if (pCurrentEntry->fTrackTime + 0.02 <= time + 2.0) {
                        bInFadeout = true;
                        sf_demo.duration = 0x2000;
                        sf_demo.holdTime = 0x199;
                        sf_demo.r = '\0';
                        sf_demo.g = '\0';
                        sf_demo.b = '\0';
                        sf_demo.a = 0xff;
                        sf_demo.fadeFlags = 1;
                        V_ScreenFade((char *)0x0,0,&sf_demo);
                      }
                    }
                  }
                }
              }
LAB_00143430:
              CL_DemoReadCmdInfo(time);
              iVar4 = DemoPlayer_IsActive();
              if (iVar4 == 0) {
                CL_ReadNetchanState_OLD();
              }
              else {
                DemoPlayer_ReadNetchanState
                          (&cls.netchan.incoming_sequence,&cls.netchan.incoming_acknowledged,
                           &cls.netchan.incoming_reliable_acknowledged,
                           &cls.netchan.incoming_reliable_sequence,&cls.netchan.outgoing_sequence,
                           &cls.netchan.reliable_sequence,&cls.netchan.last_reliable_sequence);
              }
              iVar4 = FS_Read(&iStack_1004c,4,1,cls.demofile);
              if (iVar4 != 4) {
                    /* WARNING: Subroutine does not return */
                Host_EndGame("Bad demo length.\n");
              }
              iStack_1004c = (*LittleLong)(iStack_1004c);
              if (iStack_1004c < 0) {
                    /* WARNING: Subroutine does not return */
                Host_EndGame("Demo message length < 0.\n");
              }
              if (0x10000 < iStack_1004c) {
                    /* WARNING: Subroutine does not return */
                Host_EndGame("Demo message > MAX_POSSIBLE_MSG");
              }
              if ((iStack_1004c != 0) &&
                 (iVar4 = FS_Read(auStack_10020,iStack_1004c,1,cls.demofile), iVar4 != iStack_1004c)
                 ) {
                    /* WARNING: Subroutine does not return */
                Host_EndGame("Error reading demo message data.\n");
              }
              qVar5 = true;
              Q_memcpy(net_message.data,auStack_10020,iStack_1004c);
              net_message.cursize = iStack_1004c;
            }
            else {
              qVar5 = false;
              uVar3 = FS_Tell(cls.demofile);
              FS_Seek(cls.demofile,uVar3 - 9,FILESYSTEM_SEEK_HEAD);
            }
            goto LAB_0014338f;
          }
          Q_memset(auStack_10020,0,0x8000);
          FS_Read(&cStack_10040,4,1,cls.demofile);
          cStack_10040.origin[0] = (vec_t)(*LittleLong)((int32)cStack_10040.origin[0]);
          if (0x8000 < (uint)cStack_10040.origin[0]) {
            cStack_10040.origin[0] = 4.59177e-41;
          }
          FS_Read(auStack_10020,(int)cStack_10040.origin[0],1,cls.demofile);
          ClientDLL_ReadDemoBuffer((int)cStack_10040.origin[0],auStack_10020);
          fVar2 = cls.demostarttime;
          iVar4 = cls.demostartframe;
        }
      }
    }
    FS_Seek(cls.demofile,uVar3,FILESYSTEM_SEEK_HEAD);
    qVar5 = false;
  }
LAB_0014338f:
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar5;
}


// CL_ReadNetchanState  @ 00140780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ReadNetchanState(void)

{
  int iVar1;
  
  iVar1 = DemoPlayer_IsActive();
  if (iVar1 != 0) {
    DemoPlayer_ReadNetchanState
              (&cls.netchan.incoming_sequence,&cls.netchan.incoming_acknowledged,
               &cls.netchan.incoming_reliable_acknowledged,&cls.netchan.incoming_reliable_sequence,
               &cls.netchan.outgoing_sequence,&cls.netchan.reliable_sequence,
               &cls.netchan.last_reliable_sequence);
    return;
  }
  CL_ReadNetchanState_OLD();
  return;
}


// CL_ReadNetchanState_OLD  @ 00140660
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ReadNetchanState_OLD(void)

{
  FS_Read(&cls.netchan.incoming_sequence,4,1,cls.demofile);
  FS_Read(&cls.netchan.incoming_acknowledged,4,1,cls.demofile);
  FS_Read(&cls.netchan.incoming_reliable_acknowledged,4,1,cls.demofile);
  FS_Read(&cls.netchan.incoming_reliable_sequence,4,1,cls.demofile);
  FS_Read(&cls.netchan.outgoing_sequence,4,1,cls.demofile);
  FS_Read(&cls.netchan.reliable_sequence,4,1,cls.demofile);
  FS_Read(&cls.netchan.last_reliable_sequence,4,1,cls.demofile);
  return;
}


// CL_ReadPackets  @ 00148ef0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ReadPackets(void)

{
  netadr_t a;
  netadr_t a_00;
  netadr_t b;
  uint uVar1;
  qboolean qVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int in_GS_OFFSET;
  char local_90 [4];
  undefined2 auStack_8c [62];
  int local_10;
  
                    /* Unresolved local var: int msg_count@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state == ca_dedicated) {
LAB_0014913f:
    if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  iVar5 = 0;
  cl.oldtime = cl.time;
  cl.time = host_frametime + cl.time;
LAB_00148f40:
  if (cls.demoplayback != false) goto LAB_00149020;
  do {
    if (cls.passive == false) {
      qVar2 = NET_GetPacket(NS_CLIENT);
    }
    else {
      qVar2 = NET_GetPacket(NS_MULTICAST);
    }
    while( true ) {
      if (qVar2 == false) {
        if ((0xfa < iVar5) && (cls.demoplayback == false)) {
          Con_DPrintf("Ignored %i messages\n",iVar5 + -0xfa);
        }
        CL_SetSolidEntities();
        if (ca_disconnected < cls.state) {
          qVar2 = Netchan_IncomingReady(&cls.netchan);
          if (qVar2 != false) {
            qVar2 = Netchan_CopyNormalFragments(&cls.netchan);
            if (qVar2 != false) {
              MSG_BeginReading();
              CL_ParseServerMessage(false);
            }
            qVar2 = Netchan_CopyFileFragments(&cls.netchan);
            if (qVar2 != false) {
              if (gDownloadFile[0] != '\0') {
                if (gDownloadFile[0] == '!') {
                  SetSecondaryProgressBarText("#GameUI_SecurityModule");
                }
                else {
                    /* Unresolved local var: char[128] buf@[???] */
                  __snprintf_chk(local_90,0x80,1,0x80,0x265059,gDownloadFile);
                  SetSecondaryProgressBarText(local_90);
                }
                SetSecondaryProgressBar(100.0);
              }
              CL_ProcessFile(true,cls.netchan.incomingfilename);
            }
          }
          if (((ca_connecting < cls.state) && (cls.demoplayback == false)) &&
             ((double)cl_timeout.value < realtime - (double)cls.netchan.last_received)) {
            COM_ExplainDisconnection(true,"#GameUI_ServerConnectionTimeout");
            CL_Disconnect();
            goto LAB_0014913f;
          }
        }
        if (cl_shownet.value != 0.0) {
          Con_Printf("\n");
        }
        Netchan_UpdateProgress(&cls.netchan);
        if ((0.0 < scr_downloading.value) && (gDownloadFile[0] != '\0')) {
                    /* Unresolved local var: char[128] buf@[???] */
          if (gDownloadFile[0] == '!') {
            uVar1 = 0;
            do {
              uVar4 = uVar1;
              *(undefined4 *)((int)auStack_8c + (uVar4 - 4)) =
                   *(undefined4 *)(&LAB_00265cd8 + uVar4);
              uVar1 = uVar4 + 4;
            } while (uVar4 + 4 < 0x20);
            *(short *)((int)auStack_8c + uVar4) = (short)*(undefined4 *)(&LAB_00265cdc + uVar4);
          }
          else {
            __snprintf_chk(local_90,0x80,1,0x80,&LAB_0026505f_4,gDownloadFile);
          }
          SetSecondaryProgressBar(scr_downloading.value / 100.0);
          SetSecondaryProgressBarText(local_90);
          SetLoadingProgressBarStatusText("#GameUI_VerifyingAndDownloading");
        }
        Net_APICheckTimeouts();
        goto LAB_0014913f;
      }
      iVar5 = iVar5 + 1;
      if ((0xfa < iVar5) && (cls.demoplayback == false)) break;
      if (*(int *)net_message.data == -1) {
        CL_ConnectionlessPacket();
        goto LAB_00148f40;
      }
      if (cls.passive == false) {
        if (cls.demoplayback == false) {
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
          b.ip[0] = cls.netchan.remote_address.ip[0];
          b.ip[1] = cls.netchan.remote_address.ip[1];
          b.ip[2] = cls.netchan.remote_address.ip[2];
          b.ip[3] = cls.netchan.remote_address.ip[3];
          b.type = cls.netchan.remote_address.type;
          b.ipx[0] = cls.netchan.remote_address.ipx[0];
          b.ipx[1] = cls.netchan.remote_address.ipx[1];
          b.ipx[2] = cls.netchan.remote_address.ipx[2];
          b.ipx[3] = cls.netchan.remote_address.ipx[3];
          b.ipx[4] = cls.netchan.remote_address.ipx[4];
          b.ipx[5] = cls.netchan.remote_address.ipx[5];
          b.ipx[6] = cls.netchan.remote_address.ipx[6];
          b.ipx[7] = cls.netchan.remote_address.ipx[7];
          b.ipx[8] = cls.netchan.remote_address.ipx[8];
          b.ipx[9] = cls.netchan.remote_address.ipx[9];
          b.port = cls.netchan.remote_address.port;
          qVar2 = NET_CompareAdr(a_00,b);
          if (qVar2 != false) {
            if (cls.passive != false) goto LAB_00148f96;
            goto LAB_00148faa;
          }
        }
        else if (1 < cls.state - ca_disconnected) {
LAB_00149193:
          MSG_BeginReading();
LAB_00149198:
          CL_ParseServerMessage(true);
        }
        goto LAB_00148f40;
      }
LAB_00148f96:
      if (cls.state == ca_connecting) {
        cls.state = ca_connected;
      }
      else {
LAB_00148faa:
        if (cls.state - ca_disconnected < 2) goto LAB_00148f40;
      }
      if (cls.demoplayback != false) goto LAB_00149193;
      if (7 < net_message.cursize) {
        qVar2 = Netchan_Process(&cls.netchan);
        if (qVar2 != false) goto LAB_00149198;
        goto LAB_00148f40;
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
      pcVar3 = NET_AdrToString(a);
      Con_Printf("CL_ReadPackets:  undersized packet %i bytes from %s\n",net_message.cursize,pcVar3)
      ;
      if (cls.demoplayback == false) break;
LAB_00149020:
      qVar2 = CL_ReadDemoMessage();
    }
  } while( true );
}


// CL_ReallocateDynamicData  @ 00156ac0
void CL_ReallocateDynamicData(int nMaxClients)

{
  cl.max_edicts = COM_EntsForPlayerSlots(nMaxClients);
  if (0 < cl.max_edicts) {
    if (cl_entities != (cl_entity_t *)0x0) {
      Con_Printf("CL_Reallocate cl_entities\n");
    }
    cl_entities = Mem_ZeroMalloc(cl.max_edicts * 3000);
    R_AllocObjects(cl.max_edicts);
    Q_memset(cl.frames,0,CL_UPDATE_BACKUP * 0x4318);
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("CL_ReallocateDynamicData allocating 0 entities");
}


// CL_RecordHUDCommand  @ 00140a10
void CL_RecordHUDCommand(char *cmdname)

{
  int in_GS_OFFSET;
  longdouble lVar1;
  undefined1 local_59;
  float local_58;
  int32 local_54;
  char local_50 [63];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: hud_command_t demcmd@[???] */
  local_59 = 3;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
  local_58 = (float)lVar1;
  local_54 = (*LittleLong)(host_framecount - cls.demostartframe);
  Q_memset(local_50,0,0x40);
  Q_strncpy(local_50,cmdname,0x3f);
  local_11 = 0;
  FS_Write(&local_59,0x49,1,cls.demofile);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Record_f  @ 00141b00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Record_f(void)

{
  demoentry_t *pdVar1;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  uint uVar5;
  int iVar6;
  int in_GS_OFFSET;
  longdouble lVar7;
  undefined1 uStack_335;
  float fStack_334;
  int32 iStack_330;
  char local_32c [260];
  char local_228 [260];
  char local_124 [259];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szMapName@[???]
                       Unresolved local var: char[260] szDll@[???]
                       Unresolved local var: int track@[???]
                       Unresolved local var: int32 copysize@[???]
                       Unresolved local var: int32 savepos@[???]
                       Unresolved local var: int32 curpos@[???]
                       Unresolved local var: byte cmd@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: int swlen@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = Cmd_Argc();
  if (iVar2 < 2) {
    Con_Printf("record <demoname> <cd>\n");
  }
  else if (cls.demorecording == false) {
    if (cls.demoplayback == false) {
      if ((cls.demoheader == (FileHandle_t)0x0) || (cls.state != ca_active)) {
        Con_Printf("You must be in an active map spawned on a machine that allows creation of files in %s\n"
                   ,com_gamedir);
      }
      else {
        iVar2 = Cmd_Argc();
        if (iVar2 - 2U < 2) {
          pcVar3 = Cmd_Argv(1);
          pcVar3 = Q_strstr(pcVar3,"..");
          if (pcVar3 == (char *)0x0) {
            iVar6 = -1;
            if (iVar2 == 3) {
              pcVar3 = Cmd_Argv(2);
              iVar6 = Q_atoi(pcVar3);
              Con_Printf("Forcing CD track to %i\n",iVar6);
            }
            pcVar3 = Cmd_Argv(1);
            snprintf(local_32c,0x100,"%s",pcVar3);
            COM_AddExtension(local_32c,".dem",0x104);
            qVar4 = COM_HasFileExtension(local_32c,"dem");
            if (qVar4 == false) {
              Con_Printf("Error: couldn\'t open demo file %s\n",local_32c);
            }
            else {
              Con_Printf("recording to %s.\n",local_32c);
              cls.demofile = FS_OpenPathID(local_32c,"wb","GAMECONFIG");
              if (cls.demofile == (FileHandle_t)0x0) {
                Con_Printf("Error: couldn\'t open demo file %s, demo files must have .dem extension.\n"
                           ,local_32c);
              }
              else {
                Q_memset(&demoheader,0,0x220);
                Q_strncpy(demoheader.szFileStamp,"HLDEMO",6);
                COM_FileBase((cl.worldmodel)->name,local_228);
                Q_strncpy(demoheader.szMapName,local_228,0x103);
                demoheader.szMapName[0x103] = '\0';
                Q_strncpy(local_124,com_gamedir,0x103);
                local_21 = 0;
                COM_FileBase(local_124,demoheader.szDllDir);
                demoheader.mapCRC = cl.serverCRC;
                demoheader.nDemoProtocol = 5;
                demoheader.nNetProtocolVersion = 0x30;
                demoheader.nDirectoryOffset = 0;
                FS_Write(&demoheader,0x220,1,cls.demofile);
                Q_memset(&demodir,0,8);
                demodir.nEntries = 2;
                demodir.p_rgEntries = Mem_Malloc(0xb8);
                Q_memset(demodir.p_rgEntries,0,demodir.nEntries * 0x5c);
                pCurrentEntry = demodir.p_rgEntries;
                Q_strcpy((demodir.p_rgEntries)->szDescription,"LOADING");
                pCurrentEntry->nEntryType = 0;
                pdVar1 = pCurrentEntry;
                pCurrentEntry->nCDTrack = iVar6;
                pdVar1->nFlags = 0;
                pdVar1->fTrackTime = 0.0;
                uVar5 = FS_Tell(cls.demofile);
                pdVar1->nOffset = uVar5;
                cls.demowaiting = true;
                cls.demorecording = true;
                FS_Tell(cls.demofile);
                uStack_335 = 5;
                FS_Write(&uStack_335,1,1,cls.demoheader);
                lVar7 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
                fStack_334 = (float)lVar7;
                FS_Write(&fStack_334,4,1,cls.demoheader);
                iStack_330 = (*LittleLong)(host_framecount - cls.demostartframe);
                FS_Write(&iStack_330,4,1,cls.demoheader);
                FS_Flush(cls.demoheader);
                uVar5 = FS_Tell(cls.demoheader);
                FS_Seek(cls.demoheader,0,FILESYSTEM_SEEK_HEAD);
                CL_DemoCopyFileChunk(cls.demofile,cls.demoheader,uVar5);
                FS_Seek(cls.demoheader,uVar5,FILESYSTEM_SEEK_HEAD);
                cls.demoframecount = 0;
                cls.demostartframe = host_framecount;
                cls.demostarttime = (float)realtime;
                uVar5 = FS_Tell(cls.demofile);
                pdVar1 = demodir.p_rgEntries;
                pCurrentEntry->nFileLength = uVar5 - pCurrentEntry->nOffset;
                pdVar1[1].nFlags = 0;
                pCurrentEntry = pdVar1 + 1;
                pdVar1[1].nCDTrack = iVar6;
                pdVar1[1].nEntryType = 1;
                builtin_strncpy(pdVar1[1].szDescription,"Play",4);
                builtin_strncpy(pdVar1[1].szDescription + 4,"back",4);
                pdVar1[1].szDescription[8] = '\0';
                pdVar1[1].fTrackTime = 0.0;
                uVar5 = FS_Tell(cls.demofile);
                uStack_335 = 2;
                pdVar1[1].nOffset = uVar5;
                FS_Write(&uStack_335,1,1,cls.demofile);
                lVar7 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
                fStack_334 = (float)lVar7;
                FS_Write(&fStack_334,4,1,cls.demofile);
                iStack_330 = (*LittleLong)(host_framecount - cls.demostartframe);
                FS_Write(&iStack_330,4,1,cls.demofile);
                cls.td_startframe = host_framecount;
                cls.td_lastframe = -1;
                cls.demoappending = false;
              }
            }
          }
          else {
            Con_Printf("Relative pathnames are not allowed.\n");
          }
        }
        else {
          Con_Printf("record <demoname> <cd track>\n");
        }
      }
    }
    else {
      Con_Printf("Can\'t record during demo playback.\n");
    }
  }
  else {
    Con_Printf("Already recording.\n");
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_RedoPrediction  @ 0013bee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_RedoPrediction(void)

{
  vec_t vVar1;
  vec_t vVar2;
  float fVar3;
  double dVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  local_state_t *to;
  float fVar13;
  local_state_t *local_5c;
  usercmd_t *local_50;
  usercmd_t *local_4c;
  double local_34;
  float local_28;
  float local_24;
  float local_20;
  
  if (cls.netchan.incoming_sequence == g_lastupdate_sequence) {
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: cmd_t * fcmd@[???]
                       Unresolved local var: cmd_t * tcmd@[???]
                       Unresolved local var: float targettime@[???]
                       Unresolved local var: frame_t * fromframe@[???]
                       Unresolved local var: local_state_t * from@[???]
                       Unresolved local var: local_state_t * to@[???]
                       Unresolved local var: entity_state_t * ts@[???]
                       Unresolved local var: entity_state_t * fs@[???]
                       Unresolved local var: clientdata_t * fcd@[???]
                       Unresolved local var: clientdata_t * tcd@[???]
                       Unresolved local var: double dTime@[???]
                       Unresolved local var: int stoppoint@[???] */
  if ((cls.state != ca_active) || (cls.spectator != false)) goto LAB_0013bf2f;
  pmove = &g_clmove;
  CL_SetUpPlayerPrediction(false,false);
  iVar7 = cl.parsecountmod;
  dVar4 = realtime;
  if ((cl.intermission != 0) ||
     ((cl.validsequence == 0 ||
      (CL_UPDATE_MASK <= (cls.netchan.outgoing_sequence + 1) - cls.netchan.incoming_acknowledged))))
  goto LAB_0013bf2f;
  cl.simangles[0] = cl.viewangles[0];
  cl.simangles[1] = cl.viewangles[1];
  cl.simangles[2] = cl.viewangles[2];
  if (cls.demoplayback != false) goto LAB_0013bf2f;
  iVar8 = cl.parsecountmod * 0x1930;
  iVar9 = cl.parsecountmod * 0x4318 + 0xc6aa30 + cl.playernum * 0x154;
  uVar5 = 0;
  do {
    *(undefined4 *)(iVar8 + 0xd78324 + uVar5) = *(undefined4 *)(iVar9 + 0xc + uVar5);
    *(undefined4 *)(iVar8 + 0xd78328 + uVar5) = *(undefined4 *)(iVar9 + 0x10 + uVar5);
    uVar5 = uVar5 + 8;
  } while (uVar5 < 0x150);
  iVar12 = iVar7 * 0x1930;
  *(undefined4 *)(iVar8 + 0xd78324 + uVar5) = *(undefined4 *)(iVar9 + 0xc + uVar5);
  iVar9 = iVar7 * 0x4318;
  uVar5 = 0;
  do {
    *(undefined4 *)(iVar12 + 0xd78478 + uVar5) = *(undefined4 *)(iVar9 + 0xc6d4c4 + uVar5);
    *(undefined4 *)(iVar12 + 0xd7847c + uVar5) = *(undefined4 *)(iVar9 + 0xc6d4c8 + uVar5);
    uVar5 = uVar5 + 8;
  } while (uVar5 < 0x1d8);
  *(undefined4 *)(iVar12 + 0xd78478 + uVar5) = *(undefined4 *)(iVar9 + 0xc6d4c4 + uVar5);
  Q_memcpy(cl.predicted_frames[iVar7].weapondata,cl.frames[iVar7].weapondata,0x1600);
  if (cl.frames[iVar7].invalid != false) goto LAB_0013bf2f;
  local_34 = cl.frames[iVar7].time;
  cl.onground = -1;
  to = cl.predicted_frames + cl.parsecountmod;
  local_50 = &cl.commands[cls.netchan.incoming_acknowledged & CL_UPDATE_MASK].cmd;
  CL_PushPMStates();
  CL_SetSolidPlayers(cl.playernum);
  g_i = 1;
  local_4c = local_50;
  local_5c = to;
  if ((CL_UPDATE_BACKUP < 3) ||
     (uVar5 = cls.netchan.incoming_acknowledged + 1, uVar6 = CL_UPDATE_MASK,
     cls.netchan.outgoing_sequence <= (int)uVar5)) {
    CL_PopPMStates();
    if (CL_UPDATE_MASK < 2) goto LAB_0013bf2f;
  }
  else {
    do {
      iVar7 = g_i;
      uVar10 = uVar5 & uVar6;
      local_50 = &cl.commands[uVar10].cmd;
      uVar11 = cl.parsecountmod + g_i & uVar6;
      to = cl.predicted_frames + uVar11;
      CL_RunUsercmd(local_5c,to,local_50,false,&local_34,uVar5);
      iVar9 = cls.netchan.incoming_acknowledged;
      cl.commands[uVar10].processedfuncs = true;
      uVar6 = CL_UPDATE_MASK;
      uVar5 = iVar9 + iVar7 & CL_UPDATE_MASK;
      fVar13 = cl.commands[uVar10].senttime;
      vVar1 = *(vec_t *)&cl.predicted_frames[uVar11].playerstate.field_0x14;
      vVar2 = *(vec_t *)&cl.predicted_frames[uVar11].playerstate.field_0x18;
      cl.predicted_origins[uVar5][0] = *(vec_t *)&cl.predicted_frames[uVar11].playerstate.field_0x10
      ;
      cl.predicted_origins[uVar5][1] = vVar1;
      cl.predicted_origins[uVar5][2] = vVar2;
      if (((float)dVar4 <= fVar13) ||
         (iVar7 = iVar7 + 1, g_i = iVar7, local_4c = local_50, local_5c = to,
         CL_UPDATE_BACKUP + -1 <= iVar7)) break;
      uVar5 = iVar9 + iVar7;
    } while ((int)uVar5 < cls.netchan.outgoing_sequence);
    CL_PopPMStates();
    if (CL_UPDATE_MASK <= iVar7) goto LAB_0013bf2f;
    if (to == (local_state_t *)0x0) {
      local_50 = local_4c;
      to = local_5c;
    }
  }
  fVar13 = *(float *)(local_4c + 1);
  if (*(float *)(local_50 + 1) == fVar13) {
    fVar3 = 0.0;
  }
  else {
    fVar13 = ((float)dVar4 - fVar13) / (*(float *)(local_50 + 1) - fVar13);
    fVar3 = 0.0;
    if (0.0 <= fVar13) {
      fVar3 = fVar13;
    }
  }
  iVar7 = 0;
  do {
    if (128.0 < ABS(*(float *)((to->playerstate).controller + iVar7 * 4 + -0x58) -
                    *(float *)((local_5c->playerstate).controller + iVar7 * 4 + -0x58))) {
      cl.simvel[0] = (to->client).velocity[0];
      cl.simvel[1] = (to->client).velocity[1];
      cl.simvel[2] = (to->client).velocity[2];
      cl.simorg[0] = *(vec_t *)&(to->playerstate).field_0x10;
      cl.simorg[1] = *(vec_t *)&(to->playerstate).field_0x14;
      cl.simorg[2] = *(vec_t *)&(to->playerstate).field_0x18;
      cl.punchangle[0] = (to->client).punchangle[0];
      cl.punchangle[1] = (to->client).punchangle[1];
      cl.punchangle[2] = (to->client).punchangle[2];
      cl.viewheight[0] = (to->client).view_ofs[0];
      cl.viewheight[1] = (to->client).view_ofs[1];
      cl.viewheight[2] = (to->client).view_ofs[2];
      goto LAB_0013c56f;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 3);
  iVar7 = 0;
  do {
                    /* Unresolved local var: int i@[???] */
    iVar9 = iVar7 + 4;
    *(float *)((int)cl.simorg + iVar7) =
         (*(float *)((to->playerstate).controller + iVar7 + -0x58) -
         *(float *)((local_5c->playerstate).controller + iVar7 + -0x58)) * fVar3 +
         *(float *)((local_5c->playerstate).controller + iVar7 + -0x58);
    iVar7 = iVar9;
  } while (iVar9 != 0xc);
  iVar7 = 0;
  do {
                    /* Unresolved local var: int i@[???] */
    iVar9 = iVar7 + 4;
    *(float *)((int)cl.simvel + iVar7) =
         (*(float *)((int)(to->client).velocity + iVar7) -
         *(float *)((int)(local_5c->client).velocity + iVar7)) * fVar3 +
         *(float *)((int)(local_5c->client).velocity + iVar7);
    iVar7 = iVar9;
  } while (iVar9 != 0xc);
  iVar7 = 0;
  do {
                    /* Unresolved local var: int i@[???] */
    iVar9 = iVar7 + 4;
    *(float *)((int)cl.punchangle + iVar7) =
         (*(float *)((int)(to->client).punchangle + iVar7) -
         *(float *)((int)(local_5c->client).punchangle + iVar7)) * fVar3 +
         *(float *)((int)(local_5c->client).punchangle + iVar7);
    iVar7 = iVar9;
  } while (iVar9 != 0xc);
  if ((local_5c->playerstate).usehull == (to->playerstate).usehull) {
    iVar7 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      iVar9 = iVar7 + 4;
      *(float *)((int)cl.viewheight + iVar7) =
           (*(float *)((int)(to->client).view_ofs + iVar7) -
           *(float *)((int)(local_5c->client).view_ofs + iVar7)) * fVar3 +
           *(float *)((int)(local_5c->client).view_ofs + iVar7);
      iVar7 = iVar9;
    } while (iVar9 != 0xc);
  }
  else {
    cl.viewheight[0] = (to->client).view_ofs[0];
    cl.viewheight[1] = (to->client).view_ofs[1];
    cl.viewheight[2] = (to->client).view_ofs[2];
  }
LAB_0013c56f:
  if (((to->client).flags & 0x200) == 0) {
    cl.onground = -1;
    cl.waterlevel = (to->client).waterlevel;
    cl.usehull = (to->playerstate).usehull;
    cl.stats[2] = (to->client).viewmodel;
    cl.moving = 0;
LAB_0013c5c8:
    fVar13 = (float)cl_correction_time;
    if (((0.0 < fVar13) && (cl_nosmooth.value == 0.0)) && (cl_smoothtime.value != 0.0)) {
                    /* Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???] */
      if (cl_smoothtime.value <= 0.0) {
        Cvar_DirectSet(&cl_smoothtime,"0.1");
        fVar13 = (float)cl_correction_time;
      }
      fVar3 = 0.0;
      if (0.0 <= fVar13) {
        fVar3 = fVar13;
      }
      if (cl_smoothtime.value <= fVar3) {
        fVar3 = cl_smoothtime.value;
      }
      cl_correction_time = (double)fVar3;
      local_28 = cl.simorg[0] - CL_PredictMove::lastsimorg[0];
      local_24 = cl.simorg[1] - CL_PredictMove::lastsimorg[1];
      local_20 = cl.simorg[2] - CL_PredictMove::lastsimorg[2];
      VectorScale(&local_28,1.0 - fVar3 / cl_smoothtime.value,&local_28);
      cl.simorg[0] = CL_PredictMove::lastsimorg[0] + local_28;
      cl.simorg[1] = CL_PredictMove::lastsimorg[1] + local_24;
      cl.simorg[2] = CL_PredictMove::lastsimorg[2] + local_20;
    }
  }
  else {
    cl.onground = g_lastground;
    cl.waterlevel = (to->client).waterlevel;
    cl.usehull = (to->playerstate).usehull;
    cl.stats[2] = (to->client).viewmodel;
    cl.moving = 0;
    if ((g_lastground < 1) || (cl.num_entities <= g_lastground)) goto LAB_0013c5c8;
                    /* Unresolved local var: vec3_t delta@[???] */
    local_28 = cl_entities[g_lastground].curstate.origin[0] -
               cl_entities[g_lastground].prevstate.origin[0];
    local_24 = cl_entities[g_lastground].curstate.origin[1] -
               cl_entities[g_lastground].prevstate.origin[1];
    local_20 = 0.0;
    fVar13 = Length(&local_28);
    if (0.0 < fVar13) {
      cl.moving = 1;
    }
    if (cl.moving == 0) goto LAB_0013c5c8;
    cl_correction_time = 0.0;
  }
  CL_PredictMove::lastsimorg[0] = cl.simorg[0];
  CL_PredictMove::lastsimorg[1] = cl.simorg[1];
  CL_PredictMove::lastsimorg[2] = cl.simorg[2];
  CL_SetIdealPitch();
LAB_0013bf2f:
  iVar9 = cl.parsecountmod;
                    /* Unresolved local var: int frame@[???]
                       Unresolved local var: int command@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float len@[???] */
  uVar5 = cls.netchan.incoming_acknowledged & CL_UPDATE_MASK;
  iVar7 = cl.playernum * 0x154 + cl.parsecountmod * 0x4318;
  local_28 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar7 + 0x111e0) -
             cl.predicted_origins[uVar5][0];
  local_24 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar7 + 0x111e4) -
             cl.predicted_origins[uVar5][1];
  local_20 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar7 + 0x111e8) -
             cl.predicted_origins[uVar5][2];
  fVar13 = Length(&local_28);
  if (fVar13 <= 64.0) {
    if ((cl_showerror.value != 0.0) && (0.5 < fVar13)) {
      CL_CheckPredictionError::pos = CL_CheckPredictionError::pos + 1;
      Con_NPrintf((CL_CheckPredictionError::pos & 3U) + 10,"pred. error %.3f units",(double)fVar13);
    }
    cl.prediction_error[0] = local_28;
    cl.prediction_error[1] = local_24;
    iVar7 = cl.playernum * 0x154 + iVar9 * 0x4318;
    vVar1 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar7 + 0x111e4);
    vVar2 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar7 + 0x111e8);
    cl.prediction_error[2] = local_20;
    cl.predicted_origins[iVar9][0] =
         *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar7 + 0x111e0);
    cl.predicted_origins[iVar9][1] = vVar1;
    cl.predicted_origins[iVar9][2] = vVar2;
    if ((0.25 < fVar13) && (cl.maxclients != 1)) {
      cl_correction_time = (double)cl_smoothtime.value;
    }
  }
  else {
    cl.prediction_error[0] = vec3_origin[0];
    cl.prediction_error[1] = vec3_origin[1];
    cl.prediction_error[2] = vec3_origin[2];
  }
  return;
}


// CL_RegisterCustomization  @ 001460f0
void CL_RegisterCustomization(resource_t *resource)

{
  uint playernumber;
  int iVar1;
  qboolean qVar2;
  customization_s *pcVar3;
  
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
  playernumber = (uint)resource->playernum;
  pcVar3 = cl.players[playernumber].customdata.pNext;
  if (pcVar3 != (customization_s *)0x0) {
    do {
      iVar1 = Q_memcmp((pcVar3->resource).rgucMD5_hash,resource->rgucMD5_hash,0x10);
      if (iVar1 == 0) {
        Con_DPrintf("Duplicate resource received and ignored.\n");
        return;
      }
      pcVar3 = pcVar3->pNext;
    } while (pcVar3 != (customization_s *)0x0);
    playernumber = (uint)resource->playernum;
  }
  qVar2 = COM_CreateCustomization
                    (&cl.players[playernumber].customdata,resource,playernumber,1,
                     (customization_t **)0x0,(int *)0x0);
  if (qVar2 != false) {
    return;
  }
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
  Con_Printf("Unable to create custom decal for player %i\n",(uint)resource->playernum);
  return;
}


// CL_RegisterResources  @ 00155490
void CL_RegisterResources(sizebuf_t *msg)

{
  char *s;
  CRC32_t local_10 [4];
  
  if ((cls.dl.custom != false) || ((cls.signon == 2 && (cls.state == ca_active)))) {
    cls.dl.custom = false;
    return;
  }
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_RegisterResources()");
  }
  ContinueLoadingProgressBar("ClientConnect",8,0.0);
  if (cls.demoplayback == false) {
    CL_SendConsistencyInfo(msg);
  }
  cl.worldmodel = cl.model_precache[1];
  if ((cl.model_precache[1] != (model_s *)0x0) && (0 < cl.maxclients)) {
    if (cl_entities == (cl_entity_t *)0x0) {
      cl.max_edicts = COM_EntsForPlayerSlots(cl.maxclients);
      if (cl.max_edicts < 1) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("CL_ReallocateDynamicData allocating 0 entities");
      }
      if (cl_entities != (cl_entity_t *)0x0) {
        Con_Printf("CL_Reallocate cl_entities\n");
      }
      cl_entities = Mem_ZeroMalloc(cl.max_edicts * 3000);
      R_AllocObjects(cl.max_edicts);
      Q_memset(cl.frames,0,CL_UPDATE_BACKUP * 0x4318);
    }
    cl_entities->model = cl.worldmodel;
    CL_PrecacheBSPModels(cl.model_precache[1]->name);
    if (cls.state != ca_disconnected) {
      Con_DPrintf("Setting up renderer...\n");
      R_NewMap();
      Hunk_Check();
      noclip_anglehack = false;
      if (cls.passive == false) {
                    /* Unresolved local var: int mungebuffer@[???] */
        local_10[0] = cl.mapCRC;
        MSG_WriteByte(msg,3);
        COM_Munge2((uchar *)local_10,4,0xffU - cl.servercount & 0xff);
        s = va("spawn %i %i",cl.servercount,local_10[0]);
        MSG_WriteString(msg,s);
      }
      CL_InitSpectator();
      if (fs_startup_timings.value != 0.0) {
        AddStartupTiming("end   CL_RegisterResources()");
        return;
      }
    }
    return;
  }
  Con_Printf("Client world model is NULL\n");
  COM_ExplainDisconnection(true,"Client world model is NULL\n");
  CL_Disconnect();
  return;
}


// CL_RemoveCustomization  @ 001564e0
void CL_RemoveCustomization(int nPlayerNum,customization_t *pRemove)

{
  customization_s *pcVar1;
  void *pvVar2;
  customization_s *pcVar3;
  undefined4 *p;
  int iVar4;
  cache_user_t *c;
  customization_s *pcVar5;
  
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: int i@[???] */
                    /* Unresolved local var: customization_t * pNext@[???]
                       Unresolved local var: cachewad_t * pWad@[???]
                       Unresolved local var: cacheentry_t * pic@[???] */
  pcVar1 = cl.players[nPlayerNum].customdata.pNext;
  pcVar5 = &cl.players[nPlayerNum].customdata;
  while (pcVar3 = pcVar1, pcVar3 != (customization_s *)0x0) {
    if (pcVar3 == pRemove) {
      pcVar1 = pRemove->pNext;
      if ((pRemove->bInUse != false) &&
         (((pRemove->pBuffer == (void *)0x0 ||
           (Mem_Free(pRemove->pBuffer), pRemove->bInUse != false)) &&
          (p = pRemove->pInfo, p != (undefined4 *)0x0)))) {
        if ((pRemove->resource).type == t_decal) {
          if (cls.state == ca_active) {
            R_DecalRemoveAll(~nPlayerNum);
            p = pRemove->pInfo;
          }
          Mem_Free((void *)p[4]);
          c = (cache_user_t *)(p[1] + 0x40);
          if (0 < (int)p[2]) {
            iVar4 = 0;
            do {
              pvVar2 = Cache_Check(c);
              if (pvVar2 != (void *)0x0) {
                Cache_Free(c);
              }
              iVar4 = iVar4 + 1;
              c = c + 0x11;
            } while (iVar4 < (int)p[2]);
          }
          Mem_Free((void *)*p);
          Mem_Free((void *)p[1]);
          p = pRemove->pInfo;
        }
        Mem_Free(p);
      }
      Mem_Free(pRemove);
      pcVar5->pNext = pcVar1;
    }
    else {
      pcVar1 = pcVar3->pNext;
      pcVar5 = pcVar3;
    }
  }
  return;
}


// CL_RemoveDemo_f  @ 0013f900
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_RemoveDemo_f(void)

{
  int iVar1;
  char *pcVar2;
  qboolean qVar3;
  FILE *src;
  int iVar4;
  uint uVar5;
  int iVar6;
  demoentry_t *pdVar7;
  int iVar8;
  demoentry_t *pdVar9;
  int *piVar10;
  int *piVar11;
  int in_GS_OFFSET;
  byte bVar12;
  int local_334;
  void *local_330;
  char local_32c [260];
  char local_228 [260];
  char local_124 [255];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: int nSegmentToRemove@[???]
                       Unresolved local var: demodirectory_t newdir@[???]
                       Unresolved local var: demoentry_t * oldentry@[???]
                       Unresolved local var: demoentry_t * newentry@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: int i@[???] */
  bVar12 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    if ((cls.demorecording == false) && (cls.demoplayback == false)) {
      iVar1 = Cmd_Argc();
      if (iVar1 == 3) {
        pcVar2 = Cmd_Argv(1);
        pcVar2 = Q_strstr(pcVar2,"..");
        if (pcVar2 == (char *)0x0) {
          pcVar2 = Cmd_Argv(2);
          iVar1 = Q_atoi(pcVar2);
          if (iVar1 < 2) {
            Con_Printf("Cannot remove the STARTUP segment.\n");
          }
          else {
            pcVar2 = Cmd_Argv(1);
            snprintf(local_32c,0x100,"%s",pcVar2);
            COM_DefaultExtension(local_32c,".dem");
            qVar3 = COM_HasFileExtension(local_32c,"dem");
            if (qVar3 == false) {
              Con_Printf("Error: couldn\'t open demo file %s, demo files must have .dem extension.\n"
                         ,local_32c);
            }
            else {
              Con_Printf("Removing segment %i from demo %s.\n",iVar1,local_32c);
              Q_strncpy(local_124,local_32c,0xff);
              local_25 = 0;
              src = FS_Open(local_124,"rb");
              if (src == (FILE *)0x0) {
                Con_Printf("Error: couldn\'t open demo file %s for segment removal.\n",local_32c);
              }
              else {
                COM_StripExtension(local_32c,local_228);
                COM_AddExtension(local_228,".dm2",0x104);
                qVar3 = COM_HasFileExtension(local_32c,"dm2");
                if (qVar3 == false) {
                  Con_Printf("Error: couldn\'t open temporary file %s.\n",local_32c);
                  FS_Close(src);
                }
                else {
                  cls.demofile = FS_OpenPathID(local_228,"w+b","GAMECONFIG");
                  if (cls.demofile == (FileHandle_t)0x0) {
                    Con_Printf("Error: couldn\'t open %s.\n",local_32c);
                    FS_Close(src);
                  }
                  else {
                    FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
                    FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
                    FS_Read(&demoheader,0x220,1,src);
                    FS_Write(&demoheader,0x220,1,cls.demofile);
                    iVar4 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
                    if (iVar4 == 0) {
                      if ((demoheader.nNetProtocolVersion == 0x30) &&
                         (demoheader.nDemoProtocol == 5)) {
                        FS_Seek(src,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                        FS_Read(&demodir,4,1,src);
                        if (demodir.nEntries - 1U < 0x400) {
                          if (demodir.nEntries != 1) {
                            demodir.p_rgEntries = Mem_Malloc(demodir.nEntries * 0x5c);
                            FS_Read(demodir.p_rgEntries,demodir.nEntries * 0x5c,1,src);
                            local_334 = demodir.nEntries + -1;
                            local_330 = Mem_Malloc(local_334 * 0x5c);
                            iVar4 = 0;
                            for (iVar8 = 0; iVar8 < demodir.nEntries; iVar8 = iVar8 + 1) {
                              iVar6 = iVar4;
                              if (iVar8 != iVar1 + -1) {
                                iVar6 = iVar4 + 1;
                                pdVar7 = demodir.p_rgEntries + iVar8;
                                piVar10 = (int *)((int)local_330 + iVar4 * 0x5c);
                                pdVar9 = pdVar7;
                                piVar11 = piVar10;
                                for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
                                  *piVar11 = pdVar9->nEntryType;
                                  pdVar9 = (demoentry_t *)((int)pdVar9 + (uint)bVar12 * -8 + 4);
                                  piVar11 = piVar11 + (uint)bVar12 * -2 + 1;
                                }
                                uVar5 = FS_Tell(cls.demofile);
                                piVar10[0x15] = uVar5;
                                FS_Seek(src,pdVar7->nOffset,FILESYSTEM_SEEK_HEAD);
                                CL_DemoCopyFileChunk(cls.demofile,src,piVar10[0x16]);
                              }
                              iVar4 = iVar6;
                            }
                            demoheader.nDirectoryOffset = FS_Tell(cls.demofile);
                            FS_Write(&local_334,4,1,cls.demofile);
                            for (iVar1 = 0; iVar1 < local_334; iVar1 = iVar1 + 1) {
                              FS_Write((void *)(iVar1 * 0x5c + (int)local_330),0x5c,1,cls.demofile);
                            }
                            FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
                            FS_Write(&demoheader,0x220,1,cls.demofile);
                            FS_Close(cls.demofile);
                            cls.demofile = (FileHandle_t)0x0;
                            FS_Close(src);
                            Con_Printf("Replacing old demo with edited version.\n");
                            unlink(local_124);
                            rename(local_228,local_124);
                            Mem_Free(local_330);
                            Mem_Free(demodir.p_rgEntries);
                            demodir.p_rgEntries = (demoentry_t *)0x0;
                            demodir.nEntries = 0;
                            goto LAB_0013f93a;
                          }
                          Con_Printf("ERROR: Can\'t remove last directory entry.\n");
                        }
                        else {
                          Con_Printf("ERROR: demo had bogus # of directory entries:  %i\n",
                                     demodir.nEntries);
                        }
                      }
                      else {
                        Con_Printf("ERROR: demo protocol outdated\nDemo file protocols %iN:%iD\nServer protocol is at %iN:%iD\n"
                                   ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
                      }
                    }
                    else {
                      Con_Printf("%s is not a demo file\n",local_32c);
                    }
                    FS_Close(cls.demofile);
                    FS_Close(src);
                    cls.demofile = (FileHandle_t)0x0;
                  }
                }
              }
            }
          }
        }
        else {
          Con_Printf("Relative pathnames are not allowed.\n");
        }
      }
      else {
        Con_Printf("removedemo <demoname> <segment to remove>\nSegment 1 cannot be removed\n");
      }
    }
    else {
      Con_Printf("Removedemo only available when not running or recording a demo.\n");
    }
  }
LAB_0013f93a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_RemoveFromResourceList  @ 001557a0
void CL_RemoveFromResourceList(resource_t *pResource)

{
  resource_t *prVar1;
  
  if ((pResource->pPrev == (resource_s *)0x0) ||
     (prVar1 = pResource->pNext, prVar1 == (resource_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
  }
  if ((pResource != prVar1) && (pResource != pResource->pPrev)) {
    pResource->pPrev->pNext = prVar1;
    pResource->pNext->pPrev = pResource->pPrev;
    pResource->pPrev = (resource_s *)0x0;
    pResource->pNext = (resource_s *)0x0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Attempt to free last entry in list.");
}


// CL_RequestMissingResources  @ 00156a10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_RequestMissingResources(void)

{
  bool bVar1;
  
                    /* Unresolved local var: resource_t * p@[???] */
  if (cls.dl.doneregistering != false) {
    return false;
  }
  if ((cls.dl.custom == false) && (cls.state != ca_uninitialized)) {
    return false;
  }
  if (cl.resourcesneeded.pNext != &cl.resourcesneeded) {
    bVar1 = ((cl.resourcesneeded.pNext)->ucFlags & 2) == 0;
    if (bVar1) {
      CL_MoveToOnHandList(cl.resourcesneeded.pNext);
    }
    return (uint)bVar1;
  }
  cls.dl.custom = false;
  cls.dl.doneregistering = true;
  return false;
}


// CL_ResetEvent  @ 00138d50
void CL_ResetEvent(event_info_t *ei)

{
  ei->index = 0;
  Q_memset(&ei->args,0,0x48);
  ei->fire_time = 0.0;
  ei->flags = 0;
  return;
}


// CL_ResetFrame  @ 001581f0
void CL_ResetFrame(frame_t *frame)

{
  double dVar1;
  
  dVar1 = realtime;
  frame->clientbytes = 0;
  frame->receivedtime = dVar1;
  frame->packetentitybytes = 0;
  frame->tentitybytes = 0;
  frame->playerinfobytes = 0;
  frame->soundbytes = 0;
  frame->usrbytes = 0;
  frame->invalid = false;
  frame->latency = 0.0;
  frame->choked = false;
  frame->eventbytes = 0;
  frame->msgbytes = 0;
  frame->time = cl.mtime[0];
  return;
}


// CL_ResetFrameStats  @ 00133680
void CL_ResetFrameStats(frame_t *frame)

{
  frame->clientbytes = 0;
  frame->packetentitybytes = 0;
  frame->tentitybytes = 0;
  frame->playerinfobytes = 0;
  frame->soundbytes = 0;
  frame->usrbytes = 0;
  frame->eventbytes = 0;
  frame->voicebytes = 0;
  frame->msgbytes = 0;
  return;
}


// CL_ResetLatchedState  @ 00133060
void CL_ResetLatchedState(int pnum,packet_entities_t *pack,cl_entity_t_conflict2 *ent)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
                    /* Unresolved local var: int bytenum@[???]
                       Unresolved local var: int bitnum@[???] */
  if ((1 << ((byte)pnum & 7) & (uint)pack->flags[pnum >> 3]) != 0) {
    uVar1 = *(undefined4 *)&(ent->curstate).field_0x14;
    uVar2 = *(undefined4 *)&(ent->curstate).field_0x18;
    uVar3 = *(undefined4 *)&(ent->curstate).field_0x1c;
    uVar4 = *(undefined4 *)&(ent->curstate).field_0x20;
    uVar5 = *(undefined4 *)&(ent->curstate).field_0x24;
    *(undefined4 *)&(ent->latched).field_0xc = *(undefined4 *)&(ent->curstate).field_0x10;
    *(undefined4 *)&(ent->latched).field_0x10 = uVar1;
    *(undefined4 *)&(ent->latched).field_0x14 = uVar2;
    *(undefined4 *)&(ent->latched).field_0x18 = uVar3;
    *(undefined4 *)&(ent->latched).field_0x1c = uVar4;
    *(undefined4 *)&(ent->latched).field_0x20 = uVar5;
    R_ResetLatched((cl_entity_t *)ent,true);
    CL_ResetPositions((cl_entity_t *)ent);
                    /* Unresolved local var: int bytenum@[???]
                       Unresolved local var: int bitnum@[???] */
    if (((ent->curstate).starttime != 0.0) && ((ent->curstate).impacttime != 0.0)) {
      ent->lastmove = (float)cl.time;
      return;
    }
  }
  return;
}


// CL_ResetPositions  @ 0013cb80
void CL_ResetPositions(cl_entity_t *ent)

{
  int iVar1;
  uint uVar2;
  undefined4 local_28 [7];
  
                    /* Unresolved local var: position_history_t store@[???] */
  if (ent != (cl_entity_t *)0x0) {
    iVar1 = ent->current_position;
    uVar2 = 0;
    do {
      *(undefined4 *)((int)local_28 + uVar2) =
           *(undefined4 *)((int)ent->ph[iVar1].origin + (uVar2 - 4));
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x1c);
    ent->current_position = 1;
    Q_memset(ent->ph,0,0x700);
    Q_memcpy(ent->ph + 1,local_28,0x1c);
    Q_memcpy(ent->ph,local_28,0x1c);
  }
  return;
}


// CL_Restore  @ 00157c50
void CL_Restore(char *fileName)

{
  FileHandle_t stream;
  int iVar1;
  char *pcVar2;
  uint flags;
  int entity;
  int in_GS_OFFSET;
  int local_50;
  int local_4c;
  int local_48 [2];
  short local_40;
  undefined1 local_3e;
  byte local_3d;
  vec_t local_3c [3];
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: DECALLIST decalList@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int decalCount@[???]
                       Unresolved local var: int temp@[???]
                       Unresolved local var: int mapCount@[???]
                       Unresolved local var: FileHandle_t pFile@[???]
                       Unresolved local var: char[16] name@[???]
                       Unresolved local var: char * pMapName@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  stream = FS_Open(fileName,"rb");
  if (stream != (FileHandle_t)0x0) {
    FS_SetVBuf(stream,(char *)0x0,0,0x1000);
    FS_Read(local_48,4,1,stream);
    FS_Read(&local_50,4,1,stream);
    if (local_48[0] == 0x564c4156) {
      FS_Read(&local_4c,4,1,stream);
      local_50 = 0;
      if (0 < local_4c) {
        do {
          FS_Read(local_30,0x10,1,stream);
          FS_Read(&local_40,2,1,stream);
          FS_Read(&local_3e,1,1,stream);
          FS_Read(&local_3d,1,1,stream);
          FS_Read(local_3c,0xc,1,stream);
          if (r_decals.value != 0.0) {
            local_48[0] = Draw_DecalIndexFromName(local_30);
            flags = (uint)local_3d;
            entity = (int)local_40;
            iVar1 = Draw_DecalIndex(local_48[0]);
            R_DecalShoot(iVar1,entity,0,local_3c,flags);
          }
          local_50 = local_50 + 1;
        } while (local_50 < local_4c);
      }
    }
    FS_Close(stream);
  }
  iVar1 = MSG_ReadByte();
  local_50 = 0;
  if (0 < iVar1) {
    do {
      pcVar2 = MSG_ReadString();
      Con_Printf("Loading decals from %s\n",pcVar2);
      local_50 = local_50 + 1;
    } while (local_50 < iVar1);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Retry_f  @ 00144120
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Retry_f(void)

{
  int in_GS_OFFSET;
  undefined1 *puVar1;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] szCommand@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.passive == false) {
    puVar1 = &LAB_0026279a;
  }
  else {
    puVar1 = &LAB_002589a2;
  }
  __snprintf_chk(local_114,0x104,1,0x104,puVar1,0xdf87bc);
  Cbuf_AddText(local_114);
  Con_Printf("Commencing connection retry to %s\n",0xdf87bc);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Retry_f  @ 001441c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Retry_f(void)

{
  char *pcVar1;
  
                    /* Unresolved local var: char[260] szCommand@[???] */
  if (cls.servername[0] == '\0') {
    Con_Printf("Can\'t retry, no previous connection\n");
    return;
  }
  pcVar1 = strchr(cls.servername,10);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strchr(cls.servername,0x3b);
    if (pcVar1 == (char *)0x0) {
      CL_Retry_f();
      return;
    }
  }
  Con_Printf("Invalid command separator in server name, refusing retry\n");
  return;
}


// CL_RunUsercmd  @ 0013a700
void CL_RunUsercmd(local_state_t *from,local_state_t *to,usercmd_t *u,qboolean runfuncs,
                  double *pfElapsed,uint random_seed)

{
  vec_t vVar1;
  byte bVar2;
  float fVar3;
  playermove_t_conflict *ppVar4;
  int iVar5;
  uint uVar6;
  local_state_t *plVar7;
  local_state_t *plVar8;
  int in_GS_OFFSET;
  usercmd_s local_1984;
  local_state_t local_1950;
  int local_20;
  
                    /* Unresolved local var: usercmd_t cmd@[???]
                       Unresolved local var: entity_state_t * fs@[???]
                       Unresolved local var: entity_state_t * ts@[???]
                       Unresolved local var: clientdata_t * fcd@[???]
                       Unresolved local var: clientdata_t * tcd@[???] */
  ppVar4 = pmove;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar2 = u->msec;
  fVar3 = (float)bVar2;
  if (50.0 < fVar3) {
                    /* Unresolved local var: local_state_t temp@[???]
                       Unresolved local var: usercmd_t split@[???] */
    uVar6 = 0;
    do {
      *(undefined4 *)((int)local_1984.viewangles + (uVar6 - 4)) =
           *(undefined4 *)((int)u->viewangles + (uVar6 - 4));
      uVar6 = uVar6 + 4;
    } while (uVar6 < 0x34);
    local_1984.msec = (byte)(int)(fVar3 * 0.5);
    CL_RunUsercmd(from,&local_1950,&local_1984,runfuncs,pfElapsed,random_seed);
    local_1984.impulse = '\0';
    local_1984.weaponselect = '\0';
    CL_RunUsercmd(&local_1950,to,&local_1984,runfuncs,pfElapsed,random_seed);
  }
  else {
    uVar6 = 0;
    do {
      *(undefined4 *)((int)local_1984.viewangles + (uVar6 - 4)) =
           *(undefined4 *)((int)u->viewangles + (uVar6 - 4));
      uVar6 = uVar6 + 4;
    } while (uVar6 < 0x34);
    pmove->time = (float)*pfElapsed * 1000.0;
    ppVar4->server = false;
    iVar5 = cl.maxclients;
    ppVar4->runfuncs = runfuncs;
    ppVar4->multiplayer = (uint)(1 < iVar5);
    uVar6 = 0x1930;
    ppVar4->frametime = (float)bVar2 / 1000.0;
    plVar7 = from;
    plVar8 = to;
    if (((uint)to & 4) != 0) {
      plVar8 = (local_state_t *)&(to->playerstate).number;
      uVar6 = 0x192c;
      plVar7 = (local_state_t *)&(from->playerstate).number;
      (to->playerstate).entityType = (from->playerstate).entityType;
    }
    for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      (plVar8->playerstate).entityType = (plVar7->playerstate).entityType;
      plVar7 = (local_state_t *)&(plVar7->playerstate).number;
      plVar8 = (local_state_t *)&(plVar8->playerstate).number;
    }
    pmove->player_index = (from->playerstate).number + -1;
    ppVar4 = pmove;
    pmove->flags = (from->client).flags;
    ppVar4->bInDuck = (from->client).bInDuck;
    ppVar4->flTimeStepSound = (from->client).flTimeStepSound;
    ppVar4->flDuckTime = (float)(from->client).flDuckTime;
    ppVar4->flSwimTime = (float)(from->client).flSwimTime;
    ppVar4->waterjumptime = (float)(from->client).waterjumptime;
    ppVar4->waterlevel = (from->client).waterlevel;
    ppVar4->watertype = (from->client).watertype;
    ppVar4->onground = (from->client).flags & 0x200;
    ppVar4->deadflag = (from->client).deadflag;
    ppVar4->velocity[0] = (from->client).velocity[0];
    ppVar4->velocity[1] = (from->client).velocity[1];
    ppVar4->velocity[2] = (from->client).velocity[2];
    ppVar4->view_ofs[0] = (from->client).view_ofs[0];
    ppVar4->view_ofs[1] = (from->client).view_ofs[1];
    ppVar4->view_ofs[2] = (from->client).view_ofs[2];
    ppVar4->origin[0] = *(vec_t *)&(from->playerstate).field_0x10;
    ppVar4->origin[1] = *(vec_t *)&(from->playerstate).field_0x14;
    ppVar4->origin[2] = *(vec_t *)&(from->playerstate).field_0x18;
    ppVar4->basevelocity[0] = *(vec_t *)&(from->playerstate).field_0xbc;
    ppVar4->basevelocity[1] = *(vec_t *)&(from->playerstate).field_0xc0;
    ppVar4->basevelocity[2] = *(vec_t *)&(from->playerstate).field_0xc4;
    ppVar4->punchangle[0] = (from->client).punchangle[0];
    ppVar4->punchangle[1] = (from->client).punchangle[1];
    ppVar4->punchangle[2] = (from->client).punchangle[2];
    ppVar4->angles[0] = *(vec_t *)&(from->playerstate).field_0x1c;
    ppVar4->angles[1] = *(vec_t *)&(from->playerstate).field_0x20;
    ppVar4->angles[2] = *(vec_t *)&(from->playerstate).field_0x24;
    ppVar4->oldangles[0] = *(vec_t *)&(from->playerstate).field_0x1c;
    ppVar4->oldangles[1] = *(vec_t *)&(from->playerstate).field_0x20;
    ppVar4->oldangles[2] = *(vec_t *)&(from->playerstate).field_0x24;
    ppVar4->friction = (from->playerstate).friction;
    ppVar4->usehull = (from->playerstate).usehull;
    ppVar4->oldbuttons = (from->playerstate).oldbuttons;
    ppVar4->dead = (uint)(cl.stats[0] < 1);
    ppVar4->spectator = (uint)(cls.spectator != false);
    ppVar4->movetype = (from->playerstate).movetype;
    ppVar4->gravity = (from->playerstate).gravity;
    ppVar4->effects = (from->playerstate).effects;
    ppVar4->iStepLeft = (from->playerstate).iStepLeft;
    ppVar4->flFallVelocity = (from->playerstate).flFallVelocity;
    Q_strncpy(ppVar4->physinfo,cls.physinfo,0xff);
    ppVar4 = pmove;
    uVar6 = 0;
    pmove->maxspeed = movevars.maxspeed;
    ppVar4->physinfo[0xff] = '\0';
    ppVar4->clientmaxspeed = (from->client).maxspeed;
    do {
      *(undefined4 *)((int)(ppVar4->cmd).viewangles + (uVar6 - 4)) =
           *(undefined4 *)((int)local_1984.viewangles + (uVar6 - 4));
      uVar6 = uVar6 + 4;
    } while (uVar6 < 0x34);
    ppVar4->iuser1 = (from->client).iuser1;
    ppVar4->iuser2 = (from->client).iuser2;
    ppVar4->iuser3 = (from->client).iuser3;
    ppVar4->iuser4 = (from->client).iuser4;
    ppVar4->fuser1 = (from->client).fuser1;
    ppVar4->fuser2 = (from->client).fuser2;
    ppVar4->fuser3 = (from->client).fuser3;
    ppVar4->fuser4 = (from->client).fuser4;
    ppVar4->vuser1[0] = (from->client).vuser1[0];
    ppVar4->vuser1[1] = (from->client).vuser1[1];
    ppVar4->vuser1[2] = (from->client).vuser1[2];
    ppVar4->vuser2[0] = (from->client).vuser2[0];
    ppVar4->vuser2[1] = (from->client).vuser2[1];
    ppVar4->vuser2[2] = (from->client).vuser2[2];
    ppVar4->vuser3[0] = (from->client).vuser3[0];
    ppVar4->vuser3[1] = (from->client).vuser3[1];
    ppVar4->vuser3[2] = (from->client).vuser3[2];
    ppVar4->vuser4[0] = (from->client).vuser4[0];
    ppVar4->vuser4[1] = (from->client).vuser4[1];
    vVar1 = (from->client).vuser4[2];
    ppVar4->PM_PlaySound = PM_CL_PlaySound;
    ppVar4->PM_TraceTexture = PM_CL_TraceTexture;
    ppVar4->vuser4[2] = vVar1;
    ppVar4->PM_PlaybackEventFull = PM_CL_PlaybackEventFull;
    ClientDLL_MoveClient(ppVar4);
    ppVar4 = pmove;
    g_lastground = pmove->onground;
    if (0 < g_lastground) {
      g_lastground = pmove->physents[g_lastground].info;
    }
    (to->client).flags = pmove->flags;
    (to->client).bInDuck = ppVar4->bInDuck;
    (to->client).flTimeStepSound = ppVar4->flTimeStepSound;
    (to->client).flDuckTime = (int)ppVar4->flDuckTime;
    (to->client).flSwimTime = (int)ppVar4->flSwimTime;
    (to->client).waterjumptime = (int)ppVar4->waterjumptime;
    (to->client).waterlevel = ppVar4->waterlevel;
    (to->client).watertype = ppVar4->watertype;
    (to->client).maxspeed = ppVar4->clientmaxspeed;
    (to->client).deadflag = ppVar4->deadflag;
    (to->client).velocity[0] = ppVar4->velocity[0];
    (to->client).velocity[1] = ppVar4->velocity[1];
    (to->client).velocity[2] = ppVar4->velocity[2];
    (to->client).view_ofs[0] = ppVar4->view_ofs[0];
    (to->client).view_ofs[1] = ppVar4->view_ofs[1];
    (to->client).view_ofs[2] = ppVar4->view_ofs[2];
    *(vec_t *)&(to->playerstate).field_0x10 = ppVar4->origin[0];
    *(vec_t *)&(to->playerstate).field_0x14 = ppVar4->origin[1];
    *(vec_t *)&(to->playerstate).field_0x18 = ppVar4->origin[2];
    *(vec_t *)&(to->playerstate).field_0xbc = ppVar4->basevelocity[0];
    *(vec_t *)&(to->playerstate).field_0xc0 = ppVar4->basevelocity[1];
    *(vec_t *)&(to->playerstate).field_0xc4 = ppVar4->basevelocity[2];
    (to->client).punchangle[0] = ppVar4->punchangle[0];
    (to->client).punchangle[1] = ppVar4->punchangle[1];
    (to->client).punchangle[2] = ppVar4->punchangle[2];
    (to->playerstate).oldbuttons = (uint)(ppVar4->cmd).buttons;
    (to->playerstate).friction = ppVar4->friction;
    (to->playerstate).movetype = ppVar4->movetype;
    (to->playerstate).effects = ppVar4->effects;
    (to->playerstate).usehull = ppVar4->usehull;
    (to->playerstate).iStepLeft = ppVar4->iStepLeft;
    (to->playerstate).flFallVelocity = ppVar4->flFallVelocity;
    (to->client).iuser1 = ppVar4->iuser1;
    (to->client).iuser2 = ppVar4->iuser2;
    (to->client).iuser3 = ppVar4->iuser3;
    (to->client).iuser4 = ppVar4->iuser4;
    (to->client).fuser1 = ppVar4->fuser1;
    (to->client).fuser2 = ppVar4->fuser2;
    (to->client).fuser3 = ppVar4->fuser3;
    (to->client).fuser4 = ppVar4->fuser4;
    (to->client).vuser1[0] = ppVar4->vuser1[0];
    (to->client).vuser1[1] = ppVar4->vuser1[1];
    (to->client).vuser1[2] = ppVar4->vuser1[2];
    (to->client).vuser2[0] = ppVar4->vuser2[0];
    (to->client).vuser2[1] = ppVar4->vuser2[1];
    (to->client).vuser2[2] = ppVar4->vuser2[2];
    (to->client).vuser3[0] = ppVar4->vuser3[0];
    (to->client).vuser3[1] = ppVar4->vuser3[1];
    (to->client).vuser3[2] = ppVar4->vuser3[2];
    (to->client).vuser4[0] = ppVar4->vuser4[0];
    (to->client).vuser4[1] = ppVar4->vuser4[1];
    (to->client).vuser4[2] = ppVar4->vuser4[2];
    ClientDLL_PostRunCmd(from,to,&local_1984,runfuncs,*pfElapsed,random_seed);
    *pfElapsed = (double)((float)local_1984.msec / 1000.0 + (float)*pfElapsed);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Save  @ 000be7b0
/* WARNING: Type propagation algorithm not settling */

void CL_Save(char *name)

{
  vec_t *pInput;
  FileHandle_t file;
  short *pInput_00;
  int iVar1;
  int aiStack_14014 [2];
  DECALLIST aDStack_1400c [4096];
  
                    /* Unresolved local var: DECALLIST[4096] decalList@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int decalCount@[???]
                       Unresolved local var: int temp@[???]
                       Unresolved local var: FILE * pFile@[???] */
  aiStack_14014[0] = DecalListCreate(aDStack_1400c);
  file = FS_OpenPathID(name,"wb","GAMECONFIG");
  if (file != (FileHandle_t)0x0) {
    aiStack_14014[1] = 0x564c4156;
    FS_Write(aiStack_14014 + 1,4,1,file);
    aiStack_14014[1] = 0x71;
    FS_Write(aiStack_14014 + 1,4,1,file);
    FS_Write(aiStack_14014,4,1,file);
    if (0 < aiStack_14014[0]) {
      pInput_00 = &aDStack_1400c[0].entityIndex;
      iVar1 = 0;
      do {
        iVar1 = iVar1 + 1;
        FS_Write(((DECALLIST *)(pInput_00 + -2))->name,0x10,1,file);
        FS_Write(pInput_00,2,1,file);
        FS_Write(pInput_00 + 1,1,1,file);
        FS_Write((byte *)((int)pInput_00 + 3),1,1,file);
        pInput = (vec_t *)(pInput_00 + 2);
        pInput_00 = pInput_00 + 10;
        FS_Write(pInput,0xc,1,file);
      } while (iVar1 < aiStack_14014[0]);
    }
    FS_Close(file);
  }
  return;
}


// CL_SendConnectPacket  @ 001479b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SendConnectPacket(void)

{
  undefined2 uVar1;
  netadr_t to;
  _func_short_short *p_Var2;
  ushort usPortServer;
  int iVar3;
  qboolean qVar4;
  char *pcVar5;
  uint length;
  uint32 unIPServer;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  byte bVar9;
  double dVar10;
  netadr_t_conflict local_1538;
  char local_1524 [259];
  undefined1 local_1421;
  char local_1420 [1023];
  undefined1 local_1021;
  char local_1020 [1024];
  char local_c20;
  char acStack_c1f [1023];
  char local_820 [2048];
  int local_20;
  
                    /* Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: char[2048] data@[???]
                       Unresolved local var: char[260] szServerName@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: uchar[1024] buffer@[???]
                       Unresolved local var: int nCertificateSize@[???]
                       Unresolved local var: char[1024] protinfo@[???]
                       Unresolved local var: qboolean steam@[???]
                       Unresolved local var: char[1024] rgchSteam3LoginCookie@[???]
                       Unresolved local var: int cbLogonBlob@[???] */
  bVar9 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_1020,0,0x400);
  ContinueLoadingProgressBar("ClientConnect",1,0.0);
  if (fs_startup_timings.value != 0.0) {
    g_iCurrentTiming = 0;
    g_StartupTimings[0].name = "Startup";
    dVar10 = Sys_FloatTime();
    g_StartupTimings[0].time = (float)dVar10;
  }
  Q_strncpy(local_1524,cls.servername,0x104);
  local_1421 = 0;
  iVar3 = Q_stricmp(cls.servername,"local");
  if (iVar3 == 0) {
    builtin_strncpy(local_1524,"localhost",10);
  }
  qVar4 = NET_StringToAdr(local_1524,(netadr_t *)&local_1538);
  p_Var2 = BigShort;
  if (qVar4 == false) {
    Con_Printf("Unable to resolve %s\n",local_1524);
    cls.connect_time = -99999.0;
    cls.connect_retry = 0;
    cls.state = ca_disconnected;
    Q_memset(&g_GameServerAddress,0,0x14);
    goto LAB_00147c3e;
  }
  if (local_1538.port == 0) {
    iVar3 = Q_atoi("27015");
    local_1538.port = (*p_Var2)((short)iVar3);
  }
  if (cls.authprotocol == '\x02') {
LAB_00147aa0:
    pcVar5 = CL_GetCDKeyHash();
    Q_strlen(pcVar5);
    pcVar5 = CL_GetCDKeyHash();
    Q_strncpy(local_1420,pcVar5,0x3ff);
    local_1021 = 0;
    pcVar5 = va("%i",(uint)cls.authprotocol);
    Info_SetValueForKey(local_1020,"prot",pcVar5,0x400);
    Info_SetValueForKey(local_1020,"raw",local_1420,0x400);
    if (cls.authprotocol != '\x02') {
      pcVar5 = CL_GetCDKeyHash();
      Info_SetValueForKey(local_1020,"cdkey",pcVar5,0x400);
    }
    Q_memset(&local_c20,0,0x400);
    cls.connect_time = realtime;
    __snprintf_chk(local_820,0x800,1,0x800,0x265b30,0xff,0xff,0xff,0xff,0x30,cls.challenge,
                   local_1020,0xdf9100);
    length = Q_strlen(local_820);
  }
  else {
    if (cls.authprotocol != '\x03') {
      cls.authprotocol = '\x02';
      goto LAB_00147aa0;
    }
    pcVar5 = va("%i",3);
    Info_SetValueForKey(local_1020,"prot",pcVar5,0x400);
    pcVar5 = va("%i",0xffffffff);
    Info_SetValueForKey(local_1020,"unique",pcVar5,0x400);
    Info_SetValueForKey(local_1020,"raw","steam",0x400);
    if (cls.authprotocol != '\x02') {
      pcVar5 = CL_GetCDKeyHash();
      Info_SetValueForKey(local_1020,"cdkey",pcVar5,0x400);
    }
    pcVar5 = &local_c20;
    Q_memset(pcVar5,0,0x400);
                    /* Unresolved local var: uint unIP@[???]
                       Unresolved local var: ushort unPort@[???] */
    unIPServer = NET_NetAdr_GetIPNetworkByteOrder(&local_1538);
    usPortServer = local_1538.port;
    if (local_1538.type == NA_LOOPBACK) {
      unIPServer = htonl(0x7f000001);
    }
    uVar6 = Steam_GSInitiateGameConnection
                      (pcVar5,0x400,
                       CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID),
                       unIPServer,usPortServer,cls.isVAC2Secure);
    cls.connect_time = realtime;
    __snprintf_chk(local_820,0x800,1,0x800,0x265b30,0xff,0xff,0xff,0xff,0x30,cls.challenge,
                   local_1020,0xdf9100);
    iVar3 = Q_strlen(local_820);
    length = uVar6 + iVar3;
    if (0x800 < length) {
      Con_Printf("CL_SendConnectPacket:  Potential buffer overrun (%i/%i>%i) copying steamkeybuffer into connection packet\n"
                 ,iVar3,uVar6,0x800);
      CL_Disconnect();
      qVar4 = Host_IsServerActive();
      if (qVar4 != false) {
        Host_ShutdownServer(false);
      }
      goto LAB_00147c3e;
    }
    pcVar8 = local_820 + iVar3;
    if (uVar6 < 8) {
LAB_00147f12:
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar5;
        pcVar5 = pcVar5 + (uint)bVar9 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar9 * -2 + 1;
      }
    }
    else {
      pcVar7 = pcVar8;
      if (((uint)pcVar8 & 1) != 0) {
        pcVar7 = local_820 + iVar3 + 1;
        uVar6 = uVar6 - 1;
        pcVar5 = acStack_c1f;
        *pcVar8 = local_c20;
      }
      pcVar8 = pcVar7;
      if (((uint)pcVar7 & 2) != 0) {
        uVar1 = *(undefined2 *)pcVar5;
        pcVar8 = pcVar7 + 2;
        pcVar5 = pcVar5 + 2;
        uVar6 = uVar6 - 2;
        *(undefined2 *)pcVar7 = uVar1;
      }
      if (((uint)pcVar8 & 4) == 0) goto LAB_00147f12;
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar8 = pcVar8 + 4;
      for (iVar3 = uVar6 - 4; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pcVar8 = *pcVar5;
        pcVar5 = pcVar5 + (uint)bVar9 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar9 * -2 + 1;
      }
    }
  }
  g_GameServerAddress.type = local_1538.type;
  g_GameServerAddress.ip[0] = local_1538.ip[0];
  g_GameServerAddress.ip[1] = local_1538.ip[1];
  g_GameServerAddress.ip[2] = local_1538.ip[2];
  g_GameServerAddress.ip[3] = local_1538.ip[3];
  g_GameServerAddress.ipx[0] = local_1538.ipx[0];
  g_GameServerAddress.ipx[1] = local_1538.ipx[1];
  g_GameServerAddress.ipx[2] = local_1538.ipx[2];
  g_GameServerAddress.ipx[3] = local_1538.ipx[3];
  g_GameServerAddress.ipx[4] = local_1538.ipx[4];
  g_GameServerAddress.ipx[5] = local_1538.ipx[5];
  g_GameServerAddress.ipx[6] = local_1538.ipx[6];
  g_GameServerAddress.ipx[7] = local_1538.ipx[7];
  g_GameServerAddress.ipx[8] = local_1538.ipx[8];
  g_GameServerAddress.ipx[9] = local_1538.ipx[9];
  g_GameServerAddress.port = local_1538.port;
  to.ip[0] = local_1538.ip[0];
  to.ip[1] = local_1538.ip[1];
  to.ip[2] = local_1538.ip[2];
  to.ip[3] = local_1538.ip[3];
  to.type = local_1538.type;
  to.ipx[0] = (char)local_1538.ipx._0_2_;
  to.ipx[1] = (char)((ushort)local_1538.ipx._0_2_ >> 8);
  to.ipx[2] = (char)local_1538.ipx._2_2_;
  to.ipx[3] = (char)((ushort)local_1538.ipx._2_2_ >> 8);
  to.ipx[4] = local_1538.ipx[4];
  to.ipx[5] = local_1538.ipx[5];
  to.ipx[6] = local_1538.ipx[6];
  to.ipx[7] = local_1538.ipx[7];
  to.ipx[8] = local_1538.ipx[8];
  to.ipx[9] = local_1538.ipx[9];
  to.port = local_1538.port;
  NET_SendPacket(NS_CLIENT,length,local_820,to);
LAB_00147c3e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_SendConsistencyInfo  @ 00154fb0
void CL_SendConsistencyInfo(sizebuf_t *msg)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  qboolean qVar5;
  int *piVar6;
  int iVar7;
  int in_GS_OFFSET;
  CRC32_t local_254;
  float local_250;
  undefined4 local_24c;
  undefined4 local_248;
  float local_244;
  undefined4 local_240;
  undefined4 local_23c;
  uint32 local_238 [4];
  char local_228 [259];
  undefined1 local_125;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: consistency_t * pc@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: char[260] filename@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int savepos@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char[260] szSteamFilename@[???]
                       Unresolved local var: int iFileAvailable@[???]
                       Unresolved local var: int iRunningSteam@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = COM_CheckParm("-steam");
  if (cl.need_force_consistency_response != false) {
    cl.need_force_consistency_response = false;
    MSG_WriteByte(msg,7);
    iVar1 = msg->cursize;
    MSG_WriteShort(msg,0);
    MSG_StartBitWriting(msg);
    if (0 < cl.num_consistency) {
      piVar6 = &cl.consistency_list[0].value;
      iVar7 = 0;
                    /* Unresolved local var: qboolean user_changed_diskfile@[???] */
      do {
        MSG_WriteBits(1,1);
        MSG_WriteBits(piVar6[-1],0xc);
        if (piVar6[-2] == 0) {
          Q_strncpy(local_228,((consistency_t *)(piVar6 + -3))->filename,0x103);
          local_125 = 0;
          if (iVar2 != 0) goto LAB_0015516d;
LAB_001550d6:
          pcVar3 = strstr(local_228,"models/");
          if (pcVar3 != (char *)0x0) {
                    /* Unresolved local var: CRC32_t crcFile@[???] */
            CRC32_Init(&local_254);
            CRC_File(&local_254,local_228);
            local_254 = CRC32_Final(local_254);
            qVar5 = Mod_ValidateCRC(local_228,local_254);
            iVar4 = piVar6[1];
            if (iVar4 < 3) {
              if (iVar4 < 1) {
                if (iVar4 != 0) goto LAB_00155369;
                MD5_Hash_File((uchar *)local_238,local_228,0,0,(uint *)0x0);
                *piVar6 = local_238[0];
                if (qVar5 != false) goto LAB_00155208;
                MSG_WriteBits(0,0x20);
                goto LAB_001552f9;
              }
              iVar4 = R_GetStudioBounds(local_228,&local_250,&local_244);
            }
            else {
              if (iVar4 != 3) {
LAB_00155369:
                    /* WARNING: Subroutine does not return */
                Host_Error("Unknown consistency type %i\n",iVar4);
              }
              iVar4 = R_GetStudioBounds(local_228,&local_250,&local_244);
            }
            if (iVar4 == 0) goto LAB_00155124;
            if (qVar5 == false) {
              local_244 = 9999.9;
              local_240 = 0x461c3f9a;
              local_23c = 0x461c3f9a;
              local_250 = -9999.9;
              local_24c = 0xc61c3f9a;
              local_248 = 0xc61c3f9a;
            }
            goto LAB_001552cf;
          }
          iVar4 = piVar6[1];
          if (2 < iVar4) {
            if (iVar4 != 3) goto LAB_00155369;
LAB_00155104:
            iVar4 = R_GetStudioBounds(local_228,&local_250,&local_244);
            if (iVar4 == 0) {
LAB_00155124:
                    /* WARNING: Subroutine does not return */
              Host_Error("Unable to find %s\n",local_228);
            }
            goto LAB_001552cf;
          }
LAB_001550fb:
          if (0 < iVar4) goto LAB_00155104;
          if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
            Host_Error("Unknown consistency type %i\n",iVar4);
          }
LAB_001551e0:
          MD5_Hash_File((uchar *)local_238,local_228,0,0,(uint *)0x0);
          *piVar6 = local_238[0];
LAB_00155208:
          MSG_WriteBits(local_238[0],0x20);
        }
        else {
          __snprintf_chk(local_228,0x104,1,0x104,0x25de25,((consistency_t *)(piVar6 + -3))->filename
                        );
          if (iVar2 == 0) goto LAB_001550d6;
LAB_0015516d:
          snprintf(local_124,0x104,"%s",local_228);
          COM_FixSlashes(local_124);
          iVar4 = FS_FileExists(local_124);
          if (iVar4 != 0) goto LAB_001550d6;
          pcVar3 = strstr(local_228,"models/");
          if (pcVar3 == (char *)0x0) {
            iVar4 = piVar6[1];
            if (2 < iVar4) goto LAB_001553f0;
            goto LAB_001550fb;
          }
          iVar4 = piVar6[1];
          if (iVar4 < 3) {
            if (0 < iVar4) goto LAB_00155104;
            if (iVar4 != 0) goto LAB_00155369;
            goto LAB_001551e0;
          }
LAB_001553f0:
          if (iVar4 != 3) goto LAB_00155369;
          local_244 = -1.0;
          local_240 = 0xbf800000;
          local_23c = 0xbf800000;
          local_250 = -1.0;
          local_24c = 0xbf800000;
          local_248 = 0xbf800000;
LAB_001552cf:
          MSG_WriteBitData(&local_250,0xc);
          MSG_WriteBitData(&local_244,0xc);
        }
LAB_001552f9:
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 0xb;
      } while (iVar7 < cl.num_consistency);
    }
    MSG_WriteBits(0,1);
    MSG_EndBitWriting(msg);
    iVar2 = (msg->cursize - iVar1) + -2;
    *(short *)(msg->data + iVar1) = (short)iVar2;
    COM_Munge(msg->data + iVar1 + 2,iVar2,cl.servercount);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_SendKeepaliveToServer  @ 0014b6d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SendKeepaliveToServer(void)

{
  int iVar1;
  int in_GS_OFFSET;
  sizebuf_t local_44;
  byte local_30 [32];
  int local_10;
  
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte[32] szData@[???]
                       Unresolved local var: int iCount@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state != ca_disconnected) {
    local_44.data = local_30;
    local_44.cursize = 0;
    iVar1 = 0x20;
    local_44.buffername = "Client Keepalive";
    local_44.maxsize = 0x20;
    local_44.flags = 0;
    do {
      MSG_WriteByte(&local_44,1);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    Netchan_Transmit(&cls.netchan,local_44.cursize,local_44.data);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_SendRcon  @ 001446e0
void __regparm3 CL_SendRcon(netadr_t *to,uint challenge)

{
  int in_GS_OFFSET;
  undefined1 local_490 [1152];
  int local_10;
  
                    /* Unresolved local var: char[1152] message@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __snprintf_chk(local_490,0x480,1,0x480,0x264d0f,challenge,rcon_password.string,g_lastrconcommand);
  Netchan_OutOfBandPrint(NS_CLIENT,*to,"%s",local_490);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_SendRcon  @ 00145b50
void CL_SendRcon(netadr_t *to,uint challenge)

{
  netadr_t b;
  qboolean qVar1;
  
                    /* Unresolved local var: char[1152] message@[???] */
  if (g_lastrconcommand[0] == '\0') {
    Con_Printf("Rcon:  Empty rcon string\n");
    return;
  }
  b.ip = g_rconaddress.ip;
  b.type = g_rconaddress.type;
  b.ipx._0_4_ = g_rconaddress.ipx._0_4_;
  b.ipx._4_4_ = g_rconaddress.ipx._4_4_;
  b._16_4_ = g_rconaddress._16_4_;
  qVar1 = NET_CompareAdr(*to,b);
  if (qVar1 == false) {
    Con_Printf("Rcon:  Challenge from spoofed/invalid IP address\n");
    return;
  }
  CL_SendRcon(to,challenge);
  return;
}


// CL_SendResourceListBlock  @ 0014aa50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SendResourceListBlock(void)

{
  uchar *data;
  int iVar1;
  int iVar2;
  resource_t *s;
  int in_GS_OFFSET;
  sizebuf_t sStack_10024;
  byte abStack_10010 [65540];
  
                    /* Unresolved local var: int nStartIndex@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int arg@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: uchar[65536] buf@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  ContinueLoadingProgressBar("ClientConnect",6,0.0);
  Q_memset(&sStack_10024,0,0x14);
  sStack_10024.buffername = "Client to Server Resource Block";
  sStack_10024.data = abStack_10010;
  sStack_10024.cursize = 0;
  sStack_10024.maxsize = 0x10000;
  if (cls.state < ca_connecting) {
    Con_Printf("custom resource list not valid -- not connected\n");
  }
  else {
    iVar2 = MSG_ReadLong();
    if ((cls.demoplayback == false) && (iVar2 != cl.servercount)) {
      Con_Printf("CL_SendResourceListBlock_f from different level\n");
    }
    else {
      iVar2 = MSG_ReadLong();
      if ((iVar2 < 0) || (cl.num_resources < iVar2)) {
        Con_Printf("custom resource list request out of range\n");
      }
      else {
        MSG_WriteByte(&sStack_10024,5);
        MSG_WriteShort(&sStack_10024,cl.num_resources);
        if (iVar2 < cl.num_resources) {
          s = cl.resourcelist + iVar2;
          do {
            while( true ) {
              MSG_WriteString(&sStack_10024,s->szFileName);
              MSG_WriteByte(&sStack_10024,s->type);
              MSG_WriteShort(&sStack_10024,s->nIndex);
              MSG_WriteLong(&sStack_10024,s->nDownloadSize);
              MSG_WriteByte(&sStack_10024,(uint)s->ucFlags);
              if ((s->ucFlags & 4) == 0) break;
              data = s->rgucMD5_hash;
              iVar2 = iVar2 + 1;
              s = s + 1;
              SZ_Write(&sStack_10024,data,0x10);
              if (cl.num_resources <= iVar2) goto LAB_0014ac15;
            }
            iVar2 = iVar2 + 1;
            s = s + 1;
          } while (iVar2 < cl.num_resources);
        }
LAB_0014ac15:
        if (0 < sStack_10024.cursize) {
          Netchan_CreateFragments(false,&cls.netchan,&sStack_10024);
          Netchan_FragSend(&cls.netchan);
        }
      }
    }
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_Send_CvarValue  @ 00139c90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Send_CvarValue(void)

{
  uint uVar1;
  char *pcVar2;
  size_t sVar3;
  cvar_t *pcVar4;
  
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: cvar_t * cvar@[???] */
  pcVar2 = MSG_ReadString();
  MSG_WriteByte(&cls.netchan.message,10);
  sVar3 = strlen(pcVar2);
  if (sVar3 < 0xff) {
    pcVar4 = Cvar_FindVar(pcVar2);
    if (pcVar4 != (cvar_t *)0x0) {
                    /* Unresolved local var: char * strFailureMessage@[???] */
      uVar1 = pcVar4->flags;
      if ((uVar1 & 0x400) == 0) {
        if ((uVar1 & 4) == 0) {
          if ((uVar1 & 0x20) == 0) {
            pcVar2 = pcVar4->string;
          }
          else {
            pcVar2 = "CVAR is protected";
          }
        }
        else {
          pcVar2 = "CVAR is server-only";
        }
      }
      else {
        pcVar2 = "CVAR is privileged";
      }
      MSG_WriteString(&cls.netchan.message,pcVar2);
      return;
    }
  }
  MSG_WriteString(&cls.netchan.message,"Bad CVAR request");
  return;
}


// CL_Send_CvarValue2  @ 00139d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Send_CvarValue2(void)

{
  uint uVar1;
  int c;
  char *pcVar2;
  size_t sVar3;
  cvar_t *pcVar4;
  
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: cvar_t * cvar@[???]
                       Unresolved local var: int requestID@[???] */
  c = MSG_ReadLong();
  pcVar2 = MSG_ReadString();
  MSG_WriteByte(&cls.netchan.message,0xb);
  MSG_WriteLong(&cls.netchan.message,c);
  MSG_WriteString(&cls.netchan.message,pcVar2);
  sVar3 = strlen(pcVar2);
  if (sVar3 < 0xff) {
    pcVar4 = Cvar_FindVar(pcVar2);
    if (pcVar4 != (cvar_t *)0x0) {
                    /* Unresolved local var: char * strFailureMessage@[???] */
      uVar1 = pcVar4->flags;
      if ((uVar1 & 0x400) == 0) {
        if ((uVar1 & 4) == 0) {
          if ((uVar1 & 0x20) == 0) {
            pcVar2 = pcVar4->string;
          }
          else {
            pcVar2 = "CVAR is protected";
          }
        }
        else {
          pcVar2 = "CVAR is server-only";
        }
      }
      else {
        pcVar2 = "CVAR is privileged";
      }
      MSG_WriteString(&cls.netchan.message,pcVar2);
      return;
    }
  }
  MSG_WriteString(&cls.netchan.message,"Bad CVAR request");
  return;
}


// CL_ServiceChallenge  @ 00145c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ServiceChallenge(void)

{
  netadr_t a;
  netadr_t b;
  int iVar1;
  char *pcVar2;
  uint challenge;
  qboolean qVar3;
  
                    /* Unresolved local var: char * type@[???]
                       Unresolved local var: char * value@[???]
                       Unresolved local var: uint val@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      iVar1 = Q_stricmp(pcVar2,"rcon");
      if (iVar1 == 0) {
                    /* Unresolved local var: char * type@[???]
                       Unresolved local var: char * value@[???]
                       Unresolved local var: uint val@[???] */
        pcVar2 = Cmd_Argv(2);
        challenge = Q_atoi(pcVar2);
                    /* Unresolved local var: char[1152] message@[???] */
        if (g_lastrconcommand[0] == '\0') {
          Con_Printf("Rcon:  Empty rcon string\n");
        }
        else {
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
          b.ip[0] = g_rconaddress.ip[0];
          b.ip[1] = g_rconaddress.ip[1];
          b.ip[2] = g_rconaddress.ip[2];
          b.ip[3] = g_rconaddress.ip[3];
          b.type = g_rconaddress.type;
          b.ipx[0] = g_rconaddress.ipx[0];
          b.ipx[1] = g_rconaddress.ipx[1];
          b.ipx[2] = g_rconaddress.ipx[2];
          b.ipx[3] = g_rconaddress.ipx[3];
          b.ipx[4] = g_rconaddress.ipx[4];
          b.ipx[5] = g_rconaddress.ipx[5];
          b.ipx[6] = g_rconaddress.ipx[6];
          b.ipx[7] = g_rconaddress.ipx[7];
          b.ipx[8] = g_rconaddress.ipx[8];
          b.ipx[9] = g_rconaddress.ipx[9];
          b.port = g_rconaddress.port;
          qVar3 = NET_CompareAdr(a,b);
          if (qVar3 != false) {
            CL_SendRcon(&net_from,challenge);
            return;
          }
          Con_Printf("Rcon:  Challenge from spoofed/invalid IP address\n");
        }
      }
    }
  }
  return;
}


// CL_ServiceGet  @ 00145e80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ServiceGet(void)

{
  netadr_t a;
  int iVar1;
  char *s2;
  cvar_t *pcVar2;
  char *pcVar3;
  char *format;
  
                    /* Unresolved local var: char * var@[???]
                       Unresolved local var: cvar_t * cv@[???] */
  if ((net_from.type != NA_IP) || (net_from.ip != (uchar  [4])((int)lightmaps + 0x4903f))) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    return;
  }
  s2 = Cmd_Argv(1);
  if (s2 == (char *)0x0) {
    return;
  }
  if (*s2 == '\0') {
    return;
  }
  iVar1 = Q_stricmp("clientaddress",s2);
  if (iVar1 == 0) {
    pcVar3 = cls.trueaddress;
  }
  else {
    iVar1 = Q_stricmp("serveraddress",s2);
    if (iVar1 == 0) {
      a.ip[0] = cls.netchan.remote_address.ip[0];
      a.ip[1] = cls.netchan.remote_address.ip[1];
      a.ip[2] = cls.netchan.remote_address.ip[2];
      a.ip[3] = cls.netchan.remote_address.ip[3];
      a.type = cls.netchan.remote_address.type;
      a.ipx[0] = cls.netchan.remote_address.ipx[0];
      a.ipx[1] = cls.netchan.remote_address.ipx[1];
      a.ipx[2] = cls.netchan.remote_address.ipx[2];
      a.ipx[3] = cls.netchan.remote_address.ipx[3];
      a.ipx[4] = cls.netchan.remote_address.ipx[4];
      a.ipx[5] = cls.netchan.remote_address.ipx[5];
      a.ipx[6] = cls.netchan.remote_address.ipx[6];
      a.ipx[7] = cls.netchan.remote_address.ipx[7];
      a.ipx[8] = cls.netchan.remote_address.ipx[8];
      a.ipx[9] = cls.netchan.remote_address.ipx[9];
      a.port = cls.netchan.remote_address.port;
      pcVar3 = NET_AdrToString(a);
    }
    else {
      iVar1 = Q_stricmp("userid",s2);
      if (iVar1 == 0) {
        format = "%i";
        pcVar3 = (char *)cls.userid;
        goto LAB_00145f1d;
      }
      pcVar2 = Cvar_FindVar(s2);
      if (pcVar2 == (cvar_t *)0x0) {
        CL_CreateResponse(&net_from,s2,"unknown variable");
        return;
      }
      pcVar3 = pcVar2->string;
    }
  }
  format = "%s";
LAB_00145f1d:
  pcVar3 = va(format,pcVar3);
  CL_CreateResponse(&net_from,s2,pcVar3);
  return;
}


// CL_SetDemoInfo_f  @ 0013f0b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetDemoInfo_f(void)

{
  demoentry_t *pdVar1;
  demoentry_t *pdVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  qboolean qVar6;
  FILE *src;
  uint nSize;
  int iVar7;
  int iVar8;
  int in_GS_OFFSET;
  int local_338;
  char local_32c [260];
  char local_228 [260];
  char local_124 [255];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: int nSegment@[???]
                       Unresolved local var: demoentry_t * newentry@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bDone@[???]
                       Unresolved local var: int nCurArg@[???]
                       Unresolved local var: char * pFlag@[???]
                       Unresolved local var: char * pValue@[???]
                       Unresolved local var: char * pDirection@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source != src_command) goto LAB_0013f0ea;
  if ((cls.demorecording != false) || (cls.demoplayback != false)) {
    Con_Printf("Setdemoinfo only available when not running or recording a demo.\n");
    goto LAB_0013f0ea;
  }
  iVar3 = Cmd_Argc();
  if (iVar3 < 3) {
    Con_Printf("Setdemoinfo <demoname> <seg#> <info ...>\n");
    Con_Printf("   title \"text\"\n");
    Con_Printf("   play tracknum\n");
    Con_Printf("   fade <in | out> <fast | slow>\n\n");
    Con_Printf("Use -option to disable, e.g., -title\n");
    goto LAB_0013f0ea;
  }
  pcVar4 = Cmd_Argv(1);
  pcVar4 = Q_strstr(pcVar4,"..");
  if (pcVar4 != (char *)0x0) {
    Con_Printf("Relative pathnames are not allowed.\n");
    goto LAB_0013f0ea;
  }
  pcVar4 = Cmd_Argv(2);
  iVar3 = Q_atoi(pcVar4);
  if (iVar3 < 2) {
    Con_Printf("Cannot Setdemoinfo the STARTUP segment.\n");
    goto LAB_0013f0ea;
  }
  pcVar4 = local_32c;
  pcVar5 = Cmd_Argv(1);
  snprintf(pcVar4,0x100,"%s",pcVar5);
  COM_DefaultExtension(pcVar4,".dem");
  qVar6 = COM_HasFileExtension(pcVar4,"dem");
  if (qVar6 == false) {
    Con_Printf("Error: couldn\'t open file %s, demo files must have .dem extension.\n",pcVar4);
    goto LAB_0013f0ea;
  }
  Con_Printf("Setting info for segment %i in demo %s.\n",iVar3,pcVar4);
  Q_strncpy(local_124,pcVar4,0xff);
  local_25 = 0;
  src = FS_Open(local_124,"rb");
  if (src == (FILE *)0x0) {
    Con_Printf("Error: couldn\'t open demo file %s for Setdemoinfo.\n",pcVar4);
    goto LAB_0013f0ea;
  }
  COM_StripExtension(pcVar4,local_228);
  COM_AddExtension(local_228,".dm2",0x104);
  qVar6 = COM_HasFileExtension(local_228,"dm2");
  if (qVar6 == false) {
    Con_Printf("Error: couldn\'t open temporary file %s.\n",local_228);
    FS_Close(src);
  }
  cls.demofile = FS_OpenPathID(local_228,"w+b","GAMECONFIG");
  if (cls.demofile == (FileHandle_t)0x0) {
    Con_Printf("Error: couldn\'t open %s.\n",pcVar4);
    FS_Close(src);
    goto LAB_0013f0ea;
  }
  FS_Seek(src,0,FILESYSTEM_SEEK_TAIL);
  nSize = FS_Tell(src);
  FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  CL_DemoCopyFileChunk(cls.demofile,src,nSize);
  FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  FS_Read(&demoheader,0x220,1,src);
  iVar7 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
  if (iVar7 == 0) {
    if ((demoheader.nNetProtocolVersion == 0x30) && (demoheader.nDemoProtocol == 5)) {
      FS_Seek(src,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
      FS_Read(&demodir,4,1,src);
      if (demodir.nEntries - 1U < 0x400) {
        iVar3 = iVar3 + -1;
        demodir.p_rgEntries = Mem_Malloc(demodir.nEntries * 0x5c);
        FS_Read(demodir.p_rgEntries,demodir.nEntries * 0x5c,1,src);
        pdVar2 = demodir.p_rgEntries;
        local_338 = 3;
        pdVar1 = demodir.p_rgEntries + iVar3;
LAB_0013f59a:
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  pcVar4 = Cmd_Argv(local_338);
                  if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) goto LAB_0013f5ea;
                  iVar7 = local_338 + 1;
                  iVar8 = Q_stricmp(pcVar4,"-TITLE");
                  if (iVar8 != 0) break;
                  pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags & 0xfffffffe;
                  local_338 = iVar7;
                }
                iVar8 = Q_stricmp(pcVar4,"-PLAY");
                if (iVar8 != 0) break;
                pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags & 0xfffffffb;
                local_338 = iVar7;
              }
              iVar8 = Q_stricmp(pcVar4,"-FADE");
              if (iVar8 != 0) break;
              pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags & 0xffffff87;
              local_338 = iVar7;
            }
            iVar8 = Q_stricmp(pcVar4,"TITLE");
            if (iVar8 != 0) break;
            pcVar4 = Cmd_Argv(iVar7);
            if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
              Con_Printf("Title flag requires a double-quoted value.\n");
              local_338 = local_338 + 2;
            }
            else {
              Q_strncpy(pdVar1->szDescription,pcVar4,0x3f);
              pdVar2[iVar3].szDescription[0x3f] = '\0';
              pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 1;
              local_338 = local_338 + 2;
            }
          }
          iVar8 = Q_stricmp(pcVar4,"PLAY");
          if (iVar8 != 0) break;
          pcVar4 = Cmd_Argv(iVar7);
          if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
            Con_Printf("Play flag requires a cd track #.\n");
            local_338 = local_338 + 2;
          }
          else {
            iVar7 = Q_atoi(pcVar4);
            pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 4;
            pdVar2[iVar3].nCDTrack = iVar7;
            local_338 = local_338 + 2;
          }
        }
        iVar8 = Q_stricmp(pcVar4,"FADE");
        if (iVar8 == 0) {
          pcVar4 = Cmd_Argv(iVar7);
          iVar7 = local_338 + 2;
          if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
            iVar8 = Q_stricmp(pcVar4,"IN");
            if (iVar8 == 0) {
              pcVar4 = Cmd_Argv(iVar7);
              if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
                iVar7 = Q_stricmp(pcVar4,"FAST");
                if (iVar7 == 0) {
                  pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 0x10;
                  local_338 = local_338 + 3;
                  goto LAB_0013f59a;
                }
                iVar7 = Q_stricmp(pcVar4,"SLOW");
                if (iVar7 == 0) {
                  pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 8;
                  local_338 = local_338 + 3;
                  goto LAB_0013f59a;
                }
              }
            }
            else {
              iVar8 = Q_stricmp(pcVar4,"OUT");
              if (iVar8 != 0) {
                Con_Printf("Fade flag requires a direction (in or out).\n");
                local_338 = iVar7;
                goto LAB_0013f59a;
              }
              pcVar4 = Cmd_Argv(iVar7);
              if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
                iVar7 = Q_stricmp(pcVar4,"FAST");
                if (iVar7 == 0) {
                  pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 0x40;
                  local_338 = local_338 + 3;
                  goto LAB_0013f59a;
                }
                iVar7 = Q_stricmp(pcVar4,"SLOW");
                if (iVar7 == 0) {
                  pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 0x20;
                  local_338 = local_338 + 3;
                  goto LAB_0013f59a;
                }
              }
            }
            Con_Printf("Fade flag requires a speed (fast or slow).\n");
            local_338 = local_338 + 3;
            goto LAB_0013f59a;
          }
          Con_Printf("Fade flag requires a direction and speed (in fast, e.g.)\n");
          local_338 = iVar7;
          goto LAB_0013f59a;
        }
        Con_Printf("Setdemoinfo, unrecognized flag:  %s\n",pcVar4);
LAB_0013f5ea:
        FS_Seek(cls.demofile,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
        FS_Write(&demodir,4,1,cls.demofile);
        for (iVar3 = 0; iVar3 < demodir.nEntries; iVar3 = iVar3 + 1) {
          FS_Write(demodir.p_rgEntries + iVar3,0x5c,1,cls.demofile);
        }
        FS_Close(cls.demofile);
        cls.demofile = (FileHandle_t)0x0;
        FS_Close(src);
        Con_Printf("Replacing old demo with edited version.\n");
        unlink(local_124);
        rename(local_228,local_124);
        Mem_Free(demodir.p_rgEntries);
        demodir.p_rgEntries = (demoentry_t *)0x0;
        demodir.nEntries = 0;
        goto LAB_0013f0ea;
      }
      pcVar5 = "ERROR: demo had bogus # of directory entries:  %i\n";
      pcVar4 = (char *)demodir.nEntries;
      goto LAB_0013f4b0;
    }
    Con_Printf("ERROR: demo protocol outdated\nDemo file protocols %iN:%iD\nServer protocol is at %iN:%iD\n"
               ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
  }
  else {
    pcVar5 = "%s is not a demo file\n";
LAB_0013f4b0:
    Con_Printf(pcVar5,pcVar4);
  }
  FS_Close(cls.demofile);
  FS_Close(src);
  unlink(local_228);
  cls.demofile = (FileHandle_t)0x0;
LAB_0013f0ea:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_SetDemoViewInfo  @ 0013de60
void CL_SetDemoViewInfo(ref_params_t *rp,vec_t *view,int viewmodel)

{
  undefined4 uVar1;
  usercmd_s *puVar2;
  movevars_s *pmVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    uVar1 = *(undefined4 *)((int)rp->vieworg + uVar5);
    uVar4 = uVar5 + 8;
    *(undefined4 *)((int)g_rp.rp.vieworg + uVar5 + 4) =
         *(undefined4 *)((int)rp->vieworg + uVar5 + 4);
    *(undefined4 *)((int)g_rp.rp.vieworg + uVar5) = uVar1;
    uVar5 = uVar4;
  } while (uVar4 < 0xe8);
  g_rp.rp.cmd = &g_rp.cmd;
  g_rp.rp.movevars = &g_rp.movevars;
  puVar2 = rp->cmd;
  uVar5 = 0;
  do {
    uVar4 = uVar5 + 4;
    *(undefined4 *)((int)g_rp.cmd.viewangles + (uVar5 - 4)) =
         *(undefined4 *)((int)puVar2->viewangles + (uVar5 - 4));
    uVar5 = uVar4;
  } while (uVar4 < 0x34);
  pmVar3 = rp->movevars;
  uVar5 = 0;
  do {
    uVar4 = uVar5;
    uVar1 = *(undefined4 *)(pmVar3->skyName + (uVar4 - 0x44));
    *(undefined4 *)(g_rp.movevars.skyName + (uVar4 - 0x40)) =
         *(undefined4 *)(pmVar3->skyName + (uVar4 - 0x40));
    *(undefined4 *)(g_rp.movevars.skyName + (uVar4 - 0x44)) = uVar1;
    uVar5 = uVar4 + 8;
  } while (uVar4 + 8 < 0x80);
  *(undefined4 *)(g_rp.movevars.skyName + (uVar4 - 0x3c)) =
       *(undefined4 *)(pmVar3->skyName + (uVar4 - 0x3c));
  g_rp.view[0] = *view;
  g_rp.view[1] = view[1];
  g_rp.view[2] = view[2];
  g_rp.viewmodel = viewmodel;
  return;
}


// CL_SetDevOverView  @ 0013d9d0
void CL_SetDevOverView(refdef_t_conflict *refdef)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  qboolean qVar5;
  
  fVar2 = gDevOverview.origin[0] - cl.cmd.sidemove * 0.0078125;
  fVar3 = gDevOverview.origin[1] - cl.cmd.forwardmove * 0.0078125;
  if (0.0 < cl.cmd.upmove) {
    gDevOverview.z_min = gDevOverview.z_min + 1.0;
  }
  if (cl.cmd.upmove < 0.0) {
    gDevOverview.z_min = gDevOverview.z_min - 1.0;
  }
  if ((cl.cmd.buttons & 4) != 0) {
    gDevOverview.z_max = gDevOverview.z_max - 1.0;
  }
  if ((cl.cmd.buttons & 2) != 0) {
    gDevOverview.z_max = gDevOverview.z_max + 1.0;
  }
  if ((cl.cmd.buttons & 1) != 0) {
    gDevOverview.zoom = gDevOverview.zoom + 0.01;
  }
  if ((cl.cmd.buttons & 0x800) != 0) {
    gDevOverview.zoom = gDevOverview.zoom - 0.01;
  }
  gDevOverview.origin[0] = fVar2;
  gDevOverview.origin[1] = fVar3;
  refdef->vieworg[0] = fVar2;
  refdef->vieworg[1] = fVar3;
  refdef->onlyClientDraws = false;
  qVar5 = gDevOverview.rotated;
  vVar4 = gDevOverview.origin[2];
  refdef->vieworg[2] = 16000.0;
  refdef->viewangles[0] = 90.0;
  vVar1 = 90.0;
  if (qVar5 == false) {
    vVar1 = 0.0;
  }
  refdef->viewangles[1] = vVar1;
  refdef->viewangles[2] = 0.0;
  if (dev_overview.value < 2.0) {
    Con_Printf(" Overview: Zoom %.2f, Map Origin (%.2f, %.2f, %.2f), Z Min %.2f, Z Max %.2f, Rotated %i\n"
               ,(double)gDevOverview.zoom,(double)fVar2,(double)fVar3,(double)vVar4,
               (double)gDevOverview.z_min,(double)gDevOverview.z_max,qVar5);
  }
  return;
}


// CL_SetIdealPitch  @ 0013aff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetIdealPitch(void)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double local_ac;
  double local_a4 [2];
  float local_90;
  float local_8c;
  float local_88;
  float local_84 [9];
  pmtrace_t local_60;
  
                    /* Unresolved local var: float angleval@[???]
                       Unresolved local var: float sinval@[???]
                       Unresolved local var: float cosval@[???]
                       Unresolved local var: vec3_t top@[???]
                       Unresolved local var: vec3_t bottom@[???]
                       Unresolved local var: float[6] z@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int step@[???]
                       Unresolved local var: int dir@[???]
                       Unresolved local var: int steps@[???]
                       Unresolved local var: pmtrace_t tr@[???] */
  if (cl.onground == -1) {
    return;
  }
  iVar5 = 3;
  sincos((double)((cl.simangles[1] * 3.1415927 + cl.simangles[1] * 3.1415927) / 360.0),local_a4,
         &local_ac);
  do {
    local_90 = (float)local_ac * (float)iVar5 * 12.0 + cl.simorg[0];
    local_8c = (float)iVar5 * (float)local_a4[0] * 12.0 + cl.simorg[1];
    local_88 = cl.simorg[2] + cl.viewheight[2];
    local_84[2] = local_88 - 160.0;
    local_84[0] = local_90;
    local_84[1] = local_8c;
    PM_PlayerTrace(&local_60,&local_90,local_84,2,-1);
    if (local_60.allsolid != false) {
      return;
    }
    if (local_60.fraction == 1.0) {
      return;
    }
    local_84[iVar5] = (local_84[2] - local_88) * local_60.fraction + local_88;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 9);
  iVar5 = (int)(local_84[4] - local_84[3]);
  if (((double)iVar5 <= -0.1) || (0.1 <= (double)iVar5)) {
    uVar2 = 1;
    iVar4 = (int)(local_84[5] - local_84[4]);
    dVar1 = (double)iVar4;
    iVar3 = iVar5;
    if (-0.1 < dVar1) goto LAB_0013b1b0;
LAB_0013b1f1:
    iVar5 = iVar4;
    if (iVar3 != 0) {
      if (0.1 < (double)(iVar5 - iVar3)) {
        return;
      }
      if ((double)(iVar5 - iVar3) < -0.1) {
        return;
      }
    }
  }
  else {
    uVar2 = 0;
    iVar5 = (int)(local_84[5] - local_84[4]);
    dVar1 = (double)iVar5;
    if (-0.1 < dVar1) {
      uVar2 = 0;
      iVar4 = iVar5;
      iVar5 = 0;
LAB_0013b1b0:
      iVar3 = iVar5;
      if (dVar1 < 0.1) goto LAB_0013b231;
      goto LAB_0013b1f1;
    }
  }
  uVar2 = uVar2 + 1;
LAB_0013b231:
  iVar4 = (int)(local_84[6] - local_84[5]);
  if (((double)iVar4 <= -0.1) || (0.1 <= (double)iVar4)) {
    if (iVar5 != 0) {
      if (0.1 < (double)(iVar4 - iVar5)) {
        return;
      }
      if ((double)(iVar4 - iVar5) < -0.1) {
        return;
      }
    }
    uVar2 = uVar2 + 1;
    iVar5 = iVar4;
  }
  iVar4 = (int)(local_84[7] - local_84[6]);
  if (((double)iVar4 <= -0.1) || (0.1 <= (double)iVar4)) {
    if (iVar5 != 0) {
      if (0.1 < (double)(iVar4 - iVar5)) {
        return;
      }
      if ((double)(iVar4 - iVar5) < -0.1) {
        return;
      }
    }
    uVar2 = uVar2 + 1;
    iVar5 = iVar4;
  }
  iVar4 = (int)(local_84[8] - local_84[7]);
  if (((double)iVar4 <= -0.1) || (0.1 <= (double)iVar4)) {
    if (iVar5 != 0) {
      if (0.1 < (double)(iVar4 - iVar5)) {
        return;
      }
      if ((double)(iVar4 - iVar5) < -0.1) {
        return;
      }
    }
    uVar2 = uVar2 + 1;
    iVar5 = iVar4;
  }
  if (iVar5 == 0) {
    cl.idealpitch = 0.0;
  }
  else if (1 < uVar2) {
    cl.idealpitch = (float)-iVar5 * cl_idealpitchscale.value;
  }
  return;
}


// CL_SetLastUpdate  @ 0013bed0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetLastUpdate(void)

{
  g_lastupdate_sequence = cls.netchan.incoming_sequence;
  return;
}


// CL_SetPacketFlag  @ 00133640
void CL_SetPacketFlag(packet_entities_t *pack,int index,int flag)

{
  byte bVar1;
  
  bVar1 = (byte)(1 << ((byte)index & 7));
  if (flag == 0) {
    pack->flags[index >> 3] = pack->flags[index >> 3] & ~bVar1;
    return;
  }
  pack->flags[index >> 3] = pack->flags[index >> 3] | bVar1;
  return;
}


// CL_SetSolidEntities  @ 00135d10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetSolidEntities(void)

{
  entity_state_s *state;
  undefined4 uVar1;
  int iVar2;
  vec_t vVar3;
  vec_t vVar4;
  int iVar5;
  playermove_t_conflict *ppVar6;
  model_t *pmVar7;
  model_t *pmVar8;
  physent_t_conflict1 *pe;
  uint uVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: packet_entities_t * pak@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: physent_t.conflict1 * pe@[???]
                       Unresolved local var: physent_t.conflict1 * ve@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: model_t.conflict * model@[???] */
  pmove = &g_clmove;
  Q_memset(g_clmove.physents,0,0xe0);
  Q_memset(pmove->visents,0,0xe0);
  ppVar6 = pmove;
  pmove->physents[0].model = cl.worldmodel;
  if (cl.worldmodel != (model_s *)0x0) {
    Q_strncpy(ppVar6->physents[0].name,(cl.worldmodel)->name,0x20);
    ppVar6 = pmove;
    pmove->physents[0].name[0x1f] = '\0';
  }
  vVar4 = vec3_origin[2];
  vVar3 = vec3_origin[1];
  ppVar6->physents[0].origin[0] = vec3_origin[0];
  ppVar6->physents[0].origin[1] = vVar3;
  ppVar6->physents[0].origin[2] = vVar4;
  ppVar6->physents[0].info = 0;
  ppVar6->numphysent = 1;
  uVar9 = 0;
  ppVar6->physents[0].solid = 4;
  ppVar6->physents[0].movetype = 0;
  ppVar6->physents[0].takedamage = 1;
  ppVar6->physents[0].blooddecal = 0;
  ppVar6->numvisent = 1;
  do {
    uVar1 = *(undefined4 *)(ppVar6->physents[0].name + uVar9 + 4);
    *(undefined4 *)(ppVar6->visents[0].name + uVar9) =
         *(undefined4 *)(ppVar6->physents[0].name + uVar9);
    *(undefined4 *)(ppVar6->visents[0].name + uVar9 + 4) = uVar1;
    uVar9 = uVar9 + 8;
  } while (uVar9 < 0xe0);
  iVar11 = 0;
  ppVar6->nummoveent = 0;
  iVar5 = cl.parsecountmod;
  iVar10 = cl.frames[cl.parsecountmod].packet_entities.num_entities;
  if (0 < iVar10) {
    do {
      while( true ) {
        state = cl.frames[iVar5].packet_entities.entities + iVar11;
        if (((0 < state->number) && (state->number <= cl.maxclients)) || (state->modelindex == 0))
        goto LAB_00135e70;
        pmVar7 = CL_GetModelByIndex(state->modelindex);
        ppVar6 = pmove;
        if ((pmVar7 != (model_t *)0x0) &&
           ((state->owner == 0 || (state->owner + -1 != cl.playernum)))) break;
LAB_00135f00:
        iVar10 = cl.frames[iVar5].packet_entities.num_entities;
        iVar11 = iVar11 + 1;
        if (iVar10 <= iVar11) {
          return;
        }
      }
      if ((pmVar7->hulls[1].firstclipnode != 0) || (pmVar7->type == mod_studio)) {
        iVar10 = pmove->numvisent;
        pmove->numvisent = iVar10 + 1;
        iVar2 = state->number;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1510].r_offset + (int)ppVar6->physents) = iVar2;
        if ((0 < iVar2) && (iVar2 <= cl.maxclients)) {
          *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x150a].r_offset + (int)ppVar6->physents) = iVar2;
        }
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150a].r_info + (int)ppVar6->physents) =
             state->origin[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150b].r_offset + (int)ppVar6->physents) =
             state->origin[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150b].r_info + (int)ppVar6->physents) =
             state->origin[2];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x1510].r_info + (int)ppVar6->physents) =
             state->angles[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x1511].r_offset + (int)ppVar6->physents) =
             state->angles[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x1511].r_info + (int)ppVar6->physents) =
             state->angles[2];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150d].r_offset + (int)ppVar6->physents) =
             state->mins[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150d].r_info + (int)ppVar6->physents) =
             state->mins[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150e].r_offset + (int)ppVar6->physents) =
             state->mins[2];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150e].r_info + (int)ppVar6->physents) =
             state->maxs[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150f].r_offset + (int)ppVar6->physents) =
             state->maxs[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x150f].r_info + (int)ppVar6->physents) =
             state->maxs[2];
        *(float *)((int)&__DT_REL[iVar10 * 0x1c + 0x1513].r_info + (int)ppVar6->physents) =
             state->frame;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1514].r_offset + (int)ppVar6->physents) =
             state->sequence;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1513].r_offset + (int)ppVar6->physents) =
             state->rendermode;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1512].r_info + (int)ppVar6->physents) =
             (int)state->skin;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1512].r_offset + (int)ppVar6->physents) =
             (int)state->solid;
        Q_memcpy(ppVar6->visents[iVar10].controller,state->controller,4);
        Q_memcpy(ppVar6->visents[iVar10].blending,state->blending,2);
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1515].r_info + (int)ppVar6->physents) =
             state->movetype;
        *(undefined4 *)((int)&__DT_REL[iVar10 * 0x1c + 0x1516].r_offset + (int)ppVar6->physents) = 0
        ;
        *(undefined4 *)((int)&__DT_REL[iVar10 * 0x1c + 0x1516].r_info + (int)ppVar6->physents) = 0;
        iVar2 = *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1512].r_offset + (int)ppVar6->physents);
        if (iVar2 == 4) {
LAB_001360f8:
          pmVar8 = CL_GetModelByIndex(state->modelindex);
          *(undefined4 *)((int)&__DT_REL[iVar10 * 0x1c + 0x150c].r_info + (int)ppVar6->physents) = 0
          ;
          *(model_t **)((int)&__DT_REL[iVar10 * 0x1c + 0x150c].r_offset + (int)ppVar6->physents) =
               pmVar8;
LAB_00136115:
          Q_strncpy(ppVar6->visents[iVar10].name,pmVar8->name,0x20);
          *(char *)((int)&__DT_REL[iVar10 * 0x1c + 0x1509].r_info +
                   (int)(ppVar6->physents[0].name + 3)) = '\0';
        }
        else {
          if (iVar2 != 2) {
            pmVar8 = CL_GetModelByIndex(state->modelindex);
            if (pmVar8->type != mod_studio) goto LAB_001360f8;
            *(undefined4 *)((int)&__DT_REL[iVar10 * 0x1c + 0x150c].r_offset + (int)ppVar6->physents)
                 = 0;
            pmVar8 = CL_GetModelByIndex(state->modelindex);
            *(model_t **)((int)&__DT_REL[iVar10 * 0x1c + 0x150c].r_info + (int)ppVar6->physents) =
                 pmVar8;
            goto LAB_00136115;
          }
                    /* Unresolved local var: model_t.conflict * pModel@[???] */
          *(undefined4 *)((int)&__DT_REL[iVar10 * 0x1c + 0x150c].r_offset + (int)ppVar6->physents) =
               0;
          *(undefined4 *)((int)&__DT_REL[iVar10 * 0x1c + 0x150c].r_info + (int)ppVar6->physents) = 0
          ;
          pmVar8 = CL_GetModelByIndex(state->modelindex);
          Q_strncpy(ppVar6->visents[iVar10].name,pmVar8->name,0x20);
          *(char *)((int)&__DT_REL[iVar10 * 0x1c + 0x1509].r_info +
                   (int)(ppVar6->physents[0].name + 3)) = '\0';
          if ((pmVar8->flags & 0x200) != 0) {
            *(model_t **)((int)&__DT_REL[iVar10 * 0x1c + 0x150c].r_info + (int)ppVar6->physents) =
                 pmVar8;
          }
        }
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1518].r_offset + (int)ppVar6->physents) =
             state->iuser1;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1518].r_info + (int)ppVar6->physents) =
             state->iuser2;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1519].r_offset + (int)ppVar6->physents) =
             state->iuser3;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1519].r_info + (int)ppVar6->physents) =
             state->iuser4;
        *(float *)((int)&__DT_REL[iVar10 * 0x1c + 0x151a].r_offset + (int)ppVar6->physents) =
             state->fuser1;
        *(float *)((int)&__DT_REL[iVar10 * 0x1c + 0x151a].r_info + (int)ppVar6->physents) =
             state->fuser2;
        *(float *)((int)&__DT_REL[iVar10 * 0x1c + 0x151b].r_offset + (int)ppVar6->physents) =
             state->fuser3;
        *(float *)((int)&__DT_REL[iVar10 * 0x1c + 0x151b].r_info + (int)ppVar6->physents) =
             state->fuser4;
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151c].r_offset + (int)ppVar6->physents) =
             state->vuser1[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151c].r_info + (int)ppVar6->physents) =
             state->vuser1[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151d].r_offset + (int)ppVar6->physents) =
             state->vuser1[2];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151d].r_info + (int)ppVar6->physents) =
             state->vuser2[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151e].r_offset + (int)ppVar6->physents) =
             state->vuser2[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151e].r_info + (int)ppVar6->physents) =
             state->vuser2[2];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151f].r_offset + (int)ppVar6->physents) =
             state->vuser3[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x151f].r_info + (int)ppVar6->physents) =
             state->vuser3[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x1520].r_offset + (int)ppVar6->physents) =
             state->vuser3[2];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x1520].r_info + (int)ppVar6->physents) =
             state->vuser4[0];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x1521].r_offset + (int)ppVar6->physents) =
             state->vuser4[1];
        *(vec_t *)((int)&__DT_REL[iVar10 * 0x1c + 0x1521].r_info + (int)ppVar6->physents) =
             state->vuser4[2];
        *(byte *)((int)&__DT_REL[iVar10 * 0x1c + 0x1515].r_offset + (int)ppVar6->physents) =
             state->blending[0];
        *(byte *)((int)&__DT_REL[iVar10 * 0x1c + 0x1515].r_offset +
                 (int)(ppVar6->physents[0].name + 1)) = state->blending[1];
        *(byte *)((int)&__DT_REL[iVar10 * 0x1c + 0x1514].r_info + (int)ppVar6->physents) =
             state->controller[0];
        *(byte *)((int)&__DT_REL[iVar10 * 0x1c + 0x1514].r_info +
                 (int)(ppVar6->physents[0].name + 1)) = state->controller[1];
        *(byte *)((int)&__DT_REL[iVar10 * 0x1c + 0x1514].r_info +
                 (int)(ppVar6->physents[0].name + 2)) = state->controller[2];
        *(byte *)((int)&__DT_REL[iVar10 * 0x1c + 0x1514].r_info +
                 (int)(ppVar6->physents[0].name + 3)) = state->controller[3];
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1513].r_offset + (int)ppVar6->physents) =
             state->rendermode;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1514].r_offset + (int)ppVar6->physents) =
             state->sequence;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1517].r_offset + (int)ppVar6->physents) =
             state->team;
        *(int *)((int)&__DT_REL[iVar10 * 0x1c + 0x1517].r_info + (int)ppVar6->physents) =
             state->playerclass;
      }
      if ((state->solid == 1) || ((state->solid == 0 && (-2 < state->skin)))) goto LAB_00135f00;
      if ((state->mins[2] == 0.0) && (state->maxs[2] == 1.0)) goto LAB_00135f00;
      local_28 = state->maxs[0] - state->mins[0];
      local_24 = state->maxs[1] - state->mins[1];
      local_20 = state->maxs[2] - state->mins[2];
      fVar12 = Length(&local_28);
      if ((fVar12 == 0.0) || ((pmVar7->hulls[1].firstclipnode == 0 && (pmVar7->type != mod_studio)))
         ) goto LAB_00135f00;
      if (*(int *)&state->skin == 0xfff0) {
        iVar10 = pmove->nummoveent;
        if (iVar10 < 0x40) {
          pe = (physent_t_conflict1 *)(pmove->moveents + iVar10);
          pmove->nummoveent = iVar10 + 1;
          goto LAB_001363b9;
        }
        Con_DPrintf("CL_SetSolidEntities:  pmove->nummoveent >= MAX_MOVEENTS\n");
        iVar10 = cl.frames[iVar5].packet_entities.num_entities;
      }
      else {
        iVar10 = pmove->numphysent;
        if (iVar10 < 600) {
          pe = (physent_t_conflict1 *)(pmove->physents + iVar10);
          pmove->numphysent = iVar10 + 1;
LAB_001363b9:
          CL_AddStateToEntlist(pe,(entity_state_t_conflict *)state);
          goto LAB_00135f00;
        }
        Con_DPrintf("CL_SetSolidEntities:  pmove->numphysent >= MAX_PHYSENTS\n");
        iVar10 = cl.frames[iVar5].packet_entities.num_entities;
      }
LAB_00135e70:
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar10);
  }
  return;
}


// CL_SetSolidPlayers  @ 00136680
void CL_SetSolidPlayers(int playernum)

{
  int iVar1;
  int iVar2;
  predicted_player *ppVar3;
  int iVar4;
  int iVar5;
  physent_t *dest;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: predicted_player * pplayer@[???]
                       Unresolved local var: physent_t.conflict1 * pent@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: frame_t * frame@[???] */
  if (cl_solid_players.value != 0.0) {
    iVar4 = 0;
    iVar5 = cl.parsecountmod * 0x4318 + 0xc6aa3c;
    ppVar3 = predicted_players;
    dest = pmove->physents + pmove->numphysent;
    iVar2 = 1;
    do {
      if (playernum == -1) {
        if ((cl.playernum == iVar4) || (ppVar3->active != false)) {
LAB_00136716:
          if (ppVar3->solid != 0) {
            Q_memset(dest,0,0xe0);
            dest->player = 1;
            dest->model = (model_s *)0x0;
            dest->origin[0] = ppVar3->origin[0];
            dest->origin[1] = ppVar3->origin[1];
            dest->origin[2] = ppVar3->origin[2];
            dest->mins[0] = player_mins[ppVar3->usehull][0];
            dest->mins[1] = player_mins[ppVar3->usehull][1];
            dest->mins[2] = player_mins[ppVar3->usehull][2];
            dest->maxs[0] = player_maxs[ppVar3->usehull][0];
            dest->maxs[1] = player_maxs[ppVar3->usehull][1];
            dest->maxs[2] = player_maxs[ppVar3->usehull][2];
            __snprintf_chk(dest,0x20,1,0x20,&DAT_0026332e,iVar4);
            iVar1 = ppVar3->solid;
            dest->skin = 0;
            dest->solid = iVar1;
            dest->info = iVar2;
            dest->movetype = (int)ppVar3->movetype;
            dest->blooddecal = 0;
            dest->takedamage = 1;
            dest->angles[0] = ppVar3->angles[0];
            dest->angles[1] = ppVar3->angles[1];
            dest->angles[2] = ppVar3->angles[2];
            dest->iuser1 = *(int *)(iVar5 + 0x104);
            dest->iuser2 = *(int *)(iVar5 + 0x108);
            dest->iuser3 = *(int *)(iVar5 + 0x10c);
            dest->iuser4 = *(int *)(iVar5 + 0x110);
            dest->fuser1 = *(float *)(iVar5 + 0x114);
            dest->fuser2 = *(float *)(iVar5 + 0x118);
            dest->fuser3 = *(float *)(iVar5 + 0x11c);
            dest->fuser4 = *(float *)(iVar5 + 0x120);
            dest->vuser1[0] = *(vec_t *)(iVar5 + 0x124);
            dest->vuser1[1] = *(vec_t *)(iVar5 + 0x128);
            dest->vuser1[2] = *(vec_t *)(iVar5 + 300);
            dest->vuser2[0] = *(vec_t *)(iVar5 + 0x130);
            dest->vuser2[1] = *(vec_t *)(iVar5 + 0x134);
            dest->vuser2[2] = *(vec_t *)(iVar5 + 0x138);
            dest->vuser3[0] = *(vec_t *)(iVar5 + 0x13c);
            dest->vuser3[1] = *(vec_t *)(iVar5 + 0x140);
            dest->vuser3[2] = *(vec_t *)(iVar5 + 0x144);
            dest->vuser4[0] = *(vec_t *)(iVar5 + 0x148);
            dest->vuser4[1] = *(vec_t *)(iVar5 + 0x14c);
            dest->vuser4[2] = *(vec_t *)(iVar5 + 0x150);
            dest->blending[0] = *(byte *)(iVar5 + 0x6c);
            dest->blending[1] = *(byte *)(iVar5 + 0x6d);
            dest->controller[0] = *(byte *)(iVar5 + 0x68);
            dest->controller[1] = *(byte *)(iVar5 + 0x69);
            dest->controller[2] = *(byte *)(iVar5 + 0x6a);
            dest->controller[3] = *(byte *)(iVar5 + 0x6b);
            dest->frame = *(float *)(iVar5 + 0x30);
            dest->rendermode = *(int *)(iVar5 + 0x48);
            dest->sequence = *(int *)(iVar5 + 0x2c);
            dest->team = *(int *)(iVar5 + 0xa4);
            dest->classnumber = *(int *)(iVar5 + 0xa8);
            pmove->numphysent = pmove->numphysent + 1;
            dest = dest + 1;
          }
        }
      }
      else if ((ppVar3->active != false) && (playernum != iVar4)) goto LAB_00136716;
      ppVar3 = ppVar3 + 1;
      iVar5 = iVar5 + 0x154;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (ppVar3 != (predicted_player *)&gpSprite);
  }
  return;
}


// CL_SetUpPlayerPrediction  @ 001364c0
void CL_SetUpPlayerPrediction(qboolean dopred,qboolean bIncludeLocalClient)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  msprite_t *pmVar4;
  int iVar5;
  int iVar6;
  cl_entity_t *ent;
  predicted_player *ppVar7;
  int iVar8;
  bool bVar9;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: predicted_player * pplayer@[???]
                       Unresolved local var: cl_entity_t.conflict2 * ent@[???] */
  iVar6 = 0;
  ppVar7 = predicted_players;
  pmove = &g_clmove;
  iVar8 = cl.parsecountmod * 0x4318 + 0xc6aa3c;
  do {
    bVar9 = *(int *)(iVar8 + 0xc) == cl.parsecount;
    ppVar7->active = false;
    if ((bVar9) && (*(int *)(iVar8 + 0x28) != 0)) {
      if (((*(byte *)(iVar8 + 0x3c) & 0x80) == 0) || (bIncludeLocalClient != false)) {
        pmVar4 = *(msprite_t **)(iVar8 + 0x58);
        bVar9 = cl.playernum != iVar6;
        ppVar7->active = true;
        ppVar7->movetype = (int)pmVar4;
        ppVar7->solid = (int)*(short *)(iVar8 + 0x3a);
        ppVar7->usehull = *(int *)(iVar8 + 200);
        if (bVar9) goto LAB_0013655d;
        iVar5 = iVar6 * 0x154 + cl.parsecountmod * 0x4318;
        vVar1 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar5 + 0x111e4);
        vVar2 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar5 + 0x111f0);
        ppVar7->origin[0] = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar5 + 0x111e0);
        ppVar7->origin[1] = vVar1;
        vVar1 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar5 + 0x111ec);
        vVar3 = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar5 + 0x111f4);
        ppVar7->origin[2] = *(vec_t *)((int)__DT_REL + (int)cl.resourcelist + iVar5 + 0x111e8);
        ppVar7->angles[0] = vVar1;
        ppVar7->angles[1] = vVar2;
        ppVar7->angles[2] = vVar3;
      }
      else if (cl.playernum != iVar6) {
        pmVar4 = *(msprite_t **)(iVar8 + 0x58);
        ppVar7->active = true;
        ppVar7->movetype = (int)pmVar4;
        ppVar7->solid = (int)*(short *)(iVar8 + 0x3a);
        ppVar7->usehull = *(int *)(iVar8 + 200);
LAB_0013655d:
        ent = cl_entities + iVar6 + 1;
        CL_ComputePlayerOrigin(ent);
        ppVar7->origin[0] = ent->origin[0];
        ppVar7->origin[1] = ent->origin[1];
        ppVar7->origin[2] = ent->origin[2];
        ppVar7->angles[0] = ent->angles[0];
        ppVar7->angles[1] = ent->angles[1];
        ppVar7->angles[2] = ent->angles[2];
      }
    }
    iVar6 = iVar6 + 1;
    ppVar7 = ppVar7 + 1;
    iVar8 = iVar8 + 0x154;
    if (ppVar7 == (predicted_player *)&gpSprite) {
      return;
    }
  } while( true );
}


// CL_Set_ServerExtraInfo  @ 00137c70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Set_ServerExtraInfo(void)

{
  char *pszDir;
  int iVar1;
  int in_GS_OFFSET;
  char local_30 [32];
  int local_10;
  
                    /* Unresolved local var: char[32] val@[???]
                       Unresolved local var: char * dir@[???]
                       Unresolved local var: int cheats_enabled@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pszDir = MSG_ReadString();
  iVar1 = MSG_ReadByte();
  __snprintf_chk(local_30,0x20,1,0x20,"%d",iVar1 != 0);
  Cvar_DirectSet(&sv_cheats,local_30);
  COM_AddDefaultDir(pszDir);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_ShowTEBlood  @ 0014be60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_ShowTEBlood(void)

{
  qboolean qVar1;
  
  if (violence_hblood.value != 0.0) {
    return true;
  }
  qVar1 = (qboolean)NAN(violence_ablood.value);
  if (violence_ablood.value != 0.0) {
    qVar1 = true;
  }
  return qVar1;
}


// CL_ShutDownClientStatic  @ 001477a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ShutDownClientStatic(void)

{
  int iVar1;
  entity_state_s **ppeVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: packet_entities_t * pClientPack@[???] */
  iVar1 = CL_UPDATE_BACKUP;
  if (0 < CL_UPDATE_BACKUP) {
    iVar3 = 0;
    ppeVar2 = &cl.frames[0].packet_entities.entities;
    do {
      if (*ppeVar2 != (entity_state_s *)0x0) {
        Mem_Free(*ppeVar2);
        iVar1 = CL_UPDATE_BACKUP;
      }
      iVar3 = iVar3 + 1;
      *ppeVar2 = (entity_state_s *)0x0;
      ppeVar2 = ppeVar2 + 0x10c6;
    } while (iVar3 < iVar1);
  }
  Q_memset(cl.frames,0,iVar1 * 0x4318);
  return;
}


// CL_ShutDownUsrMessages  @ 001545a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ShutDownUsrMessages(void)

{
  _UserMsg *p_Var1;
  _UserMsg *p;
  
                    /* Unresolved local var: UserMsg * pList@[???]
                       Unresolved local var: UserMsg * pNext@[???] */
  p = gClientUserMsgs;
  if (gClientUserMsgs != (UserMsg *)0x0) {
    do {
      p_Var1 = p->next;
      Mem_Free(p);
      p = p_Var1;
    } while (p_Var1 != (_UserMsg *)0x0);
    gClientUserMsgs = (UserMsg *)0x0;
  }
  return;
}


// CL_Shutdown  @ 0014ac80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Shutdown(void)

{
  int iVar1;
  
  CL_FlushEventSystem();
  TextMessageShutdown();
  Net_APIShutDown();
  if (cls.demoheader != (FileHandle_t)0x0) {
    FS_Close(cls.demoheader);
    cls.demoheader = (FileHandle_t)0x0;
  }
  iVar1 = FS_FileExists("demoheader.dmf");
  if (iVar1 != 0) {
    FS_RemoveFile("demoheader.dmf",(char *)0x0);
  }
  return;
}


// CL_SignonReply  @ 00149940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SignonReply(void)

{
  uint uVar1;
  uint uVar2;
  qboolean qVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int in_GS_OFFSET;
  bool bVar10;
  byte bVar11;
  char acStack_117 [7];
  uint local_110 [64];
  int local_10;
  
                    /* Unresolved local var: char[256] mapname@[???]
                       Unresolved local var: int l@[???] */
  bVar11 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Con_DPrintf("CL_SignonReply: %i\n",cls.signon);
  if (cls.signon == 1) {
    Cache_Report();
    MSG_WriteByte(&cls.netchan.message,3);
    MSG_WriteString(&cls.netchan.message,"sendents");
  }
  else if (cls.signon == 2) {
    SCR_EndLoadingPlaque();
    __isoc99_sscanf(0xde4738,&LAB_0025dfbc,local_110);
    puVar6 = local_110;
    do {
      puVar5 = puVar6;
      uVar1 = *puVar5 + 0xfefefeff & ~*puVar5;
      uVar2 = uVar1 & 0x80808080;
      puVar6 = puVar5 + 1;
    } while (uVar2 == 0);
    if ((uVar1 & 0x8080) == 0) {
      puVar6 = (uint *)((int)puVar5 + 6);
      uVar2 = uVar2 >> 0x10;
    }
    pcVar7 = (char *)((int)puVar6 + ((-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2)) - (int)local_110))
    ;
    bVar10 = pcVar7 == (char *)0x4;
    if (4 < (int)pcVar7) {
                    /* Unresolved local var: size_t __s1_len@[???]
                       Unresolved local var: size_t __s2_len@[???] */
      iVar4 = 5;
      pcVar8 = acStack_117 + (int)(pcVar7 + 3);
      pcVar9 = ".bsp";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar10 = *pcVar8 == *pcVar9;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if (bVar10) {
        acStack_117[(int)(pcVar7 + 3)] = '\0';
      }
    }
    FS_LogLevelLoadFinished((char *)local_110);
    VGuiWrap2_LoadingFinished("level",(char *)local_110);
    if ((g_bRedirectedToProxy != 0) && (cls.spectator == false)) {
      Con_Printf("Redirected to invalid server\n");
      CL_Disconnect();
      qVar3 = Host_IsServerActive();
      if (qVar3 != false) {
        Host_ShutdownServer(false);
      }
    }
    g_bRedirectedToProxy = 0;
    if (cls.demoplayback != false) {
      Sequence_OnLevelLoad((char *)local_110);
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CL_Slist_f  @ 00144ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Slist_f(void)

{
  netadr_t adr;
  _func_short_short *p_Var1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: netadr_t adr@[???] */
  iVar5 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  num_servers = 0;
  Q_memset(cached_servers,0,0x4480);
  Con_Printf("Searching for local servers...\n");
  cls.slist_time = (float)realtime;
  NET_Config(true);
  Q_memset(&local_24,0,0x14);
  do {
    while( true ) {
      p_Var1 = BigShort;
      iVar4 = Q_atoi("27015");
      sVar3 = (*p_Var1)((short)iVar4 + (short)iVar5);
      local_14 = CONCAT22(sVar3,(undefined2)local_14);
      uVar2 = local_14;
      if (noip != false) break;
      local_24 = 2;
      iVar5 = iVar5 + 1;
      adr.ip[0] = (undefined1)local_20;
      adr.ip[1] = local_20._1_1_;
      adr.ip[2] = local_20._2_1_;
      adr.ip[3] = local_20._3_1_;
      adr.type = 2;
      adr.ipx[0] = (undefined1)local_1c;
      adr.ipx[1] = local_1c._1_1_;
      adr.ipx[2] = local_1c._2_1_;
      adr.ipx[3] = local_1c._3_1_;
      adr.ipx[4] = (undefined1)local_18;
      adr.ipx[5] = local_18._1_1_;
      adr.ipx[6] = local_18._2_1_;
      adr.ipx[7] = local_18._3_1_;
      adr.ipx[8] = (undefined1)local_14;
      adr.ipx[9] = local_14._1_1_;
      adr.port = sVar3;
      local_14 = uVar2;
      Netchan_OutOfBandPrint(NS_CLIENT,adr,"%c%s",0x54,0x25db9d);
      if (iVar5 == 10) goto LAB_00144bc5;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 10);
LAB_00144bc5:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_SpecPos_f  @ 001449b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SpecPos_f(void)

{
  int iVar1;
  char *str;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: vec3_t origin@[???]
                       Unresolved local var: vec3_t angles@[???] */
  local_20 = r_refdef.vieworg[0];
  local_1c = r_refdef.vieworg[1];
  local_18 = r_refdef.vieworg[2];
  local_14 = r_refdef.viewangles[0];
  local_10 = r_refdef.viewangles[1];
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    str = Cmd_Argv(1);
    iVar1 = Q_atoi(str);
    if ((iVar1 == 2) && (cls.state == ca_active)) {
      iVar1 = cl.playernum * 0x154 + cl.parsecountmod * 0x4318;
      local_20 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar1 + 0x111e0);
      local_1c = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar1 + 0x111e4);
      local_18 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar1 + 0x111e8);
      local_14 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar1 + 0x111ec);
      local_10 = *(float *)((int)__DT_REL + (int)cl.resourcelist + iVar1 + 0x111f0);
    }
  }
  Con_Printf("spec_pos %.1f %.1f %.1f %.1f %.1f\n",(double)local_20,(double)local_1c,
             (double)local_18,(double)local_14,(double)local_10);
  return;
}


// CL_StartMovie_f  @ 00144230
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_StartMovie_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  float fVar4;
  
                    /* Unresolved local var: char * pFilename@[???] */
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    if (cls.demoplayback == false) {
      Con_Printf("startmovie only allowed during demo playback.\n");
    }
    else {
                    /* Unresolved local var: char * pFilename@[???] */
      pcVar2 = Cmd_Argv(1);
      if ((((*pcVar2 != '/') && (pcVar3 = Q_strstr(pcVar2,":"), pcVar3 == (char *)0x0)) &&
          (pcVar3 = Q_strstr(pcVar2,".."), pcVar3 == (char *)0x0)) &&
         (pcVar3 = Q_strstr(pcVar2,"\\"), pcVar3 == (char *)0x0)) {
        pcVar2 = Cmd_Argv(2);
        fVar4 = Q_atof(pcVar2);
        cl_inmovie = true;
        host_framerate.value = 1.0 / fVar4;
        pcVar2 = Cmd_Argv(1);
        VID_WriteBuffer(pcVar2);
        Con_Printf("Started recording movie...\n");
        return;
      }
      Con_Printf("Couldn\'t open %s (contains illegal characters).\n",pcVar2);
    }
  }
  else {
    Con_Printf("startmovie <filename> <fps>\n");
  }
  return;
}


// CL_StartResourceDownloading  @ 00155ce0
void CL_StartResourceDownloading(char *pszMessage,qboolean bCustom)

{
  resourceinfo_t local_2c;
  
                    /* Unresolved local var: resourceinfo_t ri@[???] */
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_StartResourceDownloading()");
  }
  if (pszMessage != (char *)0x0) {
    Con_DPrintf("%s",pszMessage);
  }
  cls.dl.nTotalSize = COM_SizeofResourceList(&cl.resourcesneeded,&local_2c);
  cls.dl.nTotalToTransfer = CL_EstimateNeededResources();
  if (bCustom == false) {
    cls.state = ca_uninitialized;
    gfExtendedError = false;
  }
  cls.dl.custom = (qboolean)(bCustom != false);
  cls.dl.fLastStatusUpdate = (float)realtime;
  cls.dl.doneregistering = false;
  cls.dl.nRemainingToTransfer = cls.dl.nTotalToTransfer;
  Q_memset(cls.dl.rgStats,0,0x60);
  cls.dl.nCurStat = 0;
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_StartResourceDownloading()");
    CL_BatchResourceRequest();
    return;
  }
  CL_BatchResourceRequest();
  return;
}


// CL_StopPlayback  @ 00142b50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_StopPlayback(void)

{
  float fVar1;
  int iVar2;
  
  if (cls.demoplayback == false) {
    return;
  }
  iVar2 = DemoPlayer_IsActive();
  if (iVar2 == 0) {
    FS_Close(cls.demofile);
  }
  else {
    DemoPlayer_Stop();
  }
  cls.demoplayback = false;
  cls.demofile = (FileHandle_t)0x0;
  cls.state = ca_disconnected;
  cls.demoframecount = 0;
  if (demodir.p_rgEntries != (demoentry_t *)0x0) {
    Mem_Free(demodir.p_rgEntries);
  }
  demodir.p_rgEntries = (demoentry_t *)0x0;
  demodir.nEntries = 0;
  if (cl_gamegauge.value != 0.0) {
    CL_FinishGameGauge();
  }
  if (cls.timedemo != false) {
                    /* Unresolved local var: int frames@[???]
                       Unresolved local var: float time@[???] */
    fVar1 = (float)realtime - cls.td_starttime;
    cls.timedemo = false;
    iVar2 = (host_framecount - cls.td_startframe) + -1;
    if (fVar1 == 0.0) {
      fVar1 = 1.0;
    }
    Con_Printf("%i frames %5.3f seconds %5.3f fps\n",iVar2,(double)fVar1,
               (double)((float)iVar2 / fVar1));
  }
  Cbuf_AddText("cd stop\n");
  return;
}


// CL_Stop_f  @ 001417c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Stop_f(void)

{
  float fVar1;
  int iVar2;
  demoentry_t *pdVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  longdouble lVar7;
  undefined1 local_221;
  float local_220;
  int32 local_21c;
  char local_218 [259];
  undefined1 local_115;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: byte c@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: float ft@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: int swlen@[???]
                       Unresolved local var: int curpos@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[260] szNewName@[???]
                       Unresolved local var: char[260] szOldName@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    if (cls.demorecording == false) {
      Con_Printf("Not recording a demo.\n");
    }
    else {
      local_221 = 5;
      FS_Write(&local_221,1,1,cls.demofile);
      fVar1 = (float)realtime;
      lVar7 = (longdouble)(*LittleFloat)(fVar1 - cls.demostarttime);
      local_220 = (float)lVar7;
      FS_Write(&local_220,4,1,cls.demofile);
      local_21c = (*LittleLong)(host_framecount - cls.demostartframe);
      iVar5 = 0;
      FS_Write(&local_21c,4,1,cls.demofile);
      uVar4 = FS_Tell(cls.demofile);
      pdVar3 = pCurrentEntry;
      pCurrentEntry->nFileLength = uVar4 - pCurrentEntry->nOffset;
      pdVar3->fTrackTime = fVar1 - cls.demostarttime;
      pdVar3->nFrames = cls.demoframecount;
      FS_Write(&demodir,4,1,cls.demofile);
      if (0 < demodir.nEntries) {
        iVar6 = 0;
        do {
          iVar5 = iVar5 + 1;
          iVar2 = iVar6 + -4;
          iVar6 = iVar6 + 0x5c;
          FS_Write((demodir.p_rgEntries)->szDescription + iVar2,0x5c,1,cls.demofile);
        } while (iVar5 < demodir.nEntries);
      }
      if (demodir.p_rgEntries != (demoentry_t *)0x0) {
        Mem_Free(demodir.p_rgEntries);
      }
      demodir.p_rgEntries = (demoentry_t *)0x0;
      demodir.nEntries = 0;
      demoheader.nDirectoryOffset = uVar4;
      FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
      FS_Write(&demoheader,0x220,1,cls.demofile);
      FS_Close(cls.demofile);
      cls.demofile = (FileHandle_t)0x0;
      cls.demorecording = false;
      cls.td_lastframe = host_framecount;
      if (cls.demoappending != false) {
        Con_Printf("Replacing old demo with appended version.\n");
        Q_strncpy(local_218,cls.demofilename,0x103);
        local_115 = 0;
        unlink(cls.demofilename);
        COM_StripExtension(cls.demofilename,local_114);
        COM_DefaultExtension(local_114,".dm2");
        rename(local_114,local_218);
      }
      Con_Printf("Completed demo\n");
      Con_DPrintf("Recording time %.2f\nHost frames %i\n",(double)(fVar1 - cls.demostarttime),
                  cls.td_lastframe - cls.td_startframe);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_StudioEstimateFrame  @ 000dc600
float CL_StudioEstimateFrame(mstudioseqdesc_t *pseqdesc)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: double dfdt@[???]
                       Unresolved local var: double f@[???] */
  if (r_dointerp == 0) {
LAB_000dc62d:
    fVar2 = 0.0;
  }
  else {
    fVar2 = (currententity->curstate).animtime;
    if ((float)cl.time < fVar2) goto LAB_000dc62d;
    fVar2 = ((float)cl.time - fVar2) * (currententity->curstate).framerate * pseqdesc->fps;
  }
  iVar3 = pseqdesc->numframes;
  if (iVar3 < 2) {
    fVar2 = fVar2 + 0.0;
    if ((pseqdesc->flags & 1) == 0) goto LAB_000dc69c;
  }
  else {
                    /* Unresolved local var: float baseframe@[???] */
    iVar1 = iVar3 + -1;
    fVar2 = (float)iVar1 * (currententity->curstate).frame * 0.00390625 + fVar2;
    if ((pseqdesc->flags & 1) == 0) {
LAB_000dc69c:
      if ((float)iVar3 - 1.001 <= fVar2) {
        fVar2 = (float)iVar3 - 1.001;
      }
      if (fVar2 < 0.0) {
        return 0.0;
      }
      return fVar2;
    }
    fVar2 = fVar2 - (float)((int)(fVar2 / (float)iVar1) * iVar1);
  }
  if (fVar2 < 0.0) {
    fVar2 = (float)(iVar3 + -1) + fVar2;
  }
  return fVar2;
}


// CL_StudioEstimateInterpolant  @ 000dc270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float CL_StudioEstimateInterpolant(void)

{
  float fVar1;
  
                    /* Unresolved local var: float dadt@[???] */
  fVar1 = 1.0;
  if (r_dointerp != 0) {
                    /* Unresolved local var: float dadt@[???] */
    fVar1 = (currententity->curstate).animtime;
    if (fVar1 < (currententity->latched).prevanimtime + 0.01) {
      fVar1 = 1.0;
    }
    else {
      fVar1 = ((float)cl.time - fVar1) / 0.1;
      if (2.0 < fVar1) {
        fVar1 = 2.0;
      }
    }
  }
  return fVar1;
}


// CL_SwapDemo_f  @ 0013eab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SwapDemo_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  qboolean qVar5;
  FILE *src;
  uint nSize;
  int iVar6;
  demoentry_t *pdVar7;
  int *piVar8;
  demoentry_t *pdVar9;
  demoentry_t *pdVar10;
  int in_GS_OFFSET;
  byte bVar11;
  undefined4 uVar12;
  int local_388 [23];
  char local_32c [260];
  char local_228 [260];
  char local_124 [255];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: int nSegment1@[???]
                       Unresolved local var: int nSegment2@[???]
                       Unresolved local var: demoentry_t * oldentry@[???]
                       Unresolved local var: demoentry_t * newentry@[???]
                       Unresolved local var: demoentry_t temp@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: int i@[???] */
  bVar11 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source != src_command) goto LAB_0013eaea;
  if ((cls.demorecording != false) || (cls.demoplayback != false)) {
    Con_Printf("Swapdemo only available when not running or recording a demo.\n");
    goto LAB_0013eaea;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 != 4) {
    Con_Printf("Swapdemo <demoname> <seg#> <seg#>\nSwaps segments, segment 1 cannot be moved\n");
    goto LAB_0013eaea;
  }
  pcVar2 = Cmd_Argv(1);
  pcVar2 = Q_strstr(pcVar2,"..");
  if (pcVar2 != (char *)0x0) {
    Con_Printf("Relative pathnames are not allowed.\n");
    goto LAB_0013eaea;
  }
  pcVar2 = Cmd_Argv(2);
  iVar1 = Q_atoi(pcVar2);
  if (iVar1 < 2) {
    Con_Printf("Cannot swap the STARTUP segment.\n");
    goto LAB_0013eaea;
  }
  pcVar2 = local_32c;
  pcVar3 = Cmd_Argv(3);
  iVar4 = Q_atoi(pcVar3);
  pcVar3 = Cmd_Argv(1);
  snprintf(pcVar2,0x100,"%s",pcVar3);
  COM_DefaultExtension(pcVar2,".dem");
  qVar5 = COM_HasFileExtension(pcVar2,"dem");
  if (qVar5 == false) {
    Con_Printf("Error: couldn\'t open %s, demo files must have .dem extension.\n",pcVar2);
    goto LAB_0013eaea;
  }
  pcVar3 = pcVar2;
  Con_Printf("Swapping segment %i for %i from demo %s.\n",iVar1,iVar4,pcVar2);
  uVar12 = 0xff;
  Q_strncpy(local_124,pcVar2,0xff);
  local_25 = 0;
  src = FS_Open(local_124,"rb");
  if (src == (FILE *)0x0) {
    Con_Printf("Error: couldn\'t open demo file %s for swapping.\n",pcVar2,uVar12,pcVar3);
    goto LAB_0013eaea;
  }
  COM_StripExtension(pcVar2,local_228);
  COM_AddExtension(local_228,".dm2",0x104);
  qVar5 = COM_HasFileExtension(local_228,"dm2");
  if (qVar5 == false) {
    Con_Printf("Error: couldn\'t open temporary file %s.\n",local_228);
    FS_Close(src);
    goto LAB_0013eaea;
  }
  cls.demofile = FS_OpenPathID(local_228,"w+b","GAMECONFIG");
  if (cls.demofile == (FileHandle_t)0x0) {
    Con_Printf("Error: couldn\'t open %s.\n",pcVar2);
    FS_Close(src);
    goto LAB_0013eaea;
  }
  FS_Seek(src,0,FILESYSTEM_SEEK_TAIL);
  nSize = FS_Tell(src);
  FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  CL_DemoCopyFileChunk(cls.demofile,src,nSize);
  FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  FS_Read(&demoheader,0x220,1,src);
  iVar6 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
  if (iVar6 == 0) {
    if ((demoheader.nNetProtocolVersion == 0x30) && (demoheader.nDemoProtocol == 5)) {
      FS_Seek(src,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
      FS_Read(&demodir,4,1,src);
      pcVar2 = (char *)demodir.nEntries;
      if (demodir.nEntries - 1U < 0x400) {
        if ((iVar4 + -1 < demodir.nEntries) && (iVar1 + -1 < demodir.nEntries)) {
          demodir.p_rgEntries = Mem_Malloc(demodir.nEntries * 0x5c);
          FS_Read(demodir.p_rgEntries,demodir.nEntries * 0x5c,1,src);
          pdVar7 = demodir.p_rgEntries + iVar1 + -1;
          piVar8 = local_388;
          for (iVar6 = 0x17; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar8 = pdVar7->nEntryType;
            pdVar7 = (demoentry_t *)((int)pdVar7 + (uint)bVar11 * -8 + 4);
            piVar8 = piVar8 + (uint)bVar11 * -2 + 1;
          }
          pdVar10 = demodir.p_rgEntries + iVar4 + -1;
          pdVar7 = pdVar10;
          pdVar9 = demodir.p_rgEntries + iVar1 + -1;
          for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
            pdVar9->nEntryType = pdVar7->nEntryType;
            pdVar7 = (demoentry_t *)((int)pdVar7 + (uint)bVar11 * -8 + 4);
            pdVar9 = (demoentry_t *)((int)pdVar9 + (uint)bVar11 * -8 + 4);
          }
          piVar8 = local_388;
          for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
            pdVar10->nEntryType = *piVar8;
            piVar8 = piVar8 + (uint)bVar11 * -2 + 1;
            pdVar10 = (demoentry_t *)((int)pdVar10 + (uint)bVar11 * -8 + 4);
          }
          FS_Seek(cls.demofile,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
          FS_Write(&demodir,4,1,cls.demofile);
          for (iVar1 = 0; iVar1 < demodir.nEntries; iVar1 = iVar1 + 1) {
            FS_Write(demodir.p_rgEntries + iVar1,0x5c,1,cls.demofile);
          }
          FS_Close(cls.demofile);
          cls.demofile = (FileHandle_t)0x0;
          FS_Close(src);
          Con_Printf("Replacing old demo with edited version.\n");
          unlink(local_124);
          rename(local_228,local_124);
          Mem_Free(demodir.p_rgEntries);
          demodir.p_rgEntries = (demoentry_t *)0x0;
          demodir.nEntries = 0;
          goto LAB_0013eaea;
        }
        pcVar3 = "ERROR: demo only has %d entries\n";
      }
      else {
        pcVar3 = "ERROR: demo had bogus # of directory entries:  %i\n";
      }
      goto LAB_0013ee9c;
    }
    Con_Printf("ERROR: demo protocol outdated\nDemo file protocols %iN:%iD\nServer protocol is at %iN:%iD\n"
               ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
  }
  else {
    pcVar3 = "%s is not a demo file\n";
LAB_0013ee9c:
    Con_Printf(pcVar3,pcVar2);
  }
  FS_Close(cls.demofile);
  FS_Close(src);
  unlink(local_228);
  cls.demofile = (FileHandle_t)0x0;
LAB_0013eaea:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_SwitchToNextDemoSection  @ 00140520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_SwitchToNextDemoSection(void)

{
                    /* Unresolved local var: float ft@[???] */
  if (((0 < nCurEntryIndex) && (pCurrentEntry != (demoentry_t *)0x0)) &&
     ((pCurrentEntry->nFlags & 4) != 0)) {
    Cbuf_AddText("cd stop\n");
  }
  nCurEntryIndex = nCurEntryIndex + 1;
  if (nCurEntryIndex < demodir.nEntries) {
    pCurrentEntry = demodir.p_rgEntries + nCurEntryIndex;
    cls.forcetrack = pCurrentEntry->nCDTrack;
    FS_Seek(cls.demofile,pCurrentEntry->nOffset,FILESYSTEM_SEEK_HEAD);
    cls.demostartframe = host_framecount;
    cls.demoframecount = 0;
    cls.demostarttime = g_demotimescale * (float)realtime;
    return true;
  }
                    /* WARNING: Subroutine does not return */
  Host_EndGame("End of demo.\n");
}


// CL_TakeSnapshot_f  @ 00143b50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TakeSnapshot_f(void)

{
  FileHandle_t file;
  int iVar1;
  int in_GS_OFFSET;
  char local_90 [64];
  char local_50 [64];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: char[64] base@[???]
                       Unresolved local var: char[64] filename@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((cl.num_entities == 0) || (cl_entities->model == (model_s *)0x0)) {
    Q_strcpy(local_90,"Snapshot");
  }
  else {
    COM_FileBase(cl_entities->model->name,local_90);
  }
  iVar1 = 0;
  do {
    __snprintf_chk(local_50,0x40,1,0x40,&LAB_00264b81_4,local_90,iVar1);
    file = FS_OpenPathID(local_50,"r","GAMECONFIG");
    if (file == (FileHandle_t)0x0) {
      VID_TakeSnapshot(local_50);
      goto LAB_00143c23;
    }
    iVar1 = iVar1 + 1;
    FS_Close(file);
  } while (iVar1 != 1000);
  Con_Printf("Unable to take a screenshot.\n");
LAB_00143c23:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_TempEntAlloc  @ 00152bb0
TEMPENTITY * CL_TempEntAlloc(vec_t *org,model_t *model)

{
  cl_entity_t *dest;
  vec_t vVar1;
  TEMPENTITY *pTVar2;
  TEMPENTITY *pTVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  pTVar3 = gpTempEntFree;
  if (gpTempEntFree == (TEMPENTITY *)0x0) {
    Con_DPrintf("Overflow %d temporary ents!\n",500);
  }
  else if (model == (model_t *)0x0) {
    pTVar3 = (TEMPENTITY *)0x0;
    Con_DPrintf("efx.CL_TempEntAlloc: No model\n");
  }
  else {
    dest = &gpTempEntFree->entity;
    gpTempEntFree = gpTempEntFree->next;
    Q_memset(dest,0,3000);
    pTVar3->flags = 0;
    (pTVar3->entity).curstate.colormap = 0;
    pTVar3->die = (float)cl.time + 0.75;
    (pTVar3->entity).model = model;
    (pTVar3->entity).curstate.renderfx = 0;
    pTVar2 = gpTempEntActive;
    (pTVar3->entity).curstate.rendermode = 0;
    pTVar3->fadeSpeed = 0.5;
    pTVar3->hitSound = 0;
    pTVar3->clientIndex = -1;
    pTVar3->bounceFactor = 1.0;
    pTVar3->hitcallback = (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0;
    pTVar3->callback = (_func_void_tempent_s_ptr_float_float *)0x0;
    pTVar3->priority = 0;
    gpTempEntActive = pTVar3;
    (pTVar3->entity).origin[0] = *org;
    (pTVar3->entity).origin[1] = org[1];
    vVar1 = org[2];
    pTVar3->next = pTVar2;
    (pTVar3->entity).origin[2] = vVar1;
  }
  return pTVar3;
}


// CL_TempEntAllocHigh  @ 00152de0
TEMPENTITY * CL_TempEntAllocHigh(vec_t *org,model_t *model)

{
  tempent_s **pptVar1;
  TEMPENTITY *pTVar2;
  tempent_s *ptVar3;
  TEMPENTITY *pTVar4;
  
  pTVar4 = gpTempEntFree;
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: TEMPENTITY * pActive@[???] */
  pTVar2 = gpTempEntActive;
  if (model == (model_t *)0x0) {
    Con_DPrintf("temporary ent model invalid\n");
    pTVar4 = (TEMPENTITY *)0x0;
  }
  else {
    ptVar3 = gpTempEntActive;
    if (gpTempEntFree == (TEMPENTITY *)0x0) {
      while (pTVar4 = ptVar3, pTVar4 != (TEMPENTITY *)0x0) {
        if (pTVar4->priority == 0) goto LAB_00152e1a;
        ptVar3 = pTVar4->next;
      }
      Con_DPrintf("Couldn\'t alloc a high priority TENT!\n");
      pTVar4 = (TEMPENTITY *)0x0;
    }
    else {
      gpTempEntActive = gpTempEntFree;
      pptVar1 = &gpTempEntFree->next;
      gpTempEntFree = gpTempEntFree->next;
      *pptVar1 = pTVar2;
LAB_00152e1a:
      Q_memset(&pTVar4->entity,0,3000);
      pTVar4->flags = 0;
      (pTVar4->entity).curstate.colormap = 0;
      pTVar4->die = (float)cl.time + 0.75;
      (pTVar4->entity).model = model;
      (pTVar4->entity).curstate.renderfx = 0;
      (pTVar4->entity).curstate.rendermode = 0;
      pTVar4->fadeSpeed = 0.5;
      pTVar4->hitSound = 0;
      pTVar4->clientIndex = -1;
      pTVar4->bounceFactor = 1.0;
      pTVar4->hitcallback = (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0;
      pTVar4->callback = (_func_void_tempent_s_ptr_float_float *)0x0;
      pTVar4->priority = 1;
      (pTVar4->entity).origin[0] = *org;
      (pTVar4->entity).origin[1] = org[1];
      (pTVar4->entity).origin[2] = org[2];
    }
  }
  return pTVar4;
}


// CL_TempEntAllocNoModel  @ 00152ce0
TEMPENTITY * CL_TempEntAllocNoModel(vec_t *org)

{
  cl_entity_t *dest;
  vec_t vVar1;
  TEMPENTITY *pTVar2;
  TEMPENTITY *pTVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  pTVar3 = gpTempEntFree;
  if (gpTempEntFree == (TEMPENTITY *)0x0) {
    Con_DPrintf("Overflow %d temporary ents!\n",500);
  }
  else {
    dest = &gpTempEntFree->entity;
    gpTempEntFree = gpTempEntFree->next;
    Q_memset(dest,0,3000);
    pTVar3->flags = 0;
    (pTVar3->entity).curstate.colormap = 0;
    pTVar3->die = (float)cl.time + 0.75;
    (pTVar3->entity).model = (model_s *)0x0;
    (pTVar3->entity).curstate.rendermode = 0;
    pTVar3->flags = 0x40000;
    (pTVar3->entity).curstate.renderfx = 0;
    pTVar2 = gpTempEntActive;
    pTVar3->fadeSpeed = 0.5;
    pTVar3->hitSound = 0;
    pTVar3->clientIndex = -1;
    pTVar3->bounceFactor = 1.0;
    pTVar3->hitcallback = (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0;
    pTVar3->callback = (_func_void_tempent_s_ptr_float_float *)0x0;
    pTVar3->priority = 0;
    gpTempEntActive = pTVar3;
    (pTVar3->entity).origin[0] = *org;
    (pTVar3->entity).origin[1] = org[1];
    vVar1 = org[2];
    pTVar3->next = pTVar2;
    (pTVar3->entity).origin[2] = vVar1;
  }
  return pTVar3;
}


// CL_TempEntInit  @ 00152ac0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TempEntInit(void)

{
  undefined *puVar1;
  
                    /* Unresolved local var: int i@[???] */
  Q_memset(gTempEnts,0,0x176830);
  puVar1 = (undefined *)0x37081c;
  do {
    *(undefined **)(puVar1 + -0xbd0) = puVar1;
    puVar1 = puVar1 + 0xbfc;
  } while (puVar1 != &DAT_004e6450);
  gTempEnts[499].next = (tempent_s *)0x0;
  gpTempEntFree = gTempEnts;
  gpTempEntActive = (TEMPENTITY *)0x0;
  return;
}


// CL_TempEntPlaySound  @ 0014b990
void CL_TempEntPlaySound(TEMPENTITY *pTemp,float damp)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  uint uVar4;
  int32 iVar5;
  uint uVar6;
  int iVar7;
  int32 iVar8;
  int32 pitch;
  float local_50;
  sfx_t *local_34 [4];
  sfx_t *local_24;
  sfx_t *local_20;
  
                    /* Unresolved local var: sfx_t *[6] rgsfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: int fShell@[???]
                       Unresolved local var: int zvel@[???] */
  Q_memset(local_34,0,0x18);
  iVar7 = pTemp->hitSound;
  if (iVar7 == 8) {
    iVar8 = 2;
    local_34[0] = cl_sfx_wood1;
    local_34[1] = cl_sfx_wood2;
    local_34[2] = cl_sfx_wood3;
  }
  else if (iVar7 < 9) {
    if (iVar7 == 2) {
      local_34[0] = cl_sfx_metal1;
      local_34[1] = cl_sfx_metal2;
      local_34[2] = cl_sfx_metal3;
      iVar8 = 2;
    }
    else if (iVar7 == 4) {
      iVar8 = 5;
      local_34[0] = cl_sfx_flesh1;
      local_34[1] = cl_sfx_flesh2;
      local_34[2] = cl_sfx_flesh3;
      local_34[3] = cl_sfx_flesh4;
      local_24 = cl_sfx_flesh5;
      local_20 = cl_sfx_flesh6;
    }
    else {
      if (iVar7 != 1) {
        return;
      }
      iVar8 = 2;
      local_34[0] = cl_sfx_glass1;
      local_34[1] = cl_sfx_glass2;
      local_34[2] = cl_sfx_glass3;
    }
  }
  else {
    if (iVar7 == 0x20) {
      local_34[0] = cl_sfx_pl_shell1;
      fVar1 = 0.8;
      local_34[1] = cl_sfx_pl_shell2;
      local_50 = 0.8;
      local_34[2] = cl_sfx_pl_shell3;
LAB_0014ba25:
      uVar6 = (uint)(pTemp->entity).baseline.origin[2];
      uVar4 = (int)uVar6 >> 0x1f;
      iVar7 = (uVar6 ^ uVar4) - uVar4;
      if ((iVar7 < 200) && (iVar8 = RandomLong(0,3), iVar8 != 0)) {
        return;
      }
      if (damp <= 0.0) {
        return;
      }
                    /* Unresolved local var: int pitch@[???] */
      fVar2 = (float)iVar7 / 350.0;
      if (fVar2 <= 1.0) {
        local_50 = fVar2 * fVar1;
      }
      iVar8 = 2;
      bVar3 = true;
      goto LAB_0014ba7c;
    }
    if (iVar7 < 0x21) {
      if (iVar7 != 0x10) {
        return;
      }
      iVar8 = 4;
      local_34[0] = cl_sfx_ric1;
      local_34[1] = cl_sfx_ric2;
      local_34[2] = cl_sfx_ric3;
      local_34[3] = cl_sfx_ric4;
      local_24 = cl_sfx_ric5;
    }
    else {
      if (iVar7 != 0x40) {
        if (iVar7 != 0x80) {
          return;
        }
        fVar1 = 0.5;
        local_34[0] = cl_sfx_sshell1;
        local_50 = 0.5;
        local_34[1] = cl_sfx_sshell2;
        local_34[2] = cl_sfx_sshell3;
        goto LAB_0014ba25;
      }
      local_34[0] = cl_sfx_concrete1;
      iVar8 = 2;
      local_34[1] = cl_sfx_concrete2;
      local_34[2] = cl_sfx_concrete3;
    }
  }
  fVar1 = (pTemp->entity).baseline.origin[2];
  iVar5 = RandomLong(0,5);
  if (iVar5 != 0) {
    return;
  }
  if (damp <= 0.0) {
    return;
  }
  uVar4 = (uint)fVar1;
  uVar6 = (int)uVar4 >> 0x1f;
  fVar1 = (float)(int)((uVar4 ^ uVar6) - uVar6) / 450.0;
  local_50 = 0.8;
  if (fVar1 <= 1.0) {
    local_50 = fVar1 * 0.8;
    bVar3 = false;
  }
  else {
    bVar3 = false;
  }
LAB_0014ba7c:
  pitch = 100;
  iVar5 = RandomLong(0,3);
  if (iVar5 == 0 && !bVar3) {
    pitch = RandomLong(0x5a,0x7c);
  }
  iVar8 = RandomLong(0,iVar8);
  S_StartDynamicSound(-1,0,local_34[iVar8],(pTemp->entity).origin,local_50,1.0,0,pitch);
  return;
}


// CL_TempEntPrepare  @ 00152b20
void CL_TempEntPrepare(TEMPENTITY *pTemp,model_t *model)

{
  Q_memset(&pTemp->entity,0,3000);
  pTemp->flags = 0;
  (pTemp->entity).curstate.colormap = 0;
  pTemp->die = (float)cl.time + 0.75;
  (pTemp->entity).model = model;
  (pTemp->entity).curstate.rendermode = 0;
  (pTemp->entity).curstate.renderfx = 0;
  pTemp->fadeSpeed = 0.5;
  pTemp->hitSound = 0;
  pTemp->clientIndex = -1;
  pTemp->bounceFactor = 1.0;
  pTemp->hitcallback = (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0;
  pTemp->callback = (_func_void_tempent_s_ptr_float_float *)0x0;
  return;
}


// CL_TempEntUpdate  @ 00152f20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TempEntUpdate(void)

{
                    /* Unresolved local var: double frametime@[???] */
  if (cl.worldmodel != (model_s *)0x0) {
    ClientDLL_TempEntUpdate
              (cl.time - cl.oldtime,cl.time,(double)movevars.gravity,&gpTempEntFree,&gpTempEntActive
               ,CL_AddVisibleEntity,CL_TempEntPlaySound);
  }
  return;
}


// CL_TentModel  @ 0014bea0
model_t * CL_TentModel(char *pName)

{
  model_t *pModel;
  
                    /* Unresolved local var: model_t * pModel@[???] */
  pModel = Mod_ForName(pName,true,false);
  Mod_MarkClient(pModel);
  return pModel;
}


// CL_TimeDemo_f  @ 001427f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TimeDemo_f(void)

{
  int iVar1;
  
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    CL_PlayDemo_f();
    cls.timedemo = true;
    cls.td_startframe = host_framecount;
    cls.td_lastframe = -1;
    cls.td_starttime = (float)realtime;
  }
  else {
    Con_Printf("timedemo <demoname>: gets demo speeds\n");
  }
  return;
}


// CL_TouchLight  @ 001346b0
void CL_TouchLight(dlight_t *dl)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[DW_OP_reg1(ECX)] */
  uVar1 = ((int)&dl[-0x4e5b7].decay >> 3) * -0x33333333;
  if (uVar1 < 0x20) {
    r_dlightchanged = r_dlightchanged | 1 << ((byte)uVar1 & 0x1f);
  }
  return;
}


// CL_TransferMessageData  @ 00157f70
/* WARNING: Removing unreachable block (ram,0x00157fc1) */
/* WARNING: Removing unreachable block (ram,0x00157f99) */
/* WARNING: Removing unreachable block (ram,0x00157fad) */
/* WARNING: Removing unreachable block (ram,0x001581d0) */
/* WARNING: Removing unreachable block (ram,0x001581e0) */
/* WARNING: Removing unreachable block (ram,0x00157fd6) */
/* WARNING: Removing unreachable block (ram,0x00158159) */
/* WARNING: Removing unreachable block (ram,0x0015816f) */
/* WARNING: Removing unreachable block (ram,0x00158185) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TransferMessageData(void)

{
                    /* Unresolved local var: int i@[???] */
  total_data[0x3f] = last_data[0x3f] + total_data[0x3f];
  total_data[0x3e] = last_data[0x3e] + total_data[0x3e];
  total_data[0x3d] = last_data[0x3d] + total_data[0x3d];
  total_data[0x3c] = last_data[0x3c] + total_data[0x3c];
  total_data[0x3b] = last_data[0x3b] + total_data[0x3b];
  total_data[0x3a] = last_data[0x3a] + total_data[0x3a];
  total_data[0x39] = last_data[0x39] + total_data[0x39];
  total_data[0x38] = last_data[0x38] + total_data[0x38];
  total_data[0x37] = last_data[0x37] + total_data[0x37];
  total_data[0x36] = last_data[0x36] + total_data[0x36];
  total_data[0x35] = last_data[0x35] + total_data[0x35];
  total_data[0x34] = last_data[0x34] + total_data[0x34];
  total_data[0x33] = last_data[0x33] + total_data[0x33];
  total_data[0x32] = last_data[0x32] + total_data[0x32];
  total_data[0x31] = last_data[0x31] + total_data[0x31];
  total_data[0x30] = last_data[0x30] + total_data[0x30];
  total_data[0x2f] = last_data[0x2f] + total_data[0x2f];
  total_data[0x2e] = last_data[0x2e] + total_data[0x2e];
  total_data[0x2d] = last_data[0x2d] + total_data[0x2d];
  total_data[0x2c] = last_data[0x2c] + total_data[0x2c];
  total_data[0x2b] = last_data[0x2b] + total_data[0x2b];
  total_data[0x2a] = last_data[0x2a] + total_data[0x2a];
  total_data[0x29] = last_data[0x29] + total_data[0x29];
  total_data[0x28] = last_data[0x28] + total_data[0x28];
  total_data[0x27] = last_data[0x27] + total_data[0x27];
  total_data[0x26] = last_data[0x26] + total_data[0x26];
  total_data[0x25] = last_data[0x25] + total_data[0x25];
  total_data[0x24] = last_data[0x24] + total_data[0x24];
  total_data[0x23] = last_data[0x23] + total_data[0x23];
  total_data[0x22] = last_data[0x22] + total_data[0x22];
  total_data[0x21] = last_data[0x21] + total_data[0x21];
  total_data[0x20] = last_data[0x20] + total_data[0x20];
  total_data[0x1f] = last_data[0x1f] + total_data[0x1f];
  total_data[0x1e] = last_data[0x1e] + total_data[0x1e];
  total_data[0x1d] = last_data[0x1d] + total_data[0x1d];
  total_data[0x1c] = last_data[0x1c] + total_data[0x1c];
  total_data[0x1b] = last_data[0x1b] + total_data[0x1b];
  total_data[0x1a] = last_data[0x1a] + total_data[0x1a];
  total_data[0x19] = last_data[0x19] + total_data[0x19];
  total_data[0x18] = last_data[0x18] + total_data[0x18];
  total_data[0x17] = last_data[0x17] + total_data[0x17];
  total_data[0x16] = last_data[0x16] + total_data[0x16];
  total_data[0x15] = last_data[0x15] + total_data[0x15];
  total_data[0x14] = last_data[0x14] + total_data[0x14];
  total_data[0x13] = last_data[0x13] + total_data[0x13];
  total_data[0x12] = last_data[0x12] + total_data[0x12];
  total_data[0x11] = last_data[0x11] + total_data[0x11];
  total_data[0x10] = last_data[0x10] + total_data[0x10];
  total_data[0xf] = last_data[0xf] + total_data[0xf];
  total_data[0xe] = last_data[0xe] + total_data[0xe];
  total_data[0xd] = last_data[0xd] + total_data[0xd];
  total_data[0xc] = last_data[0xc] + total_data[0xc];
  total_data[0xb] = last_data[0xb] + total_data[0xb];
  total_data[10] = last_data[10] + total_data[10];
  total_data[9] = last_data[9] + total_data[9];
  total_data[8] = last_data[8] + total_data[8];
  total_data[7] = last_data[7] + total_data[7];
  total_data[6] = last_data[6] + total_data[6];
  total_data[5] = last_data[5] + total_data[5];
  total_data[4] = last_data[4] + total_data[4];
  total_data[3] = last_data[3] + total_data[3];
  total_data[2] = last_data[2] + total_data[2];
  total_data[1] = last_data[1] + total_data[1];
  total_data[0] = last_data[0] + total_data[0];
  return;
}


// CL_UpdatePositions  @ 0013cae0
void CL_UpdatePositions(cl_entity_t *ent)

{
  vec_t vVar1;
  uint uVar2;
  
                    /* Unresolved local var: position_history_t * ph@[???] */
  vVar1 = (ent->curstate).angles[0];
  uVar2 = ent->current_position + 1U & 0x3f;
  ent->current_position = uVar2;
  ent->ph[uVar2].angles[0] = vVar1;
  ent->ph[uVar2].angles[1] = (ent->curstate).angles[1];
  ent->ph[uVar2].angles[2] = (ent->curstate).angles[2];
  ent->ph[uVar2].origin[0] = (ent->curstate).origin[0];
  ent->ph[uVar2].origin[1] = (ent->curstate).origin[1];
  ent->ph[uVar2].origin[2] = (ent->curstate).origin[2];
  ent->ph[uVar2].animtime = (ent->curstate).animtime;
  return;
}


// CL_UpdateSoundFade  @ 00144dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_UpdateSoundFade(void)

{
  float fVar1;
  
                    /* Unresolved local var: int nTotal@[???]
                       Unresolved local var: float fGap@[???]
                       Unresolved local var: float f@[???] */
  cls.soundfade.nClientSoundFadePercent = 0;
  if ((longdouble)realtime <
      (longdouble)
      (cls.soundfade.soundFadeInTime + cls.soundfade.soundFadeOutTime +
      cls.soundfade.soundFadeHoldTime) + (longdouble)cls.soundfade.soundFadeStartTime) {
    fVar1 = (float)((longdouble)realtime - (longdouble)cls.soundfade.soundFadeStartTime);
    if ((cls.soundfade.soundFadeOutTime != 0) && (fVar1 < (float)cls.soundfade.soundFadeOutTime)) {
      cls.soundfade.nClientSoundFadePercent =
           (int)((fVar1 / (float)cls.soundfade.soundFadeOutTime) *
                (float)cls.soundfade.nStartPercent);
      return;
    }
    if (fVar1 < (float)(cls.soundfade.soundFadeHoldTime + cls.soundfade.soundFadeOutTime)) {
      cls.soundfade.nClientSoundFadePercent = cls.soundfade.nStartPercent;
      return;
    }
    cls.soundfade.nClientSoundFadePercent =
         (int)((1.0 - (fVar1 - (float)(cls.soundfade.soundFadeHoldTime +
                                      cls.soundfade.soundFadeOutTime)) /
                      (float)cls.soundfade.soundFadeOutTime) * (float)cls.soundfade.nStartPercent);
  }
  return;
}


// CL_UpdateUserinfo  @ 001545d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_UpdateUserinfo(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint64 uVar6;
  
                    /* Unresolved local var: int slot@[???]
                       Unresolved local var: player_info_t * player@[???] */
  iVar2 = MSG_ReadByte();
  if (iVar2 < 0x20) {
    iVar3 = MSG_ReadLong();
    pcVar5 = cl.players[iVar2].userinfo;
    cl.players[iVar2].userid = iVar3;
    pcVar4 = MSG_ReadString();
    Q_strncpy(pcVar5,pcVar4,0xff);
    cl.players[iVar2].userinfo[0xff] = '\0';
    MSG_ReadBuf(0x10,cl.players[iVar2].hashedcdkey);
    pcVar4 = Info_ValueForKey(pcVar5,"name");
    Q_strncpy(cl.players[iVar2].name,pcVar4,0x1f);
    cl.players[iVar2].name[0x1f] = '\0';
    pcVar4 = Info_ValueForKey(pcVar5,"model");
    Q_strncpy(cl.players[iVar2].model,pcVar4,0x3f);
    cl.players[iVar2].model[0x3f] = '\0';
    pcVar4 = Info_ValueForKey(pcVar5,"topcolor");
    iVar3 = Q_atoi(pcVar4);
    cl.players[iVar2].topcolor = iVar3;
    pcVar4 = Info_ValueForKey(pcVar5,"bottomcolor");
    iVar3 = Q_atoi(pcVar4);
    cl.players[iVar2].bottomcolor = iVar3;
    pcVar4 = Info_ValueForKey(pcVar5,"*hltv");
    iVar3 = Q_atoi(pcVar4);
    cl.players[iVar2].spectator = iVar3;
    pcVar5 = Info_ValueForKey(pcVar5,"*sid");
    uVar6 = strtoll(pcVar5,(char **)0x0,10);
    cVar1 = cl.players[iVar2].userinfo[0];
    cl.players[iVar2].m_nSteamID = uVar6;
    if ((cVar1 == '\0') || (cl.players[iVar2].name[0] == '\0')) {
      COM_ClearCustomizationList(&cl.players[iVar2].customdata,true);
    }
    Steam_UpdateRichPresence();
    return;
  }
                    /* WARNING: Subroutine does not return */
  Host_EndGame("CL_ParseServerMessage: svc_updateuserinfo > MAX_CLIENTS");
}


// CL_ViewDemo_f  @ 001425a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ViewDemo_f(void)

{
  netadr_t adr;
  int iVar1;
  char *src;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] name@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    DemoPlayer_SetActive(1);
    iVar1 = DemoPlayer_IsActive();
    if (iVar1 == 0) {
      Con_Printf("viewdemo not available.\n");
    }
    else {
      DemoPlayer_ShowGUI();
      iVar1 = Cmd_Argc();
      if (iVar1 == 2) {
        CL_Disconnect();
        src = Cmd_Argv(1);
        Q_strncpy(local_114,src,0xff);
        COM_DefaultExtension(local_114,".dem");
        Con_Printf("Playing demo from %s.\n",local_114);
        iVar1 = DemoPlayer_LoadGame(local_114);
        if (iVar1 == 0) {
          Con_Printf("Viewdemo: couldn\'t load demo %s.\n",local_114);
          cls.demonum = -1;
        }
        else {
          cls.demoplayback = true;
          cls.state = ca_connected;
          cls.passive = false;
          cls.spectator = false;
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
          Netchan_Setup(NS_CLIENT,&cls.netchan,adr,-1,&cls,CL_GetFragmentSize);
          NET_ClearLagData(true,false);
          cls.nextcmdtime = (float)realtime;
          cls.lastoutgoingcommand = -1;
          DispatchDirectUserMsg("InitHUD",0,(void *)0x0);
        }
      }
      else {
        Con_Printf("viewdemo <demoname>: shows a demo\n");
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_VoiceIdle  @ 000b8e00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_VoiceIdle(void)

{
  Voice_Idle((float)host_frametime);
  return;
}


// CL_WavePlayLen_f  @ 00142860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_WavePlayLen_f(void)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
                    /* Unresolved local var: uint length@[???] */
    pcVar2 = Cmd_Argv(1);
    uVar3 = COM_GetApproxWavePlayLength(pcVar2);
    if (uVar3 == 0) {
      pcVar2 = Cmd_Argv(1);
      Con_Printf("Unable to read %s, file may be missing or incorrectly formatted.\n",pcVar2);
    }
    else {
      Con_Printf("Play time is approximately %dms\n",uVar3);
    }
  }
  else {
    Con_Printf(
              "waveplaylen <wave file name>: returns approximate number of milliseconds a wave file will take to play.\n"
              );
  }
  return;
}


// CL_WriteClientDLLMessage  @ 0013db80
void CL_WriteClientDLLMessage(int size,uchar *buf)

{
  longdouble lVar1;
  undefined1 local_15;
  int32 iStack_14;
  float afStack_10 [3];
  
                    /* Unresolved local var: int swlen@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: byte cmd@[???]
                       Unresolved local var: int frame@[???] */
  if ((cls.demorecording != false) && (cls.demofile != (FileHandle_t)0x0)) {
    if (-1 < size) {
      local_15 = 9;
      FS_Write(&local_15,1,1,cls.demofile);
      lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
      afStack_10[0] = (float)lVar1;
      FS_Write(afStack_10,4,1,cls.demofile);
      iStack_14 = (*LittleLong)(host_framecount - cls.demostartframe);
      FS_Write(&iStack_14,4,1,cls.demofile);
      iStack_14 = (*LittleLong)(size);
      FS_Write(&iStack_14,4,1,cls.demofile);
      FS_Write(buf,size,1,cls.demofile);
    }
    return;
  }
  return;
}


// CL_WriteDLLUpdate  @ 00140af0
void CL_WriteDLLUpdate(client_data_t *cdata)

{
  longdouble lVar1;
  undefined1 local_35;
  float local_34;
  int32 local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  int local_14;
  float local_10;
  
                    /* Unresolved local var: cl_demo_data_t demcmd@[???] */
  if (cls.demofile != (FileHandle_t)0x0) {
    local_35 = 4;
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_34 = (float)lVar1;
    local_30 = (*LittleLong)(host_framecount - cls.demostartframe);
    local_2c = cdata->origin[0];
    local_28 = cdata->origin[1];
    local_24 = cdata->origin[2];
    local_20 = cdata->viewangles[0];
    local_1c = cdata->viewangles[1];
    local_14 = cdata->iWeaponBits;
    local_18 = cdata->viewangles[2];
    local_10 = cdata->fov;
    FS_Write(&local_35,0x29,1,cls.demofile);
  }
  return;
}


// CL_WriteDemoMessage  @ 00141640
void CL_WriteDemoMessage(int start,sizebuf_t *msg)

{
  FileHandle_t file;
  int size;
  longdouble lVar1;
  undefined1 local_35;
  float local_34;
  int32 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int32 local_10;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: demo_command_t demcmd@[???] */
  if (((cls.demorecording != false) && (cls.demofile != (FileHandle_t)0x0)) &&
     (size = msg->cursize - start, -1 < size)) {
    cls.demoframecount = cls.demoframecount + 1;
    local_35 = 1;
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_34 = (float)lVar1;
    local_30 = (*LittleLong)(host_framecount - cls.demostartframe);
    FS_Write(&local_35,9,1,cls.demofile);
    FS_Write(&g_rp,0x1b4,1,cls.demofile);
    file = cls.demofile;
                    /* Unresolved local var: sequence_info_t si@[???] */
    local_2c = cls.netchan.incoming_sequence;
    local_28 = cls.netchan.incoming_acknowledged;
    local_24 = cls.netchan.incoming_reliable_acknowledged;
    local_20 = cls.netchan.incoming_reliable_sequence;
    local_1c = cls.netchan.outgoing_sequence;
    local_18 = cls.netchan.reliable_sequence;
    local_14 = cls.netchan.last_reliable_sequence;
    local_10 = (*LittleLong)(size);
    FS_Write(&local_2c,0x20,1,file);
    FS_Write(msg->data + start,size,1,cls.demofile);
    return;
  }
  return;
}


// CL_WriteDemoStartup  @ 001414c0
void CL_WriteDemoStartup(int start,sizebuf_t *msg)

{
  FileHandle_t file;
  int size;
  longdouble lVar1;
  undefined1 local_35;
  float local_34;
  int32 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int32 local_10;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: demo_command_t demcmd@[???] */
  if ((cls.demoheader != (FileHandle_t)0x0) && (size = msg->cursize - start, 0 < size)) {
    local_35 = 0;
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_34 = (float)lVar1;
    local_30 = (*LittleLong)(host_framecount - cls.demostartframe);
    FS_Write(&local_35,9,1,cls.demoheader);
    FS_Write(&g_rp,0x1b4,1,cls.demoheader);
    file = cls.demoheader;
                    /* Unresolved local var: sequence_info_t si@[???] */
    local_2c = cls.netchan.incoming_sequence;
    local_28 = cls.netchan.incoming_acknowledged;
    local_24 = cls.netchan.incoming_reliable_acknowledged;
    local_20 = cls.netchan.incoming_reliable_sequence;
    local_1c = cls.netchan.outgoing_sequence;
    local_18 = cls.netchan.reliable_sequence;
    local_14 = cls.netchan.last_reliable_sequence;
    local_10 = (*LittleLong)(size);
    FS_Write(&local_2c,0x20,1,file);
    FS_Write(msg->data + start,size,1,cls.demoheader);
    return;
  }
  return;
}


// CL_WriteErrorMessage  @ 00158320
void CL_WriteErrorMessage(int starting_count,int current_count,sizebuf_t *msg)

{
  sizebuf_t *psVar1;
  FileHandle_t file;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char * buffer_file@[???] */
  psVar1 = msg;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_114,"buffer.dat",0xb);
  COM_FixSlashes(local_114);
  COM_CreatePath(local_114);
  file = FS_Open(local_114,"wb");
  if (file != (FileHandle_t)0x0) {
    FS_Write(&starting_count,4,1,file);
    FS_Write(&current_count,4,1,file);
    FS_Write(psVar1->data,psVar1->cursize,1,file);
    FS_Close(file);
    Con_Printf("Wrote erroneous message to %s\n","buffer.dat");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CL_WriteMessageHistory  @ 00158430
void CL_WriteMessageHistory(int starting_count,int cmd)

{
  int iVar1;
  _UserMsg *p_Var2;
  UserMsg *pUVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int thecmd@[???] */
  uVar4 = 0x1f;
  Con_Printf("Last %i messages parsed.\n",0x20);
  do {
    uVar5 = ~uVar4 + currentcmd & 0x1f;
    iVar1 = oldcmd[uVar5].command;
    Q_strcpy(CL_MsgInfo::sz,"???");
    pUVar3 = gClientUserMsgs;
    if (iVar1 < 0x3c) {
      Q_strncpy(CL_MsgInfo::sz,cl_parsefuncs[iVar1].pszname,0xff);
      CL_MsgInfo::sz[0xff] = '\0';
    }
    else {
      for (; pUVar3 != (UserMsg *)0x0; pUVar3 = pUVar3->next) {
        if (iVar1 == pUVar3->iMsg) {
          Q_strncpy(CL_MsgInfo::sz,pUVar3->szName,0xff);
          CL_MsgInfo::sz[0xff] = '\0';
          break;
        }
      }
    }
    pcVar6 = CL_MsgInfo::sz;
    Con_Printf("%i %04i %s\n",oldcmd[uVar5].frame_number,oldcmd[uVar5].starting_offset,
               CL_MsgInfo::sz);
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  Q_strcpy(CL_MsgInfo::sz,"???");
  if (cmd < 0x3c) {
    Q_strncpy(CL_MsgInfo::sz,cl_parsefuncs[cmd].pszname,0xff);
    CL_MsgInfo::sz[0xff] = '\0';
  }
  else {
                    /* Unresolved local var: UserMsg * pList@[???] */
    if (gClientUserMsgs != (UserMsg *)0x0) {
      iVar1 = gClientUserMsgs->iMsg;
      p_Var2 = gClientUserMsgs;
      while (iVar1 != cmd) {
        p_Var2 = p_Var2->next;
        if (p_Var2 == (_UserMsg *)0x0) goto LAB_0015856e;
        iVar1 = p_Var2->iMsg;
      }
      Q_strncpy(CL_MsgInfo::sz,p_Var2->szName,0xff);
      CL_MsgInfo::sz[0xff] = '\0';
    }
  }
LAB_0015856e:
  Con_Printf("BAD:  %3i:%s\n",msg_readcount + -1,CL_MsgInfo::sz,pcVar6);
  if (developer.value == 0.0) {
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int thecmd@[???] */
  CL_WriteErrorMessage(starting_count,msg_readcount + -1,&net_message);
  return;
}


