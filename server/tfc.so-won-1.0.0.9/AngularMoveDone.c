// AngularMoveDone__11CBaseToggle  @ 000f0ed0
void AngularMoveDone__11CBaseToggle(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x116];
  *(int *)(iVar1 + 0x54) = param_1[0x117];
  *(int *)(iVar1 + 0x58) = param_1[0x118];
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0xe4) = 0xbf800000;
  if (*(short *)((int)param_1 + 0x446) != 0) {
    if (*(short *)((int)param_1 + 0x446) < 1) {
      pcVar2 = (code *)param_1[0x112];
    }
    else {
      pcVar2 = *(code **)(*(int *)((int)(short)param_1[0x112] + (int)param_1) + -4 +
                         *(short *)((int)param_1 + 0x446) * 4);
    }
    (*pcVar2)((int)(short)param_1[0x111] + (int)param_1);
  }
  return;
}


