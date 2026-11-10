// ClientCommand__10CGameRulesP11CBasePlayerPCc  @ 000b0338
undefined4 ClientCommand__10CGameRulesP11CBasePlayerPCc(void)

{
  return 0;
}


// ClientCommand__13CTeamFortressP11CBasePlayerPCc  @ 000fbbf4
undefined4
ClientCommand__13CTeamFortressP11CBasePlayerPCc(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ClientCommand__13CVoiceGameMgrP11CBasePlayerPCc(param_1 + 0x18,param_2,param_3);
  if (cVar1 == '\0') {
    uVar2 = ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc(param_1,param_2,param_3);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// ClientCommand__13CVoiceGameMgrP11CBasePlayerPCc  @ 0013abd4
undefined4 ClientCommand__13CVoiceGameMgrP11CBasePlayerPCc(int param_1,int *param_2,char *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char *__s;
  int iVar4;
  undefined4 uVar5;
  char *__format;
  undefined4 uStack_8;
  
  iVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_2 + 0x208));
  iVar2 = iVar2 + -1;
  if ((iVar2 < 0) || (*(int *)(param_1 + 0xc) <= iVar2)) {
    VoiceServerDebug__FPCce
              ("CVoiceGameMgr::ClientCommand: cmd %s from invalid client (%d)\n",param_3,iVar2);
    uVar5 = 1;
  }
  else {
    iVar3 = strcasecmp(param_3,"vban");
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7f0)(), 1 < iVar3)) {
      for (iVar3 = 1; iVar4 = (*DAT_0019f7f0)(), iVar3 < iVar4; iVar3 = iVar3 + 1) {
        uStack_8 = 0;
        __format = "%x";
        __s = (char *)(*DAT_0019f7ec)(iVar3,&DAT_0015c044,&uStack_8);
        sscanf(__s,__format);
        if (iVar3 < 2) {
          VoiceServerDebug__FPCce
                    ("CVoiceGameMgr::ClientCommand: vban (0x%x) from %d\n",uStack_8,iVar2);
          *(undefined4 *)(iVar2 * 4 + 0x1af73c + iVar3 * 4) = uStack_8;
        }
        else {
          VoiceServerDebug__FPCce("CVoiceGameMgr::ClientCommand: invalid index (%d)\n",iVar3);
        }
      }
      return 1;
    }
    iVar3 = strcasecmp(param_3,"VModEnable");
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7f0)(), 1 < iVar3)) {
      uVar5 = (*DAT_0019f7ec)(1);
      iVar3 = __strtol_internal(uVar5,0,10,0);
      VoiceServerDebug__FPCce("CVoiceGameMgr::ClientCommand: VModEnable (%d)\n",iVar3 != 0);
      uVar5 = (*DAT_0019f7ec)(1);
      iVar3 = __strtol_internal(uVar5,0,10,0);
      iVar4 = iVar2 >> 5;
      bVar1 = (byte)iVar2;
      if (iVar3 == 0) {
        (&g_PlayerModEnable)[iVar4] =
             (&g_PlayerModEnable)[iVar4] &
             (-2 << (bVar1 & 0x1f) | 0xfffffffeU >> 0x20 - (bVar1 & 0x1f));
      }
      else {
        (&g_PlayerModEnable)[iVar4] = (&g_PlayerModEnable)[iVar4] | 1 << (bVar1 & 0x1f);
      }
      (&g_bWantModEnable)[iVar4] =
           (&g_bWantModEnable)[iVar4] &
           (-2 << (bVar1 & 0x1f) | 0xfffffffeU >> 0x20 - (bVar1 & 0x1f));
      return 1;
    }
    uVar5 = 0;
  }
  return uVar5;
}


// ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc  @ 000f9ba4
void ClientCommand__17CHalfLifeTeamplayP11CBasePlayerPCc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc(param_1,param_2,param_3);
  return;
}


// ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc  @ 000afd90
undefined4
ClientCommand__18CHalfLifeMultiplayP11CBasePlayerPCc
          (undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_3,"menuselect");
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7f0)();
    if (iVar1 < 2) {
      uVar2 = 1;
    }
    else {
      uVar2 = (*DAT_0019f7ec)(1);
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


// ClientCommand__FP7edict_s  @ 00090524
void ClientCommand__FP7edict_s(int param_1)

{
  float fVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined2 uVar12;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  pcVar2 = (char *)(*DAT_0019f7ec)(0);
  if (*(int *)(param_1 + 0x7c) == 0) {
    return;
  }
  iVar3 = param_1;
  if ((param_1 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = *(int **)(iVar3 + 0x7c);
  }
  iVar3 = strcmp(pcVar2,"special");
  if ((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"_special"), iVar3 == 0)) {
    UseSpecialSkill__11CBasePlayer(piVar9);
    goto LAB_000910e0;
  }
  iVar3 = strcmp(pcVar2,"say");
  if (iVar3 == 0) {
    uVar7 = 0;
LAB_000905ee:
    Host_Say__FP7edict_si(param_1,uVar7);
  }
  else {
    iVar3 = strcmp(pcVar2,"say_team");
    if (iVar3 == 0) {
      uVar7 = 1;
      goto LAB_000905ee;
    }
    iVar3 = strcmp(pcVar2,"fullupdate");
    if (iVar3 == 0) {
      ForceClientDllUpdate__11CBasePlayer(piVar9);
    }
    else {
      iVar3 = strcmp(pcVar2,"tell");
      if (iVar3 == 0) {
        Host_Tell__FP7edict_s(param_1);
      }
      else {
        iVar3 = strcmp(pcVar2,"give");
        if (iVar3 == 0) {
          if ((byte)(0.0 < g_flWeaponCheat |
                     (byte)((ushort)((ushort)NAN(g_flWeaponCheat) << 10) >> 8) |
                    (byte)((ushort)((ushort)(g_flWeaponCheat == 0.0) << 0xe) >> 8)) != 0x40) {
            uVar7 = (*DAT_0019f7ec)(1);
            GiveNamedItem__11CBasePlayerPc(piVar9,uVar7);
          }
        }
        else {
          iVar3 = strcmp(pcVar2,"fov");
          if (iVar3 == 0) {
            iVar3 = (*DAT_0019f7f0)();
            if (iVar3 < 2) {
              uVar7 = UTIL_VarArgs__FPce("\"fov\" is \"%d\"\n",piVar9[0x22f],0,0,0,0);
              ClientPrint__FP9entvars_siPCcN42(param_1 + 0x80,1,uVar7);
            }
            else {
              uVar7 = (*DAT_0019f7ec)(1);
              iVar3 = __strtol_internal(uVar7,0,10,0);
              piVar9[0x22f] = iVar3;
              *(float *)(*piVar9 + 0x214) = (float)iVar3;
            }
          }
          else {
            iVar3 = strcmp(pcVar2,"spectate");
            if (iVar3 == 0) {
              iVar3 = *piVar9;
              if ((*(byte *)(iVar3 + 0x1a6) & 0x10) == 0) {
                if ((byte)((float)allow_spectators._12_4_ < 0.0 |
                           (byte)((ushort)((ushort)NAN((float)allow_spectators._12_4_) << 10) >> 8)
                          | (byte)((ushort)((ushort)((float)allow_spectators._12_4_ == 0.0) << 0xe)
                                  >> 8)) == 0x40) {
                  if ((*(int *)(iVar3 + 0x20c) == 0) && (*(int *)(iVar3 + 0x1ac) == 0))
                  goto LAB_00090c10;
                }
                else if (((float)piVar9[0x1c6] < *gpGlobals) && (piVar9[0x48] != 0)) {
                  uVar7 = GetTeamName__Fi(piVar9[0x48]);
                  uVar7 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar9 + 0x208),uVar7);
                  uVar7 = (*DAT_0019f864)(*(undefined4 *)(*piVar9 + 0x208),uVar7);
                  UTIL_LogPrintf__FPce
                            ("\"%s<%i><%s><%s>\" joined team \"SPECTATOR\"\n",
                             *(int *)(*piVar9 + 0x1d0) + (int)gpGlobals[0x26],uVar7);
                  piVar9[0x1c6] = (int)(*gpGlobals + 1.0);
                  iVar4 = EntSelectSpawnPoint__FP7edict_s(param_1);
                  iVar3 = iVar4 + 0x80;
                  iVar8 = iVar3;
                  if (iVar4 == 0) {
                    iVar8 = 0;
                  }
                  local_1c = *(undefined4 *)(iVar8 + 8);
                  local_18 = *(undefined4 *)(iVar8 + 0xc);
                  local_14 = *(undefined4 *)(iVar8 + 0x10);
                  if (iVar4 == 0) {
                    iVar3 = 0;
                  }
                  local_10 = *(undefined4 *)(iVar3 + 0x50);
                  local_c = *(undefined4 *)(iVar3 + 0x54);
                  local_8 = *(undefined4 *)(iVar3 + 0x58);
                  puVar11 = &local_10;
                  puVar5 = &local_1c;
                  goto LAB_0009093f;
                }
              }
              else {
                uVar7 = GetTeamName__Fi(piVar9[0x48]);
                uVar7 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar9 + 0x208),uVar7);
                uVar7 = (*DAT_0019f864)(*(undefined4 *)(*piVar9 + 0x208),uVar7);
                UTIL_LogPrintf__FPce
                          ("\"%s<%i><%s><%s>\" joined team \"SPECTATOR\"\n",
                           *(int *)(*piVar9 + 0x1d0) + (int)gpGlobals[0x26],uVar7);
                iVar4 = EntSelectSpawnPoint__FP7edict_s(param_1);
                iVar3 = iVar4 + 0x80;
                iVar8 = iVar3;
                if (iVar4 == 0) {
                  iVar8 = 0;
                }
                local_10 = *(undefined4 *)(iVar8 + 8);
                local_c = *(undefined4 *)(iVar8 + 0xc);
                local_8 = *(undefined4 *)(iVar8 + 0x10);
                if (iVar4 == 0) {
                  iVar3 = 0;
                }
                local_1c = *(undefined4 *)(iVar3 + 0x50);
                local_18 = *(undefined4 *)(iVar3 + 0x54);
                local_14 = *(undefined4 *)(iVar3 + 0x58);
                puVar11 = &local_1c;
                puVar5 = &local_10;
LAB_0009093f:
                StartObserver__11CBasePlayerG6VectorT1(piVar9,puVar5,puVar11);
              }
            }
            else {
              iVar3 = strcmp(pcVar2,"specmode");
              if (iVar3 == 0) {
                if (*(int *)(*piVar9 + 0x244) != 0) {
                  uVar7 = (*DAT_0019f7ec)(1);
                  uVar7 = __strtol_internal(uVar7,0,10,0);
                  Observer_SetMode__11CBasePlayeri(piVar9,uVar7);
                }
              }
              else {
                iVar3 = strcmp(pcVar2,"follownext");
                if (iVar3 == 0) {
                  if (*(int *)(*piVar9 + 0x244) != 0) {
                    uVar7 = (*DAT_0019f7ec)(1);
                    uVar12 = 0;
                    iVar3 = __strtol_internal(uVar7,0,10,0);
                    Observer_FindNextPlayer__11CBasePlayerb
                              (piVar9,CONCAT22(uVar12,(short)CONCAT31((int3)((uint)iVar3 >> 8),
                                                                      iVar3 != 0)));
                  }
                }
                else {
                  iVar3 = strcmp(pcVar2,"scout");
                  if (iVar3 == 0) {
                    uVar7 = 1;
                  }
                  else {
                    iVar3 = strcmp(pcVar2,"sniper");
                    if (iVar3 == 0) {
                      uVar7 = 2;
                    }
                    else {
                      iVar3 = strcmp(pcVar2,"soldier");
                      if (iVar3 == 0) {
                        uVar7 = 3;
                      }
                      else {
                        iVar3 = strcmp(pcVar2,"demoman");
                        if (iVar3 == 0) {
                          uVar7 = 4;
                        }
                        else {
                          iVar3 = strcmp(pcVar2,"medic");
                          if (iVar3 == 0) {
                            uVar7 = 5;
                          }
                          else {
                            iVar3 = strcmp(pcVar2,"hvyweap");
                            if ((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"hwguy"), iVar3 == 0)) {
                              uVar7 = 6;
                            }
                            else {
                              iVar3 = strcmp(pcVar2,"pyro");
                              if (iVar3 == 0) {
                                uVar7 = 7;
                              }
                              else {
                                iVar3 = strcmp(pcVar2,"spy");
                                if (iVar3 == 0) {
                                  uVar7 = 8;
                                }
                                else {
                                  iVar3 = strcmp(pcVar2,"engineer");
                                  if (iVar3 != 0) {
                                    iVar3 = strcmp(pcVar2,"randompc");
                                    if (iVar3 == 0) {
                                      iVar3 = PositionAvailable__11CBasePlayer(piVar9);
                                      if (iVar3 != 0) {
                                        uVar7 = 10;
                                        goto LAB_00090bb6;
                                      }
                                      ClientPrint__FP9entvars_siPCcN42
                                                (param_1 + 0x80,1,"#Game_enoughofclass",0,0,0,0);
                                      Menu_Class__11CBasePlayer(piVar9);
                                    }
                                    else {
                                      iVar3 = strcmp(pcVar2,"civilian");
                                      if (iVar3 == 0) {
                                        iVar3 = TeamFortress_TeamIsCivilian__Ff((float)piVar9[0x48])
                                        ;
                                        if (iVar3 != 0) {
                                          uVar7 = 0xb;
                                          goto LAB_00090bb6;
                                        }
                                      }
                                      else {
                                        iVar3 = strcmp(pcVar2,"changeclass");
                                        if (iVar3 == 0) {
                                          if (*(int *)(*piVar9 + 0x244) == 0) {
                                            if (*(int *)(*piVar9 + 0x20c) != 0) {
                                              Menu_Class__11CBasePlayer(piVar9);
                                            }
                                            goto LAB_000910e0;
                                          }
                                        }
                                        else {
                                          iVar3 = strcmp(pcVar2,"changeteam");
                                          if (iVar3 != 0) {
                                            iVar3 = strcmp(pcVar2,"jointeam");
                                            if (iVar3 == 0) {
                                              iVar3 = (*DAT_0019f7f0)();
                                              if (1 < iVar3) {
                                                uVar7 = (*DAT_0019f7ec)(1);
                                                iVar3 = __strtol_internal(uVar7,0,10,0);
                                                if (iVar3 == 5) {
                                                  TeamFortress_TeamPutPlayerInTeam__11CBasePlayer
                                                            (piVar9);
                                                }
                                                else {
                                                  fVar1 = (float)iVar3;
                                                  if (((byte)(number_of_teams < fVar1 |
                                                              (byte)((ushort)((ushort)(NAN(
                                                  number_of_teams) || NAN(fVar1)) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(number_of_teams == fVar1)
                                                                 << 0xe) >> 8)) != 1) && (0 < iVar3)
                                                  ) {
                                                    TeamFortress_TeamSet__11CBasePlayeri
                                                              (piVar9,iVar3);
                                                  }
                                                }
                                              }
                                            }
                                            else {
                                              iVar3 = strcmp(pcVar2,"admin");
                                              if (iVar3 == 0) {
                                                uVar7 = (*DAT_0019f7ec)(1);
                                                AdminAccess__11CBasePlayerPc(piVar9,uVar7);
                                              }
                                              else if (piVar9[0x7f] == 1) {
                                                iVar3 = strcmp(pcVar2,"adm_countplayers");
                                                if (iVar3 == 0) {
                                                  Admin_CountPlayers__11CBasePlayer(piVar9);
                                                }
                                                else {
                                                  if (piVar9[0x7f] != 1) goto LAB_00090e7c;
                                                  iVar3 = strcmp(pcVar2,"adm_ceasefire");
                                                  if (iVar3 == 0) {
                                                    Admin_CeaseFire__Fv();
                                                  }
                                                  else {
                                                    if (piVar9[0x7f] != 1) goto LAB_00090e7c;
                                                    iVar3 = strcmp(pcVar2,"adm_deal");
                                                    if (((iVar3 == 0) ||
                                                        (iVar3 = strcmp(pcVar2,"adm_next"),
                                                        iVar3 == 0)) ||
                                                       (iVar3 = strcmp(pcVar2,"next"), iVar3 == 0))
                                                    {
                                                      Admin_CycleDeal__11CBasePlayer(piVar9);
                                                    }
                                                    else {
                                                      if (piVar9[0x7f] != 1) goto LAB_00090e7c;
                                                      iVar3 = strcmp(pcVar2,"adm_kick");
                                                      if (((iVar3 == 0) ||
                                                          (iVar3 = strcmp(pcVar2,"kick"), iVar3 == 0
                                                          )) && (piVar9[0x80] == 1)) {
                                                        Admin_DoKick__11CBasePlayer(piVar9);
                                                      }
                                                      else {
                                                        if (piVar9[0x7f] != 1) goto LAB_00090e7c;
                                                        iVar3 = strcmp(pcVar2,"adm_ban");
                                                        if (((iVar3 == 0) ||
                                                            (iVar3 = strcmp(pcVar2,"ban"),
                                                            iVar3 == 0)) && (piVar9[0x80] == 1)) {
                                                          Admin_DoBan__11CBasePlayer(piVar9);
                                                        }
                                                        else {
                                                          if (piVar9[0x7f] != 1) goto LAB_00090e7c;
                                                          iVar3 = strcmp(pcVar2,"adm_listplayers");
                                                          if (iVar3 == 0) {
                                                            Admin_ListIPs__11CBasePlayer(piVar9);
                                                          }
                                                          else {
                                                            if ((piVar9[0x7f] != 1) ||
                                                               (iVar3 = strcmp(pcVar2,
                                                  "adm_changelevel"), iVar3 != 0))
                                                  goto LAB_00090e7c;
                                                  Admin_Changelevel__11CBasePlayer(piVar9);
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                              else {
LAB_00090e7c:
                                                iVar3 = (**(code **)(*g_pGameRules + 0x68))
                                                                  (g_pGameRules,piVar9,pcVar2);
                                                if (iVar3 == 0) {
                                                  iVar3 = (**(code **)(piVar9[0x115] + 0x8c))
                                                                    (piVar9);
                                                  if (iVar3 == 0) {
                                                    return;
                                                  }
                                                  if (((piVar9[0x1a] == 0) && (piVar9[0x1b] == 0))
                                                     && (piVar9[0x1c] == 0)) {
                                                    iVar3 = strcmp(pcVar2,"use");
                                                    if (iVar3 == 0) {
                                                      uVar7 = (*DAT_0019f7ec)(1);
                                                      SelectItem__11CBasePlayerPCc(piVar9,uVar7);
                                                    }
                                                    else {
                                                      pcVar6 = strstr(pcVar2,"weapon_");
                                                      if (((pcVar6 == (char *)0x0) ||
                                                          (pcVar6 != pcVar2)) &&
                                                         ((pcVar6 = strstr(pcVar2,"tf_weapon_"),
                                                          pcVar6 == (char *)0x0 ||
                                                          (pcVar6 != pcVar2)))) {
                                                        iVar3 = strcmp(pcVar2,"lastinv");
                                                        if (iVar3 == 0) {
                                                          SelectLastItem__11CBasePlayer(piVar9);
                                                        }
                                                        else {
                                                          iVar3 = strcmp(pcVar2,"primeone");
                                                          if (iVar3 == 0) {
LAB_00090fa8:
                                                            uVar7 = 1;
                                                          }
                                                          else {
                                                            iVar3 = strcmp(pcVar2,"primetwo");
                                                            if (iVar3 != 0) {
                                                              iVar3 = strcmp(pcVar2,"+gren1");
                                                              if (iVar3 == 0) goto LAB_00090fa8;
                                                              iVar3 = strcmp(pcVar2,"+gren2");
                                                              if (iVar3 != 0) {
                                                                iVar3 = strcmp(pcVar2,"detstart");
                                                                if (iVar3 == 0) {
                                                                  iVar3 = (*DAT_0019f7f0)();
                                                                  if (iVar3 < 2) {
LAB_00091060:
                                                                    iVar3 = 0x14;
                                                                  }
                                                                  else {
                                                                    uVar7 = (*DAT_0019f7ec)(1);
                                                                    iVar3 = __strtol_internal(uVar7,
                                                  0,10,0);
                                                  if (0x32 < iVar3) {
                                                    iVar3 = 0x32;
                                                  }
                                                  if (iVar3 < 5) {
                                                    iVar3 = 5;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar3 = strcmp(pcVar2,"+det5");
                                                    if (iVar3 == 0) {
                                                      iVar3 = 5;
                                                    }
                                                    else {
                                                      iVar3 = strcmp(pcVar2,"+det20");
                                                      if (iVar3 == 0) goto LAB_00091060;
                                                      iVar3 = strcmp(pcVar2,"+det50");
                                                      if (iVar3 != 0) {
                                                        iVar3 = strcmp(pcVar2,"discard");
                                                        if ((iVar3 == 0) ||
                                                           (iVar3 = strcmp(pcVar2,"drop"),
                                                           iVar3 == 0)) {
                                                          TeamFortress_Discard__11CBasePlayer
                                                                    (piVar9);
                                                        }
                                                        else if ((*(int *)(*piVar9 + 0x20c) != 0) &&
                                                                (iVar3 = strcmp(pcVar2,"saveme"),
                                                                iVar3 == 0)) {
                                                          TeamFortress_SaveMe__11CBasePlayer(piVar9)
                                                          ;
                                                        }
                                                        goto LAB_000910e0;
                                                      }
                                                      iVar3 = 0x32;
                                                    }
                                                  }
                                                  TeamFortress_SetDetpack__11CBasePlayeri
                                                            (piVar9,iVar3);
                                                  goto LAB_000910e0;
                                                  }
                                                  }
                                                  uVar7 = 2;
                                                  }
                                                  TeamFortress_PrimeGrenade__11CBasePlayeri
                                                            (piVar9,uVar7);
                                                  }
                                                  }
                                                  else {
                                                    SelectItem__11CBasePlayerPCc(piVar9,pcVar2);
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                            goto LAB_000910e0;
                                          }
                                        }
LAB_00090c10:
                                        Menu_Team__11CBasePlayer(piVar9);
                                      }
                                    }
                                    goto LAB_000910e0;
                                  }
                                  uVar7 = 9;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
LAB_00090bb6:
                  ChangeClass__11CBasePlayeri(piVar9,uVar7);
                }
              }
            }
          }
        }
      }
    }
  }
LAB_000910e0:
  iVar3 = strcmp(pcVar2,"flaginfo");
  if (iVar3 == 0) {
    TeamFortress_DisplayDetectionItems__11CBasePlayer(piVar9);
    return;
  }
  if ((*(int *)(*piVar9 + 0x20c) != 0) && (iVar3 = strcmp(pcVar2,"dropitems"), iVar3 == 0)) {
    DropGoalItems__11CBasePlayer(piVar9);
    return;
  }
  if (*(int *)(*piVar9 + 0x20c) == 9) {
    iVar3 = strcmp(pcVar2,"detsentry");
    if (iVar3 == 0) {
      pcVar2 = "building_sentrygun";
LAB_00091195:
      DestroyBuilding__FP11CBaseEntityPc(piVar9,pcVar2);
      return;
    }
    if (*(int *)(*piVar9 + 0x20c) == 9) {
      iVar3 = strcmp(pcVar2,"detdispenser");
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"detdispensor"), iVar3 == 0)) {
        pcVar2 = "building_dispenser";
        goto LAB_00091195;
      }
      if (*(int *)(*piVar9 + 0x20c) == 9) {
        iVar3 = strcmp(pcVar2,"dismantle");
        if (iVar3 == 0) {
          iVar3 = (*DAT_0019f7f0)();
          if (iVar3 < 2) {
            return;
          }
          uVar7 = (*DAT_0019f7ec)(1);
          iVar3 = __strtol_internal(uVar7,0,10,0);
          if (iVar3 == 1) {
            uVar7 = 0x41100000;
          }
          else {
            if (iVar3 != 2) {
              return;
            }
            uVar7 = 0x40400000;
          }
        }
        else {
          if (*(int *)(*piVar9 + 0x20c) != 9) goto LAB_00091278;
          iVar3 = strcmp(pcVar2,"rotatesentry");
          if (iVar3 == 0) {
            uVar7 = 0x40800000;
          }
          else {
            if ((*(int *)(*piVar9 + 0x20c) != 9) ||
               (iVar3 = strcmp(pcVar2,"rotatesentry180"), iVar3 != 0)) goto LAB_00091278;
            uVar7 = 0x40c00000;
          }
        }
        Menu_Engineer_Input__11CBasePlayerf(piVar9,uVar7);
        return;
      }
    }
  }
LAB_00091278:
  iVar3 = strcmp(pcVar2,"detpipe");
  if (iVar3 == 0) {
    if ((piVar9[0x237] != 0) &&
       (fVar1 = *(float *)(piVar9[0x237] + 0x488),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
      ExplodeOldPipebomb__11CBasePlayerii(piVar9,1,0);
    }
  }
  else {
    iVar3 = strcmp(pcVar2,"throwgren");
    if (((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"-gren1"), iVar3 == 0)) ||
       (iVar3 = strcmp(pcVar2,"-gren2"), iVar3 == 0)) {
      TeamFortress_ThrowPrimedGrenade__11CBasePlayer(piVar9);
    }
    else {
      iVar3 = strcmp(pcVar2,"detstop");
      if (((iVar3 == 0) || (iVar3 = strcmp(pcVar2,"-det5"), iVar3 == 0)) ||
         ((iVar3 = strcmp(pcVar2,"-det20"), iVar3 == 0 ||
          (iVar3 = strcmp(pcVar2,"-det50"), iVar3 == 0)))) {
        TeamFortress_DetpackStop__11CBasePlayer(piVar9);
      }
      else {
        iVar3 = strcmp(pcVar2,"build");
        if ((iVar3 == 0) && (*(int *)(*piVar9 + 0x20c) == 9)) {
          iVar3 = (*DAT_0019f7f0)();
          if (iVar3 == 1) {
            uVar7 = 0;
          }
          else {
            uVar7 = (*DAT_0019f7ec)(1);
            uVar7 = __strtol_internal(uVar7,0,10,0);
          }
          TeamFortress_EngineerBuild__11CBasePlayeri(piVar9,uVar7);
        }
        else {
          iVar3 = strcmp(pcVar2,"disguise");
          if ((iVar3 == 0) && (*(int *)(*piVar9 + 0x20c) == 8)) {
            iVar3 = (*DAT_0019f7f0)();
            if (iVar3 == 1) {
              TeamFortress_SpyGoUndercover__11CBasePlayer(piVar9);
            }
            else {
              iVar3 = (*DAT_0019f7f0)();
              if (iVar3 == 2) {
                uVar7 = 0;
              }
              else {
                iVar3 = (*DAT_0019f7f0)();
                if (iVar3 != 3) {
                  return;
                }
                uVar7 = (*DAT_0019f7ec)(2);
                uVar7 = __strtol_internal(uVar7,0,10,0);
              }
              uVar7 = (*DAT_0019f7ec)(1,uVar7);
              uVar7 = __strtol_internal(uVar7,0,10,0);
              TeamFortress_SpyDisguise__11CBasePlayerii(piVar9,uVar7);
            }
          }
          else {
            iVar3 = strcmp(pcVar2,"disguise_enemy");
            if ((iVar3 == 0) && (*(int *)(*piVar9 + 0x20c) == 8)) {
              iVar3 = (*DAT_0019f7f0)();
              if (iVar3 == 1) {
                uVar7 = 0;
                uVar10 = 1;
              }
              else {
                uVar7 = (*DAT_0019f7ec)(1);
                uVar7 = __strtol_internal(uVar7,0,10,0);
                uVar10 = 1;
              }
            }
            else {
              iVar3 = strcmp(pcVar2,"disguise_friendly");
              if ((iVar3 != 0) || (*(int *)(*piVar9 + 0x20c) != 8)) {
                iVar3 = strcmp(pcVar2,"feign");
                if ((iVar3 == 0) && (*(int *)(*piVar9 + 0x20c) == 8)) {
                  uVar7 = 0;
                }
                else {
                  iVar3 = strcmp(pcVar2,"sfeign");
                  if (iVar3 != 0) {
                    return;
                  }
                  if (*(int *)(*piVar9 + 0x20c) != 8) {
                    return;
                  }
                  uVar7 = 1;
                }
                TeamFortress_SpyFeignDeath__11CBasePlayeri(piVar9,uVar7);
                return;
              }
              iVar3 = (*DAT_0019f7f0)();
              if (iVar3 == 1) {
                uVar7 = 0;
              }
              else {
                uVar7 = (*DAT_0019f7ec)(1);
                uVar7 = __strtol_internal(uVar7,0,10,0);
              }
              uVar10 = 0;
            }
            TeamFortress_SpyDisguiseEnemy__11CBasePlayerii(piVar9,uVar10,uVar7);
          }
        }
      }
    }
  }
  return;
}


