// HullIndex__6CGraphPC11CBaseEntity  @ 000c3dd4
undefined4 HullIndex__6CGraphPC11CBaseEntity(undefined4 param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  if (*(int *)(*param_2 + 0x108) == 5) {
    uVar3 = 3;
  }
  else {
    bVar4 = false;
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_2 + 0xdc)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(*param_2 + 0xdc) == -12.0) << 0xe) >> 8)) == 0x40
        ) && (fVar1 = *(float *)(*param_2 + 0xe0),
             (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == -12.0) << 0xe) >> 8)) == 0x40)) {
      fVar1 = *(float *)(*param_2 + 0xe4);
      bVar4 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
    }
    if (bVar4) {
      uVar3 = 0;
    }
    else {
      bVar4 = false;
      if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_2 + 0xdc)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(*param_2 + 0xdc) == -16.0) << 0xe) >> 8)) ==
           0x40) &&
         (fVar1 = *(float *)(*param_2 + 0xe0),
         (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == -16.0) << 0xe) >> 8)) == 0x40)) {
        fVar1 = *(float *)(*param_2 + 0xe4);
        bVar4 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
      }
      if (!bVar4) {
        iVar2 = *param_2;
        bVar4 = false;
        if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0xdc)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar2 + 0xdc) == -32.0) << 0xe) >> 8)) ==
             0x40) &&
           ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0xe0)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar2 + 0xe0) == -32.0) << 0xe) >> 8)) == 0x40
           )) {
          fVar1 = *(float *)(iVar2 + 0xe4);
          bVar4 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
        }
        if (bVar4) {
          return 2;
        }
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}


