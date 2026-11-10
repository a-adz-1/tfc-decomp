// Host_AutoSave_f  @ 0005992c
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


// Host_Changelevel2_f  @ 0005bbd8
void Host_Changelevel2_f(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char local_c4 [64];
  undefined1 local_84 [64];
  undefined1 local_44 [64];
  
  giActive = 4;
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    pcVar3 = "changelevel2 <levelname> : continue game on a new level in the unit\n";
LAB_0005bc3e:
    Con_Printf(pcVar3);
    return;
  }
  if (((sv == 0) || (DAT_003855a4 != 0)) || (DAT_00153584 != 0)) {
    pcVar3 = "Only the server may changelevel\n";
    goto LAB_0005bc3e;
  }
  SCR_BeginLoadingPlaque();
  S_StopAllSounds(1);
  uVar2 = Cmd_Argv(1);
  Q_strcpy(local_44,uVar2);
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    uVar2 = Cmd_Argv(2);
    pcVar3 = local_c4;
    Q_strcpy(pcVar3,uVar2);
    if (local_c4[0] != '\0') goto LAB_0005bc9e;
  }
  pcVar3 = (char *)0x0;
LAB_0005bc9e:
  Q_strcpy(local_84,&DAT_001535a8);
  uVar2 = SaveGamestate();
  SV_ServerShutdown();
  iVar1 = SV_SpawnServer(0,local_44,pcVar3);
  if (iVar1 == 0) {
    Sys_Error("Couldn\'t load map %s\n",local_44);
    return;
  }
  SaveExit(uVar2);
  iVar1 = LoadGamestate(local_44,0);
  if (iVar1 == 0) {
    SV_LoadEntities();
  }
  LoadAdjacentEntities(local_84,pcVar3);
  DAT_00153584 = 1;
  DAT_00153588 = 1;
  gGlobalVariables = (float)DAT_0015358c;
  if ((iVar1 == 0) &&
     ((byte)((float)sv_newunit._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)sv_newunit._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_newunit._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    Host_ClearSaveDirectory();
  }
  SV_ActivateServer(0);
  return;
}


// Host_Changelevel_f  @ 00058ccc
void Host_Changelevel_f(void)

{
  int iVar1;
  char *pcVar2;
  undefined1 **ppuVar3;
  undefined1 *puVar4;
  undefined1 *puStack_9c;
  undefined1 *puStack_98;
  char *pcStack_94;
  undefined1 local_84 [64];
  undefined1 local_44 [64];
  
  ppuVar3 = (undefined1 **)&stack0xffffff70;
  pcStack_94 = (char *)0x58ce9;
  iVar1 = Cmd_Argc();
  if (1 < iVar1) {
    pcStack_94 = (char *)0x58cf3;
    iVar1 = Host_ValidGame();
    if (iVar1 != 0) {
      if ((sv == 0) || (DAT_003855a4 != 0)) {
        pcVar2 = "Only the server may changelevel\n";
      }
      else {
        pcStack_94 = (char *)0x1;
        puStack_98 = (undefined1 *)0x58d2b;
        puStack_98 = (undefined1 *)Cmd_Argv();
        puStack_9c = (undefined1 *)0x58d31;
        iVar1 = PF_IsMapValid_I();
        if (iVar1 != 0) {
          pcStack_94 = (char *)0x58d65;
          SCR_BeginLoadingPlaque();
          pcStack_94 = (char *)0x1;
          puStack_98 = (undefined1 *)0x58d6c;
          S_StopAllSounds();
          puStack_98 = (undefined1 *)0x1;
          puStack_9c = (undefined1 *)0x58d73;
          puStack_9c = (undefined1 *)Cmd_Argv();
          Q_strcpy(local_44);
          iVar1 = Cmd_Argc();
          if (iVar1 == 2) {
            puVar4 = (undefined1 *)0x0;
          }
          else {
            pcStack_94 = (char *)0x2;
            puStack_98 = (undefined1 *)0x58d97;
            puStack_98 = (undefined1 *)Cmd_Argv();
            puVar4 = local_84;
            puStack_9c = puVar4;
            Q_strcpy();
          }
          pcStack_94 = (char *)0x58da9;
          SV_InactivateClients();
          pcStack_94 = "VWj";
          SV_ServerShutdown();
          puStack_9c = (undefined1 *)0x0;
          puStack_98 = local_44;
          pcStack_94 = puVar4;
          SV_SpawnServer();
          SV_LoadEntities();
          SV_ActivateServer(1);
          return;
        }
        pcStack_94 = "changelevel failed: \'";
        puStack_98 = (undefined1 *)0x58d44;
        Con_Printf();
        puStack_98 = (undefined1 *)0x1;
        puStack_9c = (undefined1 *)0x58d4b;
        puStack_9c = (undefined1 *)Cmd_Argv();
        ppuVar3 = &puStack_9c;
        Con_Printf();
        pcVar2 = "\' not found on server\n";
      }
      goto LAB_00058d57;
    }
  }
  pcVar2 = "changelevel <levelname> : continue game on a new level\n";
  ppuVar3 = (undefined1 **)&stack0xffffff70;
LAB_00058d57:
  *(char **)((int)ppuVar3 + -4) = pcVar2;
  *(undefined4 *)((int)ppuVar3 + -8) = 0x58d5d;
  Con_Printf();
  return;
}


// Host_CheckConnectionFailure  @ 00056f04
void Host_CheckConnectionFailure(void)

{
  if ((cls == 1) &&
     ((((byte)giSubState & 4) != 0 ||
      ((byte)((byte)((ushort)((ushort)NAN((float)console._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)console._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)))) {
    if (0 < frames_63) {
      frames_63 = frames_63 + -1;
      return;
    }
    giActive = 2;
  }
  frames_63 = 5;
  return;
}


// Host_CheckDyanmicStructures  @ 00055a14
void Host_CheckDyanmicStructures(void)

{
  FUN_00055a22();
  return;
}


// Host_ClearClients  @ 00055680
void Host_ClearClients(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_54 [5];
  undefined4 *puStack_40;
  code *pcStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 *puStack_30;
  int local_20;
  int local_1c;
  undefined4 local_18 [5];
  
  host_client = DAT_001ab4e4;
  for (local_1c = 0; local_1c < DAT_001ab4e8; local_1c = local_1c + 1) {
    if ((*(int *)(host_client + 0x34e0) != 0) && (local_20 = 0, 0 < SV_UPDATE_BACKUP)) {
      iVar2 = 0;
      do {
        puVar1 = (undefined4 *)(iVar2 + *(int *)(host_client + 0x34e0));
        iStack_34 = 0x556ec;
        puStack_30 = puVar1;
        SV_ClearPacketEntities();
        iVar2 = iVar2 + 0xd10;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0xbf800000;
        local_20 = local_20 + 1;
      } while (local_20 < SV_UPDATE_BACKUP);
    }
    if (*(int *)(host_client + 0x24) != 0) {
      puVar1 = (undefined4 *)(host_client + 0x24);
      puVar3 = local_18;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar3 = puVar3 + 1;
      }
      puStack_30 = (undefined4 *)0x2430;
      iStack_34 = 0;
      iStack_38 = host_client + 0x20;
      pcStack_3c = (code *)0x5574d;
      Q_memset();
      pcStack_3c = SV_GetFragmentSize;
      puStack_40 = &host_client;
      puVar1 = local_18;
      puVar3 = auStack_54;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar3 = puVar3 + 1;
      }
      Netchan_Setup(1,host_client + 0x20);
    }
    puStack_30 = (undefined4 *)0x0;
    iStack_34 = host_client + 0x4ea8;
    iStack_38 = 0x55796;
    COM_ClearCustomizationList();
    host_client = host_client + 0x5054;
  }
  if (param_1 == 0) {
    host_client = DAT_001ab4e4;
    for (local_1c = 0; local_1c < DAT_001ab4ec; local_1c = local_1c + 1) {
      puStack_30 = (undefined4 *)(host_client + 0x34e0);
      iStack_34 = 0x557e7;
      SV_ClearFrames();
      host_client = host_client + 0x5054;
    }
    puStack_30 = (undefined4 *)(DAT_001ab4ec * 0x5054);
    iStack_34 = 0;
    iStack_38 = DAT_001ab4e4;
    pcStack_3c = (code *)0x55826;
    Q_memset();
    pcStack_3c = (code *)0x5582b;
    SV_AllocClientFrames();
  }
  return;
}


// Host_ClearGameState  @ 0005bba8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_ClearGameState(void)

{
  S_StopAllSounds(1);
  Host_ClearSaveDirectory();
  (*_DAT_00386258)();
  return;
}


// Host_ClearMemory  @ 00055a8c
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
  DAT_0038494c = 0;
  SV_ClearCaches();
  Q_memset(&sv,0,HPAK_Init);
  CL_ClearClientState();
  SV_ClearClientStates();
  return;
}


// Host_ClearSaveDirectory  @ 0005bb4c
void Host_ClearSaveDirectory(void)

{
  undefined4 uVar1;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory();
  sprintf(local_108,"%s",uVar1);
  COM_FixSlashes(local_108);
  Sys_mkdir(local_108);
  Q_strcat(local_108,"*.HL?");
  DirectoryClear(local_108);
  return;
}


// Host_ClientCommands  @ 0005545c
void Host_ClientCommands(char *param_1)

{
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  MSG_WriteByte(host_client + 0x74,9);
  MSG_WriteString(host_client + 0x74,local_404);
  return;
}


// Host_ComputeFPS  @ 00056b6c
void Host_ComputeFPS(double param_1)

{
  rolling_fps = param_1 * 0.4 + rolling_fps * 0.6;
  return;
}


// Host_Demos_f  @ 0005cde0
void Host_Demos_f(void)

{
  if (cls != 0) {
    if (DAT_0038539c == -1) {
      DAT_0038539c = 0;
    }
    CL_Disconnect_f();
    Host_NextDemo();
  }
  return;
}


