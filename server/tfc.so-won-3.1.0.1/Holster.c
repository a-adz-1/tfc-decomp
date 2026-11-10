// Holster__10CTFMedikiti  @ 00117f58
void Holster__10CTFMedikiti(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,4,1);
  return;
}


// Holster__10CTFSpanneri  @ 001178f0
void Holster__10CTFSpanneri(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,5,1);
  return;
}


// Holster__11CTFAssaultCi  @ 00116148
void Holster__11CTFAssaultCi(int param_1)

{
  WindDown__11CTFAssaultC(param_1);
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3dcccccd;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,6,1);
  return;
}


// Holster__12CHandGrenade  @ 000aa7f4
void Holster__12CHandGrenade(int *param_1)

{
  *(undefined4 *)(param_1[0xfd] + 0x5d8) = 0x3f000000;
  if (*(int *)(param_1[0x10e] * 4 + param_1[0xfd] + 0x850) == 0) {
    *(byte *)(*(int *)param_1[0xfd] + 0x169) = *(byte *)(*(int *)param_1[0xfd] + 0x169) & 0xef;
    param_1[3] = -0x10000;
    param_1[4] = (int)DestroyItem__15CBasePlayerItem;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  else {
    (**(code **)(param_1[0xf5] + 0x160))(param_1,6,0);
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),1,"common/null.wav",0x3f800000,
             0x3f4ccccd,0,100);
  return;
}


// Holster__12CTFAutoRiflei  @ 001169ec
void Holster__12CTFAutoRiflei(int param_1)

{
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,8,1);
  return;
}


// Holster__13CWeaponCycler  @ 000a9ec4
void Holster__13CWeaponCycler(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  return;
}


// Holster__14CTFIncendiaryCi  @ 0011a3dc
void Holster__14CTFIncendiaryCi(int param_1)

{
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,4,1);
  return;
}


// Holster__14CTFSniperRiflei  @ 0011ce74
void Holster__14CTFSniperRiflei(int param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(param_1 + 0x430) = 0;
  if (*(int *)(param_1 + 0x428) != 0) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x16c))(param_1);
  }
  pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x85);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x3f4));
  if (*(int *)(param_1 + 0x450) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x450) + 0x3d4) + 0x3c))(*(int *)(param_1 + 0x450),0,1)
    ;
    *(undefined4 *)(param_1 + 0x450) = 0;
  }
  *(undefined4 *)(param_1 + 0x420) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,4,1);
  return;
}


// Holster__15CBasePlayerItemi  @ 00110708
void Holster__15CBasePlayerItemi(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0xbc) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0xc0) = 0;
  return;
}


// Holster__15CTFFlamethroweri  @ 00119110
void Holster__15CTFFlamethroweri(int param_1)

{
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,10,1);
  return;
}


// Holster__17CBasePlayerWeaponi  @ 00110fe0
void Holster__17CBasePlayerWeaponi(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0xbc) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0xc0) = 0;
  return;
}


// Holster__18CTFGrenadeLauncheri  @ 00119828
void Holster__18CTFGrenadeLauncheri(int param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x808) = *(undefined4 *)(param_1 + 0x440);
  pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x434) = 0;
  *(undefined4 *)(param_1 + 0x410) = 0x447a0000;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,*(undefined4 *)(param_1 + 0x454),1);
  return;
}


// Holster__6CTFAxei  @ 001170b4
void Holster__6CTFAxei(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,2,1);
  return;
}


// Holster__6CTFRpgi  @ 0011b9d8
void Holster__6CTFRpgi(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x434) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,3,1);
  return;
}


// Holster__8CCrowbari  @ 0008f340
void Holster__8CCrowbari(void)

{
  FUN_0008f346();
  return;
}


// Holster__8CTFKnifei  @ 00117c7c
void Holster__8CTFKnifei(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,5,1);
  return;
}


