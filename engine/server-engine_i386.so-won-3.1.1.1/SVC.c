// SVC_GameDllQuery  @ 000a2f84
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SVC_GameDllQuery(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  int *apiStack_840 [5];
  undefined4 local_80c;
  undefined1 local_808 [2044];
  int local_c;
  int local_8;
  
  apiStack_840[4] = (int *)0xa2f95;
  local_c = 0x800;
  if (sv == 0) {
    uVar1 = 0;
  }
  else if (DAT_00524288 < 2) {
    uVar1 = 0;
  }
  else {
    apiStack_840[3] = (int *)0x800;
    apiStack_840[2] = (int *)0x0;
    apiStack_840[1] = &local_80c;
    apiStack_840[0] = (int *)0xa2fe1;
    Q_memset();
    local_8 = local_c + -4;
    apiStack_840[4] = &local_8;
    apiStack_840[3] = (int *)local_808;
    apiStack_840[2] = (int *)param_1;
    apiStack_840[1] = &net_from;
    apiStack_840[0] = (int *)0xa3016;
    uVar1 = (*_DAT_0036aff4)();
    if ((local_8 != 0) && (local_8 <= local_c + -4)) {
      local_80c = 0xffffffff;
      puVar3 = &net_from;
      ppiVar4 = apiStack_840;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppiVar4 = (int *)*puVar3;
        puVar3 = puVar3 + 1;
        ppiVar4 = ppiVar4 + 1;
      }
      NET_SendPacket(1,local_8 + 4,&local_80c);
    }
  }
  return uVar1;
}


