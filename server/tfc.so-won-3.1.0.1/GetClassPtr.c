// GetClassPtr__H1Z10CBaseDelay_PX01_PX01  @ 0012d828
void GetClassPtr__H1Z10CBaseDelay_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CBreakable_PX01_PX01  @ 0012a6e4
void GetClassPtr__H1Z10CBreakable_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_10CBreakable;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CCineBlood_PX01_PX01  @ 0012b13c
void GetClassPtr__H1Z10CCineBlood_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CCineBlood;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CEnvFunnel_PX01_PX01  @ 0012a3cc
void GetClassPtr__H1Z10CEnvFunnel_PX01_PX01(void)

{
  FUN_0012a3d4();
  return;
}


// GetClassPtr__H1Z10CEnvGlobal_PX01_PX01  @ 001291a4
void GetClassPtr__H1Z10CEnvGlobal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_10CEnvGlobal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CFuncTrain_PX01_PX01  @ 0012cb68
void GetClassPtr__H1Z10CFuncTrain_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x48c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_14CBasePlatTrain;
    piVar2[0xf5] = (int)__vt_10CFuncTrain;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CFurniture_PX01_PX01  @ 0012d410
void GetClassPtr__H1Z10CFurniture_PX01_PX01(void)

{
  FUN_0012d418();
  return;
}


// GetClassPtr__H1Z10CGunTarget_PX01_PX01  @ 0012cebc
void GetClassPtr__H1Z10CGunTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x620);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_10CGunTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CHealthKit_PX01_PX01  @ 0012b92c
void GetClassPtr__H1Z10CHealthKit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_10CHealthKit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CLaserSpot_PX01_PX01  @ 0012e9ac
void GetClassPtr__H1Z10CLaserSpot_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CLaserSpot;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CLightning_PX01_PX01  @ 00129dbc
void GetClassPtr__H1Z10CLightning_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x40c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CBeam;
    piVar2[0xf5] = (int)__vt_10CLightning;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CPathTrack_PX01_PX01  @ 0012c8f0
void GetClassPtr__H1Z10CPathTrack_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3ec);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_10CPathTrack;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CRotButton_PX01_PX01  @ 00129360
void GetClassPtr__H1Z10CRotButton_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4b0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_11CBaseButton;
    piVar2[0xf5] = (int)__vt_10CRotButton;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFBomblet_PX01_PX01  @ 0012e5cc
void GetClassPtr__H1Z10CTFBomblet_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_10CTFBomblet;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFCaltrop_PX01_PX01  @ 0012963c
void GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CTFCaltrop;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFGrenade_PX01_PX01  @ 0012e920
void GetClassPtr__H1Z10CTFGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_10CTFGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFMedikit_PX01_PX01  @ 00130ab0
void GetClassPtr__H1Z10CTFMedikit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_8CCrowbar;
    piVar2[0xf5] = (int)__vt_6CTFAxe;
    piVar2[0xf5] = (int)__vt_10CTFMedikit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFNailgun_PX01_PX01  @ 00130e48
void GetClassPtr__H1Z10CTFNailgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_10CTFNailgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFRailgun_PX01_PX01  @ 00130fb4
void GetClassPtr__H1Z10CTFRailgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_10CTFRailgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFRpgAmmo_PX01_PX01  @ 0012e894
void GetClassPtr__H1Z10CTFRpgAmmo_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_15CBasePlayerAmmo;
    piVar2[0xf5] = (int)__vt_10CTFRpgAmmo;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFShotgun_PX01_PX01  @ 00131114
void GetClassPtr__H1Z10CTFShotgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x464);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_10CTFShotgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFSpanner_PX01_PX01  @ 001309e4
void GetClassPtr__H1Z10CTFSpanner_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4d4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_8CCrowbar;
    piVar2[0xf5] = (int)__vt_6CTFAxe;
    piVar2[0xf5] = (int)__vt_10CTFSpanner;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CWeaponBox_PX01_PX01  @ 001296bc
void GetClassPtr__H1Z10CWeaponBox_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4fc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CWeaponBox;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CWorldItem_PX01_PX01  @ 0012ba5c
void GetClassPtr__H1Z10CWorldItem_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CWorldItem;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CXenPLight_PX01_PX01  @ 001301a8
void GetClassPtr__H1Z10CXenPLight_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3fc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_13CActAnimating;
    piVar2[0xf5] = (int)__vt_10CXenPLight;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CBaseButton_PX01_PX01  @ 001292bc
