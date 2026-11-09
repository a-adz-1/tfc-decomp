// AnimateThink__7CSprite  @ 000ae200
void AnimateThink__7CSprite(int *param_1)

{
  float *pfVar1;
  
  Animate__7CSpritef(param_1,(*gpGlobals - (float)param_1[0xf3]) * *(float *)(*param_1 + 0x118));
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[0xf3] = (int)*pfVar1;
  return;
}


