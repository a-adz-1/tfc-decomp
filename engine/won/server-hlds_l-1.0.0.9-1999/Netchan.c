// Netchan_CanPacket  @ 08065910
undefined4 Netchan_CanPacket(int *param_1)

{
  double dVar1;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)net_chokeloopback._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)net_chokeloopback._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
      ) || (*param_1 != 1)) {
    if ((sv == 0) ||
       ((byte)(0.0 < (float)sv_lan._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
      dVar1 = (1.0 / *(double *)(param_1 + 0x10)) * 200.0;
    }
    else {
      dVar1 = 0.020002000033855438;
    }
    if (dVar1 + realtime <= *(double *)(param_1 + 0xe)) {
      return 0;
    }
  }
  return 1;
}


// Netchan_CanReliable  @ 080659a0
undefined4 Netchan_CanReliable(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1dc4) == 0) {
    uVar1 = Netchan_CanPacket(param_1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Netchan_Init  @ 08065f50
void Netchan_Init(void)

{
  Cvar_RegisterVariable(showpackets);
  Cvar_RegisterVariable(showdrop);
  Cvar_RegisterVariable(scr_netgraph);
  Cvar_RegisterVariable(net_chokeloopback);
  Cmd_AddCommand("uprate",Net_Rate_f);
  net_rate = 0x461c3c00;
  return;
}


// Netchan_OutOfBand  @ 080657c0
void Netchan_OutOfBand(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 **ppuVar5;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined1 *apuStack_1d8c [4];
  undefined4 uStack_1d7c;
  undefined1 local_1d6c [7508];
  undefined1 local_18 [8];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar2 = in_stack_00000020;
  uVar1 = in_stack_0000001c;
  local_10 = local_1d6c;
  local_c = 0x1d54;
  local_8 = 0;
  uStack_1d7c = 0xffffffff;
  apuStack_1d8c[2] = (undefined1 *)0x80657f4;
  apuStack_1d8c[3] = local_18;
  MSG_WriteLong();
  apuStack_1d8c[2] = (undefined1 *)uVar1;
  apuStack_1d8c[1] = (undefined1 *)uVar2;
  apuStack_1d8c[0] = local_18;
  SZ_Write();
  if (DAT_081b9d98 == 0) {
    puVar4 = (undefined4 *)&stack0x00000008;
    ppuVar5 = apuStack_1d8c;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppuVar5 = (undefined1 *)*puVar4;
      puVar4 = puVar4 + 1;
      ppuVar5 = ppuVar5 + 1;
    }
    NET_SendPacket(param_1,local_8,local_10);
  }
  return;
}


// Netchan_OutOfBandPrint  @ 08065840
void Netchan_OutOfBandPrint(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *in_stack_0000001c;
  undefined4 auStack_3c [5];
  uint uStack_28;
  undefined1 *puStack_24;
  
  puStack_24 = (undefined1 *)0x806585e;
  vsprintf(&string_98,in_stack_0000001c,&stack0x00000020);
  puStack_24 = &string_98;
  uStack_28 = 0xffffffff;
  pcVar4 = &string_98;
  do {
    if (uStack_28 == 0) break;
    uStack_28 = uStack_28 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uStack_28 = ~uStack_28;
  puVar3 = (undefined4 *)&stack0x00000008;
  puVar5 = auStack_3c;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  Netchan_OutOfBand(param_1);
  return;
}


// Netchan_Process  @ 08065d30
undefined4 Netchan_Process(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint auStack_50 [4];
  char *pcStack_40;
  uint uStack_3c;
  char *pcStack_38;
  undefined4 *puStack_34;
  uint uStack_30;
  float local_2c;
  uint local_c;
  
  if (DAT_081b9d98 == 0) {
    puVar5 = param_1;
    puVar6 = auStack_50 + 5;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = &net_from;
    puVar6 = auStack_50;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    iVar2 = NET_CompareAdr();
    if (iVar2 == 0) {
      return 0;
    }
  }
  local_2c = 4.043409e-34;
  MSG_BeginReading();
  local_2c = 4.0434113e-34;
  uVar1 = MSG_ReadLong();
  local_2c = 4.0434145e-34;
  local_c = MSG_ReadLong();
  uVar3 = local_c >> 0x1f;
  uVar4 = uVar1 & 0x7fffffff;
  local_c = local_c & 0x7fffffff;
  if ((byte)(0.0 < (float)showpackets._12_4_ |
             (byte)((ushort)((ushort)NAN((float)showpackets._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    local_2c = (float)net_message._16_4_;
    puStack_34 = (undefined4 *)local_c;
    pcStack_40 = "<-- s=%i(%i) a=%i(%i) %i\n";
    auStack_50[3] = 0x8065de1;
    uStack_3c = uVar4;
    pcStack_38 = (char *)-((int)uVar1 >> 0x1f);
    uStack_30 = uVar3;
    Con_Printf();
  }
  if (uVar4 <= (uint)param_1[0x12]) {
    if ((byte)(0.0 < (float)showdrop._12_4_ |
               (byte)((ushort)((ushort)NAN((float)showdrop._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)showdrop._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      local_2c = (float)param_1[0x12];
      puVar6 = auStack_50 + 3;
      uStack_30 = uVar4;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *param_1;
        param_1 = param_1 + 1;
        puVar6 = puVar6 + 1;
      }
      auStack_50[2] = 0x8065e1e;
      puStack_34 = (undefined4 *)NET_AdrToString();
      pcStack_38 = "%s:Out of order packet %i at %i\n";
      uStack_3c = 0x8065e2e;
      Con_Printf();
    }
    return 0;
  }
  uStack_30 = (uVar4 - 1) - param_1[0x12];
  net_drop = uStack_30;
  if ((0 < (int)uStack_30) &&
     (param_1[0xb] = param_1[0xb] + 1,
     (byte)(0.0 < (float)showdrop._12_4_ |
            (byte)((ushort)((ushort)NAN((float)showdrop._12_4_) << 10) >> 8) |
           (byte)((ushort)((ushort)((float)showdrop._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    puVar5 = param_1;
    puVar6 = auStack_50 + 3;
    local_2c = (float)uVar4;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    auStack_50[2] = 0x8065e82;
    puStack_34 = (undefined4 *)NET_AdrToString();
    pcStack_38 = "%s:Dropped %i packets at %i\n";
    uStack_3c = 0x8065e90;
    Con_Printf();
  }
  if (uVar3 == param_1[0x17]) {
    param_1[0x771] = 0;
  }
  param_1[0x12] = uVar4;
  param_1[0x13] = local_c;
  param_1[0x14] = uVar3;
  if (-((int)uVar1 >> 0x1f) != 0) {
    *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x15) ^ 1;
  }
  local_2c = (float)realtime - (float)param_1[7];
  if (local_2c < 0.001) {
    local_2c = 0.001;
  }
  if ((byte)(0.5 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 0.5) << 0xe) >> 8)) == 1) {
    local_2c = 0.5;
  }
  local_2c = 1.0 / local_2c;
  uStack_30 = param_1[0x16] - local_c;
  puStack_34 = param_1;
  pcStack_38 = (char *)0x8065f21;
  Netchan_UpdateStats();
  param_1[0xc] = param_1[0xc] + 1;
  param_1[7] = (float)realtime;
  return 1;
}


// Netchan_Setup  @ 080658a0
void Netchan_Setup(undefined4 param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = param_2;
  for (iVar2 = 0xfa5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_2[5] = param_1;
  puVar3 = (undefined4 *)&stack0x0000000c;
  puVar4 = param_2;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  fVar1 = (float)realtime;
  param_2[7] = fVar1;
  param_2[8] = fVar1;
  param_2[0x1b] = param_2 + 0x1e;
  param_2[0x19] = 1;
  param_2[0x1c] = 0x1d4c;
  *(double *)(param_2 + 0x10) = (double)net_rate;
  return;
}


// Netchan_Transmit  @ 080659d0
void Netchan_Transmit(undefined4 *param_1,int param_2)

{
  double dVar1;
  uint uVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 **ppuVar7;
  undefined1 *apuStack_1dc0 [2];
  undefined1 *local_1d74;
  undefined1 local_1d6c [7508];
  undefined1 local_18 [8];
  undefined1 *local_10;
  int local_c;
  int local_8;
  
  if (param_1[0x1a] == 0) {
    local_1d74 = (undefined1 *)0x0;
    if ((int)param_1[0x18] < (int)param_1[0x13]) {
      local_1d74 = (undefined1 *)(uint)(param_1[0x14] != param_1[0x17]);
    }
    if ((param_1[0x771] == 0) && (param_1[0x1d] != 0)) {
      apuStack_1dc0[1] = (undefined1 *)0x8065a77;
      memcpy(param_1 + 0x772,param_1 + 0x1e,param_1[0x1d]);
      param_1[0x771] = param_1[0x1d];
      param_1[0x1d] = 0;
      *(byte *)(param_1 + 0x17) = *(byte *)(param_1 + 0x17) ^ 1;
      local_1d74 = (undefined1 *)0x1;
    }
    local_10 = local_1d6c;
    local_c = 0x1d54;
    local_8 = 0;
    param_1[0x16] = param_1[0x16] + 1;
    MSG_WriteLong();
    apuStack_1dc0[0] = (undefined1 *)0x8065ae1;
    apuStack_1dc0[1] = local_18;
    MSG_WriteLong();
    if (local_1d74 != (undefined1 *)0x0) {
      apuStack_1dc0[1] = (undefined1 *)0x8065b07;
      SZ_Write();
      param_1[0x18] = param_1[0x16];
    }
    if (local_c - local_8 < param_2) {
      Con_DPrintf();
    }
    else {
      apuStack_1dc0[1] = (undefined1 *)0x8065b2e;
      SZ_Write();
    }
    if (local_8 < 0x10) {
      iVar5 = 0;
      do {
        MSG_WriteByte();
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x10);
    }
    uVar2 = param_1[0x16];
    param_1[(uVar2 & 0x1f) + 0xec5] = local_8;
    *(double *)(param_1 + (uVar2 & 0x1f) * 2 + 0xee5) = realtime;
    if (DAT_081b9d98 == 0) {
      puVar6 = param_1;
      ppuVar7 = apuStack_1dc0;
      for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppuVar7 = (undefined1 *)*puVar6;
        puVar6 = puVar6 + 1;
        ppuVar7 = ppuVar7 + 1;
      }
      NET_SendPacket(param_1[5],local_8,local_10);
    }
    if ((sv == 0) ||
       ((byte)(0.0 < (float)sv_lan._12_4_ |
               (byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
      fVar3 = 1.0 / (float)*(double *)(param_1 + 0x10);
    }
    else {
      fVar3 = 0.00010001;
    }
    dVar1 = *(double *)(param_1 + 0xe);
    if ((byte)(dVar1 < realtime | (byte)((ushort)((ushort)(NAN(dVar1) || NAN(realtime)) << 10) >> 8)
              | (byte)((ushort)((ushort)(dVar1 == realtime) << 0xe) >> 8)) == 1) {
      *(double *)(param_1 + 0xe) = (double)(fVar3 * (float)local_8 + (float)realtime);
    }
    else {
      *(double *)(param_1 + 0xe) =
           (double)(fVar3 * (float)local_8 + (float)*(double *)(param_1 + 0xe));
    }
    if ((byte)(0.0 < (float)showpackets._12_4_ |
               (byte)((ushort)((ushort)NAN((float)showpackets._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      apuStack_1dc0[1] = local_1d74;
      apuStack_1dc0[0] = (undefined1 *)param_1[0x16];
      Con_Printf("--> s=%i(%i) a=%i(%i) %i ");
    }
    if ((byte)(0.0 < (float)showpackets._12_4_ |
               (byte)((ushort)((ushort)NAN((float)showpackets._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      Con_Printf();
    }
    return;
  }
  param_1[6] = 1;
  ppuVar7 = apuStack_1dc0;
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppuVar7 = (undefined1 *)*param_1;
    param_1 = param_1 + 1;
    ppuVar7 = ppuVar7 + 1;
  }
  uVar4 = NET_AdrToString();
  Con_Printf("%s:Outgoing message overflow\n",uVar4);
  return;
}


// Netchan_UpdateStats  @ 08065cb0
void Netchan_UpdateStats(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  puVar1 = (undefined4 *)(param_1 + 0x3c94 + (*(uint *)(param_1 + 0x30) & 0x3f) * 8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (*(int *)(param_1 + 0x30) < 0x40) {
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    else {
      fVar3 = 0.0;
      iVar5 = 0;
      fVar4 = fVar3;
      do {
        piVar2 = (int *)(param_1 + 0x3c94 + iVar5 * 8);
        fVar3 = fVar3 + (float)piVar2[1];
        fVar4 = fVar4 + (float)*piVar2;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x40);
      *(float *)(param_1 + 0x24) = fVar4 * 0.015625;
      *(float *)(param_1 + 0x28) = fVar3 * 0.015625;
    }
  }
  return;
}


