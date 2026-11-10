// ExplodeTouch__8CGrenadeP11CBaseEntity  @ 000b1cbc
void ExplodeTouch__8CGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [56];
  
  *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_2 + 0x208);
  iVar2 = *param_1;
  local_60 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                  *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                  *(float *)(*param_1 + 0x20) * *(float *)(*param_1 + 0x20));
  if ((byte)((byte)((ushort)((ushort)NAN(local_60) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_60 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_68 = 0.0;
    local_64 = 0.0;
    local_60 = 1.0;
  }
  else {
    local_60 = 1.0 / local_60;
    local_68 = local_60 * *(float *)(iVar2 + 0x20);
    local_64 = local_60 * *(float *)(iVar2 + 0x24);
    local_60 = local_60 * *(float *)(iVar2 + 0x28);
  }
  iVar2 = *param_1;
  local_44 = *(float *)(iVar2 + 8) - local_68 * 32.0;
  local_40 = *(float *)(iVar2 + 0xc) - local_64 * 32.0;
  local_3c = *(float *)(iVar2 + 0x10) - local_60 * 32.0;
  local_48 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                  *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                  *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
  if ((byte)((byte)((ushort)((ushort)NAN(local_48) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_48 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_54 = 0.0;
    local_50 = 0.0;
    local_4c = 1.0;
  }
  else {
    local_4c = 1.0 / local_48;
    local_54 = local_4c * *(float *)(iVar2 + 0x20);
    local_50 = local_4c * *(float *)(iVar2 + 0x24);
    local_4c = local_4c * *(float *)(iVar2 + 0x28);
  }
  local_60 = local_54 * 64.0;
  local_5c = local_50 * 64.0;
  local_58 = local_4c * 64.0;
  local_6c = local_44 + local_60;
  local_68 = local_40 + local_5c;
  local_64 = local_3c + local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_44,&local_6c,1,*(undefined4 *)(*param_1 + 0x208),local_38);
  iVar2 = *param_1;
  if ((*(int *)(iVar2 + 0x198) != 0) && (iVar3 = *(int *)(iVar2 + 0x198) + 0x80, iVar3 != 0)) {
    fVar1 = *(float *)(*param_2 + 0x16c);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      (**(code **)(param_2[0x111] + 0x38))(param_2,iVar2,iVar3,*(undefined4 *)(iVar2 + 0x1e0),0x40);
    }
  }
  (**(code **)(param_1[0x111] + 0x220))(param_1,local_38,0x40);
  return;
}


