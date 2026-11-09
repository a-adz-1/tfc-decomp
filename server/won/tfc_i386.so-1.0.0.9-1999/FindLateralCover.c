// FindLateralCover__12CBaseMonsterRC6VectorT1  @ 000c75c0
undefined4 FindLateralCover__12CBaseMonsterRC6VectorT1(int *param_1,float *param_2,float *param_3)

{
  int iVar1;
  int local_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
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
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_78 = *(float *)(gpGlobals + 0x40) * 48.0;
  local_74 = *(float *)(gpGlobals + 0x44) * 48.0;
  local_70 = 0.0;
  iVar1 = *param_1;
  local_6c = *(float *)(iVar1 + 8);
  local_68 = *(float *)(iVar1 + 0xc);
  local_64 = *(float *)(iVar1 + 0x10);
  local_94 = 0;
  local_60 = local_6c;
  local_5c = local_68;
  local_58 = local_64;
  do {
    local_60 = local_60 - local_78;
    local_5c = local_5c - local_74;
    local_58 = local_58 - local_70;
    local_6c = local_6c + local_78;
    local_68 = local_68 + local_74;
    local_64 = local_64 + local_70;
    iVar1 = *param_1;
    local_84 = local_60 + *(float *)(iVar1 + 0x154);
    local_80 = local_5c + *(float *)(iVar1 + 0x158);
    local_7c = local_58 + *(float *)(iVar1 + 0x15c);
    local_90 = *param_2 + *param_3;
    fStack_8c = param_2[1] + param_3[1];
    fStack_88 = param_2[2] + param_3[2];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&local_90,&local_84,1,1,*(undefined4 *)(iVar1 + 0x1e8),auStack_3c);
    if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar1 = (**(code **)(param_1[0xf2] + 0x1ac))(param_1,&local_60);
      if (((iVar1 != 0) &&
          (iVar1 = (**(code **)(param_1[0xf2] + 0x138))(param_1,*param_1 + 8,&local_60,0,0),
          iVar1 == 2)) &&
         (iVar1 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,4,0,&local_60),
         iVar1 != 0)) {
        return 1;
      }
    }
    iVar1 = *param_1;
    local_90 = local_6c + *(float *)(iVar1 + 0x154);
    fStack_8c = local_68 + *(float *)(iVar1 + 0x158);
    fStack_88 = local_64 + *(float *)(iVar1 + 0x15c);
    local_84 = *param_2 + *param_3;
    local_80 = param_2[1] + param_3[1];
    local_7c = param_2[2] + param_3[2];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&local_84,&local_90,1,1,*(undefined4 *)(iVar1 + 0x1e8),auStack_3c);
    if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar1 = (**(code **)(param_1[0xf2] + 0x1ac))(param_1,&local_6c);
      if (((iVar1 != 0) &&
          (iVar1 = (**(code **)(param_1[0xf2] + 0x138))(param_1,*param_1 + 8,&local_6c,0,0),
          iVar1 == 2)) &&
         (iVar1 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,4,0,&local_6c),
         iVar1 != 0)) {
        return 1;
      }
    }
    local_94 = local_94 + 1;
    if (4 < local_94) {
      return 0;
    }
  } while( true );
}


