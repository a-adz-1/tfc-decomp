// NET_AddToLagged  @ 000c3760
void NET_AddToLagged(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                    undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_3[9] == 0) && (param_3[8] == 0)) {
    param_3[9] = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 **)(*(int *)(param_2 + 0x24) + 0x20) = param_3;
    *(undefined4 **)(param_2 + 0x24) = param_3;
    param_3[8] = param_2;
    uVar1 = Mem_Malloc(param_9);
    *param_3 = uVar1;
    Q_memcpy(*param_3,param_7,param_9);
    param_3[1] = param_9;
    param_3[7] = param_10;
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


// NET_AdjustLag  @ 000c3838
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NET_AdjustLag(void)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float local_14;
  
  dVar1 = realtime - lasttime_77;
  if (dVar1 < 0.0) {
    dVar1 = 0.0;
  }
  if ((byte)(_FUN_000ed510 < dVar1 |
             (byte)((ushort)((ushort)(NAN(_FUN_000ed510) || NAN(dVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_FUN_000ed510 == dVar1) << 0xe) >> 8)) == 1) {
    dVar1 = _FUN_000ed510;
  }
  lasttime_77 = realtime;
  if ((allow_cheats == 0) &&
     ((byte)(0.0 < (float)fakelag._12_4_ |
             (byte)((ushort)((ushort)NAN((float)fakelag._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)fakelag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    Con_Printf("Server must enable cheats to activate fakelag\n");
    Cvar_SetValue("fakelag",0);
    gFakeLag = 0;
  }
  else if ((byte)((byte)((ushort)((ushort)(NAN((float)fakelag._12_4_) || NAN((float)gFakeLag)) << 10
                                 ) >> 8) |
                 (byte)((ushort)((ushort)((float)fakelag._12_4_ == (float)gFakeLag) << 0xe) >> 8))
           != 0x40) {
    fVar2 = (float)fakelag._12_4_ - (float)gFakeLag;
    local_14 = (float)((longdouble)200.0 * (longdouble)dVar1);
    fVar3 = ABS(fVar2);
    if ((byte)(fVar3 < local_14 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(local_14)) << 10) >> 8)
              | (byte)((ushort)((ushort)(fVar3 == local_14) << 0xe) >> 8)) == 1) {
      local_14 = ABS(fVar2);
    }
    if (fVar2 < 0.0) {
      local_14 = -local_14;
    }
    gFakeLag = (int)ROUND((float)gFakeLag + local_14);
  }
  return;
}


// NET_AdrToString  @ 000c3074
undefined1 *
NET_AdrToString(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint16_t uVar1;
  
  Q_memset(s_36,0,0x40);
  if (param_1 == 1) {
    snprintf(s_36,0x40,"loopback");
  }
  else if (param_1 == 3) {
    uVar1 = ntohs(param_5._2_2_);
    snprintf(s_36,0x40,"%i.%i.%i.%i:%i",param_2 & 0xff,param_2 >> 8 & 0xff,param_2 >> 0x10 & 0xff,
             param_2 >> 0x18,(uint)uVar1);
  }
  return s_36;
}


// NET_AllocMsg  @ 000c4740
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
  }
  else {
    puVar2 = (undefined4 *)net_malloc(0x24);
    uVar3 = net_malloc(param_1);
    puVar2[2] = uVar3;
    puVar2[8] = param_1;
    puVar2[1] = 0;
  }
  return puVar2;
}


// NET_AllocateQueues  @ 000c4ae0
void NET_AllocateQueues(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x28; local_8 = local_8 + 1) {
    puVar1 = (undefined4 *)Mem_ZeroMalloc(0x24);
    uVar2 = Mem_ZeroMalloc(0x600);
    puVar1[2] = uVar2;
    puVar1[1] = 1;
    *puVar1 = normalqueue;
    normalqueue = puVar1;
  }
  NET_StartThread();
  return;
}


// NET_BaseAdrToString  @ 000c3130
undefined1 * NET_BaseAdrToString(int param_1,uint param_2)

{
  Q_memset(s_40,0,0x40);
  if (param_1 == 1) {
    snprintf(s_40,0x40,"loopback");
  }
  else if (param_1 == 3) {
    snprintf(s_40,0x40,"%i.%i.%i.%i",param_2 & 0xff,param_2 >> 8 & 0xff,param_2 >> 0x10 & 0xff,
             param_2 >> 0x18);
  }
  return s_40;
}


// NET_ClearLagData  @ 000c5f48
void NET_ClearLagData(int param_1,int param_2)

{
  NET_ThreadLock();
  if (param_1 != 0) {
    NET_ClearLaggedList(g_pLagData);
    NET_ClearLaggedList(0x1498b0);
  }
  if (param_2 != 0) {
    NET_ClearLaggedList(0x149888);
  }
  NET_ThreadUnlock();
  return;
}


// NET_ClearLaggedList  @ 000c36c0
void NET_ClearLaggedList(int *param_1)

{
  int *piVar1;
  int *local_8;
  
  local_8 = (int *)param_1[8];
  while ((local_8 != (int *)0x0 && (local_8 != param_1))) {
    piVar1 = (int *)local_8[8];
    NET_RemoveFromPacketList(local_8);
    if (*local_8 != 0) {
      Mem_Free(*local_8);
      *local_8 = 0;
    }
    Mem_Free(local_8);
    local_8 = piVar1;
  }
  param_1[9] = (int)param_1;
  param_1[8] = (int)param_1;
  return;
}