// SVC_GetChallenge  @ 000a14c4
void SVC_GetChallenge(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint **ppuVar6;
  ushort in_FPUControlWord;
  int iStack_468;
  char *pcStack_464;
  uint *puStack_460;
  char **ppcStack_45c;
  char *pcStack_458;
  char *pcStack_454;
  undefined4 uStack_450;
  char *local_428 [2];
  ushort local_420;
  int local_41c;
  int local_418;
  char *local_414;
  char local_410 [1024];
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0x7fffffff;
  local_418 = 0;
  local_41c = 0;
  uStack_450 = 0xa1503;
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    pcStack_458 = "steam";
    iStack_468 = 1;
    ppcStack_45c = (char **)Cmd_Argv();
    puStack_460 = (uint *)0xa152b;
    iVar1 = Q_stricmp();
    if (iVar1 == 0) {
      local_418 = 1;
    }
  }
  uStack_450 = 0xa1543;
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    pcStack_458 = "valve";
    iStack_468 = 1;
    ppcStack_45c = (char **)Cmd_Argv();
    puStack_460 = (uint *)0xa156b;
    iVar1 = Q_stricmp();
    if (iVar1 == 0) {
      local_41c = 1;
    }
  }
  for (local_8 = 0; local_8 < 0x400; local_8 = local_8 + 1) {
    puVar3 = (undefined4 *)(g_rg_sv_challenges + local_8 * 0x1c);
    piVar4 = &iStack_468;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    puVar3 = &net_from;
    puVar5 = (undefined4 *)&stack0xfffffb84;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar1 = NET_CompareBaseAdr();
    if (iVar1 != 0) break;
    if (*(int *)(g_rg_sv_challenges + local_8 * 0x1c + 0x18) < local_10) {
      local_10 = *(int *)(g_rg_sv_challenges + local_8 * 0x1c + 0x18);
      local_c = local_8;
    }
  }
  if (local_8 == 0x400) {
    pcStack_458 = (char *)0xffff;
    ppcStack_45c = (char **)0x0;
    puStack_460 = (uint *)0xa1660;
    iVar1 = RandomLong();
    pcStack_458 = (char *)0xffff;
    ppcStack_45c = (char **)0x0;
    puStack_460 = (uint *)0xa1674;
    uVar2 = RandomLong();
    *(uint *)(g_rg_sv_challenges + local_c * 0x1c + 0x14) = iVar1 << 0x10 | uVar2;
    puVar3 = &net_from;
    puVar5 = (undefined4 *)(g_rg_sv_challenges + local_c * 0x1c);
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    local_420 = in_FPUControlWord | 0xc00;
    *(int *)(g_rg_sv_challenges + local_c * 0x1c + 0x18) = (int)ROUND(realtime);
    local_8 = local_c;
  }
  if ((sv == 0) || (DAT_00524288 < 2)) {
    gfUseLANAuthentication = 1;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
    uStack_450 = 0xa175c;
    COM_CheckAuthenticationType();
  }
  else {
    gfUseLANAuthentication = 1;
  }
  if ((local_418 == 0) && (local_41c == 0)) {
    local_414 = (char *)0x0;
    if (gfUseLANAuthentication == 0) {
      ppcStack_45c = (char **)0xe97e0;
      puStack_460 = (uint *)0xa1975;
      Con_DPrintf();
      local_414 = (char *)0x1;
    }
    else {
      ppcStack_45c = (char **)0xe97a0;
      puStack_460 = (uint *)0xa1952;
      Con_DPrintf();
      local_414 = (char *)0x2;
    }
    pcStack_458 = local_414;
    ppcStack_45c = *(char ***)(g_rg_sv_challenges + local_8 * 0x1c + 0x14);
    puStack_460 = (uint *)0x41;
    pcStack_464 = (char *)0xff;
    iStack_468 = 0xff;
    snprintf(local_410,0x400,"%c%c%c%c%c00000000 %u %i\n");
  }
  else {
    ppcStack_45c = local_428;
    puStack_460 = (uint *)0xa17ad;
    iVar1 = SteamGetEncryptionKeyToSendToNewClient();
    if (iVar1 == 0) {
      ppcStack_45c = (char **)0xe96a0;
      puStack_460 = (uint *)0xa17d2;
      Sys_Error();
    }
    if ((char *)0x320 < local_428[0]) {
      pcStack_454 = (char *)0x320;
      pcStack_458 = local_428[0];
      ppcStack_45c = (char **)0xe96e0;
      puStack_460 = (uint *)0xa17fe;
      Sys_Error();
    }
    ppcStack_45c = (char **)0xe9740;
    puStack_460 = (uint *)0xa1812;
    Con_DPrintf();
    if (local_418 == 0) {
      if (local_41c != 0) {
        pcStack_458 = local_428[0];
        puStack_460 = (uint *)0xa18c3;
        ppcStack_45c = (char **)iVar1;
        uStack_450 = COM_BinPrintf();
        pcStack_454 = local_428[0];
        pcStack_458 = (char *)0x4;
        ppcStack_45c = *(char ***)(g_rg_sv_challenges + local_8 * 0x1c + 0x14);
        puStack_460 = (uint *)0x41;
        pcStack_464 = (char *)0xff;
        iStack_468 = 0xff;
        snprintf(local_410,0x400,"%c%c%c%c%c00000000 %u %i %u %s\n");
      }
    }
    else {
      pcStack_458 = local_428[0];
      puStack_460 = (uint *)0xa1838;
      ppcStack_45c = (char **)iVar1;
      uStack_450 = COM_BinPrintf();
      pcStack_454 = local_428[0];
      pcStack_458 = (char *)0x3;
      ppcStack_45c = *(char ***)(g_rg_sv_challenges + local_8 * 0x1c + 0x14);
      puStack_460 = (uint *)0x41;
      pcStack_464 = (char *)0xff;
      iStack_468 = 0xff;
      snprintf(local_410,0x400,"%c%c%c%c%c00000000 %u %i %u %s\n");
    }
  }
  puVar3 = &net_from;
  ppuVar6 = &puStack_460;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar6 = (uint *)*puVar3;
    puVar3 = puVar3 + 1;
    ppuVar6 = ppuVar6 + 1;
  }
  pcStack_464 = local_410;
  iStack_468 = Q_strlen();
  iStack_468 = iStack_468 + 1;
  NET_SendPacket();
  return;
}


// SVC_Heartbeat  @ 000a2ec8
void SVC_Heartbeat(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 auStack_4c [5];
  undefined4 *apuStack_38 [6];
  undefined4 uStack_20;
  undefined4 *local_8;
  
  uStack_20 = 0xa2ed6;
  if (valvemaster_adr != (undefined4 *)0x0) {
    for (local_8 = valvemaster_adr; local_8 != (undefined4 *)0x0;
        local_8 = (undefined4 *)local_8[0xb]) {
      puVar3 = &net_from;
      ppuVar4 = apuStack_38;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppuVar4 = (undefined4 *)*puVar3;
        puVar3 = puVar3 + 1;
        ppuVar4 = ppuVar4 + 1;
      }
      puVar3 = local_8 + 6;
      puVar5 = auStack_4c;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar2 = NET_CompareAdr();
      if (iVar2 != 0) break;
    }
    if (local_8 != (undefined4 *)0x0) {
      *local_8 = 0;
      uStack_20 = 0xa2f62;
      uVar1 = MSG_ReadLong();
      local_8[2] = uVar1;
      apuStack_38[3] = local_8;
      apuStack_38[2] = (undefined4 *)0xa2f76;
      Master_RequestHeartbeat();
    }
  }
  return;
}


