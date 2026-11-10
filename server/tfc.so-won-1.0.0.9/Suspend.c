// Suspend__10CLaserSpotf  @ 00103130
void Suspend__10CLaserSpotf(int *param_1,float param_2)

{
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  param_1[3] = -0x10000;
  param_1[4] = (int)Revive__10CLaserSpot;
  *(float *)(*param_1 + 0xe4) = param_2 + *gpGlobals;
  return;
}


