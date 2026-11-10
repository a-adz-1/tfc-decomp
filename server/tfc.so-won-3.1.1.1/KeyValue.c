// KeyValue__10CBaseDelayP14KeyValueData_s  @ 000f66d0
void KeyValue__10CBaseDelayP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"delay");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x458) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x45c) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__10CBreakableP14KeyValueData_s  @ 000a7988
void KeyValue__10CBreakableP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"explosion");
  if (iVar1 == 0) {
    iVar1 = strcasecmp(*(char **)(param_2 + 8),"directed");
    if (iVar1 == 0) {
      param_1[0x119] = 1;
    }
    else {
      strcasecmp(*(char **)(param_2 + 8),"random");
      param_1[0x119] = 0;
    }
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"material");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      if (uVar2 < 10) {
        param_1[0x118] = uVar2;
      }
      else {
        param_1[0x118] = 1;
      }
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"deadmodel");
      if ((iVar1 != 0) && (iVar1 = strcmp(*(char **)(param_2 + 4),"shards"), iVar1 != 0)) {
        iVar1 = strcmp(*(char **)(param_2 + 4),"gibmodel");
        if (iVar1 == 0) {
          iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
          param_1[0x11c] = iVar1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"spawnobject");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            if (iVar1 - 1U < 0x15) {
              param_1[0x11d] =
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
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__10CEnvGlobalP14KeyValueData_s  @ 0008a20c
void KeyValue__10CEnvGlobalP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 0xc) = 1;
  iVar1 = strcmp(*(char **)(param_2 + 4),"globalstate");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x458) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"triggermode");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x45c) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"initialstate");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x460) = uVar2;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__10CFuncTrainP14KeyValueData_s  @ 000d2590
void KeyValue__10CFuncTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x504) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__14CBasePlatTrainP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__10CLightningP14KeyValueData_s  @ 0009fab4
void KeyValue__10CLightningP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"LightningStart");
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    param_1[0x117] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"LightningEnd");
    if (iVar1 == 0) {
      iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      param_1[0x118] = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"life");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x119] = (int)(float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"BoltWidth");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          param_1[0x11a] = iVar1;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"NoiseAmplitude");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            param_1[0x11b] = iVar1;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"TextureScroll");
            if (iVar1 == 0) {
              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              param_1[0x11d] = iVar1;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"StrikeTime");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                param_1[0x11e] = (int)(float)lVar2;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
                if (iVar1 == 0) {
                  iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
                  param_1[0x120] = iVar1;
                  *(undefined4 *)(param_2 + 0xc) = 1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"framestart");
                  if (iVar1 == 0) {
                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                    param_1[0x121] = iVar1;
                    *(undefined4 *)(param_2 + 0xc) = 1;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"Radius");
                    if (iVar1 == 0) {
                      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                      param_1[0x122] = (int)(float)lVar2;
                      *(undefined4 *)(param_2 + 0xc) = 1;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
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
              }
            }
          }
        }
      }
    }
  }
  return;
}


// KeyValue__10CPathTrackP14KeyValueData_s  @ 000cccf4
void KeyValue__10CPathTrackP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"altpath");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x45c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__10CWeaponBoxP14KeyValueData_s  @ 00125090
void KeyValue__10CWeaponBoxP14KeyValueData_s(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x578) < 0x20) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    uVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 4),uVar1);
    PackAmmo__10CWeaponBoxii(param_1,uVar1);
    *(int *)(param_1 + 0x578) = *(int *)(param_1 + 0x578) + 1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    (*DAT_0019f794)(1,"WeaponBox too full! only %d ammotypes allowed\n",0x20);
  }
  return;
}


