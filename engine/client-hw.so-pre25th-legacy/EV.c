// EV_FindModelIndex  @ 00211020
int EV_FindModelIndex(char *pmodel)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (1 < cl.model_precache_count) {
    iVar3 = 1;
    iVar2 = cl.model_precache_count;
    do {
      if ((cl.model_precache[iVar3] != (model_s *)0x0) &&
         (iVar1 = Q_stricmp(pmodel,cl.model_precache[iVar3]->name), iVar2 = cl.model_precache_count,
         iVar1 == 0)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return 0;
}


// EV_GetPhysent  @ 00210f40
physent_s * EV_GetPhysent(int idx)

{
  physent_s *ppVar1;
  
  ppVar1 = (physent_s *)0x0;
  if ((-1 < idx) && (idx < pmove->numphysent)) {
    ppVar1 = pmove->physents + idx;
  }
  return ppVar1;
}


// EV_IndexFromTrace  @ 00210f10
int EV_IndexFromTrace(pmtrace_s *pTrace)

{
  int iVar1;
  
  iVar1 = 0;
  if (pTrace != (pmtrace_s *)0x0) {
    iVar1 = pmove->physents[pTrace->ent].info;
  }
  return iVar1;
}


// EV_IsLocal  @ 00210f80
int EV_IsLocal(int playernum)

{
  return (uint)(cl.playernum == playernum);
}


// EV_KillEvents  @ 00211070
void EV_KillEvents(int entnum,char *eventname)

{
  int iVar1;
  event_info_t *ei;
  event_info_t *peVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  ei = cl.events.ei;
  do {
    while (((ei->index == 0 || ((ei->args).entindex != entnum)) ||
           (iVar1 = Q_stricmp(eventname,cl.event_precache[ei->index].filename), iVar1 != 0))) {
      ei = ei + 1;
      if (ei == (event_info_t *)cl.downloadUrl) {
        return;
      }
    }
    peVar2 = ei + 1;
    CL_ResetEvent(ei);
    ei = peVar2;
  } while (peVar2 != (event_info_t *)cl.downloadUrl);
  return;
}


// EV_LocalPlayerBounds  @ 00210eb0
void EV_LocalPlayerBounds(int hull,float *mins,float *maxs)

{
  if (mins != (float *)0x0) {
    *mins = player_mins[hull][0];
    mins[1] = player_mins[hull][1];
    mins[2] = player_mins[hull][2];
  }
  if (maxs != (float *)0x0) {
    *maxs = player_maxs[hull][0];
    maxs[1] = player_maxs[hull][1];
    maxs[2] = player_maxs[hull][2];
  }
  return;
}


// EV_LocalPlayerDucking  @ 00210e80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EV_LocalPlayerDucking(void)

{
  return (uint)(cl.usehull == 1);
}


// EV_LocalPlayerViewheight  @ 00210e90
void EV_LocalPlayerViewheight(float *viewheight)

{
  *viewheight = cl.viewheight[0];
  viewheight[1] = cl.viewheight[1];
  viewheight[2] = cl.viewheight[2];
  return;
}


// EV_PlayReliableEvent  @ 001352d0
void EV_PlayReliableEvent
               (client_t *cl,int entindex,ushort eventindex,float delay,event_args_t *pargs)

{
  uint uVar1;
  byte local_4c0 [1024];
  uchar local_c0 [4];
  int local_bc;
  uchar local_78 [72];
  sizebuf_t local_30;
  
                    /* Unresolved local var: uchar[1024] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: event_args_t nullargs@[???] */
  if (cl->fakeclient == false) {
    Q_memset(&local_30,0,0x14);
    local_30.buffername = "Reliable Event";
    local_30.data = local_4c0;
    local_30.cursize = 0;
    local_30.maxsize = 0x400;
    Q_memset(local_78,0,0x48);
    uVar1 = 0;
    do {
      *(undefined4 *)(local_c0 + uVar1) = *(undefined4 *)((int)pargs->origin + (uVar1 - 8));
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x48);
    local_bc = entindex;
    MSG_WriteByte(&local_30,0x15);
    MSG_StartBitWriting(&local_30);
    MSG_WriteBits((uint)eventindex,10);
    DELTA_WriteDelta(local_78,local_c0,true,g_peventdelta,(_func_void *)0x0);
    if (delay == 0.0) {
      MSG_WriteBits(0,1);
    }
    else {
      MSG_WriteBits(1,1);
      MSG_WriteBits((int)(delay * 100.0),0x10);
    }
    MSG_EndBitWriting(&local_30);
    if ((cl->netchan).message.maxsize < (cl->netchan).message.cursize + local_30.cursize) {
      Netchan_CreateFragments(true,&cl->netchan,&local_30);
    }
    else {
      SZ_Write(&(cl->netchan).message,local_30.data,local_30.cursize);
    }
  }
  return;
}


// EV_PlaySound  @ 00211160
void EV_PlaySound(int ent,float *origin,int channel,char *sample,float volume,float attenuation,
                 int fFlags,int pitch)

{
  int iVar1;
  sfx_t *sfxin;
  sfx_t local_64;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???]
                       Unresolved local var: int i@[???] */
  if ((fFlags & 0x10U) == 0) {
    sfxin = CL_LookupSound(sample);
  }
  else {
    iVar1 = Q_atoi(sample + 1);
    sfxin = &local_64;
    snprintf(sfxin->name,0x40,"!%s",rgpszrawsentence[iVar1]);
  }
  if (channel == 6) {
    S_StartStaticSound(ent,6,sfxin,origin,volume,attenuation,fFlags,pitch);
  }
  else {
    S_StartDynamicSound(ent,channel,sfxin,origin,volume,attenuation,fFlags,pitch);
  }
  return;
}


// EV_Playback  @ 001354e0
void EV_Playback(int flags,edict_t *pInvoker,ushort eventindex,float delay,float *origin,
                float *angles,float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,
                int bparam2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  qboolean qVar4;
  int entindex;
  uint uVar5;
  uint uVar6;
  event_info_s *peVar7;
  int iVar8;
  int iVar9;
  client_t *client;
  int local_a0;
  event_args_t local_7c;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int slot@[???]
                       Unresolved local var: vec3_t event_origin@[???]
                       Unresolved local var: int multicast_flag@[???]
                       Unresolved local var: int leafnum@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???]
                       Unresolved local var: int bestslot@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: qboolean skiphost@[???]
                       Unresolved local var: int invoker@[???]
                       Unresolved local var: int j@[???] */
  uVar6 = (uint)eventindex;
  if ((flags & 0x40U) == 0) {
    Q_memset(&local_7c,0,0x48);
    iVar2 = VectorCompare(origin,vec3_origin);
    if (iVar2 == 0) {
      local_7c.origin[0] = *origin;
      local_7c.flags = local_7c.flags | 1;
      local_7c.origin[1] = origin[1];
      local_7c.origin[2] = origin[2];
    }
    iVar2 = VectorCompare(angles,vec3_origin);
    if (iVar2 == 0) {
      local_7c.angles[0] = *angles;
      local_7c.flags = local_7c.flags | 2;
      local_7c.angles[1] = angles[1];
      local_7c.angles[2] = angles[2];
    }
    local_7c.iparam1 = iparam1;
    local_7c.iparam2 = iparam2;
    local_7c.bparam1 = bparam1;
    local_7c.bparam2 = bparam2;
    local_7c.fparam1 = fparam1;
    local_7c.fparam2 = fparam2;
    if ((ushort)(eventindex - 1) < 0xff) {
      if (sv.event_precache[uVar6].pszScript == (char *)0x0) {
        Con_DPrintf("EV_Playback:  no event for index %i\n",uVar6);
      }
      else {
        if (pInvoker == (edict_t *)0x0) {
          local_2c = local_7c.origin[0];
          local_a0 = -1;
          local_28 = local_7c.origin[1];
          local_24 = local_7c.origin[2];
        }
        else {
          local_2c = (pInvoker->v).origin[0];
          local_28 = (pInvoker->v).origin[1];
          local_24 = (pInvoker->v).origin[2];
          local_a0 = NUM_FOR_EDICT(pInvoker);
          if (((0 < local_a0) && (local_a0 <= svs.maxclients)) &&
             (((pInvoker->v).flags & 0x4000) != 0)) {
            local_7c.ducking = 1;
          }
          if ((local_7c.flags & 1U) == 0) {
            local_7c.origin[0] = (pInvoker->v).origin[0];
            local_7c.origin[1] = (pInvoker->v).origin[1];
            local_7c.origin[2] = (pInvoker->v).origin[2];
          }
          if ((local_7c.flags & 2U) == 0) {
            local_7c.angles[0] = (pInvoker->v).angles[0];
            local_7c.angles[1] = (pInvoker->v).angles[1];
            local_7c.angles[2] = (pInvoker->v).angles[2];
          }
        }
        iVar2 = SV_PointLeafnum(&local_2c);
        if (0 < svs.maxclients) {
          iVar8 = 0;
          iVar9 = 0;
          iVar3 = svs.maxclients;
LAB_001356f0:
          client = (client_t *)(((svs.clients)->netchan).remote_address.ip + iVar9 + -0x24);
          if (((client->active == false) || (client->spawned == false)) ||
             ((client->connected == false ||
              ((client->fully_connected == false || (client->fakeclient != false))))))
          goto LAB_00135760;
          if ((pInvoker == (edict_t *)0x0) ||
             ((uVar5 = (pInvoker->v).groupinfo, uVar5 == 0 ||
              (uVar1 = (client->edict->v).groupinfo, uVar1 == 0)))) {
LAB_001357d0:
            if ((((((flags & 4U) != 0) || (pInvoker == (edict_t *)0x0)) ||
                 (qVar4 = SV_ValidClientMulticast(client,iVar2,4), iVar3 = svs.maxclients,
                 qVar4 != false)) &&
                (((iVar3 = svs.maxclients, client != host_client || ((flags & 1U) == 0)) ||
                 (client->lw == 0)))) &&
               (((flags & 0x10U) == 0 || ((edict_t *)client->edict == pInvoker)))) {
              entindex = 0;
              if ((flags & 2U) == 0) {
                if (((flags & 8U) != 0) && (local_a0 != -1)) {
                  do {
                    peVar7 = (client->events).ei + entindex;
                    if ((peVar7->index == uVar6) && (peVar7->entity_index == local_a0))
                    goto LAB_00135928;
                    entindex = entindex + 1;
                  } while (entindex != 0x40);
                  entindex = 0;
                }
                do {
                  peVar7 = (client->events).ei + entindex;
                  if (peVar7->index == 0) goto LAB_00135928;
                  entindex = entindex + 1;
                } while (entindex != 0x40);
              }
              else {
                if (pInvoker != (edict_t *)0x0) {
                  entindex = NUM_FOR_EDICT(pInvoker);
                }
                EV_PlayReliableEvent(client,entindex,eventindex,delay,&local_7c);
                iVar3 = svs.maxclients;
              }
            }
          }
          else if (g_groupop == 0) {
            if ((uVar1 & uVar5) != 0) goto LAB_001357d0;
          }
          else if ((g_groupop != 1) || ((uVar1 & uVar5) == 0)) goto LAB_001357d0;
          goto LAB_00135760;
        }
      }
    }
    else {
      Con_DPrintf("EV_Playback:  index out of range %i\n",uVar6);
    }
  }
  return;
LAB_00135928:
  peVar7->packet_index = -1;
  peVar7->index = eventindex;
  if (pInvoker == (edict_t *)0x0) {
    peVar7->entity_index = -1;
  }
  else {
    peVar7->entity_index = (short)local_a0;
  }
  uVar5 = 0;
  do {
    *(undefined4 *)((int)(peVar7->args).origin + (uVar5 - 8)) =
         *(undefined4 *)((int)local_7c.origin + (uVar5 - 8));
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x48);
  peVar7->fire_time = delay;
  iVar3 = svs.maxclients;
LAB_00135760:
  iVar8 = iVar8 + 1;
  iVar9 = iVar9 + 0x4ef8;
  if (iVar3 <= iVar8) {
    return;
  }
  goto LAB_001356f0;
}


