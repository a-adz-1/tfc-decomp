// idprintf__FPUci  @ 000cf528
undefined1 * idprintf__FPUci(int param_1,int param_2)

{
  int local_18;
  char local_14 [15];
  byte local_5;
  
  memset(szReturn_3,0,0x80);
  for (local_18 = 0; local_18 < param_2; local_18 = local_18 + 1) {
    local_5 = *(byte *)(param_1 + local_18);
    sprintf(local_14,"%02x",(uint)local_5);
    strcat(szReturn_3,local_14);
  }
  return szReturn_3;
}