void GetClassPtr__H1Z11CBaseButton_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4b0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_11CBaseButton;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CBasePlayer_PX01_PX01  @ 001295bc
void GetClassPtr__H1Z11CBasePlayer_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0xd6c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_11CBasePlayer;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CCine2Slave_PX01_PX01  @ 0012af98
void GetClassPtr__H1Z11CCine2Slave_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_11CCine2Slave;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CCineBarney_PX01_PX01  @ 0012adf4
void GetClassPtr__H1Z11CCineBarney_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_11CCineBarney;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CEnvShooter_PX01_PX01  @ 0012a078
void GetClassPtr__H1Z11CEnvShooter_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3fc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_11CGibShooter;
    piVar2[0xf5] = (int)__vt_11CEnvShooter;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CFireAndDie_PX01_PX01  @ 0012f7c4
void GetClassPtr__H1Z11CFireAndDie_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_11CFireAndDie;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CGibShooter_PX01_PX01  @ 00129fec
void GetClassPtr__H1Z11CGibShooter_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3fc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_11CGibShooter;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CItemHealth_PX01_PX01  @ 0012d96c
void GetClassPtr__H1Z11CItemHealth_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_11CItemHealth;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CMiniTurret_PX01_PX01  @ 0012fec4
void GetClassPtr__H1Z11CMiniTurret_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x68c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_11CBaseTurret;
    piVar2[0xf5] = (int)__vt_11CMiniTurret;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CNodeViewer_PX01_PX01  @ 0012c79c
void GetClassPtr__H1Z11CNodeViewer_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x7f8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_11CNodeViewer;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CNullEntity_PX01_PX01  @ 0012d7a8
void GetClassPtr__H1Z11CNullEntity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_11CNullEntity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CPathCorner_PX01_PX01  @ 0012c864
void GetClassPtr__H1Z11CPathCorner_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_11CPathCorner;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTFAssaultC_PX01_PX01  @ 001306fc
void GetClassPtr__H1Z11CTFAssaultC_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x464);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_11CTFAssaultC;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTFGoalItem_PX01_PX01  @ 0012ee7c
void GetClassPtr__H1Z11CTFGoalItem_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_7CTFGoal;
    piVar2[0xf5] = (int)__vt_11CTFGoalItem;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTestEffect_PX01_PX01  @ 0012a110
void GetClassPtr__H1Z11CTestEffect_PX01_PX01(void)

{
  FUN_0012a118();
  return;
}


// GetClassPtr__H1Z11CWallHealth_PX01_PX01  @ 0012b9b8
void GetClassPtr__H1Z11CWallHealth_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x48c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_11CWallHealth;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CAutoTrigger_PX01_PX01  @ 0012efa0
void GetClassPtr__H1Z12CAutoTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),1000);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_12CAutoTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CBaseTrigger_PX01_PX01  @ 0012f1dc
void GetClassPtr__H1Z12CBaseTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CChangeLevel_PX01_PX01  @ 0012f850
void GetClassPtr__H1Z12CChangeLevel_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4c0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_12CChangeLevel;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCine3Barney_PX01_PX01  @ 0012b0b0
void GetClassPtr__H1Z12CCine3Barney_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_12CCine3Barney;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCineMonster_PX01_PX01  @ 0012d260
void GetClassPtr__H1Z12CCineMonster_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x650);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_12CCineMonster;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCinePanther_PX01_PX01  @ 0012ad68
void GetClassPtr__H1Z12CCinePanther_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_12CCinePanther;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCyclerProbe_PX01_PX01  @ 0012b588
void GetClassPtr__H1Z12CCyclerProbe_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x620);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_7CCycler;
    piVar2[0xf5] = (int)__vt_12CCyclerProbe;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CEnvBeverage_PX01_PX01  @ 0012a458
void GetClassPtr__H1Z12CEnvBeverage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_12CEnvBeverage;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CFuncPlatRot_PX01_PX01  @ 0012caac
void GetClassPtr__H1Z12CFuncPlatRot_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x498);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_14CBasePlatTrain;
    piVar2[0xf5] = (int)__vt_9CFuncPlat;
    piVar2[0xf5] = (int)__vt_12CFuncPlatRot;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CFuncTankGun_PX01_PX01  @ 0012a808