// SVC_Info  @ 000a25a0
void SVC_Info(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  char *apcStack_b24 [5];
  char *pcStack_b10;
  char **ppcStack_b0c;
  char *pcStack_b08;
  undefined1 *puStack_b04;
  undefined4 uStack_b00;
  int local_ad4;
  undefined1 local_ad0 [32];
  undefined4 local_ab0;
  undefined4 local_aac;
  undefined1 local_aa8 [260];
  int local_9a4;
  undefined4 local_9a0;
  undefined4 local_99c;
  undefined1 local_998 [512];
  undefined1 local_798 [512];
  undefined1 local_598 [1400];
  char *local_20;
  undefined2 local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  uStack_b00 = 0xa25b1;
  local_20 = "SVC_Info";
  local_14 = 0x578;
  local_10 = 0;
  local_18 = local_598;
  local_1c = 1;
  if (sv == 0) {
    return;
  }
  if (DAT_00524288 < 2) {
    return;
  }
  local_c = 0;
  for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
    if (((*(int *)(DAT_00524284 + local_8 * 0x4eec) != 0) ||
        (*(int *)(DAT_00524284 + 4 + local_8 * 0x4eec) != 0)) ||
       (*(int *)(DAT_00524284 + 0xc + local_8 * 0x4eec) != 0)) {
      local_c = local_c + 1;
    }
  }
  pcStack_b08 = (char *)0xffffffff;
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa26e2;
  MSG_WriteLong();
  if (param_1 == 0) {
    pcStack_b08 = (char *)0x43;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa270e;
    MSG_WriteByte();
  }
  else {
    pcStack_b08 = (char *)0x6d;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa26f9;
    MSG_WriteByte();
  }
  if (noip == 0) {
    puVar2 = &net_local_adr;
    ppcVar3 = apcStack_b24;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar3 = (char *)*puVar2;
      puVar2 = puVar2 + 1;
      ppcVar3 = ppcVar3 + 1;
    }
    pcStack_b08 = (char *)NET_AdrToString();
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa274b;
    MSG_WriteString();
  }
  else {
    pcStack_b08 = "LOOPBACK";
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa2765;
    MSG_WriteString();
  }
  apcStack_b24[4] = "hostname";
  apcStack_b24[3] = (char *)0xa277c;
  pcStack_b08 = (char *)Cvar_VariableString();
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa278b;
  MSG_WriteString();
  pcStack_b08 = &DAT_0036bc88;
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa27a4;
  MSG_WriteString();
  pcStack_b08 = local_aa8;
  ppcStack_b0c = (char **)&com_gamedir;
  pcStack_b10 = (char *)0xa27bf;
  COM_FileBase();
  pcStack_b08 = local_aa8;
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa27d5;
  MSG_WriteString();
  pcStack_b08 = (char *)0xa27e6;
  pcStack_b08 = (char *)(*DAT_0036afb0)();
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa27f2;
  MSG_WriteString();
  pcStack_b08 = (char *)local_c;
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa2805;
  MSG_WriteByte();
  local_ad4 = (int)ROUND((float)sv_visiblemaxplayers._12_4_);
  if (local_ad4 < 0) {
    local_ad4 = DAT_00524288;
  }
  pcStack_b08 = (char *)local_ad4;
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa2866;
  MSG_WriteByte();
  pcStack_b08 = (char *)0x2e;
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa2877;
  MSG_WriteByte();
  if (param_1 == 0) goto LAB_000a2a5d;
  if (cls == 0) {
    pcStack_b08 = (char *)0x64;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa289d;
    MSG_WriteByte();
  }
  else {
    pcStack_b08 = (char *)0x6c;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa28b2;
    MSG_WriteByte();
  }
  pcStack_b08 = (char *)0x6c;
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa28c3;
  MSG_WriteByte();
  ppcStack_b0c = (char **)sv_password._4_4_;
  pcStack_b10 = (char *)0xa28d8;
  iVar1 = Q_strlen();
  if (iVar1 < 1) {
LAB_000a2918:
    pcStack_b08 = (char *)0x0;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa2926;
    MSG_WriteByte();
  }
  else {
    pcStack_b08 = &DAT_000e9480;
    ppcStack_b0c = (char **)sv_password._4_4_;
    pcStack_b10 = (char *)0xa28fc;
    iVar1 = Q_stricmp();
    if (iVar1 == 0) goto LAB_000a2918;
    pcStack_b08 = (char *)0x1;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa2913;
    MSG_WriteByte();
  }
  puStack_b04 = local_ad0;
  pcStack_b08 = (char *)&local_aac;
  ppcStack_b0c = (char **)&local_ab0;
  pcStack_b10 = (char *)&local_9a0;
  apcStack_b24[4] = (char *)&local_99c;
  apcStack_b24[3] = local_998;
  apcStack_b24[2] = local_798;
  apcStack_b24[1] = (char *)0xa2962;
  local_9a4 = SV_GetModInfo();
  if (local_9a4 == 0) {
    pcStack_b08 = (char *)0x0;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa2a36;
    MSG_WriteByte();
  }
  else {
    pcStack_b08 = (char *)0x1;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa2986;
    MSG_WriteByte();
    pcStack_b08 = local_798;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa299c;
    MSG_WriteString();
    pcStack_b08 = local_998;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa29b2;
    MSG_WriteString();
    pcStack_b08 = &DAT_000e86dc;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa29ca;
    MSG_WriteString();
    pcStack_b08 = (char *)local_99c;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa29e0;
    MSG_WriteLong();
    pcStack_b08 = (char *)local_9a0;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa29f6;
    MSG_WriteLong();
    pcStack_b08 = (char *)local_ab0;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa2a0c;
    MSG_WriteByte();
    pcStack_b08 = (char *)local_aac;
    ppcStack_b0c = &local_20;
    pcStack_b10 = (char *)0xa2a22;
    MSG_WriteByte();
  }
  pcStack_b08 = (char *)(uint)(DAT_00524368 != 0);
  ppcStack_b0c = &local_20;
  pcStack_b10 = (char *)0xa2a5a;
  MSG_WriteByte();
