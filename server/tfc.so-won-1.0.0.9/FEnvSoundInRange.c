// FEnvSoundInRange__FP9entvars_tT0Pf  @ 000ec350
undefined4 FEnvSoundInRange__FP9entvars_tT0Pf(int param_1,int param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_60 [8];
  int local_58;
  int local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = GetClassPtr__H1Z9CEnvSound_PX01_PX01(param_1);
  local_10 = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x154);
  local_c = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x158);
  local_8 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x15c);
  local_1c = *(float *)(param_2 + 8) + *(float *)(param_2 + 0x154);
  local_18 = *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0x158);
  local_14 = *(float *)(param_2 + 0x10) + *(float *)(param_2 + 0x15c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_10,&local_1c,1,*(undefined4 *)(param_1 + 0x1e8),local_60);
  if ((((local_58 != 0) && (local_54 != 0)) ||
      ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) != 0x40)) ||
     (fVar1 = SQRT((local_44 - local_8) * (local_44 - local_8) +
                   (local_48 - local_c) * (local_48 - local_c) +
                   (local_4c - local_10) * (local_4c - local_10)), *(float *)(iVar2 + 0x3cc) < fVar1
     )) {
    uVar3 = 0;
  }
  else {
    if (param_3 != (float *)0x0) {
      *param_3 = fVar1;
    }
    uVar3 = 1;
  }
  return uVar3;
}


