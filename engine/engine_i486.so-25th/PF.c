// PF_BuildSoundMsg_I  @ 00073c20
void PF_BuildSoundMsg_I(edict_t *entity,int channel,char *sample,float volume,float attenuation,
                       int fFlags,int pitch,int msg_dest,int msg_type,float *pOrigin,edict_t *ed)

{
  if ((msg_dest == 1 || msg_dest == 8) && (ed == (edict_t *)0x0)) {
    Sys_Error("MSG_ONE or MSG_ONE_UNRELIABLE with no target entity\n");
  }
  if ((msg_dest != 8 && msg_dest != 1) && (ed != (edict_t *)0x0)) {
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
  gMsgBuffer.cursize = 0;
  gMsgBuffer.flags = 1;
  SV_BuildSoundMsg(entity,channel,sample,(int)volume,attenuation,fFlags,pitch,pOrigin,&gMsgBuffer);
  PF_MessageEnd_I();
  return;
}


// PF_CanSkipPlayer  @ 00073fa0
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


// PF_CreateFakeClient_I  @ 000727a0
edict_t * PF_CreateFakeClient_I(char *netname)

{
  char *pcVar1;
  edict_t *peVar2;
  int iVar3;
  client_s *unaff_ESI;
  uint64 steamid;
  
                    /* Unresolved local var: client_t * fakeclient@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int g_userid@[???] */
  if (svs.maxclients < 1) {
    if (svs.maxclients != 0) {
      iVar3 = 0;
LAB_000727f0:
      peVar2 = EDICT_NUM(iVar3 + 1);
      if (unaff_ESI->frames != (client_frame_t *)0x0) {
        SV_ClearFrames(&unaff_ESI->frames);
      }
      Q_memset(unaff_ESI,0,0x6668);
      (unaff_ESI->resourcesneeded).pPrev = &unaff_ESI->resourcesneeded;
      (unaff_ESI->resourcesneeded).pNext = &unaff_ESI->resourcesneeded;
      (unaff_ESI->resourcesonhand).pPrev = &unaff_ESI->resourcesonhand;
      (unaff_ESI->resourcesonhand).pNext = &unaff_ESI->resourcesonhand;
      Q_strncpy(unaff_ESI->name,netname,0x20);
      unaff_ESI->active = true;
      unaff_ESI->fakeclient = true;
      unaff_ESI->edict = peVar2;
      unaff_ESI->name[0x1f] = '\0';
      unaff_ESI->spawned = true;
      unaff_ESI->userid = g_userid;
      pcVar1 = pr_strings;
      g_userid = g_userid + 1;
      unaff_ESI->fully_connected = true;
      unaff_ESI->connected = true;
      unaff_ESI->uploading = false;
      (peVar2->v).flags = 0x2008;
      (peVar2->v).netname = (int)unaff_ESI->name - (int)pcVar1;
      pcVar1 = unaff_ESI->userinfo;
      (peVar2->v).pContainingEntity = peVar2;
      Info_SetValueForKey(pcVar1,"name",netname,0x100);
      Info_SetValueForKey(pcVar1,"model","gordon",0x100);
      Info_SetValueForKey(pcVar1,"topcolor","1",0x100);
      Info_SetValueForKey(pcVar1,"bottomcolor","1",0x100);
      unaff_ESI->sendinfo = true;
      SV_ExtractFromUserinfo(unaff_ESI);
      steamid = ISteamGameServer_CreateUnauthenticatedUserConnection();
      (unaff_ESI->network_userid).idtype = 1;
      (unaff_ESI->network_userid).m_SteamID = steamid;
      ISteamGameServer_BUpdateUserData(steamid,netname,0);
      return peVar2;
    }
  }
  else {
    iVar3 = 0;
    unaff_ESI = svs.clients;
    do {
      if (((unaff_ESI->active == false) && (unaff_ESI->spawned == false)) &&
         (unaff_ESI->connected == false)) goto LAB_000727f0;
      iVar3 = iVar3 + 1;
      unaff_ESI = unaff_ESI + 1;
    } while (svs.maxclients != iVar3);
  }
  return (edict_t *)0x0;
}


// PF_CreateInstancedBaseline  @ 00074020
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
      uVar1 = *(undefined4 *)((int)baseline->origin + (uVar5 - 0x10));
      *(undefined4 *)(peVar2->baseline[iVar4].controller + (uVar5 - 100)) =
           *(undefined4 *)((int)baseline->origin + (uVar5 - 0xc));
      *(undefined4 *)(peVar2->baseline[iVar4].controller + (uVar5 - 0x68)) = uVar1;
      uVar3 = uVar5 + 8;
    } while (uVar5 + 8 < 0x150);
    *(undefined4 *)(peVar2->baseline[iVar4].controller + (uVar5 - 0x60)) =
         *(undefined4 *)((int)baseline->origin + (uVar5 - 8));
    (sv.instance_baselines)->number = (sv.instance_baselines)->number + 1;
    iVar4 = (sv.instance_baselines)->number;
  }
  return iVar4;
}


// PF_Cvar_DirectSet  @ 000740b0
void PF_Cvar_DirectSet(cvar_s *var,char *value)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  qboolean qVar5;
  size_t sVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  float fVar8;
  char acStack_420 [1024];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((var == (cvar_s *)0x0) || (value == (char *)0x0)) goto LAB_00042ad3;
  uVar4 = var->flags;
  if ((uVar4 & 0x2000) != 0) {
    if ((((*value == '/') || (pcVar2 = Q_strstr(value,":"), pcVar2 != (char *)0x0)) ||
        (pcVar2 = Q_strstr(value,".."), pcVar2 != (char *)0x0)) ||
       (pcVar2 = Q_strstr(value,"\\"), pcVar2 != (char *)0x0)) {
      Con_Printf("Refusing to set %s to %s (invalid path)\n",var->name,value);
      goto LAB_00042ad3;
    }
    uVar4 = var->flags;
  }
  if ((uVar4 & 0x80) == 0) {
    if ((uVar4 & 0x200) == 0) {
      if ((uVar4 & 0x1000) == 0) goto LAB_00042b7c;
      Q_strncpy_s(acStack_420,value,0x400);
    }
    else {
      Q_strncpy_s(acStack_420,value,0x400);
LAB_00042b6a:
      value = acStack_420;
      Q_StripUnprintableAndSpace(value);
      if ((var->flags & 0x1000) == 0) goto LAB_00042b7c;
    }
LAB_00042cb2:
    value = acStack_420;
    sVar6 = strcspn(value,";\n");
    acStack_420[sVar6] = '\0';
  }
  else {
    acStack_420[0] = '\0';
    qVar5 = Q_UnicodeValidate(value);
    if (qVar5 == 0) {
      pcVar2 = acStack_420;
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
      pcVar2 = acStack_420;
      Q_strncpy_s(pcVar2,value,0x400);
    }
    value = acStack_420;
    qVar5 = Q_UnicodeValidate(pcVar2);
    if (qVar5 == 0) {
      Q_UnicodeRepair(pcVar2);
    }
    iVar3 = Q_strlen(value);
    if (iVar3 == 0) {
      Q_strcpy(value,"empty");
    }
    if ((var->flags & 0x200U) != 0) goto LAB_00042b6a;
    if ((var->flags & 0x1000U) != 0) goto LAB_00042cb2;
  }
LAB_00042b7c:
  iVar3 = Q_strcmp(var->string,value);
  uVar4 = var->flags;
  if (((uVar4 & 2) != 0) && (cls.state == ca_dedicated)) {
    pcVar2 = var->name;
    pcVar7 = Info_Serverinfo();
    Info_SetValueForKey(pcVar7,pcVar2,value,0x200);
    pcVar2 = Info_Serverinfo();
    SV_BroadcastCommand("fullserverinfo \"%s\"\n",pcVar2);
    uVar4 = var->flags;
  }
  if (((uVar4 & 4) != 0) && (iVar3 != 0)) {
    if ((uVar4 & 0x100) == 0) {
      if ((uVar4 & 0x20) == 0) {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,value);
        pcVar2 = value;
      }
      else {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,"***PROTECTED***");
        pcVar2 = "***PROTECTED***";
      }
      SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",var->name,pcVar2);
      uVar4 = var->flags;
    }
    pcVar2 = value;
    if ((uVar4 & 0x20) != 0) {
      iVar3 = Q_strlen(value);
      if (0 < iVar3) {
        iVar3 = Q_stricmp(value,"none");
        pcVar2 = "1";
        if (iVar3 != 0) goto LAB_00042bfd;
      }
      pcVar2 = "0";
    }
LAB_00042bfd:
    Steam_SetCVar(var->name,pcVar2);
  }
  Z_Free(var->string);
  iVar3 = Q_strlen(value);
  pcVar2 = Z_Malloc(iVar3 + 1);
  var->string = pcVar2;
  Q_strcpy(pcVar2,value);
  fVar8 = Q_atof(var->string);
  var->value = fVar8;
LAB_00042ad3:
  if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// PF_DecalIndex  @ 00071e80
int PF_DecalIndex(char *name)

{
  int iVar1;
  int iVar2;
  decalname_t *s1;
  
                    /* Unresolved local var: int i@[???] */
  s1 = sv_decalnames;
  iVar2 = 0;
  if (0 < sv_decalnamecount) {
    do {
      iVar1 = Q_stricmp(s1->name,name);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      s1 = s1 + 1;
    } while (iVar2 < sv_decalnamecount);
  }
  return -1;
}


// PF_FadeVolume  @ 00073920
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


// PF_ForceUnmodified  @ 000740c0
void PF_ForceUnmodified(FORCE_TYPE type,float *mins,float *maxs,char *filename)

{
  int iVar1;
  int iVar2;
  consistency_t *pcVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (filename == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("PF_ForceUnmodified: NULL pointer");
  }
  if (*filename < '!') {
    type = (FORCE_TYPE)s_PF_ForceUnmodified__Bad_string___000d70b4;
  }
  else {
    if (sv.state != ss_loading) {
      pcVar3 = sv.consistency_list;
      while ((pcVar3->filename == (char *)0x0 ||
             (iVar1 = Q_stricmp(pcVar3->filename,filename), iVar1 != 0))) {
        pcVar3 = pcVar3 + 1;
        if (pcVar3 == (consistency_t *)&sv.num_consistency) {
                    /* WARNING: Subroutine does not return */
          Host_Error("ForceUnmodified: \'%s\' Precache can only be done in spawn functions",filename
                    );
        }
      }
      return;
    }
    pcVar3 = sv.consistency_list;
    iVar1 = 0;
    do {
      if (pcVar3->filename == (char *)0x0) {
        sv.consistency_list[iVar1].filename = filename;
        sv.consistency_list[iVar1].check_type = type;
        if (mins != (float *)0x0) {
          sv.consistency_list[iVar1].mins[0] = *mins;
          sv.consistency_list[iVar1].mins[1] = mins[1];
          sv.consistency_list[iVar1].mins[2] = mins[2];
        }
        if (maxs == (float *)0x0) {
          return;
        }
        sv.consistency_list[iVar1].maxs[0] = *maxs;
        sv.consistency_list[iVar1].maxs[1] = maxs[1];
        sv.consistency_list[iVar1].maxs[2] = maxs[2];
        return;
      }
      iVar2 = Q_stricmp(pcVar3->filename,filename);
      if (iVar2 == 0) {
        return;
      }
      iVar1 = iVar1 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar1 != 0x200);
    type = (FORCE_TYPE)s_ForceUnmodified____s__overflow_000d7094;
  }
                    /* WARNING: Subroutine does not return */
  Host_Error((char *)type);
}


