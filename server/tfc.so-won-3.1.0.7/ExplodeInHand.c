// ExplodeInHand__15CTFPrimeGrenade  @ 000fc91c
void ExplodeInHand__15CTFPrimeGrenade(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_000fc95e;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_000fc95e:
  (**(code **)(param_1[0x111] + 0xc))(param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*piVar2 + 8);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 0x28) = DAT_001c0fe8;
  iVar1 = *param_1;
  UTIL_VecToAngles__FRC6Vector(&local_c,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = unaff_EDI;
  *(undefined4 *)(iVar1 + 0x54) = local_c;
  *(undefined4 *)(iVar1 + 0x58) = local_8;
  *(int *)(*param_1 + 0x1e4) = param_1[0x1aa];
  param_1[3] = -0x10000;
  param_1[4] = (int)Detonate__8CGrenade;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


