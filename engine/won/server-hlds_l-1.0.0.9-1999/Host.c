// Host_AutoSave_f  @ 0805b670
void Host_AutoSave_f(void)

{
  int iVar1;
  undefined1 local_54 [80];
  
  iVar1 = Host_ValidSave();
  if (iVar1 != 0) {
    Host_SavegameComment(local_54);
    SaveGameSlot("autosave",local_54);
  }
  return;
}


// Host_BeginRedirect  @ 08059cc0
void Host_BeginRedirect(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  sv_redirected = param_1;
  puVar2 = &sv_redirectto;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  outputbuf = 0;
  return;
}


// Host_Begin_f  @ 0805df80
void Host_Begin_f(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = host_client;
  if (cmd_source == 1) {
    Con_Printf("begin is not valid from the console\n");
  }
  else {
    *host_client = 1;
    puVar2[1] = 1;
    puVar2[2] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2 = puVar2 + 0xf2a;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}


// Host_CRC_f  @ 0805eea0
void Host_CRC_f(void)

{
  int iVar1;
  undefined4 local_10c;
  char local_108 [260];
  
  iVar1 = Cmd_Argv(1);
  if (iVar1 != 0) {
    sprintf(local_108,"maps\\%s.bsp",iVar1);
    CRC32_Init(&local_10c);
    iVar1 = CRC_MapFile(&local_10c,local_108);
    if (iVar1 == 0) {
      Con_Printf("Couldn\'t CRC %s\n",local_108);
    }
    else {
      Con_Printf("CRC of %s = %i\n",local_108,local_10c);
    }
  }
  return;
}


// Host_Changelevel2_f  @ 0805d2f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_Changelevel2_f(void)

{
  int iVar1;
  char *pcVar2;
  char *__src;
  undefined4 uVar3;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  
  giActive = 4;
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    Con_Printf("changelevel2 <levelname> : continue game on a new level in the unit\n");
    return;
  }
  if (((sv == 0) || (DAT_081b9d98 != 0)) || (DAT_0811d244 != 0)) {
    Con_Printf("Only the server may changelevel\n");
    return;
  }
  SCR_BeginLoadingPlaque();
  S_StopAllSounds(1);
  pcVar2 = (char *)Cmd_Argv(1);
  strcpy(local_44,pcVar2);
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    __src = (char *)Cmd_Argv(2);
    pcVar2 = local_c4;
    strcpy(pcVar2,__src);
    if (local_c4[0] != '\0') goto LAB_0805d3ae;
  }
  pcVar2 = (char *)0x0;
LAB_0805d3ae:
  strcpy(local_84,&DAT_0811d260);
  uVar3 = SaveGamestate();
  iVar1 = SV_SpawnServer(0,local_44,pcVar2);
  if (iVar1 == 0) {
    Sys_Error("Couldn\'t load map %s\n",local_44);
  }
  else {
    SaveExit(uVar3);
    iVar1 = LoadGamestate(local_44,0);
    if (iVar1 == 0) {
      SV_LoadEntities();
    }
    LoadAdjacentEntities(local_84,pcVar2);
    DAT_0811d244 = 1;
    DAT_0811d248 = 1;
    gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
    if ((iVar1 == 0) &&
       ((byte)(0.0 < (float)sv_newunit._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_newunit._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_newunit._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
      Host_ClearSaveDirectory();
    }
    SV_ActivateServer(0);
  }
  return;
}


// Host_Changelevel_f  @ 0805ab40
void Host_Changelevel_f(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *__src;
  char local_84 [64];
  char local_44 [64];
  
  iVar1 = Cmd_Argc();
  if ((iVar1 < 2) || (iVar1 = Host_ValidGame(), iVar1 == 0)) {
    Con_Printf("changelevel <levelname> : continue game on a new level\n");
    return;
  }
  if ((sv != 0) && (DAT_081b9d98 == 0)) {
    uVar2 = Cmd_Argv(1);
    iVar1 = PF_IsMapValid_I(uVar2);
    if (iVar1 == 0) {
      Con_Printf("changelevel failed: \'");
      uVar2 = Cmd_Argv(1);
      Con_Printf(uVar2);
      Con_Printf("\' not found on server\n");
      return;
    }
    SCR_BeginLoadingPlaque();
    S_StopAllSounds(1);
    pcVar3 = (char *)Cmd_Argv(1);
    strcpy(local_44,pcVar3);
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      pcVar3 = (char *)0x0;
    }
    else {
      __src = (char *)Cmd_Argv(2);
      pcVar3 = local_84;
      strcpy(pcVar3,__src);
    }
    SV_InactivateClients();
    SV_SpawnServer(0,local_44,pcVar3);
    SV_LoadEntities();
    SV_ActivateServer(1);
    return;
  }
  Con_Printf("Only the server may changelevel\n");
  return;
}


// Host_CheckDyanmicStructures  @ 08057d40
void Host_CheckDyanmicStructures(void)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_0816dd10 != 0) && (0 < DAT_08166d04)) {
    iVar2 = 0;
    iVar1 = DAT_0816dd10;
    do {
      if (iVar1 == 0) {
        return;
      }
      if (*(int *)(iVar1 + 0x4f04) != 0) {
        SV_ClearFrames(iVar1 + 0x4f04);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x52b8;
    } while (iVar2 < DAT_08166d04);
  }
  return;
}


// Host_CheckForRcon  @ 08058e90
void Host_CheckForRcon(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = NET_GetPacket(1);
    if (iVar1 == 0) break;
    iVar1 = SV_FilterPacket();
    if (iVar1 == 0) {
      if (*(int *)net_message._8_4_ == -1) {
        Host_HandleRconPacket();
      }
    }
    else {
      SV_SendBan();
    }
  }
  return;
}


// Host_ClearClients  @ 08057a20
void Host_ClearClients(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_3c [2];
  int local_1c;
  undefined4 local_18 [5];
  
  host_client = DAT_0816dd10;
  for (local_1c = 0; local_1c < svs; local_1c = local_1c + 1) {
    if ((*(int *)((int)host_client + 0x4f04) != 0) && (iVar1 = 0, 0 < SV_UPDATE_BACKUP)) {
      do {
        puVar2 = (undefined4 *)(*(int *)((int)host_client + 0x4f04) + iVar1 * 0x18);
        SV_ClearPacketEntities();
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0xbf800000;
        iVar1 = iVar1 + 1;
      } while (iVar1 < SV_UPDATE_BACKUP);
    }
    if (*(int *)((int)host_client + 0x14) != 0) {
      puVar2 = (undefined4 *)((int)host_client + 0x14);
      puVar3 = local_18;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)((int)host_client + 0x14);
      for (iVar1 = 0xfa5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      puVar2 = local_18;
      puVar3 = auStack_3c;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      Netchan_Setup(1,(int)host_client + 0x14);
    }
    COM_ClearCustomizationList();
    host_client = (void *)((int)host_client + 0x52b8);
  }
  if (param_1 == 0) {
    host_client = DAT_0816dd10;
    for (local_1c = 0; local_1c < DAT_08166d04; local_1c = local_1c + 1) {
      SV_ClearFrames();
      host_client = (void *)((int)host_client + 0x52b8);
    }
    auStack_3c[1] = 0x8057b82;
    memset(DAT_0816dd10,0,DAT_08166d04 * 0x52b8);
    auStack_3c[1] = 0x8057b87;
    SV_AllocClientFrames();
  }
  return;
}


// Host_ClearGameState  @ 0805d2d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_ClearGameState(void)

{
  S_StopAllSounds(1);
  Host_ClearSaveDirectory();
  (*_DAT_08178ed8)();
  return;
}