// PF_GetCurrentPlayer  @ 00073f60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PF_GetCurrentPlayer(void)

{
  int iVar1;
  
                    /* Unresolved local var: int idx@[???] */
  iVar1 = ((int)host_client - (int)svs.clients >> 3) * 0x4ffec005;
  if (-1 < iVar1) {
    if (svs.maxclients <= iVar1) {
      iVar1 = -1;
    }
    return iVar1;
  }
  return -1;
}


// PF_GetInfoKeyBuffer_I  @ 00071ab0
char * PF_GetInfoKeyBuffer_I(edict_t *e)

{
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: int e1@[???]
                       Unresolved local var: char * value@[???] */
  if (e == (edict_t *)0x0) {
    return localinfo;
  }
  iVar1 = NUM_FOR_EDICT(e);
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


// PF_GetPhysicsInfoString  @ 00073e20
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


// PF_GetPhysicsKeyValue  @ 00073e70
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


// PF_GetPlayerAuthId  @ 00073af0
char * PF_GetPlayerAuthId(edict_t *e)

{
  int iVar1;
  char (*pacVar2) [64];
  char *pcVar3;
  int iVar4;
  client_s *client;
  int iVar5;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = (PF_GetPlayerAuthId::count + 1) % 5;
  pacVar2 = PF_GetPlayerAuthId::szAuthID + iVar4;
  PF_GetPlayerAuthId::count = iVar4;
  PF_GetPlayerAuthId::szAuthID[iVar4][0] = '\0';
  if ((sv.active != false) && (e != (edict_t *)0x0)) {
    if (0 < svs.maxclients) {
      iVar5 = 0;
      iVar1 = svs.maxclients;
      client = svs.clients;
      do {
        while (iVar4 = PF_GetPlayerAuthId::count, e != client->edict) {
LAB_00073b50:
          iVar5 = iVar5 + 1;
          client = client + 1;
          iVar4 = PF_GetPlayerAuthId::count;
          if (iVar1 <= iVar5) goto LAB_00073ba6;
        }
        if (client->fakeclient != false) {
          builtin_strncpy(PF_GetPlayerAuthId::szAuthID[PF_GetPlayerAuthId::count],"BOT",4);
          goto LAB_00073b50;
        }
        if ((client->network_userid).idtype != 3) {
          pcVar3 = SV_GetClientIDString(client);
          snprintf(PF_GetPlayerAuthId::szAuthID[PF_GetPlayerAuthId::count],0x3f,"%s",pcVar3);
          iVar1 = svs.maxclients;
          goto LAB_00073b50;
        }
        iVar5 = iVar5 + 1;
        client = client + 1;
        builtin_strncpy(PF_GetPlayerAuthId::szAuthID[PF_GetPlayerAuthId::count],"HLTV",4);
        PF_GetPlayerAuthId::szAuthID[iVar4][4] = '\0';
        iVar4 = PF_GetPlayerAuthId::count;
      } while (iVar5 < iVar1);
    }
LAB_00073ba6:
    pacVar2 = PF_GetPlayerAuthId::szAuthID + iVar4;
    PF_GetPlayerAuthId::szAuthID[iVar4][0x3f] = '\0';
  }
  return *pacVar2;
}


// PF_GetPlayerStats  @ 00074260
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


// PF_GetPlayerUserId  @ 00073a80
int PF_GetPlayerUserId(edict_t *e)

{
  client_s *pcVar1;
  client_s *pcVar2;
  client_s *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  if (((sv.active != false) && (e != (edict_t *)0x0)) && (0 < svs.maxclients)) {
    pcVar3 = svs.clients;
    if (e != (svs.clients)->edict) {
      iVar4 = 0;
      pcVar2 = svs.clients;
      do {
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar2 + 1;
        if (iVar4 == svs.maxclients) {
          return -1;
        }
        pcVar1 = pcVar2 + 1;
        pcVar2 = pcVar3;
      } while (e != pcVar1->edict);
    }
    return pcVar3->userid;
  }
  return -1;
}


// PF_GetPlayerWONId  @ 00073ae0
uint PF_GetPlayerWONId(edict_t *e)

{
  return 0xffffffff;
}


// PF_InfoKeyValue_I  @ 00071b10
char * PF_InfoKeyValue_I(char *infobuffer,char *key)

{
  char cVar1;
  int iVar2;
  char (*pacVar3) [128];
  char *pcVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  char acStack_a0 [128];
  int iStack_20;
  char *pcVar6;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  Info_ValueForKey::valueindex = (Info_ValueForKey::valueindex + 1) % 4;
  cVar1 = *infobuffer;
  if (cVar1 == '\\') {
    cVar1 = infobuffer[1];
    infobuffer = infobuffer + 1;
  }
  do {
    if (cVar1 == '\\') {
      pcVar4 = acStack_a0;
    }
    else {
      if (cVar1 == '\0') {
LAB_0005e8a0:
        pacVar3 = (char (*) [128])0xd7a8b;
LAB_0005e8a5:
        if (iStack_20 == *(int *)(in_GS_OFFSET + 0x14)) {
          return *pacVar3;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      pcVar5 = acStack_a0;
      while( true ) {
        pcVar4 = pcVar5 + 1;
        infobuffer = infobuffer + 1;
        *pcVar5 = cVar1;
        cVar1 = *infobuffer;
        if ((cVar1 == '\\') || (pcVar4 == acStack_a0 + 0x7f)) break;
        pcVar5 = pcVar4;
        if (cVar1 == '\0') goto LAB_0005e8a0;
      }
    }
    *pcVar4 = '\0';
    pcVar4 = infobuffer + 1;
    cVar1 = infobuffer[1];
    pcVar5 = Info_ValueForKey::value[Info_ValueForKey::valueindex];
    if ((cVar1 != '\\') && (cVar1 != '\0')) {
      pcVar6 = pcVar5;
      do {
        pcVar5 = pcVar6 + 1;
        pcVar4 = pcVar4 + 1;
        *pcVar6 = cVar1;
        cVar1 = *pcVar4;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        pcVar6 = pcVar5;
      } while (pcVar4 != infobuffer + 0x80);
    }
    *pcVar5 = '\0';
    iVar2 = Q_strcmp(key,acStack_a0);
    if (iVar2 == 0) {
      pacVar3 = Info_ValueForKey::value + Info_ValueForKey::valueindex;
      goto LAB_0005e8a5;
    }
    if (*pcVar4 == '\0') goto LAB_0005e8a0;
    infobuffer = pcVar4 + 1;
    cVar1 = pcVar4[1];
  } while( true );
}


// PF_IsDedicatedServer  @ 00073e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PF_IsDedicatedServer(void)

{
  return g_bIsDedicatedServer;
}


// PF_IsMapValid_I  @ 000719e0
int PF_IsMapValid_I(char *mapname)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] cBuf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (mapname == (char *)0x0) {
    iVar1 = 0;
  }
  else if (*mapname != '\0') {
    __snprintf_chk(local_114,0x104,1,0x104,"maps/%.32s.bsp",mapname);
    iVar1 = FS_FileExists(local_114);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// PF_MessageBegin_I  @ 00072c80
void PF_MessageBegin_I(int msg_dest,int msg_type,float *pOrigin,edict_t *ed)

{
  if ((msg_dest == 1 || msg_dest == 8) && (ed == (edict_t *)0x0)) {
    Sys_Error("MSG_ONE or MSG_ONE_UNRELIABLE with no target entity\n");
  }
  if ((msg_dest != 8 && msg_dest != 1) && (ed != (edict_t *)0x0)) {
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
  gMsgBuffer.cursize = 0;
  gMsgBuffer.flags = 1;
  return;
}


// PF_MessageEnd_I  @ 00072dd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PF_MessageEnd_I(void)

{
  client_s *pcVar1;
  bool bVar2;
  UserMsg *pUVar3;
  int iVar4;
  int iVar5;
  sizebuf_t *psVar6;
  qboolean reliable;
  
                    /* Unresolved local var: qboolean MsgIsVarLength@[???]
                       Unresolved local var: sizebuf_t * pBuffer@[???]
                       Unresolved local var: int entnum@[???] */
  if (gMsgStarted == false) {
    Sys_Error("MESSAGE_END called with no active message\n");
  }
  iVar5 = gMsgDest;
  gMsgStarted = false;
  if ((gMsgEntity != (edict_t *)0x0) && (((gMsgEntity->v).flags & 0x2000) != 0)) {
    gMsgStarted = false;
    return;
  }
  if (((byte)gMsgBuffer.flags & 2) != 0) {
    Sys_Error("MESSAGE_END called, but message buffer from .dll had overflowed\n");
    return;
  }
                    /* Unresolved local var: qboolean MsgIsVarLength@[???]
                       Unresolved local var: sizebuf_t * pBuffer@[???]
                       Unresolved local var: int entnum@[???] */
  pUVar3 = sv_gpUserMsgs;
  if (0x3b < gMsgType) {
    for (; pUVar3 != (UserMsg *)0x0; pUVar3 = pUVar3->next) {
      if (gMsgType == pUVar3->iMsg) goto LAB_00072e42;
    }
    pUVar3 = sv_gpNewUserMsgs;
    if (gMsgDest == 3) {
      for (; pUVar3 != (UserMsg *)0x0; pUVar3 = pUVar3->next) {
        if (gMsgType == pUVar3->iMsg) goto LAB_00072e42;
      }
    }
    Con_DPrintf("PF_MessageEnd_I:  Unknown User Msg %d\n",gMsgType);
    return;
  }
  switch(gMsgDest) {
  case 0:
    psVar6 = &sv.datagram;
    bVar2 = false;
    break;
  case 1:
  case 8:
    bVar2 = false;
switchD_00072e6d_caseD_1:
                    /* Unresolved local var: int entnum@[???] */
    iVar4 = NUM_FOR_EDICT(gMsgEntity);
    if ((iVar4 < 1) || (svs.maxclients < iVar4)) {
                    /* WARNING: Subroutine does not return */
      Host_Error("WriteDest_Parm: not a client");
    }
    if (iVar5 == 1) {
      psVar6 = &svs.clients[-1].netchan.message;
    }
    else {
      psVar6 = &svs.clients[-1].datagram;
    }
    psVar6 = (sizebuf_t *)((int)psVar6 + iVar4 * 0x6668);
    iVar5 = gMsgDest;
    if (gMsgDest != 0) goto LAB_00072e80;
    break;
  case 2:
    bVar2 = false;
switchD_00072e6d_caseD_2:
    iVar5 = 2;
    psVar6 = &sv.reliable_datagram;
    goto LAB_00072e80;
  case 3:
    bVar2 = false;
switchD_00072e6d_caseD_3:
    iVar5 = 3;
    psVar6 = &sv.signon;
    goto LAB_00072e80;
  case 4:
  case 5:
    bVar2 = false;
switchD_00072e6d_caseD_4:
    psVar6 = &sv.multicast;
    goto LAB_00072e80;
  default:
switchD_00072e6d_caseD_6:
                    /* WARNING: Subroutine does not return */
    Host_Error("WriteDest_Parm: bad destination=%d",gMsgDest);
  case 9:
    bVar2 = false;
switchD_00072e6d_caseD_9:
    psVar6 = &sv.spectator;
    goto LAB_00072e80;
  }
LAB_0007301d:
  if (psVar6->maxsize < gMsgBuffer.cursize + psVar6->cursize) {
    return;
  }
  iVar5 = 0;
LAB_00072e80:
  if (psVar6->data == (byte *)0x0) {
    return;
  }
  if ((0x3b < gMsgType) && ((iVar5 == 1 || (iVar5 == 8)))) {
                    /* Unresolved local var: client_t * cl@[???] */
    iVar5 = NUM_FOR_EDICT(gMsgEntity);
    if ((iVar5 < 1) || (svs.maxclients < iVar5)) {
                    /* WARNING: Subroutine does not return */
      Host_Error("WriteDest_Parm: not a client");
    }
    pcVar1 = svs.clients + iVar5 + -1;
    if (pcVar1->hasusrmsgs == false) {
      return;
    }
    if ((pcVar1->active == false) && (pcVar1->spawned == false)) {
      return;
    }
    if (pcVar1->fakeclient != false) {
      return;
    }
  }
  MSG_WriteByte(psVar6,gMsgType);
  if (bVar2) {
    MSG_WriteByte(psVar6,gMsgBuffer.cursize);
  }
  MSG_WriteBuf(psVar6,gMsgBuffer.cursize,gMsgBuffer.data);
  if (gMsgDest == 5) {
    reliable = false;
  }
  else {
    if (gMsgDest < 6) {
      if (gMsgDest != 4) {
        return;
      }
      SV_Multicast(gMsgEntity,gMsgOrigin,2,false);
      return;
    }
    if ((gMsgDest != 6) && (gMsgDest != 7)) {
      return;
    }
    reliable = true;
  }
  SV_Multicast(gMsgEntity,gMsgOrigin,4,reliable);
  return;
LAB_00072e42:
  iVar4 = pUVar3->iSize;
  if (iVar4 == -1) {
    bVar2 = true;
    if (0xc0 < gMsgBuffer.cursize) {
                    /* WARNING: Subroutine does not return */
      Host_Error("PF_MessageEnd_I:  Refusing to send user message %s of %i bytes to client, user message size limit is %i bytes\n"
                 ,pUVar3->szName,gMsgBuffer.cursize,0xc0);
    }
  }
  else {
    bVar2 = false;
    if (iVar4 != gMsgBuffer.cursize) {
      Sys_Error("User Msg \'%s\': %d bytes written, expected %d\n",pUVar3->szName,gMsgBuffer.cursize
                ,iVar4);
      return;
    }
  }
                    /* Unresolved local var: int entnum@[???] */
  switch(gMsgDest) {
  case 0:
    psVar6 = &sv.datagram;
    break;
  case 1:
  case 8:
    goto switchD_00072e6d_caseD_1;
  case 2:
    goto switchD_00072e6d_caseD_2;
  case 3:
    goto switchD_00072e6d_caseD_3;
  case 4:
  case 5:
    goto switchD_00072e6d_caseD_4;
  default:
    goto switchD_00072e6d_caseD_6;
  case 9:
    goto switchD_00072e6d_caseD_9;
  }
  goto LAB_0007301d;
}


// PF_NumberOfEntities_I  @ 00071a70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PF_NumberOfEntities_I(void)

{
  qboolean *pqVar1;
  int iVar2;
  edict_t *peVar3;
  
                    /* Unresolved local var: int ent_count@[???]
                       Unresolved local var: int i@[???] */
  if (0 < sv.num_edicts) {
    iVar2 = 0;
    peVar3 = sv.edicts;
    do {
      pqVar1 = &peVar3->free;
      peVar3 = peVar3 + 1;
      iVar2 = iVar2 + (-(uint)(*pqVar1 == false) & 1);
    } while (peVar3 != sv.edicts + sv.num_edicts);
    return iVar2;
  }
  return 0;
}


// PF_RemoveKey_I  @ 00071bc0
void PF_RemoveKey_I(char *s,char *key)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  size_t count;
  char *pcVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  char acStack_120 [128];
  char acStack_a0 [128];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar2 = strlen(key);
  count = 0x7f;
  if (sVar2 < 0x7f) {
    count = sVar2;
  }
  pcVar3 = Q_strstr(key,"\\");
  if (pcVar3 == (char *)0x0) {
    cVar1 = *s;
    pcVar3 = s;
    if (cVar1 == '\\') goto LAB_0005ea2a;
LAB_0005e98c:
    if (cVar1 != '\0') {
      pcVar6 = acStack_120;
      do {
        pcVar5 = pcVar6 + 1;
        *pcVar6 = cVar1;
        cVar1 = s[1];
        if ((cVar1 == '\\') || (pcVar5 == acStack_120 + 0x7f)) {
          cVar1 = s[2];
          s = s + 2;
          *pcVar5 = '\0';
          if ((cVar1 == '\\') || (cVar1 == '\0')) {
            pcVar6 = acStack_a0;
            goto LAB_0005e9f4;
          }
LAB_0005e9ce:
          pcVar5 = acStack_a0;
          do {
            pcVar6 = pcVar5 + 1;
            s = s + 1;
            *pcVar5 = cVar1;
            cVar1 = *s;
            if ((cVar1 == '\\') || (cVar1 == '\0')) break;
            pcVar5 = pcVar6;
          } while (pcVar6 != acStack_a0 + 0x7f);
LAB_0005e9f4:
          do {
            *pcVar6 = '\0';
            iVar4 = Q_strncmp(key,acStack_120,count);
            if (iVar4 == 0) {
              iVar4 = Q_strlen(s);
              memmove(pcVar3,s,iVar4 + 1);
              goto LAB_0005e951;
            }
            cVar1 = *s;
            if (cVar1 == '\0') goto LAB_0005e951;
            pcVar3 = s;
            if (cVar1 != '\\') goto LAB_0005e98c;
LAB_0005ea2a:
            cVar1 = pcVar3[1];
            s = pcVar3 + 1;
            if (cVar1 != '\\') goto LAB_0005e98c;
            cVar1 = pcVar3[2];
            s = pcVar3 + 2;
            acStack_120[0] = '\0';
            if ((cVar1 != '\0') && (cVar1 != '\\')) goto LAB_0005e9ce;
            pcVar6 = acStack_a0;
          } while( true );
        }
        s = s + 1;
        pcVar6 = pcVar5;
      } while (cVar1 != '\0');
    }
  }
  else {
    Con_Printf("Can\'t use a key with a \\\n");
  }
LAB_0005e951:
  if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// PF_Remove_I  @ 000704b0
void PF_Remove_I(edict_t *ed)

{
  float fVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  void *p;
  
  if (ed->free != false) {
    return;
  }
  SV_UnlinkEdict(ed);
  p = ed->pvPrivateData;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(ed);
      p = ed->pvPrivateData;
    }
    Mem_Free(p);
  }
  ed->serialnumber = ed->serialnumber + 1;
  ed->free = true;
  vVar2 = vec3_origin[0];
  (ed->v).flags = 0;
  (ed->v).origin[0] = vVar2;
  vVar3 = vec3_origin[1];
  (ed->v).colormap = 0;
  (ed->v).origin[1] = vVar3;
  vVar4 = vec3_origin[2];
  (ed->v).skin = 0;
  (ed->v).origin[2] = vVar4;
  (ed->v).angles[0] = vVar2;
  (ed->v).angles[1] = vVar3;
  (ed->v).angles[2] = vVar4;
  fVar1 = (float)sv.time;
  ed->pvPrivateData = (void *)0x0;
  (ed->v).model = 0;
  (ed->v).takedamage = 0.0;
  (ed->v).modelindex = 0;
  (ed->v).frame = 0.0;
  (ed->v).scale = 0.0;
  (ed->v).gravity = 0.0;
  (ed->v).nextthink = -1.0;
  (ed->v).solid = 0;
  ed->freetime = fVar1;
  return;
}


// PF_RunPlayerMove_I  @ 000729c0
void PF_RunPlayerMove_I(edict_t *fakeclient,float *viewangles,float forwardmove,float sidemove,
                       float upmove,ushort buttons,byte impulse,byte msec)

{
  client_t *pcVar1;
  edict_t *peVar2;
  int iVar3;
  uint uVar4;
  usercmd_t local_50;
  
  peVar2 = sv_player;
                    /* Unresolved local var: usercmd_t cmd@[???]
                       Unresolved local var: edict_t * oldclient@[???]
                       Unresolved local var: client_t * old@[???]
                       Unresolved local var: int entnum@[???] */
  pcVar1 = host_client;
  iVar3 = NUM_FOR_EDICT(fakeclient);
  sv_player = fakeclient;
  host_client = svs.clients + iVar3 + -1;
  host_client->svtimebase = (sv.time + host_frametime) - (double)msec / 1000.0;
  Q_memset(&local_50,0,0x34);
  local_50.viewangles[0] = *viewangles;
  local_50.viewangles[1] = viewangles[1];
  local_50.viewangles[2] = viewangles[2];
  local_50.impulse = impulse;
  local_50.msec = msec;
  local_50.forwardmove = forwardmove;
  local_50.sidemove = sidemove;
  local_50.upmove = upmove;
  pmove = &g_svmove;
  local_50.buttons = buttons;
  local_50.lightlevel = '\0';
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


// PF_SetClientKeyValue_I  @ 00071bd0
void PF_SetClientKeyValue_I(int clientIndex,char *infobuffer,char *key,char *value)

{
  client_s *pcVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: client_t * pClient@[DW_OP_reg0(EAX)] */
  if (infobuffer != localinfo) {
    pcVar2 = Info_Serverinfo();
    if (((0 < clientIndex) && (infobuffer != pcVar2)) && (clientIndex <= svs.maxclients)) {
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


// PF_SetClientMaxspeed  @ 00073a20
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


// PF_SetGroupMask  @ 00074000
void PF_SetGroupMask(int mask,int op)

{
  g_groupmask = mask;
  g_groupop = op;
  return;
}


// PF_SetKeyValue_I  @ 00071b20
void PF_SetKeyValue_I(char *infobuffer,char *key,char *value)

{
  char *pcVar1;
  
  if (infobuffer == localinfo) {
    Info_SetValueForKey(localinfo,key,value,0x8000);
  }
  else {
    pcVar1 = Info_Serverinfo();
    if (infobuffer != pcVar1) {
      Sys_Error("Can\'t set client keys with SetKeyValue");
      return;
    }
    Info_SetValueForKey(infobuffer,key,value,0x200);
  }
  return;
}


// PF_SetPhysicsKeyValue  @ 00073ee0
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


// PF_Spawn_I  @ 00070410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

edict_t * PF_Spawn_I(void)

{
  void *p;
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pedict@[???] */
  iVar2 = svs.maxclients + 1;
  if (iVar2 < sv.num_edicts) {
    peVar1 = sv.edicts + iVar2;
    do {
      if ((peVar1->free != false) &&
         (((double)peVar1->freetime < 2.0 || (0.5 < sv.time - (double)peVar1->freetime))))
      goto LAB_00074d14;
      iVar2 = iVar2 + 1;
      peVar1 = peVar1 + 1;
    } while (iVar2 != sv.num_edicts);
  }
  if (sv.max_edicts <= iVar2) {
    if (sv.max_edicts == 0) {
      Sys_Error("ED_Alloc: No edicts yet");
    }
    Sys_Error("ED_Alloc: no free edicts");
  }
  sv.num_edicts = sv.num_edicts + 1;
  peVar1 = sv.edicts + iVar2;
LAB_00074d14:
  Q_memset(&peVar1->v,0,0x2a4);
  p = peVar1->pvPrivateData;
  peVar1->free = false;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(peVar1);
      p = peVar1->pvPrivateData;
    }
    Mem_Free(p);
  }
  peVar1->pvPrivateData = (void *)0x0;
  (peVar1->v).pContainingEntity = peVar1;
  return peVar1;
}


// PF_StaticDecal  @ 00073520
void PF_StaticDecal(float *origin,int decalIndex,int entityIndex,int modelIndex)

{
  MSG_WriteByte(&sv.signon,0x17);
  MSG_WriteByte(&sv.signon,0xd);
  MSG_WriteCoord(&sv.signon,*origin);
  MSG_WriteCoord(&sv.signon,origin[1]);
  MSG_WriteCoord(&sv.signon,origin[2]);
  MSG_WriteShort(0x53e618,decalIndex);
  MSG_WriteShort(0x53e618,entityIndex);
  if (entityIndex == 0) {
    return;
  }
  MSG_WriteShort();
  return;
}


// PF_Time  @ 0006d870
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float PF_Time(void)

{
  double dVar1;
  
  dVar1 = Sys_FloatTime();
  return (float)dVar1;
}


// PF_TraceToss_DLL  @ 0006f050
void PF_TraceToss_DLL(edict_t *pent,edict_t *pentToIgnore,TraceResult *ptr)

{
  trace_t local_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  if (pentToIgnore == (edict_t *)0x0) {
    pentToIgnore = sv.edicts;
  }
  SV_Trace_Toss(&local_44,pent,pentToIgnore);
  gGlobalVariables.trace_allsolid = (float)local_44.allsolid;
  gGlobalVariables.trace_startsolid = (float)local_44.startsolid;
  gGlobalVariables.trace_fraction = local_44.fraction;
  gGlobalVariables.trace_endpos[0] = local_44.endpos[0];
  gGlobalVariables.trace_endpos[1] = local_44.endpos[1];
  gGlobalVariables.trace_plane_normal[0] = local_44.plane.normal[0];
  gGlobalVariables.trace_inwater = (float)local_44.inwater;
  gGlobalVariables.trace_plane_normal[1] = local_44.plane.normal[1];
  gGlobalVariables.trace_plane_normal[2] = local_44.plane.normal[2];
  gGlobalVariables.trace_endpos[2] = local_44.endpos[2];
  gGlobalVariables.trace_plane_dist = local_44.plane.dist;
  gGlobalVariables.trace_inopen = (float)local_44.inopen;
  if (local_44.ent == (edict_t *)0x0) {
    local_44.ent = sv.edicts;
  }
  gGlobalVariables.trace_hitgroup = local_44.hitgroup;
  gGlobalVariables.trace_ent = local_44.ent;
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


// PF_TraceToss_Shared  @ 0006ee60
void PF_TraceToss_Shared(edict_t *ent,edict_t *ignore)

{
  trace_t local_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  SV_Trace_Toss(&local_44,ent,ignore);
  gGlobalVariables.trace_allsolid = (float)local_44.allsolid;
  gGlobalVariables.trace_fraction = local_44.fraction;
  gGlobalVariables.trace_endpos[0] = local_44.endpos[0];
  gGlobalVariables.trace_endpos[1] = local_44.endpos[1];
  gGlobalVariables.trace_plane_normal[0] = local_44.plane.normal[0];
  gGlobalVariables.trace_startsolid = (float)local_44.startsolid;
  gGlobalVariables.trace_plane_normal[1] = local_44.plane.normal[1];
  gGlobalVariables.trace_plane_normal[2] = local_44.plane.normal[2];
  gGlobalVariables.trace_endpos[2] = local_44.endpos[2];
  gGlobalVariables.trace_plane_dist = local_44.plane.dist;
  gGlobalVariables.trace_inwater = (float)local_44.inwater;
  gGlobalVariables.trace_inopen = (float)local_44.inopen;
  if (local_44.ent == (edict_t *)0x0) {
    local_44.ent = sv.edicts;
  }
  gGlobalVariables.trace_ent = local_44.ent;
  gGlobalVariables.trace_hitgroup = local_44.hitgroup;
  return;
}


// PF_WaterMove  @ 0009d2d0
void PF_WaterMove(edict_t *pSelf)

{
  vec_t *veca;
  uint uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int32 iVar7;
  longdouble lVar8;
  
                    /* Unresolved local var: int flags@[???]
                       Unresolved local var: int waterlevel@[???]
                       Unresolved local var: int watertype@[???]
                       Unresolved local var: float drownlevel@[???] */
  if ((pSelf->v).movetype == 8) {
LAB_0009d486:
    (pSelf->v).air_finished = (float)sv.time + 12.0;
    return;
  }
  if ((pSelf->v).health < 0.0) {
    return;
  }
                    /* Unresolved local var: int flags@[???]
                       Unresolved local var: int waterlevel@[???]
                       Unresolved local var: int watertype@[???]
                       Unresolved local var: float drownlevel@[???] */
  uVar1 = (pSelf->v).flags;
  fVar4 = 1.0;
  iVar2 = (pSelf->v).waterlevel;
  iVar3 = (pSelf->v).watertype;
  if ((pSelf->v).deadflag == 0) {
    fVar4 = 3.0;
  }
  if ((uVar1 & 0x20040) == 0) {
    if (((uVar1 & 2) != 0) || (fVar4 <= (float)iVar2)) {
      fVar4 = (float)sv.time;
      if (((pSelf->v).air_finished < fVar4) && ((pSelf->v).pain_finished < fVar4)) {
        fVar5 = (pSelf->v).dmg + 2.0;
        fVar6 = 10.0;
        if (fVar5 <= 15.0) {
          fVar6 = fVar5;
        }
        (pSelf->v).dmg = fVar6;
        (pSelf->v).pain_finished = fVar4 + 1.0;
      }
    }
    else {
      (pSelf->v).air_finished = (float)sv.time + 12.0;
      (pSelf->v).dmg = 2.0;
    }
  }
  if (iVar2 == 0) {
    if ((uVar1 & 0x10) != 0) {
      iVar7 = RandomLong(0,3);
      if (iVar7 == 1) {
        SV_StartSound(0,pSelf,4,"player/pl_wade2.wav",0xff,0.8,0,100);
      }
      else if (iVar7 < 2) {
        if (iVar7 == 0) {
          SV_StartSound(0,pSelf,4,"player/pl_wade1.wav",0xff,0.8,0,100);
        }
      }
      else if (iVar7 == 2) {
        SV_StartSound(0,pSelf,4,"player/pl_wade3.wav",0xff,0.8,0,100);
      }
      else if (iVar7 == 3) {
        SV_StartSound(0,pSelf,4,"player/pl_wade4.wav",0xff,0.8,0,100);
      }
      (pSelf->v).flags = uVar1 & 0xffffffef;
    }
    goto LAB_0009d486;
  }
  if (iVar3 == -5) {
    if (((uVar1 & 0x80040) == 0) &&
       (lVar8 = (longdouble)sv.time, (longdouble)(pSelf->v).dmgtime < lVar8)) {
      if (lVar8 <= (longdouble)(pSelf->v).radsuit_finished) goto LAB_0009d532;
      (pSelf->v).dmgtime = (float)(lVar8 + (longdouble)0.2);
    }
LAB_0009d560:
    if ((uVar1 & 0x10) != 0) goto LAB_0009d3bc;
  }
  else {
    if (iVar3 == -4) {
      if ((((uVar1 & 0x40040) == 0) && ((double)(pSelf->v).dmgtime < sv.time)) &&
         ((double)(pSelf->v).radsuit_finished < sv.time)) {
LAB_0009d532:
        (pSelf->v).dmgtime = (float)sv.time + 1.0;
      }
      goto LAB_0009d560;
    }
    if ((uVar1 & 0x10) != 0) goto LAB_0009d3bc;
    if (iVar3 == -3) {
      iVar7 = RandomLong(0,3);
      if (iVar7 == 1) {
        SV_StartSound(0,pSelf,4,"player/pl_wade2.wav",0xff,0.8,0,100);
      }
      else if (iVar7 < 2) {
        if (iVar7 == 0) {
          SV_StartSound(0,pSelf,4,"player/pl_wade1.wav",0xff,0.8,0,100);
        }
      }
      else if (iVar7 == 2) {
        SV_StartSound(0,pSelf,4,"player/pl_wade3.wav",0xff,0.8,0,100);
      }
      else if (iVar7 == 3) {
        SV_StartSound(0,pSelf,4,"player/pl_wade4.wav",0xff,0.8,0,100);
      }
    }
  }
  (pSelf->v).flags = uVar1 | 0x10;
  (pSelf->v).dmgtime = 0.0;
LAB_0009d3bc:
  if ((uVar1 & 0x800) == 0) {
    veca = (pSelf->v).velocity;
    VectorMA(veca,(float)(pSelf->v).waterlevel * -0.8 * (float)host_frametime,veca,veca);
  }
  return;
}


// PF_WriteAngle_I  @ 000732b0
void PF_WriteAngle_I(float flValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteAngle_I called with no active message\n");
  }
  MSG_WriteAngle(&gMsgBuffer,flValue);
  return;
}


// PF_WriteByte_I  @ 000731f0
void PF_WriteByte_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("WRITE_BYTE called with no active message\n");
  }
  MSG_WriteByte(&gMsgBuffer,iValue);
  return;
}


// PF_WriteChar_I  @ 00073220
void PF_WriteChar_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("WRITE_CHAR called with no active message\n");
  }
  MSG_WriteChar(&gMsgBuffer,iValue);
  return;
}


