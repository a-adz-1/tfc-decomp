// ButtonSpark__11CBaseButton  @ 0009e8b0
void ButtonSpark__11CBaseButton(int *param_1)

{
  longdouble lVar1;
  
  param_1[3] = -0x10000;
  param_1[4] = (int)ButtonSpark__11CBaseButton;
  lVar1 = (longdouble)(*DAT_0017562c)(0,0x3fc00000);
  *(float *)(*param_1 + 0xe4) = (float)((longdouble)0.1 + lVar1 + (longdouble)*gpGlobals);
  DoSpark__FP9entvars_tRC6Vector(*param_1,*param_1 + 0xbc);
  return;
}


