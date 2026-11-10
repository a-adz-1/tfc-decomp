// AnimateThink__7CSprite  @ 000a33f4
void AnimateThink__7CSprite(int *param_1)

{
  Animate__7CSpritef(param_1,(*gpGlobals - (float)param_1[0x112]) * *(float *)(*param_1 + 0x138));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x112] = (int)*gpGlobals;
  return;
}


