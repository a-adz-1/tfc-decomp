// item_airtank  @ 00086af8
void item_airtank(undefined4 param_1)

{
  GetClassPtr__H1Z8CAirtank_PX01_PX01(param_1);
  return;
}


// item_antidote  @ 000b6d68
void item_antidote(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemAntidote_PX01_PX01(param_1);
  return;
}


// item_armor1  @ 000f9e00
void item_armor1(undefined4 param_1)

{
  GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01(param_1);
  return;
}


// item_armor2  @ 000f9ec8
void item_armor2(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01(param_1);
  return;
}


// item_armor3  @ 000f9f90
void item_armor3(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemArmorRed_PX01_PX01(param_1);
  return;
}


// item_artifact_envirosuit  @ 000faa38
void item_artifact_envirosuit(undefined4 param_1)

{
  GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01(param_1);
  return;
}


// item_artifact_invisibility  @ 000fab60
void item_artifact_invisibility(undefined4 param_1)

{
  GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01(param_1);
  return;
}


// item_artifact_invulnerability  @ 000fa8fc
void item_artifact_invulnerability(undefined4 param_1)

{
  GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01(param_1);
  return;
}


// item_artifact_super_damage  @ 000fac9c
void item_artifact_super_damage(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01(param_1);
  return;
}


// item_battery  @ 000b6d4c
void item_battery(undefined4 param_1)

{
  GetClassPtr__H1Z12CItemBattery_PX01_PX01(param_1);
  return;
}


// item_cells  @ 000fa61c
void item_cells(undefined4 param_1)

{
  GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01(param_1);
  return;
}


// item_health  @ 000f9830
void item_health(undefined4 param_1)

{
  GetClassPtr__H1Z11CItemHealth_PX01_PX01(param_1);
  return;
}


// item_healthkit  @ 000b5f20
void item_healthkit(undefined4 param_1)

{
  GetClassPtr__H1Z10CHealthKit_PX01_PX01(param_1);
  return;
}


// item_longjump  @ 000b6da0
void item_longjump(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemLongJump_PX01_PX01(param_1);
  return;
}


// item_rockets  @ 000fa448
void item_rockets(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01(param_1);
  return;
}


// item_security  @ 000b6d84
void item_security(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemSecurity_PX01_PX01(param_1);
  return;
}


// item_shells  @ 000fa290
void item_shells(undefined4 param_1)

{
  GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01(param_1);
  return;
}


// item_sodacan  @ 000a5550
void item_sodacan(undefined4 param_1)

{
  GetClassPtr__H1Z9CItemSoda_PX01_PX01(param_1);
  return;
}


// item_spikes  @ 000fa36c
void item_spikes(undefined4 param_1)

{
  GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01(param_1);
  return;
}


// item_suit  @ 000b6d30
void item_suit(undefined4 param_1)

{
  GetClassPtr__H1Z9CItemSuit_PX01_PX01(param_1);
  return;
}


// item_tfgoal  @ 00106110
void item_tfgoal(undefined4 param_1)

{
  GetClassPtr__H1Z11CTFGoalItem_PX01_PX01(param_1);
  return;
}