// EV_PlaybackEvent  @ 002112e0
void EV_PlaybackEvent(int flags,edict_s *pInvoker,ushort eventindex,float delay,float *origin,
                     float *angles,float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,
                     int bparam2)

{
  event_args_t local_64;
  
                    /* Unresolved local var: event_args_t eargs@[???] */
  if ((flags & 0x20U) == 0) {
                    /* Unresolved local var: event_args_t eargs@[???] */
    Q_memset(&local_64,0,0x48);
    local_64.origin[0] = *origin;
    local_64.entindex = flags;
    local_64.origin[1] = origin[1];
    local_64.origin[2] = origin[2];
    local_64.angles[0] = *angles;
    local_64.angles[1] = angles[1];
    local_64.angles[2] = angles[2];
    local_64.fparam1 = fparam1;
    local_64.fparam2 = fparam2;
    local_64.iparam1 = iparam1;
    local_64.iparam2 = iparam2;
    local_64.bparam1 = bparam1;
    local_64.bparam2 = bparam2;
    CL_QueueEvent(flags,(uint)eventindex,delay,&local_64);
  }
  return;
}


// EV_PlayerTrace  @ 002110e0
void EV_PlayerTrace(float *start,float *end,int traceFlags,int ignore_pe,pmtrace_s *tr)