// Host_ClearMemory  @ 08057da0
void Host_ClearMemory(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
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
  DAT_081b9180 = 0;
  puVar2 = &sv;
  for (iVar1 = 0xd7e3; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  CL_ClearClientState();
  SV_ClearClientStates();
  return;
}


// Host_ClearSaveDirectory  @ 0805d280
void Host_ClearSaveDirectory(void)

{
  undefined4 uVar1;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory();
  sprintf(local_108,"%s",uVar1);
  COM_FixSlashes(local_108);
  Sys_mkdir(local_108);
  strcat(local_108,"*.HL?");
  DirectoryClear(local_108);
  return;
}


// Host_ClientCommands  @ 08057870
void Host_ClientCommands(char *param_1)

{
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  MSG_WriteByte(host_client + 0x78,9);
  MSG_WriteString(host_client + 0x78,local_404);
  return;
}


// Host_Connect_f  @ 0805ae90
void Host_Connect_f(void)

{
  int iVar1;
  char *__src;
  char local_44 [64];
  
  if (DAT_081b9d98 != 0) {
    CL_StopPlayback();
    CL_Disconnect();
  }
  iVar1 = Cmd_Argc();
  if ((1 < iVar1) && (iVar1 = Cmd_Args(), iVar1 != 0)) {
    __src = (char *)Cmd_Args();
    strcpy(local_44,__src);
    strncpy(&DAT_081b9184,local_44,0x103);
    CL_Connect_f();
    return;
  }
  Con_Printf("Usage:  connect <server>\n");
  return;
}


// Host_Demos_f  @ 0805e5c0
void Host_Demos_f(void)

{
  if (cls != 0) {
    if (DAT_081b9b90 == -1) {
      DAT_081b9b90 = 0;
    }
    CL_Disconnect_f();
    CL_NextDemo();
  }
  return;
}


// Host_EndGame  @ 08057230
void Host_EndGame(char *param_1)

{
  int iVar1;
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  Con_DPrintf("Host_EndGame: %s\n",local_404);
  iVar1 = DAT_081b9b90;
  scr_disabled_for_loading = 1;
  if (sv != 0) {
    Host_ShutdownServer(0);
  }
  DAT_081b9b90 = iVar1;
  if (cls == 0) {
    Sys_Error("Host_EndGame: %s\n",local_404);
  }
  iVar1 = DAT_081b9b90;
  if (DAT_081b9b90 != -1) {
    CL_Disconnect_f();
    DAT_081b9b90 = iVar1;
    CL_NextDemo();
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


// Host_EndRedirect  @ 08059cf0
void Host_EndRedirect(void)

{
  Host_FlushRedirect();
  sv_redirected = 0;
  return;
}


// Host_EndSection  @ 0805ec50
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
    iVar1 = strcasecmp(param_1,"_oem_end_training");
    if (iVar1 == 0) {
      giStateInfo = 1;
    }
    else {
      iVar1 = strcasecmp(param_1,"_oem_end_logo");
      if (iVar1 == 0) {
        giStateInfo = 2;
      }
      else {
        iVar1 = strcasecmp(param_1,"_oem_end_demo");
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


// Host_Error  @ 08057300
void Host_Error(char *param_1)

{
  char local_404 [1024];
  
  if (inerror_96 != 0) {
    Sys_Error("Host_Error: recursively entered");
  }
  inerror_96 = 1;
  SCR_EndLoadingPlaque();
  vsprintf(local_404,param_1,&stack0x00000008);
  Con_Printf("Host_Error: %s\n",local_404);
  if (sv != 0) {
    Host_ShutdownServer(0);
  }
  if (cls == 0) {
    Sys_Error("Host_Error: %s\n",local_404);
  }
  CL_Disconnect();
  DAT_081b9b90 = 0xffffffff;
  inerror_96 = 0;
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Host_FilterTime  @ 08057e20
undefined4 Host_FilterTime(float param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  
  realtime = (double)(param_1 + (float)realtime);
  if (isDedicated == 0) {
    dVar1 = (double)(float)fps_single._12_4_;
    if ((sv == 0) &&
       (dVar1 = (double)(float)fps_modem._12_4_,
       (byte)(5000.0 < (float)rate._12_4_ |
              (byte)((ushort)((ushort)NAN((float)rate._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)rate._12_4_ == 5000.0) << 0xe) >> 8)) == 1)) {
      dVar1 = (double)(float)fps_lan._12_4_;
    }
    if ((byte)(0.0 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(dVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      if (0.1 <= dVar1) {
        if ((byte)(72.0 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(dVar1 == 72.0) << 0xe) >> 8)) == 1) {
          dVar1 = 72.0;
        }
      }
      else {
        dVar1 = 0.10000000149011612;
      }
      if (DAT_081b9d9c == 0) {
        dVar2 = realtime - oldrealtime;
        dVar1 = 1.0 / dVar1;
        if ((byte)(dVar2 < dVar1 | (byte)((ushort)((ushort)(NAN(dVar2) || NAN(dVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(dVar2 == dVar1) << 0xe) >> 8)) == 1) {
          return 0;
        }
      }
    }
  }
  host_frametime = realtime - oldrealtime;
  oldrealtime = realtime;
  if (((byte)(0.0 < (float)host_framerate._12_4_ |
              (byte)((ushort)((ushort)NAN((float)host_framerate._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)host_framerate._12_4_ == 0.0) << 0xe) >> 8)) == 1) &&
     (iVar3 = IsSinglePlayerGame(), iVar3 != 0)) {
    host_frametime = (double)(float)host_framerate._12_4_;
  }
  else {
    if ((byte)(0.1 < host_frametime | (byte)((ushort)((ushort)NAN(host_frametime) << 10) >> 8) |
              (byte)((ushort)((ushort)(host_frametime == 0.1) << 0xe) >> 8)) == 1) {
      host_frametime = 0.1;
    }
    if (host_frametime < 0.001) {
      host_frametime = 0.001;
    }
  }
  return 1;
}


// Host_FindMaxClients  @ 080573b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_FindMaxClients(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if (0 < DAT_08166d04) {
    iVar3 = 0;
    iVar2 = (int)DAT_0816dd10;
    do {
      SV_ClearFrames(iVar2 + 0x4f04);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x52b8;
    } while (iVar3 < DAT_08166d04);
  }
  svs = 1;
  iVar2 = COM_CheckParm("-maxplayers");
  if (iVar2 == 0) {
    if (isDedicated != 0) {
      svs = 6;
      goto LAB_08057433;
    }
  }
  else {
    svs = Q_atoi(*(undefined4 *)(com_argv + 4 + iVar2 * 4));
LAB_08057433:
    if (isDedicated != 0) {
      cls = 0;
      goto LAB_0805745a;
    }
  }
  cls = 1;
LAB_0805745a:
  if (svs < 1) {
    svs = 6;
  }
  else if (0x20 < svs) {
    svs = 0x20;
  }
  if ((isDedicated == 0) && (_DAT_080cc330 < 0x1000001)) {
    DAT_08166d04 = 4;
  }
  else {
    DAT_08166d04 = 0x20;
  }
  if (svs == 1) {
    SV_UPDATE_BACKUP = 8;
  }
  else {
    SV_UPDATE_BACKUP = 0x40;
  }
  SV_UPDATE_MASK = SV_UPDATE_BACKUP + -1;
  puVar1 = (undefined4 *)Hunk_AllocName(DAT_08166d04 * 0x52b8,"clients");
  DAT_0816dd10 = puVar1;
  if (0 < DAT_08166d04) {
    iVar2 = 0;
    do {
      puVar4 = puVar1;
      for (iVar3 = 0x14ae; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      puVar1[0x1446] = puVar1 + 0x142e;
      puVar1[0x1447] = puVar1 + 0x142e;
      puVar1[0x142c] = puVar1 + 0x1414;
      puVar1[0x142d] = puVar1 + 0x1414;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x14ae;
    } while (iVar2 < DAT_08166d04);
  }
  if (svs < 2) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0x3f800000;
  }
  Cvar_SetValue("deathmatch",uVar5);
  SV_AllocClientFrames();
  if (DAT_08166d04 < svs) {
    svs = DAT_08166d04;
  }
  return;
}


// Host_FindRecentSave  @ 0805ac50
char * Host_FindRecentSave(char *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char *__src;
  int iVar3;
  int local_214;
  int local_210;
  char local_20c [260];
  undefined1 local_108 [260];
  
  uVar2 = Host_SaveGameDirectory();
  sprintf(param_1,"%s*.sav",uVar2);
  uVar2 = Host_SaveGameDirectory();
  sprintf(local_20c,"%s",uVar2);
  __src = (char *)Sys_FindFirst(param_1,local_108);
  bVar1 = false;
  while (__src != (char *)0x0) {
    iVar3 = Q_strlen(__src);
    if ((iVar3 != 0) && (iVar3 = Q_strcasecmp(__src,"HLSave.sav"), iVar3 != 0)) {
      uVar2 = Host_SaveGameDirectory(__src);
      sprintf(local_20c,"%s%s",uVar2);
      local_210 = Sys_FileTime(local_20c);
      if ((0 < local_210) &&
         ((!bVar1 || (iVar3 = Sys_CompareFileTime(&local_214,&local_210), iVar3 < 0)))) {
        local_214 = local_210;
        strcpy(param_1,__src);
        bVar1 = true;
      }
    }
    __src = (char *)Sys_FindNext(local_108);
  }
  Sys_FindClose();
  if (!bVar1) {
    param_1 = (char *)0x0;
  }
  return param_1;
}


// Host_FlushRedirect  @ 08059c00
void Host_FlushRedirect(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 **ppuVar3;
  undefined1 *apuStack_5cc [4];
  undefined4 uStack_5bc;
  undefined1 local_5ac [1428];
  undefined1 local_18 [8];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (sv_redirected == 2) {
    local_c = 0x591;
    local_8 = 0;
    local_10 = local_5ac;
    uStack_5bc = 0xffffffff;
    apuStack_5cc[2] = (undefined1 *)0x8059c37;
    apuStack_5cc[3] = local_18;
    MSG_WriteLong();
    apuStack_5cc[2] = (undefined1 *)0x6c;
    apuStack_5cc[0] = (undefined1 *)0x8059c3f;
    apuStack_5cc[1] = local_18;
    MSG_WriteByte();
    apuStack_5cc[0] = &outputbuf;
    MSG_WriteString(local_18);
    MSG_WriteByte(local_18,0);
    puVar2 = &sv_redirectto;
    ppuVar3 = apuStack_5cc;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = (undefined1 *)*puVar2;
      puVar2 = puVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    NET_SendPacket(1,local_8,local_10);
  }
  else if (sv_redirected == 1) {
    uStack_5bc = 8;
    apuStack_5cc[3] = (undefined1 *)(host_client + 0x78);
    apuStack_5cc[2] = (undefined1 *)0x8059c99;
    MSG_WriteByte();
    apuStack_5cc[2] = &outputbuf;
    apuStack_5cc[1] = (undefined1 *)(host_client + 0x78);
    apuStack_5cc[0] = (undefined1 *)0x8059cac;
    MSG_WriteString();
  }
  outputbuf = 0;
  return;
}


// Host_Fly_f  @ 0805a6b0
void Host_Fly_f(void)

{
  char *pcVar1;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (((byte)(0.0 < (float)gGlobalVariables._20_4_ |
                   (byte)((ushort)((ushort)NAN((float)gGlobalVariables._20_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)gGlobalVariables._20_4_ == 0.0) << 0xe) >> 8)) ==
            0x40) || (*(int *)(host_client + 0x3eb4) != 0)) {
    if (*(int *)(sv_player + 0x1c4) == 5) {
      *(undefined4 *)(sv_player + 0x1c4) = 3;
      pcVar1 = "flymode OFF\n";
    }
    else {
      *(undefined4 *)(sv_player + 0x1c4) = 5;
      pcVar1 = "flymode ON\n";
    }
    SV_ClientPrintf(pcVar1);
  }
  return;
}


// Host_Frame  @ 080590f0
undefined4 Host_Frame(undefined4 param_1,undefined4 param_2,int *param_3)

{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined4 *puVar4;
  longdouble lVar5;
  longdouble lVar6;
  int local_24;
  
  iVar3 = __sigsetjmp(host_abortserver,0);
  if (iVar3 == 0) {
    if ((cls == 5) && (g_bForceReloadOnCA_Active != 0)) {
      _ForceReloadProfile(&g_szPlayerName);
      g_bForceReloadOnCA_Active = 0;
      puVar4 = &g_szPlayerName;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    giActive = param_2;
    *param_3 = 0;
    if ((byte)((byte)((ushort)((ushort)NAN((float)serverprofile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)serverprofile._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      _Host_Frame(param_1);
      if (giStateInfo != 0) {
        *param_3 = giStateInfo;
        giStateInfo = 0;
        Cbuf_Execute();
      }
    }
    else {
      lVar5 = (longdouble)Sys_FloatTime();
      _Host_Frame(param_1);
      lVar6 = (longdouble)Sys_FloatTime();
      if (giStateInfo != 0) {
        *param_3 = giStateInfo;
        giStateInfo = 0;
        Cbuf_Execute();
      }
      if ((cls == 1) && (con_quiet != 0)) {
        giActive = 2;
      }
      timetotal_172 = ((double)lVar6 - (double)lVar5) + timetotal_172;
      timecount_173 = timecount_173 + 1;
      if (999 < timecount_173) {
        dVar1 = timetotal_172 * 1000.0;
        dVar2 = (double)timecount_173;
        timecount_173 = 0;
        timetotal_172 = 0.0;
        iVar3 = 0;
        local_24 = 0;
        if (0 < svs) {
          do {
            if (*(int *)(DAT_0816dd10 + local_24 * 0x52b8) != 0) {
              iVar3 = iVar3 + 1;
            }
            local_24 = local_24 + 1;
          } while (local_24 < svs);
        }
        Con_Printf("serverprofile: %2i clients %2i msec\n",iVar3,(int)ROUND(dVar1 / dVar2));
      }
    }
  }
  return giActive;
}


// Host_FullInfo_f  @ 0805d4c0
void Host_FullInfo_f(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_404 [512];
  char local_204 [512];
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 2) {
    pcVar3 = (char *)Cmd_Argv(1);
    if (*pcVar3 == '\\') {
      pcVar3 = pcVar3 + 1;
    }
    while (*pcVar3 != '\0') {
      pcVar4 = local_204;
      cVar1 = *pcVar3;
      while ((cVar1 != '\0' && (*pcVar3 != '\\'))) {
        *pcVar4 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar3;
      }
      *pcVar4 = '\0';
      if (*pcVar3 == '\0') {
        Con_Printf("MISSING VALUE\n");
        return;
      }
      pcVar4 = local_404;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
      while ((cVar1 != '\0' && (*pcVar3 != '\\'))) {
        *pcVar4 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar3;
      }
      *pcVar4 = '\0';
      if (*pcVar3 != '\0') {
        pcVar3 = pcVar3 + 1;
      }
      if (cmd_source == 1) {
        Info_SetValueForKey(&DAT_081b9acc,local_204,local_404,0xc4);
        Cmd_ForwardToServer();
        return;
      }
      Info_SetValueForKey(host_client + 0x4f18,local_204,local_404,0xc4);
      SV_ExtractFromUserinfo(host_client);
    }
  }
  else {
    Con_Printf("fullinfo <complete info string>\n");
  }
  return;
}


// Host_GetBatchModList_f  @ 0805f120
void Host_GetBatchModList_f(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 auStack_c8 [4];
  undefined4 uStack_b8;
  char *pcStack_b4;
  undefined4 uStack_b0;
  undefined4 auStack_ac [2];
  char local_84 [128];
  
  NET_Config();
  if ((gfNoMasterServer == 0) && (valvemaster_adr != 0)) {
    auStack_ac[1] = 0x805f160;
    sprintf(local_84,"%c\r\nstart-of-list\r\n");
    if (valvemaster_adr != 0) {
      iVar4 = valvemaster_adr;
      do {
        puVar5 = (undefined4 *)(iVar4 + 0x18);
        puVar6 = auStack_ac;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        uStack_b0 = 0x805f18d;
        uStack_b0 = NET_AdrToString();
        pcStack_b4 = "Requesting batch mod status from %s\n";
        uStack_b8 = 0x805f19a;
        Con_Printf();
        puVar5 = (undefined4 *)(iVar4 + 0x18);
        puVar6 = auStack_c8;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        uVar3 = 0xffffffff;
        pcVar7 = local_84;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        NET_SendPacket(0,~uVar3,local_84);
        iVar4 = *(int *)(iVar4 + 0x2c);
      } while (iVar4 != 0);
    }
  }
  return;
}


// Host_GetBatchServerList_f  @ 0805f090
void Host_GetBatchServerList_f(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_4c [4];
  undefined4 uStack_3c;
  char *pcStack_38;
  undefined4 uStack_34;
  undefined4 auStack_30 [5];
  undefined1 local_10;
  undefined4 local_f;
  
  auStack_30[4] = 1;
  auStack_30[3] = 0x805f0a0;
  NET_Config();
  if ((gfNoMasterServer == 0) && (valvemaster_adr != 0)) {
    local_10 = 0x65;
    local_f = 0;
    for (iVar1 = valvemaster_adr; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
      puVar3 = (undefined4 *)(iVar1 + 0x18);
      puVar4 = auStack_30;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      uStack_34 = 0x805f0e1;
      uStack_34 = NET_AdrToString();
      pcStack_38 = "Requesting batch server list from %s\n";
      uStack_3c = 0x805f0ec;
      Con_Printf();
      puVar3 = (undefined4 *)(iVar1 + 0x18);
      puVar4 = auStack_4c;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      NET_SendPacket(0,5,&local_10);
    }
  }
  return;
}


// Host_GetHostInfo  @ 08058ca0
void Host_GetHostInfo(undefined4 *param_1,int *param_2,int *param_3,undefined4 *param_4,
                     char *param_5)

{
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  *param_1 = g_fFrameTime;
  SV_CountPlayers(&local_c,&local_8);
  local_c = local_c - local_8;
  *param_2 = local_c;
  *param_3 = local_8;
  if (param_5 != (char *)0x0) {
    if (DAT_0811d260 == '\0') {
      *param_5 = '\0';
    }
    else {
      strcpy(param_5,&DAT_0811d260);
    }
  }
  *param_4 = svs;
  return;
}


// Host_GetServerList_f  @ 0805f000
void Host_GetServerList_f(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_44 [4];
  undefined4 uStack_34;
  char *pcStack_30;
  undefined4 uStack_2c;
  undefined4 auStack_28 [5];
  undefined1 local_5;
  
  auStack_28[4] = 1;
  auStack_28[3] = 0x805f010;
  NET_Config();
  if ((gfNoMasterServer == 0) && (valvemaster_adr != 0)) {
    local_5 = 99;
    for (iVar1 = valvemaster_adr; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
      puVar3 = (undefined4 *)(iVar1 + 0x18);
      puVar4 = auStack_28;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      uStack_2c = 0x805f049;
      uStack_2c = NET_AdrToString();
      pcStack_30 = "Requesting server list from %s\n";
      uStack_34 = 0x805f054;
      Con_Printf();
      puVar3 = (undefined4 *)(iVar1 + 0x18);
      puVar4 = auStack_44;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      NET_SendPacket(0,1,&local_5);
    }
  }
  return;
}


// Host_Getcertificate_f  @ 0805f2d0
void Host_Getcertificate_f(void)

{
  int iVar1;
  char *pcVar2;
  
  Con_Printf("Trying to authenticate with WON servers\n");
  iVar1 = (*Launcher_RequestNewClientCertificate)();
  if (iVar1 == 0) {
    pcVar2 = "Failed to authenticate\n";
  }
  else {
    pcVar2 = "WON Authentication successful\n";
  }
  Con_Printf(pcVar2);
  return;
}


// Host_God_f  @ 0805a360
void Host_God_f(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = sv_player;
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if ((((byte)(0.0 < (float)gGlobalVariables._20_4_ |
                    (byte)((ushort)((ushort)NAN((float)gGlobalVariables._20_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)gGlobalVariables._20_4_ == 0.0) << 0xe) >> 8)) ==
             0x40) || (*(int *)(host_client + 0x3eb4) != 0)) && (allow_cheats != 0)) {
    *(byte *)(sv_player + 0x260) = *(byte *)(sv_player + 0x260) ^ 0x40;
    if ((*(byte *)(iVar1 + 0x260) & 0x40) == 0) {
      pcVar2 = "godmode OFF\n";
    }
    else {
      pcVar2 = "godmode ON\n";
    }
    SV_ClientPrintf(pcVar2);
  }
  return;
}


// Host_HandleRconPacket  @ 08058e30
void Host_HandleRconPacket(void)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  bool bVar7;
  
  MSG_BeginReading();
  MSG_ReadLong();
  uVar1 = MSG_ReadStringLine();
  Cmd_TokenizeString(uVar1);
  pbVar2 = (byte *)Cmd_Argv(0);
  pcVar5 = "Brcon";
  iVar4 = 5;
  bVar6 = false;
  uVar3 = 0;
  bVar7 = true;
  do {
    pcVar5 = pcVar5 + 1;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar6 = *pbVar2 < (byte)*pcVar5;
    bVar7 = *pbVar2 == *pcVar5;
    pbVar2 = pbVar2 + 1;
  } while (bVar7);
  if (!bVar7) {
    uVar3 = -(uint)bVar6 | 1;
  }
  if (uVar3 == 0) {
    Host_RemoteCommand(&net_from);
  }
  return;
}


// Host_Init  @ 08059640
undefined4 Host_Init(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (standard_quake == 0) {
    minimum_memory = 0x650000;
  }
  else {
    minimum_memory = 0x550000;
  }
  iVar1 = COM_CheckParm();
  if (iVar1 != 0) {
    param_1[5] = minimum_memory;
  }
  puVar4 = param_1;
  puVar5 = &host_parms;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if ((int)param_1[5] < minimum_memory) {
    Sys_Error("Only %4.1f megs of memory available, can\'t execute game",
              (double)((float)(int)param_1[5] * 9.536743e-07));
  }
  com_argc = param_1[2];
  com_argv = param_1[3];
  realtime._0_4_ = 0;
  realtime._4_4_ = 0;
  iVar1 = COM_CheckParm();
  if (((iVar1 == 0) && (iVar1 = COM_CheckParm(), iVar1 == 0)) &&
     (iVar1 = COM_CheckParm(), iVar1 == 0)) {
    con_quiet = 1;
  }
  else {
    con_quiet = 0;
  }
  iVar1 = COM_CheckParm();
  if ((iVar1 != 0) && (iVar1 = Q_atoi(), iVar1 == 0x23)) {
    PROTOCOL_VERSION = 0x23;
  }
  Protocol_Init();
  Memory_Init(param_1[4],param_1[5]);
  Cbuf_Init();
  Cmd_Init();
  Cvar_CmdInit();
  V_Init();
  Chase_Init();
  COM_Init(*param_1);
  Host_InitLocal();
  W_LoadWadFile("gfx.wad");
  Key_Init();
  Con_Init();
  Decal_Init();
  Mod_Init();
  NET_Init();
  Netchan_Init();
  SV_Init();
  Con_DPrintf("Exe: 13:47:28 May  3 1999\n");
  Con_DPrintf("%4.1f megabyte heap\n",(double)(int)param_1[5] * 9.5367431640625e-07);
  R_InitTextures();
  if (cls != 0) {
    iVar1 = COM_LoadHunkFile();
    if (iVar1 == 0) {
      Sys_Error();
    }
    iVar2 = Hunk_AllocName(0x800,"palette.lmp");
    iVar6 = 0;
    host_basepal = iVar2;
    do {
      pcVar3 = (char *)(iVar6 * 3 + iVar1);
      *(short *)(iVar2 + iVar6 * 8) = (short)pcVar3[2];
      *(short *)(iVar2 + 2 + iVar6 * 8) = (short)pcVar3[1];
      *(short *)(iVar2 + 4 + iVar6 * 8) = (short)*pcVar3;
      *(undefined2 *)(iVar2 + 6 + iVar6 * 8) = 0;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x100);
    ClientDLL_Init();
    iVar1 = VID_Init();
    if (iVar1 == 0) {
      return 0;
    }
    Draw_Init();
    SCR_Init();
    R_Init();
    S_Init();
    CL_Init();
    IN_Init();
    (*Launcher_InitCmds)();
  }
  Cbuf_InsertText();
  WON_InitAuthentication();
  Hunk_AllocName(0,"-HOST_HUNKLEVEL-");
  host_hunklevel = Hunk_LowMark();
  giActive = 1;
  scr_skipupdate = 0;
  iVar1 = COM_CheckParm(&DAT_080a084c);
  if (iVar1 != 0) {
    Cvar_SetValue("sv_cheats",0x3f800000);
    Cvar_SetValue("developer",0x3f800000);
  }
  CheckGore();
  host_initialized = 1;
  return 1;
}


// Host_InitCommands  @ 0805f310
void Host_InitCommands(void)

{
  Cmd_AddCommand("getcertificate",Host_Getcertificate_f);
  Cmd_AddCommand("notify",Host_Notify_f);
  Cmd_AddCommand("getsv",Host_GetServerList_f);
  Cmd_AddCommand("bgetsv",Host_GetBatchServerList_f);
  Cmd_AddCommand("bgetmod",Host_GetBatchModList_f);
  Cmd_AddCommand("pingsv",Host_PingServer_f);
  Cmd_AddCommand("protocol",Host_Protocol_f);
  Cmd_AddCommand("logos",Host_Logos_f);
  Cmd_AddCommand(&DAT_080a1c60,Host_CRC_f);
  Cmd_AddCommand("killserver",Host_KillServer_f);
  Cmd_AddCommand("soundfade",Host_Soundfade_f);
  Cmd_AddCommand(&DAT_080a1c79,Host_WC_f);
  Cmd_AddCommand("status",Host_Status_f);
  Cmd_AddCommand(&DAT_080a1c83,Host_Quit_f);
  Cmd_AddCommand(&DAT_080a1c88,Host_Quit_f);
  Cmd_AddCommand(&DAT_080a1c8d,Host_Map_f);
  Cmd_AddCommand(&DAT_080a1c91,Host_Maps_f);
  Cmd_AddCommand("restart",Host_Restart_f);
  Cmd_AddCommand("reload",Host_Reload_f);
  Cmd_AddCommand("changelevel",Host_Changelevel_f);
  Cmd_AddCommand("changelevel2",Host_Changelevel2_f);
  Cmd_AddCommand("connect",Host_Connect_f);
  Cmd_AddCommand("reconnect",Host_Reconnect_f);
  Cmd_AddCommand("version",Host_Version_f);
  Cmd_AddCommand(&DAT_080a1cd8,Host_Say_f);
  Cmd_AddCommand("say_team",Host_Say_Team_f);
  Cmd_AddCommand(&DAT_080a1ce5,Host_Tell_f);
  Cmd_AddCommand(&DAT_080a1cea,Host_Kill_f);
  Cmd_AddCommand("pause",Host_Pause_f);
  Cmd_AddCommand("spawn",Host_Spawn_f);
  Cmd_AddCommand("begin",Host_Begin_f);
  Cmd_AddCommand("prespawn",Host_PreSpawn_f);
  Cmd_AddCommand(&DAT_080a1d0a,Host_Kick_f);
  Cmd_AddCommand(&DAT_080a1d0f,Host_Ping_f);
  Cmd_AddCommand(&DAT_080a1d14,Host_Loadgame_f);
  Cmd_AddCommand(&DAT_080a1d19,Host_Savegame_f);
  Cmd_AddCommand("autosave",Host_AutoSave_f);
  Cmd_AddCommand("startdemos",Host_Startdemos_f);
  Cmd_AddCommand("demos",Host_Demos_f);
  Cmd_AddCommand("stopdemo",Host_Stopdemo_f);
  Cmd_AddCommand("setinfo",Host_SetInfo_f);
  Cmd_AddCommand("fullinfo",Host_FullInfo_f);
  Cmd_AddCommand("ptrack",SV_PTrack_f);
  Cmd_AddCommand("customrsrclist",SV_RequestResourceList_f);
  Cmd_AddCommand(&DAT_080a1d5f,Host_God_f);
  Cmd_AddCommand("notarget",Host_Notarget_f);
  Cmd_AddCommand(&DAT_080a1d6c,Host_Fly_f);
  Cmd_AddCommand("noclip",Host_Noclip_f);
  Cmd_AddCommand("viewmodel",Host_Viewmodel_f);
  Cmd_AddCommand("viewframe",Host_Viewframe_f);
  Cmd_AddCommand("viewnext",Host_Viewnext_f);
  Cmd_AddCommand("viewprev",Host_Viewprev_f);
  Cmd_AddCommand("mcache",Mod_Print);
  Cmd_AddCommand("interp",Host_Interp_f);
  Cmd_AddCommand("setmaster",Master_SetMaster_f);
  Cmd_AddCommand("heartbeat",Master_Heartbeat_f);
  Cmd_AddCommand(&DAT_080a1dbf,Host_RequestMOTD_f);
  Cmd_AddCommand("sv_print_custom",SV_PrintCusomizations_f);
  Cmd_AddCommand("addip",SV_AddIP_f);
  Cmd_AddCommand("removeip",SV_RemoveIP_f);
  Cmd_AddCommand("listip",SV_ListIP_f);
  Cmd_AddCommand("writeip",SV_WriteIP_f);
  Cmd_AddCommand("download",SV_BeginDownload_f);
  Cmd_AddCommand("nextdl",SV_NextDownload_f);
  Cmd_AddCommand("sv_allow_download",SV_AllowDownload_f);
  Cmd_AddCommand("sv_allow_upload",SV_AllowUpload_f);
  Cmd_AddCommand("resourcelist",SV_SendResourceListBlock_f);
  Cvar_RegisterVariable(rcon_password);
  Cvar_RegisterVariable(filterban);
  Cmd_AddCommand(&DAT_080a0eb2,SV_New_f);
  Cmd_AddCommand("dropclient",SV_Drop_f);
  Cmd_AddCommand(&DAT_080a1e3c,SV_Info_f);
  Cvar_RegisterVariable(gHostMap);
  Cmd_AddCommand(&DAT_080a1e41,SV_Keys_f);
  Host_ClearSaveDirectory();
  HPAK_Init();
  return;
}


// Host_InitLocal  @ 080575c0
void Host_InitLocal(void)

{
  Host_InitCommands();
  Cvar_RegisterVariable(fps_single);
  Cvar_RegisterVariable(fps_lan);
  Cvar_RegisterVariable(fps_modem);
  Cvar_RegisterVariable(host_framerate);
  Cvar_RegisterVariable(host_speeds);
  Cvar_RegisterVariable(serverprofile);
  Cvar_RegisterVariable(mp_logfile);
  Cvar_RegisterVariable(mp_logecho);
  Cvar_RegisterVariable(host_killtime);
  Cvar_RegisterVariable(developer);
  Cvar_RegisterVariable(deathmatch);
  Cvar_RegisterVariable(coop);
  Cvar_RegisterVariable(pausable);
  Cvar_RegisterVariable(skill);
  Host_FindMaxClients();
  host_time._0_4_ = 0;
  host_time._4_4_ = 0x3ff00000;
  return;
}


// Host_InitializeGameDLL  @ 08059a60
void Host_InitializeGameDLL(void)

{
  Cbuf_Execute();
  if (DAT_08166d0c == 0) {
    DAT_08166d0c = 1;
    LoadEntityDLLs(host_parms);
    (*gEntityInterface)();
    Cbuf_Execute();
  }
  else {
    Con_DPrintf("Sys_InitializeGameDLL called twice, skipping second call\n");
  }
  return;
}


// Host_Interp_f  @ 0805e4a0
void Host_Interp_f(void)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = r_dointerp == 0;
  r_dointerp = (uint)bVar1;
  if (bVar1) {
    pcVar2 = "Frame Interpolation ON\n";
  }
  else {
    pcVar2 = "Frame Interpolation OFF\n";
  }
  Con_Printf(pcVar2);
  return;
}


// Host_Kick_f  @ 0805dff0
void Host_Kick_f(void)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  longdouble lVar9;
  
  pcVar8 = (char *)0x0;
  bVar1 = false;
  iVar4 = Cmd_Argc();
  piVar2 = host_client;
  if (iVar4 < 2) {
    Con_Printf("usage:  kick < name > | < # userid >\n");
    return;
  }
  if (cmd_source == 1) {
    if (sv == 0) {
      Cmd_ForwardToServer();
      return;
    }
  }
  else if (((byte)(0.0 < (float)gGlobalVariables._20_4_ |
                   (byte)((ushort)((ushort)NAN((float)gGlobalVariables._20_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)gGlobalVariables._20_4_ == 0.0) << 0xe) >> 8)) !=
            0x40) && (host_client[0xfad] == 0)) {
    return;
  }
  iVar4 = Cmd_Argc();
  if (2 < iVar4) {
    uVar5 = Cmd_Argv(1,&DAT_080a16a6);
    iVar4 = Q_strcmp(uVar5);
    if (iVar4 == 0) {
      uVar5 = Cmd_Argv(2);
      lVar9 = (longdouble)Q_atof(uVar5);
      iVar4 = (int)ROUND(lVar9 - (longdouble)1);
      if (iVar4 < 0) {
        return;
      }
      if (svs <= iVar4) {
        return;
      }
      if (DAT_0816dd10[iVar4 * 0x14ae] == 0) {
        return;
      }
      host_client = DAT_0816dd10 + iVar4 * 0x14ae;
      bVar1 = true;
      goto LAB_0805e16b;
    }
  }
  iVar4 = 0;
  host_client = DAT_0816dd10;
  if (svs < 1) {
    host_client = piVar2;
    return;
  }
  do {
    if ((*host_client != 0) || (host_client[2] != 0)) {
      uVar5 = Cmd_Argv(1);
      iVar6 = Q_strcasecmp((int)host_client + 0x5005,uVar5);
      if (iVar6 == 0) break;
    }
    iVar4 = iVar4 + 1;
    host_client = host_client + 0x14ae;
  } while (iVar4 < svs);
LAB_0805e16b:
  piVar3 = piVar2;
  if (iVar4 < svs) {
    pcVar7 = (char *)((int)piVar2 + 0x5005);
    if (cmd_source == 1) {
      pcVar7 = "Console";
    }
    piVar3 = host_client;
    if (host_client != piVar2) {
      iVar4 = Cmd_Argc();
      if (2 < iVar4) {
        uVar5 = Cmd_Args();
        pcVar8 = (char *)COM_Parse(uVar5);
        if (bVar1) {
          do {
            pcVar8 = pcVar8 + 1;
          } while (*pcVar8 == ' ');
          uVar5 = Cmd_Argv(2);
          iVar4 = Q_strlen(uVar5);
          pcVar8 = pcVar8 + iVar4;
        }
        for (; *pcVar8 == ' '; pcVar8 = pcVar8 + 1) {
        }
      }
      if (pcVar8 == (char *)0x0) {
        SV_ClientPrintf("Kicked by %s\n",pcVar7);
      }
      else {
        SV_ClientPrintf("Kicked by %s: %s\n",pcVar7,pcVar8);
      }
      SV_DropClient(host_client,0);
      piVar3 = piVar2;
    }
  }
  host_client = piVar3;
  return;
}


// Host_KillServer_f  @ 0805ee50
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


// Host_Kill_f  @ 0805d980
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_Kill_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (0.0 < *(float *)(sv_player + 0x21c)) {
    gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
    (*_DAT_08178ee4)(sv_player);
  }
  else {
    SV_ClientPrintf("Can\'t suicide -- already dead!\n");
  }
  return;
}


