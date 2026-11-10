// DoResults__FP11CBaseEntityP11CBasePlayeri  @ 0010b500
void DoResults__FP11CBaseEntityP11CBasePlayeri(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int local_4;
  
  fVar1 = *gpGlobals;
  if ((((byte)((cb_prematch_time < fVar1 |
                (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) - 1) < 0x40) ||
      (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 == 0x81)) &&
     (param_1[0x86] != 1)) {
    if (((float)param_1[0xfd] <= 0.0) || (param_1[0x86] == 4)) {
      if (param_1[0x89] != 0) {
        iVar2 = GetTeamCheckTeam__FPCc(param_1[0x89] + (int)gpGlobals[0x26]);
        param_1[0x87] = iVar2;
      }
      param_1[0x86] = 2;
      iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
      if ((iVar2 == 0x80) || (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 == 0x81))
      {
        *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
      }
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x1e8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar2 + 0x208),2,*(int *)(iVar2 + 0x1e8) + (int)gpGlobals[0x26],
                   0x3f800000,0x3f4ccccd,0,100);
      }
      if (param_1[0xbc] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(1,param_1[0xbc]);
      }
      if (param_1[0xbd] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(2,param_1[0xbd]);
      }
      if (param_1[0xbe] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(3,param_1[0xbe]);
      }
      if (param_1[0xbf] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(4,param_1[0xbf]);
      }
      if ((param_1[0xc0] != 0) && (param_1[0x87] != 0)) {
        TeamFortress_TeamIncreaseScore__Fii(param_1[0x87],param_1[0xc0]);
      }
      if (param_1 != (int *)0x0) {
        if (*(char *)(*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]) != '\0') {
          if (param_2 == (int *)0x0) {
            UTIL_LogPrintf__FPce
                      ("World triggered \"%s\"\n",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26])
            ;
          }
          else {
            if (param_2[0x48] == 0) {
              pcVar3 = "SPECTATOR";
            }
            else {
              pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],
                                               *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]);
            }
            uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
            uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
            UTIL_LogPrintf__FPce
                      ("\"%s<%i><%u><%s>\" triggered \"%s\"\n",
                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          }
        }
      }
      if (((CTF_Map == 1) && (param_2 != (int *)0x0)) &&
         ((param_1[0x84] == 1 || (param_1[0x84] == 3)))) {
        for (iVar2 = 1; iVar2 <= (int)gpGlobals[0x24]; iVar2 = iVar2 + 1) {
          piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar2);
          if (piVar5 != (int *)0x0) {
            if (((piVar5[0x48] == 2) && (param_1[0x84] == 1)) ||
               ((piVar5[0x48] == 1 && (param_1[0x84] == 2)))) {
              if (piVar5 != param_2) {
                pcVar3 = "Your team GOT the ENEMY flag!!";
                goto LAB_0010b920;
              }
              pcVar3 = "You got the enemy flag!\n\nReturn to base!";
LAB_0010b8ea:
              iVar6 = *param_2;
            }
            else {
              if (param_1[0x84] - 1U < 2) {
                pcVar3 = "Your flag has been TAKEN!!";
              }
              else if (((piVar5[0x48] == 2) && (param_1[0x84] == 3)) ||
                      ((piVar5[0x48] == 1 && (param_1[0x84] == 4)))) {
                if (piVar5 == param_2) {
                  pcVar3 = "You CAPTURED the FLAG!!";
                  goto LAB_0010b8ea;
                }
                pcVar3 = "Your flag was CAPTURED!!";
              }
              else {
                if (1 < param_1[0x84] - 3U) goto LAB_0010b92e;
                pcVar3 = "Your team CAPTURED the flag!!";
              }
LAB_0010b920:
              iVar6 = *piVar5;
            }
            ClientPrint__FP9entvars_siPCcN42(iVar6,4,pcVar3,0,0,0,0);
          }
LAB_0010b92e:
        }
        switch(param_1[0x84]) {
        case 1:
          uVar4 = UTIL_VarArgs__FPce("%s GOT the BLUE flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
          if (param_2[0x48] == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_2[0x48]);
          }
          uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%u><%s>\" triggered \"Stole_Blue_Flag\"\n",
                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 2;
          break;
        case 2:
          uVar4 = UTIL_VarArgs__FPce("%s GOT the RED flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
          if (param_2[0x48] == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_2[0x48]);
          }
          uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%u><%s>\" triggered \"Stole_Red_Flag\"\n",
                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 4;
          break;
        case 3:
          uVar4 = UTIL_VarArgs__FPce("%s CAPTURED the RED flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
          if (param_2[0x48] == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_2[0x48]);
          }
          uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%u><%s>\" triggered \"Captured_Red_Flag\"\n",
                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfb;
          break;
        case 4:
          uVar4 = UTIL_VarArgs__FPce("%s CAPTURED the BLUE flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
          if (param_2[0x48] == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(param_2[0x48]);
          }
          uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%u><%s>\" triggered \"Captured_Blue_Flag\"\n",
                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfd;
        }
      }
      if (param_1[0xae] != 0) {
        iVar2 = 0;
        while (iVar2 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar2,"netname","info_player_teamspawn"), iVar2 != 0) {
          if (*(int *)(iVar2 + 0x214) == param_1[0xae]) {
            InactivateSpawn__FP11CBaseEntity(iVar2);
          }
        }
      }
      if (param_1[0xaf] != 0) {
        iVar2 = 0;
        while (iVar2 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar2,"netname","info_player_teamspawn"), iVar2 != 0) {
          if (*(int *)(iVar2 + 0x214) == param_1[0xaf]) {
            ActivateSpawn__FP11CBaseEntity(iVar2);
          }
        }
      }
      if ((param_1[0xdd] != 0) && (CTF_Map == 0)) {
        UTIL_LogPrintf__FPce("World triggered \"%s\"\n",param_1[0xdd] + (int)gpGlobals[0x26]);
      }
      if (((param_1[0xee] != 0) && (CTF_Map == 0)) && (param_2 != (int *)0x0)) {
        if (param_2[0x48] == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],param_1[0xee] + (int)gpGlobals[0x26]);
        }
        uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
        uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar4);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%u><%s>\" triggered \"%s\"\n",
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
      }
      local_4 = 1;
      if (0 < (int)gpGlobals[0x24]) {
        do {
          piVar5 = (int *)UTIL_PlayerByIndex__Fi(local_4);
          if (piVar5 != (int *)0x0) {
            if ((param_1[0xdd] != 0) && (CTF_Map == 0)) {
              UTIL_ShowMessage__FPCcP7edict_s
                        (param_1[0xdd] + (int)gpGlobals[0x26],*(undefined4 *)(*piVar5 + 0x208));
            }
            if (((param_1[0xee] != 0) && (CTF_Map == 0)) && (param_2 != (int *)0x0)) {
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar5,1,param_1[0xee] + (int)gpGlobals[0x26],
                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0);
            }
            if ((param_1[0xe4] != 0) && (CTF_Map == 0)) {
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar5,4,param_1[0xe4] + (int)gpGlobals[0x26],0,0,0,0);
            }
            if (param_1[0xf4] != 0) {
              ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xf4] + (int)gpGlobals[0x26]);
            }
            if (param_2 == piVar5) {
              if ((*(int *)(*param_1 + 0x1d4) != 0) &&
                 (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 != 0x83)) {
                UTIL_ShowMessage__FPCcP7edict_s
                          (*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26],
                           *(undefined4 *)(*param_2 + 0x208));
              }
              if ((param_1[0xeb] != 0) &&
                 (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 != 0x83)) {
                ClientPrint__FP9entvars_siPCcN42
                          (*piVar5,4,param_1[0xeb] + (int)gpGlobals[0x26],0,0,0,0);
              }
              if (param_1[0xf5] != 0) {
                ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xf5] + (int)gpGlobals[0x26]);
              }
            }
            else {
              if ((param_2 == (int *)0x0) || (param_2[0x48] != piVar5[0x48])) {
                if ((param_1[0xe0] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xe1] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                    iVar2 = param_1[0xe1];
                    goto LAB_0010c29c;
                  }
                  if (param_1[0xdf] != 0) {
                    uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                    iVar2 = param_1[0xdf];
                    goto LAB_0010c29c;
                  }
                }
                else {
                  uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                  iVar2 = param_1[0xe0];
LAB_0010c29c:
                  UTIL_ShowMessage__FPCcP7edict_s(iVar2 + (int)gpGlobals[0x26],uVar4);
                }
                if ((param_1[0xe7] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xe8] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xe8];
                    goto LAB_0010c32b;
                  }
                  if (param_1[0xe6] != 0) {
                    iVar2 = param_1[0xe6];
                    goto LAB_0010c32b;
                  }
                }
                else {
                  iVar2 = param_1[0xe7];
LAB_0010c32b:
                  ClientPrint__FP9entvars_siPCcN42(*piVar5,4,iVar2 + (int)gpGlobals[0x26],0,0,0,0);
                }
                if ((param_1[0xf8] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xf9] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xf9];
                    goto LAB_0010c3a7;
                  }
                  if (param_1[0xf7] != 0) {
                    iVar2 = param_1[0xf7];
                    goto LAB_0010c3a7;
                  }
                }
                else {
                  iVar2 = param_1[0xf8];
LAB_0010c3a7:
                  ClientHearVox__11CBasePlayerPCc(piVar5,iVar2 + (int)gpGlobals[0x26]);
                }
                if (((param_1[0xf1] != 0) && (piVar5[0x48] == param_1[0x87])) &&
                   (param_2 != (int *)0x0)) goto LAB_0010c3d2;
                if ((param_1[0xf0] == 0) || (param_2 == (int *)0x0)) goto LAB_0010c443;
                iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                iVar2 = param_1[0xf0];
              }
              else {
                if ((param_1[0xe0] == 0) || (param_2[0x48] != param_1[0x87])) {
                  if ((param_1[0xe1] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                    iVar2 = param_1[0xe1];
                    goto LAB_0010c0ac;
                  }
                  if (param_1[0xde] != 0) {
                    uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                    iVar2 = param_1[0xde];
                    goto LAB_0010c0ac;
                  }
                }
                else {
                  uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                  iVar2 = param_1[0xe0];
LAB_0010c0ac:
                  UTIL_ShowMessage__FPCcP7edict_s(iVar2 + (int)gpGlobals[0x26],uVar4);
                }
                if ((param_1[0xe7] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xe8] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xe8];
                    goto LAB_0010c13b;
                  }
                  if (param_1[0xe5] != 0) {
                    iVar2 = param_1[0xe5];
                    goto LAB_0010c13b;
                  }
                }
                else {
                  iVar2 = param_1[0xe7];
LAB_0010c13b:
                  ClientPrint__FP9entvars_siPCcN42(*piVar5,4,iVar2 + (int)gpGlobals[0x26],0,0,0,0);
                }
                if ((param_1[0xf8] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xf9] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xf9];
                    goto LAB_0010c1b7;
                  }
                  if (param_1[0xf6] != 0) {
                    iVar2 = param_1[0xf6];
                    goto LAB_0010c1b7;
                  }
                }
                else {
                  iVar2 = param_1[0xf8];
LAB_0010c1b7:
                  ClientHearVox__11CBasePlayerPCc(piVar5,iVar2 + (int)gpGlobals[0x26]);
                }
                if ((param_1[0xf1] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if (param_1[0xef] != 0) {
                    iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                    iVar2 = param_1[0xef];
                    goto LAB_0010c42f;
                  }
                  goto LAB_0010c443;
                }
LAB_0010c3d2:
                iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                iVar2 = param_1[0xf1];
              }
