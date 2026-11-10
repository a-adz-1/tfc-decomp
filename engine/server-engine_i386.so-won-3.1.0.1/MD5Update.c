// MD5Update__FP12MD5Context_tPCUcUi  @ 00095618
void MD5Update__FP12MD5Context_tPCUcUi(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar8 = uVar1 + param_3 * 8;
  *(uint *)(param_1 + 0x10) = uVar8;
  if (uVar8 < uVar1) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  uVar8 = uVar1 >> 3 & 0x3f;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  if (uVar8 != 0) {
    uVar1 = 0x40 - uVar8;
    if (param_3 < uVar1) {
      puVar7 = (undefined4 *)&stack0xffffffe0;
      goto LAB_000957dc;
    }
    memcpy((void *)(param_1 + 0x18 + uVar8),param_2,uVar1);
    MD5Transform__FPUiPCUi(param_1,param_1 + 0x18);
    param_2 = (undefined4 *)((int)param_2 + uVar1);
    param_3 = param_3 - uVar1;
  }
  puVar6 = &stack0xffffffec;
  puVar3 = (undefined4 *)(param_1 + 0x18);
  if (0x3f < param_3) {
    uVar8 = 0x3f - param_3 & 0xff;
    if (0x3f < (int)param_3) {
      puVar4 = &stack0xffffffec;
      if (uVar8 == 0) goto LAB_00095744;
      if (uVar8 < 0xc0) {
        if (uVar8 < 0x80) {
          puVar4 = &stack0xffffffec;
          if (uVar8 < 0x40) goto LAB_00095744;
          puVar9 = param_2;
          puVar10 = puVar3;
          for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          MD5Transform__FPUiPCUi();
          param_2 = param_2 + 0x10;
          param_3 = param_3 - 0x40;
        }
        puVar9 = param_2;
        puVar10 = puVar3;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        MD5Transform__FPUiPCUi();
        param_2 = param_2 + 0x10;
        param_3 = param_3 - 0x40;
      }
    }
    puVar9 = param_2;
    puVar10 = puVar3;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    puVar5 = &stack0xffffffe4;
    MD5Transform__FPUiPCUi();
    param_2 = param_2 + 0x10;
    for (param_3 = param_3 - 0x40; puVar6 = puVar5 + 8, puVar4 = puVar5 + 8, 0x3f < param_3;
        param_3 = param_3 - 0x100) {
LAB_00095744:
      puVar9 = param_2;
      puVar10 = puVar3;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 **)(puVar4 + -4) = puVar3;
      *(int *)(puVar4 + -8) = param_1;
      *(undefined4 *)(puVar4 + -0xc) = 0x9575e;
      MD5Transform__FPUiPCUi();
      puVar9 = param_2 + 0x10;
      puVar10 = puVar3;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 **)(puVar4 + -4) = puVar3;
      *(int *)(puVar4 + -8) = param_1;
      *(undefined4 *)(puVar4 + -0xc) = 0x9577b;
      MD5Transform__FPUiPCUi();
      puVar9 = param_2 + 0x20;
      puVar10 = puVar3;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 **)(puVar4 + -4) = puVar3;
      *(int *)(puVar4 + -8) = param_1;
      *(undefined4 *)(puVar4 + -0xc) = 0x95798;
      MD5Transform__FPUiPCUi();
      puVar9 = param_2 + 0x30;
      puVar10 = puVar3;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 **)(puVar4 + -4) = puVar3;
      puVar5 = puVar4 + -8;
      *(int *)(puVar4 + -8) = param_1;
      *(undefined4 *)(puVar4 + -0xc) = 0x957b8;
      MD5Transform__FPUiPCUi();
      param_2 = param_2 + 0x40;
    }
  }
  *(uint *)(puVar6 + -4) = param_3;
  *(undefined4 **)(puVar6 + -8) = param_2;
  puVar7 = (undefined4 *)(puVar6 + -0xc);
  *(undefined4 **)(puVar6 + -0xc) = puVar3;
LAB_000957dc:
  puVar7[-1] = 0x957e1;
  memcpy((void *)*puVar7,(void *)puVar7[1],puVar7[2]);
  return;
}


