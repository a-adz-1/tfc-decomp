// Host_AutoSave_f  @ 000c1420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_AutoSave_f(void)

{
  int in_GS_OFFSET;
  double dVar1;
  char local_b0 [79];
  undefined1 local_61;
  char local_60 [80];
  int local_10;
  
                    /* Unresolved local var: char[80] szComment@[???]
                       Unresolved local var: char[80] szTemp@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    if (sv.active == false) {
      Con_Printf("Not playing a local game.\n");
    }
    else if (svs.maxclients == 1) {
      if ((cls.state == ca_active) && (cls.signon == 2)) {
        if (cl.intermission == 0) {
          if (((svs.clients)->active == false) || (0.0 < ((svs.clients)->edict->v).health)) {
                    /* Unresolved local var: char[80] szComment@[???]
                       Unresolved local var: char[80] szTemp@[???] */
            (*g_pSaveGameCommentFunc)(local_60,0x50);
            dVar1 = fmod(sv.time,60.0);
            __snprintf_chk(local_b0,0x4f,1,0x50,0x258d8e,local_60,(int)((float)sv.time / 60.0),
                           (int)dVar1);
            local_61 = 0;
            SaveGameSlot("autosave",local_b0);
          }
          else {
            Con_Printf("Can\'t savegame with a dead player\n");
          }
        }
        else {
          Con_Printf("Can\'t save in intermission.\n");
        }
      }
      else {
        Con_Printf("Can\'t save during transition.\n");
      }
    }
    else {
      Con_Printf("Can\'t save multiplayer games.\n");
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Career_f  @ 000c2650
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Career_f(void)

{
  if (cmd_source != src_command) {
    return;
  }
  g_careerState = CAREER_LOADING;
  Host_Map_f();
  return;
}


// Host_Changelevel2_f  @ 000c1ae0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Changelevel2_f(void)

{
  int iVar1;
  char *pcVar2;
  char *src;
  SAVERESTOREDATA *p;
  int in_GS_OFFSET;
  char local_e0 [63];
  undefined1 local_a1;
  char local_a0 [63];
  undefined1 local_61;
  char local_60 [63];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[64] level@[???]
                       Unresolved local var: char[64] oldlevel@[???]
                       Unresolved local var: char[64] _startspot@[???]
                       Unresolved local var: char * startspot@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: qboolean newUnit@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  giActive = 4;
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("changelevel2 <levelname> : continue game on a new level in the unit\n");
    goto LAB_000c1b47;
  }
  if (((sv.active == false) || (cls.demoplayback != false)) || (sv.paused != false)) {
    Con_Printf("Only the server may changelevel\n");
    goto LAB_000c1b47;
  }
  if (1 < svs.maxclients) {
    Con_Printf("changelevel2 <levelname> : not for use with multiplayer games\n");
    goto LAB_000c1b47;
  }
  SCR_BeginLoadingPlaque(true);
  S_StopAllSounds(true);
  pcVar2 = Cmd_Argv(1);
  Q_strncpy(local_e0,pcVar2,0x3f);
  local_a1 = 0;
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
LAB_000c1d30:
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = local_60;
    src = Cmd_Argv(2);
    Q_strncpy(pcVar2,src,0x3f);
    local_21 = 0;
    if (local_60[0] == '\0') goto LAB_000c1d30;
  }
  Q_strncpy(local_a0,sv.name,0x3f);
  local_61 = 0;
  p = SaveGamestate();
  SV_ServerShutdown();
  FS_LogLevelLoadStarted(local_e0);
  iVar1 = SV_SpawnServer(false,local_e0,pcVar2);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Host_Changelevel2: Couldn\'t load map %s\n",local_e0);
  }
  if (p != (SAVERESTOREDATA *)0x0) {
    if (p->pTokens != (char **)0x0) {
      Mem_Free(p->pTokens);
      p->pTokens = (char **)0x0;
      p->tokenCount = 0;
    }
    Mem_Free(p);
    gGlobalVariables.pSaveData = (void *)0x0;
  }
  iVar1 = LoadGamestate(local_e0,0);
  if (iVar1 == 0) {
    SV_LoadEntities();
    LoadAdjacentEntities(local_a0,pcVar2);
    sv.paused = true;
    sv.loadgame = true;
    gGlobalVariables.time = (float)sv.time;
    if (sv_newunit.value != 0.0) {
      Host_ClearSaveDirectory();
    }
  }
  else {
    LoadAdjacentEntities(local_a0,pcVar2);
    sv.paused = true;
    sv.loadgame = true;
    gGlobalVariables.time = (float)sv.time;
  }
  SV_ActivateServer(0);
  Steam_UpdateRichPresence();
LAB_000c1b47:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Changelevel_f  @ 000bb150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Changelevel_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  char local_90 [63];
  undefined1 local_51;
  char local_50 [63];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[64] level@[???]
                       Unresolved local var: char[64] _startspot@[???]
                       Unresolved local var: char * startspot@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
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
      Q_strncpy(local_90,pcVar3,0x3f);
      local_51 = 0;
      iVar1 = Cmd_Argc();
      if (iVar1 != 2) {
        pcVar2 = local_50;
        pcVar3 = Cmd_Argv(2);
        Q_strncpy(pcVar2,pcVar3,0x3f);
        local_11 = 0;
      }
      SCR_BeginLoadingPlaque(true);
      S_StopAllSounds(true);
      SV_InactivateClients();
      SV_ServerShutdown();
      SV_SpawnServer(false,local_90,pcVar2);
      SV_LoadEntities();
      SV_ActivateServer(1);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_CheckConnectionFailure  @ 000b8ec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_CheckConnectionFailure(void)

{
  if (((cls.state == ca_disconnected) && (*scr_connectmsg.string == '\0')) &&
     ((((byte)giSubState & 4) != 0 || (console.value == 0.0)))) {
    if (0 < Host_CheckConnectionFailure::frames) {
      Host_CheckConnectionFailure::frames = Host_CheckConnectionFailure::frames + -1;
      return;
    }
    giActive = 2;
  }
  Host_CheckConnectionFailure::frames = 5;
  return;
}


// Host_CheckDyanmicStructures  @ 000b8600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_CheckDyanmicStructures(void)

{
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if ((svs.clients != (client_s *)0x0) && (0 < svs.maxclientslimit)) {
    iVar3 = 0;
    iVar1 = svs.maxclientslimit;
    pcVar2 = svs.clients;
    do {
      if (pcVar2->frames != (client_frame_t *)0x0) {
        SV_ClearFrames(&pcVar2->frames);
        iVar1 = svs.maxclientslimit;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while ((pcVar2 != (client_s *)0x0) && (iVar3 < iVar1));
  }
  return;
}


// Host_ClearClients  @ 000b7f80
void Host_ClearClients(qboolean bFramesOnly)

{
  int iVar1;
  netadr_t adr;
  int iVar2;
  client_frame_t *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: client_frame_t * frame@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar5 = 0;
    do {
      pcVar3 = host_client->frames;
      if ((pcVar3 != (client_frame_t *)0x0) && (0 < SV_UPDATE_BACKUP)) {
        iVar6 = 0;
        iVar4 = 0;
        while( true ) {
          pcVar3 = (client_frame_t *)((int)(pcVar3->clientdata).origin + iVar6 + -0xc);
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0x1870;
          SV_ClearPacketEntities(pcVar3);
          *(undefined4 *)&pcVar3->senttime = 0;
          iVar2 = SV_UPDATE_BACKUP;
          *(undefined4 *)((int)&pcVar3->senttime + 4) = 0;
          pcVar3->ping_time = -1.0;
          if (iVar2 <= iVar4) break;
          pcVar3 = host_client->frames;
        }
      }
      if ((host_client->netchan).remote_address.type != NA_UNUSED) {
                    /* Unresolved local var: netadr_t save@[???] */
        adr = (host_client->netchan).remote_address;
        Q_memset(&host_client->netchan,0,0x33b4);
        Netchan_Setup(NS_SERVER,&host_client->netchan,adr,
                      ((int)host_client - (int)svs.clients >> 3) * 0x4ffec005,&host_client,
                      SV_GetFragmentSize);
      }
      iVar5 = iVar5 + 1;
      COM_ClearCustomizationList(&host_client->customdata,false);
      host_client = host_client + 1;
    } while (iVar5 < svs.maxclients);
  }
  if (bFramesOnly == false) {
    host_client = svs.clients;
    if (0 < svs.maxclientslimit) {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        SV_ClearFrames(&host_client->frames);
        host_client = host_client + 1;
      } while (iVar5 < svs.maxclientslimit);
    }
    Q_memset(svs.clients,0,svs.maxclientslimit * 0x6668);
    if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
      SV_AllocClientFrames();
      return;
    }
  }
  else if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_ClearGameState  @ 000c2dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_ClearGameState(void)

{
  S_StopAllSounds(true);
  Host_ClearSaveDirectory();
  if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000c2de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEntityInterface.pfnResetGlobalState)();
    return;
  }
  return;
}


// Host_ClearMemory  @ 000b8650
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
    if ((svs.clients != (client_s *)0x0) && (0 < svs.maxclientslimit)) {
      iVar3 = 0;
      iVar2 = svs.maxclientslimit;
      pcVar1 = svs.clients;
      do {
        if (pcVar1->frames != (client_frame_t *)0x0) {
          SV_ClearFrames(&pcVar1->frames);
          iVar2 = svs.maxclientslimit;
        }
        iVar3 = iVar3 + 1;
        pcVar1 = pcVar1 + 1;
      } while ((iVar3 < iVar2) && (pcVar1 != (client_s *)0x0));
    }
    Hunk_FreeToLowMark(host_hunklevel);
  }
  cls.signon = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  SV_ClearCaches();
  Q_memset(&sv,0,0x473ac);
  CL_ClearClientState();
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


// Host_ClearSaveDirectory  @ 000c1850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_ClearSaveDirectory(void)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint *puVar4;
  uint *puVar5;
  int in_GS_OFFSET;
  uint local_114 [64];
  undefined1 uStack_11;
  int local_10;
  
                    /* Unresolved local var: char[260] szName@[???]
                       Unresolved local var: char * pfn@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  snprintf((char *)local_114,0x104,"%s",Host_SaveGameDirectory::szDirectory);
  puVar5 = local_114;
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
  __strncat_chk(local_114,0x258d63,
                &uStack_11 + -(int)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))),
                0x104);
  COM_FixSlashes((char *)local_114);
  pcVar3 = Sys_FindFirstPathID((char *)local_114,"GAMECONFIG");
  if (pcVar3 != (char *)0x0) {
    Sys_FindClose();
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    snprintf((char *)local_114,0x104,"%s",Host_SaveGameDirectory::szDirectory);
    COM_FixSlashes((char *)local_114);
    FS_CreateDirHierarchy((char *)local_114,"GAMECONFIG");
    puVar5 = local_114;
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
    __strncat_chk(local_114,0x258d63,
                  &uStack_11 + -(int)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))),
                  0x104);
    pcVar3 = Sys_FindFirstPathID((char *)local_114,"GAMECONFIG");
    while (pcVar3 != (char *)0x0) {
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
      __snprintf_chk(local_114,0x104,1,0x104,&LAB_0026291c,Host_SaveGameDirectory::szDirectory,
                     pcVar3);
      FS_RemoveFile((char *)local_114,"GAMECONFIG");
      pcVar3 = Sys_FindNext((char *)0x0);
    }
  }
  Sys_FindClose();
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_ClientCommands  @ 000b7be0
void Host_ClientCommands(char *fmt,...)

{
  int in_GS_OFFSET;
  char local_410 [1023];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (host_client->fakeclient == false) {
    __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000008);
    local_11 = 0;
    MSG_WriteByte(&(host_client->netchan).message,9);
    MSG_WriteString(&(host_client->netchan).message,local_410);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_ComputeFPS  @ 000b8a90
void Host_ComputeFPS(double frametime)

{
  rolling_fps = frametime * 0.4 + rolling_fps * 0.6;
  return;
}


// Host_Crash_f  @ 000c3270
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Crash_f(void)

{
                    /* Unresolved local var: int * p@[???] */
  _DAT_00000000 = 0xdeadbeef;
  return;
}


// Host_Demos_f  @ 000bb960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Demos_f(void)

{
  if (cls.state != ca_dedicated) {
    if (cls.demonum == -1) {
      cls.demonum = 0;
      CL_Disconnect_f();
    }
    else {
      CL_Disconnect_f();
                    /* Unresolved local var: char[1024] str@[???] */
    }
    if (cls.demonum != -1) {
      SCR_BeginLoadingPlaque(false);
      if (((cls.demos[cls.demonum][0] != '\0') && (cls.demonum != 0x20)) ||
         (cls.demonum = 0, cls.demos[0][0] != '\0')) {
        Host_NextDemo();
        return;
      }
      Con_Printf("No demos listed with startdemos\n");
      cls.demonum = -1;
    }
  }
  return;
}


// Host_EndGame  @ 000b8350
void Host_EndGame(char *message,...)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined1 local_410 [1024];
  undefined4 local_10;
  
                    /* Unresolved local var: int oldn@[???]
                       Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  local_10 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,message,&stack0x00000008);
  Con_DPrintf("Host_EndGame: %s\n",local_410);
  iVar1 = cls.demonum;
  if (sv.active != false) {
                    /* Unresolved local var: int i@[???] */
    Host_ShutdownServer(false);
  }
  cls.demonum = iVar1;
  if (cls.state != ca_dedicated) {
    if (iVar1 != -1) {
      CL_Disconnect_f();
      cls.demonum = iVar1;
      Host_NextDemo();
                    /* WARNING: Subroutine does not return */
      __longjmp_chk(host_enddemo,1);
    }
    CL_Disconnect();
    Cbuf_AddText("cd stop\n");
    Cbuf_Execute();
                    /* WARNING: Subroutine does not return */
    __longjmp_chk(host_abortserver,1);
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Host_EndGame: %s\n",local_410);
}


// Host_EndSection  @ 000c3190
void Host_EndSection(char *pszSection)

{
  int iVar1;
  
  giActive = 2;
  giSubState = 1;
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


// Host_Error  @ 000b8450
void Host_Error(char *error,...)

{
  int in_GS_OFFSET;
  undefined1 local_410 [1024];
  undefined4 local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  local_10 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  if (Host_Error::inerror != false) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Host_Error: recursively entered");
  }
  Host_Error::inerror = true;
  SCR_EndLoadingPlaque();
  __vsnprintf_chk(local_410,0x400,1,0x400,error,&stack0x00000008);
  if ((sv.active == false) && (developer.value != 0.0)) {
    CL_WriteMessageHistory(0,0);
  }
  Con_Printf("Host_Error: %s\n",local_410);
  if (sv.active != false) {
                    /* Unresolved local var: int i@[???] */
    Host_ShutdownServer(false);
  }
  if (cls.state == ca_dedicated) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Host_Error: %s\n",local_410);
  }
  CL_Disconnect();
  cls.demonum = -1;
  Host_Error::inerror = false;
                    /* WARNING: Subroutine does not return */
  __longjmp_chk(host_abortserver,1);
}


// Host_FilterTime  @ 000b8770
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
                    /* Unresolved local var: float fps@[???] */
  realtime = (double)time * (double)sys_timescale.value + realtime;
  if (g_bIsDedicatedServer != false) {
    if (Host_FilterTime::lexical_block_0::command_line_ticrate == -1) {
      Host_FilterTime::lexical_block_0::command_line_ticrate = COM_CheckParm("-sys_ticrate");
    }
    fVar1 = sys_ticrate.value;
    if (0 < Host_FilterTime::lexical_block_0::command_line_ticrate) {
      dVar4 = strtod(com_argv[Host_FilterTime::lexical_block_0::command_line_ticrate + 1],
                     (char **)0x0);
      fVar1 = (float)dVar4;
    }
    dVar2 = realtime - oldrealtime;
    if ((0.0 < (double)fVar1) && (dVar2 < 1.0 / ((double)fVar1 + 1.0))) {
      return false;
    }
    goto LAB_000b8862;
  }
  if ((sv.active == false) && ((cls.state & ~ca_uninitialized) != ca_disconnected)) {
    dVar4 = 31.0;
    if (fps_override.value == 0.0) goto LAB_000b8960;
LAB_000b88d0:
    if (1 < cl.maxclients) {
      dVar2 = dVar4;
      if (dVar4 < 20.0) {
        dVar4 = 20.0;
        goto LAB_000b89ca;
      }
      goto LAB_000b8990;
    }
  }
  else {
    dVar4 = (double)fps_max.value;
    if (0.5 <= dVar4) {
      if (fps_override.value != 0.0) goto LAB_000b88d0;
      if (100.0 < dVar4) {
        dVar2 = 100.0;
        goto LAB_000b8990;
      }
    }
    else {
      dVar4 = 0.5;
    }
LAB_000b8960:
    dVar2 = dVar4;
    if ((1 < cl.maxclients) && (dVar2 = 20.0, 20.0 <= dVar4)) {
      dVar2 = dVar4;
    }
LAB_000b8990:
    dVar4 = dVar2;
    if ((gl_vsync.value != 0.0) && (dVar4 = 100.0, fps_override.value != 0.0)) {
      dVar4 = dVar2;
    }
  }
LAB_000b89ca:
  dVar2 = realtime - oldrealtime;
  if ((cls.timedemo == false) && (dVar2 < (double)sys_timescale.value / (dVar4 + 0.5))) {
    return false;
  }
LAB_000b8862:
  oldrealtime = realtime;
  if (dVar2 <= 0.25) {
    host_frametime = dVar2;
    return true;
  }
  host_frametime = 0.25;
  return true;
}


