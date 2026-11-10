// KeyValuePartTwo__11CBaseEntityP14KeyValueData_s  @ 001094ac
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KeyValuePartTwo__11CBaseEntityP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x314) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"increase_team");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x318) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"axhitme");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x31c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"pausetime");
  if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"delay"), iVar1 == 0)) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 800) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"attack_finished");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x334) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x338) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x37c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"noise4");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x380) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"broadcast");
  if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_b"), iVar1 == 0)) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 900) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"team_broadcast");
  if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_t"), iVar1 == 0)) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x388) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"speak");
  if (iVar1 != 0) {
    iVar1 = strcmp(*(char **)(param_2 + 4),"AP_speak");
    if (iVar1 == 0) {
LAB_0010a247:
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3e4) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"team_speak");
    if (iVar1 == 0) {
LAB_0010a283:
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 1000) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"owners_team_speak");
    if (iVar1 == 0) {
LAB_0010a2bf:
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3f0) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"non_owners_team_speak");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3f4) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"non_team_broadcast");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_n"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x38c) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"non_team_speak");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3ec) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"owners_team_broadcast");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"b_o"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x390) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"non_owners_team_broadcast");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x394) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"netname_broadcast");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_b"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3c8) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"netname_team_broadcast");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_t"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3cc) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"netname_non_team_broadcast");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_n"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3d0) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"netname_owners_team_broadcast");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"n_o"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3d4) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"team_drop");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_t"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x398) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"non_team_drop");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_n"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x39c) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"netname_team_drop");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_n_t"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3d8) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"netname_non_team_drop");
    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"d_n_n"), iVar1 == 0)) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3dc) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"all_active");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x3fc) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"delay_time");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x404) = (float)lVar3;
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
      *(undefined4 *)(param_1 + 0x44) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"no_grenades_2");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x48) = uVar2;
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
      DAT_001ac4dc = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"team2_allies");
    if (iVar1 == 0) {
      _DAT_001ac4e0 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"team3_allies");
    if (iVar1 == 0) {
      uRam001ac4e4 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"team4_allies");
    if (iVar1 == 0) {
      uRam001ac4e8 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"invincible_finished");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x42c) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"invisible_finished");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x430) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"super_damage_finished");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x434) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"last_impulse");
    if (iVar1 != 0) {
      iVar1 = strcmp(*(char **)(param_2 + 4),"radsuit_finished");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x438) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"deathtype");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x3f8) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"team1_name");
      if (iVar1 == 0) goto LAB_0010a20b;
      iVar1 = strcmp(*(char **)(param_2 + 4),"team2_name");
      if (iVar1 == 0) goto LAB_0010a247;
      iVar1 = strcmp(*(char **)(param_2 + 4),"team3_name");
      if (iVar1 == 0) goto LAB_0010a283;
      iVar1 = strcmp(*(char **)(param_2 + 4),"team4_name");
      if (iVar1 == 0) goto LAB_0010a2bf;
      iVar1 = strcmp(*(char **)(param_2 + 4),"speed_reduction");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x33c) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_time");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x340) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_team1");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x364) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_team2");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x368) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_team3");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x36c) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_team4");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x370) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_win_team1");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x344) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_win_team2");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x348) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_win_team3");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x34c) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_win_team4");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x350) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_lose_team1");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x354) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_lose_team2");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x358) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_lose_team3");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x35c) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"endround_lose_team4");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x360) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"teamcheck");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x220) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"owned_by_teamcheck");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x224) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"number_of_teams");
      if (iVar1 != 0) {
        KeyValuePartThree__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        return;
      }
    }
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x34) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
LAB_0010a20b:
  uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
  *(undefined4 *)(param_1 + 0x3e0) = uVar2;
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


