// AngularMoveDone__11CBaseToggle  @ 000f6424
void AngularMoveDone__11CBaseToggle(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x139];
  *(int *)(iVar1 + 0x54) = param_1[0x13a];
  *(int *)(iVar1 + 0x58) = param_1[0x13b];
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
  if (*(short *)((int)param_1 + 0x4d2) != 0) {
    if (*(short *)((int)param_1 + 0x4d2) < 1) {
      pcVar2 = (code *)param_1[0x135];
    }
    else {
      pcVar2 = *(code **)(*(int *)((int)(short)param_1[0x135] + (int)param_1) + -4 +
                         *(short *)((int)param_1 + 0x4d2) * 4);
    }
    (*pcVar2)((int)(short)param_1[0x134] + (int)param_1);
  }
  return;
}


