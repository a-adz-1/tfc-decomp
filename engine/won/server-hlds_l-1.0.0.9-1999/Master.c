// Master_AddServer  @ 080584d0
void Master_AddServer(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  undefined4 auStackY_38 [5];
  char *apcStackY_24 [4];
  
  Master_Init();
  iVar3 = (int)valvemaster_adr;
  if (valvemaster_adr != (undefined4 *)0x0) {
    do {
      puVar1 = param_1;
      ppcVar4 = apcStackY_24;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppcVar4 = (char *)*puVar1;
        puVar1 = puVar1 + 1;
        ppcVar4 = ppcVar4 + 1;
      }
      puVar1 = (undefined4 *)(iVar3 + 0x18);
      puVar5 = auStackY_38;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar2 = NET_CompareAdr();
    } while ((iVar2 == 0) && (iVar3 = *(int *)(iVar3 + 0x2c), iVar3 != 0));
    if (iVar3 != 0) {
      return;
    }
  }
  apcStackY_24[3] = (char *)0x8058526;
  puVar1 = malloc(0x30);
  if (puVar1 == (undefined4 *)0x0) {
    apcStackY_24[3] = "Error allocating %i bytes for master address.";
    apcStackY_24[2] = (char *)0x805853b;
    Sys_Error();
  }
  puVar5 = puVar1;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = puVar1 + 6;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *param_1;
    param_1 = param_1 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar1[4] = 0;
  puVar1[5] = 0xc0f869f0;
  puVar1[0xb] = valvemaster_adr;
  valvemaster_adr = puVar1;
  return;
}


// Master_Heartbeat  @ 08058280
void Master_Heartbeat(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int aiStack_2c [4];
  undefined4 uStack_1c;
  undefined1 local_9;
  float local_8;
  
  if ((((gfNoMasterServer == 0) && (gfUseLANAuthentication == 0)) &&
      ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((1 < svs && (sv != 0)))) {
    uStack_1c = 0x80582da;
    Master_Init();
    piVar2 = valvemaster_adr;
    while (piVar2 != (int *)0x0) {
      if ((realtime - *(double *)(piVar2 + 4) < 300.0) ||
         ((*piVar2 != 0 && ((float)realtime - (float)piVar2[1] < 15.0)))) {
        piVar2 = (int *)piVar2[0xb];
      }
      else {
        *piVar2 = 1;
        local_8 = (float)realtime;
        piVar2[1] = (int)local_8;
        *(double *)(piVar2 + 4) = (double)local_8;
        local_9 = 0x71;
        piVar3 = piVar2 + 6;
        piVar4 = aiStack_2c;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar4 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar4 = piVar4 + 1;
        }
        NET_SendPacket(1,1,&local_9);
      }
    }
  }
  return;
}


// Master_Heartbeat_f  @ 080588a0
void Master_Heartbeat_f(void)

{
  int iVar1;
  
  for (iVar1 = valvemaster_adr; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0xc0c38780;
  }
  return;
}


// Master_Init  @ 08058920
void Master_Init(void)

{
  char cVar1;
  int iVar2;
  void *__ptr;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  int local_368;
  char local_35c [256];
  char local_25c [64];
  undefined4 local_21c [5];
  char local_208 [260];
  char local_104 [256];
  
  local_368 = 0;
  if ((((gfNoMasterServer == 0) && (gfUseLANAuthentication == 0)) &&
      ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((1 < svs && (bInitialized_153 == 0)))) {
    bInitialized_153 = 1;
    sprintf(local_104,"half-life.east.won.net:27010");
    sprintf(local_208,"%s");
    iVar2 = COM_CheckParm("-comm");
    if ((iVar2 != 0) && (iVar2 < com_argc + -1)) {
      strcpy(local_208,*(char **)(com_argv + 4 + iVar2 * 4));
    }
    __ptr = (void *)COM_LoadFile();
    if (__ptr == (void *)0x0) {
      Con_Printf();
      Master_UseDefault();
    }
    else {
LAB_08058a2c:
      COM_Parse();
      iVar2 = -1;
      pcVar5 = &com_token;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (iVar2 != -2) {
        iVar2 = strcasecmp(&com_token,"Master");
        bVar7 = iVar2 != 0;
        COM_Parse();
        iVar2 = -1;
        pcVar5 = &com_token;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        if ((iVar2 != -2) && (iVar2 = strcasecmp(&com_token,"{"), iVar2 == 0)) {
          do {
            COM_Parse();
            iVar2 = -1;
            pcVar5 = &com_token;
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            if ((iVar2 == -2) || (iVar2 = strcasecmp(&com_token,"}"), iVar2 == 0))
            goto LAB_08058a2c;
            sprintf(local_35c,"%s");
            COM_Parse();
            iVar2 = -1;
            pcVar5 = &com_token;
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            if ((iVar2 == -2) || (iVar2 = strcasecmp(&com_token,":"), iVar2 != 0))
            goto LAB_08058a2c;
            COM_Parse();
            iVar2 = -1;
            pcVar5 = &com_token;
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            if (iVar2 == -2) goto LAB_08058a2c;
            __strtol_internal();
            sprintf(local_25c,"%s:%i");
            iVar2 = NET_StringToAdr(local_25c);
            if (iVar2 == 0) {
              bVar7 = true;
            }
            if (!bVar7) {
              puVar4 = local_21c;
              puVar6 = (undefined4 *)&stack0xfffffc70;
              for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar6 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar6 = puVar6 + 1;
              }
              uVar3 = NET_AdrToString();
              Con_Printf("Adding master server %s\n",uVar3);
              Master_AddServer(local_21c);
              local_368 = local_368 + 1;
            }
          } while( true );
        }
      }
      if (local_368 == 0) {
        Con_Printf();
        Master_UseDefault();
      }
      free(__ptr);
    }
  }
  return;
}


