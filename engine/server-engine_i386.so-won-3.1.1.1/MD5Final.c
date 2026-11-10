// MD5Final__FPUcP12MD5Context_t  @ 000cce78
void MD5Final__FPUcP12MD5Context_t(void *param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = *(uint *)((int)param_2 + 0x10) >> 3 & 0x3f;
  puVar3 = (undefined1 *)((int)param_2 + uVar2 + 0x18);
  *puVar3 = 0x80;
  puVar3 = puVar3 + 1;
  iVar1 = -uVar2;
  uVar2 = iVar1 + 0x3f;
  if (uVar2 < 8) {
    memset(puVar3,0,uVar2);
    MD5Transform__FPUiPCUi(param_2,(int)param_2 + 0x18);
    memset((void *)((int)param_2 + 0x18),0,0x38);
  }
  else {
    memset(puVar3,0,iVar1 + 0x37);
  }
  *(undefined4 *)((int)param_2 + 0x50) = *(undefined4 *)((int)param_2 + 0x10);
  *(undefined4 *)((int)param_2 + 0x54) = *(undefined4 *)((int)param_2 + 0x14);
  MD5Transform__FPUiPCUi(param_2,(int)param_2 + 0x18);
  memcpy(param_1,param_2,0x10);
  memset(param_2,0,4);
  return;
}


