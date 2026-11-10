// PreThink__11CBasePlayer  @ 000dab60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PreThink__11CBasePlayer(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  float local_64;
  undefined1 local_48 [16];
  float local_38;
  int local_18;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = *param_1;
  uVar4 = param_1[0x18c] ^ *(uint *)(iVar3 + 0x160);
  param_1[0x18d] = *(uint *)(iVar3 + 0x160) & uVar4;
  param_1[0x18e] = uVar4 & ~*(uint *)(iVar3 + 0x160);
  if ((byte)((byte)((ushort)((ushort)(NAN(_FUN_00139fc4) || NAN((float)param_1[0x45])) << 10) >> 8)
            | (byte)((ushort)((ushort)(_FUN_00139fc4 == (float)param_1[0x45]) << 0xe) >> 8)) == 0x40
     ) {
    if (((*(uint *)(iVar3 + 0x160) & 0x2823) != 0) &&
       (ResetMenu__11CBasePlayer(param_1), param_1[0x261] != 1)) {
      (**(code **)(*g_pGameRules + 0xdc))(g_pGameRules,*(undefined4 *)(*param_1 + 0x1e8));
      param_1[0x261] = 1;
    }
  }
  else if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x45] == 2.0) << 0xe) >> 8)) == 0x40) &&
          ((*(byte *)(param_1 + 0x18d) & 2) != 0)) {
    ResetMenu__11CBasePlayer(param_1);
    TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1);
    *(byte *)(param_1 + 0x18d) = *(byte *)(param_1 + 0x18d) & 0xfd;
  }
  (**(code **)(*g_pGameRules + 0x54))(g_pGameRules,param_1);
  if (g_fGameOver != 0) {
    return;
  }
  if (((*(byte *)(*param_1 + 0x185) & 2) != 0) &&
     (((*(byte *)(param_1 + 0x19a) & 0x10) != 0 || ((*(byte *)(param_1 + 0x18d) & 0x20) != 0)))) {
    iVar3 = *param_1;
    local_10 = *(float *)(iVar3 + 0x20) * 0.3;
    local_c = *(float *)(iVar3 + 0x24) * 0.3;
    local_8 = *(float *)(iVar3 + 0x28) * 0.3;
    *(float *)(iVar3 + 0x20) = local_10;
    *(float *)(iVar3 + 0x24) = local_c;
    *(float *)(iVar3 + 0x28) = local_8;
    *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) & 0xef;
  }
  ItemPreFrame__11CBasePlayer(param_1);
  WaterMove__11CBasePlayer(param_1);
  *(byte *)(param_1 + 0x202) = *(byte *)(param_1 + 0x202) | 2;
  UpdateClientData__11CBasePlayer(param_1);
  CheckTimeBasedDamage__11CBasePlayer(param_1);
  if ((1 < *(int *)(*param_1 + 0x1a0)) &&
     (fVar2 = (float)param_1[0x72],
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"ambience/steamburst1.wav",0x3f800000,0x3f4ccccd,
               0,100);
    param_1[0x72] = 0;
  }
  if (*(int *)(*param_1 + 0x1a0) == 2) {
    CheckWaterJump__11CBasePlayer(param_1);
  }
  else if (*(int *)(*param_1 + 0x1a0) == 0) {
    pbVar1 = (byte *)(*param_1 + 0x185);
    *pbVar1 = *pbVar1 & 0xf7;
  }
  if (0 < *(int *)(*param_1 + 0x150)) {
    PlayerDeathThink__11CBasePlayer(param_1);
    return;
  }
  if ((*(byte *)(param_1 + 0x19a) & 2) == 0) {
    *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) & 0xfe;
  }
  else {
    *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) | 1;
  }
  if ((*(byte *)(param_1 + 0x19a) & 2) == 0) {
    if ((char)param_1[0x1f6] < '\0') {
      param_1[0x1f6] = 0xc0;
    }
LAB_000dafc3:
    if ((((((*(byte *)(*param_1 + 0x160) & 2) != 0) &&
          (iVar3 = IsOnLadder__11CBasePlayer(param_1), iVar3 == 0)) && (cease_fire == 0)) &&
        ((param_1[0x1b] == 0 && (param_1[0x1c] == 0)))) && (param_1[0x1d] == 0)) {
      (**(code **)(param_1[0xf2] + 0x214))(param_1);
    }
    if ((((*(byte *)(*param_1 + 0x160) & 4) != 0) || ((*(byte *)(*param_1 + 0x185) & 0x40) != 0)) ||
       ((*(byte *)(param_1 + 0x19a) & 8) != 0)) {
      (**(code **)(param_1[0xf2] + 0x218))(param_1);
    }
    UpdateStepSound__11CBasePlayer(param_1);
    if ((*(byte *)(*param_1 + 0x185) & 2) == 0) {
      param_1[0x192] = (int)-*(float *)(*param_1 + 0x28);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x11c,0);
    if ((*(byte *)(param_1 + 0x19a) & 4) != 0) {
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar3 + 0x24) = DAT_00175484;
      *(undefined4 *)(iVar3 + 0x28) = DAT_00175488;
    }
  }
  else {
    iVar3 = *(int *)(*param_1 + 0x17c);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(iVar3 + 0xd8);
    }
    if (piVar5 == (int *)0x0) {
      iVar3 = *param_1;
      local_10 = *(float *)(iVar3 + 8) + 0.0;
      local_c = *(float *)(iVar3 + 0xc) + 0.0;
      local_8 = *(float *)(iVar3 + 0x10) + -38.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (iVar3 + 8,&local_10,1,*(undefined4 *)(iVar3 + 0x1e8),local_48);
      if (((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (local_18 != 0)) {
        if ((local_18 == 0) && (local_18 = (*DAT_001755d4)(0), local_18 == 0)) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = *(int **)(local_18 + 0xd8);
        }
      }
      if (((piVar5 != (int *)0x0) &&
          (uVar4 = (**(code **)(piVar5[0xf2] + 0x1c))(piVar5), (uVar4 & 0x40) != 0)) &&
         (iVar3 = (**(code **)(piVar5[0xf2] + 0x80))(piVar5,*param_1), iVar3 != 0)) {
LAB_000daef0:
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x24) = DAT_00175484;
        *(undefined4 *)(iVar3 + 0x28) = DAT_00175488;
        local_64 = 0.0;
        if ((*(byte *)(param_1 + 0x18d) & 8) == 0) {
          if ((*(byte *)(param_1 + 0x18d) & 0x10) != 0) {
            local_64 = -1.0;
            goto LAB_000daf40;
          }
        }
        else {
          local_64 = 1.0;
LAB_000daf40:
          (**(code **)(piVar5[0xf2] + 0xb0))(piVar5,param_1,param_1,2,local_64);
        }
        if ((byte)(local_64 < 0.0 | (byte)((ushort)((ushort)NAN(local_64) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_64 == 0.0) << 0xe) >> 8)) != 0x40) {
          iVar3 = TrainSpeed__Fii((int)ROUND(*(float *)(*piVar5 + 0x1d8)),
                                  *(undefined4 *)(*piVar5 + 0x164));
          param_1[0x1f6] = iVar3;
          *(byte *)(param_1 + 0x1f6) = *(byte *)(param_1 + 0x1f6) | 0xc0;
        }
        goto LAB_000dafc3;
      }
    }
    else if ((((*(byte *)(*param_1 + 0x185) & 2) != 0) && ((*(byte *)(*piVar5 + 0x180) & 2) == 0))
            && ((*(byte *)(*param_1 + 0x161) & 6) == 0)) goto LAB_000daef0;
    *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) & 0xfd;
    param_1[0x1f6] = 0xc0;
  }
  return;
}


