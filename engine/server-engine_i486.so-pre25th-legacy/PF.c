// PF_BuildSoundMsg_I  @ 00090b10
void PF_BuildSoundMsg_I(edict_t_conflict *entity,int channel,char *sample,float volume,
                       float attenuation,int fFlags,int pitch,int msg_dest,int msg_type,
                       float *pOrigin,edict_t_conflict *ed)

{
  PF_MessageBegin_I(msg_dest,msg_type,pOrigin,ed);
  SV_BuildSoundMsg(entity,channel,sample,(int)volume,attenuation,fFlags,pitch,pOrigin,&gMsgBuffer);
  PF_MessageEnd_I();
  return;
}


// PF_CanSkipPlayer  @ 00090d90
int PF_CanSkipPlayer(edict_t *pClient)

{
  int iVar1;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(pClient);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    return (uint)(svs.clients[iVar1 + -1].lw != 0);
  }
  Con_Printf("tried to PF_CanSkipPlayer a non-client\n");
  return 0;
}


// PF_CreateFakeClient_I  @ 0008f790
edict_t_conflict * PF_CreateFakeClient_I(char *netname)

{
  char *pcVar1;
  edict_t_conflict *peVar2;
  int iVar3;
  client_s *unaff_EBX;
  uint64 steamid;
  
                    /* Unresolved local var: client_t * fakeclient@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int g_userid@[???] */
  if (svs.maxclients < 1) {
    if (svs.maxclients != 0) {
      iVar3 = 0;
LAB_0008f7e0:
      peVar2 = EDICT_NUM(iVar3 + 1);
      if (unaff_EBX->frames != (client_frame_t *)0x0) {
        SV_ClearFrames(&unaff_EBX->frames);
      }
      Q_memset(unaff_EBX,0,0x4ef8);
      (unaff_EBX->resourcesneeded).pPrev = &unaff_EBX->resourcesneeded;
      (unaff_EBX->resourcesneeded).pNext = &unaff_EBX->resourcesneeded;
      (unaff_EBX->resourcesonhand).pPrev = &unaff_EBX->resourcesonhand;
      (unaff_EBX->resourcesonhand).pNext = &unaff_EBX->resourcesonhand;
      Q_strncpy(unaff_EBX->name,netname,0x20);
      unaff_EBX->active = true;
      unaff_EBX->fakeclient = true;
      unaff_EBX->edict = peVar2;
      unaff_EBX->name[0x1f] = '\0';
      unaff_EBX->spawned = true;
      unaff_EBX->userid = g_userid;
      pcVar1 = pr_strings;
      g_userid = g_userid + 1;
      unaff_EBX->fully_connected = true;
      unaff_EBX->connected = true;
      unaff_EBX->uploading = false;
      (peVar2->v).netname = (int)unaff_EBX->name - (int)pcVar1;
      pcVar1 = unaff_EBX->userinfo;
      (peVar2->v).flags = 0x2008;
      (peVar2->v).pContainingEntity = peVar2;
      Info_SetValueForKey(pcVar1,"name",netname,0x100);
      Info_SetValueForKey(pcVar1,"model","gordon",0x100);
      Info_SetValueForKey(pcVar1,"topcolor","1",0x100);
      Info_SetValueForKey(pcVar1,"bottomcolor","1",0x100);
      unaff_EBX->sendinfo = true;
      SV_ExtractFromUserinfo(unaff_EBX);
      steamid = ISteamGameServer_CreateUnauthenticatedUserConnection();
      (unaff_EBX->network_userid).idtype = 1;
      (unaff_EBX->network_userid).m_SteamID = steamid;
      ISteamGameServer_BUpdateUserData(steamid,netname,0);
      return peVar2;
    }
  }
  else {
    iVar3 = 0;
    unaff_EBX = svs.clients;
    do {
      if (((unaff_EBX->active == false) && (unaff_EBX->spawned == false)) &&
         (unaff_EBX->connected == false)) goto LAB_0008f7e0;
      iVar3 = iVar3 + 1;
      unaff_EBX = unaff_EBX + 1;
    } while (iVar3 != svs.maxclients);
  }
  return (edict_t_conflict *)0x0;
}


// PF_CreateInstancedBaseline  @ 00090e10
int PF_CreateInstancedBaseline(int classname,entity_state_s *baseline)

{
  undefined4 uVar1;
  extra_baselines_s *peVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  if ((sv.instance_baselines)->number < 0x3f) {
    (sv.instance_baselines)->classname[(sv.instance_baselines)->number] = classname;
    peVar2 = sv.instance_baselines;
    iVar4 = (sv.instance_baselines)->number;
    uVar3 = 0;
    do {
      uVar5 = uVar3;
      uVar1 = *(undefined4 *)((int)baseline->origin + (uVar5 - 0xc));
      *(undefined4 *)((int)peVar2->baseline[iVar4].origin + (uVar5 - 0x10)) =
           *(undefined4 *)((int)baseline->origin + (uVar5 - 0x10));
      *(undefined4 *)((int)peVar2->baseline[iVar4].origin + (uVar5 - 0xc)) = uVar1;
      uVar3 = uVar5 + 8;
    } while (uVar5 + 8 < 0x150);
    *(undefined4 *)((int)peVar2->baseline[iVar4].origin + (uVar5 - 8)) =
         *(undefined4 *)((int)baseline->origin + (uVar5 - 8));
    (sv.instance_baselines)->number = (sv.instance_baselines)->number + 1;
    iVar4 = (sv.instance_baselines)->number;
  }
  return iVar4;
}


// PF_Cvar_DirectSet  @ 00090e90
void PF_Cvar_DirectSet(cvar_s *var,char *value)

{
  char cVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  qboolean qVar6;
  char *s;
  char *pcVar7;
  float fVar8;
  char acStack_41c [1036];
  
  if ((value != (char *)0x0) && (var != (cvar_s *)0x0)) {
    uVar5 = var->flags;
    if ((uVar5 & 0x2000) != 0) {
      if ((((*value == '/') || (pcVar2 = Q_strstr(value,":"), pcVar2 != (char *)0x0)) ||
          (pcVar2 = Q_strstr(value,".."), pcVar2 != (char *)0x0)) ||
         (pcVar2 = Q_strstr(value,"\\"), pcVar2 != (char *)0x0)) {
        Con_Printf("Refusing to set %s to %s (invalid path)\n",var->name,value);
        return;
      }
      uVar5 = var->flags;
    }
    if ((uVar5 & 0x80) != 0) {
      acStack_41c[0] = '\0';
      qVar6 = Q_UnicodeValidate(value);
      if (qVar6 == 0) {
        pcVar2 = acStack_41c;
        while( true ) {
          pcVar7 = value + 1;
          cVar1 = *value;
          if (cVar1 == '\0') break;
          value = pcVar7;
          if ((byte)(cVar1 - 0x20U) < 0x5f) {
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
          }
        }
        *pcVar2 = '\0';
      }
      else {
        pcVar2 = acStack_41c;
        Q_strncpy_s(pcVar2,value,0x400);
      }
      value = acStack_41c;
      qVar6 = Q_UnicodeValidate(pcVar2);
      if (qVar6 == 0) {
        Q_UnicodeRepair(pcVar2);
      }
      iVar4 = Q_strlen(value);
      if (iVar4 == 0) {
        Q_strcpy(value,"empty");
      }
      uVar5 = var->flags;
    }
    pcVar2 = value;
    if ((uVar5 & 0x200) != 0) {
      pcVar2 = acStack_41c;
      if (value != pcVar2) {
        Q_strncpy_s(pcVar2,value,0x400);
      }
      Q_StripUnprintableAndSpace(pcVar2);
      uVar5 = var->flags;
    }
    pcVar7 = pcVar2;
    if ((uVar5 & 0x1000) != 0) {
      pcVar7 = acStack_41c;
      if (pcVar2 != pcVar7) {
        Q_strncpy_s(pcVar7,pcVar2,0x400);
      }
      sVar3 = strcspn(pcVar7,";\n");
      acStack_41c[sVar3] = '\0';
    }
    iVar4 = Q_strcmp(var->string,pcVar7);
    uVar5 = var->flags;
    if (((uVar5 & 2) != 0) && (cls.state == ca_dedicated)) {
      pcVar2 = var->name;
      s = Info_Serverinfo();
      Info_SetValueForKey(s,pcVar2,pcVar7,0x200);
      pcVar2 = Info_Serverinfo();
      SV_BroadcastCommand("fullserverinfo \"%s\"\n",pcVar2);
      uVar5 = var->flags;
    }
    if (((uVar5 & 4) != 0) && (iVar4 != 0)) {
      if ((uVar5 & 0x100) == 0) {
        if ((uVar5 & 0x20) == 0) {
          Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,pcVar7);
          pcVar2 = pcVar7;
        }
        else {
          Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,"***PROTECTED***");
          pcVar2 = "***PROTECTED***";
        }
        SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",var->name,pcVar2);
        uVar5 = var->flags;
      }
      pcVar2 = pcVar7;
      if ((uVar5 & 0x20) != 0) {
        pcVar2 = "0";
        iVar4 = Q_strlen(pcVar7);
        if ((0 < iVar4) && (iVar4 = Q_stricmp(pcVar7,"none"), iVar4 != 0)) {
          pcVar2 = "1";
        }
      }
      Steam_SetCVar(var->name,pcVar2);
    }
    Z_Free(var->string);
    iVar4 = Q_strlen(pcVar7);
    pcVar2 = Z_Malloc(iVar4 + 1);
    var->string = pcVar2;
    Q_strcpy(pcVar2,pcVar7);
    fVar8 = Q_atof(var->string);
    var->value = fVar8;
  }
  return;
}


// PF_DecalIndex  @ 0008ee90
int PF_DecalIndex(char *name)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = -1;
  if (0 < sv_decalnamecount) {
    iVar2 = 0;
    while( true ) {
      iVar1 = Q_stricmp(sv_decalnames[iVar2].name,name);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
      if (sv_decalnamecount <= iVar2) {
        return -1;
      }
    }
  }
  return iVar2;
}


// PF_FadeVolume  @ 00090800
void PF_FadeVolume(edict_t *clientent,int fadePercent,int fadeOutSeconds,int holdTime,
                  int fadeInSeconds)

