// Host_AutoSave_f  @ 00071654
void Host_AutoSave_f(void)

{
  int iVar1;
  undefined1 local_a4 [80];
  char local_54 [79];
  undefined1 local_5;
  
  iVar1 = Host_ValidSave();
  if (iVar1 != 0) {
    (*(code *)g_pSaveGameCommentFunc)(local_a4,0x50);
    fmod(DAT_0036bc6c,60.0);
    snprintf(local_54,0x4f,"%-64.64s %02d:%02d");
    local_5 = 0;
    SaveGameSlot("autosave",local_54);
  }
  return;
}


// Host_Changelevel2_f  @ 00074578
void Host_Changelevel2_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcStack_c8;
  char acStack_c4 [63];
  undefined1 uStack_85;
  undefined1 auStack_84 [63];
  undefined1 uStack_45;
  undefined1 auStack_44 [63];
  undefined1 uStack_5;
  
  giActive = 4;
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("changelevel2 <levelname> : continue game on a new level in the unit\n");
  }
  else if (((sv == 0) || (DAT_002fe004 != 0)) || (DAT_0036bc64 != 0)) {
    Con_Printf("Only the server may changelevel\n");
  }
  else if (DAT_00524288 < 2) {
    SCR_BeginLoadingPlaque();
    S_StopAllSounds(1);
    uVar3 = 0x3f;
    uVar2 = Cmd_Argv(1);
    Q_strncpy(auStack_44,uVar2,uVar3);
    uStack_5 = 0;
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      pcStack_c8 = (char *)0x0;
    }
    else {
      uVar3 = 0x3f;
      uVar2 = Cmd_Argv(2);
      Q_strncpy(acStack_c4,uVar2,uVar3);
      uStack_85 = 0;
      if (acStack_c4[0] == '\0') {
        pcStack_c8 = (char *)0x0;
      }
      else {
        pcStack_c8 = acStack_c4;
      }
    }
    Q_strncpy(auStack_84,&DAT_0036bc88,0x3f);
    uStack_45 = 0;
    uVar2 = SaveGamestate();
    SV_ServerShutdown();
    FS_LogLevelLoadStarted(auStack_44);
    iVar1 = SV_SpawnServer(0,auStack_44,pcStack_c8);
    if (iVar1 == 0) {
      Sys_Error("Host_Changelevel2: Couldn\'t load map %s\n",auStack_44);
    }
    else {
      SaveExit(uVar2);
      iVar1 = LoadGamestate(auStack_44,0);
      if (iVar1 == 0) {
        SV_LoadEntities();
      }
      LoadAdjacentEntities(auStack_84,pcStack_c8);
      DAT_0036bc64 = 1;
      DAT_0036bc68 = 1;
      gGlobalVariables = (float)DAT_0036bc6c;
      if ((iVar1 == 0) &&
         ((byte)(0.0 < (float)sv_newunit._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)sv_newunit._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_newunit._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
        Host_ClearSaveDirectory();
      }
      SV_ActivateServer(0);
    }
  }
  else {
    Con_Printf("changelevel2 <levelname> : not for use with multiplayer games\n");
  }
  return;
}


// Host_Changelevel_f  @ 00070410
void Host_Changelevel_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *local_88;
  undefined1 local_84 [63];
  undefined1 local_45;
  undefined1 local_44 [63];
  undefined1 local_5;
  
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("changelevel <levelname> : continue game on a new level\n");
  }
  else if ((sv == 0) || (DAT_002fe004 != 0)) {
    Con_Printf("Only the server may changelevel\n");
  }
  else {
    uVar2 = Cmd_Argv(1);
    iVar1 = PF_IsMapValid_I(uVar2);
    if (iVar1 == 0) {
      uVar2 = Cmd_Argv(1);
      Con_Printf("changelevel failed: \'%s\' not found on server.\n",uVar2);
    }
    else {
      SCR_BeginLoadingPlaque();
      S_StopAllSounds(1);
      uVar3 = 0x3f;
      uVar2 = Cmd_Argv(1);
      Q_strncpy(local_44,uVar2,uVar3);
      local_5 = 0;
      iVar1 = Cmd_Argc();
      if (iVar1 == 2) {
        local_88 = (undefined1 *)0x0;
      }
      else {
        uVar3 = 0x3f;
        uVar2 = Cmd_Argv(2);
        Q_strncpy(local_84,uVar2,uVar3);
        local_45 = 0;
        local_88 = local_84;
      }
      SV_InactivateClients();
      SV_ServerShutdown();
      SV_SpawnServer(0,local_44,local_88);
      SV_LoadEntities();
      SV_ActivateServer(1);
    }
  }
  return;
}


// Host_CheckConnectionFailure  @ 0006d280
void Host_CheckConnectionFailure(void)

{
  if ((cls == 1) &&
     (((giSubState & 4) != 0 ||
      ((byte)(0.0 < (float)console._12_4_ |
              (byte)((ushort)((ushort)NAN((float)console._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)console._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)))) {
    if (0 < frames_138) {
      frames_138 = frames_138 + -1;
      return;
    }
    giActive = 2;
  }
  frames_138 = 5;
  return;
}


// Host_CheckDyanmicStructures  @ 0006b0f8
void Host_CheckDyanmicStructures(void)

{
  int local_c;
  int local_8;
  
  if (DAT_00524284 != 0) {
    local_8 = 0;
    for (local_c = DAT_00524284; (local_8 < DAT_0052428c && (local_c != 0));
        local_c = local_c + 0x4eec) {
      if (*(int *)(local_c + 0x3480) != 0) {
        SV_ClearFrames(local_c + 0x3480);
      }
      local_8 = local_8 + 1;
    }
  }
  return;
}


// Host_ClearClients  @ 0006ac68
void Host_ClearClients(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_64 [5];
  int iStack_50;
  undefined4 *puStack_4c;
  code *pcStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 local_24 [5];
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  uStack_40 = 0x6ac76;
  host_client = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (*(int *)(host_client + 0x3480) != 0) {
      for (local_c = 0; local_c < SV_UPDATE_BACKUP; local_c = local_c + 1) {
        puStack_4c = (undefined4 *)(*(int *)(host_client + 0x3480) + local_c * 0x1810);
        iStack_50 = 0x6ad08;
        local_10 = puStack_4c;
        SV_ClearPacketEntities();
        *local_10 = 0;
        local_10[1] = 0;
        local_10[2] = 0xbf800000;
      }
    }
    if (*(int *)(host_client + 0x20) != 0) {
      puVar2 = (undefined4 *)(host_client + 0x20);
      puVar3 = local_24;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iStack_44 = 0x2414;
      pcStack_48 = (code *)0x0;
      puStack_4c = (undefined4 *)(host_client + 0x1c);
      iStack_50 = 0x6ad6f;
      Q_memset();
      pcStack_48 = SV_GetFragmentSize;
      puStack_4c = &host_client;
      iStack_50 = (host_client - DAT_00524284) * 0x614fb973 >> 2;
      puVar2 = local_24;
      puVar3 = auStack_64;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      Netchan_Setup(1,host_client + 0x1c);
    }
    pcStack_48 = (code *)0x0;
    puStack_4c = (undefined4 *)(host_client + 0x4d30);
    iStack_50 = 0x6ade5;
    COM_ClearCustomizationList();
    host_client = host_client + 0x4eec;
  }
  if (param_1 == 0) {
    host_client = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_0052428c; local_8 = local_8 + 1) {
      puStack_4c = (undefined4 *)(host_client + 0x3480);
      iStack_50 = 0x6ae47;
      SV_ClearFrames();
      host_client = host_client + 0x4eec;
    }
    iStack_44 = DAT_0052428c * 0x4eec;
    pcStack_48 = (code *)0x0;
    puStack_4c = (undefined4 *)DAT_00524284;
    iStack_50 = 0x6ae9c;
    Q_memset();
    uStack_40 = 0x6aea4;
    SV_AllocClientFrames();
  }
  return;
}


// Host_ClearGameState  @ 0007453c
void Host_ClearGameState(void)

{
  S_StopAllSounds(1);
  Host_ClearSaveDirectory();
  (*DAT_0036af78)();
  return;
}


// Host_ClearMemory  @ 0006b17c
void Host_ClearMemory(int param_1)

{
  CM_FreePAS();
  SV_ClearEntities();
  if (param_1 == 0) {
    Con_DPrintf("Clearing memory\n");
  }
  D_FlushCaches();
  Mod_ClearAll();
  if (host_hunklevel != 0) {
    Host_CheckDyanmicStructures();
    Hunk_FreeToLowMark(host_hunklevel);
  }
  DAT_002fd3ac = 0;
  SV_ClearCaches();
  Q_memset(&sv,0,0x4640c);
  CL_ClearClientState();
  SV_ClearClientStates();
  return;
}


// Host_ClearSaveDirectory  @ 00074484
void Host_ClearSaveDirectory(void)

{
  undefined4 uVar1;
  size_t sVar2;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory();
  snprintf(local_108,0x104,"%s",uVar1);
  COM_FixSlashes(local_108);
  FS_CreateDirHierarchy(local_108,0);
  sVar2 = strlen(local_108);
  strncat(local_108,"*.HL?",0x103 - sVar2);
  DirectoryClear(local_108);
  return;
}


// Host_ClientCommands  @ 0006a8e4
void Host_ClientCommands(char *param_1)

{
  char local_408 [1024];
  undefined1 *local_8;
  
  if (*(int *)(host_client + 0x2438) == 0) {
    local_8 = &stack0x00000008;
    vsnprintf(local_408,0x400,param_1,local_8);
    MSG_WriteByte(host_client + 0x74,9);
    MSG_WriteString(host_client + 0x74,local_408);
  }
  return;
}


// Host_ComputeFPS  @ 0006ceac
void Host_ComputeFPS(double param_1)

{
  rolling_fps = param_1 * 0.4 + rolling_fps * 0.6;
  return;
}


// Host_Demos_f  @ 000756fc
void Host_Demos_f(void)

{
  if (cls != 0) {
    if (DAT_002fddfc == -1) {
      DAT_002fddfc = 0;
    }
    CL_Disconnect_f();
    Host_NextDemo();
  }
  return;
}


// Host_EndGame  @ 00069f50
void Host_EndGame(char *param_1)

{
  char local_40c [1024];
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0x00000008;
  vsnprintf(local_40c,0x400,param_1,local_c);
  Con_DPrintf("Host_EndGame: %s\n",local_40c);
  scr_disabled_for_loading = 1;
  local_8 = DAT_002fddfc;
  if (sv != 0) {
    Host_ShutdownServer(0);
  }
  DAT_002fddfc = local_8;
  if (cls == 0) {
    Sys_Error("Host_EndGame: %s\n",local_40c);
  }
  if (DAT_002fddfc != -1) {
    local_8 = DAT_002fddfc;
    CL_Disconnect_f();
    DAT_002fddfc = local_8;
    Host_NextDemo();
                    /* WARNING: Subroutine does not return */
    longjmp((__jmp_buf_tag *)host_enddemo,1);
  }
  scr_disabled_for_loading = 0;
  CL_Disconnect();
  Cbuf_AddText("cd stop\n");
  Cbuf_Execute();
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Host_EndSection  @ 00075794
void Host_EndSection(char *param_1)

{
  int iVar1;
  
  giActive = 2;
  giSubState = 1;
  giStateInfo = 1;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    Con_Printf(" endsection with no arguments\n");
  }
  else {
    iVar1 = Q_stricmp(param_1,"_oem_end_training");
    if (iVar1 == 0) {
      giStateInfo = 1;
    }
    else {
      iVar1 = Q_stricmp(param_1,"_oem_end_logo");
      if (iVar1 == 0) {
        giStateInfo = 2;
      }
      else {
        iVar1 = Q_stricmp(param_1,"_oem_end_demo");
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


// Host_Error  @ 0006a0a8
void Host_Error(char *param_1)

{
  char local_408 [1024];
  undefined1 *local_8;
  
  if (inerror_33 != 0) {
    Sys_Error("Host_Error: recursively entered");
  }
  inerror_33 = 1;
  SCR_EndLoadingPlaque();
  local_8 = &stack0x00000008;
  vsnprintf(local_408,0x400,param_1,local_8);
  if ((sv == 0) &&
     ((byte)(0.0 < (float)developer._12_4_ |
             (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    CL_WriteMessageHistory(0,0);
  }
  Con_Printf("Host_Error: %s\n",local_408);
  if (sv != 0) {
    Host_ShutdownServer(0);
  }
  if (cls == 0) {
    Sys_Error("Host_Error: %s\n",local_408);
  }
  CL_Disconnect();
  DAT_002fddfc = 0xffffffff;
  inerror_33 = 0;
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Host_FilterTime  @ 0006b224
undefined4 Host_FilterTime(float param_1)

{
  int iVar1;
  float local_8;
  
  if (((byte)(0.0 < (float)host_framerate._12_4_ |
              (byte)((ushort)((ushort)NAN((float)host_framerate._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)host_framerate._12_4_ == 0.0) << 0xe) >> 8)) == 1) &&
     ((iVar1 = Host_IsSinglePlayerGame(), iVar1 != 0 || (DAT_002fe004 != 0)))) {
    host_frametime = (double)((float)host_framerate._12_4_ * (float)sys_timescale._12_4_);
    realtime = realtime + host_frametime;
  }
  else {
    realtime = (double)((float)realtime + param_1 * (float)sys_timescale._12_4_);
    if (isDedicated == 0) {
      if ((sv == 0) &&
         ((byte)(0.0 < (float)fps_modem._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)fps_modem._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)fps_modem._12_4_ == 0.0) << 0xe) >> 8)) == 1)) {
        local_8 = (float)fps_modem._12_4_;
      }
      else {
        local_8 = (float)fps_max._12_4_;
      }
      if (((sv == 0) && (cls != 1)) && (cls != 5)) {
        local_8 = 30.0;
      }
      if (local_8 < 0.5) {
        local_8 = 0.5;
      }
      if (((byte)((byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) &&
         ((byte)(100.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 100.0) << 0xe) >> 8)) == 1)) {
        local_8 = 100.0;
      }
      if ((1 < (int)cl._1717472_4_) && (local_8 < 20.0)) {
        local_8 = 20.0;
      }
      if ((DAT_002fe008 == 0) &&
         (realtime - oldrealtime < (double)(float)sys_timescale._12_4_ / (double)local_8)) {
        return 0;
      }
    }
    else if (((byte)(0.0 < (float)sys_ticrate._12_4_ |
                     (byte)((ushort)((ushort)NAN((float)sys_ticrate._12_4_) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)sys_ticrate._12_4_ == 0.0) << 0xe) >> 8)) == 1)
            && (realtime - oldrealtime < 1.0 / ((double)(float)sys_ticrate._12_4_ + 1.0))) {
      return 0;
    }
    host_frametime = realtime - oldrealtime;
    oldrealtime = realtime;
    if ((byte)(0.25 < host_frametime | (byte)((ushort)((ushort)NAN(host_frametime) << 10) >> 8) |
              (byte)((ushort)((ushort)(host_frametime == 0.25) << 0xe) >> 8)) == 1) {
      host_frametime = 0.25;
    }
    else if (host_frametime < 0.001) {
      host_frametime = 0.001;
    }
  }
  return 1;
}


