// WON_CheckAuthentication  @ 000c9994
undefined4 WON_CheckAuthentication(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 local_818;
  int local_814;
  undefined1 local_810 [1024];
  int local_410;
  undefined1 local_40c [1024];
  undefined1 *local_c;
  int local_8;
  
  local_c = (undefined1 *)0x0;
  local_818 = 0;
  *param_3 = 0xffffffff;
  local_8 = SV_FindAuthRequest(0,param_1);
  if (local_8 == -1) {
    local_818 = 0;
  }
  else {
    local_c = svauthstates + local_8 * 0x38;
    if (*(int *)(svauthstates + local_8 * 0x38 + 0x30) != 0) {
      puVar3 = local_40c;
      uVar1 = Q_strlen(param_2);
      COM_HexConvert(param_2,uVar1,puVar3);
      local_410 = Q_strlen(param_2);
      local_410 = local_410 / 2;
      iVar2 = (*(code *)crypt._20_4_)(*(undefined4 *)(local_c + 0x30),local_810,&local_814);
      if ((iVar2 != 0) && (local_814 == local_410)) {
        iVar2 = Q_memcmp(local_810,local_40c,local_410);
        if (iVar2 == 0) {
          local_818 = 1;
          *param_3 = *(undefined4 *)(local_c + 0x34);
        }
      }
    }
    WON_RemoveUser(local_c);
  }
  return local_818;
}


// WON_GetUseridForAddress  @ 000c991c
undefined4 WON_GetUseridForAddress(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = SV_FindAuthRequest(0,param_1);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(svauthstates + iVar1 * 0x38 + 0x34);
  }
  return uVar2;
}


