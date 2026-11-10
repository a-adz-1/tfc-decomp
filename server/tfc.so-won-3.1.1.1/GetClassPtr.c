// GetClassPtr__H1Z10CBaseDelay_PX01_PX01  @ 00142d6c
void GetClassPtr__H1Z10CBaseDelay_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CBreakable_PX01_PX01  @ 0013fc20
void GetClassPtr__H1Z10CBreakable_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_10CBreakable;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CCineBlood_PX01_PX01  @ 00140878
void GetClassPtr__H1Z10CCineBlood_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CCineBlood;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CEnvFunnel_PX01_PX01  @ 0013f770
void GetClassPtr__H1Z10CEnvFunnel_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_10CEnvFunnel;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CEnvGlobal_PX01_PX01  @ 0013e7f8
void GetClassPtr__H1Z10CEnvGlobal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_10CEnvGlobal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CFuncTrain_PX01_PX01  @ 00142304
void GetClassPtr__H1Z10CFuncTrain_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x50c,param_1);
    piVar3 = (int *)__10CFuncTrain(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CFurniture_PX01_PX01  @ 001429b0
void GetClassPtr__H1Z10CFurniture_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_10CFurniture;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CGunTarget_PX01_PX01  @ 0014228c
void GetClassPtr__H1Z10CGunTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6a0,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_10CGunTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CHealthKit_PX01_PX01  @ 0014103c
void GetClassPtr__H1Z10CHealthKit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CItem;
    piVar2[0x115] = (int)__vt_10CHealthKit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CLaserSpot_PX01_PX01  @ 001442dc
void GetClassPtr__H1Z10CLaserSpot_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CLaserSpot;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CLightning_PX01_PX01  @ 0013f1fc
void GetClassPtr__H1Z10CLightning_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CBeam;
    piVar2[0x115] = (int)__vt_10CLightning;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CPathTrack_PX01_PX01  @ 00142058
void GetClassPtr__H1Z10CPathTrack_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_10CPathTrack;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CRotButton_PX01_PX01  @ 0013eb20
void GetClassPtr__H1Z10CRotButton_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__10CRotButton(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFBomblet_PX01_PX01  @ 00143b14
void GetClassPtr__H1Z10CTFBomblet_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__10CTFBomblet(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFCaltrop_PX01_PX01  @ 0013ec04
void GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CTFCaltrop;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFGrenade_PX01_PX01  @ 001440d8
void GetClassPtr__H1Z10CTFGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_10CTFGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFMedikit_PX01_PX01  @ 00146104
void GetClassPtr__H1Z10CTFMedikit_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x55c,param_1);
    piVar3 = (int *)__10CTFMedikit(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFNailgun_PX01_PX01  @ 00146534
void GetClassPtr__H1Z10CTFNailgun_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__10CTFNailgun(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFRailgun_PX01_PX01  @ 001465d4
void GetClassPtr__H1Z10CTFRailgun_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__10CTFRailgun(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFRpgAmmo_PX01_PX01  @ 00144054
void GetClassPtr__H1Z10CTFRpgAmmo_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_15CBasePlayerAmmo;
    piVar2[0x115] = (int)__vt_10CTFRpgAmmo;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFShotgun_PX01_PX01  @ 0014678c
void GetClassPtr__H1Z10CTFShotgun_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e4,param_1);
    piVar3 = (int *)__10CTFShotgun(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTFSpanner_PX01_PX01  @ 00146164
void GetClassPtr__H1Z10CTFSpanner_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x554,param_1);
    piVar3 = (int *)__10CTFSpanner(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CTeamCheck_PX01_PX01  @ 00144578
void GetClassPtr__H1Z10CTeamCheck_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_10CTeamCheck;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CWeaponBox_PX01_PX01  @ 0013eb8c
void GetClassPtr__H1Z10CWeaponBox_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x57c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CWeaponBox;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CWorldItem_PX01_PX01  @ 00141b58
void GetClassPtr__H1Z10CWorldItem_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CWorldItem;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z10CXenPLight_PX01_PX01  @ 001459cc
void GetClassPtr__H1Z10CXenPLight_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __13CActAnimating(piVar2);
    piVar2[0x115] = (int)__vt_10CXenPLight;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CBaseButton_PX01_PX01  @ 0013e900
void GetClassPtr__H1Z11CBaseButton_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x530,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x115] = (int)__vt_11CBaseButton;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CBasePlayer_PX01_PX01  @ 0013ec7c
void GetClassPtr__H1Z11CBasePlayer_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0xe08,param_1);
    piVar3 = (int *)__11CBasePlayer(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CCine2Slave_PX01_PX01  @ 001409b0
void GetClassPtr__H1Z11CCine2Slave_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__11CCine2Slave(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CCineBarney_PX01_PX01  @ 00140ad0
void GetClassPtr__H1Z11CCineBarney_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__11CCineBarney(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CEnvShooter_PX01_PX01  @ 0013f968
void GetClassPtr__H1Z11CEnvShooter_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x47c,param_1);
    piVar3 = (int *)__11CEnvShooter(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CFireAndDie_PX01_PX01  @ 00144d00
void GetClassPtr__H1Z11CFireAndDie_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_11CFireAndDie;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CGibShooter_PX01_PX01  @ 0013f40c
void GetClassPtr__H1Z11CGibShooter_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_11CGibShooter;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CItemHealth_PX01_PX01  @ 00143074
void GetClassPtr__H1Z11CItemHealth_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CItem;
    piVar2[0x115] = (int)__vt_11CItemHealth;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CMiniTurret_PX01_PX01  @ 001456dc
void GetClassPtr__H1Z11CMiniTurret_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x70c,param_1);
    piVar3 = (int *)__11CMiniTurret(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CNodeViewer_PX01_PX01  @ 00141ee4
void GetClassPtr__H1Z11CNodeViewer_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x878,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_11CNodeViewer;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CNullEntity_PX01_PX01  @ 00142de4
void GetClassPtr__H1Z11CNullEntity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_11CNullEntity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CPathCorner_PX01_PX01  @ 00141fd4
void GetClassPtr__H1Z11CPathCorner_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_11CPathCorner;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTFAssaultC_PX01_PX01  @ 00145ecc
void GetClassPtr__H1Z11CTFAssaultC_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4e4,param_1);
    piVar3 = (int *)__11CTFAssaultC(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTFGoalItem_PX01_PX01  @ 00144500
void GetClassPtr__H1Z11CTFGoalItem_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __7CTFGoal(piVar2);
    piVar2[0x115] = (int)__vt_11CTFGoalItem;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CTestEffect_PX01_PX01  @ 0013f4dc
void GetClassPtr__H1Z11CTestEffect_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_11CTestEffect;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z11CWallHealth_PX01_PX01  @ 001410c0
void GetClassPtr__H1Z11CWallHealth_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_11CWallHealth;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CAutoTrigger_PX01_PX01  @ 00144848
void GetClassPtr__H1Z12CAutoTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_12CAutoTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CBaseTrigger_PX01_PX01  @ 001449c8
void GetClassPtr__H1Z12CBaseTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x115] = (int)__vt_12CBaseTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CChangeLevel_PX01_PX01  @ 0014504c
void GetClassPtr__H1Z12CChangeLevel_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x540,param_1);
    piVar3 = (int *)__12CChangeLevel(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCine3Barney_PX01_PX01  @ 001408f0
void GetClassPtr__H1Z12CCine3Barney_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__12CCine3Barney(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCineMonster_PX01_PX01  @ 00142880
void GetClassPtr__H1Z12CCineMonster_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6d0,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_12CCineMonster;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCinePanther_PX01_PX01  @ 00140b30
void GetClassPtr__H1Z12CCinePanther_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__12CCinePanther(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CCyclerProbe_PX01_PX01  @ 00140edc
void GetClassPtr__H1Z12CCyclerProbe_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6a0,param_1);
    piVar3 = (int *)__12CCyclerProbe(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CEnvBeverage_PX01_PX01  @ 0013f7f4
void GetClassPtr__H1Z12CEnvBeverage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_12CEnvBeverage;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CFuncPlatRot_PX01_PX01  @ 0014211c
void GetClassPtr__H1Z12CFuncPlatRot_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x518,param_1);
    __9CFuncPlat(piVar2);
    piVar2[0x115] = (int)__vt_12CFuncPlatRot;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CFuncTankGun_PX01_PX01  @ 0013fd50
void GetClassPtr__H1Z12CFuncTankGun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4d4,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_9CFuncTank;
    piVar2[0x115] = (int)__vt_12CFuncTankGun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CHandGrenade_PX01_PX01  @ 00140fdc
void GetClassPtr__H1Z12CHandGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__12CHandGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CItemBattery_PX01_PX01  @ 001411bc
void GetClassPtr__H1Z12CItemBattery_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CItem;
    piVar2[0x115] = (int)__vt_12CItemBattery;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CMultiSource_PX01_PX01  @ 0013e87c
void GetClassPtr__H1Z12CMultiSource_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x5e0,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_12CMultiSource;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CNoBuildArea_PX01_PX01  @ 0013fab8
void GetClassPtr__H1Z12CNoBuildArea_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CNoBuildArea;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CPlatTrigger_PX01_PX01  @ 001424b4
void GetClassPtr__H1Z12CPlatTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPlatTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CPointEntity_PX01_PX01  @ 0013fa40
void GetClassPtr__H1Z12CPointEntity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CRevertSaved_PX01_PX01  @ 00142688
void GetClassPtr__H1Z12CRevertSaved_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_12CRevertSaved;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFAutoRifle_PX01_PX01  @ 00145f6c
void GetClassPtr__H1Z12CTFAutoRifle_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__12CTFAutoRifle(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFDispenser_PX01_PX01  @ 0013ef7c
void GetClassPtr__H1Z12CTFDispenser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6a8,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_12CTFDispenser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01  @ 00143fdc
void GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6bc,param_1);
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_12CTFRpgRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFSentrygun_PX01_PX01  @ 00142a88
void GetClassPtr__H1Z12CTFSentrygun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6d4,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_12CTFSentrygun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTFTimerGoal_PX01_PX01  @ 00144488
void GetClassPtr__H1Z12CTFTimerGoal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x474,param_1);
    __7CTFGoal(piVar2);
    piVar2[0x115] = (int)__vt_12CTFTimerGoal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerHurt_PX01_PX01  @ 0014546c
void GetClassPtr__H1Z12CTriggerHurt_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__12CTriggerHurt(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerOnce_PX01_PX01  @ 00144bc4
void GetClassPtr__H1Z12CTriggerOnce_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    __16CTriggerMultiple(piVar2);
    piVar2[0x115] = (int)__vt_12CTriggerOnce;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerPush_PX01_PX01  @ 0014522c
void GetClassPtr__H1Z12CTriggerPush_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__12CTriggerPush(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CTriggerSave_PX01_PX01  @ 0014516c
void GetClassPtr__H1Z12CTriggerSave_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__12CTriggerSave(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z12CXenSporeMed_PX01_PX01  @ 00145dcc
void GetClassPtr__H1Z12CXenSporeMed_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x478,param_1);
    piVar3 = (int *)__12CXenSporeMed(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CButtonTarget_PX01_PX01  @ 0013ea30
void GetClassPtr__H1Z13CButtonTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_13CButtonTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CCyclerSprite_PX01_PX01  @ 00140e64
void GetClassPtr__H1Z13CCyclerSprite_PX01_PX01(void)

{
  FUN_00140e6f();
  return;
}


// GetClassPtr__H1Z13CEnvExplosion_PX01_PX01  @ 0013fb30
void GetClassPtr__H1Z13CEnvExplosion_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6a4,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_13CEnvExplosion;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CFuncConveyor_PX01_PX01  @ 0013e4c4
void GetClassPtr__H1Z13CFuncConveyor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CFuncWall;
    piVar2[0x115] = (int)__vt_13CFuncConveyor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CFuncRotating_PX01_PX01  @ 0013e708
void GetClassPtr__H1Z13CFuncRotating_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_13CFuncRotating;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemAntidote_PX01_PX01  @ 00141240
void GetClassPtr__H1Z13CItemAntidote_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CItem;
    piVar2[0x115] = (int)__vt_13CItemAntidote;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemArmorRed_PX01_PX01  @ 0014373c
void GetClassPtr__H1Z13CItemArmorRed_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__13CItemArmorRed(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemLongJump_PX01_PX01  @ 00141348
void GetClassPtr__H1Z13CItemLongJump_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CItem;
    piVar2[0x115] = (int)__vt_13CItemLongJump;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CItemSecurity_PX01_PX01  @ 001412c4
void GetClassPtr__H1Z13CItemSecurity_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CItem;
    piVar2[0x115] = (int)__vt_13CItemSecurity;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CMultiManager_PX01_PX01  @ 00144950
void GetClassPtr__H1Z13CMultiManager_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x584,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x115] = (int)__vt_13CMultiManager;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CStripWeapons_PX01_PX01  @ 00142604
void GetClassPtr__H1Z13CStripWeapons_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_13CStripWeapons;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01  @ 00143b74
void GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__13CTFEMPGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01  @ 00143bd4
void GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6c4,param_1);
    piVar3 = (int *)__13CTFGasGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CTriggerRelay_PX01_PX01  @ 001448cc
void GetClassPtr__H1Z13CTriggerRelay_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_13CTriggerRelay;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z13CWeaponCycler_PX01_PX01  @ 00140e04
void GetClassPtr__H1Z13CWeaponCycler_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__13CWeaponCycler(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CCineScientist_PX01_PX01  @ 00140b90
void GetClassPtr__H1Z14CCineScientist_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__14CCineScientist(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CFuncTankLaser_PX01_PX01  @ 0013fdd4
void GetClassPtr__H1Z14CFuncTankLaser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4dc,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_9CFuncTank;
    piVar2[0x115] = (int)__vt_14CFuncTankLaser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CFuncTrackAuto_PX01_PX01  @ 00142214
void GetClassPtr__H1Z14CFuncTrackAuto_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x53c,param_1);
    __16CFuncTrackChange(piVar2);
    piVar2[0x115] = (int)__vt_14CFuncTrackAuto;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CGenericCycler_PX01_PX01  @ 00140f3c
void GetClassPtr__H1Z14CGenericCycler_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6a0,param_1);
    piVar3 = (int *)__14CGenericCycler(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01  @ 001435bc
void GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__14CItemAmmoCells(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01  @ 0014367c
void GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__14CItemAmmoNails(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CMomentaryDoor_PX01_PX01  @ 0013f124
void GetClassPtr__H1Z14CMomentaryDoor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_14CMomentaryDoor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CNoGrenadeArea_PX01_PX01  @ 00144680
void GetClassPtr__H1Z14CNoGrenadeArea_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_14CNoGrenadeArea;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFIncendiaryC_PX01_PX01  @ 0014641c
void GetClassPtr__H1Z14CTFIncendiaryC_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__14CTFIncendiaryC(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01  @ 00143c34
void GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__14CTFMirvGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01  @ 00143c94
void GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__14CTFNailGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01  @ 00143e74
void GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_14CTFNailgunNail;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTFSniperRifle_PX01_PX01  @ 0014682c
void GetClassPtr__H1Z14CTFSniperRifle_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4dc,param_1);
    piVar3 = (int *)__14CTFSniperRifle(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTargetCDAudio_PX01_PX01  @ 00144b00
void GetClassPtr__H1Z14CTargetCDAudio_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_14CTargetCDAudio;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTelefragDeath_PX01_PX01  @ 0013ffd8
void GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_14CTelefragDeath;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTriggerCamera_PX01_PX01  @ 00144fc8
void GetClassPtr__H1Z14CTriggerCamera_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x49c,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_14CTriggerCamera;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CTriggerVolume_PX01_PX01  @ 00144c7c
void GetClassPtr__H1Z14CTriggerVolume_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_14CTriggerVolume;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CXenSporeLarge_PX01_PX01  @ 00145d6c
void GetClassPtr__H1Z14CXenSporeLarge_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x478,param_1);
    piVar3 = (int *)__14CXenSporeLarge(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z14CXenSporeSmall_PX01_PX01  @ 00145e2c
void GetClassPtr__H1Z14CXenSporeSmall_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x478,param_1);
    piVar3 = (int *)__14CXenSporeSmall(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CAmbientGeneric_PX01_PX01  @ 00142c74
void GetClassPtr__H1Z15CAmbientGeneric_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_15CAmbientGeneric;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CCine2Scientist_PX01_PX01  @ 00140a70
void GetClassPtr__H1Z15CCine2Scientist_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__15CCine2Scientist(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CCine3Scientist_PX01_PX01  @ 00140950
void GetClassPtr__H1Z15CCine3Scientist_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__15CCine3Scientist(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTankMortar_PX01_PX01  @ 0013fedc
void GetClassPtr__H1Z15CFuncTankMortar_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4d4,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_9CFuncTank;
    piVar2[0x115] = (int)__vt_15CFuncTankMortar;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTankRocket_PX01_PX01  @ 0013fe58
void GetClassPtr__H1Z15CFuncTankRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4d4,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_9CFuncTank;
    piVar2[0x115] = (int)__vt_15CFuncTankRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncTrackTrain_PX01_PX01  @ 0014243c
void GetClassPtr__H1Z15CFuncTrackTrain_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4a0,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_15CFuncTrackTrain;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CFuncWallToggle_PX01_PX01  @ 0013e440
void GetClassPtr__H1Z15CFuncWallToggle_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CFuncWall;
    piVar2[0x115] = (int)__vt_15CFuncWallToggle;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CGenericMonster_PX01_PX01  @ 00140050
void GetClassPtr__H1Z15CGenericMonster_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_15CGenericMonster;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01  @ 001436dc
void GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__15CItemAmmoShells(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01  @ 001437fc
void GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__15CItemArmorGreen(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFFlamethrower_PX01_PX01  @ 00146264
void GetClassPtr__H1Z15CTFFlamethrower_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__15CTFFlamethrower(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFPrimeGrenade_PX01_PX01  @ 0014389c
void GetClassPtr__H1Z15CTFPrimeGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_15CTFPrimeGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFSuperNailgun_PX01_PX01  @ 001464bc
void GetClassPtr__H1Z15CTFSuperNailgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __10CTFNailgun(piVar2);
    piVar2[0x115] = (int)__vt_15CTFSuperNailgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTFSuperShotgun_PX01_PX01  @ 00146714
void GetClassPtr__H1Z15CTFSuperShotgun_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __10CTFShotgun(piVar2);
    piVar2[0x115] = (int)__vt_15CTFSuperShotgun;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerCDAudio_PX01_PX01  @ 001453ac
void GetClassPtr__H1Z15CTriggerCDAudio_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__15CTriggerCDAudio(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerCounter_PX01_PX01  @ 001452ec
void GetClassPtr__H1Z15CTriggerCounter_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__15CTriggerCounter(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CTriggerGravity_PX01_PX01  @ 001450ac
void GetClassPtr__H1Z15CTriggerGravity_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__15CTriggerGravity(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01  @ 00145c78
void GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_15CXenTreeTrigger;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncIllusionary_PX01_PX01  @ 0013e594
void GetClassPtr__H1Z16CFuncIllusionary_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x115] = (int)__vt_16CFuncIllusionary;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncMonsterClip_PX01_PX01  @ 0013e60c
void GetClassPtr__H1Z16CFuncMonsterClip_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CFuncWall;
    piVar2[0x115] = (int)__vt_16CFuncMonsterClip;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncMortarField_PX01_PX01  @ 00141d00
void GetClassPtr__H1Z16CFuncMortarField_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_16CFuncMortarField;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CFuncTrackChange_PX01_PX01  @ 00142364
void GetClassPtr__H1Z16CFuncTrackChange_PX01_PX01(void)

{
  FUN_0014236e();
  return;
}


// GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01  @ 0014361c
void GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__16CItemAmmoRockets(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01  @ 0014379c
void GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__16CItemArmorYellow(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01  @ 0014343c
void GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x45c,param_1);
    piVar3 = (int *)__16CItemPowerupQuad(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CRenderFxManager_PX01_PX01  @ 001454cc
void GetClassPtr__H1Z16CRenderFxManager_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_16CRenderFxManager;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01  @ 00143cf4
void GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6d0,param_1);
    piVar3 = (int *)__16CTFNapalmGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01  @ 00143d54
void GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__16CTFNormalGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTFSentrygunBase_PX01_PX01  @ 00142b00
void GetClassPtr__H1Z16CTFSentrygunBase_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_16CTFSentrygunBase;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTriggerMultiple_PX01_PX01  @ 0014534c
void GetClassPtr__H1Z16CTriggerMultiple_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__16CTriggerMultiple(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z16CTriggerTeleport_PX01_PX01  @ 001451cc
void GetClassPtr__H1Z16CTriggerTeleport_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__16CTriggerTeleport(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CFrictionModifier_PX01_PX01  @ 00145544
void GetClassPtr__H1Z17CFrictionModifier_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_17CFrictionModifier;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CFuncTankControls_PX01_PX01  @ 0013ff60
void GetClassPtr__H1Z17CFuncTankControls_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_17CFuncTankControls;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CInfoIntermission_PX01_PX01  @ 0014270c
void GetClassPtr__H1Z17CInfoIntermission_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_17CInfoIntermission;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CScriptedSentence_PX01_PX01  @ 00142938
void GetClassPtr__H1Z17CScriptedSentence_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __11CBaseToggle(piVar2);
    piVar2[0x115] = (int)__vt_17CScriptedSentence;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01  @ 00143db4
void GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__17CTFCaltropGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CCine2HeavyWeapons_PX01_PX01  @ 00140a10
void GetClassPtr__H1Z18CCine2HeavyWeapons_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x69c,param_1);
    piVar3 = (int *)__18CCine2HeavyWeapons(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CFuncTrainControls_PX01_PX01  @ 001423c4
void GetClassPtr__H1Z18CFuncTrainControls_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_18CFuncTrainControls;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CTFGrenadeLauncher_PX01_PX01  @ 0014637c
void GetClassPtr__H1Z18CTFGrenadeLauncher_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__18CTFGrenadeLauncher(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z18CTriggerEndSection_PX01_PX01  @ 0014510c
void GetClassPtr__H1Z18CTriggerEndSection_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__18CTriggerEndSection(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01  @ 001434fc
void GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x45c,param_1);
    piVar3 = (int *)__19CItemPowerupRadsuit(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CMomentaryRotButton_PX01_PX01  @ 0013e9b8
void GetClassPtr__H1Z19CMomentaryRotButton_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_19CMomentaryRotButton;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CTFPipebombLauncher_PX01_PX01  @ 00146304
void GetClassPtr__H1Z19CTFPipebombLauncher_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __18CTFGrenadeLauncher(piVar2);
    piVar2[0x115] = (int)__vt_19CTFPipebombLauncher;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z19CTriggerMonsterJump_PX01_PX01  @ 0014540c
void GetClassPtr__H1Z19CTriggerMonsterJump_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__19CTriggerMonsterJump(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01  @ 00143e14
void GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__20CTFConcussionGrenade(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFFlamethrowerBurst_PX01_PX01  @ 00143eec
void GetClassPtr__H1Z20CTFFlamethrowerBurst_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6bc,param_1);
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_20CTFFlamethrowerBurst;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01  @ 00143f64
void GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6bc,param_1);
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_20CTFIncendiaryCRocket;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z20CTriggerChangeTarget_PX01_PX01  @ 00144f44
void GetClassPtr__H1Z20CTriggerChangeTarget_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_20CTriggerChangeTarget;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01  @ 0014355c
void GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x45c,param_1);
    piVar3 = (int *)__22CItemPowerupInvincible(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01  @ 0013eff4
void GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x474,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_23CDispenserRefillThinker;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01  @ 0014349c
void GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x45c,param_1);
    piVar3 = (int *)__24CItemPowerupInvisibility(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z4CGib_PX01_PX01  @ 0013ecdc
void GetClassPtr__H1Z4CGib_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_4CGib;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CBeam_PX01_PX01  @ 0013f878
void GetClassPtr__H1Z5CBeam_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CBeam;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CFade_PX01_PX01  @ 0013f668
void GetClassPtr__H1Z5CFade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_5CFade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z5CGlow_PX01_PX01  @ 0013f304
void GetClassPtr__H1Z5CGlow_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_5CGlow;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CBlood_PX01_PX01  @ 0013f560
void GetClassPtr__H1Z6CBlood_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_6CBlood;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CDecal_PX01_PX01  @ 0014588c
void GetClassPtr__H1Z6CDecal_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_6CDecal;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CGhost_PX01_PX01  @ 00142e5c
void GetClassPtr__H1Z6CGhost_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_6CGhost;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CLaser_PX01_PX01  @ 0013f280
void GetClassPtr__H1Z6CLaser_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CBeam;
    piVar2[0x115] = (int)__vt_6CLaser;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CLight_PX01_PX01  @ 00141bd0
void GetClassPtr__H1Z6CLight_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_6CLight;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CShake_PX01_PX01  @ 0013f5e4
void GetClassPtr__H1Z6CShake_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_6CShake;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTFAxe_PX01_PX01  @ 00145fcc
void GetClassPtr__H1Z6CTFAxe_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x554,param_1);
    __8CCrowbar(piVar2);
    piVar2[0x115] = (int)__vt_6CTFAxe;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTFRpg_PX01_PX01  @ 00146674
void GetClassPtr__H1Z6CTFRpg_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__6CTFRpg(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CTimer_PX01_PX01  @ 00144354
void GetClassPtr__H1Z6CTimer_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_6CTimer;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z6CWorld_PX01_PX01  @ 0014579c
void GetClassPtr__H1Z6CWorld_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_6CWorld;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CCineAI_PX01_PX01  @ 00142a28
void GetClassPtr__H1Z7CCineAI_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x6d0,param_1);
    piVar3 = (int *)__7CCineAI(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CCorpse_PX01_PX01  @ 00145814
void GetClassPtr__H1Z7CCorpse_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_7CCorpse;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CLadder_PX01_PX01  @ 0014528c
void GetClassPtr__H1Z7CLadder_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x4f8,param_1);
    piVar3 = (int *)__7CLadder(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CMortar_PX01_PX01  @ 00141d78
void GetClassPtr__H1Z7CMortar_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6bc,param_1);
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_7CMortar;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CSentry_PX01_PX01  @ 0014567c
void GetClassPtr__H1Z7CSentry_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x70c,param_1);
    piVar3 = (int *)__7CSentry(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CShower_PX01_PX01  @ 0013fba8
void GetClassPtr__H1Z7CShower_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_7CShower;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CSprite_PX01_PX01  @ 0013f388
void GetClassPtr__H1Z7CSprite_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_7CSprite;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CTFGoal_PX01_PX01  @ 001446f8
void GetClassPtr__H1Z7CTFGoal_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__7CTFGoal(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z7CTurret_PX01_PX01  @ 0014573c
void GetClassPtr__H1Z7CTurret_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x710,param_1);
    piVar3 = (int *)__7CTurret(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CAirtank_PX01_PX01  @ 0013e28c
void GetClassPtr__H1Z8CAirtank_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6bc,param_1);
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_8CAirtank;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CAreaDef_PX01_PX01  @ 0013e304
int * GetClassPtr__H1Z8CAreaDef_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int local_8;
  
  local_8 = param_1;
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    local_8 = iVar1 + 0x80;
    if (iVar1 == 0) {
      local_8 = 0;
    }
  }
  piVar2 = (int *)0x0;
  if (*(int *)(local_8 + 0x208) != 0) {
    piVar2 = *(int **)(*(int *)(local_8 + 0x208) + 0x7c);
  }
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x50c,local_8);
    __11CBaseEntity(piVar2);
    piVar3 = piVar2 + 0x116;
    piVar2[0x115] = (int)__vt_8CAreaDef;
    iVar1 = 0xb;
    do {
      Clear__15DBAreaClassData(piVar3);
      piVar3 = piVar3 + 3;
      bVar4 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar4);
    g_nActiveAreas = g_nActiveAreas + 1;
    *(undefined1 *)(piVar2 + 0x13a) = 0;
    piVar2[0x142] = (int)g_pActiveAreas;
    g_pActiveAreas = piVar2;
    *piVar2 = local_8;
  }
  return piVar2;
}


// GetClassPtr__H1Z8CCrowbar_PX01_PX01  @ 0013ee5c
void GetClassPtr__H1Z8CCrowbar_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x50c,param_1);
    piVar3 = (int *)__8CCrowbar(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CDeadHEV_PX01_PX01  @ 0014258c
void GetClassPtr__H1Z8CDeadHEV_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6a0,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_8CDeadHEV;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CDetpack_PX01_PX01  @ 0013eebc
void GetClassPtr__H1Z8CDetpack_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __8CGrenade(piVar2);
    piVar2[0x115] = (int)__vt_8CDetpack;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CGrenade_PX01_PX01  @ 001400c8
void GetClassPtr__H1Z8CGrenade_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6b8,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_8CGrenade;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CMessage_PX01_PX01  @ 0013f6ec
void GetClassPtr__H1Z8CMessage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_8CMessage;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CNodeEnt_PX01_PX01  @ 00141f5c
void GetClassPtr__H1Z8CNodeEnt_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_8CNodeEnt;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CRotDoor_PX01_PX01  @ 0013f19c
void GetClassPtr__H1Z8CRotDoor_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x534,param_1);
    piVar3 = (int *)__8CRotDoor(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CSpeaker_PX01_PX01  @ 00142bfc
void GetClassPtr__H1Z8CSpeaker_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_8CSpeaker;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFFlame_PX01_PX01  @ 00142808
void GetClassPtr__H1Z8CTFFlame_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6a0,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_8CTFFlame;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFKnife_PX01_PX01  @ 001461c4
void GetClassPtr__H1Z8CTFKnife_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x558,param_1);
    piVar3 = (int *)__8CTFKnife(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFSpawn_PX01_PX01  @ 001447d0
void GetClassPtr__H1Z8CTFSpawn_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_8CTFSpawn;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTFTranq_PX01_PX01  @ 001468cc
void GetClassPtr__H1Z8CTFTranq_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar3 = (int *)__8CTFTranq(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CTeamSet_PX01_PX01  @ 001445fc
void GetClassPtr__H1Z8CTeamSet_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_10CBaseDelay;
    piVar2[0x115] = (int)__vt_8CTeamSet;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenHair_PX01_PX01  @ 00145a44
void GetClassPtr__H1Z8CXenHair_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __13CActAnimating(piVar2);
    piVar2[0x115] = (int)__vt_8CXenHair;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenHull_PX01_PX01  @ 00145b34
void GetClassPtr__H1Z8CXenHull_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_8CXenHull;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z8CXenTree_PX01_PX01  @ 00145abc
void GetClassPtr__H1Z8CXenTree_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    __13CActAnimating(piVar2);
    piVar2[0x115] = (int)__vt_8CXenTree;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CBaseDoor_PX01_PX01  @ 0013f06c
void GetClassPtr__H1Z9CBaseDoor_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x534,param_1);
    __11CBaseToggle(piVar2);
    piVar2[0x115] = (int)__vt_9CBaseDoor;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CBubbling_PX01_PX01  @ 0013f9c8
void GetClassPtr__H1Z9CBubbling_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CBubbling;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvLight_PX01_PX01  @ 00141ca0
void GetClassPtr__H1Z9CEnvLight_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    piVar3 = (int *)__9CEnvLight(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvSound_PX01_PX01  @ 00142b78
void GetClassPtr__H1Z9CEnvSound_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x460,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_12CPointEntity;
    piVar2[0x115] = (int)__vt_9CEnvSound;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CEnvSpark_PX01_PX01  @ 0013eaa8
void GetClassPtr__H1Z9CEnvSpark_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CEnvSpark;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CFuncPlat_PX01_PX01  @ 0014252c
void GetClassPtr__H1Z9CFuncPlat_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x500,param_1);
    piVar3 = (int *)__9CFuncPlat(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CFuncWall_PX01_PX01  @ 0013e780
void GetClassPtr__H1Z9CFuncWall_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CFuncWall;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CItemSoda_PX01_PX01  @ 0013f8f0
void GetClassPtr__H1Z9CItemSoda_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CItemSoda;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CItemSuit_PX01_PX01  @ 00141138
void GetClassPtr__H1Z9CItemSuit_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_5CItem;
    piVar2[0x115] = (int)__vt_9CItemSuit;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CPendulum_PX01_PX01  @ 0013e690
void GetClassPtr__H1Z9CPendulum_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x488,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_9CPendulum;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CPushable_PX01_PX01  @ 0013fcf0
void GetClassPtr__H1Z9CPushable_PX01_PX01(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    uVar2 = __nw__11CBaseEntityUiP9entvars_s(0x484,param_1);
    piVar3 = (int *)__9CPushable(uVar2);
    *piVar3 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CRecharge_PX01_PX01  @ 00140140
void GetClassPtr__H1Z9CRecharge_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CRecharge;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CSoundEnt_PX01_PX01  @ 00142cec
void GetClassPtr__H1Z9CSoundEnt_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0xc68,param_1);
    __11CBaseEntity(piVar2);
    piVar2[0x115] = (int)__vt_9CSoundEnt;
    iVar1 = 0x3f;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CSprayCan_PX01_PX01  @ 00142790
void GetClassPtr__H1Z9CSprayCan_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CSprayCan;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CTFDetect_PX01_PX01  @ 00144758
void GetClassPtr__H1Z9CTFDetect_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
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
    piVar2[0x115] = (int)__vt_9CTFDetect;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CTestHull_PX01_PX01  @ 00141df0
void GetClassPtr__H1Z9CTestHull_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6a8,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_9CTestHull;
    *piVar2 = param_1;
  }
  return;
}


// GetClassPtr__H1Z9CWreckage_PX01_PX01  @ 00140cb0
void GetClassPtr__H1Z9CWreckage_PX01_PX01(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    iVar1 = (*DAT_0019f6f4)();
    param_1 = iVar1 + 0x80;
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x208) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x208) + 0x7c);
  }
  if (iVar1 == 0) {
    piVar2 = (int *)__nw__11CBaseEntityUiP9entvars_s(0x6a0,param_1);
    __12CBaseMonster(piVar2);
    piVar2[0x115] = (int)__vt_9CWreckage;
    *piVar2 = param_1;
  }
  return;
}


