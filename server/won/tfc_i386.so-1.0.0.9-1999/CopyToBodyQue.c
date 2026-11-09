// CopyToBodyQue__FP9entvars_t  @ 0011d0d0
void CopyToBodyQue__FP9entvars_t(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (-1 < *(char *)(param_1 + 0xf8)) {
    if (g_pBodyQueueHead == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = g_pBodyQueueHead + 0xdc;
    }
    *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(param_1 + 0x50);
    *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(param_1 + 0x54);
    *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(iVar2 + 0x98) = *(undefined4 *)(param_1 + 0x98);
    *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(param_1 + 0x94);
    *(undefined4 *)(iVar2 + 0x110) = *(undefined4 *)(param_1 + 0x110);
    *(undefined4 *)(iVar2 + 0x188) = *(undefined4 *)(param_1 + 0x188);
    *(undefined4 *)(iVar2 + 0xe8) = 6;
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x184) = 0;
    *(undefined4 *)(iVar2 + 0x150) = *(undefined4 *)(param_1 + 0x150);
    *(undefined4 *)(iVar2 + 0x13c) = 0x11;
    iVar1 = (*DAT_001755dc)(*(undefined4 *)(param_1 + 0x1e8));
    *(float *)(iVar2 + 300) = (float)iVar1;
    *(uint *)(iVar2 + 0xf8) = *(uint *)(param_1 + 0xf8) | 0x20;
    *(undefined4 *)(iVar2 + 0x108) = *(undefined4 *)(param_1 + 0x108);
    *(undefined4 *)(iVar2 + 0x114) = *(undefined4 *)(param_1 + 0x114);
    UTIL_SetOrigin__FP9entvars_tRC6Vector(iVar2,param_1 + 8);
    UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar2,param_1 + 0xbc,param_1 + 200);
    g_pBodyQueueHead = *(int *)(iVar2 + 0x178);
  }
  return;
}


