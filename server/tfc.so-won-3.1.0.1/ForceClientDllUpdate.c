// ForceClientDllUpdate__11CBasePlayer  @ 000d0550
void ForceClientDllUpdate__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0x814) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x818) = 0xffffffff;
  *(byte *)(param_1 + 0x7ec) = *(byte *)(param_1 + 0x7ec) | 0xc0;
  *(undefined4 *)(param_1 + 0x7f0) = 0;
  *(undefined4 *)(param_1 + 0x670) = 0;
  *(undefined4 *)(param_1 + 0xd54) = 0;
  *(undefined4 *)(param_1 + 0xd58) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd5c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd64) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd68) = 0xffffffff;
  UpdateClientData__11CBasePlayer(param_1);
  return;
}


