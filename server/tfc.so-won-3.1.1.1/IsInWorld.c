// IsInWorld__11CBaseEntity  @ 0008e584
undefined4 IsInWorld__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *param_1;
  if (((((4096.0 <= *(float *)(iVar3 + 8)) || (fVar1 = *(float *)(iVar3 + 0xc), 4096.0 <= fVar1)) ||
       (4096.0 <= *(float *)(iVar3 + 0x10))) ||
      ((((*(float *)(iVar3 + 8) <= -4096.0 ||
         ((byte)((fVar1 < -4096.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == -4096.0) << 0xe) >> 8)) - 1) < 0x40)) ||
        ((*(float *)(iVar3 + 0x10) <= -4096.0 ||
         ((fVar1 = *(float *)(iVar3 + 0x20),
          (byte)((2000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 2000.0) << 0xe) >> 8)) - 1) < 0x40 ||
          (fVar2 = *(float *)(iVar3 + 0x24),
          (byte)((2000.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 2000.0) << 0xe) >> 8)) - 1) < 0x40)))))) ||
       (2000.0 <= *(float *)(iVar3 + 0x28))))) ||
     (((fVar1 <= -2000.0 || (*(float *)(iVar3 + 0x24) <= -2000.0)) ||
      (*(float *)(iVar3 + 0x28) <= -2000.0)))) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