// KeyValue__10CWorldItemP14KeyValueData_s  @ 000b60a4
void KeyValue__10CWorldItemP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"type");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x458) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__11CBaseButtonP14KeyValueData_s  @ 0008a900
void KeyValue__11CBaseButtonP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"changetarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x500) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sound");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(char *)(param_1 + 0x528) = (char)(longlong)ROUND(lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sentence");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(char *)(param_1 + 0x529) = (char)(longlong)ROUND(lVar3);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sound");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(char *)(param_1 + 0x52a) = (char)(longlong)ROUND(lVar3);
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sentence");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x52b) = (char)(longlong)ROUND(lVar3);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
            if (iVar1 == 0) {
              uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(undefined4 *)(param_1 + 0x52c) = uVar2;
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


// KeyValue__11CBaseEntityP14KeyValueData_s  @ 00108654
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
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(*param_1 + 0xb8) = uVar2;
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
                      if ((iVar1 == 0) ||
                         (iVar1 = strcmp(*(char **)(param_2 + 4),"g_a"), iVar1 == 0)) {
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
                                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0)
                                      ;
                                      param_1[0x91] = iVar1;
                                    }
                                    else {
                                      iVar1 = strcmp(*(char **)(param_2 + 4),"if_group_is_active");
                                      if (iVar1 == 0) {
                                        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,
                                                                  0);
                                        param_1[0x92] = iVar1;
                                      }
                                      else {
                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                       "if_group_is_inactive");
                                        if (iVar1 == 0) {
                                          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,
                                                                    10,0);
                                          param_1[0x93] = iVar1;
                                        }
                                        else {
                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                         "if_group_is_removed");
                                          if (iVar1 == 0) {
                                            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0
                                                                      ,10,0);
                                            param_1[0x94] = iVar1;
                                          }
                                          else {
                                            iVar1 = strcmp(*(char **)(param_2 + 4),"search_time");
                                            if (iVar1 == 0) {
                                              lVar4 = (longdouble)
                                                      __strtod_internal(*(undefined4 *)(param_2 + 8)
                                                                        ,0,0);
                                              param_1[0x95] = (int)(float)lVar4;
                                            }
                                            else {
                                              iVar1 = strcmp(*(char **)(param_2 + 4),"t_length");
                                              if (iVar1 == 0) {
                                                lVar4 = (longdouble)
                                                        __strtod_internal(*(undefined4 *)
                                                                           (param_2 + 8),0,0);
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
                                                                               (param_2 + 8),0,10,0)
                                                    ;
                                                    param_1[0x98] = iVar1;
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
                                                      param_1[0x99] = iVar1;
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
                                                        param_1[0x9a] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "activate_group_no");
                                                        if (iVar1 == 0) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0x9b] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "inactivate_group_no");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0x9c] = iVar1;
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
                                                              param_1[0x9d] = iVar1;
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
                                                    param_1[0x9e] = iVar1;
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
                                                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664)
                                                                                  || NAN(fStack_10))
                                                                         << 10) >> 8) |
                                                         (byte)((ushort)((ushort)(DAT_0019f664 ==
                                                                                 fStack_10) << 0xe)
                                                               >> 8)) == 0x40)) {
                                                    bVar3 = (byte)(DAT_0019f668 < fStack_c |
                                                                   (byte)((ushort)((ushort)(NAN(
                                                  DAT_0019f668) || NAN(fStack_c)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(DAT_0019f668 == fStack_c)
                                                                 << 0xe) >> 8)) == 0x40;
                                                  }
                                                  if (!bVar3) {
                                                    param_1[0xa0] = (int)fStack_14;
                                                    param_1[0xa1] = (int)fStack_10;
                                                    param_1[0xa2] = (int)fStack_c;
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
                                                  ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664)
                                                                                  || NAN(fStack_10))
                                                                         << 10) >> 8) |
                                                         (byte)((ushort)((ushort)(DAT_0019f664 ==
                                                                                 fStack_10) << 0xe)
                                                               >> 8)) == 0x40)) {
                                                    bVar3 = (byte)(DAT_0019f668 < fStack_c |
                                                                   (byte)((ushort)((ushort)(NAN(
                                                  DAT_0019f668) || NAN(fStack_c)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(DAT_0019f668 == fStack_c)
                                                                 << 0xe) >> 8)) == 0x40;
                                                  }
                                                  if (!bVar3) {
                                                    param_1[0xa3] = (int)fStack_14;
                                                    param_1[0xa4] = (int)fStack_10;
                                                    param_1[0xa5] = (int)fStack_c;
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
                                                      param_1[0xaa] = iVar1;
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
                                                        param_1[0xab] = iVar1;
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
                                                          param_1[0xac] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "return_item_no");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0xad] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "if_item_has_moved");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xae] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"if_item_hasnt_moved")
                                                              ;
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xaf] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   (char *)FUN_00156c00);
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xb0] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "restore_spawnpoint");
                                                      if (iVar1 == 0) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0xb1] = iVar1;
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
                                                          param_1[0xb2] = iVar1;
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
                                                            param_1[0xb3] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "display_item_status1");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xb4] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"display_item_status2"
                                                                            );
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xb5] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "display_item_status3");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xb6] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "display_item_status4");
                                                      if (iVar1 == 0) {
                                                        iVar1 = __strtol_internal(*(undefined4 *)
                                                                                   (param_2 + 8),0,
                                                                                  10,0);
                                                        param_1[0xb7] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "team_str_home");
                                                        if ((iVar1 == 0) ||
                                                           (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "t_s_g"), iVar1 == 0)) {
                                                          iVar1 = (*DAT_0019f7ac)(*(undefined4 *)
                                                                                   (param_2 + 8));
                                                          param_1[0xb8] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "team_str_moved");
                                                          if ((iVar1 == 0) ||
                                                             (iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"t_s_m"), iVar1 == 0))
                                                          {
                                                            iVar1 = (*DAT_0019f7ac)(*(undefined4 *)
                                                                                     (param_2 + 8));
                                                            param_1[0xb9] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "team_str_carried");
                                                            if ((iVar1 == 0) ||
                                                               (iVar1 = strcmp(*(char **)(param_2 +
                                                                                         4),"t_s_c")
                                                               , iVar1 == 0)) {
                                                              iVar1 = (*DAT_0019f7ac)(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ));
                                                              param_1[0xba] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"non_team_str_home");
                                                              if ((iVar1 == 0) ||
                                                                 (iVar1 = strcmp(*(char **)(param_2 
                                                  + 4),"t_s_h"), iVar1 == 0)) {
                                                    iVar1 = (*DAT_0019f7ac)(*(undefined4 *)
                                                                             (param_2 + 8));
                                                    param_1[0xbb] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "non_team_str_moved");
                                                    if ((iVar1 == 0) ||
                                                       (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "t_s_m"), iVar1 == 0)) {
                                                      iVar1 = (*DAT_0019f7ac)(*(undefined4 *)
                                                                               (param_2 + 8));
                                                      param_1[0xbc] = iVar1;
                                                    }
                                                    else {
                                                      iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                     "non_team_str_carried");
                                                      if ((iVar1 == 0) ||
                                                         (iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "n_s_c"), iVar1 == 0)) {
                                                        iVar1 = (*DAT_0019f7ac)(*(undefined4 *)
                                                                                 (param_2 + 8));
                                                        param_1[0xbd] = iVar1;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                       "ex_skill_min");
                                                        if (iVar1 == 0) {
                                                          iVar1 = __strtol_internal(*(undefined4 *)
                                                                                     (param_2 + 8),0
                                                                                    ,10,0);
                                                          param_1[0xbe] = iVar1;
                                                        }
                                                        else {
                                                          iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                         "ex_skill_max");
                                                          if (iVar1 == 0) {
                                                            iVar1 = __strtol_internal(*(undefined4 *
                                                                                       )(param_2 + 8
                                                                                        ),0,10,0);
                                                            param_1[0xbf] = iVar1;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                           "increase_team1");
                                                            if (iVar1 == 0) {
                                                              iVar1 = __strtol_internal(*(undefined4
                                                                                          *)(param_2
                                                                                            + 8),0,
                                                                                        10,0);
                                                              param_1[0xc0] = iVar1;
                                                            }
                                                            else {
                                                              iVar1 = strcmp(*(char **)(param_2 + 4)
                                                                             ,"increase_team2");
                                                              if (iVar1 == 0) {
                                                                iVar1 = __strtol_internal(*(
                                                  undefined4 *)(param_2 + 8),0,10,0);
                                                  param_1[0xc1] = iVar1;
                                                  }
                                                  else {
                                                    iVar1 = strcmp(*(char **)(param_2 + 4),
                                                                   "increase_team3");
                                                    if (iVar1 == 0) {
                                                      iVar1 = __strtol_internal(*(undefined4 *)
                                                                                 (param_2 + 8),0,10,
                                                                                0);
                                                      param_1[0xc2] = iVar1;
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
                                                  param_1[0xc3] = iVar1;
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


// KeyValue__11CBaseToggleP14KeyValueData_s  @ 000f5eb8
void KeyValue__11CBaseToggleP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"lip");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x484) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x480) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"master");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x4f4) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x47c) = (float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"delay");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x458) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"killtarget");
            if (iVar1 == 0) {
              uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
              *(undefined4 *)(param_1 + 0x45c) = uVar2;
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


// KeyValue__11CBaseTurretP14KeyValueData_s  @ 0011a30c
void KeyValue__11CBaseTurretP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"maxsleep");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x6e0) = (float)lVar3;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"orientation");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x6c0) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"searchspeed");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(param_1 + 0x6e4) = uVar2;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"turnrate");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x6b8) = uVar2;
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


