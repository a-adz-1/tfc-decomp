// DeadEnd__15CFuncTrackTrain  @ 000cf778
void DeadEnd__15CFuncTrackTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)param_1[0x116];
  (*DAT_0019f794)(2,"TRAIN(%s): Dead end ",*(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98));
  if (piVar5 != (int *)0x0) {
    fVar1 = (float)param_1[0x126];
    piVar4 = piVar5;
    if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
      do {
        piVar5 = piVar4;
        uVar3 = GetNext__10CPathTrack(piVar5,1);
        piVar4 = (int *)ValidPath__10CPathTrackP10CPathTracki(piVar5,uVar3);
      } while (piVar4 != (int *)0x0);
    }
    else {
      do {
        piVar5 = piVar4;
        uVar3 = GetPrevious__10CPathTrack(piVar5,1);
        piVar4 = (int *)ValidPath__10CPathTrackP10CPathTracki(piVar5,uVar3);
      } while (piVar4 != (int *)0x0);
    }
  }
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x24) = DAT_0019f664;
  *(undefined4 *)(iVar2 + 0x28) = DAT_0019f668;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar2 + 100) = DAT_0019f668;
  if (piVar5 == (int *)0x0) {
    (*DAT_0019f794)(2,&DAT_0014f874);
  }
  else {
    (*DAT_0019f794)(2,"at %s\n",*(int *)(*piVar5 + 0x1cc) + *(int *)(gpGlobals + 0x98));
    if (*(int *)(*piVar5 + 0x1d0) != 0) {
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                (*(int *)(*piVar5 + 0x1d0) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
    }
  }
  return;
}


