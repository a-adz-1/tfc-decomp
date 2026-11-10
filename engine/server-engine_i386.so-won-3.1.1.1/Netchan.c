// Netchan_AddBufferToList  @ 00081e9c
void Netchan_AddBufferToList(int *param_1,int *param_2)

{
  int *local_8;
  
  *param_2 = 0;
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      *param_2 = *param_1;
      *param_1 = (int)param_2;
    }
    else {
      for (local_8 = (int *)*param_1; *local_8 != 0; local_8 = (int *)*local_8) {
        if ((param_2[1] >> 0x10 & 0xffffU) < (((int *)*local_8)[1] >> 0x10 & 0xffffU)) {
          *param_2 = *(int *)*local_8;
          *local_8 = (int)param_2;
          return;
        }
      }
      *local_8 = (int)param_2;
    }
  }
  return;
}


// Netchan_AddFragbufToTail  @ 00081fc4
void Netchan_AddFragbufToTail(int param_1,undefined4 *param_2)

{
  undefined4 local_8;
  
  *param_2 = 0;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 **)(param_1 + 8) = param_2;
  }
  else {
    for (local_8 = *(int **)(param_1 + 8); *local_8 != 0; local_8 = (int *)*local_8) {
    }
    *local_8 = (int)param_2;
  }
  return;
}


// Netchan_AllocFragbuf  @ 00081f4c
undefined4 * Netchan_AllocFragbuf(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)Mem_ZeroMalloc(0x6a8);
  puVar1[1] = 0;
  puVar1[6] = 0;
  puVar1[4] = puVar1 + 7;
  puVar1[5] = 0x578;
  puVar1[2] = "Frag Buffer Alloc\'d";
  *puVar1 = 0;
  return puVar1;
}


// Netchan_CanPacket  @ 0008040c
undefined4 Netchan_CanPacket(int param_1)

{
  double dVar1;
  undefined4 uVar2;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)net_chokeloopback._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)net_chokeloopback._12_4_ == 0.0) << 0xe) >> 8)) == 0x40
      ) && (*(int *)(param_1 + 4) == 1)) {
    *(double *)(param_1 + 0x2c) = realtime;
    uVar2 = 1;
  }
  else {
    dVar1 = *(double *)(param_1 + 0x2c);
    if ((byte)(dVar1 < realtime | (byte)((ushort)((ushort)(NAN(dVar1) || NAN(realtime)) << 10) >> 8)
              | (byte)((ushort)((ushort)(dVar1 == realtime) << 0xe) >> 8)) == 1) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


// Netchan_CheckForCompletion  @ 000812ec
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Netchan_CheckForCompletion(undefined *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_6c [4];
  char local_34 [32];
  undefined4 *local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = 0;
  local_14 = *(undefined4 **)(param_1 + param_2 * 4 + 0x1fd0);
  if (local_14 != (undefined4 *)0x0) {
    for (; local_14 != (undefined4 *)0x0; local_14 = (undefined4 *)*local_14) {
      local_c = local_c + local_14[6];
      local_8 = local_8 + 1;
      local_10 = (int)local_14[1] >> 0x10 & 0xffff;
      if ((local_10 != local_8) && (param_1 == &DAT_002f9fa4)) {
        if (_DAT_002f9fa4 == 2) {
          puVar2 = (undefined4 *)&DAT_002f9fa4;
          puVar3 = auStackY_6c;
          for (iVar1 = 5; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *puVar2;
            puVar3 = puVar3 + 1;
          }
          NET_AdrToString();
          auStackY_6c[3] = 0x813ba;
          snprintf(local_34,0x20,"listen %s\n");
          auStackY_6c[3] = 0x813c9;
          Cbuf_AddText();
          return;
        }
        auStackY_6c[3] = 0x813e1;
        Con_Printf();
        auStackY_6c[3] = 0x813f5;
        Cbuf_AddText();
      }
    }
    if (local_8 == param_3) {
      *(undefined4 *)(param_1 + param_2 * 4 + 0x1fd8) = 1;
    }
  }
  return;
}


// Netchan_Clear  @ 000801f8
void Netchan_Clear(int param_1)

{
  undefined4 local_8;
  
  Netchan_ClearFragments(param_1);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x1004) = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    *(undefined4 *)(local_8 * 4 + param_1 + 0x1fb0) = 0;
    *(undefined4 *)(local_8 * 4 + param_1 + 0x1fa8) = 0;
    *(undefined4 *)(local_8 * 4 + param_1 + 0x1fc0) = 0;
    *(undefined2 *)(local_8 * 2 + param_1 + 0x1fc8) = 0;
    *(undefined2 *)(local_8 * 2 + param_1 + 0x1fcc) = 0;
    *(undefined4 *)(local_8 * 4 + param_1 + 0x1fd8) = 0;
  }
  if (*(int *)(param_1 + 0x20e4) != 0) {
    Mem_Free(*(undefined4 *)(param_1 + 0x20e4));
    *(undefined4 *)(param_1 + 0x20e4) = 0;
  }
  *(undefined4 *)(param_1 + 0x20e8) = 0;
  return;
}


// Netchan_ClearFragbufs  @ 000800b8
void Netchan_ClearFragbufs(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  if (param_1 != (undefined4 *)0x0) {
    local_8 = (undefined4 *)*param_1;
    while (local_8 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_8;
      Mem_Free(local_8);
      local_8 = puVar1;
    }
    *param_1 = 0;
  }
  return;
}


// Netchan_ClearFragments  @ 00080114
void Netchan_ClearFragments(int param_1)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    local_c = *(undefined4 **)(local_8 * 4 + param_1 + 0x1fa0);
    while (local_c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_c;
      Netchan_ClearFragbufs(local_c + 2);
      Mem_Free(local_c);
      local_c = puVar1;
    }
    *(undefined4 *)(local_8 * 4 + param_1 + 0x1fa0) = 0;
    Netchan_ClearFragbufs(local_8 * 4 + 0x1fb8 + param_1);
    Netchan_FlushIncoming(param_1,local_8);
  }
  return;
}


