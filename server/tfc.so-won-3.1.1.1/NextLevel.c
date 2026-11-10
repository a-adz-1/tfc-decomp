// NextLevel__Fv  @ 00116364
void NextLevel__Fv(void)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  
  iVar3 = (*DAT_0019f6d8)(0,"classname","trigger_changelevel");
  bVar2 = false;
  if (iVar3 != 0) {
    iVar4 = (*DAT_0019f7b8)(iVar3);
    if (iVar4 != 0) goto LAB_001163ba;
  }
  bVar2 = true;
LAB_001163ba:
  if (bVar2) {
    fVar5 = (float)(*DAT_0019f7ac)("start");
    gpGlobals[3] = fVar5;
    piVar6 = (int *)GetClassPtr__H1Z12CChangeLevel_PX01_PX01(0);
    piVar6[0x13e] = 0x72617473;
    *(undefined2 *)(piVar6 + 0x13f) = 0x74;
  }
  else {
    iVar4 = iVar3 + 0x80;
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    piVar6 = (int *)GetClassPtr__H1Z12CChangeLevel_PX01_PX01(iVar4);
  }
  strcpy(st_szNextMap,(char *)(piVar6 + 0x13e));
  g_fGameOver = 1;
  fVar5 = *gpGlobals;
  fVar1 = *(float *)(*piVar6 + 0x104);
  if (0x3f < (byte)((fVar5 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar5) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar5 == fVar1) << 0xe) >> 8)) - 1)) {
    piVar6[3] = -0x10000;
    piVar6[4] = (int)ExecuteChangeLevel__12CChangeLevel;
    *(float *)(*piVar6 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


