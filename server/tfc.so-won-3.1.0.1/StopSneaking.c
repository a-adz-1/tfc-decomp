// StopSneaking__11CBaseEntity  @ 00100664
void StopSneaking__11CBaseEntity(void)

{
  return;
}


// StopSneaking__11CBasePlayer  @ 000d8d10
void StopSneaking__11CBasePlayer(int param_1)

{
  *(float *)(param_1 + 0x80c) = *gpGlobals + 30.0;
  return;
}


