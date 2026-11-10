// GetLaser__14CFuncTankLaser  @ 000ac868
int GetLaser__14CFuncTankLaser(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1[0x131] == 0) {
    iVar2 = *(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98);
    iVar4 = 0;
    while( true ) {
      iVar4 = (*DAT_001c1058)(iVar4,"targetname",iVar2);
      bVar1 = false;
      if ((iVar4 == 0) || (iVar2 = (*DAT_001c1138)(iVar4), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) goto LAB_000ac970;
      piVar3 = (int *)(iVar4 + 0x80);
      if (iVar4 == 0) {
        piVar3 = (int *)0x0;
      }
      iVar2 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"env_laser");
      if (iVar2 == 0) break;
      iVar2 = *(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98);
    }
    if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar4 + 0x7c);
    }
    param_1[0x131] = iVar2;
  }
LAB_000ac970:
  return param_1[0x131];
}


