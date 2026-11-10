// CheckArea__11CBaseEntityP11CBaseEntity  @ 0009bf84
undefined4 CheckArea__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  int local_38 [4];
  float fStack_28;
  int iStack_8;
  
  iVar2 = *param_1;
  local_44 = *(float *)(iVar2 + 8);
  local_40 = *(float *)(iVar2 + 0xc);
  local_3c = *(float *)(iVar2 + 0x10);
  iVar2 = UTIL_PointContents__FRC6Vector(&local_44);
  if ((iVar2 == -1) || (iVar2 == -3)) {
    iVar2 = *param_2;
    local_50 = *(undefined4 *)(iVar2 + 8);
    local_4c = *(undefined4 *)(iVar2 + 0xc);
    local_48 = *(float *)(iVar2 + 0x10);
    if ((*(byte *)(iVar2 + 0x1a5) & 0x40) != 0) {
      local_80 = -16.0;
      local_6c = 0xc1900000;
      local_78 = -36.0;
      local_68 = 0;
      local_64 = 0;
      local_60 = 0x41900000;
      local_54 = local_48 + 18.0;
      local_7c = local_80;
      local_74 = local_80;
      local_70 = local_80;
      local_5c = local_50;
      local_58 = local_4c;
      local_48 = local_54;
    }
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_50,*param_1 + 8,1,2,*(undefined4 *)(*param_1 + 0x208),local_38);
    if (iStack_8 == 0) {
      (*DAT_001a7f54)(0);
    }
    if (((byte)((byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
               (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40) &&
       (local_38[0] != 1)) {
      piVar3 = (int *)0x0;
      do {
        piVar3 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                  (piVar3,*param_1 + 8,0x42400000);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
          do {
            piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"func_nobuild");
            if (piVar3 == (int *)0x0) {
              local_6c = 0xc2800000;
              local_74 = 0.0;
              local_70 = 0.0;
              local_78 = local_3c + -64.0;
              local_80 = local_44;
              local_7c = local_40;
              UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (&local_44,&local_80,0,*(undefined4 *)(*param_1 + 0x208),local_38);
              if ((byte)(1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40) {
                return 1;
              }
              return 0;
            }
            iVar2 = *piVar3;
            fVar1 = *(float *)(iVar2 + 0xdc);
          } while ((((((byte)(local_44 < fVar1 |
                              (byte)((ushort)((ushort)(NAN(local_44) || NAN(fVar1)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(local_44 == fVar1) << 0xe) >> 8)) == 1) ||
                     (fVar1 = *(float *)(iVar2 + 0xe0),
                     (byte)(local_40 < fVar1 |
                            (byte)((ushort)((ushort)(NAN(local_40) || NAN(fVar1)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(local_40 == fVar1) << 0xe) >> 8)) == 1)) ||
                    (fVar1 = *(float *)(iVar2 + 0xe4),
                    (byte)(local_3c < fVar1 |
                           (byte)((ushort)((ushort)(NAN(local_3c) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(local_3c == fVar1) << 0xe) >> 8)) == 1)) ||
                   ((*(float *)(iVar2 + 0xe8) < local_44 || (*(float *)(iVar2 + 0xec) < local_40))))
                  || (fVar1 = *(float *)(iVar2 + 0xf0),
                     0x3f < (byte)((local_3c < fVar1 |
                                    (byte)((ushort)((ushort)(NAN(local_3c) || NAN(fVar1)) << 10) >>
                                          8) |
                                   (byte)((ushort)((ushort)(local_3c == fVar1) << 0xe) >> 8)) - 1)))
          ;
          return 2;
        }
      } while (((piVar3 == param_2) || (piVar3 == param_1)) || (*(int *)(*piVar3 + 0x10c) < 2));
    }
  }
  return 1;
}


