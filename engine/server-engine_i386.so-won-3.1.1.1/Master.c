// Master_AddServer  @ 0006bc58
void Master_AddServer(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 auStack_4c [5];
  int aiStack_38 [3];
  char *pcStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_8;
  
  uStack_20 = 0x6bc72;
  Master_Init();
  for (local_8 = valvemaster_adr; local_8 != 0; local_8 = *(int *)(local_8 + 0x2c)) {
    puVar3 = param_1;
    piVar4 = aiStack_38;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    puVar3 = (undefined4 *)(local_8 + 0x18);
    puVar5 = auStack_4c;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar1 = NET_CompareAdr();
    if (iVar1 != 0) break;
  }
  if (local_8 == 0) {
    pcStack_2c = (char *)0x30;
    aiStack_38[2] = 0x6bcde;
    iVar1 = Mem_Malloc();
    if (iVar1 == 0) {
      uStack_28 = 0x30;
      pcStack_2c = "Error allocating %i bytes for master address.";
      aiStack_38[2] = 0x6bcfd;
      Sys_Error();
    }
    uStack_24 = 0x30;
    uStack_28 = 0;
    aiStack_38[2] = 0x6bd10;
    pcStack_2c = (char *)iVar1;
    Q_memset();
    puVar3 = (undefined4 *)(iVar1 + 0x18);
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined8 *)(iVar1 + 0x10) = 0xc0f869f000000000;
    *(int *)(iVar1 + 0x2c) = valvemaster_adr;
    valvemaster_adr = iVar1;
  }
  return;
}


// Master_Heartbeat  @ 0006b9e4
void Master_Heartbeat(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int aiStack_50 [4];
  undefined4 uStack_40;
  int *local_c;
  undefined1 local_5;
  
  if (((gfNoMasterServer != 0) || (DAT_00524288 < 2)) || (sv == 0)) {
    return;
  }
  uStack_40 = 0x6ba2d;
  Master_Init();
  local_c = valvemaster_adr;
  do {
    while( true ) {
      while( true ) {
        if (local_c == (int *)0x0) {
          return;
        }
        if (300.0 <= realtime - *(double *)(local_c + 4)) break;
        local_c = (int *)local_c[0xb];
      }
      if (*local_c != 0) break;
LAB_0006baa8:
      *local_c = 1;
      local_c[1] = (int)(float)realtime;
      *(double *)(local_c + 4) = realtime;
      local_5 = 0x71;
      piVar4 = local_c + 6;
      piVar5 = aiStack_50;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      NET_SendPacket(1,1,&local_5);
    }
    fVar1 = (float)realtime - (float)local_c[1];
    fVar2 = (float)gfMasterHeartbeatTimeout;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) goto LAB_0006baa8;
    local_c = (int *)local_c[0xb];
  } while( true );
}


// Master_Heartbeat_f  @ 0006c244
void Master_Heartbeat_f(void)

{
  undefined4 local_8;
  
  for (local_8 = valvemaster_adr; local_8 != 0; local_8 = *(int *)(local_8 + 0x2c)) {
    *(undefined8 *)(local_8 + 0x10) = 0xc0c3878000000000;
  }
  return;
}