// PF_WriteCoord_I  @ 000732f0
void PF_WriteCoord_I(float flValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteCoord_I called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,(int)(flValue * 8.0));
  return;
}


// PF_WriteEntity_I  @ 00073360
void PF_WriteEntity_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteEntity_I called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,iValue);
  return;
}


// PF_WriteLong_I  @ 00073280
void PF_WriteLong_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteLong_I called with no active message\n");
  }
  MSG_WriteLong(&gMsgBuffer,iValue);
  return;
}


// PF_WriteShort_I  @ 00073250
void PF_WriteShort_I(int iValue)

{
  if (gMsgStarted == false) {
    Sys_Error("WRITE_SHORT called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,iValue);
  return;
}


// PF_WriteString_I  @ 00073330
void PF_WriteString_I(char *sz)

{
  if (gMsgStarted == false) {
    Sys_Error("PF_WriteString_I called with no active message\n");
  }
  MSG_WriteString(&gMsgBuffer,sz);
  return;
}


// PF_aim_I  @ 00071fc0
void PF_aim_I(edict_t *ent,float speed,float *rgflReturn)

{
  int iVar1;
  float fVar2;
  int iVar3;
  edict_t *peVar4;
  int iVar5;
  int iVar6;
  float local_94;
  vec_t local_90;
  vec_t local_8c;
  vec_t local_88;
  float local_78;
  float local_74;
  float local_70;
  vec_t local_6c;
  vec_t local_68;
  vec_t local_64;
  float local_60;
  float local_5c;
  float local_58;
  trace_t local_54;
  
                    /* Unresolved local var: edict_t * check@[???]
                       Unresolved local var: edict_t * bestent@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: vec3_t bestdir@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: trace_t tr@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float bestdist@[???] */
  if ((ent == (edict_t *)0x0) || (((ent->v).flags & 0x2000) != 0)) {
    *rgflReturn = gGlobalVariables.v_forward[0];
    rgflReturn[1] = gGlobalVariables.v_forward[1];
    rgflReturn[2] = gGlobalVariables.v_forward[2];
  }
  else {
    local_78 = (ent->v).origin[0] + (ent->v).view_ofs[0];
    local_74 = (ent->v).view_ofs[1] + (ent->v).origin[1];
    local_6c = gGlobalVariables.v_forward[0];
    local_68 = gGlobalVariables.v_forward[1];
    local_64 = gGlobalVariables.v_forward[2];
    local_70 = (ent->v).view_ofs[2] + (ent->v).origin[2];
    VectorMA(&local_78,2048.0,&local_6c,&local_60);
    SV_Move(&local_54,&local_78,vec3_origin,vec3_origin,&local_60,0,ent,false);
    if (((local_54.ent == (edict_t *)0x0) || (((local_54.ent)->v).takedamage != 2.0)) ||
       ((iVar3 = (ent->v).team, 0 < iVar3 && (iVar3 == ((local_54.ent)->v).team)))) {
      local_8c = local_6c;
      local_88 = local_68;
      local_90 = local_64;
      if (sv_allow_autoaim.value == 0.0) {
        local_94 = 0.0;
      }
      else {
        local_94 = sv_aim.value;
      }
      if (1 < sv.num_edicts) {
        iVar5 = 0x324;
        iVar6 = 1;
        iVar3 = sv.num_edicts;
        do {
          peVar4 = (edict_t *)((int)(sv.edicts)->leafnums + iVar5 + -0x18);
          if (((((peVar4->v).takedamage == 2.0) && (((peVar4->v).flags & 0x2000) == 0)) &&
              (ent != peVar4)) &&
             ((iVar1 = (ent->v).team, iVar1 < 1 || (iVar1 != (peVar4->v).team)))) {
            local_60 = (ent->v).view_ofs[0] * 0.0 +
                       ((peVar4->v).mins[0] + (peVar4->v).maxs[0]) * 0.75 + (peVar4->v).origin[0];
            local_5c = (ent->v).view_ofs[1] * 0.0 +
                       ((peVar4->v).mins[1] + (peVar4->v).maxs[1]) * 0.75 + (peVar4->v).origin[1];
            local_58 = (ent->v).view_ofs[2] * 0.0 +
                       ((peVar4->v).mins[2] + (peVar4->v).maxs[2]) * 0.75 + (peVar4->v).origin[2];
            local_6c = local_60 - local_78;
            local_68 = local_5c - local_74;
            local_64 = local_58 - local_70;
            VectorNormalize(&local_6c);
            fVar2 = local_64 * gGlobalVariables.v_forward[2] +
                    local_68 * gGlobalVariables.v_forward[1] +
                    local_6c * gGlobalVariables.v_forward[0];
            iVar3 = sv.num_edicts;
            if ((local_94 <= fVar2) &&
               (SV_Move(&local_54,&local_78,vec3_origin,vec3_origin,&local_60,0,ent,false),
               iVar3 = sv.num_edicts, local_54.ent == peVar4)) {
              local_8c = local_6c;
              local_88 = local_68;
              local_90 = local_64;
              local_94 = fVar2;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x324;
        } while (iVar6 < iVar3);
      }
      *rgflReturn = local_8c;
      rgflReturn[1] = local_88;
      rgflReturn[2] = local_90;
      return;
    }
    *rgflReturn = gGlobalVariables.v_forward[0];
    rgflReturn[1] = gGlobalVariables.v_forward[1];
    rgflReturn[2] = gGlobalVariables.v_forward[2];
  }
  return;
}


// PF_ambientsound_I  @ 0006e030
void PF_ambientsound_I(edict_t *entity,float *pos,char *samp,float vol,float attenuation,int fFlags,
                      int pitch)

{
  float *pfVar1;
  char *s1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  int iVar5;
  sizebuf_t *sb;
  uint local_30;
  
                    /* Unresolved local var: char * * check@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int soundnum@[???]
                       Unresolved local var: int ent@[???]
                       Unresolved local var: sizebuf_t * pout@[???] */
  local_30 = fFlags;
  if (*samp == '!') {
    local_30 = fFlags | 0x10;
    iVar3 = Q_atoi(samp + 1);
    if (iVar3 < 0x800) {
LAB_0006e0b2:
      sb = &sv.datagram;
      iVar2 = NUM_FOR_EDICT(entity);
      if ((local_30 & 0x100) != 0) {
        sb = &sv.signon;
      }
      iVar5 = 0;
      MSG_WriteByte(sb,0x1d);
      do {
        pfVar1 = pos + iVar5;
        iVar5 = iVar5 + 1;
        MSG_WriteCoord(sb,*pfVar1);
      } while (iVar5 != 3);
      MSG_WriteShort(sb,iVar3);
      MSG_WriteByte(sb,(int)(vol * 255.0));
      MSG_WriteByte(sb,(int)(attenuation * 64.0));
      MSG_WriteShort(sb,iVar2);
      MSG_WriteByte(sb,pitch);
      MSG_WriteByte(sb,local_30 & 0xff);
      return;
    }
    entity = (edict_t *)s_invalid_sentence_number___s_000d62f6;
  }
  else {
    iVar3 = 0;
    ppcVar4 = sv.sound_precache;
    s1 = sv.sound_precache[0];
    while (s1 != (char *)0x0) {
      iVar2 = Q_stricmp(s1,samp);
      if (iVar2 == 0) {
        if (*ppcVar4 != (char *)0x0) goto LAB_0006e0b2;
        break;
      }
      ppcVar4 = ppcVar4 + 1;
      iVar3 = iVar3 + 1;
      s1 = *ppcVar4;
    }
    entity = (edict_t *)s_no_precache___s_000d62bb;
  }
  Con_Printf((char *)entity);
  return;
}


// PF_bprint  @ 0006dda0
void PF_bprint(char *s)

{
  SV_BroadcastPrintf("%s",s);
  return;
}


// PF_changelevel_I  @ 00073660
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


// PF_changepitch_I  @ 000724c0
void PF_changepitch_I(edict_t *ent)

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
  if (fVar3 == fVar4) {
    return;
  }
  fVar1 = fVar4 - fVar3;
  if (fVar4 <= fVar3) {
    if (fVar1 <= -180.0) {
      fVar1 = fVar1 + 360.0;
      fVar4 = (ent->v).pitch_speed;
      goto joined_r0x00072570;
    }
  }
  else if (180.0 <= fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  fVar4 = (ent->v).pitch_speed;
joined_r0x00072570:
  if (0.0 < fVar1) {
    fVar2 = fVar1;
    if (fVar4 < fVar1) {
      fVar2 = fVar4;
    }
  }
  else {
    fVar2 = -fVar4;
    if (-fVar4 <= fVar1) {
      fVar2 = fVar1;
    }
  }
  fVar4 = anglemod(fVar3 + fVar2);
  (ent->v).angles[0] = fVar4;
  return;
}


// PF_changeyaw_I  @ 000723e0
void PF_changeyaw_I(edict_t *ent)

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
  if (fVar3 == fVar4) {
    return;
  }
  fVar1 = fVar4 - fVar3;
  if (fVar4 <= fVar3) {
    if (fVar1 <= -180.0) {
      fVar1 = fVar1 + 360.0;
      fVar4 = (ent->v).yaw_speed;
      goto joined_r0x00072490;
    }
  }
  else if (180.0 <= fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  fVar4 = (ent->v).yaw_speed;
joined_r0x00072490:
  if (0.0 < fVar1) {
    fVar2 = fVar1;
    if (fVar4 < fVar1) {
      fVar2 = fVar4;
    }
  }
  else {
    fVar2 = -fVar4;
    if (-fVar4 <= fVar1) {
      fVar2 = fVar1;
    }
  }
  fVar4 = anglemod(fVar3 + fVar2);
  (ent->v).angles[1] = fVar4;
  return;
}


// PF_checkbottom_I  @ 00071fa0
int PF_checkbottom_I(edict_t *pEdict)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  vec_t vVar7;
  int iVar8;
  int iVar9;
  qboolean monsterClipBrush;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  trace_t tStack_54;
  
  fVar2 = (pEdict->v).origin[0] + (pEdict->v).mins[0];
  g_groupmask = (pEdict->v).groupinfo;
  uVar1 = (pEdict->v).flags;
  fVar3 = (pEdict->v).origin[1] + (pEdict->v).mins[1];
  fVar4 = (pEdict->v).origin[2] + (pEdict->v).mins[2];
  fVar5 = (pEdict->v).origin[0] + (pEdict->v).maxs[0];
  fVar6 = (pEdict->v).origin[1] + (pEdict->v).maxs[1];
  fStack_64 = fVar4 - 1.0;
  fStack_6c = fVar2;
  fStack_68 = fVar3;
  iVar8 = SV_PointContents(&fStack_6c);
  if (iVar8 == -2) {
    g_groupmask = (pEdict->v).groupinfo;
    fStack_6c = fVar2;
    fStack_68 = fVar6;
    iVar8 = SV_PointContents(&fStack_6c);
    if (iVar8 == -2) {
      g_groupmask = (pEdict->v).groupinfo;
      fStack_6c = fVar5;
      fStack_68 = fVar3;
      iVar8 = SV_PointContents(&fStack_6c);
      if (iVar8 == -2) {
        g_groupmask = (pEdict->v).groupinfo;
        fStack_6c = fVar5;
        fStack_68 = fVar6;
        iVar8 = SV_PointContents(&fStack_6c);
        if (iVar8 == -2) goto LAB_00095a67;
      }
    }
  }
  fStack_64 = fVar4 + sv_stepsize.value;
  monsterClipBrush = uVar1 >> 0x17 & true;
  fStack_6c = (fVar2 + fVar5) * 0.5;
  c_no = c_no + 1;
  fStack_68 = (fVar3 + fVar6) * 0.5;
  fStack_58 = fStack_64 - (sv_stepsize.value + sv_stepsize.value);
  fStack_60 = fStack_6c;
  fStack_5c = fStack_68;
  SV_Move(&tStack_54,&fStack_6c,vec3_origin,vec3_origin,&fStack_60,1,pEdict,monsterClipBrush);
  vVar7 = tStack_54.endpos[2];
  if (tStack_54.fraction == 1.0) {
    return 0;
  }
  iVar8 = 0;
  do {
    fVar4 = fVar2;
    if (iVar8 != 0) {
      fVar4 = fVar5;
    }
    iVar9 = 0;
    do {
      fStack_68 = fVar6;
      if (iVar9 == 0) {
        fStack_68 = fVar3;
      }
      fStack_6c = fVar4;
      fStack_60 = fVar4;
      fStack_5c = fStack_68;
      SV_Move(&tStack_54,&fStack_6c,vec3_origin,vec3_origin,&fStack_60,1,pEdict,monsterClipBrush);
      if (tStack_54.fraction == 1.0) {
        return 0;
      }
      if (sv_stepsize.value < vVar7 - tStack_54.endpos[2]) {
        return 0;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 2);
    iVar8 = iVar8 + 1;
  } while (iVar8 != 2);
LAB_00095a67:
  c_yes = c_yes + 1;
  return 1;
}


// PF_checkclient_I  @ 0006f440
edict_t * PF_checkclient_I(edict_t *pEdict)

{
  mleaf_t *pmVar1;
  edict_t *peVar2;
  int iVar3;
  edict_t *peVar4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: mleaf_t * leaf@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: vec3_t view@[???] */
  if (0.1 <= sv.time - sv.lastchecktime) {
    sv.lastcheck = PF_newcheckclient(sv.lastcheck);
    sv.lastchecktime = sv.time;
  }
  peVar4 = sv.edicts + sv.lastcheck;
  peVar2 = sv.edicts;
  if ((peVar4->free == false) && (peVar4->pvPrivateData != (void *)0x0)) {
    local_18 = (pEdict->v).origin[0] + (pEdict->v).view_ofs[0];
    local_14 = (pEdict->v).origin[1] + (pEdict->v).view_ofs[1];
    local_10 = (pEdict->v).origin[2] + (pEdict->v).view_ofs[2];
    pmVar1 = Mod_PointInLeaf(&local_18,sv.worldmodel);
    iVar3 = ((int)pmVar1 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
    if ((iVar3 < 0) || (((int)(uint)checkpvs[iVar3 >> 3] >> ((byte)iVar3 & 7) & 1U) == 0)) {
      c_notvis = c_notvis + 1;
      return sv.edicts;
    }
    c_invis = c_invis + 1;
    peVar2 = peVar4;
  }
  return peVar2;
}


// PF_crosshairangle_I  @ 00072650
void PF_crosshairangle_I(edict_t *clientent,float pitch,float yaw)

{
  sizebuf_t *sb;
  int iVar1;
  float local_14;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int clientnum@[???] */
  local_14 = pitch;
  iVar1 = NUM_FOR_EDICT(clientent);
  if (((0 < iVar1) && (iVar1 <= svs.maxclients)) && (svs.clients[iVar1 + -1].fakeclient == false)) {
    if (180.0 < pitch) {
      local_14 = pitch - 360.0;
    }
    if (local_14 < -180.0) {
      local_14 = local_14 + 360.0;
    }
    sb = &svs.clients[iVar1 + -1].netchan.message;
    MSG_WriteByte(sb,0x2f);
    MSG_WriteChar(sb,(int)(local_14 * 5.0));
    MSG_WriteChar();
    return;
  }
  return;
}


// PF_droptofloor_I  @ 00071d60
int PF_droptofloor_I(edict_t *ent)

{
  int *piVar1;
  int iVar2;
  vec_t local_50;
  vec_t local_4c;
  float local_48;
  trace_t local_44;
  
                    /* Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  local_48 = (ent->v).origin[2] - 256.0;
  local_50 = (ent->v).origin[0];
  local_4c = (ent->v).origin[1];
  SV_Move(&local_44,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_50,0,ent,
          (uint)(ent->v).flags >> 0x17 & true);
  if (local_44.allsolid == false) {
    iVar2 = 0;
    if (local_44.fraction != 1.0) {
      (ent->v).origin[0] = local_44.endpos[0];
      (ent->v).origin[1] = local_44.endpos[1];
      (ent->v).origin[2] = local_44.endpos[2];
      SV_LinkEdict(ent,false);
      piVar1 = &(ent->v).flags;
      *piVar1 = *piVar1 | 0x200;
      (ent->v).groundentity = local_44.ent;
      return 1;
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


// PF_lightstyle_I  @ 00071ee0
void PF_lightstyle_I(int style,char *val)

{
  int iVar1;
  sizebuf_t *sb;
  int iVar2;
  bool bVar3;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int j@[???] */
  bVar3 = sv.state == ss_active;
  sv.lightstyles[style] = val;
  if (bVar3) {
    if (0 < svs.maxclients) {
      sb = &((svs.clients)->netchan).message;
      iVar2 = 0;
      iVar1 = svs.maxclients;
      do {
        if (((*(int *)&sb[-6].flags != 0) || (sb[-6].data != (byte *)0x0)) &&
           (sb[0x291].cursize == 0)) {
          MSG_WriteChar(sb,0xc);
          MSG_WriteChar(sb,style);
          MSG_WriteString(sb,val);
          iVar1 = svs.maxclients;
        }
        iVar2 = iVar2 + 1;
        sb = (sizebuf_t *)&sb[0x51e].cursize;
      } while (iVar2 < iVar1);
    }
  }
  return;
}


// PF_localcmd_I  @ 000701f0
void PF_localcmd_I(char *str)

{
  int iVar1;
  
                    /* Unresolved local var: int len@[???] */
  iVar1 = Q_strlen(str);
  if ((iVar1 != 0) && ((str[iVar1 + -1] == '\n' || (str[iVar1 + -1] == ';')))) {
    Cbuf_AddText(str);
    return;
  }
  Con_Printf("Error, bad server command %s\n",str);
  return;
}


// PF_localexec_I  @ 00070240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PF_localexec_I(void)

{
  Cbuf_ExecuteCommandsFromBuffer(&cmd_text,true,-1);
  Cbuf_ExecuteCommandsFromBuffer(&filteredcmd_text,false,1);
  return;
}


// PF_makestatic_I  @ 00073390
void PF_makestatic_I(edict_t *ent)

{
  int iVar1;
  vec_t *pvVar2;
  vec_t *pvVar3;
  
                    /* Unresolved local var: int i@[???] */
  MSG_WriteByte(&sv.signon,0x14);
  iVar1 = SV_ModelIndex(pr_strings + (ent->v).model);
  MSG_WriteShort(0x53e618,iVar1);
  MSG_WriteByte(&sv.signon,(ent->v).sequence);
  MSG_WriteByte(&sv.signon,(int)(ent->v).frame);
  MSG_WriteWord(&sv.signon,(ent->v).colormap);
  MSG_WriteByte(&sv.signon,(ent->v).skin);
  pvVar2 = (ent->v).origin;
  do {
    pvVar3 = pvVar2 + 1;
    MSG_WriteCoord(&sv.signon,*pvVar2);
    MSG_WriteAngle(&sv.signon,pvVar2[0x12]);
    pvVar2 = pvVar3;
  } while (pvVar3 != (ent->v).oldorigin);
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


// PF_makevectors_I  @ 0006d840
void PF_makevectors_I(float *rgflVector)

{
  AngleVectors(rgflVector,gGlobalVariables.v_forward,gGlobalVariables.v_right,gGlobalVariables.v_up)
  ;
  return;
}


// PF_modelindex  @ 0006dd40
int PF_modelindex(char *pstr)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((pstr != (char *)0x0) && (iVar2 = 0, *pstr != '\0')) {
    do {
      iVar1 = iVar2;
      if (sv.model_precache[iVar2] == (char *)0x0) break;
      iVar1 = Q_strcasecmp(sv.model_precache[iVar2],pstr);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2;
    } while (iVar2 != 0x200);
    Sys_Error("SV_ModelIndex: model %s not precached",pstr);
  }
  return iVar1;
}


// PF_newcheckclient  @ 0006f330
int PF_newcheckclient(int check)

{
  edict_t *peVar1;
  mleaf_t *leaf;
  byte *src;
  int iVar2;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte * pvs@[???]
                       Unresolved local var: edict_t * ent@[???]
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
  if (iVar2 == svs.maxclients + 1) goto LAB_0006f38a;
  while (peVar1 = sv.edicts + iVar2, iVar2 != check) {
    while( true ) {
      if (((peVar1->free == false) && (peVar1->pvPrivateData != (void *)0x0)) &&
         (((peVar1->v).flags & 0x80) == 0)) goto LAB_0006f39a;
      iVar2 = iVar2 + 1;
      if (iVar2 != svs.maxclients + 1) break;
LAB_0006f38a:
      iVar2 = 1;
      peVar1 = sv.edicts + 1;
      if (check == 1) goto LAB_0006f39a;
    }
  }
LAB_0006f39a:
  local_18 = (peVar1->v).origin[0] + (peVar1->v).view_ofs[0];
  local_14 = (peVar1->v).origin[1] + (peVar1->v).view_ofs[1];
  local_10 = (peVar1->v).origin[2] + (peVar1->v).view_ofs[2];
  leaf = Mod_PointInLeaf(&local_18,sv.worldmodel);
  src = Mod_LeafPVS(leaf,sv.worldmodel);
  Q_memcpy(checkpvs,src,(sv.worldmodel)->numleafs + 7 >> 3);
  return iVar2;
}


// PF_particle_I  @ 0006e010
void PF_particle_I(float *org,float *dir,float color,float count)

{
  SV_StartParticle(org,dir,(int)color,(int)count);
  return;
}


// PF_pointcontents_I  @ 00071fb0
int PF_pointcontents_I(float *rgflVector)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  model_s *pmVar3;
  int iVar4;
  int iVar5;
  
  pmVar3 = sv.worldmodel;
  iVar5 = 0;
  do {
    while( true ) {
      if ((iVar5 < pmVar3->hulls[0].firstclipnode) || (pmVar3->hulls[0].lastclipnode < iVar5)) {
        Sys_Error("SV_HullPointContents: bad node number");
      }
      pdVar1 = pmVar3->hulls[0].clipnodes + iVar5;
      pmVar2 = pmVar3->hulls[0].planes + pdVar1->planenum;
      if (2 < pmVar2->type) break;
      if (0.0 <= rgflVector[pmVar2->type] - pmVar2->dist) goto LAB_000aa206;
LAB_000aa269:
      iVar5 = (int)pdVar1->children[1];
      if (iVar5 < 0) goto LAB_000aa271;
    }
    if ((pmVar2->normal[2] * rgflVector[2] +
        pmVar2->normal[1] * rgflVector[1] + pmVar2->normal[0] * *rgflVector) - pmVar2->dist < 0.0)
    goto LAB_000aa269;
LAB_000aa206:
    iVar5 = (int)pdVar1->children[0];
  } while (-1 < iVar5);
LAB_000aa271:
  if (iVar5 + 0xeU < 6) {
    iVar5 = -3;
  }
  else if (iVar5 == -2) {
    return -2;
  }
  iVar4 = SV_LinkContents(sv_areanodes,rgflVector);
  if (iVar4 == -1) {
    iVar4 = iVar5;
  }
  return iVar4;
}


// PF_precache_generic_I  @ 000718f0
int PF_precache_generic_I(char *s)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (s == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("PF_precache_generic_I: NULL pointer");
  }
  if (' ' < *s) {
    iVar2 = 0;
    if (sv.state == ss_loading) {
      iVar2 = 0;
      while( true ) {
        if (sv.generic_precache[iVar2] == (char *)0x0) {
          sv.generic_precache[iVar2] = s;
          return iVar2;
        }
        iVar1 = Q_strcasecmp(sv.generic_precache[iVar2],s);
        if (iVar1 == 0) break;
        iVar2 = iVar2 + 1;
        if (iVar2 == 0x200) {
                    /* WARNING: Subroutine does not return */
          Host_Error("PF_precache_generic_I: Generic item \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
                     ,s,0x200);
        }
      }
      return iVar2;
    }
    while ((sv.generic_precache[iVar2] == (char *)0x0 ||
           (iVar1 = Q_strcmp(sv.generic_precache[iVar2],s), iVar1 != 0))) {
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x200) {
                    /* WARNING: Subroutine does not return */
        Host_Error("PF_precache_generic_I: \'%s\' Precache can only be done in spawn functions",s);
      }
    }
    return iVar2;
  }
  Con_Printf("PF_precache_generic_I: Bad string \'%s\'",s);
  return 0;
}


// PF_precache_model_I  @ 000717b0
int PF_precache_model_I(char *s)

{
  char cVar1;
  int iVar2;
  model_t *pmVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iOptional@[???] */
  if (s == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("PF_precache_model_I: NULL pointer");
  }
  cVar1 = *s;
  if (cVar1 < '!') {
                    /* WARNING: Subroutine does not return */
    Host_Error("PF_precache_model_I: Bad string \'%s\'",s);
  }
  if (cVar1 == '!') {
    s = s + 1;
  }
  if (sv.state == ss_loading) {
    iVar4 = 0;
    while (sv.model_precache[iVar4] != (char *)0x0) {
      iVar2 = Q_stricmp(sv.model_precache[iVar4],s);
      if (iVar2 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      if (iVar4 == 0x200) {
                    /* WARNING: Subroutine does not return */
        Host_Error("PF_precache_model_I: Model \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
                   ,s,0x200);
      }
    }
    sv.model_precache[iVar4] = s;
    pmVar3 = Mod_ForName(s,true,true);
    sv.models[iVar4] = pmVar3;
    if (cVar1 != '!') {
      sv.model_precache_flags[iVar4] = sv.model_precache_flags[iVar4] | 1;
    }
  }
  else {
    iVar4 = 0;
    while ((sv.model_precache[iVar4] == (char *)0x0 ||
           (iVar2 = Q_stricmp(sv.model_precache[iVar4],s), iVar2 != 0))) {
      iVar4 = iVar4 + 1;
      if (iVar4 == 0x200) {
                    /* WARNING: Subroutine does not return */
        Host_Error("PF_precache_model_I: \'%s\' Precache can only be done in spawn functions",s);
      }
    }
  }
  return iVar4;
}


// PF_precache_sound_I  @ 00070880
int PF_precache_sound_I(char *s)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (s == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("PF_precache_sound_I: NULL pointer");
  }
  if (*s < '!') {
                    /* WARNING: Subroutine does not return */
    Host_Error("PF_precache_sound_I: Bad string \'%s\'",s);
  }
  if (*s == '!') {
                    /* WARNING: Subroutine does not return */
    Host_Error("PF_precache_sound_I: \'%s\' do not precache sentence names!",s);
  }
  if (sv.state == ss_loading) {
    iVar2 = 0;
    sv.sound_precache_hashedlookup_built = false;
    while( true ) {
      if (sv.sound_precache[iVar2] == (char *)0x0) {
        sv.sound_precache[iVar2] = s;
        return iVar2;
      }
      iVar1 = Q_stricmp(sv.sound_precache[iVar2],s);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x200) {
                    /* WARNING: Subroutine does not return */
        Host_Error("PF_precache_sound_I: Sound \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
                   ,s,0x200);
      }
    }
    return iVar2;
  }
  iVar2 = 0;
  while ((sv.sound_precache[iVar2] == (char *)0x0 ||
         (iVar1 = Q_stricmp(sv.sound_precache[iVar2],s), iVar1 != 0))) {
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x200) {
                    /* WARNING: Subroutine does not return */
      Host_Error("PF_precache_sound_I: \'%s\' Precache can only be done in spawn functions",s);
    }
  }
  return iVar2;
}


