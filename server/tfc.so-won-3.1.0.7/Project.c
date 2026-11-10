// Project__10CPathTrackP10CPathTrackT1P6Vectorf  @ 000cc8ac
void Project__10CPathTrackP10CPathTrackT1P6Vectorf
               (undefined4 param_1,int *param_2,int *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  
  if ((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) {
    iVar3 = *param_3;
    iVar4 = *param_2;
    local_18 = *(float *)(iVar3 + 8) - *(float *)(iVar4 + 8);
    local_14 = *(float *)(iVar3 + 0xc) - *(float *)(iVar4 + 0xc);
    fVar1 = *(float *)(iVar3 + 0x10) - *(float *)(iVar4 + 0x10);
    local_10 = SQRT(fVar1 * fVar1 + local_14 * local_14 + local_18 * local_18);
    if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_18 = 0.0;
      local_14 = 0.0;
      local_10 = 1.0;
    }
    else {
      local_10 = 1.0 / local_10;
      local_18 = local_10 * local_18;
      local_14 = local_10 * local_14;
      local_10 = local_10 * fVar1;
    }
    iVar3 = *param_3;
    fVar1 = *(float *)(iVar3 + 0xc);
    fVar2 = *(float *)(iVar3 + 0x10);
    *param_4 = *(float *)(iVar3 + 8) + param_5 * local_18;
    param_4[1] = fVar1 + param_5 * local_14;
    param_4[2] = fVar2 + param_5 * local_10;
  }
  return;
}