// Master_RequestHeartbeat  @ 08058180
void Master_RequestHeartbeat(int *param_1)

{
  char cVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  char *pcVar8;
  undefined4 *apuStack_138 [4];
  undefined4 uStack_128;
  undefined4 local_10c;
  undefined4 local_108 [65];
  
  if (((gfUseLANAuthentication == 0) && (param_1 != (int *)0x0)) && (*param_1 == 0)) {
    fVar2 = (float)realtime - (float)param_1[1];
    if (0x3f < (byte)((15.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == 15.0) << 0xe) >> 8)) - 1)) {
      uStack_128 = 0x80581d5;
      Master_Init();
      uStack_128 = 0;
      apuStack_138[3] = &local_10c;
      apuStack_138[2] = (undefined4 *)0x80581e3;
      SV_CountPlayers();
      param_1[3] = param_1[3] + 1;
      puVar6 = (undefined4 *)&string_138;
      for (iVar3 = 0x200; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      apuStack_138[1] = (undefined4 *)com_gamedir;
      apuStack_138[0] = (undefined4 *)0x805820b;
      apuStack_138[2] = local_108;
      COM_FileBase();
      apuStack_138[0] = local_108;
      sprintf(&string_138,"%c\n%i\n%i\n%i\n%i\n%s\n",0x61,param_1[2],param_1[3],local_10c,
              PROTOCOL_VERSION);
      piVar5 = param_1 + 6;
      ppuVar7 = apuStack_138;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppuVar7 = (undefined4 *)*piVar5;
        piVar5 = piVar5 + 1;
        ppuVar7 = ppuVar7 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar8 = &string_138;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      NET_SendPacket(1,~uVar4 - 1,&string_138);
    }
  }
  return;
}


// Master_SetMaster_f  @ 08058580
void Master_SetMaster_f(void)

