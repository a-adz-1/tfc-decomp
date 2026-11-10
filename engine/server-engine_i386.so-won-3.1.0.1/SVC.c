// SVC_Friends  @ 00076f00
void SVC_Friends(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_788;
  int local_768;
  undefined1 local_654 [1400];
  undefined2 local_dc [2];
  undefined1 *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  char local_cc [200];
  
  local_d4 = 0x578;
  local_d0 = 0;
  local_d8 = local_654;
  local_dc[0] = 1;
  if ((sv != 0) && (1 < DAT_001ab4e8)) {
    local_768 = 0;
    if (0 < DAT_001ab4e8) {
      do {
        local_768 = local_768 + 1;
      } while (local_768 < DAT_001ab4e8);
    }
    MSG_WriteLong();
    MSG_WriteString();
    MSG_WriteLong();
    MSG_WriteLong(local_dc);
    sprintf(local_cc,"ver %d\n");
    Q_strlen();
    MSG_WriteBuf();
    uVar1 = Cvar_VariableString();
    sprintf(local_cc,"srv_name \"%s\"\n",uVar1);
    Q_strlen();
    MSG_WriteBuf();
    sprintf(local_cc,"map_name \"%s\"\n");
    uVar1 = Q_strlen(local_cc);
    MSG_WriteBuf(local_dc,uVar1);
    COM_FileBase();
    sprintf(local_cc,"game_dir \"%s\"\n");
    Q_strlen();
    MSG_WriteBuf(local_dc);
    (*DAT_00386290)();
    sprintf(local_cc,"game_des \"%s\"\n");
    Q_strlen();
    MSG_WriteBuf();
    sprintf(local_cc,"max_plr %d\n");
    Q_strlen();
    MSG_WriteBuf();
    sprintf(local_cc,"srv_mode %c\n");
    Q_strlen();
    MSG_WriteBuf();
    MSG_WriteString(local_dc);
    iVar2 = Q_strlen();
    if (0 < iVar2) {
      Q_stricmp();
    }
    sprintf(local_cc,"pwd %d\n");
    Q_strlen();
    MSG_WriteBuf();
    sprintf(local_cc,"num_plr %d\n");
    Q_strlen();
    MSG_WriteBuf();
    local_768 = 0;
    if (0 < DAT_001ab4e8) {
      local_788 = 0;
      do {
        if (((*(int *)(DAT_001ab4e4 + local_788) != 0) ||
            (*(int *)(DAT_001ab4e4 + 4 + local_788) != 0)) ||
           (*(int *)(DAT_001ab4e4 + 0xc + local_788) != 0)) {
          sprintf(local_cc,"plr %d\n");
          Q_strlen();
          MSG_WriteBuf();
          iVar2 = local_788 + DAT_001ab4e4;
          Info_ValueForKey(iVar2 + 0x4af4);
          iVar3 = Q_strlen();
          if (iVar3 != 0) {
            Q_atoi();
          }
          sprintf(local_cc,"svr_uid %d\n");
          Q_strlen();
          MSG_WriteBuf();
          sprintf(local_cc,"name %s\n");
          Q_strlen();
          MSG_WriteBuf();
          sprintf(local_cc,"fid %d\n");
          uVar1 = Q_strlen(local_cc);
          MSG_WriteBuf(local_dc,uVar1);
          sprintf(local_cc,"wid %d\n");
          Q_strlen();
          MSG_WriteBuf();
          sprintf(local_cc,"team %d\n");
          Q_strlen();
          MSG_WriteBuf();
          sprintf(local_cc,"class %c\n");
          uVar1 = Q_strlen(local_cc);
          MSG_WriteBuf(local_dc,uVar1);
          sprintf(local_cc,"frags %d\n");
          Q_strlen();
          MSG_WriteBuf();
          sprintf(local_cc,"time %d\n",realtime - (double)*(float *)(iVar2 + 0x3c));
          Q_strlen();
          MSG_WriteBuf();
          SV_CalcPing();
          sprintf(local_cc,"ping %d\n");
          uVar1 = Q_strlen(local_cc,local_cc);
          MSG_WriteBuf(local_dc,uVar1);
        }
        local_788 = local_788 + 0x5054;
        local_768 = local_768 + 1;
      } while (local_768 < DAT_001ab4e8);
    }
    MSG_WriteString();
    puVar4 = &net_from;
    puVar5 = (undefined4 *)&stack0xfffff850;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    NET_SendPacket(1,local_d0,local_d8);
  }
  return;
}


