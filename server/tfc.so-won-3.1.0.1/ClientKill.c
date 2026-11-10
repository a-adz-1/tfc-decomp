// ClientKill__FP7edict_s  @ 0008790c
void ClientKill__FP7edict_s(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x288);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_0008794e;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_0008794e:
  if (*(int *)(param_1 + 0x28c) != 0) {
    if (*(float *)(iVar1 + 0x67c) <= *gpGlobals) {
      *(float *)(iVar1 + 0x67c) = *gpGlobals + 5.0;
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x3c))(iVar1,param_1 + 0x80,1);
    }
  }
  return;
}


