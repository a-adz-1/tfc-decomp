// EV_PlayReliableEvent  @ 0006d640
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


// EV_PlayReliableEvent  @ 00070b60
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


// EV_Playback  @ 00070ba0
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
            goto LAB_00070ee0;
            if (pInvoker == (edict_t *)0x0) {
LAB_00070fb0:
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
                        goto LAB_00071060;
                      }
                      iVar6 = iVar6 + 1;
                      peVar8 = (event_state_t *)(peVar8->ei + 1);
                    } while (iVar6 != 0x40);
                  }
                  local_84 = &client->events;
                  iVar6 = 0;
                  peVar8 = local_84;
LAB_0007104d:
                  if (peVar8->ei[0].index != 0) goto LAB_00071040;
                  peVar10 = local_84->ei + iVar6;
LAB_00071060:
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
                  goto LAB_00070ee0;
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
LAB_00070ea0:
                if (((((byte)((uint)flags >> 2) ^ 1) & pInvoker != (edict_t *)0x0) == 0) ||
                   (qVar4 = SV_ValidClientMulticast(client,iVar3,4), iVar5 = svs.maxclients,
                   qVar4 != false)) goto LAB_00070fb0;
              }
              else if (g_groupop == 0) {
                if ((uVar1 & uVar7) != 0) goto LAB_00070ea0;
              }
              else if ((g_groupop != 1) || ((uVar1 & uVar7) == 0)) goto LAB_00070ea0;
            }
LAB_00070ee0:
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
LAB_00071040:
  iVar6 = iVar6 + 1;
  peVar8 = (event_state_t *)(peVar8->ei + 1);
  if (iVar6 == 0x40) goto LAB_00070ee0;
  goto LAB_0007104d;
}


// EV_Precache  @ 000709a0
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
        if (iVar3 == 0) goto LAB_00070a08;
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
    if (iVar3 == 0) goto LAB_00070a08;
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
LAB_00070a0b:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00070a08:
  uVar2 = (ushort)iVar5;
  goto LAB_00070a0b;
}


// EV_SV_Playback  @ 00071150
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
            goto LAB_000715b0;
            if (e == (edict_t *)0x0) {
              bVar2 = 0;
LAB_00071581:
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
                        goto LAB_000716bc;
                      }
                      iVar7 = iVar7 + 1;
                      peVar9 = (event_state_t *)(peVar9->ei + 1);
                    } while (iVar7 != 0x40);
                  }
                  local_80 = &client->events;
                  iVar7 = 0;
                  peVar9 = local_80;
LAB_000716ad:
                  if (peVar9->ei[0].index != 0) goto LAB_000716a0;
                  peVar11 = local_80->ei + iVar7;
LAB_000716bc:
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
                  goto LAB_000715b0;
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
LAB_00071550:
                if (bVar10 == 0) {
                  bVar2 = 1;
                }
                else {
                  qVar5 = SV_ValidClientMulticast(client,iVar4,4);
                  iVar6 = svs.maxclients;
                  bVar2 = bVar10;
                  if (qVar5 == false) goto LAB_000715b0;
                }
                goto LAB_00071581;
              }
              if (g_groupop == 0) {
                if ((uVar1 & uVar8) != 0) goto LAB_00071550;
              }
              else if ((g_groupop != 1) || ((uVar1 & uVar8) == 0)) goto LAB_00071550;
            }
LAB_000715b0:
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
LAB_000716a0:
  iVar7 = iVar7 + 1;
  peVar9 = (event_state_t *)(peVar9->ei + 1);
  if (iVar7 == 0x40) goto LAB_000715b0;
  goto LAB_000716ad;
}


