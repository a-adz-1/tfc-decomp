// KeyValue__10CBaseDelayP14KeyValueData_s  @ 000f3938
void KeyValue__10CBaseDelayP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"delay");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x448) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x44c) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__10CBreakableP14KeyValueData_s  @ 000a8114
void KeyValue__10CBreakableP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"explosion");
  if (iVar1 == 0) {
    iVar1 = strcasecmp(*(char **)(param_2 + 8),"directed");
    if (iVar1 == 0) {
      param_1[0x115] = 1;
    }
    else {
      strcasecmp(*(char **)(param_2 + 8),"random");
      param_1[0x115] = 0;
    }
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"material");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      if (uVar2 < 10) {
        param_1[0x114] = uVar2;
      }
      else {
        param_1[0x114] = 1;
      }
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"deadmodel");
      if ((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"shards"), iVar1 != 0)) {
        iVar1 = strcmp(*(char **)(param_2 + 4),"gibmodel");
        if (iVar1 == 0) {
          iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
          param_1[0x118] = iVar1;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"spawnobject");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          if (iVar1 - 1U < 0x15) {
            param_1[0x119] =
                 *(int *)(_10CBreakable_pSpawnObjects + iVar1 * 4) - *(int *)(gpGlobals + 0x98);
          }
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"explodemagnitude");
          if (iVar1 == 0) {
            uVar3 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(undefined4 *)(*param_1 + 0x184) = uVar3;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"lip");
            if (iVar1 != 0) {
              KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
              return;
            }
          }
        }
      }
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__10CEnvGlobalP14KeyValueData_s  @ 0008a818
void KeyValue__10CEnvGlobalP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 0xc) = 1;
  iVar1 = strcmp(*(char **)(param_2 + 4),"globalstate");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x448) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"triggermode");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x44c) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"initialstate");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x450) = uVar2;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__10CFuncTrainP14KeyValueData_s  @ 000ce6f4
void KeyValue__10CFuncTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x4f4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__14CBasePlatTrainP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__10CLightningP14KeyValueData_s  @ 000a0b34
void KeyValue__10CLightningP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"LightningStart");
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    param_1[0x113] = iVar1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"LightningEnd");
    if (iVar1 == 0) {
      iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      param_1[0x114] = iVar1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"life");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x115] = (int)(float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"BoltWidth");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        param_1[0x116] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"NoiseAmplitude");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        param_1[0x117] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"TextureScroll");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        param_1[0x119] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"StrikeTime");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x11a] = (int)(float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
      if (iVar1 != 0) {
        iVar1 = strcmp(*(char **)(param_2 + 4),"framestart");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          param_1[0x11d] = iVar1;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"Radius");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0x11e] = (int)(float)lVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(*param_1 + 0x1e0) = (float)lVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        return;
      }
      iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      param_1[0x11c] = iVar1;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__10CPathTrackP14KeyValueData_s  @ 000cc5a8
void KeyValue__10CPathTrackP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"altpath");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x44c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__10CWeaponBoxP14KeyValueData_s  @ 00121018
void KeyValue__10CWeaponBoxP14KeyValueData_s(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x568) < 0x20) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    uVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 4),uVar1);
    PackAmmo__10CWeaponBoxii(param_1,uVar1);
    *(int *)(param_1 + 0x568) = *(int *)(param_1 + 0x568) + 1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    (*DAT_001c1114)(1,"WeaponBox too full! only %d ammotypes allowed\n",0x20);
  }
  return;
}


// KeyValue__10CWorldItemP14KeyValueData_s  @ 000b67d8
void KeyValue__10CWorldItemP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"type");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x448) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__11CBaseButtonP14KeyValueData_s  @ 0008b38c
void KeyValue__11CBaseButtonP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"changetarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x4f0) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sound");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(char *)(param_1 + 0x518) = (char)(longlong)ROUND(lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sentence");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(char *)(param_1 + 0x519) = (char)(longlong)ROUND(lVar3);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sound");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(char *)(param_1 + 0x51a) = (char)(longlong)ROUND(lVar3);
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sentence");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x51b) = (char)(longlong)ROUND(lVar3);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
            if (iVar1 == 0) {
              uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(undefined4 *)(param_1 + 0x51c) = uVar2;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
            }
          }
        }
      }
    }
  }
  return;
}


