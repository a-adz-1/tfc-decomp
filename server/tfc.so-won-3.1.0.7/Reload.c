// Reload__10CTFNailgun  @ 0012aba0
void Reload__10CTFNailgun(void)

{
  return;
}


// Reload__10CTFRailgun  @ 0012b998
void Reload__10CTFRailgun(void)

{
  return;
}


// Reload__10CTFShotgun  @ 0012c864
void Reload__10CTFShotgun(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  
  if ((((*(int *)(param_1 + 0x4c4) <= *(int *)(*(int *)(param_1 + 0x464) + 0xcc)) &&
       (*(int *)(param_1 + 0x4b0) != *(int *)(param_1 + 0x4c8))) &&
      (fVar3 = *(float *)(param_1 + 0x484),
      (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar3 = *(float *)(param_1 + 0x478),
     (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x4a4) == 0) {
      (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,5,1);
      pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      *(undefined4 *)(param_1 + 0x4a4) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x480) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x478) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x47c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x4a4) == 1) {
      fVar3 = *(float *)(param_1 + 0x480);
      if ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1) {
        *(undefined4 *)(param_1 + 0x4a4) = 2;
        (*DAT_001c120c)(1,*(undefined4 *)(**(int **)(param_1 + 0x464) + 0x208),
                        *(undefined2 *)(param_1 + 0x4cc),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x484) = *(undefined4 *)(param_1 + 0x48c);
        *(undefined4 *)(param_1 + 0x480) = *(undefined4 *)(param_1 + 0x48c);
      }
    }
    else {
      *(int *)(param_1 + 0x4b0) = *(int *)(param_1 + 0x4b0) + *(int *)(param_1 + 0x4c4);
      piVar2 = (int *)(*(int *)(param_1 + 0x464) + 0xcc);
      *piVar2 = *piVar2 - *(int *)(param_1 + 0x4c4);
      *(undefined4 *)(param_1 + 0x4a4) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__11CTFAssaultC  @ 001263dc
void Reload__11CTFAssaultC(void)

{
  return;
}


// Reload__12CTFAutoRifle  @ 00126ab0
void Reload__12CTFAutoRifle(void)

{
  return;
}


// Reload__14CTFIncendiaryC  @ 0012a4f8
void Reload__14CTFIncendiaryC(void)

{
  return;
}


// Reload__14CTFSniperRifle  @ 0012dfd8
void Reload__14CTFSniperRifle(void)

{
  return;
}


// Reload__15CTFFlamethrower  @ 001291b4
void Reload__15CTFFlamethrower(void)

{
  return;
}


// Reload__17CBasePlayerWeapon  @ 00121f34
void Reload__17CBasePlayerWeapon(void)

{
  return;
}


// Reload__18CTFGrenadeLauncher  @ 00129e6c
void Reload__18CTFGrenadeLauncher(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  
  if ((((*(int *)(*(int *)(param_1 + 0x464) + 0xe4) != 0) && (*(int *)(param_1 + 0x4b0) != 6)) &&
      (fVar3 = *(float *)(param_1 + 0x484),
      (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar3 = *(float *)(param_1 + 0x478),
     (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x4a4) == 0) {
      *(undefined4 *)(param_1 + 0x4a4) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4cc),1);
      *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x480) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x478) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x47c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x4a4) == 1) {
      fVar3 = *(float *)(param_1 + 0x480);
      if ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1) {
        *(undefined4 *)(param_1 + 0x4a4) = 2;
        *(undefined4 *)(param_1 + 0x484) = *(undefined4 *)(param_1 + 0x48c);
        *(undefined4 *)(param_1 + 0x480) = *(undefined4 *)(param_1 + 0x48c);
      }
    }
    else {
      *(int *)(param_1 + 0x4b0) = *(int *)(param_1 + 0x4b0) + 1;
      piVar2 = (int *)(*(int *)(param_1 + 0x464) + 0xe4);
      *piVar2 = *piVar2 + -1;
      *(undefined4 *)(param_1 + 0x4a4) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__6CTFRpg  @ 0012baa8
void Reload__6CTFRpg(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  
  if ((((*(int *)(*(int *)(param_1 + 0x464) + 0xe4) != 0) && (*(int *)(param_1 + 0x4b0) != 4)) &&
      (fVar3 = *(float *)(param_1 + 0x484),
      (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar3 = *(float *)(param_1 + 0x478),
     (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x4a4) == 0) {
      (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,7,1);
      pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      *(undefined4 *)(param_1 + 0x4a4) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x480) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x478) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x47c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x4a4) == 1) {
      if (*(float *)(param_1 + 0x480) <= *gpGlobals) {
        *(undefined4 *)(param_1 + 0x4a4) = 2;
        (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,8,1);
        *(undefined4 *)(param_1 + 0x484) = *(undefined4 *)(param_1 + 0x48c);
        *(undefined4 *)(param_1 + 0x480) = *(undefined4 *)(param_1 + 0x48c);
      }
    }
    else {
      *(int *)(param_1 + 0x4b0) = *(int *)(param_1 + 0x4b0) + 1;
      piVar2 = (int *)(*(int *)(param_1 + 0x464) + 0xe4);
      *piVar2 = *piVar2 + -1;
      *(undefined4 *)(param_1 + 0x4a4) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__8CTFTranq  @ 0012e424
void Reload__8CTFTranq(void)

{
  return;
}


