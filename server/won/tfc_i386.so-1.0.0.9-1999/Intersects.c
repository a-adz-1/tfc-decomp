// Intersects__11CBaseEntityP11CBaseEntity  @ 000a17b0
undefined4 Intersects__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_2;
  iVar4 = *param_1;
  if (((*(float *)(iVar3 + 0xa4) <= *(float *)(iVar4 + 0xb0)) &&
      (*(float *)(iVar3 + 0xa8) <= *(float *)(iVar4 + 0xb4))) &&
     (*(float *)(iVar3 + 0xac) <= *(float *)(iVar4 + 0xb8))) {
    fVar1 = *(float *)(iVar3 + 0xb0);
    fVar2 = *(float *)(iVar4 + 0xa4);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      fVar1 = *(float *)(iVar3 + 0xb4);
      fVar2 = *(float *)(iVar4 + 0xa8);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        fVar1 = *(float *)(iVar3 + 0xb8);
        fVar2 = *(float *)(iVar4 + 0xac);
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          return 1;
        }
      }
    }
  }
  return 0;
}


