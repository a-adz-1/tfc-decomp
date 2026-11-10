// CheckShield__12CTFSentrygun  @ 000eee34
void CheckShield__12CTFSentrygun(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(float *)(*param_1 + 0x14c) = *(float *)(*param_1 + 0x14c) - 40.0;
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(*param_1 + 0x15c) = 0;
    *(undefined4 *)(*param_1 + 0x14c) = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x150) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x154) = DAT_0019f664;
    *(undefined4 *)(iVar2 + 0x158) = DAT_0019f668;
  }
  return;
}