{
  int iVar1;
  sizebuf_t *sb;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(clientent);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    if (svs.clients[iVar1 + -1].fakeclient != false) {
      return;
    }
    sb = &svs.clients[iVar1 + -1].netchan.message;
    MSG_WriteChar(sb,0x30);
    MSG_WriteByte(sb,fadePercent & 0xff);
    MSG_WriteByte(sb,holdTime & 0xff);
    MSG_WriteByte(sb,fadeOutSeconds & 0xff);
    MSG_WriteByte(sb,fadeInSeconds & 0xff);
    return;
  }
  Con_Printf("tried to PF_FadeVolume a non-client\n");
  return;
}


// PF_ForceUnmodified  @ 00090ea0
void PF_ForceUnmodified(FORCE_TYPE type,float *mins,float *maxs,char *filename)

{
  int iVar1;
  consistency_t *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (filename == (char *)0x0) {
    Host_Error("PF_ForceUnmodified: NULL pointer");
    return;
  }
  if (*filename < '!') {
    type = (FORCE_TYPE)s_PF_ForceUnmodified__Bad_string___000e7034;
  }
  else {
    pcVar2 = sv.consistency_list;
    if (sv.state != ss_loading) {
      do {
        if ((pcVar2->filename != (char *)0x0) &&
           (iVar3 = Q_stricmp(pcVar2->filename,filename), iVar3 == 0)) {
          return;
        }
        pcVar2 = pcVar2 + 1;
      } while (pcVar2 != (consistency_t *)&sv.num_consistency);
      Host_Error("ForceUnmodified: \'%s\' Precache can only be done in spawn functions",filename);
    }
    pcVar2 = sv.consistency_list;
    iVar3 = 0;
    do {
      if (pcVar2->filename == (char *)0x0) {
        sv.consistency_list[iVar3].filename = filename;
        sv.consistency_list[iVar3].check_type = type;
        if (mins != (float *)0x0) {
          sv.consistency_list[iVar3].mins[0] = *mins;
          sv.consistency_list[iVar3].mins[1] = mins[1];
          sv.consistency_list[iVar3].mins[2] = mins[2];
        }
        if (maxs == (float *)0x0) {
          return;
        }
        sv.consistency_list[iVar3].maxs[0] = *maxs;
        sv.consistency_list[iVar3].maxs[1] = maxs[1];
        sv.consistency_list[iVar3].maxs[2] = maxs[2];
        return;
      }
      iVar1 = Q_stricmp(pcVar2->filename,filename);
      if (iVar1 == 0) {
        return;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 != 0x200);
    type = (FORCE_TYPE)s_ForceUnmodified____s__overflow_000e709c;
  }
  Host_Error((char *)type);
  return;
}


// PF_GetCurrentPlayer  @ 00090d50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PF_GetCurrentPlayer(void)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int idx@[DW_OP_reg2(EDX)] */
  iVar2 = ((int)host_client - (int)svs.clients >> 3) * -0x6d690de1;
  if (-1 < iVar2) {
    iVar1 = -1;
    if (iVar2 < svs.maxclients) {
      iVar1 = iVar2;
    }
    return iVar1;
  }
  return -1;
}


// PF_GetInfoKeyBuffer_I  @ 0008ead0
char * PF_GetInfoKeyBuffer_I(edict_t_conflict *e)

{
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: int e1@[???]
                       Unresolved local var: char * value@[???] */
  if (e == (edict_t_conflict *)0x0) {
    return localinfo;
  }
  iVar1 = NUM_FOR_EDICT((edict_t *)e);
  if (iVar1 != 0) {
    pcVar2 = "";
    if (iVar1 < 0x21) {
      pcVar2 = svs.clients[iVar1 + -1].userinfo;
    }
    return pcVar2;
  }
  pcVar2 = Info_Serverinfo();
  return pcVar2;
}


// PF_GetPhysicsInfoString  @ 00090c00
char * PF_GetPhysicsInfoString(edict_t *pClient)

{
  int iVar1;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(pClient);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    return svs.clients[iVar1 + -1].physinfo;
  }
  Con_Printf("tried to PF_GetPhysicsInfoString a non-client\n");
  return "";
}


// PF_GetPhysicsKeyValue  @ 00090c50
char * PF_GetPhysicsKeyValue(edict_t *pClient,char *key)

{
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(pClient);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    pcVar2 = Info_ValueForKey(svs.clients[iVar1 + -1].physinfo,key);
    return pcVar2;
  }
  Con_Printf("tried to PF_GetPhysicsKeyValue a non-client\n");
  return "";
}


// PF_GetPlayerAuthId  @ 000909f0
char * PF_GetPlayerAuthId(edict_t_conflict *e)

{
  int iVar1;
  char *pcVar2;
  char (*pacVar3) [64];
  client_s *client;
  int iVar4;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  PF_GetPlayerAuthId::count = (PF_GetPlayerAuthId::count + 1) % 5;
  pacVar3 = PF_GetPlayerAuthId::szAuthID + PF_GetPlayerAuthId::count;
  PF_GetPlayerAuthId::szAuthID[PF_GetPlayerAuthId::count][0] = '\0';
  if ((sv.active != false) && (e != (edict_t_conflict *)0x0)) {
    if (0 < svs.maxclients) {
      iVar4 = 0;
      iVar1 = svs.maxclients;
      client = svs.clients;
      do {
        while (client->edict != e) {
          iVar4 = iVar4 + 1;
          client = client + 1;
          if (iVar1 <= iVar4) goto LAB_00090ad6;
        }
        if (client->fakeclient == false) {
          if ((client->network_userid).idtype == 3) {
            pcVar2 = "HLTV";
          }
          else {
            pcVar2 = SV_GetClientIDString(client);
          }
        }
        else {
          pcVar2 = "BOT";
        }
        iVar4 = iVar4 + 1;
        client = client + 1;
        snprintf(PF_GetPlayerAuthId::szAuthID[PF_GetPlayerAuthId::count],0x3f,"%s",pcVar2);
        iVar1 = svs.maxclients;
      } while (iVar4 < svs.maxclients);
    }
LAB_00090ad6:
    iVar1 = PF_GetPlayerAuthId::count;
    PF_GetPlayerAuthId::szAuthID[PF_GetPlayerAuthId::count][0x3f] = '\0';
    pacVar3 = PF_GetPlayerAuthId::szAuthID + iVar1;
  }
  return *pacVar3;
}


// PF_GetPlayerStats  @ 00091010
void PF_GetPlayerStats(edict_t *pClient,int *ping,int *packet_loss)

{
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  *ping = 0;
  *packet_loss = 0;
  iVar2 = NUM_FOR_EDICT(pClient);
  pcVar1 = svs.clients;
  if ((0 < iVar2) && (iVar2 <= svs.maxclients)) {
    *ping = (int)(svs.clients[iVar2 + -1].latency * 1000.0);
    *packet_loss = (int)pcVar1[iVar2 + -1].packet_loss;
    return;
  }
  Con_Printf("tried to PF_GetPlayerStats a non-client\n");
  return;
}


// PF_GetPlayerUserId  @ 00090980
int PF_GetPlayerUserId(edict_t_conflict *e)

{
  edict_t_conflict *peVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  if (((sv.active != false) && (e != (edict_t_conflict *)0x0)) && (0 < svs.maxclients)) {
    iVar3 = 0;
    peVar1 = (svs.clients)->edict;
    pcVar2 = svs.clients;
    while( true ) {
      if (peVar1 == e) {
        return pcVar2->userid;
      }
      iVar3 = iVar3 + 1;
      if (iVar3 == svs.maxclients) break;
      peVar1 = pcVar2[1].edict;
      pcVar2 = pcVar2 + 1;
    }
  }
  return -1;
}


// PF_GetPlayerWONId  @ 000909e0
uint PF_GetPlayerWONId(edict_t_conflict *e)

{
  return 0xffffffff;
}


// PF_InfoKeyValue_I  @ 0008eb30
char * PF_InfoKeyValue_I(char *infobuffer,char *key)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  char acStack_8c [128];
  
  Info_ValueForKey::valueindex = (Info_ValueForKey::valueindex + 1) % 4;
  cVar1 = *infobuffer;
  if (cVar1 == '\\') {
    cVar1 = infobuffer[1];
    infobuffer = infobuffer + 1;
  }
  uVar3 = 0;
  pcVar4 = acStack_8c;
  do {
    if ((uVar3 < 0x7f) && (cVar1 != '\\')) {
      if (cVar1 == '\0') {
LAB_0007e435:
        return "";
      }
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
      uVar3 = uVar3 + 1;
    }
    else {
      cVar1 = infobuffer[1];
      *pcVar4 = '\0';
      pcVar5 = infobuffer + 1;
      pcVar4 = Info_ValueForKey::value[Info_ValueForKey::valueindex];
      if ((cVar1 != '\\') && (cVar1 != '\0')) {
        do {
          *pcVar4 = cVar1;
          pcVar5 = pcVar5 + 1;
          pcVar4 = pcVar4 + 1;
          cVar1 = *pcVar5;
          if ((cVar1 == '\0') || (cVar1 == '\\')) break;
        } while (pcVar5 != infobuffer + 0x80);
      }
      *pcVar4 = '\0';
      iVar2 = Q_strcmp(key,acStack_8c);
      if (iVar2 == 0) {
        return Info_ValueForKey::value[Info_ValueForKey::valueindex];
      }
      if (*pcVar5 == '\0') goto LAB_0007e435;
      uVar3 = 0;
      pcVar4 = acStack_8c;
      infobuffer = pcVar5;
    }
    infobuffer = infobuffer + 1;
    cVar1 = *infobuffer;
  } while( true );
}


// PF_IsDedicatedServer  @ 00090bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PF_IsDedicatedServer(void)

{
  return g_bIsDedicatedServer;
}


// PF_IsMapValid_I  @ 0008ea40
int PF_IsMapValid_I(char *mapname)

{
  int iVar1;
  char local_110 [268];
  
                    /* Unresolved local var: char[260] cBuf@[???] */
  iVar1 = 0;
  if ((mapname != (char *)0x0) && (*mapname != '\0')) {
    snprintf(local_110,0x104,"maps/%.32s.bsp",mapname);
    iVar1 = FS_FileExists(local_110);
  }
  return iVar1;
}


// PF_MessageBegin_I  @ 0008fc20
void PF_MessageBegin_I(int msg_dest,int msg_type,float *pOrigin,edict_t_conflict *ed)

