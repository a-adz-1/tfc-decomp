// IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1  @ 0010996c
undefined4 IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(int *param_1,int *param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_48 [16];
  float local_38;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(*param_2 + 0x20c) == 0) {
LAB_00109b56:
    uVar4 = 0;
  }
  else {
    if ((*(byte *)(param_1 + 0x8b) & 0x20) != 0) {
      iVar2 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
      iVar3 = UTIL_PointContents__FRC6Vector(*param_2 + 8);
      if (iVar3 != iVar2) goto LAB_00109b56;
    }
    fVar1 = (float)param_1[0x96];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_00109a84:
      iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
      if ((iVar2 != 0x81) && (param_3 != (int *)0x0)) {
        iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
        if (((iVar2 == 0x83) && (param_2 == param_3)) ||
           ((((*(byte *)(param_1 + 0x8b) & 1) != 0 && (param_2 == param_3)) ||
            (((*(byte *)(param_1 + 0x8b) & 2) != 0 && (param_3[0x48] == param_2[0x48]))))))
        goto LAB_00109a78;
      }
      if ((((*(byte *)(param_1 + 0x8b) & 4) == 0) ||
          ((param_3 != (int *)0x0 && (param_3[0x48] == param_2[0x48])))) &&
         ((((*(byte *)(param_1 + 0x8b) & 8) == 0 || (param_2 == param_3)) &&
          (((param_1[0x30] == 0 || (param_2[0x48] != param_1[0x30])) &&
           ((param_1[0x34] == 0 || (param_2[0x48] == param_1[0x34])))))))) goto LAB_00109b56;
    }
    else {
      iVar2 = *param_1;
      iVar3 = *param_2;
      local_c = *(float *)(iVar2 + 8) - *(float *)(*param_2 + 8);
      local_8 = *(float *)(iVar2 + 0xc) - *(float *)(iVar3 + 0xc);
      local_4 = *(float *)(iVar2 + 0x10) - *(float *)(iVar3 + 0x10);
      local_10 = SQRT(local_4 * local_4 + local_8 * local_8 + local_c * local_c);
      if ((float)param_1[0x96] < local_10) goto LAB_00109a84;
      if ((*(byte *)(param_1 + 0x8b) & 0x10) != 0) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (iVar2 + 8,iVar3 + 8,0,*(undefined4 *)(iVar2 + 0x208),local_48);
        if ((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40)
        goto LAB_00109a84;
      }
    }
LAB_00109a78:
    uVar4 = 1;
  }
  return uVar4;
}


