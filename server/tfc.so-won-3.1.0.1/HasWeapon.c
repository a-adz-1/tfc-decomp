// HasWeapon__10CWeaponBoxP15CBasePlayerItem  @ 00111ee0
undefined4 HasWeapon__10CWeaponBoxP15CBasePlayerItem(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = (**(code **)(param_2[0xf5] + 0x10c))(param_2);
  puVar1 = *(undefined4 **)(param_1 + 0x3d8 + iVar2 * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar1),
                   (char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)));
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)puVar1[0xfe];
  }
  return 1;
}


