// NET_AddToLagged  @ 0008f48c
void NET_AddToLagged(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                    undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_3[9] == 0) && (param_3[8] == 0)) {
    param_3[9] = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 **)(*(int *)(param_2 + 0x24) + 0x20) = param_3;
    *(undefined4 **)(param_2 + 0x24) = param_3;
    param_3[8] = param_2;
    uVar1 = Mem_Malloc(param_8);
    *param_3 = uVar1;
    Q_memcpy(uVar1,param_6,param_8);
    param_3[1] = param_8;
    param_3[7] = param_9;
    puVar3 = param_3 + 2;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_4;
      param_4 = param_4 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    Con_Printf("Packet already linked\n");
  }
  return;
}


// NET_AdjustLag  @ 0008f514
void NET_AdjustLag(void)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar2 = (longdouble)realtime - (longdouble)lasttime_142;
  lVar1 = (longdouble)0;
  if (0x3f < (byte)((lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) - 1)) {
    lVar2 = lVar1;
  }
  if ((longdouble)0.1 < lVar2) {
    lVar2 = (longdouble)0.1;
  }
  lVar3 = (longdouble)gFakeLag;
  lasttime_142 = realtime;
  lVar4 = (longdouble)(float)fakelag._12_4_;
  if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) {
    lVar4 = lVar4 - lVar3;
    lVar2 = (longdouble)(float)((longdouble)200.0 * lVar2);
    if (ABS(lVar4) < lVar2) {
      lVar2 = (longdouble)(float)ABS(lVar4);
    }
    if (lVar4 < lVar1) {
      lVar2 = -lVar2;
    }
    gFakeLag = (int)ROUND(lVar2 + lVar3);
  }
  return;
}


// NET_AdrToString  @ 0008efe4
undefined1 *
NET_AdrToString(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint16_t uVar1;
  
  Q_memset(s_114,0,0x40);
  if (param_1 == 1) {
    sprintf(s_114,"loopback");
  }
  else if (param_1 == 3) {
    uVar1 = ntohs(param_5._2_2_);
    sprintf(s_114,"%i.%i.%i.%i:%i",param_2 & 0xff,param_2 >> 8 & 0xff,param_2 >> 0x10 & 0xff,
            param_2 >> 0x18,(uint)uVar1);
  }
  return s_114;
}


// NET_AllocMsg  @ 0008fcf0
undefined4 * NET_AllocMsg(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = normalqueue;
  if ((param_1 < 0x601) && (normalqueue != (undefined4 *)0x0)) {
    piVar1 = normalqueue + 8;
    normalqueue = (undefined4 *)*normalqueue;
    *piVar1 = param_1;
    return puVar2;
  }
  puVar2 = (undefined4 *)net_malloc(0x24);
  uVar3 = net_malloc(param_1);
  puVar2[2] = uVar3;
  puVar2[8] = param_1;
  puVar2[1] = 0;
  return puVar2;
}


// NET_AllocateQueues  @ 0008ff00
void NET_AllocateQueues(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    puVar1 = (undefined4 *)Mem_ZeroMalloc(0x24);
    uVar2 = Mem_ZeroMalloc(0x600);
    puVar1[2] = uVar2;
    puVar1[1] = 1;
    *puVar1 = normalqueue;
    normalqueue = puVar1;
    puVar1 = (undefined4 *)Mem_ZeroMalloc(0x24);
    uVar2 = Mem_ZeroMalloc(0x600);
    puVar1[2] = uVar2;
    puVar1[1] = 1;
    *puVar1 = normalqueue;
    normalqueue = puVar1;
    puVar1 = (undefined4 *)Mem_ZeroMalloc(0x24);
    uVar2 = Mem_ZeroMalloc(0x600);
    puVar1[2] = uVar2;
    puVar1[1] = 1;
    *puVar1 = normalqueue;
    normalqueue = puVar1;
    puVar1 = (undefined4 *)Mem_ZeroMalloc(0x24);
    uVar2 = Mem_ZeroMalloc(0x600);
    puVar1[2] = uVar2;
    puVar1[1] = 1;
    *puVar1 = normalqueue;
    normalqueue = puVar1;
    puVar1 = (undefined4 *)Mem_ZeroMalloc(0x24);
    uVar2 = Mem_ZeroMalloc(0x600);
    puVar1[2] = uVar2;
    puVar1[1] = 1;
    *puVar1 = normalqueue;
    iVar3 = iVar3 + 5;
    normalqueue = puVar1;
  } while (iVar3 < 0x28);
  NET_StartThread();
  return;
}


