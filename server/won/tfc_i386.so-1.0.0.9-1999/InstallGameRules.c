// InstallGameRules__FPc  @ 0011d200
void InstallGameRules__FPc(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  if (g_pGameRules != 0) {
    __builtin_delete(g_pGameRules);
  }
  iVar1 = (*DAT_0017568c)();
  if (iVar1 == 0) {
    (*DAT_0017555c)("exec game.cfg\n");
    (*DAT_00175560)();
  }
  iVar1 = 10;
  bVar6 = true;
  pcVar4 = param_1;
  pcVar5 = "half-life";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    uVar2 = __builtin_new(4);
    __14CHalfLifeRules(uVar2);
    FUN_0011d3e0();
    return;
  }
  iVar1 = 0x14;
  bVar6 = true;
  pcVar4 = param_1;
  pcVar5 = "half-life multiplay";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    uVar2 = __builtin_new(0xc);
    __18CHalfLifeMultiplay(uVar2);
    FUN_0011d3e0();
    return;
  }
  iVar1 = 0x13;
  bVar6 = true;
  pcVar4 = param_1;
  pcVar5 = "half-life teamplay";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    uVar2 = __builtin_new(0x14);
    __17CHalfLifeTeamplay(uVar2);
    FUN_0011d3e0();
    return;
  }
  iVar1 = 0x15;
  bVar6 = true;
  pcVar4 = param_1;
  pcVar5 = "teamfortress classic";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    puVar3 = (undefined4 *)__builtin_new(0x14);
    __17CHalfLifeTeamplay(puVar3);
    *puVar3 = __vt_13CTeamFortress;
    FUN_0011d3e0();
    return;
  }
  (*DAT_001755b4)(4,"Could not find game rules for game \'%s\'! Using Half-Life rules\n",param_1);
  uVar2 = __builtin_new(4);
  __14CHalfLifeRules(uVar2);
  FUN_0011d3e0();
  return;
}