// PF_setmodel_I  @ 0006db40
void PF_setmodel_I(edict_t *e,char *m)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  model_s *pmVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char **ppcVar10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * * check@[???]
                       Unresolved local var: model_t * mod@[???] */
  if (sv.model_precache[0] != (char *)0x0) {
    ppcVar10 = sv.model_precache;
    iVar9 = 0;
    pcVar7 = sv.model_precache[0];
    do {
      iVar8 = Q_stricmp(pcVar7,m);
      pcVar7 = pr_strings;
      if (iVar8 == 0) {
        if (*ppcVar10 != (char *)0x0) {
          (e->v).modelindex = iVar9;
          (e->v).model = (int)m - (int)pcVar7;
          vVar5 = vec3_origin[2];
          vVar4 = vec3_origin[1];
          vVar1 = vec3_origin[0];
          pmVar6 = sv.models[iVar9];
          if (pmVar6 == (model_s *)0x0) {
            (e->v).mins[0] = vec3_origin[0];
            (e->v).mins[1] = vVar4;
            (e->v).mins[2] = vVar5;
            (e->v).maxs[0] = vVar1;
            (e->v).maxs[1] = vVar4;
            (e->v).maxs[2] = vVar5;
            (e->v).size[0] = vVar1 - vVar1;
            (e->v).size[1] = vVar4 - vVar4;
            fVar2 = vVar5 - vVar5;
          }
          else {
                    /* Unresolved local var: float * angles@[???]
                       Unresolved local var: vec3_t rmin@[???]
                       Unresolved local var: vec3_t rmax@[???]
                       Unresolved local var: float[2][3] bounds@[???]
                       Unresolved local var: float[2] xvector@[???]
                       Unresolved local var: float[2] yvector@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: vec3_t base@[???]
                       Unresolved local var: vec3_t transformed@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int l@[???] */
            if (pmVar6->maxs[0] < pmVar6->mins[0]) {
                    /* WARNING: Subroutine does not return */
              Host_Error("backwards mins/maxs");
            }
            if (pmVar6->maxs[1] < pmVar6->mins[1]) {
                    /* WARNING: Subroutine does not return */
              Host_Error("backwards mins/maxs");
            }
            fVar2 = pmVar6->mins[2];
            fVar3 = pmVar6->maxs[2];
            if (fVar3 < fVar2) {
                    /* WARNING: Subroutine does not return */
              Host_Error("backwards mins/maxs");
            }
            vVar4 = pmVar6->maxs[0];
            vVar5 = pmVar6->maxs[1];
            vVar1 = pmVar6->mins[0];
            (e->v).mins[1] = pmVar6->mins[1];
            (e->v).mins[2] = fVar2;
            (e->v).maxs[0] = vVar4;
            (e->v).maxs[1] = vVar5;
            (e->v).mins[0] = vVar1;
            (e->v).maxs[2] = fVar3;
            (e->v).size[0] = pmVar6->maxs[0] - pmVar6->mins[0];
            (e->v).size[1] = pmVar6->maxs[1] - pmVar6->mins[1];
            fVar2 = pmVar6->maxs[2] - pmVar6->mins[2];
          }
                    /* Unresolved local var: float * angles@[???]
                       Unresolved local var: vec3_t rmin@[???]
                       Unresolved local var: vec3_t rmax@[???]
                       Unresolved local var: float[2][3] bounds@[???]
                       Unresolved local var: float[2] xvector@[???]
                       Unresolved local var: float[2] yvector@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: vec3_t base@[???]
                       Unresolved local var: vec3_t transformed@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int l@[???] */
          (e->v).size[2] = fVar2;
          SV_LinkEdict(e,false);
          return;
        }
        break;
      }
      ppcVar10 = ppcVar10 + 1;
      pcVar7 = *ppcVar10;
      iVar9 = iVar9 + 1;
    } while (pcVar7 != (char *)0x0);
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("no precache: %s\n",m);
}