// SVC_GameDllQuery  @ 00077d70
/* WARNING: Type propagation algorithm not settling */

undefined4 SVC_GameDllQuery(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  int *apiStack_830 [5];
  int local_808 [513];
  
  if ((sv == 0) || (DAT_001ab4e8 < 2)) {
    uVar1 = 0;
  }
  else {
    apiStack_830[4] = (int *)0x800;
    apiStack_830[3] = (int *)0x0;
    apiStack_830[1] = (int *)0x77dc1;
    apiStack_830[2] = local_808 + 1;
    Q_memset();
    local_808[0] = 0x7fc;
    apiStack_830[1] = local_808;
    apiStack_830[0] = local_808 + 2;
    uVar1 = (*DAT_003862d4)(&net_from,param_1);
    if ((local_808[0] != 0) && (local_808[0] < 0x7fd)) {
      local_808[1] = 0xffffffff;
      puVar3 = &net_from;
      ppiVar4 = apiStack_830;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppiVar4 = (int *)*puVar3;
        puVar3 = puVar3 + 1;
        ppiVar4 = ppiVar4 + 1;
      }
      NET_SendPacket(1,local_808[0] + 4,local_808 + 1);
    }
  }
  return uVar1;
}


// SVC_GetChallenge  @ 00076ac0
void SVC_GetChallenge(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  undefined4 *puVar6;
  char *pcStackY_ec;
  char *pcStack_e0;
  char *pcStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  char *pcStack_c8;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  char local_84 [128];
  
  pcStack_c8 = (char *)0x76ad1;
  local_98 = 0;
  local_9c = 0x7fffffff;
  local_94 = 0;
  local_a0 = 0;
  do {
    puVar4 = (undefined4 *)(g_rg_sv_challenges + local_a0);
    puVar6 = &stack0xffffff28;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar4 = &net_from;
    ppcVar5 = &pcStackY_ec;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppcVar5 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    iVar1 = NET_CompareBaseAdr();
    iVar3 = local_94;
    if (iVar1 != 0) break;
    if (*(int *)(g_rg_sv_challenges + local_a0 + 0x18) < local_9c) {
      local_98 = local_94;
      local_9c = *(int *)(g_rg_sv_challenges + local_a0 + 0x18);
    }
    puVar4 = (undefined4 *)(g_rg_sv_challenges + local_a0 + 0x1c);
    puVar6 = &stack0xffffff28;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar4 = &net_from;
    ppcVar5 = &pcStackY_ec;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppcVar5 = (char *)*puVar4;
      puVar4 = puVar4 + 1;
      ppcVar5 = ppcVar5 + 1;
    }
    iVar1 = NET_CompareBaseAdr();
    iVar3 = local_94 + 1;
    if (iVar1 != 0) break;
    if (*(int *)(g_rg_sv_challenges + local_a0 + 0x34) < local_9c) {
      local_9c = *(int *)(g_rg_sv_challenges + local_a0 + 0x34);
      local_98 = local_94 + 1;
    }
    local_a0 = local_a0 + 0x38;
    local_94 = local_94 + 2;
    iVar3 = local_94;
  } while (local_94 < 0x400);
  local_94 = iVar3;
  if (local_94 == 0x400) {
    pcStack_c8 = (char *)0xffff;
    uStack_cc = 0;
    uStack_d0 = 0x76c23;
    iVar3 = RandomLong();
    uStack_d0 = 0xffff;
    uStack_d4 = 0;
    uStack_d8 = 0x76c31;
    uVar2 = RandomLong();
    iVar1 = local_98 * 0x1c;
    *(uint *)(g_rg_sv_challenges + iVar1 + 0x14) = iVar3 << 0x10 | uVar2;
    puVar4 = &net_from;
    puVar6 = (undefined4 *)(g_rg_sv_challenges + iVar1);
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    *(int *)(g_rg_sv_challenges + iVar1 + 0x18) = (int)ROUND(realtime);
    local_94 = local_98;
  }
  if (((sv == 0) || (DAT_001ab4e8 < 2)) ||
     ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    gfUseLANAuthentication = 1;
  }
  else {
    pcStack_c8 = (char *)0x76d0b;
    COM_CheckAuthenticationType();
  }
  if (gfUseLANAuthentication == 0) {
    pcStack_c8 = "Server requiring WON authentication\n";
    uStack_cc = 0x76d44;
    Con_DPrintf();
    pcStack_c8 = (char *)0x1;
  }
  else {
    pcStack_c8 = "Server requiring authentication\n";
    uStack_cc = 0x76d30;
    Con_DPrintf();
    pcStack_c8 = (char *)0x2;
  }
  uStack_cc = *(undefined4 *)(g_rg_sv_challenges + local_94 * 0x1c + 0x14);
  uStack_d0 = 0x41;
  uStack_d4 = 0xff;
  uStack_d8 = 0xff;
  pcStack_dc = (char *)0xff;
  pcStack_e0 = (char *)0xff;
  pcStackY_ec = (char *)0x76d8c;
  sprintf(local_84,"%c%c%c%c%c00000000 %u %i\n");
  puVar4 = &net_from;
  puVar6 = &stack0xffffff28;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  pcStack_e0 = local_84;
  pcStack_dc = local_84;
  iVar3 = Q_strlen();
  pcStack_e0 = (char *)(iVar3 + 1);
  NET_SendPacket();
  return;
}