// Host_FindRecentSave  @ 0007058c
char * Host_FindRecentSave(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_21c [260];
  int local_118;
  int local_114;
  int local_110;
  undefined1 local_10c [260];
  int local_8;
  
  uVar1 = Host_SaveGameDirectory();
  sprintf(param_1,"%s*.sav",uVar1);
  uVar1 = Host_SaveGameDirectory();
  snprintf(local_21c,0x104,"%s",uVar1);
  local_8 = Sys_FindFirst(param_1,local_10c);
  local_110 = 0;
  while (local_8 != 0) {
    iVar2 = Q_strlen(local_8);
    if ((iVar2 != 0) && (iVar2 = Q_strcasecmp(local_8,"HLSave.sav"), iVar2 != 0)) {
      uVar1 = Host_SaveGameDirectory(local_8);
      snprintf(local_21c,0x104,"%s%s",uVar1);
      local_118 = FS_GetFileTime(local_21c);
      if ((0 < local_118) && ((local_110 == 0 || (local_114 < local_118)))) {
        local_114 = local_118;
        Q_strcpy(param_1,local_8);
        local_110 = 1;
      }
    }
    local_8 = Sys_FindNext(local_10c);
  }
  Sys_FindClose();
  if (local_110 == 0) {
    param_1 = (char *)0x0;
  }
  return param_1;
}


// Host_Frame  @ 0006d59c
int Host_Frame(undefined4 param_1,int param_2,int *param_3)