void GetClassPtr__H1Z12CFuncTankGun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CFuncTank;
    piVar2[0xf5] = (int)__vt_12CFuncTankGun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CHandGrenade_PX01_PX01  @ 0012b87c
void GetClassPtr__H1Z12CHandGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x458);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_12CHandGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CItemBattery_PX01_PX01  @ 0012bb68
void GetClassPtr__H1Z12CItemBattery_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_12CItemBattery;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CMultiSource_PX01_PX01  @ 00129230
void GetClassPtr__H1Z12CMultiSource_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x560);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_12CMultiSource;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CNoBuildArea_PX01_PX01  @ 0012a564
void GetClassPtr__H1Z12CNoBuildArea_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CNoBuildArea;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CPlatTrigger_PX01_PX01  @ 0012ca2c
void GetClassPtr__H1Z12CPlatTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPlatTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CPointEntity_PX01_PX01  @ 00129c3c
void GetClassPtr__H1Z12CPointEntity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CRevertSaved_PX01_PX01  @ 0012d0c8
void GetClassPtr__H1Z12CRevertSaved_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_12CRevertSaved;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFAutoRifle_PX01_PX01  @ 001307ac
void GetClassPtr__H1Z12CTFAutoRifle_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_12CTFAutoRifle;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFDispenser_PX01_PX01  @ 00129944
void GetClassPtr__H1Z12CTFDispenser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x628);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_12CTFDispenser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01  @ 0012e808
void GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x63c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_12CTFRpgRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFSentrygun_PX01_PX01  @ 0012d490
void GetClassPtr__H1Z12CTFSentrygun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x654);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_12CTFSentrygun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFTimerGoal_PX01_PX01  @ 0012edd8
void GetClassPtr__H1Z12CTFTimerGoal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_7CTFGoal;
    piVar2[0xf5] = (int)__vt_12CTFTimerGoal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerHurt_PX01_PX01  @ 0012f280
void GetClassPtr__H1Z12CTriggerHurt_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_12CTriggerHurt;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerOnce_PX01_PX01  @ 0012f5cc
void GetClassPtr__H1Z12CTriggerOnce_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_16CTriggerMultiple;
    piVar2[0xf5] = (int)__vt_12CTriggerOnce;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerPush_PX01_PX01  @ 0012f9b0
void GetClassPtr__H1Z12CTriggerPush_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_12CTriggerPush;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerSave_PX01_PX01  @ 0012fb10
void GetClassPtr__H1Z12CTriggerSave_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_12CTriggerSave;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CXenSporeMed_PX01_PX01  @ 00130550
void GetClassPtr__H1Z12CXenSporeMed_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_13CActAnimating;
    piVar2[0xf5] = (int)__vt_9CXenSpore;
    piVar2[0xf5] = (int)__vt_12CXenSporeMed;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CButtonTarget_PX01_PX01  @ 00129534
void GetClassPtr__H1Z13CButtonTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_13CButtonTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CCyclerSprite_PX01_PX01  @ 0012b614
void GetClassPtr__H1Z13CCyclerSprite_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_13CCyclerSprite;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CEnvExplosion_PX01_PX01  @ 0012a664
void GetClassPtr__H1Z13CEnvExplosion_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x624);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_13CEnvExplosion;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CFuncConveyor_PX01_PX01  @ 00128ee8
void GetClassPtr__H1Z13CFuncConveyor_PX01_PX01(void)

{
  FUN_00128ef0();
  return;
}


// GetClassPtr__H1Z13CFuncRotating_PX01_PX01  @ 001290a4
void GetClassPtr__H1Z13CFuncRotating_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3ec);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_13CFuncRotating;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemAntidote_PX01_PX01  @ 0012bbf4
void GetClassPtr__H1Z13CItemAntidote_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_13CItemAntidote;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemArmorRed_PX01_PX01  @ 0012db28
void GetClassPtr__H1Z13CItemArmorRed_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_10CItemArmor;
    piVar2[0xf5] = (int)__vt_13CItemArmorRed;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemLongJump_PX01_PX01  @ 0012bd0c
void GetClassPtr__H1Z13CItemLongJump_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_13CItemLongJump;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemSecurity_PX01_PX01  @ 0012bc80
void GetClassPtr__H1Z13CItemSecurity_PX01_PX01(void)

{
  FUN_0012bc88();
  return;
}