// Host_Load  @ 0805b900
undefined4 Host_Load(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  FILE *__stream;
  int iVar3;
  char *__format;
  char local_180 [8];
  char local_178 [256];
  undefined1 local_78 [112];
  undefined4 local_8;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    if (*param_1 == '_') {
      for (iVar3 = 0;
          ((param_1 = param_1 + 1, *param_1 != '\0' && (iVar1 = isdigit((int)*param_1), iVar1 != 0))
          && (iVar3 < 5)); iVar3 = iVar3 + 1) {
        local_180[iVar3] = *param_1;
      }
      local_180[iVar3] = '\0';
      iVar3 = __strtol_internal(local_180,0,10,0);
      if (0xb < iVar3 - 1U) {
        return 0;
      }
      uVar2 = Host_SaveGameDirectory(iVar3);
      __format = "%sHalf-Life-%i";
    }
    else {
      uVar2 = Host_SaveGameDirectory(param_1);
      __format = "%s%s";
    }
    sprintf(local_178,__format,uVar2);
    if (DAT_08166d0c == 0) {
      Host_InitializeGameDLL();
    }
    COM_DefaultExtension(local_178,&DAT_080a1123);
    COM_FixSlashes(local_178);
    Con_Printf("Loading game from %s...\n",local_178);
    __stream = fopen(local_178,"rb");
    if (__stream != (FILE *)0x0) {
      Host_ClearGameState();
      iVar3 = SaveReadHeader(__stream,local_78,1);
      if (iVar3 != 0) {
        DAT_081b9b90 = 0xffffffff;
        SV_InactivateClients();
        SCR_BeginLoadingPlaque();
        DirectoryExtract(__stream,local_8);
        fclose(__stream);
        Cvar_SetValue("deathmatch",0);
        Cvar_SetValue(&DAT_080a11dc,0);
        sprintf(local_178,"map %s\n",local_78);
        Host_Map(0,local_178,local_78,1);
        return 1;
      }
      giStateInfo = 1;
      Cbuf_AddText("\ndisconnect\n");
    }
  }
  return 0;
}