LAB_0010c42f:
              ClientPrint__FP9entvars_siPCcN42(*piVar5,1,iVar2 + (int)gpGlobals[0x26],iVar6,0,0,0);
            }
LAB_0010c443:
            iVar2 = IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(param_1,piVar5,param_2);
            if ((iVar2 != 0) &&
               (((fVar1 = (float)param_1[0x95],
                 (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
                 ((*(byte *)(param_1 + 0x8b) & 0x40) == 0)) ||
                (iVar2 = APMeetsCriteria__FP11CBaseEntityT0(param_1,piVar5), iVar2 != 0)))) {
              Apply_Results__FP11CBaseEntityP11CBasePlayerT1i(param_1,piVar5,param_2,param_3);
            }
          }
          local_4 = local_4 + 1;
        } while (local_4 <= (int)gpGlobals[0x24]);
      }
      iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
      if ((iVar2 == 0x81) || (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 == 0x80))
      {
        param_1[0x86] = 1;
      }
      if ((*(byte *)(param_1 + 0x8c) & 4) == 0) {
        fVar1 = (float)param_1[0xcc];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          EndRound__FP11CBaseEntity(param_1);
        }
        DoGroupWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        DoGoalWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
        if (((iVar2 == 0x81) ||
            (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 == 0x82)) ||
           ((iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 == 0x80 ||
            ((iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 == 0x83 ||
             (param_1[0xfe] == 1)))))) {
          DoTriggerWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        }
        iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
        if ((iVar2 == 0x80) ||
           (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 == 0x81)) {
          SetupRespawn__FP11CBaseEntity(param_1);
        }
      }
      else {
        TeamFortress_TeamShowScores__FiP11CBasePlayer(1,0);
        iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
        if (iVar2 != 0) {
          (**(code **)(*g_pGameRules + 0xe0))(g_pGameRules);
        }
      }
    }
    else {
      param_1[0x86] = 4;
      CreateTimer__11CBaseEntityi(param_1,0x65);
      *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_2 + 0x208);
      param_1[3] = -0x10000;
      param_1[4] = (int)DelayedResult__11CBaseEntity;
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0xfd];
      param_1[0x23] = param_3;
    }
  }
  return;
}


