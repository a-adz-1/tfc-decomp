// PlayerPostThink__FP7edict_s  @ 000a32c0
void PlayerPostThink__FP7edict_s(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xd8);
  }
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x220))(iVar1);
  }
  return;
}