// KeyValue__11CBaseEntityP14KeyValueData_s  @ 00106238
void KeyValue__11CBaseEntityP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  longdouble lVar4;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"goal_no");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0x84] = iVar1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"mdl");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(*param_1 + 0xb8) = uVar2;
      goto LAB_00106f9e;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"group_no");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      param_1[0x85] = iVar1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"team_no");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        param_1[0x48] = iVar1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"playerclass");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(*param_1 + 0x20c) = uVar2;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"items_allowed");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            param_1[0x3a] = iVar1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"goal_state");
            if (iVar1 == 0) {
              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              param_1[0x86] = iVar1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"items");
              if (iVar1 == 0) {
                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                param_1[0x22] = iVar1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"owned_by");
                if (iVar1 == 0) {
                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                  param_1[0x87] = iVar1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"armorclass");
                  if (iVar1 == 0) {
                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                    param_1[0xe] = iVar1;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"goal_activation");
                    if ((iVar1 == 0) || (iVar1 = strcmp(*(char **)(param_2 + 4),"g_a"), iVar1 == 0))
                    {
                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                      param_1[0x8a] = iVar1;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"goal_effects");
                      if ((iVar1 == 0) ||
                         (iVar1 = strcmp(*(char **)(param_2 + 4),"g_e"), iVar1 == 0)) {
                        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                        param_1[0x8b] = iVar1;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(param_2 + 4),"goal_result");
                        if (iVar1 == 0) {
                          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                          param_1[0x8c] = iVar1;
                        }
                        else {
                          iVar1 = strcmp(*(char **)(param_2 + 4),"goal_group");
                          if (iVar1 == 0) {
                            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                            param_1[0x8d] = iVar1;
                          }
                          else {
                            iVar1 = strcmp(*(char **)(param_2 + 4),"else_goal");
                            if (iVar1 == 0) {
                              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                              param_1[0x8e] = iVar1;
                            }
                            else {
                              iVar1 = strcmp(*(char **)(param_2 + 4),"if_goal_is_active");
                              if (iVar1 == 0) {
                                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                param_1[0x8f] = iVar1;
                              }
                              else {
                                iVar1 = strcmp(*(char **)(param_2 + 4),"if_goal_is_inactive");
                                if (iVar1 == 0) {
                                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                  param_1[0x90] = iVar1;
                                }
                                else {
                                  iVar1 = strcmp(*(char **)(param_2 + 4),"if_goal_is_removed");
                                  if (iVar1 == 0) {
                                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                    param_1[0x91] = iVar1;
                                  }
                                  else {
                                    iVar1 = strcmp(*(char **)(param_2 + 4),"if_group_is_active");
                                    if (iVar1 == 0) {
                                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0)
                                      ;
                                      param_1[0x92] = iVar1;
                                    }
                                    else {
                                      iVar1 = strcmp(*(char **)(param_2 + 4),"if_group_is_inactive")
                                      ;
                                      if (iVar1 == 0) {
                                        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,
                                                                  0);
                                        param_1[0x93] = iVar1;
                                      }
                                      else {
                                        iVar1 = strcmp(*(char **)(param_2 + 4),"if_group_is_removed"
                                                      );
                                        if (iVar1 == 0) {
                                          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,
                                                                    10,0);
                                          param_1[0x94] = iVar1;
                                        }
                                        else {
                                          iVar1 = strcmp(*(char **)(param_2 + 4),"search_time");
                                          if (iVar1 == 0) {
                                            lVar4 = (longdouble)
                                                    __strtod_internal(*(undefined4 *)(param_2 + 8),0
                                                                      ,0);
                                            param_1[0x95] = (int)(float)lVar4;
                                          }
                                          else {
                                            iVar1 = strcmp(*(char **)(param_2 + 4),"t_length");
                                            if (iVar1 == 0) {
                                              lVar4 = (longdouble)
                                                      __strtod_internal(*(undefined4 *)(param_2 + 8)
                                                                        ,0,0);
                                              param_1[0x96] = (int)(float)lVar4;
                                            }
                                            else {
                                              iVar1 = strcmp(*(char **)(param_2 + 4),
                                                             "activate_goal_no");
                                              if (iVar1 == 0) {
                                                iVar1 = __strtol_internal(*(undefined4 *)
                                                                           (param_2 + 8),0,10,0);
                                                param_1[0x97] = iVar1;
                                              }
                                              else {
                                                iVar1 = strcmp(*(char **)(param_2 + 4),
                                                               "inactivate_goal_no");
                                                if (iVar1 == 0) {
                                                  iVar1 = __strtol_internal(*(undefined4 *)
                                                                             (param_2 + 8),0,10,0);
                                                  param_1[0x98] = iVar1;
                                                }
                                                else {
                                                  iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                 "remove_goal_no");
                                                  if ((iVar1 == 0) ||
                                                     (iVar1 = strcmp(*(char **)(param_2 + 4),"rv_g")
                                                     , iVar1 == 0)) {
                                                    iVar1 = __strtol_internal(*(undefined4 *)
                                                                               (param_2 + 8),0,10,0)
                                                    ;
                                                    param_1[0x99] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "restore_goal_no");
                                                    if ((iVar1 == 0) ||
                                                       (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "rs_g"), iVar1 == 0)) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0x9a] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "activate_group_no");
                                                      if (iVar1 == 0) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0x9b] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "inactivate_group_no");
                                                        if (iVar1 == 0) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0x9c] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "remove_group_no");
                                                          if ((iVar1 == 0) ||
                                                             (iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"rv_gr"), iVar1 == 0))
                                                          {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0x9d] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "restore_group_no");
                                                            if ((iVar1 == 0) ||
                                                               (iVar1 = strcmp(*(char **)(param_2 +
                                                                                         4),"rs_gr")
                                                               , iVar1 == 0)) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0x9e] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"goal_min");
                                                              if (iVar1 == 0) {
                                                                UTIL_StringToVector__FPfPCc
                                                                          (&fStack_10,
                                                                           *(undefined4 *)
                                                                            (param_2 + 8));
                                                                bVar3 = false;
                                                                if (((byte)((byte)((ushort)((ushort)
                                                  (NAN(g_vecZero) || NAN(fStack_10)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(g_vecZero == fStack_10)
                                                                 << 0xe) >> 8)) == 0x40) &&
                                                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4)
                                                                                  || NAN(fStack_c))
                                                                         << 10) >> 8) |
                                                         (byte)((ushort)((ushort)(DAT_001c0fe4 ==
                                                                                 fStack_c) << 0xe)
                                                               >> 8)) == 0x40)) {
                                                    bVar3 = (byte)(DAT_001c0fe8 < fStack_8 |
                                                                   (byte)((ushort)((ushort)(NAN(
                                                  DAT_001c0fe8) || NAN(fStack_8)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(DAT_001c0fe8 == fStack_8)
                                                                 << 0xe) >> 8)) == 0x40;
                                                  }
                                                  if (!bVar3) {
                                                    param_1[0xa0] = (int)fStack_10;
                                                    param_1[0xa1] = (int)fStack_c;
                                                    param_1[0xa2] = (int)fStack_8;
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "goal_max");
                                                    if (iVar1 == 0) {
                                                      UTIL_StringToVector__FPfPCc
                                                                (&fStack_10,
                                                                 *(undefined4 *)(param_2 + 8));
                                                      bVar3 = false;
                                                      if (((byte)((byte)((ushort)((ushort)(NAN(
                                                  g_vecZero) || NAN(fStack_10)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(g_vecZero == fStack_10)
                                                                 << 0xe) >> 8)) == 0x40) &&
                                                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4)
                                                                                  || NAN(fStack_c))
                                                                         << 10) >> 8) |
                                                         (byte)((ushort)((ushort)(DAT_001c0fe4 ==
                                                                                 fStack_c) << 0xe)
                                                               >> 8)) == 0x40)) {
                                                    bVar3 = (byte)(DAT_001c0fe8 < fStack_8 |
                                                                   (byte)((ushort)((ushort)(NAN(
                                                  DAT_001c0fe8) || NAN(fStack_8)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(DAT_001c0fe8 == fStack_8)
                                                                 << 0xe) >> 8)) == 0x40;
                                                  }
                                                  if (!bVar3) {
                                                    param_1[0xa3] = (int)fStack_10;
                                                    param_1[0xa4] = (int)fStack_c;
                                                    param_1[0xa5] = (int)fStack_8;
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "has_item_from_group");
                                                    if ((iVar1 == 0) ||
                                                       (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "h_i_g"), iVar1 == 0)) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xa6] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "hasnt_item_from_group");
                                                      if ((iVar1 == 0) ||
                                                         (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "hn_i_g"), iVar1 == 0)) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0xa7] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "remove_item_group");
                                                        if ((iVar1 == 0) ||
                                                           (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "r_i_g"), iVar1 == 0)) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0xa8] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "return_item_no");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0xa9] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "if_item_has_moved");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xaa] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"if_item_hasnt_moved")
                                                              ;
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xab] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "remove_spawnpoint");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xac] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "restore_spawnpoint");
                                                      if (iVar1 == 0) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0xad] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "remove_spawngroup");
                                                        if ((iVar1 == 0) ||
                                                           (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "rv_s_h"), iVar1 == 0)) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0xae] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "restore_spawngroup");
                                                          if ((iVar1 == 0) ||
                                                             (iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"rs_s_h"), iVar1 == 0)
                                                             ) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0xaf] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "display_item_status1");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xb0] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"display_item_status2"
                                                                            );
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xb1] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "display_item_status3");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xb2] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "display_item_status4");
                                                      if (iVar1 != 0) {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "team_str_home");
                                                        if ((iVar1 == 0) ||
                                                           (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "t_s_g"), iVar1 == 0)) {
                                                          iVar1 = (*DAT_001c112c)(*(undefined4 *)
                                                                                   (param_2 + 8));
                                                          param_1[0xb4] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "team_str_moved");
                                                          if ((iVar1 == 0) ||
                                                             (iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"t_s_m"), iVar1 == 0))
                                                          {
                                                            iVar1 = (*DAT_001c112c)(*(undefined4 *)
                                                                                     (param_2 + 8));
                                                            param_1[0xb5] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "team_str_carried");
                                                            if ((iVar1 == 0) ||
                                                               (iVar1 = strcmp(*(char **)(param_2 +
                                                                                         4),"t_s_c")
                                                               , iVar1 == 0)) {
                                                              iVar1 = (*DAT_001c112c)(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ));
                                                              param_1[0xb6] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"non_team_str_home");
                                                              if ((iVar1 == 0) ||
                                                                 (iVar1 = strcmp(*(char **)(param_2 
                                                  + 4),"t_s_h"), iVar1 == 0)) {
                                                    iVar1 = (*DAT_001c112c)(*(undefined4 *)
                                                                             (param_2 + 8));
                                                    param_1[0xb7] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "non_team_str_moved");
                                                    if ((iVar1 == 0) ||
                                                       (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "t_s_m"), iVar1 == 0)) {
                                                      iVar1 = (*DAT_001c112c)(*(undefined4 *)
                                                                               (param_2 + 8));
                                                      param_1[0xb8] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "non_team_str_carried");
                                                      if ((iVar1 != 0) &&
                                                         (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "n_s_c"), iVar1 != 0)) {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "ex_skill_min");
                                                        if (iVar1 == 0) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0xba] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "ex_skill_max");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0xbb] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "increase_team1");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xbc] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"increase_team2");
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xbd] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "increase_team3");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xbe] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "increase_team4");
                                                      if (iVar1 != 0) {
                                                                                                                
                                                  KeyValuePartTwo__11CBaseEntityP14KeyValueData_s
                                                            (param_1,param_2);
                                                  return;
                                                  }
                                                  iVar1 = __strtol_internal(*(undefined4 *)
                                                                             (param_2 + 8),0,10,0);
                                                  param_1[0xbf] = iVar1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00106281;
                                                  }
                                                  iVar1 = (*DAT_001c112c)(*(undefined4 *)
                                                                           (param_2 + 8));
                                                  param_1[0xb9] = iVar1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