// Host_EndGame  @ 00054fac
void Host_EndGame(char *param_1)

{
  int iVar1;
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  Con_DPrintf("Host_EndGame: %s\n",local_404);
  iVar1 = DAT_0038539c;
  scr_disabled_for_loading = 1;
  if (sv != 0) {
    Host_ShutdownServer(0);
  }
  DAT_0038539c = iVar1;
  if (cls == 0) {
    Sys_Error("Host_EndGame: %s\n",local_404);
  }
  iVar1 = DAT_0038539c;
  if (DAT_0038539c != -1) {
    CL_Disconnect_f();
    DAT_0038539c = iVar1;
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


// Host_EndSection  @ 0005ce58
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
  Cbuf_AddText(FUN_000a7a04);
  return;
}


// Host_Error  @ 000550ac
void Host_Error(char *param_1)

{
  char local_404 [1024];
  
  if (inerror_4 != 0) {
    Sys_Error("Host_Error: recursively entered");
  }
  inerror_4 = 1;
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
  inerror_4 = 0;
  DAT_0038539c = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Host_FilterTime  @ 00055b24
undefined4 Host_FilterTime(float param_1)

{
  double dVar1;
  int iVar2;
  
  realtime = realtime + (double)param_1;
  if (isDedicated == 0) {
    if ((sv != 0) || (dVar1 = (double)(float)fps_modem._12_4_, dVar1 <= 0.0)) {
      dVar1 = (double)(float)fps_max._12_4_;
    }
    if (0x3f < (byte)((0.5 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar1 == 0.5) << 0xe) >> 8)) - 1)) {
      dVar1 = 0.5;
    }
    if (100.0 < dVar1) {
      dVar1 = 100.0;
    }
    if ((1 < (int)cl._1356812_4_) &&
       (0x3f < (byte)((20.0 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar1 == 20.0) << 0xe) >> 8)) - 1))) {
      dVar1 = 20.0;
    }
    if (DAT_003855a8 != 0) goto LAB_00055c40;
  }
  else {
    dVar1 = (double)(float)sys_ticrate._12_4_;
    if (dVar1 <= 0.0) goto LAB_00055c40;
  }
  if (realtime - oldrealtime < 1.0 / dVar1) {
    return 0;
  }
LAB_00055c40:
  host_frametime = realtime - oldrealtime;
  oldrealtime = realtime;
  if (((float)host_framerate._12_4_ <= 0.0) ||
     ((iVar2 = Host_IsSinglePlayerGame(), iVar2 == 0 && (DAT_003855a4 == 0)))) {
    dVar1 = 0.25;
    if ((0.25 < host_frametime) ||
       (dVar1 = 0.001,
       0x3f < (byte)((0.001 < host_frametime |
                      (byte)((ushort)((ushort)NAN(host_frametime) << 10) >> 8) |
                     (byte)((ushort)((ushort)(host_frametime == 0.001) << 0xe) >> 8)) - 1))) {
      host_frametime = dVar1;
    }
  }
  else {
    host_frametime = (double)(float)host_framerate._12_4_;
  }
  return 1;
}


// Host_FindRecentSave  @ 00058dd0
char * Host_FindRecentSave(char *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_214;
  int local_210;
  char local_20c [260];
  undefined1 local_108 [260];
  
  uVar2 = Host_SaveGameDirectory();
  sprintf(param_1,"%s*.sav",uVar2);
  uVar2 = Host_SaveGameDirectory();
  sprintf(local_20c,"%s",uVar2);
  iVar3 = Sys_FindFirst(param_1,local_108);
  bVar1 = false;
  while (iVar3 != 0) {
    iVar4 = Q_strlen(iVar3);
    if ((iVar4 != 0) && (iVar4 = Q_strcasecmp(iVar3,"HLSave.sav"), iVar4 != 0)) {
      uVar2 = Host_SaveGameDirectory(iVar3);
      sprintf(local_20c,"%s%s",uVar2);
      local_210 = Sys_FileTime(local_20c);
      if ((0 < local_210) &&
         ((!bVar1 || (iVar4 = Sys_CompareFileTime(&local_214,&local_210), iVar4 < 0)))) {
        local_214 = local_210;
        Q_strcpy(param_1,iVar3);
        bVar1 = true;
      }
    }
    iVar3 = Sys_FindNext(local_108);
  }
  Sys_FindClose();
  if (!bVar1) {
    param_1 = (char *)0x0;
  }
  return param_1;
}


// Host_Fly_f  @ 00058810
void Host_Fly_f(void)