// Host_FindRecentSave  @ 000bddb0
char * Host_FindRecentSave(char *pNameBuf,int nNameBufSize)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int32 iVar4;
  int in_GS_OFFSET;
  int local_230;
  char local_228 [260];
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char * findfn@[???]
                       Unresolved local var: char[260] basefilename@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: int32 newest@[???]
                       Unresolved local var: int32 ft@[???]
                       Unresolved local var: char[260] szPath@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  __snprintf_chk(pNameBuf,nNameBufSize,1,0xffffffff,&LAB_00258be5,
                 Host_SaveGameDirectory::szDirectory);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  snprintf(local_124,0x104,"%s",Host_SaveGameDirectory::szDirectory);
  pcVar2 = Sys_FindFirst(pNameBuf,local_228);
  if (pcVar2 == (char *)0x0) {
    Sys_FindClose();
    pcVar2 = (char *)0x0;
  }
  else {
    bVar1 = false;
    do {
      while ((iVar3 = Q_strlen(pcVar2), iVar3 == 0 ||
             (iVar3 = Q_strcasecmp(pcVar2,&LAB_00258bed), iVar3 == 0))) {
LAB_000bdeb8:
        pcVar2 = Sys_FindNext(local_228);
        if (pcVar2 == (char *)0x0) goto LAB_000bdfc0;
      }
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
      __snprintf_chk(local_124,0x104,1,0x104,&LAB_0026291c,Host_SaveGameDirectory::szDirectory,
                     pcVar2);
      iVar4 = FS_GetFileTime(local_124);
      if ((iVar4 < 1) || ((!(bool)(bVar1 ^ 1) && (bVar1 = true, iVar4 <= local_230))))
      goto LAB_000bdeb8;
      Q_strcpy(pNameBuf,pcVar2);
      bVar1 = true;
      pcVar2 = Sys_FindNext(local_228);
      local_230 = iVar4;
    } while (pcVar2 != (char *)0x0);
LAB_000bdfc0:
    Sys_FindClose();
    pcVar2 = (char *)0x0;
    if (bVar1) {
      pcVar2 = pNameBuf;
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pcVar2;
}


// Host_Fly_f  @ 000bb080
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Fly_f(void)

{
  if (cmd_source != src_command) {
    if (gGlobalVariables.deathmatch == 0.0) {
      if ((sv_player->v).movetype == 5) {
        (sv_player->v).movetype = 3;
        SV_ClientPrintf("flymode OFF\n");
      }
      else {
        (sv_player->v).movetype = 5;
        SV_ClientPrintf("flymode ON\n");
      }
    }
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// Host_Frame  @ 000b9250
int Host_Frame(float time,int iState,int *stateInfo)

{
  double dVar1;
  int iVar2;
  client_s *pcVar3;
  int iVar4;
  double local_2c;
  double local_24;
  
                    /* Unresolved local var: double time1@[???]
                       Unresolved local var: double time2@[???] */
  iVar2 = _setjmp((__jmp_buf_tag *)host_abortserver);
  if (iVar2 != 0) {
    return giActive;
  }
  if ((giActive != 3) || (g_iQuitCommandIssued == 0)) {
    giActive = iState;
  }
  *stateInfo = 0;
  if (host_profile.value != 0.0) {
    local_2c = Sys_FloatTime();
  }
  _Host_Frame(time);
  if (host_profile.value == 0.0) {
    if (giStateInfo == 0) {
      return giActive;
    }
  }
  else {
    local_24 = Sys_FloatTime();
    if (giStateInfo == 0) goto LAB_000b9316;
  }
  *stateInfo = giStateInfo;
  giStateInfo = 0;
  Cbuf_Execute();
LAB_000b9316:
  if (host_profile.value != 0.0) {
    Host_Frame::lexical_block_0::timetotal =
         (local_24 - local_2c) + Host_Frame::lexical_block_0::timetotal;
    iVar2 = Host_Frame::lexical_block_0::timecount + 1;
    Host_Frame::lexical_block_0::timecount = iVar2;
    if (999 < iVar2) {
      dVar1 = Host_Frame::lexical_block_0::timetotal * 1000.0;
      Host_Frame::lexical_block_0::timecount = 0;
      Host_Frame::lexical_block_0::timetotal = 0.0;
      if (svs.maxclients < 1) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        pcVar3 = svs.clients;
        do {
          iVar4 = (iVar4 + 1) - (uint)(pcVar3->active == false);
          pcVar3 = pcVar3 + 1;
        } while (svs.clients + svs.maxclients != pcVar3);
      }
      Con_Printf("host_profile: %2i clients %2i msec\n",iVar4,(int)(dVar1 / (double)iVar2));
    }
  }
  return giActive;
}


// Host_FullInfo_f  @ 000ba550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_FullInfo_f(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  char local_410 [511];
  undefined1 uStack_211;
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] key@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = Cmd_Argc();
  if (iVar3 == 2) {
    pcVar4 = Cmd_Argv(1);
    cVar2 = *pcVar4;
    if (cVar2 == '\\') {
      cVar2 = pcVar4[1];
      pcVar4 = pcVar4 + 1;
    }
    while (cVar2 != '\0') {
      if (cVar2 == '\\') {
        iVar3 = 0;
LAB_000ba5fa:
        local_410[iVar3] = '\0';
        cVar2 = *pcVar4;
      }
      else {
        pcVar5 = pcVar4 + 1;
        pcVar6 = pcVar4 + 0x1ff;
        iVar3 = 1;
        do {
          cVar1 = *pcVar5;
          pcVar4 = pcVar5;
          local_410[0] = cVar2;
          if ((cVar1 == '\0') || (cVar1 == '\\')) goto LAB_000ba5fa;
          pcVar5 = pcVar5 + 1;
          local_410[iVar3] = cVar1;
          iVar3 = iVar3 + 1;
        } while (pcVar5 != pcVar6);
        uStack_211 = 0;
        cVar2 = *pcVar5;
        pcVar4 = pcVar5;
      }
      if (cVar2 == '\0') {
        Con_Printf("MISSING VALUE\n");
        break;
      }
      cVar2 = pcVar4[1];
      if ((cVar2 == '\\') || (cVar2 == '\0')) {
        pcVar4 = pcVar4 + 1;
        iVar3 = 0;
      }
      else {
        pcVar4 = pcVar4 + 2;
        iVar3 = 1;
        do {
          cVar1 = *pcVar4;
          local_210[0] = cVar2;
          if ((cVar1 == '\0') || (cVar1 == '\\')) break;
          local_210[iVar3] = cVar1;
          iVar3 = iVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (iVar3 != 0x1ff);
      }
      local_210[iVar3] = '\0';
      pcVar4 = pcVar4 + (*pcVar4 != '\0');
      if (cmd_source == src_command) {
        Info_SetValueForKey(cls.userinfo,local_410,local_210,0x100);
        Cmd_ForwardToServer();
        break;
      }
      Info_SetValueForKey(host_client->userinfo,local_410,local_210,0x100);
      host_client->sendinfo = true;
      cVar2 = *pcVar4;
    }
  }
  else {
    Con_Printf("fullinfo <complete info string>\n");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_GetHostInfo  @ 000b8ab0
void Host_GetHostInfo(float *fps,int *nActive,int *unused,int *nMaxPlayers,char *pszMap)

{
  float fVar1;
  int local_10 [2];
  
                    /* Unresolved local var: int clients@[???] */
  local_10[0] = 0;
  if ((float)rolling_fps <= 0.0) {
    rolling_fps = 0.0;
    fVar1 = 0.0;
  }
  else {
    fVar1 = 1.0 / (float)rolling_fps;
  }
  *fps = fVar1;
  SV_CountPlayers(local_10);
  *nActive = local_10[0];
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


// Host_GetMaxClients  @ 000b9520
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


// Host_GetStartTime  @ 000bc810
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long Host_GetStartTime(void)

{
  return startTime;
}


// Host_God_f  @ 000baf90
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


// Host_Init  @ 000b9840
int Host_Init(quakeparms_t_conflict *parms)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int in_GS_OFFSET;
  undefined1 local_190 [128];
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] versionString@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  uVar1 = 0;
  do {
    uVar2 = uVar1 + 4;
    *(undefined4 *)((int)&host_parms.basedir + uVar1) =
         *(undefined4 *)((int)&parms->basedir + uVar1);
    uVar1 = uVar2;
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
  __snprintf_chk(local_110,0x100,1,0x100,0x2583d3,gpszVersionString,0x30,iVar3);
  Cvar_Set("sv_version",local_110);
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
    pbVar4 = COM_LoadHunkFile("gfx/palette.lmp");
    if (pbVar4 == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Host_Init: Couldn\'t load gfx/palette.lmp");
    }
    host_basepal = Hunk_AllocName(0x800,"palette.lmp");
    iVar3 = 2;
    pbVar4 = pbVar4 + 2;
    do {
      *(short *)((int)host_basepal + iVar3 + -2) = (short)(char)*pbVar4;
      *(short *)((int)host_basepal + iVar3) = (short)(char)pbVar4[-1];
      *(short *)((int)host_basepal + iVar3 + 2) = (short)(char)pbVar4[-2];
      *(undefined2 *)((int)host_basepal + iVar3 + 4) = 0;
      iVar3 = iVar3 + 8;
      pbVar4 = pbVar4 + 3;
    } while (iVar3 != 0x802);
    GL_Init();
    PM_Init(&g_clmove);
    CL_InitEventSystem();
    ClientDLL_Init();
    VGui_Startup();
    iVar3 = VID_Init(host_basepal);
    if (iVar3 == 0) {
      VGui_Shutdown();
      iVar3 = 0;
      goto LAB_000b9c21;
    }
    Draw_Init();
    SCR_Init();
    R_Init();
    S_Init();
    CDAudio_Init();
    Voice_Init("voice_speex",1);
    DemoPlayer_Init();
    CL_Init();
  }
  Cbuf_InsertText("exec controller.cfg\n");
  Cbuf_InsertText("exec valve.rc\n");
  if (cls.state != ca_dedicated) {
    GL_Config();
  }
                    /* Unresolved local var: char[128] szSubKey@[???]
                       Unresolved local var: int nBufferLen@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: qboolean bGore@[???] */
  Hunk_AllocName(0,"-HOST_HUNKLEVEL-");
  host_hunklevel = Hunk_LowMark();
  giActive = 1;
  scr_skipupdate = false;
  Q_memset(local_190,0,0x80);
  if (bLowViolenceBuild == false) {
    Cvar_SetValue("violence_hblood",1.0);
    Cvar_SetValue("violence_hgibs",1.0);
    Cvar_SetValue("violence_ablood",1.0);
    Cvar_SetValue("violence_agibs",1.0);
  }
  else {
                    /* Unresolved local var: char[128] szSubKey@[???]
                       Unresolved local var: int nBufferLen@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: qboolean bGore@[???] */
    Cvar_SetValue("violence_hblood",0.0);
    Cvar_SetValue("violence_hgibs",0.0);
    Cvar_SetValue("violence_ablood",0.0);
    Cvar_SetValue("violence_agibs",0.0);
  }
  host_initialized = true;
  Steam_ProcessInsecureLaunchParameters();
  iVar3 = 1;
LAB_000b9c21:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// Host_InitCommands  @ 000c3280
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InitCommands(void)

{
  if (g_bIsDedicatedServer == false) {
    Cmd_AddCommandWithFlags("cd",CD_Command_f,0x10);
    Cmd_AddCommand("mp3",MP3_Command_f);
    Cmd_AddCommand("_careeraudio",CareerAudio_Command_f);
  }
  Cmd_AddCommand("shutdownserver",Host_KillServer_f);
  Cmd_AddCommand("soundfade",Host_Soundfade_f);
  Cmd_AddCommand("status",Host_Status_f);
  Cmd_AddCommand("stat",Host_Status_Formatted_f);
  Cmd_AddCommandWithFlags("quit",Host_Quit_f,8);
  if (g_bIsDedicatedServer == false) {
    Cmd_AddCommandWithFlags("_restart",Host_Quit_Restart_f,8);
    Cmd_AddCommandWithFlags("_setrenderer",Host_SetRenderer_f,8);
    Cmd_AddCommandWithFlags("_setvideomode",Host_SetVideoMode_f,8);
    Cmd_AddCommandWithFlags("_setgamedir",Host_SetGameDir_f,8);
    Cmd_AddCommandWithFlags("_sethdmodels",Host_SetHDModels_f,8);
    Cmd_AddCommandWithFlags("_setaddons_folder",Host_SetAddonsFolder_f,8);
  }
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
  Cmd_AddCommand("inputset_menu",Host_InputSet_Menu_f);
  Cmd_AddCommand("inputset_game",Host_InputSet_Game_f);
  Cmd_AddCommand("richpresence_override",Host_SetRichPresenceOverride_f);
  Cmd_AddCommand("richpresence_nicemap",Host_SetRichPresenceNiceMap_f);
  Cmd_AddCommand("richpresence_update",Host_SetRichPresenceUpdate_f);
  Cmd_AddCommand("richpresence_gamemode",Host_SetRichPresenceGameMode_f);
  Cmd_AddCommand("show_osk",Host_ShowOSK_f);
  Cmd_AddCommand("load",Host_Loadgame_f);
  Cmd_AddCommand("save",Host_Savegame_f);
  Cmd_AddCommand("autosave",Host_AutoSave_f);
  Cmd_AddCommandWithFlags("writecfg",Host_WriteCustomConfig,8);
  if (g_bIsDedicatedServer == false) {
    Cmd_AddCommand("+voicerecord",Host_VoiceRecordStart_f);
    Cmd_AddCommand("-voicerecord",Host_VoiceRecordStop_f);
  }
  Cmd_AddCommand("startdemos",Host_Startdemos_f);
  Cmd_AddCommand("demos",Host_Demos_f);
  Cmd_AddCommand("stopdemo",Host_Stopdemo_f);
  Cmd_AddCommandWithFlags("setinfo",Host_SetInfo_f,0x10);
  Cmd_AddCommand("fullinfo",Host_FullInfo_f);
  Cmd_AddCommand("god",Host_God_f);
  Cmd_AddCommand("notarget",Host_Notarget_f);
  Cmd_AddCommand("fly",Host_Fly_f);
  Cmd_AddCommand("noclip",Host_Noclip_f);
  if (g_bIsDedicatedServer == false) {
    Cmd_AddCommand("viewmodel",Host_Viewmodel_f);
    Cmd_AddCommand("viewframe",Host_Viewframe_f);
    Cmd_AddCommand("viewnext",Host_Viewnext_f);
    Cmd_AddCommand("viewprev",Host_Viewprev_f);
  }
  Cmd_AddCommand("mcache",Mod_Print);
  Cmd_AddCommand("interp",Host_Interp_f);
  Cmd_AddCommand("setmaster",Master_SetMaster_f);
  Cmd_AddCommand("heartbeat",Master_Heartbeat_f);
  Cvar_RegisterVariable(&gHostMap);
  Cvar_RegisterVariable(&voice_recordtofile);
  Cvar_RegisterVariable(&voice_inputfromfile);
  return;
}


// Host_InitLocal  @ 000b7180
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


// Host_InitializeGameDLL  @ 000bc690
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InitializeGameDLL(void)

{
  int iVar1;
  code *pcVar2;
  SV_SAVEGAMECOMMENT_FUNC p_Var3;
  int iVar4;
  vec_t (*pavVar5) [3];
  vec_t (*pavVar6) [3];
  
                    /* Unresolved local var: char[10] szInsecure@[???] */
  Cbuf_Execute();
  NET_Config((uint)(1 < svs.maxclients));
  if (svs.dll_initialized != false) {
    Con_DPrintf("Sys_InitializeGameDLL called twice, skipping second call\n");
    return;
  }
                    /* Unresolved local var: char[10] szInsecure@[???] */
  pavVar6 = player_mins;
  svs.dll_initialized = true;
  pavVar5 = player_maxs;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iResult@[???] */
  iVar4 = 0;
  LoadEntityDLLs(host_parms.basedir);
  (*gEntityInterface.pfnGameInit)();
  (*gEntityInterface.pfnPM_Init)((playermove_s *)&g_svmove);
  (*gEntityInterface.pfnRegisterEncoders)();
  SV_InitEncoders();
  do {
    iVar1 = (*gEntityInterface.pfnGetHullBounds)(iVar4,*pavVar6,*pavVar5);
    if (iVar1 == 0) break;
    iVar4 = iVar4 + 1;
    pavVar6 = pavVar6 + 1;
    pavVar5 = pavVar5 + 1;
  } while (iVar4 != 4);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SV_BLENDING_INTERFACE_FUNC studio_interface@[???] */
  R_ResetSvBlending();
  iVar4 = 0;
  p_Var3 = g_pSaveGameCommentFunc;
  if (0 < g_iextdllMac) {
    do {
      pcVar2 = (code *)dlsym(g_rgextdll[iVar4].lDLLHandle,&LAB_00258a8a);
      if (pcVar2 != (code *)0x0) {
        iVar1 = (*pcVar2)(1,&g_pSvBlendingAPI,&server_studio_api,rotationmatrix,bonetransform);
        if (iVar1 != 0) break;
        Con_DPrintf("Couldn\'t get server .dll studio model blending interface. Version mismatch?\n"
                   );
        R_ResetSvBlending();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < g_iextdllMac);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pszFunction@[???]
                       Unresolved local var: SV_SAVEGAMECOMMENT_FUNC pTemp@[???] */
    p_Var3 = g_pSaveGameCommentFunc;
    if (0 < g_iextdllMac) {
      iVar4 = 0;
      do {
        p_Var3 = (SV_SAVEGAMECOMMENT_FUNC)dlsym(g_rgextdll[iVar4].lDLLHandle,&LAB_00258aa6);
        if (p_Var3 != (SV_SAVEGAMECOMMENT_FUNC)0x0) break;
        iVar4 = iVar4 + 1;
        p_Var3 = g_pSaveGameCommentFunc;
      } while (iVar4 < g_iextdllMac);
    }
  }
  g_pSaveGameCommentFunc = p_Var3;
  Cbuf_Execute();
  return;
}


// Host_InputSet_Game_f  @ 000b9f50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InputSet_Game_f(void)

{
  Steam_ActivateInputSet(false);
  return;
}


// Host_InputSet_Menu_f  @ 000b9f30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_InputSet_Menu_f(void)

{
  Steam_ActivateInputSet(true);
  return;
}


// Host_Interp_f  @ 000b9ef0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Interp_f(void)

{
  bool bVar1;
  
  bVar1 = r_dointerp == 0;
  r_dointerp = (int)bVar1;
  if (bVar1) {
    Con_Printf("Frame Interpolation ON\n");
    return;
  }
  Con_Printf("Frame Interpolation OFF\n");
  return;
}


// Host_IsServerActive  @ 000b9540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Host_IsServerActive(void)

{
  return sv.active;
}


// Host_IsSinglePlayerGame  @ 000b9500
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


// Host_Kick_f  @ 000fff40
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
  int iVar9;
  int iVar10;
  uint uVar11;
  int in_GS_OFFSET;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  char local_60 [63];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char * who@[???]
                       Unresolved local var: char * message@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean byNumber@[???]
                       Unresolved local var: char[64] idstring@[???]
                       Unresolved local var: qboolean isSteam@[???]
                       Unresolved local var: int argsStartNum@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = Cmd_Argc();
  pcVar2 = host_client;
  if (iVar3 < 2) {
    Con_Printf("usage:  kick < name > | < # userid >\n");
    pcVar2 = host_client;
  }
  else {
    if (cmd_source == src_command) {
      if (sv.active == false) {
        Cmd_ForwardToServer();
        pcVar2 = host_client;
        goto LAB_000fff83;
      }
    }
    else if ((host_client->netchan).remote_address.type != NA_LOOPBACK) {
      SV_ClientPrintf("You can\'t \'kick\' because you are not a server operator\n");
      pcVar2 = host_client;
      goto LAB_000fff83;
    }
    pcVar4 = Cmd_Argv(1);
    if ((pcVar4 == (char *)0x0) || (*pcVar4 != '#')) {
      if (0 < svs.maxclients) {
        iVar10 = 0;
        host_client = svs.clients;
        iVar3 = svs.maxclients;
        do {
          if ((host_client->active != false) || (host_client->connected != false)) {
            pcVar4 = Cmd_Argv(1);
            iVar5 = Q_strcasecmp(host_client->name,pcVar4);
            iVar3 = svs.maxclients;
            if (iVar5 == 0) {
              local_7c = 2;
              bVar1 = false;
              goto LAB_00100065;
            }
          }
          iVar10 = iVar10 + 1;
          host_client = host_client + 1;
        } while (iVar10 < iVar3);
      }
    }
    else {
                    /* Unresolved local var: int searchid@[???] */
      iVar3 = Cmd_Argc();
      if ((iVar3 < 3) || (pcVar4[1] != '\0')) {
        pcVar4 = pcVar4 + 1;
        iVar5 = Q_atoi(pcVar4);
        local_7c = 6;
        local_74 = 3;
        local_78 = 5;
        local_70 = 2;
      }
      else {
        pcVar4 = Cmd_Argv(2);
        iVar5 = Q_atoi(pcVar4);
        pcVar4 = Cmd_Argv(2);
        local_7c = 7;
        local_74 = 4;
        local_78 = 6;
        local_70 = 3;
      }
      strncpy(local_60,pcVar4,0x3f);
      local_21 = 0;
      iVar3 = Q_strnicmp(local_60,"STEAM_",6);
      if ((iVar3 == 0) || (iVar3 = Q_strnicmp(local_60,"VALVE_",6), iVar3 == 0)) {
        pcVar6 = Cmd_Argv(local_78);
        pcVar7 = Cmd_Argv(local_74);
        __snprintf_chk(local_60,0x3f,1,0x40,0x25e19d,pcVar4,pcVar7,pcVar6);
        local_21 = 0;
        bVar1 = true;
      }
      else {
        bVar1 = false;
        local_7c = local_70;
      }
      if (0 < svs.maxclients) {
        iVar10 = 0;
        host_client = svs.clients;
        iVar3 = svs.maxclients;
        if (iVar5 == 0) {
          do {
            if ((host_client->active != false) || (host_client->connected != false)) {
              SV_GetClientIDString::idstr._0_4_ = SV_GetClientIDString::idstr._0_4_ & 0xffffff00;
              if (host_client != (client_t *)0x0) {
                if (((host_client->netchan).remote_address.type == NA_LOOPBACK) &&
                   ((host_client->network_userid).idtype == 2)) {
                  builtin_strncpy(SV_GetClientIDString::idstr,"VALVE_ID_LOOPBACK",0x12);
                }
                else {
                  pcVar4 = SV_GetIDString(&host_client->network_userid);
                  snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar4);
                }
              }
              iVar5 = Q_stricmp(SV_GetClientIDString::idstr,local_60);
              iVar3 = svs.maxclients;
              if (iVar5 == 0) goto LAB_00100065;
            }
            iVar10 = iVar10 + 1;
            host_client = host_client + 1;
          } while (iVar10 < iVar3);
        }
        else {
          do {
            if ((host_client->active != false) || (host_client->connected != false)) {
              if (iVar5 == host_client->userid) goto LAB_00100065;
              SV_GetClientIDString::idstr._0_4_ = SV_GetClientIDString::idstr._0_4_ & 0xffffff00;
              if (host_client != (client_t *)0x0) {
                if (((host_client->netchan).remote_address.type == NA_LOOPBACK) &&
                   ((host_client->network_userid).idtype == 2)) {
                  builtin_strncpy(SV_GetClientIDString::idstr,"VALVE_ID_LOOPBACK",0x12);
                }
                else {
                    /* Unresolved local var: USERID_t * id@[???] */
                  pcVar4 = SV_GetIDString(&host_client->network_userid);
                  snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar4);
                }
              }
              iVar9 = Q_stricmp(SV_GetClientIDString::idstr,local_60);
              iVar3 = svs.maxclients;
              if (iVar9 == 0) goto LAB_00100065;
            }
            iVar10 = iVar10 + 1;
            host_client = host_client + 1;
          } while (iVar10 < iVar3);
        }
      }
    }
  }
  goto LAB_000fff83;
LAB_00100065:
  if (iVar10 < iVar3) {
    pcVar4 = pcVar2->name;
    if ((cmd_source == src_command) && (pcVar4 = "Console", cls.state != ca_dedicated)) {
      pcVar4 = cl_name.string;
    }
    if ((host_client->netchan).remote_address.type == NA_LOOPBACK) {
      Con_Printf("The local player cannot be kicked!\n");
      pcVar2 = host_client;
    }
    else {
      iVar3 = Cmd_Argc();
      if (local_7c < iVar3) {
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
        } while (local_7c != iVar10);
        if (bVar1) {
          uVar11 = uVar11 - 4;
        }
        sVar8 = strlen(pcVar6);
        if ((uVar11 <= sVar8) && (pcVar6 = pcVar6 + uVar11, pcVar6 != (char *)0x0)) {
          SV_ClientPrintf("Kicked by %s: %s\n",pcVar4,pcVar6);
          SV_GetClientIDString::idstr._0_4_ = SV_GetClientIDString::idstr._0_4_ & 0xffffff00;
          if (host_client != (client_t *)0x0) {
            if (((host_client->netchan).remote_address.type == NA_LOOPBACK) &&
               ((host_client->network_userid).idtype == 2)) {
              builtin_strncpy(SV_GetClientIDString::idstr,"VALVE_ID_LOOPBACK",0x12);
            }
            else {
                    /* Unresolved local var: USERID_t * id@[???] */
              pcVar7 = SV_GetIDString(&host_client->network_userid);
              snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar7);
            }
          }
          Log_Printf("Kick: \"%s<%i><%s><>\" was kicked by \"%s\" (message \"%s\")\n",
                     host_client->name,host_client->userid,SV_GetClientIDString::idstr,pcVar4,pcVar6
                    );
          pcVar4 = va("Kicked :%s",pcVar6);
          SV_DropClient(host_client,false,pcVar4);
          goto LAB_000fff83;
        }
      }
      SV_ClientPrintf("Kicked by %s\n",pcVar4);
      pcVar6 = SV_GetClientIDString(host_client);
      Log_Printf("Kick: \"%s<%i><%s><>\" was kicked by \"%s\"\n",host_client->name,
                 host_client->userid,pcVar6,pcVar4);
      SV_DropClient(host_client,false,"Kicked");
    }
  }
