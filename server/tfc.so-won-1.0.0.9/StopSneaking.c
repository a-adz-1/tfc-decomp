// StopSneaking__11CBaseEntity  @ 0010e3f0
void StopSneaking__11CBaseEntity(void)

{
  return;
}


// StopSneaking__11CBasePlayer  @ 000e4500
void StopSneaking__11CBasePlayer(int param_1)

{
  *(float *)(param_1 + 0x7f8) = *gpGlobals + 30.0;
  return;
}