{
  char *pcVar1;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(DAT_00152b54) << 10) >> 8) |
                 (byte)((ushort)((ushort)(DAT_00152b54 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (*(int *)(sv_player + 0x188) == 5) {
      *(undefined4 *)(sv_player + 0x188) = 3;
      pcVar1 = "flymode OFF\n";
    }
    else {
      *(undefined4 *)(sv_player + 0x188) = 5;
      pcVar1 = "flymode ON\n";
    }
    SV_ClientPrintf(pcVar1);
  }
  return;
}


// Host_Frame  @ 000570f8
undefined4 Host_Frame(undefined4 param_1,undefined4 param_2,int *param_3)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  double dStack_20;
  double dStack_18;
  
  iVar2 = __sigsetjmp(host_abortserver,0);
  if (iVar2 == 0) {
    giActive = param_2;
    *param_3 = 0;
    if ((byte)((float)host_profile._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)host_profile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)host_profile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      lVar6 = (longdouble)Sys_FloatTime();
      dStack_18 = (double)lVar6;
    }
    _Host_Frame(param_1);
    if ((byte)(0.0 < (float)host_profile._12_4_ |
               (byte)((ushort)((ushort)NAN((float)host_profile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)host_profile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      lVar6 = (longdouble)Sys_FloatTime();
      dStack_20 = (double)lVar6;
    }
    if (giStateInfo != 0) {
      *param_3 = giStateInfo;
      giStateInfo = 0;
      Cbuf_Execute();
    }
    if ((byte)(0.0 < (float)host_profile._12_4_ |
               (byte)((ushort)((ushort)NAN((float)host_profile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)host_profile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      timetotal_69 = timetotal_69 + (dStack_20 - dStack_18);
      iVar2 = timecount_70 + 1;
      timecount_70 = timecount_70 + 1;
      if (999 < iVar2) {
        dVar1 = timetotal_69 * 1000.0;
        iVar5 = 0;
        iVar4 = 0;
        timecount_70 = 0;
        timetotal_69 = 0.0;
        if (0 < DAT_001ab4e8) {
          iVar3 = 0;
          do {
            if (*(int *)(DAT_001ab4e4 + iVar3) != 0) {
              iVar5 = iVar5 + 1;
            }
            iVar3 = iVar3 + 0x5054;
            iVar4 = iVar4 + 1;
          } while (iVar4 < DAT_001ab4e8);
        }
        Con_Printf("host_profile: %2i clients %2i msec\n",iVar5,(int)ROUND(dVar1 / (double)iVar2));
      }
    }
  }
  return giActive;
}


// Host_FullInfo_f  @ 0005bdd4
void Host_FullInfo_f(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char local_404 [512];
  char local_204 [512];
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 2) {
    pcVar3 = (char *)Cmd_Argv(1);
    cVar1 = *pcVar3;
    if (cVar1 != '\\') goto LAB_0005bedb;
    pcVar3 = pcVar3 + 1;
    while( true ) {
      cVar1 = *pcVar3;
LAB_0005bedb:
      if (cVar1 == '\0') {
        return;
      }
      pcVar4 = local_204;
      while ((cVar1 != '\0' && (cVar1 != '\\'))) {
        *pcVar4 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar3;
      }
      *pcVar4 = '\0';
      if (*pcVar3 == '\0') {
        pcVar3 = "MISSING VALUE\n";
        goto LAB_0005be06;
      }
      pcVar4 = local_404;
      pcVar5 = pcVar3;
      while( true ) {
        pcVar3 = pcVar5 + 1;
        cVar1 = *pcVar3;
        if ((cVar1 == '\0') || (cVar1 == '\\')) break;
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar3;
      }
      *pcVar4 = '\0';
      if (*pcVar3 != '\0') {
        pcVar3 = pcVar5 + 2;
      }
      if (cmd_source == 1) break;
      Info_SetValueForKey(host_client + 0x4af4,local_204,local_404,0x100);
      *(undefined4 *)(host_client + 0x4bf4) = 1;
    }
    Info_SetValueForKey(&DAT_00385294,local_204,local_404,0x100);
    Cmd_ForwardToServer();
  }
  else {
    pcVar3 = "fullinfo <complete info string>\n";
LAB_0005be06:
    Con_Printf(pcVar3);
  }
  return;
}


// Host_GetBatchModList_f  @ 0005d09c
void Host_GetBatchModList_f(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_c8 [4];
  undefined4 uStack_b8;
  char *pcStack_b4;
  undefined4 uStack_b0;
  undefined4 auStack_ac [2];
  char local_84 [128];
  
  NET_Config();
  if ((gfNoMasterServer == 0) && (valvemaster_adr != 0)) {
    auStack_ac[1] = 0x5d0ee;
    sprintf(local_84,"%c\r\nstart-of-list\r\n");
    for (iVar1 = valvemaster_adr; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
      puVar3 = (undefined4 *)(iVar1 + 0x18);
      puVar4 = auStack_ac;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      uStack_b0 = 0x5d127;
      uStack_b0 = NET_AdrToString();
      pcStack_b4 = "Requesting batch mod status from %s\n";
      uStack_b8 = 0x5d134;
      Con_Printf();
      puVar3 = (undefined4 *)(iVar1 + 0x18);
      puVar4 = auStack_c8;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = Q_strlen(local_84,local_84);
      NET_SendPacket(0,iVar2 + 1);
    }
  }
  return;
}


// Host_GetHostInfo  @ 00056ba0
void Host_GetHostInfo(float *param_1,int *param_2,int *param_3,undefined4 *param_4,
                     undefined1 *param_5)

{
  float fVar1;
  int local_10;
  int local_c;
  float local_8;
  
  local_c = 0;
  local_10 = 0;
  fVar1 = (float)rolling_fps;
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    local_8 = 1.0 / fVar1;
    *param_1 = local_8;
  }
  else {
    rolling_fps = 0.0;
    *param_1 = 0.0;
  }
  SV_CountPlayers(&local_10,&local_c);
  local_10 = local_10 - local_c;
  *param_2 = local_10;
  *param_3 = local_c;
  if (param_5 != (undefined1 *)0x0) {
    if (DAT_001535a8 == '\0') {
      *param_5 = 0;
    }
    else {
      Q_strcpy(param_5,&DAT_001535a8);
    }
  }
  *param_4 = DAT_001ab4e8;
  return;
}


// Host_Getcertificate_f  @ 0005d188
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_Getcertificate_f(void)

{
  int iVar1;
  char *pcVar2;
  
  Con_Printf("Trying to authenticate with WON servers\n");
  iVar1 = (*_DAT_003861dc)();
  if (iVar1 == 0) {
    pcVar2 = "Failed to authenticate\n";
  }
  else {
    pcVar2 = "WON Authentication successful\n";
  }
  Con_Printf(pcVar2);
  return;
}


// Host_God_f  @ 000583fc
void Host_God_f(void)

{
  char *pcVar1;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (((byte)((byte)((ushort)((ushort)NAN(DAT_00152b54) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00152b54 == 0.0) << 0xe) >> 8)) == 0x40) &&
          (allow_cheats != 0)) {
    *(byte *)(sv_player + 0x224) = *(byte *)(sv_player + 0x224) ^ 0x40;
    if ((*(byte *)(sv_player + 0x224) & 0x40) == 0) {
      pcVar1 = "godmode OFF\n";
    }
    else {
      pcVar1 = "godmode ON\n";
    }
    SV_ClientPrintf(pcVar1);
  }
  return;
}


// Host_Init  @ 00057508
undefined4 Host_Init(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *local_c;
  char *local_8;
  
  minimum_memory = 0x550000;
  iVar2 = COM_CheckParm();
  if (iVar2 != 0) {
    param_1[5] = minimum_memory;
  }
  puVar4 = param_1;
  puVar5 = &host_parms;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
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
  Memory_Init(param_1[4],param_1[5]);
  Cvar_RegisterVariable(console);
  iVar2 = COM_CheckParm();
  if (((iVar2 != 0) || (iVar2 = COM_CheckParm(), iVar2 != 0)) ||
     (iVar2 = COM_CheckParm(), iVar2 != 0)) {
    Cvar_DirectSet(console,&DAT_000a7131);
  }
  Cbuf_Init();
  Cmd_Init();
  Cvar_CmdInit();
  V_Init();
  Chase_Init();
  COM_Init();
  Host_InitLocal();
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
  Host_Version();
  Con_DPrintf("%4.1f Mb heap\n",(double)(int)param_1[5] * 9.5367431640625e-07);
  R_InitTextures();
  HPAK_CheckIntegrity("custom");
  if (cls == 0) {
    Cvar_RegisterVariable();
  }
  else {
    pcVar3 = (char *)COM_LoadHunkFile();
    if (pcVar3 == (char *)0x0) {
      Sys_Error();
    }
    host_basepal = Hunk_AllocName(0x800,"palette.lmp");
    local_8 = pcVar3 + 1;
    local_c = pcVar3 + 2;
    iVar2 = 0;
    do {
      *(short *)(host_basepal + iVar2 * 8) = (short)*local_c;
      *(short *)(host_basepal + 2 + iVar2 * 8) = (short)*local_8;
      *(short *)(host_basepal + 4 + iVar2 * 8) = (short)*pcVar3;
      iVar1 = iVar2 + 1;
      *(undefined2 *)(host_basepal + 6 + iVar2 * 8) = 0;
      *(short *)(host_basepal + iVar1 * 8) = (short)local_c[3];
      *(short *)(host_basepal + 2 + iVar1 * 8) = (short)local_8[3];
      *(short *)(host_basepal + 4 + iVar1 * 8) = (short)pcVar3[3];
      *(undefined2 *)(host_basepal + 6 + iVar1 * 8) = 0;
      iVar1 = iVar2 + 2;
      *(short *)(host_basepal + iVar1 * 8) = (short)local_c[6];
      *(short *)(host_basepal + 2 + iVar1 * 8) = (short)local_8[6];
      *(short *)(host_basepal + 4 + iVar1 * 8) = (short)pcVar3[6];
      *(undefined2 *)(host_basepal + 6 + iVar1 * 8) = 0;
      iVar1 = iVar2 + 3;
      *(short *)(host_basepal + iVar1 * 8) = (short)local_c[9];
      *(short *)(host_basepal + 2 + iVar1 * 8) = (short)local_8[9];
      *(short *)(host_basepal + 4 + iVar1 * 8) = (short)pcVar3[9];
      iVar2 = iVar2 + 4;
      pcVar3 = pcVar3 + 0xc;
      *(undefined2 *)(host_basepal + 6 + iVar1 * 8) = 0;
      local_8 = local_8 + 0xc;
      local_c = local_c + 0xc;
    } while (iVar2 < 0x100);
    CL_InitEventSystem();
    ClientDLL_Init();
    iVar2 = VID_Init();
    if (iVar2 == 0) {
      return 0;
    }
    Draw_Init();
    SCR_Init();
    R_Init();
    S_Init();
    CL_Init();
    (*Launcher_InitCmds)();
  }
  Cbuf_InsertText();
  WON_InitAuthentication();
  Hunk_AllocName(0,"-HOST_HUNKLEVEL-");
  host_hunklevel = Hunk_LowMark();
  giActive = 1;
  scr_skipupdate = 0;
  iVar2 = COM_CheckParm();
  if (iVar2 != 0) {
    Cvar_SetValue("sv_cheats",0x3f800000);
    Cvar_SetValue();
  }
  CheckGore();
  host_initialized = 1;
  return 1;
}


// Host_InitCommands  @ 0005d1d4
void Host_InitCommands(void)

{
  Cmd_AddCommand("getcertificate",Host_Getcertificate_f);
  Cmd_AddCommand("bgetmod",Host_GetBatchModList_f);
  Cmd_AddCommand("shutdownserver",Host_KillServer_f);
  Cmd_AddCommand("soundfade",Host_Soundfade_f);
  Cmd_AddCommand("status",Host_Status_f);
  Cmd_AddCommand(&DAT_000a8116,Host_Quit_f);
  Cmd_AddCommand(&DAT_000a811b,Host_Quit_f);
  Cmd_AddCommand(&DAT_000a8120,Host_Map_f);
  Cmd_AddCommand(&DAT_000a8124,Host_Maps_f);
  Cmd_AddCommand("restart",Host_Restart_f);
  Cmd_AddCommand("reload",Host_Reload_f);
  Cmd_AddCommand("changelevel",Host_Changelevel_f);
  Cmd_AddCommand(FUN_000a8144,Host_Changelevel2_f);
  Cmd_AddCommand("reconnect",Host_Reconnect_f);
  Cmd_AddCommand("version",Host_Version_f);
  Cmd_AddCommand(&DAT_000a8163,Host_Say_f);
  Cmd_AddCommand("say_team",Host_Say_Team_f);
  Cmd_AddCommand(&DAT_000a8170,Host_Tell_f);
  Cmd_AddCommand(&DAT_000a8175,Host_Kill_f);
  Cmd_AddCommand("pause",Host_Pause_f);
  Cmd_AddCommand(&DAT_000a8180,Host_Kick_f);
  Cmd_AddCommand(&DAT_000a8185,Host_Ping_f);
  Cmd_AddCommand(&DAT_000a818a,Host_Loadgame_f);
  Cmd_AddCommand(&DAT_000a818f,Host_Savegame_f);
  Cmd_AddCommand("autosave",Host_AutoSave_f);
  Cmd_AddCommand("startdemos",Host_Startdemos_f);
  Cmd_AddCommand("demos",Host_Demos_f);
  Cmd_AddCommand("stopdemo",Host_Stopdemo_f);
  Cmd_AddCommand("setinfo",Host_SetInfo_f);
  Cmd_AddCommand("fullinfo",Host_FullInfo_f);
  Cmd_AddCommand(&DAT_000a81bf,Host_God_f);
  Cmd_AddCommand("notarget",Host_Notarget_f);
  Cmd_AddCommand(&DAT_000a81cc,Host_Fly_f);
  Cmd_AddCommand("noclip",Host_Noclip_f);
  Cmd_AddCommand("viewmodel",Host_Viewmodel_f);
  Cmd_AddCommand("viewframe",Host_Viewframe_f);
  Cmd_AddCommand("viewnext",Host_Viewnext_f);
  Cmd_AddCommand("viewprev",Host_Viewprev_f);
  Cmd_AddCommand("mcache",Mod_Print);
  Cmd_AddCommand("interp",Host_Interp_f);
  Cmd_AddCommand("setmaster",Master_SetMaster_f);
  Cmd_AddCommand("heartbeat",Master_Heartbeat_f);
  Cmd_AddCommand(&DAT_000a821f,Host_RequestMOTD_f);
  Cvar_RegisterVariable(gHostMap);
  Host_ClearSaveDirectory();
  HPAK_Init();
  return;
}


// Host_InitLocal  @ 00055168
void Host_InitLocal(void)

{
  Host_InitCommands();
  Cvar_RegisterVariable(sys_ticrate);
  Cvar_RegisterVariable(fps_max);
  Cvar_RegisterVariable(fps_modem);
  Cvar_RegisterVariable(host_name);
  Cvar_RegisterVariable(host_limitlocal);
  Cvar_RegisterVariable(host_framerate);
  Cvar_RegisterVariable(host_speeds);
  Cvar_RegisterVariable(host_profile);
  Cvar_RegisterVariable(mp_logfile);
  Cvar_RegisterVariable(mp_logecho);
  Cvar_RegisterVariable(developer);
  Cvar_RegisterVariable(deathmatch);
  Cvar_RegisterVariable(coop);
  Cvar_RegisterVariable(pausable);
  Cvar_RegisterVariable(skill);
  SV_SetMaxclients();
  return;
}


// Host_InitializeGameDLL  @ 00057ba0
void Host_InitializeGameDLL(void)

{
  Cbuf_Execute();
  if (svs == 0) {
    svs = 1;
    LoadEntityDLLs(host_parms);
    (*gEntityInterface)();
    (*DAT_003862ac)(g_svmove);
    (*DAT_003862c4)();
    SV_InitEncoders();
    SV_GetPlayerHulls();
    Cbuf_Execute();
  }
  else {
    Con_DPrintf("Sys_InitializeGameDLL called twice, skipping second call\n");
  }
  return;
}


// Host_Interp_f  @ 0005ca98
void Host_Interp_f(void)

{
  char *pcVar1;
  
  r_dointerp = (uint)(r_dointerp == 0);
  if (r_dointerp == 0) {
    pcVar1 = "Frame Interpolation OFF\n";
  }
  else {
    pcVar1 = "Frame Interpolation ON\n";
  }
  Con_Printf(pcVar1);
  return;
}


// Host_IsServerActive  @ 0005735c
undefined4 Host_IsServerActive(void)

{
  return sv;
}


// Host_IsSinglePlayerGame  @ 00057314
bool Host_IsSinglePlayerGame(void)

{
  int iVar1;
  
  iVar1 = cl._1356812_4_;
  if (sv != 0) {
    iVar1 = DAT_001ab4e8;
  }
  return iVar1 == 1;
}


// Host_Kick_f  @ 0005c53c
void Host_Kick_f(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  int local_10;
  
  pcVar7 = (char *)0x0;
  iVar3 = Cmd_Argc();
  piVar2 = host_client;
  if (iVar3 < 2) {
    pcVar7 = "usage:  kick < name > | < # userid >\n";
  }
  else {
    if (cmd_source == 1) {
      if (sv == 0) {
        Cmd_ForwardToServer();
        return;
      }
    }
    else if (host_client[9] != 1) {
      SV_ClientPrintf("You can\'t \'kick\' because you are not a server operator\n");
      return;
    }
    pcVar4 = (char *)Cmd_Argv(1);
    if ((pcVar4 == (char *)0x0) || (*pcVar4 != '#')) {
      host_client = DAT_001ab4e4;
      iVar3 = 0;
      if (0 < DAT_001ab4e8) {
        iVar3 = 0;
        do {
          if ((*host_client != 0) || (host_client[3] != 0)) {
            uVar5 = Cmd_Argv(1);
            iVar6 = Q_strcasecmp(host_client + 0x130f,uVar5);
            if (iVar6 == 0) break;
          }
          host_client = host_client + 0x1415;
          iVar3 = iVar3 + 1;
        } while (iVar3 < DAT_001ab4e8);
      }
      bVar1 = false;
    }
    else {
      iVar3 = Cmd_Argc();
      if (iVar3 < 3) {
        local_10 = Q_atoi(pcVar4 + 1);
      }
      else {
        uVar5 = Cmd_Argv(2);
        local_10 = Q_atoi(uVar5);
      }
      iVar3 = 0;
      for (host_client = DAT_001ab4e4;
          (iVar3 < DAT_001ab4e8 &&
          (((*host_client == 0 && (host_client[3] == 0)) || (host_client[0x12bb] != local_10))));
          host_client = host_client + 0x1415) {
        iVar3 = iVar3 + 1;
      }
      bVar1 = true;
    }
    if (DAT_001ab4e8 <= iVar3) {
      host_client = piVar2;
      return;
    }
    pcVar4 = (char *)(piVar2 + 0x130f);
    if (cmd_source == 1) {
      pcVar4 = "Console";
    }
    if (host_client[9] != 1) {
      iVar3 = Cmd_Argc();
      if (2 < iVar3) {
        uVar5 = Cmd_Args();
        pcVar7 = (char *)COM_Parse(uVar5);
        if (bVar1) {
          do {
            pcVar7 = pcVar7 + 1;
          } while (*pcVar7 == ' ');
          uVar5 = Cmd_Argv(2);
          iVar3 = Q_strlen(uVar5);
          pcVar7 = pcVar7 + iVar3;
        }
        for (; *pcVar7 == ' '; pcVar7 = pcVar7 + 1) {
        }
      }
      if (pcVar7 == (char *)0x0) {
        SV_ClientPrintf("Kicked by %s\n",pcVar4);
      }
      else {
        SV_ClientPrintf("Kicked by %s: %s\n",pcVar4,pcVar7);
      }
      SV_DropClient(host_client,0);
      host_client = piVar2;
      return;
    }
    pcVar7 = "The local player cannot be kicked!\n";
  }
  Con_Printf(pcVar7);
  return;
}


// Host_KillServer_f  @ 0005d048
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


// Host_Kill_f  @ 0005c3e4
void Host_Kill_f(void)

{
  float fVar1;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    fVar1 = *(float *)(sv_player + 0x1e0);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      gGlobalVariables = (float)DAT_0015358c;
      (*DAT_00386264)(sv_player);
    }
    else {
      SV_ClientPrintf(FUN_000a7d00);
    }
  }
  return;
}