{
  uint uVar1;
  pmtrace_t local_5c;
  
  PM_PlayerTrace(&local_5c,start,end,traceFlags,ignore_pe);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)tr->endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_5c.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x44);
  return;
}


// EV_Precache  @ 00135120
ushort EV_Precache(int type,char *psz)

{
  char *pcVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  char local_120 [260];
  int local_1c [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pszRaw@[???] */
  if (psz == (char *)0x0) {
    Host_Error("EV_Precache: NULL pointer");
  }
  else if (*psz < '!') {
    Host_Error("EV_Precache: Bad string \'%s\'",psz);
  }
  else {
    iVar4 = 1;
    if (sv.state != ss_loading) {
      do {
        pcVar1 = sv.event_precache[iVar4].filename;
        if ((pcVar1 != (char *)0x0) && (iVar2 = Q_stricmp(pcVar1,psz), iVar2 == 0))
        goto LAB_00135178;
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x100);
      Host_Error("EV_Precache: \'%s\' Precache can only be done in spawn functions",psz);
    }
    iVar4 = 1;
    do {
      pcVar1 = sv.event_precache[iVar4].filename;
      if (pcVar1 == (char *)0x0) {
                    /* Unresolved local var: int size@[???] */
        if (type != 1) {
          Host_Error("EV_Precache:  only file type 1 supported currently\n");
          return 0;
        }
                    /* Unresolved local var: char[260] szpath@[???] */
        snprintf(local_120,0x104,"%s",psz);
        COM_FixSlashes(local_120);
        pbVar3 = COM_LoadFile(local_120,5,local_1c);
        if (pbVar3 != (byte *)0x0) {
          sv.event_precache[iVar4].pszScript = (char *)pbVar3;
          sv.event_precache[iVar4].filename = psz;
          sv.event_precache[iVar4].filesize = local_1c[0];
          sv.event_precache[iVar4].index = (ushort)iVar4;
          return (ushort)iVar4;
        }
        Host_Error("EV_Precache:  file %s missing from server\n",psz);
        return 0;
      }
      iVar2 = Q_stricmp(pcVar1,psz);
      if (iVar2 == 0) {
LAB_00135178:
        return (ushort)iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x100);
    Host_Error("EV_Precache: \'%s\' overflow",psz);
  }
  return 0;
}


// EV_PrecacheEvent  @ 00210fc0
ushort EV_PrecacheEvent(int type,char *psz)

{
  ushort uVar1;
  int iVar2;
  char *s1;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  uVar1 = 0;
  if (cl.event_precache[1].filename != (char *)0x0) {
    s1 = cl.event_precache[1].filename;
    iVar3 = 1;
    while( true ) {
      iVar2 = Q_stricmp(s1,psz);
      if (iVar2 == 0) break;
      s1 = cl.event_precache[iVar3 + 1].filename;
      iVar3 = iVar3 + 1;
      if (s1 == (char *)0x0) {
        return 0;
      }
    }
    uVar1 = (ushort)iVar3;
  }
  return uVar1;
}


// EV_SV_Playback  @ 001359e0
void EV_SV_Playback(int flags,int clientindex,ushort eventindex,float delay,float *origin,
                   float *angles,float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,
                   int bparam2)

{
                    /* Unresolved local var: edict_t.conflict * pEdict@[???] */
  if ((flags & 0x40U) != 0) {
    return;
  }
  if ((-1 < clientindex) && (clientindex < svs.maxclients)) {
    EV_Playback(flags,(edict_t *)svs.clients[clientindex].edict,eventindex,delay,origin,angles,
                fparam1,fparam2,iparam1,iparam2,bparam1,bparam2);
    return;
  }
  Host_Error("EV_SV_Playback:  Client index %i out of range\n");
  return;
}


// EV_SetTraceHull  @ 00210f70
void EV_SetTraceHull(int hull)

{
  pmove->usehull = hull;
  return;
}


// EV_SetUpPlayerPrediction  @ 00211150
void EV_SetUpPlayerPrediction(int dopred,int bIncludeLocalClient)

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
  
  iVar7 = 0;
  pmove = &g_clmove;
  ppVar8 = predicted_players;
  iVar9 = cl.parsecountmod * 0x42b8 + 0xc7f6fc;
  do {
    bVar10 = *(int *)(iVar9 + 0xc) == cl.parsecount;
    ppVar8->active = false;
    iVar6 = cl.playernum;
    if ((bVar10) && (*(int *)(iVar9 + 0x28) != 0)) {
      if (((*(byte *)(iVar9 + 0x3c) & 0x80) == 0) || (bIncludeLocalClient != 0)) {
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


// EV_StopSound  @ 00211290
void EV_StopSound(int ent,int channel,char *sample)

{
  EV_PlaySound(ent,vec3_origin,channel,sample,0.0,0.0,0x20,100);
  return;
}


// EV_WeaponAnimation  @ 00210fa0
void EV_WeaponAnimation(int sequence,int body)

{
  cl.weaponstarttime = 0.0;
  cl.weaponsequence = sequence;
  cl.viewent.curstate.body = body;
  return;
}


