// IsSneaking__11CBaseEntity  @ 00112e34
undefined4 IsSneaking__11CBaseEntity(void)

{
  return 0;
}


// IsSneaking__11CBasePlayer  @ 000e60fc
bool IsSneaking__11CBasePlayer(int param_1)

{
  return *(float *)(param_1 + 0x8a4) <= *gpGlobals;
}


