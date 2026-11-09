// EV_PlayReliableEvent  @ 0008dfd0
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


// EV_Playback  @ 0008e1e0
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
LAB_0008e3f0:
          client = (client_t *)(((svs.clients)->netchan).remote_address.ip + iVar9 + -0x24);
          if (((client->active == false) || (client->spawned == false)) ||
             ((client->connected == false ||
              ((client->fully_connected == false || (client->fakeclient != false))))))
          goto LAB_0008e460;
          if ((pInvoker == (edict_t *)0x0) ||
             ((uVar5 = (pInvoker->v).groupinfo, uVar5 == 0 ||
              (uVar1 = (client->edict->v).groupinfo, uVar1 == 0)))) {
LAB_0008e4d0:
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
                    goto LAB_0008e628;
                    entindex = entindex + 1;
                  } while (entindex != 0x40);
                  entindex = 0;
                }
                do {
                  peVar7 = (client->events).ei + entindex;
                  if (peVar7->index == 0) goto LAB_0008e628;
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
            if ((uVar1 & uVar5) != 0) goto LAB_0008e4d0;
          }
          else if ((g_groupop != 1) || ((uVar1 & uVar5) == 0)) goto LAB_0008e4d0;
          goto LAB_0008e460;
        }
      }
    }
    else {
      Con_DPrintf("EV_Playback:  index out of range %i\n",uVar6);
    }
  }
  return;
LAB_0008e628:
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
LAB_0008e460:
  iVar8 = iVar8 + 1;
  iVar9 = iVar9 + 0x4ef8;
  if (iVar3 <= iVar8) {
    return;
  }
  goto LAB_0008e3f0;
}


// EV_Precache  @ 0008de20
ushort EV_Precache(int type,char *psz)

{
  char *pcVar1;
  int iVar2;
  uchar *puVar3;
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
        goto LAB_0008de78;
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
        puVar3 = COM_LoadFile(local_120,5,local_1c);
        if (puVar3 != (uchar *)0x0) {
          sv.event_precache[iVar4].pszScript = (char *)puVar3;
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
LAB_0008de78:
        return (ushort)iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x100);
    Host_Error("EV_Precache: \'%s\' overflow",psz);
  }
  return 0;
}


// EV_SV_Playback  @ 0008e6e0
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