LAB_000a2a5d:
  puVar2 = &net_from;
  ppcVar3 = &pcStack_b10;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar3 = (char *)*puVar2;
    puVar2 = puVar2 + 1;
    ppcVar3 = ppcVar3 + 1;
  }
  apcStack_b24[4] = local_18;
  apcStack_b24[3] = (char *)local_10;
  apcStack_b24[2] = (char *)0x1;
  apcStack_b24[1] = (char *)0xa2a81;
  NET_SendPacket();
  return;
}


// SVC_InfoString  @ 000a1eac
void SVC_InfoString(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char **ppcVar4;
  undefined4 auStack_ff4 [4];
  undefined1 *puStack_fe4;
  char *apcStack_fe0 [5];
  int local_fac;
  undefined1 local_fa6 [2];
  undefined4 local_fa4;
  undefined1 local_fa0 [2048];
  undefined1 local_7a0 [260];
  undefined1 local_69c [255];
  undefined1 local_59d;
  undefined1 local_59c [1400];
  char *local_24;
  undefined2 local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  apcStack_fe0[4] = (char *)0xa1ebd;
  local_24 = "SVC_InfoString";
  local_18 = 0x578;
  local_14 = 0;
  local_1c = local_59c;
  local_20 = 1;
  if (((noip == 0) && (sv != 0)) && (1 < DAT_00524288)) {
    local_c = 0;
    local_10 = 0;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if (((*(int *)(DAT_00524284 + local_8 * 0x4eec) != 0) ||
          (*(int *)(DAT_00524284 + 4 + local_8 * 0x4eec) != 0)) ||
         (*(int *)(DAT_00524284 + 0xc + local_8 * 0x4eec) != 0)) {
        if (*(int *)(DAT_00524284 + 0x243c + local_8 * 0x4eec) != 0) {
          local_10 = local_10 + 1;
        }
        local_c = local_c + 1;
      }
    }
    local_69c[0] = 0;
    apcStack_fe0[3] = (char *)0xff;
    puVar2 = &net_local_adr;
    puVar3 = auStack_ff4;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    apcStack_fe0[2] = (char *)NET_AdrToString();
    apcStack_fe0[1] = local_69c;
    apcStack_fe0[0] = (char *)0xa207d;
    Q_strncpy();
    local_59d = 0;
    local_fa4 = 0;
    if (*(char *)sv_password._4_4_ != '\0') {
      apcStack_fe0[2] = &DAT_000e9480;
      apcStack_fe0[1] = (char *)sv_password._4_4_;
      apcStack_fe0[0] = (char *)0xa20b2;
      iVar1 = Q_stricmp();
      if (iVar1 != 0) {
        local_fa4 = 1;
      }
    }
    apcStack_fe0[2] = &DAT_000e984c;
    apcStack_fe0[1] = local_fa6;
    apcStack_fe0[0] = (char *)0xa20de;
    Q_strcpy();
    local_fa0[0] = 0;
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[1] = (char *)0x2e;
    apcStack_fe0[0] = "%i";
    puStack_fe4 = (undefined1 *)0xa2100;
    apcStack_fe0[3] = (char *)va();
    apcStack_fe0[2] = "protocol";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa211b;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[3] = local_69c;
    apcStack_fe0[2] = "address";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa213f;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[1] = (char *)local_c;
    apcStack_fe0[0] = "%i";
    puStack_fe4 = (undefined1 *)0xa215c;
    apcStack_fe0[3] = (char *)va();
    apcStack_fe0[2] = "players";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa2177;
    Info_SetValueForKey();
    if (-1 < local_10) {
      apcStack_fe0[4] = (char *)0x800;
      apcStack_fe0[1] = (char *)local_10;
      apcStack_fe0[0] = "%i";
      puStack_fe4 = (undefined1 *)0xa219a;
      apcStack_fe0[3] = (char *)va();
      apcStack_fe0[2] = "proxytarget";
      apcStack_fe0[1] = local_fa0;
      apcStack_fe0[0] = (char *)0xa21b5;
      Info_SetValueForKey();
    }
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[1] = (char *)0xa21c5;
    iVar1 = Master_IsLanGame();
    apcStack_fe0[1] = (char *)(uint)(iVar1 != 0);
    apcStack_fe0[0] = "%i";
    puStack_fe4 = (undefined1 *)0xa21df;
    apcStack_fe0[3] = (char *)va();
    apcStack_fe0[2] = &DAT_000e9876;
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa21fa;
    Info_SetValueForKey();
    local_fac = (int)ROUND((float)sv_visiblemaxplayers._12_4_);
    if (local_fac < 0) {
      local_fac = DAT_00524288;
    }
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[1] = (char *)local_fac;
    apcStack_fe0[0] = "%i";
    puStack_fe4 = (undefined1 *)0xa2265;
    apcStack_fe0[3] = (char *)va();
    apcStack_fe0[2] = &DAT_000e987a;
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa2280;
    Info_SetValueForKey();
    apcStack_fe0[2] = local_7a0;
    apcStack_fe0[1] = &com_gamedir;
    apcStack_fe0[0] = (char *)0xa229b;
    COM_FileBase();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[3] = local_7a0;
    apcStack_fe0[2] = "gamedir";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa22bf;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[3] = (char *)0xa22d2;
    apcStack_fe0[3] = (char *)(*DAT_0036afb0)();
    apcStack_fe0[2] = "description";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa22ea;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[0] = "hostname";
    puStack_fe4 = (undefined1 *)0xa2303;
    apcStack_fe0[3] = (char *)Cvar_VariableString();
    apcStack_fe0[2] = "hostname";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa231e;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[3] = &DAT_0036bc88;
    apcStack_fe0[2] = &DAT_000e9892;
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa2345;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    if (cls == 0) {
      apcStack_fe0[3] = &DAT_000e9896;
    }
    else {
      apcStack_fe0[3] = &DAT_000e984c;
    }
    apcStack_fe0[2] = &DAT_000e9898;
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa2382;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[1] = (char *)local_fa4;
    apcStack_fe0[0] = "%i";
    puStack_fe4 = (undefined1 *)0xa23a2;
    apcStack_fe0[3] = (char *)va();
    apcStack_fe0[2] = "password";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa23bd;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    apcStack_fe0[3] = local_fa6;
    apcStack_fe0[2] = &DAT_000e989d;
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa23e1;
    Info_SetValueForKey();
    apcStack_fe0[4] = (char *)0x800;
    if (DAT_00524368 == 0) {
      apcStack_fe0[3] = &DAT_000e8746;
    }
    else {
      apcStack_fe0[3] = &DAT_000e86eb;
    }
    apcStack_fe0[2] = "secure";
    apcStack_fe0[1] = local_fa0;
    apcStack_fe0[0] = (char *)0xa2422;
    Info_SetValueForKey();
    if (gmodinfo != 0) {
      apcStack_fe0[4] = (char *)0x800;
      apcStack_fe0[1] = (char *)0x1;
      apcStack_fe0[0] = "%i";
      puStack_fe4 = (undefined1 *)0xa244c;
      apcStack_fe0[3] = (char *)va();
      apcStack_fe0[2] = &DAT_000e98a7;
      apcStack_fe0[1] = local_fa0;
      apcStack_fe0[0] = (char *)0xa2467;
      Info_SetValueForKey();
      apcStack_fe0[4] = (char *)0x800;
      apcStack_fe0[1] = (char *)DAT_0036ae84;
      apcStack_fe0[0] = "%i";
      puStack_fe4 = (undefined1 *)0xa248d;
      apcStack_fe0[3] = (char *)va();
      apcStack_fe0[2] = "modversion";
      apcStack_fe0[1] = local_fa0;
      apcStack_fe0[0] = (char *)0xa24a8;
      Info_SetValueForKey();
      apcStack_fe0[4] = (char *)0x800;
      apcStack_fe0[1] = (char *)DAT_0036ae8c;
      apcStack_fe0[0] = "%i";
      puStack_fe4 = (undefined1 *)0xa24ce;
      apcStack_fe0[3] = (char *)va();
      apcStack_fe0[2] = "svonly";
      apcStack_fe0[1] = local_fa0;
      apcStack_fe0[0] = (char *)0xa24e9;
      Info_SetValueForKey();
      apcStack_fe0[4] = (char *)0x800;
      apcStack_fe0[1] = (char *)DAT_0036ae90;
      apcStack_fe0[0] = "%i";
      puStack_fe4 = (undefined1 *)0xa250f;
      apcStack_fe0[3] = (char *)va();
      apcStack_fe0[2] = "cldll";
      apcStack_fe0[1] = local_fa0;
      apcStack_fe0[0] = (char *)0xa252a;
      Info_SetValueForKey();
    }
    apcStack_fe0[2] = (char *)0xffffffff;
    apcStack_fe0[1] = (char *)&local_24;
    apcStack_fe0[0] = (char *)0xa253b;
    MSG_WriteLong();
    apcStack_fe0[2] = "infostringresponse";
    apcStack_fe0[1] = (char *)&local_24;
    apcStack_fe0[0] = (char *)0xa2553;
    MSG_WriteString();
    apcStack_fe0[2] = local_fa0;
    apcStack_fe0[1] = (char *)&local_24;
    apcStack_fe0[0] = (char *)0xa2569;
    MSG_WriteString();
    puVar2 = &net_from;
    ppcVar4 = apcStack_fe0;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar4 = (char *)*puVar2;
      puVar2 = puVar2 + 1;
      ppcVar4 = ppcVar4 + 1;
    }
    puStack_fe4 = local_1c;
    auStack_ff4[3] = local_14;
    auStack_ff4[2] = 1;
    auStack_ff4[1] = 0xa2590;
    NET_SendPacket();
  }
  return;
}


