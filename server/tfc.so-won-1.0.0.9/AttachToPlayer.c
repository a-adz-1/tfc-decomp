// AttachToPlayer__15CBasePlayerItemP11CBasePlayer  @ 0011b470
void AttachToPlayer__15CBasePlayerItemP11CBasePlayer(int *param_1,int *param_2)

{
  *(undefined4 *)(*param_1 + 0xe8) = 0xc;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0x174) = *(undefined4 *)(*param_2 + 0x1e8);
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  *(undefined4 *)(*param_1 + 0x94) = 0;
  *(undefined4 *)(*param_1 + 0x98) = 0;
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(*param_2 + 0x1e8);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}


