// CanisterTouch__10CTFCaltropP11CBaseEntity  @ 0010118c
void CanisterTouch__10CTFCaltropP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar2 = *param_1;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar2 + 0x20)) || NAN(g_vecZero)) << 10) >> 8)
             | (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x20) == g_vecZero) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x24))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x24)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x28);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar3) {
    *(float *)(iVar2 + 0x5c) = g_vecZero;
    *(float *)(iVar2 + 0x60) = DAT_0019f664;
    *(float *)(iVar2 + 100) = DAT_0019f668;
  }
  return;
}


