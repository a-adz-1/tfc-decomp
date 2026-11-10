// SecondaryAttack__10CTFNailgun  @ 00100850
void SecondaryAttack__10CTFNailgun(void)

{
  return;
}


// SecondaryAttack__10CTFShotgun  @ 00102590
void SecondaryAttack__10CTFShotgun(void)

{
  return;
}


// SecondaryAttack__13CWeaponCycler  @ 000bbf60
void SecondaryAttack__13CWeaponCycler(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  float local_10;
  undefined1 local_c [8];
  
  iVar2 = *(int *)(*param_1 + 0x108);
  uVar1 = iVar2 + 1;
  uVar4 = uVar1;
  if ((int)uVar1 < 0) {
    uVar4 = iVar2 + 8;
  }
  *(uint *)(*param_1 + 0x108) = uVar1 - (uVar4 & 0xfffffff8);
  *(int *)(*param_1 + 0x94) = param_1[0x10a];
  uVar3 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  GetSequenceInfo__FPvP9entvars_tPfT2(uVar3,*param_1,&local_10,local_c);
  *(undefined4 *)(*param_1 + 0x94) = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x108) = 0;
  }
  (**(code **)(param_1[0xf2] + 0x15c))(param_1,*(undefined4 *)(*param_1 + 0x108));
  param_1[0x100] = (int)(*gpGlobals + 0.3);
  return;
}


// SecondaryAttack__14CTFIncendiaryC  @ 000ffaf0
void SecondaryAttack__14CTFIncendiaryC(void)

{
  return;
}


// SecondaryAttack__14CTFSniperRifle  @ 00103c90
void SecondaryAttack__14CTFSniperRifle(int *param_1)

{
  float *pfVar1;
  
  if (param_1[0x10b] == 0) {
    *(undefined4 *)(param_1[0xfa] + 0x810) = 0x14;
    param_1[0x10b] = 1;
  }
  else {
    *(undefined4 *)(param_1[0xfa] + 0x810) = 0;
    param_1[0x10b] = 0;
  }
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[0x100] = (int)(*pfVar1 + 0.3);
  return;
}


// SecondaryAttack__15CTFFlamethrower  @ 000facc0
void SecondaryAttack__15CTFFlamethrower(void)

{
  return;
}


// SecondaryAttack__17CBasePlayerWeapon  @ 0011cb60
void SecondaryAttack__17CBasePlayerWeapon(void)

{
  return;
}


// SecondaryAttack__18CTFGrenadeLauncher  @ 000fbce0
void SecondaryAttack__18CTFGrenadeLauncher(void)

{
  return;
}


// SecondaryAttack__6CTFRpg  @ 00101cd0
void SecondaryAttack__6CTFRpg(void)

{
  return;
}