{
  double dVar1;
  double dVar2;
  int iVar3;
  longdouble lVar4;
  int local_1c;
  int local_18;
  double local_14;
  double local_c;
  
  iVar3 = __sigsetjmp(host_abortserver,0);
  if (iVar3 == 0) {
    if ((giActive != 3) || (g_iQuitCommandIssued == 0)) {
      giActive = param_2;
    }
    *param_3 = 0;
    if ((byte)(0.0 < (float)host_profile._12_4_ |
               (byte)((ushort)((ushort)NAN((float)host_profile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)host_profile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      lVar4 = (longdouble)Sys_FloatTime();
      local_c = (double)lVar4;
    }
    _Host_Frame(param_1);
    if ((byte)(0.0 < (float)host_profile._12_4_ |
               (byte)((ushort)((ushort)NAN((float)host_profile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)host_profile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      lVar4 = (longdouble)Sys_FloatTime();
      local_14 = (double)lVar4;
    }
    if (giStateInfo != 0) {
      *param_3 = giStateInfo;
      giStateInfo = 0;
      Cbuf_Execute();
    }
    if ((byte)(0.0 < (float)host_profile._12_4_ |
               (byte)((ushort)((ushort)NAN((float)host_profile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)host_profile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      timetotal_146 = timetotal_146 + (local_14 - local_c);
      timecount_147 = timecount_147 + 1;
      if (999 < timecount_147) {
        dVar1 = timetotal_146 * 1000.0;
        dVar2 = (double)timecount_147;
        timecount_147 = 0;
        timetotal_146 = 0.0;
        local_1c = 0;
        for (local_18 = 0; local_18 < DAT_00524288; local_18 = local_18 + 1) {
          if (*(int *)(DAT_00524284 + local_18 * 0x4eec) != 0) {
            local_1c = local_1c + 1;
          }
        }
        Con_Printf("host_profile: %2i clients %2i msec\n",local_1c,(int)ROUND(dVar1 / dVar2));
      }
    }
  }
  return giActive;
}


// Host_FullInfo_f  @ 00074860
void Host_FullInfo_f(void)

{
  int iVar1;
  char *local_40c;
  char *local_408;
  char local_404 [512];
  char local_204 [512];
  
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("fullinfo <complete info string>\n");
    FUN_00074a34();
    return;
  }
  local_40c = (char *)Cmd_Argv(1);
  if (*local_40c == '\\') {
    local_40c = local_40c + 1;
  }
  if (*local_40c != '\0') {
    local_408 = local_204;
    for (; (*local_40c != '\0' && (*local_40c != '\\')); local_40c = local_40c + 1) {
      *local_408 = *local_40c;
      local_408 = local_408 + 1;
    }
    *local_408 = '\0';
    if (*local_40c != '\0') {
      local_408 = local_404;
      while ((local_40c = local_40c + 1, *local_40c != '\0' && (*local_40c != '\\'))) {
        *local_408 = *local_40c;
        local_408 = local_408 + 1;
      }
      FUN_0007499c();
      return;
    }
    Con_Printf("MISSING VALUE\n");
    FUN_00074a34();
    return;
  }
  FUN_00074a34();
  return;
}


// Host_GetBatchModList_f  @ 00075ba4
void Host_GetBatchModList_f(void)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  undefined4 *puVar4;
  char *apcStackY_d4 [3];
  int iStackY_c8;
  char *pcStackY_c4;
  undefined4 uStackY_c0;
  int local_88;
  char local_84 [128];
  
  uStackY_c0 = 0x75bd0;
  NET_Config();
  if ((gfNoMasterServer == 0) && (valvemaster_adr != 0)) {
    uStackY_c0 = 0x75c0d;
    snprintf(local_84,0x80,"%c\r\nstart-of-list\r\n");
    for (local_88 = valvemaster_adr; local_88 != 0; local_88 = *(int *)(local_88 + 0x2c)) {
      puVar2 = (undefined4 *)(local_88 + 0x18);
      ppcVar3 = apcStackY_d4;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar3 = (char *)*puVar2;
        puVar2 = puVar2 + 1;
        ppcVar3 = ppcVar3 + 1;
      }
      NET_AdrToString();
      uStackY_c0 = 0x75c65;
      Con_Printf();
      puVar2 = (undefined4 *)(local_88 + 0x18);
      puVar4 = &uStackY_c0;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
      }
      pcStackY_c4 = local_84;
      apcStackY_d4[0] = local_84;
      iStackY_c8 = Q_strlen();
      iStackY_c8 = iStackY_c8 + 1;
      apcStackY_d4[2] = (char *)0x0;
      apcStackY_d4[1] = (char *)0x75c9e;
      NET_SendPacket();
    }
  }
  return;
}


// Host_GetHostInfo  @ 0006cee4
void Host_GetHostInfo(float *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                     undefined1 *param_5)

{
  undefined4 local_8;
  
  local_8 = 0;
  if (0.0 < rolling_fps) {
    *param_1 = 1.0 / (float)rolling_fps;
  }
  else {
    rolling_fps._0_4_ = 0;
    rolling_fps._4_4_ = 0;
    *param_1 = 0.0;
  }
  SV_CountPlayers(&local_8);
  *param_2 = local_8;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (param_5 != (undefined1 *)0x0) {
    if (DAT_0036bc88 == '\0') {
      *param_5 = 0;
    }
    else {
      Q_strcpy(param_5,&DAT_0036bc88);
    }
  }
  *param_4 = DAT_00524288;
  return;
}


// Host_GetStartTime  @ 0006e808
undefined4 Host_GetStartTime(void)

{
  return startTime;
}


// Host_Getcertificate_f  @ 00075cc8
void Host_Getcertificate_f(void)

{
  int iVar1;
  
  Con_Printf("Trying to authenticate with WON servers\n");
  iVar1 = (*(code *)crypt._60_4_)();
  if (iVar1 == 0) {
    Con_Printf("Failed to authenticate\n");
  }
  else {
    Con_Printf("WON Authentication successful\n");
  }
  return;
}


// Host_Init  @ 0006dc84
undefined4 Host_Init(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_c;
  
  _LogFunctionTrace("Host_Init",0);
  puVar2 = param_1;
  puVar3 = &host_parms;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  com_argc = param_1[2];
  com_argv = param_1[3];
  realtime._0_4_ = 0;
  realtime._4_4_ = 0;
  Memory_Init(param_1[4],param_1[5]);
  Voice_RegisterCvars();
  Cvar_RegisterVariable(console);
  iVar1 = COM_CheckParm("-console");
  if (((iVar1 != 0) || (iVar1 = COM_CheckParm("-toconsole"), iVar1 != 0)) ||
     (iVar1 = COM_CheckParm(&DAT_000e33c4), iVar1 != 0)) {
    Cvar_DirectSet(console,&DAT_000e2a52);
  }
  Host_InitLocal();
  iVar1 = COM_CheckParm(&DAT_000e33c4);
  if (iVar1 != 0) {
    Cvar_SetValue("developer",0x3f800000);
  }
  Cbuf_Init();
  Cmd_Init();
  Cvar_Init();
  Cvar_CmdInit();
  V_Init();
  Chase_Init();
  COM_Init(*param_1);
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
  Con_DPrintf("%4.1f Mb heap\n",(double)(int)param_1[5] / 1048576.0);
  R_InitTextures();
  HPAK_CheckIntegrity("custom");
  Q_memset(g_module,0,0x14);
  if (cls == 0) {
    Cvar_RegisterVariable(suitvolume);
  }
  else {
    iVar1 = COM_LoadHunkFile("gfx/palette.lmp");
    if (iVar1 == 0) {
      Sys_Error("Host_Init: Couldn\'t load gfx/palette.lmp");
    }
    host_basepal = Hunk_AllocName(0x800,"palette.lmp");
    for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
      *(short *)(host_basepal + local_c * 8) = (short)*(char *)(local_c * 3 + iVar1 + 2);
      *(short *)(host_basepal + local_c * 8 + 2) = (short)*(char *)(local_c * 3 + iVar1 + 1);
      *(short *)(host_basepal + local_c * 8 + 4) = (short)*(char *)(iVar1 + local_c * 3);
      *(undefined2 *)(local_c * 8 + host_basepal + 6) = 0;
    }
    CL_InitEventSystem();
    ClientDLL_Init();
    iVar1 = VID_Init(host_basepal);
    if (iVar1 == 0) {
      return 0;
    }
    Draw_Init();
    SCR_Init();
    R_Init();
    S_Init();
    CL_Init();
  }
  Cbuf_InsertText("exec valve.rc\n");
  iVar1 = COM_CheckParm("-steam");
  if (iVar1 == 0) {
    WON_InitAuthentication();
  }
  Hunk_AllocName(0,"-HOST_HUNKLEVEL-");
  host_hunklevel = Hunk_LowMark();
  giActive = 1;
  scr_skipupdate = 0;
  CheckGore();
  host_initialized = 1;
  return 1;
}


// Host_InitCommands  @ 00075d3c
void Host_InitCommands(void)

{
  int iVar1;
  
  iVar1 = COM_CheckParm("-steam");
  if (iVar1 == 0) {
    Cmd_AddCommand("getcertificate",Host_Getcertificate_f);
  }
  Cmd_AddCommand("bgetmod",Host_GetBatchModList_f);
  Cmd_AddCommand("shutdownserver",Host_KillServer_f);
  Cmd_AddCommand("soundfade",Host_Soundfade_f);
  Cmd_AddCommand("status",Host_Status_f);
  Cmd_AddCommand(&UNK_000e4616,Host_Status_Formatted_f);
  Cmd_AddCommand(&UNK_000e461b,Host_Quit_f);
  Cmd_AddCommand("_restart",Host_Quit_Restart_f);
  Cmd_AddCommand(&UNK_000e4629,Host_Quit_f);
  Cmd_AddCommand(&UNK_000e462e,Host_Map_f);
  Cmd_AddCommand(&UNK_000e4632,Host_Maps_f);
  Cmd_AddCommand("restart",Host_Restart_f);
  Cmd_AddCommand("reload",Host_Reload_f);
  Cmd_AddCommand("changelevel",Host_Changelevel_f);
  Cmd_AddCommand("changelevel2",Host_Changelevel2_f);
  Cmd_AddCommand("reconnect",Host_Reconnect_f);
  Cmd_AddCommand("version",Host_Version_f);
  Cmd_AddCommand(&UNK_000e4671,Host_Say_f);
  Cmd_AddCommand("say_team",Host_Say_Team_f);
  Cmd_AddCommand(&UNK_000e467e,Host_Tell_f);
  Cmd_AddCommand(&UNK_000e4683,Host_Kill_f);
  Cmd_AddCommand("pause",Host_TogglePause_f);
  Cmd_AddCommand("setpause",Host_Pause_f);
  Cmd_AddCommand("unpause",Host_Unpause_f);
  Cmd_AddCommand(&UNK_000e469f,Host_Kick_f);
  Cmd_AddCommand(&DAT_000e3936,Host_Ping_f);
  Cmd_AddCommand(&UNK_000e46a4,Host_Motd_f);
  Cmd_AddCommand("motd_write",Host_Motd_Write_f);
  Cmd_AddCommand("stats",Host_Stats_f);
  Cmd_AddCommand(&UNK_000e46ba,Host_Loadgame_f);
  Cmd_AddCommand(&UNK_000e46bf,Host_Savegame_f);
  Cmd_AddCommand("autosave",Host_AutoSave_f);
  Cmd_AddCommand("writecfg",Host_WriteCustomConfig);
  Cmd_AddCommand("startdemos",Host_Startdemos_f);
  Cmd_AddCommand("demos",Host_Demos_f);
  Cmd_AddCommand("stopdemo",Host_Stopdemo_f);
  Cmd_AddCommand("setinfo",Host_SetInfo_f);
  Cmd_AddCommand("fullinfo",Host_FullInfo_f);
  Cmd_AddCommand("mcache",Mod_Print);
  Cmd_AddCommand("interp",Host_Interp_f);
  Cmd_AddCommand("setmaster",Master_SetMaster_f);
  Cmd_AddCommand("heartbeat",Master_Heartbeat_f);
  Cvar_RegisterVariable(gHostMap);
  Cvar_RegisterVariable(voice_recordtofile);
  Cvar_RegisterVariable(voice_inputfromfile);
  return;
}


// Host_InitLocal  @ 0006a1d8
void Host_InitLocal(void)

{
  Host_InitCommands();
  Cvar_RegisterVariable(host_killtime);
  Cvar_RegisterVariable(sys_ticrate);
  Cvar_RegisterVariable(fps_max);
  Cvar_RegisterVariable(fps_modem);
  Cvar_RegisterVariable(host_name);
  Cvar_RegisterVariable(host_limitlocal);
  sys_timescale._12_4_ = 0x3f800000;
  Cvar_RegisterVariable(host_framerate);
  Cvar_RegisterVariable(host_speeds);
  Cvar_RegisterVariable(host_profile);
  Cvar_RegisterVariable(mp_logfile);
  Cvar_RegisterVariable(mp_logecho);
  Cvar_RegisterVariable(sv_log_onefile);
  Cvar_RegisterVariable(sv_log_singleplayer);
  Cvar_RegisterVariable(sv_stats);
  Cvar_RegisterVariable(developer);
  Cvar_RegisterVariable(deathmatch);
  Cvar_RegisterVariable(coop);
  Cvar_RegisterVariable(pausable);
  Cvar_RegisterVariable(fs_preloader);
  Cvar_RegisterVariable(skill);
  SV_SetMaxclients();
  return;
}


// Host_InitializeGameDLL  @ 0006e388
void Host_InitializeGameDLL(void)

{
  int iVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  
  local_10 = 0x2d;
  local_f = 0x69;
  local_e = 0x6e;
  local_d = 0x73;
  local_c = 0x65;
  local_b = 99;
  local_a = 0x75;
  local_9 = 0x72;
  local_8 = 0x65;
  local_7 = 0;
  Cbuf_Execute();
  NET_Config(1 < DAT_00524288);
  if (svs == 0) {
    svs = 1;
    LoadEntityDLLs(host_parms);
    iVar1 = COM_CheckParm(&local_10);
    if (((iVar1 == 0) && (isDedicated != 0)) && (DAT_0036ae94 != 0)) {
      SV_DownloadingModules();
    }
    (*gEntityInterface)();
    (*DAT_0036afcc)(g_svmove);
    (*DAT_0036afe4)();
    SV_InitEncoders();
    SV_DownloadSecurityModules();
    SV_GetPlayerHulls();
    SV_CheckBlendingInterface();
    SV_CheckSaveGameCommentInterface();
    Cbuf_Execute();
    iVar1 = COM_CheckParm(&local_10);
    if (((iVar1 == 0) && (isDedicated != 0)) && (DAT_0036ae94 != 0)) {
      if (DAT_00524368 == 0) {
        SV_ServerNotSecure();
      }
      else {
        SV_ServerSecure();
      }
    }
  }
  else {
    Con_DPrintf("Sys_InitializeGameDLL called twice, skipping second call\n");
  }
  return;
}


// Host_Interp_f  @ 0007540c
void Host_Interp_f(void)

{
  r_dointerp = (uint)(r_dointerp == 0);
  if (r_dointerp == 0) {
    Con_Printf("Frame Interpolation OFF\n");
  }
  else {
    Con_Printf("Frame Interpolation ON\n");
  }
  return;
}


// Host_IsServerActive  @ 0006d908
undefined4 Host_IsServerActive(void)

{
  return sv;
}


// Host_IsSinglePlayerGame  @ 0006d8b4
bool Host_IsSinglePlayerGame(void)

{
  int iVar1;
  
  iVar1 = DAT_00524288;
  if (sv == 0) {
    iVar1 = cl._1717472_4_;
  }
  return iVar1 == 1;
}


// Host_Kick_f  @ 000aaeb8
void Host_Kick_f(void)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_5c [63];
  undefined1 local_1d;
  int local_1c;
  int local_18;
  char *local_14;
  int local_10;
  char *local_c;
  char *local_8;
  
  local_c = (char *)0x0;
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("usage:  kick < name > | < # userid >\n");
    return;
  }
  if (cmd_source == 1) {
    if (sv == 0) {
      Cmd_ForwardToServer();
      return;
    }
  }
  else if (*(int *)((int)host_client + 0x20) != 1) {
    SV_ClientPrintf("You can\'t \'kick\' because you are not a server operator\n");
    return;
  }
  local_10 = (int)host_client;
  local_14 = (char *)Cmd_Argv(1);
  if ((local_14 == (char *)0x0) || (*local_14 != '#')) {
    host_client = DAT_00524284;
    for (local_18 = 0; local_18 < DAT_00524288; local_18 = local_18 + 1) {
      if ((*host_client != 0) || (host_client[3] != 0)) {
        uVar4 = Cmd_Argv(1);
        iVar1 = Q_strcasecmp(host_client + 0x12fb,uVar4);
        if (iVar1 == 0) break;
      }
      host_client = host_client + 0x13bb;
    }
    local_1c = 0;
    goto LAB_000ab1c7;
  }
  pcVar5 = local_14 + 1;
  if (local_14[1] == ' ') {
    pcVar5 = local_14 + 2;
  }
  local_14 = pcVar5;
  iVar1 = atoi(local_14);
  strncpy(local_5c,local_14,0x3f);
  local_1d = 0;
  sVar2 = strlen("STEAM_");
  iVar3 = Q_strnicmp(local_5c,"STEAM_",sVar2);
  if (iVar3 == 0) {
LAB_000ab020:
    uVar4 = Cmd_Argv(3);
    snprintf(local_5c,0x3f,"%s:%s",local_14,uVar4);
    local_1d = 0;
  }
  else {
    sVar2 = strlen("VALVE_");
    iVar3 = Q_strnicmp(local_5c,"VALVE_",sVar2);
    if (iVar3 == 0) goto LAB_000ab020;
  }
  host_client = DAT_00524284;
  for (local_18 = 0; local_18 < DAT_00524288; local_18 = local_18 + 1) {
    if ((((*host_client != 0) || (host_client[3] != 0)) || (host_client[1] != 0)) &&
       (host_client[0x90e] == 0)) {
      if ((iVar1 != 0) && (host_client[0x12a3] == iVar1)) break;
      pcVar5 = local_5c;
      uVar4 = SV_GetClientIDString(host_client);
      iVar3 = Q_stricmp(uVar4,pcVar5);
      if (iVar3 == 0) break;
    }
    host_client = host_client + 0x13bb;
  }
  local_1c = 1;
LAB_000ab1c7:
  if (local_18 < DAT_00524288) {
    if (cmd_source == 1) {
      local_8 = "Console";
    }
    else {
      local_8 = (char *)(local_10 + 0x4bec);
    }
    if (host_client[8] == 1) {
      Con_Printf(FUN_000ea900);
      return;
    }
    iVar1 = Cmd_Argc();
    if (2 < iVar1) {
      uVar4 = Cmd_Args();
      local_c = (char *)COM_Parse(uVar4);
      if (local_1c != 0) {
        do {
          local_c = local_c + 1;
        } while (*local_c == ' ');
        iVar1 = Q_strlen(local_5c);
        iVar3 = Q_strlen("STEAM_");
        local_c = local_c + (iVar1 - iVar3) + -1;
      }
      for (; (*local_c != '\0' && (*local_c == ' ')); local_c = local_c + 1) {
      }
    }
    if (local_c == (char *)0x0) {
      SV_ClientPrintf("Kicked by %s\n",local_8);
      pcVar5 = local_8;
      uVar4 = SV_GetClientIDString(host_client);
      Log_Printf("Kick: \"%s<%i><%s><>\" was kicked by \"%s\"\n",host_client + 0x12fb,
                 host_client[0x12a3],uVar4,pcVar5);
    }
    else {
      SV_ClientPrintf("Kicked by %s: %s\n",local_8,local_c);
      pcVar5 = local_8;
      pcVar6 = local_c;
      uVar4 = SV_GetClientIDString(host_client);
      Log_Printf("Kick: \"%s<%i><%s><>\" was kicked by \"%s\" (message \"%s\")\n",
                 host_client + 0x12fb,host_client[0x12a3],uVar4,pcVar5,pcVar6);
    }
    SV_DropClient(host_client,0,"Kicked");
  }
  host_client = (int *)local_10;
  return;
}


// Host_KillServer_f  @ 00075a30
void Host_KillServer_f(void)

{
  if (cls == 0) {
    if (sv != 0) {
      Host_ShutdownServer(0);
    }
    if (cls != 0) {
      NET_Config(0);
    }
  }
  else {
    CL_Disconnect_f();
  }
  return;
}


// Host_KillVoice_f  @ 00074a40
void Host_KillVoice_f(void)

{
  Voice_Deinit();
  return;
}


// Host_Kill_f  @ 00075120
void Host_Kill_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (0.0 < *(float *)(sv_player + 0x1e0)) {
    gGlobalVariables = (float)DAT_0036bc6c;
    (*DAT_0036af84)(sv_player);
  }
  else {
    SV_ClientPrintf("Can\'t suicide -- already dead!\n");
  }
  return;
}


// Host_Load  @ 00071b68
undefined4 Host_Load(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_18c [8];
  char *local_184;
  int local_180;
  char local_17c [256];
  undefined1 local_7c [112];
  undefined4 local_c;
  int local_8;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uVar1 = 0;
  }
  else {
    if (*param_1 == '_') {
      for (local_180 = 0;
          ((local_184 = param_1 + 1, *local_184 != '\0' &&
           ((*(ushort *)(__ctype_b + *local_184 * 2) & 0x800) != 0)) && (local_180 < 5));
          local_180 = local_180 + 1) {
        local_18c[local_180] = *local_184;
        param_1 = local_184;
      }
      local_18c[local_180] = '\0';
      iVar2 = Q_atoi(local_18c);
      if ((iVar2 < 1) || (0xc < iVar2)) {
        return 0;
      }
      uVar1 = Host_SaveGameDirectory(iVar2);
      snprintf(local_17c,0xfc,"%sHalf-Life-%i",uVar1);
    }
    else {
      uVar1 = Host_SaveGameDirectory(param_1);
      snprintf(local_17c,0xfc,"%s%s",uVar1);
    }
    if (svs == 0) {
      Host_InitializeGameDLL();
    }
    COM_DefaultExtension(local_17c,&DAT_000e3e63);
    COM_FixSlashes(local_17c);
    Con_Printf("Loading game from %s...\n",local_17c);
    local_8 = FS_Open(local_17c,&DAT_000e363a);
    if (local_8 == 0) {
      uVar1 = 0;
    }
    else {
      Host_ClearGameState();
      iVar2 = SaveReadHeader(local_8,local_7c,1);
      if (iVar2 == 0) {
        giStateInfo = 1;
        Cbuf_AddText("\ndisconnect\n");
        uVar1 = 0;
      }
      else {
        DAT_002fddfc = 0xffffffff;
        SV_InactivateClients();
        SCR_BeginLoadingPlaque();
        DirectoryExtract(local_8,local_c);
        FS_Close(local_8);
        Cvar_SetValue("deathmatch",0);
        Cvar_SetValue(&DAT_000e3f39,0);
        snprintf(local_17c,0x100,"map %s\n",local_7c);
        CL_Disconnect();
        Host_Map(0,local_17c,local_7c,1);
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


// Host_Loadgame_f  @ 00071a90
void Host_Loadgame_f(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (cmd_source == 1) {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      uVar2 = Cmd_Argv(1);
      iVar1 = Host_Load(uVar2);
      if (iVar1 == 0) {
        Con_Printf("Error loading saved game\n");
      }
    }
    else {
      Con_Printf("load <savename> : load a game\n");
    }
  }
  return;
}


// Host_Map  @ 0006fd30
void Host_Map(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  size_t sVar2;
  char *__src;
  int local_8;
  
  Host_ShutdownServer(0);
  key_dest = 0;
  SCR_BeginLoadingPlaque();
  if (param_4 == 0) {
    Host_ClearGameState();
    SV_InactivateClients();
    DAT_00524294 = 0;
  }
  Q_strncpy(&DAT_002fd4b4,param_2,0x3f);
  DAT_002fd4f3 = 0;
  iVar1 = SV_SpawnServer(param_1,param_3,0);
  if (iVar1 != 0) {
    ContinueLoadingProgressBar("Server",7,0);
    if (param_4 == 0) {
      SV_LoadEntities();
      SV_ActivateServer(1);
      if (sv == 0) {
        return;
      }
      if (cls != 0) {
        Q_strcpy(&DAT_002fd4f4,&DAT_000e39dd);
        for (local_8 = 2; iVar1 = Cmd_Argc(), local_8 < iVar1; local_8 = local_8 + 1) {
          sVar2 = strlen(&DAT_002fd4f4);
          sVar2 = 0x7ff - sVar2;
          __src = (char *)Cmd_Argv(local_8);
          strncat(&DAT_002fd4f4,__src,sVar2);
          sVar2 = strlen(&DAT_002fd4f4);
          strncat(&DAT_002fd4f4," ",0x7ff - sVar2);
        }
      }
    }
    else {
      iVar1 = LoadGamestate(param_3,1);
      if (iVar1 == 0) {
        SV_LoadEntities();
      }
      DAT_0036bc64 = 1;
      DAT_0036bc68 = 1;
      SV_ActivateServer(0);
    }
    if (sv_gpNewUserMsgs != 0) {
      if (sv_gpUserMsgs == 0) {
        sv_gpUserMsgs = sv_gpNewUserMsgs;
      }
      else {
        for (local_8 = sv_gpUserMsgs; *(int *)(local_8 + 0x18) != 0;
            local_8 = *(int *)(local_8 + 0x18)) {
        }
        *(int *)(local_8 + 0x18) = sv_gpNewUserMsgs;
      }
      sv_gpNewUserMsgs = 0;
    }
    if (cls != 0) {
      Cmd_ExecuteString("connect local",1);
    }
  }
  return;
}


// Host_Map_f  @ 0006ffd4
void Host_Map_f(void)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  char *__src;
  undefined4 uVar4;
  undefined1 auStack_8c [4];
  undefined1 local_88 [63];
  undefined1 local_49;
  char local_48 [64];
  int local_8;
  
  if (cmd_source == 1) {
    iVar1 = Cmd_Argc();
    if (1 < iVar1) {
      uVar2 = Cmd_Args();
      iVar1 = Q_strlen(uVar2);
      if (0x36 < iVar1) {
        Con_Printf("map change failed: command string is too long.\n");
        return;
      }
    }
    CL_Disconnect();
    iVar1 = COM_CheckParm("-steam");
    if ((iVar1 != 0) && (iVar1 = PF_IsDedicatedServer(), iVar1 != 0)) {
      g_bMajorMapChange = 1;
    }
    FS_LogLevelLoadStarted("Map_Common");
    local_48[0] = '\0';
    local_8 = 0;
    while (iVar1 = Cmd_Argc(), local_8 < iVar1) {
      sVar3 = strlen(local_48);
      sVar3 = 0x3e - sVar3;
      __src = (char *)Cmd_Argv(local_8);
      strncat(local_48,__src,sVar3);
      sVar3 = strlen(local_48);
      strncat(local_48," ",0x3e - sVar3);
      local_8 = local_8 + 1;
    }
    Q_strcat(local_48,&DAT_000e3921);
    uVar4 = 0x3f;
    uVar2 = Cmd_Argv(1);
    Q_strncpy(local_88,uVar2,uVar4);
    local_49 = 0;
    if (svs == 0) {
      Host_InitializeGameDLL();
    }
    local_8 = Q_strlen(local_88);
    if ((4 < local_8) && (iVar1 = Q_strcasecmp(auStack_8c + local_8,&DAT_000e3a62), iVar1 == 0)) {
      auStack_8c[local_8] = 0;
    }
    FS_LogLevelLoadStarted(local_88);
    SCR_UpdateScreen();
    SCR_UpdateScreen();
    iVar1 = PF_IsMapValid_I(local_88);
    if (iVar1 == 0) {
      Con_Printf("map change failed: \'%s\' not found on server.\n",local_88);
      iVar1 = COM_CheckParm("-steam");
      if ((iVar1 != 0) && (iVar1 = PF_IsDedicatedServer(), iVar1 != 0)) {
        g_bMajorMapChange = 0;
        Sys_Printf(&DAT_000e3921);
      }
    }
    else {
      StartLoadingProgressBar("Server",0x17);
      SetLoadingProgressBarStatusText("#GameUI_StartingServer");
      ContinueLoadingProgressBar("Server",1,0);
      if ((1 < DAT_00524288) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
        COM_CheckAuthenticationType();
      }
      Cvar_Set("HostMap",local_88);
      Host_Map(0,local_48,local_88,0);
      iVar1 = COM_CheckParm("-steam");
      if ((iVar1 != 0) && (iVar1 = PF_IsDedicatedServer(), iVar1 != 0)) {
        g_bMajorMapChange = 0;
        Sys_Printf(&DAT_000e3921);
      }
      ContinueLoadingProgressBar("Server",0xb,0);
      NotifyDedicatedServerUI("UpdateMap");
    }
  }
  return;
}


// Host_Maps_f  @ 00070384
void Host_Maps_f(void)

{
  int iVar1;
  char *local_8;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    local_8 = (char *)Cmd_Argv(1);
    if ((local_8 != (char *)0x0) && (*local_8 != '\0')) {
      if (*local_8 == '*') {
        local_8 = (char *)0x0;
      }
      COM_ListMaps(local_8);
    }
  }
  else {
    Con_Printf("Usage:  maps <substring>\nmaps * for full listing\n");
  }
  return;
}


// Host_Motd_Write_f  @ 0006e684
void Host_Motd_Write_f(void)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  uint local_808;
  char local_804 [2048];
  
  iVar1 = FS_Open(motdfile._4_4_,&DAT_000e365a);
  if (iVar1 == 0) {
    Con_Printf("Unable to open %s\n",motdfile._4_4_);
  }
  else {
    uVar2 = Cmd_Args(0x800);
    Q_strncpy(local_804,uVar2);
    local_808 = 0;
    while( true ) {
      sVar3 = strlen(local_804);
      if (sVar3 <= local_808) break;
      if ((local_804[local_808] == '\\') && (local_804[local_808 + 1] == 'n')) {
        local_804[local_808] = '\n';
        strcpy(local_804 + local_808 + 1,local_804 + local_808 + 2);
      }
      local_808 = local_808 + 1;
    }
    uVar2 = 1;
    iVar4 = iVar1;
    sVar3 = strlen(local_804);
    FS_Write(local_804,sVar3,uVar2,iVar4);
    FS_Close(iVar1);
    Con_Printf("Done.\n");
  }
  return;
}