// Master_Init  @ 0006c334
void Master_Init(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_3b4 [2];
  char local_378 [256];
  int local_278;
  int local_274;
  int local_270;
  int local_26c;
  int local_268;
  char local_264 [64];
  undefined4 local_224 [5];
  int local_210;
  int local_20c;
  char local_208 [259];
  undefined1 local_105;
  char local_104 [256];
  
  local_26c = 0;
  if (bFirst_106 != 0) {
    bFirst_106 = 0;
    iVar1 = COM_CheckParm();
    if (iVar1 != 0) {
      Con_Printf();
      gfNoMasterServer = 1;
      return;
    }
  }
  if (((gfNoMasterServer == 0) && (1 < DAT_00524288)) && (bInitialized_105 == 0)) {
    bInitialized_105 = 1;
    strcpy(local_208,"valvecomm.lst");
    iVar1 = COM_CheckParm();
    if (iVar1 == 0) {
      sprintf(local_104,"half-life.east.won.net:27010");
      gfMasterHeartbeatTimeout = 0x402e000000000000;
    }
    else {
      sprintf(local_104,"hlmaster.valvesoftware.com:27010");
      iVar1 = strcmp(&com_gamedir,"dmc");
      if (iVar1 == 0) {
        gfMasterHeartbeatTimeout = 0x4062c00000000000;
      }
      else {
        iVar1 = strcmp(&com_gamedir,"tfc");
        if (iVar1 == 0) {
          gfMasterHeartbeatTimeout = 0x4079000000000000;
        }
        else {
          iVar1 = strcmp(&com_gamedir,"cstrike");
          if (iVar1 == 0) {
            gfMasterHeartbeatTimeout = 0x4079000000000000;
          }
          else {
            gfMasterHeartbeatTimeout = 0x4069000000000000;
          }
        }
      }
    }
    local_278 = COM_CheckParm();
    if ((local_278 != 0) && (local_278 < com_argc + -1)) {
      Q_strncpy();
      local_105 = 0;
    }
    local_210 = COM_LoadFile();
    local_20c = local_210;
    if (local_210 == 0) {
      Con_Printf();
      Master_UseDefault();
    }
    else {
LAB_0006c5d8:
      local_210 = COM_Parse();
      iVar1 = Q_strlen();
      if (0 < iVar1) {
        local_270 = 1;
        iVar1 = Q_stricmp();
        if (iVar1 == 0) {
          local_274 = 0x6982;
          local_270 = 0;
        }
        local_210 = COM_Parse();
        iVar1 = Q_strlen();
        if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 != 0)) goto LAB_0006c8dc;
        while( true ) {
          local_210 = COM_Parse();
          iVar1 = Q_strlen();
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 == 0)) break;
          snprintf(local_378,0x100,"%s");
          local_210 = COM_Parse();
          iVar1 = Q_strlen();
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 != 0)) break;
          local_210 = COM_Parse();
          iVar1 = Q_strlen();
          if (iVar1 < 1) break;
          local_268 = Q_atoi();
          if (local_268 == 0) {
            local_268 = local_274;
          }
          auStackY_3b4[1] = 0x6c84d;
          snprintf(local_264,0x40,"%s:%i");
          iVar1 = NET_StringToAdr();
          if (iVar1 == 0) {
            local_270 = 1;
          }
          if (local_270 == 0) {
            puVar2 = local_224;
            puVar3 = auStackY_3b4;
            for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            }
            NET_AdrToString();
            Con_Printf();
            Master_AddServer();
            local_26c = local_26c + 1;
          }
        }
        goto LAB_0006c5d8;
      }
LAB_0006c8dc:
      if (local_26c == 0) {
        Con_Printf();
        Master_UseDefault();
      }
      Mem_Free();
    }
  }
  return;
}


