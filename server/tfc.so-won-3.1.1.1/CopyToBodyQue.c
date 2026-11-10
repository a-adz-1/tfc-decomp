// CopyToBodyQue__FP9entvars_s  @ 001269f8
void CopyToBodyQue__FP9entvars_s(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (-1 < *(char *)(param_1 + 0x118)) {
    iVar2 = g_pBodyQueueHead + 0x80;
    if (g_pBodyQueueHead == 0) {
      iVar2 = 0;
    }
    *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(param_1 + 0x50);
    *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(param_1 + 0x54);
    *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(iVar2 + 0xb8) = *(undefined4 *)(param_1 + 0xb8);
    *(undefined4 *)(iVar2 + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(iVar2 + 0x130) = *(undefined4 *)(param_1 + 0x130);
    *(undefined4 *)(iVar2 + 0x1a8) = *(undefined4 *)(param_1 + 0x1a8);
    *(undefined4 *)(iVar2 + 0x108) = 6;
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x1a4) = 0;
    *(undefined4 *)(iVar2 + 0x170) = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 *)(iVar2 + 0x15c) = 0x11;
    iVar1 = (*DAT_0019f7bc)(*(undefined4 *)(param_1 + 0x208));
    *(float *)(iVar2 + 0x14c) = (float)iVar1;
    *(uint *)(iVar2 + 0x118) = *(uint *)(param_1 + 0x118) | 0x20;
    *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(param_1 + 0x128);
    *(undefined4 *)(iVar2 + 0x134) = *(undefined4 *)(param_1 + 0x134);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar2,param_1 + 8);
    UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,param_1 + 0xdc,param_1 + 0xe8);
    g_pBodyQueueHead = *(int *)(iVar2 + 0x198);
  }
  return;
}


