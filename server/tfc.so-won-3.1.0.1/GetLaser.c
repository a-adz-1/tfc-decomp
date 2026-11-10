// GetLaser__14CFuncTankLaser  @ 000a1e40
int GetLaser__14CFuncTankLaser(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1[0x115] == 0) {
    iVar2 = *(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98);
    iVar4 = 0;
    while( true ) {
      iVar4 = (*DAT_001a7e78)(iVar4,"targetname",iVar2);
      bVar1 = false;
      if ((iVar4 == 0) || (iVar2 = (*DAT_001a7f58)(iVar4), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) goto LAB_000a1f48;
      piVar3 = (int *)(iVar4 + 0x80);
      if (iVar4 == 0) {
        piVar3 = (int *)0x0;
      }
      iVar2 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"env_laser");
      if (iVar2 == 0) break;
      iVar2 = *(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98);
    }
    if ((iVar4 == 0) && (iVar4 = (*DAT_001a7f54)(0), iVar4 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar4 + 0x7c);
    }
    param_1[0x115] = iVar2;
  }
LAB_000a1f48:
  return param_1[0x115];
}


