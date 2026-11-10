// Reload__10CTFNailgun  @ 0011a77c
void Reload__10CTFNailgun(void)

{
  return;
}


// Reload__10CTFRailgun  @ 0011b4e8
void Reload__10CTFRailgun(void)

{
  return;
}


// Reload__10CTFShotgun  @ 0011c33c
void Reload__10CTFShotgun(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  
  if ((((*(int *)(param_1 + 0x454) <= *(int *)(*(int *)(param_1 + 0x3f4) + 0xcc)) &&
       (*(int *)(param_1 + 0x440) != *(int *)(param_1 + 0x458))) &&
      (fVar3 = *(float *)(param_1 + 0x414),
      (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar3 = *(float *)(param_1 + 0x408),
     (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x434) == 0) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,5,1);
      pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      *(undefined4 *)(param_1 + 0x434) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x410) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x408) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x40c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x434) == 1) {
      fVar3 = *(float *)(param_1 + 0x410);
      if ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1) {
        *(undefined4 *)(param_1 + 0x434) = 2;
        (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                        *(undefined2 *)(param_1 + 0x45c),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(param_1 + 0x41c);
        *(undefined4 *)(param_1 + 0x410) = *(undefined4 *)(param_1 + 0x41c);
      }
    }
    else {
      *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + *(int *)(param_1 + 0x454);
      piVar2 = (int *)(*(int *)(param_1 + 0x3f4) + 0xcc);
      *piVar2 = *piVar2 - *(int *)(param_1 + 0x454);
      *(undefined4 *)(param_1 + 0x434) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__11CTFAssaultC  @ 001166a4
void Reload__11CTFAssaultC(void)

{
  return;
}


// Reload__12CTFAutoRifle  @ 00116d34
void Reload__12CTFAutoRifle(void)

{
  return;
}


// Reload__14CTFIncendiaryC  @ 0011a110
void Reload__14CTFIncendiaryC(void)

{
  return;
}


// Reload__14CTFSniperRifle  @ 0011da30
void Reload__14CTFSniperRifle(void)

{
  return;
}


// Reload__15CTFFlamethrower  @ 00118e6c
void Reload__15CTFFlamethrower(void)

{
  return;
}


// Reload__17CBasePlayerWeapon  @ 001123a4
void Reload__17CBasePlayerWeapon(void)

{
  return;
}


// Reload__18CTFGrenadeLauncher  @ 00119acc
void Reload__18CTFGrenadeLauncher(void)

{
  FUN_00119ad3();
  return;
}


// Reload__6CTFRpg  @ 0011b5d8
void Reload__6CTFRpg(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  
  if ((((*(int *)(*(int *)(param_1 + 0x3f4) + 0xe4) != 0) && (*(int *)(param_1 + 0x440) != 4)) &&
      (fVar3 = *(float *)(param_1 + 0x414),
      (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) &&
     (fVar3 = *(float *)(param_1 + 0x408),
     (byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) {
    if (*(int *)(param_1 + 0x434) == 0) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,7,1);
      pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      *(undefined4 *)(param_1 + 0x434) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x410) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x408) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x40c) = 0x3dcccccd;
    }
    else if (*(int *)(param_1 + 0x434) == 1) {
      if (*(float *)(param_1 + 0x410) <= *gpGlobals) {
        *(undefined4 *)(param_1 + 0x434) = 2;
        (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,8,1);
        *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(param_1 + 0x41c);
        *(undefined4 *)(param_1 + 0x410) = *(undefined4 *)(param_1 + 0x41c);
      }
    }
    else {
      *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + 1;
      piVar2 = (int *)(*(int *)(param_1 + 0x3f4) + 0xe4);
      *piVar2 = *piVar2 + -1;
      *(undefined4 *)(param_1 + 0x434) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  return;
}


// Reload__8CTFTranq  @ 0011de44
void Reload__8CTFTranq(void)

{
  return;
}


