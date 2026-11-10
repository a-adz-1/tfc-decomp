// PlayScriptedSentence__12CBaseMonsterPCcfffiP11CBaseEntity  @ 000c19e4
void PlayScriptedSentence__12CBaseMonsterPCcfffiP11CBaseEntity
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  (**(code **)(*(int *)(param_1 + 0x444) + 0x188))(param_1,param_2,param_3,param_4,param_5);
  return;
}


// PlayScriptedSentence__12CTalkMonsterPCcfffiP11CBaseEntity  @ 000f62cc
void PlayScriptedSentence__12CTalkMonsterPCcfffiP11CBaseEntity
               (int param_1,undefined4 param_2,float param_3,undefined4 param_4,undefined4 param_5,
               int param_6,undefined4 param_7)

{
  if (param_6 == 0) {
    ShutUpFriends__12CTalkMonster(param_1);
  }
  *(byte *)(param_1 + 0x4eb) = *(byte *)(param_1 + 0x4eb) & 0xef;
  *(float *)(param_1 + 0x6e0) = param_3 + *gpGlobals;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x188))(param_1,param_2,param_3,param_4,param_5);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x6f4,param_7);
  return;
}