{
  if (((msg_dest == 8) || (msg_dest == 1)) && (ed == (edict_t_conflict *)0x0)) {
    Sys_Error("MSG_ONE or MSG_ONE_UNRELIABLE with no target entity\n");
  }
  if (((msg_dest != 1) && (msg_dest != 8)) && (ed != (edict_t_conflict *)0x0)) {
    Sys_Error("Invalid message;  cannot use broadcast message with a target entity");
  }
  if (gMsgStarted != false) {
    Sys_Error("New message started when msg \'%d\' has not been sent yet",gMsgType);
  }
  if (msg_type == 0) {
    Sys_Error("Tried to create a message with a bogus message type ( 0 )");
  }
  gMsgDest = msg_dest;
  gMsgStarted = true;
  gMsgType = msg_type;
  gMsgEntity = ed;
  if (msg_dest - 4U < 2) {
    if (pOrigin != (float *)0x0) {
      gMsgOrigin[0] = *pOrigin;
      gMsgOrigin[1] = pOrigin[1];
      gMsgOrigin[2] = pOrigin[2];
    }
    Host_IsSinglePlayerGame();
  }
  gMsgBuffer.flags = 1;
  gMsgBuffer.cursize = 0;
  return;
}


// PF_MessageEnd_I  @ 0008fd60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PF_MessageEnd_I(void)

{
  bool bVar1;
  UserMsg *pUVar2;
  sizebuf_t *sb;
  int iVar3;
  client_s *pcVar4;
  qboolean reliable;
  
                    /* Unresolved local var: qboolean MsgIsVarLength@[???]
                       Unresolved local var: sizebuf_t * pBuffer@[???]
                       Unresolved local var: int entnum@[???] */
  if (gMsgStarted == false) {
    Sys_Error("MESSAGE_END called with no active message\n");
  }
  gMsgStarted = false;
  if ((gMsgEntity != (edict_t_conflict *)0x0) && (((gMsgEntity->v).flags & 0x2000) != 0)) {
    gMsgStarted = false;
    return;
  }
  if (((byte)gMsgBuffer.flags & 2) != 0) {
    Sys_Error("MESSAGE_END called, but message buffer from .dll had overflowed\n");
    return;
  }
  pUVar2 = sv_gpUserMsgs;
  if (0x3b < gMsgType) {
    for (; pUVar2 != (UserMsg *)0x0; pUVar2 = pUVar2->next) {
      if (gMsgType == pUVar2->iMsg) goto LAB_0008fdd2;
    }
    pUVar2 = sv_gpNewUserMsgs;
    if (gMsgDest == 3) {
      for (; pUVar2 != (UserMsg *)0x0; pUVar2 = pUVar2->next) {
        if (gMsgType == pUVar2->iMsg) goto LAB_0008fdd2;
      }
    }
    Con_DPrintf("PF_MessageEnd_I:  Unknown User Msg %d\n",gMsgType);
    return;
  }
  bVar1 = false;
LAB_0008fe3a:
  sb = WriteDest_Parm(gMsgDest);
  if (((gMsgDest != 0) || (sb->cursize + gMsgBuffer.cursize <= sb->maxsize)) &&
     (sb->data != (byte *)0x0)) {
    if ((0x3b < gMsgType) && ((gMsgDest == 8 || (gMsgDest == 1)))) {
                    /* Unresolved local var: client_t * cl@[???] */
      iVar3 = NUM_FOR_EDICT((edict_t *)gMsgEntity);
      if ((iVar3 < 1) || (svs.maxclients < iVar3)) {
        Host_Error("WriteDest_Parm: not a client");
      }
      pcVar4 = svs.clients + iVar3 + -1;
      if (pcVar4->hasusrmsgs == false) {
        return;
      }
      if ((pcVar4->active == false) && (pcVar4->spawned == false)) {
        return;
      }
      if (pcVar4->fakeclient != false) {
        return;
      }
    }
    MSG_WriteByte(sb,gMsgType);
    if (bVar1) {
      MSG_WriteByte(sb,gMsgBuffer.cursize);
    }
    MSG_WriteBuf(sb,gMsgBuffer.cursize,gMsgBuffer.data);
    if (gMsgDest == 5) {
      reliable = false;
LAB_0008ff4f:
      SV_Multicast(gMsgEntity,gMsgOrigin,4,reliable);
      return;
    }
    if (gMsgDest < 6) {
      if (gMsgDest == 4) {
        SV_Multicast(gMsgEntity,gMsgOrigin,2,false);
      }
    }
    else if ((gMsgDest == 6) || (gMsgDest == 7)) {
      reliable = true;
      goto LAB_0008ff4f;
    }
  }
  return;
LAB_0008fdd2:
  iVar3 = pUVar2->iSize;
  if (iVar3 == -1) {
    bVar1 = true;
    if (0xc0 < gMsgBuffer.cursize) {
      Host_Error("PF_MessageEnd_I:  Refusing to send user message %s of %i bytes to client, user message size limit is %i bytes\n"
                 ,pUVar2->szName,gMsgBuffer.cursize,0xc0);
      return;
    }
  }
  else {
    bVar1 = false;
    if (iVar3 != gMsgBuffer.cursize) {
      Sys_Error("User Msg \'%s\': %d bytes written, expected %d\n",pUVar2->szName,gMsgBuffer.cursize
                ,iVar3);
      return;
    }
  }
  goto LAB_0008fe3a;
}


// PF_NumberOfEntities_I  @ 0008ea90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PF_NumberOfEntities_I(void)

{
  int iVar1;
  edict_t_conflict *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int ent_count@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = 0;
  if (0 < sv.num_edicts) {
    iVar3 = 0;
    peVar2 = sv.edicts;
    do {
      if (peVar2->free == 0) {
        iVar1 = iVar1 + 1;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 != sv.num_edicts);
  }
  return iVar1;
}


// PF_RemoveKey_I  @ 0008ebe0
void PF_RemoveKey_I(char *s,char *key)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  size_t count;
  char acStack_11c [128];
  char acStack_9c [140];
  
  sVar2 = strlen(key);
  count = 0x7f;
  if (sVar2 < 0x7f) {
    count = sVar2;
  }
  pcVar3 = Q_strstr(key,"\\");
  if (pcVar3 == (char *)0x0) {
    cVar1 = *s;
    pcVar3 = s;
    if (cVar1 == '\\') goto LAB_0007e55d;
LAB_0007e4ce:
    if (cVar1 != '\0') {
      uVar7 = 0;
      pcVar5 = acStack_11c;
      while( true ) {
        uVar7 = uVar7 + 1;
        s = s + 1;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
        cVar1 = *s;
        if ((0x7e < uVar7) || (cVar1 == '\\')) break;
        if (cVar1 == '\0') {
          return;
        }
      }
      do {
        cVar1 = s[1];
        pcVar8 = s + 1;
        *pcVar5 = '\0';
        if ((cVar1 == '\0') || (cVar1 == '\\')) {
          pcVar5 = acStack_9c;
          s = pcVar8;
        }
        else {
          pcVar6 = s + 0x80;
          pcVar5 = acStack_9c;
          do {
            pcVar8 = pcVar8 + 1;
            *pcVar5 = cVar1;
            cVar1 = *pcVar8;
            pcVar5 = pcVar5 + 1;
            s = pcVar8;
            if ((cVar1 == '\0') || (cVar1 == '\\')) break;
          } while (pcVar8 != pcVar6);
        }
        *pcVar5 = '\0';
        iVar4 = Q_strncmp(key,acStack_11c,count);
        if (iVar4 == 0) {
          Q_strcpy(pcVar3,s);
          return;
        }
        cVar1 = *s;
        if (cVar1 == '\0') {
          return;
        }
        pcVar3 = s;
        if (cVar1 != '\\') goto LAB_0007e4ce;
LAB_0007e55d:
        cVar1 = pcVar3[1];
        s = pcVar3 + 1;
        if (cVar1 != '\\') goto LAB_0007e4ce;
        pcVar5 = acStack_11c;
      } while( true );
    }
  }
  else {
    Con_Printf("Can\'t use a key with a \\\n");
  }
  return;
}


// PF_Remove_I  @ 0008d980
void PF_Remove_I(edict_t_conflict *ed)

{
  if (ed->free != 0) {
    return;
  }
  ED_Free(ed);
  return;
}


// PF_RunPlayerMove_I  @ 0008f9a0
void PF_RunPlayerMove_I(edict_t_conflict *fakeclient,float *viewangles,float forwardmove,
                       float sidemove,float upmove,ushort buttons,uchar impulse,uchar msec)

{
  client_t *pcVar1;
  edict_t_conflict *peVar2;
  int iVar3;
  uint uVar4;
  usercmd_t local_50;
  
  peVar2 = sv_player;
                    /* Unresolved local var: usercmd_t cmd@[???]
                       Unresolved local var: edict_t.conflict * oldclient@[???]
                       Unresolved local var: client_t * old@[???]
                       Unresolved local var: int entnum@[???] */
  pcVar1 = host_client;
  iVar3 = NUM_FOR_EDICT((edict_t *)fakeclient);
  sv_player = fakeclient;
  host_client = svs.clients + iVar3 + -1;
  host_client->svtimebase = (sv.time + host_frametime) - (double)msec / 1000.0;
  Q_memset(&local_50,0,0x34);
  local_50.viewangles[0] = *viewangles;
  local_50.msec = msec;
  local_50.lightlevel = '\0';
  local_50.viewangles[1] = viewangles[1];
  local_50.buttons = buttons;
  local_50.viewangles[2] = viewangles[2];
  local_50.forwardmove = forwardmove;
  local_50.sidemove = sidemove;
  local_50.upmove = upmove;
  local_50.impulse = impulse;
  pmove = &g_svmove;
  SV_PreRunCmd();
  SV_RunCmd(&local_50,0);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)(host_client->lastcmd).viewangles + (uVar4 - 4)) =
         *(undefined4 *)((int)local_50.viewangles + (uVar4 - 4));
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x34);
  sv_player = peVar2;
  host_client = pcVar1;
  return;
}


// PF_SetClientKeyValue_I  @ 0008ebf0
void PF_SetClientKeyValue_I(int clientIndex,char *infobuffer,char *key,char *value)

{
  client_s *pcVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: client_t * pClient@[DW_OP_reg6(ESI)] */
  if (infobuffer != localinfo) {
    pcVar2 = Info_Serverinfo();
    if (((pcVar2 != infobuffer) && (0 < clientIndex)) && (clientIndex <= svs.maxclients)) {
      pcVar2 = Info_ValueForKey(infobuffer,key);
      iVar3 = Q_strcmp(pcVar2,value);
      if (iVar3 != 0) {
        Info_SetValueForStarKey(infobuffer,key,value,0x100);
        pcVar1 = svs.clients;
        svs.clients[clientIndex + -1].sendinfo = true;
        pcVar1[clientIndex + -1].sendinfo_time = 0.0;
      }
    }
  }
  return;
}


