// CheckArea__11CBaseEntityP11CBaseEntity  @ 000b0e90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CheckArea__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  float local_84;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  int local_3c [4];
  float local_2c;
  int local_c;
  
  iVar2 = *param_1;
  local_48 = *(float *)(iVar2 + 8);
  local_44 = *(float *)(iVar2 + 0xc);
  local_40 = *(float *)(iVar2 + 0x10);
  iVar2 = UTIL_PointContents__FRC6Vector(&local_48);
  if ((iVar2 == -1) || (iVar2 == -3)) {
    iVar2 = *param_2;
    local_54 = *(float *)(iVar2 + 8);
    local_50 = *(float *)(iVar2 + 0xc);
    local_4c = *(float *)(iVar2 + 0x10);
    if ((*(byte *)(iVar2 + 0x185) & 0x40) != 0) {
      local_78 = 0xc1800000;
      local_74 = 0xc1800000;
      local_70 = _FUN_001300a8;
      local_84 = -16.0;
      local_80 = -16.0;
      local_7c = -36.0;
      local_6c = 0;
      local_68 = 0;
      local_64 = 0x41900000;
      local_60 = local_54 + 0.0;
      local_5c = local_50 + 0.0;
      local_58 = local_4c + 18.0;
      local_54 = local_60;
      local_50 = local_5c;
      local_4c = local_58;
    }
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_54,*param_1 + 8,1,2,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
    if (local_c == 0) {
      (*DAT_001755d4)(0);
    }
    if (((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) &&
       (local_3c[0] != 1)) {
      piVar3 = (int *)0x0;
      do {
        piVar3 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                  (piVar3,*param_1 + 8,0x42400000);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
          do {
            piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"func_nobuild");
            if (piVar3 == (int *)0x0) {
              local_78 = 0;
              local_74 = 0;
              local_70 = 0xc2800000;
              local_84 = local_48 + 0.0;
              local_80 = local_44 + 0.0;
              local_7c = local_40 + -64.0;
              UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (&local_48,&local_84,0,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
              if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
                return 1;
              }
              return 0;
            }
            iVar2 = *piVar3;
          } while (((((local_48 < *(float *)(iVar2 + 0xbc)) || (local_44 < *(float *)(iVar2 + 0xc0))
                     ) || (local_40 < *(float *)(iVar2 + 0xc4))) ||
                   ((fVar1 = *(float *)(iVar2 + 200),
                    0x3f < (byte)((local_48 < fVar1 |
                                   (byte)((ushort)((ushort)(NAN(local_48) || NAN(fVar1)) << 10) >> 8
                                         ) |
                                  (byte)((ushort)((ushort)(local_48 == fVar1) << 0xe) >> 8)) - 1) ||
                    (fVar1 = *(float *)(iVar2 + 0xcc),
                    0x3f < (byte)((local_44 < fVar1 |
                                   (byte)((ushort)((ushort)(NAN(local_44) || NAN(fVar1)) << 10) >> 8
                                         ) |
                                  (byte)((ushort)((ushort)(local_44 == fVar1) << 0xe) >> 8)) - 1))))
                   ) || (fVar1 = *(float *)(iVar2 + 0xd0),
                        0x3f < (byte)((local_40 < fVar1 |
                                       (byte)((ushort)((ushort)(NAN(local_40) || NAN(fVar1)) << 10)
                                             >> 8) |
                                      (byte)((ushort)((ushort)(local_40 == fVar1) << 0xe) >> 8)) - 1
                                     )));
          return 2;
        }
      } while (((piVar3 == param_2) || (piVar3 == param_1)) || (*(int *)(*piVar3 + 0xec) < 2));
    }
  }
  return 1;
}


