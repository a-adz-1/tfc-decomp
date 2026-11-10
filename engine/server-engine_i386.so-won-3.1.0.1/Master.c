// Master_AddServer  @ 000562e8
void Master_AddServer(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 auStack_3c [5];
  int aiStack_28 [3];
  char *pcStack_1c;
  undefined4 uStack_18;
  int local_8;
  
  uStack_18 = 0x56302;
  Master_Init();
  local_8 = valvemaster_adr;
  if (valvemaster_adr != 0) {
    do {
      puVar3 = param_1;
      piVar4 = aiStack_28;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      puVar3 = (undefined4 *)(local_8 + 0x18);
      puVar5 = auStack_3c;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar1 = NET_CompareAdr();
    } while ((iVar1 == 0) && (local_8 = *(int *)(local_8 + 0x2c), local_8 != 0));
    if (local_8 != 0) {
      return;
    }
  }
  uStack_18 = 0x30;
  pcStack_1c = (char *)0x5635d;
  iVar1 = Mem_Malloc();
  if (iVar1 == 0) {
    uStack_18 = 0x30;
    pcStack_1c = "Error allocating %i bytes for master address.";
    aiStack_28[2] = 0x56375;
    Sys_Error();
  }
  uStack_18 = 0x30;
  pcStack_1c = (char *)0x0;
  aiStack_28[1] = 0x56385;
  aiStack_28[2] = iVar1;
  Q_memset();
  puVar3 = (undefined4 *)(iVar1 + 0x18);
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0xc0f869f0;
  *(int *)(iVar1 + 0x2c) = valvemaster_adr;
  valvemaster_adr = iVar1;
  return;
}


// Master_Heartbeat  @ 00056034
void Master_Heartbeat(void)

{
  int *piVar1;
  double dVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int aiStack_34 [4];
  undefined4 uStack_24;
  undefined1 local_9;
  float local_8;
  
  if ((((gfNoMasterServer == 0) && (gfUseLANAuthentication == 0)) &&
      ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((1 < DAT_001ab4e8 && (sv != 0)))) {
    uStack_24 = 0x560a6;
    Master_Init();
    piVar1 = valvemaster_adr;
    while (piVar1 != (int *)0x0) {
      if ((realtime - *(double *)(piVar1 + 4) < 300.0) ||
         ((*piVar1 != 0 &&
          (dVar2 = realtime - (double)(float)piVar1[1],
          0x3f < (byte)((15.0 < dVar2 | (byte)((ushort)((ushort)NAN(dVar2) << 10) >> 8) |
                        (byte)((ushort)((ushort)(dVar2 == 15.0) << 0xe) >> 8)) - 1))))) {
        piVar1 = (int *)piVar1[0xb];
      }
      else {
        *piVar1 = 1;
        local_8 = (float)realtime;
        piVar1[1] = (int)local_8;
        local_9 = 0x71;
        *(double *)(piVar1 + 4) = realtime;
        piVar4 = piVar1 + 6;
        piVar5 = aiStack_34;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
        NET_SendPacket(1,1,&local_9);
      }
    }
  }
  return;
}


// Master_Heartbeat_f  @ 00056710
void Master_Heartbeat_f(void)

{
  int iVar1;
  
  for (iVar1 = valvemaster_adr; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0xc0c38780;
  }
  return;
}


// Master_Init  @ 0005679c
void Master_Init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  int local_368;
  char acStack_35c [256];
  char acStack_25c [64];
  undefined4 auStack_21c [5];
  char acStack_208 [260];
  char acStack_104 [256];
  
  local_368 = 0;
  if (bFirst_50 != 0) {
    bFirst_50 = 0;
    iVar1 = COM_CheckParm();
    if (iVar1 != 0) {
      Con_Printf();
      gfNoMasterServer = 1;
      return;
    }
  }
  if ((((gfNoMasterServer == 0) && (gfUseLANAuthentication == 0)) &&
      ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((1 < DAT_001ab4e8 && (bInitialized_49 == 0)))) {
    bInitialized_49 = 1;
    sprintf(acStack_104,"half-life.east.won.net:27010");
    sprintf(acStack_208,"%s");
    iVar1 = COM_CheckParm(&UNK_000a6e76);
    if ((iVar1 != 0) && (iVar1 < com_argc + -1)) {
      Q_strcpy();
    }
    iVar1 = COM_LoadFile();
    if (iVar1 == 0) {
      Con_Printf();
      Master_UseDefault();
    }
    else {
LAB_00056904:
      COM_Parse();
      iVar1 = Q_strlen();
      if (0 < iVar1) {
        iVar1 = Q_stricmp();
        bVar5 = iVar1 != 0;
        COM_Parse();
        iVar1 = Q_strlen();
        if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 != 0)) goto LAB_00056b34;
        while( true ) {
          COM_Parse();
          iVar1 = Q_strlen();
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 == 0)) break;
          sprintf(acStack_35c,"%s");
          COM_Parse();
          iVar1 = Q_strlen();
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 != 0)) break;
          COM_Parse();
          iVar1 = Q_strlen();
          if (iVar1 < 1) break;
          Q_atoi();
          sprintf(acStack_25c,"%s:%i");
          iVar1 = NET_StringToAdr(acStack_25c);
          if (iVar1 == 0) {
            bVar5 = true;
          }
          if (!bVar5) {
            puVar3 = auStack_21c;
            puVar4 = (undefined4 *)&stack0xfffffc68;
            for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + 1;
              puVar4 = puVar4 + 1;
            }
            uVar2 = NET_AdrToString();
            Con_Printf("Adding master server %s\n",uVar2);
            Master_AddServer(auStack_21c);
            local_368 = local_368 + 1;
          }
        }
        goto LAB_00056904;
      }
