// item_airtank  @ 00086b88
void item_airtank(undefined4 param_1)

{
  GetClassPtr__H1Z8CAirtank_PX01_PX01(param_1);
  return;
}


// item_antidote  @ 000b5e80
void item_antidote(void)

{
  FUN_000b5e89();
  return;
}


// item_armor1  @ 000fda9c
void item_armor1(undefined4 param_1)

{
  GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01(param_1);
  return;
}


// item_armor2  @ 000fd958
void item_armor2(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01(param_1);
  return;
}


// item_armor3  @ 000fd814
void item_armor3(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemArmorRed_PX01_PX01(param_1);
  return;
}


// item_artifact_envirosuit  @ 000fceec
void item_artifact_envirosuit(undefined4 param_1)

{
  GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01(param_1);
  return;
}


// item_artifact_invisibility  @ 000fce10
void item_artifact_invisibility(undefined4 param_1)

{
  GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01(param_1);
  return;
}


// item_artifact_invulnerability  @ 000fcfdc
void item_artifact_invulnerability(undefined4 param_1)

{
  GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01(param_1);
  return;
}


// item_artifact_super_damage  @ 000fcd20
void item_artifact_super_damage(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01(param_1);
  return;
}


// item_battery  @ 000b5ea0
void item_battery(void)

{
  FUN_000b5ea9();
  return;
}


// item_cells  @ 000fd220
void item_cells(undefined4 param_1)

{
  GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01(param_1);
  return;
}


// item_health  @ 000fdc84
void item_health(undefined4 param_1)

{
  GetClassPtr__H1Z11CItemHealth_PX01_PX01(param_1);
  return;
}


// item_healthkit  @ 000b5a88
void item_healthkit(undefined4 param_1)

{
  GetClassPtr__H1Z10CHealthKit_PX01_PX01(param_1);
  return;
}


// item_longjump  @ 000b5e40
void item_longjump(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemLongJump_PX01_PX01(param_1);
  return;
}


// item_rockets  @ 000fd378
void item_rockets(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01(param_1);
  return;
}


// item_security  @ 000b5e60
void item_security(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemSecurity_PX01_PX01(param_1);
  return;
}


// item_shells  @ 000fd628
void item_shells(undefined4 param_1)

{
  GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01(param_1);
  return;
}


// item_sodacan  @ 000a3020
void item_sodacan(undefined4 param_1)

{
  GetClassPtr__H1Z9CItemSoda_PX01_PX01(param_1);
  return;
}


// item_spikes  @ 000fd4d0
void item_spikes(undefined4 param_1)

{
  GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01(param_1);
  return;
}


// item_suit  @ 000b5ec0
void item_suit(void)

{
  FUN_000b5ec9();
  return;
}


// item_tfgoal  @ 0011243c
void item_tfgoal(undefined4 param_1)

{
  GetClassPtr__H1Z11CTFGoalItem_PX01_PX01(param_1);
  return;
}


// item_tfgoal_touch__11CBaseEntityP11CBaseEntity  @ 0010f4e8
void item_tfgoal_touch__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  int local_9c;
  undefined1 local_54 [12];
  undefined1 local_48 [12];
  undefined1 local_3c [16];
  float local_2c;
  int local_c;
  
  iVar3 = (**(code **)(param_2[0x115] + 0x2c))(param_2);
  if ((((((iVar3 == 2) && (iVar3 = (**(code **)(param_2[0x115] + 0x8c))(param_2), iVar3 != 0)) &&
        (fVar1 = *gpGlobals,
        (byte)(fVar1 < cb_prematch_time |
               (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) != 1)) &&
       (param_2[0x1c] == 0)) && ((param_1[0xa6] == 0 || (param_2[0xa6] == 0)))) &&
     (((*(int *)(*param_1 + 400) == 0 ||
       ((fVar2 = (float)param_1[0x11d],
        (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40 ||
        (*(int *)(*param_1 + 400) != *(int *)(*param_2 + 0x208))))) || (fVar2 + 5.0 <= fVar1)))) {
    param_1[0x11d] = 0;
    (**(code **)(param_2[0x115] + 0xcc))(local_48,param_2);
    (**(code **)(param_1[0x115] + 0xcc))(local_54,param_1);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (local_54,local_48,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
    if (((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) ||
       (local_c == *(int *)(*param_2 + 0x208))) {
      if (CTF_Map == 1) {
        iVar3 = *param_1;
        bVar7 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) ||
                                            NAN(*(float *)(iVar3 + 8))) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) <<
                                  0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                           NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) <<
                                 0xe) >> 8)) == 0x40)) {
          fVar1 = *(float *)(iVar3 + 0x10);
          fVar2 = *(float *)(iVar3 + 0x1c);
          bVar7 = (byte)(fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
        }
        if (bVar7) {
          if ((param_2[0x48] == 1) && (param_1[0x84] == 1)) {
            return;
          }
          if ((param_2[0x48] == 2) && (param_1[0x84] == 2)) {
            return;
          }
        }
        else if (param_1[0x48] == 1) {
          if (param_1[0x84] == 1) {
            uVar4 = UTIL_VarArgs__FPce("%s RETURNED the BLUE flag!",
                                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
            UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
            if (param_2[0x48] == 0) {
              pcVar5 = "SPECTATOR";
            }
            else {
              pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
            }
            uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
            uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
            iVar3 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
            pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Returned_Blue_Flag\"\n";
          }
          else {
            uVar4 = UTIL_VarArgs__FPce("%s RETURNED the RED flag!",
                                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
            UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
            if (param_2[0x48] == 0) {
              pcVar5 = "SPECTATOR";
            }
            else {
              pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
            }
            uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
            uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
            iVar3 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
            pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Returned_Red_Flag\"\n";
          }
          UTIL_LogPrintf__FPce(pcVar5,iVar3,uVar4);
          iVar3 = 1;
          if (0 < (int)gpGlobals[0x24]) {
            do {
              puVar6 = (undefined4 *)UTIL_PlayerByIndex__Fi(iVar3);
              if (puVar6 == (undefined4 *)0x0) goto LAB_0010f93d;
              if (puVar6[0x48] == 1) {
                local_9c = param_1[0x84];
                if (local_9c == 1) {
LAB_0010f906:
                  pcVar5 = "Your flag was RETURNED!!\n";
                  goto LAB_0010f92f;
                }
LAB_0010f8f4:
                if (puVar6[0x48] == 2) {
                  if (local_9c == 2) goto LAB_0010f906;
                  if (local_9c == 1) goto LAB_0010f921;
                }
              }
              else {
                local_9c = param_1[0x84];
                if (local_9c != 1) goto LAB_0010f8f4;
LAB_0010f921:
                pcVar5 = "The ENEMY flag was RETURNED!!\n";
LAB_0010f92f:
                ClientPrint__FP9entvars_siPCcN42(*puVar6,4,pcVar5,0,0,0,0);
              }
LAB_0010f93d:
              iVar3 = iVar3 + 1;
            } while (iVar3 <= (int)gpGlobals[0x24]);
          }
          param_1[0x86] = 2;
          *(undefined4 *)(*param_1 + 0x10c) = 1;
          param_1[5] = -0x10000;
          param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
          iVar3 = *param_1;
          *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x18);
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 0x1c);
          UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*param_1 + 0x208),1,"items/itembk2.wav",0x3f800000,0x3f4ccccd,0
                     ,0x96);
          return;
        }
      }
      iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if ((iVar3 != 0) &&
         (tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_1),
         0.0 < *(float *)(*param_2 + 0x160))) {
        param_1[0x86] = 1;
      }
    }
  }
  return;
}


