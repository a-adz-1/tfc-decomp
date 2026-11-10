// NET_AddToLagged  @ 0808b210
void NET_AddToLagged(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined4 param_5,undefined4 param_6,void *param_7,undefined4 param_8,
                    size_t param_9)

{
  void *__dest;
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_3[9] == 0) && (param_3[8] == 0)) {
    param_3[9] = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 **)(*(int *)(param_2 + 0x24) + 0x20) = param_3;
    *(undefined4 **)(param_2 + 0x24) = param_3;
    param_3[8] = param_2;
    __dest = malloc(param_9);
    *param_3 = __dest;
    memcpy(__dest,param_7,param_9);
    param_3[7] = (float)realtime;
    puVar2 = param_3 + 2;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_4;
      param_4 = param_4 + 1;
      puVar2 = puVar2 + 1;
    }
    param_3[1] = param_9;
  }
  else {
    Con_Printf("Packet already linked\n");
  }
  return;
}


// NET_AdrToString  @ 0808ade0
undefined4 *
NET_AdrToString(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint16_t uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &s_110;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == 1) {
    sprintf((char *)&s_110,"loopback");
  }
  else if (param_1 == 3) {
    uVar1 = ntohs(param_5._2_2_);
    sprintf((char *)&s_110,"%i.%i.%i.%i:%i",param_2 & 0xff,param_2 >> 8 & 0xff,
            param_2 >> 0x10 & 0xff,param_2 >> 0x18,(uint)uVar1);
  }
  return &s_110;
}


// NET_BaseAdrToString  @ 0808ae60
undefined4 * NET_BaseAdrToString(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &s_113;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == 1) {
    sprintf((char *)&s_113,"loopback");
  }
  else if (param_1 == 3) {
    sprintf((char *)&s_113,"%i.%i.%i.%i",param_2 & 0xff,param_2 >> 8 & 0xff,param_2 >> 0x10 & 0xff,
            param_2 >> 0x18);
  }
  return &s_113;
}


// NET_ClearLaggedList  @ 0808b1b0
void NET_ClearLaggedList(int *param_1)

{
  int *piVar1;
  int *__ptr;
  
  __ptr = (int *)param_1[8];
  while ((__ptr != (int *)0x0 && (__ptr != param_1))) {
    piVar1 = (int *)__ptr[8];
    NET_RemoveFromPacketList(__ptr);
    if (*__ptr != 0) {
      free((void *)*__ptr);
      *__ptr = 0;
    }
    free(__ptr);
    __ptr = piVar1;
  }
  param_1[9] = (int)param_1;
  param_1[8] = (int)param_1;
  return;
}


