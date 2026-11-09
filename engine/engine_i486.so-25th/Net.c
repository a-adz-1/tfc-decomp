// Net_CheckOpenFakeUDPPorts  @ 000bac50
void Net_CheckOpenFakeUDPPorts(qboolean bClient)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
  if (bClient == 0) {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamGameServerNetworkingSockets_SteamAPI::
                               s_CallbackCounterAndContext_1);
    piVar1 = (int *)*piVar1;
                    /* Unresolved local var: bool bLanOnly@[???] */
    if ((piVar1 != (int *)0x0) && (sv_lan.value <= 0.0)) {
                    /* Unresolved local var: bool bLanOnly@[???] */
      iVar2 = PF_IsDedicatedServer();
      if ((iVar2 == 0) &&
         ((0.0 < sv_use_steam_networking.value &&
          (ip_fakeudpports[1] == (ISteamNetworkingFakeUDPPort *)0x0)))) {
        ip_fakeudpports[1] = (ISteamNetworkingFakeUDPPort *)(**(code **)(*piVar1 + 0xb8))(piVar1,0);
        if (ip_fakeudpports[1] == (ISteamNetworkingFakeUDPPort *)0x0) {
          Con_Printf("Failed to create fake UDP port, module %d fake port idx %d",1,0);
        }
      }
    }
  }
  else {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamNetworkingSockets_SteamAPI::s_CallbackCounterAndContext);
    piVar1 = (int *)*piVar1;
    if ((piVar1 != (int *)0x0) && (ip_fakeudpports[0] == (ISteamNetworkingFakeUDPPort *)0x0)) {
      ip_fakeudpports[0] =
           (ISteamNetworkingFakeUDPPort *)(**(code **)(*piVar1 + 0xb8))(piVar1,0xffffffff);
      if (ip_fakeudpports[0] == (ISteamNetworkingFakeUDPPort *)0x0) {
        Con_Printf("Failed to create fake UDP port, module %d fake port idx %d",0,0xffffffff);
      }
    }
  }
  return;
}


// Net_CloseFakeUDPPorts  @ 000bad50
void Net_CloseFakeUDPPorts(qboolean bClient)

{
  int *piVar1;
  
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
  if (bClient == 0) {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamGameServerNetworkingSockets_SteamAPI::
                               s_CallbackCounterAndContext_1);
    if (*piVar1 != 0) {
                    /* Unresolved local var: bool bLanOnly@[???] */
      if (sv_lan.value <= 0.0) {
                    /* Unresolved local var: bool bLanOnly@[???] */
        PF_IsDedicatedServer();
      }
      if (ip_fakeudpports[1] != (ISteamNetworkingFakeUDPPort *)0x0) {
        (*(code *)**(undefined4 **)ip_fakeudpports[1])(ip_fakeudpports[1]);
        ip_fakeudpports[1] = (ISteamNetworkingFakeUDPPort *)0x0;
        return;
      }
    }
  }
  else {
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamNetworkingSockets_SteamAPI::s_CallbackCounterAndContext);
    if ((*piVar1 != 0) && (ip_fakeudpports[0] != (ISteamNetworkingFakeUDPPort *)0x0)) {
      (*(code *)**(undefined4 **)ip_fakeudpports[0])(ip_fakeudpports[0]);
      ip_fakeudpports[0] = (ISteamNetworkingFakeUDPPort *)0x0;
    }
  }
  return;
}


// Net_PollSteamFakeIPResult  @ 000bade0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Net_PollSteamFakeIPResult(void)

{
  netadr_t a;
  netadr_t a_00;
  short sVar1;
  int *piVar2;
  int32 iVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  uint local_b0 [35];
  uint32 local_24;
  uint16 local_20;
  int local_10;
  
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                       Unresolved local var: SteamNetworkingFakeIPResult_t result@[???]
                       Unresolved local var: netadr_t.conflict adr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  piVar2 = (int *)SteamInternal_ContextInit
                            (SteamGameServerNetworkingSockets_SteamAPI::
                             s_CallbackCounterAndContext_1);
  piVar2 = (int *)*piVar2;
  if ((g_nFakeIP == 0) && (piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 0xac))(piVar2,0,local_b0);
    if ((local_b0[0] & 0xffffffdf) != 10) {
      if (local_b0[0] != 1) {
        Sys_Error("FakeIP allocation failed with error code %d",local_b0[0]);
      }
      g_nFakeIP = local_24;
      iVar3 = (*BigLong)(local_24);
      sVar1 = (*BigShort)(local_20);
      a.ip[0] = (char)iVar3;
      a.ip[1] = (char)((uint)iVar3 >> 8);
      a.ip[2] = (char)((uint)iVar3 >> 0x10);
      a.ip[3] = (char)((uint)iVar3 >> 0x18);
      a.type = 3;
      a.ipx._0_4_ = local_bc;
      a.ipx._4_4_ = local_b8;
      a.ipx[8] = (undefined1)local_b4;
      a.ipx[9] = local_b4._1_1_;
      a.port = sVar1;
      pcVar4 = NET_AdrToString(a);
      Con_Printf("FakeIP allocation succeeded: %s",pcVar4);
      a_00.ip[0] = (char)iVar3;
      a_00.ip[1] = (char)((uint)iVar3 >> 8);
      a_00.ip[2] = (char)((uint)iVar3 >> 0x10);
      a_00.ip[3] = (char)((uint)iVar3 >> 0x18);
      a_00.type = 3;
      a_00.ipx._0_4_ = local_bc;
      a_00.ipx._4_4_ = local_b8;
      a_00.ipx[8] = (undefined1)local_b4;
      a_00.ipx[9] = local_b4._1_1_;
      a_00.port = sVar1;
      pcVar4 = NET_AdrToString(a_00);
      Log_Printf("FakeIP allocation succeeded: %s",pcVar4);
                    /* Unresolved local var: int i@[???] */
      g_arFakePorts[0] = local_20;
      Con_Printf("\n");
      Log_Printf("\n");
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