// GetClassPtr__H1Z13CMultiManager_PX01_PX01  @ 0012f0b8
void GetClassPtr__H1Z13CMultiManager_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x504);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_13CMultiManager;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CStripWeapons_PX01_PX01  @ 0012d03c
void GetClassPtr__H1Z13CStripWeapons_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_13CStripWeapons;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01  @ 0012e534
void GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_13CTFEMPGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01  @ 0012e49c
void GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x644);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_13CTFGasGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTriggerRelay_PX01_PX01  @ 0012f02c
void GetClassPtr__H1Z13CTriggerRelay_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_13CTriggerRelay;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CWeaponCycler_PX01_PX01  @ 0012b694
void GetClassPtr__H1Z13CWeaponCycler_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x458);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_13CWeaponCycler;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CCineScientist_PX01_PX01  @ 0012acdc
void GetClassPtr__H1Z14CCineScientist_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_14CCineScientist;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CFuncTankLaser_PX01_PX01  @ 0012a894
void GetClassPtr__H1Z14CFuncTankLaser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x45c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CFuncTank;
    piVar2[0xf5] = (int)__vt_14CFuncTankLaser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CFuncTrackAuto_PX01_PX01  @ 0012cde4
void GetClassPtr__H1Z14CFuncTrackAuto_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4bc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_14CBasePlatTrain;
    piVar2[0xf5] = (int)__vt_9CFuncPlat;
    piVar2[0xf5] = (int)__vt_12CFuncPlatRot;
    piVar2[0xf5] = (int)__vt_16CFuncTrackChange;
    piVar2[0xf5] = (int)__vt_14CFuncTrackAuto;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CGenericCycler_PX01_PX01  @ 0012b4fc
void GetClassPtr__H1Z14CGenericCycler_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x620);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_7CCycler;
    piVar2[0xf5] = (int)__vt_14CGenericCycler;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01  @ 0012dd88
void GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_9CItemAmmo;
    piVar2[0xf5] = (int)__vt_14CItemAmmoCells;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01  @ 0012dc58
void GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_9CItemAmmo;
    piVar2[0xf5] = (int)__vt_14CItemAmmoNails;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CMomentaryDoor_PX01_PX01  @ 00129b98
void GetClassPtr__H1Z14CMomentaryDoor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x47c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_14CMomentaryDoor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFIncendiaryC_PX01_PX01  @ 00130d98
void GetClassPtr__H1Z14CTFIncendiaryC_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_14CTFIncendiaryC;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01  @ 0012e404
void GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_14CTFMirvGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01  @ 0012e36c
void GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_14CTFNailGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01  @ 0012e664
void GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x644);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_14CTFNailgunNail;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFSniperRifle_PX01_PX01  @ 00131280
void GetClassPtr__H1Z14CTFSniperRifle_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x45c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_14CTFSniperRifle;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTargetCDAudio_PX01_PX01  @ 0012f490
void GetClassPtr__H1Z14CTargetCDAudio_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_14CTargetCDAudio;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTelefragDeath_PX01_PX01  @ 0012aab8
void GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_14CTelefragDeath;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTriggerCamera_PX01_PX01  @ 0012fdac
void GetClassPtr__H1Z14CTriggerCamera_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x41c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CTriggerCamera;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTriggerVolume_PX01_PX01  @ 0012f738
void GetClassPtr__H1Z14CTriggerVolume_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_14CTriggerVolume;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CXenSporeLarge_PX01_PX01  @ 00130600
void GetClassPtr__H1Z14CXenSporeLarge_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_13CActAnimating;
    piVar2[0xf5] = (int)__vt_9CXenSpore;
    piVar2[0xf5] = (int)__vt_14CXenSporeLarge;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CXenSporeSmall_PX01_PX01  @ 001304a0
void GetClassPtr__H1Z14CXenSporeSmall_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_13CActAnimating;
    piVar2[0xf5] = (int)__vt_9CXenSpore;
    piVar2[0xf5] = (int)__vt_14CXenSporeSmall;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CAmbientGeneric_PX01_PX01  @ 0012d590
void GetClassPtr__H1Z15CAmbientGeneric_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x448);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_15CAmbientGeneric;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CCine2Scientist_PX01_PX01  @ 0012ae80
void GetClassPtr__H1Z15CCine2Scientist_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_15CCine2Scientist;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CCine3Scientist_PX01_PX01  @ 0012b024
void GetClassPtr__H1Z15CCine3Scientist_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_15CCine3Scientist;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTankMortar_PX01_PX01  @ 0012a9ac
void GetClassPtr__H1Z15CFuncTankMortar_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CFuncTank;
    piVar2[0xf5] = (int)__vt_15CFuncTankMortar;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTankRocket_PX01_PX01  @ 0012a920
