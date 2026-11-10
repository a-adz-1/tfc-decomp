// KeyValuePartThree__11CBaseEntityP14KeyValueData_s  @ 0010a6e0
void KeyValuePartThree__11CBaseEntityP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"endround_owned_by");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x374) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"endround_non_owned_by");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x378) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"org_broadcast");
      if ((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_b"), iVar1 != 0)) {
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_team_broadcast");
        if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_t"), iVar1 == 0)) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3a4) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_message");
        if (iVar1 == 0) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3bc) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_owners_team_broadcast");
        if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_o"), iVar1 == 0)) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3ac) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_non_owners_team_broadcast");
        if (iVar1 == 0) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3b0) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_non_team_broadcast");
        if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_n"), iVar1 == 0)) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3a8) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_noise3");
        if (iVar1 == 0) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3c0) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_noise4");
        if (iVar1 == 0) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3c4) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_team_drop");
        if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_d_t"), iVar1 == 0)) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3b4) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_non_team_drop");
        if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_d_n"), iVar1 == 0)) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x3b8) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"increase_team_owned_by");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x310) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"replacement_model");
        if (iVar1 == 0) {
          uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x298) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"replacement_model_body");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x29c) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"replacement_model_skin");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x2a0) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"replacement_model_flags");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x2a4) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        *(undefined4 *)(param_2 + 0xc) = 0;
        return;
      }
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3a0) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
  }
  return;
}