// Host_Loadgame_f  @ 0805b880
void Host_Loadgame_f(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (cmd_source == 1) {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      uVar2 = Cmd_Argv(1);
      iVar1 = Host_Load(uVar2);
      if (iVar1 != 0) {
        return;
      }
      pcVar3 = "Error loading saved game\n";
    }
    else {
      pcVar3 = "load <savename> : load a game\n";
    }
    Con_Printf(pcVar3);
  }
  return;
}


// Host_Logos_f  @ 0805ef20
void Host_Logos_f(void)

{
  if (sv != 0) {
    SV_PrintLogos();
  }
  if (1 < cls) {
    CL_PrintLogos();
  }
  return;
}


// Host_Map  @ 0805a820
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_Map(undefined4 param_1,char *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char *__src;
  int iVar2;
  
  CL_Disconnect();
  Host_ShutdownServer(0);
  key_dest = 0;
  SCR_BeginLoadingPlaque();
  if (param_4 == 0) {
    Host_ClearGameState();
    SV_InactivateClients();
    _DAT_0816dd14 = 0;
  }
  strcpy(&DAT_081b928c,param_2);
  iVar1 = Host_ValidGame();
  if ((iVar1 != 0) && (iVar1 = SV_SpawnServer(param_1,param_3,0), iVar1 != 0)) {
    if (param_4 == 0) {
      SV_LoadEntities();
      SV_ActivateServer(1);
      if (sv == 0) {
        return;
      }
      if (cls != 0) {
        DAT_081b92cc = 0;
        for (iVar1 = 2; iVar2 = Cmd_Argc(), iVar1 < iVar2; iVar1 = iVar1 + 1) {
          __src = (char *)Cmd_Argv(iVar1);
          strcat(&DAT_081b92cc,__src);
          strcat(&DAT_081b92cc," ");
        }
      }
    }
    else {
      iVar1 = LoadGamestate(param_3,1);
      if (iVar1 == 0) {
        SV_LoadEntities();
      }
      DAT_0811d244 = 1;
      DAT_0811d248 = 1;
      SV_ActivateServer(0);
    }
    if (sv_gpNewUserMsgs != 0) {
      if (sv_gpUserMsgs == 0) {
        sv_gpUserMsgs = sv_gpNewUserMsgs;
      }
      else {
        iVar1 = *(int *)(sv_gpUserMsgs + 0x14);
        iVar2 = sv_gpUserMsgs;
        while (iVar1 != 0) {
          iVar2 = *(int *)(iVar2 + 0x14);
          iVar1 = *(int *)(iVar2 + 0x14);
        }
        *(int *)(iVar2 + 0x14) = sv_gpNewUserMsgs;
      }
      sv_gpNewUserMsgs = 0;
    }
    if (cls != 0) {
      Cmd_ExecuteString("connect local",1);
    }
  }
  return;
}


