// SV_ActivateServer  @ 08078060
void SV_ActivateServer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  Cvar_Set("sv_newunit",&DAT_080a3b53);
  (*DAT_08178ef4)(DAT_0814043c,DAT_08140434,svs);
  sv = 1;
  DAT_08140440 = 2;
  if (param_1 == 0) {
    host_frametime._0_4_ = 0xd2f1a9fc;
    host_frametime._4_4_ = 0x3f50624d;
  }
  else {
    host_frametime._0_4_ = 0x9999999a;
    host_frametime._4_4_ = 0x3fb99999;
    SV_Physics();
  }
  SV_Physics();
  SV_CreateBaseline();
  (&DAT_0814378c)[DAT_08143788 + -1] = DAT_08143784;
  SV_CreateResourceList();
  host_client = DAT_0816dd10;
  if (0 < svs) {
    iVar2 = 0;
    do {
      if ((*host_client != 0) || (host_client[2] != 0)) {
        if (svs < 2) {
          SV_SendServerinfo(host_client);
        }
        uVar1 = sv_gpNewUserMsgs;
        sv_gpNewUserMsgs = uVar1;
        if (sv_gpUserMsgs != 0) {
          sv_gpNewUserMsgs = sv_gpUserMsgs;
          SV_SendUserReg(host_client + 0x1e);
          sv_gpNewUserMsgs = uVar1;
        }
      }
      iVar2 = iVar2 + 1;
      host_client = host_client + 0x14ae;
    } while (iVar2 < svs);
  }
  HPAK_FlushHostQueue();
  if (svs < 2) {
    Con_DPrintf("Game started\n");
  }
  else {
    Con_DPrintf("%i player server started\n",svs);
  }
  return;
}


// SV_AddCorrectGravity  @ 0807ae00
void SV_AddCorrectGravity(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 0x1d8);
  fVar2 = 1.0;
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar2 = fVar1;
  }
  *(float *)(param_1 + 0x104) =
       *(float *)(param_1 + 0x104) - fVar2 * (float)sv_gravity._12_4_ * 0.5 * (float)host_frametime;
  *(float *)(param_1 + 0x104) =
       *(float *)(param_1 + 0x110) * (float)host_frametime + *(float *)(param_1 + 0x104);
  *(undefined4 *)(param_1 + 0x110) = 0;
  SV_CheckVelocity(param_1);
  return;
}


// SV_AddGravity  @ 0807ad80
void SV_AddGravity(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 0x1d8);
  fVar2 = 1.0;
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar2 = fVar1;
  }
  *(float *)(param_1 + 0x104) =
       *(float *)(param_1 + 0x104) - fVar2 * (float)sv_gravity._12_4_ * (float)host_frametime;
  *(float *)(param_1 + 0x104) =
       *(float *)(param_1 + 0x110) * (float)host_frametime + *(float *)(param_1 + 0x104);
  *(undefined4 *)(param_1 + 0x110) = 0;
  SV_CheckVelocity(param_1);
  return;
}


// SV_AddIP_f  @ 08078ca0
void SV_AddIP_f(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  longdouble lVar5;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 3) {
    iVar2 = 0;
    if (0 < numipfilters) {
      do {
        if ((&DAT_08162ce4)[iVar2 * 4] == -1) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 < numipfilters);
    }
    if (iVar2 == numipfilters) {
      if (numipfilters == 0x400) {
        Con_Printf("IP filter list is full\n");
        return;
      }
      numipfilters = numipfilters + 1;
    }
    uVar3 = Cmd_Argv(1);
    lVar5 = (longdouble)__strtod_internal(uVar3,0,0);
    fVar1 = (float)lVar5;
    if (fVar1 < 0.01) {
      fVar1 = 0.0;
    }
    (&DAT_08162cec)[iVar2 * 4] = fVar1;
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = fVar1 * 60.0 + (float)realtime;
    }
    (&DAT_08162ce8)[iVar2 * 4] = fVar1;
    uVar3 = Cmd_Argv(2,&ipfilters + iVar2 * 4);
    iVar4 = StringToFilter(uVar3);
    if (iVar4 == 0) {
      (&DAT_08162ce4)[iVar2 * 4] = 0xffffffff;
    }
  }
  else {
    Con_Printf("Usage:  addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n");
  }
  return;
}


// SV_AddResource  @ 080775e0
void SV_AddResource(undefined4 param_1,char *param_2,undefined4 param_3,int param_4,
                   undefined4 param_5)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = DAT_0813db2c * 0x68;
  if (0x4ff < DAT_0813db2c) {
    Sys_Error("Too many resources on server.");
  }
  DAT_0813db2c = DAT_0813db2c + 1;
  *(undefined4 *)(&DAT_0811d36c + iVar1) = param_1;
  strcpy(&DAT_0811d32c + iVar1,param_2);
  *(undefined4 *)(&DAT_0811d374 + iVar1) = param_3;
  bVar2 = (&DAT_0811d378)[iVar1];
  if (param_4 != 0) {
    bVar2 = bVar2 | 1;
  }
  (&DAT_0811d378)[iVar1] = bVar2;
  *(undefined4 *)(&DAT_0811d370 + iVar1) = param_5;
  return;
}


// SV_AddSampleToHashedLookupTable  @ 08071710
void SV_AddSampleToHashedLookupTable(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = SV_HashString(param_1,0x3ff);
  iVar2 = iVar1;
  while ((&DAT_0813f330)[iVar2] != 0) {
    iVar2 = iVar2 + 1;
    hashstrings_collisions = hashstrings_collisions + 1;
    if (0x3fe < iVar2) {
      iVar2 = 0;
    }
    if (iVar2 == iVar1) {
      Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
    }
  }
  (&DAT_0813f330)[iVar2] = param_2;
  return;
}


// SV_AddToFatPVS  @ 08073fd0
void SV_AddToFatPVS(float *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  while (-1 < *param_2) {
    pfVar1 = (float *)param_2[6];
    fVar2 = (param_1[2] * pfVar1[2] + param_1[1] * pfVar1[1] + *param_1 * *pfVar1) - pfVar1[3];
    if ((byte)(8.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 8.0) << 0xe) >> 8)) == 1) {
      param_2 = (int *)param_2[7];
    }
    else if (-8.0 <= fVar2) {
      SV_AddToFatPVS(param_1,param_2[7]);
      param_2 = (int *)param_2[8];
    }
    else {
      param_2 = (int *)param_2[8];
    }
  }
  if (*param_2 != -2) {
    iVar3 = Mod_LeafPVS(param_2,DAT_0811d320);
    iVar4 = 0;
    if (0 < fatbytes) {
      do {
        (&fatpvs)[iVar4] = (&fatpvs)[iVar4] | *(byte *)(iVar4 + iVar3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < fatbytes);
    }
  }
  return;
}


// SV_AddToFullPack  @ 080762c0
void SV_AddToFullPack(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_18;
  
  iVar3 = DAT_0814043c + param_2 * 0x2c8;
  if (*(int *)(iVar3 + 0x1d4) == 0x80) {
    return;
  }
  if (*(int *)(iVar3 + 0x170) == 0) {
    return;
  }
  if (*(char *)(*(int *)(iVar3 + 0x174) + pr_strings) == '\0') {
    return;
  }
  if (param_3 != 0) {
    if (*(int *)(iVar3 + 0x10) < 0) {
      iVar2 = CM_HeadnodeVisible(*(int *)(DAT_0811d320 + 0xa4) + *(short *)(iVar3 + 0x14) * 0x28,
                                 param_3);
      if (iVar2 == 0) {
        return;
      }
    }
    else {
      local_18 = 0;
      if (0 < *(int *)(iVar3 + 0x10)) {
        do {
          if ((*(byte *)((*(short *)(local_18 * 2 + iVar3 + 0x14) >> 3) + param_3) >>
               (int)(short)(*(ushort *)(local_18 * 2 + iVar3 + 0x14) & 7) & 1) != 0) break;
          local_18 = local_18 + 1;
        } while (local_18 < *(int *)(iVar3 + 0x10));
      }
      if (local_18 == *(int *)(iVar3 + 0x10)) {
        return;
      }
    }
  }
  if (*param_1 < 0x100) {
    piVar1 = param_1 + *param_1 * 0x24 + 1;
    *param_1 = *param_1 + 1;
    piVar1[1] = param_2;
    piVar1[2] = 0;
    *piVar1 = 0;
    if ((*(byte *)(iVar3 + 0x263) & 0x20) != 0) {
      *piVar1 = 1;
    }
    piVar1[3] = *(int *)(iVar3 + 0xe4);
    piVar1[4] = *(int *)(iVar3 + 0xe8);
    piVar1[5] = *(int *)(iVar3 + 0xec);
    piVar1[6] = *(int *)(iVar3 + 300);
    piVar1[7] = *(int *)(iVar3 + 0x130);
    piVar1[8] = *(int *)(iVar3 + 0x134);
    piVar1[0x1d] = *(int *)(iVar3 + 0x198);
    piVar1[0x1e] = *(int *)(iVar3 + 0x19c);
    piVar1[0x1f] = *(int *)(iVar3 + 0x1a0);
    piVar1[0x20] = *(int *)(iVar3 + 0x1a4);
    piVar1[0x21] = *(int *)(iVar3 + 0x1a8);
    piVar1[0x22] = *(int *)(iVar3 + 0x1ac);
    piVar1[0x1a] = *(int *)(iVar3 + 0xfc);
    piVar1[0x1b] = *(int *)(iVar3 + 0x100);
    piVar1[0x1c] = *(int *)(iVar3 + 0x104);
    piVar1[9] = *(int *)(iVar3 + 0x170);
    piVar1[0xb] = *(int *)(iVar3 + 0x1ec);
    piVar1[0xc] = *(int *)(iVar3 + 0x264);
    *(undefined2 *)(piVar1 + 0xd) = *(undefined2 *)(iVar3 + 0x1cc);
    piVar1[0xe] = *(int *)(iVar3 + 0x1d4);
    piVar1[0xf] = *(int *)(iVar3 + 0x200);
    *(undefined2 *)((int)piVar1 + 0x36) = *(undefined2 *)(iVar3 + 0x1c8);
    piVar1[0x14] = *(int *)(iVar3 + 0x1c4);
    piVar1[0x15] = *(int *)(iVar3 + 0x1f0);
    piVar1[10] = *(int *)(iVar3 + 0x1e4);
    piVar1[0x16] = *(int *)(iVar3 + 500);
    piVar1[0x17] = *(int *)(iVar3 + 0x1d0);
    local_18 = 0;
    do {
      *(undefined1 *)((int)piVar1 + local_18 + 0x60) = *(undefined1 *)(local_18 + iVar3 + 0x1f8);
      local_18 = local_18 + 1;
    } while (local_18 < 4);
    local_18 = 0;
    do {
      *(undefined1 *)((int)piVar1 + local_18 + 100) = *(undefined1 *)(local_18 + iVar3 + 0x1fc);
      local_18 = local_18 + 1;
    } while (local_18 < 2);
    piVar1[0x10] = *(int *)(iVar3 + 0x204);
    piVar1[0x11] = (int)ROUND(*(float *)(iVar3 + 0x208));
    piVar1[0x13] = *(int *)(iVar3 + 0x218);
    *(char *)(piVar1 + 0x12) = (char)(longlong)ROUND(*(float *)(iVar3 + 0x20c));
    *(char *)((int)piVar1 + 0x49) = (char)(longlong)ROUND(*(float *)(iVar3 + 0x210));
    *(char *)((int)piVar1 + 0x4a) = (char)(longlong)ROUND(*(float *)(iVar3 + 0x214));
    if (*(int *)(iVar3 + 0x250) == 0) {
      piVar1[0x23] = 0;
    }
    else {
      iVar3 = NUM_FOR_EDICT(*(undefined4 *)(iVar3 + 0x250));
      piVar1[0x23] = iVar3;
    }
  }
  else {
    Con_DPrintf("Too many entities in visible packet list.\n");
  }
  return;
}


// SV_AddToResourceList  @ 0807e170
void SV_AddToResourceList(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 100) == 0) && (*(int *)(param_1 + 0x60) == 0)) {
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
    *(int *)(*(int *)(param_2 + 100) + 0x60) = param_1;
    *(int *)(param_2 + 100) = param_1;
    *(int *)(param_1 + 0x60) = param_2;
  }
  else {
    Con_Printf("Resource already linked\n");
  }
  return;
}


// SV_AllocClientFrames  @ 08070640
void SV_AllocClientFrames(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  if (0 < DAT_08166d04) {
    iVar3 = 0;
    iVar2 = DAT_0816dd10;
    do {
      if (*(int *)(iVar2 + 0x4f04) != 0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      pvVar1 = malloc(SV_UPDATE_BACKUP * 0x18);
      *(void **)(iVar2 + 0x4f04) = pvVar1;
      memset(*(void **)(iVar2 + 0x4f04),0,SV_UPDATE_BACKUP * 0x18);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x52b8;
    } while (iVar3 < DAT_08166d04);
  }
  return;
}


// SV_AllocPacketEntities  @ 08070700
void SV_AllocPacketEntities(int param_1,int param_2)

{
  void *pvVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x14) != 0) {
      SV_ClearPacketEntities(param_1);
    }
    pvVar1 = malloc(param_2 * 0x90);
    *(void **)(param_1 + 0x14) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      Sys_Error("Failed to allocate space for %i packet entities\n",param_2);
    }
    memset(*(void **)(param_1 + 0x14),0,param_2 * 0x90);
    *(int *)(param_1 + 0x10) = param_2;
  }
  return;
}


// SV_AllowDownload_f  @ 0805e830
void SV_AllowDownload_f(void)

{
  float fVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(sv_allow_download + 0xc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(sv_allow_download + 0xc) == 0.0) << 0xe) >> 8)) ==
      0x40) {
    uVar2 = 0x3f800000;
  }
  *(undefined4 *)(sv_allow_download + 0xc) = uVar2;
  fVar1 = *(float *)(sv_allow_download + 0xc);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    pcVar3 = "Server downloading disabled.\n";
  }
  else {
    pcVar3 = "Server downloading enabled.\n";
  }
  Con_Printf(pcVar3);
  return;
}


// SV_AllowUpload_f  @ 0805e880
void SV_AllowUpload_f(void)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(sv_allow_upload + 0xc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(sv_allow_upload + 0xc) == 0.0) << 0xe) >> 8)) ==
      0x40) {
    uVar2 = 0x3f800000;
  }
  *(undefined4 *)(sv_allow_upload + 0xc) = uVar2;
  fVar1 = *(float *)(sv_allow_upload + 0xc);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    Con_Printf("Server uploading disabled.\n");
  }
  else {
    Con_Printf("Server uploading enabled.\nMax. upload size is %i",sv_upload_maxsize);
  }
  return;
}


// SV_BeginDownload_f  @ 0805e980
void SV_BeginDownload_f(void)

{
  char cVar1;
  int iVar2;
  char *__haystack;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 local_7c [26];
  undefined1 local_14 [16];
  
  __haystack = (char *)Cmd_Argv(1);
  if (cmd_source == 1) {
    CL_CheckOrDownloadFile(__haystack);
    return;
  }
  pcVar3 = strstr(__haystack,"..");
  if ((pcVar3 == (char *)0x0) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(sv_allow_download + 0xc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(sv_allow_download + 0xc) == 0.0) << 0xe) >> 8)) !=
      0x40)) {
    if (*(int *)(host_client + 0x5034) != 0) {
      COM_FreeFile(*(undefined4 *)(host_client + 0x5034));
      *(undefined4 *)(host_client + 0x5034) = 0;
    }
    iVar5 = -1;
    pcVar3 = __haystack;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if ((iVar5 == -0x26) && (iVar5 = strncasecmp(__haystack,"!MD5",4), iVar5 == 0)) {
      puVar6 = local_7c;
      for (iVar5 = 0x1a; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      COM_HexConvert(__haystack + 4,0x20,local_14);
      iVar5 = HPAK_ResourceForHash("custom.hpk",local_14,local_7c);
      if (iVar5 != 0) {
        HPAK_GetDataPointer("custom.hpk",local_7c,host_client + 0x5034,host_client + 0x5038);
      }
      iVar5 = host_client;
      *(undefined4 *)(host_client + 0x5048) = 1;
      uVar7 = SV_GetCustomChunk(iVar5);
      *(undefined4 *)(host_client + 0x504c) = uVar7;
    }
    else {
      iVar5 = COM_FileSize(__haystack);
      *(int *)(host_client + 0x5038) = iVar5;
      if (iVar5 != -1) {
        uVar7 = COM_LoadFile(__haystack,5,0);
        *(undefined4 *)(host_client + 0x5034) = uVar7;
      }
      iVar5 = host_client;
      *(undefined4 *)(host_client + 0x5048) = 0;
      *(undefined4 *)(iVar5 + 0x504c) = 0x400;
    }
    iVar5 = host_client;
    *(undefined4 *)(host_client + 0x503c) = 0;
    iVar2 = host_client;
    if ((*(int *)(iVar5 + 0x5038) != -1) && (*(int *)(iVar5 + 0x5034) != 0)) {
      *(undefined4 *)(host_client + 0x5040) = 0;
      CRC32_Init(iVar2 + 0x5044);
      iVar5 = Cmd_Argc();
      if (iVar5 == 4) {
        uVar7 = Cmd_Argv(2);
        uVar7 = __strtol_internal(uVar7,0,10,0);
        uVar4 = Cmd_Argv(3);
        uVar4 = __strtol_internal(uVar4,0,10,0);
        SV_SetupResume(uVar7,uVar4);
      }
      SV_NextDownload_f();
      Con_DPrintf("Downloading %s to %s\n",__haystack,host_client + 0x5005);
      return;
    }
    MSG_WriteByte(host_client + 0x78,0x28);
    MSG_WriteShort(host_client + 0x78,0xffffffff);
    MSG_WriteShort(host_client + 0x78,0xffffffff);
    uVar7 = 0xfffffffe;
  }
  else {
    MSG_WriteByte(host_client + 0x78,0x28);
    MSG_WriteShort(host_client + 0x78,0xffffffff);
    MSG_WriteShort(host_client + 0x78,0xffffffff);
    uVar7 = 0xffffffff;
  }
  MSG_WriteLong(host_client + 0x78,uVar7);
  MSG_WriteByte(host_client + 0x78,0);
  return;
}


// SV_BroadcastCommand  @ 08077ed0
void SV_BroadcastCommand(char *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 local_498 [8];
  undefined1 *local_490;
  undefined4 local_48c;
  undefined4 local_488;
  undefined1 local_484 [128];
  char local_404 [1024];
  
  local_490 = local_484;
  local_488 = 0;
  local_48c = 0x80;
  if (sv != 0) {
    vsprintf(local_404,param_1,&stack0x00000008);
    MSG_WriteByte(local_498,9);
    MSG_WriteString(local_498,local_404);
    iVar2 = 0;
    piVar1 = DAT_0816dd10;
    if (0 < svs) {
      do {
        if ((((*piVar1 != 0) || (piVar1[2] != 0)) || (piVar1[1] != 0)) && (piVar1[0xfb0] == 0)) {
          SZ_Write(piVar1 + 0x1e,local_490,local_488);
        }
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 0x14ae;
      } while (iVar2 < svs);
    }
  }
  return;
}


// SV_BroadcastPrintf  @ 080577c0
void SV_BroadcastPrintf(char *param_1)

{
  int iVar1;
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  iVar1 = 0;
  if (0 < svs) {
    do {
      if ((*(int *)(DAT_0816dd10 + iVar1 * 0x52b8) != 0) ||
         (*(int *)(DAT_0816dd10 + 4 + iVar1 * 0x52b8) != 0)) {
        MSG_WriteByte(iVar1 * 0x52b8 + DAT_0816dd10 + 0x78,8);
        MSG_WriteString(iVar1 * 0x52b8 + DAT_0816dd10 + 0x78,local_404);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < svs);
  }
  return;
}


// SV_BuildHashedSoundLookupTable  @ 080716b0
void SV_BuildHashedSoundLookupTable(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_0813f330;
  for (iVar1 = 0x1ff; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_0813eb30)[iVar1] == 0) {
      DAT_0813fb30 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_0813eb30)[iVar1],iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x200);
  DAT_0813fb30 = 1;
  return;
}


// SV_BuildSoundMsg  @ 080712d0
undefined4
SV_BuildSoundMsg(undefined4 param_1,uint param_2,char *param_3,uint param_4,float param_5,
                ushort param_6,uint param_7,int param_8,undefined4 param_9)

{
  ushort uVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  undefined1 local_20;
  undefined2 local_16;
  undefined1 local_13;
  ushort local_12;
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  if (0xff < param_4) {
    Sys_Error("SV_StartSound: volume = %i",param_4);
  }
  if ((param_5 < 0.0) ||
     ((byte)(4.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 4.0) << 0xe) >> 8)) == 1)) {
    Sys_Error("SV_StartSound: attenuation = %f",(double)param_5);
  }
  if (7 < param_2) {
    Sys_Error("SV_StartSound: channel = %i",param_2);
  }
  if (0xff < param_7) {
    Sys_Error("SV_StartSound: pitch = %i",param_7);
  }
  if ((param_3 == (char *)0x0) || (*param_3 != '!')) {
    iVar2 = SV_LookupSoundIndex();
    if ((iVar2 == 0) || ((&DAT_0813eb30)[iVar2] == 0)) {
      Con_Printf("SV_StartSound: %s not precached (%d)\n",param_3,iVar2);
      return 0;
    }
  }
  else {
    param_6 = param_6 | 0x10;
    iVar2 = __strtol_internal(param_3 + 1,0,10,0);
    if (0x5ff < iVar2) {
      Con_Printf("invalid sentence number: %s",param_3 + 1);
      return 0;
    }
  }
  uVar1 = NUM_FOR_EDICT();
  if (param_4 != 0xff) {
    param_6 = param_6 | 1;
  }
  if ((byte)(1.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 1.0) << 0xe) >> 8)) != 0x40) {
    param_6 = param_6 | 2;
  }
  if (param_7 != 100) {
    param_6 = param_6 | 8;
  }
  if (0xff < iVar2) {
    param_6 = param_6 | 4;
  }
  MSG_WriteByte(param_9,6);
  MSG_StartBitWriting(param_9);
  local_12 = param_6;
  MSG_WriteBitShort(&local_12,9);
  if ((param_6 & 1) != 0) {
    local_13 = (undefined1)param_4;
    MSG_WriteBitByte(&local_13,8);
  }
  if ((param_6 & 2) != 0) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_20 = (undefined1)(longlong)ROUND(param_5 * 64.0);
    local_13 = local_20;
    MSG_WriteBitByte(&local_13,8);
  }
  local_13 = (undefined1)param_2;
  MSG_WriteBitByte(&local_13,3);
  local_12 = uVar1;
  MSG_WriteBitShort(&local_12,10);
  if (iVar2 < 0x100) {
    local_13 = (undefined1)iVar2;
    MSG_WriteBitByte(&local_13,8);
  }
  else {
    local_12 = (ushort)iVar2;
    MSG_WriteBitShort(&local_12,0x10);
  }
  iVar2 = 0;
  do {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_16 = (undefined2)(int)ROUND(*(float *)(param_8 + iVar2 * 4) * 8.0);
    MSG_WriteSBitShort(&local_16,0x10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  if ((param_6 & 8) != 0) {
    local_13 = (undefined1)param_7;
    MSG_WriteBitByte(&local_13,8);
  }
  MSG_EndBitWriting();
  return 1;
}


// SV_CalcPacketLoss  @ 08073e10
int SV_CalcPacketLoss(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x3ec0) == 0) {
    iVar4 = 0;
    iVar2 = 0;
    iVar3 = 0;
    if (0 < SV_UPDATE_BACKUP / 2) {
      do {
        iVar2 = iVar2 + 1;
        fVar1 = *(float *)(*(int *)(param_1 + 0x4f04) + 8 +
                          (*(int *)(param_1 + 0x60) - (iVar3 + 1) & SV_UPDATE_MASK) * 0x18);
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40) {
          iVar4 = iVar4 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < SV_UPDATE_BACKUP / 2);
    }
    if (iVar2 == 0) {
      iVar2 = 100;
    }
    else {
      iVar2 = (int)ROUND(((float)iVar4 * 100.0) / (float)iVar2);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// SV_CalcPing  @ 08073d70
int SV_CalcPing(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x3ec0) == 0) {
    fVar2 = 0.0;
    iVar5 = 0;
    iVar3 = *(int *)(param_1 + 0x4f04);
    iVar4 = 0;
    if (0 < SV_UPDATE_BACKUP) {
      do {
        fVar1 = *(float *)(iVar3 + 8);
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
          fVar2 = fVar2 + *(float *)(iVar3 + 8);
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x18;
      } while (iVar4 < SV_UPDATE_BACKUP);
    }
    if (iVar5 == 0) {
      iVar3 = 9999;
    }
    else {
      iVar3 = (int)ROUND((fVar2 / (float)iVar5) * 1000.0);
    }
  }
  else {
    iVar3 = 5;
  }
  return iVar3;
}


// SV_CheckAllEnts  @ 0807a3f0
void SV_CheckAllEnts(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  if (1 < DAT_08140434) {
    do {
      piVar1 = (int *)(DAT_0814043c + iVar3 * 0x2c8);
      if ((((*piVar1 == 0) && (piVar1[0x71] != 7)) && (piVar1[0x71] != 0)) &&
         (((piVar1[0x71] != 0xc && (piVar1[0x71] != 8)) &&
          (iVar2 = SV_TestEntityPosition(piVar1), iVar2 != 0)))) {
        Con_Printf("entity in invalid position\n");
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_08140434);
  }
  return;
}


// SV_CheckBottom  @ 08079190
undefined4 SV_CheckBottom(int param_1)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float **ppfVar5;
  undefined1 *puVar6;
  int iVar7;
  int aiStackY_b8 [2];
  float *pfStack_94;
  float local_78;
  undefined1 local_6c [16];
  float local_5c;
  float local_50;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  pfVar2 = (float *)(uint)((*(byte *)(param_1 + 0x262) & 0x80) != 0);
  local_10 = *(float *)(param_1 + 0xe4) + *(float *)(param_1 + 0x198);
  local_c = *(float *)(param_1 + 0xe8) + *(float *)(param_1 + 0x19c);
  local_8 = *(float *)(param_1 + 0xec) + *(float *)(param_1 + 0x1a0);
  local_1c = *(float *)(param_1 + 0xe4) + *(float *)(param_1 + 0x1a4);
  local_18 = *(float *)(param_1 + 0xe8) + *(float *)(param_1 + 0x1a8);
  local_14 = *(float *)(param_1 + 0xec) + *(float *)(param_1 + 0x1ac);
  local_20 = local_8 - 1.0;
  iVar7 = 0;
  do {
    iVar4 = 0;
    do {
      local_28 = local_10;
      if (iVar7 != 0) {
        local_28 = local_1c;
      }
      local_24 = local_c;
      if (iVar4 != 0) {
        local_24 = local_18;
      }
      pfStack_94 = &local_28;
      iVar3 = SV_PointContents();
      if (iVar3 != -2) {
        c_no = c_no + 1;
        local_20 = local_8 + (float)sv_stepsize._12_4_;
        local_34 = (local_10 + local_1c) * 0.5;
        local_30 = (local_c + local_18) * 0.5;
        local_2c = local_20 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
        pfStack_94 = pfVar2;
        local_28 = local_34;
        local_24 = local_30;
        SV_Move(local_6c,&local_28,vec3_origin,vec3_origin,&local_34,1,param_1);
        fVar1 = local_50;
        ppfVar5 = &pfStack_94;
        if ((byte)(1.0 < local_5c | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) == 0x40) {
          return 0;
        }
        local_78 = local_50;
        iVar7 = 0;
        do {
          iVar4 = 0;
          puVar6 = (undefined1 *)ppfVar5;
          do {
            local_34 = local_10;
            if (iVar7 != 0) {
              local_34 = local_1c;
            }
            local_30 = local_c;
            if (iVar4 != 0) {
              local_30 = local_18;
            }
            *(float **)(puVar6 + -4) = pfVar2;
            *(int *)(puVar6 + -8) = param_1;
            *(undefined4 *)(puVar6 + -0xc) = 1;
            *(float **)(puVar6 + -0x10) = &local_34;
            *(undefined1 **)(puVar6 + -0x14) = vec3_origin;
            *(undefined1 **)(puVar6 + -0x18) = vec3_origin;
            *(float **)(puVar6 + -0x1c) = &local_28;
            *(undefined1 **)(puVar6 + -0x20) = local_6c;
            *(undefined4 *)(puVar6 + -0x24) = 0x807936e;
            local_28 = local_34;
            local_24 = local_30;
            SV_Move();
            ppfVar5 = (float **)(puVar6 + -4);
            if (((byte)(1.0 < local_5c | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) != 0x40) &&
               (local_78 < local_50)) {
              local_78 = local_50;
            }
            if (((byte)(1.0 < local_5c | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) == 0x40) ||
               ((float)sv_stepsize._12_4_ < fVar1 - local_50)) {
              return 0;
            }
            iVar4 = iVar4 + 1;
            puVar6 = puVar6 + -4;
          } while (iVar4 < 2);
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
        goto LAB_080793d4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    iVar7 = iVar7 + 1;
    if (1 < iVar7) {
LAB_080793d4:
      c_yes = c_yes + 1;
      return 1;
    }
  } while( true );
}


// SV_CheckOrUploadFile  @ 0807d370
/* WARNING: Removing unreachable block (ram,0x0807d660) */

undefined4 SV_CheckOrUploadFile(char *param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  uint uVar5;
  size_t sVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  char **ppcVar11;
  char *pcStack_4f0;
  char local_4b4 [8];
  char local_4ac [104];
  undefined1 local_444 [1024];
  char local_44 [64];
  
  bVar3 = false;
  bVar2 = false;
  pcVar4 = local_4ac;
  for (iVar8 = 0x1a; iVar8 != 0; iVar8 = iVar8 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = pcVar4 + 4;
  }
  pcVar4 = strstr(param_1,"..");
  if (pcVar4 != (char *)0x0) {
    Con_Printf();
    return 1;
  }
  sprintf(local_44,param_1);
  iVar8 = -1;
  pcVar4 = param_1;
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if ((iVar8 == -0x26) && (iVar8 = strncasecmp(param_1,"!MD5",4), iVar8 == 0)) {
    bVar2 = true;
    COM_HexConvert();
    pcStack_4f0 = local_4ac;
    iVar8 = HPAK_GetDataPointer("custom.hpk");
    if (iVar8 != 0) {
      Con_DPrintf();
      return 1;
    }
    Con_DPrintf();
    sprintf((char *)(host_client + 0x516c),"cust%02i.dat ");
    pcStack_4f0 = "SV_CheckOrUploadFile:  upload will be put in %s\n";
    Con_DPrintf();
  }
  else {
    Con_DPrintf();
    iVar8 = COM_FileSize();
    if (iVar8 != -1) {
      return 1;
    }
    strcpy((char *)(host_client + 0x516c),local_44);
  }
  COM_StripExtension();
  if (bVar2) {
    sprintf(local_4b4,".t%02i");
    pcStack_4f0 = (char *)0x807d548;
    strcat((char *)(host_client + 0x5128),local_4b4);
  }
  else {
    strcat((char *)(host_client + 0x5128),".tmp");
  }
  *(undefined4 *)(host_client + 0x5168) = 0;
  if (bVar2) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = COM_FOpenFile();
  }
  if (uVar5 != 0xffffffff) {
    bVar3 = true;
    uVar9 = uVar5;
    if ((int)uVar5 < 0) {
      uVar9 = uVar5 + 0x3ff;
    }
    CRC32_Init();
    iVar8 = 0;
    if (0 < (int)uVar9 >> 10) {
      do {
        sVar6 = fread(local_444,0x400,1,(FILE *)0x0);
        if (sVar6 != 1) {
          bVar3 = false;
          break;
        }
        CRC32_ProcessBuffer();
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar9 >> 10);
    }
    uVar7 = CRC32_Final();
    *(undefined4 *)(host_client + 0x5168) = uVar7;
  }
  MSG_WriteByte();
  if (bVar2) {
    MD5_Print();
    puVar10 = &stack0xfffffb1c;
  }
  else {
    if ((bVar3) && ((uVar5 & 0x3ff) == 0)) {
      va();
      pcStack_4f0 = (char *)(host_client + 0x78);
      ppcVar11 = &pcStack_4f0;
      goto LAB_0807d708;
    }
    puVar10 = &stack0xfffffb20;
  }
  *(undefined4 *)(puVar10 + -4) = 0x807d6fe;
  uVar7 = va();
  *(undefined4 *)(puVar10 + -4) = uVar7;
  ppcVar11 = (char **)(puVar10 + -8);
  *(int *)(puVar10 + -8) = host_client + 0x78;
LAB_0807d708:
  *(undefined4 *)((int)ppcVar11 + -4) = 0x807d70d;
  MSG_WriteString();
  *(undefined4 *)(host_client + 0x51b0) = 1;
  return 0;
}


// SV_CheckTimeouts  @ 08073ce0
void SV_CheckTimeouts(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  fVar1 = (float)realtime - (float)timeout._12_4_;
  iVar3 = 0;
  piVar2 = DAT_0816dd10;
  if (0 < svs) {
    do {
      if ((piVar2[0xfb0] == 0) && (((piVar2[2] != 0 || (*piVar2 != 0)) || (piVar2[1] != 0)))) {
        if ((float)piVar2[0xc] < fVar1) {
          SV_BroadcastPrintf("%s timed out\n",(int)piVar2 + 0x5005);
          SV_DropClient(piVar2,0);
        }
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x14ae;
    } while (iVar3 < svs);
  }
  return;
}


// SV_CheckVelocity  @ 0807a470
void SV_CheckVelocity(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((*(uint *)(param_1 + 0xfc + iVar2 * 4) & nanmask) == nanmask) {
      Con_Printf("Got a NaN velocity on %s\n",*(int *)(param_1 + 0xdc) + pr_strings);
      *(undefined4 *)(param_1 + 0xfc + iVar2 * 4) = 0;
    }
    if ((*(uint *)(param_1 + 0xe4 + iVar2 * 4) & nanmask) == nanmask) {
      Con_Printf("Got a NaN origin on %s\n",*(int *)(param_1 + 0xdc) + pr_strings);
      *(undefined4 *)(param_1 + 0xe4 + iVar2 * 4) = 0;
    }
    if (*(float *)(iVar2 * 4 + param_1 + 0xfc) <= (float)sv_maxvelocity._12_4_) {
      if (*(float *)(iVar2 * 4 + param_1 + 0xfc) < -(float)sv_maxvelocity._12_4_) {
        Con_DPrintf("Got a velocity too low on %s\n",*(int *)(param_1 + 0xdc) + pr_strings);
        fVar1 = -(float)sv_maxvelocity._12_4_;
        goto LAB_0807a594;
      }
    }
    else {
      Con_DPrintf("Got a velocity too high on %s\n",*(int *)(param_1 + 0xdc) + pr_strings);
      fVar1 = (float)sv_maxvelocity._12_4_;
LAB_0807a594:
      *(float *)(iVar2 * 4 + param_1 + 0xfc) = fVar1;
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return;
    }
  } while( true );
}


// SV_CheckWater  @ 0807bc60
bool SV_CheckWater(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_1 + 0x180) + *(float *)(param_1 + 0x18c)) * 0.5;
  local_c = (*(float *)(param_1 + 0x184) + *(float *)(param_1 + 400)) * 0.5;
  local_8 = *(float *)(param_1 + 0x188) + 1.0;
  *(undefined4 *)(param_1 + 0x27c) = 0;
  *(undefined4 *)(param_1 + 0x280) = 0xffffffff;
  iVar3 = SV_PointContents(&local_10);
  if (0xb < iVar3 + 0xeU) goto LAB_0807bdaa;
  *(int *)(param_1 + 0x280) = iVar3;
  *(undefined4 *)(param_1 + 0x27c) = 1;
  fVar1 = *(float *)(param_1 + 0x188);
  fVar2 = *(float *)(param_1 + 0x194);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
LAB_0807bd61:
    *(undefined4 *)(param_1 + 0x27c) = 3;
  }
  else {
    local_8 = (*(float *)(param_1 + 0x188) + *(float *)(param_1 + 0x194)) * 0.5;
    iVar4 = SV_PointContents(&local_10);
    if (iVar4 + 0xeU < 0xc) {
      *(undefined4 *)(param_1 + 0x27c) = 2;
      local_8 = local_8 + *(float *)(param_1 + 0x238);
      iVar4 = SV_PointContents(&local_10);
      if (iVar4 + 0xeU < 0xc) goto LAB_0807bd61;
    }
  }
  if (iVar3 + 0xeU < 6) {
    VectorMA(param_1 + 0x108,(float)*(int *)(param_1 + 0x27c) * 50.0,
             &current_table_120 + (-9 - iVar3) * 0xc,param_1 + 0x108);
  }
LAB_0807bdaa:
  return 1 < *(int *)(param_1 + 0x27c);
}


// SV_CheckWaterTransition  @ 0807c0c0
void SV_CheckWaterTransition(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_1 + 0x180) + *(float *)(param_1 + 0x18c)) * 0.5;
  local_c = (*(float *)(param_1 + 0x184) + *(float *)(param_1 + 400)) * 0.5;
  local_8 = *(float *)(param_1 + 0x188) + 1.0;
  iVar3 = SV_PointContents(&local_10);
  if (*(int *)(param_1 + 0x280) == 0) {
    *(int *)(param_1 + 0x280) = iVar3;
    *(undefined4 *)(param_1 + 0x27c) = 1;
  }
  else if (iVar3 + 0xeU < 0xc) {
    if (*(int *)(param_1 + 0x280) == -1) {
      SV_StartSound(param_1,0,"player/pl_wade1.wav",0xff,0x3f800000,0,100);
      *(float *)(param_1 + 0x104) = *(float *)(param_1 + 0x104) * 0.5;
    }
    *(int *)(param_1 + 0x280) = iVar3;
    *(undefined4 *)(param_1 + 0x27c) = 1;
    fVar1 = *(float *)(param_1 + 0x188);
    fVar2 = *(float *)(param_1 + 0x194);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      local_8 = (*(float *)(param_1 + 0x188) + *(float *)(param_1 + 0x194)) * 0.5;
      iVar3 = SV_PointContents(&local_10);
      if (0xb < iVar3 + 0xeU) {
        return;
      }
      *(undefined4 *)(param_1 + 0x27c) = 2;
      local_8 = local_8 + *(float *)(param_1 + 0x238);
      iVar3 = SV_PointContents(&local_10);
      if (0xb < iVar3 + 0xeU) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x27c) = 3;
  }
  else {
    if (*(int *)(param_1 + 0x280) != -1) {
      SV_StartSound(param_1,0,"player/pl_wade2.wav",0xff,0x3f800000,0,100);
    }
    *(undefined4 *)(param_1 + 0x280) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x27c) = 0;
  }
  return;
}


// SV_CleanupEnts  @ 080767d0
void SV_CleanupEnts(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  if (1 < DAT_08140434) {
    do {
      iVar2 = DAT_0814043c + iVar3 * 0x2c8;
      pbVar1 = (byte *)(iVar2 + 0x1d4);
      *pbVar1 = *pbVar1 & 0xfd;
      pbVar1 = (byte *)(iVar2 + 0x1d4);
      *pbVar1 = *pbVar1 & 0xdf;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_08140434);
  }
  return;
}


// SV_ClearClientStates  @ 08057cf0
void SV_ClearClientStates(void)

{
  int iVar1;
  int iVar2;
  
  if (0 < svs) {
    iVar2 = 0;
    iVar1 = DAT_0816dd10;
    do {
      COM_ClearCustomizationList(iVar1 + 0x5234,0);
      SV_ClearResourceLists(iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x52b8;
    } while (iVar2 < svs);
  }
  return;
}


// SV_ClearDatagram  @ 08073fb0
void SV_ClearDatagram(void)

{
  SZ_Clear(&DAT_08140444);
  return;
}


// SV_ClearEntities  @ 08078890
void SV_ClearEntities(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_08140434) {
    do {
      piVar1 = (int *)(DAT_0814043c + iVar2 * 0x2c8);
      if (*piVar1 == 0) {
        ReleaseEntityDLLFields(piVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_08140434);
  }
  return;
}


// SV_ClearFrames  @ 08070770
void SV_ClearFrames(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    iVar1 = *param_1;
    if (0 < SV_UPDATE_BACKUP) {
      iVar2 = 0;
      do {
        SV_ClearPacketEntities(iVar1);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x18;
      } while (iVar2 < SV_UPDATE_BACKUP);
    }
    free((void *)*param_1);
    *param_1 = 0;
  }
  return;
}


// SV_ClearPacketEntities  @ 080706c0
void SV_ClearPacketEntities(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x14) != 0) {
      free(*(void **)(param_1 + 0x14));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}


// SV_ClearResourceList  @ 0807e1c0
void SV_ClearResourceList(void *param_1)

{
  void *pvVar1;
  void *__ptr;
  
  __ptr = *(void **)((int)param_1 + 0x60);
  while ((__ptr != (void *)0x0 && (__ptr != param_1))) {
    pvVar1 = *(void **)((int)__ptr + 0x60);
    SV_RemoveFromResourceList(__ptr);
    free(__ptr);
    __ptr = pvVar1;
  }
  *(void **)((int)param_1 + 100) = param_1;
  *(void **)((int)param_1 + 0x60) = param_1;
  return;
}


// SV_ClearResourceLists  @ 0807dd80
void SV_ClearResourceLists(int param_1)

{
  if (param_1 == 0) {
    Sys_Error("SV_ClearResourceLists with NULL client!");
  }
  SV_ClearResourceList(param_1 + 0x50b8);
  SV_ClearResourceList(param_1 + 0x5050);
  return;
}


// SV_ClearWorld  @ 080830b0
void SV_ClearWorld(void)

{
  SV_InitBoxHull();
  memset(&sv_areanodes,0,0x400);
  sv_numareanodes = 0;
  SV_CreateAreaNode(0,DAT_0811d320 + 0x54,DAT_0811d320 + 0x60);
  return;
}


// SV_ClientPrintf  @ 08057770
void SV_ClientPrintf(char *param_1)

{
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  MSG_WriteByte(host_client + 0x78,8);
  MSG_WriteString(host_client + 0x78,local_404);
  return;
}


// SV_ClipMoveToEntity  @ 08085370
undefined4 *
SV_ClipMoveToEntity(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_3c [14];
  
  SV_SingleClipMoveToEntity(param_2,param_3,param_4,param_5,param_6,local_3c);
  puVar2 = local_3c;
  puVar3 = param_1;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// SV_ClipToLinks  @ 080853c0
/* WARNING: Removing unreachable block (ram,0x08085856) */

void SV_ClipToLinks(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar6;
  float *pfVar7;
  float *pfVar8;
  int aiStack_78 [2];
  float afStack_70 [5];
  float local_48;
  int local_44;
  float local_38;
  int *local_18;
  int *local_10;
  int *local_c;
  int *local_8;
  undefined1 *puVar5;
  
  puVar6 = &stack0xffffffa4;
  local_8 = (int *)param_1[7];
  do {
    if (local_8 == param_1 + 6) {
      if (*param_1 != -1) {
        if ((float)param_1[1] < param_2[*param_1 + 3]) {
          *(float **)(puVar6 + -4) = param_2;
          *(int *)(puVar6 + -8) = param_1[2];
          *(undefined4 *)(puVar6 + -0xc) = 0x80858f6;
          SV_ClipToLinks();
        }
        fVar1 = param_2[*param_1];
        fVar2 = (float)param_1[1];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
          *(float **)(puVar6 + -4) = param_2;
          *(int *)(puVar6 + -8) = param_1[3];
          *(undefined4 *)(puVar6 + -0xc) = 0x8085949;
          SV_ClipToLinks();
        }
      }
      return;
    }
    local_c = (int *)local_8[1];
    local_10 = local_8 + -2;
    if ((local_8[0x70] != 0) && (local_10 != (int *)param_2[0x1f])) {
      if (local_8[0x70] == 1) {
        *(char **)(puVar6 + -4) = "Trigger in clipping list";
        *(undefined4 *)(puVar6 + -8) = 0x808546c;
        Sys_Error();
      }
      if (local_10[0x72] == 4) {
        if (((local_10[0x98] & 0x800000U) == 0) || (param_2[0x20] != 0.0)) {
LAB_08085500:
          if ((((*(short *)((int)param_2 + 0x7a) == 0) || (local_10[0x81] == 0)) ||
              ((local_10[0x98] & 0x2000000U) != 0)) &&
             (((*param_2 <= (float)local_10[99] && (param_2[1] <= (float)local_10[100])) &&
              (param_2[2] <= (float)local_10[0x65])))) {
            fVar1 = param_2[3];
            fVar2 = (float)local_10[0x60];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
              fVar1 = param_2[4];
              fVar2 = (float)local_10[0x61];
              if ((byte)(fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
                fVar1 = param_2[5];
                fVar2 = (float)local_10[0x62];
                if (((byte)(fVar1 < fVar2 |
                            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
                   (((param_2[0x1f] == 0.0 ||
                     (fVar1 = *(float *)((int)param_2[0x1f] + 0x1b0),
                     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) ||
                    ((byte)((byte)((ushort)((ushort)NAN((float)local_10[0x6c]) << 10) >> 8) |
                           (byte)((ushort)((ushort)((float)local_10[0x6c] == 0.0) << 0xe) >> 8)) !=
                     0x40)))) {
                  if (param_2[0x10] != 0.0) {
                    return;
                  }
                  if ((param_2[0x1f] == 0.0) ||
                     (((float)local_10[0x95] != param_2[0x1f] &&
                      (*(int **)((int)param_2[0x1f] + 0x254) != local_10)))) {
                    if ((local_10[0x98] & 0x20U) == 0) {
                      *(float *)(puVar6 + -4) = param_2[0xf];
                      *(float *)(puVar6 + -8) = param_2[7];
                      *(float *)(puVar6 + -0xc) = param_2[6];
                      *(float *)(puVar6 + -0x10) = param_2[0xe];
                      *(int **)(puVar6 + -0x14) = local_10;
                      *(float **)(puVar6 + -0x18) = &local_48;
                      *(undefined4 *)(puVar6 + -0x1c) = 0x80857a7;
                      SV_ClipMoveToEntity();
                    }
                    else {
                      *(float *)(puVar6 + -4) = param_2[0xf];
                      *(float **)(puVar6 + -8) = param_2 + 0xb;
                      *(float **)(puVar6 + -0xc) = param_2 + 8;
                      *(float *)(puVar6 + -0x10) = param_2[0xe];
                      *(int **)(puVar6 + -0x14) = local_10;
                      *(float **)(puVar6 + -0x18) = &local_48;
                      *(undefined4 *)(puVar6 + -0x1c) = 0x8085751;
                      SV_ClipMoveToEntity();
                    }
                    puVar4 = puVar6 + -4;
                    puVar5 = puVar6 + -4;
                    if (((local_48 != 0.0) || (local_44 != 0)) ||
                       (fVar1 = param_2[0x14], puVar6 = puVar6 + -4,
                       (byte)(local_38 < fVar1 |
                              (byte)((ushort)((ushort)(NAN(local_38) || NAN(fVar1)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(local_38 == fVar1) << 0xe) >> 8)) == 1)) {
                      local_18 = local_10;
                      if (param_2[0x11] == 0.0) {
                        pfVar7 = &local_48;
                        pfVar8 = param_2 + 0x10;
                        for (iVar3 = 0xe; puVar6 = puVar5, iVar3 != 0; iVar3 = iVar3 + -1) {
                          *pfVar8 = *pfVar7;
                          pfVar7 = pfVar7 + 1;
                          pfVar8 = pfVar8 + 1;
                        }
                      }
                      else {
                        pfVar7 = &local_48;
                        pfVar8 = param_2 + 0x10;
                        for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
                          *pfVar8 = *pfVar7;
                          pfVar7 = pfVar7 + 1;
                          pfVar8 = pfVar8 + 1;
                        }
                        param_2[0x11] = 1.4013e-45;
                        puVar6 = puVar4;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if ((*(short *)(param_2 + 0x1e) != 1) || (local_10[0x71] == 0xd)) goto LAB_08085500;
    }
    local_8 = local_c;
  } while( true );
}


// SV_ClipToWorldbrush  @ 08085960
/* WARNING: Removing unreachable block (ram,0x08085bf6) */

void SV_ClipToWorldbrush(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar6;
  float *pfVar7;
  float *pfVar8;
  int aiStack_78 [2];
  float afStack_70 [5];
  float local_48;
  int local_44;
  float local_38;
  int *local_18;
  int *local_10;
  int *local_c;
  int *local_8;
  undefined1 *puVar5;
  
  puVar6 = &stack0xffffffa4;
  local_8 = (int *)param_1[7];
  do {
    if (local_8 == param_1 + 6) {
      if (*param_1 != -1) {
        if ((float)param_1[1] < param_2[*param_1 + 3]) {
          *(float **)(puVar6 + -4) = param_2;
          *(int *)(puVar6 + -8) = param_1[2];
          *(undefined4 *)(puVar6 + -0xc) = 0x8085c96;
          SV_ClipToWorldbrush();
        }
        fVar1 = param_2[*param_1];
        fVar2 = (float)param_1[1];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
          *(float **)(puVar6 + -4) = param_2;
          *(int *)(puVar6 + -8) = param_1[3];
          *(undefined4 *)(puVar6 + -0xc) = 0x8085ce9;
          SV_ClipToWorldbrush();
        }
      }
      return;
    }
    local_c = (int *)local_8[1];
    local_10 = local_8 + -2;
    if (((((local_8[0x70] == 4) && (local_10 != (int *)param_2[0x1f])) &&
         ((local_8[0x96] & 0x2000000U) != 0)) &&
        ((*param_2 <= (float)local_8[0x61] && (param_2[1] <= (float)local_8[0x62])))) &&
       (param_2[2] <= (float)local_8[99])) {
      fVar1 = param_2[3];
      fVar2 = (float)local_8[0x5e];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        fVar1 = param_2[4];
        fVar2 = (float)local_8[0x5f];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          fVar1 = param_2[5];
          fVar2 = (float)local_8[0x60];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            if (param_2[0x10] != 0.0) {
              return;
            }
            *(float *)(puVar6 + -4) = param_2[0xf];
            *(float *)(puVar6 + -8) = param_2[7];
            *(float *)(puVar6 + -0xc) = param_2[6];
            *(float *)(puVar6 + -0x10) = param_2[0xe];
            *(int **)(puVar6 + -0x14) = local_10;
            *(float **)(puVar6 + -0x18) = &local_48;
            *(undefined4 *)(puVar6 + -0x1c) = 0x8085b47;
            SV_ClipMoveToEntity();
            puVar4 = puVar6 + -4;
            puVar5 = puVar6 + -4;
            if (((local_48 != 0.0) || (local_44 != 0)) ||
               (fVar1 = param_2[0x14], puVar6 = puVar6 + -4,
               (byte)(local_38 < fVar1 |
                      (byte)((ushort)((ushort)(NAN(local_38) || NAN(fVar1)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(local_38 == fVar1) << 0xe) >> 8)) == 1)) {
              local_18 = local_10;
              if (param_2[0x11] == 0.0) {
                pfVar7 = &local_48;
                pfVar8 = param_2 + 0x10;
                for (iVar3 = 0xe; puVar6 = puVar5, iVar3 != 0; iVar3 = iVar3 + -1) {
                  *pfVar8 = *pfVar7;
                  pfVar7 = pfVar7 + 1;
                  pfVar8 = pfVar8 + 1;
                }
              }
              else {
                pfVar7 = &local_48;
                pfVar8 = param_2 + 0x10;
                for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
                  *pfVar8 = *pfVar7;
                  pfVar7 = pfVar7 + 1;
                  pfVar8 = pfVar8 + 1;
                }
                param_2[0x11] = 1.4013e-45;
                puVar6 = puVar4;
              }
            }
          }
        }
      }
    }
    local_8 = local_c;
  } while( true );
}


// SV_CloseEnough  @ 08079e40
undefined4 SV_CloseEnough(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    fVar2 = param_3 + *(float *)(param_1 + 0x18c + iVar3 * 4);
    fVar1 = *(float *)(param_2 + 0x180 + iVar3 * 4);
    if (((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) ||
       (*(float *)(param_2 + 0x18c + iVar3 * 4) < *(float *)(param_1 + 0x180 + iVar3 * 4) - param_3)
       ) break;
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      return 1;
    }
  }
  return 0;
}


// SV_ConnectClient  @ 08072460
/* WARNING: Removing unreachable block (ram,0x08072c46) */
/* WARNING: Removing unreachable block (ram,0x08072c5a) */
/* WARNING: Removing unreachable block (ram,0x08072c5c) */
/* WARNING: Removing unreachable block (ram,0x0807295e) */
/* WARNING: Removing unreachable block (ram,0x08072972) */
/* WARNING: Removing unreachable block (ram,0x08072982) */
/* WARNING: Removing unreachable block (ram,0x08072984) */
/* WARNING: Removing unreachable block (ram,0x08072dc2) */

void SV_ConnectClient(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  char **ppcVar13;
  int *piVar14;
  char *apcStack_71c [2];
  int *piStack_714;
  char *pcStack_710;
  char *pcStack_70c;
  int local_6b4;
  int *local_6ac;
  int *local_6a8;
  char local_698 [512];
  char local_498 [127];
  undefined1 local_419;
  char local_418 [1024];
  undefined4 local_18 [5];
  
  local_6b4 = 0;
  puVar10 = &net_from;
  puVar12 = local_18;
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar12 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar12 = puVar12 + 1;
  }
  Cmd_Argv();
  iVar5 = __strtol_internal();
  if ((iVar5 == PROTOCOL_VERSION) && (iVar5 = Cmd_Argc(), 6 < iVar5)) {
    Cmd_Argv();
    iVar5 = __strtol_internal();
    puVar10 = local_18;
    puVar12 = (undefined4 *)&stack0xfffff8fc;
    for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    iVar6 = NET_IsLocalAddress();
    if (iVar6 == 0) {
      iVar6 = 0;
      do {
        puVar10 = &DAT_08166d10 + iVar6 * 7;
        puVar12 = (undefined4 *)&stack0xfffff8fc;
        for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        puVar10 = &net_from;
        ppcVar13 = apcStack_71c + 1;
        for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
          *ppcVar13 = (char *)*puVar10;
          puVar10 = puVar10 + 1;
          ppcVar13 = ppcVar13 + 1;
        }
        apcStack_71c[0] = (char *)0x8072562;
        iVar7 = NET_CompareBaseAdr();
        if (iVar7 != 0) {
          if (iVar5 != *(int *)(&DAT_08166d24 + iVar6 * 0x1c)) goto LAB_08072af7;
          break;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x400);
      if (iVar6 == 0x400) goto LAB_08072af7;
    }
    if (((gfUseLANAuthentication != 0) ||
        ((byte)(0.0 < (float)sv_lan._12_4_ |
                (byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
       (net_from == 3)) {
      puVar10 = &net_local_adr;
      puVar12 = (undefined4 *)&stack0xfffff8fc;
      for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar10 = &net_from;
      ppcVar13 = apcStack_71c + 1;
      for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppcVar13 = (char *)*puVar10;
        puVar10 = puVar10 + 1;
        ppcVar13 = ppcVar13 + 1;
      }
      apcStack_71c[0] = (char *)0x8072601;
      iVar5 = NET_CompareClassBAdr();
      if (iVar5 == 0) {
        puVar10 = &net_from;
        puVar12 = (undefined4 *)&stack0xfffff8fc;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        iVar5 = NET_IsReservedAdr();
        if (iVar5 == 0) goto LAB_08072af7;
      }
    }
    iVar5 = 0;
    local_6ac = DAT_0816dd10;
    if (0 < svs) {
      do {
        if (((*local_6ac != 0) || (local_6ac[1] != 0)) || (local_6ac[2] != 0)) {
          piVar11 = local_6ac + 5;
          piVar14 = (int *)&stack0xfffff8fc;
          for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar14 = *piVar11;
            piVar11 = piVar11 + 1;
            piVar14 = piVar14 + 1;
          }
          puVar10 = local_18;
          ppcVar13 = apcStack_71c + 1;
          for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
            *ppcVar13 = (char *)*puVar10;
            puVar10 = puVar10 + 1;
            ppcVar13 = ppcVar13 + 1;
          }
          apcStack_71c[0] = (char *)0x807268e;
          iVar6 = NET_CompareAdr();
          if (iVar6 != 0) {
            puVar10 = local_18;
            puVar12 = (undefined4 *)&stack0xfffff8fc;
            for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar12 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar12 = puVar12 + 1;
            }
            NET_AdrToString();
            pcStack_70c = "%s:reconnect\n";
            pcStack_710 = "j";
            Con_Printf();
            pcStack_710 = (char *)0x0;
            piStack_714 = local_6ac;
            apcStack_71c[1] = (char *)0x80726c5;
            SV_DropClient();
          }
        }
        iVar5 = iVar5 + 1;
        local_6ac = local_6ac + 0x14ae;
      } while (iVar5 < svs);
    }
    pcVar2 = (char *)Cmd_Argv();
    if (((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) &&
       ((iVar5 = __strtol_internal(), 0 < iVar5 &&
        (((iVar5 < 3 && (pcVar2 = (char *)Cmd_Argv(), pcVar2 != (char *)0x0)) && (*pcVar2 != '\0')))
        ))) {
      iVar6 = __strtol_internal();
      pcVar2 = (char *)Cmd_Argv();
      if (((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) &&
         ((iVar7 = __strtol_internal(), 0 < iVar7 &&
          ((iVar7 < 0x401 && (pcVar2 = (char *)Cmd_Argv(), pcVar2 != (char *)0x0)))))) {
        pcVar3 = local_698;
        for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {
          pcVar3[0] = '\0';
          pcVar3[1] = '\0';
          pcVar3[2] = '\0';
          pcVar3[3] = '\0';
          pcVar3 = pcVar3 + 4;
        }
        strcpy(local_698,pcVar2);
        pcVar2 = (char *)Cmd_Argv();
        pcStack_70c = (char *)0x80727ea;
        strncpy(local_418,pcVar2,0x3ff);
        pcStack_70c = "spectator";
        piStack_714 = (int *)0x80727f5;
        pcStack_710 = local_418;
        Info_ValueForKey();
        puVar10 = local_18;
        puVar12 = (undefined4 *)&stack0xfffff8fc;
        for (iVar8 = 5; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        iVar8 = NET_IsLocalAddress();
        if (((iVar8 == 0) && (*(char *)sv_password._4_4_ != '\0')) &&
           (iVar8 = strcasecmp((char *)sv_password._4_4_,"none"), iVar8 != 0)) {
          pcVar2 = (char *)Info_ValueForKey();
          iVar8 = strcmp((char *)sv_password._4_4_,pcVar2);
          if (iVar8 != 0) {
            puVar10 = &net_from;
            puVar12 = (undefined4 *)&stack0xfffff8fc;
            for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar12 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar12 = puVar12 + 1;
            }
            NET_AdrToString();
            pcStack_70c = "%s:  password failed\n";
            pcStack_710 = (char *)0x807288a;
            Con_Printf();
            pcStack_710 = (char *)&net_from;
            piStack_714 = (int *)0x8072894;
            SV_RejectConnectionForPassword();
            return;
          }
        }
        Info_RemoveKey();
        pcVar3 = (char *)Info_ValueForKey();
        pcVar2 = local_498;
        for (iVar8 = 0x20; iVar8 != 0; iVar8 = iVar8 + -1) {
          pcVar2[0] = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          pcVar2 = pcVar2 + 4;
        }
        if (pcVar3 == (char *)0x0) {
          builtin_strncpy(local_498,"unconnected",0xc);
        }
        else {
          strncpy(local_498,pcVar3,0x80);
          local_419 = 0;
        }
        SV_CountPlayers();
        iVar8 = 0;
        if (0 < svs) {
          do {
            local_6a8 = DAT_0816dd10 + iVar8 * 0x14ae;
            if (((*local_6a8 == 0) && (local_6a8[1] == 0)) && (local_6a8[2] == 0)) break;
            iVar8 = iVar8 + 1;
          } while (iVar8 < svs);
        }
        if (iVar8 == svs) {
          SV_RejectConnection();
          return;
        }
        iVar8 = EDICT_NUM();
        if ((iVar5 == 1) || (iVar5 != 2)) {
          iVar7 = WON_CheckAuthentication();
          if (iVar7 == 0) {
            SV_RejectConnection();
            return;
          }
LAB_08072b10:
          host_client = local_6a8;
          SV_ClearResourceLists();
          SV_ClearFrames();
          piVar11 = local_6a8;
          for (iVar7 = 0x14ae; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar11 = 0;
            piVar11 = piVar11 + 1;
          }
          pvVar4 = malloc(SV_UPDATE_BACKUP * 0x18);
          local_6a8[0x13c1] = (int)pvVar4;
          pcStack_70c = (char *)0x8072b7e;
          memset((void *)local_6a8[0x13c1],0,SV_UPDATE_BACKUP * 0x18);
          local_6a8[0x1447] = (int)(local_6a8 + 0x142e);
          local_6a8[0x1446] = (int)(local_6a8 + 0x142e);
          local_6a8[0x142d] = (int)(local_6a8 + 0x1414);
          local_6a8[0x142c] = (int)(local_6a8 + 0x1414);
          puVar10 = local_18;
          ppcVar13 = apcStack_71c;
          for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
            *ppcVar13 = (char *)*puVar10;
            puVar10 = puVar10 + 1;
            ppcVar13 = ppcVar13 + 1;
          }
          Netchan_Setup(1,local_6a8 + 5);
          puVar10 = local_18;
          ppcVar13 = &pcStack_70c;
          for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
            *ppcVar13 = (char *)*puVar10;
            puVar10 = puVar10 + 1;
            ppcVar13 = ppcVar13 + 1;
          }
          pcStack_710 = (char *)0x1;
          piStack_714 = (int *)0x8072bf5;
          Netchan_OutOfBandPrint();
          pcVar2 = "loopback";
          piVar11 = local_6a8 + 5;
          piVar14 = (int *)&stack0xfffff8f8;
          for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar14 = *piVar11;
            piVar11 = piVar11 + 1;
            piVar14 = piVar14 + 1;
          }
          pcStack_70c = (char *)0x8072c11;
          pcVar3 = (char *)NET_AdrToString();
          iVar7 = strcasecmp(pcVar3,pcVar2);
          if (iVar7 == 0) {
            Con_DPrintf();
          }
          else {
            piVar11 = local_6a8 + 5;
            piVar14 = (int *)&stack0xfffff8fc;
            for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
              *piVar14 = *piVar11;
              piVar11 = piVar11 + 1;
              piVar14 = piVar14 + 1;
            }
            NET_AdrToString();
            pcStack_70c = local_498;
            pcStack_710 = "Client %s connected\nAdr: %s\n";
            piStack_714 = (int *)0x8072c9d;
            Con_DPrintf();
          }
          if ((iVar5 != 1) && (iVar5 == 2)) {
            strncpy((char *)(local_6a8 + 0x13f9),local_698,0x20);
            *(undefined1 *)(local_6a8 + 0x1401) = 0;
          }
          *local_6a8 = 0;
          local_6a8[1] = 0;
          local_6a8[2] = 1;
          local_6a8[3] = 0;
          local_6a8[0x13c2] = iVar8;
          local_6a8[0xfcd] = 0;
          local_6a8[0x13c4] = g_userid;
          g_userid = g_userid + 1;
          local_6a8[0x13c5] = iVar6;
          piVar11 = local_6a8 + 5;
          piVar14 = (int *)&stack0xfffff8fc;
          for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar14 = *piVar11;
            piVar11 = piVar11 + 1;
            piVar14 = piVar14 + 1;
          }
          NET_AdrToString();
          pcStack_70c = (char *)local_6a8[0x13c5];
          pcStack_710 = (char *)local_6a8[0x13c4];
          piStack_714 = (int *)local_498;
          apcStack_71c[1] = "\"%s<%i><WON:%u>\" connected, address \"%s\"\n";
          apcStack_71c[0] = (char *)0x8072d7d;
          Log_Printf();
          strncpy((char *)(local_6a8 + 0x13c6),local_418,0xc4);
          SV_ExtractFromUserinfo();
          local_6a8[0xfaf] = 0;
          local_6a8[0xfd1] = 1;
          local_6a8[0xfd3] = (int)(local_6a8 + 0xfd6);
          local_6a8[0xfd4] = 4000;
          local_6a8[0xfad] = 0;
          if (DAT_0811d248 != 0) {
            return;
          }
          (*DAT_08178f04)();
          return;
        }
        iVar9 = -1;
        pcVar2 = local_698;
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        if ((iVar9 == -0x22) && (iVar7 == 0x20)) {
          iVar7 = 0;
          local_6ac = DAT_0816dd10;
          if (0 < svs) {
            do {
              if ((((*local_6ac != 0) || (local_6ac[1] != 0)) || (local_6ac[2] != 0)) &&
                 (iVar9 = strncasecmp(local_698,(char *)(local_6ac + 0x13f9),0x20), iVar9 == 0)) {
                local_6b4 = local_6b4 + 1;
              }
              iVar7 = iVar7 + 1;
              local_6ac = local_6ac + 0x14ae;
            } while (iVar7 < svs);
          }
          if (local_6b4 < 5) goto LAB_08072b10;
        }
      }
    }
  }
LAB_08072af7:
  SV_RejectConnection();
  return;
}


// SV_ConnectionlessPacket  @ 080737d0
void SV_ConnectionlessPacket(void)

{
  char cVar1;
  char *pcVar2;
  byte *__s1;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  char *pcVar7;
  byte *pbVar8;
  char **ppcVar9;
  bool bVar10;
  bool bVar11;
  char *apcStack_34 [4];
  
  MSG_BeginReading();
  MSG_ReadLong();
  pcVar2 = (char *)MSG_ReadStringLine();
  Cmd_TokenizeString();
  apcStack_34[3] = (char *)0x80737fb;
  __s1 = (byte *)Cmd_Argv();
  iVar4 = 5;
  bVar10 = false;
  uVar3 = 0;
  bVar11 = true;
  pbVar5 = __s1;
  pbVar8 = &DAT_080a46f6;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar10 = *pbVar5 < *pbVar8;
    bVar11 = *pbVar5 == *pbVar8;
    pbVar5 = pbVar5 + 1;
    pbVar8 = pbVar8 + 1;
  } while (bVar11);
  if (!bVar11) {
    uVar3 = -(uint)bVar10 | 1;
  }
  if ((uVar3 == 0) || ((*__s1 == 0x69 && ((__s1[1] == 0 || (__s1[1] == 10)))))) {
    SVC_Ping();
  }
  else if ((*__s1 == 0x6c) && ((__s1[1] == 0 || (__s1[1] == 10)))) {
    MSG_BeginReading();
    MSG_ReadLong();
    MSG_ReadByte();
    MSG_ReadString();
    Con_DPrintf();
  }
  else if ((*__s1 == 0x6a) && ((__s1[1] == 0 || (__s1[1] == 10)))) {
    puVar6 = &net_from;
    ppcVar9 = apcStack_34 + 1;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppcVar9 = (char *)*puVar6;
      puVar6 = puVar6 + 1;
      ppcVar9 = ppcVar9 + 1;
    }
    apcStack_34[0] = (char *)0x80738a8;
    apcStack_34[0] = (char *)NET_AdrToString();
    Con_Printf("A2A_ACK from %s\n");
  }
  else if ((*__s1 == 0x73) && ((__s1[1] == 0 || (__s1[1] == 10)))) {
    SVC_Heartbeat();
  }
  else {
    apcStack_34[3] = (char *)0x80738eb;
    iVar4 = strcasecmp((char *)__s1,"log");
    if (iVar4 == 0) {
      if (((byte)(0.0 < (float)sv_logrelay._12_4_ |
                  (byte)((ushort)((ushort)NAN((float)sv_logrelay._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)sv_logrelay._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
         && (pcVar2 != (char *)0x0)) {
        uVar3 = 0xffffffff;
        pcVar7 = pcVar2;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        if (4 < ~uVar3 - 1) {
          if ((pcVar2 != (char *)0xfffffffc) && (pcVar2[4] != '\0')) {
            apcStack_34[3] = (char *)0x8073956;
            Con_Printf();
          }
        }
      }
    }
    else {
      iVar4 = WON_IsAuthMessage();
      if (iVar4 == 0) {
        iVar4 = 7;
        bVar10 = true;
        pbVar5 = __s1;
        pbVar8 = (byte *)"status";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar10 = *pbVar5 == *pbVar8;
          pbVar5 = pbVar5 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (bVar10) {
          SVC_Status();
        }
        else {
          iVar4 = 0xd;
          bVar10 = true;
          pbVar5 = __s1;
          pbVar8 = (byte *)"getchallenge";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar10 = *pbVar5 == *pbVar8;
            pbVar5 = pbVar5 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar10);
          if (bVar10) {
            SVC_GetChallenge();
          }
          else {
            apcStack_34[3] = (char *)0x80739cb;
            iVar4 = strcasecmp((char *)__s1,"info");
            if (iVar4 == 0) {
              SVC_Info();
            }
            else {
              apcStack_34[3] = (char *)0x80739eb;
              iVar4 = strcasecmp((char *)__s1,"details");
              if (iVar4 == 0) {
                SVC_Info();
              }
              else {
                apcStack_34[3] = (char *)0x8073a0b;
                iVar4 = strcasecmp((char *)__s1,"players");
                if (iVar4 == 0) {
                  SVC_PlayerInfo();
                }
                else {
                  apcStack_34[3] = (char *)0x8073a2b;
                  iVar4 = strcasecmp((char *)__s1,"rules");
                  if (iVar4 == 0) {
                    SVC_RuleInfo();
                  }
                  else {
                    iVar4 = 8;
                    bVar10 = true;
                    pbVar5 = __s1;
                    pbVar8 = (byte *)"connect";
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar10 = *pbVar5 == *pbVar8;
                      pbVar5 = pbVar5 + 1;
                      pbVar8 = pbVar8 + 1;
                    } while (bVar10);
                    if (bVar10) {
                      SV_ConnectClient();
                    }
                    else {
                      iVar4 = 5;
                      bVar10 = true;
                      pbVar5 = &DAT_080a4747;
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar10 = *__s1 == *pbVar5;
                        __s1 = __s1 + 1;
                        pbVar5 = pbVar5 + 1;
                      } while (bVar10);
                      if (bVar10) {
                        Host_RemoteCommand();
                      }
                      else {
                        puVar6 = &net_from;
                        ppcVar9 = apcStack_34;
                        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
                          *ppcVar9 = (char *)*puVar6;
                          puVar6 = puVar6 + 1;
                          ppcVar9 = ppcVar9 + 1;
                        }
                        NET_AdrToString();
                        apcStack_34[3] = "bad connectionless packet from %s:\n%s\n";
                        apcStack_34[2] = (char *)0x8073aab;
                        Con_Printf();
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        WON_ParseAuthenticationMessage();
      }
    }
  }
  return;
}


// SV_CountPlayers  @ 08071030
void SV_CountPlayers(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  *param_1 = 0;
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  iVar2 = 0;
  piVar1 = DAT_0816dd10;
  if (0 < svs) {
    do {
      if ((((*piVar1 != 0) || (piVar1[1] != 0)) || (piVar1[2] != 0)) &&
         ((*param_1 = *param_1 + 1, piVar1[0xfaf] != 0 && (param_2 != (int *)0x0)))) {
        *param_2 = *param_2 + 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x14ae;
    } while (iVar2 < svs);
  }
  return;
}


// SV_CreateAreaNode  @ 08082dd0
int * SV_CreateAreaNode(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float local_44;
  float local_40;
  float local_3c;
  float local_38 [4];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  int *local_8;
  
  iVar2 = sv_numareanodes * 0x20;
  local_8 = &sv_areanodes + sv_numareanodes * 8;
  sv_numareanodes = sv_numareanodes + 1;
  ClearLink(&DAT_081782b0 + iVar2);
  ClearLink(local_8 + 6);
  if (param_1 == 4) {
    *local_8 = -1;
    local_8[3] = 0;
    local_8[2] = 0;
  }
  else {
    local_14 = *param_3 - *param_2;
    local_10 = param_3[1] - param_2[1];
    local_c = param_3[2] - param_2[2];
    if (local_14 <= local_10) {
      *local_8 = 1;
    }
    else {
      *local_8 = 0;
    }
    local_8[1] = (int)((param_3[*local_8] + param_2[*local_8]) * 0.5);
    local_20 = *param_2;
    local_1c = param_2[1];
    local_18 = param_2[2];
    local_38[0] = *param_2;
    local_38[1] = param_2[1];
    local_38[2] = param_2[2];
    local_38[3] = *param_3;
    local_28 = param_3[1];
    local_24 = param_3[2];
    local_44 = *param_3;
    local_40 = param_3[1];
    local_3c = param_3[2];
    iVar2 = *local_8;
    fVar1 = (float)local_8[1];
    local_38[*local_8] = fVar1;
    local_38[iVar2 + 3] = fVar1;
    iVar2 = SV_CreateAreaNode(param_1 + 1,local_38,&local_44);
    local_8[2] = iVar2;
    iVar2 = SV_CreateAreaNode(param_1 + 1,local_38 + 6,local_38 + 3);
    local_8[3] = iVar2;
  }
  return local_8;
}


// SV_CreateBaseline  @ 08077a20
void SV_CreateBaseline(void)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  int local_14;
  uint local_10;
  
  for (local_14 = 0; local_14 < DAT_08140434; local_14 = local_14 + 1) {
    piVar1 = (int *)(DAT_0814043c + local_14 * 0x2c8);
    if ((*piVar1 == 0) && ((local_14 <= svs || (piVar1[0x5c] != 0)))) {
      piVar1[0x11] = 0;
      if ((*(byte *)((int)piVar1 + 0x263) & 0x20) != 0) {
        piVar1[0x11] = 1;
      }
      piVar1[0x14] = piVar1[0x39];
      piVar1[0x15] = piVar1[0x3a];
      piVar1[0x16] = piVar1[0x3b];
      piVar1[0x17] = piVar1[0x4b];
      piVar1[0x18] = piVar1[0x4c];
      piVar1[0x19] = piVar1[0x4d];
      piVar1[0x2e] = piVar1[0x66];
      piVar1[0x2f] = piVar1[0x67];
      piVar1[0x30] = piVar1[0x68];
      piVar1[0x31] = piVar1[0x69];
      piVar1[0x32] = piVar1[0x6a];
      piVar1[0x33] = piVar1[0x6b];
      piVar1[0x1c] = piVar1[0x7b];
      piVar1[0x20] = piVar1[0x80];
      *(short *)(piVar1 + 0x1e) = (short)piVar1[0x73];
      *(ushort *)((int)piVar1 + 0x7a) = (ushort)*(byte *)(piVar1 + 0x72);
      if ((local_14 < 1) || (svs < local_14)) {
        piVar1[0x1d] = 0;
        pcVar3 = (char *)(piVar1[0x5d] + pr_strings);
      }
      else {
        piVar1[0x1d] = local_14;
        pcVar3 = "models/player.mdl";
      }
      iVar2 = SV_ModelIndex(pcVar3);
      piVar1[0x1a] = iVar2;
      piVar1[0x21] = (uint)*(byte *)(piVar1 + 0x81);
      local_10 = (uint)(longlong)ROUND((float)piVar1[0x82]);
      piVar1[0x22] = local_10 & 0xff;
      *(char *)(piVar1 + 0x23) = (char)(longlong)ROUND((float)piVar1[0x83]);
      *(char *)((int)piVar1 + 0x8d) = (char)(longlong)ROUND((float)piVar1[0x84]);
      *(char *)((int)piVar1 + 0x8e) = (char)(longlong)ROUND((float)piVar1[0x85]);
      piVar1[0x24] = (uint)*(byte *)(piVar1 + 0x86);
      SV_FlushSignon();
      MSG_WriteByte(&DAT_08143774,0x16);
      MSG_WriteShort(&DAT_08143774,local_14);
      MSG_WriteByte(&DAT_08143774,piVar1[0x11]);
      MSG_WriteShort(&DAT_08143774,piVar1[0x1a]);
      MSG_WriteByte(&DAT_08143774,piVar1[0x1b]);
      piVar1[0x1b] = (uint)*(byte *)(piVar1 + 0x1b);
      MSG_WriteByte(&DAT_08143774,(int)ROUND((float)piVar1[0x1c]));
      local_10 = (uint)(longlong)ROUND((float)piVar1[0x1c]);
      piVar1[0x1c] = (int)(float)(local_10 & 0xff);
      if (piVar1[0x11] == 0) {
        MSG_WriteWord(&DAT_08143774,(int)ROUND((float)piVar1[0x20] * 256.0));
      }
      else {
        MSG_WriteByte(&DAT_08143774,(int)ROUND((float)piVar1[0x20]));
      }
      MSG_WriteWord(&DAT_08143774,piVar1[0x1d]);
      MSG_WriteShort(&DAT_08143774,(int)(short)piVar1[0x1e]);
      MSG_WriteByte(&DAT_08143774,(int)*(short *)((int)piVar1 + 0x7a));
      *(ushort *)((int)piVar1 + 0x7a) = (ushort)*(byte *)((int)piVar1 + 0x7a);
      iVar2 = 0;
      do {
        MSG_WriteCoord(&DAT_08143774,piVar1[iVar2 + 0x14]);
        MSG_WriteFloat(&DAT_08143774,piVar1[iVar2 + 0x17]);
        MSG_WriteCoord(&DAT_08143774,piVar1[iVar2 + 0x2e]);
        MSG_WriteCoord(&DAT_08143774,piVar1[iVar2 + 0x31]);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 3);
      MSG_WriteByte(&DAT_08143774,piVar1[0x81]);
      MSG_WriteByte(&DAT_08143774,(int)ROUND((float)piVar1[0x82]));
      MSG_WriteByte(&DAT_08143774,(int)ROUND((float)piVar1[0x83]));
      MSG_WriteByte(&DAT_08143774,(int)ROUND((float)piVar1[0x84]));
      MSG_WriteByte(&DAT_08143774,(int)ROUND((float)piVar1[0x85]));
      MSG_WriteByte(&DAT_08143774,piVar1[0x86]);
    }
  }
  return;
}


// SV_CreateCustomizationList  @ 0807dee0
void SV_CreateCustomizationList(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  int local_c;
  undefined4 local_8;
  
  *(undefined4 *)(param_1 + 0x52b4) = 0;
  iVar3 = *(int *)(param_1 + 0x50b0);
  if (iVar3 != param_1 + 0x5050) {
    do {
      for (iVar1 = *(int *)(param_1 + 0x52b4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x80)) {
        iVar2 = 0x10;
        bVar6 = true;
        pcVar4 = (char *)(iVar1 + 0x51);
        pcVar5 = (char *)(iVar3 + 0x4d);
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          Con_DPrintf("SV_CreateCustomization list, ignoring dup. resource for player %s\n",
                      param_1 + 0x5005);
          goto LAB_0807dfae;
        }
      }
      local_8 = 0;
      iVar1 = COM_CreateCustomization(param_1 + 0x5234,iVar3,0xffffffff,1,1,0,&local_c,&local_8);
      if (iVar1 == 0) {
        Con_Printf("Ignoring invalid custom decal from %s\n",param_1 + 0x5005);
      }
      else {
        *(undefined4 *)(local_c + 0x74) = local_8;
        (*DAT_08178f10)(*(undefined4 *)(param_1 + 0x4f08),local_c);
      }
LAB_0807dfae:
      iVar3 = *(int *)(iVar3 + 0x60);
    } while (iVar3 != param_1 + 0x5050);
  }
  return;
}


// SV_CreatePacketEntities  @ 080750c0
undefined4 SV_CreatePacketEntities(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined1 local_9;
  undefined2 local_8;
  undefined1 local_5;
  
  if (param_1 == 1) {
    iVar3 = *(int *)(param_2 + 0x4f04) + (*(uint *)(param_2 + 0x3eac) & SV_UPDATE_MASK) * 0x18;
    local_14 = iVar3 + 0x10;
    local_1c = *(int *)(iVar3 + 0x10);
    MSG_WriteByte(param_4,0x2a);
    MSG_WriteShort(param_4,*param_3);
    MSG_WriteByte(param_4,*(undefined4 *)(param_2 + 0x3eac));
  }
  else {
    local_1c = 0;
    local_14 = 0;
    MSG_WriteByte(param_4,0x29);
    MSG_WriteShort(param_4,*param_3);
  }
  iVar3 = 0;
  local_18 = 0;
  MSG_StartBitWriting(param_4);
  if (0 < *param_3) goto LAB_0807517b;
  if (0 < local_1c) {
    do {
      if (*param_3 <= iVar3) {
        iVar1 = 9999;
        goto LAB_08075195;
      }
LAB_0807517b:
      do {
        iVar1 = *(int *)(param_3[1] + 4 + iVar3 * 0x90);
LAB_08075195:
        if (local_18 < local_1c) {
          local_20 = *(int *)(*(int *)(local_14 + 4) + 4 + local_18 * 0x90);
        }
        else {
          local_20 = 9999;
        }
        if (iVar1 == local_20) {
          SV_WriteDelta(local_18 * 0x90 + *(int *)(local_14 + 4),iVar3 * 0x90 + param_3[1],param_4,0
                       );
          local_18 = local_18 + 1;
          iVar3 = iVar3 + 1;
        }
        else if (iVar1 < local_20) {
          iVar1 = EDICT_NUM(iVar1);
          SV_WriteDelta(iVar1 + 0x44,iVar3 * 0x90 + param_3[1],param_4,1);
          iVar3 = iVar3 + 1;
        }
        else if (local_20 < iVar1) {
          uVar2 = 0x10;
          if (0xff < local_20) {
            uVar2 = 0x8010;
          }
          if (0xff < uVar2) {
            uVar2 = uVar2 | 1;
          }
          if (0xffff < uVar2) {
            uVar2 = uVar2 | 0x100;
          }
          if (0xffffff < uVar2) {
            uVar2 = uVar2 | 0x800000;
          }
          local_5 = (undefined1)uVar2;
          MSG_WriteBitByte(&local_5,8);
          if ((uVar2 & 1) != 0) {
            local_5 = (undefined1)(uVar2 >> 8);
            MSG_WriteBitByte(&local_5,8);
          }
          if ((uVar2 & 0x100) != 0) {
            local_5 = (undefined1)(uVar2 >> 0x10);
            MSG_WriteBitByte(&local_5,8);
          }
          if ((uVar2 & 0x800000) != 0) {
            local_5 = 0;
            MSG_WriteBitByte(&local_5,8);
          }
          if ((short)uVar2 < 0) {
            local_8 = (undefined2)local_20;
            MSG_WriteBitShort(&local_8,10);
          }
          else {
            local_9 = (undefined1)local_20;
            MSG_WriteBitByte(&local_9,8);
          }
          local_18 = local_18 + 1;
        }
      } while (iVar3 < *param_3);
    } while (local_18 < local_1c);
  }
  local_10 = 0;
  MSG_WriteBitLong(&local_10,0x20);
  MSG_EndBitWriting(param_4);
  return *(undefined4 *)(param_4 + 0x10);
}


// SV_CreateResourceList  @ 08077650
void SV_CreateResourceList(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  
  bVar1 = false;
  DAT_0813db2c = 0;
  piVar4 = &DAT_0813eb34;
  if (DAT_0813eb34 != 0) {
    iVar5 = 1;
    do {
      if (*(char *)*piVar4 == '!') {
        if (!bVar1) {
          bVar1 = true;
          uVar2 = 1;
          iVar3 = 0;
          puVar6 = &DAT_080a4af0;
          goto LAB_080776c3;
        }
      }
      else {
        if (svs < 2) {
LAB_080776a3:
          iVar3 = 0;
        }
        else {
          uVar2 = va("sound/%s",*piVar4);
          iVar3 = COM_FileSize(uVar2);
          if (iVar3 == -1) goto LAB_080776a3;
        }
        uVar2 = 0;
        puVar6 = (undefined *)*piVar4;
LAB_080776c3:
        SV_AddResource(0,puVar6,iVar3,uVar2,iVar5);
      }
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (*piVar4 != 0);
  }
  piVar4 = &DAT_0813db34;
  if (DAT_0813db34 != 0) {
    iVar5 = 1;
    do {
      if ((svs < 2) || (iVar3 = COM_FileSize(*piVar4), iVar3 == -1)) {
        iVar3 = 0;
      }
      SV_AddResource(2,*piVar4,iVar3,1,iVar5);
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (*piVar4 != 0);
  }
  iVar5 = 0;
  if (0 < sv_decalnamecount) {
    do {
      uVar2 = Draw_DecalSize(iVar5,0,iVar5);
      SV_AddResource(3,(int)&sv_decalnames + iVar5 * 0x11,uVar2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < sv_decalnamecount);
  }
  piVar4 = &DAT_0813fb38;
  iVar3 = 1;
  iVar5 = DAT_0813fb38;
  while (iVar5 != 0) {
    if ((svs < 2) || (iVar5 = COM_FileSize(*piVar4), iVar5 == -1)) {
      iVar5 = 0;
    }
    SV_AddResource(4,*piVar4,iVar5,1,iVar3);
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + 1;
    iVar5 = *piVar4;
  }
  return;
}


// SV_Customization  @ 080777b0
void SV_Customization(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  host_client = DAT_0816dd10;
  iVar2 = -1;
  if (0 < svs) {
    do {
      iVar2 = iVar1;
      if (host_client == param_1) break;
      iVar1 = iVar1 + 1;
      host_client = host_client + 0x14ae;
      iVar2 = -1;
    } while (iVar1 < svs);
  }
  if (iVar2 == -1) {
    Sys_Error("Couldn\'t find player index for customization.");
  }
  else {
    iVar1 = 0;
    host_client = DAT_0816dd10;
    if (0 < svs) {
      do {
        if (((*host_client != 0) || (host_client[1] != 0)) &&
           ((host_client != param_1 || (param_3 == 0)))) {
          MSG_WriteByte(host_client + 0x1e,0x31);
          MSG_WriteByte(host_client + 0x1e,iVar2);
          MSG_WriteByte(host_client + 0x1e,*(undefined4 *)(param_2 + 0x40));
          MSG_WriteString(host_client + 0x1e,param_2);
          MSG_WriteShort(host_client + 0x1e,*(undefined4 *)(param_2 + 0x44));
          MSG_WriteLong(host_client + 0x1e,*(undefined4 *)(param_2 + 0x48));
          MSG_WriteByte(host_client + 0x1e,*(undefined1 *)(param_2 + 0x4c));
          if ((*(byte *)(param_2 + 0x4c) & 4) != 0) {
            SZ_Write(host_client + 0x1e,param_2 + 0x4d,0x10);
          }
        }
        iVar1 = iVar1 + 1;
        host_client = host_client + 0x14ae;
      } while (iVar1 < svs);
    }
  }
  return;
}


// SV_DeallocateDynamicData  @ 080704f0
void SV_DeallocateDynamicData(void)

{
  if (g_moved_edict != (void *)0x0) {
    free(g_moved_edict);
  }
  if (g_moved_from != (void *)0x0) {
    free(g_moved_from);
  }
  if (g_playertouch != (void *)0x0) {
    free(g_playertouch);
  }
  g_moved_edict = (void *)0x0;
  g_moved_from = (void *)0x0;
  g_playertouch = (void *)0x0;
  return;
}


// SV_DropClient  @ 080578c0
void SV_DropClient(undefined4 *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 local_18 [20];
  
  if (param_2 == 0) {
    iVar2 = param_1[0xfb0];
    if (iVar2 == 0) {
      MSG_WriteByte(param_1 + 0x1e,2);
      local_18[0] = 2;
    }
    if ((param_1[0x13c2] != 0) && (param_1[1] != 0)) {
      if (param_1[0xfaf] == 0) {
        uVar5 = param_1[0x13c2];
        pcVar1 = DAT_08178ee0;
      }
      else {
        uVar5 = param_1[0x13c2];
        pcVar1 = DAT_08178f18;
      }
      (*pcVar1)(uVar5);
    }
    if (param_1[0x140d] != 0) {
      COM_FreeFile(param_1[0x140d]);
      param_1[0x140d] = 0;
    }
    if (param_1[0x1448] != 0) {
      fclose((FILE *)param_1[0x1448]);
      param_1[0x1448] = 0;
    }
    if (param_1[0xfaf] == 0) {
      pcVar4 = "Dropped %s from server\n";
    }
    else {
      pcVar4 = "Dropped %s (spectator) from server\n";
    }
    Sys_Printf(pcVar4,(int)param_1 + 0x5005);
    if (param_1[0xfb0] == 0) {
      Netchan_Transmit(param_1 + 5,iVar2 == 0,local_18);
    }
  }
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *(undefined1 *)((int)param_1 + 0x5005) = 0;
  *(undefined8 *)(param_1 + 0x13be) = realtime;
  param_1[0xfcd] = 0;
  param_1[0x13c2] = 0;
  puVar3 = param_1 + 0x13c6;
  for (iVar2 = 0x31; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  SV_FullClientUpdate(param_1,&DAT_081413f8);
  return;
}


// SV_Drop_f  @ 08080330
void SV_Drop_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    Host_EndRedirect();
    if (*(int *)(host_client + 0x3ebc) == 0) {
      SV_BroadcastPrintf("%s dropped\n",host_client + 0x5005);
    }
    SV_DropClient(host_client,0);
  }
  return;
}


// SV_EmitPacketEntities  @ 08075370
void SV_EmitPacketEntities(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  msg_delta_208._8_4_ = buf_delta_206;
  msg_delta_208._12_4_ = 4000;
  msg_delta_208._16_4_ = 0;
  msg_delta_208._0_4_ = 1;
  msg_delta_208._4_4_ = 0;
  msg_nodelta_209._8_4_ = buf_nodelta_207;
  msg_nodelta_209._12_4_ = 4000;
  msg_nodelta_209._16_4_ = 0;
  msg_nodelta_209._0_4_ = 1;
  msg_nodelta_209._4_4_ = 0;
  if (*(int *)(param_1 + 0x3eac) == -1) {
    uVar3 = 0;
  }
  else {
    if (((byte)(0.0 < (float)sv_smartdelta._12_4_ |
                (byte)((ushort)((ushort)NAN((float)sv_smartdelta._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_smartdelta._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
       && (1 < svs)) {
      iVar1 = SV_CreatePacketEntities(1,param_1,param_2,msg_delta_208);
      iVar2 = SV_CreatePacketEntities(0,param_1,param_2,msg_nodelta_209);
      uVar3 = msg_nodelta_209._16_4_;
      uVar4 = msg_nodelta_209._8_4_;
      if (iVar1 < iVar2) {
        uVar3 = msg_delta_208._16_4_;
        uVar4 = msg_delta_208._8_4_;
      }
      MSG_WriteBuf(param_3,uVar3,uVar4);
      return;
    }
    uVar3 = 1;
  }
  SV_CreatePacketEntities(uVar3,param_1,param_2,param_3);
  return;
}


// SV_EstimateNeededResources  @ 0807e230
/* WARNING: Removing unreachable block (ram,0x0807e298) */

int SV_EstimateNeededResources(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  for (iVar3 = *(int *)(host_client + 0x5118); iVar3 != host_client + 0x50b8;
      iVar3 = *(int *)(iVar3 + 0x60)) {
    iVar2 = 0;
    if (*(int *)(iVar3 + 0x40) == 3) {
      iVar1 = HPAK_ResourceForHash("custom.hpk",iVar3 + 0x4d,0);
      iVar2 = -1;
      if (iVar1 != 0) {
        iVar2 = *(int *)(iVar3 + 0x48);
      }
    }
    if (iVar2 == -1) {
      *(byte *)(iVar3 + 0x4c) = *(byte *)(iVar3 + 0x4c) | 2;
      iVar2 = *(int *)(iVar3 + 0x48);
    }
    else {
      iVar2 = 0;
    }
    iVar4 = iVar4 + iVar2;
  }
  return iVar4;
}


// SV_ExecuteClientMessage  @ 0807fa80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ExecuteClientMessage(int *param_1)

{
  double *pdVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  undefined4 local_94 [9];
  int local_70 [4];
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  byte local_54;
  ushort local_52;
  byte local_50;
  int local_4c [9];
  int local_28 [9];
  
  bVar2 = false;
  pdVar1 = (double *)(param_1[0x13c1] + (param_1[0x18] & SV_UPDATE_MASK) * 0x18);
  *(float *)(pdVar1 + 1) = (float)((longdouble)realtime - (longdouble)*pdVar1);
  if (param_1[0x17] < param_1[0x1b]) {
    param_1[0x13c0] = 0;
  }
  else {
    iVar7 = (param_1[0x17] - param_1[0x1b]) + param_1[0x12];
    param_1[0x12] = iVar7;
    param_1[0x12] = param_1[0x12] + -1;
    if (0 < iVar7) {
      do {
        MSG_WriteByte(param_1 + 0x1e,0x35);
        MSG_WriteByte(param_1 + 0x1e,param_1[0x12] + param_1[0x1b]);
        iVar7 = param_1[0x12];
        param_1[0x12] = param_1[0x12] + -1;
      } while (0 < iVar7);
    }
    param_1[0x12] = 0;
    param_1[0x1b] = param_1[0x17];
  }
  *(double *)(param_1[0x13c1] + (param_1[0x1b] & SV_UPDATE_MASK) * 0x18) = realtime;
  *(float *)(param_1[0x13c1] + 0xc + (param_1[0x1b] & SV_UPDATE_MASK) * 0x18) =
       (float)host_frametime;
  *(undefined4 *)(param_1[0x13c1] + 8 + (param_1[0x1b] & SV_UPDATE_MASK) * 0x18) = 0xbf800000;
  host_client = param_1;
  sv_player = param_1[0x13c2];
  *(undefined8 *)(param_1 + 0xfbc) = _DAT_0811d24c;
  param_1[0xfab] = -1;
  do {
    if (msg_badread != 0) {
      Con_Printf("SV_ReadClientMessage: badread\n");
      SV_DropClient(param_1,0);
      return;
    }
    iVar5 = MSG_ReadByte();
    iVar7 = msg_readcount;
    if (iVar5 == -1) {
      return;
    }
    switch(iVar5) {
    case 1:
      break;
    default:
      Con_Printf("SV_ReadClientMessage: unknown command char\n");
      SV_DropClient(param_1,0);
      return;
    case 3:
      if (bVar2) {
        return;
      }
      bVar2 = true;
      puVar9 = local_94;
      for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      cVar3 = MSG_ReadByte();
      MSG_ReadUsercmd(local_28,local_94);
      MSG_ReadUsercmd(local_4c,local_28);
      MSG_ReadUsercmd(local_70,local_4c);
      if (((*param_1 != 0) || (param_1[1] != 0)) && (sv != 0)) {
        cVar4 = COM_BlockSequenceCRCByte
                          (iVar7 + net_message._8_4_ + 1,(msg_readcount - iVar7) + -1,param_1[0x17])
        ;
        if (cVar4 != cVar3) {
          Con_DPrintf("Failed command checksum for %s (%d != %d)/%d\n",(int)param_1 + 0x5005,cVar4,
                      cVar3,param_1[0x17]);
          return;
        }
        if ((byte)(0.0 < (float)sv_showcmd._12_4_ |
                   (byte)((ushort)((ushort)NAN((float)sv_showcmd._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)sv_showcmd._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
        {
          Con_Printf("MSEC %i IMP %i Buttons:  %i:%i:%i FWD %i\n",(undefined1)local_70[0],local_50,
                     local_52 & 1,local_52 >> 0xb & 1,local_52 >> 2 & 1,(int)ROUND(local_60));
        }
        piVar8 = host_client;
        if (((DAT_0811d244 == 0) && ((1 < svs || (key_dest == 0)))) &&
           ((*(byte *)(sv_player + 0x261) & 0x10) == 0)) {
          *(int *)(host_client[0x13c2] + 0x150) = local_70[1];
          *(int *)(piVar8[0x13c2] + 0x154) = local_70[2];
          *(int *)(piVar8[0x13c2] + 0x158) = local_70[3];
        }
        else {
          local_70[0]._0_1_ = 0;
          local_60 = 0.0;
          local_5c = 0;
          local_58 = 0;
          local_52 = 0;
          if ((*(byte *)(sv_player + 0x261) & 0x10) != 0) {
            local_50 = 0;
          }
          piVar8 = local_70;
          piVar10 = local_28;
          for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar10 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar10 = piVar10 + 1;
          }
          piVar8 = local_70;
          piVar10 = local_4c;
          for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar10 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar10 = piVar10 + 1;
          }
          local_70[1] = *(undefined4 *)(host_client[0x13c2] + 0x150);
          local_70[2] = *(undefined4 *)(host_client[0x13c2] + 0x154);
          local_70[3] = *(undefined4 *)(host_client[0x13c2] + 0x158);
        }
        piVar8 = host_client;
        *(uint *)(host_client[0x13c2] + 0x23c) = (uint)local_52;
        if (local_50 != 0) {
          *(uint *)(piVar8[0x13c2] + 0x240) = (uint)local_50;
        }
        *(uint *)(host_client[0x13c2] + 0x1e0) = (uint)local_54;
        SV_PreRunCmd();
        if (net_drop < 0x10) {
          if (2 < net_drop) {
            do {
              SV_RunCmd(param_1 + 0xfb3);
              net_drop = net_drop + -1;
            } while (2 < net_drop);
          }
          if (1 < net_drop) {
            SV_RunCmd(local_28);
          }
          if (0 < net_drop) {
            SV_RunCmd(local_4c);
          }
        }
        SV_RunCmd(local_70);
        piVar8 = local_70;
        piVar10 = param_1 + 0xfb3;
        for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar10 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar10 = piVar10 + 1;
        }
      }
      break;
    case 4:
      uVar6 = MSG_ReadString();
      cVar3 = (host_client[0xfad] != 0) * '\x02';
      iVar7 = Q_strncasecmp(uVar6,"status",6);
      if ((((((iVar7 == 0) || (iVar7 = Q_strncasecmp(uVar6,&DAT_080a5c51,3), iVar7 == 0)) ||
            (iVar7 = Q_strncasecmp(uVar6,"customrsrclist",0xe), iVar7 == 0)) ||
           (((((iVar7 = Q_strncasecmp(uVar6,"notarget",8), iVar7 == 0 ||
               (iVar7 = Q_strncasecmp(uVar6,&DAT_080a5c6d,3), iVar7 == 0)) ||
              ((iVar7 = Q_strncasecmp(uVar6,&DAT_080a5c71,4), iVar7 == 0 ||
               ((iVar7 = Q_strncasecmp(uVar6,"noclip",6), iVar7 == 0 ||
                (iVar7 = Q_strncasecmp(uVar6,&DAT_080a5c7d,4), iVar7 == 0)))))) ||
             (iVar7 = Q_strncasecmp(uVar6,"color",5), iVar7 == 0)) ||
            ((((((iVar7 = Q_strncasecmp(uVar6,&DAT_080a5c88,4), iVar7 == 0 ||
                 (iVar7 = Q_strncasecmp(uVar6,"pause",5), iVar7 == 0)) ||
                (iVar7 = Q_strncasecmp(uVar6,"spawn",5), iVar7 == 0)) ||
               ((iVar7 = Q_strncasecmp(uVar6,&DAT_080a5c99,3), iVar7 == 0 ||
                (iVar7 = Q_strncasecmp(uVar6,"dropclient",10), iVar7 == 0)))) ||
              (iVar7 = Q_strncasecmp(uVar6,"begin",5), iVar7 == 0)) ||
             ((iVar7 = Q_strncasecmp(uVar6,"prespawn",8), iVar7 == 0 ||
              (iVar7 = Q_strncasecmp(uVar6,&DAT_080a5cb7,4), iVar7 == 0)))))))) ||
          (((iVar7 = Q_strncasecmp(uVar6,&DAT_080a5cbc,4), iVar7 == 0 ||
            (((iVar7 = Q_strncasecmp(uVar6,"download",8), iVar7 == 0 ||
              (iVar7 = Q_strncasecmp(uVar6,"resourcelist",0xb), iVar7 == 0)) ||
             (iVar7 = Q_strncasecmp(uVar6,"nextdl",6), iVar7 == 0)))) ||
           (((iVar7 = Q_strncasecmp(uVar6,"sv_print_custom",0xf), iVar7 == 0 ||
             (iVar7 = Q_strncasecmp(uVar6,&DAT_080a5cee,3), iVar7 == 0)) ||
            (iVar7 = Q_strncasecmp(uVar6,"ptrack",6), iVar7 == 0)))))) ||
         ((iVar7 = Q_strncasecmp(uVar6,"setinfo",7), iVar7 == 0 ||
          (iVar7 = Q_strncasecmp(uVar6,"showinfo",8), iVar7 == 0)))) {
        cVar3 = '\x01';
      }
      if (cVar3 == '\x02') {
        Cbuf_InsertText(uVar6);
      }
      else if (cVar3 == '\x01') {
        Cmd_ExecuteString(uVar6,0);
      }
      else {
        Cmd_TokenizeString(uVar6);
        (*DAT_08178eec)(host_client[0x13c2]);
      }
      break;
    case 5:
      iVar7 = MSG_ReadByte();
      param_1[0xfab] = iVar7;
      break;
    case 6:
      lVar11 = (longdouble)MSG_ReadCoord();
      lVar12 = (longdouble)MSG_ReadCoord();
      lVar13 = (longdouble)MSG_ReadCoord();
      iVar7 = sv_player;
      if (host_client[0xfaf] != 0) {
        *(float *)(sv_player + 0xe4) = (float)lVar11;
        *(float *)(iVar7 + 0xe8) = (float)lVar12;
        *(float *)(iVar7 + 0xec) = (float)lVar13;
        SV_LinkEdict(iVar7,0);
      }
      break;
    case 7:
      SV_ParseUpload();
      break;
    case 8:
      SV_ParseResourceList();
    }
  } while( true );
}


// SV_ExtractFromUserinfo  @ 08076f90
void SV_ExtractFromUserinfo(int *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int *piVar7;
  char *local_68;
  undefined4 local_58;
  char local_54 [79];
  undefined1 local_5;
  
  local_58 = 1;
  (*DAT_08178ef0)(param_1[0x13c2],param_1 + 0x13c6);
  pcVar2 = (char *)Info_ValueForKey(param_1 + 0x13c6,&DAT_080a44ed);
  local_68 = local_54;
  strncpy(local_68,pcVar2,0x4f);
  local_5 = 0;
  while (local_54[0] == ' ') {
    local_68 = local_68 + 1;
    local_54[0] = *local_68;
  }
  pcVar6 = local_54;
  if ((local_68 != pcVar6) && (*local_68 != '\0')) {
    do {
      *pcVar6 = *local_68;
      local_68 = local_68 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*local_68 != '\0');
    *pcVar6 = '\0';
  }
  uVar5 = 0xffffffff;
  pcVar6 = local_54;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  for (pcVar6 = local_54 + (~uVar5 - 2); (pcVar6 != local_54 && (*pcVar6 == ' '));
      pcVar6 = pcVar6 + -1) {
  }
  pcVar6[1] = '\0';
  iVar3 = strcmp(pcVar2,local_54);
  if (iVar3 != 0) {
    Info_SetValueForKey(param_1 + 0x13c6,&DAT_080a44ed,local_54,0xc4);
    pcVar2 = (char *)Info_ValueForKey(param_1 + 0x13c6,&DAT_080a44ed);
  }
  if ((*pcVar2 == '\0') || (iVar3 = strcasecmp(pcVar2,"console"), iVar3 == 0)) {
    Info_SetValueForKey(param_1 + 0x13c6,&DAT_080a44ed,"unnamed",0xc4);
    pcVar2 = (char *)Info_ValueForKey(param_1 + 0x13c6,&DAT_080a44ed);
  }
  do {
    iVar3 = 0;
    piVar7 = DAT_0816dd10;
    do {
      if ((((*piVar7 != 0) && (piVar7[1] != 0)) && (piVar7 != param_1)) &&
         (iVar4 = strcasecmp((char *)((int)piVar7 + 0x5005),pcVar2), iVar4 == 0)) break;
      iVar3 = iVar3 + 1;
      piVar7 = piVar7 + 0x14ae;
    } while (iVar3 < 0x20);
    iVar4 = local_58;
    if (iVar3 == 0x20) break;
    uVar5 = 0xffffffff;
    pcVar6 = pcVar2;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (0x1f < ~uVar5 - 1) {
      pcVar2[0x1c] = '\0';
    }
    local_68 = pcVar2;
    if (*pcVar2 == '(') {
      if (pcVar2[2] == ')') {
        local_68 = pcVar2 + 3;
      }
      else if (pcVar2[3] == ')') {
        local_68 = pcVar2 + 4;
      }
    }
    local_58 = local_58 + 1;
    sprintf(local_54,"(%d)%-0.40s",iVar4,local_68);
    Info_SetValueForKey(param_1 + 0x13c6,&DAT_080a44ed,local_54,0xc4);
    pcVar2 = (char *)Info_ValueForKey(param_1 + 0x13c6,&DAT_080a44ed);
  } while( true );
  strncpy((char *)((int)param_1 + 0x5005),pcVar2,0x1f);
  pcVar6 = (char *)Info_ValueForKey(param_1 + 0x13c6,&DAT_080a499f);
  iVar3 = -1;
  pcVar2 = pcVar6;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    iVar3 = __strtol_internal(pcVar6,0,10,0);
    if (iVar3 < 500) {
      iVar3 = 500;
    }
    if (10000 < iVar3) {
      iVar3 = 10000;
    }
    *(double *)(param_1 + 0x15) = (double)iVar3;
  }
  pcVar6 = (char *)Info_ValueForKey(param_1 + 0x13c6,"topcolor");
  iVar3 = -1;
  pcVar2 = pcVar6;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    iVar3 = __strtol_internal(pcVar6,0,10,0);
    param_1[0x140a] = iVar3;
  }
  pcVar6 = (char *)Info_ValueForKey(param_1 + 0x13c6,"bottomcolor");
  iVar3 = -1;
  pcVar2 = pcVar6;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    iVar3 = __strtol_internal(pcVar6,0,10,0);
    param_1[0x140b] = iVar3;
  }
  return;
}


// SV_FatPVS  @ 080740b0
undefined1 * SV_FatPVS(undefined4 param_1)

{
  fatbytes = *(int *)(DAT_0811d320 + 0x88) + 0x1f >> 3;
  Q_memset(&fatpvs,0,fatbytes);
  SV_AddToFatPVS(param_1,*(undefined4 *)(DAT_0811d320 + 0xa4));
  return &fatpvs;
}


// SV_FilterPacket  @ 08078a90
uint SV_FilterPacket(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_1c;
  
  uVar5 = DAT_08178fc4;
  iVar6 = numipfilters;
  do {
    while( true ) {
      iVar4 = iVar6 + -1;
      if (iVar4 < 0) {
        return (uint)((byte)(0.0 < (float)filterban._12_4_ |
                             (byte)((ushort)((ushort)NAN((float)filterban._12_4_) << 10) >> 8) |
                            (byte)((ushort)((ushort)((float)filterban._12_4_ == 0.0) << 0xe) >> 8))
                     == 0x40);
      }
      if ((((&DAT_08162ce4)[iVar4 * 4] == -1) ||
          (fVar2 = (float)(&DAT_08162ce8)[iVar4 * 4],
          (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40)) ||
         (fVar3 = (float)realtime,
         0x3f < (byte)((fVar2 < fVar3 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1))) break;
      if (iVar6 < numipfilters) {
        do {
          iVar1 = iVar6 + -1;
          (&ipfilters)[iVar1 * 4] = (&ipfilters)[iVar6 * 4];
          (&DAT_08162ce4)[iVar1 * 4] = (&DAT_08162ce4)[iVar6 * 4];
          (&DAT_08162ce8)[iVar1 * 4] = (&DAT_08162ce8)[iVar6 * 4];
          (&DAT_08162cec)[iVar1 * 4] = (&DAT_08162cec)[iVar6 * 4];
          iVar6 = iVar6 + 1;
        } while (iVar6 < numipfilters);
      }
      numipfilters = numipfilters + -1;
      iVar6 = iVar4;
    }
    iVar6 = iVar4;
  } while ((uVar5 & (&ipfilters)[iVar4 * 4]) != (&DAT_08162ce4)[iVar4 * 4]);
  local_1c = (uint)(longlong)ROUND((float)filterban._12_4_);
  return local_1c;
}


// SV_FilterTime  @ 08057f90
bool SV_FilterTime(float param_1)

{
  float fVar1;
  
  sv_extratime_130 = sv_extratime_130 + (float)host_frametime;
  fVar1 = param_1 - sv_oldrealtime_129;
  if (0.1 <= fVar1) {
    sv_oldrealtime_129 = param_1;
    host_frametime = (double)sv_extratime_130;
    sv_extratime_130 = 0.0;
  }
  return 0.1 <= fVar1;
}


// SV_FindAuthRequest  @ 080819d0
int SV_FindAuthRequest(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  undefined4 auStack_40 [5];
  char *apcStack_2c [5];
  
  iVar2 = 0;
  do {
    if ((&svauthstates)[iVar2 * 0xd] != 0) {
      puVar3 = param_2;
      ppcVar4 = apcStack_2c;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar4 = (char *)*puVar3;
        puVar3 = puVar3 + 1;
        ppcVar4 = ppcVar4 + 1;
      }
      puVar3 = &DAT_08176864 + iVar2 * 0xd;
      puVar5 = auStack_40;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar1 = NET_CompareAdr();
      if (iVar1 != 0) {
        return iVar2;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x80);
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      if ((&svauthstates)[iVar2 * 0xd] == 0) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x80);
    if (iVar2 != 0x80) {
      iVar1 = iVar2 * 0x34;
      puVar3 = &svauthstates + iVar2 * 0xd;
      apcStack_2c[3] = (char *)0x8081a6d;
      apcStack_2c[4] = (char *)puVar3;
      WON_RemoveUser();
      *(double *)(&DAT_08176878 + iVar1) =
           (double)((float)(3 - *(int *)(&DAT_08176880 + iVar1)) * 5.0 + (float)realtime);
      *(undefined4 *)(&DAT_08176884 + iVar1) = 0x33;
      *(undefined4 *)(&DAT_08176880 + iVar1) = 3;
      for (iVar1 = 5; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
      }
      (&svauthstates)[iVar2 * 0xd] = 1;
      return iVar2;
    }
    apcStack_2c[4] = "No more authentication slots available\n";
    apcStack_2c[3] = (char *)0x8081aca;
    Con_Printf();
  }
  return -1;
}


// SV_FindModelNumbers  @ 080710a0
void SV_FindModelNumbers(void)

{
  int iVar1;
  int iVar2;
  
  sv_playermodel = -1;
  iVar2 = 0;
  do {
    if ((&DAT_0813db30)[iVar2] == 0) {
      return;
    }
    iVar1 = Q_strcasecmp((&DAT_0813db30)[iVar2],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x200);
  return;
}


// SV_FindTouchedLeafs  @ 080834c0
void SV_FindTouchedLeafs(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  
  if (*param_2 != -2) {
    if (*param_2 < 0) {
      if (*(int *)(param_1 + 0x10) < 0x18) {
        *(short *)(*(int *)(param_1 + 0x10) * 2 + param_1 + 0x14) =
             (short)(((int)param_2 - *(int *)(DAT_0811d320 + 0x8c)) * -0x55555555 >> 4) + -1;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = 0x19;
      }
    }
    else {
      iVar3 = param_2[6];
      if (*(byte *)(iVar3 + 0x10) < 3) {
        fVar1 = *(float *)(iVar3 + 0xc);
        fVar2 = *(float *)((uint)*(byte *)(iVar3 + 0x10) * 4 + param_1 + 0x180);
        if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
          uVar4 = 1;
        }
        else if (*(float *)(iVar3 + 0xc) <
                 *(float *)((uint)*(byte *)(iVar3 + 0x10) * 4 + param_1 + 0x18c)) {
          uVar4 = 3;
        }
        else {
          uVar4 = 2;
        }
      }
      else {
        uVar4 = BoxOnPlaneSide(param_1 + 0x180,param_1 + 0x18c,iVar3);
      }
      if (((uVar4 & 3) != 0) && (*param_3 == -1)) {
        *param_3 = ((int)param_2 - *(int *)(DAT_0811d320 + 0xa4)) * -0x33333333 >> 3;
      }
      if ((uVar4 & 1) != 0) {
        SV_FindTouchedLeafs(param_1,param_2[7],param_3);
      }
      if ((uVar4 & 2) != 0) {
        SV_FindTouchedLeafs(param_1,param_2[8],param_3);
      }
    }
  }
  return;
}


// SV_FixCheckBottom  @ 08079a20
void SV_FixCheckBottom(int param_1)

{
  *(byte *)(param_1 + 0x261) = *(byte *)(param_1 + 0x261) | 4;
  return;
}


// SV_FixupGravityVelocity  @ 0807ae90
void SV_FixupGravityVelocity(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 0x1d8);
  fVar2 = 1.0;
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar2 = fVar1;
  }
  *(float *)(param_1 + 0x104) =
       *(float *)(param_1 + 0x104) - fVar2 * (float)sv_gravity._12_4_ * (float)host_frametime * 0.5;
  SV_CheckVelocity(param_1);
  return;
}


// SV_FlushSignon  @ 08077350
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_FlushSignon(void)

{
  if (DAT_08143780 + -100 <= DAT_08143784) {
    if (DAT_08143788 == 0xf) {
      Sys_Error("sv.num_signon_buffers == MAX_SIGNON_BUFFERS-1");
    }
    (&DAT_0814378c)[DAT_08143788 + -1] = DAT_08143784;
    _DAT_0814377c = &DAT_081437cc + DAT_08143788 * 4000;
    DAT_08143788 = DAT_08143788 + 1;
    DAT_08143784 = 0;
  }
  return;
}


// SV_FlyDirection  @ 080799b0
bool SV_FlyDirection(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = SV_movestep(param_1,param_2,0);
  if (iVar1 != 0) {
    SV_LinkEdict(param_1,1);
  }
  else {
    SV_LinkEdict(param_1,1);
  }
  return iVar1 != 0;
}


// SV_FlyMove  @ 0807a780
uint SV_FlyMove(int *param_1,float param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int *piVar8;
  int *piVar9;
  int aiStack_110 [3];
  float local_104;
  int aiStack_100 [3];
  float local_f4;
  uint uStack_f0;
  uint local_c8;
  float local_c4;
  int local_c0;
  int local_bc;
  float local_b4 [3];
  int local_a8 [4];
  float local_98;
  int local_94;
  int local_90;
  int local_8c;
  float local_88;
  float local_84;
  float local_80;
  int local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c [3];
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  float local_8;
  
  bVar4 = *(byte *)((int)param_1 + 0x262);
  local_c8 = 0;
  local_64 = (float)param_1[0x3f];
  local_60 = (float)param_1[0x40];
  local_5c = (float)param_1[0x41];
  local_c0 = 0;
  local_c4 = param_2;
  local_bc = 0;
  puVar7 = &stack0xffffff14;
  local_58 = local_64;
  local_54 = local_60;
  local_50 = local_5c;
  while( true ) {
    if ((((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x3f]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x3f] == 0.0) << 0xe) >> 8)) == 0x40) &&
        ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x40]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_1[0x40] == 0.0) << 0xe) >> 8)) == 0x40)) &&
       (fVar1 = (float)param_1[0x41],
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
      return local_c8;
    }
    iVar6 = 0;
    do {
      local_b4[iVar6] = local_c4 * (float)param_1[iVar6 + 0x3f] + (float)param_1[iVar6 + 0x39];
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    *(uint *)(puVar7 + -4) = (uint)((bVar4 & 0x80) != 0);
    *(int **)(puVar7 + -8) = param_1;
    *(undefined4 *)(puVar7 + -0xc) = 0;
    *(float **)(puVar7 + -0x10) = local_b4;
    *(int **)(puVar7 + -0x14) = param_1 + 0x69;
    *(int **)(puVar7 + -0x18) = param_1 + 0x66;
    *(int **)(puVar7 + -0x1c) = param_1 + 0x39;
    *(int **)(puVar7 + -0x20) = local_a8;
    *(undefined4 *)(puVar7 + -0x24) = 0x807a8b9;
    SV_Move();
    if (local_a8[0] != 0) {
      param_1[0x3f] = vec3_origin._0_4_;
      param_1[0x40] = vec3_origin._4_4_;
      param_1[0x41] = vec3_origin._8_4_;
      return 4;
    }
    if (0.0 < local_98) {
      param_1[0x39] = local_94;
      param_1[0x3a] = local_90;
      param_1[0x3b] = local_8c;
      local_64 = (float)param_1[0x3f];
      local_60 = (float)param_1[0x40];
      local_5c = (float)param_1[0x41];
      local_c0 = 0;
    }
    if ((byte)(1.0 < local_98 | (byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_98 == 1.0) << 0xe) >> 8)) == 0x40) {
      return local_c8;
    }
    if (local_78 == 0) {
      *(char **)(puVar7 + -8) = "SV_FlyMove: !trace.ent";
      *(undefined4 *)(puVar7 + -0xc) = 0x807a987;
      Sys_Error();
    }
    if (((byte)(0.7 < local_80 | (byte)((ushort)((ushort)NAN(local_80) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_80 == 0.7) << 0xe) >> 8)) == 1) &&
       (((local_c8 = local_c8 | 1, *(int *)(local_78 + 0x1c8) == 4 ||
         (*(int *)(local_78 + 0x1c4) == 0xd)) ||
        ((*(int *)(local_78 + 0x1c8) == 3 || ((*(byte *)(param_1 + 0x98) & 8) != 0)))))) {
      *(byte *)((int)param_1 + 0x261) = *(byte *)((int)param_1 + 0x261) | 2;
      param_1[0x96] = local_78;
    }
    if (((byte)((byte)((ushort)((ushort)NAN(local_80) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_80 == 0.0) << 0xe) >> 8)) == 0x40) &&
       (local_c8 = local_c8 | 2, param_3 != (int *)0x0)) {
      piVar8 = local_a8;
      piVar9 = param_3;
      for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar9 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar9 = piVar9 + 1;
      }
    }
    *(int **)(puVar7 + -8) = local_a8;
    *(int *)(puVar7 + -0xc) = local_78;
    *(int **)(puVar7 + -0x10) = param_1;
    *(undefined4 *)(puVar7 + -0x14) = 0x807aa28;
    SV_Impact();
    if (*param_1 != 0) {
      return local_c8;
    }
    local_c4 = local_c4 - local_c4 * local_98;
    if (4 < local_c0) break;
    local_4c[local_c0 * 3] = local_88;
    local_4c[local_c0 * 3 + 1] = local_84;
    local_4c[local_c0 * 3 + 2] = local_80;
    local_c0 = local_c0 + 1;
    if ((param_1[0x71] == 3) &&
       (((*(byte *)((int)param_1 + 0x261) & 2) == 0 ||
        (fVar1 = (float)param_1[0x77],
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)))) {
      iVar6 = 0;
      if (0 < local_c0) {
        do {
          fVar1 = local_4c[iVar6 * 3 + 2];
          if ((byte)(0.7 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.7) << 0xe) >> 8)) == 1) {
            *(undefined4 *)(puVar7 + -8) = 0x3f800000;
            *(float **)(puVar7 + -0xc) = &local_70;
            *(float **)(puVar7 + -0x10) = local_4c + iVar6 * 3;
            *(float **)(puVar7 + -0x14) = &local_64;
            *(undefined4 *)(puVar7 + -0x18) = 0x807ab31;
            ClipVelocity();
            local_64 = local_70;
            local_60 = local_6c;
            local_5c = local_68;
          }
          else {
            *(float *)(puVar7 + -8) = (1.0 - (float)param_1[0x77]) * (float)sv_bounce._12_4_ + 1.0;
            *(float **)(puVar7 + -0xc) = &local_70;
            *(float **)(puVar7 + -0x10) = local_4c + iVar6 * 3;
            *(float **)(puVar7 + -0x14) = &local_64;
            *(undefined4 *)(puVar7 + -0x18) = 0x807ab88;
            ClipVelocity();
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < local_c0);
      }
      param_1[0x3f] = (int)local_70;
      param_1[0x40] = (int)local_6c;
      param_1[0x41] = (int)local_68;
      local_64 = local_70;
      local_60 = local_6c;
      local_5c = local_68;
    }
    else {
      iVar6 = 0;
      if (0 < local_c0) {
        do {
          *(undefined4 *)(puVar7 + -8) = 0x3f800000;
          *(float **)(puVar7 + -0xc) = &local_70;
          *(float **)(puVar7 + -0x10) = local_4c + iVar6 * 3;
          *(float **)(puVar7 + -0x14) = &local_64;
          *(undefined4 *)(puVar7 + -0x18) = 0x807ac07;
          ClipVelocity();
          iVar5 = 0;
          if (0 < local_c0) {
            do {
              if ((iVar5 != iVar6) &&
                 (fVar1 = local_68 * local_4c[iVar5 * 3 + 2] +
                          local_6c * local_4c[iVar5 * 3 + 1] + local_70 * local_4c[iVar5 * 3],
                 (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) break;
              iVar5 = iVar5 + 1;
            } while (iVar5 < local_c0);
          }
        } while ((iVar5 != local_c0) && (iVar6 = iVar6 + 1, iVar6 < local_c0));
      }
      if (iVar6 == local_c0) {
        if (local_c0 != 2) {
          return local_c8;
        }
        *(float **)(puVar7 + -8) = &local_10;
        *(undefined1 **)(puVar7 + -0xc) = local_40;
        *(float **)(puVar7 + -0x10) = local_4c;
        *(undefined4 *)(puVar7 + -0x14) = 0x807acce;
        CrossProduct();
        fVar1 = (float)param_1[0x3f];
        fVar2 = (float)param_1[0x40];
        fVar3 = (float)param_1[0x41];
        *(int **)(puVar7 + -0x14) = param_1 + 0x3f;
        *(float *)(puVar7 + -0x18) = local_8 * fVar3 + local_c * fVar2 + local_10 * fVar1;
        *(float **)(puVar7 + -0x1c) = &local_10;
        *(undefined4 *)(puVar7 + -0x20) = 0x807ad03;
        VectorScale();
      }
      else {
        param_1[0x3f] = (int)local_70;
        param_1[0x40] = (int)local_6c;
        param_1[0x41] = (int)local_68;
      }
      fVar1 = (float)param_1[0x41] * local_50 +
              (float)param_1[0x40] * local_54 + (float)param_1[0x3f] * local_58;
      if ((byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) break;
    }
    local_bc = local_bc + 1;
    puVar7 = puVar7 + -4;
    if (3 < local_bc) {
      return local_c8;
    }
  }
  param_1[0x3f] = vec3_origin._0_4_;
  param_1[0x40] = vec3_origin._4_4_;
  param_1[0x41] = vec3_origin._8_4_;
  return local_c8;
}


// SV_FullClientUpdate  @ 08073ee0
void SV_FullClientUpdate(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  char local_c8 [196];
  
  iVar2 = (param_1 - DAT_0816dd10) * -0x54557e99 >> 3;
  strcpy(local_c8,(char *)(param_1 + 0x4f18));
  Info_RemovePrefixedKeys(local_c8,0x5f);
  MSG_WriteByte(param_2,0xd);
  MSG_WriteByte(param_2,iVar2);
  MSG_WriteLong(param_2,*(undefined4 *)(param_1 + 0x4f10));
  MSG_WriteString(param_2,local_c8);
  fVar1 = *(float *)(param_1 + 0x3f34);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    MSG_WriteByte(param_2,0x34);
    MSG_WriteByte(param_2,iVar2);
    MSG_WriteFloat(param_2,*(undefined4 *)(param_1 + 0x3f34));
  }
  return;
}


// SV_GetCustomChunk  @ 0805e8e0
undefined4 SV_GetCustomChunk(int *param_1)

{
  double dVar1;
  float fVar2;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      return 0x80;
    }
    dVar1 = *(double *)(param_1 + 0x15);
    if ((byte)(0.0 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(dVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar2 = (float)*(double *)(param_1 + 0x15);
      if ((byte)(9900.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 9900.0) << 0xe) >> 8)) == 1) {
        return 0x100;
      }
      if ((byte)(4900.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 4900.0) << 0xe) >> 8)) == 1) {
        return 0xc0;
      }
      if ((byte)(3400.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 3400.0) << 0xe) >> 8)) == 1) {
        return 0x80;
      }
    }
  }
  return 0x40;
}


// SV_GetModInfo  @ 080730e0
int SV_GetModInfo(char *param_1,char *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,char *param_7)

{
  if (gmodinfo == 0) {
    *param_1 = '\0';
    *param_2 = '\0';
    builtin_strncpy(param_7,"1.0.1.0",8);
    *param_3 = 1;
    *param_4 = 0;
    *param_5 = 1;
    *param_6 = 0;
  }
  else {
    strcpy(param_1,(char *)&DAT_08178c04);
    strcpy(param_2,&DAT_08178d04);
    strcpy(param_7,&DAT_08178e04);
    *param_3 = DAT_08178e24;
    *param_4 = DAT_08178e28;
    *param_5 = DAT_08178e2c;
    *param_6 = DAT_08178e30;
  }
  return gmodinfo;
}


// SV_HashString  @ 08071570
uint SV_HashString(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = tolower((int)*param_1);
    uVar3 = iVar2 + uVar3 * 2;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return uVar3 % param_2;
}


// SV_HitgroupForStudioHull  @ 08061180
undefined4 SV_HitgroupForStudioHull(int param_1)

{
  return *(undefined4 *)(studio_hull_hitgroup + param_1 * 4);
}


// SV_HullForBeam  @ 08082430
undefined4 * SV_HullForBeam(float *param_1,float *param_2,float *param_3)

{
  float local_10;
  float local_c;
  float local_8;
  
  beam_planes._0_4_ = *param_2 - *param_1;
  beam_planes._4_4_ = param_2[1] - param_1[1];
  beam_planes._8_4_ = param_2[2] - param_1[2];
  VectorNormalize(beam_planes);
  beam_planes._20_4_ = beam_planes._0_4_;
  beam_planes._24_4_ = beam_planes._4_4_;
  beam_planes._28_4_ = beam_planes._8_4_;
  beam_planes._12_4_ =
       param_2[2] * (float)beam_planes._8_4_ +
       param_2[1] * (float)beam_planes._4_4_ + *param_2 * (float)beam_planes._0_4_;
  beam_planes._32_4_ =
       param_1[2] * (float)beam_planes._8_4_ +
       param_1[1] * (float)beam_planes._4_4_ + *param_1 * (float)beam_planes._0_4_;
  if (0.9 <= ABS((float)beam_planes._8_4_)) {
    local_10 = 1.0;
    local_8 = 0.0;
  }
  else {
    local_8 = 1.0;
    local_10 = 0.0;
  }
  local_c = 0.0;
  CrossProduct(beam_planes,&local_10,0x80c7c28);
  VectorNormalize(0x80c7c28);
  beam_planes._60_4_ = beam_planes._40_4_;
  beam_planes._64_4_ = beam_planes._44_4_;
  beam_planes._68_4_ = beam_planes._48_4_;
  beam_planes._52_4_ =
       (param_1[2] + (float)beam_planes._48_4_) * (float)beam_planes._48_4_ +
       (param_1[1] + (float)beam_planes._44_4_) * (float)beam_planes._44_4_ +
       (*param_1 + (float)beam_planes._40_4_) * (float)beam_planes._40_4_;
  local_10 = *param_1 - (float)beam_planes._40_4_;
  local_c = param_1[1] - (float)beam_planes._44_4_;
  local_8 = param_1[2] - (float)beam_planes._48_4_;
  beam_planes._72_4_ =
       local_8 * (float)beam_planes._48_4_ +
       local_c * (float)beam_planes._44_4_ + local_10 * (float)beam_planes._40_4_;
  CrossProduct(0x80c7c28,beam_planes,0x80c7c50);
  VectorNormalize(0x80c7c50);
  beam_planes._100_4_ = beam_planes._80_4_;
  beam_planes._104_4_ = beam_planes._84_4_;
  beam_planes._108_4_ = beam_planes._88_4_;
  beam_planes._12_4_ =
       ABS((float)beam_planes._8_4_ * param_3[2]) +
       ABS((float)beam_planes._4_4_ * param_3[1]) + ABS((float)beam_planes._0_4_ * *param_3) +
       (float)beam_planes._12_4_;
  beam_planes._32_4_ =
       (float)beam_planes._32_4_ -
       (ABS((float)beam_planes._28_4_ * param_3[2]) +
       ABS((float)beam_planes._24_4_ * param_3[1]) + ABS((float)beam_planes._20_4_ * *param_3));
  beam_planes._52_4_ =
       ABS((float)beam_planes._48_4_ * param_3[2]) +
       ABS((float)beam_planes._44_4_ * param_3[1]) + ABS((float)beam_planes._40_4_ * *param_3) +
       (float)beam_planes._52_4_;
  beam_planes._72_4_ =
       (float)beam_planes._72_4_ -
       (ABS((float)beam_planes._68_4_ * param_3[2]) +
       ABS((float)beam_planes._64_4_ * param_3[1]) + ABS((float)beam_planes._60_4_ * *param_3));
  beam_planes._92_4_ =
       ABS((float)beam_planes._88_4_ * param_3[2]) +
       ABS((float)beam_planes._84_4_ * param_3[1]) + ABS((float)beam_planes._80_4_ * *param_3) +
       (param_1[2] + (float)beam_planes._88_4_) * (float)beam_planes._88_4_ +
       (param_1[1] + (float)beam_planes._84_4_) * (float)beam_planes._84_4_ +
       (*param_1 + (float)beam_planes._80_4_) * (float)beam_planes._80_4_;
  beam_planes._112_4_ =
       ((param_1[2] - (float)beam_planes._88_4_) * (float)beam_planes._88_4_ +
       (param_1[1] - (float)beam_planes._84_4_) * (float)beam_planes._84_4_ +
       (*param_1 - (float)beam_planes._80_4_) * (float)beam_planes._80_4_) -
       (ABS((float)beam_planes._88_4_ * param_3[2]) +
       ABS((float)beam_planes._84_4_ * param_3[1]) + ABS((float)beam_planes._80_4_ * *param_3));
  return &beam_hull;
}


// SV_HullForBox  @ 080823c0
undefined4 * SV_HullForBox(undefined4 *param_1,undefined4 *param_2)

{
  box_planes._12_4_ = *param_2;
  box_planes._32_4_ = *param_1;
  box_planes._52_4_ = param_2[1];
  box_planes._72_4_ = param_1[1];
  box_planes._92_4_ = param_2[2];
  box_planes._112_4_ = param_1[2];
  return &box_hull;
}


// SV_HullForBsp  @ 080829c0
int SV_HullForBsp(int param_1,float *param_2,float *param_3,float *param_4)

{
  int iVar1;
  float fVar2;
  int local_c;
  
  iVar1 = (&DAT_0813e330)[*(int *)(param_1 + 0x170)];
  if (iVar1 == 0) {
    Sys_Error("Hit a %s with no model (%s)",*(int *)(param_1 + 0xdc) + pr_strings,
              *(int *)(param_1 + 0x174) + pr_strings);
  }
  else if (*(int *)(iVar1 + 0x44) == 0) goto LAB_08082ab8;
  Sys_Error("Hit a %s with no model (%s)",*(int *)(param_1 + 0xdc) + pr_strings,
            *(int *)(param_1 + 0x174) + pr_strings);
  Sys_Error("MOVETYPE_PUSH with a non bsp model");
LAB_08082ab8:
  fVar2 = *param_3 - *param_2;
  if (8.0 < fVar2) {
    if ((36.0 < fVar2) || (36.0 < param_3[2] - param_2[2])) {
      if (36.0 < fVar2) {
        local_c = iVar1 + 0x120;
      }
      else {
        local_c = iVar1 + 0xf8;
      }
    }
    else {
      local_c = iVar1 + 0x148;
    }
    *param_4 = *(float *)(local_c + 0x10) - *param_2;
    param_4[1] = *(float *)(local_c + 0x14) - param_2[1];
    param_4[2] = *(float *)(local_c + 0x18) - param_2[2];
  }
  else {
    local_c = iVar1 + 0xd0;
    *param_4 = *(float *)(iVar1 + 0xe0);
    param_4[1] = *(float *)(iVar1 + 0xe4);
    param_4[2] = *(float *)(iVar1 + 0xe8);
  }
  *param_4 = *param_4 + *(float *)(param_1 + 0xe4);
  param_4[1] = param_4[1] + *(float *)(param_1 + 0xe8);
  param_4[2] = param_4[2] + *(float *)(param_1 + 0xec);
  return local_c;
}


// SV_HullForEntity  @ 08082cb0
undefined4 SV_HullForEntity(int param_1,float *param_2,float *param_3,undefined4 *param_4)

{
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(param_1 + 0x1c8) == 4) {
    if (*(int *)(param_1 + 0x1c4) != 7) {
      Sys_Error("SOLID_BSP without MOVETYPE_PUSH");
    }
    local_20 = SV_HullForBsp(param_1,param_2,param_3,param_4);
  }
  else {
    local_10 = *(float *)(param_1 + 0x198) - *param_3;
    local_c = *(float *)(param_1 + 0x19c) - param_3[1];
    local_8 = *(float *)(param_1 + 0x1a0) - param_3[2];
    local_1c = *(float *)(param_1 + 0x1a4) - *param_2;
    local_18 = *(float *)(param_1 + 0x1a8) - param_2[1];
    local_14 = *(float *)(param_1 + 0x1ac) - param_2[2];
    local_20 = SV_HullForBox(&local_10,&local_1c);
    *param_4 = *(undefined4 *)(param_1 + 0xe4);
    param_4[1] = *(undefined4 *)(param_1 + 0xe8);
    param_4[2] = *(undefined4 *)(param_1 + 0xec);
  }
  return local_20;
}


// SV_HullForStudioModel  @ 08061350
void SV_HullForStudioModel
               (int param_1,float *param_2,float *param_3,undefined4 *param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  ushort **ppuVar3;
  undefined4 *puStack_68;
  int iStack_64;
  float *pfStack_60;
  undefined1 *puStack_5c;
  ushort *puStack_58;
  undefined4 *puStack_54;
  float *pfStack_50;
  float *pfStack_4c;
  float *pfStack_48;
  float *pfStack_44;
  float local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  ushort local_26;
  byte local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_10;
  float local_c;
  float local_8;
  
  bVar1 = false;
  local_30 = 0.5;
  local_10 = *param_3 - *param_2;
  local_c = param_3[1] - param_2[1];
  local_8 = param_3[2] - param_2[2];
  pfStack_44 = &local_10;
  pfStack_48 = (float *)vec3_origin;
  pfStack_4c = (float *)0x8061392;
  iVar2 = VectorCompare();
  if (((iVar2 != 0) && ((gGlobalVariables[0x84] & 1) == 0)) &&
     (bVar1 = true, (*(byte *)(param_1 + 0x260) & 8) != 0)) {
    if ((byte)(0.0 < (float)sv_clienttrace._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_clienttrace._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_clienttrace._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)
    {
      bVar1 = false;
    }
    else {
      local_30 = (float)sv_clienttrace._12_4_ * 0.5;
      local_8 = 1.0;
      local_c = 1.0;
      local_10 = 1.0;
    }
  }
  if (((*(byte *)((&DAT_0813e330)[*(int *)(param_1 + 0x170)] + 0x51) & 2) != 0) || (bVar1)) {
    pfStack_48 = (float *)local_30;
    pfStack_50 = (float *)0x806141c;
    pfStack_4c = &local_10;
    pfStack_44 = &local_10;
    VectorScale();
    *param_4 = vec3_origin._0_4_;
    param_4[1] = vec3_origin._4_4_;
    param_4[2] = vec3_origin._8_4_;
    if ((*(byte *)(param_1 + 0x260) & 8) == 0) {
      pfStack_44 = (float *)param_5;
      pfStack_48 = (float *)(param_1 + 0x1fc);
      pfStack_4c = (float *)(param_1 + 0x1f8);
      pfStack_50 = &local_10;
      puStack_54 = (undefined4 *)(param_1 + 0xe4);
      puStack_58 = (ushort *)(param_1 + 300);
      ppuVar3 = &puStack_58;
    }
    else {
      pfStack_44 = (float *)(&DAT_0813e330)[*(int *)(param_1 + 0x170)];
      pfStack_48 = (float *)0x806145e;
      pstudiohdr = Mod_Extradata();
      pfStack_50 = (float *)(pstudiohdr + *(int *)(pstudiohdr + 0xa8) +
                            *(int *)(param_1 + 0x1e4) * 0xb0);
      local_20 = *(undefined4 *)(param_1 + 300);
      local_1c = *(undefined4 *)(param_1 + 0x130);
      local_18 = *(undefined4 *)(param_1 + 0x134);
      pfStack_4c = (float *)local_24;
      puStack_54 = (undefined4 *)0x80614a8;
      pfStack_48 = (float *)&local_20;
      R_StudioPlayerBlend();
      local_26 = (ushort)local_24[0];
      local_2c = 0x7f;
      local_2b = 0x7f;
      local_2a = 0x7f;
      local_29 = 0x7f;
      puStack_54 = param_5;
      puStack_58 = &local_26;
      puStack_5c = &local_2c;
      iStack_64 = param_1 + 0xe4;
      ppuVar3 = (ushort **)&puStack_68;
      puStack_68 = &local_20;
      pfStack_60 = &local_10;
    }
    *(undefined4 *)((int)ppuVar3 + -4) = *(undefined4 *)(param_1 + 0x1e4);
    *(undefined4 *)((int)ppuVar3 + -8) = *(undefined4 *)(param_1 + 0x1ec);
    *(undefined4 *)((int)ppuVar3 + -0xc) = (&DAT_0813e330)[*(int *)(param_1 + 0x170)];
    *(undefined4 *)((int)ppuVar3 + -0x10) = 0x806153c;
    R_StudioHull();
  }
  else {
    *param_5 = 1;
    pfStack_44 = (float *)param_4;
    pfStack_48 = param_3;
    pfStack_4c = param_2;
    pfStack_50 = (float *)param_1;
    puStack_54 = (undefined4 *)0x8061558;
    SV_HullForEntity();
  }
  return;
}


// SV_HullPointContents  @ 08083b40
int SV_HullPointContents(int *param_1,int param_2,float *param_3)

{
  short sVar1;
  int *piVar2;
  float *pfVar3;
  float local_8;
  
  while (-1 < param_2) {
    if ((param_2 < param_1[2]) || (param_1[3] < param_2)) {
      Sys_Error("SV_HullPointContents: bad node number");
    }
    piVar2 = (int *)(*param_1 + param_2 * 8);
    pfVar3 = (float *)(param_1[1] + *piVar2 * 0x14);
    if (*(byte *)(pfVar3 + 4) < 3) {
      local_8 = param_3[*(byte *)(pfVar3 + 4)] - pfVar3[3];
    }
    else {
      local_8 = (pfVar3[2] * param_3[2] + pfVar3[1] * param_3[1] + *pfVar3 * *param_3) - pfVar3[3];
    }
    if (0.0 <= local_8) {
      sVar1 = (short)piVar2[1];
    }
    else {
      sVar1 = *(short *)((int)piVar2 + 6);
    }
    param_2 = (int)sVar1;
  }
  return param_2;
}


// SV_Impact  @ 0807a660
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_Impact(int param_1,int param_2,undefined4 param_3)

{
  gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
  if (((*(uint *)(param_1 + 0x260) | *(uint *)(param_2 + 0x260)) & 0x40000000) == 0) {
    if (*(int *)(param_1 + 0x1c8) != 0) {
      SV_SetGlobalTrace(param_3);
      (*DAT_08178eb0)(param_1,param_2);
    }
    if (*(int *)(param_2 + 0x1c8) != 0) {
      SV_SetGlobalTrace(param_3);
      (*DAT_08178eb0)(param_2,param_1);
    }
  }
  return;
}


// SV_InactivateClients  @ 08059b80
void SV_InactivateClients(void)

{
  int *piVar1;
  int iVar2;
  
  if (0 < svs) {
    iVar2 = 0;
    piVar1 = DAT_0816dd10;
    do {
      if (((*piVar1 != 0) || (piVar1[2] != 0)) || (piVar1[1] != 0)) {
        SZ_Clear(piVar1 + 0x1e);
        *piVar1 = 0;
        piVar1[2] = 1;
        piVar1[1] = 0;
        COM_ClearCustomizationList(piVar1 + 0x148d,0);
        piVar1[0xfcd] = 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x14ae;
    } while (iVar2 < svs);
  }
  return;
}


// SV_Info_f  @ 080803f0
void SV_Info_f(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    uVar2 = Cmd_Argv(1);
    uVar2 = __strtol_internal(uVar2,0,10,0);
    iVar1 = SV_SetPlayer(uVar2);
    if (iVar1 != 0) {
      Info_Print(host_client + 0x4f18);
    }
  }
  else {
    Con_Printf("Usage: info <userid>\n");
  }
  return;
}


// SV_Init  @ 08070d40
void SV_Init(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  Cmd_AddCommand("logaddress",SV_SetLogAddress_f);
  Cmd_AddCommand(&DAT_080a413c,SV_ServerLog_f);
  Cmd_AddCommand("serverinfo",SV_Serverinfo_f);
  Cmd_AddCommand("localinfo",SV_Localinfo_f);
  Cmd_AddCommand("showinfo",SV_ShowServerinfo_f);
  Cmd_AddCommand(&DAT_080a415e,SV_User_f);
  Cmd_AddCommand("users",SV_Users_f);
  Cvar_RegisterVariable(sv_sendvelocity);
  Cvar_RegisterVariable(sv_logrelay);
  Cvar_RegisterVariable(sv_smartdelta);
  Cvar_RegisterVariable(sv_lan);
  Cvar_RegisterVariable(sv_password);
  Cvar_RegisterVariable(sv_idealpitchscale);
  Cvar_RegisterVariable(sv_aim);
  Cvar_RegisterVariable(sv_language);
  Cvar_RegisterVariable(violence_hblood);
  Cvar_RegisterVariable(violence_ablood);
  Cvar_RegisterVariable(violence_hgibs);
  Cvar_RegisterVariable(violence_agibs);
  Cvar_RegisterVariable(sv_newunit);
  Cvar_RegisterVariable(sv_gravity);
  Cvar_RegisterVariable(sv_friction);
  Cvar_RegisterVariable(sv_edgefriction);
  Cvar_RegisterVariable(sv_stopspeed);
  Cvar_RegisterVariable(sv_maxspeed);
  Cvar_RegisterVariable(sv_accelerate);
  Cvar_RegisterVariable(sv_stepsize);
  Cvar_RegisterVariable(sv_clipmode);
  Cvar_RegisterVariable(sv_bounce);
  Cvar_RegisterVariable(sv_airmove);
  Cvar_RegisterVariable(sv_airaccelerate);
  Cvar_RegisterVariable(sv_wateraccelerate);
  Cvar_RegisterVariable(sv_waterfriction);
  Cvar_RegisterVariable(sv_challengetime);
  Cvar_RegisterVariable(timeout);
  Cvar_RegisterVariable(sv_clienttrace);
  Cvar_RegisterVariable(sv_zmax);
  Cvar_RegisterVariable(sv_wateramp);
  Cvar_RegisterVariable(sv_skyname);
  Cvar_RegisterVariable(sv_maxvelocity);
  Cvar_RegisterVariable(showtriggers);
  Cvar_RegisterVariable(sv_cheats);
  Cvar_RegisterVariable(spectator_password);
  Cvar_RegisterVariable(max_spectators);
  Cvar_RegisterVariable(sv_spectalk);
  Cvar_RegisterVariable(sv_spectatormaxspeed);
  Cvar_RegisterVariable(sv_netsize);
  Cvar_RegisterVariable(sv_showcmd);
  Cvar_RegisterVariable(pm_pushfix);
  Cvar_RegisterVariable(&sv_upload_maxsize);
  Cvar_RegisterVariable(&sv_allow_download);
  Cvar_RegisterVariable(&sv_allow_upload);
  Pmove_Init();
  iVar3 = 0;
  do {
    sprintf(localmodels + iVar3 * 5,"*%i",iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x200);
  if (0 < DAT_08166d04) {
    iVar3 = 0;
    do {
      puVar1 = (undefined4 *)(DAT_0816dd10 + iVar3 * 0x52b8);
      SV_ClearFrames(puVar1 + 0x13c1);
      puVar4 = puVar1;
      for (iVar2 = 0x14ae; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      puVar1[0x142d] = puVar1 + 0x1414;
      puVar1[0x142c] = puVar1 + 0x1414;
      puVar1[0x1447] = puVar1 + 0x142e;
      puVar1[0x1446] = puVar1 + 0x142e;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_08166d04);
  }
  SV_AllocClientFrames();
  return;
}


// SV_InitBoxHull  @ 08082220
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_InitBoxHull(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_10;
  uint local_8;
  
  box_hull = box_clipnodes;
  DAT_080c7ac4 = box_planes;
  _DAT_080c7ac8 = 0;
  _DAT_080c7acc = 5;
  puVar2 = &box_hull;
  puVar3 = &beam_hull;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_080c7b04 = beam_planes;
  for (local_8 = 0; (int)local_8 < 6; local_8 = local_8 + 1) {
    *(uint *)(box_clipnodes + local_8 * 8) = local_8;
    *(undefined2 *)(box_clipnodes + (local_8 & 1) * 2 + local_8 * 8 + 4) = 0xffff;
    if (local_8 == 5) {
      box_clipnodes._44_2_ = 0xfffe;
    }
    else {
      *(short *)(box_clipnodes + (local_8 & 1 ^ 1) * 2 + local_8 * 8 + 4) = (short)local_8 + 1;
    }
    local_10 = (undefined1)((int)local_8 >> 1);
    box_planes[local_8 * 0x14 + 0x10] = local_10;
    *(undefined4 *)(box_planes + ((int)local_8 >> 1) * 4 + local_8 * 0x14) = 0x3f800000;
    beam_planes[local_8 * 0x14 + 0x10] = 5;
  }
  return;
}


// SV_InitStudioHull  @ 0805f950
void SV_InitStudioHull(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_080bd9e4 == 0) {
    uVar1 = 0;
    do {
      (&studio_clipnodes)[uVar1 * 2] = uVar1;
      (&DAT_080bede4)[uVar1 * 4 + (uVar1 & 1)] = 0xffff;
      if (uVar1 == 5) {
        uRam080bee0c = 0xfffe;
      }
      else {
        (&DAT_080bede4)[uVar1 * 4 + (uVar1 & 1 ^ 1)] = (short)uVar1 + 1;
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < 6);
    iVar2 = 0;
    do {
      (&studio_hull)[iVar2 * 10] = &studio_clipnodes;
      (&DAT_080bd9e4)[iVar2 * 10] = (int)(&studio_planes + iVar2 * 0x1e);
      (&DAT_080bd9e8)[iVar2 * 10] = 0;
      (&DAT_080bd9ec)[iVar2 * 10] = 5;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x80);
  }
  return;
}


// SV_Keys_f  @ 08079020
void SV_Keys_f(void)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char local_404 [1024];
  
  if (sv == 0) {
    pcVar3 = "Not running a server\n";
  }
  else {
    Con_Printf("CD Keys =================\n");
    iVar2 = 0;
    if (0 < svs) {
      piVar1 = DAT_0816dd10;
      do {
        if (((*piVar1 != 0) || (piVar1[2] != 0)) || (piVar1[1] != 0)) {
          sprintf(local_404,"%3i %s : %s\n",iVar2 + 1,(int)piVar1 + 0x5005,piVar1 + 0x13f9);
          Con_Printf(local_404);
        }
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 0x14ae;
      } while (iVar2 < svs);
    }
    pcVar3 = "==========================\n";
  }
  Con_Printf(pcVar3);
  return;
}


// SV_LinkContents  @ 08083cd0
int SV_LinkContents(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  int local_18;
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)param_1[7];
  do {
    if (local_8 == param_1 + 6) {
      if (*param_1 == -1) {
        iVar3 = -1;
      }
      else if (param_2[*param_1] <= (float)param_1[1]) {
        fVar1 = param_2[*param_1];
        fVar2 = (float)param_1[1];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
          iVar3 = SV_LinkContents(param_1[3],param_2);
        }
        else {
          iVar3 = -1;
        }
      }
      else {
        iVar3 = SV_LinkContents(param_1[2],param_2);
      }
      return iVar3;
    }
    local_c = (int *)local_8[1];
    local_10 = local_8 + -2;
    if (((((local_8[0x70] == 0) && ((&DAT_0813e330)[local_8[0x5a]] != 0)) &&
         (*(int *)((&DAT_0813e330)[local_8[0x5a]] + 0x44) == 0)) &&
        ((*param_2 <= (float)local_8[0x61] && (param_2[1] <= (float)local_8[0x62])))) &&
       (param_2[2] <= (float)local_8[99])) {
      fVar1 = *param_2;
      fVar2 = (float)local_8[0x5e];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        fVar1 = param_2[1];
        fVar2 = (float)local_8[0x5f];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          fVar1 = param_2[2];
          fVar2 = (float)local_8[0x60];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            if ((local_8[0x71] < -100) || (100 < local_8[0x71])) {
              Con_DPrintf("Invalid contents on trigger field: %s\n",local_8[0x35] + pr_strings);
            }
            local_18 = SV_HullForBsp(local_10,vec3_origin,vec3_origin,&local_24);
            local_30 = *param_2 - local_24;
            local_2c = param_2[1] - local_20;
            local_28 = param_2[2] - local_1c;
            iVar3 = SV_HullPointContents(local_18,*(undefined4 *)(local_18 + 8),&local_30);
            if (iVar3 != -1) {
              return local_10[0x73];
            }
            local_14 = 0xffffffff;
          }
        }
      }
    }
    local_8 = local_c;
  } while( true );
}


// SV_LinkEdict  @ 08083780
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_LinkEdict(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  size_t sVar3;
  undefined4 local_c;
  int *local_8;
  
  if (param_1[2] != 0) {
    SV_UnlinkEdict(param_1);
  }
  if ((param_1 != DAT_0814043c) && (*param_1 == 0)) {
    (*_DAT_08178ec4)(param_1);
    if ((param_1[0x71] == 0xc) && (param_1[0x94] != 0)) {
      param_1[4] = *(int *)(param_1[0x94] + 0x10);
      memcpy(param_1 + 5,(void *)(param_1[0x94] + 0x14),0x30);
    }
    else {
      param_1[4] = 0;
      local_c = 0xffffffff;
      if (param_1[0x5c] != 0) {
        SV_FindTouchedLeafs(param_1,*(undefined4 *)(DAT_0811d320 + 0xa4),&local_c);
      }
      if (0x18 < param_1[4]) {
        param_1[4] = -1;
        *(short *)(param_1 + 5) = (short)local_c;
      }
    }
    if ((param_1[0x72] != 0) || (param_1[0x73] < -1)) {
      if ((param_1[0x72] == 4) &&
         (((&DAT_0813e330)[param_1[0x5c]] == 0 &&
          (sVar3 = strlen((char *)(param_1[0x5d] + pr_strings)), sVar3 == 0)))) {
        Con_DPrintf("Inserted %s with no model\n",param_1[0x37] + pr_strings);
      }
      else {
        local_8 = &sv_areanodes;
        while (*local_8 != -1) {
          if ((float)param_1[*local_8 + 0x60] <= (float)local_8[1]) {
            fVar1 = (float)param_1[*local_8 + 99];
            fVar2 = (float)local_8[1];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) break;
            local_8 = (int *)local_8[3];
          }
          else {
            local_8 = (int *)local_8[2];
          }
        }
        if (param_1[0x72] == 1) {
          InsertLinkBefore(param_1 + 2,local_8 + 4);
        }
        else {
          InsertLinkBefore(param_1 + 2,local_8 + 6);
        }
        if (param_2 != 0) {
          SV_TouchLinks(param_1,&sv_areanodes);
        }
      }
    }
  }
  return;
}


// SV_ListIP_f  @ 08078e90
void SV_ListIP_f(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  Con_Printf();
  iVar3 = 0;
  if (0 < numipfilters) {
    do {
      uVar2 = (&DAT_08162ce4)[iVar3 * 4];
      fVar1 = (float)(&DAT_08162cec)[iVar3 * 4];
      uStack_7 = (undefined1)(uVar2 >> 8);
      uStack_6 = (undefined1)(uVar2 >> 0x10);
      uStack_5 = (undefined1)(uVar2 >> 0x18);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        Con_Printf("%3i.%3i.%3i.%3i : permanent\n",uVar2 & 0xff,uStack_7,uStack_6,uStack_5);
      }
      else {
        Con_Printf("%3i.%3i.%3i.%3i : %.3f min\n",uVar2 & 0xff,uStack_7,uStack_6,uStack_5);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < numipfilters);
  }
  return;
}


// SV_LoadEntities  @ 08078870
void SV_LoadEntities(void)

{
  ED_LoadFromFile(*(undefined4 *)(DAT_0811d320 + 0x180));
  return;
}


// SV_Localinfo_f  @ 080708c0
void SV_Localinfo_f(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Local info settings:\n");
    Info_Print(localinfo);
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      pcVar2 = (char *)Cmd_Argv(1);
      if (*pcVar2 == '*') {
        Con_Printf("Star variables cannot be changed.\n");
      }
      else {
        uVar3 = Cmd_Argv(2,0x8000);
        uVar3 = Cmd_Argv(1,uVar3);
        Info_SetValueForKey(localinfo,uVar3);
      }
    }
    else {
      Con_Printf("usage: localinfo [ <key> <value> ]\n");
    }
  }
  return;
}


// SV_LookupSoundIndex  @ 080715b0
int SV_LookupSoundIndex(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = SV_HashString(param_1,0x3ff);
  if (DAT_0813fb30 == 0) {
    if (DAT_08140440 == 1) {
      iVar2 = 1;
      while( true ) {
        if ((&DAT_0813eb30)[iVar2] == 0) {
          return 0;
        }
        iVar4 = Q_strcasecmp(param_1,(&DAT_0813eb30)[iVar2]);
        if (iVar4 == 0) break;
        iVar2 = iVar2 + 1;
        if (0x1ff < iVar2) {
          return 0;
        }
      }
      return iVar2;
    }
    SV_BuildHashedSoundLookupTable();
  }
  sVar1 = (&DAT_0813f330)[iVar2];
  iVar4 = iVar2;
  while( true ) {
    if (sVar1 == 0) {
      return 0;
    }
    iVar3 = Q_strcasecmp(param_1,(&DAT_0813eb30)[(short)(&DAT_0813f330)[iVar4]]);
    if (iVar3 == 0) break;
    iVar4 = iVar4 + 1;
    if (0x3fe < iVar4) {
      iVar4 = 0;
    }
    if (iVar4 == iVar2) {
      return 0;
    }
    sVar1 = (&DAT_0813f330)[iVar4];
  }
  return (int)(short)(&DAT_0813f330)[iVar4];
}


// SV_ModelIndex  @ 080772d0
int SV_ModelIndex(char *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    do {
      if ((&DAT_0813db30)[iVar1] == 0) break;
      iVar2 = Q_strcasecmp((&DAT_0813db30)[iVar1],param_1);
      if (iVar2 == 0) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x200);
    if ((iVar1 == 0x200) || ((&DAT_0813db30)[iVar1] == 0)) {
      Sys_Error("SV_ModelIndex: model %s not precached",param_1);
    }
  }
  return iVar1;
}


// SV_Move  @ 08086120
undefined4 *
SV_Move(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
       undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_d4 [14];
  float local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  undefined1 local_88 [12];
  undefined1 auStack_7c [12];
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 local_68 [6];
  undefined4 local_50;
  undefined4 *local_4c;
  undefined4 local_48 [4];
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_18;
  ushort local_10;
  undefined2 local_e;
  undefined4 local_c;
  undefined4 local_8;
  
  memset(local_88,0,0x84);
  SV_ClipMoveToEntity(local_d4,DAT_0814043c,param_2,param_3,param_4,param_5);
  puVar2 = local_d4;
  puVar3 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_38 == 0.0) << 0xe) >> 8)) == 0x40) {
    puVar2 = local_48;
    puVar3 = param_1;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    local_98 = local_34;
    local_94 = local_30;
    local_90 = local_2c;
    local_4c = &local_98;
    local_9c = local_38;
    local_38 = 1.0;
    local_50 = param_2;
    local_70 = param_3;
    local_6c = param_4;
    local_10 = (ushort)param_6 & 0xff;
    local_e = (undefined2)((uint)param_6 >> 8);
    local_c = param_7;
    local_8 = param_8;
    if (param_6 == 2) {
      for (local_8c = 0; local_8c < 3; local_8c = local_8c + 1) {
        local_68[local_8c] = 0xc1700000;
        local_68[local_8c + 3] = 0x41700000;
      }
    }
    else {
      local_68[0] = *param_3;
      local_68[1] = param_3[1];
      local_68[2] = param_3[2];
      local_68[3] = *param_4;
      local_68[4] = param_4[1];
      local_68[5] = param_4[2];
    }
    SV_MoveBounds(param_2,local_68,local_68 + 3,&local_98,local_88,auStack_7c);
    SV_ClipToLinks(&sv_areanodes,local_88);
    local_38 = local_38 * local_9c;
    if (local_18 == 0) {
      gGlobalVariables._116_4_ = 0;
    }
    else {
      gGlobalVariables._116_4_ = local_18;
    }
    puVar2 = local_48;
    puVar3 = param_1;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return param_1;
}


// SV_MoveBounds  @ 08085d00
void SV_MoveBounds(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    if (*(float *)(param_4 + local_8 * 4) <= *(float *)(param_1 + local_8 * 4)) {
      *(float *)(param_5 + local_8 * 4) =
           (*(float *)(param_4 + local_8 * 4) + *(float *)(param_2 + local_8 * 4)) - 1.0;
      *(float *)(param_6 + local_8 * 4) =
           *(float *)(param_1 + local_8 * 4) + *(float *)(param_3 + local_8 * 4) + 1.0;
    }
    else {
      *(float *)(param_5 + local_8 * 4) =
           (*(float *)(param_1 + local_8 * 4) + *(float *)(param_2 + local_8 * 4)) - 1.0;
      *(float *)(param_6 + local_8 * 4) =
           *(float *)(param_4 + local_8 * 4) + *(float *)(param_3 + local_8 * 4) + 1.0;
    }
  }
  return;
}


// SV_MoveNoEnts  @ 08085e60
undefined4 *
SV_MoveNoEnts(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [14];
  float local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [12];
  undefined1 auStack_7c [12];
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined4 local_48 [4];
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_18;
  ushort local_10;
  undefined2 local_e;
  undefined4 local_c;
  undefined4 local_8;
  
  memset(local_88,0,0x84);
  SV_ClipMoveToEntity(local_d0,DAT_0814043c,param_2,param_3,param_4,param_5);
  puVar2 = local_d0;
  puVar3 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_38 == 0.0) << 0xe) >> 8)) == 0x40) {
    puVar2 = local_48;
    puVar3 = param_1;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    local_94 = local_34;
    local_90 = local_30;
    local_8c = local_2c;
    local_4c = &local_94;
    local_98 = local_38;
    local_38 = 1.0;
    local_50 = param_2;
    local_70 = param_3;
    local_6c = param_4;
    local_10 = (ushort)param_6 & 0xff;
    local_e = (undefined2)((uint)param_6 >> 8);
    local_c = param_7;
    local_8 = 0;
    local_68 = *param_3;
    local_64 = param_3[1];
    local_60 = param_3[2];
    local_5c = *param_4;
    local_58 = param_4[1];
    local_54 = param_4[2];
    SV_MoveBounds(param_2,&local_68,&local_5c,&local_94,local_88,auStack_7c);
    SV_ClipToWorldbrush(&sv_areanodes,local_88);
    local_38 = local_38 * local_98;
    if (local_18 == 0) {
      gGlobalVariables._116_4_ = 0;
    }
    else {
      gGlobalVariables._116_4_ = local_18;
    }
    puVar2 = local_48;
    puVar3 = param_1;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return param_1;
}


// SV_MoveToOnHandList  @ 0807e030
void SV_MoveToOnHandList(int param_1)

{
  if (param_1 == 0) {
    Con_DPrintf("Null resource passed to SV_MoveToOnHandList\n");
  }
  else {
    if (4 < *(uint *)(param_1 + 0x40)) {
      Con_DPrintf("Unknown resource type\n");
    }
    SV_RemoveFromResourceList(param_1);
    SV_AddToResourceList(param_1,host_client + 0x5050);
  }
  return;
}


// SV_MoveToOrigin_I  @ 0807a320
void SV_MoveToOrigin_I(int param_1,float *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  if ((*(uint *)(param_1 + 0x260) & 0x203) != 0) {
    if (param_4 == 0) {
      iVar1 = SV_StepDirection(param_1,*(undefined4 *)(param_1 + 0x168),param_3);
      if (iVar1 == 0) {
        SV_NewChaseDir2(param_1,&local_10,param_3);
      }
    }
    else {
      local_1c = local_10 - *(float *)(param_1 + 0xe4);
      local_18 = local_c - *(float *)(param_1 + 0xe8);
      local_14 = local_8 - *(float *)(param_1 + 0xec);
      if ((*(byte *)(param_1 + 0x260) & 3) == 0) {
        local_14 = 0.0;
      }
      VectorNormalize(&local_1c);
      VectorScale(&local_1c,param_3,&local_1c);
      SV_FlyDirection(param_1,&local_1c);
    }
  }
  return;
}


// SV_Multicast  @ 08071870
void SV_Multicast(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  uVar1 = SV_PointLeafnum(param_1);
  iVar5 = 0;
  piVar4 = DAT_0816dd10;
  if (0 < svs) {
    do {
      if (*piVar4 != 0) {
        iVar2 = SV_ValidClientMulticast(piVar4,uVar1,param_2);
        if (iVar2 == 0) {
          gPacketSuppressed = gPacketSuppressed + DAT_08143370;
        }
        else {
          piVar3 = piVar4 + 0xfd1;
          if (param_3 != 0) {
            piVar3 = piVar4 + 0x1e;
          }
          if (DAT_08143370 < piVar3[3] - piVar3[4]) {
            SZ_Write(piVar3,DAT_08143368,DAT_08143370);
          }
        }
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 0x14ae;
    } while (iVar5 < svs);
  }
  SZ_Clear(&DAT_08143360);
  return;
}


// SV_NewChaseDir  @ 08079a40
void SV_NewChaseDir(int param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  float local_28;
  float local_c;
  float local_8;
  
  lVar8 = (longdouble)anglemod((float)((int)ROUND(*(float *)(param_1 + 0x168) / 45.0) * 0x2d));
  fVar1 = (float)lVar8;
  lVar8 = (longdouble)anglemod(fVar1 - 180.0);
  fVar2 = (float)lVar8;
  fVar3 = *(float *)(param_2 + 0xe4) - *(float *)(param_1 + 0xe4);
  fVar4 = *(float *)(param_2 + 0xe8) - *(float *)(param_1 + 0xe8);
  if ((byte)(10.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 10.0) << 0xe) >> 8)) == 1) {
    local_c = 0.0;
  }
  else if (-10.0 <= fVar3) {
    local_c = -1.0;
  }
  else {
    local_c = 180.0;
  }
  fVar5 = local_c;
  if (-10.0 <= fVar4) {
    if ((byte)(10.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 10.0) << 0xe) >> 8)) == 1) {
      local_8 = 90.0;
    }
    else {
      local_8 = -1.0;
    }
  }
  else {
    local_8 = 270.0;
  }
  if (((byte)(-1.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_c == -1.0) << 0xe) >> 8)) != 0x40) &&
     ((byte)(local_8 < -1.0 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_8 == -1.0) << 0xe) >> 8)) != 0x40)) {
    if ((byte)((byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_28 = 315.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        local_28 = 45.0;
      }
    }
    else {
      local_28 = 215.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        local_28 = 135.0;
      }
    }
    if (((byte)(fVar2 < local_28 |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_28)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_28) << 0xe) >> 8)) != 0x40) &&
       (iVar6 = SV_StepDirection(param_1,local_28,param_3), iVar6 != 0)) {
      return;
    }
  }
  iVar6 = RandomLong(0,1);
  if (iVar6 == 0) {
    iVar6 = (int)ROUND(fVar4);
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    iVar7 = (int)ROUND(fVar3);
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    if (iVar6 <= iVar7) goto LAB_08079c6e;
  }
  local_c = local_8;
  local_8 = fVar5;
LAB_08079c6e:
  if ((((((byte)(-1.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_c == -1.0) << 0xe) >> 8)) == 0x40) ||
        ((byte)(fVar2 < local_c | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_c)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_c) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_c,param_3), iVar6 == 0)) &&
      ((((byte)(-1.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_8 == -1.0) << 0xe) >> 8)) == 0x40 ||
        ((byte)(fVar2 < local_8 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_8)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_8) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_8,param_3), iVar6 == 0)))) &&
     (((byte)(fVar1 < -1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40 ||
      (iVar6 = SV_StepDirection(param_1,fVar1,param_3), iVar6 == 0)))) {
    iVar6 = RandomLong(0,1);
    if (iVar6 == 0) {
      local_28 = 315.0;
      do {
        if (((byte)(fVar2 < local_28 |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_28)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_28) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_28,param_3), iVar6 != 0)) {
          return;
        }
        local_28 = local_28 - 45.0;
      } while ((byte)((0.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_28 == 0.0) << 0xe) >> 8)) - 1) < 0x40);
    }
    else {
      local_28 = 0.0;
      do {
        if (((byte)(fVar2 < local_28 |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_28)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_28) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_28,param_3), iVar6 != 0)) {
          return;
        }
        local_28 = local_28 + 45.0;
      } while (local_28 <= 315.0);
    }
    if (((byte)(fVar2 < -1.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) == 0x40) ||
       (iVar6 = SV_StepDirection(param_1,fVar2,param_3), iVar6 == 0)) {
      *(float *)(param_1 + 0x168) = fVar1;
      iVar6 = SV_CheckBottom(param_1);
      if (iVar6 == 0) {
        SV_FixCheckBottom(param_1);
      }
    }
  }
  return;
}


// SV_NewChaseDir2  @ 08079f30
void SV_NewChaseDir2(int param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  float local_28;
  float local_c;
  float local_8;
  
  lVar8 = (longdouble)anglemod((float)((int)ROUND(*(float *)(param_1 + 0x168) / 45.0) * 0x2d));
  fVar1 = (float)lVar8;
  lVar8 = (longdouble)anglemod(fVar1 - 180.0);
  fVar2 = (float)lVar8;
  fVar3 = *param_2 - *(float *)(param_1 + 0xe4);
  fVar4 = param_2[1] - *(float *)(param_1 + 0xe8);
  if ((byte)(10.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 10.0) << 0xe) >> 8)) == 1) {
    local_c = 0.0;
  }
  else if (-10.0 <= fVar3) {
    local_c = -1.0;
  }
  else {
    local_c = 180.0;
  }
  fVar5 = local_c;
  if (-10.0 <= fVar4) {
    if ((byte)(10.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 10.0) << 0xe) >> 8)) == 1) {
      local_8 = 90.0;
    }
    else {
      local_8 = -1.0;
    }
  }
  else {
    local_8 = 270.0;
  }
  if (((byte)(-1.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_c == -1.0) << 0xe) >> 8)) != 0x40) &&
     ((byte)(local_8 < -1.0 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_8 == -1.0) << 0xe) >> 8)) != 0x40)) {
    if ((byte)((byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_28 = 315.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        local_28 = 45.0;
      }
    }
    else {
      local_28 = 215.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        local_28 = 135.0;
      }
    }
    if (((byte)(fVar2 < local_28 |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_28)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_28) << 0xe) >> 8)) != 0x40) &&
       (iVar6 = SV_StepDirection(param_1,local_28,param_3), iVar6 != 0)) {
      return;
    }
  }
  iVar6 = RandomLong(0,1);
  if (iVar6 == 0) {
    iVar6 = (int)ROUND(fVar4);
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    iVar7 = (int)ROUND(fVar3);
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    if (iVar6 <= iVar7) goto LAB_0807a14e;
  }
  local_c = local_8;
  local_8 = fVar5;
LAB_0807a14e:
  if ((((((byte)(-1.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_c == -1.0) << 0xe) >> 8)) == 0x40) ||
        ((byte)(fVar2 < local_c | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_c)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_c) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_c,param_3), iVar6 == 0)) &&
      ((((byte)(-1.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_8 == -1.0) << 0xe) >> 8)) == 0x40 ||
        ((byte)(fVar2 < local_8 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_8)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_8) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_8,param_3), iVar6 == 0)))) &&
     (((byte)(fVar1 < -1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40 ||
      (iVar6 = SV_StepDirection(param_1,fVar1,param_3), iVar6 == 0)))) {
    iVar6 = RandomLong(0,1);
    if (iVar6 == 0) {
      local_28 = 315.0;
      do {
        if (((byte)(fVar2 < local_28 |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_28)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_28) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_28,param_3), iVar6 != 0)) {
          return;
        }
        local_28 = local_28 - 45.0;
      } while ((byte)((0.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_28 == 0.0) << 0xe) >> 8)) - 1) < 0x40);
    }
    else {
      local_28 = 0.0;
      do {
        if (((byte)(fVar2 < local_28 |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_28)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_28) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_28,param_3), iVar6 != 0)) {
          return;
        }
        local_28 = local_28 + 45.0;
      } while (local_28 <= 315.0);
    }
    if (((byte)(fVar2 < -1.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) == 0x40) ||
       (iVar6 = SV_StepDirection(param_1,fVar2,param_3), iVar6 == 0)) {
      *(float *)(param_1 + 0x168) = fVar1;
      iVar6 = SV_CheckBottom(param_1);
      if (iVar6 == 0) {
        SV_FixCheckBottom(param_1);
      }
    }
  }
  return;
}


// SV_New_f  @ 08071ed0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_New_f(void)

{
  undefined4 uVar1;
  code *pcVar2;
  char *__format;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iStack_200;
  int *piStack_1fc;
  char *pcStack_1f8;
  char *pcStack_1f4;
  char *pcStack_1f0;
  char local_1c8 [64];
  char local_188 [256];
  char local_88 [128];
  float local_8;
  
  piVar5 = host_client;
  if ((cmd_source != 1) && ((host_client[1] == 0 || (*host_client != 0)))) {
    iVar3 = host_client[0x13c2];
    host_client[2] = 1;
    *(undefined8 *)(piVar5 + 0x13be) = realtime;
    SZ_Clear();
    pcStack_1f0 = (char *)0x8071f3c;
    SV_SendServerinfo();
    if ((byte)(0.0 < (float)sv_netsize._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_netsize._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_netsize._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      pcStack_1f0 = (char *)0x8071f6a;
      Con_DPrintf();
    }
    if ((byte)(0.0 < (float)sv_netsize._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_netsize._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_netsize._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      pcStack_1f0 = (char *)0x8071f9c;
      Con_DPrintf();
    }
    host_client[0x13f7] = 1;
    uVar1 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != 0) {
      sv_gpNewUserMsgs = sv_gpUserMsgs;
      SV_SendUserReg();
    }
    sv_gpNewUserMsgs = uVar1;
    if ((byte)(0.0 < (float)sv_netsize._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_netsize._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_netsize._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      pcStack_1f0 = (char *)0x807200f;
      Con_DPrintf();
    }
    if (((*host_client != 0) || (host_client[1] != 0)) && (host_client[0x13c2] != 0)) {
      pcVar2 = DAT_08178ee0;
      if (host_client[0xfaf] != 0) {
        pcVar2 = DAT_08178f18;
      }
      (*pcVar2)();
    }
    if (host_client[0xfaf] == 0) {
      pcStack_1f0 = (char *)0x8072092;
      sprintf(local_1c8,(char *)((int)host_client + 0x5005));
      piVar5 = host_client + 5;
      piVar6 = &iStack_200;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar6 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar6 = piVar6 + 1;
      }
      __format = (char *)NET_AdrToString();
      sprintf(local_188,__format);
      pcStack_1f0 = (char *)0x80720d0;
      sprintf(local_88,"Connection rejected by game\n");
      iStack_200 = 0x80720e7;
      piStack_1fc = (int *)iVar3;
      pcStack_1f8 = local_1c8;
      pcStack_1f4 = local_188;
      pcStack_1f0 = local_88;
      iVar3 = (*DAT_08178edc)();
      if (iVar3 == 0) {
        pcStack_1f0 = (char *)0x8072100;
        MSG_WriteByte();
        pcStack_1f4 = "echo %s\n";
        pcStack_1f8 = (char *)0x807210b;
        pcStack_1f0 = local_88;
        pcStack_1f8 = (char *)va();
        piStack_1fc = host_client + 0x1e;
        iStack_200 = 0x807211a;
        MSG_WriteString();
        iStack_200 = 0;
        SV_DropClient(host_client);
        return;
      }
    }
    else {
      SV_SpawnSpectator();
      gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
      local_8 = (float)gGlobalVariables._0_4_;
      (*DAT_08178f04)();
      (*DAT_08178f14)();
    }
    if ((byte)(0.0 < (float)sv_netsize._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_netsize._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_netsize._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      pcStack_1f0 = (char *)0x8072191;
      Con_DPrintf();
    }
    pcStack_1f0 = (char *)0x80721a4;
    MSG_WriteByte();
    pcStack_1f0 = (char *)0x80721a9;
    pcStack_1f0 = (char *)Info_Serverinfo();
    pcStack_1f4 = "fullserverinfo \"%s\"\n";
    pcStack_1f8 = (char *)0x80721b4;
    pcStack_1f8 = (char *)va();
    piStack_1fc = host_client + 0x1e;
    iStack_200 = 0x80721c3;
    MSG_WriteString();
  }
  return;
}


// SV_NextDownload_f  @ 0805e620
void SV_NextDownload_f(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (*(int *)(host_client + 0x5034) != 0) {
    iVar3 = *(int *)(host_client + 0x5038) - *(int *)(host_client + 0x503c);
    iVar2 = 0x400;
    if (*(int *)(host_client + 0x5048) != 0) {
      iVar2 = *(int *)(host_client + 0x504c);
    }
    iVar1 = *(int *)(host_client + 0x503c);
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
    CRC32_ProcessBuffer(host_client + 0x5044,
                        *(int *)(host_client + 0x503c) + *(int *)(host_client + 0x5034),iVar3);
    MSG_WriteByte(host_client + 0x78,0x28);
    MSG_WriteShort(host_client + 0x78,iVar3);
    MSG_WriteShort(host_client + 0x78,iVar1 / iVar2);
    MSG_WriteLong(host_client + 0x78,*(undefined4 *)(host_client + 0x5044));
    iVar2 = host_client;
    *(int *)(host_client + 0x503c) = *(int *)(host_client + 0x503c) + iVar3;
    iVar2 = *(int *)(iVar2 + 0x5038);
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    MSG_WriteByte(host_client + 0x78,(*(int *)(host_client + 0x503c) * 100) / iVar2);
    SZ_Write(host_client + 0x78,
             (*(int *)(host_client + 0x503c) + *(int *)(host_client + 0x5034)) - iVar3,iVar3);
    if (*(int *)(host_client + 0x503c) == *(int *)(host_client + 0x5038)) {
      COM_FreeFile(*(undefined4 *)(host_client + 0x5034));
      iVar2 = host_client;
      *(undefined4 *)(host_client + 0x5034) = 0;
      *(undefined4 *)(iVar2 + 0x5048) = 0;
      *(undefined4 *)(iVar2 + 0x504c) = 0x400;
    }
  }
  return;
}


// SV_PTrack_f  @ 080721d0
void SV_PTrack_f(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      uVar2 = Cmd_Argv(1);
      iVar1 = __strtol_internal(uVar2,0,10,0);
      if ((((-1 < iVar1) && (iVar1 < svs)) && (*(int *)(DAT_0816dd10 + iVar1 * 0x52b8) != 0)) &&
         (*(int *)(DAT_0816dd10 + 0x3ebc + iVar1 * 0x52b8) == 0)) {
        *(int *)(host_client + 0x10) = iVar1 + 1;
        return;
      }
      SV_ClientPrintf("Invalid client to track\n");
    }
    *(undefined4 *)(host_client + 0x10) = 0;
  }
  return;
}


// SV_ParseResourceList  @ 0807e4e0
void SV_ParseResourceList(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__dest;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c [2];
  
  iVar3 = MSG_ReadShort();
  iVar4 = MSG_ReadShort();
  iVar5 = MSG_ReadShort();
  for (; iVar4 < iVar5; iVar4 = iVar4 + 1) {
    __dest = malloc(0x68);
    pcVar7 = __dest;
    for (iVar8 = 0x1a; iVar8 != 0; iVar8 = iVar8 + -1) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      pcVar7 = pcVar7 + 4;
    }
    uVar6 = MSG_ReadByte();
    *(undefined4 *)(__dest + 0x40) = uVar6;
    pcVar7 = (char *)MSG_ReadString();
    strcpy(__dest,pcVar7);
    uVar6 = MSG_ReadShort();
    *(undefined4 *)(__dest + 0x44) = uVar6;
    uVar6 = MSG_ReadLong();
    *(undefined4 *)(__dest + 0x48) = uVar6;
    cVar2 = MSG_ReadByte();
    __dest[0x4c] = cVar2;
    __dest[0x60] = '\0';
    __dest[0x61] = '\0';
    __dest[0x62] = '\0';
    __dest[99] = '\0';
    __dest[100] = '\0';
    __dest[0x65] = '\0';
    __dest[0x66] = '\0';
    __dest[0x67] = '\0';
    __dest[0x4c] = __dest[0x4c] & 0xfd;
    if ((__dest[0x4c] & 4U) != 0) {
      MSG_ReadBuf(0x10);
    }
    if (iVar4 == 0) {
      SV_ClearResourceList();
      SV_ClearResourceList(host_client + 0x5050);
    }
    SV_AddToResourceList(__dest);
  }
  if (iVar5 < iVar3) {
    *(undefined4 *)(host_client + 0xc) = 0;
  }
  else {
    Con_DPrintf();
    uVar6 = SV_SizeofResourceList
                      (host_client + 0x50b8,local_20,&local_1c,&local_18,&local_14,&local_10,local_c
                      );
    *(undefined4 *)(host_client + 0x51b4) = uVar6;
    uVar6 = SV_EstimateNeededResources();
    iVar4 = host_client;
    *(undefined4 *)(host_client + 0x51b8) = uVar6;
    if (*(int *)(iVar4 + 0x51b4) != 0) {
      Con_DPrintf("Custom resources total %.2fK\n",(double)*(int *)(iVar4 + 0x51b4) * 0.0009765625);
      if (local_1c != 0) {
        Con_DPrintf("  Models:  %.2fK\n",(double)local_1c * 0.0009765625);
      }
      if (local_14 != 0) {
        Con_DPrintf("  Sounds:  %.2fK\n",(double)local_14 * 0.0009765625);
      }
      if (local_18 != 0) {
        Con_DPrintf("  Decals:  %.2fK\n",(double)local_18 * 0.0009765625);
      }
      if (local_10 != 0) {
        Con_DPrintf("  Skins :  %.2fK\n",(double)local_10 * 0.0009765625);
      }
      if (local_c[0] != 0) {
        Con_DPrintf("  Generic :  %.2fK\n",(double)local_10 * 0.0009765625);
      }
      Con_DPrintf();
      if (*(int *)(host_client + 0x51b8) < 0x401) {
        uVar10 = CONCAT44(*(undefined4 *)(host_client + 0x51b8),"Resources to request: %i bytes\n");
      }
      else {
        iVar4 = *(int *)(host_client + 0x51b8);
        if (iVar4 < 0) {
          iVar4 = iVar4 + 0x3ff;
        }
        uVar10 = CONCAT44(iVar4 >> 10,"Resources to request: %iK\n");
      }
      Con_DPrintf(uVar10);
    }
    iVar4 = host_client;
    *(undefined4 *)(host_client + 0xc) = 1;
    *(undefined4 *)(iVar4 + 0x522c) = 0;
    *(undefined4 *)(iVar4 + 0x51b0) = 0;
    fVar1 = (float)realtime;
    *(float *)(iVar4 + 0x51c0) = fVar1;
    *(float *)(iVar4 + 0x51c4) = fVar1;
    *(undefined4 *)(iVar4 + 0x51bc) = *(undefined4 *)(iVar4 + 0x51b8);
    puVar9 = (undefined4 *)(iVar4 + 0x51c8);
    for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    *(undefined4 *)(host_client + 0x5228) = 0;
  }
  return;
}


// SV_ParseUpload  @ 0807d7d0
void SV_ParseUpload(void)

{
  byte *pbVar1;
  char cVar2;
  size_t __n;
  int iVar3;
  int iVar4;
  int iVar5;
  FILE *pFVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  bool bVar10;
  char *pcVar11;
  char local_310 [260];
  undefined1 local_20c [260];
  char local_108 [260];
  
  __n = MSG_ReadShort();
  iVar3 = MSG_ReadShort();
  iVar4 = MSG_ReadLong();
  iVar5 = MSG_ReadByte();
  iVar7 = host_client;
  if (*(int *)(host_client + 0x51b0) == 0) {
LAB_0807d828:
    Con_Printf("Error: Client uploaded without request\n");
    return;
  }
  iVar8 = -1;
  pcVar11 = (char *)(host_client + 0x516c);
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    cVar2 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar2 != '\0');
  if (iVar8 == -2) goto LAB_0807d828;
  *(int *)(host_client + 0x51ac) = iVar5;
  COM_FileBase(iVar7 + 0x516c,local_20c);
  if (__n == 0xffffffff) {
    if (iVar4 == -1) {
      pcVar11 = "Client refused upload %s.\n";
    }
    else {
      pcVar11 = "File %s not on client.\n";
    }
    Con_Printf(pcVar11,local_20c);
    if (*(int *)(host_client + 0x5120) != 0) {
      Con_Printf("Error:  host_client->upload shouldn\'t have been set.\n");
      fclose(*(FILE **)(host_client + 0x5120));
      *(undefined4 *)(host_client + 0x5120) = 0;
    }
    iVar7 = host_client;
    *(undefined4 *)(host_client + 0x51b0) = 0;
    pbVar1 = (byte *)(*(int *)(iVar7 + 0x5124) + 0x4c);
    *pbVar1 = *pbVar1 | 2;
    SV_MoveToOnHandList(*(undefined4 *)(host_client + 0x5124));
    return;
  }
  if (*(int *)(host_client + 0x5120) == 0) {
    sprintf(local_108,"%s/%s",com_gamedir,host_client + 0x5128);
    COM_CreatePath(local_108);
    if (iVar3 == 0) {
      pFVar6 = fopen(local_108,"wb");
      iVar7 = host_client;
      *(FILE **)(host_client + 0x5120) = pFVar6;
      CRC32_Init(iVar7 + 0x5230);
    }
    else {
      pFVar6 = fopen(local_108,"a+b");
      iVar7 = host_client;
      *(FILE **)(host_client + 0x5120) = pFVar6;
      *(undefined4 *)(iVar7 + 0x5230) = *(undefined4 *)(iVar7 + 0x5168);
    }
    if (*(int *)(host_client + 0x5120) == 0) {
      msg_readcount = msg_readcount + __n;
      Con_Printf("Failed to open %s\n",host_client + 0x5128);
      iVar7 = host_client;
      goto LAB_0807dc00;
    }
    Con_Printf("uploading %s\n",local_20c);
  }
  CRC32_ProcessBuffer(host_client + 0x5230,msg_readcount + net_message._8_4_,__n);
  fwrite((void *)(msg_readcount + net_message._8_4_),1,__n,*(FILE **)(host_client + 0x5120));
  msg_readcount = msg_readcount + __n;
  *(int *)(host_client + 0x51bc) = *(int *)(host_client + 0x51bc) - __n;
  SV_UpdateUploadCount();
  if (iVar5 != 100) {
    scr_downloading._12_4_ = (undefined4)iVar5;
    MSG_WriteByte(host_client + 0x78,0x2f);
    return;
  }
  Con_Printf("100%%\n");
  scr_downloading._12_4_ = 0xbf800000;
  fclose(*(FILE **)(host_client + 0x5120));
  sprintf(local_310,"%s/%s",com_gamedir,host_client + 0x5128);
  pFVar6 = fopen(local_310,"rb");
  iVar7 = host_client;
  *(FILE **)(host_client + 0x5120) = pFVar6;
  setvbuf(*(FILE **)(iVar7 + 0x5120),(char *)0x0,0,0x1000);
  if (*(int *)(host_client + 0x5120) != 0) {
    HPAK_AddLump(1,"custom.hpk",*(undefined4 *)(host_client + 0x5124),0,
                 *(undefined4 *)(host_client + 0x5120));
    iVar7 = *(int *)(host_client + 0x5124);
    *(byte *)(iVar7 + 0x4c) = *(byte *)(iVar7 + 0x4c) & 0xfd;
    for (iVar3 = *(int *)(host_client + 0x52b4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x80)) {
      iVar4 = 0x10;
      bVar10 = true;
      pcVar11 = (char *)(iVar3 + 0x51);
      pcVar9 = (char *)(iVar7 + 0x4d);
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar10 = *pcVar11 == *pcVar9;
        pcVar11 = pcVar11 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar10);
      if (bVar10) {
        Con_DPrintf("Duplicate resource received and ignored.\n");
        goto LAB_0807dbbd;
      }
    }
    iVar7 = COM_CreateCustomization(host_client + 0x5234,iVar7,0xffffffff,1,1,1,0,0);
    if (iVar7 == 0) {
      Con_Printf("Error parsing custom decal from %s\n",host_client + 0x5005);
    }
LAB_0807dbbd:
    fclose(*(FILE **)(host_client + 0x5120));
  }
  unlink(local_310);
  iVar7 = host_client;
  *(undefined4 *)(host_client + 0x5120) = 0;
  *(undefined4 *)(iVar7 + 0x51ac) = 0;
  *(undefined4 *)(iVar7 + 0x5230) = 0;
LAB_0807dc00:
  *(undefined4 *)(iVar7 + 0x51b0) = 0;
  return;
}


// SV_Physics  @ 0807ce40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_Physics(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
  (*DAT_08178f00)();
  iVar3 = 0;
  if (0 < DAT_08140434) {
    do {
      piVar1 = (int *)(DAT_0814043c + iVar3 * 0x2c8);
      if (*piVar1 == 0) {
        if ((byte)(0.0 < (float)gGlobalVariables._8_4_ |
                   (byte)((ushort)((ushort)NAN((float)gGlobalVariables._8_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)gGlobalVariables._8_4_ == 0.0) << 0xe) >> 8)) !=
            0x40) {
          SV_LinkEdict(piVar1,1);
        }
        if ((iVar3 < 1) || (svs < iVar3)) {
          if (((*(byte *)((int)piVar1 + 0x261) & 2) != 0) &&
             ((iVar2 = piVar1[0x96], iVar2 != 0 && ((*(byte *)(iVar2 + 0x260) & 4) != 0)))) {
            if ((*(byte *)((int)piVar1 + 0x262) & 0x40) == 0) {
              VectorScale(iVar2 + 0x120,*(undefined4 *)(iVar2 + 0x2b4),piVar1 + 0x42);
            }
            else {
              VectorMA(piVar1 + 0x42,*(undefined4 *)(iVar2 + 0x2b4),iVar2 + 0x120,piVar1 + 0x42);
            }
            *(byte *)((int)piVar1 + 0x262) = *(byte *)((int)piVar1 + 0x262) | 0x40;
          }
          if ((*(byte *)((int)piVar1 + 0x262) & 0x40) == 0) {
            VectorMA(piVar1 + 0x3f,
                     (float)((longdouble)1 + (longdouble)0.5 * (longdouble)host_frametime),
                     piVar1 + 0x42,piVar1 + 0x3f);
            piVar1[0x42] = vec3_origin._0_4_;
            piVar1[0x43] = vec3_origin._4_4_;
            piVar1[0x44] = vec3_origin._8_4_;
          }
          *(byte *)((int)piVar1 + 0x262) = *(byte *)((int)piVar1 + 0x262) & 0xbf;
          if (piVar1[0x71] == 7) {
            SV_Physics_Pusher(piVar1);
          }
          else if (piVar1[0x71] == 0) {
            SV_Physics_None(piVar1);
          }
          else if (piVar1[0x71] == 0xc) {
            SV_Physics_Follow(piVar1);
          }
          else if (piVar1[0x71] == 8) {
            SV_Physics_Noclip(piVar1);
          }
          else if ((piVar1[0x71] == 4) || (piVar1[0x71] == 0xd)) {
            SV_Physics_Step(piVar1);
          }
          else if (((piVar1[0x71] == 6) ||
                   (((piVar1[0x71] == 10 || (piVar1[0x71] == 0xb)) || (piVar1[0x71] == 5)))) ||
                  (piVar1[0x71] == 9)) {
            SV_Physics_Toss(piVar1);
          }
          else {
            Sys_Error("SV_Physics: %s bad movetype %d",piVar1[0x37] + pr_strings,piVar1[0x71]);
          }
          if ((*(byte *)((int)piVar1 + 0x263) & 0x40) != 0) {
            ED_Free(piVar1);
          }
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_08140434);
  }
  if ((byte)(0.0 < (float)gGlobalVariables._8_4_ |
             (byte)((ushort)((ushort)NAN((float)gGlobalVariables._8_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)gGlobalVariables._8_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    gGlobalVariables._8_4_ = (float)gGlobalVariables._8_4_ - 1.0;
  }
  _DAT_0811d24c = _DAT_0811d24c + host_frametime;
  return;
}


// SV_Physics_Follow  @ 0807bf80
void SV_Physics_Follow(int param_1)

{
  int iVar1;
  
  iVar1 = SV_RunThink(param_1);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x250) == 0) {
      Con_DPrintf("%s movetype FOLLOW with NULL aiment\n",*(int *)(param_1 + 0xdc) + pr_strings);
      *(undefined4 *)(param_1 + 0x1c4) = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x250);
      *(float *)(param_1 + 0xe4) = *(float *)(iVar1 + 0xe4) + *(float *)(param_1 + 0x150);
      *(float *)(param_1 + 0xe8) = *(float *)(iVar1 + 0xe8) + *(float *)(param_1 + 0x154);
      *(float *)(param_1 + 0xec) = *(float *)(iVar1 + 0xec) + *(float *)(param_1 + 0x158);
      *(undefined4 *)(param_1 + 300) = *(undefined4 *)(iVar1 + 300);
      *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(iVar1 + 0x130);
      *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(iVar1 + 0x134);
      SV_LinkEdict(param_1,1);
    }
  }
  return;
}


// SV_Physics_Noclip  @ 0807c040
void SV_Physics_Noclip(int param_1)

{
  int iVar1;
  
  iVar1 = SV_RunThink(param_1);
  if (iVar1 != 0) {
    VectorMA(param_1 + 300,(float)host_frametime,param_1 + 0x138,param_1 + 300);
    VectorMA(param_1 + 0xe4,(float)host_frametime,param_1 + 0xfc,param_1 + 0xe4);
    SV_LinkEdict(param_1,0);
  }
  return;
}


// SV_Physics_None  @ 0807bf70
void SV_Physics_None(undefined4 param_1)

{
  SV_RunThink(param_1);
  return;
}


// SV_Physics_Pusher  @ 0807baa0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_Physics_Pusher(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_14;
  
  fVar1 = *(float *)(param_1 + 0x1bc);
  fVar2 = *(float *)(param_1 + 0x1c0);
  if (*(float *)(param_1 + 0x1bc) + (float)host_frametime <= fVar2) {
    local_14 = (float)host_frametime;
  }
  else {
    local_14 = fVar2 - *(float *)(param_1 + 0x1bc);
    if (local_14 < 0.0) {
      local_14 = 0.0;
    }
  }
  if ((byte)(local_14 < 0.0 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x138)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0x138) == 0.0) << 0xe) >> 8)) == 0x40)
        && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x13c)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(param_1 + 0x13c) == 0.0) << 0xe) >> 8)) ==
            0x40)) &&
       (fVar3 = *(float *)(param_1 + 0x140),
       (byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40)) {
      SV_PushMove(param_1,local_14);
    }
    else if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xfc)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(*(float *)(param_1 + 0xfc) == 0.0) << 0xe) >> 8)) ==
               0x40) &&
             ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x100)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(param_1 + 0x100) == 0.0) << 0xe) >> 8)) ==
              0x40)) &&
            (fVar3 = *(float *)(param_1 + 0x104),
            (byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40)) {
      SV_PushRotate(param_1,local_14);
    }
    else {
      iVar4 = SV_PushRotate(param_1,local_14);
      if (iVar4 != 0) {
        fVar3 = *(float *)(param_1 + 0x1bc);
        *(float *)(param_1 + 0x1bc) = fVar1;
        SV_PushMove(param_1,local_14);
        if (*(float *)(param_1 + 0x1bc) < fVar3) {
          *(float *)(param_1 + 0x1bc) = fVar3;
        }
      }
    }
  }
  if ((fVar1 < fVar2) &&
     (((*(byte *)(param_1 + 0x262) & 0x20) != 0 ||
      (fVar1 = *(float *)(param_1 + 0x1bc),
      (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40)))) {
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
    (*DAT_08178ea8)(param_1);
  }
  return;
}


// SV_Physics_Step  @ 0807ca60
void SV_Physics_Step(float *param_1)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float **ppfVar7;
  longdouble lVar8;
  float *pfStack_7c;
  undefined1 local_64 [4];
  int local_60;
  float local_54;
  int local_34;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  pfStack_7c = param_1;
  PF_WaterMove();
  SV_CheckVelocity(param_1);
  fVar2 = param_1[0x98];
  iVar4 = SV_CheckWater(param_1);
  if ((*(short *)(param_1 + 0x98) < 0) && (0 < (int)param_1[0x9f])) {
    pfStack_7c = param_1;
    lVar8 = (longdouble)SV_Submerged();
    fVar1 = param_1[0x73];
    lVar3 = (longdouble)host_frametime;
    SV_AddGravity(param_1);
    param_1[0x41] = (float)(lVar8 * (longdouble)(int)fVar1 * lVar3) + param_1[0x41];
  }
  if ((((((uint)fVar2 & 0x200) == 0) && (((uint)param_1[0x98] & 1) == 0)) &&
      ((((uint)param_1[0x98] & 2) == 0 || ((int)param_1[0x9f] < 1)))) && (iVar4 == 0)) {
    pfStack_7c = param_1;
    SV_AddGravity();
  }
  pfStack_7c = (float *)vec_origin;
  iVar4 = VectorCompare(param_1 + 0x3f);
  if (iVar4 != 0) {
    pfStack_7c = (float *)vec_origin;
    iVar4 = VectorCompare(param_1 + 0x42);
    if (iVar4 != 0) {
      ppfVar7 = (float **)&stack0xffffff88;
      if ((byte)(0.0 < (float)gGlobalVariables._8_4_ |
                 (byte)((ushort)((ushort)NAN((float)gGlobalVariables._8_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)gGlobalVariables._8_4_ == 0.0) << 0xe) >> 8)) !=
          0x40) {
        pfStack_7c = (float *)((uint)param_1[0x98] >> 0x17 & 1);
        SV_Move(local_64,param_1 + 0x39,param_1 + 0x66,param_1 + 0x69,param_1 + 0x39,0,param_1);
        if (((local_54 < 1.0) || (ppfVar7 = &pfStack_7c, local_60 != 0)) &&
           (ppfVar7 = &pfStack_7c, local_34 != 0)) {
          SV_Impact(param_1,local_34,local_64);
          ppfVar7 = &pfStack_7c;
        }
      }
      goto LAB_0807cdcf;
    }
  }
  *(byte *)((int)param_1 + 0x261) = *(byte *)((int)param_1 + 0x261) & 0xfd;
  if (((uint)fVar2 & 0x200) != 0) {
    if (param_1[0x87] <= 0.0) {
      pfStack_7c = param_1;
      iVar4 = SV_CheckBottom();
      if (iVar4 == 0) goto LAB_0807cbf3;
    }
    local_8 = SQRT(param_1[0x40] * param_1[0x40] + param_1[0x3f] * param_1[0x3f]);
    if ((byte)(0.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_8 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = (float)sv_friction._12_4_ * param_1[0x77];
      param_1[0x77] = 1.0;
      fVar2 = local_8;
      if ((byte)(local_8 < (float)sv_stopspeed._12_4_ |
                 (byte)((ushort)((ushort)(NAN(local_8) || NAN((float)sv_stopspeed._12_4_)) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(local_8 == (float)sv_stopspeed._12_4_) << 0xe) >> 8)) == 1)
      {
        fVar2 = (float)sv_stopspeed._12_4_;
      }
      fVar2 = local_8 - fVar2 * (float)host_frametime * fVar1;
      fVar1 = fVar2;
      if (fVar2 < 0.0) {
        fVar1 = 0.0;
      }
      param_1[0x3f] = (fVar1 / local_8) * param_1[0x3f];
      param_1[0x40] = (fVar1 / local_8) * param_1[0x40];
      local_8 = fVar2;
    }
  }
LAB_0807cbf3:
  param_1[0x3f] = param_1[0x3f] + param_1[0x42];
  param_1[0x40] = param_1[0x40] + param_1[0x43];
  param_1[0x41] = param_1[0x41] + param_1[0x44];
  pfStack_7c = param_1;
  SV_CheckVelocity();
  local_8 = (float)host_frametime;
  SV_FlyMove(param_1,local_8,0);
  SV_CheckVelocity(param_1);
  param_1[0x3f] = param_1[0x3f] - param_1[0x42];
  param_1[0x40] = param_1[0x40] - param_1[0x43];
  param_1[0x41] = param_1[0x41] - param_1[0x44];
  SV_CheckVelocity(param_1);
  local_14 = param_1[0x39] + param_1[0x66];
  local_10 = param_1[0x3a] + param_1[0x67];
  local_c = param_1[0x3b] + param_1[0x68];
  local_20 = param_1[0x39] + param_1[0x69];
  local_1c = param_1[0x3a] + param_1[0x6a];
  local_18 = param_1[0x3b] + param_1[0x6b];
  local_24 = local_c - 1.0;
  iVar4 = 0;
  do {
    iVar6 = 0;
    do {
      local_2c = local_14;
      if (iVar4 != 0) {
        local_2c = local_20;
      }
      local_28 = local_10;
      if (iVar6 != 0) {
        local_28 = local_1c;
      }
      pfStack_7c = &local_2c;
      iVar5 = SV_PointContents();
      if (iVar5 == -2) {
        *(byte *)((int)param_1 + 0x261) = *(byte *)((int)param_1 + 0x261) | 2;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  pfStack_7c = (float *)0x1;
  SV_LinkEdict(param_1);
  ppfVar7 = (float **)&stack0xffffff88;
LAB_0807cdcf:
  *(float **)((int)ppfVar7 + -4) = param_1;
  *(undefined4 *)((int)ppfVar7 + -8) = 0x807cdd5;
  SV_RunThink();
  *(float **)((int)ppfVar7 + -8) = param_1;
  *(undefined4 *)((int)ppfVar7 + -0xc) = 0x807cddb;
  SV_CheckWaterTransition();
  return;
}


// SV_Physics_Toss  @ 0807c270
void SV_Physics_Toss(float *param_1)

{
  float fVar1;
  int iVar2;
  float **ppfVar3;
  float *local_60;
  float *pfStack_5c;
  float local_48;
  float local_44;
  float local_40;
  int local_3c [4];
  float local_2c;
  undefined1 local_1c [8];
  float local_14;
  float local_c;
  
  pfStack_5c = param_1;
  local_60 = (float *)0x807c281;
  SV_CheckWater();
  local_60 = param_1;
  iVar2 = SV_RunThink();
  if (iVar2 != 0) {
    fVar1 = param_1[0x41];
    if ((((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) ||
        (param_1[0x96] == 0.0)) || ((*(byte *)((int)param_1[0x96] + 0x260) & 0x28) != 0)) {
      *(byte *)((int)param_1 + 0x261) = *(byte *)((int)param_1 + 0x261) & 0xfd;
    }
    if ((*(byte *)((int)param_1 + 0x261) & 2) != 0) {
      pfStack_5c = (float *)vec_origin;
      local_60 = param_1 + 0x3f;
      iVar2 = VectorCompare();
      if (iVar2 != 0) {
        param_1[0x4e] = (float)vec3_origin._0_4_;
        param_1[0x4f] = (float)vec3_origin._4_4_;
        param_1[0x50] = (float)vec3_origin._8_4_;
        pfStack_5c = (float *)vec_origin;
        local_60 = param_1 + 0x42;
        iVar2 = VectorCompare();
        if (iVar2 != 0) {
          return;
        }
      }
    }
    pfStack_5c = param_1;
    local_60 = (float *)0x807c32a;
    SV_CheckVelocity();
    if (((param_1[0x71] != 7.00649e-45) && (param_1[0x71] != 1.54143e-44)) &&
       (param_1[0x71] != 1.26117e-44)) {
      pfStack_5c = param_1;
      local_60 = (float *)0x807c34e;
      SV_AddGravity();
    }
    pfStack_5c = param_1 + 0x4b;
    local_60 = param_1 + 0x4e;
    VectorMA(pfStack_5c,(float)host_frametime);
    param_1[0x3f] = param_1[0x3f] + param_1[0x42];
    param_1[0x40] = param_1[0x40] + param_1[0x43];
    param_1[0x41] = param_1[0x41] + param_1[0x44];
    SV_CheckVelocity(param_1);
    VectorScale(param_1 + 0x3f,(float)host_frametime,&local_48);
    param_1[0x3f] = param_1[0x3f] - param_1[0x42];
    param_1[0x40] = param_1[0x40] - param_1[0x43];
    param_1[0x41] = param_1[0x41] - param_1[0x44];
    local_60 = param_1;
    pfStack_5c = &local_48;
    SV_PushEntity(local_3c);
    SV_CheckVelocity(param_1);
    if (local_3c[0] == 0) {
      ppfVar3 = &pfStack_5c;
      if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
        if (*param_1 != 0.0) {
          return;
        }
        if (param_1[0x71] == 1.4013e-44) {
          local_60 = (float *)(2.0 - param_1[0x77]);
        }
        else if (param_1[0x71] == 1.54143e-44) {
          local_60 = (float *)0x40000000;
        }
        else {
          local_60 = (float *)0x3f800000;
        }
        ClipVelocity(param_1 + 0x3f,local_1c,param_1 + 0x3f);
        ppfVar3 = &pfStack_5c;
        if ((byte)(0.7 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_14 == 0.7) << 0xe) >> 8)) == 1) {
          local_48 = param_1[0x3f] + param_1[0x42];
          local_44 = param_1[0x40] + param_1[0x43];
          local_40 = param_1[0x41] + param_1[0x44];
          if (local_40 < (float)sv_gravity._12_4_ * (float)host_frametime) {
            *(byte *)((int)param_1 + 0x261) = *(byte *)((int)param_1 + 0x261) | 2;
            param_1[0x96] = local_c;
            param_1[0x41] = 0.0;
          }
          if ((local_40 * local_40 + local_44 * local_44 + local_48 * local_48 < 900.0) ||
             (1 < (int)param_1[0x71] - 10U)) {
            *(byte *)((int)param_1 + 0x261) = *(byte *)((int)param_1 + 0x261) | 2;
            param_1[0x96] = local_c;
            param_1[0x3f] = (float)vec3_origin._0_4_;
            param_1[0x40] = (float)vec3_origin._4_4_;
            param_1[0x41] = (float)vec3_origin._8_4_;
            param_1[0x4e] = (float)vec3_origin._0_4_;
            param_1[0x4f] = (float)vec3_origin._4_4_;
            param_1[0x50] = (float)vec3_origin._8_4_;
            ppfVar3 = &pfStack_5c;
          }
          else {
            local_60 = &local_48;
            VectorScale(param_1 + 0x3f,(1.0 - local_2c) * (float)host_frametime * 0.9);
            VectorMA(&local_48,(1.0 - local_2c) * (float)host_frametime * 0.9,param_1 + 0x42,
                     &local_48);
            SV_PushEntity(local_3c,param_1,&local_48);
            ppfVar3 = &local_60;
          }
        }
      }
      *(float **)((int)ppfVar3 + -4) = param_1;
      *(undefined4 *)((int)ppfVar3 + -8) = 0x807c674;
      SV_CheckWaterTransition();
    }
    else {
      param_1[0x3f] = (float)vec3_origin._0_4_;
      param_1[0x40] = (float)vec3_origin._4_4_;
      param_1[0x41] = (float)vec3_origin._8_4_;
      param_1[0x4e] = (float)vec3_origin._0_4_;
      param_1[0x4f] = (float)vec3_origin._4_4_;
      param_1[0x50] = (float)vec3_origin._8_4_;
    }
  }
  return;
}


// SV_PlayerRunThink  @ 0807ede0
bool SV_PlayerRunThink(int *param_1,float param_2,double param_3)

{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)param_3;
  if ((*(byte *)((int)param_1 + 0x263) & 0x40) == 0) {
    fVar1 = (float)param_1[0x70];
    if ((fVar1 <= 0.0) ||
       (param_2 = fVar2 + param_2,
       (byte)(param_2 < fVar1 | (byte)((ushort)((ushort)(NAN(param_2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == fVar1) << 0xe) >> 8)) == 1)) {
      return true;
    }
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      fVar1 = fVar2;
    }
    param_1[0x70] = 0;
    gGlobalVariables._0_4_ = fVar1;
    (*DAT_08178ea8)(param_1);
    if ((*(byte *)((int)param_1 + 0x263) & 0x40) == 0) goto LAB_0807ee76;
  }
  ED_Free(param_1);
LAB_0807ee76:
  return *param_1 == 0;
}


// SV_PointContents  @ 080840a0
int SV_PointContents(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = SV_HullPointContents(DAT_0811d320 + 0xd0,0,param_1);
  if ((local_8 < -8) && (-0xf < local_8)) {
    local_8 = -3;
  }
  if ((local_8 != -2) && (iVar1 = SV_LinkContents(&sv_areanodes,param_1), iVar1 != -1)) {
    local_8 = iVar1;
  }
  return local_8;
}


// SV_PointLeafnum  @ 08074100
int SV_PointLeafnum(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Mod_PointInLeaf(param_1,DAT_0811d320);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (iVar1 - *(int *)(DAT_0811d320 + 0x8c)) * -0x55555555 >> 4;
  }
  return iVar1;
}


// SV_PostRunCmd  @ 0807fa10
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_PostRunCmd(void)

{
  code *pcVar1;
  
  pcVar1 = _DAT_08178f1c;
  if (*(int *)(host_client + 0x3ebc) == 0) {
    pcVar1 = _DAT_08178efc;
  }
  gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
  (*pcVar1)(sv_player);
  return;
}


// SV_PreRunCmd  @ 0807ea50
void SV_PreRunCmd(void)

{
  int iVar1;
  
  iVar1 = DAT_08140438 + 7;
  if (iVar1 < 0) {
    iVar1 = DAT_08140438 + 0xe;
  }
  memset(g_playertouch,0,iVar1 >> 3);
  return;
}


// SV_PrintCusomizations_f  @ 0807ddc0
void SV_PrintCusomizations_f(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  char **ppcVar5;
  char *apcStack_28 [3];
  int iStack_1c;
  int *piStack_18;
  int local_8;
  
  if ((cmd_source == 1) && (sv == 0)) {
    piStack_18 = (int *)0x807dde0;
    Cmd_ForwardToServer();
  }
  else {
    puVar3 = &net_from;
    ppcVar5 = apcStack_28;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar5 = (char *)*puVar3;
      puVar3 = puVar3 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    iVar2 = NET_IsLocalAddress();
    if (iVar2 == 0) {
      piStack_18 = &net_from;
      iStack_1c = 1;
      apcStack_28[2] = (char *)0x807de1a;
      Host_BeginRedirect();
    }
    piVar4 = DAT_0816dd10;
    for (local_8 = 0; local_8 < svs; local_8 = local_8 + 1) {
      if (((*piVar4 != 0) || (piVar4[1] != 0)) && (piVar4[0x14ad] != 0)) {
        piStack_18 = (int *)((int)piVar4 + 0x5005);
        iStack_1c = local_8 + 1;
        apcStack_28[2] = "SV Customizations:\nPlayer %i:%s\n";
        apcStack_28[1] = (char *)0x807de5f;
        Con_DPrintf();
        iStack_1c = 1;
        for (piVar1 = (int *)piVar4[0x14ad]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x20]) {
          iVar2 = iStack_1c;
          if (*piVar1 != 0) {
            piStack_18 = piVar1 + 1;
            iVar2 = iStack_1c + 1;
            apcStack_28[2] = (char *)0x807de7c;
            SV_PrintResource();
          }
          iStack_1c = iVar2;
        }
        piStack_18 = (int *)0x80a5701;
        iStack_1c = 0x807de93;
        Con_DPrintf();
      }
      piVar4 = piVar4 + 0x14ae;
    }
    puVar3 = &net_from;
    ppcVar5 = apcStack_28;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar5 = (char *)*puVar3;
      puVar3 = puVar3 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    iVar2 = NET_IsLocalAddress();
    if (iVar2 == 0) {
      piStack_18 = (int *)0x807decd;
      Host_EndRedirect();
    }
  }
  return;
}


// SV_PrintLogos  @ 080790d0
void SV_PrintLogos(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_408;
  char local_404 [1024];
  
  Con_Printf("Server Rep. of Player Logos ===\n");
  piVar3 = DAT_0816dd10;
  for (local_408 = 0; local_408 < svs; local_408 = local_408 + 1) {
    if ((((*piVar3 != 0) || (piVar3[2] != 0)) || (piVar3[1] != 0)) &&
       (iVar2 = piVar3[0x14ad], iVar2 != 0)) {
      do {
        uVar1 = COM_BinPrintf(iVar2 + 0x51,0x10);
        sprintf(local_404,"%3i %s : %s\n",local_408,(int)piVar3 + 0x5005,uVar1);
        Con_Printf(local_404);
        iVar2 = *(int *)(iVar2 + 0x80);
      } while (iVar2 != 0);
    }
    piVar3 = piVar3 + 0x14ae;
  }
  Con_Printf("==========================\n");
  return;
}


// SV_PrintResource  @ 0807dc20
void SV_PrintResource(undefined4 param_1,int param_2)

{
  char *__format;
  
  sprintf((char *)&fatal_100,"N");
  switch(*(undefined4 *)(param_2 + 0x40)) {
  case 0:
    __format = "sound";
    break;
  case 1:
    __format = "skin";
    break;
  case 2:
    __format = "model";
    break;
  case 3:
    __format = "decal";
    break;
  case 4:
    __format = "generic";
    break;
  default:
    __format = "unknown";
  }
  sprintf(type_101,__format);
  Con_Printf("%3i %i %s:%15s %i %s\n",param_1,*(undefined4 *)(param_2 + 0x48),type_101,param_2,
             *(undefined4 *)(param_2 + 0x44),&fatal_100);
  return;
}


// SV_PrintResourceLists_f  @ 0807dce0
void SV_PrintResourceLists_f(void)

{
  int iVar1;
  int iVar2;
  
  Con_Printf("- Needed -------------------------------------------\n");
  Con_Printf("#   Name                  Size Type Index Fatal\n");
  iVar2 = 1;
  for (iVar1 = *(int *)(host_client + 0x5118); iVar1 != host_client + 0x50b8;
      iVar1 = *(int *)(iVar1 + 0x60)) {
    SV_PrintResource(iVar2,iVar1);
    iVar2 = iVar2 + 1;
  }
  Con_Printf("- On hand ------------------------------------------\n");
  Con_Printf("#   Name                  Size Type Index Fatal\n");
  for (iVar1 = *(int *)(host_client + 0x50b0); iVar1 != host_client + 0x5050;
      iVar1 = *(int *)(iVar1 + 0x60)) {
    SV_PrintResource(iVar2,iVar1);
    iVar2 = iVar2 + 1;
  }
  Con_Printf("--------------------------------------------\n\n");
  return;
}


// SV_PropagateCustomizations  @ 08077920
void SV_PropagateCustomizations(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_c;
  
  iVar2 = (int)host_client;
  host_client = DAT_0816dd10;
  for (local_c = 0; local_c < svs; local_c = local_c + 1) {
    if ((*host_client != 0) || (host_client[1] != 0)) {
      for (piVar1 = (int *)host_client[0x14ad]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x20])
      {
        if (*piVar1 != 0) {
          iVar3 = iVar2 + 0x78;
          MSG_WriteByte(iVar3,0x31);
          MSG_WriteByte(iVar3,local_c);
          MSG_WriteByte(iVar3,piVar1[0x11]);
          MSG_WriteString(iVar3,piVar1 + 1);
          MSG_WriteShort(iVar3,piVar1[0x12]);
          MSG_WriteLong(iVar3,piVar1[0x13]);
          MSG_WriteByte(iVar3,(char)piVar1[0x14]);
          if ((*(byte *)(piVar1 + 0x14) & 4) != 0) {
            SZ_Write(iVar3,(int)piVar1 + 0x51,0x10);
          }
        }
      }
    }
    host_client = host_client + 0x14ae;
  }
  host_client = (int *)iVar2;
  return;
}


// SV_PushEntity  @ 0807aef0
undefined4 * SV_PushEntity(undefined4 *param_1,int param_2,float *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c [4];
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_c;
  
  local_48 = *(float *)(param_2 + 0xe4) + *param_3;
  local_44 = *(float *)(param_2 + 0xe8) + param_3[1];
  local_40 = *(float *)(param_2 + 0xec) + param_3[2];
  uVar3 = 2;
  if (*(int *)(param_2 + 0x1c4) != 9) {
    uVar3 = *(uint *)(param_2 + 0x1c8) < 2;
  }
  SV_Move(local_3c,param_2 + 0xe4,param_2 + 0x198,param_2 + 0x1a4,&local_48,uVar3,param_2,
          (*(byte *)(param_2 + 0x262) & 0x80) != 0);
  if ((byte)(0.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) != 0x40) {
    *(undefined4 *)(param_2 + 0xe4) = local_28;
    *(undefined4 *)(param_2 + 0xe8) = local_24;
    *(undefined4 *)(param_2 + 0xec) = local_20;
  }
  SV_LinkEdict(param_2,1);
  if (local_c != 0) {
    SV_Impact(param_2,local_c,local_3c);
  }
  puVar2 = local_3c;
  puVar4 = param_1;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  return param_1;
}


// SV_PushMove  @ 0807aff0
void SV_PushMove(int param_1,float param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int aiStackY_bc [6];
  int local_7c;
  undefined1 local_78 [56];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  float local_28 [6];
  float local_10 [3];
  
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xfc)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0xfc) == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x100)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x100) == 0.0) << 0xe) >> 8)) == 0x40))
     && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x104)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(param_1 + 0x104) == 0.0) << 0xe) >> 8)) == 0x40))
  {
    *(float *)(param_1 + 0x1bc) = param_2 + *(float *)(param_1 + 0x1bc);
  }
  else {
    local_40 = *(undefined4 *)(param_1 + 0xe4);
    local_3c = *(undefined4 *)(param_1 + 0xe8);
    local_38 = *(undefined4 *)(param_1 + 0xec);
    iVar8 = 0;
    do {
      iVar5 = iVar8 * 4;
      local_28[iVar8] = param_2 * *(float *)(iVar5 + param_1 + 0xfc);
      local_28[iVar8 + 6] = *(float *)(iVar5 + param_1 + 0x180) + local_28[iVar8];
      local_28[iVar8 + 3] = *(float *)(iVar5 + 0x18c + param_1) + local_28[iVar8];
      *(float *)(iVar5 + param_1 + 0xe4) = *(float *)(iVar5 + param_1 + 0xe4) + local_28[iVar8];
      iVar8 = iVar8 + 1;
    } while (iVar8 < 3);
    *(float *)(param_1 + 0x1bc) = param_2 + *(float *)(param_1 + 0x1bc);
    SV_LinkEdict(param_1,0);
    if ((*(int *)(param_1 + 0x1c8) != 0) && (local_7c = 0, 1 < DAT_08140434)) {
      iVar8 = 1;
      puVar6 = &stack0xffffff64;
      do {
        piVar1 = (int *)(DAT_0814043c + iVar8 * 0x2c8);
        puVar7 = puVar6;
        if (((*piVar1 == 0) && (piVar1[0x71] != 7)) &&
           ((piVar1[0x71] != 0 && ((piVar1[0x71] != 0xc && (piVar1[0x71] != 8)))))) {
          if (((*(byte *)((int)piVar1 + 0x261) & 2) == 0) || (piVar1[0x96] != param_1)) {
            if ((((((float)piVar1[0x60] < local_28[3]) && ((float)piVar1[0x61] < local_28[4])) &&
                 ((float)piVar1[0x62] < local_28[5])) &&
                ((fVar2 = (float)piVar1[99],
                 0x3f < (byte)((fVar2 < local_10[0] |
                                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_10[0])) << 10) >> 8
                                      ) |
                               (byte)((ushort)((ushort)(fVar2 == local_10[0]) << 0xe) >> 8)) - 1) &&
                 (fVar2 = (float)piVar1[100],
                 0x3f < (byte)((fVar2 < local_10[1] |
                                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_10[1])) << 10) >> 8
                                      ) |
                               (byte)((ushort)((ushort)(fVar2 == local_10[1]) << 0xe) >> 8)) - 1))))
                ) && (fVar2 = (float)piVar1[0x65],
                     0x3f < (byte)((fVar2 < local_10[2] |
                                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_10[2])) << 10)
                                          >> 8) |
                                   (byte)((ushort)((ushort)(fVar2 == local_10[2]) << 0xe) >> 8)) - 1
                                  ))) {
              *(int **)(puVar6 + -4) = piVar1;
              *(undefined4 *)(puVar6 + -8) = 0x807b215;
              iVar5 = SV_TestEntityPosition();
              if (iVar5 != 0) goto LAB_0807b220;
            }
          }
          else {
LAB_0807b220:
            if (piVar1[0x71] != 3) {
              *(byte *)((int)piVar1 + 0x261) = *(byte *)((int)piVar1 + 0x261) & 0xfd;
            }
            local_34 = piVar1[0x39];
            local_30 = piVar1[0x3a];
            local_2c = piVar1[0x3b];
            *(int *)(g_moved_from + local_7c * 0xc) = piVar1[0x39];
            iVar5 = local_7c * 0xc + g_moved_from;
            *(int *)(iVar5 + 4) = piVar1[0x3a];
            *(int *)(iVar5 + 8) = piVar1[0x3b];
            *(int **)(g_moved_edict + local_7c * 4) = piVar1;
            local_7c = local_7c + 1;
            *(undefined4 *)(param_1 + 0x1c8) = 0;
            *(float **)(puVar6 + -4) = local_28;
            *(int **)(puVar6 + -8) = piVar1;
            *(undefined1 **)(puVar6 + -0xc) = local_78;
            *(undefined4 *)(puVar6 + -0x10) = 0x807b2a3;
            SV_PushEntity();
            *(undefined4 *)(param_1 + 0x1c8) = 4;
            *(int **)(puVar6 + -0x10) = piVar1;
            *(undefined4 *)(puVar6 + -0x14) = 0x807b2b3;
            iVar5 = SV_TestEntityPosition();
            puVar7 = puVar6 + -4;
            if (iVar5 != 0) {
              fVar2 = (float)piVar1[0x66];
              fVar3 = (float)piVar1[0x69];
              puVar7 = puVar6 + -4;
              if ((byte)(fVar3 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 0x40) {
                if (1 < (uint)piVar1[0x72]) {
                  piVar1[0x39] = local_34;
                  piVar1[0x3a] = local_30;
                  piVar1[0x3b] = local_2c;
                  *(undefined4 *)(puVar6 + -8) = 1;
                  *(int **)(puVar6 + -0xc) = piVar1;
                  *(undefined4 *)(puVar6 + -0x10) = 0x807b343;
                  SV_LinkEdict();
                  *(undefined4 *)(param_1 + 0xe4) = local_40;
                  *(undefined4 *)(param_1 + 0xe8) = local_3c;
                  *(undefined4 *)(param_1 + 0xec) = local_38;
                  *(undefined4 *)(puVar6 + -0x10) = 0;
                  *(int *)(puVar6 + -0x14) = param_1;
                  *(undefined4 *)(puVar6 + -0x18) = 0x807b366;
                  SV_LinkEdict();
                  *(float *)(param_1 + 0x1bc) = *(float *)(param_1 + 0x1bc) - param_2;
                  *(int **)(puVar6 + -0x18) = piVar1;
                  *(int *)(puVar6 + -0x1c) = param_1;
                  *(undefined4 *)(puVar6 + -0x20) = 0x807b37e;
                  (*DAT_08178eb4)();
                  iVar8 = 0;
                  if (local_7c < 1) {
                    return;
                  }
                  do {
                    iVar4 = g_moved_edict;
                    iVar5 = g_moved_from;
                    *(undefined4 *)(*(int *)(g_moved_edict + iVar8 * 4) + 0xe4) =
                         *(undefined4 *)(g_moved_from + iVar8 * 0xc);
                    iVar5 = iVar8 * 0xc + iVar5;
                    *(undefined4 *)(*(int *)(iVar4 + iVar8 * 4) + 0xe8) = *(undefined4 *)(iVar5 + 4)
                    ;
                    *(undefined4 *)(*(int *)(iVar4 + iVar8 * 4) + 0xec) = *(undefined4 *)(iVar5 + 8)
                    ;
                    *(undefined4 *)(puVar6 + -8) = 0;
                    *(undefined4 *)(puVar6 + -0xc) = *(undefined4 *)(iVar4 + iVar8 * 4);
                    *(undefined4 *)(puVar6 + -0x10) = 0x807b3cb;
                    SV_LinkEdict();
                    iVar8 = iVar8 + 1;
                  } while (iVar8 < local_7c);
                  return;
                }
                piVar1[0x67] = 0;
                piVar1[0x66] = 0;
                piVar1[0x69] = 0;
                piVar1[0x6a] = 0;
                piVar1[0x6b] = piVar1[0x68];
                puVar7 = puVar6 + -4;
              }
            }
          }
        }
        iVar8 = iVar8 + 1;
        puVar6 = puVar7;
      } while (iVar8 < DAT_08140434);
    }
  }
  return;
}


// SV_PushRotate  @ 0807b400
undefined4 SV_PushRotate(int param_1,float param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int local_e0;
  undefined1 local_dc [56];
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  float local_1c [4];
  float local_c;
  float local_8;
  
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x138)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x138) == 0.0) << 0xe) >> 8)) == 0x40)
      && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x13c)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0x13c) == 0.0) << 0xe) >> 8)) == 0x40)
      ) && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x140)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(param_1 + 0x140) == 0.0) << 0xe) >> 8)) ==
            0x40)) {
    *(float *)(param_1 + 0x1bc) = param_2 + *(float *)(param_1 + 0x1bc);
  }
  else {
    iVar9 = 0;
    do {
      local_1c[iVar9] = param_2 * *(float *)(iVar9 * 4 + param_1 + 0x138);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
    AngleVectors(param_1 + 300,&local_88,&local_94,&local_a0);
    local_34 = *(undefined4 *)(param_1 + 300);
    local_30 = *(undefined4 *)(param_1 + 0x130);
    local_2c = *(undefined4 *)(param_1 + 0x134);
    *(float *)(param_1 + 300) = *(float *)(param_1 + 300) + local_1c[0];
    *(float *)(param_1 + 0x130) = *(float *)(param_1 + 0x130) + local_1c[1];
    *(float *)(param_1 + 0x134) = *(float *)(param_1 + 0x134) + local_1c[2];
    AngleVectorsTranspose(param_1 + 300,&local_64,&local_70,&local_7c);
    *(float *)(param_1 + 0x1bc) = param_2 + *(float *)(param_1 + 0x1bc);
    SV_LinkEdict(param_1,0);
    if (*(int *)(param_1 + 0x1c8) != 0) {
      local_1c[0] = 0.0;
      local_1c[2] = 0.0;
      local_e0 = 0;
      iVar9 = 1;
      puVar7 = &stack0xffffff10;
      if (1 < DAT_08140434) {
        do {
          piVar1 = (int *)(DAT_0814043c + iVar9 * 0x2c8);
          puVar8 = puVar7;
          if (((*piVar1 == 0) && (piVar1[0x71] != 7)) &&
             ((piVar1[0x71] != 0 && ((piVar1[0x71] != 0xc && (piVar1[0x71] != 8)))))) {
            if (((*(byte *)((int)piVar1 + 0x261) & 2) == 0) || (piVar1[0x96] != param_1)) {
              if ((((float)piVar1[0x60] < *(float *)(param_1 + 0x18c)) &&
                  ((float)piVar1[0x61] < *(float *)(param_1 + 400))) &&
                 ((float)piVar1[0x62] < *(float *)(param_1 + 0x194))) {
                fVar2 = (float)piVar1[99];
                fVar3 = *(float *)(param_1 + 0x180);
                if (0x3f < (byte)((fVar2 < fVar3 |
                                   (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
                  fVar2 = (float)piVar1[100];
                  fVar3 = *(float *)(param_1 + 0x184);
                  if (0x3f < (byte)((fVar2 < fVar3 |
                                     (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8)
                                    | (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1))
                  {
                    fVar2 = (float)piVar1[0x65];
                    fVar3 = *(float *)(param_1 + 0x188);
                    if (0x3f < (byte)((fVar2 < fVar3 |
                                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >>
                                             8) |
                                      (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1))
                    {
                      *(int **)(puVar7 + -4) = piVar1;
                      *(undefined4 *)(puVar7 + -8) = 0x807b653;
                      iVar6 = SV_TestEntityPosition();
                      if (iVar6 != 0) goto LAB_0807b65e;
                    }
                  }
                }
              }
            }
            else {
LAB_0807b65e:
              if (piVar1[0x71] != 3) {
                *(byte *)((int)piVar1 + 0x261) = *(byte *)((int)piVar1 + 0x261) & 0xfd;
              }
              local_28 = piVar1[0x39];
              local_24 = piVar1[0x3a];
              local_20 = piVar1[0x3b];
              *(int *)(g_moved_from + local_e0 * 0xc) = piVar1[0x39];
              iVar6 = local_e0 * 0xc + g_moved_from;
              *(int *)(iVar6 + 4) = piVar1[0x3a];
              *(int *)(iVar6 + 8) = piVar1[0x3b];
              *(int **)(g_moved_edict + local_e0 * 4) = piVar1;
              local_e0 = local_e0 + 1;
              if (DAT_08140438 <= local_e0) {
                *(char **)(puVar7 + -4) = "Out of edicts in simulator!\n";
                *(undefined4 *)(puVar7 + -8) = 0x807b6e4;
                Sys_Error();
              }
              if (piVar1[0x71] == 0xd) {
                local_44 = ((float)piVar1[0x62] + (float)piVar1[0x65]) * 0.5;
                local_4c = ((float)piVar1[0x60] + (float)piVar1[99]) * 0.5 -
                           *(float *)(param_1 + 0xe4);
                local_48 = ((float)piVar1[0x61] + (float)piVar1[100]) * 0.5 -
                           *(float *)(param_1 + 0xe8);
                local_a4 = local_44;
              }
              else {
                local_4c = (float)piVar1[0x39] - *(float *)(param_1 + 0xe4);
                local_48 = (float)piVar1[0x3a] - *(float *)(param_1 + 0xe8);
                local_44 = (float)piVar1[0x3b];
              }
              local_44 = local_44 - *(float *)(param_1 + 0xec);
              local_40 = local_44 * local_80 + local_48 * local_84 + local_4c * local_88;
              local_3c = -(local_44 * local_8c + local_48 * local_90 + local_4c * local_94);
              local_38 = local_44 * local_98 + local_48 * local_9c + local_4c * local_a0;
              local_58 = local_38 * local_5c + local_3c * local_60 + local_40 * local_64;
              local_54 = local_38 * local_68 + local_3c * local_6c + local_40 * local_70;
              local_50 = local_38 * local_74 + local_3c * local_78 + local_40 * local_7c;
              local_1c[3] = local_58 - local_4c;
              local_c = local_54 - local_48;
              local_8 = local_50 - local_44;
              *(undefined4 *)(param_1 + 0x1c8) = 0;
              *(float **)(puVar7 + -4) = local_1c + 3;
              *(int **)(puVar7 + -8) = piVar1;
              *(undefined1 **)(puVar7 + -0xc) = local_dc;
              *(undefined4 *)(puVar7 + -0x10) = 0x807b875;
              SV_PushEntity();
              *(undefined4 *)(param_1 + 0x1c8) = 4;
              if (piVar1[0x71] != 0xd) {
                if ((*(byte *)(piVar1 + 0x98) & 8) == 0) {
                  piVar1[0x4b] = (int)((float)piVar1[0x4b] + local_1c[0]);
                  piVar1[0x4c] = (int)((float)piVar1[0x4c] + local_1c[1]);
                  piVar1[0x4d] = (int)((float)piVar1[0x4d] + local_1c[2]);
                }
                else {
                  piVar1[0x4f] = (int)local_1c[1];
                  piVar1[0x57] = 2;
                }
              }
              *(int **)(puVar7 + -8) = piVar1;
              *(undefined4 *)(puVar7 + -0xc) = 0x807b8e3;
              iVar6 = SV_TestEntityPosition();
              puVar8 = puVar7 + -4;
              if (iVar6 != 0) {
                fVar2 = (float)piVar1[0x66];
                fVar3 = (float)piVar1[0x69];
                puVar8 = puVar7 + -4;
                if ((byte)(fVar3 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 0x40) {
                  if (1 < (uint)piVar1[0x72]) {
                    piVar1[0x39] = local_28;
                    piVar1[0x3a] = local_24;
                    piVar1[0x3b] = local_20;
                    *(undefined4 *)(puVar7 + -8) = 1;
                    *(int **)(puVar7 + -0xc) = piVar1;
                    *(undefined4 *)(puVar7 + -0x10) = 0x807b973;
                    SV_LinkEdict();
                    *(undefined4 *)(param_1 + 300) = local_34;
                    *(undefined4 *)(param_1 + 0x130) = local_30;
                    *(undefined4 *)(param_1 + 0x134) = local_2c;
                    *(undefined4 *)(puVar7 + -0x10) = 0;
                    *(int *)(puVar7 + -0x14) = param_1;
                    *(undefined4 *)(puVar7 + -0x18) = 0x807b996;
                    SV_LinkEdict();
                    *(float *)(param_1 + 0x1bc) = *(float *)(param_1 + 0x1bc) - param_2;
                    *(int **)(puVar7 + -0x18) = piVar1;
                    *(int *)(puVar7 + -0x1c) = param_1;
                    *(undefined4 *)(puVar7 + -0x20) = 0x807b9ae;
                    (*DAT_08178eb4)();
                    iVar9 = 0;
                    if (0 < local_e0) {
                      do {
                        iVar4 = g_moved_edict;
                        iVar6 = g_moved_from;
                        *(undefined4 *)(*(int *)(g_moved_edict + iVar9 * 4) + 0xe4) =
                             *(undefined4 *)(g_moved_from + iVar9 * 0xc);
                        iVar6 = iVar9 * 0xc + iVar6;
                        *(undefined4 *)(*(int *)(iVar4 + iVar9 * 4) + 0xe8) =
                             *(undefined4 *)(iVar6 + 4);
                        *(undefined4 *)(*(int *)(iVar4 + iVar9 * 4) + 0xec) =
                             *(undefined4 *)(iVar6 + 8);
                        iVar5 = g_moved_edict;
                        iVar6 = *(int *)(iVar4 + iVar9 * 4);
                        if ((*(byte *)(iVar6 + 0x260) & 8) == 0) {
                          iVar6 = *(int *)(g_moved_edict + iVar9 * 4);
                          if (*(int *)(iVar6 + 0x1c4) != 0xd) {
                            *(float *)(iVar6 + 300) = *(float *)(iVar6 + 300) - local_1c[0];
                            iVar6 = *(int *)(iVar5 + iVar9 * 4);
                            *(float *)(iVar6 + 0x130) = *(float *)(iVar6 + 0x130) - local_1c[1];
                            iVar6 = *(int *)(iVar5 + iVar9 * 4);
                            *(float *)(iVar6 + 0x134) = *(float *)(iVar6 + 0x134) - local_1c[2];
                          }
                        }
                        else {
                          *(undefined4 *)(iVar6 + 0x13c) = 0;
                        }
                        *(undefined4 *)(puVar7 + -8) = 0;
                        *(undefined4 *)(puVar7 + -0xc) = *(undefined4 *)(g_moved_edict + iVar9 * 4);
                        *(undefined4 *)(puVar7 + -0x10) = 0x807ba65;
                        SV_LinkEdict();
                        iVar9 = iVar9 + 1;
                      } while (iVar9 < local_e0);
                    }
                    return 0;
                  }
                  piVar1[0x67] = 0;
                  piVar1[0x66] = 0;
                  piVar1[0x69] = 0;
                  piVar1[0x6a] = 0;
                  piVar1[0x6b] = piVar1[0x68];
                  puVar8 = puVar7 + -4;
                }
              }
            }
          }
          iVar9 = iVar9 + 1;
          puVar7 = puVar8;
        } while (iVar9 < DAT_08140434);
      }
    }
  }
  return 1;
}


// SV_QueryMovevarsChanged  @ 08071aa0
void SV_QueryMovevarsChanged(void)

{
  int iVar1;
  int *piVar2;
  
  if (((((((byte)((byte)((ushort)((ushort)(NAN((float)movevars._0_4_) ||
                                          NAN((float)sv_sendvelocity._12_4_)) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)movevars._0_4_ == (float)sv_sendvelocity._12_4_) <<
                                0xe) >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN((float)movevars._12_4_) ||
                                         NAN((float)sv_maxspeed._12_4_)) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)movevars._12_4_ == (float)sv_maxspeed._12_4_) << 0xe
                               ) >> 8)) == 0x40)) &&
        ((byte)((byte)((ushort)((ushort)(NAN((float)movevars._4_4_) || NAN((float)sv_gravity._12_4_)
                                        ) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)movevars._4_4_ == (float)sv_gravity._12_4_) << 0xe)
                     >> 8)) == 0x40)) &&
       ((((byte)((byte)((ushort)((ushort)(NAN((float)movevars._8_4_) ||
                                         NAN((float)sv_stopspeed._12_4_)) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)movevars._8_4_ == (float)sv_stopspeed._12_4_) << 0xe
                               ) >> 8)) == 0x40 &&
         ((byte)((byte)((ushort)((ushort)(NAN((float)movevars._16_4_) ||
                                         NAN((float)sv_spectatormaxspeed._12_4_)) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)movevars._16_4_ ==
                                        (float)sv_spectatormaxspeed._12_4_) << 0xe) >> 8)) == 0x40))
        && (((byte)((byte)((ushort)((ushort)(NAN((float)movevars._20_4_) ||
                                            NAN((float)sv_accelerate._12_4_)) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)movevars._20_4_ == (float)sv_accelerate._12_4_)
                                  << 0xe) >> 8)) == 0x40 &&
            (((byte)((byte)((ushort)((ushort)(NAN((float)movevars._24_4_) ||
                                             NAN((float)sv_airaccelerate._12_4_)) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)movevars._24_4_ ==
                                            (float)sv_airaccelerate._12_4_) << 0xe) >> 8)) == 0x40
             && ((byte)((byte)((ushort)((ushort)(NAN((float)movevars._28_4_) ||
                                                NAN((float)sv_wateraccelerate._12_4_)) << 10) >> 8)
                       | (byte)((ushort)((ushort)((float)movevars._28_4_ ==
                                                 (float)sv_wateraccelerate._12_4_) << 0xe) >> 8)) ==
                 0x40)))))))) &&
      (((byte)((byte)((ushort)((ushort)(NAN((float)movevars._32_4_) ||
                                       NAN((float)sv_friction._12_4_)) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)movevars._32_4_ == (float)sv_friction._12_4_) << 0xe)
                    >> 8)) == 0x40 &&
       ((((byte)((byte)((ushort)((ushort)(NAN((float)movevars._36_4_) ||
                                         NAN((float)sv_edgefriction._12_4_)) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)movevars._36_4_ == (float)sv_edgefriction._12_4_) <<
                               0xe) >> 8)) == 0x40 &&
         ((byte)((byte)((ushort)((ushort)(NAN((float)movevars._40_4_) ||
                                         NAN((float)sv_waterfriction._12_4_)) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)movevars._40_4_ == (float)sv_waterfriction._12_4_)
                               << 0xe) >> 8)) == 0x40)) &&
        ((byte)((byte)((ushort)((ushort)NAN((float)movevars._44_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)movevars._44_4_ == 1.0) << 0xe) >> 8)) == 0x40))))))
     && ((((byte)((byte)((ushort)((ushort)(NAN((float)movevars._48_4_) ||
                                          NAN((float)sv_bounce._12_4_)) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)movevars._48_4_ == (float)sv_bounce._12_4_) << 0xe)
                       >> 8)) == 0x40 &&
          ((byte)((byte)((ushort)((ushort)(NAN((float)movevars._52_4_) ||
                                          NAN((float)sv_stepsize._12_4_)) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)movevars._52_4_ == (float)sv_stepsize._12_4_) <<
                                0xe) >> 8)) == 0x40)) &&
         ((((byte)((byte)((ushort)((ushort)(NAN((float)movevars._56_4_) ||
                                           NAN((float)sv_maxvelocity._12_4_)) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)movevars._56_4_ == (float)sv_maxvelocity._12_4_)
                                 << 0xe) >> 8)) == 0x40 &&
           (((byte)((byte)((ushort)((ushort)(NAN((float)movevars._60_4_) ||
                                            NAN((float)sv_zmax._12_4_)) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)movevars._60_4_ == (float)sv_zmax._12_4_) << 0xe)
                         >> 8)) == 0x40 &&
            ((byte)((byte)((ushort)((ushort)(NAN((float)movevars._64_4_) ||
                                            NAN((float)sv_wateramp._12_4_)) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)movevars._64_4_ == (float)sv_wateramp._12_4_) <<
                                  0xe) >> 8)) == 0x40)))) &&
          (iVar1 = strcmp((char *)sv_skyname._4_4_,movevars + 0x44), iVar1 == 0)))))) {
    return;
  }
  SV_SetMoveVars();
  if (0 < svs) {
    iVar1 = 0;
    piVar2 = DAT_0816dd10;
    do {
      if (((*piVar2 != 0) || (piVar2[1] != 0)) || (piVar2[2] != 0)) {
        SV_WriteMovevarsToClient(piVar2 + 0x1e);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x14ae;
    } while (iVar1 < svs);
  }
  return;
}


// SV_ReachedGoal  @ 08079ec0
undefined4 SV_ReachedGoal(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    fVar2 = param_3 + *(float *)(param_1 + 0x18c + iVar3 * 4);
    fVar1 = *(float *)(param_2 + iVar3 * 4);
    if (((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) ||
       (*(float *)(param_2 + iVar3 * 4) < *(float *)(param_1 + 0x180 + iVar3 * 4) - param_3)) break;
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      return 1;
    }
  }
  return 0;
}


// SV_ReadPackets  @ 08073ac0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ReadPackets(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int *piVar6;
  undefined4 *puVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  undefined4 auStack_5c [5];
  int aiStack_48 [4];
  int *piStack_38;
  int local_20;
  float local_18 [4];
  float local_8;
  
  piStack_38 = (int *)0x8073ace;
  SV_SetClientTimes();
  pfVar5 = local_18;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar5 = 0.0;
    pfVar5 = pfVar5 + 1;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 2.0) << 0xe) >> 8)) == 0x40) {
    piStack_38 = (int *)0x8073afe;
    lVar8 = (longdouble)Sys_FloatTime();
    local_18[0] = (float)lVar8;
  }
  do {
    do {
      while( true ) {
        while( true ) {
          piStack_38 = (int *)0x1;
          aiStack_48[3] = 0x8073ca3;
          iVar1 = NET_GetPacket();
          if (iVar1 == 0) {
            if ((byte)((byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 2.0) << 0xe) >> 8)) ==
                0x40) {
              piStack_38 = (int *)0x8073ccb;
              Sys_FloatTime();
            }
            return;
          }
          piStack_38 = (int *)0x8073b15;
          lVar8 = (longdouble)Sys_FloatTime();
          piStack_38 = (int *)0x8073b1d;
          iVar1 = SV_FilterPacket();
          if (iVar1 == 0) break;
          piStack_38 = (int *)0x8073b26;
          SV_SendBan();
        }
        piStack_38 = (int *)0x8073b35;
        lVar9 = (longdouble)Sys_FloatTime();
        if ((byte)((byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 2.0) << 0xe) >> 8)) == 0x40)
        {
          local_18[2] = ((float)lVar9 - (float)lVar8) + local_18[2];
        }
        if (*(int *)net_message._8_4_ != -1) break;
        piStack_38 = (int *)0x8073b71;
        SV_ConnectionlessPacket();
      }
      local_20 = 0;
      piVar2 = DAT_0816dd10;
    } while (svs < 1);
    do {
      if (((piVar2[2] != 0) || (*piVar2 != 0)) || (piVar2[1] != 0)) {
        piVar3 = piVar2 + 5;
        piVar6 = aiStack_48;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar6 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar6 = piVar6 + 1;
        }
        puVar4 = &net_from;
        puVar7 = auStack_5c;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
        iVar1 = NET_CompareAdr();
        if (iVar1 != 0) {
          piStack_38 = (int *)0x8073be8;
          lVar8 = (longdouble)Sys_FloatTime();
          piStack_38 = piVar2 + 5;
          aiStack_48[3] = 0x8073bf4;
          iVar1 = Netchan_Process();
          if (iVar1 != 0) {
            _DAT_0816dd4c = _DAT_0816dd4c + 1;
            piVar2[0x13c0] = 1;
            piStack_38 = (int *)0x8073c10;
            lVar9 = (longdouble)Sys_FloatTime();
            aiStack_48[3] = 0x8073c19;
            piStack_38 = piVar2;
            SV_ExecuteClientMessage();
            aiStack_48[3] = 0x8073c1e;
            lVar10 = (longdouble)Sys_FloatTime();
            if ((byte)((byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 2.0) << 0xe) >> 8)) ==
                0x40) {
              local_18[3] = ((float)lVar10 - (float)lVar9) + local_18[3];
            }
          }
          piStack_38 = (int *)0x8073c53;
          lVar9 = (longdouble)Sys_FloatTime();
          if ((byte)((byte)((ushort)((ushort)NAN((float)host_speeds._12_4_) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)host_speeds._12_4_ == 2.0) << 0xe) >> 8)) ==
              0x40) {
            local_8 = ((float)lVar9 - (float)lVar8) + local_8;
          }
          break;
        }
      }
      local_20 = local_20 + 1;
      piVar2 = piVar2 + 0x14ae;
    } while (local_20 < svs);
  } while( true );
}


// SV_ReallocateDynamicData  @ 08070560
void SV_ReallocateDynamicData(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08140438;
  if (DAT_08140438 == 0) {
    Con_DPrintf("SV_ReallocateDynamicData with sv.max_edicts == 0");
  }
  else {
    if (g_moved_edict != (void *)0x0) {
      Con_Printf("Reallocate on moved_edict\n");
    }
    g_moved_edict = malloc(iVar1 * 4);
    memset(g_moved_edict,0,iVar1 * 4);
    if (g_moved_from != (void *)0x0) {
      Con_Printf("Reallocate on moved_from\n");
    }
    g_moved_from = malloc(iVar1 * 0xc);
    memset(g_moved_from,0,iVar1 * 0xc);
    if (g_playertouch != (void *)0x0) {
      Con_Printf("Reallocate on playertouch\n");
    }
    iVar2 = iVar1 + 7;
    if (iVar2 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    g_playertouch = malloc(iVar2 >> 3);
    iVar2 = iVar1 + 7;
    if (iVar2 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    memset(g_playertouch,0,iVar2 >> 3);
  }
  return;
}


// SV_RecursiveHullCheck  @ 08084210
undefined4
SV_RecursiveHullCheck
          (int *param_1,int param_2,float param_3,float param_4,float *param_5,float *param_6,
          int *param_7)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  float local_30;
  float local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float *local_c;
  int *local_8;
  
  if (param_2 < 0) {
    if (param_2 == -2) {
      param_7[1] = 1;
    }
    else {
      *param_7 = 0;
      if (param_2 == -1) {
        param_7[2] = 1;
      }
      else if (param_2 != -0xf) {
        param_7[3] = 1;
      }
    }
    uVar1 = 1;
  }
  else {
    if (((param_2 < param_1[2]) || (param_1[3] < param_2)) || (param_1[1] == 0)) {
      Sys_Error("SV_RecursiveHullCheck: bad node number");
    }
    local_8 = (int *)(*param_1 + param_2 * 8);
    local_c = (float *)(param_1[1] + *local_8 * 0x14);
    if (*(byte *)(local_c + 4) < 3) {
      local_10 = param_5[*(byte *)(local_c + 4)] - local_c[3];
      local_14 = param_6[*(byte *)(local_c + 4)] - local_c[3];
    }
    else {
      local_10 = (local_c[2] * param_5[2] + local_c[1] * param_5[1] + *local_c * *param_5) -
                 local_c[3];
      local_14 = (local_c[2] * param_6[2] + local_c[1] * param_6[1] + *local_c * *param_6) -
                 local_c[3];
    }
    if (((byte)((0.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) - 1) < 0x40) &&
       ((byte)((0.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) - 1) < 0x40)) {
      uVar1 = SV_RecursiveHullCheck
                        (param_1,(int)(short)local_8[1],param_3,param_4,param_5,param_6,param_7);
    }
    else if ((0.0 <= local_10) || (0.0 <= local_14)) {
      if (0.0 <= local_10) {
        local_18 = (local_10 - 0.03125) / (local_10 - local_14);
      }
      else {
        local_18 = (local_10 + 0.03125) / (local_10 - local_14);
      }
      if (local_18 < 0.0) {
        local_18 = 0.0;
      }
      if ((byte)(1.0 < local_18 | (byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_18 == 1.0) << 0xe) >> 8)) == 1) {
        local_18 = 1.0;
      }
      local_30 = param_3 + (param_4 - param_3) * local_18;
      for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
        (&local_28)[local_1c] =
             param_5[local_1c] + (param_6[local_1c] - param_5[local_1c]) * local_18;
      }
      uVar3 = (uint)(local_10 < 0.0);
      iVar2 = SV_RecursiveHullCheck
                        (param_1,(int)*(short *)(uVar3 * 2 + 4 + (int)local_8),param_3,local_30,
                         param_5,&local_28,param_7);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        iVar2 = SV_HullPointContents
                          (param_1,(int)*(short *)((uVar3 ^ 1) * 2 + 4 + (int)local_8),&local_28);
        if (iVar2 == -2) {
          if (*param_7 == 0) {
            if (uVar3 == 0) {
              param_7[8] = (int)*local_c;
              param_7[9] = (int)local_c[1];
              param_7[10] = (int)local_c[2];
              param_7[0xb] = (int)local_c[3];
            }
            else {
              param_7[8] = (int)((float)vec3_origin._0_4_ - *local_c);
              param_7[9] = (int)((float)vec3_origin._4_4_ - local_c[1]);
              param_7[10] = (int)((float)vec3_origin._8_4_ - local_c[2]);
              param_7[0xb] = (int)-local_c[3];
            }
            while (iVar2 = SV_HullPointContents(param_1,param_1[2],&local_28), iVar2 == -2) {
              local_18 = local_18 - 0.1;
              if (local_18 < 0.0) {
                param_7[4] = (int)local_30;
                param_7[5] = (int)local_28;
                param_7[6] = local_24;
                param_7[7] = local_20;
                Con_DPrintf("backup past 0\n");
                return 0;
              }
              local_30 = param_3 + (param_4 - param_3) * local_18;
              for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
                (&local_28)[local_1c] =
                     param_5[local_1c] + (param_6[local_1c] - param_5[local_1c]) * local_18;
              }
            }
            param_7[4] = (int)local_30;
            param_7[5] = (int)local_28;
            param_7[6] = local_24;
            param_7[7] = local_20;
            uVar1 = 0;
          }
          else {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = SV_RecursiveHullCheck
                            (param_1,(int)*(short *)((uVar3 ^ 1) * 2 + 4 + (int)local_8),local_30,
                             param_4,&local_28,param_6,param_7);
        }
      }
    }
    else {
      uVar1 = SV_RecursiveHullCheck
                        (param_1,(int)*(short *)((int)local_8 + 6),param_3,param_4,param_5,param_6,
                         param_7);
    }
  }
  return uVar1;
}


// SV_RecursiveWaterLevel  @ 0807bdd0
longdouble SV_RecursiveWaterLevel(undefined4 *param_1,float param_2,float param_3,int param_4)

{
  int iVar1;
  longdouble lVar2;
  float fVar3;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  fVar3 = (param_2 - param_3) * 0.5 + param_3;
  if (param_4 + 1 < 6) {
    local_10 = *param_1;
    local_c = param_1[1];
    local_8 = fVar3 + (float)param_1[2];
    iVar1 = SV_PointContents(&local_10);
    if (iVar1 != -3) {
      param_2 = fVar3;
      fVar3 = param_3;
    }
    lVar2 = (longdouble)SV_RecursiveWaterLevel(param_1,param_2,fVar3,param_4 + 1);
  }
  else {
    lVar2 = (longdouble)fVar3;
  }
  return lVar2;
}


// SV_RegisterResources  @ 0807dfd0
void SV_RegisterResources(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = host_client;
  *(undefined4 *)(host_client + 0xc) = 0;
  for (iVar1 = *(int *)(iVar2 + 0x50b0); iVar1 != iVar2 + 0x5050; iVar1 = *(int *)(iVar1 + 0x60)) {
    SV_CreateCustomizationList(iVar2);
    SV_Customization(iVar2,iVar1,1);
  }
  host_client = iVar2;
  return;
}


// SV_RejectConnection  @ 08072280
void SV_RejectConnection(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined4 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = net_message;
  puStack_18 = (undefined4 *)0x8072293;
  SZ_Clear();
  puStack_18 = (undefined4 *)0xffffffff;
  puStack_1c = net_message;
  uStack_20 = 0x807229f;
  MSG_WriteLong();
  uStack_20 = 0x39;
  puStack_24 = net_message;
  uStack_28 = 0x80722ab;
  MSG_WriteByte();
  uStack_28 = param_2;
  puStack_2c = net_message;
  uStack_30 = 0x80722b6;
  MSG_WriteString();
  puVar2 = param_1;
  puVar3 = auStack_40;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  NET_SendPacket(1,net_message._16_4_,net_message._8_4_);
  puStack_14 = net_message;
  puStack_18 = (undefined4 *)0x80722e6;
  SZ_Clear();
  puStack_18 = param_1;
  puStack_1c = (undefined1 *)0x80722ef;
  WON_RemoveUserbyAddress();
  return;
}


// SV_RejectConnectionForPassword  @ 08072300
void SV_RejectConnectionForPassword(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  char *pcStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined4 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = net_message;
  puStack_18 = (undefined4 *)0x8072313;
  SZ_Clear();
  puStack_18 = (undefined4 *)0xffffffff;
  puStack_1c = net_message;
  uStack_20 = 0x807231f;
  MSG_WriteLong();
  uStack_20 = 0x38;
  puStack_24 = net_message;
  pcStack_28 = (char *)0x807232b;
  MSG_WriteByte();
  pcStack_28 = "BADPASSWORD";
  puStack_2c = net_message;
  uStack_30 = 0x807233a;
  MSG_WriteString();
  puVar2 = param_1;
  puVar3 = auStack_40;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  NET_SendPacket(1,net_message._16_4_,net_message._8_4_);
  puStack_14 = net_message;
  puStack_18 = (undefined4 *)0x8072369;
  SZ_Clear();
  puStack_18 = param_1;
  puStack_1c = (undefined1 *)0x807236f;
  WON_RemoveUserbyAddress();
  return;
}


// SV_RemoveFromResourceList  @ 0807e200
void SV_RemoveFromResourceList(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 100) + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(*(int *)(param_1 + 0x60) + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}


// SV_RemoveIP_f  @ 08078db0
void SV_RemoveIP_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14;
  int local_10;
  
  uVar2 = Cmd_Argv(1,&local_14);
  iVar3 = StringToFilter(uVar2);
  if (iVar3 != 0) {
    iVar3 = 0;
    if (0 < numipfilters) {
      do {
        if (((&ipfilters)[iVar3 * 4] == local_14) && ((&DAT_08162ce4)[iVar3 * 4] == local_10)) {
          iVar3 = iVar3 + 1;
          if (iVar3 < numipfilters) {
            do {
              iVar1 = iVar3 + -1;
              (&ipfilters)[iVar1 * 4] = (&ipfilters)[iVar3 * 4];
              (&DAT_08162ce4)[iVar1 * 4] = (&DAT_08162ce4)[iVar3 * 4];
              (&DAT_08162ce8)[iVar1 * 4] = (&DAT_08162ce8)[iVar3 * 4];
              (&DAT_08162cec)[iVar1 * 4] = (&DAT_08162cec)[iVar3 * 4];
              iVar3 = iVar3 + 1;
            } while (iVar3 < numipfilters);
          }
          numipfilters = numipfilters + -1;
          Con_Printf("Filter removed.\n");
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < numipfilters);
    }
    uVar2 = Cmd_Argv(1);
    Con_Printf("Didn\'t find %s.\n",uVar2);
  }
  return;
}


// SV_RequestMissingResources  @ 0807e320
undefined4 SV_RequestMissingResources(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char local_108 [260];
  
  iVar3 = host_client;
  if ((((*(int *)(host_client + 0x5120) != 0) || (*(int *)(host_client + 0x51b0) != 0)) ||
      (*(int *)(host_client + 0xc) == 0)) || (*(int *)(host_client + 0x522c) != 0)) {
    return 0;
  }
  iVar1 = *(int *)(host_client + 0x5118);
  *(int *)(host_client + 0x5124) = iVar1;
  if (iVar1 == iVar3 + 0x50b8) {
    SV_RegisterResources();
    SV_PropagateCustomizations();
    Con_DPrintf("Custom resource propagation complete.\n");
    *(undefined4 *)(host_client + 0x522c) = 1;
    return 0;
  }
  if ((*(byte *)(iVar1 + 0x4c) & 2) != 0) {
    if (*(int *)(iVar1 + 0x40) != 3) {
      return 1;
    }
    if ((*(byte *)(iVar1 + 0x4c) & 4) == 0) {
      iVar3 = SV_CheckOrUploadFile(iVar1);
    }
    else {
      uVar2 = MD5_Print(iVar1 + 0x4d);
      sprintf(local_108,"!MD5%s",uVar2);
      iVar3 = SV_CheckOrUploadFile(local_108);
    }
    if (iVar3 == 0) {
      return 1;
    }
  }
  SV_MoveToOnHandList(iVar1);
  return 1;
}


// SV_RequestMissingResourcesFromClients  @ 0807e2d0
void SV_RequestMissingResourcesFromClients(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  host_client = DAT_0816dd10;
  if (0 < svs) {
    do {
      if (*host_client != 0) goto LAB_0807e2f8;
      iVar1 = host_client[1];
      while (iVar1 != 0) {
LAB_0807e2f8:
        iVar1 = SV_RequestMissingResources();
      }
      iVar2 = iVar2 + 1;
      host_client = host_client + 0x14ae;
    } while (iVar2 < svs);
  }
  return;
}


// SV_RequestResourceList_f  @ 0807e410
void SV_RequestResourceList_f(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    uVar2 = Cmd_Argv(1);
    iVar1 = __strtol_internal(uVar2,0,10,0);
    if ((DAT_081b9d98 == 0) && (iVar1 != DAT_08166d08)) {
      Con_Printf("Resource request with mismatched servercount\n");
    }
    else {
      uVar2 = Cmd_Argv(2);
      iVar1 = __strtol_internal(uVar2,0,10,0);
      if (iVar1 < 0) {
        Con_Printf("Resource request with bogus starting index %i\n",iVar1);
      }
      else {
        MSG_WriteByte(host_client + 0x78,0x30);
        MSG_WriteLong(host_client + 0x78,DAT_08166d08);
        MSG_WriteLong(host_client + 0x78,iVar1);
      }
    }
  }
  else {
    Con_Printf("Invalid resource request\n");
  }
  return;
}


// SV_ResetModInfo  @ 080730b0
void SV_ResetModInfo(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &gmodinfo;
  for (iVar1 = 0x8d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_08178e24 = 1;
  DAT_08178e2c = 1;
  return;
}


// SV_RunCmd  @ 0807ee90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_RunCmd(byte *param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  bool bVar14;
  longdouble lVar15;
  int local_60;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  pbVar10 = param_1;
  puVar12 = &cmd;
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = *(undefined4 *)pbVar10;
    pbVar10 = pbVar10 + 4;
    puVar12 = puVar12 + 1;
  }
  if ((byte)cmd < 0x33) {
    frametime = (float)*param_1 * 0.001;
    DropPunchAngle(frametime);
    iVar8 = sv_player;
    *(undefined4 *)(sv_player + 0x114) = vec3_origin._0_4_;
    *(undefined4 *)(iVar8 + 0x118) = vec3_origin._4_4_;
    *(undefined4 *)(iVar8 + 0x11c) = vec3_origin._8_4_;
    if (*(int *)(iVar8 + 0x15c) == 0) {
      *(undefined4 *)(iVar8 + 0x150) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(iVar8 + 0x154) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(iVar8 + 0x158) = *(undefined4 *)(param_1 + 0xc);
    }
    iVar8 = sv_player;
    *(uint *)(sv_player + 0x23c) = (uint)*(ushort *)(param_1 + 0x1e);
    if (param_1[0x20] != 0) {
      *(uint *)(iVar8 + 0x240) = (uint)param_1[0x20];
    }
    if ((((*(byte *)(sv_player + 0x261) & 2) != 0) &&
        (iVar8 = *(int *)(sv_player + 600), iVar8 != 0)) && ((*(byte *)(iVar8 + 0x260) & 4) != 0)) {
      if ((*(byte *)(sv_player + 0x262) & 0x40) == 0) {
        VectorScale(iVar8 + 0x120,*(undefined4 *)(iVar8 + 0x2b4),sv_player + 0x108);
      }
      else {
        VectorMA(sv_player + 0x108,*(undefined4 *)(iVar8 + 0x2b4),iVar8 + 0x120,sv_player + 0x108);
      }
      *(byte *)(sv_player + 0x262) = *(byte *)(sv_player + 0x262) | 0x40;
    }
    if ((*(byte *)(sv_player + 0x262) & 0x40) == 0) {
      VectorMA(sv_player + 0xfc,frametime * 0.5 + 1.0,sv_player + 0x108,sv_player + 0xfc);
      iVar8 = sv_player;
      *(undefined4 *)(sv_player + 0x108) = vec3_origin._0_4_;
      *(undefined4 *)(iVar8 + 0x10c) = vec3_origin._4_4_;
      *(undefined4 *)(iVar8 + 0x110) = vec3_origin._8_4_;
    }
    iVar8 = sv_player;
    *(byte *)(sv_player + 0x262) = *(byte *)(sv_player + 0x262) & 0xbf;
    if (*(int *)(host_client + 0x3ebc) == 0) {
      gGlobalVariables._0_4_ = (undefined4)*(double *)(host_client + 0x3efc);
      (*DAT_08178ef8)(iVar8);
      SV_PlayerRunThink(sv_player,frametime,*(undefined8 *)(host_client + 0x3efc));
    }
    iVar8 = host_client;
    *(double *)(host_client + 0x3efc) =
         (double)(frametime + (float)*(double *)(host_client + 0x3efc));
    iVar5 = sv_player;
    _DAT_081051e0 = *(float *)(iVar8 + 0x3f34);
    if (((byte)(0.0 < _DAT_081051e0 | (byte)((ushort)((ushort)NAN(_DAT_081051e0) << 10) >> 8) |
               (byte)((ushort)((ushort)(_DAT_081051e0 == 0.0) << 0xe) >> 8)) == 0x40) ||
       ((byte)(_DAT_081051e0 < (float)sv_maxspeed._12_4_ |
               (byte)((ushort)((ushort)(NAN(_DAT_081051e0) || NAN((float)sv_maxspeed._12_4_)) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(_DAT_081051e0 == (float)sv_maxspeed._12_4_) << 0xe) >> 8)) !=
        1)) {
      _DAT_081051e0 = (float)sv_maxspeed._12_4_;
    }
    fVar1 = SQRT(_DAT_0816ddd8 * _DAT_0816ddd8 +
                 _DAT_0816ddd4 * _DAT_0816ddd4 + _DAT_0816ddd0 * _DAT_0816ddd0);
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
       (_DAT_081051e0 < fVar1)) {
      fVar1 = _DAT_081051e0 / fVar1;
      _DAT_0816ddd0 = fVar1 * _DAT_0816ddd0;
      _DAT_0816ddd4 = fVar1 * _DAT_0816ddd4;
      _DAT_0816ddd8 = fVar1 * _DAT_0816ddd8;
    }
    bVar14 = (*(byte *)(sv_player + 0x261) & 0x40) != 0;
    if (bVar14) {
      _DAT_0816ddd0 = _DAT_0816ddd0 * 0.333;
      _DAT_0816ddd4 = _DAT_0816ddd4 * 0.333;
      _DAT_0816ddd8 = _DAT_0816ddd8 * 0.333;
    }
    DAT_081051c0 = (uint)bVar14;
    if ((*(uint *)(sv_player + 0x260) & 0x1001000) != 0) {
      _DAT_0816ddd0 = 0.0;
      _DAT_0816ddd4 = 0.0;
      _DAT_0816ddd8 = 0.0;
    }
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(sv_player + 0x108)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(sv_player + 0x108) == 0.0) << 0xe) >> 8)) !=
          0x40) ||
        ((byte)((byte)((ushort)((ushort)NAN(*(float *)(sv_player + 0x10c)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(sv_player + 0x10c) == 0.0) << 0xe) >> 8)) != 0x40
        )) || (fVar1 = *(float *)(sv_player + 0x110),
              (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      *(undefined4 *)(sv_player + 0x114) = *(undefined4 *)(sv_player + 0x108);
      *(undefined4 *)(iVar5 + 0x118) = *(undefined4 *)(iVar5 + 0x10c);
      *(undefined4 *)(iVar5 + 0x11c) = *(undefined4 *)(iVar5 + 0x110);
    }
    iVar8 = sv_player;
    *(float *)(sv_player + 0x150) = *(float *)(sv_player + 0x150) + *(float *)(sv_player + 0x144);
    *(float *)(iVar8 + 0x154) = *(float *)(iVar8 + 0x154) + *(float *)(iVar8 + 0x148);
    *(float *)(iVar8 + 0x158) = *(float *)(iVar8 + 0x158) + *(float *)(iVar8 + 0x14c);
    fVar1 = *(float *)(iVar8 + 0x21c);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      lVar15 = (longdouble)
               V_CalcRoll(iVar8 + 300,iVar8 + 0xfc,sv_rollangle._12_4_,sv_rollspeed._12_4_);
      iVar8 = sv_player;
      *(float *)(sv_player + 0x134) = (float)((longdouble)4.0 * lVar15);
      if (*(int *)(iVar8 + 0x15c) == 0) {
        *(float *)(iVar8 + 300) = -*(float *)(iVar8 + 0x150) / 3.0;
        *(undefined4 *)(iVar8 + 0x130) = *(undefined4 *)(iVar8 + 0x154);
      }
    }
    iVar8 = sv_player + 0xe4;
    iVar5 = sv_player + 0x198;
    iVar11 = 0;
    do {
      (&DAT_0810516c)[iVar11] =
           (*(float *)(iVar11 * 4 + iVar5) - (float)(&player_mins)[DAT_081051c0 * 3 + iVar11]) +
           *(float *)(iVar11 * 4 + iVar8);
      iVar11 = iVar11 + 1;
    } while (iVar11 < 3);
    DAT_08105164 = 1;
    _DAT_08105168 = (float)((longdouble)1000.0 * (longdouble)_DAT_0811d24c);
    _DAT_081051b4 = *(undefined4 *)(host_client + 0x3f3c);
    DAT_081051b8 = *(undefined4 *)(host_client + 0x3f40);
    DAT_08105184 = *(float *)(sv_player + 0xfc);
    DAT_08105188 = *(float *)(sv_player + 0x100);
    _DAT_0810518c = *(float *)(sv_player + 0x104);
    _DAT_08105190 = *(undefined4 *)(sv_player + 0x120);
    _DAT_08105194 = *(undefined4 *)(sv_player + 0x124);
    _DAT_08105198 = *(undefined4 *)(sv_player + 0x128);
    _DAT_08105178 = *(undefined4 *)(sv_player + 0x150);
    _DAT_0810517c = *(undefined4 *)(sv_player + 0x154);
    _DAT_08105180 = *(undefined4 *)(sv_player + 0x158);
    _DAT_0810519c = *(undefined4 *)(sv_player + 0x108);
    _DAT_081051a0 = *(undefined4 *)(sv_player + 0x10c);
    _DAT_081051a4 = *(undefined4 *)(sv_player + 0x110);
    _DAT_081051a8 = *(undefined4 *)(sv_player + 0x230);
    _DAT_081051ac = *(undefined4 *)(sv_player + 0x234);
    _DAT_081051b0 = *(undefined4 *)(sv_player + 0x238);
    _DAT_081051c4 = *(undefined4 *)(sv_player + 0x1d8);
    _DAT_081051c8 = *(undefined4 *)(sv_player + 0x1dc);
    DAT_081051d8 = *(undefined4 *)(host_client + 0x3ebc);
    _DAT_081051d0 = *(undefined4 *)(sv_player + 0x270);
    puVar12 = &cmd;
    puVar13 = &DAT_081125ac;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar13 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    }
    DAT_081051d4 = (uint)(*(float *)(sv_player + 0x21c) <= 0.0);
    DAT_081051cc = *(undefined4 *)(host_client + 0x3ef8);
    DAT_081051dc = *(int *)(sv_player + 0x1c4);
    DAT_081051bc = *(undefined4 *)(sv_player + 0x260);
    iVar8 = 0;
    do {
      (&pmove_mins)[iVar8] = (float)(&DAT_0810516c)[iVar8] - 256.0;
      (&pmove_maxs)[iVar8] = (float)(&DAT_0810516c)[iVar8] + 256.0;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 3);
    DAT_081051e4 = 1;
    DAT_08112028 = 0;
    DAT_081051f4 = DAT_0811d320;
    AddLinksToPmove(&sv_areanodes);
    if ((byte)(0.0 < (float)pm_pushfix._12_4_ |
               (byte)((ushort)((ushort)NAN((float)pm_pushfix._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)pm_pushfix._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      SV_LinkEdict();
    }
    pmove = NUM_FOR_EDICT(sv_player);
    PlayerMove();
    iVar8 = host_client;
    if (DAT_081051dc == 3) {
      _DAT_081051c8 = 0x3f800000;
    }
    *(undefined4 *)(host_client + 0x3f40) = DAT_081051b8;
    *(undefined4 *)(iVar8 + 0x3f3c) = _DAT_081051b4;
    *(undefined4 *)(iVar8 + 0x3ef8) = DAT_081051cc;
    iVar8 = sv_player;
    *(undefined4 *)(sv_player + 0x270) = _DAT_081051d0;
    *(undefined4 *)(iVar8 + 0x27c) = waterlevel;
    *(undefined4 *)(iVar8 + 0x280) = watertype;
    *(undefined4 *)(iVar8 + 0x260) = DAT_081051bc;
    *(undefined4 *)(iVar8 + 0x1dc) = _DAT_081051c8;
    if (DAT_081051d4 == 0) {
      *(int *)(iVar8 + 0x1c4) = DAT_081051dc;
    }
    if (onground == 0xffffffff) {
      *(byte *)(sv_player + 0x261) = *(byte *)(sv_player + 0x261) & 0xfd;
    }
    else {
      *(byte *)(sv_player + 0x261) = *(byte *)(sv_player + 0x261) | 2;
      uVar6 = EDICT_NUM(*(undefined4 *)(&DAT_08105214 + onground * 0x58));
      *(undefined4 *)(sv_player + 600) = uVar6;
    }
    iVar8 = sv_player;
    *(undefined4 *)(sv_player + 0x230) = _DAT_081051a8;
    *(undefined4 *)(iVar8 + 0x234) = _DAT_081051ac;
    *(undefined4 *)(iVar8 + 0x238) = _DAT_081051b0;
    onground = (uint)(onground != 0xffffffff);
    iVar11 = 0;
    iVar8 = sv_player + 0xe4;
    iVar5 = sv_player + 0x198;
    do {
      *(float *)(iVar11 * 4 + iVar8) =
           (float)(&DAT_0810516c)[iVar11] -
           (*(float *)(iVar11 * 4 + iVar5) - (float)(&player_mins)[DAT_081051c0 * 3 + iVar11]);
      iVar4 = sv_player;
      iVar11 = iVar11 + 1;
    } while (iVar11 < 3);
    if ((byte)((byte)((ushort)((ushort)NAN((float)pm_pushfix._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)pm_pushfix._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      *(float *)(sv_player + 0xfc) = DAT_08105184;
      *(float *)(iVar4 + 0x100) = DAT_08105188;
      *(float *)(iVar4 + 0x104) = _DAT_0810518c;
    }
    iVar8 = sv_player;
    *(undefined4 *)(sv_player + 0x108) = _DAT_0810519c;
    *(undefined4 *)(iVar8 + 0x10c) = _DAT_081051a0;
    *(undefined4 *)(iVar8 + 0x110) = _DAT_081051a4;
    origin = iVar8 + 0xe4;
    velocity = sv_player + 0xfc;
    if ((byte)(0.0 < (float)pm_pushfix._12_4_ |
               (byte)((ushort)((ushort)NAN((float)pm_pushfix._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)pm_pushfix._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      if (*(int *)(host_client + 0x3ebc) == 0) {
        SV_LinkEdict();
        uVar6 = *(undefined4 *)(sv_player + 0xfc);
        uVar2 = *(undefined4 *)(sv_player + 0x100);
        uVar3 = *(undefined4 *)(sv_player + 0x104);
        iVar8 = 0;
        if (0 < DAT_081125d0) {
          do {
            iVar11 = *(int *)(&DAT_08105214 + (&DAT_08112604)[iVar8 * 0x11] * 0x58);
            iVar7 = EDICT_NUM(iVar11);
            iVar4 = sv_player;
            iVar5 = iVar11;
            if (iVar11 < 0) {
              iVar5 = iVar11 + 7;
            }
            local_60 = iVar11;
            if (iVar11 < 0) {
              local_60 = iVar11 + 7;
            }
            if (((*(byte *)((iVar5 >> 3) + g_playertouch) >>
                  (iVar11 - (uint)((byte)local_60 & 0xf8) & 0x1f) & 1) == 0) &&
               ((*(byte *)(iVar7 + 0x263) & 4) == 0)) {
              local_3c = (&DAT_081125d4)[iVar8 * 0x11];
              local_38 = (&DAT_081125d8)[iVar8 * 0x11];
              local_34 = (&DAT_081125dc)[iVar8 * 0x11];
              local_30 = (&DAT_081125e0)[iVar8 * 0x11];
              local_2c = (&DAT_081125e4)[iVar8 * 0x11];
              local_28 = (&DAT_081125e8)[iVar8 * 0x11];
              local_24 = (&DAT_081125ec)[iVar8 * 0x11];
              local_20 = (&DAT_081125f0)[iVar8 * 0x11];
              local_1c = (&DAT_081125f4)[iVar8 * 0x11];
              local_18 = (&DAT_081125f8)[iVar8 * 0x11];
              local_14 = (&DAT_081125fc)[iVar8 * 0x11];
              local_10 = (&DAT_08112600)[iVar8 * 0x11];
              local_8 = (&DAT_08112614)[iVar8 * 0x11];
              *(undefined4 *)(sv_player + 0xfc) = (&DAT_08112608)[iVar8 * 0x11];
              *(undefined4 *)(iVar4 + 0x100) = (&DAT_0811260c)[iVar8 * 0x11];
              *(undefined4 *)(iVar4 + 0x104) = (&DAT_08112610)[iVar8 * 0x11];
              local_c = iVar7;
              SV_Impact(iVar7,iVar4,&local_3c);
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < DAT_081125d0);
        }
        iVar8 = sv_player;
        *(undefined4 *)(sv_player + 0xfc) = uVar6;
        *(undefined4 *)(iVar8 + 0x100) = uVar2;
        *(undefined4 *)(iVar8 + 0x104) = uVar3;
      }
    }
    else if (*(int *)(host_client + 0x3ebc) == 0) {
      local_58 = (float)vec3_origin._0_4_;
      local_54 = (float)vec3_origin._4_4_;
      local_50 = (float)vec3_origin._8_4_;
      iVar8 = 0;
      if (0 < DAT_081125d0) {
        do {
          local_58 = local_58 + (float)(&DAT_08112608)[iVar8 * 0x11];
          local_54 = local_54 + (float)(&DAT_0811260c)[iVar8 * 0x11];
          local_50 = local_50 + (float)(&DAT_08112610)[iVar8 * 0x11];
          iVar8 = iVar8 + 1;
        } while (iVar8 < DAT_081125d0);
      }
      PM_CheckVelocity();
      iVar8 = sv_player;
      *(float *)(sv_player + 0xfc) = DAT_08105184 + local_58;
      *(float *)(iVar8 + 0x100) = DAT_08105188 + local_54;
      *(float *)(iVar8 + 0x104) = _DAT_0810518c + local_50;
      SV_LinkEdict();
    }
    SV_PostRunCmd();
  }
  else {
    bVar9 = (byte)((int)(uint)*param_1 >> 1);
    cmd._0_1_ = bVar9;
    SV_RunCmd(&cmd);
    DAT_0816dde0 = 0;
    cmd._0_1_ = bVar9;
    SV_RunCmd();
  }
  return;
}


// SV_RunThink  @ 0807a5b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool SV_RunThink(int *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  if ((*(byte *)((int)param_1 + 0x263) & 0x40) == 0) {
    lVar1 = (longdouble)(float)param_1[0x70];
    if ((lVar1 <= (longdouble)0) ||
       (lVar2 = (longdouble)_DAT_0811d24c + (longdouble)host_frametime,
       (byte)(lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) == 1)) {
      return true;
    }
    lVar2 = (longdouble)_DAT_0811d24c;
    if ((byte)(lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) == 1) {
      lVar1 = (longdouble)(float)_DAT_0811d24c;
    }
    param_1[0x70] = 0;
    gGlobalVariables._0_4_ = (undefined4)lVar1;
    (*DAT_08178ea8)(param_1);
    if ((*(byte *)((int)param_1 + 0x263) & 0x40) == 0) goto LAB_0807a648;
  }
  ED_Free(param_1);
LAB_0807a648:
  return *param_1 == 0;
}


// SV_SaveSpawnparms  @ 08077fb0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_SaveSpawnparms(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  _DAT_0816dd14 = (int)ROUND((float)gGlobalVariables._32_4_);
  (*DAT_08178f08)();
  iVar3 = 0;
  host_client = DAT_0816dd10;
  if (0 < svs) {
    do {
      piVar1 = host_client;
      if ((*host_client != 0) || (host_client[2] != 0)) {
        host_client[0x140c] = *(int *)(param_1 + 8);
        uVar2 = NUM_FOR_EDICT(piVar1[0x13c2]);
        *(undefined4 *)(param_1 + 0x1c) = uVar2;
        (*DAT_08178ebc)(host_client[0x13c2],param_1);
      }
      iVar3 = iVar3 + 1;
      host_client = host_client + 0x14ae;
    } while (iVar3 < svs);
  }
  return;
}


// SV_SendBan  @ 08078a00
void SV_SendBan(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 **ppuVar3;
  undefined1 *apuStack_34 [3];
  char local_14 [16];
  
  apuStack_34[2] = (undefined1 *)0x8078a17;
  sprintf(local_14,"banned.\n");
  apuStack_34[2] = net_message;
  apuStack_34[1] = (undefined1 *)0x8078a21;
  SZ_Clear();
  apuStack_34[1] = (undefined1 *)0xffffffff;
  apuStack_34[0] = net_message;
  MSG_WriteLong();
  MSG_WriteByte(net_message,0x6c);
  MSG_WriteString(net_message,local_14);
  puVar2 = &net_from;
  ppuVar3 = apuStack_34;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar3 = (undefined1 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  }
  NET_SendPacket(1,net_message._16_4_,net_message._8_4_);
  SZ_Clear();
  return;
}


// SV_SendClientDatagram  @ 08076b20
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SV_SendClientDatagram(int param_1)

{
  undefined4 local_fb8;
  int local_fb4;
  undefined1 *local_fb0;
  undefined4 local_fac;
  int local_fa8;
  undefined1 local_fa4 [4000];
  
  local_fb0 = local_fa4;
  local_fac = 4000;
  local_fa8 = 0;
  local_fb8 = 1;
  local_fb4 = 0;
  MSG_WriteByte(&local_fb8,7);
  MSG_WriteFloat(&local_fb8,(float)_DAT_0811d24c);
  SV_WriteClientdataToMessage(param_1,&local_fb8);
  SV_WriteEntitiesToClient(param_1,&local_fb8);
  if (*(int *)(param_1 + 0x3f48) == 0) {
    SZ_Write(&local_fb8,*(undefined4 *)(param_1 + 0x3f4c),*(undefined4 *)(param_1 + 0x3f54));
  }
  else {
    Con_Printf("WARNING: datagram overflowed for %s\n",param_1 + 0x5005);
  }
  SZ_Clear(param_1 + 0x3f44);
  if (nDatagramBytesSent < local_fa8) {
    nDatagramBytesSent = local_fa8;
  }
  if (local_fb4 != 0) {
    Con_Printf("WARNING: msg overflowed for %s\n",param_1 + 0x5005);
    SZ_Clear(&local_fb8);
  }
  Netchan_Transmit(param_1 + 0x14,local_fa8,local_fa4);
  return 1;
}


// SV_SendClientMessages  @ 08076e00
void SV_SendClientMessages(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  SV_UpdateToReliableMessages();
  nReliableBytesSent = 0;
  nDatagramBytesSent = 0;
  nReliables = 0;
  nDatagrams = 0;
  bUnreliableOverflow = 0;
  iVar3 = 0;
  host_client = DAT_0816dd10;
  if (0 < svs) {
    do {
      if ((((*host_client != 0) || (host_client[2] != 0)) || (host_client[1] != 0)) &&
         (host_client[0xfb0] == 0)) {
        if (host_client[0x1f] != 0) {
          SZ_Clear(host_client + 0x1e);
          SZ_Clear(host_client + 0xfd1);
          SV_BroadcastPrintf("%s overflowed\n",(int)host_client + 0x5005);
          Con_Printf("WARNING: reliable overflow for %s\n",(int)host_client + 0x5005);
          SV_DropClient(host_client,0);
          piVar1 = host_client;
          host_client[0x13c0] = 1;
          piVar1[0x13] = 0;
          piVar1[0x14] = 0;
        }
        piVar1 = host_client;
        if (host_client[0x13c0] != 0) {
          host_client[0x13c0] = 0;
          iVar2 = Netchan_CanPacket(piVar1 + 5);
          if (iVar2 == 0) {
            host_client[0xfaa] = host_client[0xfaa] + 1;
          }
          else if (*host_client == 0) {
            Netchan_Transmit(host_client + 5,0,0);
          }
          else {
            SV_SendClientDatagram(host_client);
          }
        }
      }
      iVar3 = iVar3 + 1;
      host_client = host_client + 0x14ae;
    } while (iVar3 < svs);
  }
  SV_CleanupEnts();
  return;
}


// SV_SendReconnect  @ 08077f90
void SV_SendReconnect(void)

{
  SV_BroadcastCommand("reconnect\n");
  return;
}


// SV_SendResourceListBlock_f  @ 080773c0
void SV_SendResourceListBlock_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (*(int *)(host_client + 8) == 0) {
    Con_Printf("resourcelist not valid -- already spawned\n");
  }
  else {
    if (DAT_081b9d98 == 0) {
      uVar2 = Cmd_Argv(1);
      iVar3 = __strtol_internal(uVar2,0,10,0);
      if (iVar3 != DAT_08166d08) {
        Con_Printf("SV_SendResourceListBlock_f from different level\n");
        SV_New_f();
        return;
      }
    }
    uVar2 = Cmd_Argv(2);
    iVar4 = __strtol_internal(uVar2,0,10,0);
    MSG_WriteByte(host_client + 0x78,0x2d);
    MSG_WriteShort(host_client + 0x78,DAT_0813db2c);
    MSG_WriteShort(host_client + 0x78,iVar4);
    iVar3 = *(int *)(host_client + 0x88);
    MSG_WriteShort(host_client + 0x78,0);
    if (iVar4 < DAT_0813db2c) {
      do {
        if (*(int *)(host_client + 0x84) + -0x200 <= *(int *)(host_client + 0x88)) break;
        iVar1 = iVar4 * 0x68;
        MSG_WriteByte(host_client + 0x78,*(undefined4 *)(&DAT_0811d36c + iVar1));
        MSG_WriteString(host_client + 0x78,&DAT_0811d32c + iVar1);
        MSG_WriteShort(host_client + 0x78,*(undefined4 *)(&DAT_0811d370 + iVar1));
        MSG_WriteLong(host_client + 0x78,*(undefined4 *)(&DAT_0811d374 + iVar1));
        MSG_WriteByte(host_client + 0x78,(&DAT_0811d378)[iVar1]);
        if (((&DAT_0811d378)[iVar1] & 4) != 0) {
          SZ_Write(&DAT_081b5328,&DAT_0811d379 + iVar1,0x10);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_0813db2c);
    }
    *(short *)(iVar3 + *(int *)(host_client + 0x80)) = (short)iVar4;
    if (iVar4 < DAT_0813db2c) {
      MSG_WriteByte(host_client + 0x78,9);
      uVar2 = va("cmd resourcelist %i %i\n",DAT_08166d08,iVar4);
      MSG_WriteString(host_client + 0x78,uVar2);
    }
  }
  return;
}


// SV_SendServerinfo  @ 08071cd0
void SV_SendServerinfo(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_804 [2048];
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) ||
     (1 < svs)) {
    MSG_WriteByte(param_1 + 0x78,8);
    uVar1 = build_number(0,DAT_08166d08);
    sprintf(local_804,"%c\nBUILD %d SERVER (%i CRC)\nServer # %i\n",2,uVar1);
    MSG_WriteString(param_1 + 0x78,local_804);
  }
  iVar2 = param_1 + 0x78;
  MSG_WriteByte(iVar2,0xb);
  MSG_WriteLong(iVar2,PROTOCOL_VERSION);
  MSG_WriteLong(iVar2,DAT_08166d08);
  MSG_WriteLong(iVar2,DAT_0811d324);
  MSG_WriteLong(iVar2,DAT_0811d328);
  MSG_WriteByte(iVar2,svs);
  iVar2 = NUM_FOR_EDICT(*(undefined4 *)(param_1 + 0x4f08));
  uVar3 = iVar2 - 1;
  if (*(int *)(param_1 + 0x3ebc) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  MSG_WriteByte(param_1 + 0x78,uVar3);
  if (((byte)((byte)((ushort)((ushort)NAN((float)coop._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)coop._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((float)deathmatch._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)deathmatch._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)deathmatch._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  MSG_WriteByte(param_1 + 0x78,uVar1);
  COM_FileBase(com_gamedir,local_804);
  iVar2 = param_1 + 0x78;
  MSG_WriteString(iVar2,local_804);
  MSG_WriteString(iVar2,&DAT_0811d2e0);
  sprintf(local_804,"%s",*(int *)(DAT_0814043c + 0x290) + pr_strings);
  MSG_WriteString(iVar2,local_804);
  SV_WriteMovevarsToClient(host_client + 0x78);
  MSG_WriteByte(iVar2,0x20);
  MSG_WriteByte(iVar2,gGlobalVariables._140_4_);
  MSG_WriteByte(iVar2,gGlobalVariables._140_4_);
  MSG_WriteByte(iVar2,5);
  uVar1 = NUM_FOR_EDICT(*(undefined4 *)(param_1 + 0x4f08));
  MSG_WriteShort(iVar2,uVar1);
  MSG_WriteByte(iVar2,0x30);
  MSG_WriteLong(iVar2,DAT_08166d08);
  MSG_WriteLong(iVar2,0);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0x3eb8) = 1;
  return;
}


// SV_SendUserReg  @ 08078980
void SV_SendUserReg(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = sv_gpNewUserMsgs;
  if (sv_gpNewUserMsgs != (undefined4 *)0x0) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[5]) {
      MSG_WriteByte(param_1,0x27);
      MSG_WriteByte(param_1,*puVar1);
      MSG_WriteByte(param_1,puVar1[1]);
      MSG_WriteLong(param_1,puVar1[2]);
      MSG_WriteLong(param_1,puVar1[3]);
      MSG_WriteLong(param_1,puVar1[4]);
      MSG_WriteLong(param_1,puVar1[5]);
    }
  }
  return;
}


// SV_ServerLog_f  @ 08070ab0
void SV_ServerLog_f(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    pcVar4 = "off";
    pcVar2 = (char *)Cmd_Argv(1);
    iVar1 = strcasecmp(pcVar2,pcVar4);
    if (iVar1 == 0) {
      if (DAT_0816dd18 != 0) {
        if (DAT_0816dd34 != 0) {
          Log_Close();
        }
        Con_Printf("Server logging disabled.\n");
        DAT_0816dd18 = 0;
      }
    }
    else {
      pcVar4 = "on";
      pcVar2 = (char *)Cmd_Argv(1);
      iVar1 = strcasecmp(pcVar2,pcVar4);
      if (iVar1 == 0) {
        DAT_0816dd18 = 1;
        Log_Open();
      }
      else {
        uVar3 = Cmd_Argv(1);
        Con_Printf("log:  unknown parameter %s, \'on\' and \'off\' are valid\n",uVar3);
      }
    }
  }
  else {
    Con_Printf("usage:  log < on | off >\n");
    if (DAT_0816dd18 == 0) {
      Con_Printf("not currently logging\n");
    }
    else {
      Con_Printf("currently logging\n");
    }
  }
  return;
}


// SV_Serverinfo_f  @ 080707c0
void SV_Serverinfo_f(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  longdouble lVar4;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Server info settings:\n");
    uVar2 = Info_Serverinfo();
    Info_Print(uVar2);
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      pcVar3 = (char *)Cmd_Argv(1);
      if (*pcVar3 == '*') {
        Con_Printf("Star variables cannot be changed.\n");
      }
      else {
        uVar2 = Cmd_Argv(2,0x200);
        uVar2 = Cmd_Argv(1,uVar2);
        uVar2 = Info_Serverinfo(uVar2);
        Info_SetValueForKey(uVar2);
        uVar2 = Cmd_Argv(1);
        iVar1 = Cvar_FindVar(uVar2);
        if (iVar1 != 0) {
          Z_Free(*(undefined4 *)(iVar1 + 4));
          uVar2 = Cmd_Argv(2);
          uVar2 = CopyString(uVar2);
          *(undefined4 *)(iVar1 + 4) = uVar2;
          lVar4 = (longdouble)__strtod_internal(uVar2,0,0);
          *(float *)(iVar1 + 0xc) = (float)lVar4;
        }
        uVar2 = Info_Serverinfo();
        SV_BroadcastCommand("fullserverinfo \"%s\"\n",uVar2);
      }
    }
    else {
      Con_Printf("usage: serverinfo [ <key> <value> ]\n");
    }
  }
  return;
}


// SV_SetClientTimes  @ 0807cdf0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_SetClientTimes(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = DAT_0816dd10;
  if (0 < svs) {
    do {
      if (((*piVar1 != 0) || (piVar1[1] != 0)) || (piVar1[2] != 0)) {
        *(undefined8 *)(piVar1 + 0xfbf) = _DAT_0811d24c;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x14ae;
    } while (iVar2 < svs);
  }
  return;
}


// SV_SetGlobalTrace  @ 0806cb90
void SV_SetGlobalTrace(uint *param_1)

{
  gGlobalVariables._76_4_ = (float)*param_1;
  gGlobalVariables._80_4_ = (float)param_1[1];
  gGlobalVariables._84_4_ = param_1[4];
  gGlobalVariables._124_4_ = (float)param_1[3];
  gGlobalVariables._120_4_ = (float)param_1[2];
  gGlobalVariables._88_4_ = param_1[5];
  gGlobalVariables._92_4_ = param_1[6];
  gGlobalVariables._96_4_ = param_1[7];
  gGlobalVariables._100_4_ = param_1[8];
  gGlobalVariables._104_4_ = param_1[9];
  gGlobalVariables._108_4_ = param_1[10];
  gGlobalVariables._112_4_ = param_1[0xb];
  gGlobalVariables._116_4_ = DAT_0814043c;
  if (param_1[0xc] != 0) {
    gGlobalVariables._116_4_ = param_1[0xc];
  }
  gGlobalVariables._128_4_ = param_1[0xd];
  return;
}


// SV_SetIdealPitch  @ 0807e7e0
void SV_SetIdealPitch(void)

{
  int iVar1;
  float fVar2;
  double dVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  longdouble lVar9;
  longdouble lVar10;
  int aiStack_b8 [9];
  int local_88;
  float local_70 [7];
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  int local_3c [4];
  float local_2c;
  
  if ((*(byte *)(sv_player + 0x261) & 2) != 0) {
    fVar2 = *(float *)(sv_player + 0x130) * 3.1415927;
    local_70[0] = (fVar2 + fVar2) / 360.0;
    lVar9 = (longdouble)fsin((longdouble)local_70[0]);
    lVar10 = (longdouble)fcos((longdouble)local_70[0]);
    iVar6 = 0;
    puVar4 = &stack0xffffff6c;
    do {
      puVar7 = puVar4;
      *(int *)(puVar7 + -4) = iVar6 + 3;
      local_54 = (float)lVar10 * (float)*(int *)(puVar7 + -4) * 12.0 + *(float *)(sv_player + 0xe4);
      local_50 = (float)*(int *)(puVar7 + -4) * (float)lVar9 * 12.0 + *(float *)(sv_player + 0xe8);
      local_40 = *(float *)(sv_player + 0xec) + *(float *)(sv_player + 0x238);
      local_4c = local_40 - 160.0;
      *(undefined4 *)(puVar7 + -4) = 0;
      *(int *)(puVar7 + -8) = sv_player;
      *(undefined4 *)(puVar7 + -0xc) = 1;
      *(float **)(puVar7 + -0x10) = &local_54;
      *(undefined1 **)(puVar7 + -0x14) = vec3_origin;
      *(undefined1 **)(puVar7 + -0x18) = vec3_origin;
      *(float **)(puVar7 + -0x1c) = &local_48;
      *(int **)(puVar7 + -0x20) = local_3c;
      *(undefined4 *)(puVar7 + -0x24) = 0x807e8a4;
      local_48 = local_54;
      local_44 = local_50;
      SV_Move();
      if (local_3c[0] != 0) {
        return;
      }
      if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
        return;
      }
      local_70[iVar6 + 1] = (local_4c - local_40) * local_2c + local_40;
      iVar6 = iVar6 + 1;
      puVar4 = puVar7 + -4;
    } while (iVar6 < 6);
    local_88 = 0;
    iVar8 = 0;
    iVar5 = 1;
    if (1 < iVar6) {
      do {
        iVar1 = (int)ROUND(local_70[iVar5 + 1] - local_70[iVar5]);
        *(int *)(puVar7 + -8) = iVar1;
        dVar3 = (double)*(int *)(puVar7 + -8);
        if ((dVar3 <= -0.1) ||
           ((byte)(dVar3 < 0.1 | (byte)((ushort)((ushort)NAN(dVar3) << 10) >> 8) |
                  (byte)((ushort)((ushort)(dVar3 == 0.1) << 0xe) >> 8)) != 1)) {
          if (local_88 != 0) {
            *(int *)(puVar7 + -8) = iVar1 - local_88;
            dVar3 = (double)*(int *)(puVar7 + -8);
            if (0.1 < dVar3) {
              return;
            }
            if ((byte)(dVar3 < -0.1 | (byte)((ushort)((ushort)NAN(dVar3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar3 == -0.1) << 0xe) >> 8)) == 1) {
              return;
            }
          }
          iVar8 = iVar8 + 1;
          local_88 = iVar1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar6);
    }
    if (local_88 == 0) {
      *(undefined4 *)(sv_player + 0x160) = 0;
    }
    else if (1 < iVar8) {
      *(int *)(puVar7 + -8) = -local_88;
      *(float *)(sv_player + 0x160) =
           (float)*(int *)(puVar7 + -8) * (float)sv_idealpitchscale._12_4_;
    }
  }
  return;
}


// SV_SetLogAddress_f  @ 08070960
void SV_SetLogAddress_f(void)

{
  int iVar1;
  char *pcVar2;
  char **ppcVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  char *pcStackY_148;
  char *pcStackY_144;
  char *pcStackY_140;
  char *pcStack_134;
  char *pcStack_130;
  char local_11c [20];
  char local_108 [260];
  
  pcStack_130 = (char *)0x8070971;
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcStack_130 = (char *)0x1;
    pcStack_134 = (char *)0x80709c7;
    pcVar2 = (char *)Cmd_Argv();
    pcStack_134 = (char *)0x2;
    Cmd_Argv();
    pcStack_130 = (char *)0x0;
    pcStack_134 = (char *)0xa;
    pcStackY_140 = (char *)0x80709df;
    pcStack_130 = (char *)__strtol_internal();
    if (pcStack_130 == (char *)0x0) {
      pcStack_130 = "logaddress:  must specify a valid port\n";
      pcStack_134 = (char *)0x80709f0;
      Con_Printf();
      return;
    }
    if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
      pcStack_130 = "logaddress:  unparseable address\n";
      pcStack_134 = (char *)0x8070a13;
      Con_Printf();
      return;
    }
    pcStackY_140 = (char *)0x8070a33;
    pcStack_134 = pcVar2;
    sprintf(local_108,"%s:%i");
    pcStackY_148 = (char *)0x8070a46;
    pcStackY_144 = local_108;
    pcStackY_140 = local_11c;
    iVar1 = NET_StringToAdr();
    if (iVar1 == 0) {
      pcStack_130 = local_108;
      ppcVar3 = &stack0xfffffecc;
      pcStack_134 = "logaddress:  unable to resolve %s\n";
    }
    else {
      DAT_0816dd1c = 1;
      pcVar2 = local_11c;
      puVar4 = &DAT_0816dd20;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        puVar4 = puVar4 + 1;
      }
      pcVar2 = local_11c;
      ppcVar5 = &pcStackY_140;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar5 = (char *)*(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        ppcVar5 = ppcVar5 + 1;
      }
      pcStackY_144 = (char *)0x8070a82;
      pcStackY_144 = (char *)NET_AdrToString();
      ppcVar3 = &pcStackY_148;
      pcStackY_148 = "logaddress:  %s\n";
    }
  }
  else {
    pcStack_130 = "logaddress:  usage\nlogaddress ip port\n";
    pcStack_134 = (char *)0x8070980;
    Con_Printf();
    if (DAT_0816dd1c == 0) {
      return;
    }
    puVar4 = &DAT_0816dd20;
    ppcVar5 = &pcStackY_140;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar5 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    pcStackY_144 = (char *)0x80709a7;
    pcStackY_144 = (char *)NET_AdrToString();
    ppcVar3 = &pcStackY_148;
    pcStackY_148 = "current:  %s\n";
  }
  *(undefined4 *)((int)ppcVar3 + -4) = 0x8070aa1;
  Con_Printf();
  return;
}


// SV_SetMoveVars  @ 0807d280
void SV_SetMoveVars(void)

{
  movevars._0_4_ = sv_sendvelocity._12_4_;
  movevars._4_4_ = sv_gravity._12_4_;
  movevars._8_4_ = sv_stopspeed._12_4_;
  movevars._12_4_ = sv_maxspeed._12_4_;
  movevars._16_4_ = sv_spectatormaxspeed._12_4_;
  movevars._20_4_ = sv_accelerate._12_4_;
  movevars._24_4_ = sv_airaccelerate._12_4_;
  movevars._28_4_ = sv_wateraccelerate._12_4_;
  movevars._32_4_ = sv_friction._12_4_;
  movevars._36_4_ = sv_edgefriction._12_4_;
  movevars._40_4_ = sv_waterfriction._12_4_;
  movevars._44_4_ = 0x3f800000;
  movevars._48_4_ = sv_bounce._12_4_;
  movevars._52_4_ = sv_stepsize._12_4_;
  movevars._56_4_ = sv_maxvelocity._12_4_;
  movevars._60_4_ = sv_zmax._12_4_;
  movevars._64_4_ = sv_wateramp._12_4_;
  strcpy(movevars + 0x44,(char *)sv_skyname._4_4_);
  return;
}


// SV_SetPlayer  @ 08080390
undefined4 SV_SetPlayer(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = DAT_0816dd10;
  while ((((piVar1[1] == 0 || (*piVar1 == 0)) || (piVar1[2] == 0)) || (piVar1[0x13c4] != param_1)))
  {
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 0x14ae;
    if (0x1f < iVar2) {
      Con_Printf("Userid %i is not on the server\n",param_1);
      return 0;
    }
  }
  host_client = piVar1;
  sv_player = piVar1[0x13c2];
  return 1;
}


// SV_SetStudioHullPlane  @ 08060cc0
void SV_SetStudioHullPlane(float *param_1,int param_2,int param_3,float param_4)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 4) = 5;
  param_2 = param_2 * 0x30;
  iVar1 = param_3 * 4 + param_2;
  *param_1 = *(float *)(bonetransform + iVar1);
  param_1[1] = *(float *)(bonetransform + iVar1 + 0x10);
  param_1[2] = *(float *)(bonetransform + iVar1 + 0x20);
  param_1[3] = *(float *)(bonetransform + param_2 + 0x2c) * param_1[2] +
               *(float *)(bonetransform + param_2 + 0x1c) * param_1[1] +
               *(float *)(bonetransform + param_2 + 0xc) * *param_1 + param_4;
  return;
}


// SV_SetupResume  @ 0805e7b0
void SV_SetupResume(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  if (((-1 < param_1) && (*(int *)(host_client + 0x5048) == 0)) &&
     (param_1 = param_1 * 0x400, param_1 <= *(int *)(host_client + 0x5038))) {
    CRC32_Init(&local_8);
    CRC32_ProcessBuffer(&local_8,*(undefined4 *)(host_client + 0x5034),param_1);
    iVar2 = CRC32_Final(local_8);
    iVar1 = host_client;
    if (iVar2 == param_2) {
      *(undefined4 *)(host_client + 0x5040) = 1;
      *(int *)(iVar1 + 0x503c) = param_1;
      *(int *)(iVar1 + 0x5044) = param_2;
    }
  }
  return;
}


// SV_ShouldUpdatePing  @ 08075490
bool SV_ShouldUpdatePing(int param_1)

{
  bool bVar1;
  
  if (DAT_08166d04 == 1) {
    bVar1 = host_framecount == (host_framecount / 0x1e) * 0x1e;
  }
  else if (param_1 == host_framecount % DAT_08166d04) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// SV_ShowServerinfo_f  @ 08080450
void SV_ShowServerinfo_f(void)

{
  undefined4 uVar1;
  
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    uVar1 = Info_Serverinfo();
    Info_Print(uVar1);
  }
  return;
}


// SV_SingleClipMoveToEntity  @ 08084a10
void SV_SingleClipMoveToEntity
               (int param_1,float *param_2,undefined4 param_3,undefined4 param_4,float *param_5,
               int *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  int local_a8 [4];
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  int local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  memset(param_6,0,0x38);
  param_6[4] = 0x3f800000;
  *param_6 = 1;
  param_6[5] = (int)*param_5;
  param_6[6] = (int)param_5[1];
  param_6[7] = (int)param_5[2];
  local_30 = (&DAT_0813e330)[*(int *)(param_1 + 0x170)];
  if (*(int *)(local_30 + 0x44) == 3) {
    local_2c = SV_HullForStudioModel(param_1,param_3,param_4,&local_10,&local_34);
  }
  else {
    local_2c = SV_HullForEntity(param_1,param_3,param_4,&local_10);
    local_34 = 1;
  }
  local_1c = *param_2 - local_10;
  local_18 = param_2[1] - local_c;
  local_14 = param_2[2] - local_8;
  local_28 = *param_5 - local_10;
  local_24 = param_5[1] - local_c;
  local_20 = param_5[2] - local_8;
  if ((*(int *)(param_1 + 0x1c8) == 4) &&
     ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 300)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 300) == 0.0) << 0xe) >> 8)) != 0x40 ||
       ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x130)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x130) == 0.0) << 0xe) >> 8)) != 0x40))
      || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x134)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0x134) == 0.0) << 0xe) >> 8)) != 0x40)
      ))) {
    local_3c = 1;
  }
  else {
    local_3c = 0;
  }
  if (local_3c != 0) {
    AngleVectors(param_1 + 300,&local_48,&local_54,&local_60);
    fVar1 = local_14 * local_40;
    fVar2 = local_1c * local_54;
    fVar3 = local_14 * local_4c;
    local_14 = local_14 * local_58 + local_18 * local_5c + local_1c * local_60;
    local_6c = local_28;
    local_68 = local_24;
    local_64 = local_20;
    local_40 = local_20 * local_40;
    local_54 = local_28 * local_54;
    local_4c = local_20 * local_4c;
    local_20 = local_20 * local_58 + local_24 * local_5c + local_28 * local_60;
    local_28 = local_40 + local_24 * local_44 + local_28 * local_48;
    local_24 = -(local_4c + local_24 * local_50 + local_54);
    local_1c = fVar1 + local_18 * local_44 + local_1c * local_48;
    local_18 = -(fVar3 + local_18 * local_50 + fVar2);
  }
  if (local_34 == 1) {
    SV_RecursiveHullCheck
              (local_2c,*(undefined4 *)(local_2c + 8),0,0x3f800000,&local_1c,&local_28,param_6);
  }
  else {
    local_70 = 0;
    for (local_38 = 0; local_38 < local_34; local_38 = local_38 + 1) {
      memset(local_a8,0,0x38);
      local_98 = 1.0;
      local_a8[0] = 1;
      local_94 = *param_5;
      local_90 = param_5[1];
      local_8c = param_5[2];
      SV_RecursiveHullCheck
                (local_2c + local_38 * 0x28,*(undefined4 *)(local_2c + 8 + local_38 * 0x28),0,
                 0x3f800000,&local_1c,&local_28,local_a8);
      if (((local_38 == 0) || (local_a8[0] != 0)) ||
         ((local_a8[1] != 0 ||
          (fVar1 = (float)param_6[4],
          (byte)(local_98 < fVar1 |
                 (byte)((ushort)((ushort)(NAN(local_98) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_98 == fVar1) << 0xe) >> 8)) == 1)))) {
        if (param_6[1] == 0) {
          piVar5 = local_a8;
          piVar6 = param_6;
          for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar6 = *piVar5;
            piVar5 = piVar5 + 1;
            piVar6 = piVar6 + 1;
          }
        }
        else {
          piVar5 = local_a8;
          piVar6 = param_6;
          for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar6 = *piVar5;
            piVar5 = piVar5 + 1;
            piVar6 = piVar6 + 1;
          }
          param_6[1] = 1;
        }
        local_70 = local_38;
      }
    }
    iVar4 = SV_HitgroupForStudioHull(local_70);
    param_6[0xd] = iVar4;
  }
  fVar1 = (float)param_6[4];
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
    if (local_3c != 0) {
      AngleVectorsTranspose(param_1 + 300,&local_6c,&local_b4,&local_c0);
      fVar1 = (float)param_6[8];
      fVar2 = (float)param_6[9];
      fVar3 = (float)param_6[10];
      param_6[8] = (int)(fVar3 * local_64 + fVar2 * local_68 + fVar1 * local_6c);
      param_6[9] = (int)(fVar3 * local_ac + fVar2 * local_b0 + fVar1 * local_b4);
      param_6[10] = (int)(fVar3 * local_b8 + fVar2 * local_bc + fVar1 * local_c0);
    }
    param_6[5] = (int)(*param_2 + (*param_5 - *param_2) * (float)param_6[4]);
    param_6[6] = (int)(param_2[1] + (param_5[1] - param_2[1]) * (float)param_6[4]);
    param_6[7] = (int)(param_2[2] + (param_5[2] - param_2[2]) * (float)param_6[4]);
  }
  if (((float)param_6[4] < 1.0) || (param_6[1] != 0)) {
    param_6[0xc] = param_1;
  }
  return;
}


// SV_SizeofResourceList  @ 0807e090
int SV_SizeofResourceList
              (int param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
              int *param_7)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  *param_3 = 0;
  *param_2 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  for (iVar1 = *(int *)(param_1 + 0x60); iVar1 != param_1; iVar1 = *(int *)(iVar1 + 0x60)) {
    local_8 = local_8 + *(int *)(iVar1 + 0x48);
    switch(*(undefined4 *)(iVar1 + 0x40)) {
    case 0:
      *param_5 = *param_5 + *(int *)(iVar1 + 0x48);
      break;
    case 1:
      *param_6 = *param_6 + *(int *)(iVar1 + 0x48);
      break;
    case 2:
      if (*(int *)(iVar1 + 0x44) == 1) {
        *param_2 = *(undefined4 *)(iVar1 + 0x48);
      }
      else {
        *param_3 = *param_3 + *(int *)(iVar1 + 0x48);
      }
      break;
    case 3:
      *param_4 = *param_4 + *(int *)(iVar1 + 0x48);
      break;
    case 4:
      *param_7 = *param_7 + *(int *)(iVar1 + 0x48);
    }
  }
  return local_8;
}


// SV_SpawnServer  @ 080781d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SV_SpawnServer(undefined4 param_1,char *param_2,char *param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  char *__s;
  undefined4 local_60;
  char local_44 [64];
  
  if ((sv != 0) && (1 < svs)) {
    SV_SendReconnect();
    iVar4 = 0;
    piVar3 = DAT_0816dd10;
    if (0 < svs) {
      do {
        if ((((*piVar3 != 0) || (piVar3[1] != 0)) || (piVar3[2] != 0)) &&
           ((piVar3[0x13c2] != 0 && (*(int *)piVar3[0x13c2] == 0)))) {
          if (((int *)piVar3[0x13c2])[0x36] == 0) {
            Con_Printf("Skipping reconnect on %s, no pvPrivateData\n",(int)piVar3 + 0x5005);
          }
          else {
            if (piVar3[0xfaf] == 0) {
              iVar8 = piVar3[0x13c2];
              pcVar1 = DAT_08178ee0;
            }
            else {
              iVar8 = piVar3[0x13c2];
              pcVar1 = DAT_08178f18;
            }
            (*pcVar1)(iVar8);
          }
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 0x14ae;
      } while (iVar4 < svs);
    }
  }
  Log_Open();
  Log_Printf("Spawning server \"%s\"\n",param_2);
  Log_PrintServerVars();
  NET_Config(1 < svs);
  if (*(char *)hostname._4_4_ == '\0') {
    Cvar_Set("hostname","Half-Life");
  }
  scr_centertime_off = 0;
  if (param_3 == (char *)0x0) {
    Con_DPrintf("Spawn Server %s\n",param_2);
  }
  else {
    Con_DPrintf("Spawn Server %s: [%s]\n",param_2,param_3);
  }
  DAT_08166d08 = DAT_08166d08 + 1;
  gHostSpawnCount = DAT_08166d08;
  if ((byte)(0.0 < (float)coop._12_4_ | (byte)((ushort)((ushort)NAN((float)coop._12_4_) << 10) >> 8)
            | (byte)((ushort)((ushort)((float)coop._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    Cvar_SetValue("deathmatch",0);
  }
  current_skill = (int)ROUND((float)skill._12_4_ + 0.5);
  if (current_skill < 0) {
    current_skill = 0;
  }
  if (3 < current_skill) {
    current_skill = 3;
  }
  Cvar_SetValue("skill",(float)current_skill);
  Host_ClearMemory(0);
  iVar4 = 0;
  piVar3 = DAT_0816dd10;
  if (0 < DAT_08166d04) {
    do {
      SV_ClearFrames(piVar3 + 0x13c1);
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0x14ae;
    } while (iVar4 < DAT_08166d04);
  }
  if (svs == 1) {
    SV_UPDATE_BACKUP = 8;
  }
  else {
    SV_UPDATE_BACKUP = 0x40;
  }
  SV_UPDATE_MASK = SV_UPDATE_BACKUP + -1;
  SV_AllocClientFrames();
  puVar5 = &sv;
  for (iVar4 = 0xd7e3; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  strcpy(&DAT_0811d260,param_2);
  if (param_3 == (char *)0x0) {
    DAT_0811d2a0 = 0;
  }
  else {
    strcpy(&DAT_0811d2a0,param_3);
  }
  pr_strings = gNullString;
  gGlobalVariables._152_4_ = gNullString;
  if (svs == 1) {
    Cvar_SetValue("sv_clienttrace",0x3f800000);
  }
  DAT_08140438 = COM_EntsForPlayerSlots(svs);
  SV_DeallocateDynamicData();
  SV_ReallocateDynamicData();
  gGlobalVariables._148_4_ = DAT_08140438;
  DAT_0814043c = (undefined4 *)Hunk_AllocName(DAT_08140438 * 0x2c8,"edicts");
  _DAT_08140450 = 4000;
  DAT_08140454 = 0;
  DAT_0814044c = &DAT_08140458;
  _DAT_08141404 = 4000;
  DAT_08141408 = 0;
  DAT_08141400 = &DAT_0814140c;
  _DAT_081423b8 = 4000;
  _DAT_081423b4 = &DAT_081423c0;
  _DAT_0814336c = 0x400;
  DAT_08143368 = &DAT_08143374;
  _DAT_0814377c = &DAT_081437cc;
  DAT_08143780 = 4000;
  DAT_08143784 = 0;
  DAT_08143788 = 1;
  DAT_08140434 = svs + 1;
  iVar4 = 0;
  if (0 < svs) {
    do {
      DAT_0816dd10[iVar4 * 0x14ae + 0x13c2] = (int)(DAT_0814043c + iVar4 * 0xb2 + 0xb2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < svs);
  }
  gGlobalVariables._144_4_ = svs;
  DAT_08140440 = 1;
  DAT_0811d244 = 0;
  _DAT_0811d24c = 0;
  _DAT_0811d250 = 0x3ff00000;
  gGlobalVariables._0_4_ = 0x3f800000;
  strcpy(&DAT_0811d260,param_2);
  sprintf(&DAT_0811d2e0,"maps/%s.bsp",param_2);
  DAT_0811d320 = Mod_ForName(&DAT_0811d2e0,0);
  if (DAT_0811d320 == 0) {
    __s = &DAT_0811d2e0;
    pcVar7 = "Couldn\'t spawn server %s\n";
  }
  else {
    if (svs < 2) {
      DAT_0811d324 = 0;
      DAT_0811d328 = 0;
LAB_08078714:
      DAT_0813e334 = DAT_0811d320;
      SV_ClearWorld();
      DAT_0813eb30 = pr_strings;
      DAT_0813db30 = pr_strings;
      DAT_0813db34 = &DAT_0811d2e0;
      iVar4 = 1;
      while (puVar5 = DAT_0814043c, iVar4 < *(int *)(DAT_0811d320 + 0x78)) {
        iVar8 = iVar4 + 1;
        (&DAT_0813db30)[iVar8] = localmodels + iVar4 * 5;
        uVar2 = Mod_ForName(localmodels + iVar4 * 5,0);
        (&DAT_0813e330)[iVar8] = uVar2;
        iVar4 = iVar8;
      }
      puVar6 = DAT_0814043c + 0x37;
      for (iVar4 = 0x7b; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *puVar5 = 0;
      puVar5[0x5d] = DAT_0811d320 - (int)pr_strings;
      puVar5[0x5c] = 1;
      puVar5[0x72] = 4;
      puVar5[0x71] = 7;
      if ((byte)(0.0 < (float)coop._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)coop._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)coop._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
        gGlobalVariables._20_4_ = deathmatch._12_4_;
      }
      else {
        gGlobalVariables._24_4_ = coop._12_4_;
      }
      gGlobalVariables._12_4_ = (int)&DAT_0811d260 - (int)pr_strings;
      gGlobalVariables._16_4_ = (int)&DAT_0811d2a0 - (int)pr_strings;
      gGlobalVariables._32_4_ = (undefined4)_DAT_0816dd14;
      local_60 = (undefined4)(longlong)ROUND((float)sv_cheats._12_4_);
      allow_cheats = local_60;
      SV_SetMoveVars();
      Log_Printf("Map CRC \"%i\"\n",DAT_0811d324);
      return 1;
    }
    CRC32_Init(&DAT_0811d324);
    iVar4 = CRC_MapFile(&DAT_0811d324,&DAT_0811d2e0);
    if (iVar4 == 0) {
      __s = &DAT_0811d2e0;
      pcVar7 = "Couldn\'t CRC server map:  %s\n";
    }
    else {
      __s = local_44;
      sprintf(__s,"cl_dlls/client.dll");
      CRC32_Init(&DAT_0811d328);
      iVar4 = CRC_File(&DAT_0811d328,__s);
      if (iVar4 != 0) {
        CM_CalcPAS(DAT_0811d320);
        goto LAB_08078714;
      }
      pcVar7 = "Couldn\'t CRC client side dll:  %s\n";
    }
  }
  Con_Printf(pcVar7,__s);
  sv = 0;
  return 0;
}


// SV_SpawnSpectator  @ 08072380
void SV_SpawnSpectator(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
  iVar5 = sv_player;
  *(undefined4 *)(sv_player + 0xe4) = vec3_origin._0_4_;
  *(undefined4 *)(iVar5 + 0xe8) = vec3_origin._4_4_;
  *(undefined4 *)(iVar5 + 0xec) = vec3_origin._8_4_;
  *(undefined4 *)(iVar5 + 0x230) = vec3_origin._0_4_;
  *(undefined4 *)(iVar5 + 0x234) = vec3_origin._4_4_;
  *(undefined4 *)(iVar5 + 0x238) = 0x41b00000;
  iVar5 = 0x1f;
  if (0x1f < DAT_08140434) {
    do {
      iVar2 = EDICT_NUM(iVar5);
      iVar1 = sv_player;
      iVar4 = 0x12;
      bVar8 = false;
      uVar3 = 0;
      bVar9 = true;
      pbVar6 = (byte *)(pr_strings + *(int *)(iVar2 + 0xdc));
      pbVar7 = (byte *)"info_player_start";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        uVar3 = -(uint)bVar8 | 1;
      }
      if (uVar3 == 0) {
        *(undefined4 *)(sv_player + 0xe4) = *(undefined4 *)(iVar2 + 0xe4);
        *(undefined4 *)(iVar1 + 0xe8) = *(undefined4 *)(iVar2 + 0xe8);
        *(undefined4 *)(iVar1 + 0xec) = *(undefined4 *)(iVar2 + 0xec);
        return;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_08140434);
  }
  return;
}


// SV_StartParticle  @ 08071100
void SV_StartParticle(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (DAT_08140454 < 0xf91) {
    MSG_WriteByte(&DAT_08140444,0x12);
    MSG_WriteCoord(&DAT_08140444,*param_1);
    MSG_WriteCoord(&DAT_08140444,param_1[1]);
    MSG_WriteCoord(&DAT_08140444,param_1[2]);
    iVar2 = 0;
    do {
      iVar1 = (int)ROUND(*(float *)(param_2 + iVar2 * 4) * 16.0);
      if (iVar1 < 0x80) {
        if (iVar1 < -0x80) {
          iVar1 = -0x80;
        }
      }
      else {
        iVar1 = 0x7f;
      }
      MSG_WriteChar(&DAT_08140444,iVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    MSG_WriteByte(&DAT_08140444,param_4);
    MSG_WriteByte(&DAT_08140444,param_3);
  }
  return;
}


// SV_StartSound  @ 080711f0
void SV_StartSound(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  uint param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  float local_10 [3];
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 4;
    local_10[iVar2] =
         (*(float *)(iVar1 + param_1 + 0x198) + *(float *)(iVar1 + param_1 + 0x1a4)) * 0.5 +
         *(float *)(iVar1 + param_1 + 0xe4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  iVar2 = SV_BuildSoundMsg(param_1,param_2,param_3,param_4,param_5,param_6,param_7,local_10,
                           &DAT_08143360);
  if (iVar2 != 0) {
    if ((param_2 == 6) || ((param_6 & 0x20) != 0)) {
      iVar2 = IsSinglePlayerGame();
      bVar3 = iVar2 == 0;
      uVar4 = 0;
    }
    else {
      bVar3 = false;
      uVar4 = 2;
    }
    SV_Multicast(local_10,uVar4,bVar3);
  }
  return;
}


// SV_StepDirection  @ 08079900
bool SV_StepDirection(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  lVar2 = (longdouble)((param_2 * 3.1415927 + param_2 * 3.1415927) / 360.0);
  lVar3 = (longdouble)fcos(lVar2);
  local_10 = (float)(lVar3 * (longdouble)param_3);
  lVar2 = (longdouble)fsin(lVar2);
  local_c = (float)(lVar2 * (longdouble)param_3);
  local_8 = 0;
  iVar1 = SV_movestep(param_1,&local_10,0);
  if (iVar1 != 0) {
    SV_LinkEdict(param_1,1);
  }
  else {
    SV_LinkEdict(param_1,1);
  }
  return iVar1 != 0;
}


// SV_StudioSetupBones  @ 08060780
void SV_StudioSetupBones(undefined4 param_1,float param_2,int param_3,undefined4 param_4,
                        undefined4 *param_5,undefined4 param_6,byte *param_7,int param_8)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_280;
  float local_26c;
  int local_268;
  int local_254 [128];
  undefined1 local_54 [12];
  undefined4 local_48;
  undefined4 local_38;
  undefined4 local_28;
  undefined1 local_24 [32];
  
  local_280 = 0;
  if ((param_3 < 0) || (*(int *)(pstudiohdr + 0xa4) <= param_3)) {
    Con_DPrintf("sequence %d out of range for model %s\n",param_3,pstudiohdr + 8);
    param_3 = 0;
  }
  iVar1 = *(int *)(pstudiohdr + 0xa8) + pstudiohdr + param_3 * 0xb0;
  iVar5 = pstudiohdr + *(int *)(pstudiohdr + 0x90);
  iVar3 = R_GetAnim(param_1,iVar1);
  if ((param_8 < -1) || (*(int *)(pstudiohdr + 0x8c) <= param_8)) {
    param_8 = 0;
  }
  if (param_8 == -1) {
    local_280 = *(int *)(pstudiohdr + 0x8c);
    iVar7 = 0;
    if (0 < local_280) {
      do {
        local_254[(local_280 - iVar7) + -1] = iVar7;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(pstudiohdr + 0x8c));
    }
  }
  else {
    for (; param_8 != -1; param_8 = *(int *)(iVar5 + 0x20 + param_8 * 0x70)) {
      local_254[local_280] = param_8;
      local_280 = local_280 + 1;
    }
  }
  if (*(int *)(iVar1 + 0x38) < 2) {
    local_26c = 0.0;
  }
  else {
    local_26c = param_2 * (float)(*(int *)(iVar1 + 0x38) + -1) * 0.00390625;
  }
  fVar2 = local_26c - (float)(int)ROUND(local_26c);
  R_StudioCalcBoneAdj(0,local_24,param_6,param_6,0);
  local_268 = local_280 + -1;
  if (-1 < local_268) {
    do {
      iVar7 = local_254[local_268];
      iVar4 = iVar3 + iVar7 * 0xc;
      iVar6 = iVar7 * 0x70 + iVar5;
      R_StudioCalcBoneQuaterion
                ((int)ROUND(local_26c),fVar2,iVar6,iVar4,local_24,q_117 + iVar7 * 0x10);
      R_StudioCalcBonePosition
                ((int)ROUND(local_26c),fVar2,iVar6,iVar4,local_24,pos_116 + iVar7 * 0xc);
      local_268 = local_268 + -1;
    } while (-1 < local_268);
  }
  if (1 < *(int *)(iVar1 + 0x78)) {
    iVar3 = R_GetAnim(param_1,pstudiohdr + *(int *)(pstudiohdr + 0xa8) + param_3 * 0xb0);
    iVar1 = *(int *)(pstudiohdr + 0x8c);
    local_268 = local_280 + -1;
    if (-1 < local_268) {
      do {
        iVar7 = local_254[local_268];
        iVar4 = iVar3 + iVar1 * 0xc + iVar7 * 0xc;
        iVar6 = iVar7 * 0x70 + iVar5;
        R_StudioCalcBoneQuaterion
                  ((int)ROUND(local_26c),fVar2,iVar6,iVar4,local_24,q2_119 + iVar7 * 0x10);
        R_StudioCalcBonePosition
                  ((int)ROUND(local_26c),fVar2,iVar6,iVar4,local_24,pos2_118 + iVar7 * 0xc);
        local_268 = local_268 + -1;
      } while (-1 < local_268);
    }
    R_StudioSlerpBones(q_117,pos_116,q2_119,pos2_118,(float)*param_7 / 255.0);
  }
  AngleMatrix(param_4,rotationmatrix);
  rotationmatrix._12_4_ = *param_5;
  rotationmatrix._28_4_ = param_5[1];
  rotationmatrix._44_4_ = param_5[2];
  local_268 = local_280 + -1;
  if (-1 < local_268) {
    do {
      iVar3 = local_254[local_268];
      QuaternionMatrix(q_117 + iVar3 * 0x10,local_54);
      iVar1 = iVar3 * 0xc;
      local_48 = *(undefined4 *)(pos_116 + iVar1);
      local_38 = *(undefined4 *)(pos_116 + iVar1 + 4);
      local_28 = *(undefined4 *)(pos_116 + iVar1 + 8);
      if (*(int *)(iVar5 + 0x20 + iVar3 * 0x70) == -1) {
        puVar8 = rotationmatrix;
      }
      else {
        puVar8 = bonetransform + *(int *)(iVar5 + 0x20 + iVar3 * 0x70) * 0x30;
      }
      R_ConcatTransforms(puVar8,local_54,bonetransform + iVar3 * 0x30);
      local_268 = local_268 + -1;
    } while (-1 < local_268);
  }
  return;
}


// SV_Submerged  @ 0807be50
longdouble SV_Submerged(int param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_1 + 0x180) + *(float *)(param_1 + 0x18c)) * 0.5;
  local_c = (*(float *)(param_1 + 0x184) + *(float *)(param_1 + 400)) * 0.5;
  local_14 = (*(float *)(param_1 + 0x188) + *(float *)(param_1 + 0x194)) * 0.5;
  fVar1 = *(float *)(param_1 + 0x188) - local_14;
  iVar2 = *(int *)(param_1 + 0x27c);
  local_8 = local_14;
  if (iVar2 == 2) {
LAB_0807bf30:
    fVar4 = *(float *)(param_1 + 0x194) - local_8;
    fVar5 = 0.0;
LAB_0807bf43:
    lVar3 = (longdouble)SV_RecursiveWaterLevel(&local_10,fVar4,fVar5,0);
    lVar3 = lVar3 - (longdouble)fVar1;
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        fVar4 = 0.0;
        fVar5 = fVar1;
        goto LAB_0807bf43;
      }
    }
    else if (iVar2 == 3) {
      local_18 = *(undefined4 *)(param_1 + 0x194);
      local_20 = local_10;
      local_1c = local_c;
      iVar2 = SV_PointContents(&local_20);
      if (iVar2 == -3) {
        return (longdouble)*(float *)(param_1 + 0x1ac) - (longdouble)*(float *)(param_1 + 0x1a0);
      }
      goto LAB_0807bf30;
    }
    lVar3 = (longdouble)0;
  }
  return lVar3;
}


// SV_TestEntityPosition  @ 08084160
undefined4 SV_TestEntityPosition(int param_1)

{
  undefined1 local_3c [4];
  int local_38;
  undefined4 local_c;
  
  SV_Move(local_3c,param_1 + 0xe4,param_1 + 0x198,param_1 + 0x1a4,param_1 + 0xe4,0,param_1,
          (*(uint *)(param_1 + 0x260) & 0x800000) != 0);
  if (local_38 == 0) {
    local_c = 0;
  }
  else {
    SV_SetGlobalTrace(local_3c);
  }
  return local_c;
}


// SV_TouchLinks  @ 08083140
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_TouchLinks(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)param_2[5];
  do {
    if (local_8 == param_2 + 4) {
      if (*param_2 != -1) {
        if ((float)param_2[1] < (float)param_1[*param_2 + 99]) {
          SV_TouchLinks(param_1,param_2[2]);
        }
        fVar1 = (float)param_1[*param_2 + 0x60];
        fVar2 = (float)param_2[1];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
          SV_TouchLinks(param_1,param_2[3]);
        }
      }
      return;
    }
    local_c = (int *)local_8[1];
    local_10 = local_8 + -2;
    if ((((local_10 != param_1) && (local_8[0x70] == 1)) &&
        ((float)param_1[0x60] <= (float)local_8[0x61])) &&
       (((float)param_1[0x61] <= (float)local_8[0x62] &&
        ((float)param_1[0x62] <= (float)local_8[99])))) {
      fVar1 = (float)param_1[99];
      fVar2 = (float)local_8[0x5e];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        fVar1 = (float)param_1[100];
        fVar2 = (float)local_8[0x5f];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          fVar1 = (float)param_1[0x65];
          fVar2 = (float)local_8[0x60];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            local_14 = (&DAT_0813e330)[local_8[0x5a]];
            if ((local_14 != 0) && (*(int *)(local_14 + 0x44) == 0)) {
              local_1c = SV_HullForBsp(local_10,param_1 + 0x66,param_1 + 0x69,&local_28);
              local_34 = (float)param_1[0x39] - local_28;
              local_30 = (float)param_1[0x3a] - local_24;
              local_2c = (float)param_1[0x3b] - local_20;
              local_18 = SV_HullPointContents(local_1c,*(undefined4 *)(local_1c + 8),&local_34);
              if (local_18 != -2) goto LAB_080833db;
            }
            gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
            (*DAT_08178eb0)(local_10,param_1);
          }
        }
      }
    }
LAB_080833db:
    local_8 = local_c;
  } while( true );
}


// SV_Trace_Toss  @ 0807d100
undefined4 * SV_Trace_Toss(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int aiStack_35c [2];
  float local_354;
  int aiStack_350 [2];
  float local_348;
  int aiStack_344 [4];
  float local_31c;
  float local_318;
  float local_314;
  float local_310;
  float local_30c;
  float local_308;
  undefined4 local_304 [5];
  float local_2f0;
  float local_2ec;
  float local_2e8;
  int local_2d4;
  undefined4 local_2cc [57];
  float local_1e8;
  float local_1e4;
  float local_1e0;
  undefined1 local_1d0 [48];
  undefined1 local_1a0 [12];
  undefined1 local_194 [96];
  undefined1 local_134 [12];
  undefined1 local_128 [292];
  
  uVar1 = host_frametime;
  host_frametime = 0.05;
  puVar5 = local_2cc;
  for (iVar2 = 0xb2; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar3 = &stack0xfffffccc;
  do {
    do {
      *(undefined4 **)(puVar3 + -4) = local_2cc;
      *(undefined4 *)(puVar3 + -8) = 0x807d156;
      SV_CheckVelocity();
      *(undefined4 **)(puVar3 + -8) = local_2cc;
      *(undefined4 *)(puVar3 + -0xc) = 0x807d15c;
      SV_AddGravity();
      *(undefined1 **)(puVar3 + -0xc) = local_1a0;
      *(undefined1 **)(puVar3 + -0x10) = local_194;
      *(float *)(puVar3 + -0x14) = (float)host_frametime;
      *(undefined1 **)(puVar3 + -0x18) = local_1a0;
      *(undefined4 *)(puVar3 + -0x1c) = 0x807d182;
      VectorMA();
      *(float **)(puVar3 + -0x1c) = &local_310;
      *(float *)(puVar3 + -0x20) = (float)host_frametime;
      *(undefined1 **)(puVar3 + -0x24) = local_1d0;
      *(undefined4 *)(puVar3 + -0x28) = 0x807d1ad;
      VectorScale();
      local_31c = local_1e8 + local_310;
      local_318 = local_1e4 + local_30c;
      local_314 = local_1e0 + local_308;
      *(undefined4 *)(puVar3 + -4) = 0;
      *(undefined4 **)(puVar3 + -8) = local_2cc;
      *(undefined4 *)(puVar3 + -0xc) = 0;
      *(float **)(puVar3 + -0x10) = &local_31c;
      *(undefined1 **)(puVar3 + -0x14) = local_128;
      *(undefined1 **)(puVar3 + -0x18) = local_134;
      *(float **)(puVar3 + -0x1c) = &local_1e8;
      *(undefined4 **)(puVar3 + -0x20) = local_304;
      *(undefined4 *)(puVar3 + -0x24) = 0x807d20d;
      SV_Move();
      local_1e8 = local_2f0;
      local_1e4 = local_2ec;
      local_1e0 = local_2e8;
      puVar4 = puVar3 + -4;
      puVar3 = puVar3 + -4;
    } while (local_2d4 == 0);
    puVar3 = puVar4;
  } while (local_2d4 == param_3);
  puVar5 = local_304;
  puVar6 = param_1;
  host_frametime = (double)uVar1;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return param_1;
}


// SV_TruePointContents  @ 08084120
undefined4 SV_TruePointContents(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = SV_HullPointContents(DAT_0811d320 + 0xd0,0,param_1);
  return uVar1;
}


// SV_UnlinkEdict  @ 08083100
void SV_UnlinkEdict(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    RemoveLink(param_1 + 8);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


// SV_UpdateToReliableMessages  @ 08076c50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_UpdateToReliableMessages(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  host_client = DAT_0816dd10;
  if (0 < svs) {
    do {
      piVar3 = host_client;
      if (host_client[0x13c2] != 0) {
        if ((host_client[0x13f7] != 0) && ((double)(float)host_client[0x13f8] <= _DAT_0811d24c)) {
          host_client[0x13f7] = 0;
          piVar3[0x13f8] = (int)((float)_DAT_0811d24c + 1.0);
          SV_FullClientUpdate(piVar3,&DAT_081413f8);
        }
        if ((host_client[0xfb0] == 0) &&
           (((*host_client != 0 || (host_client[2] != 0)) && (sv_gpNewUserMsgs != 0)))) {
          SV_SendUserReg(host_client + 0x1e);
        }
      }
      iVar2 = iVar2 + 1;
      host_client = host_client + 0x14ae;
    } while (iVar2 < svs);
  }
  if (sv_gpNewUserMsgs != 0) {
    if (sv_gpUserMsgs == 0) {
      sv_gpUserMsgs = sv_gpNewUserMsgs;
    }
    else {
      iVar2 = *(int *)(sv_gpUserMsgs + 0x14);
      iVar1 = sv_gpUserMsgs;
      while (iVar2 != 0) {
        iVar1 = *(int *)(iVar1 + 0x14);
        iVar2 = *(int *)(iVar1 + 0x14);
      }
      *(int *)(iVar1 + 0x14) = sv_gpNewUserMsgs;
    }
    sv_gpNewUserMsgs = 0;
  }
  if (DAT_08140448 != 0) {
    Con_DPrintf("sv.datagram overflowed!\n");
    SZ_Clear(&DAT_08140444);
  }
  iVar2 = 0;
  piVar3 = DAT_0816dd10;
  if (0 < svs) {
    do {
      if ((*piVar3 != 0) && (piVar3[0xfb0] == 0)) {
        SZ_Write(piVar3 + 0x1e,DAT_08141400,DAT_08141408);
        SZ_Write(piVar3 + 0xfd1,DAT_0814044c,DAT_08140454);
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x14ae;
    } while (iVar2 < svs);
  }
  SZ_Clear(&DAT_081413f8);
  SZ_Clear(&DAT_08140444);
  return;
}


// SV_UpdateUploadCount  @ 0807d730
void SV_UpdateUploadCount(void)

{
  undefined4 *puVar1;
  float fVar2;
  int iVar3;
  
  if ((byte)(0.0 < (float)sv_uploadinterval._12_4_ |
             (byte)((ushort)((ushort)NAN((float)sv_uploadinterval._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_uploadinterval._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
  {
    if ((float)sv_uploadinterval._12_4_ < 0.0) {
      Cvar_SetValue("sv_uploadinterval",0x3f800000);
    }
    iVar3 = host_client;
    fVar2 = (float)realtime - *(float *)(host_client + 0x51c4);
    if ((byte)(fVar2 < (float)sv_uploadinterval._12_4_ |
               (byte)((ushort)((ushort)(NAN(fVar2) || NAN((float)sv_uploadinterval._12_4_)) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(fVar2 == (float)sv_uploadinterval._12_4_) << 0xe) >> 8)) != 1
       ) {
      fVar2 = (float)realtime;
      *(float *)(host_client + 0x51c4) = fVar2;
      puVar1 = (undefined4 *)(iVar3 + 0x51c8 + (*(uint *)(iVar3 + 0x5228) & 7) * 0xc);
      *puVar1 = 1;
      puVar1[1] = fVar2;
      puVar1[2] = *(undefined4 *)(iVar3 + 0x51bc);
      *(int *)(iVar3 + 0x5228) = *(int *)(iVar3 + 0x5228) + 1;
    }
  }
  return;
}


// SV_User_f  @ 08070ba0
void SV_User_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  
  if (sv == 0) {
    pcVar6 = "Can\'t \'user\', not running a server\n";
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      uVar2 = Cmd_Argv(1);
      iVar1 = __strtol_internal(uVar2,0,10,0);
      iVar5 = 0;
      piVar4 = DAT_0816dd10;
      if (0 < svs) {
        do {
          if ((((*piVar4 != 0) || (piVar4[1] != 0)) || (piVar4[2] != 0)) &&
             (*(char *)((int)piVar4 + 0x5005) != '\0')) {
            if (piVar4[0x13c4] == iVar1) {
LAB_08070c49:
              Info_Print(piVar4 + 0x13c6);
              return;
            }
            pcVar6 = (char *)Cmd_Argv(1);
            iVar3 = strcmp((char *)((int)piVar4 + 0x5005),pcVar6);
            if (iVar3 == 0) goto LAB_08070c49;
          }
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 0x14ae;
        } while (iVar5 < svs);
      }
      pcVar6 = "User not in server.\n";
    }
    else {
      pcVar6 = "Usage: user <username / userid>\n";
    }
  }
  Con_Printf(pcVar6);
  return;
}


// SV_Users_f  @ 08070c90
void SV_Users_f(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (sv == 0) {
    Con_Printf("Can\'t \'users\', not running a server\n");
  }
  else {
    iVar3 = 0;
    Con_Printf("userid name\n");
    Con_Printf("------ ----\n");
    if (0 < svs) {
      iVar2 = 0;
      piVar1 = DAT_0816dd10;
      do {
        if ((((*piVar1 != 0) || (piVar1[1] != 0)) || (piVar1[2] != 0)) &&
           (*(char *)((int)piVar1 + 0x5005) != '\0')) {
          Con_Printf("%6i %s\n",piVar1[0x13c4],(int)piVar1 + 0x5005);
          iVar3 = iVar3 + 1;
        }
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 0x14ae;
      } while (iVar2 < svs);
    }
    Con_Printf("%i users\n",iVar3);
  }
  return;
}


// SV_ValidClientMulticast  @ 080717c0
undefined4 SV_ValidClientMulticast(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = IsSinglePlayerGame();
  if (iVar1 == 0) {
    if (param_3 == 1) {
      iVar2 = CM_LeafPVS(param_2);
    }
    else if (param_3 < 2) {
      if (param_3 != 0) {
LAB_08071810:
        Con_Printf("MULTICAST: Error %d!\n",param_3);
        return 0;
      }
    }
    else {
      if (param_3 != 2) goto LAB_08071810;
      iVar2 = CM_LeafPAS(param_2);
    }
    if ((iVar2 != 0) &&
       (iVar1 = SV_PointLeafnum(*(int *)(param_1 + 0x4f08) + 0xe4),
       (*(byte *)(((int)(iVar1 - 1U) >> 3) + iVar2) >> (iVar1 - 1U & 7) & 1) == 0)) {
      return 0;
    }
  }
  return 1;
}


// SV_WriteClientdataToMessage  @ 08076810
void SV_WriteClientdataToMessage(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_1 + 0x4f08);
  if (*(int *)(param_1 + 0x3ea8) != 0) {
    MSG_WriteByte(param_2,0x2c);
    MSG_WriteByte(param_2,*(undefined4 *)(param_1 + 0x3ea8));
    *(undefined4 *)(param_1 + 0x3ea8) = 0;
  }
  SV_SetIdealPitch();
  if (*(int *)(iVar2 + 0x15c) != 0) {
    if (*(int *)(iVar2 + 0x15c) == 2) {
      MSG_WriteByte(param_2,0x26);
      MSG_WriteHiresAngle(param_2,*(undefined4 *)(iVar2 + 0x13c));
      *(undefined4 *)(iVar2 + 0x13c) = 0;
    }
    else {
      MSG_WriteByte(param_2,10);
      iVar4 = 0;
      do {
        MSG_WriteHiresAngle(param_2,*(undefined4 *)(iVar2 + 300 + iVar4 * 4));
        iVar4 = iVar4 + 1;
      } while (iVar4 < 3);
    }
    *(undefined4 *)(iVar2 + 0x15c) = 0;
  }
  uVar5 = (uint)((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x238)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x238) == 22.0) << 0xe) >> 8)) !=
                0x40);
  fVar1 = *(float *)(iVar2 + 0x160);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    uVar5 = uVar5 | 2;
  }
  if (*(int *)(iVar2 + 0x224) != 0) {
    uVar5 = uVar5 | 0x100;
  }
  if ((*(byte *)(iVar2 + 0x261) & 2) != 0) {
    uVar5 = uVar5 | 0x400;
  }
  if (1 < *(int *)(iVar2 + 0x27c)) {
    uVar5 = uVar5 | 0x800;
  }
  if (2 < *(int *)(iVar2 + 0x27c)) {
    uVar5 = uVar5 | 0x8000;
  }
  if (*(int *)(iVar2 + 0x178) != 0) {
    uVar5 = uVar5 | 0x200;
  }
  iVar4 = 0;
  do {
    fVar1 = *(float *)(iVar2 + 0x144 + iVar4 * 4);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 4 << ((byte)iVar4 & 0x1f);
    }
    fVar1 = *(float *)(iVar2 + 0xfc + iVar4 * 4);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 0x20 << ((byte)iVar4 & 0x1f);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  MSG_WriteByte(param_2,0xf);
  MSG_WriteShort(param_2,uVar5);
  if ((uVar5 & 1) != 0) {
    MSG_WriteChar(param_2,(int)ROUND(*(float *)(iVar2 + 0x238)));
  }
  if ((uVar5 & 2) != 0) {
    MSG_WriteChar(param_2,(int)ROUND(*(float *)(iVar2 + 0x160)));
  }
  iVar4 = 0;
  do {
    if ((4 << ((byte)iVar4 & 0x1f) & uVar5) != 0) {
      MSG_WriteHiresAngle(param_2,*(undefined4 *)(iVar2 + 0x144 + iVar4 * 4));
    }
    if ((0x20 << ((byte)iVar4 & 0x1f) & uVar5) != 0) {
      MSG_WriteChar(param_2,(int)ROUND(*(float *)(iVar2 + 0xfc + iVar4 * 4) * 0.0625));
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  if ((uVar5 & 0x100) != 0) {
    MSG_WriteLong(param_2,*(undefined4 *)(iVar2 + 0x224));
  }
  if ((uVar5 & 0x200) != 0) {
    uVar3 = SV_ModelIndex(*(int *)(iVar2 + 0x178) + pr_strings);
    MSG_WriteShort(param_2,uVar3);
  }
  MSG_WriteShort(param_2,(int)ROUND(*(float *)(iVar2 + 0x21c)));
  return;
}


// SV_WriteCustomEntityDeltaToClient  @ 08074150
void SV_WriteCustomEntityDeltaToClient(int param_1,int param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 in_FPUControlWord;
  char local_34;
  char local_2c;
  undefined2 local_16;
  undefined2 local_14;
  char local_11;
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  uVar5 = 0x2101;
  if (*(int *)(param_2 + 0x40) != *(int *)(param_1 + 0x40)) {
    uVar5 = 0x2501;
  }
  uVar4 = *(uint *)(param_2 + 0x40) & 0xf;
  if (uVar4 < 2) {
    iVar3 = 0;
    do {
      fVar1 = *(float *)(param_2 + 0xc + iVar3 * 4) - *(float *)(param_1 + 0xc + iVar3 * 4);
      if (((byte)(fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) == 1) || (0.1 < fVar1)) {
        uVar5 = uVar5 | 2 << ((byte)iVar3 & 0x1f);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    if (uVar4 == 0) {
      iVar3 = 0;
      do {
        fVar1 = *(float *)(param_2 + 0x18 + iVar3 * 4) - *(float *)(param_1 + 0x18 + iVar3 * 4);
        if (((byte)(fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) == 1) || (0.1 < fVar1)) {
          uVar5 = uVar5 | 0x20 << ((byte)iVar3 & 0x1f);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
    }
  }
  if ((uVar4 - 1 < 2) &&
     ((*(int *)(param_2 + 0x28) != *(int *)(param_1 + 0x28) ||
      (*(short *)(param_2 + 0x34) != *(short *)(param_1 + 0x34))))) {
    uVar5 = uVar5 | 0x200;
  }
  if (*(int *)(param_2 + 0x24) != *(int *)(param_1 + 0x24)) {
    uVar5 = uVar5 | 0x800;
  }
  fVar1 = *(float *)(param_2 + 0x3c);
  fVar2 = *(float *)(param_1 + 0x3c);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar5 = uVar5 | 0x1000;
  }
  if (*(int *)(param_2 + 0x5c) != *(int *)(param_1 + 0x5c)) {
    uVar5 = uVar5 | 0x4000;
  }
  if (((*(uint *)(param_2 + 0x48) & 0xffffff) != (*(uint *)(param_1 + 0x48) & 0xffffff)) ||
     (*(int *)(param_2 + 0x4c) != *(int *)(param_1 + 0x4c))) {
    uVar5 = uVar5 | 0x10000;
  }
  if (*(int *)(param_2 + 0x44) != *(int *)(param_1 + 0x44)) {
    uVar5 = uVar5 | 0x20000;
  }
  fVar1 = *(float *)(param_2 + 0x2c);
  fVar2 = *(float *)(param_1 + 0x2c);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar5 = uVar5 | 0x80000;
  }
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  if ((int)ROUND(*(float *)(param_2 + 0x54)) != (int)ROUND(*(float *)(param_1 + 0x54))) {
    uVar5 = uVar5 | 0x40000;
  }
  if (0xff < *(int *)(param_2 + 4)) {
    uVar5 = uVar5 | 0x8000;
  }
  if (0xff < (int)uVar5) {
    uVar5 = uVar5 | 1;
  }
  if (0xffff < (int)uVar5) {
    uVar5 = uVar5 | 0x100;
  }
  if (0xffffff < (int)uVar5) {
    uVar5 = uVar5 | 0x800000;
  }
  if (*(int *)(param_2 + 4) == 0) {
    Sys_Error("Unset entity number");
  }
  if ((uVar5 != 0) || (param_4 != 0)) {
    local_11 = (char)uVar5;
    MSG_WriteBitByte(&local_11,8);
    if ((uVar5 & 1) != 0) {
      local_11 = (char)(uVar5 >> 8);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x100) != 0) {
      local_11 = (char)(uVar5 >> 0x10);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x800000) != 0) {
      local_11 = (char)(uVar5 >> 0x18);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((short)uVar5 < 0) {
      local_14 = *(undefined2 *)(param_2 + 4);
      MSG_WriteBitShort(&local_14,10);
    }
    else {
      local_11 = *(char *)(param_2 + 4);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 2) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_16 = (undefined2)(int)ROUND(*(float *)(param_2 + 0xc) * 8.0);
      MSG_WriteSBitShort(&local_16,0x10);
    }
    if ((uVar5 & 4) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_16 = (undefined2)(int)ROUND(*(float *)(param_2 + 0x10) * 8.0);
      MSG_WriteSBitShort(&local_16,0x10);
    }
    if ((uVar5 & 8) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_16 = (undefined2)(int)ROUND(*(float *)(param_2 + 0x14) * 8.0);
      MSG_WriteSBitShort(&local_16,0x10);
    }
    if ((uVar5 & 0x20) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_16 = (undefined2)(int)ROUND(*(float *)(param_2 + 0x18) * 8.0);
      MSG_WriteSBitShort(&local_16,0x10);
    }
    if ((uVar5 & 0x40) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_16 = (undefined2)(int)ROUND(*(float *)(param_2 + 0x1c) * 8.0);
      MSG_WriteSBitShort(&local_16,0x10);
    }
    if ((char)uVar5 < '\0') {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_16 = (undefined2)(int)ROUND(*(float *)(param_2 + 0x20) * 8.0);
      MSG_WriteSBitShort(&local_16,0x10);
    }
    if ((uVar5 & 0x200) != 0) {
      local_14 = *(undefined2 *)(param_2 + 0x28);
      MSG_WriteBitShort(&local_14,0x10);
      local_14 = *(undefined2 *)(param_2 + 0x34);
      MSG_WriteBitShort(&local_14,0x10);
    }
    if ((uVar5 & 0x400) != 0) {
      local_11 = *(char *)(param_2 + 0x40);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x800) != 0) {
      local_14 = *(undefined2 *)(param_2 + 0x24);
      MSG_WriteBitShort(&local_14,0x10);
    }
    if ((uVar5 & 0x1000) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_2c = (char)(longlong)ROUND(*(float *)(param_2 + 0x3c));
      local_11 = local_2c;
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x4000) != 0) {
      local_11 = *(char *)(param_2 + 0x5c);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x10000) != 0) {
      local_11 = *(char *)(param_2 + 0x48);
      MSG_WriteBitByte(&local_11,8);
      local_11 = *(char *)(param_2 + 0x49);
      MSG_WriteBitByte(&local_11,8);
      local_11 = *(char *)(param_2 + 0x4a);
      MSG_WriteBitByte(&local_11,8);
      local_11 = *(char *)(param_2 + 0x4c);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x20000) != 0) {
      local_11 = *(char *)(param_2 + 0x44);
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x80000) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_34 = (char)(longlong)ROUND(*(float *)(param_2 + 0x2c));
      local_11 = local_34;
      MSG_WriteBitByte(&local_11,8);
    }
    if ((uVar5 & 0x40000) != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      local_34 = (char)(longlong)ROUND(*(float *)(param_2 + 0x54));
      local_11 = local_34;
      MSG_WriteBitByte(&local_11,8);
    }
  }
  return;
}


// SV_WriteDelta  @ 080746d0
void SV_WriteDelta(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined2 in_FPUControlWord;
  undefined1 local_30;
  char local_28;
  uint local_1c;
  undefined1 local_17;
  undefined2 local_16;
  undefined2 local_14;
  char local_11;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  if (*param_2 == 0) {
    uVar5 = 0;
    local_1c = 0;
    iVar4 = 0;
    do {
      fVar1 = (float)param_2[iVar4 + 3] - *(float *)(param_1 + 0xc + iVar4 * 4);
      if (((byte)(fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) == 1) || (0.1 < fVar1)) {
        uVar5 = uVar5 | 2 << ((byte)iVar4 & 0x1f);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    fVar1 = (float)param_2[6];
    fVar2 = *(float *)(param_1 + 0x18);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 0x200;
    }
    fVar1 = (float)param_2[7];
    fVar2 = *(float *)(param_1 + 0x1c);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 0x20;
    }
    fVar1 = (float)param_2[8];
    fVar2 = *(float *)(param_1 + 0x20);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 0x400;
    }
    if (param_2[0x14] != *(int *)(param_1 + 0x50)) {
      uVar5 = uVar5 | 0x40;
    }
    if (param_2[0xc] != *(int *)(param_1 + 0x30)) {
      uVar5 = uVar5 | 0x40000;
    }
    if (param_2[0xd] != *(int *)(param_1 + 0x34)) {
      uVar5 = uVar5 | 0x80000;
    }
    fVar1 = (float)param_2[0xb];
    fVar2 = *(float *)(param_1 + 0x2c);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 0x80;
    }
    fVar1 = (float)param_2[0xf];
    fVar2 = *(float *)(param_1 + 0x3c);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 0x40000000;
    }
    if (param_2[0xe] != *(int *)(param_1 + 0x38)) {
      uVar5 = uVar5 | 0x4000;
    }
    if (param_2[9] != *(int *)(param_1 + 0x24)) {
      uVar5 = uVar5 | 0x800;
    }
    if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(param_1 + 0x54)) ||
                                        NAN((float)param_2[0x15])) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == (float)param_2[0x15]) << 0xe)
                     >> 8)) != 0x40) || (param_2[10] != *(int *)(param_1 + 0x28))) {
      uVar5 = uVar5 | 0x1000;
    }
    fVar1 = (float)param_2[0x16];
    fVar2 = *(float *)(param_1 + 0x58);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar5 = uVar5 | 0x10000;
    }
    if (param_2[0x17] != *(int *)(param_1 + 0x5c)) {
      uVar5 = uVar5 | 0x400000;
    }
    if ((char)param_2[0x18] != *(char *)(param_1 + 0x60)) {
      uVar5 = uVar5 | 0x1000000;
    }
    if (*(char *)((int)param_2 + 0x61) != *(char *)(param_1 + 0x61)) {
      uVar5 = uVar5 | 0x2000000;
    }
    if (*(char *)((int)param_2 + 0x62) != *(char *)(param_1 + 0x62)) {
      uVar5 = uVar5 | 0x4000000;
    }
    if (*(char *)((int)param_2 + 99) != *(char *)(param_1 + 99)) {
      uVar5 = uVar5 | 0x8000000;
    }
    if ((char)param_2[0x19] != *(char *)(param_1 + 100)) {
      uVar5 = uVar5 | 0x10000000;
    }
    if (*(char *)((int)param_2 + 0x65) != *(char *)(param_1 + 0x65)) {
      uVar5 = uVar5 | 0x20000000;
    }
    if ((((param_2[0x10] != *(int *)(param_1 + 0x40)) || (param_2[0x11] != *(int *)(param_1 + 0x44))
         ) || (param_2[0x13] != *(int *)(param_1 + 0x4c))) ||
       ((param_2[0x12] & 0xffffffU) != (*(uint *)(param_1 + 0x48) & 0xffffff))) {
      uVar5 = uVar5 | 0x100000;
    }
    fVar1 = (float)param_2[0x15];
    if ((((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
        ((byte)((byte)((ushort)((ushort)NAN((float)param_2[0x1a]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_2[0x1a] == 0.0) << 0xe) >> 8)) == 0x40)) &&
       (((byte)((byte)((ushort)((ushort)NAN((float)param_2[0x1b]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_2[0x1b] == 0.0) << 0xe) >> 8)) == 0x40 &&
        ((byte)((byte)((ushort)((ushort)NAN((float)param_2[0x1c]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_2[0x1c] == 0.0) << 0xe) >> 8)) == 0x40)))) {
      uVar5 = uVar5 | 0x200000;
    }
    iVar4 = 0;
    do {
      fVar1 = (float)param_2[iVar4 + 0x1d] - *(float *)(param_1 + 0x74 + iVar4 * 4);
      if (((byte)(fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) == 1) || (0.1 < fVar1)) {
        local_1c = local_1c | 1 << ((byte)iVar4 & 0x1f);
      }
      fVar1 = (float)param_2[iVar4 + 0x20] - *(float *)(param_1 + 0x80 + iVar4 * 4);
      if (((byte)(fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) == 1) || (0.1 < fVar1)) {
        local_1c = local_1c | 8 << ((byte)iVar4 & 0x1f);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    if (param_2[0x23] != *(int *)(param_1 + 0x8c)) {
      local_1c = local_1c | 0x40;
    }
    if ((param_2[0x14] == 0xc) && (param_2[0x23] != 0)) {
      uVar5 = uVar5 & 0xfffffff1;
    }
    else if (param_2[0x23] != *(int *)(param_1 + 0x8c)) {
      uVar5 = uVar5 | 0xe;
    }
    if (0xff < param_2[1]) {
      uVar5 = uVar5 | 0x8000;
    }
    if (0xff < uVar5) {
      uVar5 = uVar5 | 1;
    }
    if (0xffff < uVar5) {
      uVar5 = uVar5 | 0x100;
    }
    if (0xffffff < uVar5) {
      uVar5 = uVar5 | 0x800000;
    }
    if (local_1c != 0) {
      uVar5 = uVar5 | 0x80800101;
    }
    if (param_2[1] == 0) {
      Sys_Error("Unset entity number");
    }
    if (((uVar5 != 0) || (local_1c != 0)) || (param_4 != 0)) {
      local_11 = (char)uVar5;
      MSG_WriteBitByte(&local_11,8);
      if ((uVar5 & 1) != 0) {
        local_11 = (char)(uVar5 >> 8);
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x100) != 0) {
        local_11 = (char)(uVar5 >> 0x10);
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x800000) != 0) {
        local_11 = (char)(uVar5 >> 0x18);
        MSG_WriteBitByte(&local_11,8);
      }
      if ((int)uVar5 < 0) {
        local_11 = (char)local_1c;
        MSG_WriteBitByte(&local_11,8);
      }
      if ((short)uVar5 < 0) {
        local_14 = (undefined2)param_2[1];
        MSG_WriteBitShort(&local_14,10);
      }
      else {
        local_11 = (char)param_2[1];
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x800) != 0) {
        if (param_2[9] < 0x100) {
          local_11 = '\0';
          MSG_WriteBitByte(&local_11,1);
          local_11 = (char)param_2[9];
          MSG_WriteBitByte(&local_11,8);
        }
        else {
          local_11 = '\x01';
          MSG_WriteBitByte(&local_11,1);
          local_14 = (undefined2)param_2[9];
          MSG_WriteBitShort(&local_14,10);
        }
      }
      if ((char)uVar5 < '\0') {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_28 = (char)(longlong)ROUND((float)param_2[0xb]);
        local_11 = local_28;
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x40) != 0) {
        local_11 = (char)param_2[0x14];
        MSG_WriteBitByte(&local_11,4);
      }
      if ((uVar5 & 0x40000) != 0) {
        local_14 = (undefined2)param_2[0xc];
        MSG_WriteBitShort(&local_14,0x10);
      }
      if ((uVar5 & 0x80000) != 0) {
        local_11 = (char)param_2[0xd];
        MSG_WriteBitByte(&local_11,8);
        local_11 = *(char *)((int)param_2 + 0x36);
        MSG_WriteBitByte(&local_11,3);
      }
      if ((uVar5 & 0x40000000) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_14 = (undefined2)(longlong)ROUND((float)param_2[0xf] * 256.0);
        MSG_WriteBitShort(&local_14,0x10);
      }
      if ((uVar5 & 0x4000) != 0) {
        local_11 = (char)param_2[0xe];
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 2) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[3] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((uVar5 & 0x200) != 0) {
        MSG_WriteBitAngle(param_2[6],0xb);
      }
      if ((uVar5 & 4) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[4] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((uVar5 & 0x20) != 0) {
        MSG_WriteBitAngle(param_2[7],0xd);
      }
      if ((uVar5 & 8) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[5] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((uVar5 & 0x400) != 0) {
        MSG_WriteBitAngle(param_2[8],0xb);
      }
      if ((uVar5 & 0x1000) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = (int)ROUND((float)param_2[0x15] * 100.0);
        cVar3 = (char)local_10;
        local_11 = (char)param_2[10];
        MSG_WriteBitByte(&local_11,8);
        local_11 = cVar3;
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x10000) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_30 = (undefined1)(int)ROUND((float)param_2[0x16] * 16.0);
        local_17 = local_30;
        MSG_WriteSBitByte(&local_17,8);
      }
      if ((uVar5 & 0x1000000) != 0) {
        local_11 = (char)param_2[0x18];
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x2000000) != 0) {
        local_11 = *(char *)((int)param_2 + 0x61);
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x4000000) != 0) {
        local_11 = *(char *)((int)param_2 + 0x62);
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x8000000) != 0) {
        local_11 = *(char *)((int)param_2 + 99);
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x10000000) != 0) {
        local_11 = (char)param_2[0x19];
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x20000000) != 0) {
        local_11 = *(char *)((int)param_2 + 0x65);
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x400000) != 0) {
        local_11 = (char)param_2[0x17];
        MSG_WriteBitByte(&local_11,8);
      }
      if ((uVar5 & 0x100000) != 0) {
        local_11 = (char)param_2[0x10];
        MSG_WriteBitByte(&local_11,8);
        local_11 = (char)param_2[0x11];
        MSG_WriteBitByte(&local_11,8);
        local_11 = (char)param_2[0x12];
        MSG_WriteBitByte(&local_11,8);
        local_11 = *(char *)((int)param_2 + 0x49);
        MSG_WriteBitByte(&local_11,8);
        local_11 = *(char *)((int)param_2 + 0x4a);
        MSG_WriteBitByte(&local_11,8);
        local_11 = (char)param_2[0x13];
        MSG_WriteBitByte(&local_11,8);
      }
      if ((local_1c & 1) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[0x1d] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((local_1c & 2) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[0x1e] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((local_1c & 4) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[0x1f] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((local_1c & 8) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[0x20] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((local_1c & 0x10) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[0x21] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((local_1c & 0x20) != 0) {
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_16 = (undefined2)(int)ROUND((float)param_2[0x22] * 8.0);
        MSG_WriteSBitShort(&local_16,0x10);
      }
      if ((local_1c & 0x40) != 0) {
        local_16 = (undefined2)param_2[0x23];
        MSG_WriteBitShort(&local_16,10);
      }
    }
  }
  else {
    SV_WriteCustomEntityDeltaToClient(param_1,param_2,param_3,param_4);
  }
  return;
}


// SV_WriteEntitiesToClient  @ 08076620
void SV_WriteEntitiesToClient(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_9014;
  undefined1 local_9010 [36864];
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = *(int *)(param_1 + 0x4f08);
  iVar1 = *(int *)(param_1 + 0x4f04) + (*(uint *)(param_1 + 0x5c) & SV_UPDATE_MASK) * 0x18;
  if (*(int *)(param_1 + 0x4f0c) == 0) {
    local_10 = *(float *)(iVar3 + 0xe4) + *(float *)(iVar3 + 0x230);
    local_c = *(float *)(iVar3 + 0xe8) + *(float *)(iVar3 + 0x234);
    local_8 = *(float *)(iVar3 + 0xec) + *(float *)(iVar3 + 0x238);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x4f0c);
    local_10 = *(float *)(iVar3 + 0xe4) + *(float *)(iVar3 + 0x230);
    local_c = *(float *)(iVar3 + 0xe8) + *(float *)(iVar3 + 0x234);
    local_8 = *(float *)(iVar3 + 0xec) + *(float *)(iVar3 + 0x238);
  }
  uVar2 = SV_FatPVS(&local_10);
  SV_WritePlayersToClient(param_1,uVar2,param_2);
  SV_ClearPacketEntities(iVar1);
  piVar4 = (int *)(iVar1 + 0x10);
  local_9014 = 0;
  iVar3 = svs + 1;
  if (iVar3 < DAT_08140434) {
    do {
      SV_AddToFullPack(&local_9014,iVar3,uVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_08140434);
  }
  *piVar4 = local_9014;
  iVar3 = local_9014;
  if (local_9014 == 0) {
    iVar3 = 1;
  }
  if (*(int *)(iVar1 + 0x14) != 0) {
    Con_DPrintf("Allocating pack entities over existing pack\n");
  }
  SV_AllocPacketEntities(iVar1,iVar3);
  if (local_9014 == 0) {
    *piVar4 = 0;
  }
  if (*piVar4 == 0) {
    puVar5 = *(undefined4 **)(iVar1 + 0x14);
    for (iVar3 = 0x24; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  else {
    memcpy(*(void **)(iVar1 + 0x14),local_9010,*piVar4 * 0x90);
  }
  SV_EmitPacketEntities(param_1,piVar4,param_2);
  return;
}


// SV_WriteIP_f  @ 08078f50
void SV_WriteIP_f(void)

{
  uint uVar1;
  FILE *__stream;
  int iVar2;
  char local_108 [260];
  
  sprintf(local_108,"%s/listip.cfg",com_gamedir);
  Con_Printf("Writing %s.\n",local_108);
  __stream = fopen(local_108,"wb");
  if (__stream == (FILE *)0x0) {
    Con_Printf("Couldn\'t open %s\n",local_108);
  }
  else {
    iVar2 = 0;
    if (0 < numipfilters) {
      do {
        uVar1 = (&DAT_08162ce4)[iVar2 * 4];
        if ((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_08162cec)[iVar2 * 4]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)(&DAT_08162cec)[iVar2 * 4] == 0.0) << 0xe) >> 8))
            == 0x40) {
          fprintf(__stream,"addip 0.0 %i.%i.%i.%i\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
                  uVar1 >> 0x10 & 0xff,uVar1 >> 0x18);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < numipfilters);
    }
    fclose(__stream);
  }
  return;
}


// SV_WriteMovevarsToClient  @ 08071920
void SV_WriteMovevarsToClient(undefined4 param_1)

{
  MSG_WriteByte(param_1,0x2e);
  MSG_WriteByte(param_1,(byte)((byte)((ushort)((ushort)NAN((float)movevars._0_4_) << 10) >> 8) |
                              (byte)((ushort)((ushort)((float)movevars._0_4_ == 0.0) << 0xe) >> 8))
                        != 0x40);
  MSG_WriteFloat(param_1,movevars._4_4_);
  MSG_WriteFloat(param_1,movevars._8_4_);
  MSG_WriteFloat(param_1,movevars._12_4_);
  MSG_WriteFloat(param_1,movevars._16_4_);
  MSG_WriteFloat(param_1,movevars._20_4_);
  MSG_WriteFloat(param_1,movevars._24_4_);
  MSG_WriteFloat(param_1,movevars._28_4_);
  MSG_WriteFloat(param_1,movevars._32_4_);
  MSG_WriteFloat(param_1,movevars._36_4_);
  MSG_WriteFloat(param_1,movevars._40_4_);
  MSG_WriteFloat(param_1,movevars._44_4_);
  MSG_WriteFloat(param_1,movevars._48_4_);
  MSG_WriteFloat(param_1,movevars._52_4_);
  MSG_WriteFloat(param_1,movevars._56_4_);
  MSG_WriteFloat(param_1,movevars._60_4_);
  MSG_WriteFloat(param_1,movevars._64_4_);
  MSG_WriteString(param_1,0x811c5e4);
  return;
}


// SV_WritePlayersToClient  @ 08075510
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_WritePlayersToClient(int param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined2 in_FPUControlWord;
  byte local_88;
  byte local_80;
  uint local_70;
  int *local_68;
  undefined2 local_64;
  byte local_61;
  undefined2 local_60;
  byte local_5d;
  uint local_5c;
  undefined4 local_58 [9];
  int local_34;
  undefined2 local_2c;
  undefined2 uStack_2a;
  int local_28 [7];
  undefined2 local_a;
  undefined1 local_8;
  
  iVar2 = *(int *)(param_1 + 0x4f08);
  local_5c = 0;
  local_68 = DAT_0816dd10;
  if (0 < svs) {
    do {
      if ((local_68[1] != 0) || (*local_68 != 0)) {
        iVar3 = local_68[0x13c2];
        bVar4 = true;
        iVar5 = SV_ShouldUpdatePing(local_5c);
        if ((iVar3 == iVar2) ||
           ((*(int *)(param_1 + 0x10) != 0 && (*(int *)(param_1 + 0x10) - 1U == local_5c)))) {
LAB_08075625:
          if (!bVar4) goto LAB_08075629;
        }
        else {
          if (local_68[0xfaf] == 0) {
            iVar7 = 0;
            if (0 < *(int *)(iVar3 + 0x10)) {
              do {
                if ((*(byte *)((*(short *)(iVar7 * 2 + iVar3 + 0x14) >> 3) + param_2) >>
                     (int)(short)(*(ushort *)(iVar7 * 2 + iVar3 + 0x14) & 7) & 1) != 0) break;
                iVar7 = iVar7 + 1;
              } while (iVar7 < *(int *)(iVar3 + 0x10));
            }
            if (iVar7 == *(int *)(iVar3 + 0x10)) {
              bVar4 = false;
            }
            goto LAB_08075625;
          }
          bVar4 = false;
LAB_08075629:
          if (iVar5 == 0) goto LAB_08076298;
        }
        local_70 = PF_MSEC | PF_COMMAND;
        if (*(int *)(iVar3 + 0x170) != sv_playermodel) {
          if (*(int *)(iVar3 + 0x170) < 0x100) {
            local_70 = local_70 | PF_MODEL;
          }
          else {
            local_70 = local_70 | PF_LONGMODEL;
          }
        }
        if (*(int *)(iVar3 + 0x17c) != 0) {
          if (*(int *)(iVar3 + 0x17c) < 0x100) {
            local_70 = local_70 | PF_WEAPONMODEL;
          }
          else {
            local_70 = local_70 | PF_LONGWEAPONMODEL;
          }
        }
        if ((*(int *)(iVar3 + 0x1e4) != 0) ||
           (fVar1 = *(float *)(iVar3 + 0x1f0),
           (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
          local_70 = local_70 | PF_SEQUENCE;
        }
        if (*(int *)(iVar3 + 0x1e8) != 0) {
          local_70 = local_70 | PF_GAIT;
        }
        if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0xfc)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar3 + 0xfc) == 0.0) << 0xe) >> 8)) != 0x40)
           || (fVar1 = *(float *)(iVar3 + 0x100),
              (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
          local_70 = local_70 | PF_VELOCITY1OR2;
        }
        fVar1 = *(float *)(iVar3 + 0x104);
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          local_70 = local_70 | PF_VELOCITY3;
        }
        if (*(int *)(iVar3 + 0x1d4) != 0) {
          local_70 = local_70 | PF_EFFECTS;
        }
        fVar1 = *(float *)(iVar3 + 500);
        if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
          local_70 = local_70 | PF_FRAMERATE;
        }
        if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x114)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x114) == 0.0) << 0xe) >> 8)) !=
              0x40) ||
            ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x118)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x118) == 0.0) << 0xe) >> 8)) != 0x40
            )) || (fVar1 = *(float *)(iVar3 + 0x11c),
                  (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
          local_70 = local_70 | PF_BASEVELOCITY;
        }
        iVar7 = 0;
        do {
          if (*(char *)(iVar7 + iVar3 + 0x1f8) != '\0') {
            local_70 = local_70 | PF_CONTROLLER1 << ((byte)iVar7 & 0x1f);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 4);
        iVar7 = 0;
        do {
          if (*(char *)(iVar7 + iVar3 + 0x1fc) != '\0') {
            local_70 = local_70 | PF_BLENDING1 << ((byte)iVar7 & 0x1f);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
        if (*(int *)(iVar3 + 0x1d0) != 0) {
          local_70 = local_70 | PF_BODY;
        }
        if (*(int *)(iVar3 + 0x1cc) != 0) {
          local_70 = local_70 | PF_SKINNUM;
        }
        fVar1 = *(float *)(iVar3 + 0x1dc);
        if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
          local_70 = local_70 | PF_FRICTION;
        }
        if ((((*(int *)(iVar3 + 0x204) != 0) ||
             ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x208)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x208) == 0.0) << 0xe) >> 8)) !=
              0x40)) ||
            ((*(int *)(iVar3 + 0x218) != 0 ||
             (((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x20c)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x20c) == 0.0) << 0xe) >> 8)) !=
               0x40 || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x210)) << 10) >> 8) |
                              (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x210) == 0.0) << 0xe) >>
                                    8)) != 0x40)))))) ||
           (fVar1 = *(float *)(iVar3 + 0x214),
           (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
          local_70 = local_70 | PF_RENDER;
        }
        if (*(float *)(iVar3 + 0x21c) <= 0.0) {
          local_70 = local_70 | PF_DEAD;
        }
        if (*(int *)(iVar3 + 0x1c4) != 3) {
          local_70 = local_70 | PF_MOVETYPE;
        }
        if (local_68[0xfaf] == 0) {
          if (iVar3 == iVar2) {
            local_70 = local_70 & ~PF_MSEC;
            if ((byte)((byte)((ushort)((ushort)NAN((float)sv_sendvelocity._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)sv_sendvelocity._12_4_ == 0.0) << 0xe) >> 8))
                == 0x40) {
              uVar6 = ~(PF_VELOCITY1OR2 | PF_VELOCITY3);
              goto LAB_08075943;
            }
            goto LAB_08075946;
          }
        }
        else {
          uVar6 = PF_VELOCITY1OR2 | PF_VELOCITY3;
LAB_08075943:
          local_70 = local_70 & uVar6;
LAB_08075946:
          if ((((iVar3 == iVar2) && (sv != 0)) && (cls == 5)) &&
             ((*(int *)(param_1 + 0x14) == 1 &&
              ((byte)((byte)((ushort)((ushort)NAN((float)fakelag._12_4_) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)fakelag._12_4_ == 0.0) << 0xe) >> 8)) == 0x40))
             )) {
            local_70 = local_70 | PF_VELOCITY1OR2 | PF_VELOCITY3;
          }
        }
        if (iVar5 != 0) {
          if (bVar4) {
            local_70 = local_70 | PF_PING;
          }
          else if ((iVar5 != 0) && (!bVar4)) {
            local_70 = PF_PING;
          }
        }
        local_5d = 0;
        if ((*(byte *)(iVar3 + 0x263) & 1) != 0) {
          local_5d = PLPHYS_ONTRAIN;
        }
        if ((*(byte *)(iVar3 + 0x261) & 0x40) != 0) {
          local_5d = local_5d | PLPHYS_DUCKING;
        }
        if ((*(byte *)(iVar3 + 0x261) & 0x10) != 0) {
          local_5d = local_5d | PLPHYS_FROZEN;
        }
        if ((*(byte *)(iVar3 + 0x263) & 4) != 0) {
          local_5d = local_5d | PLPHYS_SPECTATOR;
        }
        if ((*(byte *)(iVar3 + 0x261) & 8) != 0) {
          local_5d = local_5d | PLPHYS_WATERJUMP;
        }
        MSG_WriteByte(param_3,0x2b);
        if (0xff < (int)local_70) {
          local_70 = local_70 | PF_MOREBITS;
        }
        if (0xffff < (int)local_70) {
          local_70 = local_70 | PF_EVENMOREBITS;
        }
        if (0xffffff < (int)local_70) {
          local_70 = local_70 | PF_YETMOREBITS;
        }
        MSG_WriteByte(param_3,local_70);
        if ((local_70 & PF_MOREBITS) != 0) {
          MSG_WriteByte(param_3,(int)local_70 >> 8);
        }
        if ((local_70 & PF_EVENMOREBITS) != 0) {
          MSG_WriteByte(param_3,(int)local_70 >> 0x10);
        }
        if ((local_70 & PF_YETMOREBITS) != 0) {
          MSG_WriteByte(param_3,(int)local_70 >> 0x18);
        }
        MSG_StartBitWriting(param_3);
        if (local_68[0xfaf] != 0) {
          local_5c = local_5c | 0x40;
        }
        MSG_WriteBitByte(&local_5c,6);
        MSG_WriteBitByte(&local_5d,5);
        iVar5 = 0;
        do {
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0xe4 + iVar5 * 4) * 8.0);
          MSG_WriteSBitShort(&local_60,0x10);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
        _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
        local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
        local_80 = (byte)(int)ROUND(*(float *)(iVar3 + 0x1ec));
        local_61 = local_80;
        MSG_WriteBitByte(&local_61,8);
        if ((local_70 & PF_COMMAND) != 0) {
          piVar8 = local_68 + 0xfb3;
          piVar9 = local_28;
          for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar9 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar9 = piVar9 + 1;
          }
          if (*(float *)(iVar3 + 0x21c) <= 0.0) {
            local_28[2] = *(undefined4 *)(iVar3 + 0x130);
            local_28[1] = 0;
          }
          local_a = 0;
          local_8 = 0;
          puVar10 = local_58;
          for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar10 = 0;
            puVar10 = puVar10 + 1;
          }
          MSG_WriteBitUsercmd(local_28,local_58);
        }
        if ((local_70 & PF_MSEC) != 0) {
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = (int)ROUND((_DAT_0811d24c - *(double *)(local_68 + 0xfbc)) * 1000.0);
          iVar5 = local_34;
          if (0xff < local_34) {
            iVar5 = 0xff;
          }
          local_61 = (byte)iVar5;
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_VELOCITY1OR2) != 0) {
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0xfc) * 0.25);
          MSG_WriteSBitShort(&local_60,9);
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0x100) * 0.25);
          MSG_WriteSBitShort(&local_60,9);
        }
        if ((local_70 & PF_VELOCITY3) != 0) {
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0x104) * 0.25);
          MSG_WriteSBitShort(&local_60,9);
        }
        if ((local_70 & PF_MODEL) == 0) {
          if ((local_70 & PF_LONGMODEL) != 0) {
            local_64 = *(undefined2 *)(iVar3 + 0x170);
            MSG_WriteBitShort(&local_64,10);
          }
        }
        else {
          local_61 = *(byte *)(iVar3 + 0x170);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_SKINNUM) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1cc);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_EFFECTS) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1d4);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_LONGWEAPONMODEL) == 0) {
          if ((local_70 & PF_WEAPONMODEL) != 0) {
            local_61 = SV_ModelIndex(*(int *)(iVar3 + 0x17c) + pr_strings);
            MSG_WriteBitByte(&local_61,8);
          }
        }
        else {
          local_64 = SV_ModelIndex(*(int *)(iVar3 + 0x17c) + pr_strings);
          MSG_WriteBitShort(&local_64,10);
        }
        if ((local_70 & PF_MOVETYPE) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1c4);
          MSG_WriteBitByte(&local_61,4);
        }
        if ((local_70 & PF_SEQUENCE) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1e4);
          MSG_WriteBitByte(&local_61,8);
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_80 = (byte)(int)ROUND(*(float *)(iVar3 + 0x1f0) * 100.0);
          local_61 = local_80;
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_RENDER) != 0) {
          local_61 = *(byte *)(iVar3 + 0x204);
          MSG_WriteBitByte(&local_61,8);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_80 = (byte)(longlong)ROUND(*(float *)(iVar3 + 0x208));
          local_61 = local_80;
          MSG_WriteBitByte(&local_61,8);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_88 = (byte)(longlong)ROUND(*(float *)(iVar3 + 0x20c));
          local_61 = local_88;
          MSG_WriteBitByte(&local_61,8);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_88 = (byte)(longlong)ROUND(*(float *)(iVar3 + 0x210));
          local_61 = local_88;
          MSG_WriteBitByte(&local_61,8);
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_88 = (byte)(longlong)ROUND(*(float *)(iVar3 + 0x214));
          local_61 = local_88;
          MSG_WriteBitByte(&local_61,8);
          local_61 = *(byte *)(iVar3 + 0x218);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_FRAMERATE) != 0) {
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_88 = (byte)(int)ROUND(*(float *)(iVar3 + 500) * 16.0);
          local_61 = local_88;
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_BODY) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1d0);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_CONTROLLER1) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1f8);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_CONTROLLER2) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1f9);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_CONTROLLER3) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1fa);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_CONTROLLER4) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1fb);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_BLENDING1) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1fc);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_BLENDING2) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1fd);
          MSG_WriteBitByte(&local_61,8);
        }
        if ((local_70 & PF_BASEVELOCITY) != 0) {
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0x114) * 8.0);
          MSG_WriteSBitShort(&local_64,0x10);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0x118) * 8.0);
          MSG_WriteSBitShort(&local_64,0x10);
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0x11c) * 8.0);
          MSG_WriteSBitShort(&local_64,0x10);
        }
        if ((local_70 & PF_FRICTION) != 0) {
          _local_2c = CONCAT22(uStack_2a,in_FPUControlWord);
          local_34 = CONCAT22(uStack_2a,CONCAT11(0xc,(char)in_FPUControlWord));
          local_60 = (undefined2)(int)ROUND(*(float *)(iVar3 + 0x1dc) * 8.0);
          MSG_WriteBitShort(&local_64,0x10);
        }
        if ((local_70 & PF_PING) != 0) {
          local_64 = SV_CalcPing(local_68);
          MSG_WriteBitShort(&local_64,0xc);
          local_61 = SV_CalcPacketLoss(local_68);
          if (0x3f < local_61) {
            local_61 = 0x3f;
          }
          MSG_WriteBitByte(&local_61,6);
        }
        if ((local_70 & PF_GAIT) != 0) {
          local_61 = *(byte *)(iVar3 + 0x1e8);
          MSG_WriteBitByte(&local_61,8);
        }
        MSG_EndBitWriting(param_3);
      }
LAB_08076298:
      local_5c = local_5c + 1;
      local_68 = local_68 + 0x14ae;
    } while ((int)local_5c < svs);
  }
  return;
}


// SV_movestep  @ 080795d0
/* WARNING: Type propagation algorithm not settling */

undefined4 SV_movestep(uint param_1,float *param_2,int param_3)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint *puVar5;
  int iVar6;
  uint auStack_80 [2];
  int local_60;
  int local_5c;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_30;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = (uint)((*(byte *)(param_1 + 0x262) & 0x80) != 0);
  local_10 = *(undefined4 *)(param_1 + 0xe4);
  local_c = *(undefined4 *)(param_1 + 0xe8);
  local_8 = *(undefined4 *)(param_1 + 0xec);
  local_1c = *(float *)(param_1 + 0xe4) + *param_2;
  local_18 = *(float *)(param_1 + 0xe8) + param_2[1];
  if ((*(byte *)(param_1 + 0x260) & 3) == 0) {
    local_14 = *(float *)(param_1 + 0xec) + param_2[2] + (float)sv_stepsize._12_4_;
    local_20 = local_14 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
    auStack_80[0] = param_1;
    auStack_80[1] = uVar3;
    local_28 = local_1c;
    local_24 = local_18;
    SV_Move(&local_60,&local_1c,param_1 + 0x198,param_1 + 0x1a4,&local_28,0);
    puVar5 = auStack_80 + 1;
    if (local_60 != 0) {
      return 0;
    }
    if (local_5c != 0) {
      local_14 = local_14 - (float)sv_stepsize._12_4_;
      auStack_80[0] = uVar3;
      SV_Move(&local_60,&local_1c,param_1 + 0x198,param_1 + 0x1a4,&local_28,0,param_1);
      puVar5 = auStack_80;
      if (local_60 != 0) {
        return 0;
      }
      if (local_5c != 0) {
        return 0;
      }
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) == 0x40) {
      if ((*(byte *)(param_1 + 0x261) & 4) != 0) {
        *(float *)(param_1 + 0xe4) = *(float *)(param_1 + 0xe4) + *param_2;
        *(float *)(param_1 + 0xe8) = *(float *)(param_1 + 0xe8) + param_2[1];
        *(float *)(param_1 + 0xec) = *(float *)(param_1 + 0xec) + param_2[2];
        if (param_3 != 0) {
          puVar5[0xffffffff] = 1;
          puVar5[0xfffffffe] = param_1;
          puVar5[0xfffffffd] = 0x8079865;
          SV_LinkEdict();
        }
        *(byte *)(param_1 + 0x261) = *(byte *)(param_1 + 0x261) & 0xfd;
        return 1;
      }
      return 0;
    }
    *(undefined4 *)(param_1 + 0xe4) = local_4c;
    *(undefined4 *)(param_1 + 0xe8) = local_48;
    *(undefined4 *)(param_1 + 0xec) = local_44;
    puVar5[0xffffffff] = param_1;
    puVar5[0xfffffffe] = 0x8079891;
    iVar6 = SV_CheckBottom();
    if (iVar6 == 0) {
      if ((*(byte *)(param_1 + 0x261) & 4) == 0) {
        *(undefined4 *)(param_1 + 0xe4) = local_10;
        *(undefined4 *)(param_1 + 0xe8) = local_c;
        *(undefined4 *)(param_1 + 0xec) = local_8;
        return 0;
      }
    }
    else {
      if ((*(byte *)(param_1 + 0x261) & 4) != 0) {
        *(byte *)(param_1 + 0x261) = *(byte *)(param_1 + 0x261) & 0xfb;
      }
      *(undefined4 *)(param_1 + 600) = local_30;
    }
  }
  else {
    iVar6 = 0;
    puVar4 = &stack0xffffff88;
    while( true ) {
      local_1c = *(float *)(param_1 + 0xe4) + *param_2;
      local_18 = *(float *)(param_1 + 0xe8) + param_2[1];
      local_14 = *(float *)(param_1 + 0xec) + param_2[2];
      iVar1 = *(int *)(param_1 + 0x24c);
      if ((iVar6 == 0) && (iVar1 != 0)) {
        fVar2 = *(float *)(param_1 + 0xec) - *(float *)(iVar1 + 0xec);
        if ((byte)(40.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 40.0) << 0xe) >> 8)) == 1) {
          local_14 = local_14 - 8.0;
        }
        if (fVar2 < 30.0) {
          local_14 = local_14 + 8.0;
        }
      }
      *(uint *)(puVar4 + -4) = uVar3;
      *(uint *)(puVar4 + -8) = param_1;
      *(undefined4 *)(puVar4 + -0xc) = 0;
      *(float **)(puVar4 + -0x10) = &local_1c;
      *(uint *)(puVar4 + -0x14) = param_1 + 0x1a4;
      *(uint *)(puVar4 + -0x18) = param_1 + 0x198;
      *(uint *)(puVar4 + -0x1c) = param_1 + 0xe4;
      *(int **)(puVar4 + -0x20) = &local_60;
      *(undefined4 *)(puVar4 + -0x24) = 0x80796ea;
      SV_Move();
      if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) == 0x40) break;
      if (iVar1 == 0) {
        return 0;
      }
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + -4;
      if (1 < iVar6) {
        return 0;
      }
    }
    if ((*(byte *)(param_1 + 0x260) & 2) != 0) {
      *(undefined4 **)(puVar4 + -8) = &local_4c;
      *(undefined4 *)(puVar4 + -0xc) = 0x8079710;
      iVar6 = SV_PointContents();
      if (iVar6 == -1) {
        return 0;
      }
    }
    puVar5 = (uint *)(puVar4 + -4);
    *(undefined4 *)(param_1 + 0xe4) = local_4c;
    *(undefined4 *)(param_1 + 0xe8) = local_48;
    *(undefined4 *)(param_1 + 0xec) = local_44;
  }
  if (param_3 != 0) {
    *(undefined4 *)((int)puVar5 + -4) = 1;
    *(uint *)((int)puVar5 + -8) = param_1;
    *(undefined4 *)((int)puVar5 + -0xc) = 0x80798e7;
    SV_LinkEdict();
  }
  return 1;
}


// SV_movetest  @ 080793f0
undefined4 SV_movetest(int param_1,float *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iStack_74;
  int iStack_70;
  int local_60;
  int local_5c;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_30;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *(undefined4 *)(param_1 + 0xe4);
  local_c = *(undefined4 *)(param_1 + 0xe8);
  local_8 = *(undefined4 *)(param_1 + 0xec);
  local_28 = *(float *)(param_1 + 0xe4) + *param_2;
  local_24 = *(float *)(param_1 + 0xe8) + param_2[1];
  local_14 = *(float *)(param_1 + 0xec) + param_2[2] + (float)sv_stepsize._12_4_;
  local_20 = local_14 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
  iStack_70 = param_1;
  iStack_74 = 0;
  local_1c = local_28;
  local_18 = local_24;
  SV_MoveNoEnts(&local_60,&local_1c,param_1 + 0x198,param_1 + 0x1a4,&local_28);
  piVar3 = &iStack_70;
  if (local_60 == 0) {
    if (local_5c != 0) {
      local_14 = local_14 - (float)sv_stepsize._12_4_;
      iStack_74 = param_1;
      SV_MoveNoEnts(&local_60,&local_1c,param_1 + 0x198,param_1 + 0x1a4,&local_28,0);
      piVar3 = &iStack_74;
      if ((local_60 != 0) || (local_5c != 0)) goto LAB_0807958c;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) == 0x40) {
      if ((*(byte *)(param_1 + 0x261) & 4) == 0) goto LAB_0807958c;
      *(float *)(param_1 + 0xe4) = *(float *)(param_1 + 0xe4) + *param_2;
      *(float *)(param_1 + 0xe8) = *(float *)(param_1 + 0xe8) + param_2[1];
      *(float *)(param_1 + 0xec) = *(float *)(param_1 + 0xec) + param_2[2];
      if (param_3 != 0) {
        *(undefined4 *)((int)piVar3 + -4) = 1;
        *(int *)((int)piVar3 + -8) = param_1;
        *(undefined4 *)((int)piVar3 + -0xc) = 0x8079532;
        SV_LinkEdict();
      }
      *(byte *)(param_1 + 0x261) = *(byte *)(param_1 + 0x261) & 0xfd;
    }
    else {
      *(undefined4 *)(param_1 + 0xe4) = local_4c;
      *(undefined4 *)(param_1 + 0xe8) = local_48;
      *(undefined4 *)(param_1 + 0xec) = local_44;
      *(int *)((int)piVar3 + -4) = param_1;
      *(undefined4 *)((int)piVar3 + -8) = 0x8079561;
      iVar1 = SV_CheckBottom();
      if (iVar1 == 0) {
        if ((*(byte *)(param_1 + 0x261) & 4) == 0) {
          *(undefined4 *)(param_1 + 0xe4) = local_10;
          *(undefined4 *)(param_1 + 0xe8) = local_c;
          *(undefined4 *)(param_1 + 0xec) = local_8;
          goto LAB_0807958c;
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x261) & 4) != 0) {
          *(byte *)(param_1 + 0x261) = *(byte *)(param_1 + 0x261) & 0xfb;
        }
        *(undefined4 *)(param_1 + 600) = local_30;
      }
      if (param_3 != 0) {
        *(undefined4 *)((int)piVar3 + -4) = 1;
        *(int *)((int)piVar3 + -8) = param_1;
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80795b5;
        SV_LinkEdict();
      }
    }
    uVar2 = 1;
  }
  else {
LAB_0807958c:
    uVar2 = 0;
  }
  return uVar2;
}