// NET_BaseAdrToString  @ 0008f06c
undefined1 * NET_BaseAdrToString(int param_1,uint param_2)

{
  Q_memset(s_117,0,0x40);
  if (param_1 == 1) {
    sprintf(s_117,"loopback");
  }
  else if (param_1 == 3) {
    sprintf(s_117,"%i.%i.%i.%i",param_2 & 0xff,param_2 >> 8 & 0xff,param_2 >> 0x10 & 0xff,
            param_2 >> 0x18);
  }
  return s_117;
}


// NET_ClearLagData  @ 00090bec
void NET_ClearLagData(int param_1,int param_2)

{
  NET_ThreadLock();
  if (param_1 != 0) {
    NET_ClearLaggedList(g_pLagData);
  }
  if (param_2 != 0) {
    NET_ClearLaggedList(0xe44c8);
  }
  NET_ThreadUnlock();
  return;
}


// NET_ClearLaggedList  @ 0008f428
void NET_ClearLaggedList(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[8];
  while ((piVar2 != (int *)0x0 && (piVar2 != param_1))) {
    piVar1 = (int *)piVar2[8];
    NET_RemoveFromPacketList(piVar2);
    if (*piVar2 != 0) {
      Mem_Free(*piVar2);
      *piVar2 = 0;
    }
    Mem_Free(piVar2);
    piVar2 = piVar1;
  }
  param_1[9] = (int)param_1;
  param_1[8] = (int)param_1;
  return;
}


// NET_CompareAdr  @ 0008ef08
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


// NET_CompareBaseAdr  @ 0008efb8
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


// NET_CompareClassBAdr  @ 0008ef40
undefined4 NET_CompareClassBAdr(int param_1,short param_2)