LAB_00106f9e:
                                                  *(undefined4 *)(param_2 + 0xc) = 1;
                                                  return;
                                                  }
                                                  iVar1 = __strtol_internal(*(undefined4 *)
                                                                             (param_2 + 8),0,10,0);
                                                  param_1[0xb3] = iVar1;
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
  }
LAB_00106281:
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__11CBaseToggleP14KeyValueData_s  @ 000f407c
void KeyValue__11CBaseToggleP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"lip");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x474) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x470) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"master");
      if (iVar1 == 0) {
        uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x4e4) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x46c) = (float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
        }
      }
    }
  }
  return;
}


// KeyValue__11CBaseTurretP14KeyValueData_s  @ 001163ec
void KeyValue__11CBaseTurretP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"maxsleep");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x6d0) = (float)lVar3;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"orientation");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x6b0) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"searchspeed");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x6d4) = uVar2;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"turnrate");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x6a8) = uVar2;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"style");
          if ((((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"height"), iVar1 != 0)) &&
              (iVar1 = strcmp(*(char **)(param_2 + 4),"value1"), iVar1 != 0)) &&
             ((iVar1 = strcmp(*(char **)(param_2 + 4),"value2"), iVar1 != 0 &&
              (iVar1 = strcmp(*(char **)(param_2 + 4),"value3"), iVar1 != 0)))) {
            KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
            return;
          }
        }
      }
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__11CEnvShooterP14KeyValueData_s  @ 000a4020
void KeyValue__11CEnvShooterP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"shootmodel");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0xb8) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"shootsounds");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_2 + 0xc) = 1;
      switch(uVar2) {
      case 0:
        param_1[0x116] = 0;
        break;
      case 1:
        param_1[0x116] = 1;
        break;
      case 2:
        param_1[0x116] = 2;
        break;
      case 3:
        param_1[0x116] = 3;
        break;
      case 4:
        param_1[0x116] = 8;
        break;
      default:
        param_1[0x116] = 9;
      }
    }
    else {
      KeyValue__11CGibShooterP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__11CGibShooterP14KeyValueData_s  @ 000a3884
void KeyValue__11CGibShooterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iGibs");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x454) = uVar2;
    *(undefined4 *)(param_1 + 0x450) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_flVelocity");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x460) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_flVariance");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x464) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_flGibLife");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x468) = (float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
        }
      }
    }
  }
  return;
}


// KeyValue__11CPathCornerP14KeyValueData_s  @ 000cc488
void KeyValue__11CPathCornerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x448) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__11CWallHealthP14KeyValueData_s  @ 000b617c
void KeyValue__11CWallHealthP14KeyValueData_s(void)

{
  FUN_000b6184();
  return;
}


