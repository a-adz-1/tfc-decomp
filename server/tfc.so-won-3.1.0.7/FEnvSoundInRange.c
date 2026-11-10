// FEnvSoundInRange__FP9entvars_sT0Pf  @ 000ee894
undefined4 FEnvSoundInRange__FP9entvars_sT0Pf(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined1 auStack_5c [8];
  int iStack_54;
  int iStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar3 = GetClassPtr__H1Z9CEnvSound_PX01_PX01(param_1);
  fStack_c = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x174);
  fStack_8 = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x178);
  fStack_4 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x17c);
  fStack_18 = *(float *)(param_2 + 8) + *(float *)(param_2 + 0x174);
  fStack_14 = *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0x178);
  fStack_10 = *(float *)(param_2 + 0x10) + *(float *)(param_2 + 0x17c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_c,&fStack_18,1,*(undefined4 *)(param_1 + 0x208),auStack_5c);
  if (((iStack_54 == 0) || (iStack_50 == 0)) &&
     ((byte)((byte)((ushort)((ushort)NAN(fStack_4c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_4c == 1.0) << 0xe) >> 8)) == 0x40)) {
    fVar2 = SQRT((fStack_40 - fStack_4) * (fStack_40 - fStack_4) +
                 (fStack_44 - fStack_8) * (fStack_44 - fStack_8) +
                 (fStack_48 - fStack_c) * (fStack_48 - fStack_c));
    fVar1 = *(float *)(iVar3 + 0x448);
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


