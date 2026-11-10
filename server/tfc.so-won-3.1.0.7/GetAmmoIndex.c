// GetAmmoIndex__11CBasePlayerPCc  @ 000dc768
int GetAmmoIndex__11CBasePlayerPCc(char *param_1)

{
  char *__s2;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
LAB_000dc849:
    iVar3 = -1;
  }
  else {
    iVar3 = 1;
    __s2 = DAT_001ce748;
    if (DAT_001ce748 == (char *)0x0) goto LAB_000dc7ed;
    while (iVar1 = strcasecmp(param_1,__s2), iVar1 != 0) {
LAB_000dc7ed:
      do {
        iVar1 = iVar3 + 1;
        if (((&_15CBasePlayerItem_AmmoInfoArray)[iVar1 * 2] != 0) &&
           (iVar2 = strcasecmp(param_1,(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar1 * 2]),
           iVar2 == 0)) {
          return iVar1;
        }
        iVar1 = iVar3 + 2;
        if (((&_15CBasePlayerItem_AmmoInfoArray)[iVar1 * 2] != 0) &&
           (iVar2 = strcasecmp(param_1,(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar1 * 2]),
           iVar2 == 0)) {
          return iVar1;
        }
        iVar1 = iVar3 + 3;
        if (0x1f < iVar1) goto LAB_000dc849;
        if (((&_15CBasePlayerItem_AmmoInfoArray)[iVar1 * 2] != 0) &&
           (iVar2 = strcasecmp(param_1,(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar1 * 2]),
           iVar2 == 0)) {
          return iVar1;
        }
        iVar3 = iVar3 + 4;
      } while ((&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2] == 0);
      __s2 = (char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2];
    }
  }
  return iVar3;
}


