// AddAmmoNameToAmmoRegistry__FPCc  @ 00126144
void AddAmmoNameToAmmoRegistry__FPCc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2] == (char *)0x0 ||
         (iVar1 = strcasecmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2],param_1),
         iVar1 != 0))) {
    iVar2 = iVar2 + 1;
    if (0x1f < iVar2) {
      giAmmoIndex = giAmmoIndex + 1;
      if (0x1f < giAmmoIndex) {
        giAmmoIndex = 0;
      }
      (&_15CBasePlayerItem_AmmoInfoArray)[giAmmoIndex * 2] = param_1;
      (&DAT_001acde4)[giAmmoIndex * 2] = giAmmoIndex;
      return;
    }
  }
  return;
}