// KeyValue__12CAutoTriggerP14KeyValueData_s  @ 00110f3c
void KeyValue__12CAutoTriggerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"globalstate");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x450) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"triggerstate");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x454) = 0;
      }
      else if (iVar1 == 2) {
        *(undefined4 *)(param_1 + 0x454) = 3;
      }
      else {
        *(undefined4 *)(param_1 + 0x454) = 1;
      }
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__12CBaseMonsterP14KeyValueData_s  @ 000c115c
void KeyValue__12CBaseMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"TriggerTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x674) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"TriggerCondition");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x670) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__12CBaseTriggerP14KeyValueData_s  @ 001119dc
void KeyValue__12CBaseTriggerP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1e0) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"count");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[300] = (int)ROUND(lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"damagetype");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        param_1[0x138] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__12CChangeLevelP14KeyValueData_s  @ 00112cd4
void KeyValue__12CChangeLevelP14KeyValueData_s(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  longdouble lVar6;
  char *__src;
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"map");
  if (iVar2 == 0) {
    uVar5 = 0xffffffff;
    pcVar3 = *(char **)(param_2 + 8);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (0x1f < ~uVar5 - 1) {
      (*DAT_001c1114)(4,"Map name \'%s\' too long (32 chars)\n",*(char **)(param_2 + 8));
    }
    __src = *(char **)(param_2 + 8);
    pcVar3 = (char *)(param_1 + 0x4e8);
  }
  else {
    iVar2 = strcmp(*(char **)(param_2 + 4),"landmark");
    if (iVar2 != 0) {
      iVar2 = strcmp(*(char **)(param_2 + 4),"changetarget");
      if (iVar2 == 0) {
        uVar4 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x528) = uVar4;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar2 = strcmp(*(char **)(param_2 + 4),"changedelay");
      if (iVar2 != 0) {
        KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
        return;
      }
      lVar6 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x52c) = (float)lVar6;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    uVar5 = 0xffffffff;
    pcVar3 = *(char **)(param_2 + 8);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (0x1f < ~uVar5 - 1) {
      (*DAT_001c1114)(4,"Landmark name \'%s\' too long (32 chars)\n",*(char **)(param_2 + 8));
    }
    __src = *(char **)(param_2 + 8);
    pcVar3 = (char *)(param_1 + 0x508);
  }
  strcpy(pcVar3,__src);
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CCineMonsterP14KeyValueData_s  @ 000e7d14
void KeyValue__12CCineMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszIdle");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x68c) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszPlay");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x690) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszEntity");
      if (iVar1 != 0) {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_fMoveTo");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x698) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_flRepeat");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x6a4) = (float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_flRadius");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x6a0) = (float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_iFinishSchedule");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x69c) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
        return;
      }
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x694) = uVar2;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CMultiSourceP14KeyValueData_s  @ 0008aaec
void KeyValue__12CMultiSourceP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"style");
  if ((((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"height"), iVar1 != 0)) &&
      (iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget"), iVar1 != 0)) &&
     (((iVar1 = strcmp(*(char **)(param_2 + 4),"value1"), iVar1 != 0 &&
       (iVar1 = strcmp(*(char **)(param_2 + 4),"value2"), iVar1 != 0)) &&
      (iVar1 = strcmp(*(char **)(param_2 + 4),"value3"), iVar1 != 0)))) {
    iVar1 = strcmp(*(char **)(param_2 + 4),"globalstate");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x5cc) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    return;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CRevertSavedP14KeyValueData_s  @ 000df3e0
void KeyValue__12CRevertSavedP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1d8) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"holdtime");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1dc) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"messagetime");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x112] = (int)(float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"loadtime");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0x113] = (int)(float)lVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        }
      }
    }
  }
  return;
}


// KeyValue__12CTalkMonsterP14KeyValueData_s  @ 000f6d88
void KeyValue__12CTalkMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"UseSentence");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x6e4) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"UnUseSentence");
    if (iVar1 != 0) {
      KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
      return;
    }
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x6e8) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CTriggerPushP14KeyValueData_s  @ 00113e40
void KeyValue__12CTriggerPushP14KeyValueData_s(undefined4 param_1,undefined4 param_2)

{
  KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  return;
}


// KeyValue__13CEnvExplosionP14KeyValueData_s  @ 000a7624
void KeyValue__13CEnvExplosionP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"iMagnitude");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x68c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__13CFuncRotatingP14KeyValueData_s  @ 00088a24
void KeyValue__13CFuncRotatingP14KeyValueData_s(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"fanfriction");
  if (iVar2 == 0) {
    lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    param_1[0x112] = (int)(float)((longdouble)0.01 * lVar4);
  }
  else {
    iVar2 = strcmp(*(char **)(param_2 + 4),"Volume");
    if (iVar2 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[0x114] = (int)(float)((longdouble)0.1 * lVar4);
      if (1.0 < (float)param_1[0x114]) {
        param_1[0x114] = 0x3f800000;
      }
      fVar1 = (float)param_1[0x114];
      if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        param_1[0x114] = 0;
      }
    }
    else {
      iVar2 = strcmp(*(char **)(param_2 + 4),"spawnorigin");
      if (iVar2 == 0) {
        UTIL_StringToVector__FPfPCc(&local_10,*(undefined4 *)(param_2 + 8));
        bVar3 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(local_10)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(g_vecZero == local_10) << 0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(local_c)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe4 == local_c) << 0xe) >> 8)) == 0x40)) {
          bVar3 = (byte)(DAT_001c0fe8 < local_8 |
                         (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(local_8)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(DAT_001c0fe8 == local_8) << 0xe) >> 8)) == 0x40;
        }
        if (bVar3) {
          return;
        }
        iVar2 = *param_1;
        *(float *)(iVar2 + 8) = local_10;
        *(float *)(iVar2 + 0xc) = local_c;
        *(float *)(iVar2 + 0x10) = local_8;
        return;
      }
      iVar2 = strcmp(*(char **)(param_2 + 4),"sounds");
      if (iVar2 != 0) {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        return;
      }
      iVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      param_1[0x116] = iVar2;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__13CMultiManagerP14KeyValueData_s  @ 001112ec
void KeyValue__13CMultiManagerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined1 local_84 [132];
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x470) = (float)lVar3;
  }
  else {
    if (0xf < *(int *)(param_1 + 0x4e8)) {
      return;
    }
    UTIL_StripToken__FPCcPc(*(undefined4 *)(param_2 + 4),local_84);
    uVar2 = (*DAT_001c112c)(local_84);
    *(undefined4 *)(*(int *)(param_1 + 0x4e8) * 4 + 0x4f4 + param_1) = uVar2;
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*(int *)(param_1 + 0x4e8) * 4 + 0x534 + param_1) = (float)lVar3;
    *(int *)(param_1 + 0x4e8) = *(int *)(param_1 + 0x4e8) + 1;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__13CTriggerRelayP14KeyValueData_s  @ 00111170
void KeyValue__13CTriggerRelayP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"triggerstate");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x450) = 0;
    }
    else {
      if (iVar1 != 2) {
        FUN_001111d4();
        return;
      }
      *(undefined4 *)(param_1 + 0x450) = 3;
    }
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CBasePlatTrainP14KeyValueData_s  @ 000cd2b0
void KeyValue__14CBasePlatTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"lip");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x474) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x470) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"height");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x4b4) = (float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"rotation");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x4d4) = (float)lVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
          if (iVar1 == 0) {
            lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x4e8) = (char)(longlong)ROUND(lVar2);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"stopsnd");
            if (iVar1 == 0) {
              lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(char *)(param_1 + 0x4e9) = (char)(longlong)ROUND(lVar2);
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                *(float *)(param_1 + 0x4ec) = (float)lVar2;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
              }
            }
          }
        }
      }
    }
  }
  return;
}


