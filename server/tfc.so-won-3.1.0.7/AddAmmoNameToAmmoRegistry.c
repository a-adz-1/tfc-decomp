// AddAmmoNameToAmmoRegistry__FPCc  @ 0011f174
void AddAmmoNameToAmmoRegistry__FPCc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (((&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2] != 0) &&
       (iVar1 = strcasecmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar2 * 2],param_1),
       iVar1 == 0)) {
      return;
    }
    if (((&DAT_001ce748)[iVar2 * 2] != 0) &&
       (iVar1 = strcasecmp((char *)(&DAT_001ce748)[iVar2 * 2],param_1), iVar1 == 0)) {
      return;
    }
    if (((&DAT_001ce750)[iVar2 * 2] != 0) &&
       (iVar1 = strcasecmp((char *)(&DAT_001ce750)[iVar2 * 2],param_1), iVar1 == 0)) {
      return;
    }
    if (((&DAT_001ce758)[iVar2 * 2] != 0) &&
       (iVar1 = strcasecmp((char *)(&DAT_001ce758)[iVar2 * 2],param_1), iVar1 == 0)) break;
    iVar2 = iVar2 + 4;
    if (0x1f < iVar2) {
      giAmmoIndex = giAmmoIndex + 1;
      if (0x1f < giAmmoIndex) {
        giAmmoIndex = 0;
      }
      (&_15CBasePlayerItem_AmmoInfoArray)[giAmmoIndex * 2] = param_1;
      *(int *)(giAmmoIndex * 8 + 0x1ce744) = giAmmoIndex;
      return;
    }
  }
  return;
}


