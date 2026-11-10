// SecondaryAttack__10CTFNailgun  @ 0012b0d4
void SecondaryAttack__10CTFNailgun(void)

{
  return;
}


// SecondaryAttack__10CTFShotgun  @ 0012c860
void SecondaryAttack__10CTFShotgun(void)

{
  return;
}


// SecondaryAttack__13CWeaponCycler  @ 000b4ee8
void SecondaryAttack__13CWeaponCycler(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  float fStack_8;
  undefined1 auStack_4 [4];
  
  iVar2 = *(int *)(*param_1 + 0x128);
  uVar1 = iVar2 + 1;
  uVar4 = uVar1;
  if ((int)uVar1 < 0) {
    uVar4 = iVar2 + 8;
  }
  *(uint *)(*param_1 + 0x128) = uVar1 - (uVar4 & 0xfffffff8);
  *(int *)(*param_1 + 0xb4) = param_1[0x131];
  uVar3 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  GetSequenceInfo__FPvP9entvars_sPfT2(uVar3,*param_1,&fStack_8,auStack_4);
  *(undefined4 *)(*param_1 + 0xb4) = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_8) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_8 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  (**(code **)(param_1[0x111] + 0x168))(param_1,*(undefined4 *)(*param_1 + 0x128),0);
  param_1[0x11f] = 0x3e99999a;
  return;
}


// SecondaryAttack__14CTFIncendiaryC  @ 0012aa60
void SecondaryAttack__14CTFIncendiaryC(void)

{
  return;
}


// SecondaryAttack__14CTFSniperRifle  @ 0012df30
void SecondaryAttack__14CTFSniperRifle(int *param_1)

{
  if (param_1[0x126] == 0) {
    *(undefined4 *)(param_1[0x119] + 0x894) = 0x14;
    *(undefined4 *)(*(int *)param_1[0x119] + 0x214) = 0x41a00000;
    param_1[0x126] = 1;
  }
  else {
    *(undefined4 *)(param_1[0x119] + 0x894) = 0;
    *(undefined4 *)(*(int *)param_1[0x119] + 0x214) = 0;
    param_1[0x126] = 0;
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x11f] = 0x3e99999a;
  return;
}


// SecondaryAttack__15CTFFlamethrower  @ 00129724
void SecondaryAttack__15CTFFlamethrower(void)

{
  return;
}


// SecondaryAttack__17CBasePlayerWeapon  @ 00121f38
void SecondaryAttack__17CBasePlayerWeapon(void)

{
  return;
}


// SecondaryAttack__18CTFGrenadeLauncher  @ 00129e68
void SecondaryAttack__18CTFGrenadeLauncher(void)

{
  return;
}


// SecondaryAttack__6CTFRpg  @ 0012c16c
void SecondaryAttack__6CTFRpg(void)

{
  return;
}


