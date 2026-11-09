// KeyValue__10CBaseDelayP14KeyValueData_s  @ 000f0470
void KeyValue__10CBaseDelayP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"delay");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3cc) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x3d0) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__10CBreakableP14KeyValueData_s  @ 000b1ff0
void KeyValue__10CBreakableP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"explosion");
  if (iVar1 == 0) {
    iVar1 = strcasecmp(*(char **)(param_2 + 8),"directed");
    if (iVar1 == 0) {
      param_1[0xf6] = 1;
    }
    else {
      strcasecmp(*(char **)(param_2 + 8),"random");
      param_1[0xf6] = 0;
    }
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"material");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      if (uVar2 < 10) {
        param_1[0xf5] = uVar2;
      }
      else {
        param_1[0xf5] = 1;
      }
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"deadmodel");
      if ((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"shards"), iVar1 != 0)) {
        iVar1 = strcmp(*(char **)(param_2 + 4),"gibmodel");
        if (iVar1 == 0) {
          iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
          param_1[0xf9] = iVar1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"spawnobject");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            if (iVar1 - 1U < 0x15) {
              param_1[0xfa] =
                   *(int *)(_10CBreakable_pSpawnObjects + iVar1 * 4) - *(int *)(gpGlobals + 0x98);
            }
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"explodemagnitude");
            if (iVar1 == 0) {
              uVar3 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(undefined4 *)(*param_1 + 0x164) = uVar3;
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
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__10CEnvGlobalP14KeyValueData_s  @ 0009d560
void KeyValue__10CEnvGlobalP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 0xc) = 1;
  iVar1 = strcmp(*(char **)(param_2 + 4),"globalstate");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x3cc) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"triggermode");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x3d0) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"initialstate");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x3d4) = uVar2;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__10CFuncTrainP14KeyValueData_s  @ 000d20d0
void KeyValue__10CFuncTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x478) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__14CBasePlatTrainP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__10CLightningP14KeyValueData_s  @ 000ac020
void KeyValue__10CLightningP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"LightningStart");
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    param_1[0xf4] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"LightningEnd");
    if (iVar1 == 0) {
      iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      param_1[0xf5] = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"life");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0xf6] = (int)(float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"BoltWidth");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          param_1[0xf7] = iVar1;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"NoiseAmplitude");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            param_1[0xf8] = iVar1;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"TextureScroll");
            if (iVar1 == 0) {
              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              param_1[0xfa] = iVar1;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"StrikeTime");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                param_1[0xfb] = (int)(float)lVar2;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
                if (iVar1 == 0) {
                  iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
                  param_1[0xfd] = iVar1;
                  *(undefined4 *)(param_2 + 0xc) = 1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"framestart");
                  if (iVar1 == 0) {
                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                    param_1[0xfe] = iVar1;
                    *(undefined4 *)(param_2 + 0xc) = 1;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"Radius");
                    if (iVar1 == 0) {
                      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                      param_1[0xff] = (int)(float)lVar2;
                      *(undefined4 *)(param_2 + 0xc) = 1;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
                      if (iVar1 == 0) {
                        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                        *(float *)(*param_1 + 0x1c0) = (float)lVar2;
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
          }
        }
      }
    }
  }
  return;
}


// KeyValue__10CPathTrackP14KeyValueData_s  @ 000d0250
void KeyValue__10CPathTrackP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"altpath");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x3d0) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__10CWeaponBoxP14KeyValueData_s  @ 0011c0e0
void KeyValue__10CWeaponBoxP14KeyValueData_s(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4ec) < 0x20) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    uVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 4),uVar1);
    PackAmmo__10CWeaponBoxii(param_1,uVar1);
    *(int *)(param_1 + 0x4ec) = *(int *)(param_1 + 0x4ec) + 1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    (*DAT_001755b4)(1,"WeaponBox too full! only %d ammotypes allowed\n",0x20);
  }
  return;
}


