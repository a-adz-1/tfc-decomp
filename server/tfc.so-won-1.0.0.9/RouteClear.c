// RouteClear__12CBaseMonster  @ 000c19b0
void RouteClear__12CBaseMonster(int param_1)

{
  RouteNew__12CBaseMonster(param_1);
  *(undefined4 *)(param_1 + 0x57c) = 0;
  *(undefined4 *)(param_1 + 0x594) = 1;
  *(byte *)(param_1 + 0x5b0) = *(byte *)(param_1 + 0x5b0) & 0xdf;
  return;
}


