// KeyValuePartTwo__11CBaseEntityP14KeyValueData_s  @ 00108180
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KeyValuePartTwo__11CBaseEntityP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x2f8) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"increase_team");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x2fc) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"axhitme");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x300) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"pausetime");
        if ((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"delay"), iVar1 != 0)) {
          iVar1 = strcmp(*(char **)(param_2 + 4),"attack_finished");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x318) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x31c) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 800) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"noise4");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x324) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_b"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x328) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"team_broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_t"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x32c) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"speak");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x348) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"AP_speak");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x34c) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"team_speak");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x350) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"owners_team_speak");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x358) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"non_team_broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_n"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x330) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"non_team_speak");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x354) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"owners_team_broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_o"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x334) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"netname_broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_b"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x338) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"netname_team_broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_t"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x33c) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"netname_non_team_broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_n"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x340) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"netname_owners_team_broadcast");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_o"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x344) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"team_drop");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_t"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x35c) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"non_team_drop");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_n"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x360) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"netname_team_drop");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_n_t"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x364) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"netname_non_team_drop");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_n_n"), iVar1 == 0)) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x368) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"all_active");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0x370) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"delay_time");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x378) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"ammo_shells");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"a_s"), iVar1 == 0)) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xcc) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"ammo_nails");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"a_n"), iVar1 == 0)) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xd4) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"ammo_rockets");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"a_r"), iVar1 == 0)) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xe4) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"ammo_cells");
          if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"a_c"), iVar1 == 0)) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xdc) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"ammo_medikit");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xbc) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"ammo_detpack");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xc4) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"no_grenades_1");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0x48) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"no_grenades_2");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0x4c) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"maxammo_shells");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xc0) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"maxammo_nails");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xd0) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"maxammo_rockets");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xe0) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"maxammo_cells");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xd8) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"maxammo_medikit");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0xb8) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"maxammo_detpack");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 200) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"team1_allies");
          if (iVar1 == 0) {
            DAT_001820a8 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"team2_allies");
          if (iVar1 == 0) {
            _DAT_001820ac = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"team3_allies");
          if (iVar1 == 0) {
            _DAT_001820b0 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"team4_allies");
          if (iVar1 == 0) {
            _DAT_001820b4 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"invincible_finished");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x3a0) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"invisible_finished");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x3a4) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"super_damage_finished");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x3a8) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"last_impulse");
          if (iVar1 == 0) {
            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(param_1 + 0x38) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"radsuit_finished");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x3ac) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          iVar1 = strcmp(*(char **)(param_2 + 4),"deathtype");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x36c) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
            return;
          }
          *(undefined4 *)(param_2 + 0xc) = 0;
          return;
        }
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x304) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
    }
  }
  return;
}