// PF_SetClientMaxspeed  @ 00090920
void PF_SetClientMaxspeed(edict_t *clientent,float fNewMaxspeed)

{
  int iVar1;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: entvars_t * ev@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(clientent);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    (clientent->v).maxspeed = fNewMaxspeed;
    return;
  }
  Con_Printf("tried to PF_SetClientMaxspeed a non-client\n");
  return;
}


// PF_SetGroupMask  @ 00090df0
void PF_SetGroupMask(int mask,int op)

{
  g_groupmask = mask;
  g_groupop = op;
  return;
}


// PF_SetKeyValue_I  @ 0008eb40
void PF_SetKeyValue_I(char *infobuffer,char *key,char *value)

{
  char *s;
  
  if (infobuffer == localinfo) {
    Info_SetValueForKey(localinfo,key,value,0x8000);
  }
  else {
    s = Info_Serverinfo();
    if (s != infobuffer) {
      Sys_Error("Can\'t set client keys with SetKeyValue");
      return;
    }
    Info_SetValueForKey(s,key,value,0x200);
  }
  return;
}


// PF_SetPhysicsKeyValue  @ 00090cc0
void PF_SetPhysicsKeyValue(edict_t *pClient,char *key,char *value)

{
  int iVar1;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(pClient);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    Info_SetValueForKey(svs.clients[iVar1 + -1].physinfo,key,value,0x100);
    return;
  }
  Con_Printf("tried to PF_SetPhysicsKeyValue a non-client\n");
  return;
}


// PF_Spawn_I  @ 0008d8e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

edict_t_conflict * PF_Spawn_I(void)

{
  void *pvVar1;
  edict_t_conflict *peVar2;
  int iVar3;
  
                    /* Unresolved local var: edict_t.conflict * pedict@[???] */
  iVar3 = svs.maxclients + 1;
  if (iVar3 < sv.num_edicts) {
    peVar2 = sv.edicts + iVar3;
    do {
      if ((peVar2->free != 0) &&
         (((double)peVar2->freetime < 2.0 || (0.5 < sv.time - (double)peVar2->freetime)))) {
        Q_memset(&peVar2->v,0,0x2a4);
        pvVar1 = peVar2->pvPrivateData;
        peVar2->free = 0;
        if (pvVar1 != (void *)0x0) {
          if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
            (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(peVar2);
            pvVar1 = peVar2->pvPrivateData;
          }
          Mem_Free(pvVar1);
        }
        peVar2->pvPrivateData = (void *)0x0;
        (peVar2->v).pContainingEntity = peVar2;
        return peVar2;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 != sv.num_edicts);
  }
  if (sv.max_edicts <= iVar3) {
    if (sv.max_edicts == 0) {
      Sys_Error("ED_Alloc: No edicts yet");
    }
    Sys_Error("ED_Alloc: no free edicts");
  }
  sv.num_edicts = sv.num_edicts + 1;
  peVar2 = sv.edicts + iVar3;
  Q_memset(&peVar2->v,0,0x2a4);
  pvVar1 = peVar2->pvPrivateData;
  peVar2->free = 0;
  if (pvVar1 != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(peVar2);
      pvVar1 = peVar2->pvPrivateData;
    }
    Mem_Free(pvVar1);
  }
  peVar2->pvPrivateData = (void *)0x0;
  (peVar2->v).pContainingEntity = peVar2;
  return peVar2;
}


// PF_StaticDecal  @ 00090400
void PF_StaticDecal(float *origin,int decalIndex,int entityIndex,int modelIndex)

{
  MSG_WriteByte(&sv.signon,0x17);
  MSG_WriteByte(&sv.signon,0xd);
  MSG_WriteCoord(&sv.signon,*origin);
  MSG_WriteCoord(&sv.signon,origin[1]);
  MSG_WriteCoord(&sv.signon,origin[2]);
  MSG_WriteShort(&sv.signon,decalIndex);
  MSG_WriteShort(&sv.signon,entityIndex);
  if (entityIndex == 0) {
    return;
  }
  MSG_WriteShort(&sv.signon,modelIndex);
  return;
}


// PF_Time  @ 0008ba90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float PF_Time(void)

{
  double dVar1;
  
  dVar1 = Sys_FloatTime();
  return (float)dVar1;
}


// PF_TraceToss_DLL  @ 0008ce60
void PF_TraceToss_DLL(edict_t_conflict *pent,edict_t_conflict *pentToIgnore,TraceResult *ptr)

{
  uint uVar1;
  trace_t local_8c;
  trace_t tStack_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  if (pentToIgnore == (edict_t_conflict *)0x0) {
    pentToIgnore = sv.edicts;
  }
  SV_Trace_Toss(&local_8c,pent,pentToIgnore);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)tStack_44.endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_8c.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  SV_SetGlobalTrace(&tStack_44);
  ptr->fAllSolid = (int)gGlobalVariables.trace_allsolid;
  ptr->fStartSolid = (int)gGlobalVariables.trace_startsolid;
  ptr->fInOpen = (int)gGlobalVariables.trace_inopen;
  ptr->fInWater = (int)gGlobalVariables.trace_inwater;
  ptr->flFraction = gGlobalVariables.trace_fraction;
  ptr->flPlaneDist = gGlobalVariables.trace_plane_dist;
  ptr->pHit = gGlobalVariables.trace_ent;
  ptr->vecEndPos[0] = gGlobalVariables.trace_endpos[0];
  ptr->vecEndPos[1] = gGlobalVariables.trace_endpos[1];
  ptr->vecEndPos[2] = gGlobalVariables.trace_endpos[2];
  ptr->vecPlaneNormal[0] = gGlobalVariables.trace_plane_normal[0];
  ptr->vecPlaneNormal[1] = gGlobalVariables.trace_plane_normal[1];
  ptr->vecPlaneNormal[2] = gGlobalVariables.trace_plane_normal[2];
  ptr->iHitgroup = gGlobalVariables.trace_hitgroup;
  return;
}


// PF_TraceToss_Shared  @ 0008cc50
void PF_TraceToss_Shared(edict_t_conflict *ent,edict_t_conflict *ignore)

{
  uint uVar1;
  trace_t local_8c;
  trace_t tStack_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  SV_Trace_Toss(&local_8c,ent,ignore);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)tStack_44.endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_8c.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  SV_SetGlobalTrace(&tStack_44);
  return;
}


// PF_WaterMove  @ 000b50a0
void PF_WaterMove(edict_t_conflict *pSelf)

{
  vec_t *veca;
  uint uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int32 iVar6;
  longdouble lVar7;
  
                    /* Unresolved local var: int flags@[???]
                       Unresolved local var: int waterlevel@[???]
                       Unresolved local var: int watertype@[???]
                       Unresolved local var: float drownlevel@[???] */
  if ((pSelf->v).movetype == 8) {
LAB_000b5180:
    (pSelf->v).air_finished = (float)sv.time + 12.0;
    return;
  }
  if ((pSelf->v).health < 0.0) {
    return;
  }
  fVar5 = 1.0;
  uVar1 = (pSelf->v).flags;
  iVar2 = (pSelf->v).waterlevel;
  iVar3 = (pSelf->v).watertype;
  if ((pSelf->v).deadflag == 0) {
    fVar5 = 3.0;
  }
  if ((uVar1 & 0x20040) == 0) {
    if (((uVar1 & 2) != 0) || (fVar5 <= (float)iVar2)) {
      fVar5 = (float)sv.time;
      if (((pSelf->v).air_finished < fVar5) && ((pSelf->v).pain_finished < fVar5)) {
        fVar4 = (pSelf->v).dmg + 2.0;
        (pSelf->v).dmg = fVar4;
        if (15.0 < fVar4) {
          (pSelf->v).dmg = 10.0;
        }
        (pSelf->v).pain_finished = fVar5 + 1.0;
      }
    }
    else {
      (pSelf->v).air_finished = (float)sv.time + 12.0;
      (pSelf->v).dmg = 2.0;
    }
  }
  if (iVar2 == 0) {
    if ((uVar1 & 0x10) != 0) {
      iVar6 = RandomLong(0,3);
      if (iVar6 == 1) {
        SV_StartSound(0,pSelf,4,"player/pl_wade2.wav",0xff,0.8,0,100);
      }
      else if (iVar6 < 2) {
        if (iVar6 == 0) {
          SV_StartSound(0,pSelf,4,"player/pl_wade1.wav",0xff,0.8,0,100);
        }
      }
      else if (iVar6 == 2) {
        SV_StartSound(0,pSelf,4,"player/pl_wade3.wav",0xff,0.8,0,100);
      }
      else if (iVar6 == 3) {
        SV_StartSound(0,pSelf,4,"player/pl_wade4.wav",0xff,0.8,0,100);
      }
      (pSelf->v).flags = uVar1 & 0xffffffef;
    }
    goto LAB_000b5180;
  }
  if (iVar3 == -5) {
    if (((uVar1 & 0x80040) != 0) ||
       (lVar7 = (longdouble)sv.time, lVar7 <= (longdouble)(pSelf->v).dmgtime)) goto LAB_000b51d0;
    if ((longdouble)(pSelf->v).radsuit_finished < lVar7) {
      (pSelf->v).dmgtime = (float)(lVar7 + (longdouble)0.2);
      goto LAB_000b51d0;
    }
  }
  else if ((((iVar3 != -4) || ((uVar1 & 0x40040) != 0)) || (sv.time <= (double)(pSelf->v).dmgtime))
          || (sv.time <= (double)(pSelf->v).radsuit_finished)) goto LAB_000b51d0;
  (pSelf->v).dmgtime = (float)sv.time + 1.0;
LAB_000b51d0:
  if ((uVar1 & 0x10) == 0) {
    if (iVar3 == -3) {
      iVar6 = RandomLong(0,3);
      if (iVar6 == 1) {
        SV_StartSound(0,pSelf,4,"player/pl_wade2.wav",0xff,0.8,0,100);
      }
      else if (iVar6 < 2) {
        if (iVar6 == 0) {
          SV_StartSound(0,pSelf,4,"player/pl_wade1.wav",0xff,0.8,0,100);
        }
      }
      else if (iVar6 == 2) {
        SV_StartSound(0,pSelf,4,"player/pl_wade3.wav",0xff,0.8,0,100);
      }
      else if (iVar6 == 3) {
        SV_StartSound(0,pSelf,4,"player/pl_wade4.wav",0xff,0.8,0,100);
      }
    }
    (pSelf->v).flags = uVar1 | 0x10;
    (pSelf->v).dmgtime = 0.0;
  }
  if ((uVar1 & 0x800) != 0) {
    return;
  }
  veca = (pSelf->v).velocity;
  VectorMA(veca,(float)(pSelf->v).waterlevel * -0.8 * (float)host_frametime,veca,veca);
  return;
}


