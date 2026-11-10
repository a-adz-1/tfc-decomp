// WON_CheckAuthentication  @ 0008a2c8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 WON_CheckAuthentication(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_80c;
  int local_808;
  undefined1 local_804 [1024];
  undefined1 local_404 [1024];
  
  local_80c = 0;
  *param_3 = 0xffffffff;
  iVar2 = SV_FindAuthRequest(0,param_1);
  if (iVar2 == -1) {
    local_80c = 0;
  }
  else {
    iVar1 = iVar2 * 0x38;
    if (*(int *)(&DAT_00203ef0 + iVar1) != 0) {
      uVar3 = Q_strlen(param_2,local_404);
      COM_HexConvert(param_2,uVar3);
      iVar4 = Q_strlen(param_2);
      iVar5 = (*_DAT_003861b4)(*(undefined4 *)(&DAT_00203ef0 + iVar1),local_804,&local_808);
      if ((iVar5 != 0) && (local_808 == iVar4 / 2)) {
        iVar4 = Q_memcmp(local_804,local_404,local_808);
        if (iVar4 == 0) {
          local_80c = 1;
          *param_3 = *(undefined4 *)(&DAT_00203ef4 + iVar1);
        }
      }
    }
    WON_RemoveUser(&svauthstates + iVar2 * 0xe);
  }
  return local_80c;
}


// WON_GetUseridForAddress  @ 0008a284
undefined4 WON_GetUseridForAddress(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = SV_FindAuthRequest(0,param_1);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(&DAT_00203ef4 + iVar1 * 0x38);
  }
  return uVar2;
}


// WON_HandleClientAuthMsgs  @ 0008abf8
void WON_HandleClientAuthMsgs(void)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  char *apcStack_30 [5];
  
  apcStack_30[4] = (char *)0x8ac06;
  puVar2 = &clauthstate;
  if (clauthstate == 0) {
    return;
  }
  if (DAT_00205ae4 == 0x37) {
    if ((byte)((realtime < DAT_00205ad8 |
                (byte)((ushort)((ushort)(NAN(realtime) || NAN(DAT_00205ad8)) << 10) >> 8) |
               (byte)((ushort)((ushort)(realtime == DAT_00205ad8) << 0xe) >> 8)) - 1) < 0x40) {
      if (-1 < DAT_00205ae0) {
        return;
      }
    }
    else if (-1 < DAT_00205ae0) {
      DAT_00205ad8 = (double)((float)realtime + (float)(4 - DAT_00205ae0) * 5.0);
      apcStack_30[4] = (char *)0x8ac71;
      DAT_00205ae0 = DAT_00205ae0 + -1;
      CL_SendConnectPacket();
      return;
    }
    apcStack_30[3] = (char *)0x8ac8e;
    apcStack_30[4] = (char *)puVar2;
    WON_RemoveUser();
    apcStack_30[3] = "Connection failed after auth response\n";
    apcStack_30[2] = (char *)0x8ac9a;
    Con_Printf();
    return;
  }
  if (0x3f < (byte)((realtime < DAT_00205ad8 |
                     (byte)((ushort)((ushort)(NAN(realtime) || NAN(DAT_00205ad8)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(realtime == DAT_00205ad8) << 0xe) >> 8)) - 1)) {
    if (DAT_00205aec == 0) goto LAB_0008ad3c;
    if (-1 < DAT_00205ae0) {
      DAT_00205ad8 = (double)((float)realtime + (float)(4 - DAT_00205ae0) * 5.0);
      ppcVar3 = apcStack_30;
      for (iVar1 = 5; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar3 = (char *)*puVar2;
        ppcVar3 = ppcVar3 + 1;
      }
      DAT_00205ae0 = DAT_00205ae0 + -1;
      NET_SendPacket(0,DAT_00205ae8,DAT_00205aec);
      return;
    }
  }
  if (DAT_00205aec != 0) {
    if (-1 < DAT_00205ae0) {
      return;
    }
    apcStack_30[4] = (char *)0x3;
    apcStack_30[3] = "Server validation failed after %i retries";
    apcStack_30[2] = (char *)0x8ad39;
    Con_Printf();
  }
LAB_0008ad3c:
  apcStack_30[3] = (char *)0x8ad45;
  apcStack_30[4] = (char *)puVar2;
  WON_RemoveUser();
  apcStack_30[3] = (char *)0x8ad4a;
  CL_Disconnect_f();
  return;
}


// WON_HandleServerAuthMsgs  @ 0008aa9c
void WON_HandleServerAuthMsgs(void)

