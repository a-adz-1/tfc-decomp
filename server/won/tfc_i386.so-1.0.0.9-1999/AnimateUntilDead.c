// AnimateUntilDead__7CSprite  @ 000ae260
void AnimateUntilDead__7CSprite(int *param_1)

{
  if (*gpGlobals <= *(float *)(*param_1 + 0x1c4)) {
    AnimateThink__7CSprite(param_1);
    *(float *)(*param_1 + 0xe4) = *gpGlobals;
  }
  else {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


