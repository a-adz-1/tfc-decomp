// Ghidra decompilation of functions from tfc/game.cpp
// 2 functions, ordered by original source line

// GameDLLInit  @ 000d7b30  (line 80)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GameDLLInit(void)

{
  g_footsteps = (*g_engfuncs.pfnCVarGetPointer)("mp_footsteps");
  (*g_engfuncs.pfnCVarRegister)(&tfc_spam_penalty1);
  (*g_engfuncs.pfnCVarRegister)(&tfc_spam_penalty2);
  (*g_engfuncs.pfnCVarRegister)(&tfc_spam_limit);
  (*g_engfuncs.pfnCVarRegister)(&tfc_autoteam);
  (*g_engfuncs.pfnCVarRegister)(&tfc_birthday);
  (*g_engfuncs.pfnCVarRegister)(&tfc_fragscoring);
  (*g_engfuncs.pfnCVarRegister)(&tfc_respawndelay);
  (*g_engfuncs.pfnCVarRegister)(&tfc_clanbattle);
  (*g_engfuncs.pfnCVarRegister)(&tfc_clanbattle_prematch);
  (*g_engfuncs.pfnCVarRegister)(&tfc_prematch);
  (*g_engfuncs.pfnCVarRegister)(&tfc_clanbattle_ceasefire);
  (*g_engfuncs.pfnCVarRegister)(&tfc_clanbattle_locked);
  (*g_engfuncs.pfnCVarRegister)(&tfc_adminpwd);
  (*g_engfuncs.pfnCVarRegister)(&tfc_balance_teams);
  (*g_engfuncs.pfnCVarRegister)(&tfc_balance_scores);
  (*g_engfuncs.pfnCVarRegister)(&tfc_autokick_time);
  (*g_engfuncs.pfnCVarRegister)(&tfc_autokick_kills);
  (*g_engfuncs.pfnCVarRegister)(&allow_spectators);
  (*g_engfuncs.pfnCVarRegister)(&tfc_spectchat);
  (*g_engfuncs.pfnCVarRegister)(&tfc_playerid);
  (*g_engfuncs.pfnCVarRegister)(&displaysoundlist);
  (*g_engfuncs.pfnCVarRegister)(&teamplay);
  (*g_engfuncs.pfnCVarRegister)(&fraglimit);
  (*g_engfuncs.pfnCVarRegister)(&timelimit);
  (*g_engfuncs.pfnCVarRegister)(&fragsleft);
  (*g_engfuncs.pfnCVarRegister)(&timeleft);
  (*g_engfuncs.pfnCVarRegister)(&friendlyfire);
  (*g_engfuncs.pfnCVarRegister)(&falldamage);
  (*g_engfuncs.pfnCVarRegister)(&weaponstay);
  (*g_engfuncs.pfnCVarRegister)(&forcerespawn);
  (*g_engfuncs.pfnCVarRegister)(&flashlight);
  (*g_engfuncs.pfnCVarRegister)(&aimcrosshair);
  (*g_engfuncs.pfnCVarRegister)(&decalfrequency);
  (*g_engfuncs.pfnCVarRegister)(&cr_scout);
  (*g_engfuncs.pfnCVarRegister)(&cr_sniper);
  (*g_engfuncs.pfnCVarRegister)(&cr_soldier);
  (*g_engfuncs.pfnCVarRegister)(&cr_demoman);
  (*g_engfuncs.pfnCVarRegister)(&cr_medic);
  (*g_engfuncs.pfnCVarRegister)(&cr_hwguy);
  (*g_engfuncs.pfnCVarRegister)(&cr_pyro);
  (*g_engfuncs.pfnCVarRegister)(&cr_spy);
  (*g_engfuncs.pfnCVarRegister)(&cr_engineer);
  (*g_engfuncs.pfnCVarRegister)(&cr_random);
  (*g_engfuncs.pfnCVarRegister)(&mp_chattime);
  return;
}


// GameDLLShutdown  @ 000d7d90  (line 156)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GameDLLShutdown(void)

{
  return;
}


