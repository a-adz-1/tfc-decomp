// FEnvSoundInRange__FP9entvars_sT0Pf  @ 000e1e68
undefined4 FEnvSoundInRange__FP9entvars_sT0Pf(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 local_5c [8];
  int local_54;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = GetClassPtr__H1Z9CEnvSound_PX01_PX01(param_1);
  local_c = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x174);
  local_8 = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x178);
  local_4 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x17c);
  local_18 = *(float *)(param_2 + 8) + *(float *)(param_2 + 0x174);
  local_14 = *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0x178);
  local_10 = *(float *)(param_2 + 0x10) + *(float *)(param_2 + 0x17c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_c,&local_18,1,*(undefined4 *)(param_1 + 0x208),local_5c);
  if (((local_54 == 0) || (local_50 == 0)) &&
     ((byte)((byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_4c == 1.0) << 0xe) >> 8)) == 0x40)) {
    fVar2 = SQRT((local_40 - local_4) * (local_40 - local_4) +
                 (local_44 - local_8) * (local_44 - local_8) +
                 (local_48 - local_c) * (local_48 - local_c));
    fVar1 = *(float *)(iVar3 + 0x3d8);
    if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      if (param_3 != (float *)0x0) {
        *param_3 = fVar2;
      }
      return 1;
    }
  }
  return 0;
}


