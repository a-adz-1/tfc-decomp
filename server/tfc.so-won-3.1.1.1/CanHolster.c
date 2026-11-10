// CanHolster__12CHandGrenade  @ 000b4ff0
bool CanHolster__12CHandGrenade(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x4d0);
  return (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
}


// CanHolster__14CTFIncendiaryC  @ 0012eb20
undefined4 CanHolster__14CTFIncendiaryC(void)

{
  return 1;
}


// CanHolster__15CBasePlayerItem  @ 00126694
undefined4 CanHolster__15CBasePlayerItem(void)

{
  return 1;
}


// CanHolster__15CTFFlamethrower  @ 0012d7ec
undefined4 CanHolster__15CTFFlamethrower(void)

{
  return 1;
}


// CanHolster__6CTFRpg  @ 00130298
undefined4 CanHolster__6CTFRpg(void)

{
  return 1;
}


