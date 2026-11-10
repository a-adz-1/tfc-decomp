// SendAmmoUpdate__11CBasePlayer  @ 000d118c
void SendAmmoUpdate__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int local_4;
  
  if ((rocket_slot == 0) || (cell_slot == 0)) {
    iVar7 = 0;
    iVar5 = 0;
    do {
      iVar1 = rocket_slot;
      iVar2 = cell_slot;
      iVar3 = shell_slot;
      if ((((*(int *)((int)&_15CBasePlayerItem_AmmoInfoArray + iVar5) != 0) &&
           (**(char **)((int)&_15CBasePlayerItem_AmmoInfoArray + iVar5) != '\0')) &&
          (iVar4 = strcmp(*(char **)((int)&_15CBasePlayerItem_AmmoInfoArray + iVar5),"rockets"),
          iVar1 = iVar7, iVar2 = cell_slot, iVar3 = shell_slot, iVar4 != 0)) &&
         (((iVar4 = strcmp(*(char **)((int)&_15CBasePlayerItem_AmmoInfoArray + iVar5),"uranium"),
           iVar1 = rocket_slot, iVar2 = iVar7, iVar3 = shell_slot, iVar4 != 0 &&
           (iVar4 = strcmp(*(char **)((int)&_15CBasePlayerItem_AmmoInfoArray + iVar5),"buckshot"),
           iVar1 = rocket_slot, iVar2 = cell_slot, iVar3 = iVar7, iVar4 != 0)) &&
          (iVar4 = strcmp(*(char **)((int)&_15CBasePlayerItem_AmmoInfoArray + iVar5),
                          (char *)FUN_0013a340), iVar1 = rocket_slot, iVar2 = cell_slot,
          iVar3 = shell_slot, iVar4 == 0)))) {
        nail_slot = iVar7;
      }
      shell_slot = iVar3;
      cell_slot = iVar2;
      rocket_slot = iVar1;
      iVar5 = iVar5 + 8;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x20);
  }
  piVar8 = param_1 + 0x214;
  piVar8[rocket_slot] = param_1[0x39];
  piVar8[cell_slot] = param_1[0x37];
  piVar8[shell_slot] = param_1[0x33];
  piVar8[nail_slot] = param_1[0x35];
  local_4 = 0;
  piVar6 = param_1 + 0x234;
  do {
    if (*piVar8 != *piVar6) {
      *piVar6 = *piVar8;
      (*DAT_001a7ef8)(1,gmsgAmmoX,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(local_4);
      iVar5 = *piVar8;
      if (0xfe < iVar5) {
        iVar5 = 0xfe;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      (*DAT_001a7f00)(iVar5);
      (*DAT_001a7efc)();
    }
    if (piVar8[1] != piVar6[1]) {
      piVar6[1] = piVar8[1];
      (*DAT_001a7ef8)(1,gmsgAmmoX,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(local_4 + 1);
      iVar5 = piVar8[1];
      if (0xfe < iVar5) {
        iVar5 = 0xfe;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      (*DAT_001a7f00)(iVar5);
      (*DAT_001a7efc)();
    }
    piVar8 = piVar8 + 2;
    piVar6 = piVar6 + 2;
    local_4 = local_4 + 2;
  } while (local_4 < 0x20);
  return;
}


