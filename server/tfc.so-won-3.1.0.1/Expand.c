// Expand__7CSpriteff  @ 00098f40
void Expand__7CSpriteff(int *param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(*param_1 + 0x1f8) = param_2;
  *(undefined4 *)(*param_1 + 0x160) = param_3;
  param_1[3] = -0x10000;
  param_1[4] = (int)ExpandThink__7CSprite;
  *(int *)(*param_1 + 0x104) = *gpGlobals;
  param_1[0xf6] = *gpGlobals;
  return;
}


