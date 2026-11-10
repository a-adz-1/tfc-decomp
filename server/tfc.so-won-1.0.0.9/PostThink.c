// PostThink__11CBasePlayer  @ 000dbd50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PostThink__11CBasePlayer(int *param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float local_1c;
  float local_18;
  
  if (g_fGameOver != 0) {
    return;
  }
  Player_Menu__11CBasePlayer(param_1);
  if ((*(byte *)((int)param_1 + 0x635) & 8) != 0) {
    UseSpecialSkill__11CBasePlayer(param_1);
  }
  if (param_1[0x262] != 0) {
    MapBriefingThink__11CBasePlayer(param_1);
  }
  iVar3 = (**(code **)(param_1[0xf2] + 0x88))(param_1);
  if (iVar3 == 0) {
    return;
  }
  if (*(int *)(*param_1 + 0x150) == 99) {
    return;
  }
  piVar1 = param_1 + 0x1f8;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar3 != 0) {
    iVar3 = __rf__7EHANDLE(piVar1);
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x80))(iVar3,*param_1);
    if ((iVar3 == 0) || (*(int *)(*param_1 + 0xa0) != 0)) {
      iVar3 = __rf__7EHANDLE(param_1 + 0x1f8);
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xb0))(iVar3,param_1,param_1,0,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x1f8,0);
    }
    else {
      iVar3 = __rf__7EHANDLE(piVar1);
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xb0))(iVar3,param_1,param_1,2,0x40000000);
    }
  }
  if ((((cease_fire == 0) && (param_1[0x1b] == 0)) && (param_1[0x1c] == 0)) && (param_1[0x1d] == 0))
  {
    ItemPostFrame__11CBasePlayer(param_1);
  }
  iVar3 = *param_1;
  if ((*(byte *)(iVar3 + 0x185) & 2) != 0) {
    fVar2 = *(float *)(iVar3 + 0x140);
    if (((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1) &&
       (fVar2 = (float)param_1[0x192],
       (byte)((350.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 350.0) << 0xe) >> 8)) - 1) < 0x40)) {
      local_18 = 0.5;
      if (*(int *)(iVar3 + 0x1a4) != -3) {
        if ((byte)(650.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 650.0) << 0xe) >> 8)) == 1) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(iVar3 + 0x1e8),2,"player/pl_fallpain3.wav",0x3f800000,
                     0x3f4ccccd,0,100);
          local_1c = ((float)param_1[0x192] / 300.0) * 5.0;
          if (param_1[0xb] == 1) {
            fVar2 = 0.5;
LAB_000dbf4c:
            local_1c = fVar2 * local_1c;
          }
          else if (param_1[0xb] == 6) {
            fVar2 = (float)_FUN_0013a148;
            goto LAB_000dbf4c;
          }
          if (*(float *)(*param_1 + 0x140) < local_1c) {
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(*param_1 + 0x1e8),3,"common/bodysplat.wav",0x3f800000,
                       0x3f4ccccd,0,100);
          }
          if ((byte)(0.0 < local_1c | (byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 1) {
            iVar3 = param_1[0xf2];
            iVar4 = (*DAT_001755d4)(0,local_1c,0x8000020);
            if (iVar4 == 0) {
              iVar4 = 0;
            }
            else {
              iVar4 = iVar4 + 0xdc;
            }
            iVar4 = (*DAT_001755d4)(0,iVar4);
            if (iVar4 == 0) {
              iVar4 = 0;
            }
            else {
              iVar4 = iVar4 + 0xdc;
            }
            (**(code **)(iVar3 + 0x34))(param_1,iVar4);
          }
          local_18 = 1.0;
        }
        else {
          fVar2 = (float)param_1[0x192];
          if ((byte)(325.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 325.0) << 0xe) >> 8)) == 1) {
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(*param_1 + 0x1e8),2,"player/pl_fallpain3.wav",0x3f800000,
                       0x3f4ccccd,0,100);
            local_18 = 0.85;
          }
          else if ((float)param_1[0x192] < 200.0) {
            local_18 = 0.0;
          }
        }
      }
      if ((byte)(0.0 < local_18 | (byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 1) {
        param_1[0x19c] = 0;
        UpdateStepSound__11CBasePlayer(param_1);
        uVar5 = MapTextureTypeStepType__Fc((int)*(char *)((int)param_1 + 0x7c1),local_18);
        PlayStepSound__11CBasePlayerif(param_1,uVar5);
        *(float *)(*param_1 + 0x68) = (float)param_1[0x192] * 0.018;
        fVar2 = *(float *)(*param_1 + 0x68);
        if ((byte)(8.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 8.0) << 0xe) >> 8)) == 1) {
          *(undefined4 *)(*param_1 + 0x68) = 0x41000000;
        }
        iVar3 = (*DAT_00175628)(0,1);
        if (iVar3 != 0) {
          *(float *)(*param_1 + 0x70) = (float)param_1[0x192] * 0.009;
        }
      }
      iVar3 = (**(code **)(param_1[0xf2] + 0x88))(param_1);
      if (iVar3 != 0) {
        SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
      }
    }
    if ((*(byte *)(*param_1 + 0x185) & 2) != 0) {
      fVar2 = (float)param_1[0x192];
      if (((byte)(64.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 64.0) << 0xe) >> 8)) == 1) &&
         (iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar3 == 0)) {
        InsertSound__9CSoundEntiRC6Vectorif
                  (4,*param_1 + 8,(int)ROUND((float)param_1[0x192]),0x3e4ccccd);
      }
      param_1[0x192] = 0;
    }
  }
  iVar3 = (**(code **)(param_1[0xf2] + 0x88))(param_1);
  if (iVar3 != 0) {
    fVar2 = *(float *)(*param_1 + 0x20);
    if (((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) &&
       (fVar2 = *(float *)(*param_1 + 0x24),
       (byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40)) {
      uVar5 = 0;
    }
    else {
      fVar2 = *(float *)(*param_1 + 0x20);
      if (((((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) &&
           (fVar2 = *(float *)(*param_1 + 0x24),
           (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40)) ||
          ((*(byte *)(*param_1 + 0x185) & 2) == 0)) && (*(int *)(*param_1 + 0x1a0) < 2))
      goto LAB_000dc239;
      uVar5 = 1;
    }
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,uVar5);
  }
LAB_000dc239:
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  CheckPowerups__11CBasePlayer(param_1);
  UpdatePlayerSound__11CBasePlayer(param_1);
  param_1[0x18c] = *(int *)(*param_1 + 0x160);
  return;
}


