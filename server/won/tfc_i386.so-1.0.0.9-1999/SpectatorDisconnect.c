// SpectatorDisconnect__14CBaseSpectator  @ 000ee5e0
void SpectatorDisconnect__14CBaseSpectator(void)

{
  return;
}


// SpectatorDisconnect__FP7edict_s  @ 000a3af0
void SpectatorDisconnect__FP7edict_s(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xd8);
  }
  if (iVar1 != 0) {
    SpectatorDisconnect__14CBaseSpectator(iVar1);
  }
  return;
}