LAB_000fff83:
  host_client = pcVar2;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_KillServer_f  @ 000baa40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_KillServer_f(void)

{
  if (cls.state != ca_dedicated) {
    CL_Disconnect_f();
    return;
  }
  if (sv.active == false) {
    return;
  }
  Host_ShutdownServer(false);
  if (cls.state != ca_dedicated) {
    NET_Config(false);
  }
  return;
}


// Host_KillVoice_f  @ 000c2df0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_KillVoice_f(void)

{
  if (g_bVoiceAtLeastPartiallyInitted) {
    Voice_Deinit();
    return;
  }
  return;
}


// Host_Kill_f  @ 000ba210
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Kill_f(void)

{
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if ((sv_player->v).health <= 0.0) {
    SV_ClientPrintf("Can\'t suicide -- already dead!\n");
  }
  else {
    if (((host_client->active != false) && (host_client->connected != false)) &&
       (host_client->spawned != false)) {
      gGlobalVariables.time = (float)sv.time;
      (*gEntityInterface.pfnClientKill)(sv_player);
      return;
    }
    SV_ClientPrintf("Can\'t kill yourself -- you\'re not connected!\n");
  }
  return;
}


// Host_Load  @ 000c2670
int __regparm3 Host_Load(char *pName)

{
  GAME_HEADER *pHeader;
  char cVar1;
  char cVar2;
  ushort *puVar3;
  char *s1;
  int iVar4;
  FileHandle_t file;
  ushort **ppuVar5;
  int in_GS_OFFSET;
  undefined1 *puVar6;
  int local_1a0;
  char local_199 [5];
  GAME_HEADER local_194;
  char local_120 [251];
  undefined1 local_25;
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
                       Unresolved local var: char[5] szNumber@[???]
                       Unresolved local var: int nSlot@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*pName == '_') {
    cVar1 = pName[1];
    if (cVar1 == '\0') {
LAB_000c2ab8:
      iVar4 = 0;
    }
    else {
      ppuVar5 = __ctype_b_loc();
      puVar3 = *ppuVar5;
      if ((*(byte *)((int)puVar3 + cVar1 * 2 + 1) & 8) == 0) goto LAB_000c2ab8;
      cVar2 = pName[2];
      local_199[0] = cVar1;
      if ((cVar2 == '\0') || ((*(byte *)((int)puVar3 + cVar2 * 2 + 1) & 8) == 0)) {
        iVar4 = 1;
      }
      else {
        cVar1 = pName[3];
        local_199[1] = cVar2;
        if ((cVar1 == '\0') || ((*(byte *)((int)puVar3 + cVar1 * 2 + 1) & 8) == 0)) {
          iVar4 = 2;
        }
        else {
          cVar2 = pName[4];
          local_199[2] = cVar1;
          if ((cVar2 == '\0') || ((*(byte *)((int)puVar3 + cVar2 * 2 + 1) & 8) == 0)) {
            iVar4 = 3;
          }
          else {
            cVar1 = pName[5];
            local_199[3] = cVar2;
            if ((cVar1 == '\0') || ((*(byte *)((int)puVar3 + cVar1 * 2 + 1) & 8) == 0)) {
              iVar4 = 4;
            }
            else {
              iVar4 = 5;
              local_199[4] = cVar1;
            }
          }
        }
      }
    }
    local_199[iVar4] = '\0';
    pName = (char *)Q_atoi(local_199);
    if (pName + -1 < &DAT_0000000c) {
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      puVar6 = &LAB_00258ded;
      goto LAB_000c26da;
    }
  }
  else {
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    puVar6 = &LAB_0026291c;
LAB_000c26da:
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    __snprintf_chk(local_120,0xfc,1,0x100,puVar6,Host_SaveGameDirectory::szDirectory,pName);
    local_25 = 0;
    if (svs.dll_initialized == false) {
      Host_InitializeGameDLL();
    }
    COM_DefaultExtension(local_120,".sav");
    s1 = COM_LastFileExtension(local_120);
    if ((s1 != (char *)0x0) && (iVar4 = Q_stricmp(s1,"sav"), iVar4 == 0)) {
      COM_FixSlashes(local_120);
      local_21 = 0;
      Con_Printf("Loading game from %s...\n",local_120);
      file = FS_OpenPathID(local_120,"rb","GAMECONFIG");
      if (file != (FileHandle_t)0x0) {
        S_StopAllSounds(true);
        Host_ClearSaveDirectory();
        if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
          (*gEntityInterface.pfnResetGlobalState)();
        }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
        FS_Read(&local_1a0,4,1,file);
        if ((local_1a0 == 0x5641534a) && (FS_Read(&local_1a0,4,1,file), local_1a0 == 0x71)) {
          pHeader = (GAME_HEADER *)(local_199 + 5);
          iVar4 = SaveReadHeader(file,pHeader,1);
          if (iVar4 != 0) {
            cls.demonum = -1;
            SV_InactivateClients();
            SCR_BeginLoadingPlaque(false);
            DirectoryExtract(file,local_194.mapCount);
            FS_Close(file);
            Cvar_SetValue("deathmatch",0.0);
            Cvar_SetValue("coop",0.0);
            iVar4 = Q_stricmp(com_gamedir,"valve");
            if (((iVar4 == 0) || (iVar4 = Q_stricmp(com_gamedir,"bshift"), iVar4 == 0)) ||
               (iVar4 = Q_stricmp(com_gamedir,"gearbox"), iVar4 == 0)) {
              svs.maxclients = 1;
              Cvar_SetValue("maxplayers",1.0);
            }
            iVar4 = 1;
            __snprintf_chk(local_120,0x100,1,0x100,0x255b43,pHeader);
            CL_Disconnect();
            Host_Map(false,local_120,(char *)pHeader,true);
            goto LAB_000c2750;
          }
        }
        else {
          FS_Close(file);
        }
        giStateInfo = 1;
        Cbuf_AddText("\ndisconnect\n");
        iVar4 = 0;
        goto LAB_000c2750;
      }
    }
  }
  iVar4 = 0;
LAB_000c2750:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}


// Host_Load  @ 000c2b30
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


// Host_Loadgame_f  @ 000c2d30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Loadgame_f(void)

{
  int iVar1;
  char *s1;
  char *pcVar2;
  
  if (cmd_source != src_command) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    s1 = Cmd_Argv(1);
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
                       Unresolved local var: char[5] szNumber@[???]
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
  else {
    Con_Printf("load <savename> : load a game\n");
  }
  return;
}


// Host_Map  @ 000c1eb0
void Host_Map(qboolean bIsDemo,char *mapstring,char *mapName,qboolean loadGame)

{
  _UserMsg *p_Var1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  UserMsg *pUVar7;
  char *pcVar8;
  int arg;
  
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
    Q_strncpy(cls.mapstring,mapstring,0x3f);
    cls.mapstring[0x3f] = '\0';
    iVar3 = SV_SpawnServer(bIsDemo,mapName,(char *)0x0);
    if (iVar3 == 0) {
      return;
    }
    ContinueLoadingProgressBar("Server",7,0.0);
    SV_LoadEntities();
    SV_ActivateServer(1);
    if (sv.active == false) {
      return;
    }
    if (cls.state != ca_dedicated) {
                    /* Unresolved local var: int i@[???] */
      arg = 2;
      Q_strcpy(cls.spawnparms,"");
      iVar3 = Cmd_Argc();
      if (2 < iVar3) {
        do {
          pcVar8 = cls.spawnparms;
          do {
            pcVar6 = pcVar8;
            uVar4 = *(uint *)pcVar6 + 0xfefefeff & ~*(uint *)pcVar6;
            uVar5 = uVar4 & 0x80808080;
            pcVar8 = pcVar6 + 4;
          } while (uVar5 == 0);
          bVar2 = (byte)uVar5;
          if ((uVar4 & 0x8080) == 0) {
            bVar2 = (byte)(uVar5 >> 0x10);
            pcVar8 = pcVar6 + 6;
          }
          pcVar6 = Cmd_Argv(arg);
          __strncat_chk(0xdf8900,pcVar6,
                        0x7ff - (int)(pcVar8 + (-0xdf8903 - (uint)CARRY1(bVar2,bVar2))),0x800);
          pcVar8 = cls.spawnparms;
          do {
            pcVar6 = pcVar8;
            uVar5 = *(uint *)pcVar6 + 0xfefefeff & ~*(uint *)pcVar6;
            uVar4 = uVar5 & 0x80808080;
            pcVar8 = pcVar6 + 4;
          } while (uVar4 == 0);
          if ((uVar5 & 0x8080) == 0) {
            pcVar8 = pcVar6 + 6;
            uVar4 = uVar4 >> 0x10;
          }
          arg = arg + 1;
          __strncat_chk(0xdf8900,&DAT_0027beaa,
                        0x7ff - (int)(pcVar8 + (-0xdf8903 - (uint)CARRY1((byte)uVar4,(byte)uVar4))),
                        0x800);
          iVar3 = Cmd_Argc();
        } while (arg < iVar3);
      }
      goto LAB_000c20a4;
    }
    if (sv_gpNewUserMsgs == (UserMsg *)0x0) goto LAB_000c2030;
LAB_000c1ffa:
    p_Var1 = sv_gpUserMsgs;
    pUVar7 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != (UserMsg *)0x0) {
      do {
        pUVar7 = p_Var1;
        p_Var1 = pUVar7->next;
      } while (p_Var1 != (_UserMsg *)0x0);
      pUVar7->next = sv_gpNewUserMsgs;
      pUVar7 = sv_gpUserMsgs;
    }
    sv_gpUserMsgs = pUVar7;
    sv_gpNewUserMsgs = (UserMsg *)0x0;
  }
  else {
    Q_strncpy(cls.mapstring,mapstring,0x3f);
    cls.mapstring[0x3f] = '\0';
    iVar3 = SV_SpawnServer(bIsDemo,mapName,(char *)0x0);
    if (iVar3 == 0) {
      return;
    }
    ContinueLoadingProgressBar("Server",7,0.0);
    iVar3 = LoadGamestate(mapName,1);
    if (iVar3 == 0) {
      SV_LoadEntities();
    }
    sv.paused = true;
    sv.loadgame = true;
    SV_ActivateServer(0);
LAB_000c20a4:
    if (sv_gpNewUserMsgs != (UserMsg *)0x0) goto LAB_000c1ffa;
  }
  if (cls.state != ca_dedicated) {
    Cmd_ExecuteString("connect local",src_command);
  }