// Host_Motd_f  @ 0006e50c
void Host_Motd_f(void)

{
  int iVar1;
  int iVar2;
  char *__ptr;
  char *pcVar3;
  char *local_18;
  
  iVar1 = FS_Open(motdfile._4_4_,&DAT_000e363a);
  if (iVar1 == 0) {
    Con_Printf("Unable to open %s\n",motdfile._4_4_);
  }
  else {
    iVar2 = FS_Size(iVar1);
    if (iVar2 != 0) {
      __ptr = malloc(iVar2 + 1);
      if (__ptr != (char *)0x0) {
        FS_Read(__ptr,iVar2,1,iVar1);
        __ptr[iVar2] = '\0';
        Con_Printf("motd:");
        local_18 = __ptr;
        while( true ) {
          pcVar3 = strchr(local_18,10);
          if (pcVar3 == (char *)0x0) break;
          pcVar3 = strchr(local_18,10);
          *pcVar3 = '\0';
          Con_Printf(&DAT_000e3656,local_18);
          local_18 = pcVar3 + 1;
        }
        if (local_18 != (char *)0x0) {
          Con_Printf(&DAT_000e3656,local_18);
        }
        free(__ptr);
      }
    }
    FS_Close(iVar1);
  }
  return;
}


// Host_NextDemo  @ 00075474
void Host_NextDemo(void)

