// SteamInternal_Init_SteamApps  @ 000b0290
void SteamInternal_Init_SteamApps(ISteamApps **p)

{
  undefined4 uVar1;
  ISteamApps *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamApps *)SteamInternal_FindOrCreateUserInterface(uVar1,0x257794);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamFriends  @ 00131350
void SteamInternal_Init_SteamFriends(ISteamFriends **p)

{
  undefined4 uVar1;
  ISteamFriends *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamFriends *)SteamInternal_FindOrCreateUserInterface(uVar1,0x26276a);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamGameServer  @ 00131210
void SteamInternal_Init_SteamGameServer(ISteamGameServer **p)

{
  undefined4 uVar1;
  ISteamGameServer *pIVar2;
  
  uVar1 = SteamGameServer_GetHSteamUser();
  pIVar2 = (ISteamGameServer *)SteamInternal_FindOrCreateGameServerInterface(uVar1,&LAB_00262709);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamGameServerNetworkingSockets_SteamAPI  @ 00131240
void SteamInternal_Init_SteamGameServerNetworkingSockets_SteamAPI(ISteamNetworkingSockets **p)

{
  undefined4 uVar1;
  ISteamNetworkingSockets *pIVar2;
  
  uVar1 = SteamGameServer_GetHSteamUser();
  pIVar2 = (ISteamNetworkingSockets *)SteamInternal_FindOrCreateGameServerInterface(uVar1,0x26271c);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamHTTP  @ 001283a0
void SteamInternal_Init_SteamHTTP(ISteamHTTP **p)

{
  undefined4 uVar1;
  ISteamHTTP *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamHTTP *)SteamInternal_FindOrCreateUserInterface(uVar1,&LAB_002619d0);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamInput  @ 00131320
void SteamInternal_Init_SteamInput(ISteamInput **p)

{
  undefined4 uVar1;
  ISteamInput *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamInput *)SteamInternal_FindOrCreateUserInterface(uVar1,&LAB_0026275b_1);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamNetworkingSockets_SteamAPI  @ 001312f0
void SteamInternal_Init_SteamNetworkingSockets_SteamAPI(ISteamNetworkingSockets **p)

{
  undefined4 uVar1;
  ISteamNetworkingSockets *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamNetworkingSockets *)SteamInternal_FindOrCreateUserInterface(uVar1,0x26271c);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamNetworkingUtils_SteamAPI  @ 00131270
void SteamInternal_Init_SteamNetworkingUtils_SteamAPI(ISteamNetworkingUtils **p)

{
  int iVar1;
  ISteamNetworkingUtils *pIVar2;
  
  iVar1 = SteamInternal_FindOrCreateUserInterface(0,&LAB_00262736);
  if (iVar1 != 0) {
    pIVar2 = (ISteamNetworkingUtils *)SteamInternal_FindOrCreateUserInterface();
    *p = pIVar2;
    return;
  }
  pIVar2 = (ISteamNetworkingUtils *)SteamInternal_FindOrCreateGameServerInterface(0,&LAB_00262736);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamUser  @ 00131380
void SteamInternal_Init_SteamUser(ISteamUser **p)

{
  undefined4 uVar1;
  ISteamUser *pIVar2;
  
  uVar1 = SteamAPI_GetHSteamUser();
  pIVar2 = (ISteamUser *)SteamInternal_FindOrCreateUserInterface(uVar1,0x26277a);
  *p = pIVar2;
  return;
}


// SteamInternal_Init_SteamUtils  @ 001312c0
void SteamInternal_Init_SteamUtils(ISteamUtils **p)

{
  ISteamUtils *pIVar1;
  
  pIVar1 = (ISteamUtils *)SteamInternal_FindOrCreateUserInterface(0,&LAB_0026274e);
  *p = pIVar1;
  return;
}


