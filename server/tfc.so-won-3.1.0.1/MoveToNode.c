// MoveToNode__12CBaseMonster8ActivityfRC6Vector  @ 000af7d0
void MoveToNode__12CBaseMonster8ActivityfRC6Vector
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *(undefined4 *)(param_1 + 0x5a0) = param_2;
  *(undefined4 *)(param_1 + 0x590) = param_3;
  *(undefined4 *)(param_1 + 0x588) = 0x20;
  *(undefined4 *)(param_1 + 0x594) = *param_4;
  *(undefined4 *)(param_1 + 0x598) = param_4[1];
  *(undefined4 *)(param_1 + 0x59c) = param_4[2];
  FRefreshRoute__12CBaseMonster(param_1);
  return;
}


