// AddToPlayer__10CTFNailgunP11CBasePlayer  @ 0012f5e4
bool AddToPlayer__10CTFNailgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x474) + 0xd4;
  }
  return iVar1 != 0;
}


// AddToPlayer__10CTFShotgunP11CBasePlayer  @ 001312d4
bool AddToPlayer__10CTFShotgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x474) + 0xcc;
  }
  return iVar1 != 0;
}


// AddToPlayer__11CTFAssaultCP11CBasePlayer  @ 0012a6e8
bool AddToPlayer__11CTFAssaultCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
  }
  return iVar1 != 0;
}


// AddToPlayer__12CTFAutoRifleP11CBasePlayer  @ 0012adc8
bool AddToPlayer__12CTFAutoRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFIncendiaryCP11CBasePlayer  @ 0012eb90
bool AddToPlayer__14CTFIncendiaryCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x474) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFSniperRifleP11CBasePlayer  @ 00132200
bool AddToPlayer__14CTFSniperRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
  }
  return iVar1 != 0;
}


// AddToPlayer__15CBasePlayerItemP11CBasePlayer  @ 00125cfc
undefined4 AddToPlayer__15CBasePlayerItemP11CBasePlayer(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x474) = param_2;
  return 1;
}


// AddToPlayer__15CTFFlamethrowerP11CBasePlayer  @ 0012d834
bool AddToPlayer__15CTFFlamethrowerP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x474) + 0xdc;
  }
  return iVar1 != 0;
}


// AddToPlayer__17CBasePlayerWeaponP11CBasePlayer  @ 00125a8c
void AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_20;
  
  *(int **)(param_1 + 0x474) = param_2;
  *(uint *)(*param_2 + 0x168) =
       *(uint *)(*param_2 + 0x168) | 1 << ((byte)*(undefined4 *)(param_1 + 0x47c) & 0x1f);
  if (*(int *)(param_1 + 0x4b8) == 0) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_30);
    uVar1 = GetAmmoIndex__11CBasePlayerPCc(local_28);
    *(undefined4 *)(param_1 + 0x4b8) = uVar1;
    uVar1 = GetAmmoIndex__11CBasePlayerPCc(local_20);
    *(undefined4 *)(param_1 + 0x4bc) = uVar1;
  }
  (**(code **)(*(int *)(param_1 + 0x454) + 0x15c))(param_1);
  return;
}


// AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer  @ 0012e534
bool AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x474) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__6CTFRpgP11CBasePlayer  @ 001302f8
bool AddToPlayer__6CTFRpgP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_0019f758)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f75c)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x474) + 0xe4;
  }
  return iVar1 != 0;
}