void GetClassPtr__H1Z15CFuncTankRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CFuncTank;
    piVar2[0xf5] = (int)__vt_15CFuncTankRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTrackTrain_PX01_PX01  @ 0012cc18
void GetClassPtr__H1Z15CFuncTrackTrain_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x420);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_15CFuncTrackTrain;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncWallToggle_PX01_PX01  @ 00128e5c
void GetClassPtr__H1Z15CFuncWallToggle_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CFuncWall;
    piVar2[0xf5] = (int)__vt_15CFuncWallToggle;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CGenericMonster_PX01_PX01  @ 0012ab38
void GetClassPtr__H1Z15CGenericMonster_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_15CGenericMonster;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01  @ 0012dbc0
void GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_9CItemAmmo;
    piVar2[0xf5] = (int)__vt_15CItemAmmoShells;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01  @ 0012d9f8
void GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_10CItemArmor;
    piVar2[0xf5] = (int)__vt_15CItemArmorGreen;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFFlamethrower_PX01_PX01  @ 00130b7c
void GetClassPtr__H1Z15CTFFlamethrower_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_15CTFFlamethrower;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFPrimeGrenade_PX01_PX01  @ 0012e118
void GetClassPtr__H1Z15CTFPrimeGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFSuperNailgun_PX01_PX01  @ 00130ef8
void GetClassPtr__H1Z15CTFSuperNailgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x458);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_10CTFNailgun;
    piVar2[0xf5] = (int)__vt_15CTFSuperNailgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFSuperShotgun_PX01_PX01  @ 001311c4
void GetClassPtr__H1Z15CTFSuperShotgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x468);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_10CTFShotgun;
    piVar2[0xf5] = (int)__vt_15CTFSuperShotgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerCDAudio_PX01_PX01  @ 0012f3e0
void GetClassPtr__H1Z15CTriggerCDAudio_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_15CTriggerCDAudio;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerCounter_PX01_PX01  @ 0012f688
void GetClassPtr__H1Z15CTriggerCounter_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_15CTriggerCounter;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerGravity_PX01_PX01  @ 0012fc70
void GetClassPtr__H1Z15CTriggerGravity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_15CTriggerGravity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01  @ 001302f0
void GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_15CXenTreeTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncIllusionary_PX01_PX01  @ 00128f74
void GetClassPtr__H1Z16CFuncIllusionary_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_16CFuncIllusionary;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncMonsterClip_PX01_PX01  @ 00129018
void GetClassPtr__H1Z16CFuncMonsterClip_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CFuncWall;
    piVar2[0xf5] = (int)__vt_16CFuncMonsterClip;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncMortarField_PX01_PX01  @ 0012c56c
void GetClassPtr__H1Z16CFuncMortarField_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x490);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_16CFuncMortarField;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncTrackChange_PX01_PX01  @ 0012cd18
void GetClassPtr__H1Z16CFuncTrackChange_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4bc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_14CBasePlatTrain;
    piVar2[0xf5] = (int)__vt_9CFuncPlat;
    piVar2[0xf5] = (int)__vt_12CFuncPlatRot;
    piVar2[0xf5] = (int)__vt_16CFuncTrackChange;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01  @ 0012dcf0
void GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_9CItemAmmo;
    piVar2[0xf5] = (int)__vt_16CItemAmmoRockets;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01  @ 0012da90
void GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_10CItemArmor;
    piVar2[0xf5] = (int)__vt_16CItemArmorYellow;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01  @ 0012dfe8
void GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_12CItemPowerup;
    piVar2[0xf5] = (int)__vt_16CItemPowerupQuad;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CRenderFxManager_PX01_PX01  @ 0012f15c
