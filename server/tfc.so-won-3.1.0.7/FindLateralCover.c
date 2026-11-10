// FindLateralCover__12CBaseMonsterRC6VectorT1  @ 000c1464
undefined4 FindLateralCover__12CBaseMonsterRC6VectorT1(int *param_1,float *param_2,float *param_3)

{
  int iVar1;
  int local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined1 local_38 [16];
  float local_28;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_74 = *(float *)(gpGlobals + 0x40) * 48.0;
  local_70 = *(float *)(gpGlobals + 0x44) * 48.0;
  local_6c = 0.0;
  iVar1 = *param_1;
  local_68 = *(float *)(iVar1 + 8);
  local_64 = *(float *)(iVar1 + 0xc);
  local_60 = *(float *)(iVar1 + 0x10);
  local_90 = 0;
  local_5c = local_68;
  local_58 = local_64;
  local_54 = local_60;
  do {
    local_5c = local_5c - local_74;
    local_58 = local_58 - local_70;
    local_54 = local_54 - local_6c;
    local_68 = local_68 + local_74;
    local_64 = local_64 + local_70;
    local_60 = local_60 + local_6c;
    iVar1 = *param_1;
    local_80 = local_5c + *(float *)(iVar1 + 0x174);
    local_7c = local_58 + *(float *)(iVar1 + 0x178);
    local_78 = local_54 + *(float *)(iVar1 + 0x17c);
    local_8c = *param_2 + *param_3;
    local_88 = param_2[1] + param_3[1];
    local_84 = param_2[2] + param_3[2];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&local_8c,&local_80,1,1,*(undefined4 *)(iVar1 + 0x208),local_38);
    if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar1 = (**(code **)(param_1[0x111] + 0x1b4))(param_1,&local_5c);
      if (((iVar1 != 0) &&
          (iVar1 = (**(code **)(param_1[0x111] + 0x140))(param_1,*param_1 + 8,&local_5c,0,0),
          iVar1 == 2)) &&
         (iVar1 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,4,0,&local_5c),
         iVar1 != 0)) {
        return 1;
      }
    }
    iVar1 = *param_1;
    local_8c = local_68 + *(float *)(iVar1 + 0x174);
    local_88 = local_64 + *(float *)(iVar1 + 0x178);
    local_84 = local_60 + *(float *)(iVar1 + 0x17c);
    local_80 = *param_2 + *param_3;
    local_7c = param_2[1] + param_3[1];
    local_78 = param_2[2] + param_3[2];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&local_80,&local_8c,1,1,*(undefined4 *)(iVar1 + 0x208),local_38);
    if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar1 = (**(code **)(param_1[0x111] + 0x1b4))(param_1,&local_68);
      if (((iVar1 != 0) &&
          (iVar1 = (**(code **)(param_1[0x111] + 0x140))(param_1,*param_1 + 8,&local_68,0,0),
          iVar1 == 2)) &&
         (iVar1 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,4,0,&local_68),
         iVar1 != 0)) {
        return 1;
      }
    }
    local_90 = local_90 + 1;
    if (4 < local_90) {
      return 0;
    }
  } while( true );
}


