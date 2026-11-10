// GetClassPtr__H1Z10CBaseDelay_PX01_PX01  @ 0013dc34
void GetClassPtr__H1Z10CBaseDelay_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CBreakable_PX01_PX01  @ 0013adc0
void GetClassPtr__H1Z10CBreakable_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x468,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_10CBreakable;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CCineBlood_PX01_PX01  @ 0013b788
void GetClassPtr__H1Z10CCineBlood_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CCineBlood;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CEnvFunnel_PX01_PX01  @ 0013ab08
void GetClassPtr__H1Z10CEnvFunnel_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_10CEnvFunnel;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CEnvGlobal_PX01_PX01  @ 00139b0c
void GetClassPtr__H1Z10CEnvGlobal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_10CEnvGlobal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CFuncTrain_PX01_PX01  @ 0013d1b0
void GetClassPtr__H1Z10CFuncTrain_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4fc,param_1);
    piVar3 = (int *)__10CFuncTrain(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CFurniture_PX01_PX01  @ 0013d898
void GetClassPtr__H1Z10CFurniture_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_10CFurniture;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CGunTarget_PX01_PX01  @ 0013d3f0
void GetClassPtr__H1Z10CGunTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x690,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_10CGunTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CHealthKit_PX01_PX01  @ 0013c040
void GetClassPtr__H1Z10CHealthKit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CItem;
    piVar2[0x111] = (int)__vt_10CHealthKit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CLaserSpot_PX01_PX01  @ 0013ed24
void GetClassPtr__H1Z10CLaserSpot_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CLaserSpot;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CLightning_PX01_PX01  @ 0013a590
void GetClassPtr__H1Z10CLightning_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x47c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CBeam;
    piVar2[0x111] = (int)__vt_10CLightning;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CPathTrack_PX01_PX01  @ 0013cf88
void GetClassPtr__H1Z10CPathTrack_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x45c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_10CPathTrack;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CRotButton_PX01_PX01  @ 00139cac
void GetClassPtr__H1Z10CRotButton_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x520,param_1);
    piVar3 = (int *)__10CRotButton(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFBomblet_PX01_PX01  @ 0013ea1c
void GetClassPtr__H1Z10CTFBomblet_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    piVar3 = (int *)__10CTFBomblet(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFCaltrop_PX01_PX01  @ 00139ebc
void GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CTFCaltrop;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFGrenade_PX01_PX01  @ 0013ecb4
void GetClassPtr__H1Z10CTFGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_10CTFGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFMedikit_PX01_PX01  @ 00140b3c
void GetClassPtr__H1Z10CTFMedikit_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x54c,param_1);
    piVar3 = (int *)__10CTFMedikit(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFNailgun_PX01_PX01  @ 00140dfc
void GetClassPtr__H1Z10CTFNailgun_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    piVar3 = (int *)__10CTFNailgun(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFRailgun_PX01_PX01  @ 00140f00
void GetClassPtr__H1Z10CTFRailgun_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    piVar3 = (int *)__10CTFRailgun(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFRpgAmmo_PX01_PX01  @ 0013ec38
void GetClassPtr__H1Z10CTFRpgAmmo_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_15CBasePlayerAmmo;
    piVar2[0x111] = (int)__vt_10CTFRpgAmmo;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFShotgun_PX01_PX01  @ 00141028
void GetClassPtr__H1Z10CTFShotgun_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4d4,param_1);
    piVar3 = (int *)__10CTFShotgun(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFSpanner_PX01_PX01  @ 00140aa8
void GetClassPtr__H1Z10CTFSpanner_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x544,param_1);
    piVar3 = (int *)__10CTFSpanner(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTeamCheck_PX01_PX01  @ 0013f238
void GetClassPtr__H1Z10CTeamCheck_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_10CTeamCheck;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CWeaponBox_PX01_PX01  @ 00139f2c
void GetClassPtr__H1Z10CWeaponBox_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x56c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CWeaponBox;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CWorldItem_PX01_PX01  @ 0013c12c
void GetClassPtr__H1Z10CWorldItem_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CWorldItem;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CXenPLight_PX01_PX01  @ 001403e0
void GetClassPtr__H1Z10CXenPLight_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x46c,param_1);
    __13CActAnimating(piVar2);
    piVar2[0x111] = (int)__vt_10CXenPLight;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CBaseButton_PX01_PX01  @ 00139c04
void GetClassPtr__H1Z11CBaseButton_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x520,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_11CBaseButton;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CBasePlayer_PX01_PX01  @ 00139e60
void GetClassPtr__H1Z11CBasePlayer_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0xdec,param_1);
    piVar3 = (int *)__11CBasePlayer(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CCine2Slave_PX01_PX01  @ 0013b604
void GetClassPtr__H1Z11CCine2Slave_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    piVar3 = (int *)__11CCine2Slave(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CCineBarney_PX01_PX01  @ 0013b448
void GetClassPtr__H1Z11CCineBarney_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    piVar3 = (int *)__11CCineBarney(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CEnvShooter_PX01_PX01  @ 0013a840
void GetClassPtr__H1Z11CEnvShooter_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x46c,param_1);
    piVar3 = (int *)__11CEnvShooter(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CFireAndDie_PX01_PX01  @ 0013faa4
void GetClassPtr__H1Z11CFireAndDie_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_11CFireAndDie;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CGibShooter_PX01_PX01  @ 0013a780
void GetClassPtr__H1Z11CGibShooter_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x46c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_11CGibShooter;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CItemHealth_PX01_PX01  @ 0013dd78
void GetClassPtr__H1Z11CItemHealth_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CItem;
    piVar2[0x111] = (int)__vt_11CItemHealth;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CMiniTurret_PX01_PX01  @ 001400f0
void GetClassPtr__H1Z11CMiniTurret_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6fc,param_1);
    piVar3 = (int *)__11CMiniTurret(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CNodeViewer_PX01_PX01  @ 0013ce34
void GetClassPtr__H1Z11CNodeViewer_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x868,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_11CNodeViewer;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CNullEntity_PX01_PX01  @ 0013dbc4
void GetClassPtr__H1Z11CNullEntity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_11CNullEntity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CPathCorner_PX01_PX01  @ 0013cf0c
void GetClassPtr__H1Z11CPathCorner_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_11CPathCorner;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTFAssaultC_PX01_PX01  @ 0014087c
void GetClassPtr__H1Z11CTFAssaultC_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4d4,param_1);
    piVar3 = (int *)__11CTFAssaultC(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTFGoalItem_PX01_PX01  @ 0013f1c8
void GetClassPtr__H1Z11CTFGoalItem_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x468,param_1);
    __7CTFGoal(piVar2);
    piVar2[0x111] = (int)__vt_11CTFGoalItem;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTestEffect_PX01_PX01  @ 0013a89c
void GetClassPtr__H1Z11CTestEffect_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x51c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_11CTestEffect;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CWallHealth_PX01_PX01  @ 0013c0bc
void GetClassPtr__H1Z11CWallHealth_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4fc,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_11CWallHealth;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CAutoTrigger_PX01_PX01  @ 0013f410
void GetClassPtr__H1Z12CAutoTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x458,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_12CAutoTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CBaseTrigger_PX01_PX01  @ 0013f5e8
void GetClassPtr__H1Z12CBaseTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_12CBaseTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CChangeLevel_PX01_PX01  @ 0013fb58
void GetClassPtr__H1Z12CChangeLevel_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x530,param_1);
    piVar3 = (int *)__12CChangeLevel(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCine3Barney_PX01_PX01  @ 0013b72c
void GetClassPtr__H1Z12CCine3Barney_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    piVar3 = (int *)__12CCine3Barney(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCineMonster_PX01_PX01  @ 0013d724
void GetClassPtr__H1Z12CCineMonster_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6c0,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_12CCineMonster;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCinePanther_PX01_PX01  @ 0013b3b4
void GetClassPtr__H1Z12CCinePanther_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    piVar3 = (int *)__12CCinePanther(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCyclerProbe_PX01_PX01  @ 0013bd04
void GetClassPtr__H1Z12CCyclerProbe_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x690,param_1);
    piVar3 = (int *)__12CCyclerProbe(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CEnvBeverage_PX01_PX01  @ 0013ab84
void GetClassPtr__H1Z12CEnvBeverage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_12CEnvBeverage;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CFuncPlatRot_PX01_PX01  @ 0013d108
void GetClassPtr__H1Z12CFuncPlatRot_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x508,param_1);
    __9CFuncPlat(piVar2);
    piVar2[0x111] = (int)__vt_12CFuncPlatRot;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CFuncTankGun_PX01_PX01  @ 0013aedc
void GetClassPtr__H1Z12CFuncTankGun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncTank;
    piVar2[0x111] = (int)__vt_12CFuncTankGun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CHandGrenade_PX01_PX01  @ 0013bfe4
void GetClassPtr__H1Z12CHandGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c8,param_1);
    piVar3 = (int *)__12CHandGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CItemBattery_PX01_PX01  @ 0013c218
void GetClassPtr__H1Z12CItemBattery_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CItem;
    piVar2[0x111] = (int)__vt_12CItemBattery;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CMultiSource_PX01_PX01  @ 00139b88
void GetClassPtr__H1Z12CMultiSource_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x5d0,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_12CMultiSource;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CNoBuildArea_PX01_PX01  @ 0013ac70
void GetClassPtr__H1Z12CNoBuildArea_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CNoBuildArea;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CPlatTrigger_PX01_PX01  @ 0013d098
void GetClassPtr__H1Z12CPlatTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPlatTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CPointEntity_PX01_PX01  @ 0013a440
void GetClassPtr__H1Z12CPointEntity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CRevertSaved_PX01_PX01  @ 0013d5bc
void GetClassPtr__H1Z12CRevertSaved_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_12CRevertSaved;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFAutoRifle_PX01_PX01  @ 00140910
void GetClassPtr__H1Z12CTFAutoRifle_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    piVar3 = (int *)__12CTFAutoRifle(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFDispenser_PX01_PX01  @ 0013a1ec
void GetClassPtr__H1Z12CTFDispenser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x698,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_12CTFDispenser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01  @ 0013ebc8
void GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6ac,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_12CTFRpgRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFSentrygun_PX01_PX01  @ 0013d908
void GetClassPtr__H1Z12CTFSentrygun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6c4,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_12CTFSentrygun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFTimerGoal_PX01_PX01  @ 0013f158
void GetClassPtr__H1Z12CTFTimerGoal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x464,param_1);
    __7CTFGoal(piVar2);
    piVar2[0x111] = (int)__vt_12CTFTimerGoal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerHurt_PX01_PX01  @ 0013f690
void GetClassPtr__H1Z12CTriggerHurt_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__12CTriggerHurt(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerOnce_PX01_PX01  @ 0013f924
void GetClassPtr__H1Z12CTriggerOnce_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    __16CTriggerMultiple(piVar2);
    piVar2[0x111] = (int)__vt_12CTriggerOnce;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerPush_PX01_PX01  @ 0013fc80
void GetClassPtr__H1Z12CTriggerPush_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__12CTriggerPush(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerSave_PX01_PX01  @ 0013fda8
void GetClassPtr__H1Z12CTriggerSave_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__12CTriggerSave(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CXenSporeMed_PX01_PX01  @ 001406e8
void GetClassPtr__H1Z12CXenSporeMed_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x468,param_1);
    piVar3 = (int *)__12CXenSporeMed(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CButtonTarget_PX01_PX01  @ 00139de8
void GetClassPtr__H1Z13CButtonTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_13CButtonTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CCyclerSprite_PX01_PX01  @ 0013bd60
void GetClassPtr__H1Z13CCyclerSprite_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_13CCyclerSprite;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CEnvExplosion_PX01_PX01  @ 0013ad50
void GetClassPtr__H1Z13CEnvExplosion_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x694,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_13CEnvExplosion;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CFuncConveyor_PX01_PX01  @ 00139880
void GetClassPtr__H1Z13CFuncConveyor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncWall;
    piVar2[0x111] = (int)__vt_13CFuncConveyor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CFuncRotating_PX01_PX01  @ 00139a2c
void GetClassPtr__H1Z13CFuncRotating_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x45c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_13CFuncRotating;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemAntidote_PX01_PX01  @ 0013c294
void GetClassPtr__H1Z13CItemAntidote_PX01_PX01(void)

{
  FUN_0013c29c();
  return;
}


// GetClassPtr__H1Z13CItemArmorRed_PX01_PX01  @ 0013df78
void GetClassPtr__H1Z13CItemArmorRed_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    piVar3 = (int *)__13CItemArmorRed(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemLongJump_PX01_PX01  @ 0013c38c
void GetClassPtr__H1Z13CItemLongJump_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CItem;
    piVar2[0x111] = (int)__vt_13CItemLongJump;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemSecurity_PX01_PX01  @ 0013c310
void GetClassPtr__H1Z13CItemSecurity_PX01_PX01(void)

{
  FUN_0013c318();
  return;
}


// GetClassPtr__H1Z13CMultiManager_PX01_PX01  @ 0013f508
void GetClassPtr__H1Z13CMultiManager_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x574,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_13CMultiManager;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CStripWeapons_PX01_PX01  @ 0013d540
void GetClassPtr__H1Z13CStripWeapons_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_13CStripWeapons;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01  @ 0013e988
void GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    piVar3 = (int *)__13CTFEMPGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01  @ 0013e8f4
void GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b4,param_1);
    piVar3 = (int *)__13CTFGasGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTriggerRelay_PX01_PX01  @ 0013f48c
void GetClassPtr__H1Z13CTriggerRelay_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_13CTriggerRelay;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CWeaponCycler_PX01_PX01  @ 0013be08
void GetClassPtr__H1Z13CWeaponCycler_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c8,param_1);
    piVar3 = (int *)__13CWeaponCycler(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CCineScientist_PX01_PX01  @ 0013b320
void GetClassPtr__H1Z14CCineScientist_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    piVar3 = (int *)__14CCineScientist(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CFuncTankLaser_PX01_PX01  @ 0013af58
void GetClassPtr__H1Z14CFuncTankLaser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4cc,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncTank;
    piVar2[0x111] = (int)__vt_14CFuncTankLaser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CFuncTrackAuto_PX01_PX01  @ 0013d380
void GetClassPtr__H1Z14CFuncTrackAuto_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x52c,param_1);
    __16CFuncTrackChange(piVar2);
    piVar2[0x111] = (int)__vt_14CFuncTrackAuto;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CGenericCycler_PX01_PX01  @ 0013bc70
void GetClassPtr__H1Z14CGenericCycler_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x690,param_1);
    piVar3 = (int *)__14CGenericCycler(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01  @ 0013e1f8
void GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    piVar3 = (int *)__14CItemAmmoCells(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01  @ 0013e0b8
void GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    piVar3 = (int *)__14CItemAmmoNails(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CMomentaryDoor_PX01_PX01  @ 0013a3d0
void GetClassPtr__H1Z14CMomentaryDoor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4ec,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_14CMomentaryDoor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CNoGrenadeArea_PX01_PX01  @ 0013f330
void GetClassPtr__H1Z14CNoGrenadeArea_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_14CNoGrenadeArea;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFIncendiaryC_PX01_PX01  @ 00140d68
void GetClassPtr__H1Z14CTFIncendiaryC_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    piVar3 = (int *)__14CTFIncendiaryC(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01  @ 0013e860
void GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    piVar3 = (int *)__14CTFMirvGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01  @ 0013e7cc
void GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    piVar3 = (int *)__14CTFNailGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01  @ 0013ea78
void GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6b4,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_14CTFNailgunNail;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFSniperRifle_PX01_PX01  @ 0014112c
void GetClassPtr__H1Z14CTFSniperRifle_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4cc,param_1);
    piVar3 = (int *)__14CTFSniperRifle(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTargetCDAudio_PX01_PX01  @ 0013f814
void GetClassPtr__H1Z14CTargetCDAudio_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_14CTargetCDAudio;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTelefragDeath_PX01_PX01  @ 0013b13c
void GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(void)

{
  FUN_0013b144();
  return;
}


// GetClassPtr__H1Z14CTriggerCamera_PX01_PX01  @ 0013ffa8
void GetClassPtr__H1Z14CTriggerCamera_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x48c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_14CTriggerCamera;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTriggerVolume_PX01_PX01  @ 0013fa28
void GetClassPtr__H1Z14CTriggerVolume_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_14CTriggerVolume;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CXenSporeLarge_PX01_PX01  @ 0014077c
void GetClassPtr__H1Z14CXenSporeLarge_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x468,param_1);
    piVar3 = (int *)__14CXenSporeLarge(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CXenSporeSmall_PX01_PX01  @ 00140654
void GetClassPtr__H1Z14CXenSporeSmall_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x468,param_1);
    piVar3 = (int *)__14CXenSporeSmall(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CAmbientGeneric_PX01_PX01  @ 0013d9e8
void GetClassPtr__H1Z15CAmbientGeneric_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4b8,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_15CAmbientGeneric;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CCine2Scientist_PX01_PX01  @ 0013b4dc
void GetClassPtr__H1Z15CCine2Scientist_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    piVar3 = (int *)__15CCine2Scientist(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CCine3Scientist_PX01_PX01  @ 0013b698
void GetClassPtr__H1Z15CCine3Scientist_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    piVar3 = (int *)__15CCine3Scientist(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTankMortar_PX01_PX01  @ 0013b050
void GetClassPtr__H1Z15CFuncTankMortar_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncTank;
    piVar2[0x111] = (int)__vt_15CFuncTankMortar;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTankRocket_PX01_PX01  @ 0013afd4
void GetClassPtr__H1Z15CFuncTankRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncTank;
    piVar2[0x111] = (int)__vt_15CFuncTankRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTrackTrain_PX01_PX01  @ 0013d20c
void GetClassPtr__H1Z15CFuncTrackTrain_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x490,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_15CFuncTrackTrain;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncWallToggle_PX01_PX01  @ 00139804
void GetClassPtr__H1Z15CFuncWallToggle_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncWall;
    piVar2[0x111] = (int)__vt_15CFuncWallToggle;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CGenericMonster_PX01_PX01  @ 0013b1ac
void GetClassPtr__H1Z15CGenericMonster_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x68c,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_15CGenericMonster;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01  @ 0013e018
void GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    piVar3 = (int *)__15CItemAmmoShells(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01  @ 0013de38
void GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    piVar3 = (int *)__15CItemArmorGreen(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFFlamethrower_PX01_PX01  @ 00140bd0
void GetClassPtr__H1Z15CTFFlamethrower_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    piVar3 = (int *)__15CTFFlamethrower(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFPrimeGrenade_PX01_PX01  @ 0013e568
void GetClassPtr__H1Z15CTFPrimeGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_15CTFPrimeGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFSuperNailgun_PX01_PX01  @ 00140e58
void GetClassPtr__H1Z15CTFSuperNailgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4c8,param_1);
    __10CTFNailgun(piVar2);
    piVar2[0x111] = (int)__vt_15CTFSuperNailgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFSuperShotgun_PX01_PX01  @ 00141084
void GetClassPtr__H1Z15CTFSuperShotgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4d8,param_1);
    __10CTFShotgun(piVar2);
    piVar2[0x111] = (int)__vt_15CTFSuperShotgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerCDAudio_PX01_PX01  @ 0013f7b8
void GetClassPtr__H1Z15CTriggerCDAudio_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__15CTriggerCDAudio(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerCounter_PX01_PX01  @ 0013f9cc
void GetClassPtr__H1Z15CTriggerCounter_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__15CTriggerCounter(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerGravity_PX01_PX01  @ 0013fed0
void GetClassPtr__H1Z15CTriggerGravity_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__15CTriggerGravity(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01  @ 001404c0
void GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_15CXenTreeTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncIllusionary_PX01_PX01  @ 00139940
void GetClassPtr__H1Z16CFuncIllusionary_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_16CFuncIllusionary;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncMonsterClip_PX01_PX01  @ 001399b0
void GetClassPtr__H1Z16CFuncMonsterClip_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncWall;
    piVar2[0x111] = (int)__vt_16CFuncMonsterClip;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncMortarField_PX01_PX01  @ 0013cc74
void GetClassPtr__H1Z16CFuncMortarField_PX01_PX01(void)

{
  FUN_0013cc7c();
  return;
}


// GetClassPtr__H1Z16CFuncTrackChange_PX01_PX01  @ 0013d324
void GetClassPtr__H1Z16CFuncTrackChange_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x52c,param_1);
    piVar3 = (int *)__16CFuncTrackChange(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01  @ 0013e158
void GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    piVar3 = (int *)__16CItemAmmoRockets(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01  @ 0013ded8
void GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    piVar3 = (int *)__16CItemArmorYellow(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01  @ 0013e478
void GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    piVar3 = (int *)__16CItemPowerupQuad(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CRenderFxManager_PX01_PX01  @ 0013f578
void GetClassPtr__H1Z16CRenderFxManager_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_16CRenderFxManager;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01  @ 0013e738
void GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6c0,param_1);
    piVar3 = (int *)__16CTFNapalmGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01  @ 0013e6a4
void GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    piVar3 = (int *)__16CTFNormalGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFSentrygunBase_PX01_PX01  @ 0013d978
void GetClassPtr__H1Z16CTFSentrygunBase_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_16CTFSentrygunBase;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTriggerMultiple_PX01_PX01  @ 0013f8c8
void GetClassPtr__H1Z16CTriggerMultiple_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__16CTriggerMultiple(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTriggerTeleport_PX01_PX01  @ 0013fd14
void GetClassPtr__H1Z16CTriggerTeleport_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__16CTriggerTeleport(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CFrictionModifier_PX01_PX01  @ 0013f3a0
void GetClassPtr__H1Z17CFrictionModifier_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_17CFrictionModifier;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CFuncTankControls_PX01_PX01  @ 0013b0cc
void GetClassPtr__H1Z17CFuncTankControls_PX01_PX01(void)

{
  FUN_0013b0d4();
  return;
}


// GetClassPtr__H1Z17CInfoIntermission_PX01_PX01  @ 0013d638
void GetClassPtr__H1Z17CInfoIntermission_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_17CInfoIntermission;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CScriptedSentence_PX01_PX01  @ 0013d828
void GetClassPtr__H1Z17CScriptedSentence_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x50c,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_17CScriptedSentence;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01  @ 0013e610
void GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    piVar3 = (int *)__17CTFCaltropGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CCine2HeavyWeapons_PX01_PX01  @ 0013b570
void GetClassPtr__H1Z18CCine2HeavyWeapons_PX01_PX01(void)

{
  FUN_0013b577();
  return;
}


// GetClassPtr__H1Z18CFuncTrainControls_PX01_PX01  @ 0013d27c
void GetClassPtr__H1Z18CFuncTrainControls_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_18CFuncTrainControls;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CTFGrenadeLauncher_PX01_PX01  @ 00140c64
void GetClassPtr__H1Z18CTFGrenadeLauncher_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4d8,param_1);
    piVar3 = (int *)__18CTFGrenadeLauncher(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CTriggerEndSection_PX01_PX01  @ 0013fe3c
void GetClassPtr__H1Z18CTriggerEndSection_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__18CTriggerEndSection(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01  @ 0013e338
void GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    piVar3 = (int *)__19CItemPowerupRadsuit(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CMomentaryRotButton_PX01_PX01  @ 00139d08
void GetClassPtr__H1Z19CMomentaryRotButton_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x510,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_19CMomentaryRotButton;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CTFPipebombLauncher_PX01_PX01  @ 00140cc0
void GetClassPtr__H1Z19CTFPipebombLauncher_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4d8,param_1);
    __18CTFGrenadeLauncher(piVar2);
    piVar2[0x111] = (int)__vt_19CTFPipebombLauncher;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CTriggerMonsterJump_PX01_PX01  @ 0013f724
void GetClassPtr__H1Z19CTriggerMonsterJump_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__19CTriggerMonsterJump(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01  @ 0013e50c
void GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6b0,param_1);
    piVar3 = (int *)__20CTFConcussionGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFFlamethrowerBurst_PX01_PX01  @ 0013eae8
void GetClassPtr__H1Z20CTFFlamethrowerBurst_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6ac,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_20CTFFlamethrowerBurst;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01  @ 0013eb58
void GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6ac,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_20CTFIncendiaryCRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTriggerChangeTarget_PX01_PX01  @ 0013ff2c
void GetClassPtr__H1Z20CTriggerChangeTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x454,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_20CTriggerChangeTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01  @ 0013e298
void GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    piVar3 = (int *)__22CItemPowerupInvincible(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01  @ 0013a25c
void GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x464,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_23CDispenserRefillThinker;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01  @ 0013e3d8
void GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    piVar3 = (int *)__24CItemPowerupInvisibility(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z4CGib_PX01_PX01  @ 00139f9c
void GetClassPtr__H1Z4CGib_PX01_PX01(void)

{
  FUN_00139fa4();
  return;
}


// GetClassPtr__H1Z5CBeam_PX01_PX01  @ 0013a520
void GetClassPtr__H1Z5CBeam_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CBeam;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CFade_PX01_PX01  @ 0013aa10
void GetClassPtr__H1Z5CFade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_5CFade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CGlow_PX01_PX01  @ 0013a688
void GetClassPtr__H1Z5CGlow_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_5CGlow;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CBlood_PX01_PX01  @ 0013a918
void GetClassPtr__H1Z6CBlood_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_6CBlood;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CDecal_PX01_PX01  @ 001401e0
void GetClassPtr__H1Z6CDecal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_6CDecal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CGhost_PX01_PX01  @ 0013dca4
void GetClassPtr__H1Z6CGhost_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_6CGhost;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CLaser_PX01_PX01  @ 0013a60c
void GetClassPtr__H1Z6CLaser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x45c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CBeam;
    piVar2[0x111] = (int)__vt_6CLaser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CLight_PX01_PX01  @ 0013cb58
void GetClassPtr__H1Z6CLight_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_6CLight;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CShake_PX01_PX01  @ 0013a994
void GetClassPtr__H1Z6CShake_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_6CShake;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTFAxe_PX01_PX01  @ 0014096c
void GetClassPtr__H1Z6CTFAxe_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x544,param_1);
    __8CCrowbar(piVar2);
    piVar2[0x111] = (int)__vt_6CTFAxe;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTFRpg_PX01_PX01  @ 00140f94
void GetClassPtr__H1Z6CTFRpg_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    piVar3 = (int *)__6CTFRpg(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTimer_PX01_PX01  @ 0013ef04
void GetClassPtr__H1Z6CTimer_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_6CTimer;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CWorld_PX01_PX01  @ 001402c0
void GetClassPtr__H1Z6CWorld_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_6CWorld;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CCineAI_PX01_PX01  @ 0013d7cc
void GetClassPtr__H1Z7CCineAI_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6c0,param_1);
    piVar3 = (int *)__7CCineAI(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CCorpse_PX01_PX01  @ 00140250
void GetClassPtr__H1Z7CCorpse_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_7CCorpse;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CLadder_PX01_PX01  @ 0013fbec
void GetClassPtr__H1Z7CLadder_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e8,param_1);
    piVar3 = (int *)__7CLadder(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CMortar_PX01_PX01  @ 0013cce4
void GetClassPtr__H1Z7CMortar_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6ac,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_7CMortar;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CSentry_PX01_PX01  @ 00140184
void GetClassPtr__H1Z7CSentry_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6fc,param_1);
    piVar3 = (int *)__7CSentry(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CShower_PX01_PX01  @ 0013ace0
void GetClassPtr__H1Z7CShower_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_7CShower;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CSprite_PX01_PX01  @ 0013a704
void GetClassPtr__H1Z7CSprite_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_7CSprite;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CTFGoal_PX01_PX01  @ 0013f0fc
void GetClassPtr__H1Z7CTFGoal_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x464,param_1);
    piVar3 = (int *)__7CTFGoal(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CTurret_PX01_PX01  @ 0014005c
void GetClassPtr__H1Z7CTurret_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x700,param_1);
    piVar3 = (int *)__7CTurret(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CAirtank_PX01_PX01  @ 0013969c
void GetClassPtr__H1Z8CAirtank_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6ac,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_8CAirtank;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CAreaDef_PX01_PX01  @ 0013970c
void GetClassPtr__H1Z8CAreaDef_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar4 = 0x139759;
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4fc,param_1);
    piVar3 = (int *)__8CAreaDefb(uVar2,uVar4 & 0xffff0000);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CCrowbar_PX01_PX01  @ 0013a0f4
void GetClassPtr__H1Z8CCrowbar_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4fc,param_1);
    piVar3 = (int *)__8CCrowbar(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CDeadHEV_PX01_PX01  @ 0013d4d0
void GetClassPtr__H1Z8CDeadHEV_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x690,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_8CDeadHEV;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CDetpack_PX01_PX01  @ 0013a150
void GetClassPtr__H1Z8CDetpack_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6b4,param_1);
    __8CGrenade(piVar2);
    piVar2[0x111] = (int)__vt_8CDetpack;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CGrenade_PX01_PX01  @ 0013b21c
void GetClassPtr__H1Z8CGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6a8,param_1);
    piVar3 = (int *)__8CGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CMessage_PX01_PX01  @ 0013aa8c
void GetClassPtr__H1Z8CMessage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_8CMessage;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CNodeEnt_PX01_PX01  @ 0013cd54
void GetClassPtr__H1Z8CNodeEnt_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_8CNodeEnt;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CRotDoor_PX01_PX01  @ 0013a374
void GetClassPtr__H1Z8CRotDoor_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x524,param_1);
    piVar3 = (int *)__8CRotDoor(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CSpeaker_PX01_PX01  @ 0013dad4
void GetClassPtr__H1Z8CSpeaker_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_8CSpeaker;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFFlame_PX01_PX01  @ 0013d6b4
void GetClassPtr__H1Z8CTFFlame_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x690,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_8CTFFlame;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFKnife_PX01_PX01  @ 00140a14
void GetClassPtr__H1Z8CTFKnife_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x548,param_1);
    piVar3 = (int *)__8CTFKnife(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFSpawn_PX01_PX01  @ 0013efd8
void GetClassPtr__H1Z8CTFSpawn_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_8CTFSpawn;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFTranq_PX01_PX01  @ 001411c0
void GetClassPtr__H1Z8CTFTranq_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4c4,param_1);
    piVar3 = (int *)__8CTFTranq(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTeamSet_PX01_PX01  @ 0013f2b4
void GetClassPtr__H1Z8CTeamSet_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_10CBaseDelay;
    piVar2[0x111] = (int)__vt_8CTeamSet;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenHair_PX01_PX01  @ 00140450
void GetClassPtr__H1Z8CXenHair_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x468,param_1);
    __13CActAnimating(piVar2);
    piVar2[0x111] = (int)__vt_8CXenHair;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenHull_PX01_PX01  @ 001405a0
void GetClassPtr__H1Z8CXenHull_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_8CXenHull;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenTree_PX01_PX01  @ 00140530
void GetClassPtr__H1Z8CXenTree_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x46c,param_1);
    __13CActAnimating(piVar2);
    piVar2[0x111] = (int)__vt_8CXenTree;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CBaseDoor_PX01_PX01  @ 0013a2cc
void GetClassPtr__H1Z9CBaseDoor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x524,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_9CBaseDoor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CBubbling_PX01_PX01  @ 0013a4b0
void GetClassPtr__H1Z9CBubbling_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x458,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CBubbling;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvLight_PX01_PX01  @ 0013cc18
void GetClassPtr__H1Z9CEnvLight_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    piVar3 = (int *)__9CEnvLight(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvSound_PX01_PX01  @ 0013da58
void GetClassPtr__H1Z9CEnvSound_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x450,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_12CPointEntity;
    piVar2[0x111] = (int)__vt_9CEnvSound;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvSpark_PX01_PX01  @ 00139d78
void GetClassPtr__H1Z9CEnvSpark_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CEnvSpark;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CFuncPlat_PX01_PX01  @ 0013d03c
void GetClassPtr__H1Z9CFuncPlat_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f0,param_1);
    piVar3 = (int *)__9CFuncPlat(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CFuncWall_PX01_PX01  @ 00139794
void GetClassPtr__H1Z9CFuncWall_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CFuncWall;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CItemSoda_PX01_PX01  @ 0013ac00
void GetClassPtr__H1Z9CItemSoda_PX01_PX01(void)

{
  FUN_0013ac08();
  return;
}


// GetClassPtr__H1Z9CItemSuit_PX01_PX01  @ 0013c19c
void GetClassPtr__H1Z9CItemSuit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x44c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_5CItem;
    piVar2[0x111] = (int)__vt_9CItemSuit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CPendulum_PX01_PX01  @ 00139a9c
void GetClassPtr__H1Z9CPendulum_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x478,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CPendulum;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CPushable_PX01_PX01  @ 0013ae80
void GetClassPtr__H1Z9CPushable_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x474,param_1);
    piVar3 = (int *)__9CPushable(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CRecharge_PX01_PX01  @ 0013b278
void GetClassPtr__H1Z9CRecharge_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4fc,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x111] = (int)__vt_9CRecharge;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CSoundEnt_PX01_PX01  @ 0013db44
void GetClassPtr__H1Z9CSoundEnt_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0xc58,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CSoundEnt;
    iVar1 = 0x3f;
    do {
      iVar1 = iVar1 + -0x10;
    } while (iVar1 != -1);
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CSprayCan_PX01_PX01  @ 0013d460
void GetClassPtr__H1Z9CSprayCan_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CSprayCan;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CTFDetect_PX01_PX01  @ 0013f048
void GetClassPtr__H1Z9CTFDetect_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x448,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x111] = (int)__vt_9CTFDetect;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CTestHull_PX01_PX01  @ 0013cdc4
void GetClassPtr__H1Z9CTestHull_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x698,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_9CTestHull;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CWreckage_PX01_PX01  @ 0013be64
void GetClassPtr__H1Z9CWreckage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_001c1074)();
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
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x690,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x111] = (int)__vt_9CWreckage;
    *piVar2 = param_1;
  }
  return;
}


