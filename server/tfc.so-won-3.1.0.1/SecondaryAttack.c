// SecondaryAttack__10CTFNailgun  @ 0011ac88
void SecondaryAttack__10CTFNailgun(void)

{
  return;
}


// SecondaryAttack__10CTFShotgun  @ 0011c338
void SecondaryAttack__10CTFShotgun(void)

{
  return;
}


// SecondaryAttack__13CWeaponCycler  @ 000a9f18
void SecondaryAttack__13CWeaponCycler(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  float local_8;
  undefined1 local_4 [4];
  
  iVar2 = *(int *)(*param_1 + 0x128);
  uVar1 = iVar2 + 1;
  uVar4 = uVar1;
  if ((int)uVar1 < 0) {
    uVar4 = iVar2 + 8;
  }
  *(uint *)(*param_1 + 0x128) = uVar1 - (uVar4 & 0xfffffff8);
  *(int *)(*param_1 + 0xb4) = param_1[0x115];
  uVar3 = (*DAT_001a7f68)(*(undefined4 *)(*param_1 + 0x208));
  GetSequenceInfo__FPvP9entvars_sPfT2(uVar3,*param_1,&local_8,local_4);
  *(undefined4 *)(*param_1 + 0xb4) = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_8 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  (**(code **)(param_1[0xf5] + 0x160))(param_1,*(undefined4 *)(*param_1 + 0x128),0);
  param_1[0x103] = 0x3e99999a;
  return;
}


// SecondaryAttack__14CTFIncendiaryC  @ 0011a65c
void SecondaryAttack__14CTFIncendiaryC(void)

{
  return;
}


// SecondaryAttack__14CTFSniperRifle  @ 0011d988
void SecondaryAttack__14CTFSniperRifle(int *param_1)

{
  if (param_1[0x10a] == 0) {
    *(undefined4 *)(param_1[0xfd] + 0x824) = 0x14;
    *(undefined4 *)(*(int *)param_1[0xfd] + 0x214) = 0x41a00000;
    param_1[0x10a] = 1;
  }
  else {
    *(undefined4 *)(param_1[0xfd] + 0x824) = 0;
    *(undefined4 *)(*(int *)param_1[0xfd] + 0x214) = 0;
    param_1[0x10a] = 0;
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x103] = 0x3e99999a;
  return;
}


// SecondaryAttack__15CTFFlamethrower  @ 001193bc
void SecondaryAttack__15CTFFlamethrower(void)

{
  return;
}


// SecondaryAttack__17CBasePlayerWeapon  @ 001123a8
void SecondaryAttack__17CBasePlayerWeapon(void)

{
  return;
}


// SecondaryAttack__18CTFGrenadeLauncher  @ 00119ac8
void SecondaryAttack__18CTFGrenadeLauncher(void)

{
  return;
}


// SecondaryAttack__6CTFRpg  @ 0011bc84
void SecondaryAttack__6CTFRpg(void)

{
  return;
}