LAB_000c2030:
  Steam_UpdateRichPresence();
  return;
}


// Host_Map_f  @ 000c2200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Map_f(void)

{
  CareerStateType CVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int in_GS_OFFSET;
  uint local_a0 [15];
  undefined1 auStack_64 [4];
  char local_60 [63];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[64] mapstring@[???]
                       Unresolved local var: char[64] name@[???]
                       Unresolved local var: CareerStateType careerState@[???] */
  CVar1 = g_careerState;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    iVar3 = Cmd_Argc();
    if (1 < iVar3) {
      pcVar4 = Cmd_Args();
      iVar3 = Q_strlen(pcVar4);
      if (0x36 < iVar3) {
        Con_Printf("map change failed: command string is too long.\n");
        goto LAB_000c223a;
      }
    }
    iVar3 = Cmd_Argc();
    if (iVar3 < 2) {
      Con_Printf("map <levelname> : changes server to specified map\n");
      g_careerState = CAREER_NONE;
    }
    else {
      CL_Disconnect();
      if (CVar1 == CAREER_LOADING) {
        g_careerState = CAREER_LOADING;
      }
      iVar3 = COM_CheckParm("-steam");
      if ((iVar3 != 0) && (iVar3 = PF_IsDedicatedServer(), iVar3 != 0)) {
        g_bMajorMapChange = true;
      }
      iVar9 = 0;
      FS_LogLevelLoadStarted("Map_Common");
      local_a0[0]._0_1_ = 0;
      iVar3 = Cmd_Argc();
      puVar8 = local_a0;
      if (0 < iVar3) {
        do {
          do {
            puVar7 = puVar8;
            uVar5 = *puVar7 + 0xfefefeff & ~*puVar7;
            uVar6 = uVar5 & 0x80808080;
            puVar8 = puVar7 + 1;
          } while (uVar6 == 0);
          bVar2 = (byte)uVar6;
          if ((uVar5 & 0x8080) == 0) {
            bVar2 = (byte)(uVar6 >> 0x10);
            puVar8 = (uint *)((int)puVar7 + 6);
          }
          pcVar4 = Cmd_Argv(iVar9);
          __strncat_chk(local_a0,pcVar4,
                        0x3e - (int)((int)puVar8 +
                                    ((-3 - (uint)CARRY1(bVar2,bVar2)) - (int)local_a0)),0x40);
          puVar8 = local_a0;
          do {
            puVar7 = puVar8;
            uVar6 = *puVar7 + 0xfefefeff & ~*puVar7;
            uVar5 = uVar6 & 0x80808080;
            puVar8 = puVar7 + 1;
          } while (uVar5 == 0);
          if ((uVar6 & 0x8080) == 0) {
            puVar8 = (uint *)((int)puVar7 + 6);
            uVar5 = uVar5 >> 0x10;
          }
          iVar9 = iVar9 + 1;
          __strncat_chk(local_a0,&DAT_0027beaa,
                        0x3e - (int)((int)puVar8 +
                                    ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)local_a0)),
                        0x40);
          iVar3 = Cmd_Argc();
          puVar8 = local_a0;
        } while (iVar9 < iVar3);
      }
      Q_strcat((char *)local_a0,"\n");
      pcVar4 = Cmd_Argv(1);
      Q_strncpy(local_60,pcVar4,0x3f);
      local_21 = 0;
      if (svs.dll_initialized == false) {
        Host_InitializeGameDLL();
      }
      iVar3 = Q_strlen(local_60);
      if ((4 < iVar3) && (iVar9 = Q_strcasecmp(auStack_64 + iVar3,&LAB_0025dfc1_2), iVar9 == 0)) {
        auStack_64[iVar3] = 0;
      }
      FS_LogLevelLoadStarted(local_60);
      VGuiWrap2_LoadingStarted("level",local_60);
      SCR_UpdateScreen();
      SCR_UpdateScreen();
      iVar3 = PF_IsMapValid_I(local_60);
      if (iVar3 == 0) {
        Con_Printf("map change failed: \'%s\' not found on server.\n",local_60);
        iVar3 = COM_CheckParm("-steam");
        if ((iVar3 != 0) && (iVar3 = PF_IsDedicatedServer(), iVar3 != 0)) {
          g_bMajorMapChange = false;
          Sys_Printf("\n");
        }
      }
      else {
        StartLoadingProgressBar("Server",0x18);
        SetLoadingProgressBarStatusText("#GameUI_StartingServer");
        ContinueLoadingProgressBar("Server",1,0.0);
        Cvar_Set("HostMap",local_60);
        Host_Map(false,(char *)local_a0,local_60,false);
        iVar3 = COM_CheckParm("-steam");
        if ((iVar3 != 0) && (iVar3 = PF_IsDedicatedServer(), iVar3 != 0)) {
          g_bMajorMapChange = false;
          Sys_Printf("\n");
        }
        ContinueLoadingProgressBar("Server",0xb,0.0);
        NotifyDedicatedServerUI("UpdateMap");
        if (g_careerState == CAREER_LOADING) {
          g_careerState = CAREER_PLAYING;
          SetCareerAudioState(1);
        }
        else {
          SetCareerAudioState(0);
        }
      }
    }
  }
  else {
LAB_000c223a:
    g_careerState = CAREER_NONE;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Maps_f  @ 000bb100
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


// Host_Motd_Write_f  @ 000bac40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Motd_Write_f(void)

{
  byte bVar1;
  char *pcVar2;
  qboolean qVar3;
  int iVar4;
  FileHandle_t file;
  uint uVar5;
  uint uVar6;
  char *size;
  uint *puVar7;
  uint *puVar8;
  int in_GS_OFFSET;
  undefined4 local_820;
  int local_20;
  
                    /* Unresolved local var: char * pchExtension@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar2 = COM_LastFileExtension(motdfile.string);
  qVar3 = IsSafeFileToDownload(motdfile.string);
  if ((qVar3 == false) || (iVar4 = Q_stricmp(pcVar2,"txt"), iVar4 != 0)) {
    Con_Printf("Invalid motdfile name (%s)\n",motdfile.string);
  }
  else {
                    /* Unresolved local var: char[2048] newFile@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: FileHandle_t pFile@[???] */
    file = FS_Open(motdfile.string,"wb+");
    if (file == (FileHandle_t)0x0) {
      Con_Printf("Unable to open %s\n",motdfile.string);
    }
    else {
      pcVar2 = Cmd_Args();
      Q_strncpy((char *)&local_820,pcVar2,0x800);
      puVar8 = &local_820;
      do {
        puVar7 = puVar8;
        uVar5 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar6 = uVar5 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar6 == 0);
      bVar1 = (byte)uVar6;
      if ((uVar5 & 0x8080) == 0) {
        bVar1 = (byte)(uVar6 >> 0x10);
        puVar8 = (uint *)((int)puVar7 + 6);
      }
      size = (char *)((int)puVar8 + ((-3 - (uint)CARRY1(bVar1,bVar1)) - (int)&local_820));
      pcVar2 = (char *)((int)&local_820 + 1);
      for (iVar4 = 1; (char *)(iVar4 - 1U) < size; iVar4 = iVar4 + 1) {
        if ((pcVar2[-1] == '\\') && (*pcVar2 == 'n')) {
          pcVar2[-1] = '\n';
          strcpy(pcVar2,pcVar2 + 1);
          puVar8 = &local_820;
          do {
            puVar7 = puVar8;
            uVar6 = *puVar7 + 0xfefefeff & ~*puVar7;
            uVar5 = uVar6 & 0x80808080;
            puVar8 = puVar7 + 1;
          } while (uVar5 == 0);
          if ((uVar6 & 0x8080) == 0) {
            puVar8 = (uint *)((int)puVar7 + 6);
            uVar5 = uVar5 >> 0x10;
          }
          size = (char *)((int)puVar8 +
                         ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)&local_820));
        }
        pcVar2 = pcVar2 + 1;
      }
      FS_Write(&local_820,(int)size,1,file);
      FS_Close(file);
      Con_Printf("Done.\n");
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Motd_Write_f  @ 000bae00
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
    return;
  }
  return;
}


// Host_Motd_f  @ 000baa90
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
          if (__s != (char *)0x0) {
            Con_Printf("%s\n",__s);
          }
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


// Host_NextDemo  @ 000bb8d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_NextDemo(void)

