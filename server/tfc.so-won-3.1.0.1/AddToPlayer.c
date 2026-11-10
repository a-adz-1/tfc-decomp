// AddToPlayer__10CTFNailgunP11CBasePlayer  @ 0011a970
bool AddToPlayer__10CTFNailgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x3f4) + 0xd4;
  }
  return iVar1 != 0;
}


// AddToPlayer__10CTFShotgunP11CBasePlayer  @ 0011bfe4
bool AddToPlayer__10CTFShotgunP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x3f4) + 0xcc;
  }
  return iVar1 != 0;
}


// AddToPlayer__11CTFAssaultCP11CBasePlayer  @ 001160c4
bool AddToPlayer__11CTFAssaultCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
  }
  return iVar1 != 0;
}


// AddToPlayer__12CTFAutoRifleP11CBasePlayer  @ 00116824
bool AddToPlayer__12CTFAutoRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFIncendiaryCP11CBasePlayer  @ 0011a2e0
bool AddToPlayer__14CTFIncendiaryCP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x3f4) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__14CTFSniperRifleP11CBasePlayer  @ 0011cc5c
bool AddToPlayer__14CTFSniperRifleP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
  }
  return iVar1 != 0;
}


// AddToPlayer__15CBasePlayerItemP11CBasePlayer  @ 0011063c
undefined4 AddToPlayer__15CBasePlayerItemP11CBasePlayer(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x3f4) = param_2;
  return 1;
}


// AddToPlayer__15CTFFlamethrowerP11CBasePlayer  @ 0011903c
bool AddToPlayer__15CTFFlamethrowerP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x3f4) + 0xdc;
  }
  return iVar1 != 0;
}


// AddToPlayer__17CBasePlayerWeaponP11CBasePlayer  @ 00110824
undefined4 AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_2c [8];
  undefined4 local_24;
  undefined4 local_1c;
  
  iVar1 = AddToPlayer__15CBasePlayerItemP11CBasePlayer(param_1,param_2);
  *(uint *)(*param_2 + 0x168) =
       *(uint *)(*param_2 + 0x168) | 1 << ((byte)*(undefined4 *)(param_1 + 0x3fc) & 0x1f);
  if (*(int *)(param_1 + 0x438) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x110))(param_1,local_2c);
    uVar2 = GetAmmoIndex__11CBasePlayerPCc(local_24);
    *(undefined4 *)(param_1 + 0x438) = uVar2;
    uVar2 = GetAmmoIndex__11CBasePlayerPCc(local_1c);
    *(undefined4 *)(param_1 + 0x43c) = uVar2;
  }
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x154))(param_1);
  }
  return uVar2;
}


// AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer  @ 00119748
bool AddToPlayer__18CTFGrenadeLauncherP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x3f4) + 0xe4;
  }
  return iVar1 != 0;
}


// AddToPlayer__6CTFRpgP11CBasePlayer  @ 0011b8f0
bool AddToPlayer__6CTFRpgP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = AddToPlayer__17CBasePlayerWeaponP11CBasePlayer(param_1,param_2);
  if (iVar1 != 0) {
    (*DAT_001a7ef8)(1,gmsgWeapPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7efc)();
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x3f4) + 0xe4;
  }
  return iVar1 != 0;
}


