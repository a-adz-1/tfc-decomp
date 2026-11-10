// SendAmmoUpdate__11CBasePlayer  @ 000de4d0
void SendAmmoUpdate__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((rocket_slot == 0) || (cell_slot == 0)) {
    iVar5 = 0;
    do {
      iVar4 = rocket_slot;
      iVar1 = cell_slot;
      iVar2 = shell_slot;
      if (((((&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2] != 0) &&
           (*(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2] != '\0')) &&
          (iVar3 = strcmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2],"rockets"),
          iVar4 = iVar5, iVar1 = cell_slot, iVar2 = shell_slot, iVar3 != 0)) &&
         (((iVar3 = strcmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2],"uranium"),
           iVar4 = rocket_slot, iVar1 = iVar5, iVar2 = shell_slot, iVar3 != 0 &&
           (iVar3 = strcmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2],"buckshot"),
           iVar4 = rocket_slot, iVar1 = cell_slot, iVar2 = iVar5, iVar3 != 0)) &&
          (iVar3 = strcmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2],"9mm"),
          iVar4 = rocket_slot, iVar1 = cell_slot, iVar2 = shell_slot, iVar3 == 0)))) {
        nail_slot = iVar5;
      }
      shell_slot = iVar2;
      cell_slot = iVar1;
      rocket_slot = iVar4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x20);
  }
  param_1[rocket_slot + 0x20f] = param_1[0x39];
  param_1[cell_slot + 0x20f] = param_1[0x37];
  param_1[shell_slot + 0x20f] = param_1[0x33];
  param_1[nail_slot + 0x20f] = param_1[0x35];
  iVar5 = 0;
  do {
    if (param_1[iVar5 + 0x20f] != param_1[iVar5 + 0x22f]) {
      param_1[iVar5 + 0x22f] = param_1[iVar5 + 0x20f];
      (*DAT_00175578)(1,gmsgAmmoX,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(iVar5);
      iVar4 = param_1[iVar5 + 0x20f];
      if (0xfe < iVar4) {
        iVar4 = 0xfe;
      }
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      (*DAT_00175580)(iVar4);
      (*DAT_0017557c)();
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  return;
}