{
  char acStack_404 [1024];
  
  if (DAT_002fddfc != -1) {
    SCR_BeginLoadingPlaque();
    if (((&DAT_002fde00)[DAT_002fddfc * 0x10] != '\0') && (DAT_002fddfc != 0x20)) {
      FUN_00075544();
      return;
    }
    DAT_002fddfc = 0;
    if (DAT_002fde00 == '\0') {
      scr_disabled_for_loading = 0;
      Con_Printf("No demos listed with startdemos\n");
      DAT_002fddfc = -1;
    }
    else {
      snprintf(acStack_404,0x400,"playdemo %s\n",&DAT_002fde00);
      Cbuf_InsertText(acStack_404);
      DAT_002fddfc = DAT_002fddfc + 1;
    }
  }
  return;
}


// Host_Pause_f  @ 000752c4
void Host_Pause_f(void)

{
  if (cl[0x1a34b8] != '\0') {
    if (cmd_source == 1) {
      Cmd_ForwardToServer();
    }
    else if ((byte)((byte)((ushort)((ushort)NAN((float)pausable._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)pausable._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      DAT_0036bc64 = 1;
      MSG_WriteByte(&DAT_003a887c,0x18);
      MSG_WriteByte(&DAT_003a887c,DAT_0036bc64);
    }
  }
  return;
}


// Host_Ping_f  @ 0006fc80
void Host_Ping_f(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *local_c;
  int local_8;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    SV_ClientPrintf("Client ping times:\n");
    local_c = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if (*local_c != 0) {
        piVar2 = local_c + 0x12fb;
        uVar1 = SV_CalcPing(local_c);
        SV_ClientPrintf("%4i %s\n",uVar1,piVar2);
      }
      local_c = local_c + 0x13bb;
    }
  }
  return;
}


// Host_Quit_Restart_f  @ 0006ed8c
void Host_Quit_Restart_f(void)

{
  giActive = 5;
  giStateInfo = 4;
  if ((((sv == 0) && (cls == 5)) && (DAT_002fd388 != '\0')) &&
     (g_pPostRestartCmdLineArgs != (char *)0x0)) {
    strcat(g_pPostRestartCmdLineArgs," +connect ");
    strcat(g_pPostRestartCmdLineArgs,&DAT_002fd3b0);
  }
  return;
}


// Host_Quit_f  @ 0006ed10
void Host_Quit_f(void)

{
  int iVar1;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    giActive = 3;
    g_iQuitCommandIssued = 1;
    if (cls != 0) {
      CL_Disconnect();
    }
    Host_ShutdownServer(0);
    Sys_Quit();
  }
  else {
    giActive = 2;
    giStateInfo = 4;
  }
  return;
}


// Host_Reconnect_f  @ 000708c0
void Host_Reconnect_f(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_bc [4];
  char local_84 [128];
  
  if (((cls != 0) && (cls != 1)) && (cls != 2)) {
    if (DAT_002fe32c == 0) {
      SCR_BeginLoadingPlaque();
      DAT_002fd3ac = 0;
      cls = 3;
      sys_timescale._12_4_ = 0x3f800000;
      auStackY_bc[3] = 0x709a8;
      Netchan_Clear();
      auStackY_bc[3] = 0x709bd;
      SZ_Clear();
      auStackY_bc[3] = 0x709d4;
      MSG_WriteChar();
      auStackY_bc[3] = 0x709f2;
      MSG_WriteString();
    }
    else {
      puVar2 = &DAT_002fe318;
      puVar3 = auStackY_bc;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      NET_AdrToString();
      auStackY_bc[3] = 0x70951;
      snprintf(local_84,0x80,"listen %s\n");
      auStackY_bc[3] = 0x70960;
      Cbuf_AddText();
    }
  }
  return;
}


// Host_Reload_f  @ 000707f8
void Host_Reload_f(void)

{
  int iVar1;
  undefined1 local_10c [260];
  int local_8;
  
  if (((DAT_002fe004 == 0) && (sv != 0)) && (cmd_source == 1)) {
    Host_ClearGameState();
    SV_InactivateClients();
    SV_ServerShutdown();
    local_8 = Host_FindRecentSave(local_10c);
    if ((local_8 == 0) || (iVar1 = Host_Load(local_8), iVar1 == 0)) {
      SV_SpawnServer(0,gHostMap._4_4_,0);
      SV_LoadEntities();
      SV_ActivateServer(1);
    }
  }
  return;
}


// Host_Restart_f  @ 0007072c
void Host_Restart_f(void)

{
  undefined1 local_108 [259];
  undefined1 local_5;
  
  if (((DAT_002fe004 == 0) && (sv != 0)) && (cmd_source == 1)) {
    if (cls != 0) {
      cls = 1;
    }
    Host_ClearGameState();
    SV_InactivateClients();
    Q_strncpy(local_108,&DAT_0036bc88,0x103);
    local_5 = 0;
    SV_ServerShutdown();
    SV_SpawnServer(0,local_108,0);
    SV_LoadEntities();
    SV_ActivateServer(1);
  }
  return;
}


// Host_SaveAgeList  @ 00070bb8
void Host_SaveAgeList(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  char local_20c [260];
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory(param_1,param_2);
  snprintf(local_108,0x104,"%s%s%02d.sav",uVar1);
  COM_FixSlashes(local_108);
  FS_RemoveFile(local_108,0);
  for (; 0 < param_2; param_2 = param_2 + -1) {
    if (param_2 == 1) {
      uVar1 = Host_SaveGameDirectory(param_1);
      snprintf(local_20c,0x104,"%s%s.sav",uVar1);
    }
    else {
      uVar1 = Host_SaveGameDirectory(param_1,param_2 + -1);
      snprintf(local_20c,0x104,"%s%s%02d.sav",uVar1);
    }
    COM_FixSlashes(local_20c);
    uVar1 = Host_SaveGameDirectory(param_1,param_2);
    snprintf(local_108,0x104,"%s%s%02d.sav",uVar1);
    COM_FixSlashes(local_108);
    rename(local_20c,local_108);
  }
  return;
}


// Host_SaveGameDirectory  @ 00070a04
undefined1 * Host_SaveGameDirectory(void)

{
  Q_memset(szDirectory_73,0,0x104);
  snprintf(szDirectory_73,0x104,"SAVE/");
  return szDirectory_73;
}


// Host_SavegameComment  @ 00070a68
void Host_SavegameComment(char *param_1,int param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_10;
  char *local_8;
  
  local_8 = (char *)0x0;
  pcVar1 = (char *)(DAT_0036b22c + pr_strings);
  local_10 = 0;
  while ((local_10 < 0x1b && (local_8 == (char *)0x0))) {
    uVar2 = Q_strlen(*(undefined4 *)(gTitleComments + local_10 * 8));
    iVar3 = Q_strnicmp(pcVar1,*(undefined4 *)(gTitleComments + local_10 * 8),uVar2);
    if (iVar3 == 0) {
      local_8 = *(char **)(gTitleComments + local_10 * 8 + 4);
    }
    local_10 = local_10 + 1;
  }
  if ((local_8 == (char *)0x0) &&
     (((local_8 = pcVar1, pcVar1 == (char *)0x0 || (*pcVar1 == '\0')) &&
      (iVar3 = Q_strlen(0x2eded8), iVar3 != 0)))) {
    local_8 = cl + 0x1a34b8;
  }
  strncpy(param_1,local_8,param_2 - 1);
  param_1[param_2 + -1] = '\0';
  return;
}


// Host_Savegame_f  @ 0007164c
void Host_Savegame_f(void)

{
  return;
}


