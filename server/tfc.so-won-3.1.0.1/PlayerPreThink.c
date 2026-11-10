// PlayerPreThink__FP7edict_s  @ 00089d44
void PlayerPreThink__FP7edict_s(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
  }
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x21c))(iVar1);
  }
  return;
}


