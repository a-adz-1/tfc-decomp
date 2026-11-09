// Revive__10CLaserSpot  @ 00103170
void Revive__10CLaserSpot(int *param_1)

{
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


