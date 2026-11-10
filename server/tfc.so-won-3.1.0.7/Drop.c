// Drop__15CBasePlayerItem  @ 001201a0
void Drop__15CBasePlayerItem(int *param_1)

{
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


