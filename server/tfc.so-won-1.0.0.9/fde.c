// fde_merge  @ 00120814
void fde_merge(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_2[1];
  if (iVar6 != 0) {
    iVar5 = param_1[1];
    do {
      iVar6 = iVar6 + -1;
      iVar1 = *(int *)(*param_2 + iVar6 * 4);
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        iVar2 = *(int *)(*param_1 + -4 + iVar5 * 4);
        iVar3 = *(int *)(iVar1 + 8);
        iVar4 = *(int *)(iVar2 + 8);
        if (iVar4 == iVar3 || iVar4 - iVar3 < 0) break;
        *(int *)(*param_1 + (iVar6 + iVar5) * 4) = iVar2;
      }
      *(int *)(*param_1 + (iVar6 + iVar5) * 4) = iVar1;
    } while (iVar6 != 0);
    param_1[1] = param_1[1] + param_2[1];
  }
  return;
}


// fde_split  @ 0012147c
void fde_split(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0xffffffff;
  uVar5 = 0;
  uVar1 = param_1[1];
  iVar3 = (uVar1 & 0x7ffffff) * -4;
  if (uVar1 != 0) {
    do {
      while ((uVar4 != 0xffffffff &&
             (iVar2 = *(int *)(*param_1 + uVar4 * 4),
             *(int *)(*(int *)(*param_1 + uVar5 * 4) + 8) - *(int *)(iVar2 + 8) < 0))) {
        *(int *)(*param_2 + param_2[1] * 4) = iVar2;
        param_2[1] = param_2[1] + 1;
        *(undefined4 *)(*param_1 + uVar4 * 4) = 0;
        uVar4 = *(uint *)(&stack0xffffffe8 + uVar4 * 4 + iVar3);
      }
      *(uint *)(&stack0xffffffe8 + uVar5 * 4 + iVar3) = uVar4;
      uVar6 = uVar5 + 1;
      uVar4 = uVar5;
      uVar5 = uVar6;
    } while (uVar6 < uVar1);
  }
  uVar4 = 0;
  iVar3 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = *(int *)(*param_1 + uVar4 * 4);
      if (iVar2 != 0) {
        *(int *)(*param_1 + iVar3 * 4) = iVar2;
        iVar3 = iVar3 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  param_1[1] = iVar3;
  return;
}


