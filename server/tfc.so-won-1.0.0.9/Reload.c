// Reload__10CTFNailgun  @ 001003c0
void Reload__10CTFNailgun(void)

{
  return;
}


// Reload__10CTFRailgun  @ 00101040
void Reload__10CTFRailgun(void)

{
  return;
}


// Reload__10CTFShotgun  @ 001025a0
void Reload__10CTFShotgun(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  char *pcVar5;
  
  if ((*(int *)(param_1 + 0x434) <= *(int *)(*(int *)(param_1 + 1000) + 0xcc)) &&
     (*(int *)(param_1 + 0x410) != *(int *)(param_1 + 0x438))) {
    if (*(float *)(param_1 + 0x428) <= *gpGlobals) {
      if (*(float *)(param_1 + 0x3fc) <= *gpGlobals) {
        if (*(int *)(param_1 + 0x424) == 0) {
          (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,5);
          pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
          *pbVar1 = *pbVar1 | 2;
          *(undefined4 *)(param_1 + 0x424) = 1;
          pfVar3 = gpGlobals;
          *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.1;
          *(float *)(param_1 + 0x404) = *pfVar3 + 0.1;
          *(float *)(param_1 + 0x3fc) = *pfVar3 + 0.1;
          *(float *)(param_1 + 0x400) = *pfVar3 + 0.1;
        }
        else if (*(int *)(param_1 + 0x424) == 1) {
          if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
            *(undefined4 *)(param_1 + 0x424) = 2;
            iVar4 = (*DAT_00175628)(0,1);
            if (iVar4 == 0) {
              iVar4 = (*DAT_00175628)(0,0x1f);
              pcVar5 = "weapons/reload3.wav";
            }
            else {
              iVar4 = (*DAT_00175628)(0,0x1f);
              pcVar5 = "weapons/reload1.wav";
            }
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),3,pcVar5,0x3f800000,
                       0x3f4ccccd,0,iVar4 + 0x55);
            (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,3);
            pfVar3 = gpGlobals;
            *(float *)(param_1 + 0x428) = *gpGlobals + *(float *)(param_1 + 0x43c);
            *(float *)(param_1 + 0x404) = *pfVar3 + *(float *)(param_1 + 0x43c);
          }
        }
        else {
          *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + *(int *)(param_1 + 0x434);
          piVar2 = (int *)(*(int *)(param_1 + 1000) + 0xcc);
          *piVar2 = *piVar2 - *(int *)(param_1 + 0x434);
          *(undefined4 *)(param_1 + 0x424) = 1;
          pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
          *pbVar1 = *pbVar1 & 0xfd;
        }
      }
    }
  }
  return;
}


// Reload__11CTFAssaultC  @ 000f8010
void Reload__11CTFAssaultC(void)

{
  return;
}


// Reload__12CTFAutoRifle  @ 000f8660
void Reload__12CTFAutoRifle(void)

{
  return;
}


// Reload__14CTFIncendiaryC  @ 000ff610
void Reload__14CTFIncendiaryC(void)

{
  return;
}


// Reload__14CTFSniperRifle  @ 00103d10
void Reload__14CTFSniperRifle(void)

{
  return;
}


// Reload__15CTFFlamethrower  @ 000fa790
void Reload__15CTFFlamethrower(void)

{
  return;
}


// Reload__17CBasePlayerWeapon  @ 0011cb50
void Reload__17CBasePlayerWeapon(void)

{
  return;
}


// Reload__18CTFGrenadeLauncher  @ 000fbcf0
void Reload__18CTFGrenadeLauncher(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float *pfVar3;
  
  pfVar3 = gpGlobals;
  if (*(int *)(param_1 + 0x410) != 6) {
    if (*(float *)(param_1 + 0x428) <= *gpGlobals) {
      if (*(float *)(param_1 + 0x3fc) <= *gpGlobals) {
        if (*(int *)(param_1 + 0x424) == 0) {
          *(undefined4 *)(param_1 + 0x424) = 1;
          pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
          *pbVar1 = *pbVar1 | 2;
          (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,*(undefined4 *)(param_1 + 0x43c))
          ;
          pfVar3 = gpGlobals;
          *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.1;
          *(float *)(param_1 + 0x404) = *pfVar3 + 0.1;
          *(float *)(param_1 + 0x3fc) = *pfVar3 + 0.1;
          *(float *)(param_1 + 0x400) = *pfVar3 + 0.1;
        }
        else if (*(int *)(param_1 + 0x424) == 1) {
          if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
            *(undefined4 *)(param_1 + 0x424) = 2;
            *(float *)(param_1 + 0x428) = *pfVar3 + *(float *)(param_1 + 0x42c);
            *(float *)(param_1 + 0x404) = *pfVar3 + *(float *)(param_1 + 0x42c);
          }
        }
        else {
          *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + 1;
          piVar2 = (int *)(*(int *)(param_1 + 1000) + 0xe4);
          *piVar2 = *piVar2 + -1;
          *(undefined4 *)(param_1 + 0x424) = 1;
          pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
          *pbVar1 = *pbVar1 & 0xfd;
        }
      }
    }
  }
  return;
}


// Reload__6CTFRpg  @ 00101640
void Reload__6CTFRpg(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float *pfVar3;
  
  if ((*(int *)(*(int *)(param_1 + 1000) + 0xe4) != 0) && (*(int *)(param_1 + 0x410) != 4)) {
    if (*(float *)(param_1 + 0x428) <= *gpGlobals) {
      if (*(float *)(param_1 + 0x3fc) <= *gpGlobals) {
        if (*(int *)(param_1 + 0x424) == 0) {
          (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,7);
          pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
          *pbVar1 = *pbVar1 | 2;
          *(undefined4 *)(param_1 + 0x424) = 1;
          pfVar3 = gpGlobals;
          *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.1;
          *(float *)(param_1 + 0x404) = *pfVar3 + 0.1;
          *(float *)(param_1 + 0x3fc) = *pfVar3 + 0.1;
          *(float *)(param_1 + 0x400) = *pfVar3 + 0.1;
        }
        else if (*(int *)(param_1 + 0x424) == 1) {
          if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
            *(undefined4 *)(param_1 + 0x424) = 2;
            (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,8);
            pfVar3 = gpGlobals;
            *(float *)(param_1 + 0x428) = *gpGlobals + *(float *)(param_1 + 0x42c);
            *(float *)(param_1 + 0x404) = *pfVar3 + *(float *)(param_1 + 0x42c);
          }
        }
        else {
          *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + 1;
          piVar2 = (int *)(*(int *)(param_1 + 1000) + 0xe4);
          *piVar2 = *piVar2 + -1;
          *(undefined4 *)(param_1 + 0x424) = 1;
          pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
          *pbVar1 = *pbVar1 & 0xfd;
        }
      }
    }
  }
  return;
}


// Reload__8CTFTranq  @ 00104110
void Reload__8CTFTranq(void)

{
  return;
}


