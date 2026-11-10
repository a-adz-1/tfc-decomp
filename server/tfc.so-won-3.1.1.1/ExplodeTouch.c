// ExplodeTouch__8CGrenadeP11CBaseEntity  @ 000b110c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ExplodeTouch__8CGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [56];
  
  *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_2 + 0x208);
  iVar2 = *param_1;
  local_64 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                  *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                  *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
  if ((byte)((byte)((ushort)((ushort)NAN(local_64) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_64 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_6c = 0.0;
    local_68 = 0.0;
    local_64 = 1.0;
  }
  else {
    local_64 = 1.0 / local_64;
    local_6c = *(float *)(iVar2 + 0x20) * local_64;
    local_68 = *(float *)(iVar2 + 0x24) * local_64;
    local_64 = local_64 * *(float *)(iVar2 + 0x28);
  }
  iVar2 = *param_1;
  fStack_48 = *(float *)(iVar2 + 8) - local_6c * _FUN_0014c1a0;
  fStack_44 = *(float *)(iVar2 + 0xc) - local_68 * _FUN_0014c1a0;
  fStack_40 = *(float *)(iVar2 + 0x10) - _FUN_0014c1a0 * local_64;
  fStack_4c = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                   *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                   *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_4c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_4c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_58 = 0.0;
    fStack_54 = 0.0;
    fStack_50 = 1.0;
  }
  else {
    fStack_50 = 1.0 / fStack_4c;
    local_58 = *(float *)(iVar2 + 0x20) * fStack_50;
    fStack_54 = *(float *)(iVar2 + 0x24) * fStack_50;
    fStack_50 = fStack_50 * *(float *)(iVar2 + 0x28);
  }
  local_64 = local_58 * 64.0;
  local_70 = local_64 + fStack_48;
  local_60 = fStack_54 * 64.0;
  local_6c = local_60 + fStack_44;
  local_5c = fStack_50 * 64.0;
  local_68 = local_5c + fStack_40;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_48,&local_70,1,*(undefined4 *)(*param_1 + 0x208),auStack_3c);
  iVar2 = *param_1;
  if (((*(int *)(iVar2 + 0x198) != 0) && (iVar3 = *(int *)(iVar2 + 0x198) + 0x80, iVar3 != 0)) &&
     (fVar1 = *(float *)(*param_2 + 0x16c),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    (**(code **)(param_2[0x115] + 0x38))(param_2,iVar2,iVar3,*(undefined4 *)(iVar2 + 0x1e0),0x40);
  }
  (**(code **)(param_1[0x115] + 0x220))(param_1,auStack_3c,0x40);
  return;
}


