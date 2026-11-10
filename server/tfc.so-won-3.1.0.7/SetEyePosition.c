// SetEyePosition__12CBaseMonster  @ 000beda4
void SetEyePosition__12CBaseMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar3 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  GetEyePosition__FPvPf(uVar3,&local_c);
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x174) = local_c;
  *(undefined4 *)(iVar2 + 0x178) = local_8;
  *(undefined4 *)(iVar2 + 0x17c) = local_4;
  iVar2 = *param_1;
  bVar4 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x174))) << 10) >> 8
                    ) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x174)) << 0xe) >> 8)) == 0x40
      ) && ((byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(*(float *)(iVar2 + 0x178))) <<
                                  10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe4 == *(float *)(iVar2 + 0x178)) << 0xe) >> 8))
            == 0x40)) {
    fVar1 = *(float *)(iVar2 + 0x17c);
    bVar4 = (byte)(DAT_001c0fe8 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar4) {
    (*DAT_001c1114)(2,"%s has no view_ofs!\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
  }
  return;
}


