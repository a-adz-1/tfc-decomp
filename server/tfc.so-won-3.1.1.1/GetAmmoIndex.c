// GetAmmoIndex__11CBasePlayerPCc  @ 000e52d0
int GetAmmoIndex__11CBasePlayerPCc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (char *)0x0) {
    iVar2 = 1;
    do {
      if (((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2] != (char *)0x0) &&
         (iVar1 = strcasecmp(param_1,(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2]),
         iVar1 == 0)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x20);
  }
  return -1;
}