{
  undefined4 uVar1;
  int in_stack_00000018;
  short in_stack_0000001c;
  
  if ((param_1 == in_stack_00000018) &&
     ((param_1 == 1 || ((param_1 == 3 && (param_2 == in_stack_0000001c)))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_Config  @ 000908a4
void NET_Config(int param_1)

{
  if (old_config_184 != param_1) {
    old_config_184 = param_1;
    if (param_1 == 0) {
      NET_ThreadLock();
      if (ip_sockets != 0) {
        close(ip_sockets);
        ip_sockets = 0;
      }
      if (DAT_000b3878 != 0) {
        close(DAT_000b3878);
        DAT_000b3878 = 0;
      }
      NET_ThreadUnlock();
    }
    else {
      if (noip == 0) {
        NET_OpenIP();
      }
      if (bFirst_185 != 0) {
        bFirst_185 = 0;
        NET_GetLocalAddress();
      }
    }
    net_configured = (uint)(param_1 != 0);
  }
  return;
}


// NET_CountLaggedList  @ 0008f408
int NET_CountLaggedList(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0x20); (iVar1 != 0 && (iVar1 != param_1));
      iVar1 = *(int *)(iVar1 + 0x20)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// NET_ErrorString  @ 0008f258
void NET_ErrorString(int param_1)

{
  strerror(param_1);
  return;
}


// NET_FlushQueues  @ 0009002c
void NET_FlushQueues(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  NET_StopThread();
  puVar2 = messages;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2[2]);
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  messages = (undefined4 *)0x0;
  puVar2 = DAT_000b3894;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2[2]);
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  DAT_000b3894 = (undefined4 *)0x0;
  puVar2 = normalqueue;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2[2]);
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  normalqueue = (undefined4 *)0x0;
  return;
}


// NET_FreeMsg  @ 0008fd50
void NET_FreeMsg(undefined4 *param_1)

{
  if (param_1[1] == 0) {
    Mem_Free(param_1[2]);
    Mem_Free(param_1);
  }
  else {
    *param_1 = normalqueue;
    normalqueue = param_1;
  }
  return;
}


// NET_GetLocalAddress  @ 0009071c
void NET_GetLocalAddress(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_254 [4];
  undefined4 uStack_244;
  char *pcStack_240;
  undefined4 uStack_23c;
  socklen_t local_218;
  sockaddr local_214;
  char local_204 [511];
  undefined1 local_5;
  
  Q_memset();
  if (noip == 0) {
    iVar1 = Q_strcmp();
    if (iVar1 == 0) {
      gethostname(local_204,0x200);
    }
    else {
      Q_strcpy();
    }
    local_5 = 0;
    NET_StringToAdr();
    local_218 = 0x10;
    uStack_23c = 0x907e0;
    iVar1 = getsockname(DAT_000b3878,&local_214,&local_218);
    if (iVar1 == 0) {
      DAT_00216fca._0_1_ = local_214.sa_data[0];
      DAT_00216fca._1_1_ = local_214.sa_data[1];
      puVar3 = &net_local_adr;
      puVar4 = (undefined4 *)&stack0xfffffdc8;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      uStack_23c = 0x90835;
      uStack_23c = NET_AdrToString();
      pcStack_240 = "Server IP address %s\n";
      uStack_244 = 0x90842;
      Con_Printf();
      puVar3 = &net_local_adr;
      puVar4 = auStack_254;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      uVar2 = NET_AdrToString();
      uVar2 = va(&DAT_000ae411,uVar2);
      Cvar_Set("net_address",uVar2);
    }
    else {
      __errno_location();
      noip = 1;
      NET_ErrorString();
      Con_Printf();
    }
  }
  else {
    Con_Printf();
  }
  return;
}


// NET_GetLong  @ 0008f7f8
undefined4 NET_GetLong(void *param_1,int param_2,uint *param_3)

{
  size_t __n;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)((int)param_1 + 4);
  uVar4 = *(byte *)((int)param_1 + 8) & 0xf;
  uVar3 = (uint)(*(byte *)((int)param_1 + 8) >> 4);
  if ((gNetSplit == -1) || (iVar1 != gNetSplit)) {
    gNetSplit = iVar1;
    DAT_00216004 = uVar4;
  }
  __n = param_2 - 9;
  if (uVar3 == uVar4 - 1) {
    DAT_00216008 = uVar3 * 0x56f + __n;
  }
  if (*(int *)(gNetSplitFlags + uVar3 * 4) == iVar1) {
    Con_Printf("NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes )\n",uVar3 + 1,
               uVar4,__n);
  }
  else {
    DAT_00216004 = DAT_00216004 - 1;
    *(int *)(gNetSplitFlags + uVar3 * 4) = iVar1;
    if ((byte)((float)net_showpackets._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
    {
      Con_Printf("<-- Split packet %i of %i\n",uVar3,uVar4);
    }
  }
  memcpy(&DAT_0021600c + uVar3 * 0x56f,(void *)((int)param_1 + 9),__n);
  if ((int)DAT_00216004 < 1) {
    if (0xfaa < DAT_00216008) {
      Sys_Error("Split packet too large! %d bytes\n",DAT_00216008);
    }
    memcpy(param_1,&DAT_0021600c,DAT_00216008);
    *param_3 = DAT_00216008;
    uVar2 = 1;
    gNetSplit = -1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// NET_GetLoopPacket  @ 0008f2ac
bool NET_GetLoopPacket(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  param_1 = param_1 * 0x3f38;
  iVar1 = *(int *)(loopbacks + param_1 + 0x3f34);
  uVar3 = *(uint *)(loopbacks + param_1 + 0x3f30);
  if (4 < (int)(iVar1 - uVar3)) {
    uVar3 = iVar1 - 4;
    *(uint *)(loopbacks + param_1 + 0x3f30) = uVar3;
  }
  if ((int)uVar3 < iVar1) {
    iVar2 = (uVar3 & 3) * 0xfcc;
    *(uint *)(loopbacks + param_1 + 0x3f30) = uVar3 + 1;
    NET_TransferRawData(param_3,loopbacks + iVar2 + param_1,
                        *(undefined4 *)(loopbacks + iVar2 + 0xfc8 + param_1));
    Q_memset(param_2,0,0x14);
    *param_2 = 1;
  }
  return (int)uVar3 < iVar1;
}


// NET_GetPacket  @ 0008fd98
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int NET_GetPacket(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int local_8;
  
  local_8 = 0;
  NET_AdjustLag();
  NET_ThreadLock();
  iVar1 = NET_GetLoopPacket(param_1,&in_from,&in_message);
  if (iVar1 == 0) {
    if (use_thread == 0) {
      local_8 = NET_QueuePacket(param_1);
    }
    if (local_8 == 0) {
      puVar6 = (undefined2 *)0x0;
      puVar5 = (undefined4 *)0x0;
      uVar4 = 0;
      goto LAB_0008fe1e;
    }
  }
  else {
    puVar6 = &in_message;
    puVar5 = &in_from;
    uVar4 = 1;
LAB_0008fe1e:
    local_8 = NET_LagPacket(uVar4,param_1,puVar5,puVar6);
    if (local_8 == 0) {
      puVar5 = (undefined4 *)(&messages)[param_1];
      if (puVar5 != (undefined4 *)0x0) {
        (&messages)[param_1] = *puVar5;
        DAT_00226fec = puVar5[8];
        Q_memcpy(DAT_00226fe4,puVar5[2],puVar5[8]);
        puVar2 = puVar5 + 3;
        puVar3 = &net_from;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        msg_readcount = 0;
        NET_FreeMsg(puVar5);
        local_8 = 1;
      }
      goto LAB_0008feeb;
    }
  }
  Q_memcpy(DAT_00226fe4,DAT_00226ff4,_DAT_00226ffc);
  DAT_00226fec = _DAT_00226ffc;
  puVar5 = &in_from;
  puVar2 = &net_from;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
LAB_0008feeb:
  NET_ThreadUnlock();
  return local_8;
}


// NET_HostToNetShort  @ 0008eee0
uint16_t NET_HostToNetShort(uint16_t param_1)

{
  uint16_t uVar1;
  
  uVar1 = htons(param_1);
  return uVar1;
}


// NET_IPSocket  @ 000903a4
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
    if (*piVar1 != 0x61) {
      uVar2 = NET_ErrorString(*piVar1);
      Con_Printf("WARNING: UDP_OpenSocket: socket: %s",uVar2);
    }
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
             ((*param_1 == '\0' || (iVar3 = Q_stricmp(param_1,"localhost"), iVar3 == 0)))) {
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


// NET_Init  @ 00090a24
void NET_Init(void)

{
  int iVar1;
  longdouble lVar2;
  
  Cmd_AddCommand("maxplayers",MaxPlayers_f);
  Cvar_RegisterVariable(net_address);
  Cvar_RegisterVariable(ipname);
  Cvar_RegisterVariable(iphostport);
  Cvar_RegisterVariable(hostport);
  Cvar_RegisterVariable(defport);
  Cvar_RegisterVariable(ip_clientport);
  Cvar_RegisterVariable(clientport);
  Cvar_RegisterVariable(fakelag);
  Cvar_RegisterVariable(fakeloss);
  Cvar_RegisterVariable(net_graph);
  Cvar_RegisterVariable(net_graphwidth);
  Cvar_RegisterVariable(net_scale);
  Cvar_RegisterVariable(net_graphpos);
  Cvar_RegisterVariable(net_graphsolid);
  iVar1 = COM_CheckParm("-netsleep");
  if (iVar1 != 0) {
    net_sleepforever = 0;
  }
  iVar1 = COM_CheckParm("-noip");
  if (iVar1 != 0) {
    noip = 1;
  }
  iVar1 = COM_CheckParm("-port");
  if (iVar1 != 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(com_argv + 4 + iVar1 * 4),0,0);
    Cvar_SetValue("hostport",(float)lVar2);
  }
  DAT_00226fe8 = 0x10000;
  DAT_00226fe4 = net_message_buffer;
  net_message = 0;
  DAT_00226ff8 = 0x10000;
  DAT_00226ff4 = in_message_buf;
  in_message = 0;
  g_pLagData._36_4_ = g_pLagData;
  g_pLagData._32_4_ = g_pLagData;
  g_pLagData._76_4_ = 0xe44c8;
  g_pLagData._72_4_ = 0xe44c8;
  NET_AllocateQueues();
  Con_DPrintf("Base networking initialized.\n");
  return;
}


// NET_IsConfigured  @ 00090884
undefined4 NET_IsConfigured(void)

{
  return net_configured;
}


// NET_IsLocalAddress  @ 0008f244
bool NET_IsLocalAddress(int param_1)

{
  return param_1 == 1;
}


// NET_IsReservedAdr  @ 0008ef70
undefined4 NET_IsReservedAdr(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 1) ||
     ((param_1 == 3 &&
      (((((char)param_2 == '\n' || ((char)param_2 == '\x7f')) ||
        (((char)param_2 == -0x54 && ((0xf < param_2._1_1_ && (param_2._1_1_ < 0x20)))))) ||
       (((char)param_2 == -0x40 && (0xa7 < param_2._1_1_)))))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_LagPacket  @ 0008f5e8
int NET_LagPacket(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  float fVar1;
  undefined4 *puVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_24;
  
  lVar4 = (longdouble)0;
  lVar3 = (longdouble)gFakeLag;
  if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 1) {
    NET_ClearLagData(1,1);
    return param_1;
  }
  fVar5 = (float)realtime;
  if (param_1 != 0) {
    if ((byte)((float)fakeloss._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)fakeloss._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)fakeloss._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      iVar7 = *(int *)((int)&losscount_145 + param_2 * 4);
      *(int *)((int)&losscount_145 + param_2 * 4) = iVar7 + 1;
      if ((byte)(((float)fakeloss._12_4_ < 0.0 |
                  (byte)((ushort)((ushort)NAN((float)fakeloss._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)fakeloss._12_4_ == 0.0) << 0xe) >> 8)) - 1) < 0x40)
      {
        local_24 = 2;
        if (1 < (int)ROUND(ABS((float)fakeloss._12_4_))) {
          local_24 = (int)ROUND(ABS((float)fakeloss._12_4_));
        }
        if ((iVar7 + 1) % local_24 == 0) {
          return 0;
        }
      }
      else {
        iVar7 = RandomLong(0,100);
        if (iVar7 <= (int)ROUND((float)fakeloss._12_4_)) {
          return 0;
        }
      }
    }
    uVar8 = Mem_ZeroMalloc(0x28);
    NET_AddToLagged(param_2,g_pLagData + param_2 * 0x28,uVar8,param_3,*param_4,param_4[1],param_4[2]
                    ,param_4[3],fVar5);
  }
  puVar2 = *(undefined4 **)(g_pLagData + param_2 * 0x28 + 0x20);
  while( true ) {
    if (puVar2 == (undefined4 *)(g_pLagData + param_2 * 0x28)) {
      return 0;
    }
    fVar6 = fVar5 - (float)gFakeLag * 0.001;
    fVar1 = (float)puVar2[7];
    if ((byte)(fVar6 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar6) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar6 == fVar1) << 0xe) >> 8)) != 1) break;
    puVar2 = (undefined4 *)puVar2[8];
  }
  NET_RemoveFromPacketList(puVar2);
  NET_TransferRawData(&in_message,*puVar2,puVar2[1]);
  puVar9 = puVar2 + 2;
  puVar10 = &in_from;
  for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  if ((void *)*puVar2 != (void *)0x0) {
    free((void *)*puVar2);
  }
  Mem_Free(puVar2);
  return 1;
}


