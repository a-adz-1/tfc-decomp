// CanisterTouch__10CTFCaltropP11CBaseEntity  @ 000fdda0
void CanisterTouch__10CTFCaltropP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x20))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x20)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x24),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_00175484 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x28);
    bVar3 = (byte)(DAT_00175488 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar3) {
    iVar2 = *param_1;
    *(float *)(iVar2 + 0x5c) = g_vecZero;
    *(float *)(iVar2 + 0x60) = DAT_00175484;
    *(float *)(iVar2 + 100) = DAT_00175488;
  }
  return;
}


