// FindEntityForward__FP11CBaseEntity  @ 000daab4
undefined4 FindEntityForward__FP11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  int local_c;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
  iVar2 = *param_1;
  local_54 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
  local_50 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
  local_4c = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
  local_60 = *(float *)(gpGlobals + 0x28) * 8192.0;
  local_48 = local_54 + local_60;
  local_5c = *(float *)(gpGlobals + 0x2c) * 8192.0;
  local_44 = local_50 + local_5c;
  local_58 = *(float *)(gpGlobals + 0x30) * 8192.0;
  local_40 = local_4c + local_58;
  local_6c = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
  local_68 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
  local_64 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_6c,&local_48,0,*(undefined4 *)(iVar2 + 0x208),local_3c);
  if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
    bVar1 = false;
    if ((local_c == 0) || (iVar2 = (*DAT_0019f7b8)(local_c), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      if ((local_c == 0) && (local_c = (*DAT_0019f7b4)(0), local_c == 0)) {
        return 0;
      }
      return *(undefined4 *)(local_c + 0x7c);
    }
  }
  return 0;
}