// Host_Say  @ 00074b68
void Host_Say(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  char *pcVar4;
  char local_94 [128];
  char *local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  if (cls == 0) {
    iVar1 = Cmd_Argc();
    if ((1 < iVar1) && (local_14 = (char *)Cmd_Args(), local_14 != (char *)0x0)) {
      local_c = host_client;
      if (*local_14 == '\"') {
        local_14 = local_14 + 1;
        iVar1 = Q_strlen(local_14);
        local_14[iVar1 + -1] = '\0';
      }
      uVar2 = Cvar_VariableString("hostname");
      snprintf(local_94,0x80,"%c<%s> ",1,uVar2);
      iVar1 = Q_strlen(local_14);
      if (0x3f < iVar1) {
        local_14[0x3f] = '\0';
      }
      local_10 = Q_strlen(local_94);
      local_10 = 0x7e - local_10;
      iVar1 = Q_strlen(local_14);
      if (local_10 < iVar1) {
        local_14[local_10] = '\0';
      }
      Q_strcat(local_94,local_14);
      puVar3 = &DAT_000e3921;
      pcVar4 = local_94;
      Q_strcat(pcVar4,&DAT_000e3921);
      local_8 = DAT_00524284;
      for (local_10 = 0; local_10 < DAT_00524288; local_10 = local_10 + 1) {
        if ((((local_8 != (int *)0x0) && (*local_8 != 0)) && (local_8[1] != 0)) &&
           (local_8[0x90e] == 0)) {
          host_client = local_8;
          puVar3 = (undefined *)
                   RegUserMsg("SayText",0xffffffff,pcVar4,puVar3,0,
                              DAT_003a78b8 + local_10 * 0x324 + 0x324);
          PF_MessageBegin_I(1);
          PF_WriteByte_I(0);
          pcVar4 = local_94;
          PF_WriteString_I();
          PF_MessageEnd_I();
        }
        local_8 = local_8 + 0x13bb;
      }
      FUN_00074dd0();
      return;
    }
  }
  else if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  return;
}


// Host_Say_Team_f  @ 00074e48
void Host_Say_Team_f(void)

{
  Host_Say(1);
  return;
}


// Host_Say_f  @ 00074e20
void Host_Say_f(void)

{
  Host_Say(0);
  return;
}


// Host_SetInfo_f  @ 00074a60
void Host_SetInfo_f(void)

{
  FUN_00074a6c();
  return;
}


// Host_Shutdown  @ 0006e0d0
void Host_Shutdown(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  _LogFunctionTrace("Host_Shutdown",0);
  if (isdown_166 == 0) {
    isdown_166 = 1;
    if (host_initialized != 0) {
      Host_WriteConfiguration();
    }
    SV_ServerShutdown();
    host_initialized = 0;
    CloseSecurityModule();
    Cmd_RemoveGameCmds();
    Cmd_Shutdown();
    Cvar_Shutdown();
    HPAK_FlushHostQueue();
    SV_DeallocateDynamicData();
    local_c = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_0052428c; local_8 = local_8 + 1) {
      SV_ClearFrames(local_c + 0x3480);
      local_c = local_c + 0x4eec;
    }
    SV_Shutdown();
    SystemWrapper_ShutDown();
    Master_Shutdown(1);
    scr_disabled_for_loading = 1;
    NET_Shutdown();
    S_Shutdown();
    Con_Shutdown();
    ReleaseEntityDlls();
    CL_ShutDownClientStatic();
    CM_FreePAS();
    if (wadpath != 0) {
      Mem_Free(wadpath);
      wadpath = 0;
    }
    if (cls != 0) {
      Draw_Shutdown();
    }
    Draw_DecalShutdown();
    W_Shutdown();
    iVar1 = COM_CheckParm("-steam");
    if (iVar1 == 0) {
      WON_ShutdownAuthentication();
    }
    Log_Printf("Server shutdown\n");
    Log_Close();
    COM_Shutdown();
    CL_Shutdown();
    DELTA_Shutdown();
    if (cls == 0) {
      iVar1 = COM_CheckParm("-steam");
      if (iVar1 == 0) {
        (*(code *)crypt._12_4_)();
      }
    }
    realtime._0_4_ = 0;
    realtime._4_4_ = 0;
    DAT_0036bc6c._0_4_ = 0;
    DAT_0036bc6c._4_4_ = 0;
    cl._176020_4_ = 0;
    cl._176024_4_ = 0;
  }
  else {
    printf("recursive shutdown\n");
  }
  return;
}


// Host_ShutdownServer  @ 0006aeb0
void Host_ShutdownServer(undefined4 param_1)

{
  int local_8;
  
  if (sv != 0) {
    SV_ServerShutdown();
    sv = 0;
    NET_ClearLagData(1,1);
    host_client = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if ((*host_client != 0) || (host_client[3] != 0)) {
        SV_DropClient(host_client,param_1,"Server shutting down");
      }
      host_client = host_client + 0x13bb;
    }
    CL_Disconnect();
    SV_ClearEntities();
    SV_ClearCaches();
    FreeAllEntPrivateData();
    Q_memset(&sv,0,0x4640c);
    CL_ClearClientState();
    SV_ClearClientStates();
    Host_ClearClients(0);
    host_client = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_0052428c; local_8 = local_8 + 1) {
      SV_ClearFrames(host_client + 0xd20);
      host_client = host_client + 0x13bb;
    }
    Q_memset(DAT_00524284,0,DAT_0052428c * 0x4eec);
    Master_Shutdown(0);
    HPAK_FlushHostQueue();
    Log_Printf("Server shutdown\n");
    Log_Close();
  }
  return;
}


// Host_Soundfade_f  @ 000758ac
void Host_Soundfade_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  iVar1 = Cmd_Argc();
  if ((iVar1 != 3) && (iVar1 = Cmd_Argc(), iVar1 != 5)) {
    Con_Printf("soundfade <percent> <hold> [<out> <int>]\n");
    return;
  }
  uVar2 = Cmd_Argv(1);
  iVar1 = Q_atoi(uVar2);
  if (100 < iVar1) {
    iVar1 = 100;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  uVar2 = Cmd_Argv(2);
  iStack_10 = Q_atoi(uVar2);
  if (0xff < iStack_10) {
    iStack_10 = 0xff;
  }
  iStack_c = 0;
  iStack_14 = 0;
  iVar3 = Cmd_Argc();
  if (iVar3 == 5) {
    uVar2 = Cmd_Argv(3);
    iStack_14 = Q_atoi(uVar2);
    if (0xff < iStack_14) {
      iStack_14 = 0xff;
    }
    uVar2 = Cmd_Argv(4);
    iStack_c = Q_atoi(uVar2);
    if (0xff < iStack_c) {
      iStack_c = 0xff;
    }
  }
  iRam002fe1f0 = iStack_c;
  iRam002fe1ec = iStack_10;
  iRam002fe1e8 = iStack_14;
  uRam002fe1e0 = realtime;
  iRam002fe1d8 = iVar1;
  return;
}


// Host_Speeds  @ 0006cfc4
void Host_Speeds(double *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int local_44;
  int local_40;
  
  fVar1 = (float)((longdouble)1000.0 * ((longdouble)param_1[1] - (longdouble)*param_1));
  fVar2 = (float)((longdouble)1000.0 * ((longdouble)param_1[2] - (longdouble)param_1[1]));
  fVar3 = (float)((longdouble)1000.0 * ((longdouble)param_1[3] - (longdouble)param_1[2]));
  fVar4 = (float)((longdouble)1000.0 * ((longdouble)param_1[4] - (longdouble)param_1[3]));
  fVar5 = (float)((longdouble)1000.0 * ((longdouble)param_1[5] - (longdouble)param_1[4]));
  fVar6 = (fVar1 + fVar2 + fVar3 + fVar4 + fVar5) / 1000.0;
  if (0.0001 <= fVar6) {
    fVar6 = 1.0 / fVar6;
  }
  else {
    fVar6 = 999.0;
  }
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    local_40 = 0;
    for (local_44 = 0; local_44 < DAT_003a78b0; local_44 = local_44 + 1) {
      if (*(int *)(DAT_003a78b8 + local_44 * 0x324) == 0) {
        local_40 = local_40 + 1;
      }
    }
    Con_Printf("%3i fps -- host(%3.0f) sv(%3.0f) cl(%3.0f) gfx(%3.0f) snd(%3.0f) ents(%d)\n",
               (int)ROUND(fVar6),(double)fVar1,(double)fVar2,(double)fVar3,(double)fVar4,
               (double)fVar5,local_40);
  }
  return;
}


// Host_Startdemos_f  @ 000755ac
void Host_Startdemos_f(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iStack_c;
  int iStack_8;
  
  if (cls == 0) {
    if (sv == 0) {
      Con_Printf("Cannot play demos on a dedicated server.\n");
    }
    return;
  }
  iStack_c = Cmd_Argc();
  iStack_c = iStack_c + -1;
  if (0x20 < iStack_c) {
    Con_Printf("Max %i demos in demoloop\n",0x20);
    iStack_c = 0x20;
  }
  Con_Printf("%i demo(s) in loop\n",iStack_c);
  for (iStack_8 = 1; iStack_8 < iStack_c + 1; iStack_8 = iStack_8 + 1) {
    uVar2 = 0xf;
    uVar1 = Cmd_Argv(iStack_8);
    Q_strncpy(iStack_8 * 0x10 + 0x2fddf0,uVar1,uVar2);
    *(undefined1 *)((iStack_8 + -1) * 0x10 + 0x2fde0f) = 0;
  }
  FUN_000756a4();
  return;
}


// Host_Stats_f  @ 0006ecbc
void Host_Stats_f(void)

{
  undefined1 local_204 [512];
  
  GetStatsString(local_204,0x200);
  Con_Printf("CPU   In    Out   Uptime  Users   FPS    Players\n%s\n",local_204);
  return;
}


// Host_Status_Formatted_f  @ 0006f638
void Host_Status_Formatted_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  char local_148 [260];
  char local_44 [32];
  int local_24;
  undefined4 local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_14 = 0;
  local_20 = 0;
  local_24 = 1;
  if (cmd_source == 1) {
    if (sv == 0) {
      Cmd_ForwardToServer();
      return;
    }
  }
  else {
    local_24 = 0;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    Cmd_Argv();
    iVar1 = Q_strcasecmp();
    if (iVar1 == 0) {
      snprintf(local_148,0x104,"%s");
      unlink(local_148);
      local_20 = 1;
    }
  }
  Cvar_VariableString();
  Host_Status_Printf();
  build_number();
  Host_Status_Printf();
  if (noip == 0) {
    puVar3 = &net_local_adr;
    puVar5 = (undefined4 *)&stack0xfffffe64;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    NET_AdrToString();
    Host_Status_Printf();
  }
  Host_Status_Printf();
  SV_CountPlayers();
  Host_Status_Printf();
  Host_Status_Printf(local_24,local_20,
                     "%-2.2s\t%-9.9s\t%-7.7s\t%-20.20s\t%-4.4s\t%-8.8s\t%-4.4s\t%-4.4s\t%-21.21s\n",
                     &DAT_000e3966);
  local_8 = DAT_00524284;
  for (local_18 = 0; local_18 < DAT_00524288; local_18 = local_18 + 1) {
    if (*local_8 != 0) {
      local_14 = 0;
      local_c = (int)ROUND((float)realtime - (float)local_8[0xf]);
      local_10 = local_c / 0x3c;
      if (local_10 != 0) {
        local_c = local_c % 0x3c;
        local_14 = local_10 / 0x3c;
        if (local_14 != 0) {
          local_10 = local_10 % 0x3c;
        }
      }
      if (local_14 == 0) {
        snprintf(local_44,0x20,"%02i:%02i");
      }
      else {
        snprintf(local_44,0x20,"%-2i:%02i:%02i");
      }
      if (local_24 != 0) {
        piVar4 = local_8 + 8;
        piVar6 = (int *)&stack0xfffffe64;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar6 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar6 = piVar6 + 1;
        }
        NET_AdrToString();
      }
      va();
      SV_CalcPing();
      va();
      va();
      SV_GetClientIDString(local_8);
      va(&DAT_000e39e3,local_8[0x12a3]);
      va(&DAT_000e38b5,local_8 + 0x12fb);
      uVar2 = va(&DAT_000e39e8,local_18 + 1);
      Host_Status_Printf(local_24,local_20,
                         "%-2.2s\t%-9.9s\t%-7.7s\t%-20.20s\t%-4.4s\t%-8.8s\t%-4.4s\t%-4.4s\t%-21.21s\n"
                         ,uVar2);
    }
    local_8 = local_8 + 0x13bb;
  }
  Host_Status_Printf();
  return;
}