// KeyValue__10CWorldItemP14KeyValueData_s  @ 000bd3e0
void KeyValue__10CWorldItemP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"type");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x3cc) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__11CBaseButtonP14KeyValueData_s  @ 0009df60
void KeyValue__11CBaseButtonP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"changetarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x474) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sound");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(char *)(param_1 + 0x49c) = (char)(longlong)ROUND(lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sentence");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(char *)(param_1 + 0x49d) = (char)(longlong)ROUND(lVar3);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sound");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(char *)(param_1 + 0x49e) = (char)(longlong)ROUND(lVar3);
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sentence");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x49f) = (char)(longlong)ROUND(lVar3);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
            if (iVar1 == 0) {
              uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(undefined4 *)(param_1 + 0x4a0) = uVar2;
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


// KeyValue__11CBaseEntityP14KeyValueData_s  @ 001073a0
void KeyValue__11CBaseEntityP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  longdouble lVar4;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"goal_no");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0x84] = iVar1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"mdl");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(*param_1 + 0x98) = uVar2;
    }
    else {
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
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            param_1[0xb] = iVar1;
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
                  param_1[0x23] = iVar1;
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
                      param_1[0xf] = iVar1;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"goal_activation");
                      if ((iVar1 == 0) ||
                         (iVar1 = strcmp(*(char **)(param_2 + 4),"g_a"), iVar1 == 0)) {
                        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                        param_1[0x88] = iVar1;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(param_2 + 4),"goal_effects");
                        if ((iVar1 == 0) ||
                           (iVar1 = strcmp(*(char **)(param_2 + 4),"g_e"), iVar1 == 0)) {
                          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                          param_1[0x89] = iVar1;
                        }
                        else {
                          iVar1 = strcmp(*(char **)(param_2 + 4),"goal_result");
                          if (iVar1 == 0) {
                            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                            param_1[0x8a] = iVar1;
                          }
                          else {
                            iVar1 = strcmp(*(char **)(param_2 + 4),"goal_group");
                            if (iVar1 == 0) {
                              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                              param_1[0x8b] = iVar1;
                            }
                            else {
                              iVar1 = strcmp(*(char **)(param_2 + 4),"else_goal");
                              if (iVar1 == 0) {
                                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                param_1[0x8c] = iVar1;
                              }
                              else {
                                iVar1 = strcmp(*(char **)(param_2 + 4),"if_goal_is_active");
                                if (iVar1 == 0) {
                                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                  param_1[0x8d] = iVar1;
                                }
                                else {
                                  iVar1 = strcmp(*(char **)(param_2 + 4),"if_goal_is_inactive");
                                  if (iVar1 == 0) {
                                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                    param_1[0x8e] = iVar1;
                                  }
                                  else {
                                    iVar1 = strcmp(*(char **)(param_2 + 4),"if_goal_is_removed");
                                    if (iVar1 == 0) {
                                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0)
                                      ;
                                      param_1[0x8f] = iVar1;
                                    }
                                    else {
                                      iVar1 = strcmp(*(char **)(param_2 + 4),"if_group_is_active");
                                      if (iVar1 == 0) {
                                        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,
                                                                  0);
                                        param_1[0x90] = iVar1;
                                      }
                                      else {
                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                       "if_group_is_inactive");
                                        if (iVar1 == 0) {
                                          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,
                                                                    10,0);
                                          param_1[0x91] = iVar1;
                                        }
                                        else {
                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                         "if_group_is_removed");
                                          if (iVar1 == 0) {
                                            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0
                                                                      ,10,0);
                                            param_1[0x92] = iVar1;
                                          }
                                          else {
                                            iVar1 = strcmp(*(char **)(param_2 + 4),"search_time");
                                            if (iVar1 == 0) {
                                              lVar4 = (longdouble)
                                                      __strtod_internal(*(undefined4 *)(param_2 + 8)
                                                                        ,0,0);
                                              param_1[0x93] = (int)(float)lVar4;
                                            }
                                            else {
                                              iVar1 = strcmp(*(char **)(param_2 + 4),"t_length");
                                              if (iVar1 == 0) {
                                                lVar4 = (longdouble)
                                                        __strtod_internal(*(undefined4 *)
                                                                           (param_2 + 8),0,0);
                                                param_1[0x94] = (int)(float)lVar4;
                                              }
                                              else {
                                                iVar1 = strcmp(*(char **)(param_2 + 4),
                                                               "activate_goal_no");
                                                if (iVar1 == 0) {
                                                  iVar1 = __strtol_internal(*(undefined4 *)
                                                                             (param_2 + 8),0,10,0);
                                                  param_1[0x95] = iVar1;
                                                }
                                                else {
                                                  iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                 "inactivate_goal_no");
                                                  if (iVar1 == 0) {
                                                    iVar1 = __strtol_internal(*(undefined4 *)
                                                                               (param_2 + 8),0,10,0)
                                                    ;
                                                    param_1[0x96] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "remove_goal_no");
                                                    if ((iVar1 == 0) ||
                                                       (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "rv_g"), iVar1 == 0)) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0x97] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "restore_goal_no");
                                                      if ((iVar1 == 0) ||
                                                         (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "rs_g"), iVar1 == 0)) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0x98] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "activate_group_no");
                                                        if (iVar1 == 0) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0x99] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "inactivate_group_no");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0x9a] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "remove_group_no");
                                                            if ((iVar1 == 0) ||
                                                               (iVar1 = strcmp(*(char **)(param_2 +
                                                                                         4),"rv_gr")
                                                               , iVar1 == 0)) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0x9b] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"restore_group_no");
                                                              if ((iVar1 == 0) ||
                                                                 (iVar1 = strcmp(*(char **)(param_2 
                                                  + 4),"rs_gr"), iVar1 == 0)) {
                                                    iVar1 = __strtol_internal(*(undefined4 *)
                                                                               (param_2 + 8),0,10,0)
                                                    ;
                                                    param_1[0x9c] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "goal_min");
                                                    if (iVar1 == 0) {
                                                      UTIL_StringToVector__FPfPCc
                                                                (&fStack_14,
                                                                 *(undefined4 *)(param_2 + 8));
                                                      bVar3 = false;
                                                      if (((byte)((byte)((ushort)((ushort)(NAN(
                                                  g_vecZero) || NAN(fStack_14)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(g_vecZero == fStack_14)
                                                                 << 0xe) >> 8)) == 0x40) &&
                                                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484)
                                                                                  || NAN(fStack_10))
                                                                         << 10) >> 8) |
                                                         (byte)((ushort)((ushort)(DAT_00175484 ==
                                                                                 fStack_10) << 0xe)
                                                               >> 8)) == 0x40)) {
                                                    bVar3 = (byte)(DAT_00175488 < fStack_c |
                                                                   (byte)((ushort)((ushort)(NAN(
                                                  DAT_00175488) || NAN(fStack_c)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(DAT_00175488 == fStack_c)
                                                                 << 0xe) >> 8)) == 0x40;
                                                  }
                                                  if (!bVar3) {
                                                    param_1[0x9e] = (int)fStack_14;
                                                    param_1[0x9f] = (int)fStack_10;
                                                    param_1[0xa0] = (int)fStack_c;
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "goal_max");
                                                    if (iVar1 == 0) {
                                                      UTIL_StringToVector__FPfPCc
                                                                (&fStack_14,
                                                                 *(undefined4 *)(param_2 + 8));
                                                      bVar3 = false;
                                                      if (((byte)((byte)((ushort)((ushort)(NAN(
                                                  g_vecZero) || NAN(fStack_14)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(g_vecZero == fStack_14)
                                                                 << 0xe) >> 8)) == 0x40) &&
                                                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484)
                                                                                  || NAN(fStack_10))
                                                                         << 10) >> 8) |
                                                         (byte)((ushort)((ushort)(DAT_00175484 ==
                                                                                 fStack_10) << 0xe)
                                                               >> 8)) == 0x40)) {
                                                    bVar3 = (byte)(DAT_00175488 < fStack_c |
                                                                   (byte)((ushort)((ushort)(NAN(
                                                  DAT_00175488) || NAN(fStack_c)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(DAT_00175488 == fStack_c)
                                                                 << 0xe) >> 8)) == 0x40;
                                                  }
                                                  if (!bVar3) {
                                                    param_1[0xa1] = (int)fStack_14;
                                                    param_1[0xa2] = (int)fStack_10;
                                                    param_1[0xa3] = (int)fStack_c;
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
                                                      param_1[0xa4] = iVar1;
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
                                                        param_1[0xa5] = iVar1;
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
                                                          param_1[0xa6] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "return_item_no");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0xa7] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "if_item_has_moved");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xa8] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"if_item_hasnt_moved")
                                                              ;
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xa9] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "remove_spawnpoint");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xaa] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "restore_spawnpoint");
                                                      if (iVar1 == 0) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0xab] = iVar1;
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
                                                          param_1[0xac] = iVar1;
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
                                                            param_1[0xad] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "display_item_status1");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xae] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"display_item_status2"
                                                                            );
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xaf] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "display_item_status3");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xb0] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "display_item_status4");
                                                      if (iVar1 == 0) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0xb1] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "team_str_home");
                                                        if ((iVar1 == 0) ||
                                                           (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "t_s_g"), iVar1 == 0)) {
                                                          iVar1 = (*DAT_001755cc)(*(undefined4 *)
                                                                                   (param_2 + 8));
                                                          param_1[0xb2] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "team_str_moved");
                                                          if ((iVar1 == 0) ||
                                                             (iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"t_s_m"), iVar1 == 0))
                                                          {
                                                            iVar1 = (*DAT_001755cc)(*(undefined4 *)
                                                                                     (param_2 + 8));
                                                            param_1[0xb3] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "team_str_carried");
                                                            if ((iVar1 == 0) ||
                                                               (iVar1 = strcmp(*(char **)(param_2 +
                                                                                         4),"t_s_c")
                                                               , iVar1 == 0)) {
                                                              iVar1 = (*DAT_001755cc)(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ));
                                                              param_1[0xb4] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"non_team_str_home");
                                                              if ((iVar1 == 0) ||
                                                                 (iVar1 = strcmp(*(char **)(param_2 
                                                  + 4),"t_s_h"), iVar1 == 0)) {
                                                    iVar1 = (*DAT_001755cc)(*(undefined4 *)
                                                                             (param_2 + 8));
                                                    param_1[0xb5] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "non_team_str_moved");
                                                    if ((iVar1 == 0) ||
                                                       (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "t_s_m"), iVar1 == 0)) {
                                                      iVar1 = (*DAT_001755cc)(*(undefined4 *)
                                                                               (param_2 + 8));
                                                      param_1[0xb6] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "non_team_str_carried");
                                                      if ((iVar1 == 0) ||
                                                         (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "n_s_c"), iVar1 == 0)) {
                                                        iVar1 = (*DAT_001755cc)(*(undefined4 *)
                                                                                 (param_2 + 8));
                                                        param_1[0xb7] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "ex_skill_min");
                                                        if (iVar1 == 0) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0xb8] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "ex_skill_max");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0xb9] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "increase_team1");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xba] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"increase_team2");
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xbb] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "increase_team3");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xbc] = iVar1;
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
                                                  param_1[0xbd] = iVar1;
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
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__11CBaseToggleP14KeyValueData_s  @ 000f0ab0
void KeyValue__11CBaseToggleP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"lip");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3f8) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x3f4) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"master");
      if (iVar1 == 0) {
        uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x468) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x3f0) = (float)lVar3;
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


