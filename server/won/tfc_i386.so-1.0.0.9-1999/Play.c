// Play__14CTargetCDAudio  @ 00110360
void Play__14CTargetCDAudio(int *param_1)

{
  PlayCDTrack__Fi((int)ROUND(*(float *)(*param_1 + 0x140)));
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