// KeyValue__11CEnvShooterP14KeyValueData_s  @ 000a2200
void KeyValue__11CEnvShooterP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"shootmodel");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
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
        param_1[0x11a] = 0;
        break;
      case 1:
        param_1[0x11a] = 1;
        break;
      case 2:
        param_1[0x11a] = 2;
        break;
      case 3:
        param_1[0x11a] = 3;
        break;
      case 4:
        param_1[0x11a] = 8;
        break;
      default:
        param_1[0x11a] = 9;
      }
    }
    else {
      KeyValue__11CGibShooterP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__11CGibShooterP14KeyValueData_s  @ 000a1d10
void KeyValue__11CGibShooterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iGibs");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x464) = uVar2;
    *(undefined4 *)(param_1 + 0x460) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_flVelocity");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x470) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_flVariance");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x474) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_flGibLife");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x478) = (float)lVar3;
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


// KeyValue__11CPathCornerP14KeyValueData_s  @ 000cce18
void KeyValue__11CPathCornerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x458) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__11CWallHealthP14KeyValueData_s  @ 000b5364
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
    *(undefined4 *)(param_1 + 0x4fc) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CAutoTriggerP14KeyValueData_s  @ 00119e68
void KeyValue__12CAutoTriggerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"globalstate");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x460) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"triggerstate");
    if (iVar1 != 0) {
      KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
      return;
    }
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x464) = 0;
    }
    else if (iVar1 == 2) {
      *(undefined4 *)(param_1 + 0x464) = 3;
    }
    else {
      *(undefined4 *)(param_1 + 0x464) = 1;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CBaseMonsterP14KeyValueData_s  @ 000c1a64
void KeyValue__12CBaseMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"TriggerTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x684) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"TriggerCondition");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x680) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__12CBaseTriggerP14KeyValueData_s  @ 00114760
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
      param_1[0x130] = (int)ROUND(lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"damagetype");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        param_1[0x13c] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseToggleP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__12CChangeLevelP14KeyValueData_s  @ 001155d4
void KeyValue__12CChangeLevelP14KeyValueData_s(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  char *__dest;
  undefined4 uVar4;
  uint *__src;
  uint uVar5;
  longdouble lVar6;
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"map");
  if (iVar2 != 0) {
    iVar2 = strcmp(*(char **)(param_2 + 4),"landmark");
    if (iVar2 != 0) {
      iVar2 = strcmp(*(char **)(param_2 + 4),"changetarget");
      if (iVar2 == 0) {
        uVar4 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x538) = uVar4;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      iVar2 = strcmp(*(char **)(param_2 + 4),"changedelay");
      if (iVar2 == 0) {
        lVar6 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x53c) = (float)lVar6;
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
      KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
      return;
    }
    __src = *(uint **)(param_2 + 8);
    uVar5 = (uint)__src & 3;
    puVar1 = __src;
    if (uVar5 == 0) {
LAB_001156b9:
      do {
        puVar3 = puVar1;
        uVar5 = *puVar3;
        if ((char)uVar5 == '\0') goto LAB_001156db;
        if ((char)(uVar5 >> 8) == '\0') goto LAB_001156da;
        if ((uVar5 & 0xff0000) == 0) goto LAB_001156d9;
        puVar1 = puVar3 + 1;
      } while ((uVar5 & 0xff000000) != 0);
      puVar3 = (uint *)((int)puVar3 + 1);
LAB_001156d9:
      puVar3 = (uint *)((int)puVar3 + 1);
LAB_001156da:
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    else {
      puVar3 = __src;
      if ((POPCOUNT(uVar5) & 1U) == 0) {
LAB_001156b4:
        if ((char)*puVar3 != '\0') {
          puVar1 = (uint *)((int)puVar3 + 1);
          goto LAB_001156b9;
        }
      }
      else if (uVar5 == 2) {
LAB_001156af:
        if ((char)*puVar3 != '\0') {
          puVar3 = (uint *)((int)puVar3 + 1);
          goto LAB_001156b4;
        }
      }
      else if ((char)*__src != '\0') {
        puVar3 = (uint *)((int)__src + 1);
        goto LAB_001156af;
      }
    }
LAB_001156db:
    if (0x1f < (uint)((int)puVar3 - (int)__src)) {
      (*DAT_0019f794)(4,"Landmark name \'%s\' too long (32 chars)\n",__src);
      __src = *(uint **)(param_2 + 8);
    }
    __dest = (char *)(param_1 + 0x518);
    goto LAB_00115707;
  }
  __src = *(uint **)(param_2 + 8);
  uVar5 = (uint)__src & 3;
  puVar1 = __src;
  if (uVar5 == 0) {
LAB_00115628:
    do {
      puVar3 = puVar1;
      uVar5 = *puVar3;
      if ((char)uVar5 == '\0') goto LAB_0011564a;
      if ((char)(uVar5 >> 8) == '\0') goto LAB_00115649;
      if ((uVar5 & 0xff0000) == 0) goto LAB_00115648;
      puVar1 = puVar3 + 1;
    } while ((uVar5 & 0xff000000) != 0);
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_00115648:
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_00115649:
    puVar3 = (uint *)((int)puVar3 + 1);
  }
  else {
    puVar3 = __src;
    if ((POPCOUNT(uVar5) & 1U) == 0) {
LAB_00115623:
      if ((char)*puVar3 != '\0') {
        puVar1 = (uint *)((int)puVar3 + 1);
        goto LAB_00115628;
      }
    }
    else if (uVar5 == 2) {
LAB_0011561e:
      if ((char)*puVar3 != '\0') {
        puVar3 = (uint *)((int)puVar3 + 1);
        goto LAB_00115623;
      }
    }
    else if ((char)*__src != '\0') {
      puVar3 = (uint *)((int)__src + 1);
      goto LAB_0011561e;
    }
  }
LAB_0011564a:
  if (0x1f < (uint)((int)puVar3 - (int)__src)) {
    (*DAT_0019f794)(4,"Map name \'%s\' too long (32 chars)\n",__src);
    __src = *(uint **)(param_2 + 8);
  }
  __dest = (char *)(param_1 + 0x4f8);
LAB_00115707:
  strcpy(__dest,(char *)__src);
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CCineMonsterP14KeyValueData_s  @ 000e9208
void KeyValue__12CCineMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszIdle");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x69c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszPlay");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x6a0) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszEntity");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x6a4) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_fMoveTo");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x6a8) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"m_flRepeat");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(float *)(param_1 + 0x6b4) = (float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"m_flRadius");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(float *)(param_1 + 0x6b0) = (float)lVar3;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"m_iFinishSchedule");
              if (iVar1 == 0) {
                uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                *(undefined4 *)(param_1 + 0x6ac) = uVar2;
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


// KeyValue__12CMultiSourceP14KeyValueData_s  @ 0008a2d0
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
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x5dc) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__12CRevertSavedP14KeyValueData_s  @ 000dd8fc
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
        param_1[0x116] = (int)(float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"loadtime");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0x117] = (int)(float)lVar2;
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