// item_tfgoal_touch__11CBaseEntityP11CBaseEntity  @ 0010c7b0
void item_tfgoal_touch__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  int unaff_retaddr;
  undefined4 local_78;
  code *local_54 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [16];
  float local_30;
  int iStack_10;
  int *local_4;
  
  local_54[0] = *(code **)(param_2[0x111] + 0x2c);
  iVar3 = (*local_54[0])(param_2);
  if ((((iVar3 == 2) && (iVar3 = (**(code **)(param_2[0x111] + 0x8c))(param_2), iVar3 != 0)) &&
      (cb_prematch_time <= *gpGlobals)) && (param_2[0x1c] == 0)) {
    if (((*(int *)(*param_1 + 400) != 0) &&
        (fVar1 = (float)param_1[0x119],
        (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) &&
       ((*(int *)(*param_1 + 400) == *(int *)(*param_2 + 0x208) &&
        (*gpGlobals < (float)param_1[0x119] + 5.0)))) {
      return;
    }
    param_1[0x119] = 0;
    local_54[0] = *(code **)(param_2[0x111] + 0xcc);
    (*local_54[0])(local_44,param_2);
    (**(code **)(*(int *)(unaff_retaddr + 0x444) + 0xcc))(local_54,unaff_retaddr);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (local_54,local_78,1,*(undefined4 *)(*local_4 + 0x208),local_40);
    if (((byte)(1.0 < local_30 | (byte)((ushort)((ushort)NAN(local_30) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_30 == 1.0) << 0xe) >> 8)) == 0x40) ||
       (iStack_10 == *(int *)(*param_2 + 0x208))) {
      if (CTF_Map == 1) {
        iVar3 = *local_4;
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
          if ((param_2[0x48] == 1) && (local_4[0x84] == 1)) {
            return;
          }
          if ((param_2[0x48] == 2) && (local_4[0x84] == 2)) {
            return;
          }
        }
        else if (local_4[0x48] == 1) {
          if (local_4[0x84] == 1) {
            uVar4 = UTIL_VarArgs__FPce("%s RETURNED the BLUE flag!",
                                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
            UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
            if (param_2[0x48] == 0) {
              pcVar5 = "SPECTATOR";
            }
            else {
              pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
            }
            uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
            uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
            iVar3 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
            pcVar5 = "\"%s<%i><%u><%s>\" triggered \"Returned_Blue_Flag\"\n";
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
            uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
            uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
            iVar3 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
            pcVar5 = "\"%s<%i><%u><%s>\" triggered \"Returned_Red_Flag\"\n";
          }
          UTIL_LogPrintf__FPce(pcVar5,iVar3,uVar4);
          iVar3 = 1;
          do {
            if ((int)gpGlobals[0x24] < iVar3) {
              local_4[0x86] = 2;
              *(undefined4 *)(*local_4 + 0x10c) = 1;
              local_4[5] = -0x10000;
              local_4[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
              iVar3 = *local_4;
              *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
              *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x18);
              *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 0x1c);
              UTIL_SetOrigin__FP9entvars_sRC6Vector(*local_4,*local_4 + 8);
              EMIT_SOUND_DYN__FP7edict_siPCcffii
                        (*(undefined4 *)(*local_4 + 0x208),1,"items/itembk2.wav",0x3f800000,
                         0x3f4ccccd,0,0x96);
              return;
            }
            puVar6 = (undefined4 *)UTIL_PlayerByIndex__Fi(iVar3);
            if (puVar6 != (undefined4 *)0x0) {
              if (puVar6[0x48] == 1) {
                if (local_4[0x84] != 1) {
                  if (puVar6[0x48] != 1) goto LAB_0010cb95;
                  goto LAB_0010cba5;
                }
LAB_0010cbbe:
                pcVar5 = "Your flag was RETURNED!!\n";
              }
              else {
LAB_0010cb95:
                if (local_4[0x84] != 1) {
LAB_0010cba5:
                  if (puVar6[0x48] == 2) {
                    if (local_4[0x84] == 2) goto LAB_0010cbbe;
                    if ((puVar6[0x48] == 2) && (local_4[0x84] == 1)) goto LAB_0010cbe9;
                  }
                  goto LAB_0010cc05;
                }
LAB_0010cbe9:
                pcVar5 = "The ENEMY flag was RETURNED!!\n";
              }
              ClientPrint__FP9entvars_siPCcN42(*puVar6,4,pcVar5,0,0,0,0);
            }
LAB_0010cc05:
            iVar3 = iVar3 + 1;
          } while( true );
        }
      }
      iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(local_4,param_2,0);
      if ((iVar3 != 0) &&
         (tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0(local_4,param_2,local_4),
         0.0 < *(float *)(*param_2 + 0x160))) {
        local_4[0x86] = 1;
      }
    }
  }
  return;
}