// SVC_Ping  @ 000a1468
void SVC_Ping(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  
  uStack_30 = 0xa1476;
  local_c = 0xff;
  local_b = 0xff;
  local_a = 0xff;
  local_9 = 0xff;
  local_8 = 0x6a;
  local_7 = 0;
  puVar2 = &net_from;
  puVar3 = auStack_40;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  NET_SendPacket(1,6,&local_c);
  return;
}


// SVC_PlayerInfo  @ 000a2a94
void SVC_PlayerInfo(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 **ppuVar3;
  undefined4 *apuStack_870 [2];
  float local_868;
  undefined4 uStack_860;
  undefined1 local_824 [2048];
  char *local_24;
  undefined2 local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  float local_c;
  int local_8;
  
  uStack_860 = 0xa2aa5;
  local_24 = "SVC_PlayerInfo";
  local_18 = 0x800;
  local_14 = 0;
  local_1c = local_824;
  local_20 = 1;
  if ((sv != 0) && (1 < DAT_00524288)) {
    local_868 = -NAN;
    apuStack_870[1] = &local_24;
    apuStack_870[0] = (undefined4 *)0xa2b06;
    MSG_WriteLong();
    local_868 = 9.52883e-44;
    apuStack_870[1] = &local_24;
    apuStack_870[0] = (undefined4 *)0xa2b17;
    MSG_WriteByte();
    local_c = 0.0;
    local_10 = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if (*(int *)(DAT_00524284 + local_8 * 0x4eec) != 0) {
        local_c = (float)((int)local_c + 1);
      }
      local_10 = local_10 + 0x4eec;
    }
    local_868 = local_c;
    apuStack_870[1] = &local_24;
    apuStack_870[0] = (undefined4 *)0xa2b9c;
    MSG_WriteByte();
    local_c = 0.0;
    local_10 = DAT_00524284;
    for (local_8 = 0; local_8 < DAT_00524288; local_8 = local_8 + 1) {
      if (*(int *)(DAT_00524284 + local_8 * 0x4eec) != 0) {
        local_868 = (float)((int)local_c + 1);
        apuStack_870[1] = &local_24;
        apuStack_870[0] = (undefined4 *)0xa2c1f;
        local_c = local_868;
        MSG_WriteByte();
        local_868 = (float)(local_10 + 0x4bec);
        apuStack_870[1] = &local_24;
        apuStack_870[0] = (undefined4 *)0xa2c37;
        MSG_WriteString();
        local_868 = (float)(int)ROUND(*(float *)(*(int *)(local_10 + 0x4a84) + 0x1e4));
        apuStack_870[1] = &local_24;
        apuStack_870[0] = (undefined4 *)0xa2c87;
        MSG_WriteLong();
        local_868 = (float)realtime - *(float *)(local_10 + 0x3c);
        apuStack_870[1] = &local_24;
        apuStack_870[0] = (undefined4 *)0xa2cb8;
        MSG_WriteFloat();
      }
      local_10 = local_10 + 0x4eec;
    }
    puVar2 = &net_from;
    ppuVar3 = apuStack_870;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = (undefined4 *)*puVar2;
      puVar2 = puVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    NET_SendPacket(1,local_14,local_1c);
  }
  return;
}


