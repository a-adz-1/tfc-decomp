// CanHolster__12CHandGrenade  @ 000bc660
bool CanHolster__12CHandGrenade(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x424);
  return (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
}


// CanHolster__14CTFIncendiaryC  @ 000ff860
undefined4 CanHolster__14CTFIncendiaryC(void)

{
  return 1;
}


// CanHolster__15CBasePlayerItem  @ 0011cc40
undefined4 CanHolster__15CBasePlayerItem(void)

{
  return 1;
}


// CanHolster__15CTFFlamethrower  @ 000fa9c0
undefined4 CanHolster__15CTFFlamethrower(void)

{
  return 1;
}


// CanHolster__6CTFRpg  @ 001019e0
undefined4 CanHolster__6CTFRpg(void)

{
  return 1;
}


