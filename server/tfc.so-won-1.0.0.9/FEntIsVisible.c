// FEntIsVisible__FP9entvars_tT0  @ 000f1060
undefined4 FEntIsVisible__FP9entvars_tT0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_54 [8];
  int local_4c;
  int local_48;
  float local_44;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x154);
  local_c = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x158);
  local_8 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x15c);
  local_1c = *(float *)(param_2 + 8) + *(float *)(param_2 + 0x154);
  local_18 = *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0x158);
  local_14 = *(float *)(param_2 + 0x10) + *(float *)(param_2 + 0x15c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_10,&local_1c,1,*(undefined4 *)(param_1 + 0x1e8),local_54);
  if (((local_4c == 0) || (local_48 == 0)) &&
     ((byte)(1.0 < local_44 | (byte)((ushort)((ushort)NAN(local_44) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_44 == 1.0) << 0xe) >> 8)) == 0x40)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


