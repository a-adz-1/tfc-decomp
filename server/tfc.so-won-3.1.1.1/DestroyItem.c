// DestroyItem__15CBasePlayerItem  @ 00125d14
void DestroyItem__15CBasePlayerItem(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x474);
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x454) + 0x60))(iVar1,param_1);
  }
  (**(code **)(*(int *)(param_1 + 0x454) + 0x13c))(param_1);
  return;
}


