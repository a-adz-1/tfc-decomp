// CL_AddEntityToPhysList  @ 00195450
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
            ((physent_t_conflict *)(ppVar3->physents + iVar1),
             (entity_state_t_conflict *)&pcVar2->curstate);
  return true;
}


// CL_AddModelEffects  @ 0018d720
void CL_AddModelEffects(int keynum,cl_entity_t_conflict2 *ent,model_t_conflict *model)

{
  uint uVar1;
  vec_t vVar2;
  dlight_t_conflict *pdVar3;
  int iVar4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: vec3_t oldorigin@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  if (model == (model_t_conflict *)0x0) {
    return;
  }
  local_18 = (ent->latched).prevorigin[0];
  local_14 = (ent->latched).prevorigin[1];
  local_10 = (ent->latched).prevorigin[2];
  uVar1 = ent->model->flags;
  if ((uVar1 & 4) == 0) {
    if ((uVar1 & 0x20) == 0) {
      if ((uVar1 & 0x10) == 0) {
        if ((uVar1 & 0x40) == 0) {
          if ((uVar1 & 1) != 0) {
            (*efx.R_RocketTrail)(&local_18,ent->origin,0);
            pdVar3 = (*efx.CL_AllocDlight)(keynum);
            pdVar3->origin[0] = ent->origin[0];
            pdVar3->origin[1] = ent->origin[1];
            vVar2 = ent->origin[2];
            pdVar3->radius = 200.0;
            (pdVar3->color).b = 200;
            (pdVar3->color).g = 200;
            pdVar3->origin[2] = vVar2;
            (pdVar3->color).r = 200;
            pdVar3->die = (float)((longdouble)0.01 + (longdouble)cl.time);
            return;
          }
          if ((uVar1 & 2) == 0) {
            if ((uVar1 & 0x80) == 0) {
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
  (*efx.R_RocketTrail)(&local_18,ent->origin,iVar4);
  return;
}


// CL_AddResource  @ 0019ddf0
resource_t *
CL_AddResource(resourcetype_t type,char *name,int size,qboolean bFatalIfMissing,int index)

{
  uchar *puVar1;
  resource_t *dest;
  int iVar2;
  
                    /* Unresolved local var: resource_t * r@[???] */
  iVar2 = cl.num_resources;
  dest = cl.resourcelist + cl.num_resources;
  if (0x4ff < cl.num_resources) {
    Sys_Error("Too many resources on client.");
  }
  cl.num_resources = cl.num_resources + 1;
  cl.resourcelist[iVar2].type = type;
  Q_strncpy(dest->szFileName,name,0x3f);
  cl.resourcelist[iVar2].szFileName[0x3f] = '\0';
  cl.resourcelist[iVar2].nDownloadSize = size;
  puVar1 = &cl.resourcelist[iVar2].ucFlags;
  *puVar1 = *puVar1 | bFatalIfMissing != false;
  cl.resourcelist[iVar2].nIndex = index;
  return dest;
}


// CL_AddStateToEntlist  @ 0018e630
void CL_AddStateToEntlist(physent_t_conflict *pe,entity_state_t_conflict *state)

{
  int iVar1;
  model_t *pmVar2;
  
  iVar1 = state->number;
  pe->info = iVar1;
  if ((0 < iVar1) && (iVar1 <= cl.maxclients)) {
    pe->player = iVar1;
  }
  pe->origin[0] = state->origin[0];
  pe->origin[1] = state->origin[1];
  pe->origin[2] = state->origin[2];
  pe->angles[0] = state->angles[0];
  pe->angles[1] = state->angles[1];
  pe->angles[2] = state->angles[2];
  pe->mins[0] = state->mins[0];
  pe->mins[1] = state->mins[1];
  pe->mins[2] = state->mins[2];
  pe->maxs[0] = state->maxs[0];
  pe->maxs[1] = state->maxs[1];
  pe->maxs[2] = state->maxs[2];
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
LAB_0018e73d:
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
      goto LAB_0018e76b;
    }
    pmVar2 = CL_GetModelByIndex(state->modelindex);
    if (pmVar2->type != mod_studio) goto LAB_0018e73d;
    pe->model = (model_s_conflict1 *)0x0;
    pmVar2 = CL_GetModelByIndex(state->modelindex);
    pe->studiomodel = (model_s_conflict1 *)pmVar2;
  }
  Q_strncpy(pe->name,pmVar2->name,0x20);
  pe->name[0x1f] = '\0';
LAB_0018e76b:
  pe->iuser1 = state->iuser1;
  pe->iuser2 = state->iuser2;
  pe->iuser3 = state->iuser3;
  pe->iuser4 = state->iuser4;
  pe->fuser1 = state->fuser1;
  pe->fuser2 = state->fuser2;
  pe->fuser3 = state->fuser3;
  pe->fuser4 = state->fuser4;
  pe->vuser1[0] = state->vuser1[0];
  pe->vuser1[1] = state->vuser1[1];
  pe->vuser1[2] = state->vuser1[2];
  pe->vuser2[0] = state->vuser2[0];
  pe->vuser2[1] = state->vuser2[1];
  pe->vuser2[2] = state->vuser2[2];
  pe->vuser3[0] = state->vuser3[0];
  pe->vuser3[1] = state->vuser3[1];
  pe->vuser3[2] = state->vuser3[2];
  pe->vuser4[0] = state->vuser4[0];
  pe->vuser4[1] = state->vuser4[1];
  pe->vuser4[2] = state->vuser4[2];
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


// CL_AddToResourceList  @ 001ad210
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
  Sys_Error("Resource list corrupted.\n");
  return;
}


// CL_AddToServerCache  @ 0019cce0
void CL_AddToServerCache(server_cache_t *server)

{
  qboolean qVar1;
  int iVar2;
  server_cache_t *psVar3;
  byte bVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float fCurrentTime@[???] */
  bVar4 = 0;
  if (num_servers < 0x10) {
    if ((0.0 < cl_slisttimeout.value) && (cl_slisttimeout.value <= (float)realtime - cls.slist_time)
       ) {
      return;
    }
    if (0 < num_servers) {
      iVar2 = 0;
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
    cached_servers[num_servers].inuse = 1;
    num_servers = num_servers + 1;
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


// CL_AddVisibleEntity  @ 001a3770
int CL_AddVisibleEntity(cl_entity_t *pEntity)

{
  model_s *pmVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  mnode_t *pmVar5;
  int iVar6;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???] */
  iVar6 = 0;
  pmVar1 = pEntity->model;
  if (pmVar1 != (model_s *)0x0) {
    local_2c = pmVar1->mins[0] + pEntity->origin[0];
    local_1c = pEntity->origin[0] + pmVar1->maxs[0];
    local_28 = pmVar1->mins[1] + pEntity->origin[1];
    local_18 = pEntity->origin[1] + pmVar1->maxs[1];
    local_24 = pmVar1->mins[2] + pEntity->origin[2];
    local_14 = pEntity->origin[2] + pmVar1->maxs[2];
    pmVar5 = PVSNode((cl.worldmodel)->nodes,&local_2c,&local_1c);
    if (pmVar5 != (mnode_t *)0x0) {
      vVar2 = pEntity->angles[0];
      iVar6 = 1;
      vVar3 = pEntity->angles[1];
      vVar4 = pEntity->angles[2];
      (pEntity->curstate).angles[0] = vVar2;
      (pEntity->curstate).angles[1] = vVar3;
      (pEntity->curstate).angles[2] = vVar4;
      (pEntity->latched).prevangles[0] = vVar2;
      (pEntity->latched).prevangles[1] = vVar3;
      (pEntity->latched).prevangles[2] = vVar4;
      ClientDLL_AddEntity(2,pEntity);
    }
  }
  return iVar6;
}


// CL_AddVoiceToDatagram  @ 0011f550
void CL_AddVoiceToDatagram(qboolean bFinal)

{
  qboolean qVar1;
  int iSize;
  char local_80c [2056];
  
                    /* Unresolved local var: char[2048] uchVoiceData@[???]
                       Unresolved local var: int nDataLength@[???]
                       Unresolved local var: sizebuf_t * pBuf@[???] */
  if (cls.state == ca_active) {
    qVar1 = Voice_IsRecording();
    if (qVar1 != 0) {
      iSize = Voice_GetCompressedData(local_80c,0x800,bFinal);
      if ((iSize != 0) && (iSize + 3 + cls.datagram.cursize < cls.datagram.maxsize)) {
        MSG_WriteByte(&cls.datagram,8);
        MSG_WriteShort(&cls.datagram,(int)(short)iSize);
        MSG_WriteBuf(&cls.datagram,iSize,local_80c);
      }
    }
  }
  return;
}


// CL_AdjustClock  @ 0018fe30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_AdjustClock(void)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double msec@[???]
                       Unresolved local var: double adjust@[???]
                       Unresolved local var: double sign@[???] */
  lVar1 = (longdouble)g_clockdelta;
  if (((lVar1 != (longdouble)0) &&
      (lVar2 = (longdouble)cl_fixtimerate.value, lVar2 != (longdouble)0)) &&
     ((longdouble)0.001 <= ABS(lVar1))) {
    if (lVar2 < (longdouble)0) {
      lVar2 = (longdouble)7.5;
      cl_fixtimerate.value = (float)lVar2;
    }
    lVar3 = (longdouble)1;
    if ((longdouble)0 <= (longdouble)(int)(lVar1 * (longdouble)1000.0)) {
      lVar3 = -lVar3;
    }
    lVar4 = ABS((longdouble)(int)(lVar1 * (longdouble)1000.0));
    if (lVar4 < lVar2) {
      lVar2 = lVar4;
    }
    lVar3 = (lVar2 / (longdouble)1000.0) * lVar3;
    if (ABS(lVar3) < ABS(lVar1)) {
      g_clockdelta = (double)(lVar1 + lVar3);
      lVar3 = lVar3 + (longdouble)cl.time;
      cl.time = (double)lVar3;
    }
    else {
      lVar3 = (longdouble)cl.time;
    }
    if (lVar3 < (longdouble)cl.oldtime) {
      cl.oldtime = (double)lVar3;
    }
  }
  return;
}


// CL_AllocCustomTempEntity  @ 001ab7e0
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


// CL_AllocDlight  @ 001a19e0
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
      if (*(int *)(((lightstyle_t *)dest)->map + 0x1c) == key) goto LAB_001a1a11;
      dest = (dlight_t *)(((lightstyle_t *)dest)->map + 0x24);
      iVar2 = iVar2 + 1;
    } while ((lightstyle_t *)dest != cl_lightstyle);
  }
  dest = cl_dlights;
  iVar2 = 0;
  while (cl.time <= (double)*(float *)(((lightstyle_t *)dest)->map + 0x10)) {
    iVar2 = iVar2 + 1;
    dest = (dlight_t *)(((lightstyle_t *)dest)->map + 0x24);
    if (iVar2 == 0x20) {
      Q_memset(cl_dlights,0,0x28);
      cl_dlights[0].key = key;
      r_dlightchanged = r_dlightchanged | 1;
      r_dlightactive = r_dlightactive | 1;
      return cl_dlights;
    }
  }
LAB_001a1a11:
  Q_memset(dest,0,0x28);
  *(int *)(((lightstyle_t *)dest)->map + 0x1c) = key;
  uVar1 = 1 << ((byte)iVar2 & 0x1f);
  r_dlightchanged = r_dlightchanged | uVar1;
  r_dlightactive = r_dlightactive | uVar1;
  return (dlight_t *)(lightstyle_t *)dest;
}


// CL_AllocElight  @ 001a1ac0
dlight_t * CL_AllocElight(int key)

{
  dlight_t *dest;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * el@[???] */
  if (key != 0) {
    dest = cl_elights;
    do {
      if (dest->key == key) goto LAB_001a1ae8;
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
LAB_001a1ae8:
  Q_memset(dest,0,0x28);
  dest->key = key;
  return dest;
}


// CL_AppendDemo_f  @ 00196370
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_AppendDemo_f(void)

{
  demoentry_t *pdVar1;
  FileHandle_t file;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  FileHandle_t file_00;
  uint uVar5;
  uint uVar6;
  longdouble lVar7;
  int local_744;
  undefined1 local_734 [1024];
  char local_334 [260];
  char local_230 [260];
  char local_12c [260];
  float local_28;
  int32 local_24;
  undefined1 local_1d [13];
  
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
  if (cmd_source == src_command) {
    if ((cls.demorecording == false) && (cls.demoplayback == false)) {
      if (cls.state == ca_active) {
        iVar2 = Cmd_Argc();
        if (iVar2 - 2U < 2) {
          pcVar3 = Cmd_Argv(1);
          pcVar3 = Q_strstr(pcVar3,"..");
          if (pcVar3 == (char *)0x0) {
            local_744 = -1;
            if (iVar2 == 3) {
              pcVar3 = Cmd_Argv(2);
              local_744 = Q_atoi(pcVar3);
              Con_Printf("Forcing CD track to %i\n",local_744);
            }
            pcVar3 = Cmd_Argv(1);
            snprintf(local_334,0x100,"%s",pcVar3);
            COM_DefaultExtension(local_334,".dem");
            qVar4 = COM_HasFileExtension(local_334,"dem");
            if (qVar4 == false) {
              Con_Printf("Error: couldn\'t open %s, demo files must have .dem extension.\n",
                         local_334);
            }
            else {
              Con_Printf("Appending to demo %s.\n",local_334);
              Q_strncpy(cls.demofilename,local_334,0xff);
              cls.demofilename[0xff] = '\0';
              file_00 = FS_OpenPathID(local_334,"rb","GAMECONFIG");
              if (file_00 == (FileHandle_t)0x0) {
                Con_Printf("Error:  couldn\'t open demo file %s for appending.\n",local_334);
              }
              else {
                COM_StripExtension(local_334,local_230);
                COM_AddExtension(local_230,".dm2",0x104);
                qVar4 = COM_HasFileExtension(local_230,"dm2");
                if (qVar4 == false) {
                  Con_Printf("Error: could not open temporary file %s.\n",local_230);
                  FS_Close(file_00);
                }
                else {
                  cls.demofile = FS_OpenPathID(local_230,"w+b","GAMECONFIG");
                  if (cls.demofile == (FileHandle_t)0x0) {
                    Con_Printf("ERROR: couldn\'t open %s.\n",local_334);
                    FS_Close(file_00);
                  }
                  else {
                    FS_Seek(file_00,0,FILESYSTEM_SEEK_TAIL);
                    uVar5 = FS_Tell(file_00);
                    FS_Seek(file_00,0,FILESYSTEM_SEEK_HEAD);
                    FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
                    file = cls.demofile;
                    /* Unresolved local var: int copysize@[???]
                       Unresolved local var: char[1024] copybuf@[???] */
                    uVar6 = uVar5;
                    if (0x400 < (int)uVar5) {
                      do {
                        uVar6 = uVar6 - 0x400;
                        FS_Read(local_734,0x400,1,file_00);
                        FS_Write(local_734,0x400,1,file);
                      } while (0x400 < (int)uVar6);
                      uVar5 = (uVar5 - 0x400) - (uVar5 - 0x401 & 0xfffffc00);
                    }
                    FS_Read(local_734,uVar5,1,file_00);
                    FS_Write(local_734,uVar5,1,file);
                    FS_Flush(file_00);
                    FS_Flush(file);
                    FS_Close(file_00);
                    FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
                    FS_Read(&demoheader,0x220,1,cls.demofile);
                    iVar2 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
                    if (iVar2 == 0) {
                      COM_FileBase((cl.worldmodel)->name,local_12c);
                      iVar2 = Q_strcmp(demoheader.szMapName,local_12c);
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
                            snprintf(pCurrentEntry->szDescription,0x40,"Playback \'%i\'",
                                     demodir.nEntries + -1);
                            pdVar1 = pCurrentEntry;
                            pCurrentEntry->nFlags = 0;
                            pdVar1->nCDTrack = local_744;
                            pdVar1->fTrackTime = 0.0;
                            uVar5 = FS_Tell(cls.demofile);
                            local_1d[0] = 2;
                            cls.demostarttime = (float)realtime;
                            pdVar1->nOffset = uVar5;
                            cls.demoframecount = 0;
                            cls.demostartframe = host_framecount;
                            FS_Write(local_1d,1,1,cls.demofile);
                            lVar7 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
                            local_28 = (float)lVar7;
                            FS_Write(&local_28,4,1,cls.demofile);
                            local_24 = (*LittleLong)(host_framecount - cls.demostartframe);
                            FS_Write(&local_24,4,1,cls.demofile);
                            cls.demorecording = true;
                            cls.demowaiting = true;
                            cls.demoappending = true;
                            cls.td_lastframe = -1;
                            cls.td_startframe = host_framecount;
                            return;
                          }
                          Con_Printf("ERROR: demo had bogus # of directory entries:  %i\n",
                                     demodir.nEntries);
                          FS_Close(cls.demofile);
                          cls.demofile = (FileHandle_t)0x0;
                          return;
                        }
                        Con_Printf("ERROR: demo protocol outdated\nDemo file protocols %iN:%iD\nServer protocol is at %iN:%iD\n"
                                   ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
                      }
                      else {
                        Con_Printf("%s was recorded on a different map, cannot append.\n",local_334)
                        ;
                      }
                    }
                    else {
                      Con_Printf("%s is not a demo file\n",local_334);
                    }
                    unlink(local_230);
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
  return;
}


// CL_BatchResourceRequest  @ 001ad400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_BatchResourceRequest(void)

{
  resource_s *prVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  resource_t *prVar5;
  qboolean qVar6;
  resource_t *prVar7;
  resource_s *pResource;
  byte abStack_1012c [65536];
  char local_12c [256];
  sizebuf_t local_2c;
  
                    /* Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  Q_memset(&local_2c,0,0x14);
  local_2c.data = abStack_1012c;
  local_2c.cursize = 0;
  local_2c.buffername = "Client to Server Resource Batch";
  local_2c.maxsize = 0x10000;
  CL_HTTPStop_f();
  if ((cl.resourcesneeded.pNext != (resource_s *)0x0) &&
     (pResource = cl.resourcesneeded.pNext, cl.resourcesneeded.pNext != &cl.resourcesneeded)) {
    do {
      prVar1 = pResource->pNext;
      if ((pResource->ucFlags & 2) == 0) goto switchD_001ad4dc_caseD_1;
      if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
        Con_Printf("Skipping in game download of %s\n",pResource);
        CL_MoveToOnHandList(pResource);
        goto joined_r0x001ad51a;
      }
      qVar6 = IsSafeFileToDownload(pResource->szFileName);
      if (qVar6 == false) {
        if ((pResource->pPrev == (resource_s *)0x0) ||
           (prVar5 = pResource->pNext, prVar5 == (resource_t *)0x0)) {
          Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
          prVar5 = pResource->pNext;
        }
        if ((pResource == prVar5) || (prVar7 = pResource->pPrev, pResource == prVar7)) {
          Sys_Error("Attempt to free last entry in list.");
          prVar7 = pResource->pPrev;
          prVar5 = pResource->pNext;
        }
        prVar7->pNext = prVar5;
        pResource->pNext->pPrev = pResource->pPrev;
        pResource->pPrev = (resource_s *)0x0;
        pResource->pNext = (resource_s *)0x0;
        Con_Printf("Invalid file type...skipping download of %s\n",pResource);
        Mem_Free(pResource);
        goto joined_r0x001ad51a;
      }
      switch(pResource->type) {
      case t_sound:
        if (pResource->szFileName[0] != '*') {
          pcVar4 = va("sound/%s",pResource);
          qVar6 = CL_CheckFile(&local_2c,pcVar4);
          if (qVar6 == false) break;
        }
      case t_skin:
switchD_001ad4dc_caseD_1:
        CL_MoveToOnHandList(pResource);
        break;
      case t_model:
        if (pResource->szFileName[0] != '*') goto switchD_001ad4dc_caseD_4;
        goto switchD_001ad4dc_caseD_1;
      case t_decal:
        qVar6 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
        if (qVar6 != false) goto switchD_001ad4dc_caseD_1;
        if ((pResource->ucFlags & 8) == 0) {
                    /* Unresolved local var: char[256] filename@[???] */
          pcVar4 = COM_BinPrintf(pResource->rgucMD5_hash,0x10);
          snprintf(local_12c,0x100,"!MD5%s",pcVar4);
          MSG_WriteByte(&local_2c,3);
          pcVar4 = va("dlfile %s",local_12c);
          MSG_WriteString(&local_2c,pcVar4);
          pResource->ucFlags = pResource->ucFlags | 8;
        }
        break;
      case t_generic:
      case t_eventscript:
switchD_001ad4dc_caseD_4:
        qVar6 = CL_CheckFile(&local_2c,pResource->szFileName);
        if (qVar6 != false) {
          CL_MoveToOnHandList(pResource);
        }
      }
joined_r0x001ad51a:
    } while ((prVar1 != (resource_s *)0x0) && (pResource = prVar1, prVar1 != &cl.resourcesneeded));
  }
  iVar2 = CL_GetDownloadQueueSize();
  if (0 < iVar2) {
                    /* Unresolved local var: char[128] tmpUrl@[???] */
    uVar3 = 0;
    do {
      *(undefined4 *)(local_12c + uVar3) = *(undefined4 *)(cl.downloadUrl + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x80);
    CL_MarkMapAsUsingHTTPDownload();
    CL_Disconnect();
    iVar2 = CL_GetDownloadQueueSize();
    StartLoadingProgressBar(local_12c,iVar2);
    SetLoadingProgressBarStatusText("#GameUI_VerifyingAndDownloading");
  }
  if (cls.state != ca_disconnected) {
    if ((local_2c.cursize == 0) && (qVar6 = CL_PrecacheResources(), qVar6 != false)) {
      CL_RegisterResources(&local_2c);
    }
    if (cls.passive == false) {
      Netchan_CreateFragments(false,&cls.netchan,&local_2c);
      Netchan_FragSend(&cls.netchan);
      return;
    }
  }
  return;
}


// CL_BeginDemoStartup  @ 00199440
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


// CL_BeginUpload_f  @ 0019b590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_BeginUpload_f(void)

{
  uchar *hash;
  char *pcVar1;
  int iVar2;
  qboolean qVar3;
  resource_s local_13c;
  MD5Context_t local_b4;
  uchar local_5c [16];
  uchar local_4c [16];
  uchar *local_3c [4];
  uint local_2c [7];
  
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: uchar * buf@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: resource_t custResource@[???] */
  local_3c[0] = (uchar *)0x0;
  local_2c[0] = 0;
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
      Q_memset(&local_13c,0,0x88);
      COM_HexConvert(pcVar1 + 4,0x20,local_5c);
      qVar3 = HPAK_ResourceForHash("custom.hpk",local_5c,&local_13c);
      if (qVar3 != false) {
        hash = local_13c.rgucMD5_hash;
        iVar2 = Q_memcmp(local_5c,hash,0x10);
        if (iVar2 != 0) {
          Con_DPrintf("Bogus data retrieved from custom.hpk, attempting to delete entry\n");
          HPAK_RemoveLump("custom.hpk",&local_13c);
          return;
        }
        qVar3 = HPAK_GetDataPointer("custom.hpk",&local_13c,local_3c,(int *)local_2c);
        if (qVar3 != false) {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
          Q_memset(&local_b4,0,0x58);
          MD5Init(&local_b4);
          MD5Update(&local_b4,local_3c[0],local_2c[0]);
          MD5Final(local_4c,&local_b4);
          iVar2 = Q_memcmp(hash,local_4c,0x10);
          if (iVar2 != 0) {
            Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
            pcVar1 = MD5_Print(hash);
            Con_Printf("Purported:  %s\n",pcVar1);
            pcVar1 = MD5_Print(local_4c);
            Con_Printf("Actual   :  %s\n",pcVar1);
            Con_Printf("Removing conflicting lump\n");
            HPAK_RemoveLump("custom.hpk",&local_13c);
            return;
          }
        }
      }
      if ((local_3c[0] == (uchar *)0x0) || (local_2c[0] == 0)) {
        Con_Printf("Ingoring customization upload, couldn\'t find decal locally\n");
      }
      else {
        Netchan_CreateFileFragmentsFromBuffer(false,&cls.netchan,pcVar1,local_3c[0],local_2c[0]);
        Netchan_FragSend(&cls.netchan);
        Mem_Free(local_3c[0]);
      }
    }
    else {
      Con_Printf("Ingoring upload of non-customization\n");
    }
  }
  return;
}


// CL_BoundInterpolationFraction  @ 00194d40
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


// CL_BuildMapCycleListHints  @ 001ae510
int CL_BuildMapCycleListHints(char **hints,char *mapCycleMsg,char *firstMap)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  uint local_538 [130];
  undefined1 local_32d;
  uint local_32c [131];
  char local_120 [272];
  
                    /* Unresolved local var: char[524] szMap@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char * aFileList@[???]
                       Unresolved local var: char[260] szMod@[???] */
  sVar1 = strlen(mapCycleMsg);
  COM_FileBase(com_gamedir,local_120);
  if ((sVar1 == 0) || (mapCycleMsg == (char *)0x0)) {
    iVar2 = 1;
  }
  else {
    pcVar3 = GetCurrentSteamAppName();
    pcVar8 = szCommonPreloads;
    pcVar7 = szReslistsExt;
    pcVar4 = GetCurrentSteamAppName();
    sprintf((char *)local_538,"%s\\%s\\%s%s\r\n%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar4,pcVar8,
            pcVar7,szReslistsBaseDir,pcVar3,firstMap,pcVar7);
    puVar10 = local_538;
    do {
      puVar9 = puVar10;
      uVar5 = *puVar9 + 0xfefefeff & ~*puVar9;
      uVar6 = uVar5 & 0x80808080;
      puVar10 = puVar9 + 1;
    } while (uVar6 == 0);
    if ((uVar5 & 0x8080) == 0) {
      puVar10 = (uint *)((int)puVar9 + 6);
      uVar6 = uVar6 >> 0x10;
    }
    pcVar7 = Mem_ZeroMalloc((size_t)((int)puVar10 +
                                    (-(int)local_538 - (uint)CARRY1((byte)uVar6,(byte)uVar6)) + -2))
    ;
    *hints = pcVar7;
    iVar2 = 0;
    if (pcVar7 != (char *)0x0) {
                    /* Unresolved local var: char[524] mapLine@[???] */
      strcpy(pcVar7,(char *)local_538);
      while( true ) {
        do {
          mapCycleMsg = COM_Parse(mapCycleMsg);
          if (com_token[0] == '\0') {
            pcVar7 = GetCurrentSteamAppName();
            sprintf((char *)local_538,"%s\\%s\\mp_maps.txt\r\n",szReslistsBaseDir,pcVar7);
            pcVar7 = *hints;
            sVar1 = strlen(pcVar7);
            puVar10 = local_538;
            do {
              puVar9 = puVar10;
              uVar5 = *puVar9 + 0xfefefeff & ~*puVar9;
              uVar6 = uVar5 & 0x80808080;
              puVar10 = puVar9 + 1;
            } while (uVar6 == 0);
            if ((uVar5 & 0x8080) == 0) {
              puVar10 = (uint *)((int)puVar9 + 6);
              uVar6 = uVar6 >> 0x10;
            }
            pcVar7 = realloc(pcVar7,(size_t)((int)puVar10 +
                                            sVar1 + (-(int)local_538 -
                                                    (uint)CARRY1((byte)uVar6,(byte)uVar6)) + -1));
            *hints = pcVar7;
            strcat(pcVar7,(char *)local_538);
            return 1;
          }
          strncpy((char *)local_538,com_token,0x20b);
          local_32d = 0;
          iVar2 = COM_TokenWaiting(mapCycleMsg);
          if (iVar2 != 0) {
            mapCycleMsg = COM_Parse(mapCycleMsg);
          }
          iVar2 = PF_IsMapValid_I((char *)local_538);
        } while ((iVar2 == 0) ||
                (iVar2 = strcmp(firstMap,(char *)local_538), pcVar7 = szReslistsExt, iVar2 == 0
                    /* Unresolved local var: size_t __s1_len@[???]
                       Unresolved local var: size_t __s2_len@[???] */));
        pcVar8 = GetCurrentSteamAppName();
        sprintf((char *)local_32c,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar8,local_538,pcVar7);
        pcVar7 = *hints;
        sVar1 = strlen(pcVar7);
        puVar10 = local_32c;
        do {
          puVar9 = puVar10;
          uVar5 = *puVar9 + 0xfefefeff & ~*puVar9;
          uVar6 = uVar5 & 0x80808080;
          puVar10 = puVar9 + 1;
        } while (uVar6 == 0);
        if ((uVar5 & 0x8080) == 0) {
          puVar10 = (uint *)((int)puVar9 + 6);
          uVar6 = uVar6 >> 0x10;
        }
        pcVar7 = Mem_Realloc(pcVar7,(size_t)((int)puVar10 +
                                            sVar1 + (-(int)local_32c -
                                                    (uint)CARRY1((byte)uVar6,(byte)uVar6)) + -1));
        *hints = pcVar7;
        if (pcVar7 == (char *)0x0) break;
        strcat(pcVar7,(char *)local_32c);
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}


// CL_CalcPlayerVelocity  @ 00191220
void CL_CalcPlayerVelocity(int idx,vec_t *velocity)

{
  float fVar1;
  float fVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  float local_1c;
  float local_18;
  float local_14;
  
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
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float dt@[???] */
      fVar1 = cl_entities[idx].curstate.velocity[0];
      local_1c = fVar1 - cl_entities[idx].prevstate.velocity[0];
      local_18 = cl_entities[idx].curstate.velocity[1] - cl_entities[idx].prevstate.velocity[1];
      local_14 = cl_entities[idx].curstate.velocity[2] - cl_entities[idx].prevstate.velocity[2];
      fVar2 = cl_entities[idx].curstate.animtime - cl_entities[idx].prevstate.animtime;
      if (fVar2 == 0.0) {
        *velocity = fVar1;
        pcVar3 = cl_entities;
        velocity[1] = cl_entities[idx].curstate.velocity[1];
        velocity[2] = pcVar3[idx].curstate.velocity[2];
        return;
      }
      VectorScale(&local_1c,1.0 / fVar2,velocity);
    }
  }
  return;
}


// CL_CalculateDevOverviewParameters  @ 00195240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CalculateDevOverviewParameters(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  mvertex_t *pmVar9;
  int iVar10;
  float local_8;
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
    fVar1 = -64000.0;
    gDevOverview.z_min = -31999.0;
    gDevOverview.z_max = 31999.0;
    local_4 = -64000.0;
    gDevOverview.origin[0] = 0.0;
    gDevOverview.origin[1] = 0.0;
    gDevOverview.origin[2] = 0.0;
  }
  else {
    iVar10 = 0;
    pmVar9 = (cl.worldmodel)->vertexes;
    local_8 = 32000.0;
    fVar5 = -32000.0;
    fVar4 = 32000.0;
    fVar8 = 32000.0;
    fVar6 = -32000.0;
    fVar7 = -32000.0;
    do {
      fVar1 = pmVar9->position[0];
      fVar2 = pmVar9->position[1];
      fVar3 = pmVar9->position[2];
      if (fVar7 < fVar1) {
        fVar7 = fVar1;
      }
      if (fVar5 < fVar2) {
        fVar5 = fVar2;
      }
      if (fVar6 < fVar3) {
        fVar6 = fVar3;
      }
      if (fVar1 < fVar8) {
        fVar8 = fVar1;
      }
      if (fVar2 < local_8) {
        local_8 = fVar2;
      }
      if (fVar3 < fVar4) {
        fVar4 = fVar3;
      }
      iVar10 = iVar10 + 1;
      pmVar9 = pmVar9 + 1;
    } while (iVar10 != (cl.worldmodel)->numvertexes);
    fVar1 = fVar7 - fVar8;
    local_4 = fVar5 - local_8;
    gDevOverview.z_min = fVar6 + 1.0;
    gDevOverview.z_max = fVar4 - 1.0;
    gDevOverview.origin[0] = (fVar8 + fVar7) * 0.5;
    gDevOverview.origin[1] = (fVar5 + local_8) * 0.5;
    gDevOverview.origin[2] = (fVar4 + fVar6) * 0.5;
    if (fVar1 < local_4) {
      gDevOverview.rotated = false;
      fVar1 = 8192.0 / (fVar1 * 1.3333);
      gDevOverview.zoom = 8192.0 / local_4;
      if (fVar1 < 8192.0 / local_4) {
        gDevOverview.zoom = fVar1;
      }
      return;
    }
  }
  gDevOverview.rotated = true;
  gDevOverview.zoom = 8192.0 / (local_4 * 1.3333);
  if (8192.0 / fVar1 < gDevOverview.zoom) {
    gDevOverview.zoom = 8192.0 / fVar1;
  }
  return;
}


// CL_CanUseHTTPDownload  @ 00183ee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_CanUseHTTPDownload(void)

{
  char **ppcVar1;
  int iVar2;
  int iVar3;
  char *__s1;
  int iVar4;
  
  iVar3 = 0;
  if (cl.downloadUrl[0] != '\0') {
                    /* Unresolved local var: char * serverMapName@[???] */
    __s1 = DL_SharedVarArgs("%s:%s",0xe0a50c,0xdf7bf8);
    iVar2 = TheDownloadManager.m_downloadedMaps.m_Size;
    ppcVar1 = TheDownloadManager.m_downloadedMaps.m_Memory.m_pMemory;
    iVar3 = 1;
                    /* Unresolved local var: int i@[???] */
    if ((__s1 != (char *)0x0) && (0 < TheDownloadManager.m_downloadedMaps.m_Size)) {
      iVar3 = 0;
      do {
                    /* Unresolved local var: char * oldServerMapName@[???] */
        if ((ppcVar1[iVar3] != (char *)0x0) && (iVar4 = strcasecmp(__s1,ppcVar1[iVar3]), iVar4 == 0)
           ) {
          return 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != iVar2);
      iVar3 = 1;
    }
  }
  return iVar3;
}


// CL_CheckCRCs  @ 001ac7e0
qboolean CL_CheckCRCs(char *pszMap)

{
  qboolean qVar1;
  BOOL BVar2;
  int iVar3;
  char *fmt;
  char local_4c [72];
  
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
        fmt = "#GameUI_ConnectionFailed";
        goto LAB_001ac98d;
      }
      if (cl_allow_download.value == 0.0) {
        fmt = "Refusing to download map %s, (cl_allow_download is 0 ) disconnecting.\n";
        goto LAB_001ac98d;
      }
      Con_Printf("Couldn\'t find map %s, server will download the map\n",pszMap);
      cl.mapCRC = cl.serverCRC;
    }
    else if ((cl.serverCRC != cl.mapCRC) && (cls.demoplayback == false)) {
      fmt = "Your map [%s] differs from the server\'s.";
      goto LAB_001ac98d;
    }
  }
  if (gmodinfo.clientcrccheck != false) {
                    /* Unresolved local var: char[64] szDllName@[???] */
    pszMap = local_4c;
    snprintf(pszMap,0x40,"cl_dlls//client.dll");
    BVar2 = MD5_Hash_File(cls.md5_clientdll,pszMap,0,0,(uint *)0x0);
    if (BVar2 == 0) {
      fmt = "Couldn\'t CRC client side dll %s.";
LAB_001ac98d:
      COM_ExplainDisconnection(true,fmt,pszMap);
      Host_Error("Disconnected");
      return false;
    }
    iVar3 = Q_memcmp(cl.clientdllmd5,cls.md5_clientdll,0x10);
    if (iVar3 != 0) {
      if ((cls.demoplayback == false) && (cls.spectator == false)) {
        fmt = "Your .dll [%s] differs from the server\'s.";
        goto LAB_001ac98d;
      }
      Con_Printf("Your client side .dll [%s] failed the CRC check.\nThe .dll may be out of date, or the demo may have been recorded using an old version of the .dll.\nConsider obtaining an updated version of the .dll from the server operator.\nDemo playback proceeding.\n"
                 ,pszMap);
    }
  }
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_CheckCRCs()");
    return true;
  }
  return true;
}


// CL_CheckClientState  @ 0019cad0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CheckClientState(void)

{
  startup_timing_t *psVar1;
  netadr_t *pnVar2;
  startup_timing_t *psVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  
  if ((cls.state - ca_connected < 2) && (cls.signon == 2)) {
    cls.state = ca_active;
    if (fs_startup_timings.value != 0.0) {
                    /* Unresolved local var: int i@[???] */
      Con_Printf("Startup timings (%.2f total)\n",
                 (double)(g_StartupTimings[g_iCurrentTiming].time - g_StartupTimings[0].time));
      Con_Printf("    0.00    Startup\n");
      if (0 < g_iCurrentTiming) {
        iVar6 = 1;
        do {
          psVar3 = g_StartupTimings + iVar6;
          iVar4 = iVar6 * 2;
          psVar1 = g_StartupTimings + iVar6;
          iVar6 = iVar6 + 1;
          Con_Printf("    %.2f    %s\n",
                     (double)(psVar3->time - (float)(&cl_efrags[0x27f].entnext)[iVar4]),psVar1->name
                    );
        } while (iVar6 <= g_iCurrentTiming);
      }
    }
                    /* Unresolved local var: uchar * IPPtr@[???]
                       Unresolved local var: short port@[???] */
    pnVar2 = &cls.netchan.remote_address;
    uVar5 = cls.netchan.remote_address.port;
    if (cls.netchan.remote_address.port == 0) {
      pnVar2 = &net_local_adr;
      uVar5 = net_local_adr.port;
    }
    uVar5 = Q_ntohs(uVar5);
    VGuiWrap2_NotifyOfServerConnect(com_gamedir,*(int *)pnVar2->ip,(uint)uVar5);
    return;
  }
  return;
}


// CL_CheckFile  @ 001ac410
qboolean CL_CheckFile(sizebuf_t *msg,char *filename)

{
  int iVar1;
  char *s;
  qboolean qVar2;
  char local_110 [259];
  undefined1 local_d;
  
                    /* Unresolved local var: char[260] file@[???] */
  Q_strncpy(local_110,filename,0x103);
  local_d = 0;
  if (cl_allow_download.value == 0.0) {
    Con_DPrintf("Download refused, cl_allow_download is 0\n");
    return true;
  }
  if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
    Con_DPrintf("In-game download refused...\n");
    return true;
  }
  iVar1 = FS_FileExists(local_110);
  qVar2 = true;
  if (iVar1 == 0) {
    if ((cls.passive == false) && (cls.demoplayback == false)) {
      iVar1 = CL_CanUseHTTPDownload();
      if (iVar1 == 0) {
        MSG_WriteByte(msg,3);
        s = va("dlfile %s",local_110);
        MSG_WriteString(msg,s);
        qVar2 = false;
      }
      else {
        CL_QueueHTTPDownload(local_110);
        qVar2 = false;
      }
    }
    else {
      Con_Printf("Warning! File %s missing during demo playback.\n",local_110);
      qVar2 = true;
    }
  }
  return qVar2;
}


// CL_CheckForResend  @ 001a12f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CheckForResend(void)

{
  netadr_t addr;
  netadr_t addr_00;
  netadr_t to;
  _func_short_short *p_Var1;
  int iVar2;
  qboolean qVar3;
  longdouble lVar4;
  longdouble lVar5;
  char local_930 [2048];
  char local_130 [259];
  undefined1 local_2d;
  netadr_t local_2c;
  
                    /* Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: char[2048] data@[???]
                       Unresolved local var: char[260] szServerName@[???] */
  if ((cls.state == ca_disconnected) && (qVar3 = Host_IsServerActive(), qVar3 != false)) {
    cls.state = ca_connecting;
    gfExtendedError = false;
    Q_strncpy(cls.servername,"localhost",0x103);
    cls.servername[0x103] = '\0';
    cls.authprotocol = '\x03';
    CL_SendConnectPacket();
  }
  else if (cls.state == ca_connecting) {
    if (cls.passive == false) {
      lVar4 = (longdouble)cl_resend.value;
      lVar5 = (longdouble)1.5;
      if ((lVar4 < lVar5) || (lVar5 = (longdouble)20.0, lVar5 < lVar4)) {
        Cvar_SetValue("cl_resend",(float)lVar5);
        lVar4 = (longdouble)cl_resend.value;
      }
      if (lVar4 <= (longdouble)realtime - (longdouble)cls.connect_time) {
        Q_strncpy(local_130,cls.servername,0x104);
        local_2d = 0;
        iVar2 = Q_stricmp(cls.servername,"local");
        if (iVar2 == 0) {
          snprintf(local_130,0x104,"%s","localhost");
        }
        qVar3 = NET_StringToAdr(local_130,&local_2c);
        p_Var1 = BigShort;
        if (qVar3 == false) {
          Con_Printf("Bad server address\n");
          cls.state = ca_disconnected;
          Q_memset(&g_GameServerAddress,0,0x14);
        }
        else {
          if (local_2c.port == 0) {
            iVar2 = Q_atoi("27015");
            local_2c.port = (*p_Var1)((short)iVar2);
          }
          if (cls.connect_retry < 4) {
            cls.connect_time = realtime;
            iVar2 = Q_stricmp(local_130,"localhost");
            if (iVar2 != 0) {
              if (cls.connect_retry == 0) {
                Con_Printf("Connecting to %s...\n",local_130);
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
                Con_Printf("Retrying %s...\n",local_130);
              }
            }
            cls.connect_retry = cls.connect_retry + 1;
            snprintf(local_930,0x800,"%c%c%c%cgetchallenge steam\n",0xff,0xff,0xff,0xff);
            g_GameServerAddress.type = local_2c.type;
            g_GameServerAddress.ip[0] = local_2c.ip[0];
            g_GameServerAddress.ip[1] = local_2c.ip[1];
            g_GameServerAddress.ip[2] = local_2c.ip[2];
            g_GameServerAddress.ip[3] = local_2c.ip[3];
            g_GameServerAddress.ipx[0] = local_2c.ipx[0];
            g_GameServerAddress.ipx[1] = local_2c.ipx[1];
            g_GameServerAddress.ipx[2] = local_2c.ipx[2];
            g_GameServerAddress.ipx[3] = local_2c.ipx[3];
            g_GameServerAddress.ipx[4] = local_2c.ipx[4];
            g_GameServerAddress.ipx[5] = local_2c.ipx[5];
            g_GameServerAddress.ipx[6] = local_2c.ipx[6];
            g_GameServerAddress.ipx[7] = local_2c.ipx[7];
            g_GameServerAddress.ipx[8] = local_2c.ipx[8];
            g_GameServerAddress.ipx[9] = local_2c.ipx[9];
            g_GameServerAddress.port = local_2c.port;
            iVar2 = Q_strlen(local_930);
            to.ip[0] = local_2c.ip[0];
            to.ip[1] = local_2c.ip[1];
            to.ip[2] = local_2c.ip[2];
            to.ip[3] = local_2c.ip[3];
            to.type = local_2c.type;
            to.ipx[0] = local_2c.ipx[0];
            to.ipx[1] = local_2c.ipx[1];
            to.ipx[2] = local_2c.ipx[2];
            to.ipx[3] = local_2c.ipx[3];
            to.ipx[4] = local_2c.ipx[4];
            to.ipx[5] = local_2c.ipx[5];
            to.ipx[6] = local_2c.ipx[6];
            to.ipx[7] = local_2c.ipx[7];
            to.ipx[8] = local_2c.ipx[8];
            to.ipx[9] = local_2c.ipx[9];
            to.port = local_2c.port;
            NET_SendPacket(NS_CLIENT,iVar2,local_930,to);
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
  return;
}


// CL_CheckGameDirectory  @ 001ae470
qboolean CL_CheckGameDirectory(char *gamedir)

{
  qboolean qVar1;
  int iVar2;
  char local_110 [264];
  
                    /* Unresolved local var: char[260] szGD@[???] */
  if ((gamedir == (char *)0x0) || (*gamedir == '\0')) {
    Con_Printf("Server didn\'t specify a gamedir, assuming no change\n");
    qVar1 = true;
  }
  else {
    COM_FileBase(com_gamedir,local_110);
    iVar2 = Q_stricmp(local_110,gamedir);
    qVar1 = true;
    if (iVar2 != 0) {
      Con_Printf("Server is running game %s.  Restart in that game to connect.\n",gamedir);
      CL_Disconnect_f();
      qVar1 = false;
    }
  }
  return qVar1;
}


// CL_CheckPredictionError  @ 00192730
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CheckPredictionError(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int frame@[???]
                       Unresolved local var: int command@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float len@[???] */
  iVar2 = cl.parsecountmod;
  uVar3 = CL_UPDATE_MASK & cls.netchan.incoming_acknowledged;
  iVar1 = cl.parsecountmod * 0x42b8 + 0xc5474c + cl.playernum * 0x154;
  local_1c = *(float *)((int)__DT_SYMTAB + iVar1 + 0xef08) - cl.predicted_origins[uVar3][0];
  local_18 = *(float *)((int)__DT_SYMTAB + iVar1 + 0xef0c) - cl.predicted_origins[uVar3][1];
  local_14 = *(float *)((int)__DT_SYMTAB + iVar1 + 0xef10) - cl.predicted_origins[uVar3][2];
  fVar4 = Length(&local_1c);
  if (64.0 < fVar4) {
    cl.prediction_error[0] = vec3_origin[0];
    cl.prediction_error[1] = vec3_origin[1];
    cl.prediction_error[2] = vec3_origin[2];
  }
  else {
    if ((cl_showerror.value != 0.0) && (0.5 < fVar4)) {
      CL_CheckPredictionError::pos = CL_CheckPredictionError::pos + 1;
      Con_NPrintf((CL_CheckPredictionError::pos & 3U) + 10,"pred. error %.3f units",(double)fVar4);
    }
    iVar1 = iVar2 * 0x42b8 + 0xc5474c + cl.playernum * 0x154;
    cl.predicted_origins[iVar2][0] = *(vec_t *)((int)__DT_SYMTAB + iVar1 + 0xef08);
    cl.predicted_origins[iVar2][1] = *(vec_t *)((int)__DT_SYMTAB + iVar1 + 0xef0c);
    cl.predicted_origins[iVar2][2] = *(vec_t *)((int)__DT_SYMTAB + iVar1 + 0xef10);
    cl.prediction_error[0] = local_1c;
    cl.prediction_error[1] = local_18;
    cl.prediction_error[2] = local_14;
    if ((0.25 < fVar4) && (cl.maxclients != 1)) {
      cl_correction_time = (double)cl_smoothtime.value;
      return;
    }
  }
  return;
}


// CL_CleanFileName  @ 0019dca0
char * CL_CleanFileName(char *filename)

{
                    /* Unresolved local var: char * pfilename@[???] */
                    /* Unresolved local var: char * pfilename@[???] */
  if (((filename != (char *)0x0) && (*filename != '\0')) && (*filename == '!')) {
    filename = "customization";
  }
  return filename;
}


// CL_ClearCaches  @ 0019e030
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ClearCaches(void)

{
  char **ppcVar1;
  char **ppcVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  ppcVar2 = &cl.event_precache[1].pszScript;
  iVar4 = 1;
  do {
    if (*ppcVar2 == (char *)0x0) {
      return;
    }
    Mem_Free(*ppcVar2);
    ppcVar1 = ppcVar2 + -2;
    ppcVar2 = ppcVar2 + 4;
    Mem_Free(*ppcVar1);
    iVar3 = iVar4 + 1;
    Q_memset(cl.event_precache + iVar4,0,0x10);
    iVar4 = iVar3;
  } while (iVar3 != 0x100);
  return;
}


// CL_ClearClientState  @ 0019e0a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ClearClientState(void)

{
  char **ppcVar1;
  entity_state_s *p;
  int iVar2;
  int iVar3;
  int iVar4;
  char **ppcVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: packet_entities_t * pClientPack@[???] */
  if (0 < CL_UPDATE_BACKUP) {
    iVar2 = CL_UPDATE_BACKUP;
    iVar4 = 0;
    do {
      p = cl.frames[iVar4].packet_entities.entities;
      if (p != (entity_state_s *)0x0) {
        Mem_Free(p);
        iVar2 = CL_UPDATE_BACKUP;
      }
      iVar3 = iVar4 + 1;
      cl.frames[iVar4].packet_entities.entities = (entity_state_s *)0x0;
      cl.frames[iVar4].packet_entities.num_entities = 0;
      iVar4 = iVar3;
    } while (iVar3 < iVar2);
  }
  CL_ClearResourceLists();
  iVar2 = 0;
  do {
    iVar4 = iVar2 + 1;
    COM_ClearCustomizationList((customization_t *)&cl.players[iVar2].customdata,false);
    iVar2 = iVar4;
  } while (iVar4 != 0x20);
  ppcVar5 = &cl.event_precache[1].pszScript;
  iVar2 = 1;
  do {
    if (*ppcVar5 == (char *)0x0) break;
                    /* Unresolved local var: int i@[???] */
    Mem_Free(*ppcVar5);
    ppcVar1 = ppcVar5 + -2;
    ppcVar5 = ppcVar5 + 4;
    Mem_Free(*ppcVar1);
    iVar4 = iVar2 + 1;
    Q_memset(cl.event_precache + iVar2,0,0x10);
    iVar2 = iVar4;
  } while (iVar4 != 0x100);
  Q_memset(&cl,0,0x1af668);
  cl.resourcesonhand.pNext = &cl.resourcesonhand;
  cl.resourcesneeded.pPrev = &cl.resourcesneeded;
  cl.resourcesneeded.pNext = &cl.resourcesneeded;
  cl.resourcesonhand.pPrev = &cl.resourcesonhand;
  CL_CreateResourceList();
  return;
}


// CL_ClearPacket  @ 0018bfb0
void CL_ClearPacket(packet_entities_t *pPacket)

{
  if (pPacket->entities != (entity_state_s *)0x0) {
    Mem_Free(pPacket->entities);
  }
  pPacket->entities = (entity_state_s *)0x0;
  pPacket->num_entities = 0;
  return;
}


// CL_ClearResourceList  @ 001ac550
void CL_ClearResourceList(resource_t *pList)

{
  resource_s *prVar1;
  resource_t *p;
  resource_s *prVar2;
  resource_s *prVar3;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  p = pList->pNext;
  while ((pList != p && (p != (resource_t *)0x0))) {
    prVar1 = p->pNext;
    if ((p->pPrev == (resource_s *)0x0) || (prVar2 = prVar1, prVar1 == (resource_s *)0x0)) {
      Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
      prVar2 = p->pNext;
    }
    if ((p == prVar2) || (prVar3 = p->pPrev, p == prVar3)) {
      Sys_Error("Attempt to free last entry in list.");
      prVar3 = p->pPrev;
      prVar2 = p->pNext;
    }
    prVar3->pNext = prVar2;
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


// CL_ClearResourceLists  @ 001ac620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ClearResourceLists(void)

{
  resource_s *prVar1;
  resource_s *prVar2;
  resource_s *prVar3;
  resource_s *prVar4;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  cl.downloadUrl[0] = '\0';
  if ((cl.resourcesneeded.pNext != (resource_s *)0x0) &&
     (prVar4 = cl.resourcesneeded.pNext, cl.resourcesneeded.pNext != &cl.resourcesneeded)) {
    do {
      prVar1 = prVar4->pNext;
      if ((prVar4->pPrev == (resource_s *)0x0) || (prVar2 = prVar1, prVar1 == (resource_s *)0x0)) {
        Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
        prVar2 = prVar4->pNext;
      }
      if ((prVar4 == prVar2) || (prVar3 = prVar4->pPrev, prVar4 == prVar3)) {
        Sys_Error("Attempt to free last entry in list.");
        prVar3 = prVar4->pPrev;
        prVar2 = prVar4->pNext;
      }
      prVar3->pNext = prVar2;
      prVar4->pNext->pPrev = prVar4->pPrev;
      prVar4->pPrev = (resource_s *)0x0;
      prVar4->pNext = (resource_s *)0x0;
      Mem_Free(prVar4);
    } while ((prVar1 != &cl.resourcesneeded) && (prVar4 = prVar1, prVar1 != (resource_s *)0x0));
  }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  cl.resourcesneeded.pPrev = &cl.resourcesneeded;
  cl.resourcesneeded.pNext = &cl.resourcesneeded;
  prVar4 = cl.resourcesonhand.pNext;
  if (cl.resourcesonhand.pNext != &cl.resourcesonhand) {
    do {
      if (prVar4 == (resource_s *)0x0) break;
      prVar1 = prVar4->pNext;
      if ((prVar4->pPrev == (resource_s *)0x0) || (prVar2 = prVar1, prVar1 == (resource_s *)0x0)) {
        Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
        prVar2 = prVar4->pNext;
      }
      if ((prVar4 == prVar2) || (prVar3 = prVar4->pPrev, prVar4 == prVar3)) {
        Sys_Error("Attempt to free last entry in list.");
        prVar3 = prVar4->pPrev;
        prVar2 = prVar4->pNext;
      }
      prVar3->pNext = prVar2;
      prVar4->pNext->pPrev = prVar4->pPrev;
      prVar4->pPrev = (resource_s *)0x0;
      prVar4->pNext = (resource_s *)0x0;
      Mem_Free(prVar4);
      prVar4 = prVar1;
    } while (prVar1 != &cl.resourcesonhand);
  }
  cl.resourcesonhand.pPrev = &cl.resourcesonhand;
  cl.resourcesonhand.pNext = &cl.resourcesonhand;
  return;
}


// CL_ClearState  @ 0019e1d0
void CL_ClearState(qboolean bQuiet)

{
  qboolean qVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  qVar1 = Host_IsServerActive();
  if (qVar1 == false) {
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
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x10;
    *(int *)((int)&(cl.free_efrags)->entnext + iVar2) = (int)&cl.free_efrags[1].leaf + iVar2;
    iVar2 = iVar3;
  } while (iVar3 != 0x27f0);
  cl.free_efrags[0x27f].entnext = (efrag_s *)0x0;
  return;
}


// CL_ClientDllQuery  @ 0019d6b0
int CL_ClientDllQuery(char *s)

{
  netadr_t to;
  qboolean qVar1;
  int iVar2;
  undefined4 local_810;
  char local_80c [2044];
  int local_10 [2];
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: uchar[2048] data@[???]
                       Unresolved local var: int valid@[???] */
  iVar2 = 0;
  qVar1 = Host_IsServerActive();
  if (qVar1 != false) {
    qVar1 = Host_IsSinglePlayerGame();
    if (qVar1 == false) {
      Q_memset(&local_810,0,0x800);
      local_10[0] = 0x7fc;
      iVar2 = ClientDLL_ConnectionlessPacket(&net_from,s,local_80c,local_10);
      if ((local_10[0] != 0) && (local_10[0] < 0x7fd)) {
        local_810 = 0xffffffff;
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
        NET_SendPacket(NS_CLIENT,local_10[0] + 4,&local_810,to);
      }
    }
  }
  return iVar2;
}


// CL_ClientQueueEvent  @ 00191560
void CL_ClientQueueEvent(int flags,int index,int client_index,float delay,event_args_t *pargs)

{
  event_state_t *peVar1;
  uint uVar2;
  event_state_t *peVar3;
  
                    /* Unresolved local var: event_info_t * ei@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  peVar3 = &cl.events;
  peVar1 = &cl.events;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
    if (peVar1->ei[0].index == 0) {
      if (peVar1 != (event_state_t *)0x0) goto LAB_001915d4;
      break;
    }
    peVar1 = (event_state_t *)(peVar1->ei + 1);
  } while (peVar1 != (event_state_t *)cl.downloadUrl);
  if ((flags & 2U) != 0) {
    do {
      if ((peVar3->ei[0].index == 0) || ((peVar3->ei[0].flags & 2) == 0)) {
        peVar1 = peVar3;
        if (peVar3 == (event_state_t *)0x0) {
          return;
        }
LAB_001915d4:
        peVar1->ei[0].packet_index = 0;
        peVar1->ei[0].index = (ushort)index;
        uVar2 = 0;
        do {
          *(undefined4 *)((int)peVar1->ei[0].args.origin + (uVar2 - 8)) =
               *(undefined4 *)((int)pargs->origin + (uVar2 - 8));
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x48);
        if (delay == 0.0) {
          peVar1->ei[0].fire_time = 0.0;
        }
        else {
          peVar1->ei[0].fire_time = delay + (float)cl.time;
        }
        peVar1->ei[0].flags = flags;
        return;
      }
      peVar3 = (event_state_t *)(peVar3->ei + 1);
    } while (peVar3 != (event_state_t *)cl.downloadUrl);
  }
  return;
}


// CL_Commentator_f  @ 0019c480
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


// CL_CompareTimestamps  @ 0018b8e0
qboolean CL_CompareTimestamps(float t1,float t2)

{
                    /* Unresolved local var: int iTime1@[???]
                       Unresolved local var: int iTime2@[???] */
  return (uint)(((int)(t1 * 1000.0) - (int)(t2 * 1000.0)) + 1U < 3);
}


// CL_ComputeClientInterpolationAmount  @ 001a1e50
void CL_ComputeClientInterpolationAmount(usercmd_t *cmd)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char *value;
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
  iVar4 = (-(uint)(cls.spectator == false) & 0xffffff9c) + 200;
  iVar3 = 0x32;
  if (0.0 < cl_updaterate.value) {
    iVar3 = 1;
    if (0 < (int)(1000.0 / cl_updaterate.value)) {
      iVar3 = (int)(1000.0 / cl_updaterate.value);
    }
  }
  iVar5 = (int)(ex_interp.value * 1000.0);
  if (iVar5 + 1 < iVar3) {
    Con_Printf("ex_interp forced up to %i msec\n",iVar3);
    iVar5 = iVar3;
  }
  else {
    if (iVar5 + -1 <= iVar4) goto LAB_001a1eee;
    Con_Printf("ex_interp forced down to %i msec\n",iVar4);
    iVar5 = iVar4;
  }
                    /* Unresolved local var: float interpolation_sec@[???] */
  value = va("%f",(double)((float)iVar5 / 1000.0));
  Cvar_Set("ex_interp",value);
LAB_001a1eee:
  if (iVar3 <= iVar5) {
    iVar3 = iVar5;
  }
  if (iVar4 < iVar3) {
    iVar3 = iVar4;
  }
                    /* Unresolved local var: int msec@[???]
                       Unresolved local var: float fgoal@[???] */
  if ((float)iVar3 / 1000.0 != g_flInterpolationAmount) {
                    /* Unresolved local var: float maxmove@[???]
                       Unresolved local var: float diff@[???] */
    fVar2 = (float)host_frametime * 0.05;
    fVar1 = (float)iVar3 / 1000.0 - g_flInterpolationAmount;
    if (0.0 < fVar1) {
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
    }
    else if (fVar2 < -fVar1) {
      fVar1 = -fVar2;
    }
    g_flInterpolationAmount = fVar1 + g_flInterpolationAmount;
  }
  iVar3 = 0;
  if (-1 < (int)(g_flInterpolationAmount * 1000.0)) {
    iVar3 = (int)(g_flInterpolationAmount * 1000.0);
  }
  iVar4 = 100;
  if (iVar3 < 0x65) {
    iVar4 = iVar3;
  }
  cmd->lerp_msec = (short)iVar4;
  return;
}


// CL_ComputePacketLoss  @ 001a1ce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ComputePacketLoss(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frm@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int lost@[???] */
  if (realtime < cls.packet_loss_recalc_time) {
    return;
  }
  uVar1 = (cls.netchan.incoming_sequence - CL_UPDATE_BACKUP) + 1;
  cls.packet_loss_recalc_time = realtime + 1.0;
  if ((int)uVar1 <= cls.netchan.incoming_sequence) {
    iVar2 = 0;
    do {
      while (iVar3 = iVar2 + 1, cl.frames[uVar1 & CL_UPDATE_MASK].receivedtime == -1.0) {
        uVar1 = uVar1 + 1;
        iVar2 = iVar3;
        if (cls.netchan.incoming_sequence < (int)uVar1) goto LAB_001a1d52;
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= cls.netchan.incoming_sequence);
LAB_001a1d52:
    iVar3 = cls.netchan.incoming_sequence - (cls.netchan.incoming_sequence - CL_UPDATE_BACKUP);
    if (iVar3 != 0) {
      cls.packet_loss = ((float)iVar2 * 100.0) / (float)iVar3;
      return;
    }
  }
  cls.packet_loss = 0.0;
  return;
}


// CL_ComputePlayerOrigin  @ 001950d0
void CL_ComputePlayerOrigin(cl_entity_t *ent)

{
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: vec3_t target_origin@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: float targettime@[???] */
  if ((ent->player != false) && (ent->index + -1 != cl.playernum)) {
    CL_PureOrigin(ent,(float)cl.time - ex_interp.value,&local_24,&local_18);
    ent->angles[0] = local_18;
    ent->angles[1] = local_14;
    ent->angles[2] = local_10;
    ent->origin[0] = local_24;
    ent->origin[1] = local_20;
    ent->origin[2] = local_1c;
  }
  return;
}


// CL_ConnectClient  @ 0019d3f0
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
    cls.demonum = -1;
    cls.signon = 0;
    cl.validsequence = 0;
    cl.delta_sequence = -1;
    cls.nextcmdtime = (float)realtime;
    cls.lastoutgoingcommand = -1;
    cls.connect_time = realtime;
  }
  return;
}


// CL_ConnectTest  @ 0019fa50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ConnectTest(void)

{
                    /* Unresolved local var: double disconnect_time@[???]
                       Unresolved local var: double connect_time@[???] */
  return;
}


// CL_Connect_f  @ 0019e600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Connect_f(void)

{
  CareerStateType CVar1;
  char *pcVar2;
  int iVar3;
  char local_110 [259];
  undefined1 local_d;
  
                    /* Unresolved local var: char * server@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int num@[???] */
  pcVar2 = Cmd_Args();
  if (pcVar2 != (char *)0x0) {
    Q_strncpy(local_110,pcVar2,0x104);
    CVar1 = g_careerState;
    local_d = 0;
    if (cls.demoplayback == false) {
                    /* Unresolved local var: CareerStateType careerState@[???] */
      CL_Disconnect();
    }
    else {
      CL_StopPlayback();
      CVar1 = g_careerState;
      CL_Disconnect();
    }
    if (CVar1 == CAREER_LOADING) {
      g_careerState = CAREER_LOADING;
    }
    StartLoadingProgressBar("Connecting",0xc);
    SetLoadingProgressBarStatusText("#GameUI_EstablishingConnection");
    iVar3 = Q_atoi(local_110);
    pcVar2 = Q_strstr(local_110,".");
    if (((pcVar2 == (char *)0x0) && (0 < iVar3)) && (iVar3 <= num_servers)) {
      pcVar2 = NET_AdrToString(cached_servers[iVar3 + -1].adr);
      Q_strncpy(local_110,pcVar2,0x104);
      local_d = 0;
    }
    Q_memset(msg_buckets,0,0x100);
    Q_memset(total_data,0,0x100);
    Q_strncpy(cls.servername,local_110,0x103);
    cls.passive = false;
    cls.spectator = false;
    cls.isVAC2Secure = false;
    cls.GameServerSteamID._0_4_ = 0;
    cls.state = ca_connecting;
    cls.connect_time._0_4_ = 0;
    cls.GameServerSteamID._4_4_ = 0;
    cls.connect_time._4_4_ = 0xc0f869f0;
    cls.connect_retry = 0;
    cls.build_num = 0;
    cls.servername[0x103] = '\0';
    Q_memset(&g_GameServerAddress,0,0x14);
    cls.challenge = 0;
    gfExtendedError = false;
    g_LastScreenUpdateTime = 0.0;
    iVar3 = Q_strnicmp(cls.servername,"local",5);
    if (iVar3 != 0) {
      NET_Config(true);
      return;
    }
  }
  return;
}


// CL_Connect_f  @ 0019e870
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Connect_f(void)

{
  int iVar1;
  
                    /* Unresolved local var: char * server@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int num@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("usage: connect <server>\n");
    return;
  }
  SetCStrikeFlags();
  if (((g_bIsCStrike != 0) || (g_bIsCZero != 0)) && (cmd_source != src_command)) {
    Con_Printf("Connect only works from the console.\n");
    return;
  }
  CL_Connect_f();
  return;
}


// CL_ConnectionlessPacket  @ 001a00a0
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
  char *pcVar6;
  qboolean qVar7;
  netadr_t *to;
  byte bVar8;
  uint challenge;
  server_cache_t *psVar9;
  byte bVar10;
  server_cache_t local_464;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * cmd@[???]
                       Unresolved local var: char * args@[???]
                       Unresolved local var: uchar c@[???] */
  bVar10 = 0;
  MSG_BeginReading();
  MSG_ReadLong();
  pcVar3 = MSG_ReadStringLine();
  Cmd_TokenizeString(pcVar3);
  s1 = (byte *)Cmd_Argv(0);
  bVar8 = 0;
  if (s1 != (byte *)0x0) {
    bVar8 = *s1;
  }
  iVar4 = Q_stricmp((char *)s1,"challenge");
  if (iVar4 == 0) {
    local_464.inuse = net_from.type;
    local_464.adr.type._0_1_ = net_from.ip[0];
    local_464.adr.type._1_1_ = net_from.ip[1];
    local_464.adr.type._2_1_ = net_from.ip[2];
    local_464.adr.type._3_1_ = net_from.ip[3];
    local_464.adr.ip[0] = net_from.ipx[0];
    local_464.adr.ip[1] = net_from.ipx[1];
    local_464.adr.ip[2] = net_from.ipx[2];
    local_464.adr.ip[3] = net_from.ipx[3];
    local_464.adr.ipx[0] = net_from.ipx[4];
    local_464.adr.ipx[1] = net_from.ipx[5];
    local_464.adr.ipx[2] = net_from.ipx[6];
    local_464.adr.ipx[3] = net_from.ipx[7];
    local_464.adr.ipx._4_4_ = net_from._16_4_;
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
    qVar7 = NET_CompareAdr(a,b);
    if (qVar7 == false) {
      a_00.ip[0] = (undefined1)local_464.adr.type;
      a_00.ip[1] = local_464.adr.type._1_1_;
      a_00.ip[2] = local_464.adr.type._2_1_;
      a_00.ip[3] = local_464.adr.type._3_1_;
      a_00.type = local_464.inuse;
      a_00.ipx[0] = local_464.adr.ip[0];
      a_00.ipx[1] = local_464.adr.ip[1];
      a_00.ipx[2] = local_464.adr.ip[2];
      a_00.ipx[3] = local_464.adr.ip[3];
      a_00.ipx[4] = local_464.adr.ipx[0];
      a_00.ipx[5] = local_464.adr.ipx[1];
      a_00.ipx[6] = local_464.adr.ipx[2];
      a_00.ipx[7] = local_464.adr.ipx[3];
      a_00._16_4_ = local_464.adr.ipx._4_4_;
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
      qVar7 = NET_CompareAdr(a_00,b_00);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (qVar7 == false) goto LAB_001a0230;
    }
                    /* Unresolved local var: char * type@[???]
                       Unresolved local var: char * value@[???]
                       Unresolved local var: uint val@[???] */
    iVar4 = Cmd_Argc();
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    if (iVar4 == 3) {
      pcVar3 = Cmd_Argv(1);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if ((pcVar3 != (char *)0x0) &&
         (uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID),
         *pcVar3 != '\0')) {
        iVar4 = Q_stricmp(pcVar3,"rcon");
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (iVar4 == 0) {
          pcVar3 = Cmd_Argv(2);
          to = (netadr_t *)Q_atoi(pcVar3);
          CL_SendRcon(to,challenge);
          uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        }
      }
    }
  }
  else if (bVar8 == 0x42) {
    local_464.inuse = net_from.type;
    local_464.adr.type._0_1_ = net_from.ip[0];
    local_464.adr.type._1_1_ = net_from.ip[1];
    local_464.adr.type._2_1_ = net_from.ip[2];
    local_464.adr.type._3_1_ = net_from.ip[3];
    local_464.adr.ip[0] = net_from.ipx[0];
    local_464.adr.ip[1] = net_from.ipx[1];
    local_464.adr.ip[2] = net_from.ipx[2];
    local_464.adr.ip[3] = net_from.ipx[3];
    local_464.adr.ipx[0] = net_from.ipx[4];
    local_464.adr.ipx[1] = net_from.ipx[5];
    local_464.adr.ipx[2] = net_from.ipx[6];
    local_464.adr.ipx[3] = net_from.ipx[7];
    local_464.adr.ipx._4_4_ = net_from._16_4_;
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
    qVar7 = NET_CompareAdr(a_01,b_01);
    if (qVar7 == false) {
      a_08.ip[0] = (undefined1)local_464.adr.type;
      a_08.ip[1] = local_464.adr.type._1_1_;
      a_08.ip[2] = local_464.adr.type._2_1_;
      a_08.ip[3] = local_464.adr.type._3_1_;
      a_08.type = local_464.inuse;
      a_08.ipx[0] = local_464.adr.ip[0];
      a_08.ipx[1] = local_464.adr.ip[1];
      a_08.ipx[2] = local_464.adr.ip[2];
      a_08.ipx[3] = local_464.adr.ip[3];
      a_08.ipx[4] = local_464.adr.ipx[0];
      a_08.ipx[5] = local_464.adr.ipx[1];
      a_08.ipx[6] = local_464.adr.ipx[2];
      a_08.ipx[7] = local_464.adr.ipx[3];
      a_08._16_4_ = local_464.adr.ipx._4_4_;
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
      qVar7 = NET_CompareAdr(a_08,b_08);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (qVar7 == false) goto LAB_001a0230;
    }
    CL_ConnectClient();
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
  }
  else if (bVar8 == 0x47) {
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
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
          qVar7 = Host_IsServerActive();
          uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
          if (qVar7 != false) {
            Host_ShutdownServer(false);
            uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
          }
          goto LAB_001a0230;
        }
        pcVar3 = Cmd_Argv(3);
        CL_Listen(pcVar3);
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      }
    }
  }
  else if (bVar8 == 0x41) {
    local_464.inuse = net_from.type;
    local_464.adr.type._0_1_ = net_from.ip[0];
    local_464.adr.type._1_1_ = net_from.ip[1];
    local_464.adr.type._2_1_ = net_from.ip[2];
    local_464.adr.type._3_1_ = net_from.ip[3];
    local_464.adr.ip[0] = net_from.ipx[0];
    local_464.adr.ip[1] = net_from.ipx[1];
    local_464.adr.ip[2] = net_from.ipx[2];
    local_464.adr.ip[3] = net_from.ipx[3];
    local_464.adr.ipx[0] = net_from.ipx[4];
    local_464.adr.ipx[1] = net_from.ipx[5];
    local_464.adr.ipx[2] = net_from.ipx[6];
    local_464.adr.ipx[3] = net_from.ipx[7];
    local_464.adr.ipx._4_4_ = net_from._16_4_;
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
    qVar7 = NET_CompareAdr(a_02,b_02);
    if (qVar7 == false) {
      a_04.ip[0] = (undefined1)local_464.adr.type;
      a_04.ip[1] = local_464.adr.type._1_1_;
      a_04.ip[2] = local_464.adr.type._2_1_;
      a_04.ip[3] = local_464.adr.type._3_1_;
      a_04.type = local_464.inuse;
      a_04.ipx[0] = local_464.adr.ip[0];
      a_04.ipx[1] = local_464.adr.ip[1];
      a_04.ipx[2] = local_464.adr.ip[2];
      a_04.ipx[3] = local_464.adr.ip[3];
      a_04.ipx[4] = local_464.adr.ipx[0];
      a_04.ipx[5] = local_464.adr.ipx[1];
      a_04.ipx[6] = local_464.adr.ipx[2];
      a_04.ipx[7] = local_464.adr.ipx[3];
      a_04._16_4_ = local_464.adr.ipx._4_4_;
      b_04.ip[0] = g_rconaddress.ip[0];
      b_04.ip[1] = g_rconaddress.ip[1];
      b_04.ip[2] = g_rconaddress.ip[2];
      b_04.ip[3] = g_rconaddress.ip[3];
      b_04.type = g_rconaddress.type;
      b_04.ipx[0] = g_rconaddress.ipx[0];
      b_04.ipx[1] = g_rconaddress.ipx[1];
      b_04.ipx[2] = g_rconaddress.ipx[2];
      b_04.ipx[3] = g_rconaddress.ipx[3];
      b_04.ipx[4] = g_rconaddress.ipx[4];
      b_04.ipx[5] = g_rconaddress.ipx[5];
      b_04.ipx[6] = g_rconaddress.ipx[6];
      b_04.ipx[7] = g_rconaddress.ipx[7];
      b_04.ipx[8] = g_rconaddress.ipx[8];
      b_04.ipx[9] = g_rconaddress.ipx[9];
      b_04.port = g_rconaddress.port;
      qVar7 = NET_CompareAdr(a_04,b_04);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (qVar7 == false) goto LAB_001a0230;
    }
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    if (cls.state == ca_connecting) {
      iVar4 = Cmd_Argc();
      if (iVar4 != 3) {
        iVar4 = Cmd_Argc();
        uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
        if (iVar4 != 5) goto LAB_001a0230;
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
            pcVar6 = Cmd_Argv(4);
            if (pcVar6 == (char *)0x0) {
              Con_Printf("STEAM keysize is bogus (2)\n");
              CL_Disconnect_f();
              uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
            }
            else {
              cls.isVAC2Secure = Q_atoi(pcVar6);
              cls.GameServerSteamID = strtoll(pcVar3,(char **)0x0,10);
              CL_SendConnectPacket();
              uVar1 = cls.GameServerSteamID;
            }
          }
        }
        goto LAB_001a0230;
      }
      CL_SendConnectPacket();
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    }
  }
  else if (bVar8 == 0x6c) {
    local_464.inuse = net_from.type;
    local_464.adr.type._0_1_ = net_from.ip[0];
    local_464.adr.type._1_1_ = net_from.ip[1];
    local_464.adr.type._2_1_ = net_from.ip[2];
    local_464.adr.type._3_1_ = net_from.ip[3];
    local_464.adr.ip[0] = net_from.ipx[0];
    local_464.adr.ip[1] = net_from.ipx[1];
    local_464.adr.ip[2] = net_from.ipx[2];
    local_464.adr.ip[3] = net_from.ipx[3];
    local_464.adr.ipx[0] = net_from.ipx[4];
    local_464.adr.ipx[1] = net_from.ipx[5];
    local_464.adr.ipx[2] = net_from.ipx[6];
    local_464.adr.ipx[3] = net_from.ipx[7];
    local_464.adr.ipx._4_4_ = net_from._16_4_;
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
    qVar7 = NET_CompareAdr(a_03,b_03);
    if (qVar7 == false) {
      a_05.ip[0] = (undefined1)local_464.adr.type;
      a_05.ip[1] = local_464.adr.type._1_1_;
      a_05.ip[2] = local_464.adr.type._2_1_;
      a_05.ip[3] = local_464.adr.type._3_1_;
      a_05.type = local_464.inuse;
      a_05.ipx[0] = local_464.adr.ip[0];
      a_05.ipx[1] = local_464.adr.ip[1];
      a_05.ipx[2] = local_464.adr.ip[2];
      a_05.ipx[3] = local_464.adr.ip[3];
      a_05.ipx[4] = local_464.adr.ipx[0];
      a_05.ipx[5] = local_464.adr.ipx[1];
      a_05.ipx[6] = local_464.adr.ipx[2];
      a_05.ipx[7] = local_464.adr.ipx[3];
      a_05._16_4_ = local_464.adr.ipx._4_4_;
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
      qVar7 = NET_CompareAdr(a_05,b_05);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (qVar7 == false) goto LAB_001a0230;
    }
    MSG_BeginReading();
    MSG_ReadLong();
    MSG_ReadByte();
    pcVar3 = MSG_ReadString();
    Con_Printf("%s\n",pcVar3);
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
  }
  else if (bVar8 == 0x38) {
    local_464.inuse = net_from.type;
    local_464.adr.type._0_1_ = net_from.ip[0];
    local_464.adr.type._1_1_ = net_from.ip[1];
    local_464.adr.type._2_1_ = net_from.ip[2];
    local_464.adr.type._3_1_ = net_from.ip[3];
    local_464.adr.ip[0] = net_from.ipx[0];
    local_464.adr.ip[1] = net_from.ipx[1];
    local_464.adr.ip[2] = net_from.ipx[2];
    local_464.adr.ip[3] = net_from.ipx[3];
    local_464.adr.ipx[0] = net_from.ipx[4];
    local_464.adr.ipx[1] = net_from.ipx[5];
    local_464.adr.ipx[2] = net_from.ipx[6];
    local_464.adr.ipx[3] = net_from.ipx[7];
    local_464.adr.ipx._4_4_ = net_from._16_4_;
    a_06.ip[0] = net_from.ip[0];
    a_06.ip[1] = net_from.ip[1];
    a_06.ip[2] = net_from.ip[2];
    a_06.ip[3] = net_from.ip[3];
    a_06.type = net_from.type;
    a_06.ipx[0] = net_from.ipx[0];
    a_06.ipx[1] = net_from.ipx[1];
    a_06.ipx[2] = net_from.ipx[2];
    a_06.ipx[3] = net_from.ipx[3];
    a_06.ipx[4] = net_from.ipx[4];
    a_06.ipx[5] = net_from.ipx[5];
    a_06.ipx[6] = net_from.ipx[6];
    a_06.ipx[7] = net_from.ipx[7];
    a_06.ipx[8] = net_from.ipx[8];
    a_06.ipx[9] = net_from.ipx[9];
    a_06.port = net_from.port;
    b_06.ip[0] = g_GameServerAddress.ip[0];
    b_06.ip[1] = g_GameServerAddress.ip[1];
    b_06.ip[2] = g_GameServerAddress.ip[2];
    b_06.ip[3] = g_GameServerAddress.ip[3];
    b_06.type = g_GameServerAddress.type;
    b_06.ipx[0] = g_GameServerAddress.ipx[0];
    b_06.ipx[1] = g_GameServerAddress.ipx[1];
    b_06.ipx[2] = g_GameServerAddress.ipx[2];
    b_06.ipx[3] = g_GameServerAddress.ipx[3];
    b_06.ipx[4] = g_GameServerAddress.ipx[4];
    b_06.ipx[5] = g_GameServerAddress.ipx[5];
    b_06.ipx[6] = g_GameServerAddress.ipx[6];
    b_06.ipx[7] = g_GameServerAddress.ipx[7];
    b_06.ipx[8] = g_GameServerAddress.ipx[8];
    b_06.ipx[9] = g_GameServerAddress.ipx[9];
    b_06.port = g_GameServerAddress.port;
    qVar7 = NET_CompareAdr(a_06,b_06);
    if (qVar7 == false) {
      a_10.ip[0] = (undefined1)local_464.adr.type;
      a_10.ip[1] = local_464.adr.type._1_1_;
      a_10.ip[2] = local_464.adr.type._2_1_;
      a_10.ip[3] = local_464.adr.type._3_1_;
      a_10.type = local_464.inuse;
      a_10.ipx[0] = local_464.adr.ip[0];
      a_10.ipx[1] = local_464.adr.ip[1];
      a_10.ipx[2] = local_464.adr.ip[2];
      a_10.ipx[3] = local_464.adr.ip[3];
      a_10.ipx[4] = local_464.adr.ipx[0];
      a_10.ipx[5] = local_464.adr.ipx[1];
      a_10.ipx[6] = local_464.adr.ipx[2];
      a_10.ipx[7] = local_464.adr.ipx[3];
      a_10._16_4_ = local_464.adr.ipx._4_4_;
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
      qVar7 = NET_CompareAdr(a_10,b_10);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (qVar7 == false) goto LAB_001a0230;
    }
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    if (cls.state == ca_connecting) {
      pcVar3 = pcVar3 + 1;
      iVar4 = Q_strlen("BADPASSWORD");
      iVar4 = Q_strncasecmp(pcVar3,"BADPASSWORD",iVar4);
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
  }
  else if (bVar8 == 0x4c) {
    local_464.inuse = net_from.type;
    local_464.adr.type._0_1_ = net_from.ip[0];
    local_464.adr.type._1_1_ = net_from.ip[1];
    local_464.adr.type._2_1_ = net_from.ip[2];
    local_464.adr.type._3_1_ = net_from.ip[3];
    local_464.adr.ip[0] = net_from.ipx[0];
    local_464.adr.ip[1] = net_from.ipx[1];
    local_464.adr.ip[2] = net_from.ipx[2];
    local_464.adr.ip[3] = net_from.ipx[3];
    local_464.adr.ipx[0] = net_from.ipx[4];
    local_464.adr.ipx[1] = net_from.ipx[5];
    local_464.adr.ipx[2] = net_from.ipx[6];
    local_464.adr.ipx[3] = net_from.ipx[7];
    local_464.adr.ipx._4_4_ = net_from._16_4_;
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
    qVar7 = NET_CompareAdr(a_07,b_07);
    if (qVar7 == false) {
      a_11.ip[0] = (undefined1)local_464.adr.type;
      a_11.ip[1] = local_464.adr.type._1_1_;
      a_11.ip[2] = local_464.adr.type._2_1_;
      a_11.ip[3] = local_464.adr.type._3_1_;
      a_11.type = local_464.inuse;
      a_11.ipx[0] = local_464.adr.ip[0];
      a_11.ipx[1] = local_464.adr.ip[1];
      a_11.ipx[2] = local_464.adr.ip[2];
      a_11.ipx[3] = local_464.adr.ip[3];
      a_11.ipx[4] = local_464.adr.ipx[0];
      a_11.ipx[5] = local_464.adr.ipx[1];
      a_11.ipx[6] = local_464.adr.ipx[2];
      a_11.ipx[7] = local_464.adr.ipx[3];
      a_11._16_4_ = local_464.adr.ipx._4_4_;
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
      qVar7 = NET_CompareAdr(a_11,b_11);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (qVar7 == false) goto LAB_001a0230;
    }
                    /* Unresolved local var: char[260] szCommand@[???] */
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    if (cls.state == ca_connecting) {
      pcVar3 = pcVar3 + 1;
      pcVar6 = strchr(pcVar3,10);
      if ((pcVar6 == (char *)0x0) && (pcVar6 = strchr(pcVar3,0x3b), pcVar6 == (char *)0x0)) {
        snprintf((char *)&local_464,0x104,"connect %s\n",pcVar3);
        Cbuf_AddText((char *)&local_464);
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
  }
  else if (bVar8 == 0x39) {
    local_464.inuse = net_from.type;
    local_464.adr.type._0_1_ = net_from.ip[0];
    local_464.adr.type._1_1_ = net_from.ip[1];
    local_464.adr.type._2_1_ = net_from.ip[2];
    local_464.adr.type._3_1_ = net_from.ip[3];
    local_464.adr.ip[0] = net_from.ipx[0];
    local_464.adr.ip[1] = net_from.ipx[1];
    local_464.adr.ip[2] = net_from.ipx[2];
    local_464.adr.ip[3] = net_from.ipx[3];
    local_464.adr.ipx[0] = net_from.ipx[4];
    local_464.adr.ipx[1] = net_from.ipx[5];
    local_464.adr.ipx[2] = net_from.ipx[6];
    local_464.adr.ipx[3] = net_from.ipx[7];
    local_464.adr.ipx._4_4_ = net_from._16_4_;
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
    qVar7 = NET_CompareAdr(a_09,b_09);
    if (qVar7 == false) {
      a_12.ip[0] = (undefined1)local_464.adr.type;
      a_12.ip[1] = local_464.adr.type._1_1_;
      a_12.ip[2] = local_464.adr.type._2_1_;
      a_12.ip[3] = local_464.adr.type._3_1_;
      a_12.type = local_464.inuse;
      a_12.ipx[0] = local_464.adr.ip[0];
      a_12.ipx[1] = local_464.adr.ip[1];
      a_12.ipx[2] = local_464.adr.ip[2];
      a_12.ipx[3] = local_464.adr.ip[3];
      a_12.ipx[4] = local_464.adr.ipx[0];
      a_12.ipx[5] = local_464.adr.ipx[1];
      a_12.ipx[6] = local_464.adr.ipx[2];
      a_12.ipx[7] = local_464.adr.ipx[3];
      a_12._16_4_ = local_464.adr.ipx._4_4_;
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
      qVar7 = NET_CompareAdr(a_12,b_12);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
      if (qVar7 == false) goto LAB_001a0230;
    }
    iVar4 = COM_CheckParm("-steam");
    if ((iVar4 != 0) ||
       (uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID),
       cls.state == ca_connecting)) {
      COM_ExplainDisconnection(true,pcVar3 + 1);
      CL_Disconnect();
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    }
  }
  else if (bVar8 == 0x49) {
                    /* Unresolved local var: server_cache_t server@[???]
                       Unresolved local var: int infoByte@[???] */
    psVar9 = &local_464;
    for (iVar4 = 0x112; iVar4 != 0; iVar4 = iVar4 + -1) {
      psVar9->inuse = 0;
      psVar9 = (server_cache_t *)((int)psVar9 + (uint)bVar10 * -8 + 4);
    }
    local_464.adr.type = net_from.type;
    local_464.adr.ip[0] = net_from.ip[0];
    local_464.adr.ip[1] = net_from.ip[1];
    local_464.adr.ip[2] = net_from.ip[2];
    local_464.adr.ip[3] = net_from.ip[3];
    local_464.adr.ipx[0] = net_from.ipx[0];
    local_464.adr.ipx[1] = net_from.ipx[1];
    local_464.adr.ipx[2] = net_from.ipx[2];
    local_464.adr.ipx[3] = net_from.ipx[3];
    local_464.adr.ipx[4] = net_from.ipx[4];
    local_464.adr.ipx[5] = net_from.ipx[5];
    local_464.adr.ipx[6] = net_from.ipx[6];
    local_464.adr.ipx[7] = net_from.ipx[7];
    local_464.adr.ipx[8] = net_from.ipx[8];
    local_464.adr.ipx[9] = net_from.ipx[9];
    local_464.adr.port = net_from.port;
    Q_strncpy_s(local_464.name,pcVar3 + 2,0x100);
    pcVar3 = MSG_ReadString();
    Q_strncpy_s(local_464.map,pcVar3,0x100);
    MSG_SkipString();
    pcVar3 = MSG_ReadString();
    Q_strncpy_s(local_464.desc,pcVar3,0x100);
    MSG_ReadShort();
    local_464.players = MSG_ReadByte();
    local_464.maxplayers = MSG_ReadByte();
    local_464.bots = MSG_ReadByte();
    iVar4 = MSG_ReadByte();
    local_464.type = (char)iVar4;
    iVar4 = MSG_ReadByte();
    local_464.os = (char)iVar4;
    iVar4 = MSG_ReadByte();
    local_464.is_private = (qboolean)(iVar4 != 0);
    iVar4 = MSG_ReadByte();
    local_464.is_vac = (qboolean)(iVar4 != 0);
    MSG_SkipString();
    uVar5 = MSG_ReadByte();
    if (msg_badread == false) {
      if ((uVar5 & 0x80) != 0) {
        iVar4 = MSG_ReadShort();
        uVar2 = Q_ntohs((ushort)iVar4);
        local_464.adr.port = uVar2;
      }
      if ((uVar5 & 0x10) != 0) {
        MSG_ReadLong();
        MSG_ReadLong();
      }
      if ((uVar5 & 0x40) != 0) {
        local_464.spec_adr.type = net_from.type;
        local_464.spec_adr.ip[0] = net_from.ip[0];
        local_464.spec_adr.ip[1] = net_from.ip[1];
        local_464.spec_adr.ip[2] = net_from.ip[2];
        local_464.spec_adr.ip[3] = net_from.ip[3];
        local_464.spec_adr.ipx[0] = net_from.ipx[0];
        local_464.spec_adr.ipx[1] = net_from.ipx[1];
        local_464.spec_adr.ipx[2] = net_from.ipx[2];
        local_464.spec_adr.ipx[3] = net_from.ipx[3];
        local_464.spec_adr.ipx[4] = net_from.ipx[4];
        local_464.spec_adr.ipx[5] = net_from.ipx[5];
        local_464.spec_adr.ipx[6] = net_from.ipx[6];
        local_464.spec_adr.ipx[7] = net_from.ipx[7];
        local_464.spec_adr.ipx[8] = net_from.ipx[8];
        local_464.spec_adr.ipx[9] = net_from.ipx[9];
        local_464.spec_adr.port = net_from.port;
        iVar4 = MSG_ReadShort();
        uVar2 = Q_ntohs((ushort)iVar4);
        local_464.spec_adr.port = uVar2;
        pcVar3 = MSG_ReadString();
        Q_strncpy_s(local_464.spec_name,pcVar3,0x100);
        local_464.has_spectator_address = 1;
      }
      if ((uVar5 & 0x20) != 0) {
        MSG_SkipString();
      }
      if ((uVar5 & 1) != 0) {
        MSG_ReadLong();
        MSG_ReadLong();
      }
    }
    CL_AddToServerCache(&local_464);
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
  }
  else {
    iVar4 = CL_ClientDllQuery(pcVar3);
    uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    if (iVar4 == 0) {
      Con_Printf("Unknown command:\n%c\n",(uint)bVar8);
      uVar1 = CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID);
    }
  }
LAB_001a0230:
  cls.GameServerSteamID._4_4_ = (undefined4)(uVar1 >> 0x20);
  cls.GameServerSteamID._0_4_ = (undefined4)uVar1;
  return;
}


// CL_CreateCustomizationList  @ 001ae3d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CreateCustomizationList(void)

{
  int iVar1;
  qboolean qVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: player_info_t * pPlayer@[???] */
  iVar1 = cl.playernum;
  cl.players[cl.playernum].customdata.pNext = (customization_s_conflict *)0x0;
  if (0 < cl.num_resources) {
    iVar3 = 0;
    do {
      while (qVar2 = COM_CreateCustomization
                               ((customization_t *)&cl.players[iVar1].customdata,
                                cl.resourcelist + iVar3,cl.playernum,0,(customization_t **)0x0,
                                (int *)0x0), qVar2 == false) {
        iVar4 = iVar3 + 1;
        Con_DPrintf("Problem with client customization %i, ignoring...",iVar3);
        iVar3 = iVar4;
        if (cl.num_resources <= iVar4) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < cl.num_resources);
  }
  return;
}


// CL_CreateResourceList  @ 0019de70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_CreateResourceList(void)

{
  resource_s *pResource;
  byte bVar1;
  int iVar2;
  FileHandle_t file;
  uint uVar3;
  char local_130 [260];
  uchar local_2c [28];
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int nSize@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: uchar[16] rgucMD5_hash@[???]
                       Unresolved local var: resource_t * pNewResource@[DW_OP_reg0(EAX)] */
  if (cls.state != ca_dedicated) {
    HPAK_FlushHostQueue();
    cl.num_resources = 0;
    snprintf(local_130,0x104,"tempdecal.wad");
    Q_memset(local_2c,0,0x10);
    file = FS_OpenPathID(local_130,"rb","GAMECONFIG");
    if (file != (FileHandle_t)0x0) {
      uVar3 = FS_Size(file);
      MD5_Hash_File(local_2c,local_130,0,0,(uint *)0x0);
      iVar2 = cl.num_resources;
      if (uVar3 == 0) {
        FS_Close(file);
      }
      else {
                    /* Unresolved local var: resource_t * r@[???] */
        pResource = cl.resourcelist + cl.num_resources;
        if (0x4ff < cl.num_resources) {
          Sys_Error("Too many resources on client.");
        }
        cl.num_resources = cl.num_resources + 1;
        cl.resourcelist[iVar2].type = t_decal;
        Q_strncpy(pResource->szFileName,local_130,0x3f);
        bVar1 = cl.resourcelist[iVar2].ucFlags;
        cl.resourcelist[iVar2].nDownloadSize = uVar3;
        cl.resourcelist[iVar2].szFileName[0x3f] = '\0';
        cl.resourcelist[iVar2].nIndex = 0;
        cl.resourcelist[iVar2].ucFlags = bVar1 | 4;
        Q_memcpy(cl.resourcelist[iVar2].rgucMD5_hash,local_2c,0x10);
        HPAK_AddLump(false,"custom.hpk",pResource,(void *)0x0,file);
        FS_Close(file);
      }
    }
  }
  return;
}


// CL_CreateResponse  @ 0019c860
void __regparm3 CL_CreateResponse(netadr_t *to,char *varname,char *value)

{
  netadr_t to_00;
  int iVar1;
  char local_40c [1032];
  
                    /* Unresolved local var: char[1024] response@[???] */
  if (varname == (char *)0x0) {
    snprintf(local_40c,0x400,"%c%c%c%c\"%s\"\n",0xff,0xff,0xff,0xff,to);
  }
  else {
    snprintf(local_40c,0x400,"%c%c%c%c\"%s\"=\"%s\"\n",0xff,0xff,0xff,0xff,to,varname);
  }
  iVar1 = Q_strlen(local_40c);
  to_00.ip[0] = net_from.ip[0];
  to_00.ip[1] = net_from.ip[1];
  to_00.ip[2] = net_from.ip[2];
  to_00.ip[3] = net_from.ip[3];
  to_00.type = net_from.type;
  to_00.ipx[0] = net_from.ipx[0];
  to_00.ipx[1] = net_from.ipx[1];
  to_00.ipx[2] = net_from.ipx[2];
  to_00.ipx[3] = net_from.ipx[3];
  to_00.ipx[4] = net_from.ipx[4];
  to_00.ipx[5] = net_from.ipx[5];
  to_00.ipx[6] = net_from.ipx[6];
  to_00.ipx[7] = net_from.ipx[7];
  to_00.ipx[8] = net_from.ipx[8];
  to_00.ipx[9] = net_from.ipx[9];
  to_00.port = net_from.port;
  NET_SendPacket(NS_CLIENT,iVar1 + 1,local_40c,to_00);
  return;
}


// CL_CreateResponse  @ 0019d950
void CL_CreateResponse(netadr_t *to,char *varname,char *value)

{
  int iVar1;
  char local_40c [1028];
  
                    /* Unresolved local var: char[1024] response@[???] */
  if (value == (char *)0x0) {
    snprintf(local_40c,0x400,"%c%c%c%c\"%s\"\n",0xff,0xff,0xff,0xff,varname);
  }
  else {
    snprintf(local_40c,0x400,"%c%c%c%c\"%s\"=\"%s\"\n",0xff,0xff,0xff,0xff,varname,value);
  }
  iVar1 = Q_strlen(local_40c);
  NET_SendPacket(NS_CLIENT,iVar1 + 1,local_40c,*to);
  return;
}


// CL_CreateVisibleEntity  @ 001bde50
int CL_CreateVisibleEntity(int type,cl_entity_s *ent)

{
  int iVar1;
  
                    /* Unresolved local var: int iret@[???] */
  (*g_engdstAddrs.CL_CreateVisibleEntity)(&type,(cl_entity_s_conflict3 **)&ent);
  if (type == 3) {
    iVar1 = 0;
    if (cl_numbeamentities < 0x40) {
      cl_beamentities[cl_numbeamentities] = ent;
      cl_numbeamentities = cl_numbeamentities + 1;
      return 1;
    }
  }
  else {
    iVar1 = 0;
    if (cl_numvisedicts < 0x200) {
      cl_visedicts[cl_numvisedicts] = ent;
      cl_numvisedicts = cl_numvisedicts + 1;
      iVar1 = 1;
    }
  }
  return iVar1;
}


// CL_DeallocateDynamicData  @ 001ae310
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DeallocateDynamicData(void)

{
  if (cl_entities != (cl_entity_t *)0x0) {
    Mem_Free(cl_entities);
    cl_entities = (cl_entity_t *)0x0;
  }
  R_DestroyObjects();
  return;
}


// CL_DecayLights  @ 001a1b70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DecayLights(void)

{
  float fVar1;
  dlight_t *pdVar2;
  byte bVar3;
  uint uVar4;
  longdouble lVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * dl@[???]
                       Unresolved local var: float time@[???] */
  if (cls.signon == 2) {
    lVar5 = (longdouble)cl.time;
    r_dlightchanged = 0;
    r_dlightactive = 0;
    lVar6 = (longdouble)cl.oldtime;
    pdVar2 = cl_dlights;
    bVar3 = 0;
    do {
      while (*(float *)(((lightstyle_t *)pdVar2)->map + 8) == 0.0) {
LAB_001a1bda:
        pdVar2 = (dlight_t *)(((lightstyle_t *)pdVar2)->map + 0x24);
        bVar3 = bVar3 + 1;
        if ((lightstyle_t *)pdVar2 == cl_lightstyle) goto LAB_001a1c2b;
      }
      if ((longdouble)*(float *)(((lightstyle_t *)pdVar2)->map + 0x10) < lVar5) {
        r_dlightchanged = r_dlightchanged | 1 << (bVar3 & 0x1f);
        ((lightstyle_t *)pdVar2)->map[8] = '\0';
        ((lightstyle_t *)pdVar2)->map[9] = '\0';
        ((lightstyle_t *)pdVar2)->map[10] = '\0';
        ((lightstyle_t *)pdVar2)->map[0xb] = '\0';
        goto LAB_001a1bda;
      }
      if (*(float *)(((lightstyle_t *)pdVar2)->map + 0x14) != 0.0) {
        uVar4 = 1 << (bVar3 & 0x1f);
        r_dlightchanged = r_dlightchanged | uVar4;
        fVar1 = *(float *)(((lightstyle_t *)pdVar2)->map + 8) -
                *(float *)(((lightstyle_t *)pdVar2)->map + 0x14) * (float)(lVar5 - lVar6);
        *(float *)(((lightstyle_t *)pdVar2)->map + 8) = fVar1;
        if (fVar1 < 0.0) {
          ((lightstyle_t *)pdVar2)->map[8] = '\0';
          ((lightstyle_t *)pdVar2)->map[9] = '\0';
          ((lightstyle_t *)pdVar2)->map[10] = '\0';
          ((lightstyle_t *)pdVar2)->map[0xb] = '\0';
        }
        else if (fVar1 != 0.0) goto LAB_001a1c20;
        goto LAB_001a1bda;
      }
      uVar4 = 1 << (bVar3 & 0x1f);
LAB_001a1c20:
      r_dlightactive = r_dlightactive | uVar4;
      pdVar2 = (dlight_t *)(((lightstyle_t *)pdVar2)->map + 0x24);
      bVar3 = bVar3 + 1;
    } while ((lightstyle_t *)pdVar2 != cl_lightstyle);
LAB_001a1c2b:
    pdVar2 = cl_elights;
    do {
      if (pdVar2->radius != 0.0) {
        if ((longdouble)pdVar2->die < lVar5) {
          pdVar2->radius = 0.0;
        }
        else {
          fVar1 = pdVar2->radius - pdVar2->decay * (float)(lVar5 - lVar6);
          pdVar2->radius = fVar1;
          if (fVar1 < 0.0) {
            pdVar2->radius = 0.0;
          }
        }
      }
      pdVar2 = pdVar2 + 1;
    } while (pdVar2 != (dlight_t *)&cl_playerindex);
  }
  return;
}


// CL_DemoAPIPlayback  @ 001957a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_DemoAPIPlayback(void)

{
  return (uint)(cls.demoplayback != false);
}


// CL_DemoAPIRecording  @ 00195790
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_DemoAPIRecording(void)

{
  return (uint)(cls.demorecording != false);
}


// CL_DemoAPITimedemo  @ 001957b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_DemoAPITimedemo(void)

{
  return (uint)(cls.timedemo != false);
}


// CL_DemoAnim  @ 00198d00
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


// CL_DemoCopyFileChunk  @ 00195d30
void CL_DemoCopyFileChunk(FILE *dst,FILE *src,int nSize)

{
  int iVar1;
  undefined1 local_41c [1036];
  
                    /* Unresolved local var: int copysize@[???]
                       Unresolved local var: char[1024] copybuf@[???] */
  iVar1 = nSize;
  if (0x400 < nSize) {
    do {
      iVar1 = iVar1 + -0x400;
      FS_Read(local_41c,0x400,1,src);
      FS_Write(local_41c,0x400,1,dst);
    } while (0x400 < iVar1);
    nSize = (nSize + -0x400) - (nSize - 0x401U & 0xfffffc00);
  }
  FS_Read(local_41c,nSize,1,src);
  FS_Write(local_41c,nSize,1,dst);
  FS_Flush(src);
  FS_Flush(dst);
  return;
}


// CL_DemoEvent  @ 001991d0
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


// CL_DemoFrameInfo  @ 001989a0
void CL_DemoFrameInfo(demo_info_t *rp,float time)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = 0x1f;
  do {
    iVar1 = iVar4 + -1;
    Q_memcpy(dem_frames + iVar4,dem_frames + iVar1,0x1b4);
    iVar4 = iVar1;
  } while (iVar1 != 0);
  uVar3 = 0;
  do {
    uVar5 = uVar3;
    uVar2 = *(undefined4 *)((int)(rp->rp).vieworg + uVar5);
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + (uVar5 - 4)) =
         *(undefined4 *)((int)(rp->rp).vieworg + (uVar5 - 4));
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar5) = uVar2;
    uVar3 = uVar5 + 8;
  } while (uVar5 + 8 < 0x1b0);
  *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar5 + 4) =
       *(undefined4 *)((int)(rp->rp).vieworg + uVar5 + 4);
  dem_frames[0].rp.cmd = &dem_frames[0].cmd;
  dem_frames[0].rp.movevars = &dem_frames[0].movevars;
  dem_frames[0].timestamp = time;
  return;
}


// CL_DemoInTime  @ 00195cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float CL_DemoInTime(void)

{
  return g_demotimescale * (float)realtime;
}


// CL_DemoOutTime  @ 00195cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float CL_DemoOutTime(void)

{
  return (float)realtime;
}


// CL_DemoParseAnim  @ 001993b0
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


// CL_DemoParseEvent  @ 001992b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DemoParseEvent(void)

{
  int32 flags;
  int32 index;
  longdouble lVar1;
  event_args_t local_5c;
  float local_14;
  int32 local_10;
  
                    /* Unresolved local var: int flags@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: float delay@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: int i@[???] */
  FS_Read(&local_10,4,1,cls.demofile);
  flags = (*LittleLong)(local_10);
  local_10 = flags;
  FS_Read(&local_10,4,1,cls.demofile);
  index = (*LittleLong)(local_10);
  local_10 = index;
  FS_Read(&local_14,4,1,cls.demofile);
  lVar1 = (longdouble)(*LittleFloat)(local_14);
  local_14 = (float)lVar1;
  FS_Read(&local_5c,0x48,1,cls.demofile);
  CL_QueueEvent(flags,index,(float)lVar1,&local_5c);
  return;
}


// CL_DemoParseSound  @ 00199000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DemoParseSound(void)

{
  int32 channel;
  uint uVar1;
  int32 flags;
  int32 pitch;
  longdouble lVar2;
  longdouble lVar3;
  char local_124 [256];
  float local_24;
  uint local_20 [4];
  
                    /* Unresolved local var: int channel@[???]
                       Unresolved local var: char[256] sample@[???]
                       Unresolved local var: float volume@[???]
                       Unresolved local var: float attenuation@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: int i@[???] */
  FS_Read(local_20,4,1,cls.demofile);
  channel = (*LittleLong)(local_20[0]);
  FS_Read(local_20,4,1,cls.demofile);
  uVar1 = (*LittleLong)(local_20[0]);
  local_20[0] = 0xff;
  if (uVar1 < 0x100) {
    local_20[0] = uVar1;
  }
  FS_Read(local_124,local_20[0],1,cls.demofile);
  local_124[local_20[0]] = '\0';
  FS_Read(&local_24,4,1,cls.demofile);
  lVar2 = (longdouble)(*LittleFloat)(local_24);
  FS_Read(&local_24,4,1,cls.demofile);
  lVar3 = (longdouble)(*LittleFloat)(local_24);
  FS_Read(local_20,4,1,cls.demofile);
  flags = (*LittleLong)(local_20[0]);
  FS_Read(local_20,4,1,cls.demofile);
  pitch = (*LittleLong)(local_20[0]);
  CL_DemoPlaySound(channel,local_124,(float)lVar2,(float)lVar3,flags,pitch);
  return;
}


// CL_DemoPlaySound  @ 00198ee0
void CL_DemoPlaySound(int channel,char *sample,float attenuation,float volume,int flags,int pitch)

{
  int iVar1;
  sfx_t *sfxin;
  sfx_t local_64;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???] */
  if ((flags & 0x10U) == 0) {
    sfxin = CL_LookupSound(sample);
    if (sfxin == (sfx_s *)0x0) {
      return;
    }
  }
  else {
    sfxin = &local_64;
    iVar1 = Q_atoi(sample + 1);
    snprintf(sfxin->name,0x40,"!%s",rgpszrawsentence[iVar1]);
  }
  if (channel == 6) {
    S_StartStaticSound(cl.playernum + 1,6,sfxin,cl.simorg,volume,attenuation,flags,pitch);
  }
  else {
    S_StartDynamicSound(cl.playernum + 1,channel,sfxin,cl.simorg,volume,attenuation,flags,pitch);
  }
  return;
}


// CL_DemoQueueSound  @ 00198da0
void CL_DemoQueueSound(int channel,char *sample,float volume,float attenuation,int flags,int pitch)

{
  _func_int32_int32 *p_Var1;
  FileHandle_t file;
  int iVar2;
  longdouble lVar3;
  undefined1 local_2d;
  float local_2c;
  int32 local_28;
  int32 local_24;
  int32 local_20;
  float local_1c;
  float local_18;
  int32 local_14;
  int32 local_10;
  
                    /* Unresolved local var: demo_sound1_s demcmd1@[???]
                       Unresolved local var: demo_sound2_s demcmd2@[???] */
  if (cls.demofile != (FileHandle_t)0x0) {
    local_2d = 8;
    lVar3 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_2c = (float)lVar3;
    local_28 = (*LittleLong)(host_framecount - cls.demostartframe);
    local_24 = (*LittleLong)(channel);
    p_Var1 = LittleLong;
    iVar2 = Q_strlen(sample);
    local_20 = (*p_Var1)(iVar2);
    FS_Write(&local_2d,0x11,1,cls.demofile);
    file = cls.demofile;
    iVar2 = Q_strlen(sample);
    FS_Write(sample,iVar2,1,file);
    lVar3 = (longdouble)(*LittleFloat)(volume);
    local_1c = (float)lVar3;
    lVar3 = (longdouble)(*LittleFloat)(attenuation);
    local_18 = (float)lVar3;
    local_14 = (*LittleLong)(flags);
    local_10 = (*LittleLong)(pitch);
    FS_Write(&local_1c,0x10,1,cls.demofile);
  }
  return;
}


// CL_DemoReadCmdInfo  @ 00198a40
void CL_DemoReadCmdInfo(float time)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_1c0 [59];
  undefined4 auStack_d4 [13];
  vec_t avStack_a0 [34];
  vec_t local_18;
  vec_t local_14;
  int local_10;
  
                    /* Unresolved local var: demo_info_t rp@[???] */
  FS_Read(local_1c0,0x1b4,1,cls.demofile);
  uVar3 = 0;
  do {
    *(undefined4 *)((int)g_rp.cmd.viewangles + (uVar3 - 4)) =
         *(undefined4 *)((int)auStack_d4 + uVar3);
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x34);
  uVar3 = 0;
  do {
    uVar5 = uVar3;
    uVar2 = *(undefined4 *)((int)avStack_a0 + uVar5 + 4);
    *(undefined4 *)(g_rp.movevars.skyName + (uVar5 - 0x44)) =
         *(undefined4 *)((int)avStack_a0 + uVar5);
    *(undefined4 *)(g_rp.movevars.skyName + (uVar5 - 0x40)) = uVar2;
    uVar3 = uVar5 + 8;
  } while (uVar5 + 8 < 0x80);
  *(undefined4 *)(g_rp.movevars.skyName + (uVar5 - 0x3c)) =
       *(undefined4 *)((int)avStack_a0 + uVar5 + 8);
  g_rp.view[0] = avStack_a0[0x21];
  g_rp.view[1] = local_18;
  g_rp.view[2] = local_14;
  g_rp.viewmodel = local_10;
  iVar4 = 0x1f;
  do {
                    /* Unresolved local var: int i@[???] */
    iVar1 = iVar4 + -1;
    Q_memcpy(dem_frames + iVar4,dem_frames + iVar1,0x1b4);
    iVar4 = iVar1;
  } while (iVar1 != 0);
  uVar3 = 0;
  do {
    uVar5 = uVar3;
    uVar2 = *(undefined4 *)((int)local_1c0 + uVar5 + 4);
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + (uVar5 - 4)) =
         *(undefined4 *)((int)local_1c0 + uVar5);
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar5) = uVar2;
    uVar3 = uVar5 + 8;
  } while (uVar3 < 0x1b0);
  dem_frames[0].rp.movevars = &dem_frames[0].movevars;
  dem_frames[0].rp.cmd = &dem_frames[0].cmd;
  *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar5 + 4) =
       *(undefined4 *)((int)local_1c0 + uVar3);
  dem_frames[0].timestamp = time;
  return;
}


// CL_DemoSectionStart  @ 00198580
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_DemoSectionStart(void)

{
  uint uVar1;
  char local_8c [136];
  
                    /* Unresolved local var: char[128] szCommand@[???] */
  if (pCurrentEntry != (demoentry_t *)0x0) {
    uVar1 = pCurrentEntry->nFlags;
    if ((uVar1 & 4) != 0) {
      snprintf(local_8c,0x80,"cd stop\ncd play %i\n",pCurrentEntry->nCDTrack);
      Cbuf_AddText(local_8c);
      uVar1 = pCurrentEntry->nFlags;
    }
    if ((uVar1 & 0x10) != 0) {
      sf_demo.duration = 0x800;
      sf_demo.holdTime = 0;
      sf_demo.r = '\0';
      sf_demo.g = '\0';
      sf_demo.b = '\0';
      sf_demo.a = 0xff;
      sf_demo.fadeFlags = 0;
      V_ScreenFade((char *)0x0,0,&sf_demo);
      uVar1 = pCurrentEntry->nFlags;
    }
    if ((uVar1 & 8) != 0) {
      sf_demo.duration = 0x2000;
      sf_demo.holdTime = 0;
      sf_demo.fadeFlags = 0;
      sf_demo.r = '\0';
      sf_demo.g = '\0';
      sf_demo.b = '\0';
      sf_demo.a = 0xff;
      V_ScreenFade((char *)0x0,0,&sf_demo);
    }
  }
  return;
}


// CL_DemoWriteCmdInfo  @ 00198970
void CL_DemoWriteCmdInfo(FileHandle_t fp)

{
  FS_Write(&g_rp,0x1b4,1,fp);
  return;
}


// CL_DemoWriteSequenceInfo  @ 00198770
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


// CL_DescribeEvent  @ 00191350
void CL_DescribeEvent(int slot,char *eventname)

{
                    /* Unresolved local var: int idx@[???] */
  if ((cl_showevents.value != 0.0) && (eventname != (char *)0x0)) {
    Con_NPrintf(slot & 0x1f,"%i %f %s",slot,cl.time,eventname);
  }
  return;
}


// CL_Disconnect  @ 0019e2c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Disconnect(void)

{
  netadr_t addr;
  netadr_t addr_00;
  uchar unIPServer [4];
  qboolean qVar1;
  int iVar2;
  int iVar3;
  byte local_20;
  char local_1f [27];
  
                    /* Unresolved local var: uchar[20] final@[???]
                       Unresolved local var: uint unIP@[???] */
  cls.connect_time._0_4_ = 0;
  cls.connect_time._4_4_ = 0xc0f869f0;
  cls.connect_retry = 0;
  g_careerState = CAREER_NONE;
  SetCareerAudioState(0);
  SPR_Shutdown_NoModelFree();
  S_StopAllSounds(true);
  if (cls.demoplayback == false) {
    if ((((cls.state == ca_connected) || (cls.state == ca_active)) ||
        (cls.state == ca_uninitialized)) || (cls.state == ca_connecting)) {
      if (cls.demorecording != false) {
        CL_Stop_f();
      }
      FS_LogLevelLoadStarted("ExitGame");
      if (cls.passive == false) {
        if (cls.netchan.remote_address.type != NA_UNUSED) {
          local_20 = '\x03';
          Q_strcpy(local_1f,"dropclient\n");
          Netchan_Transmit(&cls.netchan,0xd,&local_20);
          Netchan_Transmit(&cls.netchan,0xd,&local_20);
          Netchan_Transmit(&cls.netchan,0xd,&local_20);
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
      unIPServer = net_local_adr.ip;
      if (g_GameServerAddress.type != NA_LOOPBACK) {
        unIPServer = g_GameServerAddress.ip;
      }
      Steam_GSTerminateGameConnection((uint32)unIPServer,g_GameServerAddress.port);
      Q_memset(&g_GameServerAddress,0,0x14);
      qVar1 = Host_IsServerActive();
      if (qVar1 != false) {
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
  qVar1 = Host_IsServerActive();
  if (qVar1 == false) {
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
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x10;
    *(int *)((int)&(cl.free_efrags)->entnext + iVar2) = (int)&cl.free_efrags[1].leaf + iVar2;
    iVar2 = iVar3;
  } while (iVar3 != 0x27f0);
  cl.free_efrags[0x27f].entnext = (efrag_s *)0x0;
  Netchan_Clear(&cls.netchan);
  CL_DeallocateDynamicData();
  scr_downloading.value = -1.0;
  sys_timescale.value = 1.0;
  g_LastScreenUpdateTime = 0.0;
  VGuiWrap2_NotifyOfServerDisconnect();
  StopLoadingProgressBar();
  return;
}


// CL_Disconnect_f  @ 0019e8e0
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


// CL_DriftInterpolationAmount  @ 001a1db0
int CL_DriftInterpolationAmount(int goal)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int msec@[???]
                       Unresolved local var: float fgoal@[???] */
  if ((float)goal / 1000.0 != g_flInterpolationAmount) {
                    /* Unresolved local var: float maxmove@[???]
                       Unresolved local var: float diff@[???] */
    fVar2 = (float)host_frametime * 0.05;
    fVar1 = (float)goal / 1000.0 - g_flInterpolationAmount;
    if (0.0 < fVar1) {
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
    }
    else if (fVar2 < -fVar1) {
      fVar1 = -fVar2;
    }
    g_flInterpolationAmount = fVar1 + g_flInterpolationAmount;
  }
  iVar4 = 0;
  if (-1 < (int)(g_flInterpolationAmount * 1000.0)) {
    iVar4 = (int)(g_flInterpolationAmount * 1000.0);
  }
  iVar3 = 100;
  if (iVar4 < 0x65) {
    iVar3 = iVar4;
  }
  return iVar3;
}


// CL_DumpMessageLoad_f  @ 001af8b0
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
  iVar2 = 0;
  Con_Printf("-------- Message Load ---------\n");
  ppcVar3 = &cl_parsefuncs[0].pszname;
  do {
    if (msg_buckets[iVar2] != 0) {
      pcVar1 = "bogus #";
      if (iVar2 < 0x3c) {
        pcVar1 = *ppcVar3;
      }
      Con_Printf("%i:%s: %i msgs:%.2fK\n",iVar2,pcVar1,msg_buckets[iVar2],
                 (double)((float)total_data[iVar2] * 0.0009765625));
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


// CL_EmitEntities  @ 0018f290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_EmitEntities(void)

{
  cl_entity_t *pcVar1;
  int iVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  int iVar5;
  mleaf_t *leaf;
  byte *ppvs;
  uint uVar6;
  bool bVar7;
  float fVar8;
  
                    /* Unresolved local var: mleaf_t * pleaf@[???]
                       Unresolved local var: uchar * ppvs@[???] */
  cl_numvisedicts = 0;
  cl_numbeamentities = 0;
  if (((cls.state == ca_active) && (cl.validsequence != 0)) &&
     (cl.frames[cl.parsecountmod].invalid == false)) {
    uVar6 = cls.netchan.outgoing_sequence - 1U & CL_UPDATE_MASK;
    fVar8 = CL_LerpPoint();
    bVar7 = cls.spectator != false;
    cl.commands[uVar6].frame_lerp = fVar8;
    if (bVar7) {
      leaf = Mod_PointInLeaf(cl.simorg,cl.worldmodel);
      ppvs = Mod_LeafPVS(leaf,cl.worldmodel);
      PVSMark(cl.worldmodel,ppvs);
    }
    CL_LinkPlayers();
    CL_LinkPacketEntities();
    iVar4 = cl_numvisedicts;
    pcVar3 = cl_entities;
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: int i@[???] */
    if (0 < cl_numvisedicts) {
      iVar5 = 0;
      do {
        pcVar1 = cl_visedicts[iVar5];
        iVar2 = (pcVar1->curstate).aiment;
        if ((iVar2 != 0) && ((pcVar1->curstate).movetype == 0xc)) {
          pcVar1->origin[0] = pcVar3[iVar2].origin[0];
          pcVar1->origin[1] = pcVar3[iVar2].origin[1];
          pcVar1->origin[2] = pcVar3[iVar2].origin[2];
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
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


// CL_EndMovie_f  @ 0019c1f0
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


// CL_EntityNum  @ 001abd00
cl_entity_t * CL_EntityNum(int num)

{
  if (cl.num_entities <= num) {
    if (num < cl.max_edicts) goto LAB_001abd20;
    Host_Error("CL_EntityNum: %i is an invalid number, cl.max_edicts is %i",num,cl.max_edicts);
    for (; cl.num_entities <= num; cl.num_entities = cl.num_entities + 1) {
LAB_001abd20:
      cl_entities[num].index = num;
    }
  }
  cl_entities[num].index = num;
  return cl_entities + num;
}


// CL_EntityTeleported  @ 0018b860
qboolean CL_EntityTeleported(cl_entity_t_conflict2 *ent)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t distance@[???] */
  qVar1 = true;
  if (((ent->curstate).origin[0] - (ent->prevstate).origin[0] <= 128.0) &&
     ((ent->curstate).origin[1] - (ent->prevstate).origin[1] <= 128.0)) {
    qVar1 = (qboolean)(128.0 < (ent->curstate).origin[2] - (ent->prevstate).origin[2]);
  }
  return qVar1;
}


// CL_EstimateNeededResources  @ 001ad320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_EstimateNeededResources(void)

{
  int iVar1;
  uint uVar2;
  char *pFileName;
  byte bVar3;
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
      iVar1 = 0;
      switch(pFileName_00->type) {
      case t_sound:
        iVar1 = 0;
        if (pFileName_00->szFileName[0] != '*') {
          pFileName = va("sound/%s",pFileName_00);
          uVar2 = FS_FileSize(pFileName);
          goto joined_r0x001ad37a;
        }
        break;
      case t_skin:
      case t_generic:
      case t_eventscript:
switchD_001ad34b_caseD_1:
        uVar2 = FS_FileSize(pFileName_00->szFileName);
joined_r0x001ad37a:
        if ((uVar2 == 0) || (uVar2 == 0xffffffff)) {
          bVar3 = pFileName_00->ucFlags;
          goto LAB_001ad3ab;
        }
LAB_001ad37f:
        iVar1 = 0;
        break;
      case t_model:
        iVar1 = 0;
        if ((pFileName_00->szFileName[0] != '*') && (pFileName_00->ucFlags != '\0'))
        goto switchD_001ad34b_caseD_1;
        break;
      case t_decal:
        bVar3 = pFileName_00->ucFlags;
        if ((bVar3 & 4) == 0) goto LAB_001ad37f;
LAB_001ad3ab:
        iVar1 = pFileName_00->nDownloadSize;
        pFileName_00->ucFlags = bVar3 | 2;
      }
      pFileName_00 = pFileName_00->pNext;
      iVar4 = iVar4 + iVar1;
    } while (pFileName_00 != &cl.resourcesneeded);
  }
  return iVar4;
}


// CL_Exec  @ 00192100
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Exec(void)

{
  int iVar1;
  uint uVar2;
  char local_140c [4096];
  char local_40c [1032];
  
                    /* Unresolved local var: char[1024] pchExecBuf@[???]
                       Unresolved local var: int nExecType@[???] */
  iVar1 = MSG_ReadByte();
  if (iVar1 == 0) {
                    /* Unresolved local var: char[4096] pchMapName@[???] */
    if (g_bIsTFC != 0) {
      Cbuf_AddText("exec mapdefault.cfg\n");
      uVar2 = Q_strlen(cl.levelname);
      if (uVar2 < 0xfff) {
        COM_FileBase(cl.levelname,local_140c);
        if (local_140c[0] != '\0') {
          snprintf(local_40c,0x400,"exec %s.cfg\n",local_140c);
          Cbuf_AddText(local_40c);
        }
      }
    }
  }
  else if (iVar1 == 1) {
                    /* Unresolved local var: int nClassNum@[???] */
    uVar2 = MSG_ReadByte();
    if (((-1 < (int)uVar2) && (g_bIsTFC != 0)) && (uVar2 < 0xc)) {
      Cbuf_AddText(CL_Exec::lexical_block_1::sClassCfgs[uVar2]);
    }
  }
  return;
}


// CL_FindEmptyEvent  @ 00191500
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

event_info_t * CL_FindEmptyEvent(void)

{
  event_info_t *peVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  peVar1 = cl.events.ei;
  do {
    if (((event_info_s *)&peVar1->index)->index == 0) {
      return peVar1;
    }
    peVar1 = peVar1 + 1;
  } while (peVar1 != (event_info_t *)cl.downloadUrl);
  return (event_info_t *)0x0;
}


// CL_FindEventHook  @ 00191d90
event_hook_s * CL_FindEventHook(char *name)

{
  int iVar1;
  event_hook_t *peVar2;
  
                    /* Unresolved local var: event_hook_t * hook@[???] */
  peVar2 = g_pEventHooks;
  if (name == (char *)0x0) {
    peVar2 = (event_hook_t *)0x0;
  }
  else {
    while ((peVar2 != (event_hook_t *)0x0 &&
           ((peVar2->name == (char *)0x0 || (iVar1 = Q_stricmp(name,peVar2->name), iVar1 != 0))))) {
      peVar2 = peVar2->next;
    }
  }
  return peVar2;
}


// CL_FindInterpolationUpdates  @ 00194c20
qboolean CL_FindInterpolationUpdates
                   (cl_entity_t *ent,float targettime,position_history_t **ph0,
                   position_history_t **ph1,int *ph0Index)

{
  float fVar1;
  uint uVar2;
  qboolean qVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: int i0@[???]
                       Unresolved local var: int i1@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float at@[???]
                       Unresolved local var: int imod@[???] */
  uVar2 = ent->current_position;
  uVar4 = uVar2 & 0x3f;
  iVar6 = 1;
  if (targettime <= ent->ph[uVar4].animtime) {
    do {
      uVar5 = uVar2 - iVar6 & 0x3f;
      fVar1 = ent->ph[uVar5].animtime;
      if (fVar1 == 0.0) break;
      if (fVar1 < targettime) {
        qVar3 = false;
        uVar4 = (uVar2 - iVar6) + 1 & 0x3f;
        goto LAB_00194cb7;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x3f);
  }
  qVar3 = true;
  uVar5 = uVar2 - 1 & 0x3f;
LAB_00194cb7:
  if (ph0 != (position_history_t **)0x0) {
    *ph0 = ent->ph + uVar4;
  }
  if (ph1 != (position_history_t **)0x0) {
    *ph1 = ent->ph + uVar5;
  }
  if (ph0Index != (int *)0x0) {
    *ph0Index = uVar4;
  }
  return qVar3;
}


// CL_FindUnreliableEvent  @ 00191530
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


// CL_FinishGameGauge  @ 0019a690
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
  fVar3 = (float)realtime - cls.td_starttime;
  if (fVar3 == 0.0) {
    fVar3 = 1.0;
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
      Con_Printf("%d Second %d\n",*(undefined4 *)(iVar4 * 4 + 0xbe74dc),iVar4,pcVar5);
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
      FS_FPrintf(file,"%d Second %d\n",*(undefined4 *)(iVar4 * 4 + 0xbe74dc),iVar4,pcVar5);
    } while (iVar4 < g_iSecond);
  }
  FS_Close(file);
  iVar4 = COM_CheckParm("-noquit");
  if (iVar4 == 0) {
    Cbuf_AddText("quit\n");
  }
  return;
}


// CL_FinishTimeDemo  @ 0019a400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_FinishTimeDemo(void)

{
  float fVar1;
  int iVar2;
  
                    /* Unresolved local var: int frames@[???]
                       Unresolved local var: float time@[???] */
  cls.timedemo = false;
  iVar2 = (host_framecount - cls.td_startframe) + -1;
  fVar1 = 1.0;
  if ((float)realtime - cls.td_starttime != 0.0) {
    fVar1 = (float)realtime - cls.td_starttime;
  }
  Con_Printf("%i frames %5.3f seconds %5.3f fps\n",iVar2,(double)fVar1,
             (double)((float)iVar2 / fVar1));
  return;
}


// CL_FireEvents  @ 001913a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_FireEvents(void)

{
  float fVar1;
  event_hook_s **ppeVar2;
  uint uVar3;
  int iVar4;
  event_hook_s *peVar5;
  uint uVar6;
  event_state_t *peVar7;
  char *pcVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???]
                       Unresolved local var: event_hook_t * hook@[DW_OP_reg3(EBX)] */
  uVar6 = 0;
  peVar7 = &cl.events;
  do {
    uVar3 = (uint)peVar7->ei[0].index;
    if ((uVar3 != 0) &&
       ((fVar1 = peVar7->ei[0].fire_time, fVar1 == 0.0 || (fVar1 <= (float)cl.time)))) {
                    /* Unresolved local var: event_hook_t * hook@[???] */
      pcVar8 = cl.event_precache[uVar3].filename;
      if ((pcVar8 != (char *)0x0) && (peVar5 = g_pEventHooks, g_pEventHooks != (event_hook_t *)0x0))
      {
        do {
          if ((peVar5->name != (char *)0x0) && (iVar4 = Q_stricmp(pcVar8,peVar5->name), iVar4 == 0))
          {
                    /* Unresolved local var: int idx@[???] */
            pcVar8 = cl.event_precache[peVar7->ei[0].index].filename;
            if ((cl_showevents.value != 0.0) && (pcVar8 != (char *)0x0)) {
              Con_NPrintf(uVar6 & 0x1f,"%i %f %s",uVar6,cl.time,pcVar8);
            }
            (*peVar5->pfnEvent)(&peVar7->ei[0].args);
            goto LAB_00191446;
          }
          ppeVar2 = &peVar5->next;
          peVar5 = *ppeVar2;
        } while (*ppeVar2 != (event_hook_s *)0x0);
        uVar3 = (uint)peVar7->ei[0].index;
        pcVar8 = cl.event_precache[uVar3].filename;
      }
      Con_DPrintf("CL_FireEvents:  Unknown event %i:%s\n",uVar3,pcVar8);
LAB_00191446:
      peVar7->ei[0].index = 0;
      Q_memset(&peVar7->ei[0].args,0,0x48);
      peVar7->ei[0].fire_time = 0.0;
      peVar7->ei[0].flags = 0;
    }
    uVar6 = uVar6 + 1;
    peVar7 = (event_state_t *)(peVar7->ei + 1);
    if (uVar6 == 0x40) {
      return;
    }
  } while( true );
}


// CL_FixPointers  @ 00195d10
void CL_FixPointers(demo_info_t *info)

{
  (info->rp).cmd = &info->cmd;
  (info->rp).movevars = &info->movevars;
  return;
}


// CL_FlushEntityPacket  @ 0018bd40
void CL_FlushEntityPacket(qboolean needbitencodingframe)

{
  delta_t **ppdVar1;
  delta_t **ppdVar2;
  delta_t **ppdVar3;
  uint32 uVar4;
  delta_t *pFields;
  uchar local_308 [340];
  uchar local_1b4 [340];
  con_nprint_s local_60;
  qboolean local_4c [4];
  qboolean local_3c [4];
  qboolean local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
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
  local_4c[0] = false;
  local_28 = 0;
  local_3c[0] = false;
  local_2c = false;
  local_24 = 0;
  ppdVar1 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar2 = DELTA_LookupRegistration("entity_state_t");
  ppdVar3 = DELTA_LookupRegistration("custom_entity_state_t");
  local_60.time_to_live = 1.0;
  local_60.color[0] = 1.0;
  local_60.color[1] = 0.2;
  local_60.color[2] = 0.0;
  local_60.index = 0;
  Con_NXPrintf(&local_60,"WARNING:  CL_FlushEntityPacket");
  Q_memset(local_308,0,0x154);
  cl.validsequence = 0;
  cl.frames[cl.parsecountmod].invalid = true;
  if (needbitencodingframe != false) {
    MSG_StartBitReading(&net_message);
  }
LAB_0018be50:
  uVar4 = MSG_PeekBits(0x10);
  if (uVar4 != 0) goto LAB_0018beee;
LAB_0018be64:
  uVar4 = MSG_ReadBits(0x10);
  do {
    if (msg_badread != false) {
      Host_EndGame("msg_badread in packetentities\n");
LAB_0018bf46:
      if (needbitencodingframe != false) {
        MSG_EndBitReading(&net_message);
      }
      return;
    }
    if (uVar4 == 0) goto LAB_0018bf46;
    if (local_4c[0] != false) goto LAB_0018be50;
    if (local_3c[0] == false) {
      if (((int)uVar4 < 1) || (cl.maxclients < (int)uVar4)) {
        pFields = *ppdVar2;
      }
      else {
        pFields = *ppdVar1;
      }
    }
    else {
      pFields = *ppdVar3;
    }
    DELTA_ParseDelta(local_308,local_1b4,pFields,0x154);
    uVar4 = MSG_PeekBits(0x10);
    if (uVar4 == 0) goto LAB_0018be64;
LAB_0018beee:
    uVar4 = CL_ParseDeltaHeader(local_4c,local_3c,&local_24,&local_2c,&local_28,false,local_20);
  } while( true );
}


// CL_FlushEventSystem  @ 00191ed0
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


// CL_FullServerinfo_f  @ 0019c230
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


// CL_FxBlend  @ 001aabc0
int CL_FxBlend(cl_entity_t *ent)

{
  float fVar1;
  double dVar2;
  int iVar3;
  int32 iVar4;
  int iVar5;
  double dVar6;
  double local_1c;
  
                    /* Unresolved local var: int blend@[???]
                       Unresolved local var: float offset@[???] */
  dVar6 = cl.time;
  fVar1 = (float)(ent->curstate).number * 363.0;
  iVar5 = (ent->curstate).renderfx;
  dVar2 = (double)fVar1;
  switch(iVar5) {
  case 0:
  case 0xe:
  default:
switchD_001aac30_default:
    iVar5 = (ent->curstate).renderamt;
    break;
  case 1:
    dVar6 = cl.time + cl.time;
    goto LAB_001aad48;
  case 2:
    dVar6 = cl.time * 8.0;
LAB_001aad48:
    dVar6 = sin(dVar6 + dVar2);
    iVar5 = (int)(dVar6 * 16.0 + (double)(ent->curstate).renderamt);
    break;
  case 3:
    dVar6 = cl.time + cl.time;
    goto LAB_001aad98;
  case 4:
    dVar6 = cl.time * 8.0;
LAB_001aad98:
    dVar6 = sin(dVar6 + dVar2);
    iVar5 = (int)(dVar6 * 64.0 + (double)(ent->curstate).renderamt);
    break;
  case 5:
    iVar5 = (ent->curstate).renderamt;
    if (iVar5 < 1) {
LAB_001aaf18:
      (ent->curstate).renderamt = 0;
      iVar5 = 0;
      goto LAB_001aac60;
    }
    iVar5 = iVar5 + -1;
    (ent->curstate).renderamt = iVar5;
    break;
  case 6:
    iVar5 = (ent->curstate).renderamt;
    if (iVar5 < 4) goto LAB_001aaf18;
    iVar5 = iVar5 + -4;
    (ent->curstate).renderamt = iVar5;
    break;
  case 7:
    iVar5 = (ent->curstate).renderamt;
    if (iVar5 < 0xff) {
      iVar5 = iVar5 + 1;
      (ent->curstate).renderamt = iVar5;
      goto LAB_001aac60;
    }
    goto LAB_001aaef0;
  case 8:
    iVar5 = (ent->curstate).renderamt;
    if (iVar5 < 0xfc) {
      iVar5 = iVar5 + 4;
      (ent->curstate).renderamt = iVar5;
      goto LAB_001aac60;
    }
LAB_001aaef0:
    iVar5 = 0xff;
    (ent->curstate).renderamt = 0xff;
    goto LAB_001aac60;
  case 9:
    dVar6 = 4.0;
    goto LAB_001aae26;
  case 10:
    dVar6 = 16.0;
LAB_001aae26:
    dVar6 = sin(dVar6 * cl.time + dVar2);
LAB_001aae36:
    if ((int)(dVar6 * 20.0) < 0) {
      return 0;
    }
    goto switchD_001aac30_default;
  case 0xb:
    dVar6 = sin(cl.time * 36.0 + dVar2);
    goto LAB_001aae36;
  case 0xc:
    local_1c = sin(cl.time + cl.time);
    dVar6 = dVar6 * 17.0;
    goto LAB_001aae9a;
  case 0xd:
    local_1c = sin(cl.time * 16.0);
    dVar6 = dVar6 * 23.0;
LAB_001aae9a:
    dVar6 = sin((double)fVar1 + dVar6);
    dVar6 = dVar6 + local_1c;
    goto LAB_001aae36;
  case 0xf:
  case 0x10:
                    /* Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: float dist@[???] */
    if (iVar5 == 0xf) {
      iVar5 = 0xb4;
      (ent->curstate).renderamt = 0xb4;
    }
    else {
      fVar1 = (ent->origin[2] - r_origin[2]) * vpn[2] +
              vpn[0] * (ent->origin[0] - r_origin[0]) + vpn[1] * (ent->origin[1] - r_origin[1]);
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
LAB_001aac60:
  iVar3 = 0;
  if (-1 < iVar5) {
    iVar3 = iVar5;
  }
  return iVar3;
}


// CL_FxTransform  @ 001aaf80
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
      }
      else {
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
      return;
    }
  }
  return;
}


// CL_GGSpeeds  @ 0019a980
void CL_GGSpeeds(float flCurTime)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  iVar1 = host_framecount;
  fVar2 = flCurTime;
  if ((g_flTime != 0.0) && (fVar2 = g_flTime, 1.0 <= flCurTime - g_flTime)) {
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
        g_rgFPS[g_iSecond] = iVar3;
        g_iSecond = g_iSecond + 1;
      }
    }
    else {
      cls.td_startframe = host_framecount;
      cls.td_starttime = (float)realtime;
    }
    g_iFrames = iVar1;
    g_flTime = flCurTime;
    fVar2 = g_flTime;
  }
  g_flTime = fVar2;
  return;
}


// CL_GameDir_f  @ 0019f7e0
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


// CL_GameGauge_f  @ 0019a5a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_GameGauge_f(void)

{
  int iVar1;
  
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
                    /* Unresolved local var: char[256] name@[???] */
    if (cmd_source == src_command) {
      iVar1 = Cmd_Argc();
      if ((iVar1 == 2) || (iVar1 = Cmd_Argc(), iVar1 == 3)) {
        CL_PlayDemo_f();
      }
      else {
        Con_Printf("playdemo <demoname> <replayspeed>: plays a demo\n");
        Con_Printf("replayspeed == 1.0 default\n");
      }
    }
    Cvar_Set("cl_gg","1");
    cls.td_starttime = (float)realtime;
    cls.td_startframe = host_framecount;
    cls.td_lastframe = -1;
    cls.timedemo = true;
    g_flTime = 0.0;
    g_iSecond = 0;
    g_iMaxFPS = 0;
    g_iMinFPS = 0x7fffffff;
    g_iFrames = host_framecount;
    return;
  }
  Con_Printf("gg <demoname> : Game Gauge 99\n");
  return;
}


// CL_GetCDKeyHash  @ 0019f8d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * CL_GetCDKeyHash(void)

{
  char *pcVar1;
  uchar local_184 [256];
  MD5Context_t local_84;
  uchar local_2c [16];
  uint local_1c [3];
  int local_10;
  
                    /* Unresolved local var: char[256] szKeyBuffer@[???]
                       Unresolved local var: int nKeyLength@[???]
                       Unresolved local var: int bDedicated@[???]
                       Unresolved local var: MD5Context_t ctx@[???]
                       Unresolved local var: uchar[16] digest@[???] */
  local_1c[0] = 0x40;
  local_10 = 0;
  Sys_GetCDKey((char *)local_184,(int *)local_1c,&local_10);
  if (local_10 == 0) {
    if (local_1c[0] - 1 < 0xff) {
      local_184[local_1c[0]] = '\0';
      Q_memset(&local_84,0,0x58);
      Q_memset(local_2c,0,0x10);
      MD5Init(&local_84);
      MD5Update(&local_84,local_184,local_1c[0]);
      MD5Final(local_2c,&local_84);
      Q_memset(CL_GetCDKeyHash::szHashedKeyBuffer,0,0x100);
      pcVar1 = MD5_Print(local_2c);
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
  return pcVar1;
}


// CL_GetDemoViewInfo  @ 00196310
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


// CL_GetDemoViewInfo_OLD  @ 00195ef0
void CL_GetDemoViewInfo_OLD(ref_params_t *rp,vec_t *view,int *viewmodel)

{
  float fVar1;
  float fVar2;
  int iVar3;
  movevars_s *pmVar4;
  int iVar5;
  usercmd_s *puVar6;
  int iVar7;
  undefined4 uVar8;
  float fVar9;
  uint uVar10;
  int iVar11;
  demo_info_t *pdVar12;
  float local_28;
  float local_24;
  float local_20;
  
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
  iVar3 = rp->viewport[3];
  iVar11 = rp->viewport[2];
  pmVar4 = rp->movevars;
  iVar5 = rp->viewport[0];
  puVar6 = rp->cmd;
  iVar7 = rp->viewport[1];
  uVar10 = 0;
  do {
    uVar8 = *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar10);
    *(undefined4 *)((int)rp->vieworg + uVar10 + 4) =
         *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar10 + 4);
    *(undefined4 *)((int)rp->vieworg + uVar10) = uVar8;
    uVar10 = uVar10 + 8;
  } while (uVar10 < 0xe8);
  rp->viewport[0] = iVar5;
  rp->viewport[2] = iVar11;
  rp->viewport[1] = iVar7;
  rp->viewport[3] = iVar3;
  rp->cmd = puVar6;
  rp->movevars = pmVar4;
  if (cls.timedemo != false) {
    *view = dem_frames[0].view[0];
    view[1] = dem_frames[0].view[1];
    view[2] = dem_frames[0].view[2];
    *viewmodel = dem_frames[0].viewmodel;
    return;
  }
  fVar2 = (g_demotimescale * (float)realtime - cls.demostarttime) - 0.02;
  iVar3 = 1;
  pdVar12 = dem_frames;
  do {
    iVar11 = iVar3;
    dem_frames[iVar11].rp.cmd = (usercmd_s *)(iVar11 * 0x1b4 + 0x381b6c);
    dem_frames[iVar11].rp.movevars = (movevars_s *)(iVar11 * 0x1b4 + 0x381ba0);
    fVar1 = dem_frames[iVar11].timestamp;
    if (fVar1 == 0.0) {
      return;
    }
    if (fVar1 < fVar2) goto LAB_00196042;
    iVar3 = iVar11 + 1;
    pdVar12 = dem_frames + iVar11;
  } while (iVar11 + 1 != 0x1f);
  if (fVar1 != 0.0) {
LAB_00196042:
    if (pdVar12->timestamp != fVar1) {
      fVar2 = (fVar2 - fVar1) / (pdVar12->timestamp - fVar1);
      fVar1 = 1.0;
      if ((fVar2 <= 1.0) && (fVar1 = 0.0, 0.0 <= fVar2)) {
        fVar1 = fVar2;
      }
      local_28 = (pdVar12->rp).vieworg[0] - dem_frames[iVar11].rp.vieworg[0];
      local_24 = (pdVar12->rp).vieworg[1] - dem_frames[iVar11].rp.vieworg[1];
      local_20 = (pdVar12->rp).vieworg[2] - dem_frames[iVar11].rp.vieworg[2];
      VectorMA(dem_frames[iVar11].rp.vieworg,fVar1,&local_28,rp->vieworg);
      fVar2 = dem_frames[iVar11].rp.viewangles[0];
      fVar9 = (pdVar12->rp).viewangles[0] - fVar2;
      if (180.0 < fVar9) {
        fVar9 = fVar9 - 360.0;
      }
      else if (fVar9 < -180.0) {
        fVar9 = fVar9 + 360.0;
      }
      rp->viewangles[0] = fVar9 * fVar1 + fVar2;
      fVar2 = dem_frames[iVar11].rp.viewangles[1];
      fVar9 = (pdVar12->rp).viewangles[1] - fVar2;
      if (180.0 < fVar9) {
        fVar9 = fVar9 - 360.0;
      }
      else if (fVar9 < -180.0) {
        fVar9 = fVar9 + 360.0;
      }
      rp->viewangles[1] = fVar9 * fVar1 + fVar2;
      fVar2 = dem_frames[iVar11].rp.viewangles[2];
      fVar9 = (pdVar12->rp).viewangles[2] - fVar2;
      if (fVar9 <= 180.0) {
        if (fVar9 < -180.0) {
          fVar9 = fVar9 + 360.0;
        }
      }
      else {
        fVar9 = fVar9 - 360.0;
      }
      rp->viewangles[2] = fVar9 * fVar1 + fVar2;
      COM_NormalizeAngles(rp->viewangles);
      local_28 = (pdVar12->rp).simvel[0] - dem_frames[iVar11].rp.simvel[0];
      local_24 = (pdVar12->rp).simvel[1] - dem_frames[iVar11].rp.simvel[1];
      local_20 = (pdVar12->rp).simvel[2] - dem_frames[iVar11].rp.simvel[2];
      VectorMA(dem_frames[iVar11].rp.simvel,fVar1,&local_28,rp->simvel);
      local_28 = (pdVar12->rp).simorg[0] - dem_frames[iVar11].rp.simorg[0];
      local_24 = (pdVar12->rp).simorg[1] - dem_frames[iVar11].rp.simorg[1];
      local_20 = (pdVar12->rp).simorg[2] - dem_frames[iVar11].rp.simorg[2];
      VectorMA(dem_frames[iVar11].rp.simorg,fVar1,&local_28,rp->simorg);
      fVar2 = dem_frames[iVar11].rp.viewheight[0];
      rp->viewheight[0] = ((pdVar12->rp).viewheight[0] - fVar2) * fVar1 + fVar2;
      fVar2 = dem_frames[iVar11].rp.viewheight[1];
      rp->viewheight[1] = ((pdVar12->rp).viewheight[1] - fVar2) * fVar1 + fVar2;
      fVar2 = dem_frames[iVar11].rp.viewheight[2];
      rp->viewheight[2] = ((pdVar12->rp).viewheight[2] - fVar2) * fVar1 + fVar2;
      local_28 = pdVar12->view[0] - dem_frames[iVar11].view[0];
      local_24 = pdVar12->view[1] - dem_frames[iVar11].view[1];
      local_20 = pdVar12->view[2] - dem_frames[iVar11].view[2];
      VectorMA(dem_frames[iVar11].view,fVar1,&local_28,view);
      *viewmodel = pdVar12->viewmodel;
      return;
    }
  }
  return;
}


// CL_GetDownloadQueueSize  @ 00183ed0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_GetDownloadQueueSize(void)

{
  return TheDownloadManager.m_queuedRequests.m_Size;
}


// CL_GetEstimatedFrame  @ 0013f620
float CL_GetEstimatedFrame(cl_entity_t *ent)

{
  model_t *mod;
  cl_entity_t *pcVar1;
  void *pvVar2;
  float fVar3;
  
                    /* Unresolved local var: float f@[DW_OP_reg11(ST0)]
                       Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: cl_entity_t * oldce@[???] */
  pcVar1 = currententity;
  mod = ent->model;
  if ((mod != (model_t *)0x0) && (mod->type == mod_studio)) {
    pvVar2 = Mod_Extradata(mod);
    if (pvVar2 != (void *)0x0) {
      currententity = ent;
      fVar3 = CL_StudioEstimateFrame
                        ((mstudioseqdesc_t *)
                         ((ent->curstate).sequence * 0xb0 + *(int *)((int)pvVar2 + 0xa8) +
                         (int)pvVar2));
      currententity = pcVar1;
      return fVar3;
    }
  }
  return 0.0;
}


// CL_GetFragmentSize  @ 0019c180
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


// CL_GetMessage  @ 0019dda0
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


// CL_GetModelByIndex  @ 001a3670
model_t * CL_GetModelByIndex(int index)

{
  char *pcVar1;
  model_t *mod;
  double dVar2;
  double dVar3;
  
                    /* Unresolved local var: model_t * mod@[???] */
  mod = (model_t *)0x0;
  if (index < 0x200) {
    pcVar1 = "_ZN5vgui219AnimatingImagePanel13GetMessageMapEv";
    mod = *(model_t **)(cl.resourcesneeded.szFileName + (int)pcVar1 * 4 + index * 4 + 0x18);
    if ((mod != (model_t *)0x0) && (mod->needload - true < 2)) {
      if (fs_precache_timings.value != 0.0) {
                    /* Unresolved local var: double end@[???]
                       Unresolved local var: double start@[???] */
        dVar2 = Sys_FloatTime();
        Mod_LoadModel(mod,false,false);
        dVar3 = Sys_FloatTime();
        Con_DPrintf("fs_precache_timings: loaded model %s in time %.3f sec\n",mod,
                    (double)(float)((longdouble)dVar3 - (longdouble)dVar2));
        return *(model_t **)(cl.resourcesneeded.szFileName + (int)pcVar1 * 4 + index * 4 + 0x18);
      }
      Mod_LoadModel(mod,false,false);
      return *(model_t **)(cl.resourcesneeded.szFileName + (int)pcVar1 * 4 + index * 4 + 0x18);
    }
  }
  return mod;
}


// CL_GetPlayerHulls  @ 001a2b20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_GetPlayerHulls(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iResult@[???] */
  iVar1 = ClientDLL_GetHullBounds(0,player_mins[0],player_maxs[0]);
  if (iVar1 != 0) {
    iVar1 = ClientDLL_GetHullBounds(1,player_mins[1],player_maxs[1]);
    if (iVar1 != 0) {
      iVar1 = ClientDLL_GetHullBounds(2,player_mins[2],player_maxs[2]);
      if (iVar1 != 0) {
        ClientDLL_GetHullBounds(3,player_mins[3],player_maxs[3]);
      }
    }
  }
  return;
}


// CL_GetServerCount  @ 001a3760
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_GetServerCount(void)

{
  return cl.servercount;
}


// CL_GetTargetTime  @ 00193920
void CL_GetTargetTime(float *target)

{
  *target = (float)realtime;
  return;
}


// CL_GetWorldModel  @ 001a3750
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

model_t * CL_GetWorldModel(void)

{
  return cl.worldmodel;
}


// CL_HTTPCancel_f  @ 00183bc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_HTTPCancel_f(void)

{
  int iVar1;
  int iVar2;
  
  DownloadManager::Reset(&TheDownloadManager);
                    /* Unresolved local var: int i@[???] */
  if (0 < TheDownloadManager.m_downloadedMaps.m_Size) {
    iVar2 = 0;
    iVar1 = TheDownloadManager.m_downloadedMaps.m_Size;
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


// CL_HTTPStop_f  @ 00183ba0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_HTTPStop_f(void)

{
  DownloadManager::Reset(&TheDownloadManager);
  return;
}


// CL_HTTPUpdate  @ 00184ac0
/* WARNING: Removing unreachable block (ram,0x00184bc2) */
/* WARNING: Removing unreachable block (ram,0x00184bfe) */
/* WARNING: Removing unreachable block (ram,0x00184bd0) */
/* WARNING: Removing unreachable block (ram,0x00184c2e) */
/* WARNING: Removing unreachable block (ram,0x00184c49) */
/* WARNING: Removing unreachable block (ram,0x00184e10) */
/* WARNING: Removing unreachable block (ram,0x00184c55) */
/* WARNING: Removing unreachable block (ram,0x00184c5e) */
/* WARNING: Removing unreachable block (ram,0x00184df8) */
/* WARNING: Removing unreachable block (ram,0x00184c6e) */
/* WARNING: Removing unreachable block (ram,0x00184c7d) */
/* WARNING: Removing unreachable block (ram,0x00184bdf) */
/* WARNING: Removing unreachable block (ram,0x00184d8b) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_HTTPUpdate(void)

{
  RequestContext *pRVar1;
  HTTPStatus HVar2;
  bool bVar3;
  ListElem_t *pLVar4;
  ListElem_t *pLVar5;
  char *in_stack_ffffff84;
  HTTPRequestHandle in_stack_ffffff88;
  float *in_stack_ffffff8c;
  float local_5c;
  float local_54;
  uint local_2c;
  float local_20 [4];
  
                    /* Unresolved local var: float flPercentDone@[???]
                       Unresolved local var: float flTotalPercent@[???]
                       Unresolved local var: CUtlVector<int> vecDeleteList@[???]
                       Unresolved local var: bool bCompletedRequest@[???] */
                    /* Unresolved local var: int i@[???] */
  local_2c = (uint)TheDownloadManager.m_activeRequest.m_Head;
  if (local_2c == 0xffff) {
    bVar3 = false;
    local_5c = 0.0;
  }
  else {
    local_5c = 0.0;
                    /* Unresolved local var: float flNewPercent@[???] */
    bVar3 = false;
    local_54 = 0.0;
    pLVar5 = TheDownloadManager.m_activeRequest.m_Memory.m_pMemory;
    do {
      while( true ) {
        pRVar1 = pLVar5[local_2c].m_Element;
        HVar2 = pRVar1->status;
        if (HVar2 != HTTP_DONE) break;
        if (pRVar1->hOpenResource != 0) {
          in_stack_ffffff84 = pRVar1->gamePath;
          SetSecondaryProgressBarText(in_stack_ffffff84);
          CUtlVector<int>::InsertBefore
                    ((CUtlVector<int> *)in_stack_ffffff84,in_stack_ffffff88,(int *)in_stack_ffffff8c
                    );
          bVar3 = true;
          pLVar4 = TheDownloadManager.m_activeRequest.m_Memory.m_pMemory + local_2c;
          pLVar5 = TheDownloadManager.m_activeRequest.m_Memory.m_pMemory;
          goto LAB_00184b33;
        }
LAB_00184b5d:
        local_2c = (uint)pLVar5[local_2c].m_Next;
        bVar3 = true;
        if (local_2c == 0xffff) goto LAB_00184b74;
      }
      if (HVar2 == HTTP_ERROR) {
        CUtlVector<int>::InsertBefore
                  ((CUtlVector<int> *)in_stack_ffffff84,in_stack_ffffff88,(int *)in_stack_ffffff8c);
        pLVar5 = TheDownloadManager.m_activeRequest.m_Memory.m_pMemory;
        goto LAB_00184b5d;
      }
      if (HVar2 == HTTP_FETCH) {
        in_stack_ffffff84 = pRVar1->gamePath;
        SetSecondaryProgressBarText(in_stack_ffffff84);
        pLVar4 = TheDownloadManager.m_activeRequest.m_Memory.m_pMemory + local_2c;
        pLVar5 = TheDownloadManager.m_activeRequest.m_Memory.m_pMemory;
        if (pLVar4->m_Element->hOpenResource == 0) goto LAB_00184b33;
        local_20[0] = 0.0;
        in_stack_ffffff84 = (char *)SteamHTTP();
        in_stack_ffffff8c = local_20;
        in_stack_ffffff88 =
             (TheDownloadManager.m_activeRequest.m_Memory.m_pMemory[local_2c].m_Element)->
             hOpenResource;
        (*(((DownloadManager *)in_stack_ffffff84)->m_HTTPRequestCompleted).super_CCallbackBase.
          _vptr_CCallbackBase[0xf])();
        local_54 = local_54 + 1.0;
        local_5c = local_20[0] * 0.01 + local_5c;
        pLVar5 = TheDownloadManager.m_activeRequest.m_Memory.m_pMemory;
      }
      pLVar4 = pLVar5 + local_2c;
LAB_00184b33:
      local_2c = (uint)pLVar4->m_Next;
    } while (local_2c != 0xffff);
LAB_00184b74:
    if (0.0 < local_54) {
      local_5c = (local_5c / local_54) * 100.0;
    }
  }
  if ((float)TheDownloadManager.m_lastPercent != local_5c) {
    TheDownloadManager.m_lastPercent = (int)local_5c;
    in_stack_ffffff84 = (char *)((float)TheDownloadManager.m_lastPercent * 0.01);
    SetSecondaryProgressBar((float)in_stack_ffffff84);
  }
                    /* Unresolved local var: int idel@[???] */
  if (((bVar3) && (TheDownloadManager.m_activeRequest.m_ElementCount == 0)) &&
     (TheDownloadManager.m_queuedRequests.m_Size == 0)) {
    StopLoadingProgressBar();
    in_stack_ffffff84 = "retry\n";
    Cbuf_AddText("retry\n");
  }
  DownloadManager::StartNewDownload((DownloadManager *)in_stack_ffffff84);
  return;
}


// CL_HookEvent  @ 00191de0
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


// CL_HudMessage  @ 001a2a90
void CL_HudMessage(char *pMessage)

{
  int iSize;
  
  iSize = Q_strlen(pMessage);
  DispatchDirectUserMsg("HudText",iSize,pMessage);
  return;
}


// CL_Init  @ 001a2e00
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
  iVar1 = COM_CheckParm("-nomousegrab");
  if (iVar1 != 0) {
    Cvar_Set("cl_mousegrab","0");
  }
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
  cls.datagram.buffername = "cls.datagram";
  cls.isVAC2Secure = false;
  cls.GameServerSteamID._0_4_ = 0;
  cls.GameServerSteamID._4_4_ = 0;
  cls.datagram.maxsize = 4000;
  cls.build_num = 0;
  cls.datagram.flags = 0;
  Q_memset(&cl,0,0x1af668);
  cl.resourcesneeded.pNext = &cl.resourcesneeded;
  cl.resourcesonhand.pPrev = &cl.resourcesonhand;
  cl.resourcesneeded.pPrev = &cl.resourcesneeded;
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


// CL_InitEventSystem  @ 00191ec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitEventSystem(void)

{
  g_pEventHooks = (event_hook_t *)0x0;
  return;
}


// CL_InitExtrap  @ 00194c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitExtrap(void)

{
  Cvar_RegisterVariable(&ex_interp);
  return;
}


// CL_InitPrediction  @ 00194bd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitPrediction(void)

{
  Cvar_RegisterVariable(&cl_smoothtime);
  Cvar_RegisterVariable(&cl_nosmooth);
  Cvar_RegisterVariable(&cl_showerror);
  return;
}


// CL_InitSpectator  @ 001953c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitSpectator(void)

{
  Q_memset(&spectatorState,0,0x1930);
  Q_memset(&gDevOverview,0,0x1c);
  CL_CalculateDevOverviewParameters();
  if (cls.spectator != false) {
    spectatorState.playerstate.friction = 1.0;
    spectatorState.playerstate.gravity = 1.0;
    spectatorState.playerstate.number = cl.playernum + 1;
    spectatorState.playerstate.usehull = 1;
    spectatorState.playerstate.movetype = 8;
    spectatorState.client.maxspeed = movevars.spectatormaxspeed;
  }
  return;
}


// CL_InitTEnts  @ 001a3c90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_InitTEnts(void)

{
  model_t *pmVar1;
  int iVar2;
  int iVar3;
  tempent_s **pptVar4;
  
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
                    /* Unresolved local var: model_t * pModel@[???] */
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
  pptVar4 = &gTempEnts[0].next;
  iVar2 = 1;
  do {
    iVar3 = iVar2 + 1;
    *pptVar4 = gTempEnts + iVar2;
    pptVar4 = pptVar4 + 0x2ff;
    iVar2 = iVar3;
  } while (iVar3 != 500);
  gpTempEntFree = gTempEnts;
  gTempEnts[499].next = (tempent_s *)0x0;
  gpTempEntActive = (TEMPENTITY *)0x0;
  return;
}


// CL_InterpolateEntity  @ 00195160
void CL_InterpolateEntity(cl_entity_t *ent)

{
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: vec3_t target_origin@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: float targettime@[???] */
  CL_PureOrigin(ent,(float)cl.time - ex_interp.value,&local_24,&local_18);
  ent->angles[0] = local_18;
  ent->angles[1] = local_14;
  ent->angles[2] = local_10;
  ent->origin[0] = local_24;
  ent->origin[1] = local_20;
  ent->origin[2] = local_1c;
  return;
}


// CL_InterpolateModel  @ 0018b4a0
int __regparm3 CL_InterpolateModel(cl_entity_t_conflict2 *e)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_50;
  float local_4c;
  float local_48;
  vec_t local_44;
  vec_t local_40;
  vec_t local_3c;
  float local_38;
  float local_34;
  float local_30;
  position_history_t *local_2c [4];
  position_history_t *local_1c [6];
  
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
  if ((cl.moving == 0) || (iVar4 = 1, cl.onground != e->index)) {
    fVar3 = (float)cl.time - ex_interp.value;
    CL_FindInterpolationUpdates((cl_entity_t *)e,fVar3,local_2c,local_1c,(int *)0x0);
    iVar4 = 0;
    if ((local_2c[0] != (position_history_t *)0x0) && (local_1c[0] != (position_history_t *)0x0)) {
      fVar1 = local_1c[0]->animtime;
      fVar2 = local_2c[0]->animtime;
      fVar3 = fVar3 - fVar1;
      if (0.0 <= fVar3) {
        if ((fVar1 == 0.0) ||
           ((iVar4 = VectorCompare(local_1c[0]->origin,vec3_origin), iVar4 != 0 &&
            (iVar4 = VectorCompare(local_2c[0]->origin,vec3_origin), iVar4 == 0)))) {
          e->origin[0] = local_2c[0]->origin[0];
          e->origin[1] = local_2c[0]->origin[1];
          e->origin[2] = local_2c[0]->origin[2];
          e->angles[0] = local_2c[0]->angles[0];
          e->angles[1] = local_2c[0]->angles[1];
          e->angles[2] = local_2c[0]->angles[2];
          return 0;
        }
        if (fVar1 == fVar2) {
          e->origin[0] = local_2c[0]->origin[0];
          e->origin[1] = local_2c[0]->origin[1];
          e->origin[2] = local_2c[0]->origin[2];
          e->angles[0] = local_2c[0]->angles[0];
          e->angles[1] = local_2c[0]->angles[1];
          e->angles[2] = local_2c[0]->angles[2];
          iVar4 = 1;
        }
        else {
          local_50 = local_2c[0]->origin[0] - local_1c[0]->origin[0];
          local_4c = local_2c[0]->origin[1] - local_1c[0]->origin[1];
          iVar4 = 0;
          local_48 = local_2c[0]->origin[2] - local_1c[0]->origin[2];
          fVar3 = fVar3 / (fVar2 - fVar1);
          if (0.0 <= fVar3) {
            if (1.0 < fVar3) {
              fVar3 = 1.0;
            }
            VectorMA(local_1c[0]->origin,fVar3,&local_50,&local_44);
                    /* Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???]
                       Unresolved local var: float d@[???] */
            fVar1 = local_2c[0]->angles[0] - local_1c[0]->angles[0];
            if (180.0 < fVar1) {
              fVar1 = fVar1 - 360.0;
            }
            else if (fVar1 < -180.0) {
              fVar1 = fVar1 + 360.0;
            }
            local_38 = fVar1 * fVar3 + local_1c[0]->angles[0];
            fVar1 = local_2c[0]->angles[1] - local_1c[0]->angles[1];
            if (180.0 < fVar1) {
              fVar1 = fVar1 - 360.0;
            }
            else if (fVar1 < -180.0) {
              fVar1 = fVar1 + 360.0;
            }
            local_34 = fVar1 * fVar3 + local_1c[0]->angles[1];
            fVar1 = local_2c[0]->angles[2] - local_1c[0]->angles[2];
            if (fVar1 <= 180.0) {
              if (fVar1 < -180.0) {
                fVar1 = fVar1 + 360.0;
              }
            }
            else {
              fVar1 = fVar1 - 360.0;
            }
            local_30 = local_1c[0]->angles[2] + fVar1 * fVar3;
            COM_NormalizeAngles(&local_38);
            e->origin[0] = local_44;
            e->origin[1] = local_40;
            e->origin[2] = local_3c;
            e->angles[0] = local_38;
            e->angles[1] = local_34;
            e->angles[2] = local_30;
            iVar4 = 1;
          }
        }
      }
    }
  }
  return iVar4;
}


// CL_InterpolateModel  @ 0018bfe0
int CL_InterpolateModel(cl_entity_t_conflict2 *e)

{
  int iVar1;
  
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
  e->origin[0] = (e->curstate).origin[0];
  e->origin[1] = (e->curstate).origin[1];
  e->origin[2] = (e->curstate).origin[2];
  e->angles[0] = (e->curstate).angles[0];
  e->angles[1] = (e->curstate).angles[1];
  e->angles[2] = (e->curstate).angles[2];
  if ((((cls.timedemo == false) && (e->model != (model_s_conflict1 *)0x0)) &&
      ((e->model->name[0] != '*' || (r_bmodelinterp.value != 0.0)))) && (cl.maxclients != 1)) {
    iVar1 = CL_InterpolateModel(e);
    return iVar1;
  }
  return 1;
}


// CL_InterpolateVector  @ 001938e0
void CL_InterpolateVector(float frac,vec_t *src,vec_t *dest,vec_t *output)

{
                    /* Unresolved local var: int i@[???] */
  *output = (*dest - *src) * frac + *src;
  output[1] = (dest[1] - src[1]) * frac + src[1];
  output[2] = src[2] + (dest[2] - src[2]) * frac;
  return;
}


// CL_IsDevOverviewMode  @ 00195200
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


// CL_IsPlayerIndex  @ 0018c470
qboolean CL_IsPlayerIndex(int index)

{
  qboolean qVar1;
  
  qVar1 = false;
  if (0 < index) {
    qVar1 = (qboolean)(index <= cl.maxclients);
  }
  return qVar1;
}


// CL_IsSpectateOnly  @ 001951e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_IsSpectateOnly(void)

{
  (*g_engdstAddrs.IsSpectateOnly)();
  return (uint)(cls.spectator != false);
}


// CL_KeepConnectionActive  @ 001a35a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_KeepConnectionActive(void)

{
  float fVar1;
  int iVar2;
  double dVar3;
  byte local_4c [32];
  sizebuf_t local_2c;
  
                    /* Unresolved local var: float flCurrentTime@[???] */
  dVar3 = Sys_FloatTime();
  fVar1 = (float)dVar3;
  if (fVar1 < CL_KeepConnectionActive::flLastKeepaliveTime) {
    CL_KeepConnectionActive::flLastKeepaliveTime = fVar1;
  }
  if (5.0 < fVar1 - CL_KeepConnectionActive::flLastKeepaliveTime) {
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar[32] szData@[???]
                       Unresolved local var: int iCount@[???] */
    if (cls.state != ca_disconnected) {
      local_2c.data = local_4c;
      local_2c.maxsize = 0x20;
      iVar2 = 0x20;
      local_2c.cursize = 0;
      local_2c.buffername = "Client Keepalive";
      local_2c.flags = 0;
      do {
        MSG_WriteByte(&local_2c,1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      Netchan_Transmit(&cls.netchan,local_2c.cursize,local_2c.data);
    }
    CL_KeepConnectionActive::flLastKeepaliveTime = fVar1;
    return;
  }
  return;
}


// CL_LerpPoint  @ 0018f1e0
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


// CL_LinkCustomEntity  @ 0018d880
void CL_LinkCustomEntity(cl_entity_t_conflict2 *ent,entity_state_t_conflict *state)

{
  undefined4 uVar1;
  cl_entity_t *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  (ent->curstate).movetype = state->modelindex;
  if (ent->model->type != mod_sprite) {
    Sys_Error("Bad model on beam ( not sprite ) ");
  }
  uVar3 = 0;
  do {
    uVar4 = uVar3;
    uVar1 = *(undefined4 *)((int)(ent->curstate).origin + (uVar4 - 0xc));
    *(undefined4 *)((int)(ent->prevstate).origin + (uVar4 - 0x10)) =
         *(undefined4 *)((int)(ent->curstate).origin + (uVar4 - 0x10));
    *(undefined4 *)((int)(ent->prevstate).origin + (uVar4 - 0xc)) = uVar1;
    pcVar2 = cl_entities;
    uVar3 = uVar4 + 8;
  } while (uVar4 + 8 < 0x150);
  *(undefined4 *)((int)(ent->prevstate).origin + (uVar4 - 8)) =
       *(undefined4 *)((int)(ent->curstate).origin + (uVar4 - 8));
  (ent->latched).prevsequence = (ent->curstate).sequence;
  (ent->latched).prevorigin[0] = ent->origin[0];
  (ent->latched).prevorigin[1] = ent->origin[1];
  (ent->latched).prevorigin[2] = ent->origin[2];
  (ent->latched).prevangles[0] = ent->angles[0];
  (ent->latched).prevangles[1] = ent->angles[1];
  (ent->latched).prevangles[2] = ent->angles[2];
  iVar5 = ClientDLL_AddEntity(3,pcVar2 + ent->index);
  if (iVar5 != 0) {
    return;
  }
  Con_DPrintf("Overflow beam entity list!\n");
  return;
}


// CL_LinkPacketEntities  @ 0018d990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_LinkPacketEntities(void)

{
  packet_entities_t *ppVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  dlight_t_conflict *pdVar15;
  model_s *pmVar16;
  cl_entity_t *ent;
  int iVar17;
  entity_state_t_conflict *state;
  int iVar18;
  float fVar19;
  
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: dlight_t * dl@[???]
                       Unresolved local var: int pnum@[???]
                       Unresolved local var: float saveTime@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean parametric@[???] */
  iVar11 = cl.parsecountmod;
  ppVar1 = &cl.frames[cl.parsecountmod].packet_entities;
  iVar13 = cl.frames[cl.parsecountmod].packet_entities.num_entities;
  if (iVar13 < 1) {
    return;
  }
  iVar18 = 0;
  iVar17 = 0;
LAB_0018d9c0:
  do {
    while( true ) {
      state = (entity_state_t_conflict *)
              ((int)(cl.frames[iVar11].packet_entities.entities)->origin + iVar18 + -0x10);
      iVar5 = state->number;
      if ((((iVar5 < 1) || (cl.maxclients < iVar5)) && (state->modelindex != 0)) &&
         ((state->effects & 0x80) == 0)) break;
LAB_0018db50:
      iVar17 = iVar17 + 1;
      iVar18 = iVar18 + 0x154;
      if (iVar13 <= iVar17) {
        return;
      }
    }
    ent = cl_entities + iVar5;
    uVar14 = 0;
    do {
      uVar12 = uVar14;
      uVar6 = *(undefined4 *)((int)state->origin + (uVar12 - 0x10));
      *(undefined4 *)((int)(ent->curstate).origin + (uVar12 - 0xc)) =
           *(undefined4 *)((int)state->origin + (uVar12 - 0xc));
      *(undefined4 *)((int)(ent->curstate).origin + (uVar12 - 0x10)) = uVar6;
      uVar14 = uVar12 + 8;
    } while (uVar12 + 8 < 0x150);
    *(undefined4 *)((int)(ent->curstate).origin + (uVar12 - 8)) =
         *(undefined4 *)((int)state->origin + (uVar12 - 8));
    pmVar16 = ent->model;
    if (pmVar16 == (model_s *)0x0) {
      iVar17 = iVar17 + 1;
      iVar18 = iVar18 + 0x154;
      Con_Printf("Tried to link edict %i without model\n",ent->index);
      iVar13 = ppVar1->num_entities;
      if (iVar13 <= iVar17) {
        return;
      }
      goto LAB_0018d9c0;
    }
    if (((ent->curstate).impacttime == 0.0) || ((ent->curstate).starttime == 0.0)) {
      if ((ent->curstate).animtime == (ent->prevstate).animtime) {
        iVar13 = VectorCompare((ent->curstate).origin,(ent->prevstate).origin);
        if (iVar13 == 0) {
          ent->lastmove = (float)((longdouble)0.2 + (longdouble)cl.time);
        }
        pmVar16 = ent->model;
      }
      bVar10 = false;
      if (((((ent->curstate).eflags & 1) != 0) && ((ent->curstate).animtime != 0.0)) &&
         (bVar10 = false, pmVar16->type == mod_studio)) {
        if ((float)cl.time <= ent->lastmove) {
          (ent->curstate).movetype = 0;
          bVar10 = false;
          R_ResetLatched(ent,true);
          (ent->latched).prevorigin[0] = (ent->curstate).origin[0];
          (ent->latched).prevorigin[1] = (ent->curstate).origin[1];
          (ent->latched).prevorigin[2] = (ent->curstate).origin[2];
          (ent->latched).prevangles[0] = (ent->curstate).angles[0];
          (ent->latched).prevangles[1] = (ent->curstate).angles[1];
          (ent->latched).prevangles[2] = (ent->curstate).angles[2];
          pmVar16 = ent->model;
        }
        else {
          (ent->curstate).movetype = 4;
        }
      }
    }
    else {
      bVar10 = true;
    }
    if (pmVar16->name[0] == '*') {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???] */
      ent->origin[0] = (ent->curstate).origin[0];
      ent->origin[1] = (ent->curstate).origin[1];
      ent->origin[2] = (ent->curstate).origin[2];
      ent->angles[0] = (ent->curstate).angles[0];
      ent->angles[1] = (ent->curstate).angles[1];
      ent->angles[2] = (ent->curstate).angles[2];
      if ((cls.timedemo == false) &&
         (((pmVar16->name[0] != '*' || (r_bmodelinterp.value != 0.0)) && (cl.maxclients != 1)))) {
        CL_InterpolateModel((cl_entity_t_conflict2 *)ent);
      }
      goto LAB_0018dbda;
    }
    if (!bVar10) {
      iVar13 = (ent->curstate).movetype;
      if (((iVar13 == 3) || (iVar13 == 0)) || ((iVar13 == 5 || (iVar13 == 4)))) {
        if (((g_bIsCStrike != 0) || (g_bIsCZero != 0)) &&
           ((iVar13 == 4 && (cls.netchan.remote_address.type != NA_LOOPBACK)))) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???] */
          ent->origin[0] = (ent->curstate).origin[0];
          ent->origin[1] = (ent->curstate).origin[1];
          ent->origin[2] = (ent->curstate).origin[2];
          ent->angles[0] = (ent->curstate).angles[0];
          ent->angles[1] = (ent->curstate).angles[1];
          ent->angles[2] = (ent->curstate).angles[2];
          if ((cls.timedemo == false) &&
             ((((pmVar16->name[0] != '*' || (r_bmodelinterp.value != 0.0)) && (cl.maxclients != 1))
              && (iVar13 = CL_InterpolateModel((cl_entity_t_conflict2 *)ent), iVar13 == 0)))) {
            iVar13 = ppVar1->num_entities;
            goto LAB_0018db50;
          }
          goto LAB_0018dbda;
        }
        goto LAB_0018ddad;
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: position_history_t * ph0@[???]
                       Unresolved local var: qboolean extrapolate@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: position_history_t * ph1@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t angles@[???] */
      ent->origin[0] = (ent->curstate).origin[0];
      ent->origin[1] = (ent->curstate).origin[1];
      ent->origin[2] = (ent->curstate).origin[2];
      ent->angles[0] = (ent->curstate).angles[0];
      ent->angles[1] = (ent->curstate).angles[1];
      ent->angles[2] = (ent->curstate).angles[2];
      if ((((cls.timedemo != false) || ((pmVar16->name[0] == '*' && (r_bmodelinterp.value == 0.0))))
          || (cl.maxclients == 1)) ||
         (iVar13 = CL_InterpolateModel((cl_entity_t_conflict2 *)ent), iVar13 != 0)) {
LAB_0018dbda:
        bVar4 = (byte)state->entityType;
        goto joined_r0x0018dbdd;
      }
LAB_0018db40:
      iVar13 = ppVar1->num_entities;
      goto LAB_0018db50;
    }
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float dt@[???] */
    if (((ent->curstate).starttime != 0.0) && ((ent->curstate).impacttime != 0.0)) {
      CL_ParametricMove((cl_entity_t_conflict2 *)ent);
    }
LAB_0018ddad:
    ent->origin[0] = (ent->curstate).origin[0];
    ent->origin[1] = (ent->curstate).origin[1];
    ent->origin[2] = (ent->curstate).origin[2];
    ent->angles[0] = (ent->curstate).angles[0];
    ent->angles[1] = (ent->curstate).angles[1];
    ent->angles[2] = (ent->curstate).angles[2];
    bVar4 = (byte)state->entityType;
joined_r0x0018dbdd:
    if ((bVar4 & 1) != 0) {
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
      fVar19 = (ent->curstate).origin[0];
      fVar2 = (ent->curstate).origin[1];
      fVar3 = (ent->curstate).origin[2];
      if (((128.0 < fVar19 - (ent->prevstate).origin[0]) ||
          (128.0 < fVar2 - (ent->prevstate).origin[1])) ||
         (128.0 < fVar3 - (ent->prevstate).origin[2])) {
        vVar7 = (ent->curstate).angles[0];
        (ent->latched).prevorigin[0] = fVar19;
        (ent->latched).prevorigin[1] = fVar2;
        (ent->latched).prevorigin[2] = fVar3;
        (ent->latched).prevangles[0] = vVar7;
        (ent->latched).prevangles[1] = (ent->curstate).angles[1];
        (ent->latched).prevangles[2] = (ent->curstate).angles[2];
        CL_ResetPositions(ent);
      }
      uVar14 = (ent->curstate).effects;
      if ((uVar14 & 1) != 0) {
        (*efx.R_EntityParticles)((cl_entity_s_conflict *)ent);
        uVar14 = (ent->curstate).effects;
      }
      if (ent->index != 1) {
        if ((uVar14 & 4) != 0) {
          pdVar15 = (*efx.CL_AllocDlight)(ent->index);
          pdVar15->origin[0] = ent->origin[0];
          pdVar15->origin[1] = ent->origin[1];
          fVar19 = ent->origin[2];
          (pdVar15->color).b = 0xfa;
          (pdVar15->color).g = 0xfa;
          (pdVar15->color).r = 0xfa;
          pdVar15->origin[2] = fVar19 + 16.0;
          fVar19 = RandomFloat(400.0,431.0);
          pdVar15->radius = fVar19;
          pdVar15->die = (float)((longdouble)0.001 + (longdouble)cl.time);
          uVar14 = (ent->curstate).effects;
        }
        if ((uVar14 & 8) != 0) {
          pdVar15 = (*efx.CL_AllocDlight)(ent->index);
          pdVar15->origin[0] = ent->origin[0];
          pdVar15->origin[1] = ent->origin[1];
          vVar7 = ent->origin[2];
          (pdVar15->color).b = 'd';
          (pdVar15->color).g = 'd';
          (pdVar15->color).r = 'd';
          pdVar15->origin[2] = vVar7;
          fVar19 = RandomFloat(200.0,231.0);
          pdVar15->radius = fVar19;
          pdVar15->die = (float)((longdouble)0.001 + (longdouble)cl.time);
          uVar14 = (ent->curstate).effects;
        }
      }
      if ((uVar14 & 0x40) != 0) {
                    /* Unresolved local var: dlight_t * dl@[???] */
        pdVar15 = (*efx.CL_AllocDlight)(state->number);
        pdVar15->origin[0] = ent->origin[0];
        pdVar15->origin[1] = ent->origin[1];
        vVar7 = ent->origin[2];
        pdVar15->radius = 200.0;
        (pdVar15->color).b = 'd';
        (pdVar15->color).g = 'd';
        pdVar15->origin[2] = vVar7;
        (pdVar15->color).r = 'd';
        pdVar15->die = (float)((longdouble)0.001 + (longdouble)cl.time);
        (*efx.R_RocketFlare)(ent->origin);
      }
      CL_AddModelEffects(state->number,(cl_entity_t_conflict2 *)ent,(model_t_conflict *)ent->model);
      vVar7 = ent->origin[0];
      vVar8 = ent->origin[1];
      vVar9 = ent->origin[2];
      ent->attachment[0][0] = vVar7;
      ent->attachment[0][1] = vVar8;
      ent->attachment[0][2] = vVar9;
      ent->attachment[1][0] = vVar7;
      ent->attachment[1][1] = vVar8;
      ent->attachment[1][2] = vVar9;
      ent->attachment[2][0] = vVar7;
      ent->attachment[2][1] = vVar8;
      ent->attachment[2][2] = vVar9;
      ent->attachment[3][0] = vVar7;
      ent->attachment[3][1] = vVar8;
      ent->attachment[3][2] = vVar9;
      ClientDLL_AddEntity(0,ent);
      goto LAB_0018db40;
    }
    iVar17 = iVar17 + 1;
    iVar18 = iVar18 + 0x154;
    CL_LinkCustomEntity((cl_entity_t_conflict2 *)ent,state);
    iVar13 = ppVar1->num_entities;
    if (iVar13 <= iVar17) {
      return;
    }
  } while( true );
}


// CL_LinkPlayers  @ 0018e200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_LinkPlayers(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  int iVar8;
  dlight_t_conflict *pdVar9;
  int iVar10;
  cl_entity_t *ent;
  int iVar11;
  int iVar12;
  float fVar13;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  iVar12 = 3000;
  iVar10 = 1;
  iVar11 = cl.parsecountmod * 0x42b8 + 0xc7f6fc;
  do {
    iVar1 = iVar10 + -1;
    if ((*(int *)(iVar11 + 0xc) == cl.parsecount) &&
       ((((iVar8 = ClientDLL_IsThirdPerson(), iVar8 != 0 || (cl.viewentity + -1 != iVar1)) ||
         (chase_active.value != 0.0)) &&
        ((*(int *)(iVar11 + 0x28) != 0 && ((*(byte *)(iVar11 + 0x3c) & 0x80) == 0)))))) {
      if (0x1ff < cl_numvisedicts) break;
      ent = (cl_entity_t *)((int)(cl_entities->baseline).origin + iVar12 + -0x18);
      if (ent->index != iVar10) {
        ent->index = iVar10;
      }
      if (cl.playernum == iVar1) {
        vVar5 = *(vec_t *)(iVar11 + 0x10);
        ent->origin[0] = vVar5;
        vVar6 = *(vec_t *)(iVar11 + 0x14);
        ent->origin[1] = vVar6;
        vVar7 = *(vec_t *)(iVar11 + 0x18);
        (ent->curstate).origin[0] = vVar5;
        (ent->prevstate).origin[0] = vVar5;
        (ent->prevstate).origin[2] = vVar7;
        ent->origin[2] = vVar7;
        (ent->curstate).origin[1] = vVar6;
        (ent->curstate).origin[2] = (ent->prevstate).origin[2];
        (ent->prevstate).origin[1] = vVar6;
        ent->angles[0] = (ent->curstate).angles[0];
        ent->angles[1] = (ent->curstate).angles[1];
        ent->angles[2] = (ent->curstate).angles[2];
      }
      if (((ent->curstate).effects & 0x20) != 0) {
        R_ResetLatched(ent,false);
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t distance@[???] */
      fVar13 = (ent->curstate).origin[0];
      fVar2 = (ent->curstate).origin[1];
      fVar3 = (ent->curstate).origin[2];
      if (((128.0 < fVar13 - (ent->prevstate).origin[0]) ||
          (128.0 < fVar2 - (ent->prevstate).origin[1])) ||
         (128.0 < fVar3 - (ent->prevstate).origin[2])) {
        vVar5 = (ent->curstate).angles[0];
        (ent->latched).prevorigin[0] = fVar13;
        (ent->latched).prevorigin[1] = fVar2;
        (ent->latched).prevorigin[2] = fVar3;
        (ent->latched).prevangles[0] = vVar5;
        (ent->latched).prevangles[1] = (ent->curstate).angles[1];
        (ent->latched).prevangles[2] = (ent->curstate).angles[2];
        CL_ResetPositions(ent);
      }
      if (cl.playernum == iVar1) {
        ent->origin[0] = cl.simorg[0];
        ent->origin[1] = cl.simorg[1];
        ent->origin[2] = cl.simorg[2];
      }
      else {
        ent->origin[0] = (ent->curstate).origin[0];
        ent->origin[1] = (ent->curstate).origin[1];
        ent->origin[2] = (ent->curstate).origin[2];
        ent->angles[0] = (ent->curstate).angles[0];
        ent->angles[1] = (ent->curstate).angles[1];
        ent->angles[2] = (ent->curstate).angles[2];
        CL_ComputePlayerOrigin(ent);
      }
      if (cl.viewentity + -1 != iVar1) {
        uVar4 = (ent->curstate).effects;
        if ((uVar4 & 4) != 0) {
          pdVar9 = (*efx.CL_AllocDlight)(4);
          pdVar9->origin[0] = ent->origin[0];
          pdVar9->origin[1] = ent->origin[1];
          fVar13 = ent->origin[2];
          (pdVar9->color).b = 0xfa;
          (pdVar9->color).g = 0xfa;
          (pdVar9->color).r = 0xfa;
          pdVar9->origin[2] = fVar13 + 16.0;
          fVar13 = RandomFloat(400.0,431.0);
          pdVar9->radius = fVar13;
          pdVar9->die = (float)((longdouble)0.001 + (longdouble)cl.time);
          uVar4 = (ent->curstate).effects;
        }
        if ((uVar4 & 8) != 0) {
          pdVar9 = (*efx.CL_AllocDlight)(4);
          pdVar9->origin[0] = ent->origin[0];
          pdVar9->origin[1] = ent->origin[1];
          vVar5 = ent->origin[2];
          (pdVar9->color).b = 'd';
          (pdVar9->color).g = 'd';
          (pdVar9->color).r = 'd';
          pdVar9->origin[2] = vVar5;
          fVar13 = RandomFloat(200.0,231.0);
          pdVar9->radius = fVar13;
          pdVar9->die = (float)((longdouble)0.001 + (longdouble)cl.time);
        }
      }
      vVar5 = ent->origin[0];
      vVar6 = ent->origin[1];
      vVar7 = ent->origin[2];
      ent->attachment[0][0] = vVar5;
      ent->attachment[0][1] = vVar6;
      ent->attachment[0][2] = vVar7;
      ent->attachment[1][0] = vVar5;
      ent->attachment[1][1] = vVar6;
      ent->attachment[1][2] = vVar7;
      ent->attachment[2][0] = vVar5;
      ent->attachment[2][1] = vVar6;
      ent->attachment[2][2] = vVar7;
      ent->attachment[3][0] = vVar5;
      ent->attachment[3][1] = vVar6;
      ent->attachment[3][2] = vVar7;
      ClientDLL_AddEntity(1,ent);
    }
    iVar10 = iVar10 + 1;
    iVar11 = iVar11 + 0x154;
    iVar12 = iVar12 + 3000;
  } while (iVar10 != 0x21);
  CL_PlayerFlashlight();
  return;
}


// CL_ListCachedServers_f  @ 0019c960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ListCachedServers_f(void)

{
  int iVar1;
  uint slot;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: server_cache_t * p@[???] */
  if (num_servers == 0) {
    Con_Printf("No local servers in list.\nTry \'slist\' to search again.\n");
    return;
  }
  slot = 0;
  iVar1 = num_servers;
  if (0 < num_servers) {
    do {
      while (cached_servers[slot].inuse == 0) {
        slot = slot + 1;
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
      iVar1 = num_servers;
    } while ((int)slot < num_servers);
  }
  return;
}


// CL_ListDemo_f  @ 00198130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ListDemo_f(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  int *piVar9;
  double dVar10;
  double dVar11;
  char local_370 [8];
  undefined4 local_368;
  undefined4 local_364;
  undefined1 local_360 [260];
  undefined1 local_25c [264];
  int local_154;
  char local_150 [260];
  char local_4c [32];
  char *local_2c;
  void *local_28;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: demoheader_t header@[???]
                       Unresolved local var: demodirectory_t directory@[???]
                       Unresolved local var: demoentry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[32] type@[???] */
  if (cmd_source == src_command) {
    if ((cls.demorecording == false) && (cls.demoplayback == false)) {
      pcVar7 = local_150;
      pcVar1 = Cmd_Argv(1);
      snprintf(pcVar7,0x100,"%s",pcVar1);
      COM_DefaultExtension(pcVar7,".dem");
      Con_Printf("Demo contents for %s.\n",pcVar7);
      cls.demofile = FS_Open(pcVar7,"rb");
      if (cls.demofile == (FileHandle_t)0x0) {
        Con_Printf("ERROR: couldn\'t open.\n");
      }
      else {
        FS_Read(local_370,0x220,1,cls.demofile);
        iVar2 = Q_strncmp(local_370,"HLDEMO",6);
        if (iVar2 == 0) {
          Con_Printf("Demo file protocols %iN:%iD\nServer protocols at %iN:%iD\n",local_364,
                     local_368,0x30,5);
          Con_Printf("Map name :  %s\n",local_360);
          Con_Printf("Game .dll:  %s\n",local_25c);
          FS_Seek(cls.demofile,local_154,FILESYSTEM_SEEK_HEAD);
          FS_Read(&local_2c,4,1,cls.demofile);
          if (local_2c + -1 < (char *)0x400) {
            local_28 = Mem_Malloc((int)local_2c * 0x5c);
            FS_Read(local_28,(int)local_2c * 0x5c,1,cls.demofile);
            Con_Printf("\n");
            if (0 < (int)local_2c) {
              piVar5 = (int *)0x0;
              do {
                piVar4 = (int *)((int)piVar5 * 0x5c + (int)local_28);
                if (*piVar4 == 0) {
                  snprintf(local_4c,0x20,"Start segment");
                }
                else {
                  snprintf(local_4c,0x20,"Normal segment");
                }
                piVar5 = (int *)((int)piVar5 + 1);
                piVar8 = piVar4 + 1;
                dVar11 = (double)((float)piVar4[0x16] * 0.0009765625);
                iVar2 = piVar4[0x14];
                dVar10 = (double)(float)piVar4[0x13];
                piVar6 = piVar5;
                pcVar7 = local_4c;
                piVar9 = piVar8;
                Con_Printf("%i:  %s\n  \"%20s\"\nTime:  %.2f s.\nFrames:  %i\nSize:  %.2fK\n",piVar5
                           ,local_4c,piVar8,dVar10,iVar2,dVar11);
                uVar3 = 0;
                if (piVar4[0x11] != 0) {
                  Con_Printf("  Flags:\n",piVar6,pcVar7,piVar9,dVar10,iVar2,dVar11);
                  uVar3 = piVar4[0x11];
                  if ((uVar3 & 1) != 0) {
                    Con_Printf("     Title \"%s\"\n",piVar8,pcVar7,piVar9,dVar10,iVar2,dVar11);
                    uVar3 = piVar4[0x11];
                    piVar6 = piVar8;
                  }
                  if ((uVar3 & 4) != 0) {
                    piVar6 = (int *)piVar4[0x12];
                    Con_Printf("     Play %i\n",piVar6,pcVar7,piVar9,dVar10,iVar2,dVar11);
                    uVar3 = piVar4[0x11];
                  }
                  if ((uVar3 & 8) != 0) {
                    Con_Printf("     Fade in slow\n",piVar6,pcVar7,piVar9,dVar10,iVar2,dVar11);
                    uVar3 = piVar4[0x11];
                  }
                }
                if ((uVar3 & 0x10) != 0) {
                  Con_Printf("     Fade in fast\n",piVar6,pcVar7,piVar9,dVar10,iVar2,dVar11);
                  uVar3 = piVar4[0x11];
                }
                if ((uVar3 & 0x20) != 0) {
                  Con_Printf("     Fade out slow\n",piVar6,pcVar7,piVar9,dVar10,iVar2,dVar11);
                  uVar3 = piVar4[0x11];
                }
                if ((uVar3 & 0x40) != 0) {
                  Con_Printf("     Fade out fast\n",piVar6,pcVar7,piVar9,dVar10,iVar2,dVar11);
                }
                Con_Printf("\n");
              } while ((int)piVar5 < (int)local_2c);
            }
            FS_Close(cls.demofile);
            cls.demofile = (FileHandle_t)0x0;
            Mem_Free(local_28);
            return;
          }
          pcVar1 = "ERROR: demo had bogus # of directory entries:  %i\n";
          pcVar7 = local_2c;
        }
        else {
          pcVar1 = "%s is not a demo file\n";
        }
        Con_Printf(pcVar1,pcVar7);
        FS_Close(cls.demofile);
        cls.demofile = (FileHandle_t)0x0;
      }
    }
    else {
      Con_Printf("Listdemo only available when not running or recording.\n");
    }
  }
  return;
}


// CL_Listen  @ 0019f4e0
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
  cls.state = ca_connecting;
  cl.delta_sequence = -1;
  cl.validsequence = 0;
  cls.demonum = -1;
  cls.signon = 0;
  cls.connect_time = realtime;
  cls.lastoutgoingcommand = -1;
  cls.nextcmdtime = (float)realtime;
  return;
}


// CL_Listen  @ 0019f6f0
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


// CL_Listen_f  @ 0019f750
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


// CL_LoadModel  @ 001be620
model_s * CL_LoadModel(char *modelname,int *index)

{
  model_s *s2;
  int iVar1;
  model_t *pmVar2;
  int index_00;
  
                    /* Unresolved local var: int i@[???] */
  (*g_engdstAddrs.CL_LoadModel)(&modelname,&index);
                    /* Unresolved local var: model_t * mod@[???] */
  if (cl.model_precache[1] != (model_s *)0x0) {
    s2 = cl.model_precache[1];
    index_00 = 1;
    do {
      iVar1 = Q_stricmp(modelname,s2->name);
      if (iVar1 == 0) {
        pmVar2 = CL_GetModelByIndex(index_00);
        if (index == (int *)0x0) {
          return pmVar2;
        }
        *index = index_00;
        return pmVar2;
      }
      s2 = cl.model_precache[index_00 + 1];
      index_00 = index_00 + 1;
    } while (s2 != (model_s *)0x0);
  }
  if (index == (int *)0x0) {
    return (model_s *)0x0;
  }
  *index = -1;
  return (model_s *)0x0;
}


// CL_LookupSound  @ 00143560
sfx_s * CL_LookupSound(char *pName)

{
  sfx_s *s2;
  int iVar1;
  sfx_t *psVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: sfx_t * pSound@[???] */
  iVar3 = 0;
  do {
    s2 = cl.sound_precache[iVar3];
    if (s2 != (sfx_s *)0x0) {
      iVar1 = Q_strcmp(pName,s2->name);
      if (iVar1 == 0) {
        return s2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x200);
  psVar2 = S_PrecacheSound(pName);
  return psVar2;
}


// CL_MarkMapAsUsingHTTPDownload  @ 00184050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_MarkMapAsUsingHTTPDownload(void)

{
  char **ppcVar1;
  int iVar2;
  char *__s1;
  int iVar3;
  size_t sVar4;
  char *__dest;
  int iVar5;
  char *local_20 [4];
  
                    /* Unresolved local var: char * serverMapName@[???] */
  __s1 = DL_SharedVarArgs("%s:%s",0xe0a50c,0xdf7bf8);
  iVar2 = TheDownloadManager.m_downloadedMaps.m_Size;
  ppcVar1 = TheDownloadManager.m_downloadedMaps.m_Memory.m_pMemory;
  if (__s1 != (char *)0x0) {
                    /* Unresolved local var: int i@[???] */
    if (0 < TheDownloadManager.m_downloadedMaps.m_Size) {
      iVar5 = 0;
      do {
                    /* Unresolved local var: char * oldServerMapName@[???] */
        if ((ppcVar1[iVar5] != (char *)0x0) && (iVar3 = strcasecmp(__s1,ppcVar1[iVar5]), iVar3 == 0)
           ) {
          return;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != iVar2);
    }
                    /* Unresolved local var: char * cloneStr@[???] */
    sVar4 = strlen(__s1);
    __dest = operator_new__(sVar4 + 1);
    strcpy(__dest,__s1);
    local_20[0] = __dest;
    CUtlVector<char*>::InsertBefore
              (&TheDownloadManager.m_downloadedMaps,TheDownloadManager.m_downloadedMaps.m_Size,
               local_20);
  }
  return;
}


// CL_Move  @ 001a2090
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Move(void)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  qboolean qVar8;
  int iVar9;
  uint uVar10;
  qboolean qVar11;
  usercmd_t *puVar12;
  int c;
  int iVar13;
  uint uVar14;
  bool bVar15;
  byte local_880 [2048];
  usercmd_t local_80;
  sizebuf_t local_4c;
  con_nprint_s local_30;
  
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar[2048] data@[???]
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
  if (cls.state < ca_connected) {
    return;
  }
  if (cls.state == ca_connected) {
    if (cls.passive != false) {
      return;
    }
    Netchan_Transmit(&cls.netchan,0,(byte *)0x0);
    return;
  }
  CL_ComputePacketLoss();
  fVar4 = cl_cmdbackup.value;
  local_4c.buffername = "Client Move";
  local_4c.maxsize = 0x800;
  local_4c.cursize = 0;
  local_4c.flags = 0;
  local_4c.data = local_880;
  uVar7 = CL_UPDATE_MASK & cls.netchan.outgoing_sequence;
  puVar12 = &cl.commands[uVar7].cmd;
  cl.commands[uVar7].senttime = (float)realtime;
  cl.commands[uVar7].receivedtime = -1.0;
  cl.commands[uVar7].processedfuncs = false;
  cl.commands[uVar7].heldback = false;
  cl.commands[uVar7].sendsize = 0;
  Q_memset(puVar12,0,0x34);
  bVar15 = cls.signon == 2;
  CL_SetSolidEntities();
  CL_PushPMStates();
  CL_SetSolidPlayers(cl.playernum);
  ClientDLL_CreateMove((float)host_frametime,puVar12,(uint)bVar15);
  CL_PopPMStates();
  CL_ComputeClientInterpolationAmount(puVar12);
  cl.commands[uVar7].cmd.lightlevel = (byte)cl.light_level;
  MSG_WriteByte(&local_4c,2);
  iVar5 = local_4c.cursize;
  MSG_WriteByte(&local_4c,0);
  MSG_WriteByte(&local_4c,0);
  uVar10 = 0;
  if (-1 < (int)cls.packet_loss) {
    uVar10 = (int)cls.packet_loss;
  }
  uVar14 = 100;
  if ((int)uVar10 < 0x65) {
    uVar14 = uVar10;
  }
  qVar8 = Voice_GetLoopback();
  if (qVar8 != 0) {
    uVar14 = uVar14 | 0x80;
  }
  MSG_WriteByte(&local_4c,uVar14 & 0xff);
  iVar9 = (int)((float)host_frametime * 1000.0);
  fVar3 = (float)iVar9;
  fVar2 = ((float)host_frametime * 1000.0 - fVar3) + (float)frametime_remainder;
  if (1.0 < fVar2) {
    fVar2 = fVar2 - 1.0;
    fVar3 = (float)(iVar9 + 1);
  }
  frametime_remainder = (double)fVar2;
  if (255.0 < fVar3) {
    iVar9 = 0xff;
  }
  else {
    iVar9 = (int)fVar3;
  }
  cl.commands[uVar7].cmd.msec = (byte)iVar9;
  uVar10 = 0;
  do {
    *(undefined4 *)((int)cl.cmd.viewangles + (uVar10 - 4)) =
         *(undefined4 *)((int)puVar12->viewangles + (uVar10 - 4));
    uVar10 = uVar10 + 4;
  } while (uVar10 < 0x34);
  if (cls.passive != false) {
    return;
  }
  if (cls.demoplayback != false) {
    return;
  }
  CL_PredictMove(false);
  if (cl_cmdrate.value < 10.0) {
    Cvar_Set("cl_cmdrate","10");
  }
  if (((((cls.spectator != false) && (cls.state == ca_active)) &&
       (cl.delta_sequence == cl.validsequence)) &&
      ((cls.demorecording == false || (cls.demowaiting == false)))) &&
     ((float)realtime < cls.nextcmdtime + 1.0)) {
    return;
  }
  if ((iVar9 < 1) ||
     (((cl.maxclients != 1 &&
       ((cls.netchan.remote_address.type != NA_LOOPBACK || (host_limitlocal.value != 0.0)))) &&
      (((float)realtime < cls.nextcmdtime ||
       (qVar11 = Netchan_CanPacket(&cls.netchan), qVar11 == false)))))) {
    uVar10 = CL_UPDATE_MASK & cls.netchan.outgoing_sequence;
    cls.netchan.outgoing_sequence = cls.netchan.outgoing_sequence + 1;
    cl.commands[uVar10].heldback = true;
    goto LAB_001a236c;
  }
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
    iVar9 = 8;
    if ((int)fVar4 < 9) {
      iVar9 = (int)fVar4;
    }
    iVar13 = 0;
    if (-1 < iVar9) {
      iVar13 = iVar9;
    }
    MSG_WriteByte(&local_4c,iVar13);
    iVar9 = cls.netchan.outgoing_sequence - cls.lastoutgoingcommand;
    if (cls.build_num < 0x1753) {
      c = 0x10;
      if (iVar9 < 0x11) {
        c = iVar9;
      }
    }
    else {
      c = 0x3e - iVar13;
      if (iVar9 < 0x3e - iVar13) {
        c = iVar9;
      }
    }
    iVar13 = c + -1 + iVar13;
    MSG_WriteByte(&local_4c,c);
    Q_memset(&local_80,0,0x34);
    puVar12 = &local_80;
    if (-1 < iVar13) {
      do {
        uVar10 = cls.netchan.outgoing_sequence - iVar13;
        iVar13 = iVar13 + -1;
        uVar10 = uVar10 & CL_UPDATE_MASK;
        MSG_WriteUsercmd(&local_4c,&cl.commands[uVar10].cmd,puVar12);
        puVar12 = &cl.commands[uVar10].cmd;
      } while (iVar13 != -1);
    }
    uVar10 = iVar5 + 1;
    bVar6 = 0xff;
    if ((int)(local_4c.cursize - uVar10) < 0x100) {
      bVar6 = ((char)local_4c.cursize + -1) - (char)uVar10;
    }
    local_4c.data[iVar5] = bVar6;
    pbVar1 = local_4c.data + uVar10;
    bVar6 = COM_BlockSequenceCRCByte
                      (local_4c.data + iVar5 + 2,~uVar10 + local_4c.cursize,
                       cls.netchan.outgoing_sequence);
    *pbVar1 = bVar6;
    iVar9 = 0xff;
    if ((int)(local_4c.cursize - uVar10) < 0x100) {
      iVar9 = (local_4c.cursize - uVar10) + -1;
    }
    COM_Munge(local_4c.data + iVar5 + 2,iVar9,cls.netchan.outgoing_sequence);
  }
  else {
    SZ_Clear(&local_4c);
  }
  if ((((cls.state != ca_active) || (cls.signon != 2)) ||
      (cls.netchan.outgoing_sequence - cls.netchan.incoming_acknowledged < CL_UPDATE_MASK)) ||
     (realtime - (double)cls.netchan.last_received <= 15.0)) {
    if (((cl.validsequence == 0) || (cl_nodelta.value != 0.0)) ||
       ((cls.state != ca_active || ((cls.demorecording != false && (cls.demowaiting != false))))))
    goto LAB_001a2480;
    cl.delta_sequence = cl.validsequence;
    MSG_WriteByte(&local_4c,4);
    MSG_WriteByte(&local_4c,cl.validsequence & 0xff);
  }
  else {
                    /* Unresolved local var: con_nprint_t np@[???] */
    local_30.time_to_live = 1.0;
    local_30.index = 0;
    local_30.color[0] = 1.0;
    local_30.color[1] = 0.2;
    local_30.color[2] = 0.0;
    Con_NXPrintf(&local_30,"WARNING:  Connection Problem");
    cl.validsequence = 0;
LAB_001a2480:
    cl.delta_sequence = -1;
  }
  cls.lastoutgoingcommand = cls.netchan.outgoing_sequence;
  cl.commands[cls.netchan.outgoing_sequence & CL_UPDATE_MASK].sendsize = local_4c.cursize;
  CL_AddVoiceToDatagram(false);
  if (cls.datagram.cursize <= local_4c.maxsize - local_4c.cursize) {
    Q_memcpy(local_4c.data + local_4c.cursize,cls.datagram.data,cls.datagram.cursize);
    local_4c.cursize = local_4c.cursize + cls.datagram.cursize;
  }
  cls.datagram.cursize = 0;
  Netchan_Transmit(&cls.netchan,local_4c.cursize,local_4c.data);
LAB_001a236c:
  Netchan_UpdateProgress(&cls.netchan);
  return;
}


// CL_MoveAiments  @ 0018f160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_MoveAiments(void)

{
  cl_entity_t *pcVar1;
  int iVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = cl_numvisedicts;
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: int i@[???] */
  pcVar3 = cl_entities;
  if (0 < cl_numvisedicts) {
    iVar5 = 0;
    do {
      while( true ) {
        pcVar1 = cl_visedicts[iVar5];
        iVar2 = (pcVar1->curstate).aiment;
        if ((iVar2 == 0) || ((pcVar1->curstate).movetype != 0xc)) break;
        iVar5 = iVar5 + 1;
        pcVar1->origin[0] = pcVar3[iVar2].origin[0];
        pcVar1->origin[1] = pcVar3[iVar2].origin[1];
        pcVar1->origin[2] = pcVar3[iVar2].origin[2];
        if (iVar4 <= iVar5) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  return;
}


// CL_MoveSpectatorCamera  @ 001954f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_MoveSpectatorCamera(void)

{
  uint local_2c;
  double local_1c [3];
  
                    /* Unresolved local var: double time@[???]
                       Unresolved local var: qboolean added@[???] */
  local_1c[0] = cl.time;
  if ((cls.state == ca_active) && (cls.spectator != false)) {
    CL_SetUpPlayerPrediction(false,true);
    CL_SetSolidPlayers(cl.playernum);
    local_2c = (uint)(longlong)ROUND((float)local_1c[0] * 100.0);
    CL_RunUsercmd(&spectatorState,&spectatorState,&cl.cmd,true,local_1c,local_2c);
    cl.simvel[0] = spectatorState.client.velocity[0];
    cl.simvel[1] = spectatorState.client.velocity[1];
    cl.simvel[2] = spectatorState.client.velocity[2];
    cl.simorg[0] = spectatorState.playerstate.origin[0];
    cl.simorg[1] = spectatorState.playerstate.origin[1];
    cl.simorg[2] = spectatorState.playerstate.origin[2];
    cl.punchangle[0] = spectatorState.client.punchangle[0];
    cl.punchangle[1] = spectatorState.client.punchangle[1];
    cl.punchangle[2] = spectatorState.client.punchangle[2];
    cl.viewheight[0] = spectatorState.client.view_ofs[0];
    cl.viewheight[1] = spectatorState.client.view_ofs[1];
    cl.viewheight[2] = spectatorState.client.view_ofs[2];
    return;
  }
  return;
}


// CL_MoveToOnHandList  @ 0019dc50
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


// CL_MsgInfo  @ 001afb80
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
LAB_001afbde:
      return CL_MsgInfo::sz;
    }
    if (pUVar1->iMsg == cmd) {
      Q_strncpy(CL_MsgInfo::sz,pUVar1->szName,0xff);
      CL_MsgInfo::sz[0xff] = '\0';
      goto LAB_001afbde;
    }
    pUVar1 = pUVar1->next;
  } while( true );
}


// CL_ParametricMove  @ 0018b330
qboolean __regparm3 CL_ParametricMove(cl_entity_t_conflict2 *ent)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float dt@[???] */
  local_1c = (ent->curstate).endpos[0] - (ent->curstate).startpos[0];
  local_18 = (ent->curstate).endpos[1] - (ent->curstate).startpos[1];
  local_14 = (ent->curstate).endpos[2] - (ent->curstate).startpos[2];
  fVar3 = (ent->curstate).starttime;
  fVar1 = (ent->curstate).impacttime - fVar3;
  if (fVar1 != 0.0) {
                    /* Unresolved local var: float t@[???] */
    fVar2 = (float)cl.time;
    if (fVar2 < ent->lastmove) {
      fVar2 = ent->lastmove;
    }
    fVar1 = (fVar2 - fVar3) / fVar1;
    fVar3 = 1.0;
    if ((fVar1 <= 1.0) && (fVar3 = 0.0, 0.0 <= fVar1)) {
      fVar3 = fVar1;
    }
    VectorMA((ent->curstate).startpos,fVar3,&local_1c,(ent->curstate).origin);
    ent->lastmove = fVar2;
  }
  ent->origin[0] = (ent->curstate).origin[0];
  ent->origin[1] = (ent->curstate).origin[1];
  ent->origin[2] = (ent->curstate).origin[2];
  VectorNormalize(&local_1c);
  fVar3 = Length(&local_1c);
  if (0.0 < fVar3) {
    VectorAngles(&local_1c,(ent->curstate).angles);
  }
  return true;
}


// CL_ParametricMove  @ 0018b920
qboolean CL_ParametricMove(cl_entity_t_conflict2 *ent)

{
  qboolean qVar1;
  
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float dt@[???] */
  if (((ent->curstate).starttime != 0.0) && ((ent->curstate).impacttime != 0.0)) {
    qVar1 = CL_ParametricMove(ent);
    return qVar1;
  }
  return false;
}


// CL_ParseBaseline  @ 001af040
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
  uint32 uVar8;
  delta_t *pFields;
  qboolean qVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  cl_entity_t *unaff_ESI;
  uchar local_170 [352];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: uchar type@[???]
                       Unresolved local var: entity_state_t nullstate@[???]
                       Unresolved local var: delta_t * * ppentity@[???]
                       Unresolved local var: delta_t * * ppcustom@[???]
                       Unresolved local var: delta_t * * ppplayer@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
  ppdVar4 = DELTA_LookupRegistration("entity_state_t");
  ppdVar5 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar6 = DELTA_LookupRegistration("custom_entity_state_t");
  Q_memset(local_170,0,0x154);
  MSG_StartBitReading(&net_message);
  ContinueLoadingProgressBar("ClientConnect",0xb,0.0);
  SetLoadingProgressBarStatusText("#GameUI_ParseBaseline");
  cl.highentity = 0;
  while (uVar7 = MSG_PeekBits(0x10), uVar7 != 0xffff) {
    uVar7 = MSG_ReadBits(0xb);
    if (cl.highentity <= (int)uVar7) {
      cl.highentity = uVar7;
    }
    if (cl.num_entities <= (int)uVar7) {
      if ((int)uVar7 < cl.max_edicts) goto LAB_001af140;
      Host_Error("CL_EntityNum: %i is an invalid number, cl.max_edicts is %i",uVar7,cl.max_edicts);
      for (; cl.num_entities <= (int)uVar7; cl.num_entities = cl.num_entities + 1) {
LAB_001af140:
        cl_entities[uVar7].index = uVar7;
      }
    }
    cl_entities[uVar7].index = uVar7;
    pcVar2 = cl_entities;
    uVar8 = MSG_ReadBits(2);
    unaff_ESI = pcVar2 + uVar7;
    if ((uVar8 & 2) == 0) {
      qVar9 = CL_IsPlayerIndex(uVar7);
      if (qVar9 == false) {
        pFields = *ppdVar4;
      }
      else {
        pFields = *ppdVar5;
      }
    }
    else {
      pFields = *ppdVar6;
    }
    DELTA_ParseDelta(local_170,(uchar *)&unaff_ESI->baseline,pFields,0x154);
    (unaff_ESI->baseline).entityType = uVar8 & 0xff;
  }
  MSG_ReadBits(0x10);
  Q_memset(cl.instanced_baseline,0,0x5500);
  cl.instanced_baseline_number = MSG_ReadBits(6);
  if (0 < cl.instanced_baseline_number) {
    iVar11 = 0;
    do {
      iVar12 = iVar11 + 1;
      DELTA_ParseDelta(local_170,(uchar *)(cl.instanced_baseline + iVar11),*ppdVar4,0x154);
      iVar11 = iVar12;
    } while (iVar12 < cl.instanced_baseline_number);
  }
  MSG_EndBitReading(&net_message);
  uVar3 = 0;
  do {
    uVar10 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0xc));
    *(undefined4 *)((int)(unaff_ESI->curstate).origin + (uVar10 - 0x10)) =
         *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0x10));
    *(undefined4 *)((int)(unaff_ESI->curstate).origin + (uVar10 - 0xc)) = uVar1;
    uVar3 = uVar10 + 8;
  } while (uVar10 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_ESI->curstate).origin + (uVar10 - 8)) =
       *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 8));
  uVar3 = 0;
  do {
    uVar10 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0xc));
    *(undefined4 *)((int)(unaff_ESI->prevstate).origin + (uVar10 - 0x10)) =
         *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0x10));
    *(undefined4 *)((int)(unaff_ESI->prevstate).origin + (uVar10 - 0xc)) = uVar1;
    uVar3 = uVar10 + 8;
  } while (uVar10 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_ESI->prevstate).origin + (uVar10 - 8)) =
       *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 8));
  return;
}


// CL_ParseBatchModList  @ 0019cf80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseBatchModList(void)

{
  netadr_t a;
  netadr_t to;
  char *pcVar1;
  int iVar2;
  char *str;
  int iVar3;
  char *pcVar4;
  char local_19c [255];
  undefined1 local_9d;
  char local_9c [140];
  
                    /* Unresolved local var: char * pszModName@[???]
                       Unresolved local var: char[256] szName@[???]
                       Unresolved local var: int nPlayers@[???]
                       Unresolved local var: int nServers@[???]
                       Unresolved local var: char * pszServers@[???]
                       Unresolved local var: char * pszPlayers@[???]
                       Unresolved local var: int nCount@[???] */
  pcVar4 = (char *)0x0;
  MSG_ReadByte();
  local_19c[0] = '\0';
LAB_0019cfa0:
  pcVar1 = MSG_ReadString();
  do {
    if (pcVar1 == (char *)0x0) {
      Con_Printf("%i servers\n",pcVar4);
LAB_0019d095:
      Con_Printf("Done.\n",pcVar4);
      return;
    }
    if (((*pcVar1 == '\0') || (iVar2 = Q_stricmp(pcVar1,"end-of-list"), iVar2 == 0)) ||
       (iVar2 = Q_stricmp(pcVar1,"more-in-list"), iVar2 == 0)) {
      Con_Printf("%i servers\n",pcVar4);
      if (*pcVar1 != '\0') {
        pcVar4 = "more-in-list";
        iVar2 = Q_stricmp(pcVar1,"more-in-list");
        if (iVar2 == 0) {
                    /* Unresolved local var: char[128] szRequest@[???] */
          snprintf(local_9c,0x80,"%c\r\n%s\r\n",0x78,local_19c);
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
          pcVar4 = NET_AdrToString(a);
          Con_DPrintf("Requesting next batch ( >%s ) of mods from %s\n",local_19c,pcVar4);
          iVar2 = Q_strlen(local_9c);
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
          NET_SendPacket(NS_CLIENT,iVar2 + 1,local_9c,to);
          return;
        }
      }
      goto LAB_0019d095;
    }
    pcVar4 = pcVar4 + 1;
    Q_strncpy(local_19c,pcVar1,0xff);
    local_9d = 0;
    pcVar1 = MSG_ReadString();
    iVar2 = Q_atoi(pcVar1);
    str = MSG_ReadString();
    iVar3 = Q_atoi(str);
    if ((str == (char *)0x0) || (pcVar1 == (char *)0x0)) goto LAB_0019cfa0;
    Con_Printf("%3i %5i %s\n",iVar2,iVar3,local_19c);
    pcVar1 = MSG_ReadString();
  } while( true );
}


// CL_ParseBatchUserList  @ 0019d190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseBatchUserList(void)

{
  netadr_t a;
  netadr_t to;
  _func_short_short *p_Var1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  char local_b0 [4];
  undefined4 local_ac [31];
  char local_30;
  int aiStack_2f [7];
  
                    /* Unresolved local var: char[128] szAddress@[???]
                       Unresolved local var: uchar[4] cIP@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: ushort iIPPort@[???]
                       Unresolved local var: int nNumAddresses@[???]
                       Unresolved local var: int unique@[???]
                       Unresolved local var: int hash@[???] */
  local_b0[0] = '\0';
  local_b0[1] = '\0';
  local_b0[2] = '\0';
  local_b0[3] = '\0';
  uVar5 = 0;
  do {
    uVar6 = uVar5;
    *(undefined4 *)((int)local_ac + uVar6) = 0;
    *(undefined4 *)((int)local_ac + uVar6 + 4) = 0;
    *(undefined4 *)((int)local_ac + uVar6 + 8) = 0;
    *(undefined4 *)((int)local_ac + uVar6 + 0xc) = 0;
    uVar5 = uVar6 + 0x10;
  } while (uVar6 + 0x10 < 0x70);
  *(undefined4 *)((int)local_ac + uVar6 + 0x10) = 0;
  *(undefined4 *)((int)local_ac + uVar6 + 0x14) = 0;
  *(undefined4 *)((int)local_ac + uVar6 + 0x18) = 0;
  MSG_ReadByte();
  iVar3 = MSG_ReadLong();
  iVar4 = MSG_ReadLong();
  iVar11 = (net_message.cursize - msg_readcount) / 6;
  if (0 < iVar11) {
    iVar11 = iVar11 + -1;
    do {
      iVar11 = iVar11 + -1;
      Q_memset(local_b0,0,0x80);
      uVar5 = MSG_ReadByte();
      uVar6 = MSG_ReadByte();
      uVar7 = MSG_ReadByte();
      uVar8 = MSG_ReadByte();
      snprintf(local_b0,0x80,"%i.%i.%i.%i",uVar5 & 0xff,uVar6 & 0xff,uVar7 & 0xff,uVar8 & 0xff);
      p_Var1 = BigShort;
      iVar9 = MSG_ReadShort();
      sVar2 = (*p_Var1)((short)iVar9);
      Con_Printf("%4i:  %s:%i\n",CL_ParseBatchUserList::count,local_b0,sVar2);
      CL_ParseBatchUserList::count = CL_ParseBatchUserList::count + 1;
    } while (iVar11 != -1);
  }
  if ((iVar3 != 0) && (iVar4 != 0)) {
                    /* Unresolved local var: uchar[20] c@[???]
                       Unresolved local var: int i@[???] */
    Q_strcpy(&local_30,"users");
    iVar11 = Q_strlen("users");
    *(int *)((int)aiStack_2f + iVar11) = iVar3;
    *(int *)((int)aiStack_2f + iVar11 + 4) = iVar4;
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
    pcVar10 = NET_AdrToString(a);
    Con_DPrintf("Requesting next batch ( %i ) user list from %s\n",iVar4,pcVar10);
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
    NET_SendPacket(NS_CLIENT,iVar11 + 9,&local_30,to);
    return;
  }
  Con_Printf("%i users\n",CL_ParseBatchUserList::count);
  CL_ParseBatchUserList::count = 0;
  Con_Printf("Done.\n");
  return;
}


// CL_ParseClientdata  @ 0018c530
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
  clientdata_s *pcd;
  int iVar12;
  uint32 uVar13;
  uint32 uVar14;
  uint uVar15;
  weapon_data_s *pwd;
  uint uVar16;
  local_state_t *pps;
  int iVar17;
  weapon_data_s *wd;
  local_state_t *local_26c;
  uchar local_250 [476];
  uchar local_74 [100];
  
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
  ppdVar10 = DELTA_LookupRegistration("clientdata_t");
  ppdVar11 = DELTA_LookupRegistration("weapon_data_t");
  Q_memset(local_250,0,0x1dc);
  iVar8 = cls.netchan.incoming_acknowledged;
  iVar12 = cls.netchan.incoming_sequence;
  iVar6 = CL_ParseClientdata::last_incoming_sequence;
  iVar5 = CL_UPDATE_MASK;
  uVar15 = CL_ParseClientdata::last_incoming_sequence + 1;
  if ((int)uVar15 < cls.netchan.incoming_sequence) {
    do {
      uVar16 = uVar15 & iVar5;
      if (0.0 <= cl.frames[uVar16].receivedtime) {
        *(undefined4 *)&cl.frames[uVar16].receivedtime = 0;
        *(undefined4 *)((int)&cl.frames[uVar16].receivedtime + 4) = 0xbff00000;
        *(undefined4 *)&cl.frames[uVar16].latency = 0;
        *(undefined4 *)((int)&cl.frames[uVar16].latency + 4) = 0;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 != iVar12);
  }
  uVar15 = iVar5 & iVar12;
  iVar17 = uVar15 * 0x42b8;
  cl.parsecount = iVar12;
  cl.parsecountmod = uVar15;
  cl.frames[uVar15].time = cl.mtime[0];
  dVar2 = realtime;
  fVar1 = cl.commands[iVar8 & iVar5].senttime;
  dVar3 = (double)fVar1;
  parsecounttime = (double)fVar1;
  cl.commands[iVar8 & iVar5].receivedtime = (float)realtime;
  cl.frames[uVar15].receivedtime = dVar2;
  cl.frames[uVar15].clientbytes = 0;
  cl.frames[uVar15].tentitybytes = 0;
  cl.frames[uVar15].soundbytes = 0;
  cl.frames[uVar15].eventbytes = 0;
  cl.frames[uVar15].msgbytes = 0;
  iVar7 = CL_ParseClientdata::last_command_ack;
  cl.frames[uVar15].packetentitybytes = 0;
  cl.frames[uVar15].playerinfobytes = 0;
  cl.frames[uVar15].usrbytes = 0;
  cl.frames[uVar15].voicebytes = 0;
  if (iVar7 != -1) {
                    /* Unresolved local var: int last_predicted@[???]
                       Unresolved local var: entity_state_t.conflict * ps@[???]
                       Unresolved local var: entity_state_t.conflict * pps@[???]
                       Unresolved local var: clientdata_t * pcd@[???]
                       Unresolved local var: clientdata_t * ppcd@[???]
                       Unresolved local var: weapon_data_t * wd@[???]
                       Unresolved local var: weapon_data_t * pwd@[???] */
    if (cls.spectator == false) {
      uVar16 = iVar6 + (iVar8 - iVar7) & iVar5;
      local_26c = (local_state_t *)(iVar17 + 0xc7f6fc + cl.playernum * 0x154);
      pps = cl.predicted_frames + uVar16;
      pcd = &cl.frames[uVar15].clientdata;
      plVar4 = cl.predicted_frames + uVar16;
      pwd = cl.predicted_frames[uVar16].weapondata;
      wd = cl.frames[uVar15].weapondata;
    }
    else {
      pwd = spectatorState.weapondata;
      plVar4 = &spectatorState;
      pps = &spectatorState;
      pcd = &spectatorState.client;
      local_26c = &spectatorState;
      wd = pwd;
    }
    ClientDLL_TxferPredictionData
              ((entity_state_s *)local_26c,(entity_state_s *)pps,pcd,&plVar4->client,wd,pwd);
    iVar12 = cls.netchan.incoming_sequence;
    dVar2 = realtime;
    dVar3 = parsecounttime;
  }
  qVar9 = cls.spectator;
  g_flLatency = dVar2 - dVar3;
  CL_ParseClientdata::last_incoming_sequence = iVar12;
  cl.frames[uVar15].latency = g_flLatency;
  CL_ParseClientdata::last_command_ack = iVar8;
  if (qVar9 == false) {
    to = &cl.frames[uVar15].clientdata;
    MSG_StartBitReading(&net_message);
    uVar13 = MSG_ReadBits(1);
    if (uVar13 == 0) {
                    /* Unresolved local var: int moreweapons@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: weapon_data_t * fdata@[???]
                       Unresolved local var: weapon_data_t * tdata@[???]
                       Unresolved local var: weapon_data_t wbaseline@[???] */
      DELTA_ParseDelta(local_250,(uchar *)to,*ppdVar10,0x1dc);
      Q_memset(local_74,0,0x58);
      while (uVar13 = MSG_ReadBits(1), uVar13 != 0) {
        uVar13 = MSG_ReadBits(6);
        DELTA_ParseDelta(local_74,(uchar *)(iVar17 + 0xc82360 + uVar13 * 0x58),*ppdVar11,0x58);
      }
    }
    else {
      uVar13 = MSG_ReadBits(8);
      DELTA_ParseDelta((uchar *)&cl.frames[CL_UPDATE_MASK & uVar13].clientdata,(uchar *)to,*ppdVar10
                       ,0x1dc);
      Q_memset(local_74,0,0x58);
      while (uVar14 = MSG_ReadBits(1), uVar14 != 0) {
        uVar14 = MSG_ReadBits(6);
        DELTA_ParseDelta((uchar *)(uVar14 * 0x58 + 0xc82360 + (CL_UPDATE_MASK & uVar13) * 0x42b8),
                         (uchar *)(iVar17 + 0xc82360 + uVar14 * 0x58),*ppdVar11,0x58);
      }
    }
    MSG_EndBitReading(&net_message);
    Q_strncpy(cls.physinfo,cl.frames[uVar15].clientdata.physinfo,0xff);
    cls.physinfo[0xff] = '\0';
    cl.stats[0] = (int)cl.frames[uVar15].clientdata.health;
    cl.weapons = cl.frames[uVar15].clientdata.weapons;
    cl.maxspeed = cl.frames[uVar15].clientdata.maxspeed;
    cl.pushmsec = cl.frames[uVar15].clientdata.pushmsec;
    return;
  }
  cl.stats[0] = 1;
  return;
}


// CL_ParseConsistencyInfo  @ 001ad8a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseConsistencyInfo(void)

{
  consistency_t *dest;
  uint32 uVar1;
  uint32 uVar2;
  char *pcVar3;
  uint32 uVar4;
  int iVar5;
  resource_s *__haystack;
  int iVar6;
  resource_s *local_40;
  undefined1 local_3c [44];
  
                    /* Unresolved local var: int lastcheck@[???]
                       Unresolved local var: int delta@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int isdelta@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: resource_t * skip_crc_change@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: qboolean hasinfo@[???]
                       Unresolved local var: consistency_t * pc@[???]
                       Unresolved local var: uchar[32] nullbuffer@[???] */
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_ParseConsistencyInfo()");
  }
  Q_memset(local_3c,0,0x20);
  __haystack = cl.resourcesneeded.pNext;
  uVar1 = MSG_ReadBits(1);
  cl.need_force_consistency_response = (qboolean)(uVar1 != 0);
  if (uVar1 != 0) {
    local_40 = (resource_s *)0x0;
    uVar1 = MSG_ReadBits(1);
    if (uVar1 != 0) {
      uVar1 = 0;
      do {
        uVar2 = MSG_ReadBits(1);
        if (uVar2 == 0) {
          uVar2 = MSG_ReadBits(10);
        }
        else {
          uVar2 = MSG_ReadBits(5);
          uVar2 = uVar2 + uVar1;
        }
        if (0 < (int)(uVar2 - uVar1)) {
          iVar6 = (uVar2 - uVar1) + -1;
          do {
            if ((__haystack != local_40) &&
               (pcVar3 = strstr(__haystack->szFileName,"models/"), pcVar3 != (char *)0x0)) {
              Mod_NeedCRC(__haystack->szFileName,false);
            }
            iVar6 = iVar6 + -1;
            __haystack = __haystack->pNext;
          } while (iVar6 != -1);
        }
        pcVar3 = strstr(__haystack->szFileName,"models/");
        if (pcVar3 != (char *)0x0) {
          Mod_NeedCRC(__haystack->szFileName,true);
        }
        iVar6 = cl.num_consistency;
        if (0x1ff < cl.num_consistency) {
          Host_Error("Consistency:  server sent too many filenames\n");
          return;
        }
        dest = cl.consistency_list + cl.num_consistency;
        cl.num_consistency = cl.num_consistency + 1;
        Q_memset(dest,0,0x2c);
        cl.consistency_list[iVar6].issound = (uint)(__haystack->type == t_sound);
        cl.consistency_list[iVar6].filename = __haystack->szFileName;
        cl.consistency_list[iVar6].orig_index = uVar2;
        cl.consistency_list[iVar6].value = 0;
        if (__haystack->type == t_model) {
          iVar5 = Q_memcmp(local_3c,__haystack->rguc_reserved,0x20);
          if (iVar5 != 0) {
            COM_UnMunge(__haystack->rguc_reserved,0x20,cl.servercount);
            cl.consistency_list[iVar6].check_type = (uint)__haystack->rguc_reserved[0];
          }
        }
        uVar4 = MSG_ReadBits(1);
        uVar1 = uVar2;
        local_40 = __haystack;
      } while (uVar4 != 0);
    }
    if (fs_startup_timings.value != 0.0) {
      AddStartupTiming("end   CL_ParseConsistencyInfo()");
    }
  }
  return;
}


// CL_ParseCustomization  @ 001adf70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseCustomization(void)

{
  resourcetype_t_conflict rVar1;
  customization_s *pRemove;
  bool bVar2;
  uint uVar3;
  resource_s *pResource;
  resourcetype_t rVar4;
  char *src;
  int iVar5;
  uint uVar6;
  qboolean qVar7;
  customization_s *pcVar8;
  
                    /* Unresolved local var: resource_t * resource@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: customization_t * pExistingCustomization@[???]
                       Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
  uVar3 = MSG_ReadByte();
  if (0x1f < uVar3) {
    Host_Error("Bogus player index during customization parsing.\n");
    return;
  }
  pResource = Mem_ZeroMalloc(0x88);
  rVar4 = MSG_ReadByte();
  pResource->type = rVar4;
  src = MSG_ReadString();
  Q_strncpy(pResource->szFileName,src,0x3f);
  pResource->szFileName[0x3f] = '\0';
  iVar5 = MSG_ReadShort();
  pResource->nIndex = iVar5;
  iVar5 = MSG_ReadLong();
  pResource->nDownloadSize = iVar5;
  uVar6 = MSG_ReadByte();
  pResource->pNext = (resource_s *)0x0;
  pResource->pPrev = (resource_s *)0x0;
  pResource->ucFlags = (byte)uVar6 & 0xfd;
  if ((uVar6 & 4) != 0) {
    MSG_ReadBuf(0x10,pResource->rgucMD5_hash);
  }
  bVar2 = cl_allow_download.value == 0.0;
  pResource->playernum = (uchar)uVar3;
  if (bVar2) {
    Con_DPrintf("Refusing new resource, cl_allow_download set to 0\n");
    Mem_Free(pResource);
  }
  else if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
    Con_DPrintf("Refusing new resource, cl_download_ingame set to 0\n");
    Mem_Free(pResource);
  }
  else {
                    /* Unresolved local var: customization_t * pList@[???] */
    bVar2 = false;
    pcVar8 = (customization_s *)cl.players[uVar3 & 0xff].customdata.pNext;
    if (pcVar8 != (customization_t *)0x0) {
      rVar1 = ((resource_t_conflict *)&pcVar8->resource)->type;
      pRemove = pcVar8;
      while (pResource->type != rVar1) {
        pRemove = pRemove->pNext;
        if (pRemove == (customization_s *)0x0) goto LAB_001ae053;
        rVar1 = (pRemove->resource).type;
      }
      CL_RemoveCustomization(uVar3 & 0xff,pRemove);
      pcVar8 = (customization_s *)cl.players[pResource->playernum].customdata.pNext;
      if (pcVar8 != (customization_t *)0x0) {
LAB_001ae053:
        do {
          iVar5 = Q_memcmp(((resource_t_conflict *)&pcVar8->resource)->rgucMD5_hash,
                           pResource->rgucMD5_hash,0x10);
          if (iVar5 == 0) {
            bVar2 = true;
            goto LAB_001ae08f;
          }
          pcVar8 = pcVar8->pNext;
        } while (pcVar8 != (customization_s *)0x0);
      }
      bVar2 = false;
    }
LAB_001ae08f:
    qVar7 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
    if (qVar7 != false) {
      if (bVar2) {
        Con_DPrintf("Duplicate resource ignored for local client\n");
      }
      else {
                    /* Unresolved local var: qboolean bNoError@[???] */
        qVar7 = COM_CreateCustomization
                          ((customization_t *)&cl.players[pResource->playernum].customdata,pResource
                           ,(uint)pResource->playernum,1,(customization_t **)0x0,(int *)0x0);
        if (qVar7 == false) {
          Con_DPrintf("Error loading customization\n");
        }
      }
      Mem_Free(pResource);
      return;
    }
    pResource->ucFlags = pResource->ucFlags | 2;
    if ((pResource->pPrev == (resource_s *)0x0) && (pResource->pNext == (resource_s *)0x0)) {
      if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
         (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
        Sys_Error("Resource list corrupted.\n");
      }
      else {
        pResource->pPrev = cl.resourcesneeded.pPrev;
        (cl.resourcesneeded.pPrev)->pNext = pResource;
        cl.resourcesneeded.pPrev = pResource;
        pResource->pNext = &cl.resourcesneeded;
      }
    }
    else {
      Con_Printf("Resource already linked\n");
    }
    Con_Printf("Requesting %s from server\n",pResource);
    CL_StartResourceDownloading("Custom resource propagation...\n",true);
  }
  return;
}


// CL_ParseDeltaHeader  @ 0018bbb0
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
LAB_0018bc36:
    uVar2 = MSG_ReadBits(1);
    if (uVar2 == 0) {
      uVar2 = MSG_ReadBits(6);
      uVar2 = *numbase + uVar2;
      *numbase = uVar2;
      qVar1 = *remove;
      goto joined_r0x0018bc60;
    }
    uVar2 = MSG_ReadBits(0xb);
  }
  else {
    *remove = false;
    uVar2 = MSG_ReadBits(1);
    if (uVar2 == 0) goto LAB_0018bc36;
    uVar2 = *numbase + 1;
  }
  *numbase = uVar2;
  qVar1 = *remove;
joined_r0x0018bc60:
  if (qVar1 == false) {
    uVar3 = MSG_ReadBits(1);
    *custom = (uint)(uVar3 != 0);
    if (cl.instanced_baseline_number == 0) {
      *newbl = false;
    }
    else {
      uVar3 = MSG_ReadBits(1);
      *newbl = (uint)(uVar3 != 0);
      if ((uVar3 != 0) != false) {
        uVar3 = MSG_ReadBits(6);
        *newblindex = uVar3;
      }
    }
    if ((full == false) || (*newbl != false)) {
      *offset = 0;
    }
    else {
      uVar3 = MSG_ReadBits(1);
      *offset = uVar3;
      if (uVar3 != 0) {
        uVar3 = MSG_ReadBits(6);
        *offset = uVar3;
      }
    }
  }
  return uVar2;
}


// CL_ParseEvent  @ 00191720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseEvent(void)

{
  entity_state_s *peVar1;
  delta_t **ppdVar2;
  uint32 uVar3;
  uint32 index;
  uint32 uVar4;
  int iVar5;
  uint32 uVar6;
  uint32 uVar7;
  float local_c0;
  event_args_t local_ac;
  uchar local_64 [84];
  
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
  ppdVar2 = DELTA_LookupRegistration("event_t");
  Q_memset(local_64,0,0x48);
  Q_memset(&local_ac,0,0x48);
  MSG_StartBitReading(&net_message);
  uVar3 = MSG_ReadBits(5);
  if (0 < (int)uVar3) {
    uVar7 = 0;
    local_c0 = 0.0;
    do {
      uVar6 = 0xffffffff;
      index = MSG_ReadBits(10);
      uVar4 = MSG_ReadBits(1);
      if (uVar4 == 0) {
        uVar4 = MSG_ReadBits(1);
        if (uVar4 != 0) goto LAB_00191890;
LAB_001917bc:
        uVar4 = MSG_ReadBits(1);
      }
      else {
        uVar6 = MSG_ReadBits(0xb);
        uVar4 = MSG_ReadBits(1);
        if (uVar4 == 0) goto LAB_001917bc;
LAB_00191890:
        DELTA_ParseDelta(local_64,(uchar *)&local_ac,*ppdVar2,0x48);
        uVar4 = MSG_ReadBits(1);
      }
      if (uVar4 != 0) {
        uVar4 = MSG_ReadBits(0x10);
        local_c0 = (float)uVar4 / 100.0;
      }
      if (uVar6 != 0xffffffff) {
        if ((int)uVar6 < cl.frames[cl.parsecountmod].packet_entities.num_entities) {
          peVar1 = cl.frames[cl.parsecountmod].packet_entities.entities;
          local_ac.entindex = peVar1[uVar6].number;
          iVar5 = VectorCompare(local_ac.origin,vec3_origin);
          if (iVar5 != 0) {
            local_ac.origin[0] = peVar1[uVar6].origin[0];
            local_ac.origin[1] = peVar1[uVar6].origin[1];
            local_ac.origin[2] = peVar1[uVar6].origin[2];
          }
          iVar5 = VectorCompare(local_ac.angles,vec3_origin);
          if (iVar5 != 0) {
            local_ac.angles[0] = peVar1[uVar6].angles[0];
            local_ac.angles[1] = peVar1[uVar6].angles[1];
            local_ac.angles[2] = peVar1[uVar6].angles[2];
          }
          COM_NormalizeAngles(local_ac.angles);
          if ((0 < peVar1[uVar6].number) && (peVar1[uVar6].number <= cl.maxclients)) {
            local_ac.angles[0] = local_ac.angles[0] * -3.0;
            CL_CalcPlayerVelocity(peVar1[uVar6].number,local_ac.velocity);
            local_ac.ducking = (int)(peVar1[uVar6].usehull == 1);
          }
        }
        else if (local_ac.entindex == 0) {
          Con_DPrintf("CL_ParseEvent:  Received non-packet entity index 0 for event\n");
        }
        else if ((0 < local_ac.entindex) && (local_ac.entindex <= cl.maxclients)) {
          local_ac.angles[0] = local_ac.angles[0] * -3.0;
        }
        CL_QueueEvent(0,index,local_c0,&local_ac);
      }
      uVar7 = uVar7 + 1;
    } while (uVar3 != uVar7);
  }
  MSG_EndBitReading(&net_message);
  return;
}


// CL_ParseFileTxferFailed  @ 00191f10
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
  Host_Error("CL_ParseFileTxferFailed:  empty filename\n");
  return;
}


// CL_ParseHLTV  @ 001b05f0
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


// CL_ParseListen  @ 001aefd0
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


// CL_ParseMovevars  @ 001af450
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


// CL_ParsePacketEntities  @ 0018c980
void CL_ParsePacketEntities(qboolean delta,int *playerbits)

{
  byte *pbVar1;
  entity_state_s *peVar2;
  undefined4 uVar3;
  int iVar4;
  delta_t **ppdVar5;
  delta_t **ppdVar6;
  delta_t **ppdVar7;
  int iVar8;
  int iVar9;
  entity_state_s *peVar10;
  uint32 uVar11;
  int iVar12;
  model_s *pmVar13;
  delta_t **ppdVar14;
  uint uVar15;
  packet_entities_t *dest;
  uint32 deadEntity;
  delta_t *pFields;
  int local_c4;
  int local_b8;
  qboolean local_b4;
  packet_entities_t local_94;
  qboolean local_6c [4];
  qboolean local_5c [4];
  qboolean local_4c [4];
  int local_3c [4];
  int local_2c [3];
  int local_20 [4];
  
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
                       Unresolved local var: uchar from@[???]
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
  local_3c[0] = 0;
  local_6c[0] = false;
  local_5c[0] = false;
  local_4c[0] = false;
  local_20[0] = 0;
  ppdVar5 = DELTA_LookupRegistration("entity_state_t");
  ppdVar6 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar7 = DELTA_LookupRegistration("custom_entity_state_t");
  if (cls.signon == 1) {
    cls.signon = 2;
    CL_SignonReply();
  }
  iVar4 = cl.parsecountmod;
  iVar8 = cl.parsecountmod * 0x42b8;
  cl.frames[cl.parsecountmod].invalid = false;
  iVar9 = MSG_ReadShort();
  iVar12 = 1;
  if (0 < iVar9) {
    iVar12 = iVar9;
  }
  peVar10 = cl.frames[iVar4].packet_entities.entities;
  if (peVar10 != (entity_state_s *)0x0) {
    Mem_Free(peVar10);
  }
  peVar10 = Mem_ZeroMalloc(iVar12 * 0x154);
  cl.frames[iVar4].packet_entities.entities = peVar10;
  cl.frames[iVar4].packet_entities.num_entities = iVar9;
  Q_memset(cl.frames[iVar4].packet_entities.flags,0,0x20);
  if (delta == false) {
    uVar15 = 0xffffffff;
    if (cls.demowaiting != false) {
      cls.demowaiting = false;
      MSG_WriteChar(&cls.netchan.message,3);
      MSG_WriteString(&cls.netchan.message,"fullupdate");
    }
  }
  else {
    uVar15 = MSG_ReadByte();
    uVar15 = uVar15 & 0xff;
  }
  if (cl.max_edicts == 0) {
    CL_FlushEntityPacket(true);
    peVar10 = cl.frames[iVar4].packet_entities.entities;
    if (peVar10 != (entity_state_s *)0x0) {
      Mem_Free(peVar10);
    }
    cl.frames[iVar4].packet_entities.entities = (entity_state_s *)0x0;
    cl.frames[iVar4].packet_entities.num_entities = 0;
    return;
  }
  if (uVar15 == 0xffffffff) {
    dest = &local_94;
    Q_memset(dest,0,0x28);
    local_94.num_entities = 0;
    local_b4 = true;
  }
  else {
    if (CL_UPDATE_MASK <= (int)(cls.netchan.incoming_sequence - uVar15 & 0xff)) {
      CL_FlushEntityPacket(true);
      peVar10 = cl.frames[iVar4].packet_entities.entities;
      if (peVar10 != (entity_state_s *)0x0) {
        Mem_Free(peVar10);
      }
      cl.frames[iVar4].packet_entities.entities = (entity_state_s *)0x0;
      cl.frames[iVar4].packet_entities.num_entities = 0;
      return;
    }
    local_b4 = false;
    dest = &cl.frames[uVar15 & CL_UPDATE_MASK].packet_entities;
  }
  cl.validsequence = cls.netchan.incoming_sequence;
  MSG_StartBitReading(&net_message);
  local_c4 = 0;
  local_b8 = 0;
LAB_0018cb00:
  do {
    uVar11 = MSG_PeekBits(0x10);
    if (uVar11 == 0) {
      uVar11 = MSG_ReadBits(0x10);
    }
    else {
      uVar11 = CL_ParseDeltaHeader(local_6c,local_5c,local_20,local_4c,local_3c,local_b4,local_2c);
    }
    if (uVar11 == 0) {
      if (local_b8 < dest->num_entities) {
        iVar8 = local_b8 - local_c4;
        iVar12 = local_c4 * 0x154;
        do {
          if (0xff < local_c4) {
            Host_EndGame("CL_ParsePacketEntities: newindex == MAX_PACKET_ENTITIES");
          }
          peVar10 = dest->entities;
          peVar2 = cl.frames[iVar4].packet_entities.entities;
          uVar15 = 0;
          do {
            uVar3 = *(undefined4 *)((int)peVar10[iVar8].origin + uVar15 + iVar12 + -0x10);
            *(undefined4 *)((int)peVar2->origin + uVar15 + iVar12 + -0xc) =
                 *(undefined4 *)((int)peVar10[iVar8].origin + uVar15 + iVar12 + -0xc);
            *(undefined4 *)((int)peVar2->origin + uVar15 + iVar12 + -0x10) = uVar3;
            uVar15 = uVar15 + 8;
          } while (uVar15 < 0x150);
          local_b8 = local_b8 + 1;
          local_c4 = local_c4 + 1;
          *(undefined4 *)((int)peVar2->origin + uVar15 + iVar12 + -0x10) =
               *(undefined4 *)((int)peVar10[iVar8].origin + uVar15 + iVar12 + -0x10);
          iVar12 = iVar12 + 0x154;
        } while (local_b8 < dest->num_entities);
      }
      goto LAB_0018cc5f;
    }
    deadEntity = 9999;
    if (local_b8 < dest->num_entities) {
      deadEntity = dest->entities[local_b8].number;
    }
    if ((int)deadEntity < (int)uVar11) {
      if (local_b4 != false) {
        Con_Printf("WARNING: oldcopy invalid on non-delta compressed update\n");
        CL_FlushEntityPacket(false);
        peVar10 = cl.frames[iVar4].packet_entities.entities;
        if (peVar10 != (entity_state_s *)0x0) {
          Mem_Free(peVar10);
        }
        cl.frames[iVar4].packet_entities.entities = (entity_state_s *)0x0;
        cl.frames[iVar4].packet_entities.num_entities = 0;
        goto LAB_0018cb00;
      }
      iVar9 = local_b8 * 0x154;
      iVar12 = local_c4 - local_b8;
      do {
        if (0xff < local_c4) {
          Host_EndGame("CL_ParsePacketEntities: newindex == MAX_PACKET_ENTITIES");
        }
        uVar15 = 0;
        peVar10 = cl.frames[iVar4].packet_entities.entities;
        peVar2 = dest->entities;
        do {
          uVar3 = *(undefined4 *)((int)peVar2->origin + uVar15 + iVar9 + -0x10);
          *(undefined4 *)((int)peVar10[iVar12].origin + uVar15 + iVar9 + -0xc) =
               *(undefined4 *)((int)peVar2->origin + uVar15 + iVar9 + -0xc);
          *(undefined4 *)((int)peVar10[iVar12].origin + uVar15 + iVar9 + -0x10) = uVar3;
          uVar15 = uVar15 + 8;
        } while (uVar15 < 0x150);
        deadEntity = 9999;
        local_b8 = local_b8 + 1;
        local_c4 = local_c4 + 1;
        *(undefined4 *)((int)peVar10[iVar12].origin + uVar15 + iVar9 + -0x10) =
             *(undefined4 *)((int)peVar2->origin + uVar15 + iVar9 + -0x10);
        if (local_b8 < dest->num_entities) {
          deadEntity = *(uint32 *)((int)dest->entities[1].origin + iVar9 + -0xc);
        }
        iVar9 = iVar9 + 0x154;
      } while ((int)deadEntity < (int)uVar11);
    }
    if ((int)uVar11 < (int)deadEntity) {
                    /* Unresolved local var: entity_state_t.conflict * baseline@[???] */
      if (local_6c[0] == false) {
        if (0xff < local_c4) {
          Host_EndGame("CL_ParsePacketEntities: newindex == MAX_PACKET_ENTITIES");
        }
        if (local_4c[0] == false) {
          if (local_2c[0] == 0) {
            peVar10 = &cl_entities[uVar11].baseline;
          }
          else {
            peVar10 = cl.frames[iVar4].packet_entities.entities + (local_c4 - local_2c[0]);
          }
        }
        else {
          peVar10 = cl.instanced_baseline + local_3c[0];
        }
        CL_EntityNum(uVar11);
        if (local_5c[0] == false) {
          if ((int)uVar11 < 1) {
            DELTA_ParseDelta((uchar *)peVar10,
                             (uchar *)(cl.frames[iVar4].packet_entities.entities + local_c4),
                             *ppdVar5,0x154);
            cl.frames[iVar4].packet_entities.entities[local_c4].entityType = 1;
          }
          else {
            ppdVar14 = ppdVar6;
            if (cl.maxclients < (int)uVar11) {
              ppdVar14 = ppdVar5;
            }
            iVar12 = DELTA_ParseDelta((uchar *)peVar10,
                                      (uchar *)(cl.frames[iVar4].packet_entities.entities + local_c4
                                               ),*ppdVar14,0x154);
            cl.frames[iVar4].packet_entities.entities[local_c4].entityType = 1;
            if (((int)uVar11 <= cl.maxclients) && (playerbits != (int *)0x0)) {
              *playerbits = *playerbits + iVar12;
            }
          }
        }
        else {
          DELTA_ParseDelta((uchar *)peVar10,
                           (uchar *)(cl.frames[iVar4].packet_entities.entities + local_c4),*ppdVar7,
                           0x154);
          cl.frames[iVar4].packet_entities.entities[local_c4].entityType = 2;
        }
        cl.frames[iVar4].packet_entities.entities[local_c4].number = uVar11;
        if (((cl_needinstanced.value != 0.0) && (cl.highentity < (int)uVar11)) &&
           (local_4c[0] == false)) {
          iVar12 = cl.frames[iVar4].packet_entities.entities[local_c4].modelindex;
          pmVar13 = (model_s *)&DAT_0027be06;
          if (iVar12 != 0) {
            pmVar13 = cl.model_precache[iVar12];
          }
          Con_DPrintf("Non-instanced %i %s without baseline\n",uVar11,pmVar13);
        }
        if ((local_b4 == false) || (cls.passive == false)) {
          pbVar1 = (byte *)(iVar8 + 0xc83964 + (local_c4 >> 3));
          *pbVar1 = *pbVar1 | (byte)(1 << ((byte)local_c4 & 7));
        }
        local_c4 = local_c4 + 1;
      }
      else if (local_b4 != false) {
        Con_Printf("WARNING: remove invalid on non-delta compressed update\n");
        CL_FlushEntityPacket(false);
        peVar10 = cl.frames[iVar4].packet_entities.entities;
        if (peVar10 != (entity_state_s *)0x0) {
          Mem_Free(peVar10);
        }
        cl.frames[iVar4].packet_entities.entities = (entity_state_s *)0x0;
        cl.frames[iVar4].packet_entities.num_entities = 0;
LAB_0018cc5f:
        MSG_EndBitReading(&net_message);
        if (msg_badread != false) {
          Host_EndGame("msg_badread in packetentities\n");
          return;
        }
        CL_ProcessPacket(cl.frames + iVar4);
        return;
      }
    }
    else if (uVar11 == deadEntity) {
      if (local_b4 != false) {
        cl.validsequence = 0;
        Con_Printf("WARNING: delta on full update");
      }
      if (local_6c[0] == false) {
        if (local_5c[0] == false) {
          if ((int)uVar11 < 1) {
            DELTA_ParseDelta((uchar *)(dest->entities + local_b8),
                             (uchar *)(cl.frames[iVar4].packet_entities.entities + local_c4),
                             *ppdVar5,0x154);
            cl.frames[iVar4].packet_entities.entities[local_c4].entityType = 1;
          }
          else {
            if (cl.maxclients < (int)uVar11) {
              pFields = *ppdVar5;
              peVar10 = cl.frames[iVar4].packet_entities.entities;
            }
            else {
              pFields = *ppdVar6;
              peVar10 = cl.frames[iVar4].packet_entities.entities;
            }
            iVar12 = DELTA_ParseDelta((uchar *)(dest->entities + local_b8),
                                      (uchar *)(peVar10 + local_c4),pFields,0x154);
            cl.frames[iVar4].packet_entities.entities[local_c4].entityType = 1;
            if (((int)uVar11 <= cl.maxclients) && (playerbits != (int *)0x0)) {
              *playerbits = *playerbits + iVar12;
            }
          }
        }
        else {
          DELTA_ParseDelta((uchar *)(dest->entities + local_b8),
                           (uchar *)(cl.frames[iVar4].packet_entities.entities + local_c4),*ppdVar7,
                           0x154);
          cl.frames[iVar4].packet_entities.entities[local_c4].entityType = 2;
        }
        local_b8 = local_b8 + 1;
        cl.frames[iVar4].packet_entities.entities[local_c4].number = uVar11;
        local_c4 = local_c4 + 1;
      }
      else {
        R_KillDeadBeams(deadEntity);
        local_b8 = local_b8 + 1;
      }
    }
  } while( true );
}


// CL_ParseResourceList  @ 001adae0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseResourceList(void)

{
  uint32 uVar1;
  resource_s *dest;
  resourcetype_t rVar2;
  char *src;
  uint32 uVar3;
  uint32 uVar4;
  
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * resource@[???] */
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_ParseResourceList()");
  }
  MSG_StartBitReading(&net_message);
  uVar1 = MSG_ReadBits(0xc);
  if (0 < (int)uVar1) {
    uVar4 = 0;
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
        if ((dest->pPrev == (resource_s *)0x0) && (dest->pNext == (resource_s *)0x0)) break;
        Con_Printf("Resource already linked\n");
LAB_001adb34:
        uVar4 = uVar4 + 1;
        if (uVar1 == uVar4) goto LAB_001adc30;
      }
      if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
         (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
        Sys_Error("Resource list corrupted.\n");
        goto LAB_001adb34;
      }
      dest->pPrev = cl.resourcesneeded.pPrev;
      uVar4 = uVar4 + 1;
      (cl.resourcesneeded.pPrev)->pNext = dest;
      cl.resourcesneeded.pPrev = dest;
      dest->pNext = &cl.resourcesneeded;
    } while (uVar1 != uVar4);
  }
LAB_001adc30:
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_ParseResourceList()");
  }
  CL_ParseConsistencyInfo();
  MSG_EndBitReading(&net_message);
  SetLoadingProgressBarStatusText("#GameUI_VerifyingResources");
  CL_StartResourceDownloading("Verifying and downloading resources...\n",false);
  return;
}


// CL_ParseResourceLocation  @ 001add10
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
      snprintf(cl.downloadUrl,0x80,"%s/",__s2);
    }
    else {
      strncpy(cl.downloadUrl,__s2,0x80);
      cl.downloadUrl[0x7f] = '\0';
    }
    Con_DPrintf("Using %s as primary download location\n",0xe03d28);
  }
  return;
}


// CL_ParseServerInfo  @ 001ae820
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseServerInfo(void)

{
  netadr_t addr;
  int iVar1;
  int iVar2;
  qboolean qVar3;
  char *pcVar4;
  BOOL BVar5;
  float value;
  int iVar6;
  char local_1110 [4096];
  char local_110 [264];
  
                    /* Unresolved local var: char * str@[???]
                       Unresolved local var: char * gamedir@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int mungebuffer@[???]
                       Unresolved local var: char[4096] mapBaseName@[???] */
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
  if ((iVar2 != 0x30) && (cls.demoplayback == false)) {
    Con_Printf("Server returned version %i, not %i\n",iVar2,0x30);
    return;
  }
  cl.servercount = MSG_ReadLong();
  if (cls.demoplayback != false) {
    gHostSpawnCount = gHostSpawnCount + 1;
    cl.servercount = gHostSpawnCount;
  }
  cl.serverCRC = MSG_ReadLong();
  MSG_ReadBuf(0x10,cl.clientdllmd5);
  cl.maxclients = MSG_ReadByte();
  if (0x1f < cl.maxclients - 1U) {
    Con_Printf("Bad maxclients (%u) from server\n",cl.maxclients);
    return;
  }
  value = sp_decals.value;
  if (cl.maxclients != 1) {
    value = mp_decals.value;
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
    Sys_Error("CL_ReallocateDynamicData allocating 0 entities");
  }
  if (cl_entities != (cl_entity_t *)0x0) {
    Con_Printf("CL_Reallocate cl_entities\n");
  }
  cl_entities = Mem_ZeroMalloc(cl.max_edicts * 3000);
  R_AllocObjects(cl.max_edicts);
  Q_memset(cl.frames,0,CL_UPDATE_BACKUP * 0x42b8);
  cl.playernum = MSG_ReadByte();
  COM_UnMunge3((uchar *)&cl.serverCRC,4,0xffU - cl.playernum & 0xff);
  iVar2 = 0;
  do {
    iVar6 = iVar2 + 1;
    COM_ClearCustomizationList((customization_t *)&cl.players[iVar2].customdata,true);
    iVar1 = cl.playernum;
    iVar2 = iVar6;
  } while (iVar6 != 0x20);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: player_info_t * pPlayer@[???] */
  cl.players[cl.playernum].customdata.pNext = (customization_s_conflict *)0x0;
  if (0 < cl.num_resources) {
    iVar2 = 0;
    do {
      while (qVar3 = COM_CreateCustomization
                               ((customization_t *)&cl.players[iVar1].customdata,
                                cl.resourcelist + iVar2,cl.playernum,0,(customization_t **)0x0,
                                (int *)0x0), qVar3 != false) {
        iVar2 = iVar2 + 1;
        if (cl.num_resources <= iVar2) goto LAB_001aeab1;
      }
      iVar6 = iVar2 + 1;
      Con_DPrintf("Problem with client customization %i, ignoring...",iVar2);
      iVar2 = iVar6;
    } while (iVar6 < cl.num_resources);
  }
LAB_001aeab1:
  cl.gametype = MSG_ReadByte();
  pcVar4 = MSG_ReadString();
                    /* Unresolved local var: char[260] szGD@[???] */
  if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
    Con_Printf("Server didn\'t specify a gamedir, assuming no change\n");
  }
  else {
    COM_FileBase(com_gamedir,local_110);
    iVar2 = Q_stricmp(local_110,pcVar4);
    if (iVar2 != 0) {
      Con_Printf("Server is running game %s.  Restart in that game to connect.\n",pcVar4);
      CL_Disconnect_f();
      return;
    }
  }
  pcVar4 = MSG_ReadString();
  Con_DPrintf("Remote host:  %s\n",pcVar4);
  pcVar4 = MSG_ReadString();
  Q_strncpy(cl.levelname,pcVar4,0x27);
  cl.levelname[0x27] = '\0';
  MSG_SkipString();
  COM_FileBase(cl.levelname,local_1110);
  if (1 < cl.maxclients) {
                    /* Unresolved local var: char * mapcycle@[???] */
    FS_LogLevelLoadStarted(local_1110);
    VGuiWrap2_LoadingStarted("level",local_1110);
  }
  cls.isVAC2Secure = MSG_ReadByte();
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_CheckCRCs()");
  }
  ContinueLoadingProgressBar("ClientConnect",4,0.0);
  SetLoadingProgressBarStatusText("#GameUI_CheckCRCs");
  qVar3 = Host_IsServerActive();
  if (qVar3 == false) {
    CRC32_Init(&cl.mapCRC);
    iVar2 = CRC_MapFile(&cl.mapCRC,cl.levelname);
    if (iVar2 == 0) {
      iVar2 = FS_FileExists(cl.levelname);
      if (iVar2 != 0) {
        COM_ExplainDisconnection(true,"#GameUI_ConnectionFailed",0xdf7bf8);
        Host_Error("Disconnected");
        return;
      }
      if (cl_allow_download.value == 0.0) {
        COM_ExplainDisconnection
                  (true,"Refusing to download map %s, (cl_allow_download is 0 ) disconnecting.\n",
                   0xdf7bf8);
        Host_Error("Disconnected");
        return;
      }
      Con_Printf("Couldn\'t find map %s, server will download the map\n",0xdf7bf8);
      cl.mapCRC = cl.serverCRC;
    }
    else if ((cl.mapCRC != cl.serverCRC) && (cls.demoplayback == false)) {
      COM_ExplainDisconnection(true,"Your map [%s] differs from the server\'s.",0xdf7bf8);
      Host_Error("Disconnected");
      return;
    }
  }
  if (gmodinfo.clientcrccheck != false) {
                    /* Unresolved local var: char[64] szDllName@[???] */
    snprintf(local_110,0x40,"cl_dlls//client.dll");
    BVar5 = MD5_Hash_File(cls.md5_clientdll,local_110,0,0,(uint *)0x0);
    if (BVar5 == 0) {
      COM_ExplainDisconnection(true,"Couldn\'t CRC client side dll %s.",local_110);
      Host_Error("Disconnected");
      return;
    }
    iVar2 = Q_memcmp(cl.clientdllmd5,cls.md5_clientdll,0x10);
    if (iVar2 != 0) {
      if ((cls.demoplayback == false) && (cls.spectator == false)) {
        COM_ExplainDisconnection(true,"Your .dll [%s] differs from the server\'s.",local_110);
        Host_Error("Disconnected");
        return;
      }
      Con_Printf("Your client side .dll [%s] failed the CRC check.\nThe .dll may be out of date, or the demo may have been recorded using an old version of the .dll.\nConsider obtaining an updated version of the .dll from the server operator.\nDemo playback proceeding.\n"
                 ,local_110);
    }
  }
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_CheckCRCs()");
  }
                    /* Unresolved local var: char[20] szSendres@[???] */
  gHostSpawnCount = cl.servercount;
  cls.state = ca_connected;
  CL_BeginDemoStartup();
  SetSecondaryProgressBar(100.0);
  builtin_strncpy(local_110,"sendres",8);
  MSG_WriteByte(&cls.netchan.message,3);
  MSG_WriteString(&cls.netchan.message,local_110);
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_ParseServerInfo()");
  }
  return;
}


// CL_ParseServerList  @ 0019ce20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseServerList(void)

{
  _func_short_short *p_Var1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char local_9c [4];
  undefined4 local_98 [34];
  
                    /* Unresolved local var: char[128] szAddress@[???]
                       Unresolved local var: uchar[4] cIP@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: ushort iIPPort@[???]
                       Unresolved local var: int nNumAddresses@[???]
                       Unresolved local var: int count@[???] */
  local_9c[0] = '\0';
  local_9c[1] = '\0';
  local_9c[2] = '\0';
  local_9c[3] = '\0';
  uVar3 = 0;
  do {
    uVar4 = uVar3;
    *(undefined4 *)((int)local_98 + uVar4) = 0;
    *(undefined4 *)((int)local_98 + uVar4 + 4) = 0;
    *(undefined4 *)((int)local_98 + uVar4 + 8) = 0;
    *(undefined4 *)((int)local_98 + uVar4 + 0xc) = 0;
    uVar3 = uVar4 + 0x10;
  } while (uVar4 + 0x10 < 0x70);
  iVar8 = 1;
  *(undefined4 *)((int)local_98 + uVar4 + 0x10) = 0;
  *(undefined4 *)((int)local_98 + uVar4 + 0x14) = 0;
  *(undefined4 *)((int)local_98 + uVar4 + 0x18) = 0;
  MSG_ReadByte();
  iVar7 = (net_message.cursize + -6) / 6;
  if (0 < iVar7) {
    iVar7 = iVar7 + 1;
    iVar9 = iVar8;
    do {
      while( true ) {
        Q_memset(local_9c,0,0x80);
        uVar3 = MSG_ReadByte();
        uVar4 = MSG_ReadByte();
        uVar5 = MSG_ReadByte();
        uVar6 = MSG_ReadByte();
        snprintf(local_9c,0x80,"%i.%i.%i.%i",uVar3 & 0xff,uVar4 & 0xff,uVar5 & 0xff,uVar6 & 0xff);
        p_Var1 = BigShort;
        iVar8 = MSG_ReadShort();
        sVar2 = (*p_Var1)((short)iVar8);
        if (100 < iVar9) break;
        iVar8 = iVar9 + 1;
        Con_Printf("%4i:  %s:%i\n",iVar9,local_9c,sVar2);
        iVar9 = iVar8;
        if (iVar8 == iVar7) goto LAB_0019cf64;
      }
      iVar8 = iVar9 + 1;
      iVar9 = iVar8;
    } while (iVar8 != iVar7);
  }
LAB_0019cf64:
  Con_Printf("%i total servers\n",iVar8);
  return;
}


// CL_ParseServerMessage  @ 001aff10
void CL_ParseServerMessage(qboolean normal_message)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  code *pcVar5;
  char *str;
  short sVar6;
  short sVar7;
  short sVar8;
  cactive_t cVar9;
  int start;
  double dVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  
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
  pcVar15 = (char *)0x0;
  Q_memset(last_data,0,0x100);
  dVar10 = realtime;
  if (normal_message != false) {
    uVar11 = CL_UPDATE_MASK & cls.netchan.incoming_sequence;
    if (cls.state == ca_active) {
      cl.frames[uVar11].invalid = true;
      cl.frames[uVar11].choked = false;
    }
    else {
      cl.frames[uVar11].clientbytes = 0;
      cl.frames[uVar11].packetentitybytes = 0;
      cl.frames[uVar11].tentitybytes = 0;
      cl.frames[uVar11].receivedtime = dVar10;
      cl.frames[uVar11].invalid = false;
      cl.frames[uVar11].choked = false;
      *(undefined4 *)&cl.frames[uVar11].latency = 0;
      *(undefined4 *)((int)&cl.frames[uVar11].latency + 4) = 0;
      cl.frames[uVar11].playerinfobytes = 0;
      cl.frames[uVar11].soundbytes = 0;
      cl.frames[uVar11].usrbytes = 0;
      cl.frames[uVar11].eventbytes = 0;
      cl.frames[uVar11].msgbytes = 0;
      cl.frames[uVar11].time = cl.mtime[0];
    }
  }
  do {
    while( true ) {
      if (msg_badread != false) {
        Host_Error("CL_ParseServerMessage: Bad server message",pcVar15);
      }
      iVar13 = msg_readcount;
      uVar11 = MSG_ReadByte();
      if (uVar11 == 0xffffffff) {
        cVar9 = cls.state;
        if ((cl_shownet.value == 2.0) &&
           (iVar13 = Q_strlen("END OF MESSAGE"), cVar9 = cls.state, 1 < iVar13)) {
          Con_Printf("%3i:%s\n",msg_readcount + -1,"END OF MESSAGE");
          cVar9 = cls.state;
        }
        cls.state = cVar9;
        if (cVar9 == ca_active) {
          cl.frames[cl.parsecountmod].msgbytes =
               (short)*(undefined4 *)&cl.frames[cl.parsecountmod].msgbytes +
               (short)net_message.cursize;
        }
        total_data[0] = total_data[0] + last_data[0];
        total_data[1] = total_data[1] + last_data[1];
        total_data[2] = total_data[2] + last_data[2];
        total_data[3] = total_data[3] + last_data[3];
        total_data[4] = total_data[4] + last_data[4];
        total_data[5] = total_data[5] + last_data[5];
        total_data[6] = total_data[6] + last_data[6];
        total_data[7] = total_data[7] + last_data[7];
        total_data[8] = total_data[8] + last_data[8];
        total_data[9] = total_data[9] + last_data[9];
        total_data[10] = total_data[10] + last_data[10];
        total_data[0xb] = total_data[0xb] + last_data[0xb];
        total_data[0xc] = total_data[0xc] + last_data[0xc];
        total_data[0xd] = total_data[0xd] + last_data[0xd];
        total_data[0xe] = total_data[0xe] + last_data[0xe];
        total_data[0xf] = total_data[0xf] + last_data[0xf];
        total_data[0x10] = total_data[0x10] + last_data[0x10];
        total_data[0x11] = total_data[0x11] + last_data[0x11];
        total_data[0x12] = total_data[0x12] + last_data[0x12];
        total_data[0x13] = total_data[0x13] + last_data[0x13];
        total_data[0x14] = total_data[0x14] + last_data[0x14];
        total_data[0x15] = total_data[0x15] + last_data[0x15];
        total_data[0x16] = total_data[0x16] + last_data[0x16];
        total_data[0x17] = total_data[0x17] + last_data[0x17];
        total_data[0x18] = total_data[0x18] + last_data[0x18];
        total_data[0x19] = total_data[0x19] + last_data[0x19];
        total_data[0x1a] = total_data[0x1a] + last_data[0x1a];
        total_data[0x1b] = total_data[0x1b] + last_data[0x1b];
        total_data[0x1c] = total_data[0x1c] + last_data[0x1c];
        total_data[0x1d] = total_data[0x1d] + last_data[0x1d];
        total_data[0x1e] = total_data[0x1e] + last_data[0x1e];
        total_data[0x1f] = total_data[0x1f] + last_data[0x1f];
        total_data[0x20] = total_data[0x20] + last_data[0x20];
        total_data[0x21] = total_data[0x21] + last_data[0x21];
        total_data[0x22] = total_data[0x22] + last_data[0x22];
        total_data[0x23] = total_data[0x23] + last_data[0x23];
        total_data[0x24] = total_data[0x24] + last_data[0x24];
        total_data[0x25] = total_data[0x25] + last_data[0x25];
        total_data[0x26] = total_data[0x26] + last_data[0x26];
        total_data[0x27] = total_data[0x27] + last_data[0x27];
        total_data[0x28] = total_data[0x28] + last_data[0x28];
        total_data[0x29] = total_data[0x29] + last_data[0x29];
        total_data[0x2a] = total_data[0x2a] + last_data[0x2a];
        total_data[0x2b] = total_data[0x2b] + last_data[0x2b];
        total_data[0x2c] = total_data[0x2c] + last_data[0x2c];
        total_data[0x2d] = total_data[0x2d] + last_data[0x2d];
        total_data[0x2e] = total_data[0x2e] + last_data[0x2e];
        total_data[0x2f] = total_data[0x2f] + last_data[0x2f];
        total_data[0x30] = total_data[0x30] + last_data[0x30];
        total_data[0x31] = total_data[0x31] + last_data[0x31];
        total_data[0x32] = total_data[0x32] + last_data[0x32];
        total_data[0x33] = total_data[0x33] + last_data[0x33];
        total_data[0x34] = total_data[0x34] + last_data[0x34];
        total_data[0x35] = total_data[0x35] + last_data[0x35];
        total_data[0x36] = total_data[0x36] + last_data[0x36];
        total_data[0x37] = total_data[0x37] + last_data[0x37];
        total_data[0x38] = total_data[0x38] + last_data[0x38];
        total_data[0x39] = total_data[0x39] + last_data[0x39];
        total_data[0x3a] = total_data[0x3a] + last_data[0x3a];
        total_data[0x3b] = total_data[0x3b] + last_data[0x3b];
        total_data[0x3c] = total_data[0x3c] + last_data[0x3c];
        total_data[0x3d] = total_data[0x3d] + last_data[0x3d];
        total_data[0x3e] = total_data[0x3e] + last_data[0x3e];
        total_data[0x3f] = total_data[0x3f] + last_data[0x3f];
        if (cls.demoplayback == false) {
          if (cVar9 != ca_active) {
            CL_WriteDemoStartup(start,&net_message);
          }
          if ((cls.demorecording != false) && (cls.demowaiting == false)) {
            CL_WriteDemoMessage(start,&net_message);
            return;
          }
        }
        return;
      }
      sVar7 = (short)iVar13;
      if (uVar11 != 1) break;
LAB_001b0082:
      if (cl_shownet.value == 2.0) {
        str = cl_parsefuncs[uVar11].pszname;
        iVar12 = Q_strlen(str);
        if (1 < iVar12) {
          pcVar15 = (char *)(msg_readcount + -1);
          Con_Printf("%3i:%s\n",pcVar15,str);
        }
      }
      if ((uVar11 < 0x40) && (msg_buckets[uVar11] = msg_buckets[uVar11] + 1, uVar11 == 0)) {
        CL_WriteMessageHistory(start,0);
        pcVar15 = "svc_bad";
        Host_Error("CL_ParseServerMessage: Illegible server message - %s\n","svc_bad");
      }
      else {
        pcVar5 = cl_parsefuncs[uVar11].pfnParse;
        if (pcVar5 != (code *)0x0) {
                    /* Unresolved local var: _func_void * func@[???] */
          if (cl_showmessages.value == 0.0) {
            (*pcVar5)();
          }
          else {
            pcVar15 = cl_parsefuncs[uVar11].pszname;
            Con_DPrintf("Msg: %s\n",pcVar15);
            (*pcVar5)();
          }
        }
      }
      iVar12 = msg_readcount;
      last_data[uVar11] = last_data[uVar11] + (msg_readcount - iVar13);
      iVar13 = cl.parsecountmod;
      sVar6 = (short)iVar12;
      if (uVar11 - 0x28 < 2) {
                    /* Unresolved local var: int playerbytes@[???] */
        iVar12 = cls.playerbits;
        if (cls.playerbits < 0) {
          iVar12 = cls.playerbits + 7;
        }
        sVar8 = (short)(iVar12 >> 3);
        uVar2 = cl.frames[cl.parsecountmod].packetentitybytes;
        cl.frames[cl.parsecountmod].packetentitybytes = ((sVar6 + uVar2) - sVar7) - sVar8;
        cl.frames[iVar13].playerinfobytes = sVar8 + cl.frames[iVar13].playerinfobytes;
      }
      else if (uVar11 == 0x17) {
        cl.frames[cl.parsecountmod].tentitybytes =
             (sVar6 + cl.frames[cl.parsecountmod].tentitybytes) - sVar7;
      }
      else if (uVar11 == 6) {
        uVar3 = cl.frames[cl.parsecountmod].soundbytes;
        cl.frames[cl.parsecountmod].soundbytes = (sVar6 + uVar3) - sVar7;
      }
      else if (uVar11 == 0xf) {
        uVar4 = cl.frames[cl.parsecountmod].clientbytes;
        cl.frames[cl.parsecountmod].clientbytes = (sVar6 + uVar4) - sVar7;
      }
      else if ((uVar11 == 0x15) || (uVar11 == 3)) {
        cl.frames[cl.parsecountmod].eventbytes =
             (sVar6 + cl.frames[cl.parsecountmod].eventbytes) - sVar7;
      }
    }
    uVar14 = currentcmd & 0x1f;
    oldcmd[uVar14].command = uVar11;
    oldcmd[uVar14].starting_offset = iVar13;
    currentcmd = currentcmd + 1;
    oldcmd[uVar14].frame_number = host_framecount;
    if ((int)uVar11 < 0x3c) goto LAB_001b0082;
    msg_buckets[0x3f] = msg_buckets[0x3f] + 1;
    DispatchUserMsg(uVar11);
    last_data[0x3f] = last_data[0x3f] + (msg_readcount - iVar13);
    uVar1 = cl.frames[cl.parsecountmod].usrbytes;
    cl.frames[cl.parsecountmod].usrbytes = ((short)msg_readcount + uVar1) - sVar7;
  } while( true );
}


// CL_ParseSoundFade  @ 001af610
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


// CL_ParseStatic  @ 001af300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseStatic(void)

{
  return;
}


// CL_ParseStaticSound  @ 001af310
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseStaticSound(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int entnum;
  int pitch;
  uint flags;
  sfx_t *sfxin;
  sfx_t local_70;
  float local_28;
  float local_24;
  float local_20;
  
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
  local_28 = MSG_ReadCoord(&net_message);
  local_24 = MSG_ReadCoord(&net_message);
  local_20 = MSG_ReadCoord(&net_message);
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
    sfxin = &local_70;
    snprintf(sfxin->name,0x40,"!%s",rgpszrawsentence[iVar1]);
  }
  S_StartStaticSound(entnum,6,sfxin,&local_28,(float)iVar2 / 255.0,(float)iVar3 * 0.015625,flags,
                     pitch);
  return;
}


// CL_ParseTEnt  @ 001a7870
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ParseTEnt(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  cachewad_t *wad;
  _func_void_cl_entity_s_ptr_int_int_conflict *p_Var5;
  _func_void_TEMPENTITY_ptr_float_int *p_Var6;
  _func_void_TEMPENTITY_ptr_float *p_Var7;
  _func_void_float_ptr_float_float_int_int *p_Var8;
  _func_TEMPENTITY_ptr_float_ptr_float_ptr_float_ptr_float_int_int *p_Var9;
  _func_void_int_int_int_float_ptr_int *p_Var10;
  _func_BEAM_ptr_float_ptr_float_ptr_int_float_float_float_float_float_int_float_float_float_float
  *p_Var11;
  double dVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  texture_t *ptexture;
  int32 iVar19;
  dlight_t_conflict *pdVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  TEMPENTITY *pTVar27;
  customization_s_conflict *pcVar28;
  int unaff_EBP;
  longdouble lVar29;
  longdouble lVar30;
  float fVar31;
  float fVar32;
  int local_c4;
  int local_a0;
  float local_8c;
  float local_88;
  float local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_6c;
  float local_68;
  float local_64;
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
  int local_20 [4];
  
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
  iVar14 = MSG_ReadByte();
  switch(iVar14) {
  case 0:
  case 1:
  case 8:
    if (iVar14 == 8) {
      unaff_EBP = MSG_ReadShort();
      local_a0 = MSG_ReadShort();
    }
    else {
      if (iVar14 == 1) {
        unaff_EBP = MSG_ReadShort();
      }
      else {
        local_8c = MSG_ReadCoord(&net_message);
        local_88 = MSG_ReadCoord(&net_message);
        local_84 = MSG_ReadCoord(&net_message);
      }
      local_6c = MSG_ReadCoord(&net_message);
      local_68 = MSG_ReadCoord(&net_message);
      local_64 = MSG_ReadCoord(&net_message);
    }
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    fVar31 = (float)((longdouble)0.1 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar32 = (float)((longdouble)0.1 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    local_7c = (float)uVar21;
    iVar17 = MSG_ReadByte();
    local_78 = (float)iVar17;
    uVar21 = MSG_ReadByte();
    fVar1 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar2 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar3 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar4 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    iVar17 = MSG_ReadByte();
    iVar17 = (int)((double)iVar17 * 0.1);
    if (iVar14 == 8) {
      (*efx.R_BeamEnts)(unaff_EBP,local_a0,iVar15,fVar32,local_7c * 0.1,local_78 * 0.01,fVar4,
                        (float)iVar17,iVar16,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar14 == 1) {
      (*efx.R_BeamEntPoint)
                (unaff_EBP,&local_6c,iVar15,fVar32,local_7c * 0.1,local_78 * 0.01,fVar4,
                 (float)iVar17,iVar16,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar14 == 0) {
      (*efx.R_BeamPoints)(&local_8c,&local_6c,iVar15,fVar32,local_7c * 0.1,local_78 * 0.01,fVar4,
                          (float)iVar17,iVar16,fVar31,fVar1,fVar2,fVar3);
    }
    break;
  case 2:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    (*efx.R_RunParticleEffect)(&local_8c,vec3_origin,0,0x14);
    (*efx.R_RicochetSound)(&local_8c);
    break;
  case 3:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    local_7c = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    local_78 = (float)iVar15;
    uVar21 = MSG_ReadByte();
    fVar31 = local_7c;
    p_Var6 = efx.R_Sprite_Explode;
    if (local_7c != 0.0) {
      pTVar27 = R_DefaultSprite(&local_8c,iVar14,local_78);
      (*p_Var6)(pTVar27,fVar31,uVar21);
      if ((uVar21 & 8) == 0) {
        (*efx.R_FlickerParticles)(&local_8c);
      }
      if ((uVar21 & 2) == 0) {
        pdVar20 = (*efx.CL_AllocDlight)(0);
        pdVar20->origin[0] = local_8c;
        pdVar20->origin[1] = local_88;
        pdVar20->radius = 200.0;
        (pdVar20->color).g = 0xfa;
        (pdVar20->color).r = 0xfa;
        pdVar20->origin[2] = local_84;
        (pdVar20->color).b = 0x96;
        pdVar20->die = (float)((longdouble)0.01 + (longdouble)cl.time);
        pdVar20->decay = 800.0;
        pdVar20 = (*efx.CL_AllocDlight)(0);
        pdVar20->origin[0] = local_8c;
        pdVar20->origin[1] = local_88;
        pdVar20->radius = 150.0;
        (pdVar20->color).r = 0xff;
        (pdVar20->color).g = 0xbe;
        pdVar20->origin[2] = local_84;
        (pdVar20->color).b = '(';
        pdVar20->die = (float)cl.time + 1.0;
        pdVar20->decay = 200.0;
      }
    }
    if ((uVar21 & 4) != 0) {
      return;
    }
    iVar19 = RandomLong(0,2);
    if (iVar19 == 1) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp2,&local_8c,1.0,0.3,0,100);
      return;
    }
    if (iVar19 == 2) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp3,&local_8c,1.0,0.3,0,100);
      return;
    }
    if (iVar19 != 0) {
      return;
    }
    fVar31 = 0.3;
    goto LAB_001a99a2;
  case 4:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    (*efx.R_BlobExplosion)(&local_8c);
    fVar31 = 1.0;
    goto LAB_001a99a2;
  case 5:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    local_7c = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    fVar31 = local_7c;
    p_Var7 = efx.R_Sprite_Smoke;
    local_78 = (float)iVar15;
    pTVar27 = R_DefaultSprite(&local_8c,iVar14,local_78);
    (*p_Var7)(pTVar27,fVar31);
    break;
  case 6:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    (*efx.R_TracerEffect)(&local_8c,&local_6c);
    break;
  case 7:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    local_7c = (float)iVar15;
    iVar15 = MSG_ReadByte();
    local_78 = (float)iVar15;
    iVar15 = MSG_ReadShort();
    (*efx.R_BeamLightning)
              (&local_8c,&local_6c,iVar15,(float)iVar14 * 0.1,local_7c * 0.1,local_78 * 0.01,0.6,3.5
              );
    break;
  case 9:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    (*efx.R_SparkEffect)(&local_8c,8,-200,200);
    break;
  case 10:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    (*efx.R_LavaSplash)(&local_8c);
    break;
  case 0xb:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    (*efx.R_TeleportSplash)(&local_8c);
    break;
  case 0xc:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    (*efx.R_ParticleExplosion2)(&local_8c,iVar14,iVar15);
    pdVar20 = (*efx.CL_AllocDlight)(0);
    pdVar20->origin[0] = local_8c;
    pdVar20->origin[1] = local_88;
    pdVar20->radius = 350.0;
    pdVar20->origin[2] = local_84;
    pdVar20->die = (float)cl.time + 0.5;
    pdVar20->decay = 300.0;
    fVar31 = 0.6;
LAB_001a99a2:
    S_StartDynamicSound(-1,0,cl_sfx_r_exp1,&local_8c,1.0,fVar31,0,100);
    break;
  case 0xd:
  case 0x68:
  case 0x74:
  case 0x75:
  case 0x76:
                    /* Unresolved local var: int decalTextureIndex@[???] */
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    if (iVar14 == 0xd) {
      iVar15 = MSG_ReadShort();
      iVar16 = MSG_ReadShort();
      if (iVar16 == 0) {
        iVar17 = 0;
        local_c4 = 1;
      }
      else {
        iVar17 = MSG_ReadShort();
        local_c4 = 1;
      }
    }
    else {
      iVar15 = MSG_ReadByte();
      if ((iVar14 == 0x76) || (iVar14 == 0x68)) {
        iVar16 = MSG_ReadShort();
        iVar17 = 0;
        local_c4 = 0;
      }
      else {
        iVar16 = 0;
        local_c4 = 0;
        iVar17 = 0;
      }
    }
    if (iVar14 - 0x75U < 2) {
      iVar15 = iVar15 + 0x100;
    }
    if (cl.max_edicts <= iVar16) {
      Sys_Error("Decal: entity = %i",iVar16);
    }
    p_Var10 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      iVar14 = (*efx.Draw_DecalIndex)(iVar15);
      (*p_Var10)(iVar14,iVar16,iVar17,&local_8c,local_c4);
    }
    break;
  case 0xe:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    local_7c = (float)iVar14;
    iVar14 = MSG_ReadByte();
    local_78 = (float)iVar14;
    iVar14 = MSG_ReadByte();
    local_74 = (float)iVar14 / 10.0;
    (*efx.R_Implosion)(&local_8c,local_7c,(int)local_78,local_74);
    break;
  case 0xf:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    if ((longdouble)uVar22 == (longdouble)0) {
      local_7c = 1.0;
    }
    else {
      local_7c = (float)((longdouble)0.1 * (longdouble)uVar22);
    }
    iVar16 = MSG_ReadByte();
    local_78 = (float)iVar16 * 10.0;
    iVar16 = MSG_ReadByte();
    (*efx.R_Sprite_Trail)
              (0xf,&local_8c,&local_6c,iVar14,iVar15,(float)((longdouble)0.1 * (longdouble)uVar21),
               local_7c,local_78,0xff,(float)(int)((double)iVar16 * 10.0));
    break;
  default:
    Sys_Error("CL_ParseTEnt: bad type");
    break;
  case 0x11:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    local_7c = (float)iVar15 * 0.1;
    uVar21 = MSG_ReadByte();
    iVar17 = 0x100;
    fVar31 = 0.0;
    iVar16 = 0;
    iVar15 = 5;
    lVar29 = (longdouble)0.00392156862745098 * (longdouble)uVar21;
    goto LAB_001a912f;
  case 0x12:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    p_Var11 = efx.R_BeamPoints;
    fVar31 = RandomFloat(0.5,0.655);
    (*p_Var11)(&local_8c,&local_6c,iVar14,0.01,0.4,0.0,fVar31,5.0,0,0.0,1.0,0.0,0.0);
    (*efx.R_TempSprite)(&local_6c,vec3_origin,0.1,iVar15,5,0,0.35,0.01,0);
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    local_7c = (float)uVar23;
    iVar17 = MSG_ReadByte();
    local_78 = (float)iVar17;
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamCirclePoints)
              (iVar14,&local_8c,&local_6c,iVar15,(float)((longdouble)uVar22 * lVar30),local_7c,
               local_78 * 0.01,(float)((longdouble)uVar26 * lVar29),
               (float)(int)(lVar30 * (longdouble)iVar17),iVar16,(float)((longdouble)uVar21 * lVar30)
               ,(float)((longdouble)uVar23 * lVar29),(float)((longdouble)uVar24 * lVar29),
               (float)((longdouble)uVar25 * lVar29));
    break;
  case 0x16:
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    local_7c = (float)uVar22;
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    (*efx.R_BeamFollow)(iVar14,iVar15,(float)((longdouble)0.1 * (longdouble)uVar21),local_7c,
                        (float)((longdouble)uVar22 * lVar29),(float)((longdouble)uVar23 * lVar29),
                        (float)((longdouble)uVar24 * lVar29),(float)((longdouble)uVar25 * lVar29));
    break;
  case 0x17:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    uVar21 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    local_7c = (float)iVar15 * 0.1;
    uVar22 = MSG_ReadByte();
    iVar17 = 0x80;
    iVar16 = 0xe;
    iVar15 = 3;
    fVar31 = (float)((longdouble)0.10000000149011612 * (longdouble)uVar21);
    lVar29 = (longdouble)0.00392156862745098 * (longdouble)uVar22;
LAB_001a912f:
    (*efx.R_TempSprite)(&local_8c,vec3_origin,local_7c,iVar14,iVar15,iVar16,(float)lVar29,fVar31,
                        iVar17);
    break;
  case 0x18:
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    local_7c = (float)uVar23;
    iVar18 = MSG_ReadByte();
    local_78 = (float)iVar18;
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamRing)(iVar14,iVar15,iVar16,(float)((longdouble)uVar22 * lVar30),
                      (float)(lVar30 * (longdouble)local_7c),local_78 * 0.01,
                      (float)((longdouble)uVar26 * lVar29),(float)(int)(lVar30 * (longdouble)iVar18)
                      ,iVar17,(float)((longdouble)uVar21 * lVar30),
                      (float)((longdouble)uVar23 * lVar29),(float)((longdouble)uVar24 * lVar29),
                      (float)((longdouble)uVar25 * lVar29));
    break;
  case 0x19:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    (*efx.R_StreakSplash)(&local_8c,&local_2c,iVar14,iVar15,(float)iVar16,-iVar17,iVar17);
    break;
  case 0x1b:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    pdVar20 = (*efx.CL_AllocDlight)(0);
    pdVar20->origin[0] = local_8c;
    pdVar20->origin[1] = local_88;
    pdVar20->origin[2] = local_84;
    iVar14 = MSG_ReadByte();
    pdVar20->radius = (float)(iVar14 * 10);
    iVar14 = MSG_ReadByte();
    (pdVar20->color).r = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).g = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).b = (byte)iVar14;
    dVar12 = cl.time;
    iVar14 = MSG_ReadByte();
    pdVar20->die = (float)iVar14 * 0.1 + (float)dVar12;
    iVar14 = MSG_ReadByte();
    pdVar20->decay = (float)(iVar14 * 10);
    break;
  case 0x1c:
    iVar14 = MSG_ReadShort();
    pdVar20 = (*efx.CL_AllocElight)(iVar14);
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->origin[0] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->origin[1] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->origin[2] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->radius = fVar31;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).r = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).g = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).b = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    fVar31 = (float)iVar14 * 0.1;
    pdVar20->die = fVar31 + (float)cl.time;
    fVar32 = MSG_ReadCoord(&net_message);
    pdVar20->decay = fVar32;
    if (fVar31 != 0.0) {
      pdVar20->decay = fVar32 / fVar31;
    }
    break;
  case 0x1d:
    CL_ParseTextMessage();
    break;
  case 0x1e:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    local_7c = (float)iVar14 * 0.1;
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    fVar31 = local_7c;
                    /* Unresolved local var: int pcolor@[???] */
    sVar13 = R_LookupColor((uchar)iVar14,(uchar)iVar15,(uchar)iVar16);
    PM_ParticleLine(&local_8c,&local_6c,(int)sVar13,fVar31,0.0);
    break;
  case 0x1f:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    local_7c = (float)iVar14 * 0.1;
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    fVar31 = local_7c;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int pcolor@[???]
                       Unresolved local var: vec3_t mmin@[???]
                       Unresolved local var: vec3_t mmax@[???]
                       Unresolved local var: vec3_t origin@[???] */
    sVar13 = R_LookupColor((uchar)iVar14,(uchar)iVar15,(uchar)iVar16);
    local_3c = (local_6c + local_8c) * 0.5;
    local_4c = local_6c - local_3c;
    local_5c = local_8c - local_3c;
    local_38 = (local_68 + local_88) * 0.5;
    local_48 = local_68 - local_38;
    local_58 = local_88 - local_38;
    local_34 = (local_64 + local_84) * 0.5;
    local_44 = local_64 - local_34;
    local_54 = local_84 - local_34;
    PM_DrawBBox(&local_5c,&local_4c,&local_3c,(int)sVar13,fVar31);
    break;
  case 99:
    iVar14 = MSG_ReadShort();
    (*efx.R_BeamKill)(iVar14);
    break;
  case 100:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    (*efx.R_LargeFunnel)(&local_8c,iVar15);
    (*efx.R_FunnelSprite)(&local_8c,iVar14,iVar15);
    break;
  case 0x65:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodStream)(&local_8c,&local_2c,iVar14,iVar15);
    }
    break;
  case 0x66:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    (*efx.R_ShowLine)(&local_8c,&local_6c);
    break;
  case 0x67:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_Blood)(&local_8c,&local_2c,iVar14,iVar15);
    }
    break;
  case 0x69:
    iVar14 = MSG_ReadShort();
    if (cl.max_edicts <= iVar14) {
      Sys_Error("Bubble: entity = %i",iVar14);
    }
    iVar15 = MSG_ReadShort();
    p_Var5 = efx.R_FizzEffect;
    iVar16 = MSG_ReadByte();
    (*p_Var5)((cl_entity_s_conflict *)(cl_entities + iVar14),iVar15,iVar16);
    break;
  case 0x6a:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    local_6c = 0.0;
    local_68 = MSG_ReadAngle();
    local_64 = 0.0;
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    p_Var9 = efx.R_TempModel;
    iVar16 = MSG_ReadByte();
    (*p_Var9)(&local_8c,&local_2c,&local_6c,(float)iVar16 * 0.1,iVar14,iVar15);
    break;
  case 0x6b:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    p_Var8 = efx.R_TempSphereModel;
    iVar16 = MSG_ReadByte();
    (*p_Var8)(&local_8c,local_2c,(float)iVar16 * 0.1,iVar15,iVar14);
    break;
  case 0x6c:
                    /* Unresolved local var: float flTime@[???] */
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_7c = MSG_ReadCoord(&net_message);
    local_78 = MSG_ReadCoord(&net_message);
    local_74 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_BreakModel)(&local_8c,&local_7c,&local_2c,(float)iVar14 * 10.0,(float)iVar17 * 0.1,
                        iVar16,iVar15,(char)iVar18);
    break;
  case 0x6d:
                    /* Unresolved local var: int decalTextureIndex@[???] */
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    (*efx.R_BulletImpactParticles)(&local_8c);
    iVar19 = RandomLong(0,0x7fff);
    if (iVar19 < 0x3fff) {
      switch(iVar19 % 5) {
      case 0:
        S_StartDynamicSound(-1,0,cl_sfx_ric1,&local_8c,1.0,1.0,0,100);
        break;
      case 1:
        S_StartDynamicSound(-1,0,cl_sfx_ric2,&local_8c,1.0,1.0,0,100);
        break;
      case 2:
        S_StartDynamicSound(-1,0,cl_sfx_ric3,&local_8c,1.0,1.0,0,100);
        break;
      case 3:
        S_StartDynamicSound(-1,0,cl_sfx_ric4,&local_8c,1.0,1.0,0,100);
        break;
      case 4:
        S_StartDynamicSound(-1,0,cl_sfx_ric5,&local_8c,1.0,1.0,0,100);
      }
    }
    if (cl.max_edicts <= iVar14) {
      Sys_Error("Decal: entity = %i",iVar14);
    }
    p_Var10 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      iVar15 = (*efx.Draw_DecalIndex)(iVar15);
      (*p_Var10)(iVar15,iVar14,0,&local_8c,0);
    }
    break;
  case 0x6e:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_Sprite_Spray)(&local_8c,&local_2c,iVar14,iVar15,iVar16 * 2,iVar17);
    break;
  case 0x6f:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    local_7c = (float)iVar14 * 0.1;
    (*efx.R_RicochetSprite)(&local_8c,cl_sprite_ricochet,0.1,local_7c);
    (*efx.R_RicochetSound)(&local_8c);
    break;
  case 0x70:
                    /* Unresolved local var: int decalTextureIndex@[???]
                       Unresolved local var: int playernum@[???]
                       Unresolved local var: customization_t * pCust@[???]
                       Unresolved local var: texture_t * pTexture@[???] */
    iVar14 = MSG_ReadByte();
    pcVar28 = (customization_s_conflict *)0x0;
    if (iVar14 - 1U < 0x20) {
      pcVar28 = cl.players[iVar14 + -1].customdata.pNext;
    }
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar16 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    if (cl.max_edicts <= iVar16) {
      Sys_Error("Decal: entity = %i",iVar16);
    }
    ptexture = (texture_t *)0x0;
    if (((((pcVar28 != (customization_s_conflict *)0x0) && (pcVar28->pBuffer != (void *)0x0)) &&
         (wad = pcVar28->pInfo, wad != (cachewad_t *)0x0)) &&
        ((((pcVar28->resource).ucFlags & 4) != 0 && ((pcVar28->resource).type == t_decal)))) &&
       (pcVar28->bTranslated != 0)) {
      iVar17 = wad->lumpCount + -1;
      if (iVar17 < iVar15) {
        iVar15 = iVar17;
      }
      pcVar28->nUserData1 = iVar15;
      ptexture = Draw_CustomCacheGet(wad,pcVar28->pBuffer,(pcVar28->resource).nDownloadSize,iVar15);
    }
    p_Var10 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      if (pcVar28 == (customization_s_conflict *)0x0) {
        iVar14 = (*efx.Draw_DecalIndex)(iVar15);
        (*p_Var10)(iVar14,iVar16,0,&local_8c,4);
      }
      else if (ptexture != (texture_t *)0x0) {
        R_CustomDecalShoot(ptexture,iVar14 - 1U,iVar16,0,&local_8c,4);
      }
    }
    break;
  case 0x71:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    local_7c = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    local_78 = MSG_ReadCoord(&net_message);
    (*efx.R_Bubbles)(&local_8c,&local_6c,local_7c,iVar14,iVar15,local_78);
    break;
  case 0x72:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_6c = MSG_ReadCoord(&net_message);
    local_68 = MSG_ReadCoord(&net_message);
    local_64 = MSG_ReadCoord(&net_message);
    local_7c = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    local_78 = MSG_ReadCoord(&net_message);
    (*efx.R_BubbleTrail)(&local_8c,&local_6c,local_7c,iVar14,iVar15,local_78);
    break;
  case 0x73:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    local_7c = (float)iVar17;
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodSprite)(&local_8c,iVar16,iVar14,iVar15,local_7c);
    }
    break;
  case 0x77:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_Projectile)(&local_8c,&local_2c,iVar14,(int)(float)iVar15,iVar16,
                        (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0);
    break;
  case 0x78:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_Spray)(&local_8c,&local_2c,iVar14,iVar15,iVar16,iVar17,iVar18);
    break;
  case 0x79:
                    /* Unresolved local var: int isize@[???] */
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_PlayerSprites)(iVar14,iVar15,iVar16,iVar17);
    break;
  case 0x7a:
                    /* Unresolved local var: int radius@[???] */
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_ParticleBurst)(&local_8c,iVar14,iVar15,(float)iVar16 / 10.0);
    break;
  case 0x7b:
                    /* Unresolved local var: int radius@[???] */
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_FireField)(&local_8c,iVar14,iVar15,iVar16,iVar17,(float)iVar18 / 10.0);
    break;
  case 0x7c:
    iVar14 = MSG_ReadByte();
    fVar31 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    (*efx.R_AttachTentToPlayer)(iVar14,iVar15,fVar31,(float)iVar16 / 10.0);
    break;
  case 0x7d:
    iVar14 = MSG_ReadByte();
    (*efx.R_KillAttachedTents)(iVar14);
    break;
  case 0x7e:
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_2c = local_2c / 10.0;
    local_28 = MSG_ReadCoord(&net_message);
    local_28 = local_28 / 10.0;
    local_24 = MSG_ReadCoord(&net_message);
    local_24 = local_24 / 10.0;
    local_7c = MSG_ReadCoord(&net_message);
    local_78 = MSG_ReadCoord(&net_message);
    local_74 = 0.0;
    local_7c = local_7c / 100.0;
    local_78 = local_78 / 100.0;
    iVar14 = MSG_ReadByte();
    local_20[0] = MSG_ReadByte();
    (*efx.R_MultiGunshot)(&local_8c,&local_2c,&local_7c,iVar14,1,local_20);
    break;
  case 0x7f:
                    /* Unresolved local var: float length@[???] */
    local_8c = MSG_ReadCoord(&net_message);
    local_88 = MSG_ReadCoord(&net_message);
    local_84 = MSG_ReadCoord(&net_message);
    local_2c = MSG_ReadCoord(&net_message);
    local_28 = MSG_ReadCoord(&net_message);
    local_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_UserTracerParticle)
              (&local_8c,&local_2c,(float)iVar14 / 10.0,iVar15,(float)iVar16 / 10.0,'\0',
               (_func_void_particle_s_ptr *)0x0);
  }
  return;
}


// CL_ParseTextMessage  @ 001a7710
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


// CL_Parse_AddAngle  @ 00190d20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_AddAngle(void)

{
  float fVar1;
  
                    /* Unresolved local var: float ang@[???] */
  fVar1 = MSG_ReadHiresAngle();
  cl.viewangles[1] = fVar1 + cl.viewangles[1];
  return;
}


// CL_Parse_CDTrack  @ 00190ef0
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


// CL_Parse_CenterPrint  @ 00190320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_CenterPrint(void)

{
  char *str;
  
  str = MSG_ReadString();
  SCR_CenterPrint(str);
  return;
}


// CL_Parse_Choke  @ 00191160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Choke(void)

{
  cl.frames[CL_UPDATE_MASK & cls.netchan.incoming_sequence].choked = true;
  return;
}


// CL_Parse_ClientData  @ 00190040
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
  clientdata_s *pcd;
  int iVar12;
  uint32 uVar13;
  uint32 uVar14;
  uint uVar15;
  weapon_data_s *pwd;
  uint uVar16;
  local_state_t *pps;
  int iVar17;
  weapon_data_s *wd;
  local_state_t *plStack_26c;
  uchar auStack_250 [476];
  uchar auStack_74 [100];
  
  ppdVar10 = DELTA_LookupRegistration("clientdata_t");
  ppdVar11 = DELTA_LookupRegistration("weapon_data_t");
  Q_memset(auStack_250,0,0x1dc);
  iVar8 = cls.netchan.incoming_acknowledged;
  iVar12 = cls.netchan.incoming_sequence;
  iVar6 = CL_ParseClientdata::last_incoming_sequence;
  iVar5 = CL_UPDATE_MASK;
  uVar15 = CL_ParseClientdata::last_incoming_sequence + 1;
  if ((int)uVar15 < cls.netchan.incoming_sequence) {
    do {
      uVar16 = uVar15 & iVar5;
      if (0.0 <= cl.frames[uVar16].receivedtime) {
        *(undefined4 *)&cl.frames[uVar16].receivedtime = 0;
        *(undefined4 *)((int)&cl.frames[uVar16].receivedtime + 4) = 0xbff00000;
        *(undefined4 *)&cl.frames[uVar16].latency = 0;
        *(undefined4 *)((int)&cl.frames[uVar16].latency + 4) = 0;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 != iVar12);
  }
  uVar15 = iVar5 & iVar12;
  iVar17 = uVar15 * 0x42b8;
  cl.parsecount = iVar12;
  cl.parsecountmod = uVar15;
  cl.frames[uVar15].time = cl.mtime[0];
  dVar2 = realtime;
  fVar1 = cl.commands[iVar8 & iVar5].senttime;
  dVar3 = (double)fVar1;
  parsecounttime = (double)fVar1;
  cl.commands[iVar8 & iVar5].receivedtime = (float)realtime;
  cl.frames[uVar15].receivedtime = dVar2;
  cl.frames[uVar15].clientbytes = 0;
  cl.frames[uVar15].tentitybytes = 0;
  cl.frames[uVar15].soundbytes = 0;
  cl.frames[uVar15].eventbytes = 0;
  cl.frames[uVar15].msgbytes = 0;
  iVar7 = CL_ParseClientdata::last_command_ack;
  cl.frames[uVar15].packetentitybytes = 0;
  cl.frames[uVar15].playerinfobytes = 0;
  cl.frames[uVar15].usrbytes = 0;
  cl.frames[uVar15].voicebytes = 0;
  if (iVar7 != -1) {
    if (cls.spectator == false) {
      uVar16 = iVar6 + (iVar8 - iVar7) & iVar5;
      plStack_26c = (local_state_t *)(iVar17 + 0xc7f6fc + cl.playernum * 0x154);
      pps = cl.predicted_frames + uVar16;
      pcd = &cl.frames[uVar15].clientdata;
      plVar4 = cl.predicted_frames + uVar16;
      pwd = cl.predicted_frames[uVar16].weapondata;
      wd = cl.frames[uVar15].weapondata;
    }
    else {
      pwd = spectatorState.weapondata;
      plVar4 = &spectatorState;
      pps = &spectatorState;
      pcd = &spectatorState.client;
      plStack_26c = &spectatorState;
      wd = pwd;
    }
    ClientDLL_TxferPredictionData
              ((entity_state_s *)plStack_26c,(entity_state_s *)pps,pcd,&plVar4->client,wd,pwd);
    iVar12 = cls.netchan.incoming_sequence;
    dVar2 = realtime;
    dVar3 = parsecounttime;
  }
  qVar9 = cls.spectator;
  g_flLatency = dVar2 - dVar3;
  CL_ParseClientdata::last_incoming_sequence = iVar12;
  cl.frames[uVar15].latency = g_flLatency;
  CL_ParseClientdata::last_command_ack = iVar8;
  if (qVar9 == false) {
    to = &cl.frames[uVar15].clientdata;
    MSG_StartBitReading(&net_message);
    uVar13 = MSG_ReadBits(1);
    if (uVar13 == 0) {
      DELTA_ParseDelta(auStack_250,(uchar *)to,*ppdVar10,0x1dc);
      Q_memset(auStack_74,0,0x58);
      while (uVar13 = MSG_ReadBits(1), uVar13 != 0) {
        uVar13 = MSG_ReadBits(6);
        DELTA_ParseDelta(auStack_74,(uchar *)(iVar17 + 0xc82360 + uVar13 * 0x58),*ppdVar11,0x58);
      }
    }
    else {
      uVar13 = MSG_ReadBits(8);
      DELTA_ParseDelta((uchar *)&cl.frames[CL_UPDATE_MASK & uVar13].clientdata,(uchar *)to,*ppdVar10
                       ,0x1dc);
      Q_memset(auStack_74,0,0x58);
      while (uVar14 = MSG_ReadBits(1), uVar14 != 0) {
        uVar14 = MSG_ReadBits(6);
        DELTA_ParseDelta((uchar *)(uVar14 * 0x58 + 0xc82360 + (CL_UPDATE_MASK & uVar13) * 0x42b8),
                         (uchar *)(iVar17 + 0xc82360 + uVar14 * 0x58),*ppdVar11,0x58);
      }
    }
    MSG_EndBitReading(&net_message);
    Q_strncpy(cls.physinfo,cl.frames[uVar15].clientdata.physinfo,0xff);
    cls.physinfo[0xff] = '\0';
    cl.stats[0] = (int)cl.frames[uVar15].clientdata.health;
    cl.weapons = cl.frames[uVar15].clientdata.weapons;
    cl.maxspeed = cl.frames[uVar15].clientdata.maxspeed;
    cl.pushmsec = cl.frames[uVar15].clientdata.pushmsec;
    return;
  }
  cl.stats[0] = 1;
  return;
}


// CL_Parse_CrosshairAngle  @ 00190d40
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


// CL_Parse_Customization  @ 001911c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Customization(void)

{
  resourcetype_t_conflict rVar1;
  customization_s *pRemove;
  bool bVar2;
  uint uVar3;
  resource_s *pResource;
  resourcetype_t rVar4;
  char *src;
  int iVar5;
  uint uVar6;
  qboolean qVar7;
  customization_s *pcVar8;
  
  uVar3 = MSG_ReadByte();
  if (0x1f < uVar3) {
    Host_Error("Bogus player index during customization parsing.\n");
    return;
  }
  pResource = Mem_ZeroMalloc(0x88);
  rVar4 = MSG_ReadByte();
  pResource->type = rVar4;
  src = MSG_ReadString();
  Q_strncpy(pResource->szFileName,src,0x3f);
  pResource->szFileName[0x3f] = '\0';
  iVar5 = MSG_ReadShort();
  pResource->nIndex = iVar5;
  iVar5 = MSG_ReadLong();
  pResource->nDownloadSize = iVar5;
  uVar6 = MSG_ReadByte();
  pResource->pNext = (resource_s *)0x0;
  pResource->pPrev = (resource_s *)0x0;
  pResource->ucFlags = (byte)uVar6 & 0xfd;
  if ((uVar6 & 4) != 0) {
    MSG_ReadBuf(0x10,pResource->rgucMD5_hash);
  }
  bVar2 = cl_allow_download.value == 0.0;
  pResource->playernum = (uchar)uVar3;
  if (bVar2) {
    Con_DPrintf("Refusing new resource, cl_allow_download set to 0\n");
    Mem_Free(pResource);
  }
  else if ((cls.state == ca_active) && (cl_download_ingame.value == 0.0)) {
    Con_DPrintf("Refusing new resource, cl_download_ingame set to 0\n");
    Mem_Free(pResource);
  }
  else {
    bVar2 = false;
    pcVar8 = (customization_s *)cl.players[uVar3 & 0xff].customdata.pNext;
    if (pcVar8 != (customization_t *)0x0) {
      rVar1 = ((resource_t_conflict *)&pcVar8->resource)->type;
      pRemove = pcVar8;
      while (pResource->type != rVar1) {
        pRemove = pRemove->pNext;
        if (pRemove == (customization_s *)0x0) goto LAB_001ae053;
        rVar1 = (pRemove->resource).type;
      }
      CL_RemoveCustomization(uVar3 & 0xff,pRemove);
      pcVar8 = (customization_s *)cl.players[pResource->playernum].customdata.pNext;
      if (pcVar8 != (customization_t *)0x0) {
LAB_001ae053:
        do {
          iVar5 = Q_memcmp(((resource_t_conflict *)&pcVar8->resource)->rgucMD5_hash,
                           pResource->rgucMD5_hash,0x10);
          if (iVar5 == 0) {
            bVar2 = true;
            goto LAB_001ae08f;
          }
          pcVar8 = pcVar8->pNext;
        } while (pcVar8 != (customization_s *)0x0);
      }
      bVar2 = false;
    }
LAB_001ae08f:
    qVar7 = HPAK_GetDataPointer("custom.hpk",pResource,(uchar **)0x0,(int *)0x0);
    if (qVar7 != false) {
      if (bVar2) {
        Con_DPrintf("Duplicate resource ignored for local client\n");
      }
      else {
        qVar7 = COM_CreateCustomization
                          ((customization_t *)&cl.players[pResource->playernum].customdata,pResource
                           ,(uint)pResource->playernum,1,(customization_t **)0x0,(int *)0x0);
        if (qVar7 == false) {
          Con_DPrintf("Error loading customization\n");
        }
      }
      Mem_Free(pResource);
      return;
    }
    pResource->ucFlags = pResource->ucFlags | 2;
    if ((pResource->pPrev == (resource_s *)0x0) && (pResource->pNext == (resource_s *)0x0)) {
      if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
         (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
        Sys_Error("Resource list corrupted.\n");
      }
      else {
        pResource->pPrev = cl.resourcesneeded.pPrev;
        (cl.resourcesneeded.pPrev)->pNext = pResource;
        cl.resourcesneeded.pPrev = pResource;
        pResource->pNext = &cl.resourcesneeded;
      }
    }
    else {
      Con_Printf("Resource already linked\n");
    }
    Con_Printf("Requesting %s from server\n",pResource);
    CL_StartResourceDownloading("Custom resource propagation...\n",true);
  }
  return;
}


// CL_Parse_CutScene  @ 001910d0
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


// CL_Parse_Damage  @ 00191050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Damage(void)

{
  return;
}


// CL_Parse_DecalName  @ 00190fd0
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


// CL_Parse_DeltaDescription  @ 001ab830
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
  char local_160 [255];
  undefined1 local_61;
  uchar local_60 [80];
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char[256] szDesc@[???]
                       Unresolved local var: delta_t * * ppdelta@[???]
                       Unresolved local var: delta_description_t * pdesc@[???]
                       Unresolved local var: delta_description_t nulldesc@[???]
                       Unresolved local var: delta_description_t * from@[???]
                       Unresolved local var: delta_description_t * to@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  Q_memset(local_60,0,0x44);
  src = MSG_ReadString();
  if ((src != (char *)0x0) && (*src != '\0')) {
    Q_strncpy(local_160,src,0xff);
    local_61 = 0;
    ppdesc = DELTA_LookupRegistration(local_160);
    if ((ppdesc != (delta_t **)0x0) && (*ppdesc != (delta_t *)0x0)) {
      DELTA_FreeDescription(ppdesc);
    }
    MSG_StartBitReading(&net_message);
    uVar1 = MSG_ReadBits(0x10);
    pdVar2 = Mem_ZeroMalloc(0x30);
    *ppdesc = pdVar2;
    pdVar3 = Mem_ZeroMalloc(uVar1 * 0x44);
    (*ppdesc)->dynamic = 1;
    (*ppdesc)->fieldCount = uVar1;
    if (0 < (int)uVar1) {
      uVar4 = 0;
      to = pdVar3;
      do {
        uVar4 = uVar4 + 1;
        DELTA_ParseDelta(local_60,(uchar *)to,&g_MetaDelta,0x44);
        to = to + 1;
      } while (uVar1 != uVar4);
    }
    (*ppdesc)->pdd = pdVar3;
    MSG_EndBitReading(&net_message);
    return;
  }
  Host_Error("CL_Parse_DeltaDescription:  Illegible description name\n");
  return;
}


// CL_Parse_DeltaPacketEntities  @ 00191130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_DeltaPacketEntities(void)

{
  cls.playerbits = 0;
  CL_ParsePacketEntities(true,&cls.playerbits);
  CL_SetSolidEntities();
  return;
}


// CL_Parse_Director  @ 00191bc0
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


// CL_Parse_Disconnect  @ 00190050
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
  Host_EndGame("Server disconnected\n");
  return;
}


// CL_Parse_Finale  @ 001910a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Finale(void)

{
  char *str;
  
  cl.intermission = 2;
  vid.recalc_refdef = 1;
  str = MSG_ReadString();
  SCR_CenterPrint(str);
  return;
}


// CL_Parse_FoundSecret  @ 00191070
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_FoundSecret(void)

{
  return;
}


// CL_Parse_HLTV  @ 00191bb0
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


// CL_Parse_Intermission  @ 00191080
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Intermission(void)

{
  cl.intermission = 1;
  vid.recalc_refdef = 1;
  return;
}


// CL_Parse_KilledMonster  @ 00191060
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_KilledMonster(void)

{
  return;
}


// CL_Parse_LightStyle  @ 00190d80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_LightStyle(void)

{
  int iVar1;
  char *src;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = MSG_ReadByte();
  if (0x3f < iVar1) {
    Sys_Error("svc_lightstyle > MAX_LIGHTSTYLES");
  }
  src = MSG_ReadString();
  Q_strncpy(cl_lightstyle[iVar1].map,src,0x3f);
  cl_lightstyle[iVar1].map[0x3f] = '\0';
  iVar2 = Q_strlen(cl_lightstyle[iVar1].map);
  cl_lightstyle[iVar1].length = iVar2;
  return;
}


// CL_Parse_NewMoveVars  @ 001911a0
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


// CL_Parse_NewUserMsg  @ 00191030
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_NewUserMsg(void)

{
  bool bVar1;
  int iVar2;
  UserMsg *dest;
  _UserMsg *p_Var3;
  int iStack_3c;
  int iStack_38;
  char acStack_34 [4];
  char acStack_30 [4];
  char acStack_2c [4];
  char acStack_28 [3];
  undefined1 uStack_25;
  undefined4 uStack_20;
  int iStack_10;
  
  iStack_3c = MSG_ReadByte();
  iStack_38 = MSG_ReadByte();
  uStack_20 = 0;
  if (iStack_38 == 0xff) {
    iStack_38 = -1;
  }
  iStack_10 = MSG_ReadLong();
  Q_strncpy(acStack_34,(char *)&iStack_10,4);
  iStack_10 = MSG_ReadLong();
  Q_strncpy(acStack_30,(char *)&iStack_10,4);
  iStack_10 = MSG_ReadLong();
  Q_strncpy(acStack_2c,(char *)&iStack_10,4);
  iStack_10 = MSG_ReadLong();
  Q_strncpy(acStack_28,(char *)&iStack_10,4);
  uStack_25 = 0;
  if (gClientUserMsgs != (UserMsg *)0x0) {
    bVar1 = false;
    p_Var3 = gClientUserMsgs;
    do {
      if (p_Var3->iMsg == iStack_3c) {
        p_Var3->iMsg = 0;
      }
      iVar2 = Q_stricmp(p_Var3->szName,acStack_34);
      if (iVar2 == 0) {
        bVar1 = true;
        p_Var3->iMsg = iStack_3c;
        p_Var3->iSize = iStack_38;
      }
      p_Var3 = p_Var3->next;
    } while (p_Var3 != (_UserMsg *)0x0);
    if (bVar1) {
      return;
    }
  }
  dest = Mem_Malloc(0x20);
  Q_memcpy(dest,&iStack_3c,0x20);
  dest->next = gClientUserMsgs;
  gClientUserMsgs = dest;
  return;
}


// CL_Parse_PacketEntities  @ 00191100
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_PacketEntities(void)

{
  cls.playerbits = 0;
  CL_ParsePacketEntities(false,&cls.playerbits);
  CL_SetSolidEntities();
  return;
}


// CL_Parse_Particle  @ 00190e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Particle(void)

{
  int iVar1;
  int iVar2;
  int color;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  fStack_24 = MSG_ReadCoord(&net_message);
  fStack_20 = MSG_ReadCoord(&net_message);
  fStack_1c = MSG_ReadCoord(&net_message);
  iVar1 = MSG_ReadChar();
  fStack_18 = (float)iVar1 * 0.0625;
  iVar1 = MSG_ReadChar();
  fStack_14 = (float)iVar1 * 0.0625;
  iVar1 = MSG_ReadChar();
  fStack_10 = (float)iVar1 * 0.0625;
  iVar2 = MSG_ReadByte();
  color = MSG_ReadByte();
  iVar1 = 0x400;
  if (iVar2 != 0xff) {
    iVar1 = iVar2;
  }
  R_RunParticleEffect(&fStack_24,&fStack_18,color,iVar1);
  return;
}


// CL_Parse_Pings  @ 00191b30
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


// CL_Parse_Print  @ 00190300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Print(void)

{
  char *pcVar1;
  
  pcVar1 = MSG_ReadString();
  Con_Printf("%s",pcVar1);
  return;
}


// CL_Parse_ReliableEvent  @ 001919f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ReliableEvent(void)

{
  float delay;
  delta_t **ppdVar1;
  uint32 index;
  uint32 uVar2;
  event_args_t local_ac;
  uchar local_64 [84];
  
                    /* Unresolved local var: int event_index@[???]
                       Unresolved local var: qboolean hasdelay@[???]
                       Unresolved local var: float delay@[???]
                       Unresolved local var: event_args_t nullargs@[???]
                       Unresolved local var: event_args_t newargs@[???]
                       Unresolved local var: event_args_t * from@[???]
                       Unresolved local var: event_args_t * to@[???]
                       Unresolved local var: delta_t * * ppevent@[???] */
  ppdVar1 = DELTA_LookupRegistration("event_t");
  Q_memset(local_64,0,0x48);
  Q_memset(&local_ac,0,0x48);
  MSG_StartBitReading(&net_message);
  index = MSG_ReadBits(10);
  DELTA_ParseDelta(local_64,(uchar *)&local_ac,*ppdVar1,0x48);
  uVar2 = MSG_ReadBits(1);
  delay = 0.0;
  if (uVar2 != 0) {
    uVar2 = MSG_ReadBits(0x10);
    delay = (float)uVar2 / 100.0;
  }
  if ((0 < local_ac.entindex) && (local_ac.entindex <= cl.maxclients)) {
    local_ac.angles[0] = local_ac.angles[0] * -3.0;
  }
  CL_QueueEvent(2,index,delay,&local_ac);
  MSG_EndBitReading(&net_message);
  return;
}


// CL_Parse_ResourceList  @ 00191180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ResourceList(void)

{
  uint32 uVar1;
  resource_s *dest;
  resourcetype_t rVar2;
  char *src;
  uint32 uVar3;
  uint32 uVar4;
  
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("begin CL_ParseResourceList()");
  }
  MSG_StartBitReading(&net_message);
  uVar1 = MSG_ReadBits(0xc);
  if (0 < (int)uVar1) {
    uVar4 = 0;
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
        if ((dest->pPrev == (resource_s *)0x0) && (dest->pNext == (resource_s *)0x0)) break;
        Con_Printf("Resource already linked\n");
LAB_001adb34:
        uVar4 = uVar4 + 1;
        if (uVar1 == uVar4) goto LAB_001adc30;
      }
      if ((cl.resourcesneeded.pPrev == (resource_s *)0x0) ||
         (cl.resourcesneeded.pNext == (resource_s *)0x0)) {
        Sys_Error("Resource list corrupted.\n");
        goto LAB_001adb34;
      }
      dest->pPrev = cl.resourcesneeded.pPrev;
      uVar4 = uVar4 + 1;
      (cl.resourcesneeded.pPrev)->pNext = dest;
      cl.resourcesneeded.pPrev = dest;
      dest->pNext = &cl.resourcesneeded;
    } while (uVar1 != uVar4);
  }
LAB_001adc30:
  if (fs_startup_timings.value != 0.0) {
    AddStartupTiming("end   CL_ParseResourceList()");
  }
  CL_ParseConsistencyInfo();
  MSG_EndBitReading(&net_message);
  SetLoadingProgressBarStatusText("#GameUI_VerifyingResources");
  CL_StartResourceDownloading("Verifying and downloading resources...\n",false);
  return;
}


// CL_Parse_ResourceLocation  @ 00191190
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
      snprintf(cl.downloadUrl,0x80,"%s/",__s2);
    }
    else {
      strncpy(cl.downloadUrl,__s2,0x80);
      cl.downloadUrl[0x7f] = '\0';
    }
    Con_DPrintf("Using %s as primary download location\n",0xe03d28);
  }
  return;
}


// CL_Parse_ResourceRequest  @ 001911b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ResourceRequest(void)

{
  resource_t *prVar1;
  int iVar2;
  resourcetype_t *prVar3;
  byte abStack_1003c [65536];
  sizebuf_t asStack_3c [2];
  
  ContinueLoadingProgressBar("ClientConnect",6,0.0);
  Q_memset(asStack_3c,0,0x14);
  asStack_3c[0].buffername = "Client to Server Resource Block";
  asStack_3c[0].data = abStack_1003c;
  asStack_3c[0].cursize = 0;
  asStack_3c[0].maxsize = 0x10000;
  if (cls.state < ca_connecting) {
    Con_Printf("custom resource list not valid -- not connected\n");
    return;
  }
  iVar2 = MSG_ReadLong();
  if ((cls.demoplayback == false) && (cl.servercount != iVar2)) {
    Con_Printf("CL_SendResourceListBlock_f from different level\n");
    return;
  }
  iVar2 = MSG_ReadLong();
  if ((iVar2 < 0) || (cl.num_resources < iVar2)) {
    Con_Printf("custom resource list request out of range\n");
  }
  else {
    MSG_WriteByte(asStack_3c,5);
    MSG_WriteShort(asStack_3c,cl.num_resources);
    if (iVar2 < cl.num_resources) {
      prVar3 = &cl.resourcelist[iVar2].type;
      do {
        while( true ) {
          MSG_WriteString(asStack_3c,cl.resourcelist[iVar2].szFileName);
          MSG_WriteByte(asStack_3c,*prVar3);
          MSG_WriteShort(asStack_3c,prVar3[1]);
          MSG_WriteLong(asStack_3c,prVar3[2]);
          MSG_WriteByte(asStack_3c,(uint)*(byte *)(prVar3 + 3));
          if ((*(byte *)(prVar3 + 3) & 4) == 0) break;
          prVar1 = cl.resourcelist + iVar2;
          iVar2 = iVar2 + 1;
          prVar3 = prVar3 + 0x22;
          SZ_Write(asStack_3c,prVar1->rgucMD5_hash,0x10);
          if (cl.num_resources <= iVar2) goto LAB_001a2a2d;
        }
        iVar2 = iVar2 + 1;
        prVar3 = prVar3 + 0x22;
      } while (iVar2 < cl.num_resources);
    }
LAB_001a2a2d:
    if (0 < asStack_3c[0].cursize) {
      Netchan_CreateFragments(false,&cls.netchan,asStack_3c);
      Netchan_FragSend(&cls.netchan);
      return;
    }
  }
  return;
}


// CL_Parse_Restore  @ 00190f80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Restore(void)

{
  char *fileName;
  
  fileName = MSG_ReadString();
  CL_Restore(fileName);
  return;
}


// CL_Parse_RoomType  @ 00191000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_RoomType(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  Cvar_SetValue("room_type",(float)iVar1);
  return;
}


// CL_Parse_ServerInfo  @ 00190cc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_ServerInfo(void)

{
  CL_ParseServerInfo();
  vid.recalc_refdef = 1;
  sys_timescale.value = 1.0;
  return;
}


// CL_Parse_SetAngle  @ 00190cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SetAngle(void)

{
                    /* Unresolved local var: int i@[???] */
  cl.viewangles[0] = MSG_ReadHiresAngle();
  cl.viewangles[1] = MSG_ReadHiresAngle();
  cl.viewangles[2] = MSG_ReadHiresAngle();
  return;
}


// CL_Parse_SetPause  @ 00190e50
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


// CL_Parse_SetView  @ 001902e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SetView(void)

{
  cl.viewentity = MSG_ReadShort();
  return;
}


// CL_Parse_SignonNum  @ 00190ea0
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


// CL_Parse_Sound  @ 001ab970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Sound(void)

{
  uint32 flags;
  uint32 uVar1;
  uint32 entnum;
  char *pcVar2;
  sfx_t *sfxin;
  char *__format;
  float local_94;
  float local_90;
  uint32 local_8c;
  uint32 local_88;
  sfx_t local_70;
  vec_t local_28 [6];
  
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
  MSG_StartBitReading(&net_message);
  flags = MSG_ReadBits(9);
  local_94 = 1.0;
  if ((flags & 1) != 0) {
    uVar1 = MSG_ReadBits(8);
    local_94 = (float)uVar1 / 255.0;
  }
  local_90 = 1.0;
  if ((flags & 2) != 0) {
    uVar1 = MSG_ReadBits(8);
    local_90 = (float)uVar1 * 0.015625;
  }
  uVar1 = MSG_ReadBits(3);
  entnum = MSG_ReadBits(0xb);
  if ((flags & 4) == 0) {
    local_8c = MSG_ReadBits(8);
  }
  else {
    local_8c = MSG_ReadBits(0x10);
  }
  MSG_ReadBitVec3Coord(local_28);
  local_88 = 100;
  if ((flags & 8) != 0) {
    local_88 = MSG_ReadBits(8);
  }
  MSG_EndBitReading(&net_message);
  if ((int)entnum < cl.max_edicts) {
    if ((flags & 0x10) == 0) {
      sfxin = cl.sound_precache[local_8c];
    }
    else {
      if ((int)local_8c < 0x600) {
        pcVar2 = rgpszrawsentence[local_8c];
        __format = "!%s";
      }
      else {
        __format = "!#%d";
        pcVar2 = (char *)(local_8c - 0x600);
      }
      sfxin = &local_70;
      snprintf(sfxin->name,0x40,__format,pcVar2);
    }
    if (uVar1 == 6) {
      S_StartStaticSound(entnum,6,sfxin,local_28,local_94,local_90,flags,local_88);
    }
    else {
      S_StartDynamicSound(entnum,uVar1,sfxin,local_28,local_94,local_90,flags,local_88);
    }
  }
  else {
    Con_DPrintf("CL_Parse_Sound: ent = %i, cl.max_edicts %i\n",entnum,cl.max_edicts);
  }
  return;
}


// CL_Parse_SoundFade  @ 001911d0
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


// CL_Parse_SpawnBaseline  @ 00190e20
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
  uint32 uVar8;
  delta_t *pFields;
  qboolean qVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  cl_entity_t *unaff_ESI;
  uchar auStack_170 [352];
  
  ppdVar4 = DELTA_LookupRegistration("entity_state_t");
  ppdVar5 = DELTA_LookupRegistration("entity_state_player_t");
  ppdVar6 = DELTA_LookupRegistration("custom_entity_state_t");
  Q_memset(auStack_170,0,0x154);
  MSG_StartBitReading(&net_message);
  ContinueLoadingProgressBar("ClientConnect",0xb,0.0);
  SetLoadingProgressBarStatusText("#GameUI_ParseBaseline");
  cl.highentity = 0;
  while (uVar7 = MSG_PeekBits(0x10), uVar7 != 0xffff) {
    uVar7 = MSG_ReadBits(0xb);
    if (cl.highentity <= (int)uVar7) {
      cl.highentity = uVar7;
    }
    if (cl.num_entities <= (int)uVar7) {
      if ((int)uVar7 < cl.max_edicts) goto LAB_001af140;
      Host_Error("CL_EntityNum: %i is an invalid number, cl.max_edicts is %i",uVar7,cl.max_edicts);
      for (; cl.num_entities <= (int)uVar7; cl.num_entities = cl.num_entities + 1) {
LAB_001af140:
        cl_entities[uVar7].index = uVar7;
      }
    }
    cl_entities[uVar7].index = uVar7;
    pcVar2 = cl_entities;
    uVar8 = MSG_ReadBits(2);
    unaff_ESI = pcVar2 + uVar7;
    if ((uVar8 & 2) == 0) {
      qVar9 = CL_IsPlayerIndex(uVar7);
      if (qVar9 == false) {
        pFields = *ppdVar4;
      }
      else {
        pFields = *ppdVar5;
      }
    }
    else {
      pFields = *ppdVar6;
    }
    DELTA_ParseDelta(auStack_170,(uchar *)&unaff_ESI->baseline,pFields,0x154);
    (unaff_ESI->baseline).entityType = uVar8 & 0xff;
  }
  MSG_ReadBits(0x10);
  Q_memset(cl.instanced_baseline,0,0x5500);
  cl.instanced_baseline_number = MSG_ReadBits(6);
  if (0 < cl.instanced_baseline_number) {
    iVar11 = 0;
    do {
      iVar12 = iVar11 + 1;
      DELTA_ParseDelta(auStack_170,(uchar *)(cl.instanced_baseline + iVar11),*ppdVar4,0x154);
      iVar11 = iVar12;
    } while (iVar12 < cl.instanced_baseline_number);
  }
  MSG_EndBitReading(&net_message);
  uVar3 = 0;
  do {
    uVar10 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0xc));
    *(undefined4 *)((int)(unaff_ESI->curstate).origin + (uVar10 - 0x10)) =
         *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0x10));
    *(undefined4 *)((int)(unaff_ESI->curstate).origin + (uVar10 - 0xc)) = uVar1;
    uVar3 = uVar10 + 8;
  } while (uVar10 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_ESI->curstate).origin + (uVar10 - 8)) =
       *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 8));
  uVar3 = 0;
  do {
    uVar10 = uVar3;
    uVar1 = *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0xc));
    *(undefined4 *)((int)(unaff_ESI->prevstate).origin + (uVar10 - 0x10)) =
         *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 0x10));
    *(undefined4 *)((int)(unaff_ESI->prevstate).origin + (uVar10 - 0xc)) = uVar1;
    uVar3 = uVar10 + 8;
  } while (uVar10 + 8 < 0x150);
  *(undefined4 *)((int)(unaff_ESI->prevstate).origin + (uVar10 - 8)) =
       *(undefined4 *)((int)(unaff_ESI->baseline).origin + (uVar10 - 8));
  return;
}


// CL_Parse_SpawnStatic  @ 00190e30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SpawnStatic(void)

{
  return;
}


// CL_Parse_SpawnStaticSound  @ 00190ee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_SpawnStaticSound(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int entnum;
  int pitch;
  uint flags;
  sfx_t *sfxin;
  sfx_t sStack_70;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
  fStack_28 = MSG_ReadCoord(&net_message);
  fStack_24 = MSG_ReadCoord(&net_message);
  fStack_20 = MSG_ReadCoord(&net_message);
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
    sfxin = &sStack_70;
    snprintf(sfxin->name,0x40,"!%s",rgpszrawsentence[iVar1]);
  }
  S_StartStaticSound(entnum,6,sfxin,&fStack_28,(float)iVar2 / 255.0,(float)iVar3 * 0.015625,flags,
                     pitch);
  return;
}


// CL_Parse_StopSound  @ 00190df0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_StopSound(void)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???] */
  uVar1 = MSG_ReadShort();
  S_StopSound((int)uVar1 >> 3,uVar1 & 7);
  return;
}


// CL_Parse_StuffText  @ 00190c80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_StuffText(void)

{
  char *cmd;
  qboolean qVar1;
  
                    /* Unresolved local var: char * s@[???] */
  cmd = MSG_ReadString();
  qVar1 = ValidStuffText(cmd);
  if (qVar1 != false) {
    Cbuf_AddFilteredText(cmd);
    return;
  }
  Con_Printf("Server tried to send invalid command:\"%s\"\n",cmd);
  return;
}


// CL_Parse_TempEntity  @ 00190e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_TempEntity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  cachewad_t *wad;
  _func_void_cl_entity_s_ptr_int_int_conflict *p_Var5;
  _func_void_TEMPENTITY_ptr_float_int *p_Var6;
  _func_void_TEMPENTITY_ptr_float *p_Var7;
  _func_void_float_ptr_float_float_int_int *p_Var8;
  _func_TEMPENTITY_ptr_float_ptr_float_ptr_float_ptr_float_int_int *p_Var9;
  _func_void_int_int_int_float_ptr_int *p_Var10;
  _func_BEAM_ptr_float_ptr_float_ptr_int_float_float_float_float_float_int_float_float_float_float
  *p_Var11;
  double dVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  texture_t *ptexture;
  int32 iVar19;
  dlight_t_conflict *pdVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  TEMPENTITY *pTVar27;
  customization_s_conflict *pcVar28;
  int unaff_EBP;
  longdouble lVar29;
  longdouble lVar30;
  float fVar31;
  float fVar32;
  int iStack_c4;
  int iStack_a0;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  int aiStack_20 [4];
  
  iVar14 = MSG_ReadByte();
  switch(iVar14) {
  case 0:
  case 1:
  case 8:
    if (iVar14 == 8) {
      unaff_EBP = MSG_ReadShort();
      iStack_a0 = MSG_ReadShort();
    }
    else {
      if (iVar14 == 1) {
        unaff_EBP = MSG_ReadShort();
      }
      else {
        fStack_8c = MSG_ReadCoord(&net_message);
        fStack_88 = MSG_ReadCoord(&net_message);
        fStack_84 = MSG_ReadCoord(&net_message);
      }
      fStack_6c = MSG_ReadCoord(&net_message);
      fStack_68 = MSG_ReadCoord(&net_message);
      fStack_64 = MSG_ReadCoord(&net_message);
    }
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    fVar31 = (float)((longdouble)0.1 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar32 = (float)((longdouble)0.1 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fStack_7c = (float)uVar21;
    iVar17 = MSG_ReadByte();
    fStack_78 = (float)iVar17;
    uVar21 = MSG_ReadByte();
    fVar1 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar2 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar3 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    uVar21 = MSG_ReadByte();
    fVar4 = (float)((longdouble)0.00392156862745098 * (longdouble)uVar21);
    iVar17 = MSG_ReadByte();
    iVar17 = (int)((double)iVar17 * 0.1);
    if (iVar14 == 8) {
      (*efx.R_BeamEnts)(unaff_EBP,iStack_a0,iVar15,fVar32,fStack_7c * 0.1,fStack_78 * 0.01,fVar4,
                        (float)iVar17,iVar16,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar14 == 1) {
      (*efx.R_BeamEntPoint)
                (unaff_EBP,&fStack_6c,iVar15,fVar32,fStack_7c * 0.1,fStack_78 * 0.01,fVar4,
                 (float)iVar17,iVar16,fVar31,fVar1,fVar2,fVar3);
    }
    else if (iVar14 == 0) {
      (*efx.R_BeamPoints)(&fStack_8c,&fStack_6c,iVar15,fVar32,fStack_7c * 0.1,fStack_78 * 0.01,fVar4
                          ,(float)iVar17,iVar16,fVar31,fVar1,fVar2,fVar3);
    }
    break;
  case 2:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    (*efx.R_RunParticleEffect)(&fStack_8c,vec3_origin,0,0x14);
    (*efx.R_RicochetSound)(&fStack_8c);
    break;
  case 3:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    fStack_7c = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    fStack_78 = (float)iVar15;
    uVar21 = MSG_ReadByte();
    fVar31 = fStack_7c;
    p_Var6 = efx.R_Sprite_Explode;
    if (fStack_7c != 0.0) {
      pTVar27 = R_DefaultSprite(&fStack_8c,iVar14,fStack_78);
      (*p_Var6)(pTVar27,fVar31,uVar21);
      if ((uVar21 & 8) == 0) {
        (*efx.R_FlickerParticles)(&fStack_8c);
      }
      if ((uVar21 & 2) == 0) {
        pdVar20 = (*efx.CL_AllocDlight)(0);
        pdVar20->origin[0] = fStack_8c;
        pdVar20->origin[1] = fStack_88;
        pdVar20->radius = 200.0;
        (pdVar20->color).g = 0xfa;
        (pdVar20->color).r = 0xfa;
        pdVar20->origin[2] = fStack_84;
        (pdVar20->color).b = 0x96;
        pdVar20->die = (float)((longdouble)0.01 + (longdouble)cl.time);
        pdVar20->decay = 800.0;
        pdVar20 = (*efx.CL_AllocDlight)(0);
        pdVar20->origin[0] = fStack_8c;
        pdVar20->origin[1] = fStack_88;
        pdVar20->radius = 150.0;
        (pdVar20->color).r = 0xff;
        (pdVar20->color).g = 0xbe;
        pdVar20->origin[2] = fStack_84;
        (pdVar20->color).b = '(';
        pdVar20->die = (float)cl.time + 1.0;
        pdVar20->decay = 200.0;
      }
    }
    if ((uVar21 & 4) != 0) {
      return;
    }
    iVar19 = RandomLong(0,2);
    if (iVar19 == 1) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp2,&fStack_8c,1.0,0.3,0,100);
      return;
    }
    if (iVar19 == 2) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp3,&fStack_8c,1.0,0.3,0,100);
      return;
    }
    if (iVar19 != 0) {
      return;
    }
    fVar31 = 0.3;
    goto LAB_001a99a2;
  case 4:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    (*efx.R_BlobExplosion)(&fStack_8c);
    fVar31 = 1.0;
    goto LAB_001a99a2;
  case 5:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    fStack_7c = (float)iVar15 * 0.1;
    iVar15 = MSG_ReadByte();
    fVar31 = fStack_7c;
    p_Var7 = efx.R_Sprite_Smoke;
    fStack_78 = (float)iVar15;
    pTVar27 = R_DefaultSprite(&fStack_8c,iVar14,fStack_78);
    (*p_Var7)(pTVar27,fVar31);
    break;
  case 6:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    (*efx.R_TracerEffect)(&fStack_8c,&fStack_6c);
    break;
  case 7:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    fStack_7c = (float)iVar15;
    iVar15 = MSG_ReadByte();
    fStack_78 = (float)iVar15;
    iVar15 = MSG_ReadShort();
    (*efx.R_BeamLightning)
              (&fStack_8c,&fStack_6c,iVar15,(float)iVar14 * 0.1,fStack_7c * 0.1,fStack_78 * 0.01,0.6
               ,3.5);
    break;
  case 9:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    (*efx.R_SparkEffect)(&fStack_8c,8,-200,200);
    break;
  case 10:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    (*efx.R_LavaSplash)(&fStack_8c);
    break;
  case 0xb:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    (*efx.R_TeleportSplash)(&fStack_8c);
    break;
  case 0xc:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    (*efx.R_ParticleExplosion2)(&fStack_8c,iVar14,iVar15);
    pdVar20 = (*efx.CL_AllocDlight)(0);
    pdVar20->origin[0] = fStack_8c;
    pdVar20->origin[1] = fStack_88;
    pdVar20->radius = 350.0;
    pdVar20->origin[2] = fStack_84;
    pdVar20->die = (float)cl.time + 0.5;
    pdVar20->decay = 300.0;
    fVar31 = 0.6;
LAB_001a99a2:
    S_StartDynamicSound(-1,0,cl_sfx_r_exp1,&fStack_8c,1.0,fVar31,0,100);
    break;
  case 0xd:
  case 0x68:
  case 0x74:
  case 0x75:
  case 0x76:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    if (iVar14 == 0xd) {
      iVar15 = MSG_ReadShort();
      iVar16 = MSG_ReadShort();
      if (iVar16 == 0) {
        iVar17 = 0;
        iStack_c4 = 1;
      }
      else {
        iVar17 = MSG_ReadShort();
        iStack_c4 = 1;
      }
    }
    else {
      iVar15 = MSG_ReadByte();
      if ((iVar14 == 0x76) || (iVar14 == 0x68)) {
        iVar16 = MSG_ReadShort();
        iVar17 = 0;
        iStack_c4 = 0;
      }
      else {
        iVar16 = 0;
        iStack_c4 = 0;
        iVar17 = 0;
      }
    }
    if (iVar14 - 0x75U < 2) {
      iVar15 = iVar15 + 0x100;
    }
    if (cl.max_edicts <= iVar16) {
      Sys_Error("Decal: entity = %i",iVar16);
    }
    p_Var10 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      iVar14 = (*efx.Draw_DecalIndex)(iVar15);
      (*p_Var10)(iVar14,iVar16,iVar17,&fStack_8c,iStack_c4);
    }
    break;
  case 0xe:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    fStack_7c = (float)iVar14;
    iVar14 = MSG_ReadByte();
    fStack_78 = (float)iVar14;
    iVar14 = MSG_ReadByte();
    fStack_74 = (float)iVar14 / 10.0;
    (*efx.R_Implosion)(&fStack_8c,fStack_7c,(int)fStack_78,fStack_74);
    break;
  case 0xf:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    if ((longdouble)uVar22 == (longdouble)0) {
      fStack_7c = 1.0;
    }
    else {
      fStack_7c = (float)((longdouble)0.1 * (longdouble)uVar22);
    }
    iVar16 = MSG_ReadByte();
    fStack_78 = (float)iVar16 * 10.0;
    iVar16 = MSG_ReadByte();
    (*efx.R_Sprite_Trail)
              (0xf,&fStack_8c,&fStack_6c,iVar14,iVar15,(float)((longdouble)0.1 * (longdouble)uVar21)
               ,fStack_7c,fStack_78,0xff,(float)(int)((double)iVar16 * 10.0));
    break;
  default:
    Sys_Error("CL_ParseTEnt: bad type");
    break;
  case 0x11:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    fStack_7c = (float)iVar15 * 0.1;
    uVar21 = MSG_ReadByte();
    iVar17 = 0x100;
    fVar31 = 0.0;
    iVar16 = 0;
    iVar15 = 5;
    lVar29 = (longdouble)0.00392156862745098 * (longdouble)uVar21;
    goto LAB_001a912f;
  case 0x12:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    p_Var11 = efx.R_BeamPoints;
    fVar31 = RandomFloat(0.5,0.655);
    (*p_Var11)(&fStack_8c,&fStack_6c,iVar14,0.01,0.4,0.0,fVar31,5.0,0,0.0,1.0,0.0,0.0);
    (*efx.R_TempSprite)(&fStack_6c,vec3_origin,0.1,iVar15,5,0,0.35,0.01,0);
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    fStack_7c = (float)uVar23;
    iVar17 = MSG_ReadByte();
    fStack_78 = (float)iVar17;
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamCirclePoints)
              (iVar14,&fStack_8c,&fStack_6c,iVar15,(float)((longdouble)uVar22 * lVar30),fStack_7c,
               fStack_78 * 0.01,(float)((longdouble)uVar26 * lVar29),
               (float)(int)(lVar30 * (longdouble)iVar17),iVar16,(float)((longdouble)uVar21 * lVar30)
               ,(float)((longdouble)uVar23 * lVar29),(float)((longdouble)uVar24 * lVar29),
               (float)((longdouble)uVar25 * lVar29));
    break;
  case 0x16:
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    fStack_7c = (float)uVar22;
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    (*efx.R_BeamFollow)(iVar14,iVar15,(float)((longdouble)0.1 * (longdouble)uVar21),fStack_7c,
                        (float)((longdouble)uVar22 * lVar29),(float)((longdouble)uVar23 * lVar29),
                        (float)((longdouble)uVar24 * lVar29),(float)((longdouble)uVar25 * lVar29));
    break;
  case 0x17:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    uVar21 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    fStack_7c = (float)iVar15 * 0.1;
    uVar22 = MSG_ReadByte();
    iVar17 = 0x80;
    iVar16 = 0xe;
    iVar15 = 3;
    fVar31 = (float)((longdouble)0.10000000149011612 * (longdouble)uVar21);
    lVar29 = (longdouble)0.00392156862745098 * (longdouble)uVar22;
LAB_001a912f:
    (*efx.R_TempSprite)(&fStack_8c,vec3_origin,fStack_7c,iVar14,iVar15,iVar16,(float)lVar29,fVar31,
                        iVar17);
    break;
  case 0x18:
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadByte();
    uVar21 = MSG_ReadByte();
    uVar22 = MSG_ReadByte();
    uVar23 = MSG_ReadByte();
    fStack_7c = (float)uVar23;
    iVar18 = MSG_ReadByte();
    fStack_78 = (float)iVar18;
    uVar23 = MSG_ReadByte();
    uVar24 = MSG_ReadByte();
    uVar25 = MSG_ReadByte();
    uVar26 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    lVar29 = (longdouble)0.00392156862745098;
    lVar30 = (longdouble)0.1;
    (*efx.R_BeamRing)(iVar14,iVar15,iVar16,(float)((longdouble)uVar22 * lVar30),
                      (float)(lVar30 * (longdouble)fStack_7c),fStack_78 * 0.01,
                      (float)((longdouble)uVar26 * lVar29),(float)(int)(lVar30 * (longdouble)iVar18)
                      ,iVar17,(float)((longdouble)uVar21 * lVar30),
                      (float)((longdouble)uVar23 * lVar29),(float)((longdouble)uVar24 * lVar29),
                      (float)((longdouble)uVar25 * lVar29));
    break;
  case 0x19:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    iVar17 = MSG_ReadShort();
    (*efx.R_StreakSplash)(&fStack_8c,&fStack_2c,iVar14,iVar15,(float)iVar16,-iVar17,iVar17);
    break;
  case 0x1b:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    pdVar20 = (*efx.CL_AllocDlight)(0);
    pdVar20->origin[0] = fStack_8c;
    pdVar20->origin[1] = fStack_88;
    pdVar20->origin[2] = fStack_84;
    iVar14 = MSG_ReadByte();
    pdVar20->radius = (float)(iVar14 * 10);
    iVar14 = MSG_ReadByte();
    (pdVar20->color).r = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).g = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).b = (byte)iVar14;
    dVar12 = cl.time;
    iVar14 = MSG_ReadByte();
    pdVar20->die = (float)iVar14 * 0.1 + (float)dVar12;
    iVar14 = MSG_ReadByte();
    pdVar20->decay = (float)(iVar14 * 10);
    break;
  case 0x1c:
    iVar14 = MSG_ReadShort();
    pdVar20 = (*efx.CL_AllocElight)(iVar14);
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->origin[0] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->origin[1] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->origin[2] = fVar31;
    fVar31 = MSG_ReadCoord(&net_message);
    pdVar20->radius = fVar31;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).r = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).g = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    (pdVar20->color).b = (byte)iVar14;
    iVar14 = MSG_ReadByte();
    fVar31 = (float)iVar14 * 0.1;
    pdVar20->die = fVar31 + (float)cl.time;
    fVar32 = MSG_ReadCoord(&net_message);
    pdVar20->decay = fVar32;
    if (fVar31 != 0.0) {
      pdVar20->decay = fVar32 / fVar31;
    }
    break;
  case 0x1d:
    CL_ParseTextMessage();
    break;
  case 0x1e:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    fStack_7c = (float)iVar14 * 0.1;
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    fVar31 = fStack_7c;
    sVar13 = R_LookupColor((uchar)iVar14,(uchar)iVar15,(uchar)iVar16);
    PM_ParticleLine(&fStack_8c,&fStack_6c,(int)sVar13,fVar31,0.0);
    break;
  case 0x1f:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    fStack_7c = (float)iVar14 * 0.1;
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    fVar31 = fStack_7c;
    sVar13 = R_LookupColor((uchar)iVar14,(uchar)iVar15,(uchar)iVar16);
    fStack_3c = (fStack_6c + fStack_8c) * 0.5;
    fStack_4c = fStack_6c - fStack_3c;
    fStack_5c = fStack_8c - fStack_3c;
    fStack_38 = (fStack_68 + fStack_88) * 0.5;
    fStack_48 = fStack_68 - fStack_38;
    fStack_58 = fStack_88 - fStack_38;
    fStack_34 = (fStack_64 + fStack_84) * 0.5;
    fStack_44 = fStack_64 - fStack_34;
    fStack_54 = fStack_84 - fStack_34;
    PM_DrawBBox(&fStack_5c,&fStack_4c,&fStack_3c,(int)sVar13,fVar31);
    break;
  case 99:
    iVar14 = MSG_ReadShort();
    (*efx.R_BeamKill)(iVar14);
    break;
  case 100:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    (*efx.R_LargeFunnel)(&fStack_8c,iVar15);
    (*efx.R_FunnelSprite)(&fStack_8c,iVar14,iVar15);
    break;
  case 0x65:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodStream)(&fStack_8c,&fStack_2c,iVar14,iVar15);
    }
    break;
  case 0x66:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    (*efx.R_ShowLine)(&fStack_8c,&fStack_6c);
    break;
  case 0x67:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_Blood)(&fStack_8c,&fStack_2c,iVar14,iVar15);
    }
    break;
  case 0x69:
    iVar14 = MSG_ReadShort();
    if (cl.max_edicts <= iVar14) {
      Sys_Error("Bubble: entity = %i",iVar14);
    }
    iVar15 = MSG_ReadShort();
    p_Var5 = efx.R_FizzEffect;
    iVar16 = MSG_ReadByte();
    (*p_Var5)((cl_entity_s_conflict *)(cl_entities + iVar14),iVar15,iVar16);
    break;
  case 0x6a:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_6c = 0.0;
    fStack_68 = MSG_ReadAngle();
    fStack_64 = 0.0;
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    p_Var9 = efx.R_TempModel;
    iVar16 = MSG_ReadByte();
    (*p_Var9)(&fStack_8c,&fStack_2c,&fStack_6c,(float)iVar16 * 0.1,iVar14,iVar15);
    break;
  case 0x6b:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    p_Var8 = efx.R_TempSphereModel;
    iVar16 = MSG_ReadByte();
    (*p_Var8)(&fStack_8c,fStack_2c,(float)iVar16 * 0.1,iVar15,iVar14);
    break;
  case 0x6c:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_7c = MSG_ReadCoord(&net_message);
    fStack_78 = MSG_ReadCoord(&net_message);
    fStack_74 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_BreakModel)(&fStack_8c,&fStack_7c,&fStack_2c,(float)iVar14 * 10.0,(float)iVar17 * 0.1,
                        iVar16,iVar15,(char)iVar18);
    break;
  case 0x6d:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    (*efx.R_BulletImpactParticles)(&fStack_8c);
    iVar19 = RandomLong(0,0x7fff);
    if (iVar19 < 0x3fff) {
      switch(iVar19 % 5) {
      case 0:
        S_StartDynamicSound(-1,0,cl_sfx_ric1,&fStack_8c,1.0,1.0,0,100);
        break;
      case 1:
        S_StartDynamicSound(-1,0,cl_sfx_ric2,&fStack_8c,1.0,1.0,0,100);
        break;
      case 2:
        S_StartDynamicSound(-1,0,cl_sfx_ric3,&fStack_8c,1.0,1.0,0,100);
        break;
      case 3:
        S_StartDynamicSound(-1,0,cl_sfx_ric4,&fStack_8c,1.0,1.0,0,100);
        break;
      case 4:
        S_StartDynamicSound(-1,0,cl_sfx_ric5,&fStack_8c,1.0,1.0,0,100);
      }
    }
    if (cl.max_edicts <= iVar14) {
      Sys_Error("Decal: entity = %i",iVar14);
    }
    p_Var10 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      iVar15 = (*efx.Draw_DecalIndex)(iVar15);
      (*p_Var10)(iVar15,iVar14,0,&fStack_8c,0);
    }
    break;
  case 0x6e:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_Sprite_Spray)(&fStack_8c,&fStack_2c,iVar14,iVar15,iVar16 * 2,iVar17);
    break;
  case 0x6f:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    fStack_7c = (float)iVar14 * 0.1;
    (*efx.R_RicochetSprite)(&fStack_8c,cl_sprite_ricochet,0.1,fStack_7c);
    (*efx.R_RicochetSound)(&fStack_8c);
    break;
  case 0x70:
    iVar14 = MSG_ReadByte();
    pcVar28 = (customization_s_conflict *)0x0;
    if (iVar14 - 1U < 0x20) {
      pcVar28 = cl.players[iVar14 + -1].customdata.pNext;
    }
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar16 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    if (cl.max_edicts <= iVar16) {
      Sys_Error("Decal: entity = %i",iVar16);
    }
    ptexture = (texture_t *)0x0;
    if (((((pcVar28 != (customization_s_conflict *)0x0) && (pcVar28->pBuffer != (void *)0x0)) &&
         (wad = pcVar28->pInfo, wad != (cachewad_t *)0x0)) &&
        ((((pcVar28->resource).ucFlags & 4) != 0 && ((pcVar28->resource).type == t_decal)))) &&
       (pcVar28->bTranslated != 0)) {
      iVar17 = wad->lumpCount + -1;
      if (iVar17 < iVar15) {
        iVar15 = iVar17;
      }
      pcVar28->nUserData1 = iVar15;
      ptexture = Draw_CustomCacheGet(wad,pcVar28->pBuffer,(pcVar28->resource).nDownloadSize,iVar15);
    }
    p_Var10 = efx.R_DecalShoot;
    if (r_decals.value != 0.0) {
      if (pcVar28 == (customization_s_conflict *)0x0) {
        iVar14 = (*efx.Draw_DecalIndex)(iVar15);
        (*p_Var10)(iVar14,iVar16,0,&fStack_8c,4);
      }
      else if (ptexture != (texture_t *)0x0) {
        R_CustomDecalShoot(ptexture,iVar14 - 1U,iVar16,0,&fStack_8c,4);
      }
    }
    break;
  case 0x71:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_7c = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    fStack_78 = MSG_ReadCoord(&net_message);
    (*efx.R_Bubbles)(&fStack_8c,&fStack_6c,fStack_7c,iVar14,iVar15,fStack_78);
    break;
  case 0x72:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_6c = MSG_ReadCoord(&net_message);
    fStack_68 = MSG_ReadCoord(&net_message);
    fStack_64 = MSG_ReadCoord(&net_message);
    fStack_7c = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    fStack_78 = MSG_ReadCoord(&net_message);
    (*efx.R_BubbleTrail)(&fStack_8c,&fStack_6c,fStack_7c,iVar14,iVar15,fStack_78);
    break;
  case 0x73:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    fStack_7c = (float)iVar17;
    if ((violence_hblood.value != 0.0) || (violence_ablood.value != 0.0)) {
      (*efx.R_BloodSprite)(&fStack_8c,iVar16,iVar14,iVar15,fStack_7c);
    }
    break;
  case 0x77:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_Projectile)(&fStack_8c,&fStack_2c,iVar14,(int)(float)iVar15,iVar16,
                        (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0);
    break;
  case 0x78:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_Spray)(&fStack_8c,&fStack_2c,iVar14,iVar15,iVar16,iVar17,iVar18);
    break;
  case 0x79:
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    (*efx.R_PlayerSprites)(iVar14,iVar15,iVar16,iVar17);
    break;
  case 0x7a:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_ParticleBurst)(&fStack_8c,iVar14,iVar15,(float)iVar16 / 10.0);
    break;
  case 0x7b:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadShort();
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadByte();
    iVar17 = MSG_ReadByte();
    iVar18 = MSG_ReadByte();
    (*efx.R_FireField)(&fStack_8c,iVar14,iVar15,iVar16,iVar17,(float)iVar18 / 10.0);
    break;
  case 0x7c:
    iVar14 = MSG_ReadByte();
    fVar31 = MSG_ReadCoord(&net_message);
    iVar15 = MSG_ReadShort();
    iVar16 = MSG_ReadShort();
    (*efx.R_AttachTentToPlayer)(iVar14,iVar15,fVar31,(float)iVar16 / 10.0);
    break;
  case 0x7d:
    iVar14 = MSG_ReadByte();
    (*efx.R_KillAttachedTents)(iVar14);
    break;
  case 0x7e:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_2c = fStack_2c / 10.0;
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_28 = fStack_28 / 10.0;
    fStack_24 = MSG_ReadCoord(&net_message);
    fStack_24 = fStack_24 / 10.0;
    fStack_7c = MSG_ReadCoord(&net_message);
    fStack_78 = MSG_ReadCoord(&net_message);
    fStack_74 = 0.0;
    fStack_7c = fStack_7c / 100.0;
    fStack_78 = fStack_78 / 100.0;
    iVar14 = MSG_ReadByte();
    aiStack_20[0] = MSG_ReadByte();
    (*efx.R_MultiGunshot)(&fStack_8c,&fStack_2c,&fStack_7c,iVar14,1,aiStack_20);
    break;
  case 0x7f:
    fStack_8c = MSG_ReadCoord(&net_message);
    fStack_88 = MSG_ReadCoord(&net_message);
    fStack_84 = MSG_ReadCoord(&net_message);
    fStack_2c = MSG_ReadCoord(&net_message);
    fStack_28 = MSG_ReadCoord(&net_message);
    fStack_24 = MSG_ReadCoord(&net_message);
    iVar14 = MSG_ReadByte();
    iVar15 = MSG_ReadByte();
    iVar16 = MSG_ReadByte();
    (*efx.R_UserTracerParticle)
              (&fStack_8c,&fStack_2c,(float)iVar14 / 10.0,iVar15,(float)iVar16 / 10.0,'\0',
               (_func_void_particle_s_ptr *)0x0);
  }
  return;
}


// CL_Parse_Time  @ 0018ff60
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
    if (dVar1 != 0.0) {
      g_clockdelta = dVar1;
    }
  }
  else {
    cl.time = (double)fVar2;
    g_clockdelta = 0.0;
  }
  if (cl.time < cl.oldtime) {
    cl.oldtime = cl.time;
  }
  return;
}


// CL_Parse_Timescale  @ 00191bf0
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


// CL_Parse_UpdateUserInfo  @ 00191040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_UpdateUserInfo(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *dest;
  uint64 uVar5;
  
  iVar2 = MSG_ReadByte();
  if (0x1f < iVar2) {
    Host_EndGame("CL_ParseServerMessage: svc_updateuserinfo > MAX_CLIENTS");
  }
  iVar3 = MSG_ReadLong();
  cl.players[iVar2].userid = iVar3;
  dest = cl.players[iVar2].userinfo;
  pcVar4 = MSG_ReadString();
  Q_strncpy(dest,pcVar4,0xff);
  cl.players[iVar2].userinfo[0xff] = '\0';
  MSG_ReadBuf(0x10,cl.players[iVar2].hashedcdkey);
  pcVar4 = Info_ValueForKey(dest,"name");
  Q_strncpy(cl.players[iVar2].name,pcVar4,0x1f);
  cl.players[iVar2].name[0x1f] = '\0';
  pcVar4 = Info_ValueForKey(dest,"model");
  Q_strncpy(cl.players[iVar2].model,pcVar4,0x3f);
  cl.players[iVar2].model[0x3f] = '\0';
  pcVar4 = Info_ValueForKey(dest,"topcolor");
  iVar3 = Q_atoi(pcVar4);
  cl.players[iVar2].topcolor = iVar3;
  pcVar4 = Info_ValueForKey(dest,"bottomcolor");
  iVar3 = Q_atoi(pcVar4);
  cl.players[iVar2].bottomcolor = iVar3;
  pcVar4 = Info_ValueForKey(dest,"*hltv");
  iVar3 = Q_atoi(pcVar4);
  cl.players[iVar2].spectator = iVar3;
  pcVar4 = Info_ValueForKey(dest,"*sid");
  uVar5 = strtoll(pcVar4,(char **)0x0,10);
  cVar1 = cl.players[iVar2].userinfo[0];
  cl.players[iVar2].m_nSteamID = uVar5;
  if ((cVar1 == '\0') || (cl.players[iVar2].name[0] == '\0')) {
    COM_ClearCustomizationList((customization_t *)&cl.players[iVar2].customdata,true);
  }
  return;
}


// CL_Parse_Version  @ 00190240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_Version(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = MSG_ReadLong();
  if (iVar1 != 0x30) {
    Host_Error("CL_Parse_Version: Server is protocol %i instead of %i\n",iVar1,0x30);
  }
  return;
}


// CL_Parse_VoiceData  @ 00191c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_VoiceData(void)

{
  int nEntity;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint iSize;
  char local_201c [8204];
  
                    /* Unresolved local var: int iEntity@[???]
                       Unresolved local var: int nDataLength@[???]
                       Unresolved local var: int nChannel@[???]
                       Unresolved local var: char[8192] chReceived@[???]
                       Unresolved local var: int startReadCount@[???] */
  iVar3 = msg_readcount;
  iVar1 = MSG_ReadByte();
  nEntity = iVar1 + 1;
  uVar2 = MSG_ReadShort();
  iSize = 0x2000;
  if (uVar2 < 0x2001) {
    iSize = uVar2;
  }
  MSG_ReadBuf(iSize,local_201c);
  cl.frames[cl.parsecountmod].voicebytes =
       (cl.frames[cl.parsecountmod].voicebytes + (short)msg_readcount) - (short)iVar3;
  if ((-1 < nEntity) && (nEntity < cl.num_entities)) {
    if (cl.playernum + 1 == nEntity) {
      Voice_LocalPlayerTalkingAck();
    }
    if (iSize != 0) {
      iVar3 = Voice_GetChannel(nEntity);
      if ((iVar3 == -1) && (iVar3 = Voice_AssignChannel(nEntity), iVar3 == -1)) {
        Con_DPrintf("CL_ParseVoiceData: Voice_AssignChannel failed for client %d!\n",iVar1);
        return;
      }
      Voice_AddIncomingData(iVar3,local_201c,iSize,cls.netchan.incoming_sequence);
    }
  }
  return;
}


// CL_Parse_VoiceInit  @ 00191c30
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


// CL_Parse_WeaponAnim  @ 00190fa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Parse_WeaponAnim(void)

{
  cl.weaponstarttime = 0.0;
  cl.weaponsequence = MSG_ReadByte();
  cl.viewent.curstate.body = MSG_ReadByte();
  return;
}


// CL_Particle  @ 0018d3d0
void CL_Particle(vec_t *origin,int color,float life,int zpos,int zvel)

{
  particle_s **pppVar1;
  float fVar2;
  vec_t vVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  
  ppVar5 = free_particles;
                    /* Unresolved local var: particle_t * active_particles@[???]
                       Unresolved local var: particle_t * free_particles@[???]
                       Unresolved local var: particle_t * p@[???] */
  ppVar4 = active_particles;
  if (free_particles != (particle_t *)0x0) {
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar4;
    ppVar5->die = life + (float)cl.time;
    ppVar5->color = (short)color;
    vVar3 = vec3_origin[0];
    ppVar5->packedColor = 0;
    fVar2 = (float)zvel + vec3_origin[2];
    ppVar5->type = pt_static;
    ppVar5->vel[0] = vVar3;
    vVar3 = vec3_origin[1];
    ppVar5->vel[2] = fVar2;
    ppVar5->vel[1] = vVar3;
    ppVar5->org[0] = *origin;
    ppVar5->org[1] = origin[1];
    ppVar5->org[2] = (float)zpos + origin[2];
  }
  return;
}


// CL_PingServers_f  @ 0019baa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PingServers_f(void)

{
  netadr_t adr;
  netadr_t adr_00;
  netadr_t adr_01;
  netadr_t adr_02;
  netadr_t adr_03;
  netadr_t adr_04;
  netadr_t adr_05;
  netadr_t adr_06;
  netadr_t adr_07;
  netadr_t adr_08;
  _func_short_short *p_Var1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: netadr_t adr@[???] */
  Con_Printf("Searching for local servers...\n");
  cls.slist_time = (float)realtime;
  NET_Config(true);
  Q_memset(&local_20,0,0x14);
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr.ip[0] = (undefined1)local_1c;
    adr.ip[1] = local_1c._1_1_;
    adr.ip[2] = local_1c._2_1_;
    adr.ip[3] = local_1c._3_1_;
    adr.type = 2;
    adr.ipx[0] = (undefined1)local_18;
    adr.ipx[1] = local_18._1_1_;
    adr.ipx[2] = local_18._2_1_;
    adr.ipx[3] = local_18._3_1_;
    adr.ipx[4] = (undefined1)local_14;
    adr.ipx[5] = local_14._1_1_;
    adr.ipx[6] = local_14._2_1_;
    adr.ipx[7] = local_14._3_1_;
    adr.ipx[8] = (undefined1)local_10;
    adr.ipx[9] = local_10._1_1_;
    adr.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 1);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_08.ip[0] = (undefined1)local_1c;
    adr_08.ip[1] = local_1c._1_1_;
    adr_08.ip[2] = local_1c._2_1_;
    adr_08.ip[3] = local_1c._3_1_;
    adr_08.type = 2;
    adr_08.ipx[0] = (undefined1)local_18;
    adr_08.ipx[1] = local_18._1_1_;
    adr_08.ipx[2] = local_18._2_1_;
    adr_08.ipx[3] = local_18._3_1_;
    adr_08.ipx[4] = (undefined1)local_14;
    adr_08.ipx[5] = local_14._1_1_;
    adr_08.ipx[6] = local_14._2_1_;
    adr_08.ipx[7] = local_14._3_1_;
    adr_08.ipx[8] = (undefined1)local_10;
    adr_08.ipx[9] = local_10._1_1_;
    adr_08.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_08,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 2);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_07.ip[0] = (undefined1)local_1c;
    adr_07.ip[1] = local_1c._1_1_;
    adr_07.ip[2] = local_1c._2_1_;
    adr_07.ip[3] = local_1c._3_1_;
    adr_07.type = 2;
    adr_07.ipx[0] = (undefined1)local_18;
    adr_07.ipx[1] = local_18._1_1_;
    adr_07.ipx[2] = local_18._2_1_;
    adr_07.ipx[3] = local_18._3_1_;
    adr_07.ipx[4] = (undefined1)local_14;
    adr_07.ipx[5] = local_14._1_1_;
    adr_07.ipx[6] = local_14._2_1_;
    adr_07.ipx[7] = local_14._3_1_;
    adr_07.ipx[8] = (undefined1)local_10;
    adr_07.ipx[9] = local_10._1_1_;
    adr_07.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_07,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 3);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_06.ip[0] = (undefined1)local_1c;
    adr_06.ip[1] = local_1c._1_1_;
    adr_06.ip[2] = local_1c._2_1_;
    adr_06.ip[3] = local_1c._3_1_;
    adr_06.type = 2;
    adr_06.ipx[0] = (undefined1)local_18;
    adr_06.ipx[1] = local_18._1_1_;
    adr_06.ipx[2] = local_18._2_1_;
    adr_06.ipx[3] = local_18._3_1_;
    adr_06.ipx[4] = (undefined1)local_14;
    adr_06.ipx[5] = local_14._1_1_;
    adr_06.ipx[6] = local_14._2_1_;
    adr_06.ipx[7] = local_14._3_1_;
    adr_06.ipx[8] = (undefined1)local_10;
    adr_06.ipx[9] = local_10._1_1_;
    adr_06.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_06,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 4);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_05.ip[0] = (undefined1)local_1c;
    adr_05.ip[1] = local_1c._1_1_;
    adr_05.ip[2] = local_1c._2_1_;
    adr_05.ip[3] = local_1c._3_1_;
    adr_05.type = 2;
    adr_05.ipx[0] = (undefined1)local_18;
    adr_05.ipx[1] = local_18._1_1_;
    adr_05.ipx[2] = local_18._2_1_;
    adr_05.ipx[3] = local_18._3_1_;
    adr_05.ipx[4] = (undefined1)local_14;
    adr_05.ipx[5] = local_14._1_1_;
    adr_05.ipx[6] = local_14._2_1_;
    adr_05.ipx[7] = local_14._3_1_;
    adr_05.ipx[8] = (undefined1)local_10;
    adr_05.ipx[9] = local_10._1_1_;
    adr_05.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_05,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 5);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_04.ip[0] = (undefined1)local_1c;
    adr_04.ip[1] = local_1c._1_1_;
    adr_04.ip[2] = local_1c._2_1_;
    adr_04.ip[3] = local_1c._3_1_;
    adr_04.type = 2;
    adr_04.ipx[0] = (undefined1)local_18;
    adr_04.ipx[1] = local_18._1_1_;
    adr_04.ipx[2] = local_18._2_1_;
    adr_04.ipx[3] = local_18._3_1_;
    adr_04.ipx[4] = (undefined1)local_14;
    adr_04.ipx[5] = local_14._1_1_;
    adr_04.ipx[6] = local_14._2_1_;
    adr_04.ipx[7] = local_14._3_1_;
    adr_04.ipx[8] = (undefined1)local_10;
    adr_04.ipx[9] = local_10._1_1_;
    adr_04.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_04,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 6);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_03.ip[0] = (undefined1)local_1c;
    adr_03.ip[1] = local_1c._1_1_;
    adr_03.ip[2] = local_1c._2_1_;
    adr_03.ip[3] = local_1c._3_1_;
    adr_03.type = 2;
    adr_03.ipx[0] = (undefined1)local_18;
    adr_03.ipx[1] = local_18._1_1_;
    adr_03.ipx[2] = local_18._2_1_;
    adr_03.ipx[3] = local_18._3_1_;
    adr_03.ipx[4] = (undefined1)local_14;
    adr_03.ipx[5] = local_14._1_1_;
    adr_03.ipx[6] = local_14._2_1_;
    adr_03.ipx[7] = local_14._3_1_;
    adr_03.ipx[8] = (undefined1)local_10;
    adr_03.ipx[9] = local_10._1_1_;
    adr_03.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_03,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 7);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_02.ip[0] = (undefined1)local_1c;
    adr_02.ip[1] = local_1c._1_1_;
    adr_02.ip[2] = local_1c._2_1_;
    adr_02.ip[3] = local_1c._3_1_;
    adr_02.type = 2;
    adr_02.ipx[0] = (undefined1)local_18;
    adr_02.ipx[1] = local_18._1_1_;
    adr_02.ipx[2] = local_18._2_1_;
    adr_02.ipx[3] = local_18._3_1_;
    adr_02.ipx[4] = (undefined1)local_14;
    adr_02.ipx[5] = local_14._1_1_;
    adr_02.ipx[6] = local_14._2_1_;
    adr_02.ipx[7] = local_14._3_1_;
    adr_02.ipx[8] = (undefined1)local_10;
    adr_02.ipx[9] = local_10._1_1_;
    adr_02.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_02,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 8);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip == false) {
    local_20 = 2;
    adr_01.ip[0] = (undefined1)local_1c;
    adr_01.ip[1] = local_1c._1_1_;
    adr_01.ip[2] = local_1c._2_1_;
    adr_01.ip[3] = local_1c._3_1_;
    adr_01.type = 2;
    adr_01.ipx[0] = (undefined1)local_18;
    adr_01.ipx[1] = local_18._1_1_;
    adr_01.ipx[2] = local_18._2_1_;
    adr_01.ipx[3] = local_18._3_1_;
    adr_01.ipx[4] = (undefined1)local_14;
    adr_01.ipx[5] = local_14._1_1_;
    adr_01.ipx[6] = local_14._2_1_;
    adr_01.ipx[7] = local_14._3_1_;
    adr_01.ipx[8] = (undefined1)local_10;
    adr_01.ipx[9] = local_10._1_1_;
    adr_01.port = sVar3;
    local_10 = uVar2;
    Netchan_OutOfBandPrint(NS_CLIENT,adr_01,"%c%s",0x54,"Source Engine Query");
  }
  p_Var1 = BigShort;
  iVar4 = Q_atoi("27015");
  sVar3 = (*p_Var1)((short)iVar4 + 9);
  local_10 = CONCAT22(sVar3,(undefined2)local_10);
  uVar2 = local_10;
  if (noip != false) {
    return;
  }
  local_20 = 2;
  adr_00.ip[0] = (undefined1)local_1c;
  adr_00.ip[1] = local_1c._1_1_;
  adr_00.ip[2] = local_1c._2_1_;
  adr_00.ip[3] = local_1c._3_1_;
  adr_00.type = 2;
  adr_00.ipx[0] = (undefined1)local_18;
  adr_00.ipx[1] = local_18._1_1_;
  adr_00.ipx[2] = local_18._2_1_;
  adr_00.ipx[3] = local_18._3_1_;
  adr_00.ipx[4] = (undefined1)local_14;
  adr_00.ipx[5] = local_14._1_1_;
  adr_00.ipx[6] = local_14._2_1_;
  adr_00.ipx[7] = local_14._3_1_;
  adr_00.ipx[8] = (undefined1)local_10;
  adr_00.ipx[9] = local_10._1_1_;
  adr_00.port = sVar3;
  local_10 = uVar2;
  Netchan_OutOfBandPrint(NS_CLIENT,adr_00,"%c%s",0x54,"Source Engine Query");
  return;
}


// CL_PlayDemo_f  @ 00195900
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PlayDemo_f(void)

{
  netadr_t adr;
  int iVar1;
  char *pcVar2;
  char local_10c [264];
  
                    /* Unresolved local var: char[256] name@[???] */
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
  Q_strncpy(local_10c,pcVar2,0xfb);
  COM_DefaultExtension(local_10c,".dem");
  Con_Printf("Playing demo from %s.\n",local_10c);
  cls.demofile = FS_Open(local_10c,"rb");
  if (cls.demofile == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open.\n");
    cls.demonum = -1;
    return;
  }
  FS_Read(&demoheader,0x220,1,cls.demofile);
  iVar1 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
  if (iVar1 != 0) {
    Con_Printf("%s is not a demo file\n",local_10c);
    FS_Close(cls.demofile);
    cls.demofile = (FileHandle_t)0x0;
    cls.demonum = -1;
    return;
  }
  if ((demoheader.nNetProtocolVersion != 0x30) || (demoheader.nDemoProtocol != 5)) {
    Con_Printf("WARNING! demo protocol outdated.\nDemo file protocols %i:%i, Engine protocol is at %i:%i\n"
               ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
  }
  FS_Seek(cls.demofile,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
  FS_Read(&demodir,4,1,cls.demofile);
  if (0x3ff < demodir.nEntries - 1U) {
    COM_ExplainDisconnection(true,"Error: Corrupt demo file.");
    FS_Close(cls.demofile);
    cls.demofile = (FileHandle_t)0x0;
    cls.demonum = -1;
    CL_Disconnect();
    return;
  }
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
  return;
}


// CL_PlayDemo_f  @ 0019a200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PlayDemo_f(void)

{
  int iVar1;
  
                    /* Unresolved local var: char[256] name@[???] */
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if ((iVar1 != 2) && (iVar1 = Cmd_Argc(), iVar1 != 3)) {
    Con_Printf("playdemo <demoname> <replayspeed>: plays a demo\n");
    Con_Printf("replayspeed == 1.0 default\n");
    return;
  }
  CL_PlayDemo_f();
  return;
}


// CL_PlayerDropped  @ 001abcd0
void CL_PlayerDropped(int nPlayerNumber)

{
  COM_ClearCustomizationList((customization_t *)&cl.players[nPlayerNumber].customdata,true);
  return;
}


// CL_PlayerFlashlight  @ 0018d480
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_PlayerFlashlight(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  cl_entity_t *pcVar4;
  dlight_t *veca;
  uint uVar5;
  byte bVar6;
  int iVar7;
  pmtrace_t local_6c;
  vec_t local_24 [3];
  vec_t local_18 [3];
  
                    /* Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  pcVar4 = cl_entities;
  iVar7 = cl.playernum + 1;
  uVar5 = cl_entities[iVar7].curstate.effects;
  if (((uVar5 & 0xc) == 0) || (cl.worldmodel == (model_s *)0x0)) {
    if ((cl.pLight != (dlight_t *)0x0) && ((cl.pLight)->key == 1)) {
      (cl.pLight)->die = (float)cl.time;
    }
    cl.pLight = (dlight_t *)0x0;
  }
  else {
    if ((cl.pLight == (dlight_t *)0x0) || (veca = cl.pLight, (cl.pLight)->key != 1)) {
      veca = (dlight_t *)(*efx.CL_AllocDlight)(1);
      uVar5 = pcVar4[iVar7].curstate.effects;
    }
    if ((uVar5 & 4) == 0) {
                    /* Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: float falloff@[???]
                       Unresolved local var: vec3_t vecForward@[???] */
      AngleVectors(r_playerViewportAngles,local_18,(vec_t *)0x0,(vec_t *)0x0);
      fVar1 = pcVar4[iVar7].origin[0];
      veca->origin[0] = fVar1;
      fVar2 = pcVar4[iVar7].origin[1];
      veca->origin[1] = fVar2;
      fVar3 = pcVar4[iVar7].origin[2];
      veca->origin[2] = fVar3;
      veca->origin[0] = fVar1 + cl.viewheight[0];
      veca->origin[1] = fVar2 + cl.viewheight[1];
      veca->origin[2] = fVar3 + cl.viewheight[2];
      VectorMA(veca->origin,2000.0,local_18,local_24);
      pmove->usehull = 2;
      PM_PlayerTrace(&local_6c,veca->origin,local_24,2,-1);
      if ((0 < local_6c.ent) && (pmove->physents[local_6c.ent].studiomodel != (model_s *)0x0)) {
        local_6c.endpos[0] = pmove->physents[local_6c.ent].origin[0];
        local_6c.endpos[1] = pmove->physents[local_6c.ent].origin[1];
        local_6c.endpos[2] = pmove->physents[local_6c.ent].origin[2];
      }
      veca->origin[2] = local_6c.endpos[2];
      bVar6 = 0xff;
      veca->origin[0] = local_6c.endpos[0];
      veca->origin[1] = local_6c.endpos[1];
      if (500.0 <= local_6c.fraction * 2000.0) {
        fVar1 = 500.0 / (local_6c.fraction * 2000.0);
        bVar6 = (byte)(int)(fVar1 * fVar1 * 255.0);
      }
      veca->radius = 80.0;
      (veca->color).b = bVar6;
      (veca->color).g = bVar6;
      (veca->color).r = bVar6;
    }
    else {
      (veca->color).b = 0xfa;
      (veca->color).g = 0xfa;
      (veca->color).r = 0xfa;
      veca->radius = 400.0;
      veca->origin[0] = pcVar4[iVar7].origin[0];
      veca->origin[1] = pcVar4[iVar7].origin[1];
      veca->origin[2] = pcVar4[iVar7].origin[2] + 16.0;
    }
    cl.pLight = veca;
    veca->die = (float)((longdouble)0.2 + (longdouble)cl.time);
                    /* Unresolved local var: int i@[???] */
    uVar5 = ((int)(veca + -0x4ee08) >> 3) * -0x33333333;
    if (uVar5 < 0x20) {
      r_dlightchanged = r_dlightchanged | 1 << ((byte)uVar5 & 0x1f);
    }
  }
  if ((cl_entities[cl.viewentity].curstate.effects & 2) != 0) {
    cl.viewent.curstate.effects = cl.viewent.curstate.effects | 2;
  }
  return;
}


// CL_PlayerHasCustomization  @ 001addf0
customization_t * CL_PlayerHasCustomization(int nPlayerNum,resourcetype_t type)

{
  customization_t *pcVar1;
  customization_s *pcVar2;
  
                    /* Unresolved local var: customization_t * pList@[DW_OP_reg0(EAX)] */
  pcVar1 = (customization_t *)cl.players[nPlayerNum].customdata.pNext;
  pcVar2 = (customization_t *)0x0;
  if (pcVar1 != (customization_t *)0x0) {
    pcVar2 = pcVar1;
    if (((resource_t_conflict *)&pcVar1->resource)->type == type) {
      return pcVar1;
    }
    do {
      pcVar2 = pcVar2->pNext;
      if (pcVar2 == (customization_s *)0x0) {
        return (customization_t *)0x0;
      }
    } while (((resource_t_conflict *)&pcVar2->resource)->type != type);
  }
  return pcVar2;
}


// CL_PopPMStates  @ 00194310
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


// CL_PrecacheBSPModels  @ 001aca30
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


// CL_PrecacheResources  @ 0019e910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_PrecacheResources(void)

{
  resource_s *prVar1;
  model_s *pmVar2;
  byte bVar3;
  model_t *pmVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  sfx_t *psVar8;
  resource_s *strSource;
  int iVar9;
  double dVar10;
  
                    /* Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: resource_t * next@[???] */
  SetLoadingProgressBarStatusText("#GameUI_PrecachingResources");
  ContinueLoadingProgressBar("ClientConnect",7,0.0);
  if (fs_startup_timings.value != 0.0) {
    iVar9 = g_iCurrentTiming + 1;
    g_iCurrentTiming = iVar9;
    g_StartupTimings[iVar9].name = "begin CL_PrecacheResources()";
    dVar10 = Sys_FloatTime();
    g_StartupTimings[iVar9].time = (float)dVar10;
  }
  if ((cl.resourcesonhand.pNext != (resource_s *)0x0) &&
     (strSource = cl.resourcesonhand.pNext, cl.resourcesonhand.pNext != &cl.resourcesonhand)) {
    do {
      bVar3 = strSource->ucFlags;
      prVar1 = strSource->pNext;
      if ((bVar3 & 0x10) != 0) goto LAB_0019e995;
      switch(strSource->type) {
      case t_sound:
        if ((bVar3 & 2) == 0) {
          S_BeginPrecaching();
          iVar9 = strSource->nIndex;
          psVar8 = S_PrecacheSound(strSource->szFileName);
          cl.sound_precache[iVar9] = psVar8;
          S_EndPrecaching();
          bVar3 = strSource->ucFlags;
          if ((cl.sound_precache[strSource->nIndex] == (sfx_s *)0x0) && ((bVar3 & 1) != 0)) {
            COM_ExplainDisconnection
                      (true,"Cannot continue without sound %s, disconnecting.",strSource);
            CL_Disconnect();
            return false;
          }
        }
        else {
          cl.sound_precache[strSource->nIndex] = (sfx_s *)0x0;
          bVar3 = strSource->ucFlags;
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
            iVar9 = strSource->nIndex;
LAB_0019ea2d:
            pmVar4 = Mod_ForName(strSource->szFileName,false,true);
            cl.model_precache[iVar9] = pmVar4;
            pmVar2 = cl.model_precache[strSource->nIndex];
          }
          else {
            iVar7 = Q_strnicmp(strSource->szFileName,"maps",4);
            iVar9 = strSource->nIndex;
            if (iVar7 == 0) goto LAB_0019ea2d;
            pmVar4 = Mod_FindName(true,strSource->szFileName);
            cl.model_precache[iVar9] = pmVar4;
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
          iVar9 = Q_stricmp(strSource->szFileName,"models/player.mdl");
          if (iVar9 == 0) {
            cl_playerindex = strSource->nIndex;
            bVar3 = strSource->ucFlags;
            break;
          }
        }
        goto LAB_0019e98c;
      case t_decal:
        if ((bVar3 & 4) == 0) {
          Draw_DecalSetName(strSource->nIndex,strSource->szFileName);
          bVar3 = strSource->ucFlags;
        }
        break;
      case t_eventscript:
        iVar9 = strSource->nIndex;
        pcVar5 = Mem_Strdup(strSource->szFileName);
        cl.event_precache[iVar9].filename = pcVar5;
        iVar9 = strSource->nIndex;
        pbVar6 = COM_LoadFile(strSource->szFileName,5,(int *)0x0);
        cl.event_precache[iVar9].pszScript = (char *)pbVar6;
        if (cl.event_precache[strSource->nIndex].pszScript != (char *)0x0) goto LAB_0019e98c;
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
LAB_0019e98c:
        bVar3 = strSource->ucFlags;
      }
      strSource->ucFlags = bVar3 | 0x10;
LAB_0019e995:
    } while ((prVar1 != (resource_s *)0x0) && (strSource = prVar1, prVar1 != &cl.resourcesonhand));
  }
  if (fs_startup_timings.value == 0.0) {
    return true;
  }
  iVar9 = g_iCurrentTiming + 1;
  g_StartupTimings[iVar9].name = "end  CL_PrecacheResources()";
  g_iCurrentTiming = iVar9;
  dVar10 = Sys_FloatTime();
  g_StartupTimings[iVar9].time = (float)dVar10;
  return true;
}


// CL_PredictMove  @ 00193940
void CL_PredictMove(qboolean repredicting)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  playermove_t_conflict *ppVar4;
  double dVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  local_state_t *to;
  usercmd_t *u;
  bool bVar15;
  float fVar16;
  local_state_t *local_70;
  usercmd_t *local_54;
  float local_30;
  float local_2c;
  float local_28;
  double local_24 [2];
  
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
  if (cls.state != ca_active) {
    return;
  }
  if (cls.spectator != false) {
    return;
  }
  pmove = &g_clmove;
  CL_SetUpPlayerPrediction(false,false);
  iVar8 = cl.parsecountmod;
  dVar5 = realtime;
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
  iVar13 = cl.parsecountmod * 0x42b8;
  iVar9 = cl.parsecountmod * 0x1930;
  iVar11 = iVar13 + 0xc7f6fc + cl.playernum * 0x154;
  uVar6 = 0;
  iVar10 = iVar9 + 0xd8b7e4;
  do {
    uVar3 = *(undefined4 *)(iVar11 + 4 + uVar6);
    *(undefined4 *)(iVar10 + uVar6) = *(undefined4 *)(iVar11 + uVar6);
    *(undefined4 *)(iVar9 + 0xd8b7e8 + uVar6) = uVar3;
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x150);
  *(undefined4 *)(iVar10 + uVar6) = *(undefined4 *)(iVar11 + uVar6);
  uVar6 = 0;
  iVar11 = iVar8 * 0x1930 + 0xd8b938;
  do {
    uVar3 = *(undefined4 *)(iVar13 + 0xc82188 + uVar6);
    *(undefined4 *)(iVar11 + uVar6) = *(undefined4 *)(iVar13 + 0xc82184 + uVar6);
    *(undefined4 *)(iVar8 * 0x1930 + 0xd8b93c + uVar6) = uVar3;
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x1d8);
  *(undefined4 *)(iVar11 + uVar6) = *(undefined4 *)(iVar13 + 0xc82184 + uVar6);
  Q_memcpy(cl.predicted_frames[iVar8].weapondata,cl.frames[iVar8].weapondata,0x1600);
  iVar11 = cl.parsecountmod;
  if (cl.frames[iVar8].invalid != false) {
    return;
  }
  local_24[0] = cl.frames[iVar8].time;
  local_54 = &cl.commands[CL_UPDATE_MASK & cls.netchan.incoming_acknowledged].cmd;
  cl.onground = -1;
  if (pushed == 0) {
    pushed = 1;
    oldphysent = pmove->numphysent;
    oldvisent = pmove->numvisent;
  }
  else {
    Con_Printf("CL_PushPMStates called with pushed stack\n");
  }
  fVar16 = (float)dVar5;
  local_70 = cl.predicted_frames + iVar11;
  CL_SetSolidPlayers(cl.playernum);
  g_i = 1;
  bVar15 = repredicting == false;
  if ((CL_UPDATE_BACKUP < 3) ||
     (uVar6 = cls.netchan.incoming_acknowledged + 1,
     (int)((uint)bVar15 + cls.netchan.outgoing_sequence) <= (int)uVar6)) {
    iVar8 = 1;
    to = (local_state_t *)0x0;
    u = (usercmd_t *)0x0;
  }
  else {
    uVar7 = CL_UPDATE_MASK;
    if (bVar15) {
      do {
        iVar8 = g_i;
        uVar12 = uVar7 & uVar6;
        u = &cl.commands[uVar12].cmd;
        uVar14 = cl.parsecountmod + g_i & uVar7;
        to = cl.predicted_frames + uVar14;
        CL_RunUsercmd(local_70,to,u,(uint)(cl.commands[uVar12].processedfuncs == false),local_24,
                      uVar6);
        iVar11 = cls.netchan.incoming_acknowledged;
        uVar7 = CL_UPDATE_MASK;
        cl.commands[uVar12].processedfuncs = true;
        uVar6 = iVar11 + iVar8 & uVar7;
        cl.predicted_origins[uVar6][0] = cl.predicted_frames[uVar14].playerstate.origin[0];
        cl.predicted_origins[uVar6][1] = cl.predicted_frames[uVar14].playerstate.origin[1];
        cl.predicted_origins[uVar6][2] = cl.predicted_frames[uVar14].playerstate.origin[2];
        if ((fVar16 <= cl.commands[uVar12].senttime) ||
           (iVar8 = iVar8 + 1, local_70 = to, g_i = iVar8, local_54 = u,
           CL_UPDATE_BACKUP + -1 <= iVar8)) break;
        uVar6 = iVar11 + iVar8;
      } while ((int)uVar6 < cls.netchan.outgoing_sequence + 1);
    }
    else {
      do {
        iVar8 = g_i;
        uVar12 = uVar7 & uVar6;
        u = &cl.commands[uVar12].cmd;
        uVar14 = cl.parsecountmod + g_i & uVar7;
        to = cl.predicted_frames + uVar14;
        CL_RunUsercmd(local_70,to,u,false,local_24,uVar6);
        iVar11 = cls.netchan.incoming_acknowledged;
        uVar7 = CL_UPDATE_MASK;
        cl.commands[uVar12].processedfuncs = true;
        uVar6 = iVar11 + iVar8 & uVar7;
        cl.predicted_origins[uVar6][0] = cl.predicted_frames[uVar14].playerstate.origin[0];
        cl.predicted_origins[uVar6][1] = cl.predicted_frames[uVar14].playerstate.origin[1];
        cl.predicted_origins[uVar6][2] = cl.predicted_frames[uVar14].playerstate.origin[2];
        if ((fVar16 <= cl.commands[uVar12].senttime) ||
           (iVar8 = iVar8 + 1, local_70 = to, g_i = iVar8, local_54 = u,
           CL_UPDATE_BACKUP + -1 <= iVar8)) break;
        uVar6 = iVar11 + iVar8;
      } while ((int)uVar6 < cls.netchan.outgoing_sequence);
    }
  }
  ppVar4 = pmove;
  if (pushed == 0) {
    Con_Printf("CL_PopPMStates called without stack\n");
  }
  else {
    pushed = pushed + -1;
    pmove->numphysent = oldphysent;
    ppVar4->numvisent = oldvisent;
  }
  if (CL_UPDATE_MASK <= iVar8) {
    return;
  }
  if ((to == (local_state_t *)0x0) && (to = local_70, u = local_54, repredicting == false)) {
    return;
  }
  fVar1 = *(float *)(local_54 + 1);
  if (*(float *)(u + 1) == fVar1) {
    fVar1 = 0.0;
  }
  else {
    fVar16 = (fVar16 - fVar1) / (*(float *)(u + 1) - fVar1);
    fVar1 = 0.0;
    if (0.0 <= fVar16) {
      fVar1 = fVar16;
    }
  }
  fVar16 = (to->playerstate).origin[0];
  if (((128.0 < ABS(fVar16 - (local_70->playerstate).origin[0])) ||
      (128.0 < ABS((to->playerstate).origin[1] - (local_70->playerstate).origin[1]))) ||
     (128.0 < ABS((to->playerstate).origin[2] - (local_70->playerstate).origin[2]))) {
    cl.simvel[0] = (to->client).velocity[0];
    cl.simvel[1] = (to->client).velocity[1];
    cl.simvel[2] = (to->client).velocity[2];
    cl.simorg[0] = (to->playerstate).origin[0];
    cl.simorg[1] = (to->playerstate).origin[1];
    cl.simorg[2] = (to->playerstate).origin[2];
    cl.punchangle[0] = (to->client).punchangle[0];
    cl.punchangle[1] = (to->client).punchangle[1];
    cl.punchangle[2] = (to->client).punchangle[2];
LAB_00193e56:
    cl.viewheight[0] = (to->client).view_ofs[0];
    cl.viewheight[1] = (to->client).view_ofs[1];
    cl.viewheight[2] = (to->client).view_ofs[2];
  }
  else {
                    /* Unresolved local var: int i@[???] */
    fVar2 = (local_70->playerstate).origin[0];
    cl.simorg[0] = (fVar16 - fVar2) * fVar1 + fVar2;
    fVar16 = (local_70->playerstate).origin[1];
    cl.simorg[1] = ((to->playerstate).origin[1] - fVar16) * fVar1 + fVar16;
    fVar16 = (local_70->playerstate).origin[2];
    cl.simorg[2] = ((to->playerstate).origin[2] - fVar16) * fVar1 + fVar16;
                    /* Unresolved local var: int i@[???] */
    fVar16 = (local_70->client).velocity[0];
    cl.simvel[0] = ((to->client).velocity[0] - fVar16) * fVar1 + fVar16;
    fVar16 = (local_70->client).velocity[1];
    cl.simvel[1] = ((to->client).velocity[1] - fVar16) * fVar1 + fVar16;
    fVar16 = (local_70->client).velocity[2];
    cl.simvel[2] = ((to->client).velocity[2] - fVar16) * fVar1 + fVar16;
                    /* Unresolved local var: int i@[???] */
    fVar16 = (local_70->client).punchangle[0];
    cl.punchangle[0] = ((to->client).punchangle[0] - fVar16) * fVar1 + fVar16;
    fVar16 = (local_70->client).punchangle[1];
    cl.punchangle[1] = ((to->client).punchangle[1] - fVar16) * fVar1 + fVar16;
    fVar16 = (local_70->client).punchangle[2];
    cl.punchangle[2] = ((to->client).punchangle[2] - fVar16) * fVar1 + fVar16;
    if ((local_70->playerstate).usehull != (to->playerstate).usehull) goto LAB_00193e56;
    iVar8 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      fVar16 = (local_70->client).view_ofs[iVar8];
      cl.viewheight[iVar8] = ((to->client).view_ofs[iVar8] - fVar16) * fVar1 + fVar16;
      iVar8 = iVar8 + 1;
    } while (iVar8 != 3);
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
      local_30 = cl_entities[g_lastground].curstate.origin[0] -
                 cl_entities[g_lastground].prevstate.origin[0];
      local_2c = cl_entities[g_lastground].curstate.origin[1] -
                 cl_entities[g_lastground].prevstate.origin[1];
      local_28 = 0.0;
      fVar16 = Length(&local_30);
      if (0.0 < fVar16) {
        cl.moving = 1;
      }
      else if (cl.moving == 0) goto LAB_00193eca;
      cl_correction_time = 0.0;
      goto LAB_00193fe5;
    }
  }
LAB_00193eca:
  if (((0.0 < cl_correction_time) && (cl_nosmooth.value == 0.0)) && (cl_smoothtime.value != 0.0)) {
                    /* Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???] */
    if (bVar15) {
      cl_correction_time = cl_correction_time - host_frametime;
    }
    if (cl_smoothtime.value <= 0.0) {
      Cvar_DirectSet(&cl_smoothtime,"0.1");
    }
    fVar16 = 0.0;
    if (0.0 <= (float)cl_correction_time) {
      fVar16 = (float)cl_correction_time;
    }
    if (cl_smoothtime.value <= fVar16) {
      fVar16 = cl_smoothtime.value;
    }
    cl_correction_time = (double)fVar16;
    local_30 = cl.simorg[0] - CL_PredictMove::lastsimorg[0];
    local_2c = cl.simorg[1] - CL_PredictMove::lastsimorg[1];
    local_28 = cl.simorg[2] - CL_PredictMove::lastsimorg[2];
    VectorScale(&local_30,1.0 - fVar16 / cl_smoothtime.value,&local_30);
    cl.simorg[0] = CL_PredictMove::lastsimorg[0] + local_30;
    cl.simorg[1] = CL_PredictMove::lastsimorg[1] + local_2c;
    cl.simorg[2] = CL_PredictMove::lastsimorg[2] + local_28;
  }
LAB_00193fe5:
  CL_PredictMove::lastsimorg[0] = cl.simorg[0];
  CL_PredictMove::lastsimorg[1] = cl.simorg[1];
  CL_PredictMove::lastsimorg[2] = cl.simorg[2];
  CL_SetIdealPitch();
  return;
}


// CL_PrintCachedServer  @ 0019c560
void __regparm3 CL_PrintCachedServer(int slot)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: server_cache_t * p@[???]
                       Unresolved local var: char * pszDedicated@[???]
                       Unresolved local var: char * pszOS@[???]
                       Unresolved local var: char * pszVisibility@[???]
                       Unresolved local var: char * pszSecure@[???] */
  iVar5 = slot * 0x448;
  if (cached_servers[slot].inuse != 0) {
    Con_Printf("%d ",slot + 1);
    Con_Printf("Name: %s\n",iVar5 + 0xbe7fec);
    pcVar2 = NET_AdrToString(cached_servers[slot].adr);
    Con_Printf("Address: %s\n",pcVar2);
    Con_Printf("Map: %s\n",iVar5 + 0xbe81ec);
    Con_Printf("Description: %s\n",iVar5 + 0xbe82ec);
    Con_Printf("Players: %d/%d   Bots: %d\n",cached_servers[slot].players,
               cached_servers[slot].maxplayers,cached_servers[slot].bots);
    cVar1 = cached_servers[slot].type;
    pcVar2 = "Dedicated";
    if (((cVar1 != 'd') && (pcVar2 = "Proxy", cVar1 != 'p')) && (pcVar2 = "Listen", cVar1 != 'l')) {
      pcVar2 = "Unknown";
    }
    pcVar4 = "Windows";
    if ((cached_servers[slot].os != 'w') && (pcVar4 = "Linux", cached_servers[slot].os != 'l')) {
      pcVar4 = "macOS";
    }
    pcVar3 = "Private";
    if (cached_servers[slot].is_private == false) {
      pcVar3 = "Public";
    }
    pcVar6 = "Secure";
    if (cached_servers[slot].is_vac == false) {
      pcVar6 = "Insecure";
    }
    Con_Printf("%s - %s - %s - %s\n",pcVar2,pcVar4,pcVar3,pcVar6);
    if (cached_servers[slot].has_spectator_address != 0) {
      pcVar2 = NET_AdrToString(cached_servers[slot].spec_adr);
      Con_Printf("Spectator Address: %s\n",pcVar2);
      return;
    }
  }
  return;
}


// CL_PrintCachedServer  @ 0019ccc0
void CL_PrintCachedServer(int slot)

{
                    /* Unresolved local var: server_cache_t * p@[???]
                       Unresolved local var: char * pszDedicated@[???]
                       Unresolved local var: char * pszOS@[???]
                       Unresolved local var: char * pszVisibility@[???]
                       Unresolved local var: char * pszSecure@[???] */
  if ((uint)slot < 0x10) {
    CL_PrintCachedServer(slot);
    return;
  }
  return;
}


// CL_PrintEntities_f  @ 0019b4e0
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


// CL_PrintEntity  @ 0018d3c0
void CL_PrintEntity(cl_entity_t_conflict2 *ent)

{
  return;
}


// CL_ProcessEntityUpdate  @ 0018b960
void CL_ProcessEntityUpdate(cl_entity_t_conflict2 *ent)

{
  float fVar1;
  int iVar2;
  vec_t vVar3;
  model_t *pmVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  
                    /* Unresolved local var: int i@[???] */
  ent->index = (ent->curstate).number;
  pmVar4 = CL_GetModelByIndex((ent->curstate).modelindex);
  ent->model = (model_s_conflict1 *)pmVar4;
  COM_NormalizeAngles((ent->curstate).angles);
  if (((ent->model == (model_s_conflict1 *)0x0) || (ent->model->name[0] != '*')) &&
     ((iVar2 = (ent->curstate).movetype, iVar2 == 0 ||
      ((((iVar2 == 4 || (iVar2 == 3)) || (iVar2 == 5)) ||
       (((ent->curstate).starttime != 0.0 || ((ent->curstate).impacttime != 0.0)))))))) {
    fVar1 = (ent->curstate).animtime;
  }
  else {
    fVar1 = (ent->curstate).msg_time;
    (ent->curstate).animtime = fVar1;
  }
                    /* Unresolved local var: int iTime1@[???]
                       Unresolved local var: int iTime2@[???] */
  if ((2 < ((int)(fVar1 * 1000.0) - (int)((ent->prevstate).animtime * 1000.0)) + 1U) ||
     ((ent->curstate).movetype == 0)) {
    R_UpdateLatchedVars((cl_entity_t *)ent);
    CL_UpdatePositions((cl_entity_t *)ent);
  }
  if (ent->player != 0) {
    (ent->curstate).angles[0] = (ent->curstate).angles[0] / -3.0;
  }
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float dt@[???] */
  fVar1 = (ent->curstate).starttime;
  vVar7 = (ent->curstate).origin[0];
  vVar6 = (ent->curstate).origin[1];
  vVar5 = (ent->curstate).origin[2];
  ent->origin[0] = vVar7;
  ent->origin[1] = vVar6;
  ent->origin[2] = vVar5;
  if ((fVar1 != 0.0) && ((ent->curstate).impacttime != 0.0)) {
    CL_ParametricMove(ent);
    vVar7 = (ent->curstate).origin[0];
    vVar6 = (ent->curstate).origin[1];
    vVar5 = (ent->curstate).origin[2];
  }
  ent->angles[0] = (ent->curstate).angles[0];
  vVar3 = (ent->curstate).angles[1];
  *(ulonglong *)ent->attachment[0] = CONCAT44(vVar6,vVar7);
  *(ulonglong *)(ent->attachment[0] + 2) = CONCAT44(vVar7,vVar5);
  ent->angles[1] = vVar3;
  vVar3 = (ent->curstate).angles[2];
  *(ulonglong *)(ent->attachment[1] + 1) = CONCAT44(vVar5,vVar6);
  *(ulonglong *)ent->attachment[2] = CONCAT44(vVar6,vVar7);
  ent->angles[2] = vVar3;
  *(ulonglong *)(ent->attachment[2] + 2) = CONCAT44(vVar7,vVar5);
  *(ulonglong *)(ent->attachment[3] + 1) = CONCAT44(vVar5,vVar6);
  return;
}


// CL_ProcessFile  @ 0019ecd0
void CL_ProcessFile(qboolean successfully_received,char *filename)

{
  char cVar1;
  resource_s *prVar2;
  int iVar3;
  uint playernumber;
  qboolean qVar4;
  char *pcVar5;
  customization_s_conflict *pcVar6;
  resource_s *pResource;
  bool bVar7;
  byte local_504c [20480];
  sizebuf_t local_4c;
  uchar local_2c [28];
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???]
                       Unresolved local var: char * pfilename@[???]
                       Unresolved local var: uchar[16] rgucMD5_hash@[???]
                       Unresolved local var: char[20] szModuleC@[???] */
  bVar7 = successfully_received != false;
  if ((filename == (char *)0x0) || (!bVar7)) {
    if (successfully_received == false) {
      pcVar5 = (char *)0x0;
                    /* Unresolved local var: char * pfilename@[???] */
                    /* Unresolved local var: char * pfilename@[???] */
      if (((filename != (char *)0x0) && (pcVar5 = filename, *filename != '\0')) &&
         (pcVar5 = "customization", *filename != '!')) {
        pcVar5 = filename;
      }
      Con_Printf("Error: server failed to transmit file \'%s\'\n",pcVar5);
    }
  }
  else if (*filename != '!') {
    Con_Printf("Processing %s\n",filename);
  }
  iVar3 = Q_strlen("sound/");
  iVar3 = Q_strnicmp(filename,"sound/",iVar3);
  pcVar5 = filename;
  if (iVar3 == 0) {
    iVar3 = Q_strlen("sound/");
    pcVar5 = filename + iVar3;
  }
  if (cl.resourcesneeded.pNext != &cl.resourcesneeded) {
    pResource = cl.resourcesneeded.pNext;
    do {
      prVar2 = pResource->pNext;
      iVar3 = Q_strnicmp(filename,"!MD5",4);
      if (iVar3 == 0) {
        COM_HexConvert(pcVar5 + 4,0x20,local_2c);
        iVar3 = Q_memcmp(pResource->rgucMD5_hash,local_2c,0x10);
joined_r0x0019ee31:
        if (iVar3 == 0) {
          if (!bVar7) goto LAB_0019ee45;
LAB_0019eee8:
          pResource->ucFlags = pResource->ucFlags & 0xfd;
          cVar1 = *filename;
joined_r0x0019eeef:
          if (cVar1 != '!') goto LAB_0019ee4e;
          if (cls.netchan.tempbuffer == (void *)0x0) goto LAB_0019ee5f;
          if (pResource->nDownloadSize != cls.netchan.tempbuffersize) {
            Con_Printf("CL_ProcessFile:  Downloaded %i bytes for purported %i byte file, ignoring download\n"
                       ,cls.netchan.tempbuffersize,pResource->nDownloadSize);
            goto LAB_0019ee4e;
          }
          if ((pResource->ucFlags & 4) == 0) goto LAB_0019ee57;
          HPAK_AddLump(true,"custom.hpk",pResource,cls.netchan.tempbuffer,(FileHandle_t)0x0);
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
          playernumber = (uint)pResource->playernum;
          pcVar6 = cl.players[playernumber].customdata.pNext;
          if (pcVar6 == (customization_s_conflict *)0x0) goto LAB_0019f0ad;
          goto LAB_0019efce;
        }
      }
      else {
        if (pResource->type != t_generic) {
          iVar3 = Q_stricmp(pResource->szFileName,pcVar5);
          goto joined_r0x0019ee31;
        }
        iVar3 = Q_stricmp(pResource->szFileName,filename);
        if (iVar3 == 0) {
          if (bVar7) goto LAB_0019eee8;
LAB_0019ee45:
          cVar1 = *filename;
          goto joined_r0x0019eeef;
        }
      }
      pResource = prVar2;
    } while (prVar2 != &cl.resourcesneeded);
  }
  goto LAB_0019ee88;
  while (pcVar6 = pcVar6->pNext, pcVar6 != (customization_s_conflict *)0x0) {
LAB_0019efce:
    iVar3 = Q_memcmp((pcVar6->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10);
    if (iVar3 == 0) {
      Con_DPrintf("Duplicate resource received and ignored.\n");
      goto LAB_0019ee4e;
    }
  }
  playernumber = (uint)pResource->playernum;
LAB_0019f0ad:
  qVar4 = COM_CreateCustomization
                    ((customization_t *)&cl.players[playernumber].customdata,pResource,playernumber,
                     1,(customization_t **)0x0,(int *)0x0);
  if (qVar4 == false) {
    Con_Printf("Unable to create custom decal for player %i\n",(uint)pResource->playernum);
  }
LAB_0019ee4e:
  if (cls.netchan.tempbuffer != (void *)0x0) {
LAB_0019ee57:
    Mem_Free(cls.netchan.tempbuffer);
  }
LAB_0019ee5f:
  cls.netchan.tempbuffer = (void *)0x0;
  cls.netchan.tempbuffersize = 0;
  CL_RemoveFromResourceList(pResource);
  CL_AddToResourceList(pResource,&cl.resourcesonhand);
LAB_0019ee88:
  if (cls.state != ca_disconnected) {
    if (cl.resourcesneeded.pNext == &cl.resourcesneeded) {
                    /* Unresolved local var: uchar[20480] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
      Q_memset(&local_4c,0,0x14);
      local_4c.buffername = "Resource Registration";
      local_4c.data = local_504c;
      local_4c.cursize = 0;
      local_4c.maxsize = 0x5000;
      qVar4 = CL_PrecacheResources();
      if (qVar4 != false) {
        CL_RegisterResources(&local_4c);
      }
      if (0 < local_4c.cursize) {
        Netchan_CreateFragments(false,&cls.netchan,&local_4c);
        Netchan_FragSend(&cls.netchan);
      }
    }
    if (cls.netchan.tempbuffer != (void *)0x0) {
      Con_Printf("CL_ProcessFile: Received a decal %s, but didn\'t find it in resources needed list!\n"
                 ,pcVar5);
      Mem_Free(cls.netchan.tempbuffer);
    }
    cls.netchan.tempbuffer = (void *)0x0;
    cls.netchan.tempbuffersize = 0;
  }
  return;
}


// CL_ProcessFile  @ 0019f110
void CL_ProcessFile(qboolean successfully_received,char *filename)

{
  byte bVar1;
  resource_s *prVar2;
  int iVar3;
  uint playernumber;
  qboolean qVar4;
  resource_s *pResource;
  char *s2;
  customization_s_conflict *pcVar5;
  byte local_504c [20480];
  sizebuf_t local_4c;
  uchar local_2c [28];
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???]
                       Unresolved local var: char * pfilename@[???]
                       Unresolved local var: uchar[16] rgucMD5_hash@[???]
                       Unresolved local var: char[20] szModuleC@[???] */
  if (cls.netchan.incomingfilename[0] != '!') {
    Con_Printf("Processing %s\n",0xe090e4);
  }
  s2 = cls.netchan.incomingfilename;
  iVar3 = Q_strlen("sound/");
  iVar3 = Q_strnicmp(cls.netchan.incomingfilename,"sound/",iVar3);
  if (iVar3 == 0) {
    iVar3 = Q_strlen("sound/");
    s2 = cls.netchan.incomingfilename + iVar3;
  }
  if (cl.resourcesneeded.pNext != &cl.resourcesneeded) {
    pResource = cl.resourcesneeded.pNext;
    do {
      prVar2 = pResource->pNext;
      iVar3 = Q_strnicmp(cls.netchan.incomingfilename,"!MD5",4);
      if (iVar3 == 0) {
        COM_HexConvert(s2 + 4,0x20,local_2c);
        iVar3 = Q_memcmp(pResource->rgucMD5_hash,local_2c,0x10);
      }
      else if (pResource->type == t_generic) {
        iVar3 = Q_stricmp(pResource->szFileName,cls.netchan.incomingfilename);
      }
      else {
        iVar3 = Q_stricmp(pResource->szFileName,s2);
      }
      if (iVar3 == 0) {
        bVar1 = pResource->ucFlags;
        pResource->ucFlags = bVar1 & 0xfd;
        if (cls.netchan.incomingfilename[0] != '!') goto LAB_0019f1ea;
        if (cls.netchan.tempbuffer == (void *)0x0) goto LAB_0019f1fc;
        if (pResource->nDownloadSize != cls.netchan.tempbuffersize) {
          Con_Printf("CL_ProcessFile:  Downloaded %i bytes for purported %i byte file, ignoring download\n"
                     ,cls.netchan.tempbuffersize,pResource->nDownloadSize);
          goto LAB_0019f1ea;
        }
        if ((bVar1 & 4) == 0) goto LAB_0019f1f4;
        HPAK_AddLump(true,"custom.hpk",pResource,cls.netchan.tempbuffer,(FileHandle_t)0x0);
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
        playernumber = (uint)pResource->playernum;
        pcVar5 = cl.players[playernumber].customdata.pNext;
        if (pcVar5 == (customization_s_conflict *)0x0) goto LAB_0019f486;
        goto LAB_0019f3ae;
      }
      pResource = prVar2;
    } while (prVar2 != &cl.resourcesneeded);
  }
  goto LAB_0019f224;
  while (pcVar5 = pcVar5->pNext, pcVar5 != (customization_s_conflict *)0x0) {
LAB_0019f3ae:
    iVar3 = Q_memcmp((pcVar5->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10);
    if (iVar3 == 0) {
      Con_DPrintf("Duplicate resource received and ignored.\n");
      goto LAB_0019f1ea;
    }
  }
  playernumber = (uint)pResource->playernum;
LAB_0019f486:
  qVar4 = COM_CreateCustomization
                    ((customization_t *)&cl.players[playernumber].customdata,pResource,playernumber,
                     1,(customization_t **)0x0,(int *)0x0);
  if (qVar4 == false) {
    Con_Printf("Unable to create custom decal for player %i\n",(uint)pResource->playernum);
  }
LAB_0019f1ea:
  if (cls.netchan.tempbuffer != (void *)0x0) {
LAB_0019f1f4:
    Mem_Free(cls.netchan.tempbuffer);
  }
LAB_0019f1fc:
  cls.netchan.tempbuffersize = 0;
  cls.netchan.tempbuffer = (void *)0x0;
  CL_RemoveFromResourceList(pResource);
  CL_AddToResourceList(pResource,&cl.resourcesonhand);
LAB_0019f224:
  if (cls.state != ca_disconnected) {
    if (cl.resourcesneeded.pNext == &cl.resourcesneeded) {
                    /* Unresolved local var: uchar[20480] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
      Q_memset(&local_4c,0,0x14);
      local_4c.data = local_504c;
      local_4c.buffername = "Resource Registration";
      local_4c.cursize = 0;
      local_4c.maxsize = 0x5000;
      qVar4 = CL_PrecacheResources();
      if (qVar4 != false) {
        CL_RegisterResources(&local_4c);
      }
      if (0 < local_4c.cursize) {
        Netchan_CreateFragments(false,&cls.netchan,&local_4c);
        Netchan_FragSend(&cls.netchan);
      }
    }
    if (cls.netchan.tempbuffer != (void *)0x0) {
      Con_Printf("CL_ProcessFile: Received a decal %s, but didn\'t find it in resources needed list!\n"
                 ,s2);
      Mem_Free(cls.netchan.tempbuffer);
    }
    cls.netchan.tempbuffer = (void *)0x0;
    cls.netchan.tempbuffersize = 0;
  }
  return;
}


// CL_ProcessPacket  @ 0018c1b0
void CL_ProcessPacket(frame_t *frame)

{
  entity_state_s *dst;
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  qboolean qVar5;
  uint uVar6;
  cl_entity_t *pcVar7;
  entity_state_s *state;
  int iVar8;
  int local_30;
  
                    /* Unresolved local var: packet_entities_t * pPacket@[???]
                       Unresolved local var: cl_entity_t.conflict2 * ent@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: int pnum@[???] */
  if (0 < (frame->packet_entities).num_entities) {
    local_30 = 0;
    iVar8 = 0;
    do {
      state = (entity_state_s *)
              ((int)((frame->packet_entities).entities)->origin + local_30 + -0x10);
      state->messagenum = cl.parsecount;
      pcVar7 = cl_entities;
      state->msg_time = (float)cl.mtime[0];
      iVar2 = state->number;
      pcVar7 = pcVar7 + iVar2;
      qVar5 = false;
      if (0 < iVar2) {
        qVar5 = (qboolean)(iVar2 <= cl.maxclients);
      }
      pcVar7->player = qVar5;
      if (state->number + -1 == cl.playernum) {
        ClientDLL_TxferLocalOverrides(state,&frame->clientdata);
      }
      uVar4 = 0;
      do {
        uVar6 = uVar4;
        uVar3 = *(undefined4 *)((int)(pcVar7->curstate).origin + (uVar6 - 0x10));
        *(undefined4 *)((int)(pcVar7->prevstate).origin + (uVar6 - 0xc)) =
             *(undefined4 *)((int)(pcVar7->curstate).origin + (uVar6 - 0xc));
        *(undefined4 *)((int)(pcVar7->prevstate).origin + (uVar6 - 0x10)) = uVar3;
        uVar4 = uVar6 + 8;
      } while (uVar6 + 8 < 0x150);
      *(undefined4 *)((int)(pcVar7->prevstate).origin + (uVar6 - 8)) =
           *(undefined4 *)((int)(pcVar7->curstate).origin + (uVar6 - 8));
      uVar4 = 0;
      do {
        uVar6 = uVar4;
        uVar3 = *(undefined4 *)((int)state->origin + (uVar6 - 0x10));
        *(undefined4 *)((int)(pcVar7->curstate).origin + (uVar6 - 0xc)) =
             *(undefined4 *)((int)state->origin + (uVar6 - 0xc));
        *(undefined4 *)((int)(pcVar7->curstate).origin + (uVar6 - 0x10)) = uVar3;
        uVar4 = uVar6 + 8;
      } while (uVar6 + 8 < 0x150);
      *(undefined4 *)((int)(pcVar7->curstate).origin + (uVar6 - 8)) =
           *(undefined4 *)((int)state->origin + (uVar6 - 8));
      CL_ProcessEntityUpdate((cl_entity_t_conflict2 *)pcVar7);
                    /* Unresolved local var: int bytenum@[???]
                       Unresolved local var: int bitnum@[???] */
      if ((1 << ((byte)iVar8 & 7) & (uint)(frame->packet_entities).flags[iVar8 >> 3]) == 0) {
LAB_0018c2f0:
        qVar5 = pcVar7->player;
      }
      else {
        (pcVar7->latched).prevorigin[0] = (pcVar7->curstate).origin[0];
        (pcVar7->latched).prevorigin[1] = (pcVar7->curstate).origin[1];
        (pcVar7->latched).prevorigin[2] = (pcVar7->curstate).origin[2];
        (pcVar7->latched).prevangles[0] = (pcVar7->curstate).angles[0];
        (pcVar7->latched).prevangles[1] = (pcVar7->curstate).angles[1];
        (pcVar7->latched).prevangles[2] = (pcVar7->curstate).angles[2];
        R_ResetLatched(pcVar7,true);
        CL_ResetPositions(pcVar7);
        fVar1 = (pcVar7->curstate).starttime;
        if (NAN(fVar1)) {
          fVar1 = (pcVar7->curstate).impacttime;
        }
        else {
          if (fVar1 == 0.0) goto LAB_0018c2f0;
          fVar1 = (pcVar7->curstate).impacttime;
        }
        if (fVar1 == 0.0) goto LAB_0018c2f0;
        pcVar7->lastmove = (float)cl.time;
        qVar5 = pcVar7->player;
      }
      if (qVar5 != false) {
                    /* Unresolved local var: int playerindex@[???] */
        iVar2 = state->number + -1;
                    /* Unresolved local var: entity_state_t.conflict * ps@[???] */
        dst = (entity_state_s *)(cl.parsecountmod * 0x42b8 + 0xc7f6fc + iVar2 * 0x154);
        dst->number = state->number;
        dst->messagenum = cl.parsecount;
        dst->msg_time = (float)cl.mtime[0];
        ClientDLL_ProcessPlayerState(dst,state);
        if (cl.playernum == iVar2) {
          CL_CheckPredictionError();
        }
      }
      iVar8 = iVar8 + 1;
      local_30 = local_30 + 0x154;
    } while (iVar8 < (frame->packet_entities).num_entities);
  }
  return;
}


// CL_ProcessPlayerState  @ 0018c160
void CL_ProcessPlayerState(int playerindex,entity_state_t_conflict *state)

{
  entity_state_s *dst;
  
                    /* Unresolved local var: entity_state_t.conflict * ps@[???] */
  dst = (entity_state_s *)(cl.parsecountmod * 0x42b8 + 0xc7f6fc + playerindex * 0x154);
  dst->number = state->number;
  dst->messagenum = cl.parsecount;
  dst->msg_time = (float)cl.mtime[0];
  ClientDLL_ProcessPlayerState(dst,(entity_state_s *)state);
  return;
}


// CL_PureOrigin  @ 00194e90
void CL_PureOrigin(cl_entity_t *ent,float t,vec_t *outorigin,vec_t *outangles)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_5c;
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
                       Unresolved local var: float t1@[DW_OP_reg14(ST3)]
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
  uVar4 = uVar3 & 0x3f;
  uVar5 = uVar3 - 1 & 0x3f;
  local_5c = 1;
  if (t <= ent->ph[uVar4].animtime) {
    do {
      uVar6 = uVar3 - local_5c & 0x3f;
      fVar1 = ent->ph[uVar6].animtime;
      if (fVar1 == 0.0) break;
      if (fVar1 < t) {
        uVar4 = (uVar3 - local_5c) + 1 & 0x3f;
        uVar5 = uVar6;
        break;
      }
      local_5c = local_5c + 1;
    } while (local_5c != 0x3f);
  }
  fVar1 = ent->ph[uVar5].animtime;
  fVar2 = ent->ph[uVar4].animtime;
  if (fVar2 == 0.0) {
    *outorigin = ent->ph[uVar5].origin[0];
    outorigin[1] = ent->ph[uVar5].origin[1];
    outorigin[2] = ent->ph[uVar5].origin[2];
    *outangles = ent->ph[uVar5].angles[0];
    outangles[1] = ent->ph[uVar5].angles[1];
    outangles[2] = ent->ph[uVar5].angles[2];
    return;
  }
  local_40 = ent->ph[uVar4].origin[0] - ent->ph[uVar5].origin[0];
  local_3c = ent->ph[uVar4].origin[1] - ent->ph[uVar5].origin[1];
  local_38 = ent->ph[uVar4].origin[2] - ent->ph[uVar5].origin[2];
  if (fVar2 == fVar1) {
    fVar2 = 1.0;
  }
  else {
    fVar1 = (t - fVar1) / (fVar2 - fVar1);
    fVar2 = 0.0;
    if ((0.0 <= fVar1) && (fVar2 = 1.2, fVar1 <= 1.2)) {
      fVar2 = fVar1;
    }
  }
  VectorMA(ent->ph[uVar5].origin,fVar2,&local_40,&local_34);
  InterpolateAngles(ent->ph[uVar5].angles,ent->ph[uVar4].angles,&local_28,fVar2);
  *outorigin = local_34;
  outorigin[1] = local_30;
  outorigin[2] = local_2c;
  *outangles = local_28;
  outangles[1] = local_24;
  outangles[2] = local_20;
  return;
}


// CL_PushPMStates  @ 001942c0
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


// CL_QueueEvent  @ 00191640
void CL_QueueEvent(int flags,int index,float delay,event_args_t *pargs)

{
  event_state_t *peVar1;
  uint uVar2;
  event_state_t *peVar3;
  
                    /* Unresolved local var: event_info_t * ei@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  peVar3 = &cl.events;
  peVar1 = &cl.events;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
    if (peVar1->ei[0].index == 0) {
      if (peVar1 != (event_state_t *)0x0) goto LAB_001916b4;
      break;
    }
    peVar1 = (event_state_t *)(peVar1->ei + 1);
  } while (peVar1 != (event_state_t *)cl.downloadUrl);
  if ((flags & 2U) != 0) {
    do {
      if ((peVar3->ei[0].index == 0) || ((peVar3->ei[0].flags & 2) == 0)) {
        peVar1 = peVar3;
        if (peVar3 == (event_state_t *)0x0) {
          return;
        }
LAB_001916b4:
        peVar1->ei[0].packet_index = 0;
        peVar1->ei[0].index = (ushort)index;
        uVar2 = 0;
        do {
          *(undefined4 *)((int)peVar1->ei[0].args.origin + (uVar2 - 8)) =
               *(undefined4 *)((int)pargs->origin + (uVar2 - 8));
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x48);
        if (delay == 0.0) {
          peVar1->ei[0].fire_time = 0.0;
        }
        else {
          peVar1->ei[0].fire_time = delay + (float)cl.time;
        }
        peVar1->ei[0].flags = flags;
        return;
      }
      peVar3 = (event_state_t *)(peVar3->ei + 1);
    } while (peVar3 != (event_state_t *)cl.downloadUrl);
  }
  return;
}


// CL_QueueHTTPDownload  @ 00183c10
/* WARNING: Variable defined which should be unmapped: growSize */

void CL_QueueHTTPDownload(char *filename)

{
  netadr_t a;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  undefined4 *puVar11;
  bool bVar12;
  byte bVar13;
  int growSize;
  
  bVar13 = 0;
  bVar12 = &stack0x00000000 == (undefined1 *)0x3c;
                    /* Unresolved local var: RequestContext * rc@[???] */
  iVar4 = 6;
  pcVar8 = "local";
  pcVar10 = cls.servername;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar12 = *pcVar8 == *pcVar10;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  } while (bVar12);
  if (bVar12) {
    return;
  }
  TheDownloadManager.m_totalRequests = TheDownloadManager.m_totalRequests + 1;
  puVar2 = operator_new(0xc0c);
  iVar1 = TheDownloadManager.m_queuedRequests.m_Size;
  iVar4 = TheDownloadManager.m_queuedRequests.m_Size + 1;
  iVar9 = iVar4;
  if (TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated <=
      TheDownloadManager.m_queuedRequests.m_Size) {
    iVar3 = iVar4 - TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated;
    if (TheDownloadManager.m_queuedRequests.m_Memory.m_GrowSize < 0) {
      iVar6 = TheDownloadManager.m_queuedRequests.m_Memory.m_GrowSize;
      if (0 < iVar3) goto LAB_00183c7d;
    }
    else {
      iVar6 = iVar3;
      if (((iVar3 < 1) &&
          (iVar6 = TheDownloadManager.m_queuedRequests.m_Memory.m_GrowSize,
          TheDownloadManager.m_queuedRequests.m_Memory.m_GrowSize == 0)) &&
         (iVar6 = 1, TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated != 0)) {
        iVar6 = TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated;
      }
    }
    TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated =
         TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated + iVar6;
    if (TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory == (RequestContext **)0x0) {
      TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory =
           malloc(TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated * 4);
    }
    else {
      TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory =
           realloc(TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory,
                   TheDownloadManager.m_queuedRequests.m_Memory.m_NumAllocated * 4);
      iVar9 = TheDownloadManager.m_queuedRequests.m_Size + 1;
    }
  }
LAB_00183c7d:
                    /* Unresolved local var: int numToMove@[???] */
  iVar3 = (iVar9 - iVar1) + -1;
  TheDownloadManager.m_queuedRequests.m_Size = iVar9;
  if (iVar3 < 1) {
    iVar9 = iVar1 << 2;
  }
  else {
    iVar9 = iVar1 * 4;
    memmove(TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory + iVar4,
            TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory + iVar1,iVar3 * 4);
  }
  if ((undefined4 *)(iVar9 + (int)TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory) !=
      (undefined4 *)0x0) {
    *(undefined4 *)(iVar9 + (int)TheDownloadManager.m_queuedRequests.m_Memory.m_pMemory) = puVar2;
  }
  bVar12 = ((uint)puVar2 & 1) != 0;
  uVar7 = 0xc0c;
  puVar11 = puVar2;
  if (bVar12) {
    *(undefined1 *)puVar2 = 0;
    puVar11 = (undefined4 *)((int)puVar2 + 1);
    uVar7 = 0xc0b;
  }
  if (((uint)puVar11 & 2) != 0) {
    *(undefined2 *)puVar11 = 0;
    uVar7 = uVar7 - 2;
    puVar11 = (undefined4 *)((int)puVar11 + 2);
  }
  if (((uint)puVar11 & 4) != 0) {
    *puVar11 = 0;
    uVar7 = uVar7 - 4;
    puVar11 = puVar11 + 1;
  }
  for (uVar5 = uVar7 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar11 = 0;
    puVar11 = puVar11 + (uint)bVar13 * -2 + 1;
  }
  if ((uVar7 & 2) != 0) {
    *(undefined2 *)puVar11 = 0;
    puVar11 = (undefined4 *)((int)puVar11 + 2);
  }
  if (bVar12) {
    *(undefined1 *)puVar11 = 0;
  }
  *puVar2 = 0;
  snprintf((char *)(puVar2 + 2),0x400,"%s");
  snprintf((char *)(puVar2 + 0x102),0x400,"%s");
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
  NET_AdrToString(a);
  snprintf((char *)(puVar2 + 0x202),0x400,"%s");
  return;
}


// CL_Rate_f  @ 001a2bb0
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
    Con_Printf("cl_rate:  Maximum %f, Minimum %f\n",100000,1000);
    return;
  }
  cls.netchan.rate = (double)fVar2;
  return;
}


// CL_Rcon_f  @ 0019b8a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Rcon_f(void)

{
  netadr_t adr;
  short sVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  qboolean qVar5;
  netadr_t local_20;
  
                    /* Unresolved local var: netadr_t to@[???]
                       Unresolved local var: ushort port@[???] */
  if (rcon_password.string == (char *)0x0) {
    Con_Printf("You must set \'rcon_password\' before\nissuing an rcon command.\n");
    return;
  }
  pcVar3 = Cmd_Args();
  if (pcVar3 == (char *)0x0) {
    Con_Printf("Rcon:  Empty rcon string\n");
    return;
  }
  if (cls.state < ca_connected) {
    NET_Config(true);
    iVar4 = Q_strlen(rcon_address.string);
    if (iVar4 == 0) {
      Con_Printf(
                "You must either be connected,\nor set the \'rcon_address\' cvar\nto issue rcon commands\n"
                );
      return;
    }
  }
  else {
    iVar4 = Q_strlen(rcon_address.string);
    if (iVar4 == 0) {
      local_20.type = cls.netchan.remote_address.type;
      local_20.ip[0] = cls.netchan.remote_address.ip[0];
      local_20.ip[1] = cls.netchan.remote_address.ip[1];
      local_20.ip[2] = cls.netchan.remote_address.ip[2];
      local_20.ip[3] = cls.netchan.remote_address.ip[3];
      local_20.ipx[0] = cls.netchan.remote_address.ipx[0];
      local_20.ipx[1] = cls.netchan.remote_address.ipx[1];
      local_20.ipx[2] = cls.netchan.remote_address.ipx[2];
      local_20.ipx[3] = cls.netchan.remote_address.ipx[3];
      local_20.ipx[4] = cls.netchan.remote_address.ipx[4];
      local_20.ipx[5] = cls.netchan.remote_address.ipx[5];
      local_20.ipx[6] = cls.netchan.remote_address.ipx[6];
      local_20.ipx[7] = cls.netchan.remote_address.ipx[7];
      local_20.ipx[8] = cls.netchan.remote_address.ipx[8];
      local_20.ipx[9] = cls.netchan.remote_address.ipx[9];
      local_20.port = cls.netchan.remote_address.port;
      goto LAB_0019b90a;
    }
  }
  qVar5 = NET_StringToAdr(rcon_address.string,&local_20);
  if (qVar5 == false) {
    Con_Printf("Unable to resolve rcon address %s\n",rcon_address.string);
    return;
  }
LAB_0019b90a:
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
  local_20.port = uVar2;
  pcVar3 = Cmd_Args();
  Q_strncpy(g_lastrconcommand,pcVar3,0x3ff);
  g_lastrconcommand[0x3ff] = '\0';
  g_rconaddress.type = local_20.type;
  g_rconaddress.ip[0] = local_20.ip[0];
  g_rconaddress.ip[1] = local_20.ip[1];
  g_rconaddress.ip[2] = local_20.ip[2];
  g_rconaddress.ip[3] = local_20.ip[3];
  g_rconaddress.ipx[0] = local_20.ipx[0];
  g_rconaddress.ipx[1] = local_20.ipx[1];
  g_rconaddress.ipx[2] = local_20.ipx[2];
  g_rconaddress.ipx[3] = local_20.ipx[3];
  g_rconaddress.ipx[4] = local_20.ipx[4];
  g_rconaddress.ipx[5] = local_20.ipx[5];
  g_rconaddress.ipx[6] = local_20.ipx[6];
  g_rconaddress.ipx[7] = local_20.ipx[7];
  g_rconaddress.ipx[8] = local_20.ipx[8];
  g_rconaddress.ipx[9] = local_20.ipx[9];
  g_rconaddress.port = local_20.port;
  adr.ip[0] = local_20.ip[0];
  adr.ip[1] = local_20.ip[1];
  adr.ip[2] = local_20.ip[2];
  adr.ip[3] = local_20.ip[3];
  adr.type = local_20.type;
  adr.ipx[0] = local_20.ipx[0];
  adr.ipx[1] = local_20.ipx[1];
  adr.ipx[2] = local_20.ipx[2];
  adr.ipx[3] = local_20.ipx[3];
  adr.ipx[4] = local_20.ipx[4];
  adr.ipx[5] = local_20.ipx[5];
  adr.ipx[6] = local_20.ipx[6];
  adr.ipx[7] = local_20.ipx[7];
  adr.ipx[8] = local_20.ipx[8];
  adr.ipx[9] = local_20.ipx[9];
  adr.port = local_20.port;
  Netchan_OutOfBandPrint(NS_CLIENT,adr,"challenge rcon\n");
  return;
}


// CL_ReadClientDLLData  @ 0019aa50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ReadClientDLLData(void)

{
  uint uVar1;
  uchar local_8010 [32768];
  uint local_10 [3];
  
                    /* Unresolved local var: uchar[32768] data@[???]
                       Unresolved local var: int i@[???] */
  Q_memset(local_8010,0,0x8000);
  FS_Read(local_10,4,1,cls.demofile);
  uVar1 = (*LittleLong)(local_10[0]);
  local_10[0] = 0x8000;
  if (uVar1 < 0x8001) {
    local_10[0] = uVar1;
  }
  FS_Read(local_8010,local_10[0],1,cls.demofile);
  ClientDLL_ReadDemoBuffer(local_10[0],local_8010);
  return;
}


// CL_ReadDemoMessage  @ 0019b450
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


// CL_ReadDemoMessage_OLD  @ 0019ab00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_ReadDemoMessage_OLD(void)

{
  undefined4 uVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  qboolean qVar7;
  longdouble lVar8;
  undefined1 auStack_1804c [65536];
  client_data_t local_804c [7];
  undefined4 auStack_7f60 [13];
  vec_t avStack_7f2c [34];
  vec_t vStack_7ea4;
  vec_t vStack_7ea0;
  int iStack_7e9c;
  int local_4c [4];
  float local_3c [2];
  int32 local_34;
  uint local_30;
  char local_2c [28];
  
                    /* Unresolved local var: int msglen@[???]
                       Unresolved local var: byte[65536] msgbuf@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: float ft@[DW_OP_reg11(ST0)]
                       Unresolved local var: byte cmd@[???]
                       Unresolved local var: int32 curpos@[???]
                       Unresolved local var: float fElapsedTime@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: qboolean bSkipMessage@[???]
                       Unresolved local var: int nElapsedFrames@[???] */
  local_4c[0] = 0;
  if (cls.demofile == (FileHandle_t)0x0) {
    cls.demoplayback = false;
    CL_Disconnect_f();
    Con_Printf("Tried to read a demo message with no demo file\n");
    return false;
  }
                    /* Unresolved local var: uchar[32768] data@[???]
                       Unresolved local var: int i@[???] */
  do {
    while( true ) {
      while( true ) {
        uVar3 = FS_Tell(cls.demofile);
        net_message.cursize = 0;
        FS_Read(local_2c,1,1,cls.demofile);
        FS_Read(local_3c,4,1,cls.demofile);
        lVar8 = (longdouble)(*LittleFloat)(local_3c[0]);
        local_3c[0] = (float)lVar8;
        FS_Read(&local_34,4,1,cls.demofile);
        local_34 = (*LittleLong)(local_34);
        fVar2 = g_demotimescale * (float)realtime - cls.demostarttime;
        if (((local_2c[0] != '\x05') && (local_2c[0] != '\0')) &&
           (cls.timedemo == false && fVar2 <= local_3c[0])) goto LAB_0019affe;
        if (local_2c[0] != '\x02') break;
        cls.demostartframe = host_framecount;
        cls.demostarttime = g_demotimescale * (float)realtime;
      }
      if (local_2c[0] == '\x05') break;
      if (local_2c[0] == '\x03') {
                    /* Unresolved local var: char[64] szCmdName@[???] */
        FS_Read(local_804c,0x40,1,cls.demofile);
        qVar7 = ValidStuffText((char *)local_804c);
        if (qVar7 != false) {
          Cbuf_AddFilteredText((char *)local_804c);
          Cbuf_AddFilteredText("\n");
        }
      }
      else if (local_2c[0] == '\x04') {
                    /* Unresolved local var: float scr_fov_value@[???]
                       Unresolved local var: client_data_t cdat@[???] */
        FS_Read(local_804c,0x20,1,cls.demofile);
        ClientDLL_DemoUpdateClientData(local_804c);
        scr_fov_value = local_804c[0].fov;
      }
      else if (local_2c[0] == '\x06') {
        CL_DemoParseEvent();
      }
      else if (local_2c[0] == '\a') {
                    /* Unresolved local var: int anim@[???]
                       Unresolved local var: int body@[???]
                       Unresolved local var: int i@[???] */
        FS_Read(&local_30,4,1,cls.demofile);
        uVar3 = (*LittleLong)(local_30);
        local_30 = uVar3;
        FS_Read(&local_30,4,1,cls.demofile);
        local_30 = (*LittleLong)(local_30);
        hudWeaponAnim(uVar3,local_30);
      }
      else if (local_2c[0] == '\b') {
        CL_DemoParseSound();
      }
      else {
        if (local_2c[0] != '\t') goto LAB_0019ad6b;
        Q_memset(local_804c,0,0x8000);
        FS_Read(&local_30,4,1,cls.demofile);
        uVar3 = (*LittleLong)(local_30);
        local_30 = 0x8000;
        if (uVar3 < 0x8001) {
          local_30 = uVar3;
        }
        FS_Read(local_804c,local_30,1,cls.demofile);
        ClientDLL_ReadDemoBuffer(local_30,(uchar *)local_804c);
      }
    }
    qVar7 = CL_SwitchToNextDemoSection();
  } while (qVar7 != false);
LAB_0019ad6b:
  if ((cls.timedemo != false) && (CL_ReadDemoMessage_OLD::tdlastdemoframe == host_framecount)) {
    uVar3 = FS_Tell(cls.demofile);
    uVar3 = uVar3 - 9;
LAB_0019affe:
    FS_Seek(cls.demofile,uVar3,FILESYSTEM_SEEK_HEAD);
    return false;
  }
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
      if (nCurEntryIndex == 0) goto LAB_0019b042;
    }
    else {
      cls.demoframecount = cls.demoframecount + 1;
    }
    if (bInFadeout == false) {
      uVar3 = pCurrentEntry->nFlags;
      if (((uVar3 & 0x40) != 0) && (pCurrentEntry->fTrackTime + 0.02 <= fVar2 + 0.5)) {
        bInFadeout = true;
        sf_demo.duration = 0x800;
        sf_demo.holdTime = 0x199;
        sf_demo.r = '\0';
        sf_demo.g = '\0';
        sf_demo.b = '\0';
        sf_demo.a = 0xff;
        sf_demo.fadeFlags = 1;
        V_ScreenFade((char *)0x0,0,&sf_demo);
        uVar3 = pCurrentEntry->nFlags;
      }
      if ((((uVar3 & 0x20) != 0) && (bInFadeout == false)) &&
         (pCurrentEntry->fTrackTime + 0.02 <= fVar2 + 2.0)) {
        sf_demo.fadeFlags = 1;
        bInFadeout = true;
        sf_demo.duration = 0x2000;
        sf_demo.holdTime = 0x199;
        sf_demo.r = '\0';
        sf_demo.g = '\0';
        sf_demo.b = '\0';
        sf_demo.a = 0xff;
        V_ScreenFade((char *)0x0,0,&sf_demo);
      }
    }
  }
LAB_0019b042:
                    /* Unresolved local var: demo_info_t rp@[???] */
  FS_Read(local_804c,0x1b4,1,cls.demofile);
  uVar3 = 0;
  do {
    *(undefined4 *)((int)g_rp.cmd.viewangles + (uVar3 - 4)) =
         *(undefined4 *)((int)auStack_7f60 + uVar3);
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x34);
  uVar3 = 0;
  do {
    uVar4 = uVar3;
    uVar1 = *(undefined4 *)((int)avStack_7f2c + uVar4 + 4);
    *(undefined4 *)(g_rp.movevars.skyName + (uVar4 - 0x44)) =
         *(undefined4 *)((int)avStack_7f2c + uVar4);
    *(undefined4 *)(g_rp.movevars.skyName + (uVar4 - 0x40)) = uVar1;
    uVar3 = uVar4 + 8;
  } while (uVar4 + 8 < 0x80);
  *(undefined4 *)(g_rp.movevars.skyName + (uVar4 - 0x3c)) =
       *(undefined4 *)((int)avStack_7f2c + uVar4 + 8);
  g_rp.view[0] = avStack_7f2c[0x21];
  g_rp.view[1] = vStack_7ea4;
  g_rp.view[2] = vStack_7ea0;
  g_rp.viewmodel = iStack_7e9c;
  iVar5 = 0x1f;
  do {
                    /* Unresolved local var: int i@[???] */
    iVar6 = iVar5 + -1;
    Q_memcpy(dem_frames + iVar5,dem_frames + iVar6,0x1b4);
    iVar5 = iVar6;
  } while (iVar6 != 0);
  uVar3 = 0;
  do {
    uVar4 = uVar3;
    uVar1 = *(undefined4 *)((int)local_804c[0].origin + uVar4 + 4);
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + (uVar4 - 4)) =
         *(undefined4 *)((int)local_804c[0].origin + uVar4);
    *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar4) = uVar1;
    uVar3 = uVar4 + 8;
  } while (uVar3 < 0x1b0);
  dem_frames[0].timestamp = fVar2;
  *(undefined4 *)((int)dem_frames[0].rp.vieworg + uVar4 + 4) =
       *(undefined4 *)((int)local_804c[0].origin + uVar3);
  dem_frames[0].rp.cmd = &dem_frames[0].cmd;
  dem_frames[0].rp.movevars = &dem_frames[0].movevars;
  iVar5 = DemoPlayer_IsActive();
  if (iVar5 == 0) {
    CL_ReadNetchanState_OLD();
  }
  else {
    DemoPlayer_ReadNetchanState
              (&cls.netchan.incoming_sequence,&cls.netchan.incoming_acknowledged,
               &cls.netchan.incoming_reliable_acknowledged,&cls.netchan.incoming_reliable_sequence,
               &cls.netchan.outgoing_sequence,&cls.netchan.reliable_sequence,
               &cls.netchan.last_reliable_sequence);
  }
  iVar5 = FS_Read(local_4c,4,1,cls.demofile);
  if (iVar5 == 4) {
    local_4c[0] = (*LittleLong)(local_4c[0]);
    if (local_4c[0] < 0) {
      Host_EndGame("Demo message length < 0.\n");
      qVar7 = false;
    }
    else if (local_4c[0] < 0x10001) {
      if (local_4c[0] == 0) {
        iVar5 = 0;
      }
      else {
        iVar6 = FS_Read(auStack_1804c,local_4c[0],1,cls.demofile);
        iVar5 = local_4c[0];
        if (iVar6 != local_4c[0]) {
          Host_EndGame("Error reading demo message data.\n");
          return false;
        }
      }
      Q_memcpy(net_message.data,auStack_1804c,iVar5);
      net_message.cursize = local_4c[0];
      qVar7 = true;
    }
    else {
      Host_EndGame("Demo message > MAX_POSSIBLE_MSG");
      qVar7 = false;
    }
    return qVar7;
  }
  Host_EndGame("Bad demo length.\n");
  return false;
}


// CL_ReadNetchanState  @ 00198910
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


// CL_ReadNetchanState_OLD  @ 001987f0
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


// CL_ReadPackets  @ 001a0e60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ReadPackets(void)

{
  netadr_t a;
  netadr_t a_00;
  netadr_t b;
  qboolean qVar1;
  char *pcVar2;
  int iVar3;
  qboolean successfully_received;
  uchar in_stack_ffffff48 [4];
  char local_8c [136];
  
                    /* Unresolved local var: int msg_count@[???] */
  if (cls.state == ca_dedicated) {
    return;
  }
  iVar3 = 0;
  cl.oldtime = cl.time;
  cl.time = cl.time + host_frametime;
LAB_001a0ea0:
  if (cls.demoplayback != false) goto LAB_001a0f80;
  do {
    if (cls.passive == false) {
      qVar1 = NET_GetPacket(NS_CLIENT);
    }
    else {
      qVar1 = NET_GetPacket(NS_MULTICAST);
    }
    while( true ) {
      if (qVar1 == false) {
        if ((0xfa < iVar3) && (cls.demoplayback == false)) {
          in_stack_ffffff48 = (uchar  [4])(iVar3 + -0xfa);
          Con_DPrintf("Ignored %i messages\n");
        }
        CL_SetSolidEntities();
        if (ca_disconnected < cls.state) {
          qVar1 = Netchan_IncomingReady(&cls.netchan);
          if (qVar1 != false) {
            qVar1 = Netchan_CopyNormalFragments(&cls.netchan);
            if (qVar1 != false) {
              MSG_BeginReading();
              CL_ParseServerMessage(false);
            }
            successfully_received = 0xe07104;
            qVar1 = Netchan_CopyFileFragments(&cls.netchan);
            if (qVar1 != false) {
              if (gDownloadFile[0] != '\0') {
                if (gDownloadFile[0] == '!') {
                  SetSecondaryProgressBarText("#GameUI_SecurityModule");
                }
                else {
                  in_stack_ffffff48[0] = 0x80;
                  in_stack_ffffff48[1] = '\0';
                  in_stack_ffffff48[2] = '\0';
                  in_stack_ffffff48[3] = '\0';
                    /* Unresolved local var: char[128] buf@[???] */
                  snprintf(local_8c,0x80,"File \'%s\'",gDownloadFile);
                  SetSecondaryProgressBarText(local_8c);
                }
                successfully_received = 0x42c80000;
                SetSecondaryProgressBar(100.0);
              }
              CL_ProcessFile(successfully_received,(char *)in_stack_ffffff48);
            }
          }
          if (((ca_connecting < cls.state) && (cls.demoplayback == false)) &&
             ((double)cl_timeout.value < realtime - (double)cls.netchan.last_received)) {
            COM_ExplainDisconnection(true,"#GameUI_ServerConnectionTimeout");
            CL_Disconnect();
            return;
          }
        }
        if (cl_shownet.value != 0.0) {
          Con_Printf("\n");
        }
        Netchan_UpdateProgress(&cls.netchan);
        if ((0.0 < scr_downloading.value) && (gDownloadFile[0] != '\0')) {
                    /* Unresolved local var: char[128] buf@[???] */
          if (gDownloadFile[0] == '!') {
            snprintf(local_8c,0x80,"#GameUI_DownloadingSecurityModule");
          }
          else {
            snprintf(local_8c,0x80,"Downloading file \'%s\'",gDownloadFile);
          }
          SetSecondaryProgressBar(scr_downloading.value / 100.0);
          SetSecondaryProgressBarText(local_8c);
          SetLoadingProgressBarStatusText("#GameUI_VerifyingAndDownloading");
        }
        Net_APICheckTimeouts();
        return;
      }
      iVar3 = iVar3 + 1;
      if ((0xfa < iVar3) && (cls.demoplayback == false)) break;
      if (*(int *)net_message.data == -1) {
        CL_ConnectionlessPacket();
        goto LAB_001a0ea0;
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
          in_stack_ffffff48 = net_from.ip;
          qVar1 = NET_CompareAdr(a_00,b);
          if (qVar1 == false) goto LAB_001a0ea0;
          if (cls.passive != false) goto LAB_001a10b8;
        }
LAB_001a0f09:
        if (1 < cls.state - ca_disconnected) {
          if (cls.demoplayback == false) goto LAB_001a0f17;
LAB_001a10f0:
          MSG_BeginReading();
LAB_001a10f5:
          CL_ParseServerMessage(true);
        }
        goto LAB_001a0ea0;
      }
LAB_001a10b8:
      if (cls.state != ca_connecting) goto LAB_001a0f09;
      cls.state = ca_connected;
      if (cls.demoplayback != false) goto LAB_001a10f0;
LAB_001a0f17:
      if (7 < net_message.cursize) {
        qVar1 = Netchan_Process(&cls.netchan);
        if (qVar1 != false) goto LAB_001a10f5;
        goto LAB_001a0ea0;
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
      in_stack_ffffff48 = (uchar  [4])net_message.cursize;
      Con_Printf("CL_ReadPackets:  undersized packet %i bytes from %s\n",net_message.cursize,pcVar2)
      ;
      if (cls.demoplayback == false) break;
LAB_001a0f80:
      qVar1 = CL_ReadDemoMessage();
    }
  } while( true );
}


// CL_ReallocateDynamicData  @ 001ae340
void CL_ReallocateDynamicData(int nMaxClients)

{
  cl.max_edicts = COM_EntsForPlayerSlots(nMaxClients);
  if (cl.max_edicts < 1) {
    Sys_Error("CL_ReallocateDynamicData allocating 0 entities");
  }
  if (cl_entities != (cl_entity_t *)0x0) {
    Con_Printf("CL_Reallocate cl_entities\n");
  }
  cl_entities = Mem_ZeroMalloc(cl.max_edicts * 3000);
  R_AllocObjects(cl.max_edicts);
  Q_memset(cl.frames,0,CL_UPDATE_BACKUP * 0x42b8);
  return;
}


// CL_RecordHUDCommand  @ 00198b90
void CL_RecordHUDCommand(char *cmdname)

{
  longdouble lVar1;
  undefined1 local_55;
  float local_54;
  int32 local_50;
  char local_4c [63];
  undefined1 local_d;
  
                    /* Unresolved local var: hud_command_t demcmd@[???] */
  local_55 = 3;
  lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
  local_54 = (float)lVar1;
  local_50 = (*LittleLong)(host_framecount - cls.demostartframe);
  Q_memset(local_4c,0,0x40);
  Q_strncpy(local_4c,cmdname,0x3f);
  local_d = 0;
  FS_Write(&local_55,0x49,1,cls.demofile);
  return;
}


// CL_Record_f  @ 00199ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Record_f(void)

{
  demoentry_t *pdVar1;
  FileHandle_t file;
  FileHandle_t file_00;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  uint uVar5;
  uint pos;
  longdouble lVar6;
  int local_744;
  undefined1 local_734 [1024];
  char local_334 [260];
  char local_230 [260];
  char local_12c [259];
  undefined1 local_29;
  float local_28;
  int32 local_24;
  undefined1 local_1d [13];
  
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
            local_744 = -1;
            if (iVar2 == 3) {
              pcVar3 = Cmd_Argv(2);
              local_744 = Q_atoi(pcVar3);
              Con_Printf("Forcing CD track to %i\n",local_744);
            }
            pcVar3 = Cmd_Argv(1);
            snprintf(local_334,0x100,"%s",pcVar3);
            COM_AddExtension(local_334,".dem",0x104);
            qVar4 = COM_HasFileExtension(local_334,"dem");
            if (qVar4 == false) {
              Con_Printf("Error: couldn\'t open demo file %s\n",local_334);
            }
            else {
              Con_Printf("recording to %s.\n",local_334);
              cls.demofile = FS_OpenPathID(local_334,"wb","GAMECONFIG");
              if (cls.demofile == (FileHandle_t)0x0) {
                Con_Printf("Error: couldn\'t open demo file %s, demo files must have .dem extension.\n"
                           ,local_334);
              }
              else {
                Q_memset(&demoheader,0,0x220);
                Q_strncpy(demoheader.szFileStamp,"HLDEMO",6);
                COM_FileBase((cl.worldmodel)->name,local_230);
                Q_strncpy(demoheader.szMapName,local_230,0x103);
                demoheader.szMapName[0x103] = '\0';
                Q_strncpy(local_12c,com_gamedir,0x103);
                local_29 = 0;
                COM_FileBase(local_12c,demoheader.szDllDir);
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
                pCurrentEntry->nFlags = 0;
                pdVar1->nCDTrack = local_744;
                pdVar1->fTrackTime = 0.0;
                uVar5 = FS_Tell(cls.demofile);
                pdVar1->nOffset = uVar5;
                cls.demowaiting = true;
                cls.demorecording = true;
                FS_Tell(cls.demofile);
                local_1d[0] = 5;
                FS_Write(local_1d,1,1,cls.demoheader);
                lVar6 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
                local_28 = (float)lVar6;
                FS_Write(&local_28,4,1,cls.demoheader);
                local_24 = (*LittleLong)(host_framecount - cls.demostartframe);
                FS_Write(&local_24,4,1,cls.demoheader);
                FS_Flush(cls.demoheader);
                pos = FS_Tell(cls.demoheader);
                FS_Seek(cls.demoheader,0,FILESYSTEM_SEEK_HEAD);
                file_00 = cls.demoheader;
                file = cls.demofile;
                    /* Unresolved local var: int copysize@[???]
                       Unresolved local var: char[1024] copybuf@[???] */
                uVar5 = pos;
                if (0x400 < (int)pos) {
                  do {
                    uVar5 = uVar5 - 0x400;
                    FS_Read(local_734,0x400,1,file_00);
                    FS_Write(local_734,0x400,1,file);
                  } while (0x400 < (int)uVar5);
                  uVar5 = (pos - 0x400) - (pos - 0x401 & 0xfffffc00);
                }
                FS_Read(local_734,uVar5,1,file_00);
                FS_Write(local_734,uVar5,1,file);
                FS_Flush(file_00);
                FS_Flush(file);
                FS_Seek(cls.demoheader,pos,FILESYSTEM_SEEK_HEAD);
                cls.demoframecount = 0;
                cls.demostartframe = host_framecount;
                cls.demostarttime = (float)realtime;
                uVar5 = FS_Tell(cls.demofile);
                pCurrentEntry->nFileLength = uVar5 - pCurrentEntry->nOffset;
                pdVar1 = demodir.p_rgEntries;
                pCurrentEntry = demodir.p_rgEntries + 1;
                demodir.p_rgEntries[1].nEntryType = 1;
                snprintf(pdVar1[1].szDescription,0x40,"Playback");
                pdVar1 = pCurrentEntry;
                pCurrentEntry->nFlags = 0;
                pdVar1->nCDTrack = local_744;
                pdVar1->fTrackTime = 0.0;
                uVar5 = FS_Tell(cls.demofile);
                pdVar1->nOffset = uVar5;
                local_1d[0] = 2;
                FS_Write(local_1d,1,1,cls.demofile);
                lVar6 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
                local_28 = (float)lVar6;
                FS_Write(&local_28,4,1,cls.demofile);
                local_24 = (*LittleLong)(host_framecount - cls.demostartframe);
                FS_Write(&local_24,4,1,cls.demofile);
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
  return;
}


// CL_RedoPrediction  @ 00194370
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_RedoPrediction(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  playermove_t_conflict *ppVar4;
  double dVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  local_state_t *to;
  int iVar14;
  usercmd_t *u;
  float fVar15;
  local_state_t *local_60;
  usercmd_t *local_44;
  float local_30;
  float local_2c;
  float local_28;
  double local_24 [2];
  
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
                       Unresolved local var: clientdata_t * fcd@[???]
                       Unresolved local var: double dTime@[???]
                       Unresolved local var: int stoppoint@[???]
                       Unresolved local var: entity_state_t * fs@[???]
                       Unresolved local var: clientdata_t * tcd@[???] */
  if ((cls.state != ca_active) || (cls.spectator != false)) goto LAB_001943d0;
  pmove = &g_clmove;
  CL_SetUpPlayerPrediction(false,false);
  iVar7 = cl.parsecountmod;
  dVar5 = realtime;
  if ((cl.intermission != 0) ||
     ((cl.validsequence == 0 ||
      (CL_UPDATE_MASK <= (cls.netchan.outgoing_sequence + 1) - cls.netchan.incoming_acknowledged))))
  goto LAB_001943d0;
  cl.simangles[0] = cl.viewangles[0];
  cl.simangles[1] = cl.viewangles[1];
  cl.simangles[2] = cl.viewangles[2];
  if (cls.demoplayback != false) goto LAB_001943d0;
  iVar14 = cl.parsecountmod * 0x42b8;
  iVar8 = cl.parsecountmod * 0x1930;
  iVar10 = iVar14 + 0xc7f6fc + cl.playernum * 0x154;
  uVar6 = 0;
  iVar9 = iVar8 + 0xd8b7e4;
  do {
    uVar2 = *(undefined4 *)(iVar10 + 4 + uVar6);
    *(undefined4 *)(iVar9 + uVar6) = *(undefined4 *)(iVar10 + uVar6);
    *(undefined4 *)(iVar8 + 0xd8b7e8 + uVar6) = uVar2;
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x150);
  *(undefined4 *)(iVar9 + uVar6) = *(undefined4 *)(iVar10 + uVar6);
  uVar6 = 0;
  iVar10 = iVar7 * 0x1930 + 0xd8b938;
  do {
    uVar2 = *(undefined4 *)(iVar14 + 0xc82188 + uVar6);
    *(undefined4 *)(iVar10 + uVar6) = *(undefined4 *)(iVar14 + 0xc82184 + uVar6);
    *(undefined4 *)(iVar7 * 0x1930 + 0xd8b93c + uVar6) = uVar2;
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x1d8);
  *(undefined4 *)(iVar10 + uVar6) = *(undefined4 *)(iVar14 + 0xc82184 + uVar6);
  Q_memcpy(cl.predicted_frames[iVar7].weapondata,cl.frames[iVar7].weapondata,0x1600);
  iVar10 = cl.parsecountmod;
  if (cl.frames[iVar7].invalid != false) goto LAB_001943d0;
  local_24[0] = cl.frames[iVar7].time;
  uVar6 = CL_UPDATE_MASK & cls.netchan.incoming_acknowledged;
  cl.onground = -1;
  if (pushed == 0) {
    pushed = 1;
    oldphysent = pmove->numphysent;
    oldvisent = pmove->numvisent;
  }
  else {
    Con_Printf("CL_PushPMStates called with pushed stack\n");
  }
  CL_SetSolidPlayers(cl.playernum);
  g_i = 1;
  local_60 = cl.predicted_frames + iVar10;
  local_44 = &cl.commands[uVar6].cmd;
  if ((CL_UPDATE_BACKUP < 3) ||
     (uVar11 = cls.netchan.incoming_acknowledged + 1, uVar12 = CL_UPDATE_MASK,
     cls.netchan.outgoing_sequence <= (int)uVar11)) {
    iVar7 = 1;
    to = (local_state_t *)0x0;
    u = (usercmd_t *)0x0;
  }
  else {
    do {
      iVar7 = g_i;
      uVar6 = uVar12 & uVar11;
      u = &cl.commands[uVar6].cmd;
      uVar13 = cl.parsecountmod + g_i & uVar12;
      to = cl.predicted_frames + uVar13;
      CL_RunUsercmd(local_60,to,u,false,local_24,uVar11);
      iVar10 = cls.netchan.incoming_acknowledged;
      uVar12 = CL_UPDATE_MASK;
      cl.commands[uVar6].processedfuncs = true;
      uVar11 = iVar7 + iVar10 & uVar12;
      cl.predicted_origins[uVar11][0] = cl.predicted_frames[uVar13].playerstate.origin[0];
      cl.predicted_origins[uVar11][1] = cl.predicted_frames[uVar13].playerstate.origin[1];
      cl.predicted_origins[uVar11][2] = cl.predicted_frames[uVar13].playerstate.origin[2];
      if (((float)dVar5 <= cl.commands[uVar6].senttime) ||
         (iVar7 = iVar7 + 1, local_60 = to, g_i = iVar7, local_44 = u,
         CL_UPDATE_BACKUP + -1 <= iVar7)) break;
      uVar11 = iVar10 + iVar7;
    } while ((int)uVar11 < cls.netchan.outgoing_sequence);
  }
  ppVar4 = pmove;
  if (pushed == 0) {
    Con_Printf("CL_PopPMStates called without stack\n");
  }
  else {
    pushed = pushed + -1;
    pmove->numphysent = oldphysent;
    ppVar4->numvisent = oldvisent;
  }
  if (CL_UPDATE_MASK <= iVar7) goto LAB_001943d0;
  if (to == (local_state_t *)0x0) {
    to = local_60;
    u = local_44;
  }
  fVar15 = *(float *)(local_44 + 1);
  if (*(float *)(u + 1) == fVar15) {
    fVar3 = 0.0;
  }
  else {
    fVar15 = ((float)dVar5 - fVar15) / (*(float *)(u + 1) - fVar15);
    fVar3 = 0.0;
    if (0.0 <= fVar15) {
      fVar3 = fVar15;
    }
  }
  fVar15 = (to->playerstate).origin[0];
  if (((128.0 < ABS(fVar15 - (local_60->playerstate).origin[0])) ||
      (128.0 < ABS((to->playerstate).origin[1] - (local_60->playerstate).origin[1]))) ||
     (128.0 < ABS((to->playerstate).origin[2] - (local_60->playerstate).origin[2]))) {
    cl.simvel[0] = (to->client).velocity[0];
    cl.simvel[1] = (to->client).velocity[1];
    cl.simvel[2] = (to->client).velocity[2];
    cl.simorg[0] = (to->playerstate).origin[0];
    cl.simorg[1] = (to->playerstate).origin[1];
    cl.simorg[2] = (to->playerstate).origin[2];
    cl.punchangle[0] = (to->client).punchangle[0];
    cl.punchangle[1] = (to->client).punchangle[1];
    cl.punchangle[2] = (to->client).punchangle[2];
LAB_0019485e:
    cl.viewheight[0] = (to->client).view_ofs[0];
    cl.viewheight[1] = (to->client).view_ofs[1];
    cl.viewheight[2] = (to->client).view_ofs[2];
  }
  else {
                    /* Unresolved local var: int i@[???] */
    fVar1 = (local_60->playerstate).origin[0];
    cl.simorg[0] = (fVar15 - fVar1) * fVar3 + fVar1;
    fVar15 = (local_60->playerstate).origin[1];
    cl.simorg[1] = ((to->playerstate).origin[1] - fVar15) * fVar3 + fVar15;
    fVar15 = (local_60->playerstate).origin[2];
    cl.simorg[2] = ((to->playerstate).origin[2] - fVar15) * fVar3 + fVar15;
                    /* Unresolved local var: int i@[???] */
    fVar15 = (local_60->client).velocity[0];
    cl.simvel[0] = ((to->client).velocity[0] - fVar15) * fVar3 + fVar15;
    fVar15 = (local_60->client).velocity[1];
    cl.simvel[1] = ((to->client).velocity[1] - fVar15) * fVar3 + fVar15;
    fVar15 = (local_60->client).velocity[2];
    cl.simvel[2] = ((to->client).velocity[2] - fVar15) * fVar3 + fVar15;
                    /* Unresolved local var: int i@[???] */
    fVar15 = (local_60->client).punchangle[0];
    cl.punchangle[0] = ((to->client).punchangle[0] - fVar15) * fVar3 + fVar15;
    fVar15 = (local_60->client).punchangle[1];
    cl.punchangle[1] = ((to->client).punchangle[1] - fVar15) * fVar3 + fVar15;
    fVar15 = (local_60->client).punchangle[2];
    cl.punchangle[2] = ((to->client).punchangle[2] - fVar15) * fVar3 + fVar15;
    if ((local_60->playerstate).usehull != (to->playerstate).usehull) goto LAB_0019485e;
    iVar7 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      fVar15 = (local_60->client).view_ofs[iVar7];
      cl.viewheight[iVar7] = ((to->client).view_ofs[iVar7] - fVar15) * fVar3 + fVar15;
      iVar7 = iVar7 + 1;
    } while (iVar7 != 3);
  }
  if (((to->client).flags & 0x200) == 0) {
    cl.onground = -1;
    cl.waterlevel = (to->client).waterlevel;
    cl.usehull = (to->playerstate).usehull;
    cl.stats[2] = (to->client).viewmodel;
    cl.moving = 0;
LAB_001948d2:
    fVar15 = (float)cl_correction_time;
    if (((0.0 < fVar15) && (cl_nosmooth.value == 0.0)) && (cl_smoothtime.value != 0.0)) {
                    /* Unresolved local var: float frac@[???]
                       Unresolved local var: vec3_t delta@[???] */
      if (cl_smoothtime.value <= 0.0) {
        Cvar_DirectSet(&cl_smoothtime,"0.1");
        fVar15 = (float)cl_correction_time;
      }
      fVar3 = 0.0;
      if (0.0 <= fVar15) {
        fVar3 = fVar15;
      }
      if (cl_smoothtime.value <= fVar3) {
        fVar3 = cl_smoothtime.value;
      }
      cl_correction_time = (double)fVar3;
      local_30 = cl.simorg[0] - CL_PredictMove::lastsimorg[0];
      local_2c = cl.simorg[1] - CL_PredictMove::lastsimorg[1];
      local_28 = cl.simorg[2] - CL_PredictMove::lastsimorg[2];
      VectorScale(&local_30,1.0 - fVar3 / cl_smoothtime.value,&local_30);
      cl.simorg[0] = CL_PredictMove::lastsimorg[0] + local_30;
      cl.simorg[1] = CL_PredictMove::lastsimorg[1] + local_2c;
      cl.simorg[2] = CL_PredictMove::lastsimorg[2] + local_28;
    }
  }
  else {
    cl.onground = g_lastground;
    cl.waterlevel = (to->client).waterlevel;
    cl.usehull = (to->playerstate).usehull;
    cl.stats[2] = (to->client).viewmodel;
    cl.moving = 0;
    if ((g_lastground < 1) || (cl.num_entities <= g_lastground)) goto LAB_001948d2;
                    /* Unresolved local var: vec3_t delta@[???] */
    local_30 = cl_entities[g_lastground].curstate.origin[0] -
               cl_entities[g_lastground].prevstate.origin[0];
    local_2c = cl_entities[g_lastground].curstate.origin[1] -
               cl_entities[g_lastground].prevstate.origin[1];
    local_28 = 0.0;
    fVar15 = Length(&local_30);
    if (0.0 < fVar15) {
      cl.moving = 1;
    }
    else if (cl.moving == 0) goto LAB_001948d2;
    cl_correction_time = 0.0;
  }
  CL_PredictMove::lastsimorg[0] = cl.simorg[0];
  CL_PredictMove::lastsimorg[1] = cl.simorg[1];
  CL_PredictMove::lastsimorg[2] = cl.simorg[2];
  CL_SetIdealPitch();
LAB_001943d0:
  CL_CheckPredictionError();
  return;
}


// CL_RegisterCustomization  @ 0019dcc0
void CL_RegisterCustomization(resource_t *resource)

{
  uint playernumber;
  int iVar1;
  qboolean qVar2;
  customization_s_conflict *pcVar3;
  
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: qboolean bFound@[???] */
  playernumber = (uint)resource->playernum;
  pcVar3 = cl.players[playernumber].customdata.pNext;
  if (pcVar3 != (customization_s_conflict *)0x0) {
    do {
      iVar1 = Q_memcmp((pcVar3->resource).rgucMD5_hash,resource->rgucMD5_hash,0x10);
      if (iVar1 == 0) {
        Con_DPrintf("Duplicate resource received and ignored.\n");
        return;
      }
      pcVar3 = pcVar3->pNext;
    } while (pcVar3 != (customization_s_conflict *)0x0);
    playernumber = (uint)resource->playernum;
  }
  qVar2 = COM_CreateCustomization
                    ((customization_t *)&cl.players[playernumber].customdata,resource,playernumber,1
                     ,(customization_t **)0x0,(int *)0x0);
  if (qVar2 != false) {
    return;
  }
  Con_Printf("Unable to create custom decal for player %i\n",(uint)resource->playernum);
  return;
}


// CL_RegisterResources  @ 001acf90
void CL_RegisterResources(sizebuf_t *msg)

{
  char *s;
  CRC32_t local_10 [3];
  
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
        Sys_Error("CL_ReallocateDynamicData allocating 0 entities");
      }
      if (cl_entities != (cl_entity_t *)0x0) {
        Con_Printf("CL_Reallocate cl_entities\n");
      }
      cl_entities = Mem_ZeroMalloc(cl.max_edicts * 3000);
      R_AllocObjects(cl.max_edicts);
      Q_memset(cl.frames,0,CL_UPDATE_BACKUP * 0x42b8);
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
      }
    }
    return;
  }
  Con_Printf("Client world model is NULL\n");
  COM_ExplainDisconnection(true,"Client world model is NULL\n");
  CL_Disconnect();
  return;
}


// CL_RemoveCustomization  @ 001ade30
void CL_RemoveCustomization(int nPlayerNum,customization_t *pRemove)

{
  customization_s *pcVar1;
  customization_t *pcVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *p;
  int iVar5;
  
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: int i@[???] */
                    /* Unresolved local var: customization_t * pNext@[???]
                       Unresolved local var: cachewad_t * pWad@[???]
                       Unresolved local var: cacheentry_t * pic@[???] */
  pcVar2 = (customization_t *)&cl.players[nPlayerNum].customdata;
  pcVar1 = (customization_t *)cl.players[nPlayerNum].customdata.pNext;
  while (pcVar1 != (customization_t *)0x0) {
    if (pRemove == pcVar1) {
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
          iVar5 = p[1];
          if (0 < (int)p[2]) {
            iVar4 = 0;
            do {
              pvVar3 = Cache_Check((cache_user_t *)(iVar5 + 0x40));
              if (pvVar3 != (void *)0x0) {
                Cache_Free((cache_user_t *)(iVar5 + 0x40));
              }
              iVar4 = iVar4 + 1;
              iVar5 = iVar5 + 0x44;
            } while (iVar4 < (int)p[2]);
          }
          Mem_Free((void *)*p);
          Mem_Free((void *)p[1]);
          p = pRemove->pInfo;
        }
        Mem_Free(p);
      }
      Mem_Free(pRemove);
      pcVar2->pNext = pcVar1;
    }
    else {
      pcVar2 = pcVar1;
      pcVar1 = pcVar1->pNext;
    }
  }
  return;
}


// CL_RemoveDemo_f  @ 00197ac0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_RemoveDemo_f(void)

{
  int iVar1;
  char *pcVar2;
  qboolean qVar3;
  FILE *src;
  int iVar4;
  uint uVar5;
  demoentry_t *pdVar6;
  int *piVar7;
  demoentry_t *pdVar8;
  int *piVar9;
  byte bVar10;
  int local_348;
  int local_344;
  char local_330 [260];
  char local_22c [260];
  char local_128 [255];
  undefined1 local_29;
  int local_24;
  void *local_20;
  
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
  bVar10 = 0;
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
            snprintf(local_330,0x100,"%s",pcVar2);
            COM_DefaultExtension(local_330,".dem");
            qVar3 = COM_HasFileExtension(local_330,"dem");
            if (qVar3 == false) {
              Con_Printf("Error: couldn\'t open demo file %s, demo files must have .dem extension.\n"
                         ,local_330);
            }
            else {
              Con_Printf("Removing segment %i from demo %s.\n",iVar1,local_330);
              Q_strncpy(local_128,local_330,0xff);
              local_29 = 0;
              src = FS_Open(local_128,"rb");
              if (src == (FILE *)0x0) {
                Con_Printf("Error: couldn\'t open demo file %s for segment removal.\n",local_330);
              }
              else {
                COM_StripExtension(local_330,local_22c);
                COM_AddExtension(local_22c,".dm2",0x104);
                qVar3 = COM_HasFileExtension(local_330,"dm2");
                if (qVar3 == false) {
                  Con_Printf("Error: couldn\'t open temporary file %s.\n",local_330);
                  FS_Close(src);
                }
                else {
                  cls.demofile = FS_OpenPathID(local_22c,"w+b","GAMECONFIG");
                  if (cls.demofile == (FileHandle_t)0x0) {
                    Con_Printf("Error: couldn\'t open %s.\n",local_330);
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
                            local_24 = demodir.nEntries + -1;
                            local_20 = Mem_Malloc(local_24 * 0x5c);
                            if (0 < demodir.nEntries) {
                              local_348 = 0;
                              local_344 = 0;
                              do {
                                if (local_348 != iVar1 + -1) {
                                  iVar4 = local_344 * 0x5c;
                                  uVar5 = 0x5c;
                                  local_344 = local_344 + 1;
                                  piVar7 = (int *)(iVar4 + (int)local_20);
                                  pdVar6 = demodir.p_rgEntries + local_348;
                                  pdVar8 = pdVar6;
                                  piVar9 = piVar7;
                                  if (((uint)piVar7 & 4) != 0) {
                                    piVar9 = piVar7 + (uint)bVar10 * -2 + 1;
                                    pdVar8 = (demoentry_t *)((int)pdVar6 + (uint)bVar10 * -8 + 4);
                                    *piVar7 = pdVar6->nEntryType;
                                    uVar5 = 0x58;
                                  }
                                  for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                                    *piVar9 = pdVar8->nEntryType;
                                    pdVar8 = (demoentry_t *)((int)pdVar8 + (uint)bVar10 * -8 + 4);
                                    piVar9 = piVar9 + (uint)bVar10 * -2 + 1;
                                  }
                                  uVar5 = FS_Tell(cls.demofile);
                                  piVar7[0x15] = uVar5;
                                  FS_Seek(src,pdVar6->nOffset,FILESYSTEM_SEEK_HEAD);
                                  CL_DemoCopyFileChunk(cls.demofile,src,piVar7[0x16]);
                                }
                                local_348 = local_348 + 1;
                              } while (local_348 < demodir.nEntries);
                            }
                            demoheader.nDirectoryOffset = FS_Tell(cls.demofile);
                            FS_Write(&local_24,4,1,cls.demofile);
                            if (0 < local_24) {
                              iVar1 = 0;
                              do {
                                iVar4 = iVar1 * 0x5c;
                                iVar1 = iVar1 + 1;
                                FS_Write((void *)(iVar4 + (int)local_20),0x5c,1,cls.demofile);
                              } while (iVar1 < local_24);
                            }
                            FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
                            FS_Write(&demoheader,0x220,1,cls.demofile);
                            FS_Close(cls.demofile);
                            cls.demofile = (FileHandle_t)0x0;
                            FS_Close(src);
                            Con_Printf("Replacing old demo with edited version.\n");
                            unlink(local_128);
                            rename(local_22c,local_128);
                            Mem_Free(local_20);
                            Mem_Free(demodir.p_rgEntries);
                            demodir.nEntries = 0;
                            demodir.p_rgEntries = (demoentry_t *)0x0;
                            return;
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
                      Con_Printf("%s is not a demo file\n",local_330);
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
  return;
}


// CL_RemoveFromResourceList  @ 001ad280
void CL_RemoveFromResourceList(resource_t *pResource)

{
  resource_t *prVar1;
  resource_t *prVar2;
  
  if ((pResource->pPrev == (resource_s *)0x0) ||
     (prVar1 = pResource->pNext, prVar1 == (resource_t *)0x0)) {
    Sys_Error("Mislinked resource in CL_RemoveFromResourceList");
    prVar1 = pResource->pNext;
  }
  if ((pResource == prVar1) || (prVar2 = pResource->pPrev, prVar2 == pResource)) {
    Sys_Error("Attempt to free last entry in list.");
    prVar2 = pResource->pPrev;
    prVar1 = pResource->pNext;
  }
  prVar2->pNext = prVar1;
  pResource->pNext->pPrev = pResource->pPrev;
  pResource->pPrev = (resource_s *)0x0;
  pResource->pNext = (resource_s *)0x0;
  return;
}


// CL_RequestMissingResources  @ 001ae290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_RequestMissingResources(void)

{
                    /* Unresolved local var: resource_t * p@[???] */
  if (cls.dl.doneregistering == false) {
    if ((cls.dl.custom == false) && (cls.state != ca_uninitialized)) {
      return false;
    }
    if (cl.resourcesneeded.pNext == &cl.resourcesneeded) {
      cls.dl.custom = false;
      cls.dl.doneregistering = true;
    }
    else if (((cl.resourcesneeded.pNext)->ucFlags & 2) == 0) {
      CL_MoveToOnHandList(cl.resourcesneeded.pNext);
      return true;
    }
  }
  return false;
}


// CL_ResetEvent  @ 001911e0
void CL_ResetEvent(event_info_t *ei)

{
  ei->index = 0;
  Q_memset(&ei->args,0,0x48);
  ei->fire_time = 0.0;
  ei->flags = 0;
  return;
}


// CL_ResetFrame  @ 001afb00
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
  frame->choked = false;
  frame->latency = 0.0;
  frame->eventbytes = 0;
  frame->msgbytes = 0;
  frame->time = cl.mtime[0];
  return;
}


// CL_ResetFrameStats  @ 0018c4d0
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


// CL_ResetLatchedState  @ 0018c080
void CL_ResetLatchedState(int pnum,packet_entities_t *pack,cl_entity_t_conflict2 *ent)

{
                    /* Unresolved local var: int bytenum@[???]
                       Unresolved local var: int bitnum@[???] */
  if (((uint)pack->flags[pnum >> 3] & 1 << ((byte)pnum & 7)) != 0) {
    (ent->latched).prevorigin[0] = (ent->curstate).origin[0];
    (ent->latched).prevorigin[1] = (ent->curstate).origin[1];
    (ent->latched).prevorigin[2] = (ent->curstate).origin[2];
    (ent->latched).prevangles[0] = (ent->curstate).angles[0];
    (ent->latched).prevangles[1] = (ent->curstate).angles[1];
    (ent->latched).prevangles[2] = (ent->curstate).angles[2];
    R_ResetLatched((cl_entity_t *)ent,true);
    CL_ResetPositions((cl_entity_t *)ent);
    if (((ent->curstate).starttime != 0.0) && ((ent->curstate).impacttime != 0.0)) {
      ent->lastmove = (float)cl.time;
      return;
    }
  }
  return;
}


// CL_ResetPositions  @ 00194de0
void CL_ResetPositions(cl_entity_t *ent)

{
  int iVar1;
  uint uVar2;
  undefined4 local_28 [8];
  
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


// CL_Restore  @ 001af670
void CL_Restore(char *fileName)

{
  FileHandle_t stream;
  int iVar1;
  char *pcVar2;
  int entity;
  uint flags;
  short local_5c;
  undefined1 local_5a;
  byte local_59;
  vec_t local_58 [3];
  char local_4c [16];
  int local_3c [4];
  int local_2c [3];
  int local_20 [4];
  
                    /* Unresolved local var: DECALLIST decalList@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int decalCount@[???]
                       Unresolved local var: int temp@[???]
                       Unresolved local var: int mapCount@[???]
                       Unresolved local var: FileHandle_t pFile@[???]
                       Unresolved local var: char[16] name@[???]
                       Unresolved local var: char * pMapName@[???] */
  stream = FS_Open(fileName,"rb");
  if (stream != (FileHandle_t)0x0) {
    FS_SetVBuf(stream,(char *)0x0,0,0x1000);
    FS_Read(local_20,4,1,stream);
    FS_Read(local_3c,4,1,stream);
    if (local_20[0] == 0x564c4156) {
      FS_Read(local_2c,4,1,stream);
      local_3c[0] = 0;
      if (0 < local_2c[0]) {
        do {
          FS_Read(local_4c,0x10,1,stream);
          FS_Read(&local_5c,2,1,stream);
          FS_Read(&local_5a,1,1,stream);
          FS_Read(&local_59,1,1,stream);
          FS_Read(local_58,0xc,1,stream);
          if (r_decals.value != 0.0) {
            local_20[0] = Draw_DecalIndexFromName(local_4c);
            flags = (uint)local_59;
            entity = (int)local_5c;
            iVar1 = Draw_DecalIndex(local_20[0]);
            R_DecalShoot(iVar1,entity,0,local_58,flags);
          }
          local_3c[0] = local_3c[0] + 1;
        } while (local_3c[0] < local_2c[0]);
      }
    }
    FS_Close(stream);
  }
  iVar1 = MSG_ReadByte();
  local_3c[0] = 0;
  if (0 < iVar1) {
    do {
      pcVar2 = MSG_ReadString();
      Con_Printf("Loading decals from %s\n",pcVar2);
      local_3c[0] = local_3c[0] + 1;
    } while (local_3c[0] < iVar1);
  }
  return;
}


// CL_Retry_f  @ 0019c390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Retry_f(void)

{
  char local_110 [268];
  
                    /* Unresolved local var: char[260] szCommand@[???] */
  if (cls.passive == false) {
    snprintf(local_110,0x104,"connect %s\n",0xe0a50c);
  }
  else {
    snprintf(local_110,0x104,"listen %s\n",0xe0a50c);
  }
  Cbuf_AddText(local_110);
  Con_Printf("Commencing connection retry to %s\n",0xe0a50c);
  return;
}


// CL_Retry_f  @ 0019c410
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


// CL_RunUsercmd  @ 001928f0
void CL_RunUsercmd(local_state_t *from,local_state_t *to,usercmd_t *u,qboolean runfuncs,
                  double *pfElapsed,uint random_seed)

{
  byte bVar1;
  vec_t vVar2;
  float fVar3;
  playermove_t_conflict *ppVar4;
  uint uVar5;
  local_state_t *plVar6;
  local_state_t *plVar7;
  local_state_t local_19b4;
  usercmd_s local_84;
  usercmd_t local_50;
  
                    /* Unresolved local var: usercmd_t cmd@[???]
                       Unresolved local var: entity_state_t * fs@[???]
                       Unresolved local var: entity_state_t * ts@[???]
                       Unresolved local var: clientdata_t * fcd@[???]
                       Unresolved local var: clientdata_t * tcd@[???] */
  ppVar4 = pmove;
  bVar1 = u->msec;
  uVar5 = 0;
  fVar3 = (float)bVar1;
  if (50.0 < fVar3) {
                    /* Unresolved local var: local_state_t temp@[???]
                       Unresolved local var: usercmd_t split@[???] */
    uVar5 = 0;
    do {
      *(undefined4 *)((int)local_50.viewangles + (uVar5 - 4)) =
           *(undefined4 *)((int)u->viewangles + (uVar5 - 4));
      uVar5 = uVar5 + 4;
    } while (uVar5 < 0x34);
    local_50.msec = (byte)(int)(fVar3 * 0.5);
    CL_RunUsercmd(from,&local_19b4,&local_50,runfuncs,pfElapsed,random_seed);
    local_50.impulse = '\0';
    local_50.weaponselect = '\0';
    CL_RunUsercmd(&local_19b4,to,&local_50,runfuncs,pfElapsed,random_seed);
    return;
  }
  do {
    *(undefined4 *)((int)local_84.viewangles + (uVar5 - 4)) =
         *(undefined4 *)((int)u->viewangles + (uVar5 - 4));
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x34);
  pmove->time = (float)*pfElapsed * 1000.0;
  ppVar4->server = false;
  ppVar4->multiplayer = (uint)(1 < cl.maxclients);
  ppVar4->runfuncs = runfuncs;
  ppVar4->frametime = (float)bVar1 / 1000.0;
  uVar5 = 0x1930;
  plVar6 = from;
  plVar7 = to;
  if (((uint)to & 4) != 0) {
    plVar7 = (local_state_t *)&(to->playerstate).number;
    uVar5 = 0x192c;
    plVar6 = (local_state_t *)&(from->playerstate).number;
    (to->playerstate).entityType = (from->playerstate).entityType;
  }
  for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    (plVar7->playerstate).entityType = (plVar6->playerstate).entityType;
    plVar6 = (local_state_t *)&(plVar6->playerstate).number;
    plVar7 = (local_state_t *)&(plVar7->playerstate).number;
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
  ppVar4->origin[0] = (from->playerstate).origin[0];
  ppVar4->origin[1] = (from->playerstate).origin[1];
  ppVar4->origin[2] = (from->playerstate).origin[2];
  ppVar4->basevelocity[0] = (from->playerstate).basevelocity[0];
  ppVar4->basevelocity[1] = (from->playerstate).basevelocity[1];
  ppVar4->basevelocity[2] = (from->playerstate).basevelocity[2];
  ppVar4->punchangle[0] = (from->client).punchangle[0];
  ppVar4->punchangle[1] = (from->client).punchangle[1];
  ppVar4->punchangle[2] = (from->client).punchangle[2];
  ppVar4->angles[0] = (from->playerstate).angles[0];
  ppVar4->angles[1] = (from->playerstate).angles[1];
  ppVar4->angles[2] = (from->playerstate).angles[2];
  ppVar4->oldangles[0] = (from->playerstate).angles[0];
  ppVar4->oldangles[1] = (from->playerstate).angles[1];
  ppVar4->oldangles[2] = (from->playerstate).angles[2];
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
  fVar3 = movevars.maxspeed;
  ppVar4 = pmove;
  pmove->physinfo[0xff] = '\0';
  ppVar4->maxspeed = fVar3;
  ppVar4->clientmaxspeed = (from->client).maxspeed;
  uVar5 = 0;
  do {
    *(undefined4 *)((int)(ppVar4->cmd).viewangles + (uVar5 - 4)) =
         *(undefined4 *)((int)local_84.viewangles + (uVar5 - 4));
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x34);
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
  vVar2 = (from->client).vuser4[2];
  ppVar4->PM_PlaySound = PM_CL_PlaySound;
  ppVar4->PM_TraceTexture = PM_CL_TraceTexture;
  ppVar4->vuser4[2] = vVar2;
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
  (to->playerstate).origin[0] = ppVar4->origin[0];
  (to->playerstate).origin[1] = ppVar4->origin[1];
  (to->playerstate).origin[2] = ppVar4->origin[2];
  (to->playerstate).basevelocity[0] = ppVar4->basevelocity[0];
  (to->playerstate).basevelocity[1] = ppVar4->basevelocity[1];
  (to->playerstate).basevelocity[2] = ppVar4->basevelocity[2];
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
  ClientDLL_PostRunCmd(from,to,&local_84,runfuncs,*pfElapsed,random_seed);
  *pfElapsed = (double)((float)local_84.msec / 1000.0 + (float)*pfElapsed);
  return;
}


// CL_Save  @ 00124910
/* WARNING: Type propagation algorithm not settling */

void CL_Save(char *name)

{
  char **ppcVar1;
  FileHandle_t file;
  DECALLIST *pDVar2;
  int iVar3;
  int iVar4;
  DECALLIST aDStack_14024 [4096];
  int local_24 [5];
  
                    /* Unresolved local var: DECALLIST[4096] decalList@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int decalCount@[???]
                       Unresolved local var: int temp@[???]
                       Unresolved local var: FILE * pFile@[???] */
  local_24[0] = DecalListCreate(aDStack_14024);
  file = FS_OpenPathID(name,"wb","GAMECONFIG");
  if (file != (FileHandle_t)0x0) {
    local_24[1] = 0x564c4156;
    FS_Write(local_24 + 1,4,1,file);
    local_24[1] = 0x71;
    FS_Write(local_24 + 1,4,1,file);
    FS_Write(local_24,4,1,file);
    if (0 < local_24[0]) {
      pDVar2 = aDStack_14024;
      iVar3 = 0;
      do {
        ppcVar1 = &pDVar2->name;
        pDVar2 = pDVar2 + 1;
        FS_Write(*ppcVar1,0x10,1,file);
        iVar4 = iVar3 + 1;
        FS_Write(&aDStack_14024[iVar3].entityIndex,2,1,file);
        FS_Write(&aDStack_14024[iVar3].depth,1,1,file);
        FS_Write(&aDStack_14024[iVar3].flags,1,1,file);
        FS_Write(aDStack_14024[iVar3].position,0xc,1,file);
        iVar3 = iVar4;
      } while (iVar4 < local_24[0]);
    }
    FS_Close(file);
  }
  return;
}


// CL_SendConnectPacket  @ 0019fa60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SendConnectPacket(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  netadr_t to;
  bool bVar3;
  _func_short_short *p_Var4;
  int iVar5;
  qboolean qVar6;
  char *pcVar7;
  uchar unIPServer [4];
  uint uVar8;
  uint length;
  uint uVar9;
  char *pcVar10;
  byte bVar11;
  double dVar12;
  char local_1540 [2048];
  char local_d40 [1023];
  undefined1 local_941;
  char local_940 [1024];
  char local_540;
  char acStack_53f [1023];
  char local_140 [259];
  undefined1 local_3d;
  netadr_t local_3c [2];
  
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
  bVar11 = 0;
  Q_memset(local_940,0,0x400);
  ContinueLoadingProgressBar("ClientConnect",1,0.0);
  if (fs_startup_timings.value != 0.0) {
    g_iCurrentTiming = 0;
    g_StartupTimings[0].name = "Startup";
    dVar12 = Sys_FloatTime();
    g_StartupTimings[0].time = (float)dVar12;
  }
  Q_strncpy(local_140,cls.servername,0x104);
  local_3d = 0;
  iVar5 = Q_stricmp(cls.servername,"local");
  if (iVar5 == 0) {
    snprintf(local_140,0x104,"%s","localhost");
  }
  qVar6 = NET_StringToAdr(local_140,local_3c);
  p_Var4 = BigShort;
  if (qVar6 == false) {
    Con_Printf("Unable to resolve %s\n",local_140);
    cls.connect_time = -99999.0;
    cls.connect_retry = 0;
    cls.state = ca_disconnected;
    Q_memset(&g_GameServerAddress,0,0x14);
    return;
  }
  if (local_3c[0].port == 0) {
    iVar5 = Q_atoi("27015");
    local_3c[0].port = (*p_Var4)((short)iVar5);
  }
  if (cls.authprotocol != '\x02') {
    if (cls.authprotocol == '\x03') {
      pcVar7 = va("%i",3);
      Info_SetValueForKey(local_940,"prot",pcVar7,0x400);
      pcVar7 = va("%i",0xffffffff);
      bVar3 = true;
      Info_SetValueForKey(local_940,"unique",pcVar7,0x400);
      Info_SetValueForKey(local_940,"raw","steam",0x400);
      goto LAB_0019fbda;
    }
    cls.authprotocol = '\x02';
  }
  pcVar7 = CL_GetCDKeyHash();
  Q_strlen(pcVar7);
  pcVar7 = CL_GetCDKeyHash();
  Q_strncpy(local_d40,pcVar7,0x3ff);
  local_941 = 0;
  pcVar7 = va("%i",(uint)cls.authprotocol);
  Info_SetValueForKey(local_940,"prot",pcVar7,0x400);
  bVar3 = false;
  Info_SetValueForKey(local_940,"raw",local_d40,0x400);
LAB_0019fbda:
  if (cls.authprotocol != '\x02') {
    pcVar7 = CL_GetCDKeyHash();
    Info_SetValueForKey(local_940,"cdkey",pcVar7,0x400);
  }
  pcVar7 = &local_540;
  Q_memset(pcVar7,0,0x400);
  if (bVar3) {
                    /* Unresolved local var: uint unIP@[???] */
    unIPServer = local_3c[0].ip;
    if (local_3c[0].type == NA_LOOPBACK) {
      unIPServer = net_local_adr.ip;
    }
    uVar8 = Steam_GSInitiateGameConnection
                      (pcVar7,0x400,
                       CONCAT44(cls.GameServerSteamID._4_4_,(undefined4)cls.GameServerSteamID),
                       (uint32)unIPServer,local_3c[0].port,cls.isVAC2Secure);
    cls.connect_time = realtime;
    snprintf(local_1540,0x800,"%c%c%c%cconnect %i %i \"%s\" \"%s\"\n",0xff,0xff,0xff,0xff,0x30,
             cls.challenge,local_940,0xe0ae50);
    iVar5 = Q_strlen(local_1540);
    length = uVar8 + iVar5;
    if (0x800 < length) {
      Con_Printf("CL_SendConnectPacket:  Potential buffer overrun (%i/%i>%i) copying steamkeybuffer into connection packet\n"
                 ,iVar5,uVar8,0x800);
      CL_Disconnect();
      qVar6 = Host_IsServerActive();
      if (qVar6 == false) {
        return;
      }
      Host_ShutdownServer(false);
      return;
    }
    pcVar10 = local_1540 + iVar5;
    if (7 < uVar8) {
      uVar9 = uVar8;
      if (((uint)pcVar10 & 1) != 0) {
        uVar9 = uVar8 - 1;
        pcVar7 = acStack_53f;
        *pcVar10 = local_540;
        pcVar10 = local_1540 + iVar5 + 1;
      }
      if (((uint)pcVar10 & 2) != 0) {
        uVar1 = *(undefined2 *)pcVar7;
        uVar9 = uVar9 - 2;
        pcVar7 = pcVar7 + 2;
        *(undefined2 *)pcVar10 = uVar1;
        pcVar10 = pcVar10 + 2;
      }
      if (((uint)pcVar10 & 4) != 0) {
        uVar2 = *(undefined4 *)pcVar7;
        uVar9 = uVar9 - 4;
        pcVar7 = pcVar7 + 4;
        *(undefined4 *)pcVar10 = uVar2;
        pcVar10 = pcVar10 + 4;
      }
      uVar8 = uVar9 & 3;
      for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + ((uint)bVar11 * -2 + 1) * 4;
        pcVar10 = pcVar10 + (uint)bVar11 * -8 + 4;
      }
    }
    iVar5 = 0;
    if ((uVar8 & 4) != 0) {
      iVar5 = 4;
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
    }
    if ((uVar8 & 2) != 0) {
      *(undefined2 *)(pcVar10 + iVar5) = *(undefined2 *)(pcVar7 + iVar5);
      iVar5 = iVar5 + 2;
    }
    if ((uVar8 & 1) != 0) {
      pcVar10[iVar5] = pcVar7[iVar5];
    }
  }
  else {
    cls.connect_time = realtime;
    snprintf(local_1540,0x800,"%c%c%c%cconnect %i %i \"%s\" \"%s\"\n",0xff,0xff,0xff,0xff,0x30,
             cls.challenge,local_940,0xe0ae50);
    length = Q_strlen(local_1540);
  }
  g_GameServerAddress.type = local_3c[0].type;
  g_GameServerAddress.ip[0] = local_3c[0].ip[0];
  g_GameServerAddress.ip[1] = local_3c[0].ip[1];
  g_GameServerAddress.ip[2] = local_3c[0].ip[2];
  g_GameServerAddress.ip[3] = local_3c[0].ip[3];
  g_GameServerAddress.ipx[0] = local_3c[0].ipx[0];
  g_GameServerAddress.ipx[1] = local_3c[0].ipx[1];
  g_GameServerAddress.ipx[2] = local_3c[0].ipx[2];
  g_GameServerAddress.ipx[3] = local_3c[0].ipx[3];
  g_GameServerAddress.ipx[4] = local_3c[0].ipx[4];
  g_GameServerAddress.ipx[5] = local_3c[0].ipx[5];
  g_GameServerAddress.ipx[6] = local_3c[0].ipx[6];
  g_GameServerAddress.ipx[7] = local_3c[0].ipx[7];
  g_GameServerAddress.ipx[8] = local_3c[0].ipx[8];
  g_GameServerAddress.ipx[9] = local_3c[0].ipx[9];
  g_GameServerAddress.port = local_3c[0].port;
  to.ip[0] = local_3c[0].ip[0];
  to.ip[1] = local_3c[0].ip[1];
  to.ip[2] = local_3c[0].ip[2];
  to.ip[3] = local_3c[0].ip[3];
  to.type = local_3c[0].type;
  to.ipx[0] = (char)(short)local_3c[0].ipx._0_4_;
  to.ipx[1] = (char)((ushort)(short)local_3c[0].ipx._0_4_ >> 8);
  to.ipx[2] = (char)SUB42(local_3c[0].ipx._0_4_,2);
  to.ipx[3] = (char)((ushort)SUB42(local_3c[0].ipx._0_4_,2) >> 8);
  to.ipx[4] = local_3c[0].ipx[4];
  to.ipx[5] = local_3c[0].ipx[5];
  to.ipx[6] = local_3c[0].ipx[6];
  to.ipx[7] = local_3c[0].ipx[7];
  to.ipx[8] = local_3c[0].ipx[8];
  to.ipx[9] = local_3c[0].ipx[9];
  to.port = local_3c[0].port;
  NET_SendPacket(NS_CLIENT,length,local_1540,to);
  return;
}


// CL_SendConsistencyInfo  @ 001acb40
void CL_SendConsistencyInfo(sizebuf_t *msg)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  qboolean qVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  char local_254 [259];
  undefined1 local_151;
  char local_150 [260];
  uint32 local_4c [4];
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  CRC32_t local_20 [4];
  
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
  iVar2 = COM_CheckParm("-steam");
  if (cl.need_force_consistency_response != false) {
    cl.need_force_consistency_response = false;
    MSG_WriteByte(msg,7);
    iVar1 = msg->cursize;
    MSG_WriteShort(msg,0);
    MSG_StartBitWriting(msg);
    if (0 < cl.num_consistency) {
      iVar6 = 0;
      do {
                    /* Unresolved local var: qboolean user_changed_diskfile@[???] */
        MSG_WriteBits(1,1);
        MSG_WriteBits(cl.consistency_list[iVar6].orig_index,0xc);
        if (cl.consistency_list[iVar6].issound == 0) {
          Q_strncpy(local_254,cl.consistency_list[iVar6].filename,0x103);
          local_151 = 0;
        }
        else {
          snprintf(local_254,0x104,"sound/%s",cl.consistency_list[iVar6].filename);
        }
        bVar7 = true;
        if (iVar2 != 0) {
          snprintf(local_150,0x104,"%s",local_254);
          COM_FixSlashes(local_150);
          iVar4 = FS_FileExists(local_150);
          bVar7 = iVar4 != 0;
        }
        pcVar3 = strstr(local_254,"models/");
        bVar8 = false;
        if ((pcVar3 != (char *)0x0) && (bVar7)) {
                    /* Unresolved local var: CRC32_t crcFile@[???] */
          CRC32_Init(local_20);
          CRC_File(local_20,local_254);
          local_20[0] = CRC32_Final(local_20[0]);
          qVar5 = Mod_ValidateCRC(local_254,local_20[0]);
          bVar8 = qVar5 == false;
        }
        iVar4 = cl.consistency_list[iVar6].check_type;
        if (iVar4 < 3) {
          if (0 < iVar4) {
LAB_001acc84:
            iVar4 = R_GetStudioBounds(local_254,&local_3c,&local_2c);
            if (iVar4 == 0) {
              Host_Error("Unable to find %s\n",local_254);
              return;
            }
            if (bVar8) {
              local_2c = 9999.9;
              local_28 = 0x461c3f9a;
              local_24 = 0x461c3f9a;
              local_3c = -9999.9;
              local_38 = 0xc61c3f9a;
              local_34 = 0xc61c3f9a;
            }
            goto LAB_001accf8;
          }
          if (iVar4 != 0) goto LAB_001acda1;
          MD5_Hash_File((uchar *)local_4c,local_254,0,0,(uint *)0x0);
          cl.consistency_list[iVar6].value = local_4c[0];
          if (bVar8) {
            MSG_WriteBits(0,0x20);
          }
          else {
            MSG_WriteBits(local_4c[0],0x20);
          }
        }
        else {
          if (iVar4 != 3) {
LAB_001acda1:
            Host_Error("Unknown consistency type %i\n",iVar4);
            return;
          }
          if (bVar7) goto LAB_001acc84;
          local_2c = -1.0;
          local_28 = 0xbf800000;
          local_24 = 0xbf800000;
          local_3c = -1.0;
          local_38 = 0xbf800000;
          local_34 = 0xbf800000;
LAB_001accf8:
          MSG_WriteBitData(&local_3c,0xc);
          MSG_WriteBitData(&local_2c,0xc);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < cl.num_consistency);
    }
    MSG_WriteBits(0,1);
    MSG_EndBitWriting(msg);
    iVar2 = (msg->cursize - iVar1) + -2;
    *(short *)(msg->data + iVar1) = (short)iVar2;
    COM_Munge(msg->data + iVar1 + 2,iVar2,cl.servercount);
  }
  return;
}


// CL_SendKeepaliveToServer  @ 001a3520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SendKeepaliveToServer(void)

{
  int iVar1;
  byte local_4c [32];
  sizebuf_t local_2c;
  
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar[32] szData@[???]
                       Unresolved local var: int iCount@[???] */
  if (cls.state != ca_disconnected) {
    iVar1 = 0x20;
    local_2c.buffername = "Client Keepalive";
    local_2c.maxsize = 0x20;
    local_2c.cursize = 0;
    local_2c.data = local_4c;
    local_2c.flags = 0;
    do {
      MSG_WriteByte(&local_2c,1);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    Netchan_Transmit(&cls.netchan,local_2c.cursize,local_2c.data);
  }
  return;
}


// CL_SendRcon  @ 0019c730
void __regparm3 CL_SendRcon(netadr_t *to,uint challenge)

{
  netadr_t a;
  netadr_t adr;
  netadr_t b;
  qboolean qVar1;
  char local_48c [1160];
  
                    /* Unresolved local var: char[1152] message@[???] */
  if (g_lastrconcommand[0] == '\0') {
    Con_Printf("Rcon:  Empty rcon string\n");
    return;
  }
  a.ip = net_from.ip;
  a.type = net_from.type;
  a.ipx._0_4_ = net_from.ipx._0_4_;
  a.ipx._4_4_ = net_from.ipx._4_4_;
  a._16_4_ = net_from._16_4_;
  b.ip = g_rconaddress.ip;
  b.type = g_rconaddress.type;
  b.ipx._0_4_ = g_rconaddress.ipx._0_4_;
  b.ipx._4_4_ = g_rconaddress.ipx._4_4_;
  b._16_4_ = g_rconaddress._16_4_;
  qVar1 = NET_CompareAdr(a,b);
  if (qVar1 != false) {
    snprintf(local_48c,0x480,"rcon %u \"%s\" %s",to,rcon_password.string,g_lastrconcommand);
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
    Netchan_OutOfBandPrint(NS_CLIENT,adr,"%s",local_48c);
    return;
  }
  Con_Printf("Rcon:  Challenge from spoofed/invalid IP address\n");
  return;
}


// CL_SendRcon  @ 0019d7c0
void CL_SendRcon(netadr_t *to,uint challenge)

{
  netadr_t b;
  qboolean qVar1;
  char local_48c [1156];
  
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
  if (qVar1 != false) {
    snprintf(local_48c,0x480,"rcon %u \"%s\" %s",challenge,rcon_password.string,g_lastrconcommand);
    Netchan_OutOfBandPrint(NS_CLIENT,*to,"%s",local_48c);
    return;
  }
  Con_Printf("Rcon:  Challenge from spoofed/invalid IP address\n");
  return;
}


// CL_SendResourceListBlock  @ 001a2860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SendResourceListBlock(void)

{
  resource_t *prVar1;
  int iVar2;
  resourcetype_t *prVar3;
  byte abStack_1003c [65536];
  sizebuf_t local_3c [2];
  
                    /* Unresolved local var: int nStartIndex@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int arg@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: uchar[65536] buf@[???] */
  ContinueLoadingProgressBar("ClientConnect",6,0.0);
  Q_memset(local_3c,0,0x14);
  local_3c[0].buffername = "Client to Server Resource Block";
  local_3c[0].data = abStack_1003c;
  local_3c[0].cursize = 0;
  local_3c[0].maxsize = 0x10000;
  if (cls.state < ca_connecting) {
    Con_Printf("custom resource list not valid -- not connected\n");
    return;
  }
  iVar2 = MSG_ReadLong();
  if ((cls.demoplayback == false) && (cl.servercount != iVar2)) {
    Con_Printf("CL_SendResourceListBlock_f from different level\n");
    return;
  }
  iVar2 = MSG_ReadLong();
  if ((iVar2 < 0) || (cl.num_resources < iVar2)) {
    Con_Printf("custom resource list request out of range\n");
  }
  else {
    MSG_WriteByte(local_3c,5);
    MSG_WriteShort(local_3c,cl.num_resources);
    if (iVar2 < cl.num_resources) {
      prVar3 = &cl.resourcelist[iVar2].type;
      do {
        while( true ) {
          MSG_WriteString(local_3c,cl.resourcelist[iVar2].szFileName);
          MSG_WriteByte(local_3c,*prVar3);
          MSG_WriteShort(local_3c,prVar3[1]);
          MSG_WriteLong(local_3c,prVar3[2]);
          MSG_WriteByte(local_3c,(uint)*(byte *)(prVar3 + 3));
          if ((*(byte *)(prVar3 + 3) & 4) == 0) break;
          prVar1 = cl.resourcelist + iVar2;
          iVar2 = iVar2 + 1;
          prVar3 = prVar3 + 0x22;
          SZ_Write(local_3c,prVar1->rgucMD5_hash,0x10);
          if (cl.num_resources <= iVar2) goto LAB_001a2a2d;
        }
        iVar2 = iVar2 + 1;
        prVar3 = prVar3 + 0x22;
      } while (iVar2 < cl.num_resources);
    }
LAB_001a2a2d:
    if (0 < local_3c[0].cursize) {
      Netchan_CreateFragments(false,&cls.netchan,local_3c);
      Netchan_FragSend(&cls.netchan);
      return;
    }
  }
  return;
}


// CL_Send_CvarValue  @ 00191f60
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
  if ((sVar3 < 0xff) && (pcVar4 = Cvar_FindVar(pcVar2), pcVar4 != (cvar_t *)0x0)) {
                    /* Unresolved local var: char * strFailureMessage@[???] */
    uVar1 = pcVar4->flags;
    pcVar2 = "CVAR is privileged";
    if (((uVar1 & 0x400) == 0) && (pcVar2 = "CVAR is server-only", (uVar1 & 4) == 0)) {
      if ((uVar1 & 0x20) == 0) {
        MSG_WriteString(&cls.netchan.message,pcVar4->string);
        return;
      }
      pcVar2 = "CVAR is protected";
    }
    MSG_WriteString(&cls.netchan.message,pcVar2);
    return;
  }
  MSG_WriteString(&cls.netchan.message,"Bad CVAR request");
  return;
}


// CL_Send_CvarValue2  @ 00192010
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
  if ((sVar3 < 0xff) && (pcVar4 = Cvar_FindVar(pcVar2), pcVar4 != (cvar_t *)0x0)) {
                    /* Unresolved local var: char * strFailureMessage@[???] */
    uVar1 = pcVar4->flags;
    pcVar2 = "CVAR is privileged";
    if (((uVar1 & 0x400) == 0) && (pcVar2 = "CVAR is server-only", (uVar1 & 4) == 0)) {
      if ((uVar1 & 0x20) == 0) {
        MSG_WriteString(&cls.netchan.message,pcVar4->string);
        return;
      }
      pcVar2 = "CVAR is protected";
    }
    MSG_WriteString(&cls.netchan.message,pcVar2);
    return;
  }
  MSG_WriteString(&cls.netchan.message,"Bad CVAR request");
  return;
}


// CL_ServiceChallenge  @ 0019d8f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ServiceChallenge(void)

{
  int iVar1;
  char *pcVar2;
  netadr_t *to;
  uint challenge;
  
                    /* Unresolved local var: char * type@[???]
                       Unresolved local var: char * value@[???]
                       Unresolved local var: uint val@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      iVar1 = Q_stricmp(pcVar2,"rcon");
      if (iVar1 == 0) {
        pcVar2 = Cmd_Argv(2);
        to = (netadr_t *)Q_atoi(pcVar2);
        CL_SendRcon(to,challenge);
        return;
      }
    }
  }
  return;
}


// CL_ServiceGet  @ 0019da60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ServiceGet(void)

{
  netadr_t a;
  int iVar1;
  netadr_t *to;
  cvar_t *pcVar2;
  char *pcVar3;
  char *value;
  char *value_00;
  char *format;
  
                    /* Unresolved local var: char * var@[???]
                       Unresolved local var: cvar_t * cv@[???] */
  if ((net_from.type != NA_IP) || (net_from.ip != (uchar  [4])((int)lightmaps + 0xa0fdf))) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    return;
  }
  to = (netadr_t *)Cmd_Argv(1);
  if (to == (netadr_t *)0x0) {
    return;
  }
  if ((char)to->type == NA_UNUSED) {
    return;
  }
  iVar1 = Q_stricmp("clientaddress",(char *)to);
  if (iVar1 == 0) {
    pcVar3 = cls.trueaddress;
  }
  else {
    iVar1 = Q_stricmp("serveraddress",(char *)to);
    if (iVar1 != 0) {
      iVar1 = Q_stricmp("userid",(char *)to);
      if (iVar1 == 0) {
        format = "%i";
        pcVar3 = (char *)cls.userid;
      }
      else {
        pcVar2 = Cvar_FindVar((char *)to);
        if (pcVar2 == (cvar_t *)0x0) {
          CL_CreateResponse(to,"unknown variable",value);
          return;
        }
        format = "%s";
        pcVar3 = pcVar2->string;
      }
      goto LAB_0019dafb;
    }
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
  format = "%s";
LAB_0019dafb:
  pcVar3 = va(format,pcVar3);
  CL_CreateResponse(to,pcVar3,value_00);
  return;
}


// CL_SetDemoInfo_f  @ 00197130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetDemoInfo_f(void)

{
  demoentry_t *pdVar1;
  demoentry_t *pdVar2;
  FileHandle_t file;
  int iVar3;
  char *pcVar4;
  qboolean qVar5;
  FileHandle_t file_00;
  uint size;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char *fmt;
  undefined1 local_728 [1024];
  char local_328 [260];
  char local_224 [260];
  char local_120 [255];
  undefined1 local_21;
  
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
  if (cmd_source != src_command) {
    return;
  }
  if ((cls.demorecording != false) || (cls.demoplayback != false)) {
    Con_Printf("Setdemoinfo only available when not running or recording a demo.\n");
    return;
  }
  iVar3 = Cmd_Argc();
  if (iVar3 < 3) {
    Con_Printf("Setdemoinfo <demoname> <seg#> <info ...>\n");
    Con_Printf("   title \"text\"\n");
    Con_Printf("   play tracknum\n");
    Con_Printf("   fade <in | out> <fast | slow>\n\n");
    Con_Printf("Use -option to disable, e.g., -title\n");
    return;
  }
  pcVar4 = Cmd_Argv(1);
  pcVar4 = Q_strstr(pcVar4,"..");
  if (pcVar4 != (char *)0x0) {
    Con_Printf("Relative pathnames are not allowed.\n");
    return;
  }
  pcVar4 = Cmd_Argv(2);
  iVar3 = Q_atoi(pcVar4);
  if (iVar3 < 2) {
    Con_Printf("Cannot Setdemoinfo the STARTUP segment.\n");
    return;
  }
  pcVar4 = Cmd_Argv(1);
  snprintf(local_328,0x100,"%s",pcVar4);
  COM_DefaultExtension(local_328,".dem");
  qVar5 = COM_HasFileExtension(local_328,"dem");
  if (qVar5 == false) {
    Con_Printf("Error: couldn\'t open file %s, demo files must have .dem extension.\n",local_328);
    return;
  }
  Con_Printf("Setting info for segment %i in demo %s.\n",iVar3,local_328);
  Q_strncpy(local_120,local_328,0xff);
  local_21 = 0;
  file_00 = FS_Open(local_120,"rb");
  if (file_00 == (FileHandle_t)0x0) {
    Con_Printf("Error: couldn\'t open demo file %s for Setdemoinfo.\n",local_328);
    return;
  }
  COM_StripExtension(local_328,local_224);
  COM_AddExtension(local_224,".dm2",0x104);
  qVar5 = COM_HasFileExtension(local_224,"dm2");
  if (qVar5 == false) {
    Con_Printf("Error: couldn\'t open temporary file %s.\n",local_224);
    FS_Close(file_00);
  }
  cls.demofile = FS_OpenPathID(local_224,"w+b","GAMECONFIG");
  if (cls.demofile == (FileHandle_t)0x0) {
    Con_Printf("Error: couldn\'t open %s.\n",local_328);
    FS_Close(file_00);
    return;
  }
  FS_Seek(file_00,0,FILESYSTEM_SEEK_TAIL);
  size = FS_Tell(file_00);
  FS_Seek(file_00,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  file = cls.demofile;
                    /* Unresolved local var: int copysize@[???]
                       Unresolved local var: char[1024] copybuf@[???] */
  uVar9 = size;
  if (0x400 < (int)size) {
    do {
      uVar9 = uVar9 - 0x400;
      FS_Read(local_728,0x400,1,file_00);
      FS_Write(local_728,0x400,1,file);
    } while (0x400 < (int)uVar9);
    size = (size - 0x400) - (size - 0x401 & 0xfffffc00);
  }
  FS_Read(local_728,size,1,file_00);
  FS_Write(local_728,size,1,file);
  FS_Flush(file_00);
  FS_Flush(file);
  FS_Seek(file_00,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  FS_Read(&demoheader,0x220,1,file_00);
  iVar6 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
  if (iVar6 == 0) {
    if ((demoheader.nNetProtocolVersion != 0x30) || (demoheader.nDemoProtocol != 5)) {
      Con_Printf("ERROR: demo protocol outdated\nDemo file protocols %iN:%iD\nServer protocol is at %iN:%iD\n"
                 ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
      FS_Close(cls.demofile);
      FS_Close(file_00);
      unlink(local_224);
      cls.demofile = (FileHandle_t)0x0;
      return;
    }
    FS_Seek(file_00,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
    FS_Read(&demodir,4,1,file_00);
    if (demodir.nEntries - 1U < 0x400) {
      demodir.p_rgEntries = Mem_Malloc(demodir.nEntries * 0x5c);
      FS_Read(demodir.p_rgEntries,demodir.nEntries * 0x5c,1,file_00);
      pdVar2 = demodir.p_rgEntries;
      iVar3 = iVar3 + -1;
      pdVar1 = demodir.p_rgEntries + iVar3;
      iVar6 = 3;
LAB_0019771e:
      do {
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  pcVar4 = Cmd_Argv(iVar6);
                  if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) goto LAB_00197792;
                  iVar8 = iVar6 + 1;
                  iVar7 = Q_stricmp(pcVar4,"-TITLE");
                  if (iVar7 != 0) break;
                  pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags & 0xfffffffe;
                  iVar6 = iVar8;
                }
                iVar7 = Q_stricmp(pcVar4,"-PLAY");
                if (iVar7 != 0) break;
                pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags & 0xfffffffb;
                iVar6 = iVar8;
              }
              iVar7 = Q_stricmp(pcVar4,"-FADE");
              if (iVar7 != 0) break;
              pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags & 0xffffff87;
              iVar6 = iVar8;
            }
            iVar7 = Q_stricmp(pcVar4,"TITLE");
            if (iVar7 != 0) break;
            pcVar4 = Cmd_Argv(iVar8);
            if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
              Con_Printf("Title flag requires a double-quoted value.\n");
              iVar6 = iVar6 + 2;
            }
            else {
              Q_strncpy(pdVar1->szDescription,pcVar4,0x3f);
              pdVar2[iVar3].szDescription[0x3f] = '\0';
              pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 1;
              iVar6 = iVar6 + 2;
            }
          }
          iVar7 = Q_stricmp(pcVar4,"PLAY");
          if (iVar7 != 0) break;
          pcVar4 = Cmd_Argv(iVar8);
          if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
            Con_Printf("Play flag requires a cd track #.\n");
            iVar6 = iVar6 + 2;
          }
          else {
            iVar8 = Q_atoi(pcVar4);
            pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 4;
            pdVar2[iVar3].nCDTrack = iVar8;
            iVar6 = iVar6 + 2;
          }
        }
        iVar7 = Q_stricmp(pcVar4,"FADE");
        if (iVar7 != 0) {
          Con_Printf("Setdemoinfo, unrecognized flag:  %s\n",pcVar4);
LAB_00197792:
          FS_Seek(cls.demofile,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
          FS_Write(&demodir,4,1,cls.demofile);
          if (0 < demodir.nEntries) {
            iVar3 = 0;
            do {
              iVar6 = iVar3 + 1;
              FS_Write(demodir.p_rgEntries + iVar3,0x5c,1,cls.demofile);
              iVar3 = iVar6;
            } while (iVar6 < demodir.nEntries);
          }
          FS_Close(cls.demofile);
          cls.demofile = (FileHandle_t)0x0;
          FS_Close(file_00);
          Con_Printf("Replacing old demo with edited version.\n");
          unlink(local_120);
          rename(local_224,local_120);
          Mem_Free(demodir.p_rgEntries);
          demodir.p_rgEntries = (demoentry_t *)0x0;
          demodir.nEntries = 0;
          return;
        }
        iVar7 = iVar6 + 2;
        pcVar4 = Cmd_Argv(iVar8);
        if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
          iVar8 = Q_stricmp(pcVar4,"IN");
          if (iVar8 == 0) {
            pcVar4 = Cmd_Argv(iVar7);
            if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
              iVar8 = Q_stricmp(pcVar4,"FAST");
              if (iVar8 == 0) {
                pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 0x10;
                iVar6 = iVar6 + 3;
                goto LAB_0019771e;
              }
              iVar8 = Q_stricmp(pcVar4,"SLOW");
              if (iVar8 == 0) {
                pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 8;
                iVar6 = iVar6 + 3;
                goto LAB_0019771e;
              }
            }
          }
          else {
            iVar8 = Q_stricmp(pcVar4,"OUT");
            if (iVar8 != 0) {
              Con_Printf("Fade flag requires a direction (in or out).\n");
              iVar6 = iVar7;
              goto LAB_0019771e;
            }
            pcVar4 = Cmd_Argv(iVar7);
            if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
              iVar8 = Q_stricmp(pcVar4,"FAST");
              if (iVar8 == 0) {
                pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 0x40;
                iVar6 = iVar6 + 3;
                goto LAB_0019771e;
              }
              iVar8 = Q_stricmp(pcVar4,"SLOW");
              if (iVar8 == 0) {
                pdVar2[iVar3].nFlags = pdVar2[iVar3].nFlags | 0x20;
                iVar6 = iVar6 + 3;
                goto LAB_0019771e;
              }
            }
          }
          Con_Printf("Fade flag requires a speed (fast or slow).\n");
          iVar6 = iVar6 + 3;
          goto LAB_0019771e;
        }
        Con_Printf("Fade flag requires a direction and speed (in fast, e.g.)\n");
        iVar6 = iVar7;
      } while( true );
    }
    fmt = "ERROR: demo had bogus # of directory entries:  %i\n";
    pcVar4 = (char *)demodir.nEntries;
  }
  else {
    pcVar4 = local_328;
    fmt = "%s is not a demo file\n";
  }
  Con_Printf(fmt,pcVar4);
  FS_Close(cls.demofile);
  FS_Close(file_00);
  unlink(local_224);
  cls.demofile = (FileHandle_t)0x0;
  return;
}


// CL_SetDemoViewInfo  @ 00195e20
void CL_SetDemoViewInfo(ref_params_t *rp,vec_t *view,int viewmodel)

{
  undefined4 uVar1;
  usercmd_s *puVar2;
  movevars_s *pmVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  do {
    uVar1 = *(undefined4 *)((int)rp->vieworg + uVar4 + 4);
    *(undefined4 *)((int)g_rp.rp.vieworg + uVar4) = *(undefined4 *)((int)rp->vieworg + uVar4);
    *(undefined4 *)((int)g_rp.rp.vieworg + uVar4 + 4) = uVar1;
    uVar4 = uVar4 + 8;
  } while (uVar4 < 0xe8);
  g_rp.rp.cmd = &g_rp.cmd;
  uVar4 = 0;
  g_rp.rp.movevars = &g_rp.movevars;
  puVar2 = rp->cmd;
  do {
    *(undefined4 *)((int)g_rp.cmd.viewangles + (uVar4 - 4)) =
         *(undefined4 *)((int)puVar2->viewangles + (uVar4 - 4));
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x34);
  pmVar3 = rp->movevars;
  uVar4 = 0;
  do {
    uVar5 = uVar4;
    uVar1 = *(undefined4 *)(pmVar3->skyName + (uVar5 - 0x40));
    *(undefined4 *)(g_rp.movevars.skyName + (uVar5 - 0x44)) =
         *(undefined4 *)(pmVar3->skyName + (uVar5 - 0x44));
    *(undefined4 *)(g_rp.movevars.skyName + (uVar5 - 0x40)) = uVar1;
    uVar4 = uVar5 + 8;
  } while (uVar5 + 8 < 0x80);
  *(undefined4 *)(g_rp.movevars.skyName + (uVar5 - 0x3c)) =
       *(undefined4 *)(pmVar3->skyName + (uVar5 - 0x3c));
  g_rp.view[0] = *view;
  g_rp.view[1] = view[1];
  g_rp.view[2] = view[2];
  g_rp.viewmodel = viewmodel;
  return;
}


// CL_SetDevOverView  @ 00195620
void CL_SetDevOverView(refdef_t_conflict *refdef)

{
  float fVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  qboolean qVar5;
  vec_t vVar6;
  
  fVar2 = gDevOverview.origin[0] - cl.cmd.sidemove * 0.0078125;
  fVar1 = gDevOverview.origin[1] - cl.cmd.forwardmove * 0.0078125;
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
  gDevOverview.origin[1] = fVar1;
  refdef->vieworg[0] = fVar2;
  qVar5 = gDevOverview.rotated;
  refdef->vieworg[1] = fVar1;
  vVar4 = gDevOverview.origin[2];
  fVar3 = dev_overview.value;
  vVar6 = 90.0;
  refdef->onlyClientDraws = false;
  refdef->viewangles[0] = 90.0;
  if (qVar5 == false) {
    vVar6 = 0.0;
  }
  refdef->vieworg[2] = 16000.0;
  refdef->viewangles[1] = vVar6;
  refdef->viewangles[2] = 0.0;
  if (fVar3 < 2.0) {
    Con_Printf(" Overview: Zoom %.2f, Map Origin (%.2f, %.2f, %.2f), Z Min %.2f, Z Max %.2f, Rotated %i\n"
               ,(double)gDevOverview.zoom,(double)fVar2,(double)fVar1,(double)vVar4,
               (double)gDevOverview.z_min,(double)gDevOverview.z_max,qVar5);
  }
  return;
}


// CL_SetIdealPitch  @ 001930b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetIdealPitch(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float local_a4;
  float local_a0 [4];
  pmtrace_t local_90;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float local_3c;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  
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
  if (cl.onground != -1) {
    sincosf((cl.simangles[1] * 3.1415927 + cl.simangles[1] * 3.1415927) / 360.0,local_a0,&local_a4);
    local_2c = local_a4 * 3.0 * 12.0 + cl.simorg[0];
    local_28 = local_a0[0] * 3.0 * 12.0 + cl.simorg[1];
    local_24 = cl.simorg[2] + cl.viewheight[2];
    local_14 = local_24 - 160.0;
    local_1c = local_2c;
    local_18 = local_28;
    PM_PlayerTrace(&local_90,&local_2c,&local_1c,2,-1);
    if ((local_90.allsolid == false) && (local_90.fraction != 1.0)) {
      fStack_4c = local_24 + (local_14 - local_24) * local_90.fraction;
      local_2c = local_a4 * 4.0 * 12.0 + cl.simorg[0];
      local_28 = local_a0[0] * 4.0 * 12.0 + cl.simorg[1];
      local_24 = cl.simorg[2] + cl.viewheight[2];
      local_14 = local_24 - 160.0;
      local_1c = local_2c;
      local_18 = local_28;
      PM_PlayerTrace(&local_90,&local_2c,&local_1c,2,-1);
      if ((local_90.allsolid == false) && (local_90.fraction != 1.0)) {
        fStack_48 = local_24 + (local_14 - local_24) * local_90.fraction;
        local_2c = local_a4 * 5.0 * 12.0 + cl.simorg[0];
        local_28 = local_a0[0] * 5.0 * 12.0 + cl.simorg[1];
        local_24 = cl.simorg[2] + cl.viewheight[2];
        local_14 = local_24 - 160.0;
        local_1c = local_2c;
        local_18 = local_28;
        PM_PlayerTrace(&local_90,&local_2c,&local_1c,2,-1);
        if ((local_90.allsolid == false) && (local_90.fraction != 1.0)) {
          fStack_44 = local_24 + (local_14 - local_24) * local_90.fraction;
          local_2c = local_a4 * 6.0 * 12.0 + cl.simorg[0];
          local_28 = local_a0[0] * 6.0 * 12.0 + cl.simorg[1];
          local_24 = cl.simorg[2] + cl.viewheight[2];
          local_14 = local_24 - 160.0;
          local_1c = local_2c;
          local_18 = local_28;
          PM_PlayerTrace(&local_90,&local_2c,&local_1c,2,-1);
          if ((local_90.allsolid == false) && (local_90.fraction != 1.0)) {
            local_40 = local_24 + (local_14 - local_24) * local_90.fraction;
            local_2c = local_a4 * 7.0 * 12.0 + cl.simorg[0];
            local_28 = local_a0[0] * 7.0 * 12.0 + cl.simorg[1];
            local_24 = cl.simorg[2] + cl.viewheight[2];
            local_14 = local_24 - 160.0;
            local_1c = local_2c;
            local_18 = local_28;
            PM_PlayerTrace(&local_90,&local_2c,&local_1c,2,-1);
            if ((local_90.allsolid == false) && (local_90.fraction != 1.0)) {
              local_3c = local_24 + (local_14 - local_24) * local_90.fraction;
              local_2c = local_a4 * 8.0 * 12.0 + cl.simorg[0];
              local_28 = local_a0[0] * 8.0 * 12.0 + cl.simorg[1];
              local_24 = cl.simorg[2] + cl.viewheight[2];
              local_14 = local_24 - 160.0;
              local_1c = local_2c;
              local_18 = local_28;
              PM_PlayerTrace(&local_90,&local_2c,&local_1c,2,-1);
              if ((local_90.allsolid == false) && (local_90.fraction != 1.0)) {
                iVar1 = (int)(fStack_48 - fStack_4c);
                if (((double)iVar1 <= -0.1) || (0.1 <= (double)iVar1)) {
                  uVar3 = 1;
                }
                else {
                  uVar3 = 0;
                  iVar1 = 0;
                }
                iVar2 = (int)(fStack_44 - fStack_48);
                if (((double)iVar2 <= -0.1) || (0.1 <= (double)iVar2)) {
                  if (iVar1 != 0) {
                    if (0.1 < (double)(iVar2 - iVar1)) {
                      return;
                    }
                    if ((double)(iVar2 - iVar1) < -0.1) {
                      return;
                    }
                  }
                  uVar3 = uVar3 + 1;
                  iVar1 = iVar2;
                }
                iVar2 = (int)(local_40 - fStack_44);
                if (((double)iVar2 <= -0.1) || (0.1 <= (double)iVar2)) {
                  if (iVar1 != 0) {
                    if (0.1 < (double)(iVar2 - iVar1)) {
                      return;
                    }
                    if ((double)(iVar2 - iVar1) < -0.1) {
                      return;
                    }
                  }
                  uVar3 = uVar3 + 1;
                  iVar1 = iVar2;
                }
                iVar2 = (int)(local_3c - local_40);
                if (((double)iVar2 <= -0.1) || (0.1 <= (double)iVar2)) {
                  if (iVar1 != 0) {
                    if (0.1 < (double)(iVar2 - iVar1)) {
                      return;
                    }
                    if ((double)(iVar2 - iVar1) < -0.1) {
                      return;
                    }
                  }
                  uVar3 = uVar3 + 1;
                  iVar1 = iVar2;
                }
                iVar2 = (int)((local_24 + (local_14 - local_24) * local_90.fraction) - local_3c);
                if (((double)iVar2 <= -0.1) || (0.1 <= (double)iVar2)) {
                  if (iVar1 != 0) {
                    if (0.1 < (double)(iVar2 - iVar1)) {
                      return;
                    }
                    if ((double)(iVar2 - iVar1) < -0.1) {
                      return;
                    }
                  }
                  uVar3 = uVar3 + 1;
                  iVar1 = iVar2;
                }
                if (iVar1 == 0) {
                  cl.idealpitch = 0.0;
                  return;
                }
                if (1 < uVar3) {
                  cl.idealpitch = (float)-iVar1 * cl_idealpitchscale.value;
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CL_SetLastUpdate  @ 00194360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetLastUpdate(void)

{
  g_lastupdate_sequence = cls.netchan.incoming_sequence;
  return;
}


// CL_SetPacketFlag  @ 0018c490
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


// CL_SetSolidEntities  @ 0018e930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SetSolidEntities(void)

{
  undefined4 uVar1;
  vec_t vVar2;
  int iVar3;
  playermove_t_conflict *ppVar4;
  model_t *pmVar5;
  physent_t_conflict *pe;
  uint uVar6;
  int iVar7;
  entity_state_t_conflict *state;
  int iVar8;
  int iVar9;
  float fVar10;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: packet_entities_t * pak@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: physent_t.conflict * pe@[???]
                       Unresolved local var: physent_t.conflict * ve@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: model_t.conflict * model@[???] */
  pmove = &g_clmove;
  Q_memset(g_clmove.physents,0,0xe0);
  Q_memset(pmove->visents,0,0xe0);
  ppVar4 = pmove;
  pmove->physents[0].model = cl.worldmodel;
  if (cl.worldmodel != (model_s *)0x0) {
    Q_strncpy(ppVar4->physents[0].name,(cl.worldmodel)->name,0x20);
    ppVar4 = pmove;
    pmove->physents[0].name[0x1f] = '\0';
  }
  vVar2 = vec3_origin[0];
  ppVar4->physents[0].info = 0;
  ppVar4->physents[0].blooddecal = 0;
  ppVar4->physents[0].origin[0] = vVar2;
  vVar2 = vec3_origin[1];
  ppVar4->numphysent = 1;
  ppVar4->physents[0].solid = 4;
  ppVar4->physents[0].movetype = 0;
  ppVar4->physents[0].origin[1] = vVar2;
  vVar2 = vec3_origin[2];
  ppVar4->numvisent = 1;
  ppVar4->physents[0].origin[2] = vVar2;
  ppVar4->physents[0].takedamage = 1;
  uVar6 = 0;
  do {
    uVar1 = *(undefined4 *)(ppVar4->physents[0].name + uVar6 + 4);
    *(undefined4 *)(ppVar4->visents[0].name + uVar6) =
         *(undefined4 *)(ppVar4->physents[0].name + uVar6);
    *(undefined4 *)(ppVar4->visents[0].name + uVar6 + 4) = uVar1;
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0xe0);
  ppVar4->nummoveent = 0;
  iVar3 = cl.parsecountmod;
  iVar7 = cl.frames[cl.parsecountmod].packet_entities.num_entities;
  if (0 < iVar7) {
    iVar9 = 0;
    iVar8 = 0;
    do {
      while( true ) {
        state = (entity_state_t_conflict *)
                ((int)(cl.frames[iVar3].packet_entities.entities)->origin + iVar9 + -0x10);
        if (((0 < state->number) && (state->number <= cl.maxclients)) || (state->modelindex == 0))
        goto LAB_0018ea80;
        pmVar5 = CL_GetModelByIndex(state->modelindex);
        if ((pmVar5 != (model_t *)0x0) &&
           ((state->owner == 0 || (state->owner + -1 != cl.playernum)))) break;
LAB_0018eb10:
        iVar7 = cl.frames[iVar3].packet_entities.num_entities;
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + 0x154;
        if (iVar7 <= iVar8) {
          return;
        }
      }
      if ((pmVar5->hulls[1].firstclipnode != 0) || (pmVar5->type == mod_studio)) {
        iVar7 = pmove->numvisent;
        pmove->numvisent = iVar7 + 1;
        CL_AddStateToEntlist((physent_t_conflict *)(pmove->visents + iVar7),state);
      }
      if ((state->solid == 1) || ((state->solid == 0 && (-2 < state->skin)))) goto LAB_0018eb10;
      if ((state->mins[2] == 0.0) && (state->maxs[2] == 1.0)) goto LAB_0018eb10;
      local_28 = state->maxs[0] - state->mins[0];
      local_24 = state->maxs[1] - state->mins[1];
      local_20 = state->maxs[2] - state->mins[2];
      fVar10 = Length(&local_28);
      ppVar4 = pmove;
      if ((fVar10 == 0.0) || ((pmVar5->hulls[1].firstclipnode == 0 && (pmVar5->type != mod_studio)))
         ) goto LAB_0018eb10;
      iVar7._0_2_ = state->skin;
      iVar7._2_2_ = state->solid;
      if (iVar7 == 0xfff0) {
        iVar7 = pmove->nummoveent;
        if (iVar7 < 0x40) {
          pmove->nummoveent = iVar7 + 1;
          pe = (physent_t_conflict *)(ppVar4->moveents + iVar7);
          goto LAB_0018ec57;
        }
        Con_DPrintf("CL_SetSolidEntities:  pmove->nummoveent >= MAX_MOVEENTS\n");
        iVar7 = cl.frames[iVar3].packet_entities.num_entities;
      }
      else {
        iVar7 = pmove->numphysent;
        if (iVar7 < 600) {
          pmove->numphysent = iVar7 + 1;
          pe = (physent_t_conflict *)(ppVar4->physents + iVar7);
LAB_0018ec57:
          CL_AddStateToEntlist(pe,state);
          goto LAB_0018eb10;
        }
        Con_DPrintf("CL_SetSolidEntities:  pmove->numphysent >= MAX_PHYSENTS\n");
        iVar7 = cl.frames[iVar3].packet_entities.num_entities;
      }
LAB_0018ea80:
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x154;
    } while (iVar8 < iVar7);
  }
  return;
}


// CL_SetSolidPlayers  @ 0018ee50
void CL_SetSolidPlayers(int playernum)

{
  int iVar1;
  int iVar2;
  predicted_player *ppVar3;
  int iVar4;
  int iVar5;
  physent_t *__s;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: predicted_player * pplayer@[???]
                       Unresolved local var: physent_t.conflict * pent@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: frame_t * frame@[???] */
  if (cl_solid_players.value != 0.0) {
    iVar4 = 0;
    iVar5 = cl.parsecountmod * 0x42b8 + 0xc7f6fc;
    ppVar3 = predicted_players;
    __s = pmove->physents + pmove->numphysent;
    iVar2 = 1;
    do {
      if (playernum == -1) {
        if ((cl.playernum == iVar4) || (ppVar3->active != false)) {
LAB_0018eee6:
          if (ppVar3->solid != 0) {
            Q_memset(__s,0,0xe0);
            __s->player = 1;
            __s->model = (model_s *)0x0;
            __s->origin[0] = ppVar3->origin[0];
            __s->origin[1] = ppVar3->origin[1];
            __s->origin[2] = ppVar3->origin[2];
            __s->mins[0] = player_mins[ppVar3->usehull][0];
            __s->mins[1] = player_mins[ppVar3->usehull][1];
            __s->mins[2] = player_mins[ppVar3->usehull][2];
            __s->maxs[0] = player_maxs[ppVar3->usehull][0];
            __s->maxs[1] = player_maxs[ppVar3->usehull][1];
            __s->maxs[2] = player_maxs[ppVar3->usehull][2];
            snprintf(__s->name,0x20,"player %i",iVar4);
            iVar1 = ppVar3->solid;
            __s->skin = 0;
            __s->solid = iVar1;
            __s->info = iVar2;
            __s->movetype = (int)ppVar3->movetype;
            __s->blooddecal = 0;
            __s->takedamage = 1;
            __s->angles[0] = ppVar3->angles[0];
            __s->angles[1] = ppVar3->angles[1];
            __s->angles[2] = ppVar3->angles[2];
            __s->iuser1 = *(int *)(iVar5 + 0x104);
            __s->iuser2 = *(int *)(iVar5 + 0x108);
            __s->iuser3 = *(int *)(iVar5 + 0x10c);
            __s->iuser4 = *(int *)(iVar5 + 0x110);
            __s->fuser1 = *(float *)(iVar5 + 0x114);
            __s->fuser2 = *(float *)(iVar5 + 0x118);
            __s->fuser3 = *(float *)(iVar5 + 0x11c);
            __s->fuser4 = *(float *)(iVar5 + 0x120);
            __s->vuser1[0] = *(vec_t *)(iVar5 + 0x124);
            __s->vuser1[1] = *(vec_t *)(iVar5 + 0x128);
            __s->vuser1[2] = *(vec_t *)(iVar5 + 300);
            __s->vuser2[0] = *(vec_t *)(iVar5 + 0x130);
            __s->vuser2[1] = *(vec_t *)(iVar5 + 0x134);
            __s->vuser2[2] = *(vec_t *)(iVar5 + 0x138);
            __s->vuser3[0] = *(vec_t *)(iVar5 + 0x13c);
            __s->vuser3[1] = *(vec_t *)(iVar5 + 0x140);
            __s->vuser3[2] = *(vec_t *)(iVar5 + 0x144);
            __s->vuser4[0] = *(vec_t *)(iVar5 + 0x148);
            __s->vuser4[1] = *(vec_t *)(iVar5 + 0x14c);
            __s->vuser4[2] = *(vec_t *)(iVar5 + 0x150);
            __s->blending[0] = *(byte *)(iVar5 + 0x6c);
            __s->blending[1] = *(byte *)(iVar5 + 0x6d);
            __s->controller[0] = *(byte *)(iVar5 + 0x68);
            __s->controller[1] = *(byte *)(iVar5 + 0x69);
            __s->controller[2] = *(byte *)(iVar5 + 0x6a);
            __s->controller[3] = *(byte *)(iVar5 + 0x6b);
            __s->frame = *(float *)(iVar5 + 0x30);
            __s->rendermode = *(int *)(iVar5 + 0x48);
            __s->sequence = *(int *)(iVar5 + 0x2c);
            __s->team = *(int *)(iVar5 + 0xa4);
            __s->classnumber = *(int *)(iVar5 + 0xa8);
            __s = __s + 1;
            pmove->numphysent = pmove->numphysent + 1;
          }
        }
      }
      else if ((ppVar3->active != false) && (playernum != iVar4)) goto LAB_0018eee6;
      ppVar3 = ppVar3 + 1;
      iVar5 = iVar5 + 0x154;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (ppVar3 != (predicted_player *)&gpSprite);
  }
  return;
}


// CL_SetUpPlayerPrediction  @ 0018ecd0
void CL_SetUpPlayerPrediction(qboolean dopred,qboolean bIncludeLocalClient)

{
  msprite_t *pmVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  predicted_player *ppVar8;
  cl_entity_t *ent;
  int iVar9;
  bool bVar10;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: entity_state_t.conflict * state@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: predicted_player * pplayer@[???]
                       Unresolved local var: cl_entity_t.conflict2 * ent@[???] */
  iVar7 = 0;
  pmove = &g_clmove;
  ppVar8 = predicted_players;
  iVar9 = cl.parsecountmod * 0x42b8 + 0xc7f6fc;
  do {
    bVar10 = *(int *)(iVar9 + 0xc) == cl.parsecount;
    ppVar8->active = false;
    iVar6 = cl.playernum;
    if ((bVar10) && (*(int *)(iVar9 + 0x28) != 0)) {
      if (((*(byte *)(iVar9 + 0x3c) & 0x80) == 0) || (bIncludeLocalClient != false)) {
        pmVar1 = *(msprite_t **)(iVar9 + 0x58);
        ppVar8->active = true;
        ppVar8->movetype = (int)pmVar1;
        ppVar8->solid = (int)*(short *)(iVar9 + 0x3a);
        ppVar8->usehull = *(int *)(iVar9 + 200);
        iVar5 = cl.parsecountmod;
        if (iVar7 != iVar6) goto LAB_0018ed69;
        vVar2 = cl.frames[cl.parsecountmod].playerstate[iVar7].origin[0];
        ppVar8->origin[2] = cl.frames[cl.parsecountmod].playerstate[iVar7].origin[2];
        vVar3 = cl.frames[iVar5].playerstate[iVar7].angles[0];
        ppVar8->origin[0] = vVar2;
        vVar2 = cl.frames[iVar5].playerstate[iVar7].origin[1];
        ppVar8->angles[0] = vVar3;
        vVar3 = cl.frames[iVar5].playerstate[iVar7].angles[1];
        vVar4 = cl.frames[iVar5].playerstate[iVar7].angles[2];
        ppVar8->origin[1] = vVar2;
        ppVar8->angles[1] = vVar3;
        ppVar8->angles[2] = vVar4;
      }
      else if (cl.playernum != iVar7) {
        pmVar1 = *(msprite_t **)(iVar9 + 0x58);
        ppVar8->active = true;
        ppVar8->movetype = (int)pmVar1;
        ppVar8->solid = (int)*(short *)(iVar9 + 0x3a);
        ppVar8->usehull = *(int *)(iVar9 + 200);
LAB_0018ed69:
        ent = cl_entities + iVar7 + 1;
        CL_ComputePlayerOrigin(ent);
        ppVar8->origin[0] = ent->origin[0];
        ppVar8->origin[1] = ent->origin[1];
        ppVar8->origin[2] = ent->origin[2];
        ppVar8->angles[0] = ent->angles[0];
        ppVar8->angles[1] = ent->angles[1];
        ppVar8->angles[2] = ent->angles[2];
      }
    }
    iVar7 = iVar7 + 1;
    ppVar8 = ppVar8 + 1;
    iVar9 = iVar9 + 0x154;
    if (ppVar8 == (predicted_player *)&gpSprite) {
      return;
    }
  } while( true );
}


// CL_Set_ServerExtraInfo  @ 00190270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Set_ServerExtraInfo(void)

{
  char *pszDir;
  int iVar1;
  char local_2c [36];
  
                    /* Unresolved local var: char[32] val@[???]
                       Unresolved local var: char * dir@[???]
                       Unresolved local var: int cheats_enabled@[???] */
  pszDir = MSG_ReadString();
  iVar1 = MSG_ReadByte();
  snprintf(local_2c,0x20,"%d",(uint)(iVar1 != 0));
  Cvar_DirectSet(&sv_cheats,local_2c);
  COM_AddDefaultDir(pszDir);
  return;
}


// CL_ShowTEBlood  @ 001a3c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_ShowTEBlood(void)

{
  if (violence_hblood.value != 0.0) {
    return true;
  }
  if (violence_ablood.value != 0.0) {
    return true;
  }
  return false;
}


// CL_ShutDownClientStatic  @ 0019f860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ShutDownClientStatic(void)

{
  entity_state_s *p;
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: packet_entities_t * pClientPack@[???] */
  iVar1 = CL_UPDATE_BACKUP;
  if (0 < CL_UPDATE_BACKUP) {
    iVar2 = 0;
    do {
      p = cl.frames[iVar2].packet_entities.entities;
      if (p != (entity_state_s *)0x0) {
        Mem_Free(p);
        iVar1 = CL_UPDATE_BACKUP;
      }
      iVar3 = iVar2 + 1;
      cl.frames[iVar2].packet_entities.entities = (entity_state_s *)0x0;
      iVar2 = iVar3;
    } while (iVar3 < iVar1);
  }
  Q_memset(cl.frames,0,iVar1 * 0x42b8);
  return;
}


// CL_ShutDownUsrMessages  @ 001ac220
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ShutDownUsrMessages(void)

{
  _UserMsg *p_Var1;
  UserMsg *p;
  
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


// CL_Shutdown  @ 001a2ac0
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


// CL_SignonReply  @ 001a1840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SignonReply(void)

{
  uint *puVar1;
  uint *puVar2;
  char *pcVar3;
  qboolean qVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  byte bVar11;
  uint local_10c [64];
  
                    /* Unresolved local var: char[256] mapname@[???]
                       Unresolved local var: int l@[???] */
  bVar11 = 0;
  Con_DPrintf("CL_SignonReply: %i\n",cls.signon);
  if (cls.signon == 1) {
    Cache_Report();
    MSG_WriteByte(&cls.netchan.message,3);
    MSG_WriteString(&cls.netchan.message,"sendents");
  }
  else if (cls.signon == 2) {
    SCR_EndLoadingPlaque();
    __isoc99_sscanf(0xdf7bf8,"maps/%s.bsp",local_10c);
    puVar2 = local_10c;
    do {
      puVar1 = puVar2;
      uVar6 = *puVar1 + 0xfefefeff & ~*puVar1;
      uVar7 = uVar6 & 0x80808080;
      puVar2 = puVar1 + 1;
    } while (uVar7 == 0);
    if ((uVar6 & 0x8080) == 0) {
      puVar2 = (uint *)((int)puVar1 + 6);
      uVar7 = uVar7 >> 0x10;
    }
    pcVar3 = (char *)((int)puVar2 + ((-3 - (uint)CARRY1((byte)uVar7,(byte)uVar7)) - (int)local_10c))
    ;
    bVar10 = pcVar3 == (char *)0x4;
    if (4 < (int)pcVar3) {
                    /* Unresolved local var: size_t __s1_len@[???]
                       Unresolved local var: size_t __s2_len@[???] */
      iVar5 = 5;
      pcVar8 = (char *)((int)local_10c + (int)(pcVar3 + -4));
      pcVar9 = ".bsp";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar10 = *pcVar8 == *pcVar9;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if (bVar10) {
        *(char *)((int)local_10c + (int)(pcVar3 + -4)) = '\0';
      }
    }
    FS_LogLevelLoadFinished((char *)local_10c);
    VGuiWrap2_LoadingFinished("level",(char *)local_10c);
    if ((g_bRedirectedToProxy != 0) && (cls.spectator == false)) {
      Con_Printf("Redirected to invalid server\n");
      CL_Disconnect();
      qVar4 = Host_IsServerActive();
      if (qVar4 != false) {
        Host_ShutdownServer(false);
      }
    }
    g_bRedirectedToProxy = 0;
    if (cls.demoplayback != false) {
      Sequence_OnLevelLoad((char *)local_10c);
    }
  }
  return;
}


// CL_Slist_f  @ 0019c070
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Slist_f(void)

{
  num_servers = 0;
  Q_memset(cached_servers,0,0x4480);
  CL_PingServers_f();
  return;
}


// CL_SpecPos_f  @ 001a2db0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SpecPos_f(void)

{
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: vec3_t origin@[???]
                       Unresolved local var: vec3_t angles@[???] */
  GetPos((vec3_t *)&local_24,(vec3_t *)&local_18);
  Con_Printf("spec_pos %.1f %.1f %.1f %.1f %.1f\n",(double)local_24,(double)local_20,
             (double)local_1c,(double)local_18,(double)local_14);
  return;
}


// CL_StartMovie_f  @ 0019c280
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_StartMovie_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  float fVar4;
  
                    /* Unresolved local var: char * pFilename@[???] */
  if (cmd_source == src_command) {
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
  }
  return;
}


// CL_StartResourceDownloading  @ 001ad780
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
  if (fs_startup_timings.value == 0.0) {
    CL_BatchResourceRequest();
    return;
  }
  AddStartupTiming("end   CL_StartResourceDownloading()");
  CL_BatchResourceRequest();
  return;
}


// CL_StopPlayback  @ 0019a850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_StopPlayback(void)

{
  float fVar1;
  int iVar2;
  
  if (cls.demoplayback != false) {
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
      cls.timedemo = false;
      iVar2 = (host_framecount - cls.td_startframe) + -1;
      fVar1 = 1.0;
      if ((float)realtime - cls.td_starttime != 0.0) {
        fVar1 = (float)realtime - cls.td_starttime;
      }
      Con_Printf("%i frames %5.3f seconds %5.3f fps\n",iVar2,(double)fVar1,
                 (double)((float)iVar2 / fVar1));
    }
    Cbuf_AddText("cd stop\n");
    return;
  }
  return;
}


// CL_Stop_f  @ 001997a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_Stop_f(void)

{
  float fVar1;
  demoentry_t *pdVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  char local_220 [259];
  undefined1 local_11d;
  char local_11c [260];
  float local_18;
  int32 local_14;
  undefined1 local_d [5];
  
                    /* Unresolved local var: byte c@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: float ft@[DW_OP_breg4(ESP): +24]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: int swlen@[???]
                       Unresolved local var: int curpos@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[260] szNewName@[???]
                       Unresolved local var: char[260] szOldName@[???] */
  if (cmd_source != src_command) {
    return;
  }
  if (cls.demorecording != false) {
    local_d[0] = 5;
    FS_Write(local_d,1,1,cls.demofile);
    fVar1 = (float)realtime;
    lVar6 = (longdouble)(*LittleFloat)(fVar1 - cls.demostarttime);
    local_18 = (float)lVar6;
    FS_Write(&local_18,4,1,cls.demofile);
    local_14 = (*LittleLong)(host_framecount - cls.demostartframe);
    FS_Write(&local_14,4,1,cls.demofile);
    uVar3 = FS_Tell(cls.demofile);
    pdVar2 = pCurrentEntry;
    pCurrentEntry->nFileLength = uVar3 - pCurrentEntry->nOffset;
    pdVar2->fTrackTime = fVar1 - cls.demostarttime;
    pdVar2->nFrames = cls.demoframecount;
    FS_Write(&demodir,4,1,cls.demofile);
    if (0 < demodir.nEntries) {
      iVar4 = 0;
      do {
        iVar5 = iVar4 + 1;
        FS_Write(demodir.p_rgEntries + iVar4,0x5c,1,cls.demofile);
        iVar4 = iVar5;
      } while (iVar5 < demodir.nEntries);
    }
    if (demodir.p_rgEntries != (demoentry_t *)0x0) {
      Mem_Free(demodir.p_rgEntries);
    }
    demodir.p_rgEntries = (demoentry_t *)0x0;
    demodir.nEntries = 0;
    demoheader.nDirectoryOffset = uVar3;
    FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
    FS_Write(&demoheader,0x220,1,cls.demofile);
    FS_Close(cls.demofile);
    cls.demofile = (FileHandle_t)0x0;
    cls.demorecording = false;
    cls.td_lastframe = host_framecount;
    if (cls.demoappending != false) {
      Con_Printf("Replacing old demo with appended version.\n");
      Q_strncpy(local_220,cls.demofilename,0x103);
      local_11d = 0;
      unlink(cls.demofilename);
      COM_StripExtension(cls.demofilename,local_11c);
      COM_DefaultExtension(local_11c,".dm2");
      rename(local_11c,local_220);
    }
    Con_Printf("Completed demo\n");
    Con_DPrintf("Recording time %.2f\nHost frames %i\n",(double)(fVar1 - cls.demostarttime),
                cls.td_lastframe - cls.td_startframe);
    return;
  }
  Con_Printf("Not recording a demo.\n");
  return;
}


// CL_StudioEstimateFrame  @ 0013f2e0
float CL_StudioEstimateFrame(mstudioseqdesc_t *pseqdesc)

{
  float fVar1;
  int iVar2;
  float fVar3;
  
                    /* Unresolved local var: double dfdt@[???]
                       Unresolved local var: double f@[???] */
  if (r_dointerp != 0) {
    fVar1 = (currententity->curstate).animtime;
    if (fVar1 <= (float)cl.time) {
      iVar2 = pseqdesc->numframes;
      fVar1 = ((float)cl.time - fVar1) * (currententity->curstate).framerate * pseqdesc->fps;
      goto joined_r0x0013f3d1;
    }
  }
  iVar2 = pseqdesc->numframes;
  fVar1 = 0.0;
joined_r0x0013f3d1:
  if (iVar2 < 2) {
    fVar3 = 0.0;
  }
  else {
                    /* Unresolved local var: float baseframe@[???] */
    fVar3 = (float)(iVar2 + -1) * (currententity->curstate).frame * 0.00390625;
  }
  fVar3 = fVar3 + fVar1;
  if ((pseqdesc->flags & 1) == 0) {
    if ((float)iVar2 - 1.001 <= fVar3) {
      fVar3 = (float)iVar2 - 1.001;
    }
    fVar1 = 0.0;
    if (0.0 <= fVar3) {
      return fVar3;
    }
  }
  else {
    if (1 < iVar2) {
      fVar3 = fVar3 - (float)((iVar2 + -1) * (int)(fVar3 / (float)(iVar2 + -1)));
    }
    if (0.0 <= fVar3) {
      return fVar3;
    }
    fVar1 = (float)(iVar2 + -1) + fVar3;
  }
  return fVar1;
}


// CL_StudioEstimateInterpolant  @ 0013ef70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float CL_StudioEstimateInterpolant(void)

{
  float fVar1;
  
                    /* Unresolved local var: float dadt@[DW_OP_reg11(ST0)] */
  fVar1 = 1.0;
  if (r_dointerp != 0) {
    fVar1 = (currententity->curstate).animtime;
    if (fVar1 < (currententity->latched).prevanimtime + 0.01) {
      fVar1 = 1.0;
    }
    else {
                    /* Unresolved local var: float dadt@[???] */
      fVar1 = ((float)cl.time - fVar1) / 0.1;
      if (2.0 < fVar1) {
        fVar1 = 2.0;
      }
    }
  }
  return fVar1;
}


// CL_SwapDemo_f  @ 00196b30
/* WARNING: Removing unreachable block (ram,0x00196ff0) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_SwapDemo_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  qboolean qVar5;
  FILE *src;
  uint uVar6;
  int iVar7;
  demoentry_t *pdVar8;
  demoentry_t *pdVar9;
  demoentry_t *pdVar10;
  int *piVar11;
  int *piVar12;
  demoentry_t *pdVar13;
  byte bVar14;
  undefined4 uVar15;
  char local_384 [260];
  char local_280 [260];
  char local_17c [255];
  undefined1 local_7d;
  int local_78;
  int aiStack_74 [25];
  
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
  bVar14 = 0;
  if (cmd_source != src_command) {
    return;
  }
  if ((cls.demorecording != false) || (cls.demoplayback != false)) {
    Con_Printf("Swapdemo only available when not running or recording a demo.\n");
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 != 4) {
    Con_Printf("Swapdemo <demoname> <seg#> <seg#>\nSwaps segments, segment 1 cannot be moved\n");
    return;
  }
  pcVar2 = Cmd_Argv(1);
  pcVar2 = Q_strstr(pcVar2,"..");
  if (pcVar2 != (char *)0x0) {
    Con_Printf("Relative pathnames are not allowed.\n");
    return;
  }
  pcVar2 = Cmd_Argv(2);
  iVar1 = Q_atoi(pcVar2);
  if (iVar1 < 2) {
    Con_Printf("Cannot swap the STARTUP segment.\n");
    return;
  }
  pcVar2 = local_384;
  pcVar3 = Cmd_Argv(3);
  iVar4 = Q_atoi(pcVar3);
  pcVar3 = Cmd_Argv(1);
  snprintf(pcVar2,0x100,"%s",pcVar3);
  COM_DefaultExtension(pcVar2,".dem");
  qVar5 = COM_HasFileExtension(pcVar2,"dem");
  if (qVar5 == false) {
    Con_Printf("Error: couldn\'t open %s, demo files must have .dem extension.\n",pcVar2);
    return;
  }
  pcVar3 = pcVar2;
  Con_Printf("Swapping segment %i for %i from demo %s.\n",iVar1,iVar4,pcVar2);
  uVar15 = 0xff;
  Q_strncpy(local_17c,pcVar2,0xff);
  local_7d = 0;
  src = FS_Open(local_17c,"rb");
  if (src == (FILE *)0x0) {
    Con_Printf("Error: couldn\'t open demo file %s for swapping.\n",pcVar2,uVar15,pcVar3);
    return;
  }
  COM_StripExtension(pcVar2,local_280);
  COM_AddExtension(local_280,".dm2",0x104);
  qVar5 = COM_HasFileExtension(local_280,"dm2");
  if (qVar5 == false) {
    Con_Printf("Error: couldn\'t open temporary file %s.\n",local_280);
    FS_Close(src);
    return;
  }
  cls.demofile = FS_OpenPathID(local_280,"w+b","GAMECONFIG");
  if (cls.demofile == (FileHandle_t)0x0) {
    Con_Printf("Error: couldn\'t open %s.\n",pcVar2);
    FS_Close(src);
    return;
  }
  FS_Seek(src,0,FILESYSTEM_SEEK_TAIL);
  uVar6 = FS_Tell(src);
  FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  CL_DemoCopyFileChunk(cls.demofile,src,uVar6);
  FS_Seek(src,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(cls.demofile,0,FILESYSTEM_SEEK_HEAD);
  FS_Read(&demoheader,0x220,1,src);
  iVar7 = Q_strncmp(demoheader.szFileStamp,"HLDEMO",6);
  if (iVar7 == 0) {
    if ((demoheader.nNetProtocolVersion != 0x30) || (demoheader.nDemoProtocol != 5)) {
      Con_Printf("ERROR: demo protocol outdated\nDemo file protocols %iN:%iD\nServer protocol is at %iN:%iD\n"
                 ,demoheader.nNetProtocolVersion,demoheader.nDemoProtocol,0x30,5);
      goto LAB_00196e73;
    }
    FS_Seek(src,demoheader.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
    FS_Read(&demodir,4,1,src);
    pcVar2 = (char *)demodir.nEntries;
    if (demodir.nEntries - 1U < 0x400) {
      if ((iVar1 + -1 < demodir.nEntries) && (iVar4 + -1 < demodir.nEntries)) {
        demodir.p_rgEntries = Mem_Malloc(demodir.nEntries * 0x5c);
        FS_Read(demodir.p_rgEntries,demodir.nEntries * 0x5c,1,src);
        pdVar9 = demodir.p_rgEntries + iVar1 + -1;
        piVar11 = &local_78;
        pdVar10 = pdVar9;
        piVar12 = piVar11;
        for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar12 = pdVar10->nEntryType;
          pdVar10 = (demoentry_t *)((int)pdVar10 + (uint)bVar14 * -8 + 4);
          piVar12 = piVar12 + (uint)bVar14 * -2 + 1;
        }
        pdVar8 = demodir.p_rgEntries + iVar4 + -1;
        uVar6 = 0x5c;
        pdVar10 = pdVar8;
        pdVar13 = pdVar9;
        if (((uint)pdVar9 & 4) != 0) {
          pdVar13 = (demoentry_t *)((int)pdVar9 + (uint)bVar14 * -8 + 4);
          pdVar10 = (demoentry_t *)((int)pdVar8 + (uint)bVar14 * -8 + 4);
          pdVar9->nEntryType = pdVar8->nEntryType;
          uVar6 = 0x58;
        }
        for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          pdVar13->nEntryType = pdVar10->nEntryType;
          pdVar10 = (demoentry_t *)((int)pdVar10 + (uint)bVar14 * -8 + 4);
          pdVar13 = (demoentry_t *)((int)pdVar13 + (uint)bVar14 * -8 + 4);
        }
        uVar6 = 0x5c;
        pdVar10 = pdVar8;
        if (((uint)pdVar8 & 4) != 0) {
          pdVar10 = (demoentry_t *)((int)pdVar8 + (uint)bVar14 * -8 + 4);
          piVar11 = aiStack_74 + (uint)bVar14 * -2;
          pdVar8->nEntryType = local_78;
          uVar6 = 0x58;
        }
        for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          pdVar10->nEntryType = *piVar11;
          piVar11 = piVar11 + (uint)bVar14 * -2 + 1;
          pdVar10 = (demoentry_t *)((int)pdVar10 + (uint)bVar14 * -8 + 4);
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
        unlink(local_17c);
        rename(local_280,local_17c);
        Mem_Free(demodir.p_rgEntries);
        demodir.nEntries = 0;
        demodir.p_rgEntries = (demoentry_t *)0x0;
        return;
      }
      pcVar3 = "ERROR: demo only has %d entries\n";
    }
    else {
      pcVar3 = "ERROR: demo had bogus # of directory entries:  %i\n";
    }
  }
  else {
    pcVar3 = "%s is not a demo file\n";
  }
  Con_Printf(pcVar3,pcVar2);
LAB_00196e73:
  FS_Close(cls.demofile);
  FS_Close(src);
  unlink(local_280);
  cls.demofile = (FileHandle_t)0x0;
  return;
}


// CL_SwitchToNextDemoSection  @ 001986b0
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
  Host_EndGame("End of demo.\n");
  return false;
}


// CL_TakeSnapshot_f  @ 0019c0a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TakeSnapshot_f(void)

{
  FileHandle_t file;
  int iVar1;
  char local_8c [64];
  char local_4c [64];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: char[64] base@[???]
                       Unresolved local var: char[64] filename@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  if ((cl.num_entities == 0) || (cl_entities->model == (model_s *)0x0)) {
    Q_strcpy(local_8c,"Snapshot");
  }
  else {
    COM_FileBase(cl_entities->model->name,local_8c);
  }
  iVar1 = 0;
  do {
    snprintf(local_4c,0x40,"%s%04d.bmp",local_8c,iVar1);
    file = FS_OpenPathID(local_4c,"r","GAMECONFIG");
    if (file == (FileHandle_t)0x0) {
      VID_TakeSnapshot(local_4c);
      return;
    }
    iVar1 = iVar1 + 1;
    FS_Close(file);
  } while (iVar1 != 1000);
  Con_Printf("Unable to take a screenshot.\n");
  return;
}


// CL_TempEntAlloc  @ 001aa820
TEMPENTITY * CL_TempEntAlloc(vec_t *org,model_t *model)

{
  cl_entity_t_conflict *dest;
  TEMPENTITY *pTVar1;
  TEMPENTITY *pTVar2;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  pTVar2 = gpTempEntFree;
  if (gpTempEntFree == (TEMPENTITY *)0x0) {
    Con_DPrintf("Overflow %d temporary ents!\n",500);
  }
  else if (model == (model_t *)0x0) {
    pTVar2 = (TEMPENTITY *)0x0;
    Con_DPrintf("efx.CL_TempEntAlloc: No model\n");
  }
  else {
    dest = &gpTempEntFree->entity;
    gpTempEntFree = gpTempEntFree->next;
    Q_memset(dest,0,3000);
    pTVar2->flags = 0;
    (pTVar2->entity).curstate.colormap = 0;
    pTVar2->die = (float)cl.time + 0.75;
    (pTVar2->entity).model = model;
    (pTVar2->entity).curstate.rendermode = 0;
    (pTVar2->entity).curstate.renderfx = 0;
    pTVar2->fadeSpeed = 0.5;
    pTVar2->hitSound = 0;
    pTVar2->clientIndex = -1;
    pTVar2->bounceFactor = 1.0;
    pTVar2->hitcallback = (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0;
    pTVar2->callback = (_func_void_tempent_s_ptr_float_float *)0x0;
    pTVar2->priority = 0;
    (pTVar2->entity).origin[0] = *org;
    (pTVar2->entity).origin[1] = org[1];
    (pTVar2->entity).origin[2] = org[2];
    pTVar1 = gpTempEntActive;
    gpTempEntActive = pTVar2;
    pTVar2->next = pTVar1;
  }
  return pTVar2;
}


// CL_TempEntAllocHigh  @ 001aaa30
TEMPENTITY * CL_TempEntAllocHigh(vec_t *org,model_t *model)

{
  tempent_s **pptVar1;
  TEMPENTITY *pTVar2;
  TEMPENTITY *pTVar3;
  
  pTVar2 = gpTempEntActive;
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: TEMPENTITY * pActive@[???] */
  pTVar3 = gpTempEntFree;
  if (model == (model_t *)0x0) {
    pTVar3 = (TEMPENTITY *)0x0;
    Con_DPrintf("temporary ent model invalid\n");
  }
  else if (gpTempEntFree == (TEMPENTITY *)0x0) {
    for (; pTVar2 != (TEMPENTITY *)0x0; pTVar2 = pTVar2->next) {
      if (pTVar2->priority == 0) goto LAB_001aaa6a;
    }
    Con_DPrintf("Couldn\'t alloc a high priority TENT!\n");
  }
  else {
    gpTempEntActive = gpTempEntFree;
    pptVar1 = &gpTempEntFree->next;
    gpTempEntFree = gpTempEntFree->next;
    *pptVar1 = pTVar2;
    pTVar2 = pTVar3;
LAB_001aaa6a:
    Q_memset(&pTVar2->entity,0,3000);
    (pTVar2->entity).curstate.colormap = 0;
    pTVar2->flags = 0;
    pTVar2->die = (float)cl.time + 0.75;
    (pTVar2->entity).curstate.rendermode = 0;
    (pTVar2->entity).model = model;
    (pTVar2->entity).curstate.renderfx = 0;
    pTVar2->fadeSpeed = 0.5;
    pTVar2->hitSound = 0;
    pTVar2->clientIndex = -1;
    pTVar2->bounceFactor = 1.0;
    pTVar2->hitcallback = (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0;
    pTVar2->callback = (_func_void_tempent_s_ptr_float_float *)0x0;
    pTVar2->priority = 1;
    (pTVar2->entity).origin[0] = *org;
    (pTVar2->entity).origin[1] = org[1];
    (pTVar2->entity).origin[2] = org[2];
    pTVar3 = pTVar2;
  }
  return pTVar3;
}


// CL_TempEntAllocNoModel  @ 001aa940
TEMPENTITY * CL_TempEntAllocNoModel(vec_t *org)

{
  cl_entity_t_conflict *dest;
  TEMPENTITY *pTVar1;
  TEMPENTITY *pTVar2;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  pTVar1 = gpTempEntFree;
  if (gpTempEntFree == (TEMPENTITY *)0x0) {
    Con_DPrintf("Overflow %d temporary ents!\n",500);
  }
  else {
    dest = &gpTempEntFree->entity;
    gpTempEntFree = gpTempEntFree->next;
    Q_memset(dest,0,3000);
    pTVar1->flags = 0;
    (pTVar1->entity).curstate.colormap = 0;
    pTVar1->die = (float)cl.time + 0.75;
    (pTVar1->entity).model = (model_s *)0x0;
    (pTVar1->entity).curstate.rendermode = 0;
    pTVar1->flags = 0x40000;
    (pTVar1->entity).curstate.renderfx = 0;
    pTVar1->fadeSpeed = 0.5;
    pTVar1->hitSound = 0;
    pTVar1->clientIndex = -1;
    pTVar1->bounceFactor = 1.0;
    pTVar1->hitcallback = (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0;
    pTVar1->callback = (_func_void_tempent_s_ptr_float_float *)0x0;
    pTVar1->priority = 0;
    (pTVar1->entity).origin[0] = *org;
    (pTVar1->entity).origin[1] = org[1];
    (pTVar1->entity).origin[2] = org[2];
    pTVar2 = gpTempEntActive;
    gpTempEntActive = pTVar1;
    pTVar1->next = pTVar2;
  }
  return pTVar1;
}


// CL_TempEntInit  @ 001aa720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TempEntInit(void)

{
  int iVar1;
  int iVar2;
  tempent_s **pptVar3;
  
                    /* Unresolved local var: int i@[???] */
  Q_memset(gTempEnts,0,0x176830);
  pptVar3 = &gTempEnts[0].next;
  iVar1 = 1;
  do {
    iVar2 = iVar1 + 1;
    *pptVar3 = gTempEnts + iVar1;
    pptVar3 = pptVar3 + 0x2ff;
    iVar1 = iVar2;
  } while (iVar2 != 500);
  gTempEnts[499].next = (tempent_s *)0x0;
  gpTempEntFree = gTempEnts;
  gpTempEntActive = (TEMPENTITY *)0x0;
  return;
}


// CL_TempEntPlaySound  @ 001a3850
void CL_TempEntPlaySound(TEMPENTITY *pTemp,float damp)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  uint uVar4;
  int32 iVar5;
  uint uVar6;
  int iVar7;
  int32 pitch;
  int32 iVar8;
  float local_48;
  sfx_t *local_3c [4];
  sfx_t *local_2c;
  sfx_t *local_28;
  
                    /* Unresolved local var: sfx_t *[6] rgsfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: int fShell@[???]
                       Unresolved local var: int zvel@[???] */
  Q_memset(local_3c,0,0x18);
  iVar7 = pTemp->hitSound;
  if (iVar7 == 8) {
    iVar8 = 2;
    local_3c[0] = cl_sfx_wood1;
    local_3c[1] = cl_sfx_wood2;
    local_3c[2] = cl_sfx_wood3;
  }
  else if (iVar7 < 9) {
    if (iVar7 == 2) {
      iVar8 = 2;
      local_3c[0] = cl_sfx_metal1;
      local_3c[1] = cl_sfx_metal2;
      local_3c[2] = cl_sfx_metal3;
    }
    else if (iVar7 == 4) {
      iVar8 = 5;
      local_3c[0] = cl_sfx_flesh1;
      local_3c[1] = cl_sfx_flesh2;
      local_3c[2] = cl_sfx_flesh3;
      local_3c[3] = cl_sfx_flesh4;
      local_2c = cl_sfx_flesh5;
      local_28 = cl_sfx_flesh6;
    }
    else {
      if (iVar7 != 1) {
        return;
      }
      iVar8 = 2;
      local_3c[0] = cl_sfx_glass1;
      local_3c[1] = cl_sfx_glass2;
      local_3c[2] = cl_sfx_glass3;
    }
  }
  else {
    if (iVar7 == 0x20) {
      local_3c[0] = cl_sfx_pl_shell1;
      fVar1 = 0.8;
      local_48 = 0.8;
      local_3c[1] = cl_sfx_pl_shell2;
      local_3c[2] = cl_sfx_pl_shell3;
LAB_001a38d9:
      uVar6 = (uint)(pTemp->entity).baseline.origin[2];
      uVar4 = (int)uVar6 >> 0x1f;
      iVar7 = (uVar6 ^ uVar4) - uVar4;
      if ((iVar7 < 200) && (iVar8 = RandomLong(0,3), iVar8 != 0)) {
        return;
      }
      iVar8 = 2;
      bVar3 = true;
      goto LAB_001a3a03;
    }
    if (iVar7 < 0x21) {
      if (iVar7 != 0x10) {
        return;
      }
      iVar8 = 4;
      local_3c[0] = cl_sfx_ric1;
      local_3c[1] = cl_sfx_ric2;
      local_3c[2] = cl_sfx_ric3;
      local_3c[3] = cl_sfx_ric4;
      local_2c = cl_sfx_ric5;
    }
    else {
      if (iVar7 != 0x40) {
        if (iVar7 != 0x80) {
          return;
        }
        fVar1 = 0.5;
        local_48 = 0.5;
        local_3c[0] = cl_sfx_sshell1;
        local_3c[1] = cl_sfx_sshell2;
        local_3c[2] = cl_sfx_sshell3;
        goto LAB_001a38d9;
      }
      local_3c[0] = cl_sfx_concrete1;
      iVar8 = 2;
      local_3c[1] = cl_sfx_concrete2;
      local_3c[2] = cl_sfx_concrete3;
    }
  }
  fVar1 = (pTemp->entity).baseline.origin[2];
  iVar5 = RandomLong(0,5);
  if (iVar5 != 0) {
    return;
  }
  uVar6 = (uint)fVar1;
  bVar3 = false;
  fVar1 = 0.8;
  uVar4 = (int)uVar6 >> 0x1f;
  local_48 = 0.8;
  iVar7 = (uVar6 ^ uVar4) - uVar4;
LAB_001a3a03:
  if (0.0 < damp) {
                    /* Unresolved local var: int pitch@[???] */
    if (bVar3) {
      fVar2 = (float)iVar7 / 350.0;
      if (fVar2 <= 1.0) {
        local_48 = fVar2 * fVar1;
      }
    }
    else {
      local_48 = (float)iVar7 / 450.0;
      if (1.0 < local_48) {
        local_48 = 1.0;
      }
      local_48 = local_48 * fVar1;
    }
    pitch = 100;
    iVar5 = RandomLong(0,3);
    if ((iVar5 == 0) && (!bVar3)) {
      pitch = RandomLong(0x5a,0x7c);
    }
    iVar8 = RandomLong(0,iVar8);
    S_StartDynamicSound(-1,0,local_3c[iVar8],(pTemp->entity).origin,local_48,1.0,0,pitch);
  }
  return;
}


// CL_TempEntPrepare  @ 001aa790
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


// CL_TempEntUpdate  @ 001aab60
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


// CL_TentModel  @ 001a3c50
model_t * CL_TentModel(char *pName)

{
  model_t *pModel;
  
                    /* Unresolved local var: model_t * pModel@[???] */
  pModel = Mod_ForName(pName,true,false);
  Mod_MarkClient(pModel);
  return pModel;
}


// CL_TimeDemo_f  @ 0019a470
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TimeDemo_f(void)

{
  int iVar1;
  
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
                    /* Unresolved local var: char[256] name@[???] */
    if (cmd_source == src_command) {
      iVar1 = Cmd_Argc();
      if ((iVar1 == 2) || (iVar1 = Cmd_Argc(), iVar1 == 3)) {
        CL_PlayDemo_f();
      }
      else {
        Con_Printf("playdemo <demoname> <replayspeed>: plays a demo\n");
        Con_Printf("replayspeed == 1.0 default\n");
      }
    }
    cls.td_starttime = (float)realtime;
    cls.td_startframe = host_framecount;
    cls.td_lastframe = -1;
    cls.timedemo = true;
    return;
  }
  Con_Printf("timedemo <demoname>: gets demo speeds\n");
  return;
}


// CL_TouchLight  @ 0018d450
void CL_TouchLight(dlight_t *dl)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[DW_OP_reg1(ECX)] */
  uVar1 = ((int)(dl + -0x4ee08) >> 3) * -0x33333333;
  if (uVar1 < 0x20) {
    r_dlightchanged = r_dlightchanged | 1 << ((byte)uVar1 & 0x1f);
  }
  return;
}


// CL_TransferMessageData  @ 001af970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_TransferMessageData(void)

{
                    /* Unresolved local var: int i@[???] */
  total_data[0] = total_data[0] + last_data[0];
  total_data[1] = total_data[1] + last_data[1];
  total_data[2] = total_data[2] + last_data[2];
  total_data[3] = total_data[3] + last_data[3];
  total_data[4] = total_data[4] + last_data[4];
  total_data[5] = total_data[5] + last_data[5];
  total_data[6] = total_data[6] + last_data[6];
  total_data[7] = total_data[7] + last_data[7];
  total_data[8] = total_data[8] + last_data[8];
  total_data[9] = total_data[9] + last_data[9];
  total_data[10] = total_data[10] + last_data[10];
  total_data[0xb] = total_data[0xb] + last_data[0xb];
  total_data[0xc] = total_data[0xc] + last_data[0xc];
  total_data[0xd] = total_data[0xd] + last_data[0xd];
  total_data[0xe] = total_data[0xe] + last_data[0xe];
  total_data[0xf] = total_data[0xf] + last_data[0xf];
  total_data[0x10] = total_data[0x10] + last_data[0x10];
  total_data[0x11] = total_data[0x11] + last_data[0x11];
  total_data[0x12] = total_data[0x12] + last_data[0x12];
  total_data[0x13] = total_data[0x13] + last_data[0x13];
  total_data[0x14] = total_data[0x14] + last_data[0x14];
  total_data[0x15] = total_data[0x15] + last_data[0x15];
  total_data[0x16] = total_data[0x16] + last_data[0x16];
  total_data[0x17] = total_data[0x17] + last_data[0x17];
  total_data[0x18] = total_data[0x18] + last_data[0x18];
  total_data[0x19] = total_data[0x19] + last_data[0x19];
  total_data[0x1a] = total_data[0x1a] + last_data[0x1a];
  total_data[0x1b] = total_data[0x1b] + last_data[0x1b];
  total_data[0x1c] = total_data[0x1c] + last_data[0x1c];
  total_data[0x1d] = total_data[0x1d] + last_data[0x1d];
  total_data[0x1e] = total_data[0x1e] + last_data[0x1e];
  total_data[0x1f] = total_data[0x1f] + last_data[0x1f];
  total_data[0x20] = total_data[0x20] + last_data[0x20];
  total_data[0x21] = total_data[0x21] + last_data[0x21];
  total_data[0x22] = total_data[0x22] + last_data[0x22];
  total_data[0x23] = total_data[0x23] + last_data[0x23];
  total_data[0x24] = total_data[0x24] + last_data[0x24];
  total_data[0x25] = total_data[0x25] + last_data[0x25];
  total_data[0x26] = total_data[0x26] + last_data[0x26];
  total_data[0x27] = total_data[0x27] + last_data[0x27];
  total_data[0x28] = total_data[0x28] + last_data[0x28];
  total_data[0x29] = total_data[0x29] + last_data[0x29];
  total_data[0x2a] = total_data[0x2a] + last_data[0x2a];
  total_data[0x2b] = total_data[0x2b] + last_data[0x2b];
  total_data[0x2c] = total_data[0x2c] + last_data[0x2c];
  total_data[0x2d] = total_data[0x2d] + last_data[0x2d];
  total_data[0x2e] = total_data[0x2e] + last_data[0x2e];
  total_data[0x2f] = total_data[0x2f] + last_data[0x2f];
  total_data[0x30] = total_data[0x30] + last_data[0x30];
  total_data[0x31] = total_data[0x31] + last_data[0x31];
  total_data[0x32] = total_data[0x32] + last_data[0x32];
  total_data[0x33] = total_data[0x33] + last_data[0x33];
  total_data[0x34] = total_data[0x34] + last_data[0x34];
  total_data[0x35] = total_data[0x35] + last_data[0x35];
  total_data[0x36] = total_data[0x36] + last_data[0x36];
  total_data[0x37] = total_data[0x37] + last_data[0x37];
  total_data[0x38] = total_data[0x38] + last_data[0x38];
  total_data[0x39] = total_data[0x39] + last_data[0x39];
  total_data[0x3a] = total_data[0x3a] + last_data[0x3a];
  total_data[0x3b] = total_data[0x3b] + last_data[0x3b];
  total_data[0x3c] = total_data[0x3c] + last_data[0x3c];
  total_data[0x3d] = total_data[0x3d] + last_data[0x3d];
  total_data[0x3e] = total_data[0x3e] + last_data[0x3e];
  total_data[0x3f] = total_data[0x3f] + last_data[0x3f];
  return;
}


// CL_UpdatePositions  @ 00194d70
void CL_UpdatePositions(cl_entity_t *ent)

{
  vec_t vVar1;
  uint uVar2;
  
                    /* Unresolved local var: position_history_t * ph@[DW_OP_reg2(EDX)] */
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


// CL_UpdateSoundFade  @ 0019cbe0
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
    if ((cls.soundfade.soundFadeOutTime == 0) || ((float)cls.soundfade.soundFadeOutTime <= fVar1)) {
      if (fVar1 < (float)(cls.soundfade.soundFadeHoldTime + cls.soundfade.soundFadeOutTime)) {
        cls.soundfade.nClientSoundFadePercent = cls.soundfade.nStartPercent;
        return;
      }
      fVar1 = 1.0 - (fVar1 - (float)(cls.soundfade.soundFadeHoldTime +
                                    cls.soundfade.soundFadeOutTime)) /
                    (float)cls.soundfade.soundFadeOutTime;
    }
    else {
      fVar1 = fVar1 / (float)cls.soundfade.soundFadeOutTime;
    }
    cls.soundfade.nClientSoundFadePercent = (int)(fVar1 * (float)cls.soundfade.nStartPercent);
  }
  return;
}


// CL_UpdateUserinfo  @ 001ac250
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_UpdateUserinfo(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *dest;
  uint64 uVar5;
  
                    /* Unresolved local var: int slot@[???]
                       Unresolved local var: player_info_t * player@[???] */
  iVar2 = MSG_ReadByte();
  if (0x1f < iVar2) {
    Host_EndGame("CL_ParseServerMessage: svc_updateuserinfo > MAX_CLIENTS");
  }
  iVar3 = MSG_ReadLong();
  cl.players[iVar2].userid = iVar3;
  dest = cl.players[iVar2].userinfo;
  pcVar4 = MSG_ReadString();
  Q_strncpy(dest,pcVar4,0xff);
  cl.players[iVar2].userinfo[0xff] = '\0';
  MSG_ReadBuf(0x10,cl.players[iVar2].hashedcdkey);
  pcVar4 = Info_ValueForKey(dest,"name");
  Q_strncpy(cl.players[iVar2].name,pcVar4,0x1f);
  cl.players[iVar2].name[0x1f] = '\0';
  pcVar4 = Info_ValueForKey(dest,"model");
  Q_strncpy(cl.players[iVar2].model,pcVar4,0x3f);
  cl.players[iVar2].model[0x3f] = '\0';
  pcVar4 = Info_ValueForKey(dest,"topcolor");
  iVar3 = Q_atoi(pcVar4);
  cl.players[iVar2].topcolor = iVar3;
  pcVar4 = Info_ValueForKey(dest,"bottomcolor");
  iVar3 = Q_atoi(pcVar4);
  cl.players[iVar2].bottomcolor = iVar3;
  pcVar4 = Info_ValueForKey(dest,"*hltv");
  iVar3 = Q_atoi(pcVar4);
  cl.players[iVar2].spectator = iVar3;
  pcVar4 = Info_ValueForKey(dest,"*sid");
  uVar5 = strtoll(pcVar4,(char **)0x0,10);
  cVar1 = cl.players[iVar2].userinfo[0];
  cl.players[iVar2].m_nSteamID = uVar5;
  if ((cVar1 == '\0') || (cl.players[iVar2].name[0] == '\0')) {
    COM_ClearCustomizationList((customization_t *)&cl.players[iVar2].customdata,true);
  }
  return;
}


// CL_ViewDemo_f  @ 0019a250
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_ViewDemo_f(void)

{
  netadr_t adr;
  int iVar1;
  char *src;
  char local_110 [268];
  
                    /* Unresolved local var: char[260] name@[???] */
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
        Q_strncpy(local_110,src,0xff);
        COM_DefaultExtension(local_110,".dem");
        Con_Printf("Playing demo from %s.\n",local_110);
        iVar1 = DemoPlayer_LoadGame(local_110);
        if (iVar1 == 0) {
          Con_Printf("Viewdemo: couldn\'t load demo %s.\n",local_110);
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
          cls.lastoutgoingcommand = -1;
          cls.nextcmdtime = (float)realtime;
          DispatchDirectUserMsg("InitHUD",0,(void *)0x0);
        }
      }
      else {
        Con_Printf("viewdemo <demoname>: shows a demo\n");
      }
    }
  }
  return;
}


// CL_VoiceIdle  @ 0011f600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_VoiceIdle(void)

{
  Voice_Idle((float)host_frametime);
  return;
}


// CL_WavePlayLen_f  @ 0019a520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_WavePlayLen_f(void)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  if (cmd_source == src_command) {
    iVar1 = Cmd_Argc();
    if (iVar1 != 2) {
      Con_Printf(
                "waveplaylen <wave file name>: returns approximate number of milliseconds a wave file will take to play.\n"
                );
      return;
    }
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
  return;
}


// CL_WriteClientDLLMessage  @ 001957c0
void CL_WriteClientDLLMessage(int size,uchar *buf)

{
  longdouble lVar1;
  int32 local_18;
  float local_14;
  undefined1 local_d [5];
  
                    /* Unresolved local var: int swlen@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: byte cmd@[???]
                       Unresolved local var: int frame@[???] */
  if (((cls.demorecording != false) && (cls.demofile != (FileHandle_t)0x0)) && (-1 < size)) {
                    /* Unresolved local var: int swlen@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: byte cmd@[???]
                       Unresolved local var: int frame@[???] */
    local_d[0] = 9;
    FS_Write(local_d,1,1,cls.demofile);
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_14 = (float)lVar1;
    FS_Write(&local_14,4,1,cls.demofile);
    local_18 = (*LittleLong)(host_framecount - cls.demostartframe);
    FS_Write(&local_18,4,1,cls.demofile);
    local_18 = (*LittleLong)(size);
    FS_Write(&local_18,4,1,cls.demofile);
    FS_Write(buf,size,1,cls.demofile);
  }
  return;
}


// CL_WriteDLLUpdate  @ 00198c40
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
    local_18 = cdata->viewangles[2];
    local_14 = cdata->iWeaponBits;
    local_10 = cdata->fov;
    FS_Write(&local_35,0x29,1,cls.demofile);
  }
  return;
}


// CL_WriteDemoMessage  @ 00199610
void CL_WriteDemoMessage(int start,sizebuf_t *msg)

{
  FileHandle_t file;
  int size;
  longdouble lVar1;
  int local_45;
  int local_41;
  int local_3d;
  int local_39;
  int local_35;
  int local_31;
  int local_2d;
  int32 local_29;
  undefined1 local_25;
  float local_24;
  int32 local_20;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: demo_command_t demcmd@[???] */
  if (((cls.demorecording != false) && (cls.demofile != (FileHandle_t)0x0)) &&
     (size = msg->cursize - start, -1 < size)) {
    cls.demoframecount = cls.demoframecount + 1;
    local_25 = 1;
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_24 = (float)lVar1;
    local_20 = (*LittleLong)(host_framecount - cls.demostartframe);
    FS_Write(&local_25,9,1,cls.demofile);
    FS_Write(&g_rp,0x1b4,1,cls.demofile);
    file = cls.demofile;
                    /* Unresolved local var: sequence_info_t si@[???] */
    local_45 = cls.netchan.incoming_sequence;
    local_41 = cls.netchan.incoming_acknowledged;
    local_3d = cls.netchan.incoming_reliable_acknowledged;
    local_39 = cls.netchan.incoming_reliable_sequence;
    local_35 = cls.netchan.outgoing_sequence;
    local_31 = cls.netchan.reliable_sequence;
    local_2d = cls.netchan.last_reliable_sequence;
    local_29 = (*LittleLong)(size);
    FS_Write(&local_45,0x20,1,file);
    FS_Write(msg->data + start,size,1,cls.demofile);
  }
  return;
}


// CL_WriteDemoStartup  @ 001994a0
void CL_WriteDemoStartup(int start,sizebuf_t *msg)

{
  FileHandle_t file;
  int size;
  longdouble lVar1;
  int local_45;
  int local_41;
  int local_3d;
  int local_39;
  int local_35;
  int local_31;
  int local_2d;
  int32 local_29;
  undefined1 local_25;
  float local_24;
  int32 local_20;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: demo_command_t demcmd@[???] */
  if ((cls.demoheader != (FileHandle_t)0x0) && (size = msg->cursize - start, 0 < size)) {
    local_25 = 0;
    lVar1 = (longdouble)(*LittleFloat)((float)realtime - cls.demostarttime);
    local_24 = (float)lVar1;
    local_20 = (*LittleLong)(host_framecount - cls.demostartframe);
    FS_Write(&local_25,9,1,cls.demoheader);
    FS_Write(&g_rp,0x1b4,1,cls.demoheader);
    file = cls.demoheader;
                    /* Unresolved local var: sequence_info_t si@[???] */
    local_45 = cls.netchan.incoming_sequence;
    local_41 = cls.netchan.incoming_acknowledged;
    local_3d = cls.netchan.incoming_reliable_acknowledged;
    local_39 = cls.netchan.incoming_reliable_sequence;
    local_35 = cls.netchan.outgoing_sequence;
    local_31 = cls.netchan.reliable_sequence;
    local_2d = cls.netchan.last_reliable_sequence;
    local_29 = (*LittleLong)(size);
    FS_Write(&local_45,0x20,1,file);
    FS_Write(msg->data + start,size,1,cls.demoheader);
  }
  return;
}


// CL_WriteErrorMessage  @ 001abbe0
void __regparm3 CL_WriteErrorMessage(int starting_count,int current_count,sizebuf_t *msg)

{
  FileHandle_t file;
  int local_124;
  int local_120 [4];
  char local_110 [268];
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char * buffer_file@[???] */
  local_124 = current_count;
  local_120[0] = starting_count;
  snprintf(local_110,0x104,"%s","buffer.dat");
  COM_FixSlashes(local_110);
  COM_CreatePath(local_110);
  file = FS_Open(local_110,"wb");
  if (file != (FileHandle_t)0x0) {
    FS_Write(local_120,4,1,file);
    FS_Write(&local_124,4,1,file);
    FS_Write(net_message.data,net_message.cursize,1,file);
    FS_Close(file);
    Con_Printf("Wrote erroneous message to %s\n","buffer.dat");
  }
  return;
}


// CL_WriteErrorMessage  @ 001afc30
void CL_WriteErrorMessage(int starting_count,int current_count,sizebuf_t *msg)

{
  sizebuf_t *psVar1;
  FileHandle_t file;
  char local_110 [264];
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char * buffer_file@[???] */
  psVar1 = msg;
  snprintf(local_110,0x104,"%s","buffer.dat");
  COM_FixSlashes(local_110);
  COM_CreatePath(local_110);
  file = FS_Open(local_110,"wb");
  if (file != (FileHandle_t)0x0) {
    FS_Write(&starting_count,4,1,file);
    FS_Write(&current_count,4,1,file);
    FS_Write(psVar1->data,psVar1->cursize,1,file);
    FS_Close(file);
    Con_Printf("Wrote erroneous message to %s\n","buffer.dat");
  }
  return;
}


// CL_WriteMessageHistory  @ 001afd20
void CL_WriteMessageHistory(int starting_count,int cmd)

{
  int iVar1;
  UserMsg *pUVar2;
  sizebuf_t *msg;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int thecmd@[???] */
  uVar3 = 0x1f;
  Con_Printf("Last %i messages parsed.\n",0x20);
  do {
    uVar4 = ~uVar3 + currentcmd & 0x1f;
    iVar1 = oldcmd[uVar4].command;
    Q_strcpy(CL_MsgInfo::sz,"???");
    pUVar2 = gClientUserMsgs;
    if (iVar1 < 0x3c) {
      Q_strncpy(CL_MsgInfo::sz,cl_parsefuncs[iVar1].pszname,0xff);
      CL_MsgInfo::sz[0xff] = '\0';
    }
    else {
      for (; pUVar2 != (UserMsg *)0x0; pUVar2 = pUVar2->next) {
        if (iVar1 == pUVar2->iMsg) {
          Q_strncpy(CL_MsgInfo::sz,pUVar2->szName,0xff);
          CL_MsgInfo::sz[0xff] = '\0';
          break;
        }
      }
    }
    pcVar5 = CL_MsgInfo::sz;
    Con_Printf("%i %04i %s\n",oldcmd[uVar4].frame_number,oldcmd[uVar4].starting_offset,
               CL_MsgInfo::sz);
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  Q_strcpy(CL_MsgInfo::sz,"???");
  pUVar2 = gClientUserMsgs;
  if (cmd < 0x3c) {
    Q_strncpy(CL_MsgInfo::sz,cl_parsefuncs[cmd].pszname,0xff);
    CL_MsgInfo::sz[0xff] = '\0';
  }
  else {
    for (; pUVar2 != (UserMsg *)0x0; pUVar2 = pUVar2->next) {
      if (cmd == pUVar2->iMsg) {
        Q_strncpy(CL_MsgInfo::sz,pUVar2->szName,0xff);
        CL_MsgInfo::sz[0xff] = '\0';
        break;
      }
    }
  }
  Con_Printf("BAD:  %3i:%s\n",msg_readcount + -1,CL_MsgInfo::sz,pcVar5);
  if (developer.value == 0.0) {
    return;
  }
  CL_WriteErrorMessage(starting_count,msg_readcount + -1,msg);
  return;
}