// KeyValue__14CFuncTankLaserP14KeyValueData_s  @ 000ac800
void KeyValue__14CFuncTankLaserP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"laserentity");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1d4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__9CFuncTankP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CMomentaryDoorP14KeyValueData_s  @ 0009f75c
void KeyValue__14CMomentaryDoorP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(char *)(param_1 + 0x4e8) = (char)(longlong)ROUND(lVar2);
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"stopsnd");
    if ((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"healthvalue"), iVar1 != 0)) {
      KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
      return;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__14CTargetCDAudioP14KeyValueData_s  @ 00111e10
void KeyValue__14CTargetCDAudioP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x144) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CTriggerCameraP14KeyValueData_s  @ 00114980
void KeyValue__14CTriggerCameraP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x468) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"moveto");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x464) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"acceleration");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x480) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"deceleration");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x484) = (float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
        }
      }
    }
  }
  return;
}


// KeyValue__15CAmbientGenericP14KeyValueData_s  @ 000ee1f0
void KeyValue__15CAmbientGenericP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"preset");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x44c) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"pitch");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x450) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      if (0xff < *(int *)(param_1 + 0x450)) {
        *(undefined4 *)(param_1 + 0x450) = 0xff;
      }
      if (-1 < *(int *)(param_1 + 0x450)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x450) = 0;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"pitchstart");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x454) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      if (0xff < *(int *)(param_1 + 0x454)) {
        *(undefined4 *)(param_1 + 0x454) = 0xff;
      }
      if (-1 < *(int *)(param_1 + 0x454)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x454) = 0;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"spinup");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(int *)(param_1 + 0x458) = iVar1;
      if (100 < iVar1) {
        *(undefined4 *)(param_1 + 0x458) = 100;
      }
      if (*(int *)(param_1 + 0x458) < 0) {
        *(undefined4 *)(param_1 + 0x458) = 0;
      }
      if (0 < *(int *)(param_1 + 0x458)) {
        *(int *)(param_1 + 0x458) = (0x65 - *(int *)(param_1 + 0x458)) * 0x40;
      }
      *(undefined4 *)(param_1 + 0x48c) = *(undefined4 *)(param_1 + 0x458);
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"spindown");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(int *)(param_1 + 0x45c) = iVar1;
        if (100 < iVar1) {
          *(undefined4 *)(param_1 + 0x45c) = 100;
        }
        if (*(int *)(param_1 + 0x45c) < 0) {
          *(undefined4 *)(param_1 + 0x45c) = 0;
        }
        if (0 < *(int *)(param_1 + 0x45c)) {
          *(int *)(param_1 + 0x45c) = (0x65 - *(int *)(param_1 + 0x45c)) * 0x40;
        }
        *(undefined4 *)(param_1 + 0x490) = *(undefined4 *)(param_1 + 0x45c);
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"volstart");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(int *)(param_1 + 0x464) = iVar1;
          if (10 < iVar1) {
            *(undefined4 *)(param_1 + 0x464) = 10;
          }
          if (*(int *)(param_1 + 0x464) < 0) {
            *(undefined4 *)(param_1 + 0x464) = 0;
          }
          *(int *)(param_1 + 0x464) = *(int *)(param_1 + 0x464) * 10;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"fadein");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(int *)(param_1 + 0x468) = iVar1;
            if (100 < iVar1) {
              *(undefined4 *)(param_1 + 0x468) = 100;
            }
            if (*(int *)(param_1 + 0x468) < 0) {
              *(undefined4 *)(param_1 + 0x468) = 0;
            }
            if (0 < *(int *)(param_1 + 0x468)) {
              *(int *)(param_1 + 0x468) = (0x65 - *(int *)(param_1 + 0x468)) * 0x40;
            }
            *(undefined4 *)(param_1 + 0x49c) = *(undefined4 *)(param_1 + 0x468);
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"fadeout");
            if (iVar1 == 0) {
              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(int *)(param_1 + 0x46c) = iVar1;
              if (100 < iVar1) {
                *(undefined4 *)(param_1 + 0x46c) = 100;
              }
              if (*(int *)(param_1 + 0x46c) < 0) {
                *(undefined4 *)(param_1 + 0x46c) = 0;
              }
              if (0 < *(int *)(param_1 + 0x46c)) {
                *(int *)(param_1 + 0x46c) = (0x65 - *(int *)(param_1 + 0x46c)) * 0x40;
              }
              *(undefined4 *)(param_1 + 0x4a0) = *(undefined4 *)(param_1 + 0x46c);
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"lfotype");
              if (iVar1 == 0) {
                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                *(int *)(param_1 + 0x470) = iVar1;
                if (4 < iVar1) {
                  *(undefined4 *)(param_1 + 0x470) = 2;
                }
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"lforate");
                if (iVar1 == 0) {
                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                  *(int *)(param_1 + 0x474) = iVar1;
                  if (1000 < iVar1) {
                    *(undefined4 *)(param_1 + 0x474) = 1000;
                  }
                  if (*(int *)(param_1 + 0x474) < 0) {
                    *(undefined4 *)(param_1 + 0x474) = 0;
                  }
                  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) << 8;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"lfomodpitch");
                  if (iVar1 == 0) {
                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                    *(int *)(param_1 + 0x478) = iVar1;
                    if (100 < iVar1) {
                      *(undefined4 *)(param_1 + 0x478) = 100;
                    }
                    if (*(int *)(param_1 + 0x478) < 0) {
                      *(undefined4 *)(param_1 + 0x478) = 0;
                    }
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"lfomodvol");
                    if (iVar1 == 0) {
                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                      *(int *)(param_1 + 0x47c) = iVar1;
                      if (100 < iVar1) {
                        *(undefined4 *)(param_1 + 0x47c) = 100;
                      }
                      if (*(int *)(param_1 + 0x47c) < 0) {
                        *(undefined4 *)(param_1 + 0x47c) = 0;
                      }
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"cspinup");
                      if (iVar1 != 0) {
                        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
                        return;
                      }
                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                      *(int *)(param_1 + 0x480) = iVar1;
                      if (100 < iVar1) {
                        *(undefined4 *)(param_1 + 0x480) = 100;
                      }
                      if (*(int *)(param_1 + 0x480) < 0) {
                        *(undefined4 *)(param_1 + 0x480) = 0;
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


// KeyValue__15CFuncTankMortarP14KeyValueData_s  @ 000acfa4
void KeyValue__15CFuncTankMortarP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"iMagnitude");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(*param_1 + 0x184) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__9CFuncTankP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__15CFuncTrackTrainP14KeyValueData_s  @ 000cf29c
void KeyValue__15CFuncTrackTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wheels");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x44c) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"height");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x450) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"startspeed");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x45c) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x47c) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(float *)(param_1 + 0x480) = (float)iVar1;
            *(float *)(param_1 + 0x480) = *(float *)(param_1 + 0x480) * 0.1;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"bank");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(float *)(param_1 + 0x484) = (float)lVar3;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
            }
          }
        }
      }
    }
  }
  return;
}


