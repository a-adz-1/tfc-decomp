// FBoxVisible__FP9entvars_sT0R6Vectorf  @ 000a7b88
undefined4
FBoxVisible__FP9entvars_sT0R6Vectorf(int param_1,int param_2,float *param_3,float param_4)

{
  int iVar1;
  longdouble lVar2;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [16];
  float local_28;
  
  if (*(int *)(param_1 + 0x1c0) != 3) {
    if (*(int *)(param_2 + 0x1c0) == 3) {
      return 0;
    }
    if (*(int *)(param_1 + 0x1c0) != 3) goto LAB_000a7bfc;
  }
  if (*(int *)(param_2 + 0x1c0) == 0) {
    return 0;
  }
LAB_000a7bfc:
  local_44 = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x174);
  local_40 = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x178);
  local_3c = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x17c);
  iVar1 = 0;
  do {
    local_50 = *(float *)(param_2 + 8);
    local_4c = *(float *)(param_2 + 0xc);
    local_48 = *(float *)(param_2 + 0x10);
    lVar2 = (longdouble)
            (*DAT_001a7fac)(param_4 + *(float *)(param_2 + 0xdc),
                            *(float *)(param_2 + 0xe8) - param_4);
    local_50 = (float)(lVar2 + (longdouble)local_50);
    lVar2 = (longdouble)
            (*DAT_001a7fac)(param_4 + *(float *)(param_2 + 0xe0),
                            *(float *)(param_2 + 0xec) - param_4);
    local_4c = (float)(lVar2 + (longdouble)local_4c);
    lVar2 = (longdouble)
            (*DAT_001a7fac)(param_4 + *(float *)(param_2 + 0xe4),
                            *(float *)(param_2 + 0xf0) - param_4);
    local_48 = (float)(lVar2 + (longdouble)local_48);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&local_44,&local_50,1,1,*(undefined4 *)(param_1 + 0x208),local_38);
    if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) == 0x40) {
      *param_3 = local_50;
      param_3[1] = local_4c;
      param_3[2] = local_48;
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return 0;
}