// Netchan_CopyFileFragments  @ 00082838
undefined4 Netchan_CopyFileFragments(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int local_120;
  int local_114;
  undefined4 *local_10c;
  char local_108 [259];
  undefined1 local_5;
  
  if (*(int *)(param_1 + 0x1fdc) == 0) {
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x1fd4) == 0) {
    Con_Printf("Netchan_CopyFileFragments:  Called with no fragments readied\n");
    *(undefined4 *)(param_1 + 0x1fdc) = 0;
    uVar2 = 0;
  }
  else {
    local_10c = *(undefined4 **)(param_1 + 0x1fd4);
    SZ_Clear(&net_message);
    MSG_BeginReading();
    SZ_Write(&net_message,local_10c[4],local_10c[6]);
    uVar2 = MSG_ReadString(0x103);
    Q_strncpy(local_108,uVar2);
    local_5 = 0;
    iVar3 = Q_strlen(local_108);
    if (iVar3 < 1) {
      Con_Printf("File fragment received with no filename\nFlushing input queue\n");
      Netchan_FlushIncoming(param_1,1);
      uVar2 = 0;
    }
    else {
      iVar3 = Q_strstr(local_108,&DAT_000e55de);
      if (iVar3 == 0) {
        Q_strncpy(param_1 + 0x1fe0,local_108,0x103);
        *(undefined1 *)(param_1 + 0x20e3) = 0;
        if (local_108[0] != '!') {
          iVar3 = FS_Open(local_108,&DAT_000e528f);
          if (iVar3 != 0) {
            Con_Printf("Can\'t download %s, already exists\n",local_108);
            Netchan_FlushIncoming(param_1,1);
            FS_Close(iVar3);
            return 1;
          }
          COM_CreatePath(local_108);
        }
        local_114 = 0;
        for (; local_10c != (undefined4 *)0x0; local_10c = (undefined4 *)*local_10c) {
          local_114 = local_114 + local_10c[6];
          if (local_10c == *(undefined4 **)(param_1 + 0x1fd4)) {
            local_114 = local_114 - msg_readcount;
          }
        }
        iVar3 = Mem_ZeroMalloc(local_114 + 1);
        if (iVar3 == 0) {
          Con_Printf("Buffer allocation failed on %i bytes\n",local_114 + 1);
          Netchan_FlushIncoming(param_1,1);
          uVar2 = 0;
        }
        else {
          local_120 = 0;
          local_10c = *(undefined4 **)(param_1 + 0x1fd4);
          while (local_10c != (undefined4 *)0x0) {
            puVar1 = (undefined4 *)*local_10c;
            if (local_10c == *(undefined4 **)(param_1 + 0x1fd4)) {
              local_10c[6] = local_10c[6] - msg_readcount;
              Q_memcpy(iVar3 + local_120,local_10c[4] + msg_readcount,local_10c[6]);
            }
            else {
              Q_memcpy(iVar3 + local_120,local_10c[4],local_10c[6]);
            }
            local_120 = local_120 + local_10c[6];
            Mem_Free(local_10c);
            local_10c = puVar1;
          }
          if (local_108[0] == '!') {
            if (*(int *)(param_1 + 0x20e4) != 0) {
              Con_DPrintf("Netchan_CopyFragments:  Freeing holdover tempbuffer\n");
              Mem_Free(*(undefined4 *)(param_1 + 0x20e4));
            }
            *(int *)(param_1 + 0x20e4) = iVar3;
            *(int *)(param_1 + 0x20e8) = local_120;
          }
          else {
            COM_WriteFile(local_108,iVar3,local_120);
            Mem_Free(iVar3);
          }
          SZ_Clear(&net_message);
          msg_readcount = 0;
          *(undefined4 *)(param_1 + 0x1fd4) = 0;
          *(undefined4 *)(param_1 + 0x1fdc) = 0;
          uVar2 = 1;
        }
      }
      else {
        Con_Printf("File fragment received with relative path, ignoring\n");
        Netchan_FlushIncoming(param_1,1);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


// Netchan_CopyNormalFragments  @ 0008273c
undefined4 Netchan_CopyNormalFragments(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_8;
  
  if (*(int *)(param_1 + 0x1fd8) == 0) {
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x1fd0) == 0) {
    Con_Printf("Netchan_CopyNormalFragments:  Called with no fragments readied\n");
    *(undefined4 *)(param_1 + 0x1fd8) = 0;
    uVar2 = 0;
  }
  else {
    local_8 = *(undefined4 **)(param_1 + 0x1fd0);
    SZ_Clear(&net_message);
    MSG_BeginReading();
    while (local_8 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_8;
      SZ_Write(&net_message,local_8[4],local_8[6]);
      Mem_Free(local_8);
      local_8 = puVar1;
    }
    *(undefined4 *)(param_1 + 0x1fd0) = 0;
    *(undefined4 *)(param_1 + 0x1fd8) = 0;
    uVar2 = 1;
  }
  return uVar2;
}


// Netchan_CreateFileFragments  @ 00082424
undefined4 Netchan_CreateFileFragments(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *local_30;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_1c = 1;
  bVar1 = true;
  iVar2 = (**(code **)(param_2 + 0x54))(*(undefined4 *)(param_2 + 0x50));
  iVar3 = FS_Open(param_3,&DAT_000e528f);
  if (iVar3 == 0) {
    Con_Printf("Warning:  Unable to open %s for transfer\n",param_3);
    uVar4 = 0;
  }
  else {
    local_14 = FS_Size(iVar3);
    FS_Close(iVar3);
    iVar3 = Mem_ZeroMalloc(0xc);
    local_18 = 0;
    while (0 < local_14) {
      local_10 = iVar2;
      if (local_14 < iVar2) {
        local_10 = local_14;
      }
      iVar5 = Netchan_AllocFragbuf();
      if (iVar5 == 0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(iVar3);
        if (param_1 == 0) {
          CL_Disconnect_f();
        }
        else {
          SV_DropClient(host_client,0,"Malloc problem");
        }
        return 0;
      }
      *(int *)(iVar5 + 4) = local_1c;
      local_1c = local_1c + 1;
      SZ_Clear(iVar5 + 8);
      if (bVar1) {
        bVar1 = false;
        MSG_WriteString(iVar5 + 8,param_3);
        local_10 = local_10 - *(int *)(iVar5 + 0x18);
      }
      *(undefined4 *)(iVar5 + 0x594) = 1;
      *(int *)(iVar5 + 0x6a4) = local_10;
      *(int *)(iVar5 + 0x6a0) = local_18;
      Q_strncpy(iVar5 + 0x59c,param_3,0x103);
      *(undefined1 *)(iVar5 + 0x69f) = 0;
      local_18 = local_18 + local_10;
      local_14 = local_14 - local_10;
      Netchan_AddFragbufToTail(iVar3,iVar5);
    }
    if (*(int *)(param_2 + 0x1fa4) == 0) {
      *(int *)(param_2 + 0x1fa4) = iVar3;
    }
    else {
      for (local_30 = *(int **)(param_2 + 0x1fa4); *local_30 != 0; local_30 = (int *)*local_30) {
      }
      *local_30 = iVar3;
    }
    uVar4 = 1;
  }
  return uVar4;
}


// Netchan_CreateFileFragmentsFromBuffer  @ 00082224
void Netchan_CreateFileFragmentsFromBuffer
               (int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_2c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_1c = 1;
  bVar1 = true;
  if (param_5 != 0) {
    iVar2 = (**(code **)(param_2 + 0x54))(*(undefined4 *)(param_2 + 0x50));
    iVar3 = Mem_ZeroMalloc(0xc);
    local_14 = param_5;
    local_18 = 0;
    while (0 < local_14) {
      local_10 = iVar2;
      if (local_14 < iVar2) {
        local_10 = local_14;
      }
      iVar4 = Netchan_AllocFragbuf();
      if (iVar4 == 0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(iVar3);
        if (param_1 != 0) {
          SV_DropClient(host_client,0,"Malloc problem");
          return;
        }
        CL_Disconnect_f();
        return;
      }
      *(int *)(iVar4 + 4) = local_1c;
      local_1c = local_1c + 1;
      SZ_Clear(iVar4 + 8);
      if (bVar1) {
        bVar1 = false;
        MSG_WriteString(iVar4 + 8,param_3);
        local_10 = local_10 - *(int *)(iVar4 + 0x18);
      }
      *(undefined4 *)(iVar4 + 0x598) = 1;
      *(undefined4 *)(iVar4 + 0x594) = 1;
      *(int *)(iVar4 + 0x6a4) = local_10;
      *(int *)(iVar4 + 0x6a0) = local_18;
      MSG_WriteBuf(iVar4 + 8,local_10,param_4 + local_18);
      local_18 = local_18 + local_10;
      local_14 = local_14 - local_10;
      Netchan_AddFragbufToTail(iVar3,iVar4);
    }
    if (*(int *)(param_2 + 0x1fa4) == 0) {
      *(int *)(param_2 + 0x1fa4) = iVar3;
    }
    else {
      for (local_2c = *(int **)(param_2 + 0x1fa4); *local_2c != 0; local_2c = (int *)*local_2c) {
      }
      *local_2c = iVar3;
    }
  }
  return;
}


// Netchan_CreateFragments  @ 000821c4
void Netchan_CreateFragments(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x821d0;
  if (0 < *(int *)(param_2 + 0x68)) {
    Netchan_CreateFragments_(param_1,param_2,param_2 + 0x58,0x821d0);
    *(undefined4 *)(param_2 + 0x68) = 0;
  }
  Netchan_CreateFragments_(param_1,param_2,param_3,uVar1);
  return;
}


// Netchan_CreateFragments_  @ 00082020
void Netchan_CreateFragments_(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_24;
  int local_1c;
  int local_18;
  int local_14;
  
  local_1c = 1;
  if (*(int *)(param_3 + 0x10) != 0) {
    iVar1 = (**(code **)(param_2 + 0x54))(*(undefined4 *)(param_2 + 0x50));
    iVar2 = Mem_ZeroMalloc(0xc);
    local_14 = *(int *)(param_3 + 0x10);
    local_18 = 0;
    while (0 < local_14) {
      iVar3 = iVar1;
      if (local_14 < iVar1) {
        iVar3 = local_14;
      }
      local_14 = local_14 - iVar3;
      iVar4 = Netchan_AllocFragbuf();
      if (iVar4 == 0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(iVar2);
        if (param_1 != 0) {
          SV_DropClient(host_client,0,"Malloc problem");
          return;
        }
        CL_Disconnect_f();
        return;
      }
      *(int *)(iVar4 + 4) = local_1c;
      local_1c = local_1c + 1;
      SZ_Clear(iVar4 + 8);
      SZ_Write(iVar4 + 8,local_18 + *(int *)(param_3 + 8),iVar3);
      local_18 = local_18 + iVar3;
      Netchan_AddFragbufToTail(iVar2,iVar4);
    }
    if (*(int *)(param_2 + 0x1fa0) == 0) {
      *(int *)(param_2 + 0x1fa0) = iVar2;
    }
    else {
      for (local_24 = *(int **)(param_2 + 0x1fa0); *local_24 != 0; local_24 = (int *)*local_24) {
      }
      *local_24 = iVar2;
    }
  }
  return;
}


// Netchan_FindBufferById  @ 00081220
undefined4 * Netchan_FindBufferById(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)*param_1;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      if (param_3 == 0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)Mem_ZeroMalloc(0x6a8);
        puVar1[1] = param_2;
        puVar1[6] = 0;
        puVar1[4] = puVar1 + 7;
        puVar1[5] = 0x578;
        puVar1[2] = "Frag Buffer";
        *(undefined2 *)(puVar1 + 3) = 1;
        Netchan_AddBufferToList(param_1,puVar1);
      }
      return puVar1;
    }
    if (local_8[1] == param_2) break;
    local_8 = (undefined4 *)*local_8;
  }
  return local_8;
}


