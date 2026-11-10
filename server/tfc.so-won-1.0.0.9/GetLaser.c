// GetLaser__14CFuncTankLaser  @ 000b5cd0
int GetLaser__14CFuncTankLaser(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1[0x112] == 0) {
    iVar2 = *(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98);
    iVar4 = 0;
    do {
      iVar4 = (*DAT_001754f8)(iVar4,"targetname",iVar2);
      bVar1 = false;
      if (iVar4 == 0) {
LAB_000b5d24:
        bVar1 = true;
      }
      else {
        iVar2 = (*DAT_001755d8)(iVar4);
        if (iVar2 == 0) goto LAB_000b5d24;
      }
      if (bVar1) break;
      if (iVar4 == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(iVar4 + 0xdc);
      }
      iVar2 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"env_laser");
      if (iVar2 == 0) goto code_r0x000b5d66;
      iVar2 = *(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98);
    } while( true );
  }
  goto LAB_000b5dc0;
code_r0x000b5d66:
  if (iVar4 == 0) {
    iVar4 = (*DAT_001755d4)(0);
    if (iVar4 != 0) goto LAB_000b5d79;
    iVar2 = 0;
  }
  else {
LAB_000b5d79:
    iVar2 = *(int *)(iVar4 + 0xd8);
  }
  param_1[0x112] = iVar2;
LAB_000b5dc0:
  return param_1[0x112];
}


