// Host_AutoSave_f  @ 0007c500
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_AutoSave_f(void)

{
  int iVar1;
  ushort in_FPUStatusWord;
  longdouble lVar2;
  double dVar3;
  char local_ac [79];
  undefined1 local_5d;
  char local_5c [88];
  
                    /* Unresolved local var: char[80] szComment@[???]
                       Unresolved local var: char[80] szTemp@[???] */
  iVar1 = Host_ValidSave();
  if (iVar1 == 0) {
    return;
  }
                    /* Unresolved local var: char[80] szComment@[???]
                       Unresolved local var: char[80] szTemp@[???] */
  (*g_pSaveGameCommentFunc)(local_5c,0x50);
  lVar2 = (longdouble)sv.time;
  do {
    lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / (longdouble)60.0) * (longdouble)60.0;
  } while ((in_FPUStatusWord & 0x400) != 0);
  if (NAN(lVar2)) {
    dVar3 = fmod(sv.time,60.0);
    lVar2 = (longdouble)dVar3;
  }
  snprintf(local_ac,0x4f,"%-64.64s %02d:%02d",local_5c,(int)((float)sv.time / 60.0),(int)lVar2);
  local_5d = 0;
  SaveGameSlot("autosave",local_ac);
  return;
}


// Host_Career_f  @ 0007d9c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Career_f(void)

{
  int iVar1;
  char *str;
  
  if (cmd_source == src_command) {
    g_careerState = CAREER_LOADING;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[64] mapstring@[???]
                       Unresolved local var: CareerStateType careerState@[???]
                       Unresolved local var: char[64] name@[???] */
    iVar1 = Cmd_Argc();
    if (1 < iVar1) {
      str = Cmd_Args();
      iVar1 = Q_strlen(str);
      if (0x36 < iVar1) {
        Con_Printf("map change failed: command string is too long.\n");
        g_careerState = CAREER_NONE;
        return;
      }
    }
    iVar1 = Cmd_Argc();
    if (1 < iVar1) {
      CL_Disconnect();
      g_careerState = CAREER_LOADING;
      Host_Map_f();
      return;
    }
    Con_Printf("map <levelname> : changes server to specified map\n");
    g_careerState = CAREER_NONE;
  }
  return;
}


// Host_Changelevel2_f  @ 0007ca50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Changelevel2_f(void)

{
  int iVar1;
  char *pcVar2;
  char *src;
  SAVERESTOREDATA *p;
  char local_dc [63];
  undefined1 local_9d;
  char local_9c [63];
  undefined1 local_5d;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: char[64] level@[???]
                       Unresolved local var: char[64] oldlevel@[???]
                       Unresolved local var: char[64] _startspot@[???]
                       Unresolved local var: char * startspot@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: qboolean newUnit@[???] */
  giActive = 4;
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("changelevel2 <levelname> : continue game on a new level in the unit\n");
  }
  else if (((sv.active == false) || (cls.demoplayback != false)) || (sv.paused != false)) {
    Con_Printf("Only the server may changelevel\n");
  }
  else if (svs.maxclients < 2) {
                    /* Unresolved local var: char[64] level@[???]
                       Unresolved local var: char[64] oldlevel@[???]
                       Unresolved local var: char[64] _startspot@[???]
                       Unresolved local var: char * startspot@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: qboolean newUnit@[???] */
    SCR_BeginLoadingPlaque(true);
    S_StopAllSounds(true);
    pcVar2 = Cmd_Argv(1);
    Q_strncpy(local_dc,pcVar2,0x3f);
    local_9d = 0;
    iVar1 = Cmd_Argc();
    pcVar2 = (char *)0x0;
    if (iVar1 != 2) {
      src = Cmd_Argv(2);
      Q_strncpy(local_5c,src,0x3f);
      local_1d = 0;
      if (local_5c[0] != '\0') {
        pcVar2 = local_5c;
      }
    }
    Q_strncpy(local_9c,sv.name,0x3f);
    local_5d = 0;
    p = SaveGamestate();
    SV_ServerShutdown();
    FS_LogLevelLoadStarted(local_dc);
    iVar1 = SV_SpawnServer(false,local_dc,pcVar2);
    if (iVar1 == 0) {
      Sys_Error("Host_Changelevel2: Couldn\'t load map %s\n",local_dc);
    }
    else {
      if (p != (SAVERESTOREDATA *)0x0) {
        if (p->pTokens != (char **)0x0) {
          Mem_Free(p->pTokens);
          p->pTokens = (char **)0x0;
          p->tokenCount = 0;
        }
        Mem_Free(p);
        gGlobalVariables.pSaveData = (void *)0x0;
      }
      iVar1 = LoadGamestate(local_dc,0);
      if (iVar1 == 0) {
        SV_LoadEntities();
        LoadAdjacentEntities(local_9c,pcVar2);
        sv.paused = true;
        sv.loadgame = true;
        gGlobalVariables.time = (float)sv.time;
        if (sv_newunit.value != 0.0) {
          Host_ClearSaveDirectory();
        }
      }
      else {
        LoadAdjacentEntities(local_9c,pcVar2);
        sv.paused = true;
        sv.loadgame = true;
        gGlobalVariables.time = (float)sv.time;
      }
      SV_ActivateServer(0);
    }
  }
  else {
    Con_Printf("changelevel2 <levelname> : not for use with multiplayer games\n");
  }
  return;
}


// Host_Changelevel_f  @ 00076eb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Changelevel_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char local_8c [63];
  undefined1 local_4d;
  char local_4c [63];
  undefined1 local_d;
  
                    /* Unresolved local var: char[64] level@[???]
                       Unresolved local var: char[64] _startspot@[???]
                       Unresolved local var: char * startspot@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("changelevel <levelname> : continue game on a new level\n");
  }
  else if ((sv.active == false) || (cls.demoplayback != false)) {
    Con_Printf("Only the server may changelevel\n");
  }
  else {
    pcVar2 = Cmd_Argv(1);
    iVar1 = PF_IsMapValid_I(pcVar2);
    if (iVar1 == 0) {
      pcVar2 = Cmd_Argv(1);
      Con_Printf("changelevel failed: \'%s\' not found on server.\n",pcVar2);
    }
    else {
                    /* Unresolved local var: char[64] level@[???]
                       Unresolved local var: char[64] _startspot@[???]
                       Unresolved local var: char * startspot@[???] */
      pcVar3 = Cmd_Argv(1);
      pcVar2 = (char *)0x0;
      Q_strncpy(local_8c,pcVar3,0x3f);
      local_4d = 0;
      iVar1 = Cmd_Argc();
      if (iVar1 != 2) {
        pcVar3 = Cmd_Argv(2);
        pcVar2 = local_4c;
        Q_strncpy(pcVar2,pcVar3,0x3f);
        local_d = 0;
      }
      SCR_BeginLoadingPlaque(true);
      S_StopAllSounds(true);
      SV_InactivateClients();
      SV_ServerShutdown();
      SV_SpawnServer(false,local_8c,pcVar2);
      SV_LoadEntities();
      SV_ActivateServer(1);
    }
  }
  return;
}


// Host_CheckConnectionFailure  @ 000751e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_CheckConnectionFailure(void)

{
  if ((cls.state == ca_disconnected) && ((((byte)giSubState & 4) != 0 || (console.value == 0.0)))) {
    if (0 < Host_CheckConnectionFailure::frames) {
      Host_CheckConnectionFailure::frames = Host_CheckConnectionFailure::frames + -1;
      return;
    }
    giActive = 2;
  }
  Host_CheckConnectionFailure::frames = 5;
  return;
}


// Host_CheckDyanmicStructures  @ 00074b40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_CheckDyanmicStructures(void)

{
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if ((svs.clients != (client_s *)0x0) &&
     (iVar3 = 0, iVar1 = svs.maxclientslimit, pcVar2 = svs.clients, 0 < svs.maxclientslimit)) {
    do {
      if (pcVar2->frames != (client_frame_t *)0x0) {
        SV_ClearFrames(&pcVar2->frames);
        iVar1 = svs.maxclientslimit;
      }
      iVar3 = iVar3 + 1;
    } while ((iVar3 < iVar1) && (pcVar2 = pcVar2 + 1, pcVar2 != (client_s *)0x0));
  }
  return;
}


// Host_ClearClients  @ 00074350
void Host_ClearClients(qboolean bFramesOnly)

{
  netadr_t adr;
  int iVar1;
  client_t *pcVar2;
  client_frame_t *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: client_frame_t * frame@[???] */
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar4 = 0;
    pcVar2 = svs.clients;
    do {
      pcVar3 = pcVar2->frames;
      host_client = pcVar2;
      if ((pcVar3 != (client_frame_t *)0x0) && (0 < SV_UPDATE_BACKUP)) {
        iVar6 = 0;
        iVar5 = 0;
        while( true ) {
          pcVar3 = (client_frame_t *)((int)(pcVar3->clientdata).origin + iVar6 + -0xc);
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x1810;
          SV_ClearPacketEntities(pcVar3);
          *(undefined4 *)&pcVar3->senttime = 0;
          iVar1 = SV_UPDATE_BACKUP;
          *(undefined4 *)((int)&pcVar3->senttime + 4) = 0;
          pcVar2 = host_client;
          pcVar3->ping_time = -1.0;
          if (iVar1 <= iVar5) break;
          pcVar3 = pcVar2->frames;
        }
      }
      if ((pcVar2->netchan).remote_address.type != NA_UNUSED) {
                    /* Unresolved local var: netadr_t save@[???] */
        adr = (pcVar2->netchan).remote_address;
        Q_memset(&pcVar2->netchan,0,0x2414);
        Netchan_Setup(NS_SERVER,&host_client->netchan,adr,
                      ((int)host_client - (int)svs.clients >> 3) * -0x6d690de1,&host_client,
                      SV_GetFragmentSize);
        pcVar2 = host_client;
      }
      iVar4 = iVar4 + 1;
      COM_ClearCustomizationList(&pcVar2->customdata,false);
      pcVar2 = host_client + 1;
      host_client = pcVar2;
    } while (iVar4 < svs.maxclients);
  }
  if (bFramesOnly != false) {
    return;
  }
  host_client = svs.clients;
  if (0 < svs.maxclientslimit) {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      SV_ClearFrames(&host_client->frames);
      host_client = host_client + 1;
    } while (iVar4 < svs.maxclientslimit);
  }
  Q_memset(svs.clients,0,svs.maxclientslimit * 0x4ef8);
  SV_AllocClientFrames();
  return;
}


// Host_ClearGameState  @ 0007da50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_ClearGameState(void)

{
  S_StopAllSounds(true);
  Host_ClearSaveDirectory();
  if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007da70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEntityInterface.pfnResetGlobalState)();
    return;
  }
  return;
}


// Host_ClearMemory  @ 00074b90
void Host_ClearMemory(qboolean bQuiet)

{
  client_s *pcVar1;
  int iVar2;
  int iVar3;
  
  CM_FreePAS();
  SV_ClearEntities();
  if (bQuiet == false) {
    Con_DPrintf("Clearing memory\n");
  }
  D_FlushCaches();
  Mod_ClearAll();
  if (host_hunklevel != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
    if ((svs.clients != (client_s *)0x0) &&
       (iVar3 = 0, iVar2 = svs.maxclientslimit, pcVar1 = svs.clients, 0 < svs.maxclientslimit)) {
      do {
        if (pcVar1->frames != (client_frame_t *)0x0) {
          SV_ClearFrames(&pcVar1->frames);
          iVar2 = svs.maxclientslimit;
        }
        iVar3 = iVar3 + 1;
      } while ((iVar3 < iVar2) && (pcVar1 = pcVar1 + 1, pcVar1 != (client_s *)0x0));
    }
    Hunk_FreeToLowMark(host_hunklevel);
  }
  cls.signon = 0;
  SV_ClearCaches();
  Q_memset(&sv,0,0x4640c);
  CL_ClearClientState();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar2 = 0;
    pcVar1 = svs.clients;
    do {
      iVar2 = iVar2 + 1;
      COM_ClearCustomizationList(&pcVar1->customdata,false);
      SV_ClearResourceLists(pcVar1);
      pcVar1 = pcVar1 + 1;
    } while (iVar2 < svs.maxclients);
  }
  return;
}


// Host_ClearSaveDirectory  @ 0007c7f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_ClearSaveDirectory(void)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint *puVar4;
  uint *puVar5;
  uint local_110 [64];
  undefined1 auStack_d [5];
  
                    /* Unresolved local var: char[260] szName@[???]
                       Unresolved local var: char * pfn@[???] */
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf((char *)local_110,0x104,"%s",Host_SaveGameDirectory::szDirectory);
  puVar5 = local_110;
  do {
    puVar4 = puVar5;
    uVar1 = *puVar4 + 0xfefefeff & ~*puVar4;
    uVar2 = uVar1 & 0x80808080;
    puVar5 = puVar4 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar5 = (uint *)((int)puVar4 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat((char *)local_110,"*.HL?",
          (size_t)(auStack_d + -(int)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2)))));
  COM_FixSlashes((char *)local_110);
  pcVar3 = Sys_FindFirstPathID((char *)local_110,"GAMECONFIG");
  if (pcVar3 != (char *)0x0) {
    Sys_FindClose();
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    snprintf((char *)local_110,0x104,"%s",Host_SaveGameDirectory::szDirectory);
    COM_FixSlashes((char *)local_110);
    FS_CreateDirHierarchy((char *)local_110,"GAMECONFIG");
    puVar5 = local_110;
    do {
      puVar4 = puVar5;
      uVar1 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar2 = uVar1 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar2 == 0);
    if ((uVar1 & 0x8080) == 0) {
      puVar5 = (uint *)((int)puVar4 + 6);
      uVar2 = uVar2 >> 0x10;
    }
    strncat((char *)local_110,"*.HL?",
            (size_t)(auStack_d + -(int)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))
           );
    pcVar3 = Sys_FindFirstPathID((char *)local_110,"GAMECONFIG");
    while (pcVar3 != (char *)0x0) {
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
      snprintf((char *)local_110,0x104,"%s%s",Host_SaveGameDirectory::szDirectory,pcVar3);
      FS_RemoveFile((char *)local_110,"GAMECONFIG");
      pcVar3 = Sys_FindNext((char *)0x0);
    }
  }
  Sys_FindClose();
  return;
}


// Host_ClientCommands  @ 00074010
void Host_ClientCommands(char *fmt,...)

{
  char local_40c [1023];
  undefined1 local_d;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  if (host_client->fakeclient == false) {
    vsnprintf(local_40c,0x400,fmt,&stack0x00000008);
    local_d = 0;
    MSG_WriteByte(&(host_client->netchan).message,9);
    MSG_WriteString(&(host_client->netchan).message,local_40c);
  }
  return;
}


// Host_ComputeFPS  @ 00074f30
void Host_ComputeFPS(double frametime)

{
  rolling_fps = frametime * 0.4 + rolling_fps * 0.6;
  return;
}


// Host_Crash_f  @ 0007de70
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Crash_f(void)

{
                    /* Unresolved local var: int * p@[???] */
  _DAT_00000000 = 0xdeadbeef;
  return;
}


// Host_Demos_f  @ 0007db80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Demos_f(void)

{
  if (cls.state == ca_dedicated) {
    return;
  }
  if (cls.demonum != -1) {
    CL_Disconnect_f();
    Host_NextDemo();
    return;
  }
  cls.demonum = 0;
  CL_Disconnect_f();
  Host_NextDemo();
  return;
}


// Host_EndGame  @ 00074a00
void Host_EndGame(char *message,...)

{
  int iVar1;
  char local_40c [1028];
  
                    /* Unresolved local var: int oldn@[???]
                       Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  vsnprintf(local_40c,0x400,message,&stack0x00000008);
  Con_DPrintf("Host_EndGame: %s\n",local_40c);
  iVar1 = cls.demonum;
  if (sv.active != false) {
    Host_ShutdownServer(false);
  }
  cls.demonum = iVar1;
  if (cls.state == ca_dedicated) {
    Sys_Error("Host_EndGame: %s\n",local_40c);
  }
  iVar1 = cls.demonum;
  if (cls.demonum != -1) {
    CL_Disconnect_f();
    cls.demonum = iVar1;
    Host_NextDemo();
                    /* WARNING: Subroutine does not return */
    longjmp((__jmp_buf_tag *)host_enddemo,1);
  }
  CL_Disconnect();
  Cbuf_AddText("cd stop\n");
  Cbuf_Execute();
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Host_EndSection  @ 0007dd10
void Host_EndSection(char *pszSection)

{
  int iVar1;
  
  giSubState = 1;
  giActive = 2;
  giStateInfo = 1;
  if ((pszSection == (char *)0x0) || (*pszSection == '\0')) {
    Con_Printf(" endsection with no arguments\n");
  }
  else {
    iVar1 = Q_stricmp(pszSection,"_oem_end_training");
    if (iVar1 == 0) {
      giStateInfo = 1;
    }
    else {
      iVar1 = Q_stricmp(pszSection,"_oem_end_logo");
      if (iVar1 == 0) {
        giStateInfo = 2;
      }
      else {
        iVar1 = Q_stricmp(pszSection,"_oem_end_demo");
        if (iVar1 == 0) {
          giStateInfo = 3;
        }
        else {
          Con_DPrintf(" endsection with unknown Section keyvalue\n");
        }
      }
    }
  }
  Cbuf_AddText("\ndisconnect\n");
  return;
}