// SVC_Heartbeat  @ 00077ce0
void SVC_Heartbeat(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 auStack_3c [5];
  undefined4 *apuStack_28 [5];
  undefined4 *local_8;
  
  apuStack_28[4] = (undefined4 *)0x77cee;
  local_8 = valvemaster_adr;
  if (valvemaster_adr != (undefined4 *)0x0) {
    do {
      puVar3 = &net_from;
      ppuVar4 = apuStack_28;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppuVar4 = (undefined4 *)*puVar3;
        puVar3 = puVar3 + 1;
        ppuVar4 = ppuVar4 + 1;
      }
      puVar3 = local_8 + 6;
      puVar5 = auStack_3c;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar2 = NET_CompareAdr();
    } while ((iVar2 == 0) && (local_8 = (undefined4 *)local_8[0xb], local_8 != (undefined4 *)0x0));
    if (local_8 != (undefined4 *)0x0) {
      *local_8 = 0;
      apuStack_28[4] = (undefined4 *)0x77d57;
      uVar1 = MSG_ReadLong();
      local_8[2] = uVar1;
      apuStack_28[4] = local_8;
      apuStack_28[3] = (undefined4 *)0x77d63;
      Master_RequestHeartbeat();
    }
  }
  return;
}


// SVC_Info  @ 0007759c
void SVC_Info(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int **ppiVar5;
  int *apiStack_aec [2];
  undefined4 **ppuStack_ae4;
  int *piStack_ae0;
  char *pcStack_adc;
  int local_ac4;
  int local_ac0;
  int local_abc;
  int *local_ab8;
  undefined4 local_ab4;
  undefined1 local_ab0 [32];
  undefined1 local_a90 [260];
  int local_98c [128];
  undefined1 local_78c [512];
  undefined1 local_58c [1400];
  undefined2 local_14 [2];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x578;
  local_8 = 0;
  local_10 = local_58c;
  local_14[0] = 0;
  if (sv == 0) {
    return;
  }
  if ((int)DAT_001ab4e8 < 2) {
    return;
  }
  local_ac4 = 0;
  iVar4 = 0;
  if (0 < (int)DAT_001ab4e8) {
    iVar2 = 0;
    do {
      if (((*(int *)(DAT_001ab4e4 + iVar2) != 0) || (*(int *)(DAT_001ab4e4 + 4 + iVar2) != 0)) ||
         (*(int *)(DAT_001ab4e4 + 0xc + iVar2) != 0)) {
        local_ac4 = local_ac4 + 1;
      }
      iVar2 = iVar2 + 0x5054;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)DAT_001ab4e8);
  }
  pcStack_adc = (char *)0xffffffff;
  ppuStack_ae4 = (undefined4 **)0x7764e;
  piStack_ae0 = (int *)local_14;
  MSG_WriteLong();
  if (param_1 == 0) {
    pcStack_adc = (char *)0x43;
  }
  else {
    pcStack_adc = (char *)0x6d;
  }
  ppuStack_ae4 = (undefined4 **)0x7766a;
  piStack_ae0 = (int *)local_14;
  MSG_WriteByte();
  if (noip == 0) {
    puVar3 = &net_local_adr;
    ppiVar5 = apiStack_aec;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppiVar5 = (int *)*puVar3;
      puVar3 = puVar3 + 1;
      ppiVar5 = ppiVar5 + 1;
    }
    uVar1 = NET_AdrToString();
    MSG_WriteString(local_14,uVar1);
  }
  else {
    pcStack_adc = "LOOPBACK";
    ppuStack_ae4 = (undefined4 **)0x776b7;
    piStack_ae0 = (int *)local_14;
    MSG_WriteString();
  }
  pcStack_adc = "hostname";
  piStack_ae0 = (int *)0x776c6;
  piStack_ae0 = (int *)Cvar_VariableString();
  apiStack_aec[1] = (int *)0x776d3;
  ppuStack_ae4 = (undefined4 **)local_14;
  MSG_WriteString();
  apiStack_aec[1] = (int *)&DAT_001535a8;
  apiStack_aec[0] = (int *)local_14;
  MSG_WriteString();
  COM_FileBase(com_gamedir,local_a90);
  MSG_WriteString(local_14,local_a90);
  pcStack_adc = (char *)0x77717;
  pcStack_adc = (char *)(*DAT_00386290)();
  ppuStack_ae4 = (undefined4 **)0x77724;
  piStack_ae0 = (int *)local_14;
  MSG_WriteString();
  ppuStack_ae4 = (undefined4 **)local_ac4;
  apiStack_aec[0] = (int *)0x77737;
  apiStack_aec[1] = (int *)local_14;
  MSG_WriteByte();
  apiStack_aec[0] = DAT_001ab4e8;
  MSG_WriteByte(local_14);
  MSG_WriteByte(local_14,0x2a);
  if (param_1 == 0) goto LAB_000778c9;
  if (cls == 0) {
    pcStack_adc = (char *)0x64;
  }
  else {
    pcStack_adc = (char *)0x6c;
  }
  ppuStack_ae4 = (undefined4 **)0x77786;
  piStack_ae0 = (int *)local_14;
  MSG_WriteByte();
  pcStack_adc = (char *)0x6c;
  ppuStack_ae4 = (undefined4 **)0x77797;
  piStack_ae0 = (int *)local_14;
  MSG_WriteByte();
  ppuStack_ae4 = (undefined4 **)sv_password._4_4_;
  apiStack_aec[1] = (int *)0x777a6;
  iVar4 = Q_strlen();
  if (iVar4 < 1) {
LAB_000777d4:
    pcStack_adc = (char *)0x0;
  }
  else {
    pcStack_adc = &DAT_000ab13c;
    piStack_ae0 = (int *)sv_password._4_4_;
    ppuStack_ae4 = (undefined4 **)0x777c3;
    iVar4 = Q_stricmp();
    if (iVar4 == 0) goto LAB_000777d4;
    pcStack_adc = (char *)0x1;
  }
  ppuStack_ae4 = (undefined4 **)0x777e2;
  piStack_ae0 = (int *)local_14;
  MSG_WriteByte();
  pcStack_adc = local_ab0;
  piStack_ae0 = &local_ab4;
  ppuStack_ae4 = &local_ab8;
  apiStack_aec[1] = &local_abc;
  apiStack_aec[0] = &local_ac0;
  iVar4 = SV_GetModInfo(local_78c,local_98c);
  if (iVar4 == 0) {
    pcStack_adc = (char *)0x0;
    ppuStack_ae4 = (undefined4 **)0x778c6;
    piStack_ae0 = (int *)local_14;
    MSG_WriteByte();
  }
  else {
    pcStack_adc = (char *)0x1;
    ppuStack_ae4 = (undefined4 **)0x77834;
    piStack_ae0 = (int *)local_14;
    MSG_WriteByte();
    apiStack_aec[0] = (int *)0x77841;
    apiStack_aec[1] = (int *)local_14;
    ppuStack_ae4 = (undefined4 **)local_78c;
    MSG_WriteString();
    apiStack_aec[0] = local_98c;
    MSG_WriteString(local_14);
    MSG_WriteString(local_14,&DAT_000aa5fc);
    pcStack_adc = (char *)local_ac0;
    ppuStack_ae4 = (undefined4 **)0x77877;
    piStack_ae0 = (int *)local_14;
    MSG_WriteLong();
    ppuStack_ae4 = (undefined4 **)local_abc;
    apiStack_aec[0] = (int *)0x7788a;
    apiStack_aec[1] = (int *)local_14;
    MSG_WriteLong();
    apiStack_aec[0] = local_ab8;
    MSG_WriteByte(local_14);
    MSG_WriteByte(local_14,local_ab4);
  }
