// PlayerTouch__11CBasePlayerP11CBaseEntity  @ 000d85d8
void PlayerTouch__11CBasePlayerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  float local_60;
  float local_5c;
  float local_58;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [48];
  int local_c;
  float local_4;
  
  iVar4 = (**(code **)(param_2[0xf5] + 0x28))(param_2);
  if (iVar4 != 2) {
    return;
  }
  if ((*(int *)(*param_1 + 0x20c) == 8) || (*(int *)(*param_2 + 0x20c) == 8)) {
    CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(param_1,param_2);
    CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(param_2,param_1);
  }
  iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
  if (iVar4 == 0) {
    return;
  }
  fVar1 = *(float *)(*param_2 + 0x24);
  fVar5 = *(float *)(*param_2 + 0x28);
  fVar1 = SQRT(fVar5 * fVar5 +
               fVar1 * fVar1 + *(float *)(*param_2 + 0x20) * *(float *)(*param_2 + 0x20));
  if ((byte)((50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 50.0) << 0xe) >> 8)) - 1) < 0x40) {
    return;
  }
  fVar1 = *(float *)(*param_1 + 0x24);
  fVar5 = *(float *)(*param_1 + 0x28);
  local_4 = SQRT(fVar5 * fVar5 +
                 fVar1 * fVar1 + *(float *)(*param_1 + 0x20) * *(float *)(*param_1 + 0x20));
  if (((byte)(55.0 < local_4 | (byte)((ushort)((ushort)NAN(local_4) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_4 == 55.0) << 0xe) >> 8)) != 1) &&
     ((*(byte *)((int)param_1 + 0x8a) & 6) == 0)) {
    return;
  }
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
  iVar4 = *param_1;
  local_48 = *(float *)(iVar4 + 8) + *(float *)(gpGlobals + 0x28) * 24.0;
  local_44 = *(float *)(iVar4 + 0xc) + *(float *)(gpGlobals + 0x2c) * 24.0;
  local_40 = *(float *)(iVar4 + 0x10) + *(float *)(gpGlobals + 0x30) * 24.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar4 + 8,&local_48,0,*(undefined4 *)(iVar4 + 0x208),local_3c);
  bVar3 = false;
  if ((local_c == 0) || (iVar4 = (*DAT_001a7f58)(local_c), iVar4 == 0)) {
    bVar3 = true;
  }
  if (!bVar3) {
    if ((local_c == 0) && (local_c = (*DAT_001a7f54)(0), local_c == 0)) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(local_c + 0x7c);
    }
    if (piVar6 == param_2) {
      if ((*(byte *)((int)param_1 + 0x8a) & 6) == 0) {
        if ((*(byte *)((int)param_2 + 0x8a) & 6) != 0) {
          return;
        }
        iVar4 = *param_2;
        iVar2 = *param_1;
        local_40 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                        *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                        *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
        if ((byte)((byte)((ushort)((ushort)NAN(local_40) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_40 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_48 = 0.0;
          local_44 = 0.0;
          local_40 = 1.0;
        }
        else {
          local_40 = 1.0 / local_40;
          local_48 = local_40 * *(float *)(iVar2 + 0x20);
          local_44 = local_40 * *(float *)(iVar2 + 0x24);
          local_40 = local_40 * *(float *)(iVar2 + 0x28);
        }
        iVar2 = *param_2;
        fVar1 = *(float *)(iVar2 + 0x24);
        fVar5 = *(float *)(iVar2 + 0x28) + local_40 * 30.0;
        *(float *)(iVar4 + 0x20) = *(float *)(iVar2 + 0x20) + local_48 * 30.0;
        *(float *)(iVar4 + 0x24) = fVar1 + local_44 * 30.0;
      }
      else {
        iVar4 = *param_2;
        iVar2 = *param_1;
        local_58 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                        *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                        *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
        if ((byte)((byte)((ushort)((ushort)NAN(local_58) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_58 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_60 = 0.0;
          local_5c = 0.0;
          local_58 = 1.0;
        }
        else {
          local_58 = 1.0 / local_58;
          local_60 = local_58 * *(float *)(iVar2 + 0x20);
          local_5c = local_58 * *(float *)(iVar2 + 0x24);
          local_58 = local_58 * *(float *)(iVar2 + 0x28);
        }
        iVar2 = *param_2;
        fVar1 = *(float *)(iVar2 + 0x24);
        fVar5 = *(float *)(iVar2 + 0x28) + local_58 * 120.0;
        *(float *)(iVar4 + 0x20) = *(float *)(iVar2 + 0x20) + local_60 * 120.0;
        *(float *)(iVar4 + 0x24) = fVar1 + local_5c * 120.0;
      }
      *(float *)(iVar4 + 0x28) = fVar5;
    }
    return;
  }
  return;
}


