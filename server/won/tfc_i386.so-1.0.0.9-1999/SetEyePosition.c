// SetEyePosition__12CBaseMonster  @ 000c54d0
void SetEyePosition__12CBaseMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  GetEyePosition__FPvPf(uVar3,&local_10);
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x154) = local_10;
  *(undefined4 *)(iVar2 + 0x158) = local_c;
  *(undefined4 *)(iVar2 + 0x15c) = local_8;
  iVar2 = *param_1;
  bVar4 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x154))) << 10) >> 8
                    ) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x154)) << 0xe) >> 8)) == 0x40
      ) && ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(*(float *)(iVar2 + 0x158))) <<
                                  10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175484 == *(float *)(iVar2 + 0x158)) << 0xe) >> 8))
            == 0x40)) {
    fVar1 = *(float *)(iVar2 + 0x15c);
    bVar4 = (byte)(DAT_00175488 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar4) {
    (*DAT_001755b4)(2,"%s has no view_ofs!\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
  }
  return;
}


