// SetAnswerQuestion__12CTalkMonsterP12CTalkMonster  @ 000f8aa8
void SetAnswerQuestion__12CTalkMonsterP12CTalkMonster(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x698) == 0) {
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,slIdleResponse);
  }
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x704,param_2);
  return;
}


