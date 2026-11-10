// MoveToTarget__12CBaseMonster8Activityf  @ 000af794
void MoveToTarget__12CBaseMonster8Activityf(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x5a0) = param_2;
  *(undefined4 *)(param_1 + 0x590) = param_3;
  *(undefined4 *)(param_1 + 0x588) = 1;
  FRefreshRoute__12CBaseMonster(param_1);
  return;
}


