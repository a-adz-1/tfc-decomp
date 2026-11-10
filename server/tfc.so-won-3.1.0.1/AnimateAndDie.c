// AnimateAndDie__7CSpritef  @ 0009bb6c
void AnimateAndDie__7CSpritef(int *param_1,float param_2)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)AnimateUntilDead__7CSprite;
  *(float *)(*param_1 + 0x138) = param_2;
  *(float *)(*param_1 + 0x1e4) = (float)param_1[0xf7] / param_2 + *gpGlobals;
  *(float *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


