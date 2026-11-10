// PreThink__11CBasePlayer  @ 000ccde4
void PreThink__11CBasePlayer(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  float fStack_60;
  undefined1 local_44 [16];
  float local_34;
  int local_14;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *param_1;
  uVar2 = param_1[400] ^ *(uint *)(iVar1 + 0x180);
  param_1[0x191] = *(uint *)(iVar1 + 0x180) & uVar2;
  param_1[0x192] = uVar2 & ~*(uint *)(iVar1 + 0x180);
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x44] == 2.0) << 0xe) >> 8)) == 0x40) &&
     ((*(byte *)(param_1 + 0x191) & 2) != 0)) {
    ResetMenu__11CBasePlayer(param_1);
    TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1);
    *(byte *)(param_1 + 0x191) = *(byte *)(param_1 + 0x191) & 0xfd;
  }
  (**(code **)(*g_pGameRules + 0x54))(g_pGameRules,param_1);
  if (g_fGameOver != 0) {
    return;
  }
  if (((*(byte *)(*param_1 + 0x1a5) & 2) != 0) &&
     (((*(byte *)(param_1 + 0x19e) & 0x10) != 0 || ((*(byte *)(param_1 + 0x191) & 0x20) != 0)))) {
    iVar1 = *param_1;
    local_c = *(float *)(iVar1 + 0x20) * 0.3;
    local_8 = *(float *)(iVar1 + 0x24) * 0.3;
    local_4 = *(float *)(iVar1 + 0x28) * 0.3;
    *(float *)(iVar1 + 0x20) = local_c;
    *(float *)(iVar1 + 0x24) = local_8;
    *(float *)(iVar1 + 0x28) = local_4;
    *(byte *)(param_1 + 0x19e) = *(byte *)(param_1 + 0x19e) & 0xef;
  }
  ItemPreFrame__11CBasePlayer(param_1);
  WaterMove__11CBasePlayer(param_1);
  *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) | 2;
  UpdateClientData__11CBasePlayer(param_1);
  CheckTimeBasedDamage__11CBasePlayer(param_1);
  if (*(int *)(*param_1 + 0x244) != 0) {
    Observer_HandleButtons__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x184) = 0;
    return;
  }
  if ((1 < *(int *)(*param_1 + 0x1c0)) && (0.0 < (float)param_1[0x72])) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"ambience/steamburst1.wav",0x3f800000,0x3f4ccccd,
               0,100);
    param_1[0x72] = 0;
  }
  if (0 < *(int *)(*param_1 + 0x170)) {
    PlayerDeathThink__11CBasePlayer(param_1);
    return;
  }
  if ((*(byte *)(param_1 + 0x19e) & 2) == 0) {
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) & 0xfe;
  }
  else {
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 1;
  }
  if ((*(byte *)(param_1 + 0x19e) & 2) == 0) {
    if ((char)param_1[0x1fb] < '\0') {
      param_1[0x1fb] = 0xc0;
    }
LAB_000cd1f3:
    if ((((((*(byte *)(*param_1 + 0x180) & 2) != 0) &&
          (iVar1 = IsOnLadder__11CBasePlayer(param_1), iVar1 == 0)) && (cease_fire == 0)) &&
        ((param_1[0x1a] == 0 && (param_1[0x1b] == 0)))) && (param_1[0x1c] == 0)) {
      (**(code **)(param_1[0xf5] + 0x214))(param_1);
    }
    if ((((*(byte *)(*param_1 + 0x180) & 4) != 0) || ((*(byte *)(*param_1 + 0x1a5) & 0x40) != 0)) ||
       ((*(byte *)(param_1 + 0x19e) & 8) != 0)) {
      (**(code **)(param_1[0xf5] + 0x218))(param_1);
    }
    UpdateStepSound__11CBasePlayer(param_1);
    if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
      param_1[0x196] = (int)-*(float *)(*param_1 + 0x28);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x11f,0);
    if ((*(byte *)(param_1 + 0x19e) & 4) != 0) {
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
      *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
    }
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x19c);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(iVar1 + 0x7c);
    }
    if (piVar3 == (int *)0x0) {
      iVar1 = *param_1;
      local_c = *(float *)(iVar1 + 8);
      local_8 = *(float *)(iVar1 + 0xc);
      local_4 = *(float *)(iVar1 + 0x10) + -38.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (iVar1 + 8,&local_c,1,*(undefined4 *)(iVar1 + 0x208),local_44);
      if (((byte)(1.0 < local_34 | (byte)((ushort)((ushort)NAN(local_34) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_34 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (local_14 != 0)) {
        if ((local_14 == 0) && (local_14 = (*DAT_001a7f54)(0), local_14 == 0)) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = *(int **)(local_14 + 0x7c);
        }
      }
      if (((piVar3 != (int *)0x0) &&
          (uVar2 = (**(code **)(piVar3[0xf5] + 0x1c))(piVar3), (uVar2 & 0x40) != 0)) &&
         (iVar1 = (**(code **)(piVar3[0xf5] + 0x80))(piVar3,*param_1), iVar1 != 0)) {
LAB_000cd114:
        iVar1 = *param_1;
        *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
        *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
        fStack_60 = 0.0;
        if ((*(byte *)(param_1 + 0x191) & 8) == 0) {
          if ((*(byte *)(param_1 + 0x191) & 0x10) != 0) {
            fStack_60 = -1.0;
            goto LAB_000cd159;
          }
        }
        else {
          fStack_60 = 1.0;
LAB_000cd159:
          (**(code **)(piVar3[0xf5] + 0xb0))(piVar3,param_1,param_1,2,fStack_60);
        }
        if ((byte)(fStack_60 < 0.0 | (byte)((ushort)((ushort)NAN(fStack_60) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_60 == 0.0) << 0xe) >> 8)) != 0x40) {
          iVar1 = TrainSpeed__Fii((int)ROUND(*(float *)(*piVar3 + 0x1f8)),
                                  *(undefined4 *)(*piVar3 + 0x184));
          param_1[0x1fb] = iVar1;
          *(byte *)(param_1 + 0x1fb) = *(byte *)(param_1 + 0x1fb) | 0xc0;
        }
        goto LAB_000cd1f3;
      }
    }
    else if ((((*(byte *)(*param_1 + 0x1a5) & 2) != 0) && ((*(byte *)(*piVar3 + 0x1a0) & 2) == 0))
            && ((*(byte *)(*param_1 + 0x181) & 6) == 0)) goto LAB_000cd114;
    *(byte *)(param_1 + 0x19e) = *(byte *)(param_1 + 0x19e) & 0xfd;
    param_1[0x1fb] = 0xc0;
  }
  return;
}


