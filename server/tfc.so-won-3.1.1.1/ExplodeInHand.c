// ExplodeInHand__15CTFPrimeGrenade  @ 000fee00
void ExplodeInHand__15CTFPrimeGrenade(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_000fee42;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_000fee42:
  (**(code **)(param_1[0x115] + 0xc))(param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*piVar2 + 8);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x28) = DAT_0019f668;
  iVar1 = *param_1;
  UTIL_VecToAngles__FRC6Vector(&uStack_10,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = uStack_10;
  *(undefined4 *)(iVar1 + 0x54) = uStack_c;
  *(undefined4 *)(iVar1 + 0x58) = uStack_8;
  *(int *)(*param_1 + 0x1e4) = param_1[0x1ae];
  param_1[3] = -0x10000;
  param_1[4] = (int)Detonate__8CGrenade;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