// Host_Error  @ 000748f0
void Host_Error(char *error,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  if (Host_Error::inerror != false) {
    Sys_Error("Host_Error: recursively entered");
  }
  Host_Error::inerror = true;
  SCR_EndLoadingPlaque();
  vsnprintf(local_40c,0x400,error,&stack0x00000008);
  if ((sv.active == false) && (developer.value != 0.0)) {
    CL_WriteMessageHistory(0,0);
  }
  Con_Printf("Host_Error: %s\n",local_40c);
  if (sv.active != false) {
    Host_ShutdownServer(false);
  }
  if (cls.state == ca_dedicated) {
    Sys_Error("Host_Error: %s\n",local_40c);
  }
  CL_Disconnect();
  cls.demonum = -1;
  Host_Error::inerror = false;
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Host_FilterTime  @ 00074cb0
qboolean Host_FilterTime(float time)

{
  float fVar1;
  double dVar2;
  int iVar3;
  double dVar4;
  
                    /* Unresolved local var: float fps@[???] */
  if (0.0 < host_framerate.value) {
    iVar3 = cl.maxclients;
    if (sv.active != false) {
      iVar3 = svs.maxclients;
    }
    if ((iVar3 == 1) || (cls.demoplayback != false)) {
      host_frametime = (double)(host_framerate.value * sys_timescale.value);
      realtime = (double)((float)realtime + host_framerate.value * sys_timescale.value);
      return true;
    }
  }
  realtime = (double)time * (double)sys_timescale.value + realtime;
  if (g_bIsDedicatedServer == false) {
    if (((sv.active == false) && (cls.state != ca_disconnected)) && (cls.state != ca_active)) {
      dVar4 = 31.0;
    }
    else {
      dVar4 = 0.5;
      if (0.5 <= (double)fps_max.value) {
        dVar4 = (double)fps_max.value;
      }
    }
    if ((fps_override.value == 0.0) && (100.0 < dVar4)) {
      dVar4 = 100.0;
    }
    dVar2 = dVar4;
    if ((1 < cl.maxclients) && (dVar2 = 20.0, 20.0 <= dVar4)) {
      dVar2 = dVar4;
    }
    dVar4 = realtime - oldrealtime;
    if ((cls.timedemo == false) && (dVar4 < (double)sys_timescale.value / (dVar2 + 0.5))) {
      return false;
    }
  }
  else {
    if (Host_FilterTime::lexical_block_1::command_line_ticrate == -1) {
      Host_FilterTime::lexical_block_1::command_line_ticrate = COM_CheckParm("-sys_ticrate");
    }
    fVar1 = sys_ticrate.value;
    if (0 < Host_FilterTime::lexical_block_1::command_line_ticrate) {
      dVar4 = strtod(com_argv[Host_FilterTime::lexical_block_1::command_line_ticrate + 1],
                     (char **)0x0);
      fVar1 = (float)dVar4;
    }
    dVar4 = realtime - oldrealtime;
    if ((0.0 < (double)fVar1) && (dVar4 < 1.0 / ((double)fVar1 + 1.0))) {
      return false;
    }
  }
  host_frametime = dVar4;
  if (0.25 < host_frametime) {
    host_frametime = 0.25;
  }
  oldrealtime = realtime;
  return true;
}


// Host_FindRecentSave  @ 00079330
char * Host_FindRecentSave(char *pNameBuf,int nNameBufSize)

{
  bool bVar1;
  bool bVar2;
  char *str;
  int iVar3;
  int32 iVar4;
  int local_230;
  char local_224 [260];
  char local_120 [272];
  
                    /* Unresolved local var: char * findfn@[???]
                       Unresolved local var: char[260] basefilename@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: int32 newest@[???]
                       Unresolved local var: int32 ft@[???]
                       Unresolved local var: char[260] szPath@[???] */
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(pNameBuf,nNameBufSize,"%s*.sav",Host_SaveGameDirectory::szDirectory);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(local_120,0x104,"%s",Host_SaveGameDirectory::szDirectory);
  str = Sys_FindFirst(pNameBuf,local_224);
  if (str == (char *)0x0) {
    Sys_FindClose();
    pNameBuf = (char *)0x0;
  }
  else {
    bVar1 = false;
    do {
      while ((iVar3 = Q_strlen(str), bVar2 = bVar1, iVar3 == 0 ||
             (iVar3 = Q_strcasecmp(str,"HLSave.sav"), iVar3 == 0))) {
LAB_00079428:
        bVar1 = bVar2;
        str = Sys_FindNext(local_224);
        if (str == (char *)0x0) goto LAB_00079520;
      }
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
      snprintf(local_120,0x104,"%s%s",Host_SaveGameDirectory::szDirectory,str);
      iVar4 = FS_GetFileTime(local_120);
      if ((iVar4 < 1) || ((iVar4 <= local_230 && (bVar2 = true, bVar1)))) goto LAB_00079428;
      Q_strcpy(pNameBuf,str);
      bVar1 = true;
      str = Sys_FindNext(local_224);
      local_230 = iVar4;
    } while (str != (char *)0x0);
LAB_00079520:
    Sys_FindClose();
    if (!bVar1) {
      pNameBuf = (char *)0x0;
    }
  }
  return pNameBuf;
}


// Host_Fly_f  @ 00076700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Fly_f(void)

{
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (gGlobalVariables.deathmatch == 0.0) {
    if ((sv_player->v).movetype == 5) {
      (sv_player->v).movetype = 3;
      SV_ClientPrintf("flymode OFF\n");
      return;
    }
    (sv_player->v).movetype = 5;
    SV_ClientPrintf("flymode ON\n");
  }
  return;
}


// Host_Frame  @ 00075640
int Host_Frame(float time,int iState,int *stateInfo)

{
  double dVar1;
  int iVar2;
  int iVar3;
  client_s *pcVar4;
  int iVar5;
  double local_24;
  double local_1c;
  
                    /* Unresolved local var: double time1@[???]
                       Unresolved local var: double time2@[???] */
  iVar2 = _setjmp((__jmp_buf_tag *)host_abortserver);
  if (iVar2 == 0) {
    if ((giActive != 3) || (g_iQuitCommandIssued == 0)) {
      giActive = iState;
    }
    *stateInfo = 0;
    if (host_profile.value != 0.0) {
      local_24 = Sys_FloatTime();
    }
    _Host_Frame(time);
    if (host_profile.value != 0.0) {
      local_1c = Sys_FloatTime();
    }
    if (giStateInfo != 0) {
      *stateInfo = giStateInfo;
      giStateInfo = 0;
      Cbuf_Execute();
    }
    if (host_profile.value != 0.0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int m@[???] */
      Host_Frame::lexical_block_0::timetotal =
           (local_1c - local_24) + Host_Frame::lexical_block_0::timetotal;
      iVar2 = Host_Frame::lexical_block_0::timecount + 1;
      Host_Frame::lexical_block_0::timecount = iVar2;
      if (999 < iVar2) {
        dVar1 = Host_Frame::lexical_block_0::timetotal * 1000.0;
        Host_Frame::lexical_block_0::timecount = 0;
        iVar3 = 0;
        Host_Frame::lexical_block_0::timetotal = 0.0;
        if (0 < svs.maxclients) {
          iVar5 = 0;
          pcVar4 = svs.clients;
          do {
            if (pcVar4->active != false) {
              iVar3 = iVar3 + 1;
            }
            iVar5 = iVar5 + 1;
            pcVar4 = pcVar4 + 1;
          } while (iVar5 != svs.maxclients);
        }
        Con_Printf("host_profile: %2i clients %2i msec\n",iVar3,(int)(dVar1 / (double)iVar2));
      }
    }
  }
  return giActive;
}


// Host_FullInfo_f  @ 00076b80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_FullInfo_f(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char local_40c [511];
  undefined1 uStack_20d;
  char local_20c [516];
  
                    /* Unresolved local var: char[512] key@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: int i@[???] */
  pcVar3 = Cmd_Argv(1);
  cVar1 = *pcVar3;
  if (cVar1 == '\\') {
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 1;
  }
  do {
    if (cVar1 == '\0') {
      return;
    }
    if ((cVar1 == '\\') || (cVar1 == '\0')) {
      iVar4 = 0;
LAB_00076bf1:
      local_40c[iVar4] = '\0';
      cVar1 = *pcVar3;
    }
    else {
      iVar4 = 1;
      pcVar6 = pcVar3 + 1;
      pcVar5 = pcVar3 + 0x1ff;
      do {
        cVar2 = *pcVar6;
        pcVar3 = pcVar6;
        local_40c[0] = cVar1;
        if ((cVar2 == '\\') || (cVar2 == '\0')) goto LAB_00076bf1;
        pcVar6 = pcVar6 + 1;
        local_40c[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
      } while (pcVar6 != pcVar5);
      uStack_20d = 0;
      cVar1 = *pcVar6;
      pcVar3 = pcVar6;
    }
    if (cVar1 == '\0') {
      Con_Printf("MISSING VALUE\n");
      return;
    }
    cVar1 = pcVar3[1];
    if ((cVar1 == '\\') || (cVar1 == '\0')) {
      pcVar6 = pcVar3 + 1;
      iVar4 = 0;
    }
    else {
      pcVar6 = pcVar3 + 2;
      iVar4 = 1;
      do {
        cVar2 = *pcVar6;
        local_20c[0] = cVar1;
        if ((cVar2 == '\\') || (cVar2 == '\0')) goto LAB_00076c51;
        pcVar6 = pcVar6 + 1;
        local_20c[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
      } while (pcVar6 != pcVar3 + 0x200);
      iVar4 = 0x1ff;
    }
LAB_00076c51:
    local_20c[iVar4] = '\0';
    pcVar3 = pcVar6 + (*pcVar6 != '\0');
    if (cmd_source == src_command) {
      Info_SetValueForKey(cls.userinfo,local_40c,local_20c,0x100);
      Cmd_ForwardToServer();
      return;
    }
    Info_SetValueForKey(host_client->userinfo,local_40c,local_20c,0x100);
    host_client->sendinfo = true;
    cVar1 = *pcVar3;
  } while( true );
}


// Host_FullInfo_f  @ 00076d30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_FullInfo_f(void)

{
  int iVar1;
  
                    /* Unresolved local var: char[512] key@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("fullinfo <complete info string>\n");
    return;
  }
  Host_FullInfo_f();
  return;
}


// Host_GetHostInfo  @ 00074f50
void Host_GetHostInfo(float *fps,int *nActive,int *unused,int *nMaxPlayers,char *pszMap)

{
  int local_1c [5];
  
                    /* Unresolved local var: int clients@[???] */
  local_1c[0] = 0;
  if (0.0 < (float)rolling_fps) {
    *fps = 1.0 / (float)rolling_fps;
  }
  else {
    rolling_fps = 0.0;
    *fps = 0.0;
  }
  SV_CountPlayers(local_1c);
  *nActive = local_1c[0];
  if (unused != (int *)0x0) {
    *unused = 0;
  }
  if (pszMap != (char *)0x0) {
    if (sv.name[0] == '\0') {
      *pszMap = '\0';
    }
    else {
      Q_strcpy(pszMap,sv.name);
    }
  }
  *nMaxPlayers = svs.maxclients;
  return;
}


// Host_GetMaxClients  @ 000758e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Host_GetMaxClients(void)

{
  int iVar1;
  
  iVar1 = cl.maxclients;
  if (sv.active != false) {
    iVar1 = svs.maxclients;
  }
  return iVar1;
}


// Host_GetStartTime  @ 00077e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long Host_GetStartTime(void)

{
  return startTime;
}


// Host_GetVideoLevel  @ 0006e240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Host_GetVideoLevel(void)

{
  int iVar1;
  
                    /* Unresolved local var: int vid_level@[???] */
  iVar1 = (*registry->_vptr_IRegistry[2])(registry,"vid_level",0);
  return iVar1;
}


// Host_God_f  @ 000767e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_God_f(void)

{
  uint uVar1;
  
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if ((gGlobalVariables.deathmatch == 0.0) && (sv_cheats.value != 0.0)) {
    uVar1 = (sv_player->v).flags ^ 0x40;
    (sv_player->v).flags = uVar1;
    if ((uVar1 & 0x40) == 0) {
      SV_ClientPrintf("godmode OFF\n");
      return;
    }
    SV_ClientPrintf("godmode ON\n");
  }
  return;
}


// Host_Init  @ 00075bc0
int Host_Init(quakeparms_t_conflict *parms)

{
  uchar *puVar1;
  uint uVar2;
  int iVar3;
  uchar *puVar4;
  char local_18c [256];
  undefined1 local_8c [132];
  
                    /* Unresolved local var: char[256] versionString@[???] */
  uVar2 = time((time_t *)0x0);
  srand(uVar2);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)&host_parms.basedir + uVar2) =
         *(undefined4 *)((int)&parms->basedir + uVar2);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x18);
  com_argc = parms->argc;
  realtime._4_4_ = 0;
  com_argv = parms->argv;
  realtime._0_4_ = 0;
  Memory_Init(parms->membase,parms->memsize);
  Voice_RegisterCvars();
  Cvar_RegisterVariable(&console);
  iVar3 = COM_CheckParm("-console");
  if (((iVar3 != 0) || (iVar3 = COM_CheckParm("-toconsole"), iVar3 != 0)) ||
     (iVar3 = COM_CheckParm("-dev"), iVar3 != 0)) {
    Cvar_DirectSet(&console,"1.0");
  }
  Host_InitLocal();
  iVar3 = COM_CheckParm("-dev");
  if (iVar3 != 0) {
    Cvar_SetValue("developer",1.0);
  }
  Cbuf_Init();
  Cmd_Init();
  Cvar_Init();
  Cvar_CmdInit();
  V_Init();
  Chase_Init();
  COM_Init(parms->basedir);
  Host_ClearSaveDirectory();
  HPAK_Init();
  W_LoadWadFile("gfx.wad");
  W_LoadWadFile("fonts.wad");
  Key_Init();
  Con_Init();
  Decal_Init();
  Mod_Init();
  NET_Init();
  Netchan_Init();
  DELTA_Init();
  SV_Init();
  SystemWrapper_Init();
  Host_Version();
  iVar3 = build_number();
  snprintf(local_18c,0x100,"%s,%i,%i",gpszVersionString,0x30,iVar3);
  Cvar_Set("sv_version",local_18c);
  Con_DPrintf("%4.1f Mb heap\n",(double)((float)parms->memsize * 9.536743e-07));
  R_InitTextures();
  HPAK_CheckIntegrity("custom");
  Q_memset(&g_module,0,0x14);
  if (cls.state == ca_dedicated) {
    Cvar_RegisterVariable(&suitvolume);
  }
  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * disk_basepal@[???] */
    puVar4 = COM_LoadHunkFile("gfx/palette.lmp");
    if (puVar4 == (uchar *)0x0) {
      Sys_Error("Host_Init: Couldn\'t load gfx/palette.lmp");
    }
    puVar4 = puVar4 + 2;
    host_basepal = Hunk_AllocName(0x800,"palette.lmp");
    iVar3 = 0;
    do {
      *(short *)((int)host_basepal + iVar3) = (short)(char)*puVar4;
      *(short *)((int)host_basepal + iVar3 + 2) = (short)(char)puVar4[-1];
      puVar1 = puVar4 + -2;
      puVar4 = puVar4 + 3;
      *(short *)((int)host_basepal + iVar3 + 4) = (short)(char)*puVar1;
      *(undefined2 *)((int)host_basepal + iVar3 + 6) = 0;
      iVar3 = iVar3 + 8;
    } while (iVar3 != 0x800);
    CL_InitEventSystem();
    ClientDLL_Init();
    iVar3 = VID_Init(host_basepal);
    if (iVar3 == 0) {
      return 0;
    }
    Draw_Init();
    SCR_Init();
    R_Init();
    CL_Init();
  }
  Cbuf_InsertText("exec valve.rc\n");
  Hunk_AllocName(0,"-HOST_HUNKLEVEL-");
  host_hunklevel = Hunk_LowMark();
  giActive = 1;
  scr_skipupdate = false;
                    /* Unresolved local var: char[128] szSubKey@[???]
                       Unresolved local var: int nBufferLen@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: qboolean bGore@[???] */
  Q_memset(local_8c,0,0x80);
  if (bLowViolenceBuild == false) {
    Cvar_SetValue("violence_hblood",1.0);
    Cvar_SetValue("violence_hgibs",1.0);
    Cvar_SetValue("violence_ablood",1.0);
    Cvar_SetValue("violence_agibs",1.0);
  }
  else {
    Cvar_SetValue("violence_hblood",0.0);
    Cvar_SetValue("violence_hgibs",0.0);
    Cvar_SetValue("violence_ablood",0.0);
    Cvar_SetValue("violence_agibs",0.0);
  }
  host_initialized = true;
  return 1;
}


// Host_InitCommands  @ 0007de80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InitCommands(void)

