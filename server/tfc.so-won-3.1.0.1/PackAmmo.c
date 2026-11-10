// PackAmmo__10CWeaponBoxii  @ 00111d3c
undefined4 PackAmmo__10CWeaponBoxii(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    (*DAT_001a7f34)(1,"NULL String in PackAmmo!\n");
    uVar1 = 0;
  }
  else {
    iVar2 = MaxAmmoCarry__Fi(param_2);
    if ((iVar2 == -1) || (param_3 < 1)) {
      uVar1 = 0;
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x60))
                (param_1,param_3,param_2 + *(int *)(gpGlobals + 0x98),iVar2,0);
      uVar1 = 1;
    }
  }
  return uVar1;
}


