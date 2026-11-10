// FindTransition__14CBaseAnimatingiiPi  @ 000c1c30
undefined4
FindTransition__14CBaseAnimatingiiPi(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int local_8;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
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


// FindTransition__FPviiPi  @ 000877d8
int FindTransition__FPviiPi(int param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_10;
  
  if (param_1 != 0) {
    iVar4 = param_1 + *(int *)(param_1 + 0xa8);
    uVar5 = *(uint *)(iVar4 + 0xa0 + param_2 * 0xb0);
    if ((uVar5 != 0) && (uVar3 = *(uint *)(iVar4 + 0xa0 + param_3 * 0xb0), uVar3 != 0)) {
      if (0 < *param_4) {
        uVar5 = *(uint *)(iVar4 + 0xa4 + param_2 * 0xb0);
      }
      if (uVar5 == uVar3) {
        *param_4 = 1;
      }
      else {
        uVar3 = (uint)*(byte *)(param_1 + *(int *)(param_1 + 0xf0) + -1 +
                               (uVar5 - 1) * *(int *)(param_1 + 0xec) + uVar3);
        if (uVar3 != 0) {
          local_10 = 0;
          if (0 < *(int *)(param_1 + 0xa4)) {
            do {
              iVar2 = local_10 * 0xb0;
              uVar1 = *(uint *)(iVar4 + 0xa0 + iVar2);
              if ((uVar1 == uVar5) && (*(uint *)(iVar4 + 0xa4 + iVar2) == uVar3)) {
                *param_4 = 1;
                return local_10;
              }
              if (((*(int *)(iVar4 + 0xa8 + iVar2) != 0) &&
                  (*(uint *)(iVar4 + 0xa4 + iVar2) == uVar5)) && (uVar1 == uVar3)) {
                *param_4 = -1;
                return local_10;
              }
              local_10 = local_10 + 1;
            } while (local_10 < *(int *)(param_1 + 0xa4));
          }
          (*DAT_0019f794)(1,"error in transition graph");
        }
      }
    }
  }
  return param_3;
}


