// ClientKill__FP7edict_s  @ 000a1f60
void ClientKill__FP7edict_s(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c4);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_000a1fa2;
    }
  }
  iVar1 = *(int *)(iVar1 + 0xd8);
LAB_000a1fa2:
  if (*(int *)(iVar1 + 0x2c) != 0) {
    if (*(float *)(iVar1 + 0x66c) <= *gpGlobals) {
      *(float *)(iVar1 + 0x66c) = *gpGlobals + 5.0;
      *(undefined4 *)(param_1 + 0x21c) = 0;
      (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x3c))(iVar1,param_1 + 0xdc,1);
    }
  }
  return;
}


