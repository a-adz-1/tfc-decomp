// RouteClear__12CBaseMonster  @ 000c2b58
void RouteClear__12CBaseMonster(int param_1)

{
  RouteNew__12CBaseMonster(param_1);
  *(undefined4 *)(param_1 + 0x608) = 0;
  *(undefined4 *)(param_1 + 0x620) = 1;
  *(byte *)(param_1 + 0x63c) = *(byte *)(param_1 + 0x63c) & 0xdf;
  return;
}


