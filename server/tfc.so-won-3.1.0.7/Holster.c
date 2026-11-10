// Holster__10CTFMedikiti  @ 00127d40
void Holster__10CTFMedikiti(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,4,1);
  return;
}


// Holster__10CTFSpanneri  @ 001276b4
void Holster__10CTFSpanneri(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,5,1);
  return;
}


// Holster__11CTFAssaultCi  @ 00125e70
void Holster__11CTFAssaultCi(int param_1)

{
  WindDown__11CTFAssaultCb(param_1,0x120001);
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3dcccccd;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,6,1);
  return;
}


// Holster__12CHandGrenade  @ 000b5874
void Holster__12CHandGrenade(int *param_1)

{
  *(undefined4 *)(param_1[0x119] + 0x648) = 0x3f000000;
  if (*(int *)(param_1[0x12a] * 4 + param_1[0x119] + 0x8c4) == 0) {
    *(byte *)(*(int *)param_1[0x119] + 0x169) = *(byte *)(*(int *)param_1[0x119] + 0x169) & 0xef;
    param_1[3] = -0x10000;
    param_1[4] = (int)DestroyItem__15CBasePlayerItem;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  else {
    (**(code **)(param_1[0x111] + 0x168))(param_1,6,0);
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*(int *)param_1[0x119] + 0x208),1,"common/null.wav",0x3f800000,
             0x3f4ccccd,0,100);
  return;
}


// Holster__12CTFAutoRiflei  @ 0012675c
void Holster__12CTFAutoRiflei(int param_1)

{
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,8,1);
  return;
}


// Holster__13CWeaponCycler  @ 000b4e94
void Holster__13CWeaponCycler(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  return;
}


// Holster__14CTFIncendiaryCi  @ 0012a7d8
void Holster__14CTFIncendiaryCi(int param_1)

{
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,4,1);
  return;
}


// Holster__14CTFSniperRiflei  @ 0012d40c
void Holster__14CTFSniperRiflei(int param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  if (*(int *)(param_1 + 0x498) != 0) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x174))(param_1);
  }
  pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x85);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x464));
  if (*(int *)(param_1 + 0x4c0) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x4c0) + 0x444) + 0x40))
              (*(int *)(param_1 + 0x4c0),0,0,1);
    *(undefined4 *)(param_1 + 0x4c0) = 0;
  }
  *(undefined4 *)(param_1 + 0x490) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,4,1);
  return;
}


// Holster__15CBasePlayerItemi  @ 00120258
void Holster__15CBasePlayerItemi(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 0x464) + 0xbc) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x464) + 0xc0) = 0;
  return;
}


// Holster__15CTFFlamethroweri  @ 0012946c
void Holster__15CTFFlamethroweri(int param_1)

{
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,10,1);
  return;
}


// Holster__17CBasePlayerWeaponi  @ 00120b30
void Holster__17CBasePlayerWeaponi(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x464) + 0xbc) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x464) + 0xc0) = 0;
  return;
}


// Holster__18CTFGrenadeLauncheri  @ 00129bc0
void Holster__18CTFGrenadeLauncheri(int param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x878) = *(undefined4 *)(param_1 + 0x4b0);
  pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x4a4) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0x447a0000;
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4c4),1);
  return;
}


// Holster__6CTFAxei  @ 00126e60
void Holster__6CTFAxei(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,2,1);
  return;
}


// Holster__6CTFRpgi  @ 0012beb8
void Holster__6CTFRpgi(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x4a4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,3,1);
  return;
}


// Holster__8CCrowbari  @ 00097e78
void Holster__8CCrowbari(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,2,0);
  return;
}


// Holster__8CTFKnifei  @ 00127a54
void Holster__8CTFKnifei(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,5,1);
  return;
}


