// SpectatorConnect__14CBaseSpectator  @ 000ee5a0
void SpectatorConnect__14CBaseSpectator(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x184) = 0x4000000;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 8;
  param_1[1] = 0;
  return;
}


// SpectatorConnect__FP7edict_s  @ 000a3ac0
void SpectatorConnect__FP7edict_s(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xd8);
  }
  if (iVar1 != 0) {
    SpectatorConnect__14CBaseSpectator(iVar1);
  }
  return;
}