// KeyValue__12CTalkMonsterP14KeyValueData_s  @ 000f8594
void KeyValue__12CTalkMonsterP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"UseSentence");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x6f4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"UnUseSentence");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x6f8) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__12CTriggerPushP14KeyValueData_s  @ 00118560
void KeyValue__12CTriggerPushP14KeyValueData_s(undefined4 param_1,undefined4 param_2)

{
  KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  return;
}


// KeyValue__13CEnvExplosionP14KeyValueData_s  @ 000a7644
void KeyValue__13CEnvExplosionP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"iMagnitude");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x69c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__13CFuncRotatingP14KeyValueData_s  @ 00087e34
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
    param_1[0x116] = (int)(float)((longdouble)0.01 * lVar4);
  }
  else {
    iVar2 = strcmp(*(char **)(param_2 + 4),"Volume");
    if (iVar2 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[0x118] = (int)(float)((longdouble)0.1 * lVar4);
      if (1.0 < (float)((longdouble)0.1 * lVar4)) {
        param_1[0x118] = 0x3f800000;
      }
      fVar1 = (float)param_1[0x118];
      if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        param_1[0x118] = 0;
      }
    }
    else {
      iVar2 = strcmp(*(char **)(param_2 + 4),"spawnorigin");
      if (iVar2 == 0) {
        UTIL_StringToVector__FPfPCc(&local_14,*(undefined4 *)(param_2 + 8));
        bVar3 = false;
        if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(local_14)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(g_vecZero == local_14) << 0xe) >> 8)) == 0x40) &&
           ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(local_10)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f664 == local_10) << 0xe) >> 8)) == 0x40)) {
          bVar3 = (byte)(DAT_0019f668 < local_c |
                         (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(local_c)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(DAT_0019f668 == local_c) << 0xe) >> 8)) == 0x40;
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
      param_1[0x11a] = iVar2;
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__13CMultiManagerP14KeyValueData_s  @ 00114328
void KeyValue__13CMultiManagerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined1 auStack_88 [132];
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x480) = (float)lVar3;
  }
  else {
    if (0xf < *(int *)(param_1 + 0x4f8)) {
      return;
    }
    UTIL_StripToken__FPCcPc(*(undefined4 *)(param_2 + 4),auStack_88);
    uVar2 = (*DAT_0019f7ac)(auStack_88);
    *(undefined4 *)(*(int *)(param_1 + 0x4f8) * 4 + 0x504 + param_1) = uVar2;
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(*(int *)(param_1 + 0x4f8) * 4 + 0x544 + param_1) = (float)lVar3;
    *(int *)(param_1 + 0x4f8) = *(int *)(param_1 + 0x4f8) + 1;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__13CTriggerRelayP14KeyValueData_s  @ 00119be4
void KeyValue__13CTriggerRelayP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"triggerstate");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x460) = 0;
    }
    else if (iVar1 == 2) {
      *(undefined4 *)(param_1 + 0x460) = 3;
    }
    else {
      *(undefined4 *)(param_1 + 0x460) = 1;
    }
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CBasePlatTrainP14KeyValueData_s  @ 000cd114
void KeyValue__14CBasePlatTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"lip");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x484) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x480) = (float)lVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"height");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x4c4) = (float)lVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"rotation");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x4e4) = (float)lVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
          if (iVar1 == 0) {
            lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x4f8) = (char)(longlong)ROUND(lVar2);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"stopsnd");
            if (iVar1 == 0) {
              lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(char *)(param_1 + 0x4f9) = (char)(longlong)ROUND(lVar2);
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                *(float *)(param_1 + 0x4fc) = (float)lVar2;
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


// KeyValue__14CFuncTankLaserP14KeyValueData_s  @ 000ac3b8
void KeyValue__14CFuncTankLaserP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"laserentity");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1d4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__9CFuncTankP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__14CMomentaryDoorP14KeyValueData_s  @ 0009ee28
void KeyValue__14CMomentaryDoorP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"movesnd");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(char *)(param_1 + 0x4f8) = (char)(longlong)ROUND(lVar2);
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


// KeyValue__14CTargetCDAudioP14KeyValueData_s  @ 00119168
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


// KeyValue__14CTriggerCameraP14KeyValueData_s  @ 00116e90
void KeyValue__14CTriggerCameraP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wait");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x478) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"moveto");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x474) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"acceleration");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x490) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"deceleration");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(float *)(param_1 + 0x494) = (float)lVar3;
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


