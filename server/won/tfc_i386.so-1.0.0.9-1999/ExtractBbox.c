// ExtractBbox__FPviPfT2  @ 0009aa30
bool ExtractBbox__FPviPfT2(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + *(int *)(param_1 + 0xa8);
    param_2 = param_2 * 0xb0;
    *param_3 = *(undefined4 *)(iVar1 + 0x60 + param_2);
    param_3[1] = *(undefined4 *)(iVar1 + 100 + param_2);
    param_3[2] = *(undefined4 *)(iVar1 + 0x68 + param_2);
    *param_4 = *(undefined4 *)(iVar1 + 0x6c + param_2);
    param_4[1] = *(undefined4 *)(iVar1 + 0x70 + param_2);
    param_4[2] = *(undefined4 *)(iVar1 + 0x74 + param_2);
  }
  return param_1 != 0;
}


