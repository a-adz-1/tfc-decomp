// GoToIntermission__13CTeamFortress  @ 000f9698
void GoToIntermission__13CTeamFortress(int param_1)

{
  undefined4 uVar1;
  longdouble lVar2;
  
  if (g_fGameOver == 0) {
    (*DAT_001c10d8)(2,0x1e,0,0);
    (*DAT_001c10dc)();
    DumpClanScores__Fv();
    clan_scores_dumped = 0x3f800000;
    lVar2 = (longdouble)(*DAT_001c1104)("mp_chattime");
    if ((int)ROUND(lVar2) < 10) {
      (*DAT_001c1110)("mp_chattime",&DAT_0014eb87);
    }
    else if (0x78 < (int)ROUND(lVar2)) {
      uVar1 = UTIL_dtos1__Fi(0x78);
      (*DAT_001c1110)("mp_chattime",uVar1);
    }
    *(float *)(param_1 + 4) = (float)(int)ROUND((float)mp_chattime._12_4_) + *gpGlobals;
    *(float *)(param_1 + 8) = *gpGlobals;
    g_fGameOver = 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


// GoToIntermission__18CHalfLifeMultiplay  @ 000afde4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GoToIntermission__18CHalfLifeMultiplay(int param_1)

{
  if (g_fGameOver == 0) {
    (*DAT_001c10d8)(2,0x1e,0,0);
    (*DAT_001c10dc)();
    *(float *)(param_1 + 4) = _FUN_00146944 + *gpGlobals;
    g_fGameOver = 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


