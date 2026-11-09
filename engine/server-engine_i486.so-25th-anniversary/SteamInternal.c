// SteamInternal_Init_SteamApps  @ 0004c700
void SteamInternal_Init_SteamApps(ISteamApps **p)

{
  undefined4 uVar1;
  ISteamApps *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamApps *)
           SteamInternal_FindOrCreateUserInterface(uVar1,"STEAMAPPS_INTERFACE_VERSION008");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamFriends  @ 000bec10
void SteamInternal_Init_SteamFriends(ISteamFriends **p)

{
  undefined4 uVar1;
  ISteamFriends *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamFriends *)SteamInternal_FindOrCreateUserInterface(uVar1,"SteamFriends017");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamGameServer  @ 000bead0
void SteamInternal_Init_SteamGameServer(ISteamGameServer **p)

{
  undefined4 uVar1;
  ISteamGameServer *pIVar2;
  
  uVar1 = SteamGameServer_GetHSteamUser();
  pIVar2 = (ISteamGameServer *)
           SteamInternal_FindOrCreateGameServerInterface(uVar1,"SteamGameServer015");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamGameServerNetworkingSockets_SteamAPI  @ 000beb00
void SteamInternal_Init_SteamGameServerNetworkingSockets_SteamAPI(ISteamNetworkingSockets **p)

{
  undefined4 uVar1;
  ISteamNetworkingSockets *pIVar2;
  
  uVar1 = SteamGameServer_GetHSteamUser();
  pIVar2 = (ISteamNetworkingSockets *)
           SteamInternal_FindOrCreateGameServerInterface(uVar1,"SteamNetworkingSockets012");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamInput  @ 000bebe0
void SteamInternal_Init_SteamInput(ISteamInput **p)

{
  undefined4 uVar1;
  ISteamInput *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamInput *)SteamInternal_FindOrCreateUserInterface(uVar1,"SteamInput006");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamNetworkingSockets_SteamAPI  @ 000bebb0
void SteamInternal_Init_SteamNetworkingSockets_SteamAPI(ISteamNetworkingSockets **p)

{
  undefined4 uVar1;
  ISteamNetworkingSockets *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamNetworkingSockets *)
           SteamInternal_FindOrCreateUserInterface(uVar1,"SteamNetworkingSockets012");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamNetworkingUtils_SteamAPI  @ 000beb30
void SteamInternal_Init_SteamNetworkingUtils_SteamAPI(ISteamNetworkingUtils **p)

{
  int iVar1;
  ISteamNetworkingUtils *pIVar2;
  
  iVar1 = SteamInternal_FindOrCreateUserInterface(0,"SteamNetworkingUtils004");
  if (iVar1 != 0) {
    pIVar2 = (ISteamNetworkingUtils *)SteamInternal_FindOrCreateUserInterface();
    *p = pIVar2;
    return;
  }
  pIVar2 = (ISteamNetworkingUtils *)
           SteamInternal_FindOrCreateGameServerInterface(0,"SteamNetworkingUtils004");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamUser  @ 000bec40
void SteamInternal_Init_SteamUser(ISteamUser **p)

{
  undefined4 uVar1;
  ISteamUser *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamUser *)SteamInternal_FindOrCreateUserInterface(uVar1,"SteamUser023");
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamUtils  @ 000beb80
void SteamInternal_Init_SteamUtils(ISteamUtils **p)

{
  ISteamUtils *pIVar1;
  
  pIVar1 = (ISteamUtils *)SteamInternal_FindOrCreateUserInterface(0,"SteamUtils010");
  *p = pIVar1;
  return;
}


