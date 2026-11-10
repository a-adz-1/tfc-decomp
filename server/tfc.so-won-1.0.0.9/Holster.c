// Holster__10CTFMedikit  @ 000f9950
void Holster__10CTFMedikit(int param_1)

{
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,4);
  return;
}


// Holster__10CTFSpanner  @ 000f9420
void Holster__10CTFSpanner(int param_1)

{
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,5);
  return;
}


// Holster__11CTFAssaultC  @ 000f7780
void Holster__11CTFAssaultC(int param_1)

{
  WindDown__11CTFAssaultC(param_1);
  *(undefined4 *)(param_1 + 0x41c) = 0;
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.1;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,6);
  return;
}


// Holster__12CHandGrenade  @ 000bc690
void Holster__12CHandGrenade(int *param_1)

{
  *(float *)(param_1[0xfa] + 0x5cc) = *gpGlobals + 0.5;
  if (*(int *)(param_1[0x102] * 4 + param_1[0xfa] + 0x83c) == 0) {
    *(byte *)(*(int *)param_1[0xfa] + 0x149) = *(byte *)(*(int *)param_1[0xfa] + 0x149) & 0xef;
    param_1[3] = -0x10000;
    param_1[4] = (int)DestroyItem__15CBasePlayerItem;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  else {
    (**(code **)(param_1[0xf2] + 0x15c))(param_1,6);
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),1,"common/null.wav",0x3f800000,
             0x3f4ccccd,0,100);
  return;
}


// Holster__12CTFAutoRifle  @ 000f8310
void Holster__12CTFAutoRifle(int param_1)

{
  *(undefined4 *)(param_1 + 0x41c) = 0;
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,8);
  return;
}


// Holster__13CWeaponCycler  @ 000bbee0
void Holster__13CWeaponCycler(int param_1)

{
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  return;
}


// Holster__14CTFIncendiaryC  @ 000ff870
void Holster__14CTFIncendiaryC(int param_1)

{
  *(undefined4 *)(param_1 + 0x41c) = 0;
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,4);
  return;
}


// Holster__14CTFSniperRifle  @ 001033e0
void Holster__14CTFSniperRifle(int param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(param_1 + 0x41c) = 0;
  if (*(int *)(param_1 + 0x42c) != 0) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x168))(param_1);
  }
  pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x89);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 1000));
  if (*(int *)(param_1 + 0x430) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x430) + 0x3c8) + 0x3c))(*(int *)(param_1 + 0x430),0,1)
    ;
    *(undefined4 *)(param_1 + 0x430) = 0;
  }
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,4);
  return;
}


// Holster__15CBasePlayerItem  @ 0011b440
void Holster__15CBasePlayerItem(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 1000) + 0x9c) = 0;
  *(undefined4 *)(**(int **)(param_1 + 1000) + 0xa0) = 0;
  return;
}


// Holster__15CTFFlamethrower  @ 000fa9d0
void Holster__15CTFFlamethrower(int param_1)

{
  *(undefined4 *)(param_1 + 0x41c) = 0;
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,10);
  return;
}


// Holster__17CBasePlayerWeapon  @ 0011bc80
void Holster__17CBasePlayerWeapon(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x41c) = 0;
  *(undefined4 *)(**(int **)(param_1 + 1000) + 0x9c) = 0;
  *(undefined4 *)(**(int **)(param_1 + 1000) + 0xa0) = 0;
  return;
}


// Holster__18CTFGrenadeLauncher  @ 000fba00
void Holster__18CTFGrenadeLauncher(int param_1)

{
  byte *pbVar1;
  float *pfVar2;
  
  *(undefined4 *)(*(int *)(param_1 + 1000) + 0x7f4) = *(undefined4 *)(param_1 + 0x410);
  pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x424) = 0;
  pfVar2 = gpGlobals;
  *(float *)(param_1 + 0x404) = *gpGlobals + 9999.0;
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *pfVar2 + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,*(undefined4 *)(param_1 + 0x434));
  return;
}


// Holster__6CTFAxe  @ 000f8910
void Holster__6CTFAxe(int param_1)

{
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
  return;
}


// Holster__6CTFRpg  @ 001019f0
void Holster__6CTFRpg(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined4 *)(param_1 + 0x424) = 0;
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,3);
  return;
}


// Holster__8CCrowbar  @ 000a6610
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Holster__8CCrowbar(int param_1)

{
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = (float)_FUN_0012d480 + *gpGlobals;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
  return;
}


// Holster__8CTFKnife  @ 000f9730
void Holster__8CTFKnife(int param_1)

{
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,5);
  return;
}


