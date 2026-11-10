// SwitchWeapon__11CBasePlayerP15CBasePlayerItem  @ 000dfc30
undefined4 SwitchWeapon__11CBasePlayerP15CBasePlayerItem(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x114))(param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    ResetAutoaim__11CBasePlayer(param_1);
    if (*(int *)(param_1 + 0x830) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x120))(*(int *)(param_1 + 0x830));
    }
    *(int *)(param_1 + 0x830) = param_2;
    (**(code **)(*(int *)(param_2 + 0x3c8) + 0x118))(param_2);
    uVar2 = 1;
  }
  return uVar2;
}


// SwitchWeapon__11CBasePlayerPCc  @ 000dfcb0
undefined4 SwitchWeapon__11CBasePlayerPCc(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    for (iVar1 = *(int *)(param_1 + 0x818 + iVar4 * 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3ec))
    {
      if (((&DAT_00182a98)[*(int *)(iVar1 + 0x3f0) * 0xb] != 0) &&
         (iVar2 = strcmp((char *)(&DAT_00182a98)[*(int *)(iVar1 + 0x3f0) * 0xb],param_2), iVar2 == 0
         )) {
        uVar3 = SwitchWeapon__11CBasePlayerP15CBasePlayerItem(param_1,iVar1);
        return uVar3;
      }
    }
    iVar4 = iVar4 + 1;
    if (5 < iVar4) {
      return 0;
    }
  } while( true );
}


