// SetEyePosition__12CBaseMonster  @ 000c1f48
void SetEyePosition__12CBaseMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar3 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  GetEyePosition__FPvPf(uVar3,&uStack_10);
  iVar2 = *param_1;
  bVar4 = false;
  *(undefined4 *)(iVar2 + 0x174) = uStack_10;
  *(undefined4 *)(iVar2 + 0x178) = uStack_c;
  *(undefined4 *)(iVar2 + 0x17c) = uStack_8;
  param_1 = (int *)*param_1;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0x5d])) << 10) >> 8) |
             (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0x5d]) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN((float)param_1[0x5e])) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == (float)param_1[0x5e]) << 0xe) >> 8)) == 0x40))
  {
    fVar1 = (float)param_1[0x5f];
    bVar4 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar4) {
    (*DAT_0019f794)(2,"%s has no view_ofs!\n",*param_1 + *(int *)(gpGlobals + 0x98));
  }
  return;
}


