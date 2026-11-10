// PlayScriptedSentence__12CBaseMonsterPCcfffiP11CBaseEntity  @ 000b6784
void PlayScriptedSentence__12CBaseMonsterPCcfffiP11CBaseEntity
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x180))(param_1,param_2,param_3,param_4,param_5);
  return;
}


// PlayScriptedSentence__12CTalkMonsterPCcfffiP11CBaseEntity  @ 000e95f0
void PlayScriptedSentence__12CTalkMonsterPCcfffiP11CBaseEntity
               (int param_1,undefined4 param_2,float param_3,undefined4 param_4,undefined4 param_5,
               int param_6,undefined4 param_7)

{
  if (param_6 == 0) {
    ShutUpFriends__12CTalkMonster(param_1);
  }
  *(byte *)(param_1 + 0x47b) = *(byte *)(param_1 + 0x47b) & 0xef;
  *(float *)(param_1 + 0x670) = param_3 + *gpGlobals;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x180))(param_1,param_2,param_3,param_4,param_5);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x684,param_7);
  return;
}


