// AddToPlayer__10CTFNailgunP11CBasePlayer  @ 0012adb4
bool AddToPlayer__10CTFNailgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x464) + 0xd4;
  }
  return iVar1 != 0;
}


// AddToPlayer__10CTFShotgunP11CBasePlayer  @ 0012c500
bool AddToPlayer__10CTFShotgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x464) + 0xcc;
  }
  return iVar1 != 0;
}


// AddToPlayer__11CTFAssaultCP11CBasePlayer  @ 00125dec
bool AddToPlayer__11CTFAssaultCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
  }
  return iVar1 != 0;
}


// AddToPlayer__12CTFAutoRifleP11CBasePlayer  @ 00126584
bool AddToPlayer__12CTFAutoRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFIncendiaryCP11CBasePlayer  @ 0012a6dc
bool AddToPlayer__14CTFIncendiaryCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x464) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFSniperRifleP11CBasePlayer  @ 0012d1e0
bool AddToPlayer__14CTFSniperRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
  }
  return iVar1 != 0;
}


// AddToPlayer__15CBasePlayerItemP11CBasePlayer  @ 0012018c
undefined4 AddToPlayer__15CBasePlayerItemP11CBasePlayer(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x464) = param_2;
  return 1;
}


// AddToPlayer__15CTFFlamethrowerP11CBasePlayer  @ 00129398
bool AddToPlayer__15CTFFlamethrowerP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x464) + 0xdc;
  }
  return iVar1 != 0;
}


// AddToPlayer__17CBasePlayerWeaponP11CBasePlayer  @ 00120374
undefined4 AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_2c [8];
  undefined4 local_24;
  undefined4 local_1c;
  
  iVar1 = AddToPlayer__15CBasePlayerItemP11CBasePlayer(param_1,param_2);
  *(uint *)(*param_2 + 0x168) =
       *(uint *)(*param_2 + 0x168) | 1 << ((byte)*(undefined4 *)(param_1 + 0x46c) & 0x1f);
  if (*(int *)(param_1 + 0x4a8) == 0) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x118))(param_1,local_2c);
    uVar2 = GetAmmoIndex__11CBasePlayerPCc(local_24);
    *(undefined4 *)(param_1 + 0x4a8) = uVar2;
    uVar2 = GetAmmoIndex__11CBasePlayerPCc(local_1c);
    *(undefined4 *)(param_1 + 0x4ac) = uVar2;
  }
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_1 + 0x444) + 0x15c))(param_1);
  }
  return uVar2;
}


// AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer  @ 00129ae0
bool AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x464) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__6CTFRpgP11CBasePlayer  @ 0012bdd0
bool AddToPlayer__6CTFRpgP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001c10d8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x464) + 0xe4;
  }
  return iVar1 != 0;
}


