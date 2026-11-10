// PackAmmo__10CWeaponBoxii  @ 0011c6d0
undefined4 PackAmmo__10CWeaponBoxii(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    (*DAT_001755b4)(1,"NULL String in PackAmmo!\n");
  }
  else {
    iVar1 = MaxAmmoCarry__Fi(param_2);
    if ((iVar1 != -1) && (0 < param_3)) {
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x60))
                (param_1,param_3,param_2 + *(int *)(gpGlobals + 0x98),iVar1,0);
      return 1;
    }
  }
  return 0;
}


