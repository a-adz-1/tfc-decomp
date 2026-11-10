// WriteTime__5CSavePCcPCfi  @ 0010d228
void WriteTime__5CSavePCcPCfi(int *param_1,undefined4 param_2,float *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  float local_1c [7];
  
  BufferHeader__5CSavePCci(param_1,param_2,param_4 * 4);
  iVar2 = 0;
  if (0 < (int)param_4) {
    uVar1 = param_4 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          local_1c[0] = *param_3;
          if (*param_1 != 0) {
            local_1c[0] = local_1c[0] - *(float *)(*param_1 + 0x550);
          }
          BufferData__5CSavePCci(param_1,local_1c,4);
          param_3 = param_3 + 1;
          iVar2 = 1;
        }
        local_1c[0] = *param_3;
        if (*param_1 != 0) {
          local_1c[0] = local_1c[0] - *(float *)(*param_1 + 0x550);
        }
        BufferData__5CSavePCci(param_1,local_1c,4);
        param_3 = param_3 + 1;
        iVar2 = iVar2 + 1;
      }
      local_1c[0] = *param_3;
      if (*param_1 != 0) {
        local_1c[0] = local_1c[0] - *(float *)(*param_1 + 0x550);
      }
      BufferData__5CSavePCci(param_1,local_1c,4);
      param_3 = param_3 + 1;
      iVar2 = iVar2 + 1;
      if ((int)param_4 <= iVar2) {
        return;
      }
    }
    do {
      local_1c[0] = *param_3;
      if (*param_1 != 0) {
        local_1c[0] = local_1c[0] - *(float *)(*param_1 + 0x550);
      }
      BufferData__5CSavePCci(param_1,local_1c,4);
      local_1c[0] = param_3[1];
      if (*param_1 != 0) {
        local_1c[0] = local_1c[0] - *(float *)(*param_1 + 0x550);
      }
      BufferData__5CSavePCci(param_1,local_1c,4);
      local_1c[0] = param_3[2];
      if (*param_1 != 0) {
        local_1c[0] = local_1c[0] - *(float *)(*param_1 + 0x550);
      }
      BufferData__5CSavePCci(param_1,local_1c,4);
      local_1c[0] = param_3[3];
      if (*param_1 != 0) {
        local_1c[0] = local_1c[0] - *(float *)(*param_1 + 0x550);
      }
      BufferData__5CSavePCci(param_1,local_1c,4);
      param_3 = param_3 + 4;
      iVar2 = iVar2 + 4;
    } while (iVar2 < (int)param_4);
  }
  return;
}