// Master_IsLanGame  @ 0006b4d4
undefined4 Master_IsLanGame(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((gfUseLANAuthentication == 0) || (iVar1 = COM_CheckParm("-steam"), iVar1 != 0)) &&
     ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// Master_RequestHeartbeat  @ 0006b540
void Master_RequestHeartbeat(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  undefined8 local_1950;
  char *pcStack_1948;
  undefined1 *puStack_1944;
  undefined4 uStack_1940;
  undefined1 local_1912 [2];
  undefined4 local_1910;
  undefined1 local_190c [260];
  undefined4 local_1808;
  undefined1 local_1804 [2048];
  char local_1004 [4096];
  
  uStack_1940 = 0x6b551;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    local_1950 = 1.9713850179229544e-308;
    iVar1 = COM_CheckParm();
    if (iVar1 != 0) {
      local_1950 = gfMasterHeartbeatTimeout;
      Con_DPrintf("Master Heartbeat timeout %f against %f",
                  (double)((float)realtime - (float)param_1[1]));
    }
    if ((float)realtime - (float)param_1[1] < (float)gfMasterHeartbeatTimeout) {
      local_1950 = 1.9713850179230414e-308;
      iVar1 = COM_CheckParm();
      if (iVar1 != 0) {
        local_1950 = 1.971578119540032e-308;
        Con_DPrintf();
      }
      local_1950 = (double)CONCAT44(&local_1808,0x6b661);
      SV_CountPlayers();
      param_1[3] = param_1[3] + 1;
      puStack_1944 = (undefined1 *)0x800;
      pcStack_1948 = (char *)0x0;
      local_1950 = (double)CONCAT44(local_1004,0x6b680);
      Q_memset();
      pcStack_1948 = local_190c;
      local_1950 = 2.872333502867963e-308;
      COM_FileBase();
      local_1910 = 0;
      if (*(char *)sv_password._4_4_ != '\0') {
        pcStack_1948 = &DAT_000e2d5d;
        local_1950 = (double)CONCAT44(sv_password._4_4_,0x6b6c9);
        iVar1 = Q_stricmp();
        if (iVar1 != 0) {
          local_1910 = 1;
        }
      }
      pcStack_1948 = &DAT_000e2d62;
      local_1950 = (double)CONCAT44(local_1912,0x6b6f5);
      Q_strcpy();
      local_1804[0] = 0;
      uStack_1940 = 0x800;
      local_1950 = 9.76122654326517e-313;
      puStack_1944 = (undefined1 *)va();
      pcStack_1948 = "protocol";
      local_1950 = (double)CONCAT44(local_1804,0x6b732);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      local_1950 = (double)CONCAT44(param_1[2],&DAT_000e2d64);
      puStack_1944 = (undefined1 *)va();
      pcStack_1948 = "challenge";
      local_1950 = (double)CONCAT44(local_1804,0x6b76d);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      local_1950 = (double)CONCAT44(local_1808,&DAT_000e2d64);
      puStack_1944 = (undefined1 *)va();
      pcStack_1948 = "players";
      local_1950 = (double)CONCAT44(local_1804,0x6b7a8);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      local_1950 = (double)CONCAT44(DAT_00524288,&DAT_000e2d64);
      puStack_1944 = (undefined1 *)va();
      pcStack_1948 = &DAT_000e2d82;
      local_1950 = (double)CONCAT44(local_1804,0x6b7e6);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      puStack_1944 = local_190c;
      pcStack_1948 = "gamedir";
      local_1950 = (double)CONCAT44(local_1804,0x6b80a);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      puStack_1944 = &DAT_0036bc88;
      pcStack_1948 = &DAT_000e2d8e;
      local_1950 = (double)CONCAT44(local_1804,0x6b831);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      if (cls == 0) {
        puStack_1944 = &DAT_000e2d92;
      }
      else {
        puStack_1944 = &DAT_000e2d62;
      }
      pcStack_1948 = &DAT_000e2d94;
      local_1950 = (double)CONCAT44(local_1804,0x6b86e);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      local_1950 = (double)CONCAT44(local_1910,&DAT_000e2d64);
      puStack_1944 = (undefined1 *)va();
      pcStack_1948 = "password";
      local_1950 = (double)CONCAT44(local_1804,0x6b8a9);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      puStack_1944 = local_1912;
      pcStack_1948 = &DAT_000e2da2;
      local_1950 = (double)CONCAT44(local_1804,0x6b8cd);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      if (DAT_00524368 == 0) {
        puStack_1944 = &DAT_000e2a7f;
      }
      else {
        puStack_1944 = &DAT_000e2a8f;
      }
      pcStack_1948 = "secure";
      local_1950 = (double)CONCAT44(local_1804,0x6b90e);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      puStack_1944 = (undefined1 *)0x6b91b;
      iVar1 = Master_IsLanGame();
      if (iVar1 == 0) {
        puStack_1944 = &DAT_000e2a7f;
      }
      else {
        puStack_1944 = &DAT_000e2a8f;
      }
      pcStack_1948 = &DAT_000e2dac;
      local_1950 = (double)CONCAT44(local_1804,0x6b94a);
      Info_SetValueForKey();
      uStack_1940 = 0x800;
      puStack_1944 = gpszVersionString;
      pcStack_1948 = "version";
      local_1950 = (double)CONCAT44(local_1804,0x6b970);
      Info_SetValueForKey();
      local_1950 = (double)CONCAT44(local_1804,0x30);
      snprintf(local_1004,0x1000,"%c\n%s\n");
      piVar3 = param_1 + 6;
      piVar4 = (int *)&local_1950;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      pcVar5 = local_1004;
      uVar2 = Q_strlen(local_1004);
      NET_SendPacket(1,uVar2,pcVar5);
    }
    else {
      local_1950 = 1.971385017923016e-308;
      iVar1 = COM_CheckParm();
      if (iVar1 != 0) {
        local_1950 = 1.9715356796241875e-308;
        Con_DPrintf();
      }
    }
  }
  return;
}


