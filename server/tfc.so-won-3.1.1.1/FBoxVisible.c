// FBoxVisible__FP9entvars_sT0R6Vectorf  @ 000b200c
undefined4
FBoxVisible__FP9entvars_sT0R6Vectorf(int param_1,int param_2,float *param_3,float param_4)

{
  int iVar1;
  longdouble lVar2;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  if (*(int *)(param_1 + 0x1c0) == 3) {
    if (*(int *)(param_2 + 0x1c0) == 0) {
      return 0;
    }
  }
  else if (*(int *)(param_2 + 0x1c0) == 3) {
    return 0;
  }
  local_48 = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x174);
  local_40 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x17c);
  iVar1 = 0;
  local_44 = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x178);
  do {
    local_54 = *(float *)(param_2 + 8);
    local_50 = *(float *)(param_2 + 0xc);
    local_4c = *(float *)(param_2 + 0x10);
    lVar2 = (longdouble)
            (*DAT_0019f80c)(param_4 + *(float *)(param_2 + 0xdc),
                            *(float *)(param_2 + 0xe8) - param_4);
    local_54 = (float)(lVar2 + (longdouble)local_54);
    lVar2 = (longdouble)
            (*DAT_0019f80c)(param_4 + *(float *)(param_2 + 0xe0),
                            *(float *)(param_2 + 0xec) - param_4);
    local_50 = (float)(lVar2 + (longdouble)local_50);
    lVar2 = (longdouble)
            (*DAT_0019f80c)(param_4 + *(float *)(param_2 + 0xe4),
                            *(float *)(param_2 + 0xf0) - param_4);
    local_4c = (float)(lVar2 + (longdouble)local_4c);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&local_48,&local_54,1,1,*(undefined4 *)(param_1 + 0x208),local_3c);
    if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
      *param_3 = local_54;
      param_3[1] = local_50;
      param_3[2] = local_4c;
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return 0;
}


