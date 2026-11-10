// NextLevel__Fv  @ 00113bbc
void NextLevel__Fv(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int *piVar5;
  
  iVar2 = (*DAT_001c1058)(0,"classname","trigger_changelevel");
  bVar1 = false;
  if (iVar2 != 0) {
    iVar3 = (*DAT_001c1138)(iVar2);
    if (iVar3 != 0) goto LAB_00113c0f;
  }
  bVar1 = true;
LAB_00113c0f:
  if (bVar1) {
    fVar4 = (float)(*DAT_001c112c)("start");
    gpGlobals[3] = fVar4;
    piVar5 = (int *)GetClassPtr__H1Z12CChangeLevel_PX01_PX01(0);
    piVar5[0x13a] = 0x72617473;
    *(undefined2 *)(piVar5 + 0x13b) = 0x74;
  }
  else {
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    piVar5 = (int *)GetClassPtr__H1Z12CChangeLevel_PX01_PX01(iVar3);
  }
  strcpy(st_szNextMap,(char *)(piVar5 + 0x13a));
  g_fGameOver = 1;
  if (*(float *)(*piVar5 + 0x104) < *gpGlobals) {
    piVar5[3] = -0x10000;
    piVar5[4] = (int)ExecuteChangeLevel__12CChangeLevel;
    *(float *)(*piVar5 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


