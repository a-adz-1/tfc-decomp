// SpectatorDisconnect__14CBaseSpectator  @ 000e4550
void SpectatorDisconnect__14CBaseSpectator(void)

{
  return;
}


// SpectatorDisconnect__FP7edict_s  @ 0008a8ec
void SpectatorDisconnect__FP7edict_s(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
  }
  if (iVar1 != 0) {
    SpectatorDisconnect__14CBaseSpectator(iVar1);
  }
  return;
}


