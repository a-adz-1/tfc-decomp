// SendAmmoUpdate__11CBasePlayer  @ 000db6d8
void SendAmmoUpdate__11CBasePlayer(int *param_1)

{
  char *__s1;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((rocket_slot == 0) || (cell_slot == 0)) {
    iVar5 = 0;
    do {
      __s1 = (char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2];
      iVar4 = rocket_slot;
      iVar1 = cell_slot;
      iVar2 = shell_slot;
      if ((((__s1 != (char *)0x0) && (*__s1 != '\0')) &&
          (iVar3 = strcmp(__s1,"rockets"), iVar4 = iVar5, iVar1 = cell_slot, iVar2 = shell_slot,
          iVar3 != 0)) &&
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
  param_1[rocket_slot + 0x23b] = param_1[0x39];
  param_1[cell_slot + 0x23b] = param_1[0x37];
  param_1[shell_slot + 0x23b] = param_1[0x33];
  iVar5 = 0;
  param_1[nail_slot + 0x23b] = param_1[0x35];
  do {
    if (param_1[iVar5 + 0x23b] != param_1[iVar5 + 0x25b]) {
      param_1[iVar5 + 0x25b] = param_1[iVar5 + 0x23b];
      (*DAT_0019f758)(1,gmsgAmmoX,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(iVar5);
      iVar4 = param_1[iVar5 + 0x23b];
      if (0xfe < iVar4) {
        iVar4 = 0xfe;
      }
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      (*DAT_0019f760)(iVar4);
      (*DAT_0019f75c)();
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  return;
}


