// FallInit__15CBasePlayerItem  @ 0011ac00
void FallInit__15CBasePlayerItem(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)FallThink__15CBasePlayerItem;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


