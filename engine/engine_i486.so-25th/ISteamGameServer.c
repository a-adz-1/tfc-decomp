// ISteamGameServer_BUpdateUserData  @ 000bba90
bool ISteamGameServer_BUpdateUserData(uint64 steamid,char *netname,uint32 score)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = (int *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  if (*piVar2 != 0) {
    puVar3 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    uVar1 = (**(code **)(*(int *)*puVar3 + 0xa4))((int *)*puVar3,steamid,netname,score);
    return (bool)uVar1;
  }
  return false;
}


// ISteamGameServer_CreateUnauthenticatedUserConnection  @ 000bba40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint64 ISteamGameServer_CreateUnauthenticatedUserConnection(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined8 local_18;
  
  piVar1 = (int *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  if (*piVar1 != 0) {
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar2 + 0x9c))((int)&local_18 + 4,(int *)*puVar2);
    return local_18;
  }
  return 0;
}


