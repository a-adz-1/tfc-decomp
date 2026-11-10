// ForceClientDllUpdate__11CBasePlayer  @ 000dbc18
void ForceClientDllUpdate__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0x884) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x888) = 0xffffffff;
  *(byte *)(param_1 + 0x85c) = *(byte *)(param_1 + 0x85c) | 0xc0;
  *(undefined4 *)(param_1 + 0x860) = 0;
  *(undefined4 *)(param_1 + 0x6e0) = 0;
  *(undefined4 *)(param_1 + 0xdd4) = 0;
  *(undefined4 *)(param_1 + 0xdd8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xddc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xde4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xde8) = 0xffffffff;
  UpdateClientData__11CBasePlayer(param_1);
  return;
}


