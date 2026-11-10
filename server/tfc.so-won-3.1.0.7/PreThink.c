// PreThink__11CBasePlayer  @ 000d8494
void PreThink__11CBasePlayer(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  float fStack_60;
  undefined1 auStack_44 [16];
  float fStack_34;
  int iStack_14;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *param_1;
  uVar2 = param_1[0x1ac] ^ *(uint *)(iVar1 + 0x180);
  param_1[0x1ad] = *(uint *)(iVar1 + 0x180) & uVar2;
  param_1[0x1ae] = uVar2 & ~*(uint *)(iVar1 + 0x180);
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x44] == 2.0) << 0xe) >> 8)) == 0x40) &&
     ((*(byte *)(param_1 + 0x1ad) & 2) != 0)) {
    ResetMenu__11CBasePlayer(param_1);
    TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1);
    *(byte *)(param_1 + 0x1ad) = *(byte *)(param_1 + 0x1ad) & 0xfd;
  }
  (**(code **)(*g_pGameRules + 0x54))(g_pGameRules,param_1);
  if (g_fGameOver != 0) {
    return;
  }
  if (((*(byte *)(*param_1 + 0x1a5) & 2) != 0) &&
     (((*(byte *)(param_1 + 0x1ba) & 0x10) != 0 || ((*(byte *)(param_1 + 0x1ad) & 0x20) != 0)))) {
    iVar1 = *param_1;
    local_c = *(float *)(iVar1 + 0x20) * 0.3;
    local_8 = *(float *)(iVar1 + 0x24) * 0.3;
    local_4 = *(float *)(iVar1 + 0x28) * 0.3;
    *(float *)(iVar1 + 0x20) = local_c;
    *(float *)(iVar1 + 0x24) = local_8;
    *(float *)(iVar1 + 0x28) = local_4;
    *(byte *)(param_1 + 0x1ba) = *(byte *)(param_1 + 0x1ba) & 0xef;
  }
  ItemPreFrame__11CBasePlayer(param_1);
  WaterMove__11CBasePlayer(param_1);
  *(byte *)(param_1 + 0x223) = *(byte *)(param_1 + 0x223) | 2;
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
  if ((*(byte *)(param_1 + 0x1ba) & 2) == 0) {
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) & 0xfe;
  }
  else {
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 1;
  }
  if ((*(byte *)(param_1 + 0x1ba) & 2) == 0) {
    if ((char)param_1[0x217] < '\0') {
      param_1[0x217] = 0xc0;
    }
LAB_000d88a3:
    if ((((((*(byte *)(*param_1 + 0x180) & 2) != 0) &&
          (iVar1 = IsOnLadder__11CBasePlayer(param_1), iVar1 == 0)) && (cease_fire == 0)) &&
        ((param_1[0x1a] == 0 && (param_1[0x1b] == 0)))) && (param_1[0x1c] == 0)) {
      (**(code **)(param_1[0x111] + 0x21c))(param_1);
    }
    if ((((*(byte *)(*param_1 + 0x180) & 4) != 0) || ((*(byte *)(*param_1 + 0x1a5) & 0x40) != 0)) ||
       ((*(byte *)(param_1 + 0x1ba) & 8) != 0)) {
      (**(code **)(param_1[0x111] + 0x220))(param_1);
    }
    UpdateStepSound__11CBasePlayer(param_1);
    if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
      param_1[0x1b2] = (int)-*(float *)(*param_1 + 0x28);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x13b,0);
    if ((*(byte *)(param_1 + 0x1ba) & 4) != 0) {
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar1 + 0x24) = DAT_001c0fe4;
      *(undefined4 *)(iVar1 + 0x28) = DAT_001c0fe8;
    }
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x19c);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
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
                (iVar1 + 8,&local_c,1,*(undefined4 *)(iVar1 + 0x208),auStack_44);
      if (((byte)(1.0 < fStack_34 | (byte)((ushort)((ushort)NAN(fStack_34) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_34 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (iStack_14 != 0)) {
        if ((iStack_14 == 0) && (iStack_14 = (*DAT_001c1134)(0), iStack_14 == 0)) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = *(int **)(iStack_14 + 0x7c);
        }
      }
      if (((piVar3 != (int *)0x0) &&
          (uVar2 = (**(code **)(piVar3[0x111] + 0x20))(piVar3), (uVar2 & 0x40) != 0)) &&
         (iVar1 = (**(code **)(piVar3[0x111] + 0x84))(piVar3,*param_1), iVar1 != 0)) {
LAB_000d87c4:
        iVar1 = *param_1;
        *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar1 + 0x24) = DAT_001c0fe4;
        *(undefined4 *)(iVar1 + 0x28) = DAT_001c0fe8;
        fStack_60 = 0.0;
        if ((*(byte *)(param_1 + 0x1ad) & 8) == 0) {
          if ((*(byte *)(param_1 + 0x1ad) & 0x10) != 0) {
            fStack_60 = -1.0;
            goto LAB_000d8809;
          }
        }
        else {
          fStack_60 = 1.0;
LAB_000d8809:
          (**(code **)(piVar3[0x111] + 0xb8))(piVar3,param_1,param_1,2,fStack_60);
        }
        if ((byte)(fStack_60 < 0.0 | (byte)((ushort)((ushort)NAN(fStack_60) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_60 == 0.0) << 0xe) >> 8)) != 0x40) {
          iVar1 = TrainSpeed__Fii((int)ROUND(*(float *)(*piVar3 + 0x1f8)),
                                  *(undefined4 *)(*piVar3 + 0x184));
          param_1[0x217] = iVar1;
          *(byte *)(param_1 + 0x217) = *(byte *)(param_1 + 0x217) | 0xc0;
        }
        goto LAB_000d88a3;
      }
    }
    else if ((((*(byte *)(*param_1 + 0x1a5) & 2) != 0) && ((*(byte *)(*piVar3 + 0x1a0) & 2) == 0))
            && ((*(byte *)(*param_1 + 0x181) & 6) == 0)) goto LAB_000d87c4;
    *(byte *)(param_1 + 0x1ba) = *(byte *)(param_1 + 0x1ba) & 0xfd;
    param_1[0x217] = 0xc0;
  }
  return;
}