LAB_00056b34:
      if (local_368 == 0) {
        Con_Printf();
        Master_UseDefault();
      }
      Mem_Free();
    }
  }
  return;
}


// Master_RequestHeartbeat  @ 00055ce8
void Master_RequestHeartbeat(int *param_1)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  char **ppcVar5;
  undefined2 in_FPUControlWord;
  char *apcStack_194c [4];
  undefined4 uStack_193c;
  undefined4 uStack_1918;
  undefined4 uStack_1914;
  undefined2 uStack_190c;
  undefined2 uStack_190a;
  undefined1 auStack_1908 [260];
  char acStack_1804 [2048];
  char acStack_1004 [4096];
  
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    dVar1 = realtime - (double)(float)param_1[1];
    if (0x3f < (byte)((15.0 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar1 == 15.0) << 0xe) >> 8)) - 1)) {
      uStack_193c = 0;
      apcStack_194c[3] = (char *)&uStack_1918;
      apcStack_194c[2] = (char *)0x55d47;
      SV_CountPlayers();
      param_1[3] = param_1[3] + 1;
      apcStack_194c[2] = (char *)0x800;
      apcStack_194c[1] = (char *)0x0;
      apcStack_194c[0] = acStack_1004;
      Q_memset();
      COM_FileBase(com_gamedir,auStack_1908);
      acStack_1804[0] = '\0';
      uVar2 = va(&DAT_000a6bb0,DAT_001ab4e8,0x800);
      Info_SetValueForKey(acStack_1804,&UNK_000a6bb3,uVar2);
      uStack_193c = 0x800;
      apcStack_194c[3] = (char *)DAT_001ab53c;
      apcStack_194c[1] = (char *)0x55dd2;
      apcStack_194c[2] = &DAT_000a6bb0;
      apcStack_194c[3] = (char *)va();
      apcStack_194c[2] = &UNK_000a6bb9;
      apcStack_194c[0] = "h";
      apcStack_194c[1] = acStack_1804;
      Info_SetValueForKey();
      apcStack_194c[0] = (char *)0x800;
      uVar2 = va(&DAT_000a6bb0,DAT_001ab540);
      Info_SetValueForKey(acStack_1804,&UNK_000a6bbe,uVar2);
      uStack_193c = 0x800;
      uStack_1914 = CONCAT22(uStack_190a,CONCAT11(0xc,(char)in_FPUControlWord));
      apcStack_194c[3] = (char *)(int)ROUND(DAT_001ab534);
      apcStack_194c[1] = (char *)0x55e51;
      apcStack_194c[2] = &DAT_000a6bb0;
      apcStack_194c[3] = (char *)va();
      apcStack_194c[2] = &UNK_000a6bc3;
      apcStack_194c[0] = "h";
      apcStack_194c[1] = acStack_1804;
      Info_SetValueForKey();
      apcStack_194c[0] = (char *)0x800;
      uStack_1914 = CONCAT22(uStack_190a,CONCAT11(0xc,(char)in_FPUControlWord));
      uVar2 = va(&DAT_000a6bb0,(int)ROUND(DAT_001ab538));
      Info_SetValueForKey(acStack_1804,"empty",uVar2);
      uStack_193c = 0x800;
      uStack_1914 = CONCAT22(uStack_190a,CONCAT11(0xc,(char)in_FPUControlWord));
      apcStack_194c[3] = (char *)(int)ROUND(DAT_001ab548);
      apcStack_194c[1] = (char *)0x55efc;
      apcStack_194c[2] = &DAT_000a6bb0;
      apcStack_194c[3] = (char *)va();
      apcStack_194c[2] = &UNK_000a6bce;
      apcStack_194c[0] = "h";
      apcStack_194c[1] = acStack_1804;
      Info_SetValueForKey();
      apcStack_194c[0] = (char *)0x800;
      uStack_1914 = CONCAT22(uStack_190a,CONCAT11(0xc,(char)in_FPUControlWord));
      uVar2 = va(&DAT_000a6bb0,(int)ROUND(DAT_001ab554));
      Info_SetValueForKey(acStack_1804,&UNK_000a6bd1,uVar2);
      uStack_193c = 0x800;
      _uStack_190c = CONCAT22(uStack_190a,in_FPUControlWord);
      uStack_1914 = CONCAT22(uStack_190a,CONCAT11(0xc,(char)in_FPUControlWord));
      apcStack_194c[3] = (char *)(int)ROUND(DAT_001ab55c * 1000.0);
      apcStack_194c[1] = (char *)0x55fad;
      apcStack_194c[2] = &DAT_000a6bb0;
      apcStack_194c[3] = (char *)va();
      apcStack_194c[2] = &UNK_000a6bd8;
      apcStack_194c[0] = (char *)0x55fc0;
      apcStack_194c[1] = acStack_1804;
      Info_SetValueForKey();
      apcStack_194c[0] = acStack_1804;
      sprintf(acStack_1004,"%c\n%i\n%i\n%i\n%i\n%s\n%s\n",0x61,param_1[2],param_1[3],uStack_1918,
              0x2a,auStack_1908);
      piVar4 = param_1 + 6;
      ppcVar5 = apcStack_194c;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppcVar5 = (char *)*piVar4;
        piVar4 = piVar4 + 1;
        ppcVar5 = ppcVar5 + 1;
      }
      uVar2 = Q_strlen(acStack_1004,acStack_1004);
      NET_SendPacket(1,uVar2);
    }
  }
  return;
}