// PF_WriteAngle_I  @ 00090140
void PF_WriteAngle_I(float flValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteAngle_I called with no active message\n");
  }
  MSG_WriteAngle(&gMsgBuffer,flValue);
  return;
}


// PF_WriteByte_I  @ 00090080
void PF_WriteByte_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("WRITE_BYTE called with no active message\n");
  }
  MSG_WriteByte(&gMsgBuffer,iValue);
  return;
}


// PF_WriteChar_I  @ 000900b0
void PF_WriteChar_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("WRITE_CHAR called with no active message\n");
  }
  MSG_WriteChar(&gMsgBuffer,iValue);
  return;
}


// PF_WriteCoord_I  @ 00090170
void PF_WriteCoord_I(float flValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteCoord_I called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,(int)(flValue * 8.0));
  return;
}


// PF_WriteEntity_I  @ 00090200
void PF_WriteEntity_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteEntity_I called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,iValue);
  return;
}


// PF_WriteLong_I  @ 00090110
void PF_WriteLong_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteLong_I called with no active message\n");
  }
  MSG_WriteLong(&gMsgBuffer,iValue);
  return;
}


// PF_WriteShort_I  @ 000900e0
void PF_WriteShort_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("WRITE_SHORT called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,iValue);
  return;
}


// PF_WriteString_I  @ 000901c0
void PF_WriteString_I(char *sz)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteString_I called with no active message\n");
  }
  MSG_WriteString(&gMsgBuffer,sz);
  return;
}


// PF_aim_I  @ 0008efd0
void PF_aim_I(edict_t_conflict *ent,float speed,float *rgflReturn)

{
  int iVar1;
  float fVar2;
  int iVar3;
  edict_t_conflict *peVar4;
  int iVar5;
  int iVar6;
  float local_a4;
  vec_t local_a0;
  vec_t local_9c;
  vec_t local_98;
  trace_t local_84;
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  
                    /* Unresolved local var: edict_t.conflict * check@[???]
                       Unresolved local var: edict_t.conflict * bestent@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: vec3_t bestdir@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: trace_t tr@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float bestdist@[???] */
  if ((ent != (edict_t_conflict *)0x0) && (((ent->v).flags & 0x2000) == 0)) {
    local_34 = (ent->v).origin[0] + (ent->v).view_ofs[0];
    local_4c = gGlobalVariables.v_forward[0];
    local_30 = (ent->v).origin[1] + (ent->v).view_ofs[1];
    local_48 = gGlobalVariables.v_forward[1];
    local_2c = (ent->v).origin[2] + (ent->v).view_ofs[2];
    local_44 = gGlobalVariables.v_forward[2];
    VectorMA(&local_34,2048.0,&local_4c,&local_28);
    SV_Move(&local_84,&local_34,vec3_origin,vec3_origin,&local_28,0,ent,false);
    if (((local_84.ent == (edict_t_conflict *)0x0) || (((local_84.ent)->v).takedamage != 2.0)) ||
       ((iVar3 = (ent->v).team, 0 < iVar3 && (iVar3 == ((local_84.ent)->v).team)))) {
      local_a4 = sv_aim.value;
      local_98 = local_4c;
      local_a0 = local_48;
      local_9c = local_44;
      if (1 < sv.num_edicts) {
        iVar5 = 0x324;
        iVar6 = 1;
        iVar3 = sv.num_edicts;
        do {
          peVar4 = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar5 + -0x18);
          if (((((peVar4->v).takedamage == 2.0) && (((peVar4->v).flags & 0x2000) == 0)) &&
              (peVar4 != ent)) &&
             ((iVar1 = (ent->v).team, iVar1 < 1 || (iVar1 != (peVar4->v).team)))) {
            local_28 = (ent->v).view_ofs[0] * 0.0 +
                       ((peVar4->v).mins[0] + (peVar4->v).maxs[0]) * 0.75 + (peVar4->v).origin[0];
            local_24 = (ent->v).view_ofs[1] * 0.0 +
                       ((peVar4->v).mins[1] + (peVar4->v).maxs[1]) * 0.75 + (peVar4->v).origin[1];
            fStack_20 = (ent->v).view_ofs[2] * 0.0 +
                        ((peVar4->v).mins[2] + (peVar4->v).maxs[2]) * 0.75 + (peVar4->v).origin[2];
            local_4c = local_28 - local_34;
            local_48 = local_24 - local_30;
            local_44 = fStack_20 - local_2c;
            VectorNormalize(&local_4c);
            fVar2 = local_44 * gGlobalVariables.v_forward[2] +
                    local_48 * gGlobalVariables.v_forward[1] +
                    local_4c * gGlobalVariables.v_forward[0];
            iVar3 = sv.num_edicts;
            if ((local_a4 <= fVar2) &&
               (SV_Move(&local_84,&local_34,vec3_origin,vec3_origin,&local_28,0,ent,false),
               iVar3 = sv.num_edicts, peVar4 == local_84.ent)) {
              local_98 = local_4c;
              local_a0 = local_48;
              local_9c = local_44;
              local_a4 = fVar2;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x324;
        } while (iVar6 < iVar3);
      }
      *rgflReturn = local_98;
      rgflReturn[1] = local_a0;
      rgflReturn[2] = local_9c;
      return;
    }
  }
  *rgflReturn = gGlobalVariables.v_forward[0];
  rgflReturn[1] = gGlobalVariables.v_forward[1];
  rgflReturn[2] = gGlobalVariables.v_forward[2];
  return;
}


// PF_ambientsound_I  @ 0008c040
void PF_ambientsound_I(edict_t_conflict *entity,float *pos,char *samp,float vol,float attenuation,
                      int fFlags,int pitch)

{
  char *s1;
  int iVar1;
  char **ppcVar2;
  sizebuf_t *sb;
  int c;
  uint local_28;
  
                    /* Unresolved local var: char * * check@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int soundnum@[???]
                       Unresolved local var: int ent@[???]
                       Unresolved local var: sizebuf_t * pout@[???] */
  local_28 = fFlags;
  if (*samp == '!') {
    c = Q_atoi(samp + 1);
    local_28 = fFlags | 0x10;
    if (c < 0x600) {
LAB_0008c0c8:
      sb = &sv.signon;
      iVar1 = NUM_FOR_EDICT((edict_t *)entity);
      if ((local_28 & 0x100) == 0) {
        sb = &sv.datagram;
      }
      MSG_WriteByte(sb,0x1d);
      MSG_WriteCoord(sb,*pos);
      MSG_WriteCoord(sb,pos[1]);
      MSG_WriteCoord(sb,pos[2]);
      MSG_WriteShort(sb,c);
      MSG_WriteByte(sb,(int)(vol * 255.0));
      MSG_WriteByte(sb,(int)(attenuation * 64.0));
      MSG_WriteShort(sb,iVar1);
      MSG_WriteByte(sb,pitch);
      MSG_WriteByte(sb,local_28 & 0xff);
      return;
    }
    entity = (edict_t_conflict *)s_invalid_sentence_number___s_000e62c7;
  }
  else {
    if (sv.sound_precache[0] != (char *)0x0) {
      c = 0;
      ppcVar2 = sv.sound_precache;
      s1 = sv.sound_precache[0];
      do {
        iVar1 = Q_stricmp(s1,samp);
        if (iVar1 == 0) {
          if (*ppcVar2 != (char *)0x0) goto LAB_0008c0c8;
          break;
        }
        ppcVar2 = ppcVar2 + 1;
        c = c + 1;
        s1 = *ppcVar2;
      } while (s1 != (char *)0x0);
    }
    entity = (edict_t_conflict *)s_no_precache___s_000e628c;
  }
  Con_Printf((char *)entity);
  return;
}


// PF_bprint  @ 0008bd90
void PF_bprint(char *s)

{
  SV_BroadcastPrintf("%s",s);
  return;
}


// PF_changelevel_I  @ 00090530
void PF_changelevel_I(char *s1,char *s2)

{
  char *text;
  
  if (svs.spawncount != PF_changelevel_I::last_spawncount) {
    PF_changelevel_I::last_spawncount = svs.spawncount;
    SV_SkipUpdates();
    if (s2 == (char *)0x0) {
      text = va("changelevel %s\n",s1);
    }
    else {
      text = va("changelevel2 %s %s\n",s1,s2);
    }
    Cbuf_AddText(text);
    return;
  }
  return;
}


// PF_changepitch_I  @ 0008f4d0
void PF_changepitch_I(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
                    /* Unresolved local var: float ideal@[???]
                       Unresolved local var: float current@[???]
                       Unresolved local var: float move@[???]
                       Unresolved local var: float speed@[???] */
  fVar3 = anglemod((ent->v).angles[0]);
  fVar4 = (ent->v).idealpitch;
  fVar1 = (ent->v).pitch_speed;
  if (fVar3 != fVar4) {
    fVar2 = fVar4 - fVar3;
    if (fVar4 <= fVar3) {
      if (fVar2 <= -180.0) {
        fVar2 = fVar2 + 360.0;
      }
    }
    else if (180.0 <= fVar2) {
      fVar2 = fVar2 - 360.0;
    }
    if (fVar2 <= 0.0) {
      fVar4 = -fVar1;
      if (-fVar1 <= fVar2) {
        fVar4 = fVar2;
      }
    }
    else {
      fVar4 = fVar2;
      if (fVar1 < fVar2) {
        fVar4 = fVar1;
      }
    }
    fVar4 = anglemod(fVar3 + fVar4);
    (ent->v).angles[0] = fVar4;
    return;
  }
  return;
}


// PF_changeyaw_I  @ 0008f3f0
void PF_changeyaw_I(edict_t_conflict *ent)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
                    /* Unresolved local var: float ideal@[???]
                       Unresolved local var: float current@[???]
                       Unresolved local var: float move@[???]
                       Unresolved local var: float speed@[???] */
  fVar3 = anglemod((ent->v).angles[1]);
  fVar4 = (ent->v).ideal_yaw;
  fVar1 = (ent->v).yaw_speed;
  if (fVar3 != fVar4) {
    fVar2 = fVar4 - fVar3;
    if (fVar4 <= fVar3) {
      if (fVar2 <= -180.0) {
        fVar2 = fVar2 + 360.0;
      }
    }
    else if (180.0 <= fVar2) {
      fVar2 = fVar2 - 360.0;
    }
    if (fVar2 <= 0.0) {
      fVar4 = -fVar1;
      if (-fVar1 <= fVar2) {
        fVar4 = fVar2;
      }
    }
    else {
      fVar4 = fVar2;
      if (fVar1 < fVar2) {
        fVar4 = fVar1;
      }
    }
    fVar4 = anglemod(fVar3 + fVar4);
    (ent->v).angles[1] = fVar4;
    return;
  }
  return;
}