// Host_Load  @ 00059c34
undefined4 Host_Load(char *param_1)

{
  undefined4 uVar1;
  char *__format;
  FILE *__stream;
  int iVar2;
  char *local_18c;
  char local_180 [8];
  char local_178 [256];
  undefined1 local_78 [112];
  undefined4 local_8;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    if (*param_1 == '_') {
      local_18c = param_1 + 1;
      iVar2 = 0;
      if ((param_1[1] != '\0') && ((*(byte *)(__ctype_b + 1 + param_1[1] * 2) & 8) != 0)) {
        iVar2 = 0;
        while (iVar2 < 5) {
          local_180[iVar2] = *local_18c;
          local_18c = local_18c + 1;
          iVar2 = iVar2 + 1;
          if ((*local_18c == '\0') || ((*(byte *)(__ctype_b + 1 + *local_18c * 2) & 8) == 0)) break;
        }
      }
      local_180[iVar2] = '\0';
      iVar2 = Q_atoi(local_180);
      if (0xb < iVar2 - 1U) {
        return 0;
      }
      uVar1 = Host_SaveGameDirectory(iVar2);
      __format = "%sHalf-Life-%i";
    }
    else {
      uVar1 = Host_SaveGameDirectory(param_1);
      __format = "%s%s";
    }
    sprintf(local_178,__format,uVar1);
    if (svs == 0) {
      Host_InitializeGameDLL();
    }
    COM_DefaultExtension(local_178,&DAT_000a7963);
    COM_FixSlashes(local_178);
    Con_Printf("Loading game from %s...\n",local_178);
    __stream = fopen(local_178,"rb");
    if (__stream != (FILE *)0x0) {
      Host_ClearGameState();
      iVar2 = SaveReadHeader(__stream,local_78,1);
      if (iVar2 != 0) {
        DAT_0038539c = 0xffffffff;
        SV_InactivateClients();
        SCR_BeginLoadingPlaque();
        DirectoryExtract(__stream,local_8);
        fclose(__stream);
        Cvar_SetValue("deathmatch",0);
        Cvar_SetValue(&DAT_000a7a1c,0);
        sprintf(local_178,"map %s\n",local_78);
        Host_Map(0,local_178,local_78,1);
        return 1;
      }
      giStateInfo = 1;
      Cbuf_AddText(FUN_000a7a04);
    }
  }
  return 0;
}


// Host_Loadgame_f  @ 00059b9c
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


// Host_Map  @ 00058988
void Host_Map(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  CL_Disconnect();
  Host_ShutdownServer(0);
  key_dest = 0;
  SCR_BeginLoadingPlaque();
  if (param_4 == 0) {
    Host_ClearGameState();
    SV_InactivateClients();
    DAT_001ab4f4 = 0;
  }
  Q_strcpy(&DAT_00384a54,param_2);
  iVar1 = Host_ValidGame();
  if ((iVar1 != 0) && (iVar1 = SV_SpawnServer(param_1,param_3,0), iVar1 != 0)) {
    if (param_4 == 0) {
      SV_LoadEntities();
      SV_ActivateServer(1);
      if (sv == 0) {
        return;
      }
      if (cls != 0) {
        Q_strcpy(&DAT_00384a94,&DAT_000a75b4);
        for (iVar1 = 2; iVar3 = Cmd_Argc(), iVar1 < iVar3; iVar1 = iVar1 + 1) {
          uVar2 = Cmd_Argv(iVar1);
          Q_strcat(&DAT_00384a94,uVar2);
          Q_strcat(&DAT_00384a94,&DAT_000a75b5);
        }
      }
    }
    else {
      iVar1 = LoadGamestate(param_3,1);
      if (iVar1 == 0) {
        SV_LoadEntities();
      }
      DAT_00153584 = 1;
      DAT_00153588 = 1;
      SV_ActivateServer(0);
    }
    if (sv_gpNewUserMsgs != 0) {
      iVar1 = sv_gpUserMsgs;
      if (sv_gpUserMsgs == 0) {
        sv_gpUserMsgs = sv_gpNewUserMsgs;
      }
      else {
        do {
          iVar3 = iVar1;
          iVar1 = *(int *)(iVar3 + 0x14);
        } while (iVar1 != 0);
        *(int *)(iVar3 + 0x14) = sv_gpNewUserMsgs;
      }
      sv_gpNewUserMsgs = 0;
    }
    if (cls != 0) {
      Cmd_ExecuteString("connect local",1);
    }
  }
  return;
}