// Master_SetMaster_f  @ 000563c4
void Master_SetMaster_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char **ppcVar4;
  char *pcVar5;
  char **ppcVar6;
  int *piVar7;
  int aiStackY_fc [2];
  undefined *puStackY_f4;
  int iStackY_f0;
  char *pcStackY_ec;
  char *pcStackY_e8;
  char *pcStack_d8;
  char *pcStack_c8;
  int iStack_bc;
  char *pcStack_b8;
  char acStack_ac [20];
  char local_98 [20];
  char acStack_84 [128];
  
  pcVar5 = (char *)0x6982;
  pcStack_d8 = (char *)0x6982;
  sprintf(local_98,"%i");
  iVar1 = Cmd_Argc();
  if (iVar1 - 2U < 3) {
    pcStack_d8 = (char *)0x1;
    pcVar2 = (char *)Cmd_Argv();
    if (pcVar2 == (char *)0x0) {
      return;
    }
    if (*pcVar2 == '\0') {
      return;
    }
    pcStack_d8 = "disable";
    iVar3 = Q_stricmp();
    if (iVar3 == 0) {
      gfNoMasterServer = 1;
      return;
    }
    pcStack_d8 = "enable";
    iVar3 = Q_stricmp();
    if (iVar3 == 0) {
      gfNoMasterServer = 0;
      return;
    }
    pcStack_d8 = "add";
    iVar3 = Q_stricmp();
    if (iVar3 == 0) {
LAB_0005654c:
      pcStack_d8 = (char *)0x2;
      Cmd_Argv();
      if (iVar1 == 4) {
        pcStack_d8 = (char *)0x3;
        pcStack_d8 = (char *)Cmd_Argv();
        if (((pcStack_d8 != (char *)0x0) && (*pcStack_d8 != '\0')) &&
           (pcVar5 = (char *)Q_atoi(), pcVar5 == (char *)0x0)) {
          pcVar5 = (char *)0x6982;
        }
      }
      pcStackY_e8 = (char *)0x565aa;
      pcStack_d8 = pcVar5;
      sprintf(acStack_84,"%s:%i");
      iStackY_f0 = 0x565c3;
      pcStackY_ec = acStack_84;
      pcStackY_e8 = acStack_ac;
      iVar1 = NET_StringToAdr();
      if (iVar1 == 0) {
        ppcVar4 = &pcStack_d8;
        pcVar5 = " Invalid address \"%s\", setmaster command ignored\n";
        pcStack_d8 = acStack_84;
      }
      else {
        pcStack_d8 = "add";
        iVar1 = Q_stricmp();
        if (iVar1 == 0) {
          pcStack_d8 = (char *)0x565f5;
          Master_Init();
          pcStack_d8 = acStack_ac;
          Master_AddServer();
          gfNoMasterServer = 0;
          ppcVar4 = (char **)&stack0xffffff24;
          pcVar5 = "Adding master at %s\n";
        }
        else {
          pcStack_d8 = (char *)0x56625;
          Master_Init();
          pcStack_c8 = valvemaster_adr;
          if (valvemaster_adr == (char *)0x0) {
            pcStack_d8 = "Can\'t remove master, list is empty\n";
            goto LAB_00056637;
          }
          do {
            pcVar5 = acStack_ac;
            ppcVar6 = &pcStackY_e8;
            for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
              *ppcVar6 = (char *)*(undefined4 *)pcVar5;
              pcVar5 = pcVar5 + 4;
              ppcVar6 = ppcVar6 + 1;
            }
            pcVar5 = pcStack_c8 + 0x18;
            piVar7 = aiStackY_fc;
            for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
              *piVar7 = *(undefined4 *)pcVar5;
              pcVar5 = pcVar5 + 4;
              piVar7 = piVar7 + 1;
            }
            iVar1 = NET_CompareAdr();
          } while ((iVar1 == 0) &&
                  (pcStack_c8 = *(char **)(pcStack_c8 + 0x2c), pcStack_c8 != (char *)0x0));
          if (pcStack_c8 != (char *)0x0) {
            if (pcStack_c8 == valvemaster_adr) {
              valvemaster_adr = *(char **)(pcStack_c8 + 0x2c);
            }
            else {
              pcVar5 = valvemaster_adr;
              if (valvemaster_adr == (char *)0x0) {
                return;
              }
              do {
                pcVar2 = *(char **)(pcVar5 + 0x2c);
                if (pcVar2 == pcStack_c8) break;
                pcVar5 = pcVar2;
              } while (pcVar2 != (char *)0x0);
              if (pcVar5 == (char *)0x0) {
                return;
              }
              *(undefined4 *)(pcVar5 + 0x2c) = *(undefined4 *)(pcStack_c8 + 0x2c);
            }
            pcStack_d8 = pcStack_c8;
            Mem_Free();
            return;
          }
          ppcVar4 = &pcStack_d8;
          pcVar5 = "Can\'t remove master %s, not in list\n";
          pcStack_d8 = acStack_84;
        }
      }
    }
    else {
      pcStack_d8 = "remove";
      iVar3 = Q_stricmp();
      if (iVar3 == 0) goto LAB_0005654c;
      ppcVar4 = &pcStack_d8;
      pcVar5 = "Setmaster:  Unknown command %s\n";
      pcStack_d8 = pcVar2;
    }
    *(char **)((int)ppcVar4 + -4) = pcVar5;
    *(code **)((int)ppcVar4 + -8) = FUN_000566b0;
    Con_Printf();
  }
  else {
    pcStack_d8 = "Usage:\nSetmaster <add | remove | enable | disable> <IP:port>\n";
    Con_Printf();
    pcStack_b8 = valvemaster_adr;
    if (valvemaster_adr != (char *)0x0) {
      iStack_bc = 1;
      pcStack_d8 = "Current:\n";
      Con_Printf();
      do {
        pcVar5 = pcStack_b8 + 0x18;
        ppcVar6 = &pcStackY_e8;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *ppcVar6 = (char *)*(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          ppcVar6 = ppcVar6 + 1;
        }
        pcStackY_ec = (char *)0x56473;
        pcStackY_ec = (char *)NET_AdrToString();
        puStackY_f4 = &UNK_000a6cd8;
        iStackY_f0 = iStack_bc;
        iStack_bc = iStack_bc + 1;
        aiStackY_fc[1] = 0x5648e;
        Con_Printf();
        pcStack_b8 = *(char **)(pcStack_b8 + 0x2c);
      } while (pcStack_b8 != (char *)0x0);
      return;
    }
    pcStack_d8 = "Current:  None\n";
LAB_00056637:
    Con_Printf();
  }
  return;
}


