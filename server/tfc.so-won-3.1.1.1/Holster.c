// Holster__10CTFMedikiti  @ 0012c974
void Holster__10CTFMedikiti(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,4,1);
  return;
}


// Holster__10CTFSpanneri  @ 0012cf3c
void Holster__10CTFSpanneri(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,5,1);
  return;
}


// Holster__11CTFAssaultCi  @ 0012a690
void Holster__11CTFAssaultCi(int param_1)

{
  WindDown__11CTFAssaultCb(param_1,0x120001);
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3dcccccd;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,6,1);
  return;
}


// Holster__12CHandGrenade  @ 000b4f24
void Holster__12CHandGrenade(int *param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(param_1[0x11d] + 0x658) = 0x3f000000;
  if (((int *)param_1[0x11d])[param_1[0x12e] + 0x23b] == 0) {
    pbVar1 = (byte *)(*(int *)param_1[0x11d] + 0x169);
    *pbVar1 = *pbVar1 & 0xef;
    param_1[3] = -0x10000;
    param_1[4] = (int)DestroyItem__15CBasePlayerItem;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  else {
    (**(code **)(param_1[0x115] + 0x168))(param_1,6,0);
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),1,"common/null.wav",0x3f800000,
             0x3f4ccccd,0,100);
  return;
}


// Holster__12CTFAutoRiflei  @ 0012ac20
void Holster__12CTFAutoRiflei(int param_1)

{
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,8,1);
  return;
}


// Holster__13CWeaponCycler  @ 000b3f9c
void Holster__13CWeaponCycler(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  return;
}


// Holster__14CTFIncendiaryCi  @ 0012ead8
void Holster__14CTFIncendiaryCi(int param_1)

{
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,4,1);
  return;
}


// Holster__14CTFSniperRiflei  @ 00131f94
void Holster__14CTFSniperRiflei(int param_1)

{
  byte *pbVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  if (*(int *)(param_1 + 0x4a8) != 0) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x174))(param_1);
  }
  pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x85);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x474));
  iVar2 = *(int *)(param_1 + 0x4d0);
  if (iVar2 != 0) {
    (**(code **)(*(int *)(iVar2 + 0x454) + 0x40))(iVar2,0,0,1);
    *(undefined4 *)(param_1 + 0x4d0) = 0;
  }
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,4,1);
  return;
}


// Holster__15CBasePlayerItemi  @ 00125c0c
void Holster__15CBasePlayerItemi(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 0x474) + 0xbc) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x474) + 0xc0) = 0;
  return;
}


// Holster__15CTFFlamethroweri  @ 0012d7a4
void Holster__15CTFFlamethroweri(int param_1)

{
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,10,1);
  return;
}


// Holster__17CBasePlayerWeaponi  @ 00125470
void Holster__17CBasePlayerWeaponi(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x474) + 0xbc) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x474) + 0xc0) = 0;
  return;
}


// Holster__18CTFGrenadeLauncheri  @ 0012e46c
void Holster__18CTFGrenadeLauncheri(int param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x8a0) = *(undefined4 *)(param_1 + 0x4c0);
  pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x490) = 0x447a0000;
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4d4),1);
  return;
}


// Holster__6CTFAxei  @ 0012d0f0
void Holster__6CTFAxei(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,2,1);
  return;
}


// Holster__6CTFRpgi  @ 00130244
void Holster__6CTFRpgi(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,3,1);
  return;
}


// Holster__8CCrowbari  @ 000981c4
void Holster__8CCrowbari(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,2,0);
  return;
}


// Holster__8CTFKnifei  @ 0012cb94
void Holster__8CTFKnifei(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,5,1);
  return;
}