// Host_Map_f  @ 00058b1c
void Host_Map_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_88;
  undefined1 local_84 [64];
  undefined1 local_44 [64];
  
  if (cmd_source == 1) {
    local_44[0] = 0;
    iVar3 = 0;
    while( true ) {
      iVar1 = Cmd_Argc();
      if (iVar1 <= iVar3) break;
      uVar2 = Cmd_Argv(iVar3);
      Q_strcat(local_44,uVar2);
      Q_strcat(local_44,&DAT_000a75b5);
      iVar3 = iVar3 + 1;
    }
    Q_strcat(local_44,&DAT_000a7505);
    uVar2 = Cmd_Argv(1);
    local_88 = local_84;
    Q_strcpy(local_84,uVar2);
    if (svs == 0) {
      Host_InitializeGameDLL();
    }
    iVar3 = Q_strlen(local_84);
    if (4 < iVar3) {
      iVar1 = Q_strcasecmp(local_84 + iVar3 + -4,&DAT_000a75c5);
      if (iVar1 == 0) {
        local_84[iVar3 + -4] = 0;
      }
    }
    iVar3 = PF_IsMapValid_I(local_84);
    if (iVar3 == 0) {
      Con_Printf("map change failed: \'");
      Con_Printf(local_88);
      Con_Printf("\' not found on server\n");
    }
    else {
      if ((1 < DAT_001ab4e8) &&
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


// Host_Maps_f  @ 00058c7c
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


// Host_NextDemo  @ 0005cadc
void Host_NextDemo(void)

{
  char local_404 [1024];
  
  if (DAT_0038539c != -1) {
    SCR_BeginLoadingPlaque();
    if ((((&DAT_003853a0)[DAT_0038539c * 0x10] == '\0') || (DAT_0038539c == 0x20)) &&
       (DAT_0038539c = 0, DAT_003853a0 == '\0')) {
      scr_disabled_for_loading = 0;
      Con_Printf("No demos listed with startdemos\n");
      DAT_0038539c = 0xffffffff;
      return;
    }
    sprintf(local_404,"playdemo %s\n",&DAT_003853a0 + DAT_0038539c * 0x10);
    Cbuf_InsertText(local_404);
    DAT_0038539c = DAT_0038539c + 1;
  }
  return;
}


// Host_Noclip_f  @ 000585d4
void Host_Noclip_f(void)

{
  int iVar1;
  undefined1 local_28 [12];
  undefined1 local_1c [12];
  undefined1 local_10 [12];
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (((byte)((byte)((ushort)((ushort)NAN(DAT_00152b54) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00152b54 == 0.0) << 0xe) >> 8)) == 0x40) &&
          (allow_cheats != 0)) {
    if (*(int *)(sv_player + 0x188) == 8) {
      noclip_anglehack = 0;
      *(undefined4 *)(sv_player + 0x188) = 3;
      *(undefined4 *)(sv_player + 0x94) = *(undefined4 *)(sv_player + 0x88);
      *(undefined4 *)(sv_player + 0x98) = *(undefined4 *)(sv_player + 0x8c);
      *(undefined4 *)(sv_player + 0x9c) = *(undefined4 *)(sv_player + 0x90);
      SV_ClientPrintf("noclip OFF\n");
      iVar1 = SV_TestEntityPosition(sv_player);
      if (iVar1 != 0) {
        AngleVectors(sv_player + 0xf4,local_10,local_1c,local_28);
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
        *(undefined4 *)(sv_player + 0x88) = *(undefined4 *)(sv_player + 0x94);
        *(undefined4 *)(sv_player + 0x8c) = *(undefined4 *)(sv_player + 0x98);
        *(undefined4 *)(sv_player + 0x90) = *(undefined4 *)(sv_player + 0x9c);
      }
    }
    else {
      noclip_anglehack = 1;
      *(undefined4 *)(sv_player + 0x188) = 8;
      SV_ClientPrintf("noclip ON\n");
    }
  }
  return;
}


// Host_Notarget_f  @ 00058480
void Host_Notarget_f(void)

{
  char *pcVar1;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(DAT_00152b54) << 10) >> 8) |
                 (byte)((ushort)((ushort)(DAT_00152b54 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(byte *)(sv_player + 0x224) = *(byte *)(sv_player + 0x224) ^ 0x80;
    if (*(char *)(sv_player + 0x224) < '\0') {
      pcVar1 = "notarget ON\n";
    }
    else {
      pcVar1 = "notarget OFF\n";
    }
    SV_ClientPrintf(pcVar1);
  }
  return;
}


// Host_Pause_f  @ 0005c468
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
    DAT_00153584 = DAT_00153584 ^ 1;
    if (DAT_00153584 == 0) {
      iVar1 = *(int *)(sv_player + 0x250);
      pcVar2 = "%s unpaused the game\n";
    }
    else {
      iVar1 = *(int *)(sv_player + 0x250);
      pcVar2 = "%s paused the game\n";
    }
    SV_BroadcastPrintf(pcVar2,iVar1 + pr_strings);
    MSG_WriteByte(&DAT_00187f54,0x18);
    MSG_WriteByte(&DAT_00187f54,DAT_00153584);
  }
  return;
}


// Host_Ping_f  @ 00058900
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
    iVar3 = 0;
    piVar2 = DAT_001ab4e4;
    if (0 < DAT_001ab4e8) {
      do {
        if (*piVar2 != 0) {
          uVar1 = SV_CalcPing(piVar2,piVar2 + 0x130f);
          SV_ClientPrintf("%4i %s\n",uVar1);
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 0x1415;
      } while (iVar3 < DAT_001ab4e8);
    }
  }
  return;
}


// Host_Quit_f  @ 00057d20
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


// Host_Reconnect_f  @ 00059034
void Host_Reconnect_f(void)

{
  if (2 < cls) {
    SCR_BeginLoadingPlaque();
    DAT_0038494c = 0;
    cls = 3;
    Netchan_Clear(&DAT_00382504);
    SZ_Clear(&DAT_00382558);
    MSG_WriteChar(&DAT_00382558,3);
    MSG_WriteString(&DAT_00382558,&DAT_000a76cf);
  }
  return;
}


// Host_Reload_f  @ 00058fa0
void Host_Reload_f(void)

{
  int iVar1;
  undefined1 local_108 [260];
  
  if (((DAT_003855a4 == 0) && (sv != 0)) && (cmd_source == 1)) {
    Host_ClearGameState();
    SV_InactivateClients();
    SV_ServerShutdown();
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


// Host_RequestMOTD_f  @ 00057c28
void Host_RequestMOTD_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  undefined4 *puVar6;
  char *apcStack_840 [4];
  undefined4 uStack_830;
  undefined4 uStack_824;
  undefined4 uStack_820;
  char local_804 [2048];
  
  if ((gfNoMasterServer == 0) && (valvemaster_adr != 0)) {
    uStack_820 = 1;
    uStack_824 = 0x57c65;
    NET_Config();
    uStack_824 = 0x67;
    uStack_830 = 0x57c80;
    sprintf(local_804,"%c\n");
    iVar1 = valvemaster_adr;
    puVar4 = (undefined4 *)(valvemaster_adr + 0x18);
    ppcVar5 = apcStack_840;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppcVar5 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    uVar2 = NET_AdrToString();
    Con_DPrintf("Requesting MOTD from master(s)\n",uVar2);
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
      puVar4 = (undefined4 *)(iVar1 + 0x18);
      puVar6 = &uStack_830;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      apcStack_840[1] = (char *)0x57cef;
      apcStack_840[2] = local_804;
      apcStack_840[3] = local_804;
      apcStack_840[2] = (char *)Q_strlen();
      apcStack_840[1] = (char *)0x0;
      apcStack_840[0] = (char *)0x57cfa;
      NET_SendPacket();
    }
  }
  return;
}


// Host_Restart_f  @ 00058f10
void Host_Restart_f(void)

{
  undefined1 local_108 [260];
  
  if (((DAT_003855a4 == 0) && (sv != 0)) && (cmd_source == 1)) {
    if (cls != 0) {
      cls = 1;
    }
    Host_ClearGameState();
    SV_InactivateClients();
    Q_strcpy(local_108,&DAT_001535a8);
    SV_ServerShutdown();
    SV_SpawnServer(0,local_108,0);
    SV_LoadEntities();
    SV_ActivateServer(1);
  }
  return;
}


// Host_SaveAgeList  @ 0005925c
void Host_SaveAgeList(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
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
        iVar2 = 0;
      }
      else {
        iVar2 = param_2 + -1;
        uVar1 = Host_SaveGameDirectory(param_1,iVar2);
        sprintf(local_20c,"%s%s%02d.sav",uVar1);
      }
      COM_FixSlashes(local_20c);
      uVar1 = Host_SaveGameDirectory(param_1,param_2);
      sprintf(local_108,"%s%s%02d.sav",uVar1);
      COM_FixSlashes(local_108);
      rename(local_20c,local_108);
      param_2 = iVar2;
    } while (0 < iVar2);
  }
  return;
}


// Host_SaveGameDirectory  @ 000590a4
undefined1 * Host_SaveGameDirectory(void)

{
  Q_memset(szDirectory_114,0,0x104);
  sprintf(szDirectory_114,"%s/SAVE/",com_gamedir);
  return szDirectory_114;
}