// NET_CompareAdr  @ 000c2f0c
undefined4
NET_CompareAdr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  
  if (param_1 == param_6) {
    if (param_1 == 1) {
      uVar1 = 1;
    }
    else if (param_1 == 3) {
      if (((((char)param_2 == (char)param_7) && (param_2._1_1_ == param_7._1_1_)) &&
          (param_2._2_1_ == param_7._2_1_)) &&
         ((param_2._3_1_ == param_7._3_1_ && (param_5._2_2_ == param_10._2_2_)))) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_CompareBaseAdr  @ 000c3018
undefined4 NET_CompareBaseAdr(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_stack_00000018;
  char cStack0000001c;
  char cStack0000001d;
  char cStack0000001e;
  char cStack0000001f;
  
  if (param_1 == in_stack_00000018) {
    if (param_1 == 1) {
      uVar1 = 1;
    }
    else if (param_1 == 3) {
      if (((((char)param_2 == cStack0000001c) && (param_2._1_1_ == cStack0000001d)) &&
          (param_2._2_1_ == cStack0000001e)) && (param_2._3_1_ == cStack0000001f)) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_CompareClassBAdr  @ 000c2f70
undefined4 NET_CompareClassBAdr(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_stack_00000018;
  char cStack0000001c;
  char cStack0000001d;
  
  if (param_1 == in_stack_00000018) {
    if (param_1 == 1) {
      uVar1 = 1;
    }
    else if (param_1 == 3) {
      if (((char)param_2 == cStack0000001c) && (param_2._1_1_ == cStack0000001d)) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_Config  @ 000c59cc
void NET_Config(int param_1)

{
  int local_8;
  
  if (old_config_150 != param_1) {
    old_config_150 = param_1;
    if (param_1 == 0) {
      NET_ThreadLock();
      for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
        if ((&ip_sockets)[local_8] != 0) {
          close((&ip_sockets)[local_8]);
          (&ip_sockets)[local_8] = 0;
        }
      }
      NET_ThreadUnlock();
    }
    else {
      if (noip == 0) {
        NET_OpenIP();
      }
      if (bFirst_151 != 0) {
        bFirst_151 = 0;
        NET_GetLocalAddress();
      }
    }
    net_configured = (uint)(param_1 != 0);
  }
  return;
}


// NET_CountLaggedList  @ 000c3678
int NET_CountLaggedList(int param_1)

{
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = *(int *)(param_1 + 0x20); (local_c != 0 && (local_c != param_1));
      local_c = *(int *)(local_c + 0x20)) {
    local_8 = local_8 + 1;
  }
  return local_8;
}


// NET_ErrorString  @ 000c33d0
char * NET_ErrorString(int param_1)

{
  char *pcVar1;
  
  pcVar1 = strerror(param_1);
  return pcVar1;
}


// NET_FlushQueues  @ 000c4b60
void NET_FlushQueues(void)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  int local_8;
  
  NET_StopThread();
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    local_c = *(undefined4 **)(messages + local_8 * 4);
    while (local_c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_c;
      Mem_Free(local_c[2]);
      Mem_Free(local_c);
      local_c = puVar1;
    }
    *(undefined4 *)(messages + local_8 * 4) = 0;
  }
  local_c = normalqueue;
  while (local_c != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_c;
    Mem_Free(local_c[2]);
    Mem_Free(local_c);
    local_c = puVar1;
  }
  normalqueue = (undefined4 *)0x0;
  return;
}


// NET_FlushSocket  @ 000c3c6c
void NET_FlushSocket(int param_1)

{
  ssize_t sVar1;
  undefined1 local_fc8 [4012];
  int local_1c;
  socklen_t local_18;
  sockaddr local_14;
  
  local_1c = (&ip_sockets)[param_1];
  if (local_1c != 0) {
    local_18 = 0x10;
    do {
      sVar1 = recvfrom(local_1c,local_fc8,0xfaa,0,&local_14,&local_18);
    } while (0 < sVar1);
  }
  return;
}


// NET_FreeMsg  @ 000c47e8
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


// NET_GetLocalAddress  @ 000c57a4
void NET_GetLocalAddress(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int aiStackY_26c [6];
  undefined *puStackY_254;
  undefined4 uStackY_250;
  socklen_t local_218;
  sockaddr local_214;
  char local_204 [511];
  undefined1 local_5;
  
  uStackY_250 = 0xc57db;
  Q_memset();
  if (noip == 0) {
    uStackY_250 = 0xc581c;
    iVar1 = Q_strcmp();
    if (iVar1 == 0) {
      uStackY_250 = 0xc5860;
      gethostname(local_204,0x200);
    }
    else {
      uStackY_250 = 0xc5840;
      Q_strncpy();
    }
    local_5 = 0;
    uStackY_250 = 0xc587f;
    NET_StringToAdr();
    local_218 = 0x10;
    uStackY_250 = 0xc58ae;
    iVar1 = getsockname(DAT_000f30b4,&local_214,&local_218);
    if (iVar1 == 0) {
      DAT_0058d8aa._0_1_ = local_214.sa_data[0];
      DAT_0058d8aa._1_1_ = local_214.sa_data[1];
      puVar3 = &net_local_adr;
      piVar2 = aiStackY_26c + 2;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar2 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar2 = piVar2 + 1;
      }
      aiStackY_26c[1] = 0xc5935;
      NET_AdrToString();
      uStackY_250 = 0xc5949;
      Con_Printf();
      puVar3 = &net_local_adr;
      piVar2 = aiStackY_26c;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar2 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar2 = piVar2 + 1;
      }
      uStackY_250 = NET_AdrToString();
      puStackY_254 = &DAT_000edb71;
      aiStackY_26c[5] = 0xc5983;
      va();
      uStackY_250 = 0xc5997;
      Cvar_Set();
    }
    else {
      piVar2 = __errno_location();
      puStackY_254 = (undefined *)*piVar2;
      noip = 1;
      aiStackY_26c[5] = 0xc58e6;
      NET_ErrorString();
      uStackY_250 = 0xc58fa;
      Con_Printf();
    }
  }
  else {
    uStackY_250 = 0xc57fa;
    Con_Printf();
  }
  return;
}


// NET_GetLong  @ 000c3cf4
undefined4 NET_GetLong(void *param_1,int param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  size_t __n;
  uint uVar5;
  size_t sVar6;
  int local_20;
  
  sVar6 = 0xc3d01;
  iVar1 = *(int *)((int)param_1 + 4);
  uVar3 = (uint)(*(byte *)((int)param_1 + 8) >> 4);
  uVar4 = (uint)(*(byte *)((int)param_1 + 8) & 0xf);
  if (((gNetSplit == -1) || (iVar1 != gNetSplit)) &&
     (gNetSplit = iVar1, DAT_0058c8e4 = uVar4,
     (byte)((byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
           (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 4.0) << 0xe) >> 8)) == 0x40)) {
    Con_Printf("<-- Split packet restart %i count %i seq\n",uVar4,iVar1);
  }
  __n = param_2 - 9;
  if (*(int *)(gNetSplitFlags_88 + uVar3 * 4) == iVar1) {
    uVar5 = uVar4;
    Con_Printf("NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes )\n",uVar3 + 1,
               uVar4,__n);
  }
  else {
    if (uVar3 == uVar4 - 1) {
      DAT_0058c8e8 = __n + (uVar4 - 1) * 0x56f;
    }
    DAT_0058c8e4 = DAT_0058c8e4 - 1;
    *(int *)(gNetSplitFlags_88 + uVar3 * 4) = iVar1;
    if ((byte)((byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 4.0) << 0xe) >> 8)) == 0x40)
    {
      Con_Printf("<-- Split packet %i of %i, %i bytes %i seq\n",uVar3 + 1,uVar4,__n,iVar1);
    }
    memcpy(&DAT_0058c8ec + uVar3 * 0x56f,(void *)((int)param_1 + 9),__n);
    uVar5 = __n;
    __n = sVar6;
  }
  if ((int)DAT_0058c8e4 < 1) {
    for (local_20 = 0; local_20 < (int)uVar4; local_20 = local_20 + 1) {
      if (*(int *)(gNetSplitFlags_88 + local_20 * 4) != gNetSplit) {
        Con_Printf("Split packet without all %i parts, part %i had wrong sequence %i/%i\n",uVar4,
                   local_20 + 1,*(undefined4 *)(gNetSplitFlags_88 + local_20 * 4),gNetSplit);
        return 0;
      }
    }
    gNetSplit = -1;
    if (DAT_0058c8e8 < 0xfab) {
      memcpy(param_1,&DAT_0058c8ec,DAT_0058c8e8);
      *param_3 = DAT_0058c8e8;
      uVar2 = 1;
    }
    else {
      Con_Printf("Split packet too large! %d bytes\n",DAT_0058c8e8,uVar5,__n);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// NET_GetLoopPacket  @ 000c3440
bool NET_GetLoopPacket(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  param_1 = param_1 * 0x3f38;
  if (4 < *(int *)(loopbacks + param_1 + 0x3f34) - *(int *)(loopbacks + param_1 + 0x3f30)) {
    *(int *)(loopbacks + param_1 + 0x3f30) = *(int *)(loopbacks + param_1 + 0x3f34) + -4;
  }
  iVar2 = *(int *)(loopbacks + param_1 + 0x3f30);
  iVar1 = *(int *)(loopbacks + param_1 + 0x3f34);
  if (iVar2 < iVar1) {
    uVar3 = *(uint *)(loopbacks + param_1 + 0x3f30);
    *(int *)(loopbacks + param_1 + 0x3f30) = *(int *)(loopbacks + param_1 + 0x3f30) + 1;
    NET_TransferRawData(param_3,loopbacks + (uVar3 & 3) * 0xfcc + param_1,
                        *(undefined4 *)((uVar3 & 3) * 0xfcc + param_1 + 0x1429a8));
    Q_memset(param_2,0,0x14);
    *param_2 = 1;
  }
  return iVar2 < iVar1;
}


// NET_GetPacket  @ 000c4848
int NET_GetPacket(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  NET_AdjustLag();
  NET_ThreadLock();
  iVar1 = NET_GetLoopPacket(param_1,&in_from,&in_message);
  if (iVar1 == 0) {
    if (use_thread == 0) {
      local_c = NET_QueuePacket(param_1);
    }
    if (local_c == 0) {
      local_c = NET_LagPacket(0,param_1,0,0);
    }
  }
  else {
    local_c = NET_LagPacket(1,param_1,&in_from,&in_message);
  }
  if (local_c == 0) {
    if (*(int *)(messages + param_1 * 4) != 0) {
      local_8 = *(int *)(messages + param_1 * 4);
      *(undefined4 *)(messages + param_1 * 4) = **(undefined4 **)(messages + param_1 * 4);
      DAT_0059d8d0 = *(int *)(local_8 + 0x20);
      Q_memcpy(DAT_0059d8c8,*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0x20));
      puVar2 = (undefined4 *)(local_8 + 0xc);
      puVar3 = &net_from;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      msg_readcount = 0;
      NET_FreeMsg(local_8);
      local_c = 1;
    }
  }
  else {
    if (*DAT_0059d8dc == -3) {
      local_10 = DAT_0059d8cc;
      iVar1 = DecompressPacket(DAT_0059d8c8,&local_10,DAT_0059d8dc + 1,DAT_0059d8e4 + -4);
      DAT_0059d8d0 = local_10;
      if (iVar1 != 1) {
        Q_memcpy(DAT_0059d8c8,DAT_0059d8dc,DAT_0059d8e4);
        DAT_0059d8d0 = DAT_0059d8e4;
      }
    }
    else {
      Q_memcpy(DAT_0059d8c8,DAT_0059d8dc,DAT_0059d8e4);
      DAT_0059d8d0 = DAT_0059d8e4;
    }
    puVar2 = &in_from;
    puVar3 = &net_from;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  NET_ThreadUnlock();
  return local_c;
}


// NET_HostToNetShort  @ 000c2ecc
uint16_t NET_HostToNetShort(uint16_t param_1)

{
  uint16_t uVar1;
  
  uVar1 = htons(param_1);
  return uVar1;
}


// NET_IPSocket  @ 000c5110
/* WARNING: Type propagation algorithm not settling */

int NET_IPSocket(char *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_28;
  int local_24;
  uint local_20 [2];
  sockaddr local_18;
  int local_8;
  
  local_20[1] = 1;
  local_20[0] = 1;
  local_8 = socket(2,2,0x11);
  if (local_8 == -1) {
    piVar1 = __errno_location();
    local_24 = *piVar1;
    if (local_24 != 0x61) {
      uVar2 = NET_ErrorString(local_24);
      Con_Printf("WARNING: UDP_OpenSocket: port: %d socket: %s",param_2,uVar2);
    }
    local_8 = 0;
  }
  else {
    iVar3 = ioctl(local_8,0x5421,local_20 + 1);
    if (iVar3 == -1) {
      piVar1 = __errno_location();
      local_24 = *piVar1;
      uVar2 = NET_ErrorString(local_24);
      Con_Printf("WARNING: UDP_OpenSocket: port: %d  ioctl FIONBIO: %s\n",param_2,uVar2);
      local_8 = 0;
    }
    else {
      iVar3 = setsockopt(local_8,1,6,local_20,4);
      if (iVar3 == -1) {
        piVar1 = __errno_location();
        local_24 = *piVar1;
        uVar2 = NET_ErrorString(local_24);
        Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt SO_BROADCAST: %s\n",param_2,uVar2)
        ;
        local_8 = 0;
      }
      else {
        iVar3 = COM_CheckParm("-reuse");
        if (((iVar3 == 0) && (param_3 == 0)) ||
           (iVar3 = setsockopt(local_8,1,2,local_20 + 1,4), iVar3 != -1)) {
          iVar3 = COM_CheckParm(&DAT_000ed940);
          if (iVar3 != 0) {
            local_28 = 0x10;
            Con_Printf("Enabling LOWDELAY TOS option\n");
            iVar3 = setsockopt(local_8,0,1,&local_28,4);
            if ((iVar3 < 0) && (piVar1 = __errno_location(), *piVar1 != 0x5c)) {
              piVar1 = __errno_location();
              local_24 = *piVar1;
              uVar2 = NET_ErrorString(local_24);
              Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt IP_TOS: %s\n",param_2,uVar2)
              ;
              return 0;
            }
          }
          if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
             (iVar3 = Q_stricmp(param_1,"localhost"), iVar3 == 0)) {
            local_18.sa_data[2] = '\0';
            local_18.sa_data[3] = '\0';
            local_18.sa_data[4] = '\0';
            local_18.sa_data[5] = '\0';
          }
          else {
            NET_StringToSockaddr(param_1,&local_18);
          }
          if (param_2 == -1) {
            local_18.sa_data[0] = '\0';
            local_18.sa_data[1] = '\0';
          }
          else {
            local_18.sa_data._0_2_ = htons((uint16_t)param_2);
          }
          local_18.sa_family = 2;
          iVar3 = bind(local_8,&local_18,0x10);
          if (iVar3 == -1) {
            piVar1 = __errno_location();
            local_24 = *piVar1;
            uVar2 = NET_ErrorString(local_24);
            Con_Printf("WARNING: UDP_OpenSocket: port: %d  bind: %s\n",param_2,uVar2);
            close(local_8);
            local_8 = 0;
          }
          else {
            iVar3 = COM_CheckParm("-loopback");
            local_20[0] = (uint)(iVar3 != 0);
            iVar3 = setsockopt(local_8,0,0x22,local_20,4);
            if (iVar3 == -1) {
              piVar1 = __errno_location();
              local_24 = *piVar1;
              uVar2 = NET_ErrorString(local_24);
              Con_DPrintf("WARNING: UDP_OpenSocket: port %d setsockopt IP_MULTICAST_LOOP: %s\n",
                          param_2,uVar2);
            }
          }
        }
        else {
          piVar1 = __errno_location();
          local_24 = *piVar1;
          uVar2 = NET_ErrorString(local_24);
          Con_Printf("WARNING: UDP_OpenSocket: port: %d  setsockopt SO_REUSEADDR: %s\n",param_2,
                     uVar2);
          local_8 = 0;
        }
      }
    }
  }
  return local_8;
}


// NET_Init  @ 000c5bd0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NET_Init(void)

{
  int iVar1;
  double dVar2;
  int local_8;
  
  Cmd_AddCommand("maxplayers",MaxPlayers_f);
  Cvar_RegisterVariable(net_address);
  Cvar_RegisterVariable(ipname);
  Cvar_RegisterVariable(iphostport);
  Cvar_RegisterVariable(hostport);
  Cvar_RegisterVariable(defport);
  Cvar_RegisterVariable(ip_clientport);
  Cvar_RegisterVariable(clientport);
  Cvar_RegisterVariable(clockwindow);
  Cvar_RegisterVariable(multicastport);
  Cvar_RegisterVariable(fakelag);
  Cvar_RegisterVariable(fakeloss);
  Cvar_RegisterVariable(net_graph);
  Cvar_RegisterVariable(net_graphwidth);
  Cvar_RegisterVariable(net_scale);
  Cvar_RegisterVariable(net_graphpos);
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
    dVar2 = atof(*(char **)(iVar1 * 4 + com_argv + 4));
    Cvar_SetValue("hostport",(float)dVar2);
  }
  iVar1 = COM_CheckParm("-clockwindow");
  if (iVar1 != 0) {
    dVar2 = atof(*(char **)(iVar1 * 4 + com_argv + 4));
    Cvar_SetValue("clockwindow",(float)dVar2);
  }
  DAT_0059d8cc = 0x10000;
  DAT_0059d8c8 = net_message_buffer;
  DAT_0059d8c4 = 0;
  net_message = "net_message";
  DAT_0059d8e0 = 0x10000;
  DAT_0059d8dc = in_message_buf;
  _DAT_0059d8d8 = 0;
  in_message = "in_message";
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    *(undefined1 **)(g_pLagData + local_8 * 0x28 + 0x24) = g_pLagData + local_8 * 0x28;
    *(undefined1 **)(g_pLagData + local_8 * 0x28 + 0x20) = g_pLagData + local_8 * 0x28;
  }
  NET_AllocateQueues();
  Con_DPrintf("Base networking initialized.\n");
  return;
}


