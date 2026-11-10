// ButtonSpark__11CBaseButton  @ 0008bd90
void ButtonSpark__11CBaseButton(int *param_1)

{
  longdouble lVar1;
  
  param_1[3] = -0x10000;
  param_1[4] = (int)ButtonSpark__11CBaseButton;
  lVar1 = (longdouble)(*DAT_001c118c)(0,0x3fc00000);
  *(float *)(*param_1 + 0x104) = (float)((longdouble)0.1 + lVar1 + (longdouble)*gpGlobals);
  DoSpark__FP9entvars_sRC6Vector(*param_1,*param_1 + 0xdc);
  return;
}


