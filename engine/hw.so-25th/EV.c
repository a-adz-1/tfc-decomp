// EV_FindModelIndex  @ 001c1400
int EV_FindModelIndex(char *pmodel)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = 1;
  iVar2 = cl.model_precache_count;
  if (1 < cl.model_precache_count) {
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


// EV_GetPhysent  @ 001c11e0
physent_s * EV_GetPhysent(int idx)

{
  if ((-1 < idx) && (idx < pmove->numphysent)) {
    return pmove->physents + idx;
  }
  return (physent_s *)0x0;
}


// EV_IndexFromTrace  @ 001c11b0
int EV_IndexFromTrace(pmtrace_s *pTrace)

{
  if (pTrace != (pmtrace_s *)0x0) {
    return pmove->physents[pTrace->ent].info;
  }
  return 0;
}


// EV_IsLocal  @ 001c1230
int EV_IsLocal(int playernum)

{
  return (uint)(cl.playernum == playernum);
}


// EV_KillEvents  @ 001c1530
void EV_KillEvents(int entnum,char *eventname)

{
  int iVar1;
  event_info_t *ei;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  ei = cl.events.ei;
  do {
    if (((ei->index != 0) && ((ei->args).entindex == entnum)) &&
       (iVar1 = Q_stricmp(eventname,cl.event_precache[ei->index].filename), iVar1 == 0)) {
      CL_ResetEvent(ei);
    }
    ei = ei + 1;
  } while (ei != (event_info_t *)cl.downloadUrl);
  return;
}


// EV_LocalPlayerBounds  @ 001c1130
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


// EV_LocalPlayerDucking  @ 001c10f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EV_LocalPlayerDucking(void)

{
  return (uint)(cl.usehull == 1);
}


// EV_LocalPlayerViewheight  @ 001c1100
void EV_LocalPlayerViewheight(float *viewheight)

{
  *viewheight = cl.viewheight[0];
  viewheight[1] = cl.viewheight[1];
  viewheight[2] = cl.viewheight[2];
  return;
}


// EV_PlayReliableEvent  @ 000cdac0
void __regparm3
EV_PlayReliableEvent(client_t *cl,int entindex,ushort eventindex,float delay,event_args_t *pargs)

{
  uint uVar1;
  int in_GS_OFFSET;
  sizebuf_t local_4c4;
  uchar local_4b0 [4];
  int local_4ac;
  uchar local_468 [72];
  byte local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: uchar[1024] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: event_args_t nullargs@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&local_4c4,0,0x14);
  local_4c4.buffername = "Reliable Event";
  local_4c4.data = local_420;
  local_4c4.cursize = 0;
  local_4c4.maxsize = 0x400;
  Q_memset(local_468,0,0x48);
  uVar1 = 0;
  do {
    *(undefined4 *)(local_4b0 + uVar1) = *(undefined4 *)((int)pargs->origin + (uVar1 - 8));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x48);
  local_4ac = entindex;
  MSG_WriteByte(&local_4c4,0x15);
  MSG_StartBitWriting(&local_4c4);
  MSG_WriteBits((uint)eventindex,10);
  DELTA_WriteDelta(local_468,local_4b0,true,g_peventdelta,(_func_void *)0x0);
  if (delay == 0.0) {
    MSG_WriteBits(0,1);
  }
  else {
    MSG_WriteBits(1,1);
    MSG_WriteBits((int)(delay * 100.0),0x10);
  }
  MSG_EndBitWriting(&local_4c4);
  if ((cl->netchan).message.maxsize < (cl->netchan).message.cursize + local_4c4.cursize) {
    Netchan_CreateFragments(true,&cl->netchan,&local_4c4);
  }
  else {
    SZ_Write(&(cl->netchan).message,local_4c4.data,local_4c4.cursize);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EV_PlayReliableEvent  @ 000d1020
void EV_PlayReliableEvent
               (client_t *cl,int entindex,ushort eventindex,float delay,event_args_t *pargs)

{
                    /* Unresolved local var: uchar[1024] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: event_args_t nullargs@[???] */
  if (cl->fakeclient != false) {
    return;
  }
  EV_PlayReliableEvent(cl,entindex,eventindex,delay,pargs);
  return;
}


// EV_PlaySound  @ 001c1270
void EV_PlaySound(int ent,float *origin,int channel,char *sample,float volume,float attenuation,
                 int fFlags,int pitch)

{
  int iVar1;
  sfx_t *sfxin;
  int in_GS_OFFSET;
  sfx_t local_68;
  int local_20;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???]
                       Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((fFlags & 0x10U) == 0) {
    sfxin = CL_LookupSound(sample);
  }
  else {
    iVar1 = Q_atoi(sample + 1);
    sfxin = &local_68;
    __snprintf_chk(sfxin,0x40,1,0x40,&DAT_00263ab4,rgpszrawsentence[iVar1]);
  }
  if (channel == 6) {
    S_StartStaticSound(ent,6,sfxin,origin,volume,attenuation,fFlags,pitch);
  }
  else {
    S_StartDynamicSound(ent,channel,sfxin,origin,volume,attenuation,fFlags,pitch);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EV_Playback  @ 000d1060
void EV_Playback(int flags,edict_t *pInvoker,ushort eventindex,float delay,float *origin,
                float *angles,float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,
                int bparam2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  qboolean qVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  event_state_t *peVar8;
  short sVar9;
  event_info_s *peVar10;
  int iVar11;
  int iVar12;
  client_t *client;
  int local_a4;
  event_state_t *local_84;
  vec_t local_78;
  vec_t local_74;
  vec_t local_70;
  event_args_t local_6c;
  
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
  uVar2 = (uint)eventindex;
  if ((flags & 0x40U) == 0) {
    Q_memset(&local_6c,0,0x48);
    iVar3 = VectorCompare(origin,vec3_origin);
    if (iVar3 == 0) {
      local_6c.origin[0] = *origin;
      local_6c.origin[1] = origin[1];
      local_6c.flags = local_6c.flags | 1;
      local_6c.origin[2] = origin[2];
    }
    iVar3 = VectorCompare(angles,vec3_origin);
    if (iVar3 == 0) {
      local_6c.angles[0] = *angles;
      local_6c.angles[1] = angles[1];
      local_6c.flags = local_6c.flags | 2;
      local_6c.angles[2] = angles[2];
    }
    local_6c.iparam1 = iparam1;
    local_6c.iparam2 = iparam2;
    local_6c.bparam1 = bparam1;
    local_6c.bparam2 = bparam2;
    local_6c.fparam1 = fparam1;
    local_6c.fparam2 = fparam2;
    if ((ushort)(eventindex - 1) < 0xff) {
      if (sv.event_precache[uVar2].pszScript == (char *)0x0) {
        Con_DPrintf("EV_Playback:  no event for index %i\n",uVar2);
      }
      else {
        if (pInvoker == (edict_t *)0x0) {
          local_78 = local_6c.origin[0];
          local_74 = local_6c.origin[1];
          local_70 = local_6c.origin[2];
          local_a4 = -1;
        }
        else {
          local_78 = (pInvoker->v).origin[0];
          local_74 = (pInvoker->v).origin[1];
          local_70 = (pInvoker->v).origin[2];
          local_a4 = NUM_FOR_EDICT(pInvoker);
          if (((0 < local_a4) && (local_a4 <= svs.maxclients)) &&
             (((pInvoker->v).flags & 0x4000) != 0)) {
            local_6c.ducking = 1;
          }
          if ((local_6c.flags & 1U) == 0) {
            local_6c.origin[0] = (pInvoker->v).origin[0];
            local_6c.origin[2] = (pInvoker->v).origin[2];
            local_6c.origin[1] = (pInvoker->v).origin[1];
          }
          if ((local_6c.flags & 2U) == 0) {
            local_6c.angles[0] = (pInvoker->v).angles[0];
            local_6c.angles[1] = (pInvoker->v).angles[1];
            local_6c.angles[2] = (pInvoker->v).angles[2];
          }
        }
        iVar3 = SV_PointLeafnum(&local_78);
        if (0 < svs.maxclients) {
          sVar9 = -1;
          if (pInvoker != (edict_t *)0x0) {
            sVar9 = (short)local_a4;
          }
          iVar12 = 0;
          iVar11 = 0;
          iVar5 = svs.maxclients;
          do {
            client = (client_t *)(((svs.clients)->netchan).remote_address.ip + iVar12 + -0x24);
            if (((client->active == false) || (client->spawned == false)) ||
               ((client->connected == false ||
                ((client->fully_connected == false || (client->fakeclient != false))))))
            goto LAB_000d13a0;
            if (pInvoker == (edict_t *)0x0) {
LAB_000d1470:
              iVar5 = svs.maxclients;
              if (((client != host_client) || (((flags & 1U) == 0 || (client->lw == 0)))) &&
                 (((flags & 0x10U) == 0 || (pInvoker == client->edict)))) {
                if ((flags & 2U) == 0) {
                  if ((flags & 8U) != 0) {
                    iVar6 = 0;
                    peVar8 = &client->events;
                    do {
                      if (((peVar8->ei[0].index == uVar2) && (local_a4 != -1)) &&
                         (local_a4 == peVar8->ei[0].entity_index)) {
                        peVar10 = (client->events).ei + iVar6;
                        goto LAB_000d1520;
                      }
                      iVar6 = iVar6 + 1;
                      peVar8 = (event_state_t *)(peVar8->ei + 1);
                    } while (iVar6 != 0x40);
                  }
                  local_84 = &client->events;
                  iVar6 = 0;
                  peVar8 = local_84;
LAB_000d150d:
                  if (peVar8->ei[0].index != 0) goto LAB_000d1500;
                  peVar10 = local_84->ei + iVar6;
LAB_000d1520:
                  peVar10->packet_index = -1;
                  peVar10->index = eventindex;
                  peVar10->entity_index = sVar9;
                  uVar7 = 0;
                  do {
                    *(undefined4 *)((int)(peVar10->args).origin + (uVar7 - 8)) =
                         *(undefined4 *)((int)local_6c.origin + (uVar7 - 8));
                    uVar7 = uVar7 + 4;
                  } while (uVar7 < 0x48);
                  peVar10->fire_time = delay;
                  iVar5 = svs.maxclients;
                  goto LAB_000d13a0;
                }
                if (pInvoker == (edict_t *)0x0) {
                  iVar6 = 0;
                }
                else {
                  iVar6 = NUM_FOR_EDICT(pInvoker);
                }
                    /* Unresolved local var: uchar[1024] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: event_args_t nullargs@[???] */
                iVar5 = svs.maxclients;
                if (client->fakeclient == false) {
                  EV_PlayReliableEvent(client,iVar6,eventindex,delay,&local_6c);
                  iVar5 = svs.maxclients;
                }
              }
            }
            else {
              uVar7 = (pInvoker->v).groupinfo;
              if ((uVar7 == 0) || (uVar1 = (client->edict->v).groupinfo, uVar1 == 0)) {
LAB_000d1360:
                if (((((byte)((uint)flags >> 2) ^ 1) & pInvoker != (edict_t *)0x0) == 0) ||
                   (qVar4 = SV_ValidClientMulticast(client,iVar3,4), iVar5 = svs.maxclients,
                   qVar4 != false)) goto LAB_000d1470;
              }
              else if (g_groupop == 0) {
                if ((uVar1 & uVar7) != 0) goto LAB_000d1360;
              }
              else if ((g_groupop != 1) || ((uVar1 & uVar7) == 0)) goto LAB_000d1360;
            }
LAB_000d13a0:
            iVar11 = iVar11 + 1;
            iVar12 = iVar12 + 0x6668;
          } while (iVar11 < iVar5);
        }
      }
    }
    else {
      Con_DPrintf("EV_Playback:  index out of range %i\n",uVar2);
    }
  }
  return;
LAB_000d1500:
  iVar6 = iVar6 + 1;
  peVar8 = (event_state_t *)(peVar8->ei + 1);
  if (iVar6 == 0x40) goto LAB_000d13a0;
  goto LAB_000d150d;
}


// EV_PlaybackEvent  @ 001c15a0
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
    local_64.origin[1] = origin[1];
    local_64.iparam1 = iparam1;
    local_64.origin[2] = origin[2];
    local_64.angles[0] = *angles;
    local_64.angles[1] = angles[1];
    local_64.iparam2 = iparam2;
    local_64.angles[2] = angles[2];
    local_64.bparam1 = bparam1;
    local_64.fparam1 = fparam1;
    local_64.fparam2 = fparam2;
    local_64.bparam2 = bparam2;
    local_64.entindex = flags;
    CL_QueueEvent(flags,(uint)eventindex,delay,&local_64);
  }
  return;
}


// EV_PlayerTrace  @ 001c14d0
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


// EV_Precache  @ 000d0e60
ushort EV_Precache(int type,char *psz)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int in_GS_OFFSET;
  int local_118;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pszRaw@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (psz == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("EV_Precache: NULL pointer");
  }
  if (*psz < '!') {
                    /* WARNING: Subroutine does not return */
    Host_Error("EV_Precache: Bad string \'%s\'",psz);
  }
  iVar5 = 1;
  if (sv.state != ss_loading) {
    do {
      pcVar1 = sv.event_precache[iVar5].filename;
      if (pcVar1 != (char *)0x0) {
        iVar3 = Q_stricmp(pcVar1,psz);
        if (iVar3 == 0) goto LAB_000d0ec8;
      }
      iVar5 = iVar5 + 1;
      if (iVar5 == 0x100) {
                    /* WARNING: Subroutine does not return */
        Host_Error("EV_Precache: \'%s\' Precache can only be done in spawn functions",psz);
      }
    } while( true );
  }
  iVar5 = 1;
  while (pcVar1 = sv.event_precache[iVar5].filename, pcVar1 != (char *)0x0) {
    iVar3 = Q_stricmp(pcVar1,psz);
    if (iVar3 == 0) goto LAB_000d0ec8;
    iVar5 = iVar5 + 1;
    if (iVar5 == 0x100) {
                    /* WARNING: Subroutine does not return */
      Host_Error("EV_Precache: \'%s\' overflow",psz);
    }
  }
                    /* Unresolved local var: int size@[???] */
  if (type != 1) {
                    /* WARNING: Subroutine does not return */
    Host_Error("EV_Precache:  only file type 1 supported currently\n");
  }
                    /* Unresolved local var: char[260] szpath@[???] */
  snprintf(local_114,0x104,"%s",psz);
  COM_FixSlashes(local_114);
  pbVar4 = COM_LoadFile(local_114,5,&local_118);
  if (pbVar4 == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("EV_Precache:  file %s missing from server\n",psz);
  }
  sv.event_precache[iVar5].pszScript = (char *)pbVar4;
  sv.event_precache[iVar5].filename = psz;
  sv.event_precache[iVar5].filesize = local_118;
  uVar2 = (ushort)iVar5;
  sv.event_precache[iVar5].index = uVar2;
LAB_000d0ecb:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_000d0ec8:
  uVar2 = (ushort)iVar5;
  goto LAB_000d0ecb;
}


