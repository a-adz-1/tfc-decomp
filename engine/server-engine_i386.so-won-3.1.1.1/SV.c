// SV_ActivateServer  @ 000a900c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ActivateServer(int param_1)

{
  undefined4 uVar1;
  char *apcStack_1001c [2];
  undefined1 *puStack_10014;
  undefined4 uStack_10010;
  undefined4 uStack_1000c;
  undefined1 auStack_10008 [65536];
  int local_8;
  
  Q_memset(apcStack_1001c,0,0x14);
  apcStack_1001c[0] = "Activate Server";
  puStack_10014 = auStack_10008;
  uStack_1000c = 0;
  uStack_10010 = 0x10000;
  g_bIsCStrike = 0;
  Cvar_Set("sv_newunit",&DAT_000e8746);
  ContinueLoadingProgressBar("Server",8,0);
  (*_DAT_0036af94)(DAT_003a78b8,DAT_003a78b0,DAT_00524288);
  ContinueLoadingProgressBar("Server",9,0);
  SV_CreateGenericResources();
  sv = 1;
  DAT_003a78c4 = 2;
  ContinueLoadingProgressBar("Server",10,0);
  if (param_1 == 0) {
    host_frametime = 0x3f50624dd2f1a9fc;
    SV_Physics();
  }
  else if (DAT_00524288 < 2) {
    host_frametime = 0x3fb999999999999a;
    SV_Physics();
    SV_Physics();
  }
  else {
    host_frametime = 0x3fe999999999999a;
    for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
      SV_Physics();
    }
  }
  SV_CreateBaseline();
  SV_CreateResourceList();
  DAT_0039bda4 = SV_TransferConsistencyInfo();
  host_client = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (((*host_client != 0) || (host_client[3] != 0)) && (host_client[0x90e] == 0)) {
      Netchan_Clear(host_client + 7);
      if (DAT_00524288 < 2) {
        SV_SendServerinfo(apcStack_1001c,host_client);
      }
      else {
        SV_BuildReconnect(host_client + 0x1d);
        Netchan_Transmit(host_client + 7,0,0);
      }
      uVar1 = sv_gpNewUserMsgs;
      if (sv_gpUserMsgs != 0) {
        sv_gpNewUserMsgs = sv_gpUserMsgs;
        SV_SendUserReg(apcStack_1001c);
      }
      sv_gpNewUserMsgs = uVar1;
      host_client[5] = 1;
      Netchan_CreateFragments(1,host_client + 7,apcStack_1001c);
      Netchan_FragSend(host_client + 7);
      SZ_Clear(apcStack_1001c);
    }
    host_client = host_client + 0x13bb;
  }
  FUN_000a9348();
  return;
}


// SV_AddCorrectGravity  @ 000b1bb0
void SV_AddCorrectGravity(int param_1)

{
  float fVar1;
  undefined4 local_8;
  
  fVar1 = *(float *)(param_1 + 0x19c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_8 = 1.0;
  }
  else {
    local_8 = *(float *)(param_1 + 0x19c);
  }
  *(float *)(param_1 + 0xa8) =
       *(float *)(param_1 + 0xa8) - local_8 * (float)sv_gravity._12_4_ * 0.5 * (float)host_frametime
  ;
  *(float *)(param_1 + 0xa8) =
       *(float *)(param_1 + 0xb4) * (float)host_frametime + *(float *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xb4) = 0;
  SV_CheckVelocity(param_1);
  return;
}


// SV_AddFailedRcon  @ 000a3250
void SV_AddFailedRcon(int *param_1)

{
  undefined4 uVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int aiStack_8c [8];
  char *pcStack_6c;
  undefined4 local_68;
  undefined4 uStack_60;
  int local_20;
  int *local_1c;
  float local_10;
  int local_c;
  int local_8;
  
  uStack_60 = 0xa325e;
  local_c = 0;
  local_10 = -99999.0;
  bVar3 = false;
  sv_rcon_minfailures._12_4_ = (undefined4)(int)ROUND((float)sv_rcon_minfailures._12_4_);
  sv_rcon_maxfailures._12_4_ = (undefined4)(int)ROUND((float)sv_rcon_maxfailures._12_4_);
  sv_rcon_minfailuretime._12_4_ = (undefined4)(int)ROUND((float)sv_rcon_minfailuretime._12_4_);
  if ((float)sv_rcon_minfailures._12_4_ < 1.0) {
    local_68 = 0x3f800000;
    pcStack_6c = "sv_rcon_minfailures";
    aiStack_8c[7] = 0xa3342;
    Cvar_SetValue();
  }
  if ((byte)(20.0 < (float)sv_rcon_minfailures._12_4_ |
             (byte)((ushort)((ushort)NAN((float)sv_rcon_minfailures._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_rcon_minfailures._12_4_ == 20.0) << 0xe) >> 8)) == 1)
  {
    local_68 = 0x41a00000;
    pcStack_6c = "sv_rcon_minfailures";
    aiStack_8c[7] = 0xa337d;
    Cvar_SetValue();
  }
  if ((float)sv_rcon_maxfailures._12_4_ < 1.0) {
    local_68 = 0x3f800000;
    pcStack_6c = "sv_rcon_maxfailures";
    aiStack_8c[7] = 0xa33aa;
    Cvar_SetValue();
  }
  if ((byte)(20.0 < (float)sv_rcon_maxfailures._12_4_ |
             (byte)((ushort)((ushort)NAN((float)sv_rcon_maxfailures._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_rcon_maxfailures._12_4_ == 20.0) << 0xe) >> 8)) == 1)
  {
    local_68 = 0x41a00000;
    pcStack_6c = "sv_rcon_maxfailures";
    aiStack_8c[7] = 0xa33e5;
    Cvar_SetValue();
  }
  if ((byte)((float)sv_rcon_maxfailures._12_4_ < (float)sv_rcon_minfailures._12_4_ |
             (byte)((ushort)((ushort)(NAN((float)sv_rcon_maxfailures._12_4_) ||
                                     NAN((float)sv_rcon_minfailures._12_4_)) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_rcon_maxfailures._12_4_ ==
                                    (float)sv_rcon_minfailures._12_4_) << 0xe) >> 8)) == 1) {
    uVar1 = sv_rcon_maxfailures._12_4_;
    local_68 = sv_rcon_minfailures._12_4_;
    pcStack_6c = "sv_rcon_maxfailures";
    aiStack_8c[7] = 0xa3430;
    Cvar_SetValue();
    pcStack_6c = "sv_rcon_minfailures";
    aiStack_8c[7] = 0xa344d;
    local_68 = uVar1;
    Cvar_SetValue();
  }
  if ((float)sv_rcon_minfailuretime._12_4_ < 1.0) {
    local_68 = 0x3f800000;
    pcStack_6c = "sv_rcon_minfailuretime";
    aiStack_8c[7] = 0xa347a;
    Cvar_SetValue();
  }
  local_8 = 0;
  do {
    if (0x1f < local_8) {
LAB_000a353c:
      if (0x1f < local_8) {
        local_1c = (int *)(g_rgRconFailures + local_c * 0x74);
      }
      if ((local_1c != (int *)0x0) && ((!bVar3 || (local_1c[1] == 0)))) {
        *local_1c = 1;
        local_1c[1] = 0;
        local_1c[8] = (int)(float)realtime;
        piVar7 = param_1;
        piVar8 = local_1c + 2;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar8 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar8 = piVar8 + 1;
        }
        if (!bVar3) {
          local_1c[7] = 0;
        }
        if ((float)sv_rcon_maxfailures._12_4_ <= (float)local_1c[7]) {
          local_8 = 1;
          while (fVar2 = (float)local_8,
                (byte)(fVar2 < (float)sv_rcon_maxfailures._12_4_ |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN((float)sv_rcon_maxfailures._12_4_)
                                               ) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == (float)sv_rcon_maxfailures._12_4_) << 0xe)
                            >> 8)) == 1) {
            local_1c[local_8 + 8] = local_1c[local_8 + 9];
            local_8 = local_8 + 1;
          }
          local_1c[7] = local_1c[7] + -1;
        }
        local_1c[local_1c[7] + 9] = (int)(float)realtime;
        local_1c[7] = local_1c[7] + 1;
        local_20 = 0;
        for (local_8 = 0; local_8 < local_1c[7]; local_8 = local_8 + 1) {
          fVar2 = (float)realtime - (float)local_1c[local_8 + 9];
          if ((byte)(fVar2 < (float)sv_rcon_minfailuretime._12_4_ |
                     (byte)((ushort)((ushort)(NAN(fVar2) ||
                                             NAN((float)sv_rcon_minfailuretime._12_4_)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == (float)sv_rcon_minfailuretime._12_4_) << 0xe
                                     ) >> 8)) == 1) {
            local_20 = local_20 + 1;
          }
        }
        if ((float)sv_rcon_minfailures._12_4_ <= (float)local_20) {
          piVar7 = aiStack_8c + 2;
          for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar7 = *param_1;
            param_1 = param_1 + 1;
            piVar7 = piVar7 + 1;
          }
          aiStack_8c[1] = 0xa370a;
          local_68 = NET_AdrToString();
          pcStack_6c = "User %s will be banned for rcon hacking\n";
          aiStack_8c[7] = 0xa371e;
          Con_Printf();
          local_1c[1] = 1;
        }
      }
      return;
    }
    iVar5 = local_8 * 0x74;
    local_1c = (int *)(g_rgRconFailures + iVar5);
    if (*local_1c == 0) goto LAB_000a353c;
    piVar7 = param_1;
    piVar8 = aiStack_8c + 5;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar8 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar8 = piVar8 + 1;
    }
    puVar6 = (undefined4 *)(g_rgRconFailures + iVar5 + 8);
    piVar7 = aiStack_8c;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      piVar7 = piVar7 + 1;
    }
    iVar4 = NET_CompareAdr();
    if (iVar4 != 0) {
      bVar3 = true;
      goto LAB_000a353c;
    }
    if (local_10 < (float)realtime - *(float *)(g_rgRconFailures + iVar5 + 0x20)) {
      local_c = local_8;
      local_10 = (float)realtime - *(float *)(g_rgRconFailures + iVar5 + 0x20);
    }
    local_8 = local_8 + 1;
  } while( true );
}


// SV_AddGravity  @ 000b1b00
void SV_AddGravity(int param_1)

{
  float fVar1;
  undefined4 local_8;
  
  fVar1 = *(float *)(param_1 + 0x19c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_8 = 1.0;
  }
  else {
    local_8 = *(float *)(param_1 + 0x19c);
  }
  *(float *)(param_1 + 0xa8) =
       *(float *)(param_1 + 0xa8) - local_8 * (float)sv_gravity._12_4_ * (float)host_frametime;
  *(float *)(param_1 + 0xa8) =
       *(float *)(param_1 + 0xb4) * (float)host_frametime + *(float *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xb4) = 0;
  SV_CheckVelocity(param_1);
  return;
}


// SV_AddIP_f  @ 000aba44
void SV_AddIP_f(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  longdouble lVar6;
  int local_1c;
  int local_18;
  float local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0.0;
  iVar2 = Cmd_Argc();
  if (iVar2 == 3) {
    uVar3 = Cmd_Argv(1);
    lVar6 = (longdouble)Q_atof(uVar3);
    local_c = (float)lVar6;
    piVar4 = &local_1c;
    uVar3 = Cmd_Argv(2);
    iVar2 = StringToFilter(uVar3,piVar4);
    if (iVar2 == 0) {
      Con_Printf(
                "Invalid IP address!\nUsage: addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n"
                );
    }
    else {
      for (local_8 = 0; local_8 < numipfilters; local_8 = local_8 + 1) {
        if ((*(int *)(ipfilters + local_8 * 0x10) == local_1c) &&
           (*(int *)(ipfilters + local_8 * 0x10 + 4) == local_18)) {
          *(float *)(ipfilters + local_8 * 0x10 + 0xc) = local_c;
          if ((byte)(0.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 0x40) {
            fVar1 = 0.0;
          }
          else {
            fVar1 = local_c * 60.0 + (float)realtime;
          }
          *(float *)(ipfilters + local_8 * 0x10 + 8) = fVar1;
          return;
        }
      }
      if (numipfilters <= local_8) {
        if (0x7fff < numipfilters) {
          Con_Printf("IP filter list is full\n");
          return;
        }
        numipfilters = numipfilters + 1;
      }
      if (local_c < 0.01) {
        local_c = 0.0;
      }
      *(float *)(ipfilters + local_8 * 0x10 + 0xc) = local_c;
      if ((byte)(0.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 0x40) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = local_c * 60.0 + (float)realtime;
      }
      *(float *)(ipfilters + local_8 * 0x10 + 8) = fVar1;
      *(int *)(ipfilters + local_8 * 0x10 + 4) = local_18;
      *(int *)(ipfilters + local_8 * 0x10) = local_1c;
      host_client = DAT_00524284;
      for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
        if ((((host_client[3] != 0) && (*host_client != 0)) && (host_client[1] != 0)) &&
           (host_client[0x90e] == 0)) {
          piVar4 = host_client + 8;
          piVar5 = &net_from;
          for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
            *piVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            piVar5 = piVar5 + 1;
          }
          iVar2 = SV_FilterPacket();
          if (iVar2 != 0) {
            SV_ClientPrintf("The server operator has added you to banned list\n");
            SV_DropClient(host_client,0,"Added to banned list");
          }
        }
        host_client = host_client + 0x13bb;
      }
    }
  }
  else {
    Con_Printf("Usage: addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n");
  }
  return;
}


// SV_AddLinksToPM  @ 000b7954
void SV_AddLinksToPM(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  float local_20 [6];
  int local_8;
  
  Q_memset(pmove + 0x250,0,0xe0);
  Q_memset("__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
           + pmove + 0x83,0,0xe0);
  *(int *)(pmove + 0x280) = DAT_0036bd88;
  if (DAT_0036bd88 != 0) {
    Q_strncpy(pmove + 0x250,DAT_0036bd88,0x20);
    *(undefined1 *)(pmove + 0x26f) = 0;
  }
  *(undefined4 *)(pmove + 0x274) = vec3_origin;
  *(undefined4 *)(pmove + 0x278) = DAT_000f1be0;
  *(undefined4 *)(pmove + 0x27c) = DAT_000f1be4;
  *(undefined4 *)(pmove + 0x2a0) = 0;
  *(undefined4 *)(pmove + 0x2b0) = 4;
  *(undefined4 *)(pmove + 0x2cc) = 0;
  *(undefined4 *)(pmove + 0x2d0) = 1;
  *(undefined4 *)(pmove + 0x2d4) = 0;
  *(undefined4 *)(pmove + 0x24c) = 1;
  pcVar3 = "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
           + pmove + 0x7f;
  pcVar3[0] = '\x01';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  puVar2 = (undefined4 *)(pmove + 0x250);
  pcVar3 = "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
           + pmove + 0x83;
  for (iVar1 = 0x38; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pcVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    pcVar3 = pcVar3 + 4;
  }
  *(undefined4 *)((int)&__DT_SYMTAB[0xbde].st_size + pmove) = 0;
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    local_20[local_8 + 3] = *(float *)(param_2 + local_8 * 4) - 256.0;
    local_20[local_8] = *(float *)(param_2 + local_8 * 4) + 256.0;
  }
  SV_AddLinksToPM_(param_1,local_20 + 3,local_20);
  return;
}


// SV_AddLinksToPM_  @ 000b74ac
void SV_AddLinksToPM_(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  longdouble lVar8;
  int *local_24;
  int *local_20;
  char *local_1c;
  undefined4 *local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)param_1[7];
  do {
    if (local_8 == param_1 + 6) {
      if (*param_1 != -1) {
        if ((float)param_1[1] < *(float *)(param_3 + *param_1 * 4)) {
          SV_AddLinksToPM_(param_1[2],param_2,param_3);
        }
        fVar3 = *(float *)(param_2 + *param_1 * 4);
        fVar4 = (float)param_1[1];
        if ((byte)(fVar3 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) == 1) {
          SV_AddLinksToPM_(param_1[3],param_2,param_3);
        }
      }
      return;
    }
    local_c = (int *)local_8[1];
    local_10 = local_8 + -2;
    if (local_8[0xae] == 0) {
LAB_000b7558:
      if (((int *)local_8[0x84] != sv_player) &&
         ((((local_8[0x61] == 4 || (local_8[0x61] == 2)) || (local_8[0x61] == 3)) ||
          (local_8[0x61] == 0)))) {
        iVar5 = NUM_FOR_EDICT(local_10);
        local_1c = "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                   + pmove + *(int *)(
                                     "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                                     + pmove + 0x7f) * 0xe0 + 0x83;
        *(int *)(
                "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                + pmove + 0x7f) =
             *(int *)(
                     "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                     + pmove + 0x7f) + 1;
        SV_CopyEdictToPhysent(local_1c,iVar5,local_10);
        if (((local_10[99] != 0) || ((local_10[100] != 0 && (local_10[0x4d] != 0)))) &&
           (((((local_10[0x89] & 0x800000U) == 0 || (local_10[99] != 4)) && (local_10 != sv_player))
            && (((((local_10[0x89] & 8U) == 0 || (0.0 < (float)local_10[0x78])) &&
                 (((byte)((byte)((ushort)((ushort)NAN((float)local_10[0x59]) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)local_10[0x59] == 0.0) << 0xe) >> 8)) !=
                   0x40 || ((byte)((byte)((ushort)((ushort)NAN((float)local_10[0x5c]) << 10) >> 8) |
                                  (byte)((ushort)((ushort)((float)local_10[0x5c] == 1.0) << 0xe) >>
                                        8)) != 0x40)))) &&
                (lVar8 = (longdouble)Length(local_10 + 0x5d),
                (byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar8)) << 10) >> 8) |
                      (byte)((ushort)((ushort)((longdouble)0 == lVar8) << 0xe) >> 8)) != 0x40))))))
        {
          local_20 = local_10 + 0x51;
          local_24 = local_10 + 0x54;
          if ((local_10[0x89] & 8U) != 0) {
            SV_GetTrueMinMax(iVar5 + -1,&local_20,&local_24);
          }
          iVar5 = pmove;
          for (local_14 = 0;
              (local_14 < 3 && ((float)local_20[local_14] <= *(float *)(param_3 + local_14 * 4)));
              local_14 = local_14 + 1) {
            fVar3 = (float)local_24[local_14];
            fVar4 = *(float *)(param_2 + local_14 * 4);
            if ((byte)(fVar3 < fVar4 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) == 1) break;
          }
          if (local_14 == 3) {
            if ((local_10[99] == 0) && (local_10[100] == -0x10)) {
              if (0x3f < *(int *)((int)&__DT_SYMTAB[0xbde].st_size + pmove)) {
                Con_DPrintf("SV_AddLinksToPM:  pmove->nummoveent >= MAX_MOVEENTS\n");
                goto LAB_000b78bd;
              }
              iVar1 = *(int *)((int)&__DT_SYMTAB[0xbde].st_size + pmove) * 0xe0 + 0x20f54;
              piVar2 = (int *)((int)&__DT_SYMTAB[0xbde].st_size + pmove);
              *piVar2 = *piVar2 + 1;
            }
            else {
              if (599 < *(int *)(pmove + 0x24c)) {
                Con_DPrintf("SV_AddLinksToPM:  pmove->numphysent >= MAX_PHYSENTS\n");
                return;
              }
              iVar1 = *(int *)(pmove + 0x24c) * 0xe0 + 0x250;
              *(int *)(pmove + 0x24c) = *(int *)(pmove + 0x24c) + 1;
            }
            local_18 = (undefined4 *)(iVar5 + iVar1);
            pcVar6 = local_1c;
            puVar7 = local_18;
            for (iVar5 = 0x38; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar7 = *(undefined4 *)pcVar6;
              pcVar6 = pcVar6 + 4;
              puVar7 = puVar7 + 1;
            }
          }
        }
      }
    }
    else if (g_groupop == 0) {
      if ((local_8[0xae] & sv_player[0xb0]) != 0) goto LAB_000b7558;
    }
    else if ((g_groupop != 1) || ((local_8[0xae] & sv_player[0xb0]) == 0)) goto LAB_000b7558;
LAB_000b78bd:
    local_8 = local_c;
  } while( true );
}


// SV_AddLogAddress_f  @ 0009ab24
void SV_AddLogAddress_f(void)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStackY_174 [2];
  void *local_128;
  undefined4 local_124;
  undefined1 local_120 [14];
  short local_112;
  char local_110 [260];
  int local_c;
  char *local_8;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 3) {
    local_8 = (char *)Cmd_Argv();
    Cmd_Argv();
    local_c = Q_atoi();
    if (local_c == 0) {
      Con_Printf();
    }
    else if ((local_8 == (char *)0x0) || (*local_8 == '\0')) {
      Con_Printf();
    }
    else {
      auStackY_174[1] = 0x9ac81;
      snprintf(local_110,0x104,"%s:%i");
      iVar2 = NET_StringToAdr();
      pvVar3 = firstLog;
      if (iVar2 == 0) {
        Con_Printf();
      }
      else if (firstLog == (void *)0x0) {
        firstLog = malloc(0x24);
        if (firstLog == (void *)0x0) {
          Con_Printf();
        }
        else {
          puVar4 = &local_124;
          puVar5 = (undefined4 *)((int)firstLog + 8);
          for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          *(undefined4 *)((int)firstLog + 0x20) = 0;
          puVar4 = &local_124;
          puVar5 = auStackY_174;
          for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          NET_AdrToString();
          Con_Printf();
        }
      }
      else {
        local_128 = firstLog;
        bVar1 = false;
        iVar2 = memcmp((void *)((int)firstLog + 0xc),local_120,4);
        if ((iVar2 == 0) && (*(short *)((int)pvVar3 + 0x1a) == local_112)) {
          bVar1 = true;
        }
        for (; *(int *)((int)local_128 + 0x20) != 0; local_128 = *(void **)((int)local_128 + 0x20))
        {
          iVar2 = memcmp((void *)((int)local_128 + 0xc),local_120,4);
          if ((iVar2 == 0) && (*(short *)((int)local_128 + 0x1a) == local_112)) {
            bVar1 = true;
            break;
          }
        }
        if (bVar1) {
          Con_Printf();
        }
        else {
          pvVar3 = malloc(0x24);
          if (pvVar3 == (void *)0x0) {
            Con_Printf();
          }
          else {
            *(void **)((int)local_128 + 0x20) = pvVar3;
            puVar4 = &local_124;
            puVar5 = (undefined4 *)((int)pvVar3 + 8);
            for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar5 = puVar5 + 1;
            }
            *(undefined4 *)((int)pvVar3 + 0x20) = 0;
            puVar4 = &local_124;
            puVar5 = auStackY_174;
            for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar5 = puVar5 + 1;
            }
            NET_AdrToString();
            Con_Printf();
          }
        }
      }
    }
  }
  else {
    Con_Printf();
    if (firstLog != (void *)0x0) {
      for (local_128 = firstLog; local_128 != (void *)0x0;
          local_128 = *(void **)((int)local_128 + 0x20)) {
        puVar4 = (undefined4 *)((int)local_128 + 8);
        puVar5 = auStackY_174;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        NET_AdrToString();
        Con_Printf();
      }
    }
  }
  return;
}


// SV_AddResource  @ 000a7c40
void SV_AddResource(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                   undefined4 param_5)

{
  int iVar1;
  
  iVar1 = DAT_003965a0 * 0x88;
  if (0x4ff < DAT_003965a0) {
    Sys_Error("Too many resources on server.");
  }
  DAT_003965a0 = DAT_003965a0 + 1;
  *(undefined4 *)(&DAT_0036bde0 + iVar1) = param_1;
  Q_strncpy(&DAT_0036bda0 + iVar1,param_2,0x3f);
  (&DAT_0036bddf)[iVar1] = 0;
  *(undefined4 *)(&DAT_0036bde8 + iVar1) = param_3;
  (&DAT_0036bdec)[iVar1] = param_4;
  *(undefined4 *)(&DAT_0036bde4 + iVar1) = param_5;
  return;
}


// SV_AddSampleToHashedLookupTable  @ 0009cae8
void SV_AddSampleToHashedLookupTable(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int local_8;
  
  iVar1 = SV_HashString(param_1,0x3ff);
  local_8 = iVar1;
  while (*(short *)(&DAT_0039e7a8 + local_8 * 2) != 0) {
    local_8 = local_8 + 1;
    hashstrings_collisions = hashstrings_collisions + 1;
    if (0x3fe < local_8) {
      local_8 = 0;
    }
    if (local_8 == iVar1) {
      Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
    }
  }
  *(undefined2 *)(&DAT_0039e7a8 + local_8 * 2) = param_2;
  return;
}


// SV_AddToFatPAS  @ 000a53a4
void SV_AddToFatPAS(float *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int local_8;
  
  while (-1 < *param_2) {
    pfVar1 = (float *)param_2[6];
    fVar2 = (param_1[2] * pfVar1[2] + param_1[1] * pfVar1[1] + *param_1 * *pfVar1) - pfVar1[3];
    if ((byte)(8.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 8.0) << 0xe) >> 8)) == 1) {
      param_2 = (int *)param_2[7];
    }
    else if (-8.0 <= fVar2) {
      SV_AddToFatPAS(param_1,param_2[7]);
      param_2 = (int *)param_2[8];
    }
    else {
      param_2 = (int *)param_2[8];
    }
  }
  if (*param_2 != -2) {
    iVar3 = CM_LeafPAS(((int)param_2 - *(int *)(DAT_0036bd88 + 0x8c)) * -0x55555555 >> 4);
    for (local_8 = 0; local_8 < fatpasbytes; local_8 = local_8 + 1) {
      fatpas[local_8] = fatpas[local_8] | *(byte *)(iVar3 + local_8);
    }
  }
  return;
}


// SV_AddToFatPVS  @ 000a51bc
void SV_AddToFatPVS(float *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int local_8;
  
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
    iVar3 = Mod_LeafPVS(param_2,DAT_0036bd88);
    for (local_8 = 0; local_8 < fatbytes; local_8 = local_8 + 1) {
      fatpvs[local_8] = fatpvs[local_8] | *(byte *)(iVar3 + local_8);
    }
  }
  return;
}


// SV_AddToResourceList  @ 000b5b8c
void SV_AddToResourceList(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0x84) == 0) && (*(int *)(param_1 + 0x80) == 0)) {
    *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_2 + 0x84);
    *(int *)(*(int *)(param_2 + 0x84) + 0x80) = param_1;
    *(int *)(param_2 + 0x84) = param_1;
    *(int *)(param_1 + 0x80) = param_2;
  }
  else {
    Con_Printf("Resource already linked\n");
  }
  return;
}


// SV_AllocClientFrames  @ 0009b900
void SV_AllocClientFrames(void)

{
  undefined4 uVar1;
  int local_c;
  int local_8;
  
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_0052428c; local_8 = local_8 + 1) {
    if (*(int *)(local_c + 0x3480) != 0) {
      Con_DPrintf("Allocating over frame pointer?\n");
    }
    uVar1 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1810);
    *(undefined4 *)(local_c + 0x3480) = uVar1;
    local_c = local_c + 0x4eec;
  }
  return;
}


// SV_AllocPacketEntities  @ 0009ba34
void SV_AllocPacketEntities(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x180c) != 0) {
      SV_ClearPacketEntities(param_1);
    }
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 1;
    }
    uVar2 = Mem_ZeroMalloc(iVar1 * 0x154);
    *(undefined4 *)(param_1 + 0x180c) = uVar2;
    *(int *)(param_1 + 0x17e8) = param_2;
  }
  return;
}


// SV_BanId_f  @ 000aa678
void SV_BanId_f(void)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  longdouble lVar10;
  undefined8 uVar11;
  char *pcVar12;
  size_t sVar13;
  int *local_170;
  int *local_16c;
  int *local_168;
  char local_154 [63];
  undefined1 local_115;
  char local_114 [256];
  char *local_14;
  int *local_10;
  float local_c;
  int local_8;
  
  local_10 = (int *)0x0;
  iVar3 = Cmd_Argc();
  if ((iVar3 < 3) || (iVar3 = Cmd_Argc(), 6 < iVar3)) {
    Con_Printf();
    Con_Printf();
    return;
  }
  uVar4 = Cmd_Argv(1);
  uVar11 = CONCAT44(uVar4,0xaa704);
  lVar10 = (longdouble)Q_atof();
  local_c = (float)lVar10;
  if (local_c < 0.01) {
    local_c = 0.0;
  }
  sVar13 = 0x3f;
  uVar4 = 2;
  pcVar5 = (char *)Cmd_Argv(2,uVar11);
  strncpy(local_154,pcVar5,sVar13);
  local_115 = 0;
  bVar2 = false;
  iVar3 = Cmd_Argc();
  if (3 < iVar3) {
    pcVar5 = &DAT_000ea655;
    iVar3 = Cmd_Argc();
    Cmd_Argv(iVar3 + -1);
    iVar3 = Q_strcasecmp();
    if (iVar3 == 0) {
      bVar2 = true;
    }
  }
  if (local_154[0] == '#') {
    uVar11 = CONCAT44(local_154,0xaa7c0);
    iVar3 = Q_strlen();
    if (iVar3 == 1) {
      iVar3 = Cmd_Argc();
      if (iVar3 < 3) {
        Con_Printf();
        return;
      }
      Cmd_Argv(3,uVar4,uVar11);
      local_16c = (int *)Q_atoi();
    }
    else {
      local_16c = (int *)Q_atoi();
    }
    local_168 = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if ((((*local_168 != 0) || (local_168[3] != 0)) || (local_168[1] != 0)) &&
         ((local_168[0x90e] == 0 && ((int *)local_168[0x12a3] == local_16c)))) {
        local_10 = local_168 + 0x12a4;
        break;
      }
      local_168 = local_168 + 0x13bb;
    }
    if (local_10 == (int *)0x0) {
      Con_Printf();
      return;
    }
    goto LAB_000aaaf4;
  }
  sVar13 = strlen("STEAM_");
  pcVar5 = "STEAM_";
  iVar3 = Q_strnicmp();
  if (iVar3 == 0) {
LAB_000aa984:
    uVar4 = Cmd_Argv(4);
    uVar6 = Cmd_Argv(2);
    snprintf(local_154,0x3f,"%s:%s",uVar6,uVar4,pcVar5,sVar13);
    local_115 = 0;
  }
  else {
    sVar13 = strlen("VALVE_");
    pcVar5 = "VALVE_";
    iVar3 = Q_strnicmp();
    if (iVar3 == 0) goto LAB_000aa984;
  }
  local_16c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if ((((*local_16c != 0) || (local_16c[3] != 0)) || (local_16c[1] != 0)) &&
       (local_16c[0x90e] == 0)) {
      pcVar5 = local_154;
      SV_GetClientIDString(local_16c);
      iVar3 = Q_stricmp();
      if (iVar3 == 0) {
        local_10 = local_16c + 0x12a4;
        break;
      }
    }
    local_16c = local_16c + 0x13bb;
  }
  if ((local_10 == (int *)0x0) && (local_10 = (int *)SV_StringToUserID(), local_10 == (int *)0x0)) {
    Con_Printf();
    Con_Printf();
    Con_Printf();
    return;
  }
LAB_000aaaf4:
  if (local_10 == (int *)0x0) {
    Con_Printf();
    iVar3 = (int)host_client;
  }
  else {
    local_8 = 0;
    while ((local_8 < numuserfilters &&
           (pcVar5 = (char *)local_10, iVar3 = SV_CompareUserID(), iVar3 == 0))) {
      local_8 = local_8 + 1;
    }
    if (numuserfilters <= local_8) {
      if (0x7fff < numuserfilters) {
        Con_Printf();
        return;
      }
      numuserfilters = numuserfilters + 1;
    }
    *(float *)(userfilters + local_8 * 0x1c + 0x18) = local_c;
    if ((byte)(0.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = local_c * 60.0 + (float)realtime;
    }
    *(float *)(userfilters + local_8 * 0x1c + 0x14) = fVar1;
    piVar8 = local_10;
    piVar9 = (int *)(userfilters + local_8 * 0x1c);
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar9 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar9 = piVar9 + 1;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 0x40) {
      sprintf(local_114,"permanently");
    }
    else {
      snprintf(local_114,0x100,"for %.2f minutes",(double)local_c,pcVar5);
    }
    iVar3 = (int)host_client;
    if (cmd_source == 1) {
      local_14 = "Console";
    }
    else {
      local_14 = (char *)((int)host_client + 0x4bec);
    }
    if (bVar2) {
      local_170 = DAT_00524284;
      for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
        if ((((*local_170 != 0) || (local_170[3] != 0)) || (local_170[1] != 0)) &&
           ((local_170[0x90e] == 0 && (iVar7 = SV_CompareUserID(), iVar7 != 0)))) {
          host_client = local_170;
          if ((byte)(0.0 < (float)sv_logbans._12_4_ |
                     (byte)((ushort)((ushort)NAN((float)sv_logbans._12_4_) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)sv_logbans._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
             ) {
            pcVar5 = local_114;
            pcVar12 = local_14;
            uVar4 = SV_GetClientIDString(local_170);
            Log_Printf("Ban: \"%s<%i><%s><>\" was kicked and banned \"%s\" by \"%s\"\n",
                       host_client + 0x12fb,host_client[0x12a3],uVar4,pcVar5,pcVar12);
          }
          SV_ClientPrintf();
          SV_DropClient();
          host_client = (int *)iVar3;
          return;
        }
        local_170 = local_170 + 0x13bb;
      }
    }
    else if ((byte)(0.0 < (float)sv_logbans._12_4_ |
                    (byte)((ushort)((ushort)NAN((float)sv_logbans._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)sv_logbans._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
    {
      SV_GetIDString(local_10);
      Log_Printf();
      iVar3 = (int)host_client;
    }
  }
  host_client = (int *)iVar3;
  return;
}


// SV_BatchUploadRequest  @ 000b5ec4
void SV_BatchUploadRequest(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_110 [260];
  int local_c;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x4d20);
  while (local_8 != param_1 + 0x4ca0) {
    local_c = *(int *)(local_8 + 0x80);
    if ((*(byte *)(local_8 + 0x4c) & 2) == 0) {
      SV_MoveToOnHandList(local_8);
    }
    else if (*(int *)(local_8 + 0x40) == 3) {
      if ((*(byte *)(local_8 + 0x4c) & 4) == 0) {
        Con_Printf("Non customization in upload queue!\n");
        SV_MoveToOnHandList(local_8);
      }
      else {
        uVar1 = MD5_Print(local_8 + 0x4d);
        snprintf(local_110,0x104,"!MD5%s",uVar1);
        iVar2 = SV_CheckFile(param_1 + 0x74,local_110);
        if (iVar2 != 0) {
          SV_MoveToOnHandList(local_8);
        }
      }
    }
    local_8 = local_c;
  }
  return;
}


// SV_BeginFileDownload_f  @ 000ac6e0
void SV_BeginFileDownload_f(void)

{
  int iVar1;
  int local_bc;
  int local_b8;
  undefined1 local_b4 [136];
  undefined1 local_2c [16];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  char *local_8;
  
  local_1c = 0x21;
  local_1b = 0x4d;
  local_1a = 0x6f;
  local_19 = 100;
  local_18 = 0x75;
  local_17 = 0x6c;
  local_16 = 0x65;
  local_15 = 0x43;
  local_14 = 0x2e;
  local_13 = 100;
  local_12 = 0x6c;
  local_11 = 0x6c;
  local_10 = 0;
  iVar1 = Cmd_Argc();
  if ((((1 < iVar1) && (cmd_source != 1)) && (local_8 = (char *)Cmd_Argv(1), local_8 != (char *)0x0)
      ) && (*local_8 != '\0')) {
    iVar1 = Q_strncmp(local_8,&local_1c,0xc);
    if ((iVar1 == 0) && (DAT_00524368 != 0)) {
      Netchan_CreateFileFragmentsFromBuffer(1,host_client + 0x1c,local_8,DAT_00524318,DAT_0052431c);
      Netchan_FragSend(host_client + 0x1c);
    }
    else {
      iVar1 = Q_strstr(local_8,&DAT_000ea0c4);
      if ((iVar1 == 0) &&
         ((byte)(0.0 < (float)sv_allow_download._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)sv_allow_download._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_allow_download._12_4_ == 0.0) << 0xe) >> 8)) !=
          0x40)) {
        if (*local_8 == '!') {
          iVar1 = Q_strlen(local_8);
          if ((iVar1 == 0x24) && (iVar1 = Q_strnicmp(local_8,&DAT_000eb024,4), iVar1 == 0)) {
            local_b8 = 0;
            local_bc = 0;
            if ((byte)((byte)((ushort)((ushort)NAN((float)sv_send_logos._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)sv_send_logos._12_4_ == 0.0) << 0xe) >> 8)) ==
                0x40) {
              SV_FailDownload(local_8);
            }
            else {
              Q_memset(local_b4,0,0x88);
              COM_HexConvert(local_8 + 4,0x20,local_2c);
              iVar1 = HPAK_ResourceForHash("custom.hpk",local_2c,local_b4);
              if (((iVar1 != 0) &&
                  (HPAK_GetDataPointer("custom.hpk",local_b4,&local_b8,&local_bc), local_b8 != 0))
                 && (local_bc != 0)) {
                Netchan_CreateFileFragmentsFromBuffer
                          (1,host_client + 0x1c,local_8,local_b8,local_bc);
                Netchan_FragSend(host_client + 0x1c);
                Mem_Free(local_b8);
              }
            }
          }
          else {
            SV_FailDownload(local_8);
          }
        }
        else if (((byte)(0.0 < (float)sv_send_resources._12_4_ |
                         (byte)((ushort)((ushort)NAN((float)sv_send_resources._12_4_) << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)sv_send_resources._12_4_ == 0.0) << 0xe) >>
                              8)) == 0x40) ||
                (iVar1 = Netchan_CreateFileFragments(1,host_client + 0x1c,local_8), iVar1 == 0)) {
          SV_FailDownload(local_8);
        }
        else {
          Netchan_FragSend(host_client + 0x1c);
        }
      }
      else {
        SV_FailDownload(local_8);
      }
    }
  }
  return;
}


// SV_BeginRedirect  @ 000a31a4
void SV_BeginRedirect(undefined4 param_1,undefined4 *param_2)

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


// SV_BroadcastCommand  @ 000a8ce4
void SV_BroadcastCommand(char *param_1)

{
  int *local_4a4;
  int local_4a0;
  char *local_49c;
  uint local_498;
  undefined1 *local_494;
  undefined4 local_490;
  undefined4 local_48c;
  undefined1 local_488 [128];
  char local_408 [1024];
  undefined1 *local_8;
  
  local_49c = "Broadcast Command";
  local_494 = local_488;
  local_48c = 0;
  local_490 = 0x80;
  local_498 = CONCAT22(local_498._2_2_,1);
  if (sv == 0) {
    FUN_000a8e70();
    return;
  }
  local_8 = &stack0x00000008;
  vsnprintf(local_408,0x400,param_1,local_8);
  MSG_WriteByte(&local_49c,9);
  MSG_WriteString(&local_49c,local_408);
  if ((local_498 & 2) == 0) {
    local_4a4 = DAT_00524284;
    for (local_4a0 = 0; local_4a0 < DAT_00524288; local_4a0 = local_4a0 + 1) {
      if ((((*local_4a4 != 0) || (local_4a4[3] != 0)) || (local_4a4[1] != 0)) &&
         (local_4a4[0x90e] == 0)) {
        SZ_Write(local_4a4 + 0x1d,local_494,local_48c);
      }
      local_4a4 = local_4a4 + 0x13bb;
    }
    FUN_000a8e70();
    return;
  }
  Sys_Error("SV_BroadcastCommand:  Overflowed on %s, %i is max size\n",local_408,local_490);
  FUN_000a8e70();
  return;
}


// SV_BroadcastPrintf  @ 0006a710
void SV_BroadcastPrintf(char *param_1)

{
  int local_40c;
  char local_408 [1024];
  undefined1 *local_8;
  
  local_8 = &stack0x00000008;
  vsnprintf(local_408,0x400,param_1,local_8);
  for (local_40c = 0; local_40c < DAT_00524288; local_40c = local_40c + 1) {
    if (((*(int *)(DAT_00524284 + local_40c * 0x4eec) != 0) ||
        (*(int *)(DAT_00524284 + 4 + local_40c * 0x4eec) != 0)) &&
       (*(int *)(DAT_00524284 + 0x2438 + local_40c * 0x4eec) == 0)) {
      MSG_WriteByte(DAT_00524284 + local_40c * 0x4eec + 0x74,8);
      MSG_WriteString(DAT_00524284 + local_40c * 0x4eec + 0x74,local_408);
    }
  }
  Con_DPrintf(&DAT_000e2b83,local_408);
  return;
}


// SV_BuildHashedSoundLookupTable  @ 0009ca38
void SV_BuildHashedSoundLookupTable(void)

{
  int local_8;
  
  Q_memset(&DAT_0039e7a8,0,0x7fe);
  for (local_8 = 0; (local_8 < 0x200 && ((&DAT_0039dfa8)[local_8] != 0)); local_8 = local_8 + 1) {
    SV_AddSampleToHashedLookupTable((&DAT_0039dfa8)[local_8],local_8);
  }
  DAT_0039efa8 = 1;
  return;
}


// SV_BuildReconnect  @ 000a8e7c
void SV_BuildReconnect(undefined4 param_1)

{
  MSG_WriteByte(param_1,9);
  MSG_WriteString(param_1,"reconnect\n");
  return;
}


// SV_BuildSoundMsg  @ 0009c4f8
undefined4
SV_BuildSoundMsg(undefined4 param_1,int param_2,char *param_3,int param_4,float param_5,uint param_6
                ,int param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  uint local_c;
  int local_8;
  
  if ((param_4 < 0) || (0xff < param_4)) {
    Sys_Error("SV_StartSound: volume = %i",param_4);
  }
  if ((param_5 < 0.0) ||
     ((byte)(4.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 4.0) << 0xe) >> 8)) == 1)) {
    Sys_Error("SV_StartSound: attenuation = %f",(double)param_5);
  }
  if ((param_2 < 0) || (7 < param_2)) {
    Sys_Error("SV_StartSound: channel = %i",param_2);
  }
  if ((param_7 < 0) || (0xff < param_7)) {
    Sys_Error("SV_StartSound: pitch = %i",param_7);
  }
  if ((param_3 == (char *)0x0) || (*param_3 != '!')) {
    if ((param_3 == (char *)0x0) || (*param_3 != '#')) {
      local_8 = SV_LookupSoundIndex(param_3);
      if ((local_8 == 0) || ((&DAT_0039dfa8)[local_8] == 0)) {
        Con_Printf("SV_StartSound: %s not precached (%d)\n",param_3,local_8);
        return 0;
      }
    }
    else {
      param_6 = param_6 | 0x10;
      local_8 = Q_atoi(param_3 + 1);
      local_8 = local_8 + 0x600;
    }
  }
  else {
    param_6 = param_6 | 0x10;
    local_8 = Q_atoi(param_3 + 1);
    if (0x5ff < local_8) {
      Con_Printf("invalid sentence number: %s",param_3 + 1);
      return 0;
    }
  }
  uVar1 = NUM_FOR_EDICT(param_1);
  local_c = param_6;
  if (param_4 != 0xff) {
    local_c = param_6 | 1;
  }
  if ((byte)(1.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 1.0) << 0xe) >> 8)) != 0x40) {
    local_c = local_c | 2;
  }
  if (param_7 != 100) {
    local_c = local_c | 8;
  }
  if (0xff < local_8) {
    local_c = local_c | 4;
  }
  MSG_WriteByte(param_9,6);
  MSG_StartBitWriting(param_9);
  MSG_WriteBits(local_c,9);
  if ((local_c & 1) != 0) {
    MSG_WriteBits(param_4,8);
  }
  if ((local_c & 2) != 0) {
    MSG_WriteBits((int)ROUND(param_5 * 64.0),8);
  }
  MSG_WriteBits(param_2,3);
  MSG_WriteBits(uVar1,0xb);
  if (local_8 < 0x100) {
    MSG_WriteBits(local_8,8);
  }
  else {
    MSG_WriteBits(local_8,0x10);
  }
  MSG_WriteBitVec3Coord(param_8);
  if ((local_c & 8) != 0) {
    MSG_WriteBits(param_7,8);
  }
  MSG_EndBitWriting(param_9);
  return 1;
}


// SV_CalcClientTime  @ 000b9724
longdouble SV_CalcClientTime(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float local_18;
  float local_14;
  int local_10;
  int local_c;
  float local_8;
  
  local_8 = 0.0;
  local_10 = 0;
  iVar2 = (int)ROUND((float)sv_unlagsamples._12_4_);
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  if (0x10 < iVar2) {
    iVar2 = 0x10;
  }
  iVar3 = SV_UPDATE_BACKUP;
  if (iVar2 < SV_UPDATE_BACKUP) {
    iVar3 = iVar2;
  }
  for (local_c = 0; local_c < iVar3; local_c = local_c + 1) {
    iVar2 = *(int *)(param_1 + 0x3480) +
            (*(int *)(param_1 + 0x54) - local_c & SV_UPDATE_MASK) * 0x1810;
    fVar1 = *(float *)(iVar2 + 8);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      local_8 = local_8 + *(float *)(iVar2 + 8);
      local_10 = local_10 + 1;
    }
  }
  if (local_10 == 0) {
    lVar4 = (longdouble)0;
  }
  else {
    local_14 = 9999.0;
    local_18 = -9999.0;
    local_c = 0;
    while( true ) {
      iVar2 = SV_UPDATE_BACKUP;
      if (4 < SV_UPDATE_BACKUP) {
        iVar2 = 4;
      }
      if (iVar2 <= local_c) break;
      iVar2 = *(int *)(param_1 + 0x3480) +
              (*(int *)(param_1 + 0x54) - local_c & SV_UPDATE_MASK) * 0x1810;
      fVar1 = *(float *)(iVar2 + 8);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        fVar1 = *(float *)(iVar2 + 8);
        if ((byte)(fVar1 < local_14 |
                   (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_14)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == local_14) << 0xe) >> 8)) == 1) {
          local_14 = *(float *)(iVar2 + 8);
        }
        if (local_18 < *(float *)(iVar2 + 8)) {
          local_18 = *(float *)(iVar2 + 8);
        }
      }
      local_c = local_c + 1;
    }
    if ((local_14 <= local_18) &&
       (fVar1 = ABS(local_18 - local_14),
       (byte)(0.2 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.2) << 0xe) >> 8)) == 1)) {
      return (longdouble)0;
    }
    lVar4 = (longdouble)(local_8 / (float)local_10);
  }
  return lVar4;
}


// SV_CalcPing  @ 000a4b78
int SV_CalcPing(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x2438) == 0) {
    local_8 = 0.0;
    local_10 = 0;
    iVar2 = SV_UPDATE_BACKUP / 2;
    if (0x10 < iVar2) {
      iVar2 = 0x10;
    }
    for (local_c = 0; local_c < iVar2; local_c = local_c + 1) {
      iVar3 = ((*(int *)(param_1 + 0x54) - local_c) - 1U & SV_UPDATE_MASK) * 0x1810 +
              *(int *)(param_1 + 0x3480);
      fVar1 = *(float *)(iVar3 + 8);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        local_8 = local_8 + *(float *)(iVar3 + 8);
        local_10 = local_10 + 1;
      }
    }
    if (local_10 == 0) {
      iVar2 = 0;
    }
    else {
      local_8 = local_8 / (float)local_10;
      if (local_8 < 0.0) {
        local_8 = 0.0;
      }
      iVar2 = (int)ROUND(local_8 * 1000.0);
    }
  }
  else {
    iVar2 = 5;
  }
  return iVar2;
}


// SV_CheckAllEnts  @ 000b0c94
void SV_CheckAllEnts(void)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  for (local_8 = 1; local_8 < DAT_003a78b0; local_8 = local_8 + 1) {
    piVar2 = (int *)(DAT_003a78b8 + local_8 * 0x324);
    if ((((*piVar2 == 0) && (piVar2[0x62] != 7)) && (piVar2[0x62] != 0)) &&
       (((piVar2[0x62] != 0xc && (piVar2[0x62] != 8)) &&
        (iVar1 = SV_TestEntityPosition(piVar2), iVar1 != 0)))) {
      Con_Printf("entity in invalid position\n");
    }
  }
  return;
}


// SV_CheckBlendingInterface  @ 00076270
void SV_CheckBlendingInterface(void)

{
  code *pcVar1;
  int iVar2;
  int local_8;
  
  R_ResetSvBlending();
  local_8 = 0;
  do {
    if (g_iextdllMac <= local_8) {
      return;
    }
    pcVar1 = (code *)dlsym((&g_rgextdll)[local_8 * 3],"Server_GetBlendingInterface");
    if (pcVar1 != (code *)0x0) {
      iVar2 = (*pcVar1)(1,&g_pSvBlendingAPI,server_studio_api,rotationmatrix,bonetransform);
      if (iVar2 != 0) {
        return;
      }
      Con_DPrintf("Couldn\'t get server .dll studio model blending interface. Version mismatch?\n");
      R_ResetSvBlending();
    }
    local_8 = local_8 + 1;
  } while( true );
}


// SV_CheckBottom  @ 000af1b8
undefined4 SV_CheckBottom(int param_1)

{
  float fVar1;
  int iVar2;
  uint *puVar3;
  int aiStackY_d4 [2];
  uint uStack_b0;
  uint local_80;
  float local_7c;
  int local_74;
  int local_70;
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
  
  uStack_b0 = 0xaf1c7;
  local_80 = (uint)((*(uint *)(param_1 + 0x224) & 0x800000) != 0);
  local_10 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x15c);
  local_c = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x160);
  local_8 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x164);
  local_1c = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x168);
  local_18 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x16c);
  local_14 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x170);
  local_20 = local_8 - 1.0;
  local_70 = 0;
  do {
    if (1 < local_70) {
      c_yes = c_yes + 1;
      return 1;
    }
    for (local_74 = 0; local_74 < 2; local_74 = local_74 + 1) {
      local_28 = local_10;
      if (local_70 != 0) {
        local_28 = local_1c;
      }
      local_24 = local_c;
      if (local_74 != 0) {
        local_24 = local_18;
      }
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      iVar2 = SV_PointContents(&local_28);
      if (iVar2 != -2) {
        c_no = c_no + 1;
        local_20 = local_8 + (float)sv_stepsize._12_4_;
        local_34 = (local_10 + local_1c) * 0.5;
        local_30 = (local_c + local_18) * 0.5;
        local_2c = local_20 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
        uStack_b0 = local_80;
        local_28 = local_34;
        local_24 = local_30;
        SV_Move(local_6c,&local_28,&vec3_origin,&vec3_origin,&local_34,1,param_1);
        fVar1 = local_50;
        puVar3 = &uStack_b0;
        if ((byte)((byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) == 0x40) {
          return 0;
        }
        local_7c = local_50;
        local_70 = 0;
        do {
          if (1 < local_70) {
            c_yes = c_yes + 1;
            return 1;
          }
          for (local_74 = 0; local_74 < 2; local_74 = local_74 + 1) {
            local_34 = local_10;
            if (local_70 != 0) {
              local_34 = local_1c;
            }
            local_30 = local_c;
            if (local_74 != 0) {
              local_30 = local_18;
            }
            *(uint *)((int)puVar3 + -4) = local_80;
            *(int *)((int)puVar3 + -8) = param_1;
            *(undefined4 *)((int)puVar3 + -0xc) = 1;
            *(float **)((int)puVar3 + -0x10) = &local_34;
            *(undefined4 **)((int)puVar3 + -0x14) = &vec3_origin;
            *(undefined4 **)((int)puVar3 + -0x18) = &vec3_origin;
            *(float **)((int)puVar3 + -0x1c) = &local_28;
            *(undefined1 **)((int)puVar3 + -0x20) = local_6c;
            *(undefined4 *)((int)puVar3 + -0x24) = 0xaf44e;
            local_28 = local_34;
            local_24 = local_30;
            SV_Move();
            puVar3 = (uint *)((int)puVar3 + -4);
            if (((byte)(1.0 < local_5c | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) != 0x40) &&
               (local_7c < local_50)) {
              local_7c = local_50;
            }
            if (((byte)(1.0 < local_5c | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) == 0x40) ||
               ((float)sv_stepsize._12_4_ < fVar1 - local_50)) {
              return 0;
            }
          }
          local_70 = local_70 + 1;
        } while( true );
      }
    }
    local_70 = local_70 + 1;
  } while( true );
}


// SV_CheckChallenge  @ 0009f8dc
undefined4 SV_CheckChallenge(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  char **ppcVar4;
  char *apcStack_4c [9];
  char *pcStack_28;
  undefined4 uStack_20;
  int local_8;
  
  uStack_20 = 0x9f8ea;
  if (param_1 == (undefined4 *)0x0) {
    apcStack_4c[8] = "SV_CheckChallenge:  Null address\n";
    apcStack_4c[7] = (char *)0x9f908;
    Sys_Error();
    uVar1 = 0;
  }
  else {
    puVar3 = param_1;
    ppcVar4 = apcStack_4c + 4;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar4 = (char *)*puVar3;
      puVar3 = puVar3 + 1;
      ppcVar4 = ppcVar4 + 1;
    }
    apcStack_4c[3] = (char *)0x9f92e;
    iVar2 = NET_IsLocalAddress();
    if (iVar2 == 0) {
      for (local_8 = 0; local_8 < 0x400; local_8 = local_8 + 1) {
        puVar3 = (undefined4 *)(g_rg_sv_challenges + local_8 * 0x1c);
        ppcVar4 = apcStack_4c + 5;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *ppcVar4 = (char *)*puVar3;
          puVar3 = puVar3 + 1;
          ppcVar4 = ppcVar4 + 1;
        }
        puVar3 = &net_from;
        ppcVar4 = apcStack_4c;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *ppcVar4 = (char *)*puVar3;
          puVar3 = puVar3 + 1;
          ppcVar4 = ppcVar4 + 1;
        }
        iVar2 = NET_CompareBaseAdr();
        if (iVar2 != 0) {
          if (param_2 != *(int *)(g_rg_sv_challenges + local_8 * 0x1c + 0x14)) {
            pcStack_28 = "Bad challenge.\n";
            apcStack_4c[8] = (char *)param_1;
            apcStack_4c[7] = (char *)0x9f9ed;
            SV_RejectConnection();
            return 0;
          }
          break;
        }
      }
      if (local_8 == 0x400) {
        pcStack_28 = "No challenge for your address.\n";
        apcStack_4c[8] = (char *)param_1;
        apcStack_4c[7] = (char *)0x9fa1a;
        SV_RejectConnection();
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// SV_CheckCmdTimes  @ 000acdc4
void SV_CheckCmdTimes(void)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int local_8;
  
  if (1.0 <= realtime - lastreset_435) {
    lastreset_435 = realtime;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      piVar3 = (int *)(DAT_00524284 + local_8 * 0x4eec);
      if ((piVar3[3] != 0) && (*piVar3 != 0)) {
        if ((byte)((byte)((ushort)((ushort)NAN(*(double *)(piVar3 + 0x91d)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(double *)(piVar3 + 0x91d) == 0.0) << 0xe) >> 8)) ==
            0x40) {
          *(double *)(piVar3 + 0x91d) = realtime;
        }
        fVar1 = (float)(((longdouble)*(double *)(piVar3 + 0x91f) +
                        (longdouble)*(double *)(piVar3 + 0x91d)) - (longdouble)realtime);
        if (fVar1 <= (float)clockwindow._12_4_) {
          fVar2 = -(float)clockwindow._12_4_;
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
            *(double *)(piVar3 + 0x91f) = realtime - *(double *)(piVar3 + 0x91d);
          }
        }
        else {
          *(double *)(piVar3 + 0x921) = (double)((float)realtime + (float)clockwindow._12_4_);
          *(double *)(piVar3 + 0x91f) = realtime - *(double *)(piVar3 + 0x91d);
        }
      }
    }
  }
  return;
}


// SV_CheckFile  @ 000b5544
bool SV_CheckFile(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined1 local_8c [77];
  undefined1 local_3f [59];
  
  Q_memset(local_8c,0,0x88);
  iVar1 = Q_strlen(param_2);
  if ((iVar1 == 0x24) && (iVar1 = Q_strnicmp(param_2,&DAT_000ebc96,4), iVar1 == 0)) {
    COM_HexConvert(param_2 + 4,0x20,local_3f);
    iVar1 = HPAK_GetDataPointer("custom.hpk",local_8c,0,0);
    if (iVar1 != 0) {
      return true;
    }
  }
  bVar3 = (byte)((byte)((ushort)((ushort)NAN((float)sv_allow_upload._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_allow_upload._12_4_ == 0.0) << 0xe) >> 8)) !=
          0x40;
  if (bVar3) {
    MSG_WriteByte(param_1,9);
    uVar2 = MD5_Print(local_3f);
    uVar2 = va("upload \"!MD5%s\"\n",uVar2);
    MSG_WriteString(param_1,uVar2);
  }
  return !bVar3;
}


// SV_CheckForDuplicateNames  @ 000a02cc
undefined4 SV_CheckForDuplicateNames(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_3c;
  int local_38;
  char *local_34;
  char *local_30;
  int local_2c;
  int local_28;
  char local_24 [32];
  
  local_38 = 1;
  local_3c = 0;
  local_30 = (char *)Info_ValueForKey(param_1,&DAT_000e9470);
  while( true ) {
    local_28 = 0;
    local_2c = DAT_00524284;
    while ((local_28 < 0x20 &&
           ((((param_2 != 0 && (local_28 == param_3)) || (*(int *)(local_2c + 0xc) == 0)) ||
            (iVar1 = Q_stricmp(local_2c + 0x4bec,local_30), iVar1 != 0))))) {
      local_28 = local_28 + 1;
      local_2c = local_2c + 0x4eec;
    }
    if (0x1f < local_28) break;
    local_34 = local_30;
    if (*local_30 == '(') {
      if (local_30[2] == ')') {
        local_34 = local_30 + 3;
      }
      else if (local_30[3] == ')') {
        local_34 = local_30 + 4;
      }
    }
    snprintf(local_24,0x20,"(%d)%-0.*s",local_38,0x1c,local_34);
    Info_SetValueForKey(param_1,&DAT_000e9470,local_24,0x100);
    local_30 = (char *)Info_ValueForKey(param_1,&DAT_000e9470);
    local_3c = 1;
    local_38 = local_38 + 1;
  }
  return local_3c;
}


// SV_CheckForDuplicateSteamID  @ 000a00f4
int SV_CheckForDuplicateSteamID(int param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00524288 <= local_c) {
      return -1;
    }
    iVar1 = DAT_00524284 + local_c * 0x4eec;
    if ((((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 0x2438) == 0)) &&
        ((*(int *)(iVar1 + 0x4a90) == 1 || (*(int *)(iVar1 + 0x4a90) == 2)))) &&
       ((param_1 != iVar1 && (iVar1 = SV_CompareUserID(param_1 + 0x4a90,iVar1 + 0x4a90), iVar1 != 0)
        ))) break;
    local_c = local_c + 1;
  }
  return local_c;
}


// SV_CheckForDuplicateWonID  @ 000a01f8
int SV_CheckForDuplicateWonID(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00524288 <= local_c) {
      return -1;
    }
    iVar1 = DAT_00524284 + local_c * 0x4eec;
    if ((((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 0x2438) == 0)) &&
        (*(int *)(iVar1 + 0x4a90) == 0)) && (*(int *)(iVar1 + 0x4a94) == param_3)) break;
    local_c = local_c + 1;
  }
  return local_c;
}


// SV_CheckForRcon  @ 000acf54
void SV_CheckForRcon(void)

{
  int iVar1;
  
  if ((((sv == 0) && (cls == 0)) && (giActive != 3)) && (host_initialized != 0)) {
    while (iVar1 = NET_GetPacket(1), iVar1 != 0) {
      iVar1 = SV_FilterPacket();
      if (iVar1 == 0) {
        if (*DAT_0059d8c8 == -1) {
          SV_HandleRconPacket();
        }
      }
      else {
        SV_SendBan();
      }
    }
  }
  return;
}


// SV_CheckIPRestrictions  @ 0009fa38
undefined4 SV_CheckIPRestrictions(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int aiStack_4c [8];
  int *piStack_2c;
  char *pcStack_28;
  undefined4 uStack_20;
  
  uStack_20 = 0x9fa46;
  if (param_1 == (int *)0x0) {
    piStack_2c = (int *)0xe9160;
    aiStack_4c[7] = 0x9fa64;
    Sys_Error();
    uVar1 = 0;
  }
  else {
    if ((param_2 == 0) &&
       (((gfUseLANAuthentication != 0 ||
         ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
        (*param_1 == 3)))) {
      puVar3 = &net_local_adr;
      piVar4 = aiStack_4c + 5;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      piVar4 = param_1;
      piVar5 = aiStack_4c;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      iVar2 = NET_CompareClassBAdr();
      if (iVar2 == 0) {
        piVar4 = param_1;
        piVar5 = aiStack_4c + 4;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
        aiStack_4c[3] = 0x9fafe;
        iVar2 = NET_IsReservedAdr();
        if (iVar2 == 0) {
          pcStack_28 = "LAN servers are restricted to local clients (class C).\n";
          piStack_2c = param_1;
          aiStack_4c[7] = 0x9fb1c;
          SV_RejectConnection();
          return 0;
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


// SV_CheckKeyInfo  @ 0009fe90
undefined4
SV_CheckKeyInfo(undefined4 param_1,undefined4 param_2,undefined2 *param_3,int *param_4,int *param_5,
               undefined4 param_6,char *param_7)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  int local_1c;
  int local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  local_8 = Info_ValueForKey(param_2,&DAT_000e93ea);
  local_c = Q_atoi(local_8);
  if ((local_c < 1) || (4 < local_c)) {
    SV_RejectConnection(param_1,"Invalid connection.\n");
    uVar3 = 0;
  }
  else {
    local_8 = Info_ValueForKey(param_2,"unique");
    iVar2 = Q_strlen(local_8);
    if (iVar2 < 1) {
      uVar3 = 0;
    }
    else {
      iVar2 = Q_atoi(local_8);
      *param_5 = iVar2;
      if (*param_5 != -1) {
        local_20 = 0;
        local_1c = *param_5;
        iVar2 = SV_FilterUser(&local_20);
        if (iVar2 != 0) {
          SV_RejectConnection(param_1,"You have been banned from this server.\n");
          return 0;
        }
      }
      local_8 = Info_ValueForKey(param_2,&DAT_000e940b);
      iVar2 = Q_strlen(local_8);
      if ((iVar2 < 1) || ((local_c == 2 && (iVar2 = Q_strlen(local_8), iVar2 != 0x20)))) {
        SV_RejectConnection(param_1,"Invalid authentication certificate length.\n");
        uVar3 = 0;
      }
      else {
        Q_strcpy(param_6,local_8);
        if (local_c == 2) {
          snprintf(param_7,0x40,"%s",local_8);
        }
        else {
          local_8 = Info_ValueForKey(param_2,"cdkey");
          iVar2 = Q_strlen(local_8);
          if (iVar2 != 0x20) {
            SV_RejectConnection(param_1,"Invalid hashed CD key.\n");
            return 0;
          }
          snprintf(param_7,0x40,"%s",local_8);
        }
        uVar1 = Q_atoi("27005");
        *param_3 = uVar1;
        *param_4 = local_c;
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}


// SV_CheckMapDifferences  @ 000ad050
void SV_CheckMapDifferences(void)

{
  int local_c;
  int *local_8;
  
  if (5.0 <= realtime - lastcheck_445) {
    lastcheck_445 = realtime;
    local_8 = DAT_00524284;
    for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
      if ((((*local_8 != 0) && (local_8[0x1375] != 0)) && (local_8[8] != 1)) &&
         (local_8[0x1375] != DAT_0036bd8c)) {
        *(ushort *)(local_8 + 0x1e) = *(ushort *)(local_8 + 0x1e) | 2;
      }
      local_8 = local_8 + 0x13bb;
    }
  }
  return;
}


// SV_CheckMovingGround  @ 000b7cd0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_CheckMovingGround(int param_1,float param_2)

{
  int iVar1;
  
  if ((((*(uint *)(param_1 + 0x224) & 0x200) != 0) &&
      (iVar1 = *(int *)(param_1 + 0x21c), iVar1 != 0)) && ((*(uint *)(iVar1 + 0x224) & 4) != 0)) {
    if ((*(uint *)(param_1 + 0x224) & 0x400000) == 0) {
      VectorScale(iVar1 + 0xc4,*(undefined4 *)(iVar1 + 0x278),param_1 + 0xac);
    }
    else {
      VectorMA(param_1 + 0xac,*(undefined4 *)(iVar1 + 0x278),iVar1 + 0xc4,param_1 + 0xac);
    }
    *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) | 0x400000;
  }
  if ((*(uint *)(param_1 + 0x224) & 0x400000) == 0) {
    VectorMA(param_1 + 0xa0,(float)_FUN_000ec2e0 * param_2 + 1.0,param_1 + 0xac,param_1 + 0xa0);
    *(undefined4 *)(param_1 + 0xac) = 0;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xffbfffff;
  return;
}


// SV_CheckProtocol  @ 0009f818
undefined4 SV_CheckProtocol(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    Sys_Error("SV_CheckProtocol:  Null address\n");
    uVar1 = 0;
  }
  else if (param_2 == 0x2e) {
    uVar1 = 1;
  }
  else {
    if (param_2 < 0x2f) {
      SV_RejectConnection(param_1,
                          "This server is using a newer protocol ( %i ) than your client ( %i ).  You should check for updates to your client\n"
                          ,0x2e,param_2);
    }
    else {
      iVar2 = Q_strlen(sv_contact._4_4_);
      pcVar3 = (char *)sv_contact._4_4_;
      if (iVar2 < 1) {
        pcVar3 = "(no email address specified)";
      }
      SV_RejectConnection(param_1,
                          "This server is using an older protocol ( %i ) than your client ( %i ).  If you believe this server is outdated, you can contact the server administrator at %s\n"
                          ,0x2e,param_2,pcVar3);
    }
    uVar1 = 0;
  }
  return uVar1;
}


// SV_CheckRate  @ 000a42ec
void SV_CheckRate(int param_1)

{
  float fVar1;
  
  if (((byte)(0.0 < (float)sv_maxrate._12_4_ |
              (byte)((ushort)((ushort)NAN((float)sv_maxrate._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_maxrate._12_4_ == 0.0) << 0xe) >> 8)) == 1) &&
     ((float)sv_maxrate._12_4_ < (float)*(double *)(param_1 + 0x40))) {
    fVar1 = (float)sv_maxrate._12_4_;
    if (20000.0 <= (float)sv_maxrate._12_4_) {
      fVar1 = 20000.0;
    }
    *(double *)(param_1 + 0x40) = (double)fVar1;
  }
  if (((byte)(0.0 < (float)sv_minrate._12_4_ |
              (byte)((ushort)((ushort)NAN((float)sv_minrate._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_minrate._12_4_ == 0.0) << 0xe) >> 8)) == 1) &&
     (fVar1 = (float)*(double *)(param_1 + 0x40),
     (byte)(fVar1 < (float)sv_minrate._12_4_ |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN((float)sv_minrate._12_4_)) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == (float)sv_minrate._12_4_) << 0xe) >> 8)) == 1)) {
    fVar1 = (float)sv_minrate._12_4_;
    if ((byte)(1000.0 < (float)sv_minrate._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_minrate._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_minrate._12_4_ == 1000.0) << 0xe) >> 8)) != 1) {
      fVar1 = 1000.0;
    }
    *(double *)(param_1 + 0x40) = (double)fVar1;
  }
  return;
}


// SV_CheckRconFailure  @ 000a3738
undefined4 SV_CheckRconFailure(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_5c [5];
  undefined4 auStack_48 [6];
  undefined4 uStack_30;
  int local_8;
  
  uStack_30 = 0xa3746;
  local_8 = 0;
  do {
    if (0x1f < local_8) {
      return 0;
    }
    iVar1 = local_8 * 0x74;
    if (*(int *)(g_rgRconFailures + iVar1) != 0) {
      puVar3 = (undefined4 *)(g_rgRconFailures + iVar1 + 8);
      puVar4 = auStack_48;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = param_1;
      puVar4 = auStack_5c;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = NET_CompareAdr();
      if ((iVar2 != 0) && (*(int *)(g_rgRconFailures + iVar1 + 4) != 0)) {
        return 1;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// SV_CheckSaveGameCommentInterface  @ 00076350
void SV_CheckSaveGameCommentInterface(void)

{
  undefined *puVar1;
  int local_8;
  
  local_8 = 0;
  while ((puVar1 = g_pSaveGameCommentFunc, local_8 < g_iextdllMac &&
         (puVar1 = (undefined *)dlsym((&g_rgextdll)[local_8 * 3],"SV_SaveGameComment"),
         puVar1 == (undefined *)0x0))) {
    local_8 = local_8 + 1;
  }
  g_pSaveGameCommentFunc = puVar1;
  return;
}


// SV_CheckTimeouts  @ 000a4a98
void SV_CheckTimeouts(void)

{
  float fVar1;
  float fVar2;
  int *local_c;
  int local_8;
  
  fVar2 = (float)realtime - (float)sv_timeout._12_4_;
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (((local_c[0x90e] == 0) && (((local_c[3] != 0 || (*local_c != 0)) || (local_c[1] != 0)))) &&
       (fVar1 = (float)local_c[0xe],
       (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1)) {
      SV_BroadcastPrintf("%s timed out\n",local_c + 0x12fb);
      SV_DropClient(local_c,0,"Timed out");
    }
    local_c = local_c + 0x13bb;
  }
  return;
}


// SV_CheckUpdateRate  @ 0009f23c
void SV_CheckUpdateRate(double *param_1)

{
  float fVar1;
  float fVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *param_1 = 0.05;
  }
  else {
    if (((float)sv_maxupdaterate._12_4_ <= 0.001) &&
       ((byte)(0.0 < (float)sv_maxupdaterate._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_maxupdaterate._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_maxupdaterate._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
       )) {
      Cvar_Set("sv_maxupdaterate",&DAT_000e870d);
    }
    if (((float)sv_minupdaterate._12_4_ <= 0.001) &&
       ((byte)(0.0 < (float)sv_minupdaterate._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_minupdaterate._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_minupdaterate._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
       )) {
      Cvar_Set("sv_minupdaterate",&DAT_000e8f65);
    }
    if ((byte)(0.0 < (float)sv_maxupdaterate._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_maxupdaterate._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_maxupdaterate._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
       ) {
      fVar1 = 1.0 / (float)sv_maxupdaterate._12_4_;
      fVar2 = (float)*param_1;
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
        *param_1 = (double)(1.0 / (float)sv_maxupdaterate._12_4_);
      }
    }
    if ((byte)(0.0 < (float)sv_minupdaterate._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_minupdaterate._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_minupdaterate._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
       ) {
      if (1.0 / (float)sv_minupdaterate._12_4_ < (float)*param_1) {
        *param_1 = (double)(1.0 / (float)sv_minupdaterate._12_4_);
      }
    }
  }
  return;
}


// SV_CheckUserInfo  @ 000a0434
undefined4
SV_CheckUserInfo(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  char *apcStack_74 [6];
  int *piStack_5c;
  char *pcStack_58;
  int iStack_54;
  undefined4 uStack_50;
  int local_30;
  char local_2c [31];
  undefined1 local_d;
  char *local_c;
  int local_8;
  
  uStack_50 = 0xa0442;
  puVar2 = param_1;
  ppcVar3 = apcStack_74 + 2;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar3 = (char *)*puVar2;
    puVar2 = puVar2 + 1;
    ppcVar3 = ppcVar3 + 1;
  }
  apcStack_74[1] = (char *)0xa0463;
  iVar1 = NET_IsLocalAddress();
  if ((iVar1 == 0) && (*(char *)sv_password._4_4_ != '\0')) {
    pcStack_58 = &DAT_000e9480;
    piStack_5c = (int *)sv_password._4_4_;
    apcStack_74[5] = (char *)0xa049d;
    iVar1 = Q_stricmp();
    if (iVar1 != 0) {
      apcStack_74[5] = "password";
      apcStack_74[4] = (char *)param_2;
      apcStack_74[3] = (char *)0xa04c2;
      pcStack_58 = (char *)Info_ValueForKey();
      piStack_5c = (int *)sv_password._4_4_;
      apcStack_74[5] = (char *)0xa04d7;
      iVar1 = Q_strcmp();
      if (iVar1 != 0) {
        puVar2 = param_1;
        ppcVar3 = apcStack_74;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *ppcVar3 = (char *)*puVar2;
          puVar2 = puVar2 + 1;
          ppcVar3 = ppcVar3 + 1;
        }
        pcStack_58 = (char *)NET_AdrToString();
        piStack_5c = (int *)0xe948e;
        apcStack_74[5] = (char *)0xa0511;
        Con_Printf();
        piStack_5c = param_1;
        apcStack_74[5] = (char *)0xa0520;
        SV_RejectConnectionForPassword();
        return 0;
      }
    }
  }
  pcStack_58 = "password";
  piStack_5c = (int *)param_2;
  apcStack_74[5] = (char *)0xa0541;
  Info_RemoveKey();
  pcStack_58 = &DAT_000e9470;
  piStack_5c = (int *)param_2;
  apcStack_74[5] = (char *)0xa0559;
  local_8 = Info_ValueForKey();
  if (local_8 == 0) {
    pcStack_58 = "unnamed";
    piStack_5c = (int *)local_2c;
    apcStack_74[5] = (char *)0xa0595;
    Q_strcpy();
  }
  else {
    iStack_54 = 0x20;
    piStack_5c = (int *)local_2c;
    apcStack_74[5] = (char *)0xa0577;
    pcStack_58 = (char *)local_8;
    Q_strncpy();
    local_d = 0;
  }
  for (local_c = local_2c; (local_c != (char *)0x0 && (*local_c != '\0')); local_c = local_c + 1) {
    if (*local_c == '%') {
      *local_c = ' ';
    }
  }
  pcStack_58 = (char *)param_5;
  piStack_5c = (int *)local_2c;
  apcStack_74[5] = (char *)0xa05d8;
  TrimSpace();
  uStack_50 = 0x100;
  iStack_54 = param_5;
  pcStack_58 = &DAT_000e9470;
  piStack_5c = (int *)param_2;
  apcStack_74[5] = (char *)0xa05f6;
  Info_SetValueForKey();
  iStack_54 = param_4;
  pcStack_58 = (char *)param_3;
  piStack_5c = (int *)param_2;
  apcStack_74[5] = (char *)0xa060d;
  iVar1 = SV_CheckForDuplicateNames();
  if (iVar1 != 0) {
    pcStack_58 = &DAT_000e9470;
    piStack_5c = (int *)param_2;
    apcStack_74[5] = (char *)0xa062b;
    pcStack_58 = (char *)Info_ValueForKey();
    iStack_54 = 0x20;
    piStack_5c = (int *)param_5;
    apcStack_74[5] = (char *)0xa0643;
    local_8 = (int)pcStack_58;
    Q_strncpy();
    *(undefined1 *)(param_5 + 0x1f) = 0;
  }
  pcStack_58 = "*hltv";
  piStack_5c = (int *)param_2;
  apcStack_74[5] = (char *)0xa0664;
  piStack_5c = (int *)Info_ValueForKey();
  if (piStack_5c != (int *)0x0) {
    apcStack_74[5] = (char *)0xa0680;
    local_8 = (int)piStack_5c;
    iVar1 = Q_atoi();
    if (iVar1 != 1) {
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          return 1;
        }
      }
      else if (iVar1 == 3) {
        pcStack_58 = "Please connect to HLTV master proxy.\n";
        piStack_5c = param_1;
        apcStack_74[5] = (char *)0xa070d;
        SV_RejectConnection();
        return 0;
      }
      pcStack_58 = "Unknown HLTV client type.\n";
      piStack_5c = param_1;
      apcStack_74[5] = (char *)0xa0729;
      SV_RejectConnection();
      return 0;
    }
    piStack_5c = &local_30;
    apcStack_74[5] = (char *)0xa06b4;
    SV_CountProxies();
    if (((float)sv_proxies._12_4_ <= (float)local_30) && (param_3 == 0)) {
      pcStack_58 = "Proxy slots are full.\n";
      piStack_5c = param_1;
      apcStack_74[5] = (char *)0xa06eb;
      SV_RejectConnection();
      return 0;
    }
  }
  return 1;
}


// SV_CheckVelocity  @ 000b0d7c
void SV_CheckVelocity(int param_1)

{
  float fVar1;
  float fVar2;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    if ((*(uint *)(local_8 * 4 + param_1 + 0xa0) & nanmask) == nanmask) {
      Con_Printf("Got a NaN velocity on %s\n",pr_strings + *(int *)(param_1 + 0x80));
      *(undefined4 *)(local_8 * 4 + param_1 + 0xa0) = 0;
    }
    if ((*(uint *)(local_8 * 4 + param_1 + 0x88) & nanmask) == nanmask) {
      Con_Printf("Got a NaN origin on %s\n",pr_strings + *(int *)(param_1 + 0x80));
      *(undefined4 *)(local_8 * 4 + param_1 + 0x88) = 0;
    }
    if (*(float *)(local_8 * 4 + param_1 + 0xa0) <= (float)sv_maxvelocity._12_4_) {
      fVar2 = -(float)sv_maxvelocity._12_4_;
      fVar1 = *(float *)(local_8 * 4 + param_1 + 0xa0);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        Con_DPrintf("Got a velocity too low on %s\n",pr_strings + *(int *)(param_1 + 0x80));
        *(float *)(local_8 * 4 + param_1 + 0xa0) = -(float)sv_maxvelocity._12_4_;
      }
    }
    else {
      Con_DPrintf("Got a velocity too high on %s\n",pr_strings + *(int *)(param_1 + 0x80));
      *(undefined4 *)(local_8 * 4 + param_1 + 0xa0) = sv_maxvelocity._12_4_;
    }
  }
  return;
}


// SV_CheckVisibility  @ 000a63ec
void SV_CheckVisibility(int param_1,int param_2)

{
  short sVar1;
  int local_8;
  
  if (param_2 == 0) {
    FUN_000a65ec();
    return;
  }
  if (*(int *)(param_1 + 0x10) < 0) {
    local_8 = 0;
    while ((local_8 < *(int *)(param_1 + 0x14) &&
           (((int)(uint)*(byte *)((*(short *)(local_8 * 2 + param_1 + 0x18) >> 3) + param_2) >>
             ((byte)*(undefined2 *)(local_8 * 2 + param_1 + 0x18) & 7) & 1U) == 0))) {
      local_8 = local_8 + 1;
    }
    if (local_8 < *(int *)(param_1 + 0x14)) {
      FUN_000a65ec();
      return;
    }
    FUN_000a65ec();
    return;
  }
  local_8 = 0;
  while( true ) {
    sVar1 = *(short *)(local_8 * 2 + param_1 + 0x18);
    if (sVar1 == -1) {
      FUN_000a6488();
      return;
    }
    if (((int)(uint)*(byte *)(((int)sVar1 >> 3) + param_2) >> ((byte)sVar1 & 7) & 1U) != 0) break;
    local_8 = local_8 + 1;
    if (0x2f < local_8) {
      FUN_000a6488();
      return;
    }
  }
  FUN_000a65ec();
  return;
}


// SV_CheckWater  @ 000b31f4
bool SV_CheckWater(int param_1)

{
  int iVar1;
  int iVar2;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
  local_c = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
  local_8 = *(float *)(param_1 + 0x14c) + 1.0;
  *(undefined4 *)(param_1 + 0x240) = 0;
  *(undefined4 *)(param_1 + 0x244) = 0xffffffff;
  g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
  iVar1 = SV_PointContents(&local_10);
  if ((iVar1 < -2) && (-0xf < iVar1)) {
    *(int *)(param_1 + 0x244) = iVar1;
    *(undefined4 *)(param_1 + 0x240) = 1;
    if ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(param_1 + 0x158)) ||
                                       NAN(*(float *)(param_1 + 0x14c))) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x158) == *(float *)(param_1 + 0x14c))
                             << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(param_1 + 0x240) = 3;
    }
    else {
      local_8 = (*(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x158)) * 0.5;
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      iVar2 = SV_PointContents(&local_10);
      if ((iVar2 < -2) && (-0xf < iVar2)) {
        *(undefined4 *)(param_1 + 0x240) = 2;
        local_10 = local_10 + *(float *)(param_1 + 500);
        local_c = local_c + *(float *)(param_1 + 0x1f8);
        local_8 = local_8 + *(float *)(param_1 + 0x1fc);
        g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
        iVar2 = SV_PointContents(&local_10);
        if ((iVar2 < -2) && (-0xf < iVar2)) {
          *(undefined4 *)(param_1 + 0x240) = 3;
        }
      }
    }
    if ((iVar1 < -8) && (-0xf < iVar1)) {
      VectorMA(param_1 + 0xac,(float)*(int *)(param_1 + 0x240) * 50.0,
               &current_table_42 + (-9 - iVar1) * 0xc,param_1 + 0xac);
    }
  }
  return 1 < *(int *)(param_1 + 0x240);
}


// SV_CheckWaterTransition  @ 000b38ac
void SV_CheckWaterTransition(int param_1)

{
  int iVar1;
  float local_14;
  float local_10;
  float local_c;
  int local_8;
  
  local_14 = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
  local_10 = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
  local_c = *(float *)(param_1 + 0x14c) + 1.0;
  g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
  local_8 = SV_PointContents(&local_14);
  if (*(int *)(param_1 + 0x244) == 0) {
    *(int *)(param_1 + 0x244) = local_8;
    *(undefined4 *)(param_1 + 0x240) = 1;
  }
  else if ((local_8 < -2) && (-0xf < local_8)) {
    if (*(int *)(param_1 + 0x244) == -1) {
      SV_StartSound(0,param_1,0,"player/pl_wade1.wav",0xff,0x3f800000,0,100);
      *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xa8) * 0.5;
    }
    *(int *)(param_1 + 0x244) = local_8;
    *(undefined4 *)(param_1 + 0x240) = 1;
    if ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(param_1 + 0x158)) ||
                                       NAN(*(float *)(param_1 + 0x14c))) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x158) == *(float *)(param_1 + 0x14c))
                             << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(param_1 + 0x240) = 3;
    }
    else {
      local_c = (*(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x158)) * 0.5;
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      local_8 = SV_PointContents(&local_14);
      if ((local_8 < -2) && (-0xf < local_8)) {
        *(undefined4 *)(param_1 + 0x240) = 2;
        local_14 = local_14 + *(float *)(param_1 + 500);
        local_10 = local_10 + *(float *)(param_1 + 0x1f8);
        local_c = local_c + *(float *)(param_1 + 0x1fc);
        g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
        iVar1 = SV_PointContents(&local_14);
        if ((iVar1 < -2) && (-0xf < iVar1)) {
          *(undefined4 *)(param_1 + 0x240) = 3;
        }
      }
    }
  }
  else {
    if (*(int *)(param_1 + 0x244) != -1) {
      SV_StartSound(0,param_1,0,"player/pl_wade2.wav",0xff,0x3f800000,0,100);
    }
    *(undefined4 *)(param_1 + 0x244) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x240) = 0;
  }
  return;
}


// SV_CleanupEnts  @ 000a6aa4
void SV_CleanupEnts(void)

{
  int iVar1;
  undefined4 local_8;
  
  for (local_8 = 1; local_8 < DAT_003a78b0; local_8 = local_8 + 1) {
    iVar1 = DAT_003a78b8 + local_8 * 0x324;
    *(uint *)(iVar1 + 0x198) = *(uint *)(iVar1 + 0x198) & 0xfffffffd;
    *(uint *)(iVar1 + 0x198) = *(uint *)(iVar1 + 0x198) & 0xffffffdf;
  }
  return;
}


// SV_ClearCaches  @ 000a84fc
void SV_ClearCaches(void)

{
  int local_8;
  
  for (local_8 = 1; (local_8 < 0x100 && (*(int *)(&DAT_0039cfac + local_8 * 0x10) != 0));
      local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0039cfac + local_8 * 0x10) = 0;
    if (*(int *)(&DAT_0039cfb4 + local_8 * 0x10) != 0) {
      Mem_Free(*(undefined4 *)(&DAT_0039cfb4 + local_8 * 0x10));
    }
    *(undefined4 *)(&DAT_0039cfb4 + local_8 * 0x10) = 0;
  }
  return;
}


// SV_ClearClientStates  @ 0006b084
void SV_ClearClientStates(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    COM_ClearCustomizationList(local_c + 0x4d30,0);
    SV_ClearResourceLists(local_c);
    local_c = local_c + 0x4eec;
  }
  return;
}


// SV_ClearEntities  @ 000aa114
void SV_ClearEntities(void)

{
  FUN_000aa121();
  return;
}


// SV_ClearFrames  @ 0009bac0
void SV_ClearFrames(int *param_1)

{
  undefined4 *local_c;
  int local_8;
  
  if (*param_1 != 0) {
    local_8 = 0;
    local_c = (undefined4 *)*param_1;
    for (; local_8 < SV_UPDATE_BACKUP; local_8 = local_8 + 1) {
      SV_ClearPacketEntities(local_c);
      *local_c = 0;
      local_c[1] = 0;
      local_c[2] = 0xbf800000;
      local_c = local_c + 0x604;
    }
    Mem_Free(*param_1);
    *param_1 = 0;
  }
  return;
}


// SV_ClearPacketEntities  @ 0009b9d8
void SV_ClearPacketEntities(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x180c) != 0) {
      Mem_Free(*(undefined4 *)(param_1 + 0x180c));
    }
    *(undefined4 *)(param_1 + 0x180c) = 0;
    *(undefined4 *)(param_1 + 0x17e8) = 0;
  }
  return;
}


// SV_ClearResourceList  @ 000b5c18
void SV_ClearResourceList(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x80);
  while ((local_8 != 0 && (local_8 != param_1))) {
    iVar1 = *(int *)(local_8 + 0x80);
    SV_RemoveFromResourceList(local_8);
    Mem_Free(local_8);
    local_8 = iVar1;
  }
  *(int *)(param_1 + 0x84) = param_1;
  *(int *)(param_1 + 0x80) = param_1;
  return;
}


// SV_ClearResourceLists  @ 000b5670
void SV_ClearResourceLists(int param_1)

{
  if (param_1 == 0) {
    Sys_Error("SV_ClearResourceLists with NULL client!");
  }
  SV_ClearResourceList(param_1 + 0x4ca0);
  SV_ClearResourceList(param_1 + 0x4c18);
  return;
}


// SV_ClearSecurityModule  @ 00093f64
void SV_ClearSecurityModule(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x93f70;
  if (*param_1 != 0) {
    Mem_Free(*param_1);
  }
  Q_memset(param_1,0,0x18,uVar1);
  return;
}


// SV_ClearWorld  @ 000be57c
void SV_ClearWorld(void)

{
  SV_InitBoxHull();
  Q_memset(&sv_areanodes,0,0x400);
  sv_numareanodes = 0;
  SV_CreateAreaNode(0,DAT_0036bd88 + 0x54,DAT_0036bd88 + 0x60);
  return;
}


// SV_ClientPrintf  @ 0006a680
void SV_ClientPrintf(char *param_1)

{
  char local_408 [1024];
  undefined1 *local_8;
  
  if (*(int *)(host_client + 0x2438) == 0) {
    local_8 = &stack0x00000008;
    vsnprintf(local_408,0x400,param_1,local_8);
    MSG_WriteByte(host_client + 0x74,8);
    MSG_WriteString(host_client + 0x74,local_408);
  }
  return;
}


// SV_ClipMoveToEntity  @ 000bff38
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


// SV_ClipToLinks  @ 000bff94
/* WARNING: Removing unreachable block (ram,0x000c034e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ClipToLinks(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar6;
  float *pfVar7;
  float *pfVar8;
  int aiStack_90 [2];
  float afStack_88 [7];
  float local_48;
  int local_44;
  float local_38;
  int *local_18;
  int *local_10;
  int *local_c;
  int *local_8;
  undefined1 *puVar5;
  
  puVar6 = &stack0xffffff94;
  local_8 = (int *)param_1[7];
  do {
    if (local_8 == param_1 + 6) {
      if (*param_1 != -1) {
        if ((float)param_1[1] < param_2[*param_1 + 3]) {
          *(float **)(puVar6 + -0xc) = param_2;
          *(int *)(puVar6 + -0x10) = param_1[2];
          *(undefined4 *)(puVar6 + -0x14) = 0xc03a7;
          SV_ClipToLinks();
        }
        fVar1 = param_2[*param_1];
        fVar2 = (float)param_1[1];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
          *(float **)(puVar6 + -0xc) = param_2;
          *(int *)(puVar6 + -0x10) = param_1[3];
          *(undefined4 *)(puVar6 + -0x14) = 0xc03e1;
          SV_ClipToLinks();
        }
      }
      return;
    }
    local_c = (int *)local_8[1];
    local_10 = local_8 + -2;
    if (((local_8[0xae] == 0) || (param_2[0x1f] == 0.0)) ||
       (*(int *)((int)param_2[0x1f] + 0x2c0) == 0)) {
LAB_000c0054:
      if ((local_8[0x61] != 0) && (local_10 != (int *)param_2[0x1f])) {
        if (local_8[0x61] == 1) {
          *(char **)(puVar6 + -0x10) = "Trigger in clipping list";
          *(undefined4 *)(puVar6 + -0x14) = 0xc0095;
          Sys_Error();
        }
        if (_DAT_0036aea0 != (code *)0x0) {
          *(float *)(puVar6 + -0xc) = param_2[0x1f];
          *(int **)(puVar6 + -0x10) = local_10;
          *(undefined4 *)(puVar6 + -0x14) = 0xc00bd;
          iVar3 = (*_DAT_0036aea0)();
          if (iVar3 == 0) {
            return;
          }
        }
        if (local_10[99] == 4) {
          if (((local_10[0x89] & 0x800000U) == 0) || (param_2[0x20] != 0.0)) {
LAB_000c011c:
            if ((((*(short *)((int)param_2 + 0x7a) == 0) || (local_10[0x72] == 0)) ||
                ((local_10[0x89] & 0x2000000U) != 0)) &&
               (((*param_2 <= (float)local_10[0x54] && (param_2[1] <= (float)local_10[0x55])) &&
                (param_2[2] <= (float)local_10[0x56])))) {
              fVar1 = param_2[3];
              fVar2 = (float)local_10[0x51];
              if ((byte)(fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
                fVar1 = param_2[4];
                fVar2 = (float)local_10[0x52];
                if ((byte)(fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
                  fVar1 = param_2[5];
                  fVar2 = (float)local_10[0x53];
                  if (((byte)(fVar1 < fVar2 |
                              (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
                     (((param_2[0x1f] == 0.0 ||
                       (fVar1 = *(float *)((int)param_2[0x1f] + 0x174),
                       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) ||
                      ((byte)((byte)((ushort)((ushort)NAN((float)local_10[0x5d]) << 10) >> 8) |
                             (byte)((ushort)((ushort)((float)local_10[0x5d] == 0.0) << 0xe) >> 8))
                       != 0x40)))) {
                    if (param_2[0x10] != 0.0) {
                      return;
                    }
                    if ((param_2[0x1f] == 0.0) ||
                       (((float)local_10[0x86] != param_2[0x1f] &&
                        (*(int **)((int)param_2[0x1f] + 0x218) != local_10)))) {
                      if ((local_10[0x89] & 0x20U) == 0) {
                        *(float *)(puVar6 + -0xc) = param_2[0xf];
                        *(float *)(puVar6 + -0x10) = param_2[7];
                        *(float *)(puVar6 + -0x14) = param_2[6];
                        *(float *)(puVar6 + -0x18) = param_2[0xe];
                        *(int **)(puVar6 + -0x1c) = local_10;
                        *(float **)(puVar6 + -0x20) = &local_48;
                        *(undefined4 *)(puVar6 + -0x24) = 0xc02dc;
                        SV_ClipMoveToEntity();
                      }
                      else {
                        *(float *)(puVar6 + -0xc) = param_2[0xf];
                        *(float **)(puVar6 + -0x10) = param_2 + 0xb;
                        *(float **)(puVar6 + -0x14) = param_2 + 8;
                        *(float *)(puVar6 + -0x18) = param_2[0xe];
                        *(int **)(puVar6 + -0x1c) = local_10;
                        *(float **)(puVar6 + -0x20) = &local_48;
                        *(undefined4 *)(puVar6 + -0x24) = 0xc02a8;
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
        else if ((*(short *)(param_2 + 0x1e) != 1) || (local_10[0x62] == 0xd)) goto LAB_000c011c;
      }
    }
    else if (g_groupop == 0) {
      if ((local_8[0xae] & *(uint *)((int)param_2[0x1f] + 0x2c0)) != 0) goto LAB_000c0054;
    }
    else if ((g_groupop != 1) || ((local_8[0xae] & *(uint *)((int)param_2[0x1f] + 0x2c0)) == 0))
    goto LAB_000c0054;
    local_8 = local_c;
  } while( true );
}


// SV_ClipToWorldbrush  @ 000c03f0
/* WARNING: Removing unreachable block (ram,0x000c05b2) */

void SV_ClipToWorldbrush(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar6;
  float *pfVar7;
  float *pfVar8;
  int aiStack_90 [2];
  float afStack_88 [7];
  float local_48;
  int local_44;
  float local_38;
  int *local_18;
  int *local_10;
  int *local_c;
  int *local_8;
  undefined1 *puVar5;
  
  puVar6 = &stack0xffffff94;
  local_8 = (int *)param_1[7];
  do {
    if (local_8 == param_1 + 6) {
      if (*param_1 != -1) {
        if ((float)param_1[1] < param_2[*param_1 + 3]) {
          *(float **)(puVar6 + -0xc) = param_2;
          *(int *)(puVar6 + -0x10) = param_1[2];
          *(undefined4 *)(puVar6 + -0x14) = 0xc060b;
          SV_ClipToWorldbrush();
        }
        fVar1 = param_2[*param_1];
        fVar2 = (float)param_1[1];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
          *(float **)(puVar6 + -0xc) = param_2;
          *(int *)(puVar6 + -0x10) = param_1[3];
          *(undefined4 *)(puVar6 + -0x14) = 0xc0645;
          SV_ClipToWorldbrush();
        }
      }
      return;
    }
    local_c = (int *)local_8[1];
    local_10 = local_8 + -2;
    if (((((local_8[0x61] == 4) && (local_10 != (int *)param_2[0x1f])) &&
         ((local_8[0x87] & 0x2000000U) != 0)) &&
        ((*param_2 <= (float)local_8[0x52] && (param_2[1] <= (float)local_8[0x53])))) &&
       (param_2[2] <= (float)local_8[0x54])) {
      fVar1 = param_2[3];
      fVar2 = (float)local_8[0x4f];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        fVar1 = param_2[4];
        fVar2 = (float)local_8[0x50];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          fVar1 = param_2[5];
          fVar2 = (float)local_8[0x51];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            if (param_2[0x10] != 0.0) {
              return;
            }
            *(float *)(puVar6 + -0xc) = param_2[0xf];
            *(float *)(puVar6 + -0x10) = param_2[7];
            *(float *)(puVar6 + -0x14) = param_2[6];
            *(float *)(puVar6 + -0x18) = param_2[0xe];
            *(int **)(puVar6 + -0x1c) = local_10;
            *(float **)(puVar6 + -0x20) = &local_48;
            *(undefined4 *)(puVar6 + -0x24) = 0xc0540;
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


// SV_CloseEnough  @ 000b0334
undefined4 SV_CloseEnough(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return 1;
    }
    if (*(float *)(local_8 * 4 + param_1 + 0x150) + param_3 <
        *(float *)(local_8 * 4 + param_2 + 0x144)) break;
    fVar2 = *(float *)(local_8 * 4 + param_1 + 0x144) - param_3;
    fVar1 = *(float *)(local_8 * 4 + param_2 + 0x150);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      return 0;
    }
    local_8 = local_8 + 1;
  }
  return 0;
}


// SV_CompareUserID  @ 000ae1f0
bool SV_CompareUserID(int *param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  size_t sVar4;
  char local_84 [63];
  undefined1 local_45;
  char local_44 [63];
  undefined1 local_5;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    bVar3 = false;
  }
  else if (*param_1 == *param_2) {
    iVar2 = *param_1;
    if (iVar2 == 0) {
      bVar3 = param_2[1] == param_1[1];
    }
    else if ((iVar2 < 0) || (2 < iVar2)) {
      bVar3 = false;
    }
    else {
      sVar4 = 0x3f;
      pcVar1 = (char *)SV_GetIDString(param_1);
      strncpy(local_44,pcVar1,sVar4);
      local_5 = 0;
      sVar4 = 0x3f;
      pcVar1 = (char *)SV_GetIDString(param_2);
      strncpy(local_84,pcVar1,sVar4);
      local_45 = 0;
      iVar2 = strcasecmp(local_44,local_84);
      bVar3 = iVar2 == 0;
    }
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}


// SV_ComputeLatency  @ 000b9920
void SV_ComputeLatency(int param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)SV_CalcClientTime(param_1);
  *(float *)(param_1 + 0x248c) = (float)lVar1;
  return;
}


// SV_ConnectClient  @ 000a0830
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ConnectClient(void)

{
  int iVar1;
  int *piVar2;
  int **ppiVar3;
  int *piVar4;
  int *piStackY_12fc;
  int aiStackY_12f8 [3];
  int *piStackY_12ec;
  int *piStackY_12e8;
  char *pcStackY_12e4;
  int *piStackY_12e0;
  undefined1 local_12ac [1024];
  undefined1 local_eac [1024];
  size_t local_aac;
  int local_aa8;
  uint local_aa4;
  int local_aa0;
  undefined1 *local_a9c;
  undefined2 local_a96;
  int local_a94;
  int local_a90 [129];
  int local_88c [8];
  undefined4 local_86c;
  int local_828 [255];
  undefined1 local_429;
  int local_428 [255];
  undefined1 local_29;
  int local_28;
  int local_24;
  int local_20 [5];
  int *local_c;
  int local_8;
  
  local_c = (int *)0x0;
  local_a90[0] = -1;
  local_a94 = -1;
  local_a9c = (undefined1 *)0x0;
  piVar2 = &net_from;
  piVar4 = local_20;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar4 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar4 = piVar4 + 1;
  }
  piStackY_12e0 = (int *)0xa0891;
  local_a96 = Q_atoi();
  iVar1 = Cmd_Argc();
  if (iVar1 < 5) {
    piStackY_12e0 = (int *)0xa08be;
    SV_RejectConnection();
  }
  else {
    aiStackY_12f8[2] = 1;
    aiStackY_12f8[1] = 0xa08d8;
    pcStackY_12e4 = (char *)Cmd_Argv();
    piStackY_12e8 = (int *)0xa08e3;
    Q_atoi();
    piStackY_12e0 = (int *)0xa08f2;
    iVar1 = SV_CheckProtocol();
    if (iVar1 != 0) {
      aiStackY_12f8[2] = 2;
      aiStackY_12f8[1] = 0xa0910;
      pcStackY_12e4 = (char *)Cmd_Argv();
      piStackY_12e8 = (int *)0xa091b;
      Q_atoi();
      piStackY_12e0 = (int *)0xa092a;
      iVar1 = SV_CheckChallenge();
      if (iVar1 != 0) {
        piStackY_12e0 = (int *)0xa094e;
        Q_memset();
        piStackY_12e0 = (int *)0xa095b;
        local_86c = Cmd_Argv();
        piStackY_12e0 = (int *)0xa0981;
        Q_strncpy();
        local_429 = 0;
        piStackY_12e0 = local_a90;
        pcStackY_12e4 = (char *)&local_a96;
        piStackY_12e8 = local_828;
        piStackY_12ec = local_20;
        aiStackY_12f8[2] = 0xa09c1;
        iVar1 = SV_CheckKeyInfo();
        if (iVar1 != 0) {
          piStackY_12e0 = (int *)0xa09eb;
          iVar1 = SV_CheckIPRestrictions();
          if (iVar1 != 0) {
            piStackY_12e0 = (int *)0xa0a06;
            local_86c = Cmd_Argv();
            piStackY_12e0 = (int *)0xa0a2c;
            Q_strncpy();
            local_29 = 0;
            iVar1 = Master_IsLanGame();
            if (((((iVar1 == 0) && (local_a90[0] != 2)) && (local_a94 != -1)) &&
                ((local_a94 != 0 && (local_a90[0] != 3)))) && (local_a90[0] != 4)) {
              piStackY_12e0 = (int *)0xa0b26;
              local_aa0 = SV_CheckForDuplicateWonID();
              if (local_aa0 != -1) {
                local_c = (int *)(DAT_00524284 + local_aa0 * 0x4eec);
                pcStackY_12e4 = &DAT_000e9470;
                piStackY_12e8 = local_428;
                piStackY_12ec = (int *)0xa0ba1;
                local_28 = local_aa0;
                Info_ValueForKey();
                piStackY_12e0 = (int *)0xa0bac;
                iVar1 = Q_stricmp();
                local_aa4 = (uint)(iVar1 == 0);
                piVar2 = local_c + 8;
                ppiVar3 = &piStackY_12e8;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *ppiVar3 = (int *)*piVar2;
                  piVar2 = piVar2 + 1;
                  ppiVar3 = ppiVar3 + 1;
                }
                piVar2 = local_20;
                ppiVar3 = &piStackY_12fc;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *ppiVar3 = (int *)*piVar2;
                  piVar2 = piVar2 + 1;
                  ppiVar3 = ppiVar3 + 1;
                }
                local_aa8 = NET_CompareAdr();
                local_aac = 0;
                if (((sv != 0) && (cls != 0)) && (local_aa0 == 0)) {
                  local_aac = 1;
                }
                if ((local_aac != 0) || ((local_aa4 == 0 && (local_aa8 == 0)))) {
                  piStackY_12e0 = (int *)0xa0c55;
                  SV_RejectConnection();
                  return;
                }
                local_a9c = (undefined1 *)0x1;
                local_aac = 0;
              }
            }
            else {
              for (local_28 = 0; local_28 < DAT_00524288; local_28 = local_28 + 1) {
                local_c = (int *)(DAT_00524284 + local_28 * 0x4eec);
                piVar2 = local_c + 8;
                ppiVar3 = &piStackY_12e8;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *ppiVar3 = (int *)*piVar2;
                  piVar2 = piVar2 + 1;
                  ppiVar3 = ppiVar3 + 1;
                }
                piVar2 = local_20;
                ppiVar3 = &piStackY_12fc;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *ppiVar3 = (int *)*piVar2;
                  piVar2 = piVar2 + 1;
                  ppiVar3 = ppiVar3 + 1;
                }
                iVar1 = NET_CompareAdr();
                if (iVar1 != 0) {
                  local_a9c = (undefined1 *)0x1;
                  break;
                }
              }
            }
            piStackY_12e0 = (int *)local_28;
            pcStackY_12e4 = local_a9c;
            piStackY_12e8 = local_428;
            piStackY_12ec = local_20;
            aiStackY_12f8[2] = 0xa0c8f;
            iVar1 = SV_CheckUserInfo();
            if (iVar1 != 0) {
              piStackY_12e0 = (int *)0xa0cbe;
              iVar1 = SV_FinishCertificateCheck();
              if (iVar1 != 0) {
                if (local_a9c == (undefined1 *)0x0) {
                  piStackY_12e0 = (int *)0xa0ce9;
                  iVar1 = SV_FindEmptySlot();
                  if (iVar1 == 0) {
                    return;
                  }
                }
                else {
                  if (((*local_c != 0) || (local_c[1] != 0)) && (local_c[0x12a1] != 0)) {
                    piStackY_12e0 = (int *)0xa0d34;
                    (*_DAT_0036af80)();
                  }
                  piVar2 = local_20;
                  piVar4 = aiStackY_12f8 + 1;
                  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                    *piVar4 = *piVar2;
                    piVar2 = piVar2 + 1;
                    piVar4 = piVar4 + 1;
                  }
                  aiStackY_12f8[0] = 0xa0d52;
                  NET_AdrToString();
                  piStackY_12e0 = (int *)0xa0d66;
                  Con_Printf();
                }
                host_client = local_c;
                if (local_a90[0] == 3) {
                  local_aac = DAT_0059d8d0 - msg_readcount;
                  if (((int)local_aac < 1) || (0x3ff < (int)local_aac)) {
                    piStackY_12e0 = (int *)0xa0dd2;
                    SV_RejectConnection();
                    return;
                  }
                  piStackY_12e0 = (int *)0xa0e06;
                  memcpy(local_eac,(void *)(DAT_0059d8c8 + msg_readcount),local_aac);
                  piStackY_12e0 = (int *)local_aac;
                  pcStackY_12e4 = local_eac;
                  piStackY_12e8 = local_20;
                  piStackY_12ec = host_client;
                  aiStackY_12f8[2] = 0xa0e2e;
                  iVar1 = SV_StartSteamValidation();
                  if (iVar1 == 0) {
                    piStackY_12e0 = (int *)0xa0e91;
                    SV_RejectConnection();
                    return;
                  }
                  host_client[0x12a4] = 1;
                  piStackY_12e0 = (int *)0xa0e64;
                  Q_memset();
                  host_client[0x12a8] = local_20[1];
                }
                else if (local_a90[0] == 4) {
                  local_aac = DAT_0059d8d0 - msg_readcount;
                  if (((int)local_aac < 1) || (0x3ff < (int)local_aac)) {
                    piStackY_12e0 = (int *)0xa0f02;
                    SV_RejectConnection();
                    return;
                  }
                  piStackY_12e0 = (int *)0xa0f36;
                  memcpy(local_12ac,(void *)(DAT_0059d8c8 + msg_readcount),local_aac);
                  piStackY_12e0 = (int *)local_aac;
                  pcStackY_12e4 = local_12ac;
                  piStackY_12e8 = local_20;
                  piStackY_12ec = host_client;
                  aiStackY_12f8[2] = 0xa0f5e;
                  iVar1 = SV_StartSteamValidation();
                  if (iVar1 == 0) {
                    piStackY_12e0 = (int *)0xa0fc1;
                    SV_RejectConnection();
                    return;
                  }
                  host_client[0x12a4] = 2;
                  piStackY_12e0 = (int *)0xa0f94;
                  Q_memset();
                  host_client[0x12a8] = local_20[1];
                }
                else {
                  local_c[0x12a4] = 0;
                  host_client[0x12a5] = local_a94;
                }
                piStackY_12e0 = (int *)0xa1007;
                SV_ClearResourceLists();
                piStackY_12e0 = (int *)0xa1021;
                SV_ClearFrames();
                piStackY_12e0 = (int *)0xa1047;
                iVar1 = Mem_ZeroMalloc();
                host_client[0xd20] = iVar1;
                piVar2 = host_client;
                piVar4 = host_client + 0x1328;
                host_client[0x1349] = (int)piVar4;
                piVar2[0x1348] = (int)piVar4;
                piVar2 = host_client;
                piVar4 = host_client + 0x1306;
                host_client[0x1327] = (int)piVar4;
                piVar2[0x1326] = (int)piVar4;
                local_24 = local_28 + 1;
                piStackY_12e0 = (int *)0xa10c5;
                local_8 = EDICT_NUM();
                host_client[0x12a1] = local_8;
                if (_DAT_001198c4 != (code *)0x0) {
                  piStackY_12e0 = (int *)0xa10fc;
                  (*_DAT_001198c4)();
                }
                piStackY_12e0 = (int *)(((int)local_c - DAT_00524284) * 0x614fb973 >> 2);
                piVar2 = local_20;
                piVar4 = aiStackY_12f8 + 1;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *piVar4 = *piVar2;
                  piVar2 = piVar2 + 1;
                  piVar4 = piVar4 + 1;
                }
                aiStackY_12f8[0] = (int)(host_client + 7);
                piStackY_12fc = (int *)0x1;
                Netchan_Setup();
                piVar2 = host_client;
                piVar2[0xd1c] = -0x66666666;
                piVar2[0xd1d] = 0x3fa99999;
                *(double *)(host_client + 0xd1a) = realtime + *(double *)(host_client + 0xd1c);
                host_client[0x90d] = -1;
                piStackY_12e0 = (int *)0xa11b6;
                Q_memset();
                piVar2 = host_client;
                piVar2[0x927] = 0;
                piVar2[0x928] = -0x40100000;
                if (host_client[8] == 1) {
                  piStackY_12e0 = (int *)0xa11ec;
                  Con_DPrintf();
                }
                else {
                  piVar2 = host_client + 8;
                  piVar4 = aiStackY_12f8 + 2;
                  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                    *piVar4 = *piVar2;
                    piVar2 = piVar2 + 1;
                    piVar4 = piVar4 + 1;
                  }
                  aiStackY_12f8[1] = 0xa1217;
                  NET_AdrToString();
                  piStackY_12e0 = (int *)0xa1232;
                  Con_DPrintf();
                }
                piStackY_12e0 = (int *)0xa1255;
                Q_strncpy();
                *(undefined1 *)(host_client + 0x12f3) = 0;
                *host_client = 0;
                host_client[1] = 0;
                host_client[3] = 1;
                host_client[4] = 0;
                host_client[2] = 0;
                host_client[0x12a3] = g_userid;
                g_userid = g_userid + 1;
                piVar2 = host_client + 8;
                piVar4 = aiStackY_12f8 + 2;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *piVar4 = *piVar2;
                  piVar2 = piVar2 + 1;
                  piVar4 = piVar4 + 1;
                }
                aiStackY_12f8[1] = 0xa12ec;
                NET_AdrToString();
                piStackY_12e8 = host_client;
                piStackY_12ec = (int *)0xa1312;
                SV_GetClientIDString();
                piStackY_12e0 = (int *)0x42;
                pcStackY_12e4 = "%c %s %i \"%s\"";
                piVar2 = local_20;
                piVar4 = aiStackY_12f8;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *piVar4 = *piVar2;
                  piVar2 = piVar2 + 1;
                  piVar4 = piVar4 + 1;
                }
                piStackY_12fc = (int *)0x1;
                Netchan_OutOfBandPrint();
                piVar2 = host_client + 8;
                piVar4 = aiStackY_12f8;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *piVar4 = *piVar2;
                  piVar2 = piVar2 + 1;
                  piVar4 = piVar4 + 1;
                }
                piStackY_12fc = (int *)0xa1360;
                NET_AdrToString();
                piStackY_12ec = host_client;
                aiStackY_12f8[2] = 0xa1377;
                piStackY_12e0 = (int *)SV_GetClientIDString();
                pcStackY_12e4 = (char *)host_client[0x12a3];
                piStackY_12e8 = local_88c;
                piStackY_12ec = (int *)0xe9660;
                aiStackY_12f8[2] = 0xa13a1;
                Log_Printf();
                piStackY_12e0 = (int *)0xa13c7;
                Q_strncpy();
                *(undefined1 *)((int)host_client + 0x4ba3) = 0;
                piStackY_12e0 = (int *)0xa13ea;
                SV_ExtractFromUserinfo();
                *(undefined2 *)(host_client + 0x92c) = 1;
                host_client[0x92d] = (int)(host_client + 0x930);
                host_client[0x92e] = 4000;
                host_client[0x92b] = (int)(host_client + 0x12fb);
                host_client[0x12ea] = 0;
              }
            }
          }
        }
      }
    }
  }
  return;
}


// SV_ConnectionlessPacket  @ 000a3ce8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ConnectionlessPacket(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  byte **ppbVar5;
  byte *apbStack_54 [8];
  int iStack_34;
  undefined4 uStack_30;
  
  uStack_30 = 0xa3d02;
  MSG_BeginReading();
  uStack_30 = 0xa3d07;
  MSG_ReadLong();
  uStack_30 = 0xa3d0c;
  iVar1 = MSG_ReadStringLine();
  apbStack_54[5] = (byte *)0xa3d23;
  apbStack_54[6] = (byte *)iVar1;
  Cmd_TokenizeString();
  apbStack_54[6] = (byte *)0x0;
  apbStack_54[5] = (byte *)0xa3d30;
  pbVar2 = (byte *)Cmd_Argv();
  puVar4 = &net_from;
  ppbVar5 = apbStack_54 + 2;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppbVar5 = (byte *)*puVar4;
    puVar4 = puVar4 + 1;
    ppbVar5 = ppbVar5 + 1;
  }
  apbStack_54[1] = (byte *)0xa3d55;
  iVar3 = CheckIP();
  if (iVar3 == 0) {
    if ((byte)(0.0 < (float)sv_logblocks._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_logblocks._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_logblocks._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      puVar4 = &net_from;
      ppbVar5 = apbStack_54;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppbVar5 = (byte *)*puVar4;
        puVar4 = puVar4 + 1;
        ppbVar5 = ppbVar5 + 1;
      }
      apbStack_54[7] = (byte *)NET_AdrToString();
      apbStack_54[6] = (byte *)0xe9ac0;
      apbStack_54[5] = (byte *)0xa3da9;
      Log_Printf();
    }
  }
  else {
    apbStack_54[7] = &DAT_000e9af7;
    apbStack_54[5] = (byte *)0xa3dc9;
    apbStack_54[6] = pbVar2;
    iVar3 = Q_strcmp();
    if ((iVar3 == 0) || ((*pbVar2 == 0x69 && ((pbVar2[1] == 0 || (pbVar2[1] == 10)))))) {
      uStack_30 = 0xa3df5;
      SVC_Ping();
    }
    else if (*pbVar2 == 0x6c) {
      uStack_30 = 0xa3e0d;
      MSG_BeginReading();
      uStack_30 = 0xa3e12;
      MSG_ReadLong();
      uStack_30 = 0xa3e17;
      MSG_ReadByte();
      uStack_30 = 0xa3e1c;
      apbStack_54[7] = (byte *)MSG_ReadString();
      apbStack_54[6] = &DAT_000e9afc;
      apbStack_54[5] = (byte *)0xa3e36;
      Con_Printf();
    }
    else if (*pbVar2 == 0x4f) {
      uStack_30 = 0xa3e51;
      MSG_BeginReading();
      uStack_30 = 0xa3e56;
      MSG_ReadLong();
      uStack_30 = 0xa3e5b;
      MSG_ReadByte();
      apbStack_54[7] = (byte *)0x3;
      apbStack_54[6] = (byte *)0xe9b00;
      apbStack_54[5] = (byte *)0xa3e6e;
      Con_Printf();
      apbStack_54[6] = (byte *)0xe8f7c;
      apbStack_54[5] = (byte *)0xa3e82;
      iVar1 = COM_CheckParm();
      if (iVar1 == 0) {
        apbStack_54[6] = (byte *)0xe9b80;
        apbStack_54[5] = (byte *)0xa3eb5;
        Con_Printf();
      }
      else {
        apbStack_54[6] = (byte *)0xe9b20;
        apbStack_54[5] = (byte *)0xa3e9c;
        Con_Printf();
      }
    }
    else if ((*pbVar2 == 0x6a) && ((pbVar2[1] == 0 || (pbVar2[1] == 10)))) {
      puVar4 = &net_from;
      ppbVar5 = apbStack_54;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppbVar5 = (byte *)*puVar4;
        puVar4 = puVar4 + 1;
        ppbVar5 = ppbVar5 + 1;
      }
      apbStack_54[7] = (byte *)NET_AdrToString();
      apbStack_54[6] = (byte *)0xe9bb9;
      apbStack_54[5] = (byte *)0xa3f14;
      Con_Printf();
    }
    else if ((*pbVar2 == 0x73) && ((pbVar2[1] == 0 || (pbVar2[1] == 10)))) {
      uStack_30 = 0xa3f45;
      SVC_Heartbeat();
    }
    else if ((*pbVar2 == 0x4b) && ((pbVar2[1] == 0 || (pbVar2[1] == 10)))) {
      uStack_30 = 0xa3f71;
      UPDATE_ProcessMessage();
    }
    else {
      apbStack_54[7] = &DAT_000e9bca;
      apbStack_54[5] = (byte *)0xa3f91;
      apbStack_54[6] = pbVar2;
      iVar3 = Q_stricmp();
      if (iVar3 == 0) {
        if (((byte)(0.0 < (float)sv_logrelay._12_4_ |
                    (byte)((ushort)((ushort)NAN((float)sv_logrelay._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)sv_logrelay._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
            ) && (iVar1 != 0)) {
          apbStack_54[5] = (byte *)0xa3fc7;
          apbStack_54[6] = (byte *)iVar1;
          iVar3 = Q_strlen();
          if (4 < iVar3) {
            apbStack_54[6] = &DAT_000e9bce;
            apbStack_54[5] = (byte *)0xa3fe2;
            iVar3 = Q_strlen();
            apbStack_54[7] = (byte *)(iVar1 + iVar3);
            if ((apbStack_54[7] != (byte *)0x0) && (*apbStack_54[7] != '\0')) {
              apbStack_54[6] = &DAT_000e9afc;
              apbStack_54[5] = (byte *)0xa4012;
              Con_Printf();
            }
          }
        }
      }
      else {
        apbStack_54[6] = (byte *)(uint)*pbVar2;
        apbStack_54[5] = (byte *)0xa4030;
        iVar3 = WON_IsAuthMessage();
        if (iVar3 != 0) {
          apbStack_54[6] = (byte *)0xe8f7c;
          apbStack_54[5] = (byte *)0xa404a;
          iVar3 = COM_CheckParm();
          if (iVar3 == 0) {
            apbStack_54[6] = (byte *)(uint)*pbVar2;
            apbStack_54[5] = (byte *)0xa4063;
            WON_ParseAuthenticationMessage();
            return;
          }
        }
        apbStack_54[7] = (byte *)0xe9bd3;
        apbStack_54[5] = (byte *)0xa4085;
        apbStack_54[6] = pbVar2;
        iVar3 = Q_strcmp();
        if (iVar3 == 0) {
          uStack_30 = 0xa4093;
          SVC_GetChallenge();
        }
        else {
          apbStack_54[7] = (byte *)0xe9be0;
          apbStack_54[5] = (byte *)0xa40b5;
          apbStack_54[6] = pbVar2;
          iVar3 = Q_stricmp();
          if (iVar3 == 0) {
            uStack_30 = 0xa40c3;
            SVC_ServiceChallenge();
          }
          else {
            apbStack_54[7] = &DAT_000e9bea;
            apbStack_54[5] = (byte *)0xa40e5;
            apbStack_54[6] = pbVar2;
            iVar3 = Q_stricmp();
            if (iVar3 == 0) {
              apbStack_54[6] = (byte *)0x0;
              apbStack_54[5] = (byte *)0xa40f8;
              SVC_Info();
            }
            else {
              apbStack_54[7] = (byte *)0xe9bef;
              apbStack_54[5] = (byte *)0xa411d;
              apbStack_54[6] = pbVar2;
              iVar3 = Q_stricmp();
              if (iVar3 == 0) {
                apbStack_54[6] = (byte *)0x1;
                apbStack_54[5] = (byte *)0xa4130;
                SVC_Info();
              }
              else {
                apbStack_54[7] = (byte *)0xe9bf7;
                apbStack_54[5] = (byte *)0xa4155;
                apbStack_54[6] = pbVar2;
                iVar3 = Q_stricmp();
                if (iVar3 == 0) {
                  uStack_30 = 0xa4163;
                  SVC_InfoString();
                }
                else {
                  apbStack_54[7] = (byte *)0xe9862;
                  apbStack_54[5] = (byte *)0xa4185;
                  apbStack_54[6] = pbVar2;
                  iVar3 = Q_stricmp();
                  if (iVar3 == 0) {
                    uStack_30 = 0xa4193;
                    SVC_PlayerInfo();
                  }
                  else {
                    apbStack_54[7] = (byte *)0xe9c02;
                    apbStack_54[5] = (byte *)0xa41b5;
                    apbStack_54[6] = pbVar2;
                    iVar3 = Q_stricmp();
                    if (iVar3 == 0) {
                      uStack_30 = 0xa41c3;
                      SVC_RuleInfo();
                    }
                    else {
                      apbStack_54[7] = (byte *)0xe9c08;
                      apbStack_54[5] = (byte *)0xa41e5;
                      apbStack_54[6] = pbVar2;
                      iVar3 = Q_strcmp();
                      if (iVar3 == 0) {
                        uStack_30 = 0xa41f3;
                        SV_ConnectClient();
                      }
                      else {
                        apbStack_54[7] = (byte *)0xe9c10;
                        apbStack_54[5] = (byte *)0xa4215;
                        apbStack_54[6] = pbVar2;
                        iVar3 = Q_strcmp();
                        if (iVar3 == 0) {
                          if (_DAT_001198cc != (code *)0x0) {
                            apbStack_54[7] = (byte *)DAT_0059d8d0;
                            apbStack_54[6] = (byte *)DAT_0059d8c8;
                            apbStack_54[5] = (byte *)0xa424c;
                            (*_DAT_001198cc)();
                          }
                        }
                        else {
                          apbStack_54[7] = &DAT_000e981f;
                          apbStack_54[5] = (byte *)0xa4271;
                          apbStack_54[6] = pbVar2;
                          iVar3 = Q_strcmp();
                          if (iVar3 == 0) {
                            apbStack_54[6] = (byte *)&net_from;
                            apbStack_54[5] = (byte *)0xa428b;
                            SV_Rcon();
                          }
                          else {
                            apbStack_54[5] = (byte *)0xa429c;
                            apbStack_54[6] = (byte *)iVar1;
                            iVar3 = SVC_GameDllQuery();
                            if (iVar3 == 0) {
                              puVar4 = &net_from;
                              ppbVar5 = apbStack_54;
                              iStack_34 = iVar1;
                              for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
                                *ppbVar5 = (byte *)*puVar4;
                                puVar4 = puVar4 + 1;
                                ppbVar5 = ppbVar5 + 1;
                              }
                              apbStack_54[7] = (byte *)NET_AdrToString();
                              apbStack_54[6] = (byte *)0xe9c20;
                              apbStack_54[5] = (byte *)0xa42dd;
                              Con_DPrintf();
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// SV_ConvertPMTrace  @ 000b7e48
void SV_ConvertPMTrace(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  param_1[8] = param_2[8];
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  param_1[0xb] = param_2[0xb];
  param_1[0xd] = param_2[0x10];
  param_1[0xc] = param_3;
  return;
}


// SV_CopyEdictToPhysent  @ 000b6f20
void SV_CopyEdictToPhysent(char *param_1,undefined4 param_2,int param_3)

{
  int local_8;
  
  *(undefined4 *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_3 + 0x88);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_3 + 0x8c);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_3 + 0x90);
  if ((*(int *)(param_1 + 0x50) < 1) || (DAT_00524288 < *(int *)(param_1 + 0x50))) {
    param_1[0x20] = '\0';
    param_1[0x21] = '\0';
    param_1[0x22] = '\0';
    param_1[0x23] = '\0';
  }
  else {
    SV_GetTrueOrigin(*(int *)(param_1 + 0x50) + -1,param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x50);
  }
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_3 + 0xd0);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_3 + 0xd4);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_3 + 0xd8);
  param_1[0x34] = '\0';
  param_1[0x35] = '\0';
  param_1[0x36] = '\0';
  param_1[0x37] = '\0';
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_3 + 0x1c8);
  if (*(int *)(param_3 + 0x18c) == 4) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_3 + 0x134) * 4)
    ;
    Q_strncpy(param_1,*(undefined4 *)(param_1 + 0x30),0x20);
    param_1[0x1f] = '\0';
  }
  else if (*(int *)(param_3 + 0x18c) == 0) {
    if (*(int *)(param_3 + 0x134) == 0) {
      param_1[0x30] = '\0';
      param_1[0x31] = '\0';
      param_1[0x32] = '\0';
      param_1[0x33] = '\0';
    }
    else {
      *(undefined4 *)(param_1 + 0x30) =
           *(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_3 + 0x134) * 4);
      Q_strncpy(param_1,*(undefined4 *)(param_1 + 0x30),0x20);
      param_1[0x1f] = '\0';
    }
  }
  else if (*(int *)(param_3 + 0x18c) == 2) {
    param_1[0x30] = '\0';
    param_1[0x31] = '\0';
    param_1[0x32] = '\0';
    param_1[0x33] = '\0';
    if (*(int *)(param_3 + 0x134) == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(int *)(&DAT_0039c5a8 + *(int *)(param_3 + 0x134) * 4);
    }
    if ((local_8 == 0) || ((*(uint *)(local_8 + 0x50) & 0x200) == 0)) {
      if (local_8 != 0) {
        Q_strncpy(param_1,local_8,0x20);
        param_1[0x1f] = '\0';
      }
    }
    else {
      *(int *)(param_1 + 0x34) = local_8;
      Q_strncpy(param_1,*(undefined4 *)(param_1 + 0x34),0x20);
      param_1[0x1f] = '\0';
    }
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_3 + 0x15c);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_3 + 0x160);
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_3 + 0x164);
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_3 + 0x168);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_3 + 0x16c);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_3 + 0x170);
  }
  else {
    param_1[0x30] = '\0';
    param_1[0x31] = '\0';
    param_1[0x32] = '\0';
    param_1[0x33] = '\0';
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_3 + 0x15c);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_3 + 0x160);
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_3 + 0x164);
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_3 + 0x168);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_3 + 0x16c);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_3 + 0x170);
    if (*(int *)(param_3 + 0x80) == 0) {
      sprintf(param_1,"?");
    }
    else {
      Q_strncpy(param_1,pr_strings + *(int *)(param_3 + 0x80),0x20);
      param_1[0x1f] = '\0';
    }
    param_1[0x1f] = '\0';
  }
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_3 + 0x18c);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_3 + 400);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_3 + 0x1b0);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_3 + 0x1a8);
  Q_memcpy(param_1 + 0x74,param_3 + 0x1bc,4);
  Q_memcpy(param_1 + 0x78,param_3 + 0x1c0,2);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_3 + 0x188);
  param_1[0x80] = '\0';
  param_1[0x81] = '\0';
  param_1[0x82] = '\0';
  param_1[0x83] = '\0';
  param_1[0x84] = '\0';
  param_1[0x85] = '\0';
  param_1[0x86] = '\0';
  param_1[0x87] = '\0';
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_3 + 0x2c4);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_3 + 0x2c8);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_3 + 0x2cc);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_3 + 0x2d0);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_3 + 0x2d4);
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_3 + 0x2d8);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_3 + 0x2dc);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_3 + 0x2e0);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_3 + 0x2e4);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_3 + 0x2e8);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_3 + 0x2ec);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_3 + 0x2f0);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_3 + 0x2f4);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_3 + 0x2f8);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_3 + 0x2fc);
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_3 + 0x300);
  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_3 + 0x304);
  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_3 + 0x308);
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_3 + 0x30c);
  *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_3 + 0x310);
  return;
}


// SV_CountPlayers  @ 0009c040
void SV_CountPlayers(int *param_1)

{
  int *local_c;
  int local_8;
  
  *param_1 = 0;
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (((*local_c != 0) || (local_c[1] != 0)) || (local_c[3] != 0)) {
      *param_1 = *param_1 + 1;
    }
    local_c = local_c + 0x13bb;
  }
  return;
}


// SV_CountProxies  @ 0009c0b8
void SV_CountProxies(int *param_1)

{
  int *local_c;
  int local_8;
  
  *param_1 = 0;
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if ((((*local_c != 0) || (local_c[1] != 0)) || (local_c[3] != 0)) && (local_c[0x90f] != 0)) {
      *param_1 = *param_1 + 1;
    }
    local_c = local_c + 0x13bb;
  }
  return;
}


// SV_CreateAreaNode  @ 000be36c
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
  ClearLink(&DAT_0057c3f0 + iVar2);
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


// SV_CreateBaseline  @ 000a8808
/* WARNING: Removing unreachable block (ram,0x000a88d8) */
/* WARNING: Removing unreachable block (ram,0x000a88e6) */

void SV_CreateBaseline(void)

{
  int *piVar1;
  undefined1 local_168 [344];
  undefined4 uStack_10;
  int local_c;
  int *piStack_8;
  
  DAT_003a78c0 = g_sv_instance_baselines;
  Q_memset(local_168,0,0x154);
  SV_FindModelNumbers();
  piVar1 = DAT_003a78b8;
  local_c = 0;
  if (DAT_003a78b0 < 1) {
    FUN_000a89f8();
    return;
  }
  piStack_8 = DAT_003a78b8;
  if ((*DAT_003a78b8 == 0) && ((-1 < DAT_00524288 || (DAT_003a78b8[0x4d] != 0)))) {
    uStack_10 = 0;
    DAT_003a78bc[1] = 0;
    *DAT_003a78bc = 1;
    if ((piVar1[0x89] & 0x20000000U) != 0) {
      *DAT_003a78bc = 2;
    }
    (*pcRam0036afe0)(0,0,DAT_003a78bc,piVar1,sv_playermodel,player_mins,player_maxs);
    sv_lastnum = local_c;
  }
  local_c = local_c + 1;
  FUN_000a8858();
  return;
}


// SV_CreateCustomizationList  @ 000b56cc
void SV_CreateCustomizationList(int param_1)

{
  int iVar1;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(param_1 + 0x4dd0) = 0;
  local_8 = *(int *)(param_1 + 0x4c98);
  do {
    if (local_8 == param_1 + 0x4c18) {
      return;
    }
    local_10 = 0;
    for (local_c = *(int *)(param_1 + 0x4dd0); local_c != 0; local_c = *(int *)(local_c + 0xa0)) {
      iVar1 = Q_memcmp(local_c + 0x51,local_8 + 0x4d,0x10);
      if (iVar1 == 0) {
        local_10 = 1;
        break;
      }
    }
    if (local_10 == 0) {
      local_1c = 0;
      local_18 = COM_CreateCustomization(param_1 + 0x4d30,local_8,0xffffffff,3,&local_14,&local_1c);
      if (local_18 == 0) {
        if ((byte)(0.0 < (float)sv_allow_upload._12_4_ |
                   (byte)((ushort)((ushort)NAN((float)sv_allow_upload._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)sv_allow_upload._12_4_ == 0.0) << 0xe) >> 8)) ==
            0x40) {
          Con_Printf("Ignoring custom decal from %s\n",param_1 + 0x4bec);
        }
        else {
          Con_Printf("Ignoring invalid custom decal from %s\n",param_1 + 0x4bec);
        }
      }
      else {
        *(undefined4 *)(local_14 + 0x94) = local_1c;
        (*DAT_0036afb4)(*(undefined4 *)(param_1 + 0x4a84),local_14);
      }
    }
    else {
      Con_DPrintf("SV_CreateCustomization list, ignoring dup. resource for player %s\n",
                  param_1 + 0x4bec);
    }
    local_8 = *(int *)(local_8 + 0x80);
  } while( true );
}


// SV_CreateGenericResources  @ 000a7d00
void SV_CreateGenericResources(void)

{
  int iVar1;
  int iStack_110;
  undefined1 local_108 [260];
  
  COM_StripExtension(&DAT_0036bd48,local_108);
  COM_DefaultExtension(local_108,&DAT_000ea084);
  COM_FixSlashes(local_108);
  iStack_110 = COM_LoadFile(local_108,5,0);
  if (iStack_110 == 0) {
    return;
  }
  Con_DPrintf("Precaching from %s\n",local_108);
  Con_DPrintf("----------------------------------\n");
  iRam003a77ac = 0;
  while( true ) {
    iStack_110 = COM_Parse(iStack_110);
    iVar1 = Q_strlen(&com_token);
    if (iVar1 < 1) break;
    iVar1 = Q_strstr(&com_token,&DAT_000ea0c4);
    if (iVar1 == 0) {
      iVar1 = Q_strstr(&com_token,&UNK_000ea117);
      if (iVar1 == 0) {
        iVar1 = Q_strstr(&com_token,&UNK_000ea14f);
        if (iVar1 == 0) {
          iVar1 = Q_strstr(&com_token,&UNK_000ea151);
          if (iVar1 == 0) {
            iVar1 = Q_strstr(&com_token,&UNK_000ea180);
            if (iVar1 == 0) {
              iVar1 = Q_strstr(&com_token,&UNK_000ea1c0);
              if (iVar1 == 0) {
                iVar1 = Q_strstr(&com_token,&UNK_000ea200);
                if (iVar1 == 0) {
                  iVar1 = Q_strstr(&com_token,&UNK_000ea240);
                  if (iVar1 == 0) {
                    iVar1 = Q_strstr(&com_token,&UNK_000ea280);
                    if (iVar1 == 0) {
                      iVar1 = Q_strstr(&com_token,&UNK_000ea2c0);
                      if (iVar1 == 0) {
                        Q_strncpy(iRam003a77ac * 0x40 + 0x39f7ac,&com_token,0x3f);
                        *(undefined1 *)(iRam003a77ac * 0x40 + 0x39f7eb) = 0;
                        PF_precache_generic_I(iRam003a77ac * 0x40 + 0x39f7ac);
                        Con_DPrintf(&UNK_000ea300,iRam003a77ac * 0x40 + 0x39f7ac);
                        iRam003a77ac = iRam003a77ac + 1;
                      }
                      else {
                        Con_Printf("Can\'t precache .dll files:  %s\n",&com_token);
                      }
                    }
                    else {
                      Con_Printf("Can\'t precache .bat files:  %s\n",&com_token);
                    }
                  }
                  else {
                    Con_Printf("Can\'t precache .com files:  %s\n",&com_token);
                  }
                }
                else {
                  Con_Printf("Can\'t precache .vbs files:  %s\n",&com_token);
                }
              }
              else {
                Con_Printf("Can\'t precache .exe files:  %s\n",&com_token);
              }
            }
            else {
              Con_Printf("Can\'t precache .lst files:  %s\n",&com_token);
            }
          }
          else {
            Con_Printf("Can\'t precache .cfg files:  %s\n",&com_token);
          }
        }
        else {
          Con_Printf("Can\'t precache resource with invalid relative path %s\n",&com_token);
        }
      }
      else {
        Con_Printf("Can\'t precache resource with absolute path %s\n",&com_token);
      }
    }
    else {
      Con_Printf("Can\'t precache resource with invalid relative path %s\n",&com_token);
    }
  }
  FUN_000a81bc();
  return;
}


// SV_CreatePacketEntities  @ 000a5b9c
void SV_CreatePacketEntities(int param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_28 = 0;
  local_30 = (int *)0x0;
  if (param_1 == 1) {
    local_c = *(int *)(param_2 + 0x3480) + (*(uint *)(param_2 + 0x2434) & SV_UPDATE_MASK) * 0x1810;
    local_10 = (int *)(local_c + 0x17e8);
    local_24 = *local_10;
    MSG_WriteByte(param_4,0x29);
    MSG_WriteShort(param_4,*param_3);
    MSG_WriteByte(param_4,*(undefined4 *)(param_2 + 0x2434));
  }
  else {
    local_24 = 0;
    local_10 = (int *)0x0;
    MSG_WriteByte(param_4,0x28);
    MSG_WriteShort(param_4,*param_3);
  }
  local_18 = 0;
  local_14 = 0;
  MSG_StartBitWriting(param_4);
  do {
    while( true ) {
      while( true ) {
        if ((*param_3 <= local_18) && (local_24 <= local_14)) {
          FUN_000a6168();
          return;
        }
        if (local_18 < *param_3) {
          local_20 = *(int *)(param_3[9] + 4 + local_18 * 0x154);
        }
        else {
          local_20 = 9999;
        }
        if (local_14 < local_24) {
          local_1c = *(int *)(local_10[9] + 4 + local_14 * 0x154);
        }
        else {
          local_1c = 9999;
        }
        if (local_20 != local_1c) break;
        local_28 = *(uint *)(param_3[9] + local_18 * 0x154) >> 1 & 1;
        SV_SetCallback(local_20,0,local_28,&local_30,0,0);
        if (local_28 == 0) {
          pcVar3 = SV_InvokeCallback;
          iVar1 = SV_IsPlayerIndex(local_20);
          uVar2 = g_pentitydelta;
          if (iVar1 != 0) {
            uVar2 = g_pplayerdelta;
          }
          DELTA_WriteDelta(local_10[9] + local_14 * 0x154,param_3[9] + local_18 * 0x154,0,uVar2,
                           pcVar3);
        }
        else {
          DELTA_WriteDelta(local_10[9] + local_14 * 0x154,param_3[9] + local_18 * 0x154,0,
                           g_pcustomentitydelta,SV_InvokeCallback);
        }
        local_14 = local_14 + 1;
        local_18 = local_18 + 1;
      }
      if (local_20 < local_1c) break;
      if (local_1c < local_20) {
        local_28 = 0;
        SV_WriteDeltaHeader(local_1c,1,0,&local_30,0,0,0,0);
        TRACE_DELTA("remove%i\n",local_1c);
        local_14 = local_14 + 1;
      }
    }
    local_8 = EDICT_NUM(local_20);
    TRACE_DELTA("new from baseline %i\n",local_20);
    local_28 = *(uint *)(param_3[9] + local_18 * 0x154) >> 1 & 1;
    SV_SetCallback(local_20,0,local_28,&local_30,local_10 == (int *)0x0,0);
    local_34 = (int *)(DAT_003a78bc + local_20 * 0x154);
    if ((((byte)(0.0 < (float)sv_instancedbaseline._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)sv_instancedbaseline._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_instancedbaseline._12_4_ == 0.0) << 0xe) >> 8))
          == 0x40) || (*DAT_003a78c0 == 0)) || (local_20 <= sv_lastnum)) {
      if ((local_10 == (int *)0x0) &&
         (local_2c = SV_FindBestBaseline(local_18,&local_34,param_3[9],local_20,local_28),
         local_2c != 0)) {
        SV_SetCallback(local_20,0,local_28,&local_30,1,local_2c);
      }
    }
    else {
      for (local_38 = 0; local_38 < *DAT_003a78c0; local_38 = local_38 + 1) {
        if (DAT_003a78c0[local_38 + 1] == *(int *)(local_8 + 0x80)) {
          SV_SetNewInfo(local_38);
          local_34 = DAT_003a78c0 + local_38 * 0x55 + 0x41;
          break;
        }
      }
    }
    if (local_28 == 0) {
      pcVar3 = SV_InvokeCallback;
      iVar1 = SV_IsPlayerIndex(local_20);
      uVar2 = g_pentitydelta;
      if (iVar1 != 0) {
        uVar2 = g_pplayerdelta;
      }
      DELTA_WriteDelta(local_34,param_3[9] + local_18 * 0x154,1,uVar2,pcVar3);
    }
    else {
      DELTA_WriteDelta(local_34,param_3[9] + local_18 * 0x154,1,g_pcustomentitydelta,
                       SV_InvokeCallback);
    }
    local_18 = local_18 + 1;
  } while( true );
}


// SV_CreateResourceList  @ 000a81ec
void SV_CreateResourceList(void)

{
  bool bVar1;
  undefined4 uVar2;
  int local_14;
  int local_10;
  int *local_8;
  
  bVar1 = false;
  DAT_003965a0 = 0;
  local_10 = 1;
  for (local_8 = &DAT_0039efb0; *local_8 != 0; local_8 = local_8 + 1) {
    if (DAT_00524288 < 2) {
      local_14 = 0;
    }
    else {
      local_14 = COM_FileSize(*local_8);
      if (local_14 == -1) {
        local_14 = 0;
      }
    }
    SV_AddResource(4,*local_8,local_14,1,local_10);
    local_10 = local_10 + 1;
  }
  local_10 = 1;
  for (local_8 = &DAT_0039dfac; *local_8 != 0; local_8 = local_8 + 1) {
    if (*(char *)*local_8 == '!') {
      if (!bVar1) {
        bVar1 = true;
        SV_AddResource(0,&DAT_000ea30f,0,1,local_10);
      }
    }
    else {
      if (DAT_00524288 < 2) {
        local_14 = 0;
      }
      else {
        uVar2 = va("sound/%s",*local_8);
        local_14 = COM_FileSize(uVar2);
        if (local_14 == -1) {
          local_14 = 0;
        }
      }
      SV_AddResource(0,*local_8,local_14,0,local_10);
    }
    local_10 = local_10 + 1;
  }
  local_10 = 1;
  for (local_8 = &DAT_0039bdac; *local_8 != 0; local_8 = local_8 + 1) {
    if (DAT_00524288 < 2) {
      local_14 = 0;
    }
    else {
      local_14 = COM_FileSize(*local_8);
      if (local_14 == -1) {
        local_14 = 0;
      }
    }
    SV_AddResource(2,*local_8,local_14,(&DAT_0039cda8)[local_10],local_10);
    local_10 = local_10 + 1;
  }
  FUN_000a8418();
  return;
}


// SV_Customization  @ 000b586c
void SV_Customization(int *param_1,int param_2,int param_3)

{
  int local_c;
  int local_8;
  
  local_c = -1;
  local_8 = 0;
  host_client = DAT_00524284;
  do {
    if (DAT_00524288 <= local_8) {
LAB_000b58dc:
      if (local_c == -1) {
        Sys_Error("Couldn\'t find player index for customization.");
      }
      else {
        host_client = DAT_00524284;
        for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
          if ((((*host_client != 0) || (host_client[1] != 0)) && (host_client[0x90e] == 0)) &&
             ((host_client != param_1 || (param_3 == 0)))) {
            MSG_WriteByte(host_client + 0x1d,0x2e);
            MSG_WriteByte(host_client + 0x1d,local_c);
            MSG_WriteByte(host_client + 0x1d,*(undefined4 *)(param_2 + 0x40));
            MSG_WriteString(host_client + 0x1d,param_2);
            MSG_WriteShort(host_client + 0x1d,*(undefined4 *)(param_2 + 0x44));
            MSG_WriteLong(host_client + 0x1d,*(undefined4 *)(param_2 + 0x48));
            MSG_WriteByte(host_client + 0x1d,*(undefined1 *)(param_2 + 0x4c));
            if ((*(byte *)(param_2 + 0x4c) & 4) != 0) {
              SZ_Write(host_client + 0x1d,param_2 + 0x4d,0x10);
            }
          }
          host_client = host_client + 0x13bb;
        }
      }
      return;
    }
    if (host_client == param_1) {
      local_c = local_8;
      goto LAB_000b58dc;
    }
    local_8 = local_8 + 1;
    host_client = host_client + 0x13bb;
  } while( true );
}


// SV_DeallocateDynamicData  @ 0009b7c0
void SV_DeallocateDynamicData(void)

{
  if (g_moved_edict != 0) {
    Mem_Free(g_moved_edict);
  }
  if (g_moved_from != 0) {
    Mem_Free(g_moved_from);
  }
  g_moved_edict = 0;
  g_moved_from = 0;
  return;
}


// SV_DelLogAddress_f  @ 0009af14
void SV_DelLogAddress_f(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStackY_174 [2];
  void *local_12c;
  void *local_128;
  undefined4 local_124;
  undefined1 local_120 [14];
  short local_112;
  char local_110 [260];
  int local_c;
  char *local_8;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 3) {
    local_8 = (char *)Cmd_Argv();
    Cmd_Argv();
    local_c = Q_atoi();
    if (local_c == 0) {
      Con_Printf();
    }
    else if ((local_8 == (char *)0x0) || (*local_8 == '\0')) {
      Con_Printf();
    }
    else {
      auStackY_174[1] = 0x9b071;
      snprintf(local_110,0x104,"%s:%i");
      iVar2 = NET_StringToAdr();
      if (iVar2 == 0) {
        Con_Printf();
      }
      else if (firstLog == (void *)0x0) {
        Con_Printf();
      }
      else {
        local_12c = (void *)0x0;
        bVar1 = false;
        for (local_128 = firstLog; local_128 != (void *)0x0;
            local_128 = *(void **)((int)local_128 + 0x20)) {
          iVar2 = memcmp((void *)((int)local_128 + 0xc),local_120,4);
          if ((iVar2 == 0) && (*(short *)((int)local_128 + 0x1a) == local_112)) {
            bVar1 = true;
            break;
          }
          local_12c = local_128;
        }
        if (bVar1) {
          if (local_12c == (void *)0x0) {
            firstLog = (void *)0x0;
          }
          else {
            *(undefined4 *)((int)local_12c + 0x20) = *(undefined4 *)((int)local_128 + 0x20);
          }
          puVar3 = &local_124;
          puVar4 = auStackY_174;
          for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          NET_AdrToString();
          Con_Printf();
          free(local_128);
        }
        else {
          Con_Printf();
        }
      }
    }
  }
  else {
    Con_Printf();
    if (firstLog != (void *)0x0) {
      for (local_128 = firstLog; local_128 != (void *)0x0;
          local_128 = *(void **)((int)local_128 + 0x20)) {
        puVar3 = (undefined4 *)((int)local_128 + 8);
        puVar4 = auStackY_174;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        NET_AdrToString();
        Con_Printf();
      }
    }
  }
  return;
}


// SV_DownloadSecurityModules  @ 00093a8c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_DownloadSecurityModules(void)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  
  local_10 = 0x2d;
  local_f = 0x69;
  local_e = 0x6e;
  local_d = 0x73;
  local_c = 0x65;
  local_b = 99;
  local_a = 0x75;
  local_9 = 0x72;
  local_8 = 0x65;
  local_7 = 0;
  Q_memset(&DAT_00524318,0,0x18);
  Q_memset(&DAT_00524300,0,0x18);
  Q_memset(&DAT_00524348,0,0x18);
  Q_memset(&DAT_00524330,0,0x18);
  DAT_00524368 = 0;
  _DAT_00524360 = 0.0;
  iVar1 = COM_CheckParm(&local_10);
  if (((iVar1 == 0) && (isDedicated != 0)) && (DAT_0036ae94 != 0)) {
    UPDATE_UpdateAddressList();
    uVar2 = SV_GetFileNameModuleC(&DAT_00524348);
    UPDATE_GetModuleBlocking(uVar2);
    if ((DAT_00524348 == 0) || (DAT_0052434c == 0)) {
      SV_ClearSecurityModule(&DAT_00524348);
    }
    else {
      uVar2 = SV_GetFileNameModuleS(&DAT_00524330);
      UPDATE_GetModuleBlocking(uVar2);
      if ((DAT_00524330 == 0) || (DAT_00524334 == 0)) {
        SV_ClearSecurityModule(&DAT_00524330);
        SV_ClearSecurityModule(&DAT_00524348);
      }
      else {
        DAT_00524368 = 1;
        lVar3 = (longdouble)UPDATE_GetUpdateInterval();
        _DAT_00524360 = (double)((longdouble)realtime + lVar3);
        gSecureUpdateState = 4;
      }
    }
  }
  return;
}


// SV_DownloadingModules  @ 0009b3e8
void SV_DownloadingModules(void)

{
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  local_38 = 0x44;
  local_37 = 0x6f;
  local_36 = 0x77;
  local_35 = 0x6e;
  local_34 = 0x6c;
  local_33 = 0x6f;
  local_32 = 0x61;
  local_31 = 100;
  local_30 = 0x69;
  local_2f = 0x6e;
  local_2e = 0x67;
  local_2d = 0x20;
  local_2c = 0x53;
  local_2b = 0x65;
  local_2a = 99;
  local_29 = 0x75;
  local_28 = 0x72;
  local_27 = 0x69;
  local_26 = 0x74;
  local_25 = 0x79;
  local_24 = 0x20;
  local_23 = 0x4d;
  local_22 = 0x6f;
  local_21 = 100;
  local_20 = 0x75;
  local_1f = 0x6c;
  local_1e = 0x65;
  local_1d = 0x20;
  local_1c = 0x66;
  local_1b = 0x72;
  local_1a = 0x6f;
  local_19 = 0x6d;
  local_18 = 0x20;
  local_17 = 0x53;
  local_16 = 0x70;
  local_15 = 0x65;
  local_14 = 0x61;
  local_13 = 0x6b;
  local_12 = 0x65;
  local_11 = 0x61;
  local_10 = 0x73;
  local_f = 0x79;
  local_e = 0x2e;
  local_d = 0x6e;
  local_c = 0x65;
  local_b = 0x74;
  local_a = 0x20;
  local_9 = 0x2e;
  local_8 = 0x2e;
  local_7 = 0x2e;
  local_6 = 10;
  local_5 = 0;
  Con_Printf(&local_38);
  return;
}


// SV_DropClient  @ 0006a974
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_DropClient(undefined4 *param_1,int param_2,char *param_3)

{
  size_t sVar1;
  char local_474 [1024];
  undefined1 *local_74;
  float local_70;
  undefined1 local_6c;
  char local_6b [98];
  undefined1 local_9;
  int local_8;
  
  local_8 = 0;
  local_74 = &stack0x00000010;
  vsnprintf(local_474,0x400,param_3,local_74);
  if (param_2 == 0) {
    if (param_1[0x90e] == 0) {
      MSG_WriteByte(param_1 + 0x1d,2);
      MSG_WriteString(param_1 + 0x1d,local_474);
      local_6c = 2;
      sVar1 = strlen(local_474);
      if (sVar1 < 100) {
        sVar1 = strlen(local_474);
      }
      else {
        sVar1 = 99;
      }
      strncpy(local_6b,local_474,sVar1);
      local_9 = 0;
      sVar1 = strlen(local_474);
      if (sVar1 < 100) {
        sVar1 = strlen(local_474);
        local_8 = sVar1 + 1;
      }
      else {
        local_8 = 100;
      }
    }
    if ((param_1[0x12a1] != 0) && (param_1[1] != 0)) {
      (*_DAT_0036af80)(param_1[0x12a1]);
    }
    Sys_Printf("Dropped %s from server\nReason:  %s\n",param_1 + 0x12fb,local_474);
    if (param_1[0x90e] == 0) {
      Netchan_Transmit(param_1 + 7,local_8,&local_6c);
    }
  }
  local_70 = (float)realtime - (float)param_1[0xf];
  if ((byte)(60.0 < local_70 | (byte)((ushort)((ushort)NAN(local_70) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_70 == 60.0) << 0xe) >> 8)) == 1) {
    DAT_005242ec = DAT_005242ec + 1;
    DAT_005242f0 = DAT_005242f0 + local_70;
  }
  Netchan_Clear(param_1 + 7);
  SV_RemoveSteamValidation(param_1);
  *param_1 = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[0x90e] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 0x12fb) = 0;
  *(double *)(param_1 + 0xd18) = realtime;
  param_1[0x90f] = 0;
  COM_ClearCustomizationList(param_1 + 0x134c,0);
  param_1[0x12a1] = 0;
  Q_memset(param_1 + 0x12a9,0,0x100);
  Q_memset(param_1 + 0x1378,0,0x100);
  SV_FullClientUpdate(param_1,&DAT_003a887c);
  NotifyDedicatedServerUI("UpdatePlayers");
  return;
}


// SV_Drop_f  @ 000ad1f4
void SV_Drop_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    SV_EndRedirect();
    SV_BroadcastPrintf("%s dropped\n",host_client + 0x4bec);
    SV_DropClient(host_client,0,"Client sent \'drop\'");
  }
  return;
}


// SV_EmitEvents  @ 000a4df4
void SV_EmitEvents(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_6c [72];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  short *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_1c = 0;
  Q_memset(local_6c,0,0x48);
  local_10 = param_1 + 0x3484;
  for (local_c = 0; local_c < 0x40; local_c = local_c + 1) {
    local_14 = (short *)(local_10 + local_c * 0x58);
    if (*local_14 != 0) {
      local_1c = local_1c + 1;
    }
  }
  if (local_1c != 0) {
    if (0x1f < local_1c) {
      local_1c = 0x1f;
    }
    for (local_c = 0; local_c < 0x40; local_c = local_c + 1) {
      local_14 = (short *)(local_10 + local_c * 0x58);
      if (*local_14 != 0) {
        local_20 = (int)local_14[2];
        local_8 = 0;
        while ((local_8 < *param_2 &&
               (local_18 = param_2[9] + local_8 * 0x154, *(int *)(local_18 + 4) != local_20))) {
          local_8 = local_8 + 1;
        }
        if (local_8 < *param_2) {
          local_14[1] = (short)local_8;
          local_14[0x1c] = 0;
          local_14[0x1d] = 0;
          if ((*(uint *)(local_14 + 6) & 1) == 0) {
            local_14[10] = 0;
            local_14[0xb] = 0;
            local_14[0xc] = 0;
            local_14[0xd] = 0;
            local_14[0xe] = 0;
            local_14[0xf] = 0;
          }
          if ((*(uint *)(local_14 + 6) & 2) == 0) {
            local_14[0x10] = 0;
            local_14[0x11] = 0;
            local_14[0x12] = 0;
            local_14[0x13] = 0;
            local_14[0x14] = 0;
            local_14[0x15] = 0;
          }
        }
        else {
          local_14[1] = (short)*param_2;
          *(int *)(local_14 + 8) = local_20;
        }
      }
    }
    MSG_WriteByte(param_3,3);
    MSG_StartBitWriting(param_3);
    MSG_WriteBits(local_1c,5);
    local_24 = 0;
    for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
      local_14 = (short *)(local_10 + local_8 * 0x58);
      if (*local_14 == 0) {
        local_14[1] = -1;
        local_14[2] = -1;
      }
      else {
        if (local_24 < local_1c) {
          MSG_WriteBits(*local_14,10);
          if (local_14[1] == -1) {
            MSG_WriteBits(0,1);
          }
          else {
            MSG_WriteBits(1,1);
            MSG_WriteBits((int)local_14[1],0xb);
            iVar1 = Q_memcmp(local_6c,local_14 + 6,0x48);
            if (iVar1 == 0) {
              MSG_WriteBits(0,1);
            }
            else {
              MSG_WriteBits(1,1);
              DELTA_WriteDelta(local_6c,local_14 + 6,1,g_peventdelta,0);
            }
          }
          if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(local_14 + 4)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(local_14 + 4) == 0.0) << 0xe) >> 8)) == 0x40
             ) {
            MSG_WriteBits(0,1);
          }
          else {
            MSG_WriteBits(1,1);
            MSG_WriteBits((int)ROUND(*(float *)(local_14 + 4) * 100.0),0x10);
          }
        }
        *local_14 = 0;
        local_14[1] = -1;
        local_14[2] = -1;
        local_24 = local_24 + 1;
      }
    }
    MSG_EndBitWriting(param_3);
  }
  return;
}


// SV_EmitPacketEntities  @ 000a619c
void SV_EmitPacketEntities(void)

{
  FUN_000a61a8();
  return;
}


// SV_EmitPings  @ 000a65f8
void SV_EmitPings(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  MSG_WriteByte(param_2,0x11);
  MSG_StartBitWriting(param_2);
  local_8 = DAT_00524284;
  for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
    if (*local_8 != 0) {
      SV_GetNetInfo(local_8,&local_10,&local_14);
      MSG_WriteBits(1,1);
      MSG_WriteBits(local_c,5);
      MSG_WriteBits(local_10,0xc);
      MSG_WriteBits(local_14,7);
    }
    local_8 = local_8 + 0x13bb;
  }
  MSG_WriteBits(0,1);
  MSG_EndBitWriting(param_2);
  return;
}


// SV_EndRedirect  @ 000a31ec
void SV_EndRedirect(void)

{
  SV_FlushRedirect();
  sv_redirected = 0;
  return;
}


// SV_EstablishTimeBase  @ 000ba880
void SV_EstablishTimeBase(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined8 local_14;
  undefined4 local_8;
  
  local_14 = 0.0;
  local_8 = param_5;
  if (param_3 < 0x18) {
    for (; param_4 < param_3; param_3 = param_3 + -1) {
      local_14 = local_14 + (double)*(byte *)(param_1 + 0x2442) / 1000.0;
    }
    for (; 0 < param_3; param_3 = param_3 + -1) {
      local_14 = local_14 +
                 (double)*(byte *)(param_2 + 2 + (param_3 + param_5 + -1) * 0x34) / 1000.0;
    }
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    local_14 = local_14 + (double)*(byte *)(param_2 + 2 + local_8 * 0x34) / 1000.0;
  }
  *(double *)(param_1 + 0x24a4) = (DAT_0036bc6c + host_frametime) - local_14;
  return;
}


// SV_EstimateNeededResources  @ 000b5cf0
int SV_EstimateNeededResources(void)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = *(int *)(host_client + 0x4d20); local_8 != host_client + 0x4ca0;
      local_8 = *(int *)(local_8 + 0x80)) {
    local_10 = 0;
    if (*(int *)(local_8 + 0x40) == 3) {
      iVar1 = HPAK_ResourceForHash("custom.hpk",local_8 + 0x4d,0);
      if (iVar1 == 0) {
        local_10 = *(int *)(local_8 + 0x48);
      }
      else {
        local_10 = 0;
      }
    }
    if (local_10 != 0) {
      *(byte *)(local_8 + 0x4c) = *(byte *)(local_8 + 0x4c) | 2;
      local_c = local_c + local_10;
    }
  }
  return local_c;
}


// SV_ExecuteClientMessage  @ 000bb49c
void SV_ExecuteClientMessage(int param_1)

{
  float fVar1;
  int iVar2;
  double *pdVar3;
  
  g_balreadymoved = 0;
  pdVar3 = (double *)
           (*(int *)(param_1 + 0x3480) + (*(uint *)(param_1 + 0x54) & SV_UPDATE_MASK) * 0x1810);
  *(float *)(pdVar3 + 1) =
       (float)(((longdouble)realtime - (longdouble)*pdVar3) -
              (longdouble)*(double *)(param_1 + 0x3470));
  if ((byte)((byte)((ushort)((ushort)NAN(*pdVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(*pdVar3 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(pdVar3 + 1) = 0;
  }
  if ((realtime - *(double *)(param_1 + 0x3460) < 2.0) &&
     (fVar1 = *(float *)(pdVar3 + 1),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
    *(undefined4 *)(pdVar3 + 1) = 0;
  }
  SV_ComputeLatency(param_1);
  host_client = param_1;
  sv_player = *(undefined4 *)(param_1 + 0x4a84);
  *(undefined4 *)(param_1 + 0x2434) = 0xffffffff;
  pmove = g_svmove;
  while( true ) {
    if (msg_badread != 0) {
      Con_Printf("SV_ReadClientMessage: badread\n");
      SV_DropClient(param_1,0,"Bad parse in client command");
      return;
    }
    iVar2 = MSG_ReadByte();
    if (iVar2 == -1) break;
    if ((iVar2 < 0) || (9 < iVar2)) {
      Con_Printf("SV_ReadClientMessage: unknown command char (%d)\n",iVar2);
      SV_DropClient(param_1,0,"Bad command character in client command");
      return;
    }
    if (*(int *)(sv_clcfuncs + iVar2 * 0xc + 8) != 0) {
      (**(code **)(sv_clcfuncs + iVar2 * 0xc + 8))(param_1);
    }
  }
  return;
}


// SV_ExtractFromUserinfo  @ 000a7510
void SV_ExtractFromUserinfo(int *param_1)

{
  int iVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [31];
  undefined1 local_19;
  undefined4 local_18;
  int *local_14;
  int local_10;
  undefined4 local_8;
  
  local_18 = 1;
  local_8 = Info_ValueForKey(param_1 + 0x12a9,&DAT_000e9470);
  Q_strncpy(local_38,local_8,0x1f);
  local_19 = 0;
  Q_strcpy(local_58,local_38);
  TrimSpace(local_58,local_38);
  iVar1 = Q_strlen(local_38);
  if ((iVar1 < 1) || (iVar1 = Q_stricmp(local_38,"console"), iVar1 == 0)) {
    Info_SetValueForKey(param_1 + 0x12a9,&DAT_000e9470,"unnamed",0x100);
    local_8 = Info_ValueForKey(param_1 + 0x12a9,&DAT_000e9470);
  }
  else {
    iVar1 = Q_strcmp(local_8,local_38);
    if (iVar1 != 0) {
      Info_SetValueForKey(param_1 + 0x12a9,&DAT_000e9470,local_38,0x100);
      local_8 = Info_ValueForKey(param_1 + 0x12a9,&DAT_000e9470);
    }
  }
  local_10 = 0;
  local_14 = DAT_00524284;
  while( true ) {
    if (0x1f < local_10) {
      FUN_000a76dc();
      return;
    }
    if (((*local_14 == 0) || (local_14[1] == 0)) || (local_14 == param_1)) break;
    iVar1 = Q_stricmp(local_14 + 0x12fb,local_8);
    if (iVar1 == 0) {
      FUN_000a76dc();
      return;
    }
    local_10 = local_10 + 1;
    local_14 = local_14 + 0x13bb;
  }
  FUN_000a76d0();
  return;
}


// SV_FailDownload  @ 000ac67c
void SV_FailDownload(char *param_1)

{
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    MSG_WriteByte(host_client + 0x74,0x31);
    MSG_WriteString(host_client + 0x74,param_1);
  }
  return;
}


// SV_FatPAS  @ 000a553c
undefined1 * SV_FatPAS(undefined4 param_1)

{
  fatpasbytes = *(int *)(DAT_0036bd88 + 0x88) + 0x1f >> 3;
  Q_memset(fatpas,0,fatpasbytes);
  SV_AddToFatPAS(param_1,*(undefined4 *)(DAT_0036bd88 + 0xa4));
  return fatpas;
}


// SV_FatPVS  @ 000a531c
undefined1 * SV_FatPVS(undefined4 param_1)

{
  fatbytes = *(int *)(DAT_0036bd88 + 0x88) + 0x1f >> 3;
  Q_memset(fatpvs,0,fatbytes);
  SV_AddToFatPVS(param_1,*(undefined4 *)(DAT_0036bd88 + 0xa4));
  return fatpvs;
}


// SV_FileInConsistencyList  @ 000b6a28
undefined4 SV_FileInConsistencyList(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(&DAT_003965a4 + local_8 * 0x2c) == 0) {
      return 0;
    }
    iVar1 = Q_stricmp(param_1,*(undefined4 *)(&DAT_003965a4 + local_8 * 0x2c));
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = &DAT_003965a4 + local_8 * 0x2c;
  }
  return 1;
}


// SV_FilterPacket  @ 000a45f8
uint SV_FilterPacket(void)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_28;
  int local_c;
  int local_8;
  
  uVar3 = DAT_0058c8b8;
  local_c = numipfilters;
LAB_000a4628:
  do {
    local_8 = local_c + -1;
    if (local_8 < 0) {
      return (uint)((byte)(0.0 < (float)sv_filterban._12_4_ |
                           (byte)((ushort)((ushort)NAN((float)sv_filterban._12_4_) << 10) >> 8) |
                          (byte)((ushort)((ushort)((float)sv_filterban._12_4_ == 0.0) << 0xe) >> 8))
                   == 0x40);
    }
    if ((*(int *)(ipfilters + local_8 * 0x10 + 4) != -1) &&
       (fVar1 = *(float *)(ipfilters + local_8 * 0x10 + 8),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      fVar1 = *(float *)(ipfilters + local_8 * 0x10 + 8);
      fVar2 = (float)realtime;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        for (; local_c < numipfilters; local_c = local_c + 1) {
          iVar4 = (local_c + -1) * 0x10;
          iVar5 = local_c * 0x10;
          *(undefined4 *)(ipfilters + iVar4) = *(undefined4 *)(ipfilters + iVar5);
          *(undefined4 *)(ipfilters + iVar4 + 4) = *(undefined4 *)(ipfilters + iVar5 + 4);
          *(undefined4 *)(ipfilters + iVar4 + 8) = *(undefined4 *)(ipfilters + iVar5 + 8);
          *(undefined4 *)(ipfilters + iVar4 + 0xc) = *(undefined4 *)(ipfilters + iVar5 + 0xc);
        }
        numipfilters = numipfilters + -1;
        local_c = local_8;
        goto LAB_000a4628;
      }
    }
    local_c = local_8;
    if ((uVar3 & *(uint *)(ipfilters + local_8 * 0x10)) == *(uint *)(ipfilters + local_8 * 0x10 + 4)
       ) {
      local_28 = (uint)(longlong)ROUND((float)sv_filterban._12_4_);
      return local_28;
    }
  } while( true );
}


// SV_FilterUser  @ 0009f670
uint SV_FilterUser(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_28;
  int local_c;
  int local_8;
  
  local_c = numuserfilters;
LAB_0009f694:
  do {
    local_8 = local_c + -1;
    if (local_8 < 0) {
      return (uint)((byte)(0.0 < (float)sv_filterban._12_4_ |
                           (byte)((ushort)((ushort)NAN((float)sv_filterban._12_4_) << 10) >> 8) |
                          (byte)((ushort)((ushort)((float)sv_filterban._12_4_ == 0.0) << 0xe) >> 8))
                   == 0x40);
    }
    fVar1 = *(float *)(userfilters + local_8 * 0x1c + 0x14);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *(float *)(userfilters + local_8 * 0x1c + 0x14);
      fVar2 = (float)realtime;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        for (; local_c < numuserfilters; local_c = local_c + 1) {
          puVar4 = (undefined4 *)(userfilters + local_c * 0x1c);
          puVar5 = (undefined4 *)(userfilters + (local_c + -1) * 0x1c);
          for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
        }
        numuserfilters = numuserfilters + -1;
        local_c = local_8;
        goto LAB_0009f694;
      }
    }
    iVar3 = SV_CompareUserID(param_1,userfilters + local_8 * 0x1c);
    local_c = local_8;
    if (iVar3 != 0) {
      local_28 = (uint)(longlong)ROUND((float)sv_filterban._12_4_);
      return local_28;
    }
  } while( true );
}


// SV_FindAuthRequest  @ 000c9b08
int SV_FindAuthRequest(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  undefined4 auStack_6c [5];
  char *apcStack_58 [6];
  undefined4 uStack_40;
  int local_8;
  
  uStack_40 = 0xc9b16;
  local_8 = 0;
  do {
    if (0x7f < local_8) {
      if (param_1 == 0) {
        local_8 = -1;
      }
      else {
        for (local_8 = 0; (local_8 < 0x80 && (*(int *)(svauthstates + local_8 * 0x38) != 0));
            local_8 = local_8 + 1) {
        }
        if (local_8 == 0x80) {
          apcStack_58[3] = "No more authentication slots available\n";
          apcStack_58[2] = (char *)0xc9c22;
          Con_Printf();
          local_8 = -1;
        }
        else {
          iVar1 = local_8 * 0x38;
          puVar3 = (undefined4 *)(svauthstates + iVar1);
          apcStack_58[2] = (char *)0xc9c5f;
          apcStack_58[3] = (char *)puVar3;
          WON_RemoveUser();
          *(double *)(svauthstates + iVar1 + 0x18) =
               (double)((float)realtime + (float)(3 - *(int *)(svauthstates + iVar1 + 0x20)) * 5.0);
          *(undefined4 *)(svauthstates + iVar1 + 0x24) = 0x33;
          *(undefined4 *)(svauthstates + iVar1 + 0x20) = 3;
          puVar5 = puVar3;
          for (iVar2 = 5; puVar5 = puVar5 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = *param_2;
            param_2 = param_2 + 1;
          }
          *puVar3 = 1;
          *(undefined4 *)(svauthstates + iVar1 + 0x34) = 0xffffffff;
        }
      }
      return local_8;
    }
    if (*(int *)(svauthstates + local_8 * 0x38) != 0) {
      puVar3 = param_2;
      ppcVar4 = apcStack_58;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar4 = (char *)*puVar3;
        puVar3 = puVar3 + 1;
        ppcVar4 = ppcVar4 + 1;
      }
      puVar3 = (undefined4 *)(svauthstates + local_8 * 0x38);
      puVar5 = auStack_6c;
      for (iVar1 = 5; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar3;
        puVar5 = puVar5 + 1;
      }
      iVar1 = NET_CompareAdr();
      if (iVar1 != 0) {
        return local_8;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// SV_FindBestBaseline  @ 000a5944
int SV_FindBestBaseline(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = param_1;
  if (param_5 == 0) {
    iVar1 = SV_IsPlayerIndex(param_4);
    uVar2 = g_pentitydelta;
    if (iVar1 != 0) {
      uVar2 = g_pplayerdelta;
    }
    local_8 = DELTA_TestDelta(*param_2,param_1 * 0x154 + param_3,uVar2);
  }
  else {
    local_8 = DELTA_TestDelta(*param_2,param_1 * 0x154 + param_3,g_pcustomentitydelta);
  }
  local_8 = local_8 + -6;
  local_14 = param_1;
  while (((local_14 = local_14 + -1, 0 < local_8 && (-1 < local_14)) && (param_1 - local_14 < 0x3f))
        ) {
    if (*(int *)(param_3 + param_1 * 0x154) == *(int *)(param_3 + local_14 * 0x154)) {
      if (param_5 == 0) {
        iVar1 = SV_IsPlayerIndex(param_4);
        uVar2 = g_pentitydelta;
        if (iVar1 != 0) {
          uVar2 = g_pplayerdelta;
        }
        local_c = DELTA_TestDelta(local_14 * 0x154 + param_3,param_1 * 0x154 + param_3,uVar2);
      }
      else {
        local_c = DELTA_TestDelta(local_14 * 0x154 + param_3,param_1 * 0x154 + param_3,
                                  g_pcustomentitydelta);
      }
      if (local_c < local_8) {
        local_8 = local_c;
        local_10 = local_14;
      }
    }
  }
  if (param_1 - local_10 != 0) {
    *param_2 = param_3 + local_10 * 0x154;
  }
  return param_1 - local_10;
}


// SV_FindEmptySlot  @ 000a0744
bool SV_FindEmptySlot(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  local_10 = 0;
  SV_CountPlayers(&local_10);
  local_c = 0;
  while ((local_c < DAT_00524288 &&
         (((local_8 = (int *)(DAT_00524284 + local_c * 0x4eec), *local_8 != 0 || (local_8[1] != 0))
          || (local_8[3] != 0))))) {
    local_c = local_c + 1;
  }
  bVar1 = local_c < DAT_00524288;
  if (bVar1) {
    *param_2 = local_c;
    *param_3 = local_8;
  }
  else {
    SV_RejectConnection(param_1,"Server is full.\n");
  }
  return bVar1;
}


// SV_FindEntInPack  @ 000b9c28
int SV_FindEntInPack(int param_1,int *param_2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*param_2 <= local_8) {
      return 0;
    }
    if (*(int *)(param_2[9] + 4 + local_8 * 0x154) == param_1) break;
    local_8 = local_8 + 1;
  }
  return local_8 * 0x154 + param_2[9];
}


// SV_FindModelNumbers  @ 0009c13c
void SV_FindModelNumbers(void)

{
  int iVar1;
  int local_8;
  
  sv_playermodel = -1;
  for (local_8 = 0; (local_8 < 0x200 && ((&DAT_0039bda8)[local_8] != 0)); local_8 = local_8 + 1) {
    iVar1 = Q_strcasecmp((&DAT_0039bda8)[local_8],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = local_8;
    }
  }
  return;
}


// SV_FindTouchedLeafs  @ 000be938
void SV_FindTouchedLeafs(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  
  if (*param_2 != -2) {
    if (*param_2 < 0) {
      if (*(int *)(param_1 + 0x14) < 0x30) {
        *(short *)(*(int *)(param_1 + 0x14) * 2 + param_1 + 0x18) =
             (short)(((int)param_2 - *(int *)(DAT_0036bd88 + 0x8c)) * -0x55555555 >> 4) + -1;
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = 0x31;
      }
    }
    else {
      iVar3 = param_2[6];
      if (*(byte *)(iVar3 + 0x10) < 3) {
        fVar1 = *(float *)(iVar3 + 0xc);
        fVar2 = *(float *)((uint)*(byte *)(iVar3 + 0x10) * 4 + param_1 + 0x144);
        if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
          uVar4 = 1;
        }
        else if (*(float *)(iVar3 + 0xc) <
                 *(float *)((uint)*(byte *)(iVar3 + 0x10) * 4 + param_1 + 0x150)) {
          uVar4 = 3;
        }
        else {
          uVar4 = 2;
        }
      }
      else {
        uVar4 = BoxOnPlaneSide(param_1 + 0x144,param_1 + 0x150,iVar3);
      }
      if ((uVar4 == 3) && (*param_3 == -1)) {
        *param_3 = ((int)param_2 - *(int *)(DAT_0036bd88 + 0xa4)) * -0x33333333 >> 3;
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


// SV_FinishCertificateCheck  @ 0009fb38
undefined4
SV_FinishCertificateCheck(undefined4 param_1,undefined4 param_2,int param_3,char *param_4)

{
  int iVar1;
  undefined4 local_28;
  int local_24;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_c = -1;
  local_14 = 0;
  switch(param_2) {
  default:
    iVar1 = WON_CheckAuthentication(param_1,param_4,&local_c);
    if (iVar1 == 0) {
      SV_RejectConnection(param_1,"Invalid authentication information.\n");
      return 0;
    }
    if (local_c != param_3) {
      SV_RejectConnection(param_1,"Invalid authentication userid.\n");
      return 0;
    }
    if (local_c != -1) {
      local_28 = 0;
      local_24 = local_c;
      iVar1 = SV_FilterUser(&local_28);
      if (iVar1 != 0) {
        SV_RejectConnection(param_1,"You have been banned from this server.\n");
        return 0;
      }
    }
    break;
  case 2:
    if (gfUseLANAuthentication == 0) {
      SV_RejectConnection(param_1,"Invalid authentication message.\n");
      return 0;
    }
    iVar1 = Q_strlen(param_4);
    if (iVar1 != 0x20) {
      SV_RejectConnection(param_1,"Invalid CD Key.\n");
      return 0;
    }
    local_10 = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if ((((*local_10 != 0) || (local_10[1] != 0)) || (local_10[3] != 0)) &&
         (iVar1 = Q_strnicmp(param_4,local_10 + 0x12eb,0x20), iVar1 == 0)) {
        local_14 = local_14 + 1;
      }
      local_10 = local_10 + 0x13bb;
    }
    if (4 < local_14) {
      SV_RejectConnection(param_1,"CD Key already in use.\n");
      return 0;
    }
    break;
  case 3:
    iVar1 = strcasecmp(param_4,"steam");
    if (iVar1 != 0) {
      SV_RejectConnection(param_1,"Expecting STEAM authentication USERID ticket!\n");
      return 0;
    }
    iVar1 = DAT_0059d8d0 - msg_readcount;
    if ((iVar1 < 0x400) && (0 < iVar1)) {
      return 1;
    }
    SV_RejectConnection(param_1,"STEAM authentication USERID ticket size is invalid(%i/%i)!\n",iVar1
                        ,0x400);
    return 0;
  case 4:
    iVar1 = strcasecmp(param_4,"valve");
    if (iVar1 != 0) {
      SV_RejectConnection(param_1,"Expecting VALVE authentication USERID ticket!\n");
      return 0;
    }
    iVar1 = DAT_0059d8d0 - msg_readcount;
    if ((iVar1 < 0x400) && (0 < iVar1)) {
      return 1;
    }
    SV_RejectConnection(param_1,"VALVE authentication USERID ticket size is invalid(%i/%i)!\n",iVar1
                        ,0x400);
    return 0;
  }
  return 1;
}


// SV_FixCheckBottom  @ 000afe28
void SV_FixCheckBottom(int param_1)

{
  *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) | 0x400;
  return;
}


// SV_FixupGravityVelocity  @ 000b1c68
void SV_FixupGravityVelocity(int param_1)

{
  float fVar1;
  undefined4 local_8;
  
  fVar1 = *(float *)(param_1 + 0x19c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_8 = 1.0;
  }
  else {
    local_8 = *(float *)(param_1 + 0x19c);
  }
  *(float *)(param_1 + 0xa8) =
       *(float *)(param_1 + 0xa8) - local_8 * (float)sv_gravity._12_4_ * (float)host_frametime * 0.5
  ;
  SV_CheckVelocity(param_1);
  return;
}


// SV_FlushRedirect  @ 000a3084
void SV_FlushRedirect(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 **ppuVar3;
  undefined1 *apuStack_5e0 [4];
  undefined4 uStack_5d0;
  undefined1 local_5ac [1428];
  char *local_18;
  undefined2 local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uStack_5d0 = 0xa3095;
  if (sv_redirected == 2) {
    local_18 = "Redirected Text";
    local_c = 0x591;
    local_8 = 0;
    local_10 = local_5ac;
    local_14 = 1;
    apuStack_5e0[2] = (undefined1 *)0xffffffff;
    apuStack_5e0[1] = (undefined1 *)&local_18;
    apuStack_5e0[0] = (undefined1 *)0xa30e1;
    MSG_WriteLong();
    apuStack_5e0[2] = (undefined1 *)0x6c;
    apuStack_5e0[1] = (undefined1 *)&local_18;
    apuStack_5e0[0] = (undefined1 *)0xa30f2;
    MSG_WriteByte();
    apuStack_5e0[2] = &outputbuf;
    apuStack_5e0[1] = (undefined1 *)&local_18;
    apuStack_5e0[0] = (undefined1 *)0xa310a;
    MSG_WriteString();
    apuStack_5e0[2] = (undefined1 *)0x0;
    apuStack_5e0[1] = (undefined1 *)&local_18;
    apuStack_5e0[0] = (undefined1 *)0xa311b;
    MSG_WriteByte();
    puVar2 = &sv_redirectto;
    ppuVar3 = apuStack_5e0;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = (undefined1 *)*puVar2;
      puVar2 = puVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    NET_SendPacket(1,local_8,local_10);
  }
  else if (sv_redirected == 1) {
    apuStack_5e0[2] = (undefined1 *)0x8;
    apuStack_5e0[1] = (undefined1 *)(host_client + 0x74);
    apuStack_5e0[0] = (undefined1 *)0xa3169;
    MSG_WriteByte();
    apuStack_5e0[2] = &outputbuf;
    apuStack_5e0[1] = (undefined1 *)(host_client + 0x74);
    apuStack_5e0[0] = (undefined1 *)0xa3189;
    MSG_WriteString();
  }
  outputbuf = 0;
  return;
}


// SV_FlyDirection  @ 000afd9c
bool SV_FlyDirection(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = SV_movestep(param_1,param_2,0,0xafda8);
  if (iVar1 == 0) {
    SV_LinkEdict(param_1,1);
  }
  else {
    SV_LinkEdict(param_1,1);
  }
  return iVar1 != 0;
}


// SV_FlyMove  @ 000b12ec
uint SV_FlyMove(int *param_1,float param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  int *piVar5;
  int aiStack_130 [5];
  float local_11c;
  int iStack_118;
  float local_114;
  uint uStack_110;
  uint local_d8;
  uint local_d4;
  float local_d0;
  float local_cc [3];
  int local_c0 [4];
  float local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  int local_90;
  int local_88;
  int local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c [3];
  undefined1 local_50 [48];
  int local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  
  local_d8 = (uint)((param_1[0x89] & 0x800000U) != 0);
  local_c = 4;
  local_d4 = 0;
  local_74 = (float)param_1[0x28];
  local_70 = (float)param_1[0x29];
  local_6c = (float)param_1[0x2a];
  local_68 = (float)param_1[0x28];
  local_64 = (float)param_1[0x29];
  local_60 = (float)param_1[0x2a];
  local_20 = 0;
  local_d0 = param_2;
  local_8 = 0;
  puVar3 = &stack0xfffffef4;
  do {
    if (local_c <= local_8) {
      return local_d4;
    }
    if ((((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x28]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x28] == 0.0) << 0xe) >> 8)) == 0x40) &&
        ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x29]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_1[0x29] == 0.0) << 0xe) >> 8)) == 0x40)) &&
       ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x2a]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x2a] == 0.0) << 0xe) >> 8)) == 0x40)) {
      return local_d4;
    }
    for (local_84 = 0; local_84 < 3; local_84 = local_84 + 1) {
      local_cc[local_84] =
           (float)param_1[local_84 + 0x22] + local_d0 * (float)param_1[local_84 + 0x28];
    }
    *(uint *)(puVar3 + -4) = local_d8;
    *(int **)(puVar3 + -8) = param_1;
    *(undefined4 *)(puVar3 + -0xc) = 0;
    *(float **)(puVar3 + -0x10) = local_cc;
    *(int **)(puVar3 + -0x14) = param_1 + 0x5a;
    *(int **)(puVar3 + -0x18) = param_1 + 0x57;
    *(int **)(puVar3 + -0x1c) = param_1 + 0x22;
    *(int **)(puVar3 + -0x20) = local_c0;
    *(undefined4 *)(puVar3 + -0x24) = 0xb14e6;
    SV_Move();
    if (local_c0[0] != 0) {
      param_1[0x28] = vec3_origin;
      param_1[0x29] = DAT_000f1be0;
      param_1[0x2a] = DAT_000f1be4;
      return 4;
    }
    if ((byte)(0.0 < local_b0 | (byte)((ushort)((ushort)NAN(local_b0) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_b0 == 0.0) << 0xe) >> 8)) == 1) {
      param_1[0x22] = local_ac;
      param_1[0x23] = local_a8;
      param_1[0x24] = local_a4;
      local_74 = (float)param_1[0x28];
      local_70 = (float)param_1[0x29];
      local_6c = (float)param_1[0x2a];
      local_20 = 0;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_b0) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_b0 == 1.0) << 0xe) >> 8)) == 0x40) {
      return local_d4;
    }
    if (local_90 == 0) {
      *(char **)(puVar3 + -0x14) = "SV_FlyMove: !trace.ent";
      *(undefined4 *)(puVar3 + -0x18) = 0xb15d6;
      Sys_Error();
    }
    if (((byte)(0.7 < local_98 | (byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_98 == 0.7) << 0xe) >> 8)) == 1) &&
       (((local_d4 = local_d4 | 1, *(int *)(local_90 + 0x18c) == 4 ||
         (*(int *)(local_90 + 0x188) == 0xd)) ||
        ((*(int *)(local_90 + 0x18c) == 3 || ((param_1[0x89] & 8U) != 0)))))) {
      param_1[0x89] = param_1[0x89] | 0x200;
      param_1[0x87] = local_90;
    }
    if (((byte)((byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_98 == 0.0) << 0xe) >> 8)) == 0x40) &&
       (local_d4 = local_d4 | 2, param_3 != (int *)0x0)) {
      piVar4 = local_c0;
      piVar5 = param_3;
      for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
    }
    *(int **)(puVar3 + -0xc) = local_c0;
    *(int *)(puVar3 + -0x10) = local_90;
    *(int **)(puVar3 + -0x14) = param_1;
    *(undefined4 *)(puVar3 + -0x18) = 0xb16aa;
    SV_Impact();
    if (*param_1 != 0) {
      return local_d4;
    }
    local_d0 = local_d0 - local_d0 * local_b0;
    if (4 < local_20) {
      param_1[0x28] = vec3_origin;
      param_1[0x29] = DAT_000f1be0;
      param_1[0x2a] = DAT_000f1be4;
      return local_d4;
    }
    local_5c[local_20 * 3] = local_a0;
    local_5c[local_20 * 3 + 1] = local_9c;
    local_5c[local_20 * 3 + 2] = local_98;
    local_20 = local_20 + 1;
    if ((param_1[0x62] == 3) &&
       (((param_1[0x89] & 0x200U) == 0 ||
        ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x68]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_1[0x68] == 1.0) << 0xe) >> 8)) != 0x40)))) {
      for (local_84 = 0; local_84 < local_20; local_84 = local_84 + 1) {
        fVar1 = local_5c[local_84 * 3 + 2];
        if ((byte)(0.7 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.7) << 0xe) >> 8)) == 1) {
          *(undefined4 *)(puVar3 + -8) = 0x3f800000;
          *(float **)(puVar3 + -0xc) = &local_80;
          *(float **)(puVar3 + -0x10) = local_5c + local_84 * 3;
          *(float **)(puVar3 + -0x14) = &local_74;
          *(undefined4 *)(puVar3 + -0x18) = 0xb1820;
          ClipVelocity();
          local_74 = local_80;
          local_70 = local_7c;
          local_6c = local_78;
        }
        else {
          *(float *)(puVar3 + -8) = (1.0 - (float)param_1[0x68]) * (float)sv_bounce._12_4_ + 1.0;
          *(float **)(puVar3 + -0xc) = &local_80;
          *(float **)(puVar3 + -0x10) = local_5c + local_84 * 3;
          *(float **)(puVar3 + -0x14) = &local_74;
          *(undefined4 *)(puVar3 + -0x18) = 0xb1885;
          ClipVelocity();
        }
      }
      param_1[0x28] = (int)local_80;
      param_1[0x29] = (int)local_7c;
      param_1[0x2a] = (int)local_78;
      local_74 = local_80;
      local_70 = local_7c;
      local_6c = local_78;
    }
    else {
      for (local_84 = 0; local_84 < local_20; local_84 = local_84 + 1) {
        *(undefined4 *)(puVar3 + -8) = 0x3f800000;
        *(float **)(puVar3 + -0xc) = &local_80;
        *(float **)(puVar3 + -0x10) = local_5c + local_84 * 3;
        *(float **)(puVar3 + -0x14) = &local_74;
        *(undefined4 *)(puVar3 + -0x18) = 0xb190c;
        ClipVelocity();
        local_88 = 0;
        while ((local_88 < local_20 &&
               ((local_88 == local_84 ||
                (0.0 <= local_78 * local_5c[local_88 * 3 + 2] +
                        local_7c * local_5c[local_88 * 3 + 1] + local_80 * local_5c[local_88 * 3])))
               )) {
          local_88 = local_88 + 1;
        }
        if (local_88 == local_20) break;
      }
      if (local_84 == local_20) {
        if (local_20 != 2) {
          return local_d4;
        }
        *(float **)(puVar3 + -0xc) = &local_18;
        *(undefined1 **)(puVar3 + -0x10) = local_50;
        *(float **)(puVar3 + -0x14) = local_5c;
        *(undefined4 *)(puVar3 + -0x18) = 0xb1a1b;
        CrossProduct();
        local_1c = local_10 * (float)param_1[0x2a] +
                   local_14 * (float)param_1[0x29] + local_18 * (float)param_1[0x28];
        *(int **)(puVar3 + -0xc) = param_1 + 0x28;
        *(float *)(puVar3 + -0x10) = local_1c;
        *(float **)(puVar3 + -0x14) = &local_18;
        *(undefined4 *)(puVar3 + -0x18) = 0xb1a67;
        VectorScale();
      }
      else {
        param_1[0x28] = (int)local_80;
        param_1[0x29] = (int)local_7c;
        param_1[0x2a] = (int)local_78;
      }
      if ((float)param_1[0x2a] * local_60 +
          (float)param_1[0x29] * local_64 + (float)param_1[0x28] * local_68 <= 0.0) {
        param_1[0x28] = vec3_origin;
        param_1[0x29] = DAT_000f1be0;
        param_1[0x2a] = DAT_000f1be4;
        return local_d4;
      }
    }
    local_8 = local_8 + 1;
    puVar3 = puVar3 + -4;
  } while( true );
}


// SV_ForceFullClientsUpdate  @ 000b7ef4
void SV_ForceFullClientsUpdate(void)

{
  char *local_2420 [2];
  undefined1 *local_2418;
  undefined4 local_2414;
  undefined4 local_2410;
  undefined1 local_240c [9216];
  int *local_c;
  int local_8;
  
  Q_memset(local_2420,0,0x14);
  local_2420[0] = "Force Update";
  local_2418 = local_240c;
  local_2410 = 0;
  local_2414 = 0x2400;
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if ((((local_c == host_client) || (*local_c != 0)) || (local_c[3] != 0)) || (local_c[1] != 0)) {
      SV_FullClientUpdate(local_c,local_2420);
    }
    local_c = local_c + 0x13bb;
  }
  Con_DPrintf("Client %s started recording. Send full update.\n",host_client + 0x12fb);
  Netchan_CreateFragments(1,host_client + 7,local_2420);
  Netchan_FragSend(host_client + 7);
  return;
}


// SV_Frame  @ 000ad120
void SV_Frame(void)

{
  int iVar1;
  
  if (sv != 0) {
    DAT_0036b224 = (float)host_frametime;
    DAT_0036bc74 = DAT_0036bc6c;
    SV_CheckCmdTimes();
    SV_ReadPackets();
    iVar1 = SV_IsSimulating();
    if (iVar1 != 0) {
      SV_Physics();
      DAT_0036bc6c = DAT_0036bc6c + host_frametime;
    }
    SV_QueryMovevarsChanged();
    SV_RequestMissingResourcesFromClients();
    iVar1 = COM_CheckParm("-steam");
    if (iVar1 == 0) {
      WON_HandleServerAuthMsgs();
    }
    ValveAuth_Init();
    Master_Heartbeat();
    SV_CheckTimeouts();
    SV_SecurityUpdate();
    SV_SendClientMessages();
    SV_CheckMapDifferences();
    SV_GatherStatistics();
    SV_ProcessSteamClientConnections();
  }
  return;
}


// SV_FullClientUpdate  @ 000a4cc8
void SV_FullClientUpdate(int param_1,undefined4 param_2)

{
  undefined1 local_170 [88];
  undefined1 local_118 [16];
  undefined1 local_108 [255];
  undefined1 local_9;
  int local_8;
  
  local_8 = (param_1 - DAT_00524284) * 0x614fb973 >> 2;
  Q_strncpy(local_108,param_1 + 0x4aa4,0xff);
  local_9 = 0;
  Info_RemovePrefixedKeys(local_108,0x5f);
  MSG_WriteByte(param_2,0xd);
  MSG_WriteByte(param_2,local_8);
  MSG_WriteLong(param_2,*(undefined4 *)(param_1 + 0x4a8c));
  MSG_WriteString(param_2,local_108);
  MD5Init(local_170);
  MD5Update(local_170,param_1 + 0x4bac,0x40);
  MD5Final(local_118,local_170);
  MSG_WriteBuf(param_2,0x10,local_118);
  return;
}


// SV_FullUpdate_f  @ 000bb80c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_FullUpdate_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    SV_ForceFullClientsUpdate();
    (*_DAT_0036af8c)(sv_player);
  }
  return;
}


// SV_GatherStatistics  @ 0009b4e4
void SV_GatherStatistics(void)

{
  int *local_1c;
  float local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if (realtime <= DAT_005242b8) {
    if ((byte)(realtime < DAT_005242c0 |
               (byte)((ushort)((ushort)(NAN(realtime) || NAN(DAT_005242c0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(realtime == DAT_005242c0) << 0xe) >> 8)) != 1) {
      DAT_005242c8 = DAT_005242c8 + 1;
      DAT_005242c0 = realtime + 60.0;
      SV_CountPlayers(&local_8);
      DAT_005242e4 = DAT_005242e4 + ((float)local_8 * 100.0) / (float)DAT_00524288;
      if (0 < DAT_005242c8) {
        DAT_005242e8 = DAT_005242e4 / (float)DAT_005242c8;
      }
      if (local_8 < DAT_005242dc) {
        DAT_005242dc = local_8;
      }
      else if (DAT_005242e0 < local_8) {
        DAT_005242e0 = local_8;
      }
      if (DAT_00524288 + -1 <= local_8) {
        DAT_005242cc = DAT_005242cc + 1;
      }
      if (local_8 < 2) {
        DAT_005242d0 = DAT_005242d0 + 1;
      }
      if (0 < DAT_005242c8) {
        DAT_005242d4 = ((float)DAT_005242cc * 100.0) / (float)DAT_005242c8;
        DAT_005242d8 = ((float)DAT_005242d0 * 100.0) / (float)DAT_005242c8;
      }
      local_14 = 0;
      local_18 = 0.0;
      local_1c = DAT_00524284;
      for (local_10 = 0; local_10 < DAT_00524288; local_10 = local_10 + 1) {
        if ((*local_1c != 0) && (local_1c[0x90e] == 0)) {
          local_14 = local_14 + 1;
          local_18 = local_18 + (float)local_1c[0x923];
        }
        local_1c = local_1c + 0x13bb;
      }
      if (local_14 == 0) {
        local_18 = 0.0;
      }
      else {
        local_18 = local_18 / (float)local_14;
      }
      DAT_005242f8 = DAT_005242f8 + local_18;
      if (0 < DAT_005242c8) {
        DAT_005242fc = DAT_005242f8 / (float)DAT_005242c8;
      }
      if (0 < DAT_005242ec) {
        DAT_005242f4 = DAT_005242f0 / (float)DAT_005242ec;
      }
    }
  }
  else {
    SV_CountPlayers(&local_8);
    DAT_005242b8 = realtime + 3600.0;
    Q_memset(&DAT_005242c8,0,0x38);
    DAT_005242e0 = local_8;
    DAT_005242dc = local_8;
  }
  return;
}


// SV_GetClientIDString  @ 000ae4b4
undefined1 * SV_GetClientIDString(int param_1)

{
  int iVar1;
  undefined1 local_20 [12];
  undefined1 local_14 [12];
  int *local_8;
  
  idstr_477 = 0;
  if ((param_1 != 0) && (local_8 = (int *)(param_1 + 0x4a90), local_8 != (int *)0x0)) {
    iVar1 = *local_8;
    if (iVar1 == 1) {
      Q_memset(local_14,0,0xc);
      iVar1 = memcmp(local_8 + 1,local_14,0xc);
      if ((iVar1 == 0) && (*(int *)(param_1 + 0x20) != 1)) {
        strcpy(&idstr_477,"STEAM_ID_PENDING");
      }
      else {
        if (*(int *)(param_1 + 0x20) == 1) {
          snprintf(&idstr_477,0x3f,"STEAM_ID_LOOPBACK");
        }
        else {
          snprintf(&idstr_477,0x3f,"STEAM_%u:%Lu",(uint)*(ushort *)(local_8 + 1),local_8[2],
                   local_8[3]);
        }
        DAT_0013a47f = 0;
      }
    }
    else {
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          sprintf(&idstr_477,"%u",*(undefined4 *)(param_1 + 0x4a94));
          goto LAB_000ae6f0;
        }
      }
      else if (iVar1 == 2) {
        Q_memset(local_20,0,0xc);
        iVar1 = memcmp(local_8 + 1,local_20,0xc);
        if ((iVar1 == 0) && (*(int *)(param_1 + 0x20) != 1)) {
          strcpy(&idstr_477,"VALVE_ID_PENDING");
        }
        else {
          if (*(int *)(param_1 + 0x20) == 1) {
            snprintf(&idstr_477,0x3f,"VALVE_ID_LOOPBACK");
          }
          else {
            snprintf(&idstr_477,0x3f,"VALVE_%u:%Lu",(uint)*(ushort *)(local_8 + 1),local_8[2],
                     local_8[3]);
          }
          DAT_0013a47f = 0;
        }
        goto LAB_000ae6f0;
      }
      strcpy(&idstr_477,"UNKNOWN");
    }
  }
LAB_000ae6f0:
  return &idstr_477;
}


// SV_GetFileNameModuleC  @ 000935cc
undefined1 * SV_GetFileNameModuleC(void)

{
  undefined1 local_11c;
  undefined1 local_11b;
  undefined1 local_11a;
  undefined1 local_119;
  undefined1 local_118;
  undefined1 local_117;
  undefined1 local_116;
  undefined1 local_115;
  undefined1 local_114;
  undefined1 local_113;
  undefined1 local_112;
  undefined1 local_111;
  undefined1 local_108 [260];
  
  local_11c = 0x4d;
  local_11b = 0x6f;
  local_11a = 100;
  local_119 = 0x75;
  local_118 = 0x6c;
  local_117 = 0x65;
  local_116 = 0x43;
  local_115 = 0x2e;
  local_114 = 100;
  local_113 = 0x6c;
  local_112 = 0x6c;
  local_111 = 0;
  COM_FileBase(&com_gamedir,local_108);
  snprintf(moduleFileName_7,0x103,"%s/%s",local_108,&local_11c);
  moduleFileName_7[0x103] = 0;
  return moduleFileName_7;
}


// SV_GetFileNameModuleS  @ 000934dc
undefined1 * SV_GetFileNameModuleS(void)

{
  undefined1 local_11c;
  undefined1 local_11b;
  undefined1 local_11a;
  undefined1 local_119;
  undefined1 local_118;
  undefined1 local_117;
  undefined1 local_116;
  undefined1 local_115;
  undefined1 local_114;
  undefined1 local_113;
  undefined1 local_112;
  undefined1 local_111;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  undefined1 local_10d;
  undefined1 local_108 [260];
  
  local_11c = 0x4d;
  local_11b = 0x6f;
  local_11a = 100;
  local_119 = 0x75;
  local_118 = 0x6c;
  local_117 = 0x65;
  local_116 = 0x53;
  local_115 = 0x5f;
  local_114 = 0x69;
  local_113 = 0x33;
  local_112 = 0x38;
  local_111 = 0x36;
  local_110 = 0x2e;
  local_10f = 0x73;
  local_10e = 0x6f;
  local_10d = 0;
  COM_FileBase(&com_gamedir,local_108);
  snprintf(moduleFileName_3,0x103,"%s/%s",local_108,&local_11c);
  moduleFileName_3[0x103] = 0;
  return moduleFileName_3;
}


// SV_GetFragmentSize  @ 0009f59c
int SV_GetFragmentSize(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[3] == 0)) || (param_1[2] == 0)) {
    iVar2 = 0x400;
  }
  else {
    uVar1 = Info_ValueForKey(param_1 + 0x12a9,"cl_dlmax");
    iVar2 = Q_strlen(uVar1);
    if (iVar2 == 0) {
      iVar2 = 0x80;
    }
    else {
      iVar2 = Q_atoi(uVar1);
      if (iVar2 < 0x40) {
        iVar2 = 0x40;
      }
      if (0x400 < iVar2) {
        iVar2 = 0x400;
      }
    }
  }
  return iVar2;
}


// SV_GetIDString  @ 000ae2e8
undefined1 * SV_GetIDString(int *param_1)

{
  int iVar1;
  undefined1 local_1c [12];
  undefined1 local_10 [12];
  
  idstr_473 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if (iVar1 == 1) {
      Q_memset(local_10,0,0xc);
      iVar1 = memcmp(param_1 + 1,local_10,0xc);
      if (iVar1 == 0) {
        strcpy(&idstr_473,"STEAM_ID_PENDING");
      }
      else {
        snprintf(&idstr_473,0x3f,"STEAM_%u:%Lu",(uint)*(ushort *)(param_1 + 1),param_1[2],param_1[3]
                );
        DAT_0013a43f = 0;
      }
    }
    else {
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          sprintf(&idstr_473,"%u",param_1[1]);
          goto LAB_000ae4a0;
        }
      }
      else if (iVar1 == 2) {
        Q_memset(local_1c,0,0xc);
        iVar1 = memcmp(param_1 + 1,local_1c,0xc);
        if (iVar1 == 0) {
          strcpy(&idstr_473,"VALVE_ID_PENDING");
        }
        else {
          snprintf(&idstr_473,0x3f,"VALVE_%u:%Lu",(uint)*(ushort *)(param_1 + 1),param_1[2],
                   param_1[3]);
          DAT_0013a43f = 0;
        }
        goto LAB_000ae4a0;
      }
      strcpy(&idstr_473,"UNKNOWN");
    }
  }
LAB_000ae4a0:
  return &idstr_473;
}


// SV_GetModInfo  @ 000a1d70
int SV_GetModInfo(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 param_7)

{
  if (gmodinfo == 0) {
    Q_strcpy(param_1,&DAT_000e86dc);
    Q_strcpy(param_2,&DAT_000e86dc);
    Q_strcpy(param_7,&DAT_000e86dc);
    *param_3 = 1;
    *param_4 = 0;
    *param_5 = 1;
    *param_6 = 0;
  }
  else {
    Q_strcpy(param_1,&DAT_0036ac64);
    Q_strcpy(param_2,&DAT_0036ad64);
    Q_strcpy(param_7,&DAT_0036ae64);
    *param_3 = DAT_0036ae84;
    *param_4 = DAT_0036ae88;
    *param_5 = DAT_0036ae8c;
    *param_6 = DAT_0036ae90;
  }
  return gmodinfo;
}


// SV_GetNetInfo  @ 000a62f4
void SV_GetNetInfo(int param_1,uint *param_2,uint *param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = (param_1 - DAT_00524284) * 0x614fb973 >> 2;
  if (*(double *)(param_1 + 0x249c) <= realtime) {
    *(double *)(param_1 + 0x249c) = realtime + 2.0;
    uVar1 = SV_CalcPing(param_1);
    *(undefined2 *)(lastping_300 + iVar2 * 2) = uVar1;
    lastloss_301[iVar2] = (char)(int)ROUND(*(float *)(param_1 + 0x2490));
  }
  *param_2 = (uint)*(ushort *)(lastping_300 + iVar2 * 2);
  *param_3 = (uint)(byte)lastloss_301[iVar2];
  return;
}


// SV_GetPlayerHulls  @ 0006e2f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_GetPlayerHulls(void)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while ((local_8 < 4 &&
         (iVar1 = (*_DAT_0036aff8)(local_8,player_mins + local_8 * 0xc,player_maxs + local_8 * 0xc),
         iVar1 != 0))) {
    local_8 = local_8 + 1;
  }
  return;
}


// SV_GetTrueMinMax  @ 000b9b0c
void SV_GetTrueMinMax(int param_1,int *param_2,int *param_3)

{
  if ((((((host_client[0x1376] != 0) && (host_client[0x1377] != 0)) &&
        ((byte)(0.0 < (float)sv_unlag._12_4_ |
                (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
       ((1 < DAT_00524288 && (*host_client != 0)))) &&
      ((-1 < param_1 &&
       ((param_1 < DAT_00524288 && (*(int *)(truepositions + param_1 * 0x58) != 0)))))) &&
     (*(int *)(truepositions + param_1 * 0x58 + 4) != 0)) {
    *param_2 = param_1 * 0x58 + 0x140c4c;
    *param_3 = param_1 * 0x58 + 0x140c58;
  }
  return;
}


// SV_GetTrueOrigin  @ 000b99cc
void SV_GetTrueOrigin(int param_1,undefined4 *param_2)

{
  if ((((((host_client[0x1376] != 0) && (host_client[0x1377] != 0)) &&
        ((byte)(0.0 < (float)sv_unlag._12_4_ |
                (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
       ((1 < DAT_00524288 && (*host_client != 0)))) &&
      ((-1 < param_1 &&
       ((param_1 < DAT_00524288 && (*(int *)(truepositions + param_1 * 0x58) != 0)))))) &&
     (*(int *)(truepositions + param_1 * 0x58 + 4) != 0)) {
    *param_2 = *(undefined4 *)(truepositions + param_1 * 0x58 + 0x14);
    param_2[1] = *(undefined4 *)(truepositions + param_1 * 0x58 + 0x18);
    param_2[2] = *(undefined4 *)(truepositions + param_1 * 0x58 + 0x1c);
  }
  return;
}


// SV_HandleRconPacket  @ 000accf0
void SV_HandleRconPacket(void)

{
  undefined4 uVar1;
  int iVar2;
  
  MSG_BeginReading();
  MSG_ReadLong();
  uVar1 = MSG_ReadStringLine();
  Cmd_TokenizeString(uVar1);
  uVar1 = Cmd_Argv(0);
  iVar2 = Q_strcmp(uVar1,"getchallenge");
  if (iVar2 == 0) {
    SVC_GetChallenge();
  }
  else {
    iVar2 = Q_stricmp(uVar1,"challenge");
    if (iVar2 == 0) {
      SVC_ServiceChallenge();
    }
    else {
      iVar2 = Q_strcmp(uVar1,&DAT_000e981f);
      if (iVar2 == 0) {
        SV_Rcon(&net_from);
      }
    }
  }
  return;
}


// SV_HasEventsInQueue  @ 000a6288
undefined4 SV_HasEventsInQueue(int param_1)

{
  int local_8;
  
  if (param_1 != 0) {
    for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
      if (*(short *)(param_1 + 0x3484 + local_8 * 0x58) != 0) {
        return 1;
      }
    }
  }
  return 0;
}


// SV_HashString  @ 0009c82c
uint SV_HashString(char *param_1,uint param_2)

{
  uint local_8;
  
  local_8 = 0;
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    local_8 = *(int *)(__ctype_tolower + *param_1 * 4) + local_8 * 2;
  }
  return local_8 % param_2;
}


// SV_HitgroupForStudioHull  @ 00092220
undefined4 SV_HitgroupForStudioHull(int param_1)

{
  return *(undefined4 *)(studio_hull_hitgroup + param_1 * 4);
}


// SV_HullForBeam  @ 000bdb2c
undefined4 * SV_HullForBeam(float *param_1,float *param_2,float *param_3)

{
  float local_10;
  float local_c;
  float local_8;
  
  beam_planes = *param_2 - *param_1;
  DAT_001418c4 = param_2[1] - param_1[1];
  DAT_001418c8 = param_2[2] - param_1[2];
  VectorNormalize(&beam_planes);
  DAT_001418d4 = beam_planes;
  DAT_001418d8 = DAT_001418c4;
  DAT_001418dc = DAT_001418c8;
  DAT_001418cc = param_2[2] * DAT_001418c8 + param_2[1] * DAT_001418c4 + *param_2 * beam_planes;
  DAT_001418e0 = param_1[2] * DAT_001418c8 + param_1[1] * DAT_001418c4 + *param_1 * beam_planes;
  if (0.9 <= ABS(DAT_001418c8)) {
    local_10 = 1.0;
    local_8 = 0.0;
  }
  else {
    local_8 = 1.0;
    local_10 = 0.0;
  }
  local_c = 0.0;
  CrossProduct(&beam_planes,&local_10,&DAT_001418e8);
  VectorNormalize(&DAT_001418e8);
  DAT_001418fc = DAT_001418e8;
  DAT_00141900 = DAT_001418ec;
  DAT_00141904 = DAT_001418f0;
  DAT_001418f4 = (param_1[2] + DAT_001418f0) * DAT_001418f0 +
                 (param_1[1] + DAT_001418ec) * DAT_001418ec +
                 (*param_1 + DAT_001418e8) * DAT_001418e8;
  local_10 = *param_1 - DAT_001418e8;
  local_c = param_1[1] - DAT_001418ec;
  local_8 = param_1[2] - DAT_001418f0;
  DAT_00141908 = local_8 * DAT_001418f0 + local_c * DAT_001418ec + local_10 * DAT_001418e8;
  CrossProduct(&DAT_001418e8,&beam_planes,&DAT_00141910);
  VectorNormalize(&DAT_00141910);
  DAT_00141924 = DAT_00141910;
  DAT_00141928 = DAT_00141914;
  DAT_0014192c = DAT_00141918;
  DAT_001418cc = ABS(DAT_001418c8 * param_3[2]) +
                 ABS(DAT_001418c4 * param_3[1]) + ABS(beam_planes * *param_3) + DAT_001418cc;
  DAT_001418e0 = DAT_001418e0 -
                 (ABS(DAT_001418dc * param_3[2]) +
                 ABS(DAT_001418d8 * param_3[1]) + ABS(DAT_001418d4 * *param_3));
  DAT_001418f4 = ABS(DAT_001418f0 * param_3[2]) +
                 ABS(DAT_001418ec * param_3[1]) + ABS(DAT_001418e8 * *param_3) + DAT_001418f4;
  DAT_00141908 = DAT_00141908 -
                 (ABS(DAT_00141904 * param_3[2]) +
                 ABS(DAT_00141900 * param_3[1]) + ABS(DAT_001418fc * *param_3));
  DAT_0014191c = ABS(DAT_00141918 * param_3[2]) +
                 ABS(DAT_00141914 * param_3[1]) + ABS(DAT_00141910 * *param_3) +
                 (param_1[2] + DAT_00141918) * DAT_00141918 +
                 (param_1[1] + DAT_00141914) * DAT_00141914 +
                 (*param_1 + DAT_00141910) * DAT_00141910;
  DAT_00141930 = ((param_1[2] - DAT_00141918) * DAT_00141918 +
                 (param_1[1] - DAT_00141914) * DAT_00141914 +
                 (*param_1 - DAT_00141910) * DAT_00141910) -
                 (ABS(DAT_00141918 * param_3[2]) +
                 ABS(DAT_00141914 * param_3[1]) + ABS(DAT_00141910 * *param_3));
  return &beam_hull;
}


// SV_HullForBox  @ 000bdabc
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


// SV_HullForBsp  @ 000bdfec
int SV_HullForBsp(int param_1,float *param_2,float *param_3,float *param_4)

{
  int iVar1;
  float fVar2;
  int local_c;
  
  iVar1 = *(int *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4);
  if (iVar1 == 0) {
    Sys_Error("Hit a %s with no model (%s)",pr_strings + *(int *)(param_1 + 0x80),
              pr_strings + *(int *)(param_1 + 0x138));
  }
  else if (*(int *)(iVar1 + 0x44) == 0) goto LAB_000be0c8;
  Sys_Error("Hit a %s with no model (%s)",pr_strings + *(int *)(param_1 + 0x80),
            pr_strings + *(int *)(param_1 + 0x138));
  Sys_Error("MOVETYPE_PUSH with a non bsp model");
LAB_000be0c8:
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
  *param_4 = *param_4 + *(float *)(param_1 + 0x88);
  param_4[1] = param_4[1] + *(float *)(param_1 + 0x8c);
  param_4[2] = param_4[2] + *(float *)(param_1 + 0x90);
  return local_c;
}


// SV_HullForEntity  @ 000be234
undefined4 SV_HullForEntity(int param_1,float *param_2,float *param_3,undefined4 *param_4)

{
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(param_1 + 0x18c) == 4) {
    if ((*(int *)(param_1 + 0x188) != 7) && (*(int *)(param_1 + 0x188) != 0xd)) {
      Sys_Error("SOLID_BSP without MOVETYPE_PUSH");
    }
    local_20 = SV_HullForBsp(param_1,param_2,param_3,param_4);
  }
  else {
    local_10 = *(float *)(param_1 + 0x15c) - *param_3;
    local_c = *(float *)(param_1 + 0x160) - param_3[1];
    local_8 = *(float *)(param_1 + 0x164) - param_3[2];
    local_1c = *(float *)(param_1 + 0x168) - *param_2;
    local_18 = *(float *)(param_1 + 0x16c) - param_2[1];
    local_14 = *(float *)(param_1 + 0x170) - param_2[2];
    local_20 = SV_HullForBox(&local_10,&local_1c);
    *param_4 = *(undefined4 *)(param_1 + 0x88);
    param_4[1] = *(undefined4 *)(param_1 + 0x8c);
    param_4[2] = *(undefined4 *)(param_1 + 0x90);
  }
  return local_20;
}


// SV_HullForStudioModel  @ 000924c0
undefined4
SV_HullForStudioModel
          (int param_1,float *param_2,float *param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  int local_8;
  
  local_8 = 0;
  local_1c = 0;
  local_18 = 0.5;
  local_14 = *param_3 - *param_2;
  local_10 = param_3[1] - param_2[1];
  local_c = param_3[2] - param_2[2];
  iVar1 = VectorCompare(&vec3_origin,&local_14);
  if (((iVar1 != 0) && ((DAT_0036b2a4 & 1) == 0)) &&
     (local_8 = 1, (*(uint *)(param_1 + 0x224) & 8) != 0)) {
    if ((byte)(0.0 < (float)sv_clienttrace._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_clienttrace._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_clienttrace._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)
    {
      local_8 = 0;
    }
    else {
      local_18 = (float)sv_clienttrace._12_4_ * 0.5;
      local_c = 1.0;
      local_10 = 1.0;
      local_14 = 1.0;
    }
  }
  if ((*(int *)(param_1 + 0x2b8) == 1) && (g_bIsCStrike == 1)) {
    local_1c = 1;
  }
  if (((*(uint *)(*(int *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4) + 0x50) & 0x200) == 0) &&
     (local_8 == 0)) {
    *param_5 = 1;
    uVar2 = SV_HullForEntity(param_1,param_2,param_3,param_4);
  }
  else {
    VectorScale(&local_14,local_18,&local_14);
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    if ((*(uint *)(param_1 + 0x224) & 8) == 0) {
      uVar2 = R_StudioHull(*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4),
                           *(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a8),
                           param_1 + 0xd0,param_1 + 0x88,&local_14,param_1 + 0x1bc,param_1 + 0x1c0,
                           param_5,param_1,local_1c);
    }
    else {
      pstudiohdr = Mod_Extradata(*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4));
      local_38 = *(undefined4 *)(param_1 + 0xd0);
      local_34 = *(undefined4 *)(param_1 + 0xd4);
      local_30 = *(undefined4 *)(param_1 + 0xd8);
      R_StudioPlayerBlend(*(int *)(param_1 + 0x1a8) * 0xb0 +
                          *(int *)(pstudiohdr + 0xa8) + pstudiohdr,local_3c,&local_38);
      local_3e = local_3c[0];
      local_3d = 0;
      local_44 = 0x7f;
      local_43 = 0x7f;
      local_42 = 0x7f;
      local_41 = 0x7f;
      uVar2 = R_StudioHull(*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4),
                           *(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a8),
                           &local_38,param_1 + 0x88,&local_14,&local_44,&local_3e,param_5,param_1,
                           local_1c);
    }
  }
  return uVar2;
}


// SV_HullPointContents  @ 000bee40
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


// SV_Impact  @ 000b1084
void SV_Impact(int param_1,int param_2,undefined4 param_3)

{
  gGlobalVariables = (float)DAT_0036bc6c;
  if (((*(uint *)(param_1 + 0x224) | *(uint *)(param_2 + 0x224)) & 0x40000000) != 0) {
    return;
  }
  if ((*(int *)(param_1 + 0x2c0) != 0) && (*(int *)(param_2 + 0x2c0) != 0)) {
    if (g_groupop == 0) {
      if ((*(uint *)(param_1 + 0x2c0) & *(uint *)(param_2 + 0x2c0)) == 0) {
        return;
      }
    }
    else if ((g_groupop == 1) && ((*(uint *)(param_1 + 0x2c0) & *(uint *)(param_2 + 0x2c0)) != 0)) {
      return;
    }
  }
  if (*(int *)(param_1 + 0x18c) != 0) {
    SV_SetGlobalTrace(param_3);
    (*DAT_0036af50)(param_1,param_2);
  }
  if (*(int *)(param_2 + 0x18c) != 0) {
    SV_SetGlobalTrace(param_3);
    (*DAT_0036af50)(param_2,param_1);
  }
  return;
}


// SV_InactivateClients  @ 000ac560
void SV_InactivateClients(void)

{
  int *local_c;
  int local_8;
  
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (((*local_c != 0) || (local_c[3] != 0)) || (local_c[1] != 0)) {
      if (local_c[0x90e] == 0) {
        *local_c = 0;
        local_c[3] = 1;
        local_c[1] = 0;
        local_c[2] = 0;
        SZ_Clear(local_c + 0x1d);
        SZ_Clear(local_c + 0x92b);
        COM_ClearCustomizationList(local_c + 0x134c,0);
        Q_memset(local_c + 0x1378,0,0x100);
      }
      else {
        SV_DropClient(local_c,0,"Dropping fakeclient on level change");
      }
    }
    local_c = local_c + 0x13bb;
  }
  return;
}


// SV_Init  @ 000ad5fc
void SV_Init(void)

{
  int iVar1;
  int local_8;
  
  Cmd_AddCommand("banid",SV_BanId_f);
  Cmd_AddCommand("removeid",SV_RemoveId_f);
  Cmd_AddCommand("listid",SV_ListId_f);
  Cmd_AddCommand("writeid",SV_WriteId_f);
  Cmd_AddCommand("resetrcon",SV_ResetRcon_f);
  Cmd_AddCommand("logaddress",SV_SetLogAddress_f);
  Cmd_AddCommand("logaddress_add",SV_AddLogAddress_f);
  Cmd_AddCommand("logaddress_del",SV_DelLogAddress_f);
  Cmd_AddCommand(&DAT_000e9bca,SV_ServerLog_f);
  Cmd_AddCommand("serverinfo",SV_Serverinfo_f);
  Cmd_AddCommand("localinfo",SV_Localinfo_f);
  Cmd_AddCommand("showinfo",SV_ShowServerinfo_f);
  Cmd_AddCommand(&DAT_000eb2ee,SV_User_f);
  Cmd_AddCommand("users",SV_Users_f);
  Cmd_AddCommand("dlfile",SV_BeginFileDownload_f);
  Cmd_AddCommand(FUN_000eb300,SV_AddIP_f);
  Cmd_AddCommand("removeip",SV_RemoveIP_f);
  Cmd_AddCommand("listip",SV_ListIP_f);
  Cmd_AddCommand("writeip",SV_WriteIP_f);
  Cmd_AddCommand("dropclient",SV_Drop_f);
  Cmd_AddCommand("spawn",SV_Spawn_f);
  Cmd_AddCommand(&DAT_000eb32f,SV_New_f);
  Cmd_AddCommand("sendres",SV_SendRes_f);
  Cmd_AddCommand("sendents",SV_SendEnts_f);
  Cmd_AddCommand("fullupdate",SV_FullUpdate_f);
  Cvar_RegisterVariable(sv_failuretime);
  Cvar_RegisterVariable(sv_voicecodec);
  Cvar_RegisterVariable(sv_voiceenable);
  Cvar_RegisterVariable(rcon_password);
  Cvar_RegisterVariable(mp_consistency);
  Cvar_RegisterVariable(sv_instancedbaseline);
  Cvar_RegisterVariable(sv_contact);
  Cvar_RegisterVariable(sv_unlag);
  Cvar_RegisterVariable(sv_maxunlag);
  Cvar_RegisterVariable(sv_unlagpush);
  Cvar_RegisterVariable(sv_unlagsamples);
  Cvar_RegisterVariable(sv_filterban);
  Cvar_RegisterVariable(sv_maxupdaterate);
  Cvar_RegisterVariable(sv_minupdaterate);
  Cvar_RegisterVariable(sv_logrelay);
  Cvar_RegisterVariable(sv_lan);
  Cvar_RegisterVariable(sv_lan_rate);
  Cvar_RegisterVariable(sv_proxies);
  Cvar_RegisterVariable(sv_visiblemaxplayers);
  Cvar_RegisterVariable(sv_password);
  Cvar_RegisterVariable(sv_aim);
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
  Cvar_RegisterVariable(sv_footsteps);
  Cvar_RegisterVariable(sv_accelerate);
  Cvar_RegisterVariable(sv_stepsize);
  Cvar_RegisterVariable(sv_clipmode);
  Cvar_RegisterVariable(sv_bounce);
  Cvar_RegisterVariable(sv_airmove);
  Cvar_RegisterVariable(sv_airaccelerate);
  Cvar_RegisterVariable(sv_wateraccelerate);
  Cvar_RegisterVariable(sv_waterfriction);
  Cvar_RegisterVariable(sv_skycolor_r);
  Cvar_RegisterVariable(sv_skycolor_g);
  Cvar_RegisterVariable(sv_skycolor_b);
  Cvar_RegisterVariable(sv_skyvec_x);
  Cvar_RegisterVariable(sv_skyvec_y);
  Cvar_RegisterVariable(sv_skyvec_z);
  Cvar_RegisterVariable(sv_timeout);
  Cvar_RegisterVariable(sv_clienttrace);
  Cvar_RegisterVariable(sv_zmax);
  Cvar_RegisterVariable(sv_wateramp);
  Cvar_RegisterVariable(sv_skyname);
  Cvar_RegisterVariable(sv_maxvelocity);
  Cvar_RegisterVariable(sv_cheats);
  iVar1 = COM_CheckParm(&DAT_000eb34f);
  if (iVar1 != 0) {
    Cvar_SetValue("sv_cheats",0x3f800000);
  }
  Cvar_RegisterVariable(sv_spectatormaxspeed);
  Cvar_RegisterVariable(sv_allow_download);
  Cvar_RegisterVariable(sv_allow_upload);
  Cvar_RegisterVariable(sv_send_logos);
  Cvar_RegisterVariable(sv_send_resources);
  Cvar_RegisterVariable(sv_logbans);
  Cvar_RegisterVariable(hpk_maxsize);
  Cvar_RegisterVariable(mapcyclefile);
  Cvar_RegisterVariable(motdfile);
  Cvar_RegisterVariable(servercfgfile);
  Cvar_RegisterVariable(lservercfgfile);
  Cvar_RegisterVariable(logsdir);
  Cvar_RegisterVariable(sv_rcon_minfailures);
  Cvar_RegisterVariable(sv_rcon_maxfailures);
  Cvar_RegisterVariable(sv_rcon_minfailuretime);
  Cvar_RegisterVariable(sv_rcon_banpenalty);
  Cvar_RegisterVariable(sv_minrate);
  Cvar_RegisterVariable(sv_maxrate);
  Cvar_RegisterVariable(max_queries_sec);
  Cvar_RegisterVariable(max_queries_sec_global);
  Cvar_RegisterVariable(max_queries_window);
  Cvar_RegisterVariable(sv_logblocks);
  for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
    snprintf(localmodels + local_8 * 5,5,(char *)FUN_000eb354,local_8);
  }
  Q_memset(&DAT_00524318,0,0x18);
  Q_memset(&DAT_00524300,0,0x18);
  Q_memset(&DAT_00524348,0,0x18);
  Q_memset(&DAT_00524330,0,0x18);
  DAT_00524368 = 0;
  DAT_00524360 = 0;
  DAT_00524364 = 0;
  for (local_8 = 0; local_8 < DAT_0052428c; local_8 = local_8 + 1) {
    iVar1 = DAT_00524284 + local_8 * 0x4eec;
    SV_ClearFrames(iVar1 + 0x3480);
    Q_memset(iVar1,0,0x4eec);
    *(int *)(iVar1 + 0x4c9c) = iVar1 + 0x4c18;
    *(int *)(iVar1 + 0x4c98) = iVar1 + 0x4c18;
    *(int *)(iVar1 + 0x4d24) = iVar1 + 0x4ca0;
    *(int *)(iVar1 + 0x4d20) = iVar1 + 0x4ca0;
  }
  PM_Init(g_svmove);
  SV_AllocClientFrames();
  SV_InitDeltas();
  DAT_0052436c = realtime;
  SteamInitializeUserIDTicketValidator(0,0,600,300,0x14,0x20,100);
  return;
}


// SV_InitBoxHull  @ 000bd928
void SV_InitBoxHull(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint local_8;
  
  box_hull = box_clipnodes;
  DAT_00141784 = box_planes;
  DAT_00141788 = 0;
  DAT_0014178c = 5;
  puVar2 = &box_hull;
  puVar3 = &beam_hull;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_001417c4 = &beam_planes;
  for (local_8 = 0; (int)local_8 < 6; local_8 = local_8 + 1) {
    *(uint *)(box_clipnodes + local_8 * 8) = local_8;
    *(undefined2 *)(box_clipnodes + (local_8 & 1) * 2 + local_8 * 8 + 4) = 0xffff;
    if (local_8 == 5) {
      box_clipnodes._44_2_ = 0xfffe;
    }
    else {
      *(short *)(box_clipnodes + (local_8 & 1 ^ 1) * 2 + local_8 * 8 + 4) = (short)local_8 + 1;
    }
    box_planes[local_8 * 0x14 + 0x10] = (char)((int)local_8 >> 1);
    *(undefined4 *)(box_planes + ((int)local_8 >> 1) * 4 + local_8 * 0x14) = 0x3f800000;
    (&DAT_001418d0)[local_8 * 0x14] = 5;
  }
  return;
}


// SV_InitDeltas  @ 000ad328
void SV_InitDeltas(void)

{
  Con_DPrintf("Initializing deltas\n");
  SV_RegisterDelta("clientdata_t","delta.lst");
  SV_RegisterDelta("entity_state_t","delta.lst");
  SV_RegisterDelta("entity_state_player_t","delta.lst");
  SV_RegisterDelta("custom_entity_state_t","delta.lst");
  SV_RegisterDelta("usercmd_t","delta.lst");
  SV_RegisterDelta("weapon_data_t","delta.lst");
  SV_RegisterDelta("event_t","delta.lst");
  g_pplayerdelta = SV_LookupDelta("entity_state_player_t");
  if (g_pplayerdelta == 0) {
    Sys_Error("No entity_state_player_t encoder on server!\n");
  }
  g_pentitydelta = SV_LookupDelta("entity_state_t");
  if (g_pentitydelta == 0) {
    Sys_Error("No entity_state_t encoder on server!\n");
  }
  g_pcustomentitydelta = SV_LookupDelta("custom_entity_state_t");
  if (g_pcustomentitydelta == 0) {
    Sys_Error("No custom_entity_state_t encoder on server!\n");
  }
  g_pclientdelta = SV_LookupDelta("clientdata_t");
  if (g_pclientdelta == 0) {
    Sys_Error("No clientdata_t encoder on server!\n");
  }
  g_pweapondelta = SV_LookupDelta("weapon_data_t");
  if (g_pweapondelta == 0) {
    Sys_Error("No weapon_data_t encoder on server!\n");
  }
  g_peventdelta = SV_LookupDelta("event_t");
  if (g_peventdelta == 0) {
    Sys_Error("No event_t encoder on server!\n");
  }
  return;
}


// SV_InitEncoders  @ 000ad57c
void SV_InitEncoders(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *local_c;
  
  for (local_c = g_sv_delta; local_c != (undefined4 *)0x0; local_c = (undefined4 *)*local_c) {
    iVar1 = local_c[3];
    iVar2 = Q_strlen(iVar1 + 8);
    if (0 < iVar2) {
      uVar3 = DELTA_LookupEncoder(iVar1 + 8);
      *(undefined4 *)(iVar1 + 0x28) = uVar3;
    }
  }
  return;
}


// SV_InitStudioHull  @ 0008ee48
void SV_InitStudioHull(void)

{
  uint local_8;
  
  if (studio_hull._4_4_ == 0) {
    for (local_8 = 0; (int)local_8 < 6; local_8 = local_8 + 1) {
      *(uint *)(studio_clipnodes + local_8 * 8) = local_8;
      *(undefined2 *)(studio_clipnodes + (local_8 & 1) * 2 + local_8 * 8 + 4) = 0xffff;
      if (local_8 == 5) {
        studio_clipnodes._44_2_ = 0xfffe;
      }
      else {
        *(short *)(studio_clipnodes + (local_8 & 1 ^ 1) * 2 + local_8 * 8 + 4) = (short)local_8 + 1;
      }
    }
    for (local_8 = 0; (int)local_8 < 0x80; local_8 = local_8 + 1) {
      *(undefined1 **)(studio_hull + local_8 * 0x28) = studio_clipnodes;
      *(undefined1 **)(studio_hull + local_8 * 0x28 + 4) = studio_planes + local_8 * 0x78;
      *(undefined4 *)(studio_hull + local_8 * 0x28 + 8) = 0;
      *(undefined4 *)(studio_hull + local_8 * 0x28 + 0xc) = 5;
    }
  }
  return;
}


// SV_InvokeCallback  @ 000a58d0
void SV_InvokeCallback(void)

{
  SV_WriteDeltaHeader(DAT_00524264,DAT_00524268,DAT_0052426c,g_svdeltacallback,DAT_00524270,
                      DAT_00524274,DAT_00524278,DAT_0052427c);
  return;
}


// SV_IsPlayerIndex  @ 0009b9a0
undefined4 SV_IsPlayerIndex(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 1) || (DAT_00524288 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// SV_IsSimulating  @ 000acff0
undefined4 SV_IsSimulating(void)

{
  undefined4 uVar1;
  
  if ((DAT_0036bc64 == 0) && ((1 < DAT_00524288 || ((key_dest == 0 && ((cls == 5 || (cls == 0)))))))
     ) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// SV_KickPlayer  @ 000ac1f4
void SV_KickPlayer(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char local_420;
  char local_41f [1023];
  int local_20;
  undefined4 local_1c [5];
  int local_8;
  
  if ((((-1 < param_1) && (param_1 < DAT_00524288)) &&
      (local_8 = DAT_00524284 + param_1 * 0x4eec, *(int *)(local_8 + 0xc) != 0)) &&
     (DAT_00524368 != 0)) {
    puVar4 = (undefined4 *)(local_8 + 0x4a90);
    puVar5 = local_1c;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    uVar1 = SV_GetIDString(local_1c);
    Log_Printf("Secure: \"%s<%i><%s><>\" was detected cheating and dropped from the server.\n",
               local_8 + 0x4bec,*(undefined4 *)(local_8 + 0x4a8c),uVar1,param_2);
    local_420 = '\b';
    sprintf(local_41f,
            "\n********************************************\nYou have been automatically disconnected\nfrom this secure server because an illegal\ncheat was detected on your computer.\nRepeat violators may be permanently banned\nfrom all secure servers.\n\nFor help cleaning your system of cheats, visit:\nhttp://www.counter-strike.net/cheat.html\n********************************************\n\n"
           );
    pcVar6 = &local_420;
    sVar2 = strlen(&local_420);
    Netchan_Transmit(DAT_00524284 + param_1 * 0x4eec + 0x1c,sVar2 + 1,pcVar6);
    sprintf(&local_420,"%s was automatically disconnected\nfrom this secure server.\n",
            DAT_00524284 + param_1 * 0x4eec + 0x4bec);
    for (local_20 = 0; local_20 < DAT_00524288; local_20 = local_20 + 1) {
      if (((*(int *)(DAT_00524284 + local_20 * 0x4eec) != 0) ||
          (*(int *)(DAT_00524284 + 4 + local_20 * 0x4eec) != 0)) &&
         (*(int *)(DAT_00524284 + 0x2438 + local_20 * 0x4eec) == 0)) {
        MSG_WriteByte(DAT_00524284 + local_20 * 0x4eec + 0x74,0x1a);
        MSG_WriteString(DAT_00524284 + local_20 * 0x4eec + 0x74,&local_420);
      }
    }
    SV_DropClient(DAT_00524284 + param_1 * 0x4eec,0,"Automatically dropped by cheat detector");
  }
  return;
}


// SV_LinkContents  @ 000bef5c
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
    if (local_8[0x61] != 0) goto LAB_000bf1b8;
    if (local_8[0xae] == 0) {
LAB_000bf010:
      if ((((*(int *)(&DAT_0039c5a8 + local_8[0x4b] * 4) != 0) &&
           (*(int *)(*(int *)(&DAT_0039c5a8 + local_8[0x4b] * 4) + 0x44) == 0)) &&
          (*param_2 <= (float)local_8[0x52])) &&
         ((param_2[1] <= (float)local_8[0x53] && (param_2[2] <= (float)local_8[0x54])))) {
        fVar1 = *param_2;
        fVar2 = (float)local_8[0x4f];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          fVar1 = param_2[1];
          fVar2 = (float)local_8[0x50];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            fVar1 = param_2[2];
            fVar2 = (float)local_8[0x51];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
              if ((local_8[0x62] < -100) || (100 < local_8[0x62])) {
                Con_DPrintf("Invalid contents on trigger field: %s\n",pr_strings + local_8[0x1e]);
              }
              local_18 = SV_HullForBsp(local_10,&vec3_origin,&vec3_origin,&local_24);
              local_30 = *param_2 - local_24;
              local_2c = param_2[1] - local_20;
              local_28 = param_2[2] - local_1c;
              iVar3 = SV_HullPointContents(local_18,*(undefined4 *)(local_18 + 8),&local_30);
              if (iVar3 != -1) {
                return local_10[100];
              }
              local_14 = 0xffffffff;
            }
          }
        }
      }
    }
    else if (g_groupop == 0) {
      if ((local_8[0xae] & g_groupmask) != 0) goto LAB_000bf010;
    }
    else if ((g_groupop != 1) || ((local_8[0xae] & g_groupmask) == 0)) goto LAB_000bf010;
LAB_000bf1b8:
    local_8 = local_c;
  } while( true );
}


// SV_LinkEdict  @ 000beb38
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_LinkEdict(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int local_c;
  int *local_8;
  
  if (param_1[2] != 0) {
    SV_UnlinkEdict(param_1);
  }
  if ((param_1 != DAT_003a78b8) && (*param_1 == 0)) {
    (*_DAT_0036af64)(param_1);
    if ((param_1[0x62] == 0xc) && (param_1[0x85] != 0)) {
      param_1[4] = *(int *)(param_1[0x85] + 0x10);
      param_1[5] = *(int *)(param_1[0x85] + 0x14);
      Q_memcpy(param_1 + 6,param_1[0x85] + 0x18,0x60);
    }
    else {
      param_1[5] = 0;
      param_1[4] = -1;
      local_c = -1;
      if (param_1[0x4d] != 0) {
        SV_FindTouchedLeafs(param_1,*(undefined4 *)(DAT_0036bd88 + 0xa4),&local_c);
      }
      if (0x30 < param_1[5]) {
        param_1[5] = 0;
        param_1[4] = local_c;
        Q_memset(param_1 + 6,0xff,0x60);
      }
    }
    if ((param_1[99] != 0) || (param_1[100] < -1)) {
      if ((param_1[99] == 4) &&
         ((*(int *)(&DAT_0039c5a8 + param_1[0x4d] * 4) == 0 &&
          (iVar3 = Q_strlen(pr_strings + param_1[0x4e]), iVar3 == 0)))) {
        Con_DPrintf("Inserted %s with no model\n",pr_strings + param_1[0x20]);
      }
      else {
        local_8 = &sv_areanodes;
        while (*local_8 != -1) {
          if ((float)param_1[*local_8 + 0x51] <= (float)local_8[1]) {
            fVar1 = (float)param_1[*local_8 + 0x54];
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
        if (param_1[99] == 1) {
          InsertLinkBefore(param_1 + 2,local_8 + 4);
        }
        else {
          InsertLinkBefore(param_1 + 2,local_8 + 6);
        }
        if ((param_2 != 0) && (iTouchLinkSemaphore_45 == 0)) {
          iTouchLinkSemaphore_45 = 1;
          SV_TouchLinks(param_1,&sv_areanodes);
          iTouchLinkSemaphore_45 = 0;
        }
      }
    }
  }
  return;
}


// SV_ListIP_f  @ 000abf50
void SV_ListIP_f(void)

{
  float fVar1;
  uint uVar2;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  int local_8;
  
  if (numipfilters < 1) {
    Con_Printf("IP filter list: empty\n");
  }
  else {
    Con_Printf("IP filter list:\n");
    for (local_8 = 0; local_8 < numipfilters; local_8 = local_8 + 1) {
      uVar2 = *(uint *)(ipfilters + local_8 * 0x10 + 4);
      fVar1 = *(float *)(ipfilters + local_8 * 0x10 + 0xc);
      uStack_b = (undefined1)(uVar2 >> 8);
      uStack_a = (undefined1)(uVar2 >> 0x10);
      uStack_9 = (undefined1)(uVar2 >> 0x18);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        Con_Printf("%3i.%3i.%3i.%3i : permanent\n",uVar2 & 0xff,uStack_b,uStack_a,uStack_9);
      }
      else {
        Con_Printf("%3i.%3i.%3i.%3i : %.3f min\n",uVar2 & 0xff,uStack_b,uStack_a,uStack_9,
                   (double)*(float *)(ipfilters + local_8 * 0x10 + 0xc));
      }
    }
  }
  return;
}


// SV_ListId_f  @ 000ab8d0
void SV_ListId_f(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  double dVar4;
  int local_8;
  
  if (numuserfilters < 1) {
    Con_Printf();
  }
  else {
    dVar4 = 2.040035825882238e-308;
    iVar3 = numuserfilters;
    Con_Printf();
    for (local_8 = 0; local_8 < numuserfilters; local_8 = local_8 + 1) {
      fVar1 = *(float *)(userfilters + local_8 * 0x1c + 0x18);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        SV_GetIDString(userfilters + local_8 * 0x1c,(int)((ulonglong)dVar4 >> 0x20),iVar3);
        iVar3 = local_8 + 1;
        dVar4 = 2.040141925671916e-308;
        Con_Printf();
      }
      else {
        dVar4 = (double)*(float *)(userfilters + local_8 * 0x1c + 0x18);
        uVar2 = SV_GetIDString(userfilters + local_8 * 0x1c);
        Con_Printf("%i %s : %.3f min\n",local_8 + 1,uVar2);
      }
    }
  }
  return;
}


// SV_LoadEntities  @ 000aa0dc
void SV_LoadEntities(void)

{
  ED_LoadFromFile(*(undefined4 *)(DAT_0036bd88 + 0x180));
  return;
}


// SV_LoadSecurityModules  @ 00093cbc
void SV_LoadSecurityModules(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  bVar6 = false;
  if ((DAT_00524368 != 0) && (gSecureUpdateState == 4)) {
    iVar1 = Q_memcmp(&DAT_00524320,&DAT_00524350,0x10);
    if ((iVar1 != 0) && (DAT_00524348 != 0)) {
      bVar6 = DAT_0052431c != 0;
      if (DAT_00524318 != 0) {
        Mem_Free(DAT_00524318);
      }
      puVar4 = &DAT_00524348;
      puVar5 = &DAT_00524318;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      Q_memset(&DAT_00524348,0,0x18);
    }
    iVar1 = Q_memcmp(&DAT_00524308,&DAT_00524338,0x10);
    if ((iVar1 != 0) && (DAT_00524330 != 0)) {
      if (DAT_00524304 != 0) {
        bVar6 = true;
      }
      SV_ReconnectAllClients();
      CloseSecurityModule();
      puVar4 = &DAT_00524330;
      puVar5 = &DAT_00524300;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar1 = 0x2f;
      pcVar2 = (char *)SV_GetFileNameModuleS();
      pcVar2 = strchr(pcVar2,iVar1);
      iVar1 = FS_Open(pcVar2,&DAT_000e7038);
      if (iVar1 != 0) {
        iVar3 = FS_Write(DAT_00524300,DAT_00524304,1,iVar1);
        FS_Close(iVar1);
        if (0 < iVar3) {
          LoadSecurityModuleFromDisk(pcVar2);
        }
        pcVar2 = (char *)SV_GetFileNameModuleS();
        unlink(pcVar2);
      }
      Mem_Free(DAT_00524300);
      DAT_00524300 = 0;
      Q_memset(&DAT_00524330,0,0x18);
    }
    if (g_module._16_4_ == 0) {
      SV_ServerNotSecure();
      DAT_00524368 = 0;
    }
    else {
      if (bVar6) {
        SV_SecureUpdateComplete();
      }
      gSecureUpdateState = 0;
    }
  }
  return;
}


// SV_Localinfo_f  @ 0009bcd0
void SV_Localinfo_f(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
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
        uVar5 = 0x8000;
        uVar3 = Cmd_Argv(2);
        uVar4 = Cmd_Argv(1);
        Info_SetValueForKey(localinfo,uVar4,uVar3,uVar5);
      }
    }
    else {
      Con_Printf("usage: localinfo [ <key> <value> ]\n");
    }
  }
  return;
}


// SV_LookupDelta  @ 0009b368
undefined4 SV_LookupDelta(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = g_sv_delta;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      Sys_Error("Couldn\'t find delta for %s\n",param_1);
      return 0;
    }
    iVar1 = Q_stricmp(param_1,local_8[1]);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)*local_8;
  }
  return local_8[3];
}


// SV_LookupSoundIndex  @ 0009c89c
int SV_LookupSoundIndex(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  iVar1 = SV_HashString(param_1,0x3ff);
  local_8 = iVar1;
  if (DAT_0039efa8 == 0) {
    if (DAT_003a78c4 == 1) {
      for (local_8 = 1; (local_8 < 0x200 && ((&DAT_0039dfa8)[local_8] != 0)); local_8 = local_8 + 1)
      {
        iVar1 = Q_strcasecmp(param_1,(&DAT_0039dfa8)[local_8]);
        if (iVar1 == 0) {
          return local_8;
        }
      }
      return 0;
    }
    SV_BuildHashedSoundLookupTable();
  }
  while( true ) {
    if (*(short *)(&DAT_0039e7a8 + local_8 * 2) == 0) {
      return 0;
    }
    iVar2 = Q_strcasecmp(param_1,(&DAT_0039dfa8)[*(short *)(&DAT_0039e7a8 + local_8 * 2)]);
    if (iVar2 == 0) break;
    local_8 = local_8 + 1;
    if (0x3fe < local_8) {
      local_8 = 0;
    }
    if (local_8 == iVar1) {
      return 0;
    }
  }
  return (int)*(short *)(&DAT_0039e7a8 + local_8 * 2);
}


// SV_ModelIndex  @ 000a7b50
int SV_ModelIndex(char *param_1)

{
  int iVar1;
  int local_8;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    local_8 = 0;
  }
  else {
    for (local_8 = 0; (local_8 < 0x200 && ((&DAT_0039bda8)[local_8] != 0)); local_8 = local_8 + 1) {
      iVar1 = Q_strcasecmp((&DAT_0039bda8)[local_8],param_1);
      if (iVar1 == 0) {
        return local_8;
      }
    }
    if ((local_8 == 0x200) || ((&DAT_0039bda8)[local_8] == 0)) {
      Sys_Error("SV_ModelIndex: model %s not precached",param_1);
    }
  }
  return local_8;
}


// SV_Move  @ 000c09cc
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
  undefined1 local_7c [12];
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
  
  Q_memset(local_88,0,0x84);
  SV_ClipMoveToEntity(local_d4,DAT_003a78b8,param_2,param_3,param_4,param_5);
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
    SV_MoveBounds(param_2,local_68,local_68 + 3,&local_98,local_88,local_7c);
    SV_ClipToLinks(&sv_areanodes,local_88);
    local_38 = local_38 * local_9c;
    if (local_18 == 0) {
      DAT_0036b294 = 0;
    }
    else {
      DAT_0036b294 = local_18;
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


// SV_MoveBounds  @ 000c0654
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


// SV_MoveNoEnts  @ 000c07e4
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
  undefined1 local_7c [12];
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
  
  Q_memset(local_88,0,0x84);
  SV_ClipMoveToEntity(local_d0,DAT_003a78b8,param_2,param_3,param_4,param_5);
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
    SV_MoveBounds(param_2,&local_68,&local_5c,&local_94,local_88,local_7c);
    SV_ClipToWorldbrush(&sv_areanodes,local_88);
    local_38 = local_38 * local_98;
    if (local_18 == 0) {
      DAT_0036b294 = 0;
    }
    else {
      DAT_0036b294 = local_18;
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


// SV_MoveToOnHandList  @ 000b5b28
void SV_MoveToOnHandList(int param_1)

{
  if (param_1 == 0) {
    Con_DPrintf("Null resource passed to SV_MoveToOnHandList\n");
  }
  else {
    SV_RemoveFromResourceList(param_1);
    SV_AddToResourceList(param_1,host_client + 0x4c18);
  }
  return;
}


// SV_MoveToOrigin_I  @ 000b0980
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
  if ((*(uint *)(param_1 + 0x224) & 0x203) != 0) {
    if (param_4 == 0) {
      iVar1 = SV_StepDirection(param_1,*(undefined4 *)(param_1 + 300),param_3,0xb098c);
      if (iVar1 == 0) {
        SV_NewChaseDir2(param_1,&local_10,param_3);
      }
    }
    else {
      local_1c = local_10 - *(float *)(param_1 + 0x88);
      local_18 = local_c - *(float *)(param_1 + 0x8c);
      local_14 = local_8 - *(float *)(param_1 + 0x90);
      if ((*(uint *)(param_1 + 0x224) & 3) == 0) {
        local_14 = 0.0;
      }
      VectorNormalize(&local_1c);
      VectorScale(&local_1c,param_3,&local_1c);
      SV_FlyDirection(param_1,&local_1c);
    }
  }
  return;
}


// SV_Multicast  @ 0009cca8
void SV_Multicast(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_14;
  int local_10;
  int *local_8;
  
  piVar1 = host_client;
  uVar2 = SV_PointLeafnum(param_2);
  if ((param_1 != 0) && ((host_client == (int *)0x0 || (host_client[0x12a1] != param_1)))) {
    local_8 = DAT_00524284;
    for (local_10 = 0; local_10 < DAT_00524288; local_10 = local_10 + 1) {
      if (local_8[0x12a1] == param_1) {
        host_client = local_8;
        break;
      }
      local_8 = local_8 + 0x13bb;
    }
  }
  local_10 = 0;
  local_8 = DAT_00524284;
  do {
    if (DAT_00524288 <= local_10) {
      SZ_Clear(&DAT_003a9830);
      host_client = piVar1;
      return;
    }
    if ((*local_8 == 0) || (((param_3 & 0x80) != 0 && (local_8 == host_client)))) goto LAB_0009cec7;
    if ((param_1 == 0) ||
       ((*(int *)(param_1 + 0x2c0) == 0 || (*(int *)(local_8[0x12a1] + 0x2c0) == 0)))) {
LAB_0009ce24:
      iVar3 = SV_ValidClientMulticast(local_8,uVar2,param_3);
      if (iVar3 == 0) {
        gPacketSuppressed = DAT_003a9840 + gPacketSuppressed;
      }
      else {
        if (param_4 == 0) {
          local_14 = local_8 + 0x92b;
        }
        else {
          local_14 = local_8 + 0x1d;
        }
        if (DAT_003a9840 < local_14[3] - local_14[4]) {
          SZ_Write(local_14,DAT_003a9838,DAT_003a9840);
        }
      }
    }
    else if (g_groupop == 0) {
      if ((*(uint *)(param_1 + 0x2c0) & *(uint *)(local_8[0x12a1] + 0x2c0)) != 0) goto LAB_0009ce24;
    }
    else if ((g_groupop != 1) ||
            ((*(uint *)(param_1 + 0x2c0) & *(uint *)(local_8[0x12a1] + 0x2c0)) == 0))
    goto LAB_0009ce24;
LAB_0009cec7:
    local_10 = local_10 + 1;
    local_8 = local_8 + 0x13bb;
  } while( true );
}


// SV_NewChaseDir  @ 000afe44
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
  float local_1c;
  float local_14;
  float local_10;
  
  lVar8 = (longdouble)anglemod((float)((int)ROUND(*(float *)(param_1 + 300) / 45.0) * 0x2d));
  fVar1 = (float)lVar8;
  lVar8 = (longdouble)anglemod(fVar1 - 180.0);
  fVar2 = (float)lVar8;
  fVar3 = *(float *)(param_2 + 0x88) - *(float *)(param_1 + 0x88);
  fVar4 = *(float *)(param_2 + 0x8c) - *(float *)(param_1 + 0x8c);
  if ((byte)(10.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 10.0) << 0xe) >> 8)) == 1) {
    local_14 = 0.0;
  }
  else if (-10.0 <= fVar3) {
    local_14 = -1.0;
  }
  else {
    local_14 = 180.0;
  }
  fVar5 = local_14;
  if (-10.0 <= fVar4) {
    if ((byte)(10.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 10.0) << 0xe) >> 8)) == 1) {
      local_10 = 90.0;
    }
    else {
      local_10 = -1.0;
    }
  }
  else {
    local_10 = 270.0;
  }
  if (((byte)(-1.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_14 == -1.0) << 0xe) >> 8)) != 0x40) &&
     ((byte)(-1.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_10 == -1.0) << 0xe) >> 8)) != 0x40)) {
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_10 == 90.0) << 0xe) >> 8)) == 0x40) {
        local_1c = 45.0;
      }
      else {
        local_1c = 315.0;
      }
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_10 == 90.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 135.0;
    }
    else {
      local_1c = 215.0;
    }
    if (((byte)(fVar2 < local_1c |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_1c)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_1c) << 0xe) >> 8)) != 0x40) &&
       (iVar6 = SV_StepDirection(param_1,local_1c,param_3), iVar6 != 0)) {
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
    if (iVar6 <= iVar7) goto LAB_000b00d6;
  }
  local_14 = local_10;
  local_10 = fVar5;
LAB_000b00d6:
  if ((((((byte)(-1.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_14 == -1.0) << 0xe) >> 8)) == 0x40) ||
        ((byte)(fVar2 < local_14 |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_14)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_14) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_14,param_3), iVar6 == 0)) &&
      ((((byte)(-1.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_10 == -1.0) << 0xe) >> 8)) == 0x40 ||
        ((byte)(fVar2 < local_10 |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_10)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_10) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_10,param_3), iVar6 == 0)))) &&
     (((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40 ||
      (iVar6 = SV_StepDirection(param_1,fVar1,param_3), iVar6 == 0)))) {
    iVar6 = RandomLong(0,1);
    if (iVar6 == 0) {
      local_1c = 315.0;
      while ((byte)((0.0 < local_1c | (byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
        if (((byte)(fVar2 < local_1c |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_1c)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_1c) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_1c,param_3), iVar6 != 0)) {
          return;
        }
        local_1c = local_1c - 45.0;
      }
    }
    else {
      for (local_1c = 0.0; local_1c <= 315.0; local_1c = local_1c + 45.0) {
        if (((byte)(fVar2 < local_1c |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_1c)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_1c) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_1c,param_3), iVar6 != 0)) {
          return;
        }
      }
    }
    if (((byte)(-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) == 0x40) ||
       (iVar6 = SV_StepDirection(param_1,fVar2,param_3), iVar6 == 0)) {
      *(float *)(param_1 + 300) = fVar1;
      iVar6 = SV_CheckBottom(param_1);
      if (iVar6 == 0) {
        SV_FixCheckBottom(param_1);
      }
    }
  }
  return;
}


// SV_NewChaseDir2  @ 000b0498
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
  float local_1c;
  float local_14;
  float local_10;
  
  lVar8 = (longdouble)anglemod((float)((int)ROUND(*(float *)(param_1 + 300) / 45.0) * 0x2d));
  fVar1 = (float)lVar8;
  lVar8 = (longdouble)anglemod(fVar1 - 180.0);
  fVar2 = (float)lVar8;
  fVar3 = *param_2 - *(float *)(param_1 + 0x88);
  fVar4 = param_2[1] - *(float *)(param_1 + 0x8c);
  if ((byte)(10.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 10.0) << 0xe) >> 8)) == 1) {
    local_14 = 0.0;
  }
  else if (-10.0 <= fVar3) {
    local_14 = -1.0;
  }
  else {
    local_14 = 180.0;
  }
  fVar5 = local_14;
  if (-10.0 <= fVar4) {
    if ((byte)(10.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 10.0) << 0xe) >> 8)) == 1) {
      local_10 = 90.0;
    }
    else {
      local_10 = -1.0;
    }
  }
  else {
    local_10 = 270.0;
  }
  if (((byte)(-1.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_14 == -1.0) << 0xe) >> 8)) != 0x40) &&
     ((byte)(-1.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_10 == -1.0) << 0xe) >> 8)) != 0x40)) {
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_10 == 90.0) << 0xe) >> 8)) == 0x40) {
        local_1c = 45.0;
      }
      else {
        local_1c = 315.0;
      }
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_10 == 90.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 135.0;
    }
    else {
      local_1c = 215.0;
    }
    if (((byte)(fVar2 < local_1c |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_1c)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_1c) << 0xe) >> 8)) != 0x40) &&
       (iVar6 = SV_StepDirection(param_1,local_1c,param_3), iVar6 != 0)) {
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
    if (iVar6 <= iVar7) goto LAB_000b0722;
  }
  local_14 = local_10;
  local_10 = fVar5;
LAB_000b0722:
  if ((((((byte)(-1.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_14 == -1.0) << 0xe) >> 8)) == 0x40) ||
        ((byte)(fVar2 < local_14 |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_14)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_14) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_14,param_3), iVar6 == 0)) &&
      ((((byte)(-1.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_10 == -1.0) << 0xe) >> 8)) == 0x40 ||
        ((byte)(fVar2 < local_10 |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_10)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_10) << 0xe) >> 8)) == 0x40)) ||
       (iVar6 = SV_StepDirection(param_1,local_10,param_3), iVar6 == 0)))) &&
     (((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40 ||
      (iVar6 = SV_StepDirection(param_1,fVar1,param_3), iVar6 == 0)))) {
    iVar6 = RandomLong(0,1);
    if (iVar6 == 0) {
      local_1c = 315.0;
      while ((byte)((0.0 < local_1c | (byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
        if (((byte)(fVar2 < local_1c |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_1c)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_1c) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_1c,param_3), iVar6 != 0)) {
          return;
        }
        local_1c = local_1c - 45.0;
      }
    }
    else {
      for (local_1c = 0.0; local_1c <= 315.0; local_1c = local_1c + 45.0) {
        if (((byte)(fVar2 < local_1c |
                    (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_1c)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == local_1c) << 0xe) >> 8)) != 0x40) &&
           (iVar6 = SV_StepDirection(param_1,local_1c,param_3), iVar6 != 0)) {
          return;
        }
      }
    }
    if (((byte)(-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) == 0x40) ||
       (iVar6 = SV_StepDirection(param_1,fVar2,param_3), iVar6 == 0)) {
      *(float *)(param_1 + 300) = fVar1;
      iVar6 = SV_CheckBottom(param_1);
      if (iVar6 == 0) {
        SV_FixCheckBottom(param_1);
      }
    }
  }
  return;
}


// SV_New_f  @ 0009eb98
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_New_f(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int aiStackY_1021c [2];
  char *pcStackY_10214;
  char *pcStackY_10210;
  char acStack_101e4 [64];
  char acStack_101a4 [256];
  char acStack_100a4 [128];
  int iStack_10024;
  char *pcStack_10020;
  undefined1 *puStack_10018;
  undefined4 uStack_10014;
  undefined4 uStack_10010;
  undefined1 auStack_1000c [65536];
  int *local_c;
  int local_8;
  
  pcStackY_10210 = (char *)0x9ebc3;
  Q_memset();
  pcStack_10020 = "New Connection";
  puStack_10018 = auStack_1000c;
  uStack_10010 = 0;
  uStack_10014 = 0x10000;
  if ((cmd_source != 1) && ((host_client[1] == 0 || (*host_client != 0)))) {
    iStack_10024 = host_client[0x12a1];
    host_client[3] = 1;
    *(undefined8 *)(host_client + 0xd18) = realtime;
    pcStackY_10210 = (char *)0x9ec71;
    SZ_Clear();
    pcStackY_10210 = (char *)0x9ec8b;
    SZ_Clear();
    pcStackY_10210 = (char *)0x9eca2;
    Netchan_Clear();
    pcStackY_10210 = (char *)0x9ecbd;
    SV_SendServerinfo();
    uVar1 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != 0) {
      sv_gpNewUserMsgs = sv_gpUserMsgs;
      pcStackY_10210 = (char *)0x9ecf8;
      SV_SendUserReg();
    }
    sv_gpNewUserMsgs = uVar1;
    host_client[5] = 1;
    if (((*host_client != 0) || (host_client[1] != 0)) && (host_client[0x12a1] != 0)) {
      pcStackY_10210 = (char *)0x9ed66;
      (*_DAT_0036af80)();
    }
    pcStackY_10210 = (char *)0x9ed8f;
    snprintf(acStack_101e4,0x40,"%s");
    piVar3 = host_client + 8;
    piVar4 = aiStackY_1021c;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    NET_AdrToString();
    pcStackY_10210 = (char *)0x9edd2;
    snprintf(acStack_101a4,0x100,"%s");
    pcStackY_10210 = (char *)0x9edf2;
    snprintf(acStack_100a4,0x80,"Connection rejected by game\n");
    pcStackY_10210 = (char *)0x9ee1c;
    iVar2 = (*_DAT_0036af7c)();
    if (iVar2 == 0) {
      pcStackY_10210 = (char *)0x9ee3b;
      MSG_WriteByte();
      pcStackY_10210 = acStack_100a4;
      pcStackY_10214 = "echo %s\n";
      aiStackY_1021c[1] = 0x9ee59;
      va();
      pcStackY_10210 = (char *)0x9ee70;
      MSG_WriteString();
      pcStackY_10210 = (char *)0x9ee93;
      SV_DropClient();
    }
    else {
      pcStackY_10210 = (char *)0x9eead;
      MSG_WriteByte();
      pcStackY_10210 = (char *)0x9eebb;
      pcStackY_10210 = (char *)Info_Serverinfo();
      pcStackY_10214 = "fullserverinfo \"%s\"\n";
      aiStackY_1021c[1] = 0x9eecc;
      va();
      pcStackY_10210 = (char *)0x9eede;
      MSG_WriteString();
      local_c = DAT_00524284;
      for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
        if (((local_c == host_client) || (*local_c != 0)) ||
           ((local_c[3] != 0 || (local_c[1] != 0)))) {
          pcStackY_10210 = (char *)0x9ef43;
          SV_FullClientUpdate();
        }
        local_c = local_c + 0x13bb;
      }
      pcStackY_10210 = (char *)0x9ef71;
      Netchan_CreateFragments();
      pcStackY_10210 = (char *)0x9ef88;
      Netchan_FragSend();
    }
  }
  return;
}


// SV_ParseConsistencyResponse  @ 000b63dc
void SV_ParseConsistencyResponse(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_200 [4];
  undefined4 uStack_1f0;
  float *pfStack_1ec;
  float *pfStack_1e8;
  code *pcStack_1e4;
  undefined1 *puStack_1e0;
  undefined1 local_1c4 [272];
  float *local_b4;
  uint local_b0;
  byte local_ac;
  undefined1 local_ab [12];
  float local_9f [4];
  float local_8c [8];
  undefined1 local_6c [32];
  float local_4c [6];
  float local_34 [3];
  float local_28 [3];
  int local_1c;
  undefined *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puStack_1e0 = (undefined1 *)0xb63ed;
  local_10 = 0;
  local_1c = 0;
  pcStack_1e4 = (code *)0x20;
  pfStack_1e8 = (float *)0x0;
  pfStack_1ec = local_8c;
  uStack_1f0 = 0xb6415;
  Q_memset();
  puStack_1e0 = (undefined1 *)0xb641d;
  pfStack_1e8 = (float *)MSG_ReadShort();
  pcStack_1e4 = (code *)DAT_00524290;
  pfStack_1ec = (float *)(DAT_0059d8c8 + msg_readcount);
  uStack_1f0 = 0xb6452;
  local_b4 = pfStack_1e8;
  COM_UnMunge();
  pfStack_1ec = (float *)&net_message;
  uStack_1f0 = 0xb6466;
  MSG_StartBitReading();
  do {
    pfStack_1ec = (float *)0x1;
    uStack_1f0 = 0xb6476;
    iVar3 = MSG_ReadBits();
    if (iVar3 == 0) {
LAB_000b68a4:
      pfStack_1ec = (float *)&net_message;
      uStack_1f0 = 0xb68b5;
      MSG_EndBitReading();
      if ((local_1c < 0) || (local_10 != DAT_0039bda4)) {
        msg_badread = 1;
        puVar4 = (undefined4 *)(host_client + 0x20);
        puVar5 = auStack_200;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        pcStack_1e4 = (code *)NET_AdrToString();
        pfStack_1e8 = (float *)(host_client + 0x4bec);
        pfStack_1ec = (float *)0xec1a0;
        uStack_1f0 = 0xb6926;
        Con_Printf();
        pcStack_1e4 = FUN_000ec1d8;
        pfStack_1e8 = (float *)0x0;
        pfStack_1ec = (float *)host_client;
        uStack_1f0 = 0xb6945;
        SV_DropClient();
      }
      else if (local_1c < 1) {
        *(undefined4 *)(host_client + 0x18) = 0;
      }
      else {
        local_1c4[0] = 0;
        pcStack_1e4 = (code *)local_1c4;
        pfStack_1e8 = (float *)(&DAT_0036bd18 + local_1c * 0x88);
        pfStack_1ec = *(float **)(host_client + 0x4a84);
        uStack_1f0 = 0xb69aa;
        iVar3 = (*DAT_0036b000)();
        if (iVar3 != 0) {
          pfStack_1ec = (float *)local_1c4;
          uStack_1f0 = 0xb69c2;
          iVar3 = Q_strlen();
          if (0 < iVar3) {
            pfStack_1e8 = (float *)local_1c4;
            pfStack_1ec = (float *)&DAT_000ec1e6;
            uStack_1f0 = 0xb69e3;
            SV_ClientPrintf();
          }
          puStack_1e0 = local_1c4;
          pfStack_1e8 = (float *)0x0;
          pfStack_1ec = (float *)host_client;
          uStack_1f0 = 0xb6a06;
          pcStack_1e4 = (code *)"Bad file %s";
          SV_DropClient();
        }
      }
      return;
    }
    pfStack_1ec = (float *)0xc;
    uStack_1f0 = 0xb648e;
    local_8 = MSG_ReadBits();
    if ((local_8 < 0) || (DAT_003965a0 <= local_8)) {
      local_1c = -1;
      goto LAB_000b68a4;
    }
    iVar3 = local_8 * 0x88;
    local_18 = &DAT_0036bda0 + iVar3;
    if (((&DAT_0036bdec)[iVar3] & 0x80) == 0) {
      local_1c = -1;
      goto LAB_000b68a4;
    }
    pcStack_1e4 = (code *)0x20;
    pfStack_1e8 = (float *)(&DAT_0036bdfe + iVar3);
    pfStack_1ec = (float *)local_6c;
    uStack_1f0 = 0xb6511;
    Q_memcpy();
    pcStack_1e4 = (code *)0x20;
    pfStack_1e8 = local_8c;
    pfStack_1ec = (float *)local_6c;
    uStack_1f0 = 0xb6529;
    iVar3 = Q_memcmp();
    if (iVar3 == 0) {
      pfStack_1ec = (float *)0x20;
      uStack_1f0 = 0xb653c;
      local_c = MSG_ReadBits();
      if (local_c != *(int *)(local_18 + 0x4d)) {
        local_1c = local_8 + 1;
      }
    }
    else {
      pfStack_1e8 = (float *)0xc;
      pfStack_1ec = local_4c + 3;
      uStack_1f0 = 0xb656a;
      MSG_ReadBitData();
      pfStack_1e8 = (float *)0xc;
      pfStack_1ec = local_4c;
      uStack_1f0 = 0xb657b;
      MSG_ReadBitData();
      pcStack_1e4 = (code *)0x20;
      pfStack_1e8 = (float *)(local_18 + 0x5e);
      pfStack_1ec = (float *)&local_ac;
      uStack_1f0 = 0xb6596;
      Q_memcpy();
      pcStack_1e4 = (code *)DAT_00524290;
      pfStack_1e8 = (float *)0x20;
      pfStack_1ec = (float *)&local_ac;
      uStack_1f0 = 0xb65b4;
      COM_UnMunge();
      local_b0 = (uint)local_ac;
      if (local_b0 == 2) {
        pcStack_1e4 = (code *)0xc;
        pfStack_1e8 = (float *)local_ab;
        pfStack_1ec = local_4c + 9;
        uStack_1f0 = 0xb6684;
        Q_memcpy();
        pcStack_1e4 = (code *)0xc;
        pfStack_1e8 = local_9f;
        pfStack_1ec = local_4c + 6;
        uStack_1f0 = 0xb669f;
        Q_memcpy();
        for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
          fVar1 = local_4c[local_14 + 3];
          fVar2 = local_4c[local_14 + 9];
          if (((byte)(fVar1 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
             (local_4c[local_14 + 6] < local_4c[local_14])) break;
        }
        if (local_14 < 3) {
          local_1c = local_8 + 1;
        }
      }
      else if (local_b0 < 3) {
        if (local_b0 == 1) {
          pcStack_1e4 = (code *)0xc;
          pfStack_1e8 = (float *)local_ab;
          pfStack_1ec = local_4c + 9;
          uStack_1f0 = 0xb660c;
          Q_memcpy();
          pcStack_1e4 = (code *)0xc;
          pfStack_1e8 = local_9f;
          pfStack_1ec = local_4c + 6;
          uStack_1f0 = 0xb6627;
          Q_memcpy();
          pfStack_1e8 = local_4c + 9;
          pfStack_1ec = local_4c + 3;
          uStack_1f0 = 0xb663a;
          iVar3 = VectorCompare();
          if (iVar3 != 0) {
            pfStack_1e8 = local_4c + 6;
            pfStack_1ec = local_4c;
            uStack_1f0 = 0xb6653;
            iVar3 = VectorCompare();
            if (iVar3 != 0) goto LAB_000b688c;
          }
          local_1c = local_8 + 1;
        }
        else {
LAB_000b6874:
          msg_badread = 1;
          local_1c = local_8 + 1;
        }
      }
      else {
        if (local_b0 != 3) goto LAB_000b6874;
        pcStack_1e4 = (code *)0xc;
        pfStack_1e8 = (float *)local_ab;
        pfStack_1ec = local_4c + 9;
        uStack_1f0 = 0xb6748;
        Q_memcpy();
        pcStack_1e4 = (code *)0xc;
        pfStack_1e8 = local_9f;
        pfStack_1ec = local_4c + 6;
        uStack_1f0 = 0xb6763;
        Q_memcpy();
        if ((((((byte)((byte)((ushort)((ushort)NAN(local_4c[3]) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_4c[3] == -1.0) << 0xe) >> 8)) != 0x40) ||
              ((byte)((byte)((ushort)((ushort)NAN(local_4c[4]) << 10) >> 8) |
                     (byte)((ushort)((ushort)(local_4c[4] == -1.0) << 0xe) >> 8)) != 0x40)) ||
             ((byte)((byte)((ushort)((ushort)NAN(local_4c[5]) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_4c[5] == -1.0) << 0xe) >> 8)) != 0x40)) ||
            (((byte)((byte)((ushort)((ushort)NAN(local_4c[0]) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_4c[0] == -1.0) << 0xe) >> 8)) != 0x40 ||
             ((byte)((byte)((ushort)((ushort)NAN(local_4c[1]) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_4c[1] == -1.0) << 0xe) >> 8)) != 0x40)))) ||
           ((byte)((byte)((ushort)((ushort)NAN(local_4c[2]) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_4c[2] == -1.0) << 0xe) >> 8)) != 0x40)) {
          for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
            fVar1 = local_4c[local_14 + 3];
            fVar2 = local_4c[local_14 + 9];
            if (((byte)(fVar1 < fVar2 |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
               (local_4c[local_14 + 6] < local_4c[local_14])) break;
          }
          if (local_14 < 3) {
            local_1c = local_8 + 1;
          }
        }
      }
    }
LAB_000b688c:
    if (msg_badread != 0) goto LAB_000b68a4;
    local_10 = local_10 + 1;
  } while( true );
}


// SV_ParseDelta  @ 000ba850
void SV_ParseDelta(void)

{
  undefined4 uVar1;
  
  uVar1 = MSG_ReadByte();
  *(undefined4 *)(host_client + 0x2434) = uVar1;
  return;
}


// SV_ParseMove  @ 000ba9b4
void SV_ParseMove(int param_1)

{
  double dVar1;
  double dVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int **ppiVar9;
  int *piVar10;
  int iStack_6e0;
  int *apiStack_6dc [2];
  int iStack_6d4;
  int iStack_6d0;
  int *piStack_6cc;
  int *piStack_6c8;
  int *piStack_6c4;
  undefined4 uStack_6c0;
  uint local_688;
  int local_678;
  undefined4 local_668 [13];
  float local_634;
  int local_630;
  int local_62c;
  int local_628;
  undefined4 *local_624;
  undefined4 *local_620;
  undefined4 local_61c;
  undefined4 local_618 [6];
  byte local_600;
  ushort local_5fe;
  undefined1 auStack_5fc [1528];
  
  uStack_6c0 = 0xba9c5;
  local_628 = 2;
  if (g_balreadymoved == 0) {
    g_balreadymoved = 1;
    iVar6 = host_client[0xd20] + (host_client[0x15] & SV_UPDATE_MASK) * 0x1810;
    piStack_6c4 = (int *)0x34;
    piStack_6c8 = (int *)0x0;
    piStack_6cc = local_668;
    iStack_6d0 = 0xbaa48;
    Q_memset();
    iVar7 = msg_readcount + 1;
    uStack_6c0 = 0xbaa5f;
    puVar5 = (undefined4 *)MSG_ReadByte();
    uStack_6c0 = 0xbaa6c;
    cVar3 = MSG_ReadByte();
    piStack_6c4 = (int *)host_client[0x14];
    piStack_6cc = (int *)(iVar7 + DAT_0059d8c8 + 1);
    iStack_6d0 = 0xbaaa5;
    piStack_6c8 = puVar5;
    COM_UnMunge();
    uStack_6c0 = 0xbaaad;
    local_688 = MSG_ReadByte();
    *(uint *)(param_1 + 0x4ee0) = local_688 >> 7 & 1;
    local_688 = local_688 & 0xffffff7f;
    local_634 = (float)(int)local_688;
    uStack_6c0 = 0xbaae4;
    local_628 = MSG_ReadByte();
    uStack_6c0 = 0xbaaf1;
    local_62c = MSG_ReadByte();
    local_630 = local_62c + local_628;
    net_drop = (net_drop + 1) - local_62c;
    if ((local_630 < 0) || (0x1c < local_630)) {
      piVar8 = host_client + 8;
      ppiVar9 = apiStack_6dc;
      for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppiVar9 = (int *)*piVar8;
        piVar8 = piVar8 + 1;
        ppiVar9 = ppiVar9 + 1;
      }
      iStack_6e0 = 0xbab60;
      uStack_6c0 = NET_AdrToString();
      piStack_6c4 = host_client + 0x12fb;
      piStack_6c8 = (int *)local_630;
      piStack_6cc = (int *)0xec440;
      iStack_6d0 = 0xbab8a;
      Con_Printf();
      piStack_6c4 = (int *)0xec477;
      piStack_6c8 = (int *)0x0;
      piStack_6cc = host_client;
      iStack_6d0 = 0xbaba9;
      SV_DropClient();
      msg_badread = 1;
    }
    else {
      local_620 = local_668;
      local_678 = local_630;
      while (local_678 = local_678 + -1, -1 < local_678) {
        piStack_6cc = &local_61c + local_678 * 0xd;
        piStack_6c8 = local_620;
        iStack_6d0 = 0xbac25;
        local_624 = piStack_6cc;
        MSG_ReadUsercmd();
        local_620 = local_624;
      }
      if ((sv != 0) && ((*host_client != 0 || (host_client[1] != 0)))) {
        if (msg_badread == 0) {
          piStack_6c4 = (int *)host_client[0x14];
          piStack_6c8 = (int *)((msg_readcount - iVar7) + -1);
          piStack_6cc = (int *)(iVar7 + DAT_0059d8c8 + 1);
          iStack_6d0 = 0xbad08;
          cVar4 = COM_BlockSequenceCRCByte();
          if (cVar4 == cVar3) {
            host_client[0x924] = (int)local_634;
            if ((DAT_0036bc64 == 0) &&
               (((1 < DAT_00524288 || (key_dest == 0)) &&
                ((*(uint *)(sv_player + 0x224) & 0x1000) == 0)))) {
              *(undefined4 *)(sv_player + 0xf4) = local_618[0];
              *(undefined4 *)(sv_player + 0xf8) = local_618[1];
              *(undefined4 *)(sv_player + 0xfc) = local_618[2];
            }
            else {
              for (local_678 = 0; local_678 < local_62c; local_678 = local_678 + 1) {
                *(undefined1 *)((int)&local_61c + local_678 * 0x34 + 2) = 0;
                local_618[local_678 * 0xd + 3] = 0;
                local_618[local_678 * 0xd + 4] = 0;
                local_618[local_678 * 0xd + 5] = 0;
                *(undefined2 *)(auStack_5fc + local_678 * 0x34 + -2) = 0;
                if ((*(uint *)(sv_player + 0x224) & 0x1000) != 0) {
                  auStack_5fc[local_678 * 0x34] = 0;
                }
                local_618[local_678 * 0xd] = *(undefined4 *)(sv_player + 0xf4);
                local_618[local_678 * 0xd + 1] = *(undefined4 *)(sv_player + 0xf8);
                local_618[local_678 * 0xd + 2] = *(undefined4 *)(sv_player + 0xfc);
              }
              net_drop = 0;
            }
            *(uint *)(sv_player + 0x200) = (uint)local_5fe;
            *(uint *)(sv_player + 0x1a4) = (uint)local_600;
            piStack_6cc = (int *)local_62c;
            iStack_6d0 = local_628;
            iStack_6d4 = net_drop;
            apiStack_6dc[1] = &local_61c;
            apiStack_6dc[0] = host_client;
            iStack_6e0 = 0xbb03b;
            SV_EstablishTimeBase();
            uStack_6c0 = 0xbb043;
            SV_PreRunCmd();
            local_678 = local_62c;
            if (net_drop < 0x18) {
              for (; local_628 < net_drop; net_drop = net_drop + -1) {
                piStack_6c8 = (int *)0x0;
                piStack_6cc = host_client + 0x910;
                iStack_6d0 = 0xbb091;
                SV_RunCmd();
              }
              for (; local_678 = local_62c, 0 < net_drop; net_drop = net_drop + -1) {
                iVar7 = local_62c + net_drop + -1;
                piStack_6c8 = (int *)(host_client[0x14] - iVar7);
                piStack_6cc = &local_61c + iVar7 * 0xd;
                iStack_6d0 = 0xbb10d;
                SV_RunCmd();
              }
            }
            while (local_678 = local_678 + -1, -1 < local_678) {
              piStack_6c8 = (int *)(host_client[0x14] - local_678);
              piStack_6cc = &local_61c + local_678 * 0xd;
              iStack_6d0 = 0xbb177;
              SV_RunCmd();
            }
            piVar8 = &local_61c;
            piVar10 = host_client + 0x910;
            for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
              *piVar10 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar10 = piVar10 + 1;
            }
            *(float *)(iVar6 + 8) =
                 *(float *)(iVar6 + 8) -
                 ((float)*(byte *)((int)host_client + 0x2442) * 0.5) / 1000.0;
            if (*(float *)(iVar6 + 8) < 0.0) {
              *(undefined4 *)(iVar6 + 8) = 0;
            }
            dVar2 = (double)*(float *)(sv_player + 0x1b4);
            dVar1 = DAT_0036bc6c + host_frametime;
            if ((byte)(dVar1 < dVar2 |
                       (byte)((ushort)((ushort)(NAN(dVar1) || NAN(dVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar1 == dVar2) << 0xe) >> 8)) == 1) {
              *(float *)(sv_player + 0x1b4) =
                   (float)((longdouble)DAT_0036bc6c + (longdouble)host_frametime);
            }
          }
          else {
            piVar8 = host_client + 8;
            piVar10 = &iStack_6e0;
            for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
              *piVar10 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar10 = piVar10 + 1;
            }
            piStack_6c4 = (int *)NET_AdrToString();
            piStack_6c8 = host_client + 0x12fb;
            piStack_6cc = (int *)0xec4e0;
            iStack_6d0 = 0xbad67;
            Con_DPrintf();
            msg_badread = 1;
          }
        }
        else {
          piVar8 = host_client + 8;
          piVar10 = &iStack_6e0;
          for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar10 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar10 = piVar10 + 1;
          }
          piStack_6c4 = (int *)NET_AdrToString();
          piStack_6c8 = host_client + 0x12fb;
          piStack_6cc = (int *)0xec4a0;
          iStack_6d0 = 0xbacbd;
          Con_Printf();
        }
      }
    }
  }
  else {
    msg_badread = 1;
  }
  return;
}


// SV_ParseResourceList  @ 000b6054
void SV_ParseResourceList(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  double dVar4;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = MSG_ReadShort();
  SV_ClearResourceList(host_client + 0x4ca0);
  SV_ClearResourceList(host_client + 0x4c18);
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    local_14 = Mem_ZeroMalloc(0x88);
    uVar2 = MSG_ReadString();
    Q_strncpy(local_14,uVar2);
    *(undefined1 *)(local_14 + 0x3f) = 0;
    uVar2 = MSG_ReadByte();
    *(undefined4 *)(local_14 + 0x40) = uVar2;
    uVar2 = MSG_ReadShort();
    *(undefined4 *)(local_14 + 0x44) = uVar2;
    uVar2 = MSG_ReadLong();
    *(undefined4 *)(local_14 + 0x48) = uVar2;
    uVar1 = MSG_ReadByte();
    *(undefined1 *)(local_14 + 0x4c) = uVar1;
    *(undefined4 *)(local_14 + 0x80) = 0;
    *(undefined4 *)(local_14 + 0x84) = 0;
    *(byte *)(local_14 + 0x4c) = *(byte *)(local_14 + 0x4c) & 0xfd;
    if ((*(byte *)(local_14 + 0x4c) & 4) != 0) {
      MSG_ReadBuf(0x10,local_14 + 0x4d);
    }
    SV_AddToResourceList(local_14,host_client + 0x4ca0);
  }
  if ((byte)(0.0 < (float)sv_allow_upload._12_4_ |
             (byte)((ushort)((ushort)NAN((float)sv_allow_upload._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_allow_upload._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    Con_DPrintf("Verifying and uploading resources...\n");
  }
  local_10 = COM_SizeofResourceList(host_client + 0x4ca0,&local_34);
  if ((local_10 != 0) &&
     ((byte)(0.0 < (float)sv_allow_upload._12_4_ |
             (byte)((ushort)((ushort)NAN((float)sv_allow_upload._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_allow_upload._12_4_ == 0.0) << 0xe) >> 8)) != 0x40))
  {
    dVar4 = (double)local_10 / 1024.0;
    Con_DPrintf("Custom resources total %.2fK\n",dVar4);
    if (local_2c != 0) {
      dVar4 = (double)local_2c / 1024.0;
      Con_DPrintf("  Models:  %.2fK\n",dVar4);
    }
    if (local_34 != 0) {
      dVar4 = (double)local_34 / 1024.0;
      Con_DPrintf("  Sounds:  %.2fK\n",dVar4);
    }
    if (local_28 != 0) {
      dVar4 = (double)local_28 / 1024.0;
      Con_DPrintf("  Decals:  %.2fK\n",dVar4);
    }
    if (local_30 != 0) {
      dVar4 = (double)local_30 / 1024.0;
      Con_DPrintf("  Skins :  %.2fK\n",dVar4);
    }
    if (local_24 != 0) {
      dVar4 = (double)local_24 / 1024.0;
      Con_DPrintf("  Generic :  %.2fK\n",dVar4);
    }
    if (local_20 != 0) {
      dVar4 = (double)local_20 / 1024.0;
      Con_DPrintf("  Events  :  %.2fK\n",dVar4);
    }
    Con_DPrintf("----------------------\n",dVar4);
    iVar3 = SV_EstimateNeededResources();
    if (iVar3 < 0x401) {
      Con_DPrintf("Resources to request: %i bytes\n",iVar3);
    }
    else {
      Con_DPrintf(FUN_000ebfe0,(double)((float)iVar3 / 1024.0));
    }
  }
  *(undefined4 *)(host_client + 0x10) = 1;
  *(undefined4 *)(host_client + 0x4d2c) = 0;
  SV_BatchUploadRequest(host_client);
  return;
}


// SV_ParseStringCommand  @ 000ba78c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ParseStringCommand(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MSG_ReadString();
  iVar2 = SV_ValidateClientCommand(iVar1);
  if (iVar2 == 1) {
    Cmd_ExecuteString(iVar1,0);
  }
  else if (iVar2 == 2) {
    Cbuf_InsertText(iVar1);
  }
  else {
    iVar2 = Q_strlen(iVar1);
    if (0x7f < iVar2) {
      *(undefined1 *)(iVar1 + 0x7f) = 0;
    }
    Cmd_TokenizeString(iVar1);
    (*_DAT_0036af8c)(sv_player);
  }
  return;
}


// SV_ParseVoiceData  @ 000bb25c
void SV_ParseVoiceData(int *param_1)

{
  int *piVar1;
  bool bVar2;
  uint local_101c;
  undefined1 local_1010 [4096];
  uint local_10;
  uint local_c;
  int local_8;
  
  local_c = ((int)param_1 - DAT_00524284) * 0x614fb973 >> 2;
  local_10 = MSG_ReadShort();
  if (local_10 < 0x1001) {
    MSG_ReadBuf(local_10,local_1010);
    if ((byte)((byte)((ushort)((ushort)NAN((float)sv_voiceenable._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_voiceenable._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
    {
      for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
        piVar1 = (int *)(DAT_00524284 + local_8 * 0x4eec);
        bVar2 = piVar1 == param_1;
        if ((((1 << ((byte)local_8 & 0x1f) & param_1[(local_8 >> 5) + 0x13b9]) != 0) || (bVar2)) &&
           ((*piVar1 != 0 || ((piVar1[3] != 0 || (bVar2)))))) {
          local_101c = local_10;
          if ((bVar2) && (piVar1[0x13b8] == 0)) {
            local_101c = 0;
          }
          if ((int)(piVar1[0x92f] + 6 + local_10) < piVar1[0x92e]) {
            MSG_WriteByte(piVar1 + 0x92b,0x35);
            MSG_WriteByte(piVar1 + 0x92b,local_c & 0xff);
            MSG_WriteShort(piVar1 + 0x92b,local_101c);
            MSG_WriteBuf(piVar1 + 0x92b,local_101c,local_1010);
          }
        }
      }
    }
  }
  else {
    Host_Error("SV_ParseVoiceData: invalid incoming packet.\n");
  }
  return;
}


// SV_Physics  @ 000b4f30
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_Physics(void)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  gGlobalVariables = (float)DAT_0036bc6c;
  (*DAT_0036afa4)();
  for (local_8 = 0; local_8 < DAT_003a78b0; local_8 = local_8 + 1) {
    piVar2 = (int *)(DAT_003a78b8 + local_8 * 0x324);
    if (*piVar2 == 0) {
      if ((byte)(0.0 < DAT_0036b228 | (byte)((ushort)((ushort)NAN(DAT_0036b228) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_0036b228 == 0.0) << 0xe) >> 8)) != 0x40) {
        SV_LinkEdict(piVar2,1);
      }
      if ((local_8 < 1) || (DAT_00524288 < local_8)) {
        if (((piVar2[0x89] & 0x200U) != 0) &&
           ((iVar1 = piVar2[0x87], iVar1 != 0 && ((*(uint *)(iVar1 + 0x224) & 4) != 0)))) {
          if ((piVar2[0x89] & 0x400000U) == 0) {
            VectorScale(iVar1 + 0xc4,*(undefined4 *)(iVar1 + 0x278),piVar2 + 0x2b);
          }
          else {
            VectorMA(piVar2 + 0x2b,*(undefined4 *)(iVar1 + 0x278),iVar1 + 0xc4,piVar2 + 0x2b);
          }
          piVar2[0x89] = piVar2[0x89] | 0x400000;
        }
        if ((piVar2[0x89] & 0x400000U) == 0) {
          VectorMA(piVar2 + 0x28,
                   (float)((longdouble)1 + (longdouble)_FUN_000ebc60 * (longdouble)host_frametime),
                   piVar2 + 0x2b,piVar2 + 0x28);
          piVar2[0x2b] = vec3_origin;
          piVar2[0x2c] = DAT_000f1be0;
          piVar2[0x2d] = DAT_000f1be4;
        }
        piVar2[0x89] = piVar2[0x89] & 0xffbfffff;
        if (piVar2[0x62] == 7) {
          SV_Physics_Pusher(piVar2);
        }
        else if (piVar2[0x62] == 0) {
          SV_Physics_None(piVar2);
        }
        else if (piVar2[0x62] == 0xc) {
          SV_Physics_Follow(piVar2);
        }
        else if (piVar2[0x62] == 8) {
          SV_Physics_Noclip(piVar2);
        }
        else if (piVar2[0x62] == 4) {
          SV_Physics_Step(piVar2);
        }
        else if (piVar2[0x62] == 0xd) {
          SV_Physics_Step(piVar2);
        }
        else if ((((piVar2[0x62] == 6) || (piVar2[0x62] == 10)) || (piVar2[0x62] == 0xb)) ||
                ((piVar2[0x62] == 5 || (piVar2[0x62] == 9)))) {
          SV_Physics_Toss(piVar2);
        }
        else {
          Sys_Error("SV_Physics: %s bad movetype %d",pr_strings + piVar2[0x20],piVar2[0x62]);
        }
        if ((piVar2[0x89] & 0x40000000U) != 0) {
          ED_Free(piVar2);
        }
      }
    }
  }
  if ((byte)(0.0 < DAT_0036b228 | (byte)((ushort)((ushort)NAN(DAT_0036b228) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_0036b228 == 0.0) << 0xe) >> 8)) != 0x40) {
    DAT_0036b228 = DAT_0036b228 - 1.0;
  }
  return;
}


// SV_Physics_Follow  @ 000b36b4
void SV_Physics_Follow(int param_1)

{
  int iVar1;
  
  iVar1 = SV_RunThink(param_1);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x214) == 0) {
      Con_DPrintf("%s movetype FOLLOW with NULL aiment\n",pr_strings + *(int *)(param_1 + 0x80));
      *(undefined4 *)(param_1 + 0x188) = 0;
    }
    else {
      *(float *)(param_1 + 0x88) =
           *(float *)(*(int *)(param_1 + 0x214) + 0x88) + *(float *)(param_1 + 0xf4);
      *(float *)(param_1 + 0x8c) =
           *(float *)(*(int *)(param_1 + 0x214) + 0x8c) + *(float *)(param_1 + 0xf8);
      *(float *)(param_1 + 0x90) =
           *(float *)(*(int *)(param_1 + 0x214) + 0x90) + *(float *)(param_1 + 0xfc);
      *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(*(int *)(param_1 + 0x214) + 0xd0);
      *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(*(int *)(param_1 + 0x214) + 0xd4);
      *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(*(int *)(param_1 + 0x214) + 0xd8);
      SV_LinkEdict(param_1,1);
    }
  }
  return;
}


// SV_Physics_Noclip  @ 000b37f4
void SV_Physics_Noclip(int param_1)

{
  int iVar1;
  
  iVar1 = SV_RunThink(param_1);
  if (iVar1 != 0) {
    VectorMA(param_1 + 0xd0,(float)host_frametime,param_1 + 0xdc,param_1 + 0xd0);
    VectorMA(param_1 + 0x88,(float)host_frametime,param_1 + 0xa0,param_1 + 0x88);
    SV_LinkEdict(param_1,0);
  }
  return;
}


// SV_Physics_None  @ 000b3688
void SV_Physics_None(undefined4 param_1)

{
  SV_RunThink(param_1);
  return;
}


// SV_Physics_Pusher  @ 000b2f9c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_Physics_Pusher(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float local_10;
  
  fVar1 = *(float *)(param_1 + 0x180);
  fVar2 = *(float *)(param_1 + 0x184);
  if (*(float *)(param_1 + 0x180) + (float)host_frametime <= fVar2) {
    local_10 = (float)host_frametime;
  }
  else {
    local_10 = fVar2 - *(float *)(param_1 + 0x180);
    if (local_10 < 0.0) {
      local_10 = 0.0;
    }
  }
  if ((byte)(0.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xdc)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0xdc) == 0.0) << 0xe) >> 8)) == 0x40)
        && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xe0)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(param_1 + 0xe0) == 0.0) << 0xe) >> 8)) == 0x40
           )) && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xe4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(*(float *)(param_1 + 0xe4) == 0.0) << 0xe) >> 8))
                  == 0x40)) {
      SV_PushMove(param_1,local_10);
    }
    else if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa0)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa0) == 0.0) << 0xe) >> 8)) ==
               0x40) &&
             ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa4)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa4) == 0.0) << 0xe) >> 8)) ==
              0x40)) &&
            ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa8)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa8) == 0.0) << 0xe) >> 8)) ==
             0x40)) {
      SV_PushRotate(param_1,local_10);
    }
    else {
      iVar5 = SV_PushRotate(param_1,local_10);
      if (iVar5 != 0) {
        fVar3 = *(float *)(param_1 + 0x180);
        *(float *)(param_1 + 0x180) = fVar1;
        SV_PushMove(param_1,local_10);
        fVar4 = *(float *)(param_1 + 0x180);
        if ((byte)(fVar4 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == fVar3) << 0xe) >> 8)) == 1) {
          *(float *)(param_1 + 0x180) = fVar3;
        }
      }
    }
  }
  if ((fVar1 < fVar2) &&
     (((*(uint *)(param_1 + 0x224) & 0x200000) != 0 ||
      (fVar1 = *(float *)(param_1 + 0x180),
      (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40)))) {
    *(undefined4 *)(param_1 + 0x184) = 0;
    gGlobalVariables = (float)DAT_0036bc6c;
    (*_DAT_0036af48)(param_1);
  }
  return;
}


// SV_Physics_Step  @ 000b493c
void SV_Physics_Step(int param_1)

{
  int iVar1;
  uint *puVar2;
  longdouble lVar3;
  double dVar4;
  uint uStack_c0;
  undefined1 local_a0 [4];
  int local_9c;
  float local_90;
  int local_70;
  int local_68;
  int local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_30;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float *local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  uStack_c0 = 0xb494b;
  local_10 = 0;
  PF_WaterMove(param_1);
  SV_CheckVelocity(param_1);
  local_8 = *(uint *)(param_1 + 0x224) & 0x200;
  local_c = SV_CheckWater(param_1);
  if (((*(ushort *)(param_1 + 0x224) & 0x8000) != 0) && (0 < *(int *)(param_1 + 0x240))) {
    lVar3 = (longdouble)SV_Submerged(param_1);
    local_28 = (float)((longdouble)*(int *)(param_1 + 400) * lVar3 * (longdouble)host_frametime);
    SV_AddGravity(param_1);
    *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xa8) + local_28;
  }
  if (((local_8 == 0) && ((*(uint *)(param_1 + 0x224) & 1) == 0)) &&
     (((*(uint *)(param_1 + 0x224) & 2) == 0 || (*(int *)(param_1 + 0x240) < 1)))) {
    if (*(float *)(param_1 + 0xa8) < (float)sv_gravity._12_4_ * -0.1) {
      local_10 = 1;
    }
    if (local_c == 0) {
      SV_AddGravity(param_1);
    }
  }
  iVar1 = VectorCompare(param_1 + 0xa0,vec_origin);
  if (iVar1 != 0) {
    iVar1 = VectorCompare(param_1 + 0xac,vec_origin);
    if (iVar1 != 0) {
      puVar2 = (uint *)&stack0xffffff44;
      if ((byte)(0.0 < DAT_0036b228 | (byte)((ushort)((ushort)NAN(DAT_0036b228) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_0036b228 == 0.0) << 0xe) >> 8)) != 0x40) {
        uStack_c0 = *(uint *)(param_1 + 0x224) >> 0x17 & 1;
        SV_Move(local_a0,param_1 + 0x88,param_1 + 0x15c,param_1 + 0x168,param_1 + 0x88,0,param_1);
        if (((local_90 < 1.0) || (puVar2 = &uStack_c0, local_9c != 0)) &&
           (puVar2 = &uStack_c0, local_70 != 0)) {
          SV_Impact(param_1,local_70,local_a0);
          puVar2 = &uStack_c0;
        }
      }
      goto LAB_000b4f08;
    }
  }
  *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xfffffdff;
  if ((local_8 != 0) &&
     ((0.0 < *(float *)(param_1 + 0x1e0) || (iVar1 = SV_CheckBottom(param_1), iVar1 != 0)))) {
    local_14 = (float *)(param_1 + 0xa0);
    dVar4 = sqrt((double)(*(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4) +
                         *local_14 * *local_14));
    local_18 = (float)dVar4;
    if ((byte)(0.0 < local_18 | (byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) != 0x40) {
      local_24 = (float)sv_friction._12_4_ * *(float *)(param_1 + 0x1a0);
      *(undefined4 *)(param_1 + 0x1a0) = 0x3f800000;
      local_20 = local_18;
      if ((byte)(local_18 < (float)sv_stopspeed._12_4_ |
                 (byte)((ushort)((ushort)(NAN(local_18) || NAN((float)sv_stopspeed._12_4_)) << 10)
                       >> 8) |
                (byte)((ushort)((ushort)(local_18 == (float)sv_stopspeed._12_4_) << 0xe) >> 8)) == 1
         ) {
        local_20 = (float)sv_stopspeed._12_4_;
      }
      local_1c = local_18 - local_24 * local_20 * (float)host_frametime;
      if (local_1c < 0.0) {
        local_1c = 0.0;
      }
      local_1c = local_1c / local_18;
      *local_14 = *local_14 * local_1c;
      local_14[1] = local_14[1] * local_1c;
    }
  }
  *(float *)(param_1 + 0xa0) = *(float *)(param_1 + 0xa0) + *(float *)(param_1 + 0xac);
  *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0xb0);
  *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0xb4);
  SV_CheckVelocity(param_1);
  local_30 = (float)host_frametime;
  SV_FlyMove(param_1,local_30,0);
  SV_CheckVelocity(param_1);
  *(float *)(param_1 + 0xa0) = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xac);
  *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0);
  *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xb4);
  SV_CheckVelocity(param_1);
  local_48 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x15c);
  local_44 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x160);
  local_40 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x164);
  local_54 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x168);
  local_50 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x16c);
  local_4c = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x170);
  local_58 = local_40 - 1.0;
  for (local_64 = 0; local_64 < 2; local_64 = local_64 + 1) {
    for (local_68 = 0; local_68 < 2; local_68 = local_68 + 1) {
      local_60 = local_48;
      if (local_64 != 0) {
        local_60 = local_54;
      }
      local_5c = local_44;
      if (local_68 != 0) {
        local_5c = local_50;
      }
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      iVar1 = SV_PointContents(&local_60);
      if (iVar1 == -2) {
        *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) | 0x200;
        break;
      }
    }
  }
  SV_LinkEdict(param_1,1);
  puVar2 = (uint *)&stack0xffffff44;
  if ((*(uint *)(param_1 + 0x224) & 0x200) != 0) {
    puVar2 = (uint *)&stack0xffffff44;
  }
LAB_000b4f08:
  *(int *)((int)puVar2 + -0x10) = param_1;
  *(undefined4 *)((int)puVar2 + -0x14) = 0xb4f14;
  SV_RunThink();
  *(int *)((int)puVar2 + -0x10) = param_1;
  *(undefined4 *)((int)puVar2 + -0x14) = 0xb4f23;
  SV_CheckWaterTransition();
  return;
}


// SV_Physics_Toss  @ 000b3b20
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_Physics_Toss(int *param_1)

{
  float fVar1;
  int iVar2;
  float **ppfVar3;
  float *local_74;
  int *piStack_70;
  float *local_4c;
  float local_48;
  float local_44;
  float local_40;
  int local_3c [4];
  float local_2c;
  undefined1 local_1c [8];
  float local_14;
  int local_c;
  
  piStack_70 = (int *)0xb3b2c;
  SV_CheckWater(param_1);
  iVar2 = SV_RunThink(param_1);
  if (iVar2 != 0) {
    fVar1 = (float)param_1[0x2a];
    if ((((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) || (param_1[0x87] == 0))
       || ((*(uint *)(param_1[0x87] + 0x224) & 0x28) != 0)) {
      param_1[0x89] = param_1[0x89] & 0xfffffdff;
    }
    if (((param_1[0x89] & 0x200U) != 0) &&
       (iVar2 = VectorCompare(param_1 + 0x28,vec_origin), iVar2 != 0)) {
      param_1[0x37] = vec3_origin;
      param_1[0x38] = DAT_000f1be0;
      param_1[0x39] = DAT_000f1be4;
      iVar2 = VectorCompare(param_1 + 0x2b,vec_origin);
      if (iVar2 != 0) {
        return;
      }
    }
    SV_CheckVelocity(param_1);
    if (((param_1[0x62] != 5) && (param_1[0x62] != 0xb)) && (param_1[0x62] != 9)) {
      SV_AddGravity(param_1);
    }
    piStack_70 = param_1 + 0x34;
    local_74 = (float *)(param_1 + 0x37);
    VectorMA(param_1 + 0x34,(float)host_frametime);
    param_1[0x28] = (int)((float)param_1[0x28] + (float)param_1[0x2b]);
    param_1[0x29] = (int)((float)param_1[0x29] + (float)param_1[0x2c]);
    param_1[0x2a] = (int)((float)param_1[0x2a] + (float)param_1[0x2d]);
    SV_CheckVelocity(param_1);
    local_74 = &local_48;
    VectorScale(param_1 + 0x28,(float)host_frametime);
    param_1[0x28] = (int)((float)param_1[0x28] - (float)param_1[0x2b]);
    param_1[0x29] = (int)((float)param_1[0x29] - (float)param_1[0x2c]);
    param_1[0x2a] = (int)((float)param_1[0x2a] - (float)param_1[0x2d]);
    local_74 = &local_48;
    SV_PushEntity(local_3c,param_1);
    SV_CheckVelocity(param_1);
    if (local_3c[0] == 0) {
      if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
        SV_CheckWaterTransition(param_1);
      }
      else if (*param_1 == 0) {
        if (param_1[0x62] == 10) {
          local_4c = (float *)(2.0 - (float)param_1[0x68]);
        }
        else if (param_1[0x62] == 0xb) {
          local_4c = (float *)0x40000000;
        }
        else {
          local_4c = (float *)0x3f800000;
        }
        local_74 = local_4c;
        ClipVelocity(param_1 + 0x28,local_1c,param_1 + 0x28);
        ppfVar3 = (float **)&piStack_70;
        if ((byte)(0.7 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_14 == 0.7) << 0xe) >> 8)) == 1) {
          local_48 = (float)param_1[0x28] + (float)param_1[0x2b];
          local_44 = (float)param_1[0x29] + (float)param_1[0x2c];
          local_40 = (float)param_1[0x2a] + (float)param_1[0x2d];
          if (local_40 < (float)sv_gravity._12_4_ * (float)host_frametime) {
            param_1[0x89] = param_1[0x89] | 0x200;
            param_1[0x87] = local_c;
            param_1[0x2a] = 0;
          }
          if ((local_40 * local_40 + local_44 * local_44 + local_48 * local_48 < 900.0) ||
             ((param_1[0x62] != 10 && (param_1[0x62] != 0xb)))) {
            param_1[0x89] = param_1[0x89] | 0x200;
            param_1[0x87] = local_c;
            param_1[0x28] = vec3_origin;
            param_1[0x29] = DAT_000f1be0;
            param_1[0x2a] = DAT_000f1be4;
            param_1[0x37] = vec3_origin;
            param_1[0x38] = DAT_000f1be0;
            param_1[0x39] = DAT_000f1be4;
            ppfVar3 = (float **)&piStack_70;
          }
          else {
            VectorScale(param_1 + 0x28,
                        (float)_FUN_000ebbb8 * (1.0 - local_2c) * (float)host_frametime,&local_48);
            local_74 = &local_48;
            VectorMA(&local_48,(float)_FUN_000ebbb8 * (1.0 - local_2c) * (float)host_frametime,
                     param_1 + 0x2b);
            SV_PushEntity(local_3c,param_1,&local_48);
            ppfVar3 = &local_74;
          }
        }
        *(int **)((int)ppfVar3 + -0x10) = param_1;
        *(undefined4 *)((int)ppfVar3 + -0x14) = 0xb40f6;
        SV_CheckWaterTransition();
      }
    }
    else {
      param_1[0x28] = vec3_origin;
      param_1[0x29] = DAT_000f1be0;
      param_1[0x2a] = DAT_000f1be4;
      param_1[0x37] = vec3_origin;
      param_1[0x38] = DAT_000f1be0;
      param_1[0x39] = DAT_000f1be4;
    }
  }
  return;
}


// SV_PlayerRunPreThink  @ 000b7b94
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_PlayerRunPreThink(undefined4 param_1,undefined4 param_2)

{
  gGlobalVariables = param_2;
  (*_DAT_0036af9c)(param_1);
  return;
}


// SV_PlayerRunThink  @ 000b7bd4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool SV_PlayerRunThink(int *param_1,float param_2,double param_3)

{
  float fVar1;
  bool bVar2;
  float local_8;
  
  if (((param_1[0x89] & 0x40000000U) == 0) && ((param_1[0x89] & 0x80000000U) == 0)) {
    local_8 = (float)param_1[0x61];
    if (0.0 < local_8) {
      param_2 = param_2 + (float)param_3;
      if ((byte)(param_2 < local_8 |
                 (byte)((ushort)((ushort)(NAN(param_2) || NAN(local_8)) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == local_8) << 0xe) >> 8)) != 1) {
        fVar1 = (float)param_3;
        if ((byte)(local_8 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(local_8) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_8 == fVar1) << 0xe) >> 8)) == 1) {
          local_8 = (float)param_3;
        }
        param_1[0x61] = 0;
        gGlobalVariables = local_8;
        (*_DAT_0036af48)(param_1);
        goto LAB_000b7c8f;
      }
    }
    bVar2 = true;
  }
  else {
LAB_000b7c8f:
    if ((param_1[0x89] & 0x40000000U) != 0) {
      ED_Free(param_1);
    }
    bVar2 = *param_1 == 0;
  }
  return bVar2;
}


// SV_PointContents  @ 000bf264
int SV_PointContents(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = SV_HullPointContents(DAT_0036bd88 + 0xd0,0,param_1);
  if ((local_8 < -8) && (-0xf < local_8)) {
    local_8 = -3;
  }
  if ((local_8 != -2) && (iVar1 = SV_LinkContents(&sv_areanodes,param_1), iVar1 != -1)) {
    local_8 = iVar1;
  }
  return local_8;
}


// SV_PointLeafnum  @ 000a55c4
int SV_PointLeafnum(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Mod_PointInLeaf(param_1,DAT_0036bd88);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (iVar1 - *(int *)(DAT_0036bd88 + 0x8c)) * -0x55555555 >> 4;
  }
  return iVar1;
}


// SV_PreRunCmd  @ 000b6f18
void SV_PreRunCmd(void)

{
  return;
}


// SV_ProcessFile  @ 000a43d8
void SV_ProcessFile(int param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  undefined1 local_20 [16];
  int local_10;
  int local_c;
  int local_8;
  
  bVar1 = false;
  if (*param_2 == '!') {
    COM_HexConvert(param_2 + 4,0x20,local_20);
    local_c = *(int *)(param_1 + 0x4d20);
    while (local_c != param_1 + 0x4ca0) {
      local_10 = *(int *)(local_c + 0x80);
      iVar2 = Q_memcmp(local_c + 0x4d,local_20,0x10);
      if (iVar2 == 0) {
        bVar1 = true;
        break;
      }
      local_c = local_10;
    }
    if (bVar1) {
      if (*(int *)(local_c + 0x48) == *(int *)(param_1 + 0x2104)) {
        bVar1 = false;
        HPAK_AddLump(1,"custom.hpk",local_c,*(undefined4 *)(param_1 + 0x2100),0);
        *(byte *)(local_c + 0x4c) = *(byte *)(local_c + 0x4c) & 0xfd;
        SV_MoveToOnHandList(local_c);
        for (local_8 = *(int *)(param_1 + 0x4dd0); local_8 != 0; local_8 = *(int *)(local_8 + 0xa0))
        {
          iVar2 = Q_memcmp(local_8 + 0x51,local_c + 0x4d,0x10);
          if (iVar2 == 0) {
            bVar1 = true;
            break;
          }
        }
        if (bVar1) {
          Con_DPrintf("Duplicate resource received and ignored.\n");
        }
        else {
          iVar2 = COM_CreateCustomization(param_1 + 0x4d30,local_c,0xffffffff,7,0,0);
          if (iVar2 == 0) {
            Con_Printf("Error parsing custom decal from %s\n",param_1 + 0x4bec);
          }
        }
      }
      else {
        Con_Printf("SV_ProcessFile:  Downloaded %i bytes for purported %i byte file\n",
                   *(undefined4 *)(param_1 + 0x2104),*(undefined4 *)(local_c + 0x48));
      }
    }
    else {
      Con_Printf("SV_ProcessFile:  Unrequested decal\n");
    }
  }
  else {
    Con_Printf("Ignoring non-customization file upload of %s\n",param_2);
  }
  return;
}


// SV_ProcessSteamClientConnections  @ 000aeb60
void SV_ProcessSteamClientConnections(void)

{
  int iVar1;
  undefined4 uVar2;
  char local_420 [512];
  char local_220 [256];
  char local_120 [256];
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if ((byte)(realtime < DAT_0052436c |
             (byte)((ushort)((ushort)(NAN(realtime) || NAN(DAT_0052436c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(realtime == DAT_0052436c) << 0xe) >> 8)) != 1) {
    DAT_0052436c = realtime + 0.10000000149011612;
    local_8 = g_nValidators;
    while (local_8 = local_8 + -1, -1 < local_8) {
      iVar1 = local_8 * 0xc;
      local_20 = (int *)(g_rgValidator + iVar1);
      if (local_20 != (int *)0x0) {
        if (*local_20 == DAT_00524290) {
          local_c = SteamProcessOngoingUserIDTicketValidation
                              (*(undefined4 *)(g_rgValidator + iVar1 + 8),&local_18,&local_1c,0,0,0)
          ;
          switch(local_c) {
          case 0:
            iVar1 = local_20[1];
            *(undefined4 *)(iVar1 + 0x4a94) = local_18;
            *(undefined4 *)(iVar1 + 0x4a98) = local_14;
            *(undefined4 *)(iVar1 + 0x4a9c) = local_10;
            *(undefined4 *)(local_20[1] + 0x4aa0) = local_1c;
            iVar1 = SV_FilterUser(local_20[1] + 0x4a90);
            if (iVar1 == 0) {
              iVar1 = SV_CheckForDuplicateSteamID(local_20[1]);
              if (iVar1 == -1) {
                if (*(int *)(local_20[1] + 0x4a90) == 1) {
                  uVar2 = SV_GetClientIDString(local_20[1]);
                  sprintf(local_420,"\"%s<%i><%s><>\" STEAM USERID validated\n",local_20[1] + 0x4bec
                          ,*(undefined4 *)(local_20[1] + 0x4a8c),uVar2);
                }
                else {
                  uVar2 = SV_GetClientIDString(local_20[1]);
                  sprintf(local_420,"\"%s<%i><%s><>\" VALVE USERID validated\n",local_20[1] + 0x4bec
                          ,*(undefined4 *)(local_20[1] + 0x4a8c),uVar2);
                }
                Con_DPrintf(&DAT_000e8e9b,local_420);
                Log_Printf(&DAT_000e8e9b,local_420);
                SV_RemoveSteamValidation(local_20[1]);
              }
              else {
                sprintf(local_220,"Your UserID is already in use on this server.\n");
                SV_RejectConnection(local_20[1] + 0x20,local_220);
                if (*(int *)(local_20[1] + 0x4a90) == 1) {
                  uVar2 = SV_GetClientIDString(local_20[1]);
                  SV_DropClient(local_20[1],0,"STEAM UserID %s is already\nin use on this server\n",
                                uVar2);
                }
                else {
                  uVar2 = SV_GetClientIDString(local_20[1]);
                  SV_DropClient(local_20[1],0,"VALVE UserID %s is already\nin use on this server\n",
                                uVar2);
                }
              }
            }
            else {
              sprintf(local_120,"You have been banned from this server\n");
              SV_RejectConnection(local_20[1] + 0x20,local_120);
              uVar2 = SV_GetClientIDString(local_20[1]);
              SV_DropClient(local_20[1],0,"STEAM UserID %s is in server ban list\n",uVar2);
            }
            break;
          default:
            if (*(int *)(local_20[1] + 0x4a90) == 1) {
              SV_DropClient(local_20[1],0,"Error verifying STEAM UserID Ticket (%i)\n",local_c);
            }
            else {
              SV_DropClient(local_20[1],0,"Error verifying VALVE key (%i)\n",local_c);
            }
            break;
          case 0x17:
            break;
          case 0x18:
            SV_DropClient(local_20[1],0,"Client using inactive STEAM UserID Ticket handle\n");
            break;
          case 0x19:
          case 0x24:
            if (*(int *)(local_20[1] + 0x4a90) == 1) {
              SV_DropClient(local_20[1],0,"Invalid STEAM UserID Ticket\n");
            }
            else {
              SV_DropClient(local_20[1],0,"Invalid VALVE CD Key\n");
            }
            break;
          case 0x1b:
          case 0x1f:
          case 0x20:
          case 0x23:
            if (*(int *)(local_20[1] + 0x4a90) == 1) {
              SV_DropClient(local_20[1],0,
                            "Error verifying STEAM UserID Ticket(server was\nunable to contact the authentication server, %i).\n"
                            ,local_c);
            }
            else if ((byte)(0.0 < (float)sv_lan._12_4_ |
                            (byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
                           (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) ==
                     0x40) {
              SV_DropClient(local_20[1],0,
                            "Error verifying VALVE key (server was unable\nto contact the authentication server, %i).\n"
                            ,local_c);
            }
            else {
              *(undefined2 *)(local_20[1] + 0x4a94) = 1;
              iVar1 = local_20[1];
              *(undefined4 *)(iVar1 + 0x4a98) = 0;
              *(undefined4 *)(iVar1 + 0x4a9c) = 0;
              *(undefined4 *)(local_20[1] + 0x4aa0) = local_1c;
              SV_RemoveSteamValidation(local_20[1]);
            }
            break;
          case 0x2a:
            if (*(int *)(local_20[1] + 0x4a90) == 1) {
              SV_DropClient(local_20[1],0,"Invalid STEAM UserID Ticket\n");
            }
            else {
              SV_DropClient(local_20[1],0,"Your CD Key is already in use.\n");
            }
          }
        }
        else {
          SV_RemoveSteamValidation(*(undefined4 *)(g_rgValidator + iVar1 + 4));
        }
      }
    }
  }
  return;
}


// SV_PropagateCustomizations  @ 000a85d0
void SV_PropagateCustomizations(void)

{
  int iVar1;
  int local_14;
  int *local_c;
  
  iVar1 = (int)host_client;
  host_client = DAT_00524284;
  for (local_14 = 0; local_14 < DAT_00524288; local_14 = local_14 + 1) {
    if (((*host_client != 0) || (host_client[1] != 0)) && (host_client[0x90e] == 0)) {
      local_c = (int *)host_client[0x1374];
      while (local_c != (int *)0x0) {
        if (*local_c == 0) {
          local_c = (int *)local_c[0x28];
        }
        else {
          MSG_WriteByte(iVar1 + 0x74,0x2e);
          MSG_WriteByte(iVar1 + 0x74,local_14);
          MSG_WriteByte(iVar1 + 0x74,local_c[0x11]);
          MSG_WriteString(iVar1 + 0x74,local_c + 1);
          MSG_WriteShort(iVar1 + 0x74,local_c[0x12]);
          MSG_WriteLong(iVar1 + 0x74,local_c[0x13]);
          MSG_WriteByte(iVar1 + 0x74,(char)local_c[0x14]);
          if ((*(byte *)(local_c + 0x14) & 4) != 0) {
            SZ_Write(iVar1 + 0x74,(int)local_c + 0x51,0x10);
          }
          local_c = (int *)local_c[0x28];
        }
      }
    }
    host_client = host_client + 0x13bb;
  }
  host_client = (int *)iVar1;
  return;
}


// SV_PushEntity  @ 000b1cf0
undefined4 * SV_PushEntity(undefined4 *param_1,int param_2,float *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_50;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c [4];
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_c;
  
  local_48 = *(float *)(param_2 + 0x88) + *param_3;
  local_44 = *(float *)(param_2 + 0x8c) + param_3[1];
  local_40 = *(float *)(param_2 + 0x90) + param_3[2];
  if (*(int *)(param_2 + 0x188) == 9) {
    local_50 = 2;
  }
  else if ((*(int *)(param_2 + 0x18c) == 1) || (*(int *)(param_2 + 0x18c) == 0)) {
    local_50 = 1;
  }
  else {
    local_50 = 0;
  }
  SV_Move(local_3c,param_2 + 0x88,param_2 + 0x15c,param_2 + 0x168,&local_48,local_50,param_2,
          (*(uint *)(param_2 + 0x224) & 0x800000) != 0);
  if ((byte)(0.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) != 0x40) {
    *(undefined4 *)(param_2 + 0x88) = local_28;
    *(undefined4 *)(param_2 + 0x8c) = local_24;
    *(undefined4 *)(param_2 + 0x90) = local_20;
  }
  SV_LinkEdict(param_2,1);
  if (local_c != 0) {
    SV_Impact(param_2,local_c,local_3c);
  }
  puVar2 = local_3c;
  puVar3 = param_1;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// SV_PushMove  @ 000b1e6c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_PushMove(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int aiStackY_d4 [2];
  undefined4 uStack_c0;
  undefined1 local_88 [56];
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  float local_34 [6];
  float local_1c [3];
  int *local_10;
  int local_c;
  int local_8;
  
  uStack_c0 = 0xb1e7d;
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa0) == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa4) == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa8) == 0.0) << 0xe) >> 8)) == 0x40)) {
    *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) + param_2;
  }
  else {
    local_4c = *(undefined4 *)(param_1 + 0x88);
    local_48 = *(undefined4 *)(param_1 + 0x8c);
    local_44 = *(undefined4 *)(param_1 + 0x90);
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      local_34[local_8] = *(float *)(local_8 * 4 + param_1 + 0xa0) * param_2;
      local_34[local_8 + 6] = *(float *)(local_8 * 4 + param_1 + 0x144) + local_34[local_8];
      local_34[local_8 + 3] = *(float *)(local_8 * 4 + param_1 + 0x150) + local_34[local_8];
      *(float *)(local_8 * 4 + param_1 + 0x88) =
           *(float *)(local_8 * 4 + param_1 + 0x88) + local_34[local_8];
    }
    *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) + param_2;
    SV_LinkEdict(param_1,0);
    if (*(int *)(param_1 + 0x18c) != 0) {
      local_50 = 0;
      puVar3 = &stack0xffffff44;
      for (local_c = 1; local_c < DAT_003a78b0; local_c = local_c + 1) {
        local_10 = (int *)(DAT_003a78b8 + local_c * 0x324);
        puVar4 = puVar3;
        if (((*local_10 == 0) && (local_10[0x62] != 7)) &&
           ((local_10[0x62] != 0 && ((local_10[0x62] != 0xc && (local_10[0x62] != 8)))))) {
          if (((local_10[0x89] & 0x200U) == 0) || (local_10[0x87] != param_1)) {
            if ((((((float)local_10[0x51] < local_34[3]) && ((float)local_10[0x52] < local_34[4]))
                 && ((float)local_10[0x53] < local_34[5])) &&
                ((fVar1 = (float)local_10[0x54],
                 0x3f < (byte)((fVar1 < local_1c[0] |
                                (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_1c[0])) << 10) >> 8
                                      ) |
                               (byte)((ushort)((ushort)(fVar1 == local_1c[0]) << 0xe) >> 8)) - 1) &&
                 (fVar1 = (float)local_10[0x55],
                 0x3f < (byte)((fVar1 < local_1c[1] |
                                (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_1c[1])) << 10) >> 8
                                      ) |
                               (byte)((ushort)((ushort)(fVar1 == local_1c[1]) << 0xe) >> 8)) - 1))))
                ) && (fVar1 = (float)local_10[0x56],
                     0x3f < (byte)((fVar1 < local_1c[2] |
                                    (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_1c[2])) << 10)
                                          >> 8) |
                                   (byte)((ushort)((ushort)(fVar1 == local_1c[2]) << 0xe) >> 8)) - 1
                                  ))) {
              *(int **)(puVar3 + -0x10) = local_10;
              *(undefined4 *)(puVar3 + -0x14) = 0xb2228;
              iVar2 = SV_TestEntityPosition();
              if (iVar2 != 0) goto LAB_000b2238;
            }
          }
          else {
LAB_000b2238:
            if (local_10[0x62] != 3) {
              local_10[0x89] = local_10[0x89] & 0xfffffdff;
            }
            local_40 = local_10[0x22];
            local_3c = local_10[0x23];
            local_38 = local_10[0x24];
            *(int *)(g_moved_from + local_50 * 0xc) = local_10[0x22];
            *(int *)(local_50 * 0xc + g_moved_from + 4) = local_10[0x23];
            *(int *)(local_50 * 0xc + g_moved_from + 8) = local_10[0x24];
            *(int **)(g_moved_edict + local_50 * 4) = local_10;
            local_50 = local_50 + 1;
            *(undefined4 *)(param_1 + 0x18c) = 0;
            *(float **)(puVar3 + -8) = local_34;
            *(int **)(puVar3 + -0xc) = local_10;
            *(undefined1 **)(puVar3 + -0x10) = local_88;
            *(undefined4 *)(puVar3 + -0x14) = 0xb2330;
            SV_PushEntity();
            *(undefined4 *)(param_1 + 0x18c) = 4;
            *(int **)(puVar3 + -0x14) = local_10;
            *(undefined4 *)(puVar3 + -0x18) = 0xb234c;
            iVar2 = SV_TestEntityPosition();
            puVar4 = puVar3 + -4;
            if ((iVar2 != 0) &&
               (puVar4 = puVar3 + -4,
               (byte)((byte)((ushort)((ushort)(NAN((float)local_10[0x5a]) ||
                                              NAN((float)local_10[0x57])) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)local_10[0x5a] == (float)local_10[0x57]) << 0xe
                                    ) >> 8)) != 0x40)) {
              if ((local_10[99] != 0) && (local_10[99] != 1)) {
                local_10[0x22] = local_40;
                local_10[0x23] = local_3c;
                local_10[0x24] = local_38;
                *(undefined4 *)(puVar3 + -0x10) = 1;
                *(int **)(puVar3 + -0x14) = local_10;
                *(undefined4 *)(puVar3 + -0x18) = 0xb241a;
                SV_LinkEdict();
                *(undefined4 *)(param_1 + 0x88) = local_4c;
                *(undefined4 *)(param_1 + 0x8c) = local_48;
                *(undefined4 *)(param_1 + 0x90) = local_44;
                *(undefined4 *)(puVar3 + -0x10) = 0;
                *(int *)(puVar3 + -0x14) = param_1;
                *(undefined4 *)(puVar3 + -0x18) = 0xb244f;
                SV_LinkEdict();
                *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) - param_2;
                *(int **)(puVar3 + -0x10) = local_10;
                *(int *)(puVar3 + -0x14) = param_1;
                *(undefined4 *)(puVar3 + -0x18) = 0xb247d;
                (*_DAT_0036af54)();
                for (local_8 = 0; local_8 < local_50; local_8 = local_8 + 1) {
                  *(undefined4 *)(*(int *)(g_moved_edict + local_8 * 4) + 0x88) =
                       *(undefined4 *)(g_moved_from + local_8 * 0xc);
                  *(undefined4 *)(*(int *)(g_moved_edict + local_8 * 4) + 0x8c) =
                       *(undefined4 *)(g_moved_from + local_8 * 0xc + 4);
                  *(undefined4 *)(*(int *)(g_moved_edict + local_8 * 4) + 0x90) =
                       *(undefined4 *)(g_moved_from + local_8 * 0xc + 8);
                  *(undefined4 *)(puVar3 + -0x10) = 0;
                  *(undefined4 *)(puVar3 + -0x14) = *(undefined4 *)(g_moved_edict + local_8 * 4);
                  *(undefined4 *)(puVar3 + -0x18) = 0xb2564;
                  SV_LinkEdict();
                }
                return;
              }
              local_10[0x58] = 0;
              local_10[0x57] = 0;
              local_10[0x5a] = local_10[0x57];
              local_10[0x5b] = local_10[0x58];
              local_10[0x5c] = local_10[0x59];
              puVar4 = puVar3 + -4;
            }
          }
        }
        puVar3 = puVar4;
      }
    }
  }
  return;
}


// SV_PushRotate  @ 000b258c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SV_PushRotate(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int aiStackY_124 [2];
  undefined1 local_f4 [68];
  float local_b0;
  float local_ac;
  float local_a8;
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
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  float local_28 [4];
  float local_18;
  float local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xdc)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0xdc) == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xe0)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0xe0) == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xe4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0xe4) == 0.0) << 0xe) >> 8)) == 0x40)) {
    *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) + param_2;
  }
  else {
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      local_28[local_8] = *(float *)(local_8 * 4 + param_1 + 0xdc) * param_2;
    }
    AngleVectors(param_1 + 0xd0,&local_98,&local_a4,&local_b0);
    local_40 = *(undefined4 *)(param_1 + 0xd0);
    local_3c = *(undefined4 *)(param_1 + 0xd4);
    local_38 = *(undefined4 *)(param_1 + 0xd8);
    *(float *)(param_1 + 0xd0) = *(float *)(param_1 + 0xd0) + local_28[0];
    *(float *)(param_1 + 0xd4) = *(float *)(param_1 + 0xd4) + local_28[1];
    *(float *)(param_1 + 0xd8) = *(float *)(param_1 + 0xd8) + local_28[2];
    AngleVectorsTranspose(param_1 + 0xd0,&local_74,&local_80,&local_8c);
    *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) + param_2;
    SV_LinkEdict(param_1,0);
    if (*(int *)(param_1 + 0x18c) != 0) {
      local_28[0] = 0.0;
      local_28[2] = 0.0;
      local_44 = 0;
      puVar4 = &stack0xfffffef4;
      for (local_c = 1; local_c < DAT_003a78b0; local_c = local_c + 1) {
        local_10 = (int *)(DAT_003a78b8 + local_c * 0x324);
        puVar5 = puVar4;
        if (((*local_10 == 0) && (local_10[0x62] != 7)) &&
           ((local_10[0x62] != 0 && ((local_10[0x62] != 0xc && (local_10[0x62] != 8)))))) {
          if (((local_10[0x89] & 0x200U) == 0) || (local_10[0x87] != param_1)) {
            if ((((float)local_10[0x51] < *(float *)(param_1 + 0x150)) &&
                ((float)local_10[0x52] < *(float *)(param_1 + 0x154))) &&
               ((float)local_10[0x53] < *(float *)(param_1 + 0x158))) {
              fVar1 = (float)local_10[0x54];
              fVar2 = *(float *)(param_1 + 0x144);
              if (0x3f < (byte)((fVar1 < fVar2 |
                                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
                fVar1 = (float)local_10[0x55];
                fVar2 = *(float *)(param_1 + 0x148);
                if (0x3f < (byte)((fVar1 < fVar2 |
                                   (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
                  fVar1 = (float)local_10[0x56];
                  fVar2 = *(float *)(param_1 + 0x14c);
                  if (0x3f < (byte)((fVar1 < fVar2 |
                                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
                  {
                    *(int **)(puVar4 + -0x10) = local_10;
                    *(undefined4 *)(puVar4 + -0x14) = 0xb28cc;
                    iVar3 = SV_TestEntityPosition();
                    if (iVar3 != 0) goto LAB_000b28dc;
                  }
                }
              }
            }
          }
          else {
LAB_000b28dc:
            if (local_10[0x62] != 3) {
              local_10[0x89] = local_10[0x89] & 0xfffffdff;
            }
            local_34 = local_10[0x22];
            local_30 = local_10[0x23];
            local_2c = local_10[0x24];
            *(int *)(g_moved_from + local_44 * 0xc) = local_10[0x22];
            *(int *)(local_44 * 0xc + g_moved_from + 4) = local_10[0x23];
            *(int *)(local_44 * 0xc + g_moved_from + 8) = local_10[0x24];
            *(int **)(g_moved_edict + local_44 * 4) = local_10;
            local_44 = local_44 + 1;
            if (DAT_003a78b4 <= local_44) {
              *(char **)(puVar4 + -0x10) = "Out of edicts in simulator!\n";
              *(undefined4 *)(puVar4 + -0x14) = 0xb29d2;
              Sys_Error();
            }
            if (local_10[0x62] == 0xd) {
              local_5c = ((float)local_10[0x51] + (float)local_10[0x54]) * 0.5 -
                         *(float *)(param_1 + 0x88);
              local_58 = ((float)local_10[0x52] + (float)local_10[0x55]) * 0.5 -
                         *(float *)(param_1 + 0x8c);
              local_54 = ((float)local_10[0x53] + (float)local_10[0x56]) * 0.5 -
                         *(float *)(param_1 + 0x90);
            }
            else {
              local_5c = (float)local_10[0x22] - *(float *)(param_1 + 0x88);
              local_58 = (float)local_10[0x23] - *(float *)(param_1 + 0x8c);
              local_54 = (float)local_10[0x24] - *(float *)(param_1 + 0x90);
            }
            local_50 = local_54 * local_90 + local_58 * local_94 + local_5c * local_98;
            local_4c = -(local_54 * local_9c + local_58 * local_a0 + local_5c * local_a4);
            local_48 = local_54 * local_a8 + local_58 * local_ac + local_5c * local_b0;
            local_68 = local_48 * local_6c + local_4c * local_70 + local_50 * local_74;
            local_64 = local_48 * local_78 + local_4c * local_7c + local_50 * local_80;
            local_60 = local_48 * local_84 + local_4c * local_88 + local_50 * local_8c;
            local_28[3] = local_68 - local_5c;
            local_18 = local_64 - local_58;
            local_14 = local_60 - local_54;
            *(undefined4 *)(param_1 + 0x18c) = 0;
            *(float **)(puVar4 + -8) = local_28 + 3;
            *(int **)(puVar4 + -0xc) = local_10;
            *(undefined1 **)(puVar4 + -0x10) = local_f4;
            *(undefined4 *)(puVar4 + -0x14) = 0xb2ba3;
            SV_PushEntity();
            *(undefined4 *)(param_1 + 0x18c) = 4;
            if (local_10[0x62] != 0xd) {
              if ((local_10[0x89] & 8U) == 0) {
                local_10[0x34] = (int)((float)local_10[0x34] + local_28[0]);
                local_10[0x35] = (int)((float)local_10[0x35] + local_28[1]);
                local_10[0x36] = (int)((float)local_10[0x36] + local_28[2]);
              }
              else {
                local_10[0x38] = (int)((float)local_10[0x38] + local_28[1]);
                local_10[0x48] = 2;
              }
            }
            *(int **)(puVar4 + -0x14) = local_10;
            *(undefined4 *)(puVar4 + -0x18) = 0xb2c3f;
            iVar3 = SV_TestEntityPosition();
            puVar5 = puVar4 + -4;
            if ((iVar3 != 0) &&
               (puVar5 = puVar4 + -4,
               (byte)((byte)((ushort)((ushort)(NAN((float)local_10[0x5a]) ||
                                              NAN((float)local_10[0x57])) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)local_10[0x5a] == (float)local_10[0x57]) << 0xe
                                    ) >> 8)) != 0x40)) {
              if ((local_10[99] != 0) && (local_10[99] != 1)) {
                local_10[0x22] = local_34;
                local_10[0x23] = local_30;
                local_10[0x24] = local_2c;
                *(undefined4 *)(puVar4 + -0x10) = 1;
                *(int **)(puVar4 + -0x14) = local_10;
                *(undefined4 *)(puVar4 + -0x18) = 0xb2d0e;
                SV_LinkEdict();
                *(undefined4 *)(param_1 + 0xd0) = local_40;
                *(undefined4 *)(param_1 + 0xd4) = local_3c;
                *(undefined4 *)(param_1 + 0xd8) = local_38;
                *(undefined4 *)(puVar4 + -0x10) = 0;
                *(int *)(puVar4 + -0x14) = param_1;
                *(undefined4 *)(puVar4 + -0x18) = 0xb2d43;
                SV_LinkEdict();
                *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) - param_2;
                *(int **)(puVar4 + -0x10) = local_10;
                *(int *)(puVar4 + -0x14) = param_1;
                *(undefined4 *)(puVar4 + -0x18) = 0xb2d71;
                (*_DAT_0036af54)();
                for (local_8 = 0; local_8 < local_44; local_8 = local_8 + 1) {
                  *(undefined4 *)(*(int *)(g_moved_edict + local_8 * 4) + 0x88) =
                       *(undefined4 *)(g_moved_from + local_8 * 0xc);
                  *(undefined4 *)(*(int *)(g_moved_edict + local_8 * 4) + 0x8c) =
                       *(undefined4 *)(g_moved_from + local_8 * 0xc + 4);
                  *(undefined4 *)(*(int *)(g_moved_edict + local_8 * 4) + 0x90) =
                       *(undefined4 *)(g_moved_from + local_8 * 0xc + 8);
                  if ((*(uint *)(*(int *)(g_moved_edict + local_8 * 4) + 0x224) & 8) == 0) {
                    if (*(int *)(*(int *)(g_moved_edict + local_8 * 4) + 0x188) != 0xd) {
                      *(float *)(*(int *)(g_moved_edict + local_8 * 4) + 0xd0) =
                           *(float *)(*(int *)(g_moved_edict + local_8 * 4) + 0xd0) - local_28[0];
                      *(float *)(*(int *)(g_moved_edict + local_8 * 4) + 0xd4) =
                           *(float *)(*(int *)(g_moved_edict + local_8 * 4) + 0xd4) - local_28[1];
                      *(float *)(*(int *)(g_moved_edict + local_8 * 4) + 0xd8) =
                           *(float *)(*(int *)(g_moved_edict + local_8 * 4) + 0xd8) - local_28[2];
                    }
                  }
                  else {
                    *(undefined4 *)(*(int *)(g_moved_edict + local_8 * 4) + 0xe0) = 0;
                  }
                  *(undefined4 *)(puVar4 + -0x10) = 0;
                  *(undefined4 *)(puVar4 + -0x14) = *(undefined4 *)(g_moved_edict + local_8 * 4);
                  *(undefined4 *)(puVar4 + -0x18) = 0xb2f6d;
                  SV_LinkEdict();
                }
                return 0;
              }
              local_10[0x58] = 0;
              local_10[0x57] = 0;
              local_10[0x5a] = local_10[0x57];
              local_10[0x5b] = local_10[0x58];
              local_10[0x5c] = local_10[0x59];
              puVar5 = puVar4 + -4;
            }
          }
        }
        puVar4 = puVar5;
      }
    }
  }
  return 1;
}


// SV_QueryMovevarsChanged  @ 0009d580
void SV_QueryMovevarsChanged(void)

{
  int iVar1;
  int *local_c;
  int local_8;
  
  if (((((((((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b28) || NAN((float)sv_maxspeed._12_4_)) <<
                                   10) >> 8) |
                   (byte)((ushort)((ushort)(DAT_00362b28 == (float)sv_maxspeed._12_4_) << 0xe) >> 8)
                   ) != 0x40) ||
           ((byte)((byte)((ushort)((ushort)(NAN(movevars) || NAN((float)sv_gravity._12_4_)) << 10)
                         >> 8) |
                  (byte)((ushort)((ushort)(movevars == (float)sv_gravity._12_4_) << 0xe) >> 8)) !=
            0x40)) ||
          ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b24) || NAN((float)sv_stopspeed._12_4_)) <<
                                 10) >> 8) |
                 (byte)((ushort)((ushort)(DAT_00362b24 == (float)sv_stopspeed._12_4_) << 0xe) >> 8))
           != 0x40)) ||
         ((((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b2c) ||
                                           NAN((float)sv_spectatormaxspeed._12_4_)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00362b2c == (float)sv_spectatormaxspeed._12_4_) <<
                                 0xe) >> 8)) != 0x40 ||
           ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b30) || NAN((float)sv_accelerate._12_4_))
                                  << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00362b30 == (float)sv_accelerate._12_4_) << 0xe) >> 8
                        )) != 0x40)) ||
          (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b34) || NAN((float)sv_airaccelerate._12_4_)
                                           ) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00362b34 == (float)sv_airaccelerate._12_4_) << 0xe)
                        >> 8)) != 0x40 ||
           (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b38) ||
                                            NAN((float)sv_wateraccelerate._12_4_)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(DAT_00362b38 == (float)sv_wateraccelerate._12_4_) << 0xe
                                  ) >> 8)) != 0x40 ||
            ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b3c) || NAN((float)sv_friction._12_4_)) <<
                                   10) >> 8) |
                   (byte)((ushort)((ushort)(DAT_00362b3c == (float)sv_friction._12_4_) << 0xe) >> 8)
                   ) != 0x40)))))))) ||
        ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b40) || NAN((float)sv_edgefriction._12_4_)) <<
                               10) >> 8) |
               (byte)((ushort)((ushort)(DAT_00362b40 == (float)sv_edgefriction._12_4_) << 0xe) >> 8)
               ) != 0x40)) ||
       ((((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b44) || NAN((float)sv_waterfriction._12_4_))
                                << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_00362b44 == (float)sv_waterfriction._12_4_) << 0xe) >>
                      8)) != 0x40 ||
         ((byte)((byte)((ushort)((ushort)NAN(DAT_00362b48) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_00362b48 == 1.0) << 0xe) >> 8)) != 0x40)) ||
        ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b4c) || NAN((float)sv_bounce._12_4_)) << 10)
                      >> 8) |
               (byte)((ushort)((ushort)(DAT_00362b4c == (float)sv_bounce._12_4_) << 0xe) >> 8)) !=
         0x40)))) ||
      ((((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b50) || NAN((float)sv_stepsize._12_4_)) << 10)
                      >> 8) |
               (byte)((ushort)((ushort)(DAT_00362b50 == (float)sv_stepsize._12_4_) << 0xe) >> 8)) !=
         0x40 || ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b54) ||
                                                 NAN((float)sv_maxvelocity._12_4_)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(DAT_00362b54 == (float)sv_maxvelocity._12_4_) <<
                                       0xe) >> 8)) != 0x40)) ||
       (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b58) || NAN((float)sv_zmax._12_4_)) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(DAT_00362b58 == (float)sv_zmax._12_4_) << 0xe) >> 8)) !=
         0x40 || (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b5c) ||
                                                  NAN((float)sv_wateramp._12_4_)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(DAT_00362b5c == (float)sv_wateramp._12_4_) << 0xe)
                               >> 8)) != 0x40 ||
                  ((byte)((byte)((ushort)((ushort)(NAN((float)sv_footsteps._12_4_) ||
                                                  NAN((float)DAT_00362b60)) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)sv_footsteps._12_4_ == (float)DAT_00362b60)
                                        << 0xe) >> 8)) != 0x40)))))))) ||
     (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b84) || NAN((float)sv_rollangle._12_4_)) << 10)
                    >> 8) |
             (byte)((ushort)((ushort)(DAT_00362b84 == (float)sv_rollangle._12_4_) << 0xe) >> 8)) !=
       0x40 || ((((((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b88) ||
                                                   NAN((float)sv_rollspeed._12_4_)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(DAT_00362b88 == (float)sv_rollspeed._12_4_) <<
                                         0xe) >> 8)) != 0x40 ||
                   ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b8c) ||
                                                   NAN((float)sv_skycolor_r._12_4_)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(DAT_00362b8c == (float)sv_skycolor_r._12_4_) <<
                                         0xe) >> 8)) != 0x40)) ||
                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b90) ||
                                                  NAN((float)sv_skycolor_g._12_4_)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(DAT_00362b90 == (float)sv_skycolor_g._12_4_) <<
                                        0xe) >> 8)) != 0x40)) ||
                 (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b94) ||
                                                  NAN((float)sv_skycolor_b._12_4_)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(DAT_00362b94 == (float)sv_skycolor_b._12_4_) <<
                                        0xe) >> 8)) != 0x40 ||
                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b98) ||
                                                  NAN((float)sv_skyvec_x._12_4_)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(DAT_00362b98 == (float)sv_skyvec_x._12_4_) << 0xe)
                               >> 8)) != 0x40)))) ||
                (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362b9c) ||
                                                 NAN((float)sv_skyvec_y._12_4_)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(DAT_00362b9c == (float)sv_skyvec_y._12_4_) << 0xe)
                              >> 8)) != 0x40 ||
                 (((byte)((byte)((ushort)((ushort)(NAN(DAT_00362ba0) ||
                                                  NAN((float)sv_skyvec_z._12_4_)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(DAT_00362ba0 == (float)sv_skyvec_z._12_4_) << 0xe)
                               >> 8)) != 0x40 ||
                  (iVar1 = Q_strcmp(sv_skyname._4_4_,&DAT_00362b64), iVar1 != 0)))))))))) {
    SV_SetMoveVars();
    local_c = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if ((local_c[0x90e] == 0) && (((*local_c != 0 || (local_c[1] != 0)) || (local_c[3] != 0)))) {
        SV_WriteMovevarsToClient(local_c + 0x1d);
      }
      local_c = local_c + 0x13bb;
    }
  }
  return;
}


// SV_Rcon  @ 000a39d8
void SV_Rcon(undefined4 *param_1)

{
  int iVar1;
  size_t sVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  undefined *apuStackY_654 [5];
  undefined4 uStackY_640;
  undefined1 local_608 [1535];
  undefined1 local_9;
  int local_8;
  
  local_8 = SV_Rcon_Validate();
  uStackY_640 = 0xa3a15;
  iVar1 = Q_strlen();
  iVar1 = DAT_0059d8d0 - iVar1;
  if ((0 < iVar1) && (iVar1 < 0x1ff)) {
    apuStackY_654[4] = &DAT_000e981f;
    apuStackY_654[3] = (undefined *)0xa3a6b;
    Q_strlen();
    uStackY_640 = 0xa3a86;
    Q_memcpy();
    local_608[iVar1] = 0;
    if (local_8 != 0) {
      puVar3 = param_1;
      ppuVar4 = apuStackY_654;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppuVar4 = (undefined *)*puVar3;
        puVar3 = puVar3 + 1;
        ppuVar4 = ppuVar4 + 1;
      }
      NET_AdrToString();
      uStackY_640 = 0xa3ad7;
      Con_Printf();
      puVar3 = param_1;
      ppuVar4 = apuStackY_654 + 1;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppuVar4 = (undefined *)*puVar3;
        puVar3 = puVar3 + 1;
        ppuVar4 = ppuVar4 + 1;
      }
      apuStackY_654[0] = (undefined *)0xa3af7;
      NET_AdrToString();
      uStackY_640 = 0xa3b12;
      Log_Printf();
    }
    if (local_8 == 0) {
      puVar3 = param_1;
      ppuVar4 = apuStackY_654;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppuVar4 = (undefined *)*puVar3;
        puVar3 = puVar3 + 1;
        ppuVar4 = ppuVar4 + 1;
      }
      NET_AdrToString();
      uStackY_640 = 0xa3b53;
      Con_Printf();
      ppuVar4 = apuStackY_654 + 1;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppuVar4 = (undefined *)*param_1;
        param_1 = param_1 + 1;
        ppuVar4 = ppuVar4 + 1;
      }
      apuStackY_654[0] = (undefined *)0xa3b73;
      NET_AdrToString();
      uStackY_640 = 0xa3b8e;
      Log_Printf();
    }
    uStackY_640 = 0xa3b9f;
    SV_BeginRedirect();
    if (local_8 == 0) {
      uStackY_640 = 0xa3c3f;
      COM_Parse();
      uStackY_640 = 0xa3c59;
      COM_Parse();
      uStackY_640 = 0xa3c73;
      iVar1 = COM_Parse();
      if (iVar1 == 0) {
        uStackY_640 = 0xa3c98;
        Con_Printf();
        return;
      }
      uStackY_640 = 0xa3cbb;
      Q_strncpy();
      local_9 = 0;
      uStackY_640 = 0xa3cd3;
      Cmd_ExecuteString();
    }
    else if ((local_8 == 1) || (local_8 != 2)) {
      uStackY_640 = 0xa3bca;
      sVar2 = strlen((char *)rcon_password._4_4_);
      if (sVar2 == 0) {
        uStackY_640 = 0xa3bfd;
        Con_Printf();
      }
      else {
        uStackY_640 = 0xa3be4;
        Con_Printf();
      }
    }
    else {
      uStackY_640 = 0xa3c15;
      Con_Printf();
    }
    SV_EndRedirect();
  }
  return;
}


// SV_Rcon_Validate  @ 000a37f8
undefined4 SV_Rcon_Validate(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int aiStack_5c [5];
  char *pcStack_48;
  int iStack_44;
  undefined4 uStack_40;
  char *pcStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_30;
  
  uStack_30 = 0xa3812;
  iVar1 = Cmd_Argc();
  if (iVar1 < 3) {
    uVar2 = 1;
  }
  else {
    pcStack_3c = (char *)rcon_password._4_4_;
    uStack_40 = 0xa3836;
    iVar1 = Q_strlen();
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      if ((float)sv_rcon_banpenalty._12_4_ < 0.0) {
        uStack_38 = 0;
        pcStack_3c = "sv_rcon_banpenalty";
        uStack_40 = 0xa3873;
        Cvar_SetValue();
      }
      pcStack_3c = (char *)&net_from;
      uStack_40 = 0xa3887;
      iVar1 = SV_CheckRconFailure();
      if (iVar1 == 0) {
        aiStack_5c[3] = 1;
        aiStack_5c[2] = 0xa3950;
        iStack_44 = Cmd_Argv();
        pcStack_48 = (char *)0xa395b;
        uStack_38 = Q_atoi();
        pcStack_3c = (char *)&net_from;
        uStack_40 = 0xa396f;
        iVar1 = SV_CheckChallenge();
        if (iVar1 == 0) {
          uVar2 = 2;
        }
        else {
          uStack_38 = rcon_password._4_4_;
          pcStack_48 = (char *)0x2;
          aiStack_5c[4] = 0xa3997;
          pcStack_3c = (char *)Cmd_Argv();
          uStack_40 = 0xa39a2;
          iVar1 = Q_strcmp();
          if (iVar1 == 0) {
            uVar2 = 0;
          }
          else {
            pcStack_3c = (char *)&net_from;
            uStack_40 = 0xa39bc;
            SV_AddFailedRcon();
            uVar2 = 1;
          }
        }
      }
      else {
        puVar3 = &net_from;
        piVar4 = aiStack_5c + 2;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          piVar4 = piVar4 + 1;
        }
        aiStack_5c[1] = 0xa38b4;
        uStack_38 = NET_AdrToString();
        pcStack_3c = "Banning %s for rcon hacking attempts\n";
        uStack_40 = 0xa38c8;
        Con_Printf();
        puVar3 = &net_from;
        piVar4 = aiStack_5c;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          piVar4 = piVar4 + 1;
        }
        uStack_40 = NET_BaseAdrToString();
        iStack_44 = (int)ROUND((float)sv_rcon_banpenalty._12_4_);
        pcStack_48 = "addip %i %s\n";
        aiStack_5c[4] = 0xa3928;
        pcStack_3c = (char *)va();
        uStack_40 = 0xa3933;
        Cbuf_AddText();
        uVar2 = 3;
      }
    }
  }
  return uVar2;
}


// SV_ReachedGoal  @ 000b03f0
undefined4 SV_ReachedGoal(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return 1;
    }
    if (*(float *)(local_8 * 4 + param_1 + 0x150) + param_3 < *(float *)(param_2 + local_8 * 4))
    break;
    fVar2 = *(float *)(local_8 * 4 + param_1 + 0x144) - param_3;
    fVar1 = *(float *)(param_2 + local_8 * 4);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      return 0;
    }
    local_8 = local_8 + 1;
  }
  return 0;
}


// SV_ReadPackets  @ 000a487c
void SV_ReadPackets(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 auStack_5c [5];
  int aiStack_48 [3];
  int *piStack_3c;
  int *piStack_38;
  undefined4 uStack_30;
  int *local_c;
  int local_8;
  
  uStack_30 = 0xa488a;
  while( true ) {
    piStack_3c = (int *)0x1;
    aiStack_48[2] = 0xa48a2;
    iVar1 = NET_GetPacket();
    if (iVar1 == 0) break;
    uStack_30 = 0xa48b5;
    iVar1 = SV_FilterPacket();
    if (iVar1 == 0) {
      if (*DAT_0059d8c8 == -1) {
        uStack_30 = 0xa48d7;
        SV_ConnectionlessPacket();
      }
      else {
        local_c = DAT_00524284;
        for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
          if (((local_c[3] != 0) || (*local_c != 0)) || (local_c[1] != 0)) {
            piVar2 = local_c + 8;
            piVar4 = aiStack_48;
            for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
              *piVar4 = *piVar2;
              piVar2 = piVar2 + 1;
              piVar4 = piVar4 + 1;
            }
            puVar3 = &net_from;
            puVar5 = auStack_5c;
            for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar5 = *puVar3;
              puVar3 = puVar3 + 1;
              puVar5 = puVar5 + 1;
            }
            iVar1 = NET_CompareAdr();
            if (iVar1 != 0) {
              piStack_3c = local_c + 7;
              aiStack_48[2] = 0xa4973;
              iVar1 = Netchan_Process();
              if (iVar1 != 0) {
                if (DAT_00524288 == 1) {
                  local_c[0xd1e] = 1;
                }
                if (((*local_c == 0) || (local_c[1] == 0)) || (local_c[2] == 0)) {
                  local_c[0xd1e] = 1;
                }
                piStack_3c = local_c;
                aiStack_48[2] = 0xa49cd;
                SV_ExecuteClientMessage();
                DAT_0036b224 = (float)host_frametime;
              }
              piStack_3c = local_c + 7;
              aiStack_48[2] = 0xa49f0;
              iVar1 = Netchan_IncomingReady();
              if (iVar1 != 0) {
                piStack_3c = local_c + 7;
                aiStack_48[2] = 0xa4a08;
                iVar1 = Netchan_CopyNormalFragments();
                if (iVar1 != 0) {
                  uStack_30 = 0xa4a16;
                  MSG_BeginReading();
                  piStack_3c = local_c;
                  aiStack_48[2] = 0xa4a22;
                  SV_ExecuteClientMessage();
                }
                piStack_3c = local_c + 7;
                aiStack_48[2] = 0xa4a34;
                iVar1 = Netchan_CopyFileFragments();
                if (iVar1 != 0) {
                  host_client = local_c;
                  piStack_38 = local_c + 0x7ff;
                  piStack_3c = local_c;
                  aiStack_48[2] = 0xa4a5d;
                  SV_ProcessFile();
                }
              }
            }
          }
          local_c = local_c + 0x13bb;
        }
      }
    }
    else {
      uStack_30 = 0xa48c0;
      SV_SendBan();
    }
  }
  return;
}


// SV_ReallocateDynamicData  @ 0009b830
void SV_ReallocateDynamicData(void)

{
  int iVar1;
  
  iVar1 = DAT_003a78b4;
  if (DAT_003a78b4 == 0) {
    Con_DPrintf("SV_ReallocateDynamicData with sv.max_edicts == 0");
  }
  else {
    if (g_moved_edict != 0) {
      Con_Printf("Reallocate on moved_edict\n");
    }
    g_moved_edict = Mem_ZeroMalloc(iVar1 * 4);
    if (g_moved_from != 0) {
      Con_Printf("Reallocate on moved_from\n");
    }
    g_moved_from = Mem_ZeroMalloc(iVar1 * 0xc);
  }
  return;
}


// SV_ReconnectAllClients  @ 000a8ec0
void SV_ReconnectAllClients(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 local_2c [9];
  int local_8;
  
  pcVar2 = "Server updating Security Module.\n";
  puVar3 = local_2c;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  host_client = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (((*host_client != 0) || (host_client[3] != 0)) && (host_client[0x90e] == 0)) {
      Netchan_Clear(host_client + 7);
      MSG_WriteByte(host_client + 0x1d,8);
      MSG_WriteString(host_client + 0x1d,local_2c);
      MSG_WriteByte(host_client + 0x1d,9);
      MSG_WriteString(host_client + 0x1d,"retry\n");
      SV_DropClient(host_client,0,local_2c);
    }
    host_client = host_client + 0x13bb;
  }
  FUN_000a9000();
  return;
}


// SV_RecursiveHullCheck  @ 000bf394
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
              param_7[8] = (int)(vec3_origin - *local_c);
              param_7[9] = (int)(DAT_000f1be0 - local_c[1]);
              param_7[10] = (int)(DAT_000f1be4 - local_c[2]);
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


// SV_RecursiveWaterLevel  @ 000b3440
longdouble SV_RecursiveWaterLevel(undefined4 *param_1,float param_2,float param_3,int param_4)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  fVar1 = (param_2 - param_3) * 0.5 + param_3;
  param_4 = param_4 + 1;
  if (param_4 < 6) {
    local_10 = *param_1;
    local_c = param_1[1];
    local_8 = (float)param_1[2] + fVar1;
    iVar2 = SV_PointContents(&local_10);
    if (iVar2 == -3) {
      lVar3 = (longdouble)SV_RecursiveWaterLevel(param_1,param_2,fVar1,param_4);
    }
    else {
      lVar3 = (longdouble)SV_RecursiveWaterLevel(param_1,fVar1,param_3,param_4);
    }
  }
  else {
    lVar3 = (longdouble)fVar1;
  }
  return lVar3;
}


// SV_RegisterDelta  @ 000ad26c
void SV_RegisterDelta(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = DELTA_Load(param_1,&local_8,param_2);
  if (iVar1 == 0) {
    Sys_Error("Error parsing %s!!!\n",param_2);
  }
  else {
    puVar2 = (undefined4 *)Mem_ZeroMalloc(0x10);
    uVar3 = Mem_Strdup(param_2);
    puVar2[2] = uVar3;
    uVar3 = Mem_Strdup(param_1);
    puVar2[1] = uVar3;
    puVar2[3] = local_8;
    *puVar2 = g_sv_delta;
    g_sv_delta = puVar2;
  }
  return;
}


// SV_RegisterResources  @ 000b5a94
void SV_RegisterResources(void)

{
  int iVar1;
  undefined4 local_8;
  
  *(undefined4 *)(host_client + 0x10) = 0;
  iVar1 = host_client;
  for (local_8 = *(int *)(host_client + 0x4c98); local_8 != iVar1 + 0x4c18;
      local_8 = *(int *)(local_8 + 0x80)) {
    SV_CreateCustomizationList(iVar1);
    SV_Customization(iVar1,local_8,1);
  }
  host_client = iVar1;
  return;
}


// SV_RejectConnection  @ 0009f3a0
void SV_RejectConnection(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_430;
  char local_408 [1024];
  undefined1 *local_8;
  
  local_8 = &stack0x0000000c;
  uStack_430 = 0x9f3d7;
  vsnprintf(local_408,0x400,param_2,local_8);
  uStack_430 = 0x9f3eb;
  SZ_Clear();
  uStack_430 = 0x9f401;
  MSG_WriteLong();
  uStack_430 = 0x9f417;
  MSG_WriteByte();
  uStack_430 = 0x9f432;
  MSG_WriteString();
  puVar2 = &uStack_430;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  NET_SendPacket(1,DAT_0059d8d0,DAT_0059d8c8);
  uStack_430 = 0x9f476;
  SZ_Clear();
  uStack_430 = 0x9f48a;
  iVar1 = COM_CheckParm();
  if (iVar1 == 0) {
    uStack_430 = 0x9f49f;
    WON_RemoveUserbyAddress();
  }
  return;
}


// SV_RejectConnectionForPassword  @ 0009f4b0
void SV_RejectConnectionForPassword(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  char *apcStack_30 [4];
  undefined4 uStack_20;
  
  uStack_20 = 0x9f4be;
  apcStack_30[1] = (char *)&net_message;
  apcStack_30[0] = (char *)0x9f4d6;
  SZ_Clear();
  apcStack_30[2] = (char *)0xffffffff;
  apcStack_30[1] = (char *)&net_message;
  apcStack_30[0] = (char *)0x9f4ec;
  MSG_WriteLong();
  apcStack_30[2] = (char *)0x38;
  apcStack_30[1] = (char *)&net_message;
  apcStack_30[0] = (char *)0x9f502;
  MSG_WriteByte();
  apcStack_30[2] = "BADPASSWORD";
  apcStack_30[1] = (char *)&net_message;
  apcStack_30[0] = (char *)0x9f51f;
  MSG_WriteString();
  puVar2 = param_1;
  ppcVar3 = apcStack_30;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar3 = (char *)*puVar2;
    puVar2 = puVar2 + 1;
    ppcVar3 = ppcVar3 + 1;
  }
  NET_SendPacket(1,DAT_0059d8d0,DAT_0059d8c8);
  apcStack_30[1] = (char *)&net_message;
  apcStack_30[0] = (char *)0x9f563;
  SZ_Clear();
  apcStack_30[1] = "-steam";
  apcStack_30[0] = (char *)0x9f577;
  iVar1 = COM_CheckParm();
  if (iVar1 == 0) {
    apcStack_30[1] = (char *)param_1;
    apcStack_30[0] = (char *)0x9f58c;
    WON_RemoveUserbyAddress();
  }
  return;
}


// SV_RemoveFromResourceList  @ 000b5c9c
void SV_RemoveFromResourceList(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x84) + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(*(int *)(param_1 + 0x80) + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}


// SV_RemoveIP_f  @ 000abd8c
void SV_RemoveIP_f(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  piVar3 = &local_14;
  uVar1 = Cmd_Argv(1);
  iVar2 = StringToFilter(uVar1,piVar3);
  if (iVar2 != 0) {
    for (local_18 = 0; local_18 < numipfilters; local_18 = local_18 + 1) {
      if ((*(int *)(ipfilters + local_18 * 0x10) == local_14) &&
         (*(int *)(ipfilters + local_18 * 0x10 + 4) == local_10)) {
        while (local_1c = local_18 + 1, local_1c < numipfilters) {
          local_18 = local_18 * 0x10;
          iVar2 = local_1c * 0x10;
          *(undefined4 *)(ipfilters + local_18) = *(undefined4 *)(ipfilters + iVar2);
          *(undefined4 *)(ipfilters + local_18 + 4) = *(undefined4 *)(ipfilters + iVar2 + 4);
          *(undefined4 *)(ipfilters + local_18 + 8) = *(undefined4 *)(ipfilters + iVar2 + 8);
          *(undefined4 *)(ipfilters + local_18 + 0xc) = *(undefined4 *)(ipfilters + iVar2 + 0xc);
          local_18 = local_1c;
        }
        numipfilters = numipfilters + -1;
        *(undefined4 *)(ipfilters + numipfilters * 0x10 + 0xc) = 0;
        *(undefined4 *)(ipfilters + numipfilters * 0x10 + 8) = 0;
        *(undefined4 *)(ipfilters + numipfilters * 0x10 + 4) = 0;
        *(undefined4 *)(ipfilters + numipfilters * 0x10) = 0;
        Con_Printf("IP filter removed.\n");
        return;
      }
    }
    uVar1 = Cmd_Argv(1);
    Con_Printf("removeip: couldn\'t find %s.\n",uVar1);
  }
  return;
}


// SV_RemoveId_f  @ 000ab3d4
void SV_RemoveId_f(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  undefined4 local_64 [5];
  int local_50;
  char local_4c;
  undefined1 local_4b [62];
  undefined1 local_d;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  iVar1 = Cmd_Argc();
  if ((iVar1 != 2) && (iVar1 = Cmd_Argc(), iVar1 != 4)) {
    Con_Printf(FUN_000ea9e0);
    return;
  }
  sVar8 = 0x3f;
  pcVar2 = (char *)Cmd_Argv(1);
  strncpy(&local_4c,pcVar2,sVar8);
  local_d = 0;
  if (local_4c == '\0') {
    Con_Printf("SV_RemoveId_f:  Id string is empty!\n");
    return;
  }
  if (local_4c == '#') {
    local_50 = Q_atoi(local_4b);
    if ((0 < local_50) && (local_50 <= numuserfilters)) {
      local_50 = local_50 + -1;
      puVar6 = (undefined4 *)(userfilters + local_50 * 0x1c);
      puVar7 = local_64;
      for (iVar1 = 5; iVar5 = local_50, iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      while (local_c = iVar5 + 1, local_c < numuserfilters) {
        puVar6 = (undefined4 *)(userfilters + local_c * 0x1c);
        puVar7 = (undefined4 *)(userfilters + iVar5 * 0x1c);
        for (iVar1 = 7; iVar5 = local_c, iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      numuserfilters = numuserfilters + -1;
      uVar3 = SV_GetIDString(local_64);
      Con_Printf("UserID filter removed for %s, id %s\n",&local_4c,uVar3);
      return;
    }
    Con_Printf("SV_RemoveId_f:  invalid slot #%i\n",local_50);
    return;
  }
  sVar8 = strlen("STEAM_");
  iVar1 = Q_strnicmp(&local_4c,"STEAM_",sVar8);
  if (iVar1 != 0) {
    sVar8 = strlen("VALVE_");
    iVar1 = Q_strnicmp(&local_4c,"VALVE_",sVar8);
    if (iVar1 != 0) goto code_r0x000ab647;
  }
  uVar3 = Cmd_Argv(3);
  uVar4 = Cmd_Argv(1);
  snprintf(&local_4c,0x3f,"%s:%s",uVar4,uVar3);
  local_d = 0;
code_r0x000ab647:
  local_8 = 0;
  while( true ) {
    if (numuserfilters <= local_8) {
      Con_Printf("removeid: couldn\'t find %s\n",&local_4c);
      return;
    }
    pcVar2 = &local_4c;
    uVar3 = SV_GetIDString(userfilters + local_8 * 0x1c);
    iVar5 = Q_stricmp(uVar3,pcVar2);
    iVar1 = local_8;
    if (iVar5 == 0) break;
    local_8 = local_8 + 1;
  }
  while (local_c = iVar1 + 1, local_c < numuserfilters) {
    puVar6 = (undefined4 *)(userfilters + local_c * 0x1c);
    puVar7 = (undefined4 *)(userfilters + iVar1 * 0x1c);
    for (iVar5 = 7; iVar1 = local_c, iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  numuserfilters = numuserfilters + -1;
  Con_Printf("UserID filter removed for %s\n",&local_4c);
  return;
}


// SV_RemoveSteamValidation  @ 000ae9b4
void SV_RemoveSteamValidation(int param_1)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  iVar2 = g_nValidators;
  do {
    local_c = iVar2;
    local_8 = local_c + -1;
    if (local_8 < 0) {
      return;
    }
    iVar1 = local_8 * 0xc;
    iVar2 = local_8;
  } while ((g_rgValidator + iVar1 == (undefined1 *)0x0) ||
          (iVar2 = local_8, *(int *)(g_rgValidator + iVar1 + 4) != param_1));
  if (*(int *)(g_rgValidator + iVar1 + 8) != 0) {
    SteamAbortOngoingUserIDTicketValidation(*(undefined4 *)(g_rgValidator + iVar1 + 8));
  }
  memset(g_rgValidator + iVar1,0,0xc);
  for (; local_c < g_nValidators; local_c = local_c + 1) {
    iVar2 = local_8 * 0xc;
    iVar1 = local_c * 0xc;
    *(undefined4 *)(g_rgValidator + iVar2) = *(undefined4 *)(g_rgValidator + iVar1);
    *(undefined4 *)(g_rgValidator + iVar2 + 4) = *(undefined4 *)(g_rgValidator + iVar1 + 4);
    *(undefined4 *)(g_rgValidator + iVar2 + 8) = *(undefined4 *)(g_rgValidator + iVar1 + 8);
  }
  g_nValidators = g_nValidators + -1;
  return;
}


// SV_RequestMissingResources  @ 000b5fe8
undefined4 SV_RequestMissingResources(void)

{
  if ((*(int *)(host_client + 0x10) != 0) && (*(int *)(host_client + 0x4d2c) == 0)) {
    SV_UploadComplete(host_client);
  }
  return 0;
}


// SV_RequestMissingResourcesFromClients  @ 000b5db8
void SV_RequestMissingResourcesFromClients(void)

{
  int iVar1;
  int local_8;
  
  host_client = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (*host_client != 0) goto LAB_000b5e18;
    iVar1 = host_client[1];
    while (iVar1 != 0) {
LAB_000b5e18:
      iVar1 = SV_RequestMissingResources();
    }
    host_client = host_client + 0x13bb;
  }
  return;
}


// SV_ResetModInfo  @ 000a1d18
void SV_ResetModInfo(void)

{
  Q_memset(&gmodinfo,0,0x238);
  DAT_0036ae84 = 1;
  DAT_0036ae8c = 1;
  return;
}


// SV_ResetRcon_f  @ 000a3218
void SV_ResetRcon_f(void)

{
  Q_memset(g_rgRconFailures,0,0xe80);
  return;
}


// SV_RestoreMove  @ 000ba564
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_RestoreMove(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  if (nofind == 0) {
    iVar1 = (*_DAT_0036b004)();
    if (((((iVar1 != 0) && (1 < DAT_00524288)) &&
         ((byte)(0.0 < (float)sv_unlag._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
        ((param_1[0x1376] != 0 && (param_1[0x1377] != 0)))) && (*param_1 != 0)) {
      for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
        piVar3 = (int *)(DAT_00524284 + local_8 * 0x4eec);
        if ((piVar3 != param_1) && (*piVar3 != 0)) {
          iVar1 = local_8 * 0x58;
          iVar2 = VectorCompare(iVar1 + 0x140c28,iVar1 + 0x140c34);
          if ((iVar2 == 0) && (*(int *)(truepositions + iVar1 + 4) != 0)) {
            if (*(int *)(truepositions + iVar1) == 0) {
              Con_DPrintf("SV_RestoreMove:  Tried to restore \'inactive\' player %i/%s\n",local_8,
                          piVar3 + 0x12fb);
            }
            else {
              iVar2 = VectorCompare(iVar1 + 0x140c40,piVar3[0x12a1] + 0x88);
              if (iVar2 != 0) {
                *(undefined4 *)(piVar3[0x12a1] + 0x88) =
                     *(undefined4 *)(truepositions + iVar1 + 0x14);
                *(undefined4 *)(piVar3[0x12a1] + 0x8c) =
                     *(undefined4 *)(truepositions + iVar1 + 0x18);
                *(undefined4 *)(piVar3[0x12a1] + 0x90) =
                     *(undefined4 *)(truepositions + iVar1 + 0x1c);
                SV_LinkEdict(piVar3[0x12a1],0);
              }
            }
          }
        }
      }
    }
  }
  else {
    nofind = 0;
  }
  return;
}


// SV_RunCmd  @ 000b8028
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_RunCmd(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  longdouble lVar4;
  double dVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  longdouble lVar13;
  undefined4 local_80;
  undefined1 local_60;
  float local_4c;
  undefined1 local_48 [56];
  int local_10;
  int local_c;
  undefined4 local_8;
  
  iVar8 = host_client;
  puVar9 = param_1;
  puVar11 = &local_80;
  for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  if (*(double *)(host_client + 0x2484) <= realtime) {
    *(undefined4 *)(host_client + 0x2484) = 0;
    *(undefined4 *)(iVar8 + 0x2488) = 0;
    dVar5 = (double)local_80._2_1_;
    if ((byte)(50.0 < dVar5 | (byte)((ushort)((ushort)NAN(dVar5) << 10) >> 8) |
              (byte)((ushort)((ushort)(dVar5 == 50.0) << 0xe) >> 8)) == 1) {
      bVar3 = *(byte *)((int)param_1 + 2);
      local_80._2_1_ = (byte)(int)ROUND((float)bVar3 / 2.0);
      SV_RunCmd(&local_80,param_2);
      local_80._2_1_ = (byte)(int)ROUND((float)bVar3 / 2.0);
      local_60 = 0;
      SV_RunCmd(&local_80,param_2);
    }
    else {
      if (*(int *)(host_client + 0x2438) == 0) {
        SV_SetupMove(host_client);
      }
      (*_DAT_0036afec)(sv_player,param_1,param_2);
      local_4c = (float)*(byte *)((int)param_1 + 2) * 0.001;
      *(double *)(host_client + 0x24a4) =
           (double)((float)*(double *)(host_client + 0x24a4) + local_4c);
      *(double *)(host_client + 0x247c) =
           *(double *)(host_client + 0x247c) + (double)*(byte *)((int)param_1 + 2) / 1000.0;
      if ((*(char *)(param_1 + 8) != '\0') &&
         (*(uint *)(sv_player + 0x204) = (uint)*(byte *)(param_1 + 8),
         *(char *)(param_1 + 8) == -0x34)) {
        SV_ForceFullClientsUpdate();
      }
      *(undefined4 *)(sv_player + 0xb8) = 0;
      *(undefined4 *)(sv_player + 0xbc) = 0;
      *(undefined4 *)(sv_player + 0xc0) = 0;
      *(uint *)(sv_player + 0x200) = (uint)*(ushort *)((int)param_1 + 0x1e);
      SV_CheckMovingGround(sv_player,local_4c);
      pmove[0x14] = *(int *)(sv_player + 0xf4);
      pmove[0x15] = *(int *)(sv_player + 0xf8);
      pmove[0x16] = *(int *)(sv_player + 0xfc);
      if (*(int *)(sv_player + 0x120) == 0) {
        *(undefined4 *)(sv_player + 0xf4) = param_1[1];
        *(undefined4 *)(sv_player + 0xf8) = param_1[2];
        *(undefined4 *)(sv_player + 0xfc) = param_1[3];
      }
      SV_PlayerRunPreThink(sv_player,(float)*(double *)(host_client + 0x24a4));
      SV_PlayerRunThink(sv_player,local_4c,*(undefined8 *)(host_client + 0x24a4));
      lVar13 = (longdouble)Length(sv_player + 0xac);
      lVar4 = (longdouble)0;
      if ((byte)(lVar4 < lVar13 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar13)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar4 == lVar13) << 0xe) >> 8)) == 1) {
        *(undefined4 *)(sv_player + 0xb8) = *(undefined4 *)(sv_player + 0xac);
        *(undefined4 *)(sv_player + 0xbc) = *(undefined4 *)(sv_player + 0xb0);
        *(undefined4 *)(sv_player + 0xc0) = *(undefined4 *)(sv_player + 0xb4);
      }
      pmove[1] = 1;
      pmove[2] = (uint)(1 < DAT_00524288);
      pmove[3] = (int)(float)((longdouble)1000.0 * (longdouble)*(double *)(host_client + 0x24a4));
      pmove[0x2f] = *(uint *)(sv_player + 0x224) >> 0xe & 1;
      pmove[0x7d] = sv_maxspeed._12_4_;
      pmove[0x7e] = *(int *)(sv_player + 0x290);
      pmove[0x23] = (int)(float)*(int *)(sv_player + 0x2ac);
      pmove[0x24] = *(int *)(sv_player + 0x2a0);
      pmove[0x25] = *(int *)(sv_player + 0x2a4);
      pmove[0x26] = *(int *)(sv_player + 0x2b0);
      pmove[0x27] = *(int *)(sv_player + 0x2b4);
      pmove[0x2b] = (int)(float)*(int *)(sv_player + 0x2a8);
      pmove[0x32] = *(int *)(sv_player + 700);
      Q_strncpy(pmove + 0x13cfc,host_client + 0x4de0,0xff);
      *(undefined1 *)((int)pmove + 0x4f4ef) = 0;
      pmove[0x17] = *(int *)(sv_player + 0xa0);
      pmove[0x18] = *(int *)(sv_player + 0xa4);
      pmove[0x19] = *(int *)(sv_player + 0xa8);
      pmove[0x1a] = *(int *)(sv_player + 0xc4);
      pmove[0x1b] = *(int *)(sv_player + 200);
      pmove[0x1c] = *(int *)(sv_player + 0xcc);
      pmove[0x11] = *(int *)(sv_player + 0xf4);
      pmove[0x12] = *(int *)(sv_player + 0xf8);
      pmove[0x13] = *(int *)(sv_player + 0xfc);
      pmove[0x1d] = *(int *)(sv_player + 0xac);
      pmove[0x1e] = *(int *)(sv_player + 0xb0);
      pmove[0x1f] = *(int *)(sv_player + 0xb4);
      pmove[0x20] = *(int *)(sv_player + 500);
      pmove[0x21] = *(int *)(sv_player + 0x1f8);
      pmove[0x22] = *(int *)(sv_player + 0x1fc);
      pmove[0x28] = *(int *)(sv_player + 0xe8);
      pmove[0x29] = *(int *)(sv_player + 0xec);
      pmove[0x2a] = *(int *)(sv_player + 0xf0);
      pmove[0x35] = *(int *)(sv_player + 0x1f0);
      pmove[0x2d] = *(int *)(sv_player + 0x198);
      pmove[0x30] = *(int *)(sv_player + 0x19c);
      pmove[0x31] = *(int *)(sv_player + 0x1a0);
      pmove[0x36] = 0;
      pmove[0x33] = *(int *)(sv_player + 0x234);
      piVar10 = &local_80;
      piVar12 = pmove + 0x11516;
      for (iVar8 = 0xd; iVar8 != 0; iVar8 = iVar8 + -1) {
        *piVar12 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar12 = piVar12 + 1;
      }
      pmove[0x34] = (uint)(*(float *)(sv_player + 0x1e0) <= 0.0);
      pmove[0x37] = *(int *)(sv_player + 0x188);
      pmove[0x2e] = *(int *)(sv_player + 0x224);
      iVar8 = NUM_FOR_EDICT(sv_player);
      *pmove = iVar8 + -1;
      pmove[0x7f] = *(int *)(sv_player + 0x2c4);
      pmove[0x80] = *(int *)(sv_player + 0x2c8);
      pmove[0x81] = *(int *)(sv_player + 0x2cc);
      pmove[0x82] = *(int *)(sv_player + 0x2d0);
      pmove[0x83] = *(int *)(sv_player + 0x2d4);
      pmove[0x84] = *(int *)(sv_player + 0x2d8);
      pmove[0x85] = *(int *)(sv_player + 0x2dc);
      pmove[0x86] = *(int *)(sv_player + 0x2e0);
      pmove[0x87] = *(int *)(sv_player + 0x2e4);
      pmove[0x88] = *(int *)(sv_player + 0x2e8);
      pmove[0x89] = *(int *)(sv_player + 0x2ec);
      pmove[0x8a] = *(int *)(sv_player + 0x2f0);
      pmove[0x8b] = *(int *)(sv_player + 0x2f4);
      pmove[0x8c] = *(int *)(sv_player + 0x2f8);
      pmove[0x8d] = *(int *)(sv_player + 0x2fc);
      pmove[0x8e] = *(int *)(sv_player + 0x300);
      pmove[0x8f] = *(int *)(sv_player + 0x304);
      pmove[0x90] = *(int *)(sv_player + 0x308);
      pmove[0x91] = *(int *)(sv_player + 0x30c);
      pmove[0x92] = *(int *)(sv_player + 0x310);
      pmove[0xe] = *(int *)(sv_player + 0x88);
      pmove[0xf] = *(int *)(sv_player + 0x8c);
      pmove[0x10] = *(int *)(sv_player + 0x90);
      SV_AddLinksToPM(&sv_areanodes,pmove + 0xe);
      pmove[4] = (int)local_4c;
      pmove[0x13d6c] = 1;
      pmove[0x13d6d] = (int)PM_SV_PlaySound;
      pmove[0x13d6e] = (int)PM_SV_TraceTexture;
      pmove[0x13d6f] = (int)PM_SV_PlaybackEventFull;
      (*_DAT_0036afc8)(pmove,1);
      *(int *)(sv_player + 0x1f0) = pmove[0x35];
      *(int *)(sv_player + 0x198) = pmove[0x2d];
      *(int *)(sv_player + 0x234) = pmove[0x33];
      *(int *)(sv_player + 0x240) = pmove[0x39];
      *(int *)(sv_player + 0x244) = pmove[0x3a];
      *(int *)(sv_player + 0x224) = pmove[0x2e];
      *(int *)(sv_player + 0x1a0) = pmove[0x31];
      *(int *)(sv_player + 0x188) = pmove[0x37];
      *(int *)(sv_player + 0x290) = pmove[0x7e];
      *(int *)(sv_player + 0x2b0) = pmove[0x26];
      *(int *)(sv_player + 500) = pmove[0x20];
      *(int *)(sv_player + 0x1f8) = pmove[0x21];
      *(int *)(sv_player + 0x1fc) = pmove[0x22];
      *(int *)(sv_player + 0xc4) = pmove[0x1a];
      *(int *)(sv_player + 200) = pmove[0x1b];
      *(int *)(sv_player + 0xcc) = pmove[0x1c];
      *(int *)(sv_player + 0xe8) = pmove[0x28];
      *(int *)(sv_player + 0xec) = pmove[0x29];
      *(int *)(sv_player + 0xf0) = pmove[0x2a];
      if (pmove[0x38] == -1) {
        *(uint *)(sv_player + 0x224) = *(uint *)(sv_player + 0x224) & 0xfffffdff;
      }
      else {
        *(uint *)(sv_player + 0x224) = *(uint *)(sv_player + 0x224) | 0x200;
        uVar6 = EDICT_NUM(pmove[pmove[0x38] * 0x38 + 0xa8]);
        *(undefined4 *)(sv_player + 0x21c) = uVar6;
      }
      *(int *)(sv_player + 0x88) = pmove[0xe];
      *(int *)(sv_player + 0x8c) = pmove[0xf];
      *(int *)(sv_player + 0x90) = pmove[0x10];
      *(int *)(sv_player + 0xa0) = pmove[0x17];
      *(int *)(sv_player + 0xa4) = pmove[0x18];
      *(int *)(sv_player + 0xa8) = pmove[0x19];
      *(int *)(sv_player + 0xac) = pmove[0x1d];
      *(int *)(sv_player + 0xb0) = pmove[0x1e];
      *(int *)(sv_player + 0xb4) = pmove[0x1f];
      if (*(int *)(sv_player + 0x120) == 0) {
        *(int *)(sv_player + 0xf4) = pmove[0x11];
        *(int *)(sv_player + 0xf8) = pmove[0x12];
        *(int *)(sv_player + 0xfc) = pmove[0x13];
        *(int *)(sv_player + 0xd0) = pmove[0x11];
        *(int *)(sv_player + 0xd4) = pmove[0x12];
        *(int *)(sv_player + 0xd8) = pmove[0x13];
        *(float *)(sv_player + 0xd0) = -(float)pmove[0x11] / 3.0;
      }
      *(int *)(sv_player + 0x2a0) = pmove[0x24];
      *(int *)(sv_player + 0x2ac) = (int)ROUND((float)pmove[0x23]);
      *(int *)(sv_player + 0x2a4) = pmove[0x25];
      *(int *)(sv_player + 0x2b4) = pmove[0x27];
      *(int *)(sv_player + 0x2a8) = (int)ROUND((float)pmove[0x2b]);
      *(uint *)(sv_player + 700) = (uint)*(ushort *)((int)pmove + 0x45476);
      *(int *)(sv_player + 0x2c4) = pmove[0x7f];
      *(int *)(sv_player + 0x2c8) = pmove[0x80];
      *(int *)(sv_player + 0x2cc) = pmove[0x81];
      *(int *)(sv_player + 0x2d0) = pmove[0x82];
      *(int *)(sv_player + 0x2d4) = pmove[0x83];
      *(int *)(sv_player + 0x2d8) = pmove[0x84];
      *(int *)(sv_player + 0x2dc) = pmove[0x85];
      *(int *)(sv_player + 0x2e0) = pmove[0x86];
      *(int *)(sv_player + 0x2e4) = pmove[0x87];
      *(int *)(sv_player + 0x2e8) = pmove[0x88];
      *(int *)(sv_player + 0x2ec) = pmove[0x89];
      *(int *)(sv_player + 0x2f0) = pmove[0x8a];
      *(int *)(sv_player + 0x2f4) = pmove[0x8b];
      *(int *)(sv_player + 0x2f8) = pmove[0x8c];
      *(int *)(sv_player + 0x2fc) = pmove[0x8d];
      *(int *)(sv_player + 0x300) = pmove[0x8e];
      *(int *)(sv_player + 0x304) = pmove[0x8f];
      *(int *)(sv_player + 0x308) = pmove[0x90];
      *(int *)(sv_player + 0x30c) = pmove[0x91];
      *(int *)(sv_player + 0x310) = pmove[0x92];
      SetMinMaxSize(sv_player,player_mins + pmove[0x2f] * 0xc,player_maxs + pmove[0x2f] * 0xc,0);
      if (*(int *)(*(int *)(host_client + 0x4a84) + 0x18c) != 0) {
        SV_LinkEdict(sv_player,1);
        uVar6 = *(undefined4 *)(sv_player + 0xa0);
        uVar1 = *(undefined4 *)(sv_player + 0xa4);
        uVar2 = *(undefined4 *)(sv_player + 0xa8);
        for (local_c = 0; local_c < pmove[0x11523]; local_c = local_c + 1) {
          local_10 = pmove[pmove[local_c * 0x11 + 0x11530] * 0x38 + 0xa8];
          local_8 = EDICT_NUM(local_10);
          piVar10 = pmove + local_c * 0x11 + 0x11524;
          SV_ConvertPMTrace(local_48,piVar10,local_8);
          *(int *)(sv_player + 0xa0) = piVar10[0xd];
          *(int *)(sv_player + 0xa4) = piVar10[0xe];
          *(int *)(sv_player + 0xa8) = piVar10[0xf];
          SV_Impact(local_8,sv_player,local_48);
        }
        *(undefined4 *)(sv_player + 0xa0) = uVar6;
        *(undefined4 *)(sv_player + 0xa4) = uVar1;
        *(undefined4 *)(sv_player + 0xa8) = uVar2;
      }
      gGlobalVariables = (float)*(double *)(host_client + 0x24a4);
      DAT_0036b224 = local_4c;
      (*_DAT_0036afa0)(sv_player);
      (*_DAT_0036aff0)(sv_player);
      if (*(int *)(host_client + 0x2438) == 0) {
        SV_RestoreMove(host_client);
      }
    }
  }
  else {
    *(double *)(host_client + 0x247c) =
         *(double *)(host_client + 0x247c) + (double)*(byte *)((int)param_1 + 2) / 1000.0;
  }
  return;
}


// SV_RunThink  @ 000b0f7c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool SV_RunThink(int *param_1)

{
  double dVar1;
  double dVar2;
  float fVar3;
  bool bVar4;
  float local_8;
  
  if ((param_1[0x89] & 0x40000000U) == 0) {
    local_8 = (float)param_1[0x61];
    if (0.0 < local_8) {
      dVar2 = (double)local_8;
      dVar1 = DAT_0036bc6c + host_frametime;
      if ((byte)(dVar1 < dVar2 | (byte)((ushort)((ushort)(NAN(dVar1) || NAN(dVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(dVar1 == dVar2) << 0xe) >> 8)) != 1) {
        fVar3 = (float)DAT_0036bc6c;
        if ((byte)(local_8 < fVar3 |
                   (byte)((ushort)((ushort)(NAN(local_8) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_8 == fVar3) << 0xe) >> 8)) == 1) {
          local_8 = (float)DAT_0036bc6c;
        }
        param_1[0x61] = 0;
        gGlobalVariables = local_8;
        (*_DAT_0036af48)(param_1);
        goto LAB_000b1045;
      }
    }
    bVar4 = true;
  }
  else {
LAB_000b1045:
    if ((param_1[0x89] & 0x40000000U) != 0) {
      ED_Free(param_1);
    }
    bVar4 = *param_1 == 0;
  }
  return bVar4;
}


// SV_SecureUpdateComplete  @ 000937c0
void SV_SecureUpdateComplete(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 local_3c;
  
  pcVar2 = "Completed updating Security Module from Speakeasy.net\n";
  puVar3 = &local_3c;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  Con_Printf(&local_3c);
  return;
}


// SV_SecureUpdateFailed  @ 00093778
void SV_SecureUpdateFailed(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 local_38;
  
  pcVar2 = "Error updating Security Module from Speakeasy.net\n";
  puVar3 = &local_38;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  Con_DPrintf(&local_38);
  return;
}


// SV_SecurityUpdate  @ 00093808
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_SecurityUpdate(void)

{
  undefined4 uVar1;
  int iVar2;
  longdouble lVar3;
  
  if (DAT_00524368 != 0) {
    switch(gSecureUpdateState) {
    case 0:
      if (_DAT_00524360 <= realtime) {
        SV_ClearSecurityModule(&DAT_00524348);
        SV_ClearSecurityModule(&DAT_00524330);
        gSecureUpdateState = 1;
        UPDATE_UpdateAddressList();
        uVar1 = SV_GetFileNameModuleS(&DAT_00524330,&DAT_00524300);
        UPDATE_GetModule(uVar1);
      }
      break;
    case 1:
      iVar2 = UPDATE_IsActive();
      if (iVar2 == 0) {
        UPDATE_FinishDownload();
        if (DAT_00524334 == 0) {
          gSecureUpdateState = 3;
        }
        else {
          gSecureUpdateState = 2;
          uVar1 = SV_GetFileNameModuleC(&DAT_00524348,&DAT_00524318);
          UPDATE_GetModule(uVar1);
        }
      }
      break;
    case 2:
      iVar2 = UPDATE_IsActive();
      if (iVar2 == 0) {
        UPDATE_FinishDownload();
        if (DAT_0052434c == 0) {
          gSecureUpdateState = 3;
        }
        else {
          lVar3 = (longdouble)UPDATE_GetUpdateInterval();
          _DAT_00524360 = (double)(float)lVar3 + realtime;
          gSecureUpdateState = 4;
        }
      }
      break;
    case 3:
      SV_ClearSecurityModule(&DAT_00524348);
      SV_ClearSecurityModule(&DAT_00524330);
      SV_SecureUpdateFailed();
      _DAT_00524360 = realtime + 120.0;
      gSecureUpdateState = 0;
      break;
    case 4:
      break;
    default:
      Host_Error("Invalid state %i.\n",gSecureUpdateState);
    }
    UPDATE_Resend();
  }
  return;
}


// SV_SendBan  @ 000a47a4
void SV_SendBan(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uStack_70;
  char local_44 [64];
  
  uStack_70 = 0xa47d0;
  snprintf(local_44,0x40,"You have been banned from this server.\n");
  uStack_70 = 0xa47e4;
  SZ_Clear();
  uStack_70 = 0xa47fa;
  MSG_WriteLong();
  uStack_70 = 0xa4810;
  MSG_WriteByte();
  uStack_70 = 0xa4828;
  MSG_WriteString();
  puVar2 = &net_from;
  puVar3 = &uStack_70;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  NET_SendPacket(1,DAT_0059d8d0,DAT_0059d8c8);
  uStack_70 = 0xa486f;
  SZ_Clear();
  return;
}


// SV_SendClientDatagram  @ 000a6b40
undefined4 SV_SendClientDatagram(int param_1)

{
  char *local_fb8;
  uint local_fb4;
  undefined1 *local_fb0;
  undefined4 local_fac;
  undefined4 local_fa8;
  undefined1 local_fa4 [4000];
  
  local_fb8 = "Client Datagram";
  local_fb0 = local_fa4;
  local_fac = 4000;
  local_fa8 = 0;
  local_fb4 = CONCAT22(local_fb4._2_2_,1);
  MSG_WriteByte(&local_fb8,7);
  MSG_WriteFloat(&local_fb8,(float)DAT_0036bc6c);
  SV_WriteClientdataToMessage(param_1,&local_fb8);
  SV_WriteEntitiesToClient(param_1,&local_fb8);
  if ((*(ushort *)(param_1 + 0x24b0) & 2) == 0) {
    SZ_Write(&local_fb8,*(undefined4 *)(param_1 + 0x24b4),*(undefined4 *)(param_1 + 0x24bc));
  }
  else {
    Con_Printf("WARNING: datagram overflowed for %s\n",param_1 + 0x4bec);
  }
  SZ_Clear(param_1 + 0x24ac);
  if ((local_fb4 & 2) != 0) {
    Con_Printf("WARNING: msg overflowed for %s\n",param_1 + 0x4bec);
    SZ_Clear(&local_fb8);
  }
  Netchan_Transmit(param_1 + 0x1c,local_fa8,local_fa4);
  return 1;
}


// SV_SendClientMessages  @ 000a7194
void SV_SendClientMessages(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  SV_UpdateToReliableMessages();
  host_client = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if ((((*host_client != 0) || (host_client[3] != 0)) || (host_client[1] != 0)) &&
       (host_client[0x90e] == 0)) {
      if (host_client[0xd1f] == 0) {
        if (((byte)((byte)((ushort)((ushort)NAN((float)host_limitlocal._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)host_limitlocal._12_4_ == 0.0) << 0xe) >> 8)) ==
             0x40) && (host_client[8] == 1)) {
          host_client[0xd1e] = 1;
        }
        if (((*host_client != 0) && (host_client[1] != 0)) &&
           ((host_client[2] != 0 && (*(double *)(host_client + 0xd1a) <= realtime + host_frametime))
           )) {
          host_client[0xd1e] = 1;
        }
        if ((*(ushort *)(host_client + 0x1e) & 2) == 0) {
          if ((host_client[0xd1e] != 0) &&
             (fVar1 = (float)realtime - (float)host_client[0xe],
             (byte)((float)sv_failuretime._12_4_ < fVar1 |
                    (byte)((ushort)((ushort)(NAN((float)sv_failuretime._12_4_) || NAN(fVar1)) << 10)
                          >> 8) |
                   (byte)((ushort)((ushort)((float)sv_failuretime._12_4_ == fVar1) << 0xe) >> 8)) ==
             1)) {
            host_client[0xd1e] = 0;
          }
        }
        else {
          SZ_Clear(host_client + 0x1d);
          SZ_Clear(host_client + 0x92b);
          SV_BroadcastPrintf("%s overflowed\n",host_client + 0x12fb);
          Con_Printf("WARNING: reliable overflow for %s\n",host_client + 0x12fb);
          SV_DropClient(host_client,0,"Reliable channel overflowed");
          host_client[0xd1e] = 1;
          piVar2 = host_client;
          host_client[0x12] = 0;
          piVar2[0x13] = 0;
        }
        if (host_client[0xd1e] != 0) {
          iVar3 = Netchan_CanPacket(host_client + 7);
          if (iVar3 == 0) {
            host_client[0x90c] = host_client[0x90c] + 1;
          }
          else {
            host_client[0xd1e] = 0;
            *(double *)(host_client + 0xd1a) =
                 realtime + host_frametime + *(double *)(host_client + 0xd1c);
            if (((*host_client == 0) || (host_client[1] == 0)) || (host_client[2] == 0)) {
              Netchan_Transmit(host_client + 7,0,0);
            }
            else {
              SV_SendClientDatagram(host_client);
            }
          }
        }
      }
      else {
        host_client[0xd1f] = 0;
      }
    }
    host_client = host_client + 0x13bb;
  }
  FUN_000a7504();
  return;
}


// SV_SendConsistencyList  @ 000b6d88
void SV_SendConsistencyList(void)

{
  int local_10;
  int local_8;
  
  local_10 = 0;
  *(undefined4 *)(host_client + 0x18) = 0;
  if ((((DAT_00524288 == 1) ||
       ((byte)(0.0 < (float)mp_consistency._12_4_ |
               (byte)((ushort)((ushort)NAN((float)mp_consistency._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)mp_consistency._12_4_ == 0.0) << 0xe) >> 8)) == 0x40))
      || (DAT_0039bda4 == 0)) || (*(int *)(host_client + 0x243c) != 0)) {
    MSG_WriteBits(0,1);
  }
  else {
    *(undefined4 *)(host_client + 0x18) = 1;
    MSG_WriteBits(1,1);
    for (local_8 = 0; local_8 < DAT_003965a0; local_8 = local_8 + 1) {
      if ((local_8 * 0x88 != -0x36bda0) && (((&DAT_0036bdec)[local_8 * 0x88] & 0x80) != 0)) {
        MSG_WriteBits(1,1);
        if (local_8 - local_10 < 0x20) {
          MSG_WriteBits(1,1);
          MSG_WriteBits(local_8 - local_10,5);
        }
        else {
          MSG_WriteBits(0,1);
          MSG_WriteBits(local_8,10);
        }
        local_10 = local_8;
      }
    }
    MSG_WriteBits(0,1);
  }
  return;
}


// SV_SendEnts_f  @ 000bb7a4
void SV_SendEnts_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else if (((*host_client != 0) && (host_client[1] != 0)) && (host_client[3] != 0)) {
    host_client[2] = 1;
  }
  return;
}


// SV_SendRes_f  @ 0009ef98
void SV_SendRes_f(void)

{
  char *apcStack_10018 [2];
  undefined1 *puStack_10010;
  undefined4 uStack_1000c;
  undefined4 uStack_10008;
  undefined1 auStack_10004 [65536];
  
  Q_memset(apcStack_10018,0,0x14);
  apcStack_10018[0] = "SendResources";
  puStack_10010 = auStack_10004;
  uStack_10008 = 0;
  uStack_1000c = 0x10000;
  if ((cmd_source != 1) && ((host_client[1] == 0 || (*host_client != 0)))) {
    SV_SendResources(apcStack_10018);
    Netchan_CreateFragments(1,host_client + 7,apcStack_10018);
    Netchan_FragSend(host_client + 7);
  }
  return;
}


// SV_SendResources  @ 0009dde8
void SV_SendResources(undefined4 param_1)

{
  int iVar1;
  undefined1 local_28 [32];
  int local_8;
  
  Q_memset(local_28,0,0x20);
  MSG_WriteByte(param_1,0x2d);
  MSG_WriteLong(param_1,DAT_00524290);
  MSG_WriteLong(param_1,0);
  MSG_WriteByte(param_1,0x2b);
  MSG_StartBitWriting(param_1);
  MSG_WriteBits(DAT_003965a0,0xc);
  for (local_8 = 0; local_8 < DAT_003965a0; local_8 = local_8 + 1) {
    MSG_WriteBits(*(undefined4 *)(&DAT_0036bde0 + local_8 * 0x88),4);
    MSG_WriteBitString(&DAT_0036bda0 + local_8 * 0x88);
    MSG_WriteBits(*(undefined4 *)(&DAT_0036bde4 + local_8 * 0x88),0xc);
    MSG_WriteBits(*(undefined4 *)(&DAT_0036bde8 + local_8 * 0x88),0x18);
    MSG_WriteBits((&DAT_0036bdec)[local_8 * 0x88] & 3,3);
    if (((&DAT_0036bdec)[local_8 * 0x88] & 4) != 0) {
      MSG_WriteBitData(&DAT_0036bded + local_8 * 0x88,0x10);
    }
    iVar1 = Q_memcmp(&DAT_0036bdfe + local_8 * 0x88,local_28,0x20);
    if (iVar1 == 0) {
      MSG_WriteBits(0,1);
    }
    else {
      MSG_WriteBits(1,1);
      MSG_WriteBitData(&DAT_0036bdfe + local_8 * 0x88,0x20);
    }
  }
  SV_SendConsistencyList(param_1);
  MSG_EndBitWriting(param_1);
  return;
}


// SV_SendServerinfo  @ 0009d988
void SV_SendServerinfo(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_818;
  int local_814;
  int local_810;
  int local_80c;
  undefined4 local_808;
  char local_804 [2048];
  
  local_808 = 0;
  if (((byte)((byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) ||
     (1 < DAT_00524288)) {
    MSG_WriteByte(param_1,8);
    uVar1 = build_number(0,DAT_00524290);
    snprintf(local_804,0x800,"%c\nBUILD %d SERVER (%i CRC)\nServer # %i\n",2,uVar1);
    MSG_WriteString(param_1,local_804);
  }
  MSG_WriteByte(param_1,0xb);
  MSG_WriteLong(param_1,0x2e);
  MSG_WriteLong(param_1,DAT_00524290);
  local_80c = NUM_FOR_EDICT(*(undefined4 *)(param_2 + 0x4a84));
  local_80c = local_80c + -1;
  local_818 = DAT_0036bd8c;
  COM_Munge3(&local_818,4,0xffU - local_80c & 0xff);
  MSG_WriteLong(param_1,local_818);
  MSG_WriteBuf(param_1,0x10,&DAT_0036bd90);
  MSG_WriteByte(param_1,DAT_00524288);
  MSG_WriteByte(param_1,local_80c);
  if (((byte)((byte)((ushort)((ushort)NAN((float)coop._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)coop._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)(0.0 < (float)deathmatch._12_4_ |
             (byte)((ushort)((ushort)NAN((float)deathmatch._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)deathmatch._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    MSG_WriteByte(param_1,1);
  }
  else {
    MSG_WriteByte(param_1,0);
  }
  COM_FileBase(&com_gamedir,local_804);
  MSG_WriteString(param_1,local_804);
  uVar1 = Cvar_VariableString("hostname");
  MSG_WriteString(param_1,uVar1);
  MSG_WriteString(param_1,&DAT_0036bd48);
  local_810 = COM_LoadFileForMe(mapcyclefile._4_4_,&local_814);
  if ((local_810 == 0) || (local_814 == 0)) {
    MSG_WriteString(param_1,"mapcycle failure");
  }
  else {
    MSG_WriteString(param_1,local_810);
    COM_FreeFile(local_810);
  }
  MSG_WriteByte(param_1,DAT_00524368);
  if (DAT_00524368 != 0) {
    MSG_WriteByte(param_1,4);
    MSG_WriteBuf(param_1,4,0x59dac8);
    MSG_WriteBuf(param_1,0x10,&DAT_00524320);
  }
  MSG_WriteByte(param_1,0x36);
  MSG_WriteString(param_1,&com_clientfallback);
  MSG_WriteByte(param_1,allow_cheats);
  SV_WriteDeltaDescriptionsToClient(param_1);
  SV_SetMoveVars();
  SV_WriteMovevarsToClient(param_1);
  MSG_WriteByte(param_1,0x20);
  MSG_WriteByte(param_1,DAT_0036b2ac);
  MSG_WriteByte(param_1,DAT_0036b2ac);
  MSG_WriteByte(param_1,5);
  uVar1 = NUM_FOR_EDICT(*(undefined4 *)(param_2 + 0x4a84));
  MSG_WriteShort(param_1,uVar1);
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 0xc) = 1;
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}


// SV_SendUserReg  @ 0009eaa8
void SV_SendUserReg(undefined4 param_1)

{
  undefined4 *local_8;
  
  if (sv_gpNewUserMsgs != (undefined4 *)0x0) {
    for (local_8 = sv_gpNewUserMsgs; local_8 != (undefined4 *)0x0;
        local_8 = (undefined4 *)local_8[6]) {
      MSG_WriteByte(param_1,0x27);
      MSG_WriteByte(param_1,*local_8);
      MSG_WriteByte(param_1,local_8[1]);
      MSG_WriteLong(param_1,local_8[2]);
      MSG_WriteLong(param_1,local_8[3]);
      MSG_WriteLong(param_1,local_8[4]);
      MSG_WriteLong(param_1,local_8[5]);
    }
  }
  return;
}


// SV_ServerLog_f  @ 0009b21c
void SV_ServerLog_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    puVar3 = &DAT_000e864b;
    uVar2 = Cmd_Argv(1);
    iVar1 = Q_stricmp(uVar2,puVar3);
    if (iVar1 == 0) {
      if (DAT_00524298 != 0) {
        if (DAT_005242b4 != 0) {
          Log_Close();
        }
        Con_Printf("Server logging disabled.\n");
        DAT_00524298 = 0;
      }
    }
    else {
      puVar3 = &DAT_000e8669;
      uVar2 = Cmd_Argv(1);
      iVar1 = Q_stricmp(uVar2,puVar3);
      if (iVar1 == 0) {
        DAT_00524298 = 1;
        Log_Open();
      }
      else {
        uVar2 = Cmd_Argv(1);
        Con_Printf("log:  unknown parameter %s, \'on\' and \'off\' are valid\n",uVar2);
      }
    }
  }
  else {
    Con_Printf("usage:  log < on | off >\n");
    if (DAT_00524298 == 0) {
      Con_Printf("not currently logging\n");
    }
    else {
      Con_Printf("currently logging\n");
    }
  }
  return;
}


// SV_ServerNotSecure  @ 0009370c
void SV_ServerNotSecure(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 local_54;
  undefined4 local_3c [14];
  
  pcVar2 = "Error downloading Security Module from Speakeasy.net\n";
  puVar3 = local_3c;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  pcVar2 = "Server is not Secure.\n";
  puVar3 = &local_54;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  Con_Printf(local_3c);
  Con_Printf(&local_54);
  return;
}


// SV_ServerSecure  @ 000936a0
void SV_ServerSecure(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 local_5c;
  undefined4 local_40 [15];
  
  pcVar2 = "Completed downloading Security Module from Speakeasy.net\n";
  puVar3 = local_40;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  pcVar2 = "Server is in Secure Mode.\n";
  puVar3 = &local_5c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  Con_Printf(local_40);
  Con_Printf(&local_5c);
  return;
}


// SV_ServerShutdown  @ 000a93f8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ServerShutdown(void)

{
  gGlobalVariables = (float)DAT_0036bc6c;
  if ((svs != 0) && (sv != 0)) {
    (*_DAT_0036af98)();
  }
  return;
}


// SV_Serverinfo_f  @ 0009bb60
void SV_Serverinfo_f(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  longdouble lVar5;
  undefined4 uVar6;
  
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
        uVar6 = 0x200;
        uVar2 = Cmd_Argv(2);
        uVar4 = Cmd_Argv(1);
        uVar2 = Info_Serverinfo(uVar4,uVar2,uVar6);
        Info_SetValueForKey(uVar2);
        uVar2 = Cmd_Argv(1);
        iVar1 = Cvar_FindVar(uVar2);
        if (iVar1 != 0) {
          Z_Free(*(undefined4 *)(iVar1 + 4));
          uVar2 = Cmd_Argv(2);
          uVar2 = CopyString(uVar2);
          *(undefined4 *)(iVar1 + 4) = uVar2;
          lVar5 = (longdouble)Q_atof(*(undefined4 *)(iVar1 + 4));
          *(float *)(iVar1 + 0xc) = (float)lVar5;
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


// SV_SetCallback  @ 000a5658
void SV_SetCallback(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  DAT_00524264 = param_1;
  DAT_00524268 = param_2;
  DAT_0052426c = param_3;
  g_svdeltacallback = param_4;
  DAT_00524270 = 0;
  DAT_00524274 = 0;
  DAT_00524278 = param_5;
  DAT_0052427c = param_6;
  return;
}


// SV_SetGlobalTrace  @ 00087af4
void SV_SetGlobalTrace(uint *param_1)

{
  DAT_0036b26c = (float)*param_1;
  DAT_0036b270 = (float)param_1[1];
  DAT_0036b274 = param_1[4];
  DAT_0036b29c = (float)param_1[3];
  DAT_0036b298 = (float)param_1[2];
  DAT_0036b278 = param_1[5];
  DAT_0036b27c = param_1[6];
  DAT_0036b280 = param_1[7];
  DAT_0036b284 = param_1[8];
  DAT_0036b288 = param_1[9];
  DAT_0036b28c = param_1[10];
  DAT_0036b290 = param_1[0xb];
  if (param_1[0xc] == 0) {
    DAT_0036b294 = DAT_003a78b8;
  }
  else {
    DAT_0036b294 = param_1[0xc];
  }
  DAT_0036b2a0 = param_1[0xd];
  return;
}


// SV_SetLogAddress_f  @ 0009a94c
void SV_SetLogAddress_f(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_164 [2];
  undefined4 local_124 [5];
  char local_110 [260];
  int local_c;
  char *local_8;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    local_8 = (char *)Cmd_Argv();
    Cmd_Argv();
    local_c = Q_atoi();
    if (local_c == 0) {
      Con_Printf();
    }
    else if ((local_8 == (char *)0x0) || (*local_8 == '\0')) {
      Con_Printf();
    }
    else {
      auStackY_164[1] = 0x9aa75;
      snprintf(local_110,0x104,"%s:%i");
      iVar1 = NET_StringToAdr();
      if (iVar1 == 0) {
        Con_Printf();
      }
      else {
        DAT_0052429c = 1;
        puVar2 = local_124;
        puVar3 = &DAT_005242a0;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        puVar2 = local_124;
        puVar3 = auStackY_164;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        NET_AdrToString();
        Con_Printf();
      }
    }
  }
  else {
    Con_Printf();
    if (DAT_00524298 != 0) {
      puVar2 = &DAT_005242a0;
      puVar3 = auStackY_164;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      NET_AdrToString();
      Con_Printf();
    }
  }
  return;
}


// SV_SetMaxclients  @ 000aca40
void SV_SetMaxclients(void)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_0052428c; local_8 = local_8 + 1) {
    SV_ClearFrames(local_c + 0x3480);
    local_c = local_c + 0x4eec;
  }
  DAT_00524288 = 1;
  iVar2 = COM_CheckParm("-maxplayers");
  if (iVar2 == 0) {
    if (isDedicated != 0) {
      DAT_00524288 = 6;
    }
  }
  else {
    DAT_00524288 = Q_atoi(*(undefined4 *)(iVar2 * 4 + com_argv + 4));
  }
  cls = (uint)(isDedicated == 0);
  if (DAT_00524288 < 1) {
    DAT_00524288 = 6;
  }
  else if (0x20 < DAT_00524288) {
    DAT_00524288 = 0x20;
  }
  if ((isDedicated == 0) && (DAT_00300870 < 0x1000001)) {
    DAT_0052428c = 4;
  }
  else {
    DAT_0052428c = 0x20;
  }
  if (DAT_00524288 == 1) {
    SV_UPDATE_BACKUP = 8;
  }
  else {
    SV_UPDATE_BACKUP = 0x40;
  }
  SV_UPDATE_MASK = SV_UPDATE_BACKUP + -1;
  local_c = Hunk_AllocName(DAT_0052428c * 0x4eec,"clients");
  DAT_00524284 = local_c;
  for (local_8 = 0; local_8 < DAT_0052428c; local_8 = local_8 + 1) {
    Q_memset(local_c,0,0x4eec);
    *(int *)(local_c + 0x4d24) = local_c + 0x4ca0;
    *(int *)(local_c + 0x4d20) = local_c + 0x4ca0;
    *(int *)(local_c + 0x4c9c) = local_c + 0x4c18;
    *(int *)(local_c + 0x4c98) = local_c + 0x4c18;
    local_c = local_c + 0x4eec;
  }
  if (DAT_00524288 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f800000;
  }
  Cvar_SetValue("deathmatch",uVar1);
  SV_AllocClientFrames();
  if (DAT_0052428c < DAT_00524288) {
    DAT_00524288 = DAT_0052428c;
  }
  return;
}


// SV_SetMoveVars  @ 0009d358
void SV_SetMoveVars(void)

{
  undefined4 local_10;
  
  movevars = sv_gravity._12_4_;
  DAT_00362b24 = sv_stopspeed._12_4_;
  DAT_00362b28 = sv_maxspeed._12_4_;
  DAT_00362b2c = sv_spectatormaxspeed._12_4_;
  DAT_00362b30 = sv_accelerate._12_4_;
  DAT_00362b34 = sv_airaccelerate._12_4_;
  DAT_00362b38 = sv_wateraccelerate._12_4_;
  DAT_00362b3c = sv_friction._12_4_;
  DAT_00362b40 = sv_edgefriction._12_4_;
  DAT_00362b44 = sv_waterfriction._12_4_;
  DAT_00362b48 = 0x3f800000;
  DAT_00362b4c = sv_bounce._12_4_;
  DAT_00362b50 = sv_stepsize._12_4_;
  DAT_00362b54 = sv_maxvelocity._12_4_;
  DAT_00362b58 = sv_zmax._12_4_;
  DAT_00362b5c = sv_wateramp._12_4_;
  local_10 = (undefined4)(longlong)ROUND((float)sv_footsteps._12_4_);
  DAT_00362b60 = local_10;
  DAT_00362b84 = sv_rollangle._12_4_;
  DAT_00362b88 = sv_rollspeed._12_4_;
  DAT_00362b8c = sv_skycolor_r._12_4_;
  DAT_00362b90 = sv_skycolor_g._12_4_;
  DAT_00362b94 = sv_skycolor_b._12_4_;
  DAT_00362b98 = sv_skyvec_x._12_4_;
  DAT_00362b9c = sv_skyvec_y._12_4_;
  DAT_00362ba0 = sv_skyvec_z._12_4_;
  Q_strncpy(&DAT_00362b64,sv_skyname._4_4_,0x1f);
  DAT_00362b83 = 0;
  return;
}


// SV_SetNewInfo  @ 000a56d0
void SV_SetNewInfo(undefined4 param_1)

{
  DAT_00524270 = 1;
  DAT_00524274 = param_1;
  return;
}


// SV_SetPlayer  @ 000bb6a8
undefined4 SV_SetPlayer(int param_1)

{
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = DAT_00524284;
  while( true ) {
    if (0x1f < local_c) {
      Con_Printf("Userid %i is not on the server\n",param_1);
      return 0;
    }
    if ((((local_8[1] != 0) && (*local_8 != 0)) && (local_8[3] != 0)) &&
       (local_8[0x12a3] == param_1)) break;
    local_c = local_c + 1;
    local_8 = local_8 + 0x13bb;
  }
  host_client = local_8;
  sv_player = local_8[0x12a1];
  return 1;
}


// SV_SetStudioHullPlane  @ 00091818
void SV_SetStudioHullPlane(float *param_1,int param_2,int param_3,float param_4)

{
  *(undefined1 *)(param_1 + 4) = 5;
  *param_1 = *(float *)(bonetransform + param_3 * 4 + param_2 * 0x30);
  param_1[1] = *(float *)(bonetransform + param_3 * 4 + param_2 * 0x30 + 0x10);
  param_1[2] = *(float *)(bonetransform + param_3 * 4 + param_2 * 0x30 + 0x20);
  param_1[3] = *(float *)(bonetransform + param_2 * 0x30 + 0x2c) * param_1[2] +
               *(float *)(bonetransform + param_2 * 0x30 + 0x1c) * param_1[1] +
               *(float *)(bonetransform + param_2 * 0x30 + 0xc) * *param_1 + param_4;
  return;
}


// SV_SetupMove  @ 000b9ca0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_SetupMove(int *param_1)

{
  float fVar1;
  int iVar2;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_50;
  int *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  float local_34;
  double *local_30;
  uint local_2c;
  double *local_28;
  double *local_24;
  float local_20;
  float local_1c;
  float local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_24 = (double *)0x0;
  Q_memset(truepositions,0,0xb00);
  nofind = 1;
  iVar2 = (*_DAT_0036b004)();
  if (((((iVar2 != 0) &&
        ((byte)(0.0 < (float)sv_unlag._12_4_ |
                (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
       (param_1[0x1376] != 0)) && ((param_1[0x1377] != 0 && (1 < DAT_00524288)))) && (*param_1 != 0)
     ) {
    nofind = 0;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      local_14 = (int *)(DAT_00524284 + local_8 * 0x4eec);
      if ((local_14 != param_1) && (*local_14 != 0)) {
        iVar2 = local_8 * 0x58;
        local_4c = (int *)(truepositions + iVar2);
        *(undefined4 *)(truepositions + iVar2 + 0x14) = *(undefined4 *)(local_14[0x12a1] + 0x88);
        *(undefined4 *)(truepositions + iVar2 + 0x18) = *(undefined4 *)(local_14[0x12a1] + 0x8c);
        *(undefined4 *)(truepositions + iVar2 + 0x1c) = *(undefined4 *)(local_14[0x12a1] + 0x90);
        *(undefined4 *)(truepositions + iVar2 + 0x2c) = *(undefined4 *)(local_14[0x12a1] + 0x144);
        *(undefined4 *)(truepositions + iVar2 + 0x30) = *(undefined4 *)(local_14[0x12a1] + 0x148);
        *(undefined4 *)(truepositions + iVar2 + 0x34) = *(undefined4 *)(local_14[0x12a1] + 0x14c);
        *(undefined4 *)(truepositions + iVar2 + 0x38) = *(undefined4 *)(local_14[0x12a1] + 0x150);
        *(undefined4 *)(truepositions + iVar2 + 0x3c) = *(undefined4 *)(local_14[0x12a1] + 0x154);
        *(undefined4 *)(truepositions + iVar2 + 0x40) = *(undefined4 *)(local_14[0x12a1] + 0x158);
        *local_4c = 1;
      }
    }
    fVar1 = (float)param_1[0x923];
    if ((byte)(1.5 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.5) << 0xe) >> 8)) == 1) {
      local_20 = 1.5;
    }
    else {
      local_20 = (float)param_1[0x923];
    }
    fVar1 = local_20;
    if ((byte)(0.0 < (float)sv_maxunlag._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_maxunlag._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_maxunlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      if ((float)sv_maxunlag._12_4_ < 0.0) {
        Cvar_SetValue("sv_maxunlag",0);
      }
      fVar1 = (float)sv_maxunlag._12_4_;
      if ((byte)(local_20 < (float)sv_maxunlag._12_4_ |
                 (byte)((ushort)((ushort)(NAN(local_20) || NAN((float)sv_maxunlag._12_4_)) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(local_20 == (float)sv_maxunlag._12_4_) << 0xe) >> 8)) == 1)
      {
        fVar1 = local_20;
      }
    }
    local_20 = fVar1;
    local_1c = (float)(short)param_1[0x910] / _FUN_000ec3c4;
    if ((byte)(0.1 < local_1c | (byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_1c == 0.1) << 0xe) >> 8)) == 1) {
      local_1c = 0.1;
    }
    if (local_1c < (float)*(double *)(param_1 + 0xd1c)) {
      local_1c = (float)*(double *)(param_1 + 0xd1c);
      local_50 = local_1c;
    }
    local_18 = (float)sv_unlagpush._12_4_ + (((float)realtime - local_20) - local_1c);
    fVar1 = (float)realtime;
    if ((byte)(fVar1 < local_18 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_18)) << 10) >> 8)
              | (byte)((ushort)((ushort)(fVar1 == local_18) << 0xe) >> 8)) == 1) {
      local_18 = (float)realtime;
      local_50 = local_18;
    }
    local_28 = (double *)0x0;
    for (local_8 = 0; local_8 < SV_UPDATE_BACKUP; local_8 = local_8 + 1) {
      local_2c = param_1[0x18] - (local_8 + 1);
      local_24 = (double *)(param_1[0xd20] + (local_2c & SV_UPDATE_MASK) * 0x1810);
      local_30 = local_24 + 0x2fd;
      for (local_c = 0; local_c < *(int *)local_30; local_c = local_c + 1) {
        local_38 = *(int *)((int)local_30 + 0x24) + local_c * 0x154;
        if ((0 < *(int *)(local_38 + 4)) && (*(int *)(local_38 + 4) < DAT_00524288)) {
          iVar2 = *(int *)(local_38 + 4) * 0x58;
          local_4c = (int *)(g_rgValidator + iVar2 + 0x2a8);
          if (*(int *)(g_rgValidator + iVar2 + 0x2ec) == 0) {
            if (*(int *)(local_38 + 0xac) < 1) {
              *(undefined4 *)(g_rgValidator + iVar2 + 0x2ec) = 1;
            }
            if ((*(uint *)(local_38 + 0x3c) & 0x20) != 0) {
              *(undefined4 *)(g_rgValidator + iVar2 + 0x2ec) = 1;
            }
            if (*(int *)(g_rgValidator + iVar2 + 0x2fc) == 0) {
              *(undefined4 *)(g_rgValidator + iVar2 + 0x2fc) = 1;
            }
            else {
              iVar2 = SV_UnlagCheckTeleport(local_38 + 0x10,iVar2 + 0x140c10);
              if (iVar2 != 0) {
                local_4c[0x11] = 1;
              }
            }
            local_4c[0x12] = *(undefined4 *)(local_38 + 0x10);
            local_4c[0x13] = *(undefined4 *)(local_38 + 0x14);
            local_4c[0x14] = *(undefined4 *)(local_38 + 0x18);
          }
        }
      }
      fVar1 = (float)*local_24;
      if ((byte)(fVar1 < local_18 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_18)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_18) << 0xe) >> 8)) == 1) break;
      local_28 = local_24;
    }
    if (local_8 < SV_UPDATE_BACKUP) {
      fVar1 = local_18 - (float)*local_24;
      if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
        Q_memset(truepositions,0,0xb00);
        nofind = 1;
      }
      else {
        local_30 = local_24 + 0x2fd;
        if (local_28 == (double *)0x0) {
          local_28 = local_24;
          local_34 = 0.0;
        }
        else {
          local_64 = (float)((longdouble)*local_28 - (longdouble)*local_24);
          if ((byte)(0.0 < local_64 | (byte)((ushort)((ushort)NAN(local_64) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_64 == 0.0) << 0xe) >> 8)) == 0x40) {
            local_34 = 0.0;
          }
          else {
            local_34 = (local_18 - (float)*local_24) / local_64;
            if ((byte)(1.0 < local_34 | (byte)((ushort)((ushort)NAN(local_34) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_34 == 1.0) << 0xe) >> 8)) == 1) {
              local_34 = 1.0;
            }
            if (local_34 < 0.0) {
              local_34 = 0.0;
            }
          }
        }
        for (local_8 = 0; local_8 < *(int *)local_30; local_8 = local_8 + 1) {
          local_38 = *(int *)((int)local_30 + 0x24) + local_8 * 0x154;
          if ((0 < *(int *)(local_38 + 4)) && (*(int *)(local_38 + 4) < DAT_00524288)) {
            iVar2 = DAT_00524284 + *(int *)(local_38 + 4) * 0x4eec;
            local_14 = (int *)(iVar2 + -0x4eec);
            local_10 = *(int *)(local_38 + 4) + -1;
            if ((local_14 != param_1) &&
               ((*local_14 != 0 &&
                (local_4c = (int *)(truepositions + local_10 * 0x58),
                *(int *)(truepositions + local_10 * 0x58 + 0x44) == 0)))) {
              if (*local_4c == 0) {
                Con_DPrintf("tried to store off position of bogus player %i/%s\n",local_8,
                            iVar2 + -0x300);
              }
              else {
                local_3c = SV_FindEntInPack(*(undefined4 *)(local_38 + 4),local_28 + 0x2fd);
                if (local_3c == 0) {
                  local_48 = *(int *)(local_38 + 0x10);
                  local_44 = *(int *)(local_38 + 0x14);
                  local_40 = *(int *)(local_38 + 0x18);
                }
                else {
                  local_70 = *(float *)(local_3c + 0x10) - *(float *)(local_38 + 0x10);
                  local_6c = *(float *)(local_3c + 0x14) - *(float *)(local_38 + 0x14);
                  local_68 = *(float *)(local_3c + 0x18) - *(float *)(local_38 + 0x18);
                  VectorMA(local_38 + 0x10,local_34,&local_70,&local_48);
                }
                local_4c[2] = local_48;
                local_4c[3] = local_44;
                local_4c[4] = local_40;
                local_4c[8] = local_48;
                local_4c[9] = local_44;
                local_4c[10] = local_40;
                iVar2 = VectorCompare(&local_48,local_14[0x12a1] + 0x88);
                if (iVar2 == 0) {
                  *(int *)(local_14[0x12a1] + 0x88) = local_48;
                  *(int *)(local_14[0x12a1] + 0x8c) = local_44;
                  *(int *)(local_14[0x12a1] + 0x90) = local_40;
                  SV_LinkEdict(local_14[0x12a1],0);
                  local_4c[1] = 1;
                }
              }
            }
          }
        }
      }
    }
    else {
      Q_memset(truepositions,0,0xb00);
      nofind = 1;
    }
  }
  return;
}


// SV_ShouldUpdatePing  @ 000a61f4
ushort SV_ShouldUpdatePing(int param_1)

{
  ushort uVar1;
  
  if (*(int *)(param_1 + 0x243c) == 0) {
    SV_CalcPing(param_1);
    uVar1 = *(ushort *)(param_1 + 0x245e) & 0x8000;
  }
  else if (realtime < *(double *)(param_1 + 0x249c)) {
    uVar1 = 0;
  }
  else {
    *(double *)(param_1 + 0x249c) = realtime + 2.0;
    uVar1 = 1;
  }
  return uVar1;
}


// SV_ShowServerinfo_f  @ 000bb760
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


// SV_Shutdown  @ 000ae0f0
void SV_Shutdown(void)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  SV_ShutdownSteamValidation();
  local_8 = g_sv_delta;
  while (local_8 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_8;
    if (local_8[3] != 0) {
      DELTA_FreeDescription(local_8 + 3);
    }
    Mem_Free(local_8[1]);
    Mem_Free(local_8[2]);
    Mem_Free(local_8);
    local_8 = puVar1;
  }
  g_sv_delta = (undefined4 *)0x0;
  SV_ClearSecurityModule(&DAT_00524318);
  SV_ClearSecurityModule(&DAT_00524348);
  SV_ClearSecurityModule(&DAT_00524300);
  SV_ClearSecurityModule(&DAT_00524330);
  return;
}


// SV_ShutdownSteamValidation  @ 000aeac8
void SV_ShutdownSteamValidation(void)

{
  int iVar1;
  int local_8;
  
  local_8 = g_nValidators;
  while (local_8 = local_8 + -1, -1 < local_8) {
    iVar1 = local_8 * 0xc;
    if ((iVar1 != -0x140920) && (*(int *)(g_rgValidator + iVar1 + 8) != 0)) {
      SteamAbortOngoingUserIDTicketValidation(*(undefined4 *)(g_rgValidator + iVar1 + 8));
      *(undefined4 *)(g_rgValidator + iVar1 + 8) = 0;
    }
  }
  g_nValidators = 0;
  SteamShutdownUserIDTicketValidator();
  return;
}


// SV_SingleClipMoveToEntity  @ 000bf9a0
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
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
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
  
  Q_memset(param_6,0,0x38);
  param_6[4] = 0x3f800000;
  *param_6 = 1;
  param_6[5] = (int)*param_5;
  param_6[6] = (int)param_5[1];
  param_6[7] = (int)param_5[2];
  local_30 = *(int *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4);
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
  if ((*(int *)(param_1 + 0x18c) == 4) &&
     ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd0) == 0.0) << 0xe) >> 8)) != 0x40 ||
       ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd4) == 0.0) << 0xe) >> 8)) != 0x40))
      || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd8)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd8) == 0.0) << 0xe) >> 8)) != 0x40))
     )) {
    local_3c = 1;
  }
  else {
    local_3c = 0;
  }
  if (local_3c != 0) {
    AngleVectors(param_1 + 0xd0,&local_48,&local_54,&local_60);
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
      Q_memset(local_a8,0,0x38);
      local_98 = 1.0;
      local_a8[0] = 1;
      local_94 = *param_5;
      local_90 = param_5[1];
      local_8c = param_5[2];
      SV_RecursiveHullCheck
                (local_38 * 0x28 + local_2c,*(undefined4 *)(local_2c + 8 + local_38 * 0x28),0,
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
      AngleVectorsTranspose(param_1 + 0xd0,&local_6c,&local_c0,&local_cc);
      fVar1 = (float)param_6[8];
      fVar2 = (float)param_6[9];
      fVar3 = (float)param_6[10];
      param_6[8] = (int)(fVar3 * local_64 + fVar2 * local_68 + fVar1 * local_6c);
      param_6[9] = (int)(fVar3 * local_b8 + fVar2 * local_bc + fVar1 * local_c0);
      param_6[10] = (int)(fVar3 * local_c4 + fVar2 * local_c8 + fVar1 * local_cc);
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


// SV_SkipUpdates  @ 000a7104
void SV_SkipUpdates(void)

{
  int *local_c;
  int local_8;
  
  local_c = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if ((((*local_c != 0) || (local_c[3] != 0)) || (local_c[1] != 0)) &&
       (*(int *)(host_client + 0x2438) == 0)) {
      local_c[0xd1f] = 1;
    }
    local_c = local_c + 0x13bb;
  }
  return;
}


// SV_SpawnServer  @ 000a9448
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_SpawnServer(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 auStack_94 [63];
  undefined1 uStack_55;
  char *pcStack_54;
  int local_10;
  int *local_8;
  
  if ((sv != 0) && (1 < DAT_00524288)) {
    local_8 = DAT_00524284;
    for (local_10 = 0; local_10 < DAT_00524288; local_10 = local_10 + 1) {
      if ((((*local_8 != 0) || (local_8[1] != 0)) || (local_8[3] != 0)) &&
         ((local_8[0x12a1] != 0 && (*(int *)local_8[0x12a1] == 0)))) {
        if (*(int *)(local_8[0x12a1] + 0x7c) == 0) {
          Con_Printf("Skipping reconnect on %s, no pvPrivateData\n",local_8 + 0x12fb);
        }
        else {
          (*_DAT_0036af80)(local_8[0x12a1]);
        }
      }
      local_8 = local_8 + 0x13bb;
    }
    FUN_000a9540();
    return;
  }
  Log_Open();
  Log_Printf("Loading map \"%s\"\n",param_2);
  Log_PrintServerVars();
  NET_Config(1 < DAT_00524288);
  pcStack_54 = (char *)Cvar_VariableString("hostname");
  if ((pcStack_54 != (char *)0x0) && (*pcStack_54 == '\0')) {
    Cvar_Set("hostname","Half-Life");
  }
  scr_centertime_off = 0;
  if (param_3 != 0) {
    Con_DPrintf("Spawn Server %s: [%s]\n",param_2,param_3);
    FUN_000a960c();
    return;
  }
  Con_DPrintf("Spawn Server %s\n",param_2);
  gHostSpawnCount = DAT_00524290 + 1;
  DAT_00524290 = gHostSpawnCount;
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
  ContinueLoadingProgressBar("Server",2,0);
  HPAK_CheckSize("custom");
  auStack_94[0] = 0;
  Q_strncpy(auStack_94,&DAT_0036bc88,0x3f);
  uStack_55 = 0;
  Host_ClearMemory(0);
  local_8 = DAT_00524284;
  for (local_10 = 0; local_10 < DAT_0052428c; local_10 = local_10 + 1) {
    SV_ClearFrames(local_8 + 0xd20);
    local_8 = local_8 + 0x13bb;
  }
  FUN_000a9794();
  return;
}


// SV_Spawn_f  @ 0009f074
void SV_Spawn_f(void)

{
  int iVar1;
  char *__nptr;
  undefined4 uVar2;
  char *apcStack_10018 [2];
  undefined1 *puStack_10010;
  undefined4 uStack_1000c;
  undefined4 uStack_10008;
  undefined1 auStack_10004 [65536];
  
  Q_memset(apcStack_10018,0,0x14);
  apcStack_10018[0] = "Spawning";
  puStack_10010 = auStack_10004;
  uStack_10008 = 0;
  uStack_1000c = 0x10000;
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    __nptr = (char *)Cmd_Argv(2);
    iVar1 = atoi(__nptr);
    *(int *)(host_client + 0x4dd4) = iVar1;
    COM_UnMunge2(host_client + 0x4dd4,4,0xffU - DAT_00524290 & 0xff);
    if (cmd_source == 1) {
      Con_Printf("spawn is not valid from the console\n");
    }
    else {
      if (DAT_002fe004 == 0) {
        uVar2 = Cmd_Argv(1);
        iVar1 = Q_atoi(uVar2);
        if (iVar1 != DAT_00524290) {
          SV_New_f();
          return;
        }
      }
      SZ_Write(apcStack_10018,DAT_003aa060,DAT_003aa068);
      SV_WriteSpawn(apcStack_10018);
      Netchan_CreateFragments(1,host_client + 0x1c,apcStack_10018);
      Netchan_FragSend(host_client + 0x1c);
    }
  }
  else {
    Con_Printf("spawn is not valid\n");
  }
  return;
}


// SV_StartParticle  @ 0009c1e0
void SV_StartParticle(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int local_c;
  int local_8;
  
  if (DAT_003a78d8 < 0xf91) {
    MSG_WriteByte(&DAT_003a78c8,0x12);
    MSG_WriteCoord(&DAT_003a78c8,*param_1);
    MSG_WriteCoord(&DAT_003a78c8,param_1[1]);
    MSG_WriteCoord(&DAT_003a78c8,param_1[2]);
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      local_c = (int)ROUND(*(float *)(param_2 + local_8 * 4) * 16.0);
      if (local_c < 0x80) {
        if (local_c < -0x80) {
          local_c = -0x80;
        }
      }
      else {
        local_c = 0x7f;
      }
      MSG_WriteChar(&DAT_003a78c8,local_c);
    }
    MSG_WriteByte(&DAT_003a78c8,param_4);
    MSG_WriteByte(&DAT_003a78c8,param_3);
  }
  return;
}


// SV_StartSound  @ 0009c354
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_StartSound(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,uint param_7,undefined4 param_8)

{
  int iVar1;
  uint local_28;
  float local_18 [3];
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    local_18[local_8] =
         (float)_FUN_000e8c88 *
         (*(float *)(local_8 * 4 + param_2 + 0x15c) + *(float *)(local_8 * 4 + param_2 + 0x168)) +
         *(float *)(local_8 * 4 + param_2 + 0x88);
  }
  iVar1 = SV_BuildSoundMsg(param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_18,
                           &DAT_003a9830);
  if (iVar1 != 0) {
    local_28 = 0;
    if ((param_3 == 6) || ((param_7 & 0x20) != 0)) {
      local_c = 0;
    }
    else {
      local_c = 1;
    }
    if (param_1 == 1) {
      local_28 = 0x80;
    }
    if (local_c == 0) {
      iVar1 = Host_IsSinglePlayerGame();
      if (iVar1 == 0) {
        SV_Multicast(param_2,local_18,local_28 | 1,1);
      }
      else {
        SV_Multicast(param_2,local_18,local_28 | 1,0);
      }
    }
    else {
      SV_Multicast(param_2,local_18,local_28 | 4,0);
    }
  }
  return;
}


// SV_StartSteamValidation  @ 000ae704
undefined4
SV_StartSteamValidation
          (undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  size_t sVar4;
  int local_40;
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  SV_RemoveSteamValidation(param_1);
  if (*param_2 == 1) {
    uVar1 = 1;
  }
  else if (g_nValidators < 0x40) {
    if (param_5 == 3) {
      local_10 = SteamStartValidatingUserIDTicket(param_3,param_4,param_2[1],&local_c);
    }
    else {
      if (param_5 != 4) {
        Con_Printf("SteamStartValidatingUserIDTicket:  Invalid authentication type\n");
        return 0;
      }
      local_14 = 0;
      memset(local_3c,0,0x20);
      iVar2 = GetValveAuthServerCount();
      if ((iVar2 < 1) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
        Con_Printf("SteamStartValidatingUserIDTicket:  No Valve Auth servers defined\n");
        return 0;
      }
      if ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
        return 1;
      }
      iVar2 = GetValveAuthServerCount();
      local_18 = RandomLong(0,iVar2 + -1);
      iVar2 = GetValveAuthServerCount();
      local_1c = RandomLong(0,iVar2 + -1);
      iVar2 = GetValveAuthServerCount();
      if (1 < iVar2) {
        for (local_40 = 0; (local_1c == local_18 && (local_40 < 100)); local_40 = local_40 + 1) {
          iVar2 = GetValveAuthServerCount();
          local_1c = RandomLong(0,iVar2 + -1);
        }
      }
      sVar4 = 0x10;
      pvVar3 = (void *)GetValveAuthServer(local_18);
      memcpy(local_3c,pvVar3,sVar4);
      sVar4 = 0x10;
      pvVar3 = (void *)GetValveAuthServer(local_1c);
      memcpy(local_2c,pvVar3,sVar4);
      local_10 = SteamStartValidatingNewValveCDKey
                           (param_3,param_4,param_2[1],local_3c,local_2c,&local_c);
    }
    if ((local_10 == 0) || (local_10 == 0x17)) {
      iVar2 = g_nValidators * 0xc;
      g_nValidators = g_nValidators + 1;
      *(undefined4 *)(g_rgValidator + iVar2) = DAT_00524290;
      *(undefined4 *)(g_rgValidator + iVar2 + 4) = param_1;
      *(undefined4 *)(g_rgValidator + iVar2 + 8) = local_c;
      uVar1 = 1;
    }
    else {
      Con_Printf("SteamStartValidatingUserIDTicket:  Returned ESteamError %i\n",local_10);
      uVar1 = 0;
    }
  }
  else {
    Sys_Error("SV_StartSteamValidation:  Ran out of steam validator slots\n");
    uVar1 = 0;
  }
  return uVar1;
}


// SV_StepDirection  @ 000afcb0
bool SV_StepDirection(undefined4 param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  double dVar3;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  fVar1 = (param_2 * 3.1415927 + param_2 * 3.1415927) / 360.0;
  dVar3 = cos((double)fVar1);
  local_10 = param_3 * (float)dVar3;
  dVar3 = sin((double)fVar1);
  local_c = param_3 * (float)dVar3;
  local_8 = 0;
  iVar2 = SV_movestep(param_1,&local_10,0);
  if (iVar2 == 0) {
    SV_LinkEdict(param_1,1);
  }
  else {
    SV_LinkEdict(param_1,1);
  }
  return iVar2 != 0;
}


// SV_StringToUserID  @ 000aa47c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * SV_StringToUserID(char *param_1)

{
  size_t sVar1;
  int iVar2;
  char *__nptr;
  undefined4 uVar3;
  size_t sVar4;
  char local_84 [127];
  undefined1 local_5;
  
  Q_memset(&id_386,0,0x14);
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    sVar1 = strlen("STEAM_");
    iVar2 = Q_strnicmp(param_1,"STEAM_",sVar1);
    if (iVar2 != 0) {
      sVar1 = strlen("VALVE_");
      iVar2 = Q_strnicmp(param_1,"VALVE_",sVar1);
      if (iVar2 != 0) {
        id_386 = 0;
        _DAT_0013a3e4 = Q_atoi(param_1);
        return &id_386;
      }
    }
    sVar1 = strlen("STEAM_");
    iVar2 = Q_strnicmp(param_1,"STEAM_",sVar1);
    if (iVar2 == 0) {
      sVar4 = 0x7f;
      sVar1 = strlen("STEAM_");
      strncpy(local_84,param_1 + sVar1,sVar4);
      id_386 = 1;
    }
    else {
      sVar4 = 0x7f;
      sVar1 = strlen("VALVE_");
      strncpy(local_84,param_1 + sVar1,sVar4);
      id_386 = 2;
    }
    local_5 = 0;
    Cmd_TokenizeString(local_84);
    __nptr = (char *)Cmd_Argv(0);
    iVar2 = atoi(__nptr);
    _DAT_0013a3e4 = CONCAT22(DAT_0013a3e4_2,(short)iVar2);
    uVar3 = Cmd_Argv(2);
    DAT_0013a3e8 = Q_strtoull(uVar3);
    DAT_0013a3ec = DAT_0013a3e8 >> 0x1f;
  }
  return &id_386;
}


// SV_StudioSetupBones  @ 00091098
void SV_StudioSetupBones(undefined4 param_1,float param_2,int param_3,undefined4 param_4,
                        undefined4 *param_5,undefined4 param_6,byte *param_7,int param_8)

{
  int iVar1;
  int local_274;
  int local_270 [128];
  undefined1 local_70 [12];
  undefined4 local_64;
  undefined4 local_54;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined1 local_34 [32];
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  
  local_274 = 0;
  if ((param_3 < 0) || (*(int *)(pstudiohdr + 0xa4) <= param_3)) {
    Con_DPrintf("SV_StudioSetupBones:  sequence %i/%i out of range for model %s\n",param_3,
                *(undefined4 *)(pstudiohdr + 0xa4),pstudiohdr + 8);
    param_3 = 0;
  }
  local_3c = param_3 * 0xb0 + *(int *)(pstudiohdr + 0xa8) + pstudiohdr;
  local_38 = *(int *)(pstudiohdr + 0x90) + pstudiohdr;
  local_40 = R_GetAnim(param_1,local_3c);
  if ((param_8 < -1) || (*(int *)(pstudiohdr + 0x8c) <= param_8)) {
    param_8 = 0;
  }
  if (param_8 == -1) {
    local_274 = *(int *)(pstudiohdr + 0x8c);
    for (local_8 = 0; local_8 < *(int *)(pstudiohdr + 0x8c); local_8 = local_8 + 1) {
      local_270[(local_274 - local_8) + -1] = local_8;
    }
  }
  else {
    for (local_8 = param_8; local_8 != -1; local_8 = *(int *)(local_38 + 0x20 + local_8 * 0x70)) {
      local_270[local_274] = local_8;
      local_274 = local_274 + 1;
    }
  }
  if (*(int *)(local_3c + 0x38) < 2) {
    local_10 = 0.0;
  }
  else {
    local_10 = ((float)(*(int *)(local_3c + 0x38) + -1) * param_2) / 256.0;
  }
  local_14 = local_10 - (float)(int)ROUND(local_10);
  R_StudioCalcBoneAdj(0,local_34,param_6,param_6,0);
  for (local_c = local_274 + -1; -1 < local_c; local_c = local_c + -1) {
    local_8 = local_270[local_c];
    R_StudioCalcBoneQuaterion
              ((int)ROUND(local_10),local_14,local_8 * 0x70 + local_38,local_8 * 0xc + local_40,
               local_34,q_37 + local_8 * 0x10);
    R_StudioCalcBonePosition
              ((int)ROUND(local_10),local_14,local_8 * 0x70 + local_38,local_8 * 0xc + local_40,
               local_34,pos_36 + local_8 * 0xc);
  }
  if (1 < *(int *)(local_3c + 0x78)) {
    local_3c = param_3 * 0xb0 + *(int *)(pstudiohdr + 0xa8) + pstudiohdr;
    iVar1 = R_GetAnim(param_1,local_3c);
    local_40 = iVar1 + *(int *)(pstudiohdr + 0x8c) * 0xc;
    for (local_c = local_274 + -1; -1 < local_c; local_c = local_c + -1) {
      local_8 = local_270[local_c];
      R_StudioCalcBoneQuaterion
                ((int)ROUND(local_10),local_14,local_8 * 0x70 + local_38,local_8 * 0xc + local_40,
                 local_34,q2_39 + local_8 * 0x10);
      R_StudioCalcBonePosition
                ((int)ROUND(local_10),local_14,local_8 * 0x70 + local_38,local_8 * 0xc + local_40,
                 local_34,pos2_38 + local_8 * 0xc);
    }
    R_StudioSlerpBones(q_37,pos_36,q2_39,pos2_38,(float)*param_7 / 255.0);
  }
  AngleMatrix(param_4,rotationmatrix);
  rotationmatrix._12_4_ = *param_5;
  rotationmatrix._28_4_ = param_5[1];
  rotationmatrix._44_4_ = param_5[2];
  for (local_c = local_274 + -1; -1 < local_c; local_c = local_c + -1) {
    local_8 = local_270[local_c];
    QuaternionMatrix(q_37 + local_8 * 0x10,local_70);
    local_64 = *(undefined4 *)(pos_36 + local_8 * 0xc);
    local_54 = *(undefined4 *)(pos_36 + local_8 * 0xc + 4);
    local_44 = *(undefined4 *)(pos_36 + local_8 * 0xc + 8);
    if (*(int *)(local_38 + 0x20 + local_8 * 0x70) == -1) {
      R_ConcatTransforms(rotationmatrix,local_70,bonetransform + local_8 * 0x30);
    }
    else {
      R_ConcatTransforms(bonetransform + *(int *)(local_38 + 0x20 + local_8 * 0x70) * 0x30,local_70,
                         bonetransform + local_8 * 0x30);
    }
  }
  return;
}


// SV_Submerged  @ 000b3504
longdouble SV_Submerged(int param_1)

{
  int iVar1;
  longdouble lVar2;
  float local_38;
  float local_34;
  undefined4 local_30;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_1c = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
  local_18 = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
  local_14 = (*(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x158)) * 0.5;
  local_10 = *(float *)(param_1 + 0x14c) - local_14;
  iVar1 = *(int *)(param_1 + 0x240);
  if (iVar1 == 2) {
LAB_000b363c:
    local_8 = 0.0;
    local_c = *(float *)(param_1 + 0x158) - local_14;
    lVar2 = (longdouble)SV_RecursiveWaterLevel(&local_1c,local_c,0,0);
    lVar2 = lVar2 - (longdouble)local_10;
  }
  else {
    if (iVar1 < 3) {
      if (iVar1 == 1) {
        local_c = 0.0;
        local_8 = local_10;
        lVar2 = (longdouble)SV_RecursiveWaterLevel(&local_1c,0,local_10,0);
        return lVar2 - (longdouble)local_10;
      }
    }
    else if (iVar1 == 3) {
      local_30 = *(undefined4 *)(param_1 + 0x158);
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      local_38 = local_1c;
      local_34 = local_18;
      iVar1 = SV_PointContents(&local_38);
      if (iVar1 == -3) {
        return (longdouble)*(float *)(param_1 + 0x170) - (longdouble)*(float *)(param_1 + 0x164);
      }
      goto LAB_000b363c;
    }
    lVar2 = (longdouble)0;
  }
  return lVar2;
}


// SV_TestEntityPosition  @ 000bf2f4
undefined4 SV_TestEntityPosition(int param_1)

{
  undefined1 local_3c [4];
  int local_38;
  undefined4 local_c;
  
  SV_Move(local_3c,param_1 + 0x88,param_1 + 0x15c,param_1 + 0x168,param_1 + 0x88,0,param_1,
          (*(uint *)(param_1 + 0x224) & 0x800000) != 0);
  if (local_38 == 0) {
    local_c = 0;
  }
  else {
    SV_SetGlobalTrace(local_3c);
  }
  return local_c;
}


// SV_TouchLinks  @ 000be640
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
        if ((float)param_2[1] < (float)param_1[*param_2 + 0x54]) {
          SV_TouchLinks(param_1,param_2[2]);
        }
        fVar1 = (float)param_1[*param_2 + 0x51];
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
    if (local_10 == param_1) goto LAB_000be89a;
    if ((local_8[0xae] == 0) || (param_1[0xb0] == 0)) {
LAB_000be6fc:
      if ((((local_8[0x61] == 1) && ((float)param_1[0x51] <= (float)local_8[0x52])) &&
          ((float)param_1[0x52] <= (float)local_8[0x53])) &&
         ((float)param_1[0x53] <= (float)local_8[0x54])) {
        fVar1 = (float)param_1[0x54];
        fVar2 = (float)local_8[0x4f];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          fVar1 = (float)param_1[0x55];
          fVar2 = (float)local_8[0x50];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            fVar1 = (float)param_1[0x56];
            fVar2 = (float)local_8[0x51];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
              local_14 = *(int *)(&DAT_0039c5a8 + local_8[0x4b] * 4);
              if ((local_14 != 0) && (*(int *)(local_14 + 0x44) == 0)) {
                local_1c = SV_HullForBsp(local_10,param_1 + 0x57,param_1 + 0x5a,&local_28);
                local_34 = (float)param_1[0x22] - local_28;
                local_30 = (float)param_1[0x23] - local_24;
                local_2c = (float)param_1[0x24] - local_20;
                local_18 = SV_HullPointContents(local_1c,*(undefined4 *)(local_1c + 8),&local_34);
                if (local_18 != -2) goto LAB_000be89a;
              }
              gGlobalVariables = (float)DAT_0036bc6c;
              (*DAT_0036af50)(local_10,param_1);
            }
          }
        }
      }
    }
    else if (g_groupop == 0) {
      if ((local_8[0xae] & param_1[0xb0]) != 0) goto LAB_000be6fc;
    }
    else if ((g_groupop != 1) || ((local_8[0xae] & param_1[0xb0]) == 0)) goto LAB_000be6fc;
LAB_000be89a:
    local_8 = local_c;
  } while( true );
}


// SV_Trace_Toss  @ 000b5320
undefined4 * SV_Trace_Toss(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int aiStackY_3c0 [5];
  int iStack_3a0;
  float local_37c;
  float local_378;
  float local_374;
  float local_370;
  float local_36c;
  float local_368;
  undefined4 local_364 [5];
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  int local_334;
  undefined1 *local_32c;
  undefined1 local_328 [804];
  
  uVar1 = host_frametime;
  host_frametime = 0.05;
  Q_memcpy(local_328,param_2,0x324);
  local_32c = local_328;
  puVar3 = &stack0xfffffc64;
  do {
    do {
      *(undefined1 **)(puVar3 + -0x10) = local_32c;
      *(undefined4 *)(puVar3 + -0x14) = 0xb5393;
      SV_CheckVelocity();
      *(undefined1 **)(puVar3 + -0x10) = local_32c;
      *(undefined4 *)(puVar3 + -0x14) = 0xb53a5;
      SV_AddGravity();
      *(undefined1 **)(puVar3 + -4) = local_32c + 0xd0;
      *(undefined1 **)(puVar3 + -8) = local_32c + 0xdc;
      *(float *)(puVar3 + -0xc) = (float)host_frametime;
      *(undefined1 **)(puVar3 + -0x10) = local_32c + 0xd0;
      *(undefined4 *)(puVar3 + -0x14) = 0xb53eb;
      VectorMA();
      *(float **)(puVar3 + -8) = &local_370;
      *(float *)(puVar3 + -0xc) = (float)host_frametime;
      *(undefined1 **)(puVar3 + -0x10) = local_32c + 0xa0;
      *(undefined4 *)(puVar3 + -0x14) = 0xb5423;
      VectorScale();
      local_37c = *(float *)(local_32c + 0x88) + local_370;
      local_378 = *(float *)(local_32c + 0x8c) + local_36c;
      local_374 = *(float *)(local_32c + 0x90) + local_368;
      *(undefined4 *)(puVar3 + -4) = 0;
      *(undefined1 **)(puVar3 + -8) = local_32c;
      *(undefined4 *)(puVar3 + -0xc) = 0;
      *(float **)(puVar3 + -0x10) = &local_37c;
      *(undefined1 **)(puVar3 + -0x14) = local_32c + 0x168;
      *(undefined1 **)(puVar3 + -0x18) = local_32c + 0x15c;
      *(undefined1 **)(puVar3 + -0x1c) = local_32c + 0x88;
      *(undefined4 **)(puVar3 + -0x20) = local_364;
      *(undefined4 *)(puVar3 + -0x24) = 0xb54b3;
      SV_Move();
      puVar4 = puVar3 + -4;
      *(undefined4 *)(local_32c + 0x88) = local_350;
      *(undefined4 *)(local_32c + 0x8c) = local_34c;
      *(undefined4 *)(local_32c + 0x90) = local_348;
      puVar3 = puVar3 + -4;
    } while (local_334 == 0);
    puVar3 = puVar4;
  } while (local_334 == param_3);
  puVar5 = local_364;
  puVar6 = param_1;
  host_frametime = (double)uVar1;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return param_1;
}


// SV_TransferConsistencyInfo  @ 000b6afc
int SV_TransferConsistencyInfo(void)

{
  int iVar1;
  undefined1 local_130 [12];
  undefined1 local_124 [12];
  int local_118;
  char local_114 [259];
  undefined1 local_11;
  undefined *local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  do {
    if (DAT_003965a0 <= local_c) {
      return local_8;
    }
    local_10 = &DAT_0036bda0 + local_c * 0x88;
    if (((local_10 != (undefined *)0x0) && (((&DAT_0036bdec)[local_c * 0x88] & 0x80) == 0)) &&
       (iVar1 = SV_FileInConsistencyList(local_10,&local_118), iVar1 != 0)) {
      local_10[0x4c] = local_10[0x4c] | 0x80;
      if (*(int *)(local_10 + 0x40) == 0) {
        snprintf(local_114,0x104,"sound/%s",local_10);
      }
      else {
        Q_strncpy(local_114,local_10,0x103);
        local_11 = 0;
      }
      MD5_Hash_File(local_10 + 0x4d,local_114,0,0,0);
      if (*(int *)(local_10 + 0x40) == 2) {
        iVar1 = *(int *)(local_118 + 0x10);
        if (iVar1 == 1) {
          iVar1 = R_GetStudioBounds(local_114,local_124,local_130);
          if (iVar1 == 0) {
            Host_Error("Server unable to get bounds for %s\n",local_114);
            return 0;
          }
          Q_memcpy(local_10 + 0x5f,local_124,0xc);
          Q_memcpy(local_10 + 0x6b,local_130,0xc);
          local_10[0x5e] = *(undefined1 *)(local_118 + 0x10);
          COM_Munge(local_10 + 0x5e,0x20,DAT_00524290);
        }
        else if ((0 < iVar1) && (iVar1 < 4)) {
          Q_memcpy(local_10 + 0x5f,local_118 + 0x14,0xc);
          Q_memcpy(local_10 + 0x6b,local_118 + 0x20,0xc);
          local_10[0x5e] = *(undefined1 *)(local_118 + 0x10);
          COM_Munge(local_10 + 0x5e,0x20,DAT_00524290);
        }
      }
      local_8 = local_8 + 1;
    }
    local_c = local_c + 1;
  } while( true );
}


// SV_UnlagCheckTeleport  @ 000b9954
undefined4 SV_UnlagCheckTeleport(int param_1,int param_2)

{
  float fVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return 0;
    }
    fVar1 = ABS(*(float *)(param_1 + local_8 * 4) - *(float *)(param_2 + local_8 * 4));
    if ((byte)(128.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 128.0) << 0xe) >> 8)) == 1) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


// SV_UnlinkEdict  @ 000be5f0
void SV_UnlinkEdict(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    RemoveLink(param_1 + 8);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


// SV_UpdateToReliableMessages  @ 000a6cd8
void SV_UpdateToReliableMessages(void)

{
  int local_20;
  int *local_10;
  int local_c;
  int local_8;
  
  host_client = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (host_client[0x12a1] != 0) {
      if ((host_client[0x12e9] != 0) && ((float)host_client[0x12ea] <= (float)realtime)) {
        host_client[0x12e9] = 0;
        host_client[0x12ea] = (int)((float)realtime + 1.0);
        SV_ExtractFromUserinfo(host_client);
        SV_FullClientUpdate(host_client,&DAT_003a887c);
      }
      if ((host_client[0x90e] == 0) &&
         (((*host_client != 0 || (host_client[3] != 0)) && (sv_gpNewUserMsgs != 0)))) {
        SV_SendUserReg(host_client + 0x1d);
      }
    }
    host_client = host_client + 0x13bb;
  }
  if (sv_gpNewUserMsgs != 0) {
    if (sv_gpUserMsgs == 0) {
      sv_gpUserMsgs = sv_gpNewUserMsgs;
    }
    else {
      for (local_20 = sv_gpUserMsgs; *(int *)(local_20 + 0x18) != 0;
          local_20 = *(int *)(local_20 + 0x18)) {
      }
      *(int *)(local_20 + 0x18) = sv_gpNewUserMsgs;
    }
    sv_gpNewUserMsgs = 0;
  }
  if ((DAT_003a78cc & 2) != 0) {
    Con_DPrintf("sv.datagram overflowed!\n");
    SZ_Clear(&DAT_003a78c8);
  }
  if ((DAT_003a9c48 & 2) != 0) {
    Con_DPrintf("sv.spectator overflowed!\n");
    SZ_Clear(&DAT_003a9c44);
  }
  local_10 = DAT_00524284;
  for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
    if ((local_10[0x90e] == 0) && (*local_10 != 0)) {
      if (local_10[0x21] + DAT_003a888c < local_10[0x20]) {
        SZ_Write(local_10 + 0x1d,DAT_003a8884,DAT_003a888c);
      }
      else {
        Netchan_CreateFragments(1,local_10 + 7,&DAT_003a887c);
      }
      if (local_10[0x92f] + DAT_003a78d8 < local_10[0x92e]) {
        SZ_Write(local_10 + 0x92b,DAT_003a78d0,DAT_003a78d8);
      }
      else {
        Con_DPrintf("Warning:  Ignoring unreliable datagram for %s, would overflow\n",
                    local_10 + 0x12fb);
      }
      if ((local_10[0x90f] != 0) && (local_10[0x92f] + DAT_003a9c54 < local_10[0x92e])) {
        SZ_Write(local_10 + 0x92b,DAT_003a9c4c,DAT_003a9c54);
      }
    }
    local_10 = local_10 + 0x13bb;
  }
  FUN_000a70b4();
  return;
}


// SV_UploadComplete  @ 000b5e48
undefined4 SV_UploadComplete(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4d20) == param_1 + 0x4ca0) {
    SV_RegisterResources();
    SV_PropagateCustomizations();
    if ((byte)(0.0 < (float)sv_allow_upload._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_allow_upload._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_allow_upload._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
    {
      Con_DPrintf("Custom resource propagation complete.\n");
    }
    *(undefined4 *)(param_1 + 0x4d2c) = 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// SV_User_f  @ 0009bdac
void SV_User_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_10;
  int local_c;
  
  if (sv == 0) {
    Con_Printf("Can\'t \'user\', not running a server\n");
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      uVar2 = Cmd_Argv(1);
      iVar1 = Q_atoi(uVar2);
      local_10 = DAT_00524284;
      for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
        if ((((*local_10 != 0) || (local_10[1] != 0)) || (local_10[3] != 0)) &&
           ((local_10[0x90e] == 0 && ((char)local_10[0x12fb] != '\0')))) {
          if (local_10[0x12a3] == iVar1) {
LAB_0009becc:
            Info_Print(local_10 + 0x12a9);
            return;
          }
          uVar2 = Cmd_Argv(1);
          iVar3 = Q_strcmp(local_10 + 0x12fb,uVar2);
          if (iVar3 == 0) goto LAB_0009becc;
        }
        local_10 = local_10 + 0x13bb;
      }
      Con_Printf("User not in server.\n");
    }
    else {
      Con_Printf("Usage: user <username / userid>\n");
    }
  }
  return;
}


// SV_Users_f  @ 0009bf10
void SV_Users_f(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *local_10;
  int local_c;
  int local_8;
  
  if (sv == 0) {
    Con_Printf("Can\'t \'users\', not running a server\n");
  }
  else {
    local_c = 0;
    Con_Printf("userid : uniqueid : name\n");
    Con_Printf("------ : ---------: ----\n");
    local_10 = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if ((((*local_10 != 0) || (local_10[1] != 0)) || (local_10[3] != 0)) &&
         ((local_10[0x90e] == 0 && ((char)local_10[0x12fb] != '\0')))) {
        piVar2 = local_10 + 0x12fb;
        uVar1 = SV_GetClientIDString(local_10);
        Con_Printf("%6i : %s : %s\n",local_10[0x12a3],uVar1,piVar2);
        local_c = local_c + 1;
      }
      local_10 = local_10 + 0x13bb;
    }
    Con_Printf("%i users\n",local_c);
  }
  return;
}


// SV_ValidClientMulticast  @ 0009cb98
undefined4 SV_ValidClientMulticast(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  uVar1 = param_3 & 0xffffff7f;
  iVar2 = Host_IsSinglePlayerGame();
  if ((iVar2 == 0) && (*(int *)(param_1 + 0x243c) == 0)) {
    if (uVar1 == 2) {
      local_8 = CM_LeafPVS(param_2);
    }
    else if ((int)uVar1 < 3) {
      if (uVar1 != 1) {
LAB_0009cc2c:
        Con_Printf("MULTICAST: Error %d!\n",param_3);
        return 0;
      }
    }
    else {
      if (uVar1 != 4) goto LAB_0009cc2c;
      local_8 = CM_LeafPAS(param_2);
    }
    if ((local_8 != 0) &&
       (iVar2 = SV_PointLeafnum(*(int *)(param_1 + 0x4a84) + 0x88),
       ((int)(uint)*(byte *)((iVar2 + -1 >> 3) + local_8) >> ((byte)(iVar2 + -1) & 7) & 1U) == 0)) {
      return 0;
    }
  }
  return 1;
}


// SV_ValidateClientCommand  @ 000b9684
undefined4 SV_ValidateClientCommand(undefined4 param_1)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_c = 0;
  COM_Parse(param_1);
  local_8 = clcommands._0_4_;
  while( true ) {
    if (local_8 == 0) {
      return 0;
    }
    iVar1 = Q_strcasecmp(&com_token,local_8);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
    local_8 = *(int *)(clcommands + local_c * 4);
  }
  return 1;
}


// SV_WriteClientdataToMessage  @ 0009e0a0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_WriteClientdataToMessage(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_25c [88];
  undefined8 *local_204;
  undefined1 *local_200;
  undefined4 local_1fc;
  undefined1 local_1f8 [476];
  int local_1c;
  undefined1 *local_18;
  undefined8 *local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_1fc = 0;
  Q_memset(local_1f8,0,0x1dc);
  local_10 = *(int *)(param_1 + 0x4a84);
  local_8 = 0;
  local_14 = (undefined8 *)
             (*(int *)(param_1 + 0x3480) + (*(uint *)(param_1 + 0x60) & SV_UPDATE_MASK) * 0x1810);
  *local_14 = realtime;
  *(undefined4 *)(local_14 + 1) = 0xbf800000;
  if (*(int *)(param_1 + 0x2430) != 0) {
    MSG_WriteByte(param_2,0x2a);
    *(undefined4 *)(param_1 + 0x2430) = 0;
  }
  if (*(int *)(local_10 + 0x120) != 0) {
    if (*(int *)(local_10 + 0x120) == 2) {
      MSG_WriteByte(param_2,0x26);
      MSG_WriteHiresAngle(param_2,*(undefined4 *)(local_10 + 0xe0));
      *(undefined4 *)(local_10 + 0xe0) = 0;
    }
    else {
      MSG_WriteByte(param_2,10);
      for (local_c = 0; local_c < 3; local_c = local_c + 1) {
        MSG_WriteHiresAngle(param_2,*(undefined4 *)(local_c * 4 + local_10 + 0xd0));
      }
    }
    *(undefined4 *)(local_10 + 0x120) = 0;
  }
  Q_memset((int)local_14 + 0xc,0,0x1dc);
  (*_DAT_0036afd8)(local_10,*(int *)(host_client + 0x4dd8) != 0,(int)local_14 + 0xc);
  MSG_WriteByte(param_2,0xf);
  if (*(int *)(param_1 + 0x243c) == 0) {
    MSG_StartBitWriting(param_2);
    if (*(int *)(host_client + 0x2434) == -1) {
      local_18 = local_1f8;
    }
    else {
      local_18 = (undefined1 *)
                 (*(int *)(host_client + 0x3480) +
                  (*(uint *)(host_client + 0x2434) & SV_UPDATE_MASK) * 0x1810 + 0xc);
    }
    local_1c = (int)local_14 + 0xc;
    local_1fc = 1;
    if (*(int *)(host_client + 0x2434) == -1) {
      MSG_WriteBits(0,1);
    }
    else {
      MSG_WriteBits(1,1);
      MSG_WriteBits(*(undefined4 *)(host_client + 0x2434),8);
    }
    DELTA_WriteDelta(local_18,local_1c,local_1fc,g_pclientdelta,0);
    if (*(int *)(host_client + 0x4dd8) != 0) {
      Q_memset(local_25c,0,0x58);
      iVar1 = (*_DAT_0036afe8)(*(undefined4 *)(host_client + 0x4a84),local_14 + 0x3d);
      if (iVar1 != 0) {
        for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
          if (*(int *)(host_client + 0x2434) == -1) {
            local_200 = local_25c;
          }
          else {
            local_200 = (undefined1 *)
                        (local_c * 0x58 + 0x1e8 +
                        *(int *)(host_client + 0x3480) +
                        (*(uint *)(host_client + 0x2434) & SV_UPDATE_MASK) * 0x1810);
          }
          local_204 = local_14 + local_c * 0xb + 0x3d;
          iVar1 = DELTA_CheckDelta(local_200,local_204,g_pweapondelta);
          if (iVar1 != 0) {
            MSG_WriteBits(1,1);
            MSG_WriteBits(local_c,5);
            DELTA_WriteDelta(local_200,local_204,1,g_pweapondelta,0);
          }
        }
      }
    }
    MSG_WriteBits(0,1);
    MSG_EndBitWriting(param_2);
  }
  return;
}


// SV_WriteDeltaDescriptionsToClient  @ 0009d23c
void SV_WriteDeltaDescriptionsToClient(undefined4 param_1)

{
  undefined1 local_54 [68];
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  Q_memset(local_54,0,0x44);
  for (local_10 = g_sv_delta; local_10 != (undefined4 *)0x0; local_10 = (undefined4 *)*local_10) {
    MSG_WriteByte(param_1,0xe);
    MSG_WriteString(param_1,local_10[1]);
    local_8 = *(int *)(local_10[3] + 4);
    MSG_StartBitWriting(param_1);
    MSG_WriteBits(local_8,0x10);
    for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
      DELTA_WriteDelta(local_54,*(int *)(local_10[3] + 0x2c) + local_c * 0x44,1,g_MetaDelta,0);
    }
    MSG_EndBitWriting(param_1);
  }
  return;
}


// SV_WriteDeltaHeader  @ 000a5700
void SV_WriteDeltaHeader(int param_1,int param_2,int param_3,int *param_4,int param_5,
                        undefined4 param_6,int param_7,int param_8)

{
  int iVar1;
  
  iVar1 = param_1 - *param_4;
  if (param_7 == 0) {
    MSG_WriteBits(param_2 != 0,1);
    if ((iVar1 < 1) || (0x3f < iVar1)) {
      MSG_WriteBits(1,1);
      MSG_WriteBits(param_1,0xb);
    }
    else {
      MSG_WriteBits(0,1);
      MSG_WriteBits(iVar1,6);
    }
  }
  else if (iVar1 == 1) {
    MSG_WriteBits(1,1);
  }
  else {
    MSG_WriteBits(0,1);
    if ((iVar1 < 1) || (0x3f < iVar1)) {
      MSG_WriteBits(1,1);
      MSG_WriteBits(param_1,0xb);
    }
    else {
      MSG_WriteBits(0,1);
      MSG_WriteBits(iVar1,6);
    }
  }
  *param_4 = param_1;
  if (param_2 == 0) {
    MSG_WriteBits(param_3 != 0,1);
    if (*DAT_003a78c0 != 0) {
      if (param_5 == 0) {
        MSG_WriteBits(0,1);
      }
      else {
        MSG_WriteBits(1,1);
        MSG_WriteBits(param_6,6);
      }
    }
    if ((param_7 != 0) && (param_5 == 0)) {
      if (param_8 == 0) {
        MSG_WriteBits(0,1);
      }
      else {
        MSG_WriteBits(1,1);
        MSG_WriteBits(param_8,6);
      }
    }
  }
  return;
}


// SV_WriteEntitiesToClient  @ 000a66ec
void SV_WriteEntitiesToClient(void)

{
  FUN_000a66fc();
  return;
}


// SV_WriteIP_f  @ 000ac080
void SV_WriteIP_f(void)

{
  float fVar1;
  uint uVar2;
  int local_114;
  char local_10c [260];
  int local_8;
  
  snprintf(local_10c,0x104,"listip.cfg");
  Con_Printf("Writing %s.\n",local_10c);
  local_8 = FS_Open(local_10c,&DAT_000ead71);
  if (local_8 == 0) {
    Con_Printf("Couldn\'t open %s\n",local_10c);
  }
  else {
    for (local_114 = 0; local_114 < numipfilters; local_114 = local_114 + 1) {
      uVar2 = *(uint *)(ipfilters + local_114 * 0x10 + 4);
      fVar1 = *(float *)(ipfilters + local_114 * 0x10 + 0xc);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        FS_FPrintf(local_8,"addip 0.0 %i.%i.%i.%i\n",uVar2 & 0xff,uVar2 >> 8 & 0xff,
                   uVar2 >> 0x10 & 0xff,uVar2 >> 0x18);
      }
    }
    FS_Close(local_8);
  }
  return;
}


// SV_WriteId_f  @ 000ab764
void SV_WriteId_f(void)

{
  float fVar1;
  undefined4 uVar2;
  int local_110;
  char local_10c [260];
  int local_8;
  
  snprintf(local_10c,0x104,"banned.cfg");
  Con_Printf("Writing %s.\n",local_10c);
  local_8 = FS_Open(local_10c,&DAT_000eab14);
  if (local_8 == 0) {
    Con_Printf("Couldn\'t open %s\n",local_10c);
  }
  else {
    for (local_110 = 0; local_110 < numuserfilters; local_110 = local_110 + 1) {
      fVar1 = *(float *)(userfilters + local_110 * 0x1c + 0x18);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        uVar2 = SV_GetIDString(userfilters + local_110 * 0x1c);
        FS_FPrintf(local_8,"banid 0.0 %s\n",uVar2);
      }
    }
    FS_Close(local_8);
  }
  return;
}


// SV_WriteMovevarsToClient  @ 0009cf04
void SV_WriteMovevarsToClient(undefined4 param_1)

{
  MSG_WriteByte(param_1,0x2c);
  MSG_WriteFloat(param_1,movevars);
  MSG_WriteFloat(param_1,DAT_00362b24);
  MSG_WriteFloat(param_1,DAT_00362b28);
  MSG_WriteFloat(param_1,DAT_00362b2c);
  MSG_WriteFloat(param_1,DAT_00362b30);
  MSG_WriteFloat(param_1,DAT_00362b34);
  MSG_WriteFloat(param_1,DAT_00362b38);
  MSG_WriteFloat(param_1,DAT_00362b3c);
  MSG_WriteFloat(param_1,DAT_00362b40);
  MSG_WriteFloat(param_1,DAT_00362b44);
  MSG_WriteFloat(param_1,DAT_00362b48);
  MSG_WriteFloat(param_1,DAT_00362b4c);
  MSG_WriteFloat(param_1,DAT_00362b50);
  MSG_WriteFloat(param_1,DAT_00362b54);
  MSG_WriteFloat(param_1,DAT_00362b58);
  MSG_WriteFloat(param_1,DAT_00362b5c);
  MSG_WriteByte(param_1,DAT_00362b60 != 0);
  MSG_WriteFloat(param_1,DAT_00362b84);
  MSG_WriteFloat(param_1,DAT_00362b88);
  MSG_WriteFloat(param_1,DAT_00362b8c);
  MSG_WriteFloat(param_1,DAT_00362b90);
  MSG_WriteFloat(param_1,DAT_00362b94);
  MSG_WriteFloat(param_1,DAT_00362b98);
  MSG_WriteFloat(param_1,DAT_00362b9c);
  MSG_WriteFloat(param_1,DAT_00362ba0);
  MSG_WriteString(param_1,&DAT_00362b64);
  return;
}


// SV_WriteSpawn  @ 0009e534
void SV_WriteSpawn(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *local_680;
  undefined1 local_67c [36];
  int local_658;
  undefined1 auStack_650 [1352];
  char local_108 [256];
  int local_8;
  
  if (DAT_0036bc68 == 0) {
    DAT_003a78c4 = 1;
    ReleaseEntityDLLFields(sv_player);
    Q_memset(sv_player + 0x80,0,0x2a4);
    InitEntityDLLFields(sv_player);
    uVar2 = NUM_FOR_EDICT(sv_player);
    *(undefined4 *)(sv_player + 0x228) = uVar2;
    *(int *)(sv_player + 0x250) = (int)host_client - (pr_strings + -0x4bec);
    if (host_client[0x90f] != 0) {
      *(uint *)(sv_player + 0x224) = *(uint *)(sv_player + 0x224) | 0x100000;
    }
    gGlobalVariables = (float)DAT_0036bc6c;
    (*DAT_0036af88)(sv_player);
    DAT_003a78c4 = 2;
  }
  else {
    if (host_client[0x90f] != 0) {
      Con_Printf("ERROR! Spectator mode doesn\'t work with saved game.\n");
      return;
    }
    DAT_0036bc64 = 0;
  }
  SZ_Clear(host_client + 0x1d);
  SZ_Clear(host_client + 0x92b);
  MSG_WriteByte(param_1,7);
  MSG_WriteFloat(param_1,(float)DAT_0036bc6c);
  host_client[0x12e9] = 1;
  local_680 = DAT_00524284;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if ((((local_680 == host_client) || (*local_680 != 0)) || (local_680[3] != 0)) ||
       (local_680[1] != 0)) {
      SV_FullClientUpdate(local_680,param_1);
    }
    local_680 = local_680 + 0x13bb;
  }
  for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
    MSG_WriteByte(param_1,0xc);
    MSG_WriteByte(param_1,(int)(char)local_8);
    MSG_WriteString(param_1,*(undefined4 *)(&DAT_003a77b0 + local_8 * 4));
  }
  if (host_client[0x90f] == 0) {
    MSG_WriteByte(param_1,10);
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      MSG_WriteHiresAngle(param_1,*(undefined4 *)(local_8 * 4 + sv_player + 0xf4));
    }
    MSG_WriteHiresAngle(param_1,0);
    SV_WriteClientdataToMessage(host_client,param_1);
    if (DAT_0036bc68 != 0) {
      Q_memset(local_67c,0,0x574);
      DAT_0036b2bc = local_67c;
      (*DAT_0036afac)();
      MSG_WriteByte(param_1,0x21);
      uVar2 = Host_SaveGameDirectory(&DAT_0036bc88);
      snprintf(local_108,0x100,"%s%s.HL2",uVar2);
      COM_FixSlashes(local_108);
      MSG_WriteString(param_1,local_108);
      MSG_WriteByte(param_1,local_658);
      for (local_8 = 0; local_8 < local_658; local_8 = local_8 + 1) {
        MSG_WriteString(param_1,auStack_650 + local_8 * 0x50);
      }
      DAT_0036bc68 = 0;
      DAT_0036b2bc = (undefined1 *)0x0;
    }
  }
  MSG_WriteByte(param_1,0x19);
  MSG_WriteByte(param_1,1);
  *host_client = 1;
  piVar1 = host_client;
  host_client[0x91d] = 0;
  piVar1[0x91e] = 0;
  piVar1 = host_client;
  host_client[0x921] = 0;
  piVar1[0x922] = 0;
  piVar1 = host_client;
  host_client[0x91f] = 0;
  piVar1[0x920] = 0;
  host_client[1] = 1;
  host_client[3] = 1;
  host_client[2] = 0;
  NotifyDedicatedServerUI("UpdatePlayers");
  return;
}


// SV_WriteVoiceCodec  @ 000a879c
void SV_WriteVoiceCodec(undefined4 param_1)

{
  MSG_WriteByte(param_1,0x34);
  if (DAT_00524288 < 2) {
    MSG_WriteString(param_1,&DAT_000e86dc);
  }
  else {
    MSG_WriteString(param_1,sv_voicecodec._4_4_);
  }
  return;
}


// SV_movestep  @ 000af7cc
/* WARNING: Type propagation algorithm not settling */

undefined4 SV_movestep(uint param_1,float *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint *puVar4;
  uint auStack_94 [2];
  uint local_70;
  int local_68;
  int local_64;
  int local_60;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_34;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  auStack_94[1] = 0xaf7db;
  local_70 = (uint)((*(uint *)(param_1 + 0x224) & 0x800000) != 0);
  local_14 = *(undefined4 *)(param_1 + 0x88);
  local_10 = *(undefined4 *)(param_1 + 0x8c);
  local_c = *(undefined4 *)(param_1 + 0x90);
  local_2c = *(float *)(param_1 + 0x88) + *param_2;
  local_28 = *(float *)(param_1 + 0x8c) + param_2[1];
  if ((*(uint *)(param_1 + 0x224) & 3) == 0) {
    local_18 = *(float *)(param_1 + 0x90) + param_2[2] + (float)sv_stepsize._12_4_;
    local_24 = local_18 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
    auStack_94[1] = local_70;
    auStack_94[0] = param_1;
    local_20 = local_2c;
    local_1c = local_28;
    SV_Move(&local_64,&local_20,param_1 + 0x15c,param_1 + 0x168,&local_2c,0);
    puVar4 = auStack_94 + 1;
    if (local_64 == 0) {
      if (local_60 != 0) {
        local_18 = local_18 - (float)sv_stepsize._12_4_;
        auStack_94[0] = local_70;
        SV_Move(&local_64,&local_20,param_1 + 0x15c,param_1 + 0x168,&local_2c,0,param_1);
        puVar4 = auStack_94;
        if ((local_64 != 0) || (local_60 != 0)) {
          return 0;
        }
      }
      if ((byte)((byte)((ushort)((ushort)NAN(local_54) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_54 == 1.0) << 0xe) >> 8)) == 0x40) {
        if ((*(uint *)(param_1 + 0x224) & 0x400) == 0) {
          uVar2 = 0;
        }
        else {
          *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x88) + *param_2;
          *(float *)(param_1 + 0x8c) = *(float *)(param_1 + 0x8c) + param_2[1];
          *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + param_2[2];
          if (param_3 != 0) {
            puVar4[0xfffffffd] = 1;
            puVar4[0xfffffffc] = param_1;
            puVar4[0xfffffffb] = 0xafb93;
            SV_LinkEdict();
          }
          *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xfffffdff;
          uVar2 = 1;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x88) = local_50;
        *(undefined4 *)(param_1 + 0x8c) = local_4c;
        *(undefined4 *)(param_1 + 0x90) = local_48;
        puVar4[0xfffffffc] = param_1;
        puVar4[0xfffffffb] = 0xafbf0;
        iVar1 = SV_CheckBottom();
        if (iVar1 == 0) {
          if ((*(uint *)(param_1 + 0x224) & 0x400) == 0) {
            *(undefined4 *)(param_1 + 0x88) = local_14;
            *(undefined4 *)(param_1 + 0x8c) = local_10;
            *(undefined4 *)(param_1 + 0x90) = local_c;
            uVar2 = 0;
          }
          else {
            if (param_3 != 0) {
              puVar4[0xfffffffd] = 1;
              puVar4[0xfffffffc] = param_1;
              puVar4[0xfffffffb] = 0xafc20;
              SV_LinkEdict();
            }
            uVar2 = 1;
          }
        }
        else {
          if ((*(uint *)(param_1 + 0x224) & 0x400) != 0) {
            *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xfffffbff;
          }
          *(undefined4 *)(param_1 + 0x21c) = local_34;
          if (param_3 != 0) {
            puVar4[0xfffffffd] = 1;
            puVar4[0xfffffffc] = param_1;
            puVar4[0xfffffffb] = 0xafc9c;
            SV_LinkEdict();
          }
          uVar2 = 1;
        }
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    puVar3 = &stack0xffffff74;
    for (local_68 = 0; local_68 < 2; local_68 = local_68 + 1) {
      local_20 = *(float *)(param_1 + 0x88) + *param_2;
      local_1c = *(float *)(param_1 + 0x8c) + param_2[1];
      local_18 = *(float *)(param_1 + 0x90) + param_2[2];
      iVar1 = *(int *)(param_1 + 0x210);
      if ((local_68 == 0) && (iVar1 != 0)) {
        local_8 = *(float *)(param_1 + 0x90) - *(float *)(*(int *)(param_1 + 0x210) + 0x90);
        if ((byte)(40.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_8 == 40.0) << 0xe) >> 8)) == 1) {
          local_18 = local_18 - 8.0;
        }
        if (local_8 < 30.0) {
          local_18 = local_18 + 8.0;
        }
      }
      *(uint *)(puVar3 + -4) = local_70;
      *(uint *)(puVar3 + -8) = param_1;
      *(undefined4 *)(puVar3 + -0xc) = 0;
      *(float **)(puVar3 + -0x10) = &local_20;
      *(uint *)(puVar3 + -0x14) = param_1 + 0x168;
      *(uint *)(puVar3 + -0x18) = param_1 + 0x15c;
      *(uint *)(puVar3 + -0x1c) = param_1 + 0x88;
      *(int **)(puVar3 + -0x20) = &local_64;
      *(undefined4 *)(puVar3 + -0x24) = 0xaf970;
      SV_Move();
      if ((byte)((byte)((ushort)((ushort)NAN(local_54) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_54 == 1.0) << 0xe) >> 8)) == 0x40) {
        g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
        if ((*(uint *)(param_1 + 0x224) & 2) != 0) {
          *(undefined4 **)(puVar3 + -0x14) = &local_50;
          *(undefined4 *)(puVar3 + -0x18) = 0xaf9b8;
          iVar1 = SV_PointContents();
          if (iVar1 == -1) {
            return 0;
          }
        }
        *(undefined4 *)(param_1 + 0x88) = local_50;
        *(undefined4 *)(param_1 + 0x8c) = local_4c;
        *(undefined4 *)(param_1 + 0x90) = local_48;
        if (param_3 != 0) {
          *(undefined4 *)(puVar3 + -0x10) = 1;
          *(uint *)(puVar3 + -0x14) = param_1;
          *(undefined4 *)(puVar3 + -0x18) = 0xafa04;
          SV_LinkEdict();
        }
        return 1;
      }
      if (iVar1 == 0) break;
      puVar3 = puVar3 + -4;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// SV_movetest  @ 000af4dc
/* WARNING: Type propagation algorithm not settling */

undefined4 SV_movetest(int param_1,float *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int aiStack_84 [2];
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
  
  piVar3 = aiStack_84 + 1;
  aiStack_84[1] = 0xaf4e8;
  local_10 = *(undefined4 *)(param_1 + 0x88);
  local_c = *(undefined4 *)(param_1 + 0x8c);
  local_8 = *(undefined4 *)(param_1 + 0x90);
  local_28 = *(float *)(param_1 + 0x88) + *param_2;
  local_24 = *(float *)(param_1 + 0x8c) + param_2[1];
  local_14 = *(float *)(param_1 + 0x90) + param_2[2] + (float)sv_stepsize._12_4_;
  local_20 = local_14 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
  aiStack_84[0] = param_1;
  local_1c = local_28;
  local_18 = local_24;
  SV_MoveNoEnts(&local_60,&local_1c,param_1 + 0x15c,param_1 + 0x168,&local_28,0);
  if (local_60 == 0) {
    if (local_5c != 0) {
      local_14 = local_14 - (float)sv_stepsize._12_4_;
      SV_MoveNoEnts(&local_60,&local_1c,param_1 + 0x15c,param_1 + 0x168,&local_28,0,param_1);
      piVar3 = aiStack_84;
      if ((local_60 != 0) || (local_5c != 0)) {
        return 0;
      }
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) == 0x40) {
      if ((*(uint *)(param_1 + 0x224) & 0x400) == 0) {
        uVar1 = 0;
      }
      else {
        *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x88) + *param_2;
        *(float *)(param_1 + 0x8c) = *(float *)(param_1 + 0x8c) + param_2[1];
        *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + param_2[2];
        if (param_3 != 0) {
          piVar3[0xfffffffd] = 1;
          piVar3[0xfffffffc] = param_1;
          piVar3[0xfffffffb] = 0xaf6af;
          SV_LinkEdict();
        }
        *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xfffffdff;
        uVar1 = 1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x88) = local_4c;
      *(undefined4 *)(param_1 + 0x8c) = local_48;
      *(undefined4 *)(param_1 + 0x90) = local_44;
      piVar3[0xfffffffc] = param_1;
      piVar3[0xfffffffb] = 0xaf70c;
      iVar2 = SV_CheckBottom();
      if (iVar2 == 0) {
        if ((*(uint *)(param_1 + 0x224) & 0x400) == 0) {
          *(undefined4 *)(param_1 + 0x88) = local_10;
          *(undefined4 *)(param_1 + 0x8c) = local_c;
          *(undefined4 *)(param_1 + 0x90) = local_8;
          uVar1 = 0;
        }
        else {
          if (param_3 != 0) {
            piVar3[0xfffffffd] = 1;
            piVar3[0xfffffffc] = param_1;
            piVar3[0xfffffffb] = 0xaf73c;
            SV_LinkEdict();
          }
          uVar1 = 1;
        }
      }
      else {
        if ((*(uint *)(param_1 + 0x224) & 0x400) != 0) {
          *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xfffffbff;
        }
        *(undefined4 *)(param_1 + 0x21c) = local_30;
        if (param_3 != 0) {
          piVar3[0xfffffffd] = 1;
          piVar3[0xfffffffc] = param_1;
          piVar3[0xfffffffb] = 0xaf7b8;
          SV_LinkEdict();
        }
        uVar1 = 1;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


