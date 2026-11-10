// WritePositionVector__5CSavePCcPCfi  @ 0012107c
void WritePositionVector__5CSavePCcPCfi(int *param_1,undefined4 param_2,float *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float local_28;
  float local_24;
  float local_20;
  
  BufferHeader__5CSavePCci(param_1,param_2,param_4 * 0xc);
  iVar2 = 0;
  if (0 < param_4) {
    do {
      local_28 = *param_3;
      local_24 = param_3[1];
      local_20 = param_3[2];
      iVar1 = *param_1;
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x52c) != 0)) {
        local_28 = local_28 - *(float *)(iVar1 + 0x544);
        local_24 = local_24 - *(float *)(iVar1 + 0x548);
        local_20 = local_20 - *(float *)(iVar1 + 0x54c);
      }
      BufferData__5CSavePCci(param_1,&local_28,0xc);
      param_3 = param_3 + 3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_4);
  }
  return;
}


// WritePositionVector__5CSavePCcRC6Vector  @ 00121150
void WritePositionVector__5CSavePCcRC6Vector(int *param_1,undefined4 param_2,float *param_3)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x52c) != 0)) {
    local_10 = *param_3 - *(float *)(iVar1 + 0x544);
    local_c = param_3[1] - *(float *)(iVar1 + 0x548);
    local_8 = param_3[2] - *(float *)(iVar1 + 0x54c);
    WriteVector__5CSavePCcPCfi(param_1,param_2,&local_10,1);
  }
  WriteVector__5CSavePCcPCfi(param_1,param_2,param_3,1);
  return;
}


