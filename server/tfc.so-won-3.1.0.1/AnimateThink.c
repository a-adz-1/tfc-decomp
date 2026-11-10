// AnimateThink__7CSprite  @ 00098e74
void AnimateThink__7CSprite(int *param_1)

{
  Animate__7CSpritef(param_1,(*gpGlobals - (float)param_1[0xf6]) * *(float *)(*param_1 + 0x138));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0xf6] = (int)*gpGlobals;
  return;
}


