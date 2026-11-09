// NextLevel__Fv  @ 00111a40
void NextLevel__Fv(void)

{
  float fVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  int *piVar7;
  
  iVar4 = (*DAT_001754f8)(0,"classname","trigger_changelevel");
  bVar2 = false;
  if (iVar4 != 0) {
    iVar5 = (*DAT_001755d8)(iVar4);
    if (iVar5 != 0) goto LAB_00111a7a;
  }
  bVar2 = true;
LAB_00111a7a:
  if (bVar2) {
    fVar6 = (float)(*DAT_001755cc)("start");
    gpGlobals[3] = fVar6;
    piVar7 = (int *)GetClassPtr__H1Z12CChangeLevel_PX01_PX01(0);
    piVar7[0x11b] = 0x72617473;
    *(undefined2 *)(piVar7 + 0x11c) = 0x74;
  }
  else {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = iVar4 + 0xdc;
    }
    piVar7 = (int *)GetClassPtr__H1Z12CChangeLevel_PX01_PX01(iVar4);
  }
  strcpy(st_szNextMap,(char *)(piVar7 + 0x11b));
  pfVar3 = gpGlobals;
  g_fGameOver = 1;
  fVar6 = *(float *)(*piVar7 + 0xe4);
  fVar1 = *gpGlobals;
  if ((byte)(fVar6 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar6) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar6 == fVar1) << 0xe) >> 8)) == 1) {
    piVar7[3] = -0x10000;
    piVar7[4] = (int)ExecuteChangeLevel__12CChangeLevel;
    *(float *)(*piVar7 + 0xe4) = *pfVar3 + 0.1;
  }
  return;
}


