// SVC_GetChallenge  @ 08072e90
void SVC_GetChallenge(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char **ppcVar6;
  undefined4 auStackY_d4 [3];
  char *apcStack_c0 [5];
  int local_98;
  int local_94;
  char local_84 [21];
  undefined4 local_6f;
  undefined1 uStack_6b;
  
  local_94 = 0;
  local_98 = 0x7fffffff;
  iVar3 = 0;
  do {
    puVar4 = &DAT_08166d10 + iVar3 * 7;
    ppcVar6 = apcStack_c0;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar6 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar6 = ppcVar6 + 1;
    }
    puVar4 = &net_from;
    puVar5 = auStackY_d4;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar2 = NET_CompareBaseAdr();
    if (iVar2 != 0) break;
    if (*(int *)(&DAT_08166d28 + iVar3 * 0x1c) < local_98) {
      local_98 = *(int *)(&DAT_08166d28 + iVar3 * 0x1c);
      local_94 = iVar3;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x400);
  if (iVar3 == 0x400) {
    apcStack_c0[4] = (char *)0xffff;
    apcStack_c0[3] = (char *)0x0;
    apcStack_c0[2] = (char *)0x8072f3f;
    iVar3 = RandomLong();
    apcStack_c0[2] = (char *)0xffff;
    apcStack_c0[1] = (char *)0x0;
    apcStack_c0[0] = (char *)0x8072f4d;
    uVar1 = RandomLong();
    *(uint *)(&DAT_08166d24 + local_94 * 0x1c) = iVar3 << 0x10 | uVar1;
    puVar4 = &net_from;
    puVar5 = &DAT_08166d10 + local_94 * 7;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(int *)(&DAT_08166d28 + local_94 * 0x1c) = (int)ROUND(realtime);
    iVar3 = local_94;
  }
  apcStack_c0[4] = (char *)0x41;
  apcStack_c0[3] = (char *)0xff;
  apcStack_c0[2] = (char *)0xff;
  apcStack_c0[1] = (char *)0xff;
  apcStack_c0[0] = (char *)0xff;
  auStackY_d4[2] = 0x8072ff6;
  sprintf(local_84,"%c%c%c%c%c0000000000000000");
  auStackY_d4[2] = *(undefined4 *)(&DAT_08166d24 + iVar3 * 0x1c);
  auStackY_d4[1] = 0x807300e;
  local_6f = (*BigLong)();
  if (((sv == 0) || (svs < 2)) ||
     ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    gfUseLANAuthentication = 1;
  }
  else {
    apcStack_c0[4] = (char *)0x8073044;
    COM_CheckAuthenticationType();
  }
  if (gfUseLANAuthentication == 0) {
    apcStack_c0[4] = "Server requiring WON authentication\n";
    apcStack_c0[3] = (char *)0x807307a;
    Con_DPrintf();
    uStack_6b = 1;
  }
  else {
    apcStack_c0[4] = "Server requiring authentication\n";
    apcStack_c0[3] = (char *)0x8073063;
    Con_DPrintf();
    uStack_6b = 2;
  }
  puVar4 = &net_from;
  ppcVar6 = apcStack_c0;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppcVar6 = (char *)*puVar4;
    puVar4 = puVar4 + 1;
    ppcVar6 = ppcVar6 + 1;
  }
  auStackY_d4[2] = 1;
  auStackY_d4[1] = 0x80730a1;
  NET_SendPacket();
  return;
}


// SVC_Heartbeat  @ 08073750
void SVC_Heartbeat(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 *puVar6;
  undefined4 auStack_38 [5];
  undefined4 *apuStack_24 [5];
  
  if ((valvemaster_adr != (undefined4 *)0x0) &&
     (puVar3 = valvemaster_adr, valvemaster_adr != (undefined4 *)0x0)) {
    do {
      puVar4 = &net_from;
      ppuVar5 = apuStack_24;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppuVar5 = (undefined4 *)*puVar4;
        puVar4 = puVar4 + 1;
        ppuVar5 = ppuVar5 + 1;
      }
      puVar4 = puVar3 + 6;
      puVar6 = auStack_38;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      iVar2 = NET_CompareAdr();
    } while ((iVar2 == 0) && (puVar3 = (undefined4 *)puVar3[0xb], puVar3 != (undefined4 *)0x0));
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      apuStack_24[4] = (undefined4 *)0x80737b0;
      uVar1 = MSG_ReadLong();
      puVar3[2] = uVar1;
      apuStack_24[3] = (undefined4 *)0x80737b9;
      apuStack_24[4] = puVar3;
      Master_RequestHeartbeat();
    }
  }
  return;
}