// Host_SavegameComment  @ 000590e8
void Host_SavegameComment(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  ushort in_FPUStatusWord;
  longdouble lVar6;
  char *local_54;
  char local_44 [64];
  
  local_54 = (char *)0x0;
  uVar5 = 0;
  pcVar2 = (char *)(DAT_00152b4c + pr_strings);
  do {
    uVar3 = Q_strlen((&gTitleComments)[uVar5 * 2]);
    iVar4 = Q_strnicmp(pcVar2,(&gTitleComments)[uVar5 * 2],uVar3);
    if ((iVar4 == 0) && (iVar4 = TextMessageGet((&PTR_DAT_000b2d38)[uVar5 * 2]), iVar4 != 0)) {
      Q_strncpy(local_44,*(undefined4 *)(iVar4 + 0x28),0x40);
      iVar4 = 0;
      do {
        cVar1 = local_44[iVar4];
        local_54 = local_44;
        if (cVar1 == '\0') break;
        if ((cVar1 == '\n') || (cVar1 == '\r')) {
          local_44[iVar4] = '\0';
        }
        else {
          iVar4 = iVar4 + 1;
        }
      } while (iVar4 < 0x40);
    }
    uVar5 = uVar5 + 1;
    if ((0x1a < uVar5) || (local_54 != (char *)0x0)) {
      if ((local_54 == (char *)0x0) && (iVar4 = Q_strlen(0x3725c4), local_54 = pcVar2, iVar4 != 0))
      {
        local_54 = cl + 0x14b3e4;
      }
      lVar6 = (longdouble)DAT_0015358c;
      do {
        lVar6 = lVar6 - (longdouble)(unkint10)(lVar6 / (longdouble)60.0) * (longdouble)60.0;
      } while ((in_FPUStatusWord & 0x400) != 0);
      sprintf(param_1,"%-64.64s %02d:%02d",local_54,(int)ROUND(DAT_0015358c * 0.016666666666666666),
              (int)ROUND(lVar6));
      return;
    }
  } while( true );
}


// Host_Savegame_f  @ 00059924
void Host_Savegame_f(void)

{
  return;
}


// Host_Say  @ 0005bfc4
void Host_Say(void)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  int local_94;
  int *local_90;
  char local_84;
  undefined1 local_83 [127];
  
  if (cls == 0) {
    iVar2 = Cmd_Argc();
    if (1 < iVar2) {
      pcVar3 = (char *)Cmd_Args();
      uVar1 = host_client;
      if (pcVar3 != (char *)0x0) {
        pcVar6 = pcVar3;
        if (*pcVar3 == '\"') {
          pcVar6 = pcVar3 + 1;
          iVar2 = Q_strlen(pcVar6);
          pcVar3[iVar2] = '\0';
        }
        uVar4 = Cvar_VariableString("hostname");
        sprintf(&local_84,"%c<%s> ",1,uVar4);
        iVar2 = Q_strlen(pcVar6);
        if (0x3f < iVar2) {
          pcVar6[0x3f] = '\0';
        }
        iVar2 = Q_strlen(&local_84);
        iVar5 = Q_strlen(pcVar6);
        if (0x7e - iVar2 < iVar5) {
          pcVar6[0x7e - iVar2] = '\0';
        }
        Q_strcat(&local_84,pcVar6);
        Q_strcat(&local_84,&DAT_000a7505);
        iVar2 = 0;
        if (0 < DAT_001ab4e8) {
          local_90 = DAT_001ab4e4 + 0x918;
          local_94 = 0x324;
          piVar7 = DAT_001ab4e4;
          do {
            if ((((piVar7 != (int *)0x0) && (*piVar7 != 0)) && (local_90[-0x917] != 0)) &&
               (*local_90 == 0)) {
              host_client = piVar7;
              uVar4 = RegUserMsg("SayText",0xffffffff,0,local_94 + DAT_00186f94);
              PF_MessageBegin_I(1,uVar4);
              PF_WriteByte_I(0);
              PF_WriteString_I(&local_84);
              PF_MessageEnd_I();
            }
            local_94 = local_94 + 0x324;
            iVar2 = iVar2 + 1;
            local_90 = local_90 + 0x1415;
            piVar7 = piVar7 + 0x1415;
          } while (iVar2 < DAT_001ab4e8);
        }
        host_client = (int *)uVar1;
        Sys_Printf(&DAT_000a7360,local_83);
      }
    }
  }
  else if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  return;
}


// Host_Say_Team_f  @ 0005c1cc
void Host_Say_Team_f(void)

{
  Host_Say(1);
  return;
}


// Host_Say_f  @ 0005c1ac
void Host_Say_f(void)

{
  Host_Say(0);
  return;
}


// Host_SetInfo_f  @ 0005bef0
void Host_SetInfo_f(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Info_Print(&DAT_00385294);
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      if (cmd_source == 1) {
        uVar2 = Cmd_Argv(2,0x100);
        uVar2 = Cmd_Argv(1,uVar2);
        Info_SetValueForKey(&DAT_00385294,uVar2);
        Cmd_ForwardToServer();
      }
      else {
        uVar2 = Cmd_Argv(2,0x100);
        uVar2 = Cmd_Argv(1,uVar2);
        Info_SetValueForKey(host_client + 0x4af4,uVar2);
        *(undefined4 *)(host_client + 0x4bf4) = 1;
      }
    }
    else {
      Con_Printf("usage: setinfo [ <key> <value> ]\n");
    }
  }
  return;
}


// Host_Shutdown  @ 00057984
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Host_Shutdown(void)

{
  int iVar1;
  int iVar2;
  
  if (isdown_83 == 0) {
    isdown_83 = 1;
    if (host_initialized != 0) {
      Host_WriteConfiguration();
    }
    SV_ServerShutdown();
    host_initialized = 0;
    HPAK_FlushHostQueue();
    SV_DeallocateDynamicData();
    if (0 < DAT_001ab4ec) {
      iVar1 = 0;
      iVar2 = DAT_001ab4e4;
      do {
        SV_ClearFrames(iVar2 + 0x34e0);
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x5054;
      } while (iVar1 < DAT_001ab4ec);
    }
    SV_Shutdown();
    Master_Shutdown(1);
    scr_disabled_for_loading = 1;
    NET_Shutdown();
    S_Shutdown();
    Con_Shutdown();
    if (cls != 0) {
      (*VID_Shutdown)();
    }
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
    WON_ShutdownAuthentication();
    Log_Printf("Server shutdown.\n");
    Log_Close();
    COM_Shutdown();
    CL_Shutdown();
    DELTA_Shutdown();
    if (cls == 0) {
      (*_DAT_003861ac)();
    }
  }
  else {
    printf("recursive shutdown\n");
  }
  return;
}


// Host_ShutdownServer  @ 00055838
void Host_ShutdownServer(undefined4 param_1)

{
  int iVar1;
  
  if (sv != 0) {
    SV_ServerShutdown();
    sv = 0;
    NET_ClearLagData(1,1);
    if ((((cls == 5) || (cls == 3)) || (cls == 4)) || (cls == 2)) {
      host_client = DAT_001ab4e4;
      iVar1 = 0;
      if (0 < DAT_001ab4e8) {
        do {
          if (((*host_client != 0) || (host_client[3] != 0)) && (host_client[0x918] == 0)) {
            SV_DropClient(host_client,param_1);
          }
          host_client = host_client + 0x1415;
          iVar1 = iVar1 + 1;
        } while (iVar1 < DAT_001ab4e8);
      }
      CL_Disconnect();
      SV_ClearEntities();
    }
    SV_ClearCaches();
    Q_memset(&sv,0,HPAK_Init);
    CL_ClearClientState();
    SV_ClearClientStates();
    Host_ClearClients(0);
    iVar1 = 0;
    host_client = DAT_001ab4e4;
    if (0 < DAT_001ab4ec) {
      do {
        SV_ClearFrames(host_client + 0xd38);
        host_client = host_client + 0x1415;
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_001ab4ec);
    }
    Q_memset(DAT_001ab4e4,0,DAT_001ab4ec * 0x5054);
    Master_Shutdown(0);
    HPAK_FlushHostQueue();
    Log_Printf("Server shutdown.\n");
    Log_Close();
  }
  return;
}


// Host_Soundfade_f  @ 0005cf38
void Host_Soundfade_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  iVar1 = Cmd_Argc();
  if ((iVar1 != 3) && (iVar1 = Cmd_Argc(), iVar1 != 5)) {
    Con_Printf("soundfade <percent> <hold> [<out> <int>]\n");
    return;
  }
  uVar2 = Cmd_Argv(1);
  iVar1 = Q_atoi(uVar2);
  local_c = 100;
  if (iVar1 < 0x65) {
    local_c = iVar1;
  }
  if (local_c < 0) {
    local_c = 0;
  }
  uVar2 = Cmd_Argv(2);
  local_8 = Q_atoi(uVar2);
  if (0xff < local_8) {
    local_8 = 0xff;
  }
  iVar3 = 0;
  iVar4 = 0;
  iVar1 = Cmd_Argc();
  if (iVar1 == 5) {
    uVar2 = Cmd_Argv(3);
    iVar4 = Q_atoi(uVar2);
    if (0xff < iVar4) {
      iVar4 = 0xff;
    }
    uVar2 = Cmd_Argv(4);
    iVar3 = Q_atoi(uVar2);
    if (0xff < iVar3) {
      iVar3 = 0xff;
    }
  }
  DAT_003857a0 = iVar3;
  DAT_0038579c = local_8;
  DAT_00385798 = iVar4;
  DAT_00385790 = realtime;
  DAT_00385788 = local_c;
  return;
}


