// Project__10CPathTrackP10CPathTrackT1P6Vectorf  @ 000cc2a4
void Project__10CPathTrackP10CPathTrackT1P6Vectorf
               (undefined4 param_1,int *param_2,int *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_1c;
  float local_18;
  float local_14;
  
  if ((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) {
    iVar3 = *param_3;
    iVar4 = *param_2;
    local_1c = *(float *)(iVar3 + 8) - *(float *)(iVar4 + 8);
    local_18 = *(float *)(iVar3 + 0xc) - *(float *)(iVar4 + 0xc);
    fVar1 = *(float *)(iVar3 + 0x10) - *(float *)(iVar4 + 0x10);
    local_14 = SQRT(fVar1 * fVar1 + local_18 * local_18 + local_1c * local_1c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = local_1c * local_14;
      local_18 = local_18 * local_14;
      local_14 = local_14 * fVar1;
    }
    iVar3 = *param_3;
    fVar1 = *(float *)(iVar3 + 0xc);
    fVar2 = *(float *)(iVar3 + 0x10);
    *param_4 = local_1c * param_5 + *(float *)(iVar3 + 8);
    param_4[1] = local_18 * param_5 + fVar1;
    param_4[2] = local_14 * param_5 + fVar2;
  }
  return;
}


