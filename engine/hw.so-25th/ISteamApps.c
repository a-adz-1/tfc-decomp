// ISteamApps_BIsSubscribedApp  @ 0012e230
bool ISteamApps_BIsSubscribedApp(uint32 appid)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = (int *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
  if (*piVar2 != 0) {
    puVar3 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
    uVar1 = (**(code **)(*(int *)*puVar3 + 0x18))((int *)*puVar3,appid);
    return (bool)uVar1;
  }
  return false;
}


