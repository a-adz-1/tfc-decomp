// BarnacleVictimBitten__11CBasePlayerP9entvars_s  @ 000e5270
void BarnacleVictimBitten__11CBasePlayerP9entvars_s(int *param_1,undefined4 param_2)

{
  (**(code **)(param_1[0x115] + 0x38))
            (param_1,param_2,param_2,*(float *)(*param_1 + 0x160) + *(float *)(*param_1 + 0x1bc),
             0x2004);
  return;
}


// BarnacleVictimBitten__12CBaseMonsterP9entvars_s  @ 000c2cc8
void BarnacleVictimBitten__12CBaseMonsterP9entvars_s(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x174))(param_1,0x27);
  if (iVar1 != 0) {
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,iVar1);
  }
  return;
}