// WON_HandleClientAuthMsgs  @ 000ca510
void WON_HandleClientAuthMsgs(void)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  char *apcStack_50 [4];
  undefined4 uStack_40;
  
  uStack_40 = 0xca51e;
  puVar2 = &clauthstate;
  if (clauthstate != 0) {
    if (DAT_0059f704 == 0x37) {
      if (((byte)(DAT_0059f6f8 < realtime |
                  (byte)((ushort)((ushort)(NAN(DAT_0059f6f8) || NAN(realtime)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(DAT_0059f6f8 == realtime) << 0xe) >> 8)) == 1) &&
         (-1 < DAT_0059f700)) {
        DAT_0059f700 = DAT_0059f700 + -1;
        DAT_0059f6f8 = (double)((float)realtime + (float)(3 - DAT_0059f700) * 5.0);
        uStack_40 = 0xca5a6;
        CL_SendConnectPacket();
      }
      else if (DAT_0059f700 < 0) {
        apcStack_50[0] = (char *)0xca5bd;
        apcStack_50[1] = (char *)puVar2;
        WON_RemoveUser();
        apcStack_50[1] = "Connection failed after auth response\n";
        apcStack_50[0] = (char *)0xca5d1;
        Con_Printf();
      }
    }
    else if ((((byte)(DAT_0059f6f8 < realtime |
                      (byte)((ushort)((ushort)(NAN(DAT_0059f6f8) || NAN(realtime)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(DAT_0059f6f8 == realtime) << 0xe) >> 8)) == 1) &&
             (DAT_0059f70c != 0)) && (-1 < DAT_0059f700)) {
      DAT_0059f700 = DAT_0059f700 + -1;
      DAT_0059f6f8 = (double)((float)realtime + (float)(3 - DAT_0059f700) * 5.0);
      ppcVar3 = apcStack_50;
      for (iVar1 = 5; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar3 = (char *)*puVar2;
        ppcVar3 = ppcVar3 + 1;
      }
      NET_SendPacket(0,DAT_0059f708,DAT_0059f70c);
    }
    else if ((DAT_0059f70c == 0) || (DAT_0059f700 < 0)) {
      if (DAT_0059f70c != 0) {
        apcStack_50[2] = (char *)0x3;
        apcStack_50[1] = "Server validation failed after %i retries";
        apcStack_50[0] = (char *)0xca6a0;
        Con_Printf();
      }
      apcStack_50[0] = (char *)0xca6af;
      apcStack_50[1] = (char *)puVar2;
      WON_RemoveUser();
      uStack_40 = 0xca6b7;
      CL_Disconnect_f();
    }
  }
  return;
}


// WON_HandleServerAuthMsgs  @ 000ca380
void WON_HandleServerAuthMsgs(void)

{
  double dVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iStack_70;
  int *piStack_6c;
  int iStack_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined1 local_2c [32];
  int *local_c;
  int local_8;
  
  uStack_60 = 0xca38e;
  local_8 = 0;
  do {
    if (0x7f < local_8) {
      return;
    }
    iVar2 = local_8 * 0x38;
    piVar3 = (int *)(svauthstates + iVar2);
    if (*piVar3 != 0) {
      dVar1 = *(double *)(svauthstates + iVar2 + 0x18);
      local_c = piVar3;
      if ((((byte)(dVar1 < realtime |
                   (byte)((ushort)((ushort)(NAN(dVar1) || NAN(realtime)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(dVar1 == realtime) << 0xe) >> 8)) == 1) &&
          (*(int *)(svauthstates + iVar2 + 0x2c) != 0)) &&
         (-1 < *(int *)(svauthstates + iVar2 + 0x20))) {
        *(int *)(svauthstates + iVar2 + 0x20) = *(int *)(svauthstates + iVar2 + 0x20) + -1;
        *(double *)(svauthstates + iVar2 + 0x18) =
             (double)((float)realtime + (float)(3 - *(int *)(svauthstates + iVar2 + 0x20)) * 5.0);
        if (*(int *)(svauthstates + iVar2 + 0x28) < 0x20) {
          iStack_64 = 0x20;
          iStack_68 = 1;
          piStack_6c = (int *)local_2c;
          iStack_70 = 0xca45e;
          Q_memset();
          iStack_64 = local_c[10];
          iStack_68 = local_c[0xb];
          piStack_6c = (int *)local_2c;
          iStack_70 = 0xca47b;
          Q_memcpy();
          piVar4 = &iStack_70;
          piVar3 = local_c;
          for (iVar2 = 5; piVar3 = piVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
            *piVar4 = *piVar3;
            piVar4 = piVar4 + 1;
          }
          NET_SendPacket(1,0x20,local_2c);
        }
        else {
          piVar4 = &iStack_70;
          for (iVar2 = 5; piVar3 = piVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
            *piVar4 = *piVar3;
            piVar4 = piVar4 + 1;
          }
          NET_SendPacket(1,local_c[10],local_c[0xb]);
        }
      }
      else if ((*(int *)(svauthstates + iVar2 + 0x2c) == 0) ||
              (*(int *)(svauthstates + iVar2 + 0x20) < 0)) {
        iStack_70 = 0xca4f4;
        piStack_6c = piVar3;
        WON_RemoveUser();
        return;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// WON_InitAuthentication  @ 000ca24c
void WON_InitAuthentication(void)

{
  Q_memset(svauthstates,0,0x1c00);
  Q_memset(&clauthstate,0,0x38);
  return;
}


// WON_IsAuthMessage  @ 000c9878
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


// WON_ParseAuthenticationMessage  @ 000c9cdc
void WON_ParseAuthenticationMessage(char param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_54 [5];
  undefined4 uStack_40;
  char *pcStack_3c;
  undefined4 *puStack_38;
  char *pcStack_34;
  undefined4 uStack_30;
  char *local_14;
  
  uStack_30 = 0xc9cea;
  if ((crypt._36_4_ == 0) || (crypt._44_4_ == 0)) {
    pcStack_3c = "Cyrpt interface not initialized\n";
    uStack_40 = 0xc9d29;
    Con_DPrintf();
    return;
  }
  local_14 = (char *)0x0;
  if (param_1 == '3') {
    pcStack_3c = "C2S_AUTHREQUEST1\n";
    uStack_40 = 0xc9d65;
    Con_DPrintf();
    puStack_38 = &net_from;
    pcStack_3c = (char *)0x1;
    uStack_40 = 0xc9d7b;
    iVar2 = SV_FindAuthRequest();
    if (iVar2 == -1) {
      pcStack_3c = "C2S_AUTHREQUEST1 from unknown address\n";
      uStack_40 = 0xc9d9a;
      Con_DPrintf();
      return;
    }
    iVar2 = iVar2 * 0x38;
    local_14 = svauthstates + iVar2;
    if (*(int *)(svauthstates + iVar2 + 0x24) != 0x33) {
      *(undefined4 *)(svauthstates + iVar2 + 0x24) = 0x33;
    }
    puStack_38 = (undefined4 *)(DAT_0059d8d0 + -5);
    pcStack_3c = (char *)(DAT_0059d8c8 + 5);
    uStack_40 = 0xc9e06;
    pcStack_34 = local_14;
    iVar1 = (*(code *)crypt._36_4_)();
    if (iVar1 == 2) {
      *(undefined4 *)(svauthstates + iVar2 + 0x20) = 3;
      *(undefined8 *)(svauthstates + iVar2 + 0x18) = realtime;
      *(undefined4 *)(svauthstates + iVar2 + 0x24) = 0x35;
      return;
    }
    if (iVar1 == 1) {
      pcStack_3c = "C2S_AUTHREQUEST1:  Client request invalid\n";
      uStack_40 = 0xc9e57;
      Con_Printf();
    }
    else {
      pcStack_3c = "C2S_AUTHREQUEST1:  Unable to parse Auth request.\n";
      uStack_40 = 0xc9e6d;
      Con_DPrintf();
    }
  }
  else if (param_1 == '5') {
    pcStack_3c = "C2S_AUTHCHALLENGE2\n";
    uStack_40 = 0xc9e89;
    Con_DPrintf();
    puStack_38 = &net_from;
    pcStack_3c = (char *)0x0;
    uStack_40 = 0xc9e9f;
    iVar2 = SV_FindAuthRequest();
    if (iVar2 == -1) {
      pcStack_3c = "C2S_AUTHCHALLENGE2 from unknown address\n";
      uStack_40 = 0xc9ebe;
      Con_DPrintf();
      return;
    }
    iVar2 = iVar2 * 0x38;
    local_14 = svauthstates + iVar2;
    if (*(int *)(svauthstates + iVar2 + 0x24) != 0x35) {
      pcStack_3c = "C2S_AUTHCHALLENGE2 out of sequence\n";
      uStack_40 = 0xc9f05;
      Con_DPrintf();
      return;
    }
    puStack_38 = (undefined4 *)(DAT_0059d8d0 + -5);
    pcStack_3c = (char *)(DAT_0059d8c8 + 5);
    uStack_40 = 0xc9f3c;
    pcStack_34 = local_14;
    iVar1 = (*(code *)crypt._44_4_)();
    if (iVar1 == 2) {
      *(undefined4 *)(svauthstates + iVar2 + 0x20) = 3;
      *(undefined8 *)(svauthstates + iVar2 + 0x18) = realtime;
      *(undefined4 *)(svauthstates + iVar2 + 0x24) = 0x37;
      return;
    }
    if (iVar1 == 1) {
      pcStack_3c = "Client Challenge 2 invalid\n";
      uStack_40 = 0xc9f8b;
      Con_Printf();
    }
    else {
      pcStack_3c = "C2S_AUTHCHALLENGE2:  Unable to parse Auth challenge 2.\n";
      uStack_40 = 0xc9fa1;
      Con_DPrintf();
    }
  }
  if (local_14 != (char *)0x0) {
    pcStack_3c = local_14;
    uStack_40 = 0xc9fba;
    WON_RemoveUser();
  }
  puVar3 = &net_from;
  puVar4 = auStack_54;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puStack_38 = (undefined4 *)NET_AdrToString();
  pcStack_3c = "Authentication failure on %s\n";
  uStack_40 = 0xc9ff1;
  Con_Printf();
  return;
}


// WON_RemoveUser  @ 000ca32c
void WON_RemoveUser(undefined4 param_1)

{
  if (crypt._24_4_ != 0) {
    (*(code *)crypt._24_4_)(param_1);
    Q_memset(param_1,0,0x38);
  }
  return;
}


// WON_RemoveUserbyAddress  @ 000c98ac
void WON_RemoveUserbyAddress(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = SV_FindAuthRequest(0,param_1);
  if (iVar1 != -1) {
    WON_RemoveUser(svauthstates + iVar1 * 0x38);
  }
  return;
}


// WON_ShutdownAuthentication  @ 000ca29c
void WON_ShutdownAuthentication(void)

{
  int local_8;
  
  if (crypt._24_4_ != 0) {
    (*(code *)crypt._24_4_)(&clauthstate);
    for (local_8 = 0; local_8 < 0x80; local_8 = local_8 + 1) {
      (*(code *)crypt._24_4_)(svauthstates + local_8 * 0x38);
    }
  }
  return;
}