// NET_OpenIP  @ 00090568
void NET_OpenIP(void)

{
  int iVar1;
  bool bVar2;
  int local_18;
  
  local_18 = 0;
  bVar2 = cls == 0;
  NET_ThreadLock();
  iVar1 = 0;
  if (DAT_000b3878 == 0) {
    local_18 = (int)ROUND((float)iphostport._12_4_);
    if (local_18 == 0) {
      local_18 = (int)ROUND((float)hostport._12_4_);
      if (local_18 == 0) {
        local_18 = (int)ROUND((float)defport._12_4_);
      }
    }
    DAT_000b3878 = NET_IPSocket(ipname._4_4_,local_18);
    if ((DAT_000b3878 == 0) && (bVar2)) {
      Sys_Error("Couldn\'t allocate dedicated server IP port");
    }
  }
  NET_ThreadUnlock();
  if (cls != 0) {
    NET_ThreadLock();
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
    NET_ThreadUnlock();
    if (bFirst_177 != 0) {
      bFirst_177 = 0;
      Con_Printf("NET Ports:  server %i, client %i\n",local_18,iVar1);
    }
  }
  return;
}


// NET_QueuePacket  @ 0008f978
void NET_QueuePacket(int param_1)

{
  ssize_t sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_fcc;
  int local_fc8;
  socklen_t local_fc4;
  undefined1 local_fc0 [4012];
  sockaddr local_14;
  
  local_fc8 = 0;
  local_fcc = 0;
  do {
    if (local_fcc == 0) {
      local_fc8 = (&ip_sockets)[param_1];
    }
    if (local_fc8 != 0) {
      local_fc4 = 0x10;
      sVar1 = recvfrom(local_fc8,local_fc0,0xfaa,0,&local_14,&local_fc4);
      if (sVar1 == -1) {
        piVar2 = __errno_location();
        iVar4 = *piVar2;
        if (((iVar4 != 0xb) && (iVar4 != 0x68)) && (iVar4 != 0x6f)) {
          if (iVar4 == 0x5a) {
            Con_DPrintf();
          }
          else if (cls == 0) {
            NET_ErrorString();
            Con_Printf();
          }
          else {
            NET_ErrorString();
            Sys_Error();
          }
        }
      }
      else {
        SockadrToNetadr();
        if (sVar1 != 0xfaa) {
          NET_TransferRawData();
          if (*DAT_00226ff4 == -2) {
            NET_GetLong();
            return;
          }
          break;
        }
        puVar5 = &in_from;
        puVar6 = (undefined4 *)&stack0xfffff010;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        uVar3 = NET_AdrToString();
        Con_Printf("NET_QueuePacket:  Oversize packet from %s\n",uVar3);
      }
    }
    local_fcc = local_fcc + 1;
  } while (local_fcc < 1);
  NET_LagPacket();
  return;
}


