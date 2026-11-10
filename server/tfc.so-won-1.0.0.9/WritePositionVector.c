// WritePositionVector__5CSavePCcPCfi  @ 001192a0
void WritePositionVector__5CSavePCcPCfi(int *param_1,undefined4 param_2,float *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float local_28;
  float local_24;
  float local_20;
  
  BufferHeader__5CSavePCci(param_1,param_2,param_4 * 0xc);
  if (0 < param_4) {
    iVar2 = 0;
    do {
      local_28 = *param_3;
      local_24 = param_3[1];
      local_20 = param_3[2];
      if ((*param_1 != 0) && (iVar1 = *param_1, *(int *)(iVar1 + 0x52c) != 0)) {
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


// WritePositionVector__5CSavePCcRC6Vector  @ 00119230
void WritePositionVector__5CSavePCcRC6Vector(int *param_1,undefined4 param_2,float *param_3)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  
  if ((*param_1 != 0) && (iVar1 = *param_1, *(int *)(iVar1 + 0x52c) != 0)) {
    local_10 = *param_3 - *(float *)(iVar1 + 0x544);
    local_c = param_3[1] - *(float *)(iVar1 + 0x548);
    local_8 = param_3[2] - *(float *)(iVar1 + 0x54c);
    WriteVector__5CSavePCcRC6Vector(param_1,param_2,&local_10);
  }
  WriteVector__5CSavePCcRC6Vector(param_1,param_2,param_3);
  return;
}