// PF_setorigin_I  @ 0006d890
void PF_setorigin_I(edict_t *e,float *org)

{
  if (e != (edict_t *)0x0) {
    (e->v).origin[0] = *org;
    (e->v).origin[1] = org[1];
    (e->v).origin[2] = org[2];
    SV_LinkEdict(e,false);
    return;
  }
  return;
}


// PF_setsize_I  @ 0006da10
void PF_setsize_I(edict_t *e,float *rgflMin,float *rgflMax)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  
                    /* Unresolved local var: float * angles@[???]
                       Unresolved local var: vec3_t rmin@[???]
                       Unresolved local var: vec3_t rmax@[???]
                       Unresolved local var: float[2][3] bounds@[???]
                       Unresolved local var: float[2] xvector@[???]
                       Unresolved local var: float[2] yvector@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: vec3_t base@[???]
                       Unresolved local var: vec3_t transformed@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int l@[???] */
  if (*rgflMax < *rgflMin) {
                    /* WARNING: Subroutine does not return */
    Host_Error("backwards mins/maxs");
  }
  if (rgflMin[1] <= rgflMax[1]) {
    fVar2 = rgflMin[2];
    fVar3 = rgflMax[2];
    if (fVar2 <= fVar3) {
      vVar4 = *rgflMax;
      vVar5 = rgflMax[1];
      vVar1 = *rgflMin;
      (e->v).mins[1] = rgflMin[1];
      (e->v).mins[2] = fVar2;
      (e->v).maxs[0] = vVar4;
      (e->v).maxs[1] = vVar5;
      (e->v).mins[0] = vVar1;
      (e->v).maxs[2] = fVar3;
      (e->v).size[0] = *rgflMax - *rgflMin;
      (e->v).size[1] = rgflMax[1] - rgflMin[1];
      (e->v).size[2] = rgflMax[2] - rgflMin[2];
      SV_LinkEdict(e,false);
      return;
    }
                    /* WARNING: Subroutine does not return */
    Host_Error("backwards mins/maxs");
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("backwards mins/maxs");
}


