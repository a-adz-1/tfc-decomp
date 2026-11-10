// AttachToPlayer__15CBasePlayerItemP11CBasePlayer  @ 00125b60
void AttachToPlayer__15CBasePlayerItemP11CBasePlayer(int *param_1,int *param_2)

{
  *(undefined4 *)(*param_1 + 0x108) = 0xc;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x194) = *(undefined4 *)(*param_2 + 0x208);
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  *(undefined4 *)(*param_1 + 0xb4) = 0;
  *(undefined4 *)(*param_1 + 0xb8) = 0;
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}


