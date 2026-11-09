// MoveToTarget__12CBaseMonster8Activityf  @ 000c1c60
void MoveToTarget__12CBaseMonster8Activityf(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x594) = param_2;
  *(undefined4 *)(param_1 + 0x584) = param_3;
  *(undefined4 *)(param_1 + 0x57c) = 1;
  FRefreshRoute__12CBaseMonster(param_1);
  return;
}