// KeyValue__16CFuncIllusionaryP14KeyValueData_s  @ 000887f4
void KeyValue__16CFuncIllusionaryP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"skin");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(int *)(*param_1 + 0x110) = (int)ROUND(lVar2);
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__16CFuncMortarFieldP14KeyValueData_s  @ 000c2f04
void KeyValue__16CFuncMortarFieldP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszXController");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x4e8) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszYController");
    if (iVar1 != 0) {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_flSpread");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x4f0) = (float)lVar3;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_fControl");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x4fc) = uVar2;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"m_iCount");
          if (iVar1 != 0) {
            return;
          }
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x4f8) = uVar2;
        }
      }
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x4ec) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__16CFuncTrackChangeP14KeyValueData_s  @ 000d1350
void KeyValue__16CFuncTrackChangeP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"train");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x51c) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"toptrack");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x514) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"bottomtrack");
      if (iVar1 != 0) {
        KeyValue__14CBasePlatTrainP14KeyValueData_s(param_1,param_2);
        return;
      }
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x518) = uVar2;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__17CFrictionModifierP14KeyValueData_s  @ 00110e18
void KeyValue__17CFrictionModifierP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"modifier");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x448) = (float)((longdouble)0.01 * lVar2);
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__17CScriptedSentenceP14KeyValueData_s  @ 000e9640
void KeyValue__17CScriptedSentenceP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"sentence");
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    param_1[0x13a] = iVar1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),(char *)FUN_0014cb38);
    if (iVar1 == 0) {
      iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      param_1[0x13b] = iVar1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x13d] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x13c] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"refire");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x13e] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"attenuation");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(*param_1 + 0x184) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x140] = (int)(float)((longdouble)0.1 * lVar3);
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"listener");
      if (iVar1 != 0) {
        KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
        return;
      }
      iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      param_1[0x142] = iVar1;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__18CTriggerEndSectionP14KeyValueData_s  @ 001145d0
void KeyValue__18CTriggerEndSectionP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"section");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1d4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__19CMomentaryRotButtonP14KeyValueData_s  @ 0008cb08
void KeyValue__19CMomentaryRotButtonP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"returnspeed");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x4f0) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x50c) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__20CTriggerChangeTargetP14KeyValueData_s  @ 00114760
void KeyValue__20CTriggerChangeTargetP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszNewTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x450) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__5CFadeP14KeyValueData_s  @ 000a4dc8
void KeyValue__5CFadeP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1d8) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"holdtime");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1dc) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__5CItemP14KeyValueData_s  @ 000b6a9c
void KeyValue__5CItemP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"respawn_delay");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x448) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__6CBloodP14KeyValueData_s  @ 000a4760
void KeyValue__6CBloodP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"color");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 1) {
      *(undefined4 *)(*param_1 + 0x184) = 0xc3;
    }
    else {
      *(undefined4 *)(*param_1 + 0x184) = 0xf7;
    }
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"amount");
    if (iVar1 != 0) {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      return;
    }
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1e0) = (float)lVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__6CDecalP14KeyValueData_s  @ 0012242c
void KeyValue__6CDecalP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c10d0)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x110) = uVar2;
    if (*(int *)(*param_1 + 0x110) < 0) {
      (*DAT_001c1114)(1,"Can\'t find decal %s\n",*(undefined4 *)(param_2 + 8));
    }
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__6CLaserP14KeyValueData_s  @ 000a2974
void KeyValue__6CLaserP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"LaserTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1d4) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"width");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x144) = (float)(int)ROUND(lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"NoiseAmplitude");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(*param_1 + 0x114) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"TextureScroll");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(float *)(*param_1 + 0x134) = (float)iVar1;
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(*param_1 + 0xb8) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"EndSprite");
      if (iVar1 != 0) {
        iVar1 = strcmp(*(char **)(param_2 + 4),"framestart");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(float *)(*param_1 + 0x130) = (float)iVar1;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(*param_1 + 0x1e0) = (float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
          return;
        }
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        return;
      }
      iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
      param_1[0x113] = iVar1;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__6CLightP14KeyValueData_s  @ 000b6f3c
void KeyValue__6CLightP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"style");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0x112] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"pitch");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x50) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"pattern");
      if (iVar1 == 0) {
        iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
        param_1[0x113] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__6CShakeP14KeyValueData_s  @ 000a4bec
void KeyValue__6CShakeP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"amplitude");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x144) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"frequency");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1dc) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(*param_1 + 0x1d8) = (float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(*param_1 + 0x1e0) = (float)lVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        }
      }
    }
  }
  return;
}


// KeyValue__6CWorldP14KeyValueData_s  @ 00123b2c
void KeyValue__6CWorldP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"skyname");
  if (iVar1 == 0) {
    (*DAT_001c1110)("sv_skyname",*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(gpGlobals + 0x8c) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"WaveHeight");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x144) = (float)((longdouble)0.125 * lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
      (*DAT_001c110c)("sv_wateramp",*(undefined4 *)(*param_1 + 0x144));
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"MaxRange");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1f8) = (float)lVar3;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"chaptertitle");
      if (iVar1 == 0) {
        uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(*param_1 + 0x1d0) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"startdark");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_2 + 0xc) = 1;
        if (iVar1 == 0) {
          return;
        }
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
        return;
      }
      iVar1 = strcmp(*(char **)(param_2 + 4),"newunit");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        if (iVar1 != 0) {
          (*DAT_001c110c)("sv_newunit",0x3f800000);
        }
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"gametitle");
        if (iVar1 != 0) {
          KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
          return;
        }
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        if (iVar1 != 0) {
          *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 2;
        }
      }
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__7CLadderP14KeyValueData_s  @ 00113d1c
void KeyValue__7CLadderP14KeyValueData_s(undefined4 param_1,undefined4 param_2)

{
  KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  return;
}


// KeyValue__8CAreaDefP14KeyValueData_s  @ 000871ac
void KeyValue__8CAreaDefP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"areaname");
  if (iVar1 == 0) {
    strncpy((char *)(param_1 + 0x4d8),*(char **)(param_2 + 8),0x1f);
    *(undefined1 *)(param_1 + 0x4f7) = 0;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CDeadHEVP14KeyValueData_s  @ 000df104
void KeyValue__8CDeadHEVP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"pose");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x68c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CMessageP14KeyValueData_s  @ 000a5038
void KeyValue__8CMessageP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"messagesound");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1e8) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"messagevolume");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x144) = (float)((longdouble)0.1 * lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"messageattenuation");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(*param_1 + 0x184) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__8CNodeEntP14KeyValueData_s  @ 000c6810
void KeyValue__8CNodeEntP14KeyValueData_s(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"hinttype");
  if (iVar2 == 0) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined2 *)(param_1 + 0x448) = uVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  iVar2 = strcmp(*(char **)(param_2 + 4),"activity");
  if (iVar2 == 0) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined2 *)(param_1 + 0x44a) = uVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CSpeakerP14KeyValueData_s  @ 000f0704
