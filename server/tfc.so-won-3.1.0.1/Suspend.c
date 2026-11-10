// Suspend__10CLaserSpotf  @ 000f4b58
void Suspend__10CLaserSpotf(int *param_1,float param_2)

{
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  param_1[3] = -0x10000;
  param_1[4] = (int)Revive__10CLaserSpot;
  *(float *)(*param_1 + 0x104) = param_2 + *gpGlobals;
  return;
}