// Host_Speeds  @ 00056c64
void Host_Speeds(double *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  longdouble lVar10;
  uint local_1c;
  
  lVar10 = (longdouble)1000.0;
  fVar1 = (float)(((longdouble)param_1[1] - (longdouble)*param_1) * lVar10);
  fVar2 = (float)(((longdouble)param_1[2] - (longdouble)param_1[1]) * lVar10);
  fVar3 = (float)(((longdouble)param_1[3] - (longdouble)param_1[2]) * lVar10);
  fVar4 = (float)(((longdouble)param_1[4] - (longdouble)param_1[3]) * lVar10);
  fVar5 = (float)(((longdouble)param_1[5] - (longdouble)param_1[4]) * lVar10);
  fVar6 = (fVar1 + fVar2 + fVar3 + fVar4 + fVar5) * 0.001;
  if ((byte)((0.0001 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar6 == 0.0001) << 0xe) >> 8)) - 1) < 0x40) {
    fVar6 = 1.0 / fVar6;
  }
  else {
    fVar6 = 999.0;
  }
  if ((byte)(0.0 < (float)host_speeds._12_4_ |
             (byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  local_1c = 0;
  iVar9 = 0;
  if (0 < (int)DAT_00186f8c) {
    iVar7 = 0;
    uVar8 = DAT_00186f8c & 3;
    if (uVar8 != 0) {
      if (1 < uVar8) {
        if (2 < uVar8) {
          local_1c = (uint)(*DAT_00186f94 == 0);
          iVar7 = 0x324;
        }
        if (*(int *)((int)DAT_00186f94 + iVar7) == 0) {
          local_1c = local_1c + 1;
        }
        iVar7 = iVar7 + 0x324;
        iVar9 = (2 < uVar8) + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar7) == 0) {
        local_1c = local_1c + 1;
      }
      iVar7 = iVar7 + 0x324;
      iVar9 = iVar9 + 1;
      if ((int)DAT_00186f8c <= iVar9) goto LAB_00056de2;
    }
    do {
      if (*(int *)((int)DAT_00186f94 + iVar7) == 0) {
        local_1c = local_1c + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar7 + 0x324) == 0) {
        local_1c = local_1c + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar7 + 0x648) == 0) {
        local_1c = local_1c + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar7 + 0x96c) == 0) {
        local_1c = local_1c + 1;
      }
      iVar7 = iVar7 + 0xc90;
      iVar9 = iVar9 + 4;
    } while (iVar9 < (int)DAT_00186f8c);
  }
LAB_00056de2:
  Con_Printf(FUN_000a6f40,(int)ROUND(fVar6),(double)fVar1,(double)fVar2,(double)fVar3,(double)fVar4,
             (double)fVar5,local_1c);
  return;
}


// Host_Startdemos_f  @ 0005cbb4
void Host_Startdemos_f(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int local_c;
  
  if (cls == 0) {
    if (sv != 0) {
      return;
    }
    Con_Printf("Cannot play demos on a dedicated server.\n");
    return;
  }
  iVar1 = Cmd_Argc();
  uVar3 = iVar1 - 1;
  if (0x20 < (int)uVar3) {
    Con_Printf("Max %i demos in demoloop\n",0x20);
    uVar3 = 0x20;
  }
  Con_Printf("%i demo(s) in loop\n",uVar3);
  iVar4 = 1;
  iVar1 = uVar3 + 1;
  if (1 < iVar1) {
    local_c = 0x10;
    uVar3 = uVar3 & 3;
    if (uVar3 != 0) {
      if (1 < uVar3) {
        if (2 < uVar3) {
          uVar2 = Cmd_Argv(1,0xf);
          Q_strncpy(&DAT_003853a0,uVar2);
          local_c = 0x20;
          iVar4 = 2;
        }
        uVar2 = Cmd_Argv(iVar4,0xf);
        Q_strncpy(local_c + 0x385390,uVar2);
        local_c = local_c + 0x10;
        iVar4 = iVar4 + 1;
      }
      uVar2 = Cmd_Argv(iVar4,0xf);
      Q_strncpy(local_c + 0x385390,uVar2);
      local_c = local_c + 0x10;
      iVar4 = iVar4 + 1;
      if (iVar1 <= iVar4) goto LAB_0005cd90;
    }
    do {
      uVar2 = Cmd_Argv(iVar4,0xf);
      Q_strncpy(local_c + 0x385390,uVar2);
      uVar2 = Cmd_Argv(iVar4 + 1,0xf);
      Q_strncpy(&DAT_003853a0 + local_c,uVar2);
      uVar2 = Cmd_Argv(iVar4 + 2,0xf);
      Q_strncpy(&DAT_003853b0 + local_c,uVar2);
      uVar2 = Cmd_Argv(iVar4 + 3,0xf);
      Q_strncpy(&DAT_003853c0 + local_c,uVar2);
      local_c = local_c + 0x40;
      iVar4 = iVar4 + 4;
    } while (iVar4 < iVar1);
  }
LAB_0005cd90:
  if (((sv == 0) && (DAT_0038539c != -1)) && (DAT_003855a4 == 0)) {
    DAT_0038539c = 0;
    Host_NextDemo();
  }
  else {
    DAT_0038539c = 0xffffffff;
  }
  return;
}


// Host_Status_Printf  @ 00057d84
void Host_Status_Printf(int param_1,int param_2,char *param_3)

{
  char local_1108 [260];
  char local_1004 [4096];
  
  vsprintf(local_1004,param_3,&stack0x00000010);
  if (param_1 == 0) {
    SV_ClientPrintf(&DAT_000a7360,local_1004);
  }
  else {
    Con_Printf(&DAT_000a7360,local_1004);
  }
  if (param_2 != 0) {
    sprintf(local_1108,"%s/%s",com_gamedir,"status.log");
    COM_Log(local_1108,&DAT_000a7360,local_1004);
  }
  return;
}


// Host_Status_f  @ 00057e20
void Host_Status_f(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined2 in_FPUControlWord;
  int *local_138;
  float *local_134;
  int local_130;
  undefined4 local_12c;
  int local_128;
  int *local_120;
  undefined1 local_11c [4];
  int local_118;
  undefined4 local_114;
  undefined2 local_10c;
  undefined2 uStack_10a;
  char local_108 [260];
  
  local_12c = 0;
  local_130 = 1;
  if (cmd_source == 1) {
    if (sv == 0) {
      Cmd_ForwardToServer();
      return;
    }
  }
  else {
    local_130 = 0;
  }
  iVar2 = Cmd_Argc();
  if (iVar2 == 2) {
    Cmd_Argv();
    iVar2 = Q_strcasecmp();
    if (iVar2 == 0) {
      sprintf(local_108,"%s/%s");
      unlink(local_108);
      local_12c = 1;
    }
  }
  Cvar_VariableString();
  Host_Status_Printf();
  uVar3 = build_number();
  Host_Status_Printf(local_130,local_12c,"version :  %i/%s %d\n",0x2a,gpszVersionString,uVar3);
  if (noip == 0) {
    puVar4 = &net_local_adr;
    puVar6 = (undefined4 *)&stack0xfffffe98;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    uVar3 = NET_AdrToString();
    Host_Status_Printf(local_130,local_12c,"tcp/ip  :  %s\n",uVar3);
  }
  _local_10c = CONCAT22(uStack_10a,in_FPUControlWord);
  local_114 = CONCAT22(uStack_10a,CONCAT11(0xc,(char)in_FPUControlWord));
  Host_Status_Printf(local_130,local_12c);
  SV_CountPlayers(local_11c,&local_118);
  if (local_118 == 0) {
    Host_Status_Printf();
  }
  else {
    Host_Status_Printf(local_130);
  }
  Host_Status_Printf();
  local_128 = 0;
  local_120 = DAT_001ab4e4;
  if (0 < DAT_001ab4e8) {
    local_134 = (float *)(DAT_001ab4e4 + 0x92d);
    local_138 = DAT_001ab4e4 + 0x12b9;
    do {
      if (*local_120 != 0) {
        iVar2 = 0;
        local_114 = CONCAT22(uStack_10a,CONCAT11(0xc,(char)in_FPUControlWord));
        iVar1 = (int)ROUND(realtime - (double)(float)local_138[-0x12aa]) / 0x3c;
        if (iVar1 != 0) {
          iVar2 = iVar1 / 0x3c;
        }
        Host_Status_Printf(local_130,local_12c);
        _local_10c = CONCAT22(uStack_10a,in_FPUControlWord);
        local_114 = CONCAT22(uStack_10a,CONCAT11(0xc,(char)in_FPUControlWord));
        Host_Status_Printf(local_130,local_12c,&DAT_000a74dd,
                           (int)ROUND(*(float *)(*local_138 + 0x1e4)));
        if (iVar2 == 0) {
          Host_Status_Printf();
        }
        else {
          Host_Status_Printf(local_130);
        }
        SV_CalcPing();
        Host_Status_Printf();
        _local_10c = CONCAT22(uStack_10a,in_FPUControlWord);
        local_114 = CONCAT22(uStack_10a,CONCAT11(0xc,(char)in_FPUControlWord));
        Host_Status_Printf(local_130,local_12c,&DAT_000a74dd,(int)ROUND(*local_134));
        if (local_130 != 0) {
          piVar5 = local_120 + 9;
          piVar7 = (int *)&stack0xfffffe98;
          for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
            *piVar7 = *piVar5;
            piVar5 = piVar5 + 1;
            piVar7 = piVar7 + 1;
          }
          uVar3 = NET_AdrToString();
          Host_Status_Printf(local_130,local_12c,&DAT_000a7501,uVar3);
        }
        Host_Status_Printf();
      }
      local_128 = local_128 + 1;
      local_138 = local_138 + 0x1415;
      local_134 = local_134 + 0x1415;
      local_120 = local_120 + 0x1415;
    } while (local_128 < DAT_001ab4e8);
  }
  return;
}


// Host_Stopdemo_f  @ 0005ce20
void Host_Stopdemo_f(void)

{
  if ((cls != 0) && (DAT_003855a4 != 0)) {
    CL_StopPlayback();
    CL_Disconnect();
  }
  return;
}


