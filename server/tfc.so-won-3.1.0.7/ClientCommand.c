// ClientCommand__10CGameRulesP11CBasePlayerPCc  @ 000b0a1c
undefined4 ClientCommand__10CGameRulesP11CBasePlayerPCc(void)

{
  return 0;
}


// ClientCommand__13CTeamFortressP11CBasePlayerPCc  @ 000f925c
void ClientCommand__13CTeamFortressP11CBasePlayerPCc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc(param_1,param_2,param_3);
  return;
}


// ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc  @ 000f6fdc
void ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc(param_1,param_2,param_3);
  return;
}


// ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc  @ 000ae9f8
undefined4
ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc
          (undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_3,"menuselect");
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1170)();
    if (iVar1 < 2) {
      uVar2 = 1;
    }
    else {
      uVar2 = (*DAT_001c116c)(1);
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


// ClientCommand__FP7edict_s  @ 00090d4c
void ClientCommand__FP7edict_s(int param_1)

{
  float fVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pcVar2 = (char *)(*DAT_001c116c)(0);
  if (*(int *)(param_1 + 0x7c) == 0) {
    return;
  }
  iVar3 = param_1;
  if ((param_1 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = *(int **)(iVar3 + 0x7c);
  }
  iVar3 = strcmp(pcVar2,"special");
  if ((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"_special"), iVar3 == 0)) {
    UseSpecialSkill__11CBasePlayer(piVar7);
    goto LAB_000916ac;
  }
  iVar3 = strcmp(pcVar2,"say");
  if (iVar3 == 0) {
    uVar6 = 0;
LAB_00090e16:
    Host_Say__FP7edict_si(param_1,uVar6);
  }
  else {
    iVar3 = strcmp(pcVar2,"say_team");
    if (iVar3 == 0) {
      uVar6 = 1;
      goto LAB_00090e16;
    }
    iVar3 = strcmp(pcVar2,"tell");
    if (iVar3 == 0) {
      Host_Tell__FP7edict_s(param_1);
    }
    else {
      iVar3 = strcmp(pcVar2,"give");
      if (iVar3 == 0) {
        if ((byte)(0.0 < g_flWeaponCheat | (byte)((ushort)((ushort)NAN(g_flWeaponCheat) << 10) >> 8)
                  | (byte)((ushort)((ushort)(g_flWeaponCheat == 0.0) << 0xe) >> 8)) != 0x40) {
          uVar6 = (*DAT_001c116c)(1);
          GiveNamedItem__11CBasePlayerPc(piVar7,uVar6);
        }
      }
      else {
        iVar3 = strcmp(pcVar2,"fov");
        if (iVar3 == 0) {
          iVar3 = (*DAT_001c1170)();
          if (iVar3 < 2) {
            uVar6 = UTIL_VarArgs__FPce("\"fov\" is \"%d\"\n",piVar7[0x225],0,0,0,0);
            ClientPrint__FP9entvars_siPCcN42(param_1 + 0x80,1,uVar6);
          }
          else {
            uVar6 = (*DAT_001c116c)(1);
            iVar3 = __strtol_internal(uVar6,0,10,0);
            piVar7[0x225] = iVar3;
            *(float *)(*piVar7 + 0x214) = (float)piVar7[0x225];
          }
        }
        else {
          iVar3 = strcmp(pcVar2,"spectate");
          if (iVar3 == 0) {
            if ((byte)(0.0 < (float)allow_spectators._12_4_ |
                       (byte)((ushort)((ushort)NAN((float)allow_spectators._12_4_) << 10) >> 8) |
                      (byte)((ushort)((ushort)((float)allow_spectators._12_4_ == 0.0) << 0xe) >> 8))
                == 0x40) {
              if ((*(int *)(*piVar7 + 0x20c) == 0) && (*(int *)(*piVar7 + 0x1ac) == 0))
              goto LAB_000911f4;
            }
            else {
              iVar4 = EntSelectSpawnPoint__FP7edict_s(param_1);
              iVar3 = iVar4 + 0x80;
              if (iVar4 == 0) {
                iVar3 = 0;
              }
              local_c = *(undefined4 *)(iVar3 + 8);
              local_8 = *(undefined4 *)(iVar3 + 0xc);
              local_4 = *(undefined4 *)(iVar3 + 0x10);
              iVar3 = iVar4 + 0x80;
              if (iVar4 == 0) {
                iVar3 = 0;
              }
              local_18 = *(undefined4 *)(iVar3 + 0x50);
              local_14 = *(undefined4 *)(iVar3 + 0x54);
              local_10 = *(undefined4 *)(iVar3 + 0x58);
              StartObserver__11CBasePlayerG6VectorT1(piVar7,&local_c,&local_18);
            }
          }
          else {
            iVar3 = strcmp(pcVar2,"scout");
            if (iVar3 == 0) {
              uVar6 = 1;
            }
            else {
              iVar3 = strcmp(pcVar2,"sniper");
              if (iVar3 == 0) {
                uVar6 = 2;
              }
              else {
                iVar3 = strcmp(pcVar2,"soldier");
                if (iVar3 == 0) {
                  uVar6 = 3;
                }
                else {
                  iVar3 = strcmp(pcVar2,"demoman");
                  if (iVar3 == 0) {
                    uVar6 = 4;
                  }
                  else {
                    iVar3 = strcmp(pcVar2,"medic");
                    if (iVar3 == 0) {
                      uVar6 = 5;
                    }
                    else {
                      iVar3 = strcmp(pcVar2,"hvyweap");
                      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"hwguy"), iVar3 == 0)) {
                        uVar6 = 6;
                      }
                      else {
                        iVar3 = strcmp(pcVar2,"pyro");
                        if (iVar3 == 0) {
                          uVar6 = 7;
                        }
                        else {
                          iVar3 = strcmp(pcVar2,"spy");
                          if (iVar3 == 0) {
                            uVar6 = 8;
                          }
                          else {
                            iVar3 = strcmp(pcVar2,"engineer");
                            if (iVar3 != 0) {
                              iVar3 = strcmp(pcVar2,"randompc");
                              if (iVar3 == 0) {
                                iVar3 = PositionAvailable__11CBasePlayer(piVar7);
                                if (iVar3 != 0) {
                                  uVar6 = 10;
                                  goto LAB_00091196;
                                }
                                ClientPrint__FP9entvars_siPCcN42
                                          (param_1 + 0x80,1,"#Game_enoughofclass",0,0,0,0);
                                Menu_Class__11CBasePlayer(piVar7);
                              }
                              else {
                                iVar3 = strcmp(pcVar2,"civilian");
                                if (iVar3 == 0) {
                                  iVar3 = TeamFortress_TeamIsCivilian__Ff((float)piVar7[0x48]);
                                  if (iVar3 != 0) {
                                    uVar6 = 0xb;
                                    goto LAB_00091196;
                                  }
                                }
                                else {
                                  iVar3 = strcmp(pcVar2,"changeclass");
                                  if (iVar3 == 0) {
                                    if (*(int *)(*piVar7 + 0x244) == 0) {
                                      if (*(int *)(*piVar7 + 0x20c) != 0) {
                                        Menu_Class__11CBasePlayer(piVar7);
                                      }
                                      goto LAB_000916ac;
                                    }
                                  }
                                  else {
                                    iVar3 = strcmp(pcVar2,"changeteam");
                                    if (iVar3 != 0) {
                                      iVar3 = strcmp(pcVar2,"jointeam");
                                      if (iVar3 == 0) {
                                        iVar3 = (*DAT_001c1170)();
                                        if (1 < iVar3) {
                                          uVar6 = (*DAT_001c116c)(1);
                                          iVar3 = __strtol_internal(uVar6,0,10,0);
                                          if (iVar3 == 5) {
                                            TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(piVar7);
                                          }
                                          else if (((float)iVar3 <= number_of_teams) && (0 < iVar3))
                                          {
                                            TeamFortress_TeamSet__11CBasePlayeri(piVar7,iVar3);
                                          }
                                        }
                                      }
                                      else {
                                        iVar3 = strcmp(pcVar2,"admin");
                                        if (iVar3 == 0) {
                                          uVar6 = (*DAT_001c116c)(1);
                                          AdminAccess__11CBasePlayerPc(piVar7,uVar6);
                                        }
                                        else if (piVar7[0x7f] == 1) {
                                          iVar3 = strcmp(pcVar2,"adm_countplayers");
                                          if (iVar3 == 0) {
                                            Admin_CountPlayers__11CBasePlayer(piVar7);
                                          }
                                          else {
                                            if (piVar7[0x7f] != 1) goto LAB_00091460;
                                            iVar3 = strcmp(pcVar2,"adm_ceasefire");
                                            if (iVar3 == 0) {
                                              Admin_CeaseFire__Fv();
                                            }
                                            else {
                                              if (piVar7[0x7f] != 1) goto LAB_00091460;
                                              iVar3 = strcmp(pcVar2,"adm_deal");
                                              if (((iVar3 == 0) ||
                                                  (iVar3 = strcmp(pcVar2,"adm_next"), iVar3 == 0))
                                                 || (iVar3 = strcmp(pcVar2,"next"), iVar3 == 0)) {
                                                Admin_CycleDeal__11CBasePlayer(piVar7);
                                              }
                                              else {
                                                if (piVar7[0x7f] != 1) goto LAB_00091460;
                                                iVar3 = strcmp(pcVar2,"adm_kick");
                                                if (((iVar3 == 0) ||
                                                    (iVar3 = strcmp(pcVar2,"kick"), iVar3 == 0)) &&
                                                   (piVar7[0x80] == 1)) {
                                                  Admin_DoKick__11CBasePlayer(piVar7);
                                                }
                                                else {
                                                  if (piVar7[0x7f] != 1) goto LAB_00091460;
                                                  iVar3 = strcmp(pcVar2,"adm_ban");
                                                  if (((iVar3 == 0) ||
                                                      (iVar3 = strcmp(pcVar2,"ban"), iVar3 == 0)) &&
                                                     (piVar7[0x80] == 1)) {
                                                    Admin_DoBan__11CBasePlayer(piVar7);
                                                  }
                                                  else {
                                                    if (piVar7[0x7f] != 1) goto LAB_00091460;
                                                    iVar3 = strcmp(pcVar2,"adm_listplayers");
                                                    if (iVar3 == 0) {
                                                      Admin_ListIPs__11CBasePlayer(piVar7);
                                                    }
                                                    else {
                                                      if ((piVar7[0x7f] != 1) ||
                                                         (iVar3 = strcmp(pcVar2,"adm_changelevel"),
                                                         iVar3 != 0)) goto LAB_00091460;
                                                      Admin_Changelevel__11CBasePlayer(piVar7);
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                        else {
LAB_00091460:
                                          iVar3 = (**(code **)(*g_pGameRules + 0x68))
                                                            (g_pGameRules,piVar7,pcVar2);
                                          if (iVar3 == 0) {
                                            iVar3 = (**(code **)(piVar7[0x111] + 0x8c))(piVar7);
                                            if (iVar3 == 0) {
                                              return;
                                            }
                                            if (((piVar7[0x1a] == 0) && (piVar7[0x1b] == 0)) &&
                                               (piVar7[0x1c] == 0)) {
                                              iVar3 = strcmp(pcVar2,"use");
                                              if (iVar3 == 0) {
                                                uVar6 = (*DAT_001c116c)(1);
                                                SelectItem__11CBasePlayerPCc(piVar7,uVar6);
                                              }
                                              else {
                                                pcVar5 = strstr(pcVar2,"weapon_");
                                                if (((pcVar5 == (char *)0x0) || (pcVar5 != pcVar2))
                                                   && ((pcVar5 = strstr(pcVar2,"tf_weapon_"),
                                                       pcVar5 == (char *)0x0 || (pcVar5 != pcVar2)))
                                                   ) {
                                                  iVar3 = strcmp(pcVar2,"lastinv");
                                                  if (iVar3 == 0) {
                                                    SelectLastItem__11CBasePlayer(piVar7);
                                                  }
                                                  else {
                                                    iVar3 = strcmp(pcVar2,"primeone");
                                                    if (iVar3 == 0) {
LAB_0009158c:
                                                      uVar6 = 1;
                                                    }
                                                    else {
                                                      iVar3 = strcmp(pcVar2,"primetwo");
                                                      if (iVar3 != 0) {
                                                        iVar3 = strcmp(pcVar2,"+gren1");
                                                        if (iVar3 == 0) goto LAB_0009158c;
                                                        iVar3 = strcmp(pcVar2,"+gren2");
                                                        if (iVar3 != 0) {
                                                          iVar3 = strcmp(pcVar2,"detstart");
                                                          if (iVar3 == 0) {
                                                            iVar3 = (*DAT_001c1170)();
                                                            if (iVar3 < 2) {
LAB_0009162c:
                                                              uVar6 = 0x14;
                                                            }
                                                            else {
                                                              uVar6 = (*DAT_001c116c)(1);
                                                              uVar6 = __strtol_internal(uVar6,0,10,0
                                                                                       );
                                                            }
                                                          }
                                                          else {
                                                            iVar3 = strcmp(pcVar2,"+det5");
                                                            if (iVar3 == 0) {
                                                              uVar6 = 5;
                                                            }
                                                            else {
                                                              iVar3 = strcmp(pcVar2,"+det20");
                                                              if (iVar3 == 0) goto LAB_0009162c;
                                                              iVar3 = strcmp(pcVar2,"+det50");
                                                              if (iVar3 != 0) {
                                                                iVar3 = strcmp(pcVar2,"discard");
                                                                if ((iVar3 == 0) ||
                                                                   (iVar3 = strcmp(pcVar2,"drop"),
                                                                   iVar3 == 0)) {
                                                                                                                                    
                                                  TeamFortress_Discard__11CBasePlayer(piVar7);
                                                  }
                                                  else if ((*(int *)(*piVar7 + 0x20c) != 0) &&
                                                          (iVar3 = strcmp(pcVar2,"saveme"),
                                                          iVar3 == 0)) {
                                                    TeamFortress_SaveMe__11CBasePlayer(piVar7);
                                                  }
                                                  goto LAB_000916ac;
                                                  }
                                                  uVar6 = 0x32;
                                                  }
                                                  }
                                                  TeamFortress_SetDetpack__11CBasePlayeri
                                                            (piVar7,uVar6);
                                                  goto LAB_000916ac;
                                                  }
                                                  }
                                                  uVar6 = 2;
                                                  }
                                                  TeamFortress_PrimeGrenade__11CBasePlayeri
                                                            (piVar7,uVar6);
                                                  }
                                                }
                                                else {
                                                  SelectItem__11CBasePlayerPCc(piVar7,pcVar2);
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      goto LAB_000916ac;
                                    }
                                  }
LAB_000911f4:
                                  Menu_Team__11CBasePlayer(piVar7);
                                }
                              }
                              goto LAB_000916ac;
                            }
                            uVar6 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_00091196:
            ChangeClass__11CBasePlayeri(piVar7,uVar6);
          }
        }
      }
    }
  }
LAB_000916ac:
  iVar3 = strcmp(pcVar2,"flaginfo");
  if (iVar3 == 0) {
    TeamFortress_DisplayDetectionItems__11CBasePlayer(piVar7);
    return;
  }
  if ((*(int *)(*piVar7 + 0x20c) != 0) && (iVar3 = strcmp(pcVar2,"dropitems"), iVar3 == 0)) {
    DropGoalItems__11CBasePlayer(piVar7);
    return;
  }
  if (*(int *)(*piVar7 + 0x20c) == 9) {
    iVar3 = strcmp(pcVar2,"detsentry");
    if (iVar3 == 0) {
      pcVar2 = "building_sentrygun";
LAB_00091769:
      DestroyBuilding__FP11CBaseEntityPc(piVar7,pcVar2);
      return;
    }
    if (*(int *)(*piVar7 + 0x20c) == 9) {
      iVar3 = strcmp(pcVar2,"detdispenser");
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"detdispensor"), iVar3 == 0)) {
        pcVar2 = "building_dispenser";
        goto LAB_00091769;
      }
      if (*(int *)(*piVar7 + 0x20c) == 9) {
        iVar3 = strcmp(pcVar2,"dismantle");
        if (iVar3 == 0) {
          iVar3 = (*DAT_001c1170)();
          if (iVar3 < 2) {
            return;
          }
          uVar6 = (*DAT_001c116c)(1);
          iVar3 = __strtol_internal(uVar6,0,10,0);
          if (iVar3 == 1) {
            uVar6 = 0x41100000;
          }
          else {
            if (iVar3 != 2) {
              return;
            }
            uVar6 = 0x40400000;
          }
        }
        else {
          if (*(int *)(*piVar7 + 0x20c) != 9) goto LAB_0009184c;
          iVar3 = strcmp(pcVar2,"rotatesentry");
          if (iVar3 == 0) {
            uVar6 = 0x40800000;
          }
          else {
            if ((*(int *)(*piVar7 + 0x20c) != 9) ||
               (iVar3 = strcmp(pcVar2,"rotatesentry180"), iVar3 != 0)) goto LAB_0009184c;
            uVar6 = 0x40c00000;
          }
        }
        Menu_Engineer_Input__11CBasePlayerf(piVar7,uVar6);
        return;
      }
    }
  }
LAB_0009184c:
  iVar3 = strcmp(pcVar2,"detpipe");
  if (iVar3 == 0) {
    if ((piVar7[0x22d] != 0) &&
       (fVar1 = *(float *)(piVar7[0x22d] + 0x478),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
      ExplodeOldPipebomb__11CBasePlayerii(piVar7,1,0);
    }
  }
  else {
    iVar3 = strcmp(pcVar2,"throwgren");
    if (((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"-gren1"), iVar3 == 0)) ||
       (iVar3 = strcmp(pcVar2,"-gren2"), iVar3 == 0)) {
      TeamFortress_ThrowPrimedGrenade__11CBasePlayer(piVar7);
    }
    else {
      iVar3 = strcmp(pcVar2,"detstop");
      if (((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"-det5"), iVar3 == 0)) ||
         ((iVar3 = strcmp(pcVar2,"-det20"), iVar3 == 0 ||
          (iVar3 = strcmp(pcVar2,"-det50"), iVar3 == 0)))) {
        TeamFortress_DetpackStop__11CBasePlayer(piVar7);
      }
      else {
        iVar3 = strcmp(pcVar2,"build");
        if ((iVar3 == 0) && (*(int *)(*piVar7 + 0x20c) == 9)) {
          iVar3 = (*DAT_001c1170)();
          if (iVar3 == 1) {
            uVar6 = 0;
          }
          else {
            uVar6 = (*DAT_001c116c)(1);
            uVar6 = __strtol_internal(uVar6,0,10,0);
          }
          TeamFortress_EngineerBuild__11CBasePlayeri(piVar7,uVar6);
        }
        else {
          iVar3 = strcmp(pcVar2,"disguise");
          if ((iVar3 == 0) && (*(int *)(*piVar7 + 0x20c) == 8)) {
            iVar3 = (*DAT_001c1170)();
            if (iVar3 == 1) {
              TeamFortress_SpyGoUndercover__11CBasePlayer(piVar7);
            }
            else {
              iVar3 = (*DAT_001c1170)();
              if (iVar3 == 2) {
                uVar6 = 0;
              }
              else {
                iVar3 = (*DAT_001c1170)();
                if (iVar3 != 3) {
                  return;
                }
                uVar6 = (*DAT_001c116c)(2);
                uVar6 = __strtol_internal(uVar6,0,10,0);
              }
              uVar6 = (*DAT_001c116c)(1,uVar6);
              uVar6 = __strtol_internal(uVar6,0,10,0);
              TeamFortress_SpyDisguise__11CBasePlayerii(piVar7,uVar6);
            }
          }
          else {
            iVar3 = strcmp(pcVar2,"disguise_enemy");
            if ((iVar3 == 0) && (*(int *)(*piVar7 + 0x20c) == 8)) {
              iVar3 = (*DAT_001c1170)();
              if (iVar3 == 1) {
                uVar6 = 0;
                uVar8 = 1;
              }
              else {
                uVar6 = (*DAT_001c116c)(1);
                uVar6 = __strtol_internal(uVar6,0,10,0);
                uVar8 = 1;
              }
            }
            else {
              iVar3 = strcmp(pcVar2,"disguise_friendly");
              if ((iVar3 != 0) || (*(int *)(*piVar7 + 0x20c) != 8)) {
                iVar3 = strcmp(pcVar2,"feign");
                if ((iVar3 == 0) && (*(int *)(*piVar7 + 0x20c) == 8)) {
                  uVar6 = 0;
                }
                else {
                  iVar3 = strcmp(pcVar2,"sfeign");
                  if (iVar3 != 0) {
                    return;
                  }
                  if (*(int *)(*piVar7 + 0x20c) != 8) {
                    return;
                  }
                  uVar6 = 1;
                }
                TeamFortress_SpyFeignDeath__11CBasePlayeri(piVar7,uVar6);
                return;
              }
              iVar3 = (*DAT_001c1170)();
              if (iVar3 == 1) {
                uVar6 = 0;
              }
              else {
                uVar6 = (*DAT_001c116c)(1);
                uVar6 = __strtol_internal(uVar6,0,10,0);
              }
              uVar8 = 0;
            }
            TeamFortress_SpyDisguiseEnemy__11CBasePlayerii(piVar7,uVar8,uVar6);
          }
        }
      }
    }
  }
  return;
}


