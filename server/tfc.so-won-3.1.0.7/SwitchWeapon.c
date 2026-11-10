// SwitchWeapon__11CBasePlayerP15CBasePlayerItem  @ 000defb4
undefined4 SwitchWeapon__11CBasePlayerP15CBasePlayerItem(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_2 + 0x444) + 0x11c))(param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    ResetAutoaim__11CBasePlayer(param_1);
    if (*(int *)(param_1 + 0x8b4) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 0x128))
                (*(int *)(param_1 + 0x8b4),0);
    }
    *(int *)(param_1 + 0x8b4) = param_2;
    (**(code **)(*(int *)(param_2 + 0x444) + 0x120))(param_2);
    uVar2 = 1;
  }
  return uVar2;
}


// SwitchWeapon__11CBasePlayerPCc  @ 000df038
undefined4 SwitchWeapon__11CBasePlayerPCc(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    for (iVar3 = *(int *)(param_1 + 0x89c + iVar4 * 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x468))
    {
      iVar1 = *(int *)(iVar3 + 0x46c) * 0x2c;
      if ((*(int *)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18) != 0) &&
         (iVar1 = strcmp(*(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18),param_2),
         iVar1 == 0)) goto LAB_000df0d8;
    }
    for (iVar3 = *(int *)(param_1 + 0x8a0 + iVar4 * 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x468))
    {
      iVar1 = *(int *)(iVar3 + 0x46c) * 0x2c;
      if ((*(int *)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18) != 0) &&
         (iVar1 = strcmp(*(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18),param_2),
         iVar1 == 0)) {
LAB_000df0d8:
        uVar2 = SwitchWeapon__11CBasePlayerP15CBasePlayerItem(param_1,iVar3);
        return uVar2;
      }
    }
    iVar4 = iVar4 + 2;
    if (5 < iVar4) {
      return 0;
    }
  } while( true );
}


