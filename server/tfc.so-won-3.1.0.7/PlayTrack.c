// PlayTrack__15CTriggerCDAudio  @ 00111d94
void PlayTrack__15CTriggerCDAudio(int *param_1)

{
  PlayCDTrack__Fi((int)ROUND(*(float *)(*param_1 + 0x160)));
  param_1[5] = 0;
  param_1[6] = 0;
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