// KeyValue__15CAmbientGenericP14KeyValueData_s  @ 000efe6c
void KeyValue__15CAmbientGenericP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"preset");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x45c) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"pitch");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x460) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      iVar1 = *(int *)(param_1 + 0x460);
      if (0xff < iVar1) {
        *(undefined4 *)(param_1 + 0x460) = 0xff;
        iVar1 = 0xff;
      }
      if (-1 < iVar1) {
        return;
      }
      *(undefined4 *)(param_1 + 0x460) = 0;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"pitchstart");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(param_1 + 0x464) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
      iVar1 = *(int *)(param_1 + 0x464);
      if (0xff < iVar1) {
        *(undefined4 *)(param_1 + 0x464) = 0xff;
        iVar1 = 0xff;
      }
      if (-1 < iVar1) {
        return;
      }
      *(undefined4 *)(param_1 + 0x464) = 0;
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"spinup");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(int *)(param_1 + 0x468) = iVar1;
      if (100 < iVar1) {
        *(undefined4 *)(param_1 + 0x468) = 100;
      }
      iVar1 = *(int *)(param_1 + 0x468);
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x468) = 0;
        iVar1 = 0;
      }
      if (0 < iVar1) {
        iVar1 = (0x65 - iVar1) * 0x40;
        *(int *)(param_1 + 0x468) = iVar1;
      }
      *(int *)(param_1 + 0x49c) = iVar1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"spindown");
      if (iVar1 == 0) {
        iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(int *)(param_1 + 0x46c) = iVar1;
        if (100 < iVar1) {
          *(undefined4 *)(param_1 + 0x46c) = 100;
        }
        iVar1 = *(int *)(param_1 + 0x46c);
        if (iVar1 < 0) {
          *(undefined4 *)(param_1 + 0x46c) = 0;
          iVar1 = 0;
        }
        if (0 < iVar1) {
          iVar1 = (0x65 - iVar1) * 0x40;
          *(int *)(param_1 + 0x46c) = iVar1;
        }
        *(int *)(param_1 + 0x4a0) = iVar1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"volstart");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(int *)(param_1 + 0x474) = iVar1;
          if (10 < iVar1) {
            *(undefined4 *)(param_1 + 0x474) = 10;
          }
          iVar1 = *(int *)(param_1 + 0x474);
          if (iVar1 < 0) {
            *(undefined4 *)(param_1 + 0x474) = 0;
            iVar1 = 0;
          }
          *(int *)(param_1 + 0x474) = iVar1 * 10;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"fadein");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(int *)(param_1 + 0x478) = iVar1;
            if (100 < iVar1) {
              *(undefined4 *)(param_1 + 0x478) = 100;
            }
            iVar1 = *(int *)(param_1 + 0x478);
            if (iVar1 < 0) {
              *(undefined4 *)(param_1 + 0x478) = 0;
              iVar1 = 0;
            }
            if (0 < iVar1) {
              iVar1 = (0x65 - iVar1) * 0x40;
              *(int *)(param_1 + 0x478) = iVar1;
            }
            *(int *)(param_1 + 0x4ac) = iVar1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"fadeout");
            if (iVar1 == 0) {
              iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(int *)(param_1 + 0x47c) = iVar1;
              if (100 < iVar1) {
                *(undefined4 *)(param_1 + 0x47c) = 100;
              }
              iVar1 = *(int *)(param_1 + 0x47c);
              if (iVar1 < 0) {
                *(undefined4 *)(param_1 + 0x47c) = 0;
                iVar1 = 0;
              }
              if (0 < iVar1) {
                iVar1 = (0x65 - iVar1) * 0x40;
                *(int *)(param_1 + 0x47c) = iVar1;
              }
              *(int *)(param_1 + 0x4b0) = iVar1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"lfotype");
              if (iVar1 == 0) {
                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                *(int *)(param_1 + 0x480) = iVar1;
                if (4 < iVar1) {
                  *(undefined4 *)(param_1 + 0x480) = 2;
                }
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"lforate");
                if (iVar1 == 0) {
                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                  *(int *)(param_1 + 0x484) = iVar1;
                  if (1000 < iVar1) {
                    *(undefined4 *)(param_1 + 0x484) = 1000;
                  }
                  iVar1 = *(int *)(param_1 + 0x484);
                  if (iVar1 < 0) {
                    *(undefined4 *)(param_1 + 0x484) = 0;
                    iVar1 = 0;
                  }
                  *(int *)(param_1 + 0x484) = iVar1 << 8;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"lfomodpitch");
                  if (iVar1 == 0) {
                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                    *(int *)(param_1 + 0x488) = iVar1;
                    if (100 < iVar1) {
                      *(undefined4 *)(param_1 + 0x488) = 100;
                    }
                    if (*(int *)(param_1 + 0x488) < 0) {
                      *(undefined4 *)(param_1 + 0x488) = 0;
                    }
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"lfomodvol");
                    if (iVar1 == 0) {
                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                      *(int *)(param_1 + 0x48c) = iVar1;
                      if (100 < iVar1) {
                        *(undefined4 *)(param_1 + 0x48c) = 100;
                      }
                      if (*(int *)(param_1 + 0x48c) < 0) {
                        *(undefined4 *)(param_1 + 0x48c) = 0;
                      }
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"cspinup");
                      if (iVar1 != 0) {
                        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
                        return;
                      }
                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                      *(int *)(param_1 + 0x490) = iVar1;
                      if (100 < iVar1) {
                        *(undefined4 *)(param_1 + 0x490) = 100;
                      }
                      if (*(int *)(param_1 + 0x490) < 0) {
                        *(undefined4 *)(param_1 + 0x490) = 0;
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


// KeyValue__15CFuncTankMortarP14KeyValueData_s  @ 000ac030
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


// KeyValue__15CFuncTrackTrainP14KeyValueData_s  @ 000ce814
void KeyValue__15CFuncTrackTrainP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"wheels");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x45c) = (float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"height");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x460) = (float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"startspeed");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x46c) = (float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x48c) = uVar2;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
          if (iVar1 == 0) {
            iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
            *(float *)(param_1 + 0x490) = (float)iVar1;
            *(float *)(param_1 + 0x490) = (float)iVar1 * 0.1;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"bank");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(float *)(param_1 + 0x494) = (float)lVar3;
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


// KeyValue__16CFuncIllusionaryP14KeyValueData_s  @ 00089ae0
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


// KeyValue__16CFuncMortarFieldP14KeyValueData_s  @ 000c3768
void KeyValue__16CFuncMortarFieldP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszXController");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x4f8) = uVar2;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszYController");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x4fc) = uVar2;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"m_flSpread");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(param_1 + 0x500) = (float)lVar3;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"m_fControl");
        if (iVar1 == 0) {
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x50c) = uVar2;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"m_iCount");
          if (iVar1 != 0) {
            return;
          }
          uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(undefined4 *)(param_1 + 0x508) = uVar2;
        }
      }
    }
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__16CFuncTrackChangeP14KeyValueData_s  @ 000d04f4
void KeyValue__16CFuncTrackChangeP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"train");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x52c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"toptrack");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_1 + 0x524) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"bottomtrack");
      if (iVar1 == 0) {
        uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x528) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__14CBasePlatTrainP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__17CFrictionModifierP14KeyValueData_s  @ 0011a058
void KeyValue__17CFrictionModifierP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"modifier");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x458) = (float)((longdouble)0.01 * lVar2);
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__17CScriptedSentenceP14KeyValueData_s  @ 000ea4d8
void KeyValue__17CScriptedSentenceP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"sentence");
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    param_1[0x13e] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"entity");
    if (iVar1 == 0) {
      iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      param_1[0x13f] = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"duration");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x141] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0x140] = (int)(float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"refire");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            param_1[0x142] = (int)(float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"attenuation");
            if (iVar1 == 0) {
              uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
              *(undefined4 *)(*param_1 + 0x184) = uVar2;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"volume");
              if (iVar1 == 0) {
                lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                param_1[0x144] = (int)(float)((longdouble)0.1 * lVar3);
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"listener");
                if (iVar1 == 0) {
                  iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
                  param_1[0x146] = iVar1;
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


// KeyValue__18CTriggerEndSectionP14KeyValueData_s  @ 001181e8
void KeyValue__18CTriggerEndSectionP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"section");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1d4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__19CMomentaryRotButtonP14KeyValueData_s  @ 0008c958
void KeyValue__19CMomentaryRotButtonP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"returnspeed");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x500) = (float)lVar3;
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
  return;
}


// KeyValue__20CTriggerChangeTargetP14KeyValueData_s  @ 00117f98
void KeyValue__20CTriggerChangeTargetP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"m_iszNewTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_1 + 0x460) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__10CBaseDelayP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__5CFadeP14KeyValueData_s  @ 000a2c34
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


