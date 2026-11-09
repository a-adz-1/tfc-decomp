// FindEntityForward__FP11CBaseEntity  @ 000dd730
undefined4 FindEntityForward__FP11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  int iStack_c;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
  iVar2 = *param_1;
  fStack_54 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x154);
  fStack_50 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x158);
  fStack_4c = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x15c);
  fStack_60 = *(float *)(gpGlobals + 0x28) * 8192.0;
  fStack_5c = *(float *)(gpGlobals + 0x2c) * 8192.0;
  fStack_58 = *(float *)(gpGlobals + 0x30) * 8192.0;
  fStack_48 = fStack_54 + fStack_60;
  fStack_44 = fStack_50 + fStack_5c;
  fStack_40 = fStack_4c + fStack_58;
  fStack_6c = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x154);
  fStack_68 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x158);
  fStack_64 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x15c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_6c,&fStack_48,0,*(undefined4 *)(iVar2 + 0x1e8),auStack_3c);
  if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
    bVar1 = false;
    if ((iStack_c == 0) || (iVar2 = (*DAT_001755d8)(iStack_c), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      if ((iStack_c == 0) && (iStack_c = (*DAT_001755d4)(0), iStack_c == 0)) {
        return 0;
      }
      return *(undefined4 *)(iStack_c + 0xd8);
    }
  }
  return 0;
}