// Host_Map_f  @ 0805a9b0
void Host_Map_f(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char local_84 [64];
  char local_44 [64];
  
  if (cmd_source == 1) {
    local_44[0] = '\0';
    iVar5 = 0;
    while( true ) {
      iVar2 = Cmd_Argc();
      if (iVar2 <= iVar5) break;
      pcVar3 = (char *)Cmd_Argv(iVar5);
      strcat(local_44,pcVar3);
      strcat(local_44," ");
      iVar5 = iVar5 + 1;
    }
    strcat(local_44,"\n");
    pcVar3 = (char *)Cmd_Argv(1);
    strcpy(local_84,pcVar3);
    if (DAT_08166d0c == 0) {
      Host_InitializeGameDLL();
    }
    uVar4 = 0xffffffff;
    pcVar3 = local_84;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    if (4 < (int)(uVar4 - 1)) {
      iVar5 = Q_strcasecmp(local_84 + (uVar4 - 5),&DAT_080a0d95);
      if (iVar5 == 0) {
        local_84[uVar4 - 5] = '\0';
      }
    }
    iVar5 = PF_IsMapValid_I(local_84);
    if (iVar5 == 0) {
      Con_Printf("map change failed: \'");
      Con_Printf(local_84);
      Con_Printf("\' not found on server\n");
    }
    else {
      if ((1 < svs) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
        COM_CheckAuthenticationType();
      }
      Cvar_Set("HostMap",local_84);
      Host_Map(0,local_44,local_84,0);
    }
  }
  return;
}


// Host_Maps_f  @ 0805aaf0
void Host_Maps_f(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    pcVar2 = (char *)Cmd_Argv(1);
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      if (*pcVar2 == '*') {
        pcVar2 = (char *)0x0;
      }
      COM_ListMaps(pcVar2);
    }
  }
  else {
    Con_Printf("Usage:  maps <substring>\nmaps * for full listing\n");
  }
  return;
}


// Host_Noclip_f  @ 0805a4d0
void Host_Noclip_f(void)

{
  int iVar1;
  undefined1 local_28 [12];
  undefined1 local_1c [12];
  undefined1 local_10 [12];
  
  iVar1 = sv_player;
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if ((((byte)(0.0 < (float)gGlobalVariables._20_4_ |
                    (byte)((ushort)((ushort)NAN((float)gGlobalVariables._20_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)gGlobalVariables._20_4_ == 0.0) << 0xe) >> 8)) ==
             0x40) || (*(int *)(host_client + 0x3eb4) != 0)) && (allow_cheats != 0)) {
    if (*(int *)(sv_player + 0x1c4) == 8) {
      noclip_anglehack = 0;
      *(undefined4 *)(sv_player + 0x1c4) = 3;
      *(undefined4 *)(iVar1 + 0xf0) = *(undefined4 *)(iVar1 + 0xe4);
      *(undefined4 *)(iVar1 + 0xf4) = *(undefined4 *)(iVar1 + 0xe8);
      *(undefined4 *)(iVar1 + 0xf8) = *(undefined4 *)(iVar1 + 0xec);
      SV_ClientPrintf("noclip OFF\n");
      iVar1 = SV_TestEntityPosition(sv_player);
      if (iVar1 != 0) {
        AngleVectors(sv_player + 0x150,local_10,local_1c,local_28);
        iVar1 = FindPassableSpace(sv_player,local_10,0x3f800000);
        if (iVar1 == 0) {
          iVar1 = FindPassableSpace(sv_player,local_1c,0x3f800000);
          if (iVar1 == 0) {
            iVar1 = FindPassableSpace(sv_player,local_1c,0xbf800000);
            if (iVar1 == 0) {
              iVar1 = FindPassableSpace(sv_player,local_28,0x3f800000);
              if (iVar1 == 0) {
                iVar1 = FindPassableSpace(sv_player,local_28,0xbf800000);
                if (iVar1 == 0) {
                  iVar1 = FindPassableSpace(sv_player,local_10,0xbf800000);
                  if (iVar1 == 0) {
                    Con_DPrintf("Can\'t find the world\n");
                  }
                }
              }
            }
          }
        }
        iVar1 = sv_player;
        *(undefined4 *)(sv_player + 0xe4) = *(undefined4 *)(sv_player + 0xf0);
        *(undefined4 *)(iVar1 + 0xe8) = *(undefined4 *)(iVar1 + 0xf4);
        *(undefined4 *)(iVar1 + 0xec) = *(undefined4 *)(iVar1 + 0xf8);
      }
    }
    else {
      noclip_anglehack = 1;
      *(undefined4 *)(sv_player + 0x1c4) = 8;
      SV_ClientPrintf("noclip ON\n");
    }
  }
  return;
}


// Host_Notarget_f  @ 0805a3e0
void Host_Notarget_f(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = sv_player;
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (((byte)(0.0 < (float)gGlobalVariables._20_4_ |
                   (byte)((ushort)((ushort)NAN((float)gGlobalVariables._20_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)gGlobalVariables._20_4_ == 0.0) << 0xe) >> 8)) ==
            0x40) || (*(int *)(host_client + 0x3eb4) != 0)) {
    *(byte *)(sv_player + 0x260) = *(byte *)(sv_player + 0x260) ^ 0x80;
    if (*(char *)(iVar1 + 0x260) < '\0') {
      pcVar2 = "notarget ON\n";
    }
    else {
      pcVar2 = "notarget OFF\n";
    }
    SV_ClientPrintf(pcVar2);
  }
  return;
}


// Host_Notify_f  @ 0805f2c0
void Host_Notify_f(void)

{
  return;
}


// Host_Pause_f  @ 0805d9f0
void Host_Pause_f(void)

{
  int iVar1;
  char *pcVar2;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if ((byte)((byte)((ushort)((ushort)NAN((float)pausable._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)pausable._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
    SV_ClientPrintf("Pause not allowed.\n");
  }
  else {
    DAT_0811d244 = DAT_0811d244 ^ 1;
    if (DAT_0811d244 == 0) {
      iVar1 = *(int *)(sv_player + 0x28c);
      pcVar2 = "%s unpaused the game\n";
    }
    else {
      iVar1 = *(int *)(sv_player + 0x28c);
      pcVar2 = "%s paused the game\n";
    }
    SV_BroadcastPrintf(pcVar2,iVar1 + pr_strings);
    MSG_WriteByte(&DAT_081413f8,0x18);
    MSG_WriteByte(&DAT_081413f8,DAT_0811d244);
  }
  return;
}


// Host_PingServer_f  @ 0805f1e0
void Host_PingServer_f(void)

{
  uint16_t __hostshort;
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  undefined4 *puVar4;
  undefined4 auStack_58 [4];
  undefined4 uStack_48;
  char *pcStack_44;
  undefined4 uStack_40;
  char *apcStack_3c [4];
  undefined4 local_20 [4];
  uint16_t local_e;
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  
  apcStack_3c[3] = (char *)0x805f1ef;
  NET_Config();
  local_c = 0xffffffff;
  local_8 = 0x69;
  local_7 = 0;
  apcStack_3c[3] = (char *)0x805f203;
  apcStack_3c[3] = (char *)Cmd_Args();
  if ((apcStack_3c[3] == (char *)0x0) || (*apcStack_3c[3] == '\0')) {
    apcStack_3c[3] = (char *)0x805f21b;
    Con_Printf();
  }
  else {
    apcStack_3c[2] = (char *)0x805f22a;
    iVar1 = NET_StringToAdr();
    if (iVar1 == 0) {
      apcStack_3c[3] = "svping:  bad address %s\n";
      apcStack_3c[2] = (char *)0x805f23c;
      Con_Printf();
    }
    else {
      if (local_e == 0) {
        apcStack_3c[3] = (char *)0xa;
        apcStack_3c[2] = (char *)0x0;
        apcStack_3c[1] = "27015";
        apcStack_3c[0] = (char *)0x805f257;
        __hostshort = __strtol_internal();
        apcStack_3c[3] = (char *)0x805f261;
        local_e = htons(__hostshort);
      }
      pingstart = realtime;
      puVar2 = local_20;
      ppcVar3 = apcStack_3c;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar3 = (char *)*puVar2;
        puVar2 = puVar2 + 1;
        ppcVar3 = ppcVar3 + 1;
      }
      uStack_40 = 0x805f289;
      uStack_40 = NET_AdrToString();
      pcStack_44 = "Pinging %s\n";
      uStack_48 = 0x805f294;
      Con_Printf();
      puVar2 = local_20;
      puVar4 = auStack_58;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
      }
      NET_SendPacket(0,6,&local_c);
    }
  }
  return;
}


// Host_Ping_f  @ 0805a7a0
void Host_Ping_f(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    SV_ClientPrintf("Client ping times:\n");
    if (0 < svs) {
      iVar3 = 0;
      piVar2 = DAT_0816dd10;
      do {
        if (*piVar2 != 0) {
          uVar1 = SV_CalcPing(piVar2,(int)piVar2 + 0x5005);
          SV_ClientPrintf("%4i %s\n",uVar1);
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 0x14ae;
      } while (iVar3 < svs);
    }
  }
  return;
}


// Host_PostFrameRate  @ 08058c90
void Host_PostFrameRate(undefined4 param_1)

{
  g_fFrameTime = param_1;
  return;
}


// Host_PreSpawn_f  @ 0805daa0
void Host_PreSpawn_f(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (cmd_source == 1) {
    Con_Printf("prespawn is not valid from the console\n");
  }
  else if (*(int *)(host_client + 4) == 0) {
    if (DAT_081b9d98 == 0) {
      uVar1 = Cmd_Argv(1);
      iVar2 = __strtol_internal(uVar1,0,10,0);
      if (iVar2 != DAT_08166d08) {
        Con_Printf("SV_PreSpawn_f from different level\n");
        SV_New_f();
        return;
      }
    }
    uVar1 = Cmd_Argv(2);
    iVar2 = __strtol_internal(uVar1,0,10,0);
    if (DAT_08143788 <= iVar2) {
      iVar2 = 0;
    }
    SZ_Write(host_client + 0x78,&DAT_081437cc + iVar2 * 4000,(&DAT_0814378c)[iVar2]);
    if (iVar2 + 1 == DAT_08143788) {
      MSG_WriteByte(host_client + 0x78,0x19);
      MSG_WriteByte(host_client + 0x78,1);
      *(undefined4 *)(host_client + 0x3eb8) = 1;
    }
    else {
      MSG_WriteByte(host_client + 0x78,9);
      uVar1 = va("cmd prespawn %i %i\n",DAT_08166d08,iVar2 + 1);
      MSG_WriteString(host_client + 0x78,uVar1);
    }
  }
  else {
    Con_Printf("prespawn not valid -- already spawned\n");
  }
  return;
}


// Host_Protocol_f  @ 0805ef50
void Host_Protocol_f(void)

{
  int iVar1;
  char **ppcVar2;
  char *pcStack_10;
  char *pcStack_c;
  char *pcStack_8;
  
  pcStack_8 = (char *)0x805ef58;
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    if (sv != 0) {
      pcStack_8 = "protocol cannot be changed while a server is running.\n";
      pcStack_c = (char *)0x805ef83;
      Con_Printf();
      return;
    }
    if (1 < cls) {
      pcStack_8 = "protocol cannot be changed while in a game.\n";
      pcStack_c = (char *)0x805efa3;
      Con_Printf();
      return;
    }
    pcStack_8 = (char *)0x1;
    pcStack_c = (char *)0x805efb7;
    pcStack_c = (char *)Cmd_Argv();
    pcStack_10 = (char *)0x805efbd;
    pcStack_8 = (char *)Q_atoi();
    if (pcStack_8 + -0x23 < (char *)0x4) {
      pcStack_c = (char *)0x805efec;
      PROTOCOL_VERSION = pcStack_8;
      Protocol_Init();
      pcStack_c = PROTOCOL_VERSION;
      ppcVar2 = &pcStack_10;
      pcStack_10 = "protocol set to %i\n";
    }
    else {
      pcStack_8 = (char *)0x26;
      ppcVar2 = &pcStack_c;
      pcStack_c = "invalid protocol, valid protocols are 35 through %i\n";
    }
  }
  else {
    pcStack_8 = PROTOCOL_VERSION;
    ppcVar2 = &pcStack_c;
    pcStack_c = "protocol is %i\n";
  }
  *(undefined4 *)((int)ppcVar2 + -4) = 0x805effc;
  Con_Printf();
  return;
}


