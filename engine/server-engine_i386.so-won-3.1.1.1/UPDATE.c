// UPDATE_AddServer  @ 000c7cd0
void UPDATE_AddServer(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char **ppcVar3;
  undefined4 *puVar4;
  undefined4 auStack_4c [5];
  char *apcStack_38 [7];
  undefined4 *local_8;
  
  apcStack_38[6] = (char *)0xc7cde;
  for (local_8 = sUpdateMasterAdr; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)local_8[5])
  {
    puVar1 = param_1;
    ppcVar3 = apcStack_38;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar3 = (char *)*puVar1;
      puVar1 = puVar1 + 1;
      ppcVar3 = ppcVar3 + 1;
    }
    puVar1 = local_8;
    puVar4 = auStack_4c;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar2 = NET_CompareAdr();
    if (iVar2 != 0) break;
  }
  if (local_8 == (undefined4 *)0x0) {
    apcStack_38[3] = (char *)0x18;
    apcStack_38[2] = (char *)0xc7d4e;
    puVar1 = (undefined4 *)Mem_Malloc();
    if (puVar1 == (undefined4 *)0x0) {
      apcStack_38[4] = (char *)0x18;
      apcStack_38[3] = "Error allocating %i bytes for secure master address.";
      apcStack_38[2] = (char *)0xc7d6d;
      Sys_Error();
    }
    apcStack_38[5] = (char *)0x18;
    apcStack_38[4] = (char *)0x0;
    apcStack_38[2] = (char *)0xc7d80;
    apcStack_38[3] = (char *)puVar1;
    Q_memset();
    puVar4 = puVar1;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *param_1;
      param_1 = param_1 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar1[5] = sUpdateMasterAdr;
    sUpdateMasterAdr = puVar1;
  }
  return;
}


// UPDATE_BuildServerList  @ 000c7db4
void UPDATE_BuildServerList(void)

{
  int iVar1;
  char local_274 [256];
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  char local_164 [64];
  undefined1 local_124 [20];
  int local_110;
  int local_10c;
  char local_108 [259];
  undefined1 local_5;
  
  local_16c = 0;
  if (sUpdateMasterAdr == 0) {
    strcpy(local_108,"valvecomm.lst");
    local_174 = COM_CheckParm("-comm");
    if ((local_174 != 0) && (local_174 < com_argc + -1)) {
      Q_strncpy(local_108,*(undefined4 *)(local_174 * 4 + com_argv + 4),0x103);
      local_5 = 0;
    }
    local_110 = COM_LoadFile(local_108,5,0);
    local_10c = local_110;
    if (local_110 == 0) {
      iVar1 = NET_StringToAdr("gridmaster.valvesoftware.com:27012",local_124);
      if (iVar1 != 0) {
        UPDATE_AddServer(local_124);
      }
    }
    else {
LAB_000c7ed8:
      local_110 = COM_Parse(local_110);
      iVar1 = Q_strlen(&com_token);
      if (0 < iVar1) {
        local_170 = 1;
        iVar1 = Q_stricmp(&com_token,"Secure");
        if (iVar1 == 0) {
          local_170 = 0;
        }
        local_110 = COM_Parse(local_110);
        iVar1 = Q_strlen(&com_token);
        if ((iVar1 < 1) || (iVar1 = Q_stricmp(&com_token,&DAT_000ee02a), iVar1 != 0))
        goto LAB_000c819c;
        while( true ) {
          local_110 = COM_Parse(local_110);
          iVar1 = Q_strlen(&com_token);
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(&com_token,&DAT_000ee02c), iVar1 == 0)) break;
          snprintf(local_274,0x100,"%s",&com_token);
          local_110 = COM_Parse(local_110);
          iVar1 = Q_strlen(&com_token);
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(&com_token,&DAT_000ee031), iVar1 != 0)) break;
          local_110 = COM_Parse(local_110);
          iVar1 = Q_strlen(&com_token);
          if (iVar1 < 1) break;
          local_168 = Q_atoi(&com_token);
          if (local_168 == 0) {
            local_168 = 0x6984;
          }
          snprintf(local_164,0x40,"%s:%i",local_274,local_168);
          iVar1 = NET_StringToAdr(local_164,local_124);
          if (iVar1 == 0) {
            local_170 = 1;
          }
          if (local_170 == 0) {
            UPDATE_AddServer(local_124);
            local_16c = local_16c + 1;
          }
        }
        goto LAB_000c7ed8;
      }
