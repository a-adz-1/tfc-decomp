// BounceGibTouch__4CGibP11CBaseEntity  @ 00095f50
void BounceGibTouch__4CGibP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [56];
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a5) & 2) == 0) {
    if (((g_Language != 1) && (0 < param_1[0x117])) && (param_1[0x116] != -1)) {
      local_8 = *(float *)(iVar2 + 0x10) + 8.0;
      local_60 = *(undefined4 *)(iVar2 + 8);
      local_5c = *(undefined4 *)(iVar2 + 0xc);
      local_4c = 0xc1c00000;
      local_58 = local_8 + -24.0;
      local_54 = 0;
      local_50 = 0;
      local_10 = local_60;
      local_c = local_5c;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_10,&local_60,1,*(undefined4 *)(iVar2 + 0x208),local_48);
      UTIL_BloodDecalTrace__FP11TraceResulti(local_48,param_1[0x116]);
      param_1[0x117] = param_1[0x117] + -1;
    }
    if (param_1[0x118] != 9) {
      iVar2 = (*DAT_0019f808)(0,2);
      if (iVar2 == 0) {
        if (ABS(*(float *)(*param_1 + 0x28)) * 0.0022222223 <= 1.0) {
          fVar1 = ABS(*(float *)(*param_1 + 0x28)) * 0.0017777778;
        }
        else {
          fVar1 = 0.8;
        }
        MaterialSoundRandom__10CBreakableP7edict_s9Materialsf
                  (*(undefined4 *)(*param_1 + 0x208),param_1[0x118],fVar1);
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


