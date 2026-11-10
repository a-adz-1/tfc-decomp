// IsSneaking__11CBaseEntity  @ 0010f964
undefined4 IsSneaking__11CBaseEntity(void)

{
  return 0;
}


// IsSneaking__11CBasePlayer  @ 000e4ca4
bool IsSneaking__11CBasePlayer(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 0x87c);
  fVar2 = *gpGlobals;
  return (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40;
}


