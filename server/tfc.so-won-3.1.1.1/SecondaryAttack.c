// SecondaryAttack__10CTFNailgun  @ 0012f564
void SecondaryAttack__10CTFNailgun(void)

{
  return;
}


// SecondaryAttack__10CTFShotgun  @ 001311ec
void SecondaryAttack__10CTFShotgun(void)

{
  return;
}


// SecondaryAttack__13CWeaponCycler  @ 000b3e88
void SecondaryAttack__13CWeaponCycler(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_10;
  float local_c;
  undefined1 local_8 [4];
  
  iVar2 = *(int *)(*param_1 + 0x128);
  uVar1 = iVar2 + 1;
  local_10 = uVar1;
  if ((int)uVar1 < 0) {
    local_10 = iVar2 + 8;
  }
  local_10 = local_10 & 0xfffffff8;
  *(uint *)(*param_1 + 0x128) = uVar1 - local_10;
  *(int *)(*param_1 + 0xb4) = param_1[0x135];
  uVar3 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  GetSequenceInfo__FPvP9entvars_sPfT2(uVar3,*param_1,&local_c,local_8);
  *(undefined4 *)(*param_1 + 0xb4) = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  (**(code **)(param_1[0x115] + 0x168))(param_1,*(undefined4 *)(*param_1 + 0x128),0);
  param_1[0x123] = 0x3e99999a;
  return;
}


// SecondaryAttack__14CTFIncendiaryC  @ 0012ead0
void SecondaryAttack__14CTFIncendiaryC(void)

{
  return;
}


// SecondaryAttack__14CTFSniperRifle  @ 00131ee8
void SecondaryAttack__14CTFSniperRifle(int *param_1)

{
  if (param_1[0x12a] == 0) {
    *(undefined4 *)(param_1[0x11d] + 0x8bc) = 0x14;
    *(undefined4 *)(*(int *)param_1[0x11d] + 0x214) = 0x41a00000;
    param_1[0x12a] = 1;
  }
  else {
    *(undefined4 *)(param_1[0x11d] + 0x8bc) = 0;
    *(undefined4 *)(*(int *)param_1[0x11d] + 0x214) = 0;
    param_1[0x12a] = 0;
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x123] = 0x3e99999a;
  return;
}


// SecondaryAttack__15CTFFlamethrower  @ 0012d79c
void SecondaryAttack__15CTFFlamethrower(void)

{
  return;
}


// SecondaryAttack__17CBasePlayerWeapon  @ 00126594
void SecondaryAttack__17CBasePlayerWeapon(void)

{
  return;
}


// SecondaryAttack__18CTFGrenadeLauncher  @ 0012e464
void SecondaryAttack__18CTFGrenadeLauncher(void)

{
  return;
}


// SecondaryAttack__6CTFRpg  @ 0013023c
void SecondaryAttack__6CTFRpg(void)

{
  return;
}