// Host_Status_Printf  @ 0006ee2c
void Host_Status_Printf(int param_1,int param_2,char *param_3)

{
  char local_110c [260];
  undefined1 *local_1008;
  char local_1004 [4096];
  
  local_1008 = &stack0x00000010;
  vsnprintf(local_1004,0x1000,param_3,local_1008);
  if (param_1 == 0) {
    SV_ClientPrintf(&DAT_000e37a0,local_1004);
  }
  else {
    Con_Printf(&DAT_000e37a0,local_1004);
  }
  if (param_2 != 0) {
    snprintf(local_110c,0x104,"%s","status.log");
    COM_Log(local_110c,&DAT_000e37a0,local_1004);
  }
  return;
}


// Host_Status_f  @ 0006ef04
void Host_Status_f(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int **ppiVar4;
  int *apiStackY_18c [4];
  char local_138 [260];
  int *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = (int *)0x1;
  if (cmd_source == 1) {
    if (sv == 0) {
      Cmd_ForwardToServer();
      return;
    }
  }
  else {
    local_34 = (int *)0x0;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    apiStackY_18c[1] = (int *)0x1;
    apiStackY_18c[0] = (int *)0x6ef95;
    Cmd_Argv();
    apiStackY_18c[3] = (int *)0x6efa0;
    iVar1 = Q_strcasecmp();
    if (iVar1 == 0) {
      apiStackY_18c[3] = (int *)0x6efcc;
      snprintf(local_138,0x104,"%s");
      apiStackY_18c[3] = (int *)0x6efde;
      unlink(local_138);
      local_30 = 1;
    }
  }
  apiStackY_18c[3] = (int *)0x6eff9;
  Cvar_VariableString();
  apiStackY_18c[3] = (int *)0x6f015;
  Host_Status_Printf();
  build_number();
  apiStackY_18c[3] = (int *)0x2e;
  apiStackY_18c[2] = (int *)0xe37da;
  apiStackY_18c[1] = (int *)local_30;
  apiStackY_18c[0] = local_34;
  Host_Status_Printf();
  if (noip == 0) {
    puVar2 = &net_local_adr;
    ppiVar4 = apiStackY_18c;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppiVar4 = (int *)*puVar2;
      puVar2 = puVar2 + 1;
      ppiVar4 = ppiVar4 + 1;
    }
    NET_AdrToString();
    apiStackY_18c[3] = (int *)0x6f0ad;
    Host_Status_Printf();
  }
  apiStackY_18c[3] = (int *)&DAT_0036bc88;
  apiStackY_18c[2] = (int *)0xe3820;
  apiStackY_18c[1] = (int *)local_30;
  apiStackY_18c[0] = local_34;
  Host_Status_Printf();
  apiStackY_18c[3] = (int *)0x6f192;
  SV_CountPlayers();
  apiStackY_18c[3] = (int *)local_2c;
  apiStackY_18c[2] = (int *)0xe3860;
  apiStackY_18c[1] = (int *)local_30;
  apiStackY_18c[0] = local_34;
  Host_Status_Printf();
  apiStackY_18c[3] = (int *)0x6f1d8;
  Host_Status_Printf();
  local_8 = DAT_00524284;
  for (local_28 = 0; local_28 < DAT_00524288; local_28 = local_28 + 1) {
    if (*local_8 != 0) {
      local_24 = 0;
      local_c = (int)ROUND((float)realtime - (float)local_8[0xf]);
      local_10 = local_c / 0x3c;
      if (local_10 != 0) {
        local_c = local_c % 0x3c;
        local_24 = local_10 / 0x3c;
        if (local_24 != 0) {
          local_10 = local_10 % 0x3c;
        }
      }
      apiStackY_18c[3] = local_8;
      apiStackY_18c[2] = (int *)0x6f302;
      SV_GetClientIDString();
      apiStackY_18c[2] = local_8 + 0x12fb;
      apiStackY_18c[1] = (int *)&DAT_000e38b5;
      apiStackY_18c[0] = (int *)0x6f32c;
      va();
      apiStackY_18c[3] = (int *)(local_28 + 1);
      apiStackY_18c[2] = (int *)0xe38ba;
      apiStackY_18c[1] = (int *)local_30;
      apiStackY_18c[0] = local_34;
      Host_Status_Printf();
      if (local_8[0x90f] == 0) {
        apiStackY_18c[3] = (int *)0x6f4bf;
        Host_Status_Printf();
      }
      else {
        apiStackY_18c[3] = (int *)0x6f37a;
        local_20 = Info_ValueForKey();
        apiStackY_18c[3] = (int *)0x6f38c;
        iVar1 = Q_strlen();
        if (iVar1 != 0) {
          apiStackY_18c[3] = (int *)0x6f3a1;
          local_18 = Q_atoi();
        }
        apiStackY_18c[3] = (int *)0x6f3c3;
        local_20 = Info_ValueForKey();
        apiStackY_18c[3] = (int *)0x6f3d5;
        iVar1 = Q_strlen();
        if (iVar1 != 0) {
          apiStackY_18c[3] = (int *)0x6f3ea;
          local_14 = Q_atoi();
        }
        apiStackY_18c[3] = (int *)0x6f40c;
        local_20 = Info_ValueForKey();
        apiStackY_18c[3] = (int *)0x6f41e;
        iVar1 = Q_strlen();
        if (iVar1 != 0) {
          apiStackY_18c[3] = (int *)0x6f433;
          local_1c = Q_atoi();
        }
        apiStackY_18c[3] = (int *)local_18;
        apiStackY_18c[2] = (int *)0xe38de;
        apiStackY_18c[1] = (int *)local_30;
        apiStackY_18c[0] = local_34;
        Host_Status_Printf();
      }
      if (local_24 == 0) {
        apiStackY_18c[3] = (int *)local_10;
        apiStackY_18c[2] = (int *)0xe3907;
        apiStackY_18c[1] = (int *)local_30;
        apiStackY_18c[0] = local_34;
        Host_Status_Printf();
      }
      else {
        apiStackY_18c[3] = (int *)local_24;
        apiStackY_18c[2] = (int *)0xe38f8;
        apiStackY_18c[1] = (int *)local_30;
        apiStackY_18c[0] = local_34;
        Host_Status_Printf();
      }
      if (local_8[0x90f] == 0) {
        apiStackY_18c[0] = local_8;
        apiStackY_18c[3] = (int *)SV_CalcPing();
        apiStackY_18c[2] = (int *)0xe3912;
        apiStackY_18c[1] = (int *)local_30;
        apiStackY_18c[0] = local_34;
        Host_Status_Printf();
      }
      if ((local_34 == (int *)0x0) && (local_8[0x90f] == 0)) {
        apiStackY_18c[3] = (int *)0x6f5f9;
        Host_Status_Printf();
      }
      else {
        piVar3 = local_8 + 8;
        ppiVar4 = apiStackY_18c;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *ppiVar4 = (int *)*piVar3;
          piVar3 = piVar3 + 1;
          ppiVar4 = ppiVar4 + 1;
        }
        NET_AdrToString();
        apiStackY_18c[3] = (int *)0x6f5db;
        Host_Status_Printf();
      }
    }
    local_8 = local_8 + 0x13bb;
  }
  apiStackY_18c[3] = (int *)0x6f626;
  Host_Status_Printf();
  return;
}


// Host_Stopdemo_f  @ 0007574c
void Host_Stopdemo_f(void)

{
  if ((cls != 0) && (DAT_002fe004 != 0)) {
    CL_StopPlayback();
    CL_Disconnect();
  }
  return;
}


// Host_Tell_f  @ 00074e70
void Host_Tell_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  char acStack_54 [64];
  char *pcStack_14;
  int iStack_10;
  int iStack_c;
  int *piStack_8;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    iVar1 = Cmd_Argc();
    if ((2 < iVar1) && (pcStack_14 = (char *)Cmd_Args(), pcStack_14 != (char *)0x0)) {
      snprintf(acStack_54,0x40,"%s TELL: ",(int)host_client + 0x4bec);
      if (*pcStack_14 == '\"') {
        pcStack_14 = pcStack_14 + 1;
        iVar1 = Q_strlen(pcStack_14);
        pcStack_14[iVar1 + -1] = '\0';
      }
      iStack_10 = Q_strlen(acStack_54);
      iStack_10 = 0x3e - iStack_10;
      iVar1 = Q_strlen(pcStack_14);
      if (iStack_10 < iVar1) {
        pcStack_14[iStack_10] = '\0';
      }
      uVar2 = Cmd_Argv(1);
      iVar1 = Q_strstr(pcStack_14,uVar2);
      if (iVar1 == 0) {
        Q_strcat(acStack_54,pcStack_14);
      }
      else {
        uVar2 = Cmd_Argv(1);
        iVar3 = Q_strlen(uVar2);
        Q_strcat(acStack_54,iVar3 + iVar1);
      }
      Q_strcat(acStack_54,&DAT_000e3921);
      iStack_c = (int)host_client;
      iStack_10 = 0;
      piStack_8 = DAT_00524284;
      if (DAT_00524288 < 1) {
        FUN_0007510c();
        return;
      }
      if ((*DAT_00524284 == 0) || (DAT_00524284[1] == 0)) {
        FUN_000750fc();
        return;
      }
      if (DAT_00524284[0x90e] != 0) {
        FUN_000750fc();
        return;
      }
      uVar2 = Cmd_Argv(1);
      piVar4 = piStack_8 + 0x12fb;
      iVar1 = Q_strcasecmp(piVar4,uVar2);
      if (iVar1 == 0) {
        host_client = piStack_8;
        uVar2 = RegUserMsg("SayText",0xffffffff,piVar4,uVar2,0,
                           DAT_003a78b8 + iStack_10 * 0x324 + 0x324);
        PF_MessageBegin_I(1,uVar2);
        PF_WriteByte_I(0);
        PF_WriteString_I(acStack_54);
        PF_MessageEnd_I();
        FUN_0007510c();
        return;
      }
      FUN_000750fc();
      return;
    }
  }
  return;
}