// KeyValue__5CItemP14KeyValueData_s  @ 000b603c
void KeyValue__5CItemP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"respawn_delay");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x458) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__6CBloodP14KeyValueData_s  @ 000a272c
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


// KeyValue__6CDecalP14KeyValueData_s  @ 00127f70
void KeyValue__6CDecalP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f750)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x110) = uVar2;
    if (*(int *)(*param_1 + 0x110) < 0) {
      (*DAT_0019f794)(1,"Can\'t find decal %s\n",*(undefined4 *)(param_2 + 8));
    }
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__6CLaserP14KeyValueData_s  @ 000a1714
void KeyValue__6CLaserP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"LaserTarget");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(*param_1 + 0x1d4) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"width");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x144) = (float)(int)ROUND(lVar3);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"NoiseAmplitude");
      if (iVar1 == 0) {
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(*param_1 + 0x114) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"TextureScroll");
        if (iVar1 == 0) {
          iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
          *(float *)(*param_1 + 0x134) = (float)iVar1;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"texture");
          if (iVar1 == 0) {
            uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
            *(undefined4 *)(*param_1 + 0xb8) = uVar2;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"EndSprite");
            if (iVar1 == 0) {
              iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
              param_1[0x117] = iVar1;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"framestart");
              if (iVar1 == 0) {
                iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                *(float *)(*param_1 + 0x130) = (float)iVar1;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"damage");
                if (iVar1 == 0) {
                  lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  *(float *)(*param_1 + 0x1e0) = (float)lVar3;
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


// KeyValue__6CLightP14KeyValueData_s  @ 000b6214
void KeyValue__6CLightP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"style");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0x116] = iVar1;
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
        iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
        param_1[0x117] = iVar1;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
      }
    }
  }
  return;
}


// KeyValue__6CShakeP14KeyValueData_s  @ 000a2b0c
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


// KeyValue__6CWorldP14KeyValueData_s  @ 001277d4
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
    pcVar3 = DAT_0019f790;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"sounds");
    if (iVar1 == 0) {
      uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      *(undefined4 *)(gpGlobals + 0x8c) = uVar2;
      goto LAB_0012785a;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"WaveHeight");
    if (iVar1 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x144) = (float)((longdouble)0.125 * lVar4);
      *(undefined4 *)(param_2 + 0xc) = 1;
      (*DAT_0019f78c)("sv_wateramp",*(undefined4 *)(*param_1 + 0x144));
      return;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"MaxRange");
    if (iVar1 == 0) {
      lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(*param_1 + 0x1f8) = (float)lVar4;
      goto LAB_0012785a;
    }
    iVar1 = strcmp(*(char **)(param_2 + 4),"chaptertitle");
    if (iVar1 == 0) {
      uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(*param_1 + 0x1d0) = uVar2;
      goto LAB_0012785a;
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
    if (iVar1 != 0) {
      iVar1 = strcmp(*(char **)(param_2 + 4),"gametitle");
      if (iVar1 != 0) {
        KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
        return;
      }
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      if (iVar1 != 0) {
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 2;
      }
      goto LAB_0012785a;
    }
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    if (iVar1 == 0) goto LAB_0012785a;
    uVar2 = 0x3f800000;
    pcVar5 = "sv_newunit";
    pcVar3 = DAT_0019f78c;
  }
  (*pcVar3)(pcVar5,uVar2);
LAB_0012785a:
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


// KeyValue__7CLadderP14KeyValueData_s  @ 001186f4
void KeyValue__7CLadderP14KeyValueData_s(undefined4 param_1,undefined4 param_2)

{
  KeyValue__12CBaseTriggerP14KeyValueData_s(param_1,param_2);
  return;
}


// KeyValue__8CAreaDefP14KeyValueData_s  @ 00086e38
void KeyValue__8CAreaDefP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"areaname");
  if (iVar1 == 0) {
    strncpy((char *)(param_1 + 0x4e8),*(char **)(param_2 + 8),0x1f);
    *(undefined1 *)(param_1 + 0x507) = 0;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CDeadHEVP14KeyValueData_s  @ 000e4dc4
void KeyValue__8CDeadHEVP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"pose");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x69c) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__12CBaseMonsterP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CMessageP14KeyValueData_s  @ 000a2cdc
void KeyValue__8CMessageP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"messagesound");
  if (iVar1 == 0) {
    uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
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


// KeyValue__8CNodeEntP14KeyValueData_s  @ 000cb584
void KeyValue__8CNodeEntP14KeyValueData_s(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"hinttype");
  if (iVar2 == 0) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined2 *)(param_1 + 0x458) = uVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  iVar2 = strcmp(*(char **)(param_2 + 4),"activity");
  if (iVar2 == 0) {
    uVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined2 *)(param_1 + 0x45a) = uVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__8CSpeakerP14KeyValueData_s  @ 000f1e48