// NET_RemoveFromPacketList  @ 0008f3dc
void NET_RemoveFromPacketList(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// NET_SendLong  @ 000900e4
int NET_SendLong(int param_1,int param_2,void *param_3,uint param_4,int param_5,sockaddr *param_6,
                socklen_t param_7)

{
  uint uVar1;
  char cVar2;
  ssize_t sVar3;
  int iVar4;
  size_t __n;
  void *local_594;
  char local_584;
  int local_580;
  undefined4 local_57c;
  int local_578;
  char local_574;
  undefined1 local_573 [1391];
  
  if ((param_1 == 1) && (0x578 < (int)param_4)) {
    iVar4 = gSequenceNumber_170 + 1;
    gSequenceNumber_170 = gSequenceNumber_170 + 1;
    if (iVar4 < 0) {
      gSequenceNumber_170 = 1;
    }
    local_57c = 0xfffffffe;
    local_578 = gSequenceNumber_170;
    cVar2 = '\0';
    local_580 = 0;
    uVar1 = param_4 + 0x56e;
    if (0 < (int)param_4) {
      local_594 = param_3;
      do {
        __n = 0x56f;
        if (param_4 < 0x570) {
          __n = param_4;
        }
        local_584 = (char)(uVar1 / 0x56f);
        local_574 = cVar2 * '\x10' + local_584;
        memcpy(local_573,local_594,__n);
        sVar3 = sendto(param_2,&local_57c,__n + 9,param_5,param_6,param_7);
        if (sVar3 < 0) {
          return sVar3;
        }
        if ((int)__n <= sVar3) {
          local_580 = local_580 + __n;
        }
        param_4 = param_4 - __n;
        local_594 = (void *)((int)local_594 + 0x56f);
        cVar2 = cVar2 + '\x01';
      } while (0 < (int)param_4);
    }
  }
  else {
    local_580 = sendto(param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_580;
}


// NET_SendLoopPacket  @ 0008f358
void NET_SendLoopPacket(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  NET_ThreadLock();
  iVar1 = (param_1 ^ 1) * 0x3f38;
  uVar2 = *(uint *)(loopbacks + iVar1 + 0x3f34);
  *(uint *)(loopbacks + iVar1 + 0x3f34) = uVar2 + 1;
  iVar3 = (uVar2 & 3) * 0xfcc;
  Q_memcpy(loopbacks + iVar3 + iVar1,param_3,param_2);
  *(undefined4 *)(loopbacks + iVar3 + 0xfc8 + iVar1) = param_2;
  NET_ThreadUnlock();
  return;
}


// NET_SendPacket  @ 00090268
void NET_SendPacket(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  char **ppcVar5;
  char *apcStack_38 [5];
  undefined1 local_14 [16];
  
  apcStack_38[4] = (char *)0x90276;
  if (param_4 == 1) {
    puVar4 = &param_4;
    ppcVar5 = apcStack_38;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppcVar5 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    NET_SendLoopPacket(param_1,param_2,param_3);
  }
  else {
    if ((param_4 == 2) || (param_4 == 3)) {
      unaff_EDI = (&ip_sockets)[param_1];
      if (unaff_EDI == 0) {
        return;
      }
    }
    else {
      apcStack_38[4] = "NET_SendPacket: bad address type";
      apcStack_38[3] = (char *)0x902d8;
      Sys_Error();
    }
    apcStack_38[2] = "j\x10Vj";
    apcStack_38[3] = (char *)&param_4;
    apcStack_38[4] = local_14;
    NetadrToSockadr();
    apcStack_38[2] = (char *)0x10;
    apcStack_38[0] = (char *)0x0;
    apcStack_38[1] = local_14;
    iVar3 = NET_SendLong(param_1,unaff_EDI,param_3,param_2);
    if (iVar3 == -1) {
      apcStack_38[4] = (char *)0x90313;
      piVar1 = __errno_location();
      iVar3 = *piVar1;
      if ((((iVar3 != 0xb) && (iVar3 != 0x6f)) && (iVar3 != 0x68)) &&
         ((iVar3 != 99 || (param_4 != 2)))) {
        if (cls == 0) {
          apcStack_38[3] = (char *)0x90340;
          apcStack_38[4] = (char *)iVar3;
          apcStack_38[3] = (char *)NET_ErrorString();
          apcStack_38[2] = "NET_SendPacket ERROR: %s\n";
          apcStack_38[1] = (char *)0x9034d;
          Con_Printf();
        }
        else if (iVar3 == 99) {
          puVar4 = &param_4;
          ppcVar5 = apcStack_38;
          for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
            *ppcVar5 = (char *)*puVar4;
            puVar4 = puVar4 + 1;
            ppcVar5 = ppcVar5 + 1;
          }
          uVar2 = NET_AdrToString();
          uVar2 = NET_ErrorString(99,uVar2);
          Con_DPrintf("NET_SendPacket Warning: %s : %s\n",uVar2);
        }
        else {
          apcStack_38[3] = (char *)0x9038a;
          apcStack_38[4] = (char *)iVar3;
          apcStack_38[3] = (char *)NET_ErrorString();
          apcStack_38[2] = "NET_SendPacket ERROR: %s\n";
          apcStack_38[1] = (char *)0x90397;
          Sys_Error();
        }
      }
    }
  }
  return;
}


// NET_Shutdown  @ 00090c3c
void NET_Shutdown(void)

{
  NET_ThreadLock();
  NET_ClearLaggedList(g_pLagData);
  NET_ClearLaggedList(0xe44c8);
  NET_ThreadUnlock();
  NET_Config(0);
  NET_FlushQueues();
  return;
}


// NET_Sleep  @ 0008fb48
void NET_Sleep(void)

{
  byte *pbVar1;
  int iVar2;
  __fd_mask *p_Var3;
  timeval *local_98;
  uint local_94;
  timeval local_8c;
  byte local_84 [128];
  
  p_Var3 = (__fd_mask *)local_84;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *p_Var3 = 0;
    p_Var3 = p_Var3 + 1;
  }
  local_94 = 0;
  if (ip_sockets != 0) {
    pbVar1 = (byte *)((int)local_84 + ((int)(ip_sockets & 0x1f) >> 3) + (ip_sockets >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (ip_sockets & 7);
    if (0 < (int)ip_sockets) {
      local_94 = ip_sockets;
    }
  }
  if (DAT_000b3878 != 0) {
    pbVar1 = (byte *)((int)local_84 + ((int)(DAT_000b3878 & 0x1f) >> 3) + (DAT_000b3878 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (DAT_000b3878 & 7);
    if ((int)local_94 < (int)DAT_000b3878) {
      local_94 = DAT_000b3878;
    }
  }
  local_8c.tv_sec = 0;
  local_98 = (timeval *)0x0;
  local_8c.tv_usec = 20000;
  if (net_sleepforever == 0) {
    local_98 = &local_8c;
  }
  select(local_94 + 1,(fd_set *)local_84,(fd_set *)0x0,(fd_set *)0x0,local_98);
  return;
}


// NET_StartThread  @ 0008fc60
void NET_StartThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized == 0)) {
    net_thread_initialized = 1;
  }
  return;
}


// NET_StopThread  @ 0008fc98
void NET_StopThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized != 0)) {
    net_thread_initialized = 0;
  }
  return;
}


