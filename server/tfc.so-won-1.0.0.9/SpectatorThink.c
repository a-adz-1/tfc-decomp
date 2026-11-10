// SpectatorThink__14CBaseSpectator  @ 000ee700
void SpectatorThink__14CBaseSpectator(int *param_1)

{
  if ((*(byte *)(*param_1 + 0x187) & 4) == 0) {
    *(undefined4 *)(*param_1 + 0x184) = 0x4000000;
  }
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 8;
  if (*(int *)(*param_1 + 0x164) != 0) {
    SpectatorImpulseCommand__14CBaseSpectator(param_1);
  }
  return;
}


// SpectatorThink__FP7edict_s  @ 000a3b20
void SpectatorThink__FP7edict_s(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xd8);
  }
  if (iVar1 != 0) {
    SpectatorThink__14CBaseSpectator(iVar1);
  }
  return;
}


