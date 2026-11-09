// ExplodeInHand__15CTFPrimeGrenade  @ 000fc650
void ExplodeInHand__15CTFPrimeGrenade(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(*param_1 + 0x178);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_000fc682;
    }
  }
  piVar2 = *(int **)(iVar1 + 0xd8);
LAB_000fc682:
  (**(code **)(param_1[0xf2] + 8))(param_1);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*piVar2 + 8);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
  iVar1 = *param_1;
  UTIL_VecToAngles__FRC6Vector(&local_10,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = local_10;
  *(undefined4 *)(iVar1 + 0x54) = local_c;
  *(undefined4 *)(iVar1 + 0x58) = local_8;
  *(int *)(*param_1 + 0x1c4) = param_1[0x189];
  param_1[3] = -0x10000;
  param_1[4] = (int)Detonate__8CGrenade;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