// Netchan_FlushIncoming  @ 00082684
void Netchan_FlushIncoming(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  SZ_Clear(&net_message);
  msg_readcount = 0;
  local_8 = *(undefined4 **)(param_2 * 4 + param_1 + 0x1fd0);
  while (local_8 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_8;
    Mem_Free(local_8);
    local_8 = puVar1;
  }
  *(undefined4 *)(param_2 * 4 + param_1 + 0x1fd0) = 0;
  *(undefined4 *)(param_2 * 4 + param_1 + 0x1fd8) = 0;
  return;
}


// Netchan_FragSend  @ 00081d74
void Netchan_FragSend(int param_1)

{
  undefined4 *puVar1;
  int local_c;
  
  if (param_1 != 0) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      if ((*(int *)(local_c * 4 + param_1 + 0x1fb8) == 0) &&
         (*(int *)(local_c * 4 + param_1 + 0x1fa0) != 0)) {
        puVar1 = *(undefined4 **)(local_c * 4 + param_1 + 0x1fa0);
        *(undefined4 *)(local_c * 4 + param_1 + 0x1fa0) =
             **(undefined4 **)(local_c * 4 + param_1 + 0x1fa0);
        *puVar1 = 0;
        *(undefined4 *)(local_c * 4 + param_1 + 0x1fb8) = puVar1[2];
        *(undefined4 *)(local_c * 4 + param_1 + 0x1fc0) = puVar1[1];
        Mem_Free(puVar1);
      }
    }
  }
  return;
}


