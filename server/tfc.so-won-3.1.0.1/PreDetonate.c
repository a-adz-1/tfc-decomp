// PreDetonate__8CGrenade  @ 000a6be0
void PreDetonate__8CGrenade(int *param_1)

{
  InsertSound__9CSoundEntiRC6Vectorif(0x20,*param_1 + 8,400,0x3e99999a);
  param_1[3] = -0x10000;
  param_1[4] = (int)Detonate__8CGrenade;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  return;
}