{
  Cmd_AddCommand("shutdownserver",Host_KillServer_f);
  Cmd_AddCommand("soundfade",Host_Soundfade_f);
  Cmd_AddCommand("status",Host_Status_f);
  Cmd_AddCommand("stat",Host_Status_Formatted_f);
  Cmd_AddCommandWithFlags("quit",Host_Quit_f,8);
  Cmd_AddCommand("exit",Host_Quit_f);
  Cmd_AddCommand("map",Host_Map_f);
  Cmd_AddCommand("career",Host_Career_f);
  Cmd_AddCommand("maps",Host_Maps_f);
  Cmd_AddCommand("restart",Host_Restart_f);
  Cmd_AddCommand("reload",Host_Reload_f);
  Cmd_AddCommand("changelevel",Host_Changelevel_f);
  Cmd_AddCommand("changelevel2",Host_Changelevel2_f);
  Cmd_AddCommand("reconnect",Host_Reconnect_f);
  Cmd_AddCommand("version",Host_Version_f);
  Cmd_AddCommandWithFlags("say",Host_Say_f,0x10);
  Cmd_AddCommand("say_team",Host_Say_Team_f);
  Cmd_AddCommand("tell",Host_Tell_f);
  Cmd_AddCommandWithFlags("kill",Host_Kill_f,8);
  Cmd_AddCommand("pause",Host_TogglePause_f);
  Cmd_AddCommand("setpause",Host_Pause_f);
  Cmd_AddCommand("unpause",Host_Unpause_f);
  Cmd_AddCommand("kick",Host_Kick_f);
  Cmd_AddCommand("ping",Host_Ping_f);
  Cmd_AddCommandWithFlags("motd",Host_Motd_f,8);
  Cmd_AddCommandWithFlags("motd_write",Host_Motd_Write_f,8);
  Cmd_AddCommand("stats",Host_Stats_f);
  Cmd_AddCommand("load",Host_Loadgame_f);
  Cmd_AddCommand("save",Host_Savegame_f);
  Cmd_AddCommand("autosave",Host_AutoSave_f);
  Cmd_AddCommandWithFlags("writecfg",Host_WriteCustomConfig,8);
  Cmd_AddCommand("startdemos",Host_Startdemos_f);
  Cmd_AddCommand("demos",Host_Demos_f);
  Cmd_AddCommand("stopdemo",Host_Stopdemo_f);
  Cmd_AddCommandWithFlags("setinfo",Host_SetInfo_f,0x10);
  Cmd_AddCommand("fullinfo",Host_FullInfo_f);
  Cmd_AddCommand("god",Host_God_f);
  Cmd_AddCommand("notarget",Host_Notarget_f);
  Cmd_AddCommand("fly",Host_Fly_f);
  Cmd_AddCommand("noclip",Host_Noclip_f);
  Cmd_AddCommand("mcache",Mod_Print);
  Cmd_AddCommand("interp",Host_Interp_f);
  Cmd_AddCommand("setmaster",Master_SetMaster_f);
  Cmd_AddCommand("heartbeat",Master_Heartbeat_f);
  Cvar_RegisterVariable(&gHostMap);
  Cvar_RegisterVariable(&voice_recordtofile);
  Cvar_RegisterVariable(&voice_inputfromfile);
  return;
}


// Host_InitLocal  @ 00073bb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InitLocal(void)

{
  Host_InitCommands();
  Cvar_RegisterVariable(&host_killtime);
  Cvar_RegisterVariable(&sys_ticrate);
  Cvar_RegisterVariable(&fps_max);
  Cvar_RegisterVariable(&fps_override);
  Cvar_RegisterVariable(&host_name);
  Cvar_RegisterVariable(&host_limitlocal);
  sys_timescale.value = 1.0;
  Cvar_RegisterVariable(&host_framerate);
  Cvar_RegisterVariable(&host_speeds);
  Cvar_RegisterVariable(&host_profile);
  Cvar_RegisterVariable(&mp_logfile);
  Cvar_RegisterVariable(&mp_logecho);
  Cvar_RegisterVariable(&sv_log_onefile);
  Cvar_RegisterVariable(&sv_log_singleplayer);
  Cvar_RegisterVariable(&sv_logsecret);
  Cvar_RegisterVariable(&sv_stats);
  Cvar_RegisterVariable(&developer);
  Cvar_RegisterVariable(&deathmatch);
  Cvar_RegisterVariable(&coop);
  Cvar_RegisterVariable(&pausable);
  Cvar_RegisterVariable(&skill);
  SV_SetMaxclients();
  return;
}


// Host_InitializeGameDLL  @ 00077bb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InitializeGameDLL(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  SV_SAVEGAMECOMMENT_FUNC p_Var4;
  extensiondll_t *peVar5;
  extensiondll_t *peVar6;
  
                    /* Unresolved local var: char[10] szInsecure@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iResult@[???] */
  svs.dll_initialized = true;
  LoadEntityDLLs(host_parms.basedir);
  (*gEntityInterface.pfnGameInit)();
  (*gEntityInterface.pfnPM_Init)(&g_svmove);
  (*gEntityInterface.pfnRegisterEncoders)();
  SV_InitEncoders();
  iVar1 = (*gEntityInterface.pfnGetHullBounds)(0,player_mins[0],player_maxs[0]);
  if (((iVar1 != 0) &&
      (iVar1 = (*gEntityInterface.pfnGetHullBounds)(1,player_mins[1],player_maxs[1]), iVar1 != 0))
     && (iVar1 = (*gEntityInterface.pfnGetHullBounds)(2,player_mins[2],player_maxs[2]), iVar1 != 0))
  {
    (*gEntityInterface.pfnGetHullBounds)(3,player_mins[3],player_maxs[3]);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SV_BLENDING_INTERFACE_FUNC studio_interface@[???] */
  R_ResetSvBlending();
  p_Var4 = g_pSaveGameCommentFunc;
  if (0 < g_iextdllMac) {
    peVar6 = g_rgextdll;
    iVar1 = 0;
    peVar5 = g_rgextdll;
    do {
      pcVar2 = (code *)dlsym(peVar5->lDLLHandle,"Server_GetBlendingInterface");
      if (pcVar2 != (code *)0x0) {
        iVar3 = (*pcVar2)(1,&g_pSvBlendingAPI,&server_studio_api,rotationmatrix,bonetransform);
        if (iVar3 != 0) break;
        Con_DPrintf("Couldn\'t get server .dll studio model blending interface. Version mismatch?\n"
                   );
        R_ResetSvBlending();
      }
      iVar1 = iVar1 + 1;
      peVar5 = peVar5 + 1;
    } while (iVar1 < g_iextdllMac);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pszFunction@[???]
                       Unresolved local var: SV_SAVEGAMECOMMENT_FUNC pTemp@[???] */
    p_Var4 = g_pSaveGameCommentFunc;
    if (0 < g_iextdllMac) {
      iVar1 = 0;
      do {
        p_Var4 = (SV_SAVEGAMECOMMENT_FUNC)dlsym(peVar6->lDLLHandle,"SV_SaveGameComment");
        if (p_Var4 != (SV_SAVEGAMECOMMENT_FUNC)0x0) break;
        iVar1 = iVar1 + 1;
        peVar6 = peVar6 + 1;
        p_Var4 = g_pSaveGameCommentFunc;
      } while (iVar1 < g_iextdllMac);
    }
  }
  g_pSaveGameCommentFunc = p_Var4;
  Cbuf_Execute();
  return;
}


// Host_InitializeGameDLL  @ 00077dd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InitializeGameDLL(void)

{
                    /* Unresolved local var: char[10] szInsecure@[???] */
  Cbuf_Execute();
  NET_Config((uint)(1 < svs.maxclients));
  if (svs.dll_initialized == false) {
    Host_InitializeGameDLL();
    return;
  }
  Con_DPrintf("Sys_InitializeGameDLL called twice, skipping second call\n");
  return;
}


// Host_Interp_f  @ 000761b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Interp_f(void)

{
  r_dointerp = (int)(r_dointerp == 0);
  if (r_dointerp != 0) {
    Con_Printf("Frame Interpolation ON\n");
    return;
  }
  Con_Printf("Frame Interpolation OFF\n");
  return;
}


// Host_IsServerActive  @ 00075900
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Host_IsServerActive(void)

{
  return sv.active;
}


// Host_IsSinglePlayerGame  @ 000758c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Host_IsSinglePlayerGame(void)

{
  int iVar1;
  
  iVar1 = cl.maxclients;
  if (sv.active != false) {
    iVar1 = svs.maxclients;
  }
  return (uint)(iVar1 == 1);
}


// Host_Kick_f  @ 000abc10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Kick_f(void)

{
  bool bVar1;
  client_t *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  size_t sVar8;
  client_t *pcVar9;
  int iVar10;
  uint uVar11;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * who@[???]
                       Unresolved local var: char * message@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean byNumber@[???]
                       Unresolved local var: char[64] idstring@[???]
                       Unresolved local var: qboolean isSteam@[???]
                       Unresolved local var: int argsStartNum@[???] */
  iVar3 = Cmd_Argc();
  pcVar2 = host_client;
  if (iVar3 < 2) {
    Con_Printf("usage:  kick < name > | < # userid >\n");
    return;
  }
  if (cmd_source == src_command) {
    if (sv.active == false) {
      Cmd_ForwardToServer();
      return;
    }
  }
  else if ((host_client->netchan).remote_address.type != NA_LOOPBACK) {
    SV_ClientPrintf("You can\'t \'kick\' because you are not a server operator\n");
    return;
  }
  pcVar4 = Cmd_Argv(1);
  if ((pcVar4 == (char *)0x0) || (*pcVar4 != '#')) {
    if (svs.maxclients < 1) {
      host_client = pcVar2;
      return;
    }
    iVar10 = 0;
    host_client = svs.clients;
    iVar3 = svs.maxclients;
    do {
      if ((host_client->active != false) || (host_client->connected != false)) {
        pcVar4 = Cmd_Argv(1);
        iVar5 = Q_strcasecmp(host_client->name,pcVar4);
        iVar3 = svs.maxclients;
        if (iVar5 == 0) {
          local_60 = 2;
          bVar1 = false;
          goto LAB_000abd29;
        }
      }
      iVar10 = iVar10 + 1;
      host_client = host_client + 1;
      if (iVar3 <= iVar10) {
        host_client = pcVar2;
        return;
      }
    } while( true );
  }
                    /* Unresolved local var: int searchid@[???] */
  iVar3 = Cmd_Argc();
  if ((iVar3 < 3) || (pcVar4[1] != '\0')) {
    pcVar4 = pcVar4 + 1;
    iVar3 = 6;
    local_6c = Q_atoi(pcVar4);
    local_64 = 3;
    local_68 = 5;
    local_60 = 2;
  }
  else {
    iVar3 = 7;
    pcVar4 = Cmd_Argv(2);
    local_6c = Q_atoi(pcVar4);
    pcVar4 = Cmd_Argv(2);
    local_64 = 4;
    local_68 = 6;
    local_60 = 3;
  }
  strncpy(local_5c,pcVar4,0x3f);
  local_1d = 0;
  iVar10 = Q_strnicmp(local_5c,"STEAM_",6);
  if ((iVar10 == 0) || (iVar10 = Q_strnicmp(local_5c,"VALVE_",6), iVar10 == 0)) {
    pcVar6 = Cmd_Argv(local_68);
    pcVar7 = Cmd_Argv(local_64);
    snprintf(local_5c,0x3f,"%s:%s:%s",pcVar4,pcVar7,pcVar6);
    local_1d = 0;
    bVar1 = true;
    local_60 = iVar3;
  }
  else {
    bVar1 = false;
  }
  if (svs.maxclients < 1) {
    host_client = pcVar2;
    return;
  }
  iVar10 = 0;
  host_client = svs.clients;
  iVar3 = svs.maxclients;
  if (local_6c == 0) {
    do {
      if ((host_client->active != false) || (host_client->connected != false)) {
        SV_GetClientIDString::idstr[0] = '\0';
        if (((host_client->netchan).remote_address.type == NA_LOOPBACK) &&
           ((host_client->network_userid).idtype == 2)) {
          snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
        }
        else {
          pcVar4 = SV_GetIDString(&host_client->network_userid);
          snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar4);
        }
        iVar5 = Q_stricmp(SV_GetClientIDString::idstr,local_5c);
        iVar3 = svs.maxclients;
        if (iVar5 == 0) goto LAB_000abd29;
      }
      iVar10 = iVar10 + 1;
      host_client = host_client + 1;
      if (iVar3 <= iVar10) {
        host_client = pcVar2;
        return;
      }
    } while( true );
  }
  do {
    if ((host_client->active != false) || (host_client->connected != false)) {
      if (host_client->userid == local_6c) {
LAB_000abd29:
        if (iVar10 < iVar3) {
          pcVar4 = pcVar2->name;
          if (cmd_source == src_command) {
            pcVar4 = "Console";
          }
          if ((host_client->netchan).remote_address.type == NA_LOOPBACK) {
            Con_Printf("The local player cannot be kicked!\n");
            pcVar2 = host_client;
          }
          else {
            iVar3 = Cmd_Argc();
            if (local_60 < iVar3) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int dataLen@[???] */
              pcVar6 = Cmd_Args();
              uVar11 = 0;
              iVar3 = 1;
              do {
                iVar10 = iVar3 + 1;
                pcVar7 = Cmd_Argv(iVar3);
                sVar8 = strlen(pcVar7);
                uVar11 = uVar11 + 1 + sVar8;
                iVar3 = iVar10;
              } while (iVar10 < local_60);
              if (bVar1) {
                uVar11 = uVar11 - 4;
              }
              sVar8 = strlen(pcVar6);
              if ((uVar11 <= sVar8) && (pcVar6 = pcVar6 + uVar11, pcVar6 != (char *)0x0)) {
                SV_ClientPrintf("Kicked by %s: %s\n",pcVar4,pcVar6);
                SV_GetClientIDString::idstr[0] = '\0';
                pcVar9 = (client_t *)0x0;
                if (host_client != (client_t *)0x0) {
                  if (((host_client->netchan).remote_address.type == NA_LOOPBACK) &&
                     ((host_client->network_userid).idtype == 2)) {
                    snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
                    pcVar9 = host_client;
                  }
                  else {
                    /* Unresolved local var: USERID_t * id@[???] */
                    pcVar7 = SV_GetIDString(&host_client->network_userid);
                    snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar7);
                    pcVar9 = host_client;
                  }
                }
                Log_Printf("Kick: \"%s<%i><%s><>\" was kicked by \"%s\" (message \"%s\")\n",
                           pcVar9->name,pcVar9->userid,SV_GetClientIDString::idstr,pcVar4,pcVar6);
                pcVar4 = va("Kicked :%s",pcVar6);
                SV_DropClient(host_client,false,pcVar4);
                host_client = pcVar2;
                return;
              }
            }
            SV_ClientPrintf("Kicked by %s\n",pcVar4);
            SV_GetClientIDString::idstr[0] = '\0';
            pcVar9 = (client_t *)0x0;
            if (host_client != (client_t *)0x0) {
              if (((host_client->netchan).remote_address.type == NA_LOOPBACK) &&
                 ((host_client->network_userid).idtype == 2)) {
                snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
                pcVar9 = host_client;
              }
              else {
                    /* Unresolved local var: USERID_t * id@[???] */
                pcVar6 = SV_GetIDString(&host_client->network_userid);
                snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar6);
                pcVar9 = host_client;
              }
            }
            Log_Printf("Kick: \"%s<%i><%s><>\" was kicked by \"%s\"\n",pcVar9->name,pcVar9->userid,
                       SV_GetClientIDString::idstr,pcVar4);
            SV_DropClient(host_client,false,"Kicked");
          }
        }
        host_client = pcVar2;
        return;
      }
      SV_GetClientIDString::idstr[0] = '\0';
      if (((host_client->netchan).remote_address.type == NA_LOOPBACK) &&
         ((host_client->network_userid).idtype == 2)) {
        snprintf(SV_GetClientIDString::idstr,0x3f,"VALVE_ID_LOOPBACK");
      }
      else {
                    /* Unresolved local var: USERID_t * id@[???] */
        pcVar4 = SV_GetIDString(&host_client->network_userid);
        snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar4);
      }
      iVar5 = Q_stricmp(SV_GetClientIDString::idstr,local_5c);
      iVar3 = svs.maxclients;
      if (iVar5 == 0) goto LAB_000abd29;
    }
    iVar10 = iVar10 + 1;
    host_client = host_client + 1;
    if (iVar3 <= iVar10) {
      host_client = pcVar2;
      return;
    }
  } while( true );
}


// Host_KillServer_f  @ 00076160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_KillServer_f(void)

{
  if (cls.state != ca_dedicated) {
    CL_Disconnect_f();
    return;
  }
  if (sv.active != false) {
    Host_ShutdownServer(false);
    if (cls.state != ca_dedicated) {
      NET_Config(false);
      return;
    }
  }
  return;
}


// Host_KillVoice_f  @ 0007da80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_KillVoice_f(void)

{
  return;
}


// Host_Kill_f  @ 00076670
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Kill_f(void)

{
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (0.0 < (sv_player->v).health) {
    if (((host_client->active != false) && (host_client->connected != false)) &&
       (host_client->spawned != false)) {
      gGlobalVariables.time = (float)sv.time;
      (*gEntityInterface.pfnClientKill)(sv_player);
      return;
    }
    SV_ClientPrintf("Can\'t kill yourself -- you\'re not connected!\n");
    return;
  }
  SV_ClientPrintf("Can\'t suicide -- already dead!\n");
  return;
}


// Host_Load  @ 0007cf30
int __regparm3 Host_Load(char *pName)