void GetClassPtr__H1Z16CRenderFxManager_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_16CRenderFxManager;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01  @ 0012e2d4
void GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x650);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_16CTFNapalmGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01  @ 0012e23c
void GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_16CTFNormalGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFSentrygunBase_PX01_PX01  @ 0012d510
void GetClassPtr__H1Z16CTFSentrygunBase_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_16CTFSentrygunBase;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTriggerMultiple_PX01_PX01  @ 0012f51c
void GetClassPtr__H1Z16CTriggerMultiple_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_16CTriggerMultiple;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTriggerTeleport_PX01_PX01  @ 0012fa60
void GetClassPtr__H1Z16CTriggerTeleport_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_16CTriggerTeleport;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CFrictionModifier_PX01_PX01  @ 0012ef20
void GetClassPtr__H1Z17CFrictionModifier_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_17CFrictionModifier;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CFuncTankControls_PX01_PX01  @ 0012aa38
void GetClassPtr__H1Z17CFuncTankControls_PX01_PX01(void)

{
  FUN_0012aa40();
  return;
}


// GetClassPtr__H1Z17CInfoIntermission_PX01_PX01  @ 0012d154
void GetClassPtr__H1Z17CInfoIntermission_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_17CInfoIntermission;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CScriptedSentence_PX01_PX01  @ 0012d36c
void GetClassPtr__H1Z17CScriptedSentence_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x49c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_17CScriptedSentence;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01  @ 0012e1a4
void GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_17CTFCaltropGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CCine2HeavyWeapons_PX01_PX01  @ 0012af0c
void GetClassPtr__H1Z18CCine2HeavyWeapons_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x61c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_18CLegacyCineMonster;
    piVar2[0xf5] = (int)__vt_18CCine2HeavyWeapons;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CFuncTrainControls_PX01_PX01  @ 0012cc98
void GetClassPtr__H1Z18CFuncTrainControls_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_18CFuncTrainControls;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CTFGrenadeLauncher_PX01_PX01  @ 00130c2c
void GetClassPtr__H1Z18CTFGrenadeLauncher_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x468);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_18CTFGrenadeLauncher;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CTriggerEndSection_PX01_PX01  @ 0012fbc0
void GetClassPtr__H1Z18CTriggerEndSection_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_18CTriggerEndSection;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01  @ 0012deb8
void GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_12CItemPowerup;
    piVar2[0xf5] = (int)__vt_19CItemPowerupRadsuit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CMomentaryRotButton_PX01_PX01  @ 00129410
void GetClassPtr__H1Z19CMomentaryRotButton_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4a0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_19CMomentaryRotButton;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CTFPipebombLauncher_PX01_PX01  @ 00130cdc
void GetClassPtr__H1Z19CTFPipebombLauncher_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x468);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_18CTFGrenadeLauncher;
    piVar2[0xf5] = (int)__vt_19CTFPipebombLauncher;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CTriggerMonsterJump_PX01_PX01  @ 0012f330
void GetClassPtr__H1Z19CTriggerMonsterJump_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_19CTriggerMonsterJump;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01  @ 0012e080
void GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x640);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_15CTFPrimeGrenade;
    piVar2[0xf5] = (int)__vt_20CTFConcussionGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFFlamethrowerBurst_PX01_PX01  @ 0012e6f0
void GetClassPtr__H1Z20CTFFlamethrowerBurst_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x63c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_20CTFFlamethrowerBurst;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01  @ 0012e77c
void GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x63c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_20CTFIncendiaryCRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTriggerChangeTarget_PX01_PX01  @ 0012fd20
void GetClassPtr__H1Z20CTriggerChangeTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_20CTriggerChangeTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01  @ 0012de20
void GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_12CItemPowerup;
    piVar2[0xf5] = (int)__vt_22CItemPowerupInvincible;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01  @ 001299c4
void GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_23CDispenserRefillThinker;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01  @ 0012df50
void GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_12CItemPowerup;
    piVar2[0xf5] = (int)__vt_24CItemPowerupInvisibility;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z4CGib_PX01_PX01  @ 0012973c
void GetClassPtr__H1Z4CGib_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),1000);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_4CGib;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CBeam_PX01_PX01  @ 00129d3c
void GetClassPtr__H1Z5CBeam_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CBeam;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CFade_PX01_PX01  @ 0012a2b4
void GetClassPtr__H1Z5CFade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_5CFade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CGlow_PX01_PX01  @ 00129ed4
void GetClassPtr__H1Z5CGlow_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_5CGlow;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CBlood_PX01_PX01  @ 0012a19c
void GetClassPtr__H1Z6CBlood_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_6CBlood;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CDecal_PX01_PX01  @ 0012ffdc
void GetClassPtr__H1Z6CDecal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_6CDecal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CGhost_PX01_PX01  @ 0012d8a8
void GetClassPtr__H1Z6CGhost_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_6CGhost;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CLaser_PX01_PX01  @ 00129e48
void GetClassPtr__H1Z6CLaser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3ec);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CBeam;
    piVar2[0xf5] = (int)__vt_6CLaser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CLight_PX01_PX01  @ 0012c448
