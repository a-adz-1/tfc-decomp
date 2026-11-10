// Play__14CTargetCDAudio  @ 00102908
void Play__14CTargetCDAudio(int *param_1)

{
  PlayCDTrack__Fi((int)ROUND(*(float *)(*param_1 + 0x160)));
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


