// item_airtank  @ 0009a700
void item_airtank(undefined4 param_1)

{
  GetClassPtr__H1Z8CAirtank_PX01_PX01(param_1);
  return;
}


// item_antidote  @ 000bd8f0
void item_antidote(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemAntidote_PX01_PX01(param_1);
  return;
}


// item_armor1  @ 000f5990
void item_armor1(undefined4 param_1)

{
  GetClassPtr__H1Z15CItemArmorGreen_PX01_PX01(param_1);
  return;
}


// item_armor2  @ 000f5a30
void item_armor2(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemArmorYellow_PX01_PX01(param_1);
  return;
}


// item_armor3  @ 000f5ad0
void item_armor3(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemArmorRed_PX01_PX01(param_1);
  return;
}


// item_artifact_envirosuit  @ 000f6440
void item_artifact_envirosuit(undefined4 param_1)

{
  GetClassPtr__H1Z19CItemPowerupRadsuit_PX01_PX01(param_1);
  return;
}


// item_artifact_invisibility  @ 000f6520
void item_artifact_invisibility(undefined4 param_1)

{
  GetClassPtr__H1Z24CItemPowerupInvisibility_PX01_PX01(param_1);
  return;
}


// item_artifact_invulnerability  @ 000f6350
void item_artifact_invulnerability(undefined4 param_1)

{
  GetClassPtr__H1Z22CItemPowerupInvincible_PX01_PX01(param_1);
  return;
}


// item_artifact_super_damage  @ 000f6610
void item_artifact_super_damage(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemPowerupQuad_PX01_PX01(param_1);
  return;
}


// item_battery  @ 000bd8e0
void item_battery(undefined4 param_1)

{
  GetClassPtr__H1Z12CItemBattery_PX01_PX01(param_1);
  return;
}


// item_cells  @ 000f6050
void item_cells(undefined4 param_1)

{
  GetClassPtr__H1Z14CItemAmmoCells_PX01_PX01(param_1);
  return;
}


// item_health  @ 000f53e0
void item_health(undefined4 param_1)

{
  GetClassPtr__H1Z11CItemHealth_PX01_PX01(param_1);
  return;
}


// item_healthkit  @ 000bcca0
void item_healthkit(undefined4 param_1)

{
  GetClassPtr__H1Z10CHealthKit_PX01_PX01(param_1);
  return;
}


// item_longjump  @ 000bd910
void item_longjump(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemLongJump_PX01_PX01(param_1);
  return;
}


// item_rockets  @ 000f5ee0
void item_rockets(undefined4 param_1)

{
  GetClassPtr__H1Z16CItemAmmoRockets_PX01_PX01(param_1);
  return;
}


// item_security  @ 000bd900
void item_security(undefined4 param_1)

{
  GetClassPtr__H1Z13CItemSecurity_PX01_PX01(param_1);
  return;
}


// item_shells  @ 000f5d80
void item_shells(undefined4 param_1)

{
  GetClassPtr__H1Z15CItemAmmoShells_PX01_PX01(param_1);
  return;
}


// item_sodacan  @ 000afee0
void item_sodacan(undefined4 param_1)

{
  GetClassPtr__H1Z9CItemSoda_PX01_PX01(param_1);
  return;
}


// item_spikes  @ 000f5e30
void item_spikes(undefined4 param_1)

{
  GetClassPtr__H1Z14CItemAmmoNails_PX01_PX01(param_1);
  return;
}


// item_suit  @ 000bd8d0
void item_suit(undefined4 param_1)

{
  GetClassPtr__H1Z9CItemSuit_PX01_PX01(param_1);
  return;
}


// item_tfgoal  @ 001072f0
void item_tfgoal(undefined4 param_1)

{
  GetClassPtr__H1Z11CTFGoalItem_PX01_PX01(param_1);
  return;
}


// item_tfgoal_touch__11CBaseEntityP11CBaseEntity  @ 0010c360
void item_tfgoal_touch__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  bool bVar6;
  char *pcVar7;
  
  iVar3 = (**(code **)(param_2[0xf2] + 0x28))(param_2);
  if ((((iVar3 == 2) && (0.0 < *(float *)(*param_2 + 0x140))) && (cb_prematch_time <= *gpGlobals))
     && (param_2[0x1d] == 0)) {
    iVar3 = *param_1;
    if (CTF_Map == 1) {
      bVar6 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) ||
                                          NAN(*(float *)(iVar3 + 8))) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) << 0xe)
                       >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                         NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) << 0xe
                               ) >> 8)) == 0x40)) {
        fVar1 = *(float *)(iVar3 + 0x10);
        fVar2 = *(float *)(iVar3 + 0x1c);
        bVar6 = (byte)(fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar6) {
        if ((param_2[0x48] == 1) && (param_1[0x84] == 1)) {
          return;
        }
        if ((param_2[0x48] == 2) && (param_1[0x84] == 2)) {
          return;
        }
      }
      else if (param_1[0x48] == 1) {
        if (param_1[0x84] == 1) {
          iVar3 = *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26];
          pcVar7 = "%s RETURNED the BLUE flag!";
        }
        else {
          iVar3 = *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26];
          pcVar7 = "%s RETURNED the RED flag!";
        }
        uVar4 = UTIL_VarArgs__FPce(pcVar7,iVar3,0,0,0,0);
        UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
        iVar3 = 1;
        do {
          if ((int)gpGlobals[0x24] < iVar3) {
            param_1[0x86] = 2;
            *(undefined4 *)(*param_1 + 0xec) = 1;
            param_1[5] = -0x10000;
            param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
            iVar3 = *param_1;
            *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
            *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x18);
            *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 0x1c);
            UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(*param_1 + 0x1e8),1,"items/itembk2.wav",0x3f800000,0x3f4ccccd
                       ,0,0x96);
            return;
          }
          puVar5 = (undefined4 *)UTIL_PlayerByIndex__Fi(iVar3);
          if (puVar5 != (undefined4 *)0x0) {
            if (puVar5[0x48] == 1) {
              if (param_1[0x84] != 1) {
                if (puVar5[0x48] != 1) goto LAB_0010c4ca;
                goto LAB_0010c4d3;
              }
LAB_0010c4e5:
              pcVar7 = "Your flag was RETURNED!!\n";
            }
            else {
LAB_0010c4ca:
              if (param_1[0x84] != 1) {
LAB_0010c4d3:
                if (puVar5[0x48] == 2) {
                  if (param_1[0x84] == 2) goto LAB_0010c4e5;
                  if ((puVar5[0x48] == 2) && (param_1[0x84] == 1)) goto LAB_0010c512;
                }
                goto LAB_0010c52c;
              }
LAB_0010c512:
              pcVar7 = "The ENEMY flag was RETURNED!!\n";
            }
            ClientPrint__FP9entvars_tiPCcN42(*puVar5,4,pcVar7,0,0,0,0);
          }
LAB_0010c52c:
          iVar3 = iVar3 + 1;
        } while( true );
      }
    }
    iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
    if (iVar3 != 0) {
      tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_1);
      fVar1 = *(float *)(*param_2 + 0x140);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        param_1[0x86] = 1;
      }
    }
  }
  return;
}