{
  double dVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int aiStack_7c [5];
  undefined1 *puStack_68;
  int aiStack_64 [2];
  undefined1 *puStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  int local_30;
  int local_28;
  undefined1 local_24 [32];
  
  piStack_54 = (int *)0x8aaaa;
  local_28 = 0;
  local_30 = 0;
  do {
    piVar3 = (int *)((int)&svauthstates + local_30);
    if (*piVar3 != 0) {
      dVar1 = *(double *)(&DAT_00203ed8 + local_30);
      if (0x3f < (byte)((realtime < dVar1 |
                         (byte)((ushort)((ushort)(NAN(realtime) || NAN(dVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(realtime == dVar1) << 0xe) >> 8)) - 1)) {
        if (*(int *)(&DAT_00203eec + local_30) == 0) goto LAB_0008abcf;
        iVar2 = *(int *)(&DAT_00203ee0 + local_30);
        if (-1 < iVar2) {
          *(int *)(&DAT_00203ee0 + local_30) = iVar2 + -1;
          *(double *)(&DAT_00203ed8 + local_30) =
               (double)((float)realtime + (float)(4 - iVar2) * 5.0);
          if (*(int *)(&DAT_00203ee8 + local_30) < 0x20) {
            piStack_54 = (int *)0x20;
            uStack_58 = 1;
            aiStack_64[1] = 0x8ab4f;
            puStack_5c = local_24;
            Q_memset();
            aiStack_64[1] = *(int *)(&DAT_00203ee8 + local_30);
            aiStack_64[0] = *(int *)(&DAT_00203eec + local_30);
            aiStack_7c[4] = 0x8ab66;
            puStack_68 = local_24;
            Q_memcpy();
            piVar4 = aiStack_7c;
            for (iVar2 = 5; piVar3 = piVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
              *piVar4 = *piVar3;
              piVar4 = piVar4 + 1;
            }
            NET_SendPacket(1,0x20,local_24);
          }
          else {
            piVar4 = aiStack_64;
            for (iVar2 = 5; piVar3 = piVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
              *piVar4 = *piVar3;
              piVar4 = piVar4 + 1;
            }
            puStack_68 = *(undefined1 **)(&DAT_00203eec + local_30);
            aiStack_7c[4] = *(int *)(&DAT_00203ee8 + local_30);
            aiStack_7c[3] = 1;
            aiStack_7c[2] = 0x8abba;
            NET_SendPacket();
          }
          goto LAB_0008abdc;
        }
      }
      if ((*(int *)(&DAT_00203eec + local_30) == 0) || (*(int *)(&DAT_00203ee0 + local_30) < 0)) {
LAB_0008abcf:
        uStack_58 = 0x8abd8;
        piStack_54 = piVar3;
        WON_RemoveUser();
        return;
      }
    }
LAB_0008abdc:
    local_30 = local_30 + 0x38;
    local_28 = local_28 + 1;
    if (0x7f < local_28) {
      return;
    }
  } while( true );
}


// WON_InitAuthentication  @ 0008a90c
void WON_InitAuthentication(void)

{
  Q_memset(&svauthstates,0,0x1c00);
  Q_memset(&clauthstate,0,0x38);
  return;
}


// WON_IsAuthMessage  @ 0008a21c
undefined4 WON_IsAuthMessage(byte param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x37) && (0x32 < param_1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// WON_ParseAuthenticationMessage  @ 0008a5c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WON_ParseAuthenticationMessage(char param_1)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int *piVar8;
  int aiStack_24 [3];
  undefined4 *puStack_18;
  code *pcStack_14;
  
  pcStack_14 = (code *)0x8a5cb;
  pcVar6 = (char *)0x0;
  if (param_1 == '3') {
    pcStack_14 = (code *)0xad22c;
    puStack_18 = (undefined4 *)0x8a5f8;
    Con_DPrintf();
    puStack_18 = &net_from;
    aiStack_24[2] = 1;
    aiStack_24[1] = 0x8a606;
    iVar5 = SV_FindAuthRequest();
    if (iVar5 == -1) {
      pcVar3 = FUN_000ad240;
      goto LAB_0008a6ea;
    }
    iVar1 = iVar5 * 0x38;
    pcVar6 = (char *)(&svauthstates + iVar5 * 0xe);
    if (*(int *)(&DAT_00203ee4 + iVar1) != 0x33) {
      *(undefined4 *)(&DAT_00203ee4 + iVar1) = 0x33;
    }
    puStack_18 = (undefined4 *)(DAT_00226fec + -5);
    aiStack_24[2] = DAT_00226fe4 + 5;
    aiStack_24[1] = 0x8a65b;
    pcStack_14 = (code *)pcVar6;
    iVar5 = (*_DAT_003861c4)();
    if (iVar5 == 2) {
      *(undefined4 *)(&DAT_00203ee0 + iVar1) = 3;
      uVar2 = realtime;
      *(undefined4 *)(&DAT_00203ee4 + iVar1) = 0x35;
      *(undefined8 *)(&DAT_00203ed8 + iVar1) = uVar2;
      return;
    }
    if (iVar5 != 1) {
      pcStack_14 = (code *)0xad2c0;
LAB_0008a756:
      puStack_18 = (undefined4 *)0x8a75c;
      Con_DPrintf();
      goto LAB_0008a75f;
    }
    pcStack_14 = (code *)0xad280;
  }
  else {
    if (param_1 != '5') goto LAB_0008a75f;
    pcStack_14 = (code *)0xad2f2;
    puStack_18 = (undefined4 *)0x8a6ac;
    Con_DPrintf();
    puStack_18 = &net_from;
    aiStack_24[2] = 0;
    aiStack_24[1] = 0x8a6ba;
    iVar5 = SV_FindAuthRequest();
    if (iVar5 == -1) {
      pcVar3 = FUN_000ad320;
LAB_0008a6ea:
      puStack_18 = (undefined4 *)0x8a6f0;
      pcStack_14 = pcVar3;
      Con_DPrintf();
      return;
    }
    iVar1 = iVar5 * 0x38;
    pcVar6 = (char *)(&svauthstates + iVar5 * 0xe);
    if (*(int *)(&DAT_00203ee4 + iVar1) != 0x35) {
      pcVar3 = (code *)"C2S_AUTHCHALLENGE2 out of sequence\n";
      goto LAB_0008a6ea;
    }
    puStack_18 = (undefined4 *)(DAT_00226fec + -5);
    aiStack_24[2] = DAT_00226fe4 + 5;
    aiStack_24[1] = 0x8a718;
    pcStack_14 = (code *)pcVar6;
    iVar5 = (*_DAT_003861cc)();
    if (iVar5 == 2) {
      *(undefined4 *)(&DAT_00203ee0 + iVar1) = 3;
      uVar2 = realtime;
      *(undefined4 *)(&DAT_00203ee4 + iVar1) = 0x37;
      *(undefined8 *)(&DAT_00203ed8 + iVar1) = uVar2;
      return;
    }
    if (iVar5 != 1) {
      pcStack_14 = (code *)0xad3a0;
      goto LAB_0008a756;
    }
    pcStack_14 = (code *)0xad384;
  }
  puStack_18 = (undefined4 *)0x8a74d;
  Con_Printf();
LAB_0008a75f:
  if (pcVar6 != (char *)0x0) {
    puStack_18 = (undefined4 *)0x8a769;
    pcStack_14 = (code *)pcVar6;
    WON_RemoveUser();
  }
  puVar7 = &net_from;
  piVar8 = aiStack_24;
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  uVar4 = NET_AdrToString();
  Con_Printf("Authentication failure on %s\n",uVar4);
  return;
}


// WON_RemoveUser  @ 0008aa68
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WON_RemoveUser(undefined4 param_1)

{
  (*_DAT_003861b8)(param_1);
  Q_memset(param_1,0,0x38);
  return;
}


// WON_RemoveUserbyAddress  @ 0008a240
void WON_RemoveUserbyAddress(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = SV_FindAuthRequest(0,param_1);
  if (iVar1 != -1) {
    WON_RemoveUser(&svauthstates + iVar1 * 0xe);
  }
  return;
}


// WON_ShutdownAuthentication  @ 0008a948
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WON_ShutdownAuthentication(void)

{
  int iVar1;
  int iVar2;
  
  (*_DAT_003861b8)(&clauthstate);
  iVar2 = 0;
  iVar1 = 0;
  do {
    (*_DAT_003861b8)((int)&svauthstates + iVar1);
    (*_DAT_003861b8)((int)&DAT_00203ef8 + iVar1);
    (*_DAT_003861b8)((int)&DAT_00203f30 + iVar1);
    (*_DAT_003861b8)((int)&DAT_00203f68 + iVar1);
    (*_DAT_003861b8)((int)&DAT_00203fa0 + iVar1);
    (*_DAT_003861b8)((int)&DAT_00203fd8 + iVar1);
    (*_DAT_003861b8)((int)&DAT_00204010 + iVar1);
    (*_DAT_003861b8)((int)&DAT_00204048 + iVar1);
    iVar1 = iVar1 + 0x1c0;
    iVar2 = iVar2 + 8;
  } while (iVar2 < 0x80);
  return;
}


