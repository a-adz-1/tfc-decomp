// FindTransition__14CBaseAnimatingiiPi  @ 000c5c20
undefined4
FindTransition__14CBaseAnimatingiiPi(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int local_8;
  
  uVar1 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  if (param_4 == 0) {
    uVar1 = FindTransition__FPviiPi(uVar1,param_2,param_3,&local_8);
    if (local_8 != 1) {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = FindTransition__FPviiPi(uVar1,param_2,param_3,param_4);
  }
  return uVar1;
}


// FindTransition__FPviiPi  @ 0009b380
int FindTransition__FPviiPi(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (((param_1 != 0) &&
      (iVar5 = param_1 + *(int *)(param_1 + 0xa8), *(int *)(iVar5 + 0xa0 + param_2 * 0xb0) != 0)) &&
     (*(int *)(iVar5 + 0xa0 + param_3 * 0xb0) != 0)) {
    if (*param_4 < 1) {
      iVar1 = *(int *)(iVar5 + 0xa0 + param_2 * 0xb0);
    }
    else {
      iVar1 = *(int *)(iVar5 + 0xa4 + param_2 * 0xb0);
    }
    if (iVar1 == *(int *)(iVar5 + 0xa0 + param_3 * 0xb0)) {
      *param_4 = 1;
    }
    else {
      uVar3 = (uint)*(byte *)(param_1 + *(int *)(param_1 + 0xf0) + -1 +
                             (iVar1 + -1) * *(int *)(param_1 + 0xec) +
                             *(int *)(iVar5 + 0xa0 + param_3 * 0xb0));
      if (uVar3 != 0) {
        for (iVar4 = 0; iVar4 < *(int *)(param_1 + 0xa4); iVar4 = iVar4 + 1) {
          if ((*(int *)(iVar5 + 0xa0 + iVar4 * 0xb0) == iVar1) &&
             (*(uint *)(iVar5 + 0xa4 + iVar4 * 0xb0) == uVar3)) {
            *param_4 = 1;
            return iVar4;
          }
          iVar2 = iVar4 * 0xb0;
          if (((*(int *)(iVar5 + 0xa8 + iVar2) != 0) && (*(int *)(iVar5 + 0xa4 + iVar2) == iVar1))
             && (*(uint *)(iVar5 + 0xa0 + iVar2) == uVar3)) {
            *param_4 = -1;
            return iVar4;
          }
        }
        (*DAT_001755b4)(1,"error in transition graph");
      }
    }
  }
  return param_3;
}


