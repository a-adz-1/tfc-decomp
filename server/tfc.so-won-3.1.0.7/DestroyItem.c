// DestroyItem__15CBasePlayerItem  @ 00120144
void DestroyItem__15CBasePlayerItem(int param_1)

{
  if (*(int *)(param_1 + 0x464) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x464) + 0x444) + 0x60))
              (*(int *)(param_1 + 0x464),param_1);
  }
  (**(code **)(*(int *)(param_1 + 0x444) + 0x13c))(param_1);
  return;
}