{
  ushort *puVar1;
  int iVar2;
  FileHandle_t file;
  ushort **ppuVar3;
  int iVar4;
  char *mapName;
  char cVar5;
  qboolean loadGame;
  char *pcVar6;
  char local_1a0 [251];
  undefined1 local_a5;
  undefined1 local_a1;
  GAME_HEADER local_a0;
  char local_2c [12];
  int local_20 [4];
  
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
                       Unresolved local var: char[5] szNumber@[???]
                       Unresolved local var: int nSlot@[???] */
  if (*pName == '_') {
    cVar5 = pName[1];
    if (cVar5 == '\0') {
      iVar2 = 0;
    }
    else {
      ppuVar3 = __ctype_b_loc();
      puVar1 = *ppuVar3;
      iVar4 = 0;
      do {
        iVar2 = iVar4;
        if (((*(byte *)((int)puVar1 + cVar5 * 2 + 1) & 8) == 0) || (4 < iVar4)) break;
        local_2c[iVar4] = cVar5;
        iVar2 = iVar4 + 1;
        cVar5 = pName[iVar4 + 2];
        iVar4 = iVar2;
      } while (cVar5 != '\0');
    }
    local_2c[iVar2] = '\0';
    pName = (char *)Q_atoi(local_2c);
    if ((char *)0xb < pName + -1) {
      return 0;
    }
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    pcVar6 = "%sHalf-Life-%i";
  }
  else {
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    pcVar6 = "%s%s";
  }
  snprintf(local_1a0,0xfc,pcVar6,Host_SaveGameDirectory::szDirectory,pName);
  local_a5 = 0;
  if (svs.dll_initialized == false) {
                    /* Unresolved local var: char[10] szInsecure@[???] */
    Cbuf_Execute();
    NET_Config((uint)(1 < svs.maxclients));
    if (svs.dll_initialized == false) {
      Host_InitializeGameDLL();
    }
    else {
      Con_DPrintf("Sys_InitializeGameDLL called twice, skipping second call\n");
    }
  }
  COM_DefaultExtension(local_1a0,".sav");
  pcVar6 = COM_LastFileExtension(local_1a0);
  if ((pcVar6 != (char *)0x0) && (iVar2 = Q_stricmp(pcVar6,"sav"), iVar2 == 0)) {
    COM_FixSlashes(local_1a0);
    local_a1 = 0;
    Con_Printf("Loading game from %s...\n",local_1a0);
    file = FS_OpenPathID(local_1a0,"rb","GAMECONFIG");
    if (file != (FileHandle_t)0x0) {
      S_StopAllSounds(true);
      Host_ClearSaveDirectory();
      if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
        (*gEntityInterface.pfnResetGlobalState)();
      }
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???] */
      FS_Read(local_20,4,1,file);
      if ((local_20[0] == 0x5641534a) && (FS_Read(local_20,4,1,file), local_20[0] == 0x71)) {
        iVar2 = SaveReadHeader(file,&local_a0,1);
        if (iVar2 != 0) {
          cls.demonum = -1;
          SV_InactivateClients();
          SCR_BeginLoadingPlaque(false);
          DirectoryExtract(file,local_a0.mapCount);
          FS_Close(file);
          Cvar_SetValue("deathmatch",0.0);
          Cvar_SetValue("coop",0.0);
          iVar2 = Q_stricmp(com_gamedir,"valve");
          if (((iVar2 == 0) || (iVar2 = Q_stricmp(com_gamedir,"bshift"), iVar2 == 0)) ||
             (iVar2 = Q_stricmp(com_gamedir,"gearbox"), iVar2 == 0)) {
            svs.maxclients = 1;
            Cvar_SetValue("maxplayers",1.0);
          }
          snprintf(local_1a0,0x100,"map %s\n",&local_a0);
          CL_Disconnect();
          Host_ShutdownServer(false);
          key_dest = key_game;
          SCR_BeginLoadingPlaque(false);
          Q_strncpy(cls.mapstring,local_1a0,0x3f);
          cls.mapstring[0x3f] = '\0';
          loadGame = false;
          iVar2 = SV_SpawnServer(false,local_a0.mapName,(char *)0x0);
          if (iVar2 == 0) {
            return 1;
          }
          Host_Map((qboolean)&local_a0,(char *)0x1,mapName,loadGame);
          return 1;
        }
      }
      else {
        FS_Close(file);
      }
      giStateInfo = 1;
      Cbuf_AddText("\ndisconnect\n");
    }
  }
  return 0;
}


// Host_Load  @ 0007d3a0
int Host_Load(char *pName)

{
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
                       Unresolved local var: char[5] szNumber@[???]
                       Unresolved local var: int nSlot@[???] */
  if ((pName != (char *)0x0) && (*pName != '\0')) {
    pcVar1 = Q_strstr(pName,"..");
    if (pcVar1 != (char *)0x0) {
      Con_Printf("Relative pathnames are not allowed.\n");
      return 0;
    }
    iVar2 = Host_Load(pName);
    return iVar2;
  }
  return 0;
}


// Host_Loadgame_f  @ 0007d400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Loadgame_f(void)

{
  int iVar1;
  char *s1;
  char *pcVar2;
  
  if (cmd_source == src_command) {
    iVar1 = Cmd_Argc();
    if (iVar1 != 2) {
      Con_Printf("load <savename> : load a game\n");
      return;
    }
    s1 = Cmd_Argv(1);
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char[5] szNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
                       Unresolved local var: int nSlot@[???] */
    if ((s1 != (char *)0x0) && (*s1 != '\0')) {
      pcVar2 = Q_strstr(s1,"..");
      if (pcVar2 == (char *)0x0) {
        iVar1 = Host_Load(s1);
        if (iVar1 != 0) {
          return;
        }
      }
      else {
        Con_Printf("Relative pathnames are not allowed.\n");
      }
    }
    Con_Printf("Error loading saved game\n");
  }
  return;
}


// Host_Map  @ 0007b140
void __regparm3 Host_Map(qboolean bIsDemo,char *mapstring,char *mapName,qboolean loadGame)

{
  _UserMsg *p_Var1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  UserMsg *pUVar6;
  char *pcVar7;
  cactive_t cVar8;
  int arg;
  
  ContinueLoadingProgressBar("Server",7,0.0);
  if (mapstring == (char *)0x0) {
    SV_LoadEntities();
    SV_ActivateServer(1);
    if (sv.active == false) {
      return;
    }
    cVar8 = ca_dedicated;
    if (cls.state != ca_dedicated) {
                    /* Unresolved local var: int i@[???] */
      arg = 2;
      Q_strcpy(cls.spawnparms,"");
      iVar2 = Cmd_Argc();
      cVar8 = cls.state;
      if (2 < iVar2) {
        do {
          pcVar7 = cls.spawnparms;
          do {
            pcVar5 = pcVar7;
            uVar3 = *(uint *)pcVar5 + 0xfefefeff & ~*(uint *)pcVar5;
            uVar4 = uVar3 & 0x80808080;
            pcVar7 = pcVar5 + 4;
          } while (uVar4 == 0);
          if ((uVar3 & 0x8080) == 0) {
            pcVar7 = pcVar5 + 6;
            uVar4 = uVar4 >> 0x10;
          }
          pcVar5 = Cmd_Argv(arg);
          strncat(cls.spawnparms,pcVar5,
                  0x7ff - (int)(pcVar7 + (-0x1478f3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))));
          pcVar7 = cls.spawnparms;
          do {
            pcVar5 = pcVar7;
            uVar3 = *(uint *)pcVar5 + 0xfefefeff & ~*(uint *)pcVar5;
            uVar4 = uVar3 & 0x80808080;
            pcVar7 = pcVar5 + 4;
          } while (uVar4 == 0);
          if ((uVar3 & 0x8080) == 0) {
            pcVar7 = pcVar5 + 6;
            uVar4 = uVar4 >> 0x10;
          }
          arg = arg + 1;
          strncat(cls.spawnparms," ",
                  0x7ff - (int)(pcVar7 + (-0x1478f3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))));
          iVar2 = Cmd_Argc();
          cVar8 = cls.state;
        } while (arg < iVar2);
      }
    }
  }
  else {
    iVar2 = LoadGamestate((char *)bIsDemo,1);
    if (iVar2 == 0) {
      SV_LoadEntities();
    }
    sv.paused = true;
    sv.loadgame = true;
    SV_ActivateServer(0);
    cVar8 = cls.state;
  }
  if (sv_gpNewUserMsgs != (UserMsg *)0x0) {
    p_Var1 = sv_gpUserMsgs;
    pUVar6 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != (UserMsg *)0x0) {
      do {
        pUVar6 = p_Var1;
        p_Var1 = pUVar6->next;
      } while (p_Var1 != (_UserMsg *)0x0);
      pUVar6->next = sv_gpNewUserMsgs;
      pUVar6 = sv_gpUserMsgs;
    }
    sv_gpUserMsgs = pUVar6;
    sv_gpNewUserMsgs = (UserMsg *)0x0;
  }
  if (cVar8 == ca_dedicated) {
    return;
  }
  Cmd_ExecuteString("connect local",src_command);
  return;
}


// Host_Map  @ 0007ce40
void Host_Map(qboolean bIsDemo,char *mapstring,char *mapName,qboolean loadGame)

{
  int iVar1;
  char *mapName_00;
  
  Host_ShutdownServer(false);
  key_dest = key_game;
  SCR_BeginLoadingPlaque(false);
  if (loadGame == false) {
    S_StopAllSounds(true);
    Host_ClearSaveDirectory();
    if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
      (*gEntityInterface.pfnResetGlobalState)();
    }
    SV_InactivateClients();
    svs.serverflags = 0;
  }
  Q_strncpy(cls.mapstring,mapstring,0x3f);
  cls.mapstring[0x3f] = '\0';
  iVar1 = SV_SpawnServer(bIsDemo,mapName,(char *)0x0);
  if (iVar1 == 0) {
    return;
  }
  Host_Map((qboolean)mapName,(char *)loadGame,mapName_00,bIsDemo);
  return;
}


// Host_Map_f  @ 0007d530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Map_f(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *mapName;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  qboolean loadGame;
  uint local_9c [15];
  char acStack_60 [4];
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[64] mapstring@[???]
                       Unresolved local var: char[64] name@[???]
                       Unresolved local var: CareerStateType careerState@[???] */
  iVar1 = COM_CheckParm("-steam");
  if ((iVar1 != 0) && (iVar1 = PF_IsDedicatedServer(), iVar1 != 0)) {
    g_bMajorMapChange = true;
  }
  iVar7 = 0;
  FS_LogLevelLoadStarted("Map_Common");
  local_9c[0]._0_1_ = 0;
  iVar1 = Cmd_Argc();
  puVar6 = local_9c;
  if (0 < iVar1) {
    do {
      do {
        puVar5 = puVar6;
        uVar2 = *puVar5 + 0xfefefeff & ~*puVar5;
        uVar3 = uVar2 & 0x80808080;
        puVar6 = puVar5 + 1;
      } while (uVar3 == 0);
      if ((uVar2 & 0x8080) == 0) {
        puVar6 = (uint *)((int)puVar5 + 6);
        uVar3 = uVar3 >> 0x10;
      }
      pcVar4 = Cmd_Argv(iVar7);
      strncat((char *)local_9c,pcVar4,
              0x3e - (int)((int)puVar6 +
                          ((-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)) - (int)local_9c)));
      puVar6 = local_9c;
      do {
        puVar5 = puVar6;
        uVar2 = *puVar5 + 0xfefefeff & ~*puVar5;
        uVar3 = uVar2 & 0x80808080;
        puVar6 = puVar5 + 1;
      } while (uVar3 == 0);
      if ((uVar2 & 0x8080) == 0) {
        puVar6 = (uint *)((int)puVar5 + 6);
        uVar3 = uVar3 >> 0x10;
      }
      iVar7 = iVar7 + 1;
      strncat((char *)local_9c," ",
              0x3e - (int)((int)puVar6 +
                          ((-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)) - (int)local_9c)));
      iVar1 = Cmd_Argc();
      puVar6 = local_9c;
    } while (iVar7 < iVar1);
  }
  Q_strcat((char *)local_9c,"\n");
  pcVar4 = Cmd_Argv(1);
  Q_strncpy(local_5c,pcVar4,0x3f);
  local_1d = 0;
  if (svs.dll_initialized == false) {
                    /* Unresolved local var: char[10] szInsecure@[???] */
    Cbuf_Execute();
    NET_Config((uint)(1 < svs.maxclients));
    if (svs.dll_initialized == false) {
      Host_InitializeGameDLL();
    }
    else {
      Con_DPrintf("Sys_InitializeGameDLL called twice, skipping second call\n");
    }
  }
  iVar1 = Q_strlen(local_5c);
  if ((4 < iVar1) && (iVar7 = Q_strcasecmp(acStack_60 + iVar1,".bsp"), iVar7 == 0)) {
    acStack_60[iVar1] = '\0';
  }
  FS_LogLevelLoadStarted(local_5c);
  SCR_UpdateScreen();
  SCR_UpdateScreen();
  iVar1 = PF_IsMapValid_I(local_5c);
  if (iVar1 != 0) {
    StartLoadingProgressBar("Server",0x18);
    SetLoadingProgressBarStatusText("#GameUI_StartingServer");
    ContinueLoadingProgressBar("Server",1,0.0);
    Cvar_Set("HostMap",local_5c);
    Host_ShutdownServer(false);
    key_dest = key_game;
    SCR_BeginLoadingPlaque(false);
    S_StopAllSounds(true);
    Host_ClearSaveDirectory();
    if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
      (*gEntityInterface.pfnResetGlobalState)();
    }
    SV_InactivateClients();
    svs.serverflags = 0;
    Q_strncpy(cls.mapstring,(char *)local_9c,0x3f);
    cls.mapstring[0x3f] = '\0';
    loadGame = false;
    iVar1 = SV_SpawnServer(false,local_5c,(char *)0x0);
    if (iVar1 == 0) {
      iVar1 = COM_CheckParm("-steam");
    }
    else {
      Host_Map((qboolean)local_5c,(char *)0x0,mapName,loadGame);
      iVar1 = COM_CheckParm("-steam");
    }
    if ((iVar1 != 0) && (iVar1 = PF_IsDedicatedServer(), iVar1 != 0)) {
      g_bMajorMapChange = false;
      Sys_Printf("\n");
    }
    ContinueLoadingProgressBar("Server",0xb,0.0);
    NotifyDedicatedServerUI("UpdateMap");
    if (g_careerState == CAREER_LOADING) {
      g_careerState = CAREER_PLAYING;
      SetCareerAudioState(1);
      return;
    }
    SetCareerAudioState(0);
    return;
  }
  Con_Printf("map change failed: \'%s\' not found on server.\n",local_5c);
  iVar1 = COM_CheckParm("-steam");
  if ((iVar1 != 0) && (iVar1 = PF_IsDedicatedServer(), iVar1 != 0)) {
    g_bMajorMapChange = false;
    Sys_Printf("\n");
  }
  return;
}


// Host_Map_f  @ 0007d930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Map_f(void)

{
  CareerStateType CVar1;
  int iVar2;
  char *str;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[64] mapstring@[???]
                       Unresolved local var: char[64] name@[???]
                       Unresolved local var: CareerStateType careerState@[???] */
  CVar1 = g_careerState;
  if (cmd_source == src_command) {
    iVar2 = Cmd_Argc();
    if (1 < iVar2) {
      str = Cmd_Args();
      iVar2 = Q_strlen(str);
      if (0x36 < iVar2) {
        Con_Printf("map change failed: command string is too long.\n");
        g_careerState = CAREER_NONE;
        return;
      }
    }
    iVar2 = Cmd_Argc();
    if (1 < iVar2) {
      CL_Disconnect();
      if (CVar1 == CAREER_LOADING) {
        g_careerState = CAREER_LOADING;
      }
      Host_Map_f();
      return;
    }
    Con_Printf("map <levelname> : changes server to specified map\n");
  }
  g_careerState = CAREER_NONE;
  return;
}


// Host_Maps_f  @ 00077010
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Maps_f(void)

{
  int iVar1;
  char *pszSubString;
  
                    /* Unresolved local var: char * pszSubString@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
                    /* Unresolved local var: char * pszSubString@[???] */
    pszSubString = Cmd_Argv(1);
    if ((pszSubString != (char *)0x0) && (*pszSubString != '\0')) {
      if (*pszSubString == '*') {
        pszSubString = (char *)0x0;
      }
      COM_ListMaps(pszSubString);
      return;
    }
  }
  else {
    Con_Printf("Usage:  maps <substring>\nmaps * for full listing\n");
  }
  return;
}


// Host_Motd_Write_f  @ 000770d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Motd_Write_f(void)

