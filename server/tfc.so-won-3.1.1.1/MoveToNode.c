// MoveToNode__12CBaseMonster8ActivityfRC6Vector  @ 000c29d4
void MoveToNode__12CBaseMonster8ActivityfRC6Vector
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *(undefined4 *)(param_1 + 0x620) = param_2;
  *(undefined4 *)(param_1 + 0x608) = 0x20;
  *(undefined4 *)(param_1 + 0x610) = param_3;
  *(undefined4 *)(param_1 + 0x614) = *param_4;
  *(undefined4 *)(param_1 + 0x618) = param_4[1];
  *(undefined4 *)(param_1 + 0x61c) = param_4[2];
  FRefreshRoute__12CBaseMonster(param_1);
  return;
}