void KeyValue__8CSpeakerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"preset");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x448) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__9CBaseDoorP14KeyValueData_s  @ 0009d700
void KeyValue__9CBaseDoorP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"skin");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(int *)(*param_1 + 0x110) = (int)ROUND(lVar2);
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(char *)((int)param_1 + 0x4e9) = (char)(longlong)ROUND(lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"stopsnd");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(char *)((int)param_1 + 0x4ea) = (char)(longlong)ROUND(lVar2);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"healthvalue");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(char *)(param_1 + 0x13a) = (char)(longlong)ROUND(lVar2);
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sound");
          if (iVar1 == 0) {
            lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x144) = (char)(longlong)ROUND(lVar2);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sentence");
            if (iVar1 == 0) {
              lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(char *)((int)param_1 + 0x511) = (char)(longlong)ROUND(lVar2);
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sound");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                *(char *)((int)param_1 + 0x512) = (char)(longlong)ROUND(lVar2);
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sentence");
                if (iVar1 == 0) {
                  lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  *(char *)((int)param_1 + 0x513) = (char)(longlong)ROUND(lVar2);
                  *(undefined4 *)(param_2 + 0xc) = 1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"WaveHeight");
                  if (iVar1 == 0) {
                    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                    *(float *)(*param_1 + 0x144) = (float)((longdouble)0.125 * lVar2);
                    *(undefined4 *)(param_2 + 0xc) = 1;
                  }
                  else {
                    KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// KeyValue__9CBubblingP14KeyValueData_s  @ 0009fe54
void KeyValue__9CBubblingP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"density");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0x112] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"frequency");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      param_1[0x113] = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"current");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(float *)(*param_1 + 0x1f8) = (float)iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__9CEnvLightP14KeyValueData_s  @ 000b71e4
/* WARNING: Removing unreachable block (ram,0x000b74f2) */
/* WARNING: Removing unreachable block (ram,0x000b74fe) */
/* WARNING: Removing unreachable block (ram,0x000b741a) */
/* WARNING: Removing unreachable block (ram,0x000b7325) */
/* WARNING: Removing unreachable block (ram,0x000b7331) */
/* WARNING: Removing unreachable block (ram,0x000b7335) */
/* WARNING: Removing unreachable block (ram,0x000b7348) */
/* WARNING: Removing unreachable block (ram,0x000b734d) */
/* WARNING: Removing unreachable block (ram,0x000b734f) */
/* WARNING: Removing unreachable block (ram,0x000b7346) */
/* WARNING: Removing unreachable block (ram,0x000b740a) */
/* WARNING: Removing unreachable block (ram,0x000b7416) */
/* WARNING: Removing unreachable block (ram,0x000b7430) */
/* WARNING: Removing unreachable block (ram,0x000b7435) */
/* WARNING: Removing unreachable block (ram,0x000b7437) */
/* WARNING: Removing unreachable block (ram,0x000b7444) */
/* WARNING: Removing unreachable block (ram,0x000b7502) */
/* WARNING: Removing unreachable block (ram,0x000b7518) */
/* WARNING: Removing unreachable block (ram,0x000b751d) */
/* WARNING: Removing unreachable block (ram,0x000b751f) */
/* WARNING: Removing unreachable block (ram,0x000b7513) */

void KeyValue__9CEnvLightP14KeyValueData_s(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  longdouble lVar2;
  longdouble lVar3;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined8 local_58;
  undefined2 local_50;
  undefined2 uStack_4e;
  undefined4 local_4c;
  undefined2 local_44;
  undefined2 uStack_42;
  char acStack_40 [64];
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"_light");
  if (iVar1 == 0) {
    iVar1 = sscanf(*(char **)(param_2 + 8),"%d %d %d %d\n",&local_68,&local_64,&local_60,&local_5c);
    if (iVar1 == 1) {
      local_60 = local_68;
      local_64 = local_68;
    }
    else if (iVar1 == 4) {
      local_68 = (int)ROUND((double)local_68 * 0.00392156862745098 * (double)local_5c);
      local_64 = (int)ROUND((double)local_64 * 0.00392156862745098 * (double)local_5c);
      local_60 = (int)ROUND((double)local_60 * 0.00392156862745098 * (double)local_5c);
    }
    lVar2 = (longdouble)0.008771929824561403 * (longdouble)local_68;
    lVar3 = (longdouble)0.0;
    if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) {
      lVar2 = (longdouble)log2(lVar2);
      lVar2 = (longdouble)1 * lVar2 * (longdouble)0.6;
      lVar3 = ROUND(lVar2);
      lVar2 = (longdouble)f2xm1(lVar2 - lVar3);
      lVar3 = (longdouble)fscale(lVar2 + (longdouble)1.0,lVar3);
    }
    local_68 = (int)ROUND((longdouble)264.0 * lVar3);
    lVar2 = (longdouble)0.008771929824561403 * (longdouble)local_64;
    lVar3 = (longdouble)0.0;
    if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) {
      lVar2 = (longdouble)log2(lVar2);
      lVar2 = (longdouble)1 * lVar2 * (longdouble)0.6;
      lVar3 = ROUND(lVar2);
      lVar2 = (longdouble)f2xm1(lVar2 - lVar3);
      lVar3 = (longdouble)fscale(lVar2 + (longdouble)1.0,lVar3);
    }
    local_64 = (int)ROUND((longdouble)264.0 * lVar3);
    lVar2 = (longdouble)0.008771929824561403 * (longdouble)local_60;
    _local_50 = CONCAT22(uStack_4e,in_FPUControlWord);
    local_58 = 1;
    lVar3 = (longdouble)0.0;
    if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) {
      lVar2 = (longdouble)log2(lVar2);
      lVar2 = (longdouble)1 * lVar2 * (longdouble)0.6;
      lVar3 = ROUND(lVar2);
      lVar2 = (longdouble)f2xm1(lVar2 - lVar3);
      lVar3 = (longdouble)fscale(lVar2 + (longdouble)1.0,lVar3);
    }
    _local_44 = CONCAT22(uStack_42,in_FPUControlWord);
    local_4c = CONCAT22(uStack_42,CONCAT11(0xc,(char)in_FPUControlWord));
    local_60 = (int)ROUND((longdouble)264.0 * lVar3);
    *(undefined4 *)(param_2 + 0xc) = 1;
    sprintf(acStack_40,"%d",local_68);
    (*DAT_001c1110)("sv_skycolor_r",acStack_40);
    sprintf(acStack_40,"%d",local_64);
    (*DAT_001c1110)("sv_skycolor_g",acStack_40);
    sprintf(acStack_40,"%d",local_60);
    (*DAT_001c1110)("sv_skycolor_b",acStack_40);
  }
  else {
    KeyValue__6CLightP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__9CEnvSoundP14KeyValueData_s  @ 000ee7fc
void KeyValue__9CEnvSoundP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x448) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"roomtype");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x44c) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  return;
}


