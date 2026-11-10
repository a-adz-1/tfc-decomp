// Intersects__11CBaseEntityP11CBaseEntity  @ 0008f260
undefined4 Intersects__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_2;
  iVar4 = *param_1;
  if (((*(float *)(iVar3 + 0xc4) <= *(float *)(iVar4 + 0xd0)) &&
      (*(float *)(iVar3 + 200) <= *(float *)(iVar4 + 0xd4))) &&
     (*(float *)(iVar3 + 0xcc) <= *(float *)(iVar4 + 0xd8))) {
    fVar1 = *(float *)(iVar3 + 0xd0);
    fVar2 = *(float *)(iVar4 + 0xc4);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      fVar1 = *(float *)(iVar3 + 0xd4);
      fVar2 = *(float *)(iVar4 + 200);
      if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
         (*(float *)(iVar4 + 0xcc) <= *(float *)(iVar3 + 0xd8))) {
        return 1;
      }
    }
  }
  return 0;
}