// KeyValue__11CBaseTurretP14KeyValueData_s  @ 00113970
void KeyValue__11CBaseTurretP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"maxsleep");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x654) = (float)lVar3;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"orientation");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x634) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"searchspeed");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x658) = uVar2;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"turnrate");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x62c) = uVar2;
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


// KeyValue__11CEnvShooterP14KeyValueData_s  @ 000aec30
void KeyValue__11CEnvShooterP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"shootmodel");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x98) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"shootsounds");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_2 + 0xc) = 1;
      switch(uVar2) {
      case 0:
        param_1[0xf7] = 0;
        break;
      case 1:
        param_1[0xf7] = 1;
        break;
      case 2:
        param_1[0xf7] = 2;
        break;
      case 3:
        param_1[0xf7] = 3;
        break;
      case 4:
        param_1[0xf7] = 8;
        break;
      default:
        param_1[0xf7] = 9;
      }
    }
    else {
      KeyValue__11CGibShooterP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__11CGibShooterP14KeyValueData_s  @ 000ae5e0
void KeyValue__11CGibShooterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iGibs");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x3d8) = uVar2;
    *(undefined4 *)(param_1 + 0x3d4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_flVelocity");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x3e4) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_flVariance");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 1000) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_flGibLife");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x3ec) = (float)lVar3;
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


// KeyValue__11CPathCornerP14KeyValueData_s  @ 000d0150
void KeyValue__11CPathCornerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3cc) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__11CWallHealthP14KeyValueData_s  @ 000bce80
void KeyValue__11CWallHealthP14KeyValueData_s(int param_1,int param_2)

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
    *(undefined4 *)(param_1 + 0x470) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CAutoTriggerP14KeyValueData_s  @ 0010f4b0
void KeyValue__12CAutoTriggerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"globalstate");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x3d4) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"triggerstate");
    if (iVar1 != 0) {
      KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
      return;
    }
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x3d8) = 0;
    }
    else if (iVar1 == 2) {
      *(undefined4 *)(param_1 + 0x3d8) = 3;
    }
    else {
      *(undefined4 *)(param_1 + 0x3d8) = 1;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CBaseMonsterP14KeyValueData_s  @ 000c72b0
void KeyValue__12CBaseMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"TriggerTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x5f8) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"TriggerCondition");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x5f4) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__12CBaseTriggerP14KeyValueData_s  @ 0010fe60
void KeyValue__12CBaseTriggerP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1c0) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"count");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[0x10d] = (int)ROUND(lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"damagetype");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        param_1[0x119] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__12CChangeLevelP14KeyValueData_s  @ 00110f40
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
      (*DAT_001755b4)(4,"Map name \'%s\' too long (32 chars)\n",*(char **)(param_2 + 8));
    }
    __src = *(char **)(param_2 + 8);
    pcVar3 = (char *)(param_1 + 0x46c);
  }
  else {
    iVar2 = strcmp(*(char **)(param_2 + 4),"landmark");
    if (iVar2 != 0) {
      iVar2 = strcmp(*(char **)(param_2 + 4),"changetarget");
      if (iVar2 == 0) {
        uVar4 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x4ac) = uVar4;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar2 = strcmp(*(char **)(param_2 + 4),"changedelay");
      if (iVar2 == 0) {
        lVar6 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x4b0) = (float)lVar6;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
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
      (*DAT_001755b4)(4,"Landmark name \'%s\' too long (32 chars)\n",*(char **)(param_2 + 8));
    }
    __src = *(char **)(param_2 + 8);
    pcVar3 = (char *)(param_1 + 0x48c);
  }
  strcpy(pcVar3,__src);
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CCineMonsterP14KeyValueData_s  @ 000e6db0
void KeyValue__12CCineMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszIdle");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x610) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszPlay");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x614) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszEntity");
      if (iVar1 == 0) {
        uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x618) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_fMoveTo");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x61c) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"m_flRepeat");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x628) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"m_flRadius");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(float *)(param_1 + 0x624) = (float)lVar3;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"m_iFinishSchedule");
              if (iVar1 == 0) {
                uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                *(undefined4 *)(param_1 + 0x620) = uVar2;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
              }
            }
          }
        }
      }
    }
  }
  return;
}


