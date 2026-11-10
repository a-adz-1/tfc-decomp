// FEntIsVisible__FP9entvars_sT0  @ 000e79dc
undefined4 FEntIsVisible__FP9entvars_sT0(int param_1,int param_2)

{
  undefined1 local_50 [8];
  int local_48;
  int local_44;
  float local_40;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x174);
  local_8 = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x178);
  local_4 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x17c);
  local_18 = *(float *)(param_2 + 8) + *(float *)(param_2 + 0x174);
  local_14 = *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0x178);
  local_10 = *(float *)(param_2 + 0x10) + *(float *)(param_2 + 0x17c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_c,&local_18,1,*(undefined4 *)(param_1 + 0x208),local_50);
  if (((local_48 == 0) || (local_44 == 0)) &&
     ((byte)(1.0 < local_40 | (byte)((ushort)((ushort)NAN(local_40) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_40 == 1.0) << 0xe) >> 8)) == 0x40)) {
    return 1;
  }
  return 0;
}


