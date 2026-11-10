// HasWeapon__10CWeaponBoxP15CBasePlayerItem  @ 00124dd8
undefined4 HasWeapon__10CWeaponBoxP15CBasePlayerItem(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = (**(code **)(param_2[0x115] + 0x114))(param_2);
  puVar1 = *(undefined4 **)(param_1 + 0x458 + iVar2 * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar1),
                   (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*param_2));
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)puVar1[0x11e];
  }
  return 1;
}