// KeyValue__12CMultiSourceP14KeyValueData_s  @ 0009d7f0
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
    if (iVar1 != 0) {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      return;
    }
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x550) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CRevertSavedP14KeyValueData_s  @ 000dffa0
void KeyValue__12CRevertSavedP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1b8) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"holdtime");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1bc) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"messagetime");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0xf3] = (int)(float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"loadtime");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0xf4] = (int)(float)lVar2;
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


// KeyValue__12CTalkMonsterP14KeyValueData_s  @ 000f32d0
void KeyValue__12CTalkMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"UseSentence");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x668) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"UnUseSentence");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x66c) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__12CTriggerPushP14KeyValueData_s  @ 00111c50
void KeyValue__12CTriggerPushP14KeyValueData_s(undefined4 param_1,undefined4 param_2)

{
  KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  return;
}


// KeyValue__13CEnvExplosionP14KeyValueData_s  @ 000b1940
void KeyValue__13CEnvExplosionP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"iMagnitude");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x610) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__13CFuncRotatingP14KeyValueData_s  @ 0009bb70
void KeyValue__13CFuncRotatingP14KeyValueData_s(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  float local_14;
  float local_10;
  float local_c;
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"fanfriction");
  if (iVar2 == 0) {
    lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    param_1[0xf3] = (int)(float)(lVar4 / (longdouble)100.0);
  }
  else {
    iVar2 = strcmp(*(char **)(param_2 + 4),"Volume");
    if (iVar2 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[0xf5] = (int)(float)(lVar4 / (longdouble)10.0);
      fVar1 = (float)param_1[0xf5];
      if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
        param_1[0xf5] = 0x3f800000;
      }
      if ((float)param_1[0xf5] < 0.0) {
        param_1[0xf5] = 0;
      }
    }
    else {
      iVar2 = strcmp(*(char **)(param_2 + 4),"spawnorigin");
      if (iVar2 == 0) {
        UTIL_StringToVector__FPfPCc(&local_14,*(undefined4 *)(param_2 + 8));
        bVar3 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(local_14)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(g_vecZero == local_14) << 0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(local_10)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175484 == local_10) << 0xe) >> 8)) == 0x40)) {
          bVar3 = (byte)(DAT_00175488 < local_c |
                         (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(local_c)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(DAT_00175488 == local_c) << 0xe) >> 8)) == 0x40;
        }
        if (bVar3) {
          return;
        }
        iVar2 = *param_1;
        *(float *)(iVar2 + 8) = local_14;
        *(float *)(iVar2 + 0xc) = local_10;
        *(float *)(iVar2 + 0x10) = local_c;
        return;
      }
      iVar2 = strcmp(*(char **)(param_2 + 4),"sounds");
      if (iVar2 != 0) {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        return;
      }
      iVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      param_1[0xf7] = iVar2;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__13CMultiManagerP14KeyValueData_s  @ 0010f810
void KeyValue__13CMultiManagerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined1 auStack_88 [132];
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3f4) = (float)lVar3;
  }
  else {
    if (0xf < *(int *)(param_1 + 0x46c)) {
      return;
    }
    UTIL_StripToken__FPCcPc(*(undefined4 *)(param_2 + 4),auStack_88);
    uVar2 = (*DAT_001755cc)(auStack_88);
    *(undefined4 *)(*(int *)(param_1 + 0x46c) * 4 + 0x478 + param_1) = uVar2;
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*(int *)(param_1 + 0x46c) * 4 + 0x4b8 + param_1) = (float)lVar3;
    *(int *)(param_1 + 0x46c) = *(int *)(param_1 + 0x46c) + 1;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__13CTriggerRelayP14KeyValueData_s  @ 0010f6a0
void KeyValue__13CTriggerRelayP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"triggerstate");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x3d4) = 0;
    }
    else {
      if (iVar1 != 2) {
        FUN_0010f700();
        return;
      }
      *(undefined4 *)(param_1 + 0x3d4) = 3;
    }
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CBasePlatTrainP14KeyValueData_s  @ 000d0e10
void KeyValue__14CBasePlatTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"lip");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3f8) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x3f4) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"height");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x438) = (float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"rotation");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x458) = (float)lVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
          if (iVar1 == 0) {
            lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x46c) = (char)(longlong)ROUND(lVar2);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"stopsnd");
            if (iVar1 == 0) {
              lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(char *)(param_1 + 0x46d) = (char)(longlong)ROUND(lVar2);
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                *(float *)(param_1 + 0x470) = (float)lVar2;
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


// KeyValue__14CFuncTankLaserP14KeyValueData_s  @ 000b5c80
void KeyValue__14CFuncTankLaserP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"laserentity");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1b4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__9CFuncTankP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CMomentaryDoorP14KeyValueData_s  @ 000aaea0
void KeyValue__14CMomentaryDoorP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(char *)(param_1 + 0x46c) = (char)(longlong)ROUND(lVar2);
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


// KeyValue__14CTargetCDAudioP14KeyValueData_s  @ 001101f0
void KeyValue__14CTargetCDAudioP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x124) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CTriggerCameraP14KeyValueData_s  @ 00112610
void KeyValue__14CTriggerCameraP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3ec) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"moveto");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 1000) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"acceleration");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x404) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"deceleration");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x408) = (float)lVar3;
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


