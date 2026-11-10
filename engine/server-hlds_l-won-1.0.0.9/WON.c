// WON_CheckAuthentication  @ 080818e0
undefined4 WON_CheckAuthentication(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  uint local_808;
  char local_804 [1024];
  char local_404 [1024];
  
  iVar2 = SV_FindAuthRequest(0,param_1);
  if (iVar2 != -1) {
    if (*(int *)(&DAT_08176890 + iVar2 * 0x34) != 0) {
      uVar4 = 0xffffffff;
      pcVar5 = param_2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      COM_HexConvert(param_2,~uVar4 - 1,local_404);
      uVar4 = 0xffffffff;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *param_2;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4 - 1 >> 1;
      iVar3 = (*Launcher_GetRawBFKey)
                        (*(undefined4 *)(&DAT_08176890 + iVar2 * 0x34),local_804,&local_808);
      if ((iVar3 != 0) && (local_808 == uVar4)) {
        bVar7 = true;
        pcVar5 = local_804;
        pcVar6 = local_404;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          bVar7 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          WON_RemoveUser(&svauthstates + iVar2 * 0xd);
          return 1;
        }
      }
    }
    WON_RemoveUser(&svauthstates + iVar2 * 0xd);
  }
  return 0;
}


// WON_HandleClientAuthMsgs  @ 08082050
void WON_HandleClientAuthMsgs(void)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  char *apcStack_24 [5];
  
  if (clauthstate == 0) {
    return;
  }
  if (DAT_08178284 == 0x37) {
    if ((byte)(DAT_08178278 < realtime |
               (byte)((ushort)((ushort)(NAN(DAT_08178278) || NAN(realtime)) << 10) >> 8) |
              (byte)((ushort)((ushort)(DAT_08178278 == realtime) << 0xe) >> 8)) == 1) {
      if (-1 < DAT_08178280) {
        DAT_08178280 = DAT_08178280 + -1;
        DAT_08178278 = (double)((float)(3 - DAT_08178280) * 5.0 + (float)realtime);
        apcStack_24[4] = (char *)0x80820ad;
        CL_SendConnectPacket();
        return;
      }
    }
    else if (-1 < DAT_08178280) {
      return;
    }
    apcStack_24[4] = (char *)&clauthstate;
    apcStack_24[3] = (char *)0x80820d0;
    WON_RemoveUser();
    apcStack_24[3] = "Connection failed after auth response\n";
    apcStack_24[2] = (char *)0x80820da;
    Con_Printf();
    return;
  }
  if ((byte)(DAT_08178278 < realtime |
             (byte)((ushort)((ushort)(NAN(DAT_08178278) || NAN(realtime)) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_08178278 == realtime) << 0xe) >> 8)) == 1) {
    if (DAT_0817828c == 0) goto LAB_08082171;
    if (-1 < DAT_08178280) {
      DAT_08178280 = DAT_08178280 + -1;
      apcStack_24[4] = (char *)(3 - DAT_08178280);
      DAT_08178278 = (double)((float)(int)apcStack_24[4] * 5.0 + (float)realtime);
      puVar2 = &DAT_08178264;
      ppcVar3 = apcStack_24;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar3 = (char *)*puVar2;
        puVar2 = puVar2 + 1;
        ppcVar3 = ppcVar3 + 1;
      }
      NET_SendPacket(0,DAT_08178288,DAT_0817828c);
      return;
    }
  }
  if (DAT_0817828c != 0) {
    if (-1 < DAT_08178280) {
      return;
    }
    if (DAT_0817828c != 0) {
      apcStack_24[4] = (char *)0x3;
      apcStack_24[3] = "Server validation failed after %i retries";
      apcStack_24[2] = (char *)0x808216e;
      Con_Printf();
    }
  }
LAB_08082171:
  apcStack_24[4] = (char *)&clauthstate;
  apcStack_24[3] = (char *)0x8082177;
  WON_RemoveUser();
  apcStack_24[3] = (char *)0x808217c;
  CL_Disconnect_f();
  return;
}