// NET_IsConfigured  @ 000c59a8
undefined4 NET_IsConfigured(void)

{
  return net_configured;
}


// NET_IsLocalAddress  @ 000c33b8
bool NET_IsLocalAddress(int param_1)

{
  return param_1 == 1;
}


// NET_IsReservedAdr  @ 000c2fbc
undefined4 NET_IsReservedAdr(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    uVar1 = 1;
  }
  else if (param_1 == 3) {
    if (((((char)param_2 == '\n') || ((char)param_2 == '\x7f')) ||
        (((char)param_2 == -0x54 && ((0xf < param_2._1_1_ && (param_2._1_1_ < 0x20)))))) ||
       (((char)param_2 == -0x40 && (0xa7 < param_2._1_1_)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// NET_JoinGroup  @ 000c6014
undefined4 NET_JoinGroup(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = (&ip_sockets)[param_1];
  local_14 = param_3;
  local_10 = 0;
  iVar1 = setsockopt(local_8,0,0x23,&local_14,8);
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    local_c = *piVar2;
    if (local_c != 0x61) {
      uVar3 = NET_ErrorString(local_c);
      Con_Printf("WARNING: NET_JoinGroup: IP_ADD_MEMBERSHIP: %s",uVar3);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


// NET_LagPacket  @ 000c39a4
int NET_LagPacket(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 auStack_6c [4];
  int *local_c;
  
  if ((longdouble)gFakeLag <= (longdouble)0) {
    auStack_6c[3] = 0xc39d6;
    NET_ClearLagData();
    return param_1;
  }
  fVar2 = (float)realtime;
  if (param_1 != 0) {
    if ((byte)(0.0 < (float)fakeloss._12_4_ |
               (byte)((ushort)((ushort)NAN((float)fakeloss._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)fakeloss._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      if (allow_cheats == 0) {
        auStack_6c[3] = 0xc3a32;
        Cvar_SetValue();
      }
      else {
        *(int *)(losscount_81 + param_2 * 4) = *(int *)(losscount_81 + param_2 * 4) + 1;
        if ((byte)(0.0 < (float)fakeloss._12_4_ |
                   (byte)((ushort)((ushort)NAN((float)fakeloss._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)fakeloss._12_4_ == 0.0) << 0xe) >> 8)) == 1) {
          auStack_6c[3] = 0xc3a74;
          iVar5 = RandomLong();
          if (iVar5 <= (int)ROUND((float)fakeloss._12_4_)) {
            return 0;
          }
        }
        else {
          iVar5 = (int)ROUND(ABS((float)fakeloss._12_4_));
          if (iVar5 < 2) {
            iVar5 = 2;
          }
          if (*(int *)(losscount_81 + param_2 * 4) % iVar5 == 0) {
            return 0;
          }
        }
      }
    }
    auStack_6c[3] = 0xc3b16;
    uVar4 = Mem_ZeroMalloc();
    puVar7 = auStack_6c;
    for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *param_4;
      param_4 = param_4 + 1;
      puVar7 = puVar7 + 1;
    }
    NET_AddToLagged(param_2,g_pLagData + param_2 * 0x28,uVar4,param_3);
  }
  local_c = *(int **)(g_pLagData + param_2 * 0x28 + 0x20);
  while( true ) {
    if (local_c == (int *)(g_pLagData + param_2 * 0x28)) {
      return 0;
    }
    fVar3 = fVar2 - (float)gFakeLag / 1000.0;
    fVar1 = (float)local_c[7];
    if ((byte)((fVar1 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar3) << 0xe) >> 8)) - 1) < 0x40) break;
    local_c = (int *)local_c[8];
  }
  auStack_6c[3] = 0xc3be3;
  NET_RemoveFromPacketList();
  auStack_6c[3] = 0xc3c04;
  NET_TransferRawData();
  piVar6 = local_c + 2;
  piVar8 = &in_from;
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar8 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar8 = piVar8 + 1;
  }
  if (*local_c != 0) {
    auStack_6c[3] = 0xc3c33;
    free((void *)*local_c);
  }
  auStack_6c[3] = 0xc3c42;
  Mem_Free();
  return 1;
}


// NET_LeaveGroup  @ 000c60bc
undefined4 NET_LeaveGroup(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  local_8 = (&ip_sockets)[param_1];
  local_14 = param_3;
  local_10 = 0;
  iVar1 = setsockopt(local_8,0,0x24,&local_14,8);
  if ((iVar1 == -1) && (piVar2 = __errno_location(), *piVar2 != 0x61)) {
    return 0;
  }
  return 1;
}


// NET_OpenIP  @ 000c5500
void NET_OpenIP(void)

{
  bool bVar1;
  int local_18;
  int local_14;
  int local_c;
  
  local_14 = 0;
  local_18 = 0;
  bVar1 = cls == 0;
  NET_ThreadLock();
  if (DAT_000f30b4 == 0) {
    local_c = (int)ROUND((float)iphostport._12_4_);
    if ((local_c == 0) && (local_c = (int)ROUND((float)hostport._12_4_), local_c == 0)) {
      hostport._12_4_ = defport._12_4_;
      local_c = (int)ROUND((float)defport._12_4_);
    }
    local_14 = local_c;
    DAT_000f30b4 = NET_IPSocket(ipname._4_4_,local_c,0);
    if ((DAT_000f30b4 == 0) && (bVar1)) {
      Sys_Error("Couldn\'t allocate dedicated server IP port");
    }
  }
  NET_ThreadUnlock();
  if (cls != 0) {
    NET_ThreadLock();
    if (ip_sockets == 0) {
      local_c = (int)ROUND((float)ip_clientport._12_4_);
      if ((local_c == 0) && (local_c = (int)ROUND((float)clientport._12_4_), local_c == 0)) {
        local_c = -1;
      }
      local_18 = local_c;
      ip_sockets = NET_IPSocket(ipname._4_4_,local_c,0);
      if (ip_sockets == 0) {
        ip_sockets = NET_IPSocket(ipname._4_4_,0xffffffff,0);
      }
    }
    if (((DAT_000f30b8 == 0) &&
        (DAT_000f30b8 = NET_IPSocket(ipname._4_4_,(int)ROUND((float)multicastport._12_4_),1),
        DAT_000f30b8 == 0)) && (!bVar1)) {
      Con_Printf("Warning! Couldn\'t allocate multicast IP port.\n");
    }
    NET_ThreadUnlock();
    if (bFirst_140 != 0) {
      bFirst_140 = 0;
      Con_Printf("NET Ports:  server %i, client %i\n",local_14,local_18);
    }
  }
  return;
}


// NET_QueuePacket  @ 000c3fe0
undefined4 NET_QueuePacket(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStackY_1014 [2];
  undefined1 local_fd4 [4012];
  int local_28;
  int local_24;
  int local_20;
  socklen_t local_1c;
  sockaddr local_18;
  ssize_t local_8;
  
  local_20 = 0;
  local_24 = 0;
  do {
    if (0 < local_24) {
      uVar2 = NET_LagPacket();
      return uVar2;
    }
    if (local_24 == 0) {
      local_20 = (&ip_sockets)[param_1];
    }
    if (local_20 != 0) {
      local_1c = 0x10;
      auStackY_1014[1] = 0xc406b;
      local_8 = recvfrom(local_20,local_fd4,0xfaa,0,&local_18,&local_1c);
      if (local_8 == -1) {
        piVar1 = __errno_location();
        local_28 = *piVar1;
        if (((local_28 != 0xb) && (local_28 != 0x68)) && (local_28 != 0x6f)) {
          if (local_28 == 0x5a) {
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
        if (local_8 != 0xfaa) {
          NET_TransferRawData();
          if (*DAT_0059d8dc == -2) {
            uVar2 = NET_GetLong();
            return uVar2;
          }
          uVar2 = NET_LagPacket();
          return uVar2;
        }
        puVar4 = &in_from;
        puVar5 = auStackY_1014;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        NET_AdrToString();
        Con_Printf();
      }
    }
    local_24 = local_24 + 1;
  } while( true );
}


// NET_RemoveFromPacketList  @ 000c363c
void NET_RemoveFromPacketList(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// NET_SendLong  @ 000c4c58
int NET_SendLong(int param_1,int param_2,void *param_3,uint param_4,int param_5,sockaddr *param_6,
                socklen_t param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_5f4 [2];
  undefined4 local_5a8 [5];
  undefined4 *local_594;
  int local_590;
  uint local_58c;
  size_t local_588;
  ssize_t local_584;
  int local_580;
  undefined4 local_57c;
  int local_578;
  undefined1 local_573 [1391];
  
  if ((param_1 == 1) && (0x578 < (int)param_4)) {
    gSequenceNumber_128 = gSequenceNumber_128 + 1;
    if (gSequenceNumber_128 < 0) {
      gSequenceNumber_128 = 1;
    }
    local_594 = &local_57c;
    local_57c = 0xfffffffe;
    local_578 = gSequenceNumber_128;
    local_590 = 0;
    local_580 = 0;
    local_58c = (param_4 + 0x56e) / 0x56f;
    for (; 0 < (int)param_4; param_4 = param_4 - local_588) {
      local_588 = param_4;
      if (0x56f < param_4) {
        local_588 = 0x56f;
      }
      *(char *)(local_594 + 2) = (char)local_58c + (char)local_590 * '\x10';
      memcpy(local_573,(void *)(local_590 * 0x56f + (int)param_3),local_588);
      if ((byte)((byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 4.0) << 0xe) >> 8)) ==
          0x40) {
        SockadrToNetadr();
        puVar2 = local_5a8;
        puVar3 = auStackY_5f4;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        NET_AdrToString();
        auStackY_5f4[1] = 0xc4e02;
        Con_DPrintf();
      }
      auStackY_5f4[1] = 0xc4e2e;
      local_584 = sendto(param_2,&local_57c,local_588 + 9,param_5,param_6,param_7);
      if (local_584 < 0) {
        return local_584;
      }
      if ((int)local_588 <= local_584) {
        local_580 = local_580 + local_588;
      }
      local_590 = local_590 + 1;
    }
  }
  else {
    local_594 = (undefined4 *)0x0;
    auStackY_5f4[1] = 0xc4eb2;
    local_580 = sendto(param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_580;
}


// NET_SendLoopPacket  @ 000c356c
void NET_SendLoopPacket(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  NET_ThreadLock();
  iVar2 = (param_1 ^ 1) * 0x3f38;
  uVar1 = *(uint *)(loopbacks + iVar2 + 0x3f34);
  *(int *)(loopbacks + iVar2 + 0x3f34) = *(int *)(loopbacks + iVar2 + 0x3f34) + 1;
  Q_memcpy(loopbacks + (uVar1 & 3) * 0xfcc + iVar2,param_3,param_2);
  *(undefined4 *)((uVar1 & 3) * 0xfcc + iVar2 + 0x1429a8) = param_2;
  NET_ThreadUnlock();
  return;
}


// NET_SendPacket  @ 000c4ed8
void NET_SendPacket(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int aiStack_70 [4];
  int iStack_60;
  char *pcStack_5c;
  undefined1 *puStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int local_1c;
  undefined1 local_18 [16];
  int local_8;
  
  uStack_50 = 0xc4ee6;
  uncompressTotal_132 = uncompressTotal_132 + param_2;
  compressTotal_133 = compressTotal_133 + param_2;
  if (param_4 == 1) {
    puVar4 = &param_4;
    piVar1 = &iStack_60;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      piVar1 = piVar1 + 1;
    }
    aiStack_70[3] = param_3;
    aiStack_70[2] = param_2;
    aiStack_70[1] = param_1;
    aiStack_70[0] = 0xc4f4c;
    NET_SendLoopPacket();
    return;
  }
  if (param_4 == 2) {
    local_1c = (&ip_sockets)[param_1];
  }
  else {
    if (param_4 != 3) {
      pcStack_5c = "NET_SendPacket: bad address type";
      iStack_60 = 0xc4fc5;
      Sys_Error();
      goto LAB_000c4fc8;
    }
    local_1c = (&ip_sockets)[param_1];
  }
  if (local_1c == 0) {
    return;
  }
LAB_000c4fc8:
  puStack_58 = local_18;
  pcStack_5c = (char *)&param_4;
  iStack_60 = 0xc4fd8;
  NetadrToSockadr();
  uStack_54 = 0x10;
  puStack_58 = local_18;
  pcStack_5c = (char *)0x0;
  iStack_60 = param_2;
  aiStack_70[3] = param_3;
  aiStack_70[2] = local_1c;
  aiStack_70[1] = param_1;
  aiStack_70[0] = 0xc4ffb;
  local_8 = NET_SendLong();
  if (local_8 == -1) {
    uStack_50 = 0xc5012;
    piVar1 = __errno_location();
    iVar2 = *piVar1;
    if ((((iVar2 != 0xb) && (iVar2 != 0x6f)) && (iVar2 != 0x68)) &&
       ((iVar2 != 99 || (param_4 != 2)))) {
      if (cls == 0) {
        aiStack_70[2] = 0xc506e;
        aiStack_70[3] = iVar2;
        puStack_58 = (undefined1 *)NET_ErrorString();
        pcStack_5c = "NET_SendPacket ERROR: %s\n";
        iStack_60 = 0xc5082;
        Con_Printf();
      }
      else if ((iVar2 == 99) || (iVar2 == 0x69)) {
        puVar4 = &param_4;
        piVar1 = aiStack_70;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          piVar1 = piVar1 + 1;
        }
        uStack_54 = NET_AdrToString();
        aiStack_70[2] = 0xc50c5;
        aiStack_70[3] = iVar2;
        puStack_58 = (undefined1 *)NET_ErrorString();
        pcStack_5c = "NET_SendPacket Warning: %s : %s\n";
        iStack_60 = 0xc50d9;
        Con_DPrintf();
      }
      else {
        aiStack_70[2] = 0xc50ef;
        aiStack_70[3] = iVar2;
        puStack_58 = (undefined1 *)NET_ErrorString();
        pcStack_5c = "NET_SendPacket ERROR: %s\n";
        iStack_60 = 0xc5103;
        Sys_Error();
      }
    }
  }
  return;
}


// NET_Shutdown  @ 000c5fb4
void NET_Shutdown(void)

{
  NET_ThreadLock();
  NET_ClearLaggedList(g_pLagData);
  NET_ClearLaggedList(0x149888);
  NET_ThreadUnlock();
  NET_Config(0);
  NET_FlushQueues();
  return;
}


// NET_Sleep  @ 000c450c
int NET_Sleep(void)

{
  byte *pbVar1;
  timeval *__timeout;
  int iVar2;
  __fd_mask *p_Var3;
  timeval local_94;
  int local_8c;
  int local_88;
  fd_set local_84;
  
  iVar2 = 0x20;
  p_Var3 = local_84.fds_bits;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    *p_Var3 = 0;
    p_Var3 = p_Var3 + 1;
  }
  local_88 = 0;
  for (local_8c = 0; local_8c < 3; local_8c = local_8c + 1) {
    if (((&ip_sockets)[local_8c] != 0) &&
       (pbVar1 = (byte *)((int)local_84.fds_bits +
                         ((int)((&ip_sockets)[local_8c] & 0x1f) >> 3) +
                         ((uint)(&ip_sockets)[local_8c] >> 5) * 4),
       *pbVar1 = *pbVar1 | '\x01' << ((&ip_sockets)[local_8c] & 7),
       local_88 < (int)(&ip_sockets)[local_8c])) {
      local_88 = (&ip_sockets)[local_8c];
    }
  }
  local_94.tv_sec = 0;
  local_94.tv_usec = 20000;
  if (net_sleepforever == 0) {
    __timeout = &local_94;
  }
  else {
    __timeout = (timeval *)0x0;
  }
  iVar2 = select(local_88 + 1,&local_84,(fd_set *)0x0,(fd_set *)0x0,__timeout);
  return iVar2;
}


// NET_Sleep_Timeout  @ 000c4240
int NET_Sleep_Timeout(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  __fd_mask *p_Var4;
  longdouble lVar5;
  int local_98;
  timeval local_94;
  int local_8c;
  int local_88;
  fd_set local_84;
  
  iVar1 = (int)ROUND((float)sys_ticrate._12_4_);
  lVar5 = (longdouble)Sys_FloatTime();
  iVar3 = (int)ROUND(lVar5);
  if (lasttime_95 == 0) {
    lasttime_95 = iVar3;
  }
  if (1 < iVar3 - lasttime_95) {
    staggerFrames_97 = iVar1 / 100 + 1;
    numFrames_96 = iVar1;
    lasttime_95 = iVar3;
  }
  iVar3 = 0x20;
  p_Var4 = local_84.fds_bits;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    *p_Var4 = 0;
    p_Var4 = p_Var4 + 1;
  }
  local_88 = 0;
  for (local_8c = 0; local_8c < 3; local_8c = local_8c + 1) {
    if (((&ip_sockets)[local_8c] != 0) &&
       (pbVar2 = (byte *)((int)local_84.fds_bits +
                         ((int)((&ip_sockets)[local_8c] & 0x1f) >> 3) +
                         ((uint)(&ip_sockets)[local_8c] >> 5) * 4),
       *pbVar2 = *pbVar2 | '\x01' << ((&ip_sockets)[local_8c] & 7),
       local_88 < (int)(&ip_sockets)[local_8c])) {
      local_88 = (&ip_sockets)[local_8c];
    }
  }
  local_94.tv_sec = 0;
  local_94.tv_usec = (int)(1000 / (longlong)iVar1) * 1000;
  if (local_94.tv_usec < 1) {
    local_94.tv_usec = 1;
  }
  if ((numFrames_96 < 1) || (numFrames_96 % staggerFrames_97 == 0)) {
    local_98 = select(0,(fd_set *)0x0,(fd_set *)0x0,(fd_set *)0x0,&local_94);
  }
  else {
    local_98 = select(local_88 + 1,&local_84,(fd_set *)0x0,(fd_set *)0x0,&local_94);
  }
  numFrames_96 = numFrames_96 + -1;
  return local_98;
}


// NET_StartThread  @ 000c468c
void NET_StartThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized == 0)) {
    net_thread_initialized = 1;
  }
  return;
}