LAB_000778c9:
  puVar3 = &net_from;
  ppiVar5 = apiStack_aec;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppiVar5 = (int *)*puVar3;
    puVar3 = puVar3 + 1;
    ppiVar5 = ppiVar5 + 1;
  }
  NET_SendPacket(1,local_8,local_10);
  return;
}


// SVC_Ping  @ 00076a60
void SVC_Ping(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_2c [4];
  undefined4 uStack_1c;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  
  uStack_1c = 0x76a6e;
  local_c = 0xff;
  local_b = 0xff;
  local_a = 0xff;
  local_9 = 0xff;
  local_8 = 0x6a;
  local_7 = 0;
  puVar2 = &net_from;
  puVar3 = auStack_2c;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  NET_SendPacket(1,6,&local_c);
  return;
}


// SVC_PlayerInfo  @ 000778f8
void SVC_PlayerInfo(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iStack_860;
  undefined2 *puStack_85c;
  int *piStack_858;
  undefined2 *puStack_854;
  uint uStack_850;
  int local_83c;
  float *local_838;
  int *local_828;
  undefined1 local_814 [2048];
  undefined2 local_14 [2];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x800;
  local_8 = 0;
  local_10 = local_814;
  local_14[0] = 0;
  if (sv == 0) {
    return;
  }
  if ((int)DAT_001ab4e8 < 2) {
    return;
  }
  uStack_850 = 0xffffffff;
  piStack_858 = (int *)0x7795d;
  puStack_854 = local_14;
  MSG_WriteLong();
  piStack_858 = (int *)0x44;
  iStack_860 = 0x7796b;
  puStack_85c = local_14;
  MSG_WriteByte();
  uStack_850 = 0;
  iVar4 = 0;
  if (0 < (int)DAT_001ab4e8) {
    iVar2 = 0;
    uVar1 = DAT_001ab4e8 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          uStack_850 = (uint)(*DAT_001ab4e4 != 0);
          iVar2 = 0x5054;
        }
        if (*(int *)((int)DAT_001ab4e4 + iVar2) != 0) {
          uStack_850 = uStack_850 + 1;
        }
        iVar2 = iVar2 + 0x5054;
        iVar4 = (2 < uVar1) + 1;
      }
      if (*(int *)((int)DAT_001ab4e4 + iVar2) != 0) {
        uStack_850 = uStack_850 + 1;
      }
      iVar2 = iVar2 + 0x5054;
      iVar4 = iVar4 + 1;
      if ((int)DAT_001ab4e8 <= iVar4) goto LAB_00077a41;
    }
    do {
      if (*(int *)((int)DAT_001ab4e4 + iVar2) != 0) {
        uStack_850 = uStack_850 + 1;
      }
      if (*(int *)((int)DAT_001ab4e4 + iVar2 + 0x5054) != 0) {
        uStack_850 = uStack_850 + 1;
      }
      if (*(int *)((int)DAT_001ab4e4 + iVar2 + 0xa0a8) != 0) {
        uStack_850 = uStack_850 + 1;
      }
      if (*(int *)((int)DAT_001ab4e4 + iVar2 + 0xf0fc) != 0) {
        uStack_850 = uStack_850 + 1;
      }
      iVar2 = iVar2 + 0x14150;
      iVar4 = iVar4 + 4;
    } while (iVar4 < (int)DAT_001ab4e8);
  }