{
  char *pcVar1;
  qboolean qVar2;
  int iVar3;
  FileHandle_t file;
  uint uVar4;
  uint uVar5;
  char *size;
  uint *puVar6;
  uint *puVar7;
  char *pcVar8;
  bool bVar9;
  undefined4 local_81c;
  
                    /* Unresolved local var: char * pchExtension@[???] */
  pcVar1 = COM_LastFileExtension(motdfile.string);
  qVar2 = IsSafeFileToDownload(motdfile.string);
  if ((qVar2 == false) || (iVar3 = Q_stricmp(pcVar1,"txt"), iVar3 != 0)) {
    Con_Printf("Invalid motdfile name (%s)\n",motdfile.string);
  }
  else {
                    /* Unresolved local var: char[2048] newFile@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: FileHandle_t pFile@[???] */
    file = FS_Open(motdfile.string,"wb+");
    if (file != (FileHandle_t)0x0) {
      pcVar1 = Cmd_Args();
      Q_strncpy((char *)&local_81c,pcVar1,0x800);
      puVar7 = &local_81c;
      do {
        puVar6 = puVar7;
        uVar4 = *puVar6 + 0xfefefeff & ~*puVar6;
        uVar5 = uVar4 & 0x80808080;
        puVar7 = puVar6 + 1;
      } while (uVar5 == 0);
      if ((uVar4 & 0x8080) == 0) {
        puVar7 = (uint *)((int)puVar6 + 6);
        uVar5 = uVar5 >> 0x10;
      }
      size = (char *)((int)puVar7 + ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)&local_81c)
                     );
      pcVar1 = (char *)((int)&local_81c + 2);
      pcVar8 = (char *)0x1;
      if (size != (char *)0x0) {
        do {
          if ((pcVar1[-2] == '\\') && (pcVar1[-1] == 'n')) {
            pcVar1[-2] = '\n';
            strcpy((char *)((int)&local_81c + (int)pcVar8),pcVar1);
            puVar7 = &local_81c;
            do {
              puVar6 = puVar7;
              uVar4 = *puVar6 + 0xfefefeff & ~*puVar6;
              uVar5 = uVar4 & 0x80808080;
              puVar7 = puVar6 + 1;
            } while (uVar5 == 0);
            if ((uVar4 & 0x8080) == 0) {
              puVar7 = (uint *)((int)puVar6 + 6);
              uVar5 = uVar5 >> 0x10;
            }
            size = (char *)((int)puVar7 +
                           ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)&local_81c));
          }
          pcVar1 = pcVar1 + 1;
          bVar9 = pcVar8 < size;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
      }
      FS_Write(&local_81c,(int)size,1,file);
      FS_Close(file);
      Con_Printf("Done.\n");
      return;
    }
    Con_Printf("Unable to open %s\n",motdfile.string);
  }
  return;
}


// Host_Motd_Write_f  @ 00077270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Motd_Write_f(void)

{
  int iVar1;
  
                    /* Unresolved local var: char * pchExtension@[???] */
  if (((sv.active != false) && (cmd_source == src_command)) && (cls.state == ca_dedicated)) {
    iVar1 = Cmd_Argc();
    if (1 < iVar1) {
      Host_Motd_Write_f();
      return;
    }
    Con_Printf("No message provided\n");
  }
  return;
}


// Host_Motd_f  @ 000772c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Motd_f(void)

{
  char *pcVar1;
  int iVar2;
  FileHandle_t file;
  uint size;
  char *pcVar3;
  char *__s;
  
                    /* Unresolved local var: char * pchExtension@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: FileHandle_t pFile@[???] */
  if ((((*motdfile.string == '/') || (pcVar1 = Q_strstr(motdfile.string,":"), pcVar1 != (char *)0x0)
       ) || (pcVar1 = Q_strstr(motdfile.string,".."), pcVar1 != (char *)0x0)) ||
     (pcVar1 = Q_strstr(motdfile.string,"\\"), pcVar1 != (char *)0x0)) {
    Con_Printf("Unable to open %s (contains illegal characters)\n",motdfile.string);
  }
  else {
                    /* Unresolved local var: char * pchExtension@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: FileHandle_t pFile@[???] */
    pcVar1 = COM_LastFileExtension(motdfile.string);
    iVar2 = Q_stricmp(pcVar1,"txt");
    if (iVar2 == 0) {
      file = FS_Open(motdfile.string,"rb");
      if (file == (FileHandle_t)0x0) {
        Con_Printf("Unable to open %s\n",motdfile.string);
      }
      else {
        size = FS_Size(file);
                    /* Unresolved local var: char * pFileList@[???] */
        if ((size != 0) && (pcVar1 = malloc(size + 1), pcVar1 != (char *)0x0)) {
                    /* Unresolved local var: char * next@[???]
                       Unresolved local var: char * now@[???] */
          FS_Read(pcVar1,size,1,file);
          pcVar1[size] = '\0';
          Con_Printf("motd:");
          __s = pcVar1;
          while (pcVar3 = strchr(__s,10), pcVar3 != (char *)0x0) {
            *pcVar3 = '\0';
            Con_Printf("%s\n",__s);
            __s = pcVar3 + 1;
          }
          Con_Printf("%s\n",__s);
          free(pcVar1);
        }
        FS_Close(file);
      }
    }
    else {
      Con_Printf("Invalid motdfile name %s (wrong file extension, must be .txt)\n",motdfile.string);
    }
  }
  return;
}


// Host_NextDemo  @ 0007dad0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_NextDemo(void)

{
  int iVar1;
  char local_40c [1032];
  
                    /* Unresolved local var: char[1024] str@[???] */
  if (cls.demonum != -1) {
    SCR_BeginLoadingPlaque(false);
    if ((cls.demos[cls.demonum][0] == '\0') || (cls.demonum == 0x20)) {
      cls.demonum = 0;
      iVar1 = 0x1481fc;
      if (cls.demos[0][0] == '\0') {
        Con_Printf("No demos listed with startdemos\n");
        cls.demonum = -1;
        return;
      }
    }
    else {
                    /* Unresolved local var: char[1024] str@[???] */
      iVar1 = cls.demonum * 0x10 + 0x1481fc;
    }
    snprintf(local_40c,0x400,"playdemo %s\n",iVar1);
    Cbuf_InsertText(local_40c);
    cls.demonum = cls.demonum + 1;
  }
  return;
}


// Host_Noclip_f  @ 00079010
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Noclip_f(void)

