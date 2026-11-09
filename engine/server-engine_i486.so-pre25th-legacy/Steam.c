// Steam_Activate  @ 000d0050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_Activate(void)

{
  CSteam3Server *this;
  
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    CSteam3Server::Activate(s_Steam3Server);
    return;
  }
  this = operator_new(0xa8);
  CSteam3Server::CSteam3Server(this);
  s_Steam3Server = this;
  CSteam3Server::Activate(this);
  return;
}


// Steam_ClientRunFrame  @ 000d00f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_ClientRunFrame(void)

{
  SteamAPI_RunCallbacks();
  return;
}


// Steam_GSBLoggedOn  @ 000d02f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Steam_GSBLoggedOn(void)

{
  int *piVar1;
  uint uVar2;
  
  if ((s_Steam3Server->super_CSteam3).m_bLoggedOn == false) {
    return 0;
  }
  piVar1 = (int *)SteamGameServer();
  uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1);
  return uVar2 & 0xff;
}


// Steam_GSBSecure  @ 000d02d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Steam_GSBSecure(void)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)SteamGameServer();
  uVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
  return uVar2 & 0xff;
}


// Steam_GSBSecurePreference  @ 000d0320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Steam_GSBSecurePreference(void)

{
  return (uint)s_Steam3Server->m_bWantToBeSecure;
}


// Steam_GSGetSteamID  @ 000d02a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint64 Steam_GSGetSteamID(void)

{
  if (s_Steam3Server->m_bLanOnly != false) {
    return 0x100000000000000;
  }
  return (s_Steam3Server->m_SteamIDGS).m_steamid.m_unAll64Bits;
}


// Steam_GSInitiateGameConnection  @ 000d01c0
int Steam_GSInitiateGameConnection
              (void *pData,int cbMaxData,uint64 steamID,uint32 unIPServer,uint16 usPortServer,
              qboolean bSecure)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)SteamUser();
                    /* Unresolved local var: ushort __v@[DW_OP_reg3(EBX)]
                       Unresolved local var: ushort __x@[???] */
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
  iVar2 = (**(code **)(*piVar1 + 0xc))
                    (piVar1,pData,cbMaxData,steamID,
                     unIPServer >> 0x18 | (unIPServer & 0xff0000) >> 8 | (unIPServer & 0xff00) << 8
                     | unIPServer << 0x18,usPortServer >> 8 | usPortServer << 8,bSecure != 0);
  return iVar2;
}


// Steam_GSTerminateGameConnection  @ 000d0250
void Steam_GSTerminateGameConnection(uint32 unIPServer,uint16 usPortServer)

{
  int *piVar1;
  
  piVar1 = (int *)SteamUser();
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
  (**(code **)(*piVar1 + 0x10))
            (piVar1,unIPServer >> 0x18 | (unIPServer & 0xff0000) >> 8 | (unIPServer & 0xff00) << 8 |
                    unIPServer << 0x18,usPortServer >> 8 | usPortServer << 8);
  return;
}


// Steam_GetCommunityName  @ 000cfd00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Steam_GetCommunityName(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  iVar1 = SteamFriends();
  pcVar2 = (char *)0x0;
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)SteamFriends();
    pcVar2 = (char *)(**(code **)*puVar3)(puVar3);
  }
  return pcVar2;
}


// Steam_GetGSUniverse  @ 000d03e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Steam_GetGSUniverse(void)

{
  char *pcVar1;
  uint uVar2;
  
                    /* Unresolved local var: CSteamID steamID@[???] */
  uVar2 = 0x1000000;
  if (s_Steam3Server->m_bLanOnly == false) {
    uVar2 = *(uint *)((int)&(s_Steam3Server->m_SteamIDGS).m_steamid + 4);
  }
  pcVar1 = "(u)";
  uVar2 = (uVar2 >> 0x18) - 1;
  if (uVar2 < 3) {
    pcVar1 = (&CSWTCH_82)[uVar2];
  }
  return pcVar1;
}


// Steam_HandleIncomingPacket  @ 000d0530
void Steam_HandleIncomingPacket(byte *data,int len,int fromip,uint16 port)

{
  int *piVar1;
  
  piVar1 = (int *)SteamGameServer();
  (**(code **)(*piVar1 + 0x94))(piVar1,data,len,fromip,port);
  return;
}


// Steam_InitClient  @ 000d0100
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_InitClient(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  FILE *__stream;
  
  if (!s_Steam3Client.super_CSteam3.m_bLoggedOn) {
    s_Steam3Client.super_CSteam3.m_bLoggedOn = true;
    unlink("steam_appid.txt");
    pcVar2 = getenv("SteamAppId");
    if (pcVar2 == (char *)0x0) {
                    /* Unresolved local var: int nAppID@[???] */
      iVar3 = GetGameAppID();
      if (0 < iVar3) {
                    /* Unresolved local var: FILE * f@[???] */
        __stream = fopen("steam_appid.txt","w+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%d\n",iVar3);
          fclose(__stream);
        }
      }
    }
    cVar1 = SteamAPI_Init();
    if (cVar1 != '\0') {
      s_Steam3Client.super_CSteam3.m_bLogOnResult = false;
      return;
    }
    Sys_Error("Failed to initalize authentication interface. Exiting...\n");
  }
  return;
}


// Steam_NotifyBotConnect  @ 000cff20
qboolean Steam_NotifyBotConnect(client_t_conflict *cl)