// Netchan_IncomingReady  @ 00082d8c
undefined4 Netchan_IncomingReady(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (1 < local_8) {
      return 0;
    }
    if (*(int *)(local_8 * 4 + param_1 + 0x1fd8) != 0) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


// Netchan_Init  @ 00083074
void Netchan_Init(void)

{
  Cvar_RegisterVariable(net_log);
  Cvar_RegisterVariable(net_showpackets);
  Cvar_RegisterVariable(net_showdrop);
  Cvar_RegisterVariable(net_chokeloopback);
  Cvar_RegisterVariable(net_drawslider);
  return;
}


// Netchan_IsReceiving  @ 00082d40
undefined4 Netchan_IsReceiving(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (1 < local_8) {
      return 0;
    }
    if (*(int *)(local_8 * 4 + param_1 + 0x1fd0) != 0) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


// Netchan_IsSending  @ 00082cf4
undefined4 Netchan_IsSending(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (1 < local_8) {
      return 0;
    }
    if (*(int *)(local_8 * 4 + param_1 + 0x1fb8) != 0) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


// Netchan_OutOfBand  @ 0007ff8c
void Netchan_OutOfBand(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 **ppuVar3;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 *apuStack_1010 [4];
  undefined4 uStack_1000;
  undefined1 local_fe0 [4040];
  char *local_18;
  undefined2 local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uStack_1000 = 0x7ff9d;
  local_18 = "Netchan_OutOfBand";
  local_10 = local_fe0;
  local_c = 0xfc5;
  local_8 = 0;
  local_14 = 1;
  apuStack_1010[2] = (undefined4 *)0xffffffff;
  apuStack_1010[1] = &local_18;
  apuStack_1010[0] = (undefined4 *)0x7ffda;
  MSG_WriteLong();
  apuStack_1010[3] = (undefined4 *)in_stack_0000001c;
  apuStack_1010[2] = (undefined4 *)in_stack_00000020;
  apuStack_1010[1] = &local_18;
  apuStack_1010[0] = (undefined4 *)0x7fff1;
  SZ_Write();
  if (DAT_002fe004 == 0) {
    puVar2 = (undefined4 *)&stack0x00000008;
    ppuVar3 = apuStack_1010;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = (undefined4 *)*puVar2;
      puVar2 = puVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    NET_SendPacket(param_1,local_8,local_10);
  }
  return;
}


// Netchan_OutOfBandPrint  @ 00080034
void Netchan_OutOfBandPrint(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 **ppuVar3;
  char *in_stack_0000001c;
  undefined1 *apuStack_38 [3];
  
  apuStack_38[2] = (undefined1 *)0x8006a;
  vsnprintf(string_9,0x2000,in_stack_0000001c,&stack0x00000020);
  apuStack_38[2] = string_9;
  apuStack_38[1] = (undefined1 *)0x80087;
  Q_strlen();
  puVar2 = (undefined4 *)&stack0x00000008;
  ppuVar3 = apuStack_38;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar3 = (undefined1 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  }
  Netchan_OutOfBand(param_1);
  return;
}


// Netchan_Process  @ 00081554
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Netchan_Process(char *param_1)

{
  double dVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char **ppcVar9;
  char *apcStack_cc [9];
  uint *puStack_a8;
  undefined8 local_a4;
  undefined1 *local_5c;
  undefined1 *local_58;
  int local_54;
  uint local_38 [8];
  uint *local_18;
  uint local_14;
  uint *local_10;
  uint *local_c;
  int local_8;
  
  local_a4 = (double)CONCAT44(0x81565,(uint)local_a4);
  local_38[6] = 0;
  local_38[7] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  if ((DAT_002fe004 == 0) && (DAT_002fe32c == 0)) {
    ppcVar9 = apcStack_cc + 5;
    pcVar7 = param_1;
    for (iVar5 = 5; pcVar7 = pcVar7 + 4, iVar5 != 0; iVar5 = iVar5 + -1) {
      *ppcVar9 = (char *)*(undefined4 *)pcVar7;
      ppcVar9 = ppcVar9 + 1;
    }
    puVar8 = &net_from;
    ppcVar9 = apcStack_cc;
    for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
      *ppcVar9 = (char *)*puVar8;
      puVar8 = puVar8 + 1;
      ppcVar9 = ppcVar9 + 1;
    }
    iVar5 = NET_CompareAdr();
    if (iVar5 == 0) {
      return 0;
    }
  }
  *(float *)(param_1 + 0x1c) = (float)realtime;
  local_a4 = (double)CONCAT44(0x81617,(uint)local_a4);
  MSG_BeginReading();
  local_a4 = (double)CONCAT44(0x8161c,(uint)local_a4);
  local_c = (uint *)MSG_ReadLong();
  local_a4 = (double)CONCAT44(0x81624,(uint)local_a4);
  local_10 = (uint *)MSG_ReadLong();
  if ((((uint)local_10 & 0x40000000) == 0) || (_DAT_0011989c != (code *)0x0)) {
    if (_DAT_0011989c != (code *)0x0) {
      puStack_a8 = &net_message;
      apcStack_cc[8] = param_1;
      apcStack_cc[7] = (char *)0x8166f;
      iVar5 = (*_DAT_0011989c)();
      if (iVar5 == 0) {
        return 0;
      }
    }
    local_a4 = (double)(CONCAT44(local_a4._4_4_,local_c) & 0xffffffff000000ff);
    puStack_a8 = DAT_0059d8d0 + -2;
    apcStack_cc[8] = (char *)(DAT_0059d8c8 + 8);
    apcStack_cc[7] = (char *)0x816ab;
    COM_UnMunge2();
    local_18 = (uint *)((uint)local_c >> 0x1f);
    local_14 = (uint)local_10 >> 0x1f;
    uVar6 = (uint)local_c >> 0x1e & 1;
    if (uVar6 != 0) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        local_a4 = (double)CONCAT44(0x816ed,(uint)local_a4);
        iVar5 = MSG_ReadByte();
        if (iVar5 != 0) {
          local_38[local_8 + 4] = 1;
          local_a4 = (double)CONCAT44(0x8170e,(uint)local_a4);
          uVar4 = MSG_ReadLong();
          local_38[local_8 + 6] = uVar4;
          local_a4 = (double)CONCAT44(0x81727,(uint)local_a4);
          uVar4 = MSG_ReadShort();
          local_38[local_8 + 2] = uVar4;
          local_a4 = (double)CONCAT44(0x81740,(uint)local_a4);
          uVar4 = MSG_ReadShort();
          local_38[local_8] = uVar4;
        }
      }
      apcStack_cc[8] = (char *)local_38;
      apcStack_cc[7] = (char *)(local_38 + 2);
      apcStack_cc[6] = (char *)(local_38 + 6);
      apcStack_cc[5] = (char *)(local_38 + 4);
      apcStack_cc[4] = param_1;
      apcStack_cc[3] = (char *)0x81778;
      iVar5 = Netchan_Validate();
      if (iVar5 == 0) {
        return 0;
      }
    }
    local_c = (uint *)((uint)local_c & 0x3fffffff);
    local_10 = (uint *)((uint)local_10 & 0x3fffffff);
    if (((byte)(0.0 < (float)net_showpackets._12_4_ |
                (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
        ) && ((byte)(3.0 < (float)net_showpackets._12_4_ |
                     (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 3.0) << 0xe) >> 8)) !=
              0x40)) {
      if (param_1 == &DAT_002f9fa4) {
        cVar2 = 'c';
        dVar1 = (double)cl._176020_8_;
      }
      else {
        cVar2 = 's';
        dVar1 = DAT_0036bc6c;
      }
      local_a4 = (double)(float)dVar1;
      puStack_a8 = local_18;
      apcStack_cc[8] = (char *)local_10;
      apcStack_cc[7] = (char *)local_c;
      apcStack_cc[6] = (char *)DAT_0059d8d0;
      apcStack_cc[5] = (char *)(int)cVar2;
      apcStack_cc[4] = " %c <-- sz=%i seq=%i ack=%i rel=%i tm=%f\n";
      apcStack_cc[3] = (char *)0x8184a;
      Con_Printf();
    }
    if (*(uint **)(param_1 + 0x34) < local_c) {
      net_drop = (int)local_c + (-1 - *(int *)(param_1 + 0x34));
      if ((0 < net_drop) &&
         ((byte)(0.0 < (float)net_showdrop._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)net_showdrop._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)net_showdrop._12_4_ == 0.0) << 0xe) >> 8)) != 0x40))
      {
        local_a4 = (double)CONCAT44(local_c,(int)local_c + (-1 - *(int *)(param_1 + 0x34)));
        ppcVar9 = apcStack_cc + 2;
        pcVar7 = param_1;
        for (iVar5 = 5; pcVar7 = pcVar7 + 4, iVar5 != 0; iVar5 = iVar5 + -1) {
          *ppcVar9 = (char *)*(undefined4 *)pcVar7;
          ppcVar9 = ppcVar9 + 1;
        }
        apcStack_cc[1] = (char *)0x81968;
        puStack_a8 = (uint *)NET_AdrToString();
        apcStack_cc[8] = "%s:Dropped %i packets at %i\n";
        apcStack_cc[7] = (char *)0x8197c;
        Con_Printf();
      }
      if ((local_14 == *(uint *)(param_1 + 0x48)) &&
         (*(int *)(param_1 + 0x4c) <= *(int *)(param_1 + 0x38) + 1)) {
        param_1[0x1004] = '\0';
        param_1[0x1005] = '\0';
        param_1[0x1006] = '\0';
        param_1[0x1007] = '\0';
      }
      *(uint **)(param_1 + 0x34) = local_c;
      *(uint **)(param_1 + 0x38) = local_10;
      *(uint *)(param_1 + 0x3c) = local_14;
      if (local_18 != (uint *)0x0) {
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ 1;
      }
      *(uint **)(param_1 + ((*(uint *)(param_1 + 0x2400) & 0x1f) * 3 + 0x8a0) * 4) =
           DAT_0059d8d0 + 7;
      *(double *)(param_1 + ((*(uint *)(param_1 + 0x2400) & 0x1f) * 3 + 0x8a1) * 4) = realtime;
      *(int *)(param_1 + 0x2400) = *(int *)(param_1 + 0x2400) + 1;
      apcStack_cc[8] = param_1;
      apcStack_cc[7] = (char *)0x81a46;
      Netchan_UpdateFlow();
      if (uVar6 != 0) {
        for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
          if (local_38[local_8 + 4] != 0) {
            uVar6 = local_38[local_8 + 6];
            uVar4 = local_38[local_8 + 6];
            if (local_38[local_8 + 6] != 0) {
              local_a4._0_4_ = 1;
              puStack_a8 = (uint *)local_38[local_8 + 6];
              apcStack_cc[8] = param_1 + (local_8 + 0x7f4) * 4;
              apcStack_cc[7] = (char *)0x81b0d;
              iVar5 = Netchan_FindBufferById();
              if (iVar5 == 0) {
                apcStack_cc[8] = "Netchan_Process:  Couldn\'t allocate or find buffer %i\n";
                apcStack_cc[7] = (char *)0x81bd5;
                puStack_a8 = (uint *)(uVar6 >> 0x10);
                Con_Printf();
              }
              else {
                uVar6 = local_38[local_8];
                apcStack_cc[8] = (char *)(iVar5 + 8);
                apcStack_cc[7] = (char *)0x81b43;
                SZ_Clear();
                puStack_a8 = (uint *)(DAT_0059d8c8 + msg_readcount + local_38[local_8 + 2]);
                apcStack_cc[8] = (char *)(iVar5 + 8);
                apcStack_cc[7] = (char *)0x81b82;
                local_a4._0_4_ = uVar6;
                SZ_Write();
                if ((*(ushort *)(iVar5 + 0xc) & 2) != 0) {
                  if (param_1 != &DAT_002f9fa4) {
                    *(ushort *)(param_1 + 0x5c) = *(ushort *)(param_1 + 0x5c) | 2;
                  }
                  return 0;
                }
              }
              local_a4 = (double)(CONCAT44(local_a4._4_4_,uVar4) & 0xffffffff0000ffff);
              puStack_a8 = (uint *)local_8;
              apcStack_cc[8] = param_1;
              apcStack_cc[7] = (char *)0x81bec;
              Netchan_CheckForCompletion();
            }
            local_58 = (undefined1 *)
                       (DAT_0059d8c8 + msg_readcount + local_38[local_8 + 2] + local_38[local_8]);
            local_5c = (undefined1 *)(DAT_0059d8c8 + msg_readcount + local_38[local_8 + 2]);
            iVar5 = (int)DAT_0059d8d0 +
                    ((-local_38[local_8 + 2] - local_38[local_8]) - msg_readcount);
            for (local_54 = 0; local_54 < iVar5; local_54 = local_54 + 1) {
              *local_5c = *local_58;
              local_58 = local_58 + 1;
              local_5c = local_5c + 1;
            }
            DAT_0059d8d0 = (uint *)((int)DAT_0059d8d0 - local_38[local_8]);
            iVar5 = local_8;
            while (local_54 = iVar5 + 1, local_54 < 2) {
              local_38[iVar5 + 3] = local_38[iVar5 + 3] - local_38[local_8];
              iVar5 = local_54;
            }
          }
        }
        if ((int)DAT_0059d8d0 < 0x11) {
          return 0;
        }
      }
      uVar3 = 1;
    }
    else {
      if ((byte)(0.0 < (float)net_showdrop._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)net_showdrop._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)net_showdrop._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
      {
        if (local_c == *(uint **)(param_1 + 0x34)) {
          local_a4 = (double)CONCAT44(*(undefined4 *)(param_1 + 0x34),local_c);
          ppcVar9 = apcStack_cc + 2;
          for (iVar5 = 5; param_1 = param_1 + 4, iVar5 != 0; iVar5 = iVar5 + -1) {
            *ppcVar9 = (char *)*(undefined4 *)param_1;
            ppcVar9 = ppcVar9 + 1;
          }
          apcStack_cc[1] = (char *)0x818a8;
          puStack_a8 = (uint *)NET_AdrToString();
          apcStack_cc[8] = "%s:duplicate packet %i at %i\n";
          apcStack_cc[7] = (char *)0x818bc;
          Con_Printf();
        }
        else {
          local_a4 = (double)CONCAT44(*(undefined4 *)(param_1 + 0x34),local_c);
          ppcVar9 = apcStack_cc + 2;
          for (iVar5 = 5; param_1 = param_1 + 4, iVar5 != 0; iVar5 = iVar5 + -1) {
            *ppcVar9 = (char *)*(undefined4 *)param_1;
            ppcVar9 = ppcVar9 + 1;
          }
          apcStack_cc[1] = (char *)0x818ea;
          puStack_a8 = (uint *)NET_AdrToString();
          apcStack_cc[8] = "%s:out of order packet %i at %i\n";
          apcStack_cc[7] = (char *)0x818fe;
          Con_Printf();
        }
      }
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// Netchan_Setup  @ 00080334
void Netchan_Setup(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  
  Netchan_Clear(param_2);
  Q_memset(param_2,0,0x2414);
  param_2[6] = in_stack_00000020 + 1;
  *param_2 = param_1;
  puVar2 = (undefined4 *)&stack0x0000000c;
  puVar3 = param_2;
  for (iVar1 = 5; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  param_2[7] = (float)realtime;
  param_2[8] = (float)realtime;
  param_2[0x18] = param_2 + 0x1b;
  *(undefined2 *)(param_2 + 0x17) = 1;
  param_2[0x19] = 0xf96;
  param_2[0x16] = "netchan->message";
  *(undefined8 *)(param_2 + 9) = 0x40c3878000000000;
  param_2[0x11] = 1;
  param_2[0x14] = in_stack_00000024;
  param_2[0x15] = in_stack_00000028;
  return;
}


// Netchan_Transmit  @ 00080638
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Netchan_Transmit(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  double dVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  bool bVar7;
  int aiStack_1094 [2];
  char *pcStack_108c;
  int iStack_1088;
  undefined1 *puStack_1084;
  int iStack_1080;
  char **ppcStack_107c;
  char **ppcStack_1078;
  undefined8 local_1074;
  int local_1020;
  int local_101c;
  int local_1014 [4];
  float local_1004;
  int local_1000;
  int local_ffc;
  undefined4 *local_ff8;
  uint local_ff4;
  int local_ff0;
  int local_fec;
  int local_fe8;
  int local_fe4;
  undefined1 local_fe0 [4040];
  char *local_18;
  undefined2 local_14;
  undefined1 *local_10;
  int local_c;
  int local_8;
  
  local_1074._4_4_ = 0x80649;
  local_fec = 0;
  local_18 = "Netchan_Transmit";
  local_10 = local_fe0;
  local_c = 0xfc5;
  local_8 = 0;
  local_14 = 0;
  if ((*(ushort *)(param_1 + 0x17) & 2) == 0) {
    local_fe4 = 0;
    if (((int)param_1[0x13] < (int)param_1[0xe]) && (param_1[0xf] != param_1[0x12])) {
      local_fe4 = 1;
      local_fec = 1;
    }
    if (param_1[0x401] == 0) {
      local_1014[3] = 0;
      local_1014[0] = 0;
      local_1014[1] = 0;
      ppcStack_107c = (char **)param_1;
      iStack_1080 = 0x8074a;
      Netchan_FragSend();
      bVar7 = param_1[0x1a] != 0;
      for (local_ffc = 0; local_ffc < 2; local_ffc = local_ffc + 1) {
        if (param_1[local_ffc + 0x7ee] != 0) {
          local_1014[local_ffc] = 1;
        }
      }
      if (((bVar7) && (local_1014[0] != 0)) && (bVar7 = false, 0x4b0 < (int)param_1[0x1a])) {
        local_1074._0_4_ = param_1 + 0x16;
        ppcStack_1078 = (char **)param_1;
        ppcStack_107c = (char **)(uint)(param_1 != (undefined4 *)&DAT_002f9fa4);
        iStack_1080 = 0x8080b;
        Netchan_CreateFragments();
        param_1[0x1a] = 0;
      }
      for (local_ffc = 0; local_ffc < 2; local_ffc = local_ffc + 1) {
        *(undefined2 *)((int)param_1 + local_ffc * 2 + 0x1fc8) = 0;
        param_1[local_ffc + 0x7ea] = 0;
        param_1[local_ffc + 0x7ec] = 0;
        *(undefined2 *)((int)param_1 + local_ffc * 2 + 0x1fcc) = 0;
        if (local_1014[local_ffc] != 0) {
          local_1014[3] = 1;
        }
      }
      if ((bVar7) || (local_1014[3] != 0)) {
        param_1[0x12] = param_1[0x12] ^ 1;
        local_fe4 = 1;
      }
      if (bVar7) {
        local_1074._0_4_ = (undefined4 *)param_1[0x1a];
        ppcStack_1078 = (char **)(param_1 + 0x1b);
        ppcStack_107c = (char **)(param_1 + 0x402);
        iStack_1080 = 0x80929;
        Q_memcpy();
        param_1[0x401] = param_1[0x1a];
        param_1[0x1a] = 0;
        for (local_ffc = 0; local_ffc < 2; local_ffc = local_ffc + 1) {
          *(undefined2 *)((int)param_1 + local_ffc * 2 + 0x1fc8) = *(undefined2 *)(param_1 + 0x401);
        }
      }
      for (local_ffc = 0; local_ffc < 2; local_ffc = local_ffc + 1) {
        local_1014[2] = param_1[local_ffc + 0x7ee];
        if (((local_1014[2] != 0) &&
            (local_101c = *(int *)(local_1014[2] + 0x18), *(int *)(local_1014[2] + 0x594) != 0)) &&
           (*(int *)(local_1014[2] + 0x598) == 0)) {
          local_101c = *(int *)(local_1014[2] + 0x6a4);
        }
        if (((local_1014[local_ffc] != 0) && (local_1014[2] != 0)) &&
           (local_101c + param_1[0x401] < 0x4b0)) {
          param_1[local_ffc + 0x7ec] =
               *(int *)(local_1014[2] + 4) << 0x10 | param_1[local_ffc + 0x7f0] & 0xffff;
          if ((*(int *)(local_1014[2] + 0x594) != 0) && (*(int *)(local_1014[2] + 0x598) == 0)) {
            ppcStack_1078 = (char **)&DAT_000e528f;
            ppcStack_107c = (char **)(local_1014[2] + 0x59c);
            iStack_1080 = 0x80af2;
            uVar3 = FS_Open();
            local_1074 = (double)((ulonglong)local_1074._4_4_ << 0x20);
            ppcStack_1078 = *(char ***)(local_1014[2] + 0x6a0);
            iStack_1080 = 0x80b1b;
            ppcStack_107c = (char **)uVar3;
            FS_Seek();
            local_1074._0_4_ = (undefined4 *)0x1;
            ppcStack_1078 = *(char ***)(local_1014[2] + 0x6a4);
            ppcStack_107c =
                 (char **)(*(int *)(local_1014[2] + 0x10) + *(int *)(local_1014[2] + 0x18));
            iStack_1080 = 0x80b4e;
            local_1074._4_4_ = uVar3;
            FS_Read();
            *(int *)(local_1014[2] + 0x18) =
                 *(int *)(local_1014[2] + 0x6a4) + *(int *)(local_1014[2] + 0x18);
            iStack_1080 = 0x80b81;
            ppcStack_107c = (char **)uVar3;
            FS_Close();
          }
          local_1074._0_4_ = *(undefined4 **)(local_1014[2] + 0x18);
          ppcStack_1078 = *(char ***)(local_1014[2] + 0x10);
          ppcStack_107c = (char **)(param_1[0x401] + 0x1008 + (int)param_1);
          iStack_1080 = 0x80bb5;
          Q_memcpy();
          param_1[0x401] = *(int *)(local_1014[2] + 0x18) + param_1[0x401];
          *(undefined2 *)((int)param_1 + local_ffc * 2 + 0x1fcc) =
               *(undefined2 *)(local_1014[2] + 0x18);
          ppcStack_1078 = (char **)(param_1 + local_ffc + 0x7ee);
          ppcStack_107c = (char **)local_1014[2];
          iStack_1080 = 0x80c22;
          Netchan_UnlinkFragment();
          param_1[local_ffc + 0x7ea] = 1;
          for (local_1000 = local_ffc + 1; local_1000 < 2; local_1000 = local_1000 + 1) {
            *(short *)((int)param_1 + local_1000 * 2 + 0x1fc8) =
                 *(short *)((int)param_1 + local_ffc * 2 + 0x1fcc) +
                 *(short *)((int)param_1 + local_1000 * 2 + 0x1fc8);
          }
        }
      }
    }
    local_ff4 = param_1[0x11] | local_fe4 << 0x1f;
    local_ff8 = (undefined4 *)(param_1[0xd] | param_1[0x10] << 0x1f);
    local_fe8 = 0;
    for (local_ffc = 0; local_ffc < 2; local_ffc = local_ffc + 1) {
      if (param_1[local_ffc + 0x7ea] != 0) {
        local_fe8 = 1;
        break;
      }
    }
    if ((local_fe4 != 0) && (local_fe8 != 0)) {
      local_ff4 = local_ff4 | 0x40000000;
    }
    param_1[0x11] = param_1[0x11] + 1;
    ppcStack_1078 = (char **)local_ff4;
    ppcStack_107c = &local_18;
    iStack_1080 = 0x80dc2;
    MSG_WriteLong();
    ppcStack_1078 = (char **)local_ff8;
    ppcStack_107c = &local_18;
    iStack_1080 = 0x80dd8;
    MSG_WriteLong();
    if ((local_fe4 != 0) && (local_fe8 != 0)) {
      for (local_ffc = 0; local_ffc < 2; local_ffc = local_ffc + 1) {
        if (param_1[local_ffc + 0x7ea] == 0) {
          ppcStack_1078 = (char **)0x0;
          ppcStack_107c = &local_18;
          iStack_1080 = 0x80ece;
          MSG_WriteByte();
        }
        else {
          ppcStack_1078 = (char **)0x1;
          ppcStack_107c = &local_18;
          iStack_1080 = 0x80e3f;
          MSG_WriteByte();
          ppcStack_1078 = (char **)param_1[local_ffc + 0x7ec];
          ppcStack_107c = &local_18;
          iStack_1080 = 0x80e69;
          MSG_WriteLong();
          ppcStack_1078 = (char **)(int)*(short *)((int)param_1 + local_ffc * 2 + 0x1fc8);
          ppcStack_107c = &local_18;
          iStack_1080 = 0x80e91;
          MSG_WriteShort();
          ppcStack_1078 = (char **)(int)*(short *)((int)param_1 + local_ffc * 2 + 0x1fcc);
          ppcStack_107c = &local_18;
          iStack_1080 = 0x80eb9;
          MSG_WriteShort();
        }
      }
    }
    if (local_fe4 != 0) {
      local_1074._0_4_ = (undefined4 *)param_1[0x401];
      ppcStack_1078 = (char **)(param_1 + 0x402);
      ppcStack_107c = &local_18;
      iStack_1080 = 0x80f04;
      SZ_Write();
      param_1[0x13] = param_1[0x11] + -1;
    }
    local_ff0 = local_c;
    if (local_fec != 0) {
      local_ff0 = 0x578;
    }
    if (local_ff0 - local_8 < (int)param_2) {
      ppcStack_107c = (char **)0xe52a0;
      iStack_1080 = 0x80f69;
      Con_DPrintf();
    }
    else {
      local_1074._0_4_ = param_2;
      ppcStack_1078 = (char **)param_3;
      ppcStack_107c = &local_18;
      iStack_1080 = 0x80f53;
      SZ_Write();
    }
    if (local_8 < 0x10) {
      for (local_1020 = local_8; local_1020 < 0x10; local_1020 = local_1020 + 1) {
        ppcStack_1078 = (char **)0x1;
        ppcStack_107c = &local_18;
        iStack_1080 = 0x80f96;
        MSG_WriteByte();
      }
    }
    param_1[(param_1[0x89b] & 0x1f) * 3 + 0x83b] = local_8 + 0x1c;
    *(double *)(param_1 + (param_1[0x89b] & 0x1f) * 3 + 0x83c) = realtime;
    param_1[0x89b] = param_1[0x89b] + 1;
    ppcStack_107c = (char **)param_1;
    iStack_1080 = 0x8100f;
    Netchan_UpdateFlow();
    if (DAT_002fe004 == 0) {
      local_1074 = (double)(CONCAT44(local_1074._4_4_,param_1[0x11] + -1) & 0xffffffff000000ff);
      ppcStack_1078 = (char **)(local_8 + -8);
      ppcStack_107c = (char **)(local_10 + 8);
      iStack_1080 = 0x81046;
      COM_Munge2();
      if (_DAT_00119898 != (code *)0x0) {
        ppcStack_1078 = &local_18;
        ppcStack_107c = (char **)param_1;
        iStack_1080 = 0x8106b;
        (*_DAT_00119898)();
      }
      piVar6 = &iStack_1080;
      puVar5 = param_1;
      for (iVar4 = 5; puVar5 = puVar5 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar6 = *puVar5;
        piVar6 = piVar6 + 1;
      }
      puStack_1084 = local_10;
      iStack_1088 = local_8;
      pcStack_108c = (char *)*param_1;
      aiStack_1094[1] = 0x81094;
      NET_SendPacket();
    }
    if (((sv == 0) ||
        ((byte)(0.0 < (float)sv_lan._12_4_ |
                (byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) ||
       (local_1004 = (float)sv_lan_rate._12_4_,
       (byte)(1000.0 < (float)sv_lan_rate._12_4_ |
              (byte)((ushort)((ushort)NAN((float)sv_lan_rate._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_lan_rate._12_4_ == 1000.0) << 0xe) >> 8)) != 1)) {
      local_1004 = (float)*(double *)(param_1 + 9);
    }
    local_1004 = 1.0 / local_1004;
    dVar1 = *(double *)(param_1 + 0xb);
    if ((byte)(dVar1 < realtime | (byte)((ushort)((ushort)(NAN(dVar1) || NAN(realtime)) << 10) >> 8)
              | (byte)((ushort)((ushort)(dVar1 == realtime) << 0xe) >> 8)) == 1) {
      *(double *)(param_1 + 0xb) = realtime;
    }
    *(double *)(param_1 + 0xb) =
         (double)((float)*(double *)(param_1 + 0xb) + (float)(local_8 + 0x1c) * local_1004);
    if (((byte)(0.0 < (float)net_showpackets._12_4_ |
                (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
        ) && ((byte)(2.0 < (float)net_showpackets._12_4_ |
                     (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 2.0) << 0xe) >> 8)) !=
              0x40)) {
      if (param_1 == (undefined4 *)&DAT_002f9fa4) {
        cVar2 = 'c';
        dVar1 = (double)cl._176020_8_;
      }
      else {
        cVar2 = 's';
        dVar1 = DAT_0036bc6c;
      }
      local_1074 = (double)(float)dVar1;
      ppcStack_1078 = (char **)(uint)(local_fe4 != 0);
      ppcStack_107c = (char **)param_1[0xd];
      iStack_1080 = param_1[0x11] + -1;
      puStack_1084 = (undefined1 *)local_8;
      iStack_1088 = (int)cVar2;
      pcStack_108c = " %c --> sz=%i seq=%i ack=%i rel=%i tm=%f\n";
      aiStack_1094[1] = 0x8120f;
      Con_Printf();
    }
  }
  else {
    piVar6 = aiStack_1094;
    for (iVar4 = 5; param_1 = param_1 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar6 = *param_1;
      piVar6 = piVar6 + 1;
    }
    ppcStack_1078 = (char **)NET_AdrToString();
    ppcStack_107c = (char **)0xe5271;
    iStack_1080 = 0x806c3;
    Con_Printf();
  }
  return;
}


// Netchan_UnlinkFragment  @ 0007fecc
void Netchan_UnlinkFragment(int *param_1,int *param_2)

{
  int *local_8;
  
  if (param_2 == (int *)0x0) {
    Con_Printf("Netchan_UnlinkFragment:  Asked to unlink fragment from empty list, ignored\n");
  }
  else if (param_1 == (int *)*param_2) {
    *param_2 = *param_1;
    Mem_Free(param_1);
  }
  else {
    for (local_8 = (int *)*param_2; *local_8 != 0; local_8 = (int *)*local_8) {
      if ((int *)*local_8 == param_1) {
        *local_8 = *param_1;
        Mem_Free(param_1);
        return;
      }
    }
    Con_Printf("Netchan_UnlinkFragment:  Couldn\'t find fragment\n");
  }
  return;
}


// Netchan_UpdateFlow  @ 00080480
void Netchan_UpdateFlow(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *local_24;
  float local_18;
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = 0;
  local_18 = 0.0;
  if (param_1 != 0) {
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      iVar2 = param_1 + local_8 * 0x194 + 0x20ec;
      if (0.1 <= realtime - *(double *)(iVar2 + 0x184)) {
        *(double *)(iVar2 + 0x184) = realtime + 0.1;
        uVar3 = *(int *)(iVar2 + 0x180) - 1;
        local_24 = (int *)(iVar2 + (uVar3 & 0x1f) * 0xc);
        for (local_10 = 1; local_10 < 0x10; local_10 = local_10 + 1) {
          piVar1 = (int *)(iVar2 + (uVar3 - local_10 & 0x1f) * 0xc);
          local_14 = local_14 + *piVar1;
          local_18 = (float)(((longdouble)*(double *)(local_24 + 1) -
                             (longdouble)*(double *)(piVar1 + 1)) + (longdouble)local_18);
          local_24 = piVar1;
        }
        if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
          *(undefined4 *)(iVar2 + 0x18c) = 0;
        }
        else {
          *(float *)(iVar2 + 0x18c) = (float)local_14 / local_18;
          *(float *)(iVar2 + 0x18c) = *(float *)(iVar2 + 0x18c) / 1024.0;
        }
        *(float *)(iVar2 + 400) =
             *(float *)(iVar2 + 0x18c) * 0.33333334 + *(float *)(iVar2 + 400) * 0.6666667;
      }
    }
  }
  return;
}


// Netchan_UpdateProgress  @ 00082dd8
void Netchan_UpdateProgress(int param_1)

{
  int iVar1;
  int local_438;
  char *local_434;
  char *local_430;
  char local_42c [1028];
  float local_28;
  float local_18;
  int local_14;
  uint local_10;
  int local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_18 = 0.0;
  scr_downloading._12_4_ = 0xbf800000;
  gDownloadFile = 0;
  if (((byte)(1.0 < (float)net_drawslider._12_4_ |
              (byte)((ushort)((ushort)NAN((float)net_drawslider._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)net_drawslider._12_4_ == 1.0) << 0xe) >> 8)) == 0x40)
     || (*(int *)(param_1 + 0x1fd4) != 0)) {
    for (local_14 = 1; -1 < local_14; local_14 = local_14 + -1) {
      if (*(int *)(local_14 * 4 + param_1 + 0x1fd0) == 0) {
        if (((*(int *)(local_14 * 4 + param_1 + 0x1fb8) != 0) &&
            (*(int *)(local_14 * 4 + param_1 + 0x1fc0) != 0)) &&
           (local_28 = ((float)*(int *)(*(int *)(local_14 * 4 + param_1 + 0x1fb8) + 4) * 100.0) /
                       (float)*(int *)(local_14 * 4 + param_1 + 0x1fc0), local_18 < local_28)) {
          local_18 = local_28;
        }
      }
      else {
        local_8 = *(undefined4 **)(local_14 * 4 + param_1 + 0x1fd0);
        local_10 = local_8[1] & 0xffff;
        for (; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
          local_c = local_c + 1;
        }
        if ((local_10 != 0) &&
           (local_28 = ((float)local_c * 100.0) / (float)local_10, local_18 < local_28)) {
          local_18 = local_28;
        }
        local_8 = *(undefined4 **)(local_14 * 4 + param_1 + 0x1fd0);
        if (local_14 == 1) {
          local_438 = 0;
          local_430 = *(char **)((int)local_8 + 0x10);
          local_434 = local_42c;
          do {
            if (*local_430 == '\0') break;
            *local_434 = *local_430;
            local_430 = local_430 + 1;
            local_434 = local_434 + 1;
            local_438 = local_438 + 1;
          } while (local_438 < 0x81);
          *local_434 = '\0';
          iVar1 = Q_strlen(local_42c);
          if ((0 < iVar1) && (local_42c[0] != '!')) {
            Q_strncpy(&gDownloadFile,local_42c,0xff);
            DAT_00362aff = 0;
          }
        }
      }
    }
    scr_downloading._12_4_ = local_18;
  }
  return;
}


// Netchan_Validate  @ 00081438
bool Netchan_Validate(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int local_8;
  
  for (local_8 = 0;
      (local_8 < 2 &&
      ((*(int *)(param_2 + local_8 * 4) == 0 ||
       ((((*(uint *)(param_3 + local_8 * 4) >> 0x10 < 0x61a9 &&
          ((*(uint *)(param_3 + local_8 * 4) & 0xffff) < 0x61a9)) &&
         (-1 < *(int *)(param_5 + local_8 * 4))) &&
        (((*(int *)(param_5 + local_8 * 4) < 0x801 && (-1 < *(int *)(param_4 + local_8 * 4))) &&
         (*(int *)(param_4 + local_8 * 4) < 0x4001)))))))); local_8 = local_8 + 1) {
  }
  return 1 < local_8;
}