// Host_TogglePause_f  @ 000751ac
void Host_TogglePause_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if ((byte)((byte)((ushort)((ushort)NAN((float)pausable._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)pausable._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
    SV_ClientPrintf("Pause not allowed.\n");
  }
  else {
    DAT_0036bc64 = DAT_0036bc64 ^ 1;
    if (DAT_0036bc64 == 0) {
      SV_BroadcastPrintf("%s unpaused the game\n",pr_strings + *(int *)(sv_player + 0x250));
    }
    else {
      SV_BroadcastPrintf("%s paused the game\n",pr_strings + *(int *)(sv_player + 0x250));
    }
    MSG_WriteByte(&DAT_003a887c,0x18);
    MSG_WriteByte(&DAT_003a887c,DAT_0036bc64);
  }
  return;
}


// Host_Unpause_f  @ 00075368
void Host_Unpause_f(void)

{
  if (cl[0x1a34b8] != '\0') {
    if (cmd_source == 1) {
      Cmd_ForwardToServer();
    }
    else if ((byte)((byte)((ushort)((ushort)NAN((float)pausable._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)pausable._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      DAT_0036bc64 = 0;
      MSG_WriteByte(&DAT_003a887c,0x18);
      MSG_WriteByte(&DAT_003a887c,DAT_0036bc64);
    }
  }
  return;
}


// Host_UpdateScreen  @ 0006d18c
void Host_UpdateScreen(void)

{
  if (((gfBackground == 0) && (SCR_UpdateScreen(), cl_inmovie != 0)) &&
     ((byte)((byte)((ushort)((ushort)NAN(scr_con_current) << 10) >> 8) |
            (byte)((ushort)((ushort)(scr_con_current == 0.0) << 0xe) >> 8)) == 0x40)) {
    VID_WriteBuffer(0);
  }
  return;
}


// Host_UpdateSounds  @ 0006d1e8
void Host_UpdateSounds(void)

{
  if (gfBackground == 0) {
    if (DAT_002fd3ac == 2) {
      S_Update(r_soundOrigin,vpn,vright,vup);
    }
    else {
      S_Update(&vec3_origin,&vec3_origin,&vec3_origin,&vec3_origin);
    }
    S_PrintStats();
  }
  return;
}


// Host_UpdateStats  @ 0006e82c
void Host_UpdateStats(void)

{
  int iVar1;
  __pid_t _Var2;
  FILE *__stream;
  ushort in_FPUControlWord;
  longdouble lVar3;
  longdouble lVar4;
  int local_1074;
  int local_1070;
  int local_106c;
  time_t local_1068;
  char local_1064 [4100];
  undefined1 local_60 [4];
  sysinfo local_5c;
  int local_c;
  ushort local_8;
  
  if (startTime == 0) {
    lVar3 = (longdouble)Sys_FloatTime();
    local_8 = in_FPUControlWord | 0xc00;
    startTime = (int)ROUND(lVar3);
  }
  lVar3 = (longdouble)Sys_FloatTime();
  lVar4 = (longdouble)last_18 + (longdouble)1;
  if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 1) {
    local_1068 = time((time_t *)0x0);
    sysinfo(&local_5c);
    _Var2 = getpid();
    snprintf(local_1064,0xfff,"/proc/%i/stat",_Var2);
    __stream = fopen(local_1064,"r");
    if (__stream == (FILE *)0x0) {
      Con_Printf("Unable to open %s\n",local_1064);
    }
    else {
      fscanf(__stream,
             "%d %s %c %d %d %d %d %d %lu %lu \t\t\t%lu %lu %lu %ld %ld %ld %ld %ld %ld %lu \t\t\t%lu %ld %lu %lu %lu %lu %lu %lu %lu %lu \t\t\t%lu %lu %lu %lu %lu %lu"
             ,local_60,local_1064,local_60,local_60,local_60,local_60,local_60,local_60,local_60,
             local_60,local_60,local_60,local_60,&local_106c,&local_1070,local_60,local_60,local_60,
             local_60,local_60,&local_1074,local_60,local_60,local_60,local_60,local_60,local_60,
             local_60,local_60,local_60,local_60,local_60,local_60,local_60,local_60,local_60);
      fclose(__stream);
      local_1074 = local_5c.uptime * 100 - local_1074;
      local_106c = local_106c + local_1070;
      if (lastcputicks_20 == 0) {
        lastcputicks_20 = local_106c;
      }
      iVar1 = local_1074;
      if (lastrunticks_19 != 0) {
        local_c = local_1074 - lastrunticks_19;
        cpuPercent = (double)(local_106c - lastcputicks_20) / (double)local_c;
        iVar1 = lastrunticks_19;
      }
      lastrunticks_19 = iVar1;
      lVar3 = (longdouble)Sys_FloatTime();
      lVar4 = (longdouble)lastAvg_21 + (longdouble)5.0;
      if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 1) {
        lastrunticks_19 = local_1074;
        lastcputicks_20 = local_106c;
        lVar3 = (longdouble)Sys_FloatTime();
        lastAvg_21 = (float)lVar3;
      }
      if ((byte)(0.999 < cpuPercent | (byte)((ushort)((ushort)NAN(cpuPercent) << 10) >> 8) |
                (byte)((ushort)((ushort)(cpuPercent == 0.999) << 0xe) >> 8)) == 1) {
        cpuPercent = 0.999;
      }
      if (cpuPercent < 0.0) {
        cpuPercent = 0.0;
      }
      lVar3 = (longdouble)Sys_FloatTime();
      last_18 = (float)lVar3;
    }
  }
  return;
}


// Host_ValidSave  @ 00070d18
undefined4 Host_ValidSave(void)

{
  undefined4 uVar1;
  
  if (cmd_source == 1) {
    if (sv == 0) {
      Con_Printf("Not playing a local game.\n");
      uVar1 = 0;
    }
    else if (DAT_00524288 == 1) {
      if ((cls == 5) && (DAT_002fd3ac == 2)) {
        if (cl._176000_4_ == 0) {
          if ((*DAT_00524284 == 0) || (0.0 < *(float *)(DAT_00524284[0x12a1] + 0x1e0))) {
            uVar1 = 1;
          }
          else {
            Con_Printf("Can\'t savegame with a dead player\n");
            uVar1 = 0;
          }
        }
        else {
          Con_Printf("Can\'t save in intermission.\n");
          uVar1 = 0;
        }
      }
      else {
        Con_Printf("Can\'t save during transition.\n");
        uVar1 = 0;
      }
    }
    else {
      Con_Printf("Can\'t save multiplayer games.\n");
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Host_Version  @ 0006d92c
void Host_Version(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_13c [32];
  undefined4 local_11c;
  undefined1 *local_118;
  int local_114;
  int local_110;
  undefined1 *local_10c;
  char local_108 [260];
  
  local_110 = 0;
  local_114 = 0;
  local_118 = (undefined1 *)0x0;
  local_11c = 0;
  Q_strcpy(gpszVersionString,"1.0.1.4");
  iVar1 = COM_CheckParm("-steam");
  if (iVar1 == 0) {
    sprintf(local_108,"sierra.inf");
  }
  else {
    sprintf(local_108,"steam.inf");
  }
  local_114 = FS_Open(local_108,&DAT_000e330b);
  if (local_114 != 0) {
    local_110 = FS_Size(local_114);
    local_10c = (undefined1 *)Mem_Malloc(local_110 + 1);
    FS_Read(local_10c,local_110,1,local_114);
    FS_Close(local_114);
    local_10c[local_110] = 0;
    local_118 = local_10c;
    do {
      local_118 = (undefined1 *)COM_Parse(local_118);
      if ((local_118 == (undefined1 *)0x0) || (iVar1 = Q_strlen(&com_token), iVar1 < 1))
      goto LAB_0006dbd8;
      uVar2 = Q_strlen("PatchVersion=");
      iVar1 = Q_strnicmp(&com_token,"PatchVersion=",uVar2);
    } while (iVar1 != 0);
    iVar1 = Q_strlen("PatchVersion=");
    local_118 = &com_token + iVar1;
    Q_strncpy(gpszVersionString,local_118,0x1f);
    gpszVersionString[0x1f] = 0;
    iVar1 = COM_CheckParm("-steam");
    if (iVar1 != 0) {
      FS_GetInterfaceVersion(local_13c,0x1f);
      snprintf(gpszVersionString,0x20,"%s/%s",local_118,local_13c);
      gpszVersionString[0x1f] = 0;
    }
LAB_0006dbd8:
    if (local_10c != (undefined1 *)0x0) {
      Mem_Free(local_10c);
    }
  }
  if (cls == 0) {
    Con_Printf("Protocol version %i\nExe version %s\n",0x2e,gpszVersionString);
    uVar2 = build_number();
    Con_Printf("Exe build: 22:35:19 Apr 29 2003 (%i)\n",uVar2);
  }
  else {
    Con_DPrintf("Protocol version %i\nExe version %s\n",0x2e,gpszVersionString);
    uVar2 = build_number();
    Con_DPrintf("Exe build: 22:35:19 Apr 29 2003 (%i)\n",uVar2);
  }
  return;
}


// Host_Version_f  @ 00074808
void Host_Version_f(void)

{
  undefined4 uVar1;
  
  Con_Printf("Protocol version %i\nExe version %s\n",0x2e,gpszVersionString);
  uVar1 = build_number();
  Con_Printf("Exe build: 22:35:19 Apr 29 2003 (%i)\n",uVar1);
  return;
}


// Host_VoiceRecordStart_f  @ 00075a90
void Host_VoiceRecordStart_f(void)

{
  char *pcStack_10;
  char *local_c;
  char *local_8;
  
  if (cls == 5) {
    local_8 = (char *)0x0;
    local_c = (char *)0x0;
    pcStack_10 = (char *)0x0;
    if ((int)ROUND((float)voice_recordtofile._12_4_) != 0) {
      local_8 = "voice_micdata.wav";
      local_c = "voice_decompressed.wav";
    }
    if ((int)ROUND((float)voice_inputfromfile._12_4_) != 0) {
      pcStack_10 = "voice_input.wav";
    }
    Voice_RecordStart(local_8,local_c,pcStack_10);
  }
  return;
}


// Host_VoiceRecordStop_f  @ 00075b60
void Host_VoiceRecordStop_f(void)

{
  int iVar1;
  
  if (cls == 5) {
    iVar1 = Voice_IsRecording();
    if (iVar1 != 0) {
      CL_AddVoiceToDatagram(1);
      Voice_RecordStop();
    }
  }
  return;
}


// Host_WriteConfiguration  @ 0006a53c
void Host_WriteConfiguration(void)

{
  return;
}


// Host_WriteCustomConfig  @ 0006a550
void Host_WriteCustomConfig(void)

{
  undefined4 uVar1;
  int iVar2;
  char local_118 [276];
  
  uVar1 = Cmd_Args();
  snprintf(local_118,0x101,"%s",uVar1);
  if (&stack0x00000000 == (undefined1 *)0x118) {
    Con_Printf("writecfg: writecfg <filename>\n");
  }
  else {
    iVar2 = Q_strstr(local_118,&DAT_000e2bbf);
    if ((((iVar2 != 0) || (iVar2 = Q_stricmp(local_118,"config"), iVar2 == 0)) ||
        (iVar2 = Q_stricmp(local_118,"autoexec"), iVar2 == 0)) ||
       ((iVar2 = Q_stricmp(local_118,"listenserver"), iVar2 == 0 ||
        (iVar2 = Q_stricmp(local_118,"server"), iVar2 == 0)))) {
      Con_Printf("skipping writecfg output, invalid filename given\n");
    }
  }
  return;
}


