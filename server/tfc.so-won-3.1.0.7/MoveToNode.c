// MoveToNode__12CBaseMonster8ActivityfRC6Vector  @ 000baa30
void MoveToNode__12CBaseMonster8ActivityfRC6Vector
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *(undefined4 *)(param_1 + 0x610) = param_2;
  *(undefined4 *)(param_1 + 0x600) = param_3;
  *(undefined4 *)(param_1 + 0x5f8) = 0x20;
  *(undefined4 *)(param_1 + 0x604) = *param_4;
  *(undefined4 *)(param_1 + 0x608) = param_4[1];
  *(undefined4 *)(param_1 + 0x60c) = param_4[2];
  FRefreshRoute__12CBaseMonster(param_1);
  return;
}