// Host_Quit_f  @ 08059e70
void Host_Quit_f(void)

{
  int iVar1;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    giActive = 3;
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


// Host_Reconnect_f  @ 0805ae40
void Host_Reconnect_f(void)

{
  if (2 < cls) {
    SCR_BeginLoadingPlaque();
    DAT_081b9180 = 0;
    cls = 3;
    MSG_WriteChar(&DAT_081b5328,4);
    MSG_WriteString(&DAT_081b5328,&DAT_080a0eb2);
  }
  return;
}


// Host_Reload_f  @ 0805add0
void Host_Reload_f(void)

{
  int iVar1;
  undefined1 local_108 [260];
  
  if (((DAT_081b9d98 == 0) && (sv != 0)) && (cmd_source == 1)) {
    Host_ClearGameState();
    SV_InactivateClients();
    iVar1 = Host_FindRecentSave(local_108);
    if ((iVar1 != 0) && (iVar1 = Host_Load(iVar1), iVar1 != 0)) {
      return;
    }
    SV_SpawnServer(0,gHostMap._4_4_,0);
    SV_LoadEntities();
    SV_ActivateServer(1);
  }
  return;
}


// Host_RemoteCommand  @ 08059d60
void Host_RemoteCommand(undefined4 *param_1)

{
  int iVar1;
  char *__src;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStackY_428;
  char local_404 [1024];
  
  iVar1 = Rcon_Validate();
  if (iVar1 == 0) {
    puVar3 = param_1;
    puVar4 = &uStackY_428;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    NET_AdrToString();
    Con_Printf();
  }
  if (iVar1 == 1) {
    puVar3 = &uStackY_428;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    NET_AdrToString();
    Con_Printf();
  }
  Host_BeginRedirect();
  if (iVar1 == 0) {
    Con_Printf();
  }
  else {
    local_404[0] = '\0';
    iVar1 = 2;
    while( true ) {
      iVar2 = Cmd_Argc();
      if (iVar2 <= iVar1) break;
      __src = (char *)Cmd_Argv();
      strcat(local_404,__src);
      uStackY_428 = 0x8059e38;
      strcat(local_404," ");
      iVar1 = iVar1 + 1;
    }
    Cmd_ExecuteString();
  }
  Host_EndRedirect();
  return;
}


// Host_RequestMOTD_f  @ 08059ab0
void Host_RequestMOTD_f(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int aiStack_83c [3];
  char *pcStack_830;
  undefined4 uStack_82c;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  char local_804 [2048];
  
  if ((gfNoMasterServer == 0) && (valvemaster_adr != 0)) {
    uStack_81c = 1;
    uStack_820 = 0x8059add;
    NET_Config();
    uStack_820 = 0x67;
    uStack_82c = 0x8059af0;
    sprintf(local_804,"%c\n");
    iVar5 = valvemaster_adr;
    puVar6 = (undefined4 *)(valvemaster_adr + 0x18);
    piVar7 = aiStack_83c;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      piVar7 = piVar7 + 1;
    }
    uVar2 = NET_AdrToString();
    Con_DPrintf("Requesting MOTD from master(s)\n",uVar2);
    if (iVar5 != 0) {
      do {
        puVar6 = (undefined4 *)(iVar5 + 0x18);
        puVar8 = &uStack_82c;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        uVar4 = 0xffffffff;
        pcVar9 = local_804;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        aiStack_83c[2] = ~uVar4 - 1;
        aiStack_83c[1] = 0;
        aiStack_83c[0] = 0x8059b5c;
        pcStack_830 = local_804;
        NET_SendPacket();
        iVar5 = *(int *)(iVar5 + 0x2c);
      } while (iVar5 != 0);
    }
  }
  return;
}


// Host_Restart_f  @ 0805ad70
void Host_Restart_f(void)

{
  char local_108 [260];
  
  if (((DAT_081b9d98 == 0) && (sv != 0)) && (cmd_source == 1)) {
    Host_ClearGameState();
    SV_InactivateClients();
    strcpy(local_108,&DAT_0811d260);
    SV_SpawnServer(0,local_108,0);
    SV_LoadEntities();
    SV_ActivateServer(1);
  }
  return;
}


// Host_SaveAgeList  @ 0805b090
void Host_SaveAgeList(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  char local_20c [260];
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory(param_1,param_2);
  sprintf(local_108,"%s%s%02d.sav",uVar1);
  COM_FixSlashes(local_108);
  Sys_Unlink(local_108);
  if (0 < param_2) {
    do {
      if (param_2 == 1) {
        uVar1 = Host_SaveGameDirectory(param_1);
        sprintf(local_20c,"%s%s.sav",uVar1);
      }
      else {
        uVar1 = Host_SaveGameDirectory(param_1,param_2 + -1);
        sprintf(local_20c,"%s%s%02d.sav",uVar1);
      }
      COM_FixSlashes(local_20c);
      uVar1 = Host_SaveGameDirectory(param_1,param_2);
      sprintf(local_108,"%s%s%02d.sav",uVar1);
      COM_FixSlashes(local_108);
      rename(local_20c,local_108);
      param_2 = param_2 + -1;
    } while (0 < param_2);
  }
  return;
}


// Host_SaveGameDirectory  @ 0805af00
undefined4 * Host_SaveGameDirectory(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &szDirectory_148;
  for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  sprintf((char *)&szDirectory_148,"%s/SAVE/",com_gamedir);
  return &szDirectory_148;
}


// Host_SavegameComment  @ 0805af40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_SavegameComment(char *param_1)

{
  char cVar1;
  char *__s1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  ushort in_FPUStatusWord;
  longdouble lVar6;
  longdouble lVar7;
  char *local_54;
  char local_44 [64];
  
  local_54 = (char *)0x0;
  __s1 = (char *)(gGlobalVariables._12_4_ + pr_strings);
  uVar4 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar5 = (&gTitleComments)[uVar4 * 2];
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar2 = strncasecmp(__s1,(&gTitleComments)[uVar4 * 2],~uVar3 - 1);
    if ((iVar2 == 0) && (iVar2 = TextMessageGet((&PTR_s_T0A0TITLE_080aac04)[uVar4 * 2]), iVar2 != 0)
       ) {
      local_54 = local_44;
      strncpy(local_54,*(char **)(iVar2 + 0x28),0x40);
      iVar2 = 0;
      do {
        if (local_54[iVar2] == '\0') break;
        if ((local_54[iVar2] == '\n') || (local_54[iVar2] == '\r')) {
          local_54[iVar2] = '\0';
        }
        else {
          iVar2 = iVar2 + 1;
        }
      } while (iVar2 < 0x40);
    }
    uVar4 = uVar4 + 1;
  } while ((uVar4 < 0x1b) && (local_54 == (char *)0x0));
  if (local_54 == (char *)0x0) {
    iVar2 = -1;
    pcVar5 = cl + 0x21c9c;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    local_54 = __s1;
    if (iVar2 != -2) {
      local_54 = cl + 0x21c9c;
    }
  }
  lVar6 = (longdouble)60.0;
  lVar7 = (longdouble)_DAT_0811d24c;
  do {
    lVar7 = lVar7 - (longdouble)(unkint10)(lVar7 / lVar6) * lVar6;
  } while ((in_FPUStatusWord & 0x400) != 0);
  sprintf(param_1,"%-64.64s %02d:%02d",local_54,(int)ROUND((longdouble)_DAT_0811d24c / lVar6),
          (int)ROUND(lVar7));
  return;
}


// Host_Savegame_f  @ 0805b660
void Host_Savegame_f(void)

{
  return;
}


// Host_Say  @ 0805d6c0
void Host_Say(void)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char *__src;
  int *piVar6;
  char local_44;
  undefined1 local_43 [63];
  
  if (cls == 0) {
    iVar2 = Cmd_Argc();
    if (1 < iVar2) {
      pcVar3 = (char *)Cmd_Args();
      uVar1 = host_client;
      if (pcVar3 != (char *)0x0) {
        __src = pcVar3;
        if (*pcVar3 == '\"') {
          __src = pcVar3 + 1;
          iVar2 = Q_strlen(__src);
          pcVar3[iVar2] = '\0';
        }
        sprintf(&local_44,"%c<%s> ",1,hostname._4_4_);
        iVar2 = Q_strlen(&local_44);
        iVar4 = Q_strlen(__src);
        if (0x3e - iVar2 < iVar4) {
          __src[0x3e - iVar2] = '\0';
        }
        strcat(&local_44,__src);
        strcat(&local_44,"\n");
        iVar2 = 0;
        piVar6 = DAT_0816dd10;
        if (0 < svs) {
          do {
            if (((piVar6 != (int *)0x0) && (*piVar6 != 0)) && (piVar6[1] != 0)) {
              host_client = piVar6;
              uVar5 = RegUserMsg("SayText",0xffffffff,0,DAT_0814043c + 0x2c8 + iVar2 * 0x2c8);
              PF_MessageBegin_I(1,uVar5);
              PF_WriteByte_I(0);
              PF_WriteString_I(&local_44);
              PF_MessageEnd_I();
            }
            iVar2 = iVar2 + 1;
            piVar6 = piVar6 + 0x14ae;
          } while (iVar2 < svs);
        }
        host_client = (int *)uVar1;
        Sys_Printf(&DAT_080a0e9f,local_43);
      }
    }
  }
  else if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  return;
}


// Host_Say_Team_f  @ 0805d830
void Host_Say_Team_f(void)

{
  Host_Say(1);
  return;
}


// Host_Say_f  @ 0805d820
void Host_Say_f(void)

{
  Host_Say(0);
  return;
}


// Host_ServerFrame  @ 08058040
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_ServerFrame(void)

{
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    Sys_FloatTime();
  }
  gGlobalVariables._4_4_ = (undefined4)host_frametime;
  SV_ReadPackets();
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    Sys_FloatTime();
  }
  if ((DAT_0811d244 == 0) && ((1 < svs || ((key_dest == 0 && ((cls == 5 || (cls == 0)))))))) {
    SV_Physics();
  }
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    Sys_FloatTime();
  }
  SV_QueryMovevarsChanged();
  SV_SendClientMessages();
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    Sys_FloatTime();
  }
  SV_RequestMissingResourcesFromClients();
  Master_Heartbeat();
  if ((byte)(0.0 < (float)host_killtime._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_killtime._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_killtime._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((double)(float)host_killtime._12_4_ < _DAT_0811d24c) {
      Host_Quit_f();
    }
  }
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    Sys_FloatTime();
  }
  return;
}


// Host_SetInfo_f  @ 0805d5f0
void Host_SetInfo_f(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Info_Print(&DAT_081b9acc);
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      if (cmd_source == 1) {
        uVar2 = Cmd_Argv(2,0xc4);
        uVar2 = Cmd_Argv(1,uVar2);
        Info_SetValueForKey(&DAT_081b9acc,uVar2);
        Cmd_ForwardToServer();
      }
      else {
        uVar2 = Cmd_Argv(2,0xc4);
        uVar2 = Cmd_Argv(1,uVar2);
        Info_SetValueForKey(host_client + 0x4f18,uVar2);
        iVar1 = host_client;
        *(undefined4 *)(host_client + 0x4fdc) = 1;
        SV_ExtractFromUserinfo(iVar1);
      }
    }
    else {
      Con_Printf("usage: setinfo [ <key> <value> ]\n");
    }
  }
  return;
}


