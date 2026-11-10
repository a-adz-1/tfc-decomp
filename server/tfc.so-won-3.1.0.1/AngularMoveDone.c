// AngularMoveDone__11CBaseToggle  @ 000e787c
void AngularMoveDone__11CBaseToggle(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x119];
  *(int *)(iVar1 + 0x54) = param_1[0x11a];
  *(int *)(iVar1 + 0x58) = param_1[0x11b];
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
  *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
  if (*(short *)((int)param_1 + 0x452) != 0) {
    if (*(short *)((int)param_1 + 0x452) < 1) {
      pcVar2 = (code *)param_1[0x115];
    }
    else {
      pcVar2 = *(code **)(*(int *)((int)(short)param_1[0x115] + (int)param_1) + -4 +
                         *(short *)((int)param_1 + 0x452) * 4);
    }
    (*pcVar2)((int)(short)param_1[0x114] + (int)param_1);
  }
  return;
}