LAB_000c819c:
      if ((local_16c == 0) &&
         (iVar1 = NET_StringToAdr("gridmaster.valvesoftware.com:27012",local_124), iVar1 != 0)) {
        UPDATE_AddServer(local_124);
      }
      Mem_Free(local_10c);
    }
  }
  return;
}


// UPDATE_FinishDownload  @ 000c8a7c
void UPDATE_FinishDownload(void)

{
  int iVar1;
  undefined1 local_6c [16];
  undefined1 local_5c [88];
  
  if (sUpdateComState == 6) {
    Q_memset(local_5c,0,0x58);
    MD5Init(local_5c);
    MD5Update(local_5c,sUpdateFileData,sUpdateFileSize);
    MD5Final(local_6c,local_5c);
    iVar1 = Q_memcmp(local_6c,sUpdateMD5Hash,0x10);
    if (iVar1 == 0) {
      if (sUpdateNewModule != (int *)0x0) {
        sUpdateNewModule[1] = sUpdateFileSize;
        *sUpdateNewModule = sUpdateFileData;
        Q_memcpy(sUpdateNewModule + 2,sUpdateMD5Hash,0x10);
      }
    }
    else {
      Mem_Free(sUpdateFileData);
      sUpdateFileData = 0;
    }
  }
  else if (sUpdateFileData != 0) {
    Mem_Free(sUpdateFileData);
    sUpdateFileData = 0;
  }
  sUpdateComState = 0;
  return;
}


// UPDATE_GetFile  @ 000c9070
undefined * UPDATE_GetFile(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 auStack_4c [4];
  undefined4 uStack_3c;
  int aiStack_38 [3];
  undefined *puStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  if (sUpdateMasterAdr == (undefined4 *)0x0) {
    puVar2 = (undefined *)0x0;
  }
  else {
    sUpdateComState = 1;
    sUpdateChallengeNumber = 0;
    sUpdatePacketRetries = 0;
    sUpdateFileSize = 0;
    sUpdateBytesReceived = 0;
    sUpdateLastSend = 0xc0c3878000000000;
    sUpdateFileData = (undefined *)0x0;
    sUpdateName = param_1;
    sUpdateResendDelay._0_4_ = 0;
    sUpdateResendDelay._4_4_ = 0;
    while( true ) {
      uStack_20 = 0xc9105;
      iVar1 = UPDATE_IsActive();
      if (iVar1 == 0) break;
      while( true ) {
        puStack_2c = (undefined *)0x1;
        aiStack_38[2] = 0xc911a;
        iVar1 = NET_GetPacket();
        if (iVar1 == 0) break;
        puVar3 = sUpdateMasterAdr;
        piVar4 = aiStack_38;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar4 = *puVar3;
          puVar3 = puVar3 + 1;
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
          uStack_20 = 0xc9168;
          UPDATE_ProcessMessage();
        }
      }
      uStack_20 = 0xc9171;
      UPDATE_Resend();
      puStack_2c = (undefined *)0x1;
      aiStack_38[2] = 0xc917b;
      Sys_Sleep();
    }
    uStack_20 = 0xc9185;
    UPDATE_FinishDownload();
    puVar2 = sUpdateFileData;
    if ((param_2 != 0) && (sUpdateFileData != (undefined *)0x0)) {
      puStack_28 = &DAT_000ee080;
      puStack_2c = (undefined *)sUpdateName;
      aiStack_38[2] = 0xc91ac;
      iVar1 = FS_Open();
      if (iVar1 != 0) {
        uStack_24 = sUpdateFileSize;
        puStack_28 = sUpdateFileData;
        aiStack_38[0] = sUpdateName;
        uStack_3c = 0xc91da;
        puStack_2c = (undefined *)COM_SkipPath();
        aiStack_38[2] = 0xc91e5;
        COM_WriteFile();
      }
      puStack_2c = sUpdateFileData;
      aiStack_38[2] = 0xc91f7;
      Mem_Free();
      sUpdateFileData = (undefined *)0x0;
      puVar2 = sUpdateFileData;
    }
  }
  return puVar2;
}


