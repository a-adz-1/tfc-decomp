// BounceGibTouch__4CGibP11CBaseEntity  @ 00096610
void BounceGibTouch__4CGibP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [56];
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a5) & 2) == 0) {
    if (((g_Language != 1) && (0 < param_1[0x113])) && (param_1[0x112] != -1)) {
      iVar2 = *param_1;
      local_5c = *(undefined4 *)(iVar2 + 8);
      local_58 = *(undefined4 *)(iVar2 + 0xc);
      local_4 = *(float *)(iVar2 + 0x10) + 8.0;
      local_48 = 0xc1c00000;
      local_50 = 0;
      local_4c = 0;
      local_54 = local_4 + -24.0;
      local_c = local_5c;
      local_8 = local_58;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_c,&local_5c,1,*(undefined4 *)(iVar2 + 0x208),local_44);
      UTIL_BloodDecalTrace__FP11TraceResulti(local_44,param_1[0x112]);
      param_1[0x113] = param_1[0x113] + -1;
    }
    if (param_1[0x114] != 9) {
      iVar2 = (*DAT_001c1188)(0,2);
      if (iVar2 == 0) {
        if (ABS(*(float *)(*param_1 + 0x28)) * 0.0022222223 <= 1.0) {
          fVar1 = ABS(*(float *)(*param_1 + 0x28)) * 0.0017777778;
        }
        else {
          fVar1 = 0.8;
        }
        MaterialSoundRandom__10CBreakableP7edict_s9Materialsf
                  (*(undefined4 *)(*param_1 + 0x208),param_1[0x114],fVar1);
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