LAB_00077a41:
  piStack_858 = (int *)0x77a4e;
  puStack_854 = local_14;
  MSG_WriteByte();
  uVar1 = 0;
  iVar4 = 0;
  local_828 = DAT_001ab4e4;
  if (0 < (int)DAT_001ab4e8) {
    local_838 = (float *)(DAT_001ab4e4 + 0xf);
    local_83c = 0;
    do {
      if (*(int *)((int)DAT_001ab4e4 + local_83c) != 0) {
        uVar1 = uVar1 + 1;
        piStack_858 = (int *)0x77ab5;
        puStack_854 = local_14;
        uStack_850 = uVar1;
        MSG_WriteByte();
        piStack_858 = local_828 + 0x130f;
        iStack_860 = 0x77acd;
        puStack_85c = local_14;
        MSG_WriteString();
        iStack_860 = (int)ROUND(*(float *)((int)local_838[0x12aa] + 0x1e4));
        MSG_WriteLong(local_14);
        MSG_WriteFloat(local_14,(float)realtime - *local_838);
      }
      local_83c = local_83c + 0x5054;
      iVar4 = iVar4 + 1;
      local_838 = local_838 + 0x1415;
      local_828 = local_828 + 0x1415;
    } while (iVar4 < (int)DAT_001ab4e8);
  }
  puVar3 = &net_from;
  piVar5 = &iStack_860;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    piVar5 = piVar5 + 1;
  }
  NET_SendPacket(1,local_8,local_10);
  return;
}


