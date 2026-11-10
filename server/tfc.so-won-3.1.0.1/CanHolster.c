// CanHolster__12CHandGrenade  @ 000aa7bc
bool CanHolster__12CHandGrenade(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x450);
  return (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
}


// CanHolster__14CTFIncendiaryC  @ 0011a3d4
undefined4 CanHolster__14CTFIncendiaryC(void)

{
  return 1;
}


// CanHolster__15CBasePlayerItem  @ 00112448
undefined4 CanHolster__15CBasePlayerItem(void)

{
  return 1;
}


// CanHolster__15CTFFlamethrower  @ 00119108
undefined4 CanHolster__15CTFFlamethrower(void)

{
  return 1;
}


// CanHolster__6CTFRpg  @ 0011b9d0
undefined4 CanHolster__6CTFRpg(void)

{
  return 1;
}


