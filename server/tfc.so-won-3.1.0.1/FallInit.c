// FallInit__15CBasePlayerItem  @ 0010fe64
void FallInit__15CBasePlayerItem(int *param_1)

{
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  local_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_18,&local_c);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)FallThink__15CBasePlayerItem;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


