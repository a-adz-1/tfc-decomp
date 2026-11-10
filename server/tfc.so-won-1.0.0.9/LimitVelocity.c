// LimitVelocity__4CGib  @ 000a3b50
void LimitVelocity__4CGib(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x20);
  fVar2 = *(float *)(iVar4 + 0x24);
  fVar3 = *(float *)(iVar4 + 0x28);
  fVar5 = SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
  if ((byte)(1500.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar5 == 1500.0) << 0xe) >> 8)) == 1) {
    local_18 = SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_18 * *(float *)(iVar4 + 0x20);
      local_1c = local_18 * *(float *)(iVar4 + 0x24);
      local_18 = local_18 * *(float *)(iVar4 + 0x28);
    }
    *(float *)(iVar4 + 0x20) = local_20 * 1500.0;
    *(float *)(iVar4 + 0x24) = local_1c * 1500.0;
    *(float *)(iVar4 + 0x28) = local_18 * 1500.0;
  }
  return;
}