// Master_SetMaster_f  @ 0006bd58
void Master_SetMaster_f(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_10c [4];
  int local_c8;
  int local_c4;
  undefined4 local_c0 [5];
  char local_ac [20];
  char *local_98;
  int local_94;
  char local_90 [128];
  char *local_10;
  undefined4 local_c;
  int local_8;
  
  local_94 = 0x6982;
  snprintf(local_ac,0x14,"%i");
  local_8 = Cmd_Argc();
  if ((local_8 < 2) || (4 < local_8)) {
    Con_Printf();
    local_c4 = valvemaster_adr;
    if (valvemaster_adr == 0) {
      Con_Printf();
    }
    else {
      Con_Printf();
      for (; local_c4 != 0; local_c4 = *(int *)(local_c4 + 0x2c)) {
        puVar2 = (undefined4 *)(local_c4 + 0x18);
        puVar3 = auStackY_10c + 3;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        auStackY_10c[2] = 0x6be49;
        NET_AdrToString();
        Con_Printf();
      }
    }
  }
  else {
    local_98 = (char *)Cmd_Argv();
    if ((local_98 != (char *)0x0) && (*local_98 != '\0')) {
      iVar1 = Q_stricmp();
      if (iVar1 == 0) {
        gfNoMasterServer = 1;
      }
      else {
        iVar1 = Q_stricmp();
        if (iVar1 == 0) {
          gfNoMasterServer = 0;
        }
        else {
          iVar1 = Q_stricmp();
          if ((iVar1 == 0) || (iVar1 = Q_stricmp(), iVar1 == 0)) {
            local_c = Cmd_Argv();
            if (local_8 == 4) {
              local_10 = (char *)Cmd_Argv();
              if ((local_10 == (char *)0x0) || (*local_10 == '\0')) {
                local_10 = local_ac;
              }
              else {
                local_94 = Q_atoi();
                if (local_94 == 0) {
                  local_94 = 0x6982;
                }
              }
            }
            auStackY_10c[3] = 0x6c01d;
            snprintf(local_90,0x80,"%s:%i");
            iVar1 = NET_StringToAdr();
            if (iVar1 == 0) {
              Con_Printf();
            }
            else {
              iVar1 = Q_stricmp();
              if (iVar1 == 0) {
                Master_Init();
                Master_AddServer();
                gfNoMasterServer = 0;
                Con_Printf();
              }
              else {
                Master_Init();
                if (valvemaster_adr == 0) {
                  Con_Printf();
                }
                else {
                  for (local_c8 = valvemaster_adr; local_c8 != 0;
                      local_c8 = *(int *)(local_c8 + 0x2c)) {
                    puVar2 = local_c0;
                    puVar3 = (undefined4 *)&stack0xffffff08;
                    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                      *puVar3 = *puVar2;
                      puVar2 = puVar2 + 1;
                      puVar3 = puVar3 + 1;
                    }
                    puVar2 = (undefined4 *)(local_c8 + 0x18);
                    puVar3 = auStackY_10c;
                    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                      *puVar3 = *puVar2;
                      puVar2 = puVar2 + 1;
                      puVar3 = puVar3 + 1;
                    }
                    iVar1 = NET_CompareAdr();
                    if (iVar1 != 0) break;
                  }
                  if (local_c8 == 0) {
                    Con_Printf();
                  }
                  else if (local_c8 == valvemaster_adr) {
                    valvemaster_adr = *(int *)(valvemaster_adr + 0x2c);
                    Mem_Free();
                  }
                  else {
                    for (local_c4 = valvemaster_adr;
                        (local_c4 != 0 && (*(int *)(local_c4 + 0x2c) != local_c8));
                        local_c4 = *(int *)(local_c4 + 0x2c)) {
                    }
                    if (local_c4 != 0) {
                      *(undefined4 *)(local_c4 + 0x2c) = *(undefined4 *)(local_c8 + 0x2c);
                      Mem_Free();
                    }
                  }
                }
              }
            }
          }
          else {
            Con_Printf();
          }
        }
      }
    }
  }
  return;
}


// Master_Shutdown  @ 0006bb08
void Master_Shutdown(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uStack_840;
  int local_808;
  char local_804 [2048];
  
  if ((((gfNoMasterServer == 0) && (1 < DAT_00524288)) && (iVar1 = NET_IsConfigured(), iVar1 != 0))
     && (svs != 0)) {
    Master_Init();
    uStack_840 = 0x6bb79;
    snprintf(local_804,0x800,"%c\n");
    for (local_808 = valvemaster_adr; local_808 != 0; local_808 = *(int *)(local_808 + 0x2c)) {
      puVar3 = (undefined4 *)(local_808 + 0x18);
      puVar4 = &uStack_840;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      pcVar5 = local_804;
      uVar2 = Q_strlen(local_804);
      NET_SendPacket(1,uVar2,pcVar5);
    }
    if (param_1 != 0) {
      local_808 = valvemaster_adr;
      while (local_808 != 0) {
        local_808 = *(int *)(local_808 + 0x2c);
        uStack_840 = 0x6bc2a;
        Mem_Free();
      }
      valvemaster_adr = 0;
    }
  }
  return;
}


// Master_UseDefault  @ 0006c28c
void Master_UseDefault(void)

{
  int iVar1;
  undefined1 local_118 [20];
  char local_104 [256];
  
  iVar1 = COM_CheckParm("-steam");
  if (iVar1 == 0) {
    sprintf(local_104,"half-life.east.won.net:27010");
  }
  else {
    sprintf(local_104,"hlmaster.valvesoftware.com:27010");
  }
  iVar1 = NET_StringToAdr(local_104,local_118);
  if (iVar1 != 0) {
    Master_AddServer(local_118);
  }
  return;
}