// SVC_RuleInfo  @ 000a2d00
void SVC_RuleInfo(void)

{
  int iVar1;
  undefined4 *puVar2;
  char ***pppcVar3;
  char **appcStack_850 [4];
  undefined4 uStack_840;
  undefined1 local_820 [2048];
  char *local_20;
  undefined2 local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 *local_c;
  undefined *local_8;
  
  local_20 = "SVC_RuleInfo";
  local_14 = 0x800;
  local_10 = 0;
  local_1c = 1;
  local_18 = local_820;
  if ((sv != 0) && (1 < DAT_00524288)) {
    uStack_840 = 0xa2d69;
    local_8 = (undefined *)Cvar_CountServerVariables();
    if (0 < (int)local_8) {
      appcStack_850[2] = (char **)0xffffffff;
      appcStack_850[1] = &local_20;
      appcStack_850[0] = (char **)0xa2d8a;
      MSG_WriteLong();
      appcStack_850[2] = (char **)0x45;
      appcStack_850[1] = &local_20;
      appcStack_850[0] = (char **)0xa2d9b;
      MSG_WriteByte();
      appcStack_850[2] = (char **)local_8;
      appcStack_850[1] = &local_20;
      appcStack_850[0] = (char **)0xa2dae;
      MSG_WriteShort();
      for (local_c = cvar_vars; local_c != (undefined4 *)0x0; local_c = (undefined4 *)local_c[4]) {
        if ((local_c[2] & 4) != 0) {
          appcStack_850[2] = (char **)*local_c;
          appcStack_850[1] = &local_20;
          appcStack_850[0] = (char **)0xa2dee;
          MSG_WriteString();
          if ((local_c[2] & 0x20) == 0) {
            appcStack_850[2] = (char **)local_c[1];
            appcStack_850[1] = &local_20;
            appcStack_850[0] = (char **)0xa2e83;
            MSG_WriteString();
          }
          else {
            appcStack_850[1] = (char **)local_c[1];
            appcStack_850[0] = (char **)0xa2e0d;
            iVar1 = Q_strlen();
            if (0 < iVar1) {
              appcStack_850[2] = (char **)&DAT_000e9480;
              appcStack_850[1] = (char **)local_c[1];
              appcStack_850[0] = (char **)0xa2e2e;
              iVar1 = Q_stricmp();
              if (iVar1 != 0) {
                appcStack_850[2] = (char **)&DAT_000e86eb;
                appcStack_850[1] = &local_20;
                appcStack_850[0] = (char **)0xa2e4c;
                MSG_WriteString();
                goto LAB_000a2e86;
              }
            }
            appcStack_850[2] = (char **)&DAT_000e8746;
            appcStack_850[1] = &local_20;
            appcStack_850[0] = (char **)0xa2e69;
            MSG_WriteString();
          }
        }
LAB_000a2e86:
      }
      puVar2 = &net_from;
      pppcVar3 = appcStack_850;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pppcVar3 = (char **)*puVar2;
        puVar2 = puVar2 + 1;
        pppcVar3 = pppcVar3 + 1;
      }
      NET_SendPacket(1,local_10,local_18);
    }
  }
  return;
}