// EV_PrecacheEvent  @ 001c1460
ushort EV_PrecacheEvent(int type,char *psz)

{
  char *s1;
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 1;
  s1 = cl.event_precache[1].filename;
  while( true ) {
    if (s1 == (char *)0x0) {
      return 0;
    }
    iVar2 = Q_stricmp(s1,psz);
    if (iVar2 == 0) break;
    s1 = cl.event_precache[iVar1 + 1].filename;
    iVar1 = iVar1 + 1;
  }
  return (ushort)iVar1;
}


// EV_SV_Playback  @ 000d1610
void EV_SV_Playback(int flags,int clientindex,ushort eventindex,float delay,float *origin,
                   float *angles,float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,
                   int bparam2)

{
  edict_t *e;
  uint uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  qboolean qVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  event_state_t *peVar9;
  byte bVar10;
  client_t *client;
  event_info_s *peVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int local_a4;
  event_state_t *local_80;
  vec_t local_78;
  vec_t local_74;
  vec_t local_70;
  event_args_t local_6c;
  
                    /* Unresolved local var: edict_t * pEdict@[???] */
  uVar12 = (uint)eventindex;
  if ((flags & 0x40U) == 0) {
    if ((clientindex < 0) || (svs.maxclients <= clientindex)) {
                    /* WARNING: Subroutine does not return */
      Host_Error("EV_SV_Playback:  Client index %i out of range\n",clientindex);
    }
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
    e = svs.clients[clientindex].edict;
    Q_memset(&local_6c,0,0x48);
    iVar4 = VectorCompare(origin,vec3_origin);
    if (iVar4 == 0) {
      local_6c.flags = local_6c.flags | 1;
      local_6c.origin[0] = *origin;
      local_6c.origin[1] = origin[1];
      local_6c.origin[2] = origin[2];
    }
    iVar4 = VectorCompare(angles,vec3_origin);
    if (iVar4 == 0) {
      local_6c.flags = local_6c.flags | 2;
      local_6c.angles[0] = *angles;
      local_6c.angles[2] = angles[2];
      local_6c.angles[1] = angles[1];
    }
    local_6c.iparam1 = iparam1;
    local_6c.iparam2 = iparam2;
    local_6c.bparam1 = bparam1;
    local_6c.bparam2 = bparam2;
    local_6c.fparam1 = fparam1;
    local_6c.fparam2 = fparam2;
    if ((ushort)(eventindex - 1) < 0xff) {
      if (sv.event_precache[uVar12].pszScript == (char *)0x0) {
        Con_DPrintf("EV_Playback:  no event for index %i\n",uVar12);
      }
      else {
        if (e == (edict_t *)0x0) {
          local_78 = local_6c.origin[0];
          local_74 = local_6c.origin[1];
          local_70 = local_6c.origin[2];
          local_a4 = -1;
        }
        else {
          local_78 = (e->v).origin[0];
          local_74 = (e->v).origin[1];
          local_70 = (e->v).origin[2];
          local_a4 = NUM_FOR_EDICT(e);
          if (((0 < local_a4) && (local_a4 <= svs.maxclients)) && (((e->v).flags & 0x4000) != 0)) {
            local_6c.ducking = 1;
          }
          if ((local_6c.flags & 1U) == 0) {
            local_6c.origin[0] = (e->v).origin[0];
            local_6c.origin[1] = (e->v).origin[1];
            local_6c.origin[2] = (e->v).origin[2];
          }
          if ((local_6c.flags & 2U) == 0) {
            local_6c.angles[0] = (e->v).angles[0];
            local_6c.angles[1] = (e->v).angles[1];
            local_6c.angles[2] = (e->v).angles[2];
          }
        }
        iVar4 = SV_PointLeafnum(&local_78);
        if (0 < svs.maxclients) {
          bVar10 = e != (edict_t *)0x0 & ((byte)((uint)flags >> 2) ^ 1);
          iVar13 = 0;
          iVar14 = 0;
          iVar6 = svs.maxclients;
          do {
            client = (client_t *)(((svs.clients)->netchan).remote_address.ip + iVar13 + -0x24);
            if (((client->active == false) || (client->spawned == false)) ||
               ((client->connected == false ||
                ((client->fully_connected == false || (client->fakeclient != false))))))
            goto LAB_000d1a70;
            if (e == (edict_t *)0x0) {
              bVar2 = 0;
LAB_000d1a41:
              iVar6 = svs.maxclients;
              if ((((client != host_client) || ((flags & 1U) == 0)) || (client->lw == 0)) &&
                 (((flags & 0x10U) == 0 || (e == client->edict)))) {
                if ((flags & 2U) == 0) {
                  if ((flags & 8U) != 0) {
                    iVar7 = 0;
                    peVar9 = &client->events;
                    do {
                      if (((peVar9->ei[0].index == uVar12) && (local_a4 != -1)) &&
                         (local_a4 == peVar9->ei[0].entity_index)) {
                        peVar11 = (client->events).ei + iVar7;
                        goto LAB_000d1b7c;
                      }
                      iVar7 = iVar7 + 1;
                      peVar9 = (event_state_t *)(peVar9->ei + 1);
                    } while (iVar7 != 0x40);
                  }
                  local_80 = &client->events;
                  iVar7 = 0;
                  peVar9 = local_80;
LAB_000d1b6d:
                  if (peVar9->ei[0].index != 0) goto LAB_000d1b60;
                  peVar11 = local_80->ei + iVar7;
LAB_000d1b7c:
                  peVar11->index = eventindex;
                  sVar3 = -1;
                  if (bVar2 != 0) {
                    sVar3 = (short)local_a4;
                  }
                  peVar11->packet_index = -1;
                  peVar11->entity_index = sVar3;
                  uVar8 = 0;
                  do {
                    *(undefined4 *)((int)(peVar11->args).origin + (uVar8 - 8)) =
                         *(undefined4 *)((int)local_6c.origin + (uVar8 - 8));
                    uVar8 = uVar8 + 4;
                  } while (uVar8 < 0x48);
                  peVar11->fire_time = delay;
                  iVar6 = svs.maxclients;
                  goto LAB_000d1a70;
                }
                if (bVar2 == 0) {
                  iVar7 = 0;
                }
                else {
                  iVar7 = NUM_FOR_EDICT(e);
                }
                    /* Unresolved local var: uchar[1024] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: event_args_t eargs@[???]
                       Unresolved local var: event_args_t nullargs@[???] */
                iVar6 = svs.maxclients;
                if (client->fakeclient == false) {
                  EV_PlayReliableEvent(client,iVar7,eventindex,delay,&local_6c);
                  iVar6 = svs.maxclients;
                }
              }
            }
            else {
              uVar8 = (e->v).groupinfo;
              if ((uVar8 == 0) || (uVar1 = (client->edict->v).groupinfo, uVar1 == 0)) {
LAB_000d1a10:
                if (bVar10 == 0) {
                  bVar2 = 1;
                }
                else {
                  qVar5 = SV_ValidClientMulticast(client,iVar4,4);
                  iVar6 = svs.maxclients;
                  bVar2 = bVar10;
                  if (qVar5 == false) goto LAB_000d1a70;
                }
                goto LAB_000d1a41;
              }
              if (g_groupop == 0) {
                if ((uVar1 & uVar8) != 0) goto LAB_000d1a10;
              }
              else if ((g_groupop != 1) || ((uVar1 & uVar8) == 0)) goto LAB_000d1a10;
            }
LAB_000d1a70:
            iVar14 = iVar14 + 1;
            iVar13 = iVar13 + 0x6668;
          } while (iVar14 < iVar6);
        }
      }
    }
    else {
      Con_DPrintf("EV_Playback:  index out of range %i\n",uVar12);
    }
  }
  return;
LAB_000d1b60:
  iVar7 = iVar7 + 1;
  peVar9 = (event_state_t *)(peVar9->ei + 1);
  if (iVar7 == 0x40) goto LAB_000d1a70;
  goto LAB_000d1b6d;
}


