// ForceClientDllUpdate__11CBasePlayer  @ 000dda00
void ForceClientDllUpdate__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0x800) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x804) = 0xffffffff;
  *(byte *)(param_1 + 0x7d8) = *(byte *)(param_1 + 0x7d8) | 0xc0;
  *(undefined4 *)(param_1 + 0x7dc) = 0;
  *(undefined4 *)(param_1 + 0x660) = 0;
  UpdateClientData__11CBasePlayer(param_1);
  return;
}