{
  vec_t *pvVar1;
  entvars_t *peVar2;
  edict_t_conflict *peVar3;
  edict_t_conflict *peVar4;
  edict_t_conflict *peVar5;
  edict_t_conflict *peVar6;
  int iVar7;
  vec_t local_40 [3];
  vec_t local_34 [3];
  vec_t local_28 [6];
  
  peVar3 = sv_player;
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (gGlobalVariables.deathmatch != 0.0) {
    return;
  }
  if (sv_cheats.value == 0.0) {
    return;
  }
  if ((sv_player->v).movetype != 8) {
    (sv_player->v).movetype = 8;
    noclip_anglehack = true;
    SV_ClientPrintf("noclip ON\n");
    return;
  }
  peVar2 = &sv_player->v;
  (sv_player->v).movetype = 3;
  noclip_anglehack = false;
  (peVar3->v).oldorigin[0] = peVar2->origin[0];
  (peVar3->v).oldorigin[1] = (peVar3->v).origin[1];
  (peVar3->v).oldorigin[2] = (peVar3->v).origin[2];
  SV_ClientPrintf("noclip OFF\n");
  peVar3 = SV_TestEntityPosition(sv_player);
  if (peVar3 == (edict_t_conflict *)0x0) {
    return;
  }
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
  iVar7 = 100;
  AngleVectors((sv_player->v).v_angle,local_40,local_34,local_28);
  peVar3 = sv_player;
  pvVar1 = (sv_player->v).origin;
  do {
    VectorMA(pvVar1,1.0,local_40,pvVar1);
    peVar4 = SV_TestEntityPosition(peVar3);
    peVar6 = sv_player;
    if (peVar4 == (edict_t_conflict *)0x0) goto LAB_0007916b;
                    /* Unresolved local var: int i@[???] */
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 100;
  pvVar1 = (sv_player->v).origin;
  do {
    VectorMA(pvVar1,1.0,local_34,pvVar1);
    peVar5 = SV_TestEntityPosition(peVar6);
    peVar4 = sv_player;
    peVar3 = peVar6;
    if (peVar5 == (edict_t_conflict *)0x0) goto LAB_0007916b;
                    /* Unresolved local var: int i@[???] */
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 100;
  pvVar1 = (sv_player->v).origin;
  do {
    VectorMA(pvVar1,-1.0,local_34,pvVar1);
    peVar5 = SV_TestEntityPosition(peVar4);
    peVar6 = sv_player;
    peVar3 = peVar4;
    if (peVar5 == (edict_t_conflict *)0x0) goto LAB_0007916b;
                    /* Unresolved local var: int i@[???] */
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 100;
  pvVar1 = (sv_player->v).origin;
  do {
    VectorMA(pvVar1,1.0,local_28,pvVar1);
    peVar5 = SV_TestEntityPosition(peVar6);
    peVar4 = sv_player;
    peVar3 = peVar6;
    if (peVar5 == (edict_t_conflict *)0x0) goto LAB_0007916b;
                    /* Unresolved local var: int i@[???] */
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 100;
  pvVar1 = (sv_player->v).origin;
  do {
    VectorMA(pvVar1,-1.0,local_28,pvVar1);
    peVar6 = SV_TestEntityPosition(peVar4);
    peVar3 = peVar4;
    if (peVar6 == (edict_t_conflict *)0x0) goto LAB_0007916b;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = FindPassableSpace((edict_t *)sv_player,local_40,-1.0);
  if (iVar7 == 0) {
    Con_DPrintf("Can\'t find the world\n");
  }
LAB_0007918f:
  peVar3 = sv_player;
  (sv_player->v).origin[0] = (sv_player->v).oldorigin[0];
  (peVar3->v).origin[1] = (peVar3->v).oldorigin[1];
  (peVar3->v).origin[2] = (peVar3->v).oldorigin[2];
  return;
LAB_0007916b:
                    /* Unresolved local var: int i@[???] */
  (peVar3->v).oldorigin[0] = (peVar3->v).origin[0];
  (peVar3->v).oldorigin[1] = (peVar3->v).origin[1];
  (peVar3->v).oldorigin[2] = (peVar3->v).origin[2];
  goto LAB_0007918f;
}


// Host_Notarget_f  @ 00076770
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Notarget_f(void)

{
  uint uVar1;
  
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (gGlobalVariables.deathmatch == 0.0) {
    uVar1 = (sv_player->v).flags ^ 0x80;
    (sv_player->v).flags = uVar1;
    if ((uVar1 & 0x80) == 0) {
      SV_ClientPrintf("notarget OFF\n");
      return;
    }
    SV_ClientPrintf("notarget ON\n");
  }
  return;
}


// Host_Pause_f  @ 00076600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Pause_f(void)

{
  if (cl.levelname[0] != '\0') {
    if (cmd_source == src_command) {
      Cmd_ForwardToServer();
      return;
    }
    if (pausable.value != 0.0) {
      sv.paused = true;
      MSG_WriteByte(&sv.reliable_datagram,0x18);
      MSG_WriteByte(&sv.reliable_datagram,sv.paused);
    }
  }
  return;
}


// Host_Ping_f  @ 000764d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Ping_f(void)

{
  char *pcVar1;
  int iVar2;
  client_s *cl;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???] */
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  SV_ClientPrintf("Client ping times:\n");
  if (0 < svs.maxclients) {
    iVar3 = 0;
    iVar2 = svs.maxclients;
    cl = svs.clients;
    do {
      while (cl->active != false) {
        iVar3 = iVar3 + 1;
        iVar2 = SV_CalcPing(cl);
        pcVar1 = cl->name;
        cl = cl + 1;
        SV_ClientPrintf("%4i %s\n",iVar2,pcVar1);
        iVar2 = svs.maxclients;
        if (svs.maxclients <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      cl = cl + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// Host_Quit_Restart_f  @ 00078210
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Quit_Restart_f(void)

{
  char *pcVar1;
  size_t sVar2;
  
  pcVar1 = g_pPostRestartCmdLineArgs;
  giActive = 5;
  giStateInfo = 4;
  if (sv.active == false) {
    if (cls.state != ca_active) {
      giStateInfo = 4;
      giActive = 5;
      return;
    }
    if (cls.trueaddress[0] == '\0') {
      giStateInfo = 4;
      giActive = 5;
      return;
    }
    if (g_pPostRestartCmdLineArgs == (char *)0x0) {
      giStateInfo = 4;
      giActive = 5;
      return;
    }
    sVar2 = strlen(g_pPostRestartCmdLineArgs);
    builtin_strncpy(pcVar1 + sVar2," +connect ",0xb);
    strcat(g_pPostRestartCmdLineArgs,cls.servername);
    if (sv.active == false) {
      return;
    }
  }
  if (((svs.maxclients == 1) && (cls.state == ca_active)) &&
     (g_pPostRestartCmdLineArgs != (char *)0x0)) {
    Cbuf_AddText("save quick\n");
    Cbuf_Execute();
    pcVar1 = g_pPostRestartCmdLineArgs;
    sVar2 = strlen(g_pPostRestartCmdLineArgs);
    builtin_strncpy(pcVar1 + sVar2," +load quick",0xd);
  }
  return;
}


// Host_Quit_f  @ 00077060
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Quit_f(void)

{
  int iVar1;
  
  iVar1 = Cmd_Argc();
  if (iVar1 != 1) {
    giActive = 2;
    giStateInfo = 4;
    return;
  }
  giActive = 3;
  g_iQuitCommandIssued = 1;
  if (cls.state != ca_dedicated) {
    CL_Disconnect();
  }
  Host_ShutdownServer(false);
  Sys_Quit();
  return;
}


// Host_Reconnect_f  @ 00076d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Reconnect_f(void)

{
  netadr_t a;
  char *src;
  int iVar1;
  char local_10c [128];
  char local_8c [136];
  
                    /* Unresolved local var: char[128] cmdString@[???] */
  if (ca_connecting < cls.state) {
    if (cls.passive == false) {
      SCR_BeginLoadingPlaque(true);
      cls.signon = 0;
      cls.state = ca_connected;
      sys_timescale.value = 1.0;
      Netchan_Clear(&cls.netchan);
      SZ_Clear(&cls.netchan.message);
      MSG_WriteChar(&cls.netchan.message,3);
      MSG_WriteString(&cls.netchan.message,"new");
      return;
    }
                    /* Unresolved local var: char[128] cmdString@[???]
                       Unresolved local var: char[128] buf@[???] */
    a.ip = cls.connect_stream.ip;
    a.type = cls.connect_stream.type;
    a.ipx._0_4_ = cls.connect_stream.ipx._0_4_;
    a.ipx._4_4_ = cls.connect_stream.ipx._4_4_;
    a._16_4_ = cls.connect_stream._16_4_;
    src = NET_AdrToString(a);
    Q_strncpy_s(local_10c,src,0x80);
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???]
                       Unresolved local var: size_t __result@[???] */
    iVar1 = 0;
    while (((local_10c[0] != '\0' && (local_10c[0] != ';')) && (local_10c[0] != '\n'))) {
      iVar1 = iVar1 + 1;
      local_10c[0] = local_10c[iVar1];
    }
    local_10c[iVar1] = '\0';
    snprintf(local_8c,0x80,"listen %s\n",local_10c);
    Cbuf_AddText(local_8c);
  }
  return;
}


// Host_Reload_f  @ 0007cce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Reload_f(void)

{
                    /* Unresolved local var: char * pSaveName@[???]
                       Unresolved local var: char[260] name@[???] */
  if (((cls.demoplayback == false) && (sv.active != false)) && (cmd_source == src_command)) {
                    /* Unresolved local var: char * pSaveName@[???]
                       Unresolved local var: char[260] name@[???] */
    S_StopAllSounds(true);
    Host_ClearSaveDirectory();
    if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
      (*gEntityInterface.pfnResetGlobalState)();
    }
    SV_InactivateClients();
    SV_ServerShutdown();
    SV_SpawnServer(false,gHostMap.string,(char *)0x0);
    SV_LoadEntities();
    SV_ActivateServer(1);
  }
  return;
}


// Host_Restart_f  @ 0007cd70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Restart_f(void)

{
  char local_110 [259];
  undefined1 local_d;
  
                    /* Unresolved local var: char[260] name@[???] */
  if (cls.state != ca_dedicated) {
    cls.state = ca_disconnected;
  }
  S_StopAllSounds(true);
  Host_ClearSaveDirectory();
  if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
    (*gEntityInterface.pfnResetGlobalState)();
  }
  SV_InactivateClients();
  Q_strncpy(local_110,sv.name,0x103);
  local_d = 0;
  SV_ServerShutdown();
  SV_SpawnServer(false,local_110,(char *)0x0);
  SV_LoadEntities();
  SV_ActivateServer(1);
  return;
}


// Host_Restart_f  @ 0007ce10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Restart_f(void)

{
                    /* Unresolved local var: char[260] name@[???] */
  if (((cls.demoplayback == false) && (sv.active != false)) && (cmd_source == src_command)) {
    Host_Restart_f();
    return;
  }
  return;
}


// Host_SaveAgeList  @ 000795a0
void Host_SaveAgeList(char *pName,int count)

{
  char local_224 [260];
  char local_120 [272];
  
                    /* Unresolved local var: char[260] newName@[???]
                       Unresolved local var: char[260] oldName@[???] */
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(local_224,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,pName,count);
  COM_FixSlashes(local_224);
  FS_RemoveFile(local_224,"GAMECONFIG");
  if (0 < count) {
    while( true ) {
      if (count == 1) break;
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
      snprintf(local_120,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,pName,count + -1);
      COM_FixSlashes(local_120);
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
      snprintf(local_224,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,pName,count);
      COM_FixSlashes(local_224);
      FS_Rename(local_120,local_224);
      count = count + -1;
    }
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    snprintf(local_120,0x104,"%s%s.sav",Host_SaveGameDirectory::szDirectory,pName);
    COM_FixSlashes(local_120);
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    snprintf(local_224,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,pName,1);
    COM_FixSlashes(local_224);
    FS_Rename(local_120,local_224);
  }
  return;
}


// Host_SaveGameDirectory  @ 00079550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Host_SaveGameDirectory(void)

{
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  return Host_SaveGameDirectory::szDirectory;
}


// Host_SavegameComment  @ 00076420
void Host_SavegameComment(char *pszBuffer,int iSizeBuffer)

{
  int iVar1;
  char *__src;
  uint uVar2;
  char *s1;
  
                    /* Unresolved local var: char * pszName@[???]
                       Unresolved local var: char * pszMapName@[???]
                       Unresolved local var: int i@[???] */
  uVar2 = 0;
  s1 = pr_strings + gGlobalVariables.mapname;
  do {
    iVar1 = Q_strlen(gTitleComments[uVar2].pBSPName);
    iVar1 = Q_strnicmp(s1,gTitleComments[uVar2].pBSPName,iVar1);
    if (iVar1 == 0) {
      __src = gTitleComments[uVar2].pTitleName;
      if (__src != (char *)0x0) break;
    }
    else {
      __src = (char *)0x0;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x42);
  if ((__src == (char *)0x0) && ((s1 == (char *)0x0 || (__src = s1, *s1 == '\0')))) {
    iVar1 = Q_strlen(cl.levelname);
    __src = cl.levelname;
    if (iVar1 == 0) {
      __src = s1;
    }
  }
  strncpy(pszBuffer,__src,iSizeBuffer - 1);
  pszBuffer[iSizeBuffer + -1] = '\0';
  return;
}


// Host_Savegame_f  @ 00076150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Savegame_f(void)

{
  return;
}


// Host_Say  @ 00077470
void Host_Say(qboolean teamonly)

{
  bool bVar1;
  client_t *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  edict_t_conflict *ed;
  client_s *pcVar6;
  char *str;
  char local_9c;
  undefined1 local_9b [139];
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: qboolean fromServer@[???] */
  pcVar3 = Cmd_Args();
  pcVar2 = host_client;
  if (pcVar3 != (char *)0x0) {
    str = pcVar3;
    if (*pcVar3 == '\"') {
      str = pcVar3 + 1;
      iVar4 = Q_strlen(str);
      pcVar3[iVar4] = '\0';
    }
    pcVar3 = Cvar_VariableString("hostname");
    snprintf(&local_9c,0x80,"%c<%s> ",1,pcVar3);
    iVar4 = Q_strlen(str);
    if (0x3f < iVar4) {
      str[0x3f] = '\0';
    }
    iVar4 = Q_strlen(&local_9c);
    iVar5 = Q_strlen(str);
    if (0x7e - iVar4 < iVar5) {
      str[0x7e - iVar4] = '\0';
    }
    Q_strcat(&local_9c,str);
    Q_strcat(&local_9c,"\n");
    if (0 < svs.maxclients) {
      iVar4 = svs.maxclients;
      pcVar6 = svs.clients;
      iVar5 = 1;
      do {
        if ((((pcVar6 != (client_t *)0x0) && (pcVar6->active != false)) &&
            (pcVar6->spawned != false)) && (pcVar6->fakeclient == false)) {
          ed = sv.edicts + iVar5;
          host_client = pcVar6;
          iVar4 = RegUserMsg("SayText",-1);
          PF_MessageBegin_I(1,iVar4,(float *)0x0,ed);
          PF_WriteByte_I(0);
          PF_WriteString_I(&local_9c);
          PF_MessageEnd_I();
          iVar4 = svs.maxclients;
        }
        pcVar6 = pcVar6 + 1;
        bVar1 = iVar5 < iVar4;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
    host_client = pcVar2;
    Sys_Printf("%s",local_9b);
    Log_Printf("Server say \"%s\"\n",str);
  }
  return;
}


// Host_Say  @ 0007da90
void Host_Say(qboolean teamonly)

{
  int iVar1;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: qboolean fromServer@[???] */
  if (cls.state == ca_dedicated) {
    iVar1 = Cmd_Argc();
    if (1 < iVar1) {
      Host_Say(teamonly);
      return;
    }
  }
  else if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  return;
}


// Host_Say_Team_f  @ 000778d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Say_Team_f(void)

{
  int iVar1;
  qboolean in_stack_00000004;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: qboolean fromServer@[???] */
  if (cls.state == ca_dedicated) {
    iVar1 = Cmd_Argc();
    if (1 < iVar1) {
      Host_Say(in_stack_00000004);
      return;
    }
  }
  else if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  return;
}


// Host_Say_f  @ 00077910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Say_f(void)

{
  int iVar1;
  qboolean in_stack_00000004;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: qboolean fromServer@[???] */
  if (cls.state == ca_dedicated) {
    iVar1 = Cmd_Argc();
    if (1 < iVar1) {
      Host_Say(in_stack_00000004);
      return;
    }
  }
  else if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  return;
}


// Host_SetAddonsFolder_f  @ 0006e070
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetAddonsFolder_f(void)

{
  int iVar1;
  char *__s1;
  int iVar2;
  bool bVar3;
  
                    /* Unresolved local var: bool bEnabled@[???] */
  if (cls.state != ca_dedicated) {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      iVar1 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0);
      __s1 = Cmd_Argv(1);
      iVar2 = strcasecmp(__s1,"1");
      if (iVar2 == 0) {
        (*registry->_vptr_IRegistry[3])(registry,"addons_folder",1);
      }
      else {
        (*registry->_vptr_IRegistry[3])(registry,"addons_folder",0);
      }
      iVar2 = COM_CheckParm("-addons");
      bVar3 = true;
      if (iVar2 == 0) {
        iVar2 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0);
        bVar3 = 0 < iVar2;
      }
      if (0 < iVar1 != bVar3) {
        COM_SetupDirectories();
        return;
      }
    }
  }
  return;
}


// Host_SetHDModels_f  @ 0006df80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetHDModels_f(void)

{
  int iVar1;
  char *__s1;
  int iVar2;
  bool bVar3;
  
                    /* Unresolved local var: bool bEnabled@[???] */
  if (cls.state != ca_dedicated) {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      iVar1 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",1);
      __s1 = Cmd_Argv(1);
      iVar2 = strcasecmp(__s1,"1");
      if (iVar2 == 0) {
        (*registry->_vptr_IRegistry[3])(registry,"hdmodels",1);
      }
      else {
        (*registry->_vptr_IRegistry[3])(registry,"hdmodels",0);
      }
      iVar2 = COM_CheckParm("-nohdmodels");
      bVar3 = false;
      if (iVar2 == 0) {
        iVar2 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",1);
        bVar3 = 0 < iVar2;
      }
      if (0 < iVar1 != bVar3) {
        COM_SetupDirectories();
        return;
      }
    }
  }
  return;
}


// Host_SetInfo_f  @ 00076a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetInfo_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Info_Print(cls.userinfo);
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    if (cmd_source != src_command) {
      pcVar2 = Cmd_Argv(2);
      pcVar3 = Cmd_Argv(1);
      Info_SetValueForKey(host_client->userinfo,pcVar3,pcVar2,0x100);
      host_client->sendinfo = true;
      return;
    }
    pcVar2 = Cmd_Argv(2);
    pcVar3 = Cmd_Argv(1);
    Info_SetValueForKey(cls.userinfo,pcVar3,pcVar2,0x100);
    Cmd_ForwardToServer();
    return;
  }
  Con_Printf("usage: setinfo [ <key> <value> ]\n");
  return;
}


// Host_SetVideoLevel_f  @ 0006e160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetVideoLevel_f(void)

{
  int iVar1;
  char *__s1;
  
  if (cls.state != ca_dedicated) {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      __s1 = Cmd_Argv(1);
      iVar1 = strcasecmp(__s1,"1");
      if (iVar1 == 0) {
        (*registry->_vptr_IRegistry[3])(registry,"vid_level",1);
        Cvar_Set("gl_texturemode","GL_LINEAR_MIPMAP_NEAREST");
        Cvar_Set("gl_ansio","4");
      }
      else {
        (*registry->_vptr_IRegistry[3])(registry,"vid_level",0);
        Cvar_Set("gl_texturemode","GL_LINEAR_MIPMAP_LINEAR");
        Cvar_Set("gl_ansio","16");
      }
    }
  }
  return;
}


// Host_Shutdown  @ 00075ff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Shutdown(void)

{
  client_frame_t **frames;
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * pclient@[???] */
  if (Host_Shutdown::isdown == false) {
    Host_Shutdown::isdown = true;
    SV_ServerShutdown();
    host_initialized = false;
    Cmd_RemoveGameCmds();
    Cmd_Shutdown();
    Cvar_Shutdown();
    HPAK_FlushHostQueue();
    SV_DeallocateDynamicData();
    if (0 < svs.maxclientslimit) {
      iVar2 = 0;
      pcVar1 = svs.clients;
      do {
        frames = &pcVar1->frames;
        iVar2 = iVar2 + 1;
        pcVar1 = pcVar1 + 1;
        SV_ClearFrames(frames);
      } while (iVar2 < svs.maxclientslimit);
    }
    SV_Shutdown();
    SystemWrapper_ShutDown();
    NET_Shutdown();
    S_Shutdown();
    Con_Shutdown();
    ReleaseEntityDlls();
    CL_ShutDownClientStatic();
    CM_FreePAS();
    if (wadpath != (char *)0x0) {
      Mem_Free(wadpath);
      wadpath = (char *)0x0;
    }
    if (cls.state != ca_dedicated) {
      Draw_Shutdown();
    }
    Draw_DecalShutdown();
    W_Shutdown();
    Log_Printf("Server shutdown\n");
    Log_Close();
    COM_Shutdown();
    CL_Shutdown();
    DELTA_Shutdown();
    sv.time._4_4_ = 0;
    cl.time._0_4_ = 0;
    realtime._4_4_ = 0;
    sv.time._0_4_ = 0;
    realtime._0_4_ = 0;
    cl.time._4_4_ = 0;
    return;
  }
  puts("recursive shutdown");
  return;
}


// Host_ShutdownServer  @ 00074550
void Host_ShutdownServer(qboolean crash)

{
  netadr_t adr;
  int iVar1;
  int iVar2;
  int iVar3;
  client_frame_t *pcVar4;
  client_s *cl;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  if (sv.active != false) {
                    /* Unresolved local var: int i@[???] */
    SV_ServerShutdown();
    sv.active = false;
    NET_ClearLagData(true,true);
    host_client = svs.clients;
    if (0 < svs.maxclients) {
      iVar2 = 0;
      iVar3 = svs.maxclients;
      do {
        if ((host_client->active != false) || (host_client->connected != false)) {
          SV_DropClient(host_client,crash,"Server shutting down");
          iVar3 = svs.maxclients;
        }
        iVar2 = iVar2 + 1;
        host_client = host_client + 1;
      } while (iVar2 < iVar3);
    }
    CL_Disconnect();
    SV_ClearEntities();
    SV_ClearCaches();
    FreeAllEntPrivateData();
    Q_memset(&sv,0,0x4640c);
    CL_ClearClientState();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
    if (0 < svs.maxclients) {
      iVar3 = 0;
      cl = svs.clients;
      do {
        iVar3 = iVar3 + 1;
        COM_ClearCustomizationList(&cl->customdata,false);
        SV_ClearResourceLists(cl);
        cl = cl + 1;
      } while (iVar3 < svs.maxclients);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: client_frame_t * frame@[???] */
      if (0 < svs.maxclients) {
        iVar3 = 0;
        host_client = svs.clients;
        do {
          pcVar4 = host_client->frames;
          if ((pcVar4 != (client_frame_t *)0x0) && (0 < SV_UPDATE_BACKUP)) {
            iVar5 = 0;
            iVar2 = 0;
            while( true ) {
              pcVar4 = (client_frame_t *)((int)(pcVar4->clientdata).origin + iVar5 + -0xc);
              iVar2 = iVar2 + 1;
              iVar5 = iVar5 + 0x1810;
              SV_ClearPacketEntities(pcVar4);
              *(undefined4 *)&pcVar4->senttime = 0;
              iVar1 = SV_UPDATE_BACKUP;
              *(undefined4 *)((int)&pcVar4->senttime + 4) = 0;
              pcVar4->ping_time = -1.0;
              if (iVar1 <= iVar2) break;
              pcVar4 = host_client->frames;
            }
          }
          if ((host_client->netchan).remote_address.type != NA_UNUSED) {
                    /* Unresolved local var: netadr_t save@[???] */
            adr = (host_client->netchan).remote_address;
            Q_memset(&host_client->netchan,0,0x2414);
            Netchan_Setup(NS_SERVER,&host_client->netchan,adr,
                          ((int)host_client - (int)svs.clients >> 3) * -0x6d690de1,&host_client,
                          SV_GetFragmentSize);
          }
          iVar3 = iVar3 + 1;
          COM_ClearCustomizationList(&host_client->customdata,false);
          host_client = host_client + 1;
        } while (iVar3 < svs.maxclients);
      }
    }
    host_client = svs.clients;
    if (0 < svs.maxclientslimit) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        SV_ClearFrames(&host_client->frames);
        host_client = host_client + 1;
      } while (iVar3 < svs.maxclientslimit);
    }
    Q_memset(svs.clients,0,svs.maxclientslimit * 0x4ef8);
    SV_AllocClientFrames();
    host_client = svs.clients;
    if (0 < svs.maxclientslimit) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        SV_ClearFrames(&host_client->frames);
        host_client = host_client + 1;
      } while (iVar3 < svs.maxclientslimit);
    }
    Q_memset(svs.clients,0,svs.maxclientslimit * 0x4ef8);
    HPAK_FlushHostQueue();
    Steam_Shutdown();
    Log_Printf("Server shutdown\n");
    Log_Close();
    return;
  }
  return;
}


// Host_Soundfade_f  @ 000761f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Soundfade_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int percent@[???]
                       Unresolved local var: int inTime@[???]
                       Unresolved local var: int holdTime@[???]
                       Unresolved local var: int outTime@[???] */
  iVar1 = Cmd_Argc();
  if ((iVar1 == 3) || (iVar1 = Cmd_Argc(), iVar1 == 5)) {
    pcVar2 = Cmd_Argv(1);
    iVar3 = Q_atoi(pcVar2);
    iVar1 = 100;
    if (iVar3 < 0x65) {
      iVar1 = iVar3;
    }
    iVar3 = 0;
    if (-1 < iVar1) {
      iVar3 = iVar1;
    }
    pcVar2 = Cmd_Argv(2);
    iVar4 = Q_atoi(pcVar2);
    iVar1 = 0xff;
    if (iVar4 < 0x100) {
      iVar1 = iVar4;
    }
    iVar4 = Cmd_Argc();
    if (iVar4 == 5) {
      pcVar2 = Cmd_Argv(3);
      iVar5 = Q_atoi(pcVar2);
      iVar4 = 0xff;
      if (iVar5 < 0x100) {
        iVar4 = iVar5;
      }
      pcVar2 = Cmd_Argv(4);
      cls.soundfade.soundFadeInTime = Q_atoi(pcVar2);
      if (0xff < cls.soundfade.soundFadeInTime) {
        cls.soundfade.soundFadeInTime = 0xff;
      }
    }
    else {
      iVar4 = 0;
      cls.soundfade.soundFadeInTime = 0;
    }
    cls.soundfade.soundFadeStartTime = realtime;
    cls.soundfade.nStartPercent = iVar3;
    cls.soundfade.soundFadeOutTime = iVar4;
    cls.soundfade.soundFadeHoldTime = iVar1;
  }
  else {
    Con_Printf("soundfade <percent> <hold> [<out> <int>]\n");
  }
  return;
}


// Host_Speeds  @ 00075000
void Host_Speeds(double *time)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  edict_t_conflict *peVar7;
  int iVar8;
  longdouble lVar9;
  
                    /* Unresolved local var: float pass1@[???]
                       Unresolved local var: float pass2@[???]
                       Unresolved local var: float pass3@[???]
                       Unresolved local var: float pass4@[???]
                       Unresolved local var: float pass5@[???]
                       Unresolved local var: double frameTime@[???]
                       Unresolved local var: double fps@[???] */
  lVar9 = (longdouble)1000.0;
  fVar1 = (float)(((longdouble)time[1] - (longdouble)*time) * lVar9);
  fVar2 = (float)(((longdouble)time[2] - (longdouble)time[1]) * lVar9);
  fVar3 = (float)(((longdouble)time[3] - (longdouble)time[2]) * lVar9);
  fVar4 = (float)(((longdouble)time[4] - (longdouble)time[3]) * lVar9);
  fVar5 = (float)(((longdouble)time[5] - (longdouble)time[4]) * lVar9);
  lVar9 = ((longdouble)fVar1 + (longdouble)fVar2 + (longdouble)fVar3 + (longdouble)fVar4 +
          (longdouble)fVar5) / lVar9;
  if (lVar9 < (longdouble)0.0001) {
    lVar9 = (longdouble)999.0;
  }
  else {
    lVar9 = (longdouble)1.0 / lVar9;
  }
  if (host_speeds.value != 0.0) {
                    /* Unresolved local var: int ent_count@[???]
                       Unresolved local var: int i@[???] */
    iVar6 = 0;
    if (0 < sv.num_edicts) {
      iVar8 = 0;
      peVar7 = sv.edicts;
      do {
        if (peVar7->free == 0) {
          iVar6 = iVar6 + 1;
        }
        iVar8 = iVar8 + 1;
        peVar7 = peVar7 + 1;
      } while (iVar8 != sv.num_edicts);
    }
    Con_Printf("%3i fps -- host(%3.0f) sv(%3.0f) cl(%3.0f) gfx(%3.0f) snd(%3.0f) ents(%d)\n",
               (int)lVar9,(double)fVar1,(double)fVar2,(double)fVar3,(double)fVar4,(double)fVar5,
               iVar6);
    return;
  }
  return;
}


