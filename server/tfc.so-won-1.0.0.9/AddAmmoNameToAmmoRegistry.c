// AddAmmoNameToAmmoRegistry__FPCc  @ 0011a5b0
void AddAmmoNameToAmmoRegistry__FPCc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (((&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2] == 0 ||
         (iVar1 = strcasecmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2],param_1),
         iVar1 != 0))) {
    iVar2 = iVar2 + 1;
    if (0x1f < iVar2) {
      giAmmoIndex = giAmmoIndex + 1;
      if (0x1f < giAmmoIndex) {
        giAmmoIndex = 0;
      }
      iVar2 = giAmmoIndex;
      (&_15CBasePlayerItem_AmmoInfoArray)[giAmmoIndex * 2] = param_1;
      (&DAT_00182984)[iVar2 * 2] = iVar2;
      return;
    }
  }
  return;
}