// KeyValue__15CAmbientGenericP14KeyValueData_s  @ 000ebcb0
void KeyValue__15CAmbientGenericP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"preset");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x3d0) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"pitch");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x3d4) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      if (0xff < *(int *)(param_1 + 0x3d4)) {
        *(undefined4 *)(param_1 + 0x3d4) = 0xff;
      }
      if (-1 < *(int *)(param_1 + 0x3d4)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x3d4) = 0;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"pitchstart");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x3d8) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      if (0xff < *(int *)(param_1 + 0x3d8)) {
        *(undefined4 *)(param_1 + 0x3d8) = 0xff;
      }
      if (-1 < *(int *)(param_1 + 0x3d8)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x3d8) = 0;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"spinup");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(int *)(param_1 + 0x3dc) = iVar1;
      if (100 < iVar1) {
        *(undefined4 *)(param_1 + 0x3dc) = 100;
      }
      if (*(int *)(param_1 + 0x3dc) < 0) {
        *(undefined4 *)(param_1 + 0x3dc) = 0;
      }
      if (0 < *(int *)(param_1 + 0x3dc)) {
        *(int *)(param_1 + 0x3dc) = (0x65 - *(int *)(param_1 + 0x3dc)) * 0x40;
      }
      *(undefined4 *)(param_1 + 0x410) = *(undefined4 *)(param_1 + 0x3dc);
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"spindown");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(int *)(param_1 + 0x3e0) = iVar1;
        if (100 < iVar1) {
          *(undefined4 *)(param_1 + 0x3e0) = 100;
        }
        if (*(int *)(param_1 + 0x3e0) < 0) {
          *(undefined4 *)(param_1 + 0x3e0) = 0;
        }
        if (0 < *(int *)(param_1 + 0x3e0)) {
          *(int *)(param_1 + 0x3e0) = (0x65 - *(int *)(param_1 + 0x3e0)) * 0x40;
        }
        *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(param_1 + 0x3e0);
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"volstart");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(int *)(param_1 + 1000) = iVar1;
          if (10 < iVar1) {
            *(undefined4 *)(param_1 + 1000) = 10;
          }
          if (*(int *)(param_1 + 1000) < 0) {
            *(undefined4 *)(param_1 + 1000) = 0;
          }
          *(int *)(param_1 + 1000) = *(int *)(param_1 + 1000) * 10;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"fadein");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(int *)(param_1 + 0x3ec) = iVar1;
            if (100 < iVar1) {
              *(undefined4 *)(param_1 + 0x3ec) = 100;
            }
            if (*(int *)(param_1 + 0x3ec) < 0) {
              *(undefined4 *)(param_1 + 0x3ec) = 0;
            }
            if (0 < *(int *)(param_1 + 0x3ec)) {
              *(int *)(param_1 + 0x3ec) = (0x65 - *(int *)(param_1 + 0x3ec)) * 0x40;
            }
            *(undefined4 *)(param_1 + 0x420) = *(undefined4 *)(param_1 + 0x3ec);
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"fadeout");
            if (iVar1 == 0) {
              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(int *)(param_1 + 0x3f0) = iVar1;
              if (100 < iVar1) {
                *(undefined4 *)(param_1 + 0x3f0) = 100;
              }
              if (*(int *)(param_1 + 0x3f0) < 0) {
                *(undefined4 *)(param_1 + 0x3f0) = 0;
              }
              if (0 < *(int *)(param_1 + 0x3f0)) {
                *(int *)(param_1 + 0x3f0) = (0x65 - *(int *)(param_1 + 0x3f0)) * 0x40;
              }
              *(undefined4 *)(param_1 + 0x424) = *(undefined4 *)(param_1 + 0x3f0);
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"lfotype");
              if (iVar1 == 0) {
                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                *(int *)(param_1 + 0x3f4) = iVar1;
                if (4 < iVar1) {
                  *(undefined4 *)(param_1 + 0x3f4) = 2;
                }
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"lforate");
                if (iVar1 == 0) {
                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                  *(int *)(param_1 + 0x3f8) = iVar1;
                  if (1000 < iVar1) {
                    *(undefined4 *)(param_1 + 0x3f8) = 1000;
                  }
                  if (*(int *)(param_1 + 0x3f8) < 0) {
                    *(undefined4 *)(param_1 + 0x3f8) = 0;
                  }
                  *(int *)(param_1 + 0x3f8) = *(int *)(param_1 + 0x3f8) << 8;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"lfomodpitch");
                  if (iVar1 == 0) {
                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                    *(int *)(param_1 + 0x3fc) = iVar1;
                    if (100 < iVar1) {
                      *(undefined4 *)(param_1 + 0x3fc) = 100;
                    }
                    if (*(int *)(param_1 + 0x3fc) < 0) {
                      *(undefined4 *)(param_1 + 0x3fc) = 0;
                    }
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"lfomodvol");
                    if (iVar1 == 0) {
                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                      *(int *)(param_1 + 0x400) = iVar1;
                      if (100 < iVar1) {
                        *(undefined4 *)(param_1 + 0x400) = 100;
                      }
                      if (*(int *)(param_1 + 0x400) < 0) {
                        *(undefined4 *)(param_1 + 0x400) = 0;
                      }
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"cspinup");
                      if (iVar1 != 0) {
                        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
                        return;
                      }
                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                      *(int *)(param_1 + 0x404) = iVar1;
                      if (100 < iVar1) {
                        *(undefined4 *)(param_1 + 0x404) = 100;
                      }
                      if (*(int *)(param_1 + 0x404) < 0) {
                        *(undefined4 *)(param_1 + 0x404) = 0;
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


// KeyValue__15CFuncTankMortarP14KeyValueData_s  @ 000b6040
void KeyValue__15CFuncTankMortarP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"iMagnitude");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(*param_1 + 0x164) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__9CFuncTankP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__15CFuncTrackTrainP14KeyValueData_s  @ 000d2ba0
void KeyValue__15CFuncTrackTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wheels");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3d0) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"height");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x3d4) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"startspeed");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x3e0) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x400) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(float *)(param_1 + 0x404) = (float)iVar1;
            *(float *)(param_1 + 0x404) = *(float *)(param_1 + 0x404) * 0.1;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"bank");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(float *)(param_1 + 0x408) = (float)lVar3;
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


// KeyValue__16CFuncIllusionaryP14KeyValueData_s  @ 0009b9a0
void KeyValue__16CFuncIllusionaryP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"skin");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(int *)(*param_1 + 0xf0) = (int)ROUND(lVar2);
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__16CFuncMortarFieldP14KeyValueData_s  @ 000c8df0
void KeyValue__16CFuncMortarFieldP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszXController");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x46c) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszYController");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x470) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_flSpread");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x474) = (float)lVar3;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_fControl");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x480) = uVar2;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"m_iCount");
          if (iVar1 != 0) {
            return;
          }
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x47c) = uVar2;
        }
      }
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__16CFuncTrackChangeP14KeyValueData_s  @ 000d4850
void KeyValue__16CFuncTrackChangeP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"train");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x4a0) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"toptrack");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x498) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"bottomtrack");
      if (iVar1 == 0) {
        uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x49c) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__14CBasePlatTrainP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__17CFrictionModifierP14KeyValueData_s  @ 0010f3c0
