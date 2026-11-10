// ClientCommand__10CGameRulesP11CBasePlayerPCc  @ 000b8970
undefined4 ClientCommand__10CGameRulesP11CBasePlayerPCc(void)

{
  return 0;
}


// ClientCommand__13CTeamFortressP11CBasePlayerPCc  @ 000f4f30
undefined4
ClientCommand__13CTeamFortressP11CBasePlayerPCc(undefined4 param_1,int param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_3,"menuselect");
  if ((iVar1 == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_2 + 0x114)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_2 + 0x114) == 2.0) << 0xe) >> 8)) == 0x40)) {
    iVar1 = (*DAT_00175610)();
    if (iVar1 < 2) {
      uVar2 = 0;
    }
    else {
      uVar2 = (*DAT_0017560c)(1);
      iVar1 = __strtol_internal(uVar2,0,10,0);
      Menu_Team_Input__11CBasePlayerf(param_2,(float)iVar1);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc(param_1,param_2,param_3);
  }
  return uVar2;
}


// ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc  @ 000f34d0
undefined4
ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc(undefined4 param_1,int param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if (((iVar1 != 0) && (iVar1 = strcmp(param_3,"menuselect"), iVar1 == 0)) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_2 + 0x114)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_2 + 0x114) == 2.0) << 0xe) >> 8)) == 0x40)) {
    iVar1 = (*DAT_00175610)();
    if (iVar1 < 2) {
      return 1;
    }
    uVar2 = (*DAT_0017560c)(1);
    iVar1 = __strtol_internal(uVar2,0,10,0);
    Menu_Team_Input__11CBasePlayerf(param_2,(float)iVar1);
    return 1;
  }
  uVar2 = ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc(param_1,param_2,param_3);
  return uVar2;
}


// ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc  @ 000b7400
undefined4
ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc
          (undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_3,"menuselect");
  if (iVar1 == 0) {
    iVar1 = (*DAT_00175610)();
    if (iVar1 < 2) {
      uVar2 = 1;
    }
    else {
      uVar2 = (*DAT_0017560c)(1);
      iVar1 = __strtol_internal(uVar2,0,10,0);
      Menu_Input__11CBasePlayerf(param_2,(float)iVar1);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ClientCommand__FP7edict_s  @ 000a2680
void ClientCommand__FP7edict_s(int param_1)

{
  float fVar1;
  float fVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  
  pcVar3 = (char *)(*DAT_0017560c)(0);
  if (*(int *)(param_1 + 0xd8) == 0) {
    return;
  }
  iVar4 = param_1;
  if ((param_1 == 0) && (iVar4 = (*DAT_001755d4)(0), iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0xd8);
  }
  iVar5 = strcmp(pcVar3,"special");
  if (iVar5 == 0) {
    UseSpecialSkill__11CBasePlayer(iVar4);
    goto LAB_000a2df1;
  }
  iVar5 = strcmp(pcVar3,"say");
  if (iVar5 == 0) {
    uVar7 = 0;
LAB_000a2734:
    Host_Say__FP7edict_si(param_1,uVar7);
  }
  else {
    iVar5 = strcmp(pcVar3,"say_team");
    if (iVar5 == 0) {
      uVar7 = 1;
      goto LAB_000a2734;
    }
    iVar5 = strcmp(pcVar3,"give");
    if (iVar5 == 0) {
      if ((byte)(0.0 < g_flWeaponCheat | (byte)((ushort)((ushort)NAN(g_flWeaponCheat) << 10) >> 8) |
                (byte)((ushort)((ushort)(g_flWeaponCheat == 0.0) << 0xe) >> 8)) != 0x40) {
        uVar7 = (*DAT_0017560c)(1);
        GiveNamedItem__11CBasePlayerPc(iVar4,uVar7);
      }
    }
    else {
      iVar5 = strcmp(pcVar3,"fov");
      if (iVar5 == 0) {
        iVar5 = (*DAT_00175610)();
        if (iVar5 < 2) {
          uVar7 = UTIL_VarArgs__FPce("\"fov\" is \"%d\"\n",*(undefined4 *)(iVar4 + 0x810),0,0,0,0);
          ClientPrint__FP9entvars_tiPCcN42(param_1 + 0xdc,1,uVar7);
        }
        else {
          uVar7 = (*DAT_0017560c)(1);
          uVar7 = __strtol_internal(uVar7,0,10,0);
          *(undefined4 *)(iVar4 + 0x810) = uVar7;
        }
      }
      else {
        iVar5 = strcmp(pcVar3,"scout");
        if (iVar5 == 0) {
          uVar7 = 1;
        }
        else {
          iVar5 = strcmp(pcVar3,"sniper");
          if (iVar5 == 0) {
            uVar7 = 2;
          }
          else {
            iVar5 = strcmp(pcVar3,"soldier");
            if (iVar5 == 0) {
              uVar7 = 3;
            }
            else {
              iVar5 = strcmp(pcVar3,"demoman");
              if (iVar5 == 0) {
                uVar7 = 4;
              }
              else {
                iVar5 = strcmp(pcVar3,"medic");
                if (iVar5 == 0) {
                  uVar7 = 5;
                }
                else {
                  iVar5 = strcmp(pcVar3,"hvyweap");
                  if ((iVar5 == 0) || (iVar5 = strcmp(pcVar3,"hwguy"), iVar5 == 0)) {
                    uVar7 = 6;
                  }
                  else {
                    iVar5 = strcmp(pcVar3,"pyro");
                    if (iVar5 == 0) {
                      uVar7 = 7;
                    }
                    else {
                      iVar5 = strcmp(pcVar3,"spy");
                      if (iVar5 == 0) {
                        uVar7 = 8;
                      }
                      else {
                        iVar5 = strcmp(pcVar3,"engineer");
                        if (iVar5 == 0) {
                          uVar7 = 9;
                        }
                        else {
                          iVar5 = strcmp(pcVar3,"randompc");
                          if (iVar5 != 0) {
                            if (*(int *)(iVar4 + 0x2c) == 0) {
LAB_000a2a00:
                              iVar5 = strcmp(pcVar3,"admin");
                              if (iVar5 == 0) {
                                uVar7 = (*DAT_0017560c)(1);
                                AdminAccess__11CBasePlayerPc(iVar4,uVar7);
                              }
                              else if (*(int *)(iVar4 + 0x1fc) == 1) {
                                iVar5 = strcmp(pcVar3,"adm_countplayers");
                                if (iVar5 == 0) {
                                  Admin_CountPlayers__11CBasePlayer(iVar4);
                                }
                                else {
                                  if (*(int *)(iVar4 + 0x1fc) != 1) goto LAB_000a2bb0;
                                  iVar5 = strcmp(pcVar3,"adm_ceasefire");
                                  if (iVar5 == 0) {
                                    Admin_CeaseFire__11CBasePlayer(iVar4);
                                  }
                                  else {
                                    if (*(int *)(iVar4 + 0x1fc) != 1) goto LAB_000a2bb0;
                                    iVar5 = strcmp(pcVar3,"adm_deal");
                                    if (((iVar5 == 0) ||
                                        (iVar5 = strcmp(pcVar3,"adm_next"), iVar5 == 0)) ||
                                       (iVar5 = strcmp(pcVar3,"next"), iVar5 == 0)) {
                                      Admin_CycleDeal__11CBasePlayer(iVar4);
                                    }
                                    else {
                                      if (*(int *)(iVar4 + 0x1fc) != 1) goto LAB_000a2bb0;
                                      iVar5 = strcmp(pcVar3,"adm_kick");
                                      if (((iVar5 == 0) ||
                                          (iVar5 = strcmp(pcVar3,"kick"), iVar5 == 0)) &&
                                         (*(int *)(iVar4 + 0x200) == 1)) {
                                        Admin_DoKick__11CBasePlayer(iVar4);
                                      }
                                      else {
                                        if (*(int *)(iVar4 + 0x1fc) != 1) goto LAB_000a2bb0;
                                        iVar5 = strcmp(pcVar3,"adm_ban");
                                        if (((iVar5 == 0) ||
                                            (iVar5 = strcmp(pcVar3,"ban"), iVar5 == 0)) &&
                                           (*(int *)(iVar4 + 0x200) == 1)) {
                                          Admin_DoBan__11CBasePlayer(iVar4);
                                        }
                                        else {
                                          if ((*(int *)(iVar4 + 0x1fc) != 1) ||
                                             (iVar5 = strcmp(pcVar3,"adm_listplayers"), iVar5 != 0))
                                          goto LAB_000a2bb0;
                                          Admin_ListIPs__11CBasePlayer(iVar4);
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              else {
LAB_000a2bb0:
                                iVar5 = (**(code **)(*g_pGameRules + 0x68))
                                                  (g_pGameRules,iVar4,pcVar3);
                                if (iVar5 == 0) {
                                  iVar5 = (**(code **)(*(int *)(iVar4 + 0x3c8) + 0x88))(iVar4);
                                  if (iVar5 == 0) {
                                    return;
                                  }
                                  if (((*(int *)(iVar4 + 0x6c) == 0) &&
                                      (*(int *)(iVar4 + 0x70) == 0)) &&
                                     (*(int *)(iVar4 + 0x74) == 0)) {
                                    iVar5 = strcmp(pcVar3,"use");
                                    if (iVar5 == 0) {
                                      uVar7 = (*DAT_0017560c)(1);
                                      SelectItem__11CBasePlayerPCc(iVar4,uVar7);
                                    }
                                    else {
                                      pcVar6 = strstr(pcVar3,"weapon_");
                                      if (((pcVar6 == (char *)0x0) || (pcVar6 != pcVar3)) &&
                                         ((pcVar6 = strstr(pcVar3,"tf_weapon_"),
                                          pcVar6 == (char *)0x0 || (pcVar6 != pcVar3)))) {
                                        iVar5 = strcmp(pcVar3,"lastinv");
                                        if (iVar5 == 0) {
                                          SelectLastItem__11CBasePlayer(iVar4);
                                        }
                                        else {
                                          iVar5 = strcmp(pcVar3,"primeone");
                                          if (iVar5 == 0) {
LAB_000a2cc6:
                                            uVar7 = 1;
                                          }
                                          else {
                                            iVar5 = strcmp(pcVar3,"primetwo");
                                            if (iVar5 != 0) {
                                              iVar5 = strcmp(pcVar3,"+gren1");
                                              if (iVar5 == 0) goto LAB_000a2cc6;
                                              iVar5 = strcmp(pcVar3,"+gren2");
                                              if (iVar5 != 0) {
                                                iVar5 = strcmp(pcVar3,"detstart");
                                                if (iVar5 == 0) {
                                                  iVar5 = (*DAT_00175610)();
                                                  if (iVar5 < 2) {
LAB_000a2d72:
                                                    uVar7 = 0x14;
                                                  }
                                                  else {
                                                    uVar7 = (*DAT_0017560c)(1);
                                                    uVar7 = __strtol_internal(uVar7,0,10,0);
                                                  }
                                                }
                                                else {
                                                  iVar5 = strcmp(pcVar3,"+det5");
                                                  if (iVar5 == 0) {
                                                    uVar7 = 5;
                                                  }
                                                  else {
                                                    iVar5 = strcmp(pcVar3,"+det20");
                                                    if (iVar5 == 0) goto LAB_000a2d72;
                                                    iVar5 = strcmp(pcVar3,"+det50");
                                                    if (iVar5 != 0) {
                                                      iVar5 = strcmp(pcVar3,"discard");
                                                      if ((iVar5 == 0) ||
                                                         (iVar5 = strcmp(pcVar3,"drop"), iVar5 == 0)
                                                         ) {
                                                        TeamFortress_Discard__11CBasePlayer(iVar4);
                                                      }
                                                      else if ((*(int *)(iVar4 + 0x2c) != 0) &&
                                                              (iVar5 = strcmp(pcVar3,"saveme"),
                                                              iVar5 == 0)) {
                                                        TeamFortress_SaveMe__11CBasePlayer(iVar4);
                                                      }
                                                      goto LAB_000a2df1;
                                                    }
                                                    uVar7 = 0x32;
                                                  }
                                                }
                                                TeamFortress_SetDetpack__11CBasePlayeri(iVar4,uVar7)
                                                ;
                                                goto LAB_000a2df1;
                                              }
                                            }
                                            uVar7 = 2;
                                          }
                                          TeamFortress_PrimeGrenade__11CBasePlayeri(iVar4,uVar7);
                                        }
                                      }
                                      else {
                                        SelectItem__11CBasePlayerPCc(iVar4,pcVar3);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            else {
                              iVar5 = strcmp(pcVar3,"changeclass");
                              if (iVar5 == 0) {
                                *(undefined4 *)(iVar4 + 0x114) = 0x41a00000;
                              }
                              else {
                                if ((*(int *)(iVar4 + 0x2c) == 0) ||
                                   (iVar5 = strcmp(pcVar3,"changeteam"), iVar5 != 0))
                                goto LAB_000a2a00;
                                if (*(int *)(iVar4 + 0x2c) == 9) {
                                  Engineer_RemoveBuildings__11CBasePlayer(iVar4);
                                }
                                *(undefined4 *)(iVar4 + 0x114) = 0x41a80000;
                              }
                            }
                            goto LAB_000a2df1;
                          }
                          uVar7 = 10;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ChangeClass__11CBasePlayeri(iVar4,uVar7);
      }
    }
  }
LAB_000a2df1:
  iVar5 = strcmp(pcVar3,"flaginfo");
  if (iVar5 == 0) {
    TeamFortress_DisplayDetectionItems__11CBasePlayer(iVar4);
    return;
  }
  if ((*(int *)(iVar4 + 0x2c) != 0) && (iVar5 = strcmp(pcVar3,"dropitems"), iVar5 == 0)) {
    DropGoalItems__11CBasePlayer(iVar4);
    return;
  }
  if (*(int *)(iVar4 + 0x2c) == 9) {
    iVar5 = strcmp(pcVar3,"detsentry");
    if (iVar5 == 0) {
      pcVar3 = "building_sentrygun";
    }
    else {
      if ((*(int *)(iVar4 + 0x2c) != 9) || (iVar5 = strcmp(pcVar3,"detdispenser"), iVar5 != 0))
      goto LAB_000a2e90;
      pcVar3 = "building_dispenser";
    }
    DestroyBuilding__FP11CBaseEntityPc(iVar4,pcVar3);
  }
  else {
LAB_000a2e90:
    iVar5 = strcmp(pcVar3,"detpipe");
    if (iVar5 == 0) {
      if (*(int *)(iVar4 + 0x830) != 0) {
        fVar1 = *(float *)(*(int *)(iVar4 + 0x830) + 0x3fc);
        fVar2 = *gpGlobals;
        if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
          ExplodeOldPipebomb__11CBasePlayeri(iVar4,1);
        }
      }
    }
    else {
      iVar5 = strcmp(pcVar3,"throwgren");
      if (((iVar5 == 0) || (iVar5 = strcmp(pcVar3,"-gren1"), iVar5 == 0)) ||
         (iVar5 = strcmp(pcVar3,"-gren2"), iVar5 == 0)) {
        TeamFortress_ThrowPrimedGrenade__11CBasePlayer(iVar4);
      }
      else {
        iVar5 = strcmp(pcVar3,"detstop");
        if (((iVar5 == 0) || (iVar5 = strcmp(pcVar3,"-det5"), iVar5 == 0)) ||
           ((iVar5 = strcmp(pcVar3,"-det20"), iVar5 == 0 ||
            (iVar5 = strcmp(pcVar3,"-det50"), iVar5 == 0)))) {
          TeamFortress_DetpackStop__11CBasePlayer(iVar4);
        }
        else {
          iVar5 = strcmp(pcVar3,"build");
          if ((iVar5 == 0) && (*(int *)(iVar4 + 0x2c) == 9)) {
            TeamFortress_EngineerBuild__11CBasePlayer(iVar4);
          }
          else {
            iVar5 = strcmp(pcVar3,"disguise");
            if ((iVar5 == 0) && (*(int *)(iVar4 + 0x2c) == 8)) {
              TeamFortress_SpyGoUndercover__11CBasePlayer(iVar4);
            }
            else {
              iVar5 = strcmp(pcVar3,"feign");
              if ((iVar5 == 0) && (*(int *)(iVar4 + 0x2c) == 8)) {
                uVar7 = 0;
              }
              else {
                iVar5 = strcmp(pcVar3,"sfeign");
                if (iVar5 != 0) {
                  return;
                }
                if (*(int *)(iVar4 + 0x2c) != 8) {
                  return;
                }
                uVar7 = 1;
              }
              TeamFortress_SpyFeignDeath__11CBasePlayeri(iVar4,uVar7);
            }
          }
        }
      }
    }
  }
  return;
}


