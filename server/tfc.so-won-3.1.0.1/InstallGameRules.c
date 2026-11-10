// InstallGameRules__FPc  @ 00112af4
undefined4 * InstallGameRules__FPc(char *param_1)

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
  iVar1 = (*DAT_001a800c)();
  if (iVar1 == 0) {
    (*DAT_001a7edc)("exec game.cfg\n");
    (*DAT_001a7ee0)();
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
    puVar3 = (undefined4 *)__14CHalfLifeRules(uVar2);
  }
  else {
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
      puVar3 = (undefined4 *)__18CHalfLifeMultiplay(uVar2);
    }
    else {
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
        puVar3 = (undefined4 *)__17CHalfLifeTeamplay(uVar2);
      }
      else {
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
        }
        else {
          (*DAT_001a7f34)(4,"Could not find game rules for game \'%s\'! Using Half-Life rules\n",
                          param_1);
          uVar2 = __builtin_new(4);
          puVar3 = (undefined4 *)__14CHalfLifeRules(uVar2);
        }
      }
    }
  }
  return puVar3;
}


