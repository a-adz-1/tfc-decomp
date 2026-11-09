// ISteamApps_BIsSubscribedApp  @ 000cf260
bool ISteamApps_BIsSubscribedApp(uint32 appid)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = SteamApps();
  uVar1 = 0;
  if (iVar2 != 0) {
    piVar3 = (int *)SteamApps();
    uVar1 = (**(code **)(*piVar3 + 0x18))(piVar3,appid);
  }
  return (bool)uVar1;
}