// UPDATE_GetModule  @ 000c921c
void UPDATE_GetModule(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = UPDATE_IsActive();
  if (iVar1 == 0) {
    sUpdateComState = 1;
    sUpdateChallengeNumber = 0;
    sUpdatePacketRetries = 0;
    sUpdateFileSize = 0;
    sUpdateBytesReceived = 0;
    sUpdateLastSend = 0xc0c3878000000000;
    sUpdateFileData = 0;
    sUpdateName = param_1;
    sUpdateResendDelay._0_4_ = 0;
    sUpdateResendDelay._4_4_ = 0x3ff00000;
    sUpdateCurModule = param_3;
    sUpdateNewModule = param_2;
    Q_memset(param_2,0,0x18);
  }
  return;
}


// UPDATE_GetModuleBlocking  @ 000c92d4
bool UPDATE_GetModuleBlocking(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  sUpdateCurModule = 0;
  sUpdateNewModule = param_2;
  iVar1 = UPDATE_GetFile(param_1,0);
  *param_2 = iVar1;
  iVar1 = *param_2;
  if (iVar1 != 0) {
    param_2[1] = sUpdateFileSize;
    Q_memcpy(param_2 + 2,sUpdateMD5Hash,0x10);
  }
  else {
    Q_memset(param_2,0,4);
  }
  return iVar1 != 0;
}


// UPDATE_GetUpdateInterval  @ 000c8a5c
longdouble UPDATE_GetUpdateInterval(void)

{
  return (longdouble)sUpdateInterval;
}


// UPDATE_IsActive  @ 000c8a24
undefined4 UPDATE_IsActive(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((sUpdateComState != 0) && (sUpdateComState < 5)) {
    uVar1 = 1;
  }
  return uVar1;
}


// UPDATE_IsMD5Valid  @ 000c82a0
undefined4 UPDATE_IsMD5Valid(void)

