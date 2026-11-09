// MoveToNode__12CBaseMonster8ActivityfRC6Vector  @ 000c1c90
void MoveToNode__12CBaseMonster8ActivityfRC6Vector
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *(undefined4 *)(param_1 + 0x594) = param_2;
  *(undefined4 *)(param_1 + 0x584) = param_3;
  *(undefined4 *)(param_1 + 0x57c) = 0x20;
  *(undefined4 *)(param_1 + 0x588) = *param_4;
  *(undefined4 *)(param_1 + 0x58c) = param_4[1];
  *(undefined4 *)(param_1 + 0x590) = param_4[2];
  FRefreshRoute__12CBaseMonster(param_1);
  return;
}