void KeyValue__8CSpeakerP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"preset");
  if (iVar1 == 0) {
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    *(undefined4 *)(param_1 + 0x458) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__9CBaseDoorP14KeyValueData_s  @ 0009cd20
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
      *(char *)((int)param_1 + 0x4f9) = (char)(longlong)ROUND(lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"stopsnd");
      if (iVar1 == 0) {
        lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(char *)((int)param_1 + 0x4fa) = (char)(longlong)ROUND(lVar2);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"healthvalue");
        if (iVar1 == 0) {
          lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          *(char *)(param_1 + 0x13e) = (char)(longlong)ROUND(lVar2);
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sound");
          if (iVar1 == 0) {
            lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            *(char *)(param_1 + 0x148) = (char)(longlong)ROUND(lVar2);
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"locked_sentence");
            if (iVar1 == 0) {
              lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              *(char *)((int)param_1 + 0x521) = (char)(longlong)ROUND(lVar2);
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sound");
              if (iVar1 == 0) {
                lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                *(char *)((int)param_1 + 0x522) = (char)(longlong)ROUND(lVar2);
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"unlocked_sentence");
                if (iVar1 == 0) {
                  lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  *(char *)((int)param_1 + 0x523) = (char)(longlong)ROUND(lVar2);
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


// KeyValue__9CBubblingP14KeyValueData_s  @ 0009f51c
void KeyValue__9CBubblingP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"density");
  if (iVar1 == 0) {
    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
    param_1[0x116] = iVar1;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"frequency");
    if (iVar1 == 0) {
      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
      param_1[0x117] = iVar1;
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


// KeyValue__9CEnvLightP14KeyValueData_s  @ 000b62e8
/* WARNING: Removing unreachable block (ram,0x000b65b1) */
/* WARNING: Removing unreachable block (ram,0x000b65b9) */
/* WARNING: Removing unreachable block (ram,0x000b65ce) */
/* WARNING: Removing unreachable block (ram,0x000b64e5) */
/* WARNING: Removing unreachable block (ram,0x000b6401) */
/* WARNING: Removing unreachable block (ram,0x000b6409) */
/* WARNING: Removing unreachable block (ram,0x000b641e) */
/* WARNING: Removing unreachable block (ram,0x000b640d) */
/* WARNING: Removing unreachable block (ram,0x000b6420) */
/* WARNING: Removing unreachable block (ram,0x000b6425) */
/* WARNING: Removing unreachable block (ram,0x000b6427) */
/* WARNING: Removing unreachable block (ram,0x000b6468) */
/* WARNING: Removing unreachable block (ram,0x000b6434) */
/* WARNING: Removing unreachable block (ram,0x000b64d9) */
/* WARNING: Removing unreachable block (ram,0x000b64e1) */
/* WARNING: Removing unreachable block (ram,0x000b64f6) */
/* WARNING: Removing unreachable block (ram,0x000b64f8) */
/* WARNING: Removing unreachable block (ram,0x000b64fd) */
/* WARNING: Removing unreachable block (ram,0x000b64ff) */
/* WARNING: Removing unreachable block (ram,0x000b6540) */
/* WARNING: Removing unreachable block (ram,0x000b650c) */
/* WARNING: Removing unreachable block (ram,0x000b65bd) */
/* WARNING: Removing unreachable block (ram,0x000b65d0) */
/* WARNING: Removing unreachable block (ram,0x000b65d5) */
/* WARNING: Removing unreachable block (ram,0x000b65d7) */
/* WARNING: Removing unreachable block (ram,0x000b6618) */
/* WARNING: Removing unreachable block (ram,0x000b65e4) */

void KeyValue__9CEnvLightP14KeyValueData_s(undefined4 param_1,int param_2)

{
  double dVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  longdouble lVar3;
  longdouble lVar4;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined8 local_5c;
  undefined2 local_54;
  undefined2 uStack_52;
  undefined4 local_50;
  undefined2 local_48;
  undefined2 uStack_46;
  char local_44 [64];
  
  iVar2 = strcmp(*(char **)(param_2 + 4),"_light");
  if (iVar2 == 0) {
    iVar2 = sscanf(*(char **)(param_2 + 8),"%d %d %d %d\n",&local_6c,&local_68,&local_64,&local_60);
    if (iVar2 == 1) {
      local_64 = local_6c;
      local_68 = local_6c;
    }
    else if (iVar2 == 4) {
      dVar1 = (double)local_60;
      local_6c = (int)ROUND((double)local_6c * 0.00392156862745098 * dVar1);
      local_68 = (int)ROUND((double)local_68 * 0.00392156862745098 * dVar1);
      local_64 = (int)ROUND((double)local_64 * 0.00392156862745098 * dVar1);
    }
    lVar3 = (longdouble)0.008771929824561403 * (longdouble)local_6c;
    lVar4 = (longdouble)0;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) {
      lVar4 = (longdouble)log2(lVar3);
      lVar4 = (longdouble)1 * lVar4 * (longdouble)0.6;
      lVar3 = ROUND(lVar4);
      lVar4 = (longdouble)f2xm1(lVar4 - lVar3);
      lVar4 = (longdouble)fscale(lVar4 + (longdouble)1.0,lVar3);
    }
    local_6c = (int)ROUND((longdouble)264.0 * lVar4);
    lVar3 = (longdouble)0.008771929824561403 * (longdouble)local_68;
    lVar4 = (longdouble)0;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) {
      lVar4 = (longdouble)log2(lVar3);
      lVar4 = (longdouble)1 * lVar4 * (longdouble)0.6;
      lVar3 = ROUND(lVar4);
      lVar4 = (longdouble)f2xm1(lVar4 - lVar3);
      lVar4 = (longdouble)fscale(lVar4 + (longdouble)1.0,lVar3);
    }
    local_68 = (int)ROUND((longdouble)264.0 * lVar4);
    lVar3 = (longdouble)0.008771929824561403 * (longdouble)local_64;
    _local_54 = CONCAT22(uStack_52,in_FPUControlWord);
    local_5c = 1;
    lVar4 = (longdouble)0;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) {
      lVar4 = (longdouble)log2(lVar3);
      lVar4 = (longdouble)1 * lVar4 * (longdouble)0.6;
      lVar3 = ROUND(lVar4);
      lVar4 = (longdouble)f2xm1(lVar4 - lVar3);
      lVar4 = (longdouble)fscale(lVar4 + (longdouble)1.0,lVar3);
    }
    _local_48 = CONCAT22(uStack_46,in_FPUControlWord);
    local_50 = CONCAT22(uStack_46,CONCAT11(0xc,(char)in_FPUControlWord));
    local_64 = (int)ROUND((longdouble)264.0 * lVar4);
    *(undefined4 *)(param_2 + 0xc) = 1;
    sprintf(local_44,"%d",local_6c);
    (*DAT_0019f790)("sv_skycolor_r",local_44);
    sprintf(local_44,"%d",local_68);
    (*DAT_0019f790)("sv_skycolor_g",local_44);
    sprintf(local_44,"%d",local_64);
    (*DAT_0019f790)("sv_skycolor_b",local_44);
  }
  else {
    KeyValue__6CLightP14KeyValueData_s(param_1,param_2);
  }
  return;
}


// KeyValue__9CEnvSoundP14KeyValueData_s  @ 000f2838
void KeyValue__9CEnvSoundP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"radius");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x458) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  iVar1 = strcmp(*(char **)(param_2 + 4),"roomtype");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x45c) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  return;
}


// KeyValue__9CEnvSparkP14KeyValueData_s  @ 0008c084
void KeyValue__9CEnvSparkP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"MaxDelay");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x458) = (float)lVar2;
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