// PF_checkbottom_I  @ 0008efb0
int PF_checkbottom_I(edict_t_conflict *pEdict)

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
  trace_t tStack_6c;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
  fVar1 = (pEdict->v).origin[0];
  fVar4 = (pEdict->v).mins[0] + fVar1;
  g_groupmask = (pEdict->v).groupinfo;
  uVar3 = (pEdict->v).flags;
  fVar2 = (pEdict->v).origin[1];
  fVar5 = (pEdict->v).mins[1] + fVar2;
  fVar6 = (pEdict->v).origin[2] + (pEdict->v).mins[2];
  fVar1 = fVar1 + (pEdict->v).maxs[0];
  fVar2 = fVar2 + (pEdict->v).maxs[1];
  fStack_2c = fVar6 - 1.0;
  fStack_34 = fVar4;
  fStack_30 = fVar5;
  iVar8 = SV_PointContents(&fStack_34);
  if (iVar8 == -2) {
    g_groupmask = (pEdict->v).groupinfo;
    fStack_34 = fVar4;
    fStack_30 = fVar2;
    iVar8 = SV_PointContents(&fStack_34);
    if (iVar8 == -2) {
      g_groupmask = (pEdict->v).groupinfo;
      fStack_34 = fVar1;
      fStack_30 = fVar5;
      iVar8 = SV_PointContents(&fStack_34);
      if (iVar8 == -2) {
        g_groupmask = (pEdict->v).groupinfo;
        fStack_34 = fVar1;
        fStack_30 = fVar2;
        iVar8 = SV_PointContents(&fStack_34);
        if (iVar8 == -2) goto LAB_000ae5e4;
      }
    }
  }
  monsterClipBrush = (qboolean)((uVar3 & 0x800000) != 0);
  fStack_2c = fVar6 + sv_stepsize.value;
  c_no = c_no + 1;
  fStack_34 = (fVar4 + fVar1) * 0.5;
  fStack_30 = (fVar5 + fVar2) * 0.5;
  fStack_20 = fStack_2c - (sv_stepsize.value + sv_stepsize.value);
  fStack_28 = fStack_34;
  fStack_24 = fStack_30;
  SV_Move(&tStack_6c,&fStack_34,vec3_origin,vec3_origin,&fStack_28,1,pEdict,monsterClipBrush);
  vVar7 = tStack_6c.endpos[2];
  if (tStack_6c.fraction == 1.0) {
    return 0;
  }
  fStack_34 = fVar4;
  fStack_30 = fVar5;
  fStack_28 = fVar4;
  fStack_24 = fVar5;
  SV_Move(&tStack_6c,&fStack_34,vec3_origin,vec3_origin,&fStack_28,1,pEdict,monsterClipBrush);
  if (tStack_6c.fraction == 1.0) {
    return 0;
  }
  if (sv_stepsize.value < vVar7 - tStack_6c.endpos[2]) {
    return 0;
  }
  fStack_34 = fVar4;
  fStack_30 = fVar2;
  fStack_28 = fVar4;
  fStack_24 = fVar2;
  SV_Move(&tStack_6c,&fStack_34,vec3_origin,vec3_origin,&fStack_28,1,pEdict,monsterClipBrush);
  if (tStack_6c.fraction == 1.0) {
    return 0;
  }
  if (sv_stepsize.value < vVar7 - tStack_6c.endpos[2]) {
    return 0;
  }
  fStack_34 = fVar1;
  fStack_30 = fVar5;
  fStack_28 = fVar1;
  fStack_24 = fVar5;
  SV_Move(&tStack_6c,&fStack_34,vec3_origin,vec3_origin,&fStack_28,1,pEdict,monsterClipBrush);
  if (tStack_6c.fraction == 1.0) {
    return 0;
  }
  if (sv_stepsize.value < vVar7 - tStack_6c.endpos[2]) {
    return 0;
  }
  fStack_34 = fVar1;
  fStack_30 = fVar2;
  fStack_28 = fVar1;
  fStack_24 = fVar2;
  SV_Move(&tStack_6c,&fStack_34,vec3_origin,vec3_origin,&fStack_28,1,pEdict,monsterClipBrush);
  if (tStack_6c.fraction == 1.0) {
    return 0;
  }
  if (sv_stepsize.value < vVar7 - tStack_6c.endpos[2]) {
    return 0;
  }
LAB_000ae5e4:
  c_yes = c_yes + 1;
  return 1;
}


// PF_checkclient_I  @ 0008d140
edict_t_conflict * PF_checkclient_I(edict_t_conflict *pEdict)

{
  mleaf_t *pmVar1;
  int iVar2;
  edict_t_conflict *peVar3;
  edict_t_conflict *peVar4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: mleaf_t * leaf@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: vec3_t view@[???] */
  if (0.1 <= sv.time - sv.lastchecktime) {
    sv.lastcheck = PF_newcheckclient(sv.lastcheck);
    sv.lastchecktime = sv.time;
  }
  peVar4 = sv.edicts + sv.lastcheck;
  peVar3 = sv.edicts;
  if ((peVar4->free == 0) && (peVar4->pvPrivateData != (void *)0x0)) {
    local_18 = (pEdict->v).origin[0] + (pEdict->v).view_ofs[0];
    local_14 = (pEdict->v).origin[1] + (pEdict->v).view_ofs[1];
    local_10 = (pEdict->v).origin[2] + (pEdict->v).view_ofs[2];
    pmVar1 = Mod_PointInLeaf(&local_18,sv.worldmodel);
    iVar2 = ((int)pmVar1 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
    if ((iVar2 < 0) || (((int)(uint)checkpvs[iVar2 >> 3] >> ((byte)iVar2 & 7) & 1U) == 0)) {
      c_notvis = c_notvis + 1;
      return sv.edicts;
    }
    c_invis = c_invis + 1;
    peVar3 = peVar4;
  }
  return peVar3;
}


// PF_crosshairangle_I  @ 0008f650
void PF_crosshairangle_I(edict_t *clientent,float pitch,float yaw)

{
  sizebuf_t *sb;
  int iVar1;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int clientnum@[???] */
  local_14 = pitch;
  local_10 = yaw;
  iVar1 = NUM_FOR_EDICT(clientent);
  if (((0 < iVar1) && (iVar1 <= svs.maxclients)) && (svs.clients[iVar1 + -1].fakeclient == false)) {
    if (180.0 < pitch) {
      local_14 = pitch - 360.0;
    }
    if (local_14 < -180.0) {
      local_14 = local_14 + 360.0;
    }
    if (180.0 < yaw) {
      local_10 = yaw - 360.0;
    }
    if (local_10 < -180.0) {
      local_10 = local_10 + 360.0;
    }
    sb = &svs.clients[iVar1 + -1].netchan.message;
    MSG_WriteByte(sb,0x2f);
    MSG_WriteChar(sb,(int)(local_14 * 5.0));
    MSG_WriteChar(sb,(int)(local_10 * 5.0));
    return;
  }
  return;
}


// PF_droptofloor_I  @ 0008ed90
int PF_droptofloor_I(edict_t_conflict *ent)

{
  int *piVar1;
  int iVar2;
  trace_t local_5c;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  local_18 = (ent->v).origin[0];
  local_10 = (ent->v).origin[2] - 256.0;
  local_14 = (ent->v).origin[1];
  SV_Move(&local_5c,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_18,0,ent,
          (uint)(((ent->v).flags & 0x800000) != 0));
  iVar2 = -1;
  if ((local_5c.allsolid == false) && (iVar2 = 0, local_5c.fraction != 1.0)) {
    (ent->v).origin[0] = local_5c.endpos[0];
    (ent->v).origin[1] = local_5c.endpos[1];
    (ent->v).origin[2] = local_5c.endpos[2];
    SV_LinkEdict(ent,false);
    piVar1 = &(ent->v).flags;
    *piVar1 = *piVar1 | 0x200;
    (ent->v).groundentity = local_5c.ent;
    return 1;
  }
  return iVar2;
}


// PF_lightstyle_I  @ 0008eef0
void PF_lightstyle_I(int style,char *val)

{
  sizebuf_t *sb;
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int j@[???] */
  sv.lightstyles[style] = val;
  if (sv.state == ss_active) {
    if (0 < svs.maxclients) {
      iVar3 = 0;
      iVar1 = svs.maxclients;
      pcVar2 = svs.clients;
      do {
        if (((pcVar2->active != false) || (pcVar2->spawned != false)) &&
           (pcVar2->fakeclient == false)) {
          sb = &(pcVar2->netchan).message;
          MSG_WriteChar(sb,0xc);
          MSG_WriteChar(sb,style);
          MSG_WriteString(sb,val);
          iVar1 = svs.maxclients;
        }
        iVar3 = iVar3 + 1;
        pcVar2 = pcVar2 + 1;
      } while (iVar3 < iVar1);
    }
  }
  return;
}


// PF_localcmd_I  @ 0008d6c0
void PF_localcmd_I(char *str)

{
  int iVar1;
  
                    /* Unresolved local var: int len@[???] */
  iVar1 = Q_strlen(str);
  if ((iVar1 != 0) && ((str[iVar1 + -1] == ';' || (str[iVar1 + -1] == '\n')))) {
    Cbuf_AddText(str);
    return;
  }
  Con_Printf("Error, bad server command %s\n",str);
  return;
}


// PF_localexec_I  @ 0008d710
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PF_localexec_I(void)

{
  Cbuf_ExecuteCommandsFromBuffer(&cmd_text,true,-1);
  Cbuf_ExecuteCommandsFromBuffer(&filteredcmd_text,false,1);
  return;
}


// PF_makestatic_I  @ 00090230
void PF_makestatic_I(edict_t_conflict *ent)

{
  int c;
  
                    /* Unresolved local var: int i@[???] */
  MSG_WriteByte(&sv.signon,0x14);
  c = SV_ModelIndex(pr_strings + (ent->v).model);
  MSG_WriteShort(&sv.signon,c);
  MSG_WriteByte(&sv.signon,(ent->v).sequence);
  MSG_WriteByte(&sv.signon,(int)(ent->v).frame);
  MSG_WriteWord(&sv.signon,(ent->v).colormap);
  MSG_WriteByte(&sv.signon,(ent->v).skin);
  MSG_WriteCoord(&sv.signon,(ent->v).origin[0]);
  MSG_WriteAngle(&sv.signon,(ent->v).angles[0]);
  MSG_WriteCoord(&sv.signon,(ent->v).origin[1]);
  MSG_WriteAngle(&sv.signon,(ent->v).angles[1]);
  MSG_WriteCoord(&sv.signon,(ent->v).origin[2]);
  MSG_WriteAngle(&sv.signon,(ent->v).angles[2]);
  MSG_WriteByte(&sv.signon,(ent->v).rendermode);
  if ((ent->v).rendermode != 0) {
    MSG_WriteByte(&sv.signon,(int)(ent->v).renderamt);
    MSG_WriteByte(&sv.signon,(int)(ent->v).rendercolor[0]);
    MSG_WriteByte(&sv.signon,(int)(ent->v).rendercolor[1]);
    MSG_WriteByte(&sv.signon,(int)(ent->v).rendercolor[2]);
    MSG_WriteByte(&sv.signon,(ent->v).renderfx);
  }
  ED_Free(ent);
  return;
}


// PF_makevectors_I  @ 0008ba60
void PF_makevectors_I(float *rgflVector)

{
  AngleVectors(rgflVector,gGlobalVariables.v_forward,gGlobalVariables.v_right,gGlobalVariables.v_up)
  ;
  return;
}


// PF_modelindex  @ 0008bd30
int PF_modelindex(char *pstr)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((pstr != (char *)0x0) && (*pstr != '\0')) {
    do {
      if (sv.model_precache[iVar2] == (char *)0x0) break;
      iVar1 = Q_strcasecmp(sv.model_precache[iVar2],pstr);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x200);
    Sys_Error("SV_ModelIndex: model %s not precached",pstr);
  }
  return iVar2;
}