{
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: char[1024] str@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __snprintf_chk(local_410,0x400,1,0x400,0x2589ef,cls.demonum * 0x10 + 0xdf920c);
  Cbuf_InsertText(local_410);
  cls.demonum = cls.demonum + 1;
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_NextDemo  @ 000c3120
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_NextDemo(void)

{
                    /* Unresolved local var: char[1024] str@[???] */
  if (cls.demonum != -1) {
    SCR_BeginLoadingPlaque(false);
    if (((cls.demos[cls.demonum][0] != '\0') && (cls.demonum != 0x20)) ||
       (cls.demonum = 0, cls.demos[0][0] != '\0')) {
      Host_NextDemo();
      return;
    }
    Con_Printf("No demos listed with startdemos\n");
    cls.demonum = -1;
  }
  return;
}


// Host_Noclip_f  @ 000bda10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Noclip_f(void)

{
  vec_t *pvVar1;
  vec_t vVar2;
  vec_t vVar3;
  edict_t *peVar4;
  edict_t *peVar5;
  edict_t *peVar6;
  int iVar7;
  vec_t local_40 [3];
  vec_t local_34 [3];
  vec_t local_28 [6];
  
  peVar5 = sv_player;
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
  }
  else if ((gGlobalVariables.deathmatch == 0.0) && (sv_cheats.value != 0.0)) {
    if ((sv_player->v).movetype == 8) {
      vVar2 = (sv_player->v).origin[1];
      vVar3 = (sv_player->v).origin[2];
      (sv_player->v).oldorigin[0] = (sv_player->v).origin[0];
      (peVar5->v).oldorigin[1] = vVar2;
      (peVar5->v).oldorigin[2] = vVar3;
      (peVar5->v).movetype = 3;
      noclip_anglehack = false;
      SV_ClientPrintf("noclip OFF\n");
      peVar5 = SV_TestEntityPosition(sv_player);
      if (peVar5 != (edict_t *)0x0) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
        iVar7 = 100;
        AngleVectors((sv_player->v).v_angle,local_40,local_34,local_28);
        peVar5 = sv_player;
        pvVar1 = (sv_player->v).origin;
        do {
          VectorMA(pvVar1,1.0,local_40,pvVar1);
          peVar6 = SV_TestEntityPosition(peVar5);
          peVar4 = sv_player;
          if (peVar6 == (edict_t *)0x0) {
            vVar2 = (peVar5->v).origin[1];
            (peVar5->v).oldorigin[0] = (peVar5->v).origin[0];
            vVar3 = (peVar5->v).origin[2];
            (peVar5->v).oldorigin[1] = vVar2;
            (peVar5->v).oldorigin[2] = vVar3;
            goto LAB_000bdb9b;
          }
                    /* Unresolved local var: int i@[???] */
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 100;
        pvVar1 = (sv_player->v).origin;
        do {
          VectorMA(pvVar1,1.0,local_34,pvVar1);
          peVar6 = SV_TestEntityPosition(peVar4);
          peVar5 = sv_player;
          if (peVar6 == (edict_t *)0x0) {
            vVar2 = (peVar4->v).origin[1];
            vVar3 = (peVar4->v).origin[2];
            (peVar4->v).oldorigin[0] = (peVar4->v).origin[0];
            (peVar4->v).oldorigin[1] = vVar2;
            (peVar4->v).oldorigin[2] = vVar3;
            goto LAB_000bdb9b;
          }
                    /* Unresolved local var: int i@[???] */
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 100;
        pvVar1 = (sv_player->v).origin;
        do {
          VectorMA(pvVar1,-1.0,local_34,pvVar1);
          peVar6 = SV_TestEntityPosition(peVar5);
          peVar4 = sv_player;
          if (peVar6 == (edict_t *)0x0) {
            vVar2 = (peVar5->v).origin[1];
            (peVar5->v).oldorigin[0] = (peVar5->v).origin[0];
            vVar3 = (peVar5->v).origin[2];
            (peVar5->v).oldorigin[1] = vVar2;
            (peVar5->v).oldorigin[2] = vVar3;
            goto LAB_000bdb9b;
          }
                    /* Unresolved local var: int i@[???] */
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 100;
        pvVar1 = (sv_player->v).origin;
        do {
          VectorMA(pvVar1,1.0,local_28,pvVar1);
          peVar5 = SV_TestEntityPosition(peVar4);
          if (peVar5 == (edict_t *)0x0) {
            vVar2 = (peVar4->v).origin[1];
            (peVar4->v).oldorigin[0] = (peVar4->v).origin[0];
            vVar3 = (peVar4->v).origin[2];
            (peVar4->v).oldorigin[1] = vVar2;
            (peVar4->v).oldorigin[2] = vVar3;
            goto LAB_000bdb9b;
          }
                    /* Unresolved local var: int i@[???] */
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = FindPassableSpace(sv_player,local_28,-1.0);
        if ((iVar7 == 0) && (iVar7 = FindPassableSpace(sv_player,local_40,-1.0), iVar7 == 0)) {
          Con_DPrintf("Can\'t find the world\n");
        }
LAB_000bdb9b:
        peVar5 = sv_player;
        vVar2 = (sv_player->v).oldorigin[1];
        vVar3 = (sv_player->v).oldorigin[2];
        (sv_player->v).origin[0] = (sv_player->v).oldorigin[0];
        (peVar5->v).origin[1] = vVar2;
        (peVar5->v).origin[2] = vVar3;
      }
    }
    else {
      (sv_player->v).movetype = 8;
      noclip_anglehack = true;
      SV_ClientPrintf("noclip ON\n");
    }
  }
  return;
}


// Host_Notarget_f  @ 000bb010
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Notarget_f(void)

{
  uint uVar1;
  
  if (cmd_source != src_command) {
    if (gGlobalVariables.deathmatch == 0.0) {
      uVar1 = (sv_player->v).flags ^ 0x80;
      (sv_player->v).flags = uVar1;
      if ((uVar1 & 0x80) == 0) {
        SV_ClientPrintf("notarget OFF\n");
      }
      else {
        SV_ClientPrintf("notarget ON\n");
      }
    }
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// Host_Pause_f  @ 000bb540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Pause_f(void)

{
  if (cl.levelname[0] != '\0') {
    if (cmd_source == src_command) {
      Cmd_ForwardToServer();
      return;
    }
    if (pausable.value != 0.0) {
      Steam_UpdateRichPresence();
      sv.paused = true;
      MSG_WriteByte(&sv.reliable_datagram,0x18);
      MSG_WriteByte(&sv.reliable_datagram,sv.paused);
      Steam_UpdateRichPresence();
      return;
    }
  }
  return;
}


// Host_Ping_f  @ 000ba400
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
  iVar3 = 0;
  SV_ClientPrintf("Client ping times:\n");
  iVar2 = svs.maxclients;
  cl = svs.clients;
  if (0 < svs.maxclients) {
    do {
      while (cl->active == false) {
        iVar3 = iVar3 + 1;
        cl = cl + 1;
        if (iVar2 <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = SV_CalcPing(cl);
      pcVar1 = cl->name;
      cl = cl + 1;
      SV_ClientPrintf("%4i %s\n",iVar2,pcVar1);
      iVar2 = svs.maxclients;
    } while (iVar3 < svs.maxclients);
  }
  return;
}


// Host_Quit_Restart_f  @ 000ba0b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Quit_Restart_f(void)

{
  char *pcVar1;
  qboolean qVar2;
  size_t sVar3;
  
  pcVar1 = g_pPostRestartCmdLineArgs;
  giActive = 5;
  giStateInfo = 4;
  if (sv.active == false) {
    if (((cls.state != ca_active) || (cls.trueaddress[0] == '\0')) ||
       (g_pPostRestartCmdLineArgs == (char *)0x0)) goto LAB_000ba0de;
    sVar3 = strlen(g_pPostRestartCmdLineArgs);
    builtin_strncpy(pcVar1 + sVar3," +connect ",0xb);
    strcat(g_pPostRestartCmdLineArgs,cls.servername);
    if (sv.active == false) goto LAB_000ba0de;
  }
  if (((svs.maxclients == 1) && (cls.state == ca_active)) &&
     (g_pPostRestartCmdLineArgs != (char *)0x0)) {
    Cbuf_AddText("save quick\n");
    Cbuf_Execute();
    pcVar1 = g_pPostRestartCmdLineArgs;
    sVar3 = strlen(g_pPostRestartCmdLineArgs);
    builtin_strncpy(pcVar1 + sVar3," +load quick",0xd);
  }
LAB_000ba0de:
  qVar2 = Host_IsServerActive();
  if (qVar2 == false) {
    if (cls.state != ca_dedicated) {
      CL_Disconnect();
    }
  }
  else {
    Host_ShutdownServer(false);
  }
  NET_Config(false);
  Cache_Force_Flush();
  return;
}


// Host_Quit_f  @ 000baf10
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
  g_iQuitCommandIssued = 1;
  giActive = 3;
  if (cls.state != ca_dedicated) {
    CL_Disconnect();
  }
  Host_ShutdownServer(false);
  NET_Config(false);
  Sys_Quit();
  return;
}


// Host_Reconnect_f  @ 000bb2d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Reconnect_f(void)

{
  netadr_t a;
  char *src;
  int iVar1;
  int in_GS_OFFSET;
  char local_110 [128];
  char local_90 [128];
  int local_10;
  
                    /* Unresolved local var: char[128] cmdString@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (ca_connecting < cls.state) {
    if (cls.passive == false) {
                    /* Unresolved local var: char[128] cmdString@[???] */
      SCR_BeginLoadingPlaque(true);
      cls.signon = 0;
      cls.state = ca_connected;
      sys_timescale.value = 1.0;
      Netchan_Clear(&cls.netchan);
      SZ_Clear(&cls.netchan.message);
      MSG_WriteChar(0xdf3c9c,3);
      MSG_WriteString(&cls.netchan.message,"new");
    }
    else {
                    /* Unresolved local var: char[128] buf@[???] */
      a.ip = cls.connect_stream.ip;
      a.type = cls.connect_stream.type;
      a.ipx._0_4_ = cls.connect_stream.ipx._0_4_;
      a.ipx._4_4_ = cls.connect_stream.ipx._4_4_;
      a._16_4_ = cls.connect_stream._16_4_;
      src = NET_AdrToString(a);
      Q_strncpy_s(local_90,src,0x80);
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???]
                       Unresolved local var: size_t __result@[???] */
      iVar1 = 0;
      while (((local_90[0] != '\0' && (local_90[0] != '\n')) && (local_90[0] != ';'))) {
        iVar1 = iVar1 + 1;
        local_90[0] = local_90[iVar1];
      }
      local_90[iVar1] = '\0';
      __snprintf_chk(local_110,0x80,1,0x80,&LAB_002589a2,local_90);
      Cbuf_AddText(local_110);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Reload_f  @ 000c2c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Reload_f(void)

{
  char *s1;
  char *pcVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char * pSaveName@[???]
                       Unresolved local var: char[260] name@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  S_StopAllSounds(true);
  Host_ClearSaveDirectory();
  if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
    (*gEntityInterface.pfnResetGlobalState)();
  }
  SV_InactivateClients();
  SV_ServerShutdown();
  s1 = Host_FindRecentSave(local_114,0x104);
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
                       Unresolved local var: char[5] szNumber@[???]
                       Unresolved local var: int nSlot@[???] */
  if ((s1 != (char *)0x0) && (*s1 != '\0')) {
    pcVar1 = Q_strstr(s1,"..");
    if (pcVar1 == (char *)0x0) {
      iVar2 = Host_Load(s1);
      if (iVar2 != 0) goto LAB_000c2ca8;
    }
    else {
      Con_Printf("Relative pathnames are not allowed.\n");
    }
  }
  SV_SpawnServer(false,gHostMap.string,(char *)0x0);
  SV_LoadEntities();
  SV_ActivateServer(1);
LAB_000c2ca8:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Reload_f  @ 000c2d00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Reload_f(void)

{
                    /* Unresolved local var: char * pSaveName@[???]
                       Unresolved local var: char[260] name@[???] */
  if (((cls.demoplayback == false) && (sv.active != false)) && (cmd_source == src_command)) {
    Host_Reload_f();
    return;
  }
  return;
}


// Host_Restart_f  @ 000c1dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Restart_f(void)

{
  int in_GS_OFFSET;
  char local_114 [259];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[260] name@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state != ca_dedicated) {
    cls.state = ca_disconnected;
  }
  S_StopAllSounds(true);
  Host_ClearSaveDirectory();
  if (gEntityInterface.pfnResetGlobalState != (_func_void *)0x0) {
    (*gEntityInterface.pfnResetGlobalState)();
  }
  SV_InactivateClients();
  Q_strncpy(local_114,sv.name,0x103);
  local_11 = 0;
  SV_ServerShutdown();
  SV_SpawnServer(false,local_114,(char *)0x0);
  SV_LoadEntities();
  SV_ActivateServer(1);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Restart_f  @ 000c1e80
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


// Host_SaveAgeList  @ 000be0a0
void Host_SaveAgeList(char *pName,int count)

{
  int in_GS_OFFSET;
  char local_228 [260];
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[260] newName@[???]
                       Unresolved local var: char[260] oldName@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  __snprintf_chk(local_228,0x104,1,0x104,&LAB_00258bf8,Host_SaveGameDirectory::szDirectory,pName,
                 count);
  COM_FixSlashes(local_228);
  FS_RemoveFile(local_228,"GAMECONFIG");
  if (0 < count) {
    while (count != 1) {
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
      __snprintf_chk(local_124,0x104,1,0x104,&LAB_00258bf8,Host_SaveGameDirectory::szDirectory,pName
                     ,count + -1);
      COM_FixSlashes(local_124);
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
      __snprintf_chk(local_228,0x104,1,0x104,&LAB_00258bf8,Host_SaveGameDirectory::szDirectory,pName
                     ,count);
      COM_FixSlashes(local_228);
      FS_Rename(local_124,local_228);
      count = count + -1;
    }
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    __snprintf_chk(local_124,0x104,1,0x104,&LAB_00258c05,Host_SaveGameDirectory::szDirectory,pName);
    COM_FixSlashes(local_124);
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    __snprintf_chk(local_228,0x104,1,0x104,&LAB_00258bf8,Host_SaveGameDirectory::szDirectory,pName,1
                  );
    COM_FixSlashes(local_228);
    FS_Rename(local_124,local_228);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_SaveGameDirectory  @ 000be000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Host_SaveGameDirectory(void)

{
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  return Host_SaveGameDirectory::szDirectory;
}


// Host_SavegameComment  @ 000ba490
/* WARNING: Removing unreachable block (ram,0x000ba543) */

void Host_SavegameComment(char *pszBuffer,int iSizeBuffer)

{
  int iVar1;
  char *__src;
  int iVar2;
  char *s1;
  bool bVar3;
  
                    /* Unresolved local var: char * pszName@[???]
                       Unresolved local var: char * pszMapName@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = 0;
  s1 = pr_strings + gGlobalVariables.mapname;
  do {
    iVar1 = Q_strlen(gTitleComments[iVar2].pBSPName);
    iVar1 = Q_strnicmp(s1,gTitleComments[iVar2].pBSPName,iVar1);
    if (iVar1 == 0) {
      __src = gTitleComments[iVar2].pTitleName;
      bVar3 = __src == (char *)0x0;
    }
    else {
      __src = (char *)0x0;
      bVar3 = true;
    }
  } while ((iVar2 + 1U < 0x54) && (iVar2 = iVar2 + 1, bVar3));
  if ((__src == (char *)0x0) && ((s1 == (char *)0x0 || (__src = s1, *s1 == '\0')))) {
    iVar2 = Q_strlen(cl.levelname);
    __src = cl.levelname;
    if (iVar2 == 0) {
      __src = s1;
    }
  }
  strncpy(pszBuffer,__src,iSizeBuffer - 1);
  pszBuffer[iSizeBuffer + -1] = '\0';
  return;
}


// Host_Savegame_f  @ 000c1190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Savegame_f(void)

{
  int iVar1;
  char *s1;
  char *pcVar2;
  int in_GS_OFFSET;
  double dVar3;
  char local_b0 [79];
  undefined1 local_61;
  char local_60 [80];
  int local_10;
  
                    /* Unresolved local var: char[80] szComment@[???]
                       Unresolved local var: char[80] szTemp@[???]
                       Unresolved local var: char * pFilename@[???]
                       Unresolved local var: char * pchLoadExtension@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    if (sv.active == false) {
      Con_Printf("Not playing a local game.\n");
    }
    else if (svs.maxclients == 1) {
      if ((cls.state == ca_active) && (cls.signon == 2)) {
        if (cl.intermission == 0) {
          if (((svs.clients)->active == false) || (0.0 < ((svs.clients)->edict->v).health)) {
            iVar1 = Cmd_Argc();
            if (iVar1 == 2) {
              s1 = Cmd_Argv(1);
              if (*s1 != '/') {
                pcVar2 = Q_strstr(s1,":");
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = Q_strstr(s1,"..");
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = Q_strstr(s1,"\\");
                    if (pcVar2 == (char *)0x0) {
                      COM_DefaultExtension(s1,".sav");
                      pcVar2 = COM_LastFileExtension(s1);
                      if (pcVar2 != (char *)0x0) {
                        iVar1 = Q_stricmp(pcVar2,"sav");
                        if (iVar1 == 0) {
                          (*g_pSaveGameCommentFunc)(local_60,0x50);
                          dVar3 = fmod(sv.time,60.0);
                          __snprintf_chk(local_b0,0x4f,1,0x50,0x258d8e,local_60,
                                         (int)((float)sv.time / 60.0),(int)dVar3);
                          local_61 = 0;
                          SaveGameSlot(s1,local_b0);
                          CL_HudMessage("GAMESAVED");
                          goto LAB_000c11bc;
                        }
                      }
                      Con_Printf("Couldn\'t open %s (wrong file extension, must be .sav)\n");
                      goto LAB_000c11bc;
                    }
                  }
                }
              }
              Con_Printf("Couldn\'t open %s (contains illegal characters).\n");
            }
            else {
              Con_Printf("save <savename> : save a game\n");
            }
          }
          else {
            Con_Printf("Can\'t savegame with a dead player\n");
          }
        }
        else {
          Con_Printf("Can\'t save in intermission.\n");
        }
      }
      else {
        Con_Printf("Can\'t save during transition.\n");
      }
    }
    else {
      Con_Printf("Can\'t save multiplayer games.\n");
    }
  }
LAB_000c11bc:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Say  @ 000c2e00
void Host_Say(qboolean teamonly)

{
  bool bVar1;
  client_t *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  edict_t *ed;
  client_t *pcVar6;
  char *str;
  int in_GS_OFFSET;
  char local_a0;
  undefined1 local_9f [127];
  int local_20;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: qboolean fromServer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state == ca_dedicated) {
    iVar3 = Cmd_Argc();
    if ((1 < iVar3) && (pcVar4 = Cmd_Args(), pcVar2 = host_client, pcVar4 != (char *)0x0)) {
      str = pcVar4;
      if (*pcVar4 == '\"') {
        str = pcVar4 + 1;
        iVar3 = Q_strlen(str);
        pcVar4[iVar3] = '\0';
      }
      pcVar4 = Cvar_VariableString("hostname");
      __snprintf_chk(&local_a0,0x80,1,0x80,0x258a71,1,pcVar4);
      iVar3 = Q_strlen(str);
      if (0x3f < iVar3) {
        str[0x3f] = '\0';
      }
      iVar3 = Q_strlen(&local_a0);
      iVar5 = Q_strlen(str);
      if (0x7e - iVar3 < iVar5) {
        str[0x7e - iVar3] = '\0';
      }
      Q_strcat(&local_a0,str);
      Q_strcat(&local_a0,"\n");
      iVar5 = 1;
      iVar3 = svs.maxclients;
      pcVar6 = svs.clients;
      if (0 < svs.maxclients) {
        do {
          if ((((pcVar6 != (client_t *)0x0) && (pcVar6->active != false)) &&
              (pcVar6->spawned != false)) && (pcVar6->fakeclient == false)) {
            ed = sv.edicts + iVar5;
            host_client = pcVar6;
            iVar3 = RegUserMsg("SayText",-1);
            PF_MessageBegin_I(1,iVar3,(float *)0x0,ed);
            PF_WriteByte_I(0);
            PF_WriteString_I(&local_a0);
            PF_MessageEnd_I();
            iVar3 = svs.maxclients;
          }
          bVar1 = iVar5 < iVar3;
          iVar5 = iVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar1);
      }
      host_client = pcVar2;
      Sys_Printf("%s",local_9f);
      Log_Printf("Server say \"%s\"\n",str);
    }
  }
  else if (cmd_source == src_command) {
    Cmd_ForwardToServer();
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Say_Team_f  @ 000bc3f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Say_Team_f(void)

{
  bool bVar1;
  client_t *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  edict_t *ed;
  client_t *pcVar6;
  char *str;
  int in_GS_OFFSET;
  char local_a0;
  undefined1 local_9f [127];
  int local_20;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: qboolean fromServer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state == ca_dedicated) {
    iVar3 = Cmd_Argc();
    if ((1 < iVar3) && (pcVar4 = Cmd_Args(), pcVar2 = host_client, pcVar4 != (char *)0x0)) {
      str = pcVar4;
      if (*pcVar4 == '\"') {
        str = pcVar4 + 1;
        iVar3 = Q_strlen(str);
        pcVar4[iVar3] = '\0';
      }
      pcVar4 = Cvar_VariableString("hostname");
      __snprintf_chk(&local_a0,0x80,1,0x80,0x258a71,1,pcVar4);
      iVar3 = Q_strlen(str);
      if (0x3f < iVar3) {
        str[0x3f] = '\0';
      }
      iVar3 = Q_strlen(&local_a0);
      iVar5 = Q_strlen(str);
      if (0x7e - iVar3 < iVar5) {
        str[0x7e - iVar3] = '\0';
      }
      Q_strcat(&local_a0,str);
      Q_strcat(&local_a0,"\n");
      iVar5 = 1;
      iVar3 = svs.maxclients;
      pcVar6 = svs.clients;
      if (0 < svs.maxclients) {
        do {
          if ((((pcVar6 != (client_t *)0x0) && (pcVar6->active != false)) &&
              (pcVar6->spawned != false)) && (pcVar6->fakeclient == false)) {
            ed = sv.edicts + iVar5;
            host_client = pcVar6;
            iVar3 = RegUserMsg("SayText",-1);
            PF_MessageBegin_I(1,iVar3,(float *)0x0,ed);
            PF_WriteByte_I(0);
            PF_WriteString_I(&local_a0);
            PF_MessageEnd_I();
            iVar3 = svs.maxclients;
          }
          bVar1 = iVar5 < iVar3;
          iVar5 = iVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar1);
      }
      host_client = pcVar2;
      Sys_Printf("%s",local_9f);
      Log_Printf("Server say \"%s\"\n",str);
    }
  }
  else if (cmd_source == src_command) {
    Cmd_ForwardToServer();
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Say_f  @ 000bc190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Say_f(void)

{
  bool bVar1;
  client_t *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  edict_t *ed;
  client_t *pcVar6;
  char *str;
  int in_GS_OFFSET;
  char local_a0;
  undefined1 local_9f [127];
  int local_20;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: qboolean fromServer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state == ca_dedicated) {
    iVar3 = Cmd_Argc();
    if ((1 < iVar3) && (pcVar4 = Cmd_Args(), pcVar2 = host_client, pcVar4 != (char *)0x0)) {
      str = pcVar4;
      if (*pcVar4 == '\"') {
        str = pcVar4 + 1;
        iVar3 = Q_strlen(str);
        pcVar4[iVar3] = '\0';
      }
      pcVar4 = Cvar_VariableString("hostname");
      __snprintf_chk(&local_a0,0x80,1,0x80,0x258a71,1,pcVar4);
      iVar3 = Q_strlen(str);
      if (0x3f < iVar3) {
        str[0x3f] = '\0';
      }
      iVar3 = Q_strlen(&local_a0);
      iVar5 = Q_strlen(str);
      if (0x7e - iVar3 < iVar5) {
        str[0x7e - iVar3] = '\0';
      }
      Q_strcat(&local_a0,str);
      Q_strcat(&local_a0,"\n");
      iVar5 = 1;
      iVar3 = svs.maxclients;
      pcVar6 = svs.clients;
      if (0 < svs.maxclients) {
        do {
          if ((((pcVar6 != (client_t *)0x0) && (pcVar6->active != false)) &&
              (pcVar6->spawned != false)) && (pcVar6->fakeclient == false)) {
            ed = sv.edicts + iVar5;
            host_client = pcVar6;
            iVar3 = RegUserMsg("SayText",-1);
            PF_MessageBegin_I(1,iVar3,(float *)0x0,ed);
            PF_WriteByte_I(0);
            PF_WriteString_I(&local_a0);
            PF_MessageEnd_I();
            iVar3 = svs.maxclients;
          }
          bVar1 = iVar5 < iVar3;
          iVar5 = iVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar1);
      }
      host_client = pcVar2;
      Sys_Printf("%s",local_9f);
      Log_Printf("Server say \"%s\"\n",str);
    }
  }
  else if (cmd_source == src_command) {
    Cmd_ForwardToServer();
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_SetAddonsFolder_f  @ 000aee50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetAddonsFolder_f(void)

{
  int iVar1;
  char *__s1;
  int iVar2;
  bool bVar3;
  
                    /* Unresolved local var: bool bEnabled@[???] */
  if (cls.state == ca_dedicated) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    iVar1 = (*registry->_vptr_IRegistry[2])(registry,0x258ec0,0);
    __s1 = Cmd_Argv(1);
    iVar2 = strcasecmp(__s1,"1");
    if (iVar2 == 0) {
      (*registry->_vptr_IRegistry[3])(registry,0x258ec0,1);
    }
    else {
      (*registry->_vptr_IRegistry[3])(registry,0x258ec0,0);
    }
    iVar2 = COM_CheckParm("-addons");
    bVar3 = true;
    if (iVar2 == 0) {
      iVar2 = (*registry->_vptr_IRegistry[2])(registry,0x258ec0,0);
      bVar3 = 0 < iVar2;
    }
    if (0 < iVar1 != bVar3) {
      COM_SetupDirectories();
      return;
    }
  }
  return;
}


// Host_SetGameDir_f  @ 000bae50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetGameDir_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
                    /* Unresolved local var: char * pDir@[???] */
  iVar1 = Cmd_Argc();
  if ((0 < iVar1) && (g_pPostRestartCmdLineArgs != (char *)0x0)) {
    pcVar2 = Cmd_Argv(1);
    if (((pcVar2 != (char *)0x0) &&
        (((*pcVar2 != '/' && (pcVar3 = Q_strstr(pcVar2,":"), pcVar3 == (char *)0x0)) &&
         (pcVar3 = Q_strstr(pcVar2,".."), pcVar3 == (char *)0x0)))) &&
       (pcVar3 = Q_strstr(pcVar2,"\\"), pcVar3 == (char *)0x0)) {
                    /* Unresolved local var: char * pDir@[???] */
      strcat(g_pPostRestartCmdLineArgs," -game ");
      pcVar2 = Cmd_Argv(1);
      strcat(g_pPostRestartCmdLineArgs,pcVar2);
      return;
    }
    Con_Printf("Couldn\'t set gamedir to %s (contains illegal characters)\n",pcVar2);
  }
  return;
}


// Host_SetHDModels_f  @ 000aed60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetHDModels_f(void)

{
  int iVar1;
  char *__s1;
  int iVar2;
  bool bVar3;
  
                    /* Unresolved local var: bool bEnabled@[???] */
  if (cls.state == ca_dedicated) {
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    iVar1 = (*registry->_vptr_IRegistry[2])(registry,0x2577b6,0);
    __s1 = Cmd_Argv(1);
    iVar2 = strcasecmp(__s1,"1");
    if (iVar2 == 0) {
      (*registry->_vptr_IRegistry[3])(registry,0x2577b6,1);
    }
    else {
      (*registry->_vptr_IRegistry[3])(registry,0x2577b6,0);
    }
    iVar2 = COM_CheckParm("-nohdmodels");
    bVar3 = false;
    if (iVar2 == 0) {
      iVar2 = (*registry->_vptr_IRegistry[2])(registry,0x2577b6,0);
      bVar3 = 0 < iVar2;
    }
    if (0 < iVar1 != bVar3) {
      COM_SetupDirectories();
      return;
    }
  }
  return;
}


// Host_SetInfo_f  @ 000bb450
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


// Host_SetRenderer_f  @ 000bb710
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetRenderer_f(void)

{
  int iVar1;
  char *pcVar2;
  uint windowed;
  int hardware;
  
                    /* Unresolved local var: int hardware@[???]
                       Unresolved local var: int windowed@[???] */
  if (cls.state == ca_dedicated) {
    return;
  }
  iVar1 = Cmd_Argc();
  if ((iVar1 != 2) && (iVar1 = Cmd_Argc(), iVar1 != 3)) {
    return;
  }
                    /* Unresolved local var: int hardware@[???]
                       Unresolved local var: int windowed@[???] */
  hardware = 0;
  pcVar2 = Cmd_Argv(1);
  iVar1 = strcasecmp(pcVar2,"software");
  if (iVar1 != 0) {
    pcVar2 = Cmd_Argv(1);
    iVar1 = strcasecmp(pcVar2,"gl");
    if (iVar1 != 0) {
      pcVar2 = Cmd_Argv(1);
      iVar1 = strcasecmp(pcVar2,"d3d");
      if (iVar1 == 0) {
        hardware = 2;
        goto LAB_000bb763;
      }
    }
    hardware = 1;
  }
LAB_000bb763:
  iVar1 = Cmd_Argc();
  windowed = 0;
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(2);
    iVar1 = strcasecmp(pcVar2,"windowed");
    windowed = (uint)(iVar1 == 0);
  }
  VideoMode_SwitchMode(hardware,windowed);
  return;
}


// Host_SetRichPresenceGameMode_f  @ 000b9ff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetRichPresenceGameMode_f(void)

{
  int iVar1;
  char *pszString;
  
                    /* Unresolved local var: char * pszGameMode@[???] */
  iVar1 = Cmd_Argc();
  if (0 < iVar1) {
    pszString = Cmd_Argv(1);
    Steam_SetRichPresenceGameMode(pszString);
    return;
  }
  Steam_SetRichPresenceGameMode((char *)0x0);
  return;
}


// Host_SetRichPresenceNiceMap_f  @ 000b9fb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetRichPresenceNiceMap_f(void)

{
  int iVar1;
  char *pszNiceMapName;
  
                    /* Unresolved local var: char * pszNiceMapName@[???] */
  iVar1 = Cmd_Argc();
  if (0 < iVar1) {
    pszNiceMapName = Cmd_Argv(1);
    Steam_SetRichPresenceInfo(pszNiceMapName);
    return;
  }
  Steam_SetRichPresenceInfo((char *)0x0);
  return;
}


// Host_SetRichPresenceOverride_f  @ 000b9f70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetRichPresenceOverride_f(void)

{
  int iVar1;
  char *pszString;
  
                    /* Unresolved local var: char * pszString@[???] */
  iVar1 = Cmd_Argc();
  if (0 < iVar1) {
    pszString = Cmd_Argv(1);
    Steam_SetRichPresenceOverride(pszString);
    return;
  }
  Steam_SetRichPresenceOverride((char *)0x0);
  return;
}


// Host_SetRichPresenceUpdate_f  @ 000ba030
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetRichPresenceUpdate_f(void)

{
  CSteam3Client::UpdateRichPresence(&s_Steam3Client);
  return;
}


// Host_SetVideoMode_f  @ 000bb810
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_SetVideoMode_f(void)

{
  int iVar1;
  char *pcVar2;
  int height;
  int iVar3;
  
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
  if (cls.state != ca_dedicated) {
    iVar1 = Cmd_Argc();
    if ((iVar1 == 3) || (iVar1 = Cmd_Argc(), iVar1 == 4)) {
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
      pcVar2 = Cmd_Argv(1);
      iVar1 = Q_atoi(pcVar2);
      pcVar2 = Cmd_Argv(2);
      height = Q_atoi(pcVar2);
      iVar3 = Cmd_Argc();
      if (iVar3 == 4) {
        pcVar2 = Cmd_Argv(3);
        iVar3 = Q_atoi(pcVar2);
      }
      else {
        iVar3 = 0x10;
      }
      VideoMode_SetVideoMode(iVar1,height,iVar3);
    }
    return;
  }
  return;
}


// Host_ShowOSK_f  @ 000ba040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_ShowOSK_f(void)

{
  int iVar1;
  char *pcVar2;
  long fieldX;
  
                    /* Unresolved local var: int fieldX@[???]
                       Unresolved local var: int fieldY@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    iVar1 = 0;
    fieldX = 0;
  }
  else {
    pcVar2 = Cmd_Argv(1);
    fieldX = strtol(pcVar2,(char **)0x0,10);
    pcVar2 = Cmd_Argv(2);
    iVar1 = strtol(pcVar2,(char **)0x0,10);
  }
  Steam_ShowOnScreenKeyboard(fieldX,iVar1);
  return;
}


// Host_Shutdown  @ 000b9d10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Shutdown(void)

{
  client_frame_t **frames;
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * pclient@[???] */
  if (Host_Shutdown::isdown == false) {
    Host_Shutdown::isdown = true;
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: kbutton_t * ml@[???]
                       Unresolved local var: kbutton_t * jl@[???]
                       Unresolved local var: qboolean bSetFileToReadOnly@[???] */
    if ((host_initialized != false) && (cls.state != ca_dedicated)) {
      SetRateRegistrySetting(rate.string);
      iVar1 = Key_CountBindings();
      if (iVar1 < 2) {
        Con_Printf("skipping config.cfg output, no keys bound\n");
      }
      else {
        Host_WriteConfiguration();
      }
    }
    SV_ServerShutdown();
    Voice_Deinit();
    host_initialized = false;
    CDAudio_Shutdown();
    VGui_Shutdown();
    if (cls.state != ca_dedicated) {
      ClientDLL_Shutdown();
    }
    Cmd_RemoveGameCmds();
    Cmd_Shutdown();
    Cvar_Shutdown();
    HPAK_FlushHostQueue();
    SV_DeallocateDynamicData();
    if (0 < svs.maxclientslimit) {
      iVar1 = 0;
      frames = &(svs.clients)->frames;
      do {
        iVar1 = iVar1 + 1;
        SV_ClearFrames(frames);
        frames = frames + 0x199a;
      } while (iVar1 < svs.maxclientslimit);
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
    Key_Shutdown();
    realtime._0_4_ = 0;
    sv.time._4_4_ = 0;
    cl.time._0_4_ = 0;
    realtime._4_4_ = 0;
    sv.time._0_4_ = 0;
    cl.time._4_4_ = 0;
    return;
  }
  puts("recursive shutdown");
  return;
}


// Host_ShutdownServer  @ 000b81c0
void __regparm3 Host_ShutdownServer(qboolean crash)

{
  int iVar1;
  client_t *cl;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
  SV_ServerShutdown();
  sv.active = false;
  NET_ClearLagData(true,true);
  host_client = svs.clients;
  iVar2 = svs.maxclients;
  if (0 < svs.maxclients) {
    do {
      if ((host_client->active != false) || (host_client->connected != false)) {
        SV_DropClient(host_client,crash,"Server shutting down");
        iVar2 = svs.maxclients;
      }
      iVar1 = iVar1 + 1;
      host_client = host_client + 1;
    } while (iVar1 < iVar2);
  }
  CL_Disconnect();
  SV_ClearEntities();
  SV_ClearCaches();
  FreeAllEntPrivateData();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  iVar2 = 0;
  Q_memset(&sv,0,0x473ac);
  CL_ClearClientState();
  cl = svs.clients;
  if (0 < svs.maxclients) {
    do {
      iVar2 = iVar2 + 1;
      COM_ClearCustomizationList(&cl->customdata,false);
      SV_ClearResourceLists(cl);
      cl = cl + 1;
    } while (iVar2 < svs.maxclients);
  }
  iVar2 = 0;
  Host_ClearClients(false);
  host_client = svs.clients;
  if (0 < svs.maxclientslimit) {
    do {
      iVar2 = iVar2 + 1;
      SV_ClearFrames(&host_client->frames);
      host_client = host_client + 1;
    } while (iVar2 < svs.maxclientslimit);
  }
  Q_memset(svs.clients,0,svs.maxclientslimit * 0x6668);
  HPAK_FlushHostQueue();
  Steam_Shutdown();
  Log_Printf("Server shutdown\n");
  Log_Close();
  Steam_UpdateRichPresence();
  return;
}


// Host_ShutdownServer  @ 000b8580
void Host_ShutdownServer(qboolean crash)

{
                    /* Unresolved local var: int i@[???] */
  if (sv.active == false) {
    return;
  }
  Host_ShutdownServer(crash);
  return;
}


// Host_Soundfade_f  @ 000ba2f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Soundfade_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int percent@[???]
                       Unresolved local var: int inTime@[???]
                       Unresolved local var: int holdTime@[???]
                       Unresolved local var: int outTime@[???] */
  iVar1 = Cmd_Argc();
  if ((iVar1 == 3) || (iVar1 = Cmd_Argc(), iVar1 == 5)) {
    pcVar2 = Cmd_Argv(1);
    iVar1 = Q_atoi(pcVar2);
    if (100 < iVar1) {
      iVar1 = 100;
    }
    iVar4 = 0;
    if (-1 < iVar1) {
      iVar4 = iVar1;
    }
    pcVar2 = Cmd_Argv(2);
    iVar1 = Q_atoi(pcVar2);
    if (0xff < iVar1) {
      iVar1 = 0xff;
    }
    iVar3 = Cmd_Argc();
    if (iVar3 == 5) {
      pcVar2 = Cmd_Argv(3);
      iVar3 = Q_atoi(pcVar2);
      if (0xff < iVar3) {
        iVar3 = 0xff;
      }
      pcVar2 = Cmd_Argv(4);
      cls.soundfade.soundFadeInTime = Q_atoi(pcVar2);
      if (0xff < cls.soundfade.soundFadeInTime) {
        cls.soundfade.soundFadeInTime = 0xff;
      }
    }
    else {
      iVar3 = 0;
      cls.soundfade.soundFadeInTime = 0;
    }
    cls.soundfade.soundFadeStartTime = realtime;
    cls.soundfade.nStartPercent = iVar4;
    cls.soundfade.soundFadeOutTime = iVar3;
    cls.soundfade.soundFadeHoldTime = iVar1;
  }
  else {
    Con_Printf("soundfade <percent> <hold> [<out> <int>]\n");
  }
  return;
}


// Host_Speeds  @ 000b8b60
void Host_Speeds(double *time)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  qboolean *pqVar6;
  edict_t *peVar7;
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
    if (sv.num_edicts < 1) {
      iVar8 = 0;
    }
    else {
      iVar8 = 0;
      peVar7 = sv.edicts;
      do {
        pqVar6 = &peVar7->free;
        peVar7 = peVar7 + 1;
        iVar8 = iVar8 + (-(uint)(*pqVar6 == false) & 1);
      } while (sv.edicts + sv.num_edicts != peVar7);
    }
    Con_Printf("%3i fps -- host(%3.0f) sv(%3.0f) cl(%3.0f) gfx(%3.0f) snd(%3.0f) ents(%d)\n",
               (int)lVar9,(double)fVar1,(double)fVar2,(double)fVar3,(double)fVar4,(double)fVar5,
               iVar8);
  }
  if (cl_gamegauge.value == 0.0) {
    return;
  }
  CL_GGSpeeds((float)time[3]);
  return;
}


// Host_Startdemos_f  @ 000bbff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Startdemos_f(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char *src;
  int iVar4;
  char (*dest) [16];
  char *pcVar5;
  
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
  pcVar5 = (char *)(iVar3 + -1);
  if ((int)pcVar5 < 0x21) {
    src = pcVar5;
    Con_Printf("%i demo(s) in loop\n",pcVar5);
    if ((int)pcVar5 < 1) goto LAB_000bc0a7;
  }
  else {
    pcVar5 = (char *)0x20;
    Con_Printf("Max %i demos in demoloop\n",0x20);
    Con_Printf("%i demo(s) in loop\n",0x20);
  }
  dest = cls.demos;
  iVar3 = 1;
  do {
    iVar1 = iVar3 + -1;
    src = Cmd_Argv(iVar3);
    Q_strncpy(*dest,src,0xf);
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???]
                       Unresolved local var: size_t __result@[???] */
    cVar2 = (*dest)[0];
    iVar4 = 0;
    (*dest)[0xf] = '\0';
    while (((cVar2 != '\0' && (cVar2 != '\n')) && (cVar2 != ';'))) {
      iVar4 = iVar4 + 1;
      cVar2 = (*dest)[iVar4];
    }
    iVar3 = iVar3 + 1;
    dest = dest + 1;
    *(undefined1 *)(iVar4 + 0xdf920c + iVar1 * 0x10) = 0;
  } while (iVar3 <= (int)pcVar5);
LAB_000bc0a7:
  if (((sv.active != false) || (cls.demonum == -1)) || (cls.demoplayback != false)) {
    cls.demonum = -1;
    return;
  }
                    /* Unresolved local var: char[1024] str@[???] */
  cls.demonum = 0;
  SCR_BeginLoadingPlaque(false);
  if (((cls.demos[cls.demonum][0] == '\0') || (cls.demonum == 0x20)) &&
     (cls.demonum = 0, cls.demos[0][0] == '\0')) {
    Con_Printf("No demos listed with startdemos\n",src);
    cls.demonum = -1;
    return;
  }
  Host_NextDemo();
  return;
}


