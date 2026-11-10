// DeadEnd__15CFuncTrackTrain  @ 000d39b0
void DeadEnd__15CFuncTrackTrain(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = (int *)param_1[0xf3];
  (*DAT_001755b4)(2,"TRAIN(%s): Dead end ",*(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98));
  if (piVar4 != (int *)0x0) {
    piVar3 = piVar4;
    if (0.0 <= (float)param_1[0x103]) {
      do {
        piVar4 = piVar3;
        uVar2 = GetNext__10CPathTrack(piVar4,1);
        piVar3 = (int *)ValidPath__10CPathTrackP10CPathTracki(piVar4,uVar2);
      } while (piVar3 != (int *)0x0);
    }
    else {
      do {
        piVar4 = piVar3;
        uVar2 = GetPrevious__10CPathTrack(piVar4,1);
        piVar3 = (int *)ValidPath__10CPathTrackP10CPathTracki(piVar4,uVar2);
      } while (piVar3 != (int *)0x0);
    }
  }
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  if (piVar4 == (int *)0x0) {
    (*DAT_001755b4)(2,&DAT_001382c0);
  }
  else {
    (*DAT_001755b4)(2,"at %s\n",*(int *)(*piVar4 + 0x1ac) + *(int *)(gpGlobals + 0x98));
    if (*(int *)(*piVar4 + 0x1b0) != 0) {
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                (*(int *)(*piVar4 + 0x1b0) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
    }
  }
  return;
}


