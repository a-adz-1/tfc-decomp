// ISteamGameServer_BUpdateUserData  @ 000cf200
bool ISteamGameServer_BUpdateUserData(uint64 steamid,char *netname,uint32 score)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = SteamGameServer();
  uVar1 = 0;
  if (iVar2 != 0) {
    piVar3 = (int *)SteamGameServer();
    uVar1 = (**(code **)(*piVar3 + 0x6c))(piVar3,steamid,netname,score);
  }
  return (bool)uVar1;
}


// ISteamGameServer_CreateUnauthenticatedUserConnection  @ 000cf1c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint64 ISteamGameServer_CreateUnauthenticatedUserConnection(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  undefined4 local_14 [5];
  
  iVar1 = SteamGameServer();
  uVar3 = 0;
  uVar4 = 0;
  if (iVar1 != 0) {
    piVar2 = (int *)SteamGameServer();
    (**(code **)(*piVar2 + 100))(local_14,piVar2);
    uVar3 = local_18;
    uVar4 = local_14[0];
  }
  return CONCAT44(uVar4,uVar3);
}