// Host_Stats_f  @ 000bcc60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Stats_f(void)

{
  int in_GS_OFFSET;
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] stats@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  GetStatsString(local_210,0x200);
  Con_Printf("CPU   In    Out   Uptime  Users   FPS    Players\n%s\n",local_210);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Status_Formatted_f  @ 000bd440
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
  undefined1 *puVar7;
  int iVar8;
  qboolean conprint;
  client_t *cl;
  int iVar9;
  int in_GS_OFFSET;
  char *pcVar10;
  undefined4 uVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  qboolean local_130;
  int local_128;
  char local_124 [260];
  int local_20;
  
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
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((cmd_source == src_command) && (conprint = true, sv.active == false)) {
    Cmd_ForwardToServer();
    goto LAB_000bd865;
  }
  iVar3 = Cmd_Argc();
  if (iVar3 == 2) {
    pcVar5 = Cmd_Argv(1);
    iVar3 = Q_strcasecmp(pcVar5,"log");
    if (iVar3 != 0) goto LAB_000bd476;
                    /* Unresolved local var: char[260] szfile@[???] */
    builtin_strncpy(local_124,"status.log",0xb);
    unlink(local_124);
    local_130 = true;
  }
  else {
LAB_000bd476:
    local_130 = false;
  }
  qVar4 = Steam_GSBSecure();
  pcVar5 = Cvar_VariableString("hostname");
  Host_Status_Printf(conprint,local_130,"hostname:  %s\n",pcVar5);
  puVar7 = &LAB_00264c9b;
  if (qVar4 == 0) {
    puVar7 = (undefined1 *)0x262877;
  }
  iVar3 = build_number();
  Host_Status_Printf(conprint,local_130,"version :  %i/%s %d %s\n",0x30,gpszVersionString,iVar3,
                     puVar7);
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
    uVar11 = net_local_adr._16_4_;
    pcVar5 = NET_AdrToString(a);
    Host_Status_Printf(conprint,local_130,"tcp/ip  :  %s\n",pcVar5,uVar11,iVar3,puVar7);
  }
  Host_Status_Printf(conprint,local_130,"map     :  %s at: %d x, %d y, %d z\n",0x9cbfa8,
                     (int)r_origin[0],(int)r_origin[1],(int)r_origin[2]);
  SV_CountPlayers(&local_128);
  Host_Status_Printf(conprint,local_130,"players :  %i active (%i max)\n\n",local_128,svs.maxclients
                    );
  pcVar17 = "adr";
  pcVar16 = "loss";
  pcVar15 = "ping";
  pcVar5 = "time    ";
  pcVar14 = "frag";
  iVar9 = 1;
  pcVar13 = "uniqueid ";
  pcVar12 = "userid   ";
  pcVar10 = "name    ";
  Host_Status_Printf(conprint,local_130,
                     "%-2.2s\t%-9.9s\t%-7.7s\t%-20.20s\t%-4.4s\t%-8.8s\t%-4.4s\t%-4.4s\t%-21.21s\n",
                     &LAB_00258b96_1,&LAB_00258b8e,0x258b84,0x258b7a,"frag",&LAB_00258b71,"ping",
                     0x26107b,&LAB_00258b6d);
  iVar3 = svs.maxclients;
  cl = svs.clients;
  if (0 < svs.maxclients) {
    do {
      if (cl->active != false) {
        iVar8 = (int)(realtime - (double)(cl->netchan).connect_time);
        iVar2 = iVar8 / 0x3c;
        iVar3 = iVar8;
        if (iVar2 == 0) {
LAB_000bd774:
          __snprintf_chk(local_124,0x20,1,0x20,0x258b41,iVar2,iVar3);
        }
        else {
          iVar3 = iVar8 % 0x3c;
          iVar8 = iVar8 / 0xe10;
          if (iVar8 == 0) goto LAB_000bd774;
          __snprintf_chk(local_124,0x20,1,0x20,&LAB_00258b9a,iVar8,iVar2 + iVar8 * -0x3c,iVar3);
        }
        pcVar17 = "";
        if (conprint != false) {
          pcVar17 = NET_AdrToString((cl->netchan).remote_address);
        }
        pcVar16 = va("%-4i",(int)cl->packet_loss);
        iVar3 = SV_CalcPing(cl);
        pcVar15 = va("%-4i",iVar3);
        pcVar14 = va("%-4i",(int)(cl->edict->v).frags);
        pcVar13 = SV_GetClientIDString(cl);
        pcVar12 = va("%-7i",cl->userid);
        pcVar10 = va("\"%s\"",cl->name);
        pcVar6 = va("%-2i",iVar9);
        pcVar5 = local_124;
        Host_Status_Printf(conprint,local_130,
                           "%-2.2s\t%-9.9s\t%-7.7s\t%-20.20s\t%-4.4s\t%-8.8s\t%-4.4s\t%-4.4s\t%-21.21s\n"
                           ,pcVar6,pcVar10,pcVar12,pcVar13,pcVar14,pcVar5,pcVar15,pcVar16,pcVar17);
        iVar3 = svs.maxclients;
      }
      bVar1 = iVar9 < iVar3;
      cl = cl + 1;
      iVar9 = iVar9 + 1;
    } while (bVar1);
  }
  Host_Status_Printf(conprint,local_130,"%i users\n",local_128,pcVar10,pcVar12,pcVar13,pcVar14,
                     pcVar5,pcVar15,pcVar16,pcVar17);
