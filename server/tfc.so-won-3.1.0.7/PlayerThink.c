// PlayerThink__14CHalfLifeRulesP11CBasePlayer  @ 000ae480
void PlayerThink__14CHalfLifeRulesP11CBasePlayer(void)

{
  return;
}


// PlayerThink__18CHalfLifeMultiplayP11CBasePlayer  @ 000af244
void PlayerThink__18CHalfLifeMultiplayP11CBasePlayer(int param_1,int *param_2)

{
  if (g_fGameOver != 0) {
    if ((param_2[0x1ad] & 0x827U) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 1;
    }
    param_2[0x1ad] = 0;
    *(undefined4 *)(*param_2 + 0x180) = 0;
    param_2[0x1ae] = 0;
  }
  return;
}