void KeyValue__17CFrictionModifierP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"modifier");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3cc) = (float)(lVar2 / (longdouble)100.0);
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__17CScriptedSentenceP14KeyValueData_s  @ 000e8550
void KeyValue__17CScriptedSentenceP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"sentence");
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    param_1[0x11b] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"entity");
    if (iVar1 == 0) {
      iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      param_1[0x11c] = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x11e] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0x11d] = (int)(float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"refire");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            param_1[0x11f] = (int)(float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"attenuation");
            if (iVar1 == 0) {
              uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(undefined4 *)(*param_1 + 0x164) = uVar2;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
              if (iVar1 == 0) {
                lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                param_1[0x121] = (int)(float)((longdouble)0.1 * lVar3);
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"listener");
                if (iVar1 == 0) {
                  iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
                  param_1[0x123] = iVar1;
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
  return;
}


// KeyValue__18CTriggerEndSectionP14KeyValueData_s  @ 001122e0
void KeyValue__18CTriggerEndSectionP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"section");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1b4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__19CMomentaryRotButtonP14KeyValueData_s  @ 0009f500
void KeyValue__19CMomentaryRotButtonP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"returnspeed");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x474) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x490) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__20CTriggerChangeTargetP14KeyValueData_s  @ 00112430
void KeyValue__20CTriggerChangeTargetP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszNewTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x3d4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__5CFadeP14KeyValueData_s  @ 000af840
void KeyValue__5CFadeP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1b8) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"holdtime");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1bc) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__5CItemP14KeyValueData_s  @ 000bd670
void KeyValue__5CItemP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),(char *)FUN_00134210);
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3cc) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__6CBloodP14KeyValueData_s  @ 000af290
void KeyValue__6CBloodP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"color");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 1) {
      *(undefined4 *)(*param_1 + 0x164) = 0xc3;
    }
    else {
      *(undefined4 *)(*param_1 + 0x164) = 0xf7;
    }
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"amount");
    if (iVar1 != 0) {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      return;
    }
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x1c0) = (float)lVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__6CDecalP14KeyValueData_s  @ 0011cfe0
void KeyValue__6CDecalP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
  if (iVar1 == 0) {
    uVar2 = (*DAT_00175570)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0xf0) = uVar2;
    if (*(int *)(*param_1 + 0xf0) < 0) {
      (*DAT_001755b4)(1,"Can\'t find decal %s\n",*(undefined4 *)(param_2 + 8));
    }
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__6CLaserP14KeyValueData_s  @ 000ad890
void KeyValue__6CLaserP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"LaserTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1b4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"width");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x124) = (float)(int)ROUND(lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"NoiseAmplitude");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(*param_1 + 0xf4) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"TextureScroll");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(float *)(*param_1 + 0x114) = (float)iVar1;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
          if (iVar1 == 0) {
            uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(*param_1 + 0x98) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"EndSprite");
            if (iVar1 == 0) {
              iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
              param_1[0xf4] = iVar1;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"framestart");
              if (iVar1 == 0) {
                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                *(float *)(*param_1 + 0x110) = (float)iVar1;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
                if (iVar1 == 0) {
                  lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  *(float *)(*param_1 + 0x1c0) = (float)lVar3;
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
    }
  }
  return;
}


// KeyValue__6CLightP14KeyValueData_s  @ 000bda20
void KeyValue__6CLightP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"style");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0xf3] = iVar1;
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
        iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
        param_1[0xf4] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__6CShakeP14KeyValueData_s  @ 000af680
void KeyValue__6CShakeP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"amplitude");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*param_1 + 0x124) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"frequency");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1bc) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(*param_1 + 0x1b8) = (float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(*param_1 + 0x1c0) = (float)lVar2;
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


// KeyValue__6CWorldP14KeyValueData_s  @ 0011de50
void KeyValue__6CWorldP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  longdouble lVar4;
  char *pcVar5;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"skyname");
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_2 + 8);
    pcVar5 = "sv_skyname";
    pcVar3 = DAT_001755b0;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(gpGlobals + 0x8c) = uVar2;
      goto LAB_0011dec1;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"WaveHeight");
    if (iVar1 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x124) = (float)((longdouble)0.125 * lVar4);
      *(undefined4 *)(param_2 + 0xc) = 1;
      (*DAT_001755ac)("sv_wateramp",*(undefined4 *)(*param_1 + 0x124));
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"MaxRange");
    if (iVar1 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1d8) = (float)lVar4;
      goto LAB_0011dec1;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"chaptertitle");
    if (iVar1 == 0) {
      uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(*param_1 + 0x1b0) = uVar2;
      goto LAB_0011dec1;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"startdark");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_2 + 0xc) = 1;
      if (iVar1 == 0) {
        return;
      }
      *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"newunit");
    if (iVar1 != 0) {
      iVar1 = strcmp(*(char **)(param_2 + 4),"gametitle");
      if (iVar1 != 0) {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        return;
      }
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      if (iVar1 != 0) {
        *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 2;
      }
      goto LAB_0011dec1;
    }
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 0) goto LAB_0011dec1;
    uVar2 = 0x3f800000;
    pcVar5 = "sv_newunit";
    pcVar3 = DAT_001755ac;
  }
  (*pcVar3)(pcVar5,uVar2);
LAB_0011dec1:
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__7CLadderP14KeyValueData_s  @ 00111b60
void KeyValue__7CLadderP14KeyValueData_s(undefined4 param_1,undefined4 param_2)

{
  KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  return;
}


// KeyValue__8CDeadHEVP14KeyValueData_s  @ 000dfd30
void KeyValue__8CDeadHEVP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"pose");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x610) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CMessageP14KeyValueData_s  @ 000afa60
void KeyValue__8CMessageP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"messagesound");
  if (iVar1 == 0) {
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1c8) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"messagevolume");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x124) = (float)((longdouble)0.1 * lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"messageattenuation");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(*param_1 + 0x164) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__8CNodeEntP14KeyValueData_s  @ 000cbc10
void KeyValue__8CNodeEntP14KeyValueData_s(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"hinttype");
  if (iVar2 == 0) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined2 *)(param_1 + 0x3cc) = uVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  iVar2 = strcmp(*(char **)(param_2 + 4),"activity");
  if (iVar2 == 0) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined2 *)(param_1 + 0x3ce) = uVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CSpeakerP14KeyValueData_s  @ 000ede20