// SVC_RuleInfo  @ 00077ba8
void SVC_RuleInfo(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iStack_838;
  undefined2 *puStack_834;
  undefined4 uStack_830;
  undefined2 *puStack_82c;
  undefined *puStack_828;
  undefined1 local_814 [2048];
  undefined2 local_14 [2];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x800;
  local_8 = 0;
  local_14[0] = 1;
  local_10 = local_814;
  if ((sv != 0) && (1 < DAT_001ab4e8)) {
    puStack_828 = (undefined *)0x77c01;
    iVar1 = Cvar_CountServerVariables();
    if (0 < iVar1) {
      puStack_828 = (undefined *)0xffffffff;
      uStack_830 = 0x77c1c;
      puStack_82c = local_14;
      MSG_WriteLong();
      uStack_830 = 0x45;
      iStack_838 = 0x77c24;
      puStack_834 = local_14;
      MSG_WriteByte();
      iStack_838 = iVar1;
      MSG_WriteShort(local_14);
      for (puVar2 = cvar_vars; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[4]) {
        if ((*(byte *)(puVar2 + 2) & 4) != 0) {
          puStack_828 = (undefined *)*puVar2;
          uStack_830 = 0x77c51;
          puStack_82c = local_14;
          MSG_WriteString();
          if ((*(byte *)(puVar2 + 2) & 0x20) == 0) {
            puStack_828 = (undefined *)puVar2[1];
          }
          else {
            puStack_828 = (undefined *)puVar2[1];
            puStack_82c = (undefined2 *)0x77c63;
            iVar1 = Q_strlen();
            if (0 < iVar1) {
              puStack_828 = &DAT_000ab13c;
              puStack_82c = (undefined2 *)puVar2[1];
              uStack_830 = 0x77c7a;
              iVar1 = Q_stricmp();
              if (iVar1 != 0) {
                puStack_828 = &DAT_000aa60b;
                goto LAB_00077ca1;
              }
            }
            puStack_828 = &DAT_000aa665;
          }
LAB_00077ca1:
          uStack_830 = 0x77ca6;
          puStack_82c = local_14;
          MSG_WriteString();
        }
      }
      puVar2 = &net_from;
      piVar3 = &iStack_838;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        piVar3 = piVar3 + 1;
      }
      NET_SendPacket(1,local_8,local_10);
    }
  }
  return;
}


// SVC_Status  @ 00076ab8
void SVC_Status(void)

{
  return;
}


