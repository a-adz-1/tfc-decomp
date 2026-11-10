// KeyValuePartThree__11CBaseEntityP14KeyValueData_s  @ 001082a4
void KeyValuePartThree__11CBaseEntityP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"endround_owned_by");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x364) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"endround_non_owned_by");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x368) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"org_broadcast");
      if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_b"), iVar1 == 0)) {
        uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x390) = uVar2;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"org_team_broadcast");
        if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_t"), iVar1 == 0)) {
          uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
          *(undefined4 *)(param_1 + 0x394) = uVar2;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"org_message");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(param_1 + 0x3ac) = uVar2;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"org_owners_team_broadcast");
            if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_o"), iVar1 == 0)) {
              uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
              *(undefined4 *)(param_1 + 0x39c) = uVar2;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"org_non_owners_team_broadcast");
              if (iVar1 == 0) {
                uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                *(undefined4 *)(param_1 + 0x3a0) = uVar2;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"org_non_team_broadcast");
                if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"org_b_n"), iVar1 == 0))
                {
                  uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                  *(undefined4 *)(param_1 + 0x398) = uVar2;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"org_noise3");
                  if (iVar1 == 0) {
                    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                    *(undefined4 *)(param_1 + 0x3b0) = uVar2;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"org_noise4");
                    if (iVar1 == 0) {
                      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                      *(undefined4 *)(param_1 + 0x3b4) = uVar2;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"org_team_drop");
                      if ((iVar1 == 0) ||
                         (iVar1 = strcmp(*(char **)(param_2 + 4),"org_d_t"), iVar1 == 0)) {
                        uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                        *(undefined4 *)(param_1 + 0x3a4) = uVar2;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(param_2 + 4),"org_non_team_drop");
                        if ((iVar1 != 0) &&
                           (iVar1 = strcmp(*(char **)(param_2 + 4),"org_d_n"), iVar1 != 0)) {
                          iVar1 = strcmp(*(char **)(param_2 + 4),"increase_team_owned_by");
                          if (iVar1 == 0) {
                            uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                            *(undefined4 *)(param_1 + 0x300) = uVar2;
                            *(undefined4 *)(param_2 + 0xc) = 1;
                            return;
                          }
                          *(undefined4 *)(param_2 + 0xc) = 0;
                          return;
                        }
                        uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                        *(undefined4 *)(param_1 + 0x3a8) = uVar2;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


