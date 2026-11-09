// WriteTime__5CSavePCcPCfi  @ 00119090
void WriteTime__5CSavePCcPCfi(int *param_1,undefined4 param_2,float *param_3,int param_4)

{
  int iVar1;
  float local_20 [7];
  
  BufferHeader__5CSavePCci(param_1,param_2,param_4 * 4);
  iVar1 = 0;
  if (0 < param_4) {
    do {
      local_20[0] = *param_3;
      if (*param_1 != 0) {
        local_20[0] = local_20[0] - *(float *)(*param_1 + 0x550);
      }
      BufferData__5CSavePCci(param_1,local_20,4);
      param_3 = param_3 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_4);
  }
  return;
}