// NET_StopThread  @ 000c46cc
void NET_StopThread(void)

{
  if ((use_thread != 0) && (net_thread_initialized != 0)) {
    net_thread_initialized = 0;
  }
  return;
}


// NET_StringToAdr  @ 000c3320
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


// NET_StringToSockaddr  @ 000c31d4
undefined4 NET_StringToSockaddr(undefined4 param_1,undefined2 *param_2)

{
  uint16_t uVar1;
  int iVar2;
  in_addr_t iVar3;
  hostent *phVar4;
  char local_90 [127];
  undefined1 local_11;
  char *local_c;
  
  Q_memset(param_2,0,0x10);
  *param_2 = 2;
  param_2[1] = 0;
  Q_strncpy(local_90,param_1,0x7f);
  local_11 = 0;
  for (local_c = local_90; *local_c != '\0'; local_c = local_c + 1) {
    if (*local_c == ':') {
      *local_c = '\0';
      iVar2 = atoi(local_c + 1);
      uVar1 = htons((uint16_t)iVar2);
      param_2[1] = uVar1;
    }
  }
  if (((local_90[0] < '0') || ('9' < local_90[0])) ||
     (iVar2 = Q_strstr(local_90,&DAT_000ed4b0), iVar2 == 0)) {
    phVar4 = gethostbyname(local_90);
    if (phVar4 == (hostent *)0x0) {
      return 0;
    }
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)*phVar4->h_addr_list;
  }
  else {
    iVar3 = inet_addr(local_90);
    *(in_addr_t *)(param_2 + 2) = iVar3;
  }
  return 1;
}


// NET_ThreadLock  @ 000c2dc0
void NET_ThreadLock(void)

{
  return;
}


// NET_ThreadUnlock  @ 000c2dc8
void NET_ThreadUnlock(void)

{
  return;
}


// NET_TransferRawData  @ 000c3400
void NET_TransferRawData(int param_1,undefined4 param_2,undefined4 param_3)

{
  Q_memcpy(*(undefined4 *)(param_1 + 8),param_2,param_3,0xc340c);
  *(undefined4 *)(param_1 + 0x10) = param_3;
  return;
}