// NET_StringToAdr  @ 0008f1cc
undefined4 NET_StringToAdr(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_14 [16];
  
  iVar1 = Q_strcmp(param_1,"localhost");
  if (iVar1 == 0) {
    Q_memset(param_2,0,0x14);
    *param_2 = 1;
    uVar2 = 1;
  }
  else {
    iVar1 = NET_StringToSockaddr(param_1,local_14);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      SockadrToNetadr(local_14,param_2);
      uVar2 = 1;
    }
  }
  return uVar2;
}


// NET_StringToSockaddr  @ 0008f0e4
undefined4 NET_StringToSockaddr(undefined4 param_1,undefined2 *param_2)

{
  char cVar1;
  uint16_t uVar2;
  int iVar3;
  in_addr_t iVar4;
  hostent *phVar5;
  char *pcVar6;
  char local_84 [128];
  
  Q_memset(param_2,0,0x10);
  *param_2 = 2;
  param_2[1] = 0;
  Q_strcpy(local_84,param_1);
  pcVar6 = local_84;
  cVar1 = local_84[0];
  while (cVar1 != '\0') {
    if (*pcVar6 == ':') {
      *pcVar6 = '\0';
      uVar2 = __strtol_internal(pcVar6 + 1,0,10,0);
      uVar2 = htons(uVar2);
      param_2[1] = uVar2;
    }
    pcVar6 = pcVar6 + 1;
    cVar1 = *pcVar6;
  }
  if (((byte)(local_84[0] - 0x30U) < 10) && (iVar3 = Q_strstr(local_84,&DAT_000adfdb), iVar3 != 0))
  {
    iVar4 = inet_addr(local_84);
  }
  else {
    phVar5 = gethostbyname(local_84);
    if (phVar5 == (hostent *)0x0) {
      return 0;
    }
    iVar4 = *(in_addr_t *)*phVar5->h_addr_list;
  }
  *(in_addr_t *)(param_2 + 2) = iVar4;
  return 1;
}


// NET_ThreadLock  @ 0008ee44
void NET_ThreadLock(void)

{
  return;
}


// NET_ThreadUnlock  @ 0008ee4c
void NET_ThreadUnlock(void)

{
  return;
}


// NET_TransferRawData  @ 0008f278
void NET_TransferRawData(int param_1,undefined4 param_2,undefined4 param_3)

{
  Q_memcpy(*(undefined4 *)(param_1 + 4),param_2,param_3);
  *(undefined4 *)(param_1 + 0xc) = param_3;
  return;
}