// EV_SetTraceHull  @ 001c1220
void EV_SetTraceHull(int hull)

{
  pmove->usehull = hull;
  return;
}


// EV_SetUpPlayerPrediction  @ 001c14c0
void EV_SetUpPlayerPrediction(int dopred,int bIncludeLocalClient)

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
  
  iVar6 = 0;
  ppVar7 = predicted_players;
  pmove = &g_clmove;
  iVar8 = cl.parsecountmod * 0x4318 + 0xc6aa3c;
  do {
    bVar9 = *(int *)(iVar8 + 0xc) == cl.parsecount;
    ppVar7->active = false;
    if ((bVar9) && (*(int *)(iVar8 + 0x28) != 0)) {
      if (((*(byte *)(iVar8 + 0x3c) & 0x80) == 0) || (bIncludeLocalClient != 0)) {
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


// EV_StopSound  @ 001c16d0
void EV_StopSound(int ent,int channel,char *sample)

{
  sfx_s *sfxin;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???]
                       Unresolved local var: int i@[???] */
  sfxin = CL_LookupSound(sample);
  if (channel != 6) {
    S_StartDynamicSound(ent,channel,sfxin,vec3_origin,0.0,0.0,0x20,100);
    return;
  }
  S_StartStaticSound(ent,6,sfxin,vec3_origin,0.0,0.0,0x20,100);
  return;
}


// EV_WeaponAnimation  @ 001c1250
void EV_WeaponAnimation(int sequence,int body)

{
  cl.weaponstarttime = 0.0;
  cl.weaponsequence = sequence;
  cl.viewent.curstate.body = body;
  return;
}


