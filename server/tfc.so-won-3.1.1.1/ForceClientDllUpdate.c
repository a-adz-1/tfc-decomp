// ForceClientDllUpdate__11CBasePlayer  @ 000e5620
void ForceClientDllUpdate__11CBasePlayer(int param_1)

{
  *(undefined4 *)(param_1 + 0x8ac) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8b0) = 0xffffffff;
  *(byte *)(param_1 + 0x884) = *(byte *)(param_1 + 0x884) | 0xc0;
  *(undefined4 *)(param_1 + 0x888) = 0;
  *(undefined4 *)(param_1 + 0x704) = 0;
  *(undefined4 *)(param_1 + 0x87c) = 1;
  *(undefined4 *)(param_1 + 0xdf0) = 0;
  *(undefined4 *)(param_1 + 0xdf4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xdf8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe00) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe04) = 0xffffffff;
  UpdateClientData__11CBasePlayer(param_1);
  return;
}


