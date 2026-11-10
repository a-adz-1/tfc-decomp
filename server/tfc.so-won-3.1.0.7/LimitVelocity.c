// LimitVelocity__4CGib  @ 00094d88
void LimitVelocity__4CGib(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = *param_1;
  if (1500.0 < SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                    *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                    *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20))) {
    local_14 = SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                    *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                    *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20));
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = local_14 * *(float *)(iVar1 + 0x20);
      local_18 = local_14 * *(float *)(iVar1 + 0x24);
      local_14 = local_14 * *(float *)(iVar1 + 0x28);
    }
    *(float *)(iVar1 + 0x20) = local_1c * 1500.0;
    *(float *)(iVar1 + 0x24) = local_18 * 1500.0;
    *(float *)(iVar1 + 0x28) = local_14 * 1500.0;
  }
  return;
}