// KeyValue__9CFuncTankP14KeyValueData_s  @ 000a9e80
void KeyValue__9CFuncTankP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"yawrate");
  if (iVar1 == 0) {
    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    param_1[0x11c] = (int)(float)lVar3;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"yawrange");
    if (iVar1 == 0) {
      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      param_1[0x11d] = (int)(float)lVar3;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      iVar1 = strcmp(*(char **)(param_2 + 4),"yawtolerance");
      if (iVar1 == 0) {
        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        param_1[0x11e] = (int)(float)lVar3;
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      else {
        iVar1 = strcmp(*(char **)(param_2 + 4),"pitchrange");
        if (iVar1 == 0) {
          lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
          param_1[0x121] = (int)(float)lVar3;
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
        else {
          iVar1 = strcmp(*(char **)(param_2 + 4),"pitchrate");
          if (iVar1 == 0) {
            lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
            param_1[0x120] = (int)(float)lVar3;
            *(undefined4 *)(param_2 + 0xc) = 1;
          }
          else {
            iVar1 = strcmp(*(char **)(param_2 + 4),"pitchtolerance");
            if (iVar1 == 0) {
              lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
              param_1[0x122] = (int)(float)lVar3;
              *(undefined4 *)(param_2 + 0xc) = 1;
            }
            else {
              iVar1 = strcmp(*(char **)(param_2 + 4),"firerate");
              if (iVar1 == 0) {
                lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                param_1[0x124] = (int)(float)lVar3;
                *(undefined4 *)(param_2 + 0xc) = 1;
              }
              else {
                iVar1 = strcmp(*(char **)(param_2 + 4),"barrel");
                if (iVar1 == 0) {
                  lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                  param_1[0x129] = (int)(float)lVar3;
                  *(undefined4 *)(param_2 + 0xc) = 1;
                }
                else {
                  iVar1 = strcmp(*(char **)(param_2 + 4),"barrely");
                  if (iVar1 == 0) {
                    lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                    param_1[0x12a] = (int)(float)lVar3;
                    *(undefined4 *)(param_2 + 0xc) = 1;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(param_2 + 4),"barrelz");
                    if (iVar1 == 0) {
                      lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                      param_1[299] = (int)(float)lVar3;
                      *(undefined4 *)(param_2 + 0xc) = 1;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(param_2 + 4),"spritescale");
                      if (iVar1 == 0) {
                        lVar3 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                        param_1[300] = (int)(float)lVar3;
                        *(undefined4 *)(param_2 + 0xc) = 1;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(param_2 + 4),"spritesmoke");
                        if (iVar1 == 0) {
                          iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
                          param_1[0x12d] = iVar1;
                          *(undefined4 *)(param_2 + 0xc) = 1;
                        }
                        else {
                          iVar1 = strcmp(*(char **)(param_2 + 4),"spriteflash");
                          if (iVar1 == 0) {
                            iVar1 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
                            param_1[0x12e] = iVar1;
                            *(undefined4 *)(param_2 + 0xc) = 1;
                          }
                          else {
                            iVar1 = strcmp(*(char **)(param_2 + 4),"rotatesound");
                            if (iVar1 == 0) {
                              uVar2 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
                              *(undefined4 *)(*param_1 + 0x1e8) = uVar2;
                              *(undefined4 *)(param_2 + 0xc) = 1;
                            }
                            else {
                              iVar1 = strcmp(*(char **)(param_2 + 4),"persistence");
                              if (iVar1 == 0) {
                                lVar3 = (longdouble)
                                        __strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                                param_1[0x126] = (int)(float)lVar3;
                                *(undefined4 *)(param_2 + 0xc) = 1;
                              }
                              else {
                                iVar1 = strcmp(*(char **)(param_2 + 4),"bullet");
                                if (iVar1 == 0) {
                                  iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                  param_1[0x12f] = iVar1;
                                  *(undefined4 *)(param_2 + 0xc) = 1;
                                }
                                else {
                                  iVar1 = strcmp(*(char **)(param_2 + 4),"bullet_damage");
                                  if (iVar1 == 0) {
                                    iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
                                    param_1[0x130] = iVar1;
                                    *(undefined4 *)(param_2 + 0xc) = 1;
                                  }
                                  else {
                                    iVar1 = strcmp(*(char **)(param_2 + 4),"firespread");
                                    if (iVar1 == 0) {
                                      iVar1 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0)
                                      ;
                                      param_1[0x134] = iVar1;
                                      *(undefined4 *)(param_2 + 0xc) = 1;
                                    }
                                    else {
                                      iVar1 = strcmp(*(char **)(param_2 + 4),"minRange");
                                      if (iVar1 == 0) {
                                        lVar3 = (longdouble)
                                                __strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
                                        param_1[0x127] = (int)(float)lVar3;
                                        *(undefined4 *)(param_2 + 0xc) = 1;
                                      }
                                      else {
                                        iVar1 = strcmp(*(char **)(param_2 + 4),"maxRange");
                                        if (iVar1 == 0) {
                                          lVar3 = (longdouble)
                                                  __strtod_internal(*(undefined4 *)(param_2 + 8),0,0
                                                                   );
                                          param_1[0x128] = (int)(float)lVar3;
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


// KeyValue__9CPendulumP14KeyValueData_s  @ 00089588
void KeyValue__9CPendulumP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = strcmp(*(char **)(param_2 + 4),"distance");
  if (iVar1 == 0) {
    lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)(param_1 + 0x45c) = (float)lVar2;
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"damp");
    if (iVar1 == 0) {
      lVar2 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
      *(float *)(param_1 + 0x464) = (float)((longdouble)0.001 * lVar2);
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    else {
      KeyValue__11CBaseEntityP14KeyValueData_s(param_1,param_2);
    }
  }
  return;
}


// KeyValue__9CPushableP14KeyValueData_s  @ 000a9040
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KeyValue__9CPushableP14KeyValueData_s(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  longdouble lVar5;
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
    puVar4 = &local_10;
    local_10 = 0x41000000;
    local_1c = 0xc1000000;
    puVar3 = &local_1c;
    local_18 = local_1c;
    local_14 = local_1c;
    local_c = local_10;
    local_8 = local_10;
    goto LAB_000a91a5;
  default:
    puVar4 = &local_34;
    local_30 = 0x41800000;
    local_2c = 0x42100000;
    local_28 = _FUN_0014b4f0;
    break;
  case 2:
    puVar4 = &local_1c;
    local_10 = 0x41800000;
    local_8 = 0x41900000;
    local_1c = 0x42000000;
    local_14 = 0x42100000;
    local_30 = _FUN_0014b4f0;
    local_2c = 0xc1900000;
    local_28 = 0xc2000000;
    local_18 = local_1c;
    local_c = local_10;
    break;
  case 3:
    puVar4 = &local_10;
    local_10 = 0x41800000;
    local_8 = 0x41900000;
    local_34 = _FUN_0014b4f0;
    local_2c = 0xc1900000;
    puVar3 = &local_34;
    local_30 = local_34;
    local_c = local_10;
    goto LAB_000a91a5;
  }
  local_20 = 0xc2100000;
  puVar3 = &local_28;
  local_34 = local_30;
  local_24 = local_28;
LAB_000a91a5:
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,puVar3,puVar4);
  return;
}


// KeyValue__9CRechargeP14KeyValueData_s  @ 000b28e8
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
    *(undefined4 *)(param_1 + 0x4fc) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


