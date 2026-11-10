// MoveToTarget__12CBaseMonster8Activityf  @ 000ba9f4
void MoveToTarget__12CBaseMonster8Activityf(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x610) = param_2;
  *(undefined4 *)(param_1 + 0x600) = param_3;
  *(undefined4 *)(param_1 + 0x5f8) = 1;
  FRefreshRoute__12CBaseMonster(param_1);
  return;
}