// WON_HandleServerAuthMsgs  @ 08081f00
void WON_HandleServerAuthMsgs(void)

{
  double dVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_5c [2];
  int local_28;
  undefined1 local_24 [32];
  
  local_28 = 0;
  do {
    iVar2 = local_28 * 0x34;
    if ((&svauthstates)[local_28 * 0xd] != 0) {
      dVar1 = *(double *)(&DAT_08176878 + iVar2);
      if ((byte)(dVar1 < realtime |
                 (byte)((ushort)((ushort)(NAN(dVar1) || NAN(realtime)) << 10) >> 8) |
                (byte)((ushort)((ushort)(dVar1 == realtime) << 0xe) >> 8)) == 1) {
        if (*(int *)(&DAT_0817688c + iVar2) == 0) goto LAB_0808201c;
        if (-1 < *(int *)(&DAT_08176880 + iVar2)) {
          *(int *)(&DAT_08176880 + iVar2) = *(int *)(&DAT_08176880 + iVar2) + -1;
          *(double *)(&DAT_08176878 + iVar2) =
               (double)((float)(3 - *(int *)(&DAT_08176880 + iVar2)) * 5.0 + (float)realtime);
          if (*(int *)(&DAT_08176888 + iVar2) < 0x20) {
            memset(local_24,1,0x20);
            auStack_5c[1] = 0x8081fac;
            memcpy(local_24,*(void **)(&DAT_0817688c + iVar2),*(size_t *)(&DAT_08176888 + iVar2));
            puVar4 = &DAT_08176864 + local_28 * 0xd;
            puVar5 = auStack_5c;
            for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar5 = puVar5 + 1;
            }
            NET_SendPacket(1,0x20,local_24);
          }
          else {
            puVar4 = &DAT_08176864 + local_28 * 0xd;
            puVar5 = (undefined4 *)&stack0xffffffb0;
            for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar5 = puVar5 + 1;
            }
            auStack_5c[1] = *(undefined4 *)(&DAT_08176888 + iVar2);
            auStack_5c[0] = 1;
            NET_SendPacket();
          }
          goto LAB_08082030;
        }
      }
      if ((*(int *)(&DAT_0817688c + iVar2) == 0) || (*(int *)(&DAT_08176880 + iVar2) < 0)) {
LAB_0808201c:
        WON_RemoveUser();
        return;
      }
    }
LAB_08082030:
    local_28 = local_28 + 1;
    if (0x7f < local_28) {
      return;
    }
  } while( true );
}