{
  undefined4 uVar1;
  
  if (sUpdateComState == 7) {
    uVar1 = 1;
  }
  else if (sUpdateComState == 8) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// UPDATE_ProcessMessage  @ 000c860c
void UPDATE_ProcessMessage(void)

{
  int iVar1;
  longdouble lVar2;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  char local_9;
  undefined4 local_8;
  
  local_14 = 0x42;
  local_13 = 0x4c;
  local_12 = 0x4f;
  local_11 = 0x43;
  local_10 = 0x4b;
  local_f = 0;
  local_1c = 0x46;
  local_1b = 0x49;
  local_1a = 0x4e;
  local_19 = 0x49;
  local_18 = 0x53;
  local_17 = 0x48;
  local_16 = 0;
  local_24 = 0x41;
  local_23 = 0x43;
  local_22 = 0x43;
  local_21 = 0x45;
  local_20 = 0x50;
  local_1f = 0x54;
  local_1e = 0;
  local_2c = 0x46;
  local_2b = 0x49;
  local_2a = 0x4c;
  local_29 = 0x45;
  local_28 = 0;
  local_34 = 0x41;
  local_33 = 0x42;
  local_32 = 0x4f;
  local_31 = 0x52;
  local_30 = 0x54;
  local_2f = 0;
  MSG_BeginReading();
  iVar1 = MSG_ReadLong();
  if (iVar1 == -1) {
    local_9 = MSG_ReadByte();
    iVar1 = MSG_ReadByte();
    if (iVar1 == 0) {
      if (local_9 == 'N') {
        if ((sUpdateComState == 7) && (iVar1 = MSG_ReadLong(), iVar1 == sUpdateChallengeNumber)) {
          iVar1 = MSG_ReadByte();
          if (iVar1 == 0) {
            sUpdateComState = 9;
          }
          else {
            sUpdateComState = 8;
          }
        }
      }
      else if ((local_9 == 'K') && (iVar1 = UPDATE_IsActive(), iVar1 != 0)) {
        sUpdatePacketRetries = 0;
        lVar2 = (longdouble)Sys_FloatTime();
        sUpdateLastSend = (double)((lVar2 + (longdouble)sUpdateResendDelay) - (longdouble)4.0);
        local_8 = MSG_ReadString();
        iVar1 = Q_strncmp(local_8,&local_14,5);
        if (iVar1 == 0) {
          iVar1 = MSG_ReadShort();
          if (sUpdateComState != 3) {
            sUpdateComState = 4;
          }
          MSG_ReadBuf(iVar1,sUpdateFileData + sUpdateBytesReceived);
          COM_UnMunge2(sUpdateFileData + sUpdateBytesReceived,iVar1,sUpdateChallengeNumber);
          sUpdateBytesReceived = sUpdateBytesReceived + iVar1;
        }
        else {
          iVar1 = Q_strncmp(local_8,&local_1c,6);
          if (iVar1 == 0) {
            if (sUpdateComState == 3) {
              sUpdateComState = 6;
            }
          }
          else {
            iVar1 = Q_strncmp(local_8,&local_24,6);
            if (iVar1 == 0) {
              sUpdateChallengeNumber = MSG_ReadLong();
              if (sUpdateComState == 1) {
                sUpdateComState = 2;
              }
            }
            else {
              iVar1 = Q_strncmp(local_8,&local_2c,4);
              if (iVar1 == 0) {
                if (sUpdateComState == 2) {
                  sUpdateComState = 3;
                  sUpdateFileSize = MSG_ReadLong();
                  MSG_ReadBuf(0x10,sUpdateMD5Hash);
                  iVar1 = MSG_ReadLong();
                  sUpdateInterval = (float)iVar1;
                  iVar1 = UPDATE_ReadScrambledIP(sUpdateIPAddress);
                  if (iVar1 == 0) {
                    sUpdateComState = 4;
                  }
                  else if ((((sUpdateCurModule == 0) || (sUpdateNewModule == (undefined4 *)0x0)) ||
                           (sUpdateFileSize != *(int *)(sUpdateCurModule + 4))) ||
                          (iVar1 = Q_memcmp(sUpdateMD5Hash,sUpdateCurModule + 8,0x10), iVar1 != 0))
                  {
                    sUpdateFileData = Mem_Malloc(sUpdateFileSize);
                    if (sUpdateFileData == 0) {
                      sUpdateComState = 4;
                    }
                  }
                  else {
                    sUpdateNewModule[1] = *(undefined4 *)(sUpdateCurModule + 4);
                    Q_memcpy(sUpdateNewModule + 2,sUpdateCurModule + 8,0x10);
                    *sUpdateNewModule = 0;
                    sUpdateComState = 4;
                  }
                }
                else {
                  sUpdateComState = 4;
                }
              }
              else {
                iVar1 = Q_strncmp(local_8,&local_34,5);
                if (iVar1 == 0) {
                  sUpdateComState = 5;
                }
                else {
                  sUpdateComState = 4;
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


// UPDATE_ReadScrambledIP  @ 000c8490
bool UPDATE_ReadScrambledIP(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  byte local_38;
  byte local_37;
  uint local_2c;
  char *local_28 [2];
  undefined1 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_c;
  undefined4 local_8;
  
  local_2c = 0xfa37bc42;
  local_20 = &local_3c;
  local_1c = 0x10;
  local_18 = 0;
  local_28[0] = "UPDATE Temp";
  MSG_StartBitReading(&net_message);
  MSG_StartBitWriting(local_28);
  for (local_c = 0; local_c < 0x30; local_c = local_c + 1) {
    iVar1 = MSG_ReadOneBit();
    local_2c = local_2c + iVar1;
    local_8 = MSG_ReadOneBit();
    MSG_WriteBits(local_8,1);
  }
  MSG_EndBitReading(&net_message);
  MSG_EndBitWriting(local_28);
  *(undefined1 *)(param_1 + 1) = local_3c;
  *(undefined1 *)((int)param_1 + 5) = local_3b;
  *(undefined1 *)((int)param_1 + 6) = local_3a;
  *(undefined1 *)((int)param_1 + 7) = local_39;
  *(ushort *)((int)param_1 + 0x12) = (ushort)local_38 + (ushort)local_37 * 0x100;
  *param_1 = 3;
  uVar2 = MSG_ReadShort();
  iVar1 = (uint)*(ushort *)((int)param_1 + 0x12) + (uint)*(byte *)(param_1 + 1) * 0x10000;
  local_14 = (uint)(iVar1 * iVar1) >> 8 & 0xffff;
  return (local_14 ^ local_2c) == (uVar2 & 0xffff ^ local_2c);
}


// UPDATE_Resend  @ 000c8bac
undefined1 * UPDATE_Resend(void)

{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char **ppcVar6;
  ushort uVar7;
  longdouble lVar8;
  longdouble extraout_ST0;
  char *apcStack_b0 [3];
  int iStack_a4;
  undefined4 uStack_a0;
  char local_5c [31];
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
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
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
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
  int local_8;
  
  local_8 = 0;
  local_14 = 0x43;
  local_13 = 0x48;
  local_12 = 0x41;
  local_11 = 0x4c;
  local_10 = 0x4c;
  local_f = 0x45;
  local_e = 0x4e;
  local_d = 0x47;
  local_c = 0x45;
  local_b = 0;
  local_18 = 0x47;
  local_17 = 0x45;
  local_16 = 0x54;
  local_15 = 0;
  local_20 = 0x4e;
  local_1f = 0x45;
  local_1e = 0x58;
  local_1d = 0x54;
  local_1c = 0;
  local_28 = 0x41;
  local_27 = 0x42;
  local_26 = 0x4f;
  local_25 = 0x52;
  local_24 = 0x54;
  local_23 = 0;
  local_34 = 0x2d;
  local_33 = 0x74;
  local_32 = 0x65;
  local_31 = 0x73;
  local_30 = 0x74;
  local_2f = 0x6d;
  local_2e = 0x6f;
  local_2d = 100;
  local_2c = 0x75;
  local_2b = 0x6c;
  local_2a = 0x65;
  local_29 = 0;
  puVar4 = &local_3c;
  local_3c = 0x70;
  local_3b = 0x72;
  local_3a = 0x69;
  local_39 = 0x76;
  local_38 = 0x61;
  local_37 = 0x74;
  local_36 = 0x65;
  local_35 = 0;
  if (sUpdateMasterAdr != (undefined4 *)0x0) {
    uStack_a0 = 0xc8ca5;
    iVar3 = UPDATE_IsActive();
    if (iVar3 == 0) {
      puVar4 = (undefined1 *)0x0;
    }
    else {
      dVar2 = sUpdateLastSend + 4.0;
      uStack_a0 = 0xc8cca;
      lVar8 = (longdouble)Sys_FloatTime();
      dVar1 = (double)lVar8;
      uVar7 = (ushort)(dVar2 < dVar1) << 8 | (ushort)(NAN(dVar2) || NAN(dVar1)) << 10 |
              (ushort)(dVar2 == dVar1) << 0xe;
      puVar4 = (undefined1 *)(uint)uVar7;
      if ((char)(uVar7 >> 8) != '\0') {
        if (sUpdatePacketRetries < 9) {
          apcStack_b0[1] = (char *)&net_message;
          apcStack_b0[0] = (char *)0xc8d09;
          SZ_Clear();
          apcStack_b0[2] = (char *)0xffffffff;
          apcStack_b0[1] = (char *)&net_message;
          apcStack_b0[0] = (char *)0xc8d1f;
          MSG_WriteLong();
          apcStack_b0[2] = (char *)0x4a;
          apcStack_b0[1] = (char *)&net_message;
          apcStack_b0[0] = (char *)0xc8d35;
          MSG_WriteByte();
          apcStack_b0[2] = (undefined1 *)0x0;
          apcStack_b0[1] = (char *)&net_message;
          apcStack_b0[0] = (char *)0xc8d4b;
          MSG_WriteByte();
          switch(sUpdateComState) {
          case 1:
            apcStack_b0[2] = &local_14;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8d95;
            MSG_WriteString();
            break;
          case 2:
            apcStack_b0[2] = &local_18;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8db5;
            MSG_WriteString();
            apcStack_b0[2] = (char *)sUpdateChallengeNumber;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8dd0;
            MSG_WriteLong();
            apcStack_b0[2] = (char *)sUpdateName;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8deb;
            MSG_WriteString();
            apcStack_b0[2] = (char *)0x43210004;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8e04;
            MSG_WriteLong();
            apcStack_b0[1] = &local_34;
            apcStack_b0[0] = (char *)0xc8e13;
            local_8 = COM_CheckParm();
            if ((local_8 == 0) || (com_argc + -1 <= local_8)) {
              apcStack_b0[2] = (char *)0x0;
              apcStack_b0[1] = (char *)&net_message;
              apcStack_b0[0] = (char *)0xc8e9b;
              MSG_WriteByte();
            }
            else {
              apcStack_b0[1] = *(char **)(local_8 * 4 + com_argv + 4);
              apcStack_b0[0] = &local_3c;
              snprintf(local_5c,0x1f,"\\%s\\%s");
              local_3d = 0;
              apcStack_b0[2] = local_5c;
              apcStack_b0[1] = (char *)&net_message;
              apcStack_b0[0] = (char *)0xc8e80;
              MSG_WriteString();
            }
            if (sUpdateCurModule == 0) {
              apcStack_b0[0] = (char *)0xfffffff;
              apcStack_b0[2] = (char *)RandomLong(0);
              apcStack_b0[1] = (char *)&net_message;
              apcStack_b0[0] = (char *)0xc8ef2;
              MSG_WriteLong();
              apcStack_b0[0] = (char *)0xfffffff;
              apcStack_b0[2] = (char *)RandomLong(0);
              apcStack_b0[1] = (char *)&net_message;
              apcStack_b0[0] = (char *)0xc8f1b;
              MSG_WriteLong();
              apcStack_b0[0] = (char *)0xfffffff;
              apcStack_b0[2] = (char *)RandomLong(0);
              apcStack_b0[1] = (char *)&net_message;
              apcStack_b0[0] = (char *)0xc8f44;
              MSG_WriteLong();
              apcStack_b0[0] = (char *)0xfffffff;
              apcStack_b0[2] = (char *)RandomLong(0);
              apcStack_b0[1] = (char *)&net_message;
              apcStack_b0[0] = (char *)0xc8f6d;
              MSG_WriteLong();
            }
            else {
              iStack_a4 = sUpdateCurModule + 8;
              apcStack_b0[2] = (undefined1 *)0x10;
              apcStack_b0[1] = (char *)&net_message;
              apcStack_b0[0] = (char *)0xc8ec4;
              MSG_WriteBuf();
            }
            break;
          case 3:
            apcStack_b0[2] = &local_20;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8f8d;
            MSG_WriteString();
            apcStack_b0[2] = (char *)sUpdateBytesReceived;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8fa8;
            MSG_WriteLong();
            apcStack_b0[2] = (undefined1 *)0x0;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8fbe;
            MSG_WriteByte();
            break;
          case 4:
            apcStack_b0[2] = &local_28;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8fd9;
            MSG_WriteString();
            apcStack_b0[2] = (undefined1 *)0x0;
            apcStack_b0[1] = (char *)&net_message;
            apcStack_b0[0] = (char *)0xc8fef;
            MSG_WriteLong();
            sUpdateComState = 5;
          }
          puVar5 = sUpdateMasterAdr;
          ppcVar6 = apcStack_b0;
          for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
            *ppcVar6 = (char *)*puVar5;
            puVar5 = puVar5 + 1;
            ppcVar6 = ppcVar6 + 1;
          }
          NET_SendPacket(1,DAT_0059d8d0,DAT_0059d8c8);
          apcStack_b0[1] = (char *)&net_message;
          apcStack_b0[0] = (char *)0xc9048;
          SZ_Clear();
          uStack_a0 = 0xc9050;
          puVar4 = (undefined1 *)Sys_FloatTime();
          sUpdateLastSend = (double)extraout_ST0;
          sUpdatePacketRetries = sUpdatePacketRetries + 1;
        }
        else {
          sUpdateComState = 5;
        }
      }
    }
  }
  return puVar4;
}


// UPDATE_RotateList  @ 000c7c40
void UPDATE_RotateList(void)

{
  int local_c;
  int local_8;
  
  if ((sUpdateMasterAdr != 0) && (*(int *)(sUpdateMasterAdr + 0x14) != 0)) {
    local_c = sUpdateMasterAdr;
    for (local_8 = *(int *)(sUpdateMasterAdr + 0x14); *(int *)(local_8 + 0x14) != 0;
        local_8 = *(int *)(local_8 + 0x14)) {
      local_c = local_8;
    }
    *(undefined4 *)(local_c + 0x14) = *(undefined4 *)(local_8 + 0x14);
    *(int *)(local_8 + 0x14) = sUpdateMasterAdr;
    sUpdateMasterAdr = local_8;
  }
  return;
}


// UPDATE_UpdateAddressList  @ 000c81f4
void UPDATE_UpdateAddressList(void)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (sUpdateMasterAdr == 0) {
    UPDATE_BuildServerList();
  }
  for (local_c = sUpdateMasterAdr; local_c != 0; local_c = *(int *)(local_c + 0x14)) {
    local_8 = local_8 + 1;
  }
  if ((1 < local_8) && (iVar1 = RandomLong(0,0x32), 0 < iVar1)) {
    for (local_10 = 0; local_10 < iVar1; local_10 = local_10 + 1) {
      UPDATE_RotateList();
    }
  }
  return;
}


// UPDATE_VerifyMD5  @ 000c82dc
void UPDATE_VerifyMD5(int param_1)

{
  double dVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  longdouble lVar5;
  longdouble lVar6;
  undefined4 *apuStack_70 [2];
  int iStack_68;
  undefined1 *puStack_64;
  undefined4 uStack_60;
  char *local_38;
  undefined2 local_34;
  undefined1 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [32];
  
  uStack_60 = 0xc82ea;
  if (param_1 != 0) {
    puStack_64 = (undefined1 *)0x10;
    iStack_68 = param_1;
    apuStack_70[1] = (undefined4 *)sUpdateMD5Hash;
    apuStack_70[0] = (undefined4 *)0xc830e;
    Q_memcpy();
    iStack_68 = 0xfffffff;
    apuStack_70[1] = (undefined4 *)0x0;
    apuStack_70[0] = (undefined4 *)0xc8320;
    sUpdateChallengeNumber = RandomLong();
    sUpdatePacketRetries = 0;
    sUpdateLastSend = -9999.0;
    sUpdateComState = 7;
    uStack_60 = 0xc834e;
    UPDATE_UpdateAddressList();
  }
  if (sUpdateComState == 7) {
    if (sUpdateMasterAdr == (undefined4 *)0x0) {
      sUpdateComState = 9;
    }
    else {
      dVar1 = sUpdateLastSend + 2.0;
      uStack_60 = 0xc838a;
      lVar5 = (longdouble)Sys_FloatTime();
      lVar6 = (longdouble)dVar1;
      if ((byte)(lVar5 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar6)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar5 == lVar6) << 0xe) >> 8)) != 1) {
        if (sUpdatePacketRetries < 9) {
          local_38 = "CL_ISMV";
          local_2c = 0x20;
          local_28 = 0;
          local_34 = 0;
          local_30 = local_24;
          apuStack_70[1] = &local_38;
          apuStack_70[0] = (undefined4 *)0xc83e5;
          SZ_Clear();
          iStack_68 = 0xffffffff;
          apuStack_70[1] = &local_38;
          apuStack_70[0] = (undefined4 *)0xc83f6;
          MSG_WriteLong();
          iStack_68 = 0x4d;
          apuStack_70[1] = &local_38;
          apuStack_70[0] = (undefined4 *)0xc8407;
          MSG_WriteByte();
          iStack_68 = 0;
          apuStack_70[1] = &local_38;
          apuStack_70[0] = (undefined4 *)0xc8418;
          MSG_WriteByte();
          iStack_68 = sUpdateChallengeNumber;
          apuStack_70[1] = &local_38;
          apuStack_70[0] = (undefined4 *)0xc842e;
          MSG_WriteLong();
          puStack_64 = sUpdateMD5Hash;
          iStack_68 = 0x10;
          apuStack_70[1] = &local_38;
          apuStack_70[0] = (undefined4 *)0xc8448;
          MSG_WriteBuf();
          puVar3 = sUpdateMasterAdr;
          ppuVar4 = apuStack_70;
          for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
            *ppuVar4 = (undefined4 *)*puVar3;
            puVar3 = puVar3 + 1;
            ppuVar4 = ppuVar4 + 1;
          }
          NET_SendPacket(0,local_28,local_30);
          uStack_60 = 0xc8477;
          lVar6 = (longdouble)Sys_FloatTime();
          sUpdateLastSend = (double)lVar6;
          sUpdatePacketRetries = sUpdatePacketRetries + 1;
        }
        else {
          sUpdateComState = 9;
        }
      }
    }
  }
  return;
}