// Host_Startdemos_f  @ 0007dbd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Startdemos_f(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char *src;
  int iVar4;
  char (*dest) [16];
  int arg;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  if (cls.state == ca_dedicated) {
    if (sv.active != false) {
      return;
    }
    Con_Printf("Cannot play demos on a dedicated server.\n");
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  iVar3 = Cmd_Argc();
  iVar3 = iVar3 + -1;
  if (iVar3 < 0x21) {
    Con_Printf("%i demo(s) in loop\n",iVar3);
    if (iVar3 < 1) goto LAB_0007dc87;
  }
  else {
    iVar3 = 0x20;
    Con_Printf("Max %i demos in demoloop\n",0x20);
    Con_Printf("%i demo(s) in loop\n",0x20);
  }
  dest = cls.demos;
  arg = 1;
  do {
    src = Cmd_Argv(arg);
    Q_strncpy(*dest,src,0xf);
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???]
                       Unresolved local var: size_t __result@[???] */
    cVar2 = (*dest)[0];
    iVar4 = 0;
    iVar1 = arg + -1;
    (*dest)[0xf] = '\0';
    while (((cVar2 != '\0' && (cVar2 != ';')) && (cVar2 != '\n'))) {
      iVar4 = iVar4 + 1;
      cVar2 = (*dest)[iVar4];
    }
    arg = arg + 1;
    dest = dest + 1;
    *(undefined1 *)(iVar4 + 0x1481fc + iVar1 * 0x10) = 0;
  } while (arg <= iVar3);
LAB_0007dc87:
  if (((sv.active == false) && (cls.demonum != -1)) && (cls.demoplayback == false)) {
    cls.demonum = 0;
    Host_NextDemo();
    return;
  }
  cls.demonum = -1;
  return;
}


// Host_Stats_f  @ 00077780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Stats_f(void)

{
  float fVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  char local_20c [511];
  undefined1 local_d;
  
                    /* Unresolved local var: char[512] stats@[???] */
                    /* Unresolved local var: float avgIn@[???]
                       Unresolved local var: float avgOut@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int players@[???] */
  host_client = svs.clients;
  if (svs.maxclients < 1) {
    fVar1 = 0.0;
    iVar5 = 0;
    fVar2 = fVar1;
  }
  else {
    fVar2 = 0.0;
    iVar4 = 0;
    iVar5 = 0;
    fVar1 = fVar2;
    do {
      if ((((host_client->active != false) || (host_client->connected != false)) ||
          (host_client->spawned != false)) && (host_client->fakeclient == false)) {
        fVar1 = fVar1 + (host_client->netchan).flow[1].avgkbytespersec;
        iVar5 = iVar5 + 1;
        fVar2 = fVar2 + (host_client->netchan).flow[0].avgkbytespersec;
      }
      iVar4 = iVar4 + 1;
      host_client = host_client + 1;
    } while (iVar4 != svs.maxclients);
  }
  dVar3 = 1.0 / host_frametime;
  iVar4 = g_userid + -1;
  dVar6 = Sys_FloatTime();
  snprintf(local_20c,0x1ff,"%5.2f %5.2f %5.2f %7i %5i %7.2f %7i",(double)((float)cpuPercent * 100.0)
           ,(double)fVar1,(double)fVar2,(int)(dVar6 - (double)startTime) / 0x3c,iVar4,dVar3,iVar5);
  local_d = 0;
  Con_Printf("CPU   In    Out   Uptime  Users   FPS    Players\n%s\n",local_20c);
  return;
}


// Host_Status_Formatted_f  @ 000783d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Status_Formatted_f(void)

{
  bool bVar1;
  int iVar2;
  netadr_t a;
  int iVar3;
  qboolean qVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  client_s *cl;
  int iVar8;
  qboolean conprint;
  char *pcVar9;
  undefined4 uVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  qboolean local_164;
  char local_144 [260];
  char local_40 [32];
  int local_20 [4];
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int seconds@[???]
                       Unresolved local var: int minutes@[???]
                       Unresolved local var: int hours@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int nClients@[???]
                       Unresolved local var: qboolean log@[???]
                       Unresolved local var: qboolean conprint@[???]
                       Unresolved local var: qboolean bIsSecure@[???]
                       Unresolved local var: char[32] sz@[???] */
  conprint = false;
  if ((cmd_source == src_command) && (conprint = true, sv.active == false)) {
    Cmd_ForwardToServer();
    return;
  }
  iVar3 = Cmd_Argc();
  local_164 = false;
  if (iVar3 == 2) {
    pcVar5 = Cmd_Argv(1);
    iVar3 = Q_strcasecmp(pcVar5,"log");
    if (iVar3 == 0) {
                    /* Unresolved local var: char[260] szfile@[???] */
      snprintf(local_144,0x104,"%s","status.log");
      unlink(local_144);
      local_164 = true;
    }
  }
  qVar4 = Steam_GSBSecure();
  pcVar7 = "secure";
  pcVar5 = Cvar_VariableString("hostname");
  Host_Status_Printf(conprint,local_164,"hostname:  %s\n",pcVar5);
  if (qVar4 == 0) {
    pcVar7 = "insecure";
  }
  iVar3 = build_number();
  Host_Status_Printf(conprint,local_164,"version :  %i/%s %d %s\n",0x30,gpszVersionString,iVar3,
                     pcVar7);
  if (noip == false) {
    a.ip[0] = net_local_adr.ip[0];
    a.ip[1] = net_local_adr.ip[1];
    a.ip[2] = net_local_adr.ip[2];
    a.ip[3] = net_local_adr.ip[3];
    a.type = net_local_adr.type;
    a.ipx[0] = net_local_adr.ipx[0];
    a.ipx[1] = net_local_adr.ipx[1];
    a.ipx[2] = net_local_adr.ipx[2];
    a.ipx[3] = net_local_adr.ipx[3];
    a.ipx[4] = net_local_adr.ipx[4];
    a.ipx[5] = net_local_adr.ipx[5];
    a.ipx[6] = net_local_adr.ipx[6];
    a.ipx[7] = net_local_adr.ipx[7];
    a.ipx[8] = net_local_adr.ipx[8];
    a.ipx[9] = net_local_adr.ipx[9];
    a.port = net_local_adr.port;
    uVar10 = net_local_adr._16_4_;
    pcVar5 = NET_AdrToString(a);
    Host_Status_Printf(conprint,local_164,"tcp/ip  :  %s\n",pcVar5,uVar10,iVar3,pcVar7);
  }
  Host_Status_Printf(conprint,local_164,"map     :  %s at: %d x, %d y, %d z\n",0x506a28,
                     (int)r_origin[0],(int)r_origin[1],(int)r_origin[2]);
  SV_CountPlayers(local_20);
  Host_Status_Printf(conprint,local_164,"players :  %i active (%i max)\n\n",local_20[0],
                     svs.maxclients);
  pcVar15 = "loss";
  pcVar14 = "ping";
  pcVar9 = "name    ";
  pcVar5 = "time    ";
  pcVar13 = "frag";
  pcVar12 = "uniqueid ";
  pcVar11 = "userid   ";
  pcVar7 = "adr";
  Host_Status_Printf(conprint,local_164,
                     "%-2.2s\t%-9.9s\t%-7.7s\t%-20.20s\t%-4.4s\t%-8.8s\t%-4.4s\t%-4.4s\t%-21.21s\n",
                     &DAT_000e3eaf,"name    ","userid   ","uniqueid ",&DAT_000e3e8d,"time    ",
                     &DAT_000e3e7f,"loss",&DAT_000e3e7b);
  if (0 < svs.maxclients) {
    iVar3 = svs.maxclients;
    cl = svs.clients;
    iVar8 = 1;
    do {
      if (cl->active != false) {
        iVar3 = (int)(realtime - (double)(cl->netchan).connect_time);
        iVar2 = iVar3 / 0x3c;
        if (iVar2 == 0) {
LAB_00078759:
          snprintf(local_40,0x20,"%02i:%02i",iVar2,iVar3);
        }
        else {
          iVar3 = iVar3 % 0x3c;
          if (iVar2 / 0x3c == 0) goto LAB_00078759;
          snprintf(local_40,0x20,"%-2i:%02i:%02i",iVar2 / 0x3c,iVar2 % 0x3c,iVar3);
        }
        pcVar7 = "";
        if (conprint != false) {
          pcVar7 = NET_AdrToString((cl->netchan).remote_address);
        }
        pcVar15 = va("%-4i",(int)cl->packet_loss);
        iVar3 = SV_CalcPing(cl);
        pcVar14 = va("%-4i",iVar3);
        pcVar13 = va("%-4i",(int)(cl->edict->v).frags);
        pcVar12 = SV_GetClientIDString(cl);
        pcVar11 = va("%-7i",cl->userid);
        pcVar9 = va("\"%s\"",cl->name);
        pcVar6 = va("%-2i",iVar8);
        pcVar5 = local_40;
        Host_Status_Printf(conprint,local_164,
                           "%-2.2s\t%-9.9s\t%-7.7s\t%-20.20s\t%-4.4s\t%-8.8s\t%-4.4s\t%-4.4s\t%-21.21s\n"
                           ,pcVar6,pcVar9,pcVar11,pcVar12,pcVar13,pcVar5,pcVar14,pcVar15,pcVar7);
        iVar3 = svs.maxclients;
      }
      cl = cl + 1;
      bVar1 = iVar8 < iVar3;
      iVar8 = iVar8 + 1;
    } while (bVar1);
  }
  Host_Status_Printf(conprint,local_164,"%i users\n",local_20[0],pcVar9,pcVar11,pcVar12,pcVar13,
                     pcVar5,pcVar14,pcVar15,pcVar7);
  return;
}


// Host_Status_Printf  @ 00078300
void Host_Status_Printf(qboolean conprint,qboolean log,char *fmt,...)

{
  char local_1110 [4096];
  char local_110 [264];
  
                    /* Unresolved local var: char[4096] string@[???]
                       Unresolved local var: va_list argptr@[???] */
  vsnprintf(local_1110,0x1000,fmt,&stack0x00000010);
  if (conprint == false) {
    SV_ClientPrintf("%s",local_1110);
  }
  else {
    Con_Printf("%s");
  }
  if (log != false) {
                    /* Unresolved local var: char[260] szfile@[???] */
    snprintf(local_110,0x104,"%s","status.log");
    COM_Log(local_110,"%s",local_1110);
  }
  return;
}


// Host_Status_f  @ 000788e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Status_f(void)

{
  qboolean qVar1;
  bool bVar2;
  netadr_t a;
  netadr_t a_00;
  int iVar3;
  char *pcVar4;
  qboolean qVar5;
  qboolean qVar6;
  qboolean qVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  client_s *client;
  qboolean conprint;
  qboolean log;
  undefined4 uVar12;
  int local_14c;
  int local_148;
  int local_140;
  int local_138;
  int local_134;
  int local_130;
  char local_124 [260];
  int local_20 [4];
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int seconds@[???]
                       Unresolved local var: int minutes@[???]
                       Unresolved local var: int hltv_slots@[???]
                       Unresolved local var: int hltv_specs@[???]
                       Unresolved local var: int hltv_delay@[???]
                       Unresolved local var: char * val@[???]
                       Unresolved local var: int hours@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int nClients@[???]
                       Unresolved local var: qboolean log@[???]
                       Unresolved local var: qboolean conprint@[???]
                       Unresolved local var: qboolean bIsSecure@[???]
                       Unresolved local var: qboolean bWantsToBeSecure@[???]
                       Unresolved local var: qboolean bConnectedToSteam3@[???]
                       Unresolved local var: char * pchConnectionString@[???]
                       Unresolved local var: char * pchSteamUniverse@[???] */
  conprint = false;
  if ((cmd_source == src_command) && (conprint = true, sv.active == false)) {
    Cmd_ForwardToServer();
    return;
  }
  iVar3 = Cmd_Argc();
  log = false;
  if (iVar3 == 2) {
    pcVar4 = Cmd_Argv(1);
    iVar3 = Q_strcasecmp(pcVar4,"log");
    if (iVar3 == 0) {
                    /* Unresolved local var: char[260] szfile@[???] */
      log = true;
      snprintf(local_124,0x104,"%s","status.log");
      unlink(local_124);
    }
  }
  pcVar4 = Cvar_VariableString("hostname");
  Host_Status_Printf(conprint,log,"hostname:  %s\n",pcVar4);
  qVar5 = Steam_GSBSecure();
  qVar6 = Steam_GSBSecurePreference();
  qVar7 = Steam_GSBLoggedOn();
  if ((qVar6 == 0) || (qVar5 != 0)) {
    pcVar4 = "";
  }
  else {
    pcVar4 = "(secure mode enabled, connected to Steam3)";
    if (qVar7 == 0) {
      pcVar4 = "(secure mode enabled, disconnected from Steam3)";
    }
  }
  pcVar9 = "";
  if (sv.active != false) {
    pcVar9 = Steam_GetGSUniverse();
  }
  pcVar11 = "secure";
  iVar3 = GetGameAppID();
  if (qVar5 == 0) {
    pcVar11 = "insecure";
  }
  iVar8 = build_number();
  Host_Status_Printf(conprint,log,"version :  %i/%s %d %s %s%s (%d)\n",0x30,gpszVersionString,iVar8,
                     pcVar11,pcVar4,pcVar9,iVar3);
  if (noip == false) {
    a_00.ip[0] = net_local_adr.ip[0];
    a_00.ip[1] = net_local_adr.ip[1];
    a_00.ip[2] = net_local_adr.ip[2];
    a_00.ip[3] = net_local_adr.ip[3];
    a_00.type = net_local_adr.type;
    a_00.ipx[0] = net_local_adr.ipx[0];
    a_00.ipx[1] = net_local_adr.ipx[1];
    a_00.ipx[2] = net_local_adr.ipx[2];
    a_00.ipx[3] = net_local_adr.ipx[3];
    a_00.ipx[4] = net_local_adr.ipx[4];
    a_00.ipx[5] = net_local_adr.ipx[5];
    a_00.ipx[6] = net_local_adr.ipx[6];
    a_00.ipx[7] = net_local_adr.ipx[7];
    a_00.ipx[8] = net_local_adr.ipx[8];
    a_00.ipx[9] = net_local_adr.ipx[9];
    a_00.port = net_local_adr.port;
    uVar12 = net_local_adr._16_4_;
    pcVar10 = NET_AdrToString(a_00);
    Host_Status_Printf(conprint,log,"tcp/ip  :  %s\n",pcVar10,uVar12,iVar8,pcVar11,pcVar4,pcVar9,
                       iVar3);
  }
  Host_Status_Printf(conprint,log,"map     :  %s at: %d x, %d y, %d z\n",0x506a28,(int)r_origin[0],
                     (int)r_origin[1],(int)r_origin[2],pcVar4,pcVar9,iVar3);
  SV_CountPlayers(local_20);
  local_148 = svs.maxclients;
  Host_Status_Printf(conprint,log,"players :  %i active (%i max)\n\n",local_20[0],svs.maxclients);
  Host_Status_Printf(conprint,log,"#      name userid uniqueid frag time ping loss adr\n");
  if (0 < svs.maxclients) {
    local_14c = 1;
    local_138 = 0;
    local_130 = 0;
    local_134 = 0;
    iVar3 = svs.maxclients;
    client = svs.clients;
LAB_00078ad4:
    do {
      if (client->active != false) {
        local_140 = 0;
        iVar3 = (int)(realtime - (double)(client->netchan).connect_time);
        local_148 = iVar3 / 0x3c;
        if (local_148 != 0) {
          iVar3 = iVar3 % 0x3c;
          local_140 = local_148 / 0x3c;
          if (local_140 != 0) {
            local_148 = local_148 % 0x3c;
          }
        }
        pcVar4 = "BOT";
        if (client->fakeclient == false) {
          pcVar4 = SV_GetClientIDString(client);
        }
        iVar8 = client->userid;
        pcVar9 = va("\"%s\"",client->name);
        Host_Status_Printf(conprint,log,"#%2i %8s %i %s",local_14c,pcVar9,iVar8,pcVar4);
        if (client->proxy == false) {
          Host_Status_Printf(conprint,log," %3i",(int)(client->edict->v).frags,pcVar9,iVar8,pcVar4);
        }
        else {
          pcVar9 = client->userinfo;
          pcVar11 = Info_ValueForKey(pcVar9,"hspecs");
          iVar8 = Q_strlen(pcVar11);
          if (iVar8 != 0) {
            local_134 = Q_atoi(pcVar11);
          }
          pcVar11 = Info_ValueForKey(pcVar9,"hslots");
          iVar8 = Q_strlen(pcVar11);
          if (iVar8 != 0) {
            local_138 = Q_atoi(pcVar11);
          }
          pcVar9 = Info_ValueForKey(pcVar9,"hdelay");
          iVar8 = Q_strlen(pcVar9);
          if (iVar8 != 0) {
            local_130 = Q_atoi(pcVar9);
          }
          iVar8 = local_130;
          Host_Status_Printf(conprint,log," hltv:%u/%u delay:%u",local_134,local_138,local_130);
        }
        if (local_140 == 0) {
          Host_Status_Printf(conprint,log," %02i:%02i",local_148,iVar3,iVar8,pcVar4);
          qVar1 = client->proxy;
          local_140 = local_148;
          local_148 = iVar3;
          iVar3 = iVar8;
        }
        else {
          Host_Status_Printf(conprint,log," %2i:%02i:%02i",local_140,local_148,iVar3,pcVar4);
          qVar1 = client->proxy;
        }
        if (qVar1 == false) {
          local_148 = (int)client->packet_loss;
          local_140 = SV_CalcPing(client);
          Host_Status_Printf(conprint,log," %4i  %3i",local_140,local_148,iVar3);
        }
        if (((conprint == false) && (client->proxy == false)) ||
           ((client->netchan).remote_address.type != NA_IP)) {
          client = client + 1;
          Host_Status_Printf(conprint,log,"\n",local_140,local_148,iVar3);
          bVar2 = svs.maxclients <= local_14c;
          iVar3 = svs.maxclients;
          local_14c = local_14c + 1;
          if (bVar2) break;
          goto LAB_00078ad4;
        }
        local_148 = *(int *)((client->netchan).remote_address.ipx + 8);
        a.ip = (uchar  [4])*(undefined4 *)(client->netchan).remote_address.ip;
        a.type = 3;
        a.ipx._0_4_ = *(undefined4 *)(client->netchan).remote_address.ipx;
        a.ipx._4_4_ = *(undefined4 *)((client->netchan).remote_address.ipx + 4);
        a.ipx[8] = (char)local_148;
        a.ipx[9] = (char)((uint)local_148 >> 8);
        a.port = (short)((uint)local_148 >> 0x10);
        pcVar4 = NET_AdrToString(a);
        Host_Status_Printf(conprint,log," %s\n",pcVar4,local_148,iVar3);
        iVar3 = svs.maxclients;
      }
      client = client + 1;
      bVar2 = local_14c < iVar3;
      local_14c = local_14c + 1;
    } while (bVar2);
  }
  Host_Status_Printf(conprint,log,"%i users\n",local_20[0],local_148);
  return;
}