// KeyValue__9CEnvSparkP14KeyValueData_s  @ 0008d454
void KeyValue__9CEnvSparkP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"MaxDelay");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x448) = (float)lVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"style");
    if ((((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"height"), iVar1 != 0)) &&
        (iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget"), iVar1 != 0)) &&
       (((iVar1 = strcmp(*(char **)(param_2 + 4),"value1"), iVar1 != 0 &&
         (iVar1 = strcmp(*(char **)(param_2 + 4),"value2"), iVar1 != 0)) &&
        (iVar1 = strcmp(*(char **)(param_2 + 4),"value3"), iVar1 != 0)))) {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      return;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__9CFuncTankP14KeyValueData_s  @ 000aa6c4
void KeyValue__9CFuncTankP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"yawrate");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    param_1[0x118] = (int)(float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"yawrange");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[0x119] = (int)(float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"yawtolerance");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x11a] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"pitchrange");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0x11d] = (int)(float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"pitchrate");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            param_1[0x11c] = (int)(float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"pitchtolerance");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              param_1[0x11e] = (int)(float)lVar3;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"firerate");
              if (iVar1 == 0) {
                lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                param_1[0x120] = (int)(float)lVar3;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"barrel");
                if (iVar1 == 0) {
                  lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  param_1[0x125] = (int)(float)lVar3;
                  *(undefined4 *)(param_2 + 0xc) = 1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"barrely");
                  if (iVar1 == 0) {
                    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                    param_1[0x126] = (int)(float)lVar3;
                    *(undefined4 *)(param_2 + 0xc) = 1;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"barrelz");
                    if (iVar1 == 0) {
                      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                      param_1[0x127] = (int)(float)lVar3;
                      *(undefined4 *)(param_2 + 0xc) = 1;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"spritescale");
                      if (iVar1 == 0) {
                        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                        param_1[0x128] = (int)(float)lVar3;
                        *(undefined4 *)(param_2 + 0xc) = 1;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(param_2 + 4),"spritesmoke");
                        if (iVar1 == 0) {
                          iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                          param_1[0x129] = iVar1;
                        }
                        else {
                          iVar1 = strcmp(*(char **)(param_2 + 4),"spriteflash");
                          if (iVar1 == 0) {
                            iVar1 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                            param_1[0x12a] = iVar1;
                          }
                          else {
                            iVar1 = strcmp(*(char **)(param_2 + 4),"rotatesound");
                            if (iVar1 != 0) {
                              iVar1 = strcmp(*(char **)(param_2 + 4),"persistence");
                              if (iVar1 == 0) {
                                lVar3 = (longdouble)
                                        __strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                                param_1[0x122] = (int)(float)lVar3;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                                return;
                              }
                              iVar1 = strcmp(*(char **)(param_2 + 4),"bullet");
                              if (iVar1 == 0) {
                                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                param_1[299] = iVar1;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                                return;
                              }
                              iVar1 = strcmp(*(char **)(param_2 + 4),"bullet_damage");
                              if (iVar1 == 0) {
                                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                param_1[300] = iVar1;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                                return;
                              }
                              iVar1 = strcmp(*(char **)(param_2 + 4),"firespread");
                              if (iVar1 == 0) {
                                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                param_1[0x130] = iVar1;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                                return;
                              }
                              iVar1 = strcmp(*(char **)(param_2 + 4),"minRange");
                              if (iVar1 == 0) {
                                lVar3 = (longdouble)
                                        __strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                                param_1[0x123] = (int)(float)lVar3;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                                return;
                              }
                              iVar1 = strcmp(*(char **)(param_2 + 4),"maxRange");
                              if (iVar1 == 0) {
                                lVar3 = (longdouble)
                                        __strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                                param_1[0x124] = (int)(float)lVar3;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                                return;
                              }
                              KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
                              return;
                            }
                            uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
                            *(undefined4 *)(*param_1 + 0x1e8) = uVar2;
                          }
                        }
                        *(undefined4 *)(param_2 + 0xc) = 1;
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
  return;
}


// KeyValue__9CPendulumP14KeyValueData_s  @ 00089b7c
void KeyValue__9CPendulumP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x44c) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"damp");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x454) = (float)((longdouble)0.001 * lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__9CPushableP14KeyValueData_s  @ 000a9ce0
void KeyValue__9CPushableP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  longdouble lVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"size");
  if (iVar1 != 0) {
    iVar1 = strcmp(*(char **)(param_2 + 4),"buoyancy");
    if (iVar1 == 0) {
      lVar5 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(int *)(*param_1 + 0x110) = (int)ROUND(lVar5);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    KeyValue__10CBreakableP14KeyValueData_s(param_1,param_2);
    return;
  }
  uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
  *(undefined4 *)(param_2 + 0xc) = 1;
  switch(uVar2) {
  case 0:
    local_c = 0x41000000;
    puVar4 = &local_c;
    uStack_18 = 0xc1000000;
    puVar3 = &uStack_18;
    uStack_14 = uStack_18;
    uStack_10 = uStack_18;
    local_8 = local_c;
    local_4 = local_c;
    goto LAB_000a9e64;
  default:
    local_2c = 0x41800000;
    local_28 = 0x42100000;
    puVar4 = &local_30;
    uStack_24 = 0xc1800000;
    break;
  case 2:
    local_c = 0x41800000;
    local_4 = 0x41900000;
    uStack_18 = 0x42000000;
    uStack_10 = 0x42100000;
    puVar4 = &uStack_18;
    local_2c = 0xc1800000;
    local_28 = 0xc1900000;
    uStack_24 = 0xc2000000;
    uStack_14 = uStack_18;
    local_8 = local_c;
    break;
  case 3:
    local_c = 0x41800000;
    local_4 = 0x41900000;
    puVar4 = &local_c;
    local_30 = 0xc1800000;
    local_28 = 0xc1900000;
    puVar3 = &local_30;
    local_2c = local_30;
    local_8 = local_c;
    goto LAB_000a9e64;
  }
  uStack_1c = 0xc2100000;
  puVar3 = &uStack_24;
  local_30 = local_2c;
  uStack_20 = uStack_24;
LAB_000a9e64:
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,puVar3,puVar4);
  return;
}


// KeyValue__9CRechargeP14KeyValueData_s  @ 000b35a8
void KeyValue__9CRechargeP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"style");
  if ((((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"height"), iVar1 != 0)) &&
      (iVar1 = strcmp(*(char **)(param_2 + 4),"value1"), iVar1 != 0)) &&
     ((iVar1 = strcmp(*(char **)(param_2 + 4),"value2"), iVar1 != 0 &&
      (iVar1 = strcmp(*(char **)(param_2 + 4),"value3"), iVar1 != 0)))) {
    iVar1 = strcmp(*(char **)(param_2 + 4),"dmdelay");
    if (iVar1 != 0) {
      KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
      return;
    }
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x4ec) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


