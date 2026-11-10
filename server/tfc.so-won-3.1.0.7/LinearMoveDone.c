// LinearMoveDone__11CBaseToggle  @ 000f42dc
void LinearMoveDone__11CBaseToggle(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_1 + 0x132);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 0x28) = DAT_001c0fe8;
  *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
  if (*(short *)((int)param_1 + 0x4c2) != 0) {
    if (*(short *)((int)param_1 + 0x4c2) < 1) {
      pcVar2 = (code *)param_1[0x131];
    }
    else {
      pcVar2 = *(code **)(*(int *)((int)(short)param_1[0x131] + (int)param_1) + -4 +
                         *(short *)((int)param_1 + 0x4c2) * 4);
    }
    (*pcVar2)((int)(short)param_1[0x130] + (int)param_1);
  }
  return;
}