void GetClassPtr__H1Z6CLight_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_6CLight;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CShake_PX01_PX01  @ 0012a228
void GetClassPtr__H1Z6CShake_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_6CShake;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTFAxe_PX01_PX01  @ 0013085c
void GetClassPtr__H1Z6CTFAxe_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4d4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_8CCrowbar;
    piVar2[0xf5] = (int)__vt_6CTFAxe;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTFRpg_PX01_PX01  @ 00131064
void GetClassPtr__H1Z6CTFRpg_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_6CTFRpg;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTimer_PX01_PX01  @ 0012eb7c
void GetClassPtr__H1Z6CTimer_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_6CTimer;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CWorld_PX01_PX01  @ 001300dc
void GetClassPtr__H1Z6CWorld_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_6CWorld;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CCineAI_PX01_PX01  @ 0012d2e0
void GetClassPtr__H1Z7CCineAI_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x650);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_12CCineMonster;
    piVar2[0xf5] = (int)__vt_7CCineAI;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CCorpse_PX01_PX01  @ 0013005c
void GetClassPtr__H1Z7CCorpse_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_7CCorpse;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CLadder_PX01_PX01  @ 0012f900
void GetClassPtr__H1Z7CLadder_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x478);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_12CBaseTrigger;
    piVar2[0xf5] = (int)__vt_7CLadder;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CMortar_PX01_PX01  @ 0012c610
void GetClassPtr__H1Z7CMortar_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x63c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_7CMortar;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CSentry_PX01_PX01  @ 0012ff50
void GetClassPtr__H1Z7CSentry_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x68c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_11CBaseTurret;
    piVar2[0xf5] = (int)__vt_7CSentry;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CShower_PX01_PX01  @ 0012a5e4
void GetClassPtr__H1Z7CShower_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_7CShower;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CSprite_PX01_PX01  @ 00129f60
void GetClassPtr__H1Z7CSprite_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_7CSprite;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CTFGoal_PX01_PX01  @ 0012ed40
void GetClassPtr__H1Z7CTFGoal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_7CTFGoal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CTurret_PX01_PX01  @ 0012fe38
void GetClassPtr__H1Z7CTurret_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x690);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_11CBaseTurret;
    piVar2[0xf5] = (int)__vt_7CTurret;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CAirtank_PX01_PX01  @ 00128d50
void GetClassPtr__H1Z8CAirtank_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x63c);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_8CAirtank;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CCrowbar_PX01_PX01  @ 00129808
void GetClassPtr__H1Z8CCrowbar_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x48c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_8CCrowbar;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CDeadHEV_PX01_PX01  @ 0012cfbc
void GetClassPtr__H1Z8CDeadHEV_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x620);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CDeadHEV;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CDetpack_PX01_PX01  @ 001298b8
void GetClassPtr__H1Z8CDetpack_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x644);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    piVar2[0xf5] = (int)__vt_8CDetpack;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CGrenade_PX01_PX01  @ 0012abb8
void GetClassPtr__H1Z8CGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x638);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CMessage_PX01_PX01  @ 0012a340
void GetClassPtr__H1Z8CMessage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_8CMessage;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CNodeEnt_PX01_PX01  @ 0012c69c
void GetClassPtr__H1Z8CNodeEnt_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_8CNodeEnt;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CRotDoor_PX01_PX01  @ 00129ae8
void GetClassPtr__H1Z8CRotDoor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4b4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_9CBaseDoor;
    piVar2[0xf5] = (int)__vt_8CRotDoor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CSpeaker_PX01_PX01  @ 0012d69c
void GetClassPtr__H1Z8CSpeaker_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_8CSpeaker;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFFlame_PX01_PX01  @ 0012d1e0
void GetClassPtr__H1Z8CTFFlame_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x620);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_8CTFFlame;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFKnife_PX01_PX01  @ 00130918
void GetClassPtr__H1Z8CTFKnife_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_8CCrowbar;
    piVar2[0xf5] = (int)__vt_6CTFAxe;
    piVar2[0xf5] = (int)__vt_8CTFKnife;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFSpawn_PX01_PX01  @ 0012ec40
