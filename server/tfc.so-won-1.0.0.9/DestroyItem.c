// DestroyItem__15CBasePlayerItem  @ 0011b340
void DestroyItem__15CBasePlayerItem(int param_1)

{
  if (*(int *)(param_1 + 1000) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 1000) + 0x3c8) + 0x5c))
              (*(int *)(param_1 + 1000),param_1);
  }
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x134))(param_1);
  return;
}


