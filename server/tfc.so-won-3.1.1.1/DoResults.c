// DoResults__FP11CBaseEntityP11CBasePlayeri  @ 0010e11c
void DoResults__FP11CBaseEntityP11CBasePlayeri(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_114;
  int local_c;
  int local_8;
  
  if (((cb_prematch_time <= *gpGlobals) ||
      (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x81)) &&
     (param_1[0x86] != 1)) {
    if (((float)param_1[0x101] <= 0.0) || (param_1[0x86] == 4)) {
      if (param_1[0x89] != 0) {
        iVar2 = GetTeamCheckTeam__FPCc(param_1[0x89] + (int)gpGlobals[0x26]);
        param_1[0x87] = iVar2;
      }
      param_1[0x86] = 2;
      iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1);
      if ((iVar2 == 0x80) || (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x81))
      {
        *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
      }
      iVar2 = *(int *)(*param_1 + 0x1e8);
      if (iVar2 != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),2,iVar2 + (int)gpGlobals[0x26],0x3f800000,
                   0x3f4ccccd,0,100);
      }
      local_8 = 0;
      do {
        if (param_1[local_8 + 0xc0] != 0) {
          TeamFortress_TeamIncreaseScore__Fii(local_8 + 1,param_1[local_8 + 0xc0]);
        }
        local_8 = local_8 + 1;
      } while (local_8 < 4);
      if ((param_1[0xc4] != 0) && (param_1[0x87] != 0)) {
        TeamFortress_TeamIncreaseScore__Fii(param_1[0x87],param_1[0xc4]);
      }
      if (param_1 != (int *)0x0) {
        fVar1 = gpGlobals[0x26];
        iVar2 = *(int *)(*param_1 + 0x1d0);
        if (*(char *)(iVar2 + (int)fVar1) != '\0') {
          if (param_2 == (int *)0x0) {
            UTIL_LogPrintf__FPce("World triggered \"%s\"\n",iVar2 + (int)fVar1);
          }
          else {
            if (param_2[0x48] == 0) {
              pcVar3 = "SPECTATOR";
            }
            else {
              pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],(int)fVar1 + iVar2);
            }
            uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
            uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
            UTIL_LogPrintf__FPce
                      ("\"%s<%i><%s><%s>\" triggered \"%s\"\n",
                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          }
        }
      }
      if (((CTF_Map == 1) && (param_2 != (int *)0x0)) &&
         ((param_1[0x84] == 1 || (param_1[0x84] == 3)))) {
        local_c = 1;
        if (0 < (int)gpGlobals[0x24]) {
          do {
            piVar5 = (int *)UTIL_PlayerByIndex__Fi(local_c);
            if (piVar5 != (int *)0x0) {
              iVar2 = piVar5[0x48];
              if (((iVar2 == 2) && (param_1[0x84] == 1)) ||
                 ((iVar7 = param_1[0x84], iVar2 == 1 && (iVar7 == 2)))) {
                if (piVar5 != param_2) {
                  pcVar3 = "Your team GOT the ENEMY flag!!";
                  goto LAB_0010e568;
                }
                pcVar3 = "You got the enemy flag!\n\nReturn to base!";
                iVar2 = *param_2;
              }
              else {
                if (iVar7 - 1U < 2) {
                  pcVar3 = "Your flag has been TAKEN!!";
                }
                else if (((iVar2 == 2) && (iVar7 == 3)) || ((iVar2 == 1 && (iVar7 == 4)))) {
                  if (piVar5 == param_2) {
                    pcVar3 = "You CAPTURED the FLAG!!";
                    iVar2 = *param_2;
                    goto LAB_0010e56e;
                  }
                  pcVar3 = "Your flag was CAPTURED!!";
                }
                else {
                  if (1 < iVar7 - 3U) goto LAB_0010e576;
                  pcVar3 = "Your team CAPTURED the flag!!";
                }
LAB_0010e568:
                iVar2 = *piVar5;
              }
LAB_0010e56e:
              ClientPrint__FP9entvars_siPCcN42(iVar2,4,pcVar3,0,0,0,0);
            }
LAB_0010e576:
            local_c = local_c + 1;
          } while (local_c <= (int)gpGlobals[0x24]);
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
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Stole_Blue_Flag\"\n",
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
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Stole_Red_Flag\"\n",
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
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Captured_Red_Flag\"\n",
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
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Captured_Blue_Flag\"\n",
                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfd;
        }
      }
      if (param_1[0xb2] != 0) {
        iVar2 = 0;
        while (iVar2 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar2,"netname","info_player_teamspawn"), iVar2 != 0) {
          if (*(int *)(iVar2 + 0x214) == param_1[0xb2]) {
            *(undefined4 *)(iVar2 + 0x218) = 3;
          }
        }
      }
      if (param_1[0xb3] != 0) {
        iVar2 = 0;
        while (iVar2 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar2,"netname","info_player_teamspawn"), iVar2 != 0) {
          if (*(int *)(iVar2 + 0x214) == param_1[0xb3]) {
            *(undefined4 *)(iVar2 + 0x218) = 2;
          }
        }
      }
      if ((param_1[0xe1] != 0) && (CTF_Map == 0)) {
        UTIL_LogPrintf__FPce("World triggered \"%s\"\n",param_1[0xe1] + (int)gpGlobals[0x26]);
      }
      if (((param_1[0xf2] != 0) && (CTF_Map == 0)) && (param_2 != (int *)0x0)) {
        if (param_2[0x48] == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],param_1[0xf2] + (int)gpGlobals[0x26]);
        }
        uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
        uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%s><%s>\" triggered \"%s\"\n",
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
      }
      local_8 = 1;
      if (0 < (int)gpGlobals[0x24]) {
        do {
          piVar5 = (int *)UTIL_PlayerByIndex__Fi(local_8);
          if (piVar5 != (int *)0x0) {
            if ((param_1[0xe1] != 0) && (CTF_Map == 0)) {
              UTIL_ShowMessage__FPCcP7edict_s
                        (param_1[0xe1] + (int)gpGlobals[0x26],*(undefined4 *)(*piVar5 + 0x208));
            }
            if (((param_1[0xf2] != 0) && (CTF_Map == 0)) && (param_2 != (int *)0x0)) {
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar5,1,param_1[0xf2] + (int)gpGlobals[0x26],
                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0);
            }
            if ((param_1[0xe8] != 0) && (CTF_Map == 0)) {
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar5,4,param_1[0xe8] + (int)gpGlobals[0x26],0,0,0,0);
            }
            if (param_1[0xf8] != 0) {
              ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xf8] + (int)gpGlobals[0x26]);
            }
            if (param_2 == piVar5) {
              if ((*(int *)(*param_1 + 0x1d4) != 0) &&
                 (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 != 0x83)) {
                UTIL_ShowMessage__FPCcP7edict_s
                          (*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26],
                           *(undefined4 *)(*param_2 + 0x208));
              }
              if ((param_1[0xef] != 0) &&
                 (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 != 0x83)) {
                ClientPrint__FP9entvars_siPCcN42
                          (*piVar5,4,param_1[0xef] + (int)gpGlobals[0x26],0,0,0,0);
              }
              if (param_1[0xf9] != 0) {
                ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xf9] + (int)gpGlobals[0x26]);
              }
            }
            else {
              if ((param_2 == (int *)0x0) || (iVar2 = piVar5[0x48], param_2[0x48] != iVar2)) {
                iVar2 = param_1[0xe4];
                if (((iVar2 != 0) && (piVar5[0x48] == param_1[0x87])) ||
                   (((iVar2 = param_1[0xe5], iVar2 != 0 && (piVar5[0x48] != param_1[0x87])) ||
                    (iVar2 = param_1[0xe3], iVar2 != 0)))) {
                  UTIL_ShowMessage__FPCcP7edict_s
                            (iVar2 + (int)gpGlobals[0x26],*(undefined4 *)(*piVar5 + 0x208));
                }
                iVar2 = param_1[0xeb];
                if ((((iVar2 != 0) && (piVar5[0x48] == param_1[0x87])) ||
                    ((iVar2 = param_1[0xec], iVar2 != 0 && (piVar5[0x48] != param_1[0x87])))) ||
                   (iVar2 = param_1[0xea], iVar2 != 0)) {
                  ClientPrint__FP9entvars_siPCcN42(*piVar5,4,iVar2 + (int)gpGlobals[0x26],0,0,0,0);
                }
                iVar2 = param_1[0xfc];
                if ((((iVar2 != 0) && (piVar5[0x48] == param_1[0x87])) ||
                    ((iVar2 = param_1[0xfd], iVar2 != 0 && (piVar5[0x48] != param_1[0x87])))) ||
                   (iVar2 = param_1[0xfb], iVar2 != 0)) {
                  ClientHearVox__11CBasePlayerPCc(piVar5,iVar2 + (int)gpGlobals[0x26]);
                }
                iVar2 = param_1[0xf5];
                if (((iVar2 != 0) && (piVar5[0x48] == param_1[0x87])) && (param_2 != (int *)0x0))
                goto LAB_0010efca;
                iVar2 = param_1[0xf4];
                if ((iVar2 == 0) || (param_2 == (int *)0x0)) goto LAB_0010f055;
LAB_0010f017:
                iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                iVar2 = iVar2 + (int)gpGlobals[0x26];
                iVar7 = *piVar5;
              }
              else {
                local_114 = param_1[0xe4];
                if (((local_114 == 0) || (iVar2 != param_1[0x87])) &&
                   ((local_114 = param_1[0xe5], local_114 == 0 || (iVar2 == param_1[0x87])))) {
                  if (param_1[0xe2] != 0) {
                    uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                    local_114 = param_1[0xe2] + (int)gpGlobals[0x26];
                    goto LAB_0010ed81;
                  }
                }
                else {
                  uVar4 = *(undefined4 *)(*piVar5 + 0x208);
                  local_114 = local_114 + (int)gpGlobals[0x26];
LAB_0010ed81:
                  UTIL_ShowMessage__FPCcP7edict_s(local_114,uVar4);
                }
                iVar2 = param_1[0xeb];
                if ((((iVar2 != 0) && (piVar5[0x48] == param_1[0x87])) ||
                    ((iVar2 = param_1[0xec], iVar2 != 0 && (piVar5[0x48] != param_1[0x87])))) ||
                   (iVar2 = param_1[0xe9], iVar2 != 0)) {
                  ClientPrint__FP9entvars_siPCcN42(*piVar5,4,iVar2 + (int)gpGlobals[0x26],0,0,0,0);
                }
                iVar2 = param_1[0xfc];
                if (((iVar2 != 0) && (piVar5[0x48] == param_1[0x87])) ||
                   (((iVar2 = param_1[0xfd], iVar2 != 0 && (piVar5[0x48] != param_1[0x87])) ||
                    (iVar2 = param_1[0xfa], iVar2 != 0)))) {
                  ClientHearVox__11CBasePlayerPCc(piVar5,iVar2 + (int)gpGlobals[0x26]);
                }
                iVar2 = param_1[0xf5];
                if ((iVar2 == 0) || (piVar5[0x48] != param_1[0x87])) {
                  iVar2 = param_1[0xf3];
                  if (iVar2 != 0) goto LAB_0010f017;
                  goto LAB_0010f055;
                }
LAB_0010efca:
                iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                iVar2 = iVar2 + (int)gpGlobals[0x26];
                iVar7 = *piVar5;
              }
              ClientPrint__FP9entvars_siPCcN42(iVar7,1,iVar2,iVar6,0,0,0);
            }
LAB_0010f055:
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
          local_8 = local_8 + 1;
        } while (local_8 <= (int)gpGlobals[0x24]);
      }
      iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1);
      if ((iVar2 == 0x81) || (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x80))
      {
        param_1[0x86] = 1;
      }
      if ((*(byte *)(param_1 + 0x8c) & 4) == 0) {
        fVar1 = (float)param_1[0xd0];
        if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          EndRound__FP11CBaseEntity(param_1);
        }
        DoGroupWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        DoGoalWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1);
        if (((iVar2 == 0x81) ||
            (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x82)) ||
           ((iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x80 ||
            ((iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x83 ||
             (param_1[0x102] == 1)))))) {
          DoTriggerWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        }
        iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1);
        if ((iVar2 == 0x80) ||
           (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x81)) {
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
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x101];
      param_1[0x23] = param_3;
    }
  }
  return;
}