// Host_Tell_f  @ 0005c1ec
void Host_Tell_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  int *local_54;
  int *local_48;
  undefined1 local_44 [64];
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
    iVar3 = (int)host_client;
  }
  else {
    iVar1 = Cmd_Argc();
    iVar3 = (int)host_client;
    if (2 < iVar1) {
      Q_strcpy(local_44,(int)host_client + 0x4c3c);
      Q_strcat(local_44," TELL: ");
      pcVar2 = (char *)Cmd_Args();
      iVar3 = (int)host_client;
      if (pcVar2 != (char *)0x0) {
        pcVar6 = pcVar2;
        if (*pcVar2 == '\"') {
          pcVar6 = pcVar2 + 1;
          iVar3 = Q_strlen(pcVar6);
          pcVar2[iVar3] = '\0';
        }
        iVar3 = Q_strlen(local_44);
        iVar1 = Q_strlen(pcVar6);
        if (0x3e - iVar3 < iVar1) {
          pcVar6[0x3e - iVar3] = '\0';
        }
        uVar4 = Cmd_Argv(1);
        iVar3 = Q_strstr(pcVar6,uVar4);
        if (iVar3 == 0) {
          Q_strcat(local_44,pcVar6);
        }
        else {
          uVar4 = Cmd_Argv(1);
          iVar1 = Q_strlen(uVar4);
          Q_strcat(local_44,iVar1 + iVar3);
        }
        Q_strcat(local_44,&DAT_000a7505);
        iVar3 = (int)host_client;
        iVar1 = 0;
        local_48 = DAT_001ab4e4;
        if (0 < DAT_001ab4e8) {
          local_54 = DAT_001ab4e4 + 0x130f;
          piVar7 = DAT_001ab4e4 + 0x918;
          do {
            if (((*local_48 != 0) && (piVar7[-0x917] != 0)) && (*piVar7 == 0)) {
              uVar4 = Cmd_Argv(1);
              iVar5 = Q_strcasecmp(local_54,uVar4);
              if (iVar5 == 0) {
                host_client = local_48;
                uVar4 = RegUserMsg("SayText",0xffffffff,0,DAT_00186f94 + 0x324 + iVar1 * 0x324);
                PF_MessageBegin_I(1,uVar4);
                PF_WriteByte_I(0);
                PF_WriteString_I(local_44);
                PF_MessageEnd_I();
                host_client = (int *)iVar3;
                return;
              }
            }
            iVar1 = iVar1 + 1;
            local_54 = local_54 + 0x1415;
            local_48 = local_48 + 0x1415;
            piVar7 = piVar7 + 0x1415;
          } while (iVar1 < DAT_001ab4e8);
        }
      }
    }
  }
  host_client = (int *)iVar3;
  return;
}


// Host_UpdateScreen  @ 00056e48
void Host_UpdateScreen(void)

{
  if (gfBackground == 0) {
    SCR_UpdateScreen();
    if ((cl_inmovie != 0) &&
       ((byte)((byte)((ushort)((ushort)NAN(scr_con_current) << 10) >> 8) |
              (byte)((ushort)((ushort)(scr_con_current == 0.0) << 0xe) >> 8)) == 0x40)) {
      VID_WriteBuffer(0);
    }
  }
  return;
}


// Host_UpdateSounds  @ 00056e9c
void Host_UpdateSounds(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (gfBackground == 0) {
    if (DAT_0038494c == 2) {
      puVar1 = &r_origin;
      puVar2 = (undefined4 *)vpn;
      puVar3 = (undefined4 *)vright;
      puVar4 = (undefined4 *)vup;
    }
    else {
      puVar1 = &vec3_origin;
      puVar2 = puVar1;
      puVar3 = puVar1;
      puVar4 = puVar1;
    }
    S_Update(puVar1,puVar2,puVar3,puVar4);
    S_PrintStats();
  }
  return;
}


// Host_ValidGame  @ 00058890
undefined4 Host_ValidGame(void)

{
  int iVar1;
  
  if (DAT_001ab4e8 < 2) {
    if ((Launcher_IsValidCD != (code *)0x0) && (iVar1 = (*Launcher_IsValidCD)(), iVar1 != 0)) {
      return 1;
    }
  }
  else if ((byte)((float)deathmatch._12_4_ < 0.0 |
                  (byte)((ushort)((ushort)NAN((float)deathmatch._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)deathmatch._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    return 1;
  }
  Con_DPrintf("Unable to launch game\n");
  return 0;
}


// Host_ValidSave  @ 00059374
undefined4 Host_ValidSave(void)

{
  float fVar1;
  char *pcVar2;
  
  if (cmd_source == 1) {
    if (sv == 0) {
      pcVar2 = "Not playing a local game.\n";
    }
    else if (DAT_001ab4e8 == 1) {
      if ((cls == 5) && (DAT_0038494c == 2)) {
        if (cl._176036_4_ == 0) {
          if ((*DAT_001ab4e4 == 0) ||
             (fVar1 = *(float *)(DAT_001ab4e4[0x12b9] + 0x1e0),
             (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
            return 1;
          }
          pcVar2 = "Can\'t savegame with a dead player\n";
        }
        else {
          pcVar2 = "Can\'t save in intermission.\n";
        }
      }
      else {
        pcVar2 = (char *)FUN_000a78c0;
      }
    }
    else {
      pcVar2 = "Can\'t save multiplayer games.\n";
    }
    Con_Printf(pcVar2);
  }
  return 0;
}


// Host_Version  @ 0005737c
void Host_Version(void)

{
  FILE *__stream;
  size_t __size;
  void *__ptr;
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  char local_108 [260];
  
  Q_strcpy(gpszVersionString,"1.0.1.4");
  sprintf(local_108,"sierra.inf");
  __stream = fopen(local_108,"r");
  if (__stream != (FILE *)0x0) {
    fseek(__stream,0,2);
    __size = ftell(__stream);
    fseek(__stream,0,0);
    __ptr = (void *)Mem_Malloc(__size + 1);
    fread(__ptr,__size,1,__stream);
    fclose(__stream);
    *(undefined1 *)(__size + (int)__ptr) = 0;
    pvVar1 = __ptr;
    do {
      pvVar1 = (void *)COM_Parse(pvVar1);
      if (pvVar1 == (void *)0x0) goto LAB_00057487;
      iVar2 = Q_strlen(&com_token);
      if (iVar2 < 1) goto LAB_00057487;
      uVar3 = Q_strlen("PatchVersion=");
      iVar2 = Q_strnicmp(&com_token,"PatchVersion=",uVar3);
    } while (iVar2 != 0);
    iVar2 = Q_strlen("PatchVersion=");
    Q_strcpy(gpszVersionString,&com_token + iVar2);
LAB_00057487:
    if (__ptr != (void *)0x0) {
      Mem_Free(__ptr);
    }
  }
  if (cls == 0) {
    Con_Printf(FUN_000a7060,0x2a,gpszVersionString);
    uVar3 = build_number();
    Con_Printf("Exe build: 15:09:11 Jun 23 2000 (%i)\n",uVar3);
  }
  else {
    Con_DPrintf(FUN_000a7060,0x2a,gpszVersionString);
    uVar3 = build_number();
    Con_DPrintf("Exe build: 15:09:11 Jun 23 2000 (%i)\n",uVar3);
  }
  return;
}


// Host_Version_f  @ 0005bd94
void Host_Version_f(void)

{
  undefined4 uVar1;
  
  Con_Printf("Protocol version %i\nExe version %s\n",0x2a,gpszVersionString);
  uVar1 = build_number();
  Con_Printf("Exe build: 15:09:15 Jun 23 2000 (%i)\n",uVar1);
  return;
}


// Host_Viewframe_f  @ 0005c8c0
void Host_Viewframe_f(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FindViewthing();
  if (iVar2 != 0) {
    iVar1 = *(int *)(cl + *(int *)(iVar2 + 0x134) * 4 + 0x144bdc);
    uVar3 = Cmd_Argv(1);
    iVar4 = Q_atoi(uVar3);
    if (*(int *)(iVar1 + 0x48) <= iVar4) {
      iVar4 = *(int *)(iVar1 + 0x48) + -1;
    }
    *(float *)(iVar2 + 0x1b0) = (float)iVar4;
  }
  return;
}


// Host_Viewmodel_f  @ 0005c840
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
      *(undefined4 *)(iVar1 + 0x1b0) = 0;
      *(int *)(cl + *(int *)(iVar1 + 0x134) * 4 + 0x144bdc) = iVar3;
    }
  }
  return;
}


// Host_Viewnext_f  @ 0005c970
void Host_Viewnext_f(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = FindViewthing();
  if (iVar5 != 0) {
    fVar3 = *(float *)(iVar5 + 0x1b0) + 1.0;
    iVar1 = *(int *)(cl + *(int *)(iVar5 + 0x134) * 4 + 0x144bdc);
    *(float *)(iVar5 + 0x1b0) = fVar3;
    iVar2 = *(int *)(iVar1 + 0x48);
    fVar4 = (float)iVar2;
    if ((byte)(fVar3 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) != 1) {
      *(float *)(iVar5 + 0x1b0) = (float)(iVar2 + -1);
    }
    PrintFrameName(iVar1,(int)ROUND(*(float *)(iVar5 + 0x1b0)));
  }
  return;
}


// Host_Viewprev_f  @ 0005ca0c
void Host_Viewprev_f(void)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = FindViewthing();
  if (iVar3 != 0) {
    fVar2 = *(float *)(iVar3 + 0x1b0) - 1.0;
    uVar1 = *(undefined4 *)(cl + *(int *)(iVar3 + 0x134) * 4 + 0x144bdc);
    *(float *)(iVar3 + 0x1b0) = fVar2;
    if (fVar2 < 0.0) {
      *(undefined4 *)(iVar3 + 0x1b0) = 0;
    }
    PrintFrameName(uVar1,(int)ROUND(*(float *)(iVar3 + 0x1b0)));
  }
  return;
}


// Host_WriteConfiguration  @ 00055324
void Host_WriteConfiguration(void)

{
  return;
}