// SVC_Info  @ 080731a0
void SVC_Info(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int **ppiVar6;
  int *apiStack_af0 [2];
  undefined4 **ppuStack_ae8;
  int local_ac8;
  int local_ac4;
  int local_ac0;
  int *local_abc;
  undefined4 local_ab8;
  undefined1 local_ab4 [32];
  int local_a94 [65];
  int local_990 [128];
  undefined1 local_790 [512];
  undefined1 local_590 [1400];
  int local_18 [2];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x578;
  local_8 = 0;
  local_10 = local_590;
  if ((sv != 0) && (1 < (int)svs)) {
    local_ac8 = 0;
    if (0 < (int)svs) {
      iVar3 = 0;
      do {
        if (*(int *)(DAT_0816dd10 + iVar3 * 0x52b8) != 0) {
          local_ac8 = local_ac8 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)svs);
    }
    ppuStack_ae8 = (undefined4 **)0x8073230;
    MSG_WriteLong();
    ppuStack_ae8 = (undefined4 **)0x807324b;
    MSG_WriteByte();
    if (noip == 0) {
      puVar4 = &net_local_adr;
      ppiVar6 = apiStack_af0;
      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppiVar6 = (int *)*puVar4;
        puVar4 = puVar4 + 1;
        ppiVar6 = ppiVar6 + 1;
      }
      uVar2 = NET_AdrToString();
      MSG_WriteString(local_18,uVar2);
    }
    else {
      ppuStack_ae8 = (undefined4 **)0x807328e;
      MSG_WriteString();
    }
    ppuStack_ae8 = (undefined4 **)0x80732a0;
    MSG_WriteString();
    ppuStack_ae8 = (undefined4 **)&DAT_0811d260;
    apiStack_af0[0] = (int *)0x80732ab;
    apiStack_af0[1] = local_18;
    MSG_WriteString();
    apiStack_af0[0] = local_a94;
    COM_FileBase(com_gamedir);
    MSG_WriteString(local_18,local_a94);
    (*DAT_08178f0c)();
    ppuStack_ae8 = (undefined4 **)0x80732d7;
    MSG_WriteString();
    ppuStack_ae8 = (undefined4 **)local_ac8;
    apiStack_af0[0] = (int *)0x80732e4;
    apiStack_af0[1] = local_18;
    MSG_WriteByte();
    apiStack_af0[0] = svs;
    MSG_WriteByte(local_18);
    MSG_WriteByte(local_18,PROTOCOL_VERSION);
    if (param_1 != 0) {
      ppuStack_ae8 = (undefined4 **)0x807332b;
      MSG_WriteByte();
      ppuStack_ae8 = (undefined4 **)0x8073339;
      MSG_WriteByte();
      iVar3 = -1;
      pcVar5 = (char *)sv_password._4_4_;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (iVar3 != -2) {
        ppuStack_ae8 = (undefined4 **)0x807335e;
        strcasecmp((char *)sv_password._4_4_,"none");
      }
      ppuStack_ae8 = (undefined4 **)0x807337b;
      MSG_WriteByte();
      ppuStack_ae8 = &local_abc;
      apiStack_af0[1] = &local_ac0;
      apiStack_af0[0] = &local_ac4;
      iVar3 = SV_GetModInfo(local_790,local_990);
      if (iVar3 == 0) {
        ppuStack_ae8 = (undefined4 **)0x807343b;
        MSG_WriteByte();
      }
      else {
        ppuStack_ae8 = (undefined4 **)0x80733ce;
        MSG_WriteByte();
        apiStack_af0[0] = (int *)0x80733d5;
        apiStack_af0[1] = local_18;
        ppuStack_ae8 = (undefined4 **)local_790;
        MSG_WriteString();
        apiStack_af0[0] = local_990;
        MSG_WriteString(local_18);
        MSG_WriteString(local_18,local_ab4);
        ppuStack_ae8 = (undefined4 **)0x80733f9;
        MSG_WriteLong();
        ppuStack_ae8 = (undefined4 **)local_ac0;
        apiStack_af0[0] = (int *)0x8073406;
        apiStack_af0[1] = local_18;
        MSG_WriteLong();
        apiStack_af0[0] = local_abc;
        MSG_WriteByte(local_18);
        MSG_WriteByte(local_18,local_ab8);
      }
    }
    puVar4 = &net_from;
    ppiVar6 = apiStack_af0;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppiVar6 = (int *)*puVar4;
      puVar4 = puVar4 + 1;
      ppiVar6 = ppiVar6 + 1;
    }
    NET_SendPacket(1,local_8,local_10);
  }
  return;
}