// SVC_ServiceChallenge  @ 000a1a2c
void SVC_ServiceChallenge(void)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  char **ppcVar7;
  int iStack_d8;
  char *pcStack_d4;
  char *apcStack_d0 [4];
  undefined4 uStack_c0;
  char local_90 [128];
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0x7fffffff;
  uStack_c0 = 0xa1a61;
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    apcStack_d0[1] = (char *)0x1;
    apcStack_d0[0] = (char *)0xa1a7a;
    pcVar2 = (char *)Cmd_Argv();
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      apcStack_d0[2] = &DAT_000e981f;
      apcStack_d0[0] = (char *)0xa1ab1;
      apcStack_d0[1] = pcVar2;
      iVar1 = Q_stricmp();
      if (iVar1 == 0) {
        for (local_8 = 0; local_8 < 0x400; local_8 = local_8 + 1) {
          puVar4 = (undefined4 *)(g_rg_sv_challenges + local_8 * 0x1c);
          piVar5 = &iStack_d8;
          for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
            *piVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            piVar5 = piVar5 + 1;
          }
          puVar4 = &net_from;
          puVar6 = (undefined4 *)&stack0xffffff14;
          for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar6 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar6 = puVar6 + 1;
          }
          iVar1 = NET_CompareBaseAdr();
          if (iVar1 != 0) break;
          if (*(int *)(g_rg_sv_challenges + local_8 * 0x1c + 0x18) < local_10) {
            local_10 = *(int *)(g_rg_sv_challenges + local_8 * 0x1c + 0x18);
            local_c = local_8;
          }
        }
        if (local_8 == 0x400) {
          apcStack_d0[2] = (char *)0xffff;
          apcStack_d0[1] = (char *)0x0;
          apcStack_d0[0] = (char *)0xa1ba4;
          iVar1 = RandomLong();
          apcStack_d0[2] = (undefined *)0xffff;
          apcStack_d0[1] = (char *)0x0;
          apcStack_d0[0] = (char *)0xa1bb8;
          uVar3 = RandomLong();
          *(uint *)(g_rg_sv_challenges + local_c * 0x1c + 0x14) = iVar1 << 0x10 | uVar3;
          puVar4 = &net_from;
          puVar6 = (undefined4 *)(g_rg_sv_challenges + local_c * 0x1c);
          for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar6 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar6 = puVar6 + 1;
          }
          *(int *)(g_rg_sv_challenges + local_c * 0x1c + 0x18) = (int)ROUND(realtime);
          local_8 = local_c;
        }
        apcStack_d0[1] = *(char **)(g_rg_sv_challenges + local_8 * 0x1c + 0x14);
        pcStack_d4 = (char *)0xff;
        iStack_d8 = 0xff;
        apcStack_d0[0] = pcVar2;
        snprintf(local_90,0x80,"%c%c%c%cchallenge %s %u\n");
        puVar4 = &net_from;
        ppcVar7 = apcStack_d0;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          *ppcVar7 = (char *)*puVar4;
          puVar4 = puVar4 + 1;
          ppcVar7 = ppcVar7 + 1;
        }
        pcStack_d4 = local_90;
        iStack_d8 = Q_strlen();
        iStack_d8 = iStack_d8 + 1;
        NET_SendPacket();
      }
    }
  }
  return;
}