// WON_InitAuthentication  @ 08081e60
void WON_InitAuthentication(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &svauthstates;
  for (iVar1 = 0x680; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &clauthstate;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// WON_IsAuthMessage  @ 08081880
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


// WON_ParseAuthenticationMessage  @ 08081ae0
void WON_ParseAuthenticationMessage(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int *piVar6;
  int aiStack_20 [3];
  undefined4 *puStack_14;
  char *pcStack_10;
  
  pcVar4 = (char *)0x0;
  if (param_1 == '3') {
    pcStack_10 = "C2S_AUTHREQUEST1\n";
    puStack_14 = (undefined4 *)0x8081b0a;
    Con_DPrintf();
    puStack_14 = &net_from;
    aiStack_20[2] = 1;
    aiStack_20[1] = 0x8081b16;
    iVar3 = SV_FindAuthRequest();
    if (iVar3 == -1) {
      pcStack_10 = "C2S_AUTHREQUEST1 from unknown address\n";
      puStack_14 = (undefined4 *)0x8081b2a;
      Con_DPrintf();
      return;
    }
    iVar1 = iVar3 * 0x34;
    pcVar4 = (char *)(&svauthstates + iVar3 * 0xd);
    if (*(int *)(&DAT_08176884 + iVar1) != 0x33) {
      *(undefined4 *)(&DAT_08176884 + iVar1) = 0x33;
    }
    puStack_14 = (undefined4 *)(net_message._16_4_ + -5);
    aiStack_20[2] = net_message._8_4_ + 5;
    aiStack_20[1] = 0x8081b64;
    pcStack_10 = pcVar4;
    iVar3 = (*Launcher_AuthChallenge1)();
    if (iVar3 == 2) {
      *(undefined4 *)(&DAT_08176880 + iVar1) = 3;
      *(undefined8 *)(&DAT_08176878 + iVar1) = realtime;
      *(undefined4 *)(&DAT_08176884 + iVar1) = 0x35;
      return;
    }
    if (iVar3 == 1) {
      pcStack_10 = "C2S_AUTHREQUEST1:  Client request invalid\n";
      puStack_14 = (undefined4 *)0x8081b9f;
      Con_Printf();
      goto LAB_08081c8d;
    }
    pcStack_10 = "C2S_AUTHREQUEST1:  Unable to parse Auth request.\n";
  }
  else {
    if (param_1 != '5') goto LAB_08081c8d;
    pcStack_10 = "C2S_AUTHCHALLENGE2\n";
    puStack_14 = (undefined4 *)0x8081bca;
    Con_DPrintf();
    puStack_14 = &net_from;
    aiStack_20[2] = 0;
    aiStack_20[1] = 0x8081bd6;
    iVar3 = SV_FindAuthRequest();
    if (iVar3 == -1) {
      pcStack_10 = "C2S_AUTHCHALLENGE2 from unknown address\n";
      puStack_14 = (undefined4 *)0x8081bea;
      Con_DPrintf();
      return;
    }
    iVar1 = iVar3 * 0x34;
    pcVar4 = (char *)(&svauthstates + iVar3 * 0xd);
    if (*(int *)(&DAT_08176884 + iVar1) != 0x35) {
      pcStack_10 = "C2S_AUTHCHALLENGE2 out of sequence\n";
      puStack_14 = (undefined4 *)0x8081c0d;
      Con_DPrintf();
      return;
    }
    puStack_14 = (undefined4 *)(net_message._16_4_ + -5);
    aiStack_20[2] = net_message._8_4_ + 5;
    aiStack_20[1] = 0x8081c3a;
    pcStack_10 = pcVar4;
    iVar3 = (*Launcher_AuthComplete)();
    if (iVar3 == 2) {
      *(undefined4 *)(&DAT_08176880 + iVar1) = 3;
      *(undefined8 *)(&DAT_08176878 + iVar1) = realtime;
      *(undefined4 *)(&DAT_08176884 + iVar1) = 0x37;
      return;
    }
    if (iVar3 == 1) {
      pcStack_10 = "Client Challenge 2 invalid\n";
      puStack_14 = (undefined4 *)0x8081c6f;
      Con_Printf();
      goto LAB_08081c8d;
    }
    pcStack_10 = "C2S_AUTHCHALLENGE2:  Unable to parse Auth challenge 2.\n";
  }
  puStack_14 = (undefined4 *)0x8081c8a;
  Con_DPrintf();
LAB_08081c8d:
  if (pcVar4 != (char *)0x0) {
    puStack_14 = (undefined4 *)0x8081c97;
    pcStack_10 = pcVar4;
    WON_RemoveUser();
  }
  puVar5 = &net_from;
  piVar6 = aiStack_20;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    piVar6 = piVar6 + 1;
  }
  uVar2 = NET_AdrToString();
  Con_Printf("Authentication failure on %s\n",uVar2);
  return;
}


// WON_RemoveUser  @ 08081ed0
void WON_RemoveUser(undefined4 *param_1)

{
  int iVar1;
  
  (*Launcher_DeleteAuthData)(param_1);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}


// WON_RemoveUserbyAddress  @ 080818b0
void WON_RemoveUserbyAddress(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = SV_FindAuthRequest(0,param_1);
  if (iVar1 != -1) {
    WON_RemoveUser(&svauthstates + iVar1 * 0xd);
  }
  return;
}


// WON_ShutdownAuthentication  @ 08081e90
void WON_ShutdownAuthentication(void)

{
  int iVar1;
  
  (*Launcher_DeleteAuthData)(&clauthstate);
  iVar1 = 0;
  do {
    (*Launcher_DeleteAuthData)(&svauthstates + iVar1 * 0xd);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  return;
}


