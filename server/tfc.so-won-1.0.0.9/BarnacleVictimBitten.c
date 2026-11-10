// BarnacleVictimBitten__11CBasePlayerP9entvars_t  @ 000df620
void BarnacleVictimBitten__11CBasePlayerP9entvars_t(int *param_1,undefined4 param_2)

{
  (**(code **)(param_1[0xf2] + 0x34))
            (param_1,param_2,param_2,*(float *)(*param_1 + 0x140) + *(float *)(*param_1 + 0x19c),
             0x2004);
  return;
}


// BarnacleVictimBitten__12CBaseMonsterP9entvars_t  @ 000c1000
void BarnacleVictimBitten__12CBaseMonsterP9entvars_t(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x16c))(param_1,0x27);
  if (iVar1 != 0) {
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,iVar1);
  }
  return;
}