// SVC_Ping  @ 08072e30
void SVC_Ping(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_28 [5];
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  
  local_c = 0xff;
  local_b = 0xff;
  local_a = 0xff;
  local_9 = 0xff;
  local_8 = 0x6a;
  local_7 = 0;
  puVar2 = &net_from;
  puVar3 = auStack_28;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  NET_SendPacket(1,6,&local_c);
  return;
}


// SVC_PlayerInfo  @ 08073470
void SVC_PlayerInfo(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iStack_84c;
  undefined1 *puStack_848;
  int iStack_844;
  undefined1 *puStack_840;
  int iStack_83c;
  int local_82c;
  undefined1 local_818 [2048];
  undefined1 local_18 [8];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x800;
  local_8 = 0;
  local_10 = local_818;
  if ((sv != 0) && (1 < svs)) {
    iStack_83c = 0xffffffff;
    iStack_844 = 0x80734b8;
    puStack_840 = local_18;
    MSG_WriteLong();
    iStack_844 = 0x44;
    iStack_84c = 0x80734c0;
    puStack_848 = local_18;
    MSG_WriteByte();
    local_82c = 0;
    iVar1 = 0;
    if (0 < svs) {
      do {
        if (*(int *)(DAT_0816dd10 + iVar1 * 0x52b8) != 0) {
          local_82c = local_82c + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < svs);
    }
    iStack_83c = local_82c;
    puStack_840 = local_18;
    iStack_844 = 0x8073515;
    MSG_WriteByte();
    local_82c = 0;
    iVar1 = 0;
    if (0 < svs) {
      iVar2 = DAT_0816dd10;
      do {
        if (*(int *)(DAT_0816dd10 + iVar1 * 0x52b8) != 0) {
          local_82c = local_82c + 1;
          iStack_844 = 0x807356f;
          puStack_840 = local_18;
          iStack_83c = local_82c;
          MSG_WriteByte();
          iStack_844 = iVar2 + 0x5005;
          iStack_84c = 0x807357c;
          puStack_848 = local_18;
          MSG_WriteString();
          iStack_84c = (int)ROUND(*(float *)(*(int *)(iVar2 + 0x4f08) + 0x220));
          MSG_WriteLong(local_18);
          MSG_WriteFloat(local_18,(float)realtime - *(float *)(iVar2 + 0x34));
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x52b8;
      } while (iVar1 < svs);
    }
    puVar3 = &net_from;
    piVar4 = &iStack_84c;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    NET_SendPacket(1,local_8,local_10);
  }
  return;
}


// SVC_RuleInfo  @ 08073620
void SVC_RuleInfo(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int *piVar6;
  int iStack_83c;
  undefined1 *puStack_838;
  undefined4 uStack_834;
  undefined1 local_818 [2048];
  undefined1 local_18 [8];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x800;
  local_8 = 0;
  local_10 = local_818;
  if (((sv != 0) && (1 < svs)) && (iVar2 = Cvar_CountServerVariables(), 0 < iVar2)) {
    uStack_834 = 0x8073677;
    MSG_WriteLong();
    uStack_834 = 0x45;
    iStack_83c = 0x807367f;
    puStack_838 = local_18;
    MSG_WriteByte();
    iStack_83c = iVar2;
    MSG_WriteShort(local_18);
    for (iVar2 = cvar_vars; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
      if ((*(byte *)(iVar2 + 8) & 4) != 0) {
        uStack_834 = 0x80736b2;
        MSG_WriteString();
        if ((*(byte *)(iVar2 + 8) & 0x20) != 0) {
          iVar3 = -1;
          pcVar5 = *(char **)(iVar2 + 4);
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          if (iVar3 != -2) {
            uStack_834 = 0x80736db;
            strcasecmp(*(char **)(iVar2 + 4),"none");
          }
        }
        uStack_834 = 0x8073710;
        MSG_WriteString();
      }
    }
    puVar4 = &net_from;
    piVar6 = &iStack_83c;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      piVar6 = piVar6 + 1;
    }
    NET_SendPacket(1,local_8,local_10);
  }
  return;
}


// SVC_Status  @ 08072e80
void SVC_Status(void)

{
  return;
}