// PF_setspawnparms_I  @ 00073620
void PF_setspawnparms_I(edict_t *ent)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???] */
  iVar1 = NUM_FOR_EDICT(ent);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("Entity is not a client");
}


// PF_setview_I  @ 000725a0
void PF_setview_I(edict_t *clientent,edict_t *viewent)

{
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int clientnum@[???] */
  iVar2 = NUM_FOR_EDICT(clientent);
  pcVar1 = svs.clients;
  if ((0 < iVar2) && (iVar2 <= svs.maxclients)) {
    if (svs.clients[iVar2 + -1].fakeclient != false) {
      return;
    }
    svs.clients[iVar2 + -1].pViewEntity = viewent;
    MSG_WriteByte(&pcVar1[iVar2 + -1].netchan.message,5);
    NUM_FOR_EDICT(viewent);
    MSG_WriteShort();
    return;
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("PF_setview_I: not a client");
}


// PF_sound_I  @ 0006e1e0
void PF_sound_I(edict_t *entity,int channel,char *sample,float volume,float attenuation,int fFlags,
               int pitch)

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


// PF_sprint  @ 0006ddc0
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


// PF_stuffcmd_I  @ 000700e0
void PF_stuffcmd_I(edict_t *pEdict,char *szFmt,...)

{
  client_t *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int entnum@[???]
                       Unresolved local var: client_t * old@[???]
                       Unresolved local var: va_list argptr@[???] */
  iVar2 = NUM_FOR_EDICT(pEdict);
  __vsnprintf_chk(PF_stuffcmd_I::szOut,0x400,1,0x400,szFmt,&stack0x0000000c);
  PF_stuffcmd_I::szOut[0x3ff] = '\0';
  if ((iVar2 < 1) || (svs.maxclients < iVar2)) {
    Con_Printf("\n!!!\n\nStuffCmd:  Some entity tried to stuff \'%s\' to console buffer of entity %i when maxclients was set to %i, ignoring\n\n"
               ,PF_stuffcmd_I::szOut,iVar2,svs.maxclients);
    return;
  }
                    /* Unresolved local var: int len@[???] */
  iVar3 = Q_strlen(PF_stuffcmd_I::szOut);
  pcVar1 = host_client;
  if ((iVar3 != 0) && (((&DAT_001113bf)[iVar3] == '\n' || ((&DAT_001113bf)[iVar3] == ';')))) {
    host_client = svs.clients + iVar2 + -1;
    Host_ClientCommands("%s",PF_stuffcmd_I::szOut);
    host_client = pcVar1;
    return;
  }
  Con_Printf("Tried to stuff bad command %s\n",PF_stuffcmd_I::szOut);
  return;
}


// PF_traceline_DLL  @ 0006e450
void PF_traceline_DLL(float *v1,float *v2,int fNoMonsters,edict_t *pentToSkip,TraceResult *ptr)

{
  trace_t local_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  if (pentToSkip == (edict_t *)0x0) {
    pentToSkip = sv.edicts;
  }
  SV_Move(&local_44,v1,vec3_origin,vec3_origin,v2,fNoMonsters,pentToSkip,false);
  gGlobalVariables.trace_flags = 0;
  gGlobalVariables.trace_allsolid = (float)local_44.allsolid;
  gGlobalVariables.trace_startsolid = (float)local_44.startsolid;
  gGlobalVariables.trace_fraction = local_44.fraction;
  gGlobalVariables.trace_endpos[0] = local_44.endpos[0];
  gGlobalVariables.trace_endpos[1] = local_44.endpos[1];
  gGlobalVariables.trace_plane_normal[0] = local_44.plane.normal[0];
  gGlobalVariables.trace_inwater = (float)local_44.inwater;
  gGlobalVariables.trace_plane_normal[1] = local_44.plane.normal[1];
  gGlobalVariables.trace_plane_normal[2] = local_44.plane.normal[2];
  gGlobalVariables.trace_endpos[2] = local_44.endpos[2];
  gGlobalVariables.trace_inopen = (float)local_44.inopen;
  gGlobalVariables.trace_plane_dist = local_44.plane.dist;
  if (local_44.ent == (edict_t *)0x0) {
    local_44.ent = sv.edicts;
  }
  gGlobalVariables.trace_hitgroup = local_44.hitgroup;
  gGlobalVariables.trace_ent = local_44.ent;
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


// PF_traceline_Shared  @ 0006e300
void PF_traceline_Shared(float *v1,float *v2,int nomonsters,edict_t *ent)

{
  trace_t local_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  SV_Move(&local_44,v1,vec3_origin,vec3_origin,v2,nomonsters,ent,false);
  gGlobalVariables.trace_flags = 0;
  gGlobalVariables.trace_allsolid = (float)local_44.allsolid;
  gGlobalVariables.trace_fraction = local_44.fraction;
  gGlobalVariables.trace_endpos[0] = local_44.endpos[0];
  gGlobalVariables.trace_endpos[1] = local_44.endpos[1];
  gGlobalVariables.trace_plane_normal[0] = local_44.plane.normal[0];
  gGlobalVariables.trace_startsolid = (float)local_44.startsolid;
  gGlobalVariables.trace_plane_normal[1] = local_44.plane.normal[1];
  gGlobalVariables.trace_plane_normal[2] = local_44.plane.normal[2];
  gGlobalVariables.trace_endpos[2] = local_44.endpos[2];
  gGlobalVariables.trace_inwater = (float)local_44.inwater;
  gGlobalVariables.trace_inopen = (float)local_44.inopen;
  gGlobalVariables.trace_plane_dist = local_44.plane.dist;
  if (local_44.ent == (edict_t *)0x0) {
    local_44.ent = sv.edicts;
  }
  gGlobalVariables.trace_ent = local_44.ent;
  gGlobalVariables.trace_hitgroup = local_44.hitgroup;
  return;
}


// PF_vectoangles_I  @ 0006e000
void PF_vectoangles_I(float *rgflVectorIn,float *rgflVectorOut)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
  fVar1 = 0.0;
  if ((rgflVectorIn[1] == 0.0) && (*rgflVectorIn == 0.0)) {
    if (rgflVectorIn[2] <= 0.0) {
      fVar2 = 270.0;
    }
    else {
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


// PF_vectoyaw_I  @ 0006df70
float PF_vectoyaw_I(float *rgflVector)

{
  float fVar1;
  double dVar2;
  
                    /* Unresolved local var: float yaw@[???] */
  if ((rgflVector[1] == 0.0) && (*rgflVector == 0.0)) {
    fVar1 = 0.0;
  }
  else {
    dVar2 = atan2((double)rgflVector[1],(double)*rgflVector);
    fVar1 = (float)(int)((dVar2 * 180.0) / 3.141592653589793);
    if (fVar1 < 0.0) {
      return fVar1 + 360.0;
    }
  }
  return fVar1;
}


// PF_walkmove_I  @ 00071c80
int PF_walkmove_I(edict_t *ent,float yaw,float dist,int iMode)

{
  qboolean qVar1;
  double local_2c;
  double local_24;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: int returnValue@[???] */
  qVar1 = false;
  if (((ent->v).flags & 0x203U) != 0) {
    sincos((double)((yaw * 3.1415927 + yaw * 3.1415927) / 360.0),&local_24,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = dist * (float)local_24;
    if (iMode == 1) {
      qVar1 = SV_movetest(ent,&local_18,true);
    }
    else {
      if (iMode == 2) {
        qVar1 = SV_movestep(ent,&local_18,false);
        return qVar1;
      }
      qVar1 = SV_movestep(ent,&local_18,true);
    }
  }
  return qVar1;
}


