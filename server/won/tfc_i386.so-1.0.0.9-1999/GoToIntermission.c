// GoToIntermission__13CTeamFortress  @ 000f5340
void GoToIntermission__13CTeamFortress(int param_1)

{
  if (g_fGameOver == 0) {
    (*DAT_00175578)(2,0x1e,0,0);
    (*DAT_0017557c)();
    DumpClanScores__Fv();
    clan_scores_dumped = 0x3f800000;
    *(float *)(param_1 + 4) = *gpGlobals + 6.0;
    g_fGameOver = 1;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


// GoToIntermission__18CHalfLifeMultiplay  @ 000b8520
void GoToIntermission__18CHalfLifeMultiplay(int param_1)

{
  if (g_fGameOver == 0) {
    (*DAT_00175578)(2,0x1e,0,0);
    (*DAT_0017557c)();
    *(float *)(param_1 + 4) = *gpGlobals + 6.0;
    g_fGameOver = 1;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