void KeyValue__8CSpeakerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"preset");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x3cc) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__9CBaseDoorP14KeyValueData_s  @ 000a91a0
void KeyValue__9CBaseDoorP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"skin");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(int *)(*param_1 + 0xf0) = (int)ROUND(lVar2);
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(char *)((int)param_1 + 0x46d) = (char)(longlong)ROUND(lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"stopsnd");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(char *)((int)param_1 + 0x46e) = (char)(longlong)ROUND(lVar2);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"healthvalue");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(char *)(param_1 + 0x11b) = (char)(longlong)ROUND(lVar2);
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sound");
          if (iVar1 == 0) {
            lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x125) = (char)(longlong)ROUND(lVar2);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sentence");
            if (iVar1 == 0) {
              lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(char *)((int)param_1 + 0x495) = (char)(longlong)ROUND(lVar2);
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sound");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                *(char *)((int)param_1 + 0x496) = (char)(longlong)ROUND(lVar2);
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sentence");
                if (iVar1 == 0) {
                  lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  *(char *)((int)param_1 + 0x497) = (char)(longlong)ROUND(lVar2);
                  *(undefined4 *)(param_2 + 0xc) = 1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"WaveHeight");
                  if (iVar1 == 0) {
                    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                    *(float *)(*param_1 + 0x124) = (float)((longdouble)0.125 * lVar2);
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


// KeyValue__9CBubblingP14KeyValueData_s  @ 000ab460
void KeyValue__9CBubblingP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"density");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0xf3] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"frequency");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      param_1[0xf4] = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"current");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(float *)(*param_1 + 0x1d8) = (float)iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__9CEnvLightP14KeyValueData_s  @ 000bdc50
/* WARNING: Removing unreachable block (ram,0x000bdf03) */
/* WARNING: Removing unreachable block (ram,0x000bdf0b) */
/* WARNING: Removing unreachable block (ram,0x000bdf20) */
/* WARNING: Removing unreachable block (ram,0x000bdf25) */
/* WARNING: Removing unreachable block (ram,0x000bdf27) */
/* WARNING: Removing unreachable block (ram,0x000bdf34) */
/* WARNING: Removing unreachable block (ram,0x000bde3f) */
/* WARNING: Removing unreachable block (ram,0x000bdd5c) */
/* WARNING: Removing unreachable block (ram,0x000bdd64) */
/* WARNING: Removing unreachable block (ram,0x000bdd68) */
/* WARNING: Removing unreachable block (ram,0x000bdd78) */
/* WARNING: Removing unreachable block (ram,0x000bdd7d) */
/* WARNING: Removing unreachable block (ram,0x000bdd7f) */
/* WARNING: Removing unreachable block (ram,0x000bdd75) */
/* WARNING: Removing unreachable block (ram,0x000bde33) */
/* WARNING: Removing unreachable block (ram,0x000bde3b) */
/* WARNING: Removing unreachable block (ram,0x000bde50) */
/* WARNING: Removing unreachable block (ram,0x000bde55) */
/* WARNING: Removing unreachable block (ram,0x000bde57) */
/* WARNING: Removing unreachable block (ram,0x000bde64) */
/* WARNING: Removing unreachable block (ram,0x000bdf0f) */

void KeyValue__9CEnvLightP14KeyValueData_s(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  longdouble lVar2;
  longdouble lVar3;
  int local_6c;
  int local_68;
  int local_64;
  int local_60 [3];
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined4 local_50;
  undefined2 local_48;
  undefined2 uStack_46;
  char acStack_44 [64];
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"_light");
  if (iVar1 == 0) {
    iVar1 = sscanf(*(char **)(param_2 + 8),"%d %d %d %d\n",&local_6c,&local_68,&local_64,local_60);
    if (iVar1 == 1) {
      local_64 = local_6c;
      local_68 = local_6c;
    }
    else if (iVar1 == 4) {
      local_6c = (int)ROUND(((double)local_60[0] / 255.0) * (double)local_6c);
      local_68 = (int)ROUND(((double)local_60[0] / 255.0) * (double)local_68);
      local_64 = (int)ROUND(((double)local_60[0] / 255.0) * (double)local_64);
    }
    lVar2 = (longdouble)local_6c / (longdouble)114.0;
    lVar3 = (longdouble)0;
    if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) {
      lVar3 = (longdouble)log2(lVar2);
      lVar3 = (longdouble)1 * lVar3 * (longdouble)0.6;
      lVar2 = ROUND(lVar3);
      lVar3 = (longdouble)f2xm1(lVar3 - lVar2);
      lVar3 = (longdouble)fscale(lVar3 + (longdouble)1.0,lVar2);
    }
    local_6c = (int)ROUND((longdouble)264.0 * lVar3);
    lVar2 = (longdouble)local_68 / (longdouble)114.0;
    lVar3 = (longdouble)0;
    if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) {
      lVar3 = (longdouble)log2(lVar2);
      lVar3 = (longdouble)1 * lVar3 * (longdouble)0.6;
      lVar2 = ROUND(lVar3);
      lVar3 = (longdouble)f2xm1(lVar3 - lVar2);
      lVar3 = (longdouble)fscale(lVar3 + (longdouble)1.0,lVar2);
    }
    local_68 = (int)ROUND((longdouble)264.0 * lVar3);
    lVar2 = (longdouble)local_64 / (longdouble)114.0;
    _uStack_54 = CONCAT22(uStack_52,in_FPUControlWord);
    local_60[1] = 1;
    local_60[2] = 0;
    lVar3 = (longdouble)0;
    if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) {
      lVar3 = (longdouble)log2(lVar2);
      lVar3 = (longdouble)1 * lVar3 * (longdouble)0.6;
      lVar2 = ROUND(lVar3);
      lVar3 = (longdouble)f2xm1(lVar3 - lVar2);
      lVar3 = (longdouble)fscale(lVar3 + (longdouble)1.0,lVar2);
    }
    _local_48 = CONCAT22(uStack_46,in_FPUControlWord);
    local_50 = CONCAT22(uStack_46,CONCAT11(0xc,(char)in_FPUControlWord));
    local_64 = (int)ROUND((longdouble)264.0 * lVar3);
    *(undefined4 *)(param_2 + 0xc) = 1;
    sprintf(acStack_44,"%d",local_6c);
    (*DAT_001755b0)("cl_skycolor_r",acStack_44);
    sprintf(acStack_44,"%d",local_68);
    (*DAT_001755b0)("cl_skycolor_g",acStack_44);
    sprintf(acStack_44,"%d",local_64);
    (*DAT_001755b0)("cl_skycolor_b",acStack_44);
  }
  else {
    KeyValue__6CLightP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__9CEnvSoundP14KeyValueData_s  @ 000ec2c0
void KeyValue__9CEnvSoundP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3cc) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"roomtype");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3d0) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  return;
}


// KeyValue__9CEnvSparkP14KeyValueData_s  @ 0009fd80
void KeyValue__9CEnvSparkP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"MaxDelay");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3cc) = (float)lVar2;
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