{
  int iVar1;
  char *__s1;
  int iVar2;
  char *pcVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  char **ppcVar8;
  char *apcStackY_e8 [3];
  int iStackY_dc;
  char *pcStackY_d8;
  undefined4 *puStackY_d4;
  int local_b4;
  undefined4 local_ac [5];
  char local_98 [20];
  char local_84 [128];
  
  sprintf(local_98,"%i");
  Master_Init();
  iVar1 = Cmd_Argc();
  if (iVar1 - 2U < 3) {
    __s1 = (char *)Cmd_Argv();
    if ((__s1 != (char *)0x0) && (*__s1 != '\0')) {
      iVar2 = strcasecmp(__s1,"disable");
      if (iVar2 == 0) {
        gfNoMasterServer = 1;
      }
      else {
        iVar2 = strcasecmp(__s1,"enable");
        if (iVar2 == 0) {
          gfNoMasterServer = 0;
        }
        else {
          iVar2 = strcasecmp(__s1,"add");
          if ((iVar2 == 0) || (iVar2 = strcasecmp(__s1,"remove"), iVar2 == 0)) {
            Cmd_Argv();
            if ((iVar1 == 4) &&
               ((pcVar3 = (char *)Cmd_Argv(), pcVar3 != (char *)0x0 && (*pcVar3 != '\0')))) {
              puStackY_d4 = (undefined4 *)0x8058734;
              __strtol_internal();
            }
            puStackY_d4 = (undefined4 *)0x8058752;
            sprintf(local_84,"%s:%i");
            puStackY_d4 = local_ac;
            iStackY_dc = 0x805875f;
            pcStackY_d8 = local_84;
            iVar1 = NET_StringToAdr();
            if (iVar1 == 0) {
              Con_Printf();
            }
            else {
              iVar1 = strcasecmp(__s1,"add");
              if (iVar1 == 0) {
                Master_AddServer();
                gfNoMasterServer = 0;
                Con_Printf();
              }
              else if (valvemaster_adr == (void *)0x0) {
                Con_Printf();
              }
              else {
                pvVar5 = valvemaster_adr;
                if (valvemaster_adr != (void *)0x0) {
                  do {
                    puVar6 = local_ac;
                    ppuVar7 = &puStackY_d4;
                    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                      *ppuVar7 = (undefined4 *)*puVar6;
                      puVar6 = puVar6 + 1;
                      ppuVar7 = ppuVar7 + 1;
                    }
                    puVar6 = (undefined4 *)((int)pvVar5 + 0x18);
                    ppcVar8 = apcStackY_e8;
                    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                      *ppcVar8 = (char *)*puVar6;
                      puVar6 = puVar6 + 1;
                      ppcVar8 = ppcVar8 + 1;
                    }
                    iVar1 = NET_CompareAdr();
                  } while ((iVar1 == 0) &&
                          (pvVar5 = *(void **)((int)pvVar5 + 0x2c), pvVar5 != (void *)0x0));
                  if (pvVar5 != (void *)0x0) {
                    if (pvVar5 == valvemaster_adr) {
                      valvemaster_adr = *(void **)((int)pvVar5 + 0x2c);
                    }
                    else {
                      pvVar4 = valvemaster_adr;
                      if (valvemaster_adr == (void *)0x0) {
                        return;
                      }
                      do {
                        if (*(void **)((int)pvVar4 + 0x2c) == pvVar5) break;
                        pvVar4 = *(void **)((int)pvVar4 + 0x2c);
                      } while (pvVar4 != (void *)0x0);
                      if (pvVar4 == (void *)0x0) {
                        return;
                      }
                      *(undefined4 *)((int)pvVar4 + 0x2c) = *(undefined4 *)((int)pvVar5 + 0x2c);
                    }
                    free(pvVar5);
                    return;
                  }
                }
                Con_Printf();
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
  else {
    Con_Printf();
    pvVar5 = valvemaster_adr;
    if (valvemaster_adr == (void *)0x0) {
      Con_Printf();
    }
    else {
      local_b4 = 1;
      Con_Printf();
      for (; pvVar5 != (void *)0x0; pvVar5 = *(void **)((int)pvVar5 + 0x2c)) {
        puVar6 = (undefined4 *)((int)pvVar5 + 0x18);
        ppuVar7 = &puStackY_d4;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *ppuVar7 = (undefined4 *)*puVar6;
          puVar6 = puVar6 + 1;
          ppuVar7 = ppuVar7 + 1;
        }
        pcStackY_d8 = (char *)0x8058625;
        pcStackY_d8 = (char *)NET_AdrToString();
        apcStackY_e8[2] = "  %i:  %s\n";
        apcStackY_e8[1] = (char *)0x805863e;
        iStackY_dc = local_b4;
        Con_Printf();
        local_b4 = local_b4 + 1;
      }
    }
  }
  return;
}


// Master_Shutdown  @ 08058390
void Master_Shutdown(int param_1)

{
  char cVar1;
  void *pvVar2;
  void *__ptr;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 auStack_82c [2];
  void *local_808;
  char local_804 [2048];
  
  if ((((gfNoMasterServer == 0) && (gfUseLANAuthentication == 0)) &&
      ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (1 < svs)) {
    Master_Init();
    auStack_82c[1] = 0x80583f3;
    sprintf(local_804,"%c\n");
    local_808 = valvemaster_adr;
    if (valvemaster_adr != (void *)0x0) {
      do {
        if (param_1 != 0) {
          puVar6 = (undefined4 *)((int)local_808 + 0x18);
          puVar7 = auStack_82c;
          for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          uVar3 = NET_AdrToString();
          Con_DPrintf("Sending shutdown to %s\n",uVar3);
        }
        puVar6 = (undefined4 *)((int)local_808 + 0x18);
        puVar7 = auStack_82c;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        uVar5 = 0xffffffff;
        pcVar8 = local_804;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        NET_SendPacket(1,~uVar5 - 1,local_804);
        local_808 = *(void **)((int)local_808 + 0x2c);
      } while (local_808 != (void *)0x0);
    }
    __ptr = valvemaster_adr;
    if (param_1 != 0) {
      while (__ptr != (void *)0x0) {
        pvVar2 = *(void **)((int)__ptr + 0x2c);
        free(__ptr);
        __ptr = pvVar2;
      }
      valvemaster_adr = (void *)0x0;
    }
  }
  return;
}


// Master_UseDefault  @ 080588d0
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


