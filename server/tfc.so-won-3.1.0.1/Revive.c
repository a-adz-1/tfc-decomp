// Revive__10CLaserSpot  @ 000f4ba0
void Revive__10CLaserSpot(int *param_1)

{
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


