// FindEntityForward__FP11CBaseEntity  @ 000d0210
undefined4 FindEntityForward__FP11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
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
  float local_3c;
  undefined1 local_38 [16];
  float local_28;
  int local_8;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
  iVar2 = *param_1;
  local_50 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
  local_4c = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
  local_48 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
  local_5c = *(float *)(gpGlobals + 0x28) * 8192.0;
  local_58 = *(float *)(gpGlobals + 0x2c) * 8192.0;
  local_54 = *(float *)(gpGlobals + 0x30) * 8192.0;
  local_44 = local_50 + local_5c;
  local_40 = local_4c + local_58;
  local_3c = local_48 + local_54;
  local_68 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
  local_64 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
  local_60 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_68,&local_44,0,*(undefined4 *)(iVar2 + 0x208),local_38);
  if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) != 0x40) {
    bVar1 = false;
    if ((local_8 == 0) || (iVar2 = (*DAT_001a7f58)(local_8), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      if ((local_8 == 0) && (local_8 = (*DAT_001a7f54)(0), local_8 == 0)) {
        return 0;
      }
      return *(undefined4 *)(local_8 + 0x7c);
    }
  }
  return 0;
}


