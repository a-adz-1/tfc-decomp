// MD5Final__FPUcP12MD5Context_t  @ 000957ec
void MD5Final__FPUcP12MD5Context_t(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2[4] >> 3 & 0x3f;
  puVar2 = (undefined1 *)((int)param_2 + uVar3 + 0x18);
  iVar1 = -uVar3;
  uVar3 = iVar1 + 0x3f;
  *puVar2 = 0x80;
  puVar2 = puVar2 + 1;
  if (uVar3 < 8) {
    memset(puVar2,0,uVar3);
    MD5Transform__FPUiPCUi(param_2,param_2 + 6);
    memset(param_2 + 6,0,0x38);
  }
  else {
    memset(puVar2,0,iVar1 + 0x37);
  }
  param_2[0x14] = param_2[4];
  param_2[0x15] = param_2[5];
  MD5Transform__FPUiPCUi(param_2,param_2 + 6);
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  memset(param_2,0,4);
  return;
}