void GetClassPtr__H1Z8CTFSpawn_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_8CTFSpawn;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFTranq_PX01_PX01  @ 00131330
void GetClassPtr__H1Z8CTFTranq_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x454);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_15CBasePlayerItem;
    piVar2[0xf5] = (int)__vt_17CBasePlayerWeapon;
    piVar2[0xf5] = (int)__vt_8CTFTranq;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenHair_PX01_PX01  @ 0013024c
void GetClassPtr__H1Z8CXenHair_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3f8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_13CActAnimating;
    piVar2[0xf5] = (int)__vt_8CXenHair;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenHull_PX01_PX01  @ 00130414
void GetClassPtr__H1Z8CXenHull_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_8CXenHull;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenTree_PX01_PX01  @ 00130370
void GetClassPtr__H1Z8CXenTree_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3fc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_13CActAnimating;
    piVar2[0xf5] = (int)__vt_8CXenTree;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CBaseDoor_PX01_PX01  @ 00129a44
void GetClassPtr__H1Z9CBaseDoor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x4b4);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_9CBaseDoor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CBubbling_PX01_PX01  @ 00129cbc
void GetClassPtr__H1Z9CBubbling_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),1000);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CBubbling;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvLight_PX01_PX01  @ 0012c4d4
void GetClassPtr__H1Z9CEnvLight_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_6CLight;
    piVar2[0xf5] = (int)__vt_9CEnvLight;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvSound_PX01_PX01  @ 0012d610
void GetClassPtr__H1Z9CEnvSound_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3e0);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_12CPointEntity;
    piVar2[0xf5] = (int)__vt_9CEnvSound;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvSpark_PX01_PX01  @ 001294b4
void GetClassPtr__H1Z9CEnvSpark_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CEnvSpark;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CFuncPlat_PX01_PX01  @ 0012c97c
void GetClassPtr__H1Z9CFuncPlat_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x480);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_14CBasePlatTrain;
    piVar2[0xf5] = (int)__vt_9CFuncPlat;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CFuncWall_PX01_PX01  @ 00128ddc
void GetClassPtr__H1Z9CFuncWall_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CFuncWall;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CItemSoda_PX01_PX01  @ 0012a4e4
void GetClassPtr__H1Z9CItemSoda_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CItemSoda;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CItemSuit_PX01_PX01  @ 0012badc
void GetClassPtr__H1Z9CItemSuit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3dc);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_5CItem;
    piVar2[0xf5] = (int)__vt_9CItemSuit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CPendulum_PX01_PX01  @ 00129124
void GetClassPtr__H1Z9CPendulum_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x408);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CPendulum;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CPushable_PX01_PX01  @ 0012a770
void GetClassPtr__H1Z9CPushable_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x404);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_10CBreakable;
    piVar2[0xf5] = (int)__vt_9CPushable;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CRecharge_PX01_PX01  @ 0012ac38
void GetClassPtr__H1Z9CRecharge_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x48c);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_10CBaseDelay;
    piVar2[0xf5] = (int)__vt_14CBaseAnimating;
    piVar2[0xf5] = (int)__vt_11CBaseToggle;
    piVar2[0xf5] = (int)__vt_9CRecharge;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CSoundEnt_PX01_PX01  @ 0012d71c
void GetClassPtr__H1Z9CSoundEnt_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0xbe8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CSoundEnt;
    iVar1 = 0x3f;
    do {
      iVar1 = iVar1 + -0x10;
    } while (iVar1 != -1);
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CSprayCan_PX01_PX01  @ 0012cf3c
void GetClassPtr__H1Z9CSprayCan_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CSprayCan;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CTFDetect_PX01_PX01  @ 0012ecc0
void GetClassPtr__H1Z9CTFDetect_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x3d8);
    __11CBaseEntity(piVar2);
    piVar2[0xf5] = (int)__vt_9CTFDetect;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CTestHull_PX01_PX01  @ 0012c71c
void GetClassPtr__H1Z9CTestHull_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x628);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_9CTestHull;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CWreckage_PX01_PX01  @ 0012b744
void GetClassPtr__H1Z9CWreckage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001a7e94)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)(*DAT_001a7f3c)(*(undefined4 *)(param_1 + 0x208),0x620);
    __12CBaseMonster(piVar2);
    piVar2[0xf5] = (int)__vt_9CWreckage;
    *piVar2 = param_1;
  }
  return;
}