// NET_CompareAdr  @ 0808ac60
undefined4
NET_CompareAdr(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  
  if ((param_1 == param_6) &&
     ((param_1 == 1 ||
      (((param_1 == 3 && (param_2 == param_7)) && (param_5._2_2_ == param_10._2_2_)))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_CompareBaseAdr  @ 0808ada0
undefined4 NET_CompareBaseAdr(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_stack_00000018;
  int in_stack_0000001c;
  
  if ((param_1 == in_stack_00000018) &&
     ((param_1 == 1 || ((param_1 == 3 && (param_2 == in_stack_0000001c)))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_CompareClassBAdr  @ 0808aca0
undefined4 NET_CompareClassBAdr(int param_1,short param_2)

{
  undefined4 uVar1;
  int in_stack_00000018;
  short in_stack_0000001c;
  
  if (param_1 != in_stack_00000018) goto LAB_0808acd6;
  if (param_1 == 1) {
LAB_0808ace0:
    uVar1 = 1;
  }
  else {
    if (param_1 == 3) {
      if (param_2 == in_stack_0000001c) goto LAB_0808ace0;
    }
    else if (param_1 == 4) goto LAB_0808ace0;
LAB_0808acd6:
    uVar1 = 0;
  }
  return uVar1;
}


// NET_CompareClassCAdr  @ 0808acf0
undefined4 NET_CompareClassCAdr(int param_1,int3 param_2)

{
  undefined4 uVar1;
  int in_stack_00000018;
  int3 in_stack_0000001c;
  
  if (param_1 != in_stack_00000018) goto LAB_0808ad26;
  if (param_1 == 1) {
LAB_0808ad30:
    uVar1 = 1;
  }
  else {
    if (param_1 == 3) {
      if (param_2 == in_stack_0000001c) goto LAB_0808ad30;
    }
    else if (param_1 == 4) goto LAB_0808ad30;
LAB_0808ad26:
    uVar1 = 0;
  }
  return uVar1;
}


// NET_Config  @ 0808bcd0
void NET_Config(int param_1)

{
  int iVar1;
  
  if (old_config_149 != param_1) {
    old_config_149 = param_1;
    if (param_1 == 0) {
      iVar1 = 0;
      do {
        if ((&ip_sockets)[iVar1] != 0) {
          close((&ip_sockets)[iVar1]);
          (&ip_sockets)[iVar1] = 0;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 2);
    }
    else {
      if (noip == 0) {
        NET_OpenIP();
      }
      if (bFirst_150 != 0) {
        bFirst_150 = 0;
        NET_GetLocalAddress();
        Master_Init();
      }
    }
  }
  return;
}


// NET_ErrorString  @ 0808c110
void NET_ErrorString(int param_1)

{
  strerror(param_1);
  return;
}


// NET_GetLocalAddress  @ 0808bd60
void NET_GetLocalAddress(void)

{
  int iVar1;
  char **ppcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcStack_230;
  socklen_t local_218;
  sockaddr local_214;
  char local_204 [511];
  undefined1 local_5;
  
  puVar3 = &net_local_adr;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if (noip == 0) {
    pcStack_230 = (char *)0x808bdb1;
    gethostname(local_204,0x200);
    local_5 = 0;
    pcStack_230 = (char *)&net_local_adr;
    NET_StringToAdr();
    local_218 = 0x10;
    iVar1 = getsockname(DAT_08178fd8,&local_214,&local_218);
    if (iVar1 == 0) {
      DAT_0817ada2._0_1_ = local_214.sa_data[0];
      DAT_0817ada2._1_1_ = local_214.sa_data[1];
      puVar3 = &net_local_adr;
      puVar4 = (undefined4 *)&stack0xfffffdc8;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      NET_AdrToString();
      ppcVar2 = (char **)&stack0xfffffdc0;
    }
    else {
      noip = 1;
      __errno_location();
      NET_ErrorString();
      ppcVar2 = &pcStack_230;
      pcStack_230 = "Could not get TCP/IP address, TCP/IP disabled\nReason:  %s\n";
    }
    *(undefined4 *)((int)ppcVar2 + -4) = 0x808be3f;
    Con_Printf();
  }
  else {
    Con_Printf();
  }
  return;
}


// NET_GetLong  @ 0808b490
undefined4 NET_GetLong(void *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = (uint)(*(byte *)((int)param_1 + 8) >> 4);
  uVar1 = *(byte *)((int)param_1 + 8) & 0xf;
  if ((gNetSplit == -1) || (*(int *)((int)param_1 + 4) != gNetSplit)) {
    gNetSplit = *(int *)((int)param_1 + 4);
    DAT_08178fe4 = uVar1;
  }
  if (uVar3 == uVar1 - 1) {
    DAT_08178fe8 = uVar3 * 0x56f + (param_2 - 9U);
  }
  DAT_08178fe4 = DAT_08178fe4 - 1;
  memcpy(&DAT_08178fec + uVar3 * 0x56f,(void *)((int)param_1 + 9),param_2 - 9U);
  if ((int)DAT_08178fe4 < 1) {
    if (0x1d4c < DAT_08178fe8) {
      Sys_Error("Split packet too large! %d bytes\n",DAT_08178fe8);
    }
    memcpy(param_1,&DAT_08178fec,DAT_08178fe8);
    *param_3 = DAT_08178fe8;
    gNetSplit = -1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// NET_GetLoopPacket  @ 0808b050
undefined4 NET_GetLoopPacket(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  param_1 = param_1 * 0x7578;
  if (4 < *(int *)(loopbacks + param_1 + 0x7574) - *(int *)(loopbacks + param_1 + 0x7570)) {
    *(int *)(loopbacks + param_1 + 0x7570) = *(int *)(loopbacks + param_1 + 0x7574) + -4;
  }
  uVar1 = *(uint *)(loopbacks + param_1 + 0x7570);
  if ((int)uVar1 < *(int *)(loopbacks + param_1 + 0x7574)) {
    *(int *)(loopbacks + param_1 + 0x7570) = *(int *)(loopbacks + param_1 + 0x7570) + 1;
    iVar3 = (uVar1 & 3) * 0x1d5c;
    memcpy(*(void **)(param_3 + 8),loopbacks + iVar3 + param_1,
           *(size_t *)(iVar3 + param_1 + 0x817cb18));
    *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar3 + param_1 + 0x817cb18);
    puVar4 = param_2;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *param_2 = 1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// NET_GetPacket  @ 0808b580
void NET_GetPacket(int param_1)

{
  int iVar1;
  ssize_t sVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  socklen_t local_18;
  sockaddr local_14;
  
  iVar1 = NET_GetLoopPacket();
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      if ((&ip_sockets)[param_1] != 0) {
        local_18 = 0x10;
        sVar2 = recvfrom((&ip_sockets)[param_1],(void *)net_message._8_4_,net_message._12_4_,0,
                         &local_14,&local_18);
        if (sVar2 == -1) {
          piVar3 = __errno_location();
          if ((*piVar3 != 0xb) && (*piVar3 != 0x6f)) {
            if (cls == 0) {
              NET_ErrorString();
              Con_Printf();
            }
            else {
              __errno_location();
              NET_ErrorString();
              Sys_Error();
            }
          }
        }
        else {
          SockadrToNetadr();
          if (sVar2 != net_message._12_4_) {
            net_message._16_4_ = sVar2;
            if (*(int *)net_message._8_4_ == -2) {
              NET_GetLong();
              return;
            }
            break;
          }
          puVar6 = &net_from;
          puVar7 = (undefined4 *)&stack0xffffffc8;
          for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          uVar4 = NET_AdrToString();
          Con_Printf("Oversize packet from %s\n",uVar4);
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
  }
  NET_LagPacket();
  return;
}


// NET_IPSocket  @ 0808b990
int NET_IPSocket(char *param_1,int param_2)

{
  int __fd;
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  sockaddr local_14;
  
  local_18 = 1;
  local_1c = 1;
  __fd = socket(2,2,0x11);
  if (__fd == -1) {
    piVar1 = __errno_location();
    uVar2 = NET_ErrorString(*piVar1);
    Con_Printf("WARNING: UDP_OpenSocket: socket: %s",uVar2);
  }
  else {
    iVar3 = ioctl(__fd,0x5421,&local_18);
    if (iVar3 == -1) {
      piVar1 = __errno_location();
      uVar2 = NET_ErrorString(*piVar1);
      Con_Printf("WARNING: UDP_OpenSocket: ioctl FIONBIO: %s\n",uVar2);
    }
    else {
      iVar3 = setsockopt(__fd,1,6,&local_1c,4);
      if (iVar3 == -1) {
        piVar1 = __errno_location();
        uVar2 = NET_ErrorString(*piVar1);
        Con_Printf("WARNING: UDP_OpenSocket: setsockopt SO_BROADCAST: %s\n",uVar2);
      }
      else {
        iVar3 = COM_CheckParm("-reuse");
        if ((iVar3 == 0) || (iVar3 = setsockopt(__fd,1,2,&local_18,4), iVar3 != -1)) {
          if ((param_1 == (char *)0x0) ||
             ((*param_1 == '\0' || (iVar3 = Q_strcasecmp(param_1,"localhost"), iVar3 == 0)))) {
            local_14.sa_data[2] = '\0';
            local_14.sa_data[3] = '\0';
            local_14.sa_data[4] = '\0';
            local_14.sa_data[5] = '\0';
          }
          else {
            NET_StringToSockaddr(param_1,&local_14);
          }
          if (param_2 == -1) {
            local_14.sa_data[0] = '\0';
            local_14.sa_data[1] = '\0';
          }
          else {
            local_14.sa_data._0_2_ = htons((uint16_t)param_2);
          }
          local_14.sa_family = 2;
          iVar3 = bind(__fd,&local_14,0x10);
          if (iVar3 != -1) {
            return __fd;
          }
          piVar1 = __errno_location();
          uVar2 = NET_ErrorString(*piVar1);
          Con_Printf("WARNING: UDP_OpenSocket: bind: %s\n",uVar2);
          close(__fd);
        }
        else {
          piVar1 = __errno_location();
          uVar2 = NET_ErrorString(*piVar1);
          Con_Printf("WARNING: UDP_OpenSocket: setsockopt SO_REUSEADDR: %s\n",uVar2);
        }
      }
    }
  }
  return 0;
}


// NET_Init  @ 0808bf70
void NET_Init(void)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  Cmd_AddCommand("maxplayers",MaxPlayers_f);
  Cmd_AddCommand("netbad",Net_BadConnection_f);
  Cmd_AddCommand("netmax",NET_ShowMaxPacketSizes_f);
  Cvar_RegisterVariable(ipname);
  Cvar_RegisterVariable(iphostport);
  Cvar_RegisterVariable(hostport);
  Cvar_RegisterVariable(defport);
  Cvar_RegisterVariable(ip_clientport);
  Cvar_RegisterVariable(clientport);
  Cvar_RegisterVariable(fakelag);
  Cvar_RegisterVariable(fakeloss);
  Cvar_RegisterVariable(hostname);
  iVar1 = COM_CheckParm("-noip");
  if (iVar1 != 0) {
    noip = 1;
  }
  iVar1 = COM_CheckParm("-port");
  if (iVar1 != 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(com_argv + 4 + iVar1 * 4),0,0);
    Cvar_SetValue("hostport",(float)lVar3);
  }
  net_message._12_4_ = 0x1d4c;
  net_message._8_4_ = net_message_buffer;
  iVar1 = 0;
  do {
    iVar2 = iVar1 * 0x28;
    *(undefined1 **)(g_pLagData + iVar2 + 0x24) = g_pLagData + iVar2;
    *(undefined1 **)(g_pLagData + iVar2 + 0x20) = g_pLagData + iVar2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  iVar1 = COM_CheckParm("-nomaster");
  if (iVar1 != 0) {
    Con_Printf("Master server communication disabled.\n");
    gfNoMasterServer = 1;
  }
  Con_Printf("Base networking initialized.\n");
  return;
}


// NET_IsLocalAddress  @ 0808b030
bool NET_IsLocalAddress(int param_1)

{
  return param_1 == 1;
}


// NET_IsReservedAdr  @ 0808ad40
undefined4 NET_IsReservedAdr(int param_1,undefined4 param_2)

{
  if (param_1 != 1) {
    if (param_1 == 3) {
      if (((((char)param_2 != '\n') && ((char)param_2 != '\x7f')) &&
          (((char)param_2 != -0x54 || ((param_2._1_1_ < 0x10 || (0x1f < param_2._1_1_)))))) &&
         (((char)param_2 != -0x40 || (param_2._1_1_ < 0xa8)))) {
        return 0;
      }
    }
    else if (param_1 != 4) {
      return 0;
    }
  }
  return 1;
}


// NET_LagPacket  @ 0808b2a0
int NET_LagPacket(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 auStack_38 [3];
  
  uVar1 = fakeloss._12_4_;
  if ((float)fakelag._12_4_ <= 0.0) {
    return param_1;
  }
  if (param_1 != 0) {
    if ((byte)(0.0 < (float)fakeloss._12_4_ |
               (byte)((ushort)((ushort)NAN((float)fakeloss._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)fakeloss._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      piVar4 = (int *)((int)&losscount_132 + param_2 * 4);
      *piVar4 = *piVar4 + 1;
      if ((byte)(0.0 < (float)uVar1 | (byte)((ushort)((ushort)NAN((float)uVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)uVar1 == 0.0) << 0xe) >> 8)) == 1) {
        iVar2 = RandomLong();
        if (iVar2 <= (int)ROUND((float)fakeloss._12_4_)) {
          return 0;
        }
      }
      else {
        iVar2 = 2;
        if (1 < (int)ROUND(ABS((float)fakeloss._12_4_))) {
          iVar2 = (int)ROUND(ABS((float)fakeloss._12_4_));
        }
        if (*(int *)((int)&losscount_132 + param_2 * 4) % iVar2 == 0) {
          return 0;
        }
      }
    }
    puVar3 = malloc(0x28);
    puVar6 = puVar3;
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = auStack_38;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *param_4;
      param_4 = param_4 + 1;
      puVar6 = puVar6 + 1;
    }
    NET_AddToLagged(param_2,g_pLagData + param_2 * 0x28,puVar3,param_3);
  }
  piVar4 = *(int **)(g_pLagData + param_2 * 0x28 + 0x20);
  if (piVar4 != (int *)(g_pLagData + param_2 * 0x28)) {
    do {
      if ((float)piVar4[7] <= (float)realtime - (float)fakelag._12_4_ / 1000.0) {
        NET_RemoveFromPacketList();
        net_message._16_4_ = piVar4[1];
        if (*piVar4 != 0) {
          auStack_38[2] = 0x808b43d;
          memcpy((void *)net_message._8_4_,(void *)*piVar4,piVar4[1]);
        }
        piVar5 = piVar4 + 2;
        piVar7 = &net_from;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar7 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar7 = piVar7 + 1;
        }
        if (*piVar4 != 0) {
          free((void *)*piVar4);
        }
        free(piVar4);
        return 1;
      }
      piVar4 = (int *)piVar4[8];
    } while (piVar4 != (int *)(g_pLagData + param_2 * 0x28));
  }
  return 0;
}


// NET_OpenIP  @ 0808bb60
void NET_OpenIP(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  bVar3 = cls == 0;
  if (DAT_08178fd8 == 0) {
    iVar2 = (int)ROUND((float)iphostport._12_4_);
    if (iVar2 == 0) {
      iVar2 = (int)ROUND((float)hostport._12_4_);
      if (iVar2 == 0) {
        iVar2 = (int)ROUND((float)defport._12_4_);
      }
    }
    DAT_08178fd8 = NET_IPSocket(ipname._4_4_,iVar2);
    if ((DAT_08178fd8 == 0) && (bVar3)) {
      Sys_Error("Couldn\'t allocate dedicated server IP port");
    }
  }
  if (cls != 0) {
    if (ip_sockets == 0) {
      iVar1 = (int)ROUND((float)ip_clientport._12_4_);
      if (iVar1 == 0) {
        iVar1 = (int)ROUND((float)clientport._12_4_);
        if (iVar1 == 0) {
          iVar1 = -1;
        }
      }
      ip_sockets = NET_IPSocket(ipname._4_4_,iVar1);
      if (ip_sockets == 0) {
        ip_sockets = NET_IPSocket(ipname._4_4_,0xffffffff);
      }
    }
    if (bFirst_146 != 0) {
      bFirst_146 = 0;
      Con_Printf("NET Ports:  server %i, client %i\n",iVar2,iVar1);
    }
  }
  return;
}


// NET_RemoveFromPacketList  @ 0808b180
void NET_RemoveFromPacketList(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// NET_SendLong  @ 0808b710
undefined8
NET_SendLong(int param_1,void *param_2,uint param_3,int param_4,sockaddr *param_5,socklen_t param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint __n;
  char local_584;
  uint local_580;
  undefined4 local_57c;
  int local_578;
  char local_574;
  undefined1 local_573 [1391];
  
  if ((int)param_3 < 0x579) {
    uVar2 = sendto(param_1,param_2,param_3,param_4,param_5,param_6);
    uVar1 = uVar2;
  }
  else {
    gSequenceNumber_139 = gSequenceNumber_139 + 1;
    if (gSequenceNumber_139 < 0) {
      gSequenceNumber_139 = 1;
    }
    local_57c = 0xfffffffe;
    local_578 = gSequenceNumber_139;
    iVar4 = 0;
    local_580 = 0;
    uVar3 = (param_3 + 0x56e) / 0x56f;
    uVar2 = local_580;
    uVar1 = uVar3;
    if (0 < (int)param_3) {
      do {
        __n = param_3;
        if (0x56f < param_3) {
          __n = 0x56f;
        }
        local_584 = (char)uVar3;
        local_574 = (char)iVar4 * '\x10' + local_584;
        memcpy(local_573,(void *)(iVar4 * 0x56f + (int)param_2),__n);
        uVar1 = sendto(param_1,&local_57c,__n + 9,param_4,param_5,param_6);
        uVar2 = uVar1;
        if ((int)uVar1 < 0) break;
        if ((int)__n <= (int)uVar1) {
          local_580 = local_580 + __n;
        }
        param_3 = param_3 - __n;
        iVar4 = iVar4 + 1;
        uVar2 = local_580;
      } while (0 < (int)param_3);
    }
  }
  return CONCAT44(uVar1,uVar2);
}


// NET_SendLoopPacket  @ 0808b110
void NET_SendLoopPacket(uint param_1,size_t param_2,void *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (param_1 ^ 1) * 0x7578;
  uVar1 = *(uint *)(loopbacks + iVar2 + 0x7574);
  *(int *)(loopbacks + iVar2 + 0x7574) = *(int *)(loopbacks + iVar2 + 0x7574) + 1;
  iVar3 = (uVar1 & 3) * 0x1d5c;
  memcpy(loopbacks + iVar3 + iVar2,param_3,param_2);
  *(size_t *)(loopbacks + iVar3 + 0x1d58 + iVar2) = param_2;
  return;
}


// NET_SendPacket  @ 0808b870
void NET_SendPacket(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  char **ppcVar4;
  char *apcStack_34 [5];
  undefined1 local_14 [16];
  
  if (net_maxpacket < param_2) {
    net_maxpacket = param_2;
  }
  if ((cls == 5) && (net_maxingame < param_2)) {
    net_maxingame = param_2;
  }
  if (param_4 == 1) {
    puVar3 = &param_4;
    ppcVar4 = apcStack_34;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar4 = (char *)*puVar3;
      puVar3 = puVar3 + 1;
      ppcVar4 = ppcVar4 + 1;
    }
    NET_SendLoopPacket(param_1,param_2,param_3);
  }
  else {
    if ((param_4 == 2) || (param_4 == 3)) {
      unaff_ESI = (&ip_sockets)[param_1];
      if (unaff_ESI == 0) {
        return;
      }
    }
    else {
      apcStack_34[4] = "NET_SendPacket: bad address type";
      apcStack_34[3] = (char *)0x808b8fa;
      Sys_Error();
    }
    apcStack_34[3] = (char *)&param_4;
    apcStack_34[2] = "j\x10Sj";
    apcStack_34[4] = local_14;
    NetadrToSockadr();
    apcStack_34[2] = (char *)0x10;
    apcStack_34[0] = (char *)0x0;
    apcStack_34[1] = local_14;
    iVar2 = NET_SendLong(unaff_ESI,param_3,param_2);
    if (iVar2 == -1) {
      apcStack_34[4] = (char *)0x808b92a;
      piVar1 = __errno_location();
      if ((*piVar1 != 0xb) && (*piVar1 != 0x6f)) {
        if (cls == 0) {
          apcStack_34[4] = (char *)*piVar1;
          apcStack_34[3] = (char *)0x808b945;
          apcStack_34[3] = (char *)NET_ErrorString();
          apcStack_34[2] = "NET_SendPacket ERROR: %s\n";
          apcStack_34[1] = (char *)0x808b950;
          Con_Printf();
        }
        else {
          apcStack_34[4] = (char *)0x808b965;
          piVar1 = __errno_location();
          apcStack_34[4] = (char *)*piVar1;
          apcStack_34[3] = (char *)0x808b96d;
          apcStack_34[3] = (char *)NET_ErrorString();
          apcStack_34[2] = "NET_SendPacket ERROR: %s\n";
          apcStack_34[1] = (char *)0x808b978;
          Sys_Error();
        }
      }
    }
  }
  return;
}


// NET_ShowMaxPacketSizes_f  @ 0808bf00
void NET_ShowMaxPacketSizes_f(void)

{
  Con_Printf("Max Packet     :  %i\n",net_maxpacket);
  Con_Printf("Max Game Packet:  %i\n",net_maxingame);
  return;
}


// NET_Shutdown  @ 0808c0e0
void NET_Shutdown(void)

{
  NET_ClearLaggedList(g_pLagData);
  NET_ClearLaggedList(0x817ad68);
  NET_Config(0);
  return;
}


// NET_StringToAdr  @ 0808afb0
undefined4 NET_StringToAdr(byte *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  bool bVar7;
  bool bVar8;
  undefined1 local_14 [16];
  
  iVar3 = 10;
  bVar7 = false;
  uVar1 = 0;
  bVar8 = true;
  pbVar4 = param_1;
  pbVar5 = (byte *)"localhost";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pbVar4 < *pbVar5;
    bVar8 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar8);
  if (!bVar8) {
    uVar1 = -(uint)bVar7 | 1;
  }
  if (uVar1 == 0) {
    puVar6 = param_2;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    *param_2 = 1;
    uVar2 = 1;
  }
  else {
    iVar3 = NET_StringToSockaddr(param_1,local_14);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      SockadrToNetadr(local_14,param_2);
      uVar2 = 1;
    }
  }
  return uVar2;
}


// NET_StringToSockaddr  @ 0808aed0
undefined4 NET_StringToSockaddr(char *param_1,undefined4 *param_2)

{
  char cVar1;
  uint16_t uVar2;
  in_addr_t iVar3;
  hostent *phVar4;
  char *__dest;
  char local_84 [128];
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  *(undefined2 *)param_2 = 2;
  *(undefined2 *)((int)param_2 + 2) = 0;
  __dest = local_84;
  strcpy(__dest,param_1);
  cVar1 = local_84[0];
  while (cVar1 != '\0') {
    if (*__dest == ':') {
      *__dest = '\0';
      uVar2 = __strtol_internal(__dest + 1,0,10,0);
      uVar2 = htons(uVar2);
      *(uint16_t *)((int)param_2 + 2) = uVar2;
    }
    __dest = __dest + 1;
    cVar1 = *__dest;
  }
  if ((byte)(local_84[0] - 0x30U) < 10) {
    iVar3 = inet_addr(local_84);
  }
  else {
    phVar4 = gethostbyname(local_84);
    if (phVar4 == (hostent *)0x0) {
      return 0;
    }
    iVar3 = *(in_addr_t *)*phVar4->h_addr_list;
  }
  param_2[1] = iVar3;
  return 1;
}


// NET_StringToSockaddrX__FPcP8sockaddr  @ 08089710
undefined4 NET_StringToSockaddrX__FPcP8sockaddr(char *param_1,undefined2 *param_2)

{
  char cVar1;
  uint16_t uVar2;
  in_addr_t iVar3;
  hostent *phVar4;
  char *__dest;
  char local_84 [128];
  
  memset(param_2,0,0x10);
  *param_2 = 2;
  param_2[1] = 0;
  __dest = local_84;
  strcpy(__dest,param_1);
  cVar1 = local_84[0];
  while (cVar1 != '\0') {
    if (*__dest == ':') {
      *__dest = '\0';
      uVar2 = __strtol_internal(__dest + 1,0,10,0);
      uVar2 = htons(uVar2);
      param_2[1] = uVar2;
    }
    __dest = __dest + 1;
    cVar1 = *__dest;
  }
  if ((byte)(local_84[0] - 0x30U) < 10) {
    iVar3 = inet_addr(local_84);
  }
  else {
    phVar4 = gethostbyname(local_84);
    if (phVar4 == (hostent *)0x0) {
      return 0;
    }
    iVar3 = *(in_addr_t *)*phVar4->h_addr_list;
  }
  *(in_addr_t *)(param_2 + 2) = iVar3;
  return 1;
}