LAB_000bd865:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Status_Printf  @ 000bccc0
void Host_Status_Printf(qboolean conprint,qboolean log,char *fmt,...)

{
  int in_GS_OFFSET;
  char local_1114 [260];
  undefined1 local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: char[4096] string@[???]
                       Unresolved local var: va_list argptr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_1010,0x1000,1,0x1000,fmt,&stack0x00000010);
  if (conprint == false) {
    SV_ClientPrintf("%s",local_1010);
  }
  else {
    Con_Printf("%s");
  }
  if (log != false) {
                    /* Unresolved local var: char[260] szfile@[???] */
    builtin_strncpy(local_1114,"status.log",0xb);
    COM_Log(local_1114,"%s",local_1010);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Status_f  @ 000bcda0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Status_f(void)

{
  bool bVar1;
  netadr_t a;
  netadr_t a_00;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  qboolean qVar5;
  qboolean qVar6;
  undefined1 *puVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  undefined1 *puVar11;
  qboolean log;
  qboolean conprint;
  client_s *client;
  int in_GS_OFFSET;
  undefined4 uVar12;
  char *local_154;
  int local_150;
  int local_144;
  int local_140;
  int local_138;
  int local_134;
  int local_130;
  int local_128;
  char local_124 [260];
  int local_20;
  
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
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((cmd_source == src_command) && (conprint = true, sv.active == false)) {
    Cmd_ForwardToServer();
    goto LAB_000bd1cc;
  }
  iVar2 = Cmd_Argc();
  if (iVar2 == 2) {
    pcVar3 = Cmd_Argv(1);
    iVar2 = Q_strcasecmp(pcVar3,"log");
    if (iVar2 != 0) goto LAB_000bcdd6;
                    /* Unresolved local var: char[260] szfile@[???] */
    log = true;
    builtin_strncpy(local_124,"status.log",0xb);
    unlink(local_124);
  }
  else {
LAB_000bcdd6:
    log = false;
  }
  pcVar3 = Cvar_VariableString("hostname");
  Host_Status_Printf(conprint,log,"hostname:  %s\n",pcVar3);
  qVar4 = Steam_GSBSecure();
  qVar5 = Steam_GSBSecurePreference();
  qVar6 = Steam_GSBLoggedOn();
  if ((qVar4 == 0) && (qVar5 != 0)) {
    puVar11 = &LAB_002599d0;
    if (qVar6 != 0) {
      puVar11 = &LAB_002599a4;
    }
  }
  else {
    puVar11 = &DAT_0027abd7;
  }
  local_154 = "";
  if (sv.active != false) {
    local_154 = Steam_GetGSUniverse();
  }
  iVar2 = GetGameAppID();
  puVar7 = &LAB_00264c9b;
  if (qVar4 == 0) {
    puVar7 = (undefined1 *)0x262877;
  }
  iVar8 = build_number();
  Host_Status_Printf(conprint,log,"version :  %i/%s %d %s %s%s (%d)\n",0x30,gpszVersionString,iVar8,
                     puVar7,puVar11,local_154,iVar2);
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
    pcVar3 = NET_AdrToString(a_00);
    Host_Status_Printf(conprint,log,"tcp/ip  :  %s\n",pcVar3,uVar12,iVar8,puVar7,puVar11,local_154,
                       iVar2);
  }
  Host_Status_Printf(conprint,log,"map     :  %s at: %d x, %d y, %d z\n",0x9cbfa8,(int)r_origin[0],
                     (int)r_origin[1],(int)r_origin[2],puVar11,local_154,iVar2);
  SV_CountPlayers(&local_128);
  iVar2 = svs.maxclients;
  Host_Status_Printf(conprint,log,"players :  %i active (%i max)\n\n",local_128,svs.maxclients);
  Host_Status_Printf(conprint,log,"#      name userid uniqueid frag time ping loss adr\n");
  if (0 < svs.maxclients) {
    local_150 = 1;
    local_130 = 0;
    local_134 = 0;
    local_138 = 0;
    iVar8 = svs.maxclients;
    client = svs.clients;
    do {
      while (client->active == false) {
LAB_000bcf80:
        client = client + 1;
        bVar1 = iVar8 <= local_150;
        local_150 = local_150 + 1;
        if (bVar1) goto LAB_000bd1af;
      }
      iVar8 = (int)(realtime - (double)(client->netchan).connect_time);
      local_140 = 0;
      local_144 = iVar8 / 0x3c;
      iVar2 = iVar8;
      if (local_144 != 0) {
        iVar2 = iVar8 % 0x3c;
        local_140 = iVar8 / 0xe10;
        if (local_140 != 0) {
          local_144 = local_144 + local_140 * -0x3c;
        }
      }
      pcVar3 = "BOT";
      if (client->fakeclient == false) {
        pcVar3 = SV_GetClientIDString(client);
      }
      iVar8 = client->userid;
      pcVar9 = va("\"%s\"",client->name);
      Host_Status_Printf(conprint,log,"#%2i %8s %i %s",local_150,pcVar9,iVar8,pcVar3);
      if (client->proxy == false) {
        Host_Status_Printf(conprint,log," %3i",(int)(client->edict->v).frags,pcVar9,iVar8,pcVar3);
      }
      else {
        pcVar9 = client->userinfo;
        pcVar10 = Info_ValueForKey(pcVar9,"hspecs");
        iVar8 = Q_strlen(pcVar10);
        if (iVar8 != 0) {
          local_134 = Q_atoi(pcVar10);
        }
        pcVar10 = Info_ValueForKey(pcVar9,"hslots");
        iVar8 = Q_strlen(pcVar10);
        if (iVar8 != 0) {
          local_138 = Q_atoi(pcVar10);
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
        Host_Status_Printf(conprint,log," %02i:%02i",local_144,iVar2,iVar8,pcVar3);
        local_140 = local_144;
        if (client->proxy == false) goto LAB_000bd233;
LAB_000bd16d:
        if ((client->netchan).remote_address.type == NA_IP) {
          iVar2 = *(int *)((client->netchan).remote_address.ipx + 8);
          a.ip = (uchar  [4])*(undefined4 *)(client->netchan).remote_address.ip;
          a.type = 3;
          a.ipx._0_4_ = *(undefined4 *)(client->netchan).remote_address.ipx;
          a.ipx._4_4_ = *(undefined4 *)((client->netchan).remote_address.ipx + 4);
          a.ipx[8] = (char)iVar2;
          a.ipx[9] = (char)((uint)iVar2 >> 8);
          a.port = (short)((uint)iVar2 >> 0x10);
          pcVar3 = NET_AdrToString(a);
          Host_Status_Printf(conprint,log," %s\n",pcVar3,iVar2,iVar8);
          iVar8 = svs.maxclients;
          goto LAB_000bcf80;
        }
      }
      else {
        iVar8 = iVar2;
        Host_Status_Printf(conprint,log," %2i:%02i:%02i",local_140,local_144,iVar2,pcVar3);
        iVar2 = local_144;
        if (client->proxy != false) goto LAB_000bd16d;
LAB_000bd233:
        iVar2 = (int)client->packet_loss;
        local_140 = SV_CalcPing(client);
        Host_Status_Printf(conprint,log," %4i  %3i",local_140,iVar2,iVar8);
        if ((conprint != false) || (client->proxy != false)) goto LAB_000bd16d;
      }
      client = client + 1;
      Host_Status_Printf(conprint,log,"\n",local_140,iVar2,iVar8);
      bVar1 = local_150 < svs.maxclients;
      iVar8 = svs.maxclients;
      local_150 = local_150 + 1;
    } while (bVar1);
  }
LAB_000bd1af:
  Host_Status_Printf(conprint,log,"%i users\n",local_128,iVar2);
LAB_000bd1cc:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Stopdemo_f  @ 000bb640
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


// Host_Tell_f  @ 000ba720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Tell_f(void)

{
  client_t *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  client_s *pcVar7;
  edict_t *ed;
  int in_GS_OFFSET;
  char local_60 [64];
  int local_20;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: client_t * save@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[64] text@[???]
                       Unresolved local var: char * tellmsg@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    pcVar1 = host_client;
  }
  else {
    iVar2 = Cmd_Argc();
    pcVar1 = host_client;
    if ((2 < iVar2) && (pcVar3 = Cmd_Args(), pcVar1 = host_client, pcVar3 != (char *)0x0)) {
      __snprintf_chk(local_60,0x40,1,0x40,&LAB_002588a8,host_client->name);
      pcVar5 = pcVar3;
      if (*pcVar3 == '\"') {
        pcVar5 = pcVar3 + 1;
        iVar2 = Q_strlen(pcVar5);
        pcVar3[iVar2] = '\0';
      }
      iVar2 = Q_strlen(local_60);
      iVar4 = Q_strlen(pcVar5);
      if (0x3e - iVar2 < iVar4) {
        pcVar5[0x3e - iVar2] = '\0';
      }
      pcVar3 = Cmd_Argv(1);
      pcVar3 = Q_strstr(pcVar5,pcVar3);
      if (pcVar3 == (char *)0x0) {
        Q_strcat(local_60,pcVar5);
      }
      else {
        pcVar5 = Cmd_Argv(1);
        iVar2 = Q_strlen(pcVar5);
        Q_strcat(local_60,pcVar3 + iVar2);
      }
      iVar4 = 0;
      Q_strcat(local_60,"\n");
      pcVar1 = host_client;
      iVar2 = svs.maxclients;
      pcVar7 = svs.clients;
      if (0 < svs.maxclients) {
        do {
          if (((pcVar7->active != false) && (pcVar7->spawned != false)) &&
             (pcVar7->fakeclient == false)) {
            pcVar3 = Cmd_Argv(1);
            iVar6 = Q_strcasecmp(pcVar7->name,pcVar3);
            iVar2 = svs.maxclients;
            if (iVar6 == 0) {
              ed = sv.edicts + iVar4 + 1;
              host_client = pcVar7;
              iVar2 = RegUserMsg("SayText",-1);
              PF_MessageBegin_I(1,iVar2,(float *)0x0,ed);
              PF_WriteByte_I(0);
              PF_WriteString_I(local_60);
              PF_MessageEnd_I();
              break;
            }
          }
          iVar4 = iVar4 + 1;
          pcVar7 = pcVar7 + 1;
        } while (iVar4 < iVar2);
      }
    }
  }
  host_client = pcVar1;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_TogglePause_f  @ 000ba980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_TogglePause_f(void)

{
  string_t sVar1;
  
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (pausable.value != 0.0) {
    sv.paused = sv.paused ^ true;
    sVar1 = (sv_player->v).netname;
    if (sv.paused == false) {
      SV_BroadcastPrintf("%s unpaused the game\n",pr_strings + sVar1);
    }
    else {
      SV_BroadcastPrintf("%s paused the game\n",pr_strings + sVar1);
    }
    MSG_WriteByte(&sv.reliable_datagram,0x18);
    MSG_WriteByte(&sv.reliable_datagram,sv.paused);
    Steam_UpdateRichPresence();
    return;
  }
  SV_ClientPrintf("Pause not allowed.\n");
  Steam_UpdateRichPresence();
  return;
}


// Host_Unpause_f  @ 000bb5c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Unpause_f(void)

{
  if (cl.levelname[0] != '\0') {
    if (cmd_source == src_command) {
      Cmd_ForwardToServer();
      return;
    }
    if (pausable.value != 0.0) {
      Steam_UpdateRichPresence();
      sv.paused = false;
      MSG_WriteByte(&sv.reliable_datagram,0x18);
      MSG_WriteByte(&sv.reliable_datagram,sv.paused);
      Steam_UpdateRichPresence();
      return;
    }
  }
  return;
}


// Host_UpdateScreen  @ 000b8cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_UpdateScreen(void)

{
  if (gfBackground == false) {
    SCR_UpdateScreen();
    if ((cl_inmovie != false) && (scr_con_current == 0.0)) {
      VID_WriteBuffer((char *)0x0);
    }
    return;
  }
  return;
}


// Host_UpdateSounds  @ 000b8e20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_UpdateSounds(void)

{
  vec_t local_30 [3];
  vec_t local_24 [3];
  vec_t local_18 [3];
  
  if (gfBackground == false) {
    if (cls.signon == 2) {
                    /* Unresolved local var: vec3_t vSoundForward@[???]
                       Unresolved local var: vec3_t vSoundRight@[???]
                       Unresolved local var: vec3_t vSoundUp@[???] */
      AngleVectors(r_playerViewportAngles,local_30,local_24,local_18);
      S_Update(r_soundOrigin,local_30,local_24,local_18);
    }
    else {
      S_Update(vec3_origin,vec3_origin,vec3_origin,vec3_origin);
    }
    S_PrintStats();
  }
  return;
}


// Host_UpdateStats  @ 000bc820
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_UpdateStats(void)

{
  int32 iVar1;
  __pid_t _Var2;
  FILE *__stream;
  int in_GS_OFFSET;
  double dVar3;
  undefined1 local_1060 [4];
  int local_105c;
  int local_1058;
  int local_1054;
  sysinfo local_1050;
  char local_1010 [4096];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (startTime == 0) {
    dVar3 = Sys_FloatTime();
    startTime = (int32)dVar3;
  }
  dVar3 = Sys_FloatTime();
  if ((double)Host_UpdateStats::last + 1.0 < dVar3) {
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
    __snprintf_chk(local_1010,0x1000,1,0x1000,&LAB_00258ab9,_Var2);
    __stream = fopen(local_1010,"r");
    if (__stream != (FILE *)0x0) {
      sysinfo(&local_1050);
      __isoc99_fscanf(__stream,&LAB_002598b4,local_1060,local_1010,local_1060,local_1060,local_1060,
                      local_1060,local_1060,local_1060,local_1060,local_1060,local_1060,local_1060,
                      local_1060,&local_105c,&local_1058,local_1060,local_1060,local_1060,local_1060
                      ,local_1060,&local_1054,local_1060,local_1060,local_1060,local_1060,local_1060
                      ,local_1060,local_1060,local_1060,local_1060,local_1060,local_1060,local_1060,
                      local_1060,local_1060,local_1060);
      fclose(__stream);
      local_1054 = local_1050.uptime * 100 - local_1054;
      local_105c = local_105c + local_1058;
      if (Host_UpdateStats::lexical_block_0::lastcputicks == 0) {
        Host_UpdateStats::lexical_block_0::lastcputicks = local_105c;
      }
      iVar1 = local_1054;
      if (Host_UpdateStats::lexical_block_0::lastrunticks != 0) {
        cpuPercent = (double)(local_105c - Host_UpdateStats::lexical_block_0::lastcputicks) /
                     (double)(local_1054 - Host_UpdateStats::lexical_block_0::lastrunticks);
        iVar1 = Host_UpdateStats::lexical_block_0::lastrunticks;
      }
      Host_UpdateStats::lexical_block_0::lastrunticks = iVar1;
      dVar3 = Sys_FloatTime();
      if ((double)Host_UpdateStats::lexical_block_0::lastAvg + 5.0 < dVar3) {
        Host_UpdateStats::lexical_block_0::lastrunticks = local_1054;
        Host_UpdateStats::lexical_block_0::lastcputicks = local_105c;
        dVar3 = Sys_FloatTime();
        Host_UpdateStats::lexical_block_0::lastAvg = (float)dVar3;
      }
      if (cpuPercent <= 0.999) {
        if (cpuPercent < 0.0) {
          cpuPercent = 0.0;
        }
      }
      else {
        cpuPercent = 0.999;
      }
    }
    dVar3 = Sys_FloatTime();
    Host_UpdateStats::last = (float)dVar3;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_ValidSave  @ 000be3a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Host_ValidSave(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (cmd_source == src_command) {
    if (sv.active == false) {
      Con_Printf("Not playing a local game.\n");
      iVar1 = 0;
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
        iVar1 = 1;
        if (((svs.clients)->active != false) && (((svs.clients)->edict->v).health <= 0.0)) {
          Con_Printf("Can\'t savegame with a dead player\n");
          iVar1 = 0;
        }
      }
      else {
        Con_Printf("Can\'t save in intermission.\n");
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// Host_Version  @ 000b9550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Version(void)

{
  FileHandle_t file;
  uint size;
  char *pOutput;
  char *data;
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_144 [32];
  undefined1 *local_124;
  undefined4 local_120;
  undefined2 local_11c;
  int local_20;
  
                    /* Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char * buffer@[???]
                       Unresolved local var: int bufsize@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char * pbuf@[???]
                       Unresolved local var: char * pstart@[???]
                       Unresolved local var: int gotKeys@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_strcpy(gpszVersionString,"1.0.1.4");
  Q_strcpy(gpszProductString,"valve");
  local_124 = &DAT_61657473;
  local_120 = 0x6e692e6d;
  local_11c = 0x66;
  file = FS_Open((char *)&local_124,"r");
  if (file != (FileHandle_t)0x0) {
    size = FS_Size(file);
    pOutput = Mem_Malloc(size + 1);
                    /* Unresolved local var: char[32] szSteamVersionId@[???] */
    FS_Read(pOutput,size,1,file);
    FS_Close(file);
    pOutput[size] = '\0';
    iVar2 = 0;
    data = pOutput;
LAB_000b960f:
    data = COM_Parse(data);
    if (data != (char *)0x0) {
      do {
        iVar1 = Q_strlen(com_token);
        if ((1 < iVar2) || (iVar1 < 1)) break;
        iVar1 = Q_strlen("PatchVersion=");
        iVar1 = Q_strnicmp(com_token,"PatchVersion=",iVar1);
        if (iVar1 == 0) {
          iVar1 = Q_strlen("PatchVersion=");
          Q_strncpy(gpszVersionString,com_token + iVar1,0x1f);
          gpszVersionString[0x1f] = '\0';
          iVar1 = COM_CheckParm("-steam");
          if (iVar1 != 0) {
            FS_GetInterfaceVersion(local_144,0x1f);
            iVar1 = Q_strlen("PatchVersion=");
            __snprintf_chk(gpszVersionString,0x20,1,0x20,&LAB_0025bece_4,com_token + iVar1,local_144
                          );
            gpszVersionString[0x1f] = '\0';
          }
        }
        else {
          iVar1 = Q_strlen("ProductName=");
          iVar1 = Q_strnicmp(com_token,"ProductName=",iVar1);
          if (iVar1 != 0) goto LAB_000b960f;
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
  if (cls.state == ca_dedicated) {
    Con_Printf("Protocol version %i\nExe version %s (%s)\n");
    iVar2 = build_number();
    Con_Printf("Exe build: 01:35:13 Oct  8 2024 (%i)\n",iVar2);
  }
  else {
    Con_DPrintf("Protocol version %i\nExe version %s (%s)\n",0x30,gpszVersionString,
                gpszProductString);
    iVar2 = build_number();
    Con_DPrintf("Exe build: 01:35:13 Oct  8 2024 (%i)\n",iVar2);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Version_f  @ 000ba2a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Version_f(void)

{
  int iVar1;
  
  Con_Printf("Protocol version %i\nExe version %s (%s)\n",0x30,gpszVersionString,gpszProductString);
  iVar1 = build_number();
  Con_Printf("Exe build: 01:35:13 Oct  8 2024 (%i)\n",iVar1);
  return;
}


// Host_Viewframe_f  @ 000bbbd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Viewframe_f(void)

{
  int iVar1;
  model_t *pmVar2;
  char *str;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: edict_t * e@[???]
                       Unresolved local var: int f@[???]
                       Unresolved local var: model_t * m@[???] */
  iVar4 = 0;
  iVar3 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * e@[???] */
  if (0 < sv.num_edicts) {
    do {
      iVar5 = (int)(sv.edicts)->leafnums + iVar3 + -0x18;
      iVar1 = Q_strcmp(pr_strings + *(int *)(iVar5 + 0x80),"viewthing");
      if (iVar1 == 0) {
        if (iVar5 == 0) {
          return;
        }
        pmVar2 = CL_GetModelByIndex(*(int *)(iVar5 + 0x134));
        str = Cmd_Argv(1);
        iVar3 = Q_atoi(str);
        if (pmVar2->numframes <= iVar3) {
          iVar3 = pmVar2->numframes + -1;
        }
        *(float *)(iVar5 + 0x1b0) = (float)iVar3;
        return;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x324;
    } while (iVar4 < sv.num_edicts);
  }
  Con_Printf("No viewthing on map\n");
  return;
}


// Host_Viewmodel_f  @ 000bba00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Viewmodel_f(void)

{
  int iVar1;
  char *pcVar2;
  model_t *pmVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: edict_t * e@[???]
                       Unresolved local var: model_t * m@[???] */
  iVar5 = 0;
  iVar4 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * e@[???] */
  if (0 < sv.num_edicts) {
    do {
      iVar6 = (int)(sv.edicts)->leafnums + iVar4 + -0x18;
      iVar1 = Q_strcmp(pr_strings + *(int *)(iVar6 + 0x80),"viewthing");
      if (iVar1 == 0) {
        if (iVar6 == 0) {
          return;
        }
        pcVar2 = Cmd_Argv(1);
        pmVar3 = Mod_ForName(pcVar2,false,false);
        if (pmVar3 == (model_t *)0x0) {
                    /* Unresolved local var: edict_t * e@[???]
                       Unresolved local var: model_t * m@[???] */
          pcVar2 = Cmd_Argv(1);
          Con_Printf("Can\'t load %s\n",pcVar2);
          return;
        }
        *(undefined4 *)(iVar6 + 0x1b0) = 0;
        cl.model_precache[*(int *)(iVar6 + 0x134)] = pmVar3;
        return;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x324;
    } while (iVar5 < sv.num_edicts);
  }
  Con_Printf("No viewthing on map\n");
  return;
}


// Host_Viewnext_f  @ 000bbc90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Viewnext_f(void)

{
  float fVar1;
  int iVar2;
  model_t *mod;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: edict_t * e@[???]
                       Unresolved local var: model_t * m@[???] */
  iVar5 = 0;
  iVar4 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * e@[???] */
  if (0 < sv.num_edicts) {
    do {
      iVar6 = (int)(sv.edicts)->leafnums + iVar4 + -0x18;
      iVar2 = Q_strcmp(pr_strings + *(int *)(iVar6 + 0x80),"viewthing");
      if (iVar2 == 0) {
        if (iVar6 == 0) {
          return;
        }
        mod = CL_GetModelByIndex(*(int *)(iVar6 + 0x134));
        fVar1 = *(float *)(iVar6 + 0x1b0) + 1.0;
        *(float *)(iVar6 + 0x1b0) = fVar1;
        if ((float)mod->numframes <= fVar1) {
          fVar1 = (float)(mod->numframes + -1);
          *(float *)(iVar6 + 0x1b0) = fVar1;
        }
                    /* Unresolved local var: aliashdr_t * hdr@[???]
                       Unresolved local var: maliasframedesc_t * pframedesc@[???] */
        pvVar3 = Mod_Extradata(mod);
        if (pvVar3 == (void *)0x0) {
          return;
        }
        Con_Printf("frame %i: %s\n",(int)fVar1,(int)pvVar3 + (int)fVar1 * 0x28 + 0xfc);
        return;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x324;
    } while (iVar5 < sv.num_edicts);
  }
  Con_Printf("No viewthing on map\n");
  return;
}


// Host_Viewprev_f  @ 000bbae0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_Viewprev_f(void)

{
  float fVar1;
  int iVar2;
  model_t *mod;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: edict_t * e@[???]
                       Unresolved local var: model_t * m@[???] */
  iVar5 = 0;
  iVar4 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * e@[???] */
  if (0 < sv.num_edicts) {
    do {
      iVar6 = (int)(sv.edicts)->leafnums + iVar4 + -0x18;
      iVar2 = Q_strcmp(pr_strings + *(int *)(iVar6 + 0x80),"viewthing");
      if (iVar2 == 0) {
        if (iVar6 == 0) {
          return;
        }
        mod = CL_GetModelByIndex(*(int *)(iVar6 + 0x134));
        fVar1 = *(float *)(iVar6 + 0x1b0) - 1.0;
        if (fVar1 < 0.0) {
          *(undefined4 *)(iVar6 + 0x1b0) = 0;
          iVar4 = 0;
        }
        else {
          *(float *)(iVar6 + 0x1b0) = fVar1;
          iVar4 = (int)fVar1;
        }
                    /* Unresolved local var: aliashdr_t * hdr@[???]
                       Unresolved local var: maliasframedesc_t * pframedesc@[???] */
        pvVar3 = Mod_Extradata(mod);
        if (pvVar3 == (void *)0x0) {
          return;
        }
        Con_Printf("frame %i: %s\n",iVar4,(int)pvVar3 + iVar4 * 0x28 + 0xfc);
        return;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x324;
    } while (iVar5 < sv.num_edicts);
  }
  Con_Printf("No viewthing on map\n");
  return;
}


// Host_VoiceRecordStart_f  @ 000bb670
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_VoiceRecordStart_f(void)

{
  char *pUncompressedFile;
  char *pMicInputFile;
  char *pDecompressedFile;
  
  if (cls.state == ca_active) {
                    /* Unresolved local var: char * pUncompressedFile@[???]
                       Unresolved local var: char * pDecompressedFile@[???]
                       Unresolved local var: char * pInputFile@[???] */
    pDecompressedFile = "voice_decompressed.wav";
    pUncompressedFile = "voice_micdata.wav";
    if ((int)voice_recordtofile.value == 0) {
      pDecompressedFile = (char *)0x0;
      pUncompressedFile = (char *)0x0;
    }
    pMicInputFile = "voice_input.wav";
    if ((int)voice_inputfromfile.value == 0) {
      pMicInputFile = (char *)0x0;
    }
    Voice_RecordStart(pUncompressedFile,pDecompressedFile,pMicInputFile);
    return;
  }
  return;
}


// Host_VoiceRecordStop_f  @ 000bb6d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_VoiceRecordStop_f(void)

{
  qboolean qVar1;
  
  if (cls.state != ca_active) {
    return;
  }
  qVar1 = Voice_IsRecording();
  if (qVar1 == 0) {
    return;
  }
  CL_AddVoiceToDatagram(true);
  Voice_RecordStop();
  return;
}


// Host_WriteConfiguration  @ 000b73d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_WriteConfiguration(void)

{
  FileHandle_t pvVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: kbutton_t * ml@[???]
                       Unresolved local var: kbutton_t * jl@[???]
                       Unresolved local var: qboolean bSetFileToReadOnly@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pvVar1 = FS_OpenPathID("config.cfg","w","GAMECONFIG");
  if (pvVar1 == (FileHandle_t)0x0) {
    if ((developer.value != 0.0) &&
       (iVar2 = FS_FileExists("../goldsrc/dev_build_all.bat"), iVar2 != 0)) {
                    /* Unresolved local var: bool[4096] nameBuf@[???] */
      FS_GetLocalPath("config.cfg",local_1010,0x1000);
      chmod(local_1010,0x180);
      pvVar1 = FS_OpenPathID("config.cfg","w","GAMECONFIG");
      if (pvVar1 != (FileHandle_t)0x0) {
        FS_FPrintf(pvVar1,
                   "// This file is overwritten whenever you change your user settings in the game.\n"
                  );
        FS_FPrintf(pvVar1,"// Add custom configurations to the file \"userconfig.cfg\".\n\n");
        FS_FPrintf(pvVar1,"unbindall\n");
        Key_WriteBindings(pvVar1);
        Cvar_WriteVariables(pvVar1);
        Info_WriteVars(pvVar1);
        FS_FPrintf(pvVar1,"+mlook\n");
        FS_FPrintf(pvVar1,"+jlook\n");
        FS_FPrintf(pvVar1,"exec controller.cfg\n");
        FS_FPrintf(pvVar1,"exec userconfig.cfg\n");
        FS_Close(pvVar1);
                    /* Unresolved local var: bool[4096] nameBuf@[???] */
        FS_GetLocalPath("config.cfg",local_1010,0x1000);
        chmod(local_1010,0x100);
        goto LAB_000b74a6;
      }
    }
    Con_Printf("Couldn\'t write config.cfg.\n");
  }
  else {
    FS_FPrintf(pvVar1,
               "// This file is overwritten whenever you change your user settings in the game.\n");
    FS_FPrintf(pvVar1,"// Add custom configurations to the file \"userconfig.cfg\".\n\n");
    FS_FPrintf(pvVar1,"unbindall\n");
    Key_WriteBindings(pvVar1);
    Cvar_WriteVariables(pvVar1);
    Info_WriteVars(pvVar1);
    FS_FPrintf(pvVar1,"+mlook\n");
    FS_FPrintf(pvVar1,"+jlook\n");
    FS_FPrintf(pvVar1,"exec controller.cfg\n");
    FS_FPrintf(pvVar1,"exec userconfig.cfg\n");
    FS_Close(pvVar1);
  }
LAB_000b74a6:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_WriteConfiguration  @ 000b7620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_WriteConfiguration(void)

{
  int iVar1;
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: kbutton_t * ml@[???]
                       Unresolved local var: kbutton_t * jl@[???]
                       Unresolved local var: qboolean bSetFileToReadOnly@[???] */
  if ((host_initialized != false) && (cls.state != ca_dedicated)) {
    SetRateRegistrySetting(rate.string);
    iVar1 = Key_CountBindings();
    if (1 < iVar1) {
      Host_WriteConfiguration();
      return;
    }
    Con_Printf("skipping config.cfg output, no keys bound\n");
  }
  return;
}


// Host_WriteCustomConfig  @ 000b7670
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Host_WriteCustomConfig(void)

{
  int iVar1;
  char *pcVar2;
  qboolean qVar3;
  FileHandle_t file;
  kbutton_s *pkVar4;
  kbutton_s *pkVar5;
  int in_GS_OFFSET;
  char local_125 [261];
  int local_20;
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: kbutton_t * ml@[???]
                       Unresolved local var: kbutton_t * jl@[???]
                       Unresolved local var: bool[261] configname@[???]
                       Unresolved local var: char * pchExtension@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = Cmd_Argc();
  if (iVar1 != 1) {
    pcVar2 = Cmd_Args();
    if (pcVar2 != (char *)0x0) {
      pcVar2 = Cmd_Args();
      if (*pcVar2 != '\0') {
        pcVar2 = Cmd_Args();
        snprintf(local_125,0x101,"%s",pcVar2);
        if ((local_125[0] != '\0') && (local_125[0] != '/')) {
          pcVar2 = Q_strstr(local_125,"..");
          if (pcVar2 == (char *)0x0) {
            pcVar2 = Q_strstr(local_125,"\\");
            if (pcVar2 == (char *)0x0) {
              pcVar2 = Q_strstr(local_125,":");
              if (pcVar2 == (char *)0x0) {
                pcVar2 = Q_strstr(local_125,"./");
                if (pcVar2 == (char *)0x0) {
                  if ((host_initialized != false) && (cls.state != ca_dedicated)) {
                    iVar1 = Key_CountBindings();
                    if (iVar1 < 2) {
                      Con_Printf("skipping config.cfg output, no keys bound\n");
                    }
                    else {
                      COM_DefaultExtension(local_125,".cfg");
                      pcVar2 = COM_LastFileExtension(local_125);
                      iVar1 = Q_stricmp(pcVar2,"cfg");
                      if (iVar1 == 0) {
                        iVar1 = Q_stricmp(local_125,"config.cfg");
                        if (iVar1 != 0) {
                          iVar1 = Q_stricmp(local_125,"autoexec.cfg");
                          if (iVar1 != 0) {
                            iVar1 = Q_stricmp(local_125,"listenserver.cfg");
                            if (iVar1 != 0) {
                              iVar1 = Q_stricmp(local_125,"server.cfg");
                              if (iVar1 != 0) {
                                iVar1 = Q_stricmp(local_125,"userconfig.cfg");
                                if (iVar1 != 0) {
                                  iVar1 = Q_stricmp(local_125,"language.cfg");
                                  if (iVar1 != 0) {
                                    iVar1 = Q_stricmp(local_125,"violence.cfg");
                                    if (iVar1 != 0) {
                                      iVar1 = Q_stricmp(local_125,"banned.cfg");
                                      if (iVar1 != 0) {
                                        iVar1 = Q_stricmp(local_125,"listip.cfg");
                                        if (iVar1 != 0) {
                                          iVar1 = Q_stricmp(local_125,"skill.cfg");
                                          if (iVar1 != 0) {
                                            iVar1 = Q_stricmp(local_125,"game.cfg");
                                            if (iVar1 != 0) {
                                              iVar1 = Q_stricmp(local_125,"joystick.cfg");
                                              if (iVar1 != 0) {
                                                qVar3 = Q_striprefix(local_125,"hw/");
                                                if (qVar3 == false) {
                                                  file = FS_OpenPathID(local_125,"w","GAMECONFIG");
                                                  if (file == (FileHandle_t)0x0) {
                                                    Con_Printf("Couldn\'t write %s.\n",local_125);
                                                  }
                                                  else {
                                                    FS_FPrintf(file,"unbindall\n");
                                                    Key_WriteBindings(file);
                                                    Cvar_WriteVariables(file);
                                                    Info_WriteVars(file);
                                                    pkVar4 = ClientDLL_FindKey("in_mlook");
                                                    pkVar5 = ClientDLL_FindKey("in_jlook");
                                                    if ((pkVar4 != (kbutton_s *)0x0) &&
                                                       ((pkVar4->state & 1) != 0)) {
                                                      FS_FPrintf(file,"+mlook\n");
                                                    }
                                                    if ((pkVar5 != (kbutton_s *)0x0) &&
                                                       ((pkVar5->state & 1) != 0)) {
                                                      FS_FPrintf(file,"+jlook\n");
                                                    }
                                                    FS_Close(file);
                                                    Con_Printf("%s successfully created!\n",
                                                               local_125);
                                                  }
                                                  goto LAB_000b76c8;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        Con_Printf("skipping writecfg output, invalid filename %s given\n",local_125
                                  );
                      }
                      else {
                        Con_Printf("skipping writecfg output, invalid filename %s given (wrong file extension, must be .cfg)\n"
                                   ,local_125);
                      }
                    }
                  }
                  goto LAB_000b76c8;
                }
              }
            }
          }
        }
        Con_Printf("skipping writecfg output, invalid filename %s given (invalid characters in filename)\n"
                   ,local_125);
        goto LAB_000b76c8;
      }
    }
  }
  Con_Printf("writecfg: writecfg <filename>\n");
LAB_000b76c8:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


