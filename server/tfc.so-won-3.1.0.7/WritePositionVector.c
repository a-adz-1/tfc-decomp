// WritePositionVector__5CSavePCcPCfi  @ 0011d348
void WritePositionVector__5CSavePCcPCfi(int *param_1,undefined4 param_2,float *param_3,uint param_4)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int local_34;
  float local_24;
  float local_20;
  float local_1c;
  
  BufferHeader__5CSavePCci(param_1,param_2,param_4 * 0xc);
  local_34 = 0;
  if (0 < (int)param_4) {
    pfVar2 = param_3 + 2;
    pfVar3 = pfVar2;
    if ((param_4 & 1) != 0) {
      local_24 = *param_3;
      local_20 = param_3[1];
      local_1c = param_3[2];
      if ((*param_1 != 0) && (iVar1 = *param_1, *(int *)(iVar1 + 0x52c) != 0)) {
        local_24 = local_24 - *(float *)(iVar1 + 0x544);
        local_20 = local_20 - *(float *)(iVar1 + 0x548);
        local_1c = local_1c - *(float *)(iVar1 + 0x54c);
      }
      BufferData__5CSavePCci(param_1,&local_24,0xc);
      pfVar2 = param_3 + 5;
      param_3 = param_3 + 3;
      local_34 = 1;
      pfVar3 = pfVar2;
      if ((int)param_4 < 2) {
        return;
      }
    }
    do {
      local_24 = *param_3;
      local_20 = pfVar3[-1];
      local_1c = *pfVar2;
      if ((*param_1 != 0) && (iVar1 = *param_1, *(int *)(iVar1 + 0x52c) != 0)) {
        local_24 = local_24 - *(float *)(iVar1 + 0x544);
        local_20 = local_20 - *(float *)(iVar1 + 0x548);
        local_1c = local_1c - *(float *)(iVar1 + 0x54c);
      }
      BufferData__5CSavePCci(param_1,&local_24,0xc);
      local_24 = param_3[3];
      local_20 = pfVar3[2];
      local_1c = pfVar2[3];
      if ((*param_1 != 0) && (iVar1 = *param_1, *(int *)(iVar1 + 0x52c) != 0)) {
        local_24 = local_24 - *(float *)(iVar1 + 0x544);
        local_20 = local_20 - *(float *)(iVar1 + 0x548);
        local_1c = local_1c - *(float *)(iVar1 + 0x54c);
      }
      BufferData__5CSavePCci(param_1,&local_24,0xc);
      pfVar2 = pfVar2 + 6;
      param_3 = param_3 + 6;
      local_34 = local_34 + 2;
      pfVar3 = pfVar3 + 6;
    } while (local_34 < (int)param_4);
  }
  return;
}


// WritePositionVector__5CSavePCcRC6Vector  @ 0011d2cc
void WritePositionVector__5CSavePCcRC6Vector(int *param_1,undefined4 param_2,float *param_3)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*param_1 != 0) && (iVar1 = *param_1, *(int *)(iVar1 + 0x52c) != 0)) {
    local_c = *param_3 - *(float *)(iVar1 + 0x544);
    local_8 = param_3[1] - *(float *)(iVar1 + 0x548);
    local_4 = param_3[2] - *(float *)(iVar1 + 0x54c);
    WriteVector__5CSavePCcRC6Vector(param_1,param_2,&local_c);
  }
  WriteVector__5CSavePCcRC6Vector(param_1,param_2,param_3);
  return;
}


