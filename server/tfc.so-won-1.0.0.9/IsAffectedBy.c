// IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1  @ 00109eb0
undefined4 IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(int *param_1,int *param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_4c [16];
  float local_3c;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_2[0xb] == 0) {
LAB_0010a06c:
    uVar4 = 0;
  }
  else {
    if ((*(byte *)(param_1 + 0x89) & 0x20) != 0) {
      iVar2 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
      iVar3 = UTIL_PointContents__FRC6Vector(*param_2 + 8);
      if (iVar3 != iVar2) goto LAB_0010a06c;
    }
    fVar1 = (float)param_1[0x94];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_00109fb0:
      iVar2 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
      if (iVar2 != 0x81) {
        iVar2 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
        if (((((iVar2 == 0x83) && (param_2 == param_3)) ||
             (((*(byte *)(param_1 + 0x89) & 1) != 0 && (param_2 == param_3)))) ||
            ((((*(byte *)(param_1 + 0x89) & 2) != 0 && (param_3[0x48] == param_2[0x48])) ||
             (((*(byte *)(param_1 + 0x89) & 4) != 0 && (param_3[0x48] != param_2[0x48])))))) ||
           (((*(byte *)(param_1 + 0x89) & 8) != 0 && (param_2 != param_3)))) goto LAB_00109f98;
      }
      if (((param_1[0x30] == 0) || (param_2[0x48] != param_1[0x30])) &&
         ((param_1[0x34] == 0 || (param_2[0x48] == param_1[0x30])))) goto LAB_0010a06c;
    }
    else {
      iVar2 = *param_1;
      iVar3 = *param_2;
      local_10 = *(float *)(iVar2 + 8) - *(float *)(*param_2 + 8);
      local_c = *(float *)(iVar2 + 0xc) - *(float *)(iVar3 + 0xc);
      local_8 = *(float *)(iVar2 + 0x10) - *(float *)(iVar3 + 0x10);
      local_14 = SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10);
      fVar1 = (float)param_1[0x94];
      if (0x3f < (byte)((local_14 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(local_14) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_14 == fVar1) << 0xe) >> 8)) - 1))
      goto LAB_00109fb0;
      if ((*(byte *)(param_1 + 0x89) & 0x10) != 0) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (iVar2 + 8,iVar3 + 8,0,*(undefined4 *)(iVar2 + 0x1e8),local_4c);
        if ((byte)((byte)((ushort)((ushort)NAN(local_3c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_3c == 1.0) << 0xe) >> 8)) != 0x40)
        goto LAB_00109fb0;
      }
    }
LAB_00109f98:
    uVar4 = 1;
  }
  return uVar4;
}


