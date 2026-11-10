// DestroyItem__15CBasePlayerItem  @ 001105f4
void DestroyItem__15CBasePlayerItem(int param_1)

{
  if (*(int *)(param_1 + 0x3f4) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x3f4) + 0x3d4) + 0x5c))
              (*(int *)(param_1 + 0x3f4),param_1);
  }
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x134))(param_1);
  return;
}


