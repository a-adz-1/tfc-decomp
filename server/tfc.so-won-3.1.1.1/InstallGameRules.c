// InstallGameRules__FPc  @ 00126b30
void InstallGameRules__FPc(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  if (g_pGameRules != 0) {
    __builtin_delete(g_pGameRules);
  }
  iVar1 = (*DAT_0019f86c)();
  if (iVar1 == 0) {
    (*DAT_0019f73c)("exec game.cfg\n");
    (*DAT_0019f740)();
  }
  iVar1 = 0x15;
  bVar5 = true;
  pcVar3 = param_1;
  pcVar4 = "teamfortress classic";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    uVar2 = __builtin_new(0x34);
    __13CTeamFortress(uVar2);
  }
  else {
    (*DAT_0019f794)(4,"Could not find game rules for game \'%s\'! Using Half-Life rules\n",param_1);
    uVar2 = __builtin_new(4);
    __14CHalfLifeRules(uVar2);
  }
  return;
}