// PF_newcheckclient  @ 0008d030
int PF_newcheckclient(int check)

{
  edict_t_conflict *peVar1;
  mleaf_t *leaf;
  uchar *src;
  int iVar2;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar * pvs@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: mleaf_t * leaf@[???]
                       Unresolved local var: vec3_t org@[???] */
  if (check < 1) {
    check = 1;
  }
  if (check == svs.maxclients || check < svs.maxclients) {
    if (check == svs.maxclients) {
      iVar2 = 1;
    }
    else {
      iVar2 = check + 1;
    }
  }
  else {
    iVar2 = 1;
    check = svs.maxclients;
  }
  if (iVar2 == svs.maxclients + 1) goto LAB_0008d08a;
  while (peVar1 = sv.edicts + iVar2, iVar2 != check) {
    while( true ) {
      if (((peVar1->free == 0) && (peVar1->pvPrivateData != (void *)0x0)) &&
         (((peVar1->v).flags & 0x80) == 0)) goto LAB_0008d0a0;
      iVar2 = iVar2 + 1;
      if (iVar2 != svs.maxclients + 1) break;
LAB_0008d08a:
      iVar2 = 1;
      peVar1 = sv.edicts + 1;
      if (check == 1) goto LAB_0008d0a0;
    }
  }
LAB_0008d0a0:
  local_18 = (peVar1->v).origin[0] + (peVar1->v).view_ofs[0];
  local_14 = (peVar1->v).origin[1] + (peVar1->v).view_ofs[1];
  local_10 = (peVar1->v).origin[2] + (peVar1->v).view_ofs[2];
  leaf = Mod_PointInLeaf(&local_18,sv.worldmodel);
  src = Mod_LeafPVS(leaf,sv.worldmodel);
  Q_memcpy(checkpvs,src,(sv.worldmodel)->numleafs + 7 >> 3);
  return iVar2;
}


// PF_particle_I  @ 0008c020
void PF_particle_I(float *org,float *dir,float color,float count)

{
  SV_StartParticle(org,dir,(int)color,(int)count);
  return;
}


// PF_pointcontents_I  @ 0008efc0
int PF_pointcontents_I(float *rgflVector)

{
  int iVar1;
  int iVar2;
  
  iVar1 = SV_HullPointContents((sv.worldmodel)->hulls,0,rgflVector);
  if (iVar1 + 0xeU < 6) {
    iVar1 = -3;
  }
  else if (iVar1 == -2) {
    return -2;
  }
  iVar2 = SV_LinkContents(sv_areanodes,rgflVector);
  if (iVar2 == -1) {
    iVar2 = iVar1;
  }
  return iVar2;
}


// PF_precache_generic_I  @ 0008e940
int PF_precache_generic_I(char *s)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (s == (char *)0x0) {
    Host_Error("PF_precache_generic_I: NULL pointer");
  }
  else if (*s < '!') {
    Con_Printf("PF_precache_generic_I: Bad string \'%s\'",s);
  }
  else {
    iVar2 = 0;
    if (sv.state != ss_loading) {
      do {
        while (sv.generic_precache[iVar2] != (char *)0x0) {
          iVar1 = Q_strcmp(sv.generic_precache[iVar2],s);
          if (iVar1 == 0) {
            return iVar2;
          }
          iVar2 = iVar2 + 1;
          if (iVar2 == 0x200) goto LAB_0008e99d;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x200);
LAB_0008e99d:
      Host_Error("PF_precache_generic_I: \'%s\' Precache can only be done in spawn functions",s);
    }
    iVar2 = 0;
    do {
      if (sv.generic_precache[iVar2] == (char *)0x0) {
        sv.generic_precache[iVar2] = s;
        return iVar2;
      }
      iVar1 = Q_strcasecmp(sv.generic_precache[iVar2],s);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x200);
    Host_Error("PF_precache_generic_I: Generic item \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
               ,s,0x200);
  }
  return 0;
}


// PF_precache_model_I  @ 0008e810
int PF_precache_model_I(char *s)

{
  char cVar1;
  int iVar2;
  model_t *pmVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iOptional@[???] */
  if (s == (char *)0x0) {
    Host_Error("PF_precache_model_I: NULL pointer");
  }
  else {
    cVar1 = *s;
    if (cVar1 < '!') {
      Host_Error("PF_precache_model_I: Bad string \'%s\'",s);
    }
    else {
      if (cVar1 == '!') {
        s = s + 1;
      }
      if (sv.state != ss_loading) {
        iVar4 = 0;
        do {
          while (sv.model_precache[iVar4] == (char *)0x0) {
            iVar4 = iVar4 + 1;
            if (iVar4 == 0x200) goto LAB_0008e881;
          }
          iVar2 = Q_stricmp(sv.model_precache[iVar4],s);
          if (iVar2 == 0) {
            return iVar4;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != 0x200);
LAB_0008e881:
        Host_Error("PF_precache_model_I: \'%s\' Precache can only be done in spawn functions",s);
      }
      iVar4 = 0;
      do {
        if (sv.model_precache[iVar4] == (char *)0x0) {
          sv.model_precache[iVar4] = s;
          pmVar3 = Mod_ForName(s,true,true);
          sv.models[iVar4] = pmVar3;
          if (cVar1 == '!') {
            return iVar4;
          }
          sv.model_precache_flags[iVar4] = sv.model_precache_flags[iVar4] | 1;
          return iVar4;
        }
        iVar2 = Q_stricmp(sv.model_precache[iVar4],s);
        if (iVar2 == 0) {
          return iVar4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x200);
      Host_Error("PF_precache_model_I: Model \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
                 ,s,0x200);
    }
  }
  return 0;
}


// PF_precache_sound_I  @ 0008dd00
int PF_precache_sound_I(char *s)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (s == (char *)0x0) {
    Host_Error("PF_precache_sound_I: NULL pointer");
  }
  else if (*s < '!') {
    Host_Error("PF_precache_sound_I: Bad string \'%s\'",s);
  }
  else if (*s == '!') {
    Host_Error("PF_precache_sound_I: \'%s\' do not precache sentence names!",s);
  }
  else {
    if (sv.state != ss_loading) {
      iVar2 = 0;
      do {
        while (sv.sound_precache[iVar2] == (char *)0x0) {
          iVar2 = iVar2 + 1;
          if (iVar2 == 0x200) goto LAB_0008dd65;
        }
        iVar1 = Q_stricmp(sv.sound_precache[iVar2],s);
        if (iVar1 == 0) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x200);
LAB_0008dd65:
      Host_Error("PF_precache_sound_I: \'%s\' Precache can only be done in spawn functions",s);
    }
    iVar2 = 0;
    sv.sound_precache_hashedlookup_built = false;
    do {
      if (sv.sound_precache[iVar2] == (char *)0x0) {
        sv.sound_precache[iVar2] = s;
        return iVar2;
      }
      iVar1 = Q_stricmp(sv.sound_precache[iVar2],s);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x200);
    Host_Error("PF_precache_sound_I: Sound \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
               ,s,0x200);
  }
  return 0;
}


// PF_setmodel_I  @ 0008bc50
void PF_setmodel_I(edict_t_conflict *e,char *m)

{
  model_s *pmVar1;
  char *pcVar2;
  int iVar3;
  char **ppcVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * * check@[???]
                       Unresolved local var: model_t * mod@[???] */
  if (sv.model_precache[0] == (char *)0x0) {
    iVar5 = 0;
  }
  else {
    ppcVar4 = sv.model_precache;
    iVar5 = 0;
    pcVar2 = sv.model_precache[0];
    do {
      iVar3 = Q_stricmp(pcVar2,m);
      if (iVar3 == 0) {
        if (*ppcVar4 != (char *)0x0) goto LAB_0008bc9c;
        break;
      }
      ppcVar4 = ppcVar4 + 1;
      iVar5 = iVar5 + 1;
      pcVar2 = *ppcVar4;
    } while (pcVar2 != (char *)0x0);
  }
  Host_Error("no precache: %s\n",m);
LAB_0008bc9c:
  pcVar2 = pr_strings;
  (e->v).modelindex = iVar5;
  (e->v).model = (int)m - (int)pcVar2;
  pmVar1 = sv.models[iVar5];
  if (pmVar1 != (model_s *)0x0) {
    SetMinMaxSize(e,pmVar1->mins,pmVar1->maxs,true);
    return;
  }
  SetMinMaxSize(e,vec3_origin,vec3_origin,true);
  return;
}


// PF_setorigin_I  @ 0008bab0
void PF_setorigin_I(edict_t_conflict *e,float *org)

{
  if (e != (edict_t_conflict *)0x0) {
    (e->v).origin[0] = *org;
    (e->v).origin[1] = org[1];
    (e->v).origin[2] = org[2];
    SV_LinkEdict(e,false);
    return;
  }
  return;
}


// PF_setsize_I  @ 0008bc20
void PF_setsize_I(edict_t_conflict *e,float *rgflMin,float *rgflMax)

{
  SetMinMaxSize(e,rgflMin,rgflMax,false);
  return;
}


// PF_setspawnparms_I  @ 000904f0
void PF_setspawnparms_I(edict_t_conflict *ent)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???] */
  iVar1 = NUM_FOR_EDICT((edict_t *)ent);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    return;
  }
  Host_Error("Entity is not a client");
  return;
}


