// Talk__12CTalkMonsterf  @ 000f2a90
void Talk__12CTalkMonsterf(int param_1,float param_2)

{
  if (param_2 <= 0.0) {
    param_2 = 3.0;
  }
  *(float *)(param_1 + 0x674) = param_2 + *gpGlobals;
  return;
}


