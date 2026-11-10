// UpdateStatsFile__FfPcffi  @ 000e6004
void UpdateStatsFile__FfPcffi
               (float param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5)

{
  FILE *__stream;
  
  __stream = fopen("stats.txt","a");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%6.2f, %6.2f, %6.2f, %s, %2d\n",(double)param_1,(double)param_3,
            (double)param_4,param_2,param_5);
    fclose(__stream);
  }
  return;
}


