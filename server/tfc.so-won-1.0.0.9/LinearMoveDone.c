// LinearMoveDone__11CBaseToggle  @ 000f0ce0
void LinearMoveDone__11CBaseToggle(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,param_1 + 0x113);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
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


