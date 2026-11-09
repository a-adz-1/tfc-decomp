// AnimateAndDie__7CSpritef  @ 000b0ab0
void AnimateAndDie__7CSpritef(int *param_1,float param_2)

{
  float *pfVar1;
  
  param_1[3] = -0x10000;
  param_1[4] = (int)AnimateUntilDead__7CSprite;
  *(float *)(*param_1 + 0x118) = param_2;
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0x1c4) = (float)param_1[0xf4] / param_2 + *gpGlobals;
  *(float *)(*param_1 + 0xe4) = *pfVar1;
  return;
}


