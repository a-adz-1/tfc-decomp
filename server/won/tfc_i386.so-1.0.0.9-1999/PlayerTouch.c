// PlayerTouch__11CBasePlayerP11CBaseEntity  @ 000e3ef0
void PlayerTouch__11CBasePlayerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  float local_64;
  float local_60;
  float local_5c;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [48];
  int local_10;
  float local_8;
  
  iVar4 = (**(code **)(param_2[0xf2] + 0x28))(param_2);
  if (iVar4 != 2) {
    return;
  }
  if ((param_1[0xb] == 8) || (param_2[0xb] == 8)) {
    CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(param_1,param_2);
    CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(param_2,param_1);
  }
  iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
  if (iVar4 == 0) {
    return;
  }
  fVar1 = *(float *)(*param_2 + 0x24);
  fVar5 = *(float *)(*param_2 + 0x28);
  if (50.0 <= SQRT(fVar5 * fVar5 +
                   fVar1 * fVar1 + *(float *)(*param_2 + 0x20) * *(float *)(*param_2 + 0x20))) {
    return;
  }
  fVar1 = *(float *)(*param_1 + 0x24);
  fVar5 = *(float *)(*param_1 + 0x28);
  local_8 = SQRT(fVar5 * fVar5 +
                 fVar1 * fVar1 + *(float *)(*param_1 + 0x20) * *(float *)(*param_1 + 0x20));
  if (((byte)(55.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_8 == 55.0) << 0xe) >> 8)) != 1) &&
     ((*(byte *)((int)param_1 + 0x8e) & 6) == 0)) {
    return;
  }
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
  iVar4 = *param_1;
  local_4c = *(float *)(iVar4 + 8) + *(float *)(gpGlobals + 0x28) * 24.0;
  local_48 = *(float *)(iVar4 + 0xc) + *(float *)(gpGlobals + 0x2c) * 24.0;
  local_44 = *(float *)(iVar4 + 0x10) + *(float *)(gpGlobals + 0x30) * 24.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar4 + 8,&local_4c,0,*(undefined4 *)(iVar4 + 0x1e8),local_40);
  bVar3 = false;
  if ((local_10 == 0) || (iVar4 = (*DAT_001755d8)(local_10), iVar4 == 0)) {
    bVar3 = true;
  }
  if (!bVar3) {
    if ((local_10 == 0) && (local_10 = (*DAT_001755d4)(0), local_10 == 0)) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(local_10 + 0xd8);
    }
    if (piVar6 == param_2) {
      if ((*(byte *)((int)param_1 + 0x8e) & 6) == 0) {
        if ((*(byte *)((int)param_2 + 0x8e) & 6) != 0) {
          return;
        }
        iVar4 = *param_2;
        iVar2 = *param_1;
        local_44 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                        *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                        *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
        if ((byte)((byte)((ushort)((ushort)NAN(local_44) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_44 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_4c = 0.0;
          local_48 = 0.0;
          local_44 = 1.0;
        }
        else {
          local_44 = 1.0 / local_44;
          local_4c = local_44 * *(float *)(iVar2 + 0x20);
          local_48 = local_44 * *(float *)(iVar2 + 0x24);
          local_44 = local_44 * *(float *)(iVar2 + 0x28);
        }
        iVar2 = *param_2;
        fVar1 = *(float *)(iVar2 + 0x24);
        fVar5 = *(float *)(iVar2 + 0x28) + local_44 * 30.0;
        *(float *)(iVar4 + 0x20) = *(float *)(iVar2 + 0x20) + local_4c * 30.0;
        *(float *)(iVar4 + 0x24) = fVar1 + local_48 * 30.0;
      }
      else {
        iVar4 = *param_2;
        iVar2 = *param_1;
        local_5c = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                        *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                        *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
        if ((byte)((byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_5c == 0.0) << 0xe) >> 8)) == 0x40) {
          local_64 = 0.0;
          local_60 = 0.0;
          local_5c = 1.0;
        }
        else {
          local_5c = 1.0 / local_5c;
          local_64 = local_5c * *(float *)(iVar2 + 0x20);
          local_60 = local_5c * *(float *)(iVar2 + 0x24);
          local_5c = local_5c * *(float *)(iVar2 + 0x28);
        }
        iVar2 = *param_2;
        fVar1 = *(float *)(iVar2 + 0x24);
        fVar5 = *(float *)(iVar2 + 0x28) + local_5c * 120.0;
        *(float *)(iVar4 + 0x20) = *(float *)(iVar2 + 0x20) + local_64 * 120.0;
        *(float *)(iVar4 + 0x24) = fVar1 + local_60 * 120.0;
      }
      *(float *)(iVar4 + 0x28) = fVar5;
    }
    return;
  }
  return;
}


