// Expand__7CSpriteff  @ 000ae2b0
void Expand__7CSpriteff(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  *(undefined4 *)(*param_1 + 0x1d8) = param_2;
  *(undefined4 *)(*param_1 + 0x140) = param_3;
  param_1[3] = -0x10000;
  param_1[4] = (int)ExpandThink__7CSprite;
  piVar1 = gpGlobals;
  *(int *)(*param_1 + 0xe4) = *gpGlobals;
  param_1[0xf3] = *piVar1;
  return;
}


