// AddToPlayer__10CTFNailgunP11CBasePlayer  @ 00100560
bool AddToPlayer__10CTFNailgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 1000) + 0xd4;
  }
  return iVar1 != 0;
}


// AddToPlayer__10CTFShotgunP11CBasePlayer  @ 00101fd0
bool AddToPlayer__10CTFShotgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 1000) + 0xcc;
  }
  return iVar1 != 0;
}


// AddToPlayer__11CTFAssaultCP11CBasePlayer  @ 000f7710
bool AddToPlayer__11CTFAssaultCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
  }
  return iVar1 != 0;
}


// AddToPlayer__12CTFAutoRifleP11CBasePlayer  @ 000f81a0
bool AddToPlayer__12CTFAutoRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFIncendiaryCP11CBasePlayer  @ 000ff790
bool AddToPlayer__14CTFIncendiaryCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 1000) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFSniperRifleP11CBasePlayer  @ 00103220
bool AddToPlayer__14CTFSniperRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
  }
  return iVar1 != 0;
}


// AddToPlayer__15CBasePlayerItemP11CBasePlayer  @ 0011b380
undefined4 AddToPlayer__15CBasePlayerItemP11CBasePlayer(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 1000) = param_2;
  return 1;
}


// AddToPlayer__15CTFFlamethrowerP11CBasePlayer  @ 000fa910
bool AddToPlayer__15CTFFlamethrowerP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 1000) + 0xdc;
  }
  return iVar1 != 0;
}


// AddToPlayer__17CBasePlayerWeaponP11CBasePlayer  @ 0011b560
undefined4 AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [8];
  undefined4 uStack_28;
  undefined4 uStack_20;
  
  iVar1 = AddToPlayer__15CBasePlayerItemP11CBasePlayer(param_1,param_2);
  *(uint *)(*param_2 + 0x148) =
       *(uint *)(*param_2 + 0x148) | 1 << ((byte)*(undefined4 *)(param_1 + 0x3f0) & 0x1f);
  if (*(int *)(param_1 + 0x408) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,auStack_30);
    uVar2 = GetAmmoIndex__11CBasePlayerPCc(uStack_28);
    *(undefined4 *)(param_1 + 0x408) = uVar2;
    uVar2 = GetAmmoIndex__11CBasePlayerPCc(uStack_20);
    *(undefined4 *)(param_1 + 0x40c) = uVar2;
  }
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x150))(param_1);
  }
  return uVar2;
}


// AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer  @ 000fb940
bool AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 1000) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__6CTFRpgP11CBasePlayer  @ 00101920
bool AddToPlayer__6CTFRpgP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_00175578)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_0017557c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 1000) + 0xe4;
  }
  return iVar1 != 0;
}