// Host_Shutdown  @ 08059940
void Host_Shutdown(void)

{
  int iVar1;
  int iVar2;
  
  if (isdown_189 == 0) {
    isdown_189 = 1;
    if (host_initialized != 0) {
      Host_WriteConfiguration();
    }
    host_initialized = 0;
    HPAK_FlushHostQueue();
    SV_DeallocateDynamicData();
    iVar1 = 0;
    iVar2 = DAT_0816dd10;
    if (0 < DAT_08166d04) {
      do {
        SV_ClearFrames(iVar2 + 0x4f04);
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x52b8;
      } while (iVar1 < DAT_08166d04);
    }
    Master_Shutdown(1);
    scr_disabled_for_loading = 1;
    NET_Shutdown();
    S_Shutdown();
    IN_Shutdown();
    Con_Shutdown();
    if (cls != 0) {
      (*VID_Shutdown)();
    }
    ReleaseEntityDlls();
    CL_ShutDownClientStatic();
    CM_FreePAS();
    if (wadpath != (void *)0x0) {
      free(wadpath);
    }
    wadpath = (void *)0x0;
    if (cls != 0) {
      Draw_Shutdown();
    }
    Draw_DecalShutdown();
    WON_ShutdownAuthentication();
    Log_Printf("Server shutdown.\n");
    Log_Close();
    COM_Shutdown();
  }
  else {
    printf("recursive shutdown\n");
  }
  return;
}


// Host_ShutdownServer  @ 08057ba0
void Host_ShutdownServer(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (sv != 0) {
    sv = 0;
    if ((((cls == 5) || (cls == 3)) || (cls == 4)) || (cls == 2)) {
      CL_Disconnect();
    }
    iVar1 = 0;
    host_client = DAT_0816dd10;
    if (0 < svs) {
      do {
        if (((*host_client != 0) || (host_client[2] != 0)) && (host_client[0xfb0] == 0)) {
          SV_DropClient(host_client,param_1);
        }
        iVar1 = iVar1 + 1;
        host_client = host_client + 0x14ae;
      } while (iVar1 < svs);
    }
    SV_ClearEntities();
    puVar2 = &sv;
    for (iVar1 = 0xd7e3; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    CL_ClearClientState();
    SV_ClearClientStates();
    Host_ClearClients(0);
    iVar1 = 0;
    host_client = DAT_0816dd10;
    if (0 < DAT_08166d04) {
      do {
        SV_ClearFrames(host_client + 0x13c1);
        iVar1 = iVar1 + 1;
        host_client = host_client + 0x14ae;
      } while (iVar1 < DAT_08166d04);
    }
    memset(DAT_0816dd10,0,DAT_08166d04 * 0x52b8);
    Master_Shutdown(0);
    HPAK_FlushHostQueue();
    Log_Printf("Server shutdown.\n");
    Log_Close();
  }
  return;
}


// Host_Soundfade_f  @ 0805ed30
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_Soundfade_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  iVar1 = Cmd_Argc();
  if ((iVar1 != 3) && (iVar1 = Cmd_Argc(), iVar1 != 5)) {
    Con_Printf("soundfade <percent> <hold> [<out> <int>]\n");
    return;
  }
  uVar2 = Cmd_Argv(1);
  iVar3 = __strtol_internal(uVar2,0,10,0);
  iVar1 = 100;
  if (iVar3 < 0x65) {
    iVar1 = iVar3;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  uVar2 = Cmd_Argv(2);
  local_8 = __strtol_internal(uVar2,0,10,0);
  if (0xff < local_8) {
    local_8 = 0xff;
  }
  iVar4 = 0;
  iVar5 = 0;
  iVar3 = Cmd_Argc();
  if (iVar3 == 5) {
    uVar2 = Cmd_Argv(3);
    iVar5 = __strtol_internal(uVar2,0,10,0);
    if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    uVar2 = Cmd_Argv(4);
    iVar4 = __strtol_internal(uVar2,0,10,0);
    if (0xff < iVar4) {
      iVar4 = 0xff;
    }
  }
  _DAT_081ba038 = iVar4;
  _DAT_081ba034 = local_8;
  _DAT_081ba030 = iVar5;
  _DAT_081ba028 = realtime;
  _DAT_081ba020 = iVar1;
  return;
}


// Host_Spawn_f  @ 0805dbf0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_Spawn_f(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_678 [9];
  int local_654;
  undefined1 local_64c [1352];
  char local_104 [256];
  
  if (cmd_source == 1) {
    Con_Printf("spawn is not valid from the console\n");
  }
  else if (*(int *)(host_client + 8) == 0) {
    Con_Printf("Spawn not valid -- already spawned\n");
  }
  else {
    uVar1 = Cmd_Argv(1);
    iVar2 = __strtol_internal(uVar1,0,10,0);
    if ((DAT_081b9d98 == 0) && (iVar2 != DAT_08166d08)) {
      Con_Printf("SV_Spawn_f from different level\n");
      SV_New_f();
    }
    else {
      if (DAT_0811d248 == 0) {
        iVar2 = *(int *)(host_client + 0x4f08);
        DAT_08140440 = 1;
        ReleaseEntityDLLFields(iVar2);
        puVar4 = (undefined4 *)(iVar2 + 0xdc);
        for (iVar3 = 0x7b; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        InitEntityDLLFields(iVar2);
        uVar1 = NUM_FOR_EDICT(iVar2);
        *(undefined4 *)(iVar2 + 0x264) = uVar1;
        *(int *)(iVar2 + 0x28c) = host_client - (pr_strings + -0x5005);
        gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
        (*DAT_08178ee8)(sv_player);
        DAT_08140440 = 2;
      }
      else {
        DAT_0811d244 = 0;
      }
      SZ_Clear(host_client + 0x78);
      MSG_WriteByte(host_client + 0x78,7);
      MSG_WriteFloat(host_client + 0x78,(float)_DAT_0811d24c);
      iVar3 = 0;
      iVar2 = DAT_0816dd10;
      if (0 < svs) {
        do {
          SV_FullClientUpdate(iVar2,host_client + 0x78);
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + 0x52b8;
        } while (iVar3 < svs);
      }
      iVar2 = 0;
      do {
        MSG_WriteByte(host_client + 0x78,0xc);
        MSG_WriteByte(host_client + 0x78,(int)(char)iVar2);
        MSG_WriteString(host_client + 0x78,(&DAT_08140334)[iVar2]);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x40);
      iVar2 = DAT_0814043c + ((host_client - DAT_0816dd10) * -0x54557e99 >> 3) * 0x2c8;
      MSG_WriteByte(host_client + 0x78,10);
      iVar3 = 0;
      do {
        MSG_WriteHiresAngle(host_client + 0x78,*(undefined4 *)(iVar2 + 0x418 + iVar3 * 4));
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
      MSG_WriteHiresAngle(host_client + 0x78,0);
      SV_WriteClientdataToMessage(host_client,host_client + 0x78);
      MSG_WriteByte(host_client + 0x78,0x19);
      MSG_WriteByte(host_client + 0x78,2);
      *(undefined4 *)(host_client + 0x3eb8) = 1;
      if (DAT_0811d248 != 0) {
        puVar4 = local_678;
        for (iVar2 = 0x15d; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        gGlobalVariables._156_4_ = local_678;
        (*DAT_08178f08)();
        MSG_WriteByte(host_client + 0x78,0x21);
        uVar1 = Host_SaveGameDirectory(&DAT_0811d260);
        sprintf(local_104,"%s%s.HL2",uVar1);
        COM_FixSlashes(local_104);
        MSG_WriteString(host_client + 0x78,local_104);
        MSG_WriteByte(host_client + 0x78,local_654);
        iVar2 = 0;
        if (0 < local_654) {
          do {
            MSG_WriteString(host_client + 0x78,local_64c + iVar2 * 0x50);
            iVar2 = iVar2 + 1;
          } while (iVar2 < local_654);
        }
        DAT_0811d248 = 0;
        gGlobalVariables._156_4_ = 0;
      }
    }
  }
  return;
}


// Host_Speeds  @ 08058d30
void Host_Speeds(double param_1,double param_2,double param_3,double param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  float local_24;
  
  lVar6 = (longdouble)1000.0;
  fVar1 = (float)(((longdouble)param_2 - (longdouble)param_1) * lVar6);
  fVar2 = (float)(((longdouble)param_3 - (longdouble)param_2) * lVar6);
  fVar3 = (float)(((longdouble)param_4 - (longdouble)param_3) * lVar6);
  local_24 = fVar1 + fVar2 + fVar3;
  if (1.0 <= local_24) {
    local_24 = 1000.0 / local_24;
  }
  else {
    local_24 = 100.0;
  }
  Host_PostFrameRate(local_24);
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar4 = 0;
    iVar5 = 0;
    if (0 < DAT_08140434) {
      do {
        if (*(int *)(DAT_0814043c + iVar5 * 0x2c8) == 0) {
          iVar4 = iVar4 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_08140434);
    }
    Con_DPrintf("%3i fps -- sv(%3.0f) gfx(%3.0f) snd(%3.0f) ents(%d)\n",(int)ROUND(local_24),
                (double)fVar1,(double)fVar2,(double)fVar3,iVar4);
  }
  return;
}


// Host_Startdemos_f  @ 0805e4e0
void Host_Startdemos_f(void)

{
  int iVar1;
  char *__src;
  int iVar2;
  size_t __n;
  
  if (cls == 0) {
    if (sv == 0) {
      Con_Printf("Cannot play demos on a dedicated server.\n");
    }
  }
  else {
    iVar1 = Cmd_Argc();
    iVar1 = iVar1 + -1;
    if (0x20 < iVar1) {
      Con_Printf("Max %i demos in demoloop\n",0x20);
      iVar1 = 0x20;
    }
    Con_Printf("%i demo(s) in loop\n",iVar1);
    iVar2 = 1;
    if (1 < iVar1 + 1) {
      do {
        __n = 0xf;
        __src = (char *)Cmd_Argv(iVar2);
        strncpy(&DAT_081b9b84 + iVar2 * 0x10,__src,__n);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1 + 1);
    }
    if (((sv == 0) && (DAT_081b9b90 != -1)) && (DAT_081b9d98 == 0)) {
      DAT_081b9b90 = 0;
      CL_NextDemo();
    }
    else {
      DAT_081b9b90 = -1;
    }
  }
  return;
}


// Host_Status_PrintClient  @ 08059ed0
void Host_Status_PrintClient(char *param_1,int param_2,code *param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined8 *puVar6;
  char *pcVar7;
  undefined8 local_38;
  char *pcStack_30;
  undefined8 local_2c;
  
  iVar5 = (int)ROUND((float)realtime - *(float *)(param_5 + 0x34));
  iVar3 = iVar5 / 0x3c;
  if (iVar3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar5 = iVar5 % 0x3c;
    iVar2 = iVar3 / 0x3c;
    if (iVar2 != 0) {
      iVar3 = iVar3 % 0x3c;
    }
  }
  local_2c = (double)CONCAT44(param_5 + 0x5005,param_4 + 1);
  pcStack_30 = "#%-2u %-12.12s\n";
  local_38 = (double)CONCAT44(0x8059f6b,(undefined4)local_38);
  (*param_3)();
  local_38 = (double)CONCAT44((int)ROUND(*(float *)(*(int *)(param_5 + 0x4f08) + 0x220)),
                              "   frags:  %3i\n");
  (*param_3)();
  if (iVar2 == 0) {
    local_2c = (double)CONCAT44(iVar5,iVar3);
    pcStack_30 = "   time :  %02i:%02i\n";
    local_38 = (double)CONCAT44(0x8059fcc,(undefined4)local_38);
    (*param_3)();
  }
  else {
    local_2c = (double)CONCAT44(iVar5,iVar3);
    local_38 = 6.162031115149059e-270;
    pcStack_30 = (char *)iVar2;
    (*param_3)();
  }
  local_2c = (double)*(float *)(param_5 + 0x3c);
  pcStack_30 = "   frame rate :  %.2f fps\n";
  local_38 = (double)CONCAT44(0x8059fe5,(undefined4)local_38);
  (*param_3)();
  local_38 = (double)*(float *)(param_5 + 0x38);
  (*param_3)("   frame latency :  %.1f frames\n");
  uVar1 = SV_CalcPing(param_5);
  (*param_3)("   ping :  %4i\n",uVar1);
  local_2c = ((double)*(int *)(param_5 + 0x40) * 100.0) / (double)*(int *)(param_5 + 0x5c);
  pcStack_30 = "   drop :  %5.2f %%\n";
  local_38 = (double)CONCAT44(0x805a037,(undefined4)local_38);
  (*param_3)();
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    local_2c = (double)CONCAT44(param_1,"   %s\n");
    pcStack_30 = (char *)0x805a053;
    (*param_3)();
  }
  if (*(int *)(param_5 + 0x3ebc) == 0) {
    if (*(int *)(param_5 + 0x3ec0) != 0) {
      local_2c = 6.16272792017835e-270;
      (*param_3)();
      goto LAB_0805a0de;
    }
    if (param_2 == 0) goto LAB_0805a0de;
    puVar4 = (undefined4 *)(param_5 + 0x14);
    puVar6 = &local_38;
    for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined4 *)puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = (undefined8 *)((int)puVar6 + 4);
    }
    uVar1 = NET_BaseAdrToString();
    pcVar7 = "   %s\n";
  }
  else {
    puVar4 = (undefined4 *)(param_5 + 0x14);
    puVar6 = &local_38;
    for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined4 *)puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = (undefined8 *)((int)puVar6 + 4);
    }
    uVar1 = NET_BaseAdrToString();
    pcVar7 = "  (spectator) %s\n";
  }
  (*param_3)(pcVar7,uVar1);
