// ChangeLevel__18CHalfLifeMultiplay  @ 000a56c4
void ChangeLevel__18CHalfLifeMultiplay(void)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_c00;
  int local_bfc;
  char local_bf8 [1500];
  char local_61c [1500];
  undefined4 local_40;
  undefined2 local_3c;
  char local_20 [32];
  
  local_bfc = 0;
  local_c00 = 0;
  local_40 = 0x6d646c68;
  local_3c = 0x31;
  bVar4 = true;
  pcVar5 = (char *)(*DAT_001a7f28)("mapcyclefile");
  local_61c[0] = '\0';
  local_bf8[0] = '\0';
  iVar6 = CountPlayers__Fv();
  iVar7 = strcasecmp(pcVar5,szPreviousMapCycleFile_838);
  if (iVar7 != 0) {
    strcpy(szPreviousMapCycleFile_838,pcVar5);
    DestroyMapCycle__FP10mapcycle_s(&mapcycle_839);
    iVar7 = ReloadMapCycleFile__FPcP10mapcycle_s(pcVar5,&mapcycle_839);
    if ((iVar7 == 0) || (mapcycle_839 == 0)) {
      (*DAT_001a7f34)(1,"Unable to load map cycle file %s\n",pcVar5);
      bVar4 = false;
    }
  }
  if ((bVar4) && (mapcycle_839 != 0)) {
    bVar4 = false;
    strcpy(local_20,(char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)));
    strcpy((char *)&local_40,(char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)));
    puVar2 = (undefined4 *)*DAT_001a7704;
    puVar8 = DAT_001a7704;
    while (puVar2 != DAT_001a7704) {
      bVar3 = false;
      if (puVar8[9] != 0) {
        if (iVar6 < (int)puVar8[9]) {
          bVar3 = true;
        }
        else {
          bVar4 = true;
          local_bfc = puVar8[9];
        }
      }
      if (puVar8[10] != 0) {
        if ((int)puVar8[10] < iVar6) {
          bVar3 = true;
        }
        else {
          bVar4 = true;
          local_c00 = puVar8[10];
        }
      }
      if (!bVar3) goto LAB_000a585f;
      puVar8 = (undefined4 *)*puVar8;
      puVar2 = (undefined4 *)*puVar8;
    }
    if (!bVar4) {
      puVar8 = DAT_001a7704;
    }
LAB_000a585f:
    DAT_001a7704 = (undefined4 *)*puVar8;
    strcpy(local_20,(char *)(puVar8 + 1));
    ExtractCommandString__FPcT0(puVar8 + 0xb,local_61c);
    strcpy(local_bf8,(char *)(puVar8 + 0xb));
  }
  iVar7 = (*DAT_001a7ff8)(local_20);
  if (iVar7 == 0) {
    strcpy(local_20,(char *)&local_40);
  }
  g_fGameOver = 1;
  (*DAT_001a7f34)(1,"CHANGE LEVEL: %s\n",local_20);
  if ((local_bfc != 0) || (local_c00 != 0)) {
    (*DAT_001a7f34)(1,"PLAYER COUNT:  min %i max %i current %i\n",local_bfc,local_c00,iVar6);
  }
  iVar6 = -1;
  pcVar5 = local_bf8;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (iVar6 != -2) {
    (*DAT_001a7f34)(1,"RULES:  %s\n",local_bf8);
  }
  (*pcRam001a7e58)(local_20,0);
  iVar6 = -1;
  pcVar5 = local_61c;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (iVar6 != -2) {
    (*DAT_001a7edc)(local_61c);
  }
  return;
}


