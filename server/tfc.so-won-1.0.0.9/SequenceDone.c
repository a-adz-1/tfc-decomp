// SequenceDone__12CCineMonsterP12CBaseMonster  @ 000e7ae0
void SequenceDone__12CCineMonsterP12CBaseMonster(int *param_1,undefined4 param_2)

{
  if ((*(byte *)(*param_1 + 0x180) & 4) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  CineCleanup__12CBaseMonster(param_2);
  (**(code **)(param_1[0xf2] + 0x220))(param_1,param_2);
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,0,3,0);
  return;
}