// Master_Shutdown  @ 0005616c
void Master_Shutdown(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_82c [2];
  char local_804 [2048];
  
  if ((((gfNoMasterServer == 0) && (gfUseLANAuthentication == 0)) &&
      ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (((1 < DAT_001ab4e8 && (iVar1 = NET_IsConfigured(), iVar1 != 0)) && (svs != 0)))) {
    Master_Init();
    auStack_82c[1] = 0x56203;
    sprintf(local_804,"%c\n");
    iVar3 = valvemaster_adr;
    for (iVar1 = valvemaster_adr; valvemaster_adr = iVar3, iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 0x2c)) {
      if (param_1 != 0) {
        puVar4 = (undefined4 *)(iVar1 + 0x18);
        puVar5 = auStack_82c;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        uVar2 = NET_AdrToString();
        Con_DPrintf("Sending shutdown to %s\n",uVar2);
      }
      puVar4 = (undefined4 *)(iVar1 + 0x18);
      puVar5 = auStack_82c;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      uVar2 = Q_strlen(local_804,local_804);
      NET_SendPacket(1,uVar2);
      iVar3 = valvemaster_adr;
    }
    if (param_1 != 0) {
      while (iVar3 != 0) {
        iVar3 = *(int *)(iVar3 + 0x2c);
        Mem_Free();
      }
      valvemaster_adr = 0;
    }
  }
  return;
}


// Master_UseDefault  @ 00056748
void Master_UseDefault(void)

{
  int iVar1;
  undefined1 local_118 [20];
  char local_104 [256];
  
  sprintf(local_104,"half-life.east.won.net:27010");
  iVar1 = NET_StringToAdr(local_104,local_118);
  if (iVar1 != 0) {
    Master_AddServer(local_118);
  }
  return;
}


