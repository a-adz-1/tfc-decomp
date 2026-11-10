// LimitVelocity__4CGib  @ 00094a9c
void LimitVelocity__4CGib(int *param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = *param_1;
  if (1500.0 < SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                    *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                    *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20))) {
    local_18 = SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                    *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                    *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20));
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = *(float *)(iVar1 + 0x20) * local_18;
      local_1c = *(float *)(iVar1 + 0x24) * local_18;
      local_18 = local_18 * *(float *)(iVar1 + 0x28);
    }
    *(float *)(iVar1 + 0x20) = local_20 * 1500.0;
    *(float *)(iVar1 + 0x24) = local_1c * 1500.0;
    *(float *)(iVar1 + 0x28) = local_18 * 1500.0;
  }
  return;
}


