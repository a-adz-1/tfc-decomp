// RouteClear__12CBaseMonster  @ 000af4a8
void RouteClear__12CBaseMonster(int param_1)

{
  RouteNew__12CBaseMonster(param_1);
  *(undefined4 *)(param_1 + 0x588) = 0;
  *(undefined4 *)(param_1 + 0x5a0) = 1;
  *(byte *)(param_1 + 0x5bc) = *(byte *)(param_1 + 0x5bc) & 0xdf;
  return;
}


