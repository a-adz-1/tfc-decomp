// PreThink__11CBasePlayer  @ 000d7f1c
void PreThink__11CBasePlayer(int *param_1)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float local_68;
  int *local_64;
  undefined1 local_48 [16];
  float local_38;
  int local_18;
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = *param_1;
  uVar3 = *(uint *)(iVar2 + 0x180) ^ param_1[0x1b5];
  uVar4 = uVar3 & *(uint *)(iVar2 + 0x180);
  param_1[0x1b6] = uVar4;
  param_1[0x1b7] = uVar3 & ~*(uint *)(iVar2 + 0x180);
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x44] == 2.0) << 0xe) >> 8)) == 0x40) &&
     ((uVar4 & 2) != 0)) {
    ResetMenu__11CBasePlayer(param_1);
    TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1);
    *(byte *)(param_1 + 0x1b6) = *(byte *)(param_1 + 0x1b6) & 0xfd;
  }
  (**(code **)(*g_pGameRules + 0x54))(g_pGameRules,param_1);
  if (g_fGameOver != 0) {
    return;
  }
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x1a5) & 2) != 0) &&
     (((*(byte *)(param_1 + 0x1c3) & 0x10) != 0 || ((*(byte *)(param_1 + 0x1b6) & 0x20) != 0)))) {
    local_10 = *(float *)(iVar2 + 0x20) * 0.3;
    local_c = *(float *)(iVar2 + 0x24) * 0.3;
    local_8 = *(float *)(iVar2 + 0x28) * 0.3;
    *(float *)(iVar2 + 0x20) = local_10;
    *(float *)(iVar2 + 0x24) = local_c;
    *(float *)(iVar2 + 0x28) = local_8;
    *(byte *)(param_1 + 0x1c3) = *(byte *)(param_1 + 0x1c3) & 0xef;
  }
  ItemPreFrame__11CBasePlayer(param_1);
  WaterMove__11CBasePlayer(param_1);
  *(byte *)(param_1 + 0x22d) = *(byte *)(param_1 + 0x22d) | 2;
  UpdateClientData__11CBasePlayer(param_1);
  CheckTimeBasedDamage__11CBasePlayer(param_1);
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x244) != 0) {
    Observer_HandleButtons__11CBasePlayer(param_1);
    Observer_CheckTarget__11CBasePlayer(param_1);
    Observer_CheckProperties__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x184) = 0;
    return;
  }
  if ((1 < *(int *)(iVar2 + 0x1c0)) && (0.0 < (float)param_1[0x72])) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar2 + 0x208),3,"ambience/steamburst1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    param_1[0x72] = 0;
    iVar2 = *param_1;
  }
  if (0 < *(int *)(iVar2 + 0x170)) {
    PlayerDeathThink__11CBasePlayer(param_1);
    return;
  }
  if ((*(byte *)(param_1 + 0x1c3) & 2) == 0) {
    *(byte *)(iVar2 + 0x1a7) = *(byte *)(iVar2 + 0x1a7) & 0xfe;
  }
  else {
    *(byte *)(iVar2 + 0x1a7) = *(byte *)(iVar2 + 0x1a7) | 1;
  }
  if ((*(byte *)(param_1 + 0x1c3) & 2) == 0) {
    if ((char)param_1[0x221] < '\0') {
      param_1[0x221] = 0xc0;
    }
LAB_000d834b:
    iVar2 = *param_1;
    if ((((((*(byte *)(iVar2 + 0x180) & 2) != 0) && (*(int *)(iVar2 + 0x108) != 5)) &&
         (cease_fire == 0)) && ((param_1[0x1a] == 0 && (param_1[0x1b] == 0)))) &&
       (param_1[0x1c] == 0)) {
      (**(code **)(param_1[0x115] + 0x21c))(param_1);
      iVar2 = *param_1;
    }
    if ((((*(byte *)(iVar2 + 0x180) & 4) != 0) || ((*(byte *)(iVar2 + 0x1a5) & 0x40) != 0)) ||
       ((*(byte *)(param_1 + 0x1c3) & 8) != 0)) {
      (**(code **)(param_1[0x115] + 0x220))(param_1);
    }
    UpdateStepSound__11CBasePlayer(param_1);
    if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
      param_1[0x1bb] = (int)-*(float *)(*param_1 + 0x28);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x13f,0);
    if ((*(byte *)(param_1 + 0x1c3) & 4) != 0) {
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar2 + 0x24) = DAT_0019f664;
      *(undefined4 *)(iVar2 + 0x28) = DAT_0019f668;
    }
  }
  else {
    iVar2 = *(int *)(*param_1 + 0x19c);
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      local_64 = (int *)0x0;
    }
    else {
      local_64 = *(int **)(iVar2 + 0x7c);
    }
    if (local_64 == (int *)0x0) {
      iVar2 = *param_1;
      local_8 = *(float *)(iVar2 + 0x10) + -38.0;
      local_10 = *(float *)(iVar2 + 8);
      local_c = *(float *)(iVar2 + 0xc);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (iVar2 + 8,&local_10,1,*(undefined4 *)(iVar2 + 0x208),local_48);
      if (((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (local_18 != 0)) {
        local_64 = *(int **)(local_18 + 0x7c);
      }
      if (((local_64 != (int *)0x0) &&
          (uVar3 = (**(code **)(local_64[0x115] + 0x20))(local_64), (uVar3 & 0x40) != 0)) &&
         (iVar2 = (**(code **)(local_64[0x115] + 0x84))(local_64,*param_1), iVar2 != 0)) {
LAB_000d821c:
        iVar2 = *param_1;
        local_68 = 0.0;
        *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar2 + 0x24) = DAT_0019f664;
        *(undefined4 *)(iVar2 + 0x28) = DAT_0019f668;
        if ((param_1[0x1b6] & 8U) == 0) {
          if ((param_1[0x1b6] & 0x10U) != 0) {
            local_68 = -1.0;
            goto LAB_000d8263;
          }
        }
        else {
          local_68 = 1.0;
LAB_000d8263:
          (**(code **)(local_64[0x115] + 0xb8))(local_64,param_1,param_1,2,local_68);
        }
        if ((byte)(local_68 < 0.0 | (byte)((ushort)((ushort)NAN(local_68) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_68 == 0.0) << 0xe) >> 8)) != 0x40) {
          iVar2 = (int)ROUND(*(float *)(*local_64 + 0x1f8));
          dVar1 = (double)iVar2 / (double)*(int *)(*local_64 + 0x184);
          if (iVar2 < 0) {
            uVar3 = 5;
          }
          else if (iVar2 == 0) {
            uVar3 = 1;
          }
          else if ((byte)((0.33 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(dVar1 == 0.33) << 0xe) >> 8)) - 1) < 0x40) {
            uVar3 = 4;
            if (0x3f < (byte)((0.66 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(dVar1 == 0.66) << 0xe) >> 8)) - 1)) {
              uVar3 = 3;
            }
          }
          else {
            uVar3 = 2;
          }
          param_1[0x221] = uVar3 | 0xc0;
        }
        goto LAB_000d834b;
      }
    }
    else if ((((*(byte *)(*param_1 + 0x1a5) & 2) != 0) && ((*(byte *)(*local_64 + 0x1a0) & 2) == 0))
            && ((*(byte *)(*param_1 + 0x181) & 6) == 0)) goto LAB_000d821c;
    *(byte *)(param_1 + 0x1c3) = *(byte *)(param_1 + 0x1c3) & 0xfd;
    param_1[0x221] = 0xc0;
  }
  return;
}