LAB_0805a0de:
  local_2c = 6.1627640240659225e-270;
  (*param_3)();
  return;
}


// Host_Status_f  @ 0805a100
void Host_Status_f(void)

{
  undefined4 uVar1;
  char *__s1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  undefined2 in_FPUControlWord;
  char *apcStack_3c [2];
  code *pcStack_34;
  char *__s2;
  code *local_1c;
  char *local_18;
  int local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  if (cmd_source == 1) {
    if (sv == 0) {
      Cmd_ForwardToServer();
      return;
    }
    local_1c = Con_Printf;
  }
  else {
    local_1c = SV_ClientPrintf;
  }
  Cvar_VariableString();
  pcStack_34 = (code *)0x80a0be1;
  apcStack_3c[1] = (char *)0x805a15c;
  (*local_1c)();
  apcStack_3c[1] = gpszVersionString;
  apcStack_3c[0] = "version :  %s\n";
  (*local_1c)();
  uVar1 = build_number();
  (*local_1c)("build   :  %d\n",uVar1);
  if (noip == 0) {
    puVar4 = &net_local_adr;
    ppcVar5 = apcStack_3c;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar5 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    uVar1 = NET_AdrToString();
    (*local_1c)("tcp/ip  :  %s\n",uVar1);
  }
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  pcStack_34 = (code *)(int)ROUND((float)r_origin._0_4_);
  apcStack_3c[1] = &DAT_0811d260;
  apcStack_3c[0] = " map     :  %s at: %d x, %d y, %d z\n";
  local_10 = (int)pcStack_34;
  (*local_1c)();
  SV_CountPlayers(&local_18,&local_14);
  if (local_14 == 0) {
    pcStack_34 = (code *)0x80a0ca0;
    apcStack_3c[1] = (char *)0x805a264;
    (*local_1c)();
  }
  else {
    pcStack_34 = (code *)local_18;
    apcStack_3c[1] = " players: %i active (%i spectators) (%i max)\n\n";
    apcStack_3c[0] = (char *)0x805a244;
    (*local_1c)();
  }
  iVar2 = Cmd_Argc();
  if (iVar2 == 2) {
    __s2 = "short";
    pcStack_34 = (code *)0x805a27d;
    __s1 = (char *)Cmd_Argv();
    pcStack_34 = (code *)0x805a286;
    iVar2 = strcasecmp(__s1,__s2);
    if (iVar2 == 0) {
      if (svs < 1) {
        return;
      }
      iVar2 = 0;
      piVar3 = DAT_0816dd10;
      do {
        if (*piVar3 != 0) {
          pcStack_34 = (code *)0x80a0cc5;
          apcStack_3c[1] = (char *)0x805a2be;
          (*local_1c)();
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 0x14ae;
      } while (iVar2 < svs);
      return;
    }
  }
  iVar2 = 0;
  piVar3 = DAT_0816dd10;
  if (0 < svs) {
    do {
      if (*piVar3 == 0) {
        if (piVar3[2] != 0) {
          apcStack_3c[0] = "CONNECTING";
          goto LAB_0805a338;
        }
      }
      else {
        apcStack_3c[0] = (char *)0x0;
LAB_0805a338:
        apcStack_3c[1] = (char *)(uint)(cmd_source == 1);
        pcStack_34 = local_1c;
        Host_Status_PrintClient();
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x14ae;
    } while (iVar2 < svs);
  }
  return;
}


// Host_Stopdemo_f  @ 0805e5f0
void Host_Stopdemo_f(void)

{
  if ((cls != 0) && (DAT_081b9d98 != 0)) {
    CL_StopPlayback();
    CL_Disconnect();
  }
  return;
}


// Host_Tell_f  @ 0805d840
void Host_Tell_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *__src;
  int *piVar6;
  char local_44 [64];
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
    iVar3 = (int)host_client;
  }
  else {
    iVar1 = Cmd_Argc();
    iVar3 = (int)host_client;
    if (2 < iVar1) {
      Q_strcpy(local_44,(int)host_client + 0x5005);
      Q_strcat(local_44,&DAT_080a1452);
      pcVar2 = (char *)Cmd_Args();
      iVar3 = (int)host_client;
      if (pcVar2 != (char *)0x0) {
        __src = pcVar2;
        if (*pcVar2 == '\"') {
          __src = pcVar2 + 1;
          iVar3 = Q_strlen(__src);
          pcVar2[iVar3] = '\0';
        }
        iVar3 = Q_strlen(local_44);
        iVar1 = Q_strlen(__src);
        if (0x3e - iVar3 < iVar1) {
          __src[0x3e - iVar3] = '\0';
        }
        strcat(local_44,__src);
        strcat(local_44,"\n");
        iVar3 = (int)host_client;
        if (0 < svs) {
          iVar1 = 0;
          piVar6 = DAT_0816dd10;
          do {
            if ((*piVar6 != 0) && (piVar6[1] != 0)) {
              uVar4 = Cmd_Argv(1);
              iVar5 = Q_strcasecmp((int)piVar6 + 0x5005,uVar4);
              if (iVar5 == 0) {
                host_client = piVar6;
                SV_ClientPrintf(&DAT_080a0e9f,local_44);
                host_client = (int *)iVar3;
                return;
              }
            }
            iVar1 = iVar1 + 1;
            piVar6 = piVar6 + 0x14ae;
          } while (iVar1 < svs);
        }
      }
    }
  }
  host_client = (int *)iVar3;
  return;
}


// Host_ValidGame  @ 0805a740
undefined4 Host_ValidGame(void)

{
  int iVar1;
  
  if (svs < 2) {
    if ((Launcher_IsValidCD != (code *)0x0) && (iVar1 = (*Launcher_IsValidCD)(), iVar1 != 0)) {
      return 1;
    }
  }
  else if ((byte)(0.0 < (float)deathmatch._12_4_ |
                  (byte)((ushort)((ushort)NAN((float)deathmatch._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)deathmatch._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    return 1;
  }
  Con_DPrintf("Unable to launch game\n");
  return 0;
}


// Host_ValidSave  @ 0805b160
undefined4 Host_ValidSave(void)

{
  char *pcVar1;
  
  if (cmd_source == 1) {
    if (sv == 0) {
      pcVar1 = "Not playing a local game.\n";
    }
    else if ((cl._134244_4_ == 0) && (cls == 5)) {
      if (svs == 1) {
        if ((*DAT_0816dd10 == 0) || (0.0 < *(float *)(DAT_0816dd10[0x13c2] + 0x21c))) {
          return 1;
        }
        pcVar1 = "Can\'t savegame with a dead player\n";
      }
      else {
        pcVar1 = "Can\'t save multiplayer games.\n";
      }
    }
    else {
      pcVar1 = "Can\'t save in intermission.\n";
    }
    Con_Printf(pcVar1);
  }
  return 0;
}


// Host_Version_f  @ 0805d490
void Host_Version_f(void)

{
  undefined4 uVar1;
  
  uVar1 = build_number();
  Con_Printf("Build %d\n",uVar1);
  Con_Printf("Exe: 10:48:20 May  6 1999\n");
  return;
}


// Host_Viewframe_f  @ 0805e310
void Host_Viewframe_f(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FindViewthing();
  if (iVar2 != 0) {
    iVar1 = *(int *)(cl + *(int *)(iVar2 + 0x170) * 4 + 0x20c9c);
    uVar3 = Cmd_Argv(1);
    iVar4 = __strtol_internal(uVar3,0,10,0);
    if (*(int *)(iVar1 + 0x48) <= iVar4) {
      iVar4 = *(int *)(iVar1 + 0x48) + -1;
    }
    *(float *)(iVar2 + 0x1ec) = (float)iVar4;
  }
  return;
}


// Host_Viewmodel_f  @ 0805e2a0
void Host_Viewmodel_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FindViewthing();
  if (iVar1 != 0) {
    uVar2 = Cmd_Argv(1,0);
    iVar3 = Mod_ForName(uVar2);
    if (iVar3 == 0) {
      uVar2 = Cmd_Argv(1);
      Con_Printf("Can\'t load %s\n",uVar2);
    }
    else {
      *(undefined4 *)(iVar1 + 0x1ec) = 0;
      *(int *)(cl + *(int *)(iVar1 + 0x170) * 4 + 0x20c9c) = iVar3;
    }
  }
  return;
}


// Host_Viewnext_f  @ 0805e3b0
void Host_Viewnext_f(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined1 in_FPUControlWord;
  
  iVar3 = FindViewthing();
  if (iVar3 != 0) {
    iVar1 = *(int *)(cl + *(int *)(iVar3 + 0x170) * 4 + 0x20c9c);
    fVar2 = *(float *)(iVar3 + 0x1ec) + 1.0;
    *(float *)(iVar3 + 0x1ec) = fVar2;
    if ((float)*(int *)(iVar1 + 0x48) <= fVar2) {
      *(float *)(iVar3 + 0x1ec) = (float)(*(int *)(iVar1 + 0x48) + -1);
    }
    PrintFrameName(iVar1,(int)ROUND(*(float *)(iVar3 + 0x1ec)),(int)ROUND(*(float *)(iVar3 + 0x1ec))
                   ,CONCAT11(0xc,in_FPUControlWord));
  }
  return;
}


// Host_Viewprev_f  @ 0805e430
void Host_Viewprev_f(void)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  undefined1 in_FPUControlWord;
  
  iVar3 = FindViewthing();
  if (iVar3 != 0) {
    uVar1 = *(undefined4 *)(cl + *(int *)(iVar3 + 0x170) * 4 + 0x20c9c);
    fVar2 = *(float *)(iVar3 + 0x1ec) - 1.0;
    *(float *)(iVar3 + 0x1ec) = fVar2;
    if (fVar2 < 0.0) {
      *(undefined4 *)(iVar3 + 0x1ec) = 0;
    }
    PrintFrameName(uVar1,(int)ROUND(*(float *)(iVar3 + 0x1ec)),(int)ROUND(*(float *)(iVar3 + 0x1ec))
                   ,CONCAT11(0xc,in_FPUControlWord));
  }
  return;
}


// Host_WC_f  @ 0805ed10
void Host_WC_f(void)

{
  Con_DPrintf("\'WC\' is only available under the Windows OS\n");
  return;
}


// Host_WriteConfiguration  @ 08057760
void Host_WriteConfiguration(void)

{
  return;
}


