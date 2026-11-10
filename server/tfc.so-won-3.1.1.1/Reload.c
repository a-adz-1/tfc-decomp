// Reload__10CTFNailgun  @ 0012f788
void Reload__10CTFNailgun(void)

{
  return;
}


// Reload__10CTFRailgun  @ 0012fb18
void Reload__10CTFRailgun(void)

{
  return;
}


// Reload__10CTFShotgun  @ 00130954
void Reload__10CTFShotgun(int param_1)

{
  byte *pbVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = *(int **)(param_1 + 0x474);
  iVar4 = *(int *)(param_1 + 0x4d4);
  if ((((iVar4 <= piVar3[0x33]) && (*(int *)(param_1 + 0x4c0) != *(int *)(param_1 + 0x4d8))) &&
      (fVar2 = *(float *)(param_1 + 0x494),
      (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar2 = *(float *)(param_1 + 0x488),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x4b4) == 0) {
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,5,1);
      pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      *(undefined4 *)(param_1 + 0x4b4) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x490) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x488) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x48c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x4b4) == 1) {
      fVar2 = *(float *)(param_1 + 0x490);
      if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
        *(undefined4 *)(param_1 + 0x4b4) = 2;
        (*DAT_0019f88c)(1,*(undefined4 *)(*piVar3 + 0x208),*(undefined2 *)(param_1 + 0x4dc),0,
                        &g_vecZero,&g_vecZero,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x494) = *(undefined4 *)(param_1 + 0x49c);
        *(undefined4 *)(param_1 + 0x490) = *(undefined4 *)(param_1 + 0x49c);
      }
    }
    else {
      *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + iVar4;
      piVar3[0x33] = piVar3[0x33] - iVar4;
      *(undefined4 *)(param_1 + 0x4b4) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__11CTFAssaultC  @ 0012a4c0
void Reload__11CTFAssaultC(void)

{
  return;
}


// Reload__12CTFAutoRifle  @ 0012ac18
void Reload__12CTFAutoRifle(void)

{
  return;
}


// Reload__14CTFIncendiaryC  @ 0012ee14
void Reload__14CTFIncendiaryC(void)

{
  return;
}


// Reload__14CTFSniperRifle  @ 00131ee0
void Reload__14CTFSniperRifle(void)

{
  return;
}


// Reload__15CTFFlamethrower  @ 0012dab8
void Reload__15CTFFlamethrower(void)

{
  return;
}


// Reload__17CBasePlayerWeapon  @ 0012658c
void Reload__17CBasePlayerWeapon(void)

{
  return;
}


// Reload__18CTFGrenadeLauncher  @ 0012e334
void Reload__18CTFGrenadeLauncher(int param_1)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x474);
  if ((((*(int *)(iVar3 + 0xe4) != 0) && (*(int *)(param_1 + 0x4c0) != 6)) &&
      (fVar2 = *(float *)(param_1 + 0x494),
      (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar2 = *(float *)(param_1 + 0x488),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x4b4) == 0) {
      *(undefined4 *)(param_1 + 0x4b4) = 1;
      *(byte *)(iVar3 + 0x84) = *(byte *)(iVar3 + 0x84) | 2;
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4dc),1);
      *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x490) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x488) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x48c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x4b4) == 1) {
      fVar2 = *(float *)(param_1 + 0x490);
      if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
        *(undefined4 *)(param_1 + 0x4b4) = 2;
        *(undefined4 *)(param_1 + 0x494) = *(undefined4 *)(param_1 + 0x49c);
        *(undefined4 *)(param_1 + 0x490) = *(undefined4 *)(param_1 + 0x49c);
      }
    }
    else {
      *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + 1;
      *(int *)(iVar3 + 0xe4) = *(int *)(iVar3 + 0xe4) + -1;
      *(undefined4 *)(param_1 + 0x4b4) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__6CTFRpg  @ 0012fdc0
void Reload__6CTFRpg(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  
  if ((((*(int *)(*(int *)(param_1 + 0x474) + 0xe4) != 0) && (*(int *)(param_1 + 0x4c0) != 4)) &&
      (fVar3 = *(float *)(param_1 + 0x494),
      (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar3 = *(float *)(param_1 + 0x488),
     (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x4b4) == 0) {
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,7,1);
      pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      *(undefined4 *)(param_1 + 0x4b4) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x490) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x488) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x48c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x4b4) == 1) {
      fVar3 = *gpGlobals;
      fVar4 = *(float *)(param_1 + 0x490);
      if ((byte)(fVar3 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) != 1) {
        *(undefined4 *)(param_1 + 0x4b4) = 2;
        (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,8,1);
        *(undefined4 *)(param_1 + 0x494) = *(undefined4 *)(param_1 + 0x49c);
        *(undefined4 *)(param_1 + 0x490) = *(undefined4 *)(param_1 + 0x49c);
      }
    }
    else {
      *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + 1;
      piVar2 = (int *)(*(int *)(param_1 + 0x474) + 0xe4);
      *piVar2 = *piVar2 + -1;
      *(undefined4 *)(param_1 + 0x4b4) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__8CTFTranq  @ 00132838
void Reload__8CTFTranq(void)

{
  return;
}


