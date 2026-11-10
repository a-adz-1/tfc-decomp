// SpectatorConnect__14CBaseSpectator  @ 000f3534
void SpectatorConnect__14CBaseSpectator(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x1a4) = 0x4000000;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 8;
  param_1[1] = 0;
  return;
}


// SpectatorConnect__FP7edict_s  @ 00094730
void SpectatorConnect__FP7edict_s(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
  }
  if (iVar1 != 0) {
    SpectatorConnect__14CBaseSpectator(iVar1);
  }
  return;
}