// KeyValue__9CFuncTankP14KeyValueData_s  @ 000b3fb0
void KeyValue__9CFuncTankP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"yawrate");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    param_1[0xf9] = (int)(float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"yawrange");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[0xfa] = (int)(float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"yawtolerance");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0xfb] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"pitchrange");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0xfe] = (int)(float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"pitchrate");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            param_1[0xfd] = (int)(float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"pitchtolerance");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              param_1[0xff] = (int)(float)lVar3;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"firerate");
              if (iVar1 == 0) {
                lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                param_1[0x101] = (int)(float)lVar3;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"barrel");
                if (iVar1 == 0) {
                  lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  param_1[0x106] = (int)(float)lVar3;
                  *(undefined4 *)(param_2 + 0xc) = 1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"barrely");
                  if (iVar1 == 0) {
                    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                    param_1[0x107] = (int)(float)lVar3;
                    *(undefined4 *)(param_2 + 0xc) = 1;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"barrelz");
                    if (iVar1 == 0) {
                      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                      param_1[0x108] = (int)(float)lVar3;
                      *(undefined4 *)(param_2 + 0xc) = 1;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"spritescale");
                      if (iVar1 == 0) {
                        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                        param_1[0x109] = (int)(float)lVar3;
                        *(undefined4 *)(param_2 + 0xc) = 1;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(param_2 + 4),"spritesmoke");
                        if (iVar1 == 0) {
                          iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
                          param_1[0x10a] = iVar1;
                          *(undefined4 *)(param_2 + 0xc) = 1;
                        }
                        else {
                          iVar1 = strcmp(*(char **)(param_2 + 4),"spriteflash");
                          if (iVar1 == 0) {
                            iVar1 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
                            param_1[0x10b] = iVar1;
                            *(undefined4 *)(param_2 + 0xc) = 1;
                          }
                          else {
                            iVar1 = strcmp(*(char **)(param_2 + 4),"rotatesound");
                            if (iVar1 == 0) {
                              uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
                              *(undefined4 *)(*param_1 + 0x1c8) = uVar2;
                              *(undefined4 *)(param_2 + 0xc) = 1;
                            }
                            else {
                              iVar1 = strcmp(*(char **)(param_2 + 4),"persistence");
                              if (iVar1 == 0) {
                                lVar3 = (longdouble)
                                        __strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                                param_1[0x103] = (int)(float)lVar3;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                              }
                              else {
                                iVar1 = strcmp(*(char **)(param_2 + 4),"bullet");
                                if (iVar1 == 0) {
                                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                  param_1[0x10c] = iVar1;
                                  *(undefined4 *)(param_2 + 0xc) = 1;
                                }
                                else {
                                  iVar1 = strcmp(*(char **)(param_2 + 4),"bullet_damage");
                                  if (iVar1 == 0) {
                                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                    param_1[0x10d] = iVar1;
                                    *(undefined4 *)(param_2 + 0xc) = 1;
                                  }
                                  else {
                                    iVar1 = strcmp(*(char **)(param_2 + 4),"firespread");
                                    if (iVar1 == 0) {
                                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0)
                                      ;
                                      param_1[0x111] = iVar1;
                                      *(undefined4 *)(param_2 + 0xc) = 1;
                                    }
                                    else {
                                      iVar1 = strcmp(*(char **)(param_2 + 4),"minRange");
                                      if (iVar1 == 0) {
                                        lVar3 = (longdouble)
                                                __strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                                        param_1[0x104] = (int)(float)lVar3;
                                        *(undefined4 *)(param_2 + 0xc) = 1;
                                      }
                                      else {
                                        iVar1 = strcmp(*(char **)(param_2 + 4),"maxRange");
                                        if (iVar1 == 0) {
                                          lVar3 = (longdouble)
                                                  __strtod_internal(*(undefined4 *)(param_2 + 8),0,0
                                                                   );
                                          param_1[0x105] = (int)(float)lVar3;
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
  return;
}


// KeyValue__9CPendulumP14KeyValueData_s  @ 0009cb10
void KeyValue__9CPendulumP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x3d0) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"damp");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x3d8) = (float)((longdouble)0.001 * lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__9CPushableP14KeyValueData_s  @ 000b36a0
void KeyValue__9CPushableP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  longdouble lVar4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"size");
  if (iVar1 != 0) {
    iVar1 = strcmp(*(char **)(param_2 + 4),"buoyancy");
    if (iVar1 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(int *)(*param_1 + 0xf0) = (int)ROUND(lVar4);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    KeyValue__10CBreakableP14KeyValueData_s(param_1,param_2);
    return;
  }
  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
  *(undefined4 *)(param_2 + 0xc) = 1;
  if (iVar1 == 1) {
LAB_000b37f0:
    local_34 = 0x41800000;
    local_30 = 0x41800000;
    local_2c = 0x42100000;
    puVar3 = &local_34;
    local_28 = 0xc1800000;
  }
  else {
    if (iVar1 < 2) {
      if (iVar1 == 0) {
        local_10 = 0x41000000;
        local_c = 0x41000000;
        local_8 = 0x41000000;
        puVar3 = &local_10;
        local_1c = 0xc1000000;
        local_18 = 0xc1000000;
        local_14 = 0xc1000000;
        puVar2 = &local_1c;
        goto LAB_000b3824;
      }
      goto LAB_000b37f0;
    }
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        local_10 = 0x41800000;
        local_c = 0x41800000;
        local_8 = 0x41900000;
        puVar3 = &local_10;
        local_34 = 0xc1800000;
        local_30 = 0xc1800000;
        local_2c = 0xc1900000;
        puVar2 = &local_34;
        goto LAB_000b3824;
      }
      goto LAB_000b37f0;
    }
    local_10 = 0x41800000;
    local_c = 0x41800000;
    local_8 = 0x41900000;
    local_1c = 0x42000000;
    local_18 = 0x42000000;
    local_14 = 0x42100000;
    puVar3 = &local_1c;
    local_34 = 0xc1800000;
    local_30 = 0xc1800000;
    local_2c = 0xc1900000;
    local_28 = 0xc2000000;
  }
  local_20 = 0xc2100000;
  puVar2 = &local_28;
  local_24 = local_28;
LAB_000b3824:
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,puVar2,puVar3);
  return;
}


// KeyValue__9CRechargeP14KeyValueData_s  @ 000ba9e0
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
    *(undefined4 *)(param_1 + 0x470) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


