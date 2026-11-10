// BounceGibTouch__4CGibP11CBaseEntity  @ 000a5120
void BounceGibTouch__4CGibP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [56];
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x185) & 2) == 0) {
    if (((g_Language != 1) && (0 < param_1[0xf4])) && (param_1[0xf3] != -1)) {
      iVar2 = *param_1;
      local_10 = *(float *)(iVar2 + 8) + 0.0;
      local_c = *(float *)(iVar2 + 0xc) + 0.0;
      local_8 = *(float *)(iVar2 + 0x10) + 8.0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0xc1c00000;
      local_60 = local_10 + 0.0;
      local_5c = local_c + 0.0;
      local_58 = local_8 + -24.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_10,&local_60,1,*(undefined4 *)(iVar2 + 0x1e8),local_48);
      UTIL_BloodDecalTrace__FP11TraceResulti(local_48,param_1[0xf3]);
      param_1[0xf4] = param_1[0xf4] + -1;
    }
    if (param_1[0xf5] != 9) {
      iVar2 = (*DAT_00175628)(0,2);
      if (iVar2 == 0) {
        fVar1 = ABS(*(float *)(*param_1 + 0x28)) / 450.0;
        if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
          fVar1 = 0.8;
        }
        else {
          fVar1 = (ABS(*(float *)(*param_1 + 0x28)) / 450.0) * 0.8;
        }
        MaterialSoundRandom__10CBreakableP7edict_s9Materialsf
                  (*(undefined4 *)(*param_1 + 0x1e8),param_1[0xf5],fVar1);
      }
    }
  }
  else {
    *(float *)(iVar2 + 0x20) = *(float *)(iVar2 + 0x20) * 0.9;
    *(float *)(iVar2 + 0x24) = *(float *)(iVar2 + 0x24) * 0.9;
    *(float *)(iVar2 + 0x28) = *(float *)(iVar2 + 0x28) * 0.9;
    *(undefined4 *)(*param_1 + 0x50) = 0;
    *(undefined4 *)(*param_1 + 0x58) = 0;
    *(undefined4 *)(*param_1 + 0x5c) = 0;
    *(undefined4 *)(*param_1 + 100) = 0;
  }
  return;
}