// PF_setview_I  @ 0008f5b0
void PF_setview_I(edict_t *clientent,edict_t *viewent)

{
  client_s *pcVar1;
  int iVar2;
  sizebuf_t *sb;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int clientnum@[???] */
  iVar2 = NUM_FOR_EDICT(clientent);
  if ((iVar2 < 1) || (svs.maxclients < iVar2)) {
    Host_Error("PF_setview_I: not a client");
  }
  pcVar1 = svs.clients;
  iVar2 = iVar2 + -1;
  if (svs.clients[iVar2].fakeclient != false) {
    return;
  }
  svs.clients[iVar2].pViewEntity = viewent;
  sb = &pcVar1[iVar2].netchan.message;
  MSG_WriteByte(sb,5);
  iVar2 = NUM_FOR_EDICT(viewent);
  MSG_WriteShort(sb,iVar2);
  return;
}


// PF_sound_I  @ 0008c200
void PF_sound_I(edict_t_conflict *entity,int channel,char *sample,float volume,float attenuation,
               int fFlags,int pitch)

{
  if ((volume < 0.0) || (255.0 < volume)) {
    Sys_Error("EMIT_SOUND: volume = %i",(double)volume);
  }
  if ((attenuation < 0.0) || (4.0 < attenuation)) {
    Sys_Error("EMIT_SOUND: attenuation = %f",(double)attenuation);
  }
  if (7 < (uint)channel) {
    Sys_Error("EMIT_SOUND: channel = %i",channel);
  }
  if (0xff < (uint)pitch) {
    Sys_Error("EMIT_SOUND: pitch = %i",pitch);
  }
  SV_StartSound(0,entity,channel,sample,(int)(volume * 255.0),attenuation,fFlags,pitch);
  return;
}


// PF_sprint  @ 0008bdb0
void PF_sprint(char *s,int entnum)

{
  sizebuf_t *sb;
  
                    /* Unresolved local var: client_t * client@[???] */
  if ((0 < entnum) && (entnum <= svs.maxclients)) {
    if (svs.clients[entnum + -1].fakeclient != false) {
      return;
    }
    sb = &svs.clients[entnum + -1].netchan.message;
    MSG_WriteChar(sb,8);
    MSG_WriteString(sb,s);
    return;
  }
  Con_Printf("tried to sprint to a non-client\n");
  return;
}


// PF_stuffcmd_I  @ 0008d5d0
void PF_stuffcmd_I(edict_t_conflict *pEdict,char *szFmt,...)

{
  client_t *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int entnum@[???]
                       Unresolved local var: client_t * old@[???]
                       Unresolved local var: va_list argptr@[???] */
  iVar2 = NUM_FOR_EDICT((edict_t *)pEdict);
  vsnprintf(PF_stuffcmd_I::szOut,0x400,szFmt,&stack0x0000000c);
  PF_stuffcmd_I::szOut[0x3ff] = '\0';
  if ((iVar2 < 1) || (svs.maxclients < iVar2)) {
    Con_Printf("\n!!!\n\nStuffCmd:  Some entity tried to stuff \'%s\' to console buffer of entity %i when maxclients was set to %i, ignoring\n\n"
               ,PF_stuffcmd_I::szOut,iVar2,svs.maxclients);
  }
  else {
                    /* Unresolved local var: int len@[???] */
    iVar3 = Q_strlen(PF_stuffcmd_I::szOut);
    pcVar1 = host_client;
    if ((iVar3 == 0) || (((&DAT_0011f8df)[iVar3] != ';' && ((&DAT_0011f8df)[iVar3] != '\n')))) {
      Con_Printf("Tried to stuff bad command %s\n",PF_stuffcmd_I::szOut);
      return;
    }
    host_client = svs.clients + iVar2 + -1;
    Host_ClientCommands("%s",PF_stuffcmd_I::szOut);
    host_client = pcVar1;
  }
  return;
}


// PF_traceline_DLL  @ 0008cd40
void PF_traceline_DLL(float *v1,float *v2,int fNoMonsters,edict_t_conflict *pentToSkip,
                     TraceResult *ptr)

{
  uint uVar1;
  trace_t local_8c;
  trace_t tStack_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  if (pentToSkip == (edict_t_conflict *)0x0) {
    pentToSkip = sv.edicts;
  }
  SV_Move(&local_8c,v1,vec3_origin,vec3_origin,v2,fNoMonsters,pentToSkip,false);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)tStack_44.endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_8c.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  gGlobalVariables.trace_flags = 0;
  SV_SetGlobalTrace(&tStack_44);
  ptr->fAllSolid = (int)gGlobalVariables.trace_allsolid;
  ptr->fStartSolid = (int)gGlobalVariables.trace_startsolid;
  ptr->fInOpen = (int)gGlobalVariables.trace_inopen;
  ptr->fInWater = (int)gGlobalVariables.trace_inwater;
  ptr->flFraction = gGlobalVariables.trace_fraction;
  ptr->flPlaneDist = gGlobalVariables.trace_plane_dist;
  ptr->pHit = gGlobalVariables.trace_ent;
  ptr->vecEndPos[0] = gGlobalVariables.trace_endpos[0];
  ptr->vecEndPos[1] = gGlobalVariables.trace_endpos[1];
  ptr->vecEndPos[2] = gGlobalVariables.trace_endpos[2];
  ptr->vecPlaneNormal[0] = gGlobalVariables.trace_plane_normal[0];
  ptr->vecPlaneNormal[1] = gGlobalVariables.trace_plane_normal[1];
  ptr->vecPlaneNormal[2] = gGlobalVariables.trace_plane_normal[2];
  ptr->iHitgroup = gGlobalVariables.trace_hitgroup;
  return;
}


// PF_traceline_Shared  @ 0008ccb0
void PF_traceline_Shared(float *v1,float *v2,int nomonsters,edict_t_conflict *ent)

{
  uint uVar1;
  trace_t local_8c;
  trace_t tStack_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  SV_Move(&local_8c,v1,vec3_origin,vec3_origin,v2,nomonsters,ent,false);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)tStack_44.endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_8c.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  gGlobalVariables.trace_flags = 0;
  SV_SetGlobalTrace(&tStack_44);
  return;
}


// PF_vectoangles_I  @ 0008c010
void PF_vectoangles_I(float *rgflVectorIn,float *rgflVectorOut)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
  if ((rgflVectorIn[1] == 0.0) && (*rgflVectorIn == 0.0)) {
    if (rgflVectorIn[2] <= 0.0) {
      fVar1 = 0.0;
      fVar2 = 270.0;
    }
    else {
      fVar1 = 0.0;
      fVar2 = 90.0;
    }
  }
  else {
    dVar4 = atan2((double)rgflVectorIn[1],(double)*rgflVectorIn);
    fVar1 = ((float)dVar4 * 180.0) / 3.1415927;
    if (fVar1 < 0.0) {
      fVar1 = fVar1 + 360.0;
    }
    fVar2 = rgflVectorIn[1] * rgflVectorIn[1] + *rgflVectorIn * *rgflVectorIn;
    fVar3 = SQRT(fVar2);
    if (NAN(fVar3)) {
      fVar3 = sqrtf(fVar2);
    }
    dVar4 = atan2((double)rgflVectorIn[2],(double)fVar3);
    fVar2 = ((float)dVar4 * 180.0) / 3.1415927;
    if (fVar2 < 0.0) {
      fVar2 = fVar2 + 360.0;
    }
  }
  *rgflVectorOut = fVar2;
  rgflVectorOut[1] = fVar1;
  rgflVectorOut[2] = 0.0;
  return;
}


// PF_vectoyaw_I  @ 0008bf70
float PF_vectoyaw_I(float *rgflVector)

{
  float fVar1;
  double dVar2;
  
                    /* Unresolved local var: float yaw@[???] */
  fVar1 = 0.0;
  if ((rgflVector[1] != 0.0) || (*rgflVector != 0.0)) {
    dVar2 = atan2((double)rgflVector[1],(double)*rgflVector);
    fVar1 = (float)(int)((dVar2 * 180.0) / 3.141592653589793);
    if (fVar1 < 0.0) {
      fVar1 = fVar1 + 360.0;
    }
  }
  return fVar1;
}


// PF_walkmove_I  @ 0008ecb0
int PF_walkmove_I(edict_t_conflict *ent,float yaw,float dist,int iMode)

{
  qboolean qVar1;
  double local_2c;
  double local_24;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: int returnValue@[???] */
  qVar1 = false;
  if (((ent->v).flags & 0x203U) != 0) {
    sincos((double)((yaw * 3.1415927 + yaw * 3.1415927) / 360.0),&local_24,&local_2c);
    local_14 = 0;
    local_1c = (float)local_2c * dist;
    local_18 = dist * (float)local_24;
    if (iMode == 1) {
      qVar1 = SV_movetest(ent,&local_1c,true);
    }
    else {
      if (iMode == 2) {
        qVar1 = SV_movestep(ent,&local_1c,false);
        return qVar1;
      }
      qVar1 = SV_movestep(ent,&local_1c,true);
    }
  }
  return qVar1;
}


