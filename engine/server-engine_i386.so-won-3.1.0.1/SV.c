// SV_ActivateServer  @ 0007bab8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_ActivateServer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_10014 [4];
  undefined1 *puStack_10010;
  undefined4 uStack_1000c;
  undefined4 uStack_10008;
  undefined1 auStack_10004 [65536];
  
  Q_memset(auStack_10014,0,0x10);
  puStack_10010 = auStack_10004;
  uStack_10008 = 0;
  uStack_1000c = 0x10000;
  Cvar_Set("sv_newunit",&DAT_000aa665);
  (*_DAT_00386274)(DAT_00186f94,DAT_00186f8c,DAT_001ab4e8);
  sv = 1;
  DAT_00186fa0 = 2;
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
  SV_CreateResourceList();
  DAT_00183684 = SV_TransferConsistencyInfo();
  host_client = DAT_001ab4e4;
  if (0 < DAT_001ab4e8) {
    iVar2 = 0;
    do {
      if ((*host_client != 0) || (host_client[3] != 0)) {
        Netchan_Clear(host_client + 8);
        if (DAT_001ab4e8 < 2) {
          SV_SendServerinfo(auStack_10014,host_client);
          SV_SendResources(auStack_10014);
        }
        else {
          SV_BuildReconnect(host_client + 0x1d);
          Netchan_Transmit(host_client + 8,0,0);
        }
        uVar1 = sv_gpNewUserMsgs;
        if ((sv_gpUserMsgs != 0) && (host_client[0x918] == 0)) {
          sv_gpNewUserMsgs = sv_gpUserMsgs;
          SV_SendUserReg(auStack_10014);
        }
        sv_gpNewUserMsgs = uVar1;
        host_client[5] = 1;
        Netchan_CreateFragments(1,host_client + 8,auStack_10014);
        Netchan_FragSend(host_client + 8);
        SZ_Clear(auStack_10014);
      }
      host_client = host_client + 0x1415;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_001ab4e8);
  }
  HPAK_FlushHostQueue();
  if (DAT_001ab4e8 < 2) {
    Con_DPrintf("Game started\n");
  }
  else {
    Con_DPrintf("%i player server started\n",DAT_001ab4e8);
  }
  return;
}


// SV_AddCorrectGravity  @ 00080d94
void SV_AddCorrectGravity(int param_1)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  float fVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  lVar3 = (longdouble)0;
  lVar6 = (longdouble)1;
  lVar5 = (longdouble)*(float *)(param_1 + 0x19c);
  if ((byte)(lVar5 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar5 == lVar3) << 0xe) >> 8)) != 0x40) {
    lVar6 = lVar5;
  }
  fVar1 = (float)((longdouble)*(float *)(param_1 + 0xa8) -
                 (longdouble)0.5 * (longdouble)host_frametime *
                 lVar6 * (longdouble)(float)sv_gravity._12_4_);
  *(float *)(param_1 + 0xa8) = fVar1;
  fVar4 = (float)host_frametime;
  fVar2 = *(float *)(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(float *)(param_1 + 0xa8) = fVar4 * fVar2 + fVar1;
  SV_CheckVelocity(param_1);
  return;
}


// SV_AddGravity  @ 00080d0c
void SV_AddGravity(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_1 + 0x19c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 1.0;
  }
  fVar2 = *(float *)(param_1 + 0xa8) - (float)host_frametime * fVar1 * (float)sv_gravity._12_4_;
  *(float *)(param_1 + 0xa8) = fVar2;
  fVar3 = (float)host_frametime;
  fVar1 = *(float *)(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(float *)(param_1 + 0xa8) = fVar3 * fVar1 + fVar2;
  SV_CheckVelocity(param_1);
  return;
}


// SV_AddIP_f  @ 0007d24c
void SV_AddIP_f(void)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  longdouble lVar8;
  longdouble lVar9;
  uint local_c;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 3) {
    local_c = 0;
    uVar1 = local_c;
    if (0 < (int)numipfilters) {
      iVar2 = 0;
      uVar5 = numipfilters & 3;
      if (uVar5 == 0) {
LAB_0007d2f0:
        piVar6 = (int *)((int)&DAT_001a74c4 + iVar2);
        do {
          uVar1 = local_c;
          if ((((*piVar6 == -1) || (uVar1 = local_c + 1, piVar6[4] == -1)) ||
              (uVar1 = local_c + 2, piVar6[8] == -1)) || (uVar1 = local_c + 3, piVar6[0xc] == -1))
          break;
          piVar6 = piVar6 + 0x10;
          local_c = local_c + 4;
          uVar1 = local_c;
        } while ((int)local_c < (int)numipfilters);
      }
      else {
        if (1 < uVar5) {
          if (2 < uVar5) {
            if (DAT_001a74c4 == -1) goto LAB_0007d323;
            iVar2 = 0x10;
            local_c = 1;
          }
          uVar1 = local_c;
          if (*(int *)((int)&DAT_001a74c4 + iVar2) == -1) goto LAB_0007d323;
          iVar2 = iVar2 + 0x10;
          local_c = local_c + 1;
        }
        uVar1 = local_c;
        if (*(int *)((int)&DAT_001a74c4 + iVar2) != -1) {
          iVar2 = iVar2 + 0x10;
          local_c = local_c + 1;
          uVar1 = local_c;
          if ((int)local_c < (int)numipfilters) goto LAB_0007d2f0;
        }
      }
    }
LAB_0007d323:
    local_c = uVar1;
    if (local_c == numipfilters) {
      if (local_c == 0x400) {
        pcVar3 = "IP filter list is full\n";
        goto LAB_0007d33b;
      }
      numipfilters = local_c + 1;
    }
    uVar4 = Cmd_Argv(1);
    lVar8 = (longdouble)Q_atof(uVar4);
    lVar9 = (longdouble)0.01;
    if (0x3f < (byte)((lVar9 < lVar8 |
                       (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) - 1)) {
      lVar8 = (longdouble)0;
    }
    lVar9 = (longdouble)0;
    (&DAT_001a74cc)[local_c * 4] = (float)lVar8;
    if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 0x40) {
      lVar8 = (longdouble)(float)((longdouble)realtime + (longdouble)60.0 * lVar8);
    }
    *(float *)(&DAT_001a74c8 + local_c * 0x10) = (float)lVar8;
    uVar4 = Cmd_Argv(2,&ipfilters + local_c * 4);
    iVar2 = StringToFilter(uVar4);
    if (iVar2 == 0) {
      (&DAT_001a74c4)[local_c * 4] = 0xffffffff;
    }
    local_c = 0;
    host_client = DAT_001ab4e4;
    if (0 < DAT_001ab4e8) {
      do {
        if (((host_client[3] != 0) && (*host_client != 0)) &&
           ((host_client[1] != 0 && (host_client[0x918] == 0)))) {
          piVar6 = host_client + 9;
          piVar7 = &net_from;
          for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
            *piVar7 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          iVar2 = SV_FilterPacket();
          if (iVar2 != 0) {
            SV_ClientPrintf("The server operator has added you to banned list\n");
            SV_DropClient(host_client,0);
          }
        }
        local_c = local_c + 1;
        host_client = host_client + 0x1415;
      } while ((int)local_c < DAT_001ab4e8);
    }
  }
  else {
    pcVar3 = "Usage:  addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n";
LAB_0007d33b:
    Con_Printf(pcVar3);
  }
  return;
}


// SV_AddLinksToPM  @ 000850c4
void SV_AddLinksToPM(undefined4 param_1,float *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  Q_memset(pmove + 0x250,0,0xe0);
  Q_memset("Draw_CacheWadHandler" + pmove + 0xc,0,0xe0);
  *(int *)(pmove + 0x280) = DAT_00153668;
  if (DAT_00153668 != 0) {
    Q_strncpy(pmove + 0x250,DAT_00153668,0x20);
    *(undefined1 *)(pmove + 0x26f) = 0;
  }
  *(undefined4 *)(pmove + 0x274) = vec3_origin;
  *(undefined4 *)(pmove + 0x278) = DAT_000b2e2c;
  *(undefined4 *)(pmove + 0x27c) = DAT_000b2e30;
  *(undefined4 *)(pmove + 0x2a0) = 0;
  *(undefined4 *)(pmove + 0x2b0) = 4;
  *(undefined4 *)(pmove + 0x2cc) = 0;
  *(undefined4 *)(pmove + 0x2d0) = 1;
  *(undefined4 *)(pmove + 0x2d4) = 0;
  *(undefined4 *)(pmove + 0x24c) = 1;
  pcVar3 = "Draw_CacheWadHandler" + pmove + 8;
  pcVar3[0] = '\x01';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  puVar2 = (undefined4 *)(pmove + 0x250);
  pcVar3 = "Draw_CacheWadHandler" + pmove + 0xc;
  for (iVar1 = 0x38; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pcVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    pcVar3 = pcVar3 + 4;
  }
  pcVar3 = "__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc"
           + pmove + 0x21;
  pcVar3[0] = '\0';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  local_10 = *param_2 - 256.0;
  local_1c = *param_2 + 256.0;
  local_c = param_2[1] - 256.0;
  local_18 = param_2[1] + 256.0;
  local_8 = param_2[2] - 256.0;
  local_14 = param_2[2] + 256.0;
  SV_AddLinksToPM_(param_1,&local_10,&local_1c);
  return;
}


// SV_AddLinksToPM_  @ 00084d38
void SV_AddLinksToPM_(int *param_1,float *param_2,float *param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  longdouble lVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  longdouble lVar14;
  int local_2c;
  float *local_c;
  float *local_8;
  
  piVar4 = (int *)param_1[7];
joined_r0x00084d5b:
  while( true ) {
    piVar9 = piVar4;
    if (piVar9 == param_1 + 6) {
      iVar11 = *param_1;
      if (iVar11 != -1) {
        fVar2 = (float)param_1[1];
        if (fVar2 < param_3[iVar11]) {
          SV_AddLinksToPM_(param_1[2],param_2,param_3);
          iVar11 = *param_1;
          fVar2 = (float)param_1[1];
        }
        fVar3 = param_2[iVar11];
        if (0x3f < (byte)((fVar2 < fVar3 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
          SV_AddLinksToPM_(param_1[3],param_2,param_3);
        }
      }
      return;
    }
    piVar4 = (int *)piVar9[1];
    piVar1 = piVar9 + -2;
    uVar5 = piVar9[0xae];
    if (uVar5 == 0) break;
    if (g_groupop != 0) goto LAB_00084da0;
    if ((uVar5 & sv_player[0xb0]) != 0) break;
  }
  goto LAB_00084db6;
LAB_00084da0:
  if ((g_groupop != 1) || ((uVar5 & sv_player[0xb0]) == 0)) {
LAB_00084db6:
    if (((int *)piVar9[0x84] != sv_player) &&
       ((((iVar11 = piVar9[0x61], iVar11 == 4 || (iVar11 == 2)) || (iVar11 == 3)) || (iVar11 == 0)))
       ) {
      iVar10 = NUM_FOR_EDICT(piVar1);
      iVar11 = *(int *)("Draw_CacheWadHandler" + pmove + 8);
      iVar6 = *(int *)("Draw_CacheWadHandler" + pmove + 8);
      iVar8 = pmove + 0xc;
      *(int *)("Draw_CacheWadHandler" + pmove + 8) =
           *(int *)("Draw_CacheWadHandler" + pmove + 8) + 1;
      SV_CopyEdictToPhysent
                ("Draw_CacheWadHandler" + (iVar11 * 8 - iVar6) * 0x20 + iVar8,iVar10,piVar1);
      if (((((piVar9[0x61] != 0) || ((piVar9[0x62] != 0 && (piVar9[0x4b] != 0)))) &&
           (((uVar5 = piVar9[0x87], (uVar5 & 0x800000) == 0 || (piVar9[0x61] != 4)) &&
            ((piVar1 != sv_player && ((uVar5 & 0x4000000) == 0)))))) &&
          (((uVar5 & 8) == 0 || (0.0 < (float)piVar9[0x76])))) &&
         (((lVar7 = (longdouble)0,
           (byte)((byte)((ushort)((ushort)(NAN(lVar7) || NAN((longdouble)(float)piVar9[0x57])) << 10
                                 ) >> 8) |
                 (byte)((ushort)((ushort)(lVar7 == (longdouble)(float)piVar9[0x57]) << 0xe) >> 8))
           != 0x40 ||
           (fVar2 = (float)piVar9[0x5a],
           (byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) != 0x40)) &&
          (lVar14 = (longdouble)Length(piVar9 + 0x5b),
          (byte)(lVar7 < lVar14 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar14)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar7 == lVar14) << 0xe) >> 8)) != 0x40)))) {
        local_c = (float *)(piVar9 + 0x4f);
        local_8 = (float *)(piVar9 + 0x52);
        if ((*(byte *)(piVar9 + 0x87) & 8) != 0) {
          SV_GetTrueMinMax(iVar10 + -1,&local_c,&local_8);
        }
        local_2c = 0;
        fVar2 = *param_3;
        fVar3 = *local_c;
        if (((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) &&
           (*param_2 <= *local_8)) {
          local_2c = 1;
          fVar2 = param_3[1];
          fVar3 = local_c[1];
          if (((byte)(fVar2 < fVar3 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) &&
             (param_2[1] <= local_8[1])) {
            local_2c = 2;
            fVar2 = param_3[2];
            fVar3 = local_c[2];
            if (((byte)(fVar2 < fVar3 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) &&
               (param_2[2] <= local_8[2])) {
              local_2c = 3;
            }
          }
        }
        if (local_2c == 3) {
          if ((piVar9[0x61] == 0) && (piVar9[0x62] == -0x10)) {
            iVar10 = *(int *)(
                             "__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc"
                             + pmove + 0x21);
            if (0x3f < iVar10) {
              Con_DPrintf("SV_AddLinksToPM:  pmove->nummoveent >= MAX_MOVEENTS\n");
              goto joined_r0x00084d5b;
            }
            pcVar13 = "__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc"
                      + iVar10 * 0xe0 + pmove + 0x25;
            *(int *)(
                    "__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc"
                    + pmove + 0x21) = iVar10 + 1;
          }
          else {
            iVar10 = *(int *)(pmove + 0x24c);
            if (599 < iVar10) {
              Con_DPrintf("SV_AddLinksToPM:  pmove->numphysent >= MAX_PHYSENTS\n");
              return;
            }
            pcVar13 = (char *)(pmove + 0x250 + iVar10 * 0xe0);
            *(int *)(pmove + 0x24c) = iVar10 + 1;
          }
          pcVar12 = "Draw_CacheWadHandler" + (iVar11 * 8 - iVar6) * 0x20 + iVar8;
          for (iVar10 = 0x38; iVar10 != 0; iVar10 = iVar10 + -1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
        }
      }
    }
  }
  goto joined_r0x00084d5b;
}


// SV_AddResource  @ 0007b138
void SV_AddResource(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                   undefined4 param_5)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = DAT_0017de80;
  iVar1 = DAT_0017de80 * 0x88;
  if (0x4ff < DAT_0017de80) {
    Sys_Error("Too many resources on server.");
  }
  DAT_0017de80 = DAT_0017de80 + 1;
  (&DAT_001536c0)[iVar2 * 0x22] = param_1;
  Q_strcpy(&DAT_00153680 + iVar1,param_2);
  (&DAT_001536c8)[iVar2 * 0x22] = param_3;
  bVar3 = (&DAT_001536cc)[iVar1];
  if (param_4 != 0) {
    bVar3 = bVar3 | 1;
  }
  (&DAT_001536cc)[iVar1] = bVar3;
  (&DAT_001536c4)[iVar2 * 0x22] = param_5;
  return;
}


// SV_AddSampleToHashedLookupTable  @ 000739d8
void SV_AddSampleToHashedLookupTable(undefined4 param_1,undefined2 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = SV_HashString(param_1,0x3ff);
  sVar1 = (&DAT_00185e88)[iVar2];
  iVar3 = iVar2;
  while (sVar1 != 0) {
    iVar3 = iVar3 + 1;
    hashstrings_collisions = hashstrings_collisions + 1;
    if (0x3fe < iVar3) {
      iVar3 = 0;
    }
    if (iVar3 == iVar2) {
      Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
    }
    sVar1 = (&DAT_00185e88)[iVar3];
  }
  (&DAT_00185e88)[iVar3] = param_2;
  return;
}


// SV_AddToFatPAS  @ 00079450
void SV_AddToFatPAS(float *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  while (-1 < *param_2) {
    pfVar1 = (float *)param_2[6];
    fVar2 = (param_1[2] * pfVar1[2] + param_1[1] * pfVar1[1] + *param_1 * *pfVar1) - pfVar1[3];
    if (fVar2 <= 8.0) {
      if ((byte)((-8.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == -8.0) << 0xe) >> 8)) - 1) < 0x40) {
        SV_AddToFatPAS(param_1,param_2[7]);
        param_2 = (int *)param_2[8];
      }
      else {
        param_2 = (int *)param_2[8];
      }
    }
    else {
      param_2 = (int *)param_2[7];
    }
  }
  if (*param_2 != -2) {
    iVar3 = CM_LeafPAS(((int)param_2 - *(int *)(DAT_00153668 + 0x8c)) * -0x55555555 >> 4);
    iVar4 = 0;
    if (0 < fatpasbytes) {
      do {
        (&fatpas)[iVar4] = (&fatpas)[iVar4] | *(byte *)(iVar4 + iVar3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < fatpasbytes);
    }
  }
  return;
}


// SV_AddToFatPVS  @ 00079304
void SV_AddToFatPVS(float *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  while (-1 < *param_2) {
    pfVar1 = (float *)param_2[6];
    fVar2 = (param_1[2] * pfVar1[2] + param_1[1] * pfVar1[1] + *param_1 * *pfVar1) - pfVar1[3];
    if (fVar2 <= 8.0) {
      if ((byte)((-8.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == -8.0) << 0xe) >> 8)) - 1) < 0x40) {
        SV_AddToFatPVS(param_1,param_2[7]);
        param_2 = (int *)param_2[8];
      }
      else {
        param_2 = (int *)param_2[8];
      }
    }
    else {
      param_2 = (int *)param_2[7];
    }
  }
  if (*param_2 != -2) {
    iVar3 = Mod_LeafPVS(param_2,DAT_00153668);
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


// SV_AddToResourceList  @ 00083ac4
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


// SV_AllocClientFrames  @ 00072bac
void SV_AllocClientFrames(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_001ab4ec) {
    piVar2 = (int *)(DAT_001ab4e4 + 0x34e0);
    do {
      if (*piVar2 != 0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar1 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0xd10);
      *piVar2 = iVar1;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x1415;
    } while (iVar3 < DAT_001ab4ec);
  }
  return;
}


// SV_AllocPacketEntities  @ 00072c70
void SV_AllocPacketEntities(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xd0c) != 0) {
      SV_ClearPacketEntities(param_1);
    }
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 1;
    }
    uVar2 = Mem_ZeroMalloc(iVar1 * 0x154);
    *(undefined4 *)(param_1 + 0xd0c) = uVar2;
    *(int *)(param_1 + 0xce8) = param_2;
  }
  return;
}


// SV_BanId_f  @ 0007c8d0
void SV_BanId_f(void)

{
  uint uVar1;
  longdouble lVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  longdouble lVar10;
  int *local_140;
  int *local_13c;
  int *local_138;
  int *local_134;
  undefined8 local_12c;
  int local_110;
  int local_10c;
  char local_104 [256];
  
  iVar3 = Cmd_Argc();
  if ((iVar3 < 3) || (iVar3 = Cmd_Argc(), 5 < iVar3)) {
    pcVar4 = 
    "Usage:  banid <minutes> <uniqueid or #userid > { kick }\nUse 0 minutes for permanent\n";
LAB_0007cd70:
    Con_Printf(pcVar4);
  }
  else {
    pcVar4 = (char *)Cmd_Argv(2);
    if ((pcVar4 == (char *)0x0) || (*pcVar4 != '#')) {
      uVar5 = Cmd_Argv(2);
      local_10c = Q_atoi(uVar5);
      if (local_10c == -1) {
        pcVar4 = (char *)FUN_000abc00;
        goto LAB_0007cd70;
      }
    }
    else {
      iVar3 = Q_strlen(pcVar4);
      if (iVar3 == 1) {
        iVar3 = Cmd_Argc();
        if (iVar3 < 3) {
          pcVar4 = "Insufficient arguments to banid\n";
          goto LAB_0007cd70;
        }
        uVar5 = Cmd_Argv(3);
        local_110 = Q_atoi(uVar5);
      }
      else {
        local_110 = Q_atoi(pcVar4 + 1);
      }
      iVar3 = 0;
      if (0 < (int)DAT_001ab4e8) {
        local_140 = DAT_001ab4e4 + 0x12bb;
        local_13c = DAT_001ab4e4 + 0x918;
        uVar8 = DAT_001ab4e8 & 3;
        piVar6 = DAT_001ab4e4;
        local_138 = local_13c;
        local_134 = local_13c;
        if (uVar8 == 0) {
LAB_0007cadc:
          do {
            if ((((*piVar6 != 0) || (local_138[-0x915] != 0)) || (local_134[-0x917] != 0)) &&
               ((*local_13c == 0 && (piVar7 = piVar6, *local_140 == local_110)))) goto LAB_0007c960;
            piVar7 = piVar6 + 0x1415;
            if ((((*piVar7 != 0) || ((local_138[0xb00] != 0 || (local_134[0xafe] != 0)))) &&
                (local_13c[0x1415] == 0)) && (local_140[0x1415] == local_110)) goto LAB_0007c960;
            piVar7 = piVar6 + 0x282a;
            if ((((*piVar7 != 0) || (local_138[0x1f15] != 0)) || (local_134[0x1f13] != 0)) &&
               ((local_13c[0x282a] == 0 && (local_140[0x282a] == local_110)))) goto LAB_0007c960;
            piVar7 = piVar6 + 0x3c3f;
            if (((*piVar7 != 0) || ((local_138[0x332a] != 0 || (local_134[0x3328] != 0)))) &&
               ((local_13c[0x3c3f] == 0 && (local_140[0x3c3f] == local_110)))) goto LAB_0007c960;
            iVar3 = iVar3 + 4;
            local_13c = local_13c + 0x5054;
            local_134 = local_134 + 0x5054;
            local_138 = local_138 + 0x5054;
            local_140 = local_140 + 0x5054;
            piVar6 = piVar6 + 0x5054;
          } while (iVar3 < (int)DAT_001ab4e8);
        }
        else {
          piVar7 = DAT_001ab4e4;
          if (uVar8 < 2) {
LAB_0007ca75:
            if ((((*piVar7 == 0) && (local_13c[-0x915] == 0)) && (local_13c[-0x917] == 0)) ||
               ((*local_13c != 0 || (*local_140 != local_110)))) {
              iVar3 = iVar3 + 1;
              local_13c = local_13c + 0x1415;
              local_140 = local_140 + 0x1415;
              piVar6 = piVar7 + 0x1415;
              local_138 = local_13c;
              local_134 = local_13c;
              if ((int)DAT_001ab4e8 <= iVar3) goto LAB_0007cc52;
              goto LAB_0007cadc;
            }
          }
          else if (uVar8 < 3) {
LAB_0007ca2e:
            if ((((*piVar7 == 0) && (local_13c[-0x915] == 0)) && (local_13c[-0x917] == 0)) ||
               ((*local_13c != 0 || (*local_140 != local_110)))) {
              iVar3 = iVar3 + 1;
              local_13c = local_13c + 0x1415;
              local_140 = local_140 + 0x1415;
              piVar7 = piVar7 + 0x1415;
              goto LAB_0007ca75;
            }
          }
          else if ((((*DAT_001ab4e4 == 0) && (DAT_001ab4e4[3] == 0)) && (DAT_001ab4e4[1] == 0)) ||
                  ((*local_13c != 0 || (*local_140 != local_110)))) {
            iVar3 = 1;
            local_13c = DAT_001ab4e4 + 0x1d2d;
            local_140 = DAT_001ab4e4 + 0x26d0;
            piVar7 = DAT_001ab4e4 + 0x1415;
            goto LAB_0007ca2e;
          }
LAB_0007c960:
          local_10c = piVar7[0x12bc];
        }
      }
LAB_0007cc52:
      if (local_10c == -1) {
        Con_Printf("Couldn\'t find userid %u, or user is a LAN user and has no unique id\n",
                   0xffffffff);
        return;
      }
    }
    uVar8 = 0;
    if (0 < (int)numuserfilters) {
      iVar3 = 0;
      uVar1 = numuserfilters & 3;
      uVar9 = uVar8;
      if (uVar1 == 0) goto LAB_0007cd24;
      if (1 < uVar1) {
        if (2 < uVar1) {
          if (userfilters == local_10c) goto LAB_0007cd58;
          iVar3 = 0xc;
          uVar8 = 1;
        }
        if (*(int *)((int)&userfilters + iVar3) == local_10c) goto LAB_0007cd58;
        iVar3 = iVar3 + 0xc;
        uVar8 = uVar8 + 1;
      }
      if (*(int *)((int)&userfilters + iVar3) != local_10c) {
        iVar3 = iVar3 + 0xc;
        while (uVar9 = uVar8 + 1, uVar8 = uVar9, (int)uVar9 < (int)numuserfilters) {
LAB_0007cd24:
          uVar8 = uVar9;
          if ((((*(int *)((int)&userfilters + iVar3) == local_10c) ||
               (uVar8 = uVar9 + 1, *(int *)((int)&DAT_0019246c + iVar3) == local_10c)) ||
              (uVar8 = uVar9 + 2, *(int *)((int)&DAT_00192478 + iVar3) == local_10c)) ||
             (uVar8 = uVar9 + 3, *(int *)((int)&DAT_00192484 + iVar3) == local_10c)) break;
          iVar3 = iVar3 + 0x30;
        }
      }
    }
LAB_0007cd58:
    if (uVar8 == numuserfilters) {
      if (0x3ff < (int)uVar8) {
        pcVar4 = "User filter list is full\n";
        goto LAB_0007cd70;
      }
      numuserfilters = uVar8 + 1;
    }
    uVar5 = Cmd_Argv(1);
    lVar10 = (longdouble)Q_atof(uVar5);
    local_12c = (double)lVar10;
    if (0x3f < (byte)((0.01 < local_12c | (byte)((ushort)((ushort)NAN(local_12c) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_12c == 0.01) << 0xe) >> 8)) - 1)) {
      lVar10 = (longdouble)0;
      local_12c = 0.0;
    }
    lVar2 = (longdouble)0;
    (&DAT_00192468)[uVar8 * 3] = (float)lVar10;
    lVar10 = (longdouble)local_12c;
    if ((byte)(lVar10 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar10) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar10 == lVar2) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(&DAT_00192464 + uVar8 * 0xc) = 0;
    }
    else {
      *(float *)(&DAT_00192464 + uVar8 * 0xc) =
           (float)((longdouble)60.0 * lVar10 + (longdouble)realtime);
    }
    (&userfilters)[uVar8 * 3] = local_10c;
    iVar3 = Cmd_Argc();
    if (3 < iVar3) {
      iVar3 = Cmd_Argc(&DAT_000abc4e);
      uVar5 = Cmd_Argv(iVar3 + -1);
      iVar3 = Q_strcasecmp(uVar5);
      uVar5 = host_client;
      if ((iVar3 == 0) && (iVar3 = 0, 0 < (int)DAT_001ab4e8)) {
        piVar6 = DAT_001ab4e4 + 0x12bc;
        local_13c = DAT_001ab4e4 + 0x918;
        piVar7 = DAT_001ab4e4;
        do {
          if ((((*piVar7 != 0) || (local_13c[-0x915] != 0)) || (local_13c[-0x917] != 0)) &&
             ((*local_13c == 0 && (*piVar6 == local_10c)))) {
            host_client = piVar7;
            if ((byte)((byte)((ushort)((ushort)NAN(local_12c) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_12c == 0.0) << 0xe) >> 8)) == 0x40) {
              sprintf(local_104,"permanently");
            }
            else {
              sprintf(local_104,"for %.2f minutes",(undefined4)local_12c,local_12c._4_4_);
            }
            SV_ClientPrintf("You have been kicked and banned %s by the server op.\n",local_104);
            SV_DropClient(host_client,0);
            host_client = (int *)uVar5;
            return;
          }
          iVar3 = iVar3 + 1;
          local_13c = local_13c + 0x1415;
          piVar6 = piVar6 + 0x1415;
          piVar7 = piVar7 + 0x1415;
        } while (iVar3 < (int)DAT_001ab4e8);
      }
    }
  }
  return;
}


// SV_BatchUploadRequest  @ 00083d10
void SV_BatchUploadRequest(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char local_108 [260];
  
  iVar1 = *(int *)(param_1 + 0x4d8c);
joined_r0x00083d3f:
  iVar2 = iVar1;
  if (iVar2 == param_1 + 0x4d0c) {
    return;
  }
  iVar1 = *(int *)(iVar2 + 0x80);
  if ((*(byte *)(iVar2 + 0x4c) & 2) != 0) goto code_r0x00083d57;
  goto LAB_00083da9;
code_r0x00083d57:
  if (*(int *)(iVar2 + 0x40) == 3) {
    if ((*(byte *)(iVar2 + 0x4c) & 4) == 0) {
      Con_Printf("Non customization in upload queue!\n");
      SV_MoveToOnHandList(iVar2);
    }
    else {
      uVar3 = MD5_Print(iVar2 + 0x4d);
      sprintf(local_108,"!MD5%s",uVar3);
      iVar4 = SV_CheckFile(param_1 + 0x74,local_108);
      if (iVar4 != 0) {
LAB_00083da9:
        SV_MoveToOnHandList(iVar2);
      }
    }
  }
  goto joined_r0x00083d3f;
}


// SV_BeginFileDownload_f  @ 0007d960
void SV_BeginFileDownload_f(void)

{
  int iVar1;
  char *pcVar2;
  int local_a4;
  int local_a0;
  undefined1 local_9c [136];
  undefined1 local_14 [16];
  
  iVar1 = Cmd_Argc();
  if ((((1 < iVar1) && (cmd_source != 1)) && (pcVar2 = (char *)Cmd_Argv(1), pcVar2 != (char *)0x0))
     && (*pcVar2 != '\0')) {
    iVar1 = Q_strstr(pcVar2,&DAT_000abf2c);
    if ((iVar1 == 0) &&
       ((byte)((float)sv_allow_download._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)sv_allow_download._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_allow_download._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40)) {
      Con_DPrintf("Downloading %s to %s\n",pcVar2,host_client + 0x4c3c);
      iVar1 = Q_strlen(pcVar2);
      if ((iVar1 == 0x24) && (iVar1 = Q_strnicmp(pcVar2,&DAT_000abf45,4), iVar1 == 0)) {
        local_a4 = 0;
        local_a0 = 0;
        Q_memset(local_9c,0,0x88);
        COM_HexConvert(pcVar2 + 4,0x20,local_14);
        iVar1 = HPAK_ResourceForHash("custom.hpk",local_14,local_9c);
        if (iVar1 == 0) {
          return;
        }
        HPAK_GetDataPointer("custom.hpk",local_9c,&local_a4,&local_a0);
        if (local_a4 == 0) {
          return;
        }
        if (local_a0 == 0) {
          return;
        }
        Netchan_CreateFileFragmentsFromBuffer(1,host_client + 0x20,pcVar2,local_a4,local_a0);
        Netchan_FragSend(host_client + 0x20);
        Mem_Free(local_a4);
        return;
      }
      iVar1 = Netchan_CreateFileFragments(1,host_client + 0x20,pcVar2);
      if (iVar1 != 0) {
        Netchan_FragSend(host_client + 0x20);
        return;
      }
    }
    SV_FailDownload(pcVar2);
  }
  return;
}


// SV_BeginRedirect  @ 00077f30
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


// SV_BroadcastCommand  @ 0007b964
void SV_BroadcastCommand(char *param_1)

{
  int *piVar1;
  int *piVar2;
  int *local_49c;
  int local_498;
  undefined2 local_494 [2];
  undefined1 *local_490;
  undefined4 local_48c;
  undefined4 local_488;
  undefined1 local_484 [128];
  char local_404 [1024];
  
  local_490 = local_484;
  local_488 = 0;
  local_48c = 0x80;
  local_494[0] = 0;
  if (sv != 0) {
    vsprintf(local_404,param_1,&stack0x00000008);
    MSG_WriteByte(local_494,9);
    MSG_WriteString(local_494,local_404);
    local_498 = 0;
    if (0 < DAT_001ab4e8) {
      local_49c = DAT_001ab4e4 + 0x1d;
      piVar1 = DAT_001ab4e4 + 0x918;
      piVar2 = DAT_001ab4e4;
      do {
        if ((((*piVar2 != 0) || (piVar1[-0x915] != 0)) || (piVar1[-0x917] != 0)) && (*piVar1 == 0))
        {
          SZ_Write(local_49c,local_490,local_488);
        }
        local_498 = local_498 + 1;
        piVar1 = piVar1 + 0x1415;
        local_49c = local_49c + 0x1415;
        piVar2 = piVar2 + 0x1415;
      } while (local_498 < DAT_001ab4e8);
    }
  }
  return;
}


// SV_BroadcastPrintf  @ 0005539c
void SV_BroadcastPrintf(char *param_1)

{
  int iVar1;
  int iVar2;
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  iVar2 = 0;
  if (0 < DAT_001ab4e8) {
    iVar1 = 0;
    do {
      if (((*(int *)(DAT_001ab4e4 + iVar1) != 0) || (*(int *)(DAT_001ab4e4 + 4 + iVar1) != 0)) &&
         (*(int *)(DAT_001ab4e4 + 0x2460 + iVar1) == 0)) {
        MSG_WriteByte(iVar1 + DAT_001ab4e4 + 0x74,8);
        MSG_WriteString(iVar1 + DAT_001ab4e4 + 0x74,local_404);
      }
      iVar1 = iVar1 + 0x5054;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_001ab4e8);
  }
  return;
}


// SV_BuildHashedSoundLookupTable  @ 000738cc
void SV_BuildHashedSoundLookupTable(void)

{
  int iVar1;
  
  Q_memset(&DAT_00185e88,0,0x7fe);
  iVar1 = 0;
  while( true ) {
    if ((&DAT_00185688)[iVar1] == 0) {
      DAT_00186688 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1],iVar1);
    if ((&DAT_00185688)[iVar1 + 1] == 0) {
      DAT_00186688 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1 + 1],iVar1 + 1);
    if ((&DAT_00185688)[iVar1 + 2] == 0) {
      DAT_00186688 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1 + 2],iVar1 + 2);
    if ((&DAT_00185688)[iVar1 + 3] == 0) {
      DAT_00186688 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1 + 3],iVar1 + 3);
    if ((&DAT_00185688)[iVar1 + 4] == 0) {
      DAT_00186688 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1 + 4],iVar1 + 4);
    if ((&DAT_00185688)[iVar1 + 5] == 0) {
      DAT_00186688 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1 + 5],iVar1 + 5);
    if ((&DAT_00185688)[iVar1 + 6] == 0) {
      DAT_00186688 = 1;
      return;
    }
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1 + 6],iVar1 + 6);
    if ((&DAT_00185688)[iVar1 + 7] == 0) break;
    SV_AddSampleToHashedLookupTable((&DAT_00185688)[iVar1 + 7],iVar1 + 7);
    iVar1 = iVar1 + 8;
    if (0x1ff < iVar1) {
      DAT_00186688 = 1;
      return;
    }
  }
  DAT_00186688 = 1;
  return;
}


// SV_BuildReconnect  @ 0007ba84
void SV_BuildReconnect(undefined4 param_1)

{
  MSG_WriteByte(param_1,9);
  MSG_WriteString(param_1,"reconnect\n");
  return;
}


// SV_BuildSoundMsg  @ 00073460
undefined4
SV_BuildSoundMsg(undefined4 param_1,uint param_2,char *param_3,uint param_4,float param_5,
                uint param_6,uint param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  
  if (0xff < param_4) {
    Sys_Error("SV_StartSound: volume = %i",param_4);
  }
  if ((param_5 < 0.0) || (4.0 < param_5)) {
    Sys_Error("SV_StartSound: attenuation = %f",(double)param_5);
  }
  if (7 < param_2) {
    Sys_Error("SV_StartSound: channel = %i",param_2);
  }
  if (0xff < param_7) {
    Sys_Error("SV_StartSound: pitch = %i",param_7);
  }
  if ((param_3 == (char *)0x0) || (*param_3 != '!')) {
    iVar1 = SV_LookupSoundIndex(param_3);
    if ((iVar1 == 0) || ((&DAT_00185688)[iVar1] == 0)) {
      Con_Printf("SV_StartSound: %s not precached (%d)\n",param_3,iVar1);
      return 0;
    }
  }
  else {
    param_6 = param_6 | 0x10;
    iVar1 = Q_atoi(param_3 + 1);
    if (0x5ff < iVar1) {
      Con_Printf("invalid sentence number: %s",param_3 + 1);
      return 0;
    }
  }
  uVar2 = NUM_FOR_EDICT(param_1);
  if (param_4 != 0xff) {
    param_6 = param_6 | 1;
  }
  if ((byte)(param_5 < 1.0 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 1.0) << 0xe) >> 8)) != 0x40) {
    param_6 = param_6 | 2;
  }
  if (param_7 != 100) {
    param_6 = param_6 | 8;
  }
  if (0xff < iVar1) {
    param_6 = param_6 | 4;
  }
  MSG_WriteByte(param_9,6);
  MSG_StartBitWriting(param_9);
  MSG_WriteBits(param_6,9);
  if ((param_6 & 1) != 0) {
    MSG_WriteBits(param_4,8);
  }
  if ((param_6 & 2) != 0) {
    MSG_WriteBits((int)ROUND(param_5 * 64.0),8);
  }
  MSG_WriteBits(param_2,3);
  MSG_WriteBits(uVar2,0xb);
  if (iVar1 < 0x100) {
    uVar2 = 8;
  }
  else {
    uVar2 = 0x10;
  }
  MSG_WriteBits(iVar1,uVar2);
  MSG_WriteBitVec3Coord(param_8);
  if ((param_6 & 8) != 0) {
    MSG_WriteBits(param_7,8);
  }
  MSG_EndBitWriting(param_9);
  return 1;
}


// SV_CalcClientTime  @ 00086830
longdouble SV_CalcClientTime(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  longdouble lVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  longdouble lVar11;
  longdouble lVar12;
  uint local_14;
  
  uVar9 = 0;
  lVar12 = (longdouble)0;
  local_14 = (uint)ROUND((float)sv_unlagsamples._12_4_);
  if ((int)local_14 < 1) {
    local_14 = 1;
  }
  if ((int)SV_UPDATE_BACKUP < 0x11) {
    if ((int)SV_UPDATE_BACKUP <= (int)local_14) {
LAB_00086892:
      local_14 = 0x10;
      if ((int)SV_UPDATE_BACKUP < 0x11) {
        local_14 = SV_UPDATE_BACKUP;
      }
    }
  }
  else if (0xf < (int)local_14) goto LAB_00086892;
  iVar7 = 0;
  if (0 < (int)local_14) {
    uVar4 = *(uint *)(param_1 + 0x54);
    lVar6 = (longdouble)0;
    uVar8 = local_14 & 3;
    iVar5 = *(int *)(param_1 + 0x34e0);
    if (uVar8 != 0) {
      if (1 < uVar8) {
        if (2 < uVar8) {
          lVar11 = (longdouble)*(float *)((uVar4 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar5);
          bVar10 = 0x3f < (byte)((lVar11 < lVar6 |
                                  (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar6)) << 10) >> 8) |
                                 (byte)((ushort)((ushort)(lVar11 == lVar6) << 0xe) >> 8)) - 1);
          if (bVar10) {
            lVar12 = lVar11 + lVar12;
          }
          uVar9 = (uint)bVar10;
          iVar7 = 1;
        }
        lVar11 = (longdouble)*(float *)((uVar4 - iVar7 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar5);
        if (0x3f < (byte)((lVar11 < lVar6 |
                           (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar6)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar11 == lVar6) << 0xe) >> 8)) - 1)) {
          lVar12 = lVar11 + lVar12;
          uVar9 = uVar9 + 1;
        }
        iVar7 = iVar7 + 1;
      }
      lVar11 = (longdouble)*(float *)((uVar4 - iVar7 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar5);
      if (0x3f < (byte)((lVar11 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar11 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar12 = lVar11 + lVar12;
        uVar9 = uVar9 + 1;
      }
      iVar7 = iVar7 + 1;
      if ((int)local_14 <= iVar7) goto LAB_00086a81;
    }
    do {
      lVar11 = (longdouble)*(float *)((uVar4 - iVar7 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar5);
      if (0x3f < (byte)((lVar11 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar11 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar12 = lVar11 + lVar12;
        uVar9 = uVar9 + 1;
      }
      lVar11 = (longdouble)*(float *)((uVar4 - (iVar7 + 1) & SV_UPDATE_MASK) * 0xd10 + 8 + iVar5);
      if (0x3f < (byte)((lVar11 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar11 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar12 = lVar11 + lVar12;
        uVar9 = uVar9 + 1;
      }
      lVar11 = (longdouble)*(float *)((uVar4 - (iVar7 + 2) & SV_UPDATE_MASK) * 0xd10 + 8 + iVar5);
      if (0x3f < (byte)((lVar11 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar11 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar12 = lVar11 + lVar12;
        uVar9 = uVar9 + 1;
      }
      lVar11 = (longdouble)*(float *)((uVar4 - (iVar7 + 3) & SV_UPDATE_MASK) * 0xd10 + 8 + iVar5);
      if (0x3f < (byte)((lVar11 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar11 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar12 = lVar11 + lVar12;
        uVar9 = uVar9 + 1;
      }
      iVar7 = iVar7 + 4;
    } while (iVar7 < (int)local_14);
  }
LAB_00086a81:
  if (uVar9 != 0) {
    iVar7 = 0;
    fVar1 = 9999.0;
    fVar2 = -9999.0;
    do {
      if ((int)SV_UPDATE_BACKUP < 5) {
        if ((int)SV_UPDATE_BACKUP <= iVar7) goto LAB_00086b46;
      }
      else if (3 < iVar7) goto LAB_00086b46;
      fVar3 = *(float *)((*(int *)(param_1 + 0x54) - iVar7 & SV_UPDATE_MASK) * 0xd10 +
                         *(int *)(param_1 + 0x34e0) + 8);
      if (0x3f < (byte)((fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1)) {
        if (fVar3 < fVar1) {
          fVar1 = fVar3;
        }
        if (0x3f < (byte)((fVar3 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1)) {
          fVar2 = fVar3;
        }
      }
      iVar7 = iVar7 + 1;
    } while( true );
  }
LAB_00086b67:
  return (longdouble)0;
LAB_00086b46:
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
    return lVar12 / (longdouble)(int)uVar9;
  }
  if (ABS(fVar2 - fVar1) <= 0.2) {
    return lVar12 / (longdouble)(int)uVar9;
  }
  goto LAB_00086b67;
}


// SV_CalcPing  @ 00078b80
int SV_CalcPing(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_18;
  int local_14;
  
  if (*(int *)(param_1 + 0x2460) == 0) {
    fVar1 = 0.0;
    uVar6 = 0;
    local_18 = SV_UPDATE_BACKUP / 2;
    if (0x10 < (int)local_18) {
      local_18 = 0x10;
    }
    local_14 = 0;
    if (0 < (int)local_18) {
      iVar3 = *(int *)(param_1 + 0x34e0);
      uVar4 = *(int *)(param_1 + 0x54) - 1;
      uVar5 = local_18 & 3;
      if (uVar5 == 0) goto LAB_00078ccc;
      if (1 < uVar5) {
        if (2 < uVar5) {
          fVar1 = *(float *)((uVar4 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar3);
          bVar7 = (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40;
          if (bVar7) {
            fVar1 = 0.0;
          }
          uVar6 = (uint)!bVar7;
          uVar4 = *(int *)(param_1 + 0x54) - 2;
          local_14 = 1;
        }
        fVar2 = *(float *)((uVar4 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar3);
        if (0x3f < (byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar2 + fVar1;
          uVar6 = uVar6 + 1;
        }
        uVar4 = uVar4 - 1;
        local_14 = local_14 + 1;
      }
      fVar2 = *(float *)((uVar4 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar3);
      if (0x3f < (byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
        fVar1 = fVar2 + fVar1;
        uVar6 = uVar6 + 1;
      }
      uVar4 = uVar4 - 1;
      for (local_14 = local_14 + 1; local_14 < (int)local_18; local_14 = local_14 + 4) {
LAB_00078ccc:
        fVar2 = *(float *)((uVar4 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar3);
        if (0x3f < (byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar2 + fVar1;
          uVar6 = uVar6 + 1;
        }
        fVar2 = *(float *)((uVar4 - 1 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar3);
        if (0x3f < (byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar2 + fVar1;
          uVar6 = uVar6 + 1;
        }
        fVar2 = *(float *)((uVar4 - 2 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar3);
        if (0x3f < (byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar2 + fVar1;
          uVar6 = uVar6 + 1;
        }
        fVar2 = *(float *)((uVar4 - 3 & SV_UPDATE_MASK) * 0xd10 + 8 + iVar3);
        if (0x3f < (byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar2 + fVar1;
          uVar6 = uVar6 + 1;
        }
        uVar4 = uVar4 - 4;
      }
    }
    if (uVar6 == 0) {
      iVar3 = 0;
    }
    else {
      fVar1 = fVar1 / (float)(int)uVar6;
      if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        fVar1 = 0.0;
      }
      iVar3 = (int)ROUND(fVar1 * 1000.0);
    }
  }
  else {
    iVar3 = 5;
  }
  return iVar3;
}


// SV_CheckAllEnts  @ 0007fda0
void SV_CheckAllEnts(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (1 < DAT_00186f8c) {
    iVar4 = 0x324;
    iVar3 = 1;
    do {
      piVar2 = (int *)(iVar4 + DAT_00186f94);
      if ((((*piVar2 == 0) && (iVar1 = piVar2[0x62], iVar1 != 7)) && (iVar1 != 0)) &&
         ((iVar1 != 0xc && (iVar1 != 8)))) {
        iVar1 = SV_TestEntityPosition(piVar2);
        if (iVar1 != 0) {
          Con_Printf("entity in invalid position\n");
        }
      }
      iVar4 = iVar4 + 0x324;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00186f8c);
  }
  return;
}


// SV_CheckBottom  @ 0007e8d4
/* WARNING: Removing unreachable block (ram,0x0007e986) */
/* WARNING: Removing unreachable block (ram,0x0007e9d4) */

undefined4 SV_CheckBottom(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  float **ppfVar6;
  undefined1 *puVar7;
  int iVar8;
  int aiStackY_e4 [2];
  float *pfStack_c0;
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
  
  pfVar4 = (float *)(uint)((*(byte *)(param_1 + 0x226) & 0x80) != 0);
  local_10 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x15c);
  local_c = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x160);
  local_8 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x164);
  local_1c = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x168);
  local_18 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x16c);
  local_14 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x170);
  local_20 = local_8 - 1.0;
  iVar8 = 0;
  while( true ) {
    local_28 = local_10;
    if (iVar8 != 0) {
      local_28 = local_1c;
    }
    local_24 = local_c;
    g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
    pfStack_c0 = &local_28;
    iVar5 = SV_PointContents();
    if (iVar5 != -2) break;
    local_28 = local_10;
    if (iVar8 != 0) {
      local_28 = local_1c;
    }
    local_24 = local_18;
    g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
    pfStack_c0 = &local_28;
    iVar5 = SV_PointContents();
    if (iVar5 != -2) break;
    iVar8 = iVar8 + 1;
    if (1 < iVar8) goto LAB_0007ebb6;
  }
  c_no = c_no + 1;
  local_20 = local_8 + (float)sv_stepsize._12_4_;
  local_34 = (local_10 + local_1c) * 0.5;
  local_30 = (local_c + local_18) * 0.5;
  local_2c = local_20 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
  pfStack_c0 = pfVar4;
  local_28 = local_34;
  local_24 = local_30;
  SV_Move(local_6c,&local_28,&vec3_origin,&vec3_origin,&local_34,1,param_1);
  fVar3 = local_50;
  ppfVar6 = &pfStack_c0;
  if ((byte)(1.0 < local_5c | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) == 0x40) {
    return 0;
  }
  iVar8 = 0;
  fVar1 = local_50;
  do {
    iVar5 = 0;
    puVar7 = (undefined1 *)ppfVar6;
    do {
      local_34 = local_10;
      if (iVar8 != 0) {
        local_34 = local_1c;
      }
      local_30 = local_c;
      if (iVar5 != 0) {
        local_30 = local_18;
      }
      *(float **)(puVar7 + -4) = pfVar4;
      *(int *)(puVar7 + -8) = param_1;
      *(undefined4 *)(puVar7 + -0xc) = 1;
      *(float **)(puVar7 + -0x10) = &local_34;
      *(undefined4 **)(puVar7 + -0x14) = &vec3_origin;
      *(undefined4 **)(puVar7 + -0x18) = &vec3_origin;
      *(float **)(puVar7 + -0x1c) = &local_28;
      *(undefined1 **)(puVar7 + -0x20) = local_6c;
      *(undefined4 *)(puVar7 + -0x24) = 0x7eb29;
      local_28 = local_34;
      local_24 = local_30;
      SV_Move();
      ppfVar6 = (float **)(puVar7 + -4);
      if (((byte)(local_5c < 1.0 | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) != 0x40) &&
         (0x3f < (byte)((local_50 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(local_50) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_50 == fVar1) << 0xe) >> 8)) - 1))) {
        fVar1 = local_50;
      }
      if ((byte)(local_5c < 1.0 | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) == 0x40) {
        return 0;
      }
      fVar2 = fVar3 - local_50;
      if (0x3f < (byte)((fVar2 < (float)sv_stepsize._12_4_ |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN((float)sv_stepsize._12_4_)) <<
                                        10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == (float)sv_stepsize._12_4_) << 0xe) >> 8))
                       - 1)) {
        return 0;
      }
      iVar5 = iVar5 + 1;
      puVar7 = puVar7 + -4;
    } while (iVar5 < 2);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
LAB_0007ebb6:
  c_yes = c_yes + 1;
  return 1;
}


// SV_CheckChallenge  @ 00075cd8
undefined4 SV_CheckChallenge(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  undefined4 auStack_44 [4];
  undefined4 uStack_34;
  char *apcStack_30 [5];
  int local_c;
  int local_8;
  
  apcStack_30[4] = (char *)0x75ce6;
  if (param_1 == (undefined4 *)0x0) {
    apcStack_30[4] = "SV_CheckChallenge:  Null address\n";
    apcStack_30[3] = (char *)0x75cff;
    Sys_Error();
LAB_00075e2c:
    uVar1 = 0;
  }
  else {
    puVar3 = param_1;
    ppcVar4 = apcStack_30;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar4 = (char *)*puVar3;
      puVar3 = puVar3 + 1;
      ppcVar4 = ppcVar4 + 1;
    }
    uStack_34 = 0x75d19;
    iVar2 = NET_IsLocalAddress();
    if (iVar2 == 0) {
      local_8 = 0;
      local_c = 0;
      do {
        puVar3 = (undefined4 *)(g_rg_sv_challenges + local_c);
        ppcVar4 = apcStack_30;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *ppcVar4 = (char *)*puVar3;
          puVar3 = puVar3 + 1;
          ppcVar4 = ppcVar4 + 1;
        }
        puVar3 = &net_from;
        puVar5 = auStack_44;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar5 = puVar5 + 1;
        }
        iVar2 = NET_CompareBaseAdr();
        if (iVar2 != 0) {
          if (param_2 != *(int *)(g_rg_sv_challenges + local_c + 0x14)) {
            apcStack_30[4] = "Bad challenge.\n";
            goto LAB_00075e27;
          }
          break;
        }
        puVar3 = (undefined4 *)(g_rg_sv_challenges + local_c + 0x1c);
        ppcVar4 = apcStack_30;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *ppcVar4 = (char *)*puVar3;
          puVar3 = puVar3 + 1;
          ppcVar4 = ppcVar4 + 1;
        }
        puVar3 = &net_from;
        puVar5 = auStack_44;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar5 = puVar5 + 1;
        }
        iVar2 = NET_CompareBaseAdr();
        if (iVar2 != 0) {
          local_8 = local_8 + 1;
          if (param_2 != *(int *)(g_rg_sv_challenges + local_c + 0x30)) {
            apcStack_30[4] = "Bad challenge.\n";
            goto LAB_00075e27;
          }
          break;
        }
        local_c = local_c + 0x38;
        local_8 = local_8 + 2;
      } while (local_8 < 0x400);
      if (local_8 == 0x400) {
        apcStack_30[4] = "No challenge for your address.\n";
LAB_00075e27:
        apcStack_30[3] = (char *)param_1;
        apcStack_30[2] = (char *)0x75e2c;
        SV_RejectConnection();
        goto LAB_00075e2c;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


// SV_CheckCmdTimes  @ 0007ddc4
void SV_CheckCmdTimes(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((1.0 <= realtime - lastreset_284) && (iVar2 = 0, lastreset_284 = realtime, 0 < DAT_001ab4e8))
  {
    iVar3 = 0;
    do {
      iVar1 = iVar3 + DAT_001ab4e4;
      iVar3 = iVar3 + 0x5054;
      *(undefined4 *)(iVar1 + 0x24a8) = 0;
      *(undefined4 *)(iVar1 + 0x24ac) = 0x409c2000;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_001ab4e8);
  }
  return;
}


// SV_CheckFile  @ 00083634
undefined4 SV_CheckFile(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_8c [77];
  undefined1 local_3f [59];
  
  Q_memset(local_8c,0,0x88);
  iVar1 = Q_strlen(param_2);
  if ((iVar1 == 0x24) && (iVar1 = Q_strnicmp(param_2,&DAT_000ac616,4), iVar1 == 0)) {
    COM_HexConvert(param_2 + 4,0x20,local_3f);
    iVar1 = HPAK_GetDataPointer("custom.hpk",local_8c,0,0);
    if (iVar1 != 0) {
      return 1;
    }
  }
  MSG_WriteByte(param_1,9);
  uVar2 = MD5_Print(local_3f);
  uVar2 = va("upload \"!MD5%s\"\n",uVar2);
  MSG_WriteString(param_1,uVar2);
  *(undefined4 *)(host_client + 0x4e24) = 1;
  return 0;
}


// SV_CheckForRcon  @ 0007de40
void SV_CheckForRcon(void)

{
  int iVar1;
  
  if ((((sv == 0) && (cls == 0)) && (giActive != 3)) && (host_initialized != 0)) {
    while (iVar1 = NET_GetPacket(1), iVar1 != 0) {
      iVar1 = SV_FilterPacket();
      if (iVar1 == 0) {
        if (*DAT_00226fe4 == -1) {
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


// SV_CheckIPRestrictions  @ 00075e38
undefined4 SV_CheckIPRestrictions(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int aiStack_3c [4];
  undefined4 uStack_2c;
  int aiStack_28 [3];
  int *piStack_1c;
  char *pcStack_18;
  
  pcStack_18 = (char *)0x75e46;
  if (param_1 == (int *)0x0) {
    pcStack_18 = "SV_CheckIPRestrictions:  Null address\n";
    piStack_1c = (int *)0x75e5f;
    Sys_Error();
    uVar1 = 0;
  }
  else {
    if (((gfUseLANAuthentication != 0) ||
        ((byte)((float)sv_lan._12_4_ < 0.0 |
                (byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
       (*param_1 == 3)) {
      puVar3 = &net_local_adr;
      piVar4 = aiStack_28;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      piVar4 = param_1;
      piVar5 = aiStack_3c;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      iVar2 = NET_CompareClassBAdr();
      if (iVar2 == 0) {
        piVar4 = param_1;
        piVar5 = aiStack_28;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
        uStack_2c = 0x75ed6;
        iVar2 = NET_IsReservedAdr();
        if (iVar2 == 0) {
          pcStack_18 = "LAN servers are restricted to local clients (class C).\n";
          piStack_1c = param_1;
          aiStack_28[2] = 0x75eed;
          SV_RejectConnection();
          return 0;
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


// SV_CheckKeyInfo  @ 00076064
undefined4
SV_CheckKeyInfo(undefined4 param_1,undefined4 param_2,undefined2 *param_3,int *param_4,int *param_5,
               undefined4 param_6)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  uVar2 = Info_ValueForKey(param_2,&DAT_000ab0ca);
  iVar3 = Q_atoi(uVar2);
  if (iVar3 - 1U < 2) {
    uVar2 = Info_ValueForKey(param_2,"unique");
    iVar4 = Q_strlen(uVar2);
    if (iVar4 < 1) {
      return 0;
    }
    iVar4 = Q_atoi(uVar2);
    *param_5 = iVar4;
    if ((iVar4 == -1) || (iVar4 = SV_FilterUser(iVar4), iVar4 == 0)) {
      uVar2 = Info_ValueForKey(param_2,&DAT_000ab0eb);
      iVar4 = Q_strlen(uVar2);
      if ((0 < iVar4) && ((iVar3 != 2 || (iVar4 = Q_strlen(uVar2), iVar4 == 0x20)))) {
        Q_strcpy(param_6,uVar2);
        uVar1 = Q_atoi("27005");
        *param_3 = uVar1;
        *param_4 = iVar3;
        return 1;
      }
      pcVar5 = "Invalid authentication certificate length.\n";
    }
    else {
      pcVar5 = "You have been banned from this server.\n";
    }
  }
  else {
    pcVar5 = "Invalid connection.\n";
  }
  SV_RejectConnection(param_1,pcVar5);
  return 0;
}


// SV_CheckMovingGround  @ 00085398
void SV_CheckMovingGround(int param_1,float param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x224);
  if ((((uVar2 & 0x200) != 0) && (iVar1 = *(int *)(param_1 + 0x21c), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x224) & 4) != 0)) {
    if ((uVar2 & 0x400000) == 0) {
      VectorScale(iVar1 + 0xc4,*(undefined4 *)(iVar1 + 0x278),param_1 + 0xac);
    }
    else {
      VectorMA(param_1 + 0xac,*(undefined4 *)(iVar1 + 0x278),iVar1 + 0xc4,param_1 + 0xac);
    }
    uVar2 = *(uint *)(param_1 + 0x224) | 0x400000;
    *(uint *)(param_1 + 0x224) = uVar2;
  }
  if ((uVar2 & 0x400000) == 0) {
    VectorMA(param_1 + 0xa0,param_2 * 0.5 + 1.0,param_1 + 0xac,param_1 + 0xa0);
    uVar2 = *(uint *)(param_1 + 0x224);
    *(undefined4 *)(param_1 + 0xac) = 0;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  *(uint *)(param_1 + 0x224) = uVar2 & 0xffbfffff;
  return;
}


// SV_CheckProtocol  @ 00075c44
undefined4 SV_CheckProtocol(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    Sys_Error("SV_CheckProtocol:  Null address\n");
  }
  else {
    if (param_2 == 0x2a) {
      return 1;
    }
    if (param_2 < 0x2b) {
      SV_RejectConnection(param_1,
                          "This server is using a newer protocol ( %i ) than your client ( %i ).  You should check for updates to your client\n"
                          ,param_2,0x2a);
    }
    else {
      iVar1 = Q_strlen(sv_contact._4_4_);
      pcVar2 = (char *)sv_contact._4_4_;
      if (iVar1 < 1) {
        pcVar2 = "(no email address specified)";
      }
      SV_RejectConnection(param_1,
                          "This server is using an older protocol ( %i ) than your client ( %i ).  If you believe this server is outdated, you can contact the server administrator at %s\n"
                          ,0x2a,param_2,pcVar2);
    }
  }
  return 0;
}


// SV_CheckRate  @ 000784e0
void SV_CheckRate(int param_1)

{
  float fVar1;
  
  if ((0x3f < (byte)(((float)sv_maxrate._12_4_ < 0.0 |
                      (byte)((ushort)((ushort)NAN((float)sv_maxrate._12_4_) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)sv_maxrate._12_4_ == 0.0) << 0xe) >> 8)) - 1))
     && (fVar1 = (float)*(double *)(param_1 + 0x40),
        0x3f < (byte)((fVar1 < (float)sv_maxrate._12_4_ |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN((float)sv_maxrate._12_4_)) << 10)
                             >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == (float)sv_maxrate._12_4_) << 0xe) >> 8)) - 1
                     ))) {
    fVar1 = (float)sv_maxrate._12_4_;
    if (20000.0 < (float)sv_maxrate._12_4_) {
      fVar1 = 20000.0;
    }
    *(double *)(param_1 + 0x40) = (double)fVar1;
  }
  if ((0x3f < (byte)(((float)sv_minrate._12_4_ < 0.0 |
                      (byte)((ushort)((ushort)NAN((float)sv_minrate._12_4_) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)sv_minrate._12_4_ == 0.0) << 0xe) >> 8)) - 1))
     && ((float)*(double *)(param_1 + 0x40) < (float)sv_minrate._12_4_)) {
    fVar1 = (float)sv_minrate._12_4_;
    if (0x3f < (byte)((1000.0 < (float)sv_minrate._12_4_ |
                       (byte)((ushort)((ushort)NAN((float)sv_minrate._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)sv_minrate._12_4_ == 1000.0) << 0xe) >> 8)) -
                     1)) {
      fVar1 = 1000.0;
    }
    *(double *)(param_1 + 0x40) = (double)fVar1;
  }
  return;
}


// SV_CheckTimeouts  @ 00078abc
void SV_CheckTimeouts(void)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int *piVar4;
  int *local_14;
  int local_c;
  
  fVar2 = (float)realtime - (float)timeout._12_4_;
  local_c = 0;
  if (0 < DAT_001ab4e8) {
    local_14 = DAT_001ab4e4 + 0x130f;
    pfVar3 = (float *)(DAT_001ab4e4 + 0xe);
    piVar4 = DAT_001ab4e4;
    do {
      if ((pfVar3[0x90a] == 0.0) &&
         (((pfVar3[-0xb] != 0.0 || (*piVar4 != 0)) || (pfVar3[-0xd] != 0.0)))) {
        fVar1 = *pfVar3;
        if (0x3f < (byte)((fVar2 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
          SV_BroadcastPrintf("%s timed out\n",local_14);
          SV_DropClient(piVar4,0);
        }
      }
      local_c = local_c + 1;
      pfVar3 = pfVar3 + 0x1415;
      local_14 = local_14 + 0x1415;
      piVar4 = piVar4 + 0x1415;
    } while (local_c < DAT_001ab4e8);
  }
  return;
}


// SV_CheckUpdateRate  @ 0007580c
void SV_CheckUpdateRate(double *param_1)

{
  float fVar1;
  float fVar2;
  
  if (param_1 != (double *)0x0) {
    if ((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
              (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)param_1 = 0x9999999a;
      *(undefined4 *)((int)param_1 + 4) = 0x3fa99999;
    }
    else {
      if (((float)sv_maxupdaterate._12_4_ <= 0.001) &&
         ((byte)((float)sv_maxupdaterate._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)sv_maxupdaterate._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_maxupdaterate._12_4_ == 0.0) << 0xe) >> 8)) !=
          0x40)) {
        Cvar_Set("sv_maxupdaterate",&DAT_000aad76);
      }
      if (((float)sv_minupdaterate._12_4_ <= 0.001) &&
         ((byte)(0.0 < (float)sv_minupdaterate._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)sv_minupdaterate._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_minupdaterate._12_4_ == 0.0) << 0xe) >> 8)) !=
          0x40)) {
        Cvar_Set("sv_minupdaterate",&DAT_000aa643);
      }
      if ((byte)(0.0 < (float)sv_maxupdaterate._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)sv_maxupdaterate._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_maxupdaterate._12_4_ == 0.0) << 0xe) >> 8)) !=
          0x40) {
        fVar1 = 1.0 / (float)sv_maxupdaterate._12_4_;
        fVar2 = (float)*param_1;
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          *param_1 = (double)fVar1;
        }
      }
      if (((byte)(0.0 < (float)sv_minupdaterate._12_4_ |
                  (byte)((ushort)((ushort)NAN((float)sv_minupdaterate._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)sv_minupdaterate._12_4_ == 0.0) << 0xe) >> 8)) !=
           0x40) && (1.0 / (float)sv_minupdaterate._12_4_ < (float)*param_1)) {
        *param_1 = (double)(1.0 / (float)sv_minupdaterate._12_4_);
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("rate","/home/jihad/valve/goldsrc/engine/sv_main.c",0x7a0,"SV_CheckUpdateRate");
}


// SV_CheckUserInfo  @ 00076178
undefined4 SV_CheckUserInfo(undefined4 *param_1,char *param_2,undefined4 *param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  char *apcStack_24 [2];
  int iStack_1c;
  char *pcStack_18;
  char *pcStack_14;
  
  pcStack_14 = "spectator";
  pcStack_18 = param_2;
  iStack_1c = 0x7619d;
  pcVar1 = (char *)Info_ValueForKey();
  if (*pcVar1 != '\0') {
    pcStack_14 = "0";
    iStack_1c = 0x761b4;
    pcStack_18 = pcVar1;
    iVar2 = Q_strcmp();
    if (iVar2 != 0) {
      *param_3 = 1;
    }
  }
  *param_3 = 0;
  puVar4 = param_1;
  ppcVar5 = apcStack_24;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppcVar5 = (char *)*puVar4;
    puVar4 = puVar4 + 1;
    ppcVar5 = ppcVar5 + 1;
  }
  iVar2 = NET_IsLocalAddress();
  if ((iVar2 == 0) && (pcStack_18 = (char *)sv_password._4_4_, *(char *)sv_password._4_4_ != '\0'))
  {
    pcStack_14 = &DAT_000ab13c;
    iStack_1c = 0x761fe;
    iVar2 = Q_stricmp();
    if (iVar2 != 0) {
      pcStack_14 = "password";
      pcStack_18 = param_2;
      iStack_1c = 0x76215;
      iStack_1c = Info_ValueForKey();
      apcStack_24[1] = (char *)sv_password._4_4_;
      apcStack_24[0] = (char *)0x76225;
      iVar2 = Q_strcmp();
      if (iVar2 != 0) {
        puVar4 = param_1;
        ppcVar5 = apcStack_24;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *ppcVar5 = (char *)*puVar4;
          puVar4 = puVar4 + 1;
          ppcVar5 = ppcVar5 + 1;
        }
        uVar3 = NET_AdrToString();
        Con_Printf("%s:  password failed\n",uVar3);
        SV_RejectConnectionForPassword(param_1);
        return 0;
      }
    }
  }
  pcStack_14 = "password";
  pcStack_18 = param_2;
  iStack_1c = 0x7626c;
  Info_RemoveKey();
  pcStack_14 = (char *)0x20;
  pcStack_18 = (char *)0x0;
  iStack_1c = param_4;
  apcStack_24[1] = (char *)0x7627c;
  Q_memset();
  apcStack_24[1] = &DAT_000ab1a6;
  apcStack_24[0] = param_2;
  pcStack_18 = (char *)Info_ValueForKey();
  if (pcStack_18 == (char *)0x0) {
    pcStack_14 = "unnamed";
    pcStack_18 = (char *)param_4;
    iStack_1c = 0x762bc;
    Q_strcpy();
  }
  else {
    pcStack_14 = (char *)0x20;
    iStack_1c = param_4;
    apcStack_24[1] = (char *)0x762a1;
    Q_strncpy();
    *(undefined1 *)(param_4 + 0x1f) = 0;
  }
  return 1;
}


// SV_CheckVelocity  @ 0007fe30
void SV_CheckVelocity(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = param_1 + 0xa0;
  do {
    if ((*(uint *)(param_1 + 0xa0 + iVar5 * 4) & nanmask) == nanmask) {
      Con_Printf("Got a NaN velocity on %s\n",*(int *)(param_1 + 0x80) + pr_strings);
      *(undefined4 *)(iVar4 + iVar5 * 4) = 0;
    }
    iVar1 = iVar5 * 4;
    if ((*(uint *)(param_1 + 0x88 + iVar5 * 4) & nanmask) == nanmask) {
      Con_Printf("Got a NaN origin on %s\n",*(int *)(param_1 + 0x80) + pr_strings);
      *(undefined4 *)(iVar1 + 0x88 + param_1) = 0;
    }
    fVar2 = *(float *)(iVar1 + iVar4);
    if (fVar2 <= (float)sv_maxvelocity._12_4_) {
      fVar3 = -(float)sv_maxvelocity._12_4_;
      if (0x3f < (byte)((fVar3 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1)) {
        Con_DPrintf("Got a velocity too low on %s\n",*(int *)(param_1 + 0x80) + pr_strings);
        fVar2 = -(float)sv_maxvelocity._12_4_;
        goto LAB_0007ff69;
      }
    }
    else {
      Con_DPrintf("Got a velocity too high on %s\n",*(int *)(param_1 + 0x80) + pr_strings);
      fVar2 = (float)sv_maxvelocity._12_4_;
LAB_0007ff69:
      *(float *)(iVar1 + iVar4) = fVar2;
    }
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      return;
    }
  } while( true );
}


// SV_CheckVisibility  @ 00079e50
undefined4 SV_CheckVisibility(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_30;
  uint local_10;
  uint local_8;
  
  if (param_2 == 0) {
LAB_0007a0ac:
    uVar5 = 1;
  }
  else {
    if (*(int *)(param_1 + 0x10) < 0) {
      iVar7 = 0;
      uVar4 = *(uint *)(param_1 + 0x14);
      iVar6 = iVar7;
      if (0 < (int)uVar4) {
        iVar8 = param_1 + 0x18;
        uVar1 = uVar4 & 3;
        if (uVar1 == 0) goto LAB_00079ffc;
        if (1 < uVar1) {
          if (2 < uVar1) {
            local_10 = (uint)*(ushort *)(param_1 + 0x18);
            if ((*(byte *)(((short)*(ushort *)(param_1 + 0x18) >> 3) + param_2) >> (local_10 & 7) &
                1) != 0) goto LAB_0007a0a7;
            iVar7 = 1;
          }
          uVar3 = *(ushort *)(iVar8 + iVar7 * 2);
          iVar6 = iVar7;
          if ((*(byte *)(((short)uVar3 >> 3) + param_2) >> (uVar3 & 7) & 1) != 0) goto LAB_0007a0a7;
          iVar7 = iVar7 + 1;
        }
        uVar3 = *(ushort *)(iVar8 + iVar7 * 2);
        bVar2 = *(byte *)(((short)uVar3 >> 3) + param_2);
        while ((iVar6 = iVar7, (bVar2 >> (uVar3 & 7) & 1) == 0 &&
               (iVar7 = iVar7 + 1, iVar6 = iVar7, iVar7 < (int)uVar4))) {
LAB_00079ffc:
          uVar3 = *(ushort *)(iVar8 + iVar7 * 2);
          iVar6 = iVar7;
          if ((*(byte *)(((short)uVar3 >> 3) + param_2) >> (uVar3 & 7) & 1) != 0) break;
          iVar6 = iVar7 + 1;
          uVar3 = *(ushort *)(iVar8 + iVar6 * 2);
          local_30 = (uint)uVar3;
          if (((*(byte *)(((short)uVar3 >> 3) + param_2) >> (local_30 & 7) & 1) != 0) ||
             (iVar6 = iVar7 + 2, uVar3 = *(ushort *)(iVar8 + iVar6 * 2),
             (*(byte *)(((short)uVar3 >> 3) + param_2) >> (uVar3 & 7) & 1) != 0)) break;
          iVar7 = iVar7 + 3;
          uVar3 = *(ushort *)(iVar8 + iVar7 * 2);
          bVar2 = *(byte *)(((short)uVar3 >> 3) + param_2);
        }
      }
LAB_0007a0a7:
      if (iVar6 < (int)uVar4) goto LAB_0007a0ac;
    }
    else {
      iVar6 = 0;
      local_8 = (uint)*(short *)(param_1 + 0x18);
      if (local_8 != 0xffffffff) {
        do {
          if ((*(byte *)(((int)local_8 >> 3) + param_2) >> (local_8 & 7) & 1) != 0)
          goto LAB_0007a0ac;
          iVar6 = iVar6 + 1;
        } while ((iVar6 < 0x30) &&
                (local_8 = (uint)*(short *)(param_1 + 0x18 + iVar6 * 2), local_8 != 0xffffffff));
      }
      iVar6 = CM_HeadnodeVisible(*(int *)(DAT_00153668 + 0xa4) + *(int *)(param_1 + 0x10) * 0x28,
                                 param_2,&local_8);
      if (iVar6 != 0) {
        *(short *)(*(int *)(param_1 + 0x14) * 2 + 0x18 + param_1) = (short)local_8;
        *(int *)(param_1 + 0x14) = (*(int *)(param_1 + 0x14) + 1) % 0x30;
        return 2;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}


// SV_CheckWater  @ 00081f60
bool SV_CheckWater(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
  local_c = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
  local_8 = *(float *)(param_1 + 0x14c) + 1.0;
  *(undefined4 *)(param_1 + 0x240) = 0;
  *(undefined4 *)(param_1 + 0x244) = 0xffffffff;
  g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
  iVar3 = SV_PointContents(&local_10);
  if (0xb < iVar3 + 0xeU) goto LAB_00082100;
  *(int *)(param_1 + 0x244) = iVar3;
  *(undefined4 *)(param_1 + 0x240) = 1;
  fVar1 = *(float *)(param_1 + 0x14c);
  fVar2 = *(float *)(param_1 + 0x158);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
LAB_000820b1:
    *(undefined4 *)(param_1 + 0x240) = 3;
  }
  else {
    local_8 = (fVar2 + fVar1) * 0.5;
    g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
    iVar4 = SV_PointContents(&local_10);
    if (iVar4 + 0xeU < 0xc) {
      *(undefined4 *)(param_1 + 0x240) = 2;
      local_10 = local_10 + *(float *)(param_1 + 500);
      local_c = local_c + *(float *)(param_1 + 0x1f8);
      local_8 = local_8 + *(float *)(param_1 + 0x1fc);
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      iVar4 = SV_PointContents(&local_10);
      if (iVar4 + 0xeU < 0xc) goto LAB_000820b1;
    }
  }
  if (iVar3 + 0xeU < 6) {
    VectorMA(param_1 + 0xac,(float)*(int *)(param_1 + 0x240) * 50.0,
             &current_table_98 + (-9 - iVar3) * 0xc,param_1 + 0xac);
  }
LAB_00082100:
  return 1 < *(int *)(param_1 + 0x240);
}


// SV_CheckWaterTransition  @ 00082438
void SV_CheckWaterTransition(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
  local_c = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
  local_8 = *(float *)(param_1 + 0x14c) + 1.0;
  g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
  iVar3 = SV_PointContents(&local_10);
  iVar4 = *(int *)(param_1 + 0x244);
  if (iVar4 == 0) {
    *(int *)(param_1 + 0x244) = iVar3;
    *(undefined4 *)(param_1 + 0x240) = 1;
  }
  else if (iVar3 + 0xeU < 0xc) {
    if (iVar4 == -1) {
      SV_StartSound(0,param_1,0,"player/pl_wade1.wav",0xff,0x3f800000,0,100);
      *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xa8) * 0.5;
    }
    *(int *)(param_1 + 0x244) = iVar3;
    *(undefined4 *)(param_1 + 0x240) = 1;
    fVar1 = *(float *)(param_1 + 0x14c);
    fVar2 = *(float *)(param_1 + 0x158);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      local_8 = (fVar2 + fVar1) * 0.5;
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      iVar4 = SV_PointContents(&local_10);
      if (0xb < iVar4 + 0xeU) {
        return;
      }
      *(undefined4 *)(param_1 + 0x240) = 2;
      local_10 = local_10 + *(float *)(param_1 + 500);
      local_c = local_c + *(float *)(param_1 + 0x1f8);
      local_8 = local_8 + *(float *)(param_1 + 0x1fc);
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      iVar4 = SV_PointContents(&local_10);
      if (0xb < iVar4 + 0xeU) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x240) = 3;
  }
  else {
    if (iVar4 != -1) {
      SV_StartSound(0,param_1,0,"player/pl_wade2.wav",0xff,0x3f800000,0,100);
    }
    *(undefined4 *)(param_1 + 0x244) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x240) = 0;
  }
  return;
}


// SV_CleanupEnts  @ 0007a418
void SV_CleanupEnts(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 1;
  if (1 < DAT_00186f8c) {
    iVar4 = 0x324;
    do {
      iVar2 = iVar4 + DAT_00186f94;
      iVar4 = iVar4 + 0x324;
      pbVar1 = (byte *)(iVar2 + 0x198);
      *pbVar1 = *pbVar1 & 0xdd;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00186f8c);
  }
  return;
}


// SV_ClearCaches  @ 0007b404
void SV_ClearCaches(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_0018469c;
  iVar2 = 0x10;
  do {
    if (*piVar1 == 0) {
      return;
    }
    *piVar1 = 0;
    if (*(int *)(&DAT_00184694 + iVar2) != 0) {
      Mem_Free(*(int *)(&DAT_00184694 + iVar2));
    }
    piVar1 = piVar1 + 4;
    *(undefined4 *)(&DAT_00184694 + iVar2) = 0;
    iVar2 = iVar2 + 0x10;
  } while ((int)piVar1 < 0x18567d);
  return;
}


// SV_ClearClientStates  @ 000559bc
void SV_ClearClientStates(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_001ab4e4;
  if (0 < DAT_001ab4e8) {
    do {
      COM_ClearCustomizationList(iVar1 + 0x4ea8,0);
      SV_ClearResourceLists(iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x5054;
    } while (iVar2 < DAT_001ab4e8);
  }
  return;
}


// SV_ClearEntities  @ 0007c5e4
void SV_ClearEntities(void)

{
  int iVar1;
  int iVar2;
  
  if (0 < DAT_00186f8c) {
    iVar2 = 0;
    iVar1 = 0;
    do {
      if (*(int *)(iVar2 + DAT_00186f94) == 0) {
        ReleaseEntityDLLFields((int *)(iVar2 + DAT_00186f94));
      }
      iVar2 = iVar2 + 0x324;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00186f8c);
  }
  return;
}


// SV_ClearFrames  @ 00072cd4
void SV_ClearFrames(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = 0;
    if (0 < SV_UPDATE_BACKUP) {
      do {
        SV_ClearPacketEntities(puVar1);
        iVar2 = iVar2 + 1;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0xbf800000;
        puVar1 = puVar1 + 0x344;
      } while (iVar2 < SV_UPDATE_BACKUP);
    }
    Mem_Free(*param_1);
    *param_1 = 0;
  }
  return;
}


// SV_ClearPacketEntities  @ 00072c28
void SV_ClearPacketEntities(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xd0c) != 0) {
      Mem_Free(*(int *)(param_1 + 0xd0c));
    }
    *(undefined4 *)(param_1 + 0xd0c) = 0;
    *(undefined4 *)(param_1 + 0xce8) = 0;
  }
  return;
}


// SV_ClearResourceList  @ 00083b28
void SV_ClearResourceList(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x80);
  while ((iVar2 != 0 && (iVar2 != param_1))) {
    iVar1 = *(int *)(iVar2 + 0x80);
    SV_RemoveFromResourceList(iVar2);
    Mem_Free(iVar2);
    iVar2 = iVar1;
  }
  *(int *)(param_1 + 0x84) = param_1;
  *(int *)(param_1 + 0x80) = param_1;
  return;
}


// SV_ClearResourceLists  @ 00083700
void SV_ClearResourceLists(int param_1)

{
  if (param_1 == 0) {
    Sys_Error("SV_ClearResourceLists with NULL client!");
  }
  SV_ClearResourceList(param_1 + 0x4d0c);
  SV_ClearResourceList(param_1 + 0x4c84);
  return;
}


// SV_ClearWorld  @ 0008b7fc
void SV_ClearWorld(void)

{
  SV_InitBoxHull();
  Q_memset(&sv_areanodes,0,0x400);
  sv_numareanodes = 0;
  SV_CreateAreaNode(0,DAT_00153668 + 0x54,DAT_00153668 + 0x60);
  return;
}


// SV_ClientPrintf  @ 0005532c
void SV_ClientPrintf(char *param_1)

{
  char local_404 [1024];
  
  if (*(int *)(host_client + 0x2460) == 0) {
    vsprintf(local_404,param_1,&stack0x00000008);
    MSG_WriteByte(host_client + 0x74,8);
    MSG_WriteString(host_client + 0x74,local_404);
  }
  return;
}


// SV_ClipMoveToEntity  @ 0008cb30
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


// SV_ClipToLinks  @ 0008cb84
void SV_ClipToLinks(int *param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  float *pfVar12;
  float *pfVar13;
  int aiStack_94 [2];
  float afStack_8c [5];
  float local_3c;
  int local_38;
  float local_2c;
  int *local_c;
  undefined1 *puVar11;
  
  piVar4 = (int *)param_1[7];
  puVar8 = &stack0xffffff88;
joined_r0x0008cba7:
  while( true ) {
    piVar7 = piVar4;
    if (piVar7 == param_1 + 6) {
      iVar9 = *param_1;
      if (iVar9 != -1) {
        fVar2 = (float)param_1[1];
        if (fVar2 < param_2[iVar9 + 3]) {
          *(float **)(puVar8 + -4) = param_2;
          *(int *)(puVar8 + -8) = param_1[2];
          *(undefined4 *)(puVar8 + -0xc) = 0x8ce72;
          SV_ClipToLinks();
          iVar9 = *param_1;
          fVar2 = (float)param_1[1];
        }
        fVar3 = param_2[iVar9];
        if (0x3f < (byte)((fVar2 < fVar3 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
          *(float **)(puVar8 + -4) = param_2;
          *(int *)(puVar8 + -8) = param_1[3];
          *(undefined4 *)(puVar8 + -0xc) = 0x8ce9f;
          SV_ClipToLinks();
        }
      }
      return;
    }
    piVar4 = (int *)piVar7[1];
    piVar1 = piVar7 + -2;
    uVar5 = piVar7[0xae];
    if (((uVar5 == 0) || (param_2[0x1f] == 0.0)) ||
       (uVar6 = *(uint *)((int)param_2[0x1f] + 0x2c0), uVar6 == 0)) break;
    if (g_groupop != 0) goto LAB_0008cbf4;
    if ((uVar5 & uVar6) != 0) break;
  }
  goto LAB_0008cc02;
LAB_0008cbf4:
  if ((g_groupop != 1) || ((uVar5 & uVar6) == 0)) {
LAB_0008cc02:
    iVar9 = piVar7[0x61];
    if ((iVar9 != 0) && (piVar1 != (int *)param_2[0x1f])) {
      if (iVar9 == 1) {
        *(char **)(puVar8 + -4) = "Trigger in clipping list";
        *(undefined4 *)(puVar8 + -8) = 0x8cc2d;
        Sys_Error();
        iVar9 = piVar7[0x61];
      }
      if (iVar9 == 4) {
        if (((*(byte *)((int)piVar7 + 0x21e) & 0x80) != 0) && (param_2[0x20] == 0.0))
        goto joined_r0x0008cba7;
      }
      else if ((*(short *)(param_2 + 0x1e) == 1) && (piVar7[0x60] != 0xd)) goto joined_r0x0008cba7;
      if (((*(short *)((int)param_2 + 0x7a) == 0) || (piVar7[0x70] == 0)) ||
         ((*(byte *)((int)piVar7 + 0x21f) & 2) != 0)) {
        fVar2 = (float)piVar7[0x52];
        fVar3 = *param_2;
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) {
          fVar2 = (float)piVar7[0x53];
          fVar3 = param_2[1];
          if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) {
            fVar2 = (float)piVar7[0x54];
            fVar3 = param_2[2];
            if (((((byte)(fVar2 < fVar3 |
                          (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) &&
                 ((float)piVar7[0x4f] <= param_2[3])) &&
                (((float)piVar7[0x50] <= param_2[4] && ((float)piVar7[0x51] <= param_2[5])))) &&
               (((fVar2 = param_2[0x1f], fVar2 == 0.0 ||
                 (fVar3 = *(float *)((int)fVar2 + 0x174),
                 (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40)) ||
                (fVar3 = (float)piVar7[0x5b],
                (byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 0x40)))) {
              if (param_2[0x10] != 0.0) {
                return;
              }
              if ((fVar2 == 0.0) ||
                 (((float)piVar7[0x84] != fVar2 && (*(int **)((int)fVar2 + 0x218) != piVar1)))) {
                if ((*(byte *)(piVar7 + 0x87) & 0x20) == 0) {
                  *(float *)(puVar8 + -4) = param_2[0xf];
                  *(float *)(puVar8 + -8) = param_2[7];
                  *(float *)(puVar8 + -0xc) = param_2[6];
                  *(float *)(puVar8 + -0x10) = param_2[0xe];
                  *(int **)(puVar8 + -0x14) = piVar1;
                  *(float **)(puVar8 + -0x18) = &local_3c;
                }
                else {
                  *(float *)(puVar8 + -4) = param_2[0xf];
                  *(float **)(puVar8 + -8) = param_2 + 0xb;
                  *(float **)(puVar8 + -0xc) = param_2 + 8;
                  *(float *)(puVar8 + -0x10) = param_2[0xe];
                  *(int **)(puVar8 + -0x14) = piVar1;
                  *(float **)(puVar8 + -0x18) = &local_3c;
                }
                *(undefined4 *)(puVar8 + -0x1c) = 0x8cdde;
                SV_ClipMoveToEntity();
                puVar10 = puVar8 + -4;
                puVar11 = puVar8 + -4;
                if (((local_3c != 0.0) || (local_38 != 0)) ||
                   (fVar2 = param_2[0x14], puVar8 = puVar8 + -4,
                   0x3f < (byte)((fVar2 < local_2c |
                                  (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_2c)) << 10) >> 8)
                                 | (byte)((ushort)((ushort)(fVar2 == local_2c) << 0xe) >> 8)) - 1)))
                {
                  local_c = piVar1;
                  if (param_2[0x11] == 0.0) {
                    pfVar12 = &local_3c;
                    pfVar13 = param_2 + 0x10;
                    for (iVar9 = 0xe; puVar8 = puVar11, iVar9 != 0; iVar9 = iVar9 + -1) {
                      *pfVar13 = *pfVar12;
                      pfVar12 = pfVar12 + 1;
                      pfVar13 = pfVar13 + 1;
                    }
                  }
                  else {
                    pfVar12 = &local_3c;
                    pfVar13 = param_2 + 0x10;
                    for (iVar9 = 0xe; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *pfVar13 = *pfVar12;
                      pfVar12 = pfVar12 + 1;
                      pfVar13 = pfVar13 + 1;
                    }
                    param_2[0x11] = 1.4013e-45;
                    puVar8 = puVar10;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  goto joined_r0x0008cba7;
}


// SV_ClipToWorldbrush  @ 0008ceac
void SV_ClipToWorldbrush(int *param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  float *pfVar10;
  float *pfVar11;
  int aiStack_88 [2];
  float afStack_80 [5];
  float local_3c;
  int local_38;
  float local_2c;
  int *local_c;
  undefined1 *puVar9;
  
  piVar4 = (int *)param_1[7];
  puVar6 = &stack0xffffff94;
  while( true ) {
    do {
      do {
        do {
          do {
            piVar5 = piVar4;
            if (piVar5 == param_1 + 6) {
              iVar7 = *param_1;
              if (iVar7 != -1) {
                fVar2 = (float)param_1[1];
                if (fVar2 < param_2[iVar7 + 3]) {
                  *(float **)(puVar6 + -4) = param_2;
                  *(int *)(puVar6 + -8) = param_1[2];
                  *(undefined4 *)(puVar6 + -0xc) = 0x8d062;
                  SV_ClipToWorldbrush();
                  iVar7 = *param_1;
                  fVar2 = (float)param_1[1];
                }
                fVar3 = param_2[iVar7];
                if (0x3f < (byte)((fVar2 < fVar3 |
                                   (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
                  *(float **)(puVar6 + -4) = param_2;
                  *(int *)(puVar6 + -8) = param_1[3];
                  *(undefined4 *)(puVar6 + -0xc) = 0x8d08f;
                  SV_ClipToWorldbrush();
                }
              }
              return;
            }
            piVar4 = (int *)piVar5[1];
            piVar1 = piVar5 + -2;
          } while (((piVar5[0x61] != 4) || (piVar1 == (int *)param_2[0x1f])) ||
                  ((*(byte *)((int)piVar5 + 0x21f) & 2) == 0));
          fVar2 = (float)piVar5[0x52];
          fVar3 = *param_2;
        } while ((byte)(fVar2 < fVar3 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1);
        fVar2 = (float)piVar5[0x53];
        fVar3 = param_2[1];
      } while ((byte)(fVar2 < fVar3 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1);
      fVar2 = (float)piVar5[0x54];
      fVar3 = param_2[2];
    } while ((((byte)(fVar2 < fVar3 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) ||
             (param_2[3] < (float)piVar5[0x4f])) ||
            ((param_2[4] < (float)piVar5[0x50] || (param_2[5] < (float)piVar5[0x51]))));
    if (param_2[0x10] != 0.0) break;
    *(float *)(puVar6 + -4) = param_2[0xf];
    *(float *)(puVar6 + -8) = param_2[7];
    *(float *)(puVar6 + -0xc) = param_2[6];
    *(float *)(puVar6 + -0x10) = param_2[0xe];
    *(int **)(puVar6 + -0x14) = piVar1;
    *(float **)(puVar6 + -0x18) = &local_3c;
    *(undefined4 *)(puVar6 + -0x1c) = 0x8cfcc;
    SV_ClipMoveToEntity();
    puVar8 = puVar6 + -4;
    puVar9 = puVar6 + -4;
    if (((local_3c != 0.0) || (local_38 != 0)) ||
       (fVar2 = param_2[0x14], puVar6 = puVar6 + -4,
       0x3f < (byte)((fVar2 < local_2c |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_2c)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == local_2c) << 0xe) >> 8)) - 1))) {
      local_c = piVar1;
      if (param_2[0x11] == 0.0) {
        pfVar10 = &local_3c;
        pfVar11 = param_2 + 0x10;
        for (iVar7 = 0xe; puVar6 = puVar9, iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar11 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          pfVar11 = pfVar11 + 1;
        }
      }
      else {
        pfVar10 = &local_3c;
        pfVar11 = param_2 + 0x10;
        for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar11 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          pfVar11 = pfVar11 + 1;
        }
        param_2[0x11] = 1.4013e-45;
        puVar6 = puVar8;
      }
    }
  }
  return;
}


// SV_CloseEnough  @ 0007f64c
undefined4 SV_CloseEnough(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar2 = *(float *)(param_1 + 0x150) + param_3;
  fVar1 = *(float *)(param_2 + 0x144);
  if (((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) &&
     (*(float *)(param_1 + 0x144) - param_3 <= *(float *)(param_2 + 0x150))) {
    fVar2 = *(float *)(param_1 + 0x154) + param_3;
    fVar1 = *(float *)(param_2 + 0x148);
    if (((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) &&
       (*(float *)(param_1 + 0x148) - param_3 <= *(float *)(param_2 + 0x154))) {
      fVar2 = *(float *)(param_1 + 0x158) + param_3;
      fVar1 = *(float *)(param_2 + 0x14c);
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) {
        param_3 = *(float *)(param_1 + 0x14c) - param_3;
        fVar1 = *(float *)(param_2 + 0x158);
        if ((byte)((param_3 < fVar1 |
                    (byte)((ushort)((ushort)(NAN(param_3) || NAN(fVar1)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
          return 1;
        }
      }
    }
  }
  return 0;
}


// SV_ComputeLatency  @ 00086b7c
void SV_ComputeLatency(int param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)SV_CalcClientTime(param_1);
  *(float *)(param_1 + 0x24b0) = (float)lVar1;
  return;
}


// SV_ConnectClient  @ 000763d0
void SV_ConnectClient(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int **ppiVar7;
  code **ppcVar8;
  int *apiStack_aa0 [2];
  code *pcStack_a98;
  char *pcStack_a94;
  code *pcStack_a90;
  int *piStack_a8c;
  code *apcStack_a88 [2];
  int *piStack_a80;
  code *pcStack_a7c;
  int **ppiStack_a78;
  int local_a50;
  int *local_a4c;
  int local_a48;
  undefined2 local_a42;
  int local_a40;
  int local_a3c;
  undefined1 local_a38 [512];
  undefined1 local_838 [32];
  undefined1 local_818 [1024];
  undefined1 local_418 [1024];
  undefined4 local_18 [5];
  
  local_a4c = (int *)0x0;
  local_a48 = 0;
  local_a40 = -1;
  local_a3c = -1;
  bVar1 = false;
  ppiStack_a78 = (int **)0xab12c;
  puVar4 = &net_from;
  puVar6 = local_18;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  pcStack_a7c = (code *)0x7643c;
  local_a42 = Q_atoi();
  pcStack_a7c = (code *)0x76448;
  iVar3 = Cmd_Argc();
  if (iVar3 < 5) {
    ppiStack_a78 = (int **)0xab1fc;
    piStack_a80 = (int *)0x76463;
    pcStack_a7c = (code *)local_18;
    SV_RejectConnection();
  }
  else {
    ppiStack_a78 = (int **)0x1;
    pcStack_a7c = (code *)0x764a7;
    pcStack_a7c = (code *)Cmd_Argv();
    piStack_a80 = (int *)0x764ad;
    piStack_a80 = (int *)Q_atoi();
    apcStack_a88[0] = (code *)0x764ba;
    apcStack_a88[1] = (code *)local_18;
    iVar3 = SV_CheckProtocol();
    if (iVar3 != 0) {
      ppiStack_a78 = (int **)0x2;
      pcStack_a7c = (code *)0x764cc;
      pcStack_a7c = (code *)Cmd_Argv();
      piStack_a80 = (int *)0x764d2;
      piStack_a80 = (int *)Q_atoi();
      apcStack_a88[0] = (code *)0x764df;
      apcStack_a88[1] = (code *)local_18;
      iVar3 = SV_CheckChallenge();
      if (iVar3 != 0) {
        pcStack_a7c = (code *)0x764f6;
        ppiStack_a78 = (int **)local_18;
        iVar3 = SV_CheckIPRestrictions();
        if (iVar3 != 0) {
          local_a50 = 0;
          local_a4c = DAT_001ab4e4;
          if (0 < DAT_001ab4e8) {
LAB_00076528:
            if (((*local_a4c == 0) && (local_a4c[1] == 0)) && (local_a4c[3] == 0))
            goto LAB_00076572;
            piVar5 = local_a4c + 9;
            ppcVar8 = apcStack_a88;
            for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
              *ppcVar8 = (code *)*piVar5;
              piVar5 = piVar5 + 1;
              ppcVar8 = ppcVar8 + 1;
            }
            puVar4 = local_18;
            ppiVar7 = apiStack_aa0 + 1;
            for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
              *ppiVar7 = (int *)*puVar4;
              puVar4 = puVar4 + 1;
              ppiVar7 = ppiVar7 + 1;
            }
            apiStack_aa0[0] = (int *)0x76567;
            iVar3 = NET_CompareAdr();
            if (iVar3 == 0) goto LAB_00076572;
            puVar4 = local_18;
            ppcVar8 = apcStack_a88;
            for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
              *ppcVar8 = (code *)*puVar4;
              puVar4 = puVar4 + 1;
              ppcVar8 = ppcVar8 + 1;
            }
            piStack_a8c = (int *)0x76480;
            piStack_a8c = (int *)NET_AdrToString();
            pcStack_a90 = (code *)0xab21a;
            pcStack_a94 = (char *)0x7648d;
            Con_Printf();
            bVar1 = true;
          }
LAB_00076594:
          ppiStack_a78 = (int **)0x200;
          pcStack_a7c = (code *)0x0;
          apcStack_a88[1] = (code *)0x765ad;
          piStack_a80 = (int *)local_a38;
          Q_memset();
          apcStack_a88[1] = (code *)0x3;
          apcStack_a88[0] = (code *)0x765b4;
          piStack_a8c = (int *)Cmd_Argv();
          apcStack_a88[0] = (code *)0x3ff;
          pcStack_a94 = (char *)0x765c6;
          pcStack_a90 = (code *)local_818;
          Q_strncpy();
          pcStack_a98 = (code *)&local_a3c;
          apiStack_aa0[1] = &local_a40;
          apiStack_aa0[0] = (int *)&local_a42;
          pcStack_a94 = local_a38;
          iVar3 = SV_CheckKeyInfo(local_18,local_818);
          if (iVar3 != 0) {
            ppiStack_a78 = (int **)0x4;
            pcStack_a7c = (code *)0x76601;
            piStack_a80 = (int *)Cmd_Argv();
            pcStack_a7c = (code *)0x3ff;
            apcStack_a88[0] = (code *)0x76619;
            apcStack_a88[1] = (code *)local_418;
            Q_strncpy();
            piStack_a8c = &local_a48;
            pcStack_a98 = (code *)0x76640;
            pcStack_a94 = (char *)local_18;
            pcStack_a90 = (code *)local_418;
            apcStack_a88[0] = (code *)local_838;
            iVar3 = SV_CheckUserInfo();
            if (iVar3 != 0) {
              if (!bVar1) {
                ppiStack_a78 = &local_a4c;
                pcStack_a7c = (code *)&local_a50;
                piStack_a80 = (int *)local_a48;
                apcStack_a88[0] = (code *)0x76675;
                apcStack_a88[1] = (code *)local_18;
                iVar3 = SV_FindEmptySlot();
                if (iVar3 == 0) {
                  return;
                }
              }
              pcStack_a7c = (code *)local_a3c;
              piStack_a80 = (int *)local_a40;
              apcStack_a88[0] = (code *)0x766a1;
              apcStack_a88[1] = (code *)local_18;
              ppiStack_a78 = (int **)local_a38;
              iVar3 = SV_FinishCertificateCheck();
              if (iVar3 != 0) {
                host_client = local_a4c;
                ppiStack_a78 = (int **)local_a4c;
                pcStack_a7c = (code *)0x766c0;
                SV_ClearResourceLists();
                pcStack_a7c = (code *)(host_client + 0xd38);
                piStack_a80 = (int *)0x766d3;
                SV_ClearFrames();
                piStack_a80 = (int *)(SV_UPDATE_BACKUP * 0xd10);
                apcStack_a88[1] = (code *)0x766ef;
                iVar3 = Mem_ZeroMalloc();
                host_client[0xd38] = iVar3;
                piVar2 = host_client;
                piVar5 = host_client + 0x1343;
                host_client[0x1364] = (int)piVar5;
                piVar2[0x1363] = (int)piVar5;
                piVar2 = host_client;
                piVar5 = host_client + 0x1321;
                host_client[0x1342] = (int)piVar5;
                piVar2[0x1341] = (int)piVar5;
                apcStack_a88[1] = (code *)(local_a50 + 1);
                apcStack_a88[0] = (code *)0x76740;
                iVar3 = EDICT_NUM();
                host_client[0x12b9] = iVar3;
                apcStack_a88[0] = SV_GetFragmentSize;
                piStack_a8c = local_a4c;
                puVar4 = local_18;
                ppiVar7 = apiStack_aa0;
                for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
                  *ppiVar7 = (int *)*puVar4;
                  puVar4 = puVar4 + 1;
                  ppiVar7 = ppiVar7 + 1;
                }
                Netchan_Setup(1,host_client + 8);
                ppiStack_a78 = (int **)0x42;
                pcStack_a7c = (code *)0xab228;
                puVar4 = local_18;
                ppiVar7 = apiStack_aa0 + 4;
                for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
                  *ppiVar7 = (int *)*puVar4;
                  puVar4 = puVar4 + 1;
                  ppiVar7 = ppiVar7 + 1;
                }
                pcStack_a94 = (char *)0x1;
                pcStack_a98 = (code *)0x767aa;
                Netchan_OutOfBandPrint();
                piVar5 = host_client;
                host_client[0xd34] = -0x66666666;
                piVar5[0xd35] = 0x3fa99999;
                *(double *)(host_client + 0xd32) = realtime + *(double *)(host_client + 0xd34);
                host_client[0x915] = -1;
                piVar5 = host_client;
                host_client[0x928] = 0;
                piVar5[0x929] = 0x40490000;
                ppiStack_a78 = (int **)0x34;
                pcStack_a7c = (code *)0x0;
                piStack_a80 = host_client + 0x91b;
                apcStack_a88[1] = (code *)0x7682a;
                Q_memset();
                piVar5 = host_client;
                host_client[0x930] = 0;
                piVar5[0x931] = -0x40100000;
                if (host_client[9] == 1) {
                  ppiStack_a78 = (int **)0xab23b;
                  pcStack_a7c = (code *)0x76863;
                  Con_DPrintf();
                }
                else {
                  piVar5 = host_client + 9;
                  ppcVar8 = apcStack_a88;
                  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *ppcVar8 = (code *)*piVar5;
                    piVar5 = piVar5 + 1;
                    ppcVar8 = ppcVar8 + 1;
                  }
                  piStack_a8c = (int *)0x7687d;
                  piStack_a8c = (int *)NET_AdrToString();
                  pcStack_a94 = "Client";
                  if (local_a48 != 0) {
                    pcStack_a94 = "Spectator";
                  }
                  pcStack_a98 = (code *)0xab25f;
                  apiStack_aa0[1] = (int *)0x768a7;
                  pcStack_a90 = (code *)local_838;
                  Con_DPrintf();
                }
                if (local_a40 == 2) {
                  ppiStack_a78 = (int **)0x20;
                  piStack_a80 = host_client + 0x12ff;
                  apcStack_a88[1] = (code *)0x768cf;
                  pcStack_a7c = (code *)local_a38;
                  Q_strncpy();
                  *(undefined1 *)(host_client + 0x1307) = 0;
                }
                *host_client = 0;
                host_client[1] = 0;
                host_client[3] = 1;
                host_client[4] = 0;
                host_client[2] = 0;
                host_client[0x12bb] = g_userid;
                g_userid = g_userid + 1;
                host_client[0x12bc] = local_a3c;
                piVar5 = host_client + 9;
                ppcVar8 = apcStack_a88;
                for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
                  *ppcVar8 = (code *)*piVar5;
                  piVar5 = piVar5 + 1;
                  ppcVar8 = ppcVar8 + 1;
                }
                piStack_a8c = (int *)0x76980;
                piStack_a8c = (int *)NET_AdrToString();
                pcStack_a90 = (code *)host_client[0x12bc];
                pcStack_a94 = (char *)host_client[0x12bb];
                apiStack_aa0[1] = (int *)0xab280;
                apiStack_aa0[0] = (int *)0x769ac;
                pcStack_a98 = (code *)local_838;
                Log_Printf();
                ppiStack_a78 = (int **)0x100;
                piStack_a80 = host_client + 0x12bd;
                apcStack_a88[1] = (code *)0x769ce;
                pcStack_a7c = (code *)local_418;
                Q_strncpy();
                apcStack_a88[1] = (code *)host_client;
                apcStack_a88[0] = (code *)0x769dc;
                SV_ExtractFromUserinfo();
                host_client[0x917] = local_a48;
                if (local_a48 != 0) {
                  *(byte *)(host_client[0x12b9] + 0x227) =
                       *(byte *)(host_client[0x12b9] + 0x227) | 4;
                }
                *(undefined2 *)(host_client + 0x944) = 1;
                host_client[0x945] = (int)(host_client + 0x948);
                host_client[0x946] = 4000;
                host_client[0x12fe] = 0;
              }
            }
          }
        }
      }
    }
  }
  return;
LAB_00076572:
  local_a50 = local_a50 + 1;
  local_a4c = local_a4c + 0x1415;
  if (DAT_001ab4e8 <= local_a50) goto LAB_00076594;
  goto LAB_00076528;
}


// SV_ConnectionlessPacket  @ 000781d8
void SV_ConnectionlessPacket(void)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  byte **ppbVar6;
  undefined4 *puVar7;
  byte **ppbVar8;
  byte *apbStack_2c [6];
  
  apbStack_2c[5] = (byte *)0x781f2;
  MSG_BeginReading();
  apbStack_2c[5] = (byte *)0x781f7;
  MSG_ReadLong();
  apbStack_2c[5] = (byte *)0x781fc;
  pcVar2 = (char *)MSG_ReadStringLine();
  apbStack_2c[4] = (byte *)0x78204;
  apbStack_2c[5] = (byte *)pcVar2;
  Cmd_TokenizeString();
  apbStack_2c[4] = (byte *)0x0;
  apbStack_2c[3] = (byte *)0x7820b;
  pbVar3 = (byte *)Cmd_Argv();
  apbStack_2c[3] = &DAT_000ab4a8;
  apbStack_2c[1] = (byte *)0x7821a;
  apbStack_2c[2] = pbVar3;
  iVar4 = Q_strcmp();
  if ((iVar4 == 0) || ((bVar1 = *pbVar3, bVar1 == 0x69 && ((pbVar3[1] == 0 || (pbVar3[1] == 10))))))
  {
    apbStack_2c[5] = (byte *)0x7823b;
    SVC_Ping();
    return;
  }
  if ((bVar1 == 0x6c) && ((pbVar3[1] == 0 || (pbVar3[1] == 10)))) {
    apbStack_2c[5] = (byte *)0x78259;
    MSG_BeginReading();
    apbStack_2c[5] = (byte *)0x7825e;
    MSG_ReadLong();
    apbStack_2c[5] = (byte *)0x78263;
    MSG_ReadByte();
    apbStack_2c[5] = (byte *)0x78268;
    apbStack_2c[5] = (byte *)MSG_ReadString();
    apbStack_2c[4] = (byte *)0x78270;
    Con_DPrintf();
    return;
  }
  if ((bVar1 == 0x6a) && ((pbVar3[1] == 0 || (pbVar3[1] == 10)))) {
    puVar7 = &net_from;
    ppbVar8 = apbStack_2c + 1;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppbVar8 = (byte *)*puVar7;
      puVar7 = puVar7 + 1;
      ppbVar8 = ppbVar8 + 1;
    }
    apbStack_2c[0] = (byte *)0x782a3;
    apbStack_2c[0] = (byte *)NET_AdrToString();
    ppbVar6 = apbStack_2c;
    pcVar2 = "A2A_ACK from %s\n";
  }
  else {
    if ((bVar1 == 0x73) && ((pbVar3[1] == 0 || (pbVar3[1] == 10)))) {
      apbStack_2c[5] = (byte *)0x782c6;
      SVC_Heartbeat();
      return;
    }
    apbStack_2c[5] = &DAT_000ab4be;
    apbStack_2c[3] = (undefined *)0x782d9;
    apbStack_2c[4] = pbVar3;
    iVar4 = Q_stricmp();
    if (iVar4 != 0) {
      apbStack_2c[5] = (byte *)(uint)*pbVar3;
      apbStack_2c[4] = (byte *)0x78356;
      iVar4 = WON_IsAuthMessage();
      if (iVar4 != 0) {
        apbStack_2c[5] = (byte *)(uint)*pbVar3;
        apbStack_2c[4] = (byte *)0x78367;
        WON_ParseAuthenticationMessage();
        return;
      }
      apbStack_2c[5] = (byte *)0xab4cb;
      apbStack_2c[3] = (byte *)0x78379;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_strcmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x78385;
        SVC_Status();
        return;
      }
      apbStack_2c[5] = (byte *)0xab4d2;
      apbStack_2c[3] = (byte *)0x78399;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_strcmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x783a5;
        SVC_GetChallenge();
        return;
      }
      apbStack_2c[5] = &DAT_000ab4df;
      apbStack_2c[3] = (byte *)0x783b9;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_stricmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x0;
        apbStack_2c[4] = (byte *)0x783c7;
        SVC_Info();
        return;
      }
      apbStack_2c[5] = (byte *)0xab4e4;
      apbStack_2c[3] = (byte *)0x783d9;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_stricmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x1;
        apbStack_2c[4] = (byte *)0x783e7;
        SVC_Info();
        return;
      }
      apbStack_2c[5] = (byte *)0xab4ec;
      apbStack_2c[3] = (byte *)0x783f9;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_stricmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x78405;
        SVC_PlayerInfo();
        return;
      }
      apbStack_2c[5] = (byte *)0xab4f4;
      apbStack_2c[3] = (byte *)0x78419;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_stricmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x78425;
        SVC_RuleInfo();
        return;
      }
      apbStack_2c[5] = (byte *)0xab4fa;
      apbStack_2c[3] = (byte *)0x78439;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_strcmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x78445;
        SV_ConnectClient();
        return;
      }
      apbStack_2c[5] = &DAT_000ab433;
      apbStack_2c[3] = (byte *)0x78459;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_strcmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)&net_from;
        apbStack_2c[4] = (byte *)0x7846c;
        SV_Rcon();
        return;
      }
      apbStack_2c[5] = (byte *)0xab33f;
      apbStack_2c[3] = (byte *)0x7847d;
      apbStack_2c[4] = pbVar3;
      iVar4 = Q_stricmp();
      if (iVar4 == 0) {
        apbStack_2c[5] = (byte *)0x78489;
        MSG_ReadByte();
        apbStack_2c[5] = (byte *)0x7848e;
        uVar5 = MSG_ReadLong();
        apbStack_2c[5] = (byte *)0x78495;
        apbStack_2c[5] = (byte *)MSG_ReadLong();
        apbStack_2c[3] = (byte *)0x7849c;
        apbStack_2c[4] = (byte *)uVar5;
        SVC_Friends();
        return;
      }
      apbStack_2c[4] = (byte *)0x784a6;
      apbStack_2c[5] = (byte *)pcVar2;
      iVar4 = SVC_GameDllQuery();
      if (iVar4 != 0) {
        return;
      }
      puVar7 = &net_from;
      ppbVar8 = apbStack_2c;
      apbStack_2c[5] = (byte *)pcVar2;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppbVar8 = (byte *)*puVar7;
        puVar7 = puVar7 + 1;
        ppbVar8 = ppbVar8 + 1;
      }
      apbStack_2c[4] = (byte *)NET_AdrToString();
      apbStack_2c[3] = (byte *)0xab520;
      apbStack_2c[2] = (byte *)0x784d6;
      Con_DPrintf();
      return;
    }
    if ((byte)((float)sv_logrelay._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)sv_logrelay._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_logrelay._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      return;
    }
    if (pcVar2 == (char *)0x0) {
      return;
    }
    apbStack_2c[4] = (byte *)0x78309;
    apbStack_2c[5] = (byte *)pcVar2;
    iVar4 = Q_strlen();
    if (iVar4 < 5) {
      return;
    }
    apbStack_2c[5] = &DAT_000ab4c2;
    apbStack_2c[4] = (byte *)0x78321;
    iVar4 = Q_strlen();
    apbStack_2c[5] = (byte *)(pcVar2 + iVar4);
    if (apbStack_2c[5] == (byte *)0x0) {
      return;
    }
    if (*apbStack_2c[5] == '\0') {
      return;
    }
    ppbVar6 = apbStack_2c + 5;
    pcVar2 = "%s\n";
  }
  *(char **)((int)ppbVar6 + -4) = pcVar2;
  *(undefined4 *)((int)ppbVar6 + -8) = 0x78344;
  Con_Printf();
  return;
}


// SV_ConvertPMTrace  @ 000854a0
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


// SV_CopyEdictToPhysent  @ 000849e8
void SV_CopyEdictToPhysent(char *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_3 + 0x88);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_3 + 0x8c);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_3 + 0x90);
  if ((param_2 < 1) || (DAT_001ab4e8 < param_2)) {
    param_1[0x20] = '\0';
    param_1[0x21] = '\0';
    param_1[0x22] = '\0';
    param_1[0x23] = '\0';
  }
  else {
    SV_GetTrueOrigin(param_2 + -1,param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x50);
  }
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_3 + 0xd0);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_3 + 0xd4);
  uVar1 = *(undefined4 *)(param_3 + 0xd8);
  param_1[0x34] = '\0';
  param_1[0x35] = '\0';
  param_1[0x36] = '\0';
  param_1[0x37] = '\0';
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_3 + 0x1c8);
  iVar2 = *(int *)(param_3 + 0x18c);
  if (iVar2 == 4) {
    uVar1 = *(undefined4 *)(&DAT_00183e88 + *(int *)(param_3 + 0x134) * 4);
  }
  else {
    if (iVar2 != 0) {
      if (iVar2 == 2) {
        param_1[0x30] = '\0';
        param_1[0x31] = '\0';
        param_1[0x32] = '\0';
        param_1[0x33] = '\0';
        if (*(int *)(param_3 + 0x134) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(&DAT_00183e88 + *(int *)(param_3 + 0x134) * 4);
        }
        if (iVar2 != 0) {
          if ((*(byte *)(iVar2 + 0x51) & 2) != 0) {
            *(int *)(param_1 + 0x34) = iVar2;
          }
          Q_strncpy(param_1,iVar2,0x20);
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
          Q_strncpy(param_1,*(int *)(param_3 + 0x80) + pr_strings,0x20);
        }
        param_1[0x1f] = '\0';
      }
      goto LAB_00084bd8;
    }
    if (*(int *)(param_3 + 0x134) == 0) {
      param_1[0x30] = '\0';
      param_1[0x31] = '\0';
      param_1[0x32] = '\0';
      param_1[0x33] = '\0';
      goto LAB_00084bd8;
    }
    uVar1 = *(undefined4 *)(&DAT_00183e88 + *(int *)(param_3 + 0x134) * 4);
  }
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  Q_strncpy(param_1,uVar1,0x20);
  param_1[0x1f] = '\0';
LAB_00084bd8:
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


// SV_CountPlayers  @ 000730ec
void SV_CountPlayers(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *local_8;
  
  *param_1 = 0;
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  if (0 < DAT_001ab4e8) {
    local_8 = DAT_001ab4e4 + 0x917;
    piVar2 = DAT_001ab4e4 + 3;
    iVar3 = 0;
    piVar1 = DAT_001ab4e4;
    do {
      if ((((*piVar1 != 0) || (piVar2[-2] != 0)) || (*piVar2 != 0)) &&
         ((*param_1 = *param_1 + 1, *local_8 != 0 && (param_2 != (int *)0x0)))) {
        *param_2 = *param_2 + 1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x1415;
      local_8 = local_8 + 0x1415;
      piVar1 = piVar1 + 0x1415;
    } while (iVar3 < DAT_001ab4e8);
  }
  return;
}


// SV_CreateAreaNode  @ 0008b6c4
int * SV_CreateAreaNode(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  float local_40;
  float local_3c;
  float local_38;
  float local_34 [7];
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = sv_numareanodes;
  iVar5 = sv_numareanodes * 0x20;
  piVar6 = &sv_areanodes + sv_numareanodes * 8;
  sv_numareanodes = sv_numareanodes + 1;
  ClearLink(iVar5 + 0x205b10);
  ClearLink(iVar5 + 0x205b18);
  if (param_1 == 4) {
    *piVar6 = -1;
    *(undefined4 *)(&DAT_00205b0c + iVar5) = 0;
    (&DAT_00205b08)[iVar3 * 8] = 0;
  }
  else {
    local_10 = *param_3 - *param_2;
    local_c = param_3[1] - param_2[1];
    local_8 = param_3[2] - param_2[2];
    if (local_10 <= local_c) {
      *piVar6 = 1;
    }
    else {
      *piVar6 = 0;
    }
    (&DAT_00205b04)[iVar3 * 8] = (param_3[*piVar6] + param_2[*piVar6]) * 0.5;
    local_34[0] = *param_2;
    local_34[1] = param_2[1];
    local_34[2] = param_2[2];
    local_40 = *param_3;
    local_3c = param_3[1];
    local_38 = param_3[2];
    iVar2 = *piVar6;
    fVar1 = (float)(&DAT_00205b04)[iVar3 * 8];
    local_34[3] = local_40;
    local_34[4] = local_3c;
    local_34[5] = local_38;
    local_34[6] = local_34[0];
    local_18 = local_34[1];
    local_14 = local_34[2];
    local_34[iVar2] = fVar1;
    (local_34 + 3)[iVar2] = fVar1;
    uVar4 = SV_CreateAreaNode(param_1 + 1,local_34,&local_40);
    (&DAT_00205b08)[iVar3 * 8] = uVar4;
    uVar4 = SV_CreateAreaNode(param_1 + 1,local_34 + 6,local_34 + 3);
    *(undefined4 *)(&DAT_00205b0c + iVar5) = uVar4;
  }
  return piVar6;
}


// SV_CreateBaseline  @ 0007b5b8
void SV_CreateBaseline(void)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *local_174;
  int local_170;
  int local_16c;
  int local_168;
  undefined4 *local_164;
  undefined1 local_158 [340];
  
  if (((g_pcustomentitydelta != 0) && (g_pentitydelta != 0)) && (g_pplayerdelta != 0)) {
    DAT_00186f9c = &g_sv_instance_baselines;
    Q_memset(local_158,0,0x154);
    SV_FindModelNumbers();
    iVar6 = 0;
    local_164 = &sv;
    if (0 < DAT_00186f8c) {
      iVar5 = 0;
      local_170 = 0;
      do {
        piVar4 = (int *)(local_170 + local_164[0xce85]);
        local_174 = local_164;
        if ((*piVar4 == 0) && ((iVar6 <= DAT_001ab4e8 || (piVar4[0x4d] != 0)))) {
          bVar2 = iVar6 <= DAT_001ab4e8;
          *(int *)(local_164[0xce86] + 4 + iVar5) = iVar6;
          *(undefined4 *)(DAT_00186f98 + iVar5) = 1;
          if ((*(byte *)((int)piVar4 + 0x227) & 0x20) != 0) {
            *(undefined4 *)(DAT_00186f98 + iVar5) = 2;
          }
          (*DAT_003862c0)(0 < iVar6 && bVar2,iVar6,iVar5 + DAT_00186f98,piVar4,sv_playermodel,
                          &player_mins,&player_maxs);
          local_174 = &sv;
          sv_lastnum = iVar6;
        }
        iVar5 = iVar5 + 0x154;
        local_170 = local_170 + 0x324;
        iVar6 = iVar6 + 1;
        local_164 = local_174;
      } while (iVar6 < (int)local_174[0xce83]);
    }
    (*DAT_003862dc)();
    MSG_WriteByte(&DAT_0018a2c4,0x16);
    MSG_StartBitWriting(&DAT_0018a2c4);
    iVar6 = 0;
    if (0 < DAT_00186f8c) {
      local_168 = 0;
      local_16c = 0;
      do {
        if ((*(int *)(local_16c + DAT_00186f94) == 0) &&
           ((iVar6 <= DAT_001ab4e8 || (((int *)(local_16c + DAT_00186f94))[0x4d] != 0)))) {
          MSG_WriteBits(iVar6,0xb);
          uVar1 = *(uint *)(DAT_00186f98 + local_168);
          MSG_WriteBits(*(undefined4 *)(DAT_00186f98 + local_168),2);
          if (((uVar1 ^ 1) & 1) == 0) {
            uVar7 = 0;
            iVar3 = SV_IsPlayerIndex(iVar6,0);
            iVar5 = g_pentitydelta;
            if (iVar3 != 0) {
              iVar5 = g_pplayerdelta;
            }
          }
          else {
            uVar7 = 0;
            iVar5 = g_pcustomentitydelta;
          }
          DELTA_WriteDelta(local_158,local_168 + DAT_00186f98,1,iVar5,uVar7);
        }
        local_168 = local_168 + 0x154;
        local_16c = local_16c + 0x324;
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_00186f8c);
    }
    MSG_WriteBits(0xffff,0x10);
    MSG_WriteBits(*DAT_00186f9c,6);
    iVar6 = 0;
    if (0 < *DAT_00186f9c) {
      iVar5 = 0x104;
      do {
        DELTA_WriteDelta(local_158,iVar5 + (int)DAT_00186f9c,1,g_pentitydelta,0);
        iVar5 = iVar5 + 0x154;
        iVar6 = iVar6 + 1;
      } while (iVar6 < *DAT_00186f9c);
    }
    MSG_EndBitWriting(&DAT_0018a2c4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("g_pcustomentitydelta && g_pentitydelta && g_pplayerdelta",
                "/home/jihad/valve/goldsrc/engine/sv_main.c",0x1588,"SV_CreateBaseline");
}


// SV_CreateCustomizationList  @ 00083748
void SV_CreateCustomizationList(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  *(undefined4 *)(param_1 + 0x4f48) = 0;
  iVar1 = *(int *)(param_1 + 0x4d04);
  do {
    if (iVar1 == param_1 + 0x4c84) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x4f48);
    if (iVar3 != 0) {
      do {
        iVar2 = Q_memcmp(iVar3 + 0x51,iVar1 + 0x4d,0x10);
        if (iVar2 == 0) {
          Con_DPrintf("SV_CreateCustomization list, ignoring dup. resource for player %s\n",
                      param_1 + 0x4c3c);
          goto LAB_00083841;
        }
        iVar3 = *(int *)(iVar3 + 0xa0);
      } while (iVar3 != 0);
    }
    local_8 = 0;
    iVar3 = COM_CreateCustomization(param_1 + 0x4ea8,iVar1,0xffffffff,3,&local_c,&local_8);
    if (iVar3 == 0) {
      Con_Printf("Ignoring invalid custom decal from %s\n",param_1 + 0x4c3c);
    }
    else {
      *(undefined4 *)(local_c + 0x94) = local_8;
      (*DAT_00386294)(*(undefined4 *)(param_1 + 0x4ae4),local_c);
    }
LAB_00083841:
    iVar1 = *(int *)(iVar1 + 0x80);
  } while( true );
}


// SV_CreatePacketEntities  @ 000797c8
undefined4 SV_CreatePacketEntities(int param_1,int param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  int local_54;
  uint *local_28;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((g_pcustomentitydelta == 0) || (g_pentitydelta == 0)) || (g_pplayerdelta == 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("g_pcustomentitydelta && g_pentitydelta && g_pplayerdelta",
                  "/home/jihad/valve/goldsrc/engine/sv_main.c",0x112a,"SV_CreatePacketEntities");
  }
  if (param_1 == 1) {
    iVar4 = (*(uint *)(param_2 + 0x2454) & SV_UPDATE_MASK) * 0xd10 + *(int *)(param_2 + 0x34e0);
    local_c = iVar4 + 0xce8;
    local_1c = *(int *)(iVar4 + 0xce8);
    MSG_WriteByte(param_4,0x29);
    MSG_WriteShort(param_4,*param_3);
    MSG_WriteByte(param_4,*(undefined4 *)(param_2 + 0x2454));
  }
  else {
    local_1c = 0;
    local_c = 0;
    MSG_WriteByte(param_4,0x28);
    MSG_WriteShort(param_4,*param_3);
  }
  local_14 = 0;
  local_10 = 0;
  MSG_StartBitWriting(param_4);
  local_54 = *param_3;
  if (0 < local_54) goto LAB_000798f9;
  do {
    if (local_1c <= local_10) {
      MSG_WriteBits(0,0x10);
      MSG_EndBitWriting(param_4);
      return *(undefined4 *)(param_4 + 0xc);
    }
    if (local_54 <= local_14) {
      local_18 = 9999;
      goto LAB_0007991f;
    }
LAB_000798f9:
    do {
      local_18 = *(int *)(param_3[9] + 4 + local_14 * 0x154);
LAB_0007991f:
      if (local_10 < local_1c) {
        iVar4 = *(int *)(*(int *)(local_c + 0x24) + 4 + local_10 * 0x154);
      }
      else {
        iVar4 = 9999;
      }
      if (local_18 == iVar4) {
        TRACE_DELTA("delta %i\n",iVar4);
        uVar5 = *(uint *)(param_3[9] + local_14 * 0x154) >> 1 & 1;
        SV_SetCallback(iVar4,0,uVar5,&local_8);
        if (uVar5 == 0) {
          pcVar7 = SV_InvokeCallback;
          iVar3 = SV_IsPlayerIndex(iVar4,SV_InvokeCallback);
          iVar4 = g_pentitydelta;
          if (iVar3 != 0) {
            iVar4 = g_pplayerdelta;
          }
          iVar3 = param_3[9] + local_14 * 0x154;
        }
        else {
          pcVar7 = SV_InvokeCallback;
          iVar3 = local_14 * 0x154 + param_3[9];
          iVar4 = g_pcustomentitydelta;
        }
        DELTA_WriteDelta(*(int *)(local_c + 0x24) + local_10 * 0x154,iVar3,0,iVar4,pcVar7);
        local_14 = local_14 + 1;
LAB_00079c65:
        local_10 = local_10 + 1;
        local_54 = *param_3;
      }
      else if (local_18 < iVar4) {
        iVar4 = EDICT_NUM(local_18);
        TRACE_DELTA("new from baseline %i\n",local_18);
        uVar5 = *(uint *)(param_3[9] + local_14 * 0x154) >> 1 & 1;
        SV_SetCallback(local_18,0,uVar5,&local_8);
        local_28 = (uint *)(DAT_00186f98 + local_18 * 0x154);
        if (((byte)((float)sv_instancedbaseline._12_4_ < 0.0 |
                    (byte)((ushort)((ushort)NAN((float)sv_instancedbaseline._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)sv_instancedbaseline._12_4_ == 0.0) << 0xe) >> 8)
                   ) != 0x40) && (sv_lastnum < local_18)) {
          iVar3 = 0;
          uVar1 = *DAT_00186f9c;
          if (0 < (int)uVar1) {
            uVar2 = *(uint *)(iVar4 + 0x80);
            uVar6 = uVar1 & 3;
            if (uVar6 == 0) goto LAB_00079b4c;
            if (uVar6 < 2) {
LAB_00079b64:
              for (; (iVar4 = iVar3, DAT_00186f9c[iVar3 + 1] != uVar2 &&
                     (iVar3 = iVar3 + 1, iVar4 = iVar3, iVar3 < (int)uVar1)); iVar3 = iVar3 + 3) {
LAB_00079b4c:
                iVar4 = iVar3;
                if ((DAT_00186f9c[iVar3 + 1] == uVar2) ||
                   ((iVar4 = iVar3 + 1, DAT_00186f9c[iVar3 + 2] == uVar2 ||
                    (iVar4 = iVar3 + 2, DAT_00186f9c[iVar3 + 3] == uVar2)))) break;
              }
            }
            else if (uVar6 < 3) {
LAB_00079b36:
              iVar4 = iVar3;
              if (DAT_00186f9c[iVar3 + 1] != uVar2) {
                iVar3 = iVar3 + 1;
                goto LAB_00079b64;
              }
            }
            else {
              iVar4 = iVar3;
              if (DAT_00186f9c[1] != uVar2) {
                iVar3 = 1;
                goto LAB_00079b36;
              }
            }
            if (iVar4 < (int)*DAT_00186f9c) {
              SV_SetNewInfo(iVar4);
              local_28 = DAT_00186f9c + iVar4 * 0x55 + 0x41;
            }
          }
        }
        if (uVar5 == 0) {
          pcVar7 = SV_InvokeCallback;
          iVar3 = SV_IsPlayerIndex(local_18,SV_InvokeCallback);
          iVar4 = g_pentitydelta;
          if (iVar3 != 0) {
            iVar4 = g_pplayerdelta;
          }
          iVar3 = param_3[9] + local_14 * 0x154;
        }
        else {
          pcVar7 = SV_InvokeCallback;
          iVar3 = param_3[9] + local_14 * 0x154;
          iVar4 = g_pcustomentitydelta;
        }
        DELTA_WriteDelta(local_28,iVar3,1,iVar4,pcVar7);
        local_14 = local_14 + 1;
        local_54 = *param_3;
      }
      else if (iVar4 < local_18) {
        SV_WriteDeltaHeader(iVar4,1,0,&local_8,0,0);
        TRACE_DELTA("remove%i\n",iVar4);
        goto LAB_00079c65;
      }
    } while (local_14 < local_54);
  } while( true );
}


// SV_CreateResourceList  @ 0007b1c0
void SV_CreateResourceList(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  int iVar6;
  
  bVar1 = false;
  piVar5 = &DAT_0018568c;
  iVar6 = 1;
  DAT_0017de80 = 0;
  iVar3 = DAT_0018568c;
  do {
    if (iVar3 == 0) {
      piVar5 = &DAT_0018368c;
      iVar6 = 1;
      iVar3 = DAT_0018368c;
      while (iVar3 != 0) {
        if ((DAT_001ab4e8 < 2) || (iVar3 = COM_FileSize(*piVar5), iVar3 == -1)) {
          iVar3 = 0;
        }
        SV_AddResource(2,*piVar5,iVar3,1,iVar6);
        piVar5 = piVar5 + 1;
        iVar6 = iVar6 + 1;
        iVar3 = *piVar5;
      }
      iVar3 = 0;
      if (0 < sv_decalnamecount) {
        iVar6 = 0;
        do {
          uVar2 = Draw_DecalSize(iVar3,0,iVar3);
          SV_AddResource(3,sv_decalnames + iVar6,uVar2);
          iVar6 = iVar6 + 0x11;
          iVar3 = iVar3 + 1;
        } while (iVar3 < sv_decalnamecount);
      }
      piVar5 = &DAT_00186690;
      iVar6 = 1;
      iVar3 = DAT_00186690;
      while (iVar3 != 0) {
        if ((DAT_001ab4e8 < 2) || (iVar3 = COM_FileSize(*piVar5), iVar3 == -1)) {
          iVar3 = 0;
        }
        SV_AddResource(4,*piVar5,iVar3,1,iVar6);
        piVar5 = piVar5 + 1;
        iVar6 = iVar6 + 1;
        iVar3 = *piVar5;
      }
      iVar6 = 1;
      iVar3 = 0x10;
      do {
        if (*(int *)(&DAT_00184694 + iVar3) == 0) {
          return;
        }
        SV_AddResource(5,*(undefined4 *)(&DAT_0018468c + iVar3),
                       *(undefined4 *)(&DAT_00184690 + iVar3),1,iVar6);
        if (*(int *)((int)&DAT_001846a4 + iVar3) == 0) {
          return;
        }
        SV_AddResource(5,*(undefined4 *)((int)&DAT_0018469c + iVar3),
                       *(undefined4 *)((int)&DAT_001846a0 + iVar3),1,iVar6 + 1);
        if (*(int *)((int)&DAT_001846b4 + iVar3) == 0) {
          return;
        }
        SV_AddResource(5,*(undefined4 *)((int)&DAT_001846ac + iVar3),
                       *(undefined4 *)((int)&DAT_001846b0 + iVar3),1,iVar6 + 2);
        iVar3 = iVar3 + 0x30;
        iVar6 = iVar6 + 3;
      } while (iVar6 < 0x100);
      return;
    }
    if (*(char *)*piVar5 == '!') {
      if (!bVar1) {
        bVar1 = true;
        uVar2 = 1;
        iVar3 = 0;
        puVar4 = &DAT_000ab90d;
        goto LAB_0007b250;
      }
    }
    else {
      if (DAT_001ab4e8 < 2) {
LAB_0007b22e:
        iVar3 = 0;
      }
      else {
        uVar2 = va("sound/%s",(char *)*piVar5);
        iVar3 = COM_FileSize(uVar2);
        if (iVar3 == -1) goto LAB_0007b22e;
      }
      uVar2 = 0;
      puVar4 = (undefined *)*piVar5;
LAB_0007b250:
      SV_AddResource(0,puVar4,iVar3,uVar2,iVar6);
    }
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + 1;
    iVar3 = *piVar5;
  } while( true );
}


// SV_Customization  @ 00083868
void SV_Customization(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = -1;
  iVar2 = 0;
  for (host_client = DAT_001ab4e4;
      (iVar1 = local_8, iVar2 < DAT_001ab4e8 && (iVar1 = iVar2, host_client != param_1));
      host_client = host_client + 0x1415) {
    iVar2 = iVar2 + 1;
  }
  local_8 = iVar1;
  if (local_8 == -1) {
    Sys_Error("Couldn\'t find player index for customization.");
  }
  else {
    host_client = DAT_001ab4e4;
    iVar2 = 0;
    if (0 < DAT_001ab4e8) {
      do {
        if ((((*host_client != 0) || (host_client[1] != 0)) && (host_client[0x918] == 0)) &&
           ((host_client != param_1 || (param_3 == 0)))) {
          MSG_WriteByte(host_client + 0x1d,0x2e);
          MSG_WriteByte(host_client + 0x1d,local_8);
          MSG_WriteByte(host_client + 0x1d,*(undefined4 *)(param_2 + 0x40));
          MSG_WriteString(host_client + 0x1d,param_2);
          MSG_WriteShort(host_client + 0x1d,*(undefined4 *)(param_2 + 0x44));
          MSG_WriteLong(host_client + 0x1d,*(undefined4 *)(param_2 + 0x48));
          MSG_WriteByte(host_client + 0x1d,*(undefined1 *)(param_2 + 0x4c));
          if ((*(byte *)(param_2 + 0x4c) & 4) != 0) {
            SZ_Write(host_client + 0x1d,param_2 + 0x4d,0x10);
          }
        }
        host_client = host_client + 0x1415;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_001ab4e8);
    }
  }
  return;
}


// SV_DeallocateDynamicData  @ 00072ab8
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


// SV_DropClient  @ 000554b8
void SV_DropClient(undefined4 *param_1,int param_2)

{
  int iVar1;
  double dVar2;
  code *pcVar3;
  char *pcVar4;
  undefined1 local_18 [20];
  
  if (param_2 == 0) {
    iVar1 = param_1[0x918];
    if (iVar1 == 0) {
      MSG_WriteByte(param_1 + 0x1d,2);
      local_18[0] = 2;
    }
    if ((param_1[0x12b9] != 0) && (param_1[1] != 0)) {
      pcVar3 = DAT_00386260;
      if (param_1[0x917] != 0) {
        pcVar3 = DAT_0038629c;
      }
      (*pcVar3)(param_1[0x12b9]);
    }
    if (param_1[0x131a] != 0) {
      COM_FreeFile(param_1[0x131a]);
      param_1[0x131a] = 0;
    }
    if ((FILE *)param_1[0x1365] != (FILE *)0x0) {
      fclose((FILE *)param_1[0x1365]);
      param_1[0x1365] = 0;
    }
    if (param_1[0x917] == 0) {
      pcVar4 = "Dropped %s from server\n";
    }
    else {
      pcVar4 = "Dropped %s (spectator) from server\n";
    }
    Sys_Printf(pcVar4,param_1 + 0x130f);
    if (param_1[0x918] == 0) {
      Netchan_Transmit(param_1 + 8,iVar1 == 0,local_18);
    }
  }
  if ((float)realtime - (float)param_1[0xf] <= 60.0) {
    Netchan_Clear(param_1 + 8);
    *param_1 = 0;
    param_1[3] = 0;
    param_1[5] = 0;
    param_1[0x918] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 0x130f) = 0;
    dVar2 = realtime;
    param_1[0x12b9] = 0;
    *(double *)(param_1 + 0xd30) = dVar2;
    Q_memset(param_1 + 0x12bd,0,0x100);
    Q_memset(param_1 + 0x13d5,0,0x100);
    SV_FullClientUpdate(param_1,&DAT_00187f54);
    return;
  }
  DAT_001ab550 = DAT_001ab550 + ((float)realtime - (float)param_1[0xf]);
  DAT_001ab54c = DAT_001ab54c + 1;
  FUN_000555f0();
  return;
}


// SV_Drop_f  @ 0007dfa8
void SV_Drop_f(void)

{
  if (cmd_source == 1) {
    Cmd_ForwardToServer();
  }
  else {
    SV_EndRedirect();
    if (*(int *)(host_client + 0x245c) == 0) {
      SV_BroadcastPrintf("%s dropped\n",host_client + 0x4c3c);
    }
    SV_DropClient(host_client,0);
  }
  return;
}


// SV_EmitEvents  @ 00078e90
void SV_EmitEvents(int param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short *local_b0;
  short *local_ac;
  int *local_a8;
  short *local_a4;
  undefined4 *local_a0;
  undefined4 *local_9c;
  undefined4 *local_98;
  undefined4 *local_94;
  uint *local_90;
  undefined4 *local_8c;
  undefined4 *local_88;
  undefined4 *local_84;
  int local_80;
  float *local_7c;
  short *local_78;
  undefined2 *local_74;
  int local_64;
  int local_5c;
  undefined1 local_4c [72];
  
  local_64 = 0;
  if (g_peventdelta == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("g_peventdelta","/home/jihad/valve/goldsrc/engine/sv_main.c",0xfa1,"SV_EmitEvents"
                 );
  }
  Q_memset(local_4c,0,0x48);
  psVar3 = (short *)(param_1 + 0x34e4);
  local_5c = 0x3f;
  psVar4 = psVar3;
  do {
    if (*psVar4 != 0) {
      local_64 = local_64 + 1;
    }
    if (psVar4[0x2c] != 0) {
      local_64 = local_64 + 1;
    }
    if (psVar4[0x58] != 0) {
      local_64 = local_64 + 1;
    }
    if (psVar4[0x84] != 0) {
      local_64 = local_64 + 1;
    }
    psVar4 = psVar4 + 0xb0;
    local_5c = local_5c + -4;
  } while (-1 < local_5c);
  if (local_64 != 0) {
    local_5c = 0;
    local_84 = (undefined4 *)(param_1 + 0x350c);
    local_88 = (undefined4 *)(param_1 + 0x3508);
    local_8c = (undefined4 *)(param_1 + 0x3504);
    local_90 = (uint *)(param_1 + 0x34f0);
    local_94 = (undefined4 *)(param_1 + 0x3500);
    local_98 = (undefined4 *)(param_1 + 0x34fc);
    local_9c = (undefined4 *)(param_1 + 0x34f8);
    local_a0 = (undefined4 *)(param_1 + 0x351c);
    local_a4 = (short *)(param_1 + 0x34e6);
    local_a8 = (int *)(param_1 + 0x34f4);
    local_ac = (short *)(param_1 + 0x34e8);
    local_b0 = psVar3;
    do {
      if ((*local_b0 != 0) && (*local_a4 == -1)) {
        iVar9 = (int)*local_ac;
        iVar7 = 0;
        uVar6 = *param_2;
        if (0 < (int)uVar6) {
          uVar2 = param_2[9];
          piVar5 = (int *)(uVar2 + 4);
          uVar1 = uVar6 & 3;
          iVar8 = iVar7;
          if (uVar1 == 0) goto LAB_00079070;
          if (uVar1 < 2) {
LAB_00079062:
            if (*piVar5 != iVar9) {
              piVar5 = piVar5 + 0x55;
              while (iVar8 = iVar7 + 1, iVar7 = iVar8, iVar8 < (int)uVar6) {
LAB_00079070:
                iVar7 = iVar8;
                if ((((*piVar5 == iVar9) || (iVar7 = iVar8 + 1, piVar5[0x55] == iVar9)) ||
                    (iVar7 = iVar8 + 2, piVar5[0xaa] == iVar9)) ||
                   (iVar7 = iVar8 + 3, piVar5[0xff] == iVar9)) break;
                piVar5 = piVar5 + 0x154;
              }
            }
          }
          else if (uVar1 < 3) {
LAB_00079057:
            if (*piVar5 != iVar9) {
              piVar5 = piVar5 + 0x55;
              iVar7 = iVar7 + 1;
              goto LAB_00079062;
            }
          }
          else if (*(int *)(uVar2 + 4) != iVar9) {
            piVar5 = (int *)(uVar2 + 0x158);
            iVar7 = 1;
            goto LAB_00079057;
          }
          if (iVar7 < (int)uVar6) {
            *local_a4 = (short)iVar7;
            *local_a0 = 0;
            uVar6 = *local_90;
            if ((uVar6 & 1) == 0) {
              *local_9c = 0;
              *local_98 = 0;
              *local_94 = 0;
              uVar6 = *local_90;
            }
            if ((uVar6 & 2) == 0) {
              *local_8c = 0;
              *local_88 = 0;
              *local_84 = 0;
            }
            goto LAB_00079130;
          }
        }
        *local_a4 = (short)*param_2;
        *local_a8 = iVar9;
      }
LAB_00079130:
      local_84 = local_84 + 0x16;
      local_88 = local_88 + 0x16;
      local_8c = local_8c + 0x16;
      local_90 = local_90 + 0x16;
      local_94 = local_94 + 0x16;
      local_98 = local_98 + 0x16;
      local_9c = local_9c + 0x16;
      local_a0 = local_a0 + 0x16;
      local_a4 = local_a4 + 0x2c;
      local_a8 = local_a8 + 0x16;
      local_ac = local_ac + 0x2c;
      local_b0 = local_b0 + 0x2c;
      local_5c = local_5c + 1;
    } while (local_5c < 0x40);
    MSG_WriteByte(param_3,3);
    MSG_StartBitWriting(param_3);
    MSG_WriteBits(local_64,5);
    iVar7 = 0;
    local_74 = (undefined2 *)(param_1 + 0x34e8);
    local_78 = (short *)(param_1 + 0x34e6);
    local_7c = (float *)(param_1 + 0x34ec);
    local_80 = param_1 + 0x34f0;
    do {
      if (*psVar3 != 0) {
        MSG_WriteBits(*psVar3,10);
        if (*local_78 == -1) {
LAB_00079250:
          MSG_WriteBits(0,1);
        }
        else {
          MSG_WriteBits(1,1);
          MSG_WriteBits((int)*local_78,0xb);
          iVar9 = Q_memcmp(local_4c,local_80,0x48);
          if (iVar9 == 0) goto LAB_00079250;
          MSG_WriteBits(1,1);
          DELTA_WriteDelta(local_4c,local_80,1,g_peventdelta,0);
        }
        if ((byte)((byte)((ushort)((ushort)NAN(*local_7c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*local_7c == 0.0) << 0xe) >> 8)) == 0x40) {
          MSG_WriteBits(0,1);
        }
        else {
          MSG_WriteBits(1,1);
          MSG_WriteBits((int)ROUND(*local_7c * 100.0),0x10);
        }
        *psVar3 = 0;
      }
      *local_78 = -1;
      *local_74 = 0xffff;
      local_74 = local_74 + 0x2c;
      local_78 = local_78 + 0x2c;
      psVar3 = psVar3 + 0x2c;
      local_7c = local_7c + 0x16;
      local_80 = local_80 + 0x58;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x40);
    MSG_EndBitWriting(param_3);
  }
  return;
}


// SV_EmitPacketEntities  @ 00079ca8
void SV_EmitPacketEntities(int param_1,undefined4 param_2,undefined4 param_3)

{
  SV_CreatePacketEntities(*(int *)(param_1 + 0x2454) != -1,param_1,param_2,param_3);
  return;
}


// SV_EmitPings  @ 0007a0c0
void SV_EmitPings(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  MSG_WriteByte(param_2,0x11);
  MSG_StartBitWriting(param_2);
  iVar1 = 0;
  piVar2 = DAT_001ab4e4;
  if (0 < DAT_001ab4e8) {
    do {
      if (*piVar2 != 0) {
        SV_GetNetInfo(piVar2,&local_c,&local_8);
        MSG_WriteBits(1,1);
        MSG_WriteBits(iVar1,5);
        MSG_WriteBits(local_c,0xc);
        MSG_WriteBits(local_8,7);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x1415;
    } while (iVar1 < DAT_001ab4e8);
  }
  MSG_WriteBits(0,1);
  MSG_EndBitWriting(param_2);
  return;
}


// SV_EndRedirect  @ 00077f74
void SV_EndRedirect(void)

{
  SV_FlushRedirect();
  sv_redirected = 0;
  return;
}


// SV_EstablishTimeBase  @ 000876e8
void SV_EstablishTimeBase(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  double dVar5;
  double dVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  
  dVar5 = 0.0;
  if (0x17 < param_3) goto LAB_00087831;
  if (param_4 < param_3) {
    dVar6 = (double)*(byte *)(param_1 + 0x246e) * 0.001;
    uVar7 = param_4 - param_3 & 3;
    if (uVar7 != 0) {
      if (uVar7 < 3) {
        if (uVar7 < 2) {
          param_3 = param_3 + -1;
          dVar5 = dVar6;
        }
        dVar5 = dVar5 + dVar6;
        param_3 = param_3 + -1;
      }
      dVar5 = dVar5 + dVar6;
      param_3 = param_3 + -1;
      if (param_3 <= param_4) goto LAB_0008776d;
    }
    do {
      param_3 = param_3 + -4;
      dVar5 = dVar5 + dVar6 + dVar6 + dVar6 + dVar6;
    } while (param_4 < param_3);
  }
LAB_0008776d:
  if (0 < param_3) {
    pbVar9 = (byte *)(param_2 + 2 + (param_5 + param_3 + -1) * 0x34);
    uVar7 = -param_3 & 3;
    if (uVar7 == 0) goto LAB_000877e0;
    if (uVar7 < 3) {
      if (uVar7 < 2) {
        bVar4 = *pbVar9;
        pbVar9 = pbVar9 + -0x34;
        dVar5 = (double)bVar4 * 0.001 + dVar5;
        param_3 = param_3 + -1;
      }
      bVar4 = *pbVar9;
      pbVar9 = pbVar9 + -0x34;
      param_3 = param_3 + -1;
      dVar5 = (double)bVar4 * 0.001 + dVar5;
    }
    bVar4 = *pbVar9;
    pbVar9 = pbVar9 + -0x34;
    for (param_3 = param_3 + -1; dVar5 = (double)bVar4 * 0.001 + dVar5, 0 < param_3;
        param_3 = param_3 + -4) {
LAB_000877e0:
      dVar5 = (double)pbVar9[-0x68] * 0.001 +
              (double)pbVar9[-0x34] * 0.001 + (double)*pbVar9 * 0.001 + dVar5;
      bVar4 = pbVar9[-0x9c];
      pbVar9 = pbVar9 + -0xd0;
    }
  }
LAB_00087831:
  uVar7 = param_5 - 1;
  if (-1 < (int)uVar7) {
    pbVar9 = (byte *)(param_2 + 2 + uVar7 * 0x34);
    uVar8 = ~uVar7 & 3;
    if (-1 < (int)uVar7) {
      if (uVar8 == 0) goto LAB_000878a8;
      if (uVar8 < 3) {
        if (uVar8 < 2) {
          bVar4 = *pbVar9;
          pbVar9 = pbVar9 + -0x34;
          uVar7 = param_5 - 2;
          dVar5 = (double)bVar4 * 0.001 + dVar5;
        }
        bVar4 = *pbVar9;
        pbVar9 = pbVar9 + -0x34;
        uVar7 = uVar7 - 1;
        dVar5 = (double)bVar4 * 0.001 + dVar5;
      }
    }
    bVar4 = *pbVar9;
    pbVar9 = pbVar9 + -0x34;
    dVar5 = (double)bVar4 * 0.001 + dVar5;
    for (uVar7 = uVar7 - 1; -1 < (int)uVar7; uVar7 = uVar7 - 4) {
LAB_000878a8:
      bVar4 = *pbVar9;
      pbVar1 = pbVar9 + -0x34;
      pbVar2 = pbVar9 + -0x68;
      pbVar3 = pbVar9 + -0x9c;
      pbVar9 = pbVar9 + -0xd0;
      dVar5 = (double)*pbVar3 * 0.001 +
              (double)*pbVar2 * 0.001 + (double)*pbVar1 * 0.001 + (double)bVar4 * 0.001 + dVar5;
    }
  }
  *(double *)(param_1 + 0x24c8) = (DAT_0015358c + host_frametime) - dVar5;
  return;
}


// SV_EstimateNeededResources  @ 00083bc8
int SV_EstimateNeededResources(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  for (iVar2 = *(int *)(host_client + 0x4d8c); iVar2 != host_client + 0x4d0c;
      iVar2 = *(int *)(iVar2 + 0x80)) {
    iVar3 = 0;
    if (*(int *)(iVar2 + 0x40) == 3) {
      iVar1 = HPAK_ResourceForHash("custom.hpk",iVar2 + 0x4d,0);
      if (iVar1 == 0) {
        iVar3 = *(int *)(iVar2 + 0x48);
      }
    }
    if (iVar3 != 0) {
      *(byte *)(iVar2 + 0x4c) = *(byte *)(iVar2 + 0x4c) | 2;
      local_8 = local_8 + iVar3;
    }
  }
  return local_8;
}


// SV_ExecuteClientMessage  @ 000882f8
void SV_ExecuteClientMessage(int param_1)

{
  double dVar1;
  uint uVar2;
  char *pcVar3;
  double *pdVar4;
  
  g_balreadymoved = 0;
  pdVar4 = (double *)
           ((*(uint *)(param_1 + 0x54) & SV_UPDATE_MASK) * 0xd10 + *(int *)(param_1 + 0x34e0));
  *(float *)(pdVar4 + 1) =
       (float)(((longdouble)realtime - (longdouble)*pdVar4) -
              (longdouble)*(double *)(param_1 + 0x34d0));
  if ((byte)((byte)((ushort)((ushort)NAN(*pdVar4) << 10) >> 8) |
            (byte)((ushort)((ushort)(*pdVar4 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(pdVar4 + 1) = 0;
  }
  dVar1 = realtime - *(double *)(param_1 + 0x34c0);
  if ((0x3f < (byte)((2.0 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(dVar1 == 2.0) << 0xe) >> 8)) - 1)) &&
     (0.0 < *(float *)(pdVar4 + 1))) {
    *(undefined4 *)(pdVar4 + 1) = 0;
  }
  SV_ComputeLatency(param_1);
  host_client = param_1;
  sv_player = *(undefined4 *)(param_1 + 0x4ae4);
  *(undefined4 *)(param_1 + 0x2454) = 0xffffffff;
  pmove = g_svmove;
  do {
    if (msg_badread != 0) {
      pcVar3 = "SV_ReadClientMessage: badread\n";
LAB_0008841a:
      Con_Printf(pcVar3);
      SV_DropClient(param_1,0);
      return;
    }
    uVar2 = MSG_ReadByte();
    if (uVar2 == 0xffffffff) {
      return;
    }
    if (7 < uVar2) {
      pcVar3 = "SV_ReadClientMessage: unknown command char\n";
      goto LAB_0008841a;
    }
    if (*(code **)(sv_clcfuncs + uVar2 * 0xc + 8) != (code *)0x0) {
      (**(code **)(sv_clcfuncs + uVar2 * 0xc + 8))();
    }
  } while( true );
}


// SV_ExtractFromUserinfo  @ 0007aae8
void SV_ExtractFromUserinfo(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *local_bc;
  int local_ac;
  char *local_a8;
  undefined1 local_a4 [80];
  char local_54 [79];
  undefined1 local_5;
  
  local_ac = 1;
  piVar5 = param_1 + 0x12bd;
  (*DAT_00386270)(param_1[0x12b9],piVar5);
  local_a8 = (char *)Info_ValueForKey(piVar5,&DAT_000ab1a6);
  Q_strncpy(local_54,local_a8,0x4f);
  local_5 = 0;
  Q_strcpy(local_a4,local_54);
  TrimSpace(local_a4,local_54);
  iVar1 = Q_strlen(local_54);
  if ((iVar1 < 1) || (iVar1 = Q_stricmp(local_54,"console"), iVar1 == 0)) {
    Info_SetValueForKey(piVar5,&DAT_000ab1a6,"unnamed",0x100);
  }
  else {
    iVar1 = Q_strcmp(local_a8,local_54);
    if (iVar1 == 0) goto LAB_0007ac2c;
    Info_SetValueForKey(piVar5,&DAT_000ab1a6,local_54,0x100);
  }
  local_a8 = (char *)Info_ValueForKey(piVar5,&DAT_000ab1a6);
LAB_0007ac2c:
  do {
    iVar1 = 0;
    local_bc = DAT_001ab4e4 + 0x130f;
    piVar7 = DAT_001ab4e4;
    do {
      if ((((*piVar7 != 0) && (local_bc[-0x130e] != 0)) && (piVar7 != param_1)) &&
         (iVar2 = Q_stricmp(local_bc,local_a8), iVar6 = iVar1, iVar2 == 0)) break;
      if (((piVar7[0x1415] != 0) && (local_bc[0x107] != 0)) &&
         ((piVar7 + 0x1415 != param_1 &&
          (iVar2 = Q_stricmp(local_bc + 0x1415,local_a8), iVar6 = iVar1 + 1, iVar2 == 0)))) break;
      if (((piVar7[0x282a] != 0) && (local_bc[0x151c] != 0)) &&
         ((piVar7 + 0x282a != param_1 &&
          (iVar2 = Q_stricmp(local_bc + 0x282a,local_a8), iVar6 = iVar1 + 2, iVar2 == 0)))) break;
      if ((((piVar7[0x3c3f] != 0) && (local_bc[0x2931] != 0)) && (piVar7 + 0x3c3f != param_1)) &&
         (iVar2 = Q_stricmp(local_bc + 0x3c3f,local_a8), iVar6 = iVar1 + 3, iVar2 == 0)) break;
      iVar1 = iVar1 + 4;
      local_bc = local_bc + 0x5054;
      piVar7 = piVar7 + 0x5054;
      iVar6 = iVar1;
    } while (iVar1 < 0x20);
    if (0x1f < iVar6) {
      piVar7 = param_1 + 0x130f;
      Q_strncpy(piVar7,local_a8,0x1f);
      uVar4 = Info_ValueForKey(piVar5,&DAT_000aad71);
      iVar1 = Q_strlen(uVar4);
      if (iVar1 != 0) {
        iVar1 = Q_atoi(uVar4);
        if (iVar1 < 1000) {
          iVar1 = 1000;
        }
        else if (20000 < iVar1) {
          iVar1 = 20000;
        }
        *(double *)(param_1 + 0x10) = (double)iVar1;
      }
      uVar4 = Info_ValueForKey(piVar5,"topcolor");
      iVar1 = Q_strlen(uVar4);
      if (iVar1 == 0) {
        Con_DPrintf("topcolor unchanged for %s\n",piVar7);
      }
      else {
        iVar1 = Q_atoi(uVar4);
        param_1[0x1317] = iVar1;
      }
      uVar4 = Info_ValueForKey(piVar5,"bottomcolor");
      iVar1 = Q_strlen(uVar4);
      if (iVar1 == 0) {
        Con_DPrintf("bottomcolor unchanged for %s\n",piVar7);
      }
      else {
        iVar1 = Q_atoi(uVar4);
        param_1[0x1318] = iVar1;
      }
      uVar4 = Info_ValueForKey(piVar5,"cl_updaterate");
      iVar1 = Q_strlen(uVar4);
      if ((iVar1 != 0) && (iVar1 = Q_atoi(uVar4), 0 < iVar1)) {
        *(double *)(param_1 + 0xd34) = 1.0 / (double)iVar1;
      }
      uVar4 = Info_ValueForKey(piVar5,"cl_lw");
      iVar1 = Q_strlen(uVar4);
      if (iVar1 == 0) {
        param_1[0x13d3] = 0;
      }
      else {
        iVar1 = Q_atoi(uVar4);
        param_1[0x13d3] = (uint)(iVar1 != 0);
      }
      uVar4 = Info_ValueForKey(piVar5,"cl_lc");
      iVar1 = Q_strlen(uVar4);
      if (iVar1 == 0) {
        param_1[0x13d4] = 0;
      }
      else {
        iVar1 = Q_atoi(uVar4);
        param_1[0x13d4] = (uint)(iVar1 != 0);
      }
      SV_CheckUpdateRate(param_1 + 0xd34);
      SV_CheckRate(param_1);
      return;
    }
    uVar3 = Q_strlen(local_a8);
    if (0x1f < uVar3) {
      local_a8[0x1c] = '\0';
    }
    if (*local_a8 == '(') {
      if (local_a8[2] == ')') {
        local_a8 = local_a8 + 3;
      }
      else if (local_a8[3] == ')') {
        local_a8 = local_a8 + 4;
      }
    }
    sprintf(local_54,"(%d)%-0.40s",local_ac,local_a8);
    Info_SetValueForKey(piVar5,&DAT_000ab1a6,local_54,0x100);
    local_a8 = (char *)Info_ValueForKey(piVar5,&DAT_000ab1a6);
    local_ac = local_ac + 1;
  } while( true );
}


// SV_FailDownload  @ 0007d914
void SV_FailDownload(char *param_1)

{
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    MSG_WriteByte(host_client + 0x74,0x31);
    MSG_WriteString(host_client + 0x74,param_1);
  }
  return;
}


// SV_FatPAS  @ 00079554
undefined1 * SV_FatPAS(undefined4 param_1)

{
  fatpasbytes = *(int *)(DAT_00153668 + 0x88) + 0x1f >> 3;
  Q_memset(&fatpas,0,fatpasbytes);
  SV_AddToFatPAS(param_1,*(undefined4 *)(DAT_00153668 + 0xa4));
  return &fatpas;
}


// SV_FatPVS  @ 000793e4
undefined1 * SV_FatPVS(undefined4 param_1)

{
  fatbytes = *(int *)(DAT_00153668 + 0x88) + 0x1f >> 3;
  Q_memset(&fatpvs,0,fatbytes);
  SV_AddToFatPVS(param_1,*(undefined4 *)(DAT_00153668 + 0xa4));
  return &fatpvs;
}


// SV_FileInConsistencyList  @ 00084674
undefined4 SV_FileInConsistencyList(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (*(int *)((int)&DAT_0017de84 + iVar2) == 0) {
      return 0;
    }
    iVar1 = Q_stricmp(param_1,*(int *)((int)&DAT_0017de84 + iVar2));
    if (iVar1 == 0) break;
    iVar2 = iVar2 + 0x2c;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = (int)&DAT_0017de84 + iVar2;
  }
  return 1;
}


// SV_FilterPacket  @ 000786e0
uint SV_FilterPacket(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_30;
  uint local_2c;
  int local_20;
  uint *local_1c;
  int local_14;
  
  uVar2 = DAT_00215fd8;
  local_14 = numipfilters + -1;
  if (-1 < local_14) {
    local_20 = local_14 * 0x10;
    local_1c = &DAT_001a74c4 + local_14 * 4;
    do {
      if (((*local_1c == 0xffffffff) ||
          (fVar1 = *(float *)(&DAT_001a74c8 + local_20),
          (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) ||
         ((float)realtime < fVar1)) {
        if ((uVar2 & *(uint *)((int)&ipfilters + local_20)) == *local_1c) {
          local_2c = (uint)(longlong)ROUND((float)sv_filterban._12_4_);
          return local_2c;
        }
      }
      else {
        local_30 = local_14 + 1;
        if (local_30 < numipfilters) {
          iVar3 = local_30 * 0x10;
          iVar4 = iVar3 + -0x10;
          do {
            *(undefined4 *)((int)&ipfilters + iVar4) = *(undefined4 *)((int)&ipfilters + iVar3);
            *(undefined4 *)((int)&DAT_001a74c4 + iVar4) =
                 *(undefined4 *)((int)&DAT_001a74c4 + iVar3);
            *(undefined4 *)(&DAT_001a74c8 + iVar4) = *(undefined4 *)(&DAT_001a74c8 + iVar3);
            *(undefined4 *)((int)&DAT_001a74cc + iVar4) =
                 *(undefined4 *)((int)&DAT_001a74cc + iVar3);
            iVar3 = iVar3 + 0x10;
            iVar4 = iVar4 + 0x10;
            local_30 = local_30 + 1;
          } while (local_30 < numipfilters);
        }
        numipfilters = numipfilters + -1;
      }
      local_1c = local_1c + -4;
      local_20 = local_20 + -0x10;
      local_14 = local_14 + -1;
    } while (-1 < local_14);
  }
  return (uint)((byte)((float)sv_filterban._12_4_ < 0.0 |
                       (byte)((ushort)((ushort)NAN((float)sv_filterban._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)sv_filterban._12_4_ == 0.0) << 0xe) >> 8)) ==
               0x40);
}


// SV_FilterUser  @ 00075b24
uint SV_FilterUser(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int local_28;
  uint local_24;
  int local_18;
  int local_14;
  
  local_14 = numuserfilters + -1;
  if (-1 < local_14) {
    local_18 = local_14 * 0xc;
    do {
      fVar1 = *(float *)(&DAT_00192464 + local_18);
      if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
         ((float)realtime < fVar1)) {
        if (param_1 == *(int *)((int)&userfilters + local_18)) {
          local_24 = (uint)(longlong)ROUND((float)sv_filterban._12_4_);
          return local_24;
        }
      }
      else {
        iVar3 = local_14 + 1;
        if (iVar3 < numuserfilters) {
          iVar2 = iVar3 * 0xc;
          local_28 = iVar2 + -0xc;
          do {
            iVar3 = iVar3 + 1;
            *(undefined4 *)((int)&userfilters + local_28) =
                 *(undefined4 *)((int)&userfilters + iVar2);
            *(undefined4 *)(&DAT_00192464 + local_28) = *(undefined4 *)(&DAT_00192464 + iVar2);
            *(undefined4 *)((int)&DAT_00192468 + local_28) =
                 *(undefined4 *)((int)&DAT_00192468 + iVar2);
            local_28 = local_28 + 0xc;
            iVar2 = iVar2 + 0xc;
          } while (iVar3 < numuserfilters);
        }
        numuserfilters = numuserfilters + -1;
      }
      local_18 = local_18 + -0xc;
      local_14 = local_14 + -1;
    } while (-1 < local_14);
  }
  return (uint)((byte)((float)sv_filterban._12_4_ < 0.0 |
                       (byte)((ushort)((ushort)NAN((float)sv_filterban._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)sv_filterban._12_4_ == 0.0) << 0xe) >> 8)) ==
               0x40);
}


// SV_FindAuthRequest  @ 0008a3d8
int SV_FindAuthRequest(int param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char **ppcVar6;
  undefined4 auStack_44 [5];
  char *apcStack_30 [5];
  int local_c;
  int local_8;
  
  apcStack_30[4] = (char *)0x8a3e6;
  local_8 = 0;
  local_c = 0;
  do {
    if (*(int *)((int)&svauthstates + local_c) != 0) {
      puVar5 = param_2;
      ppcVar6 = apcStack_30;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppcVar6 = (char *)*puVar5;
        puVar5 = puVar5 + 1;
        ppcVar6 = ppcVar6 + 1;
      }
      puVar4 = (undefined4 *)((int)&svauthstates + local_c);
      puVar5 = auStack_44;
      for (iVar3 = 5; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar5 = puVar5 + 1;
      }
      iVar3 = NET_CompareAdr();
      if (iVar3 != 0) {
        return local_8;
      }
    }
    if (*(int *)((int)&DAT_00203ef8 + local_c) != 0) {
      puVar5 = param_2;
      ppcVar6 = apcStack_30;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppcVar6 = (char *)*puVar5;
        puVar5 = puVar5 + 1;
        ppcVar6 = ppcVar6 + 1;
      }
      puVar4 = (undefined4 *)((int)&DAT_00203ef8 + local_c);
      puVar5 = auStack_44;
      for (iVar3 = 5; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar5 = puVar5 + 1;
      }
      iVar3 = NET_CompareAdr();
      if (iVar3 != 0) {
        return local_8 + 1;
      }
    }
    local_c = local_c + 0x70;
    local_8 = local_8 + 2;
  } while (local_8 < 0x80);
  if (param_1 != 0) {
    local_8 = 0;
    iVar3 = 0;
    do {
      iVar2 = local_8;
      if (((((*(int *)((int)&svauthstates + iVar3) == 0) ||
            (iVar2 = local_8 + 1, *(int *)((int)&DAT_00203ef8 + iVar3) == 0)) ||
           (iVar2 = local_8 + 2, *(int *)((int)&DAT_00203f30 + iVar3) == 0)) ||
          ((iVar2 = local_8 + 3, *(int *)((int)&DAT_00203f68 + iVar3) == 0 ||
           (iVar2 = local_8 + 4, *(int *)((int)&DAT_00203fa0 + iVar3) == 0)))) ||
         ((iVar2 = local_8 + 5, *(int *)((int)&DAT_00203fd8 + iVar3) == 0 ||
          ((iVar2 = local_8 + 6, *(int *)((int)&DAT_00204010 + iVar3) == 0 ||
           (iVar2 = local_8 + 7, *(int *)((int)&DAT_00204048 + iVar3) == 0)))))) break;
      iVar3 = iVar3 + 0x1c0;
      local_8 = local_8 + 8;
      iVar2 = local_8;
    } while (local_8 < 0x80);
    local_8 = iVar2;
    if (local_8 != 0x80) {
      iVar2 = local_8 * 0x38;
      puVar5 = &svauthstates + local_8 * 0xe;
      apcStack_30[3] = (char *)0x8a549;
      apcStack_30[4] = (char *)puVar5;
      WON_RemoveUser();
      iVar3 = *(int *)(&DAT_00203ee0 + iVar2);
      fVar1 = (float)realtime;
      *(undefined4 *)(&DAT_00203ee4 + iVar2) = 0x33;
      *(undefined4 *)(&DAT_00203ee0 + iVar2) = 3;
      *(double *)(&DAT_00203ed8 + iVar2) = (double)(fVar1 + (float)(3 - iVar3) * 5.0);
      puVar4 = puVar5;
      for (iVar3 = 5; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *param_2;
        param_2 = param_2 + 1;
      }
      *puVar5 = 1;
      *(undefined4 *)(&DAT_00203ef4 + iVar2) = 0xffffffff;
      return local_8;
    }
    apcStack_30[4] = "No more authentication slots available\n";
    apcStack_30[3] = (char *)0x8a5b0;
    Con_Printf();
  }
  return -1;
}


// SV_FindEmptySlot  @ 000762cc
undefined4 SV_FindEmptySlot(undefined4 *param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  int **ppiVar6;
  char *pcStack_3c;
  undefined4 uStack_38;
  int *apiStack_34 [4];
  undefined4 **local_24;
  int local_14;
  int local_c;
  undefined4 **local_8;
  
  ppcVar4 = (char **)&stack0xffffffe0;
  local_8 = (undefined4 ***)0x0;
  local_c = 0;
  local_24 = &local_8;
  apiStack_34[3] = &local_c;
  apiStack_34[2] = (int *)0x762ff;
  SV_CountPlayers();
  local_c = local_c - (int)local_8;
  if ((param_2 == 0) || (local_24 = local_8, (float)(int)local_8 < (float)max_spectators._12_4_)) {
    local_14 = 0;
    if (0 < DAT_001ab4e8) {
      iVar1 = 0;
      do {
        piVar3 = (int *)(iVar1 + DAT_001ab4e4);
        if (((*piVar3 == 0) && (piVar3[1] == 0)) && (piVar3[3] == 0)) break;
        iVar1 = iVar1 + 0x5054;
        local_14 = local_14 + 1;
      } while (local_14 < DAT_001ab4e8);
      if (local_14 < DAT_001ab4e8) {
        *param_3 = local_14;
        *param_4 = piVar3;
        return 1;
      }
    }
    pcVar2 = "Server is full.\n";
  }
  else {
    puVar5 = param_1;
    ppiVar6 = apiStack_34;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppiVar6 = (int *)*puVar5;
      puVar5 = puVar5 + 1;
      ppiVar6 = ppiVar6 + 1;
    }
    uStack_38 = 0x76338;
    uStack_38 = NET_AdrToString();
    pcStack_3c = "%s:No space for spectator\n";
    ppcVar4 = &pcStack_3c;
    Con_Printf();
    pcVar2 = "No more spectators allowed.\n";
  }
  *(char **)((int)ppcVar4 + -4) = pcVar2;
  *(undefined4 **)((int)ppcVar4 + -8) = param_1;
  *(undefined4 *)((int)ppcVar4 + -0xc) = 0x763c4;
  SV_RejectConnection();
  return 0;
}


// SV_FindEntInPack  @ 00086cf8
uint SV_FindEntInPack(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  uVar1 = *param_2;
  if (0 < (int)uVar1) {
    uVar3 = param_2[9];
    piVar4 = (int *)(uVar3 + 4);
    uVar5 = uVar1 & 3;
    if (uVar5 != 0) {
      if (1 < uVar5) {
        uVar2 = uVar3;
        if (2 < uVar5) {
          if (*(int *)(uVar3 + 4) == param_1) {
            return uVar3;
          }
          uVar2 = uVar3 + 0x154;
          piVar4 = (int *)(uVar3 + 0x158);
          iVar6 = 1;
        }
        if (*piVar4 == param_1) {
          return uVar2;
        }
        uVar3 = uVar2 + 0x154;
        piVar4 = piVar4 + 0x55;
        iVar6 = iVar6 + 1;
      }
      if (*piVar4 == param_1) {
        return uVar3;
      }
      uVar3 = uVar3 + 0x154;
      piVar4 = piVar4 + 0x55;
      iVar6 = iVar6 + 1;
      if ((int)uVar1 <= iVar6) {
        return 0;
      }
    }
    do {
      if (*piVar4 == param_1) {
        return uVar3;
      }
      if (piVar4[0x55] == param_1) {
        return uVar3 + 0x154;
      }
      if (piVar4[0xaa] == param_1) {
        return uVar3 + 0x2a8;
      }
      if (piVar4[0xff] == param_1) {
        return uVar3 + 0x3fc;
      }
      uVar3 = uVar3 + 0x550;
      piVar4 = piVar4 + 0x154;
      iVar6 = iVar6 + 4;
    } while (iVar6 < (int)uVar1);
  }
  return 0;
}


// SV_FindModelNumbers  @ 0007318c
void SV_FindModelNumbers(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  sv_playermodel = -1;
  while( true ) {
    if ((&DAT_00183688)[iVar2] == 0) {
      return;
    }
    iVar1 = Q_strcasecmp((&DAT_00183688)[iVar2],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = iVar2;
    }
    if ((&DAT_00183688)[iVar2 + 1] == 0) {
      return;
    }
    iVar1 = Q_strcasecmp((&DAT_00183688)[iVar2 + 1],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = iVar2 + 1;
    }
    if ((&DAT_00183688)[iVar2 + 2] == 0) {
      return;
    }
    iVar1 = Q_strcasecmp((&DAT_00183688)[iVar2 + 2],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = iVar2 + 2;
    }
    if ((&DAT_00183688)[iVar2 + 3] == 0) break;
    iVar1 = Q_strcasecmp((&DAT_00183688)[iVar2 + 3],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = iVar2 + 3;
    }
    iVar2 = iVar2 + 4;
    if (0x1ff < iVar2) {
      return;
    }
  }
  return;
}


// SV_FindTouchedLeafs  @ 0008bac8
void SV_FindTouchedLeafs(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*param_2 != -2) {
    if (*param_2 < 0) {
      if (*(int *)(param_1 + 0x14) < 0x30) {
        *(short *)(param_1 + 0x18 + *(int *)(param_1 + 0x14) * 2) =
             (short)(((int)param_2 - *(int *)(DAT_00153668 + 0x8c)) * -0x55555555 >> 4) + -1;
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = 0x31;
      }
    }
    else {
      iVar3 = param_2[6];
      if (*(byte *)(iVar3 + 0x10) < 3) {
        iVar4 = (uint)*(byte *)(iVar3 + 0x10) * 4;
        fVar1 = *(float *)(iVar3 + 0xc);
        if (*(float *)(iVar4 + 0x144 + param_1) < fVar1) {
          uVar5 = 3;
          fVar2 = *(float *)(iVar4 + 0x150 + param_1);
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            uVar5 = 2;
          }
        }
        else {
          uVar5 = 1;
        }
      }
      else {
        uVar5 = BoxOnPlaneSide(param_1 + 0x144,param_1 + 0x150,iVar3);
      }
      if (((uVar5 & 3) != 0) && (*param_3 == -1)) {
        *param_3 = ((int)param_2 - *(int *)(DAT_00153668 + 0xa4)) * -0x33333333 >> 3;
      }
      if ((uVar5 & 1) != 0) {
        SV_FindTouchedLeafs(param_1,param_2[7],param_3);
      }
      if ((uVar5 & 2) != 0) {
        SV_FindTouchedLeafs(param_1,param_2[8],param_3);
      }
    }
  }
  return;
}


// SV_FinishCertificateCheck  @ 00075f04
undefined4 SV_FinishCertificateCheck(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int *piVar4;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = -1;
  local_10 = 0;
  if ((param_2 == 1) || (param_2 != 2)) {
    iVar1 = WON_CheckAuthentication(param_1,param_4,&local_8);
    if (iVar1 == 0) {
      pcVar2 = "Invalid authentication information.\n";
    }
    else if (local_8 == param_3) {
      if (local_8 == -1) {
        return 1;
      }
      iVar1 = SV_FilterUser(local_8);
      if (iVar1 == 0) {
        return 1;
      }
      pcVar2 = "You have been banned from this server.\n";
    }
    else {
      pcVar2 = "Invalid authentication userid.\n";
    }
  }
  else if (gfUseLANAuthentication == 0) {
    pcVar2 = "Invalid authentication message.\n";
  }
  else {
    iVar1 = Q_strlen(param_4);
    if (iVar1 == 0x20) {
      local_c = 0;
      if (0 < DAT_001ab4e8) {
        local_14 = DAT_001ab4e4 + 0x12ff;
        piVar3 = DAT_001ab4e4 + 3;
        piVar4 = DAT_001ab4e4;
        do {
          if ((((*piVar4 != 0) || (piVar3[-2] != 0)) || (*piVar3 != 0)) &&
             (iVar1 = Q_strnicmp(param_4,local_14,0x20), iVar1 == 0)) {
            local_10 = local_10 + 1;
          }
          local_c = local_c + 1;
          piVar3 = piVar3 + 0x1415;
          local_14 = local_14 + 0x1415;
          piVar4 = piVar4 + 0x1415;
        } while (local_c < DAT_001ab4e8);
      }
      if (local_10 < 5) {
        return 1;
      }
      pcVar2 = "CD Key already in use.\n";
    }
    else {
      pcVar2 = "Invalid CD Key.\n";
    }
  }
  SV_RejectConnection(param_1,pcVar2);
  return 0;
}


// SV_FixCheckBottom  @ 0007f24c
void SV_FixCheckBottom(int param_1)

{
  *(byte *)(param_1 + 0x225) = *(byte *)(param_1 + 0x225) | 4;
  return;
}


// SV_FixupGravityVelocity  @ 00080e20
void SV_FixupGravityVelocity(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x19c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 1.0;
  }
  *(float *)(param_1 + 0xa8) =
       *(float *)(param_1 + 0xa8) - (float)host_frametime * fVar1 * (float)sv_gravity._12_4_ * 0.5;
  SV_CheckVelocity(param_1);
  return;
}


// SV_FlushRedirect  @ 00077e54
void SV_FlushRedirect(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 **ppuVar3;
  undefined2 *apuStack_5c8 [4];
  undefined4 uStack_5b8;
  undefined1 local_5a8 [1428];
  undefined2 local_14 [2];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (sv_redirected == 2) {
    local_c = 0x591;
    local_8 = 0;
    local_10 = local_5a8;
    local_14[0] = 0;
    uStack_5b8 = 0xffffffff;
    apuStack_5c8[2] = (undefined2 *)0x77ea1;
    apuStack_5c8[3] = local_14;
    MSG_WriteLong();
    apuStack_5c8[2] = (undefined2 *)0x6c;
    apuStack_5c8[0] = (undefined2 *)0x77ea9;
    apuStack_5c8[1] = local_14;
    MSG_WriteByte();
    apuStack_5c8[0] = (undefined2 *)&outputbuf;
    MSG_WriteString(local_14);
    MSG_WriteByte(local_14,0);
    puVar2 = &sv_redirectto;
    ppuVar3 = apuStack_5c8;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = (undefined2 *)*puVar2;
      puVar2 = puVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    NET_SendPacket(1,local_8,local_10);
  }
  else if (sv_redirected == 1) {
    uStack_5b8 = 8;
    apuStack_5c8[3] = (undefined2 *)(host_client + 0x74);
    apuStack_5c8[2] = (undefined2 *)0x77f00;
    MSG_WriteByte();
    apuStack_5c8[2] = (undefined2 *)&outputbuf;
    apuStack_5c8[1] = (undefined2 *)(host_client + 0x74);
    apuStack_5c8[0] = (undefined2 *)0x77f18;
    MSG_WriteString();
  }
  outputbuf = 0;
  return;
}


// SV_FlyDirection  @ 0007f1e0
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


// SV_FlyMove  @ 00080340
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint SV_FlyMove(int *param_1,float param_2,int *param_3)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  float *pfVar13;
  int aiStack_134 [3];
  float local_128;
  int aiStack_124 [3];
  float local_118;
  uint uStack_114;
  int local_100;
  int local_f8;
  float *local_f4;
  uint local_c8;
  float local_c4;
  uint local_c0;
  int local_bc;
  float local_b4;
  float local_b0;
  float local_ac;
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
  float local_4c [15];
  float local_10;
  float local_c;
  float local_8;
  
  puVar9 = &stack0xfffffef0;
  bVar5 = *(byte *)((int)param_1 + 0x226);
  local_c8 = 0;
  local_c0 = 0;
  local_bc = 0;
  local_c4 = param_2;
  local_64 = (float)param_1[0x28];
  local_60 = (float)param_1[0x29];
  local_5c = (float)param_1[0x2a];
  local_58 = local_64;
  local_54 = local_60;
  local_50 = local_5c;
  do {
    if ((((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x28]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x28] == 0.0) << 0xe) >> 8)) == 0x40) &&
        ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x29]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_1[0x29] == 0.0) << 0xe) >> 8)) == 0x40)) &&
       (fVar2 = (float)param_1[0x2a],
       (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40)) {
      return local_c8;
    }
    local_b4 = local_c4 * (float)param_1[0x28] + (float)param_1[0x22];
    local_b0 = local_c4 * (float)param_1[0x29] + (float)param_1[0x23];
    local_ac = local_c4 * (float)param_1[0x2a] + (float)param_1[0x24];
    *(uint *)(puVar9 + -4) = (uint)((bVar5 & 0x80) != 0);
    *(int **)(puVar9 + -8) = param_1;
    *(undefined4 *)(puVar9 + -0xc) = 0;
    *(float **)(puVar9 + -0x10) = &local_b4;
    *(int **)(puVar9 + -0x14) = param_1 + 0x5a;
    *(int **)(puVar9 + -0x18) = param_1 + 0x57;
    *(int **)(puVar9 + -0x1c) = param_1 + 0x22;
    *(int **)(puVar9 + -0x20) = local_a8;
    *(undefined4 *)(puVar9 + -0x24) = 0x804b8;
    SV_Move();
    if (local_a8[0] != 0) {
      param_1[0x28] = vec3_origin;
      param_1[0x29] = DAT_000b2e2c;
      param_1[0x2a] = DAT_000b2e30;
      return 4;
    }
    if (0x3f < (byte)((local_98 < 0.0 | (byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_98 == 0.0) << 0xe) >> 8)) - 1)) {
      local_c0 = 0;
      param_1[0x22] = local_94;
      param_1[0x23] = local_90;
      param_1[0x24] = local_8c;
      local_64 = (float)param_1[0x28];
      local_60 = (float)param_1[0x29];
      local_5c = (float)param_1[0x2a];
    }
    if ((byte)(1.0 < local_98 | (byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_98 == 1.0) << 0xe) >> 8)) == 0x40) {
      return local_c8;
    }
    if (local_78 == 0) {
      *(char **)(puVar9 + -8) = "SV_FlyMove: !trace.ent";
      *(undefined4 *)(puVar9 + -0xc) = 0x80580;
      Sys_Error();
    }
    if (0.7 < local_80) {
      local_c8 = local_c8 | 1;
      if (((*(int *)(local_78 + 0x18c) == 4) || (*(int *)(local_78 + 0x188) == 0xd)) ||
         ((*(int *)(local_78 + 0x18c) == 3 || ((*(byte *)(param_1 + 0x89) & 8) != 0)))) {
        *(byte *)((int)param_1 + 0x225) = *(byte *)((int)param_1 + 0x225) | 2;
        param_1[0x87] = local_78;
      }
    }
    if (((byte)((byte)((ushort)((ushort)NAN(local_80) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_80 == 0.0) << 0xe) >> 8)) == 0x40) &&
       (local_c8 = local_c8 | 2, param_3 != (int *)0x0)) {
      piVar10 = local_a8;
      piVar12 = param_3;
      for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar12 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar12 = piVar12 + 1;
      }
    }
    *(int **)(puVar9 + -8) = local_a8;
    *(int *)(puVar9 + -0xc) = local_78;
    *(int **)(puVar9 + -0x10) = param_1;
    *(undefined4 *)(puVar9 + -0x14) = 0x80620;
    SV_Impact();
    if (*param_1 != 0) {
      return local_c8;
    }
    local_c4 = local_c4 - local_c4 * local_98;
    if (4 < (int)local_c0) {
      param_1[0x28] = vec3_origin;
      param_1[0x29] = DAT_000b2e2c;
      param_1[0x2a] = DAT_000b2e30;
      return local_c8;
    }
    pfVar13 = local_4c;
    pfVar13[local_c0 * 3] = local_88;
    local_4c[local_c0 * 3 + 1] = local_84;
    local_4c[local_c0 * 3 + 2] = local_80;
    local_c0 = local_c0 + 1;
    if ((param_1[0x62] == 3) &&
       (((*(byte *)((int)param_1 + 0x225) & 2) == 0 ||
        (fVar2 = (float)param_1[0x68],
        (byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) != 0x40)))) {
      iVar6 = 0;
      if (0 < (int)local_c0) {
        local_f8 = 0;
        if ((local_c0 & 1) != 0) {
          if (local_4c[2] <= 0.7) {
            *(float *)(puVar9 + -8) = (1.0 - (float)param_1[0x68]) * (float)sv_bounce._12_4_ + 1.0;
            *(float **)(puVar9 + -0xc) = &local_70;
            *(float **)(puVar9 + -0x10) = pfVar13;
            *(float **)(puVar9 + -0x14) = &local_64;
            *(undefined4 *)(puVar9 + -0x18) = 0x807c2;
            ClipVelocity();
          }
          else {
            *(undefined4 *)(puVar9 + -8) = 0x3f800000;
            *(float **)(puVar9 + -0xc) = &local_70;
            *(float **)(puVar9 + -0x10) = pfVar13;
            *(float **)(puVar9 + -0x14) = &local_64;
            *(undefined4 *)(puVar9 + -0x18) = 0x80765;
            ClipVelocity();
            local_64 = local_70;
            local_60 = local_6c;
            local_5c = local_68;
          }
          pfVar13 = local_4c + 3;
          local_f8 = 0xc;
          iVar6 = 1;
          if ((int)local_c0 < 2) goto LAB_00080918;
        }
        do {
          if (*(float *)((int)local_4c + local_f8 + 8) <= 0.7) {
            *(float *)(puVar9 + -8) = (1.0 - (float)param_1[0x68]) * (float)sv_bounce._12_4_ + 1.0;
            *(float **)(puVar9 + -0xc) = &local_70;
            *(float **)(puVar9 + -0x10) = pfVar13;
            *(float **)(puVar9 + -0x14) = &local_64;
            *(undefined4 *)(puVar9 + -0x18) = 0x80868;
            ClipVelocity();
          }
          else {
            *(undefined4 *)(puVar9 + -8) = 0x3f800000;
            *(float **)(puVar9 + -0xc) = &local_70;
            *(float **)(puVar9 + -0x10) = pfVar13;
            *(float **)(puVar9 + -0x14) = &local_64;
            *(undefined4 *)(puVar9 + -0x18) = 0x80811;
            ClipVelocity();
            local_64 = local_70;
            local_60 = local_6c;
            local_5c = local_68;
          }
          if (*(float *)((int)local_4c + local_f8 + 0x14) <= 0.7) {
            *(float *)(puVar9 + -8) = (1.0 - (float)param_1[0x68]) * (float)sv_bounce._12_4_ + 1.0;
            *(float **)(puVar9 + -0xc) = &local_70;
            *(float **)(puVar9 + -0x10) = pfVar13 + 3;
            *(float **)(puVar9 + -0x14) = &local_64;
            *(undefined4 *)(puVar9 + -0x18) = 0x808fc;
            ClipVelocity();
          }
          else {
            *(undefined4 *)(puVar9 + -8) = 0x3f800000;
            *(float **)(puVar9 + -0xc) = &local_70;
            *(float **)(puVar9 + -0x10) = pfVar13 + 3;
            *(float **)(puVar9 + -0x14) = &local_64;
            *(undefined4 *)(puVar9 + -0x18) = 0x808a4;
            ClipVelocity();
            local_64 = local_70;
            local_60 = local_6c;
            local_5c = local_68;
          }
          pfVar13 = pfVar13 + 6;
          local_f8 = local_f8 + 0x18;
          iVar6 = iVar6 + 2;
        } while (iVar6 < (int)local_c0);
      }
LAB_00080918:
      param_1[0x28] = (int)local_70;
      param_1[0x29] = (int)local_6c;
      param_1[0x2a] = (int)local_68;
      local_64 = local_70;
      local_60 = local_6c;
      local_5c = local_68;
    }
    else {
      uVar11 = 0;
      if (0 < (int)local_c0) {
        uVar11 = 0;
        local_f4 = pfVar13;
        do {
          *(undefined4 *)(puVar9 + -8) = 0x3f800000;
          *(float **)(puVar9 + -0xc) = &local_70;
          *(float **)(puVar9 + -0x10) = local_f4;
          *(float **)(puVar9 + -0x14) = &local_64;
          *(undefined4 *)(puVar9 + -0x18) = 0x8097d;
          ClipVelocity();
          uVar7 = 0;
          if (0 < (int)local_c0) {
            local_100 = 0;
            uVar1 = local_c0 & 3;
            uVar8 = uVar7;
            if (uVar1 == 0) goto LAB_00080ac4;
            if (1 < uVar1) {
              if (2 < uVar1) {
                if ((uVar11 != 0) &&
                   (fVar2 = local_68 * local_4c[2] + local_6c * local_4c[1] + local_70 * local_4c[0]
                   , (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1))
                goto LAB_00080be8;
                local_100 = 0xc;
                uVar7 = 1;
              }
              if ((uVar7 != uVar11) &&
                 (fVar2 = local_68 * *(float *)((int)local_4c + local_100 + 8) +
                          local_6c * *(float *)((int)local_4c + local_100 + 4) +
                          local_70 * *(float *)((int)pfVar13 + local_100),
                 (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1))
              goto LAB_00080be8;
              local_100 = local_100 + 0xc;
              uVar7 = uVar7 + 1;
            }
            if ((uVar7 == uVar11) ||
               (fVar2 = local_68 * *(float *)((int)local_4c + local_100 + 8) +
                        local_6c * *(float *)((int)local_4c + local_100 + 4) +
                        local_70 * *(float *)((int)pfVar13 + local_100),
               (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
              local_100 = local_100 + 0xc;
              while (uVar8 = uVar7 + 1, uVar7 = uVar8, (int)uVar8 < (int)local_c0) {
LAB_00080ac4:
                if ((uVar8 != uVar11) &&
                   (fVar2 = local_68 * *(float *)((int)local_4c + local_100 + 8) +
                            local_6c * *(float *)((int)local_4c + local_100 + 4) +
                            local_70 * *(float *)((int)pfVar13 + local_100), uVar7 = uVar8,
                   (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1)) break;
                uVar7 = uVar8 + 1;
                if ((uVar7 != uVar11) &&
                   (fVar2 = local_68 * *(float *)((int)local_4c + local_100 + 0x14) +
                            local_6c * *(float *)((int)local_4c + local_100 + 0x10) +
                            local_70 * *(float *)((int)pfVar13 + local_100 + 0xc),
                   (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1)) break;
                uVar7 = uVar8 + 2;
                if ((uVar7 != uVar11) &&
                   (fVar2 = local_68 * *(float *)((int)local_4c + local_100 + 0x20) +
                            local_6c * *(float *)((int)local_4c + local_100 + 0x1c) +
                            local_70 * *(float *)((int)pfVar13 + local_100 + 0x18),
                   (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1)) break;
                uVar7 = uVar8 + 3;
                if ((uVar7 != uVar11) &&
                   (fVar2 = local_68 * *(float *)((int)local_4c + local_100 + 0x2c) +
                            local_6c * *(float *)((int)local_4c + local_100 + 0x28) +
                            local_70 * *(float *)((int)pfVar13 + local_100 + 0x24),
                   (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1)) break;
                local_100 = local_100 + 0x30;
              }
            }
          }
LAB_00080be8:
          if (uVar7 == local_c0) break;
          local_f4 = local_f4 + 3;
          uVar11 = uVar11 + 1;
        } while ((int)uVar11 < (int)local_c0);
      }
      if (uVar11 == local_c0) {
        if (local_c0 != 2) {
          return local_c8;
        }
        *(float **)(puVar9 + -8) = &local_10;
        *(float **)(puVar9 + -0xc) = local_4c + 3;
        *(float **)(puVar9 + -0x10) = pfVar13;
        *(undefined4 *)(puVar9 + -0x14) = 0x80c4d;
        CrossProduct();
        fVar2 = (float)param_1[0x28];
        fVar3 = (float)param_1[0x29];
        fVar4 = (float)param_1[0x2a];
        *(int **)(puVar9 + -0x14) = param_1 + 0x28;
        *(float *)(puVar9 + -0x18) = local_8 * fVar4 + local_c * fVar3 + local_10 * fVar2;
        *(float **)(puVar9 + -0x1c) = &local_10;
        *(undefined4 *)(puVar9 + -0x20) = 0x80c86;
        VectorScale();
      }
      else {
        param_1[0x28] = (int)local_70;
        param_1[0x29] = (int)local_6c;
        param_1[0x2a] = (int)local_68;
      }
      if ((float)param_1[0x2a] * local_50 +
          (float)param_1[0x29] * local_54 + (float)param_1[0x28] * local_58 <= 0.0) {
        param_1[0x28] = vec3_origin;
        param_1[0x29] = DAT_000b2e2c;
        param_1[0x2a] = DAT_000b2e30;
        return local_c8;
      }
    }
    puVar9 = puVar9 + -4;
    local_bc = local_bc + 1;
    if (3 < local_bc) {
      return local_c8;
    }
  } while( true );
}


// SV_Frame  @ 0007df10
void SV_Frame(void)

{
  int iVar1;
  
  if (sv != 0) {
    DAT_00152b44 = (float)host_frametime;
    DAT_00153594 = DAT_0015358c;
    SV_CheckCmdTimes();
    SV_ReadPackets();
    iVar1 = SV_IsSimulating();
    if (iVar1 != 0) {
      SV_Physics();
      DAT_0015358c = DAT_0015358c + host_frametime;
    }
    SV_QueryMovevarsChanged();
    SV_RequestMissingResourcesFromClients();
    WON_HandleServerAuthMsgs();
    Master_Heartbeat();
    SV_CheckTimeouts();
    SV_SendClientMessages();
    SV_GatherStatistics();
  }
  return;
}


// SV_FullClientUpdate  @ 00078e04
void SV_FullClientUpdate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_104 [256];
  
  iVar1 = param_1 - DAT_001ab4e4;
  Q_strcpy(local_104,param_1 + 0x4af4);
  Info_RemovePrefixedKeys(local_104,0x5f);
  MSG_WriteByte(param_2,0xd);
  MSG_WriteByte(param_2,iVar1 * -0x3356e4c3 >> 2);
  MSG_WriteLong(param_2,*(undefined4 *)(param_1 + 0x4aec));
  MSG_WriteString(param_2,local_104);
  return;
}


// SV_GatherStatistics  @ 000727b4
void SV_GatherStatistics(void)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  float *local_18;
  int local_10;
  int local_c [2];
  
  if ((byte)((realtime < DAT_001ab518 |
              (byte)((ushort)((ushort)(NAN(realtime) || NAN(DAT_001ab518)) << 10) >> 8) |
             (byte)((ushort)((ushort)(realtime == DAT_001ab518) << 0xe) >> 8)) - 1) < 0x40) {
    if ((byte)(realtime < DAT_001ab520 |
               (byte)((ushort)((ushort)(NAN(realtime) || NAN(DAT_001ab520)) << 10) >> 8) |
              (byte)((ushort)((ushort)(realtime == DAT_001ab520) << 0xe) >> 8)) != 1) {
      DAT_001ab528 = DAT_001ab528 + 1;
      DAT_001ab520 = realtime + 60.0;
      SV_CountPlayers(local_c,0);
      DAT_001ab544 = ((float)local_c[0] * 100.0) / (float)(int)DAT_001ab4e8 + DAT_001ab544;
      if (0 < DAT_001ab528) {
        DAT_001ab548 = DAT_001ab544 / (float)DAT_001ab528;
      }
      if (local_c[0] < DAT_001ab53c) {
        DAT_001ab53c = local_c[0];
      }
      else if (DAT_001ab540 < local_c[0]) {
        DAT_001ab540 = local_c[0];
      }
      if ((int)(DAT_001ab4e8 - 1) <= local_c[0]) {
        DAT_001ab52c = DAT_001ab52c + 1;
      }
      if (local_c[0] < 2) {
        DAT_001ab530 = DAT_001ab530 + 1;
      }
      if (0 < DAT_001ab528) {
        DAT_001ab534 = ((float)DAT_001ab52c * 100.0) / (float)DAT_001ab528;
        DAT_001ab538 = ((float)DAT_001ab530 * 100.0) / (float)DAT_001ab528;
      }
      iVar4 = 0;
      fVar1 = 0.0;
      local_10 = 0;
      if (0 < (int)DAT_001ab4e8) {
        local_18 = (float *)(DAT_001ab4e4 + 0x92c);
        uVar3 = DAT_001ab4e8 & 3;
        piVar2 = DAT_001ab4e4;
        if (uVar3 == 0) goto LAB_000729d0;
        if (1 < uVar3) {
          if (2 < uVar3) {
            if ((*DAT_001ab4e4 != 0) && (DAT_001ab4e4[0x918] == 0)) {
              iVar4 = 1;
              fVar1 = (float)DAT_001ab4e4[0x92c];
            }
            local_10 = 1;
            local_18 = (float *)(DAT_001ab4e4 + 0x1d41);
            piVar2 = DAT_001ab4e4 + 0x1415;
          }
          if ((*piVar2 != 0) && (local_18[-0x14] == 0.0)) {
            iVar4 = iVar4 + 1;
            fVar1 = fVar1 + *local_18;
          }
          local_10 = local_10 + 1;
          local_18 = local_18 + 0x1415;
          piVar2 = piVar2 + 0x1415;
        }
        if ((*piVar2 != 0) && (local_18[-0x14] == 0.0)) {
          iVar4 = iVar4 + 1;
          fVar1 = fVar1 + *local_18;
        }
        local_18 = local_18 + 0x1415;
        piVar2 = piVar2 + 0x1415;
        for (local_10 = local_10 + 1; local_10 < (int)DAT_001ab4e8; local_10 = local_10 + 4) {
LAB_000729d0:
          if ((*piVar2 != 0) && (local_18[-0x14] == 0.0)) {
            iVar4 = iVar4 + 1;
            fVar1 = fVar1 + *local_18;
          }
          if ((piVar2[0x1415] != 0) && (local_18[0x1401] == 0.0)) {
            iVar4 = iVar4 + 1;
            fVar1 = fVar1 + local_18[0x1415];
          }
          if ((piVar2[0x282a] != 0) && (local_18[0x2816] == 0.0)) {
            iVar4 = iVar4 + 1;
            fVar1 = fVar1 + local_18[0x282a];
          }
          if ((piVar2[0x3c3f] != 0) && (local_18[0x3c2b] == 0.0)) {
            iVar4 = iVar4 + 1;
            fVar1 = fVar1 + local_18[0x3c3f];
          }
          local_18 = local_18 + 0x5054;
          piVar2 = piVar2 + 0x5054;
        }
      }
      if (iVar4 == 0) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = fVar1 / (float)iVar4;
      }
      DAT_001ab558 = fVar1 + DAT_001ab558;
      if (0 < DAT_001ab528) {
        DAT_001ab55c = DAT_001ab558 / (float)DAT_001ab528;
      }
      if (0 < DAT_001ab54c) {
        DAT_001ab554 = DAT_001ab550 / (float)DAT_001ab54c;
      }
    }
  }
  else {
    SV_CountPlayers(local_c,0);
    DAT_001ab518 = realtime + 3600.0;
    Q_memset(&DAT_001ab528,0,0x38);
    DAT_001ab540 = local_c[0];
    DAT_001ab53c = local_c[0];
  }
  return;
}


// SV_GetCustomChunk  @ 0007d87c
undefined4 SV_GetCustomChunk(int *param_1)

{
  float fVar1;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      return 0x80;
    }
    fVar1 = (float)*(double *)(param_1 + 0x10);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      if (9900.0 < fVar1) {
        return 0x100;
      }
      if (4900.0 < fVar1) {
        return 0xc0;
      }
      if ((byte)(3400.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 3400.0) << 0xe) >> 8)) == 1) {
        return 0x80;
      }
    }
  }
  return 0x40;
}


// SV_GetFragmentSize  @ 00075a98
int SV_GetFragmentSize(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[3] == 0)) || (param_1[2] == 0)) {
    iVar2 = 0x400;
  }
  else {
    uVar1 = Info_ValueForKey(param_1 + 0x12bd,"cl_dlmax");
    iVar2 = Q_strlen(uVar1);
    if (iVar2 == 0) {
      iVar2 = 0x80;
    }
    else {
      iVar2 = Q_atoi(uVar1);
      iVar3 = 0x40;
      if (0x3f < iVar2) {
        iVar3 = iVar2;
      }
      iVar2 = 0x400;
      if (iVar3 < 0x401) {
        iVar2 = iVar3;
      }
    }
  }
  return iVar2;
}


// SV_GetModInfo  @ 00076e10
int SV_GetModInfo(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 param_7)

{
  if (gmodinfo == 0) {
    Q_strcpy(param_1,&DAT_000aa5fc);
    Q_strcpy(param_2,&DAT_000aa5fc);
    Q_strcpy(param_7,&DAT_000aa5fc);
    *param_3 = 1;
    *param_4 = 0;
    *param_5 = 1;
    *param_6 = 0;
  }
  else {
    Q_strcpy(param_1,&DAT_00385d64);
    Q_strcpy(param_2,&DAT_00385e64);
    Q_strcpy(param_7,&DAT_00385f64);
    *param_3 = DAT_00385f84;
    *param_4 = DAT_00385f88;
    *param_5 = DAT_00385f8c;
    *param_6 = DAT_00385f90;
  }
  return gmodinfo;
}


// SV_GetNetInfo  @ 00079d98
void SV_GetNetInfo(int param_1,uint *param_2,uint *param_3)

{
  double dVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 local_14;
  
  iVar3 = (param_1 - DAT_001ab4e4) * -0x3356e4c3 >> 2;
  dVar1 = *(double *)(param_1 + 0x24c0);
  if ((byte)(realtime < dVar1 | (byte)((ushort)((ushort)(NAN(realtime) || NAN(dVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(realtime == dVar1) << 0xe) >> 8)) != 1) {
    *(double *)(param_1 + 0x24c0) = realtime + 2.0;
    uVar2 = SV_CalcPing(param_1);
    *(undefined2 *)(lastping_204 + iVar3 * 2) = uVar2;
    local_14 = (undefined1)(int)ROUND(*(float *)(param_1 + 0x24b4));
    lastloss_205[iVar3] = local_14;
  }
  *param_2 = (uint)*(ushort *)(lastping_204 + iVar3 * 2);
  *param_3 = (uint)(byte)lastloss_205[iVar3];
  return;
}


// SV_GetPlayerHulls  @ 00057ae8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_GetPlayerHulls(void)

{
  int iVar1;
  
  iVar1 = (*_DAT_003862d8)(0,&player_mins,&player_maxs);
  if (iVar1 != 0) {
    iVar1 = (*_DAT_003862d8)(1,&DAT_000b2ecc,&DAT_000b2f0c);
    if (iVar1 != 0) {
      iVar1 = (*_DAT_003862d8)(2,&DAT_000b2ed8,&DAT_000b2f18);
      if (iVar1 != 0) {
        (*_DAT_003862d8)(3,&DAT_000b2ee4,&DAT_000b2f24);
      }
    }
  }
  return;
}


// SV_GetTrueMinMax  @ 00086c58
void SV_GetTrueMinMax(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (((((host_client[0x13d3] != 0) && (host_client[0x13d4] != 0)) &&
       ((byte)((float)sv_unlag._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
      ((1 < DAT_001ab4e8 && (*host_client != 0)))) && ((-1 < param_1 && (param_1 < DAT_001ab4e8))))
  {
    iVar1 = param_1 * 0x48;
    if (((&truepositions)[param_1 * 0x12] != 0) && (*(int *)(&DAT_001fab44 + iVar1) != 0)) {
      *param_2 = &DAT_001fab6c + iVar1;
      *param_3 = &DAT_001fab78 + iVar1;
    }
  }
  return;
}


// SV_GetTrueOrigin  @ 00086ba8
void SV_GetTrueOrigin(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (((((host_client[0x13d3] != 0) && (host_client[0x13d4] != 0)) &&
       ((byte)((float)sv_unlag._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) &&
      ((1 < DAT_001ab4e8 && (*host_client != 0)))) && ((-1 < param_1 && (param_1 < DAT_001ab4e8))))
  {
    iVar1 = param_1 * 0x48;
    if (((&truepositions)[param_1 * 0x12] != 0) && (*(int *)(&DAT_001fab44 + iVar1) != 0)) {
      *param_2 = *(undefined4 *)(&DAT_001fab54 + iVar1);
      param_2[1] = *(undefined4 *)(&DAT_001fab58 + iVar1);
      param_2[2] = *(undefined4 *)(&DAT_001fab5c + iVar1);
    }
  }
  return;
}


// SV_HandleRconPacket  @ 0007dd6c
void SV_HandleRconPacket(void)

{
  undefined4 uVar1;
  int iVar2;
  
  MSG_BeginReading();
  MSG_ReadLong();
  uVar1 = MSG_ReadStringLine();
  Cmd_TokenizeString(uVar1);
  uVar1 = Cmd_Argv(0);
  iVar2 = Q_strcmp(uVar1,&DAT_000ab433);
  if (iVar2 == 0) {
    SV_Rcon(&net_from);
  }
  return;
}


// SV_HasEventsInQueue  @ 00079d20
undefined4 SV_HasEventsInQueue(int param_1)

{
  short *psVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    psVar1 = (short *)(param_1 + 0x34e4);
    do {
      if (((((*psVar1 != 0) || (psVar1[0x2c] != 0)) || (psVar1[0x58] != 0)) ||
          ((psVar1[0x84] != 0 || (psVar1[0xb0] != 0)))) ||
         ((psVar1[0xdc] != 0 || ((psVar1[0x108] != 0 || (psVar1[0x134] != 0)))))) {
        return 1;
      }
      psVar1 = psVar1 + 0x160;
      iVar2 = iVar2 + 8;
    } while (iVar2 < 0x40);
  }
  return 0;
}


// SV_HashString  @ 0007368c
uint SV_HashString(char *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = *(int *)(__ctype_tolower + cVar1 * 4) + uVar2 * 2;
    cVar1 = *param_1;
  }
  return uVar2 % param_2;
}


// SV_HitgroupForStudioHull  @ 00060260
undefined4 SV_HitgroupForStudioHull(int param_1)

{
  return *(undefined4 *)(studio_hull_hitgroup + param_1 * 4);
}


// SV_HullForBeam  @ 0008b0f4
undefined4 * SV_HullForBeam(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float local_10;
  float local_c;
  float local_8;
  
  beam_planes = *param_2 - *param_1;
  DAT_000dc504 = param_2[1] - param_1[1];
  DAT_000dc508 = param_2[2] - param_1[2];
  VectorNormalize(&beam_planes);
  DAT_000dc514 = beam_planes;
  DAT_000dc518 = DAT_000dc504;
  DAT_000dc51c = DAT_000dc508;
  DAT_000dc50c = param_2[2] * DAT_000dc508 + param_2[1] * DAT_000dc504 + *param_2 * beam_planes;
  DAT_000dc520 = param_1[2] * DAT_000dc508 + DAT_000dc504 * param_1[1] + beam_planes * *param_1;
  fVar1 = ABS(DAT_000dc508);
  if ((byte)((0.9 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.9) << 0xe) >> 8)) - 1) < 0x40) {
    local_10 = 1.0;
    local_8 = 0.0;
  }
  else {
    local_8 = 1.0;
    local_10 = 0.0;
  }
  local_c = 0.0;
  CrossProduct(&beam_planes,&local_10,&DAT_000dc528);
  VectorNormalize(&DAT_000dc528);
  DAT_000dc53c = DAT_000dc528;
  DAT_000dc540 = DAT_000dc52c;
  DAT_000dc544 = DAT_000dc530;
  DAT_000dc534 = (param_1[2] + DAT_000dc530) * DAT_000dc530 +
                 (param_1[1] + DAT_000dc52c) * DAT_000dc52c +
                 (*param_1 + DAT_000dc528) * DAT_000dc528;
  local_10 = *param_1 - DAT_000dc528;
  local_c = param_1[1] - DAT_000dc52c;
  local_8 = param_1[2] - DAT_000dc530;
  DAT_000dc548 = DAT_000dc528 * local_10 + local_c * DAT_000dc52c + local_8 * DAT_000dc530;
  CrossProduct(&DAT_000dc528,&beam_planes,&DAT_000dc550);
  VectorNormalize(&DAT_000dc550);
  DAT_000dc564 = DAT_000dc550;
  DAT_000dc568 = DAT_000dc554;
  DAT_000dc56c = DAT_000dc558;
  DAT_000dc50c = ABS(DAT_000dc504 * param_3[1]) + ABS(beam_planes * *param_3) +
                 ABS(DAT_000dc508 * param_3[2]) + DAT_000dc50c;
  DAT_000dc520 = DAT_000dc520 -
                 (ABS(DAT_000dc518 * param_3[1]) + ABS(DAT_000dc514 * *param_3) +
                 ABS(DAT_000dc51c * param_3[2]));
  DAT_000dc534 = ABS(DAT_000dc52c * param_3[1]) + ABS(DAT_000dc528 * *param_3) +
                 ABS(DAT_000dc530 * param_3[2]) + DAT_000dc534;
  DAT_000dc548 = DAT_000dc548 -
                 (ABS(DAT_000dc540 * param_3[1]) + ABS(DAT_000dc53c * *param_3) +
                 ABS(DAT_000dc544 * param_3[2]));
  DAT_000dc55c = ABS(DAT_000dc554 * param_3[1]) + ABS(DAT_000dc550 * *param_3) +
                 ABS(DAT_000dc558 * param_3[2]) +
                 (param_1[2] + DAT_000dc558) * DAT_000dc558 +
                 (param_1[1] + DAT_000dc554) * DAT_000dc554 +
                 (*param_1 + DAT_000dc550) * DAT_000dc550;
  DAT_000dc570 = ((param_1[2] - DAT_000dc558) * DAT_000dc558 +
                 (param_1[1] - DAT_000dc554) * DAT_000dc554 +
                 (*param_1 - DAT_000dc550) * DAT_000dc550) -
                 (ABS(DAT_000dc554 * param_3[1]) + ABS(DAT_000dc550 * *param_3) +
                 ABS(DAT_000dc558 * param_3[2]));
  return &beam_hull;
}


// SV_HullForBox  @ 0008b09c
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


// SV_HullForBsp  @ 0008b458
int SV_HullForBsp(int param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  
  iVar2 = *(int *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4);
  if (iVar2 == 0) {
    Sys_Error("Hit a %s with no model (%s)",*(int *)(param_1 + 0x80) + pr_strings,
              *(int *)(param_1 + 0x138) + pr_strings);
  }
  else if (*(int *)(iVar2 + 0x44) == 0) goto LAB_0008b508;
  Sys_Error("Hit a %s with no model (%s)",*(int *)(param_1 + 0x80) + pr_strings,
            *(int *)(param_1 + 0x138) + pr_strings);
  Sys_Error("MOVETYPE_PUSH with a non bsp model");
LAB_0008b508:
  fVar1 = *param_3 - *param_2;
  fVar3 = param_3[2] - param_2[2];
  if (fVar1 <= 8.0) {
    iVar4 = iVar2 + 0xd0;
    *param_4 = *(float *)(iVar2 + 0xe0);
    param_4[1] = *(float *)(iVar2 + 0xe4);
    fVar1 = *(float *)(iVar2 + 0xe8);
  }
  else {
    if (((byte)(36.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 36.0) << 0xe) >> 8)) == 1) ||
       ((byte)(36.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 36.0) << 0xe) >> 8)) == 1)) {
      iVar4 = iVar2 + 0x120;
      if ((byte)(36.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 36.0) << 0xe) >> 8)) != 1) {
        iVar4 = iVar2 + 0xf8;
      }
    }
    else {
      iVar4 = iVar2 + 0x148;
    }
    *param_4 = *(float *)(iVar4 + 0x10) - *param_2;
    param_4[1] = *(float *)(iVar4 + 0x14) - param_2[1];
    fVar1 = *(float *)(iVar4 + 0x18) - param_2[2];
  }
  param_4[2] = fVar1;
  *param_4 = *param_4 + *(float *)(param_1 + 0x88);
  param_4[1] = param_4[1] + *(float *)(param_1 + 0x8c);
  param_4[2] = param_4[2] + *(float *)(param_1 + 0x90);
  return iVar4;
}


// SV_HullForEntity  @ 0008b5f4
void SV_HullForEntity(int param_1,float *param_2,float *param_3,undefined4 *param_4)

{
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(param_1 + 0x18c) == 4) {
    if (*(int *)(param_1 + 0x188) != 7) {
      Sys_Error("SOLID_BSP without MOVETYPE_PUSH");
    }
    SV_HullForBsp(param_1,param_2,param_3,param_4);
  }
  else {
    local_10 = *(float *)(param_1 + 0x15c) - *param_3;
    local_c = *(float *)(param_1 + 0x160) - param_3[1];
    local_8 = *(float *)(param_1 + 0x164) - param_3[2];
    local_1c = *(float *)(param_1 + 0x168) - *param_2;
    local_18 = *(float *)(param_1 + 0x16c) - param_2[1];
    local_14 = *(float *)(param_1 + 0x170) - param_2[2];
    SV_HullForBox(&local_10,&local_1c);
    *param_4 = *(undefined4 *)(param_1 + 0x88);
    param_4[1] = *(undefined4 *)(param_1 + 0x8c);
    param_4[2] = *(undefined4 *)(param_1 + 0x90);
  }
  return;
}


// SV_HullForStudioModel  @ 00060498
void SV_HullForStudioModel
               (int param_1,float *param_2,float *param_3,undefined4 *param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  ushort **ppuVar3;
  undefined4 *puStack_74;
  int iStack_70;
  float *pfStack_6c;
  uint *puStack_68;
  ushort *puStack_64;
  undefined4 *puStack_60;
  float *pfStack_5c;
  float *pfStack_58;
  float *pfStack_54;
  float *pfStack_50;
  float local_30;
  uint local_2c;
  ushort local_26;
  byte local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_10;
  float local_c;
  float local_8;
  
  local_30 = 0.5;
  local_10 = *param_3 - *param_2;
  local_c = param_3[1] - param_2[1];
  local_8 = param_3[2] - param_2[2];
  bVar1 = false;
  pfStack_54 = (float *)&vec3_origin;
  pfStack_58 = (float *)0x604f1;
  pfStack_50 = &local_10;
  iVar2 = VectorCompare();
  if (((iVar2 != 0) && (((byte)DAT_00152bc4 & 1) == 0)) &&
     (bVar1 = true, (*(byte *)(param_1 + 0x224) & 8) != 0)) {
    if ((byte)((float)sv_clienttrace._12_4_ < 0.0 |
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
  if (((*(byte *)(*(int *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4) + 0x51) & 2) != 0) ||
     (bVar1)) {
    pfStack_54 = (float *)local_30;
    pfStack_5c = (float *)0x6057c;
    pfStack_58 = &local_10;
    pfStack_50 = &local_10;
    VectorScale();
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    if ((*(byte *)(param_1 + 0x224) & 8) == 0) {
      pfStack_50 = (float *)param_5;
      pfStack_54 = (float *)(param_1 + 0x1c0);
      pfStack_58 = (float *)(param_1 + 0x1bc);
      puStack_60 = (undefined4 *)(param_1 + 0x88);
      puStack_64 = (ushort *)(param_1 + 0xd0);
      ppuVar3 = &puStack_64;
      pfStack_5c = &local_10;
    }
    else {
      pfStack_50 = *(float **)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4);
      pfStack_54 = (float *)0x605b8;
      pstudiohdr = Mod_Extradata();
      local_20 = *(undefined4 *)(param_1 + 0xd0);
      pfStack_5c = (float *)(*(int *)(param_1 + 0x1a8) * 0xb0 +
                            pstudiohdr + *(int *)(pstudiohdr + 0xa8));
      local_1c = *(undefined4 *)(param_1 + 0xd4);
      local_18 = *(undefined4 *)(param_1 + 0xd8);
      pfStack_58 = (float *)local_24;
      puStack_60 = (undefined4 *)0x60600;
      pfStack_54 = (float *)&local_20;
      R_StudioPlayerBlend();
      local_26 = (ushort)local_24[0];
      local_2c = CONCAT31(local_2c._1_3_,0x7f);
      local_2c = local_2c & 0x7f7f7fff | 0x7f7f7f00;
      puStack_60 = param_5;
      puStack_64 = &local_26;
      puStack_68 = &local_2c;
      iStack_70 = param_1 + 0x88;
      ppuVar3 = (ushort **)&puStack_74;
      puStack_74 = &local_20;
      pfStack_6c = &local_10;
    }
    *(undefined4 *)((int)ppuVar3 + -4) = *(undefined4 *)(param_1 + 0x1a8);
    *(undefined4 *)((int)ppuVar3 + -8) = *(undefined4 *)(param_1 + 0x1b0);
    *(undefined4 *)((int)ppuVar3 + -0xc) =
         *(undefined4 *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4);
    *(undefined4 *)((int)ppuVar3 + -0x10) = 0x6068c;
    R_StudioHull();
  }
  else {
    *param_5 = 1;
    pfStack_50 = (float *)param_4;
    pfStack_54 = param_3;
    pfStack_58 = param_2;
    pfStack_5c = (float *)param_1;
    puStack_60 = (undefined4 *)0x606ab;
    SV_HullForEntity();
  }
  return;
}


// SV_HullPointContents  @ 0008be6c
int SV_HullPointContents(int *param_1,int param_2,float *param_3)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  
  while (-1 < param_2) {
    if ((param_2 < param_1[2]) || (param_1[3] < param_2)) {
      Sys_Error("SV_HullPointContents: bad node number");
    }
    piVar1 = (int *)(*param_1 + param_2 * 8);
    pfVar2 = (float *)(param_1[1] + *piVar1 * 0x14);
    if (*(byte *)(pfVar2 + 4) < 3) {
      fVar3 = param_3[*(byte *)(pfVar2 + 4)];
    }
    else {
      fVar3 = pfVar2[2] * param_3[2] + pfVar2[1] * param_3[1] + *pfVar2 * *param_3;
    }
    fVar3 = fVar3 - pfVar2[3];
    if ((byte)((0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
      param_2 = (int)(short)piVar1[1];
    }
    else {
      param_2 = (int)*(short *)((int)piVar1 + 6);
    }
  }
  return param_2;
}


// SV_Impact  @ 00080044
void SV_Impact(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  gGlobalVariables = (float)DAT_0015358c;
  if (((*(uint *)(param_1 + 0x224) | *(uint *)(param_2 + 0x224)) & 0x40000000) != 0) {
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x2c0);
  if ((uVar1 != 0) && (uVar2 = *(uint *)(param_2 + 0x2c0), uVar2 != 0)) {
    if (g_groupop == 0) {
      if ((uVar2 & uVar1) == 0) {
        return;
      }
    }
    else if ((g_groupop == 1) && ((uVar1 & uVar2) != 0)) {
      return;
    }
  }
  if (*(int *)(param_1 + 0x18c) != 0) {
    SV_SetGlobalTrace(param_3);
    (*DAT_00386230)(param_1,param_2);
  }
  if (*(int *)(param_2 + 0x18c) != 0) {
    SV_SetGlobalTrace(param_3);
    (*DAT_00386230)(param_2,param_1);
  }
  return;
}


// SV_InactivateClients  @ 0007d794
void SV_InactivateClients(void)

{
  int *piVar1;
  int *piVar2;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  if (0 < DAT_001ab4e8) {
    local_c = DAT_001ab4e4 + 0x13d5;
    piVar1 = DAT_001ab4e4 + 0x918;
    piVar2 = DAT_001ab4e4;
    do {
      if (((*piVar2 != 0) || (piVar1[-0x915] != 0)) || (piVar1[-0x917] != 0)) {
        *piVar2 = 0;
        piVar1[-0x915] = 1;
        piVar1[-0x917] = 0;
        piVar1[-0x916] = 0;
        if (*piVar1 == 0) {
          SZ_Clear(piVar2 + 0x1d);
          SZ_Clear(piVar2 + 0x944);
          COM_ClearCustomizationList(piVar2 + 0x13aa,0);
          Q_memset(local_c,0,0x100);
        }
      }
      local_8 = local_8 + 1;
      piVar1 = piVar1 + 0x1415;
      local_c = local_c + 0x1415;
      piVar2 = piVar2 + 0x1415;
    } while (local_8 < DAT_001ab4e8);
  }
  return;
}


// SV_Init  @ 0007e26c
void SV_Init(void)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  Cmd_AddCommand("banid",SV_BanId_f);
  Cmd_AddCommand("removeid",SV_RemoveId_f);
  Cmd_AddCommand("listid",SV_ListId_f);
  Cmd_AddCommand("writeid",SV_WriteId_f);
  Cmd_AddCommand("logaddress",SV_SetLogAddress_f);
  Cmd_AddCommand(&DAT_000ab4be,SV_ServerLog_f);
  Cmd_AddCommand("serverinfo",SV_Serverinfo_f);
  Cmd_AddCommand("localinfo",SV_Localinfo_f);
  Cmd_AddCommand("showinfo",SV_ShowServerinfo_f);
  Cmd_AddCommand(&DAT_000ac1c6,SV_User_f);
  Cmd_AddCommand("users",SV_Users_f);
  Cmd_AddCommand("dlfile",SV_BeginFileDownload_f);
  Cmd_AddCommand("ptrack",SV_PTrack_f);
  Cmd_AddCommand("addip",SV_AddIP_f);
  Cmd_AddCommand("removeip",SV_RemoveIP_f);
  Cmd_AddCommand("listip",SV_ListIP_f);
  Cmd_AddCommand("writeip",SV_WriteIP_f);
  Cmd_AddCommand("dropclient",SV_Drop_f);
  Cmd_AddCommand("spawn",SV_Spawn_f);
  Cmd_AddCommand(&DAT_000ac20e,SV_New_f);
  Cmd_AddCommand("sendents",SV_SendEnts_f);
  Cvar_RegisterVariable(sv_failuretime);
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
  Cvar_RegisterVariable(sv_challengetime);
  Cvar_RegisterVariable(timeout);
  Cvar_RegisterVariable(sv_clienttrace);
  Cvar_RegisterVariable(sv_zmax);
  Cvar_RegisterVariable(sv_wateramp);
  Cvar_RegisterVariable(sv_skyname);
  Cvar_RegisterVariable(sv_maxvelocity);
  Cvar_RegisterVariable(sv_cheats);
  Cvar_RegisterVariable(spectator_password);
  Cvar_RegisterVariable(max_spectators);
  Cvar_RegisterVariable(sv_spectalk);
  Cvar_RegisterVariable(sv_spectatormaxspeed);
  Cvar_RegisterVariable(sv_allow_download);
  Cvar_RegisterVariable(sv_allow_upload);
  Cvar_RegisterVariable(sv_minrate);
  Cvar_RegisterVariable(sv_maxrate);
  iVar2 = 0;
  local_c = 0;
  do {
    sprintf(localmodels + local_c,"*%i",iVar2);
    sprintf(localmodels + local_c + 5,"*%i",iVar2 + 1);
    sprintf(localmodels + local_c + 10,"*%i",iVar2 + 2);
    sprintf(localmodels + local_c + 0xf,"*%i",iVar2 + 3);
    sprintf(localmodels + local_c + 0x14,"*%i",iVar2 + 4);
    sprintf(localmodels + local_c + 0x19,"*%i",iVar2 + 5);
    sprintf(localmodels + local_c + 0x1e,"*%i",iVar2 + 6);
    sprintf(localmodels + local_c + 0x23,"*%i",iVar2 + 7);
    local_c = local_c + 0x28;
    iVar2 = iVar2 + 8;
  } while (iVar2 < 0x200);
  iVar2 = 0;
  if (0 < DAT_001ab4ec) {
    local_8 = 0;
    do {
      iVar1 = local_8 + DAT_001ab4e4;
      SV_ClearFrames(iVar1 + 0x34e0);
      Q_memset(iVar1,0,0x5054);
      *(int *)(iVar1 + 0x4d08) = iVar1 + 0x4c84;
      *(int *)(iVar1 + 0x4d04) = iVar1 + 0x4c84;
      *(int *)(iVar1 + 0x4d90) = iVar1 + 0x4d0c;
      *(int *)(iVar1 + 0x4d8c) = iVar1 + 0x4d0c;
      local_8 = local_8 + 0x5054;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_001ab4ec);
  }
  PM_Init(g_svmove);
  SV_AllocClientFrames();
  SV_InitDeltas();
  return;
}


// SV_InitBoxHull  @ 0008ae5c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SV_InitBoxHull(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *local_1c;
  int local_18;
  undefined1 *local_14;
  
  local_1c = &box_clipnodes;
  box_hull = &box_clipnodes;
  DAT_000dc3c4 = box_planes;
  DAT_000dc3c8 = 0;
  DAT_000dc3cc = 5;
  puVar3 = &box_hull;
  puVar4 = &beam_hull;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  DAT_000dc404 = &beam_planes;
  uVar5 = 0;
  local_14 = box_planes + 0x10;
  local_18 = 0;
  do {
    *local_1c = uVar5;
    *(undefined2 *)(&DAT_000dc444 + (uVar5 & 1) * 2 + uVar5 * 8) = 0xffff;
    if (uVar5 == 5) {
      _DAT_000dc46c = 0xfffe;
    }
    else {
      *(short *)(&DAT_000dc444 + (uVar5 & 1 ^ 1) * 2 + uVar5 * 8) = (short)uVar5 + 1;
    }
    *local_14 = (char)((int)uVar5 >> 1);
    *(undefined4 *)(box_planes + local_18 + ((int)uVar5 >> 1) * 4) = 0x3f800000;
    uVar1 = uVar5 + 1;
    (&DAT_000dc510)[local_18] = 5;
    local_1c[2] = uVar1;
    *(undefined2 *)(&DAT_000dc444 + (uVar1 & 1) * 2 + uVar1 * 8) = 0xffff;
    if (uVar1 == 5) {
      _DAT_000dc46c = 0xfffe;
    }
    else {
      *(short *)(&DAT_000dc444 + (uVar1 & 1 ^ 1) * 2 + uVar1 * 8) = (short)uVar1 + 1;
    }
    local_14[0x14] = (char)((int)uVar1 >> 1);
    *(undefined4 *)(box_planes + local_18 + ((int)uVar1 >> 1) * 4 + 0x14) = 0x3f800000;
    uVar1 = uVar5 + 2;
    (&DAT_000dc524)[local_18] = 5;
    local_1c[4] = uVar1;
    *(undefined2 *)(&DAT_000dc444 + (uVar1 & 1) * 2 + uVar1 * 8) = 0xffff;
    if (uVar1 == 5) {
      _DAT_000dc46c = 0xfffe;
    }
    else {
      *(short *)(&DAT_000dc444 + (uVar1 & 1 ^ 1) * 2 + uVar1 * 8) = (short)uVar1 + 1;
    }
    local_14[0x28] = (char)((int)uVar1 >> 1);
    *(undefined4 *)(box_planes + local_18 + ((int)uVar1 >> 1) * 4 + 0x28) = 0x3f800000;
    uVar5 = uVar5 + 3;
    (&DAT_000dc538)[local_18] = 5;
    local_14 = local_14 + 0x3c;
    local_18 = local_18 + 0x3c;
    local_1c = local_1c + 6;
  } while ((int)uVar5 < 6);
  return;
}


// SV_InitDeltas  @ 0007e09c
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


// SV_InitEncoders  @ 0007e210
void SV_InitEncoders(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  for (puVar2 = g_sv_delta; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    iVar1 = puVar2[3];
    iVar5 = iVar1 + 8;
    iVar3 = Q_strlen(iVar5);
    if (0 < iVar3) {
      uVar4 = DELTA_LookupEncoder(iVar5);
      *(undefined4 *)(iVar1 + 0x28) = uVar4;
    }
  }
  return;
}


// SV_InitStudioHull  @ 0005dfb4
void SV_InitStudioHull(void)

{
  short sVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint local_28;
  
  if (DAT_000cf164 == 0) {
    local_28 = 0;
    do {
      iVar4 = local_28 * 8;
      *(uint *)(studio_clipnodes + iVar4) = local_28;
      *(undefined2 *)(studio_clipnodes + (local_28 & 1) * 2 + iVar4 + 4) = 0xffff;
      sVar1 = (short)local_28;
      if (local_28 == 5) {
        studio_clipnodes._44_2_ = 0xfffe;
      }
      else {
        *(short *)(studio_clipnodes + (local_28 & 1 ^ 1) * 2 + iVar4 + 4) = sVar1 + 1;
      }
      uVar2 = local_28 + 1;
      iVar4 = uVar2 * 8;
      *(uint *)(studio_clipnodes + iVar4) = uVar2;
      *(undefined2 *)(studio_clipnodes + (uVar2 & 1) * 2 + iVar4 + 4) = 0xffff;
      if (uVar2 == 5) {
        studio_clipnodes._44_2_ = 0xfffe;
      }
      else {
        *(short *)(studio_clipnodes + (uVar2 & 1 ^ 1) * 2 + iVar4 + 4) = sVar1 + 2;
      }
      uVar2 = local_28 + 2;
      iVar4 = uVar2 * 8;
      *(uint *)(studio_clipnodes + iVar4) = uVar2;
      *(undefined2 *)(studio_clipnodes + (uVar2 & 1) * 2 + iVar4 + 4) = 0xffff;
      if (uVar2 == 5) {
        studio_clipnodes._44_2_ = 0xfffe;
      }
      else {
        *(short *)(studio_clipnodes + (uVar2 & 1 ^ 1) * 2 + iVar4 + 4) = sVar1 + 3;
      }
      local_28 = local_28 + 3;
    } while ((int)local_28 < 6);
    local_28 = 0;
    puVar3 = studio_planes;
    iVar4 = 0;
    do {
      *(undefined1 **)((int)&studio_hull + iVar4) = studio_clipnodes;
      *(undefined1 **)((int)&DAT_000cf164 + iVar4) = puVar3;
      *(undefined4 *)((int)&DAT_000cf168 + iVar4) = 0;
      *(undefined4 *)((int)&DAT_000cf16c + iVar4) = 5;
      *(undefined1 **)((int)&DAT_000cf188 + iVar4) = studio_clipnodes;
      *(undefined1 **)((int)&DAT_000cf18c + iVar4) = puVar3 + 0x78;
      *(undefined4 *)((int)&DAT_000cf190 + iVar4) = 0;
      *(undefined4 *)((int)&DAT_000cf194 + iVar4) = 5;
      *(undefined1 **)((int)&DAT_000cf1b0 + iVar4) = studio_clipnodes;
      *(undefined1 **)((int)&DAT_000cf1b4 + iVar4) = puVar3 + 0xf0;
      *(undefined4 *)((int)&DAT_000cf1b8 + iVar4) = 0;
      *(undefined4 *)((int)&DAT_000cf1bc + iVar4) = 5;
      *(undefined1 **)((int)&DAT_000cf1d8 + iVar4) = studio_clipnodes;
      *(undefined1 **)((int)&DAT_000cf1dc + iVar4) = puVar3 + 0x168;
      *(undefined4 *)((int)&DAT_000cf1e0 + iVar4) = 0;
      puVar3 = puVar3 + 0x1e0;
      *(undefined4 *)((int)&DAT_000cf1e4 + iVar4) = 5;
      local_28 = local_28 + 4;
      iVar4 = iVar4 + 0xa0;
    } while ((int)local_28 < 0x80);
  }
  return;
}


// SV_InvokeCallback  @ 00079754
void SV_InvokeCallback(void)

{
  SV_WriteDeltaHeader(DAT_001ab4c4,DAT_001ab4c8,DAT_001ab4cc,g_svdeltacallback,DAT_001ab4d0,
                      DAT_001ab4d4);
  return;
}


// SV_IsPlayerIndex  @ 00079790
undefined4 SV_IsPlayerIndex(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 1) || (DAT_001ab4e8 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// SV_IsSimulating  @ 0007deb8
undefined4 SV_IsSimulating(void)

{
  undefined4 uVar1;
  
  if ((DAT_00153584 == 0) && ((1 < DAT_001ab4e8 || ((key_dest == 0 && ((cls == 5 || (cls == 0)))))))
     ) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// SV_LinkContents  @ 0008bf20
undefined8 SV_LinkContents(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  piVar5 = (int *)param_1[7];
joined_r0x0008bf43:
  do {
    piVar7 = piVar5;
    if (piVar7 == param_1 + 6) {
      iVar8 = *param_1;
      if (iVar8 == -1) {
LAB_0008c119:
        iVar9 = -1;
      }
      else {
        if (param_2[iVar8] <= (float)param_1[1]) {
          if ((float)param_1[1] <= param_2[iVar8]) goto LAB_0008c119;
          iVar8 = param_1[3];
        }
        else {
          iVar8 = param_1[2];
        }
        iVar9 = SV_LinkContents(iVar8,param_2);
        iVar8 = iVar9;
      }
      goto LAB_0008c13a;
    }
    piVar5 = (int *)piVar7[1];
  } while (piVar7[0x61] != 0);
  uVar6 = piVar7[0xae];
  if (uVar6 == 0) goto LAB_0008bf9b;
  if (g_groupop == 0) {
    if ((uVar6 & g_groupmask) == 0) goto joined_r0x0008bf43;
  }
  else if ((g_groupop == 1) && ((uVar6 & g_groupmask) != 0)) goto joined_r0x0008bf43;
LAB_0008bf9b:
  if (((((*(int *)(&DAT_00183e88 + piVar7[0x4b] * 4) != 0) &&
        (*(int *)(*(int *)(&DAT_00183e88 + piVar7[0x4b] * 4) + 0x44) == 0)) &&
       (fVar1 = *param_2, fVar1 <= (float)piVar7[0x52])) &&
      ((fVar2 = param_2[1], fVar2 <= (float)piVar7[0x53] &&
       (fVar3 = param_2[2], fVar3 <= (float)piVar7[0x54])))) &&
     ((fVar4 = (float)piVar7[0x4f],
      (byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) != 1 &&
      ((fVar1 = (float)piVar7[0x50],
       (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1 &&
       (fVar1 = (float)piVar7[0x51],
       (byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1)))))) {
    if (200 < piVar7[0x62] + 100U) {
      Con_DPrintf("Invalid contents on trigger field: %s\n",piVar7[0x1e] + pr_strings);
    }
    iVar8 = SV_HullForBsp(piVar7 + -2,&vec3_origin,&vec3_origin,&local_10);
    local_1c = *param_2 - local_10;
    local_18 = param_2[1] - local_c;
    local_14 = param_2[2] - local_8;
    iVar8 = SV_HullPointContents(iVar8,*(undefined4 *)(iVar8 + 8),&local_1c);
    if (iVar8 != -1) {
      iVar9 = piVar7[0x62];
LAB_0008c13a:
      return CONCAT44(iVar8,iVar9);
    }
  }
  goto joined_r0x0008bf43;
}


// SV_LinkEdict  @ 0008bc64
void SV_LinkEdict(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *local_10;
  int local_8;
  
  if (param_1[2] != 0) {
    SV_UnlinkEdict(param_1);
  }
  if ((param_1 != DAT_00186f94) && (*param_1 == 0)) {
    (*DAT_00386244)(param_1);
    if ((param_1[0x62] == 0xc) && (iVar3 = param_1[0x85], iVar3 != 0)) {
      param_1[4] = *(int *)(iVar3 + 0x10);
      param_1[5] = *(int *)(iVar3 + 0x14);
      Q_memcpy(param_1 + 6,iVar3 + 0x18,0x60);
    }
    else {
      param_1[5] = 0;
      param_1[4] = -1;
      local_8 = -1;
      if (param_1[0x4d] != 0) {
        SV_FindTouchedLeafs(param_1,*(undefined4 *)(DAT_00153668 + 0xa4),&local_8);
      }
      if (0x30 < param_1[5]) {
        param_1[5] = 0;
        param_1[4] = local_8;
        Q_memset(param_1 + 6,0xff,0x60);
      }
    }
    if ((param_1[99] != 0) || (param_1[100] < -1)) {
      if ((param_1[99] == 4) &&
         ((*(int *)(&DAT_00183e88 + param_1[0x4d] * 4) == 0 &&
          (iVar3 = Q_strlen(param_1[0x4e] + pr_strings), iVar3 == 0)))) {
        Con_DPrintf("Inserted %s with no model\n",param_1[0x20] + pr_strings);
      }
      else {
        local_10 = &sv_areanodes;
        while (iVar3 = *local_10, iVar3 != -1) {
          fVar1 = (float)local_10[1];
          if ((float)param_1[iVar3 + 0x51] <= fVar1) {
            fVar2 = (float)param_1[iVar3 + 0x54];
            if ((byte)((fVar1 < fVar2 |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) break;
            local_10 = (int *)local_10[3];
          }
          else {
            local_10 = (int *)local_10[2];
          }
        }
        if (param_1[99] == 1) {
          local_10 = local_10 + 4;
        }
        else {
          local_10 = local_10 + 6;
        }
        InsertLinkBefore(param_1 + 2,local_10);
        if (param_2 != 0) {
          SV_TouchLinks(param_1,&sv_areanodes);
        }
      }
    }
  }
  return;
}


// SV_ListIP_f  @ 0007d5ac
void SV_ListIP_f(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int local_c;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  Con_Printf();
  local_c = 0;
  if (0 < numipfilters) {
    iVar3 = 0;
    do {
      uVar2 = *(uint *)((int)&DAT_001a74c4 + iVar3);
      fVar1 = *(float *)((int)&DAT_001a74cc + iVar3);
      uStack_7 = (undefined1)(uVar2 >> 8);
      uStack_6 = (undefined1)(uVar2 >> 0x10);
      uStack_5 = (undefined1)(uVar2 >> 0x18);
      if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        Con_Printf("%3i.%3i.%3i.%3i : permanent\n",uVar2 & 0xff,uStack_7,uStack_6,uStack_5);
      }
      else {
        Con_Printf("%3i.%3i.%3i.%3i : %.3f min\n",uVar2 & 0xff,uStack_7,uStack_6,uStack_5);
      }
      iVar3 = iVar3 + 0x10;
      local_c = local_c + 1;
    } while (local_c < numipfilters);
  }
  return;
}


// SV_ListId_f  @ 0007d1bc
void SV_ListId_f(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  Con_Printf();
  iVar3 = 0;
  if (0 < numuserfilters) {
    iVar2 = 0;
    do {
      fVar1 = *(float *)((int)&DAT_00192468 + iVar2);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        Con_Printf("%u : permanent\n",*(undefined4 *)((int)&userfilters + iVar2));
      }
      else {
        Con_Printf("%u : %.3f min\n",*(undefined4 *)((int)&userfilters + iVar2));
      }
      iVar2 = iVar2 + 0xc;
      iVar3 = iVar3 + 1;
    } while (iVar3 < numuserfilters);
  }
  return;
}


// SV_LoadEntities  @ 0007c5b4
void SV_LoadEntities(void)

{
  ED_LoadFromFile(*(undefined4 *)(DAT_00153668 + 0x180));
  return;
}


// SV_Localinfo_f  @ 00072e34
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
      if (*pcVar2 != '*') {
        uVar3 = Cmd_Argv(2,0x8000);
        uVar3 = Cmd_Argv(1,uVar3);
        Info_SetValueForKey(localinfo,uVar3);
        return;
      }
      pcVar2 = "Star variables cannot be changed.\n";
    }
    else {
      pcVar2 = "usage: localinfo [ <key> <value> ]\n";
    }
    Con_Printf(pcVar2);
  }
  return;
}


// SV_LookupDelta  @ 00072758
undefined4 SV_LookupDelta(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = g_sv_delta;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      Sys_Error("Couldn\'t find delta for %s\n",param_1);
      return 0;
    }
    iVar2 = Q_stricmp(param_1,puVar1[1]);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[3];
}


// SV_LookupSoundIndex  @ 000736d8
int SV_LookupSoundIndex(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = SV_HashString(param_1,0x3ff);
  if (DAT_00186688 == 0) {
    if (DAT_00186fa0 == 1) {
      if (DAT_0018568c == 0) {
        return 0;
      }
      iVar2 = Q_strcasecmp(param_1,DAT_0018568c);
      if (iVar2 == 0) {
        return 1;
      }
      if (DAT_00185690 == 0) {
        return 0;
      }
      iVar2 = Q_strcasecmp(param_1,DAT_00185690);
      if (iVar2 == 0) {
        return 2;
      }
      if (DAT_00185694 == 0) {
        return 0;
      }
      iVar2 = Q_strcasecmp(param_1,DAT_00185694);
      if (iVar2 == 0) {
        return 3;
      }
      iVar2 = 4;
      while( true ) {
        if ((&DAT_00185688)[iVar2] == 0) {
          return 0;
        }
        iVar4 = Q_strcasecmp(param_1,(&DAT_00185688)[iVar2]);
        if (iVar4 == 0) {
          return iVar2;
        }
        if ((&DAT_00185688)[iVar2 + 1] == 0) {
          return 0;
        }
        iVar4 = Q_strcasecmp(param_1,(&DAT_00185688)[iVar2 + 1]);
        if (iVar4 == 0) {
          return iVar2 + 1;
        }
        if ((&DAT_00185688)[iVar2 + 2] == 0) {
          return 0;
        }
        iVar4 = Q_strcasecmp(param_1,(&DAT_00185688)[iVar2 + 2]);
        if (iVar4 == 0) {
          return iVar2 + 2;
        }
        if ((&DAT_00185688)[iVar2 + 3] == 0) {
          return 0;
        }
        iVar4 = Q_strcasecmp(param_1,(&DAT_00185688)[iVar2 + 3]);
        if (iVar4 == 0) break;
        iVar2 = iVar2 + 4;
        if (0x1ff < iVar2) {
          return 0;
        }
      }
      return iVar2 + 3;
    }
    SV_BuildHashedSoundLookupTable();
  }
  sVar1 = (&DAT_00185e88)[iVar2];
  iVar4 = iVar2;
  while( true ) {
    if (sVar1 == 0) {
      return 0;
    }
    iVar3 = Q_strcasecmp(param_1,(&DAT_00185688)[(short)(&DAT_00185e88)[iVar4]]);
    if (iVar3 == 0) break;
    iVar4 = iVar4 + 1;
    if (0x3fe < iVar4) {
      iVar4 = 0;
    }
    if (iVar4 == iVar2) {
      return 0;
    }
    sVar1 = (&DAT_00185e88)[iVar4];
  }
  return (int)(short)(&DAT_00185e88)[iVar4];
}


// SV_ModelIndex  @ 0007b05c
int SV_ModelIndex(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    do {
      iVar1 = iVar3;
      if ((&DAT_00183688)[iVar3] == 0) break;
      iVar1 = Q_strcasecmp((&DAT_00183688)[iVar3],param_1);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar1 = iVar3 + 1;
      if ((&DAT_00183688)[iVar1] == 0) break;
      iVar2 = Q_strcasecmp((&DAT_00183688)[iVar1],param_1);
      if (iVar2 == 0) {
        return iVar1;
      }
      iVar1 = iVar3 + 2;
      if ((&DAT_00183688)[iVar1] == 0) break;
      iVar2 = Q_strcasecmp((&DAT_00183688)[iVar1],param_1);
      if (iVar2 == 0) {
        return iVar1;
      }
      iVar1 = iVar3 + 3;
      if ((&DAT_00183688)[iVar1] == 0) break;
      iVar2 = Q_strcasecmp((&DAT_00183688)[iVar1],param_1);
      if (iVar2 == 0) {
        return iVar1;
      }
      iVar3 = iVar3 + 4;
      iVar1 = iVar3;
    } while (iVar3 < 0x200);
    if ((iVar1 == 0x200) || ((&DAT_00183688)[iVar1] == 0)) {
      Sys_Error("SV_ModelIndex: model %s not precached",param_1);
    }
  }
  return iVar1;
}


// SV_Move  @ 0008d370
undefined4 *
SV_Move(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
       undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_cc [14];
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
  SV_ClipMoveToEntity(local_cc,DAT_00186f94,param_2,param_3,param_4,param_5);
  puVar2 = local_cc;
  puVar3 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if ((byte)(local_38 < 0.0 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_38 == 0.0) << 0xe) >> 8)) != 0x40) {
    local_4c = &local_94;
    local_50 = param_2;
    local_70 = param_3;
    local_6c = param_4;
    local_10 = (ushort)param_6 & 0xff;
    local_e = (undefined2)((uint)param_6 >> 8);
    local_c = param_7;
    local_8 = param_8;
    local_94 = local_34;
    local_90 = local_30;
    local_8c = local_2c;
    local_38 = 1.0;
    if (param_6 == 2) {
      local_68 = 0xc1700000;
      local_5c = 0x41700000;
      local_64 = 0xc1700000;
      local_58 = 0x41700000;
      local_60 = 0xc1700000;
      local_54 = 0x41700000;
    }
    else {
      local_68 = *param_3;
      local_64 = param_3[1];
      local_60 = param_3[2];
      local_5c = *param_4;
      local_58 = param_4[1];
      local_54 = param_4[2];
    }
    SV_MoveBounds(param_2,&local_68,&local_5c,local_4c,local_88,local_7c);
    SV_ClipToLinks(&sv_areanodes,local_88);
    if (local_18 == 0) {
      DAT_00152bb4 = 0;
    }
    else {
      DAT_00152bb4 = local_18;
    }
  }
  puVar2 = local_48;
  puVar3 = param_1;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// SV_MoveBounds  @ 0008d09c
void SV_MoveBounds(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                  float *param_6)

{
  float fVar1;
  float *pfVar2;
  
  if (*param_4 <= *param_1) {
    *param_5 = (*param_4 + *param_2) - 1.0;
    fVar1 = *param_1;
  }
  else {
    *param_5 = (*param_1 + *param_2) - 1.0;
    fVar1 = *param_4;
  }
  *param_6 = fVar1 + *param_3 + 1.0;
  param_3 = param_3 + 1;
  param_1 = param_1 + 1;
  param_5 = param_5 + 1;
  param_2 = param_2 + 1;
  param_4 = param_4 + 1;
  for (pfVar2 = param_6 + 1; (int)pfVar2 <= (int)(param_6 + 2); pfVar2 = pfVar2 + 2) {
    if (*param_4 <= *param_1) {
      *param_5 = (*param_4 + *param_2) - 1.0;
      fVar1 = *param_1;
    }
    else {
      *param_5 = (*param_1 + *param_2) - 1.0;
      fVar1 = *param_4;
    }
    *pfVar2 = fVar1 + *param_3 + 1.0;
    if (param_4[1] <= param_1[1]) {
      param_5[1] = (param_4[1] + param_2[1]) - 1.0;
      fVar1 = param_1[1];
    }
    else {
      param_5[1] = (param_1[1] + param_2[1]) - 1.0;
      fVar1 = param_4[1];
    }
    pfVar2[1] = fVar1 + param_3[1] + 1.0;
    param_3 = param_3 + 2;
    param_1 = param_1 + 2;
    param_5 = param_5 + 2;
    param_2 = param_2 + 2;
    param_4 = param_4 + 2;
  }
  return;
}


// SV_MoveNoEnts  @ 0008d1cc
undefined4 *
SV_MoveNoEnts(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_cc [14];
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
  SV_ClipMoveToEntity(local_cc,DAT_00186f94,param_2,param_3,param_4,param_5);
  puVar2 = local_cc;
  puVar3 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if ((byte)(local_38 < 0.0 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_38 == 0.0) << 0xe) >> 8)) != 0x40) {
    local_4c = &local_94;
    local_50 = param_2;
    local_70 = param_3;
    local_6c = param_4;
    local_10 = (ushort)param_6 & 0xff;
    local_e = (undefined2)((uint)param_6 >> 8);
    local_c = param_7;
    local_8 = 0;
    local_94 = local_34;
    local_90 = local_30;
    local_8c = local_2c;
    local_38 = 1.0;
    local_68 = *param_3;
    local_64 = param_3[1];
    local_60 = param_3[2];
    local_5c = *param_4;
    local_58 = param_4[1];
    local_54 = param_4[2];
    SV_MoveBounds(param_2,&local_68,&local_5c,local_4c,local_88,local_7c);
    SV_ClipToWorldbrush(&sv_areanodes,local_88);
    if (local_18 == 0) {
      DAT_00152bb4 = 0;
    }
    else {
      DAT_00152bb4 = local_18;
    }
  }
  puVar2 = local_48;
  puVar3 = param_1;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// SV_MoveToOnHandList  @ 00083a78
void SV_MoveToOnHandList(int param_1)

{
  if (param_1 == 0) {
    Con_DPrintf("Null resource passed to SV_MoveToOnHandList\n");
  }
  else {
    SV_RemoveFromResourceList(param_1);
    SV_AddToResourceList(param_1,host_client + 0x4c84);
  }
  return;
}


// SV_MoveToOrigin_I  @ 0007fb78
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
      iVar1 = SV_StepDirection(param_1,*(undefined4 *)(param_1 + 300),param_3);
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


// SV_Multicast  @ 00073b10
void SV_Multicast(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *local_10;
  int local_c;
  
  uVar3 = SV_PointLeafnum(param_1);
  local_c = 0;
  piVar5 = DAT_001ab4e4;
  if (0 < DAT_001ab4e8) {
    do {
      if ((*piVar5 == 0) || (((param_2 & 0x80) != 0 && (piVar5 == host_client)))) goto LAB_00073c30;
      uVar1 = *(uint *)(piVar5[0x12b9] + 0x2c0);
      if ((uVar1 == 0) || (uVar2 = *(uint *)(host_client[0x12b9] + 0x2c0), uVar2 == 0)) {
LAB_00073bba:
        iVar4 = SV_ValidClientMulticast(piVar5,uVar3,param_2);
        if (iVar4 == 0) {
          gPacketSuppressed = gPacketSuppressed + DAT_00189ec0;
        }
        else {
          local_10 = piVar5 + 0x944;
          if (param_3 != 0) {
            local_10 = piVar5 + 0x1d;
          }
          if (DAT_00189ec0 < local_10[2] - local_10[3]) {
            SZ_Write(local_10,DAT_00189eb8,DAT_00189ec0);
          }
        }
      }
      else if (g_groupop == 0) {
        if ((uVar1 & uVar2) != 0) goto LAB_00073bba;
      }
      else if ((g_groupop != 1) || ((uVar1 & uVar2) == 0)) goto LAB_00073bba;
LAB_00073c30:
      local_c = local_c + 1;
      piVar5 = piVar5 + 0x1415;
    } while (local_c < DAT_001ab4e8);
  }
  SZ_Clear(&DAT_00189eb4);
  return;
}


// SV_NewChaseDir  @ 0007f260
void SV_NewChaseDir(int param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  longdouble lVar9;
  float local_c;
  float local_8;
  
  lVar9 = (longdouble)anglemod((float)((int)ROUND(*(float *)(param_1 + 300) * 0.022222223) * 0x2d));
  fVar1 = (float)lVar9;
  lVar9 = (longdouble)anglemod((float)(lVar9 - (longdouble)180.0));
  fVar2 = (float)lVar9;
  fVar4 = *(float *)(param_2 + 0x88) - *(float *)(param_1 + 0x88);
  fVar5 = *(float *)(param_2 + 0x8c) - *(float *)(param_1 + 0x8c);
  if (fVar4 <= 10.0) {
    if ((byte)((-10.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar4 == -10.0) << 0xe) >> 8)) - 1) < 0x40) {
      local_c = -1.0;
    }
    else {
      local_c = 180.0;
    }
  }
  else {
    local_c = 0.0;
  }
  fVar6 = local_c;
  if ((byte)((-10.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar5 == -10.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (fVar5 <= 10.0) {
      local_8 = -1.0;
    }
    else {
      local_8 = 90.0;
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
      fVar3 = 315.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        fVar3 = 45.0;
      }
    }
    else {
      fVar3 = 215.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        fVar3 = 135.0;
      }
    }
    if (((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 0x40) &&
       (iVar7 = SV_StepDirection(param_1,fVar3,param_3), iVar7 != 0)) {
      return;
    }
  }
  iVar7 = RandomLong(0,1);
  if (iVar7 == 0) {
    iVar7 = (int)ROUND(fVar5);
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    iVar8 = (int)ROUND(fVar4);
    if (iVar8 < 0) {
      iVar8 = -iVar8;
    }
    if (iVar7 <= iVar8) goto LAB_0007f48d;
  }
  local_c = local_8;
  local_8 = fVar6;
LAB_0007f48d:
  if ((((((byte)(-1.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_c == -1.0) << 0xe) >> 8)) == 0x40) ||
        ((byte)(fVar2 < local_c | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_c)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_c) << 0xe) >> 8)) == 0x40)) ||
       (iVar7 = SV_StepDirection(param_1,local_c,param_3), iVar7 == 0)) &&
      ((((byte)(-1.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_8 == -1.0) << 0xe) >> 8)) == 0x40 ||
        ((byte)(fVar2 < local_8 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_8)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_8) << 0xe) >> 8)) == 0x40)) ||
       (iVar7 = SV_StepDirection(param_1,local_8,param_3), iVar7 == 0)))) &&
     (((byte)(fVar1 < -1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40 ||
      (iVar7 = SV_StepDirection(param_1,fVar1,param_3), iVar7 == 0)))) {
    iVar7 = RandomLong(0,1);
    if (iVar7 == 0) {
      fVar4 = 315.0;
      do {
        if (((byte)(fVar2 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) != 0x40) &&
           (iVar7 = SV_StepDirection(param_1,fVar4,param_3), iVar7 != 0)) {
          return;
        }
        fVar4 = fVar4 - 45.0;
      } while (0.0 <= fVar4);
    }
    else {
      fVar4 = 0.0;
      do {
        if (((byte)(fVar2 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) != 0x40) &&
           (iVar7 = SV_StepDirection(param_1,fVar4,param_3), iVar7 != 0)) {
          return;
        }
        fVar4 = fVar4 + 45.0;
      } while ((byte)((fVar4 < 315.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar4 == 315.0) << 0xe) >> 8)) - 1) < 0x40);
    }
    if (((byte)(fVar2 < -1.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) == 0x40) ||
       (iVar7 = SV_StepDirection(param_1,fVar2,param_3), iVar7 == 0)) {
      *(float *)(param_1 + 300) = fVar1;
      iVar7 = SV_CheckBottom(param_1);
      if (iVar7 == 0) {
        SV_FixCheckBottom(param_1);
      }
    }
  }
  return;
}


// SV_NewChaseDir2  @ 0007f790
void SV_NewChaseDir2(int param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  longdouble lVar9;
  float local_c;
  float local_8;
  
  lVar9 = (longdouble)anglemod((float)((int)ROUND(*(float *)(param_1 + 300) * 0.022222223) * 0x2d));
  fVar1 = (float)lVar9;
  lVar9 = (longdouble)anglemod((float)(lVar9 - (longdouble)180.0));
  fVar2 = (float)lVar9;
  fVar4 = *param_2 - *(float *)(param_1 + 0x88);
  fVar5 = param_2[1] - *(float *)(param_1 + 0x8c);
  if (fVar4 <= 10.0) {
    if ((byte)((-10.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar4 == -10.0) << 0xe) >> 8)) - 1) < 0x40) {
      local_c = -1.0;
    }
    else {
      local_c = 180.0;
    }
  }
  else {
    local_c = 0.0;
  }
  fVar6 = local_c;
  if ((byte)((-10.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar5 == -10.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (fVar5 <= 10.0) {
      local_8 = -1.0;
    }
    else {
      local_8 = 90.0;
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
      fVar3 = 315.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        fVar3 = 45.0;
      }
    }
    else {
      fVar3 = 215.0;
      if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_8 == 90.0) << 0xe) >> 8)) == 0x40) {
        fVar3 = 135.0;
      }
    }
    if (((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 0x40) &&
       (iVar7 = SV_StepDirection(param_1,fVar3,param_3), iVar7 != 0)) {
      return;
    }
  }
  iVar7 = RandomLong(0,1);
  if (iVar7 == 0) {
    iVar7 = (int)ROUND(fVar5);
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    iVar8 = (int)ROUND(fVar4);
    if (iVar8 < 0) {
      iVar8 = -iVar8;
    }
    if (iVar7 <= iVar8) goto LAB_0007f9b9;
  }
  local_c = local_8;
  local_8 = fVar6;
LAB_0007f9b9:
  if ((((((byte)(-1.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_c == -1.0) << 0xe) >> 8)) == 0x40) ||
        ((byte)(fVar2 < local_c | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_c)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_c) << 0xe) >> 8)) == 0x40)) ||
       (iVar7 = SV_StepDirection(param_1,local_c,param_3), iVar7 == 0)) &&
      ((((byte)(-1.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_8 == -1.0) << 0xe) >> 8)) == 0x40 ||
        ((byte)(fVar2 < local_8 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_8)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_8) << 0xe) >> 8)) == 0x40)) ||
       (iVar7 = SV_StepDirection(param_1,local_8,param_3), iVar7 == 0)))) &&
     (((byte)(fVar1 < -1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40 ||
      (iVar7 = SV_StepDirection(param_1,fVar1,param_3), iVar7 == 0)))) {
    iVar7 = RandomLong(0,1);
    if (iVar7 == 0) {
      fVar4 = 315.0;
      do {
        if (((byte)(fVar2 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) != 0x40) &&
           (iVar7 = SV_StepDirection(param_1,fVar4,param_3), iVar7 != 0)) {
          return;
        }
        fVar4 = fVar4 - 45.0;
      } while (0.0 <= fVar4);
    }
    else {
      fVar4 = 0.0;
      do {
        if (((byte)(fVar2 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) != 0x40) &&
           (iVar7 = SV_StepDirection(param_1,fVar4,param_3), iVar7 != 0)) {
          return;
        }
        fVar4 = fVar4 + 45.0;
      } while ((byte)((fVar4 < 315.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar4 == 315.0) << 0xe) >> 8)) - 1) < 0x40);
    }
    if (((byte)(fVar2 < -1.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) == 0x40) ||
       (iVar7 = SV_StepDirection(param_1,fVar2,param_3), iVar7 == 0)) {
      *(float *)(param_1 + 300) = fVar1;
      iVar7 = SV_CheckBottom(param_1);
      if (iVar7 == 0) {
        SV_FixCheckBottom(param_1);
      }
    }
  }
  return;
}


// SV_New_f  @ 000752f0
void SV_New_f(void)

{
  undefined4 uVar1;
  code *pcVar2;
  char *__format;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iStack_10214;
  int *piStack_10210;
  int *piStack_1020c;
  int *piStack_10208;
  int *piStack_10204;
  int *piStack_101ec;
  int iStack_101dc;
  char acStack_101d8 [64];
  int aiStack_10198 [64];
  char acStack_10098 [128];
  float fStack_10018;
  char acStack_10014 [4];
  undefined1 *puStack_10010;
  undefined4 uStack_1000c;
  undefined4 uStack_10008;
  undefined1 auStack_10004 [65536];
  
  piStack_10208 = (int *)0x7531e;
  piStack_10204 = (int *)acStack_10014;
  Q_memset();
  puStack_10010 = auStack_10004;
  uStack_10008 = 0;
  uStack_1000c = 0x10000;
  if ((cmd_source != 1) && ((host_client[1] == 0 || (*host_client != 0)))) {
    iVar3 = host_client[0x12b9];
    host_client[3] = 1;
    *(undefined8 *)(host_client + 0xd30) = realtime;
    SZ_Clear();
    piStack_10204 = (int *)0x753b4;
    SZ_Clear();
    piStack_10204 = host_client + 8;
    piStack_10208 = (int *)0x753c5;
    Netchan_Clear();
    piStack_10208 = host_client;
    piStack_10210 = (int *)0x753da;
    piStack_1020c = (int *)acStack_10014;
    SV_SendServerinfo();
    uVar1 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != 0) {
      sv_gpNewUserMsgs = sv_gpUserMsgs;
      SV_SendUserReg();
    }
    sv_gpNewUserMsgs = uVar1;
    host_client[5] = 1;
    if (((*host_client != 0) || (host_client[1] != 0)) && (host_client[0x12b9] != 0)) {
      pcVar2 = DAT_00386260;
      if (host_client[0x917] != 0) {
        pcVar2 = DAT_0038629c;
      }
      (*pcVar2)();
    }
    if (host_client[0x917] == 0) {
      piStack_10204 = (int *)0x75484;
      sprintf(acStack_101d8,(char *)(host_client + 0x130f));
      piVar5 = host_client + 9;
      piVar6 = &iStack_10214;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar6 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar6 = piVar6 + 1;
      }
      __format = (char *)NET_AdrToString();
      sprintf((char *)aiStack_10198,__format);
      piStack_10204 = (int *)0x754cc;
      sprintf(acStack_10098,"Connection rejected by game\n");
      iStack_10214 = 0x754ed;
      piStack_10210 = (int *)iVar3;
      piStack_1020c = (int *)acStack_101d8;
      piStack_10208 = aiStack_10198;
      piStack_10204 = (int *)acStack_10098;
      iVar3 = (*DAT_0038625c)();
      if (iVar3 == 0) {
        piStack_10204 = (int *)0x7550b;
        MSG_WriteByte();
        piStack_10208 = (int *)0xaad01;
        piStack_1020c = (int *)0x7551e;
        piStack_10204 = (int *)acStack_10098;
        piStack_1020c = (int *)va();
        piStack_10210 = host_client + 0x1d;
        iStack_10214 = 0x75530;
        MSG_WriteString();
        iStack_10214 = 0;
        SV_DropClient(host_client);
        return;
      }
    }
    else {
      SV_SpawnSpectator();
      fStack_10018 = (float)DAT_0015358c;
      gGlobalVariables = fStack_10018;
      (*DAT_00386298)();
    }
    piStack_10204 = (int *)0x7558d;
    MSG_WriteByte();
    piStack_10204 = (int *)0x75592;
    piStack_10204 = (int *)Info_Serverinfo();
    piStack_10208 = (int *)0xaa943;
    piStack_1020c = (int *)0x7559f;
    piStack_1020c = (int *)va();
    iStack_10214 = 0x755ac;
    piStack_10210 = (int *)acStack_10014;
    MSG_WriteString();
    iStack_101dc = 0;
    if (0 < DAT_001ab4e8) {
      piStack_101ec = DAT_001ab4e4 + 1;
      piVar5 = DAT_001ab4e4;
      do {
        if (((piVar5 == host_client) || (*piVar5 != 0)) ||
           ((piStack_101ec[2] != 0 || (*piStack_101ec != 0)))) {
          piStack_10204 = (int *)0x75604;
          SV_FullClientUpdate();
        }
        iStack_101dc = iStack_101dc + 1;
        piStack_101ec = piStack_101ec + 0x1415;
        piVar5 = piVar5 + 0x1415;
      } while (iStack_101dc < DAT_001ab4e8);
    }
    SV_SendResources();
    piStack_10204 = host_client + 8;
    piStack_10208 = (int *)0x1;
    piStack_1020c = (int *)0x75654;
    Netchan_CreateFragments();
    piStack_1020c = host_client + 8;
    piStack_10210 = (int *)0x75665;
    Netchan_FragSend();
  }
  return;
}


// SV_PTrack_f  @ 00075760
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
      iVar1 = Q_atoi(uVar2);
      if ((((-1 < iVar1) && (iVar1 < DAT_001ab4e8)) &&
          (*(int *)(DAT_001ab4e4 + iVar1 * 0x5054) != 0)) &&
         (*(int *)(DAT_001ab4e4 + 0x245c + iVar1 * 0x5054) == 0)) {
        *(int *)(host_client + 0x1c) = iVar1 + 1;
        return;
      }
      SV_ClientPrintf("Invalid client to track\n");
    }
    *(undefined4 *)(host_client + 0x1c) = 0;
  }
  return;
}


// SV_ParseConsistencyResponse  @ 00084290
void SV_ParseConsistencyResponse(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  float **ppfVar7;
  float *apfStack_1d4 [5];
  int local_1a0;
  int local_19c;
  undefined1 local_194 [256];
  char local_94;
  undefined1 local_93 [12];
  float local_87 [4];
  float local_74 [8];
  float local_54 [8];
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
  
  local_19c = 0;
  local_1a0 = 0;
  apfStack_1d4[4] = (float *)0x20;
  apfStack_1d4[3] = (float *)0x0;
  apfStack_1d4[1] = (float *)0x842cf;
  apfStack_1d4[2] = local_74;
  Q_memset();
  apfStack_1d4[1] = (float *)0x842d4;
  apfStack_1d4[0] = (float *)MSG_ReadShort();
  apfStack_1d4[1] = DAT_001ab4f0;
  COM_UnMunge(msg_readcount + DAT_00226fe4);
  MSG_StartBitReading(&net_message);
  do {
    apfStack_1d4[4] = (float *)0x1;
    apfStack_1d4[3] = (float *)0x84549;
    iVar3 = MSG_ReadBits();
    if (iVar3 == 0) {
LAB_00084554:
      apfStack_1d4[4] = (float *)&net_message;
      apfStack_1d4[3] = (float *)0x84560;
      MSG_EndBitReading();
      if ((local_1a0 < 0) || (local_19c != DAT_00183684)) {
        msg_badread = 1;
        puVar6 = (undefined4 *)(host_client + 0x24);
        ppfVar7 = apfStack_1d4;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *ppfVar7 = (float *)*puVar6;
          puVar6 = puVar6 + 1;
          ppfVar7 = ppfVar7 + 1;
        }
        uVar4 = NET_AdrToString();
        Con_Printf("SV_ParseConsistencyResponse:  %s:%s sent bad file data\n",host_client + 0x4c3c,
                   uVar4);
      }
      else {
        if (local_1a0 < 1) {
          *(undefined4 *)(host_client + 0x18) = 0;
          return;
        }
        local_194[0] = 0;
        apfStack_1d4[3] = (float *)(local_1a0 * 0x88 + 0x1535f8);
        apfStack_1d4[2] = *(float **)(host_client + 0x4ae4);
        apfStack_1d4[1] = (float *)0x84626;
        apfStack_1d4[4] = (float *)local_194;
        iVar3 = (*DAT_003862e0)();
        if (iVar3 == 0) {
          return;
        }
        apfStack_1d4[3] = (float *)0x84633;
        apfStack_1d4[4] = (float *)local_194;
        iVar3 = Q_strlen();
        if (0 < iVar3) {
          apfStack_1d4[3] = (float *)0x84640;
          apfStack_1d4[4] = (float *)local_194;
          SV_ClientPrintf();
        }
      }
      apfStack_1d4[4] = (float *)0x0;
      apfStack_1d4[3] = (float *)host_client;
      apfStack_1d4[2] = (float *)0x84653;
      SV_DropClient();
      return;
    }
    apfStack_1d4[4] = (float *)0xc;
    apfStack_1d4[3] = (float *)0x8431f;
    iVar3 = MSG_ReadBits();
    if (((iVar3 < 0) || (DAT_0017de80 <= iVar3)) ||
       (iVar2 = iVar3 * 0x88, -1 < (char)(&DAT_001536cc)[iVar2])) {
      local_1a0 = -1;
      goto LAB_00084554;
    }
    apfStack_1d4[4] = (float *)0x20;
    apfStack_1d4[1] = (float *)0x84379;
    apfStack_1d4[2] = local_54;
    apfStack_1d4[3] = (float *)(&DAT_001536de + iVar2);
    Q_memcpy();
    apfStack_1d4[1] = (float *)0x20;
    apfStack_1d4[0] = local_74;
    iVar1 = Q_memcmp(local_54);
    if (iVar1 == 0) {
      apfStack_1d4[4] = (float *)0x20;
      apfStack_1d4[3] = (float *)0x84398;
      iVar1 = MSG_ReadBits();
      if (iVar1 != *(int *)(&DAT_001536cd + iVar2)) goto LAB_00084524;
    }
    else {
      apfStack_1d4[4] = (float *)0xc;
      apfStack_1d4[2] = (float *)0x843b7;
      apfStack_1d4[3] = &local_28;
      MSG_ReadBitData();
      apfStack_1d4[2] = (float *)0xc;
      apfStack_1d4[0] = (float *)0x843c8;
      apfStack_1d4[1] = &local_34;
      MSG_ReadBitData();
      apfStack_1d4[0] = (float *)0x20;
      Q_memcpy(&local_94,&DAT_001536de + iVar2);
      COM_UnMunge(&local_94,0x20,DAT_001ab4f0);
      if (local_94 == '\x01') {
        apfStack_1d4[4] = (float *)0xc;
        apfStack_1d4[3] = (float *)local_93;
        apfStack_1d4[1] = (float *)0x84421;
        apfStack_1d4[2] = &local_10;
        Q_memcpy();
        apfStack_1d4[1] = (float *)0xc;
        apfStack_1d4[0] = local_87;
        Q_memcpy(&local_1c);
        iVar2 = VectorCompare(&local_28,&local_10);
        if (iVar2 != 0) {
          apfStack_1d4[2] = (float *)0x84456;
          apfStack_1d4[3] = &local_34;
          apfStack_1d4[4] = &local_1c;
          iVar2 = VectorCompare();
          if (iVar2 != 0) goto LAB_00084531;
        }
        local_1a0 = iVar3 + 1;
      }
      else {
        if (local_94 == '\x02') {
          apfStack_1d4[4] = (float *)0xc;
          apfStack_1d4[3] = (float *)local_93;
          apfStack_1d4[1] = (float *)0x8448d;
          apfStack_1d4[2] = &local_10;
          Q_memcpy();
          apfStack_1d4[1] = (float *)0xc;
          apfStack_1d4[0] = local_87;
          Q_memcpy(&local_1c);
          uVar5 = 0;
          if ((((local_10 <= local_28) &&
               ((byte)(local_1c < local_34 |
                       (byte)((ushort)((ushort)(NAN(local_1c) || NAN(local_34)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_1c == local_34) << 0xe) >> 8)) != 1)) &&
              ((uVar5 = 1, local_c <= local_24 &&
               (((byte)(local_18 < local_30 |
                        (byte)((ushort)((ushort)(NAN(local_18) || NAN(local_30)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_18 == local_30) << 0xe) >> 8)) != 1 &&
                (uVar5 = 2, local_8 <= local_20)))))) &&
             ((byte)(local_14 < local_2c |
                     (byte)((ushort)((ushort)(NAN(local_14) || NAN(local_2c)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_14 == local_2c) << 0xe) >> 8)) != 1)) {
            uVar5 = 3;
          }
          if (2 < uVar5) goto LAB_00084531;
        }
        else {
          msg_badread = 1;
        }
LAB_00084524:
        local_1a0 = iVar3 + 1;
      }
    }
LAB_00084531:
    if (msg_badread != 0) goto LAB_00084554;
    local_19c = local_19c + 1;
  } while( true );
}


// SV_ParseDelta  @ 00087638
void SV_ParseDelta(void)

{
  undefined4 uVar1;
  
  uVar1 = MSG_ReadByte();
  *(undefined4 *)(host_client + 0x2454) = uVar1;
  return;
}


// SV_ParseMove  @ 0008790c
void SV_ParseMove(void)

{
  float fVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  int **ppiVar14;
  int *apiStack_6c4 [5];
  int *local_694;
  undefined1 *local_690;
  ushort *local_68c;
  undefined1 *local_688;
  uint local_670;
  int local_650 [13];
  undefined4 local_61c;
  undefined4 local_618 [6];
  byte local_600;
  ushort local_5fe;
  undefined1 local_5fc [22];
  undefined1 local_5e6 [2];
  undefined4 auStack_5e4 [6];
  ushort local_5ca;
  undefined1 local_5c8 [1476];
  
  if (g_balreadymoved != 0) {
    msg_badread = 1;
    return;
  }
  g_balreadymoved = 1;
  iVar11 = (host_client[0x15] & SV_UPDATE_MASK) * 0xd10 + host_client[0xd38];
  apiStack_6c4[4] = (int *)0x34;
  apiStack_6c4[3] = (int *)0x0;
  apiStack_6c4[1] = (int *)0x8798a;
  apiStack_6c4[2] = local_650;
  Q_memset();
  iVar4 = msg_readcount + 1;
  apiStack_6c4[1] = (int *)0x8799e;
  piVar5 = (int *)MSG_ReadByte();
  apiStack_6c4[1] = (int *)0x879a5;
  cVar2 = MSG_ReadByte();
  apiStack_6c4[1] = (int *)host_client[0x14];
  apiStack_6c4[0] = piVar5;
  COM_UnMunge(iVar4 + DAT_00226fe4 + 1);
  iVar6 = MSG_ReadByte();
  iVar7 = MSG_ReadByte();
  uVar8 = MSG_ReadByte();
  uVar10 = iVar7 + uVar8;
  net_drop = (net_drop + 1) - uVar8;
  if (0x1c < uVar10) {
    piVar5 = host_client + 9;
    ppiVar14 = apiStack_6c4;
    for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
      *ppiVar14 = (int *)*piVar5;
      piVar5 = piVar5 + 1;
      ppiVar14 = ppiVar14 + 1;
    }
    uVar9 = NET_AdrToString();
    Con_Printf("SV_ReadClientMessage: too many cmds %i sent for %s/%s\n",uVar10,host_client + 0x130f
               ,uVar9);
    apiStack_6c4[4] = (int *)0x0;
    apiStack_6c4[3] = host_client;
    apiStack_6c4[2] = (int *)0x87a88;
    SV_DropClient();
    msg_badread = 1;
    return;
  }
  local_670 = uVar10 - 1;
  if (-1 < (int)local_670) {
    piVar5 = &local_61c + local_670 * 0xd;
    uVar13 = ~local_670 & 3;
    apiStack_6c4[4] = local_650;
    local_694 = piVar5;
    if ((int)local_670 < 0) {
LAB_00087b2f:
      apiStack_6c4[3] = local_694;
      apiStack_6c4[2] = (int *)0x87b3c;
      MSG_ReadUsercmd();
      local_670 = local_670 - 1;
      piVar12 = local_694;
      local_694 = local_694 + -0xd;
      if ((int)local_670 < 0) goto LAB_00087bbb;
    }
    else {
      piVar12 = local_650;
      if (uVar13 != 0) {
        if (uVar13 < 3) {
          if (uVar13 < 2) {
            apiStack_6c4[2] = (int *)0x87aed;
            apiStack_6c4[3] = piVar5;
            MSG_ReadUsercmd();
            local_694 = local_650 + local_670 * 0xd;
            local_670 = uVar10 - 2;
            apiStack_6c4[4] = piVar5;
          }
          apiStack_6c4[3] = local_694;
          apiStack_6c4[2] = (int *)0x87b19;
          MSG_ReadUsercmd();
          local_670 = local_670 - 1;
          apiStack_6c4[4] = local_694;
          local_694 = local_694 + -0xd;
        }
        goto LAB_00087b2f;
      }
    }
    do {
      apiStack_6c4[3] = local_694;
      apiStack_6c4[2] = (int *)0x87b61;
      apiStack_6c4[4] = piVar12;
      MSG_ReadUsercmd();
      apiStack_6c4[4] = local_694;
      apiStack_6c4[2] = (int *)0x87b7a;
      apiStack_6c4[3] = local_694 + -0xd;
      MSG_ReadUsercmd();
      apiStack_6c4[2] = (int *)0x87b8d;
      apiStack_6c4[3] = local_694 + -0x1a;
      apiStack_6c4[4] = local_694 + -0xd;
      MSG_ReadUsercmd();
      piVar12 = local_694 + -0x27;
      apiStack_6c4[2] = (int *)0x87ba3;
      apiStack_6c4[3] = piVar12;
      apiStack_6c4[4] = local_694 + -0x1a;
      MSG_ReadUsercmd();
      local_694 = local_694 + -0x34;
      local_670 = local_670 - 4;
    } while (-1 < (int)local_670);
  }
LAB_00087bbb:
  if (sv == 0) {
    return;
  }
  if ((*host_client == 0) && (host_client[1] == 0)) {
    return;
  }
  if (msg_badread != 0) {
    piVar5 = host_client + 9;
    ppiVar14 = apiStack_6c4;
    for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
      *ppiVar14 = (int *)*piVar5;
      piVar5 = piVar5 + 1;
      ppiVar14 = ppiVar14 + 1;
    }
    uVar9 = NET_AdrToString();
    Con_Printf("Client %s:%s sent a bogus command packet\n",host_client + 0x130f,uVar9);
    return;
  }
  apiStack_6c4[4] = (int *)host_client[0x14];
  apiStack_6c4[3] = (int *)((msg_readcount - iVar4) + -1);
  apiStack_6c4[2] = (int *)(iVar4 + DAT_00226fe4 + 1);
  apiStack_6c4[1] = (int *)0x87c54;
  cVar3 = COM_BlockSequenceCRCByte();
  if (cVar3 != cVar2) {
    piVar5 = host_client + 9;
    ppiVar14 = apiStack_6c4;
    for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
      *ppiVar14 = (int *)*piVar5;
      piVar5 = piVar5 + 1;
      ppiVar14 = ppiVar14 + 1;
    }
    uVar9 = NET_AdrToString();
    Con_DPrintf("Failed command checksum for %s:%s\n",host_client + 0x130f,uVar9);
    msg_badread = 1;
    return;
  }
  host_client[0x92d] = (int)(float)iVar6;
  if ((DAT_00153584 == 0) &&
     (((1 < DAT_001ab4e8 || (key_dest == 0)) && ((*(byte *)(sv_player + 0x225) & 0x10) == 0)))) {
    *(undefined4 *)(sv_player + 0xf4) = local_618[0];
    *(undefined4 *)(sv_player + 0xf8) = local_618[1];
    *(undefined4 *)(sv_player + 0xfc) = local_618[2];
  }
  else {
    local_670 = 0;
    if (0 < (int)uVar8) {
      local_688 = local_5fc;
      local_68c = &local_5fe;
      local_690 = (undefined1 *)((int)&local_61c + 2);
      iVar4 = 0;
      if ((uVar8 & 1) != 0) {
        local_61c._2_1_ = 0;
        local_618[3] = 0;
        local_618[4] = 0;
        local_618[5] = 0;
        local_5fe = 0;
        if ((*(byte *)(sv_player + 0x225) & 0x10) != 0) {
          local_5fc[0] = 0;
        }
        local_618[0] = *(undefined4 *)(sv_player + 0xf4);
        local_688 = local_5c8;
        local_618[1] = *(undefined4 *)(sv_player + 0xf8);
        local_68c = &local_5ca;
        local_690 = local_5e6;
        local_670 = 1;
        local_618[2] = *(undefined4 *)(sv_player + 0xfc);
        iVar4 = 0x34;
        if ((int)uVar8 < 2) goto LAB_00087fab;
      }
      do {
        *local_690 = 0;
        *(undefined4 *)((int)local_618 + iVar4 + 0xc) = 0;
        *(undefined4 *)((int)local_618 + iVar4 + 0x10) = 0;
        *(undefined4 *)((int)local_618 + iVar4 + 0x14) = 0;
        *local_68c = 0;
        if ((*(byte *)(sv_player + 0x225) & 0x10) != 0) {
          *local_688 = 0;
        }
        *(undefined4 *)((int)local_618 + iVar4) = *(undefined4 *)(sv_player + 0xf4);
        *(undefined4 *)((int)local_618 + iVar4 + 4) = *(undefined4 *)(sv_player + 0xf8);
        *(undefined4 *)((int)local_618 + iVar4 + 8) = *(undefined4 *)(sv_player + 0xfc);
        local_690[0x34] = 0;
        *(undefined4 *)((int)auStack_5e4 + iVar4 + 0xc) = 0;
        *(undefined4 *)((int)auStack_5e4 + iVar4 + 0x10) = 0;
        *(undefined4 *)((int)auStack_5e4 + iVar4 + 0x14) = 0;
        local_68c[0x1a] = 0;
        if ((*(byte *)(sv_player + 0x225) & 0x10) != 0) {
          local_688[0x34] = 0;
        }
        *(undefined4 *)((int)auStack_5e4 + iVar4) = *(undefined4 *)(sv_player + 0xf4);
        *(undefined4 *)((int)auStack_5e4 + iVar4 + 4) = *(undefined4 *)(sv_player + 0xf8);
        *(undefined4 *)((int)auStack_5e4 + iVar4 + 8) = *(undefined4 *)(sv_player + 0xfc);
        local_688 = local_688 + 0x68;
        local_68c = local_68c + 0x34;
        local_690 = local_690 + 0x68;
        local_670 = local_670 + 2;
        iVar4 = iVar4 + 0x68;
      } while ((int)local_670 < (int)uVar8);
    }
LAB_00087fab:
    net_drop = 0;
  }
  *(uint *)(sv_player + 0x200) = (uint)local_5fe;
  *(uint *)(sv_player + 0x1a4) = (uint)local_600;
  apiStack_6c4[2] = (int *)net_drop;
  apiStack_6c4[0] = host_client;
  apiStack_6c4[1] = &local_61c;
  apiStack_6c4[3] = (int *)iVar7;
  apiStack_6c4[4] = (int *)uVar8;
  SV_EstablishTimeBase();
  SV_PreRunCmd();
  if (net_drop < 0x18) {
    for (; iVar7 < net_drop; net_drop = net_drop + -1) {
      apiStack_6c4[4] = (int *)0x0;
      apiStack_6c4[3] = host_client + 0x91b;
      apiStack_6c4[2] = (int *)0x8807a;
      SV_RunCmd();
    }
    for (; 0 < net_drop; net_drop = net_drop + -1) {
      iVar4 = uVar8 + net_drop + -1;
      apiStack_6c4[4] = (int *)(host_client[0x14] - iVar4);
      apiStack_6c4[3] = &local_61c + iVar4 * 0xd;
      apiStack_6c4[2] = (int *)0x880ca;
      SV_RunCmd();
    }
  }
  local_670 = uVar8 - 1;
  if ((int)local_670 < 0) goto LAB_0008823c;
  piVar5 = &local_61c + local_670 * 0xd;
  uVar10 = ~local_670 & 3;
  if ((int)local_670 < 0) {
LAB_00088179:
    apiStack_6c4[4] = (int *)(host_client[0x14] - local_670);
    apiStack_6c4[2] = (int *)0x88191;
    apiStack_6c4[3] = piVar5;
    SV_RunCmd();
    piVar5 = piVar5 + -0xd;
    local_670 = local_670 - 1;
    if ((int)local_670 < 0) goto LAB_0008823c;
  }
  else if (uVar10 != 0) {
    if (uVar10 < 3) {
      if (uVar10 < 2) {
        apiStack_6c4[4] = (int *)(host_client[0x14] - local_670);
        apiStack_6c4[2] = (int *)0x88140;
        apiStack_6c4[3] = piVar5;
        SV_RunCmd();
        piVar5 = local_650 + local_670 * 0xd;
        local_670 = uVar8 - 2;
      }
      apiStack_6c4[4] = (int *)(host_client[0x14] - local_670);
      apiStack_6c4[2] = (int *)0x8816d;
      apiStack_6c4[3] = piVar5;
      SV_RunCmd();
      piVar5 = piVar5 + -0xd;
      local_670 = local_670 - 1;
    }
    goto LAB_00088179;
  }
  do {
    apiStack_6c4[4] = (int *)(host_client[0x14] - local_670);
    apiStack_6c4[2] = (int *)0x881bc;
    apiStack_6c4[3] = piVar5;
    SV_RunCmd();
    apiStack_6c4[4] = (int *)(host_client[0x14] - (local_670 - 1));
    apiStack_6c4[3] = piVar5 + -0xd;
    apiStack_6c4[2] = (int *)0x881dd;
    SV_RunCmd();
    apiStack_6c4[4] = (int *)(host_client[0x14] - (local_670 - 2));
    apiStack_6c4[3] = piVar5 + -0x1a;
    apiStack_6c4[2] = (int *)0x88200;
    SV_RunCmd();
    apiStack_6c4[4] = (int *)(host_client[0x14] - (local_670 - 3));
    apiStack_6c4[3] = piVar5 + -0x27;
    apiStack_6c4[2] = (int *)0x88226;
    SV_RunCmd();
    piVar5 = piVar5 + -0x34;
    local_670 = local_670 - 4;
  } while (-1 < (int)local_670);
LAB_0008823c:
  piVar5 = &local_61c;
  piVar12 = host_client + 0x91b;
  for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar12 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar12 = piVar12 + 1;
  }
  fVar1 = *(float *)(iVar11 + 8) - (float)*(byte *)((int)host_client + 0x246e) * 0.0005;
  *(float *)(iVar11 + 8) = fVar1;
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(iVar11 + 8) = 0;
  }
  if ((longdouble)DAT_0015358c + (longdouble)host_frametime <
      (longdouble)*(float *)(sv_player + 0x1b4)) {
    *(float *)(sv_player + 0x1b4) = (float)((longdouble)DAT_0015358c + (longdouble)host_frametime);
  }
  return;
}


// SV_ParseResourceList  @ 00083e08
void SV_ParseResourceList(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  uVar2 = MSG_ReadShort();
  SV_ClearResourceList();
  SV_ClearResourceList(host_client + 0x4c84);
  iVar6 = 0;
  if (0 < (int)uVar2) {
    if ((uVar2 & 1) != 0) {
      iVar6 = Mem_ZeroMalloc();
      uVar3 = MSG_ReadString();
      Q_strcpy(iVar6,uVar3);
      uVar3 = MSG_ReadByte();
      *(undefined4 *)(iVar6 + 0x40) = uVar3;
      uVar3 = MSG_ReadShort();
      *(undefined4 *)(iVar6 + 0x44) = uVar3;
      uVar3 = MSG_ReadLong();
      *(undefined4 *)(iVar6 + 0x48) = uVar3;
      bVar1 = MSG_ReadByte();
      *(byte *)(iVar6 + 0x4c) = bVar1;
      *(undefined4 *)(iVar6 + 0x80) = 0;
      *(undefined4 *)(iVar6 + 0x84) = 0;
      *(byte *)(iVar6 + 0x4c) = bVar1 & 0xfd;
      if ((bVar1 & 4) != 0) {
        MSG_ReadBuf(0x10,iVar6 + 0x4d);
      }
      SV_AddToResourceList(iVar6,host_client + 0x4d0c);
      iVar6 = 1;
      if ((int)uVar2 < 2) goto LAB_00084000;
    }
    do {
      iVar4 = Mem_ZeroMalloc();
      uVar3 = MSG_ReadString();
      Q_strcpy(iVar4,uVar3);
      uVar3 = MSG_ReadByte();
      *(undefined4 *)(iVar4 + 0x40) = uVar3;
      uVar3 = MSG_ReadShort();
      *(undefined4 *)(iVar4 + 0x44) = uVar3;
      uVar3 = MSG_ReadLong();
      *(undefined4 *)(iVar4 + 0x48) = uVar3;
      bVar1 = MSG_ReadByte();
      *(byte *)(iVar4 + 0x4c) = bVar1;
      *(undefined4 *)(iVar4 + 0x80) = 0;
      *(undefined4 *)(iVar4 + 0x84) = 0;
      *(byte *)(iVar4 + 0x4c) = bVar1 & 0xfd;
      if ((bVar1 & 4) != 0) {
        MSG_ReadBuf(0x10,iVar4 + 0x4d);
      }
      SV_AddToResourceList(iVar4);
      iVar4 = Mem_ZeroMalloc();
      uVar3 = MSG_ReadString();
      Q_strcpy(iVar4,uVar3);
      uVar3 = MSG_ReadByte();
      *(undefined4 *)(iVar4 + 0x40) = uVar3;
      uVar3 = MSG_ReadShort();
      *(undefined4 *)(iVar4 + 0x44) = uVar3;
      uVar3 = MSG_ReadLong();
      *(undefined4 *)(iVar4 + 0x48) = uVar3;
      bVar1 = MSG_ReadByte();
      *(byte *)(iVar4 + 0x4c) = bVar1;
      *(undefined4 *)(iVar4 + 0x80) = 0;
      *(undefined4 *)(iVar4 + 0x84) = 0;
      *(byte *)(iVar4 + 0x4c) = bVar1 & 0xfd;
      if ((bVar1 & 4) != 0) {
        MSG_ReadBuf(0x10,iVar4 + 0x4d);
      }
      SV_AddToResourceList(iVar4);
      iVar6 = iVar6 + 2;
    } while (iVar6 < (int)uVar2);
  }
LAB_00084000:
  Con_DPrintf();
  uVar3 = COM_SizeofResourceList(host_client + 0x4d0c,&local_20);
  *(undefined4 *)(host_client + 0x4e28) = uVar3;
  uVar3 = SV_EstimateNeededResources();
  *(undefined4 *)(host_client + 0x4e2c) = uVar3;
  if (*(int *)(host_client + 0x4e28) != 0) {
    Con_DPrintf("Custom resources total %.2fK\n",
                (double)*(int *)(host_client + 0x4e28) * 0.0009765625);
    if (local_18 != 0) {
      Con_DPrintf("  Models:  %.2fK\n",(double)local_18 * 0.0009765625);
    }
    if (local_20 != 0) {
      Con_DPrintf("  Sounds:  %.2fK\n",(double)local_20 * 0.0009765625);
    }
    if (local_14 != 0) {
      Con_DPrintf("  Decals:  %.2fK\n",(double)local_14 * 0.0009765625);
    }
    if (local_1c != 0) {
      Con_DPrintf("  Skins :  %.2fK\n",(double)local_1c * 0.0009765625);
    }
    if (local_10 != 0) {
      Con_DPrintf("  Generic :  %.2fK\n",(double)local_10 * 0.0009765625);
    }
    if (local_c != 0) {
      Con_DPrintf("  Events  :  %.2fK\n",(double)local_c * 0.0009765625);
    }
    Con_DPrintf();
    iVar6 = *(int *)(host_client + 0x4e2c);
    if (iVar6 < 0x401) {
      pcVar5 = "Resources to request: %i bytes\n";
    }
    else {
      if (iVar6 < 0) {
        iVar6 = iVar6 + 0x3ff;
      }
      iVar6 = iVar6 >> 10;
      pcVar5 = "Resources to request: %iK\n";
    }
    Con_DPrintf(pcVar5,iVar6);
  }
  *(undefined4 *)(host_client + 0x10) = 1;
  *(undefined4 *)(host_client + 0x4ea0) = 0;
  *(undefined4 *)(host_client + 0x4e24) = 0;
  *(float *)(host_client + 0x4e34) = (float)realtime;
  *(float *)(host_client + 0x4e38) = (float)realtime;
  *(undefined4 *)(host_client + 0x4e30) = *(undefined4 *)(host_client + 0x4e2c);
  Q_memset(host_client + 0x4e3c,0,0x60);
  *(undefined4 *)(host_client + 0x4e9c) = 0;
  SV_BatchUploadRequest(host_client);
  return;
}


// SV_ParseStringCommand  @ 000875d4
void SV_ParseStringCommand(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = MSG_ReadString();
  iVar2 = SV_ValidateClientCommand(uVar1);
  if (iVar2 == 1) {
    Cmd_ExecuteString(uVar1,0);
  }
  else if (iVar2 == 2) {
    Cbuf_InsertText(uVar1);
  }
  else {
    Cmd_TokenizeString(uVar1);
    (*DAT_0038626c)(sv_player);
  }
  return;
}


// SV_ParseTMove  @ 00087664
void SV_ParseTMove(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  MSG_ReadVec3Coord(&net_message,&local_10);
  if (*(int *)(host_client + 0x245c) != 0) {
    *(undefined4 *)(sv_player + 0x88) = local_10;
    *(undefined4 *)(sv_player + 0x8c) = local_c;
    *(undefined4 *)(sv_player + 0x90) = local_8;
    SV_LinkEdict(sv_player,0);
  }
  return;
}


// SV_Physics  @ 000831b8
void SV_Physics(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int local_c;
  
  gGlobalVariables = (float)DAT_0015358c;
  (*DAT_00386284)();
  iVar4 = 0;
  if (0 < DAT_00186f8c) {
    local_c = 0;
    do {
      piVar3 = (int *)(local_c + DAT_00186f94);
      if (*piVar3 == 0) {
        if ((byte)(DAT_00152b48 < 0.0 | (byte)((ushort)((ushort)NAN(DAT_00152b48) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00152b48 == 0.0) << 0xe) >> 8)) != 0x40) {
          SV_LinkEdict(piVar3,1);
        }
        if ((iVar4 < 1) || (DAT_001ab4e8 < iVar4)) {
          uVar2 = piVar3[0x89];
          if (((uVar2 & 0x200) != 0) &&
             ((iVar1 = piVar3[0x87], iVar1 != 0 && ((*(byte *)(iVar1 + 0x224) & 4) != 0)))) {
            if ((uVar2 & 0x400000) == 0) {
              VectorScale(iVar1 + 0xc4,*(undefined4 *)(iVar1 + 0x278),piVar3 + 0x2b);
            }
            else {
              VectorMA(piVar3 + 0x2b,*(undefined4 *)(iVar1 + 0x278),iVar1 + 0xc4,piVar3 + 0x2b);
            }
            uVar2 = piVar3[0x89] | 0x400000;
            piVar3[0x89] = uVar2;
          }
          if ((uVar2 & 0x400000) == 0) {
            VectorMA(piVar3 + 0x28,
                     (float)((longdouble)0.5 * (longdouble)host_frametime + (longdouble)1),
                     piVar3 + 0x2b,piVar3 + 0x28);
            uVar2 = piVar3[0x89];
            piVar3[0x2b] = vec3_origin;
            piVar3[0x2c] = DAT_000b2e2c;
            piVar3[0x2d] = DAT_000b2e30;
          }
          piVar3[0x89] = uVar2 & 0xffbfffff;
          iVar1 = piVar3[0x62];
          if (iVar1 == 7) {
            SV_Physics_Pusher(piVar3);
          }
          else if (iVar1 == 0) {
            SV_Physics_None(piVar3);
          }
          else if (iVar1 == 0xc) {
            SV_Physics_Follow(piVar3);
          }
          else if (iVar1 == 8) {
            SV_Physics_Noclip(piVar3);
          }
          else if ((iVar1 == 4) || (iVar1 == 0xd)) {
            SV_Physics_Step(piVar3);
          }
          else if ((((iVar1 == 6) || (iVar1 == 10)) || (iVar1 == 0xb)) ||
                  ((iVar1 == 5 || (iVar1 == 9)))) {
            SV_Physics_Toss(piVar3);
          }
          else {
            Sys_Error("SV_Physics: %s bad movetype %d",piVar3[0x20] + pr_strings,iVar1);
          }
          if ((*(byte *)((int)piVar3 + 0x227) & 0x40) != 0) {
            ED_Free(piVar3);
          }
        }
      }
      local_c = local_c + 0x324;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_00186f8c);
  }
  if ((byte)(DAT_00152b48 < 0.0 | (byte)((ushort)((ushort)NAN(DAT_00152b48) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_00152b48 == 0.0) << 0xe) >> 8)) != 0x40) {
    DAT_00152b48 = DAT_00152b48 - 1.0;
  }
  return;
}


// SV_Physics_Follow  @ 000822ec
void SV_Physics_Follow(int param_1)

{
  int iVar1;
  
  iVar1 = SV_RunThink(param_1);
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0x214);
    if (iVar1 == 0) {
      Con_DPrintf("%s movetype FOLLOW with NULL aiment\n",*(int *)(param_1 + 0x80) + pr_strings);
      *(undefined4 *)(param_1 + 0x188) = 0;
    }
    else {
      *(float *)(param_1 + 0x88) = *(float *)(iVar1 + 0x88) + *(float *)(param_1 + 0xf4);
      *(float *)(param_1 + 0x8c) = *(float *)(iVar1 + 0x8c) + *(float *)(param_1 + 0xf8);
      *(float *)(param_1 + 0x90) = *(float *)(iVar1 + 0x90) + *(float *)(param_1 + 0xfc);
      *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(iVar1 + 0xd0);
      *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(iVar1 + 0xd4);
      *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(iVar1 + 0xd8);
      SV_LinkEdict(param_1,1);
    }
  }
  return;
}


// SV_Physics_Noclip  @ 000823b0
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


// SV_Physics_None  @ 000822cc
void SV_Physics_None(undefined4 param_1)

{
  SV_RunThink(param_1);
  return;
}


// SV_Physics_Pusher  @ 00081d84
void SV_Physics_Pusher(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  fVar1 = *(float *)(param_1 + 0x180);
  fVar2 = *(float *)(param_1 + 0x184);
  fVar4 = (float)host_frametime + fVar1;
  if ((byte)((fVar4 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar4 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    fVar4 = (float)host_frametime;
  }
  else {
    fVar4 = fVar2 - fVar1;
    if (0x3f < (byte)((0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar4 = 0.0;
    }
  }
  if ((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xdc)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0xdc) == 0.0) << 0xe) >> 8)) == 0x40)
        && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xe0)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(param_1 + 0xe0) == 0.0) << 0xe) >> 8)) == 0x40
           )) && (fVar3 = *(float *)(param_1 + 0xe4),
                 (byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40)) {
      SV_PushMove(param_1,fVar4);
    }
    else if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa0)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa0) == 0.0) << 0xe) >> 8)) ==
               0x40) &&
             ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa4)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa4) == 0.0) << 0xe) >> 8)) ==
              0x40)) &&
            (fVar3 = *(float *)(param_1 + 0xa8),
            (byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40)) {
      SV_PushRotate(param_1,fVar4);
    }
    else {
      iVar5 = SV_PushRotate(param_1,fVar4);
      if (iVar5 != 0) {
        fVar3 = *(float *)(param_1 + 0x180);
        *(float *)(param_1 + 0x180) = fVar1;
        SV_PushMove(param_1,fVar4);
        fVar4 = *(float *)(param_1 + 0x180);
        if (0x3f < (byte)((fVar3 < fVar4 |
                           (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x180) = fVar3;
        }
      }
    }
  }
  if ((0x3f < (byte)((fVar2 < fVar1 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
     (((*(byte *)(param_1 + 0x226) & 0x20) != 0 || (fVar2 <= *(float *)(param_1 + 0x180))))) {
    *(undefined4 *)(param_1 + 0x184) = 0;
    gGlobalVariables = (float)DAT_0015358c;
    (*DAT_00386228)(param_1);
  }
  return;
}


// SV_Physics_Step  @ 00082dd0
/* WARNING: Removing unreachable block (ram,0x0008309e) */
/* WARNING: Removing unreachable block (ram,0x000830ec) */

void SV_Physics_Step(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float **ppfVar6;
  longdouble lVar7;
  longdouble lVar8;
  float *pfStack_88;
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
  
  pfStack_88 = param_1;
  PF_WaterMove();
  SV_CheckVelocity(param_1);
  fVar2 = param_1[0x89];
  iVar4 = SV_CheckWater(param_1);
  if ((*(short *)(param_1 + 0x89) < 0) && (0 < (int)param_1[0x90])) {
    pfStack_88 = param_1;
    lVar7 = (longdouble)SV_Submerged();
    fVar1 = param_1[100];
    lVar8 = (longdouble)host_frametime;
    SV_AddGravity(param_1);
    param_1[0x2a] = (float)(lVar8 * lVar7 * (longdouble)(int)fVar1) + param_1[0x2a];
  }
  if ((((((uint)fVar2 & 0x200) == 0) && (((uint)param_1[0x89] & 1) == 0)) &&
      ((((uint)param_1[0x89] & 2) == 0 || ((int)param_1[0x90] < 1)))) && (iVar4 == 0)) {
    pfStack_88 = param_1;
    SV_AddGravity();
  }
  pfStack_88 = (float *)vec_origin;
  iVar4 = VectorCompare(param_1 + 0x28);
  if ((iVar4 != 0) &&
     (pfStack_88 = (float *)vec_origin, iVar4 = VectorCompare(param_1 + 0x2b), iVar4 != 0)) {
    ppfVar6 = (float **)&stack0xffffff7c;
    if ((byte)(DAT_00152b48 < 0.0 | (byte)((ushort)((ushort)NAN(DAT_00152b48) << 10) >> 8) |
              (byte)((ushort)((ushort)(DAT_00152b48 == 0.0) << 0xe) >> 8)) != 0x40) {
      pfStack_88 = (float *)((uint)param_1[0x89] >> 0x17 & 1);
      SV_Move(local_64,param_1 + 0x22,param_1 + 0x57,param_1 + 0x5a,param_1 + 0x22,0,param_1);
      if (((local_54 < 1.0) || (ppfVar6 = &pfStack_88, local_60 != 0)) &&
         (ppfVar6 = &pfStack_88, local_34 != 0)) {
        SV_Impact(param_1,local_34,local_64);
        ppfVar6 = &pfStack_88;
      }
    }
    goto LAB_000831a1;
  }
  *(byte *)((int)param_1 + 0x225) = *(byte *)((int)param_1 + 0x225) & 0xfd;
  if (((uint)fVar2 & 0x200) != 0) {
    fVar2 = param_1[0x78];
    if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
      pfStack_88 = param_1;
      iVar4 = SV_CheckBottom();
      if (iVar4 == 0) goto LAB_00082f8a;
    }
    fVar2 = param_1[0x28];
    local_8 = SQRT(param_1[0x29] * param_1[0x29] + fVar2 * fVar2);
    if ((byte)(0.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_8 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = (float)sv_friction._12_4_ * param_1[0x68];
      param_1[0x68] = 1.0;
      fVar3 = local_8;
      if (0x3f < (byte)(((float)sv_stopspeed._12_4_ < local_8 |
                         (byte)((ushort)((ushort)(NAN((float)sv_stopspeed._12_4_) || NAN(local_8))
                                        << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)sv_stopspeed._12_4_ == local_8) << 0xe) >> 8
                              )) - 1)) {
        fVar3 = (float)sv_stopspeed._12_4_;
      }
      fVar1 = local_8 - (float)host_frametime * fVar3 * fVar1;
      fVar3 = fVar1;
      if (fVar1 < 0.0) {
        fVar3 = 0.0;
      }
      param_1[0x28] = fVar2 * (fVar3 / local_8);
      param_1[0x29] = (fVar3 / local_8) * param_1[0x29];
      local_8 = fVar1;
    }
  }
LAB_00082f8a:
  param_1[0x28] = param_1[0x28] + param_1[0x2b];
  param_1[0x29] = param_1[0x29] + param_1[0x2c];
  param_1[0x2a] = param_1[0x2a] + param_1[0x2d];
  pfStack_88 = param_1;
  SV_CheckVelocity();
  local_8 = (float)host_frametime;
  SV_FlyMove(param_1,local_8,0);
  SV_CheckVelocity(param_1);
  param_1[0x28] = param_1[0x28] - param_1[0x2b];
  param_1[0x29] = param_1[0x29] - param_1[0x2c];
  param_1[0x2a] = param_1[0x2a] - param_1[0x2d];
  SV_CheckVelocity(param_1);
  local_14 = param_1[0x22] + param_1[0x57];
  local_10 = param_1[0x23] + param_1[0x58];
  local_c = param_1[0x24] + param_1[0x59];
  local_20 = param_1[0x22] + param_1[0x5a];
  local_1c = param_1[0x23] + param_1[0x5b];
  local_18 = param_1[0x24] + param_1[0x5c];
  local_24 = local_c - 1.0;
  iVar4 = 0;
  do {
    local_2c = local_14;
    if (iVar4 != 0) {
      local_2c = local_20;
    }
    local_28 = local_10;
    g_groupmask = param_1[0xb0];
    pfStack_88 = &local_2c;
    iVar5 = SV_PointContents();
    if (iVar5 == -2) {
LAB_00083113:
      *(byte *)((int)param_1 + 0x225) = *(byte *)((int)param_1 + 0x225) | 2;
    }
    else {
      local_2c = local_14;
      if (iVar4 != 0) {
        local_2c = local_20;
      }
      local_28 = local_1c;
      g_groupmask = param_1[0xb0];
      pfStack_88 = &local_2c;
      iVar5 = SV_PointContents();
      if (iVar5 == -2) goto LAB_00083113;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  pfStack_88 = (float *)0x1;
  SV_LinkEdict(param_1);
  ppfVar6 = (float **)&stack0xffffff7c;
LAB_000831a1:
  *(float **)((int)ppfVar6 + -4) = param_1;
  *(undefined4 *)((int)ppfVar6 + -8) = 0x831a7;
  SV_RunThink();
  *(float **)((int)ppfVar6 + -8) = param_1;
  *(undefined4 *)((int)ppfVar6 + -0xc) = 0x831ad;
  SV_CheckWaterTransition();
  return;
}


// SV_Physics_Toss  @ 00082630
void SV_Physics_Toss(float *param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float **ppfVar4;
  float *local_78;
  float *pfStack_74;
  float local_48;
  float local_44;
  float local_40;
  int local_3c [4];
  float local_2c;
  undefined1 local_1c [8];
  float local_14;
  float local_c;
  
  pfStack_74 = param_1;
  local_78 = (float *)0x8264e;
  SV_CheckWater();
  local_78 = param_1;
  iVar3 = SV_RunThink();
  if (iVar3 != 0) {
    fVar2 = param_1[0x2a];
    if ((((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1) ||
        (param_1[0x87] == 0.0)) || ((*(byte *)((int)param_1[0x87] + 0x224) & 0x28) != 0)) {
      *(byte *)((int)param_1 + 0x225) = *(byte *)((int)param_1 + 0x225) & 0xfd;
    }
    if ((*(byte *)((int)param_1 + 0x225) & 2) != 0) {
      local_78 = param_1 + 0x28;
      pfStack_74 = (float *)vec_origin;
      iVar3 = VectorCompare();
      if (iVar3 != 0) {
        param_1[0x37] = vec3_origin;
        param_1[0x38] = DAT_000b2e2c;
        param_1[0x39] = DAT_000b2e30;
        local_78 = param_1 + 0x2b;
        pfStack_74 = (float *)vec_origin;
        iVar3 = VectorCompare();
        if (iVar3 != 0) {
          return;
        }
      }
    }
    pfStack_74 = param_1;
    local_78 = (float *)0x826ee;
    SV_CheckVelocity();
    fVar2 = param_1[0x62];
    pfVar1 = param_1 + 0x28;
    if (((fVar2 != 7.00649e-45) && (fVar2 != 1.54143e-44)) && (fVar2 != 1.26117e-44)) {
      pfStack_74 = param_1;
      local_78 = (float *)0x82715;
      SV_AddGravity();
    }
    pfStack_74 = param_1 + 0x34;
    local_78 = param_1 + 0x37;
    VectorMA(pfStack_74,(float)host_frametime);
    param_1[0x28] = param_1[0x28] + param_1[0x2b];
    param_1[0x29] = param_1[0x29] + param_1[0x2c];
    param_1[0x2a] = param_1[0x2a] + param_1[0x2d];
    SV_CheckVelocity(param_1);
    VectorScale(pfVar1,(float)host_frametime,&local_48);
    param_1[0x28] = param_1[0x28] - param_1[0x2b];
    param_1[0x29] = param_1[0x29] - param_1[0x2c];
    param_1[0x2a] = param_1[0x2a] - param_1[0x2d];
    local_78 = param_1;
    pfStack_74 = &local_48;
    SV_PushEntity(local_3c);
    SV_CheckVelocity(param_1);
    ppfVar4 = &pfStack_74;
    if (local_3c[0] == 0) {
      if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
        if (*param_1 != 0.0) {
          return;
        }
        if (param_1[0x62] == 1.4013e-44) {
          local_78 = (float *)(2.0 - param_1[0x68]);
        }
        else {
          local_78 = (float *)0x40000000;
          if (param_1[0x62] != 1.54143e-44) {
            local_78 = (float *)0x3f800000;
          }
        }
        ClipVelocity(pfVar1,local_1c,pfVar1);
        ppfVar4 = &pfStack_74;
        if (0.7 < local_14) {
          local_48 = param_1[0x28] + param_1[0x2b];
          local_44 = param_1[0x29] + param_1[0x2c];
          local_40 = param_1[0x2a] + param_1[0x2d];
          fVar2 = (float)host_frametime * (float)sv_gravity._12_4_;
          if (0x3f < (byte)((fVar2 < local_40 |
                             (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_40)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == local_40) << 0xe) >> 8)) - 1)) {
            *(byte *)((int)param_1 + 0x225) = *(byte *)((int)param_1 + 0x225) | 2;
            param_1[0x87] = local_c;
            param_1[0x2a] = 0.0;
          }
          if ((local_40 * local_40 + local_44 * local_44 + local_48 * local_48 < 900.0) ||
             (1 < (int)param_1[0x62] - 10U)) {
            *(byte *)((int)param_1 + 0x225) = *(byte *)((int)param_1 + 0x225) | 2;
            param_1[0x87] = local_c;
            param_1[0x28] = vec3_origin;
            param_1[0x29] = DAT_000b2e2c;
            param_1[0x2a] = DAT_000b2e30;
            param_1[0x37] = vec3_origin;
            param_1[0x38] = DAT_000b2e2c;
            param_1[0x39] = DAT_000b2e30;
            ppfVar4 = &pfStack_74;
          }
          else {
            local_78 = &local_48;
            VectorScale(pfVar1,(1.0 - local_2c) * (float)host_frametime * 0.9);
            VectorMA(&local_48,(1.0 - local_2c) * (float)host_frametime * 0.9,param_1 + 0x2b,
                     &local_48);
            SV_PushEntity(local_3c,param_1,&local_48);
            ppfVar4 = &local_78;
          }
        }
      }
      *(float **)((int)ppfVar4 + -4) = param_1;
      *(undefined4 *)((int)ppfVar4 + -8) = 0x82a0c;
      SV_CheckWaterTransition();
    }
    else {
      param_1[0x28] = vec3_origin;
      param_1[0x29] = DAT_000b2e2c;
      param_1[0x2a] = DAT_000b2e30;
      param_1[0x37] = vec3_origin;
      param_1[0x38] = DAT_000b2e2c;
      param_1[0x39] = DAT_000b2e30;
    }
  }
  return;
}


// SV_PlayerRunPreThink  @ 000852ac
void SV_PlayerRunPreThink(undefined4 param_1,undefined4 param_2)

{
  gGlobalVariables = param_2;
  (*DAT_0038627c)(param_1);
  return;
}


// SV_PlayerRunThink  @ 000852e0
bool SV_PlayerRunThink(int *param_1,float param_2,double param_3)

{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)param_3;
  if ((*(byte *)((int)param_1 + 0x227) & 0x40) == 0) {
    fVar1 = (float)param_1[0x61];
    if ((fVar1 <= 0.0) ||
       (param_2 = fVar2 + param_2,
       0x3f < (byte)((fVar1 < param_2 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == param_2) << 0xe) >> 8)) - 1))) {
      return true;
    }
    if (fVar1 < fVar2) {
      fVar1 = fVar2;
    }
    param_1[0x61] = 0;
    gGlobalVariables = fVar1;
    (*DAT_00386228)(param_1);
    if ((*(byte *)((int)param_1 + 0x227) & 0x40) == 0) goto LAB_00085381;
  }
  ED_Free(param_1);
LAB_00085381:
  return *param_1 == 0;
}


// SV_PointContents  @ 0008c144
int SV_PointContents(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = SV_HullPointContents(DAT_00153668 + 0xd0,0,param_1);
  if (iVar1 + 0xeU < 6) {
    iVar1 = -3;
  }
  if ((iVar1 != -2) && (iVar2 = SV_LinkContents(&sv_areanodes,param_1), iVar2 != -1)) {
    return iVar2;
  }
  return iVar1;
}


// SV_PointLeafnum  @ 000795c0
int SV_PointLeafnum(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Mod_PointInLeaf(param_1,DAT_00153668);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (iVar1 - *(int *)(DAT_00153668 + 0x8c)) * -0x55555555 >> 4;
  }
  return iVar1;
}


// SV_PreRunCmd  @ 000849e0
void SV_PreRunCmd(void)

{
  return;
}


// SV_ProcessFile  @ 00078590
void SV_ProcessFile(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 local_14 [16];
  
  if (*param_2 == '!') {
    COM_HexConvert(param_2 + 4,0x20,local_14);
    iVar3 = *(int *)(param_1 + 0x4d8c);
    do {
      iVar1 = iVar3;
      if (iVar1 == param_1 + 0x4d0c) {
        Con_Printf("SV_ProcessFile:  Unrequested decal\n");
        return;
      }
      iVar3 = *(int *)(iVar1 + 0x80);
      iVar2 = Q_memcmp(iVar1 + 0x4d,local_14,0x10);
    } while (iVar2 != 0);
    HPAK_AddLump(1,"custom.hpk",iVar1,*(undefined4 *)(param_1 + 0x2124),0);
    *(byte *)(iVar1 + 0x4c) = *(byte *)(iVar1 + 0x4c) & 0xfd;
    SV_MoveToOnHandList(iVar1);
    iVar3 = *(int *)(param_1 + 0x4f48);
    if (iVar3 != 0) {
      do {
        iVar2 = Q_memcmp(iVar3 + 0x51,iVar1 + 0x4d,0x10);
        if (iVar2 == 0) {
          Con_DPrintf("Duplicate resource received and ignored.\n");
          return;
        }
        iVar3 = *(int *)(iVar3 + 0xa0);
      } while (iVar3 != 0);
    }
    iVar3 = COM_CreateCustomization(param_1 + 0x4ea8,iVar1,0xffffffff,7,0,0);
    if (iVar3 != 0) {
      return;
    }
    param_2 = (char *)(param_1 + 0x4c3c);
    pcVar4 = "Error parsing custom decal from %s\n";
  }
  else {
    pcVar4 = "Ignoring non-customization file upload of %s\n";
  }
  Con_Printf(pcVar4,param_2);
  return;
}


// SV_PropagateCustomizations  @ 0007b484
void SV_PropagateCustomizations(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_10;
  
  iVar2 = (int)host_client;
  host_client = DAT_001ab4e4;
  for (local_10 = 0; local_10 < DAT_001ab4e8; local_10 = local_10 + 1) {
    if (((*host_client != 0) || (host_client[1] != 0)) && (host_client[0x918] == 0)) {
      for (piVar1 = (int *)host_client[0x13d2]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x28])
      {
        if (*piVar1 != 0) {
          iVar3 = iVar2 + 0x74;
          MSG_WriteByte(iVar3,0x2e);
          MSG_WriteByte(iVar3,local_10);
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
    host_client = host_client + 0x1415;
  }
  host_client = (int *)iVar2;
  return;
}


// SV_PushEntity  @ 00080e90
undefined4 * SV_PushEntity(undefined4 *param_1,int param_2,float *param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
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
  
  local_48 = *(float *)(param_2 + 0x88) + *param_3;
  local_44 = *(float *)(param_2 + 0x8c) + param_3[1];
  local_40 = *(float *)(param_2 + 0x90) + param_3[2];
  if (*(int *)(param_2 + 0x188) == 9) {
    uVar2 = 2;
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x18c) < 2;
  }
  SV_Move(local_3c,param_2 + 0x88,param_2 + 0x15c,param_2 + 0x168,&local_48,uVar2,param_2,
          (*(byte *)(param_2 + 0x226) & 0x80) != 0);
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
  puVar3 = local_3c;
  puVar4 = param_1;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return param_1;
}


// SV_PushMove  @ 00080f94
void SV_PushMove(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  int aiStackY_c8 [6];
  int local_94;
  int local_90;
  int local_8c;
  uint local_84;
  int local_80;
  int local_7c;
  undefined1 local_78 [56];
  float local_40;
  float local_3c;
  float local_38;
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
  
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa0) == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa4) == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xa8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0xa8) == 0.0) << 0xe) >> 8)) == 0x40)) {
    *(float *)(param_1 + 0x180) = param_2 + *(float *)(param_1 + 0x180);
  }
  else {
    local_40 = *(float *)(param_1 + 0x88);
    local_3c = *(float *)(param_1 + 0x8c);
    local_38 = *(float *)(param_1 + 0x90);
    local_28 = param_2 * *(float *)(param_1 + 0xa0);
    local_10 = *(float *)(param_1 + 0x144) + local_28;
    local_1c = *(float *)(param_1 + 0x150) + local_28;
    *(float *)(param_1 + 0x88) = local_40 + local_28;
    local_24 = param_2 * *(float *)(param_1 + 0xa4);
    local_c = *(float *)(param_1 + 0x148) + local_24;
    local_18 = *(float *)(param_1 + 0x154) + local_24;
    *(float *)(param_1 + 0x8c) = local_3c + local_24;
    local_20 = param_2 * *(float *)(param_1 + 0xa8);
    local_8 = *(float *)(param_1 + 0x14c) + local_20;
    local_14 = *(float *)(param_1 + 0x158) + local_20;
    *(float *)(param_1 + 0x90) = local_38 + local_20;
    *(float *)(param_1 + 0x180) = param_2 + *(float *)(param_1 + 0x180);
    SV_LinkEdict(param_1,0);
    if (*(int *)(param_1 + 0x18c) != 0) {
      local_84 = 0;
      local_80 = 1;
      if (1 < DAT_00186f8c) {
        local_90 = 0x324;
        local_94 = 0;
        puVar4 = &stack0xffffff58;
        do {
          piVar6 = (int *)(local_90 + DAT_00186f94);
          puVar5 = puVar4;
          if (((*piVar6 == 0) && (iVar3 = piVar6[0x62], iVar3 != 7)) &&
             ((iVar3 != 0 && ((iVar3 != 0xc && (iVar3 != 8)))))) {
            if (((*(byte *)((int)piVar6 + 0x225) & 2) == 0) || (piVar6[0x87] != param_1)) {
              fVar1 = (float)piVar6[0x51];
              if (((((0x3f < (byte)((local_1c < fVar1 |
                                     (byte)((ushort)((ushort)(NAN(local_1c) || NAN(fVar1)) << 10) >>
                                           8) |
                                    (byte)((ushort)((ushort)(local_1c == fVar1) << 0xe) >> 8)) - 1))
                    && (fVar1 = (float)piVar6[0x52],
                       0x3f < (byte)((local_18 < fVar1 |
                                      (byte)((ushort)((ushort)(NAN(local_18) || NAN(fVar1)) << 10)
                                            >> 8) |
                                     (byte)((ushort)((ushort)(local_18 == fVar1) << 0xe) >> 8)) - 1)
                       )) && (fVar1 = (float)piVar6[0x53],
                             0x3f < (byte)((local_14 < fVar1 |
                                            (byte)((ushort)((ushort)(NAN(local_14) || NAN(fVar1)) <<
                                                           10) >> 8) |
                                           (byte)((ushort)((ushort)(local_14 == fVar1) << 0xe) >> 8)
                                           ) - 1))) &&
                  ((local_10 < (float)piVar6[0x54] && (local_c < (float)piVar6[0x55])))) &&
                 (local_8 < (float)piVar6[0x56])) {
                *(int **)(puVar4 + -4) = piVar6;
                *(undefined4 *)(puVar4 + -8) = 0x811f0;
                iVar3 = SV_TestEntityPosition();
                if (iVar3 != 0) goto LAB_000811fb;
              }
            }
            else {
LAB_000811fb:
              if (piVar6[0x62] != 3) {
                *(byte *)((int)piVar6 + 0x225) = *(byte *)((int)piVar6 + 0x225) & 0xfd;
              }
              local_34 = piVar6[0x22];
              local_30 = piVar6[0x23];
              local_2c = piVar6[0x24];
              *(int *)((int)g_moved_from + local_94) = piVar6[0x22];
              *(int *)((int)g_moved_from + local_94 + 4) = piVar6[0x23];
              *(int *)((int)g_moved_from + local_94 + 8) = piVar6[0x24];
              g_moved_edict[local_84] = (int)piVar6;
              local_94 = local_94 + 0xc;
              local_84 = local_84 + 1;
              *(undefined4 *)(param_1 + 0x18c) = 0;
              *(float **)(puVar4 + -4) = &local_28;
              *(int **)(puVar4 + -8) = piVar6;
              *(undefined1 **)(puVar4 + -0xc) = local_78;
              *(undefined4 *)(puVar4 + -0x10) = 0x812c3;
              SV_PushEntity();
              *(undefined4 *)(param_1 + 0x18c) = 4;
              *(int **)(puVar4 + -0x10) = piVar6;
              *(undefined4 *)(puVar4 + -0x14) = 0x812d3;
              iVar3 = SV_TestEntityPosition();
              puVar5 = puVar4 + -4;
              if (iVar3 != 0) {
                fVar1 = (float)piVar6[0x57];
                fVar2 = (float)piVar6[0x5a];
                puVar5 = puVar4 + -4;
                if ((byte)(fVar2 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
                  if (1 < (uint)piVar6[99]) {
                    piVar6[0x22] = local_34;
                    piVar6[0x23] = local_30;
                    piVar6[0x24] = local_2c;
                    *(undefined4 *)(puVar4 + -8) = 1;
                    *(int **)(puVar4 + -0xc) = piVar6;
                    *(undefined4 *)(puVar4 + -0x10) = 0x81363;
                    SV_LinkEdict();
                    *(float *)(param_1 + 0x88) = local_40;
                    *(float *)(param_1 + 0x8c) = local_3c;
                    *(float *)(param_1 + 0x90) = local_38;
                    *(undefined4 *)(puVar4 + -0x10) = 0;
                    *(int *)(puVar4 + -0x14) = param_1;
                    *(undefined4 *)(puVar4 + -0x18) = 0x81386;
                    SV_LinkEdict();
                    *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) - param_2;
                    *(int **)(puVar4 + -0x18) = piVar6;
                    *(int *)(puVar4 + -0x1c) = param_1;
                    *(undefined4 *)(puVar4 + -0x20) = 0x813a2;
                    (*DAT_00386234)();
                    local_7c = 0;
                    if ((int)local_84 < 1) {
                      return;
                    }
                    local_8c = 0;
                    if ((local_84 & 1) != 0) {
                      *(undefined4 *)(*g_moved_edict + 0x88) = *g_moved_from;
                      *(undefined4 *)(*g_moved_edict + 0x8c) = g_moved_from[1];
                      *(undefined4 *)(*g_moved_edict + 0x90) = g_moved_from[2];
                      *(undefined4 *)(puVar4 + -8) = 0;
                      *(int *)(puVar4 + -0xc) = *g_moved_edict;
                      *(undefined4 *)(puVar4 + -0x10) = 0x8142c;
                      SV_LinkEdict();
                      local_8c = 0xc;
                      local_7c = 1;
                      if ((int)local_84 < 2) {
                        return;
                      }
                    }
                    do {
                      *(undefined4 *)(g_moved_edict[local_7c] + 0x88) =
                           *(undefined4 *)((int)g_moved_from + local_8c);
                      *(undefined4 *)(g_moved_edict[local_7c] + 0x8c) =
                           *(undefined4 *)((int)g_moved_from + local_8c + 4);
                      *(undefined4 *)(g_moved_edict[local_7c] + 0x90) =
                           *(undefined4 *)((int)g_moved_from + local_8c + 8);
                      *(undefined4 *)(puVar4 + -8) = 0;
                      *(int *)(puVar4 + -0xc) = g_moved_edict[local_7c];
                      *(undefined4 *)(puVar4 + -0x10) = 0x8150d;
                      SV_LinkEdict();
                      iVar3 = local_7c + 1;
                      *(undefined4 *)(g_moved_edict[iVar3] + 0x88) =
                           *(undefined4 *)((int)g_moved_from + local_8c + 0xc);
                      *(undefined4 *)(g_moved_edict[iVar3] + 0x8c) =
                           *(undefined4 *)((int)g_moved_from + local_8c + 0x10);
                      *(undefined4 *)(g_moved_edict[iVar3] + 0x90) =
                           *(undefined4 *)((int)g_moved_from + local_8c + 0x14);
                      *(undefined4 *)(puVar4 + -8) = 0;
                      *(int *)(puVar4 + -0xc) = g_moved_edict[iVar3];
                      *(undefined4 *)(puVar4 + -0x10) = 0x815ae;
                      SV_LinkEdict();
                      local_8c = local_8c + 0x18;
                      local_7c = local_7c + 2;
                    } while (local_7c < (int)local_84);
                    return;
                  }
                  piVar6[0x58] = 0;
                  piVar6[0x57] = 0;
                  piVar6[0x5a] = 0;
                  piVar6[0x5b] = 0;
                  piVar6[0x5c] = piVar6[0x59];
                  puVar5 = puVar4 + -4;
                }
              }
            }
          }
          local_90 = local_90 + 0x324;
          local_80 = local_80 + 1;
          puVar4 = puVar5;
        } while (local_80 < DAT_00186f8c);
      }
    }
  }
  return;
}


// SV_PushRotate  @ 000815fc
undefined4 SV_PushRotate(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  int local_f4;
  int local_f0;
  int local_e4;
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
  float local_34;
  float local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xdc)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0xdc) == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xe0)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0xe0) == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xe4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0xe4) == 0.0) << 0xe) >> 8)) == 0x40)) {
    *(float *)(param_1 + 0x180) = param_2 + *(float *)(param_1 + 0x180);
  }
  else {
    local_1c = param_2 * *(float *)(param_1 + 0xdc);
    local_18 = param_2 * *(float *)(param_1 + 0xe0);
    local_14 = param_2 * *(float *)(param_1 + 0xe4);
    AngleVectors(param_1 + 0xd0,&local_88,&local_94,&local_a0);
    local_34 = *(float *)(param_1 + 0xd0);
    local_30 = *(float *)(param_1 + 0xd4);
    local_2c = *(float *)(param_1 + 0xd8);
    *(float *)(param_1 + 0xd0) = local_34 + local_1c;
    *(float *)(param_1 + 0xd4) = local_30 + local_18;
    *(float *)(param_1 + 0xd8) = local_2c + local_14;
    AngleVectorsTranspose(param_1 + 0xd0,&local_64,&local_70,&local_7c);
    *(float *)(param_1 + 0x180) = param_2 + *(float *)(param_1 + 0x180);
    SV_LinkEdict(param_1,0);
    if (*(int *)(param_1 + 0x18c) != 0) {
      local_e4 = 0;
      local_e0 = 1;
      local_1c = 0.0;
      local_14 = 0.0;
      if (1 < DAT_00186f8c) {
        local_f0 = 0x324;
        local_f4 = 0;
        puVar5 = &stack0xfffffef8;
        do {
          piVar7 = (int *)(local_f0 + DAT_00186f94);
          puVar6 = puVar5;
          if (((*piVar7 == 0) && (iVar4 = piVar7[0x62], iVar4 != 7)) &&
             ((iVar4 != 0 && ((iVar4 != 0xc && (iVar4 != 8)))))) {
            if (((*(byte *)((int)piVar7 + 0x225) & 2) == 0) || (piVar7[0x87] != param_1)) {
              fVar1 = *(float *)(param_1 + 0x150);
              fVar2 = (float)piVar7[0x51];
              if (0x3f < (byte)((fVar1 < fVar2 |
                                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
                fVar1 = *(float *)(param_1 + 0x154);
                fVar2 = (float)piVar7[0x52];
                if (0x3f < (byte)((fVar1 < fVar2 |
                                   (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
                  fVar1 = *(float *)(param_1 + 0x158);
                  fVar2 = (float)piVar7[0x53];
                  if ((((0x3f < (byte)((fVar1 < fVar2 |
                                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >>
                                              8) |
                                       (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
                       && (*(float *)(param_1 + 0x144) < (float)piVar7[0x54])) &&
                      (*(float *)(param_1 + 0x148) < (float)piVar7[0x55])) &&
                     (*(float *)(param_1 + 0x14c) < (float)piVar7[0x56])) {
                    *(int **)(puVar5 + -4) = piVar7;
                    *(undefined4 *)(puVar5 + -8) = 0x81866;
                    iVar4 = SV_TestEntityPosition();
                    if (iVar4 != 0) goto LAB_00081871;
                  }
                }
              }
            }
            else {
LAB_00081871:
              if (piVar7[0x62] != 3) {
                *(byte *)((int)piVar7 + 0x225) = *(byte *)((int)piVar7 + 0x225) & 0xfd;
              }
              local_28 = piVar7[0x22];
              local_24 = piVar7[0x23];
              local_20 = piVar7[0x24];
              *(int *)(g_moved_from + local_f4) = piVar7[0x22];
              *(int *)(local_f4 + g_moved_from + 4) = piVar7[0x23];
              *(int *)(local_f4 + g_moved_from + 8) = piVar7[0x24];
              *(int **)(g_moved_edict + local_e4 * 4) = piVar7;
              local_f4 = local_f4 + 0xc;
              local_e4 = local_e4 + 1;
              if (DAT_00186f90 <= local_e4) {
                *(char **)(puVar5 + -4) = "Out of edicts in simulator!\n";
                *(undefined4 *)(puVar5 + -8) = 0x81947;
                Sys_Error();
              }
              if (piVar7[0x62] == 0xd) {
                local_44 = ((float)piVar7[0x53] + (float)piVar7[0x56]) * 0.5;
                local_4c = ((float)piVar7[0x51] + (float)piVar7[0x54]) * 0.5 -
                           *(float *)(param_1 + 0x88);
                local_48 = ((float)piVar7[0x52] + (float)piVar7[0x55]) * 0.5 -
                           *(float *)(param_1 + 0x8c);
                local_a4 = local_44;
              }
              else {
                local_4c = (float)piVar7[0x22] - *(float *)(param_1 + 0x88);
                local_48 = (float)piVar7[0x23] - *(float *)(param_1 + 0x8c);
                local_44 = (float)piVar7[0x24];
              }
              local_44 = local_44 - *(float *)(param_1 + 0x90);
              local_40 = local_44 * local_80 + local_48 * local_84 + local_4c * local_88;
              local_38 = local_44 * local_98 + local_48 * local_9c + local_4c * local_a0;
              local_3c = -(local_44 * local_8c + local_48 * local_90 + local_4c * local_94);
              local_58 = local_38 * local_5c + local_3c * local_60 + local_40 * local_64;
              local_54 = local_38 * local_68 + local_3c * local_6c + local_40 * local_70;
              local_50 = local_38 * local_74 + local_3c * local_78 + local_40 * local_7c;
              local_10 = local_58 - local_4c;
              local_c = local_54 - local_48;
              local_8 = local_50 - local_44;
              *(undefined4 *)(param_1 + 0x18c) = 0;
              *(float **)(puVar5 + -4) = &local_10;
              *(int **)(puVar5 + -8) = piVar7;
              *(undefined1 **)(puVar5 + -0xc) = local_dc;
              *(undefined4 *)(puVar5 + -0x10) = 0x81adc;
              SV_PushEntity();
              *(undefined4 *)(param_1 + 0x18c) = 4;
              if (piVar7[0x62] != 0xd) {
                if ((*(byte *)(piVar7 + 0x89) & 8) == 0) {
                  piVar7[0x34] = (int)((float)piVar7[0x34] + local_1c);
                  piVar7[0x35] = (int)((float)piVar7[0x35] + local_18);
                  piVar7[0x36] = (int)((float)piVar7[0x36] + local_14);
                }
                else {
                  piVar7[0x48] = 2;
                  piVar7[0x38] = (int)((float)piVar7[0x38] + local_18);
                }
              }
              *(int **)(puVar5 + -8) = piVar7;
              *(undefined4 *)(puVar5 + -0xc) = 0x81b4b;
              iVar4 = SV_TestEntityPosition();
              puVar6 = puVar5 + -4;
              if (iVar4 != 0) {
                fVar1 = (float)piVar7[0x57];
                fVar2 = (float)piVar7[0x5a];
                puVar6 = puVar5 + -4;
                if ((byte)(fVar2 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
                  if (1 < (uint)piVar7[99]) {
                    piVar7[0x22] = local_28;
                    piVar7[0x23] = local_24;
                    piVar7[0x24] = local_20;
                    *(undefined4 *)(puVar5 + -8) = 1;
                    *(int **)(puVar5 + -0xc) = piVar7;
                    *(undefined4 *)(puVar5 + -0x10) = 0x81bd7;
                    SV_LinkEdict();
                    *(float *)(param_1 + 0xd0) = local_34;
                    *(float *)(param_1 + 0xd4) = local_30;
                    *(float *)(param_1 + 0xd8) = local_2c;
                    *(undefined4 *)(puVar5 + -0x10) = 0;
                    *(int *)(puVar5 + -0x14) = param_1;
                    *(undefined4 *)(puVar5 + -0x18) = 0x81bfa;
                    SV_LinkEdict();
                    *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x180) - param_2;
                    *(int **)(puVar5 + -0x18) = piVar7;
                    *(int *)(puVar5 + -0x1c) = param_1;
                    *(undefined4 *)(puVar5 + -0x20) = 0x81c16;
                    (*DAT_00386234)();
                    if (0 < local_e4) {
                      iVar8 = 0;
                      iVar4 = 0;
                      do {
                        *(undefined4 *)(*(int *)(g_moved_edict + iVar4 * 4) + 0x88) =
                             *(undefined4 *)(g_moved_from + iVar8);
                        *(undefined4 *)(*(int *)(g_moved_edict + iVar4 * 4) + 0x8c) =
                             *(undefined4 *)(iVar8 + g_moved_from + 4);
                        *(undefined4 *)(*(int *)(g_moved_edict + iVar4 * 4) + 0x90) =
                             *(undefined4 *)(iVar8 + g_moved_from + 8);
                        iVar3 = *(int *)(g_moved_edict + iVar4 * 4);
                        if ((*(byte *)(iVar3 + 0x224) & 8) == 0) {
                          if (*(int *)(iVar3 + 0x188) != 0xd) {
                            *(float *)(iVar3 + 0xd0) = *(float *)(iVar3 + 0xd0) - local_1c;
                            iVar3 = *(int *)(g_moved_edict + iVar4 * 4);
                            *(float *)(iVar3 + 0xd4) = *(float *)(iVar3 + 0xd4) - local_18;
                            iVar3 = *(int *)(g_moved_edict + iVar4 * 4);
                            *(float *)(iVar3 + 0xd8) = *(float *)(iVar3 + 0xd8) - local_14;
                          }
                        }
                        else {
                          *(undefined4 *)(iVar3 + 0xe0) = 0;
                        }
                        *(undefined4 *)(puVar5 + -8) = 0;
                        *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(g_moved_edict + iVar4 * 4);
                        *(undefined4 *)(puVar5 + -0x10) = 0x81d31;
                        SV_LinkEdict();
                        iVar8 = iVar8 + 0xc;
                        iVar4 = iVar4 + 1;
                      } while (iVar4 < local_e4);
                    }
                    return 0;
                  }
                  piVar7[0x58] = 0;
                  piVar7[0x57] = 0;
                  piVar7[0x5a] = 0;
                  piVar7[0x5b] = 0;
                  piVar7[0x5c] = piVar7[0x59];
                  puVar6 = puVar5 + -4;
                }
              }
            }
          }
          local_f0 = local_f0 + 0x324;
          local_e0 = local_e0 + 1;
          puVar5 = puVar6;
        } while (local_e0 < DAT_00186f8c);
      }
    }
  }
  return 1;
}


// SV_QueryMovevarsChanged  @ 0007423c
void SV_QueryMovevarsChanged(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *local_c;
  int local_8;
  
  if (((((((((byte)((byte)((ushort)((ushort)(NAN(DAT_00152588) || NAN((float)sv_maxspeed._12_4_)) <<
                                   10) >> 8) |
                   (byte)((ushort)((ushort)(DAT_00152588 == (float)sv_maxspeed._12_4_) << 0xe) >> 8)
                   ) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN((float)sv_gravity._12_4_) || NAN(movevars)) << 10)
                         >> 8) |
                  (byte)((ushort)((ushort)((float)sv_gravity._12_4_ == movevars) << 0xe) >> 8)) ==
            0x40)) &&
          ((byte)((byte)((ushort)((ushort)(NAN((float)sv_stopspeed._12_4_) || NAN(DAT_00152584)) <<
                                 10) >> 8) |
                 (byte)((ushort)((ushort)((float)sv_stopspeed._12_4_ == DAT_00152584) << 0xe) >> 8))
           == 0x40)) &&
         ((((byte)((byte)((ushort)((ushort)(NAN((float)sv_spectatormaxspeed._12_4_) ||
                                           NAN(DAT_0015258c)) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)sv_spectatormaxspeed._12_4_ == DAT_0015258c) <<
                                 0xe) >> 8)) == 0x40 &&
           ((byte)((byte)((ushort)((ushort)(NAN((float)sv_accelerate._12_4_) || NAN(DAT_00152590))
                                  << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)sv_accelerate._12_4_ == DAT_00152590) << 0xe) >> 8
                        )) == 0x40)) &&
          (((byte)((byte)((ushort)((ushort)(NAN((float)sv_airaccelerate._12_4_) || NAN(DAT_00152594)
                                           ) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)sv_airaccelerate._12_4_ == DAT_00152594) << 0xe)
                        >> 8)) == 0x40 &&
           (((byte)((byte)((ushort)((ushort)(NAN((float)sv_wateraccelerate._12_4_) ||
                                            NAN(DAT_00152598)) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)sv_wateraccelerate._12_4_ == DAT_00152598) << 0xe
                                  ) >> 8)) == 0x40 &&
            ((byte)((byte)((ushort)((ushort)(NAN((float)sv_friction._12_4_) || NAN(DAT_0015259c)) <<
                                   10) >> 8) |
                   (byte)((ushort)((ushort)((float)sv_friction._12_4_ == DAT_0015259c) << 0xe) >> 8)
                   ) == 0x40)))))))) &&
        ((byte)((byte)((ushort)((ushort)(NAN((float)sv_edgefriction._12_4_) || NAN(DAT_001525a0)) <<
                               10) >> 8) |
               (byte)((ushort)((ushort)((float)sv_edgefriction._12_4_ == DAT_001525a0) << 0xe) >> 8)
               ) == 0x40)) &&
       ((((byte)((byte)((ushort)((ushort)(NAN((float)sv_waterfriction._12_4_) || NAN(DAT_001525a4))
                                << 10) >> 8) |
                (byte)((ushort)((ushort)((float)sv_waterfriction._12_4_ == DAT_001525a4) << 0xe) >>
                      8)) == 0x40 &&
         ((byte)((byte)((ushort)((ushort)NAN(DAT_001525a8) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_001525a8 == 1.0) << 0xe) >> 8)) == 0x40)) &&
        ((byte)((byte)((ushort)((ushort)(NAN((float)sv_bounce._12_4_) || NAN(DAT_001525ac)) << 10)
                      >> 8) |
               (byte)((ushort)((ushort)((float)sv_bounce._12_4_ == DAT_001525ac) << 0xe) >> 8)) ==
         0x40)))) &&
      ((((byte)((byte)((ushort)((ushort)(NAN((float)sv_stepsize._12_4_) || NAN(DAT_001525b0)) << 10)
                      >> 8) |
               (byte)((ushort)((ushort)((float)sv_stepsize._12_4_ == DAT_001525b0) << 0xe) >> 8)) ==
         0x40 && ((byte)((byte)((ushort)((ushort)(NAN((float)sv_maxvelocity._12_4_) ||
                                                 NAN(DAT_001525b4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)sv_maxvelocity._12_4_ == DAT_001525b4) <<
                                       0xe) >> 8)) == 0x40)) &&
       (((byte)((byte)((ushort)((ushort)(NAN((float)sv_zmax._12_4_) || NAN(DAT_001525b8)) << 10) >>
                      8) |
               (byte)((ushort)((ushort)((float)sv_zmax._12_4_ == DAT_001525b8) << 0xe) >> 8)) ==
         0x40 && (((byte)((byte)((ushort)((ushort)(NAN((float)sv_wateramp._12_4_) ||
                                                  NAN(DAT_001525bc)) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)sv_wateramp._12_4_ == DAT_001525bc) << 0xe)
                               >> 8)) == 0x40 &&
                  ((byte)((byte)((ushort)((ushort)(NAN((float)sv_footsteps._12_4_) ||
                                                  NAN((float)DAT_001525c0)) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)sv_footsteps._12_4_ == (float)DAT_001525c0)
                                        << 0xe) >> 8)) == 0x40)))))))) &&
     (((byte)((byte)((ushort)((ushort)(NAN((float)sv_rollangle._12_4_) || NAN(DAT_001525e4)) << 10)
                    >> 8) |
             (byte)((ushort)((ushort)((float)sv_rollangle._12_4_ == DAT_001525e4) << 0xe) >> 8)) ==
       0x40 && ((((((byte)((byte)((ushort)((ushort)(NAN((float)sv_rollspeed._12_4_) ||
                                                   NAN(DAT_001525e8)) << 10) >> 8) |
                          (byte)((ushort)((ushort)((float)sv_rollspeed._12_4_ == DAT_001525e8) <<
                                         0xe) >> 8)) == 0x40 &&
                   ((byte)((byte)((ushort)((ushort)(NAN((float)sv_skycolor_r._12_4_) ||
                                                   NAN(DAT_001525ec)) << 10) >> 8) |
                          (byte)((ushort)((ushort)((float)sv_skycolor_r._12_4_ == DAT_001525ec) <<
                                         0xe) >> 8)) == 0x40)) &&
                  ((byte)((byte)((ushort)((ushort)(NAN((float)sv_skycolor_g._12_4_) ||
                                                  NAN(DAT_001525f0)) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)sv_skycolor_g._12_4_ == DAT_001525f0) <<
                                        0xe) >> 8)) == 0x40)) &&
                 (((byte)((byte)((ushort)((ushort)(NAN((float)sv_skycolor_b._12_4_) ||
                                                  NAN(DAT_001525f4)) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)sv_skycolor_b._12_4_ == DAT_001525f4) <<
                                        0xe) >> 8)) == 0x40 &&
                  ((byte)((byte)((ushort)((ushort)(NAN((float)sv_skyvec_x._12_4_) ||
                                                  NAN(DAT_001525f8)) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)sv_skyvec_x._12_4_ == DAT_001525f8) << 0xe)
                               >> 8)) == 0x40)))) &&
                (((byte)((byte)((ushort)((ushort)(NAN((float)sv_skyvec_y._12_4_) ||
                                                 NAN(DAT_001525fc)) << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)sv_skyvec_y._12_4_ == DAT_001525fc) << 0xe)
                              >> 8)) == 0x40 &&
                 (((byte)((byte)((ushort)((ushort)(NAN((float)sv_skyvec_z._12_4_) ||
                                                  NAN(DAT_00152600)) << 10) >> 8) |
                         (byte)((ushort)((ushort)((float)sv_skyvec_z._12_4_ == DAT_00152600) << 0xe)
                               >> 8)) == 0x40 &&
                  (iVar1 = Q_strcmp(sv_skyname._4_4_,&DAT_001525c4), iVar1 == 0)))))))))) {
    return;
  }
  SV_SetMoveVars();
  local_8 = 0;
  if (0 < DAT_001ab4e8) {
    local_c = DAT_001ab4e4 + 0x1d;
    piVar2 = DAT_001ab4e4 + 3;
    piVar3 = DAT_001ab4e4;
    do {
      if ((piVar2[0x915] == 0) && (((*piVar3 != 0 || (piVar2[-2] != 0)) || (*piVar2 != 0)))) {
        SV_WriteMovevarsToClient(local_c);
      }
      local_8 = local_8 + 1;
      piVar2 = piVar2 + 0x1415;
      local_c = local_c + 0x1415;
      piVar3 = piVar3 + 0x1415;
    } while (local_8 < DAT_001ab4e8);
  }
  return;
}


// SV_Rcon  @ 00077ff4
void SV_Rcon(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  char *apcStack_243c [9];
  int local_2408;
  char local_2404 [8192];
  undefined1 local_404 [1024];
  
  apcStack_243c[8] = (char *)0x78011;
  iVar1 = SV_Rcon_Validate();
  apcStack_243c[7] = (char *)0x78023;
  apcStack_243c[8] = &DAT_000ab433;
  iVar2 = Q_strlen();
  iVar2 = DAT_00226fec - iVar2;
  if ((0 < iVar2) && (iVar2 < 0x1fff)) {
    apcStack_243c[6] = (char *)0x7804e;
    apcStack_243c[7] = &DAT_000ab433;
    apcStack_243c[8] = (char *)iVar2;
    iVar3 = Q_strlen();
    apcStack_243c[7] = (char *)(iVar3 + DAT_00226fe4);
    apcStack_243c[5] = (char *)0x7806f;
    apcStack_243c[6] = local_2404;
    Q_memcpy();
    local_2404[iVar2] = '\0';
    if (iVar1 == 0) {
      puVar4 = param_1;
      ppcVar5 = apcStack_243c + 3;
      apcStack_243c[8] = local_2404;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppcVar5 = (char *)*puVar4;
        puVar4 = puVar4 + 1;
        ppcVar5 = ppcVar5 + 1;
      }
      apcStack_243c[2] = (char *)0x7809b;
      apcStack_243c[7] = (char *)NET_AdrToString();
      apcStack_243c[6] = "Bad Rcon from %s:\n%s\n";
      apcStack_243c[5] = (char *)0x780ab;
      Con_Printf();
      puVar4 = param_1;
      ppcVar5 = apcStack_243c;
      apcStack_243c[5] = local_2404;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppcVar5 = (char *)*puVar4;
        puVar4 = puVar4 + 1;
        ppcVar5 = ppcVar5 + 1;
      }
      apcStack_243c[4] = (char *)NET_AdrToString();
      apcStack_243c[3] = "Bad Rcon from \"%s\":\"(%s)\"\n";
      apcStack_243c[2] = (char *)0x780d7;
      Log_Printf();
    }
    if (iVar1 == 1) {
      puVar4 = param_1;
      ppcVar5 = apcStack_243c + 3;
      apcStack_243c[8] = local_2404;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppcVar5 = (char *)*puVar4;
        puVar4 = puVar4 + 1;
        ppcVar5 = ppcVar5 + 1;
      }
      apcStack_243c[2] = (char *)0x780ff;
      apcStack_243c[7] = (char *)NET_AdrToString();
      apcStack_243c[6] = "Rcon from %s:\n%s\n";
      apcStack_243c[5] = (char *)0x7810f;
      Con_Printf();
      puVar4 = param_1;
      ppcVar5 = apcStack_243c;
      apcStack_243c[5] = local_2404;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppcVar5 = (char *)*puVar4;
        puVar4 = puVar4 + 1;
        ppcVar5 = ppcVar5 + 1;
      }
      apcStack_243c[4] = (char *)NET_AdrToString();
      apcStack_243c[3] = "Rcon from \"%s\":\"(%s)\"\n";
      apcStack_243c[2] = (char *)0x7813b;
      Log_Printf();
    }
    apcStack_243c[8] = (char *)param_1;
    apcStack_243c[7] = (char *)0x2;
    apcStack_243c[6] = (undefined1 *)0x78149;
    SV_BeginRedirect();
    if (iVar1 == 0) {
      apcStack_243c[8] = "Bad rcon_password.\n";
      apcStack_243c[7] = (undefined1 *)0x78161;
      Con_Printf();
    }
    else {
      local_404[0] = 0;
      local_2408 = 2;
      while( true ) {
        apcStack_243c[8] = (char *)0x781b2;
        iVar1 = Cmd_Argc();
        if (iVar1 <= local_2408) break;
        apcStack_243c[8] = (char *)local_2408;
        apcStack_243c[7] = (char *)0x78190;
        apcStack_243c[7] = (char *)Cmd_Argv();
        apcStack_243c[5] = (char *)0x78197;
        apcStack_243c[6] = local_404;
        Q_strcat();
        apcStack_243c[5] = " ";
        apcStack_243c[3] = (char *)0x781a4;
        apcStack_243c[4] = local_404;
        Q_strcat();
        local_2408 = local_2408 + 1;
      }
      apcStack_243c[8] = (char *)0x1;
      apcStack_243c[6] = (undefined1 *)0x781c2;
      apcStack_243c[7] = local_404;
      Cmd_ExecuteString();
    }
    apcStack_243c[8] = (char *)0x781ca;
    SV_EndRedirect();
  }
  return;
}


// SV_Rcon_Validate  @ 00077f9c
undefined4 SV_Rcon_Validate(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Q_strlen(rcon_password._4_4_);
  if (iVar1 != 0) {
    uVar2 = Cmd_Argv(1,rcon_password._4_4_);
    iVar1 = Q_strcmp(uVar2);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}


// SV_ReachedGoal  @ 0007f6f8
undefined4 SV_ReachedGoal(int param_1,float *param_2,float param_3)

{
  undefined4 uVar1;
  
  if ((((*(float *)(param_1 + 0x150) + param_3 < *param_2) ||
       (*param_2 < *(float *)(param_1 + 0x144) - param_3)) ||
      (*(float *)(param_1 + 0x154) + param_3 < param_2[1])) ||
     (((param_2[1] < *(float *)(param_1 + 0x148) - param_3 ||
       (*(float *)(param_1 + 0x158) + param_3 < param_2[2])) ||
      (param_2[2] < *(float *)(param_1 + 0x14c) - param_3)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// SV_ReadPackets  @ 000788d4
void SV_ReadPackets(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 auStack_4c [5];
  int aiStack_38 [3];
  int *piStack_2c;
  int *piStack_28;
  int *local_18;
  int *local_14;
  int *local_10;
  int local_c;
  
  while( true ) {
    piStack_28 = (int *)0x1;
    piStack_2c = (int *)0x78aa5;
    iVar1 = NET_GetPacket();
    if (iVar1 == 0) break;
    piStack_28 = (int *)0x788f5;
    iVar1 = SV_FilterPacket();
    if (iVar1 == 0) {
      if (*DAT_00226fe4 == -1) {
        piStack_28 = (int *)0x7891b;
        SV_ConnectionlessPacket();
      }
      else {
        local_c = 0;
        local_10 = DAT_001ab4e4;
        if (0 < DAT_001ab4e8) {
          local_14 = DAT_001ab4e4 + 0x808;
          local_18 = DAT_001ab4e4 + 0xd36;
          do {
            if (((local_18[-0xd33] != 0) || (*local_10 != 0)) || (local_18[-0xd35] != 0)) {
              piVar2 = local_10 + 9;
              piVar4 = aiStack_38;
              for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                *piVar4 = *piVar2;
                piVar2 = piVar2 + 1;
                piVar4 = piVar4 + 1;
              }
              puVar3 = &net_from;
              puVar5 = auStack_4c;
              for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                *puVar5 = *puVar3;
                puVar3 = puVar3 + 1;
                puVar5 = puVar5 + 1;
              }
              iVar1 = NET_CompareAdr();
              if (iVar1 != 0) {
                piVar2 = local_10 + 8;
                piStack_2c = (int *)0x789bc;
                piStack_28 = piVar2;
                iVar1 = Netchan_Process();
                if (iVar1 != 0) {
                  if (DAT_001ab4e8 == 1) {
                    *local_18 = 1;
                  }
                  if (((*local_10 == 0) || (local_18[-0xd35] == 0)) || (local_18[-0xd34] == 0)) {
                    *local_18 = 1;
                  }
                  piStack_28 = local_10;
                  piStack_2c = (int *)0x78a07;
                  SV_ExecuteClientMessage();
                  DAT_00152b44 = (float)host_frametime;
                }
                piStack_2c = (int *)0x78a27;
                piStack_28 = piVar2;
                iVar1 = Netchan_IncomingReady();
                if (iVar1 != 0) {
                  piStack_2c = (int *)0x78a34;
                  piStack_28 = piVar2;
                  iVar1 = Netchan_CopyNormalFragments();
                  if (iVar1 != 0) {
                    piStack_28 = (int *)0x78a40;
                    MSG_BeginReading();
                    piStack_28 = local_10;
                    piStack_2c = (int *)0x78a49;
                    SV_ExecuteClientMessage();
                  }
                  piStack_2c = (int *)0x78a52;
                  piStack_28 = piVar2;
                  iVar1 = Netchan_CopyFileFragments();
                  if (iVar1 != 0) {
                    host_client = local_10;
                    piStack_28 = local_14;
                    piStack_2c = local_10;
                    aiStack_38[2] = 0x78a71;
                    SV_ProcessFile();
                  }
                }
              }
            }
            local_c = local_c + 1;
            local_18 = local_18 + 0x1415;
            local_14 = local_14 + 0x1415;
            local_10 = local_10 + 0x1415;
          } while (local_c < DAT_001ab4e8);
        }
      }
    }
    else {
      piStack_28 = (int *)0x78900;
      SV_SendBan();
    }
  }
  return;
}


// SV_ReallocateDynamicData  @ 00072b10
void SV_ReallocateDynamicData(void)

{
  int iVar1;
  
  iVar1 = DAT_00186f90;
  if (DAT_00186f90 == 0) {
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


// SV_RecursiveHullCheck  @ 0008c214
undefined4
SV_RecursiveHullCheck
          (int *param_1,int param_2,float param_3,float param_4,float *param_5,float *param_6,
          int *param_7)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  float fVar10;
  float *pfVar11;
  uint local_40;
  float local_10;
  float local_c;
  float local_8;
  
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
    return 1;
  }
  if (((param_2 < param_1[2]) || (param_1[3] < param_2)) || (iVar6 = param_1[1], iVar6 == 0)) {
    Sys_Error("SV_RecursiveHullCheck: bad node number");
    iVar6 = param_1[1];
  }
  piVar1 = (int *)(*param_1 + param_2 * 8);
  pfVar2 = (float *)(iVar6 + *piVar1 * 0x14);
  if (*(byte *)(pfVar2 + 4) < 3) {
    fVar10 = pfVar2[3];
    fVar5 = param_5[*(byte *)(pfVar2 + 4)] - fVar10;
    fVar3 = param_6[*(byte *)(pfVar2 + 4)];
  }
  else {
    fVar3 = pfVar2[2] * param_6[2] + pfVar2[1] * param_6[1] + *pfVar2 * *param_6;
    fVar10 = pfVar2[3];
    fVar5 = (pfVar2[2] * param_5[2] + pfVar2[1] * param_5[1] + *pfVar2 * *param_5) - fVar10;
  }
  fVar3 = fVar3 - fVar10;
  fVar10 = param_3;
  pfVar11 = param_5;
  if (fVar5 < 0.0) {
LAB_0008c35e:
    if (0x3f < (byte)((0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1)) {
      iVar6 = (int)*(short *)((int)piVar1 + 6);
      goto LAB_0008c4f0;
    }
    if ((byte)((0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) - 1) < 0x40) goto LAB_0008c3ac;
    fVar4 = fVar5 + 0.03125;
  }
  else {
    if (0.0 <= fVar3) {
      iVar6 = (int)(short)piVar1[1];
      goto LAB_0008c4f0;
    }
    if (0x3f < (byte)((0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) - 1)) goto LAB_0008c35e;
LAB_0008c3ac:
    fVar4 = fVar5 - 0.03125;
  }
  fVar4 = fVar4 / (fVar5 - fVar3);
  if (0x3f < (byte)((0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) - 1)) {
    fVar4 = 0.0;
  }
  if (1.0 < fVar4) {
    fVar4 = 1.0;
  }
  fVar10 = (param_4 - param_3) * fVar4 + param_3;
  pfVar11 = &local_10;
  local_10 = fVar4 * (*param_6 - *param_5) + *param_5;
  local_c = fVar4 * (param_6[1] - param_5[1]) + param_5[1];
  local_8 = fVar4 * (param_6[2] - param_5[2]) + param_5[2];
  bVar9 = (byte)(fVar5 < 0.0 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 1;
  uVar7 = (uint)bVar9;
  iVar6 = SV_RecursiveHullCheck
                    (param_1,(int)*(short *)(uVar7 * 2 + 4 + (int)piVar1),param_3,fVar10,param_5,
                     pfVar11,param_7);
  if (iVar6 != 0) {
    local_40 = (uint)!bVar9;
    iVar6 = SV_HullPointContents(param_1,(int)*(short *)(local_40 * 2 + 4 + (int)piVar1),pfVar11);
    if (iVar6 != -2) {
      iVar6 = (int)*(short *)(local_40 * 2 + 4 + (int)piVar1);
LAB_0008c4f0:
      uVar8 = SV_RecursiveHullCheck(param_1,iVar6,fVar10,param_4,pfVar11,param_6,param_7);
      return uVar8;
    }
    if (*param_7 == 0) {
      if (uVar7 == 0) {
        param_7[8] = (int)*pfVar2;
        param_7[9] = (int)pfVar2[1];
        param_7[10] = (int)pfVar2[2];
        param_7[0xb] = (int)pfVar2[3];
      }
      else {
        param_7[8] = (int)(vec3_origin - *pfVar2);
        param_7[9] = (int)(DAT_000b2e2c - pfVar2[1]);
        param_7[10] = (int)(DAT_000b2e30 - pfVar2[2]);
        param_7[0xb] = (int)-pfVar2[3];
      }
      while( true ) {
        iVar6 = SV_HullPointContents(param_1,param_1[2],pfVar11);
        if (iVar6 != -2) {
          param_7[4] = (int)fVar10;
          param_7[5] = (int)local_10;
          param_7[6] = (int)local_c;
          param_7[7] = (int)local_8;
          return 0;
        }
        fVar4 = fVar4 - 0.1;
        if (fVar4 < 0.0) break;
        fVar10 = param_3 + (param_4 - param_3) * fVar4;
        local_10 = fVar4 * (*param_6 - *param_5) + *param_5;
        local_c = fVar4 * (param_6[1] - param_5[1]) + param_5[1];
        local_8 = fVar4 * (param_6[2] - param_5[2]) + param_5[2];
      }
      param_7[4] = (int)fVar10;
      param_7[5] = (int)local_10;
      param_7[6] = (int)local_c;
      param_7[7] = (int)local_8;
      Con_DPrintf("backup past 0\n");
    }
  }
  return 0;
}


// SV_RecursiveWaterLevel  @ 0008211c
void SV_RecursiveWaterLevel(undefined4 *param_1,float param_2,float param_3,int param_4)

{
  int iVar1;
  float fVar2;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  fVar2 = (param_2 - param_3) * 0.5 + param_3;
  if (param_4 + 1 < 6) {
    local_10 = *param_1;
    local_c = param_1[1];
    local_8 = (float)param_1[2] + fVar2;
    iVar1 = SV_PointContents(&local_10);
    if (iVar1 != -3) {
      param_2 = fVar2;
      fVar2 = param_3;
    }
    SV_RecursiveWaterLevel(param_1,param_2,fVar2,param_4 + 1);
  }
  return;
}


// SV_RegisterDelta  @ 0007e010
void SV_RegisterDelta(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = DELTA_Load(param_1,&local_8,param_2);
  if (iVar1 == 0) {
    Sys_Error("Error parsing %s/%s!!!\n",com_gamedir,param_2);
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


// SV_RegisterResources  @ 00083a08
void SV_RegisterResources(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(host_client + 0x10) = 0;
  iVar3 = host_client;
  iVar1 = host_client + 0x4c84;
  for (iVar2 = *(int *)(host_client + 0x4d04); iVar2 != iVar1; iVar2 = *(int *)(iVar2 + 0x80)) {
    SV_CreateCustomizationList(iVar3);
    SV_Customization(iVar3,iVar2,1);
  }
  host_client = iVar3;
  return;
}


// SV_RejectConnection  @ 00075954
void SV_RejectConnection(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined2 **ppuVar2;
  undefined2 *apuStack_42c [4];
  char local_404 [1024];
  
  apuStack_42c[3] = (undefined2 *)0x75980;
  vsprintf(local_404,param_2,&stack0x0000000c);
  apuStack_42c[3] = &net_message;
  apuStack_42c[2] = (undefined2 *)0x7598c;
  SZ_Clear();
  apuStack_42c[2] = (undefined2 *)0xffffffff;
  apuStack_42c[1] = &net_message;
  apuStack_42c[0] = (undefined2 *)0x7599a;
  MSG_WriteLong();
  apuStack_42c[0] = (undefined2 *)0x39;
  MSG_WriteByte(&net_message);
  MSG_WriteString();
  ppuVar2 = apuStack_42c;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined2 *)*param_1;
    param_1 = param_1 + 1;
    ppuVar2 = ppuVar2 + 1;
  }
  NET_SendPacket(1,DAT_00226fec,DAT_00226fe4);
  SZ_Clear();
  WON_RemoveUserbyAddress();
  return;
}


// SV_RejectConnectionForPassword  @ 00075a04
void SV_RejectConnectionForPassword(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined2 *puStack_2c;
  char *pcStack_28;
  undefined2 *puStack_24;
  undefined4 uStack_20;
  undefined2 *puStack_1c;
  undefined4 *puStack_18;
  undefined2 *puStack_14;
  
  puStack_14 = &net_message;
  puStack_18 = (undefined4 *)0x75a22;
  SZ_Clear();
  puStack_18 = (undefined4 *)0xffffffff;
  puStack_1c = &net_message;
  uStack_20 = 0x75a30;
  MSG_WriteLong();
  uStack_20 = 0x38;
  puStack_24 = &net_message;
  pcStack_28 = (char *)0x75a3e;
  MSG_WriteByte();
  pcStack_28 = "BADPASSWORD";
  puStack_2c = &net_message;
  uStack_30 = 0x75a51;
  MSG_WriteString();
  puVar2 = param_1;
  puVar3 = auStack_40;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  NET_SendPacket(1,DAT_00226fec,DAT_00226fe4);
  puStack_14 = &net_message;
  puStack_18 = (undefined4 *)0x75a85;
  SZ_Clear();
  puStack_18 = param_1;
  puStack_1c = (undefined2 *)0x75a8e;
  WON_RemoveUserbyAddress();
  return;
}


// SV_RemoveFromResourceList  @ 00083b84
void SV_RemoveFromResourceList(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x84) + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(*(int *)(param_1 + 0x80) + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}


// SV_RemoveIP_f  @ 0007d494
void SV_RemoveIP_f(void)

{
  undefined4 uVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_14;
  int local_10;
  
  uVar1 = Cmd_Argv(1,&local_14);
  iVar2 = StringToFilter(uVar1);
  if (iVar2 != 0) {
    local_24 = 0;
    if (0 < numipfilters) {
      iVar2 = 0;
      do {
        if ((*(int *)((int)&ipfilters + iVar2) == local_14) &&
           (*(int *)((int)&DAT_001a74c4 + iVar2) == local_10)) {
          local_20 = local_24 + 1;
          if (local_20 < numipfilters) {
            iVar2 = local_20 * 0x10;
            local_24 = iVar2 + -0x10;
            do {
              *(undefined4 *)((int)&ipfilters + local_24) = *(undefined4 *)((int)&ipfilters + iVar2)
              ;
              *(undefined4 *)((int)&DAT_001a74c4 + local_24) =
                   *(undefined4 *)((int)&DAT_001a74c4 + iVar2);
              *(undefined4 *)(&DAT_001a74c8 + local_24) = *(undefined4 *)(&DAT_001a74c8 + iVar2);
              *(undefined4 *)((int)&DAT_001a74cc + local_24) =
                   *(undefined4 *)((int)&DAT_001a74cc + iVar2);
              iVar2 = iVar2 + 0x10;
              local_24 = local_24 + 0x10;
              local_20 = local_20 + 1;
            } while (local_20 < numipfilters);
          }
          numipfilters = numipfilters + -1;
          Con_Printf("Filter removed.\n");
          return;
        }
        iVar2 = iVar2 + 0x10;
        local_24 = local_24 + 1;
      } while (local_24 < numipfilters);
    }
    uVar1 = Cmd_Argv(1);
    Con_Printf("Didn\'t find %s.\n",uVar1);
  }
  return;
}


// SV_RemoveId_f  @ 0007cfe0
void SV_RemoveId_f(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int local_14;
  int local_10;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    uVar2 = Cmd_Argv(1);
    iVar1 = Q_atoi(uVar2);
    local_10 = 0;
    if (0 < numuserfilters) {
      local_14 = 0;
LAB_0007d044:
      if (iVar1 != *(int *)((int)&userfilters + local_14)) goto LAB_0007d0bc;
      local_10 = local_10 + 1;
      if (local_10 < numuserfilters) {
        iVar4 = local_10 * 0xc;
        local_14 = iVar4 + -0xc;
        do {
          *(undefined4 *)((int)&userfilters + local_14) = *(undefined4 *)((int)&userfilters + iVar4)
          ;
          *(undefined4 *)(&DAT_00192464 + local_14) = *(undefined4 *)(&DAT_00192464 + iVar4);
          *(undefined4 *)((int)&DAT_00192468 + local_14) =
               *(undefined4 *)((int)&DAT_00192468 + iVar4);
          iVar4 = iVar4 + 0xc;
          local_14 = local_14 + 0xc;
          local_10 = local_10 + 1;
        } while (local_10 < numuserfilters);
      }
      numuserfilters = numuserfilters + -1;
      pcVar3 = "removeid:  filter removed for %u.\n";
      goto LAB_0007d0d6;
    }
LAB_0007d0cc:
    pcVar3 = "removeid:  not such userid:  %u.\n";
LAB_0007d0d6:
    Con_Printf(pcVar3,iVar1);
  }
  else {
    Con_Printf("Ussage:  removeid <uniqueid>\n");
  }
  return;
LAB_0007d0bc:
  local_14 = local_14 + 0xc;
  local_10 = local_10 + 1;
  if (numuserfilters <= local_10) goto LAB_0007d0cc;
  goto LAB_0007d044;
}


// SV_RequestMissingResources  @ 00083dd0
undefined4 SV_RequestMissingResources(void)

{
  if ((*(int *)(host_client + 0x10) != 0) && (*(int *)(host_client + 0x4ea0) == 0)) {
    SV_UploadComplete(host_client);
  }
  return 0;
}


// SV_RequestMissingResourcesFromClients  @ 00083c48
void SV_RequestMissingResourcesFromClients(void)

{
  int iVar1;
  int iVar2;
  
  host_client = DAT_001ab4e4;
  iVar2 = 0;
  if (0 < DAT_001ab4e8) {
    do {
      if (*host_client != 0) goto LAB_00083c8c;
      iVar1 = host_client[1];
      while (iVar1 != 0) {
LAB_00083c8c:
        iVar1 = SV_RequestMissingResources();
      }
      host_client = host_client + 0x1415;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_001ab4e8);
  }
  return;
}


// SV_ResetModInfo  @ 00076dcc
void SV_ResetModInfo(void)

{
  Q_memset(&gmodinfo,0,0x234);
  DAT_00385f84 = 1;
  DAT_00385f8c = 1;
  return;
}


// SV_RestoreMove  @ 0008743c
void SV_RestoreMove(int *param_1)

{
  int iVar1;
  int *piVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (nofind == 0) {
    iVar1 = (*DAT_003862e4)();
    if (iVar1 != 0) {
      if (((((1 < DAT_001ab4e8) &&
            ((byte)((float)sv_unlag._12_4_ < 0.0 |
                    (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40))
           && (param_1[0x13d3] != 0)) && ((param_1[0x13d4] != 0 && (*param_1 != 0)))) &&
         (local_8 = 0, 0 < DAT_001ab4e8)) {
        local_c = 0;
        local_10 = 0;
        do {
          piVar2 = (int *)(local_10 + DAT_001ab4e4);
          if ((piVar2 != param_1) && (*piVar2 != 0)) {
            iVar1 = VectorCompare(&DAT_001fab48 + local_c,&DAT_001fab54 + local_c);
            if ((iVar1 == 0) && (*(int *)(&DAT_001fab44 + local_c) != 0)) {
              if (*(int *)((int)&truepositions + local_c) == 0) {
                Con_DPrintf("SV_RestoreMove:  Tried to restore \'inactive\' player %i/%s\n",local_8,
                            piVar2 + 0x130f);
              }
              else {
                iVar1 = VectorCompare(&DAT_001fab60 + local_c,piVar2[0x12b9] + 0x88);
                if (iVar1 != 0) {
                  *(undefined4 *)(piVar2[0x12b9] + 0x88) = *(undefined4 *)(&DAT_001fab54 + local_c);
                  *(undefined4 *)(piVar2[0x12b9] + 0x8c) = *(undefined4 *)(&DAT_001fab58 + local_c);
                  *(undefined4 *)(piVar2[0x12b9] + 0x90) = *(undefined4 *)(&DAT_001fab5c + local_c);
                  SV_LinkEdict(piVar2[0x12b9],0);
                }
              }
            }
          }
          local_c = local_c + 0x48;
          local_10 = local_10 + 0x5054;
          local_8 = local_8 + 1;
        } while (local_8 < DAT_001ab4e8);
      }
    }
  }
  else {
    nofind = 0;
  }
  return;
}


// SV_RunCmd  @ 00085504
void SV_RunCmd(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  code *pcVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  longdouble lVar11;
  undefined1 *puVar12;
  int iVar13;
  int iVar14;
  int local_a4;
  int local_a0;
  int local_90;
  undefined4 local_70;
  undefined1 local_50;
  undefined1 local_3c [56];
  
  puVar8 = param_1;
  puVar10 = &local_70;
  for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  if ((double)local_70._2_1_ <= 50.0) {
    if (*(int *)(host_client + 0x2460) == 0) {
      SV_SetupMove(host_client);
    }
    (*DAT_003862cc)();
    fVar3 = (float)*(byte *)((int)param_1 + 2) * 0.001;
    *(double *)(host_client + 0x24c8) = *(double *)(host_client + 0x24c8) + (double)fVar3;
    *(double *)(host_client + 0x24a8) =
         *(double *)(host_client + 0x24a8) - (double)*(byte *)((int)param_1 + 2);
    if (*(char *)(param_1 + 8) != '\0') {
      *(uint *)(sv_player + 0x204) = (uint)*(byte *)(param_1 + 8);
    }
    *(undefined4 *)(sv_player + 0xb8) = 0;
    *(undefined4 *)(sv_player + 0xbc) = 0;
    *(undefined4 *)(sv_player + 0xc0) = 0;
    *(uint *)(sv_player + 0x200) = (uint)*(ushort *)((int)param_1 + 0x1e);
    SV_CheckMovingGround(sv_player,fVar3);
    pmove[0x14] = *(undefined4 *)(sv_player + 0xf4);
    pmove[0x15] = *(undefined4 *)(sv_player + 0xf8);
    pmove[0x16] = *(undefined4 *)(sv_player + 0xfc);
    if (*(int *)(sv_player + 0x120) == 0) {
      *(undefined4 *)(sv_player + 0xf4) = param_1[1];
      *(undefined4 *)(sv_player + 0xf8) = param_1[2];
      *(undefined4 *)(sv_player + 0xfc) = param_1[3];
    }
    if (*(int *)(host_client + 0x245c) == 0) {
      SV_PlayerRunPreThink(sv_player,(float)*(double *)(host_client + 0x24c8));
      SV_PlayerRunThink(sv_player,fVar3,*(undefined8 *)(host_client + 0x24c8));
    }
    lVar11 = (longdouble)Length(sv_player + 0xac);
    if ((longdouble)0 < lVar11) {
      *(undefined4 *)(sv_player + 0xb8) = *(undefined4 *)(sv_player + 0xac);
      *(undefined4 *)(sv_player + 0xbc) = *(undefined4 *)(sv_player + 0xb0);
      *(undefined4 *)(sv_player + 0xc0) = *(undefined4 *)(sv_player + 0xb4);
    }
    pmove[1] = 1;
    pmove[2] = (uint)(1 < DAT_001ab4e8);
    pmove[3] = (float)((longdouble)1000.0 * (longdouble)*(double *)(host_client + 0x24c8));
    pmove[0x2f] = *(uint *)(sv_player + 0x224) >> 0xe & 1;
    pmove[0x7d] = sv_maxspeed._12_4_;
    pmove[0x7e] = *(undefined4 *)(sv_player + 0x290);
    pmove[0x23] = (float)*(int *)(sv_player + 0x2ac);
    pmove[0x24] = *(undefined4 *)(sv_player + 0x2a0);
    pmove[0x25] = *(undefined4 *)(sv_player + 0x2a4);
    pmove[0x26] = *(undefined4 *)(sv_player + 0x2b0);
    pmove[0x27] = *(undefined4 *)(sv_player + 0x2b4);
    pmove[0x2b] = (float)*(int *)(sv_player + 0x2a8);
    pmove[0x32] = *(undefined4 *)(sv_player + 700);
    Q_strcpy(pmove + 0x13cfc,host_client + 0x4f54);
    pmove[0x17] = *(undefined4 *)(sv_player + 0xa0);
    pmove[0x18] = *(undefined4 *)(sv_player + 0xa4);
    pmove[0x19] = *(undefined4 *)(sv_player + 0xa8);
    pmove[0x1a] = *(undefined4 *)(sv_player + 0xc4);
    pmove[0x1b] = *(undefined4 *)(sv_player + 200);
    pmove[0x1c] = *(undefined4 *)(sv_player + 0xcc);
    pmove[0x11] = *(undefined4 *)(sv_player + 0xf4);
    pmove[0x12] = *(undefined4 *)(sv_player + 0xf8);
    pmove[0x13] = *(undefined4 *)(sv_player + 0xfc);
    pmove[0x1d] = *(undefined4 *)(sv_player + 0xac);
    pmove[0x1e] = *(undefined4 *)(sv_player + 0xb0);
    pmove[0x1f] = *(undefined4 *)(sv_player + 0xb4);
    pmove[0x20] = *(undefined4 *)(sv_player + 500);
    pmove[0x21] = *(undefined4 *)(sv_player + 0x1f8);
    pmove[0x22] = *(undefined4 *)(sv_player + 0x1fc);
    pmove[0x28] = *(undefined4 *)(sv_player + 0xe8);
    pmove[0x29] = *(undefined4 *)(sv_player + 0xec);
    pmove[0x2a] = *(undefined4 *)(sv_player + 0xf0);
    pmove[0x35] = *(undefined4 *)(sv_player + 0x1f0);
    pmove[0x2d] = *(undefined4 *)(sv_player + 0x198);
    pmove[0x30] = *(undefined4 *)(sv_player + 0x19c);
    pmove[0x31] = *(undefined4 *)(sv_player + 0x1a0);
    pmove[0x36] = *(undefined4 *)(host_client + 0x245c);
    pmove[0x33] = *(undefined4 *)(sv_player + 0x234);
    puVar8 = &local_70;
    puVar10 = pmove + 0x11516;
    for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    pmove[0x34] = (uint)(*(float *)(sv_player + 0x1e0) <= 0.0);
    pmove[0x37] = *(undefined4 *)(sv_player + 0x188);
    pmove[0x2e] = *(undefined4 *)(sv_player + 0x224);
    uVar4 = NUM_FOR_EDICT(sv_player);
    *pmove = uVar4;
    pmove[0x7f] = *(undefined4 *)(sv_player + 0x2c4);
    pmove[0x80] = *(undefined4 *)(sv_player + 0x2c8);
    pmove[0x81] = *(undefined4 *)(sv_player + 0x2cc);
    pmove[0x82] = *(undefined4 *)(sv_player + 0x2d0);
    pmove[0x83] = *(undefined4 *)(sv_player + 0x2d4);
    pmove[0x84] = *(undefined4 *)(sv_player + 0x2d8);
    pmove[0x85] = *(undefined4 *)(sv_player + 0x2dc);
    pmove[0x86] = *(undefined4 *)(sv_player + 0x2e0);
    pmove[0x87] = *(undefined4 *)(sv_player + 0x2e4);
    pmove[0x88] = *(undefined4 *)(sv_player + 0x2e8);
    pmove[0x89] = *(undefined4 *)(sv_player + 0x2ec);
    pmove[0x8a] = *(undefined4 *)(sv_player + 0x2f0);
    pmove[0x8b] = *(undefined4 *)(sv_player + 0x2f4);
    pmove[0x8c] = *(undefined4 *)(sv_player + 0x2f8);
    pmove[0x8d] = *(undefined4 *)(sv_player + 0x2fc);
    pmove[0x8e] = *(undefined4 *)(sv_player + 0x300);
    pmove[0x8f] = *(undefined4 *)(sv_player + 0x304);
    pmove[0x90] = *(undefined4 *)(sv_player + 0x308);
    pmove[0x91] = *(undefined4 *)(sv_player + 0x30c);
    pmove[0x92] = *(undefined4 *)(sv_player + 0x310);
    pmove[0xe] = *(undefined4 *)(sv_player + 0x88);
    pmove[0xf] = *(undefined4 *)(sv_player + 0x8c);
    pmove[0x10] = *(undefined4 *)(sv_player + 0x90);
    puVar10 = pmove + 0xe;
    puVar8 = &sv_areanodes;
    SV_AddLinksToPM();
    pmove[4] = fVar3;
    pmove[0x13d6c] = 1;
    pmove[0x13d6d] = PM_SV_PlaySound;
    pmove[0x13d6e] = PM_SV_TraceTexture;
    pmove[0x13d6f] = PM_SV_PlaybackEventFull;
    (*DAT_003862a8)(pmove,1,puVar8,puVar10);
    *(undefined4 *)(sv_player + 0x1f0) = pmove[0x35];
    *(undefined4 *)(sv_player + 0x198) = pmove[0x2d];
    *(undefined4 *)(sv_player + 0x234) = pmove[0x33];
    *(undefined4 *)(sv_player + 0x240) = pmove[0x39];
    *(undefined4 *)(sv_player + 0x244) = pmove[0x3a];
    *(undefined4 *)(sv_player + 0x224) = pmove[0x2e];
    *(undefined4 *)(sv_player + 0x1a0) = pmove[0x31];
    *(undefined4 *)(sv_player + 0x188) = pmove[0x37];
    *(undefined4 *)(sv_player + 0x290) = pmove[0x7e];
    *(undefined4 *)(sv_player + 0x2b0) = pmove[0x26];
    *(undefined4 *)(sv_player + 500) = pmove[0x20];
    *(undefined4 *)(sv_player + 0x1f8) = pmove[0x21];
    *(undefined4 *)(sv_player + 0x1fc) = pmove[0x22];
    *(undefined4 *)(sv_player + 0xc4) = pmove[0x1a];
    *(undefined4 *)(sv_player + 200) = pmove[0x1b];
    *(undefined4 *)(sv_player + 0xcc) = pmove[0x1c];
    *(undefined4 *)(sv_player + 0xe8) = pmove[0x28];
    *(undefined4 *)(sv_player + 0xec) = pmove[0x29];
    *(undefined4 *)(sv_player + 0xf0) = pmove[0x2a];
    if (pmove[0x38] == -1) {
      *(byte *)(sv_player + 0x225) = *(byte *)(sv_player + 0x225) & 0xfd;
    }
    else {
      *(byte *)(sv_player + 0x225) = *(byte *)(sv_player + 0x225) | 2;
      uVar4 = EDICT_NUM(pmove[(pmove[0x38] * 8 - pmove[0x38]) * 8 + 0xa8]);
      *(undefined4 *)(sv_player + 0x21c) = uVar4;
    }
    *(undefined4 *)(sv_player + 0x88) = pmove[0xe];
    *(undefined4 *)(sv_player + 0x8c) = pmove[0xf];
    *(undefined4 *)(sv_player + 0x90) = pmove[0x10];
    *(undefined4 *)(sv_player + 0xa0) = pmove[0x17];
    *(undefined4 *)(sv_player + 0xa4) = pmove[0x18];
    *(undefined4 *)(sv_player + 0xa8) = pmove[0x19];
    *(undefined4 *)(sv_player + 0xac) = pmove[0x1d];
    *(undefined4 *)(sv_player + 0xb0) = pmove[0x1e];
    *(undefined4 *)(sv_player + 0xb4) = pmove[0x1f];
    if (*(int *)(sv_player + 0x120) == 0) {
      *(undefined4 *)(sv_player + 0xf4) = pmove[0x11];
      *(undefined4 *)(sv_player + 0xf8) = pmove[0x12];
      *(undefined4 *)(sv_player + 0xfc) = pmove[0x13];
      *(undefined4 *)(sv_player + 0xd0) = pmove[0x11];
      *(undefined4 *)(sv_player + 0xd4) = pmove[0x12];
      *(undefined4 *)(sv_player + 0xd8) = pmove[0x13];
      *(float *)(sv_player + 0xd0) = -(float)pmove[0x11] * 0.33333334;
    }
    *(undefined4 *)(sv_player + 0x2a0) = pmove[0x24];
    *(int *)(sv_player + 0x2ac) = (int)ROUND((float)pmove[0x23]);
    *(undefined4 *)(sv_player + 0x2a4) = pmove[0x25];
    *(undefined4 *)(sv_player + 0x2b4) = pmove[0x27];
    *(int *)(sv_player + 0x2a8) = (int)ROUND((float)pmove[0x2b]);
    *(uint *)(sv_player + 700) = (uint)*(ushort *)((int)pmove + 0x45476);
    *(undefined4 *)(sv_player + 0x2c4) = pmove[0x7f];
    *(undefined4 *)(sv_player + 0x2c8) = pmove[0x80];
    *(undefined4 *)(sv_player + 0x2cc) = pmove[0x81];
    *(undefined4 *)(sv_player + 0x2d0) = pmove[0x82];
    *(undefined4 *)(sv_player + 0x2d4) = pmove[0x83];
    *(undefined4 *)(sv_player + 0x2d8) = pmove[0x84];
    *(undefined4 *)(sv_player + 0x2dc) = pmove[0x85];
    *(undefined4 *)(sv_player + 0x2e0) = pmove[0x86];
    *(undefined4 *)(sv_player + 0x2e4) = pmove[0x87];
    *(undefined4 *)(sv_player + 0x2e8) = pmove[0x88];
    *(undefined4 *)(sv_player + 0x2ec) = pmove[0x89];
    *(undefined4 *)(sv_player + 0x2f0) = pmove[0x8a];
    *(undefined4 *)(sv_player + 0x2f4) = pmove[0x8b];
    *(undefined4 *)(sv_player + 0x2f8) = pmove[0x8c];
    *(undefined4 *)(sv_player + 0x2fc) = pmove[0x8d];
    *(undefined4 *)(sv_player + 0x300) = pmove[0x8e];
    *(undefined4 *)(sv_player + 0x304) = pmove[0x8f];
    *(undefined4 *)(sv_player + 0x308) = pmove[0x90];
    *(undefined4 *)(sv_player + 0x30c) = pmove[0x91];
    *(undefined4 *)(sv_player + 0x310) = pmove[0x92];
    SetMinMaxSize(sv_player,&player_mins + pmove[0x2f] * 3,&player_maxs + pmove[0x2f] * 3,0);
    if ((*(int *)(host_client + 0x245c) == 0) &&
       (*(int *)(*(int *)(host_client + 0x4ae4) + 0x18c) != 0)) {
      SV_LinkEdict(sv_player,1);
      uVar4 = *(undefined4 *)(sv_player + 0xa0);
      uVar1 = *(undefined4 *)(sv_player + 0xa4);
      local_90 = 0;
      uVar2 = *(undefined4 *)(sv_player + 0xa8);
      if (0 < (int)pmove[0x11523]) {
        local_a0 = 0x45490;
        local_a4 = 0;
        do {
          iVar7 = EDICT_NUM(pmove[(*(int *)(local_a4 + 0x454c0 + (int)pmove) * 8 -
                                  *(int *)(local_a4 + 0x454c0 + (int)pmove)) * 8 + 0xa8]);
          if ((*(byte *)(iVar7 + 0x227) & 4) == 0) {
            iVar9 = local_a0 + (int)pmove;
            iVar13 = iVar9;
            iVar14 = iVar7;
            puVar12 = local_3c;
            SV_ConvertPMTrace();
            *(undefined4 *)(sv_player + 0xa0) = *(undefined4 *)(iVar9 + 0x34);
            *(undefined4 *)(sv_player + 0xa4) = *(undefined4 *)(iVar9 + 0x38);
            *(undefined4 *)(sv_player + 0xa8) = *(undefined4 *)(iVar9 + 0x3c);
            SV_Impact(iVar7,sv_player,local_3c,puVar12,iVar13,iVar14);
          }
          local_a0 = local_a0 + 0x44;
          local_a4 = local_a4 + 0x44;
          local_90 = local_90 + 1;
        } while (local_90 < (int)pmove[0x11523]);
      }
      *(undefined4 *)(sv_player + 0xa0) = uVar4;
      *(undefined4 *)(sv_player + 0xa4) = uVar1;
      *(undefined4 *)(sv_player + 0xa8) = uVar2;
    }
    gGlobalVariables = (float)*(double *)(host_client + 0x24c8);
    pcVar5 = DAT_003862a0;
    if (*(int *)(host_client + 0x245c) == 0) {
      pcVar5 = DAT_00386280;
    }
    DAT_00152b44 = fVar3;
    (*pcVar5)(sv_player);
    (*DAT_003862d0)(sv_player);
    if (*(int *)(host_client + 0x2460) == 0) {
      SV_RestoreMove(host_client);
    }
  }
  else {
    uVar6 = (undefined1)(longlong)ROUND((double)*(byte *)((int)param_1 + 2) * 0.5);
    local_70._2_1_ = uVar6;
    SV_RunCmd(&local_70,param_2);
    local_50 = 0;
    local_70._2_1_ = uVar6;
    SV_RunCmd(&local_70,param_2);
  }
  return;
}


// SV_RunThink  @ 0007ff80
bool SV_RunThink(int *param_1)

{
  bool bVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  if ((*(byte *)((int)param_1 + 0x227) & 0x40) == 0) {
    lVar2 = (longdouble)(float)param_1[0x61];
    if ((longdouble)0 < lVar2) {
      lVar3 = (longdouble)DAT_0015358c + (longdouble)host_frametime;
      if ((byte)((lVar2 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar3)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar2 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
        if (lVar2 < (longdouble)DAT_0015358c) {
          lVar2 = (longdouble)(float)DAT_0015358c;
        }
        param_1[0x61] = 0;
        gGlobalVariables = (float)lVar2;
        (*DAT_00386228)(param_1);
        if ((*(byte *)((int)param_1 + 0x227) & 0x40) != 0) goto LAB_00080027;
        goto LAB_0008002d;
      }
    }
    bVar1 = true;
  }
  else {
LAB_00080027:
    ED_Free(param_1);
LAB_0008002d:
    bVar1 = *param_1 == 0;
  }
  return bVar1;
}


// SV_SendBan  @ 00078834
void SV_SendBan(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 **ppuVar3;
  undefined2 *apuStack_64 [3];
  char local_44 [64];
  
  apuStack_64[2] = (undefined2 *)0x78859;
  sprintf(local_44,"You have been banned from this server.\n");
  apuStack_64[2] = &net_message;
  apuStack_64[1] = (undefined2 *)0x78865;
  SZ_Clear();
  apuStack_64[1] = (undefined2 *)0xffffffff;
  apuStack_64[0] = &net_message;
  MSG_WriteLong();
  MSG_WriteByte(&net_message,0x6c);
  MSG_WriteString(&net_message,local_44);
  puVar2 = &net_from;
  ppuVar3 = apuStack_64;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar3 = (undefined2 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  }
  NET_SendPacket(1,DAT_00226fec,DAT_00226fe4);
  SZ_Clear();
  return;
}


// SV_SendClientDatagram  @ 0007a474
undefined4 SV_SendClientDatagram(int param_1)

{
  ushort local_fb4 [2];
  undefined1 *local_fb0;
  undefined4 local_fac;
  undefined4 local_fa8;
  undefined1 local_fa4 [4000];
  
  local_fac = 4000;
  local_fa8 = 0;
  local_fb4[0] = 1;
  local_fb0 = local_fa4;
  MSG_WriteByte(local_fb4,7);
  MSG_WriteFloat(local_fb4,(float)DAT_0015358c);
  SV_WriteClientdataToMessage(param_1,local_fb4);
  SV_WriteEntitiesToClient(param_1,local_fb4);
  if ((*(byte *)(param_1 + 0x2510) & 2) == 0) {
    SZ_Write(local_fb4,*(undefined4 *)(param_1 + 0x2514),*(undefined4 *)(param_1 + 0x251c));
  }
  else {
    Con_Printf("WARNING: datagram overflowed for %s\n",param_1 + 0x4c3c);
  }
  SZ_Clear(param_1 + 0x2510);
  if ((local_fb4[0] & 2) != 0) {
    Con_Printf("WARNING: msg overflowed for %s\n",param_1 + 0x4c3c);
    SZ_Clear(local_fb4);
  }
  Netchan_Transmit(param_1 + 0x20,local_fa8,local_fa4);
  return 1;
}


// SV_SendClientMessages  @ 0007a850
void SV_SendClientMessages(void)

{
  double dVar1;
  double dVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  SV_UpdateToReliableMessages();
  host_client = DAT_001ab4e4;
  iVar5 = 0;
  if (0 < DAT_001ab4e8) {
    do {
      if ((((*host_client != 0) || (host_client[3] != 0)) || (host_client[1] != 0)) &&
         (host_client[0x918] == 0)) {
        if (host_client[0xd37] == 0) {
          if (((byte)((byte)((ushort)((ushort)NAN((float)host_limitlocal._12_4_) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)host_limitlocal._12_4_ == 0.0) << 0xe) >> 8))
               == 0x40) && (host_client[9] == 1)) {
            host_client[0xd36] = 1;
          }
          if (((*host_client != 0) && (host_client[1] != 0)) && (host_client[2] != 0)) {
            dVar2 = realtime + host_frametime;
            dVar1 = *(double *)(host_client + 0xd32);
            if ((byte)(dVar2 < dVar1 |
                       (byte)((ushort)((ushort)(NAN(dVar2) || NAN(dVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar2 == dVar1) << 0xe) >> 8)) != 1) {
              host_client[0xd36] = 1;
            }
          }
          if ((*(byte *)(host_client + 0x1d) & 2) == 0) {
            if (host_client[0xd36] == 0) goto LAB_0007aac0;
            dVar1 = realtime - (double)(float)host_client[0xe];
            dVar2 = (double)(float)sv_failuretime._12_4_;
            if (0x3f < (byte)((dVar1 < dVar2 |
                               (byte)((ushort)((ushort)(NAN(dVar1) || NAN(dVar2)) << 10) >> 8) |
                              (byte)((ushort)((ushort)(dVar1 == dVar2) << 0xe) >> 8)) - 1)) {
              host_client[0xd36] = 0;
            }
          }
          else {
            SZ_Clear(host_client + 0x1d);
            SZ_Clear(host_client + 0x944);
            SV_BroadcastPrintf("%s overflowed\n",host_client + 0x130f);
            Con_Printf("WARNING: reliable overflow for %s\n",host_client + 0x130f);
            SV_DropClient(host_client,0);
            host_client[0xd36] = 1;
            piVar3 = host_client;
            host_client[0x12] = 0;
            piVar3[0x13] = 0;
          }
          if (host_client[0xd36] != 0) {
            iVar4 = Netchan_CanPacket(host_client + 8);
            if (iVar4 == 0) {
              host_client[0x914] = host_client[0x914] + 1;
            }
            else {
              host_client[0xd36] = 0;
              *(double *)(host_client + 0xd32) =
                   realtime + host_frametime + *(double *)(host_client + 0xd34);
              if (((*host_client == 0) || (host_client[1] == 0)) || (host_client[2] == 0)) {
                Netchan_Transmit(host_client + 8,0,0);
              }
              else {
                SV_SendClientDatagram(host_client);
              }
            }
          }
        }
        else {
          host_client[0xd37] = 0;
        }
      }
LAB_0007aac0:
      host_client = host_client + 0x1415;
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_001ab4e8);
  }
  SV_CleanupEnts();
  return;
}


// SV_SendConsistencyList  @ 000848c4
void SV_SendConsistencyList(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  local_8 = 0;
  *(undefined4 *)(host_client + 0x18) = 0;
  if (((DAT_001ab4e8 != 1) &&
      ((byte)((float)mp_consistency._12_4_ < 0.0 |
              (byte)((ushort)((ushort)NAN((float)mp_consistency._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)mp_consistency._12_4_ == 0.0) << 0xe) >> 8)) != 0x40))
     && (DAT_00183684 != 0)) {
    *(undefined4 *)(host_client + 0x18) = 1;
    MSG_WriteBits(1,1);
    iVar1 = 0;
    if (0 < DAT_0017de80) {
      local_c = 0;
      do {
        if ((local_c != -0x153680) && ((char)(&DAT_001536cc)[local_c] < '\0')) {
          MSG_WriteBits(1,1);
          if (iVar1 - local_8 < 0x20) {
            MSG_WriteBits(1,1);
            uVar3 = 5;
            iVar2 = iVar1 - local_8;
          }
          else {
            MSG_WriteBits(0,1);
            uVar3 = 10;
            iVar2 = iVar1;
          }
          MSG_WriteBits(iVar2,uVar3);
          local_8 = iVar1;
        }
        local_c = local_c + 0x88;
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_0017de80);
    }
  }
  MSG_WriteBits(0,1);
  return;
}


// SV_SendEnts_f  @ 00088614
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


// SV_SendResources  @ 000747c0
void SV_SendResources(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int local_28;
  undefined1 local_24 [32];
  
  Q_memset(local_24,0,0x20);
  MSG_WriteByte(param_1,0x2b);
  MSG_StartBitWriting(param_1);
  MSG_WriteBits(DAT_0017de80,0xc);
  local_28 = 0;
  if (0 < DAT_0017de80) {
    iVar2 = 0;
    do {
      MSG_WriteBits(*(undefined4 *)((int)&DAT_001536c0 + iVar2),4);
      MSG_WriteBitString(&DAT_00153680 + iVar2);
      MSG_WriteBits(*(undefined4 *)((int)&DAT_001536c4 + iVar2),0xc);
      MSG_WriteBits(*(undefined4 *)((int)&DAT_001536c8 + iVar2),0x18);
      MSG_WriteBits((&DAT_001536cc)[iVar2] & 3,3);
      if (((&DAT_001536cc)[iVar2] & 4) != 0) {
        MSG_WriteBitData(&DAT_001536cd + iVar2,0x10);
      }
      iVar1 = Q_memcmp(&DAT_001536de + iVar2,local_24,0x20);
      if (iVar1 == 0) {
        MSG_WriteBits(0,1);
      }
      else {
        MSG_WriteBits(1,1);
        MSG_WriteBitData(&DAT_001536de + iVar2,0x20);
      }
      iVar2 = iVar2 + 0x88;
      local_28 = local_28 + 1;
    } while (local_28 < DAT_0017de80);
  }
  SV_SendConsistencyList(param_1);
  MSG_EndBitWriting(param_1);
  return;
}


// SV_SendServerinfo  @ 0007459c
void SV_SendServerinfo(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_804 [2048];
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) ||
     (1 < DAT_001ab4e8)) {
    MSG_WriteByte(param_1,8);
    uVar1 = build_number(0,DAT_001ab4f0);
    sprintf(local_804,"%c\nBUILD %d SERVER (%i CRC)\nServer # %i\n",2,uVar1);
    MSG_WriteString(param_1,local_804);
  }
  MSG_WriteByte(param_1,0xb);
  MSG_WriteLong(param_1,0x2a);
  MSG_WriteLong(param_1,DAT_001ab4f0);
  MSG_WriteLong(param_1,DAT_0015366c);
  MSG_WriteBuf(param_1,0x10,&DAT_00153670);
  MSG_WriteByte(param_1,DAT_001ab4e8);
  iVar2 = NUM_FOR_EDICT(*(undefined4 *)(param_2 + 0x4ae4));
  uVar3 = iVar2 - 1;
  if (*(int *)(param_2 + 0x245c) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  MSG_WriteByte(param_1,uVar3);
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
  MSG_WriteByte(param_1,uVar1);
  COM_FileBase(com_gamedir,local_804);
  MSG_WriteString(param_1,local_804);
  MSG_WriteString(param_1,&DAT_00153628);
  MSG_WriteString(param_1,&DAT_00153628);
  SV_WriteDeltaDescriptionsToClient(param_1);
  SV_SetMoveVars();
  SV_WriteMovevarsToClient(param_1);
  MSG_WriteByte(param_1,0x20);
  MSG_WriteByte(param_1,DAT_00152bcc);
  MSG_WriteByte(param_1,DAT_00152bcc);
  MSG_WriteByte(param_1,5);
  uVar1 = NUM_FOR_EDICT(*(undefined4 *)(param_2 + 0x4ae4));
  MSG_WriteShort(param_1,uVar1);
  MSG_WriteByte(param_1,0x2d);
  MSG_WriteLong(param_1,DAT_001ab4f0);
  MSG_WriteLong(param_1,0);
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 0xc) = 1;
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}


// SV_SendUserReg  @ 0007512c
void SV_SendUserReg(undefined4 param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = sv_gpNewUserMsgs; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[5]) {
    MSG_WriteByte(param_1,0x27);
    MSG_WriteByte(param_1,*puVar1);
    MSG_WriteByte(param_1,puVar1[1]);
    MSG_WriteLong(param_1,puVar1[2]);
    MSG_WriteLong(param_1,puVar1[3]);
    MSG_WriteLong(param_1,puVar1[4]);
    MSG_WriteLong(param_1,puVar1[5]);
  }
  return;
}


// SV_ServerLog_f  @ 00072664
void SV_ServerLog_f(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    uVar3 = Cmd_Argv(1,&DAT_000aa567);
    iVar1 = Q_stricmp(uVar3);
    if (iVar1 == 0) {
      if (DAT_001ab4f8 != 0) {
        if (DAT_001ab514 != 0) {
          Log_Close();
        }
        Con_Printf("Server logging disabled.\n");
        DAT_001ab4f8 = 0;
      }
    }
    else {
      uVar3 = Cmd_Argv(1,&DAT_000aa585);
      iVar1 = Q_stricmp(uVar3);
      if (iVar1 == 0) {
        DAT_001ab4f8 = 1;
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
    if (DAT_001ab4f8 == 0) {
      pcVar2 = "not currently logging\n";
    }
    else {
      pcVar2 = "currently logging\n";
    }
    Con_Printf(pcVar2);
  }
  return;
}


// SV_ServerShutdown  @ 0007bd34
void SV_ServerShutdown(void)

{
  gGlobalVariables = (float)DAT_0015358c;
  if ((svs != 0) && (sv != 0)) {
    (*DAT_00386278)();
  }
  return;
}


// SV_Serverinfo_f  @ 00072d4c
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
      if (*pcVar3 != '*') {
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
          lVar4 = (longdouble)Q_atof(uVar2);
          *(float *)(iVar1 + 0xc) = (float)lVar4;
        }
        uVar2 = Info_Serverinfo();
        SV_BroadcastCommand("fullserverinfo \"%s\"\n",uVar2);
        return;
      }
      pcVar3 = "Star variables cannot be changed.\n";
    }
    else {
      pcVar3 = "usage: serverinfo [ <key> <value> ]\n";
    }
    Con_Printf(pcVar3);
  }
  return;
}


// SV_SetCallback  @ 00079630
void SV_SetCallback(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_001ab4c4 = param_1;
  DAT_001ab4c8 = param_2;
  DAT_001ab4cc = param_3;
  g_svdeltacallback = param_4;
  DAT_001ab4d0 = 0;
  DAT_001ab4d4 = 0;
  return;
}


// SV_SetGlobalTrace  @ 0006d09c
void SV_SetGlobalTrace(uint *param_1)

{
  DAT_00152b8c = (float)*param_1;
  DAT_00152b90 = (float)param_1[1];
  DAT_00152b94 = param_1[4];
  DAT_00152bbc = (float)param_1[3];
  DAT_00152bb8 = (float)param_1[2];
  DAT_00152b98 = param_1[5];
  DAT_00152b9c = param_1[6];
  DAT_00152ba0 = param_1[7];
  DAT_00152ba4 = param_1[8];
  DAT_00152ba8 = param_1[9];
  DAT_00152bac = param_1[10];
  DAT_00152bb0 = param_1[0xb];
  DAT_00152bb4 = param_1[0xc];
  if (param_1[0xc] == 0) {
    DAT_00152bb4 = DAT_00186f94;
  }
  DAT_00152bc0 = param_1[0xd];
  return;
}


// SV_SetLogAddress_f  @ 00072534
void SV_SetLogAddress_f(void)

{
  int iVar1;
  char *pcVar2;
  char **ppcVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  char *pcStackY_144;
  char *pcStackY_140;
  char *pcStack_134;
  char *pcStack_130;
  char local_11c [20];
  char local_108 [260];
  
  pcStack_130 = (char *)0x72551;
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcStack_130 = (char *)0x1;
    pcStack_134 = (char *)0x7259f;
    pcVar2 = (char *)Cmd_Argv();
    pcStack_134 = (char *)0x2;
    Cmd_Argv();
    pcStack_130 = (char *)Q_atoi();
    if (pcStack_130 == (char *)0x0) {
      pcStack_130 = "logaddress:  must specify a valid port\n";
    }
    else {
      if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
        pcStackY_140 = (char *)0x725ed;
        pcStack_134 = pcVar2;
        sprintf(local_108,"%s:%i");
        pcStackY_144 = local_108;
        pcStackY_140 = local_11c;
        iVar1 = NET_StringToAdr();
        if (iVar1 == 0) {
          ppcVar3 = &stack0xfffffed0;
          pcVar2 = "logaddress:  unable to resolve %s\n";
          pcStack_130 = local_108;
        }
        else {
          DAT_001ab4fc = 1;
          pcVar2 = local_11c;
          puVar4 = &DAT_001ab500;
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
          pcStackY_144 = (char *)0x7263f;
          pcStackY_144 = (char *)NET_AdrToString();
          ppcVar3 = &pcStackY_144;
          pcVar2 = "logaddress:  %s\n";
        }
        goto LAB_0007264f;
      }
      pcStack_130 = "logaddress:  unparseable address\n";
    }
    pcStack_134 = (char *)0x725d5;
    Con_Printf();
  }
  else {
    pcStack_130 = "logaddress:  usage\nlogaddress ip port\n";
    pcStack_134 = (char *)0x72562;
    Con_Printf();
    if (DAT_001ab4f8 == 0) {
      return;
    }
    puVar4 = &DAT_001ab500;
    ppcVar5 = &pcStackY_140;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar5 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    pcStackY_144 = (char *)0x7258a;
    pcStackY_144 = (char *)NET_AdrToString();
    ppcVar3 = &pcStackY_144;
    pcVar2 = "current:  %s\n";
LAB_0007264f:
    *(char **)((int)ppcVar3 + -4) = pcVar2;
    *(undefined4 *)((int)ppcVar3 + -8) = 0x72655;
    Con_Printf();
  }
  return;
}


// SV_SetMaxclients  @ 0007db34
void SV_SetMaxclients(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_10;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  iVar3 = DAT_001ab4e4;
  if (0 < DAT_001ab4ec) {
    do {
      SV_ClearFrames(iVar3 + 0x34e0);
      local_8 = local_8 + 1;
      iVar3 = iVar3 + 0x5054;
    } while (local_8 < DAT_001ab4ec);
  }
  DAT_001ab4e8 = 1;
  iVar3 = COM_CheckParm("-maxplayers");
  if (iVar3 == 0) {
    if (isDedicated != 0) {
      DAT_001ab4e8 = 6;
    }
  }
  else {
    DAT_001ab4e8 = Q_atoi(*(undefined4 *)(com_argv + 4 + iVar3 * 4));
  }
  cls = (uint)(isDedicated == 0);
  if (DAT_001ab4e8 < 1) {
    DAT_001ab4e8 = 6;
  }
  else if (0x20 < DAT_001ab4e8) {
    DAT_001ab4e8 = 0x20;
  }
  if ((isDedicated == 0) && (DAT_000e8bd0 < 0x1000001)) {
    DAT_001ab4ec = 4;
  }
  else {
    DAT_001ab4ec = 0x20;
  }
  SV_UPDATE_BACKUP = 0x40;
  if (DAT_001ab4e8 == 1) {
    SV_UPDATE_BACKUP = 8;
  }
  SV_UPDATE_MASK = SV_UPDATE_BACKUP + -1;
  iVar3 = Hunk_AllocName(DAT_001ab4ec * 0x5054,"clients");
  local_8 = 0;
  DAT_001ab4e4 = iVar3;
  if (0 < DAT_001ab4ec) {
    local_c = (int *)(iVar3 + 0x4d04);
    local_10 = (int *)(iVar3 + 0x4d08);
    do {
      Q_memset(iVar3,0,0x5054);
      local_10[0x22] = iVar3 + 0x4d0c;
      local_10[0x21] = iVar3 + 0x4d0c;
      iVar1 = iVar3 + 0x4c84;
      *local_10 = iVar1;
      iVar3 = iVar3 + 0x5054;
      *local_c = iVar1;
      local_8 = local_8 + 1;
      local_10 = local_10 + 0x1415;
      local_c = local_c + 0x1415;
    } while (local_8 < DAT_001ab4ec);
  }
  uVar2 = 0;
  if (1 < DAT_001ab4e8) {
    uVar2 = 0x3f800000;
  }
  Cvar_SetValue("deathmatch",uVar2);
  SV_AllocClientFrames();
  if (DAT_001ab4ec < DAT_001ab4e8) {
    DAT_001ab4e8 = DAT_001ab4ec;
  }
  return;
}


// SV_SetMoveVars  @ 000740b8
void SV_SetMoveVars(void)

{
  undefined4 local_10;
  
  movevars = sv_gravity._12_4_;
  DAT_00152584 = sv_stopspeed._12_4_;
  DAT_00152588 = sv_maxspeed._12_4_;
  DAT_0015258c = sv_spectatormaxspeed._12_4_;
  DAT_00152590 = sv_accelerate._12_4_;
  DAT_00152594 = sv_airaccelerate._12_4_;
  DAT_00152598 = sv_wateraccelerate._12_4_;
  DAT_0015259c = sv_friction._12_4_;
  DAT_001525a0 = sv_edgefriction._12_4_;
  DAT_001525a4 = sv_waterfriction._12_4_;
  DAT_001525a8 = 0x3f800000;
  DAT_001525ac = sv_bounce._12_4_;
  DAT_001525b0 = sv_stepsize._12_4_;
  DAT_001525b4 = sv_maxvelocity._12_4_;
  DAT_001525b8 = sv_zmax._12_4_;
  DAT_001525bc = sv_wateramp._12_4_;
  local_10 = (undefined4)(longlong)ROUND((float)sv_footsteps._12_4_);
  DAT_001525c0 = local_10;
  DAT_001525e4 = sv_rollangle._12_4_;
  DAT_001525e8 = sv_rollspeed._12_4_;
  DAT_001525ec = sv_skycolor_r._12_4_;
  DAT_001525f0 = sv_skycolor_g._12_4_;
  DAT_001525f4 = sv_skycolor_b._12_4_;
  DAT_001525f8 = sv_skyvec_x._12_4_;
  DAT_001525fc = sv_skyvec_y._12_4_;
  DAT_00152600 = sv_skyvec_z._12_4_;
  Q_strcpy(&DAT_001525c4,sv_skyname._4_4_);
  return;
}


// SV_SetNewInfo  @ 00079678
void SV_SetNewInfo(undefined4 param_1)

{
  DAT_001ab4d0 = 1;
  DAT_001ab4d4 = param_1;
  return;
}


// SV_SetPlayer  @ 00088434
undefined4 SV_SetPlayer(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_c = DAT_001ab4e4 + 0x12b9;
  piVar1 = DAT_001ab4e4 + 0x12bb;
  piVar2 = piVar1;
  piVar3 = DAT_001ab4e4;
  piVar4 = piVar1;
  while( true ) {
    if ((((piVar2[-0x12ba] != 0) && (*piVar3 != 0)) && (piVar4[-0x12b8] != 0)) &&
       (*piVar1 == param_1)) {
      host_client = piVar3;
      sv_player = *local_c;
      return 1;
    }
    if (((piVar2[0x15b] != 0) && (piVar3[0x1415] != 0)) &&
       ((piVar4[0x15d] != 0 && (piVar1[0x1415] == param_1)))) {
      host_client = piVar3 + 0x1415;
      sv_player = local_c[0x1415];
      return 1;
    }
    if (((piVar2[0x1570] != 0) && (piVar3[0x282a] != 0)) &&
       ((piVar4[0x1572] != 0 && (piVar1[0x282a] == param_1)))) break;
    if ((((piVar2[0x2985] != 0) && (piVar3[0x3c3f] != 0)) && (piVar4[0x2987] != 0)) &&
       (piVar1[0x3c3f] == param_1)) {
      host_client = piVar3 + 0x3c3f;
      sv_player = local_c[0x3c3f];
      return 1;
    }
    local_8 = local_8 + 4;
    piVar1 = piVar1 + 0x5054;
    piVar4 = piVar4 + 0x5054;
    piVar2 = piVar2 + 0x5054;
    local_c = local_c + 0x5054;
    piVar3 = piVar3 + 0x5054;
    if (0x1f < local_8) {
      Con_Printf("Userid %i is not on the server\n",param_1);
      return 0;
    }
  }
  host_client = piVar3 + 0x282a;
  sv_player = local_c[0x282a];
  return 1;
}


// SV_SetStudioHullPlane  @ 0005fcc0
void SV_SetStudioHullPlane(float *param_1,int param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  param_2 = param_2 * 0x30;
  *(undefined1 *)(param_1 + 4) = 5;
  iVar4 = param_3 * 4 + param_2;
  fVar1 = *(float *)(bonetransform + iVar4);
  *param_1 = fVar1;
  fVar2 = *(float *)(bonetransform + iVar4 + 0x10);
  param_1[1] = fVar2;
  fVar3 = *(float *)(bonetransform + iVar4 + 0x20);
  param_1[2] = fVar3;
  param_1[3] = fVar3 * *(float *)(bonetransform + param_2 + 0x2c) +
               fVar2 * *(float *)(bonetransform + param_2 + 0x1c) +
               fVar1 * *(float *)(bonetransform + param_2 + 0xc) + param_4;
  return;
}


// SV_SetupMove  @ 00086db4
void SV_SetupMove(int *param_1)

{
  int iVar1;
  int *piVar2;
  double *pdVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  double *pdVar7;
  int iVar8;
  double *pdVar9;
  int iVar10;
  int iVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  int local_64;
  int local_50;
  int local_4c;
  float local_38;
  double *local_30;
  int local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Q_memset(&truepositions,0,0x900);
  nofind = 1;
  iVar8 = (*DAT_003862e4)();
  if (iVar8 == 0) {
    return;
  }
  if ((byte)((float)sv_unlag._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)sv_unlag._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_unlag._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  if (param_1[0x13d3] == 0) {
    return;
  }
  if (param_1[0x13d4] == 0) {
    return;
  }
  if (DAT_001ab4e8 < 2) {
    return;
  }
  if (*param_1 == 0) {
    return;
  }
  nofind = 0;
  local_24 = 0;
  if (0 < DAT_001ab4e8) {
    iVar8 = 0;
    local_64 = 0;
    do {
      piVar2 = (int *)(local_64 + DAT_001ab4e4);
      if ((piVar2 != param_1) && (*piVar2 != 0)) {
        *(undefined4 *)(&DAT_001fab54 + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x88);
        *(undefined4 *)(&DAT_001fab58 + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x8c);
        *(undefined4 *)(&DAT_001fab5c + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x90);
        *(undefined4 *)(&DAT_001fab6c + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x144);
        *(undefined4 *)(&DAT_001fab70 + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x148);
        *(undefined4 *)(&DAT_001fab74 + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x14c);
        *(undefined4 *)(&DAT_001fab78 + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x150);
        *(undefined4 *)(&DAT_001fab7c + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x154);
        *(undefined4 *)(&DAT_001fab80 + iVar8) = *(undefined4 *)(piVar2[0x12b9] + 0x158);
        *(undefined4 *)((int)&truepositions + iVar8) = 1;
      }
      iVar8 = iVar8 + 0x48;
      local_64 = local_64 + 0x5054;
      local_24 = local_24 + 1;
    } while (local_24 < DAT_001ab4e8);
  }
  fVar4 = (float)param_1[0x92c];
  if (0x3f < (byte)((fVar4 < 1.5 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar4 == 1.5) << 0xe) >> 8)) - 1)) {
    fVar4 = 1.5;
  }
  if ((byte)((float)sv_maxunlag._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)sv_maxunlag._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_maxunlag._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    if (0x3f < (byte)((0.0 < (float)sv_maxunlag._12_4_ |
                       (byte)((ushort)((ushort)NAN((float)sv_maxunlag._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)sv_maxunlag._12_4_ == 0.0) << 0xe) >> 8)) - 1)
       ) {
      Cvar_SetValue("sv_maxunlag",0);
    }
    if ((float)sv_maxunlag._12_4_ <= fVar4) {
      fVar4 = (float)sv_maxunlag._12_4_;
    }
  }
  fVar5 = (float)(int)(short)param_1[0x91b] * 0.001;
  if (0x3f < (byte)((fVar5 < 0.1 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar5 == 0.1) << 0xe) >> 8)) - 1)) {
    fVar5 = 0.1;
  }
  if (0x3f < (byte)((0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) - 1)) {
    fVar5 = 0.0;
  }
  local_14 = (fVar5 + ((float)realtime - fVar4) + (float)sv_unlagpush._12_4_) - 0.1;
  if ((float)realtime < local_14) {
    local_14 = (float)realtime;
  }
  lVar12 = (longdouble)local_14;
  local_30 = (double *)0x0;
  local_24 = 0;
  if (SV_UPDATE_BACKUP < 1) {
LAB_000871ac:
    Q_memset(&truepositions,0,0x900);
    nofind = 1;
    return;
  }
  do {
    iVar8 = local_24 + 1;
    local_28 = 0;
    pdVar3 = (double *)((param_1[0x18] - iVar8 & SV_UPDATE_MASK) * 0xd10 + param_1[0xd38]);
    pdVar9 = pdVar3 + 0x19d;
    if (0 < *(int *)(pdVar3 + 0x19d)) {
      local_50 = 0;
      do {
        iVar10 = local_50 + *(int *)((int)pdVar3 + 0xd0c);
        iVar11 = *(int *)(iVar10 + 4);
        if (((0 < iVar11) && (iVar11 < DAT_001ab4e8)) &&
           (iVar11 = iVar11 * 0x48, *(int *)(&DAT_001fab3c + iVar11) == 0)) {
          if (*(int *)(iVar10 + 0xac) < 1) {
            *(undefined4 *)(&DAT_001fab3c + iVar11) = 1;
          }
          if ((*(byte *)(iVar10 + 0x3c) & 0x20) != 0) {
            *(undefined4 *)(&DAT_001fab3c + iVar11) = 1;
          }
        }
        local_50 = local_50 + 0x154;
        local_28 = local_28 + 1;
      } while (local_28 < *(int *)pdVar9);
    }
    lVar13 = (longdouble)*pdVar3;
  } while (((byte)(lVar13 < lVar12 |
                   (byte)((ushort)((ushort)(NAN(lVar13) || NAN(lVar12)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar13 == lVar12) << 0xe) >> 8)) != 1) &&
          (local_30 = pdVar3, local_24 = iVar8, iVar8 < SV_UPDATE_BACKUP));
  if ((SV_UPDATE_BACKUP <= local_24) || (lVar6 = (longdouble)1, lVar6 < lVar12 - lVar13))
  goto LAB_000871ac;
  pdVar7 = pdVar3;
  if (local_30 != (double *)0x0) {
    local_14 = (float)((longdouble)*local_30 - lVar13);
    lVar14 = (longdouble)local_14;
    lVar13 = (longdouble)0;
    pdVar7 = local_30;
    if ((byte)(lVar13 < lVar14 | (byte)((ushort)((ushort)(NAN(lVar13) || NAN(lVar14)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar13 == lVar14) << 0xe) >> 8)) != 0x40) {
      lVar12 = (longdouble)(float)((lVar12 - (longdouble)*pdVar3) / lVar14);
      if (0x3f < (byte)((lVar12 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar12) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar12 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar12 = (longdouble)1;
      }
      local_38 = (float)lVar12;
      if (local_38 < 0.0) {
        local_38 = 0.0;
      }
      goto LAB_00087253;
    }
  }
  local_30 = pdVar7;
  local_38 = 0.0;
LAB_00087253:
  local_24 = 0;
  if (*(int *)pdVar9 < 1) {
    return;
  }
  local_4c = 0;
  do {
    iVar11 = local_4c + *(int *)((int)pdVar3 + 0xd0c);
    iVar8 = *(int *)(iVar11 + 4);
    if ((0 < iVar8) && (iVar8 < DAT_001ab4e8)) {
      iVar10 = DAT_001ab4e4 + iVar8 * 0x5054;
      if (((int *)(iVar10 + -0x5054) != param_1) && (*(int *)(iVar10 + -0x5054) != 0)) {
        iVar1 = (iVar8 + -1) * 0x48;
        if (*(int *)(&DAT_001fab84 + iVar1) == 0) {
          if ((&truepositions)[(iVar8 + -1) * 0x12] == 0) {
            Con_DPrintf("tried to store off position of bogus player %i/%s\n",local_24,
                        iVar10 + -0x418);
          }
          else {
            iVar8 = SV_FindEntInPack(iVar8,local_30 + 0x19d);
            if (iVar8 == 0) {
              local_10 = *(undefined4 *)(iVar11 + 0x10);
              local_c = *(undefined4 *)(iVar11 + 0x14);
              local_8 = *(undefined4 *)(iVar11 + 0x18);
            }
            else {
              local_20 = *(float *)(iVar8 + 0x10) - *(float *)(iVar11 + 0x10);
              local_1c = *(float *)(iVar8 + 0x14) - *(float *)(iVar11 + 0x14);
              local_18 = *(float *)(iVar8 + 0x18) - *(float *)(iVar11 + 0x18);
              VectorMA(iVar11 + 0x10,local_38,&local_20,&local_10);
            }
            *(undefined4 *)(&DAT_001fab48 + iVar1) = local_10;
            *(undefined4 *)(&DAT_001fab4c + iVar1) = local_c;
            *(undefined4 *)(&DAT_001fab50 + iVar1) = local_8;
            *(undefined4 *)(&DAT_001fab60 + iVar1) = local_10;
            *(undefined4 *)(&DAT_001fab64 + iVar1) = local_c;
            *(undefined4 *)(&DAT_001fab68 + iVar1) = local_8;
            iVar8 = VectorCompare(&local_10,*(int *)(iVar10 + -0x570) + 0x88);
            if (iVar8 == 0) {
              *(undefined4 *)(*(int *)(iVar10 + -0x570) + 0x88) = local_10;
              *(undefined4 *)(*(int *)(iVar10 + -0x570) + 0x8c) = local_c;
              *(undefined4 *)(*(int *)(iVar10 + -0x570) + 0x90) = local_8;
              SV_LinkEdict(*(undefined4 *)(iVar10 + -0x570),0);
              *(undefined4 *)(&DAT_001fab44 + iVar1) = 1;
            }
          }
        }
      }
    }
    local_4c = local_4c + 0x154;
    local_24 = local_24 + 1;
  } while (local_24 < *(int *)pdVar9);
  return;
}


// SV_ShouldUpdatePing  @ 00079ce8
bool SV_ShouldUpdatePing(int param_1)

{
  SV_CalcPing(param_1);
  return *(short *)(param_1 + 0x248a) < 0;
}


// SV_ShowServerinfo_f  @ 000885dc
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


// SV_Shutdown  @ 0007e868
void SV_Shutdown(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = g_sv_delta;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    if (puVar2[3] != 0) {
      DELTA_FreeDescription(puVar2 + 3);
    }
    Mem_Free(puVar2[1]);
    Mem_Free(puVar2[2]);
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  g_sv_delta = (undefined4 *)0x0;
  return;
}


// SV_SingleClipMoveToEntity  @ 0008c648
void SV_SingleClipMoveToEntity
               (int param_1,float *param_2,undefined4 param_3,undefined4 param_4,float *param_5,
               int *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *local_cc;
  int local_c8;
  int local_bc;
  int local_b8 [4];
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  int local_90;
  int local_8c;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
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
  
  Q_memset(param_6,0,0x38);
  *param_6 = 1;
  param_6[4] = 0x3f800000;
  param_6[5] = (int)*param_5;
  param_6[6] = (int)param_5[1];
  param_6[7] = (int)param_5[2];
  if (*(int *)(*(int *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4) + 0x44) == 3) {
    local_c8 = SV_HullForStudioModel(param_1,param_3,param_4,&local_10,local_b8);
  }
  else {
    local_c8 = SV_HullForEntity(param_1,param_3,param_4,&local_10);
    local_b8[0] = 1;
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
      || (fVar1 = *(float *)(param_1 + 0xd8),
         (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)))) {
    bVar5 = true;
    AngleVectors(param_1 + 0xd0,&local_34,&local_40,&local_4c);
    fVar2 = local_18 * local_30;
    fVar3 = local_14 * local_2c;
    fVar1 = local_14 * local_38;
    local_14 = local_14 * local_44 + local_1c * local_4c + local_18 * local_48;
    local_30 = local_24 * local_30;
    local_18 = -(fVar1 + local_1c * local_40 + local_18 * local_3c);
    local_2c = local_20 * local_2c;
    local_54 = local_24;
    local_58 = local_28;
    local_48 = local_24 * local_48;
    local_24 = -(local_20 * local_38 + local_28 * local_40 + local_24 * local_3c);
    local_50 = local_20;
    local_20 = local_20 * local_44 + local_28 * local_4c + local_48;
    local_28 = local_2c + local_28 * local_34 + local_30;
    local_1c = fVar3 + fVar2 + local_1c * local_34;
  }
  else {
    bVar5 = false;
  }
  if (local_b8[0] == 1) {
    SV_RecursiveHullCheck
              (local_c8,*(undefined4 *)(local_c8 + 8),0,0x3f800000,&local_1c,&local_28,param_6);
  }
  else {
    iVar7 = 0;
    local_bc = 0;
    if (0 < local_b8[0]) {
      local_cc = (undefined4 *)(local_c8 + 8);
      iVar7 = 0;
      do {
        Q_memset(&local_90,0,0x38);
        local_90 = 1;
        local_80 = 1.0;
        local_7c = *param_5;
        local_78 = param_5[1];
        local_74 = param_5[2];
        SV_RecursiveHullCheck(local_c8,*local_cc,0,0x3f800000,&local_1c,&local_28,&local_90);
        if (((local_bc == 0) || (local_90 != 0)) ||
           ((local_8c != 0 ||
            (fVar1 = (float)param_6[4],
            0x3f < (byte)((fVar1 < local_80 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_80)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == local_80) << 0xe) >> 8)) - 1))))) {
          iVar7 = local_bc;
          if (param_6[1] == 0) {
            piVar8 = &local_90;
            piVar9 = param_6;
            for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
              *piVar9 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar9 = piVar9 + 1;
            }
          }
          else {
            piVar8 = &local_90;
            piVar9 = param_6;
            for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
              *piVar9 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar9 = piVar9 + 1;
            }
            param_6[1] = 1;
          }
        }
        local_c8 = local_c8 + 0x28;
        local_cc = local_cc + 10;
        local_bc = local_bc + 1;
      } while (local_bc < local_b8[0]);
    }
    iVar7 = SV_HitgroupForStudioHull(iVar7);
    param_6[0xd] = iVar7;
  }
  fVar1 = (float)param_6[4];
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
    if (bVar5) {
      AngleVectorsTranspose(param_1 + 0xd0,&local_58,&local_9c,&local_a8);
      fVar2 = (float)param_6[8];
      fVar3 = (float)param_6[9];
      fVar4 = (float)param_6[10];
      param_6[8] = (int)(fVar4 * local_50 + fVar3 * local_54 + fVar2 * local_58);
      param_6[9] = (int)(fVar4 * local_94 + fVar3 * local_98 + fVar2 * local_9c);
      fVar1 = (float)param_6[4];
      param_6[10] = (int)(fVar4 * local_a0 + fVar3 * local_a4 + fVar2 * local_a8);
    }
    param_6[5] = (int)(fVar1 * (*param_5 - *param_2) + *param_2);
    param_6[6] = (int)(fVar1 * (param_5[1] - param_2[1]) + param_2[1]);
    fVar2 = (param_5[2] - param_2[2]) * fVar1;
    fVar1 = (float)param_6[4];
    param_6[7] = (int)(param_2[2] + fVar2);
  }
  if ((fVar1 < 1.0) || (param_6[1] != 0)) {
    param_6[0xc] = param_1;
  }
  return;
}


// SV_SkipUpdates  @ 0007a7c0
void SV_SkipUpdates(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *local_c;
  
  iVar3 = 0;
  if (0 < DAT_001ab4e8) {
    local_c = DAT_001ab4e4 + 0xd37;
    piVar2 = DAT_001ab4e4 + 1;
    piVar1 = DAT_001ab4e4;
    do {
      if ((((*piVar1 != 0) || (piVar2[2] != 0)) || (*piVar2 != 0)) &&
         (*(int *)(host_client + 0x2460) == 0)) {
        *local_c = 1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x1415;
      local_c = local_c + 0x1415;
      piVar1 = piVar1 + 0x1415;
    } while (iVar3 < DAT_001ab4e8);
  }
  return;
}


// SV_SpawnServer  @ 0007bd88
undefined4 SV_SpawnServer(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  code *pcVar7;
  int *piVar8;
  int *piVar9;
  int local_70;
  undefined4 local_6c;
  int *local_60;
  int local_58;
  char local_44 [64];
  
  if (((sv != 0) && (1 < DAT_001ab4e8)) && (local_58 = 0, 0 < DAT_001ab4e8)) {
    local_60 = DAT_001ab4e4 + 0x917;
    piVar9 = DAT_001ab4e4 + 0x12b9;
    piVar8 = DAT_001ab4e4;
    do {
      if ((((*piVar8 != 0) || (piVar9[-0x12b8] != 0)) || (piVar9[-0x12b6] != 0)) &&
         ((piVar1 = (int *)*piVar9, piVar1 != (int *)0x0 && (*piVar1 == 0)))) {
        if (piVar1[0x1f] == 0) {
          Con_Printf("Skipping reconnect on %s, no pvPrivateData\n",piVar8 + 0x130f);
        }
        else {
          pcVar7 = DAT_00386260;
          if (*local_60 != 0) {
            pcVar7 = DAT_0038629c;
          }
          (*pcVar7)(piVar1);
        }
      }
      local_58 = local_58 + 1;
      piVar9 = piVar9 + 0x1415;
      local_60 = local_60 + 0x1415;
      piVar8 = piVar8 + 0x1415;
    } while (local_58 < DAT_001ab4e8);
  }
  Log_Open();
  Log_Printf("Spawning server \"%s\"\n",param_2);
  Log_PrintServerVars();
  NET_Config(1 < DAT_001ab4e8);
  pcVar3 = (char *)Cvar_VariableString("hostname");
  if ((pcVar3 != (char *)0x0) && (*pcVar3 == '\0')) {
    Cvar_Set("hostname","Half-Life");
  }
  scr_centertime_off = 0;
  if (param_3 == 0) {
    Con_DPrintf("Spawn Server %s\n",param_2);
  }
  else {
    Con_DPrintf("Spawn Server %s: [%s]\n",param_2,param_3);
  }
  gHostSpawnCount = DAT_001ab4f0 + 1;
  DAT_001ab4f0 = gHostSpawnCount;
  if ((byte)((float)coop._12_4_ < 0.0 | (byte)((ushort)((ushort)NAN((float)coop._12_4_) << 10) >> 8)
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
  local_58 = 0;
  piVar9 = DAT_001ab4e4;
  if (0 < DAT_001ab4ec) {
    do {
      SV_ClearFrames(piVar9 + 0xd38);
      local_58 = local_58 + 1;
      piVar9 = piVar9 + 0x1415;
    } while (local_58 < DAT_001ab4ec);
  }
  if (DAT_001ab4e8 == 1) {
    SV_UPDATE_BACKUP = 8;
  }
  else {
    SV_UPDATE_BACKUP = 0x40;
  }
  SV_UPDATE_MASK = SV_UPDATE_BACKUP + -1;
  SV_AllocClientFrames();
  Q_memset(&sv,0,HPAK_Init);
  Q_strcpy(&DAT_001535a8,param_2);
  if (param_3 == 0) {
    DAT_001535e8 = 0;
  }
  else {
    Q_strcpy(&DAT_001535e8,param_3);
  }
  pr_strings = gNullString;
  DAT_00152bd8 = gNullString;
  if (DAT_001ab4e8 == 1) {
    Cvar_SetValue("sv_clienttrace",0x3f800000);
  }
  DAT_00186f90 = COM_EntsForPlayerSlots(DAT_001ab4e8);
  SV_DeallocateDynamicData();
  SV_ReallocateDynamicData();
  DAT_00152bd4 = DAT_00186f90;
  DAT_00186f94 = (undefined4 *)Hunk_AllocName(DAT_00186f90 * 0x324,"edicts");
  DAT_00186f98 = Hunk_AllocName(DAT_00186f90 * 0x154,"baselines");
  DAT_00186fac = 4000;
  DAT_00186fb0 = 0;
  DAT_00186fa8 = &DAT_00186fb4;
  DAT_00187f5c = 4000;
  DAT_00187f60 = 0;
  DAT_00187f58 = &DAT_00187f64;
  DAT_00188f0c = 4000;
  DAT_00188f08 = &DAT_00188f14;
  DAT_00189ebc = 0x400;
  DAT_00189eb8 = &DAT_00189ec4;
  DAT_0018a2c8 = &DAT_0018a2d4;
  DAT_0018a2cc = 0x8000;
  DAT_0018a2d0 = 0;
  DAT_00186f8c = DAT_001ab4e8 + 1;
  local_58 = 0;
  if (0 < DAT_001ab4e8) {
    local_70 = 0;
    iVar4 = 0;
    do {
      *(int *)((int)DAT_001ab4e4 + local_70 + 0x4ae4) = (int)DAT_00186f94 + iVar4 + 0x324;
      local_70 = local_70 + 0x5054;
      local_58 = local_58 + 1;
      iVar4 = iVar4 + 0x324;
    } while (local_58 < DAT_001ab4e8);
  }
  DAT_00152bd0 = DAT_001ab4e8;
  DAT_00186fa0 = 1;
  DAT_00153584 = 0;
  DAT_0015358c._0_4_ = 0;
  DAT_0015358c._4_4_ = 0x3ff00000;
  gGlobalVariables = 0x3f800000;
  Q_strcpy(&DAT_001535a8,param_2);
  pcVar3 = &DAT_00153628;
  sprintf(&DAT_00153628,"maps/%s.bsp",param_2);
  DAT_00153668 = Mod_ForName(&DAT_00153628,0);
  if (DAT_00153668 == 0) {
    pcVar5 = "Couldn\'t spawn server %s\n";
  }
  else {
    if (DAT_001ab4e8 < 2) {
      DAT_0015366c = 0;
      Q_memset(&DAT_00153670,0,0x10);
LAB_0007c3e9:
      DAT_00183e8c = DAT_00153668;
      SV_ClearWorld();
      DAT_00185688 = pr_strings;
      DAT_00183688 = pr_strings;
      DAT_0018368c = &DAT_00153628;
      local_58 = 1;
      if (1 < *(int *)(DAT_00153668 + 0x78)) {
        do {
          iVar4 = local_58 + 1;
          (&DAT_00183688)[iVar4] = localmodels + local_58 * 5;
          uVar6 = Mod_ForName(localmodels + local_58 * 5,0);
          *(undefined4 *)(&DAT_00183e88 + iVar4 * 4) = uVar6;
          local_58 = iVar4;
        } while (iVar4 < *(int *)(DAT_00153668 + 0x78));
      }
      puVar2 = DAT_00186f94;
      Q_memset(DAT_00186f94 + 0x20,0,0x2a4);
      *puVar2 = 0;
      puVar2[0x4e] = DAT_00153668 - (int)pr_strings;
      puVar2[0x4d] = 1;
      puVar2[99] = 4;
      puVar2[0x62] = 7;
      if ((byte)((float)coop._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)coop._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)coop._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
        DAT_00152b54 = deathmatch._12_4_;
      }
      else {
        DAT_00152b58 = coop._12_4_;
      }
      DAT_00152b4c = (int)&DAT_001535a8 - (int)pr_strings;
      DAT_00152b50 = (int)&DAT_001535e8 - (int)pr_strings;
      DAT_00152b60 = (float)DAT_001ab4f4;
      local_6c = (undefined4)(longlong)ROUND((float)sv_cheats._12_4_);
      allow_cheats = local_6c;
      SV_SetMoveVars();
      Log_Printf("Map CRC \"%i\"\n",DAT_0015366c);
      return 1;
    }
    CRC32_Init(&DAT_0015366c);
    iVar4 = CRC_MapFile(&DAT_0015366c,&DAT_00153628);
    if (iVar4 == 0) {
      pcVar5 = "Couldn\'t CRC server map:  %s\n";
    }
    else {
      pcVar3 = local_44;
      sprintf(pcVar3,"cl_dlls/client.dll");
      iVar4 = MD5_Hash_File(&DAT_00153670,pcVar3,0,0,0);
      if (iVar4 != 0) {
        CM_CalcPAS(DAT_00153668);
        goto LAB_0007c3e9;
      }
      pcVar5 = "Couldn\'t CRC client side dll:  %s\n";
    }
  }
  Con_Printf(pcVar5,pcVar3);
  sv = 0;
  return 0;
}


// SV_SpawnSpectator  @ 000751ac
void SV_SpawnSpectator(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(sv_player + 0x88) = vec3_origin;
  *(undefined4 *)(sv_player + 0x8c) = DAT_000b2e2c;
  *(undefined4 *)(sv_player + 0x90) = DAT_000b2e30;
  *(undefined4 *)(sv_player + 500) = vec3_origin;
  *(undefined4 *)(sv_player + 0x1f8) = DAT_000b2e2c;
  *(undefined4 *)(sv_player + 0x1fc) = DAT_000b2e30;
  *(undefined4 *)(sv_player + 0x1fc) = 0x41b00000;
  iVar3 = 0x1f;
  if (0x1f < DAT_00186f8c) {
    do {
      iVar1 = EDICT_NUM(iVar3);
      iVar2 = Q_strcmp(*(int *)(iVar1 + 0x80) + pr_strings,"info_player_start");
      if (iVar2 == 0) {
        *(undefined4 *)(sv_player + 0x88) = *(undefined4 *)(iVar1 + 0x88);
        *(undefined4 *)(sv_player + 0x8c) = *(undefined4 *)(iVar1 + 0x8c);
        *(undefined4 *)(sv_player + 0x90) = *(undefined4 *)(iVar1 + 0x90);
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00186f8c);
  }
  return;
}


// SV_Spawn_f  @ 00075674
void SV_Spawn_f(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_10014 [4];
  undefined1 *puStack_10010;
  undefined4 uStack_1000c;
  undefined4 uStack_10008;
  undefined1 auStack_10004 [65536];
  
  Q_memset(auStack_10014,0,0x10);
  puStack_10010 = auStack_10004;
  uStack_10008 = 0;
  uStack_1000c = 0x10000;
  if (cmd_source == 1) {
    Con_Printf("spawn is not valid from the console\n");
  }
  else {
    if (DAT_003855a4 == 0) {
      uVar1 = Cmd_Argv(1);
      iVar2 = Q_atoi(uVar1);
      if (iVar2 != DAT_001ab4f0) {
        SV_New_f();
        return;
      }
    }
    SZ_Write(auStack_10014,DAT_0018a2c8,DAT_0018a2d0);
    SV_WriteSpawn(auStack_10014);
    Netchan_CreateFragments(1,host_client + 0x20,auStack_10014);
    Netchan_FragSend(host_client + 0x20);
  }
  return;
}


// SV_StartParticle  @ 00073274
void SV_StartParticle(undefined4 *param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  float *pfVar2;
  
  if (DAT_00186fb0 < 0xf91) {
    MSG_WriteByte(&DAT_00186fa4,0x12);
    MSG_WriteCoord(&DAT_00186fa4,*param_1);
    MSG_WriteCoord(&DAT_00186fa4,param_1[1]);
    MSG_WriteCoord(&DAT_00186fa4,param_1[2]);
    pfVar2 = param_2;
    do {
      iVar1 = (int)ROUND(*pfVar2 * 16.0);
      if (iVar1 < 0x80) {
        if (iVar1 < -0x80) {
          iVar1 = -0x80;
        }
      }
      else {
        iVar1 = 0x7f;
      }
      MSG_WriteChar(&DAT_00186fa4,iVar1);
      pfVar2 = pfVar2 + 1;
    } while ((int)pfVar2 <= (int)(param_2 + 2));
    MSG_WriteByte(&DAT_00186fa4,param_4);
    MSG_WriteByte(&DAT_00186fa4,param_3);
  }
  return;
}


// SV_StartSound  @ 00073358
void SV_StartSound(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,uint param_7,undefined4 param_8)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_2 + 0x15c) + *(float *)(param_2 + 0x168)) * 0.5 +
             *(float *)(param_2 + 0x88);
  local_c = (*(float *)(param_2 + 0x160) + *(float *)(param_2 + 0x16c)) * 0.5 +
            *(float *)(param_2 + 0x8c);
  local_8 = (*(float *)(param_2 + 0x164) + *(float *)(param_2 + 0x170)) * 0.5 +
            *(float *)(param_2 + 0x90);
  iVar1 = SV_BuildSoundMsg(param_2,param_3,param_4,param_5,param_6,param_7,param_8,&local_10,
                           &DAT_00189eb4);
  if (iVar1 != 0) {
    if ((param_3 == 6) || ((param_7 & 0x20) != 0)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    uVar2 = 0;
    if (param_1 == 1) {
      uVar2 = 0x80;
    }
    if (bVar3) {
      bVar3 = false;
      uVar2 = uVar2 | 4;
    }
    else {
      iVar1 = Host_IsSinglePlayerGame();
      bVar3 = iVar1 == 0;
      uVar2 = uVar2 | 1;
    }
    SV_Multicast(&local_10,uVar2,bVar3);
  }
  return;
}


// SV_StepDirection  @ 0007f134
bool SV_StepDirection(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  lVar2 = (longdouble)((param_2 * 3.1415927 + param_2 * 3.1415927) * 0.0027777778);
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


// SV_StudioSetupBones  @ 0005f44c
void SV_StudioSetupBones(undefined4 param_1,float param_2,int param_3,undefined4 param_4,
                        undefined4 *param_5,undefined4 param_6,byte *param_7,int param_8)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_280;
  float local_26c;
  uint local_268;
  int local_258 [129];
  undefined1 local_54 [12];
  undefined4 local_48;
  undefined4 local_38;
  undefined4 local_28;
  undefined1 local_24 [32];
  
  local_280 = 0;
  if ((param_3 < 0) || (*(int *)(pstudiohdr + 0xa4) <= param_3)) {
    Con_DPrintf("SV_StudioSetupBones:  sequence %i/%i out of range for model %s\n",param_3,
                *(undefined4 *)(pstudiohdr + 0xa4),pstudiohdr + 8);
    param_3 = 0;
  }
  iVar3 = param_3 * 0xb0 + pstudiohdr + *(int *)(pstudiohdr + 0xa8);
  iVar9 = pstudiohdr + *(int *)(pstudiohdr + 0x90);
  iVar4 = R_GetAnim(param_1,iVar3);
  if ((param_8 < -1) || (*(int *)(pstudiohdr + 0x8c) <= param_8)) {
    param_8 = 0;
  }
  if (param_8 == -1) {
    iVar10 = 0;
    local_280 = *(int *)(pstudiohdr + 0x8c);
    iVar1 = local_280;
    if (0 < local_280) {
      do {
        local_258[iVar1] = iVar10;
        iVar10 = iVar10 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar10 < *(int *)(pstudiohdr + 0x8c));
    }
  }
  else {
    do {
      local_258[local_280 + 1] = param_8;
      local_280 = local_280 + 1;
      param_8 = *(int *)(iVar9 + 0x20 + param_8 * 0x70);
    } while (param_8 != -1);
  }
  if (*(int *)(iVar3 + 0x38) < 2) {
    local_26c = 0.0;
  }
  else {
    local_26c = param_2 * (float)(*(int *)(iVar3 + 0x38) + -1) * 0.00390625;
  }
  iVar1 = (int)ROUND(local_26c);
  fVar2 = local_26c - (float)iVar1;
  R_StudioCalcBoneAdj(0,local_24,param_6,param_6,0);
  uVar7 = local_280 - 1;
  if (-1 < (int)uVar7) {
    if (((int)uVar7 < 0) || (local_268 = uVar7, (~uVar7 & 1) != 0)) {
      iVar10 = local_258[local_280];
      iVar6 = iVar4 + iVar10 * 0xc;
      iVar8 = iVar10 * 0x70 + iVar9;
      R_StudioCalcBoneQuaterion(iVar1,fVar2,iVar8,iVar6,local_24,q_95 + iVar10 * 0x10);
      R_StudioCalcBonePosition(iVar1,fVar2,iVar8,iVar6,local_24,pos_94 + iVar10 * 0xc);
      local_268 = local_280 - 2;
      if ((int)local_268 < 0) goto LAB_0005f872;
    }
    do {
      iVar10 = local_258[local_268 + 1];
      iVar6 = iVar4 + iVar10 * 0xc;
      iVar8 = iVar10 * 0x70 + iVar9;
      R_StudioCalcBoneQuaterion(iVar1,fVar2,iVar8,iVar6,local_24,q_95 + iVar10 * 0x10);
      R_StudioCalcBonePosition(iVar1,fVar2,iVar8,iVar6,local_24,pos_94 + iVar10 * 0xc);
      iVar10 = local_258[local_268];
      iVar6 = iVar4 + iVar10 * 0xc;
      iVar8 = iVar10 * 0x70 + iVar9;
      R_StudioCalcBoneQuaterion(iVar1,fVar2,iVar8,iVar6,local_24,q_95 + iVar10 * 0x10);
      R_StudioCalcBonePosition(iVar1,fVar2,iVar8,iVar6,local_24,pos_94 + iVar10 * 0xc);
      local_268 = local_268 - 2;
    } while (-1 < (int)local_268);
  }
LAB_0005f872:
  if (*(int *)(iVar3 + 0x78) < 2) goto LAB_0005fb87;
  iVar3 = R_GetAnim(param_1,param_3 * 0xb0 + pstudiohdr + *(int *)(pstudiohdr + 0xa8));
  iVar3 = iVar3 + *(int *)(pstudiohdr + 0x8c) * 0xc;
  if (-1 < (int)uVar7) {
    iVar4 = (int)ROUND(local_26c);
    if (((int)uVar7 < 0) || (local_268 = uVar7, (~uVar7 & 1) != 0)) {
      iVar1 = local_258[local_280];
      iVar10 = iVar3 + iVar1 * 0xc;
      iVar6 = iVar1 * 0x70 + iVar9;
      R_StudioCalcBoneQuaterion(iVar4,fVar2,iVar6,iVar10,local_24,q2_97 + iVar1 * 0x10);
      R_StudioCalcBonePosition(iVar4,fVar2,iVar6,iVar10,local_24,pos2_96 + iVar1 * 0xc);
      local_268 = local_280 - 2;
      if ((int)local_268 < 0) goto LAB_0005fb3a;
    }
    do {
      iVar1 = local_258[local_268 + 1];
      iVar10 = iVar3 + iVar1 * 0xc;
      iVar6 = iVar1 * 0x70 + iVar9;
      R_StudioCalcBoneQuaterion(iVar4,fVar2,iVar6,iVar10,local_24,q2_97 + iVar1 * 0x10);
      R_StudioCalcBonePosition(iVar4,fVar2,iVar6,iVar10,local_24,pos2_96 + iVar1 * 0xc);
      iVar1 = local_258[local_268];
      iVar10 = iVar3 + iVar1 * 0xc;
      iVar6 = iVar1 * 0x70 + iVar9;
      R_StudioCalcBoneQuaterion(iVar4,fVar2,iVar6,iVar10,local_24,q2_97 + iVar1 * 0x10);
      R_StudioCalcBonePosition(iVar4,fVar2,iVar6,iVar10,local_24,pos2_96 + iVar1 * 0xc);
      local_268 = local_268 - 2;
    } while (-1 < (int)local_268);
  }
LAB_0005fb3a:
  R_StudioSlerpBones(q_95,pos_94,q2_97,pos2_96,(float)*param_7 * 0.003921569);
LAB_0005fb87:
  AngleMatrix(param_4,rotationmatrix);
  rotationmatrix._12_4_ = *param_5;
  rotationmatrix._28_4_ = param_5[1];
  rotationmatrix._44_4_ = param_5[2];
  if (-1 < (int)uVar7) {
    local_268 = uVar7;
    do {
      iVar3 = local_258[local_268 + 1];
      QuaternionMatrix(q_95 + iVar3 * 0x10,local_54);
      iVar4 = iVar3 * 0xc;
      local_48 = *(undefined4 *)(pos_94 + iVar4);
      local_38 = *(undefined4 *)(pos_94 + iVar4 + 4);
      local_28 = *(undefined4 *)(pos_94 + iVar4 + 8);
      iVar4 = *(int *)(iVar9 + 0x20 + iVar3 * 0x70);
      if (iVar4 == -1) {
        puVar5 = rotationmatrix;
      }
      else {
        puVar5 = bonetransform + iVar4 * 0x30;
      }
      R_ConcatTransforms(puVar5,local_54,bonetransform + iVar3 * 0x30);
      local_268 = local_268 - 1;
    } while (-1 < (int)local_268);
  }
  return;
}


// SV_Submerged  @ 000821b0
longdouble SV_Submerged(int param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
  local_c = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
  local_14 = (*(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x158)) * 0.5;
  fVar1 = *(float *)(param_1 + 0x14c) - local_14;
  iVar2 = *(int *)(param_1 + 0x240);
  local_8 = local_14;
  if (iVar2 == 2) {
LAB_0008229c:
    fVar4 = *(float *)(param_1 + 0x158) - local_8;
    fVar5 = 0.0;
LAB_000822af:
    lVar3 = (longdouble)SV_RecursiveWaterLevel(&local_10,fVar4,fVar5,0);
    lVar3 = lVar3 - (longdouble)fVar1;
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        fVar4 = 0.0;
        fVar5 = fVar1;
        goto LAB_000822af;
      }
    }
    else if (iVar2 == 3) {
      g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
      local_20 = local_10;
      local_1c = local_c;
      local_18 = *(float *)(param_1 + 0x158);
      iVar2 = SV_PointContents(&local_20);
      if (iVar2 == -3) {
        return (longdouble)*(float *)(param_1 + 0x170) - (longdouble)*(float *)(param_1 + 0x164);
      }
      goto LAB_0008229c;
    }
    lVar3 = (longdouble)0;
  }
  return lVar3;
}


// SV_TestEntityPosition  @ 0008c1a8
undefined4 SV_TestEntityPosition(int param_1)

{
  undefined1 local_3c [4];
  int local_38;
  undefined4 local_c;
  
  SV_Move(local_3c,param_1 + 0x88,param_1 + 0x15c,param_1 + 0x168,param_1 + 0x88,0,param_1,
          (*(byte *)(param_1 + 0x226) & 0x80) != 0);
  if (local_38 == 0) {
    local_c = 0;
  }
  else {
    SV_SetGlobalTrace(local_3c);
  }
  return local_c;
}


// SV_TouchLinks  @ 0008b894
void SV_TouchLinks(int *param_1,int *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  piVar4 = (int *)param_2[5];
joined_r0x0008b8ba:
  while( true ) {
    do {
      piVar7 = piVar4;
      if (piVar7 == param_2 + 4) {
        iVar8 = *param_2;
        if (iVar8 != -1) {
          fVar2 = (float)param_2[1];
          if (fVar2 < (float)param_1[iVar8 + 0x54]) {
            SV_TouchLinks(param_1,param_2[2]);
            iVar8 = *param_2;
            fVar2 = (float)param_2[1];
          }
          fVar3 = (float)param_1[iVar8 + 0x51];
          if (0x3f < (byte)((fVar2 < fVar3 |
                             (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
            SV_TouchLinks(param_1,param_2[3]);
          }
        }
        return;
      }
      piVar4 = (int *)piVar7[1];
      piVar1 = piVar7 + -2;
    } while (piVar1 == param_1);
    uVar5 = piVar7[0xae];
    if ((uVar5 == 0) || (uVar6 = param_1[0xb0], uVar6 == 0)) break;
    if (g_groupop != 0) goto LAB_0008b900;
    if ((uVar6 & uVar5) != 0) break;
  }
  goto LAB_0008b90e;
LAB_0008b900:
  if ((g_groupop != 1) || ((uVar6 & uVar5) == 0)) {
LAB_0008b90e:
    if (piVar7[0x61] == 1) {
      fVar2 = (float)piVar7[0x52];
      fVar3 = (float)param_1[0x51];
      if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) {
        fVar2 = (float)piVar7[0x53];
        fVar3 = (float)param_1[0x52];
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) {
          fVar2 = (float)piVar7[0x54];
          fVar3 = (float)param_1[0x53];
          if (((((byte)(fVar2 < fVar3 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) &&
               ((float)piVar7[0x4f] <= (float)param_1[0x54])) &&
              ((float)piVar7[0x50] <= (float)param_1[0x55])) &&
             ((float)piVar7[0x51] <= (float)param_1[0x56])) {
            if ((*(int *)(&DAT_00183e88 + piVar7[0x4b] * 4) != 0) &&
               (*(int *)(*(int *)(&DAT_00183e88 + piVar7[0x4b] * 4) + 0x44) == 0)) {
              iVar8 = SV_HullForBsp(piVar1,param_1 + 0x57,param_1 + 0x5a,&local_10);
              local_1c = (float)param_1[0x22] - local_10;
              local_18 = (float)param_1[0x23] - local_c;
              local_14 = (float)param_1[0x24] - local_8;
              iVar8 = SV_HullPointContents(iVar8,*(undefined4 *)(iVar8 + 8),&local_1c);
              if (iVar8 != -2) goto joined_r0x0008b8ba;
            }
            gGlobalVariables = (float)DAT_0015358c;
            (*DAT_00386230)(piVar1,param_1);
          }
        }
      }
    }
  }
  goto joined_r0x0008b8ba;
}


// SV_Trace_Toss  @ 00083448
undefined4 * SV_Trace_Toss(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int aiStackY_3d8 [2];
  float local_3d0;
  int aiStackY_3cc [2];
  float local_3c4;
  int iStackY_3c0;
  float local_378;
  float local_374;
  float local_370;
  float local_36c;
  float local_368;
  float local_364;
  undefined4 local_360 [5];
  float local_34c;
  float local_348;
  float local_344;
  int local_330;
  undefined1 local_328 [136];
  float local_2a0;
  float local_29c;
  float local_298;
  undefined1 local_288 [48];
  undefined1 local_258 [12];
  undefined1 local_24c [128];
  undefined1 local_1cc [12];
  undefined1 local_1c0 [444];
  
  uVar1 = host_frametime;
  host_frametime = 0.05;
  Q_memcpy(local_328,param_2,0x324);
  puVar3 = &stack0xfffffc50;
  do {
    do {
      *(undefined1 **)(puVar3 + -4) = local_328;
      *(undefined4 *)(puVar3 + -8) = 0x83502;
      SV_CheckVelocity();
      *(undefined1 **)(puVar3 + -8) = local_328;
      *(undefined4 *)(puVar3 + -0xc) = 0x83508;
      SV_AddGravity();
      *(undefined1 **)(puVar3 + -0xc) = local_258;
      *(undefined1 **)(puVar3 + -0x10) = local_24c;
      *(float *)(puVar3 + -0x14) = (float)host_frametime;
      *(undefined1 **)(puVar3 + -0x18) = local_258;
      *(undefined4 *)(puVar3 + -0x1c) = 0x83530;
      VectorMA();
      *(float **)(puVar3 + -0x1c) = &local_36c;
      *(float *)(puVar3 + -0x20) = (float)host_frametime;
      *(undefined1 **)(puVar3 + -0x24) = local_288;
      *(undefined4 *)(puVar3 + -0x28) = 0x8355d;
      VectorScale();
      local_378 = local_2a0 + local_36c;
      local_374 = local_29c + local_368;
      local_370 = local_298 + local_364;
      *(undefined4 *)(puVar3 + -4) = 0;
      *(undefined1 **)(puVar3 + -8) = local_328;
      *(undefined4 *)(puVar3 + -0xc) = 0;
      *(float **)(puVar3 + -0x10) = &local_378;
      *(undefined1 **)(puVar3 + -0x14) = local_1c0;
      *(undefined1 **)(puVar3 + -0x18) = local_1cc;
      *(float **)(puVar3 + -0x1c) = &local_2a0;
      *(undefined4 **)(puVar3 + -0x20) = local_360;
      *(undefined4 *)(puVar3 + -0x24) = 0x835c3;
      SV_Move();
      puVar4 = puVar3 + -4;
      local_2a0 = local_34c;
      local_29c = local_348;
      local_298 = local_344;
      puVar3 = puVar3 + -4;
    } while (local_330 == 0);
    puVar3 = puVar4;
  } while (local_330 == param_3);
  puVar5 = local_360;
  puVar6 = param_1;
  host_frametime = (double)uVar1;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return param_1;
}


// SV_TransferConsistencyInfo  @ 000846e0
int SV_TransferConsistencyInfo(void)

{
  undefined *puVar1;
  int iVar2;
  undefined1 *puVar3;
  int local_138;
  int local_12c;
  int local_128;
  int local_124;
  undefined1 local_120 [12];
  undefined1 local_114 [12];
  char local_108 [260];
  
  local_128 = 0;
  local_12c = 0;
  if (0 < DAT_0017de80) {
    local_138 = 0;
    do {
      puVar1 = &DAT_00153680 + local_138;
      if (((puVar1 != (undefined *)0x0) && (-1 < (char)(&DAT_001536cc)[local_138])) &&
         (iVar2 = SV_FileInConsistencyList(puVar1,&local_124), iVar2 != 0)) {
        (&DAT_001536cc)[local_138] = (&DAT_001536cc)[local_138] | 0x80;
        if (*(int *)((int)&DAT_001536c0 + local_138) == 0) {
          sprintf(local_108,"sound/%s",puVar1);
        }
        else {
          Q_strcpy(local_108,puVar1);
        }
        MD5_Hash_File(&DAT_001536cd + local_138,local_108,0,0,0);
        if (*(int *)((int)&DAT_001536c0 + local_138) == 2) {
          if (*(int *)(local_124 + 0x10) == 1) {
            puVar3 = local_120;
            iVar2 = R_GetStudioBounds(local_108,local_114,puVar3);
            if (iVar2 == 0) {
              Host_Error("Server unable to get bounds for %s\n",local_108);
              return 0;
            }
            Q_memcpy(local_138 + 0x1536df,local_114,0xc);
          }
          else {
            if (*(int *)(local_124 + 0x10) != 2) goto LAB_00084880;
            Q_memcpy(local_138 + 0x1536df,local_124 + 0x14,0xc);
            puVar3 = (undefined1 *)(local_124 + 0x20);
          }
          Q_memcpy(local_138 + 0x1536eb,puVar3,0xc);
          (&DAT_001536de)[local_138] = *(undefined1 *)(local_124 + 0x10);
          COM_Munge(&DAT_001536de + local_138,0x20,DAT_001ab4f0);
        }
LAB_00084880:
        local_128 = local_128 + 1;
      }
      local_138 = local_138 + 0x88;
      local_12c = local_12c + 1;
    } while (local_12c < DAT_0017de80);
  }
  return local_128;
}


// SV_UnlinkEdict  @ 0008b858
void SV_UnlinkEdict(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    RemoveLink(param_1 + 8);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


// SV_UpdateToReliableMessages  @ 0007a594
void SV_UpdateToReliableMessages(void)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_c;
  
  host_client = DAT_001ab4e4;
  iVar4 = 0;
  if (0 < DAT_001ab4e8) {
    do {
      if (host_client[0x12b9] != 0) {
        if ((host_client[0x12fd] != 0) &&
           (dVar1 = (double)(float)host_client[0x12fe],
           (byte)(realtime < dVar1 |
                  (byte)((ushort)((ushort)(NAN(realtime) || NAN(dVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(realtime == dVar1) << 0xe) >> 8)) != 1)) {
          host_client[0x12fd] = 0;
          host_client[0x12fe] = (int)((float)realtime + 1.0);
          SV_ExtractFromUserinfo(host_client);
          SV_FullClientUpdate(host_client,&DAT_00187f54);
        }
        if ((host_client[0x918] == 0) &&
           (((*host_client != 0 || (host_client[3] != 0)) && (sv_gpNewUserMsgs != 0)))) {
          SV_SendUserReg(host_client + 0x1d);
        }
      }
      host_client = host_client + 0x1415;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_001ab4e8);
  }
  if (sv_gpNewUserMsgs != 0) {
    if (sv_gpUserMsgs == 0) {
      sv_gpUserMsgs = sv_gpNewUserMsgs;
    }
    else {
      iVar3 = *(int *)(sv_gpUserMsgs + 0x14);
      iVar4 = sv_gpUserMsgs;
      while (iVar2 = iVar3, iVar2 != 0) {
        iVar4 = iVar2;
        iVar3 = *(int *)(iVar2 + 0x14);
      }
      *(int *)(iVar4 + 0x14) = sv_gpNewUserMsgs;
    }
    sv_gpNewUserMsgs = 0;
  }
  if ((DAT_00186fa4 & 2) != 0) {
    Con_DPrintf("sv.datagram overflowed!\n");
    SZ_Clear(&DAT_00186fa4);
  }
  local_c = 0;
  if (0 < DAT_001ab4e8) {
    piVar5 = DAT_001ab4e4 + 0x944;
    piVar6 = DAT_001ab4e4;
    do {
      if ((piVar5[-0x2c] == 0) && (*piVar6 != 0)) {
        SZ_Write(piVar6 + 0x1d,DAT_00187f58,DAT_00187f60);
        SZ_Write(piVar5,DAT_00186fa8,DAT_00186fb0);
      }
      local_c = local_c + 1;
      piVar5 = piVar5 + 0x1415;
      piVar6 = piVar6 + 0x1415;
    } while (local_c < DAT_001ab4e8);
  }
  SZ_Clear(&DAT_00187f54);
  SZ_Clear(&DAT_00186fa4);
  return;
}


// SV_UploadComplete  @ 00083cb8
bool SV_UploadComplete(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x4d8c) == param_1 + 0x4d0c;
  if (bVar1) {
    SV_RegisterResources();
    SV_PropagateCustomizations();
    Con_DPrintf("Custom resource propagation complete.\n");
    *(undefined4 *)(param_1 + 0x4ea0) = 1;
  }
  return bVar1;
}


// SV_User_f  @ 00072ecc
void SV_User_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  int *piVar6;
  int *local_10;
  int local_c;
  
  if (sv == 0) {
    pcVar4 = "Can\'t \'user\', not running a server\n";
  }
  else {
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      uVar2 = Cmd_Argv(1);
      iVar1 = Q_atoi(uVar2);
      local_c = 0;
      if (0 < DAT_001ab4e8) {
        local_10 = DAT_001ab4e4 + 0x12bd;
        piVar5 = DAT_001ab4e4 + 0x12bb;
        piVar6 = DAT_001ab4e4;
        do {
          if ((((*piVar6 != 0) || (piVar5[-0x12ba] != 0)) || (piVar5[-0x12b8] != 0)) &&
             ((piVar5[-0x9a3] == 0 && ((char)piVar5[0x54] != '\0')))) {
            if (*piVar5 == iVar1) {
LAB_00072f9b:
              Info_Print(local_10);
              return;
            }
            uVar2 = Cmd_Argv(1);
            iVar3 = Q_strcmp(piVar6 + 0x130f,uVar2);
            if (iVar3 == 0) goto LAB_00072f9b;
          }
          local_c = local_c + 1;
          piVar5 = piVar5 + 0x1415;
          local_10 = local_10 + 0x1415;
          piVar6 = piVar6 + 0x1415;
        } while (local_c < DAT_001ab4e8);
      }
      pcVar4 = "User not in server.\n";
    }
    else {
      pcVar4 = "Usage: user <username / userid>\n";
    }
  }
  Con_Printf(pcVar4);
  return;
}


// SV_Users_f  @ 00072fe4
void SV_Users_f(void)

{
  int *piVar1;
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
    local_8 = 0;
    if (0 < DAT_001ab4e8) {
      local_10 = DAT_001ab4e4 + 0x12bb;
      piVar1 = DAT_001ab4e4 + 0x12bc;
      piVar2 = DAT_001ab4e4;
      do {
        if ((((*piVar2 != 0) || (piVar1[-0x12bb] != 0)) || (piVar1[-0x12b9] != 0)) &&
           ((piVar1[-0x9a4] == 0 && ((char)piVar1[0x53] != '\0')))) {
          Con_Printf("%6i : %u : %s\n",*local_10,*piVar1,piVar2 + 0x130f);
          local_c = local_c + 1;
        }
        local_8 = local_8 + 1;
        piVar1 = piVar1 + 0x1415;
        local_10 = local_10 + 0x1415;
        piVar2 = piVar2 + 0x1415;
      } while (local_8 < DAT_001ab4e8);
    }
    Con_Printf("%i users\n",local_c);
  }
  return;
}


// SV_ValidClientMulticast  @ 00073a64
undefined4 SV_ValidClientMulticast(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = param_3 & 0xffffff7f;
  iVar1 = Host_IsSinglePlayerGame();
  if (iVar1 == 0) {
    if (uVar2 == 2) {
      iVar3 = CM_LeafPVS(param_2);
    }
    else if ((int)uVar2 < 3) {
      if (uVar2 != 1) {
LAB_00073ab8:
        Con_Printf("MULTICAST: Error %d!\n",param_3);
        return 0;
      }
    }
    else {
      if (uVar2 != 4) goto LAB_00073ab8;
      iVar3 = CM_LeafPAS(param_2);
    }
    if ((iVar3 != 0) &&
       (iVar1 = SV_PointLeafnum(*(int *)(param_1 + 0x4ae4) + 0x88),
       (*(byte *)(((int)(iVar1 - 1U) >> 3) + iVar3) >> (iVar1 - 1U & 7) & 1) == 0)) {
      return 0;
    }
  }
  return 1;
}


// SV_ValidateClientCommand  @ 000867cc
undefined4 SV_ValidateClientCommand(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  COM_Parse(param_1);
  puVar1 = clcommands;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      return 0;
    }
    iVar2 = Q_strcasecmp(&com_token,puVar1);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
    puVar1 = (&clcommands)[iVar3];
  }
  return 1;
}


// SV_WriteClientdataToMessage  @ 00074938
void SV_WriteClientdataToMessage(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined8 *puVar4;
  int local_250;
  undefined1 *local_240;
  int local_23c;
  undefined1 local_238 [88];
  undefined1 local_1e0 [476];
  
  if (g_pclientdelta == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("g_pclientdelta","/home/jihad/valve/goldsrc/engine/sv_main.c",0x5b3,
                  "SV_WriteClientdataToMessage");
  }
  if (g_pweapondelta != 0) {
    local_240 = local_1e0;
    Q_memset(local_240,0,0x1dc);
    iVar2 = *(int *)(param_1 + 0x4ae4);
    puVar4 = (undefined8 *)
             ((*(uint *)(param_1 + 0x60) & SV_UPDATE_MASK) * 0xd10 + *(int *)(param_1 + 0x34e0));
    *puVar4 = realtime;
    *(undefined4 *)(puVar4 + 1) = 0xbf800000;
    if (*(int *)(param_1 + 0x2450) != 0) {
      MSG_WriteByte(param_2,0x2a);
      *(undefined4 *)(param_1 + 0x2450) = 0;
    }
    if (*(int *)(iVar2 + 0x120) != 0) {
      if (*(int *)(iVar2 + 0x120) == 2) {
        MSG_WriteByte(param_2,0x26);
        MSG_WriteHiresAngle(param_2,*(undefined4 *)(iVar2 + 0xe0));
        *(undefined4 *)(iVar2 + 0xe0) = 0;
      }
      else {
        MSG_WriteByte(param_2,10);
        MSG_WriteHiresAngle(param_2,*(undefined4 *)(iVar2 + 0xd0));
        MSG_WriteHiresAngle(param_2,*(undefined4 *)(iVar2 + 0xd4));
        MSG_WriteHiresAngle(param_2,*(undefined4 *)(iVar2 + 0xd8));
      }
      *(undefined4 *)(iVar2 + 0x120) = 0;
    }
    iVar1 = (int)puVar4 + 0xc;
    Q_memset(iVar1,0,0x1dc);
    (*DAT_003862b8)(iVar2,*(int *)(host_client + 0x4f4c) != 0,iVar1);
    MSG_WriteByte(param_2,0xf);
    MSG_StartBitWriting(param_2);
    if (*(uint *)(host_client + 0x2454) != 0xffffffff) {
      local_240 = (undefined1 *)
                  ((*(uint *)(host_client + 0x2454) & SV_UPDATE_MASK) * 0xd10 +
                   *(int *)(host_client + 0x34e0) + 0xc);
    }
    if (*(int *)(host_client + 0x2454) == -1) {
      MSG_WriteBits(0,1);
    }
    else {
      MSG_WriteBits(1,1);
      MSG_WriteBits(*(undefined4 *)(host_client + 0x2454),8);
    }
    DELTA_WriteDelta(local_240,iVar1,1,g_pclientdelta,0);
    if (*(int *)(host_client + 0x4f4c) != 0) {
      Q_memset(local_238,0,0x58);
      puVar4 = puVar4 + 0x3d;
      iVar2 = (*DAT_003862c8)(*(undefined4 *)(host_client + 0x4ae4),puVar4);
      if (iVar2 != 0) {
        local_23c = 0;
        local_250 = 0x1e8;
        do {
          puVar3 = local_238;
          if (*(uint *)(host_client + 0x2454) != 0xffffffff) {
            puVar3 = (undefined1 *)
                     (local_250 +
                     (*(uint *)(host_client + 0x2454) & SV_UPDATE_MASK) * 0xd10 +
                     *(int *)(host_client + 0x34e0));
          }
          iVar2 = DELTA_CheckDelta(puVar3,puVar4,g_pweapondelta);
          if (iVar2 != 0) {
            MSG_WriteBits(1,1);
            MSG_WriteBits(local_23c,5);
            DELTA_WriteDelta(puVar3,puVar4,1,g_pweapondelta,0);
          }
          puVar4 = puVar4 + 0xb;
          local_250 = local_250 + 0x58;
          local_23c = local_23c + 1;
        } while (local_23c < 0x20);
      }
    }
    MSG_WriteBits(0,1);
    MSG_EndBitWriting(param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("g_pweapondelta","/home/jihad/valve/goldsrc/engine/sv_main.c",0x5b4,
                "SV_WriteClientdataToMessage");
}


// SV_WriteDeltaDescriptionsToClient  @ 00073ec8
void SV_WriteDeltaDescriptionsToClient(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 local_48 [68];
  
  Q_memset(local_48,0,0x44);
  puVar2 = g_sv_delta;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    MSG_WriteByte(param_1,0xe);
    MSG_WriteString(param_1,puVar2[1]);
    uVar1 = *(uint *)(puVar2[3] + 4);
    MSG_StartBitWriting(param_1);
    MSG_WriteBits(uVar1,0x10);
    iVar5 = 0;
    if (0 < (int)uVar1) {
      iVar4 = 0;
      uVar3 = uVar1 & 3;
      if (uVar3 != 0) {
        if (1 < uVar3) {
          if (2 < uVar3) {
            DELTA_WriteDelta(local_48,*(undefined4 *)(puVar2[3] + 0x2c),1,g_MetaDelta,0);
            iVar4 = 0x44;
          }
          DELTA_WriteDelta(local_48,iVar4 + *(int *)(puVar2[3] + 0x2c),1,g_MetaDelta,0);
          iVar4 = iVar4 + 0x44;
          iVar5 = (2 < uVar3) + 1;
        }
        DELTA_WriteDelta(local_48,iVar4 + *(int *)(puVar2[3] + 0x2c),1,g_MetaDelta,0);
        iVar4 = iVar4 + 0x44;
        iVar5 = iVar5 + 1;
        if ((int)uVar1 <= iVar5) goto LAB_00074092;
      }
      do {
        DELTA_WriteDelta(local_48,iVar4 + *(int *)(puVar2[3] + 0x2c),1,g_MetaDelta,0);
        DELTA_WriteDelta(local_48,*(int *)(puVar2[3] + 0x2c) + 0x44 + iVar4,1,g_MetaDelta,0);
        DELTA_WriteDelta(local_48,*(int *)(puVar2[3] + 0x2c) + 0x88 + iVar4,1,g_MetaDelta,0);
        DELTA_WriteDelta(local_48,*(int *)(puVar2[3] + 0x2c) + 0xcc + iVar4,1,g_MetaDelta,0);
        iVar4 = iVar4 + 0x110;
        iVar5 = iVar5 + 4;
      } while (iVar5 < (int)uVar1);
    }
LAB_00074092:
    MSG_EndBitWriting(param_1);
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


// SV_WriteDeltaHeader  @ 000796a4
void SV_WriteDeltaHeader(int param_1,int param_2,int param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int aiStack_20 [4];
  
  aiStack_20[3] = 1;
  aiStack_20[2] = (int)(param_2 != 0);
  aiStack_20[1] = 0x796cd;
  MSG_WriteBits();
  iVar1 = *param_4;
  if ((param_1 - iVar1) - 1U < 0x3f) {
    aiStack_20[3] = 1;
    aiStack_20[2] = 0;
    aiStack_20[1] = 0x796e8;
    MSG_WriteBits();
    aiStack_20[1] = 6;
    aiStack_20[0] = param_1 - iVar1;
  }
  else {
    aiStack_20[3] = 1;
    aiStack_20[2] = 1;
    aiStack_20[1] = 0x796f9;
    MSG_WriteBits();
    aiStack_20[1] = 0xb;
    aiStack_20[0] = param_1;
  }
  MSG_WriteBits();
  *param_4 = param_1;
  if (param_2 == 0) {
    aiStack_20[3] = 1;
    aiStack_20[2] = (int)(param_3 != 0);
    aiStack_20[1] = 0x79723;
    MSG_WriteBits();
    if (param_5 == 0) {
      aiStack_20[3] = 1;
      piVar2 = aiStack_20 + 2;
      aiStack_20[2] = 0;
    }
    else {
      aiStack_20[3] = 1;
      aiStack_20[2] = 1;
      aiStack_20[1] = 0x79735;
      MSG_WriteBits();
      aiStack_20[1] = 6;
      piVar2 = aiStack_20;
      aiStack_20[0] = param_6;
    }
    *(undefined4 *)((int)piVar2 + -4) = 0x79749;
    MSG_WriteBits();
  }
  return;
}


// SV_WriteEntitiesToClient  @ 0007a16c
void SV_WriteEntitiesToClient(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iStack_1542c;
  int iStack_15428;
  undefined4 uStack_15410;
  undefined4 uStack_1540c;
  int iStack_15408;
  undefined1 auStack_15404 [87040];
  
  uStack_15410 = 0;
  uStack_1540c = 0;
  iVar1 = (*(uint *)(param_1 + 0x60) & SV_UPDATE_MASK) * 0xd10 + *(int *)(param_1 + 0x34e0);
  (*DAT_003862b4)(*(undefined4 *)(param_1 + 0x4ae8),*(undefined4 *)(param_1 + 0x4ae4),&uStack_15410,
                  &uStack_1540c);
  SV_ClearPacketEntities(iVar1);
  piVar6 = (int *)(iVar1 + 0xce8);
  iStack_15408 = 0;
  iVar3 = SV_ShouldUpdatePing(param_1);
  iVar2 = *(int *)(param_1 + 0x4f4c);
  iVar5 = 1;
  if (1 < DAT_00186f8c) {
    iStack_15428 = 0;
    iStack_1542c = 0x324;
    do {
      if (((0 >= iVar5 || iVar5 > DAT_001ab4e8) || (*(int *)(iStack_15428 + DAT_001ab4e4) != 0)) ||
         (((int *)(iStack_15428 + DAT_001ab4e4))[1] != 0)) {
        if (0xff < iStack_15408) {
          Con_DPrintf("Too many entities in visible packet list.\n");
          break;
        }
        iVar4 = (*DAT_003862bc)(auStack_15404 + iStack_15408 * 0x154,iVar5,
                                iStack_1542c + DAT_00186f94,*(undefined4 *)(host_client + 0x4ae4),
                                iVar2 != 0,0 < iVar5 && iVar5 <= DAT_001ab4e8,uStack_15410);
        if (iVar4 != 0) {
          iStack_15408 = iStack_15408 + 1;
        }
      }
      iStack_15428 = iStack_15428 + 0x5054;
      iStack_1542c = iStack_1542c + 0x324;
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00186f8c);
  }
  SV_AllocPacketEntities(iVar1,iStack_15408);
  if (*piVar6 != 0) {
    Q_memcpy(*(undefined4 *)(iVar1 + 0xd0c),auStack_15404,*piVar6 * 0x154);
  }
  SV_EmitPacketEntities(param_1,piVar6,param_2);
  SV_EmitEvents(param_1,piVar6,param_2);
  if (iVar3 != 0) {
    SV_EmitPings(param_1,param_2);
  }
  return;
}


// SV_WriteIP_f  @ 0007d68c
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void SV_WriteIP_f(void)

{
  uint uVar1;
  FILE *__stream;
  int iVar2;
  int iVar3;
  char local_108 [260];
  
  sprintf(local_108,"%s/listip.cfg",com_gamedir);
  Con_Printf("Writing %s.\n",local_108);
  __stream = fopen(local_108,"wb");
  if (__stream == (FILE *)0x0) {
    Con_Printf("Couldn\'t open %s\n",local_108);
  }
  else {
    iVar3 = 0;
    if (0 < numipfilters) {
      iVar2 = 0;
      do {
        uVar1 = *(uint *)((int)&DAT_001a74c4 + iVar2);
        if ((byte)((byte)((ushort)((ushort)NAN(*(float *)((int)&DAT_001a74cc + iVar2)) << 10) >> 8)
                  | (byte)((ushort)((ushort)(*(float *)((int)&DAT_001a74cc + iVar2) == 0.0) << 0xe)
                          >> 8)) == 0x40) {
          fprintf(__stream,"addip 0.0 %i.%i.%i.%i\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
                  uVar1 >> 0x10 & 0xff,uVar1 >> 0x18);
        }
        iVar2 = iVar2 + 0x10;
        iVar3 = iVar3 + 1;
      } while (iVar3 < numipfilters);
    }
    fclose(__stream);
  }
  return;
}


// SV_WriteId_f  @ 0007d0e8
void SV_WriteId_f(void)

{
  FILE *__stream;
  int iVar1;
  int iVar2;
  char local_108 [260];
  
  sprintf(local_108,"%s/banned.cfg",com_gamedir);
  Con_Printf("Writing %s.\n",local_108);
  __stream = fopen(local_108,"wb");
  if (__stream == (FILE *)0x0) {
    Con_Printf("Couldn\'t open %s\n",local_108);
  }
  else {
    iVar2 = 0;
    if (0 < numuserfilters) {
      iVar1 = 0;
      do {
        if ((byte)((byte)((ushort)((ushort)NAN(*(float *)((int)&DAT_00192468 + iVar1)) << 10) >> 8)
                  | (byte)((ushort)((ushort)(*(float *)((int)&DAT_00192468 + iVar1) == 0.0) << 0xe)
                          >> 8)) == 0x40) {
          fprintf(__stream,"banid 0.0 %u\n",*(undefined4 *)((int)&userfilters + iVar1));
        }
        iVar1 = iVar1 + 0xc;
        iVar2 = iVar2 + 1;
      } while (iVar2 < numuserfilters);
    }
    fclose(__stream);
  }
  return;
}


// SV_WriteMovevarsToClient  @ 00073c68
void SV_WriteMovevarsToClient(undefined4 param_1)

{
  MSG_WriteByte(param_1,0x2c);
  MSG_WriteFloat(param_1,movevars);
  MSG_WriteFloat(param_1,DAT_00152584);
  MSG_WriteFloat(param_1,DAT_00152588);
  MSG_WriteFloat(param_1,DAT_0015258c);
  MSG_WriteFloat(param_1,DAT_00152590);
  MSG_WriteFloat(param_1,DAT_00152594);
  MSG_WriteFloat(param_1,DAT_00152598);
  MSG_WriteFloat(param_1,DAT_0015259c);
  MSG_WriteFloat(param_1,DAT_001525a0);
  MSG_WriteFloat(param_1,DAT_001525a4);
  MSG_WriteFloat(param_1,DAT_001525a8);
  MSG_WriteFloat(param_1,DAT_001525ac);
  MSG_WriteFloat(param_1,DAT_001525b0);
  MSG_WriteFloat(param_1,DAT_001525b4);
  MSG_WriteFloat(param_1,DAT_001525b8);
  MSG_WriteFloat(param_1,DAT_001525bc);
  MSG_WriteByte(param_1,DAT_001525c0 != 0);
  MSG_WriteFloat(param_1,DAT_001525e4);
  MSG_WriteFloat(param_1,DAT_001525e8);
  MSG_WriteFloat(param_1,DAT_001525ec);
  MSG_WriteFloat(param_1,DAT_001525f0);
  MSG_WriteFloat(param_1,DAT_001525f4);
  MSG_WriteFloat(param_1,DAT_001525f8);
  MSG_WriteFloat(param_1,DAT_001525fc);
  MSG_WriteFloat(param_1,DAT_00152600);
  MSG_WriteString(param_1,&DAT_001525c4);
  return;
}


// SV_WriteSpawn  @ 00074d04
void SV_WriteSpawn(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  int *local_680;
  undefined1 local_678 [36];
  int local_654;
  undefined1 local_64c [1352];
  char local_104 [256];
  
  if (DAT_00153588 == 0) {
    DAT_00186fa0 = 1;
    iVar4 = host_client[0x12b9];
    ReleaseEntityDLLFields(iVar4);
    Q_memset(iVar4 + 0x80,0,0x2a4);
    InitEntityDLLFields(iVar4);
    uVar1 = NUM_FOR_EDICT(iVar4);
    *(undefined4 *)(iVar4 + 0x228) = uVar1;
    *(int *)(iVar4 + 0x250) = (int)host_client - (pr_strings + -0x4c3c);
    gGlobalVariables = (float)DAT_0015358c;
    (*DAT_00386268)(sv_player);
    DAT_00186fa0 = 2;
  }
  else {
    DAT_00153584 = 0;
  }
  SZ_Clear(host_client + 0x1d);
  SZ_Clear(host_client + 0x944);
  MSG_WriteByte(param_1,7);
  MSG_WriteFloat(param_1,(float)DAT_0015358c);
  iVar4 = 0;
  host_client[0x12fd] = 1;
  if (0 < DAT_001ab4e8) {
    local_680 = DAT_001ab4e4 + 1;
    piVar2 = DAT_001ab4e4;
    do {
      if ((((piVar2 == host_client) || (*piVar2 != 0)) || (local_680[2] != 0)) || (*local_680 != 0))
      {
        SV_FullClientUpdate(piVar2,host_client + 0x1d);
      }
      iVar4 = iVar4 + 1;
      local_680 = local_680 + 0x1415;
      piVar2 = piVar2 + 0x1415;
    } while (iVar4 < DAT_001ab4e8);
  }
  iVar4 = 0;
  do {
    MSG_WriteByte(param_1,0xc);
    MSG_WriteByte(param_1,(int)(char)iVar4);
    MSG_WriteString(param_1,(&DAT_00186e8c)[iVar4]);
    MSG_WriteByte(param_1,0xc);
    MSG_WriteByte(param_1,(int)(char)(iVar4 + 1));
    MSG_WriteString(param_1,(&DAT_00186e8c)[iVar4 + 1]);
    MSG_WriteByte(param_1,0xc);
    MSG_WriteByte(param_1,(int)(char)(iVar4 + 2));
    MSG_WriteString(param_1,(&DAT_00186e8c)[iVar4 + 2]);
    MSG_WriteByte(param_1,0xc);
    MSG_WriteByte(param_1,(int)(char)(iVar4 + 3));
    MSG_WriteString(param_1,(&DAT_00186e8c)[iVar4 + 3]);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x40);
  iVar4 = host_client[0x12b9];
  MSG_WriteByte(param_1,10);
  MSG_WriteHiresAngle(param_1,*(undefined4 *)(iVar4 + 0xf4));
  MSG_WriteHiresAngle(param_1,*(undefined4 *)(iVar4 + 0xf8));
  MSG_WriteHiresAngle(param_1,0);
  SV_WriteClientdataToMessage(host_client,param_1);
  if (DAT_00153588 != 0) {
    Q_memset(local_678,0,0x574);
    DAT_00152bdc = local_678;
    (*DAT_0038628c)();
    MSG_WriteByte(param_1,0x21);
    uVar1 = Host_SaveGameDirectory(&DAT_001535a8);
    sprintf(local_104,"%s%s.HL2",uVar1);
    COM_FixSlashes(local_104);
    MSG_WriteString(param_1,local_104);
    MSG_WriteByte(param_1,local_654);
    iVar4 = 0;
    if (0 < local_654) {
      puVar3 = local_64c;
      do {
        MSG_WriteString(param_1,puVar3);
        puVar3 = puVar3 + 0x50;
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_654);
    }
    DAT_00153588 = 0;
    DAT_00152bdc = (undefined1 *)0x0;
  }
  MSG_WriteByte(param_1,0x19);
  MSG_WriteByte(param_1,1);
  *host_client = 1;
  host_client[1] = 1;
  host_client[3] = 1;
  host_client[2] = 0;
  return;
}


// SV_movestep  @ 0007edb4
/* WARNING: Type propagation algorithm not settling */

undefined4 SV_movestep(uint param_1,float *param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  uint *puVar5;
  uint auStack_a4 [2];
  int local_64;
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
  float local_10;
  float local_c;
  float local_8;
  
  auStack_a4[1] = 0x7edc5;
  uVar1 = *(uint *)(param_1 + 0x224) >> 0x17 & 1;
  local_10 = *(float *)(param_1 + 0x88);
  local_c = *(float *)(param_1 + 0x8c);
  local_8 = *(float *)(param_1 + 0x90);
  local_1c = local_10 + *param_2;
  local_18 = local_c + param_2[1];
  if ((*(uint *)(param_1 + 0x224) & 3) == 0) {
    local_14 = local_8 + param_2[2] + (float)sv_stepsize._12_4_;
    local_20 = local_14 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
    auStack_a4[0] = param_1;
    auStack_a4[1] = uVar1;
    local_28 = local_1c;
    local_24 = local_18;
    SV_Move(&local_60,&local_1c,param_1 + 0x15c,param_1 + 0x168,&local_28,0);
    puVar5 = auStack_a4 + 1;
    if (local_60 != 0) {
      return 0;
    }
    if (local_5c != 0) {
      local_14 = local_14 - (float)sv_stepsize._12_4_;
      auStack_a4[0] = uVar1;
      SV_Move(&local_60,&local_1c,param_1 + 0x15c,param_1 + 0x168,&local_28,0,param_1);
      puVar5 = auStack_a4;
      if (local_60 != 0) {
        return 0;
      }
      if (local_5c != 0) {
        return 0;
      }
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) == 0x40) {
      if ((*(byte *)(param_1 + 0x225) & 4) != 0) {
        *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x88) + *param_2;
        *(float *)(param_1 + 0x8c) = *(float *)(param_1 + 0x8c) + param_2[1];
        *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + param_2[2];
        if (param_3 != 0) {
          puVar5[0xffffffff] = 1;
          puVar5[0xfffffffe] = param_1;
          puVar5[0xfffffffd] = 0x7f091;
          SV_LinkEdict();
        }
        *(byte *)(param_1 + 0x225) = *(byte *)(param_1 + 0x225) & 0xfd;
        return 1;
      }
      return 0;
    }
    *(undefined4 *)(param_1 + 0x88) = local_4c;
    *(undefined4 *)(param_1 + 0x8c) = local_48;
    *(undefined4 *)(param_1 + 0x90) = local_44;
    puVar5[0xffffffff] = param_1;
    puVar5[0xfffffffe] = 0x7f0c1;
    iVar3 = SV_CheckBottom();
    if (iVar3 == 0) {
      if ((*(byte *)(param_1 + 0x225) & 4) == 0) {
        *(float *)(param_1 + 0x88) = local_10;
        *(float *)(param_1 + 0x8c) = local_c;
        *(float *)(param_1 + 0x90) = local_8;
        return 0;
      }
    }
    else {
      if ((*(uint *)(param_1 + 0x224) & 0x400) != 0) {
        *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xfffffbff;
      }
      *(undefined4 *)(param_1 + 0x21c) = local_30;
    }
  }
  else {
    local_64 = 0;
    puVar4 = &stack0xffffff64;
    while( true ) {
      local_1c = *(float *)(param_1 + 0x88) + *param_2;
      local_18 = *(float *)(param_1 + 0x8c) + param_2[1];
      local_14 = *(float *)(param_1 + 0x90) + param_2[2];
      iVar3 = *(int *)(param_1 + 0x210);
      if ((local_64 == 0) && (iVar3 != 0)) {
        fVar2 = *(float *)(param_1 + 0x90) - *(float *)(iVar3 + 0x90);
        if (40.0 < fVar2) {
          local_14 = local_14 - 8.0;
        }
        if (0x3f < (byte)((30.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 30.0) << 0xe) >> 8)) - 1)) {
          local_14 = local_14 + 8.0;
        }
      }
      *(uint *)(puVar4 + -4) = uVar1;
      *(uint *)(puVar4 + -8) = param_1;
      *(undefined4 *)(puVar4 + -0xc) = 0;
      *(float **)(puVar4 + -0x10) = &local_1c;
      *(uint *)(puVar4 + -0x14) = param_1 + 0x168;
      *(uint *)(puVar4 + -0x18) = param_1 + 0x15c;
      *(uint *)(puVar4 + -0x1c) = param_1 + 0x88;
      *(int **)(puVar4 + -0x20) = &local_60;
      *(undefined4 *)(puVar4 + -0x24) = 0x7ef0c;
      SV_Move();
      if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) == 0x40) break;
      if (iVar3 == 0) {
        return 0;
      }
      local_64 = local_64 + 1;
      puVar4 = puVar4 + -4;
      if (1 < local_64) {
        return 0;
      }
    }
    g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
    if ((*(byte *)(param_1 + 0x224) & 2) != 0) {
      *(undefined4 **)(puVar4 + -8) = &local_4c;
      *(undefined4 *)(puVar4 + -0xc) = 520000;
      iVar3 = SV_PointContents();
      if (iVar3 == -1) {
        return 0;
      }
    }
    puVar5 = (uint *)(puVar4 + -4);
    *(undefined4 *)(param_1 + 0x88) = local_4c;
    *(undefined4 *)(param_1 + 0x8c) = local_48;
    *(undefined4 *)(param_1 + 0x90) = local_44;
  }
  if (param_3 != 0) {
    *(undefined4 *)((int)puVar5 + -4) = 1;
    *(uint *)((int)puVar5 + -8) = param_1;
    *(undefined4 *)((int)puVar5 + -0xc) = 0x7f11f;
    SV_LinkEdict();
  }
  return 1;
}


// SV_movetest  @ 0007ebd0
undefined4 SV_movetest(int param_1,float *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iStack_88;
  int iStack_84;
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
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(param_1 + 0x88);
  local_c = *(float *)(param_1 + 0x8c);
  local_8 = *(float *)(param_1 + 0x90);
  local_28 = local_10 + *param_2;
  local_24 = local_c + param_2[1];
  local_14 = local_8 + param_2[2] + (float)sv_stepsize._12_4_;
  local_20 = local_14 - ((float)sv_stepsize._12_4_ + (float)sv_stepsize._12_4_);
  iStack_84 = param_1;
  iStack_88 = 0;
  local_1c = local_28;
  local_18 = local_24;
  SV_MoveNoEnts(&local_60,&local_1c,param_1 + 0x15c,param_1 + 0x168,&local_28);
  piVar3 = &iStack_84;
  if (local_60 == 0) {
    if (local_5c != 0) {
      local_14 = local_14 - (float)sv_stepsize._12_4_;
      iStack_88 = param_1;
      SV_MoveNoEnts(&local_60,&local_1c,param_1 + 0x15c,param_1 + 0x168,&local_28,0);
      piVar3 = &iStack_88;
      if ((local_60 != 0) || (local_5c != 0)) goto LAB_0007ed20;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) == 0x40) {
      if ((*(byte *)(param_1 + 0x225) & 4) == 0) goto LAB_0007ed20;
      *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x88) + *param_2;
      *(float *)(param_1 + 0x8c) = *(float *)(param_1 + 0x8c) + param_2[1];
      *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + param_2[2];
      if (param_3 != 0) {
        *(undefined4 *)((int)piVar3 + -4) = 1;
        *(int *)((int)piVar3 + -8) = param_1;
        *(undefined4 *)((int)piVar3 + -0xc) = 0x7ed12;
        SV_LinkEdict();
      }
      *(byte *)(param_1 + 0x225) = *(byte *)(param_1 + 0x225) & 0xfd;
    }
    else {
      *(undefined4 *)(param_1 + 0x88) = local_4c;
      *(undefined4 *)(param_1 + 0x8c) = local_48;
      *(undefined4 *)(param_1 + 0x90) = local_44;
      *(int *)((int)piVar3 + -4) = param_1;
      *(undefined4 *)((int)piVar3 + -8) = 0x7ed49;
      iVar1 = SV_CheckBottom();
      if (iVar1 == 0) {
        if ((*(byte *)(param_1 + 0x225) & 4) == 0) {
          *(float *)(param_1 + 0x88) = local_10;
          *(float *)(param_1 + 0x8c) = local_c;
          *(float *)(param_1 + 0x90) = local_8;
          return 0;
        }
      }
      else {
        if ((*(uint *)(param_1 + 0x224) & 0x400) != 0) {
          *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) & 0xfffffbff;
        }
        *(undefined4 *)(param_1 + 0x21c) = local_30;
      }
      if (param_3 != 0) {
        *(undefined4 *)((int)piVar3 + -4) = 1;
        *(int *)((int)piVar3 + -8) = param_1;
        *(undefined4 *)((int)piVar3 + -0xc) = 0x7eda3;
        SV_LinkEdict();
      }
    }
    uVar2 = 1;
  }
  else {
LAB_0007ed20:
    uVar2 = 0;
  }
  return uVar2;
}