{
  int *piVar1;
  undefined4 local_18;
  undefined4 local_14 [4];
  
  if (((s_Steam3Server != (CSteam3Server *)0x0) && (cl != (client_t_conflict *)0x0)) &&
     ((s_Steam3Server->super_CSteam3).m_bLoggedOn != false)) {
    (cl->network_userid).idtype = 3;
    piVar1 = (int *)SteamGameServer();
    (**(code **)(*piVar1 + 100))(local_14,piVar1);
    *(undefined4 *)&(cl->network_userid).m_SteamID = local_18;
    *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4) = local_14[0];
    return 1;
  }
  return 0;
}


// Steam_NotifyClientConnect  @ 000cfee0
qboolean Steam_NotifyClientConnect(client_t_conflict *cl,void *pvSteam2Key,uint ucbSteam2Key)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    bVar1 = CSteam3Server::NotifyClientConnect(s_Steam3Server,cl,pvSteam2Key,ucbSteam2Key);
    uVar2 = (uint)bVar1;
  }
  return uVar2;
}


// Steam_NotifyClientDisconnect  @ 000cff90
void Steam_NotifyClientDisconnect(client_t_conflict *cl)

{
  int iVar1;
  int *piVar2;
  
  if ((((s_Steam3Server != (CSteam3Server *)0x0) && (cl != (client_t_conflict *)0x0)) &&
      ((s_Steam3Server->super_CSteam3).m_bLoggedOn != false)) &&
     ((iVar1 = (cl->network_userid).idtype, iVar1 == 3 || (iVar1 == 1)))) {
    piVar2 = (int *)SteamGameServer();
    (**(code **)(*piVar2 + 0x68))
              (piVar2,(int)(cl->network_userid).m_SteamID,
               *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4));
    return;
  }
  return;
}


// Steam_NotifyOfLevelChange  @ 000cfff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_NotifyOfLevelChange(void)

{
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    CSteam3Server::NotifyOfLevelChange(s_Steam3Server,false);
  }
  return;
}


// Steam_RunFrame  @ 000d00a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_RunFrame(void)

{
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    CSteam3Server::RunFrame(s_Steam3Server);
  }
  return;
}


// Steam_SetCVar  @ 000d00c0
void Steam_SetCVar(char *pchKey,char *pchValue)

{
  int *piVar1;
  
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    piVar1 = (int *)SteamGameServer();
    (**(code **)(*piVar1 + 0x50))(piVar1,pchKey,pchValue);
  }
  return;
}


// Steam_Shutdown  @ 000d0010
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_Shutdown(void)

{
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    (*(s_Steam3Server->super_CSteam3)._vptr_CSteam3[2])(s_Steam3Server);
    if (s_Steam3Server != (CSteam3Server *)0x0) {
      (*(s_Steam3Server->super_CSteam3)._vptr_CSteam3[1])(s_Steam3Server);
    }
    s_Steam3Server = (CSteam3Server *)0x0;
  }
  return;
}


// Steam_ShutdownClient  @ 000d0280
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Steam_ShutdownClient(void)

{
  (*s_Steam3Client.super_CSteam3._vptr_CSteam3[2])(&s_Steam3Client);
  return;
}


// Steam_Steam3IDtoSteam2  @ 000d0330
TSteamGlobalUserID_conflict *
Steam_Steam3IDtoSteam2(TSteamGlobalUserID_conflict *__return_storage_ptr__,uint64 unSteamID)

{
                    /* Unresolved local var: CSteamID steamID@[???]
                       Unresolved local var: TSteamGlobalUserID.conflict steam2ID@[???] */
  __return_storage_ptr__->m_SteamInstanceID = 0;
  (__return_storage_ptr__->m_SteamLocalUserID).Split.High32bits = (uint)unSteamID & 1;
  (__return_storage_ptr__->m_SteamLocalUserID).Split.Low32bits = (uint)unSteamID >> 1;
  return __return_storage_ptr__;
}


// Steam_StringToSteamID  @ 000d0350
uint64 Steam_StringToSteamID(char *pStr)

{
  uint uVar1;
  SteamID_t local_1c [3];
  
                    /* Unresolved local var: CSteamID steamID@[???] */
  local_1c[0].m_comp.m_unAccountID = 0;
  local_1c[0].m_unAll64Bits._4_2_ = 0;
  local_1c[0].m_unAll64Bits._6_1_ = 0;
  local_1c[0].m_comp.m_EUniverse = 0;
  if (s_Steam3Server != (CSteam3Server *)0x0) {
    uVar1 = 0x1000000;
    if (s_Steam3Server->m_bLanOnly == false) {
      uVar1 = *(uint *)((int)&(s_Steam3Server->m_SteamIDGS).m_steamid + 4);
    }
    CSteamID::SetFromSteam2String((CSteamID *)&local_1c[0].m_comp,pStr,uVar1 >> 0x18);
    return CONCAT17(local_1c[0].m_comp.m_EUniverse,
                    CONCAT16(local_1c[0].m_unAll64Bits._6_1_,
                             CONCAT24(local_1c[0].m_unAll64Bits._4_2_,
                                      local_1c[0].m_comp.m_unAccountID)));
  }
  CSteamID::SetFromSteam2String((CSteamID *)&local_1c[0].m_comp,pStr,k_EUniversePublic);
  return CONCAT17(local_1c[0].m_comp.m_EUniverse,
                  CONCAT16(local_1c[0].m_unAll64Bits._6_1_,
                           CONCAT24(local_1c[0].m_unAll64Bits._4_2_,local_1c[0].m_comp.m_unAccountID
                                   )));
}


