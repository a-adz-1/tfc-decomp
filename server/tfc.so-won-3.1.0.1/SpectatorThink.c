// SpectatorThink__14CBaseSpectator  @ 000e46a4
void SpectatorThink__14CBaseSpectator(int *param_1)

{
  if ((*(byte *)(*param_1 + 0x1a7) & 4) == 0) {
    *(undefined4 *)(*param_1 + 0x1a4) = 0x4000000;
  }
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 8;
  if (*(int *)(*param_1 + 0x184) != 0) {
    SpectatorImpulseCommand__14CBaseSpectator(param_1);
  }
  return;
}


// SpectatorThink__FP7edict_s  @ 0008a918
void SpectatorThink__FP7edict_s(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
  }
  if (iVar1 != 0) {
    SpectatorThink__14CBaseSpectator(iVar1);
  }
  return;
}


