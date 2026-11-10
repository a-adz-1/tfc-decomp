// MD5Update__FP12MD5Context_tPCUcUi  @ 000ccd3c
void MD5Update__FP12MD5Context_tPCUcUi(int param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  void *__dest;
  
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar1 = param_3 * 8 + uVar2;
  *(uint *)(param_1 + 0x10) = uVar1;
  if (uVar1 < uVar2) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar2 = uVar2 >> 3 & 0x3f;
  if (uVar2 != 0) {
    __dest = (void *)(param_1 + uVar2 + 0x18);
    uVar2 = 0x40 - uVar2;
    if (param_3 < uVar2) {
      memcpy(__dest,param_2,param_3);
      return;
    }
    memcpy(__dest,param_2,uVar2);
    MD5Transform__FPUiPCUi(param_1,param_1 + 0x18);
    param_2 = (void *)((int)param_2 + uVar2);
    param_3 = param_3 - uVar2;
  }
  for (; 0x3f < param_3; param_3 = param_3 - 0x40) {
    memcpy((void *)(param_1 + 0x18),param_2,0x40);
    MD5Transform__FPUiPCUi(param_1,param_1 + 0x18);
    param_2 = (void *)((int)param_2 + 0x40);
  }
  memcpy((void *)(param_1 + 0x18),param_2,param_3);
  return;
}