// Host_Stopdemo_f  @ 00076560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Stopdemo_f(void)

{
  if ((cls.state != ca_dedicated) && (cls.demoplayback != false)) {
    CL_StopPlayback();
    CL_Disconnect();
    return;
  }
  return;
}


// Host_Tell_f  @ 00076860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Tell_f(void)

{
  edict_t_conflict *peVar1;
  client_t *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  client_s *pcVar7;
  char local_5c [76];
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[64] text@[???]
                       Unresolved local var: char * tellmsg@[???] */
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    pcVar2 = host_client;
  }
  else {
    iVar3 = Cmd_Argc();
    pcVar2 = host_client;
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[64] text@[???]
                       Unresolved local var: char * tellmsg@[???] */
    if ((2 < iVar3) && (pcVar4 = Cmd_Args(), pcVar2 = host_client, pcVar4 != (char *)0x0)) {
      snprintf(local_5c,0x40,"%s TELL: ",host_client->name);
      pcVar6 = pcVar4;
      if (*pcVar4 == '\"') {
        pcVar6 = pcVar4 + 1;
        iVar3 = Q_strlen(pcVar6);
        pcVar4[iVar3] = '\0';
      }
      iVar3 = Q_strlen(local_5c);
      iVar5 = Q_strlen(pcVar6);
      if (0x3e - iVar3 < iVar5) {
        pcVar6[0x3e - iVar3] = '\0';
      }
      pcVar4 = Cmd_Argv(1);
      pcVar4 = Q_strstr(pcVar6,pcVar4);
      if (pcVar4 == (char *)0x0) {
        Q_strcat(local_5c,pcVar6);
      }
      else {
        pcVar6 = Cmd_Argv(1);
        iVar3 = Q_strlen(pcVar6);
        Q_strcat(local_5c,pcVar4 + iVar3);
      }
      Q_strcat(local_5c,"\n");
      pcVar2 = host_client;
      if (0 < svs.maxclients) {
        iVar5 = 0;
        iVar3 = svs.maxclients;
        pcVar7 = svs.clients;
        do {
          while (((pcVar7->active == false || (pcVar7->spawned == false)) ||
                 (pcVar7->fakeclient != false))) {
            iVar5 = iVar5 + 1;
            pcVar7 = pcVar7 + 1;
            if (iVar3 <= iVar5) {
              host_client = pcVar2;
              return;
            }
          }
          pcVar4 = Cmd_Argv(1);
          iVar3 = Q_strcasecmp(pcVar7->name,pcVar4);
          peVar1 = sv.edicts;
          if (iVar3 == 0) {
            host_client = pcVar7;
            iVar3 = RegUserMsg("SayText",-1);
            PF_MessageBegin_I(1,iVar3,(float *)0x0,peVar1 + iVar5 + 1);
            PF_WriteByte_I(0);
            PF_WriteString_I(local_5c);
            PF_MessageEnd_I();
            host_client = pcVar2;
            return;
          }
          iVar5 = iVar5 + 1;
          pcVar7 = pcVar7 + 1;
          iVar3 = svs.maxclients;
        } while (iVar5 < svs.maxclients);
      }
    }
  }
  host_client = pcVar2;
  return;
}


// Host_TogglePause_f  @ 00076300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_TogglePause_f(void)

{
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (pausable.value != 0.0) {
    sv.paused = sv.paused ^ true;
    if (sv.paused == false) {
      SV_BroadcastPrintf("%s unpaused the game\n",pr_strings + (sv_player->v).netname);
    }
    else {
      SV_BroadcastPrintf("%s paused the game\n",pr_strings + (sv_player->v).netname);
    }
    MSG_WriteByte(&sv.reliable_datagram,0x18);
    MSG_WriteByte(&sv.reliable_datagram,sv.paused);
    return;
  }
  SV_ClientPrintf("Pause not allowed.\n");
  return;
}


// Host_Unpause_f  @ 00076590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Unpause_f(void)

{
  if (cl.levelname[0] != '\0') {
    if (cmd_source == src_command) {
      Cmd_ForwardToServer();
      return;
    }
    if (pausable.value != 0.0) {
      sv.paused = false;
      MSG_WriteByte(&sv.reliable_datagram,0x18);
      MSG_WriteByte(&sv.reliable_datagram,sv.paused);
    }
  }
  return;
}


// Host_UpdateScreen  @ 00075170
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_UpdateScreen(void)

{
  if (((gfBackground == false) && (SCR_UpdateScreen(), cl_inmovie != false)) &&
     (scr_con_current == 0.0)) {
    VID_WriteBuffer((char *)0x0);
  }
  return;
}


// Host_UpdateSounds  @ 000751c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_UpdateSounds(void)

{
  if (gfBackground != false) {
    return;
  }
  S_PrintStats();
  return;
}


// Host_UpdateStats  @ 00077e20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_UpdateStats(void)

{
  int32 iVar1;
  __pid_t _Var2;
  FILE *__stream;
  double dVar3;
  char local_105c [4096];
  sysinfo local_5c;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  int local_10 [2];
  
  if (startTime == 0) {
    dVar3 = Sys_FloatTime();
    startTime = (int32)dVar3;
  }
  dVar3 = Sys_FloatTime();
  if (dVar3 <= (double)Host_UpdateStats::last + 1.0) {
    return;
  }
                    /* Unresolved local var: sysinfo infos@[???]
                       Unresolved local var: int32 dummy@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: char[4096] statFile@[???]
                       Unresolved local var: int32 now@[???]
                       Unresolved local var: int32 ctime@[???]
                       Unresolved local var: int32 stime@[???]
                       Unresolved local var: int32 start_time@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: int32 runticks@[???]
                       Unresolved local var: int32 cputicks@[???] */
  time((time_t *)0x0);
  _Var2 = getpid();
  snprintf(local_105c,0x1000,"/proc/%i/stat",_Var2);
  __stream = fopen(local_105c,"r");
  if (__stream != (FILE *)0x0) {
    sysinfo(&local_5c);
    __isoc99_fscanf(__stream,
                    "%d %s %c %d %d %d %d %d %lu %lu \t\t\t%lu %lu %lu %ld %ld %ld %ld %ld %ld %lu \t\t\t%lu %ld %lu %lu %lu %lu %lu %lu %lu %lu \t\t\t%lu %lu %lu %lu %lu %lu"
                    ,local_1c,local_105c,local_1c,local_1c,local_1c,local_1c,local_1c,local_1c,
                    local_1c,local_1c,local_1c,local_1c,local_1c,&local_18,&local_14,local_1c,
                    local_1c,local_1c,local_1c,local_1c,local_10,local_1c,local_1c,local_1c,local_1c
                    ,local_1c,local_1c,local_1c,local_1c,local_1c,local_1c,local_1c,local_1c,
                    local_1c,local_1c,local_1c);
    fclose(__stream);
    local_10[0] = local_5c.uptime * 100 - local_10[0];
    local_14 = local_14 + local_18;
    if (Host_UpdateStats::lexical_block_0::lastcputicks == 0) {
      Host_UpdateStats::lexical_block_0::lastcputicks = local_14;
    }
    iVar1 = local_10[0];
    if (Host_UpdateStats::lexical_block_0::lastrunticks != 0) {
      cpuPercent = (double)(local_14 - Host_UpdateStats::lexical_block_0::lastcputicks) /
                   (double)(local_10[0] - Host_UpdateStats::lexical_block_0::lastrunticks);
      iVar1 = Host_UpdateStats::lexical_block_0::lastrunticks;
    }
    Host_UpdateStats::lexical_block_0::lastrunticks = iVar1;
    dVar3 = Sys_FloatTime();
    if ((double)Host_UpdateStats::lexical_block_0::lastAvg + 5.0 < dVar3) {
      Host_UpdateStats::lexical_block_0::lastcputicks = local_14;
      Host_UpdateStats::lexical_block_0::lastrunticks = local_10[0];
      dVar3 = Sys_FloatTime();
      Host_UpdateStats::lexical_block_0::lastAvg = (float)dVar3;
    }
    if (cpuPercent <= 0.999) {
      if (cpuPercent < 0.0) {
        cpuPercent = 0.0;
        dVar3 = Sys_FloatTime();
        goto LAB_0007804b;
      }
    }
    else {
      cpuPercent = 0.999;
    }
  }
  dVar3 = Sys_FloatTime();
LAB_0007804b:
  Host_UpdateStats::last = (float)dVar3;
  return;
}


// Host_ValidSave  @ 00079830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Host_ValidSave(void)

{
  int local_10;
  
  local_10 = 0;
  if (cmd_source == src_command) {
    if (sv.active == false) {
      Con_Printf("Not playing a local game.\n");
      local_10 = 0;
    }
    else {
      if (svs.maxclients != 1) {
        Con_Printf("Can\'t save multiplayer games.\n");
        return 0;
      }
      if ((cls.state != ca_active) || (cls.signon != 2)) {
        Con_Printf("Can\'t save during transition.\n");
        return 0;
      }
      if (cl.intermission == 0) {
        local_10 = 1;
        if (((svs.clients)->active != false) && (((svs.clients)->edict->v).health <= 0.0)) {
          Con_Printf("Can\'t savegame with a dead player\n");
          local_10 = 0;
        }
      }
      else {
        local_10 = 0;
        Con_Printf("Can\'t save in intermission.\n");
      }
    }
  }
  return local_10;
}


// Host_Version  @ 00075910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Version(void)

{
  FileHandle_t file;
  uint size;
  char *pOutput;
  char *data;
  int iVar1;
  int iVar2;
  char local_140 [260];
  char local_3c [44];
  
                    /* Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char * buffer@[???]
                       Unresolved local var: int bufsize@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char * pbuf@[???]
                       Unresolved local var: char * pstart@[???]
                       Unresolved local var: int gotKeys@[???] */
  Q_strcpy(gpszVersionString,"1.0.1.4");
  Q_strcpy(gpszProductString,"valve");
  builtin_strncpy(local_140,"steam.inf",10);
  file = FS_Open(local_140,"r");
  if (file != (FileHandle_t)0x0) {
    size = FS_Size(file);
    pOutput = Mem_Malloc(size + 1);
                    /* Unresolved local var: char[32] szSteamVersionId@[???] */
    FS_Read(pOutput,size,1,file);
    FS_Close(file);
    pOutput[size] = '\0';
    iVar2 = 0;
    data = pOutput;
LAB_000759c3:
    data = COM_Parse(data);
    if (data != (char *)0x0) {
      do {
        iVar1 = Q_strlen(com_token);
        if ((iVar1 < 1) || (1 < iVar2)) break;
        iVar1 = Q_strlen("PatchVersion=");
        iVar1 = Q_strnicmp(com_token,"PatchVersion=",iVar1);
        if (iVar1 == 0) {
          iVar1 = Q_strlen("PatchVersion=");
          Q_strncpy(gpszVersionString,com_token + iVar1,0x1f);
          gpszVersionString[0x1f] = '\0';
          iVar1 = COM_CheckParm("-steam");
          if (iVar1 != 0) {
            FS_GetInterfaceVersion(local_3c,0x1f);
            iVar1 = Q_strlen("PatchVersion=");
            snprintf(gpszVersionString,0x20,"%s/%s",com_token + iVar1,local_3c);
            gpszVersionString[0x1f] = '\0';
          }
        }
        else {
          iVar1 = Q_strlen("ProductName=");
          iVar1 = Q_strnicmp(com_token,"ProductName=",iVar1);
          if (iVar1 != 0) goto LAB_000759c3;
          iVar1 = Q_strlen("ProductName=");
          Q_strncpy(gpszProductString,com_token + iVar1,0x1f);
          gpszProductString[0x1f] = '\0';
        }
        iVar2 = iVar2 + 1;
        data = COM_Parse(data);
        if (data == (char *)0x0) break;
      } while( true );
    }
    if (pOutput != (char *)0x0) {
      Mem_Free(pOutput);
    }
  }
  if (cls.state != ca_dedicated) {
    Con_DPrintf("Protocol version %i\nExe version %s (%s)\n",0x30,gpszVersionString,
                gpszProductString);
    iVar2 = build_number();
    Con_DPrintf("Exe build: 19:52:19 Aug  3 2020 (%i)\n",iVar2);
    return;
  }
  Con_Printf("Protocol version %i\nExe version %s (%s)\n");
  iVar2 = build_number();
  Con_Printf("Exe build: 19:52:19 Aug  3 2020 (%i)\n",iVar2);
  return;
}


// Host_Version_f  @ 000763d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Version_f(void)

{
  int iVar1;
  
  Con_Printf("Protocol version %i\nExe version %s (%s)\n",0x30,gpszVersionString,gpszProductString);
  iVar1 = build_number();
  Con_Printf("Exe build: 19:52:19 Aug  3 2020 (%i)\n",iVar1);
  return;
}


// Host_VoiceRecordStart_f  @ 0007ddf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_VoiceRecordStart_f(void)

{
  char *pMicInputFile;
  char *pDecompressedFile;
  char *pUncompressedFile;
  
  if (cls.state == ca_active) {
                    /* Unresolved local var: char * pUncompressedFile@[???]
                       Unresolved local var: char * pDecompressedFile@[???]
                       Unresolved local var: char * pInputFile@[???] */
    pMicInputFile = (char *)0x0;
    pDecompressedFile = "voice_decompressed.wav";
    pUncompressedFile = "voice_micdata.wav";
    if ((int)voice_recordtofile.value == 0) {
      pDecompressedFile = (char *)0x0;
      pUncompressedFile = (char *)0x0;
    }
    if ((int)voice_inputfromfile.value != 0) {
      pMicInputFile = "voice_input.wav";
    }
    Voice_RecordStart(pUncompressedFile,pDecompressedFile,pMicInputFile);
  }
  return;
}


// Host_VoiceRecordStop_f  @ 0007de40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_VoiceRecordStop_f(void)

{
  qboolean qVar1;
  
  if (cls.state == ca_active) {
    qVar1 = Voice_IsRecording();
    if (qVar1 != false) {
      CL_AddVoiceToDatagram(true);
      Voice_RecordStop();
      return;
    }
  }
  return;
}


// Host_WriteConfiguration  @ 00073dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_WriteConfiguration(void)

{
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: kbutton_t * ml@[???]
                       Unresolved local var: kbutton_t * jl@[???]
                       Unresolved local var: qboolean bSetFileToReadOnly@[???] */
  return;
}


// Host_WriteCustomConfig  @ 00073dd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_WriteCustomConfig(void)

{
  int iVar1;
  char *pcVar2;
  char local_111 [269];
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: kbutton_t * ml@[???]
                       Unresolved local var: kbutton_t * jl@[???]
                       Unresolved local var: bool[261] configname@[???]
                       Unresolved local var: char * pchExtension@[???] */
  iVar1 = Cmd_Argc();
  if (((iVar1 == 1) || (pcVar2 = Cmd_Args(), pcVar2 == (char *)0x0)) ||
     (pcVar2 = Cmd_Args(), *pcVar2 == '\0')) {
    Con_Printf("writecfg: writecfg <filename>\n");
  }
  else {
    pcVar2 = Cmd_Args();
    snprintf(local_111,0x101,"%s",pcVar2);
    if ((((local_111[0] == '/') || (local_111[0] == '\0')) ||
        ((pcVar2 = Q_strstr(local_111,".."), pcVar2 != (char *)0x0 ||
         ((pcVar2 = Q_strstr(local_111,"\\"), pcVar2 != (char *)0x0 ||
          (pcVar2 = Q_strstr(local_111,":"), pcVar2 != (char *)0x0)))))) ||
       (pcVar2 = Q_strstr(local_111,"./"), pcVar2 != (char *)0x0)) {
      Con_Printf("skipping writecfg output, invalid filename %s given (invalid characters in filename)\n"
                 ,local_111);
      return;
    }
  }
  return;
}


