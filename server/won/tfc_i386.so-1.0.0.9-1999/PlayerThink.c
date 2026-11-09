// PlayerThink__14CHalfLifeRulesP11CBasePlayer  @ 000b7020
void PlayerThink__14CHalfLifeRulesP11CBasePlayer(void)

{
  return;
}


// PlayerThink__18CHalfLifeMultiplayP11CBasePlayer  @ 000b7b60
void PlayerThink__18CHalfLifeMultiplayP11CBasePlayer(int param_1,int *param_2)

{
  if (g_fGameOver != 0) {
    if ((param_2[0x18d] & 0x827U) != 0) {
      *(undefined4 *)(param_1 + 8) = 1;
    }
    param_2[0x18d] = 0;
    *(undefined4 *)(*param_2 + 0x160) = 0;
    param_2[0x18e] = 0;
  }
  return;
}


